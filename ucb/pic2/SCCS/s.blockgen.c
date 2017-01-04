h58513
s 00002/00000/00228
d D 3.1 85/07/30 15:04:05 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00051/00043/00177
d D 2.1 85/07/23 11:19:34 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00220/00000/00000
d D 1.1 85/07/19 13:58:32 jaap 1 0
c date and time created 85/07/19 13:58:32 by jaap
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
#include	"pic.h"
#include	"y.tab.h"

I 2
#define	NBRACK	20	/* depth of [...] */
#define	NBRACE	20	/* depth of {...} */
E 2

D 2
struct pushstack stack[20];
E 2
I 2
struct pushstack stack[NBRACK];
E 2
int	nstack	= 0;
I 2
struct pushstack bracestack[NBRACE];
int	nbstack	= 0;
E 2

D 2
struct obj *leftthing(c)	/* called for {... or [... */
E 2
I 2
obj *leftthing(c)	/* called for {... or [... */
			/* really ought to be separate functions */
E 2
	int c;
{
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2

D 2
	stack[nstack].p_x = curx;
	stack[nstack].p_y = cury;
	stack[nstack].p_hvmode = hvmode;
E 2
	if (c == '[') {
I 2
		if (nstack >= NBRACK)
			fatal("[...] nested too deep");
		stack[nstack].p_x = curx;
		stack[nstack].p_y = cury;
		stack[nstack].p_hvmode = hvmode;
E 2
		curx = cury = 0;
		stack[nstack].p_xmin = xmin;
		stack[nstack].p_xmax = xmax;
		stack[nstack].p_ymin = ymin;
		stack[nstack].p_ymax = ymax;
I 2
		nstack++;
E 2
		xmin = ymin = 30000;
		xmax = ymax = -30000;
		p = makenode(BLOCK, 7);
		p->o_val[4] = nobj;	/* 1st item within [...] */
		if (p->o_nobj != nobj-1)
			fprintf(stderr, "nobjs wrong%d %d\n", p->o_nobj, nobj);
D 2
	}
	else
E 2
I 2
	} else {
		if (nbstack >= NBRACK)
			fatal("{...} nested too deep");
		bracestack[nbstack].p_x = curx;
		bracestack[nbstack].p_y = cury;
		bracestack[nbstack].p_hvmode = hvmode;
		nbstack++;
E 2
		p = NULL;
D 2
	nstack++;
E 2
I 2
	}
E 2
	return(p);
}

D 2
struct obj *rightthing(p, c)	/* called for ... ] or ... } */
	struct obj *p;
E 2
I 2
obj *rightthing(p, c)	/* called for ... ] or ... } */
	obj *p;
E 2
{
D 2
	struct obj *q;
E 2
I 2
	obj *q;
E 2

D 2
	nstack--;
	curx = stack[nstack].p_x;
	cury = stack[nstack].p_y;
	hvmode = stack[nstack].p_hvmode;
E 2
	if (c == '}') {
I 2
		nbstack--;
		curx = bracestack[nbstack].p_x;
		cury = bracestack[nbstack].p_y;
		hvmode = bracestack[nbstack].p_hvmode;
E 2
		q = makenode(MOVE, 0);
		dprintf("M %g %g\n", curx, cury);
	} else {
I 2
		nstack--;
		curx = stack[nstack].p_x;
		cury = stack[nstack].p_y;
		hvmode = stack[nstack].p_hvmode;
E 2
		q = makenode(BLOCKEND, 7);
		q->o_val[4] = p->o_nobj + 1;	/* back pointer */
		p->o_val[5] = q->o_nobj - 1;	/* forward pointer */
		p->o_val[0] = xmin; p->o_val[1] = ymin;
		p->o_val[2] = xmax; p->o_val[3] = ymax;
D 2
		p->o_dotdash = q->o_dotdash = (int) stack[nstack+1].p_symtab;
E 2
I 2
		p->o_symtab = q->o_symtab = stack[nstack+1].p_symtab;
E 2
		xmin = stack[nstack].p_xmin;
		ymin = stack[nstack].p_ymin;
		xmax = stack[nstack].p_xmax;
		ymax = stack[nstack].p_ymax;
	}
	return(q);
}

D 2
struct obj *blockgen(p, type, q)	/* handles [...] */
	struct obj *p, *q;
E 2
I 2
obj *blockgen(p, type, q)	/* handles [...] */
	obj *p, *q;
E 2
	int type;
{
D 2
	static float prevh = HT;
	static float prevw = WID;	/* golden mean, sort of */
	int i, invis, at, ddtype;
	float ddval;
	int with;
	float h, w, xwith, ywith;
E 2
I 2
	int i, invis, at, ddtype, with;
	float ddval, h, w, xwith, ywith;
E 2
	float x0, y0, x1, y1, cx, cy;
D 2
	struct obj *ppos;
E 2
I 2
	obj *ppos;
	Attr *ap;
E 2

	invis = at = 0;
	with = xwith = ywith = 0;
	ddtype = ddval = 0;
	w = p->o_val[2] - p->o_val[0];
	h = p->o_val[3] - p->o_val[1];
	cx = (p->o_val[2] + p->o_val[0]) / 2;	/* geom ctr of [] wrt local orogin */
	cy = (p->o_val[3] + p->o_val[1]) / 2;
	dprintf("cx,cy=%g,%g\n", cx, cy);
	for (i = 0; i < nattr; i++) {
D 2
		switch (attr[i].a_type) {
E 2
I 2
		ap = &attr[i];
		switch (ap->a_type) {
E 2
		case HEIGHT:
D 2
			h = attr[i].a_val.f;
E 2
I 2
			h = ap->a_val.f;
E 2
			break;
		case WIDTH:
D 2
			w = attr[i].a_val.f;
E 2
I 2
			w = ap->a_val.f;
E 2
			break;
D 2
		case SAME:
			h = prevh;
			w = prevw;
			break;
E 2
		case WITH:
D 2
			with = attr[i].a_val.i;	/* corner */
E 2
I 2
			with = ap->a_val.i;	/* corner */
E 2
			break;
		case PLACE:	/* actually with position ... */
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			xwith = cx - ppos->o_x;
			ywith = cy - ppos->o_y;
			with = PLACE;
			break;
		case AT:
I 3
		case FROM:
E 3
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			curx = ppos->o_x;
			cury = ppos->o_y;
			at++;
			break;
		case INVIS:
			invis = INVIS;
			break;
D 2
		case LJUST: case RJUST: case CENTER: case SPREAD: case FILL: case ABOVE: case BELOW:
			savetext(attr[i].a_type, attr[i].a_val.p);
E 2
I 2
		case TEXTATTR:
			savetext(ap->a_sub, ap->a_val.p);
E 2
			break;
		}
	}
	if (with) {
		switch (with) {
		case NORTH:	ywith = -h / 2; break;
		case SOUTH:	ywith = h / 2; break;
		case EAST:	xwith = -w / 2; break;
		case WEST:	xwith = w / 2; break;
		case NE:	xwith = -w / 2; ywith = -h / 2; break;
		case SE:	xwith = -w / 2; ywith = h / 2; break;
		case NW:	xwith = w / 2; ywith = -h / 2; break;
		case SW:	xwith = w / 2; ywith = h / 2; break;
		}
		curx += xwith;
		cury += ywith;
	}
	if (!at) {
		if (isright(hvmode))
			curx += w / 2;
		else if (isleft(hvmode))
			curx -= w / 2;
		else if (isup(hvmode))
			cury += h / 2;
		else
			cury -= h / 2;
	}
	x0 = curx - w / 2;
	y0 = cury - h / 2;
	x1 = curx + w / 2;
	y1 = cury + h / 2;
	extreme(x0, y0);
	extreme(x1, y1);
	p->o_x = curx;
	p->o_y = cury;
	p->o_nt1 = ntext1;
	p->o_nt2 = ntext;
	ntext1 = ntext;
	p->o_val[0] = w;
	p->o_val[1] = h;
	p->o_val[2] = cx;
	p->o_val[3] = cy;
	p->o_val[5] = q->o_nobj - 1;		/* last item in [...] */
	p->o_ddval = ddval;
	p->o_attr = invis;
	dprintf("[] %g %g %g %g at %g %g, h=%g, w=%g\n", x0, y0, x1, y1, curx, cury, h, w);
	if (isright(hvmode))
		curx = x1;
	else if (isleft(hvmode))
		curx = x0;
	else if (isup(hvmode))
		cury = y1;
	else
		cury = y0;
	for (i = 0; i <= 5; i++)
		q->o_val[i] = p->o_val[i];
	stack[nstack+1].p_symtab = NULL;	/* so won't be found again */
	blockadj(p);	/* fix up coords for enclosed blocks */
D 2
	prevh = h;
	prevw = w;
E 2
	return(p);
}

blockadj(p)	/* adjust coords in block starting at p */
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2
{
D 2
	struct obj *q;
E 2
I 2
	obj *q;
E 2
	float dx, dy;
	int n, lev;

	dx = p->o_x - p->o_val[2];
	dy = p->o_y - p->o_val[3];
	n = p->o_nobj + 1;
	q = objlist[n];
	dprintf("into blockadj: dx,dy=%g,%g\n", dx, dy);
	for (lev = 1; lev > 0; n++) {
		p = objlist[n];
		if (p->o_type == BLOCK)
			lev++;
		else if (p->o_type == BLOCKEND)
			lev--;
		dprintf("blockadj: type=%d o_x,y=%g,%g;", p->o_type, p->o_x, p->o_y);
		p->o_x += dx;
		p->o_y += dy;
		dprintf(" becomes %g,%g\n", p->o_x, p->o_y);
		switch (p->o_type) {	/* other absolute coords */
		case LINE:
		case ARROW:
		case SPLINE:
			p->o_val[0] += dx;
			p->o_val[1] += dy;
			break;
		case ARC:
			p->o_val[0] += dx;
			p->o_val[1] += dy;
			p->o_val[2] += dx;
			p->o_val[3] += dy;
			break;
		}
	}
}
E 1
