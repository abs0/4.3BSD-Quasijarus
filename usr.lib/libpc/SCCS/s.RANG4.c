h07411
s 00002/00002/00016
d D 1.4 82/11/12 18:58:41 mckusick 4 3
c make error message global var, so routine can be inline expanded
e
s 00001/00002/00017
d D 1.3 81/06/10 00:43:45 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00004/00003/00015
d D 1.2 81/03/07 16:00:10 mckusic 2 1
c merge in onyx changes
e
s 00018/00000/00000
d D 1.1 80/10/30 00:34:35 mckusick 1 0
c date and time created 80/10/30 00:34:35 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 4
char ERANG[] = "Value of %D is out of range\n";
E 4
D 3
#include "h01errs.h"
E 3

I 2
long
E 2
RANG4(value, lower, upper)
D 4

E 4
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
	if (value < lower || value > upper) {
D 3
		ERROR(ERANGE, value);
E 3
I 3
D 4
		ERROR("Value of %D is out of range\n", value);
E 4
I 4
		ERROR(ERANG, value);
E 4
E 3
		return;
	}
	return	value;
}
E 1
