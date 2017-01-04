h33249
s 00003/00001/00068
d D 4.2 83/08/11 21:15:04 sam 2 1
c standardize sccs keyword lines
e
s 00069/00000/00000
d D 4.1 83/02/12 19:06:47 shannon 1 0
c date and time created 83/02/12 19:06:47 by shannon
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

 /* te.c: error message control, input line count */
# include "t..c"
error(s)
	char *s;
{
fprintf(stderr, "\n%s: line %d: %s\n", ifile, iline, s);
# ifdef unix
fprintf(stderr, "tbl quits\n");
exit(1);
# endif
# ifdef gcos
fprintf(stderr, "run terminated due to error condition detected by tbl preprocessor\n");
exit(0);
# endif
}
gets1(s)
	char *s;
{
char *p;
int nbl = 0;
iline++;
p=fgets(s,BUFSIZ,tabin);
while (p==0)
	{
	if (swapin()==0)
		return(0);
	p = fgets(s,BUFSIZ,tabin);
	}

while (*s) s++;
s--;
if (*s == '\n') *s-- =0;
for(nbl=0; *s == '\\' && s>p; s--)
	nbl++;
if (linstart && nbl % 2) /* fold escaped nl if in table */
	gets1(s+1);

return(p);
}
# define BACKMAX 500
char backup[BACKMAX];
char *backp = backup;
un1getc(c)
{
if (c=='\n')
	iline--;
*backp++ = c;
if (backp >= backup+BACKMAX)
	error("too much backup");
}
get1char()
{
int c;
if (backp>backup)
	c = *--backp;
else
	c=getc(tabin);
if (c== EOF) /* EOF */
	{
	if (swapin() ==0)
		error("unexpected EOF");
	c = getc(tabin);
	}
if (c== '\n')
	iline++;
return(c);
}
E 1
