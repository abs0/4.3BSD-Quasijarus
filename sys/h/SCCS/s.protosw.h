h18486
s 00010/00005/00184
d D 7.3 88/06/27 18:54:12 bostic 30 29
c install approved copyright notice
e
s 00008/00002/00181
d D 7.2 87/12/30 12:04:47 bostic 29 28
c add Berkeley header
e
s 00001/00001/00182
d D 7.1 86/06/04 23:26:34 mckusick 28 27
c 4.3BSD release version
e
s 00001/00002/00182
d D 6.7 86/02/20 14:08:32 karels 27 26
c PRC_GWDOWN is unused
e
s 00002/00001/00182
d D 6.6 85/08/22 11:46:20 walsh 26 25
c mechanism for sending gateway down info to protocol to redirect connections
e
s 00007/00001/00176
d D 6.5 85/06/08 15:05:04 mckusick 25 24
c Add copyright
e
s 00024/00000/00153
d D 6.4 85/03/07 22:02:00 karels 24 23
c pr_ctloutput
e
s 00001/00001/00152
d D 6.3 84/08/21 10:16:21 karels 23 22
c add RIGHTS type for mbufs, use m_act correctly for queuing datagrams
c (for sam)
e
s 00000/00000/00153
d D 6.2 83/09/19 14:22:42 mckusick 22 19
i 21 20
c clean-ups to icmp from wnj
e
s 00016/00014/00135
d D 4.16.1.2 83/09/09 18:45:30 mckusick 21 20
c cleanup icmp (wnj - from shannon)
e
s 00000/00000/00149
d D 4.16.1.1 83/09/09 18:16:40 mckusick 20 16
c branch-place-holder
e
s 00000/00000/00151
d D 6.1 83/07/29 06:13:35 sam 19 18
c 4.2 distribution
e
s 00009/00008/00142
d D 4.18 83/07/25 21:53:11 sam 18 17
c getpeer
e
s 00002/00001/00148
d D 4.17 83/07/20 16:24:44 helge 17 16
c didn't get fixed when connect2 was added
e
s 00005/00004/00144
d D 4.16 83/06/14 20:39:05 sam 16 15
c need PR_CONNECT2 for socketpair
e
s 00001/00000/00147
d D 4.15 83/05/27 13:58:52 sam 15 14
c wnj'ify for rights passing
e
s 00012/00006/00135
d D 4.14 82/11/13 23:08:37 sam 14 13
c merge 4.1b and 4.1c
e
s 00000/00001/00141
d D 4.13 82/11/03 01:33:00 root 13 12
c delete protosw and protoswLAST
e
s 00031/00026/00111
d D 4.12 82/09/27 02:43:07 root 12 11
c first working version
e
s 00037/00000/00100
d D 4.11 82/04/24 20:40:50 sam 11 10
c icmp and ctlinput working
e
s 00007/00007/00093
d D 4.10 82/04/10 23:44:44 sam 10 9
c purge so_addr and add PRU_SOCKADDR as replacement
e
s 00004/00004/00096
d D 4.9 81/12/21 12:02:08 root 9 8
c FASTTIMO made 200 ms
e
s 00002/00000/00098
d D 4.8 81/12/12 17:50:41 root 8 7
c add PR_FASTHZ
e
s 00011/00015/00087
d D 4.7 81/11/29 22:14:17 wnj 7 6
c lint & wkend editing
e
s 00002/00001/00100
d D 4.6 81/11/26 11:54:03 wnj 6 5
c before carry to arpavax
e
s 00005/00005/00096
d D 4.5 81/11/18 15:46:59 wnj 5 4
c more cleanup
e
s 00001/00001/00100
d D 4.4 81/11/15 13:02:04 wnj 4 3
c listing
e
s 00055/00036/00046
d D 4.3 81/11/14 16:51:10 wnj 3 2
c just before overlay of ip
e
s 00010/00008/00072
d D 4.2 81/11/08 16:42:37 wnj 2 1
c first listing
e
s 00080/00000/00000
d D 4.1 81/11/07 16:35:52 wnj 1 0
c date and time created 81/11/07 16:35:52 by wnj
e
u
U
f b 
t
T
I 1
D 25
/*	%M%	%I%	%E%	*/
E 25
I 25
/*
D 28
 * Copyright (c) 1982 Regents of the University of California.
E 28
I 28
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 28
D 29
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 29
I 29
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 30
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 30
I 30
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 30
E 29
 *
 *	%W% (Berkeley) %G%
 */
E 25

/*
 * Protocol switch table.
 *
 * Each protocol has a handle initializing one of these structures,
 * which is used for protocol-protocol and system-protocol communication.
 *
I 3
 * A protocol is called through the pr_init entry before any other.
D 9
 * Thereafter it is called every 100ms through the pr_fasttimo entry and
E 9
I 9
 * Thereafter it is called every 200ms through the pr_fasttimo entry and
E 9
 * every 500ms through the pr_slowtimo for timer based actions.
 * The system will call the pr_drain entry if it is low on space and
 * this should throw away any non-critical data.
 *
E 3
 * Protocols pass data between themselves as chains of mbufs using
 * the pr_input and pr_output hooks.  Pr_input passes data up (towards
D 3
 * UNIX) and pr_output passes it down (towards the imps).
 * The protocol is responsible for the space occupied by any of its
 * arguments and must dispose of the space when it is finished with it.
E 3
I 3
 * UNIX) and pr_output passes it down (towards the imps); control
 * information passes up and down on pr_ctlinput and pr_ctloutput.
 * The protocol is responsible for the space occupied by any the
 * arguments to these entries and must dispose it.
E 3
 *
D 3
 * The advise entry is used by lower level protocols to inform
 * a higher level protocol of errors and routing advisories and the like.
 * Fasttimo is called every 100ms and is typically used to instantaeously
 * delay sending ACK's while slowtimo is called every 500ms and is used
 * for longer term cleanup.
E 3
I 3
 * The userreq routine interfaces protocols to the system and is
 * described below.
E 3
D 7
 *
D 3
 * The drain routine is called if the system is low on buffer space, and
 * should throw away non-cricital data.  The userreq routine interfaces
 * protocols to the system and is described below.  The sense routine
 * returns protocol status into the argument buffer.  This is used by
 * the system in providing session-level abstractions out of network
 * level protocols, and may also be returned by socket ioctl's.
E 3
I 3
 * The sense routine returns protocol status into the argument buffer.
 * This is used by the system in providing session-level abstractions
 * out of network level protocols, and may also be returned by socket ioctl's.
E 3
 * The amount of data returned by a sense is limited to the maxsense
 * value.  (The space for the sense is allocated by the caller, based on this.)
E 7
 */
struct protosw {
	short	pr_type;		/* socket type used for */
D 23
	short	pr_family;		/* protocol family */
E 23
I 23
	struct	domain *pr_domain;	/* domain protocol a member of */
E 23
	short	pr_protocol;		/* protocol number */
D 3
	int	pr_flags;		/* see below */
I 2
	int	(*pr_init)();		/* initialization hook */
E 3
I 3
	short	pr_flags;		/* see below */
/* protocol-protocol hooks */
E 3
E 2
	int	(*pr_input)();		/* input to protocol (from below) */
	int	(*pr_output)();		/* output to protocol (from above) */
D 3
	int	(*pr_advise)();		/* advise about error condition */
E 3
I 3
	int	(*pr_ctlinput)();	/* control input (from below) */
	int	(*pr_ctloutput)();	/* control output (from above) */
D 7
/* user-protocol hooks */
E 7
I 7
/* user-protocol hook */
E 7
	int	(*pr_usrreq)();		/* user request: see list below */
D 7
	int	(*pr_sense)();		/* sense state of protocol */
	int	pr_maxsense;		/* max size of sense value */
E 7
/* utility hooks */
	int	(*pr_init)();		/* initialization hook */
E 3
D 9
	int	(*pr_fasttimo)();	/* fast timeout (100ms) */
E 9
I 9
	int	(*pr_fasttimo)();	/* fast timeout (200ms) */
E 9
D 6
	int	(*pr_slowtimo)();	/* slow timeout (1 sec) */
E 6
I 6
	int	(*pr_slowtimo)();	/* slow timeout (500ms) */
E 6
	int	(*pr_drain)();		/* flush any excess space possible */
D 3
	int	(*pr_usrreq)();		/* user request: see list below */
	int	(*pr_sense)();		/* sense state of protocol */
	int	pr_maxsize;		/* max size of sense value */
E 3
};

I 6
#define	PR_SLOWHZ	2		/* 2 slow timeouts per second */
I 8
D 9
#define	PR_FASTHZ	10		/* 10 fast timeouts per second */
E 9
I 9
#define	PR_FASTHZ	5		/* 5 fast timeouts per second */
E 9

E 8
E 6
/*
 * Values for pr_flags
 */
#define	PR_ATOMIC	0x01		/* exchange atomic messages only */
#define	PR_ADDR		0x02		/* addresses given with messages */
/* in the current implementation, PR_ADDR needs PR_ATOMIC to work */
I 3
#define	PR_CONNREQUIRED	0x04		/* connection required by protocol */
#define	PR_WANTRCVD	0x08		/* want PRU_RCVD calls */
I 15
#define	PR_RIGHTS	0x10		/* passes capabilities */
E 15
E 3

/*
 * The arguments to usrreq are:
D 12
 *	(*protosw[].pr_usrreq)(up, req, m, addr);
E 12
I 12
 *	(*protosw[].pr_usrreq)(up, req, m, nam, opt);
E 12
 * where up is a (struct socket *), req is one of these requests,
D 12
 * m is a optional mbuf chain, and addr is an optional meta-internetwork
 * address representation.  The protocol is responsible for
 * disposal of the mbuf chain.  A non-zero return from usrreq gives an
E 12
I 12
 * m is a optional mbuf chain containing a message,
 * nam is an optional mbuf chain containing an address,
 * and opt is a pointer to a socketopt structure or nil.
 * The protocol is responsible for disposal of the mbuf chain m,
 * the caller is responsible for any space held by nam and opt.
 * A non-zero return from usrreq gives an
E 12
 * UNIX error number which should be passed to higher level software.
 */
D 3
#define	PRU_ATTACH	0	/* attach protocol to up */
#define	PRU_DETACH	1	/* detach protocol to up */
#define	PRU_CONNECT	2	/* establish connection to peer */
#define	PRU_DISCONNECT	3	/* disconnect from peer */
D 2
/* for ISCONN and ISDISCONN a 0 return means yes */
E 2
#define	PRU_ISCONN	4	/* is connection to peer complete? */
#define	PRU_ISDISCONN	5	/* is disconnection from peer complete? */
D 2
#define	PRU_RCVD	6	/* have taken data; more room now */
#define	PRU_SEND	7	/* send this data */
#define	PRU_ABORT	8	/* abort (fast DISCONNECT, DETATCH) */
#define	PRU_CLEAR	9	/* network went down: clean up */
#define	PRU_CONTROL	10	/* control operations on protocol */
#define	PRU_FASTTIMO	11	/* for protocol's use only: fast timeout */
#define	PRU_SLOWTIMO	12	/* for protocol's use only: slow timeout */
E 2
I 2
#define	PRU_SHUTDOWN	6	/* won't send any more data */
#define	PRU_RCVD	7	/* have taken data; more room now */
#define	PRU_SEND	8	/* send this data */
#define	PRU_ABORT	9	/* abort (fast DISCONNECT, DETATCH) */
#define	PRU_CLEAR	10	/* network went down: clean up */
#define	PRU_CONTROL	11	/* control operations on protocol */
#define	PRU_FASTTIMO	12	/* for protocol's use only: fast timeout */
#define	PRU_SLOWTIMO	13	/* for protocol's use only: slow timeout */
E 3
I 3
#define	PRU_ATTACH		0	/* attach protocol to up */
#define	PRU_DETACH		1	/* detach protocol from up */
D 12
#define	PRU_CONNECT		2	/* establish connection to peer */
D 5
#define	PRU_DISCONNECT		3	/* disconnect from peer */
#define	PRU_FLUSH		4	/* flush data in queues */
E 5
I 5
#define	PRU_ACCEPT		3	/* accept connection from peer */
#define	PRU_DISCONNECT		4	/* disconnect from peer */
E 5
#define	PRU_SHUTDOWN		5	/* won't send any more data */
#define	PRU_RCVD		6	/* have taken data; more room now */
#define	PRU_SEND		7	/* send this data */
#define	PRU_ABORT		8	/* abort (fast DISCONNECT, DETATCH) */
#define	PRU_CONTROL		9	/* control operations on protocol */
I 7
#define	PRU_SENSE		10	/* return status into m */
#define	PRU_RCVOOB		11	/* retrieve out of band data */
#define	PRU_SENDOOB		12	/* send out of band data */
I 10
#define	PRU_SOCKADDR		13	/* fetch socket's address */
E 12
I 12
#define	PRU_BIND		2	/* bind socket to address */
#define	PRU_LISTEN		3	/* listen for connection */
#define	PRU_CONNECT		4	/* establish connection to peer */
#define	PRU_ACCEPT		5	/* accept connection from peer */
#define	PRU_DISCONNECT		6	/* disconnect from peer */
#define	PRU_SHUTDOWN		7	/* won't send any more data */
#define	PRU_RCVD		8	/* have taken data; more room now */
#define	PRU_SEND		9	/* send this data */
#define	PRU_ABORT		10	/* abort (fast DISCONNECT, DETATCH) */
#define	PRU_CONTROL		11	/* control operations on protocol */
#define	PRU_SENSE		12	/* return status into m */
#define	PRU_RCVOOB		13	/* retrieve out of band data */
#define	PRU_SENDOOB		14	/* send out of band data */
#define	PRU_SOCKADDR		15	/* fetch socket's address */
I 16
D 18
#define	PRU_CONNECT2		16	/* connect two sockets */
E 18
I 18
#define	PRU_PEERADDR		16	/* fetch peer's address */
#define	PRU_CONNECT2		17	/* connect two sockets */
E 18
E 16
E 12
E 10
E 7
/* begin for protocols internal use */
D 7
#define	PRU_FASTTIMO		10	/* 100ms timeout */
#define	PRU_SLOWTIMO		11	/* 500ms timeout */
#define	PRU_PROTORCV		12	/* receive from below */
#define	PRU_PROTOSEND		13	/* send to below */
E 7
I 7
D 9
#define	PRU_FASTTIMO		13	/* 100ms timeout */
E 9
I 9
D 10
#define	PRU_FASTTIMO		13	/* 200ms timeout */
E 9
#define	PRU_SLOWTIMO		14	/* 500ms timeout */
#define	PRU_PROTORCV		15	/* receive from below */
#define	PRU_PROTOSEND		16	/* send to below */
E 7
E 3
E 2
/* need some stuff for splice */
E 10
I 10
D 12
#define	PRU_FASTTIMO		14	/* 200ms timeout */
#define	PRU_SLOWTIMO		15	/* 500ms timeout */
#define	PRU_PROTORCV		16	/* receive from below */
#define	PRU_PROTOSEND		17	/* send to below */
E 12
I 12
D 16
#define	PRU_FASTTIMO		16	/* 200ms timeout */
#define	PRU_SLOWTIMO		17	/* 500ms timeout */
#define	PRU_PROTORCV		18	/* receive from below */
#define	PRU_PROTOSEND		19	/* send to below */
E 16
I 16
D 18
#define	PRU_FASTTIMO		17	/* 200ms timeout */
#define	PRU_SLOWTIMO		18	/* 500ms timeout */
#define	PRU_PROTORCV		19	/* receive from below */
#define	PRU_PROTOSEND		20	/* send to below */
E 18
I 18
#define	PRU_FASTTIMO		18	/* 200ms timeout */
#define	PRU_SLOWTIMO		19	/* 500ms timeout */
#define	PRU_PROTORCV		20	/* receive from below */
#define	PRU_PROTOSEND		21	/* send to below */
E 18
E 16
E 12
E 10

I 3
D 7
#define	PRU_NREQ		14
E 7
I 7
D 10
#define	PRU_NREQ		17
E 10
I 10
D 12
#define	PRU_NREQ		18
E 12
I 12
D 18
#define	PRU_NREQ		20
E 18
I 18
#define	PRU_NREQ		21
E 18
E 12
E 10
E 7

#ifdef PRUREQUESTS
char *prurequests[] = {
D 5
	"ATTACH",	"DETACH",	"CONNECT",	"DISCONNECT",
	"FLUSH",	"SHUTDOWN",	"RCVD",		"SEND",	
E 5
I 5
D 12
	"ATTACH",	"DETACH",	"CONNECT",	"ACCEPT",
	"DISCONNECT",	"SHUTDOWN",	"RCVD",		"SEND",	
E 5
D 7
	"ABORT",	"CONTROL",	"FASTTIMO",	"SLOWTIMO",
E 7
I 7
	"ABORT",	"CONTROL",	"SENSE",	"RCVOOB",
D 10
	"SENDOOB",	"FASTTIMO",	"SLOWTIMO",
E 10
I 10
	"SENDOOB",	"SOCKADDR",	"FASTTIMO",	"SLOWTIMO",
E 10
E 7
D 5
	"PROTORCV",	"PROTOSND",
E 5
I 5
	"PROTORCV",	"PROTOSEND",
E 12
I 12
	"ATTACH",	"DETACH",	"BIND",		"LISTEN",
	"CONNECT",	"ACCEPT",	"DISCONNECT",	"SHUTDOWN",
	"RCVD",		"SEND",		"ABORT",	"CONTROL",
	"SENSE",	"RCVOOB",	"SENDOOB",	"SOCKADDR",
D 17
	"FASTTIMO",	"SLOWTIMO",	"PROTORCV",	"PROTOSEND",
E 17
I 17
D 18
	"CONNECT2",	"FASTTIMO",	"SLOWTIMO",	"PROTORCV",
	"PROTOSEND",
E 18
I 18
	"PEERADDR",	"CONNECT2",	"FASTTIMO",	"SLOWTIMO",
	"PROTORCV",	"PROTOSEND",
E 18
E 17
E 12
E 5
};
#endif

I 11
/*
 * The arguments to the ctlinput routine are
 *	(*protosw[].pr_ctlinput)(cmd, arg);
 * where cmd is one of the commands below, and arg is
 * an optional argument (caddr_t).
 *
 * N.B. The IMP code, in particular, pressumes the values
 *      of some of the commands; change with extreme care.
I 14
 * TODO:
 *	spread out codes so new ICMP codes can be
 *	accomodated more easily
E 14
 */
#define	PRC_IFDOWN		0	/* interface transition */
#define	PRC_ROUTEDEAD		1	/* select new route if possible */
#define	PRC_QUENCH		4	/* some said to slow down */
I 14
#define	PRC_MSGSIZE		5	/* message size forced drop */
E 14
#define	PRC_HOSTDEAD		6	/* normally from IMP */
#define	PRC_HOSTUNREACH		7	/* ditto */
#define	PRC_UNREACH_NET		8	/* no route to network */
#define	PRC_UNREACH_HOST	9	/* no route to host */
#define	PRC_UNREACH_PROTOCOL	10	/* dst says bad protocol */
#define	PRC_UNREACH_PORT	11	/* bad port # */
D 14
#define	PRC_MSGSIZE		12	/* message size forced drop */
E 14
I 14
D 21
#define	PRC_UNREACH_SRCFAIL	12	/* source route failed */
E 14
#define	PRC_REDIRECT_NET	13	/* net routing redirect */
#define	PRC_REDIRECT_HOST	14	/* host routing redirect */
I 14
#define	PRC_REDIRECT_TOSNET	15	/* redirect for type of service & net */
#define	PRC_REDIRECT_TOSHOST	16	/* redirect for tos & host */
E 14
#define	PRC_TIMXCEED_INTRANS	17	/* packet lifetime expired in transit */
#define	PRC_TIMXCEED_REASS	18	/* lifetime expired on reass q */
#define	PRC_PARAMPROB		19	/* header incorrect */
E 21
I 21
#define	PRC_UNREACH_NEEDFRAG	12	/* IP_DF caused drop */
#define	PRC_UNREACH_SRCFAIL	13	/* source route failed */
#define	PRC_REDIRECT_NET	14	/* net routing redirect */
#define	PRC_REDIRECT_HOST	15	/* host routing redirect */
#define	PRC_REDIRECT_TOSNET	16	/* redirect for type of service & net */
#define	PRC_REDIRECT_TOSHOST	17	/* redirect for tos & host */
#define	PRC_TIMXCEED_INTRANS	18	/* packet lifetime expired in transit */
#define	PRC_TIMXCEED_REASS	19	/* lifetime expired on reass q */
#define	PRC_PARAMPROB		20	/* header incorrect */
I 26
D 27
#define PRC_GWDOWN		21	/* gateway down */
E 27
E 26
E 21

D 21
#define	PRC_NCMDS		20
E 21
I 21
D 26
#define	PRC_NCMDS		21
E 26
I 26
D 27
#define	PRC_NCMDS		22
E 27
I 27
#define	PRC_NCMDS		21
E 27
E 26
E 21

#ifdef PRCREQUESTS
char	*prcrequests[] = {
D 14
	"IFDOWN",	"ROUTEDEAD",	"#2",		"#3",
	"QUNECH",	"#5",		"HOSTDEAD",	"HOSTUNREACH",
	"NET-UNREACH",	"HOST-UNREACH",	"PROTO-UNREACH","PORT-UNREACH",
	"MSGSIZE",	"NET-REDIRECT",	"HOST-REDIRECT","TX-INTRANS",
	"TX-REASS",	"PARAMPROB"
E 14
I 14
D 21
	"IFDOWN",	   "ROUTEDEAD",	   "#2",	    "#3",
	"QUENCH",	   "MSGSIZE",	   "HOSTDEAD",	    "HOSTUNREACH",
	"NET-UNREACH",	   "HOST-UNREACH", "PROTO-UNREACH", "PORT-UNREACH",
	"SRCFAIL-UNREACH", "NET-REDIRECT", "HOST-REDIRECT", "TOSNET-REDIRECT",
	"TOSHOST-REDIRECT","TX-INTRANS",   "TX-REASS",	    "PARAMPROB"
E 21
I 21
	"IFDOWN", "ROUTEDEAD", "#2", "#3",
	"QUENCH", "MSGSIZE", "HOSTDEAD", "HOSTUNREACH",
	"NET-UNREACH", "HOST-UNREACH", "PROTO-UNREACH", "PORT-UNREACH",
	"FRAG-UNREACH", "SRCFAIL-UNREACH", "NET-REDIRECT", "HOST-REDIRECT",
	"TOSNET-REDIRECT", "TOSHOST-REDIRECT", "TX-INTRANS", "TX-REASS",
	"PARAMPROB"
E 21
E 14
};
#endif

I 24
/*
 * The arguments to ctloutput are:
 *	(*protosw[].pr_ctloutput)(req, so, level, optname, optval);
 * req is one of the actions listed below, so is a (struct socket *),
 * level is an indication of which protocol layer the option is intended.
 * optname is a protocol dependent socket option request,
 * optval is a pointer to a mbuf-chain pointer, for value-return results.
 * The protocol is responsible for disposal of the mbuf chain *optval
 * if supplied,
 * the caller is responsible for any space held by *optval, when returned.
 * A non-zero return from usrreq gives an
 * UNIX error number which should be passed to higher level software.
 */
#define	PRCO_GETOPT	0
#define	PRCO_SETOPT	1

#define	PRCO_NCMDS	2

#ifdef PRCOREQUESTS
char	*prcorequests[] = {
	"GETOPT", "SETOPT",
};
#endif

E 24
E 11
E 3
#ifdef KERNEL
D 3
struct protosw protosw[];
I 2
extern	struct protosw *pf_findproto(), *pf_findtype();
E 3
I 3
D 4
struct	protosw protosw[];
E 4
I 4
D 13
struct	protosw protosw[], *protoswLAST;
E 13
E 4
extern	struct protosw *pffindproto(), *pffindtype();
E 3
E 2
#endif
E 1
