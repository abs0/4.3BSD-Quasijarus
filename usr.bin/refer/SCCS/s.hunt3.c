h07948
s 00003/00001/00047
d D 4.2 83/06/28 23:27:02 tut 2 1
c improved error message when query is longer than 250 chars.
e
s 00048/00000/00000
d D 4.1 83/05/06 23:47:18 tut 1 0
c date and time created 83/05/06 23:47:18 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include "refer..c"
#define BSIZ 250

getq(v)
char *v[];
{
	static char buff[BSIZ];
	static int eof = 0;
	extern char *sinput;
	char *p;
	int c, n = 0, las = 0;
	if (eof) return(-1);
	p = buff;
	while ( (c = (sinput ? *sinput++ : getchar()) ) > 0)
	{
		if (c== '\n')
			break;
		if (isalpha(c) || isdigit(c))
		{
			if (las==0)
			{
				v[n++] = p;
				las=1;
			}
			if (las++ <= 6)
				*p++ = c;
		}
		else
		{
			if (las>0)
				*p++ = 0;
			las=0;
		}
	}
	*p=0;
D 2
	assert(p<buff+BSIZ);
E 2
I 2
	if (p > buff + BSIZ)
		fprintf(stderr, "query long than %d characters\n", BSIZ);
	assert(p < buff + BSIZ);
E 2
	if (sinput==0 && c<= 0) eof=1;
# if D1
	fprintf(stderr, "no. keys %d\n",n);
	for(c=0; c<n; c++)
		fprintf(stderr, "keys X%sX\n", v[c]);
# endif
	return(n);
}
E 1
