#ifndef lint
static char sccsid[] = "@(#)td.c	5.7 (Berkeley) 9/13/2010";
#endif lint

#include <math.h>
#include "tdef.h"

/*
 * This module implements the ditroff-like \D vector drawing primitive.
 * We do most of the work in the front end, i.e., the code in this module
 * executes as a result of being called from getch() in n1.c.  We parse
 * all the voodoo between the delimiters and emit a DRAWOP...DRAWFIN
 * sequence, wherein the middle part ("...") consists of h v LINETO and
 * h v h v h v CURVETO sequences.  Each h is an ordinary horizontal motion
 * metacharacter and each v is an ordinary vertical motion, so all code
 * in the bulk of troff sees it as nothing more than a bunch of local motions.
 * The back end (t10.c) sees it as motions too, but it also acts on the 4
 * new metacharacters we've introduced to make these motions emit lineto
 * and curveto path constructions, and the closing DRAWFIN encodes the
 * stroke or fill.
 *
 * Remember that in the front end positive vertical motion is downward.
 */

extern int cbuf[];
extern int *cp;
extern int ch;
extern int dfact;
extern int vflag;
extern int nonumb;
extern int pts;
extern int lss;

static int delim, *dp, gotsome;
static int defswidth;
static double pi, quadarc_convfactor;
static double arctoobig, arctoosmall;

static int ellarc_flag;
static double ellarc_a, ellarc_b, ellarc_aoverb, ellarc_bovera;

#define	BSPLINE_MINPTS	2
#define	BSPLINE_MAXPTS	30
static int bspline_x[BSPLINE_MAXPTS], bspline_y[BSPLINE_MAXPTS];
static int bspline_npts;

init_curve_conversion()
{
	pi = acos(-1.0);
	quadarc_convfactor = (sqrt(2.0) - 1.0) * 4.0 / 3.0;
	arctoobig = pi / 2.0;
	arctoosmall = 0.05 * pi / 180.0;	/* from Adobe's psdit.pro */
}

drawop_frontend()
{
	register int i;

	if((delim = getch()) & MOT)return;
		else delim &= CMASK;
	dp = cbuf;
	*dp++ = DRAWOP;
	gotsome = 0;
	defswidth = (pts & 0377) * 3 << 11;
	i = getch() & CMASK;
	if (i == delim)
		return;
	switch (i) {
	case 'a':
	case 'A':
	case 'l':
	case 'u':
	case '~':
		ch = i;
		drawop_freeform();
		break;
	case 'c':
		drawop_circle();
		break;
	case 'e':
		drawop_ellipse();
		break;
	default:
		eat(delim);
	}
	dfact = 1;
	vflag = 0;
}

drawop_freeform()
{
	register int i, j;
	int dh1, dv1, dh2, dv2;
	int contmode, closepath;

	for (contmode = 0; ; ) {
		skip();
		i = getch() & CMASK;
		if (i == delim) {
			if (gotsome) {
				*dp++ = DRAWFIN | defswidth;
				*dp = 0;
				cp = cbuf;
			}
			return;
		}
contin:		switch (i) {
		case 'l':
			skip();
			dfact = EM;
			dh1 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			skip();
			dfact = lss;
			vflag++;
			dv1 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			vflag = 0;
			drawelement_line(dh1, dv1);
			contmode = 'l';
			continue;
		case 'u':
			/* native PostScript curve */
			for (j = 0; j < 3; j++) {
				skip();
				dfact = EM;
				i = atoi();
				if (nonumb) {
					eat(delim);
					return;
				}
				*dp++ = makem(i);
				skip();
				dfact = lss;
				vflag++;
				i = atoi();
				if (nonumb) {
					eat(delim);
					return;
				}
				*dp++ = makem(i);
				vflag = 0;
			}
			*dp++ = CURVETO;
			gotsome++;
			contmode = 0;
			continue;
		case '~':
			/* quadratic B-spline */
			contmode = 0;
			for (i = 0; i < BSPLINE_MAXPTS; i++) {
				skip();
				dfact = EM;
				j = atoi();
				if (nonumb)
					break;
				bspline_x[i] = j;
				skip();
				dfact = lss;
				vflag++;
				j = atoi();
				if (nonumb) {
					eat(delim);
					return;
				}
				vflag = 0;
				bspline_y[i] = j;
			}
			if (i < BSPLINE_MINPTS) {
				eat(delim);
				return;
			}
			bspline_npts = i;
			convert_bspline();
			continue;
		case 'a':
			/* counter-clockwise arc */
			contmode = 0;
			skip();
			dfact = EM;
			dh1 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			skip();
			dfact = lss;
			vflag++;
			dv1 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			vflag = 0;
			skip();
			dfact = EM;
			dh2 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			skip();
			dfact = lss;
			vflag++;
			dv2 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			vflag = 0;
			/* weed out degenerate conditions */
			if (!dh1 && !dv1 && !dh2 && !dv2)
				continue;
			if (!dh2 && !dv2) {
				drawelement_line(dh1, dv1);
				continue;
			}
			if (!dh1 && !dv1) {
				drawelement_line(dh2, dv2);
				continue;
			}
			/*
			 * Detect CCW quadrant arcs:
			 * it'll be hv in Q2 & Q4; vh in Q1 & Q3
			 */
			if (!dh1 && dv1 > 0 && dh2 < 0 && !dv2) { /* Q2 */
				drawelement_hvarc(dh2, dv1);
				continue;
			}
			if (!dh1 && dv1 < 0 && dh2 > 0 && !dv2) { /* Q4 */
				drawelement_hvarc(dh2, dv1);
				continue;
			}
			if (dh1 < 0 && !dv1 && !dh2 && dv2 < 0) { /* Q1 */
				drawelement_vharc(dv2, dh1);
				continue;
			}
			if (dh1 > 0 && !dv1 && !dh2 && dv2 > 0) { /* Q3 */
				drawelement_vharc(dv2, dh1);
				continue;
			}
			/* CCW arc general case */
			drawelement_genarc(dh1, dv1, dh2, dv2, 0);
			continue;
		case 'A':
			/* clockwise arc */
			contmode = 0;
			skip();
			dfact = EM;
			dh1 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			skip();
			dfact = lss;
			vflag++;
			dv1 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			vflag = 0;
			skip();
			dfact = EM;
			dh2 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			skip();
			dfact = lss;
			vflag++;
			dv2 = atoi();
			if (nonumb) {
				eat(delim);
				return;
			}
			vflag = 0;
			/* weed out degenerate conditions */
			if (!dh1 && !dv1 && !dh2 && !dv2)
				continue;
			if (!dh2 && !dv2) {
				drawelement_line(dh1, dv1);
				continue;
			}
			if (!dh1 && !dv1) {
				drawelement_line(dh2, dv2);
				continue;
			}
			/*
			 * Detect CW quadrant arcs:
			 * it'll be hv in Q1 & Q3; vh in Q2 & Q4
			 */
			if (!dh1 && dv1 > 0 && dh2 > 0 && !dv2) { /* Q1 */
				drawelement_hvarc(dh2, dv1);
				continue;
			}
			if (!dh1 && dv1 < 0 && dh2 < 0 && !dv2) { /* Q3 */
				drawelement_hvarc(dh2, dv1);
				continue;
			}
			if (dh1 > 0 && !dv1 && !dh2 && dv2 < 0) { /* Q2 */
				drawelement_vharc(dv2, dh1);
				continue;
			}
			if (dh1 < 0 && !dv1 && !dh2 && dv2 > 0) { /* Q4 */
				drawelement_vharc(dv2, dh1);
				continue;
			}
			/* CW arc general case */
			drawelement_genarc(dh1, dv1, dh2, dv2, 1);
			continue;
		case 'C':
		case 'S':
			if (!gotsome) {
				eat(delim);
				return;
			}
			if (i == 'C')
				closepath = 0x200;
			else
				closepath = 0;
			skip();
			dfact = 1;
			i = atoi();
			if (i)
				*dp++ = DRAWFIN | closepath | (i << 11);
			else
				*dp++ = DRAWFIN | closepath | defswidth;
			*dp = 0;
			eat(delim);
			cp = cbuf;
			return;
		case 'F':
			if (!gotsome) {
				eat(delim);
				return;
			}
			*dp++ = DRAWFIN | 0x400;
			*dp = 0;
			eat(delim);
			cp = cbuf;
			return;
		default:
			if (contmode) {
				ch = i;
				i = contmode;
				contmode = 0;
				goto contin;
			}
			/* garbage */
			eat(delim);
			return;
		}
	}
}

drawop_circle()
{
	register int i, x;

	skip();
	dfact = EM;
	x = atoi();
	if (!x) {
		eat(delim);
		return;
	}
	drawelement_ellipse(x, x);
	if (!gotsome) {
		eat(delim);
		return;
	}
	skip();
	i = getch() & CMASK;
	if (i == delim) {
		*dp++ = DRAWFIN | 0x200 | defswidth;
		*dp++ = makem(x);
		*dp = 0;
		cp = cbuf;
		return;
	}
	switch (i) {
	case 'C':
	case 'S':
		skip();
		dfact = 1;
		i = atoi();
		if (i)
			*dp++ = DRAWFIN | 0x200 | (i << 11);
		else
			*dp++ = DRAWFIN | 0x200 | defswidth;
		*dp++ = makem(x);
		*dp = 0;
		eat(delim);
		cp = cbuf;
		return;
	case 'F':
		*dp++ = DRAWFIN | 0x400;
		*dp++ = makem(x);
		*dp = 0;
		eat(delim);
		cp = cbuf;
		return;
	default:
		/* garbage */
		eat(delim);
		return;
	}
}

drawop_ellipse()
{
	register int i, x, y;

	skip();
	dfact = EM;
	x = atoi();
	if (nonumb) {
		eat(delim);
		return;
	}
	skip();
	dfact = lss;
	vflag++;
	y = atoi();
	if (nonumb) {
		eat(delim);
		return;
	}
	vflag = 0;
	drawelement_ellipse(x, y);
	if (!gotsome) {
		eat(delim);
		return;
	}
	skip();
	i = getch() & CMASK;
	if (i == delim) {
		*dp++ = DRAWFIN | 0x200 | defswidth;
		*dp++ = makem(x);
		*dp = 0;
		cp = cbuf;
		return;
	}
	switch (i) {
	case 'C':
	case 'S':
		skip();
		dfact = 1;
		i = atoi();
		if (i)
			*dp++ = DRAWFIN | 0x200 | (i << 11);
		else
			*dp++ = DRAWFIN | 0x200 | defswidth;
		*dp++ = makem(x);
		*dp = 0;
		eat(delim);
		cp = cbuf;
		return;
	case 'F':
		*dp++ = DRAWFIN | 0x400;
		*dp++ = makem(x);
		*dp = 0;
		eat(delim);
		cp = cbuf;
		return;
	default:
		/* garbage */
		eat(delim);
		return;
	}
}

drawelement_line(dh, dv)
{
	if (!dh && !dv)
		return;
	drawelement_vector(dh, dv);
	*dp++ = LINETO;
	gotsome++;
}

drawelement_vector(dh, dv)
{
	*dp++ = makem(dh);
	vflag++;
	*dp++ = makem(dv);
	vflag = 0;
}

/*
 * The following two functions are agnostic to the CW vs CCW direction.
 * They are intended to be efficient building blocks for implementing
 * the simple \D'c...' and \D'e...' drawing ops.
 */
drawelement_hvarc(dh, dv)
{
	int xd, yd;

	if (!dh || !dv) {
		drawelement_line(dh, dv);
		return;
	}
	xd = dh * quadarc_convfactor;
	yd = dv * quadarc_convfactor;
	drawelement_vector(xd, 0);
	drawelement_vector(dh - xd, dv - yd);
	drawelement_vector(0, yd);
	*dp++ = CURVETO;
	gotsome++;
}

drawelement_vharc(dv, dh)
{
	int xd, yd;

	if (!dh || !dv) {
		drawelement_line(dh, dv);
		return;
	}
	xd = dh * quadarc_convfactor;
	yd = dv * quadarc_convfactor;
	drawelement_vector(0, yd);
	drawelement_vector(dh - xd, dv - yd);
	drawelement_vector(xd, 0);
	*dp++ = CURVETO;
	gotsome++;
}

drawelement_ellipse(dh, dv)
{
	int xr, yr;

	xr = dh / 2;
	yr = dv / 2;
	/*
	 * Because we use the hvarc and vharc functions,
	 * we can go either CW or CCW and we don't even have to worry about it.
	 * The following code arbitrarily uses the CCW direction.
	 */
	drawelement_vharc(yr, xr);
	drawelement_hvarc(xr, -yr);
	drawelement_vharc(-yr, -xr);
	drawelement_hvarc(-xr, yr);
}

/*
 * Arc to Bezier curve conversion
 *
 * Our biggest difficulty is that ditroff's arc specification is poorly
 * designed.  Each arc is specified by two (x,y) vectors: one from the
 * starting endpoint to the centre, and another from the centre to the
 * terminal endpoint.  That is equivalent to placing the centre of a circle
 * or ellipse at the origin and defining that circle or elliple by the
 * (x,y) coordinates of two different points thereon.
 *
 * It appears that the intent was to support circular arcs only, but if
 * the two endpoints are at different distances from the specified centre,
 * the curve obviously can't be a circular arc.  (Remember the definition
 * of a circle: a set of points that are equidistant from a certain point
 * called the centre.)  Hence we are trying to generalize it to elliptic
 * arcs.
 *
 * We have started by using the algorithm lifted from Adobe's psdit prolog
 * code, translated from PostScript into C.  This algorithm gives the
 * appearance of elegantly supporting every arc that can specified in the
 * ditroff manner, circular or not, but in this case the look of the code
 * is deceiving.  Adobe's unmodified algorithm works well for circular arcs
 * as well as those that would have been circular were it not for rounding
 * errors, but if one deliberately wishes to draw an arc of a significantly
 * eccentric ellipse, the curvature comes out wrong: the Bezier curves connect
 * correctly, but the off-curve control points are wrong.
 *
 * Our next attempt was to use an arc-to-Bezier algorithm that is specifically
 * designed for arbitrary elliptic arcs.  We took the algorithm presented in
 * "Drawing an elliptical arc using polylines, quadratic or cubic Bezier
 * curves" by L. Maisonobe, found on www.spaceroots.org.  As one would
 * naturally expect, the assumption in that paper is that before proceeding
 * with the drawing part, one has a firm understanding of exactly what ellipse
 * is desired in mathematical terms, i.e., the semiaxes a and b and the tilt
 * angle theta.
 *
 * It was at this point that we had realized just how lousy ditroff's
 * specification of an arc is in mathematical terms.  First off, we had to
 * dispense with the tilt angle theta and require the ellipse to be horizontal-
 * vertical: specifying the general case of an arc of an arbitrary ellipse
 * requires 5 numbers (3 for the ellipse and 2 for the arc), whereas we only
 * have 4.  Hence we are looking for an ellipse that fits the equation
 * x**2/a**2 + y**2/b**2 = 1, and we seek to solve for a and b by substituting
 * in our two given endpoint vectors.
 *
 * As it turns out, that is a really poor way to define an ellipse.  For some
 * combination of arc endpoint vectors there is an infinite number of different
 * ellipses (one of which is a circle) which fit the given points; for others
 * there is no possible horizontal-vertical ellipse that passes through the two
 * given points.  Even worse, requests for an arcs of such impossible ellipses
 * are almost guaranteed to happen: if one wants a circular arc, but one of the
 * coordinates is off by a unit or two because of some rounding error, the
 * resulting request calls for an impossible elliptic arc!
 *
 * So what do we do?  Well, a careful comparison of Adobe's "bogoelliptic" arc
 * algorithm with Maisonobe's true elliptic arc one has revealed that the two
 * would in fact produce practically equivalent Bezier curves if Adobe's
 * algorithm were given just one slight refinement: when calculating the
 * off-curve control points, factors of a/b or b/a need to included.
 * (Obviously these factors equal 1 for a circular arc.)  Thus our solution
 * is as follows:
 *
 * We use the Adobe-based algorithm with the a/b and b/a factors;
 * For each arc we process, we do attempt to compute the a and b semiaxes
 * of the implicitly underlying ellipse;
 * If that calculation succeeds (the two endpoints do fall on some h-v
 * ellipse), we use the recovered a and b to set the a/b and b/a factors;
 * We set the a/b and b/a factors to 1 w/o further fuss under the following
 * conditions:
 * - the endpoints call for an impossible ellipse;
 * - out of the infinite number of possible ellipses we pick the circle.
 *
 * The intended result is that if one wants a circular arc, we produce one;
 * if one wanted a circular arc, but it got messed up by rounding errors, we
 * still produce good output like Adobe's original algorithm did (that output
 * does not strictly correspond to any conic arc, but then a Bezier curve never
 * does anyway); and if one actually wants an elliptic arc and specifies valid
 * endpoints for that, we'll figure it out and produce the requested elliptic
 * arc.
 */

drawelement_genarc(dh1, dv1, dh2, dv2, cw)
{
	ellarc_flag = is_arc_elliptic(dh1, dv1, dh2, dv2, &ellarc_a, &ellarc_b);
	if (ellarc_flag) {
		ellarc_aoverb = ellarc_a / ellarc_b;
		ellarc_bovera = ellarc_b / ellarc_a;
	} else
		ellarc_aoverb = ellarc_bovera = 1.0;
	drawelement_genarc_seg(dh1, dv1, dh2, dv2, cw);
}

drawelement_genarc_seg(dh1, dv1, dh2, dv2, cw)
{
	double startang, endang, sweep, signfactor;
	double halfsweep, controldelt;
	int x1, y1, x2, y2, x3, y3;

	if (ellarc_flag) {
		startang = atan2((double) -dv1 / ellarc_b,
				 (double) -dh1 / ellarc_a);
		endang = atan2((double) dv2 / ellarc_b,
				(double) dh2 / ellarc_a);
	} else {
		startang = atan2((double) -dv1, (double) -dh1);
		endang = atan2((double) dv2, (double) dh2);
	}
	signfactor = cw ? -1.0 : 1.0;
	sweep = (startang - endang) * signfactor;
	if (sweep < 0)
		sweep += pi * 2.0;
	halfsweep = sweep / 2.0;
	if (sweep > arctoobig) {
		drawelement_genarc_split(dh1, dv1, dh2, dv2, cw,
					 cw ? startang + halfsweep :
					 startang - halfsweep);
		return;
	}
	if (sweep < arctoosmall) {
		drawelement_line(dh1 + dh2, dv1 + dv2);
		return;
	}
	controldelt = (1.0 - cos(halfsweep)) / (3.0 * sin(halfsweep)) * 4.0;
	x1 = -dv1 * controldelt * ellarc_aoverb * signfactor;
	y1 = dh1 * controldelt * ellarc_bovera * signfactor;
	x3 = dh1 + dh2;
	y3 = dv1 + dv2;
	x2 = x3 - dv2 * controldelt * ellarc_aoverb * signfactor;
	y2 = y3 + dh2 * controldelt * ellarc_bovera * signfactor;
	drawelement_vector(x1, y1);
	drawelement_vector(x2 - x1, y2 - y1);
	drawelement_vector(x3 - x2, y3 - y2);
	*dp++ = CURVETO;
	gotsome++;
}

/*
 * Characterize a circular/elliptic arc by its endpoint vectors.
 * Returns 0 if the endpoint vectors fit a circular arc
 * Returns 1 if the endpoint vectors fit a valid horizontal-vertical ellipse
 * Returns 0 if the endpoint vectors call for an impossible ellipse
 * If the return value is 1, the a and b semiaxes are returned via pointers.
 */
is_arc_elliptic(dh1, dv1, dh2, dv2, ap, bp)
	double *ap, *bp;
{
	int x1sq, x2sq, y1sq, y2sq;
	int diffx, diffy;

	x1sq = dh1 * dh1;
	x2sq = dh2 * dh2;
	y1sq = dv1 * dv1;
	y2sq = dv2 * dv2;
	/*
	 * This first check will weed out some circles
	 * and impossible ellipses that call for division by 0
	 */
	if (x1sq == x2sq || y1sq == y2sq)
		return(0);
	/* all other circles */
	if (x1sq + y1sq == x2sq + y2sq)
		return(0);
	diffx = x2sq - x1sq;
	diffy = y1sq - y2sq;
	/*
	 * More impossible ellipses: sqrt of a negative number
	 */
	if (diffx > 0 && diffy < 0 || diffx < 0 && diffy > 0)
		return(0);
	/* yes, it's a valid ellipse */
	*ap = sqrt((double)y1sq * diffx / diffy + x1sq);
	*bp = sqrt((double)x1sq * diffy / diffx + y1sq);
	return(1);
}

drawelement_genarc_split(dh1, dv1, dh2, dv2, cw, midang)
	double midang;
{
	double cradius, eradius, midrad;
	int midx, midy;

	if (ellarc_flag) {
		midx = ellarc_a * cos(midang);
		midy = ellarc_b * sin(midang);
	} else {
		cradius = hypot((double) dh1, (double) dv1);
		eradius = hypot((double) dh2, (double) dv2);
		midrad = (cradius + eradius) / 2.0;
		midx = midrad * cos(midang);
		midy = midrad * sin(midang);
	}
	drawelement_genarc_seg(dh1, dv1, midx, midy, cw);
	drawelement_genarc_seg(-midx, -midy, dh2, dv2, cw);
}

/*
 * Ditroff smooth curves are quadratic B-splines; PostScript uses
 * Bezier cubics instead.  The conversion algorithm we're using is
 * identical to the one that's been used by Adobe's original psdit
 * (prior to being bastardized by someone at UCB who apparently had
 * no clue what he was doing), except that we do it in C code in the
 * troff front end, whereas Adobe's original psdit did it in PS code
 * in the prolog.
 */
convert_bspline()
{
	int Kx, Ky;
	double Qx, Qy;
	int x1, y1, x2, y2, x3, y3;
	int xlast, ylast;
	register int i;

	Kx = bspline_x[0];
	Ky = bspline_y[0];
	Qx = Qy = 0;
	xlast = ylast = 0;
	bspline_x[0] <<= 1;
	bspline_y[0] <<= 1;
	bspline_x[bspline_npts-1] <<= 1;
	bspline_y[bspline_npts-1] <<= 1;
	for (i = 0; i <= bspline_npts-2; i++) {
		x1 = Qx + bspline_x[i] / 3.0;
		y1 = Qy + bspline_y[i] / 3.0;
		x2 = Qx + (3 * bspline_x[i] + bspline_x[i+1]) / 6.0;
		y2 = Qy + (3 * bspline_y[i] + bspline_y[i+1]) / 6.0;
		x3 = Kx + bspline_x[i+1] / 2;
		y3 = Ky + bspline_y[i+1] / 2;
		Qx = Kx + bspline_x[i+1] / 2.0;
		Qy = Ky + bspline_y[i+1] / 2.0;
		Kx += bspline_x[i+1];
		Ky += bspline_y[i+1];
		drawelement_vector(x1 - xlast, y1 - ylast);
		drawelement_vector(x2 - x1, y2 - y1);
		drawelement_vector(x3 - x2, y3 - y2);
		*dp++ = CURVETO;
		xlast = x3;
		ylast = y3;
	}
	gotsome++;
}
