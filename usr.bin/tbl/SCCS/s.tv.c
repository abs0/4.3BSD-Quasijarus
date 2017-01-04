h34024
s 00003/00001/00149
d D 4.3 83/08/11 21:15:57 sam 3 2
c standardize sccs keyword lines
e
s 00001/00000/00149
d D 4.2 83/02/12 19:16:32 shannon 2 1
c *0 fixes for sun
e
s 00149/00000/00000
d D 4.1 83/02/12 19:07:09 shannon 1 0
c date and time created 83/02/12 19:07:09 by shannon
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

 /* tv.c: draw vertical lines */
# include "t..c"
drawvert(start,end, c, lwid)
{
char *exb=0, *ext=0;
int tp=0, sl, ln, pos, epb, ept, vm;
end++;
vm='v';
/* note: nr 35 has value of 1m outside of linesize */
while (instead[end]) end++;
for(ln=0; ln<lwid; ln++)
	{
	epb=ept=0;
	pos = 2*ln-lwid+1;
	if (pos!=tp) fprintf(tabout, "\\h'%dp'", pos-tp);
	tp = pos;
	if (end<nlin)
		{
		if (fullbot[end]|| (!instead[end] && allh(end)))
			epb=2;
		else
		switch (midbar(end,c))
			{
			case '-':
			exb = "1v-.5m"; break;
			case '=':
			exb = "1v-.5m";
			epb = 1; break;
			}
		}
	if (lwid>1)
	switch(interh(end, c))
		{
		case THRU: epb -= 1; break;
		case RIGHT: epb += (ln==0 ? 1 : -1); break;
		case LEFT: epb += (ln==1 ? 1 : -1); break;
		}
	if (lwid==1)
	switch(interh(end,c))
		{
		case THRU: epb -= 1; break;
		case RIGHT: case LEFT: epb += 1; break;
		}
	if (start>0)
		{
		sl = start-1;
		while (sl>=0 && instead[sl]) sl--;
		if (sl>=0 && (fullbot[sl] || allh(sl)))
			ept=0;
		else
		if (sl>=0)
		switch(midbar(sl,c))
			{
			case '-':
			ext = ".5m"; break;
			case '=':
			ext= ".5m"; ept = -1; break;
			default:
				vm = 'm'; break;
			}
		else
			ept = -4;
		}
	else if (start==0 && allh(0))
		{
		ept=0;
		vm = 'm';
		}
	if (lwid>1)
		switch(interh(start,c))
			{
			case THRU: ept += 1; break;
			case LEFT: ept += (ln==0 ? 1 : -1); break;
			case RIGHT: ept += (ln==1 ? 1 : -1); break;
			}
	else if (lwid==1)
		switch(interh(start,c))
			{
			case THRU: ept += 1; break;
			case LEFT: case RIGHT: ept -= 1; break;
			}
	if (exb)
		fprintf(tabout, "\\v'%s'", exb);
	if (epb)
		fprintf(tabout, "\\v'%dp'", epb);
	fprintf(tabout, "\\s\\n(%d",LSIZE);
	if (linsize)
		fprintf(tabout, "\\v'-\\n(%dp/6u'", LSIZE);
	fprintf(tabout, "\\h'-\\n(#~u'"); /* adjustment for T450 nroff boxes */
	fprintf(tabout, "\\L'|\\n(#%cu-%s", linestop[start]+'a'-1, vm=='v'? "1v" : "\\n(35u");
	if (ext)
		fprintf(tabout, "-(%s)",ext);
	if (exb)
		fprintf(tabout, "-(%s)", exb);
	pos = ept-epb;
	if (pos)
		fprintf(tabout, "%s%dp", pos>=0? "+" : "", pos);
	/* the string #d is either "nl" or ".d" depending
	   on diversions; on GCOS not the same */
	fprintf(tabout, "'\\s0\\v'\\n(\\*(#du-\\n(#%cu+%s", linestop[start]+'a'-1,vm=='v' ? "1v" : "\\n(35u");
	if (ext)
		fprintf(tabout, "+%s",ext);
	if (ept)
		fprintf(tabout, "%s%dp", (-ept)>0 ? "+" : "", (-ept));
	fprintf(tabout, "'");
	if (linsize)
		fprintf(tabout, "\\v'\\n(%dp/6u'", LSIZE);
	}
}


midbar(i,c)
{
int k;
k = midbcol(i,c);
if (k==0 && c>0)
	k = midbcol(i, c-1);
return(k);
}
midbcol(i,c)
{
int ct;
while ( (ct=ctype(i,c)) == 's')
	c--;
if (ct=='-' || ct == '=')
	return(ct);
if (ct=barent(table[i][c].col))
	return(ct);
return(0);
}

barent(s)
	char *s;
{
if (s==0) return (1);
I 2
if (!point(s)) return(1);
E 2
if (s[0]== '\\') s++;
if (s[1]!= 0)
	return(0);
switch(s[0])
	{
	case '_':
		return('-');
	case '=':
		return('=');
	}
return(0);
}
E 1
