h21751
s 00006/00006/00027
d D 1.2 81/03/07 15:57:05 mckusic 2 1
c merge in onyx changes
e
s 00033/00000/00000
d D 1.1 80/10/30 00:33:34 mckusick 1 0
c date and time created 80/10/30 00:33:34 by mckusick
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
INCT(element, paircnt, singcnt, data)

D 2
	register int	element;	/* element to find */
	int		paircnt;	/* number of pairs to check */
	int		singcnt;	/* number of singles to check */
	int		data;		/* paircnt plus singcnt bounds */
E 2
I 2
	register long	element;	/* element to find */
	long		paircnt;	/* number of pairs to check */
	long		singcnt;	/* number of singles to check */
	long		data;		/* paircnt plus singcnt bounds */
E 2
{
D 2
	register int	*dataptr;
E 2
I 2
	register long	*dataptr = &data;
E 2
	register int	cnt;

D 2
	dataptr = &data;
E 2
	for (cnt = 0; cnt < paircnt; cnt++) {
		if (element > *dataptr++) {
			dataptr++;
			continue;
		}
		if (element >= *dataptr++) {
			return TRUE;
		}
	}
	for (cnt = 0; cnt < singcnt; cnt++) {
		if (element == *dataptr++) {
			return TRUE;
		}
	}
	return FALSE;
}
E 1
