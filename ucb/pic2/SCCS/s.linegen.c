h04228
s 00006/00003/00207
d D 3.1 85/07/30 15:04:42 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00047/00031/00163
d D 2.1 85/07/23 11:19:54 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00194/00000/00000
d D 1.1 85/07/19 13:58:51 jaap 1 0
c date and time created 85/07/19 13:58:51 by jaap
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
struct obj *linegen(type)
E 2
I 2
obj *linegen(type)
E 2
{
	static float prevdx = HT;
	static float prevdy = 0;
	static float prevw = HT10;
	static float prevh = HT5;
D 2
	int i, j, some, head, ddtype, invis;
E 2
I 2
	int i, j, some, head, ddtype, invis, chop;
E 2
	float ddval, chop1, chop2, x0, y0, x1, y1;
D 2
	int chop;
E 2
	double sin(), cos(), atan2(), theta;
	float defx, defy;
D 2
	struct obj *p, *ppos;
E 2
I 2
	obj *p, *ppos;
E 2
	static int xtab[] = { 1, 0, -1, 0 };	/* R=0, U=1, L=2, D=3 */
	static int ytab[] = { 0, 1, 0, -1 };
	float dx[50], dy[50];
	int ndxy;
	float nx, ny;
I 2
	Attr *ap;
E 2

	nx = curx;
	ny = cury;
	defx = getfval("linewid");
	defy = getfval("lineht");
	prevh = getfval("arrowht");
	prevw = getfval("arrowwid");
	dx[0] = dy[0] = ndxy = some = head = invis = 0;
	chop = chop1 = chop2 = 0;
	ddtype = ddval = 0;
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
		case CHOP:
			if (chop++ == 0)
D 2
				chop1 = chop2 = attr[i].a_val.f;
E 2
I 2
				chop1 = chop2 = ap->a_val.f;
E 2
			else
D 2
				chop2 = attr[i].a_val.f;
E 2
I 2
				chop2 = ap->a_val.f;
E 2
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
		case SAME:
			dx[ndxy] = prevdx;
			dy[ndxy] = prevdy;
			some++;
			break;
		case LEFT:
D 2
			dx[ndxy] -= (attr[i].a_val.f==0) ? defx : attr[i].a_val.f;
E 2
I 2
			dx[ndxy] -= (ap->a_sub==DEFAULT) ? defx : ap->a_val.f;
E 2
			some++;
			hvmode = L_DIR;
			break;
		case RIGHT:
D 2
			dx[ndxy] += (attr[i].a_val.f==0) ? defx : attr[i].a_val.f;
E 2
I 2
			dx[ndxy] += (ap->a_sub==DEFAULT) ? defx : ap->a_val.f;
E 2
			some++;
			hvmode = R_DIR;
			break;
		case UP:
D 2
			dy[ndxy] += (attr[i].a_val.f==0) ? defy : attr[i].a_val.f;
E 2
I 2
			dy[ndxy] += (ap->a_sub==DEFAULT) ? defy : ap->a_val.f;
E 2
			some++;
			hvmode = U_DIR;
			break;
		case DOWN:
D 2
			dy[ndxy] -= (attr[i].a_val.f==0) ? defy : attr[i].a_val.f;
E 2
I 2
			dy[ndxy] -= (ap->a_sub==DEFAULT) ? defy : ap->a_val.f;
E 2
			some++;
			hvmode = D_DIR;
			break;
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
		case TO:
			if (some) {
				nx += dx[ndxy];
				ny += dy[ndxy];
				ndxy++;
				dx[ndxy] = dy[ndxy] = some = 0;
			}
			ppos = attr[i].a_val.o;
			dx[ndxy] = ppos->o_x - nx;
			dy[ndxy] = ppos->o_y - ny;
			some++;
			break;
		case BY:
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			if (some) {
				nx += dx[ndxy];
				ny += dy[ndxy];
				ndxy++;
				dx[ndxy] = dy[ndxy] = some = 0;
			}
			ppos = ap->a_val.o;
E 2
			dx[ndxy] = ppos->o_x;
			dy[ndxy] = ppos->o_y;
			some++;
			break;
		case THEN:	/* turn off any previous accumulation */
			if (some) {
				nx += dx[ndxy];
				ny += dy[ndxy];
				ndxy++;
				dx[ndxy] = dy[ndxy] = some = 0;
			}
			break;
		case FROM:
		case AT:
D 2
			ppos = attr[i].a_val.o;
E 2
I 2
			ppos = ap->a_val.o;
E 2
			nx = curx = ppos->o_x;
			ny = cury = ppos->o_y;
			break;
		}
	}
	if (some) {
		nx += dx[ndxy];
		ny += dy[ndxy];
		ndxy++;
		defx = dx[ndxy-1];
		defy = dy[ndxy-1];
	} else {
		defx *= xtab[hvmode];
		defy *= ytab[hvmode];
		dx[ndxy] = defx;
		dy[ndxy] = defy;
		ndxy++;
		nx += defx;
		ny += defy;
	}
	prevdx = defx;
	prevdy = defy;
	if (chop) {
		if (chop == 1 && chop1 == 0)	/* just said "chop", so use default */
			chop1 = chop2 = getfval("circlerad");
D 3
		theta = atan2((float) defy, (float) defx);
E 3
I 3
		theta = atan2(dy[0], dx[0]);
E 3
		x0 = chop1 * cos(theta);
		y0 = chop1 * sin(theta);
		curx += x0;
		cury += y0;
I 3
		dx[0] -= x0;
		dy[0] -= y0;

		theta = atan2(dy[ndxy-1], dx[ndxy-1]);
E 3
		x1 = chop2 * cos(theta);
		y1 = chop2 * sin(theta);
		nx -= x1;
		ny -= y1;
D 3
		dx[0] -= x0;
		dy[0] -= y0;
E 3
		dx[ndxy-1] -= x1;
		dy[ndxy-1] -= y1;
D 2
		if(dbg)printf("chopping %g %g %g %g; cur=%g,%g end=%g,%g\n",
E 2
I 2
		dprintf("chopping %g %g %g %g; cur=%g,%g end=%g,%g\n",
E 2
			x0, y0, x1, y1, curx, cury, nx, ny);
	}
	p = makenode(type, 5 + 2 * ndxy);
	curx = p->o_val[0] = nx;
	cury = p->o_val[1] = ny;
	if (head || type == ARROW) {
I 2
		p->o_nhead = getfval("arrowhead");
E 2
		p->o_val[2] = prevw;
		p->o_val[3] = prevh;
		if (head == 0)
			head = HEAD2;	/* default arrow head */
	}
D 2
	p->o_attr = head | invis;
E 2
I 2
	p->o_attr = head | invis | ddtype;
E 2
	p->o_val[4] = ndxy;
	nx = p->o_x;
	ny = p->o_y;
	for (i = 0, j = 5; i < ndxy; i++, j += 2) {
		p->o_val[j] = dx[i];
		p->o_val[j+1] = dy[i];
D 2
		extreme(nx += dx[i], ny += dy[i]);
E 2
I 2
		if (type == LINE)
			extreme(nx += dx[i], ny += dy[i]);
		else if (type == SPLINE && i < ndxy-1) {
			/* to compute approx extreme of spline at p,
			/* compute midway between p-1 and p+1,
			/* then go 3/4 from there to p */
			float ex, ey, xi, yi, xi1, yi1;
			xi = nx + dx[i]; yi = ny + dy[i];	/* p */
			xi1 = xi + dx[i+1]; yi1 = yi + dy[i+1];	/* p+1 */
			ex = (nx+xi1)/2; ey = (ny+yi1)/2;	/* midway */
			ex += 0.75*(xi-ex); ey += 0.75*(yi-ey);
			extreme(ex, ey);
			nx = xi; ny = yi;
		}
			
E 2
	}
D 2
	p->o_dotdash = ddtype;
E 2
	p->o_ddval = ddval;
	if (dbg) {
		printf("S or L from %g %g to %g %g with %d elements:\n", p->o_x, p->o_y, curx, cury, ndxy);
		for (i = 0, j = 5; i < ndxy; i++, j += 2)
			printf("%g %g\n", p->o_val[j], p->o_val[j+1]);
	}
	extreme(p->o_x, p->o_y);
	extreme(curx, cury);
	return(p);
D 2
}

struct obj *splinegen(type)
{
	linegen(type);
E 2
}
E 1
