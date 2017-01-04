h40284
s 00220/00126/00246
d D 1.9 2013/01/11 23:02:46 msokolov 9 8
c first round of changes for the new FSR cache design
e
s 00005/00002/00367
d D 1.8 2011/12/23 07:06:10 msokolov 8 7
c symbolic names for new RR types
e
s 00005/00000/00364
d D 1.7 2011/12/19 09:19:20 msokolov 7 6
c show cached NS tempfail info
e
s 00075/00000/00289
d D 1.6 2011/12/13 03:21:00 msokolov 6 5
c dump-subtree implemented
e
s 00010/00004/00279
d D 1.5 2011/12/10 08:46:43 msokolov 5 4
c fprintf fix, alternative dump format option
e
s 00054/00004/00229
d D 1.4 2011/09/12 05:10:26 msokolov 4 3
c added dump of new NS RRsets
e
s 00002/00002/00231
d D 1.3 2011/07/18 03:12:34 msokolov 3 2
c little buglet
e
s 00118/00001/00115
d D 1.2 2011/07/18 03:03:20 msokolov 2 1
c RR dump implemented
e
s 00116/00000/00000
d D 1.1 2011/07/18 01:04:27 msokolov 1 0
c date and time created 2011/07/18 01:04:27 by msokolov
e
u
U
t
T
I 1
/*
D 9
 * MSDNS debug feature: tree dump
E 9
I 9
 * FalconDNS debug feature: tree dump
E 9
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 4
#include <netinet/in.h>
E 4
#include <arpa/nameser.h>
I 4
#include <arpa/inet.h>
E 4
#include <ctype.h>
#include <stdio.h>
I 2
#include <time.h>
E 2
#include <syslog.h>
#include "tree.h"
D 4
#include "rr.h"
E 4
I 4
#include "nsrec.h"
E 4
#include "zone.h"
#include "class.h"
#include "globals.h"

I 6
extern struct node *find_node_by_dname();

E 6
static FILE *dumpfile;

static void
D 9
indent(cnt)
	register int cnt;
{
	while (cnt--)
		putc(' ', dumpfile);
}

static void
I 2
dump_soa(soa, ind)
E 9
I 9
dump_local_soa(soa)
E 9
	register struct soa *soa;
D 9
	register int ind;
E 9
{
D 9
	indent(ind);
	fputs("SOA:\n", dumpfile);
	indent(ind+1);
	fputs("MNAME=", dumpfile);
E 9
I 9
	fputs(" Local zone-head SOA:\n", dumpfile);
	fputs("  MNAME=", dumpfile);
E 9
	print_dname(soa->soa_mname, dumpfile);
	putc('\n', dumpfile);
D 9
	indent(ind+1);
	fputs("RNAME=", dumpfile);
E 9
I 9
	fputs("  RNAME=", dumpfile);
E 9
	print_dname(soa->soa_rname, dumpfile);
	putc('\n', dumpfile);
D 9
	indent(ind+1);
	fprintf(dumpfile, "serial=%lu\n", soa->soa_serial);
	indent(ind+1);
	fprintf(dumpfile, "refresh=%lu\n", soa->soa_refresh);
	indent(ind+1);
	fprintf(dumpfile, "retry=%lu\n", soa->soa_retry);
	indent(ind+1);
	fprintf(dumpfile, "expire=%lu\n", soa->soa_expire);
	indent(ind+1);
	fprintf(dumpfile, "minimum=%lu\n", soa->soa_minimum);
E 9
I 9
	fprintf(dumpfile, "  serial=%lu\n", soa->soa_serial);
	fprintf(dumpfile, "  refresh=%lu\n", soa->soa_refresh);
	fprintf(dumpfile, "  retry=%lu\n", soa->soa_retry);
	fprintf(dumpfile, "  expire=%lu\n", soa->soa_expire);
	fprintf(dumpfile, "  minimum=%lu\n", soa->soa_minimum);
E 9
}

I 4
static void
D 9
dump_ns_rrset(ns, ind)
E 9
I 9
dump_ns_rrset(ns)
E 9
	struct ns_rrset *ns;
D 9
	int ind;
E 9
{
	register struct nsrr *s;
	register int i;
	int count;

D 9
	indent(ind);
	fprintf(dumpfile, "NS type %d:\n", ns->ns_type);
E 9
I 9
	fprintf(dumpfile, " NS type %d:\n", ns->ns_type);
E 9
	switch (ns->ns_type) {
	case NSTYPE_ZONEHEAD:
	case NSTYPE_DELEGATION:
D 9
		indent(ind + 1);
		fprintf(dumpfile, "NS TTL %lu\n", ns->ns_ttl);
E 9
I 9
		fprintf(dumpfile, "  NS TTL %lu\n", ns->ns_ttl);
E 9
		break;
	case NSTYPE_ANCHOR:
	case NSTYPE_CACHEDREF:
D 9
		indent(ind + 1);
		fputs("cached NS expires ", dumpfile);
E 9
I 9
		fputs("  cached NS expires ", dumpfile);
E 9
		fputs(asctime(gmtime(&ns->ns_expire)), dumpfile);
	}
	for (s = ns->ns_chain, count = 0; s; s = s->nsrr_next, count++) {
D 9
		indent(ind + 1);
		fputs("server ", dumpfile);
E 9
I 9
		fputs("  server ", dumpfile);
E 9
		print_dname(s + 1, dumpfile);
		putc('\n', dumpfile);
D 9
		for (i = 0; i < s->nsrr_addrcnt; i++) {
			indent(ind + 2);
			fprintf(dumpfile, "A %s\n",
E 9
I 9
		for (i = 0; i < s->nsrr_addrcnt; i++)
			fprintf(dumpfile, "   A %s\n",
E 9
			    inet_ntoa(*(struct in_addr *)&s->nsrr_addrs[i]));
D 9
		}
E 9
		if (s->nsrr_addrcnt) {
D 9
			indent(ind + 2);
			fputs("cached A expires ", dumpfile);
E 9
I 9
			fputs("   cached A expires ", dumpfile);
E 9
			fputs(asctime(gmtime(&s->nsrr_A_expire)), dumpfile);
		}
I 7
		if (s->nsrr_tempfail) {
D 9
			indent(ind + 2);
			fputs("cached tempfail expires ", dumpfile);
E 9
I 9
			fputs("   cached tempfail expires ", dumpfile);
E 9
			fputs(asctime(gmtime(&s->nsrr_tempfail)), dumpfile);
		}
E 7
	}
D 9
	if (count != ns->ns_count) {
		indent(ind + 1);
		fprintf(dumpfile, "actual count %d != listed count %d\n",
E 9
I 9
	if (count != ns->ns_count)
		fprintf(dumpfile, "  actual count %d != listed count %d\n",
E 9
			count, ns->ns_count);
D 9
	}
E 9
}

I 9
static void
dump_cachedsoa_numbers(cp)
	register u_char *cp;
{
	register u_long num;

	GETLONG(num, cp);
	fprintf(dumpfile, "%lu ", num);
	GETLONG(num, cp);
	fprintf(dumpfile, "%lu ", num);
	GETLONG(num, cp);
	fprintf(dumpfile, "%lu ", num);
	GETLONG(num, cp);
	fprintf(dumpfile, "%lu ", num);
	GETLONG(num, cp);
	fprintf(dumpfile, "%lu", num);
}

E 9
E 4
#define	MIN_KNOWN_RRTYPE	1
D 8
#define	MAX_KNOWN_RRTYPE	16
E 8
I 8
#define	MAX_KNOWN_RRTYPE	39
E 8

static char *rr_types[MAX_KNOWN_RRTYPE] = {
	"A", "NS", "MD", "MF", "CNAME", "SOA", "MB", "MG",
D 8
	"MR", "NULL", "WKS", "PTR", "HINFO", "MINFO", "MX", "TXT"};
E 8
I 8
	"MR", "NULL", "WKS", "PTR", "HINFO", "MINFO", "MX", "TXT",
	"RP", "AFSDB", "X25", "ISDN", "RT", "NSAP", "NSAP-PTR", "SIG",
	"KEY", "PX", "GPOS", "AAAA", "LOC", "NXT", "EID", "NIMLOC",
	"SRV", "ATMA", "NAPTR", "KX", "CERT", "A6", "DNAME"};
E 8

static void
D 9
dump_rr(rr, ind)
E 9
I 9
dump_rr(rr)
E 9
	register struct rr *rr;
D 9
	int ind;
E 9
{
	register u_char *dp;
	struct minfo *mi;
I 9
	struct cachedsoa *csoa;
E 9
	register int i, len;

	dp = (u_char *)(rr + 1);
D 9
	indent(ind);
E 9
	if (rr->rr_type >= MIN_KNOWN_RRTYPE && rr->rr_type <= MAX_KNOWN_RRTYPE)
D 9
		fprintf(dumpfile, "%s (class %d)", rr_types[rr->rr_type-1],
E 9
I 9
		fprintf(dumpfile, "  %s (class %d)", rr_types[rr->rr_type-1],
E 9
			rr->rr_class);
	else
D 9
		fprintf(dumpfile, "type=%d class=%d", rr->rr_type,
E 9
I 9
		fprintf(dumpfile, "  type=%d class=%d", rr->rr_type,
E 9
			rr->rr_class);
	switch (rr->rr_type) {
	case T_MX:
I 9
	case T_AFSDB:
	case T_RT:
E 9
		fprintf(dumpfile, " %u", rr->rr_mxpref);
		/* FALL THRU */
	case T_CNAME:
	case T_MB:
	case T_MD:
	case T_MF:
	case T_MG:
	case T_MR:
I 9
	case T_NS:
E 9
	case T_PTR:
D 4
	generic_dname:
E 4
		putc(' ', dumpfile);
		print_dname(dp, dumpfile);
		break;
D 9
	case T_NS:
D 4
		dp += 4;
		goto generic_dname;
E 4
I 4
	case T_SOA:
		fputs(" NS/SOA unexpected!", dumpfile);
		break;
E 9
E 4
	case T_MINFO:
I 9
	case T_RP:
E 9
		mi = (struct minfo *)dp;
		putc(' ', dumpfile);
		print_dname(mi->minfo_dn1, dumpfile);
		putc(' ', dumpfile);
		print_dname(mi->minfo_dn2, dumpfile);
		break;
I 9
	case T_SOA:
		csoa = (struct cachedsoa *)dp;
		fputs("\n    ", dumpfile);
		print_dname(csoa->csoa_mname, dumpfile);
		putc(' ', dumpfile);
		print_dname(csoa->csoa_rname, dumpfile);
		fputs("\n    ", dumpfile);
		dump_cachedsoa_numbers(csoa->csoa_numbers);
		break;
E 9
	default:
		len = rr->rr_length;
D 9
		if (len > 8) {
			putc('\n', dumpfile);
			indent(ind);
		}
E 9
I 9
		if (len > 8)
			fputs("\n   ", dumpfile);
E 9
		for (i = 0; len--; i++) {
			if (i >= 16) {
D 9
				putc('\n', dumpfile);
				indent(ind);
E 9
I 9
				fputs("\n   ", dumpfile);
E 9
				i = 0;
			}
			fprintf(dumpfile, " %02X", *dp++);
		}
	}
	putc('\n', dumpfile);
	if (rr->rr_flags & RR_CACHED) {
D 9
		indent(ind + 1);
		fputs("expires ", dumpfile);
E 9
I 9
		fputs("    expires ", dumpfile);
E 9
		fputs(asctime(gmtime(&rr->rr_expire)), dumpfile);
D 9
	} else if (rr->rr_ttl) {
		indent(ind + 1);
		fprintf(dumpfile, "TTL %lu\n", rr->rr_ttl);
E 9
I 9
	} else if (rr->rr_ttl)
		fprintf(dumpfile, "    TTL %lu\n", rr->rr_ttl);
}

static void
dump_rescache(rc)
	register struct rescache *rc;
{
	register struct rr *rr;
	register struct ncache *nc;

	fputs("  expires ", dumpfile);
	fputs(asctime(gmtime(&rc->rc_expire)), dumpfile);
	if (rc->rc_pos) {
		for (rr = rc->rc_pos; rr; rr = rr->rr_next)
			dump_rr(rr);
	} else {
		nc = (struct ncache *)(rc + 1);
		fputs("  negative SOA:\n    owner=", dumpfile);
		print_dname(nc->nsoa_owner, dumpfile);
		fputs("\n    ", dumpfile);
		print_dname(nc->nsoa_mname, dumpfile);
		putc(' ', dumpfile);
		print_dname(nc->nsoa_rname, dumpfile);
		fputs("\n    ", dumpfile);
		dump_cachedsoa_numbers(nc->nsoa_numbers);
		putc('\n', dumpfile);
E 9
	}
}

static void
E 2
D 9
dump_node(n, depth)
E 9
I 9
dump_cached_ans(rc)
	register struct rescache *rc;
{
	for (; rc; rc = rc->rc_next) {
		fprintf(dumpfile, " Cached QTYPE %d", rc->rc_qtype);
		if (rc->rc_qtype >= MIN_KNOWN_RRTYPE &&
		    rc->rc_qtype <= MAX_KNOWN_RRTYPE)
			fprintf(dumpfile, " (%s)", rr_types[rc->rc_qtype-1]);
		fputs(":\n", dumpfile);
		dump_rescache(rc);
	}
}

static void
dump_node(n, chtype)
E 9
	register struct node *n;
{
D 9
	register struct zone *z;
E 9
I 2
	register struct rr *rr;
I 9
	struct dname dname;
E 9
E 2

D 9
	indent(depth*2);
	print_label(n, dumpfile);
	putc('\n', dumpfile);
	if (z = n->n_zone) {
		indent(depth*2 + 1);
		fputs("Zone: ", dumpfile);
		print_dname(z->z_dname, dumpfile);
		fprintf(dumpfile, " (file %s)\n", z->z_filename);
		if (z->z_activetree != n) {
			indent(depth*2 + 2);
			fputs("z_activetree doesn't match the node!\n",
				dumpfile);
		}
E 9
I 9
	dname_of_node(n, &dname);
	print_dname(&dname, dumpfile);
	putc(' ', dumpfile);
	switch (chtype) {
	case 1:
		fputs("(zone child)", dumpfile);
		break;
	case 2:
		fputs("(non-zone child)", dumpfile);
		break;
E 9
	}
D 9
	if (n->n_refcount != 1) {
		indent(depth*2 + 1);
D 5
		fprintf("n_refcount = %d\n", n->n_refcount);
E 5
I 5
		fprintf(dumpfile, "n_refcount = %d\n", n->n_refcount);
E 5
	}
E 9
I 9
	putc(':', dumpfile);
	putc('\n', dumpfile);
	if (n->n_zone)
		fputs(" Node is a zone head\n", dumpfile);
	else if (n->n_zonehead)
		fputs(" Node is part of a zone\n", dumpfile);
	if (n->n_cache_backptr)
		fputs(" included in the cache sweep list\n", dumpfile);
	if (n->n_refcount != 1)
		fprintf(dumpfile, " n_refcount = %d\n", n->n_refcount);
E 9
D 2
	/* TODO: dump RRs */
E 2
I 2
	if (n->n_soa)
D 9
		dump_soa(n->n_soa, depth*2 + 1);
E 9
I 9
		dump_local_soa(n->n_soa);
E 9
I 4
	if (n->n_ns)
D 9
		dump_ns_rrset(n->n_ns, depth*2 + 1);
E 9
I 9
		dump_ns_rrset(n->n_ns);
E 9
E 4
	if (n->n_rrzone) {
D 9
		indent(depth*2 + 1);
		fputs("RRs from the zone:\n", dumpfile);
E 9
I 9
		fputs(" RRs from the zone:\n", dumpfile);
E 9
D 3
		for (rr = n->n_rrzone; rr; rr->rr_next)
E 3
I 3
		for (rr = n->n_rrzone; rr; rr = rr->rr_next)
E 3
D 9
			dump_rr(rr, depth*2 + 2);
E 9
I 9
			dump_rr(rr);
E 9
	}
D 9
	if (n->n_rrcache) {
		indent(depth*2 + 1);
		fputs("cached RRs:\n", dumpfile);
D 3
		for (rr = n->n_rrcache; rr; rr->rr_next)
E 3
I 3
		for (rr = n->n_rrcache; rr; rr = rr->rr_next)
E 3
			dump_rr(rr, depth*2 + 2);
E 9
I 9
	if (n->n_cached_ans)
		dump_cached_ans(n->n_cached_ans);
	if (n->n_cached_cname) {
		fputs(" Cached CNAME:\n", dumpfile);
		dump_rr(n->n_cached_cname);
E 9
	}
E 2
D 9
	if (n->n_zonech) {
		indent(depth*2 + 1);
		fputs("in-zone children:\n", dumpfile);
		iterate_node_children(n->n_zonech, dump_node, depth + 1);
E 9
I 9
	if (n->n_cached_nxdom) {
		fputs(" Cached NXDOMAIN:\n", dumpfile);
		dump_rescache(n->n_cached_nxdom);
E 9
	}
D 9
	if (n->n_nzch) {
		indent(depth*2 + 1);
		fputs("non-zone children:\n", dumpfile);
		iterate_node_children(n->n_nzch, dump_node, depth + 1);
	}
E 9
I 9
	putc('\n', dumpfile);
E 9
}

I 9
static void
dump_subtree(n, chtype)
	register struct node *n;
{
	dump_node(n, chtype);
	if (n->n_zonech)
		iterate_node_children(n->n_zonech, dump_subtree, 1);
	if (n->n_nzch)
		iterate_node_children(n->n_nzch, dump_subtree, 2);
}

E 9
void
cmd_dump_tree(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;
D 5
	int classnum;
E 5
I 5
D 9
	int classnum, alt;
E 9
I 9
	int classnum;
E 9
E 5
	register struct class *cl;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
D 5
badusage:	syslog(LOG_ERR, "usage: dump-tree class dumpfile");
E 5
I 5
D 9
badusage:	syslog(LOG_ERR, "usage: dump-tree class dumpfile [alt]");
E 9
I 9
badusage:	syslog(LOG_ERR, "usage: dump-tree class dumpfile");
E 9
E 5
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
I 5
D 9
	while (isspace(*cp))
		cp++;
	alt = (*cp == 'a');
E 9
E 5
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "dump-tree: class %d not defined", classnum);
		return;
	}
	if (!cl->c_root) {
		syslog(LOG_ERR, "dump-tree: class %d has no active tree",
			classnum);
		return;
	}
	dumpfile = fopen(arg2, "w");
	if (!dumpfile) {
		syslog(LOG_ERR, "dump-tree: %s: %m", arg2);
		return;
	}
D 5
	dump_node(cl->c_root, 0);
E 5
I 5
D 9
	if (alt)
		dump_subtree_altformat(cl->c_root, dumpfile);
	else
		dump_node(cl->c_root, 0);
E 9
I 9
	dump_subtree(cl->c_root, 0);
E 9
E 5
	fclose(dumpfile);
	syslog(LOG_INFO, "dump-tree: class %d dumped to %s", classnum, arg2);
I 6
}

void
cmd_dump_subtree(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2, *arg3;
D 9
	int classnum, alt;
E 9
I 9
	int classnum;
E 9
	register struct class *cl;
	struct dname dname;
	register struct node *n;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
D 9
badusage:	syslog(LOG_ERR,
			"usage: dump-subtree class domain dumpfile [alt]");
E 9
I 9
badusage:	syslog(LOG_ERR, "usage: dump-subtree class domain dumpfile");
E 9
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg3 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
D 9
	while (isspace(*cp))
		cp++;
	alt = (*cp == 'a');
E 9
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "dump-subtree: class %d not defined", classnum);
		return;
	}
	if (parse_ascii_dname(arg2, &dname) < 0)
		goto badusage;
	n = find_node_by_dname(cl, &dname);
	if (!n) {
		syslog(LOG_ERR, "dump-subtree: %s not found in class %d", arg2,
			classnum);
		return;
	}
	dumpfile = fopen(arg3, "w");
	if (!dumpfile) {
		syslog(LOG_ERR, "dump-subtree: %s: %m", arg3);
		return;
	}
D 9
	if (alt)
		dump_subtree_altformat(n, dumpfile);
	else
		dump_node(n, 0);
E 9
I 9
	dump_subtree(n, 0);
E 9
	fclose(dumpfile);
	syslog(LOG_INFO, "dump-subtree: %s in class %d dumped to %s", arg2,
I 9
		classnum, arg3);
}

void
cmd_dump_node(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2, *arg3;
	int classnum;
	register struct class *cl;
	struct dname dname;
	register struct node *n;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
badusage:	syslog(LOG_ERR, "usage: dump-tree-node class domain dumpfile");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg3 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "dump-tree-node: class %d not defined",
			classnum);
		return;
	}
	if (parse_ascii_dname(arg2, &dname) < 0)
		goto badusage;
	n = find_node_by_dname(cl, &dname);
	if (!n) {
		syslog(LOG_ERR, "dump-tree-node: %s not found in class %d",
			arg2, classnum);
		return;
	}
	dumpfile = fopen(arg3, "w");
	if (!dumpfile) {
		syslog(LOG_ERR, "dump-tree-node: %s: %m", arg3);
		return;
	}
	dump_node(n, 0);
	fclose(dumpfile);
	syslog(LOG_INFO, "dump-tree-node: %s in class %d dumped to %s", arg2,
E 9
		classnum, arg3);
E 6
}
E 1
