h08889
s 00007/00006/00010
d D 1.4 82/11/12 18:59:06 mckusick 4 3
c make error message global var, so routine can be inline expanded
e
s 00002/00002/00014
d D 1.3 81/06/10 00:44:33 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00001/00000/00015
d D 1.2 81/03/07 16:04:06 mckusic 2 1
c merge in onyx changes
e
s 00015/00000/00000
d D 1.1 80/10/30 00:35:52 mckusick 1 0
c date and time created 80/10/30 00:35:52 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 4
extern char ESUBSC[];	/* ESUBSC is defined in SUBSCZ.c */
E 4
D 3
#include	"h01errs.h"
E 3

I 2
long
E 2
D 4
SUBSCZ(i, upper)

	long	i, upper;
E 4
I 4
SUBSCZ(value, upper)
	long		value;
	unsigned long	upper;
E 4
{
D 4
	if (i < 0 || i > upper) {
D 3
		ERROR(ESUBSC, i);
E 3
I 3
		ERROR("Subscript value of %D is out of range\n", i);
E 4
I 4
	if (value > upper) {
		ERROR(ESUBSC, value);
E 4
		return;
E 3
	}
D 4
	return i;
E 4
I 4
	return value;
E 4
}
E 1
