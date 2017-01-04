h37085
s 00003/00001/00517
d D 1.7 84/05/24 18:51:32 slatteng 7 6
c added unbordered polygons
e
s 00021/00000/00497
d D 1.6 84/04/13 16:43:52 slatteng 6 5
c added polygons and stipples
e
s 00013/00025/00484
d D 1.5 84/01/18 14:44:51 slatteng 5 4
c removed "graphics generation character" capability, and fixed bug in
c using emboldening and graphics by by-passing emboldening code for graphics.
e
s 00004/00006/00505
d D 1.4 83/11/09 15:37:55 slatteng 4 3
c removed extra font directory information, removed smnt special marker
e
s 00003/00001/00508
d D 1.3 83/08/05 14:28:29 slatteng 3 2
c fix for reading in large DESC.out files uses "unsigned"
e
s 00011/00002/00498
d D 1.2 83/07/27 19:10:40 slatteng 2 1
c new graphics commands: g, t, s added
e
s 00500/00000/00000
d D 1.1 83/07/12 10:59:57 slatteng 1 0
c date and time created 83/07/12 10:59:57 by slatteng
e
u
U
t
T
I 1
#include "tdef.h"
extern
#include "d.h"
extern
#include "v.h"
/*
troff10.c

CAT interface
*/

#include <sgtty.h>
#include "ext.h"
int	vpos	 = 0;	/* absolute vertical position on page */
int	hpos	 = 0;	/* ditto horizontal */

#define	T_IESC	16

short	*chtab;
char	*chname;
char	*fontab[NFONT+1];
char	*kerntab[NFONT+1];
char	*fitab[NFONT+1];

int	Inch;
int	Hor;
int	Vert;
int	Unitwidth;
int	nfonts;
int	nsizes;
int	nchtab;
I 6
int	nstips;
int	xstip	= ~ST;
tchar *	stiplab;
E 6

/* these characters are used as various signals or values
/* in miscellaneous places.
/* values are set in specnames in t10.c
*/

int	c_hyphen;
int	c_emdash;
int	c_rule;
int	c_minus;
int	c_narsp;
int	c_hnarsp;
int	c_fi;
int	c_fl;
int	c_ff;
int	c_ffi;
int	c_ffl;
int	c_acute;
int	c_grave;
int	c_under;
int	c_rooten;
int	c_boxrule;
int	c_lefthand;

#include "dev.h"
struct dev dev;
struct font *fontbase[NFONT+1];


ptinit()
{
	int	i, fin, nw;
	char	*setbrk(), *filebase, *p;

	/* open table for device,
	/* read in resolution, size info, font info, etc.
	/* and set params
	*/
	strcat(termtab, "/dev");
	strcat(termtab, devname);
	strcat(termtab, "/DESC.out");	/* makes "..../devXXX/DESC.out" */
	if ((fin = open(termtab, 0)) < 0) {
		fprintf(stderr, "troff: can't open tables for %s\n", termtab);
		done3(1);
	}
	read(fin, &dev, sizeof(struct dev ));
	Inch = dev.res;
	Hor = dev.hor;
	Vert = dev.vert;
	Unitwidth = dev.unitwidth;
	nfonts = dev.nfonts;
	nsizes = dev.nsizes;
	nchtab = dev.nchtab;
I 6
	nstips = dev.nstips;
E 6
D 3
	filebase = setbrk(dev.filesize + 2*EXTRAFONT);	/* enough room for whole file */
E 3
I 3
			/* "unsigned" so very large files will work properly */
I 6
	stiplab = (tchar *) setbrk((nstips + 1) * sizeof(tchar));
E 6
	filebase = setbrk((unsigned short) dev.filesize + 2*EXTRAFONT);
						/* enough room for whole file */
E 3
	read(fin, filebase, dev.filesize);	/* all at once */
	pstab = (short *) filebase;
	chtab = pstab + nsizes + 1;
	chname = (char *) (chtab + dev.nchtab);
	p = chname + dev.lchname;
	for (i = 1; i <= nfonts; i++) {
		fontbase[i] = (struct font *) p;
		nw = *p & BMASK;	/* 1st thing is width count */
		fontlab[i] = PAIR(fontbase[i]->namefont[0], fontbase[i]->namefont[1]);
		/* for now, still 2 char names */
D 4
		if (smnt == 0 && fontbase[i]->specfont == 1)
			smnt = i;	/* first special font */
E 4
		p += sizeof(struct font);	/* that's what's on the beginning */
		fontab[i] = p;
		kerntab[i] = p + nw;
		fitab[i] = p + 3 * nw;	/* skip width, kern, code */
		p += 3 * nw + dev.nchtab + 128 - 32;
	}
I 6
	for (i = 1; i <= nstips; i++) {		/* make stipple names tchars */
		stiplab[i] = PAIR(*p, *(p+1));
		while (*(p++));
	}
E 6
	fontbase[0] = (struct font *) p;	/* the last shall be first */
	fontbase[0]->nwfont = EXTRAFONT - dev.nchtab - (128-32) - sizeof (struct font);
	fontab[0] = p + sizeof (struct font);
	close(fin);
	/* there are a lot of things that used to be constant
	/* that now require code to be executed.
	*/
	sps = SPS;
	ics = ICS;
	for (i = 0; i < 16; i++)
		tabtab[i] = DTAB * (i + 1);
	pl = 11 * INCH;
	po = PO;
	spacesz = SS;
	lss = lss1 = VS;
	ll = ll1 = lt = lt1 = LL;
	specnames();	/* install names like "hyphen", etc. */
	if (ascii)
		return;
	fprintf(ptid, "x T %s\n", devname);
	fprintf(ptid, "x res %d %d %d\n", Inch, Hor, Vert);
	fprintf(ptid, "x init\n");	/* do initialization for particular device */
	for (i = 1; i <= nfonts; i++)
		fprintf(ptid, "x font %d %s\n", i, fontbase[i]->namefont);
  /*
	fprintf(ptid, "x xxx fonts=%d sizes=%d unit=%d\n", nfonts, nsizes, Unitwidth);
	fprintf(ptid, "x xxx nchtab=%d lchname=%d nfitab=%d\n",
		dev.nchtab, dev.lchname, dev.nchtab+128-32);
	fprintf(ptid, "x xxx sizes:\nx xxx ");
	for (i = 0; i < nsizes; i++)
		fprintf(ptid, " %d", pstab[i]);
	fprintf(ptid, "\nx xxx chars:\nx xxx ");
	for (i = 0; i < dev.nchtab; i++)
		fprintf(ptid, " %s", &chname[chtab[i]]);
	fprintf(ptid, "\nx xxx\n");
  */
}

specnames()
{
	static struct {
		int	*n;
		char	*v;
	} spnames[] = {
		&c_hyphen, "hy",
		&c_emdash, "em",
		&c_rule, "ru",
		&c_minus, "\\-",
		&c_narsp, "\\|",
		&c_hnarsp, "\\^",
		&c_fi, "fi",
		&c_fl, "fl",
		&c_ff, "ff",
		&c_ffi, "Fi",
		&c_ffl, "Fl",
		&c_acute, "aa",
		&c_grave, "ga",
		&c_under, "ul",
		&c_rooten, "rn",
		&c_boxrule, "br",
		&c_lefthand, "lh",
		0, 0
	};
	int	i;

	for (i = 0; spnames[i].n; i++)
		*spnames[i].n = findch(spnames[i].v);
}

findch(s)	/* find char s in chname */
register char	*s;
{
	register int	i;

	for (i = 0; i < nchtab; i++)
		if (strcmp(s, &chname[chtab[i]]) == 0)
			return(i + 128);
	return(0);
}

ptout(i)
tchar	i;
{
	register dv, ik;
	register tchar	*k;
	int	temp, a, b;

	if (cbits(i) != '\n') {
		*olinep++ = i;
		return;
	}
	if (olinep == oline) {
		lead += lss;
		return;
	}

	hpos = po;	/* ??? */
	esc = 0;	/* ??? */
	ptesc();	/* the problem is to get back to the left end of the line */
	dv = 0;
	for (k = oline; k < olinep; k++) {
		if (ismot(*k) && isvmot(*k)) {
			temp = absmot(*k);
			if (isnmot(*k))
				temp = -temp;
			dv += temp;
		}
	}
	if (dv) {
		vflag++;
		*olinep++ = makem(-dv);
		vflag = 0;
	}

	b = dip->blss + lss;
	lead += dip->blss + lss;
	dip->blss = 0;
	for (k = oline; k < olinep; )
		k += ptout0(k);	/* now passing a pointer! */
	olinep = oline;
	lead += dip->alss;
	a = dip->alss;
	dip->alss = 0;
	/*
	fprintf(ptid, "x xxx end of line: hpos=%d, vpos=%d\n", hpos, vpos);
*/
	fprintf(ptid, "n%d %d\n", b, a);	/* be nice to chuck */
}

ptout0(pi)
tchar	*pi;
{
	register short j, k, w;
	short	z, dx, dy, dx2, dy2, n;
	tchar	i;
	int outsize;	/* size of object being printed */

	outsize = 1;	/* default */
	i = *pi;
	k = cbits(i);
	if (ismot(i)) {
		j = absmot(i);
		if (isnmot(i))
			j = -j;
		if (isvmot(i))
			lead += j;
		else 
			esc += j;
		return(outsize);
	}
	if (k == CHARHT) {
		fprintf(ptid, "x H %d\n", sbits(i));
		return(outsize);
	}
	if (k == SLANT) {
		fprintf(ptid, "x S %d\n", sfbits(i)-180);
		return(outsize);
	}
	if (k == WORDSP) {
		oput('w');
		return(outsize);
	}
	if (k == FONTPOS) {
		char temp[3];
		n = i >> 16;
		temp[0] = n & BMASK;
		temp[1] = n >> BYTE;
		temp[2] = 0;
D 4
		ptfpcmd(0, temp, 0);
E 4
I 4
		ptfpcmd(0, temp);
E 4
		return(outsize);
	}
	xbitf = 2;
	if (sfbits(i) == oldbits) {
		xfont = pfont;
		xpts = ppts;
		xbitf = 0;
	} else 
		xbits(i);
	if (k < 040 && k != DRAWFCN)
		return(outsize);
	w = getcw(k - 32);
	j = z = 0;
	if (k != DRAWFCN) {
		if (cs) {
			if (bd)
				w += (bd - 1) * HOR;
			j = (cs - w) / 2;
			w = cs - j;
			if (bd)
				w -= (bd - 1) * HOR;
		}
		if (iszbit(i)) {
			if (cs)
				w = -j; 
			else 
				w = 0;
			z = 1;
		}
	}
	esc += j;
	if (xfont != mfont)
		ptfont();
	if (xpts != mpts)
		ptps();
	if (lead)
		ptlead();
	/* put out the real character here */
	if (k == DRAWFCN) {
		if (esc)
			ptesc();
D 5
		dx = absmot(pi[3]);
		if (isnmot(pi[3]))
E 5
I 5
		dx = absmot(pi[2]);
		if (isnmot(pi[2]))
E 5
			dx = -dx;
D 5
		dy = absmot(pi[4]);
		if (isnmot(pi[4]))
E 5
I 5
		dy = absmot(pi[3]);
		if (isnmot(pi[3]))
E 5
			dy = -dy;
		switch (cbits(pi[1])) {
		case DRAWCIRCLE:	/* circle */
			fprintf(ptid, "D%c %d\n", DRAWCIRCLE, dx);	/* dx is diameter */
D 5
			w = 0;
E 5
			hpos += dx;
			break;
I 2
		case DRAWSTYLE:
			fprintf(ptid, "D%c %d\n", DRAWSTYLE, dx);
D 5
			w = 0;
E 5
			break;
		case DRAWTHICK:
			fprintf(ptid, "D%c %d\n", DRAWTHICK, dx);
D 5
			w = 0;
E 5
			break;
E 2
		case DRAWELLIPSE:
			fprintf(ptid, "D%c %d %d\n", DRAWELLIPSE, dx, dy);
D 5
			w = 0;
E 5
			hpos += dx;
			break;
		case DRAWLINE:	/* line */
D 5
			k = cbits(pi[2]);
			fprintf(ptid, "D%c %d %d ", DRAWLINE, dx, dy);
			if (k < 128)
				fprintf(ptid, "%c\n", k);
			else
				fprintf(ptid, "%s\n", &chname[chtab[k - 128]]);
			w = 0;
E 5
I 5
			fprintf(ptid, "D%c %d %d\n", DRAWLINE, dx, dy);
E 5
			hpos += dx;
			vpos += dy;
			break;
		case DRAWARC:	/* arc */
D 5
			dx2 = absmot(pi[5]);
			if (isnmot(pi[5]))
E 5
I 5
			dx2 = absmot(pi[4]);
			if (isnmot(pi[4]))
E 5
				dx2 = -dx2;
D 5
			dy2 = absmot(pi[6]);
			if (isnmot(pi[6]))
E 5
I 5
			dy2 = absmot(pi[5]);
			if (isnmot(pi[5]))
E 5
				dy2 = -dy2;
			fprintf(ptid, "D%c %d %d %d %d\n", DRAWARC,
				dx, dy, dx2, dy2);
D 5
			w = 0;
E 5
			hpos += dx + dx2;
			vpos += dy + dy2;
			break;
D 2
		case DRAWWIG:	/* wiggly line */
			fprintf(ptid, "D%c %d %d", DRAWWIG, dx, dy);
E 2
I 2
		case DRAWWIG:	/* wiggly line  -or- */
		case DRAWCURVE:	/* gremlin-style curve */
			fprintf(ptid, "D%c %d %d", cbits(pi[1]), dx, dy);
E 2
D 5
			w = 0;
E 5
			hpos += dx;
			vpos += dy;
I 6
writecoords:
E 6
D 5
			for (n = 5; cbits(pi[n]) != '.'; n += 2) {
E 5
I 5
			for (n = 4; cbits(pi[n]) != '.'; n += 2) {
E 5
				dx = absmot(pi[n]);
				if (isnmot(pi[n]))
					dx = -dx;
				dy = absmot(pi[n+1]);
				if (isnmot(pi[n+1]))
					dy = -dy;
				fprintf(ptid, " %d %d", dx, dy);
				hpos += dx;
				vpos += dy;
			}
			fprintf(ptid, "\n");
			break;
I 7

E 7
I 6
		case DRAWPOLY:	/* polygon with stipple */
I 7
		case DRAWUBPOLY:/* polygon, stipple, no border */
E 7
			if (xstip != stip) ptstip();
D 7
			fprintf(ptid, "D%c %d", DRAWPOLY, dx);
E 7
I 7
			fprintf(ptid, "D%c %d", cbits(pi[1]), dx);
E 7
			goto writecoords;
E 6
		}
D 5
		for (n = 3; cbits(pi[n]) != '.'; n++)
E 5
I 5
		for (n = 2; cbits(pi[n]) != '.'; n++)
E 5
			;
D 5
		outsize = n + 1;
	} else if (k < 128) {
E 5
I 5
		return(n + 1);		/* leave here so the emboldening */
	} else if (k < 128) {		/* doesn't screw up the graphics */
E 5
		/* try to go faster and compress output */
		/* by printing nnc for small positive motion followed by c */
		/* kludgery; have to make sure set all the vars too */
		if (esc > 0 && esc < 100) {
			oput(esc / 10 + '0');
			oput(esc % 10 + '0');
			oput(k);
			hpos += esc;
			esc = 0;
		} else {
			if (esc)
				ptesc();
			fprintf(ptid, "c%c\n", k);
		}
	} else {
		if (esc)
			ptesc();
		fprintf(ptid, "C%s\n", &chname[chtab[k - 128]]);
	}
	if (bd) {
		bd -= HOR;
		if (esc += bd)
			ptesc();
		if (k < 128) {
			fprintf(ptid, "c%c\n", k);
		} else
			fprintf(ptid, "C%s\n", &chname[chtab[k - 128]]);
		if (z)
			esc -= bd;
	}
	esc += w;
	return(outsize);
}

ptps()
{
	register i, j, k;

	i = xpts;
	for (j = 0; i > (k = pstab[j]); j++)
		if (!k) {
			k = pstab[--j];
			break;
		}
	fprintf(ptid, "s%d\n", k);	/* really should put out string rep of size */
	mpts = i;
}
I 6

ptstip()
{
	xstip = stip;
	fprintf(ptid, "i%d\n", xstip);
}

E 6

ptfont()
{
	mfont = xfont;
	fprintf(ptid, "f%d\n", xfont);
}

D 4
ptfpcmd(f, s, d)
E 4
I 4
ptfpcmd(f, s)
E 4
int	f;
D 4
char	*s, *d;
E 4
I 4
char	*s;
E 4
{
	if (ascii)
		return;
D 4
	fprintf(ptid, "x font %d %s %s\n", f, s, d==0 ? "" : d);
E 4
I 4
	fprintf(ptid, "x font %d %s\n", f, s);
E 4
	ptfont();	/* make sure that it gets noticed */
}

ptlead()
{
	vpos += lead;
	if (!ascii)
		fprintf(ptid, "V%d\n", vpos);
	lead = 0;
}

ptesc()
{
	hpos += esc;
	if (esc > 0)
		fprintf(ptid, "h%d", esc);
	else
		fprintf(ptid, "H%d\n", hpos);
	esc = 0;
}

newpage(n)	/* called at end of each output page (we hope) */
{
	ptlead();
	vpos = 0;
	if (ascii)
		return;
	flusho();
	fprintf(ptid, "p%d\n", n);	/* new page */
	ptps();
	ptfont();
}

pttrailer()
{
	fprintf(ptid, "x trailer\n");
}

ptstop()
{
	fprintf(ptid, "x stop\n");
}

dostop()
{
	if (ascii)
		return;
	ptlead();
	vpos = 0;
	/*	fprintf(ptid, "x xxx end of page\n");*/
	if (!nofeed)
		pttrailer();
	ptlead();
	fprintf(ptid, "x pause\n");
	flusho();
	mpts = mfont = 0;
	paper = 0;
	esc = T_IESC;	/* this is a dreg */
	ptesc();
	esc = po;
	hpos = vpos = 0;	/* probably in wrong place */
}
E 1
