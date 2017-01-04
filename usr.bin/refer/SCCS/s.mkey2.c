h50470
s 00007/00002/00143
d D 4.2 88/04/24 17:05:50 bostic 2 1
c fixes for ANSI C
e
s 00145/00000/00000
d D 4.1 83/05/06 23:47:39 tut 1 0
c date and time created 83/05/06 23:47:39 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 500

static int eof = 0;
static long lp, lim;
static int alph, used, prevc;
static char *p, key[20];

dofile(f, name)
FILE *f;
char *name;
{
	/* read file f & spit out keys & ptrs */

	char line[MAXLINE], *s;
D 2
	extern int minlen, keycount, labels;
E 2
I 2
	extern int keycount;
E 2
	int c;
	long grec();
	extern int wholefile;
D 2
	extern char *iglist;
E 2
	alph=used=prevc=eof=0;

	lp=0;
	if (wholefile==0)
		while (lim = grec(line,f))
		{
# if D1
			fprintf(stderr, "line: /%s",line);
# endif
			used=alph=0;
			p = key;
			for(s=line; (c= *s) && (used<keycount); s++)
				chkey(c, name);
			lp += lim;
			if (used) putchar('\n');
		}
	else
	{
		p=key;
		used=alph=0;
		while ( (c=getc(f)) != EOF && used<keycount)
			chkey (c, name);
		if (used) putchar('\n');
	}
	fclose(f);
}

outkey( ky, lead, trail)
char *ky;
{
I 2
	extern int minlen;
E 2
	int n;
	n = strlen(ky);
	if (n<minlen) return (0);
	if (n<3)
	{
		if (trail == '.') return(0);
		if (mindex(".%,!#$%&'();+:*", lead)!=0) return(0);
	}
	if (isdigit(ky[0]))
		if (ky[0] != '1' || ky[1] != '9' || n!= 4) return(0);
	if (common(ky))
		return(0);
	return(1);
}

long
grec (s, f)
char *s;
FILE *f;
{
	char tm[200];
	int curtype = 0;
	long len = 0L, tlen = 0L;
	extern int wholefile;
I 2
	extern char *iglist;

E 2
	if (eof) return(0);
	*s = 0;
	while (fgets(tm, 200, f))
	{
		tlen += strlen(tm);
		if (tm[0] == '%' || tm[0] == '.')
			curtype = tm[1];
		if (tlen < MAXLINE && mindex(iglist,curtype)==0)
			strcat(s, tm);
		len = tlen;
		if (wholefile==0 && tm[0] == '\n')
			return(len);
		if (wholefile>0 && len >= MAXLINE)
		{
			fseek (f, 0L, 2);
			return(ftell(f));
		}
	}
	eof=1;
	return(s[0] ? len : 0L);
}

char *
trimnl(ln)
char *ln;
{
	register char *p = ln;
	while (*p) p++;
	p--;
	if (*p == '\n') *p=0;
	return(ln);
}

chkey (c, name)
{
I 2
	extern int labels;
	extern int wholefile;

E 2
	if (isalpha(c) || isdigit(c))
	{
		if (alph++ < 6)
			*p++ = c;
	}
	else
	{
		*p = 0;
		for(p=key; *p; p++)
			*p |= 040;
		if (outkey(p=key,prevc,c))
		{
			if (used==0)
			{
				if (labels)
				{
					if (wholefile==0)
						printf("%s:%ld,%ld\t", name, lp, lim);
					else
						printf("%s\t", name);
				}
			}
			else
				putchar(' ');
			fputs(key, stdout);
			used++;
		}
		prevc=c;
		alph=0;
	}
}
E 1
