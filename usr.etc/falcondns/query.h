/*
 * FalconDNS query processing data structures
 *
 *	@(#)query.h	1.19 (IFCTF) 2013/01/13
 */

#ifndef	__QUERY_H
#define	__QUERY_H

#include <stdio.h>
#include "defs.h"
#include "dname.h"

struct query_stage {
	struct	dname qs_qname;
	u_short	qs_cname_rrcount;
	u_short	qs_answer_rrcount;
	u_short	qs_result;
	u_short	qs_flags;
};

#define	QSRESULT_ANSWER		0
#define	QSRESULT_NXDOMAIN	1
#define	QSRESULT_NOREC		2
#define	QSRESULT_CNAME		3
#define	QSRESULT_REFERRAL	4
#define	QSRESULT_NOTHING	5
#define	QSRESULT_ERROR		6
#define	QSRESULT_TC		7

#define	QSFLAGS_AA		0x8000
#define	QSFLAGS_TC		0x4000
#define	QSFLAGS_NS_ADD_DONE	0x2000
#define	QSFLAGS_ADD_FORWARDED	0x1000

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
	int	q_aclperm;
	int	q_socket;
	void	(*q_callwhendone)();
	int	q_flags;
	struct	query *q_next;
	/* message Rx/Tx */
	u_char	*q_msg;
	int	q_msglen;
	int	q_msg_maxlen;
	u_char	*q_msgptr;
	u_char	*q_msg_endstop;
	/* deeper query processing */
	struct	class *q_class;
	int	q_type;
	struct	query_stage q_stages[MAX_CNAME_CHAIN+1];
	int	q_curstage;
	u_char	*q_answer_ptr;
	/* recursive / full service resolver operation */
	struct	node *q_noa;
	int	q_noa_depth;	/* 0 means NOA=. */
	struct	udpout *q_udpout;
	void	(*q_askforns_response_callbk)();
	void	(*q_askforns_error_callbk)();
	struct	timesched *q_timeout;
	u_short	q_retrycnt;
	u_short	q_retrylimit;
	/* nested/internal queries */
	caddr_t	q_parent;
	struct	query *q_child;
	int	q_nest_depth;
	/* management of compression nodes */
	struct	compress_chunk q_initial_chunk;
	struct	compress_chunk *q_curchunk;
	int	q_curchunk_fill;
	struct	compress_node *q_first_cnode;
	/* debug trace */
	FILE	*q_trace;
	int	q_trace_index;
	struct	querytrace *q_trace_mgmt;
	/* query dedup logic */
	struct	query **q_dupcatch_backptr;
	struct	query *q_dupcatch_next;
	struct	query *q_nextdup;
};

#define	q_axfrptr	q_noa			/* member overloading */

#define	QSTATE_STAGE		0
#define	QSTATE_COMPLETE		1
#define	QSTATE_RSPOUT		2
#define	QSTATE_RSPOUT_AXFR	3

#define	QFLAGS_INTERNAL			0x8000
#define	QFLAGS_COMPRESS_CASESEN		0x4000
#define	QFLAGS_WANT_GLUE		0x2000
#define	QFLAGS_WANT_AA			0x1000
#define	QFLAGS_WANT_AA_NS		0x0800
#define	QFLAGS_WANT_NEGSOA		0x0400
#define	QFLAGS_AXFR_CASEPRESERVE	0x0004	/* compress_case_preserve bit */
#define	QFLAGS_TCPSERV			0x0002
#define	QFLAGS_UDPSERV			0x0001

struct querytrace {
	FILE	*qt_file;
	int	qt_refcount;
	int	qt_linearcount;
};

#endif	/* include guard */
