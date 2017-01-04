h55973
s 00010/00005/00061
d D 5.3 88/06/18 19:55:29 bostic 10 9
c install approved copyright notice
e
s 00009/00003/00057
d D 5.2 88/03/09 12:30:18 bostic 9 8
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00055
d D 5.1 85/05/29 16:02:17 dist 8 7
c Add copyright
e
s 00006/00000/00054
d D 2.2 85/04/23 21:48:35 edward 7 6
c copyright message
e
s 00000/00000/00054
d D 2.1 83/10/31 13:44:06 edward 6 5
c new version
e
s 00003/00003/00051
d D 1.5 83/10/10 20:10:20 edward 5 4
c got rid of unnecessary variables
e
s 00025/00025/00029
d D 1.4 83/07/20 17:22:05 edward 4 3
c 
e
s 00002/00003/00052
d D 1.3 83/05/20 17:42:38 root 3 2
c merge
e
s 00001/00001/00054
d D 1.2 83/05/19 21:06:53 leres 2 1
c "turns" can't be a register because the assembler doesn't like it
e
s 00055/00000/00000
d D 1.1 83/03/17 21:09:20 leres 1 0
c date and time created 83/03/17 21:09:20 by leres
e
u
U
t
T
I 7
/*
D 8
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
E 8
 */

E 7
I 1
#ifndef lint
D 8
static	char *sccsid = "%W% %E%";
#endif
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9
E 8
I 3

E 3
#include "externs.h"

D 3


E 3
D 4
maxturns(shipnum)
int shipnum;
E 4
I 4
D 5
maxturns(ship)
E 5
I 5
maxturns(ship, af)
E 5
register struct ship *ship;
I 5
char *af;
E 5
E 4
{
D 2
	register int turns;
E 2
I 2
D 3
	int turns;
E 3
I 3
	register int turns;
E 3
E 2
D 4
	struct File *ptr;
E 4

D 4
	turns = specs[scene[game].ship[shipnum].shipnum].ta;
	if ((ptr = scene[game].ship[shipnum].file) -> drift > 1 && turns){
E 4
I 4
	turns = ship->specs->ta;
D 5
	if (ship->file->drift > 1 && turns) {
E 5
I 5
	if (*af = (ship->file->drift > 1 && turns)) {
E 5
E 4
		turns--;
D 4
		if(ptr -> FS == 1)
E 4
I 4
		if (ship->file->FS == 1)
E 4
			turns = 0;
D 5
		turns |= 0100000;
E 5
	}
D 4
	return(turns);
E 4
I 4
	return turns;
E 4
}

D 4
maxmove(shipnum, dir, fs)
int shipnum, dir, fs;
E 4
I 4
maxmove(ship, dir, fs)
register struct ship *ship;
int dir, fs;
E 4
{
D 4
	register int riggone = 0, Move, full, flank = 0;
	struct shipspecs *ptr;
E 4
I 4
	register int riggone = 0, Move, flank = 0;
E 4

D 4
	full = scene[game].ship[shipnum].file -> FS;
	ptr = &specs[scene[game].ship[shipnum].shipnum];
	Move = ptr -> bs;
	if (!ptr -> rig1) riggone++;
	if (!ptr -> rig2) riggone++;
	if (!ptr -> rig3) riggone++;
	if (!ptr -> rig4) riggone++;
	if ((full || fs) && fs != -1){
E 4
I 4
	Move = ship->specs->bs;
	if (!ship->specs->rig1)
		riggone++;
	if (!ship->specs->rig2)
		riggone++;
	if (!ship->specs->rig3)
		riggone++;
	if (!ship->specs->rig4)
		riggone++;
	if ((ship->file->FS || fs) && fs != -1) {
E 4
		flank = 1;
D 4
		Move = ptr -> fs;
E 4
I 4
		Move = ship->specs->fs;
E 4
	}
	if (dir == winddir)
D 4
		Move -= 1 + WET[windspeed][ptr -> class-1].B;
E 4
I 4
		Move -= 1 + WET[windspeed][ship->specs->class-1].B;
E 4
	else if (dir == winddir + 2 || dir == winddir - 2 || dir == winddir - 6 || dir == winddir + 6)
D 4
		Move -= 1 + WET[windspeed][ptr -> class-1].C;
E 4
I 4
		Move -= 1 + WET[windspeed][ship->specs->class-1].C;
E 4
	else if (dir == winddir + 3 || dir == winddir - 3 || dir == winddir - 5 || dir == winddir + 5)
D 4
		Move = (flank ? 2 : 1) - WET[windspeed][ptr -> class-1].D;
E 4
I 4
		Move = (flank ? 2 : 1) - WET[windspeed][ship->specs->class-1].D;
E 4
	else if (dir == winddir + 4 || dir == winddir - 4)
		Move = 0;
	else 
D 4
		Move -= WET[windspeed][ptr -> class-1].A;
E 4
I 4
		Move -= WET[windspeed][ship->specs->class-1].A;
E 4
	Move -= riggone;
	Move = Move < 0 ? 0 : Move;
	return(Move);
}
D 4

E 4
E 1
