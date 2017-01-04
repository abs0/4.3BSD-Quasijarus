h54252
s 00002/00001/00028
d D 1.2 81/03/07 16:01:49 mckusic 2 1
c merge in onyx changes
e
s 00029/00000/00000
d D 1.1 80/10/30 00:35:11 mckusick 1 0
c date and time created 80/10/30 00:35:11 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

I 2
bool
E 2
RELTGT(bytecnt, left, right)

D 2
	int		bytecnt;
E 2
I 2
	long		bytecnt;
E 2
	register long	*left;
	register long	*right;
{
	register int	longcnt;

	longcnt = bytecnt >> 2;
	do	{
		if ((*right & ~*left) != 0)
			return FALSE;
		if ((*left++ & ~*right++) != 0)
			goto geq;
	} while (--longcnt);
	return FALSE;
geq:
	while (--longcnt) {
		if ((*right++ & ~*left++) != 0) 
			return FALSE;
	}
	return TRUE;
}
E 1
