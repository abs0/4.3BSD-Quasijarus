h20093
s 00001/00001/00571
d D 7.2 87/10/03 11:05:12 karels 61 60
c clear carrier when master closes (even if LMDMBUF)
e
s 00001/00001/00571
d D 7.1 86/06/05 00:10:02 mckusick 60 59
c 4.3BSD release version
e
s 00001/00001/00571
d D 6.21 86/05/19 16:32:52 karels 59 58
c use UIOCCMD, as long as it's defined now
e
s 00002/00002/00570
d D 6.20 86/02/23 23:10:57 karels 58 57
c lint
e
s 00001/00001/00571
d D 6.19 86/02/19 17:46:15 karels 57 56
c lint
e
s 00019/00011/00553
d D 6.18 86/01/22 18:42:51 karels 56 54
c fixes from sun (sort of): select for write on ptc blocks
c if not at least minimal space (same as ptcwrite); fix ptcwrite test
c of canq.c_cc; cleanup spl's in ptcselect; rm unused
e
s 00019/00011/00553
d R 6.18 86/01/22 18:31:34 karels 55 54
c fixes from sun (sort of): select for write on ptc blocks
c if not at least minimal space (same as ptcwrite); fix ptcwrite test
c of canq.c_cc; cleanup spl's in ptcselect; rm unused
e
s 00001/00001/00563
d D 6.17 85/11/14 13:09:19 karels 54 53
c typo
e
s 00011/00002/00553
d D 6.16 85/11/08 19:12:26 karels 53 51
c allow select on exceptional to check control operations
e
s 00011/00002/00553
d R 6.16 85/11/08 19:02:46 karels 52 51
c select for exceptional cond. on ptc gets special operations
e
s 00021/00012/00534
d D 6.15 85/11/04 18:07:54 karels 51 50
c now using modem control entry in linesw; don't let pty's use
c nonstandard disciplines (we depend on the queue format)
e
s 00002/00000/00544
d D 6.14 85/09/04 09:46:24 bloom 50 49
c call line discipline close routine
e
s 00034/00023/00510
d D 6.13 85/06/21 17:07:21 bloom 49 48
c fix problems with NBIO and REMOTE in ptcwrite
e
s 00007/00001/00526
d D 6.12 85/06/08 14:46:58 mckusick 48 47
c Add copyright
e
s 00001/00002/00526
d D 6.11 85/06/07 17:35:06 karels 47 46
c what the hell was Edward up to?
e
s 00183/00125/00345
d D 6.10 85/04/17 17:20:14 bloom 46 45
c Performance rework by edward and add user ioctl
e
s 00002/00001/00468
d D 6.9 85/01/31 18:41:59 kre 45 44
c xon/xoff flow control should be off in raw mode.
c from net.bugs.4bsd newsitem by sun!gnu
e
s 00001/00001/00468
d D 6.8 84/12/20 14:56:05 karels 44 43
c missing parens
e
s 00001/00001/00468
d D 6.7 84/09/10 18:16:23 mckusick 43 42
c security fix from George Goble
e
s 00011/00011/00458
d D 6.6 84/08/29 20:23:06 bloom 42 41
c Change to includes.  no more ../h
e
s 00017/00006/00452
d D 6.5 84/07/29 18:40:29 sam 41 40
c bug fixes from mcvax!jim for slave side closing while master 
c side is in a read; fixes for sending EOF from dave rosenthal; performance 
c improvement from toronto
e
s 00002/00002/00456
d D 6.4 84/02/15 20:51:15 karels 40 39
c t_delct unused; use t_canq.c_cc instead
e
s 00004/00002/00454
d D 6.3 83/10/01 23:04:40 karels 39 37
c no more SIG_HOLD
e
s 00003/00002/00454
d R 6.3 83/10/01 18:09:41 karels 38 37
c no SIG_HOLD
e
s 00002/00001/00454
d D 6.2 83/09/26 08:26:11 karels 37 35
c don't lose input on large write to ptc (from thomas@utah-cs)
e
s 00002/00001/00454
d R 6.2 83/09/25 17:26:41 karels 36 35
c don't overflow doing long writes on ptc (from thomas@utah-cs)
e
s 00000/00000/00455
d D 6.1 83/07/29 06:39:31 sam 35 34
c 4.2 distribution
e
s 00002/00002/00453
d D 4.31 83/05/27 12:48:43 sam 34 33
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00000/00454
d D 4.30 83/05/21 15:39:37 sam 33 32
c kre madness
e
s 00003/00002/00451
d D 4.29 82/12/05 22:01:12 sam 32 31
c include ioctl.h separate from tty.h
e
s 00001/00001/00452
d D 4.28 82/10/17 14:05:43 root 31 30
c fix lint
e
s 00018/00022/00435
d D 4.27 82/10/17 11:33:42 root 30 29
c ioctl/open return values
e
s 00032/00030/00425
d D 4.26 82/10/13 22:09:03 root 29 28
c return errors from ioctl routines and internal ldisc routines
e
s 00001/00000/00454
d D 4.25 82/09/12 02:59:28 root 28 27
c include kernel.h for lbolt
e
s 00046/00018/00408
d D 4.24 82/08/22 20:42:11 root 27 26
c uioing
e
s 00019/00030/00407
d D 4.23 82/08/01 19:21:56 sam 26 25
c new ioctl's
e
s 00002/00000/00435
d D 4.22 82/07/21 20:22:39 sam 25 24
c make robert happier (still crude though)
e
s 00001/00000/00434
d D 4.21 82/03/23 15:52:54 wnj 24 23
c call ttyclose
e
s 00002/00002/00432
d D 4.20 82/03/15 17:08:42 root 23 22
c NPTY to 32
e
s 00007/00007/00427
d D 4.19 82/03/13 12:50:42 sam 22 21
c lint
e
s 00022/00004/00412
d D 4.18 82/03/11 23:43:55 wnj 21 20
c for remote ^S/^Q
e
s 00072/00017/00344
d D 4.17 82/02/18 13:20:20 wnj 20 19
c TIOCREMOTE for EMACS sake
e
s 00014/00004/00347
d D 4.16 82/01/19 01:59:27 wnj 19 18
c finish pt_send (send start/stop)
e
s 00022/00006/00329
d D 4.15 82/01/17 13:36:40 wnj 18 17
c fix but in read select
e
s 00066/00027/00269
d D 4.14 82/01/17 04:01:39 wnj 17 16
c first working version
e
s 00025/00003/00271
d D 4.13 82/01/15 16:40:24 wnj 16 15
c add nbio stuff
e
s 00078/00034/00196
d D 4.12 82/01/14 17:05:37 wnj 15 14
c early non-blocking stuff
e
s 00008/00006/00222
d D 4.11 82/01/13 10:57:01 root 14 13
c minor fixes
e
s 00001/00002/00227
d D 4.10 81/11/18 15:49:48 wnj 13 12
c lint
e
s 00087/00090/00142
d D 4.9 81/10/11 11:48:10 wnj 12 11
c first boot with select()
e
s 00001/00001/00231
d D 4.8 81/08/14 11:04:55 ecc 11 10
c allow new tty disc over ptys (rob gurwitz)
e
s 00001/00001/00231
d D 4.7 81/03/11 18:40:20 wnj 10 9
c mx1: cleanup; pty: fix #ifdef
e
s 00001/00001/00231
d D 4.6 81/03/09 01:53:57 wnj 9 8
c %G% -> %E%
e
s 00026/00025/00206
d D 4.5 81/02/15 12:13:11 wnj 8 7
c flushtty second arg added (per lint)
e
s 00004/00003/00227
d D 4.4 81/01/29 17:04:56 toy 7 6
c ditto
e
s 00004/00000/00226
d D 4.3 81/01/29 17:03:18 toy 6 5
c Added #if WANTPTY
e
s 00000/00004/00226
d D 4.2 81/01/28 11:41:27 wnj 5 4
c remove names
e
s 00000/00000/00230
d D 4.1 81/01/26 22:16:49 toy 4 3
c Update SCCS id to be consistent with 4bsd
e
s 00002/00001/00228
d D 1.3 81/01/26 22:13:26 toy 3 2
c SCCS
e
s 00002/00000/00227
d D 1.2 81/01/26 22:11:48 toy 2 1
c SCCS mod
e
s 00227/00000/00000
d D 1.1 81/01/26 22:10:07 toy 1 0
c date and time created 81/01/26 22:10:07 by toy
e
u
U
f b 
t
T
I 1
D 5
#
E 5
I 2
D 3
/*	%W%	%I%	%G%	*/
E 3
I 3
D 9
/*	%M%	%I%	%G%	*/
E 9
I 9
D 48
/*	%M%	%I%	%E%	*/
E 48
I 48
/*
D 60
 * Copyright (c) 1982 Regents of the University of California.
E 60
I 60
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 60
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 48
E 9

E 3
E 2
/*
 * Pseudo-teletype Driver
 * (Actually two drivers, requiring two entries in 'cdevsw')
D 5
 *
 * Overhauled, and ported to VAX/VMUNIX (V7) Bruce Borden, July 80
I 2
 * Modified and integrated into 4bsd by Kipp Hickman and Michael Toy
E 5
E 2
 */
I 7
#include "pty.h"

D 10
#if WANTPTY > 0
E 10
I 10
#if NPTY > 0
E 10
D 15

E 15
E 7
D 42
#include "../h/param.h"
#include "../h/systm.h"
I 32
#include "../h/ioctl.h"
E 32
#include "../h/tty.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/conf.h"
D 27
#include "../h/buf.h"
E 27
I 8
#include "../h/file.h"
I 12
#include "../h/proc.h"
I 27
#include "../h/uio.h"
I 28
#include "../h/kernel.h"
E 42
I 42
#include "param.h"
#include "systm.h"
#include "ioctl.h"
#include "tty.h"
#include "dir.h"
#include "user.h"
#include "conf.h"
#include "file.h"
#include "proc.h"
#include "uio.h"
#include "kernel.h"
E 42
E 28
E 27
E 12
E 8
I 6
D 7
#include "../pty.h"
E 6

I 6
#if WANTPTY > 0
E 7
D 15

E 15
E 6
D 8
#define NPTY 16                 /* Number of pseudo-teletypes */
#define BUFSIZ 100              /* Chunk size iomoved from user */
E 8
I 8
D 12
#define NPTY 16			/* Number of pseudo-teletypes */
E 12
I 12
D 23
#undef	NPTY
E 23
I 15

I 25
#if NPTY == 1
E 25
E 15
D 23
#define NPTY 16
E 23
I 23
D 46
#undef	NPTY
E 46
I 46
#undef NPTY
E 46
#define	NPTY	32		/* crude XXX */
I 25
#endif
E 25
E 23

E 12
D 41
#define BUFSIZ 100		/* Chunk size iomoved from user */
E 41
I 41
#define BUFSIZ 100		/* Chunk size iomoved to/from user */
E 41
E 8
D 12
#define ALLDELAYS (NLDELAY|TBDELAY|XTABS|CRDELAY|VTDELAY)
E 12
I 12

E 12
/*
D 12
 * A pseudo-teletype is a special device which is not unlike a pipe.
 * It is used to communicate between two processes.  However, it allows
 * one to simulate a teletype, including mode setting, interrupt, and
D 8
 * multiple end of files (all not possible on a pipe).  There are
E 8
I 8
 * multiple end of files (all not possible on a pipe).	There are
E 8
 * really two drivers here.  One is the device which looks like a TTY
 * and can be thought of as the slave device, and hence its routines
D 8
 * are prefixed with 'pts' (PTY Slave).  The other driver can be
E 8
I 8
 * are prefixed with 'pts' (PTY Slave).	 The other driver can be
E 8
 * thought of as the controlling device, and its routines are prefixed
 * by 'ptc' (PTY Controller).  To type on the simulated keyboard of the
 * PTY, one does a 'write' to the controlling device.  To get the
 * simulated printout from the PTY, one does a 'read' on the controlling
 * device.  Normally, the controlling device is called 'ptyx' and the
 * slave device is called 'ttyx' (to make programs like 'who' happy).
E 12
I 12
D 46
 * pts == /dev/tty[pP]?
 * ptc == /dev/ptp[pP]?
E 46
I 46
 * pts == /dev/tty[pqrs]?
 * ptc == /dev/pty[pqrs]?
E 46
E 12
 */
I 12
struct	tty pt_tty[NPTY];
struct	pt_ioctl {
D 17
	int	pti_flags;
	struct	clist pti_ioctl, pti_ioans;
	int	pti_gensym;
D 15
	struct	proc *pti_selr;
E 15
I 15
	struct	proc *pti_selr, *pti_selw;
E 17
I 17
	int	pt_flags;
D 56
	int	pt_gensym;
E 56
	struct	proc *pt_selr, *pt_selw;
D 46
	int	pt_send;
E 46
I 46
	u_char	pt_send;
	u_char	pt_ucntl;
E 46
E 17
E 15
} pt_ioctl[NPTY];
I 46
int	npty = NPTY;		/* for pstat -t */
E 46
E 12

D 8
struct tty pt_tty[NPTY];                /* TTY headers for PTYs */
E 8
I 8
D 12
struct tty pt_tty[NPTY];		/* TTY headers for PTYs */
E 12
I 12
D 17
#define	PTCRCOLL	0x01
I 15
#define	PTCWCOLL	0x02
I 16
#define	PTCNBIO		0x04
E 17
I 17
#define	PF_RCOLL	0x01
#define	PF_WCOLL	0x02
#define	PF_NBIO		0x04
#define	PF_PKT		0x08		/* packet mode */
D 19
#define	PF_FLOWCTL	0x10		/* peers flow control mode */
E 19
I 19
#define	PF_STOPPED	0x10		/* user told stopped */
I 20
#define	PF_REMOTE	0x20		/* remote and flow controlled input */
I 21
#define	PF_NOSTOP	0x40
I 46
#define PF_UCNTL	0x80		/* user control mode */
E 46
E 21
E 20
E 19
E 17
E 16
E 15
E 12
E 8

/*ARGSUSED*/
ptsopen(dev, flag)
D 14
dev_t dev;
E 14
I 14
	dev_t dev;
E 14
D 8
{                                       /* Open for PTY Slave */
E 8
I 8
D 12
{					/* Open for PTY Slave */
E 12
I 12
{
E 12
E 8
	register struct tty *tp;
I 46
	int error;
E 46

I 46
#ifdef lint
	npty = npty;
#endif
E 46
D 12
	if(minor(dev) >= NPTY) {
E 12
I 12
D 30
	if (minor(dev) >= NPTY) {
E 12
		u.u_error = ENXIO;
		return;
	}
E 30
I 30
	if (minor(dev) >= NPTY)
		return (ENXIO);
E 30
	tp = &pt_tty[minor(dev)];
D 12
	if((tp->t_state & ISOPEN) == 0) {
E 12
I 12
D 15
	if ((tp->t_state & ISOPEN) == 0) {
E 15
I 15
	if ((tp->t_state & TS_ISOPEN) == 0) {
E 15
E 12
D 8
		ttychars(tp);           /* Set up default chars */
		tp->t_flags = 0;        /* No features (nor raw mode) */
E 8
I 8
		ttychars(tp);		/* Set up default chars */
I 33
		tp->t_ispeed = tp->t_ospeed = EXTB;
E 33
		tp->t_flags = 0;	/* No features (nor raw mode) */
E 8
D 12
	} else if(tp->t_state&XCLUDE && u.u_uid != 0) {
E 12
I 12
D 15
	} else if (tp->t_state&XCLUDE && u.u_uid != 0) {
E 15
I 15
D 30
	} else if (tp->t_state&TS_XCLUDE && u.u_uid != 0) {
E 15
E 12
		u.u_error = EBUSY;
		return;
	}
E 30
I 30
	} else if (tp->t_state&TS_XCLUDE && u.u_uid != 0)
		return (EBUSY);
E 30
D 8
	if(tp->t_oproc)                 /* Ctrlr still around. */
E 8
I 8
D 12
	if(tp->t_oproc)			/* Ctrlr still around. */
E 12
I 12
	if (tp->t_oproc)			/* Ctrlr still around. */
E 12
E 8
D 15
		tp->t_state |= CARR_ON;
D 12
	while((tp->t_state & CARR_ON) == 0) {
E 12
I 12
	while ((tp->t_state & CARR_ON) == 0) {
E 12
		tp->t_state |= WOPEN;
E 15
I 15
		tp->t_state |= TS_CARR_ON;
	while ((tp->t_state & TS_CARR_ON) == 0) {
		tp->t_state |= TS_WOPEN;
E 15
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
	}
D 30
	(*linesw[tp->t_line].l_open)(dev, tp);
E 30
I 30
D 46
	return ((*linesw[tp->t_line].l_open)(dev, tp));
E 46
I 46
	error = (*linesw[tp->t_line].l_open)(dev, tp);
	ptcwakeup(tp, FREAD|FWRITE);
	return (error);
E 46
E 30
}

ptsclose(dev)
D 14
dev_t dev;
E 14
I 14
	dev_t dev;
E 14
D 8
{                                       /* Close slave part of PTY */
E 8
I 8
D 15
{					/* Close slave part of PTY */
E 15
I 15
{
E 15
E 8
	register struct tty *tp;

	tp = &pt_tty[minor(dev)];
	(*linesw[tp->t_line].l_close)(tp);
I 24
	ttyclose(tp);
I 41
D 46
	ptcwakeup(tp);
E 46
I 46
	ptcwakeup(tp, FREAD|FWRITE);
E 46
E 41
E 24
}

D 27
ptsread(dev)
E 27
I 27
ptsread(dev, uio)
E 27
D 14
dev_t dev;
E 14
I 14
	dev_t dev;
I 27
	struct uio *uio;
E 27
E 14
D 8
{       /* Read from PTY, i.e. from data written by controlling device */
E 8
I 8
D 12
{	/* Read from PTY, i.e. from data written by controlling device */
E 8
	register struct tty    *tp;
E 12
I 12
{
D 20
	register struct tty *tp;
I 15
	register struct pt_ioctl *pti;
E 20
I 20
	register struct tty *tp = &pt_tty[minor(dev)];
	register struct pt_ioctl *pti = &pt_ioctl[minor(dev)];
I 29
	int error = 0;
E 29
E 20
E 15
E 12

D 20
	tp = &pt_tty[minor(dev)];
D 12
	if(tp->t_oproc) {
E 12
I 12
	if (tp->t_oproc) {
E 12
		(*linesw[tp->t_line].l_read)(tp);
D 12
				/* Wakeup other half if sleeping */
E 12
		wakeup((caddr_t)&tp->t_rawq.c_cf);
I 15
		if (tp->t_rawq.c_cc < TTYHOG/2 &&
D 17
		    (pti = &pt_ioctl[minor(tp->t_dev)])->pti_selw) {
			selwakeup(pti->pti_selw, pti->pti_flags & PTCWCOLL);
			pti->pti_selw = 0;
			pti->pti_flags &= ~PTCWCOLL;
E 17
I 17
		    (pti = &pt_ioctl[minor(tp->t_dev)])->pt_selw) {
			selwakeup(pti->pt_selw, pti->pt_flags & PF_WCOLL);
			pti->pt_selw = 0;
			pti->pt_flags &= ~PF_WCOLL;
E 20
I 20
again:
	if (pti->pt_flags & PF_REMOTE) {
		while (tp == u.u_ttyp && u.u_procp->p_pgrp != tp->t_pgrp) {
D 39
			if (u.u_signal[SIGTTIN] == SIG_IGN ||
			    u.u_signal[SIGTTIN] == SIG_HOLD ||
E 39
I 39
D 46
#define bit(a) (1<<(a-1))
			if ((u.u_procp->p_sigignore & bit(SIGTTIN)) ||
			    (u.u_procp->p_sigmask & bit(SIGTTIN)) ||
E 46
I 46
			if ((u.u_procp->p_sigignore & sigmask(SIGTTIN)) ||
			    (u.u_procp->p_sigmask & sigmask(SIGTTIN)) ||
E 46
E 39
D 51
	/*
			    (u.u_procp->p_flag&SDETACH) ||
	*/
E 51
			    u.u_procp->p_flag&SVFORK)
D 29
				return;
E 29
I 29
				return (EIO);
E 29
			gsignal(u.u_procp->p_pgrp, SIGTTIN);
			sleep((caddr_t)&lbolt, TTIPRI);
E 20
E 17
		}
I 39
D 46
#undef	bit
E 39
I 20
		if (tp->t_rawq.c_cc == 0) {
E 46
I 46
		if (tp->t_canq.c_cc == 0) {
E 46
D 29
			if (tp->t_state & TS_NBIO) {
				u.u_error = EWOULDBLOCK;
				return;
			}
E 29
I 29
			if (tp->t_state & TS_NBIO)
				return (EWOULDBLOCK);
E 29
D 46
			sleep((caddr_t)&tp->t_rawq, TTIPRI);
E 46
I 46
			sleep((caddr_t)&tp->t_canq, TTIPRI);
E 46
			goto again;
		}
D 27
		while (tp->t_rawq.c_cc > 1 && passc(getc(&tp->t_rawq)) >= 0)
			;
E 27
I 27
D 46
		while (tp->t_rawq.c_cc > 1 && uio->uio_resid > 0)
			if (ureadc(getc(&tp->t_rawq), uio) < 0) {
E 46
I 46
		while (tp->t_canq.c_cc > 1 && uio->uio_resid > 0)
			if (ureadc(getc(&tp->t_canq), uio) < 0) {
E 46
D 29
				u.u_error = EFAULT;
E 29
I 29
				error = EFAULT;
E 29
				break;
			}
E 27
D 46
		if (tp->t_rawq.c_cc == 1)
			(void) getc(&tp->t_rawq);
		if (tp->t_rawq.c_cc)
E 46
I 46
		if (tp->t_canq.c_cc == 1)
			(void) getc(&tp->t_canq);
		if (tp->t_canq.c_cc)
E 46
D 29
			return;
E 29
I 29
			return (error);
E 29
	} else
		if (tp->t_oproc)
D 27
			(*linesw[tp->t_line].l_read)(tp);
E 27
I 27
D 29
			(*linesw[tp->t_line].l_read)(tp, uio);
E 29
I 29
			error = (*linesw[tp->t_line].l_read)(tp, uio);
E 29
E 27
D 46
	wakeup((caddr_t)&tp->t_rawq.c_cf);
	if (pti->pt_selw) {
		selwakeup(pti->pt_selw, pti->pt_flags & PF_WCOLL);
		pti->pt_selw = 0;
		pti->pt_flags &= ~PF_WCOLL;
E 20
E 15
	}
E 46
I 46
	ptcwakeup(tp, FWRITE);
E 46
I 29
	return (error);
E 29
}

I 15
/*
 * Write to pseudo-tty.
 * Wakeups of controlling tty will happen
 * indirectly, when tty driver calls ptsstart.
 */
E 15
D 27
ptswrite(dev)
E 27
I 27
ptswrite(dev, uio)
E 27
D 14
dev_t dev;
E 14
I 14
	dev_t dev;
I 27
	struct uio *uio;
E 27
E 14
D 8
{                       /* Write on PTY, i.e. to be read from
E 8
I 8
D 12
{			/* Write on PTY, i.e. to be read from
E 8
			   controlling device */
E 12
I 12
{
E 12
	register struct tty *tp;

	tp = &pt_tty[minor(dev)];
D 12
			/* Wait for controlling device to be opened */
	if(tp->t_oproc)
E 12
I 12
D 29
	if (tp->t_oproc)
E 12
D 27
		(*linesw[tp->t_line].l_write)(tp);
E 27
I 27
		(*linesw[tp->t_line].l_write)(tp, uio);
E 29
I 29
	if (tp->t_oproc == 0)
		return (EIO);
	return ((*linesw[tp->t_line].l_write)(tp, uio));
E 29
E 27
}

I 15
/*
 * Start output on pseudo-tty.
 * Wake up process selecting or sleeping for input from controlling tty.
 */
E 15
ptsstart(tp)
D 12
struct tty *tp;
D 8
{                       /* Called by 'ttstart' to output a character.
E 8
I 8
{			/* Called by 'ttstart' to output a character.
E 8
			   Merely wakes up controlling half, which
			   does actual work */
	if(tp->t_state & TTSTOP)
E 12
I 12
	struct tty *tp;
{
I 19
	register struct pt_ioctl *pti = &pt_ioctl[minor(tp->t_dev)];
E 19
D 18
	struct pt_ioctl *pti = &pt_ioctl[minor(tp->t_dev)];
E 18

D 15
	if (tp->t_state & TTSTOP)
E 15
I 15
	if (tp->t_state & TS_TTSTOP)
E 15
E 12
		return;
I 19
	if (pti->pt_flags & PF_STOPPED) {
		pti->pt_flags &= ~PF_STOPPED;
		pti->pt_send = TIOCPKT_START;
	}
E 19
I 18
D 46
	ptcwakeup(tp);
E 46
I 46
	ptcwakeup(tp, FREAD);
E 46
}

D 46
ptcwakeup(tp)
E 46
I 46
ptcwakeup(tp, flag)
E 46
	struct tty *tp;
{
	struct pt_ioctl *pti = &pt_ioctl[minor(tp->t_dev)];

E 18
I 12
D 17
	if (pti->pti_selr) {
		selwakeup(pti->pti_selr, pti->pti_flags & PTCRCOLL);
		pti->pti_selr = 0;
		pti->pti_flags &= ~PTCRCOLL;
E 17
I 17
D 46
	if (pti->pt_selr) {
		selwakeup(pti->pt_selr, pti->pt_flags & PF_RCOLL);
		pti->pt_selr = 0;
		pti->pt_flags &= ~PF_RCOLL;
E 46
I 46
	if (flag & FREAD) {
		if (pti->pt_selr) {
			selwakeup(pti->pt_selr, pti->pt_flags & PF_RCOLL);
			pti->pt_selr = 0;
			pti->pt_flags &= ~PF_RCOLL;
		}
		wakeup((caddr_t)&tp->t_outq.c_cf);
E 46
E 17
	}
E 12
D 46
	wakeup((caddr_t)&tp->t_outq.c_cf);
E 46
I 46
	if (flag & FWRITE) {
		if (pti->pt_selw) {
			selwakeup(pti->pt_selw, pti->pt_flags & PF_WCOLL);
			pti->pt_selw = 0;
			pti->pt_flags &= ~PF_WCOLL;
		}
		wakeup((caddr_t)&tp->t_rawq.c_cf);
	}
E 46
}

/*ARGSUSED*/
ptcopen(dev, flag)
D 12
dev_t dev;
D 8
{                               /* Open for PTY Controller */
E 8
I 8
{				/* Open for PTY Controller */
E 12
I 12
	dev_t dev;
	int flag;
{
E 12
E 8
	register struct tty *tp;
I 17
	struct pt_ioctl *pti;
E 17

D 12
	if(minor(dev) >= NPTY) {
E 12
I 12
D 30
	if (minor(dev) >= NPTY) {
E 12
		u.u_error = ENXIO;
		return;
	}
E 30
I 30
	if (minor(dev) >= NPTY)
		return (ENXIO);
E 30
	tp = &pt_tty[minor(dev)];
D 12
	if(tp->t_oproc) {
E 12
I 12
D 30
	if (tp->t_oproc) {
E 12
		u.u_error = EIO;
		return;
	}
E 30
I 30
	if (tp->t_oproc)
		return (EIO);
E 30
D 8
	tp->t_oproc = ptsstart;         /* Set address of start routine */
E 8
I 8
D 12
	tp->t_oproc = ptsstart;		/* Set address of start routine */
E 8
	tp->t_iproc = 0;
	if(tp->t_state & WOPEN)
E 12
I 12
	tp->t_oproc = ptsstart;
D 15
	if (tp->t_state & WOPEN)
E 15
I 15
D 51
	if (tp->t_state & TS_WOPEN)
E 15
E 12
		wakeup((caddr_t)&tp->t_rawq);
E 51
I 51
	(void)(*linesw[tp->t_line].l_modem)(tp, 1);
E 51
D 15
	tp->t_state |= CARR_ON;
E 15
I 15
D 61
	tp->t_state |= TS_CARR_ON;
E 61
I 17
	pti = &pt_ioctl[minor(dev)];
	pti->pt_flags = 0;
	pti->pt_send = 0;
I 46
	pti->pt_ucntl = 0;
E 46
I 30
	return (0);
E 30
E 17
E 15
}

ptcclose(dev)
D 12
dev_t dev;
D 8
{                                       /* Close controlling part of PTY */
E 8
I 8
{					/* Close controlling part of PTY */
E 12
I 12
	dev_t dev;
{
E 12
E 8
	register struct tty *tp;

	tp = &pt_tty[minor(dev)];
I 50
D 51
	if (tp->t_line)
		(*linesw[tp->t_line].l_close)(tp);
E 50
D 12
	if(tp->t_state & ISOPEN)
E 12
I 12
D 15
	if (tp->t_state & ISOPEN)
E 15
I 15
	if (tp->t_state & TS_ISOPEN)
E 15
E 12
		gsignal(tp->t_pgrp, SIGHUP);
D 8
	tp->t_state &= ~CARR_ON;        /* Virtual carrier is gone */
	flushtty(tp);                   /* Clean things up */
	tp->t_oproc = 0;                /* Mark as closed */
E 8
I 8
D 12
	tp->t_state &= ~CARR_ON;	/* Virtual carrier is gone */
	flushtty(tp, FREAD|FWRITE);		     /* Clean things up */
	tp->t_oproc = 0;		/* Mark as closed */
E 12
I 12
D 15
	tp->t_state &= ~CARR_ON;	/* virtual carrier gone */
E 15
I 15
	tp->t_state &= ~TS_CARR_ON;	/* virtual carrier gone */
E 15
D 34
	flushtty(tp, FREAD|FWRITE);
E 34
I 34
	ttyflush(tp, FREAD|FWRITE);
E 51
I 51
	(void)(*linesw[tp->t_line].l_modem)(tp, 0);
I 61
	tp->t_state &= ~TS_CARR_ON;
E 61
E 51
E 34
	tp->t_oproc = 0;		/* mark closed */
E 12
E 8
}

D 27
ptcread(dev)
E 27
I 27
ptcread(dev, uio)
E 27
D 17
dev_t dev;
E 17
I 17
	dev_t dev;
I 27
	struct uio *uio;
E 27
E 17
D 8
{                                       /* Read from PTY's output buffer */
E 8
I 8
D 12
{					/* Read from PTY's output buffer */
E 12
I 12
{
E 12
E 8
D 29
	register struct tty *tp;
E 29
I 29
	register struct tty *tp = &pt_tty[minor(dev)];
E 29
I 17
D 46
	struct pt_ioctl *pti;
E 46
I 46
	struct pt_ioctl *pti = &pt_ioctl[minor(dev)];
E 46
I 29
D 41
	int error = 0;
E 41
I 41
	char buf[BUFSIZ];
	int error = 0, cc;
E 41
E 29
E 17

D 29
	tp = &pt_tty[minor(dev)];
E 29
D 12
	if((tp->t_state&(CARR_ON|ISOPEN)) == 0)
E 12
I 12
D 15
	if ((tp->t_state&(CARR_ON|ISOPEN)) == 0)
E 15
I 15
D 46
	if ((tp->t_state&(TS_CARR_ON|TS_ISOPEN)) == 0)
E 15
E 12
D 31
		return;
E 31
I 31
		return (EIO);
E 31
I 17
	pti = &pt_ioctl[minor(dev)];
	if (pti->pt_flags & PF_PKT) {
		if (pti->pt_send) {
D 22
			passc(pti->pt_send);
E 22
I 22
D 27
			(void) passc(pti->pt_send);
E 27
I 27
D 29
			(void) ureadc(pti->pt_send, uio);
E 29
I 29
			error = ureadc(pti->pt_send, uio);
			if (error)
				return (error);
E 29
E 27
E 22
			pti->pt_send = 0;
D 29
			return;
E 29
I 29
			return (0);
E 46
I 46
	/*
	 * We want to block until the slave
	 * is open, and there's something to read;
	 * but if we lost the slave or we're NBIO,
	 * then return the appropriate error instead.
	 */
	for (;;) {
		if (tp->t_state&TS_ISOPEN) {
			if (pti->pt_flags&PF_PKT && pti->pt_send) {
D 58
				error = ureadc(pti->pt_send, uio);
E 58
I 58
				error = ureadc((int)pti->pt_send, uio);
E 58
				if (error)
					return (error);
				pti->pt_send = 0;
				return (0);
			}
			if (pti->pt_flags&PF_UCNTL && pti->pt_ucntl) {
D 58
				error = ureadc(pti->pt_ucntl, uio);
E 58
I 58
				error = ureadc((int)pti->pt_ucntl, uio);
E 58
				if (error)
					return (error);
				pti->pt_ucntl = 0;
				return (0);
			}
			if (tp->t_outq.c_cc && (tp->t_state&TS_TTSTOP) == 0)
				break;
E 46
E 29
		}
D 22
		passc(0);
E 22
I 22
D 27
		(void) passc(0);
E 27
I 27
D 29
		(void) ureadc(0, uio);
E 29
I 29
D 46
		error = ureadc(0, uio);
E 29
E 27
E 22
	}
E 17
D 8
	while(tp->t_outq.c_cc == 0 ||   /* Wait for something to arrive */
	      (tp->t_state&TTSTOP))     /* (Woken by ptsstart) */
E 8
I 8
D 12
	while(tp->t_outq.c_cc == 0 ||	/* Wait for something to arrive */
	      (tp->t_state&TTSTOP))	/* (Woken by ptsstart) */
E 12
I 12
D 15
	while (tp->t_outq.c_cc == 0 || (tp->t_state&TTSTOP))
E 15
I 15
D 16
	while (tp->t_outq.c_cc == 0 || (tp->t_state&TS_TTSTOP))
E 16
I 16
	while (tp->t_outq.c_cc == 0 || (tp->t_state&TS_TTSTOP)) {
E 46
I 41
		if ((tp->t_state&TS_CARR_ON) == 0)
			return (EIO);
E 41
D 17
		if (pt_ioctl[minor(dev)].pti_flags&PTCNBIO) {
E 17
I 17
D 29
		if (pti->pt_flags&PF_NBIO) {
E 17
			u.u_error = EWOULDBLOCK;
			return;
		}
E 29
I 29
		if (pti->pt_flags&PF_NBIO)
			return (EWOULDBLOCK);
E 29
E 16
E 15
E 12
E 8
		sleep((caddr_t)&tp->t_outq.c_cf, TTIPRI);
I 16
	}
I 46
	if (pti->pt_flags & (PF_PKT|PF_UCNTL))
		error = ureadc(0, uio);
E 46
E 16
D 12
	while(tp->t_outq.c_cc && passc(getc(&tp->t_outq)) >= 0);
	if(tp->t_outq.c_cc <= TTLOWAT(tp)  && (tp->t_state&ASLEEP)) {
E 12
I 12
D 15
	while (tp->t_outq.c_cc && passc(getc(&tp->t_outq)) >= 0);
	if (tp->t_outq.c_cc <= TTLOWAT(tp)  && (tp->t_state&ASLEEP)) {
E 12
		tp->t_state &= ~ASLEEP;
D 12
		if(tp->t_chan)
			mcstart(tp->t_chan, (caddr_t)&tp->t_outq);
		else
			wakeup((caddr_t)&tp->t_outq);
E 12
I 12
		wakeup((caddr_t)&tp->t_outq);
E 15
I 15
D 27
	while (tp->t_outq.c_cc && passc(getc(&tp->t_outq)) >= 0)
		;
E 27
I 27
D 41
	while (tp->t_outq.c_cc && uio->uio_resid > 0)
		if (ureadc(getc(&tp->t_outq), uio) < 0) {
D 29
			u.u_error = EFAULT;
E 29
I 29
			error = EFAULT;
E 41
I 41
	while (uio->uio_resid > 0 && error == 0) {
		cc = q_to_b(&tp->t_outq, buf, MIN(uio->uio_resid, BUFSIZ));
		if (cc <= 0)
E 41
E 29
			break;
D 41
		}
E 41
I 41
		error = uiomove(buf, cc, UIO_READ, uio);
	}
E 41
E 27
	if (tp->t_outq.c_cc <= TTLOWAT(tp)) {
		if (tp->t_state&TS_ASLEEP) {
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t)&tp->t_outq);
		}
		if (tp->t_wsel) {
			selwakeup(tp->t_wsel, tp->t_state & TS_WCOLL);
			tp->t_wsel = 0;
			tp->t_state &= ~TS_WCOLL;
		}
E 15
E 12
	}
I 29
	return (error);
E 29
}

I 17
ptsstop(tp, flush)
	register struct tty *tp;
	int flush;
{
	struct pt_ioctl *pti = &pt_ioctl[minor(tp->t_dev)];
I 46
	int flag;
E 46

D 19
	if (flush == 0)
		return;
D 18
	pti->pt_send |= TIOCPKT_FLUSH;
	ptsstart(tp);
E 18
I 18
	pti->pt_send |= flush;
E 19
I 19
	/* note: FLUSHREAD and FLUSHWRITE already ok */
	if (flush == 0) {
		flush = TIOCPKT_STOP;
		pti->pt_flags |= PF_STOPPED;
D 46
	} else {
E 46
I 46
	} else
E 46
		pti->pt_flags &= ~PF_STOPPED;
D 46
	}
E 46
D 21
	pti->pt_send = flush;
E 21
I 21
	pti->pt_send |= flush;
E 21
E 19
D 46
	ptcwakeup(tp);
E 46
I 46
	/* change of perspective */
	flag = 0;
	if (flush & FREAD)
		flag |= FWRITE;
	if (flush & FWRITE)
		flag |= FREAD;
D 49
	ptcwakeup(tp, flush);
E 49
I 49
	ptcwakeup(tp, flag);
E 49
E 46
E 18
}

E 17
I 12
D 15
ptcselect(dev)
E 15
I 15
ptcselect(dev, rw)
E 15
	dev_t dev;
I 15
	int rw;
E 15
{
	register struct tty *tp = &pt_tty[minor(dev)];
D 20
	struct pt_ioctl *pti;
E 20
I 20
	struct pt_ioctl *pti = &pt_ioctl[minor(dev)];
E 20
	struct proc *p;
I 18
	int s;
E 18

D 14
	if ((tp->t_state&(CARR_ON|ISOPEN)) == 0)
E 14
I 14
D 15
	if ((tp->t_state&(CARR_ON|ISOPEN)) == 0) {
E 15
I 15
D 46
	if ((tp->t_state&(TS_CARR_ON|TS_ISOPEN)) == 0)
E 46
I 46
	if ((tp->t_state&TS_CARR_ON) == 0)
E 46
E 15
E 14
		return (1);
I 18
D 56
	s = spl5();
E 56
E 18
I 15
	switch (rw) {

	case FREAD:
I 56
		/*
		 * Need to block timeouts (ttrstart).
		 */
		s = spltty();
E 56
D 18
		if (tp->t_outq.c_cc)
E 18
I 18
D 46
		if (tp->t_outq.c_cc && (tp->t_state&TS_TTSTOP) == 0) {
E 46
I 46
		if ((tp->t_state&TS_ISOPEN) &&
I 53
		     tp->t_outq.c_cc && (tp->t_state&TS_TTSTOP) == 0) {
			splx(s);
			return (1);
		}
I 56
		splx(s);
E 56
		/* FALLTHROUGH */

	case 0:					/* exceptional */
		if ((tp->t_state&TS_ISOPEN) &&
E 53
		    (pti->pt_flags&PF_PKT && pti->pt_send ||
D 53
		     pti->pt_flags&PF_UCNTL && pti->pt_ucntl ||
		     tp->t_outq.c_cc && (tp->t_state&TS_TTSTOP) == 0)) {
E 53
I 53
D 56
		     pti->pt_flags&PF_UCNTL && pti->pt_ucntl)) {
E 53
E 46
			splx(s);
E 56
I 56
		     pti->pt_flags&PF_UCNTL && pti->pt_ucntl))
E 56
E 18
			return (1);
I 18
D 56
		}
E 56
E 18
D 20
		pti = &pt_ioctl[minor(dev)];
E 20
D 17
		if ((p = pti->pti_selr) && p->p_wchan == (caddr_t)&selwait)
			pti->pti_flags |= PTCRCOLL;
E 17
I 17
		if ((p = pti->pt_selr) && p->p_wchan == (caddr_t)&selwait)
			pti->pt_flags |= PF_RCOLL;
E 17
		else
D 17
			pti->pti_selr = u.u_procp;
E 17
I 17
			pti->pt_selr = u.u_procp;
E 17
D 18
		return (0);
E 18
I 18
		break;
E 18

I 53

E 53
	case FWRITE:
D 18
		if (tp->t_rawq.c_cc + tp->t_canq.c_cc < TTYHOG/2)
E 18
I 18
D 20
		if (tp->t_rawq.c_cc + tp->t_canq.c_cc < TTYHOG/2) {
E 20
I 20
D 46
		if ((pti->pt_flags & PF_REMOTE) == 0 || tp->t_rawq.c_cc == 0) {
E 46
I 46
D 56
		if ((tp->t_state&TS_ISOPEN) &&
D 47
		    (((pti->pt_flags&PF_REMOTE) && tp->t_canq.c_cc) ||
		    (tp->t_rawq.c_cc + tp->t_canq.c_cc < TTYHOG - 2))) {
E 47
I 47
		    ((pti->pt_flags&PF_REMOTE) == 0 || tp->t_canq.c_cc == 0)) {
E 47
E 46
E 20
			splx(s);
E 18
			return (1);
E 56
I 56
		if (tp->t_state&TS_ISOPEN) {
			if (pti->pt_flags & PF_REMOTE) {
			    if (tp->t_canq.c_cc == 0)
				return (1);
			} else {
			    if (tp->t_rawq.c_cc + tp->t_canq.c_cc < TTYHOG-2)
				    return (1);
			    if (tp->t_canq.c_cc == 0 &&
D 57
			        tp->t_flags & (RAW|CBREAK) == 0)
E 57
I 57
			        (tp->t_flags & (RAW|CBREAK)) == 0)
E 57
				    return (1);
			}
E 56
I 18
		}
E 18
D 20
		pti = &pt_ioctl[minor(dev)];
E 20
D 17
		if ((p = pti->pti_selw) && p->p_wchan == (caddr_t)&selwait)
			pti->pti_flags |= PTCWCOLL;
E 17
I 17
		if ((p = pti->pt_selw) && p->p_wchan == (caddr_t)&selwait)
			pti->pt_flags |= PF_WCOLL;
E 17
		else
D 17
			pti->pti_selw = u.u_procp;
E 17
I 17
			pti->pt_selw = u.u_procp;
I 18
		break;
I 53

E 53
E 18
E 17
	}
I 18
D 56
	splx(s);
E 56
	return (0);
E 18
E 15
D 14
	if (tp->t_outq.c_cc)
E 14
I 14
}
D 15
	if (tp->t_outq.c_cc) {
E 14
		return (1);
I 14
}
E 14
	pti = &pt_ioctl[minor(dev)];
D 13
	if ((p = pti->pti_selr) && p->p_wchan == (caddr_t)select)
E 13
I 13
	if ((p = pti->pti_selr) && p->p_wchan == (caddr_t)&selwait)
E 13
		pti->pti_flags |= PTCRCOLL;
	else
		pti->pti_selr = u.u_procp;
	return (0);
}
E 15

E 12
D 27
ptcwrite(dev)
E 27
I 27
ptcwrite(dev, uio)
E 27
D 15
dev_t dev;
E 15
I 15
	dev_t dev;
I 27
D 46
	struct uio *uio;
E 46
I 46
	register struct uio *uio;
E 46
E 27
E 15
D 8
{                       /* Stuff characters into PTY's input buffer */
E 8
I 8
D 12
{			/* Stuff characters into PTY's input buffer */
E 12
I 12
{
E 12
E 8
D 29
	register struct tty *tp;
E 29
I 29
	register struct tty *tp = &pt_tty[minor(dev)];
E 29
D 46
	register char *cp, *ce;
	register int cc;
E 46
I 46
	register struct iovec *iov;
	register char *cp;
	register int cc = 0;
E 46
	char locbuf[BUFSIZ];
I 15
	int cnt = 0;
I 20
	struct pt_ioctl *pti = &pt_ioctl[minor(dev)];
I 29
	int error = 0;
E 29
E 20
E 15

D 29
	tp = &pt_tty[minor(dev)];
E 29
D 12
	if((tp->t_state&(CARR_ON|ISOPEN)) == 0)
E 12
I 12
D 15
	if ((tp->t_state&(CARR_ON|ISOPEN)) == 0)
E 15
I 15
D 46
	if ((tp->t_state&(TS_CARR_ON|TS_ISOPEN)) == 0)
E 15
E 12
D 29
		return;
E 29
I 29
		return (EIO);
E 29
D 12
	while(u.u_count) {
E 12
I 12
D 20
	while (u.u_count) {
E 20
I 20
	do {
E 20
E 12
D 27
		cc = MIN(u.u_count, BUFSIZ);
E 27
I 27
		register struct iovec *iov;

		if (uio->uio_iovcnt == 0)
			break;
		iov = uio->uio_iov;
		if (iov->iov_len == 0) {
I 41
D 44
			while (pti->pt_flags&PF_REMOTE && tp->t_rawq.c_cc != 0)
E 44
I 44
			while ((pti->pt_flags&PF_REMOTE) && tp->t_rawq.c_cc != 0)
E 44
				sleep((caddr_t)&tp->t_rawq.c_cf, TTIPRI);
			if (pti->pt_flags&PF_REMOTE) {
				(void) putc(0, &tp->t_rawq);
				wakeup((caddr_t)&tp->t_rawq);
			}
E 41
			uio->uio_iovcnt--;	
			uio->uio_iov++;
			if (uio->uio_iovcnt < 0)
				panic("ptcwrite");
			continue;
		}
		cc = MIN(iov->iov_len, BUFSIZ);
E 27
		cp = locbuf;
D 27
		iomove(cp, (unsigned)cc, B_WRITE);
E 27
I 27
D 29
		u.u_error = uiomove(cp, cc, UIO_WRITE, uio);
E 27
D 12
		if(u.u_error)
E 12
I 12
		if (u.u_error)
E 29
I 29
		error = uiomove(cp, cc, UIO_WRITE, uio);
		if (error)
E 29
E 12
			break;
		ce = cp + cc;
E 46
I 20
again:
D 46
		if (pti->pt_flags & PF_REMOTE) {
			if (tp->t_rawq.c_cc) {
				if (pti->pt_flags & PF_NBIO) {
D 27
					u.u_count += ce - cp;
E 27
I 27
					iov->iov_base -= ce - cp;
					iov->iov_len += ce - cp;
					uio->uio_resid += ce - cp;
					uio->uio_offset -= ce - cp;
E 27
D 29
					u.u_error = EWOULDBLOCK;
					return;
E 29
I 29
					return (EWOULDBLOCK);
E 29
				}
				sleep((caddr_t)&tp->t_rawq.c_cf, TTOPRI);
				goto again;
			}
D 22
			b_to_q(cp, cc, &tp->t_rawq);
			putc(0, &tp->t_rawq);
E 22
I 22
			(void) b_to_q(cp, cc, &tp->t_rawq);
			(void) putc(0, &tp->t_rawq);
E 22
			wakeup((caddr_t)&tp->t_rawq);
E 46
I 46
	if ((tp->t_state&TS_ISOPEN) == 0)
		goto block;
D 49
	if (cnt == 0 && pti->pt_flags & PF_REMOTE) {
		if (uio->uio_iovcnt <= 0)
E 46
D 29
			return;
E 29
I 29
			return (0);
E 49
I 49
	if (pti->pt_flags & PF_REMOTE) {
E 49
I 46
		if (tp->t_canq.c_cc)
			goto block;
D 49
		iov = uio->uio_iov;
		if (cc == 0 && iov->iov_len) {
			cc = MIN(iov->iov_len, BUFSIZ);
			cp = locbuf;
			error = uiomove(cp, cc, UIO_WRITE, uio);
			if (error)
				return (error);
			/* check again for safety */
			if ((tp->t_state&TS_ISOPEN) == 0)
				return (EIO);
			if (tp->t_canq.c_cc)
				goto block;
E 49
I 49
		while (uio->uio_iovcnt > 0 && tp->t_canq.c_cc < TTYHOG - 1) {
			iov = uio->uio_iov;
			if (iov->iov_len == 0) {
				uio->uio_iovcnt--;	
				uio->uio_iov++;
				continue;
			}
			if (cc == 0) {
				cc = MIN(iov->iov_len, BUFSIZ);
				cc = MIN(cc, TTYHOG - 1 - tp->t_canq.c_cc);
				cp = locbuf;
				error = uiomove(cp, cc, UIO_WRITE, uio);
				if (error)
					return (error);
				/* check again for safety */
				if ((tp->t_state&TS_ISOPEN) == 0)
					return (EIO);
			}
			if (cc)
				(void) b_to_q(cp, cc, &tp->t_canq);
			cc = 0;
E 49
E 46
E 29
		}
E 20
D 12
		while(cp < ce) {
			while(tp->t_delct && tp->t_rawq.c_cc >= TTYHOG - 2) {
E 12
I 12
D 46
		while (cp < ce) {
D 37
			while (tp->t_delct && tp->t_rawq.c_cc >= TTYHOG - 2) {
E 37
I 37
D 40
			while ((tp->t_delct || tp->t_canq.c_cc)
			&& (tp->t_rawq.c_cc + tp->t_canq.c_cc) >= TTYHOG - 2) {
E 40
I 40
			if ((tp->t_rawq.c_cc + tp->t_canq.c_cc) >= TTYHOG - 2 &&
			    (tp->t_canq.c_cc > 0)) {
E 40
E 37
E 12
				wakeup((caddr_t)&tp->t_rawq);
I 15
				if (tp->t_state & TS_NBIO) {
D 27
					u.u_count += ce - cp;
E 27
I 27
					iov->iov_base -= ce - cp;
					iov->iov_len += ce - cp;
					uio->uio_resid += ce - cp;
					uio->uio_offset -= ce - cp;
E 27
					if (cnt == 0)
D 29
						u.u_error = EWOULDBLOCK;
					return;
E 29
I 29
						return (EWOULDBLOCK);
					return (0);
E 29
				}
E 15
				/* Better than just flushing it! */
				/* Wait for something to be read */
				sleep((caddr_t)&tp->t_rawq.c_cf, TTOPRI);
I 20
				goto again;
E 46
I 46
D 49
		if (cc)
			(void) b_to_q(cp, cc, &tp->t_canq);
E 49
		(void) putc(0, &tp->t_canq);
		ttwakeup(tp);
		wakeup((caddr_t)&tp->t_canq);
		return (0);
	}
	while (uio->uio_iovcnt > 0) {
		iov = uio->uio_iov;
		if (cc == 0) {
			if (iov->iov_len == 0) {
				uio->uio_iovcnt--;	
				uio->uio_iov++;
				continue;
E 46
E 20
			}
I 46
			cc = MIN(iov->iov_len, BUFSIZ);
			cp = locbuf;
			error = uiomove(cp, cc, UIO_WRITE, uio);
			if (error)
				return (error);
			/* check again for safety */
			if ((tp->t_state&TS_ISOPEN) == 0)
				return (EIO);
		}
D 49
		while (--cc >= 0) {
E 49
I 49
		while (cc > 0) {
			if ((tp->t_rawq.c_cc + tp->t_canq.c_cc) >= TTYHOG - 2 &&
D 56
			    (tp->t_canq.c_cc > 0)) {
E 56
I 56
			   (tp->t_canq.c_cc > 0 ||
			      tp->t_flags & (RAW|CBREAK))) {
E 56
				wakeup((caddr_t)&tp->t_rawq);
				goto block;
			}
E 49
E 46
D 11
			ttyinput(*cp++, tp);
E 11
I 11
			(*linesw[tp->t_line].l_rint)(*cp++, tp);
I 15
			cnt++;
I 49
			cc--;
E 49
E 15
E 11
		}
D 20
	}
E 20
I 20
D 27
	} while (u.u_count);
E 27
I 27
D 46
	} while (uio->uio_resid);
I 29
	return (error);
E 46
I 46
		cc = 0;
	}
	return (0);
block:
	/*
D 49
	 * Come here to wait for slave to open or for space
	 * in outq.
E 49
I 49
	 * Come here to wait for slave to open, for space
	 * in outq, or space in rawq.
E 49
	 */
	if ((tp->t_state&TS_CARR_ON) == 0)
		return (EIO);
	if (pti->pt_flags & PF_NBIO) {
D 49
		if (cnt == 0)
			return (EWOULDBLOCK);
E 49
		iov->iov_base -= cc;
		iov->iov_len += cc;
		uio->uio_resid += cc;
		uio->uio_offset -= cc;
I 49
		if (cnt == 0)
			return (EWOULDBLOCK);
E 49
		return (0);
	}
	sleep((caddr_t)&tp->t_rawq.c_cf, TTOPRI);
	goto again;
E 46
E 29
E 27
E 20
}

D 12
/* Note: Both slave and controlling device have the same routine for */
/* 'ioctl' (but note check for controller - 4/12/78:mob)*/
E 12
/*ARGSUSED*/
D 26
ptyioctl(dev, cmd, addr, flag)
D 12
caddr_t addr;
dev_t dev;
{					/* Read and write status bits */
E 12
I 12
	caddr_t addr;
E 26
I 26
ptyioctl(dev, cmd, data, flag)
	caddr_t data;
E 26
	dev_t dev;
{
E 12
D 21
	register struct tty *tp;
E 21
I 21
	register struct tty *tp = &pt_tty[minor(dev)];
	register struct pt_ioctl *pti = &pt_ioctl[minor(dev)];
I 30
D 46
	int error;
E 46
I 46
	int stop, error;
I 51
	extern ttyinput();
E 51
E 46
E 30
E 21
D 13
	register int tbd;
E 13
D 12
#ifdef BLAND
	register int nld;
#endif
E 12

D 21
	tp = &pt_tty[minor(dev)];
E 21
D 12
		/* if controller stty then must flush to prevent a hang */
	if(cdevsw[major(dev)].d_open == ptcopen && cmd == TIOCSETP)
		while(getc(&tp->t_outq) >= 0);
	if(ttioctl(tp, cmd, addr, dev)) {
		if(cmd == TIOCSETP || cmd == TIOCSETN) {
#ifdef BLAND
			nld = tp->t_flags & NLDELAY;
#endif
			tbd = tp->t_flags & TBDELAY;
			tp->t_flags &= ~ALLDELAYS;
D 8
			if(tbd == TBDELAY)      /* Wants tab expansion */
E 8
I 8
			if(tbd == TBDELAY)	/* Wants tab expansion */
E 8
				tp->t_flags |= tbd;
#ifdef BLAND
D 8
			if(nld == NLDELAY)      /* Allow ANN ARBOR mode. */
E 8
I 8
			if(nld == NLDELAY)	/* Allow ANN ARBOR mode. */
E 8
				tp->t_flags |= nld;
#endif
		}
	} else
E 12
I 12
D 51
	/* IF CONTROLLER STTY THEN MUST FLUSH TO PREVENT A HANG ??? */
E 51
I 51
	/*
	 * IF CONTROLLER STTY THEN MUST FLUSH TO PREVENT A HANG.
	 * ttywflush(tp) will hang if there are characters in the outq.
	 */
E 51
D 16
	if (cdevsw[major(dev)].d_open == ptcopen && cmd == TIOCSETP)
		while (getc(&tp->t_outq) >= 0);
E 16
I 16
D 26
	if (cdevsw[major(dev)].d_open == ptcopen) {
I 17
D 21
		register struct pt_ioctl *pti = &pt_ioctl[minor(dev)];
E 21
		if (cmd == TIOCPKT) {
			int packet;
D 22
			if (copyin((caddr_t)addr, &packet, sizeof (packet))) {
E 22
I 22
			if (copyin((caddr_t)addr, (caddr_t)&packet, sizeof (packet))) {
E 22
				u.u_error = EFAULT;
				return;
			}
			if (packet)
E 26
I 26
	if (cdevsw[major(dev)].d_open == ptcopen)
		switch (cmd) {

		case TIOCPKT:
D 46
			if (*(int *)data)
E 46
I 46
			if (*(int *)data) {
				if (pti->pt_flags & PF_UCNTL)
					return (EINVAL);
E 46
E 26
				pti->pt_flags |= PF_PKT;
D 46
			else
E 46
I 46
			} else
E 46
				pti->pt_flags &= ~PF_PKT;
I 20
D 30
			return;
E 30
I 30
			return (0);
E 30
D 26
		}
		if (cmd == TIOCREMOTE) {
			int remote;
D 22
			if (copyin((caddr_t)addr, &remote, sizeof (remote))) {
E 22
I 22
			if (copyin((caddr_t)addr, (caddr_t)&remote, sizeof (remote))) {
E 22
				u.u_error = EFAULT;
				return;
			}
			if (remote)
E 26
I 26

I 46
		case TIOCUCNTL:
			if (*(int *)data) {
				if (pti->pt_flags & PF_PKT)
					return (EINVAL);
				pti->pt_flags |= PF_UCNTL;
			} else
				pti->pt_flags &= ~PF_UCNTL;
			return (0);

E 46
		case TIOCREMOTE:
			if (*(int *)data)
E 26
				pti->pt_flags |= PF_REMOTE;
			else
				pti->pt_flags &= ~PF_REMOTE;
D 34
			flushtty(tp, FREAD|FWRITE);
E 34
I 34
			ttyflush(tp, FREAD|FWRITE);
E 34
E 20
D 30
			return;
E 30
I 30
			return (0);
E 30
D 26
		}
E 17
		if (cmd == FIONBIO) {
			int nbio;
D 17
			register struct pt_ioctl *pti;
E 17
D 22
			if (copyin(addr, &nbio, sizeof (nbio))) {
E 22
I 22
			if (copyin((caddr_t)addr, (caddr_t)&nbio, sizeof (nbio))) {
E 22
				u.u_error = EFAULT;
				return;
			}
D 17
			pti = &pt_ioctl[minor(dev)];
E 17
			if (nbio)
E 26
I 26

		case FIONBIO:
			if (*(int *)data)
E 26
D 17
				pti->pti_flags |= PTCNBIO;
E 17
I 17
				pti->pt_flags |= PF_NBIO;
E 17
			else
D 17
				pti->pti_flags &= ~PTCNBIO;
E 17
I 17
				pti->pt_flags &= ~PF_NBIO;
E 17
D 30
			return;
E 30
I 30
			return (0);
E 30
I 26

		case TIOCSETP:
I 51
		case TIOCSETN:
		case TIOCSETD:
E 51
			while (getc(&tp->t_outq) >= 0)
				;
			break;
E 26
		}
D 26
		if (cmd == TIOCSETP)
			while (getc(&tp->t_outq) >= 0);
	}
E 16
	if (ttioctl(tp, cmd, addr, dev) == 0)
E 26
I 26
D 30
	if (ttioctl(tp, cmd, data, dev) == 0)
E 26
E 12
		u.u_error = ENOTTY;
E 30
I 30
D 43
	error = ttioctl(tp, cmd, data, dev);
E 43
I 43
	error = ttioctl(tp, cmd, data, flag);
I 51
	/*
	 * Since we use the tty queues internally,
	 * pty's can't be switched to disciplines which overwrite
	 * the queues.  We can't tell anything about the discipline
	 * from here...
	 */
	if (linesw[tp->t_line].l_rint != ttyinput) {
		(*linesw[tp->t_line].l_close)(tp);
		tp->t_line = 0;
		(void)(*linesw[tp->t_line].l_open)(dev, tp);
		error = ENOTTY;
	}
E 51
E 43
D 46
	if (error < 0)
E 46
I 46
	if (error < 0) {
		if (pti->pt_flags & PF_UCNTL &&
D 59
		    (cmd & ~0xff) == _IO(u,0)) {
E 59
I 59
		    (cmd & ~0xff) == UIOCCMD(0)) {
E 59
			if (cmd & 0xff) {
				pti->pt_ucntl = (u_char)cmd;
				ptcwakeup(tp, FREAD);
			}
			return (0);
		}
E 46
		error = ENOTTY;
E 30
I 21
D 32
	{ int stop = (tp->t_un.t_chr.t_stopc == ('s'&037) &&
		      tp->t_un.t_chr.t_startc == ('q'&037));
E 32
I 32
D 45
	{ int stop = (tp->t_stopc == ('s'&037) &&
E 45
I 45
D 46
	{ int stop = ((tp->t_flags & RAW) == 0 &&
		      tp->t_stopc == ('s'&037) &&
E 45
		      tp->t_startc == ('q'&037));
E 46
I 46
	}
	stop = (tp->t_flags & RAW) == 0 &&
	    tp->t_stopc == CTRL(s) && tp->t_startc == CTRL(q);
E 46
E 32
	if (pti->pt_flags & PF_NOSTOP) {
		if (stop) {
D 54
			pti->pt_send &= TIOCPKT_NOSTOP;
E 54
I 54
			pti->pt_send &= ~TIOCPKT_NOSTOP;
E 54
			pti->pt_send |= TIOCPKT_DOSTOP;
			pti->pt_flags &= ~PF_NOSTOP;
D 46
			ptcwakeup(tp);
E 46
I 46
			ptcwakeup(tp, FREAD);
E 46
		}
	} else {
D 46
		if (stop == 0) {
E 46
I 46
		if (!stop) {
E 46
			pti->pt_send &= ~TIOCPKT_DOSTOP;
			pti->pt_send |= TIOCPKT_NOSTOP;
			pti->pt_flags |= PF_NOSTOP;
D 46
			ptcwakeup(tp);
E 46
I 46
			ptcwakeup(tp, FREAD);
E 46
		}
D 46
	}
E 46
	}
I 30
	return (error);
E 30
E 21
}
I 6
#endif
E 6
E 1
