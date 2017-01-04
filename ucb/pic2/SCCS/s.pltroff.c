h03720
s 00001/00001/00349
d D 3.2 85/08/15 16:26:39 root 4 3
c Minor asjustments in dot() so dots align better
e
s 00017/00003/00333
d D 3.1 85/07/30 15:05:49 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00125/00767/00211
d D 2.1 85/07/23 11:20:56 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00978/00000/00000
d D 1.1 85/07/19 13:59:27 jaap 1 0
c date and time created 85/07/19 13:59:27 by jaap
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (CWI) %E%";
#endif lint
I 3

E 3
D 2

/*
 *	This version has code generators to drive the old-style troff
 *	that produces output for the Graphic Systems C/A/T.  
 *	Very few people actually have a C/A/T; they instead typically
 *	use some other typesetter that simulates it.  This is slow and
 *	rather silly, but compatibility with the past is important.
 *	Or so they say.  Anyway ...

 *	The code generator can be turned on to old-style troff by setting
 *	the constant OLDTROFF with a #define statement;  this will also
 *	have the effect of setting the default typesetter to the C/A/T
 *	in a consistent manner.
 */

E 2
#include <stdio.h>
D 2
#include <ctype.h>
E 2
#include <math.h>
I 2
#include "pic.h"
E 2
extern int dbg;

D 2
/* this is the place to define OLDTROFF if you're going to */
#ifdef	OLDTROFF
#	define	MAXY	8192
#	define	MAXX	8192
#	define	OLDSTYLE	1
#else
#	define	MAXY	32768
#	define	MAXX	32768
#	define	OLDSTYLE	0
#endif

E 2
#define	abs(n)	(n >= 0 ? n : -(n))
#define	max(x,y)	((x)>(y) ? (x) : (y))
D 2
#define	PI	3.141592654
#define	PI2	PI/2
E 2

D 2
extern	int	res;
extern	int	DX;	/* step size in x */
extern	int	DY;	/* step size in y */
E 2
I 2
char	*textshift = "\\v'.2m'";	/* move text this far down */
E 2

D 2
#define	DEV202	1
#define	DEVAPS	2
#define	DEVCAT	3
#define	DEV450	4
extern	int	devtype;
int	minline	= 245;	/* draw lines shorter than this with dots on 202 */
		/* ought to be point-size dependent, but what's that? */
		/* this is big enough to handle 202 up to 36 points */
int	drawdot	= '.';	/* character to use when drawing */

int	useDline	= 0;	/* if set, produce \D for all lines */
extern	float	hshift;	/* how much to move left by for text */
extern	float	vshift;	/* how much down */

/* scaling stuff, specific to typesetter */
/* defined by s command as X0,Y0 to X1,Y1 */
E 2
I 2
/* scaling stuff defined by s command as X0,Y0 to X1,Y1 */
E 2
/* output dimensions set by -l,-w options to 0,0 to hmax, vmax */
/* default output is 6x6 inches */


float	xscale;
float	yscale;

D 2
int	hpos	= 0;	/* current horizontal position in output coordinate system */
int	vpos	= 0;	/* current vertical position; 0 is top of page */
E 2
I 2
float	hpos	= 0;	/* current horizontal position in output coordinate system */
float	vpos	= 0;	/* current vertical position; 0 is top of page */
E 2

D 2
int	htrue	= 0;	/* where we really are */
int	vtrue	= 0;
E 2
I 2
float	htrue	= 0;	/* where we really are */
float	vtrue	= 0;
E 2

float	X0, Y0;		/* left bottom of input */
float	X1, Y1;		/* right top of input */

D 2
int	hmax;		/* right end of output */
int	vmax;		/* top of output (down is positive) */
E 2
I 2
float	hmax;		/* right end of output */
float	vmax;		/* top of output (down is positive) */
E 2

extern	float	deltx;
extern	float	delty;
D 2
extern	float	xmin, ymin, xmax, ymax, sxmin, symin, sxmax, symax;
extern	int	crop;
E 2
I 2
extern	float	xmin, ymin, xmax, ymax;
E 2

I 2
float	xconv(), yconv(), xsc(), ysc();

E 2
openpl(s)	/* initialize device */
	char *s;	/* residue of .PS invocation line */
{
	float maxdelt;

	hpos = vpos = 0;
D 2
	hmax = vmax = 6 * res;	/* default = 6 x 6 */
	maxdelt = max(deltx, delty);
	if (maxdelt > 8) {	/* 8 inches */
E 2
I 2
	if (deltx > 8.5 || delty > 11) {	/* 8.5x11 inches max */
E 2
		fprintf(stderr, "pic: %g X %g picture shrunk to", deltx, delty);
D 2
		deltx *= 8/maxdelt;
		delty *= 8/maxdelt;
E 2
I 2
		maxdelt = max(deltx, delty);
		deltx *= 7/maxdelt;
		delty *= 7/maxdelt;
E 2
		fprintf(stderr, " %g X %g\n", deltx, delty);
	}
D 2
	if (deltx > 0 && delty > 0) {	/* have to change default size */
		hmax = res * deltx;
		vmax = res * delty;
	}
	if (crop) {
		if (xmax == xmin)
			space(xmin, ymin, xmin + ymax-ymin, ymax);
		else
			space(xmin, ymin, xmax, ymin + xmax-xmin);	/* assumes 1:1 aspect ratio */
	}
	else
		space(sxmin, symin, sxmax, symax);
	printf("... %g %g %g %g %g %g %g %g\n",
		xmin, ymin, xmax, ymax, sxmin, symin, sxmax, symax);
	printf("... %du %du %du %du %du %du %du %du\n",
		xconv(xmin), yconv(ymin), xconv(xmax), yconv(ymax),
		xconv(sxmin), yconv(symin), xconv(sxmax), yconv(symax));
	printf(".PS %d %d %s", yconv(ymin), xconv(xmax), s);
E 2
I 2
	space(xmin, ymin, xmax, ymax);
	printf("... %g %g %g %g\n", xmin, ymin, xmax, ymax);
	printf("... %.3fi %.3fi %.3fi %.3fi\n",
		xconv(xmin), yconv(ymin), xconv(xmax), yconv(ymax));
	printf(".nr 00 \\n(.u\n");
	printf(".nf\n");
	printf(".PS %.3fi %.3fi %s", yconv(ymin), xconv(xmax), s);
E 2
		/* assumes \n comes as part of s */
D 2
	if (xconv(xmax) >= MAXX || yconv(ymax) >= MAXY) {	/* internal troff limit: 13 bits for motion */
		fprintf(stderr, "picture too high or wide");
		exit(1);
	}
	printf(".br\n");
E 2
}

I 2
space(x0, y0, x1, y1)	/* set limits of page */
	float x0, y0, x1, y1;
{
	X0 = x0;
	Y0 = y0;
	X1 = x1;
	Y1 = y1;
	xscale = deltx == 0.0 ? 1.0 : deltx / (X1-X0);
	yscale = delty == 0.0 ? 1.0 : delty / (Y1-Y0);
}

float xconv(x)	/* convert x from external to internal form */
	float x;
{
	return (x-X0) * xscale;
}

float xsc(x)	/* convert x from external to internal form, scaling only */
	float x;
{

	return (x) * xscale;
}

float yconv(y)	/* convert y from external to internal form */
	float y;
{
	return (Y1-y) * yscale;
}

float ysc(y)	/* convert y from external to internal form, scaling only */
	float y;
{
	return (y) * yscale;
}

E 2
closepl(type)	/* clean up after finished */
I 2
	int type;
E 2
{
D 2
	movehv(0, 0);	/* get back to where we started */
E 2
I 2
	movehv(0.0, 0.0);	/* get back to where we started */
E 2
	if (type == 'F')
		printf(".PF\n");
	else {
D 2
		printf(".sp 1+%du\n", yconv(ymin));
E 2
I 2
		printf(".sp 1+%.3fi\n", yconv(ymin));
E 2
		printf(".PE\n");
	}
I 2
	printf(".if \\n(00 .fi\n");
E 2
}

move(x, y)	/* go to position x, y in external coords */
	float x, y;
{
	hgoto(xconv(x));
	vgoto(yconv(y));
}

movehv(h, v)	/* go to internal position h, v */
D 2
	int h, v;
E 2
I 2
	float h, v;
E 2
{
	hgoto(h);
	vgoto(v);
}

hmot(n)	/* generate n units of horizontal motion */
D 2
	int n;
E 2
I 2
	float n;
E 2
{
	hpos += n;
}

vmot(n)	/* generate n units of vertical motion */
D 2
	int n;
E 2
I 2
	float n;
E 2
{
	vpos += n;
}

hgoto(n)
I 2
	float n;
E 2
{
	hpos = n;
}

vgoto(n)
I 2
	float n;
E 2
{
	vpos = n;
}

hvflush()	/* get to proper point for output */
{
	if (hpos != htrue) {
D 2
		printf("\\h'%du'", hpos - htrue);
E 2
I 2
		printf("\\h'%.3fi'", hpos - htrue);
E 2
		htrue = hpos;
	}
	if (vpos != vtrue) {
D 2
		printf("\\v'%du'", vpos - vtrue);
E 2
I 2
		printf("\\v'%.3fi'", vpos - vtrue);
E 2
		vtrue = vpos;
	}
}

flyback()	/* return to upper left corner (entry point) */
{
	printf(".sp -1\n");
	htrue = vtrue = 0;
}

troff(s)	/* output troff right here */
	char *s;
{
	printf("%s\n", s);
}

label(s, t, nh)	/* text s of type t nh half-lines up */
	char *s;
	int t, nh;
{
	int q;
	char *p;

	hvflush();
D 2
	printf("\\h'-%.1fm'\\v'%.1fm'", hshift, vshift);	/* shift down and left */
			/*  .3 .3 is best for PO in circuit diagrams */
	if (t == 'A')
E 2
I 2
	dprintf("label: %s %o %d\n", s, t, nh);
	printf("%s", textshift);	/* shift down and left */
	if (t & ABOVE)
E 2
		nh++;
D 2
	else if (t == 'B')
E 2
I 2
	else if (t & BELOW)
E 2
		nh--;
	if (nh)
		printf("\\v'%du*\\n(.vu/2u'", -nh);
	/* just in case the text contains a quote: */
	q = 0;
	for (p = s; *p; p++)
		if (*p == '\'') {
			q = 1;
			break;
		}
D 2
	switch (t) {
	case 'L':
	default:
E 2
I 2
	t &= ~(ABOVE|BELOW);
	if (t & LJUST) {
E 2
		printf("%s", s);
D 2
		break;
	case 'C':
	case 'A':
	case 'B':
E 2
I 2
	} else if (t & RJUST) {
E 2
		if (q)
D 2
			printf("\\h\\(ts-\\w\\(ts%s\\(tsu/2u\\(ts%s\\h\\(ts-\\w\\(ts%s\\(tsu/2u\\(ts", s, s, s);
		else
			printf("\\h'-\\w'%s'u/2u'%s\\h'-\\w'%s'u/2u'", s, s, s);
		break;
	case 'R':
		if (q)
E 2
			printf("\\h\\(ts-\\w\\(ts%s\\(tsu\\(ts%s", s, s);
		else
			printf("\\h'-\\w'%s'u'%s", s, s);
D 2
		break;
E 2
I 2
	} else {	/* CENTER */
		if (q)
			printf("\\h\\(ts-\\w\\(ts%s\\(tsu/2u\\(ts%s\\h\\(ts-\\w\\(ts%s\\(tsu/2u\\(ts", s, s, s);
		else
			printf("\\h'-\\w'%s'u/2u'%s\\h'-\\w'%s'u/2u'", s, s, s);
E 2
	}
D 2
	/* don't need these if flyback called immediately */
E 2
	printf("\n");
	flyback();
}

line(x0, y0, x1, y1)	/* draw line from x0,y0 to x1,y1 */
	float x0, y0, x1, y1;
{
	move(x0, y0);
	cont(x1, y1);
}

D 2
arrow(x0, y0, x1, y1, w, h)	/* draw arrow (without line), head wid w & len h */
	float x0, y0, x1, y1, w, h;
E 2
I 2
arrow(x0, y0, x1, y1, w, h, ang, nhead) 	/* draw arrow (without shaft) */
	float x0, y0, x1, y1, w, h, ang;	/* head wid w, len h, rotated ang */
	int nhead;				/* and drawn with nhead lines */
E 2
{
D 2
	double alpha, rot, hyp;
E 2
I 2
	double alpha, rot, drot, hyp;
E 2
	float dx, dy;
I 2
	int i;
E 2

D 2
	rot = atan2( w / 2, h );
E 2
I 2
	rot = atan2(w / 2, h);
E 2
	hyp = sqrt(w/2 * w/2 + h * h);
D 2
	alpha = atan2(y1-y0, x1-x0);
	if (dbg)
		printf("rot=%f, hyp=%f, alpha=%f\n", rot, hyp, alpha);
	dx = hyp * cos(alpha + PI + rot);
	dy = hyp * sin(alpha + PI + rot);
	if (dbg) printf("dx,dy = %g,%g\n", dx, dy);
	line(x1+dx, y1+dy, x1, y1);
	dx = hyp * cos(alpha + PI - rot);
	dy = hyp * sin(alpha + PI - rot);
	if (dbg) printf("dx,dy = %g,%g\n", dx, dy);
	line(x1+dx, y1+dy, x1, y1);
E 2
I 2
	alpha = atan2(y1-y0, x1-x0) + ang;
	if (nhead < 2)
		nhead = 2;
	dprintf("rot=%g, hyp=%g, alpha=%g\n", rot, hyp, alpha);
	for (i = nhead-1; i >= 0; i--) {
		drot = 2 * rot / (float) (nhead-1) * (float) i;
		dx = hyp * cos(alpha + PI - rot + drot);
		dy = hyp * sin(alpha + PI - rot + drot);
		dprintf("dx,dy = %g,%g\n", dx, dy);
		line(x1+dx, y1+dy, x1, y1);
	}
E 2
}

box(x0, y0, x1, y1)
	float x0, y0, x1, y1;
{
	move(x0, y0);
	cont(x0, y1);
	cont(x1, y1);
	cont(x1, y0);
	cont(x0, y0);
}

cont(x, y)	/* continue line from here to x,y */
	float x, y;
{
D 2
	int h1, v1;
	int dh, dv;
E 2
I 2
	float h1, v1;
	float dh, dv;
E 2

	h1 = xconv(x);
	v1 = yconv(y);
	dh = h1 - hpos;
	dv = v1 - vpos;
D 2
	downsize();
E 2
	hvflush();
D 2
	if (!useDline && dv == 0 && abs(dh) > minline)	/* horizontal */
		printf("\\l'%du'\n", dh);
	else if (!useDline && dh == 0 && abs(dv) > minline) {	/* vertical */
		if (devtype == DEV202)
			printf("\\L'%du\\(vr'\n", dv);
		else
			printf("\\v'-.25m'\\L'%du\\(br'\\v'.25m'\n", dv);	/* add -.25m correction if use \(br */
	} else {
		if (OLDSTYLE)
			drawline(dh, dv);
		else
			printf("\\D'l%du %du'\n", dh, dv);
	}
	upsize();
E 2
I 2
	printf("\\D'l%.3fi %.3fi'\n", dh, dv);
E 2
	flyback();	/* expensive */
	hpos = h1;
	vpos = v1;
}

circle(x, y, r)
	float x, y, r;
{
D 2
	int d;

	downsize();
	d = xsc(2 * r);
E 2
	move(x-r, y);
	hvflush();
D 2
	if (OLDSTYLE)
		drawcircle(d);
	else
		printf("\\D'c%du'\n", d);
	upsize();
E 2
I 2
	printf("\\D'c%.3fi'\n", xsc(2 * r));
E 2
	flyback();
}

D 3
spline(x, y, n, p)
E 3
I 3
spline(x, y, n, p, dashed, ddval)
E 3
	float x, y, *p;
D 2
	float n;
E 2
I 2
	float n;	/* sic */
I 3
	int dashed;
	float ddval;
E 3
E 2
{
D 2
	int i, j, dx, dy;
	char temp[1000];
E 2
I 2
	int i;
	float dx, dy;
	float xerr, yerr;
E 2

I 3
	if (dashed && ddval)
		printf(".nr 99 %.3fi\n", ddval);
E 3
D 2
	downsize();
E 2
	move(x, y);
	hvflush();
D 2
	if (OLDSTYLE) {
		temp[0] = 0;
		for (i = 0; i < 2 * n; i += 2) {
			dx = xsc(p[i]);
			dy = ysc(p[i+1]);
			sprintf(&temp[strlen(temp)], " %d %d", dx, dy);
		}
		drawspline(temp);
E 2
I 2
D 3
	printf("\\D'~");
E 3
	xerr = yerr = 0.0;
I 3
	if (dashed) {
		if (ddval)
			printf("\\X'Pd \\n(99'\\D'q 0 0");
		else
			printf("\\X'Pd'\\D'q 0 0");
	} else
		printf("\\D'~");
E 3
	for (i = 0; i < 2 * n; i += 2) {
		dx = xsc(xerr += p[i]);
		xerr -= dx/xscale;
		dy = ysc(yerr += p[i+1]);
		yerr -= dy/yscale;
		printf(" %.3fi %.3fi", dx, -dy);	/* WATCH SIGN */
E 2
	}
D 2
	else {
		printf("\\D'~");
		for (i = 0; i < 2 * n; i += 2) {
			dx = xsc(p[i]);
			dy = ysc(p[i+1]);
			printf(" %du %du", dx, dy);
		}
		printf("'\n");
	}
	upsize();
E 2
I 2
D 3
	printf("'\n");
E 3
I 3
	if (dashed)
		printf(" 0 0'\\X'Ps'\n");
	else
		printf("'\n");
E 3
E 2
	flyback();
}

ellipse(x, y, r1, r2)
	float x, y, r1, r2;
{
D 2
	int ir1, ir2;
E 2
I 2
	float ir1, ir2;
E 2

D 2
	downsize();
E 2
	move(x-r1, y);
	hvflush();
	ir1 = xsc(r1);
	ir2 = ysc(r2);
D 2
	if (OLDSTYLE)
		drawellipse(2 * ir1, 2 * abs(ir2));
	else
		printf("\\D'e%du %du'\n", 2 * ir1, 2 * abs(ir2));
	upsize();
E 2
I 2
	printf("\\D'e%.3fi %.3fi'\n", 2 * ir1, 2 * abs(ir2));
E 2
	flyback();
}

D 2
arc(x, y, x0, y0, x1, y1, r)	/* draw arc with center x,y */
	float x, y, x0, y0, x1, y1, r;
E 2
I 2
arc(x, y, x0, y0, x1, y1)	/* draw arc with center x,y */
	float x, y, x0, y0, x1, y1;
E 2
{

D 2
	downsize();
E 2
	move(x0, y0);
	hvflush();
D 2
	if (OLDSTYLE) {
		drawarc(xsc(x1-x0), ysc(y1-y0), xsc(r));
	} else {
		printf("\\D'a%du %du %du %du'\n",
			xsc(x-x0), ysc(y-y0), xsc(x1-x), ysc(y1-y));
	}
	upsize();
E 2
I 2
	printf("\\D'a%.3fi %.3fi %.3fi %.3fi'\n",
		xsc(x-x0), -ysc(y-y0), xsc(x1-x), -ysc(y1-y));	/* WATCH SIGNS */
E 2
	flyback();
}

D 2
erase()	/* get to bottom of frame */
{
	return;	/* for now, ignore them */
}

point(x, y)	/* put point at x,y */
	float x, y;
{
	static char *temp = ".";

	move(x, y);
	label(temp, 'L');
}

space(x0, y0, x1, y1)	/* set limits of page */
	float x0, y0, x1, y1;
{
	if (x0 == x1)
		x1 = x0 + 1;
	if (y0 == y1)
		y1 = y0 - 1;	/* kludge */
	X0 = x0;
	Y0 = y0;
	X1 = x1;
	Y1 = y1;
	xscale = hmax / (X1-X0);
	yscale = vmax / (Y0-Y1);
}

xconv(x)	/* convert x from external to internal form */
	float x;
{
	int v;

	v = (x-X0) * xscale + 0.5;
	if (OLDSTYLE) {
		v = (v + DX - 1) / DX;
		v *= DX;
	}
	return v;
}

xsc(x)	/* convert x from external to internal form, scaling only */
	float x;
{
	int v;

	v = (x) * xscale + 0.5;
	if (OLDSTYLE) {
		v = (v + DX - 1) / DX;
		v *= DX;
	}
	return v;
}

yconv(y)	/* convert y from external to internal form */
	float y;
{
	int v;

	y += Y1 - ymax;
	v = (y-Y1) * yscale + 0.5;
	if (OLDSTYLE) {
		v = (v + DY - 1) / DY;
		v *= DY;
	}
	return v;
}

ysc(y)	/* convert y from external to internal form, scaling only */
	float y;
{
	int v;

	v = (y) * yscale + 0.5;
	if (OLDSTYLE) {
		v = (v + DY - 1) / DY;
		v *= DY;
	}
	return v;
}

linemod(s)
	char *s;
{
}

E 2
dot() {
	hvflush();
	/* what character to draw here depends on what's available. */
	/* on the 202, l. is good but small. */
D 2
	/* on other typesetters, use a period and hope */
	if (OLDSTYLE)
		printf("\\&.\n");
	else if (devtype == DEV202)
		printf("\\z\\(l.\\(l.\\z\\(l.\\(l.\n");
	else
		printf("\\&.\n");
E 2
I 2
	/* in general, use a smaller, shifted period and hope */

D 4
	printf("\\&\\f1\\h'-.1m'\\v'.03m'\\s-3.\\s+3\\fP\n");
E 4
I 4
	printf("\\&\\f1\\h'-.05m'\\v'.03m'\\s-3.\\s+3\\fP\n");
E 4
E 2
	flyback();
}
D 2

#ifndef	OLDTROFF

	/* satisfy the loader... */

drawline(){;}
drawcircle(){;}
drawspline(){;}
drawellipse(){;}
drawarc(){;}
upsize(){;}
downsize(){;}

#endif

#ifdef	OLDTROFF

	/* these are for real */

int	drawsize	= 2;	/* shrink point size by this factor */

#define	sgn(n)	((n > 0) ? 1 : ((n < 0) ? -1 : 0))
#define	arcmove(x,y)	{ hgoto(x); vmot(-vpos-(y)); }

put1(c) /* output one character, usually a dot */
{
	static int nput = 0;

	if (nput++ > 100) {	/* crude approx: troff input buffer ~ 400 */
		nput = 0;
		printf("\n");	/* someday this will give a spurious break */
		flyback();
		printf("\\\&");
	}
	hvflush();	/* crude! */
	printf("\\z%c", c);
}

downsize()	/* set size lower to make it lighter */
{
	if (drawsize != 1) {
		printf(".nr .. \\n(.s/%d\n", drawsize);
		printf(".ps \\n(..\n");
	}
}

upsize()	/* undo downsize */
{
	printf(".ps\n");	/* God help anyone who fiddles .ps */
}

drawline(dx, dy)	/* draw line from here to dx, dy */
int dx, dy;
{
	int xd, yd;
	float val, slope;
	int i, numdots;
	int dirmot, perp;
	int motincr, perpincr;
	int ohpos, ovpos, osize;
	float incrway;

        ohpos = hpos;
	ovpos = vpos;
	xd = dx / DX;
	yd = dy / DX;
	printf("\\\&");
	put1(drawdot);
	if (xd == 0) {
		numdots = abs (yd);
		motincr = DX * sgn (yd);
		for (i = 0; i < numdots; i++) {
			vmot(motincr);
			put1(drawdot);
		}
		vgoto(ovpos + dy);
		printf("\n");
		return;
	}
	if (yd == 0) {
		numdots = abs (xd);
		motincr = DX * sgn (xd);
		for (i = 0; i < numdots; i++) {
			hmot(motincr);
			put1(drawdot);
		}
		hgoto(ohpos + dx);
		printf("\n");
		return;
	}
	if (abs (xd) > abs (yd)) {
		val = slope = (float) xd/yd;
		numdots = abs (xd);
		dirmot = 'h';
		perp = 'v';
		motincr = DX * sgn (xd);
		perpincr = DX * sgn (yd);
	}
	else {
		val = slope = (float) yd/xd;
		numdots = abs (yd);
		dirmot = 'v';
		perp = 'h';
		motincr = DX * sgn (yd);
		perpincr = DX * sgn (xd);
	}
	incrway = sgn ((int) slope);
	for (i = 0; i < numdots; i++) {
		val -= incrway;
		if (dirmot == 'h')
			hmot(motincr);
		else
			vmot(motincr);
		if (val * slope < 0) {
			if (perp == 'h')
				hmot(perpincr);
			else
				vmot(perpincr);
			val += slope;
		}
		put1(drawdot);
	}
	hgoto(ohpos + dx);
	vgoto(ovpos + dy);
	printf("\n");
}

drawspline(s)	/* draw spline curve */
	char *s;
{
	int x[50], y[50], xp, yp, pxp, pyp;
	float t1, t2, t3, w;
	int i, j, steps, N, prevsteps;
	register char *p;

	N = 0;

/* Weird...
	N = sscanf(s, "%d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d  %d %d ",
	&x[2], &y[2], &x[3], &y[3], &x[4], &y[4], &x[5], &y[5], &x[6], &y[6], &x[7], &y[7], &x[8], &y[8], &x[9], &y[9], &x[10], &y[10], &x[11], &y[11], &x[12], &y[12],
&x[13], &y[13], &x[14], &y[14], &x[15], &y[15], &x[16], &y[16], &x[17], &y[17], &x[18], &y[18], &x[19], &y[19], &x[20], &y[20], &x[21], &y[21], &x[22], &y[22], &x[23], &y[23], &x[24], &y[24],
&x[25], &y[25], &x[26], &y[26], &x[27], &y[27], &x[28], &y[28], &x[29], &y[29], &x[30], &y[30], &x[31], &y[31], &x[32], &y[32], &x[33], &y[33], &x[34], &y[34], &x[35], &y[35], &x[36], &y[36], 
&x[37], &y[37]);
*/
	p = s;
	for( i = 2; i <= 37; i++) {
		j = sscanf(p, "%d%d", &x[i], &y[i]);
		if( j == -1)
			break;
		while( isspace(*p))
			p++;
		while( isdigit(*p) || *p == '-')
			p++;
		while( isspace(*p))
			p++;
		while( isdigit(*p) || *p == '-')
			p++;
		N += 2;
	}

	N = N/2 + 2;
	x[0] = x[1] = hpos;
	y[0] = y[1] = vpos;
	for (i = 1; i < N; i++) {
		x[i+1] += x[i];
		y[i+1] += y[i];
	}
	x[N] = x[N-1];
	y[N] = y[N-1];
	prevsteps = 0;
	pxp = pyp = -9999;
	printf("\\\&");
	for (i = 0; i < N-1; i++) {	/* interval */
		steps = (dist(x[i],y[i], x[i+1],y[i+1]) + dist(x[i+1],y[i+1], x[i+2],y[i+2])) / 2;
		steps /= DX;
		for (j = 0; j < steps; j++) {	/* points within */
			w = (float) j / steps;
			t1 = 0.5 * w * w;
			w = w - 0.5;
			t2 = 0.75 - w * w;
			w = w - 0.5;
			t3 = 0.5 * w * w;
			xp = t1 * x[i+2] + t2 * x[i+1] + t3 * x[i] + 0.5;
			yp = t1 * y[i+2] + t2 * y[i+1] + t3 * y[i] + 0.5;
			xp = round(xp, DX);
			yp = round(yp, DY);
			if (xp != pxp || yp != pyp) {
				hgoto(xp);
				vgoto(yp);
				put1(drawdot);
				pxp = xp;
				pyp = yp;
			}
		}
	}
	printf("\n");
}

drawcircle(d)
{
	int xc, yc;

	xc = hpos;
	yc = vpos;
	printf("\\\&");
	conicarc(hpos + d/2, -vpos, hpos, -vpos, hpos, -vpos, d/2, d/2);
	hgoto(xc + d);	/* circle goes to right side */
	vgoto(yc);
	printf("\n");
}

dist(x1, y1, x2, y2)	/* integer distance from x1,y1 to x2,y2 */
{
	float dx, dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return sqrt(dx*dx + dy*dy) + 0.5;
}

drawarc(x, y, r)
{
	int x0, y0;
	float dx, dy, phi, d, ht, ang;

	if (r == 0)
		r = 1;
	if (r < 0)
		ang = PI / 2;
	else
		ang = -(PI / 2);
	dx = x / 2;
	dy = y / 2;
	phi = atan2(dy, dx) + ang;
	while ((d = (float)r * r - (dx*dx + dy*dy)) < 0.0)
		r *= 2;
	ht = sqrt(d);
	x0 = hpos + dx + ht * cos(phi) + 0.5;
	y0 = vpos + dy + ht * sin(phi) + 0.5;
	printf("\\\&");
	conicarc(x0, -y0, hpos, -vpos, hpos+x, -vpos-y, r, r);
	printf("\n");
}

drawellipse(a, b)
{
	int xc, yc;

	xc = hpos;
	yc = vpos;
	printf("\\\&");
	conicarc(hpos + a/2, -vpos, hpos, -vpos, hpos, -vpos, a/2, b/2);
	hgoto(xc + a);
	vgoto(yc);
	printf("\n");
}

#define sqr(x) (long int)(x)*(x)

conicarc(x, y, x0, y0, x1, y1, a, b)
{
	/* based on Bresenham, CACM, Feb 77, pp 102-3 */
	/* by Chris Van Wyk */
	/* capitalized vars are an internal reference frame */
	long dotcount = 0;
	int	xs, ys, xt, yt, Xs, Ys, qs, Xt, Yt, qt,
	M1x, M1y, M2x, M2y, M3x, M3y,
	Q, move, Xc, Yc;
	int	delta;
	float	xc, yc;
	float	radius, slope;
	float	xstep, ystep;
	if (a != b)	/* an arc of an ellipse; internally, will still think of circle */
		if (a > b) {
			xstep = (float)a / b;
			ystep = 1;
			radius = b;
		} 
		else
		 {
			xstep = 1;
			ystep = (float)b / a;
			radius = a;
		} 
	else	/* a circular arc; radius is computed from center and first point */	 {
		xstep = ystep = 1;
		radius = sqrt((float)(sqr(x0 - x) + sqr(y0 - y)));
	}


	xc = x0;
	yc = y0;
	/* now, use start and end point locations to figure out
   the angle at which start and end happen; use these
   angles with known radius to figure out where start
   and end should be */
	slope = atan2((double)(y0 - y), (double)(x0 - x)
	    );
	if ((slope == 0.0)
	     && (x0 < x)
	    )
		slope = 3.14159265;
	x0 = x + radius * cos(slope)
	 + 0.5;
	y0 = y + radius * sin(slope)
	 + 0.5;
	slope = atan2((double)(y1 - y), (double)(x1 - x)
	    );
	if ((slope == 0.0)
	     && (x1 < x)
	    )
		slope = 3.14159265;
	x1 = x + radius * cos(slope)
	 + 0.5;
	y1 = y + radius * sin(slope)
	 + 0.5;
	/* step 2: translate to zero-centered circle */
	xs = x0 - x;
	ys = y0 - y;
	xt = x1 - x;
	yt = y1 - y;
	/* step 3: normalize to first quadrant */
	if (xs < 0)
		if (ys < 0) {
			Xs = abs(ys);
			Ys = abs(xs);
			qs = 3;
			M1x = 0;
			M1y = -1;
			M2x = 1;
			M2y = -1;
			M3x = 1;
			M3y = 0;
		} 
		else {
			Xs = abs(xs);
			Ys = abs(ys);
			qs = 2;
			M1x = -1;
			M1y = 0;
			M2x = -1;
			M2y = -1;
			M3x = 0;
			M3y = -1;
		} 
	else if (ys < 0) {
		Xs = abs(xs);
		Ys = abs(ys);
		qs = 0;
		M1x = 1;
		M1y = 0;
		M2x = 1;
		M2y = 1;
		M3x = 0;
		M3y = 1;
	} else {
		Xs = abs(ys);
		Ys = abs(xs);
		qs = 1;
		M1x = 0;
		M1y = 1;
		M2x = -1;
		M2y = 1;
		M3x = -1;
		M3y = 0;
	}


	Xc = Xs;
	Yc = Ys;
	if (xt < 0)
		if (yt < 0) {
			Xt = abs(yt);
			Yt = abs(xt);
			qt = 3;
		} 
		else {
			Xt = abs(xt);
			Yt = abs(yt);
			qt = 2;
		} 
	else if (yt < 0) {
		Xt = abs(xt);
		Yt = abs(yt);
		qt = 0;
	} else {
		Xt = abs(yt);
		Yt = abs(xt);
		qt = 1;
	}


	/* step 4: calculate number of quadrant crossings */
	if (((4 + qt - qs)
	     % 4 == 0)
	     && (Xt <= Xs)
	     && (Yt >= Ys)
	    )
		Q = 3;
	else
		Q = (4 + qt - qs) % 4 - 1;
	/* step 5: calculate initial decision difference */
	delta = sqr(Xs + 1)
	 + sqr(Ys - 1)
	-sqr(xs)
	-sqr(ys);
	/* here begins the work of drawing
   we hope it ends here too */
	while ((Q >= 0)
	     || ((Q > -2)
	     && ((Xt > Xc)
	     || (Yt < Yc)
	    )
	    )
	    ) {
		if (dotcount++ % DX == 0)
			putdot(round((int) xc, DX), round((int) yc, DY));
		if (Yc < 0.5) {
			/* reinitialize */
			Xs = Xc = 0;
			Ys = Yc = sqrt((float)(sqr(xs) + sqr(ys)));
			delta = sqr(Xs + 1) + sqr(Ys - 1) - sqr(xs) - sqr(ys);
			Q--;
			M1x = M3x;
			M1y = M3y;
			 {
				int	T;
				T = M2y;
				M2y = M2x;
				M2x = -T;
				T = M3y;
				M3y = M3x;
				M3x = -T;
			}
		} else {
			if (delta <= 0)
				if (2 * delta + 2 * Yc - 1 <= 0)
					move = 1;
				else
					move = 2;
			else if (2 * delta - 2 * Xc - 1 <= 0)
				move = 2;
			else
				move = 3;
			switch (move) {
			case 1:
				Xc++;
				delta += 2 * Xc + 1;
				xc += M1x * xstep;
				yc += M1y * ystep;
				break;
			case 2:
				Xc++;
				Yc--;
				delta += 2 * Xc - 2 * Yc + 2;
				xc += M2x * xstep;
				yc += M2y * ystep;
				break;
			case 3:
				Yc--;
				delta -= 2 * Yc + 1;
				xc += M3x * xstep;
				yc += M3y * ystep;
				break;
			}
		}
	}


}

putdot(x, y)
{
	arcmove(x, y);
	put1(drawdot);
}

round(x, dx)	/* round x relative to dx */
{
	x = (x + dx - 1) / dx;
	return x * dx;
}
#endif
E 2
E 1
