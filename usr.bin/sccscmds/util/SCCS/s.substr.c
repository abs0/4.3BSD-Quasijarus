h06199
s 00001/00001/00026
d D 1.2 87/02/15 16:08:53 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00027/00000/00000
d D 1.1 87/02/15 16:03:37 lepreau 1 0
c date and time created 87/02/15 16:03:37 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)substr	2.2";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Place the `len' length substring of `as' starting at `as[origin]'
	in `aresult'.
	Return `aresult'.
 
  Note: The copying of as to aresult stops if either the
	specified number (len) characters have been copied,
	or if the end of as is found.
	A negative len generally guarantees that everything gets copied.
*/

char *substr(as, aresult, origin, len)
char *as, *aresult;
int origin;
register unsigned len;
{
	register char *s, *result;

	s = as + origin;
	result = aresult;
	++len;
	while (--len && (*result++ = *s++)) ;
	if (len == 0)
		*result = 0;
	return(aresult);
}
E 1
