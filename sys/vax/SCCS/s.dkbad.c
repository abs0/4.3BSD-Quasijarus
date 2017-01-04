h03322
s 00001/00001/00035
d D 7.1 86/06/05 00:43:00 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00029
d D 6.3 85/06/08 13:41:32 mckusick 6 5
c Add copyright
e
s 00003/00003/00027
d D 6.2 84/08/28 18:09:30 bloom 5 4
c Change to includes.  No more ../h
e
s 00000/00000/00030
d D 6.1 83/07/29 07:19:43 sam 4 3
c 4.2 distribution
e
s 00003/00007/00027
d D 4.3 81/05/10 20:04:50 root 3 2
c NOBADBLOCK->NOBADSECT
e
s 00006/00004/00028
d D 4.2 81/05/09 19:48:17 root 2 1
c NOBADBLOCK and BADMAGIC ifndefs
e
s 00032/00000/00000
d D 4.1 81/05/08 21:56:37 wnj 1 0
c date and time created 81/05/08 21:56:37 by wnj
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6

D 2
#ifdef DKBAD
E 2
I 2
D 3
#ifndef NOBADBLOCK
E 3
I 3
#ifndef NOBADSECT
E 3
E 2
D 5
#include "../h/param.h"
#include "../h/buf.h"
#include "../h/dkbad.h"
E 5
I 5
#include "param.h"
#include "buf.h"
#include "dkbad.h"
E 5

/*
D 3
 * Search the bad block table looking for
 * the specified block.  Return index if found.
E 3
I 3
 * Search the bad sector table looking for
 * the specified sector.  Return index if found.
E 3
 * Return -1 if not found.
 */

isbad(bt, cyl, trk, sec)
	register struct dkbad *bt;
{
	register int i;
	register long blk, bblk;

I 2
D 3
#ifdef BADMAGIC
E 2
	if (bt->bt_magic != BADMAGIC)
D 2
		return(-1);
E 2
I 2
		return (-1);
#endif
E 3
E 2
	blk = ((long)cyl << 16) + (trk << 8) + sec;
	for (i = 0; i < 126; i++) {
		bblk = ((long)bt->bt_bad[i].bt_cyl << 16) + bt->bt_bad[i].bt_trksec;
		if (blk == bblk)
D 2
			return(i);
E 2
I 2
			return (i);
E 2
		if (blk < bblk || bblk < 0)
			break;
	}
D 2
	return(-1);
E 2
I 2
	return (-1);
E 2
}
#endif
E 1
