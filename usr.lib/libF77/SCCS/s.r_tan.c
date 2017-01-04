h05229
s 00075/00000/00014
d D 5.3 86/11/03 21:20:16 mckusick 4 3
c update for tahope
e
s 00001/00001/00013
d D 5.2 85/07/08 14:30:37 jerry 3 2
c declare function as float, not double.
e
s 00005/00001/00009
d D 5.1 85/06/07 22:28:53 kre 2 1
c Add copyright
e
s 00010/00000/00000
d D 1.1 83/01/21 11:18:38 dlw 1 0
c date and time created 83/01/21 11:18:38 by dlw
e
u
U
t
T
I 1
/*
D 2
 *	"%W%"
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 2
 */

I 4
#ifndef tahoe
E 4
D 3
double r_tan(x)
E 3
I 3
float r_tan(x)
E 3
float *x;
{
double tan();
return( tan(*x) );
}
I 4

#else tahoe

/*
	SINGLE PRECISION floating point tangent

	sin/cos is used after argument reduction to [0,pi/4] range.
	since x is in this range, tan(x) is in [0,1] range and
	no overflow can occur here.
*/

#include <errno.h>

int	errno;
static double invpi = 1.27323954473516268;  /* 4/pi */

float
r_tan(parg)
float *parg;
{
	double arg;
	fortran float sin(), cos();
	double modf();
	float flmax_();
	double temp, e, x, xsq;
	int sign;
	int flag, i;

	arg = *parg;
	flag = 0;
	sign = 1.;
	if(arg < 0.){		/* tan(-arg) = -tan(arg) */
		arg = -arg;
		sign = -1.;
	}
	arg = arg*invpi;   /*overflow?*/
	x = modf(arg,&e);
	i = e;
	switch(i%4) {
	case 1:			/* 2nd octant: tan(x) = 1/tan(1-x) */
		x = 1. - x;
		flag = 1;
		break;

	case 2:			/* 3rd octant: tan(x) = -1/tan(x) */
		sign = - sign;
		flag = 1;
		break;

	case 3:			/* 4th octant: tan(x) = -tan(1-x) */
		x = 1. - x;
		sign = - sign;
		break;

	case 0:			/* 1st octant */
		break;
	}
	x = x/invpi;

	temp = sin(x)/cos(x);

	if(flag == 1) {
		if(temp == 0.) {	/* check for singular "point" */
			errno = ERANGE;
			if (sign>0)
				return(flmax_());
			return(-flmax_());
		}
		temp = 1./temp;
	}
	return(sign*temp);
}

#endif tahoe
E 4
E 1
