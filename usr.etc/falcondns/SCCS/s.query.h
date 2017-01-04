h38461
s 00004/00000/00115
d D 1.19 2013/01/13 15:31:44 msokolov 19 18
c duplicate query suppression implemented
e
s 00003/00006/00112
d D 1.18 2013/01/07 20:17:04 msokolov 18 17
c tcpserv revamped for multiple simultaneous queries on one connection
e
s 00003/00000/00115
d D 1.17 2011/12/20 20:45:17 msokolov 17 16
c query flags slightly revamped
e
s 00002/00000/00113
d D 1.16 2011/12/14 00:42:35 msokolov 16 15
c q_axfrptr overloaded on q_noa
e
s 00002/00002/00111
d D 1.15 2011/12/11 07:30:26 msokolov 15 14
c internal queries: prep for NS-anchor refresh
e
s 00001/00001/00112
d D 1.14 2011/12/07 20:00:41 msokolov 14 13
c preparations for the query wrap-up logic
e
s 00002/00001/00111
d D 1.13 2011/11/12 19:16:07 msokolov 13 12
c askforns retries logic better thought through
e
s 00005/00000/00107
d D 1.12 2011/11/11 09:01:29 msokolov 12 11
c new fields for the askforns service
e
s 00001/00000/00106
d D 1.11 2011/11/05 10:50:02 msokolov 11 10
c q_nest_depth added
e
s 00001/00001/00105
d D 1.10 2011/11/05 10:06:42 msokolov 10 9
c no need for a per-stage answer pointer
e
s 00012/00003/00094
d D 1.9 2011/11/02 06:55:11 msokolov 9 8
c query trace adapted for nested queries
e
s 00007/00004/00090
d D 1.8 2011/11/01 08:00:50 msokolov 8 7
c NOA concept rethought
e
s 00001/00000/00093
d D 1.7 2011/11/01 03:32:22 msokolov 7 6
c compress-case-preserve setting implemented
e
s 00001/00000/00092
d D 1.6 2011/11/01 02:40:17 msokolov 6 5
c udpserv ACL implemented
e
s 00011/00004/00081
d D 1.5 2011/10/30 01:16:49 msokolov 5 4
c query processing shaping up
e
s 00002/00000/00083
d D 1.4 2011/10/29 10:00:22 msokolov 4 3
c a couple of small additions
e
s 00026/00003/00057
d D 1.3 2011/10/29 05:42:31 msokolov 3 2
c coming along
e
s 00000/00001/00060
d D 1.2 2011/09/07 06:34:00 msokolov 2 1
c q_hdr member is redundant as it is always a direct cast of q_msg
e
s 00061/00000/00000
d D 1.1 2011/07/20 06:22:15 msokolov 1 0
c date and time created 2011/07/20 06:22:15 by msokolov
e
u
U
t
T
I 1
/*
D 18
 * MSDNS query processing data structures
E 18
I 18
 * FalconDNS query processing data structures
E 18
 *
 *	%W% (IFCTF) %E%
 */

#ifndef	__QUERY_H
#define	__QUERY_H

I 5
#include <stdio.h>
E 5
#include "defs.h"
#include "dname.h"

struct query_stage {
	struct	dname qs_qname;
D 10
	u_char	*qs_answer_ptr;
E 10
D 3
	int	qs_answer_rrcount;
E 3
I 3
	u_short	qs_cname_rrcount;
	u_short	qs_answer_rrcount;
	u_short	qs_result;
	u_short	qs_flags;
D 8
	struct	node *qs_noa;
	int	qs_noa_depth;	/* 0 means root */
E 8
E 3
};

I 3
#define	QSRESULT_ANSWER		0
#define	QSRESULT_NXDOMAIN	1
#define	QSRESULT_NOREC		2
#define	QSRESULT_CNAME		3
#define	QSRESULT_REFERRAL	4
#define	QSRESULT_NOTHING	5
D 8
#define	QSRESULT_REMOTE_ERR	6
I 4
#define	QSRESULT_TC		7
E 8
I 8
D 9
#define	QSRESULT_LOCAL_ERR	6
#define	QSRESULT_REMOTE_ERR	7
#define	QSRESULT_TC		8
E 9
I 9
#define	QSRESULT_ERROR		6
#define	QSRESULT_TC		7
E 9
E 8
E 4

#define	QSFLAGS_AA		0x8000
#define	QSFLAGS_TC		0x4000
I 8
#define	QSFLAGS_NS_ADD_DONE	0x2000
I 14
#define	QSFLAGS_ADD_FORWARDED	0x1000
E 14
E 8

E 3
struct compress_node {
	u_char	*cn_label;
	struct	compress_node *cn_nextsib;
	struct	compress_node *cn_firstchild;
};

struct compress_chunk {
	struct	compress_node ch_nodes[COMPRESS_NODES_PER_CHUNK];
	struct	compress_chunk *ch_next;
};

struct query {
	/* very general */
	int	q_state;
	struct	sockaddr_in q_sin;
I 6
	int	q_aclperm;
E 6
	int	q_socket;
	void	(*q_callwhendone)();
I 3
	int	q_flags;
	struct	query *q_next;
E 3
	/* message Rx/Tx */
	u_char	*q_msg;
	int	q_msglen;
	int	q_msg_maxlen;
	u_char	*q_msgptr;
D 18
	int	q_msg_remain;
E 18
I 3
	u_char	*q_msg_endstop;
E 3
	/* deeper query processing */
	struct	class *q_class;
	int	q_type;
	struct	query_stage q_stages[MAX_CNAME_CHAIN+1];
	int	q_curstage;
I 10
	u_char	*q_answer_ptr;
E 10
I 8
	/* recursive / full service resolver operation */
	struct	node *q_noa;
	int	q_noa_depth;	/* 0 means NOA=. */
I 12
	struct	udpout *q_udpout;
	void	(*q_askforns_response_callbk)();
	void	(*q_askforns_error_callbk)();
	struct	timesched *q_timeout;
D 13
	int	q_retrycnt;
E 13
I 13
	u_short	q_retrycnt;
	u_short	q_retrylimit;
E 13
E 12
I 9
D 15
	/* nested queries */
	struct	query *q_parent;
E 15
I 15
	/* nested/internal queries */
	caddr_t	q_parent;
E 15
	struct	query *q_child;
I 11
	int	q_nest_depth;
E 11
E 9
E 8
D 2
	HEADER	*q_hdr;
E 2
	/* management of compression nodes */
	struct	compress_chunk q_initial_chunk;
	struct	compress_chunk *q_curchunk;
	int	q_curchunk_fill;
	struct	compress_node *q_first_cnode;
I 5
	/* debug trace */
	FILE	*q_trace;
	int	q_trace_index;
I 9
	struct	querytrace *q_trace_mgmt;
I 19
	/* query dedup logic */
	struct	query **q_dupcatch_backptr;
	struct	query *q_dupcatch_next;
	struct	query *q_nextdup;
E 19
E 9
E 5
};

I 16
#define	q_axfrptr	q_noa			/* member overloading */

E 16
D 18
#define	QSTATE_TCPRDLEN		0
#define	QSTATE_TCPRDMSG		1
E 18
I 18
#define	QSTATE_STAGE		0
#define	QSTATE_COMPLETE		1
E 18
D 5
#define	QSTATE_DOQUERY		2
D 3
#define	QSTATE_RSPOUT		3
#define	QSTATE_RSPOUT_AXFR	4
E 3
I 3
#define	QSTATE_COMPLETE		3
#define	QSTATE_RSPOUT		4
#define	QSTATE_RSPOUT_AXFR	5
E 5
I 5
#define	QSTATE_RSPOUT		2
#define	QSTATE_RSPOUT_AXFR	3
D 18
#define	QSTATE_STAGE		4
#define	QSTATE_COMPLETE		5
E 18
D 14
#define	QSTATE_FOREIGN		6
E 14
E 5

#define	QFLAGS_INTERNAL			0x8000
#define	QFLAGS_COMPRESS_CASESEN		0x4000
I 4
#define	QFLAGS_WANT_GLUE		0x2000
I 17
#define	QFLAGS_WANT_AA			0x1000
#define	QFLAGS_WANT_AA_NS		0x0800
#define	QFLAGS_WANT_NEGSOA		0x0400
E 17
I 7
#define	QFLAGS_AXFR_CASEPRESERVE	0x0004	/* compress_case_preserve bit */
E 7
I 5
#define	QFLAGS_TCPSERV			0x0002
#define	QFLAGS_UDPSERV			0x0001
I 9

struct querytrace {
	FILE	*qt_file;
	int	qt_refcount;
	int	qt_linearcount;
};
E 9
E 5
E 4
E 3

#endif	/* include guard */
E 1
