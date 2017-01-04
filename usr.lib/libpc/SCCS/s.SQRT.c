h55728
s 00001/00002/00016
d D 1.3 81/06/10 00:44:22 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00002/00001/00016
d D 1.2 80/11/20 03:02:04 mckusic 2 1
c put in include for <math.h> so they will return doubles
e
s 00017/00000/00000
d D 1.1 80/10/30 00:35:46 mckusick 1 0
c date and time created 80/10/30 00:35:46 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 3
#include "h01errs.h"
E 3
I 2
#include <math.h>
E 2

double
SQRT(value)

	double	value;
{
D 2
	if (value <= 0) {
E 2
I 2
	if (value < 0) {
E 2
D 3
		ERROR(ESQRT, value);
E 3
I 3
		ERROR("Negative argument of %e to sqrt\n", value);
E 3
		return;
	}
	return sqrt(value);
}
E 1
