h58392
s 00001/00000/00089
d D 3.1 85/07/30 15:05:30 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00015/00014/00074
d D 2.1 85/07/23 11:20:24 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00088/00000/00000
d D 1.1 85/07/19 13:59:09 jaap 1 0
c date and time created 85/07/19 13:59:09 by jaap
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
struct obj *movegen(type)
E 2
I 2
obj *movegen(type)
E 2
{
	static float prevdx, prevdy;
	int i, some;
	float defx, defy, dx, dy;
D 2
	struct obj *p;
	struct obj *ppos;
E 2
I 2
	obj *p;
	obj *ppos;
E 2
	static int xtab[] = { 1, 0, -1, 0 };	/* R=0, U=1, L=2, D=3 */
	static int ytab[] = { 0, 1, 0, -1 };
I 2
	Attr *ap;
E 2

	defx = getfval("movewid");
	defy = getfval("moveht");
	dx = dy = some = 0;
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
		case SAME:
			dx = prevdx;
			dy = prevdy;
			some++;
			break;
		case LEFT:
D 2
			dx -= (attr[i].a_val.f==0) ? defx : attr[i].a_val.f;
E 2
I 2
			dx -= (ap->a_sub==DEFAULT) ? defx : ap->a_val.f;
E 2
			some++;
			hvmode = L_DIR;
			break;
		case RIGHT:
D 2
			dx += (attr[i].a_val.f==0) ? defx : attr[i].a_val.f;
E 2
I 2
			dx += (ap->a_sub==DEFAULT) ? defx : ap->a_val.f;
E 2
			some++;
			hvmode = R_DIR;
			break;
		case UP:
D 2
			dy += (attr[i].a_val.f==0) ? defy : attr[i].a_val.f;
E 2
I 2
			dy += (ap->a_sub==DEFAULT) ? defy : ap->a_val.f;
E 2
			some++;
			hvmode = U_DIR;
			break;
		case DOWN:
D 2
			dy -= (attr[i].a_val.f==0) ? defy : attr[i].a_val.f;
E 2
I 2
			dy -= (ap->a_sub==DEFAULT) ? defy : ap->a_val.f;
E 2
			some++;
			hvmode = D_DIR;
			break;
		case TO:
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			dx = ppos->o_x - curx;
			dy = ppos->o_y - cury;
			some++;
			break;
		case BY:
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			dx = ppos->o_x;
			dy = ppos->o_y;
			some++;
			break;
		case FROM:
		case AT:
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			curx = ppos->o_x;
			cury = ppos->o_y;
			break;
		}
	}
	if (some) {
		defx = dx;
		defy = dy;
	} else {
		defx *= xtab[hvmode];
		defy *= ytab[hvmode];
	}
	prevdx = defx;
	prevdy = defy;
	extreme(curx, cury);
	curx += defx;
	cury += defy;
	extreme(curx, cury);
	p = makenode(MOVE, 0);
	dprintf("M %g %g\n", curx, cury);
	return(p);
}
E 1
