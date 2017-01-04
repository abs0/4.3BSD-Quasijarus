h02117
s 00001/00000/00015
d D 1.5 81/03/07 16:03:45 mckusic 5 4
c merge in onyx changes
e
s 00005/00008/00010
d D 1.4 81/01/16 16:36:11 mckusic 4 3
c Rewrite the random number generator
e
s 00000/00001/00018
d D 1.3 81/01/06 12:04:16 mckusic 3 2
c include math.h to insure correct return type
e
s 00003/00000/00016
d D 1.2 80/11/20 03:02:09 mckusic 2 1
c put in include for <math.h> so they will return doubles
e
s 00016/00000/00000
d D 1.1 80/10/30 00:35:38 mckusick 1 0
c date and time created 80/10/30 00:35:38 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 2
D 4
#include <math.h>
E 4
I 4
#include "h00vars.h"
E 4
D 3
#include <math.h>
E 3

I 5
long
E 5
E 2
SEED(value)
D 4

	long	value;
E 4
I 4
	long value;
E 4
{
D 4
	static long	seed;
	long		tmp;
E 4
I 4
	long tmp;
E 4

D 4
	srand(value);
	tmp = seed;
	seed = value;
E 4
I 4
	tmp = _seed;
	_seed = value;
E 4
	return tmp;
}
E 1
