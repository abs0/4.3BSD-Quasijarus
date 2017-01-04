h18995
s 00001/00001/00035
d D 1.2 87/02/15 16:08:57 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00036/00000/00000
d D 1.1 87/02/15 16:03:39 lepreau 1 0
c date and time created 87/02/15 16:03:39 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)userdir	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Gets user's login directory.
	The argument must be an integer.
	Note the assumption about position of directory field in
	password file (no group id in password file).
	Returns pointer to login directory on success,
	0 on failure.
        Remembers user ID and login directory for subsequent calls.
*/

userdir(uid)
register int uid;
{
	char pw[200];
	static int ouid;
	static char ldir[33];
	register int i;
	register char *cp;

	if (ouid!=uid || ouid==0) {
		if (getpw(uid,pw))
			return(0);
		cp = pw;
		while (*cp++ != ':') ; /* login name */
		while (*cp++ != ':') ; /* passwd */
		while (*cp++ != ':') ; /* user ID */
		while (*cp++ != ':') ; /* comment */
		for (i=0; i<32; i++) {
			if ((ldir[i] = *cp)=='\0' || *cp==':') break;
			cp++;
		}
		ldir[i] = '\0';
	}
	return(ldir);
}
E 1
