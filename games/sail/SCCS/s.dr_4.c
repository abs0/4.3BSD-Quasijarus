h51599
s 00010/00005/00039
d D 5.3 88/06/18 19:55:22 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00035
d D 5.2 88/03/09 12:30:14 bostic 7 6
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00033
d D 5.1 85/05/29 16:00:54 dist 6 5
c Add copyright
e
s 00007/00000/00031
d D 2.3 85/04/23 21:47:03 edward 5 4
c copyright message
e
s 00010/00019/00021
d D 2.2 83/12/17 12:38:48 edward 4 3
c new grapple and foul data structure.
e
s 00000/00000/00040
d D 2.1 83/10/31 13:44:28 edward 3 2
c new version
e
s 00025/00031/00015
d D 1.2 83/07/20 17:23:49 edward 2 1
c 
e
s 00046/00000/00000
d D 1.1 83/03/17 21:09:31 leres 1 0
c date and time created 83/03/17 21:09:31 by leres
e
u
U
t
T
I 5
/*
D 6
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 6
I 6
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
E 6
 */

E 5
I 1
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
#endif
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 6
I 5

E 5
#include "externs.h"

D 2
ungrap(from,to)
int from, to;
E 2
I 2
ungrap(from, to)
register struct ship *from, *to;
E 2
{
D 2
	int k;
E 2
I 2
	register k;
D 4
	register struct snag *sp = from->file->grapples;
E 4
I 4
	char friend;
E 4
E 2

D 2
	if(grapple(from, to)){
		for (k = 0; k < 10; k++){
			if (scene[game].ship[from].file -> grapples[k].turnfoul && to == scene[game].ship[from].file -> grapples[k].toship && (die() < 3 || scene[game].ship[from].nationality == scene[game].ship[to].nationality)){
				cleangrapple(from, to, k);
				makesignal("ungrappling %s (%c%c)", to, from);
			}
E 2
I 2
D 4
	if (grappled2(from, to)) {
		for (k = 0; k < NSHIP; k++, sp++) {
			if (sp->turnfoul == 0 || to != sp->toship)
				continue;
			if (from->nationality == to->nationality && die() >= 3)
				continue;
			cleangrapple(from, to, k);
E 4
I 4
	if ((k = grappled2(from, to)) == 0)
		return;
	friend = capship(from)->nationality == capship(to)->nationality;
	while (--k >= 0) {
		if (friend || die() < 3) {
			cleangrapple(from, to, 0);
E 4
			makesignal(from, "ungrappling %s (%c%c)", to);
E 2
		}
	}
}

grap(from, to)
D 2
int from,to;
E 2
I 2
register struct ship *from, *to;
E 2
{
D 2
	int number, captured, l;
E 2
I 2
D 4
	register l;
E 2

D 2
	if ((captured = scene[game].ship[to].file -> captured) < 0)
		captured = to;
	number = die() < 3;
	if (!number && scene[game].ship[from].nationality == scene[game].ship[captured].nationality)
		number = 1;
	if (number){
		for (l=0; l < 10 && scene[game].ship[from].file -> grapples[l].turnfoul; l++);
		if (l < 10){
			Write(FILES + from, 0, 124 + l*4, turn);
			Write(FILES + from, 0, 124 + l*4 + 2, to);
		}
		for (l=0; l < 10 && scene[game].ship[to].file -> grapples[l].turnfoul; l++);
		if (l < 10){
			Write(FILES + to, 0, 124 + l*4, turn);
			Write(FILES + to, 0, 124 + l*4 + 2, from);
		}
		makesignal("grappled with %s (%c%c)", to, from);
	}
E 2
I 2
	if (from->nationality != capship(to)->nationality && die() >= 3)
E 4
I 4
	if (capship(from)->nationality != capship(to)->nationality && die() > 2)
E 4
		return;
D 4
	for (l = 0; l < NSHIP && from->file->grapples[l].turnfoul; l++)
		;
	if (l < NSHIP)
		Write(W_GRAP, from, 0, l, turn, to-SHIP(0), 0);
	for (l = 0; l < NSHIP && to->file->grapples[l].turnfoul; l++)
		;
	if (l < NSHIP)
		Write(W_GRAP, to, 0, l, turn, from-SHIP(0), 0);
E 4
I 4
	Write(W_GRAP, from, 0, to->file->index, 0, 0, 0);
	Write(W_GRAP, to, 0, from->file->index, 0, 0, 0);
E 4
	makesignal(from, "grappled with %s (%c%c)", to);
E 2
}
D 2


E 2
E 1
