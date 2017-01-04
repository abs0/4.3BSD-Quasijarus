h48534
s 00010/00005/00037
d D 5.4 88/06/29 20:22:30 bostic 6 5
c install approved copyright notice
e
s 00008/00002/00034
d D 5.3 88/05/20 12:37:12 bostic 5 4
c add Berkeley specific header
e
s 00000/00004/00036
d D 5.2 88/05/20 12:11:01 edward 4 3
c use getpwuid in addition to getlogin to get user name, and some cleanup
e
s 00007/00001/00033
d D 5.1 85/06/06 09:15:10 dist 3 2
c Add copyright
e
s 00022/00021/00012
d D 1.2 84/04/11 15:15:10 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00033/00000/00000
d D 1.1 84/04/11 15:03:15 karels 1 0
c date and time created 84/04/11 15:03:15 by karels
e
u
U
t
T
I 1
D 2
/* $Header: talk.h 1.2 83/04/23 02:15:12 moore Exp $ */
E 2
I 2
D 3
/*	%W% %G%	*/
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

#include <curses.h>
#include <utmp.h>

D 2
#define	forever		for(;;)
E 2
I 2
#define forever		for(;;)
E 2

D 2
#define	BUF_SIZE	512
E 2
I 2
D 4
#define BUF_SIZE	512
E 2

D 2
FILE *popen();
int quit(), sleeper();
E 2
I 2
FILE	*popen();
E 4
int	quit();
D 4
int	sleeper();
E 4
E 2

D 2
extern int sockt;
extern int curses_initialized;
extern int invitation_waiting;
E 2
I 2
extern	int sockt;
extern	int curses_initialized;
extern	int invitation_waiting;
E 2

D 2
extern char *current_state;
extern int current_line;
E 2
I 2
extern	char *current_state;
extern	int current_line;
E 2

typedef struct xwin {
D 2
	WINDOW *x_win;
	int x_nlines;
	int x_ncols;
	int x_line;
	int x_col;
	char kill;
	char cerase;
	char werase;
E 2
I 2
	WINDOW	*x_win;
	int	x_nlines;
	int	x_ncols;
	int	x_line;
	int	x_col;
	char	kill;
	char	cerase;
	char	werase;
E 2
} xwin_t;

D 2
extern xwin_t my_win;
extern xwin_t his_win;
extern WINDOW *line_win;
E 2
I 2
extern	xwin_t my_win;
extern	xwin_t his_win;
extern	WINDOW *line_win;
E 2
E 1
