h36772
s 00001/00001/00009
d D 1.2 87/02/15 16:08:59 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00010/00000/00000
d D 1.1 87/02/15 16:03:40 lepreau 1 0
c date and time created 87/02/15 16:03:40 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)userexit	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Default userexit routine for fatal and setsig.
	User supplied userexit routines can be used for logging.
*/

userexit(code)
{
	return(code);
}
E 1
