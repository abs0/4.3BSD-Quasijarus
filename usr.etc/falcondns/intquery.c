/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Internal query logic
 */

#ifndef lint
static char sccsid[] = "@(#)intquery.c	1.12 (IFCTF) 2013/01/13";
#endif

#include <sys/types.h>
#include <machine/machparam.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include "query.h"
#include "globals.h"

extern struct query *alloc_query_struct();
extern u_char *msgparse_skip_dname();

#define	INTQUERY_BUFSIZE	4096

struct query *
create_internal_query(parent)
	register struct query *parent;
{
	register struct query *q;
	register HEADER *hdr;

	q = alloc_query_struct(INTQUERY_BUFSIZE);
	if (!q)
		return(0);
	q->q_msg = (u_char *)q + sizeof(struct query);
	q->q_msg_maxlen = INTQUERY_BUFSIZE;
	q->q_flags = QFLAGS_INTERNAL;
	/* header init */
	bzero(q->q_msg + 2, 10);
	hdr = (HEADER *)q->q_msg;
	hdr->rd = 1;
	if (num_outbound_udp_sockets)
		hdr->ra = 1;
	q->q_msgptr = q->q_msg + sizeof(HEADER);
	q->q_msg_endstop = q->q_msg + q->q_msg_maxlen;
	query_init_compress(q);
	q->q_curstage = 0;
	if (parent) {
		parent->q_child = q;
		q->q_parent = (caddr_t) parent;
		q->q_nest_depth = parent->q_nest_depth + 1;
		if (parent->q_trace) {
			q->q_trace = parent->q_trace;
			q->q_trace_mgmt = parent->q_trace_mgmt;
			q->q_trace_index = ++q->q_trace_mgmt->qt_linearcount;
			q->q_trace_mgmt->qt_refcount++;
			fprintf(q->q_trace,
				"nested query #%d spawned from #%d\n",
				q->q_trace_index, parent->q_trace_index);
		} else
			q->q_trace = NULL;
	} else {
		q->q_nest_depth = 0;
		q->q_trace = NULL;
	}
	return(q);
}

reuse_internal_query(q)
	register struct query *q;
{
	register HEADER *hdr;

	q->q_flags = QFLAGS_INTERNAL;
	/* header init */
	bzero(q->q_msg + 2, 10);
	hdr = (HEADER *)q->q_msg;
	hdr->rd = 1;
	if (num_outbound_udp_sockets)
		hdr->ra = 1;
	q->q_msgptr = q->q_msg + sizeof(HEADER);
	q->q_msg_endstop = q->q_msg + q->q_msg_maxlen;
	query_init_compress(q);
	q->q_curstage = 0;
}

intquery_extract_A_answer(q, addrbuf, addrmax, ttlptr)
	register struct query *q;
	u_long *addrbuf, *ttlptr;
	int addrmax;
{
	register u_char *cp;
	register int rrcnt = 0, addrcnt = 0, answercnt;
	struct rrfixed fix;
	u_long ttl;

	answercnt = q->q_stages[q->q_curstage].qs_answer_rrcount;
	if (q->q_trace)
		fprintf(q->q_trace,
			"intquery_extract_A_answer: %d answer RRs to examine\n",
			answercnt);
	ttl = ULONG_MAX;
	for (cp = q->q_answer_ptr; ; ) {
		if (rrcnt >= answercnt)
			break;
		if (addrcnt >= addrmax)
			break;
		cp = msgparse_skip_dname(cp, q->q_msgptr);
		if (!cp) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"error skipping over RR owner field!\n");
			break;
		}
		msgparse_get_rrfix(cp, &fix);
		cp += RRFIXEDSZ;
		if (fix.type == T_A && fix.class == C_IN && fix.rdlength == 4) {
			bcopy(cp, addrbuf, 4);
			addrbuf++;
			addrcnt++;
			if (fix.ttl < ttl)
				ttl = fix.ttl;
		} else if (q->q_trace)
			fprintf(q->q_trace,
			"TYPE=%d CLASS=%d RDLENGTH=%d: not what we expect\n",
				fix.type, fix.class, fix.rdlength);
		cp += fix.rdlength;
		rrcnt++;
	}
	if (q->q_trace)
		fprintf(q->q_trace, "got %d A record(s)\n", addrcnt);
	if (addrcnt) {
		if (q->q_trace)
			fprintf(q->q_trace, "TTL is %lu\n", ttl);
		if (ttlptr)
			*ttlptr = ttl;
	}
	return(addrcnt);
}

u_long
intquery_negative_ttl(q)
	register struct query *q;
{
	register u_char *cp;
	struct rrfixed fix;
	register u_long ttl, soamin;

	ttl = ttl_limit_ncache;
	for (cp = q->q_msg + sizeof(HEADER); ; ) {
		cp = msgparse_skip_dname(cp, q->q_msgptr);
		if (!cp)
			break;
		msgparse_get_rrfix(cp, &fix);
		cp += RRFIXEDSZ;
		if (fix.type == T_CNAME) {
			if (fix.ttl < ttl)
				ttl = fix.ttl;
			cp += fix.rdlength;
			continue;
		}
		if (fix.type != T_SOA)
			break;
		if (q->q_stages[q->q_curstage].qs_flags & QSFLAGS_AA) {
			cp = msgparse_skip_dname(cp, q->q_msgptr);
			if (!cp)
				break;
			cp = msgparse_skip_dname(cp, q->q_msgptr);
			if (!cp)
				break;
			cp += 16;
			GETLONG(soamin, cp);
		} else
			soamin = fix.ttl;
		if (soamin < ttl)
			ttl = soamin;
		return(ttl);
	}
	if (q->q_stages[q->q_curstage].qs_result == QSRESULT_CNAME)
		return(ttl);
	else
		return(0);
}
