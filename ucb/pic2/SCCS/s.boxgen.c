h30191
s 00001/00000/00108
d D 3.1 85/07/30 15:04:14 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00018/00019/00090
d D 2.1 85/07/23 11:19:43 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00109/00000/00000
d D 1.1 85/07/19 13:58:35 jaap 1 0
c date and time created 85/07/19 13:58:35 by jaap
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
struct obj *boxgen(type)
E 2
I 2
obj *boxgen(type)
E 2
{
	static float prevh = HT;
	static float prevw = WID;	/* golden mean, sort of */
D 2
	int i, invis, at, ddtype;
E 2
I 2
	int i, invis, at, ddtype, with;
E 2
	float ddval, xwith, ywith;
D 2
	int with;
	float h, w;
	float x0, y0, x1, y1;
	struct obj *p, *ppos;
E 2
I 2
	float h, w, x0, y0, x1, y1;
	obj *p, *ppos;
	Attr *ap;
E 2

	h = getfval("boxht");
	w = getfval("boxwid");
	invis = at = 0;
	with = xwith = ywith = 0;
	ddtype = ddval = 0;
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
		case SAME:
			h = prevh;
			w = prevw;
			break;
		case WITH:
D 2
			with = attr[i].a_val.i;	/* corner */
E 2
I 2
			with = ap->a_val.i;	/* corner */
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
		case DOT:
		case DASH:
D 2
			ddtype = attr[i].a_type;
			ddval = attr[i].a_val.f;
			if (ddval == 0)
E 2
I 2
			ddtype = ap->a_type==DOT ? DOTBIT : DASHBIT;
			if (ap->a_sub == DEFAULT)
E 2
				ddval = getfval("dashwid");
I 2
			else
				ddval = ap->a_val.f;
E 2
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
	p = makenode(BOX, 2);
	p->o_val[0] = w;
	p->o_val[1] = h;
D 2
	p->o_dotdash = ddtype;
E 2
	p->o_ddval = ddval;
D 2
	p->o_attr = invis;
E 2
I 2
	p->o_attr = invis | ddtype;
E 2
	dprintf("B %g %g %g %g at %g %g, h=%g, w=%g\n", x0, y0, x1, y1, curx, cury, h, w);
	if (isright(hvmode))
		curx = x1;
	else if (isleft(hvmode))
		curx = x0;
	else if (isup(hvmode))
		cury = y1;
	else
		cury = y0;
	prevh = h;
	prevw = w;
	return(p);
}
E 1
