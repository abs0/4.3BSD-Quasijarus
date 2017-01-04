h32218
s 00010/00005/00206
d D 5.3 88/06/18 19:55:38 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00202
d D 5.2 88/03/09 12:30:25 bostic 10 9
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00200
d D 5.1 85/05/29 16:06:09 dist 9 8
c Add copyright
e
s 00007/00000/00198
d D 2.4 85/04/23 21:52:12 edward 8 7
c copyright message
e
s 00003/00002/00195
d D 2.3 84/02/23 16:44:42 edward 7 6
c lint
e
s 00045/00034/00152
d D 2.2 84/02/23 16:18:26 edward 6 5
c log() added.
e
s 00000/00000/00186
d D 2.1 83/10/31 13:46:08 edward 5 4
c new version
e
s 00000/00011/00186
d D 1.4 83/10/14 23:08:32 edward 4 3
c lint
e
s 00135/00001/00062
d D 1.3 83/10/10 20:11:33 edward 3 2
c got rid of unnecessary variables
e
s 00048/00057/00015
d D 1.2 83/07/20 17:28:16 edward 2 1
c 
e
s 00072/00000/00000
d D 1.1 83/03/17 21:09:53 leres 1 0
c date and time created 83/03/17 21:09:53 by leres
e
u
U
t
T
I 8
/*
D 9
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 9
I 9
 * Copyright (c) 1983 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 11
E 10
E 9
 */

E 8
I 1
#ifndef lint
D 9
static	char *sccsid = "%W% %E%";
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 9
I 8

E 8
#include "externs.h"

#define distance(x,y) (abs(x) >= abs(y) ? abs(x) + abs(y)/2 : abs(y) + abs(x)/2)

D 2
range(fromship, toship)
register int fromship, toship;
E 2
I 2
/* XXX */
range(from, to)
struct ship *from, *to;
E 2
{
D 2
    int bow1r, bow1c, bow2r, bow2c;
    int stern1r, stern1c, stern2c, stern2r;
    register int bb, bs, sb, ss, result;
E 2
I 2
	register bow1r, bow1c, bow2r, bow2c;
	int stern1r, stern1c, stern2c, stern2r;
	register int bb, bs, sb, ss, result;
E 2

D 2
    if (fromship > scene[game].vessels
	    || toship > scene[game].vessels) /* just in case */
	return(30000);
    if (!pos[toship].dir)
	return(30000);
    stern1r = bow1r = pos[fromship].row;
    stern1c = bow1c = pos[fromship].col;
    stern2r = bow2r = pos[toship].row;
    stern2c = bow2c = pos[toship].col;
    result = bb = distance((bow2r - bow1r), (bow2c - bow1c));
    if (bb < 5)
	{
	drdc(&stern2r, &stern2c, pos[toship].dir);
	drdc(&stern1r, &stern1c, pos[fromship].dir);
	bs = distance((bow2r - stern1r) ,(bow2c - stern1c));
	sb = distance((bow1r - stern2r) ,(bow1c - stern2c));
	ss = distance((stern2r - stern1r) ,(stern2c - stern1c));
	result = min(bb, min(bs, min(sb, ss)));
E 2
I 2
	if (!to->file->dir)
D 3
		return 30000;
E 3
I 3
		return -1;
E 3
	stern1r = bow1r = from->file->row;
	stern1c = bow1c = from->file->col;
	stern2r = bow2r = to->file->row;
	stern2c = bow2c = to->file->col;
	result = bb = distance(bow2r - bow1r, bow2c - bow1c);
	if (bb < 5) {
		stern2r += dr[to->file->dir];
		stern2c += dc[to->file->dir];
		stern1r += dr[from->file->dir];
		stern1c += dc[from->file->dir];
		bs = distance((bow2r - stern1r), (bow2c - stern1c));
		sb = distance((bow1r - stern2r), (bow1c - stern2c));
		ss = distance((stern2r - stern1r) ,(stern2c - stern1c));
		result = min(bb, min(bs, min(sb, ss)));
E 2
	}
D 2
    return(result);
E 2
I 2
	return result;
E 2
}

D 2
drdc(dr, dc, dir)
register int *dr, *dc;
int dir;
E 2
I 2
struct ship *
closestenemy(from, side, anyship)
register struct ship *from;
char side, anyship;
E 2
{
D 2
    switch (dir)
	{
	case 1:
	    (*dr)++;
	    break;
	case 2:
	    (*dr)++;
	    (*dc)--;
	    break;
	case 3:
	    (*dc)--;
	    break;
	case 4:
	    (*dr)--;
	    (*dc)--;
	    break;
	case 5:
	    (*dr)--;
	    break;
	case 6:
	    (*dr)--;
	    (*dc)++;
	    break;
	case 7:
	    (*dc)++;
	    break;
	case 8:
	    (*dr)++;
	    (*dc)++;
	    break;
E 2
I 2
	register struct ship *sp;
	register char a;
	int olddist = 30000, dist;
	struct ship *closest = 0;

	a = capship(from)->nationality;
	foreachship(sp) {
		if (sp == from)
			continue;
		if (sp->file->dir == 0)
			continue;
		if (a == capship(sp)->nationality && !anyship)
			continue;
		if (side && gunsbear(from, sp) != side)
			continue;
		dist = range(from, sp);
		if (dist < olddist) {
			closest = sp;
			olddist = dist;
		}
E 2
	}
I 2
	return closest;
E 2
}
I 3

angle(dr, dc)
register dr, dc;
{
	register i;

	if (dc >= 0 && dr > 0)
		i = 0;
	else if (dr <= 0 && dc > 0)
		i = 2;
	else if (dc <= 0 && dr < 0)
		i = 4;
	else
		i = 6;
	dr = abs(dr);
	dc = abs(dc);
	if ((i == 0 || i == 4) && dc * 2.4 > dr) {
		i++;
		if (dc > dr * 2.4)
			i++;
	} else if ((i == 2 || i == 6) && dr * 2.4 > dc) {
		i++;
		if (dr > dc * 2.4)
			i++;
	}
	return i % 8 + 1;
}

gunsbear(from, to)		/* checks for target bow or stern */
register struct ship *from, *to;
{
	int Dr, Dc, i;
	register ang;

	Dr = from->file->row - to->file->row;
	Dc = to->file->col - from->file->col;
	for (i = 2; i; i--) {
		if ((ang = angle(Dr, Dc) - from->file->dir + 1) < 1)
			ang += 8;
		if (ang >= 2 && ang <= 4)
			return 'r';
		if (ang >= 6 && ang <= 7)
			return 'l';
		Dr += dr[to->file->dir];
		Dc += dc[to->file->dir];
	}
	return 0;
}

portside(from, on, quick)
register struct ship *from, *on;
int quick;			/* returns true if fromship is */
{				/* shooting at onship's starboard side */
	register ang;
	register Dr, Dc;

	Dr = from->file->row - on->file->row;
	Dc = on->file->col - from->file->col;
	if (quick == -1) {
		Dr += dr[on->file->dir];
		Dc += dc[on->file->dir];
	}
	ang = angle(Dr, Dc);
	if (quick != 0)
		return ang;
	ang = (ang + 4 - on->file->dir - 1) % 8 + 1;
	return ang < 5;
}

D 4
rmend(str)
char *str;
{
	register char *p;

	for (p = str; *p; p++)
		;
	if (p != str)
		*--p = 0;
}

E 4
colours(sp)
register struct ship *sp;
{
	register char flag;

	if (sp->file->struck)
		flag = '!';
	if (sp->file->explode)
		flag = '#';
	if (sp->file->sink)
		flag = '~';
	if (sp->file->struck)
		return flag;
	flag = *countryname[capship(sp)->nationality];
	return sp->file->FS ? flag : tolower(flag);
}

D 6
#ifdef notdef
#define PI 3.1415926535

float contable[8] =
	{ 1.5708, 0.7854, 0.0, -0.7854, -1.5708, -2.3562, -PI, 2.3562 };

int tantable[40] = {
	0,100,197,291,381,
	464,540,610,675,733,
	785,833,876,915,951,
	983,1012,1039,1064,1086,
	1107,1126,1144,1161,1176,
	1190,1204,1216,1227,1239,
	1249,1259,1268,1277,1285,
	1293,1300,1307,1313,1470
};

double
arctan(y,x)
int y,x;
E 6
I 6
#include <sys/file.h>
log(s)
register struct ship *s;
E 6
{
D 6
	int sx, sy;
	register int index;
E 6
I 6
	FILE *fp;
	int persons;
	int n;
	struct logs log[NLOG];
	float net;
	register struct logs *lp;
E 6

D 6
	sy = y < 0 ? -1 : 1;
	sx = x < 0 ? -1 : 1;
	y *= sy;
	x *= sx;
	if (!x)
		return (double) PI/2 * sy;
	index = 10 * y / x + 0.5;
	if (index > 39)
		index = 39;
	return (double)
		sy * (sx < 0 ? PI : 0 + sx*((float)tantable[index]/1000));
}
E 6
I 6
	if ((fp = fopen(LOGFILE, "r+")) == NULL)
		return;
#ifdef LOCK_EX
D 7
	flock(fileno(fp), LOCK_EX);
E 7
I 7
	if (flock(fileno(fp), LOCK_EX) < 0)
		return;
E 7
E 6
#endif
I 6
	net = (float)s->file->points / s->specs->pts;
	persons = getw(fp);
	n = fread((char *)log, sizeof(struct logs), NLOG, fp);
	for (lp = &log[n]; lp < &log[NLOG]; lp++)
		lp->l_name[0] = lp->l_uid = lp->l_shipnum
			= lp->l_gamenum = lp->l_netpoints = 0;
	rewind(fp);
	if (persons < 0)
		(void) putw(1, fp);
	else
		(void) putw(persons + 1, fp);
	for (lp = log; lp < &log[NLOG]; lp++)
		if (net > (float)lp->l_netpoints
		    / scene[lp->l_gamenum].ship[lp->l_shipnum].specs->pts) {
			(void) fwrite((char *)log,
				sizeof (struct logs), lp - log, fp);
			(void) strcpy(log[NLOG-1].l_name, s->file->captain);
			log[NLOG-1].l_uid = getuid();
			log[NLOG-1].l_shipnum = s->file->index;
			log[NLOG-1].l_gamenum = game;
			log[NLOG-1].l_netpoints = s->file->points;
			(void) fwrite((char *)&log[NLOG-1],
				sizeof (struct logs), 1, fp);
			(void) fwrite((char *)lp,
				sizeof (struct logs), &log[NLOG-1] - lp, fp);
			break;
		}
#ifdef LOCK_EX
D 7
	flock(fileno(fp), LOCK_UN);
E 7
I 7
	(void) flock(fileno(fp), LOCK_UN);
E 7
#endif
	(void) fclose(fp);
}
E 6
E 3
E 1
