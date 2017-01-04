h39404
s 00001/00000/00012
d D 1.3 81/03/07 16:03:02 mckusic 3 2
c merge in onyx changes
e
s 00003/00001/00009
d D 1.2 81/03/07 00:31:47 mckusic 2 1
c fix negative rounding
e
s 00010/00000/00000
d D 1.1 80/10/30 00:35:30 mckusick 1 0
c date and time created 80/10/30 00:35:30 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 3
long
E 3
ROUND(value)

	double	value;
{
D 2
	return (long)(value + 0.5);
E 2
I 2
	if (value >= 0.0)
		return (long)(value + 0.5);
	return (long)(value - 0.5);
E 2
}
E 1
