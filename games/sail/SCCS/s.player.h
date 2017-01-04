h15155
s 00010/00005/00096
d D 5.3 88/06/18 19:56:03 bostic 13 12
c install approved copyright notice
e
s 00008/00002/00093
d D 5.2 88/03/09 12:24:17 bostic 12 11
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00007/00090
d D 5.1 85/05/29 16:13:44 dist 11 10
c Add copyright
e
s 00008/00001/00089
d D 2.8 85/04/23 21:50:33 edward 10 9
c copyright message
e
s 00014/00007/00076
d D 2.7 84/02/23 15:56:40 edward 9 8
c check curses errors, and LEAVE_SYNC added
e
s 00000/00003/00083
d D 2.6 84/01/27 15:01:41 edward 8 7
c portability
e
s 00001/00001/00085
d D 2.5 83/12/17 12:38:51 edward 7 6
c new grapple and foul data structure.
e
s 00004/00001/00082
d D 2.4 83/12/09 13:28:15 edward 6 5
c turn window bigger, and block alarm when refreshing
e
s 00001/00001/00082
d D 2.3 83/11/08 15:40:25 edward 5 4
c show state of 'S' command
e
s 00001/00000/00082
d D 2.2 83/11/02 13:42:31 edward 4 3
c LEAVE_FORK added
e
s 00000/00000/00082
d D 2.1 83/10/31 13:44:35 edward 3 2
c new version
e
s 00074/00004/00008
d D 1.2 83/07/20 17:24:18 edward 2 1
c 
e
s 00012/00000/00000
d D 1.1 83/03/17 21:18:33 leres 1 0
c date and time created 83/03/17 21:18:33 by leres
e
u
U
t
T
I 1
/*
D 10
 * sccsid = "%W% %G%";
E 10
I 10
D 11
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 10
 */
I 10

/*
 * %W% %G%
E 11
I 11
 * Copyright (c) 1983 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 *
 *	%W% (Berkeley) %G%
E 11
 */

E 10
#include <curses.h>
#include "externs.h"

D 2
#define ROWSINVIEW 15
#define COLSINVIEW 75
E 2
I 2
/* sizes and coordinates for the screen */
E 2

D 2
extern WINDOW *view;
extern WINDOW *slot;
E 2
I 2
#define LINE_T		0
#define LINE_L		0
#define LINE_X		COLS
#define LINE_Y		1
#define LINE_B		(LINE_T+LINE_Y-1)
#define LINE_R		(LINE_L+LINE_X-1)
E 2

I 2
#define BOX_T		1
#define BOX_L		0
#define BOX_X		65
#define BOX_Y		16
#define BOX_B		(BOX_T+BOX_Y-1)
#define BOX_R		(BOX_L+BOX_X-1)

#define TURN_T		BOX_B
D 5
#define TURN_X		7
E 5
I 5
D 6
#define TURN_X		8
E 6
I 6
D 9
#define TURN_X		9
E 6
E 5
#define TURN_L		((BOX_L+BOX_R-TURN_X)/2)
E 9
#define TURN_Y		1
I 9
#define TURN_L		((BOX_L+BOX_R-TURN_X)/2)
#define TURN_X		9
E 9
#define TURN_B		(TURN_T+TURN_Y+1)
#define TURN_R		(TURN_L+TURN_X+1)

#define STAT_T		0
D 9
#define STAT_L		(BOX_R+2)
E 9
#define STAT_B		BOX_B
D 9
#define STAT_R		(COLS-1)
#define STAT_X		(STAT_R-STAT_L+1)
E 9
I 9
#define STAT_L		(BOX_R+2)
#define STAT_X		14
E 9
#define STAT_Y		(STAT_B-STAT_T+1)
I 9
#define STAT_R		(STAT_L+STAT_X-1)
E 9
#define STAT_1		0
#define STAT_2          (STAT_1+4)
#define STAT_3          (STAT_2+7)

#define SCROLL_T	(BOX_B+1)
#define SCROLL_L	0
#define SCROLL_B	(LINES-1)
#define SCROLL_R	(COLS-1)
D 9
#define SCROLL_X	COLS
#define SCROLL_Y	(LINES-SCROLL_T)
E 9
I 9
#define SCROLL_X	(SCROLL_R-SCROLL_L+1)
#define SCROLL_Y	(SCROLL_B-SCROLL_T+1)
E 9

#define VIEW_T		(BOX_T+1)
#define VIEW_L		(BOX_L+1)
#define VIEW_X		(BOX_X-5)
#define VIEW_Y		(BOX_Y-2)
#define VIEW_B		(VIEW_T+VIEW_Y-1)
#define VIEW_R		(VIEW_L+VIEW_X-1)

#define SLOT_T		VIEW_T
#define SLOT_L		(VIEW_R+1)
#define SLOT_X		3
#define SLOT_Y		VIEW_Y
#define SLOT_B		VIEW_B
#define SLOT_R		(SLOT_L+SLOT_X-1)

I 9
#ifdef SIGTSTP
#define SCREENTEST()	(initscr() != ERR && signal(SIGTSTP, SIG_DFL) != BADSIG && STAT_R < COLS && SCROLL_Y > 0)
#else
#define SCREENTEST()	(initscr() != ERR && STAT_R < COLS && SCROLL_Y > 0)
#endif

E 9
WINDOW *view_w;
WINDOW *slot_w;
WINDOW *scroll_w;
WINDOW *stat_w;
WINDOW *turn_w;

char done_curses;
char loaded, fired, changed, repaired;
char dont_adjust;
int viewrow, viewcol;
D 7
char movebuf[10];
E 7
I 7
char movebuf[sizeof SHIP(0)->file->movebuf];
E 7
char version[];
int player;
struct ship *ms;		/* memorial structure, &cc->ship[player] */
struct File *mf;		/* ms->file */
struct shipspecs *mc;		/* ms->specs */

/* condition codes for leave() */
#define LEAVE_QUIT	0
#define LEAVE_CAPTURED	1
#define LEAVE_HURRICAN	2
#define LEAVE_DRIVER	3
I 4
#define LEAVE_FORK	4
I 9
#define LEAVE_SYNC	5
E 9
I 6
D 8

#define blockalarm()	((void) sigblock(1 << SIGALRM-1))
#define unblockalarm()	((void) sigsetmask(sigblock(0) & ~(1 << SIGALRM-1)))
E 8
E 6
E 4
E 2
E 1
