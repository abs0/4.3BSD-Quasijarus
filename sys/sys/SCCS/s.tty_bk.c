h47027
s 00000/00005/00159
d D 7.2 87/07/27 16:36:31 mckusick 14 13
c delete unneeded header files
e
s 00001/00001/00163
d D 7.1 86/06/05 00:09:40 mckusick 13 12
c 4.3BSD release version
e
s 00007/00001/00157
d D 6.3 85/06/08 14:46:24 mckusick 12 11
c Add copyright
e
s 00012/00012/00146
d D 6.2 84/08/29 20:22:58 bloom 11 10
c Change to includes.  no more ../h
e
s 00000/00000/00158
d D 6.1 83/07/29 06:39:18 sam 10 9
c 4.2 distribution
e
s 00001/00001/00157
d D 4.9 83/05/27 12:48:36 sam 9 8
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00000/00157
d D 4.8 82/12/05 22:01:06 sam 8 7
c include ioctl.h separate from tty.h
e
s 00001/00001/00156
d D 4.7 82/10/17 14:05:37 root 7 6
c fix lint
e
s 00008/00012/00149
d D 4.6 82/10/17 11:33:19 root 6 5
c open returns errors
e
s 00004/00004/00157
d D 4.5 82/10/13 22:08:56 root 5 4
c return errors from ioctl routines and internal ldisc routines
e
s 00001/00001/00160
d D 4.4 82/08/22 21:16:37 root 4 3
c fully uio()'d
e
s 00005/00010/00156
d D 4.3 82/08/13 00:14:40 root 3 2
c changes for char dev uio'ing
e
s 00005/00005/00161
d D 4.2 82/08/01 19:24:16 sam 2 1
c new ioctl's
e
s 00166/00000/00000
d D 4.1 82/07/13 18:30:29 root 1 0
c date and time created 82/07/13 18:30:29 by root
e
u
U
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12

#include "bk.h"

#if NBK > 0
D 11
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
I 8
#include "../h/ioctl.h"
E 8
#include "../h/tty.h"
#include "../h/proc.h"
#include "../h/inode.h"
#include "../h/file.h"
#include "../h/conf.h"
#include "../h/buf.h"
I 3
#include "../h/uio.h"
E 11
I 11
#include "param.h"
D 14
#include "systm.h"
E 14
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "tty.h"
D 14
#include "proc.h"
#include "inode.h"
E 14
#include "file.h"
D 14
#include "conf.h"
E 14
#include "buf.h"
D 14
#include "uio.h"
E 14
E 11
E 3

/*
 * Line discipline for Berkeley network.
 *
 * This supplies single lines to a user level program
 * with a minimum of fuss.  Lines are newline terminated.
 *
 * This discipline requires that tty device drivers call
 * the line specific l_ioctl routine from their ioctl routines,
 * assigning the result to cmd so that we can refuse most tty specific
 * ioctls which are unsafe because we have ambushed the
 * teletype input queues, overlaying them with other information.
 */

/*
 * Open as networked discipline.  Called when discipline changed
 * with ioctl, this assigns a buffer to the line for input, and
 * changing the interpretation of the information in the tty structure.
 */
/*ARGSUSED*/
bkopen(dev, tp)
D 2
dev_t dev;
register struct tty *tp;
E 2
I 2
	dev_t dev;
	register struct tty *tp;
E 2
{
	register struct buf *bp;

D 6
	if (u.u_error)
		return;		/* paranoia */
	if (tp->t_line == NETLDISC) {
		u.u_error = EBUSY;		/* sometimes the network */
		return;				/* ... opens /dev/tty */
	}
E 6
I 6
	if (tp->t_line == NETLDISC)
		return (EBUSY);	/* sometimes the network opens /dev/tty */
E 6
	bp = geteblk(1024);
D 9
	flushtty(tp, FREAD|FWRITE);
E 9
I 9
	ttyflush(tp, FREAD|FWRITE);
E 9
	tp->t_bufp = bp;
	tp->t_cp = (char *)bp->b_un.b_addr;
	tp->t_inbuf = 0;
	tp->t_rec = 0;
I 6
	return (0);
E 6
}

/*
 * Break down... called when discipline changed or from device
 * close routine.
 */
bkclose(tp)
D 6
register struct tty *tp;
E 6
I 6
	register struct tty *tp;
E 6
{
D 6
	register s;
E 6
I 6
	register int s;
E 6

	s = spl5();
	wakeup((caddr_t)&tp->t_rawq);
	if (tp->t_bufp) {
		brelse(tp->t_bufp);
		tp->t_bufp = 0;
	} else
		printf("bkclose: no buf\n");
	tp->t_cp = 0;
	tp->t_inbuf = 0;
	tp->t_rec = 0;
	tp->t_line = 0;		/* paranoid: avoid races */
	splx(s);
}

/*
 * Read from a network line.
 * Characters have been buffered in a system buffer and are
 * now dumped back to the user in one fell swoop, and with a
 * minimum of fuss.  Note that no input is accepted when a record
 * is waiting.  Our clearing tp->t_rec here allows further input
 * to accumulate.
 */
D 3
bkread(tp)
register struct tty *tp;
E 3
I 3
bkread(tp, uio)
	register struct tty *tp;
	struct uio *uio;
E 3
{
D 5
	register int i;
	register s;
E 5
I 5
D 7
	register int i, s;
E 7
I 7
	register int s;
E 7
	int error;
E 5

	if ((tp->t_state&TS_CARR_ON)==0)
		return (-1);
	s = spl5();
	while (tp->t_rec == 0 && tp->t_line == NETLDISC)
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
	splx(s);
	if (tp->t_line != NETLDISC)
		return (-1);
D 3
	i = MIN(tp->t_inbuf, (int)u.u_count);
	if (copyout(tp->t_bufp->b_un.b_addr, u.u_base, (unsigned)i)) {
		u.u_error = EFAULT;
		return (-1);
	}
	u.u_count -= i;
	u.u_base += i;
	u.u_offset += i;
E 3
I 3
D 4
	u.u_error = copyuout(uio, tp->t_bufp->b_un.b_addr, tp->t_inbuf);
E 4
I 4
D 5
	u.u_error = uiomove(tp->t_bufp->b_un.b_addr, tp->t_inbuf, UIO_READ, uio);
E 5
I 5
	error = uiomove(tp->t_bufp->b_un.b_addr, tp->t_inbuf, UIO_READ, uio);
E 5
E 4
E 3
	tp->t_cp = (char *)tp->t_bufp->b_un.b_addr;
	tp->t_inbuf = 0;
	tp->t_rec = 0;
D 5
	return (0);
E 5
I 5
	return (error);
E 5
}

/*
 * Low level character input routine.
 * Stuff the character in the buffer, and wake up the top
 * half after setting t_rec if this completes the record
 * or if the buffer is (ick!) full.
 *
 * Thisis where the formatting should get done to allow
 * 8 character data paths through escapes.
 *
 * This rutine should be expanded in-line in the receiver
 * interrupt routine of the dh-11 to make it run as fast as possible.
 */
bkinput(c, tp)
register c;
register struct tty *tp;
{

	if (tp->t_rec)
		return;
	*tp->t_cp++ = c;
	if (++tp->t_inbuf == 1024 || c == '\n') {
		tp->t_rec = 1;
		wakeup((caddr_t)&tp->t_rawq);
	}
}

/*
 * This routine is called whenever a ioctl is about to be performed
 * and gets a chance to reject the ioctl.  We reject all teletype
 * oriented ioctl's except those which set the discipline, and
 * those which get parameters (gtty and get special characters).
 */
/*ARGSUSED*/
D 2
bkioctl(tp, cmd, addr)
struct tty *tp;
caddr_t addr;
E 2
I 2
bkioctl(tp, cmd, data, flag)
	struct tty *tp;
	caddr_t data;
E 2
{

	if ((cmd>>8) != 't')
D 6
		return (cmd);
E 6
I 6
		return (-1);
E 6
	switch (cmd) {

	case TIOCSETD:
	case TIOCGETD:
	case TIOCGETP:
	case TIOCGETC:
D 6
		return (cmd);
E 6
I 6
		return (-1);
E 6
	}
D 6
	u.u_error = ENOTTY;
	return (0);
E 6
I 6
	return (ENOTTY);
E 6
}
#endif
E 1
