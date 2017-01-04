h43046
s 00069/00021/00008
d R 4.2 85/05/23 15:17:32 miriam 2 1
c From Prof. Kahan
e
s 00029/00000/00000
d D 4.1 82/12/25 10:46:56 sam 1 0
c date and time created 82/12/25 10:46:56 by sam
e
u
U
t
T
I 1
/*	%W%	%G%	*/

/*
	tanh(arg) computes the hyperbolic tangent of its floating
	point argument.

	sinh and cosh are called except for large arguments, which
	would cause overflow improperly.
*/

double sinh(), cosh();

double
tanh(arg)
double arg;
{
	double sign;

	sign = 1.;
	if(arg < 0.){
		arg = -arg;
		sign = -1.;
	}

	if(arg > 21.)
		return(sign);

	return(sign*sinh(arg)/cosh(arg));
}
E 1
