h39832
s 00043/00000/00000
d D 4.1 82/12/25 10:46:44 sam 1 0
c date and time created 82/12/25 10:46:44 by sam
e
u
U
t
T
I 1
/*	%W%	%G%	*/

/*
 * sqrt(a^2 + b^2)
 *	(but carefully)
 */

double sqrt();
double
hypot(a,b)
double a,b;
{
	double t;
	if(a<0) a = -a;
	if(b<0) b = -b;
	if(a > b) {
		t = a;
		a = b;
		b = t;
	}
	if(b==0) return(0.);
	a /= b;
	/*
	 * pathological overflow possible
	 * in the next line.
	 */
	return(b*sqrt(1. + a*a));
}

struct	complex
{
	double	r;
	double	i;
};

double
cabs(arg)
struct complex arg;
{
	double hypot();

	return(hypot(arg.r, arg.i));
}
E 1
