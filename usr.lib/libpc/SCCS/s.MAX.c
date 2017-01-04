h19902
s 00001/00002/00020
d D 1.4 81/06/10 00:38:35 mckusic 4 3
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00001/00001/00021
d D 1.3 81/03/10 13:01:27 mckusic 3 2
c make widths == 0 illegal
e
s 00004/00003/00018
d D 1.2 81/03/07 15:57:54 mckusic 2 1
c merge in onyx changes
e
s 00021/00000/00000
d D 1.1 80/10/30 00:33:47 mckusick 1 0
c date and time created 80/10/30 00:33:47 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"
D 4
#include "h01errs.h"
E 4

I 2
long
E 2
MAX(width, reduce, min)

D 2
	register int	width;		/* requested width */
	int		reduce;		/* amount of extra space required */
	int		min;		/* minimum amount of space needed */
E 2
I 2
	register long	width;		/* requested width */
	long		reduce;		/* amount of extra space required */
	long		min;		/* minimum amount of space needed */
E 2
{
D 3
	if (width < 0) {
E 3
I 3
	if (width <= 0) {
E 3
D 4
		ERROR(EFMTSIZE, width);
E 4
I 4
		ERROR("Non-positive format width: %D\n", width);
E 4
		return;
	}
	if ((width -= reduce) >= min)
		return width;
	return min;
}
E 1
