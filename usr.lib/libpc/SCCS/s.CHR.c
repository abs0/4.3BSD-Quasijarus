h07068
s 00004/00004/00012
d D 1.4 82/11/12 18:58:21 mckusick 4 3
c make error message global var, so routine can be inline expanded
e
s 00001/00002/00015
d D 1.3 81/06/10 00:37:26 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00002/00001/00015
d D 1.2 81/03/07 15:53:06 mckusic 2 1
c merge in onyx changes
e
s 00016/00000/00000
d D 1.1 80/10/30 00:32:56 mckusick 1 0
c date and time created 80/10/30 00:32:56 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 4
char ECHR[] = "Argument to chr of %D is out of range\n";
E 4
D 3
#include "h01errs.h"
E 3

I 2
char
E 2
CHR(value)
D 4

	long	value;
E 4
I 4
	unsigned long	value;
E 4
{
D 4
	if (value < 0 || value > 127) {
D 3
		ERROR(ECHR, value);
E 3
I 3
		ERROR("Argument to chr of %D is out of range\n", value);
E 4
I 4
	if (value > 127) {
		ERROR(ECHR, value);
E 4
E 3
		return;
	}
D 2
	return value;
E 2
I 2
	return (char)value;
E 2
}
E 1
