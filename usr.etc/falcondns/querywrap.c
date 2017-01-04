/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * The final wrap-up phase of query handling (both UDP and TCP)
 */

#ifndef lint
static char sccsid[] = "@(#)querywrap.c	1.10 (IFCTF) 2013/01/13";
#endif

#include <sys/types.h>
#include <machine/endian.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "dname.h"
#include "query.h"
#include "class.h"
#include "tree.h"
#include "rr.h"
#include "globals.h"

extern u_char *msgparse_extract_dname();
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
	register int count = 0;
	struct dname owner;
	register int owner_set = 0;
	u_char *saveptr;

	minttl = n->n_zonehead->n_soa->soa_minimum;
	for (rr = n->n_rrzone; rr; rr = rr->rr_next) {
		if (rr->rr_type != T_A)
			continue;
		if (!owner_set) {
			dname_of_node(n, &owner);
			owner_set = 1;
			saveptr = q->q_msgptr;
		}
		if (emit_genrr_into_msg(q, &owner, rr, minttl) < 0) {
			q->q_msgptr = saveptr;
			stats_local_ar_tc++;
			return(-1);
		}
		count++;
	}
	hdr->arcount += count;
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
	case T_AFSDB:
		cp += 2;
		break;
	default:
		return(0);
	}
	ndn = owners + *fillp;
	if (!msgparse_extract_dname(ndn, cp, q->q_msgptr, q->q_msg)) {
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
		(*fillp)++;
	return(i);
}

void
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
		if (q->q_flags & QFLAGS_UDPSERV)
			stats_outgoing_udp_tc++;
		if (q->q_flags & QFLAGS_TCPSERV)
			stats_outgoing_tcp_tc++;
		goto out;
	}
	switch (fins->qs_result) {
	case QSRESULT_ANSWER:
		if (q->q_trace)
			fprintf(q->q_trace,
				"answer: need additional section\n");
		if (fins->qs_flags & QSFLAGS_ADD_FORWARDED) {
			if (q->q_trace)
				fprintf(q->q_trace,
			"AR section forwarded from foreign NS response\n");
		} else
			querywrap_make_ar(q, fins->qs_answer_rrcount,
					  hdr->nscount);
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
		if (fins->qs_flags & QSFLAGS_NS_ADD_DONE) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"AR section already populated from NS RRset\n");
		} else
			querywrap_make_ar(q, 0, hdr->nscount);
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
		hdr->aa = 0;
		break;
	default:
		syslog(LOG_CRIT,
	"BUG in query_response_wrapup(): unexpected result code %d in switch",
			fins->qs_result);
		hdr->rcode = SERVFAIL;
	}
out:	q->q_msglen = q->q_msgptr - q->q_msg;
	if (q->q_trace) {
		fprintf(q->q_trace, "final answer: msglen=%d RCODE=%d\n",
			q->q_msglen, hdr->rcode);
		fprintf(q->q_trace,
			"QDCOUNT=%d ANCOUNT=%d NSCOUNT=%d ARCOUNT=%d\n",
			hdr->qdcount, hdr->ancount, hdr->nscount, hdr->arcount);
		query_trace_free(q);
	}
	hdr->qdcount = htons(hdr->qdcount);
	hdr->ancount = htons(hdr->ancount);
	hdr->nscount = htons(hdr->nscount);
	hdr->arcount = htons(hdr->arcount);
}
