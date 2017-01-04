h63661
s 00002/00001/00194
d D 3.1 85/07/30 15:06:04 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00019/00038/00176
d D 2.1 85/07/23 11:21:16 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00214/00000/00000
d D 1.1 85/07/19 13:59:33 jaap 1 0
c date and time created 85/07/19 13:59:33 by jaap
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
int xxx;
E 2
print()
{
D 2
	struct obj *p;
	int i, j, m;
E 2
I 2
	obj *p;
	int i, j, k, m;
E 2
	float x0, y0, x1, y1, ox, oy, dx, dy, ndx, ndy;

	for (i = 0; i < nobj; i++) {
D 2
		xxx = i;
E 2
		p = objlist[i];
		ox = p->o_x;
		oy = p->o_y;
		if (p->o_count >= 1)
			x1 = p->o_val[0];
		if (p->o_count >= 2)
			y1 = p->o_val[1];
		m = p->o_mode;
		switch (p->o_type) {
		case TROFF:
			troff(text[p->o_nt1].t_val);
			break;
		case BOX:
		case BLOCK:
			move(ox, oy);
			dotext(p);	/* if there are any text strings */
			x0 = ox - x1 / 2;
			y0 = oy - y1 / 2;
			x1 = ox + x1 / 2;
			y1 = oy + y1 / 2;
			if (p->o_attr & INVIS || p->o_type == BLOCK)
				;	/* nothing at all */
D 2
			else if (p->o_dotdash == 0)
				box(x0, y0, x1, y1);
E 2
I 2
			else if (p->o_attr & (DOTBIT|DASHBIT))
				dotbox(x0, y0, x1, y1, p->o_attr, p->o_ddval);
E 2
			else
D 2
				dotbox(x0, y0, x1, y1, p->o_dotdash, p->o_ddval);
E 2
I 2
				box(x0, y0, x1, y1);
E 2
			if (ishor(m))
				move(isright(m) ? x1 : x0, oy);	/* right side */
			else
				move(ox, isdown(m) ? y0 : y1);	/* bottom */
			break;
		case BLOCKEND:
			break;
D 2
			x0 = ox - x1 / 2;
			y0 = oy - y1 / 2;
			x1 = ox + x1 / 2;
			y1 = oy + y1 / 2;
			if (ishor(m))
				move(isright(m) ? x1 : x0, oy);	/* right side */
			else
				move(ox, isdown(m) ? y0 : y1);	/* bottom */
			break;
E 2
		case CIRCLE:
			move(ox, oy);
			dotext(p);
			if ((p->o_attr & INVIS) == 0)
				circle(ox, oy, x1);
			if (ishor(m))
				move(ox + isright(m) ? x1 : -x1, oy);
			else
				move(ox, oy + isup(m) ? x1 : -x1);
			break;
		case ELLIPSE:
			move(ox, oy);
			dotext(p);
			if ((p->o_attr & INVIS) == 0)
				ellipse(ox, oy, x1, y1);
			if (ishor(m))
				move(ox + isright(m) ? x1 : -x1, oy);
			else
				move(ox, oy - isdown(m) ? y1 : -y1);
			break;
		case ARC:
			move(ox, oy);
			dotext(p);
			if (p->o_attr & HEAD1)
				arrow(x1 - (y1 - oy), y1 + (x1 - ox),
D 2
				      x1, y1, p->o_val[4], p->o_val[5]);
E 2
I 2
				      x1, y1, p->o_val[4], p->o_val[5], p->o_val[5]/p->o_val[6]/2, p->o_nhead);
E 2
                        if (p->o_attr & INVIS)
                                /* probably wrong when it's cw */
                                move(x1, y1);
                        else
D 2
				arc(ox, oy, x1, y1, p->o_val[2], p->o_val[3], p->o_val[6]
					,(p->o_attr&CW_ARC));
E 2
I 2
				arc(ox, oy, x1, y1, p->o_val[2], p->o_val[3]);
E 2
			if (p->o_attr & HEAD2)
				arrow(p->o_val[2] + p->o_val[3] - oy, p->o_val[3] - (p->o_val[2] - ox),
D 2
				      p->o_val[2], p->o_val[3], p->o_val[4], p->o_val[5]);
E 2
I 2
				      p->o_val[2], p->o_val[3], p->o_val[4], p->o_val[5], -p->o_val[5]/p->o_val[6]/2, p->o_nhead);
E 2
			if (p->o_attr & CW_ARC)
				move(x1, y1);	/* because drawn backwards */
			break;
		case LINE:
		case ARROW:
		case SPLINE:
			move((ox + x1)/2, (oy + y1)/2);	/* center */
			dotext(p);
			if (p->o_attr & HEAD1)
D 2
				arrow(ox + p->o_val[5], oy + p->o_val[6], ox, oy, p->o_val[2], p->o_val[3]);
E 2
I 2
				arrow(ox + p->o_val[5], oy + p->o_val[6], ox, oy, p->o_val[2], p->o_val[3], 0.0, p->o_nhead);
E 2
                        if (p->o_attr & INVIS)
                                move(x1, y1);
			else if (p->o_type == SPLINE)
D 3
				spline(ox, oy, p->o_val[4], &p->o_val[5]);
E 3
I 3
				spline(ox, oy, p->o_val[4], &p->o_val[5], p->o_attr & (DOTBIT|DASHBIT), p->o_ddval);
E 3
			else {
D 2
				int i, j;
E 2
				dx = ox;
				dy = oy;
D 2
				for (i=0, j=5; i < p->o_val[4]; i++, j += 2) {
E 2
I 2
				for (k=0, j=5; k < p->o_val[4]; k++, j += 2) {
E 2
					ndx = dx + p->o_val[j];
					ndy = dy + p->o_val[j+1];
D 2
					if (p->o_dotdash == 0)
						line(dx, dy, ndx, ndy);
E 2
I 2
					if (p->o_attr & (DOTBIT|DASHBIT))
						dotline(dx, dy, ndx, ndy, p->o_attr, p->o_ddval);
E 2
					else
D 2
						dotline(dx, dy, ndx, ndy, p->o_dotdash, p->o_ddval);
E 2
I 2
						line(dx, dy, ndx, ndy);
E 2
					dx = ndx;
					dy = ndy;
				}
			}
			if (p->o_attr & HEAD2) {
D 2
				int i, j;
E 2
				dx = ox;
				dy = oy;
D 2
				for (i = 0, j = 5; i < p->o_val[4] - 1; i++, j += 2) {
E 2
I 2
				for (k = 0, j = 5; k < p->o_val[4] - 1; k++, j += 2) {
E 2
					dx += p->o_val[j];
					dy += p->o_val[j+1];
				}
D 2
				arrow(dx, dy, x1, y1, p->o_val[2], p->o_val[3]);
E 2
I 2
				arrow(dx, dy, x1, y1, p->o_val[2], p->o_val[3], 0.0, p->o_nhead);
E 2
			}
			break;
		case MOVE:
I 2
		case TEXT:
E 2
			move(ox, oy);
			dotext(p);
			break;
D 2
		case TEXT:
			move(ox, oy);
			label((char *)p->o_attr, p->o_dotdash, 0);	/* string in funny place */
			free((char *)p->o_attr);
			break;
E 2
		}
	}
}

dotline(x0, y0, x1, y1, ddtype, ddval) /* dotted line */
	float x0, y0, x1, y1;
	int ddtype;
	float ddval;
{
	static float prevval = 0.05;	/* 20 per inch by default */
	int i, numdots;
	double a, b, sqrt(), dx, dy;

	if (ddval == 0)
		ddval = prevval;
	prevval = ddval;
	/* don't save dot/dash value */
	dx = x1 - x0;
	dy = y1 - y0;
D 2
	if (ddtype == DOT) {
E 2
I 2
	if (ddtype & DOTBIT) {
E 2
		numdots = sqrt(dx*dx + dy*dy) / prevval + 0.5;
		if (numdots > 0)
			for (i = 0; i <= numdots; i++) {
				a = (float) i / (float) numdots;
				move(x0 + (a * dx), y0 + (a * dy));
				dot();
			}
D 2
	} else if (ddtype == DASH) {
E 2
I 2
	} else if (ddtype & DASHBIT) {
E 2
		double d, dashsize, spacesize;
		d = sqrt(dx*dx + dy*dy);
		if (d <= 2 * prevval) {
			line(x0, y0, x1, y1);
			return;
		}
		numdots = d / (2 * prevval) + 1;	/* ceiling */
		dashsize = prevval;
		spacesize = (d - numdots * dashsize) / (numdots - 1);
		for (i = 0; i < numdots-1; i++) {
			a = i * (dashsize + spacesize) / d;
			b = a + dashsize / d;
			line(x0 + (a*dx), y0 + (a*dy), x0 + (b*dx), y0 + (b*dy));
			a = b;
			b = a + spacesize / d;
			move(x0 + (a*dx), y0 + (a*dy));
		}
		line(x0 + (b * dx), y0 + (b * dy), x1, y1);
	}
	prevval = 0.05;
}

dotbox(x0, y0, x1, y1, ddtype, ddval)	/* dotted or dashed box */
	float x0, y0, x1, y1;
	int ddtype;
	float ddval;
{
	dotline(x0, y0, x1, y0, ddtype, ddval);
	dotline(x1, y0, x1, y1, ddtype, ddval);
	dotline(x1, y1, x0, y1, ddtype, ddval);
	dotline(x0, y1, x0, y0, ddtype, ddval);
}

dotext(p)	/* print text strings of p in proper vertical spacing */
D 2
	struct obj *p;
E 2
I 2
	obj *p;
E 2
{
	int i, nhalf;

	nhalf = p->o_nt2 - p->o_nt1 - 1;
	for (i = p->o_nt1; i < p->o_nt2; i++) {
		label(text[i].t_val, text[i].t_type, nhalf);
		nhalf -= 2;
	}
}
E 1
