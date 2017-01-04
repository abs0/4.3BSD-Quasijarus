h46814
s 00005/00002/00016
d D 1.2 81/03/07 16:01:24 mckusic 2 1
c merge in onyx changes
e
s 00018/00000/00000
d D 1.1 80/10/30 00:35:02 mckusick 1 0
c date and time created 80/10/30 00:35:02 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

D 2
RELSLE(size, str1, str2)
E 2
I 2
bool
RELSLE(siz, str1, str2)
E 2

D 2
	register int	size;
E 2
I 2
	long		siz;
E 2
	register char	*str1;
	register char	*str2;
{
I 2
	register int size = siz;

E 2
	while (*str1++ == *str2++ && --size)
		/* void */;
	if ((size == 0) || (*--str1 <= *--str2))
		return TRUE;
	return FALSE;
}
E 1
