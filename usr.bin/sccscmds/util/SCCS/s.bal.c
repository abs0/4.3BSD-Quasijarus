h33791
s 00003/00003/00031
d D 1.2 87/02/15 16:19:37 lepreau 2 1
c modern syntax for asgops and inits; sccs keywords
e
s 00034/00000/00000
d D 1.1 87/02/15 16:16:43 lepreau 1 0
c date and time created 87/02/15 16:16:43 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)bal	2.1";
#
E 2
I 2
static char Sccsid[] = "%W%	%G%";

E 2
/*
	Function to find the position, in str, of the first of the char-
	acters in end occurring outside a balanced string.  A balanced string
	contains matched occurrences of any character in open and the corres-
	ponding character in clos.  Balanced strings may be nested.  The null
	at the end of str is considered to belong to end.  Unmatched members
	of open or clos result in an error return.
*/

#define ifany(x) for (p=x; *p; p++) if (c == *p)
#define matching_clos clos[p-open]
#define error -1
#define position s-str-1

balbrk(str,open,clos,end)
char *str,*open,*clos,*end;
{
	register char *p, *s, c;
	char opp[2];
	opp[1] = '\0';
	for (s = str; c = *s++;  ) {
		ifany(end) return position;
		ifany(clos) return error;
		ifany(open) {
			opp[0] = matching_clos;
D 2
			s =+ balbrk(s,open,clos,opp);
E 2
I 2
			s += balbrk(s,open,clos,opp);
E 2
			if (*s++ != matching_clos) return error;
			break;
		}
	}
	return position;
}
E 1
