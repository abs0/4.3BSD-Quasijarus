h56135
s 00006/00001/00148
d D 7.2 04/03/18 19:15:25 msokolov 9 8
c make resuba return ENXIO on sans-UBA machines instead of stopping kernel
c build with an unresolved external
e
s 00001/00001/00148
d D 7.1 86/06/05 00:48:15 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00142
d D 6.4 85/06/08 13:46:16 mckusick 7 6
c Add copyright
e
s 00014/00014/00129
d D 6.3 84/08/28 18:10:44 bloom 6 5
c Change to includes.  No more ../h
e
s 00001/00000/00142
d D 6.2 83/11/26 19:01:39 sam 5 4
c must never have been compiled for tracing
e
s 00000/00000/00142
d D 6.1 83/07/29 07:21:19 sam 4 3
c 4.2 distribution
e
s 00001/00001/00141
d D 4.3 83/06/21 20:36:47 sam 3 2
c NOCOMPAT->COMPAT
e
s 00004/00003/00138
d D 4.2 83/06/13 03:01:59 sam 2 1
c a couple that got away
e
s 00141/00000/00000
d D 4.1 83/05/27 13:49:01 sam 1 0
c date and time created 83/05/27 13:49:01 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

D 6
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/ioctl.h"
#include "../h/file.h"
#include "../h/proc.h"
#include "../h/uio.h"
#include "../h/kernel.h"
#include "../h/mtio.h"
#include "../h/buf.h"
I 5
#include "../h/trace.h"
E 6
I 6
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "file.h"
#include "proc.h"
#include "uio.h"
#include "kernel.h"
#include "mtio.h"
#include "buf.h"
#include "trace.h"
E 6
E 5

D 6
#include "../vax/dkio.h"
#include "../vax/pte.h"
E 6
I 6
#include "dkio.h"
#include "pte.h"
E 6
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"

I 9
#include "uba.h"

E 9
resuba()
{
D 9

E 9
I 9
#if NUBA
E 9
	if (suser())
	if (u.u_arg[0] < numuba)
		ubareset(u.u_arg[0]);
I 9
#else
	u.u_error = ENXIO;
#endif
E 9
}

#ifdef TRACE
int	nvualarm;

vtrace()
{
	register struct a {
		int	request;
		int	value;
	} *uap;
	int vdoualarm();

	uap = (struct a *)u.u_ap;
	switch (uap->request) {

	case VTR_DISABLE:		/* disable a trace point */
	case VTR_ENABLE:		/* enable a trace point */
		if (uap->value < 0 || uap->value >= TR_NFLAGS)
			u.u_error = EINVAL;
		else {
			u.u_r.r_val1 = traceflags[uap->value];
			traceflags[uap->value] = uap->request;
		}
		break;

	case VTR_VALUE:		/* return a trace point setting */
		if (uap->value < 0 || uap->value >= TR_NFLAGS)
			u.u_error = EINVAL;
		else
			u.u_r.r_val1 = traceflags[uap->value];
		break;

	case VTR_UALARM:	/* set a real-time ualarm, less than 1 min */
		if (uap->value <= 0 || uap->value > 60 * hz ||
		    nvualarm > 5)
			u.u_error = EINVAL;
		else {
			nvualarm++;
			timeout(vdoualarm, (caddr_t)u.u_procp->p_pid,
			    uap->value);
		}
		break;

	case VTR_STAMP:
		trace(TR_STAMP, uap->value, u.u_procp->p_pid);
		break;
	}
}

vdoualarm(arg)
	int arg;
{
	register struct proc *p;

	p = pfind(arg);
	if (p)
		psignal(p, 16);
	nvualarm--;
}
#endif

D 3
#ifndef NOCOMPAT
E 3
I 3
#ifdef COMPAT
E 3
/*
 * Note: these tables are sorted by
 * ioctl "code" (in ascending order).
 */
int dctls[] = { DKIOCHDR, 0 };
int fctls[] = { FIOCLEX, FIONCLEX, FIOASYNC, FIONBIO, FIONREAD, 0 };
int mctls[] = { MTIOCTOP, MTIOCGET, 0 };
int tctls[] = {
	TIOCGETD, TIOCSETD, TIOCHPCL, TIOCMODG, TIOCMODS,
	TIOCGETP, TIOCSETP, TIOCSETN, TIOCEXCL, TIOCNXCL,
	TIOCFLUSH,TIOCSETC, TIOCGETC, TIOCREMOTE,TIOCMGET,
	TIOCMBIC, TIOCMBIS, TIOCMSET, TIOCSTART,TIOCSTOP,
D 2
	TIOCPKT,  TIOCNOTTY,TIOCGLTC, TIOCSLTC, TIOCSPGRP,
	TIOCGPGRP,TIOCCDTR, TIOCSDTR, TIOCCBRK, TIOCSBRK,
	TIOCLGET, TIOCLSET, TIOCLBIC, TIOCLBIS, 0
E 2
I 2
	TIOCPKT,  TIOCNOTTY,TIOCSTI,  TIOCOUTQ, TIOCGLTC,
	TIOCSLTC, TIOCSPGRP,TIOCGPGRP,TIOCCDTR, TIOCSDTR,
	TIOCCBRK, TIOCSBRK, TIOCLGET, TIOCLSET, TIOCLBIC,
	TIOCLBIS, 0
E 2
};

/*
 * Map an old style ioctl command to new.
 */
mapioctl(cmd)
	int cmd;
{
	register int *map, c;

	switch ((cmd >> 8) & 0xff) {

	case 'd':
		map = dctls;
		break;

	case 'f':
		map = fctls;
		break;

	case 'm':
		map = mctls;
		break;

	case 't':
		map = tctls;
		break;

	default:
		return (0);
	}
	while ((c = *map) && (c&0xff) < (cmd&0xff))
		map++;
	if (c && (c&0xff) == (cmd&0xff))
		return (c);
	return (0);
}
#endif
E 1
