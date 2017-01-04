h03685
s 00001/00001/00030
d D 1.2 87/02/15 16:09:02 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00031/00000/00000
d D 1.1 87/02/15 16:03:41 lepreau 1 0
c date and time created 87/02/15 16:03:41 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)username	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Gets user's login name.
	Note that the argument must be an integer.
	Returns pointer to login name on success,
	pointer to string representation of used ID on failure.

	Remembers user ID and login name for subsequent calls.
*/

username(uid)
register int uid;
{
	char pw[200];
	static int ouid;
	static char lnam[9], *lptr;
	register int i;

	if (ouid!=uid || ouid==0) {
		if (getpw(uid,pw))
			sprintf(lnam,"%d",uid);
		else {
			for (i=0; i<8; i++)
				if ((lnam[i] = pw[i])==':') break;
			lnam[i] = '\0';
		}
		lptr = lnam;
		ouid = uid;
	}
	return(lptr);
}
E 1
