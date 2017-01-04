h07843
s 00001/00000/00223
d D 3.1 85/07/30 15:03:55 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00101/00023/00122
d D 2.1 85/07/23 11:19:28 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00145/00000/00000
d D 1.1 85/07/19 13:58:29 jaap 1 0
c date and time created 85/07/19 13:58:29 by jaap
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

E 2
#include	<stdio.h>
I 2
#include	<math.h>
E 2
#include	"pic.h"
#include	"y.tab.h"

D 2
struct obj *arcgen(type)	/* handles circular and (eventually) elliptical arcs */
E 2
I 2
obj *arcgen(type)	/* handles circular and (eventually) elliptical arcs */
E 2
{
	static float prevw = HT10;
	static float prevh = HT5;
	static float prevrad = HT2;
	static int dtox[2][4] ={ 1, -1, -1, 1, 1, 1, -1, -1 };
	static int dtoy[2][4] ={ 1, 1, -1, -1, -1, 1, 1, -1 };
	static int dctrx[2][4] ={ 0, -1, 0, 1, 0, 1, 0, -1 };
	static int dctry[2][4] ={ 1, 0, -1, 0, -1, 0, 1, 0 };
	static int nexthv[2][4] ={ U_DIR, L_DIR, D_DIR, R_DIR, D_DIR, R_DIR, U_DIR, L_DIR };
D 2
	double sqrt(), atan2(), sin(), cos();
	float dx2, dy2, ht, phi, r, d;
	int i, head, to, at, cw, invis;
	struct obj *p, *ppos;
E 2
I 2
	float dx2, dy2, ht, phi, r, d, ddval;
	int i, head, to, at, cw, invis, ddtype;
	obj *p, *ppos;
E 2
	float fromx, fromy, tox, toy;
I 2
	Attr *ap;
E 2

	prevrad = getfval("arcrad");
	prevh = getfval("arrowht");
	prevw = getfval("arrowwid");
	fromx = curx;
	fromy = cury;
D 2
	head = to = at = cw = invis = 0;
E 2
I 2
	head = to = at = cw = invis = ddtype = 0;
E 2
	for (i = 0; i < nattr; i++) {
D 2
		switch (attr[i].a_type) {
		case LJUST: case RJUST: case CENTER: case SPREAD: case FILL: case ABOVE: case BELOW:
			savetext(attr[i].a_type, attr[i].a_val.p);
E 2
I 2
		ap = &attr[i];
		switch (ap->a_type) {
		case TEXTATTR:
			savetext(ap->a_sub, ap->a_val.p);
E 2
			break;
		case HEAD:
D 2
			head += attr[i].a_val.i;
E 2
I 2
			head += ap->a_val.i;
E 2
			break;
		case INVIS:
			invis = INVIS;
			break;
I 2
		case DOT:
		case DASH:
			ddtype = ap->a_type==DOT ? DOTBIT : DASHBIT;
			if (ap->a_sub == DEFAULT)
				ddval = getfval("dashwid");
			else
				ddval = ap->a_val.f;
			break;
E 2
		case HEIGHT:	/* length of arrowhead */
D 2
			prevh = attr[i].a_val.f;
E 2
I 2
			prevh = ap->a_val.f;
E 2
			break;
		case WIDTH:	/* width of arrowhead */
D 2
			prevw = attr[i].a_val.f;
E 2
I 2
			prevw = ap->a_val.f;
E 2
			break;
		case RADIUS:
D 2
			prevrad = attr[i].a_val.f;
E 2
I 2
			prevrad = ap->a_val.f;
E 2
			break;
		case DIAMETER:
D 2
			prevrad = attr[i].a_val.f / 2;
E 2
I 2
			prevrad = ap->a_val.f / 2;
E 2
			break;
		case CW:
			cw = 1;
			break;
		case FROM:	/* start point of arc */
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			fromx = ppos->o_x;
			fromy = ppos->o_y;
			break;
		case TO:	/* end point of arc */
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			tox = ppos->o_x;
			toy = ppos->o_y;
			to++;
			break;
		case AT:	/* center of arc */
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			curx = ppos->o_x;
			cury = ppos->o_y;
			at = 1;
			break;
		case UP:
			hvmode = U_DIR;
			break;
		case DOWN:
			hvmode = D_DIR;
			break;
		case RIGHT:
			hvmode = R_DIR;
			break;
		case LEFT:
			hvmode = L_DIR;
			break;
		}
	}
	if (!at && !to) {	/* the defaults are mostly OK */
		curx = fromx + prevrad * dctrx[cw][hvmode];
		cury = fromy + prevrad * dctry[cw][hvmode];
		tox = fromx + prevrad * dtox[cw][hvmode];
		toy = fromy + prevrad * dtoy[cw][hvmode];
		hvmode = nexthv[cw][hvmode];
	}
	else if (!at) {
		dx2 = (tox - fromx) / 2;
		dy2 = (toy - fromy) / 2;
D 2
		phi = atan2(dy2, dx2) + (cw ? -PI2 : PI2);
E 2
I 2
		phi = atan2(dy2, dx2) + (cw ? -PI/2 : PI/2);
		if (prevrad <= 0.0)
			prevrad = dx2*dx2+dy2*dy2;
E 2
		for (r=prevrad; (d = r*r - (dx2*dx2+dy2*dy2)) <= 0.0; r *= 2)
			;	/* this kludge gets around too-small radii */
		prevrad = r;
		ht = sqrt(d);
		curx = fromx + dx2 + ht * cos(phi);
		cury = fromy + dy2 + ht * sin(phi);
		dprintf("dx2,dy2=%g,%g, phi=%g, r,ht=%g,%g\n",
			dx2, dy2, phi, r, ht);
	}
	else if (at && !to) {	/* do we have all the cases??? */
		tox = fromx + prevrad * dtox[cw][hvmode];
		toy = fromy + prevrad * dtoy[cw][hvmode];
		hvmode = nexthv[cw][hvmode];
	}
	if (cw) {	/* interchange roles of from-to and heads */
		float temp;
		temp = fromx; fromx = tox; tox = temp;
		temp = fromy; fromy = toy; toy = temp;
		if (head == HEAD1)
			head = HEAD2;
		else if (head == HEAD2)
			head = HEAD1;
	}
	p = makenode(type, 7);
D 2
	/* these are wrong in general */
	extreme(fromx, fromy);
	extreme(tox, toy);
E 2
I 2
	arc_extreme(fromx, fromy, tox, toy, curx, cury);
E 2
	p->o_val[0] = fromx;
	p->o_val[1] = fromy;
	p->o_val[2] = tox;
	p->o_val[3] = toy;
	if (cw) {
		curx = fromx;
		cury = fromy;
	} else {
		curx = tox;
		cury = toy;
	}
	p->o_val[4] = prevw;
	p->o_val[5] = prevh;
	p->o_val[6] = prevrad;
D 2
	p->o_attr = head | (cw ? CW_ARC : 0) | invis;
E 2
I 2
	p->o_attr = head | (cw ? CW_ARC : 0) | invis | ddtype;
	if (head)
		p->o_nhead = getfval("arrowhead");
E 2
	dprintf("arc rad %g at %g %g from %g %g to %g %g head %g %g\n",
		prevrad, p->o_x, p->o_y,
		p->o_val[0], p->o_val[1], p->o_val[2], p->o_val[3], p->o_val[4], p->o_val[5]);
	return(p);
}
I 2

/***************************************************************************
   bounding box of a circular arc             Eric Grosse  24 May 84

Conceptually, this routine generates a list consisting of the start,
end, and whichever north, east, south, and west points lie on the arc.
The bounding box is then the range of this list.
    list = {start,end}
    j = quadrant(start)
    k = quadrant(end)
    if( j==k && long way 'round )  append north,west,south,east
    else
      while( j != k )
         append center+radius*[j-th of north,west,south,east unit vectors]
         j += 1  (mod 4)
    return( bounding box of list )
The following code implements this, with simple optimizations.
***********************************************************************/


arc_extreme(x0, y0, x1, y1, xc, yc)
	double x0, y0, x1, y1, xc, yc;  /* start, end, center */
{
	/* assumes center isn't too far out */
	double r, x, y, xmin, ymin, xmax, ymax;
	int j, k;
	x0 -= xc; y0 -= yc;	/* move to center */
	x1 -= xc; y1 -= yc;
	xmin = (x0<x1)?x0:x1; ymin = (y0<y1)?y0:y1;
	xmax = (x0>x1)?x0:x1; ymax = (y0>y1)?y0:y1;
	r = sqrt(x0*x0 + y0*y0);
	if (r > 0.0) {
		j = quadrant(x0,y0);
		k = quadrant(x1,y1);
		if (j == k && y1*x0 < x1*y0) {
			/* viewed as complex numbers, if Im(z1/z0)<0, arc is big */
			if( xmin > -r) xmin = -r; if( ymin > -r) ymin = -r;
			if( xmax <  r) xmax =  r; if( ymax <  r) ymax =  r;
		} else {
			while (j != k) {
				switch (j) {
					case 1: if( ymax <  r) ymax =  r; break; /* north */
					case 2: if( xmin > -r) xmin = -r; break; /* west */
					case 3: if( ymin > -r) ymin = -r; break; /* south */
					case 4: if( xmax <  r) xmax =  r; break; /* east */
				}
				j = j%4 + 1;
			}
		}
	}
	xmin += xc; ymin += yc;
	xmax += xc; ymax += yc;
	extreme(xmin, ymin);
	extreme(xmax, ymax);
}

quadrant(x,y)
	double x, y;
{
	if (     x>=0.0 && y> 0.0) return(1);
	else if( x< 0.0 && y>=0.0) return(2);
	else if( x<=0.0 && y< 0.0) return(3);
	else if( x> 0.0 && y<=0.0) return(4);
	else
		{ fprintf(stderr,"can't happen: x,y=%g,%g",x,y); exit(1);}
}

E 2
E 1
