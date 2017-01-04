/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)tty_conf.c	7.5 (Berkeley) 2/27/04
 */

#include "param.h"
#include "systm.h"
#include "buf.h"
#include "ioctl.h"
#include "tty.h"
#include "conf.h"

int	nodev();
int	nulldev();

int	ttyopen(),ttylclose(),ttread(),ttwrite(),nullioctl(),ttstart();
int	ttymodem(), nullmodem(), ttyinput();

#include "bk.h"
#if NBK > 0
int	bkopen(),bkclose(),bkread(),bkinput(),bkioctl();
#endif

#include "tb.h"
#if NTB > 0
int	tbopen(),tbclose(),tbread(),tbinput(),tbioctl();
#endif

#include "sl.h"
#if NSL > 0
int	slopen(),slclose(),slinput(),sltioctl(),slstart(),slmodem();
#endif

#include "ppp.h"
#if NPPP > 0
int	pppasync_topen(), pppasync_tclose(), pppasync_input();
int	pppasync_tioctl(), pppasync_start(), pppasync_modem();
#endif

#include "lk.h"
#if NLK > 0
int	lk201_lopen(), lk201_lclose(), lk201_input(), lk201_ioctl();
#endif

struct	linesw linesw[] =
{
	ttyopen, ttylclose, ttread, ttwrite, nullioctl,	/* 0- OTTYDISC */
	ttyinput, nodev, nulldev, ttstart, ttymodem,
#if NBK > 0
	bkopen, bkclose, bkread, ttwrite, bkioctl,	/* 1- NETLDISC */
	bkinput, nodev, nulldev, ttstart, nullmodem,
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
	ttyopen, ttylclose, ttread, ttwrite, nullioctl,	/* 2- NTTYDISC */
	ttyinput, nodev, nulldev, ttstart, ttymodem,
#if NTB > 0
	tbopen, tbclose, tbread, nodev, tbioctl,
	tbinput, nodev, nulldev, ttstart, nullmodem,	/* 3- TABLDISC */
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
#if NSL > 0
	slopen, slclose, nodev, nodev, sltioctl,
	slinput, nodev, nulldev, slstart, slmodem,	/* 4- SLIPDISC */
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
#if NPPP > 0
	pppasync_topen, pppasync_tclose, nodev, nodev, pppasync_tioctl,
	pppasync_input, nodev, nulldev, pppasync_start, /* 5- PPPDISC */
	pppasync_modem,
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
#if NLK > 0
	lk201_lopen, lk201_lclose, ttread, ttwrite, lk201_ioctl,
	lk201_input, nodev, nulldev, ttstart, nullmodem,/* 6- LK201DISC */
#else
	nodev, nodev, nodev, nodev, nodev,
	nodev, nodev, nodev, nodev, nodev,
#endif
};

int	nldisp = sizeof (linesw) / sizeof (linesw[0]);

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
}
