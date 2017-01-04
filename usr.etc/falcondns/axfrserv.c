/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * AXFR server logic: answering AXFR queries with our in-memory data
 */

#ifndef lint
static char sccsid[] = "@(#)axfrserv.c	1.4 (IFCTF) 2013/01/11";
#endif

#include <sys/types.h>
#include <machine/endian.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "class.h"
#include "tree.h"
#include "zone.h"
#include "query.h"
#include "globals.h"

extern struct node *find_node_by_dname();

void
axfrserv_release(q)
	struct query *q;
{
	register struct node *n;

	n = q->q_axfrptr->n_zonehead;
	free_struct_zone(n->n_zone);
	free_subtree(n);
}

void
axfrserv_emit_node(q, n)
	register struct query *q;
	register struct node *n;
{
	register HEADER *hdr;

	hdr = (HEADER *)q->q_msg;
	hdr->ancount = 0;
	query_init_compress(q);
	q->q_msgptr = q->q_msg + sizeof(HEADER);
	q->q_stages[0].qs_answer_rrcount = 0;
	q->q_stages[0].qs_flags = 0;
	if (qstage_answer_from_zone(q, n, 0) < 0) {
		syslog(LOG_ERR,
		"AXFR out: node in zone %s (%d) fails to fit into TCP message",
			n->n_zone->z_ascii_domname, n->n_class->c_class);
		hdr->tc = 1;
	} else
		hdr->tc = 0;
	hdr->ancount = htons(hdr->ancount);
	q->q_msglen = q->q_msgptr - q->q_msg;
	q->q_axfrptr = n;
}

void
axfrserv_start(q)
	register struct query *q;
{
	register HEADER *hdr;
	register struct node *n;

	hdr = (HEADER *)q->q_msg;
	hdr->qdcount = 0;
	n = find_node_by_dname(q->q_class, &q->q_stages[0].qs_qname);
	if (!n || !n->n_zone) {
		/*
		 * What should we do if the requested domain node exists,
		 * but is not a zone head?  None of the RFCs I've read
		 * had an answer.  We return NXDOMAIN, but no AA.
		 */
		hdr->rcode = NXDOMAIN;
		q->q_msglen = sizeof(HEADER);
		q->q_state = QSTATE_RSPOUT;
		return;
	}
	n->n_refcount++;
	n->n_zone->z_refcount++;
	if (compress_case_preserve & QFLAGS_AXFR_CASEPRESERVE)
		q->q_flags |= QFLAGS_COMPRESS_CASESEN;
	q->q_trace = 0;
	hdr->aa = 1;
	axfrserv_emit_node(q, n);
	q->q_state = QSTATE_RSPOUT_AXFR;
}

void
axfrserv_continue(q)
	register struct query *q;
{
	register struct node *p, *n;

	p = q->q_axfrptr;
	for (n = p->n_nextinzone; n; n = n->n_nextinzone)
		if (n->n_rrzone || n->n_ns)
			break;
	if (n) {
		axfrserv_emit_node(q, n);
		q->q_state = QSTATE_RSPOUT_AXFR;
	} else {
		axfrserv_emit_node(q, p->n_zonehead);
		axfrserv_release(q);
		q->q_state = QSTATE_RSPOUT;
	}
}
