h36248
s 00010/00005/00059
d D 7.3 88/06/29 17:07:18 bostic 17 16
c install approved copyright notice
e
s 00008/00002/00056
d D 7.2 87/12/07 17:46:09 bostic 16 15
c use Berkeley specific header
e
s 00001/00001/00057
d D 7.1 86/06/05 00:29:56 mckusick 15 14
c 4.3BSD release version
e
s 00007/00001/00051
d D 6.2 85/06/08 12:42:08 mckusick 14 13
c Add copyright
e
s 00000/00000/00052
d D 6.1 83/07/29 07:12:12 sam 13 12
c 4.2 distribution
e
s 00000/00001/00052
d D 4.12 81/12/21 10:28:39 root 12 11
c delete OURFINNOTACKED
e
s 00003/00003/00050
d D 4.11 81/12/12 12:58:33 root 11 10
c with crud (first working version)
e
s 00002/00001/00051
d D 4.10 81/12/03 17:30:08 wnj 10 9
c cleanup
e
s 00026/00011/00026
d D 4.9 81/11/26 11:57:00 wnj 9 8
c before carry to ARPAVAX
e
s 00003/00001/00034
d D 4.8 81/11/25 16:09:41 wnj 8 7
c listing
e
s 00019/00029/00016
d D 4.7 81/11/24 17:33:20 wnj 7 6
c start rewrite
e
s 00005/00012/00040
d D 4.6 81/11/18 15:37:49 wnj 6 5
c more cleanup
e
s 00001/00022/00051
d D 4.5 81/11/15 13:00:07 wnj 5 4
c listing
e
s 00001/00001/00072
d D 4.4 81/11/08 16:38:49 wnj 4 3
c restore sccs keywords
e
s 00001/00001/00072
d D 4.3 81/11/08 16:36:50 wnj 3 2
c first listing
e
s 00041/00088/00032
d D 4.2 81/11/03 21:54:24 wnj 2 1
c states now w/o fsm matrix; timers accessible by iteration
e
s 00120/00000/00000
d D 4.1 81/11/03 11:26:10 wnj 1 0
c date and time created 81/11/03 11:26:10 by wnj
e
u
U
t
T
I 1
D 2
/* fsm.h 1.4 81/10/29 */
E 2
I 2
D 3
/* %M% %I% %E% */
E 3
I 3
D 4
/* tcp_fsm.h 4.2 81/11/03 */
E 4
I 4
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
D 15
 * Copyright (c) 1982 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 15
D 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 16
 *
 *	%W% (Berkeley) %G%
 */
E 14
E 4
E 3
E 2

/*
D 6
 * TCP FSM definitions.
E 6
I 6
 * TCP FSM state definitions.
E 6
I 2
D 7
 *
D 6
 * The TCP is conceptually a finite state machine with 13 states
 * and 9 inputs.  The states and inputs are defined here, as well
 * as an array which is used in network profiling to keep event
 * counters on the state transitions.  The actual state transitions
 * occur on input to the tcp machine (tcp_input.c) and when user
 * requests are made (tcp_states.c).
 *
E 6
 * This TCP machine has two more states than suggested in RFC 793,
D 6
 * the extra states being L_SYN_RCVD and RCV_WAIT.
E 6
I 6
 * the extra states being L_SYN_RCVD and RCV_WAIT
E 6
 *
D 6
 * EXPLAIN THE EXTRA STATES!!!
E 6
I 6
 * EXPLAIN THE EXTRA STATES.
E 7
I 7
 * Per RFC793, September, 1981.
E 7
E 6
E 2
 */

D 7
/*
 * States
 */
#define	TCP_NSTATES	14
E 7
I 7
#define	TCP_NSTATES	11
E 7

D 2
#define	EFAILEC		-1		/* pseudo-state for internal use */
#define	SAME		0
#define	LISTEN		1
#define	SYN_SENT	2
E 2
I 2
D 7
#define	EFAILEC		-1		/* new state for failure, internally */
#define	SAME		0		/* no state change, internally */
#define	LISTEN		1		/* listening for connection */
#define	SYN_SENT	2		/* active, have sent syn */
E 2
#define	SYN_RCVD	3
#define	L_SYN_RCVD	4
D 2
#define	ESTAB		5
#define	FIN_W1		6
#define	FIN_W2		7
#define	TIME_WAIT	8
#define	CLOSE_WAIT	9
#define	CLOSING1	10
#define	CLOSING2	11
#define	RCV_WAIT	12
#define	CLOSED		13
E 2
I 2
#define	ESTAB		5		/* established */
#define	FIN_W1		6		/* have closed and sent fin */
#define	FIN_W2		7		/* have closed and rcvd ack of fin */
#define	TIME_WAIT	8		/* in 2*msl quiet wait after close */
D 6
#define	CLOSE_WAIT	9		/* rcvd fin, waiting for UCLOSE */
E 6
I 6
#define	CLOSE_WAIT	9		/* rcvd fin, waiting for close */
E 6
#define	CLOSING		10		/* closed xchd FIN; await FIN ACK */
D 6
#define	LAST_ACK	11		/* had fin and UCLOSE; await FIN ACK */
E 6
I 6
#define	LAST_ACK	11		/* had fin and close; await FIN ACK */
E 6
#define	RCV_WAIT	12		/* waiting for user to drain data */
#define	CLOSED		13		/* closed */
E 7
I 7
#define	TCPS_CLOSED		0	/* closed */
#define	TCPS_LISTEN		1	/* listening for connection */
#define	TCPS_SYN_SENT		2	/* active, have sent syn */
D 9
#define	TCPS_SYN_RCVD		3	/* have send and received syn */
E 9
I 9
#define	TCPS_SYN_RECEIVED	3	/* have send and received syn */
E 9
I 8
/* states < TCPS_ESTABLISHED are those where connections not established */
E 8
#define	TCPS_ESTABLISHED	4	/* established */
I 8
D 9
#define	TCPS_CLOSE_WAIT		8	/* rcvd fin, waiting for close */
E 9
I 9
#define	TCPS_CLOSE_WAIT		5	/* rcvd fin, waiting for close */
E 9
/* states > TCPS_CLOSE_WAIT are those where user has closed */
E 8
D 9
#define	TCPS_FIN_WAIT_1		5	/* have closed, sent fin */
#define	TCPS_FIN_WAIT_2		6	/* have closed, fin is acked */
#define	TCPS_TIME_WAIT		7	/* in 2*msl quiet wait after close */
D 8
#define	TCPS_CLOSE_WAIT		8	/* rcvd fin, waiting for close */
E 8
#define	TCPS_CLOSING		9	/* closed xchd FIN; await FIN ACK */
#define	TCPS_LAST_ACK		10	/* had fin and close; await FIN ACK */
E 9
I 9
#define	TCPS_FIN_WAIT_1		6	/* have closed, sent fin */
#define	TCPS_CLOSING		7	/* closed xchd FIN; await FIN ACK */
#define	TCPS_LAST_ACK		8	/* had fin and close; await FIN ACK */
/* states > TCPS_CLOSE_WAIT && < TCPS_FIN_WAIT_2 await ACK of FIN */
#define	TCPS_FIN_WAIT_2		9	/* have closed, fin is acked */
#define	TCPS_TIME_WAIT		10	/* in 2*msl quiet wait after close */
E 9
E 7
E 2

I 7
D 9
#define	TCPS_HAVERCVDSYN(s)	((s) >= TCPS_SYN_RCVD)
E 9
I 9
#define	TCPS_HAVERCVDSYN(s)	((s) >= TCPS_SYN_RECEIVED)
E 9
#define	TCPS_HAVERCVDFIN(s)	((s) >= TCPS_TIME_WAIT)
I 9
D 12
#define	TCPS_OURFINNOTACKED(s)	((s) > TCPS_CLOSE_WAIT && (s) < TCPS_FIN_WAIT_2)
E 12
E 9

I 9
#ifdef	TCPOUTFLAGS
/*
 * Flags used when sending segments in tcp_output.
 * Basic flags (TH_RST,TH_ACK,TH_SYN,TH_FIN) are totally
D 10
 * determined by state.
E 10
I 10
 * determined by state, with the proviso that TH_FIN is sent only
 * if all data queued for output is included in the segment.
E 10
 */
u_char	tcp_outflags[TCP_NSTATES] = {
    TH_RST|TH_ACK, 0, TH_SYN, TH_SYN|TH_ACK,
    TH_ACK, TH_ACK,
D 11
    TH_FIN|TH_ACK, TH_FIN|TH_ACK, TH_FIN|TH_ACK, TH_FIN|TH_ACK, TH_FIN|TH_ACK,
E 11
I 11
    TH_FIN|TH_ACK, TH_FIN|TH_ACK, TH_FIN|TH_ACK, TH_ACK, TH_ACK,
E 11
};
#endif

E 9
E 7
D 5
/*
 * Inputs to fsm.
 */
#define	TCP_NINPUTS	10

D 2
#define	IUOPENA 	1
#define	INRECV		2
#define	IUOPENR		3
#define	IUCLOSE		4
#define	ISTIMER		5
#define	IURECV		6
#define	IUSEND		7
#define	IUABORT		8
#define	INCLEAR		9
#define	INSEND		10
E 2
I 2
#define	IUOPENA 	0		/* active open by user */
#define	INRECV		1		/* segment received from net */
#define	IUOPENR		2		/* passive open by user */
#define	IUCLOSE		3		/* close by user */
#define	ISTIMER		4		/* tcp timer expired */
#define	IURECV		5		/* user read data; adjust window */
#define	IUSEND		6		/* user sending data */
#define	IUABORT		7		/* user aborts connection */
#define	INCLEAR		8		/* network clear */
#define	INSEND		9		/* send by tcp to remote peer */
E 2

E 5
D 2
/*
 * Actions
 */
#define	BAD		0
#define	LIS_CLS		1
#define	LIS_NETR	2
#define	SYR_NETR	3
#define	SYS_CLS		4
#define	SYS_NETR	5
#define	CLS_OPN		6
#define	EST_NETR	7
#define	CL2_CLW		8
#define	TIMERS		9
#define	CL1_NETR	10
#define	CL2_NETR	11
#define	CLS_RWT		12
#define	RWT_NETR	13
#define	FW1_SYR		14
#define	FW1_NETR	15
#define	FW2_NETR	16
#define	CWT_NETR	17
#define	SSS_SYN		18
#define	SSS_SND		19
#define	SSS_RCV		20
#define	CLS_NSY		21
#define	CLS_SYN		22
#define	CLS_ACT		23
#define	NOP		24
#define	CLS_ERR		25

#ifdef	KERNEL
int	acounts[14][10];
#endif

#ifdef TCPFSTAB
/* SHOULD FIGURE OUT HOW TO MAKE THIS READABLE! */
char	tcp_fstab[TCP_NSTATES][TCP_NINPUTS] = {
	{ 0, 1, 0, 4, 0, 24, 0, 0, 0, 24 },		/* CLOSED */
	{ 0, 0, 2, 0, 6, 0, 0, 0, 21, 23 },		/* LISTEN */
	{ 0, 0, 5, 0, 6, 9, 0,	0, 21, 23, },		/* SYN_SENT */
	{ 0, 0, 3, 0, 14, 9, 0,	0, 21, 23, },		/* SYN_RCVD */
	{ 0, 0, 3, 0, 14, 9, 0, 0, 21, 23, },		/* L_SYN_RCVD */
	{ 0, 0, 7, 0, 14, 9, 20, 19, 22, 23, },		/* ESTAB */
	{ 0, 0, 15, 0, 24, 9, 20, 25, 22, 23, },	/* FIN_WAIT_1 */
	{ 0, 0, 16, 0, 24, 9, 20, 24, 22, 23, },	/* FIN_WAIT_2 */
	{ 0, 0, 18, 0, 24, 9, 20, 25, 22, 23, },	/* TIME_WAIT */
	{ 0, 0, 17, 0, 8, 9, 20, 19, 22, 23, },		/* CLOSE_WAIT */
	{ 0, 0, 10, 0, 25, 9, 20, 25, 22, 23, },	/* CLOSING_1 */
	{ 0, 0, 11, 0, 25, 9, 20, 25, 22, 23, },	/* CLOSING_2 */
	{ 0, 0, 13, 0, 25, 9, 12, 25, 22, 23, },	/* RCV_WAIT */
	{ 0, 1, 0, 4, 0, 24, 0, 0, 0, 24 }		/* CLOSED */
};
#endif
#ifdef KERNEL
E 2
I 2
#ifdef KPROF
E 2
D 5
int	acounts[TCP_NSTATES][TCP_NINPUTS];
E 5
I 5
int	tcp_acounts[TCP_NSTATES][PRU_NREQ];
E 5
#endif

D 9
#ifdef TCPSTATES
E 9
I 9
#ifdef	TCPSTATES
E 9
char *tcpstates[] = {
D 2
	"CLOSED",	"LISTEN",	"SYN_SENT",	"SYN_RCVD",
E 2
I 2
D 7
	"SAME",		"LISTEN",	"SYN_SENT",	"SYN_RCVD",
E 2
	"L_SYN_RCVD",	"ESTAB",	"FIN_W1",	"FIN_W2",
D 2
	"TIME_WAIT",	"CLOSE_WAIT",	"CLOSING1",	"CLOSING2",
E 2
I 2
	"TIME_WAIT",	"CLOSE_WAIT",	"CLOSING",	"LAST_ACK",
E 2
	"RCV_WAIT",	"CLOSED"
E 7
I 7
	"CLOSED",	"LISTEN",	"SYN_SENT",	"SYN_RCVD",
D 9
	"ESTABLISHED",	"FIN_WAIT1",	"FIN_WAIT2",	"TIME_WAIT",
	"CLOSE_WAIT",	"CLOSING",	"LAST_ACK",
E 9
I 9
D 11
	"ESTABLISHED",	"CLOSE_WAIT",	"FIN_WAIT_1",	"FIN_WAIT_2",
	"TIME_WAIT",	"CLOSING",	"LAST_ACK",
E 11
I 11
	"ESTABLISHED",	"CLOSE_WAIT",	"FIN_WAIT_1",	"CLOSING",
	"LAST_ACK",	"FIN_WAIT_2",	"TIME_WAIT",
E 11
E 9
E 7
D 5
};
char *tcpinputs[] = {
	"BAD",		"UOPENA",	"NRECV",	"UOPENR",
	"UCLOSE",	"STIMER",	"URECV",	"USEND",
D 2
	"UABORT",	"NCLEAR"
E 2
I 2
	"UABORT",	"NCLEAR",	"NSEND",
E 5
E 2
};
D 2
char *tcptimers[] = { "", "INIT", "REXMT", "REXMTTL", "PERSIST", "FINACK" };
E 2
I 2
D 7
char *tcptimers[] = { "INIT", "REXMT", "REXMTTL", "PERSIST", "FINACK" };
E 7
E 2
#endif
D 2

#define	TINIT		1
#define	TREXMT		2
#define	TREXMTTL	3
#define	TPERSIST	4
#define	TFINACK		5
E 2
E 1
