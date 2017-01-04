h38749
s 00001/00001/00012
d D 1.2 87/02/15 16:09:06 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00013/00000/00000
d D 1.1 87/02/15 16:03:44 lepreau 1 0
c date and time created 87/02/15 16:03:44 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)xunlink	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Interface to unlink(II) which handles all error conditions.
	Returns 0 on success,
	fatal() on failure.
*/

xunlink(f)
{
	if (unlink(f))
		return(xmsg(f,"xunlink"));
	return(0);
}
E 1
