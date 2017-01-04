h03452
s 00001/00000/00118
d D 3.1 85/07/30 15:06:21 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00097/00044/00021
d D 2.1 85/07/23 11:21:28 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00065/00000/00000
d D 1.1 85/07/19 13:59:39 jaap 1 0
c date and time created 85/07/19 13:59:39 by jaap
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
struct obj *textgen(s)
E 2
I 2
obj *textgen()
E 2
{
D 2
	int i, type;
	float dx, dy;
	struct obj *p, *ppos;
E 2
I 2
	int i, type, sub, nstr, at, with, hset;
	float xwith, ywith, h, w, x0, y0, x1, y1;
	obj *p, *ppos;
	static float prevh = 0;
	static float prevw = 0;
	Attr *ap;
E 2

D 2
	type = 'C';
	dx = dy = 0;
	for (i = 0; i < nattr; i++)
		switch (attr[i].a_type) {
		case LEFT:
			dx -= attr[i].a_val.f;
E 2
I 2
	sub = CENTER;
	at = with = nstr = hset = 0;
	h = getfval("textht");
	w = getfval("textwid");
	for (i = 0; i < nattr; i++) {
		ap = &attr[i];
		switch (ap->a_type) {
		case HEIGHT:
			h = ap->a_val.f;
			hset++;
E 2
			break;
D 2
		case RIGHT:
			dx += attr[i].a_val.f;
E 2
I 2
		case WIDTH:
			w = ap->a_val.f;
E 2
			break;
D 2
		case UP:
			dy += attr[i].a_val.f;
E 2
I 2
		case WITH:
			with = ap->a_val.i;
E 2
			break;
D 2
		case DOWN:
			dy -= attr[i].a_val.f;
			break;
E 2
		case AT:
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			curx = ppos->o_x;
			cury = ppos->o_y;
I 2
			at++;
E 2
			break;
D 2
		case LJUST:
			type = 'L';
E 2
I 2
		case TEXTATTR:
			sub = ap->a_sub;
			if (ap->a_val.p == NULL)	/* an isolated modifier */
				text[ntext-1].t_type = sub;
			else {
				savetext(sub, ap->a_val.p);
				nstr++;
			}
E 2
			break;
D 2
		case RJUST:
			type = 'R';
			break;
		case SPREAD:
			type = 'S';
			break;
		case FILL:
			type = 'F';
			break;
		case ABOVE:
			type = 'A';
			break;
		case BELOW:
			type = 'B';
			break;
E 2
		}
D 2
	dprintf("T %c %s\n", type, s);
	extreme(curx, cury);
	curx += dx;
	cury += dy;
	extreme(curx, cury);
E 2
I 2
	}
	if (hset == 0)		/* no explicit ht cmd */
		h *= nstr;
	if (with) {
		xwith = ywith = 0.0;
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
	dprintf("Text h %g w %g at %g,%g\n", h, w, curx, cury);
E 2
	p = makenode(TEXT, 2);
D 2
	p->o_val[0] = p->o_val[1] = 0;
	p->o_attr = s;	/* kludge into funny place to avoid coercion */
	p->o_dotdash = type;
E 2
I 2
	p->o_val[0] = w;
	p->o_val[1] = h;
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
E 2
	return(p);
I 2
}

obj *troffgen(s)	/* save away a string of troff commands */
	YYSTYPE s;
{
	savetext(CENTER, s.p);	/* use the existing text mechanism */
	return makenode(TROFF, 0);
}

savetext(t, s)	/* record text elements for current object */
	int t;
	char *s;
{
	if (ntext >= ntextlist)
		text = (Text *) grow(text, "text", ntextlist += 200, sizeof(Text));
	text[ntext].t_type = t;
	text[ntext].t_val = s;
	dprintf("saving %d text %s at %d\n", t, s, ntext);
	ntext++;
E 2
}
E 1
