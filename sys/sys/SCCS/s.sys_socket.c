h37132
s 00010/00005/00154
d D 7.3 88/06/29 17:18:13 bostic 15 14
c install approved copyright notice
e
s 00009/00003/00150
d D 7.2 88/03/31 15:44:32 bostic 14 13
c add Berkeley specific header
e
s 00001/00001/00152
d D 7.1 86/06/05 00:08:28 mckusick 13 12
c 4.3BSD release version
e
s 00009/00000/00144
d D 6.6 85/09/16 20:52:33 karels 12 11
c allow select on exceptional conditions to notify of urgent data pending;
c connect on connected datagram socket does disconnect first; error status
c socket option
e
s 00007/00001/00137
d D 6.5 85/06/08 14:44:28 mckusick 11 10
c Add copyright
e
s 00001/00001/00137
d D 6.4 85/03/18 15:22:24 karels 10 9
c ifioctl args change
e
s 00012/00012/00126
d D 6.3 84/08/29 20:22:22 bloom 9 8
c Change to includes.  no more ../h
e
s 00000/00006/00138
d D 6.2 84/08/21 10:24:28 karels 8 7
c sostat now does the SENSE
e
s 00000/00000/00144
d D 6.1 83/07/29 06:37:47 sam 7 6
c 4.2 distribution
e
s 00004/00002/00140
d D 4.6 83/07/20 21:31:19 sam 6 5
c guard against null pointers 
e
s 00004/00019/00138
d D 4.5 83/06/13 23:04:19 sam 5 4
c lint and purge non operative locking on sockets
e
s 00018/00034/00139
d D 4.4 83/06/12 19:48:26 sam 4 3
c revamp network ioctls
e
s 00023/00005/00150
d D 4.3 83/06/12 14:30:17 sam 3 2
c cleanup locking a bit; fix problem with close not unlocking
e
s 00004/00000/00151
d D 4.2 83/06/11 00:53:46 sam 2 1
c FIONREAD
e
s 00151/00000/00000
d D 4.1 83/05/27 14:02:53 sam 1 0
c date and time created 83/05/27 14:02:53 by sam
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
E 14
 *
I 14
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
 *
E 14
 *	%W% (Berkeley) %G%
 */
E 11

D 9
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/file.h"
#include "../h/mbuf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
#include "../h/ioctl.h"
#include "../h/uio.h"
#include "../h/stat.h"
E 9
I 9
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "file.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "ioctl.h"
#include "uio.h"
#include "stat.h"
E 9

#include "../net/if.h"
#include "../net/route.h"

D 3
int	soo_rw(), soo_ioctl(), soo_select(), soo_stat(), soo_close();
E 3
I 3
int	soo_rw(), soo_ioctl(), soo_select(), soo_close();
E 3
struct	fileops socketops =
D 3
    { soo_rw, soo_ioctl, soo_select, soo_stat, soo_close };
E 3
I 3
    { soo_rw, soo_ioctl, soo_select, soo_close };
E 3

soo_rw(fp, rw, uio)
	struct file *fp;
	enum uio_rw rw;
	struct uio *uio;
{
	int soreceive(), sosend();

	return (
	    (*(rw==UIO_READ?soreceive:sosend))
	      ((struct socket *)fp->f_data, 0, uio, 0, 0));
}

soo_ioctl(fp, cmd, data)
	struct file *fp;
	int cmd;
	register caddr_t data;
{
	register struct socket *so = (struct socket *)fp->f_data;

	switch (cmd) {

	case FIONBIO:
		if (*(int *)data)
			so->so_state |= SS_NBIO;
		else
			so->so_state &= ~SS_NBIO;
D 4
		break;
E 4
I 4
		return (0);
E 4

	case FIOASYNC:
		if (*(int *)data)
			so->so_state |= SS_ASYNC;
		else
			so->so_state &= ~SS_ASYNC;
D 4
		break;
E 4
I 4
		return (0);
E 4

I 2
	case FIONREAD:
		*(int *)data = so->so_rcv.sb_cc;
D 4
		break;
E 4
I 4
		return (0);
E 4

E 2
	case SIOCSPGRP:
		so->so_pgrp = *(int *)data;
D 4
		break;
E 4
I 4
		return (0);
E 4

	case SIOCGPGRP:
		*(int *)data = so->so_pgrp;
D 4
		break;
E 4
I 4
		return (0);
E 4

	case SIOCATMARK:
		*(int *)data = (so->so_state&SS_RCVATMARK) != 0;
D 4
		break;

	/* routing table update calls */
	case SIOCADDRT:
	case SIOCDELRT:
		if (!suser())
			return (u.u_error);
		return (rtrequest(cmd, (struct rtentry *)data));

	/* interface parameter requests */
	case SIOCSIFADDR:
	case SIOCSIFFLAGS:
	case SIOCSIFDSTADDR:
		if (!suser())
			return (u.u_error);
		return (ifrequest(cmd, data));

	case SIOCGIFADDR:
	case SIOCGIFFLAGS:
	case SIOCGIFDSTADDR:
		return (ifrequest(cmd, data));

	case SIOCGIFCONF:
		return (ifconf(cmd, data));

	/* type/protocol specific ioctls */
	default:
		return (ENOTTY);		/* XXX */
E 4
I 4
		return (0);
E 4
	}
D 4
	return (0);
E 4
I 4
	/*
	 * Interface/routing/protocol specific ioctls:
	 * interface and routing ioctls should have a
	 * different entry since a socket's unnecessary
	 */
#define	cmdbyte(x)	(((x) >> 8) & 0xff)
	if (cmdbyte(cmd) == 'i')
D 10
		return (ifioctl(cmd, data));
E 10
I 10
		return (ifioctl(so, cmd, data));
E 10
	if (cmdbyte(cmd) == 'r')
		return (rtioctl(cmd, data));
	return ((*so->so_proto->pr_usrreq)(so, PRU_CONTROL, 
	    (struct mbuf *)cmd, (struct mbuf *)data, (struct mbuf *)0));
E 4
}

soo_select(fp, which)
	struct file *fp;
	int which;
{
	register struct socket *so = (struct socket *)fp->f_data;
	register int s = splnet();

	switch (which) {

	case FREAD:
		if (soreadable(so)) {
			splx(s);
			return (1);
		}
		sbselqueue(&so->so_rcv);
		break;

	case FWRITE:
		if (sowriteable(so)) {
			splx(s);
			return (1);
		}
		sbselqueue(&so->so_snd);
		break;
I 12

	case 0:
		if (so->so_oobmark ||
		    (so->so_state & SS_RCVATMARK)) {
			splx(s);
			return (1);
		}
		sbselqueue(&so->so_rcv);
		break;
E 12
	}
	splx(s);
	return (0);
}

I 5
/*ARGSUSED*/
E 5
D 3
soo_stat(fp, ub)
	struct file *fp;
E 3
I 3
soo_stat(so, ub)
	register struct socket *so;
E 3
	register struct stat *ub;
{
D 3
	register struct socket *so = (struct socket *)fp->f_data;
E 3

I 5
D 8
#ifdef lint
	so = so;
#endif
E 8
E 5
	bzero((caddr_t)ub, sizeof (*ub));
D 8
#ifdef notdef
E 8
	return ((*so->so_proto->pr_usrreq)(so, PRU_SENSE,
	    (struct mbuf *)ub, (struct mbuf *)0, 
	    (struct mbuf *)0));
D 8
#endif
	return (0);
E 8
}

soo_close(fp)
	struct file *fp;
{
D 6
	int error = soclose((struct socket *)fp->f_data);

E 6
I 6
	int error = 0;
D 14
	
E 14
I 14

E 14
	if (fp->f_data)
		error = soclose((struct socket *)fp->f_data);
E 6
	fp->f_data = 0;
	return (error);
I 3
D 5
}

/*ARGSUSED*/
soo_lock(so, pf, how)
	struct socket *so;
	u_char *pf;
	int how;
{

	return (EOPNOTSUPP);
}

/*ARGSUSED*/
soo_unlock(so, flags)
	struct socket *so;
	int flags;
{

	panic("soo_unlock");
E 5
E 3
}
E 1
