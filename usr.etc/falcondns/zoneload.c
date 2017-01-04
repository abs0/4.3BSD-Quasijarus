/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * The hard work of loading a zone file and building a tree from it
 */

#ifndef lint
static char sccsid[] = "@(#)zoneload.c	1.19 (IFCTF) 2013/01/14";
#endif

#include <sys/types.h>
#include <machine/endian.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <syslog.h>
#include "defs.h"
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "zone.h"
#include "class.h"
#include "globals.h"
#include "selectloop.h"
#include "msgparse.h"

#define	MAX_UNPARSED_RDATA	16384

extern u_char *myalloc();
extern u_char *msgparse_extract_dname();
extern struct node *alloc_new_node(), *node_findchild();

static void
abort_handler(z)
	register struct zone *z;
{
	FD_CLR(fileno(z->z_fileread), &select_for_read);
	fclose(z->z_fileread);
	z->z_fileread = 0;
	zone_fileread_inprogress = 0;
	z->z_class->c_outstanding_loads--;
	syslog(LOG_ERR,
	"errors occurred while loading %s (%d) from %s, zone not installed",
		z->z_ascii_domname, z->z_class->c_class, z->z_filename);
	free_subtree(z->z_tree_inprogress);
	z->z_tree_inprogress = 0;
	z->z_flags |= Z_LOAD_FAILED;
	schedule_zone_refresh(z, 1);
}

/*
 * This function reads a domain-name from the input stream.
 * Return value:
 *  0 = success
 * -1 = EOF upfront
 * -2 = EOF in the middle
 * -3 = total length exceeded
 * -4 = high bits set in a length octet
 */
static
read_dname(z, dn)
	struct zone *z;
	struct dname *dn;
{
	register FILE *f;
	register u_char *dp;
	int lcnt;
	register int len;

	f = z->z_fileread;
	dn->dn_stringlen = 0;
	dp = dn->dn_buf;
	for (lcnt = 0; ; lcnt++) {
		len = getc(f);
		if (len < 0)
			return(dn->dn_stringlen ? -2 : -1);
		if (len & INDIR_MASK)
			return(-4);
		dn->dn_labels[lcnt] = dp;
		*dp++ = len;
		dn->dn_stringlen += len + 1;
		if (dn->dn_stringlen > 256)
			return(-3);
		if (len) {
			if (fread(dp, 1, len, f) != len)
				return(-2);
			dp += len;
		} else
			break;
	}
	dn->dn_nlabels = lcnt;
	return(0);
}

static struct node *
get_node_for_zonerr(z, owner)
	register struct zone *z;
	struct dname *owner;
{
	int depth;
	register struct node *n, *ch;
	struct node_findaddchild_private_state st;

	depth = owner->dn_nlabels - z->z_dname->dn_nlabels;
	n = z->z_tree_inprogress;
	for (; depth--; n = ch) {
		ch = node_findchild(&n->n_zonech, owner->dn_labels[depth], &st);
		if (!ch) {
			ch = alloc_new_node(z->z_class,
					    owner->dn_labels[depth]);
			if (!ch)
				return(0);
			if (node_addchild(&n->n_zonech, ch, &st) < 0) {
				free(ch);
				return(0);
			}
			ch->n_parent = n;
			if (ch->n_labellen == 1 && ch->n_label_uc[0] == '*')
				n->n_zonech_wild = ch;
			ch->n_zonehead = z->z_tree_inprogress;
			z->z_fileread_lastnode->n_nextinzone = ch;
			z->z_fileread_lastnode = ch;
		}
	}
	return(n);
}

static void
handle_soa(z, n, prr)
	struct zone *z;
	struct node *n;
	register struct parsedrr *prr;
{
	register struct soa *soa;
	register u_char *cp, *dp;

	if (n != z->z_tree_inprogress) {
		syslog(LOG_ERR, "%s: record %d: SOA not at the top of the zone",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
	if (n->n_soa) {
		syslog(LOG_ERR, "%s: record %d: duplicate SOA",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
	if (prr->prr_fix.class != z->z_class->c_class) {
		syslog(LOG_ERR, "%s: record %d: SOA class %d != zone class %d",
			z->z_filename, z->z_fileread_rrcount,
			prr->prr_fix.class, z->z_class->c_class);
		abort_handler(z);
		return;
	}
	dp = myalloc(sizeof(struct soa) + dn_spaceneeded(&prr->prr_rdata_dn[0])
			+ dn_spaceneeded(&prr->prr_rdata_dn[1]));
	if (!dp) {
		syslog(LOG_CRIT,
			"SOA malloc failure prevents loading of %s (%d)",
			z->z_ascii_domname, z->z_class->c_class);
		abort_handler(z);
		return;
	}
	soa = (struct soa *)dp;
	dp += sizeof(struct soa);
	soa->soa_mname = (struct dname *)dp;
	dname_copy(&prr->prr_rdata_dn[0], dp);
	dp += dn_spaceneeded(&prr->prr_rdata_dn[0]);
	soa->soa_rname = (struct dname *)dp;
	dname_copy(&prr->prr_rdata_dn[1], dp);
	cp = prr->prr_rdata_misc;
	GETLONG(soa->soa_serial, cp);
	GETLONG(soa->soa_refresh, cp);
	GETLONG(soa->soa_retry, cp);
	GETLONG(soa->soa_expire, cp);
	GETLONG(soa->soa_minimum, cp);
	if (soa->soa_refresh < MINIMUM_SOA_REFRESH) {
		syslog(LOG_WARNING,
		"%s (%d): SOA refresh value of %lu is insane, upped to %d",
			z->z_ascii_domname, z->z_class->c_class,
			soa->soa_refresh, MINIMUM_SOA_REFRESH);
		soa->soa_refresh = MINIMUM_SOA_REFRESH;
	}
	if (soa->soa_retry < MINIMUM_SOA_RETRY) {
		syslog(LOG_WARNING,
		"%s (%d): SOA retry value of %lu is insane, upped to %d",
			z->z_ascii_domname, z->z_class->c_class,
			soa->soa_retry, MINIMUM_SOA_RETRY);
		soa->soa_retry = MINIMUM_SOA_RETRY;
	}
	n->n_soa = soa;
}

static void
process_rr(z, n, prr)
	struct zone *z;
	struct node *n;
	register struct parsedrr *prr;
{
	register int i;

	if (msgparse_rdata(prr, 0) < 0) {
		syslog(LOG_ERR, "%s: record %d: RDATA parse error, not loaded",
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
	switch (prr->prr_fix.type) {
	case T_SOA:
		handle_soa(z, n, prr);
		return;
	case T_NS:
		if (prr->prr_fix.class != z->z_class->c_class) {
			syslog(LOG_ERR,
			"%s: record %d: NS class doesn't match zone class",
				z->z_filename, z->z_fileread_rrcount);
			return;
		}
		if (n->n_labellen == 1 && n->n_label_uc[0] == '*') {
			syslog(LOG_ERR,
				"%s: record %d: wildcard NS not allowed",
				z->z_filename, z->z_fileread_rrcount);
			return;
		}
		if (attach_ns_to_node(n, prr, 0) < 0) {
mallocfail:		syslog(LOG_CRIT, "%s: record %d: malloc failure",
				z->z_filename, z->z_fileread_rrcount);
		}
		return;
	case T_A:
		if (prr->prr_fix.class == C_IN && prr->prr_fix.rdlength != 4) {
inv_a_wks:		syslog(LOG_ERR,
				"%s: record %d: IN A/WKS RDATA is invalid",
				z->z_filename, z->z_fileread_rrcount);
			return;
		}
		goto generic;
	case T_WKS:
		if (prr->prr_fix.class != C_IN) {
			syslog(LOG_ERR,
			"%s: record %d: WKS not supported for class != IN",
				z->z_filename, z->z_fileread_rrcount);
			return;
		}
		if (prr->prr_fix.rdlength < 5 + 1 ||
		    prr->prr_fix.rdlength > 5 + 8192)
			goto inv_a_wks;
		goto generic;
	case T_MD:
	case T_MF:
		syslog(LOG_ERR, "%s: record %d: MD/MF is obsolete, not loaded",
			z->z_filename, z->z_fileread_rrcount);
		return;
	case T_NULL:
		syslog(LOG_ERR, "%s: record %d: NULL RR ignored",
			z->z_filename, z->z_fileread_rrcount);
		return;
	generic:
	default:
		i = attach_rrzone_to_node(n, prr);
		if (i < 0) {
			switch (i) {
			case -1:
				syslog(LOG_ERR,
			"%s: record %d: conflict with a prior RR, not loaded",
					z->z_filename, z->z_fileread_rrcount);
				return;
			case -2:
				goto mallocfail;
			}
			syslog(LOG_CRIT,
		"%s: record %d: unknown error in attach_rrzone_to_node()",
				z->z_filename, z->z_fileread_rrcount);
		}
	}
}

static void
good_eof_handler(z)
	register struct zone *z;
{
	register struct node *tree;

	tree = z->z_tree_inprogress;
	if (!tree->n_soa) {
		syslog(LOG_ERR, "%s: no SOA record found", z->z_filename);
		abort_handler(z);
		return;
	}
	if (!tree->n_ns) {
		syslog(LOG_ERR, "%s: top-of-zone NS records missing",
			z->z_filename);
		abort_handler(z);
		return;
	}
	tree->n_ns->ns_type = NSTYPE_ZONEHEAD;
	FD_CLR(fileno(z->z_fileread), &select_for_read);
	fclose(z->z_fileread);
	z->z_fileread = 0;
	zone_fileread_inprogress = 0;
	z->z_class->c_outstanding_loads--;
	z->z_tree_inprogress = 0;
	if (install_zone_tree(z->z_class, tree, z->z_dname) < 0) {
		syslog(LOG_CRIT,
		"malloc failure prevents activation of newly loaded %s (%d)",
			z->z_ascii_domname, z->z_class->c_class);
		z->z_flags |= Z_LOAD_FAILED;
		free_subtree(tree);
		return;
	}
	z->z_activetree = tree;
	z->z_flags &= ~(Z_LOAD_FAILED | Z_LOST_IN_MALLOC | Z_RETRYING);
	syslog(LOG_INFO, "class %d: zone %s loaded from %s",
		z->z_class->c_class, z->z_ascii_domname, z->z_filename);
	class_ready_check(z->z_class);
	zone_refresh(z);
}

void
zonefile_read_handler(z)
	register struct zone *z;
{
	struct parsedrr prr;
	u_char rdata[MAX_UNPARSED_RDATA];
	struct node *n;
	register int i;

	i = read_dname(z, &prr.prr_owner);
	if (i == -1) {
		good_eof_handler(z);
		return;
	}
	z->z_fileread_rrcount++;
	if (i < 0) {
		syslog(LOG_ERR, "%s: record %d: error reading the owner field",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
	/* read in the rest of the RR so we can skip w/o aborting */
	i = fread(&prr.prr_fix, 1, RRFIXEDSZ, z->z_fileread);
	if (i != RRFIXEDSZ) {
		syslog(LOG_ERR, "%s: record %d: error reading the fixed part",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
	prr.prr_fix.type = ntohs(prr.prr_fix.type);
	prr.prr_fix.class = ntohs(prr.prr_fix.class);
	prr.prr_fix.ttl = ntohl(prr.prr_fix.ttl);
	prr.prr_fix.rdlength = ntohs(prr.prr_fix.rdlength);
	if (!prr.prr_fix.rdlength) {
		syslog(LOG_WARNING, "%s: record %d: zero RDLENGTH; RR skipped",
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
	if (prr.prr_fix.rdlength > MAX_UNPARSED_RDATA) {
		syslog(LOG_WARNING,
	"%s: record %d: RDLENGTH %u exceeds our limit of %u; RR skipped",
			z->z_filename, z->z_fileread_rrcount,
			prr.prr_fix.rdlength, MAX_UNPARSED_RDATA);
		fseek(z->z_fileread, prr.prr_fix.rdlength, 1);
		return;
	}
	i = fread(rdata, 1, prr.prr_fix.rdlength, z->z_fileread);
	if (i != prr.prr_fix.rdlength) {
		syslog(LOG_ERR, "%s: record %d: error reading RDATA",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
	/* verify owner in zone */
	if (!dname_is_under(&prr.prr_owner, z->z_dname)) {
		syslog(LOG_WARNING,
			"%s: record %d: owner above zone root, ignored",
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
	/* get/create tree node */
	n = get_node_for_zonerr(z, &prr.prr_owner);
	if (!n) {
		syslog(LOG_CRIT,
			"%s: record %d skipped: couldn't allocate node",
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
	/* actual RR handling! */
	prr.prr_rdata = rdata;
	process_rr(z, n, &prr);
}

zone_fileread_start(z)
	register struct zone *z;
{
	register FILE *f;
	register int fd;
	static char magic[] = "BINZONE\200";
	char verbuf[8];
	struct node *tree;
	struct stat st;

	z->z_flags &= ~Z_FILEREAD_NEEDED;
	zones_needing_fileread--;
	f = fopen(z->z_filename, "r");
	if (!f) {
		syslog(LOG_CRIT, "can't open zone file %s for %s (%d): %m",
			z->z_filename, z->z_ascii_domname, z->z_class->c_class);
		z->z_flags |= Z_LOAD_FAILED;
		z->z_class->c_outstanding_loads--;
		schedule_zone_refresh(z, 1);
		return(-1);
	}
	if (fread(verbuf, 1, 8, f) != 8 || bcmp(verbuf, magic, 8)) {
		syslog(LOG_CRIT, "%s is not a valid MSDNS binary zone file",
			z->z_filename);
		fclose(f);
		z->z_flags |= Z_LOAD_FAILED;
		z->z_class->c_outstanding_loads--;
		schedule_zone_refresh(z, 1);
		return(-1);
	}
	tree = alloc_new_node(z->z_class, z->z_dname->dn_labels[0]);
	if (!tree) {
		syslog(LOG_CRIT, "malloc failure prevents loading of %s (%d)",
			z->z_ascii_domname, z->z_class->c_class);
		fclose(f);
		z->z_flags |= Z_LOAD_FAILED;
		z->z_class->c_outstanding_loads--;
		return(-1);
	}
	tree->n_zone = z;
	tree->n_zonehead = tree;
	z->z_tree_inprogress = tree;
	z->z_fileread = f;
	z->z_fileread_rrcount = 0;
	z->z_fileread_lastnode = tree;
	fd = fileno(f);
	fstat(fd, &st);
	z->z_file_mtime = st.st_mtime;
	select_desc[fd].sel_read = zonefile_read_handler;
	select_desc[fd].sel_opaque = (caddr_t) z;
	FD_SET(fd, &select_for_read);
	if (fd > select_max_fd)
		select_max_fd = fd;
	zone_fileread_inprogress = 1;
	return(0);
}

zone_fileread_find()
{
	register struct zone *z;

	for (z = zone_fileread_roundrobin; ; z = z->z_next_global) {
		if (!z)
			z = global_zone_list;
		if (!z) {
			syslog(LOG_CRIT,
				"BUG in zone_fileread_find(): no zones exist!");
			abort();
		}
		if (z->z_flags & Z_FILEREAD_NEEDED)
			break;
	}
	zone_fileread_start(z);
	zone_fileread_roundrobin = z->z_next_global;
}
