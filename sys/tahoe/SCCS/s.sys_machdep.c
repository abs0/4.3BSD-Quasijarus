h37796
s 00019/00014/00118
d D 7.1 88/05/21 18:36:28 karels 2 1
c bring up to revision 7 for tahoe release
e
s 00132/00000/00000
d D 1.1 86/01/05 18:47:46 sam 1 0
c date and time created 86/01/05 18:47:46 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

D 2
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
E 2
I 2
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
E 2

D 2
#include "../machine/dkio.h"
#include "../machine/pte.h"
E 2
I 2
#include "pte.h"
E 2

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

#ifdef COMPAT
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
	TIOCPKT,  TIOCNOTTY,TIOCSTI,  TIOCOUTQ, TIOCGLTC,
	TIOCSLTC, TIOCSPGRP,TIOCGPGRP,TIOCCDTR, TIOCSDTR,
	TIOCCBRK, TIOCSBRK, TIOCLGET, TIOCLSET, TIOCLBIC,
	TIOCLBIS, 0
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
