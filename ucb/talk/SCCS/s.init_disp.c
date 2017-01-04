h18993
s 00010/00005/00118
d D 5.3 88/06/29 20:22:21 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00114
d D 5.2 88/05/20 12:37:05 bostic 5 4
c add Berkeley specific header
e
s 00007/00001/00110
d D 5.1 85/06/06 09:18:08 dist 4 3
c Add copyright
e
s 00004/00000/00107
d D 1.3 85/04/24 23:37:16 edward 3 2
c block SIGALRM in curses's SIGTSTP catcher, so alarm doesn't mess up the screen
e
s 00072/00091/00035
d D 1.2 84/04/11 15:13:55 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00126/00000/00000
d D 1.1 84/04/11 15:02:54 karels 1 0
c date and time created 84/04/11 15:02:54 by karels
e
u
U
t
T
I 4
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
 */

E 4
I 1
D 2
/* $Header: init_disp.c 1.2 83/06/23 02:01:11 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 4
E 2

/*
D 2
 * init_disp contains the initialization code for the display package,
 * as well as the signal handling routines
E 2
I 2
 * Initialization code for the display package,
 * as well as the signal handling routines.
E 2
 */

#include "talk.h"
#include <signal.h>

/* 
D 2
 * set up curses, catch the appropriate signals, and build the
 * various windows
E 2
I 2
 * Set up curses, catch the appropriate signals,
 * and build the various windows.
E 2
 */
D 2

E 2
init_display()
{
D 2
    void sig_sent();
E 2
I 2
	void sig_sent();
I 3
	struct sigvec sigv;
E 3
E 2

D 2
    initscr();
    curses_initialized = 1;

    clear();
    refresh();

    noecho();
    crmode();

    signal(SIGINT, sig_sent);
    signal(SIGPIPE, sig_sent);

E 2
I 2
	initscr();
I 3
	(void) sigvec(SIGTSTP, (struct sigvec *)0, &sigv);
	sigv.sv_mask |= sigmask(SIGALRM);
	(void) sigvec(SIGTSTP, &sigv, (struct sigvec *)0);
E 3
	curses_initialized = 1;
	clear();
	refresh();
	noecho();
	crmode();
	signal(SIGINT, sig_sent);
	signal(SIGPIPE, sig_sent);
E 2
	/* curses takes care of ^Z */
I 2
	my_win.x_nlines = LINES / 2;
	my_win.x_ncols = COLS;
	my_win.x_win = newwin(my_win.x_nlines, my_win.x_ncols, 0, 0);
	scrollok(my_win.x_win, FALSE);
	wclear(my_win.x_win);
E 2

D 2
    my_win.x_nlines = LINES / 2;
    my_win.x_ncols = COLS;
    my_win.x_win = newwin(my_win.x_nlines, my_win.x_ncols, 0, 0);
    scrollok(my_win.x_win, FALSE);
    wclear(my_win.x_win);
E 2
I 2
	his_win.x_nlines = LINES / 2 - 1;
	his_win.x_ncols = COLS;
	his_win.x_win = newwin(his_win.x_nlines, his_win.x_ncols,
	    my_win.x_nlines+1, 0);
	scrollok(his_win.x_win, FALSE);
	wclear(his_win.x_win);
E 2

D 2
    his_win.x_nlines = LINES / 2 - 1;
    his_win.x_ncols = COLS;
    his_win.x_win = newwin(his_win.x_nlines, his_win.x_ncols,
					     my_win.x_nlines+1, 0);
    scrollok(his_win.x_win, FALSE);
    wclear(his_win.x_win);

    line_win = newwin(1, COLS, my_win.x_nlines, 0);
    box(line_win, '-', '-');
    wrefresh(line_win);

E 2
I 2
	line_win = newwin(1, COLS, my_win.x_nlines, 0);
	box(line_win, '-', '-');
	wrefresh(line_win);
E 2
	/* let them know we are working on it */
D 2

    current_state = "No connection yet";
E 2
I 2
	current_state = "No connection yet";
E 2
}

D 2
    /* trade edit characters with the other talk. By agreement
     * the first three characters each talk transmits after
     * connection are the three edit characters
     */

E 2
I 2
/*
 * Trade edit characters with the other talk. By agreement
 * the first three characters each talk transmits after
 * connection are the three edit characters.
 */
E 2
set_edit_chars()
{
D 2
    char buf[3];
    int cc;
    struct sgttyb tty;
    struct ltchars ltc;
    
    gtty(0, &tty);

    ioctl(0, TIOCGLTC, (struct sgttyb *) &ltc);
E 2
I 2
	char buf[3];
	int cc;
	struct sgttyb tty;
	struct ltchars ltc;
E 2
	
D 2
    my_win.cerase = tty.sg_erase;
    my_win.kill = tty.sg_kill;

    if (ltc.t_werasc == (char) -1) {
	my_win.werase = '\027';	 /* control W */
    } else {
	my_win.werase = ltc.t_werasc;
    }

    buf[0] = my_win.cerase;
    buf[1] = my_win.kill;
    buf[2] = my_win.werase;

    cc = write(sockt, buf, sizeof(buf));

    if (cc != sizeof(buf) ) {
	p_error("Lost the connection");
    }

    cc = read(sockt, buf, sizeof(buf));

    if (cc != sizeof(buf) ) {
	p_error("Lost the connection");
    }

    his_win.cerase = buf[0];
    his_win.kill = buf[1];
    his_win.werase = buf[2];
E 2
I 2
	ioctl(0, TIOCGETP, &tty);
	ioctl(0, TIOCGLTC, (struct sgttyb *)&ltc);
	my_win.cerase = tty.sg_erase;
	my_win.kill = tty.sg_kill;
	if (ltc.t_werasc == (char) -1)
		my_win.werase = '\027';	 /* control W */
	else
		my_win.werase = ltc.t_werasc;
	buf[0] = my_win.cerase;
	buf[1] = my_win.kill;
	buf[2] = my_win.werase;
	cc = write(sockt, buf, sizeof(buf));
	if (cc != sizeof(buf) )
		p_error("Lost the connection");
	cc = read(sockt, buf, sizeof(buf));
	if (cc != sizeof(buf) )
		p_error("Lost the connection");
	his_win.cerase = buf[0];
	his_win.kill = buf[1];
	his_win.werase = buf[2];
E 2
}

D 2
void sig_sent()
E 2
I 2
void
sig_sent()
E 2
{
D 2
    message("Connection closing. Exiting");
    quit();
E 2
I 2

	message("Connection closing. Exiting");
	quit();
E 2
}

/*
 * All done talking...hang up the phone and reset terminal thingy's
 */
D 2

E 2
quit()
{
I 2

E 2
	if (curses_initialized) {
D 2
	    wmove(his_win.x_win, his_win.x_nlines-1, 0);
	    wclrtoeol(his_win.x_win);
	    wrefresh(his_win.x_win);
	    endwin();
E 2
I 2
		wmove(his_win.x_win, his_win.x_nlines-1, 0);
		wclrtoeol(his_win.x_win);
		wrefresh(his_win.x_win);
		endwin();
E 2
	}
D 2

	if (invitation_waiting) {
	    send_delete();
	}

E 2
I 2
	if (invitation_waiting)
		send_delete();
E 2
	exit(0);
}
E 1
