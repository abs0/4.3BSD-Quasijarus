h61278
s 00001/00002/00016
d D 1.4 81/06/10 00:38:30 mckusic 4 3
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00001/00000/00017
d D 1.3 81/01/06 12:04:23 mckusic 3 2
c include math.h to insure correct return type
e
s 00000/00000/00017
d D 1.2 80/11/20 03:02:13 mckusic 2 1
c put in include for <math.h> so they will return doubles
e
s 00017/00000/00000
d D 1.1 80/10/30 00:33:45 mckusick 1 0
c date and time created 80/10/30 00:33:45 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 3
#include <math.h>
E 3
D 4
#include "h01errs.h"
E 4

double
LN(value)

	double	value;
{
	if (value <= 0) {
D 4
		ERROR(ELN, value);
E 4
I 4
		ERROR("Non-positive argument of %e to ln\n", value);
E 4
		return;
	}
	return log(value);
}
E 1
