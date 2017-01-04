h12478
s 00005/00000/00168
d D 1.17 2013/01/14 00:46:43 msokolov 17 16
c return SERVFAIL until ready to serve
e
s 00002/00000/00166
d D 1.16 2013/01/13 15:31:46 msokolov 16 15
c duplicate query suppression implemented
e
s 00002/00002/00164
d D 1.15 2013/01/06 08:56:32 msokolov 15 14
c more sensible and consistent msgparse function naming:
c s/extract_dname_from_msg/msgparse_extract_dname/
c s/parse_incoming_rr/msgparse_rdata/
e
s 00001/00001/00165
d D 1.14 2013/01/06 07:03:55 msokolov 14 13
c MSDNS => FalconDNS
e
s 00012/00015/00154
d D 1.13 2011/12/23 06:57:23 msokolov 13 12
c allow querying for unknown RR types
e
s 00002/00000/00167
d D 1.12 2011/12/22 06:27:14 msokolov 12 11
c support for AA queries
e
s 00001/00000/00166
d D 1.11 2011/12/20 20:45:18 msokolov 11 10
c query flags slightly revamped
e
s 00005/00002/00161
d D 1.10 2011/12/14 00:59:14 msokolov 10 9
c enable AXFR
e
s 00001/00001/00162
d D 1.9 2011/12/07 23:41:21 msokolov 9 8
c QCLASS and QTYPE were swapped
e
s 00002/00002/00161
d D 1.8 2011/12/07 20:05:11 msokolov 8 7
c disallow back-pointers in QNAME
e
s 00003/00001/00160
d D 1.7 2011/12/07 19:13:11 msokolov 7 6
c set RA
e
s 00001/00000/00160
d D 1.6 2011/11/11 20:55:21 msokolov 6 5
c #include <machine/endian.h> for hton[ls] and ntoh[ls]
e
s 00001/00000/00159
d D 1.5 2011/11/05 10:50:03 msokolov 5 4
c q_nest_depth added
e
s 00003/00000/00156
d D 1.4 2011/11/01 03:32:23 msokolov 4 3
c compress-case-preserve setting implemented
e
s 00001/00000/00155
d D 1.3 2011/10/30 02:28:53 msokolov 3 2
c query trace hooked in
e
s 00037/00017/00118
d D 1.2 2011/10/30 01:16:51 msokolov 2 1
c query processing shaping up
e
s 00135/00000/00000
d D 1.1 2011/09/07 18:43:41 msokolov 1 0
c date and time created 2011/09/07 18:43:41 by msokolov
e
u
U
t
T
I 1
/*
D 14
 * Michael Sokolov's Domain Name Server (MSDNS)
E 14
I 14
 * FalconDNS daemon by Michael Spacefalcon
E 14
 *
 * The initial phase of query handling (both UDP and TCP)
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 6
#include <machine/endian.h>
E 6
#include <netinet/in.h>
#include <arpa/nameser.h>
I 17
#include "class.h"
E 17
#include "query.h"
#include "globals.h"
I 7
#include "acl.h"
E 7

D 15
extern u_char *extract_dname_from_msg();
E 15
I 15
extern u_char *msgparse_extract_dname();
E 15
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
D 2
 * are q_msg, q_msglen, q_msg_maxlen, q_sin, q_socket and q_callwhendone.
 * We have to take this query and handle it from here.
E 2
I 2
 * are q_msg, q_msglen, q_msg_maxlen, q_sin, q_socket and q_flags.
 * We parse/validate the incoming packet and prepare the query to be
 * handed to the first stage.
 *
 * Return value:
 *   0 = query good to go to the first stage
 *  -1 = immediate error, response packet is ready
E 2
 */
D 2
void
handle_query_initial(q, is_tcp)
E 2
I 2
handle_query_initial(q)
E 2
	register struct query *q;
{
	register HEADER *hdr;
	struct dname qname;
	int qclass;

D 2
	q->q_state = QSTATE_DOQUERY;
E 2
	hdr = (HEADER *)q->q_msg;
	/* Prepare the message to become a response */
	hdr->qr = 1;
I 12
	if (hdr->aa && allow_aa_queries)
		q->q_flags |= QFLAGS_WANT_AA;
E 12
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
D 2
		q->q_callwhendone(q);
		return;
E 2
I 2
		return(-1);
E 2
	}
	if (hdr->qdcount < 1) {
formerr:	hdr->rcode = FORMERR;
		goto short_response;
	}
	if (hdr->qdcount > 1)
		goto notimp;
	/* parse the query */
	q->q_msgptr = q->q_msg + sizeof(HEADER);
D 15
	q->q_msgptr = extract_dname_from_msg(&qname, q->q_msgptr,
E 15
I 15
	q->q_msgptr = msgparse_extract_dname(&qname, q->q_msgptr,
E 15
D 8
			q->q_msg + q->q_msglen, q->q_msg);
E 8
I 8
			q->q_msg + q->q_msglen, 0);
E 8
	if (!q->q_msgptr)
		goto formerr;
D 9
	GETSHORT(qclass, q->q_msgptr);
E 9
	GETSHORT(q->q_type, q->q_msgptr);
I 9
	GETSHORT(qclass, q->q_msgptr);
E 9
	if (q->q_msgptr - q->q_msg > q->q_msglen)
		goto formerr;
	/* figure out the class */
	if (qclass >= 255)
		goto notimp;
	q->q_class = class_array[qclass];
	if (!q->q_class)
		goto notimp;
I 17
	if (!q->q_class->c_ready_to_serve) {
		hdr->rcode = SERVFAIL;
		goto short_response;
	}
E 17
	/* initialize the query stage */
	q->q_curstage = 0;
D 8
	dname_copy_discontig(&qname, &q->q_stages[0].qs_qname);
E 8
I 8
	dname_copy(&qname, &q->q_stages[0].qs_qname);
E 8
D 2
	/* get AXFR queries out of the way */
	if (q->q_type == T_AXFR) {
E 2
I 2
	q->q_msg_endstop = q->q_msg + q->q_msg_maxlen;
	/* validate QTYPE */
	switch (q->q_type) {
D 13
	case T_A:
	case T_NS:
	case T_CNAME:
	case T_SOA:
	case T_MB:
	case T_MG:
	case T_MR:
	case T_WKS:
	case T_PTR:
	case T_HINFO:
	case T_MINFO:
	case T_MX:
	case T_TXT:
E 13
	case T_MAILB:
	case T_ANY:
D 13
		/* supported QTYPE, good */
E 13
I 13
		/* supported non-specific QTYPEs, good */
E 13
		break;
	case T_AXFR:
E 2
		/*
		 * If someone requests AXFR via UDP, which error code
		 * should we respond with?  The RFCs don't specify.
		 * NOTIMP seems wrong and so does REFUSED.
		 * Let's do FORMERR.
		 */
D 2
		if (!is_tcp)
E 2
I 2
		if (!(q->q_flags & QFLAGS_TCPSERV))
E 2
			goto formerr;
D 2
		/* the AXFR ACL check will go here */
		/* diversion to the AXFR code path will follow */
		/* but for now it is not implemented */
E 2
I 2
D 10
		/* the structure of the real AXFR code is still TBD */
E 2
		goto notimp;
E 10
I 10
		if (!(q->q_aclperm & ACL_ALLOW_AXFR)) {
			hdr->rcode = REFUSED;
			goto short_response;
		}
		return(1);
I 13
	case T_OPT:
		/* OPT makes no sense as a QTYPE */
		goto formerr;
E 13
E 10
I 2
	default:
D 13
		/* unknown / non-understood / unimplemented QTYPE */
E 13
I 13
		/*
		 * Allow data TYPEs whether we know them or not,
		 * but reject non-data ones.
		 */
		if (q->q_type >= 1 && q->q_type <= 127)
			break;
		if (q->q_type >= 256 && q->q_type <= 0xEFFF)
			break;
E 13
		goto notimp;
E 2
	}
D 7
	/* Here would be a reasonable point to set the RA bit */
E 7
I 7
	if (q->q_aclperm & ACL_ALLOW_RECURSE && num_outbound_udp_sockets)
		hdr->ra = 1;
E 7
	/* Keep/discard the question section, and init compression tree */
	query_init_compress(q);
	if (echo_question)
		echo_question_compress(q, &qname);
	else {
		hdr->qdcount = 0;
		q->q_msgptr = q->q_msg + sizeof(HEADER);
	}
D 2
	q->q_msg_remain = q->q_msg_maxlen - (q->q_msgptr - q->q_msg);
	/* we are now ready to hand it off to query_stage() */


E 2
I 2
	/* good to go to the first stage! */
I 4
	if (q->q_flags & compress_case_preserve &
	    (QFLAGS_TCPSERV | QFLAGS_UDPSERV))
		q->q_flags |= QFLAGS_COMPRESS_CASESEN;
I 11
	q->q_flags |= QFLAGS_WANT_AA_NS | QFLAGS_WANT_NEGSOA;
E 11
I 5
	q->q_nest_depth = 0;
E 5
E 4
I 3
	query_trace_init(q);
I 16
	q->q_dupcatch_backptr = 0;
	q->q_nextdup = 0;
E 16
E 3
	return(0);
E 2
}
E 1
