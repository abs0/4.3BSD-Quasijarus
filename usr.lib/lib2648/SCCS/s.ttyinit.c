h43658
s 00010/00001/00056
d D 5.1 85/04/26 12:46:09 dist 2 1
c Add copyright
e
s 00057/00000/00000
d D 4.1 83/03/09 16:23:24 ralph 1 0
c date and time created 83/03/09 16:23:24 by ralph
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
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
/*
 * sgtty stuff
 */

#include <sgtty.h>

struct	sgttyb	_ttyb;
struct	tchars	_otch, _ntch;
int	_normf;

/*
 * Routines for dealing with the unix tty modes
 */

#include "2648.h"

ttyinit()
{
	if (strcmp(getenv("TERM"), "hp2648") == 0)
		_on2648 = 1;
	ioctl(fileno(stdin), TIOCGETP, &_ttyb);
	ioctl(fileno(stdin), TIOCGETC, &_otch);
	_ntch = _otch;
	_ntch.t_quitc = _ntch.t_startc = _ntch.t_stopc = -1;
	_normf = _ttyb.sg_flags;
	_ttyb.sg_flags |= CBREAK;
	_ttyb.sg_flags &= ~(ECHO|CRMOD);
	ioctl(fileno(stdin), TIOCSETN, &_ttyb);
	ioctl(fileno(stdin), TIOCSETC, &_ntch);
	gdefault();
	zoomn(1);
	zoomon();
	kon();
	rboff();
	_cursoron = 1;	/* to force it off */
	_escmode = NONE;
	curoff();
	clearg();
	gon();
	aoff();
}

done()
{
	goff();
	koff();
	aon();
	sync();
	escseq(NONE);
	lowleft();
	printf("\n");
	fflush(stdout);
	_ttyb.sg_flags = _normf;
	ioctl(fileno(stdin), TIOCSETN, &_ttyb);
	ioctl(fileno(stdin), TIOCSETC, &_otch);
}
E 1
