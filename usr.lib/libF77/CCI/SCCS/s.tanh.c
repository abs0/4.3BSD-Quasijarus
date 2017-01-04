h37048
s 00031/00000/00000
d D 5.1 86/11/03 20:00:13 mckusick 1 0
c from CCI
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

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
