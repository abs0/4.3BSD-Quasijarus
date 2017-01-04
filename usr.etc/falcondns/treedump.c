/*
 * FalconDNS debug feature: tree dump
 */

#ifndef lint
static char sccsid[] = "@(#)treedump.c	1.9 (IFCTF) 2013/01/11";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include "tree.h"
#include "nsrec.h"
#include "zone.h"
#include "class.h"
#include "globals.h"

extern struct node *find_node_by_dname();

static FILE *dumpfile;

static void
dump_local_soa(soa)
	register struct soa *soa;
{
	fputs(" Local zone-head SOA:\n", dumpfile);
	fputs("  MNAME=", dumpfile);
	print_dname(soa->soa_mname, dumpfile);
	putc('\n', dumpfile);
	fputs("  RNAME=", dumpfile);
	print_dname(soa->soa_rname, dumpfile);
	putc('\n', dumpfile);
	fprintf(dumpfile, "  serial=%lu\n", soa->soa_serial);
	fprintf(dumpfile, "  refresh=%lu\n", soa->soa_refresh);
	fprintf(dumpfile, "  retry=%lu\n", soa->soa_retry);
	fprintf(dumpfile, "  expire=%lu\n", soa->soa_expire);
	fprintf(dumpfile, "  minimum=%lu\n", soa->soa_minimum);
}

static void
dump_ns_rrset(ns)
	struct ns_rrset *ns;
{
	register struct nsrr *s;
	register int i;
	int count;

	fprintf(dumpfile, " NS type %d:\n", ns->ns_type);
	switch (ns->ns_type) {
	case NSTYPE_ZONEHEAD:
	case NSTYPE_DELEGATION:
		fprintf(dumpfile, "  NS TTL %lu\n", ns->ns_ttl);
		break;
	case NSTYPE_ANCHOR:
	case NSTYPE_CACHEDREF:
		fputs("  cached NS expires ", dumpfile);
		fputs(asctime(gmtime(&ns->ns_expire)), dumpfile);
	}
	for (s = ns->ns_chain, count = 0; s; s = s->nsrr_next, count++) {
		fputs("  server ", dumpfile);
		print_dname(s + 1, dumpfile);
		putc('\n', dumpfile);
		for (i = 0; i < s->nsrr_addrcnt; i++)
			fprintf(dumpfile, "   A %s\n",
			    inet_ntoa(*(struct in_addr *)&s->nsrr_addrs[i]));
		if (s->nsrr_addrcnt) {
			fputs("   cached A expires ", dumpfile);
			fputs(asctime(gmtime(&s->nsrr_A_expire)), dumpfile);
		}
		if (s->nsrr_tempfail) {
			fputs("   cached tempfail expires ", dumpfile);
			fputs(asctime(gmtime(&s->nsrr_tempfail)), dumpfile);
		}
	}
	if (count != ns->ns_count)
		fprintf(dumpfile, "  actual count %d != listed count %d\n",
			count, ns->ns_count);
}

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

#define	MIN_KNOWN_RRTYPE	1
#define	MAX_KNOWN_RRTYPE	39

static char *rr_types[MAX_KNOWN_RRTYPE] = {
	"A", "NS", "MD", "MF", "CNAME", "SOA", "MB", "MG",
	"MR", "NULL", "WKS", "PTR", "HINFO", "MINFO", "MX", "TXT",
	"RP", "AFSDB", "X25", "ISDN", "RT", "NSAP", "NSAP-PTR", "SIG",
	"KEY", "PX", "GPOS", "AAAA", "LOC", "NXT", "EID", "NIMLOC",
	"SRV", "ATMA", "NAPTR", "KX", "CERT", "A6", "DNAME"};

static void
dump_rr(rr)
	register struct rr *rr;
{
	register u_char *dp;
	struct minfo *mi;
	struct cachedsoa *csoa;
	register int i, len;

	dp = (u_char *)(rr + 1);
	if (rr->rr_type >= MIN_KNOWN_RRTYPE && rr->rr_type <= MAX_KNOWN_RRTYPE)
		fprintf(dumpfile, "  %s (class %d)", rr_types[rr->rr_type-1],
			rr->rr_class);
	else
		fprintf(dumpfile, "  type=%d class=%d", rr->rr_type,
			rr->rr_class);
	switch (rr->rr_type) {
	case T_MX:
	case T_AFSDB:
	case T_RT:
		fprintf(dumpfile, " %u", rr->rr_mxpref);
		/* FALL THRU */
	case T_CNAME:
	case T_MB:
	case T_MD:
	case T_MF:
	case T_MG:
	case T_MR:
	case T_NS:
	case T_PTR:
		putc(' ', dumpfile);
		print_dname(dp, dumpfile);
		break;
	case T_MINFO:
	case T_RP:
		mi = (struct minfo *)dp;
		putc(' ', dumpfile);
		print_dname(mi->minfo_dn1, dumpfile);
		putc(' ', dumpfile);
		print_dname(mi->minfo_dn2, dumpfile);
		break;
	case T_SOA:
		csoa = (struct cachedsoa *)dp;
		fputs("\n    ", dumpfile);
		print_dname(csoa->csoa_mname, dumpfile);
		putc(' ', dumpfile);
		print_dname(csoa->csoa_rname, dumpfile);
		fputs("\n    ", dumpfile);
		dump_cachedsoa_numbers(csoa->csoa_numbers);
		break;
	default:
		len = rr->rr_length;
		if (len > 8)
			fputs("\n   ", dumpfile);
		for (i = 0; len--; i++) {
			if (i >= 16) {
				fputs("\n   ", dumpfile);
				i = 0;
			}
			fprintf(dumpfile, " %02X", *dp++);
		}
	}
	putc('\n', dumpfile);
	if (rr->rr_flags & RR_CACHED) {
		fputs("    expires ", dumpfile);
		fputs(asctime(gmtime(&rr->rr_expire)), dumpfile);
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
	}
}

static void
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
	register struct node *n;
{
	register struct rr *rr;
	struct dname dname;

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
	}
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
	if (n->n_soa)
		dump_local_soa(n->n_soa);
	if (n->n_ns)
		dump_ns_rrset(n->n_ns);
	if (n->n_rrzone) {
		fputs(" RRs from the zone:\n", dumpfile);
		for (rr = n->n_rrzone; rr; rr = rr->rr_next)
			dump_rr(rr);
	}
	if (n->n_cached_ans)
		dump_cached_ans(n->n_cached_ans);
	if (n->n_cached_cname) {
		fputs(" Cached CNAME:\n", dumpfile);
		dump_rr(n->n_cached_cname);
	}
	if (n->n_cached_nxdom) {
		fputs(" Cached NXDOMAIN:\n", dumpfile);
		dump_rescache(n->n_cached_nxdom);
	}
	putc('\n', dumpfile);
}

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

void
cmd_dump_tree(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;
	int classnum;
	register struct class *cl;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
badusage:	syslog(LOG_ERR, "usage: dump-tree class dumpfile");
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
	dump_subtree(cl->c_root, 0);
	fclose(dumpfile);
	syslog(LOG_INFO, "dump-tree: class %d dumped to %s", classnum, arg2);
}

void
cmd_dump_subtree(args)
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
badusage:	syslog(LOG_ERR, "usage: dump-subtree class domain dumpfile");
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
	dump_subtree(n, 0);
	fclose(dumpfile);
	syslog(LOG_INFO, "dump-subtree: %s in class %d dumped to %s", arg2,
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
		classnum, arg3);
}
