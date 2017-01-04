h09486
s 00012/00000/00097
d D 7.5 04/02/27 02:03:01 msokolov 17 16
c add LK201DISC
e
s 00002/00002/00095
d D 7.4 02/07/21 14:02:44 msokolov 16 15
c SLIP has slmodem now
e
s 00014/00000/00083
d D 7.3 02/07/19 22:06:08 msokolov 15 14
c add PPPDISC
e
s 00001/00001/00082
d D 7.2 88/05/26 08:56:12 karels 14 13
c SLIP needs nullmodem (and then lint is happy, too)
e
s 00001/00001/00082
d D 7.1 86/06/05 00:09:49 mckusick 13 12
c 4.3BSD release version
e
s 00016/00004/00067
d D 6.9 86/02/10 08:39:15 karels 12 11
c serial IP
e
s 00000/00007/00071
d D 6.8 85/11/06 18:27:54 sam 11 10
c don't need extra line discpline slot for tablet now since ioctl 
c sets tablet type
e
s 00000/00011/00078
d D 6.7 85/11/06 10:11:10 karels 10 9
c move nullmodem to tty.c, maintain TS_CARR_ON
e
s 00020/00009/00069
d D 6.6 85/11/04 18:10:58 karels 9 8
c use modem entry in linesw to signal carrier change; split line-disc close
c from tty close
e
s 00007/00001/00071
d D 6.5 85/06/08 14:46:42 mckusick 8 7
c Add copyright
e
s 00001/00000/00071
d D 6.4 84/12/21 13:56:20 bloom 7 6
c include ioctl.h
e
s 00005/00005/00066
d D 6.3 84/08/29 20:23:03 bloom 6 5
c Change to includes.  no more ../h
e
s 00001/00001/00070
d D 6.2 83/09/25 12:47:19 karels 5 4
c ldisc 0 close is nulldev, not nodev
e
s 00000/00000/00071
d D 6.1 83/07/29 06:39:26 sam 4 3
c 4.2 distribution
e
s 00017/00000/00054
d D 4.3 83/05/27 12:48:41 sam 3 2
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00003/00053
d D 4.2 82/10/17 11:33:26 root 2 1
c nldisp computed
e
s 00056/00000/00000
d D 4.1 82/10/17 00:15:21 root 1 0
c date and time created 82/10/17 00:15:21 by root
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
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
E 8

D 6
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/tty.h"
#include "../h/conf.h"
E 6
I 6
#include "param.h"
#include "systm.h"
#include "buf.h"
I 7
#include "ioctl.h"
E 7
#include "tty.h"
#include "conf.h"
E 6

int	nodev();
int	nulldev();

D 9
int	ttyopen(),ttyclose(),ttread(),ttwrite(),nullioctl(),ttstart();
int	ttyinput();
E 9
I 9
int	ttyopen(),ttylclose(),ttread(),ttwrite(),nullioctl(),ttstart();
int	ttymodem(), nullmodem(), ttyinput();
E 9

#include "bk.h"
#if NBK > 0
int	bkopen(),bkclose(),bkread(),bkinput(),bkioctl();
#endif

#include "tb.h"
#if NTB > 0
int	tbopen(),tbclose(),tbread(),tbinput(),tbioctl();
#endif
I 15

E 15
I 12
#include "sl.h"
#if NSL > 0
D 16
int	slopen(),slclose(),slinput(),sltioctl(),slstart();
E 16
I 16
int	slopen(),slclose(),slinput(),sltioctl(),slstart(),slmodem();
E 16
#endif
E 12

I 15
#include "ppp.h"
#if NPPP > 0
int	pppasync_topen(), pppasync_tclose(), pppasync_input();
int	pppasync_tioctl(), pppasync_start(), pppasync_modem();
#endif
E 15
I 12

I 17
#include "lk.h"
#if NLK > 0
int	lk201_lopen(), lk201_lclose(), lk201_input(), lk201_ioctl();
#endif

E 17
E 12
struct	linesw linesw[] =
{
D 5
	ttyopen, nodev, ttread, ttwrite, nullioctl,
E 5
I 5
D 9
	ttyopen, nulldev, ttread, ttwrite, nullioctl,
E 5
	ttyinput, nodev, nulldev, ttstart, nulldev,
E 9
I 9
D 12
	ttyopen, ttylclose, ttread, ttwrite, nullioctl,
E 12
I 12
	ttyopen, ttylclose, ttread, ttwrite, nullioctl,	/* 0- OTTYDISC */
E 12
	ttyinput, nodev, nulldev, ttstart, ttymodem,
E 9
#if NBK > 0
D 12
	bkopen, bkclose, bkread, ttwrite, bkioctl,
E 12
I 12
	bkopen, bkclose, bkread, ttwrite, bkioctl,	/* 1- NETLDISC */
E 12
D 9
	bkinput, nodev, nulldev, ttstart, nulldev,
E 9
I 9
	bkinput, nodev, nulldev, ttstart, nullmodem,
E 9
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
D 9
	ttyopen, ttyclose, ttread, ttwrite, nullioctl,
	ttyinput, nodev, nulldev, ttstart, nulldev,
E 9
I 9
D 12
	ttyopen, ttylclose, ttread, ttwrite, nullioctl,
E 12
I 12
	ttyopen, ttylclose, ttread, ttwrite, nullioctl,	/* 2- NTTYDISC */
E 12
	ttyinput, nodev, nulldev, ttstart, ttymodem,
E 9
#if NTB > 0
	tbopen, tbclose, tbread, nodev, tbioctl,
D 9
	tbinput, nodev, nulldev, ttstart, nulldev,		/* 3 */
E 9
I 9
D 12
	tbinput, nodev, nulldev, ttstart, nullmodem,		/* 3 */
E 12
I 12
	tbinput, nodev, nulldev, ttstart, nullmodem,	/* 3- TABLDISC */
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
#if NSL > 0
	slopen, slclose, nodev, nodev, sltioctl,
D 14
	slinput, nodev, nulldev, slstart, nulldev,	/* 4- SLIPDISC */
E 14
I 14
D 16
	slinput, nodev, nulldev, slstart, nullmodem,	/* 4- SLIPDISC */
E 16
I 16
	slinput, nodev, nulldev, slstart, slmodem,	/* 4- SLIPDISC */
E 16
I 15
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
#if NPPP > 0
	pppasync_topen, pppasync_tclose, nodev, nodev, pppasync_tioctl,
	pppasync_input, nodev, nulldev, pppasync_start, /* 5- PPPDISC */
	pppasync_modem,
I 17
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
#if NLK > 0
	lk201_lopen, lk201_lclose, ttread, ttwrite, lk201_ioctl,
	lk201_input, nodev, nulldev, ttstart, nullmodem,/* 6- LK201DISC */
E 17
E 15
E 14
E 12
E 9
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
D 11
#if NTB > 0
	tbopen, tbclose, tbread, nodev, tbioctl,
D 9
	tbinput, nodev, nulldev, ttstart, nulldev,		/* 4 */
E 9
I 9
	tbinput, nodev, nulldev, ttstart, nullmodem,		/* 4 */
E 9
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
E 11
D 2
	0		/* XXX */
E 2
};

D 2
int	nldisp = 5;

E 2
I 2
int	nldisp = sizeof (linesw) / sizeof (linesw[0]);
I 3

/*
 * Do nothing specific version of line
 * discipline specific ioctl command.
 */
/*ARGSUSED*/
nullioctl(tp, cmd, data, flags)
	struct tty *tp;
	char *data;
	int flags;
{

#ifdef lint
	tp = tp; data = data; flags = flags;
#endif
	return (-1);
I 9
}
D 10

/*
 * Default modem control routine.
 * Return argument flag, to turn off device on carrier drop.
 */
nullmodem(flag)
	int flag;
{
	
	return (flag);
E 9
}
E 10
E 3
E 2
E 1
