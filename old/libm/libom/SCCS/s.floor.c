h29403
s 00032/00000/00000
d D 4.1 82/12/25 10:46:41 sam 1 0
c date and time created 82/12/25 10:46:41 by sam
e
u
U
t
T
I 1
/*	%W%	%G%	*/

/*
 * floor and ceil-- greatest integer <= arg
 * (resp least >=)
 */

double	modf();

double
floor(d)
double d;
{
	double fract;

	if (d<0.0) {
		d = -d;
		fract = modf(d, &d);
		if (fract != 0.0)
			d += 1;
		d = -d;
	} else
		modf(d, &d);
	return(d);
}

double
ceil(d)
double d;
{
	return(-floor(-d));
}
E 1
