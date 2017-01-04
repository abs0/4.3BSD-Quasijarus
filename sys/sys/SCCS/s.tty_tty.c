h53149
s 00001/00001/00086
d D 7.1 86/06/05 00:10:57 mckusick 20 19
c 4.3BSD release version
e
s 00007/00001/00080
d D 6.3 85/06/08 14:48:28 mckusick 19 18
c Add copyright
e
s 00009/00009/00072
d D 6.2 84/08/29 20:24:58 bloom 18 17
c Change to includes.  no more ../h
e
s 00000/00000/00081
d D 6.1 83/07/29 06:40:23 sam 17 16
c 4.2 distribution
e
s 00001/00000/00080
d D 4.14 82/12/05 22:01:34 sam 16 15
c include ioctl.h separate from tty.h
e
s 00003/00000/00077
d D 4.13 82/10/17 14:05:55 root 15 14
c fix lint
e
s 00009/00011/00068
d D 4.12 82/10/17 11:30:16 root 14 13
c returns error in open, ioctl
e
s 00006/00010/00073
d D 4.11 82/10/13 22:09:25 root 13 12
c return errors from ioctl routines and internal ldisc routines
e
s 00009/00004/00074
d D 4.10 82/08/22 20:42:29 root 12 11
c uio'd
e
s 00001/00001/00077
d D 4.9 82/03/31 09:08:58 wnj 11 10
c bug fix to syselect found by mosher
e
s 00000/00001/00078
d D 4.8 82/01/24 22:02:06 wnj 10 9
c clean up SDETACH
e
s 00005/00001/00074
d D 4.7 82/01/24 19:46:11 root 9 8
c clear SDETACH when TIOCNOTTY
e
s 00005/00005/00070
d D 4.6 82/01/19 02:01:45 wnj 8 7
c no more SDETACH crap
e
s 00012/00006/00063
d D 4.5 82/01/13 10:32:35 wnj 7 6
c TIOCNOTTY
e
s 00012/00000/00057
d D 4.4 81/10/11 13:02:39 wnj 6 5
c first bootable version
e
s 00002/00002/00055
d D 4.3 81/03/09 01:49:15 wnj 5 4
c lint and a few minor fixed
e
s 00013/00001/00044
d D 4.2 81/01/28 12:05:35 wnj 4 3
c no access to /dev/tty for SDETACH processes.
e
s 00000/00000/00045
d D 4.1 80/11/09 17:32:46 bill 3 2
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00001/00044
d D 3.2 80/06/07 02:47:41 bill 2 1
c %H%->%G%
e
s 00045/00000/00000
d D 3.1 80/04/09 16:04:23 bill 1 0
c date and time created 80/04/09 16:04:23 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 19
/*	%M%	%I%	%E%	*/
E 19
I 19
/*
D 20
 * Copyright (c) 1982 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 19
E 5
E 2

/*
D 5
 *	indirect driver for controlling tty.
E 5
I 5
 * Indirect driver for controlling tty.
I 6
 *
 * THIS IS GARBAGE: MUST SOON BE DONE WITH struct inode * IN PROC TABLE.
E 6
E 5
 */
D 18
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
I 16
#include "../h/ioctl.h"
E 16
#include "../h/tty.h"
#include "../h/proc.h"
I 12
#include "../h/uio.h"
E 18
I 18
#include "param.h"
#include "systm.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "tty.h"
#include "proc.h"
#include "uio.h"
E 18
E 12

/*ARGSUSED*/
syopen(dev, flag)
I 14
	dev_t dev;
	int flag;
E 14
{

D 4
	if(u.u_ttyp == NULL) {
E 4
I 4
D 8
	if(u.u_ttyp == NULL || (u.u_procp->p_flag&SDETACH)) {
E 8
I 8
D 14
	if (u.u_ttyp == NULL) {
E 8
E 4
		u.u_error = ENXIO;
		return;
	}
	(*cdevsw[major(u.u_ttyd)].d_open)(u.u_ttyd, flag);
E 14
I 14
	if (u.u_ttyp == NULL)
		return (ENXIO);
	return ((*cdevsw[major(u.u_ttyd)].d_open)(u.u_ttyd, flag));
E 14
}

/*ARGSUSED*/
D 12
syread(dev)
E 12
I 12
syread(dev, uio)
	dev_t dev;
	struct uio *uio;
E 12
{

I 4
D 7
	if (u.u_procp->p_flag&SDETACH) {
E 7
I 7
D 8
	if (u.u_ttyp == NULL || (u.u_procp->p_flag&SDETACH)) {
E 8
I 8
D 13
	if (u.u_ttyp == NULL) {
E 8
E 7
		u.u_error = ENXIO;
		return;
	}
E 4
D 12
	(*cdevsw[major(u.u_ttyd)].d_read)(u.u_ttyd);
E 12
I 12
	(*cdevsw[major(u.u_ttyd)].d_read)(u.u_ttyd, uio);
E 13
I 13
	if (u.u_ttyp == NULL)
		return (ENXIO);
	return ((*cdevsw[major(u.u_ttyd)].d_read)(u.u_ttyd, uio));
E 13
E 12
}

/*ARGSUSED*/
D 12
sywrite(dev)
E 12
I 12
sywrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 12
{

I 4
D 7
	if (u.u_procp->p_flag&SDETACH) {
E 7
I 7
D 8
	if (u.u_ttyp == NULL || (u.u_procp->p_flag&SDETACH)) {
E 8
I 8
D 13
	if (u.u_ttyp == NULL) {
E 8
E 7
		u.u_error = ENXIO;
		return;
	}
E 4
D 12
	(*cdevsw[major(u.u_ttyd)].d_write)(u.u_ttyd);
E 12
I 12
	(*cdevsw[major(u.u_ttyd)].d_write)(u.u_ttyd, uio);
E 13
I 13
	if (u.u_ttyp == NULL)
		return (ENXIO);
	return ((*cdevsw[major(u.u_ttyd)].d_write)(u.u_ttyd, uio));
E 13
E 12
}

/*ARGSUSED*/
syioctl(dev, cmd, addr, flag)
D 9
caddr_t addr;
E 9
I 9
	dev_t dev;
	int cmd;
	caddr_t addr;
	int flag;
E 9
{

I 4
D 7
	if (u.u_procp->p_flag&SDETACH) {
E 7
I 7
	if (cmd == TIOCNOTTY) {
		u.u_ttyp = 0;
		u.u_ttyd = 0;
		u.u_procp->p_pgrp = 0;
I 9
D 10
		u.u_procp->p_flags &= ~SDETACH;
E 10
E 9
D 14
		return;
E 14
I 14
		return (0);
E 14
	}
D 8
	if (u.u_ttyp == NULL || (u.u_procp->p_flag&SDETACH)) {
E 8
I 8
D 14
	if (u.u_ttyp == NULL) {
E 8
E 7
		u.u_error = ENXIO;
		return;
	}
E 4
	(*cdevsw[major(u.u_ttyd)].d_ioctl)(u.u_ttyd, cmd, addr, flag);
E 14
I 14
	if (u.u_ttyp == NULL)
		return (ENXIO);
	return ((*cdevsw[major(u.u_ttyd)].d_ioctl)(u.u_ttyd, cmd, addr, flag));
E 14
I 6
}

I 15
/*ARGSUSED*/
E 15
syselect(dev, flag)
I 15
	dev_t dev;
	int flag;
E 15
{

D 7
	if (u.u_procp->p_flag&SDETACH) {
E 7
I 7
D 8
	if (u.u_ttyp == NULL || (u.u_procp->p_flag&SDETACH)) {
E 8
I 8
	if (u.u_ttyp == NULL) {
E 8
E 7
		u.u_error = ENXIO;
D 7
		return;
E 7
I 7
		return (0);
E 7
	}
D 7
	(*cdevsw[major(u.u_ttyd)].d_select)(dev, flag);
E 7
I 7
D 11
	return ((*cdevsw[major(u.u_ttyd)].d_select)(dev, flag));
E 11
I 11
	return ((*cdevsw[major(u.u_ttyd)].d_select)(u.u_ttyd, flag));
E 11
E 7
E 6
}
E 1
