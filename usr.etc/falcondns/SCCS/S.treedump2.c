h20439
s 00005/00002/00281
d D 1.4 2011/12/23 07:06:11 msokolov 4 3
c symbolic names for new RR types
e
s 00004/00000/00279
d D 1.3 2011/12/19 09:19:21 msokolov 3 2
c show cached NS tempfail info
e
s 00070/00000/00209
d D 1.2 2011/12/13 03:28:26 msokolov 2 1
c dump-tree-node implemented
e
s 00209/00000/00000
d D 1.1 2011/12/10 08:39:52 msokolov 1 0
c date and time created 2011/12/10 08:39:52 by msokolov
e
u
U
t
T
I 1
/*
 * MSDNS debug feature: tree dump
 * Alternative dump format
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "class.h"
#include "globals.h"

I 2
extern struct node *find_node_by_dname();

E 2
static FILE *dumpfile;

static void
dump_soa(soa)
	register struct soa *soa;
{
	fputs(" SOA:\n", dumpfile);
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
I 3
		if (s->nsrr_tempfail) {
			fputs("   cached tempfail expires ", dumpfile);
			fputs(asctime(gmtime(&s->nsrr_tempfail)), dumpfile);
		}
E 3
	}
	if (count != ns->ns_count)
		fprintf(dumpfile, "  actual count %d != listed count %d\n",
			count, ns->ns_count);
}

#define	MIN_KNOWN_RRTYPE	1
D 4
#define	MAX_KNOWN_RRTYPE	16
E 4
I 4
#define	MAX_KNOWN_RRTYPE	39
E 4

static char *rr_types[MAX_KNOWN_RRTYPE] = {
	"A", "NS", "MD", "MF", "CNAME", "SOA", "MB", "MG",
D 4
	"MR", "NULL", "WKS", "PTR", "HINFO", "MINFO", "MX", "TXT"};
E 4
I 4
	"MR", "NULL", "WKS", "PTR", "HINFO", "MINFO", "MX", "TXT",
	"RP", "AFSDB", "X25", "ISDN", "RT", "NSAP", "NSAP-PTR", "SIG",
	"KEY", "PX", "GPOS", "AAAA", "LOC", "NXT", "EID", "NIMLOC",
	"SRV", "ATMA", "NAPTR", "KX", "CERT", "A6", "DNAME"};
E 4

static void
dump_rr(rr)
	register struct rr *rr;
{
	register u_char *dp;
	struct minfo *mi;
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
		fprintf(dumpfile, " %u", rr->rr_mxpref);
		/* FALL THRU */
	case T_CNAME:
	case T_MB:
	case T_MD:
	case T_MF:
	case T_MG:
	case T_MR:
	case T_PTR:
		putc(' ', dumpfile);
		print_dname(dp, dumpfile);
		break;
	case T_NS:
	case T_SOA:
		fputs(" NS/SOA unexpected!", dumpfile);
		break;
	case T_MINFO:
		mi = (struct minfo *)dp;
		putc(' ', dumpfile);
		print_dname(mi->minfo_dn1, dumpfile);
		putc(' ', dumpfile);
		print_dname(mi->minfo_dn2, dumpfile);
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
	else if (n->n_cache_backptr)
		fputs(" cache-created node\n", dumpfile);
	if (n->n_refcount != 1)
		fprintf(dumpfile, " n_refcount = %d\n", n->n_refcount);
	if (n->n_soa)
		dump_soa(n->n_soa);
	if (n->n_ns)
		dump_ns_rrset(n->n_ns);
	if (n->n_rrzone) {
		fputs(" RRs from the zone:\n", dumpfile);
		for (rr = n->n_rrzone; rr; rr = rr->rr_next)
			dump_rr(rr);
	}
	if (n->n_rrcache) {
		fputs(" cached RRs:\n", dumpfile);
		for (rr = n->n_rrcache; rr; rr = rr->rr_next)
			dump_rr(rr);
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

dump_subtree_altformat(n, dumpf)
	struct node *n;
	FILE *dumpf;
{
	dumpfile = dumpf;
	dump_subtree(n, 0);
I 2
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
badusage:	syslog(LOG_ERR,
			"usage: dump-tree-node class domain dumpfile");
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
E 2
}
E 1
