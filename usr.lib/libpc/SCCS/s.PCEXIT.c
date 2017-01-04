h45115
s 00029/00000/00000
d D 1.1 80/10/30 00:34:12 mckusick 1 0
c date and time created 80/10/30 00:34:12 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

PCEXIT(code)

	int	code;
{
	struct	{
		long	usr_time;
		long	sys_time;
		long	child_usr_time;
		long	child_sys_time;
		} tbuf;
	double l;

	PCLOSE(GLVL);
	PFLUSH();
	if (_stcnt > 0) {
		times(&tbuf);
		l = tbuf.usr_time;
		l = l / HZ;
		fprintf(stderr, "\n%1ld %s %04.2f seconds cpu time.\n",
				_stcnt, "statements executed in", l);
	}
	exit(code);
}
E 1
