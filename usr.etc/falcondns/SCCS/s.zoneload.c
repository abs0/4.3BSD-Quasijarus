h14887
s 00006/00000/00461
d D 1.19 2013/01/14 00:40:10 msokolov 19 18
c class ready-to-serve flag implemented
e
s 00053/00062/00408
d D 1.18 2013/01/11 23:02:44 msokolov 18 17
c first round of changes for the new FSR cache design
e
s 00004/00004/00466
d D 1.17 2013/01/06 08:56:30 msokolov 17 16
c more sensible and consistent msgparse function naming:
c s/extract_dname_from_msg/msgparse_extract_dname/
c s/parse_incoming_rr/msgparse_rdata/
e
s 00001/00001/00469
d D 1.16 2013/01/06 08:15:47 msokolov 16 15
c s/dname_in_bailiwick/dname_is_under/
e
s 00001/00001/00469
d D 1.15 2013/01/06 07:03:49 msokolov 15 14
c MSDNS => FalconDNS
e
s 00001/00001/00469
d D 1.14 2011/12/16 07:03:14 msokolov 14 13
c clear Z_RETRYING
e
s 00001/00001/00469
d D 1.13 2011/12/15 02:25:54 msokolov 13 12
c do an immediate refresh after a successful file read
e
s 00031/00028/00439
d D 1.12 2011/12/04 03:18:11 msokolov 12 11
c attach_rr_to_node() converted to use struct parsedrr
e
s 00001/00000/00466
d D 1.11 2011/11/11 20:55:20 msokolov 11 10
c #include <machine/endian.h> for hton[ls] and ntoh[ls]
e
s 00006/00000/00460
d D 1.10 2011/10/31 17:42:56 msokolov 10 9
c suppress wildcard NS
e
s 00007/00023/00453
d D 1.9 2011/10/31 07:18:51 msokolov 9 8
c n_zonehead and n_nextinzone implemented
e
s 00008/00002/00468
d D 1.8 2011/09/12 04:26:04 msokolov 8 7
c NS record handling revamped into RRset model
e
s 00002/00002/00468
d D 1.7 2011/07/19 19:02:42 msokolov 7 6
c reattach_lower_zones() split off from free_subtree()
e
s 00019/00002/00451
d D 1.6 2011/07/18 05:54:14 msokolov 6 5
c basic refresh logic implemented
e
s 00043/00002/00410
d D 1.5 2011/07/16 01:18:45 msokolov 5 4
c zone loading code complete
e
s 00067/00006/00345
d D 1.4 2011/07/15 20:54:16 msokolov 4 3
c SOA parsing implemented
e
s 00079/00002/00272
d D 1.3 2011/07/15 20:11:19 msokolov 3 2
c non-SOA RR handling implemented
e
s 00006/00002/00268
d D 1.2 2011/07/15 07:39:44 msokolov 2 1
c detect and mark wildcard nodes
e
s 00270/00000/00000
d D 1.1 2011/07/14 07:27:25 msokolov 1 0
c zone file loading coming along
e
u
U
t
T
I 1
/*
D 15
 * Michael Sokolov's Domain Name Server (MSDNS)
E 15
I 15
 * FalconDNS daemon by Michael Spacefalcon
E 15
 *
 * The hard work of loading a zone file and building a tree from it
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 11
#include <machine/endian.h>
E 11
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <syslog.h>
I 6
#include "defs.h"
E 6
#include "dname.h"
#include "tree.h"
D 8
#include "rr.h"
E 8
I 8
#include "nsrec.h"
E 8
#include "zone.h"
#include "class.h"
#include "globals.h"
#include "selectloop.h"
I 12
#include "msgparse.h"
E 12

I 18
#define	MAX_UNPARSED_RDATA	16384

E 18
I 4
extern u_char *myalloc();
D 17
extern u_char *extract_dname_from_msg();
E 17
I 17
extern u_char *msgparse_extract_dname();
E 17
E 4
extern struct node *alloc_new_node(), *node_findchild();

I 4
static void
abort_handler(z)
D 5
	struct zone *z;
E 5
I 5
	register struct zone *z;
E 5
{
I 5
	FD_CLR(fileno(z->z_fileread), &select_for_read);
	fclose(z->z_fileread);
	z->z_fileread = 0;
	zone_fileread_inprogress = 0;
I 19
	z->z_class->c_outstanding_loads--;
E 19
	syslog(LOG_ERR,
	"errors occurred while loading %s (%d) from %s, zone not installed",
		z->z_ascii_domname, z->z_class->c_class, z->z_filename);
D 7
	free_subtree(z->z_tree_inprogress, 0);
E 7
I 7
	free_subtree(z->z_tree_inprogress);
E 7
	z->z_tree_inprogress = 0;
	z->z_flags |= Z_LOAD_FAILED;
I 6
	schedule_zone_refresh(z, 1);
E 6
E 5
}

E 4
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

D 9
static
owner_in_zone(z, o)
	struct zone *z;
	register struct dname *o;
{
	register struct dname *r = z->z_dname;
	register int ol, rl;

	ol = o->dn_nlabels;
	rl = r->dn_nlabels;
	if (ol < rl)
		return(0);
	while (rl) {
		ol--;
		rl--;
		if (!label_match(o->dn_labels[ol], r->dn_labels[rl]))
			return(0);
	}
	return(1);
}

E 9
static struct node *
get_node_for_zonerr(z, owner)
D 9
	struct zone *z;
E 9
I 9
	register struct zone *z;
E 9
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
I 5
			ch->n_parent = n;
E 5
I 2
			if (ch->n_labellen == 1 && ch->n_label_uc[0] == '*')
				n->n_zonech_wild = ch;
I 9
			ch->n_zonehead = z->z_tree_inprogress;
			z->z_fileread_lastnode->n_nextinzone = ch;
			z->z_fileread_lastnode = ch;
E 9
E 2
		}
	}
	return(n);
}

static void
I 3
D 18
handle_soa(z, n, fix, rdata)
E 18
I 18
handle_soa(z, n, prr)
E 18
	struct zone *z;
	struct node *n;
D 18
	struct rrfixed *fix;
	u_char *rdata;
E 18
I 18
	register struct parsedrr *prr;
E 18
{
I 4
D 18
	struct dname mname, rname;
E 18
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
D 18
	if (fix->class != z->z_class->c_class) {
E 18
I 18
	if (prr->prr_fix.class != z->z_class->c_class) {
E 18
		syslog(LOG_ERR, "%s: record %d: SOA class %d != zone class %d",
D 18
			z->z_filename, z->z_fileread_rrcount, fix->class,
			z->z_class->c_class);
E 18
I 18
			z->z_filename, z->z_fileread_rrcount,
			prr->prr_fix.class, z->z_class->c_class);
E 18
		abort_handler(z);
		return;
	}
D 18
	cp = rdata;
D 17
	cp = extract_dname_from_msg(&mname, cp, rdata + fix->rdlength, 0);
E 17
I 17
	cp = msgparse_extract_dname(&mname, cp, rdata + fix->rdlength, 0);
E 17
	if (!cp) {
invalid:	syslog(LOG_ERR, "%s: record %d: SOA RDATA is invalid",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
D 17
	cp = extract_dname_from_msg(&rname, cp, rdata + fix->rdlength, 0);
E 17
I 17
	cp = msgparse_extract_dname(&rname, cp, rdata + fix->rdlength, 0);
E 17
	if (!cp)
		goto invalid;
	if (cp + 20 != rdata + fix->rdlength)
		goto invalid;
	dp = myalloc(sizeof(struct soa) + dn_spaceneeded(&mname) +
			dn_spaceneeded(&rname));
E 18
I 18
	dp = myalloc(sizeof(struct soa) + dn_spaceneeded(&prr->prr_rdata_dn[0])
			+ dn_spaceneeded(&prr->prr_rdata_dn[1]));
E 18
	if (!dp) {
		syslog(LOG_CRIT,
			"SOA malloc failure prevents loading of %s (%d)",
			z->z_ascii_domname, z->z_class->c_class);
		abort_handler(z);
		return;
	}
	soa = (struct soa *)dp;
	dp += sizeof(struct soa);
D 8
	soa->soa_node = n;
E 8
	soa->soa_mname = (struct dname *)dp;
D 18
	dname_copy(&mname, dp);
	dp += dn_spaceneeded(&mname);
E 18
I 18
	dname_copy(&prr->prr_rdata_dn[0], dp);
	dp += dn_spaceneeded(&prr->prr_rdata_dn[0]);
E 18
	soa->soa_rname = (struct dname *)dp;
D 18
	dname_copy(&rname, dp);
E 18
I 18
	dname_copy(&prr->prr_rdata_dn[1], dp);
	cp = prr->prr_rdata_misc;
E 18
	GETLONG(soa->soa_serial, cp);
	GETLONG(soa->soa_refresh, cp);
	GETLONG(soa->soa_retry, cp);
	GETLONG(soa->soa_expire, cp);
	GETLONG(soa->soa_minimum, cp);
I 6
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
E 6
	n->n_soa = soa;
E 4
}

static void
E 3
D 12
process_rr(z, n, fix, rdata)
E 12
I 12
process_rr(z, n, prr)
E 12
	struct zone *z;
	struct node *n;
D 12
	struct rrfixed *fix;
	u_char *rdata;
E 12
I 12
	register struct parsedrr *prr;
E 12
{
I 3
	register int i;
D 18
	register char *err;
E 18
E 3

I 18
	if (msgparse_rdata(prr, 0) < 0) {
		syslog(LOG_ERR, "%s: record %d: RDATA parse error, not loaded",
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
E 18
D 3

E 3
I 3
D 12
	switch (fix->type) {
E 12
I 12
	switch (prr->prr_fix.type) {
E 12
D 18
	case T_A:
	case T_CNAME:
	case T_MB:
	case T_MG:
	case T_MR:
	case T_PTR:
	case T_HINFO:
	case T_MINFO:
	case T_MX:
	case T_TXT:
	generic:
D 12
		i = attach_rr_to_node(n, fix, rdata, 0, 0);
E 12
I 12
D 17
		if (parse_incoming_rr(prr, 0) < 0)
E 17
I 17
		if (msgparse_rdata(prr, 0) < 0)
E 17
			goto inv_rdata;
		i = attach_rr_to_node(n, prr, 0);
E 12
		if (i < 0) {
			switch (i) {
			case -1:
D 12
				err = "invalid RDATA";
E 12
I 12
inv_rdata:			err = "invalid RDATA";
E 12
				break;
			case -2:
				err = "malloc failed";
				break;
			default:
				err = "unknown error";
			}
			syslog(LOG_ERR,
				"%s: record %d: attach_rr_to_node failed: %s",
				z->z_filename, z->z_fileread_rrcount, err);
		}
E 18
I 18
	case T_SOA:
		handle_soa(z, n, prr);
E 18
		return;
	case T_NS:
D 12
		if (fix->class != z->z_class->c_class) {
E 12
I 12
		if (prr->prr_fix.class != z->z_class->c_class) {
E 12
			syslog(LOG_ERR,
			"%s: record %d: NS class doesn't match zone class",
				z->z_filename, z->z_fileread_rrcount);
			return;
		}
I 10
		if (n->n_labellen == 1 && n->n_label_uc[0] == '*') {
			syslog(LOG_ERR,
				"%s: record %d: wildcard NS not allowed",
				z->z_filename, z->z_fileread_rrcount);
			return;
		}
I 18
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
E 18
E 10
		goto generic;
	case T_WKS:
D 12
		if (fix->class != C_IN) {
E 12
I 12
		if (prr->prr_fix.class != C_IN) {
E 12
			syslog(LOG_ERR,
			"%s: record %d: WKS not supported for class != IN",
				z->z_filename, z->z_fileread_rrcount);
			return;
		}
I 18
		if (prr->prr_fix.rdlength < 5 + 1 ||
		    prr->prr_fix.rdlength > 5 + 8192)
			goto inv_a_wks;
E 18
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
D 18
	case T_SOA:
D 12
		handle_soa(z, n, fix, rdata);
E 12
I 12
		handle_soa(z, n, &prr->prr_fix, prr->prr_rdata);
E 12
		return;
E 18
I 18
	generic:
E 18
	default:
D 18
		syslog(LOG_ERR, "%s: record %d: unknown RR type %d, not loaded",
D 12
			z->z_filename, z->z_fileread_rrcount, fix->type);
E 12
I 12
			z->z_filename, z->z_fileread_rrcount,
			prr->prr_fix.type);
E 18
I 18
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
E 18
E 12
	}
E 3
}

static void
D 2
good_eof_handler()
E 2
I 2
good_eof_handler(z)
D 4
	struct zone *z;
E 2
{
}

static void
D 2
abort_handler()
E 2
I 2
abort_handler(z)
E 4
D 5
	struct zone *z;
E 5
I 5
	register struct zone *z;
E 5
E 2
{
I 5
	register struct node *tree;

	tree = z->z_tree_inprogress;
	if (!tree->n_soa) {
		syslog(LOG_ERR, "%s: no SOA record found", z->z_filename);
		abort_handler(z);
		return;
	}
I 8
	if (!tree->n_ns) {
		syslog(LOG_ERR, "%s: top-of-zone NS records missing",
			z->z_filename);
		abort_handler(z);
		return;
	}
	tree->n_ns->ns_type = NSTYPE_ZONEHEAD;
E 8
	FD_CLR(fileno(z->z_fileread), &select_for_read);
	fclose(z->z_fileread);
	z->z_fileread = 0;
	zone_fileread_inprogress = 0;
I 19
	z->z_class->c_outstanding_loads--;
E 19
	z->z_tree_inprogress = 0;
	if (install_zone_tree(z->z_class, tree, z->z_dname) < 0) {
		syslog(LOG_CRIT,
		"malloc failure prevents activation of newly loaded %s (%d)",
			z->z_ascii_domname, z->z_class->c_class);
		z->z_flags |= Z_LOAD_FAILED;
D 7
		free_subtree(tree, 0);
E 7
I 7
		free_subtree(tree);
E 7
		return;
	}
	z->z_activetree = tree;
D 14
	z->z_flags &= ~(Z_LOAD_FAILED | Z_LOST_IN_MALLOC);
E 14
I 14
	z->z_flags &= ~(Z_LOAD_FAILED | Z_LOST_IN_MALLOC | Z_RETRYING);
E 14
	syslog(LOG_INFO, "class %d: zone %s loaded from %s",
		z->z_class->c_class, z->z_ascii_domname, z->z_filename);
I 19
	class_ready_check(z->z_class);
E 19
D 6
	/* the refresh logic will go here */
	return;
E 6
I 6
D 13
	schedule_zone_refresh(z, 0);
E 13
I 13
	zone_refresh(z);
E 13
E 6
E 5
}

void
zonefile_read_handler(z)
	register struct zone *z;
{
D 12
	struct dname owner;
	struct rrfixed fix;
E 12
I 12
	struct parsedrr prr;
E 12
	u_char rdata[MAX_UNPARSED_RDATA];
	struct node *n;
	register int i;

D 12
	i = read_dname(z, &owner);
E 12
I 12
	i = read_dname(z, &prr.prr_owner);
E 12
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
D 12
	i = fread(&fix, 1, RRFIXEDSZ, z->z_fileread);
E 12
I 12
	i = fread(&prr.prr_fix, 1, RRFIXEDSZ, z->z_fileread);
E 12
	if (i != RRFIXEDSZ) {
		syslog(LOG_ERR, "%s: record %d: error reading the fixed part",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
D 12
	fix.type = ntohs(fix.type);
	fix.class = ntohs(fix.class);
	fix.ttl = ntohl(fix.ttl);
	fix.rdlength = ntohs(fix.rdlength);
I 3
	if (!fix.rdlength) {
E 12
I 12
	prr.prr_fix.type = ntohs(prr.prr_fix.type);
	prr.prr_fix.class = ntohs(prr.prr_fix.class);
	prr.prr_fix.ttl = ntohl(prr.prr_fix.ttl);
	prr.prr_fix.rdlength = ntohs(prr.prr_fix.rdlength);
	if (!prr.prr_fix.rdlength) {
E 12
		syslog(LOG_WARNING, "%s: record %d: zero RDLENGTH; RR skipped",
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
E 3
D 12
	if (fix.rdlength > MAX_UNPARSED_RDATA) {
E 12
I 12
	if (prr.prr_fix.rdlength > MAX_UNPARSED_RDATA) {
E 12
		syslog(LOG_WARNING,
	"%s: record %d: RDLENGTH %u exceeds our limit of %u; RR skipped",
D 12
			z->z_filename, z->z_fileread_rrcount, fix.rdlength,
			MAX_UNPARSED_RDATA);
		fseek(z->z_fileread, fix.rdlength, 1);
E 12
I 12
			z->z_filename, z->z_fileread_rrcount,
			prr.prr_fix.rdlength, MAX_UNPARSED_RDATA);
		fseek(z->z_fileread, prr.prr_fix.rdlength, 1);
E 12
		return;
	}
D 12
	i = fread(rdata, 1, fix.rdlength, z->z_fileread);
	if (i != fix.rdlength) {
E 12
I 12
	i = fread(rdata, 1, prr.prr_fix.rdlength, z->z_fileread);
	if (i != prr.prr_fix.rdlength) {
E 12
		syslog(LOG_ERR, "%s: record %d: error reading RDATA",
			z->z_filename, z->z_fileread_rrcount);
		abort_handler(z);
		return;
	}
	/* verify owner in zone */
D 9
	if (!owner_in_zone(z, &owner)) {
E 9
I 9
D 12
	if (!dname_in_bailiwick(&owner, z->z_dname)) {
E 12
I 12
D 16
	if (!dname_in_bailiwick(&prr.prr_owner, z->z_dname)) {
E 16
I 16
	if (!dname_is_under(&prr.prr_owner, z->z_dname)) {
E 16
E 12
E 9
D 3
		syslog(LOG_ERR, "%s: record %d: owner above zone root, ignored",
E 3
I 3
		syslog(LOG_WARNING,
			"%s: record %d: owner above zone root, ignored",
E 3
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
	/* get/create tree node */
D 12
	n = get_node_for_zonerr(z, &owner);
E 12
I 12
	n = get_node_for_zonerr(z, &prr.prr_owner);
E 12
	if (!n) {
D 18
		syslog(LOG_ERR, "%s: record %d skipped: couldn't allocate node",
E 18
I 18
		syslog(LOG_CRIT,
			"%s: record %d skipped: couldn't allocate node",
E 18
			z->z_filename, z->z_fileread_rrcount);
		return;
	}
	/* actual RR handling! */
D 12
	process_rr(z, n, &fix, rdata);
E 12
I 12
	prr.prr_rdata = rdata;
	process_rr(z, n, &prr);
E 12
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
I 5
		z->z_flags |= Z_LOAD_FAILED;
I 19
		z->z_class->c_outstanding_loads--;
E 19
I 6
		schedule_zone_refresh(z, 1);
E 6
E 5
		return(-1);
	}
	if (fread(verbuf, 1, 8, f) != 8 || bcmp(verbuf, magic, 8)) {
		syslog(LOG_CRIT, "%s is not a valid MSDNS binary zone file",
			z->z_filename);
		fclose(f);
I 5
		z->z_flags |= Z_LOAD_FAILED;
I 19
		z->z_class->c_outstanding_loads--;
E 19
I 6
		schedule_zone_refresh(z, 1);
E 6
E 5
		return(-1);
	}
	tree = alloc_new_node(z->z_class, z->z_dname->dn_labels[0]);
	if (!tree) {
		syslog(LOG_CRIT, "malloc failure prevents loading of %s (%d)",
			z->z_ascii_domname, z->z_class->c_class);
		fclose(f);
I 5
		z->z_flags |= Z_LOAD_FAILED;
I 19
		z->z_class->c_outstanding_loads--;
E 19
E 5
		return(-1);
	}
	tree->n_zone = z;
I 9
	tree->n_zonehead = tree;
E 9
	z->z_tree_inprogress = tree;
	z->z_fileread = f;
	z->z_fileread_rrcount = 0;
I 9
	z->z_fileread_lastnode = tree;
E 9
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
E 1
