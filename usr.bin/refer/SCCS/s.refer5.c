h30534
s 00005/00002/00322
d D 4.8 87/07/06 16:46:37 bostic 9 7
c bug report 4.2BSD/usr.bin/14
e
s 00005/00002/00322
d R 4.8 87/06/23 11:42:16 bostic 8 7
c bug report 4.2BSD/usr.bin/14
e
s 00012/00006/00312
d D 4.7 86/04/23 18:19:13 mckusick 7 6
c fix sequencing numbers (from Keith Muller)
e
s 00010/00005/00308
d D 4.6 86/03/10 13:38:04 mckusick 6 5
c increase size of refer data structures (from muller@nprdc.arpa (Keith Muller))
e
s 00001/00001/00312
d D 4.5 85/08/26 19:13:40 mckusick 5 4
c fix syntax errors
e
s 00002/00002/00311
d D 4.4 84/06/05 16:45:35 ralph 4 3
c fix problem with dup references and -e -s options.
e
s 00001/00001/00312
d D 4.3 84/02/15 15:42:43 ralph 3 2
c fix key letter so ^A, ^B, etc. isn't generated.
e
s 00026/00010/00287
d D 4.2 83/07/18 14:18:38 mckusick 2 1
c presotto fixes for -k (full reference) switch
e
s 00297/00000/00000
d D 4.1 83/05/06 23:30:12 tut 1 0
c date and time created 83/05/06 23:30:12 by tut
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
#define SAME 0
D 6
#define NFLAB 2000
#define NLABC 100
E 6
I 6
#define NFLAB 3000		/* number of bytes to record all labels */
#define NLABC 1000		/* max number of labels */
D 7
#define MXSIG 200		/* max bytes in aggregate signal */
E 7
E 6

D 6
static char sig[NLABC];
E 6
I 6
static char sig[MXSIG];
E 6
static char bflab[NFLAB];
static char *labtab[NLABC];
static char *lbp = bflab;
static char labc[NLABC];
static char stbuff[50];
static int  prevsig;

D 4
putsig (nf, flds, nref, nstline, endline)	/* choose signal style */
E 4
I 4
putsig (nf, flds, nref, nstline, endline, toindex)   /* choose signal style */
E 4
char *flds[], *nstline, *endline;
{
D 6
	char t[100], t1[100], t2[100], format[10], *sd, *stline;
E 6
I 6
	char t[100], t1[MXSIG], t2[100], format[10], *sd, *stline;
E 6
	int addon, another = 0;
	static FILE *fhide = 0;
I 2
	int i;
	char tag;
E 2

	if (labels) {
		if (nf == 0)	/* old */
			sprintf(t, "%s%c", labtab[nref], labc[nref]);
		else {
			*t = 0;
			if (keywant)
				sprintf(t, "%s", fpar(nf,flds,t1,keywant,1,0));
			if (science && t[0] == 0) {
				sd = fpar(nf, flds, t2, 'D', 1, 0);
				sprintf(t, "%s, %s", fpar(nf,flds,t1,'A',1,0),
					sd);
			}
			else if (t[0] == 0) {
				sprintf(format,
					nmlen>0 ? "%%.%ds%%s" : "%%s%%s",
					nmlen);
				/* format is %s%s for default labels */
				/* or %.3s%s eg if wanted */
				sd = fpar(nf, flds, t2, 'D', 1, 0);
				if (dtlen > 0) {
					char *sdb;
					for (sdb = sd; *sd; sd++)
						;
					sd = sd - dtlen;
					if (sd < sdb)
						sd = sdb;
				}
				sprintf(t, format, fpar(nf,flds,t1,'A',1,0),
					sd);
			}
			if (keywant) {
				addon = 0;
				for (sd = t; *sd; sd++)
					;
				if (*--sd == '-') {
					addon = 1;
					*sd = 0;
				}
			}
D 2
			if (!keywant || addon)
				if (!science)
					addch(t, keylet(t, nref));
E 2
I 2
			if ((!keywant || addon) && !science) {
			    addch(t, keylet(t, nref));
			}
			else {
			    tokeytab (t,nref);
			}
E 2
		}
	}
	else {
D 7
		if (sort)
			sprintf(t, "%c%d%c", FLAG, nref, FLAG);
		else
			sprintf(t, "%d", nref);
E 7
I 7
		sprintf(t, "%c%d%c", FLAG, nref, FLAG);
E 7
	}
	another = prefix (".[", sd=lookat());
	if (another && (strcmp(".[\n", sd) != SAME))
		fprintf(stderr, "File %s line %d: punctuation ignored from: %s",
			Ifile, Iline, sd);
I 6
	if ((strlen(sig) + strlen(t)) > MXSIG)
		err("sig overflow (%d)", MXSIG);
E 6
	strcat(sig, t);
#if EBUG
	fprintf(stderr, "sig is now %s leng %d\n",sig,strlen(sig));
#endif
	trimnl(nstline);
	trimnl(endline);
	stline = stbuff;
	if (prevsig == 0) {
		strcpy (stline, nstline);
		prevsig=1;
	}
	if (stline[2] || endline[2]) {
		stline += 2;
		endline += 2;
	}
	else {
		stline  = "\\*([.";
		endline = "\\*(.]";
	}
	if (science) {
		stline = " (";
		endline = ")";
	}
	if (bare == 0) {
		if (!another) {
			sprintf(t1, "%s%s\%s\n", stline, sig, endline);
I 6
			if (strlen(t1) > MXSIG)
				err("t1 overflow (%d)", MXSIG);
E 6
			append(t1);
			flout();
			sig[0] = 0;
			prevsig = 0;
			if (fo == fhide) {
				int ch;
				fclose(fhide); 
				fhide = fopen(hidenam, "r");
				fo = ftemp;
				while ((ch = getc(fhide)) != EOF)
					putc(ch, fo);
				fclose(fhide);
				unlink(hidenam);
			}
		}
		else {
D 7
			strcat(sig, ",\\|");
E 7
I 7
			if (labels) {
				strcat(sig, ",\\|");
			} else {
				/*
				 * Seperate reference numbers with AFLAG
				 * for later sorting and condensing.
				 */
				t1[0] = AFLAG;
				t1[1] = '\0';
				strcat(sig, t1);
			}
E 7
			if (fo == ftemp) {	/* hide if need be */
				sprintf(hidenam, "/tmp/rj%dc", getpid());
#if EBUG
				fprintf(stderr, "hiding in %s\n", hidenam);
#endif
				fhide = fopen(hidenam, "w");
				if (fhide == NULL)
					err("Can't get scratch file %s",
D 5
						(void) hidenam);
E 5
I 5
						hidenam);
E 5
				fo = fhide;
			}
		}
	}
	if (bare < 2)
D 4
		if (nf > 0)
E 4
I 4
		if (nf > 0 && toindex)
E 4
			fprintf(fo,".ds [F %s%c",t,sep);
	if (bare > 0)
		flout();
#if EBUG
	fprintf(stderr, "sig is now %s\n",sig);
#endif
}

char *
fpar (nf, flds, out, c, seq, prepend)
char *flds[], *out;
{
	char *p, *s;
	int i, fnd = 0;

	for(i = 0; i < nf; i++)
D 9
		if (flds[i][1] == c && ++fnd >= seq) {
E 9
I 9
		/* following if statement modified to cope with Q authors */
		if ((flds[i][1] == c || (c == 'A' && flds[i][1] == 'Q'))
		    && ++fnd >= seq) {
			c = flds[i][1];
E 9
			/* for titles use first word otherwise last */
D 9
			if (c == 'T' || c == 'J') {
E 9
I 9
			if (c == 'T' || c == 'J' || c == 'Q') {
E 9
				p = flds[i]+3;
				if (prefix("A ", p))
					p += 2;
				if (prefix("An ", p))
					p += 3;
				if (prefix("The ", p))
					p += 4;
				mycpy2(out, p, 20);
				return(out);
			}
D 2
			for(s = p = flds[i]+2; *p; p++);
			while (p > s && *p != ' ')
				p--;
E 2
I 2
			/* if its not 'L' then use just the last word */
			s = p = flds[i]+2;
			if (c != 'L') {
			    for(; *p; p++);
			    while (p > s && *p != ' ')
				    p--;
			}
E 2
			/* special wart for authors */
			if (c == 'A' && (p[-1] == ',' || p[1] =='(')) {
				p--;
				while (p > s && *p != ' ')
					p--;
				mycpy(out, p+1);
			}
			else
				strcpy(out, p+1);
			if (c == 'A' && prepend)
				initadd(out, flds[i]+2, p);
			return(out);
		}
	return(0);
}

putkey(nf, flds, nref, keystr)
char *flds[], *keystr;
{
	char t1[50], *sf;
	int ctype, i, count;

	fprintf(fo, ".\\\"");
	if (nf <= 0)
		fprintf(fo, "%s%c%c", labtab[nref], labc[nref], sep);
	else {
		while (ctype = *keystr++) {
			count = atoi(keystr);
			if (*keystr=='+')
				count=999;
			if (count <= 0)
				count = 1;
			for(i = 1; i <= count; i++) {
				sf = fpar(nf, flds, t1, ctype, i, 1);
				if (sf == 0)
					break;
				sf = artskp(sf);
				fprintf(fo, "%s%c", sf, '-');
			}
		}
		fprintf(fo, "%c%d%c%c", FLAG, nref, FLAG, sep);
	}
}

I 2

tokeytab (t, nref)
char *t;
{
	strcpy(labtab[nref]=lbp, t);
	while (*lbp++)
		;
}

E 2
keylet(t, nref)
char *t;
{
	int i;
D 2
	int x = 'a'-1;
E 2
I 2
D 3
	int x = -1;
E 3
I 3
	int x = 'a' - 1;
E 3
E 2

	for(i = 1; i < nref; i++) {
		if (strcmp(labtab[i], t) == 0)
			x = labc[i];
	}
D 2
	strcpy(labtab[nref]=lbp, t);
	while (*lbp++)
		;
E 2
I 2
	tokeytab (t, nref);
E 2
	if (lbp-bflab > NFLAB)
		err("bflab overflow (%d)", NFLAB);
	if (nref > NLABC)
		err("nref in labc overflow (%d)", NLABC);
#if EBUG
D 6
	fprintf(stderr, "lbp up to %d of 2000\n", lbp-bflab);
E 6
I 6
	fprintf(stderr, "lbp up to %d of %d\n", lbp-bflab, NFLAB);
E 6
#endif
	return(labc[nref] = x+1);
}

mycpy(s, t)
char *s, *t;
{
	while (*t && *t != ',' && *t != ' ')
		*s++ = *t++;
	*s = 0;
}

mycpy2(s, t, n)
char *s, *t;
{
	int c;

	while (n-- && (c= *t++) > 0) {
		if (c == ' ')
			c = '-';
		*s++ = c;
	}
	*s = 0;
}

initadd(to, from, stop)
char *to, *from, *stop;
{
	int c, nalph = 1;

	while (*to)
		to++;
	while (from < stop) {
		c = *from++;
		if (!isalpha(c)) {
			if (nalph)
				*to++ = '.';
			nalph = 0;
			continue;
		}
		if (nalph++ == 0)
			*to++ = c;
	}
	*to = 0;
}

static char *articles[] = {
	"the ", "an ", "a ", 0
};

char *
artskp(s)	/* skips over initial "a ", "an ", "the " in s */
char *s;
{

	char **p, *r1, *r2;

	for (p = articles; *p; p++) {
		r2 = s;
		for (r1 = *p; ((*r1 ^ *r2) & ~040 ) == 0; r1++)
			r2++;
		if (*r1 == 0 && *r2 != 0)
			return(r2);
	}
	return(s);
}
E 1
