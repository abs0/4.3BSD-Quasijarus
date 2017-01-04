h44828
s 00002/00001/00020
d D 1.2 81/03/07 16:01:42 mckusic 2 1
c merge in onyx changes
e
s 00021/00000/00000
d D 1.1 80/10/30 00:35:08 mckusick 1 0
c date and time created 80/10/30 00:35:08 by mckusick
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
RELTGE(bytecnt, left, right)

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
		if ((*right++ & ~*left++) != 0) 
			return FALSE;
	} while (--longcnt);
	return TRUE;
}
E 1
