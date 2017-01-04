h51027
s 00001/00000/00118
d D 3.1 85/07/30 15:04:19 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00026/00016/00092
d D 2.1 85/07/23 11:19:48 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00108/00000/00000
d D 1.1 85/07/19 13:58:38 jaap 1 0
c date and time created 85/07/19 13:58:38 by jaap
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

D 2
struct obj *circgen(type)
E 2
I 2
obj *circgen(type)
E 2
{
	static float rad[2] = { HT2, WID2 };
	static float rad2[2] = { HT2, HT2 };
	static float x0, y0, x1, y1, x2, y2;
D 2
	int i, at, t, invis, with;
E 2
I 2
	int i, at, t, invis, ddtype, with;
E 2
	float xwith, ywith;
D 2
	float r, r2;
	struct obj *p, *ppos;
E 2
I 2
	float r, r2, ddval;
	obj *p, *ppos;
	Attr *ap;
E 2

D 2
	at = invis = 0;
E 2
I 2
	at = invis = ddtype = 0;
E 2
	with = xwith = ywith = 0;
	t = (type == CIRCLE) ? 0 : 1;
	if (type == CIRCLE)
		r = r2 = getfval("circlerad");
	else if (type == ELLIPSE) {
		r = getfval("ellipsewid") / 2;
		r2 = getfval("ellipseht") / 2;
	}
D 2
	for (i = 0; i < nattr; i++)
		switch (attr[i].a_type) {
		case LJUST: case RJUST: case CENTER: case SPREAD: case FILL: case ABOVE: case BELOW:
			savetext(attr[i].a_type, attr[i].a_val.p);
E 2
I 2
	for (i = 0; i < nattr; i++) {
		ap = &attr[i];
		switch (ap->a_type) {
		case TEXTATTR:
			savetext(ap->a_sub, ap->a_val.p);
E 2
			break;
		case RADIUS:
D 2
			r = attr[i].a_val.f;
E 2
I 2
			r = ap->a_val.f;
E 2
			break;
		case DIAMETER:
		case WIDTH:
D 2
			r = attr[i].a_val.f / 2;
E 2
I 2
			r = ap->a_val.f / 2;
E 2
			break;
		case HEIGHT:
D 2
			r2 = attr[i].a_val.f / 2;
E 2
I 2
			r2 = ap->a_val.f / 2;
E 2
			break;
		case SAME:
			r = rad[t];
			r2 = rad2[t];
			break;
		case WITH:
D 2
			with = attr[i].a_val.i;
E 2
I 2
			with = ap->a_val.i;
E 2
			break;
		case AT:
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
		}
I 2
	}
E 2
	if (type == CIRCLE)
		r2 = r;	/* probably superfluous */
	if (with) {
		switch (with) {
		case NORTH:	ywith = -r2; break;
		case SOUTH:	ywith = r2; break;
		case EAST:	xwith = -r; break;
		case WEST:	xwith = r; break;
		case NE:	xwith = -r * 0.707; ywith = -r2 * 0.707; break;
		case SE:	xwith = -r * 0.707; ywith = r2 * 0.707; break;
		case NW:	xwith = r * 0.707; ywith = -r2 * 0.707; break;
		case SW:	xwith = r * 0.707; ywith = r2 * 0.707; break;
		}
		curx += xwith;
		cury += ywith;
	}
	if (!at) {
		if (isright(hvmode))
			curx += r;
		else if (isleft(hvmode))
			curx -= r;
		else if (isup(hvmode))
			cury += r2;
		else
			cury -= r2;
	}
	p = makenode(type, 2);
	p->o_val[0] = rad[t] = r;
	p->o_val[1] = rad2[t] = r2;
	if (r <= 0 || r2 <= 0) {
		yyerror("%s has invalid radius %g\n", (type==CIRCLE) ? "circle" : "ellipse", r<r2 ? r : r2);
	}
D 2
	p->o_attr = invis;
E 2
I 2
	p->o_attr = invis | ddtype;
E 2
	extreme(curx+r, cury+r2);
	extreme(curx-r, cury-r2);
	if (type == CIRCLE)
		dprintf("C %g %g %g\n", curx, cury, r);
	if (type == ELLIPSE)
		dprintf("E %g %g %g %g\n", curx, cury, r, r2);
	if (isright(hvmode))
		curx += r;
	else if (isleft(hvmode))
		curx -= r;
	else if (isup(hvmode))
		cury += r2;
	else
		cury -= r2;
	return(p);
}
E 1
