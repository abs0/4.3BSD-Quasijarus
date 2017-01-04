h08010
s 00010/00005/00695
d D 7.7 88/06/29 17:20:10 bostic 47 46
c install approved copyright notice
e
s 00015/00013/00685
d D 7.6 88/05/25 18:08:36 karels 46 45
c in attach, don't set sockbuf limits if set (from sonewconn); lint
e
s 00022/00008/00676
d D 7.5 88/05/24 09:47:47 karels 45 43
c fixes for unp_addr's from glenn skinner/dsr, but don't break datagrams
e
s 00023/00006/00678
d R 7.5 88/05/14 14:34:44 karels 44 43
c fixes for unp_addr's from glenn skinner/dsr
e
s 00002/00002/00682
d D 7.4 88/02/08 13:27:23 karels 43 42
c don't trip over files with type socket, f_data null
e
s 00008/00002/00676
d D 7.3 88/01/07 13:26:26 bostic 42 41
c add Berkeley header
e
s 00001/00001/00677
d D 7.2 88/01/07 13:20:41 bostic 41 40
c getpeername typo in mtod call; bug reports 4.3BSD/sys/{101,116}
e
s 00001/00001/00677
d D 7.1 86/06/05 00:18:04 mckusick 40 39
c 4.3BSD release version
e
s 00001/00001/00677
d D 6.23 86/06/02 14:41:53 karels 39 38
c lint
e
s 00005/00000/00673
d D 6.22 86/05/19 16:40:40 karels 38 37
c implement PRU_PEERADDR
e
s 00001/00001/00672
d D 6.21 86/02/23 23:13:12 karels 37 36
c lint
e
s 00003/00005/00670
d D 6.20 86/02/20 16:04:19 karels 36 35
c remove unused sonam arg to unp_connect2
e
s 00006/00001/00669
d D 6.19 86/01/13 17:41:46 karels 35 34
c don't indirect through unp_conn if it's been cleared
e
s 00064/00053/00606
d D 6.18 85/12/19 14:59:47 karels 34 33
c clean up stream flow control, give correct name for accept;
c record socket name at bind time
e
s 00002/00005/00657
d D 6.17 85/11/30 13:08:19 karels 33 32
c don't free ioctl cmds
e
s 00001/00001/00661
d D 6.16 85/10/18 17:10:21 mckusick 32 31
c attempting to bind() an already bound UNIX domain socket returns EINVAL (kre)
e
s 00006/00003/00656
d D 6.15 85/06/17 23:06:18 karels 31 30
c reflect failure back to sender if dg receive buffer full;
c plug another leak
e
s 00007/00001/00652
d D 6.14 85/06/08 15:09:20 mckusick 30 29
c Add copyright
e
s 00002/00001/00651
d D 6.13 85/06/02 23:35:09 karels 29 28
c minor cleanups
e
s 00005/00000/00647
d D 6.12 85/05/27 20:03:59 karels 28 27
c fix race when sosend blocks by returning EPIPE if receiver is gone;
c fake up inode numbers and dev for the naive
e
s 00015/00007/00632
d D 6.11 84/12/20 14:55:07 karels 27 26
c count those mbufs!; check access on Unix-domain socket connection;
c try for async. I/O in Unix domain
e
s 00013/00013/00626
d D 6.10 84/08/29 20:28:57 bloom 26 25
c Change to includes.  no more ../h
e
s 00005/00005/00634
d D 6.9 84/08/27 11:49:38 karels 25 24
c clear i_socket before reeleasing inode; fix unp_scan (no error if no rights)
e
s 00027/00023/00612
d D 6.8 84/08/21 10:43:08 karels 24 23
c change datagram queuing to use m_act properly; type mbufs with rights;
c change protocol family number in protosw to pointer to domain (for sam)
e
s 00030/00007/00605
d D 6.7 84/08/20 16:04:29 karels 23 22
c add sostat for blksize
e
s 00001/00001/00611
d D 6.6 84/07/26 17:11:04 bloom 22 21
c Receiving out of band data shouldn't free mbuf
e
s 00011/00007/00601
d D 6.5 84/07/08 16:18:13 mckusick 21 20
c rework `namei' interface to eliminate global variables
e
s 00001/00000/00607
d D 6.4 84/05/02 13:47:05 karels 20 19
c typo in last fix; free unp_remaddr in unp_drop
e
s 00008/00002/00599
d D 6.3 84/02/15 17:09:48 karels 19 18
c need to free any queued connections when closing;
c temporarily increase recvspace by a sockaddr (otherwise can't send
c max size datagram, but no EMSGSIZE)
e
s 00001/00001/00600
d D 6.2 83/09/08 10:53:32 mckusick 18 17
c fix for passing multiple file descriptors in a message (Bill Shannon)
e
s 00000/00000/00601
d D 6.1 83/07/29 06:50:02 sam 17 16
c 4.2 distribution
e
s 00003/00000/00598
d D 1.16 83/07/25 21:53:50 sam 16 15
c getpeer
e
s 00005/00007/00593
d D 1.15 83/07/21 02:03:43 sam 15 14
c fix datagram sockets so you can send more than one
e
s 00007/00003/00593
d D 1.14 83/06/14 22:11:38 sam 14 13
c no from address for datagrams, so sbappendaddr blows up
e
s 00012/00006/00584
d D 1.13 83/06/14 20:40:51 sam 13 12
c socketpair
e
s 00003/00003/00587
d D 1.12 83/06/13 22:43:14 sam 12 11
c lint
e
s 00001/00002/00589
d D 1.11 83/06/12 19:48:30 sam 11 10
c revamp network ioctls
e
s 00229/00026/00362
d D 1.10 83/05/27 12:51:31 sam 10 9
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00004/00000/00384
d D 1.9 83/04/03 00:45:40 sam 9 8
c check error return from namei; from mike@brl-vgr
e
s 00001/00001/00383
d D 1.8 83/03/23 15:43:27 sam 8 7
c not returning errors
e
s 00001/00002/00383
d D 1.7 83/01/13 18:34:19 sam 7 6
c no more opt parameter to usrreq
e
s 00007/00011/00378
d D 1.6 83/01/04 20:49:32 sam 6 5
c from reading the code -- boy is there a lot of work to be done
e
s 00001/00001/00388
d D 1.5 82/12/14 17:11:45 sam 5 4
c typed mbufs
e
s 00000/00001/00389
d D 1.4 82/11/23 14:08:04 sam 4 3
c close's on pipes make read on EOF look like an error
e
s 00109/00118/00281
d D 1.3 82/11/13 22:54:24 sam 3 2
c merge of 4.1b and 4.1c
e
s 00010/00010/00389
d D 1.2 82/11/03 00:46:46 root 2 1
c still not right
e
s 00399/00000/00000
d D 1.1 82/10/28 10:51:18 root 1 0
c date and time created 82/10/28 10:51:18 by root
e
u
U
f b 
t
T
I 1
D 30
/*	%M%	%I%	%E%	*/
E 30
I 30
/*
D 40
 * Copyright (c) 1982 Regents of the University of California.
E 40
I 40
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 40
D 42
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 42
I 42
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 47
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 47
I 47
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
E 47
E 42
 *
 *	%W% (Berkeley) %G%
 */
E 30

D 26
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/mbuf.h"
I 24
#include "../h/domain.h"
E 24
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
#include "../h/unpcb.h"
#include "../h/un.h"
#include "../h/inode.h"
I 3
D 21
#include "../h/nami.h"
E 21
I 10
#include "../h/file.h"
I 23
#include "../h/stat.h"
E 26
I 26
#include "param.h"
#include "dir.h"
#include "user.h"
#include "mbuf.h"
#include "domain.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "unpcb.h"
#include "un.h"
#include "inode.h"
#include "file.h"
#include "stat.h"
E 26
E 23
E 10
E 3

/*
 * Unix communications domain.
I 10
 *
 * TODO:
 *	SEQPACKET, RDM
D 14
 *	change for names in file system
E 14
I 14
 *	rethink name space problems
E 14
 *	need a proper out-of-band
E 10
 */
I 14
struct	sockaddr sun_noname = { AF_UNIX };
I 28
D 34
ino_t	unp_ino;				/* fake inode numbers */
E 34
I 34
ino_t	unp_ino;			/* prototype for fake inode numbers */
E 34
E 28
E 14

/*ARGSUSED*/
D 2
uipc_usrreq(so, req, m, addr)
E 2
I 2
D 7
uipc_usrreq(so, req, m, nam, opt)
E 7
I 7
D 10
uipc_usrreq(so, req, m, nam)
E 10
I 10
uipc_usrreq(so, req, m, nam, rights)
E 10
E 7
E 2
	struct socket *so;
	int req;
D 2
	struct mbuf *m;
	caddr_t addr;
E 2
I 2
D 10
	struct mbuf *m, *nam;
E 10
I 10
	struct mbuf *m, *nam, *rights;
E 10
D 7
	struct socketopt *opt;
E 7
E 2
{
	struct unpcb *unp = sotounpcb(so);
	register struct socket *so2;
	int error = 0;

I 33
	if (req == PRU_CONTROL)
		return (EOPNOTSUPP);
E 33
D 10
	if (unp == 0 && req != PRU_ATTACH)
		return (EINVAL);			/* XXX */
E 10
I 10
	if (req != PRU_SEND && rights && rights->m_len) {
		error = EOPNOTSUPP;
		goto release;
	}
	if (unp == 0 && req != PRU_ATTACH) {
		error = EINVAL;
		goto release;
	}
E 10
	switch (req) {

	case PRU_ATTACH:
		if (unp) {
D 3
			error = EINVAL;
E 3
I 3
			error = EISCONN;
E 3
			break;
		}
D 2
		error = unp_attach(so, (struct sockaddr *)addr);
E 2
I 2
		error = unp_attach(so);
E 2
		break;

	case PRU_DETACH:
		unp_detach(unp);
		break;

I 3
	case PRU_BIND:
		error = unp_bind(unp, nam);
		break;

	case PRU_LISTEN:
		if (unp->unp_inode == 0)
			error = EINVAL;
		break;

E 3
	case PRU_CONNECT:
D 2
		error = unp_connect(so, (struct sockaddr_un *)addr);
E 2
I 2
		error = unp_connect(so, nam);
E 2
		break;

I 10
D 13
#ifdef notdef
E 13
	case PRU_CONNECT2:
D 13
		error = unp_connect2(so, (struct mbuf *)0, (struct socket *)nam);
E 13
I 13
D 36
		error = unp_connect2(so, (struct mbuf *)0,
		    (struct socket *)nam);
E 36
I 36
		error = unp_connect2(so, (struct socket *)nam);
E 36
E 13
		break;

D 13
#endif
E 13
E 10
	case PRU_DISCONNECT:
		unp_disconnect(unp);
		break;

D 3
/* BEGIN QUESTIONABLE */
	case PRU_ACCEPT: {
D 2
		struct sockaddr_un *soun = (struct sockaddr_un *)addr;
E 2
I 2
		struct sockaddr_un *soun = mtod(nam, struct sockaddr_un *);
E 2

		if (soun) {
			bzero((caddr_t)soun, sizeof (*soun));
			soun->sun_family = AF_UNIX;
			/* XXX */
		}
		}
E 3
I 3
	case PRU_ACCEPT:
D 34
		nam->m_len = unp->unp_remaddr->m_len;
		bcopy(mtod(unp->unp_remaddr, caddr_t),
		    mtod(nam, caddr_t), (unsigned)nam->m_len);
E 34
I 34
D 35
		if (unp->unp_conn->unp_addr) {
E 35
I 35
		/*
		 * Pass back name of connected socket,
		 * if it was bound and we are still connected
		 * (our peer may have closed already!).
		 */
		if (unp->unp_conn && unp->unp_conn->unp_addr) {
E 35
			nam->m_len = unp->unp_conn->unp_addr->m_len;
			bcopy(mtod(unp->unp_conn->unp_addr, caddr_t),
			    mtod(nam, caddr_t), (unsigned)nam->m_len);
		} else {
			nam->m_len = sizeof(sun_noname);
			*(mtod(nam, struct sockaddr *)) = sun_noname;
		}
E 34
E 3
		break;

	case PRU_SHUTDOWN:
		socantsendmore(so);
		unp_usrclosed(unp);
		break;
D 3
/* END QUESTIONABLE */
E 3

	case PRU_RCVD:
		switch (so->so_type) {

		case SOCK_DGRAM:
			panic("uipc 1");
I 6
			/*NOTREACHED*/
E 6

D 6
		case SOCK_STREAM: {
E 6
I 6
		case SOCK_STREAM:
E 6
#define	rcv (&so->so_rcv)
#define snd (&so2->so_snd)
			if (unp->unp_conn == 0)
				break;
			so2 = unp->unp_conn->unp_socket;
			/*
D 34
			 * Transfer resources back to send port
E 34
I 34
			 * Adjust backpressure on sender
E 34
			 * and wakeup any waiting to write.
			 */
D 34
			snd->sb_mbmax += rcv->sb_mbmax - rcv->sb_mbcnt;
			rcv->sb_mbmax = rcv->sb_mbcnt;
			snd->sb_hiwat += rcv->sb_hiwat - rcv->sb_cc;
			rcv->sb_hiwat = rcv->sb_cc;
E 34
I 34
			snd->sb_mbmax += unp->unp_mbcnt - rcv->sb_mbcnt;
			unp->unp_mbcnt = rcv->sb_mbcnt;
			snd->sb_hiwat += unp->unp_cc - rcv->sb_cc;
			unp->unp_cc = rcv->sb_cc;
E 34
D 27
			sbwakeup(snd);
E 27
I 27
			sowwakeup(so2);
E 27
#undef snd
#undef rcv
D 6
			}
E 6
			break;

		default:
			panic("uipc 2");
		}
		break;

	case PRU_SEND:
I 34
		if (rights) {
			error = unp_internalize(rights);
			if (error)
				break;
		}
E 34
		switch (so->so_type) {

D 34
		case SOCK_DGRAM:
E 34
I 34
		case SOCK_DGRAM: {
			struct sockaddr *from;

E 34
D 2
			if (addr) {
E 2
I 2
			if (nam) {
E 2
				if (unp->unp_conn) {
					error = EISCONN;
					break;
				}
D 2
				error = unp_connect(so, addr);
E 2
I 2
				error = unp_connect(so, nam);
E 2
				if (error)
					break;
			} else {
				if (unp->unp_conn == 0) {
					error = ENOTCONN;
					break;
				}
			}
			so2 = unp->unp_conn->unp_socket;
D 3
			if (sbspace(&so2->so_rcv) > 0)		/* XXX */
D 2
				sbappendaddr(so2, m, addr);	/* XXX */
			if (addr)
E 2
I 2
				sbappendaddr(so2, m, nam);	/* XXX */
E 3
I 3
D 34
			/* BEGIN XXX */
D 10
			if (sbspace(&so2->so_rcv) > 0)
E 10
I 10
			if (rights) {
				error = unp_internalize(rights);
				if (error)
					break;
			}
			if (sbspace(&so2->so_rcv) > 0) {
I 14
				/*
				 * There's no record of source socket's
				 * name, so send null name for the moment.
				 */
E 14
E 10
D 27
				(void) sbappendaddr(&so2->so_rcv,
D 10
					mtod(nam, struct sockaddr *), m);
E 10
I 10
D 14
				    mtod(nam, struct sockaddr *), m,
				    rights);
E 14
I 14
				    &sun_noname, m, rights);
E 14
				sbwakeup(&so2->so_rcv);
				m = 0;
E 27
I 27
				if (sbappendaddr(&so2->so_rcv,
				    &sun_noname, m, rights)) {
					sorwakeup(so2);
					m = 0;
D 31
				}
E 31
I 31
				} else
					error = ENOBUFS;
E 31
E 27
			}
E 10
			/* END XXX */
E 34
I 34
			if (unp->unp_addr)
				from = mtod(unp->unp_addr, struct sockaddr *);
			else
				from = &sun_noname;
			if (sbspace(&so2->so_rcv) > 0 &&
			    sbappendaddr(&so2->so_rcv, from, m, rights)) {
				sorwakeup(so2);
				m = 0;
			} else
				error = ENOBUFS;
E 34
E 3
			if (nam)
E 2
D 3
				unp_disconnect(so);
E 3
I 3
				unp_disconnect(unp);
E 3
			break;
I 34
		}
E 34

		case SOCK_STREAM:
#define	rcv (&so2->so_rcv)
#define	snd (&so->so_snd)
I 10
D 34
			if (rights && rights->m_len) {
				error = EOPNOTSUPP;
				break;
			}
E 34
I 28
D 31
			if (so->so_state & SS_CANTSENDMORE)
				return (EPIPE);
E 31
I 31
			if (so->so_state & SS_CANTSENDMORE) {
				error = EPIPE;
				break;
			}
E 31
E 28
E 10
			if (unp->unp_conn == 0)
				panic("uipc 3");
			so2 = unp->unp_conn->unp_socket;
			/*
D 34
			 * Send to paired receive port, and then
			 * give it enough resources to hold what it already has.
E 34
I 34
			 * Send to paired receive port, and then reduce
			 * send buffer hiwater marks to maintain backpressure.
E 34
			 * Wake up readers.
			 */
D 34
			sbappend(rcv, m);
			snd->sb_mbmax -= rcv->sb_mbcnt - rcv->sb_mbmax;
			rcv->sb_mbmax = rcv->sb_mbcnt;
			snd->sb_hiwat -= rcv->sb_cc - rcv->sb_hiwat;
			rcv->sb_hiwat = rcv->sb_cc;
E 34
I 34
			if (rights)
D 37
				sbappendrights(rcv, m, rights);
E 37
I 37
				(void)sbappendrights(rcv, m, rights);
E 37
			else
				sbappend(rcv, m);
			snd->sb_mbmax -=
			    rcv->sb_mbcnt - unp->unp_conn->unp_mbcnt;
			unp->unp_conn->unp_mbcnt = rcv->sb_mbcnt;
			snd->sb_hiwat -= rcv->sb_cc - unp->unp_conn->unp_cc;
			unp->unp_conn->unp_cc = rcv->sb_cc;
E 34
D 27
			sbwakeup(rcv);
E 27
I 27
			sorwakeup(so2);
			m = 0;
E 27
#undef snd
#undef rcv
			break;

		default:
			panic("uipc 4");
		}
I 10
D 27
		m = 0;
E 27
E 10
		break;

	case PRU_ABORT:
		unp_drop(unp, ECONNABORTED);
		break;

D 33
/* SOME AS YET UNIMPLEMENTED HOOKS */
	case PRU_CONTROL:
D 11
		error = EOPNOTSUPP;
		break;
E 11
I 11
		return (EOPNOTSUPP);
E 11

D 23
	case PRU_SENSE:
		error = EOPNOTSUPP;
		break;
E 23
/* END UNIMPLEMENTED HOOKS */
E 33
I 23
	case PRU_SENSE:
		((struct stat *) m)->st_blksize = so->so_snd.sb_hiwat;
		if (so->so_type == SOCK_STREAM && unp->unp_conn != 0) {
			so2 = unp->unp_conn->unp_socket;
			((struct stat *) m)->st_blksize += so2->so_rcv.sb_cc;
		}
I 28
		((struct stat *) m)->st_dev = NODEV;
D 34
		((struct stat *) m)->st_ino = unp_ino++;
E 34
I 34
		if (unp->unp_ino == 0)
			unp->unp_ino = unp_ino++;
		((struct stat *) m)->st_ino = unp->unp_ino;
E 34
E 28
		return (0);
E 23

	case PRU_RCVOOB:
D 22
		break;
E 22
I 22
		return (EOPNOTSUPP);
E 22

	case PRU_SENDOOB:
I 27
		error = EOPNOTSUPP;
E 27
		break;

	case PRU_SOCKADDR:
I 45
		if (unp->unp_addr) {
			nam->m_len = unp->unp_addr->m_len;
			bcopy(mtod(unp->unp_addr, caddr_t),
			    mtod(nam, caddr_t), (unsigned)nam->m_len);
		} else
			nam->m_len = 0;
E 45
		break;

I 16
	case PRU_PEERADDR:
I 38
		if (unp->unp_conn && unp->unp_conn->unp_addr) {
			nam->m_len = unp->unp_conn->unp_addr->m_len;
			bcopy(mtod(unp->unp_conn->unp_addr, caddr_t),
D 39
			    mtod(m, caddr_t), m->m_len);
E 39
I 39
D 41
			    mtod(m, caddr_t), (unsigned)m->m_len);
E 41
I 41
			    mtod(nam, caddr_t), (unsigned)nam->m_len);
E 41
E 39
D 45
		}
E 45
I 45
		} else
			nam->m_len = 0;
E 45
E 38
		break;

E 16
	case PRU_SLOWTIMO:
		break;

	default:
		panic("piusrreq");
	}
I 10
release:
	if (m)
		m_freem(m);
E 10
D 8
	return (0);
E 8
I 8
	return (error);
E 8
}

I 10
D 23
/* SHOULD BE PIPSIZ and 0 */
E 10
int	unp_sendspace = 1024*2;
D 19
int	unp_recvspace = 1024*2;
E 19
I 19
int	unp_recvspace = 1024*2 + sizeof(struct sockaddr);
E 23
I 23
/*
D 34
 * We assign all buffering for stream sockets to the source,
 * as that is where the flow control is implemented.
E 34
I 34
 * Both send and receive buffers are allocated PIPSIZ bytes of buffering
 * for stream sockets, although the total for sender and receiver is
 * actually only PIPSIZ.
E 34
 * Datagram sockets really use the sendspace as the maximum datagram size,
 * and don't really want to reserve the sendspace.  Their recvspace should
 * be large enough for at least one max-size datagram plus address.
 */
#define	PIPSIZ	4096
D 46
int	unpst_sendspace = PIPSIZ;
D 34
int	unpst_recvspace = 0;
E 34
I 34
int	unpst_recvspace = PIPSIZ;
E 34
int	unpdg_sendspace = 2*1024;	/* really max datagram size */
int	unpdg_recvspace = 4*1024;
E 46
I 46
u_long	unpst_sendspace = PIPSIZ;
u_long	unpst_recvspace = PIPSIZ;
u_long	unpdg_sendspace = 2*1024;	/* really max datagram size */
u_long	unpdg_recvspace = 4*1024;
E 46
E 23
E 19

I 34
int	unp_rights;			/* file descriptors in flight */

E 34
D 3
unp_attach(so, soun)
E 3
I 3
unp_attach(so)
E 3
	struct socket *so;
D 3
	struct sockaddr_un *soun;
E 3
{
I 3
	register struct mbuf *m;
E 3
	register struct unpcb *unp;
D 3
	struct mbuf *m;
E 3
	int error;
	
D 23
	error = soreserve(so, unp_sendspace, unp_recvspace);
E 23
I 23
D 46
	switch (so->so_type) {
E 46
I 46
	if (so->so_snd.sb_hiwat == 0 || so->so_rcv.sb_hiwat == 0) {
		switch (so->so_type) {
E 46

D 46
	case SOCK_STREAM:
		error = soreserve(so, unpst_sendspace, unpst_recvspace);
		break;
E 46
I 46
		case SOCK_STREAM:
			error = soreserve(so, unpst_sendspace, unpst_recvspace);
			break;
E 46

D 46
	case SOCK_DGRAM:
		error = soreserve(so, unpdg_sendspace, unpdg_recvspace);
		break;
E 46
I 46
		case SOCK_DGRAM:
			error = soreserve(so, unpdg_sendspace, unpdg_recvspace);
			break;
		}
		if (error)
			return (error);
E 46
	}
E 23
D 46
	if (error)
D 6
		goto bad;
E 6
I 6
		return (error);
E 46
E 6
D 5
	m = m_getclr(M_DONTWAIT);
E 5
I 5
	m = m_getclr(M_DONTWAIT, MT_PCB);
E 5
D 6
	if (m == 0) {
		error = ENOBUFS;
		goto bad;
	}
E 6
I 6
	if (m == NULL)
		return (ENOBUFS);
E 6
	unp = mtod(m, struct unpcb *);
	so->so_pcb = (caddr_t)unp;
	unp->unp_socket = so;
D 3
	if (soun) {
		error = unp_bind(unp, soun);
		if (error) {
			unp_detach(unp);
			goto bad;
		}
	}
E 3
	return (0);
D 6
bad:
	return (error);
E 6
}

D 3
unp_disconnect(unp)
	struct unpcb *unp;
{
	register struct unpcb *unp2 = unp->unp_conn;

	if (unp2 == 0)
		return;
	unp->unp_conn = 0;
	soisdisconnected(unp->unp_socket);
	switch (unp->unp_socket->so_type) {

	case SOCK_DGRAM:
		if (unp2->unp_refs == unp)
			unp2->unp_refs = unp->unp_nextref;
		else {
			unp2 = unp2->unp_refs;
			for (;;) {
				if (unp2 == 0)
					panic("unp_disconnect");
				if (unp2->unp_nextref == unp)
					break;
				unp2 = unp2->unp_nextref;
			}
			unp2->unp_nextref = unp->unp_nextref;
		}
		unp->unp_nextref = 0;
		break;

	case SOCK_STREAM:
		unp2->unp_conn = 0;
		soisdisconnected(unp2->unp_socket);
		unp_drop(unp2, ECONNRESET);
		break;
	}
}

unp_abort(unp)
	struct unpcb *unp;
{

	unp_detach(unp);
}

E 3
unp_detach(unp)
D 3
	struct unpcb *unp;
E 3
I 3
	register struct unpcb *unp;
E 3
{
	
	if (unp->unp_inode) {
I 25
		unp->unp_inode->i_socket = 0;
E 25
		irele(unp->unp_inode);
		unp->unp_inode = 0;
	}
	if (unp->unp_conn)
		unp_disconnect(unp);
	while (unp->unp_refs)
		unp_drop(unp->unp_refs, ECONNRESET);
	soisdisconnected(unp->unp_socket);
	unp->unp_socket->so_pcb = 0;
D 3
	m_free(dtom(unp));
E 3
I 3
D 34
	m_freem(unp->unp_remaddr);
E 34
I 34
	m_freem(unp->unp_addr);
E 34
	(void) m_free(dtom(unp));
I 34
	if (unp_rights)
		unp_gc();
E 34
E 3
}

D 3
unp_usrclosed(unp)
E 3
I 3
unp_bind(unp, nam)
E 3
	struct unpcb *unp;
I 3
	struct mbuf *nam;
E 3
{
D 3
	register struct socket *so = unp->unp_socket;

#ifdef sometimes /* ??? */
	soisdisconnected(unp->unp_socket);
#endif
}

unp_drop(unp, errno)
	struct unpcb *unp;
	int errno;
{

	unp->unp_socket->so_error = errno;
	unp_disconnect(unp);
}

unp_drain()
{

}

unp_bind(unp, soun)
	struct unpcb *unp;
	struct sockaddr_un *soun;
{
E 3
I 3
	struct sockaddr_un *soun = mtod(nam, struct sockaddr_un *);
E 3
	register struct inode *ip;
D 3
	int error;
E 3
D 21
	extern schar();
E 21
I 21
	register struct nameidata *ndp = &u.u_nd;
E 21
I 3
	int error;
E 3

D 21
	u.u_dirp = soun->sun_path;
E 21
I 21
	ndp->ni_dirp = soun->sun_path;
E 21
D 10
	soun->sun_path[sizeof(soun->sun_path)-1] = 0;
E 10
I 10
D 32
	if (nam->m_len == MLEN)
E 32
I 32
	if (unp->unp_inode != NULL || nam->m_len == MLEN)
E 32
		return (EINVAL);
	*(mtod(nam, caddr_t) + nam->m_len) = 0;
/* SHOULD BE ABLE TO ADOPT EXISTING AND wakeup() ALA FIFO's */
E 10
D 3
	ip = namei(schar, 1, 1);
E 3
I 3
D 21
	ip = namei(schar, CREATE, 1);
E 21
I 21
	ndp->ni_nameiop = CREATE | FOLLOW;
	ndp->ni_segflg = UIO_SYSSPACE;
	ip = namei(ndp);
E 21
E 3
	if (ip) {
		iput(ip);
D 6
		return (EEXIST);
E 6
I 6
		return (EADDRINUSE);
E 6
	}
I 9
	if (error = u.u_error) {
		u.u_error = 0;			/* XXX */
		return (error);
	}
E 9
D 21
	ip = maknode(IFSOCK | 0777);
E 21
I 21
	ip = maknode(IFSOCK | 0777, ndp);
E 21
	if (ip == NULL) {
		error = u.u_error;		/* XXX */
		u.u_error = 0;			/* XXX */
		return (error);
	}
	ip->i_socket = unp->unp_socket;
	unp->unp_inode = ip;
I 34
	unp->unp_addr = m_copy(nam, 0, (int)M_COPYALL);
E 34
	iunlock(ip);			/* but keep reference */
	return (0);
}

D 3
unp_connect(so, soun)
E 3
I 3
unp_connect(so, nam)
E 3
	struct socket *so;
D 3
	struct sockaddr_un *soun;
E 3
I 3
	struct mbuf *nam;
E 3
{
D 3
	struct inode *ip;
E 3
I 3
	register struct sockaddr_un *soun = mtod(nam, struct sockaddr_un *);
D 10
	struct unpcb *unp = sotounpcb(so);
E 10
	register struct inode *ip;
E 3
D 45
	int error;
I 3
D 10
	struct socket *so2;
	struct unpcb *unp2;
E 10
I 10
	register struct socket *so2;
E 45
I 45
	register struct socket *so2, *so3;
E 45
I 21
	register struct nameidata *ndp = &u.u_nd;
I 45
	struct unpcb *unp2, *unp3;
	int error;
E 45
E 21
E 10
E 3

D 21
	u.u_dirp = soun->sun_path;
E 21
I 21
	ndp->ni_dirp = soun->sun_path;
E 21
D 10
	soun->sun_path[sizeof(soun->sun_path)-1] = 0;
E 10
I 10
	if (nam->m_len + (nam->m_off - MMINOFF) == MLEN)
		return (EMSGSIZE);
	*(mtod(nam, caddr_t) + nam->m_len) = 0;
E 10
D 3
	ip = namei(schar, 0, 1);
E 3
I 3
D 21
	ip = namei(schar, LOOKUP, 1);
E 21
I 21
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_SYSSPACE;
	ip = namei(ndp);
E 21
E 3
	if (ip == 0) {
		error = u.u_error;
		u.u_error = 0;
D 6
		return (ENOENT);
E 6
I 6
		return (error);		/* XXX */
E 6
	}
I 27
	if (access(ip, IWRITE)) {
		error = u.u_error;
		u.u_error = 0; 		/* XXX */
		goto bad;
	}
E 27
D 3
	error = unp_connectip(so, ip);
	return (error);
}

unp_connectip(so, ip)
	struct socket *so;
	struct inode *ip;
{
	struct unpcb *unp = sotounpcb(so);
	struct socket *so2, *so3;
	int error;
	struct unpcb *unp2;

E 3
	if ((ip->i_mode&IFMT) != IFSOCK) {
		error = ENOTSOCK;
		goto bad;
	}
	so2 = ip->i_socket;
	if (so2 == 0) {
		error = ECONNREFUSED;
		goto bad;
	}
I 13
	if (so->so_type != so2->so_type) {
		error = EPROTOTYPE;
		goto bad;
	}
D 45
	if (so->so_proto->pr_flags & PR_CONNREQUIRED &&
	    ((so2->so_options&SO_ACCEPTCONN) == 0 ||
	     (so2 = sonewconn(so2)) == 0)) {
		error = ECONNREFUSED;
		goto bad;
E 45
I 45
	if (so->so_proto->pr_flags & PR_CONNREQUIRED) {
		if ((so2->so_options & SO_ACCEPTCONN) == 0 ||
		    (so3 = sonewconn(so2)) == 0) {
			error = ECONNREFUSED;
			goto bad;
		}
		unp2 = sotounpcb(so2);
		unp3 = sotounpcb(so3);
		if (unp2->unp_addr)
			unp3->unp_addr = m_copy(unp2->unp_addr, 0, M_COPYALL);
		so2 = so3;
E 45
	}
E 13
D 10
	if (so2->so_type != so->so_type) {
		error = EPROTOTYPE;
		goto bad;
	}
E 10
I 10
D 36
	error = unp_connect2(so, nam, so2);
E 36
I 36
	error = unp_connect2(so, so2);
E 36
bad:
	iput(ip);
	return (error);
}

D 36
unp_connect2(so, sonam, so2)
E 36
I 36
unp_connect2(so, so2)
E 36
	register struct socket *so;
D 36
	struct mbuf *sonam;
E 36
	register struct socket *so2;
{
	register struct unpcb *unp = sotounpcb(so);
	register struct unpcb *unp2;

	if (so2->so_type != so->so_type)
		return (EPROTOTYPE);
I 15
	unp2 = sotounpcb(so2);
	unp->unp_conn = unp2;
E 15
E 10
	switch (so->so_type) {

	case SOCK_DGRAM:
D 10
		unp->unp_conn = sotounpcb(so2);
E 10
D 15
		unp2 = sotounpcb(so2);
I 10
		unp->unp_conn = unp2;
E 15
E 10
		unp->unp_nextref = unp2->unp_refs;
		unp2->unp_refs = unp;
I 27
		soisconnected(so);
E 27
		break;

	case SOCK_STREAM:
D 13
		if ((so2->so_options&SO_ACCEPTCONN) == 0 ||
D 3
		    (so3 = sonewconn(so2)) == 0) {
E 3
I 3
D 10
		    (so2 = sonewconn(so2)) == 0) {
E 3
			error = ECONNREFUSED;
			goto bad;
		}
E 10
I 10
		    (so2 = sonewconn(so2)) == 0)
			return (ECONNREFUSED);
E 13
E 10
D 3
		unp->unp_conn = sotounpcb(so3);
E 3
I 3
D 15
		unp2 = sotounpcb(so2);
		unp->unp_conn = unp2;
E 15
		unp2->unp_conn = unp;
D 10
		unp2->unp_remaddr = m_copy(nam, 0, (int)M_COPYALL);
E 10
I 10
D 34
		if (sonam)
			unp2->unp_remaddr = m_copy(sonam, 0, (int)M_COPYALL);
E 34
I 15
		soisconnected(so2);
		soisconnected(so);
E 15
E 10
E 3
		break;

	default:
D 10
		panic("uipc connip");
E 10
I 10
		panic("unp_connect2");
E 10
	}
D 3
	soisconnected(unp->unp_conn->unp_socket);
E 3
I 3
D 15
	soisconnected(so2);
E 3
	soisconnected(so);
E 15
D 10
	iput(ip);
E 10
	return (0);
D 10
bad:
	iput(ip);
	return (error);
E 10
I 3
}

unp_disconnect(unp)
	struct unpcb *unp;
{
	register struct unpcb *unp2 = unp->unp_conn;

	if (unp2 == 0)
		return;
	unp->unp_conn = 0;
D 15
	soisdisconnected(unp->unp_socket);
E 15
	switch (unp->unp_socket->so_type) {

	case SOCK_DGRAM:
		if (unp2->unp_refs == unp)
			unp2->unp_refs = unp->unp_nextref;
		else {
			unp2 = unp2->unp_refs;
			for (;;) {
				if (unp2 == 0)
					panic("unp_disconnect");
				if (unp2->unp_nextref == unp)
					break;
				unp2 = unp2->unp_nextref;
			}
			unp2->unp_nextref = unp->unp_nextref;
		}
		unp->unp_nextref = 0;
I 29
		unp->unp_socket->so_state &= ~SS_ISCONNECTED;
E 29
		break;

	case SOCK_STREAM:
I 15
		soisdisconnected(unp->unp_socket);
E 15
		unp2->unp_conn = 0;
		soisdisconnected(unp2->unp_socket);
D 4
		unp_drop(unp2, ECONNRESET);
E 4
		break;
	}
}

I 10
#ifdef notdef
E 10
unp_abort(unp)
	struct unpcb *unp;
{

	unp_detach(unp);
}
I 10
#endif
E 10

/*ARGSUSED*/
unp_usrclosed(unp)
	struct unpcb *unp;
{

}

unp_drop(unp, errno)
	struct unpcb *unp;
	int errno;
{
I 19
	struct socket *so = unp->unp_socket;
E 19

D 19
	unp->unp_socket->so_error = errno;
E 19
I 19
	so->so_error = errno;
E 19
	unp_disconnect(unp);
I 19
	if (so->so_head) {
		so->so_pcb = (caddr_t) 0;
I 20
D 34
		m_freem(unp->unp_remaddr);
E 34
I 34
		m_freem(unp->unp_addr);
E 34
E 20
		(void) m_free(dtom(unp));
		sofree(so);
	}
E 19
}

I 10
#ifdef notdef
E 10
unp_drain()
{

I 10
}
#endif

unp_externalize(rights)
	struct mbuf *rights;
{
	int newfds = rights->m_len / sizeof (int);
	register int i;
	register struct file **rp = mtod(rights, struct file **);
	register struct file *fp;
	int f;

	if (newfds > ufavail()) {
		for (i = 0; i < newfds; i++) {
			fp = *rp;
			unp_discard(fp);
			*rp++ = 0;
		}
		return (EMSGSIZE);
	}
	for (i = 0; i < newfds; i++) {
		f = ufalloc(0);
		if (f < 0)
			panic("unp_externalize");
		fp = *rp;
		u.u_ofile[f] = fp;
		fp->f_msgcount--;
I 34
		unp_rights--;
E 34
D 18
		*(int *)rp = f;
E 18
I 18
		*(int *)rp++ = f;
E 18
	}
	return (0);
}

unp_internalize(rights)
	struct mbuf *rights;
{
	register struct file **rp;
	int oldfds = rights->m_len / sizeof (int);
	register int i;
	register struct file *fp;

	rp = mtod(rights, struct file **);
D 12
	for (i = 0; i < oldfds; i++) {
E 12
I 12
	for (i = 0; i < oldfds; i++)
E 12
		if (getf(*(int *)rp++) == 0)
			return (EBADF);
	rp = mtod(rights, struct file **);
D 12
	for (i = 0; i < oldfds; i++)
E 12
I 12
	for (i = 0; i < oldfds; i++) {
E 12
		fp = getf(*(int *)rp);
		*rp++ = fp;
		fp->f_count++;
		fp->f_msgcount++;
I 34
		unp_rights++;
E 34
	}
	return (0);
}

int	unp_defer, unp_gcing;
int	unp_mark();
I 24
extern	struct domain unixdomain;
E 24

unp_gc()
{
	register struct file *fp;
	register struct socket *so;

	if (unp_gcing)
		return;
	unp_gcing = 1;
restart:
	unp_defer = 0;
	for (fp = file; fp < fileNFILE; fp++)
		fp->f_flag &= ~(FMARK|FDEFER);
	do {
		for (fp = file; fp < fileNFILE; fp++) {
			if (fp->f_count == 0)
				continue;
			if (fp->f_flag & FDEFER) {
				fp->f_flag &= ~FDEFER;
				unp_defer--;
			} else {
				if (fp->f_flag & FMARK)
					continue;
				if (fp->f_count == fp->f_msgcount)
					continue;
				fp->f_flag |= FMARK;
			}
D 43
			if (fp->f_type != DTYPE_SOCKET)
E 43
I 43
			if (fp->f_type != DTYPE_SOCKET ||
			    (so = (struct socket *)fp->f_data) == 0)
E 43
				continue;
D 43
			so = (struct socket *)fp->f_data;
E 43
D 24
			if (so->so_proto->pr_family != AF_UNIX ||
E 24
I 24
			if (so->so_proto->pr_domain != &unixdomain ||
E 24
D 29
			    (so->so_proto->pr_flags&PR_ADDR) == 0)
E 29
I 29
			    (so->so_proto->pr_flags&PR_RIGHTS) == 0)
E 29
				continue;
			if (so->so_rcv.sb_flags & SB_LOCK) {
				sbwait(&so->so_rcv);
				goto restart;
			}
			unp_scan(so->so_rcv.sb_mb, unp_mark);
		}
	} while (unp_defer);
	for (fp = file; fp < fileNFILE; fp++) {
		if (fp->f_count == 0)
			continue;
D 34
		if (fp->f_count == fp->f_msgcount && (fp->f_flag&FMARK)==0) {
			if (fp->f_type != DTYPE_SOCKET)
				panic("unp_gc");
			(void) soshutdown((struct socket *)fp->f_data, 0);
		}
E 34
I 34
		if (fp->f_count == fp->f_msgcount && (fp->f_flag & FMARK) == 0)
			while (fp->f_msgcount)
				unp_discard(fp);
E 34
	}
	unp_gcing = 0;
}

D 24
unp_scan(m, op)
	register struct mbuf *m;
E 24
I 24
unp_dispose(m)
	struct mbuf *m;
{
	int unp_discard();

D 25
	unp_scan(m, unp_discard);
E 25
I 25
	if (m)
		unp_scan(m, unp_discard);
E 25
}

unp_scan(m0, op)
	register struct mbuf *m0;
E 24
	int (*op)();
{
I 24
	register struct mbuf *m;
E 24
	register struct file **rp;
	register int i;
D 24
	int qfds;
E 24
I 24
D 25
	int qfds = 0;
E 25
I 25
	int qfds;
E 25
E 24

D 24
	while (m) {
		m = m->m_next;
		if (m == 0)
			goto bad;
		if (m->m_len) {
			qfds = m->m_len / sizeof (struct file *);
			rp = mtod(m, struct file **);
			for (i = 0; i < qfds; i++)
				(*op)(*rp++);
		}
		do {
			m = m->m_next;
			if (m == 0)
				goto bad;
		} while (m->m_act == 0);
		m = m->m_next;
E 24
I 24
	while (m0) {
		for (m = m0; m; m = m->m_next)
			if (m->m_type == MT_RIGHTS && m->m_len) {
				qfds = m->m_len / sizeof (struct file *);
				rp = mtod(m, struct file **);
				for (i = 0; i < qfds; i++)
					(*op)(*rp++);
				break;		/* XXX, but saves time */
			}
D 25
		m0 = m0->m_next;
E 25
I 25
		m0 = m0->m_act;
E 25
E 24
	}
D 24
	return;
bad:
	panic("unp_gcscan");
E 24
I 24
D 25
	if (qfds == 0)
		panic("unp_gcscan");
E 25
E 24
}

unp_mark(fp)
	struct file *fp;
{

	if (fp->f_flag & FMARK)
		return;
	unp_defer++;
	fp->f_flag |= (FMARK|FDEFER);
}

unp_discard(fp)
	struct file *fp;
{

	fp->f_msgcount--;
I 34
	unp_rights--;
E 34
D 12
	closef(fp, 0);
E 12
I 12
	closef(fp);
E 12
E 10
E 3
}
E 1
