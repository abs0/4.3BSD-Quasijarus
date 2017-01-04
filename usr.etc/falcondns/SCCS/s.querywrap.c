h41042
s 00001/00000/00264
d D 1.10 2013/01/13 09:14:10 msokolov 10 9
c clear AA when returning an FSR ERROR as SERVFAIL
e
s 00001/00000/00263
d D 1.9 2013/01/12 20:56:30 msokolov 9 8
c do A additional records processing for AFSDB
e
s 00002/00002/00261
d D 1.8 2013/01/06 08:56:37 msokolov 8 7
c more sensible and consistent msgparse function naming:
c s/extract_dname_from_msg/msgparse_extract_dname/
c s/parse_incoming_rr/msgparse_rdata/
e
s 00001/00001/00262
d D 1.7 2013/01/06 07:04:12 msokolov 7 6
c MSDNS => FalconDNS
e
s 00001/00001/00262
d D 1.6 2011/12/21 03:51:14 msokolov 6 5
c C operator precedence bug was causing duplicate RRsets in AR
e
s 00005/00000/00258
d D 1.5 2011/12/13 05:00:22 msokolov 5 4
c TC stats implemented
e
s 00007/00003/00251
d D 1.4 2011/12/13 04:18:42 msokolov 4 3
c RRset-style handling of AR not fitting
e
s 00148/00002/00106
d D 1.3 2011/12/08 19:18:59 msokolov 3 2
c AR section implemented
e
s 00006/00004/00102
d D 1.2 2011/12/07 21:31:53 msokolov 2 1
c set q_msglen
e
s 00106/00000/00000
d D 1.1 2011/12/07 21:04:59 msokolov 1 0
c date and time created 2011/12/07 21:04:59 by msokolov
e
u
U
t
T
I 1
/*
D 7
 * Michael Sokolov's Domain Name Server (MSDNS)
E 7
I 7
 * FalconDNS daemon by Michael Spacefalcon
E 7
 *
 * The final wrap-up phase of query handling (both UDP and TCP)
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <machine/endian.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
I 3
#include "dname.h"
E 3
#include "query.h"
I 3
#include "class.h"
#include "tree.h"
#include "rr.h"
#include "globals.h"
E 3

I 3
D 8
extern u_char *extract_dname_from_msg();
E 8
I 8
extern u_char *msgparse_extract_dname();
E 8
extern u_char *msgparse_skip_dname();
extern struct node *node_findchild();

#define	MAX_AR_OWNERS	10

queryar_scan_node(q, n)
	register struct query *q;
	struct node *n;
{
	register HEADER *hdr = (HEADER *)q->q_msg;
	u_long minttl;
	register struct rr *rr;
D 4
	int count = 0;
E 4
I 4
	register int count = 0;
E 4
	struct dname owner;
	register int owner_set = 0;
I 4
	u_char *saveptr;
E 4

	minttl = n->n_zonehead->n_soa->soa_minimum;
	for (rr = n->n_rrzone; rr; rr = rr->rr_next) {
		if (rr->rr_type != T_A)
			continue;
		if (!owner_set) {
			dname_of_node(n, &owner);
			owner_set = 1;
I 4
			saveptr = q->q_msgptr;
E 4
		}
D 4
		if (emit_genrr_into_msg(q, &owner, rr, minttl) < 0)
E 4
I 4
		if (emit_genrr_into_msg(q, &owner, rr, minttl) < 0) {
			q->q_msgptr = saveptr;
I 5
			stats_local_ar_tc++;
E 5
E 4
			return(-1);
I 4
		}
E 4
		count++;
D 4
		hdr->arcount++;
E 4
	}
I 4
	hdr->arcount += count;
E 4
	return(count);
}

queryar_one_dname(q, target, wantglue)
	register struct query *q;
	register struct dname *target;
	int wantglue;
{
	register struct node *n, *ch, *noa;
	register int depth;

	n = q->q_class->c_root;
	noa = 0;
	for (depth = target->dn_nlabels; n; n = ch) {
		if (n->n_ns)
			noa = n;
		if (!depth--)
			break;
		ch = node_findchild(&n->n_nzch, target->dn_labels[depth], 0);
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    target->dn_labels[depth], 0);
	}
	if (!n || !noa)
		return(0);
	if (!wantglue && !noa->n_zone)
		return(0);
	if (!n->n_zonehead)
		return(0);
	return(queryar_scan_node(q, n));
}

queryar_one_srcrec(q, cpp, owners, fillp, wantglue)
	register struct query *q;
	u_char **cpp;
	struct dname *owners;
	int *fillp;
{
	register u_char *cp = *cpp;
	struct rrfixed srcfix;
	register struct dname *ndn;
	register int i;

	cp = msgparse_skip_dname(cp, q->q_msgptr);
	if (!cp) {
		if (q->q_trace)
			fprintf(q->q_trace,
				"error skipping over RR owner field!\n");
		return(-1);
	}
	msgparse_get_rrfix(cp, &srcfix);
	cp += RRFIXEDSZ;
	*cpp = cp + srcfix.rdlength;
	switch (srcfix.type) {
	case T_MB:
	case T_MD:
	case T_MF:
	case T_NS:
		break;
	case T_MX:
I 9
	case T_AFSDB:
E 9
		cp += 2;
		break;
	default:
		return(0);
	}
	ndn = owners + *fillp;
D 8
	if (!extract_dname_from_msg(ndn, cp, q->q_msgptr, q->q_msg)) {
E 8
I 8
	if (!msgparse_extract_dname(ndn, cp, q->q_msgptr, q->q_msg)) {
E 8
		if (q->q_trace)
			fprintf(q->q_trace,
				"error extracting src record's RDATA\n");
		return(-1);
	}
	for (i = 0; i < *fillp; i++)
		if (dname_compare(owners + i, ndn))
			return(0);
	i = queryar_one_dname(q, ndn, wantglue);
	if (i > 0)
D 6
		*fillp++;
E 6
I 6
		(*fillp)++;
E 6
	return(i);
}

E 3
void
I 3
querywrap_make_ar(q, ancount, nscount)
	register struct query *q;
	int ancount, nscount;
{
	struct dname owners[MAX_AR_OWNERS];
	int fill = 0;
	u_char *cp;
	register int i;

	cp = q->q_answer_ptr;
	for (i = 0; i < ancount && fill < MAX_AR_OWNERS; i++)
		if (queryar_one_srcrec(q, &cp, owners, &fill, 0) < 0)
			return;
	for (i = 0; i < nscount && fill < MAX_AR_OWNERS; i++)
		if (queryar_one_srcrec(q, &cp, owners, &fill, 1) < 0)
			return;
}

void
E 3
query_response_wrapup(q)
	register struct query *q;
{
	register HEADER *hdr;
	register struct query_stage *fins;

	hdr = (HEADER *)q->q_msg;
	fins = &q->q_stages[q->q_curstage];
	if (q->q_trace) {
		fprintf(q->q_trace,
			"final result from stage %d: code %d, flags %04x\n",
			q->q_curstage, fins->qs_result, fins->qs_flags);
		fprintf(q->q_trace, "CNAME count %d, answer count %d\n",
			fins->qs_cname_rrcount, fins->qs_answer_rrcount);
	}
	hdr->aa = (q->q_stages[0].qs_flags & QSFLAGS_AA) != 0;
	if (q->q_trace)
		fprintf(q->q_trace, "forwarded AA=%d from the first stage\n",
			hdr->aa);
	if (fins->qs_flags & QSFLAGS_TC) {
		if (q->q_trace)
			fprintf(q->q_trace,
			"final stage has TC set, setting TC in resp header\n");
		hdr->tc = 1;
I 5
		if (q->q_flags & QFLAGS_UDPSERV)
			stats_outgoing_udp_tc++;
		if (q->q_flags & QFLAGS_TCPSERV)
			stats_outgoing_tcp_tc++;
E 5
		goto out;
	}
	switch (fins->qs_result) {
	case QSRESULT_ANSWER:
		if (q->q_trace)
			fprintf(q->q_trace,
				"answer: need additional section\n");
D 3
		/* to be implemented */
E 3
I 3
		if (fins->qs_flags & QSFLAGS_ADD_FORWARDED) {
			if (q->q_trace)
				fprintf(q->q_trace,
			"AR section forwarded from foreign NS response\n");
		} else
			querywrap_make_ar(q, fins->qs_answer_rrcount,
					  hdr->nscount);
E 3
		break;
	case QSRESULT_NXDOMAIN:
		if (q->q_curstage == 0 || hdr->rd) {
			hdr->rcode = NXDOMAIN;
			if (q->q_trace)
				fputs("RCODE set to NXDOMAIN\n", q->q_trace);
		} else if (q->q_trace)
			fprintf(q->q_trace,
		"NXDOMAIN on stage %d with RD=0 NOT forwarded to RCODE\n",
				q->q_curstage);
		break;
	case QSRESULT_NOREC:
	case QSRESULT_CNAME:
		/* no further processing is needed for these */
		break;
	case QSRESULT_REFERRAL:
		if (q->q_trace)
			fprintf(q->q_trace,
				"referral: need additional section\n");
D 3
		/* to be implemented */
E 3
I 3
		if (fins->qs_flags & QSFLAGS_NS_ADD_DONE) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"AR section already populated from NS RRset\n");
		} else
			querywrap_make_ar(q, 0, hdr->nscount);
E 3
		break;
	case QSRESULT_NOTHING:
		if (q->q_curstage == 0) {
			hdr->rcode = SERVFAIL;
			if (q->q_trace)
				fprintf(q->q_trace,
			"result is NOTHING on stage 0, returning SERVFAIL\n");
		} else if (q->q_trace)
			fprintf(q->q_trace,
				"result in NOTHING on stage %d, ignoring\n",
				q->q_curstage);
		break;
	case QSRESULT_ERROR:
		if (q->q_trace)
			fputs("result is ERROR, returning SERVFAIL\n",
				q->q_trace);
		hdr->rcode = SERVFAIL;
I 10
		hdr->aa = 0;
E 10
		break;
	default:
		syslog(LOG_CRIT,
	"BUG in query_response_wrapup(): unexpected result code %d in switch",
			fins->qs_result);
		hdr->rcode = SERVFAIL;
	}
D 2
out:	if (q->q_trace) {
E 2
I 2
out:	q->q_msglen = q->q_msgptr - q->q_msg;
	if (q->q_trace) {
		fprintf(q->q_trace, "final answer: msglen=%d RCODE=%d\n",
			q->q_msglen, hdr->rcode);
E 2
		fprintf(q->q_trace,
D 2
	"final answer: RCODE=%d QDCOUNT=%d ANCOUNT=%d NSCOUNT=%d ARCOUNT=%d\n",
			hdr->rcode, hdr->qdcount, hdr->ancount, hdr->nscount,
			hdr->arcount);
E 2
I 2
			"QDCOUNT=%d ANCOUNT=%d NSCOUNT=%d ARCOUNT=%d\n",
			hdr->qdcount, hdr->ancount, hdr->nscount, hdr->arcount);
E 2
		query_trace_free(q);
	}
	hdr->qdcount = htons(hdr->qdcount);
	hdr->ancount = htons(hdr->ancount);
	hdr->nscount = htons(hdr->nscount);
	hdr->arcount = htons(hdr->arcount);
}
E 1
