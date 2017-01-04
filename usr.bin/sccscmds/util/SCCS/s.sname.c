h00686
s 00001/00001/00028
d D 1.2 87/02/15 16:08:50 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00029/00000/00000
d D 1.1 87/02/15 16:03:36 lepreau 1 0
c date and time created 87/02/15 16:03:36 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)sname	2.2";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Returns pointer to "simple" name of path name; that is,
	pointer to first character after last "/".  If no slashes,
	returns pointer to first char of arg.
	If the string ends in a slash, returns a pointer to the first
	character after the preceeding slash, or the first character.
*/

char	*sname(s)
char *s;
{
	register char *p;
	register int n;
	register int j;

	n = strlen(s);
	--n;
	if (s[n] == '/') {
		for (j=n; j >= 0; --j)
			if (s[j] != '/') {
				s[++j] = '\0';
				break;
			}
	}

	for(p=s; *p; p++) if(*p == '/') s = p + 1;
	return(s);
}
E 1
