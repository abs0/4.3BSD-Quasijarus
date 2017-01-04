h33969
s 00021/00000/00000
d D 1.1 82/02/08 20:33:10 mckusick 1 0
c date and time created 82/02/08 20:33:10 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1982 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include <math.h>
extern int errno;

double
COS(value)
	double	value;
{
	double result;

	errno = 0;
	result = cos(value);
	if (errno != 0) {
		ERROR("Cannot compute cos(%e)\n", value);
		return;
	}
	return result;
}
E 1
