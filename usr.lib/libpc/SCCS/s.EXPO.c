h54090
s 00015/00003/00009
d D 1.2 81/03/07 15:55:27 mckusic 2 1
c merge in onyx changes
e
s 00012/00000/00000
d D 1.1 80/10/30 00:33:10 mckusick 1 0
c date and time created 80/10/30 00:33:10 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 2
long
E 2
EXPO(value)

D 2
	long	value;
E 2
I 2
	double	value;
E 2
{
D 2
	if (value == 0)
E 2
I 2
	register int retval;
	register char *cp;
	char sign, buf[30];
	extern char *index();

	if (value == 0.0)
E 2
		return 0;
D 2
	return ((value & ~0xffff8000) >> 7) - 128;
E 2
I 2
	sprintf(buf, "%.1e", value);
	cp = index(buf, 'e') + 1;
	sign = *cp++;
	retval = 0;
	while (*cp)
		retval = retval * 10 + *cp++ - '0';
	return sign == '-' ? -retval : retval;
E 2
}
E 1
