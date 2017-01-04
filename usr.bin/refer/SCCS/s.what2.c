h21581
s 00009/00009/00232
d D 4.2 87/09/11 08:15:10 bostic 2 1
c get rid of old assignment operators
e
s 00241/00000/00000
d D 4.1 83/05/06 23:50:15 tut 1 0
c date and time created 83/05/06 23:50:15 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include "stdio.h"
#include "ctype.h"
#define NS 5

struct sf {
	char *text;
	int olap;
} 
sents[NS];
struct sf *sp;
char stext[NS][500];

describe (file, argc, argv, rf)
char *file, *argv[];
FILE *rf;
{
D 2
	int ns 0;
E 2
I 2
	int ns = 0;
E 2
	char linbuf[BUFSIZ], *line, *p;
D 2
	int i, wrflg 0, wrote 0, ln 0;
E 2
I 2
	int i, wrflg = 0, wrote = 0, ln = 0;
E 2
	FILE *fi;
	fi = fopen(file, "r");
	if (fi==NULL) return;
	for(i=1; i<argc; i++)
		lcase(argv[i]);
	while (gsent(linbuf, BUFSIZ, fi))
	{
		wrote=0;
		for(line=linbuf; *line==' '; line++);
		if (line[0]==0) continue;
		for(p=line; *p; p++)
			if (*p=='\t') *p= ' ';
		if (wrflg && line[0]=='.' && isupper(line[1]))
			wrflg=0;
		if (wrflg)
		{
			output(line, ln, rf);
			wrote=1;
		}
		if (prefix(".TL", line))
			wrflg=1;
		if (prefix(".AU", line))
			wrflg = ln = 1;
		if (prefix(".DA", line) || prefix(".ND", line))
			output(line+4, 1, rf);
		if (line[0]=='.')
			continue;
		if (wrote) continue;
		ns=update(ns, line, count(line,argc,argv));
	}
	fclose(fi);
	for(sp=sents; sp<sents+ns; sp++)
		output(sp->text, 0, rf);
}

D 2
int state 0;
int oldc '\n';
E 2
I 2
int state = 0;
int oldc = '\n';
E 2

gsent(buf, bsize, fi)
char *buf;
FILE *fi;
{
	char *s;
D 2
	int c, leng 0;
E 2
I 2
	int c, leng = 0;
E 2
	/* state
		0: looking for '.' 
		1: looking for nl or space aftter '.'
		2: looking for nl after line with dot.
		*/
	s=buf;
	if (state==2)
		*s++='.';
	while ( (c = getc(fi)) > 0 )
	{
		switch(state)
		{
		case 0: /* normal */
			if (c=='.' && oldc == '\n')
			{
				*s=0;
				state=2;
				oldc='\n';
				return(1);
			}
			*s++ = (c=='\n'? ' ': c);
			if (s>=buf+bsize)
			{
				*--s = 0;
				return(1);
			}
			if (c=='.' || c == '?' || c=='!')
				if (leng>1)
					state=1;
			leng = (isalpha(c) ? leng+1 : 0);
			break;
		case 1: /* found ., want nl or space */
			if (c==' ' || c == '\n')
			{
				*s=0;
				state=0;
				oldc=c;
				return(1);
			}
			*s++ = (c=='\n' ? ' ' : c);
			state=0;
			leng = 0;
			break;
		case 2: /* found trof line, want nl */
			if (c == '\n')
			{
				*s=0;
				state=0;
				oldc='\n';
				return(1);
			}
			*s++ = c;
			break;
		}
		oldc=c;
	}
	*s=0;
	return(0);
}

prefix( p, s)
char *p, *s;
{
	int c;
	while ( (c= *p++) == *s++)
		if (c==0)
			return(1);
	return(c==0);
}

output (s, ln, rf)
char *s;
FILE *rf;
{
	char *t;
D 2
	int more 1;
E 2
I 2
	int more = 1;
E 2
	t=s;
	while (more)
	{
		while (t<s+72 && *t)
			t++;
		if (*t)
		{
			while (*t != ' ' && t>(s+25))
				t--;
			*t=0;
			more=1;
		}
		else
			more=0;
		printf("%s%s\n",ln++ ? "     " : "   ", s);
		if (rf!=NULL)
			fprintf(rf, "%s\n", s);
		s= ++t;
	}
}

count(isent, nw, wds)
char *wds[], *isent;
{
	int saw[50], ct;
D 2
	char sb[BUFSIZ], *s sb;
E 2
I 2
	char sb[BUFSIZ], *s = sb;
E 2
	int i, c;
	for(i=1; i<nw; i++)
		saw[i]=0;
	while (c = *isent++)
	{
		*s++ = isupper(c) ? tolower(c) : c;
	}
	*s=0;
	s=sb;
	while (*s++)
	{
		if (s[-1]!=' ') continue;
		for(i=1; i<nw; i++)
		{
			if (saw[i])continue;
			if (prefix(wds[i], s))
				saw[i]=1;
		}
	}
	ct=0;
	for(i=1; i<nw; i++)
		if (saw[i])
			ct++;
	return(ct);
}

lcase(s)
char *s;
{
	register int c;
	for(; c= *s; s++)
	{
		if (isupper(c))
			*s= tolower(c);
	}
}

update( ns, line, kov)
char *line;
{
	/* see if sentence array should be updated */
D 2
	int lval 100; 
E 2
I 2
	int lval = 100;
E 2
	char *ob;
D 2
	struct sf *sp, *least NULL;
E 2
I 2
	struct sf *sp, *least = NULL;
E 2
	if (kov<=0) return (ns) ; /* no*/
	if (ns<NS)
	{
		sp=sents+ns;
		strcpy (sp->text = stext[ns], line);
		sp->olap = kov;
		return(ns+1);
	}
	for(sp=sents+ns-1; sp>=sents; sp--)
	{
		if (sp->olap < lval)
		{
			least = sp;
			lval = sp->olap;
		}
	}
	if (kov <= lval) return(ns);
	ob = least->text;
	while (++least < sents+NS)
	{
		(least-1)->text = least->text;
		(least-1)->olap = least->olap;
	}
	sp = sents+NS-1;
	strcpy (sp->text=ob, line);
	sp->olap = kov;
	return(NS);
}
E 1
