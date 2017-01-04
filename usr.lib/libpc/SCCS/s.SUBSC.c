h01439
s 00002/00001/00015
d D 1.4 82/11/12 18:58:57 mckusick 4 3
c make error message global var, so routine can be inline expanded
e
s 00002/00002/00014
d D 1.3 81/06/10 00:44:29 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00001/00000/00015
d D 1.2 81/03/07 16:03:57 mckusic 2 1
c merge in onyx changes
e
s 00015/00000/00000
d D 1.1 80/10/30 00:35:50 mckusick 1 0
c date and time created 80/10/30 00:35:50 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 4
char ESUBSC[] = "Subscript value of %D is out of range\n";
E 4
D 3
#include	"h01errs.h"
E 3

I 2
long
E 2
SUBSC(i, lower, upper)

	long	i, lower, upper;
{
	if (i < lower || i > upper) {
D 3
		ERROR(ESUBSC, i);
E 3
I 3
D 4
		ERROR("Subscript value of %D is out of range\n", i);
E 4
I 4
		ERROR(ESUBSC, i);
E 4
		return;
E 3
	}
	return i;
}
E 1
