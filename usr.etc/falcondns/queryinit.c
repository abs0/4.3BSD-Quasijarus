/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * The initial phase of query handling (both UDP and TCP)
 */

#ifndef lint
static char sccsid[] = "@(#)queryinit.c	1.17 (IFCTF) 2013/01/14";
#endif

#include <sys/types.h>
#include <machine/endian.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include "class.h"
#include "query.h"
#include "globals.h"
#include "acl.h"

extern u_char *msgparse_extract_dname();
extern struct compress_node *get_compress_node();

/*
 * This function creates compression tree nodes for the labels which
 * make up the QNAME in the echoed question section.  Because it
 * can be called only right after query_init_compress(), the code
 * takes two shortcuts:
 *
 * - the starting tree is known to be empty;
 * - get_compress_node() is used without checking for malloc failures
 *   because the number of nodes in the initial chunk should be enough
 *   for the maximum number of labels in a dname.
 */
static void
echo_question_compress(q, qname)
	struct query *q;
	register struct dname *qname;
{
	register int i;
	register struct compress_node *cn, **cnp;

	cnp = &q->q_first_cnode;
	for (i = qname->dn_nlabels; --i >= 0; ) {
		cn = get_compress_node(q);
		cn->cn_label = qname->dn_labels[i];
		cn->cn_nextsib = 0;
		cn->cn_firstchild = 0;
		*cnp = cn;
		cnp = &cn->cn_firstchild;
	}
}

/*
 * When this function is called, the only valid members of struct query
 * are q_msg, q_msglen, q_msg_maxlen, q_sin, q_socket and q_flags.
 * We parse/validate the incoming packet and prepare the query to be
 * handed to the first stage.
 *
 * Return value:
 *   0 = query good to go to the first stage
 *  -1 = immediate error, response packet is ready
 */
handle_query_initial(q)
	register struct query *q;
{
	register HEADER *hdr;
	struct dname qname;
	int qclass;

	hdr = (HEADER *)q->q_msg;
	/* Prepare the message to become a response */
	hdr->qr = 1;
	if (hdr->aa && allow_aa_queries)
		q->q_flags |= QFLAGS_WANT_AA;
	hdr->aa = 0;
	hdr->tc = 0;
	q->q_msg[3] = 0;
	hdr->qdcount = ntohs(hdr->qdcount);
	hdr->ancount = 0;
	hdr->nscount = 0;
	hdr->arcount = 0;
	/* basic query sanity checking */
	if (hdr->opcode != QUERY) {
notimp:		hdr->rcode = NOTIMP;
short_response:	hdr->qdcount = 0;
		q->q_msglen = sizeof(HEADER);
		return(-1);
	}
	if (hdr->qdcount < 1) {
formerr:	hdr->rcode = FORMERR;
		goto short_response;
	}
	if (hdr->qdcount > 1)
		goto notimp;
	/* parse the query */
	q->q_msgptr = q->q_msg + sizeof(HEADER);
	q->q_msgptr = msgparse_extract_dname(&qname, q->q_msgptr,
			q->q_msg + q->q_msglen, 0);
	if (!q->q_msgptr)
		goto formerr;
	GETSHORT(q->q_type, q->q_msgptr);
	GETSHORT(qclass, q->q_msgptr);
	if (q->q_msgptr - q->q_msg > q->q_msglen)
		goto formerr;
	/* figure out the class */
	if (qclass >= 255)
		goto notimp;
	q->q_class = class_array[qclass];
	if (!q->q_class)
		goto notimp;
	if (!q->q_class->c_ready_to_serve) {
		hdr->rcode = SERVFAIL;
		goto short_response;
	}
	/* initialize the query stage */
	q->q_curstage = 0;
	dname_copy(&qname, &q->q_stages[0].qs_qname);
	q->q_msg_endstop = q->q_msg + q->q_msg_maxlen;
	/* validate QTYPE */
	switch (q->q_type) {
	case T_MAILB:
	case T_ANY:
		/* supported non-specific QTYPEs, good */
		break;
	case T_AXFR:
		/*
		 * If someone requests AXFR via UDP, which error code
		 * should we respond with?  The RFCs don't specify.
		 * NOTIMP seems wrong and so does REFUSED.
		 * Let's do FORMERR.
		 */
		if (!(q->q_flags & QFLAGS_TCPSERV))
			goto formerr;
		if (!(q->q_aclperm & ACL_ALLOW_AXFR)) {
			hdr->rcode = REFUSED;
			goto short_response;
		}
		return(1);
	case T_OPT:
		/* OPT makes no sense as a QTYPE */
		goto formerr;
	default:
		/*
		 * Allow data TYPEs whether we know them or not,
		 * but reject non-data ones.
		 */
		if (q->q_type >= 1 && q->q_type <= 127)
			break;
		if (q->q_type >= 256 && q->q_type <= 0xEFFF)
			break;
		goto notimp;
	}
	if (q->q_aclperm & ACL_ALLOW_RECURSE && num_outbound_udp_sockets)
		hdr->ra = 1;
	/* Keep/discard the question section, and init compression tree */
	query_init_compress(q);
	if (echo_question)
		echo_question_compress(q, &qname);
	else {
		hdr->qdcount = 0;
		q->q_msgptr = q->q_msg + sizeof(HEADER);
	}
	/* good to go to the first stage! */
	if (q->q_flags & compress_case_preserve &
	    (QFLAGS_TCPSERV | QFLAGS_UDPSERV))
		q->q_flags |= QFLAGS_COMPRESS_CASESEN;
	q->q_flags |= QFLAGS_WANT_AA_NS | QFLAGS_WANT_NEGSOA;
	q->q_nest_depth = 0;
	query_trace_init(q);
	q->q_dupcatch_backptr = 0;
	q->q_nextdup = 0;
	return(0);
}
