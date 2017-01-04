h16440
s 00001/00001/00193
d D 7.1 86/06/05 00:06:30 mckusick 9 8
c 4.3BSD release version
e
s 00001/00001/00193
d D 6.8 86/02/23 23:10:06 karels 8 7
c lint
e
s 00008/00048/00186
d D 6.7 86/02/19 17:37:19 karels 7 6
c lint; remove debug
e
s 00004/00001/00230
d D 6.6 85/09/04 13:32:03 bloom 6 5
c lint cleanup
e
s 00007/00001/00224
d D 6.5 85/06/08 14:41:01 mckusick 5 4
c Add copyright
e
s 00007/00003/00218
d D 6.4 85/03/18 15:22:13 karels 4 3
c use separate global for open flag; print logged errors if log isn't 
c open yet; tprintf goes to log also
e
s 00008/00008/00213
d D 6.3 84/08/29 20:20:52 bloom 3 2
c Change to includes.  no more ../h
e
s 00033/00013/00188
d D 6.2 84/07/17 16:19:17 ralph 2 1
c first working version.
e
s 00201/00000/00000
d D 6.1 84/07/16 16:37:55 ralph 1 0
c date and time created 84/07/16 16:37:55 by ralph
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Error log buffer for kernel printf's.
 */

D 3
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/ioctl.h"
#include "../h/msgbuf.h"
#include "../h/file.h"
#include "../h/errno.h"
E 3
I 3
#include "param.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "ioctl.h"
#include "msgbuf.h"
#include "file.h"
#include "errno.h"
E 3

#define LOG_RDPRI	(PZERO + 1)

D 4
#define LOG_OPEN	0x01
E 4
#define LOG_NBIO	0x02
#define LOG_ASYNC	0x04
#define LOG_RDWAIT	0x08

struct logsoftc {
	int	sc_state;		/* see above for possibilities */
	struct	proc *sc_selp;		/* process waiting on select call */
	int	sc_pgrp;		/* process group for async I/O */
} logsoftc;

I 4
int	log_open;			/* also used in log() */

E 4
I 2
D 7
#ifdef LOGDEBUG
/*VARARGS1*/
xprintf(fmt, x1)
	char *fmt;
	unsigned x1;
{

	prf(fmt, &x1, 1, (struct tty *)0);
}
#endif

E 7
I 6
/*ARGSUSED*/
E 6
E 2
logopen(dev)
	dev_t dev;
{

D 7
#ifdef LOGDEBUG
D 2
	printf("logopen: dev=0x%x\n", dev);
E 2
I 2
	xprintf("logopen: dev=0x%x\n", dev);
E 2
#endif
E 7
D 4
	if (logsoftc.sc_state & LOG_OPEN)
E 4
I 4
	if (log_open)
E 4
D 2
		return(EBUSY);
E 2
I 2
		return (EBUSY);
E 2
D 4
	logsoftc.sc_state |= LOG_OPEN;
E 4
I 4
	log_open = 1;
E 4
	logsoftc.sc_selp = 0;
	logsoftc.sc_pgrp = u.u_procp->p_pgrp;
	/*
	 * Potential race here with putchar() but since putchar should be
	 * called by autoconf, msg_magic should be initialized by the time
	 * we get here.
	 */
	if (msgbuf.msg_magic != MSG_MAGIC) {
		register int i;

		msgbuf.msg_magic = MSG_MAGIC;
		msgbuf.msg_bufx = msgbuf.msg_bufr = 0;
		for (i=0; i < MSG_BSIZE; i++)
			msgbuf.msg_bufc[i] = 0;
	}
D 2
	return(0);
E 2
I 2
D 7
#ifdef LOGDEBUG
	xprintf("logopen: bufx=%d, bufr=%d\n", msgbuf.msg_bufx, msgbuf.msg_bufr);
#endif
E 7
	return (0);
E 2
}

I 6
/*ARGSUSED*/
E 6
logclose(dev, flag)
	dev_t dev;
{
I 4
	log_open = 0;
E 4
	logsoftc.sc_state = 0;
	logsoftc.sc_selp = 0;
	logsoftc.sc_pgrp = 0;
D 7
#ifdef LOGDEBUG
D 2
	printf("logclose: dev=0x%x\n", dev);
E 2
I 2
	xprintf("logclose: dev=0x%x\n", dev);
E 2
#endif
E 7
}

I 6
/*ARGSUSED*/
E 6
logread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register long l;
D 7
	register u_int c;
E 7
D 6
	register struct iovec *iov;
E 6
	register int s;
	int error = 0;

D 7
#ifdef LOGDEBUG
D 2
	printf("logread: dev=0x%x\n", dev);
E 2
I 2
	xprintf("logread: dev=0x%x\n", dev);
E 2
#endif

E 7
	s = splhigh();
	while (msgbuf.msg_bufr == msgbuf.msg_bufx) {
		if (logsoftc.sc_state & LOG_NBIO) {
			splx(s);
D 2
			return(EWOULDBLOCK);
E 2
I 2
			return (EWOULDBLOCK);
E 2
		}
		logsoftc.sc_state |= LOG_RDWAIT;
		sleep((caddr_t)&msgbuf, LOG_RDPRI);
	}
	splx(s);
	logsoftc.sc_state &= ~LOG_RDWAIT;

	while (uio->uio_resid > 0) {
		l = msgbuf.msg_bufx - msgbuf.msg_bufr;
		if (l < 0)
			l = MSG_BSIZE - msgbuf.msg_bufr;
D 7
		c = min((u_int) l, (u_int)uio->uio_resid);
I 2
#ifdef LOGDEBUG
		xprintf("logread: bufx=%d, bufr=%d, l=%d, c=%d\n",
			msgbuf.msg_bufx, msgbuf.msg_bufr, l, c);
#endif
		if (c <= 0)
E 7
I 7
D 8
		l = min(l, uio->uio_resid);
E 8
I 8
		l = MIN(l, uio->uio_resid);
E 8
		if (l == 0)
E 7
			break;
E 2
		error = uiomove((caddr_t)&msgbuf.msg_bufc[msgbuf.msg_bufr],
D 7
			(int)c, UIO_READ, uio);
E 7
I 7
			(int)l, UIO_READ, uio);
E 7
		if (error)
			break;
D 7
		msgbuf.msg_bufr += c;
E 7
I 7
		msgbuf.msg_bufr += l;
E 7
		if (msgbuf.msg_bufr < 0 || msgbuf.msg_bufr >= MSG_BSIZE)
			msgbuf.msg_bufr = 0;
	}
D 2
	return(error);
E 2
I 2
	return (error);
E 2
}

I 6
/*ARGSUSED*/
E 6
logselect(dev, rw)
	dev_t dev;
	int rw;
{
	int s = splhigh();

	switch (rw) {

	case FREAD:
D 7
		if (msgbuf.msg_bufr != msgbuf.msg_bufx)
			goto win;
#ifdef LOGDEBUG
		if (logsoftc.sc_selp)
D 2
			printf("logselect: collision\n");
E 2
I 2
			xprintf("logselect: collision\n");
E 2
#endif
E 7
I 7
		if (msgbuf.msg_bufr != msgbuf.msg_bufx) {
			splx(s);
			return (1);
		}
E 7
		logsoftc.sc_selp = u.u_procp;
		break;
D 7

	case FWRITE:
#ifdef LOGDEBUG
D 2
		printf("logselect: FWRITE\n");
E 2
I 2
		xprintf("logselect: FWRITE\n");
E 2
#endif
		break;
E 7
	}
	splx(s);
D 2
	return(0);
E 2
I 2
	return (0);
E 2
D 7
win:
	splx(s);
D 2
	return(1);
E 2
I 2
	return (1);
E 7
E 2
}

logwakeup()
{

I 4
	if (!log_open)
		return;
E 4
	if (logsoftc.sc_selp) {
		selwakeup(logsoftc.sc_selp, 0);
		logsoftc.sc_selp = 0;
	}
	if (logsoftc.sc_state & LOG_ASYNC)
		gsignal(logsoftc.sc_pgrp, SIGIO); 
	if (logsoftc.sc_state & LOG_RDWAIT) {
		wakeup((caddr_t)&msgbuf);
		logsoftc.sc_state &= ~LOG_RDWAIT;
	}
}

/*ARGSUSED*/
logioctl(com, data, flag)
	caddr_t data;
{
	long l;
	int s;

	switch (com) {

	/* return number of characters immediately available */
	case FIONREAD:
		s = splhigh();
		l = msgbuf.msg_bufx - msgbuf.msg_bufr;
		splx(s);
		if (l < 0)
			l += MSG_BSIZE;
		*(off_t *)data = l;
		break;

	case FIONBIO:
		if (*(int *)data)
			logsoftc.sc_state |= LOG_NBIO;
		else
			logsoftc.sc_state &= ~LOG_NBIO;
		break;

	case FIOASYNC:
		if (*(int *)data)
			logsoftc.sc_state |= LOG_ASYNC;
		else
			logsoftc.sc_state &= ~LOG_ASYNC;
		break;

	case TIOCSPGRP:
		logsoftc.sc_pgrp = *(int *)data;
		break;

	case TIOCGPGRP:
		*(int *)data = logsoftc.sc_pgrp;
		break;

	default:
D 2
		return(-1);
E 2
I 2
		return (-1);
E 2
	}
D 2
	return(0);
E 2
I 2
	return (0);
E 2
}
E 1
