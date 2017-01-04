h19165
s 00051/00003/00103
d D 1.13 2013/08/10 07:11:42 msokolov 13 12
c external queries bypass the queue
e
s 00001/00000/00105
d D 1.12 2013/01/07 04:12:26 msokolov 12 11
c fixed a buglet in the more-compression-chunks logic
e
s 00001/00001/00104
d D 1.11 2013/01/06 07:03:46 msokolov 11 10
c MSDNS => FalconDNS
e
s 00000/00017/00105
d D 1.10 2011/12/07 21:10:40 msokolov 10 9
c query_response_byteswap_counts() absorbed into query_response_wrapup()
e
s 00001/00000/00121
d D 1.9 2011/11/11 20:55:19 msokolov 9 8
c #include <machine/endian.h> for hton[ls] and ntoh[ls]
e
s 00000/00020/00121
d D 1.8 2011/11/01 08:00:49 msokolov 8 7
c NOA concept rethought
e
s 00001/00001/00140
d D 1.7 2011/11/01 03:58:12 msokolov 7 6
c brown paper bag
e
s 00006/00027/00135
d D 1.6 2011/10/30 01:16:50 msokolov 6 5
c query processing shaping up
e
s 00020/00000/00142
d D 1.5 2011/10/29 18:37:59 msokolov 5 4
c release_query_noa_subtrees() function added
e
s 00045/00000/00097
d D 1.4 2011/10/29 05:46:04 msokolov 4 3
c query queue operations added
e
s 00017/00000/00080
d D 1.3 2011/09/07 06:33:09 msokolov 3 2
c query_response_byteswap_counts() function added
e
s 00001/00001/00079
d D 1.2 2011/08/13 19:14:59 msokolov 2 1
c simple bug
e
s 00080/00000/00000
d D 1.1 2011/07/20 06:22:15 msokolov 1 0
c date and time created 2011/07/20 06:22:15 by msokolov
e
u
U
t
T
I 1
/*
D 11
 * Michael Sokolov's Domain Name Server (MSDNS)
E 11
I 11
 * FalconDNS daemon by Michael Spacefalcon
E 11
 *
 * Query-related utility functions
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 9
#include <machine/endian.h>
E 9
#include <netinet/in.h>
#include <arpa/nameser.h>
I 13
#include <syslog.h>
E 13
#include "query.h"
I 4
#include "globals.h"
E 4

extern u_char *myalloc();

struct query *
alloc_query_struct(extra)
{
	register struct query *q;

	q = (struct query *)myalloc(sizeof(struct query) + extra);
	if (q)
		q->q_initial_chunk.ch_next = 0;
	return(q);
}

free_query_struct(q)
	register struct query *q;
{
	register struct compress_chunk *ch, *next;

	ch = q->q_initial_chunk.ch_next;
	free(q);
	for (; ch; ch = next) {
		next = ch->ch_next;
		free(ch);
	}
}

query_init_compress(q)
	register struct query *q;
{
	q->q_curchunk = &q->q_initial_chunk;
	q->q_curchunk_fill = 0;
	q->q_first_cnode = 0;
}

static
add_chunk(oldc)
	struct compress_chunk *oldc;
{
	register struct compress_chunk *newc;

	newc = (struct compress_chunk *)myalloc(sizeof(struct compress_chunk));
	if (!newc)
		return(-1);
	oldc->ch_next = newc;
I 12
	newc->ch_next = 0;
E 12
	return(0);
}

struct compress_node *
get_compress_node(q)
	register struct query *q;
{
	register struct compress_chunk *ch;
	register struct compress_node *cn;

	ch = q->q_curchunk;
	if (q->q_curchunk_fill >= COMPRESS_NODES_PER_CHUNK) {
		if (!ch->ch_next && add_chunk(ch) < 0)
			return(0);
D 2
		ch->ch_next;
E 2
I 2
		ch = ch->ch_next;
E 2
		q->q_curchunk = ch;
		q->q_curchunk_fill = 0;
	}
	cn = &ch->ch_nodes[q->q_curchunk_fill++];
	return(cn);
}
I 3

D 10
/*
 * This helper function needs to be called by q_callwhendone functions
 * before sending the response message over the wire.
 */
void
query_response_byteswap_counts(q)
	struct query *q;
{
	register HEADER *hdr;

	hdr = (HEADER *)q->q_msg;
	hdr->qdcount = htons(hdr->qdcount);
	hdr->ancount = htons(hdr->ancount);
	hdr->nscount = htons(hdr->nscount);
	hdr->arcount = htons(hdr->arcount);
I 4
}

E 10
void
D 6
put_query_on_queue(q)
E 6
I 6
D 13
put_query_on_queue(q, s)
E 13
I 13
put_intquery_on_queue(q)
E 13
E 6
	register struct query *q;
I 6
D 13
	int s;
E 13
E 6
{
D 6
	q->q_state = QSTATE_DOQUERY;
E 6
I 6
D 13
	q->q_state = s;
E 13
E 6
	q->q_next = 0;
	*queryqueue_tail = q;
	queryqueue_tail = &q->q_next;
}

I 13
void
stage_query(q)
	register struct query *q;
{
	q->q_state = QSTATE_STAGE;
	if (q->q_flags & QFLAGS_INTERNAL)
		put_intquery_on_queue(q);
	else
		query_stage_process(q);
}

void
query_complete(q)
	register struct query *q;
{
	if (q->q_flags & QFLAGS_INTERNAL) {
		q->q_state = QSTATE_COMPLETE;
		put_intquery_on_queue(q);
	} else {
		query_response_wrapup(q);
		q->q_state = QSTATE_RSPOUT;
		if (q->q_dupcatch_backptr) {
			*q->q_dupcatch_backptr = q->q_dupcatch_next;
			if (q->q_dupcatch_next)
				q->q_dupcatch_next->q_dupcatch_backptr =
					q->q_dupcatch_backptr;
		}
		q->q_callwhendone(q);
	}
}

E 13
struct query *
take_query_from_queue()
{
	register struct query *q;

	q = queryqueue_head;
	queryqueue_head = q->q_next;
	if (!queryqueue_head)
		queryqueue_tail = &queryqueue_head;
	return(q);
I 13
}

/* this queue is now used only for internal queries */
query_queue_dispatch(q)
	register struct query *q;
{
	switch (q->q_state) {
	case QSTATE_STAGE:
		query_stage_process(q);
		return;
	case QSTATE_COMPLETE:
		q->q_callwhendone(q);
		return;
	default:
		syslog(LOG_CRIT, "BUG: bad state %d in query_queue_dispatch()",
			q->q_state);
		abort();
	}
E 13
}
D 8

D 6
void
put_query_on_complq(q)
	register struct query *q;
{
	q->q_state = QSTATE_COMPLETE;
	q->q_next = 0;
	*querycompl_tail = q;
	querycompl_tail = &q->q_next;
}

struct query *
take_query_from_complq()
{
	register struct query *q;

	q = querycompl_head;
	querycompl_head = q->q_next;
	if (!querycompl_head)
		querycompl_tail = &querycompl_head;
	return(q);
E 4
}
I 5

E 6
/*
 * The query processing stages increment the n_refcount field
 * for the NOA of each stage, so that these nodes/subtrees are
 * guaranteed to still be there if they are needed for later
 * processing such as handling recursive responses or the final
 * wrap-up.
 *
 * This function releases the NOA subtrees.
 */
void
release_query_noa_subtrees(q)
	register struct query *q;
{
	register int i;

D 6
	for (i = 0; i < q->q_curstage; i++)
		if (q->q_stages[q->q_curstage].qs_noa)
			free(q->q_stages[q->q_curstage].qs_noa);
E 6
I 6
	for (i = 0; i <= q->q_curstage; i++)
		if (q->q_stages[i].qs_noa)
D 7
			free(q->q_stages[i].qs_noa);
E 7
I 7
			free_subtree(q->q_stages[i].qs_noa);
E 7
E 6
}
E 8
E 5
E 3
E 1
