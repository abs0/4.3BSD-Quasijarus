h45655
s 00029/00004/00437
d D 3.1 85/07/30 15:05:04 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00166/00059/00275
d D 2.1 85/07/23 11:20:12 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00334/00000/00000
d D 1.1 85/07/19 13:59:02 jaap 1 0
c date and time created 85/07/19 13:59:02 by jaap
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
setdir(n)	/* set direction from n */
E 2
I 2
setdir(n)	/* set direction (hvmode) from LEFT, RIGHT, etc. */
E 2
	int n;
{
	switch (n) {
	case UP:	hvmode = U_DIR; break;
	case DOWN:	hvmode = D_DIR; break;
	case LEFT:	hvmode = L_DIR; break;
	case RIGHT:	hvmode = R_DIR; break;
	}
	return(hvmode);
}

I 2
curdir()	/* convert current dir (hvmode) to RIGHT, LEFT, etc. */
{
	switch (hvmode) {
	case R_DIR:	return RIGHT;
	case L_DIR:	return LEFT;
	case U_DIR:	return UP;
	case D_DIR:	return DOWN;
	}
}

E 2
float getcomp(p, t)	/* return component of a position */
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2
	int t;
{
	switch (t) {
	case DOTX:
		return p->o_x;
	case DOTY:
		return p->o_y;
	case DOTWID:
		switch (p->o_type) {
		case BOX:
		case BLOCK:
I 3
		case TEXT:
E 3
			return p->o_val[0];
		case CIRCLE:
		case ELLIPSE:
			return 2 * p->o_val[0];
		case LINE:
		case ARROW:
			return p->o_val[0] - p->o_x;
		}
	case DOTHT:
		switch (p->o_type) {
		case BOX:
		case BLOCK:
I 3
		case TEXT:
E 3
			return p->o_val[1];
		case CIRCLE:
		case ELLIPSE:
			return 2 * p->o_val[1];
		case LINE:
		case ARROW:
			return p->o_val[1] - p->o_y;
		}
	case DOTRAD:
		switch (p->o_type) {
		case CIRCLE:
		case ELLIPSE:
			return p->o_val[0];
		}
	}
}

D 2
makeattr(type, val)	/* add attribute type and val */
	int type;
E 2
I 2
float	exprlist[100];
int	nexpr	= 0;

exprsave(f)
	float f;
{
	exprlist[nexpr++] = f;
}

char *sprintgen(fmt)
	char *fmt;
{
	int i;
	char buf[1000];

	sprintf(buf, fmt, exprlist[0], exprlist[1], exprlist[2], exprlist[3], exprlist[4]);
	nexpr = 0;
	free(fmt);
	return tostring(buf);
}

makefattr(type, sub, f)	/* float attr */
	int type, sub;
	float f;
{
E 2
	YYSTYPE val;
I 2
	val.f = f;
	makeattr(type, sub, val);
}

makeoattr(type, o)	/* obj* attr */
	obj *o;
E 2
{
I 2
	YYSTYPE val;
	val.o = o;
	makeattr(type, 0, val);
}

makeiattr(type, i)	/* int attr */
	int i;
{
	YYSTYPE val;
	val.i = i;
	makeattr(type, 0, val);
}

maketattr(sub, p)	/* text attribute: takes two */
	char *p;
{
	YYSTYPE val;
	val.p = p;
	makeattr(TEXTATTR, sub, val);
}

addtattr(sub)		/* add text attrib to existing item */
{
	attr[nattr-1].a_sub |= sub;
}

makevattr(p)	/* varname attribute */
	char *p;
{
	YYSTYPE val;
	val.p = p;
	makeattr(VARNAME, 0, val);
}

makeattr(type, sub, val)	/* add attribute type and val */
	int type, sub;
	YYSTYPE val;
{
E 2
	if (type == 0 && val.i == 0) {	/* clear table for next stat */
		nattr = 0;
		return;
	}
D 2
	dprintf("attr %d:  %d %d\n", nattr, type, val.i);
E 2
I 2
	if (nattr >= nattrlist)
		attr = (Attr *) grow(attr, "attr", nattrlist += 100, sizeof(Attr));
	dprintf("attr %d:  %d %d %d\n", nattr, type, sub, val.i);
E 2
	attr[nattr].a_type = type;
I 2
	attr[nattr].a_sub = sub;
E 2
	attr[nattr].a_val = val;
	nattr++;
}

printexpr(f)	/* print expression for debugging */
	float f;
{
D 2
	dprintf("%g\n", f);
E 2
I 2
	printf("%g\n", f);
E 2
}

printpos(p)	/* print position for debugging */
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2
{
D 2
	dprintf("%g, %g\n", p->o_x, p->o_y);
E 2
I 2
	printf("%g, %g\n", p->o_x, p->o_y);
E 2
}

char *tostring(s)
	register char *s;
{
	register char *p;

	p = malloc(strlen(s)+1);
	if (p == NULL) {
		yyerror("out of space in tostring on %s", s);
		exit(1);
	}
	strcpy(p, s);
	return(p);
}

D 2
struct obj *makepos(x, y)	/* make a osition cell */
E 2
I 2
obj *makepos(x, y)	/* make a osition cell */
E 2
	float x, y;
{
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2

	p = makenode(PLACE, 0);
	p->o_x = x;
	p->o_y = y;
	return(p);
}

D 2
struct obj *makebetween(f, p1, p2)	/* make position between p1 and p2 */
E 2
I 2
obj *makebetween(f, p1, p2)	/* make position between p1 and p2 */
E 2
	float f;
D 2
	struct obj *p1, *p2;
E 2
I 2
	obj *p1, *p2;
E 2
{
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2

	dprintf("fraction = %.2f\n", f);
	p = makenode(PLACE, 0);
	p->o_x = p1->o_x + f * (p2->o_x - p1->o_x);
	p->o_y = p1->o_y + f * (p2->o_y - p1->o_y);
	return(p);
}

D 2
struct obj *getpos(p, corner)	/* find position of point */
	struct obj *p;
E 2
I 2
obj *getpos(p, corner)	/* find position of point */
	obj *p;
E 2
	int corner;
{
I 2
	float x, y;

	whatpos(p, corner, &x, &y);
	return makepos(x, y);
}

whatpos(p, corner, px, py)	/* what is the position (no side effect) */
	obj *p;
	int corner;
	float *px, *py;
{
E 2
	float x, y, x1, y1;
I 2
	extern double sqrt();
E 2

D 2
	dprintf("getpos %o %d\n", p, corner);
E 2
I 2
	dprintf("whatpos %o %d\n", p, corner);
E 2
	x = p->o_x;
	y = p->o_y;
	x1 = p->o_val[0];
	y1 = p->o_val[1];
	switch (p->o_type) {
	case PLACE:
		break;
	case BOX:
	case BLOCK:
I 3
	case TEXT:
E 3
		switch (corner) {
		case NORTH:	y += y1 / 2; break;
		case SOUTH:	y -= y1 / 2; break;
		case EAST:	x += x1 / 2; break;
		case WEST:	x -= x1 / 2; break;
		case NE:	x += x1 / 2; y += y1 / 2; break;
		case SW:	x -= x1 / 2; y -= y1 / 2; break;
		case SE:	x += x1 / 2; y -= y1 / 2; break;
		case NW:	x -= x1 / 2; y += y1 / 2; break;
		case START:
			if (p->o_type == BLOCK)
D 2
				return getpos(objlist[(int)p->o_val[2]], START);
E 2
I 2
				return whatpos(objlist[(int)p->o_val[2]], START, px, py);
E 2
		case END:
			if (p->o_type == BLOCK)
D 2
				return getpos(objlist[(int)p->o_val[3]], END);
E 2
I 2
				return whatpos(objlist[(int)p->o_val[3]], END, px, py);
E 2
		}
		break;
I 2
	case ARC:
		switch (corner) {
		case START:
			if (p->o_attr & CW_ARC) {
				x = p->o_val[2]; y = p->o_val[3];
			} else {
				x = x1; y = y1;
			}
			break;
		case END:
			if (p->o_attr & CW_ARC) {
				x = x1; y = y1;
			} else {
				x = p->o_val[2]; y = p->o_val[3];
			}
			break;
		}
		if (corner == START || corner == END)
			break;
		x1 = y1 = sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
		/* Fall Through! */
E 2
	case CIRCLE:
	case ELLIPSE:
		switch (corner) {
		case NORTH:	y += y1; break;
		case SOUTH:	y -= y1; break;
		case EAST:	x += x1; break;
		case WEST:	x -= x1; break;
		case NE:	x += 0.707 * x1; y += 0.707 * y1; break;
		case SE:	x += 0.707 * x1; y -= 0.707 * y1; break;
		case NW:	x -= 0.707 * x1; y += 0.707 * y1; break;
		case SW:	x -= 0.707 * x1; y -= 0.707 * y1; break;
		}
		break;
	case LINE:
	case SPLINE:
	case ARROW:
	case MOVE:
		switch (corner) {
		case START:	break;	/* already in place */
		case END:	x = x1; y = y1; break;
I 2
		default: /* change! */
E 2
		case CENTER:	x = (x+x1)/2; y = (y+y1)/2; break;
		case NORTH:	if (y1 > y) { x = x1; y = y1; } break;
		case SOUTH:	if (y1 < y) { x = x1; y = y1; } break;
		case EAST:	if (x1 > x) { x = x1; y = y1; } break;
		case WEST:	if (x1 < x) { x = x1; y = y1; } break;
		}
		break;
D 2
	case ARC:
		switch (corner) {
		case START:
			if (p->o_attr & CW_ARC) {
				x = p->o_val[2]; y = p->o_val[3];
			} else {
				x = x1; y = y1;
			}
			break;
		case END:
			if (p->o_attr & CW_ARC) {
				x = x1; y = y1;
			} else {
				x = p->o_val[2]; y = p->o_val[3];
			}
			break;
		}
		break;
E 2
	}
D 2
	dprintf("getpos returns %g %g\n", x, y);
	return(makepos(x, y));
E 2
I 2
	dprintf("whatpos returns %g %g\n", x, y);
	*px = x;
	*py = y;
E 2
}

D 2
struct obj *gethere(n)	/* make a place for curx,cury */
E 2
I 2
obj *gethere(n)	/* make a place for curx,cury */
E 2
{
	dprintf("gethere %g %g\n", curx, cury);
	return(makepos(curx, cury));
}

D 2
struct obj *getlast(n, t)	/* find n-th previous occurrence of type t */
E 2
I 2
obj *getlast(n, t)	/* find n-th previous occurrence of type t */
E 2
	int n, t;
{
	int i, k;
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2

	k = n;
	for (i = nobj-1; i >= 0; i--) {
		p = objlist[i];
		if (p->o_type == BLOCKEND) {
			i = p->o_val[4];
			continue;
		}
		if (p->o_type != t)
			continue;
		if (--k > 0)
			continue;	/* not there yet */
		dprintf("got a last of x,y= %g,%g\n", p->o_x, p->o_y);
		return(p);
	}
	yyerror("there is no %dth last", n);
	return(NULL);
}

D 2
struct obj *getfirst(n, t)	/* find n-th occurrence of type t */
E 2
I 2
obj *getfirst(n, t)	/* find n-th occurrence of type t */
E 2
	int n, t;
{
	int i, k;
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2

	k = n;
	for (i = 0; i < nobj; i++) {
		p = objlist[i];
		if (p->o_type == BLOCK && t != BLOCK) {	/* skip whole block */
			i = p->o_val[5] + 1;
			continue;
		}
		if (p->o_type != t)
			continue;
		if (--k > 0)
			continue;	/* not there yet */
		dprintf("got a first of x,y= %g,%g\n", p->o_x, p->o_y);
		return(p);
	}
	yyerror("there is no %dth ", n);
	return(NULL);
}

I 3
float getblkvar(p, s)	/* find variable s2 in block p */
	obj *p;
	char *s;
{
	YYSTYPE y, getblk();

	y = getblk(p, s);
	return y.f;
}

E 3
D 2
struct obj *getblock(p, s)	/* find variable s in block p */
	struct obj *p;
E 2
I 2
obj *getblock(p, s)	/* find variable s in block p */
	obj *p;
E 2
	char *s;
{
I 3
	YYSTYPE y, getblk();

	y = getblk(p, s);
	return y.o;
}

YYSTYPE getblk(p, s)	/* find union type for s in p */
	obj *p;
	char *s;
{
	static YYSTYPE bug;
E 3
	struct symtab *stp;

	if (p->o_type != BLOCK) {
		yyerror(".%s is not in that block", s);
D 3
		return(NULL);
E 3
I 3
		return(bug);
E 3
	}
D 2
	for (stp = (struct symtab *) p->o_dotdash; stp != NULL; stp = stp->s_next)
E 2
I 2
	for (stp = p->o_symtab; stp != NULL; stp = stp->s_next)
E 2
		if (strcmp(s, stp->s_name) == 0) {
D 3
			dprintf("getblock found x,y= %g,%g\n",
E 3
I 3
			dprintf("getblk found x,y= %g,%g\n",
E 3
				(stp->s_val.o)->o_x, (stp->s_val.o)->o_y);
D 3
			return(stp->s_val.o);
E 3
I 3
			return(stp->s_val);
E 3
		}
	yyerror("there is no .%s in that []", s);
D 3
	return(NULL);
E 3
I 3
	return(bug);
E 3
}

D 2
struct obj *fixpos(p, x, y)
	struct obj *p;
E 2
I 2
obj *fixpos(p, x, y)
	obj *p;
E 2
	float x, y;
{
	dprintf("fixpos returns %g %g\n", p->o_x + x, p->o_y + y);
	return makepos(p->o_x + x, p->o_y + y);
}

D 2
struct obj *makenode(type, n)
E 2
I 2
obj *addpos(p, q)
	obj *p, *q;
{
	dprintf("addpos returns %g %g\n", p->o_x+q->o_x, p->o_y+q->o_y);
	return makepos(p->o_x+q->o_x, p->o_y+q->o_y);
}

obj *subpos(p, q)
	obj *p, *q;
{
	dprintf("subpos returns %g %g\n", p->o_x-q->o_x, p->o_y-q->o_y);
	return makepos(p->o_x-q->o_x, p->o_y-q->o_y);
}

obj *makenode(type, n)
E 2
	int type, n;
{
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2
	int i;
I 2
	extern char *calloc();
E 2

D 2
	p = (struct obj *) malloc(sizeof(struct obj) + (n-1)*sizeof(float));
E 2
I 2
	p = (obj *) calloc(1, sizeof(obj) + (n-1)*sizeof(float));
E 2
	if (p == NULL) {
		yyerror("out of space in makenode\n");
		exit(1);
	}
	p->o_type = type;
	p->o_count = n;
	p->o_nobj = nobj;
	p->o_mode = hvmode;
	p->o_x = curx;
	p->o_y = cury;
	p->o_nt1 = ntext1;
	p->o_nt2 = ntext;
	ntext1 = ntext;	/* ready for next caller */
D 2
	p->o_attr = p->o_dotdash = p->o_ddval = 0;
	for (i = 0; i < n; i++)
		p->o_val[i] = 0;
	if (nobj >= MAXOBJ) {
		yyerror("objlist overflow\n");
		exit(1);
	}
E 2
I 2
	if (nobj >= nobjlist)
		objlist = (obj **) grow(objlist, "objlist",
			nobjlist += 100, sizeof(obj *));
E 2
	objlist[nobj++] = p;
	return(p);
}

extreme(x, y)	/* record max and min x and y values */
	float x, y;
{
	if (x > xmax)
		xmax = x;
	if (y > ymax)
		ymax = y;
	if (x < xmin)
		xmin = x;
	if (y < ymin)
		ymin = y;
}
E 1
