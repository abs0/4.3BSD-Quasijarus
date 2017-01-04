h61980
s 00007/00001/00029
d D 6.3 85/06/08 14:58:46 mckusick 21 20
c Add copyright
e
s 00006/00006/00024
d D 6.2 84/08/29 20:27:53 bloom 20 19
c Change to includes.  no more ../h
e
s 00000/00000/00030
d D 6.1 83/07/29 06:46:49 sam 19 18
c 4.2 distribution
e
s 00005/00109/00025
d D 4.18 82/10/31 14:11:02 root 18 17
c version with uipc_usrreq.c
e
s 00000/00000/00134
d D 4.17 82/10/10 16:03:13 root 17 16
c move vax header files to their own directory
e
s 00000/00001/00134
d D 4.16 82/10/09 05:39:07 wnj 16 15
c fix up header file dependencies 
e
s 00002/00002/00133
d D 4.15 82/10/05 21:58:03 root 15 14
c send(... SOF_OOB) and receive(... SOF_PREVIEW)
e
s 00000/00000/00135
d D 4.14 82/10/03 23:38:44 root 14 13
c overhaul
e
s 00000/00002/00135
d D 4.13 82/06/20 12:21:50 sam 13 12
c purge COUNT crap now that we have gprof
e
s 00001/00018/00136
d D 4.12 82/06/14 22:17:12 wnj 12 11
c get rid of m_release stuff
e
s 00002/00000/00152
d D 4.11 82/03/13 12:54:49 sam 11 10
c lint
e
s 00002/00002/00150
d D 4.10 81/12/02 17:26:30 wnj 10 9
c more cleanup
e
s 00001/00017/00151
d D 4.9 81/11/26 11:58:35 wnj 9 8
c before carry to arpavax
e
s 00003/00000/00165
d D 4.8 81/11/22 15:02:47 root 8 7
c correct disconnect from peer (zero his so_pcb)
e
s 00001/00001/00164
d D 4.7 81/11/22 10:50:24 wnj 7 6
c reserve 2* (hiwat, not lowat)
e
s 00001/00001/00164
d D 4.6 81/11/21 22:13:28 root 6 5
c fix mbuf accounting
e
s 00033/00003/00132
d D 4.5 81/11/21 21:29:49 wnj 5 4
c WANTRCVD, wakeups on shutdown (commented out) prints
e
s 00034/00016/00101
d D 4.4 81/11/21 15:18:04 wnj 4 3
c first resource exchange version
e
s 00012/00031/00105
d D 4.3 81/11/18 15:45:12 wnj 3 2
c more cleanup
e
s 00004/00004/00132
d D 4.2 81/11/16 14:20:55 wnj 2 1
c lint
e
s 00136/00000/00000
d D 4.1 81/11/15 13:50:36 wnj 1 0
c date and time created 81/11/15 13:50:36 by wnj
e
u
U
t
T
I 1
D 21
/*	%M%	%I%	%E%	*/
E 21
I 21
/*
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 21

D 20
#include "../h/param.h"
D 18
#include "../h/dir.h"
#include "../h/user.h"
E 18
#include "../h/mbuf.h"
D 3
#include "../h/protocol.h"
E 3
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
I 18
#include "../h/unpcb.h"
E 20
I 20
#include "param.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "unpcb.h"
E 20
E 18
D 3
#include "../h/inaddr.h"
E 3
I 3
D 9
#include "../net/inet_systm.h"		/* XXX */
E 9
I 9
D 16
#include "../net/in_systm.h"		/* XXX */
E 16
E 9
E 3

D 3
int	pi_usrreq();
E 3
I 3
D 18
int	piusrreq();
E 18
E 3
#define	PIPSIZ	4096

/*
D 18
 * Code for pipes and other loopback protocols (single machine, that is.)
E 18
I 18
 * Sneakily connect a pipe from wso to rso.
 * This will get cleaned up when socketpair is added.
E 18
 */
D 18
struct	protosw pipeproto = {
D 5
	SOCK_STREAM,	PF_LOCAL,	0,		PR_CONNREQUIRED,
E 5
I 5
D 10
	SOCK_STREAM,	PF_LOCAL,	0,		PR_CONNREQUIRED|PR_WANTRCVD,
E 10
I 10
	SOCK_STREAM,	PF_UNIX,	0,		PR_CONNREQUIRED|PR_WANTRCVD,
E 10
E 5
	0,		0,		0,		0,
D 3
	pi_usrreq,	0,		0,
E 3
I 3
D 10
	piusrreq,	0,		0,
E 10
I 10
	piusrreq,
E 10
E 3
	0,		0,		0,		0
};

/*
 * Connect a pipe from wso to rso.  The protocol control block
 * for a pipe is used to store a pointer to the matching socket.
D 5
 * Each half of the pipe gets half of the buffer space (half send
 * buffers, half receive buffers).
E 5
 */
E 18
D 3
pi_connect(wso, rso)
E 3
I 3
piconnect(wso, rso)
E 3
	struct socket *wso, *rso;
{

I 3
D 13
COUNT(PICONNECT);
E 13
E 3
D 6
	if (m_reserve(PIPSIZ) == 0) {
E 6
I 6
D 7
	if (m_reserve(PIPSIZ/MSIZE) == 0) {
E 7
I 7
D 12
	if (m_reserve(PIPSIZ*2/MSIZE) == 0) {
E 7
E 6
		u.u_error = ENOBUFS;
		return (0);
	}
E 12
I 12
	/* when we reserve memory this routine may fail */
E 12
D 18
	wso->so_proto = rso->so_proto = &pipeproto;
	wso->so_pcb = (caddr_t)rso;
	rso->so_pcb = (caddr_t)wso;
E 18
I 18
	sotounpcb(wso)->unp_conn = sotounpcb(rso);
	sotounpcb(rso)->unp_conn = sotounpcb(wso);
E 18
D 4
	wso->so_snd.sb_hiwat = PIPSIZ/2;
	wso->so_snd.sb_mbcnt = PIPSIZ;
E 4
I 4
	wso->so_snd.sb_hiwat = PIPSIZ;
	wso->so_snd.sb_mbmax = 2*PIPSIZ;
E 4
	wso->so_state |= SS_ISCONNECTED|SS_CANTRCVMORE;
D 4
	rso->so_rcv.sb_hiwat = PIPSIZ/2;
	rso->so_rcv.sb_mbcnt = PIPSIZ;
E 4
I 4
	rso->so_rcv.sb_hiwat = 0;
	rso->so_rcv.sb_mbmax = 0;
E 4
	rso->so_state |= SS_ISCONNECTED|SS_CANTSENDMORE;
	return (1);
D 18
}

D 3
pi_splice(pso, so)
	struct socket *pso, *so;
{

	if (pso->so_proto != &pipeproto) {
		struct socket *tso;
		tso = pso; pso = so; so = tso;
	}
	if (pso->so_proto != &pipeproto)
		return (EOPNOTSUPP);
	/* check types and buffer space */
	/* merge buffers */
	return (0);
}

E 3
/*
 * User requests on pipes and other internally implemented
 * structures.
 */
I 2
/*ARGSUSED*/
E 2
D 3
pi_usrreq(so, req, m, addr)
E 3
I 3
piusrreq(so, req, m, addr)
E 3
	struct socket *so;
	int req;
	struct mbuf *m;
	caddr_t addr;
{
	struct socket *so2 = (struct socket *)so->so_pcb;

I 3
D 13
COUNT(PIUSRREQ);
E 13
E 3
	switch (req) {

	case PRU_ATTACH:
I 5
		break;

E 5
	case PRU_DETACH:
I 5
		so->so_pcb = 0;
E 5
		break;

	case PRU_CONNECT:
I 3
	case PRU_ACCEPT:
E 3
		return (EOPNOTSUPP);

	case PRU_DISCONNECT:
		if (so2 == 0)
			return (ENOTCONN);
		so->so_pcb = 0;
I 8
		so2->so_pcb = 0;
E 8
D 2
		sodetwakeup(so2);
		so->so_state &= ~SS_ISCONNECTED;
E 2
I 2
		soisdisconnected(so);
I 5
		soisdisconnected(so2);
E 5
E 2
		break;

D 3
	case PRU_FLUSH:
D 2
		soflush(so);
		break;
E 2
I 2
		return (EOPNOTSUPP);
E 2

E 3
	case PRU_SHUTDOWN:
D 3
		so->so_state |= SS_CANTSENDMORE;
I 2
		sowwakeup(so);
E 2
		if (so2) {
			so2->so_state |= SS_CANTRCVMORE;
			sorwakeup(so2);
		}
E 3
I 3
		socantsendmore(so);
		if (so2)
			socantrcvmore(so2);
E 3
		break;

	case PRU_RCVD:
D 4
		if (so->so_rcv.sb_cc == 0 && so2 && so2->so_snd.sb_cc) {
			so->so_rcv.sb_cc = so2->so_snd.sb_cc;
			so->so_rcv.sb_mbcnt = so2->so_snd.sb_mbcnt;
			so->so_rcv.sb_mb = so2->so_rcv.sb_mb;
			so2->so_snd.sb_cc = 0;
			so2->so_snd.sb_mbcnt = 0;
			so2->so_snd.sb_mb = 0;
			sorwakeup(so);
			sowwakeup(so2);
		}
E 4
I 4
		if (so2 == 0)
			break;
#define	rcv (&so->so_rcv)
#define snd (&so2->so_snd)
I 5
D 9
/*
printf("pru_rcvd in: ");
psndrcv(snd, rcv);
*/
E 9
E 5
		/*
		 * Transfer resources back to send port
		 * and wakeup any waiting to write.
		 */
		snd->sb_mbmax += rcv->sb_mbmax - rcv->sb_mbcnt;
		rcv->sb_mbmax = rcv->sb_mbcnt;
		snd->sb_hiwat += rcv->sb_hiwat - rcv->sb_cc;
		rcv->sb_hiwat = rcv->sb_cc;
I 5
D 9
/*
printf("pru_rcvd out: ");
psndrcv(snd, rcv);
*/
E 9
E 5
		sbwakeup(snd);
#undef snd
#undef rcv
E 4
		break;

	case PRU_SEND:
D 4
		sbappend(&so->so_snd, m);
		sorwakeup(so2);
E 4
I 4
#define	rcv (&so2->so_rcv)
#define	snd (&so->so_snd)
I 8
		if (so2 == 0)
			panic("pipe send");
E 8
		/*
		 * Send to paired receive port, and then
		 * give it enough resources to hold what it already has.
		 * Wake up readers.
		 */
I 5
D 9
/*
printf("pru_send in: ");
psndrcv(snd, rcv);
*/
E 9
E 5
		sbappend(rcv, m);
		snd->sb_mbmax -= rcv->sb_mbcnt - rcv->sb_mbmax;
		rcv->sb_mbmax = rcv->sb_mbcnt;
		snd->sb_hiwat -= rcv->sb_cc - rcv->sb_hiwat;
		rcv->sb_hiwat = rcv->sb_cc;
		sbwakeup(rcv);
I 5
D 9
/*
printf("pru_send out: ");
psndrcv(snd, rcv);
*/
E 9
E 5
#undef snd
#undef rcv
E 4
		break;

	case PRU_ABORT:
D 15
		return (EOPNOTSUPP);

E 15
	case PRU_CONTROL:
I 15
	case PRU_SENDOOB:
	case PRU_RCVOOB:
E 15
		return (EOPNOTSUPP);

	default:
D 3
		panic("pi_usrreq");
E 3
I 3
		panic("piusrreq");
E 3
	}
	return (0);
E 18
I 5
}
D 12

I 11
#ifdef notdef
E 11
psndrcv(snd, rcv)
	struct sockbuf *snd, *rcv;
{

	printf("snd: (cc,hiwat,mbcnt,mbmax) (%d,%d,%d,%d) ",
	    snd->sb_cc, snd->sb_hiwat, snd->sb_mbcnt, snd->sb_mbmax);
	printf("m %x, m->m_len %d\n", snd->sb_mb, snd->sb_mb ? snd->sb_mb->m_len : 0);
	printf("rcv: (cc,hiwat,mbcnt,mbmax) (%d,%d,%d,%d) ",
	    rcv->sb_cc, rcv->sb_hiwat, rcv->sb_mbcnt, rcv->sb_mbmax);
	printf("m %x, m->m_len %d\n", rcv->sb_mb, rcv->sb_mb ? rcv->sb_mb->m_len : 0);
E 5
}
I 11
#endif
E 12
E 11
E 1
