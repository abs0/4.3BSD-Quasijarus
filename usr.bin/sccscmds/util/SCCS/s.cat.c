h44565
s 00001/00001/00020
d D 1.2 87/02/15 16:08:35 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00021/00000/00000
d D 1.1 87/02/15 16:03:28 lepreau 1 0
c date and time created 87/02/15 16:03:28 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)cat	2.2";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Concatenate strings.
 
	cat(destination,source1,source2,...,sourcen,0);
 
	returns destination.
*/

char *cat(dest,source)
char *dest, *source;
{
	register char *d, *s, **sp;

	d = dest;
	for (sp = &source; s = *sp; sp++) {
		while (*d++ = *s++) ;
		d--;
	}
	return(dest);
}
E 1
