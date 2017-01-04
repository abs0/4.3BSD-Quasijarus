h05209
s 00006/00005/00016
d D 1.2 81/03/07 15:56:52 mckusic 2 1
c merge in onyx changes
e
s 00021/00000/00000
d D 1.1 80/10/30 00:33:31 mckusick 1 0
c date and time created 80/10/30 00:33:31 by mckusick
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
IN(element, lower, upper, setptr)

D 2
	int	element;	/* element to check */
	int	lower;		/* lowest element of set */
	int	upper;		/* upper - lower of set */
E 2
I 2
	long	element;	/* element to check */
	long	lower;		/* lowest element of set */
	long	upper;		/* upper - lower of set */
E 2
	char	setptr[];	/* pointer to set */
{
D 2
	int	indx;
E 2
I 2
	register int	indx;
E 2

	if ((indx = element - lower) < 0 || indx > upper)
		return FALSE;
D 2
	if (setptr[indx / BITSPERBYTE] & (1 << (indx % BITSPERBYTE)))
E 2
I 2
	if (setptr[indx >> LG2BITSBYTE] & (1 << (indx & MSKBITSBYTE)))
E 2
		return TRUE;
	return FALSE;
}
E 1
