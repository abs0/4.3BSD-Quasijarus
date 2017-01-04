h10521
s 00001/00001/00181
d D 1.12 2013/01/13 07:02:40 msokolov 12 11
c new ttl-limit-neg setting, ttl-bump-{CNAME,NS} changed to numbers
e
s 00011/00008/00171
d D 1.11 2013/01/13 03:40:19 msokolov 11 10
c intquery_negative_ttl: the SOA we are parsing may come from the local
c FSR cache now - check AA to decide which TTL to go by
e
s 00001/00001/00178
d D 1.10 2013/01/06 07:04:05 msokolov 10 9
c MSDNS => FalconDNS
e
s 00041/00000/00138
d D 1.9 2011/12/22 07:44:00 msokolov 9 8
c intquery_negative_ttl() implemented
e
s 00001/00001/00137
d D 1.8 2011/12/19 20:48:30 msokolov 8 7
c intquery_extract_A_answer(): bug in the handling of multiple As
e
s 00019/00001/00119
d D 1.7 2011/12/11 07:30:27 msokolov 7 6
c internal queries: prep for NS-anchor refresh
e
s 00005/00008/00115
d D 1.6 2011/11/12 18:57:32 msokolov 6 5
c intquery_extract_A_answer: some work moved to the caller
e
s 00002/00013/00121
d D 1.5 2011/11/12 06:08:46 msokolov 5 4
c askforns done except for the subquery completion function
e
s 00015/00008/00119
d D 1.4 2011/11/11 21:04:48 msokolov 4 3
c intquery_extract_A_answer: return TTL as well
e
s 00048/00000/00079
d D 1.3 2011/11/11 06:01:46 msokolov 3 2
c intquery_extract_A_answer() implemented
e
s 00007/00000/00072
d D 1.2 2011/11/05 11:05:32 msokolov 2 1
c max-nested-queries setting implemented
e
s 00072/00000/00000
d D 1.1 2011/11/05 10:50:13 msokolov 1 0
c date and time created 2011/11/05 10:50:13 by msokolov
e
u
U
t
T
I 1
/*
D 10
 * Michael Sokolov's Domain Name Server (MSDNS)
E 10
I 10
 * FalconDNS daemon by Michael Spacefalcon
E 10
 *
 * Internal query logic
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 4
#include <machine/machparam.h>
E 4
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include "query.h"
#include "globals.h"

extern struct query *alloc_query_struct();
I 3
extern u_char *msgparse_skip_dname();
E 3

#define	INTQUERY_BUFSIZE	4096

struct query *
create_internal_query(parent)
	register struct query *parent;
{
	register struct query *q;
	register HEADER *hdr;

I 2
D 5
	if (parent && parent->q_nest_depth >= max_nested_queries) {
		if (parent->q_trace)
			fprintf(parent->q_trace,
"create_internal_query(): parent query %d has nest depth %d, exceeds limit\n",
				parent->q_trace_index, parent->q_nest_depth);
		return(0);
	}
E 5
E 2
	q = alloc_query_struct(INTQUERY_BUFSIZE);
D 5
	if (!q) {
		if (parent->q_trace)
			fputs("unable to malloc nested query\n",
				parent->q_trace);
		return(q);
	}
E 5
I 5
	if (!q)
		return(0);
E 5
	q->q_msg = (u_char *)q + sizeof(struct query);
	q->q_msg_maxlen = INTQUERY_BUFSIZE;
	q->q_flags = QFLAGS_INTERNAL;
I 4
	/* header init */
	bzero(q->q_msg + 2, 10);
E 4
	hdr = (HEADER *)q->q_msg;
D 4
	q->q_msg[2] = 0;
	q->q_msg[3] = 0;
E 4
	hdr->rd = 1;
	if (num_outbound_udp_sockets)
		hdr->ra = 1;
D 4
	hdr->qdcount = 0;
	hdr->ancount = 0;
	hdr->nscount = 0;
	hdr->arcount = 0;
E 4
	q->q_msgptr = q->q_msg + sizeof(HEADER);
	q->q_msg_endstop = q->q_msg + q->q_msg_maxlen;
	query_init_compress(q);
	q->q_curstage = 0;
	if (parent) {
		parent->q_child = q;
D 7
		q->q_parent = parent;
E 7
I 7
		q->q_parent = (caddr_t) parent;
E 7
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
I 7
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
E 7
I 3
}

D 4
intquery_extract_A_answer(q, addrbuf, addrmax)
E 4
I 4
intquery_extract_A_answer(q, addrbuf, addrmax, ttlptr)
E 4
	register struct query *q;
D 4
	u_long *addrbuf;
E 4
I 4
	u_long *addrbuf, *ttlptr;
E 4
	int addrmax;
{
D 6
	register struct query_stage *qs;
E 6
	register u_char *cp;
D 6
	register int rrcnt = 0, addrcnt = 0;
E 6
I 6
	register int rrcnt = 0, addrcnt = 0, answercnt;
E 6
	struct rrfixed fix;
I 4
	u_long ttl;
E 4

D 6
	qs = &q->q_stages[q->q_curstage];
E 6
I 6
	answercnt = q->q_stages[q->q_curstage].qs_answer_rrcount;
E 6
	if (q->q_trace)
		fprintf(q->q_trace,
D 6
			"intquery_extract_A_answer: result of stage %d is %d\n",
			q->q_curstage, qs->qs_result);
	if (qs->qs_result != QSRESULT_ANSWER)
		return(0);
E 6
I 6
			"intquery_extract_A_answer: %d answer RRs to examine\n",
			answercnt);
E 6
I 4
	ttl = ULONG_MAX;
E 4
	for (cp = q->q_answer_ptr; ; ) {
D 6
		if (rrcnt >= qs->qs_answer_rrcount)
E 6
I 6
		if (rrcnt >= answercnt)
E 6
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
D 8
			addrbuf += 4;
E 8
I 8
			addrbuf++;
E 8
			addrcnt++;
I 4
			if (fix.ttl < ttl)
				ttl = fix.ttl;
E 4
		} else if (q->q_trace)
			fprintf(q->q_trace,
			"TYPE=%d CLASS=%d RDLENGTH=%d: not what we expect\n",
				fix.type, fix.class, fix.rdlength);
		cp += fix.rdlength;
		rrcnt++;
	}
	if (q->q_trace)
		fprintf(q->q_trace, "got %d A record(s)\n", addrcnt);
I 4
	if (addrcnt) {
		if (q->q_trace)
			fprintf(q->q_trace, "TTL is %lu\n", ttl);
		if (ttlptr)
			*ttlptr = ttl;
	}
E 4
	return(addrcnt);
E 3
}
I 9

u_long
intquery_negative_ttl(q)
	register struct query *q;
{
	register u_char *cp;
	struct rrfixed fix;
	register u_long ttl, soamin;

D 12
	ttl = ttl_limit_nsneg;
E 12
I 12
	ttl = ttl_limit_ncache;
E 12
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
D 11
		cp = msgparse_skip_dname(cp, q->q_msgptr);
		if (!cp)
			break;
		cp = msgparse_skip_dname(cp, q->q_msgptr);
		if (!cp)
			break;
		cp += 16;
		GETLONG(soamin, cp);
E 11
I 11
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
E 11
		if (soamin < ttl)
			ttl = soamin;
		return(ttl);
	}
	if (q->q_stages[q->q_curstage].qs_result == QSRESULT_CNAME)
		return(ttl);
	else
		return(0);
}
E 9
E 1
