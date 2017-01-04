h12760
s 00004/00000/00086
d D 4.3 85/09/14 16:25:20 bloom 3 2
c lint fixes
e
s 00003/00001/00083
d D 4.2 83/08/11 21:14:53 sam 2 1
c standardize sccs keyword lines
e
s 00084/00000/00000
d D 4.1 83/02/12 19:06:43 shannon 1 0
c date and time created 83/02/12 19:06:43 by shannon
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 2

 /* tb.c: check which entries exist, also storage allocation */
# include "t..c"
checkuse()
{
int i,c, k;
for(c=0; c<ncol; c++)
	{
	used[c]=lused[c]=rused[c]=0;
	for(i=0; i<nlin; i++)
		{
		if (instead[i] || fullbot[i]) continue;
		k = ctype(i,c);
		if (k== '-' || k == '=') continue;
		if ((k=='n'||k=='a'))
			{
			rused[c]|= real(table[i][c].rcol);
			if( !real(table[i][c].rcol))
			used[c] |= real(table[i][c].col);
			if (table[i][c].rcol)
			lused[c] |= real(table[i][c].col);
			}
		else
			used[c] |= real(table[i][c].col);
		}
	}
}
real(s)
	char *s;
{
if (s==0) return(0);
if (!point(s)) return(1);
if (*s==0) return(0);
return(1);
}
int spcount = 0;
extern char * calloc();
# define MAXVEC 20
char *spvecs[MAXVEC];
I 3

char *
E 3
chspace()
{
char *pp;
if (spvecs[spcount])
	return(spvecs[spcount++]);
if (spcount>=MAXVEC)
	error("Too many characters in table");
spvecs[spcount++]= pp = calloc(MAXCHS+200,1);
if (pp== -1 || pp == 0)
	error("no space for characters");
return(pp);
}
# define MAXPC 50
char *thisvec;
int tpcount = -1;
char *tpvecs[MAXPC];
I 3

int *
E 3
alocv(n)
{
int *tp, *q;
if (tpcount<0 || thisvec+n > tpvecs[tpcount]+MAXCHS)
	{
	tpcount++;
	if (tpvecs[tpcount]==0)
		{
		tpvecs[tpcount] = calloc(MAXCHS,1);
		}
	thisvec = tpvecs[tpcount];
	if (thisvec == -1)
		error("no space for vectors");
	}
tp=thisvec;
thisvec+=n;
for(q=tp; q<thisvec; q++)
	*q=0;
return(tp);
}
release()
{
extern char *exstore;
/* give back unwanted space in some vectors */
spcount=0;
tpcount= -1;
exstore=0;
}
E 1
