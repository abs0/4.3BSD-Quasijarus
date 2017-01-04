h54268
s 00002/00001/00028
d D 1.2 81/03/07 16:02:12 mckusic 2 1
c merge in onyx changes
e
s 00029/00000/00000
d D 1.1 80/10/30 00:35:16 mckusick 1 0
c date and time created 80/10/30 00:35:16 by mckusick
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
RELTLT(bytecnt, left, right)

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
		if ((*left & ~*right) != 0)
			return FALSE;
		if ((*right++ & ~*left++) != 0)
			goto leq;
	} while (--longcnt);
	return FALSE;
leq:
	while (--longcnt) {
		if ((*left++ & ~*right++) != 0) 
			return FALSE;
	}
	return TRUE;
}
E 1
