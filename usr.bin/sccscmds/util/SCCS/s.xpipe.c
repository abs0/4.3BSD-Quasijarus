h41756
s 00002/00002/00014
d D 1.2 87/02/15 16:19:42 lepreau 2 1
c modern syntax for asgops and inits; sccs keywords
e
s 00016/00000/00000
d D 1.1 87/02/15 16:16:45 lepreau 1 0
c date and time created 87/02/15 16:16:45 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)xpipe	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Interface to pipe(II) which handles all error conditions.
	Returns 0 on success,
	fatal() on failure.
*/

xpipe(t)
int *t;
{
D 2
	static char p[] "pipe";
E 2
I 2
	static char p[] = "pipe";
E 2

	if (pipe(t) == 0)
		return(0);
	return(xmsg(p,p));
}
E 1
