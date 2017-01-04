h28212
s 00001/00001/00025
d D 1.4 82/04/12 15:21:12 mckusick 4 3
c check for less than lower bound
e
s 00001/00002/00025
d D 1.3 81/06/10 00:37:18 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00004/00003/00023
d D 1.2 81/03/07 15:51:54 mckusic 2 1
c merge in onyx changes
e
s 00026/00000/00000
d D 1.1 80/10/30 00:32:47 mckusick 1 0
c date and time created 80/10/30 00:32:47 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"
D 3
#include "h01errs.h"
E 3

D 2
ARGV(subscript, var, size)
E 2
I 2
ARGV(subscript, var, siz)
E 2

D 2
	int		subscript;	/* subscript into argv */
E 2
I 2
	long		subscript;	/* subscript into argv */
E 2
	register char	*var;		/* pointer to pascal char array */
D 2
	register int	size;		/* sizeof(var) */
E 2
I 2
	long		siz;		/* sizeof(var) */
E 2
{
	register char	*cp;
I 2
	register int	size = siz;
E 2

D 4
	if (subscript >= _argc) {
E 4
I 4
	if ((unsigned)subscript >= _argc) {
E 4
D 3
		ERROR(EARGV, subscript);
E 3
I 3
		ERROR("Argument to argv of %D is out of range\n", subscript);
E 3
		return;
	}
	cp = _argv[subscript];
	do	{
		*var++ = *cp++;
	} while (--size && *cp);
	while (size--)
		*var++ = ' ';
}
E 1
