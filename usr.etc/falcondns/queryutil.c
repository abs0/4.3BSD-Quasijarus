/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Query-related utility functions
 */

#ifndef lint
static char sccsid[] = "@(#)queryutil.c	1.13 (IFCTF) 2013/08/10";
#endif

#include <sys/types.h>
#include <machine/endian.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "query.h"
#include "globals.h"

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
	newc->ch_next = 0;
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
		ch = ch->ch_next;
		q->q_curchunk = ch;
		q->q_curchunk_fill = 0;
	}
	cn = &ch->ch_nodes[q->q_curchunk_fill++];
	return(cn);
}

void
put_intquery_on_queue(q)
	register struct query *q;
{
	q->q_next = 0;
	*queryqueue_tail = q;
	queryqueue_tail = &q->q_next;
}

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

struct query *
take_query_from_queue()
{
	register struct query *q;

	q = queryqueue_head;
	queryqueue_head = q->q_next;
	if (!queryqueue_head)
		queryqueue_tail = &queryqueue_head;
	return(q);
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
}
