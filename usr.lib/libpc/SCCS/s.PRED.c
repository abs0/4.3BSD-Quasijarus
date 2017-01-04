h05977
s 00000/00001/00023
d D 1.4 81/06/10 00:39:33 mckusic 4 3
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00005/00001/00019
d D 1.3 81/06/08 00:36:02 mckusic 3 2
c put in better error messages
e
s 00004/00003/00016
d D 1.2 81/03/07 15:59:36 mckusic 2 1
c merge in onyx changes
e
s 00019/00000/00000
d D 1.1 80/10/30 00:34:28 mckusick 1 0
c date and time created 80/10/30 00:34:28 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 4
#include "h01errs.h"
E 4

I 2
long
E 2
PRED(value, lower, upper)

D 2
	int	value;
	int	lower;
	int	upper;
E 2
I 2
	long	value;
	long	lower;
	long	upper;
E 2
{
I 3
	if (value == lower) {
		ERROR("Cannot take pred of first element of a range\n");
		return;
	}
E 3
	value--;
	if (value < lower || value > upper) {
D 3
		ERROR(ERANGE, value);
E 3
I 3
		ERROR("Value of %D is out of range\n", value);
E 3
		return;
	}
	return	value;
}
E 1
