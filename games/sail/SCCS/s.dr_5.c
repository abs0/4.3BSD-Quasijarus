h35457
s 00010/00005/00067
d D 5.3 88/06/18 19:55:23 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00063
d D 5.2 88/03/09 12:30:15 bostic 6 5
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00061
d D 5.1 85/05/29 16:01:18 dist 5 4
c Add copyright
e
s 00007/00000/00059
d D 2.2 85/04/23 21:53:47 edward 4 3
c copyright message
e
s 00000/00000/00059
d D 2.1 83/10/31 13:43:29 edward 3 2
c new version
e
s 00025/00029/00034
d D 1.2 83/07/20 17:19:30 edward 2 1
c 
e
s 00063/00000/00000
d D 1.1 83/03/17 21:09:03 leres 1 0
c date and time created 83/03/17 21:09:03 by leres
e
u
U
t
T
I 4
/*
D 5
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 5
I 5
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
E 5
 */

E 4
I 1
#ifndef lint
D 5
static	char *sccsid = "%W% %E%";
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6
E 5
I 4

E 4
#include "externs.h"

subtract(from, totalfrom, crewfrom, fromcap, pcfrom)
D 2
int from, fromcap, pcfrom;
E 2
I 2
struct ship *from, *fromcap;
int pcfrom;
E 2
register int  totalfrom, crewfrom[3];
{
	register int n;

D 2
	if (fromcap == from && totalfrom){		/* if not captured */
		for (n = 0; n < 3; n++){
			if (totalfrom > crewfrom[n]){
E 2
I 2
	if (fromcap == from && totalfrom) {		/* if not captured */
		for (n = 0; n < 3; n++) {
			if (totalfrom > crewfrom[n]) {
E 2
				totalfrom -= crewfrom[n];
				crewfrom[n] = 0;
D 2
			}
			else {
E 2
I 2
			} else {
E 2
				crewfrom[n] -= totalfrom;
				totalfrom = 0;
			}
D 2
			Write(SPECS + from, 0, 14 + 2*n, crewfrom[n]);
E 2
		}
D 2
	}
	else if (totalfrom){
E 2
I 2
		Write(W_CREW, from, 0, crewfrom[0], crewfrom[1], crewfrom[2], 0);
	} else if (totalfrom) {
E 2
		pcfrom -= totalfrom;
		pcfrom = pcfrom < 0 ? 0 : pcfrom;
D 2
		Write(FILES + from, 0, 70, pcfrom);
E 2
I 2
		Write(W_PCREW, from, 0, pcfrom, 0, 0, 0);
E 2
	}
}

D 2
mensent(from, to, crew, captured, pc, points, key)
int from, to, key, crew[3], *captured, *pc, *points;
E 2
I 2
mensent(from, to, crew, captured, pc, isdefense)
struct ship *from, *to, **captured;
int crew[3], *pc;
char isdefense;
E 2
{					/* returns # of crew squares sent */
	int men = 0;
	register int n;
	int c1, c2, c3;
D 2
	struct shipspecs *ptr;
	struct File *ptr1;
	struct BP *ptr2;
E 2
I 2
	register struct BP *bp;
E 2

D 2
	ptr = &specs[scene[game].ship[from].shipnum];
	ptr1 = scene[game].ship[from].file;	/* key:  0 OBP */
	ptr2 = key ? ptr1 -> DBP : ptr1 -> OBP;	/*       1 DBP */
	*pc = ptr1 -> pcrew;
	*captured = ptr1 -> captured;
	crew[0] = ptr -> crew1;
	crew[1] = ptr -> crew2;
	crew[2] = ptr -> crew3;
	for (n=0; n < 3; n++){
		if (ptr2[n].turnsent && ptr2[n].toship == to)
			men += ptr2[n].mensent;
E 2
I 2
	*pc = from->file->pcrew;
	*captured = from->file->captured;
	crew[0] = from->specs->crew1;
	crew[1] = from->specs->crew2;
	crew[2] = from->specs->crew3;
	bp = isdefense ? from->file->DBP : from->file->OBP;
	for (n=0; n < NBP; n++, bp++) {
		if (bp->turnsent && bp->toship == to)
			men += bp->mensent;
E 2
	}
D 2
	if (men){
E 2
I 2
	if (men) {
E 2
		c1 = men/100 ? crew[0] : 0;
		c2 = (men%100)/10 ? crew[1] : 0;
		c3 = men/10 ? crew[2] : 0;
D 2
		c3 = *captured < 0 ? crew[2] : *pc;
E 2
I 2
		c3 = *captured == 0 ? crew[2] : *pc;
E 2
	} else
		c1 = c2 = c3 = 0;
	return(c1 + c2 + c3);
}
D 2

E 2
E 1
