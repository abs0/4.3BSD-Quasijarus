h32531
s 00010/00005/00050
d D 5.3 88/06/18 19:55:40 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00046
d D 5.2 88/03/09 12:30:27 bostic 7 6
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00044
d D 5.1 85/05/29 16:07:00 dist 6 5
c Add copyright
e
s 00006/00000/00043
d D 2.3 85/04/23 21:50:37 edward 5 4
c copyright message
e
s 00000/00033/00043
d D 2.2 83/12/17 12:38:55 edward 4 3
c new grapple and foul data structure.
e
s 00000/00000/00076
d D 2.1 83/10/31 13:44:41 edward 3 2
c new version
e
s 00053/00042/00023
d D 1.2 83/07/20 17:24:27 edward 2 1
c 
e
s 00065/00000/00000
d D 1.1 83/03/17 21:09:56 leres 1 0
c date and time created 83/03/17 21:09:56 by leres
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
I 2

E 2
#include "externs.h"

meleeing(from, to)
D 2
int from, to;
E 2
I 2
struct ship *from;
register struct ship *to;
E 2
{
D 2
    register int n;
E 2
I 2
	register struct BP *p = from->file->OBP;
	register struct BP *q = p + NBP;
E 2

D 2
    for (n = 0; n < 3; n++)
	{
	if (scene[game].ship[from].file -> OBP[n].turnsent && scene[game].ship[from].file -> OBP[n].toship == to)
	    return(1);
	}
    return(0);
E 2
I 2
	for (; p < q; p++)
		if (p->turnsent && p->toship == to)
			return 1;
	return 0;
E 2
}

D 2
Fouled(shipnum, offset)
int shipnum, offset;
E 2
I 2
boarding(from, isdefense)
register struct ship *from;
char isdefense;
E 2
{
D 2
    register int n, Fouls = 0;
    struct snag *ptr;
E 2
I 2
	register struct BP *p = isdefense ? from->file->DBP : from->file->OBP;
	register struct BP *q = p + NBP;
E 2

D 2
    ptr = offset == 342 ? scene[game].ship[shipnum].file -> fouls : scene[game].ship[shipnum].file -> grapples ;
    for (n=0; n < 10; n++){
	if (ptr[n].turnfoul)
	    Fouls++;
    }
    return(Fouls);
E 2
I 2
	for (; p < q; p++)
		if (p->turnsent)
			return 1;
	return 0;
E 2
}

I 2
D 4
Snagged(ship, isgrap)
struct ship *ship;
char isgrap;
{
	register int Snags = 0;
	register struct snag *sp, *sq;
E 2

D 2
Grapple(shipnum, toship, offset)
int shipnum, toship, offset;
E 2
I 2
	sp = isgrap ? ship->file->grapples : ship->file->fouls;
	sq = sp + NSHIP;
	for (; sp < sq; sp++)
		if (sp->turnfoul)
			Snags++;
	return Snags;
}

Snagged2(ship, to, isgrap, isX)
struct ship *ship, *to;
char isgrap, isX;
E 2
{
D 2
    int test = 0;
    register int n, Fouls = 0;
    struct snag *ptr;
E 2
I 2
	register Snags = 0;
	register struct snag *sp, *sq;
E 2

D 2
    if (shipnum >= 100)
	{
	shipnum -= 100;
	test = 1;
E 2
I 2
	sp = isgrap ? ship->file->grapples : ship->file->fouls;
	sq = sp + NSHIP;
	for (; sp < sq; sp++) {
		if (sp->turnfoul && sp->toship == to
		    && (!isX || sp->turnfoul < turn - 1
				&& ship->file->loadwith==L_GRAPE))
			Snags++;
E 2
	}
D 2
    ptr = offset == 342 ? scene[game].ship[shipnum].file -> fouls : scene[game].ship[shipnum].file -> grapples ;
    for (n=0; n < 10; n++)
	{
	if (ptr[n].turnfoul && ptr[n].toship == toship && (!test || (ptr[n].turnfoul < turn - 1 && (loadwith[shipnum] = GRAPE))))
	    Fouls++;
	}
    return(Fouls);
E 2
I 2
	return Snags;
E 2
}

E 4
D 2
unboard(shipnum, toship, defense)
int shipnum, toship, defense;
E 2
I 2
unboard(ship, to, isdefense)
register struct ship *ship, *to;
register char isdefense;
E 2
{
D 2
    register int n;
    struct BP *ptr;
E 2
I 2
	register struct BP *p = isdefense ? ship->file->DBP : ship->file->OBP;
	register n;
E 2

D 2
    ptr = defense ? scene[game].ship[shipnum].file -> DBP : scene[game].ship[shipnum].file -> OBP ; 
    for (n=0; n < 3; n++)
	if (ptr[n].turnsent && (ptr[n].toship == toship || defense || shipnum == toship))
	    Write(FILES + shipnum, 0, 30 + 18*defense + 6*n, 0);
E 2
I 2
	for (n = 0; n < NBP; p++, n++)
		if (p->turnsent && (p->toship == to || isdefense || ship == to))
			Write(isdefense ? W_DBP : W_OBP, ship, 0, n, 0, 0, 0);
E 2
}
E 1
