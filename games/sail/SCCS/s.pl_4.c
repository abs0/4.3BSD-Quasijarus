h42447
s 00010/00005/00103
d D 5.3 88/06/18 19:55:55 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00099
d D 5.2 88/03/09 12:30:35 bostic 12 11
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00097
d D 5.1 85/05/29 16:09:17 dist 11 10
c Add copyright
e
s 00006/00000/00096
d D 2.4 85/04/23 21:51:55 edward 10 9
c copyright message
e
s 00001/00001/00095
d D 2.3 84/12/12 16:50:06 edward 9 8
c misspelling
e
s 00001/00000/00095
d D 2.2 83/11/14 12:01:40 edward 8 7
c acceptsignal bug
e
s 00000/00000/00095
d D 2.1 83/10/31 13:45:57 edward 7 6
c new version
e
s 00034/00373/00061
d D 1.6 83/10/28 19:23:31 edward 6 5
c rearranged player and screen stuff
e
s 00059/00031/00375
d D 1.5 83/10/14 22:44:25 edward 5 4
c tricky input routines
e
s 00004/00019/00402
d D 1.4 83/10/14 20:58:36 edward 4 3
c prompt fix, no more signalflags, and sgetch refresh bug.
e
s 00002/00006/00419
d D 1.3 83/10/10 20:11:26 edward 3 2
c got rid of unnecessary variables
e
s 00004/00002/00421
d D 1.2 83/10/05 11:45:49 edward 2 1
c changed sizes of things and reformated globals.c
e
s 00423/00000/00000
d D 1.1 83/07/20 18:17:44 edward 1 0
c date and time created 83/07/20 18:17:44 by edward
e
u
U
t
T
I 10
/*
D 11
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
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
E 11
 */

E 10
I 1
#ifndef lint
D 11
static	char *sccsid = "%W% %E%";
#endif
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif not lint
E 12
I 12
#endif /* not lint */
E 12
E 11

#include "player.h"

I 5
D 6
static char sc_hasprompt;
static char *sc_prompt;
static char *sc_buf;
static int sc_line;

E 6
E 5
changesail()
{
	int rig, full;

	rig = mc->rig1;
	full = mf->FS;
	if (windspeed == 6 || windspeed == 5 && mc->class > 4)
		rig = 0;
	if (mc->crew3 && rig) {
		if (!full) {
D 5
			Signal("Increase to Full sails? ", (struct ship *)0);
			if (sgetch(1) == 'y') {
E 5
I 5
			if (sgetch("Increase to Full sails? ",
				(struct ship *)0, 1) == 'y') {
E 5
				changed = 1;
				Write(W_FS, ms, 0, 1, 0, 0, 0);
			}
		} else {
D 5
			Signal("Reduce to Battle sails? ", (struct ship *)0);
			if (sgetch(1) == 'y') {
E 5
I 5
			if (sgetch("Reduce to Battle sails? ",
				(struct ship *)0, 1) == 'y') {
E 5
				Write(W_FS, ms, 0, 0, 0, 0, 0);
				changed = 1;
			}
		}
	} else if (!rig)
		Signal("Sails rent to pieces", (struct ship *)0);
}

D 4
signalflags()
{
	register struct ship *sp;

	foreachship(sp) {
		if (*sp->file->signal) {
			(void) putchar('\7');
			Signal("%s (%c%c): %s", sp, sp->file->signal);
			*sp->file->signal = '\0';
		}
	}
}

E 4
acceptsignal()
{
	char buf[60];
	register char *p = buf;

D 5
	Signal("Message? ", (struct ship *)0);
E 5
	*p++ = '"';
D 5
	sgetstr(p, sizeof buf - 2);
E 5
I 5
D 9
	sgetstr("Mesage? ", p, sizeof buf - 2);
E 9
I 9
	sgetstr("Message? ", p, sizeof buf - 2);
E 9
E 5
	while (*p++)
		;
	p[-1] = '"';
I 8
	*p = 0;
E 8
	Write(W_SIGNAL, ms, 1, (int)buf, 0, 0, 0);
}

D 6
/*VARARGS2*/
Signal(fmt, ship, a, b, c, d)
char *fmt;
register struct ship *ship;
int a, b, c, d;
E 6
I 6
lookout()
E 6
{
D 5
	Scroll();
E 5
D 6
	if (ship == 0)
		(void) wprintw(scroll_w, fmt, a, b, c, d);
	else
		(void) wprintw(scroll_w, fmt, ship->shipname, colours(ship),
			sterncolour(ship), a, b, c, d);
D 5
	(void) wrefresh(scroll_w);
E 5
I 5
	Scroll();
E 5
}

D 5
static int sline = 0;

E 5
Scroll()
{
D 5
	(void) wmove(scroll_w, sline++, 0);
E 5
I 5
	if (++sc_line >= SCROLL_Y)
		sc_line = 0;
	(void) wmove(scroll_w, sc_line, 0);
E 5
	(void) wclrtoeol(scroll_w);
D 5
	if (sline >= SCROLL_Y)
		sline = 0;
E 5
I 5
	(void) wrefresh(scroll_w);
E 5
}

D 5
/* make sure we have two consecutive lines */
Scroll2()
{
	Scroll();
	if (sline > SCROLL_Y - 2)
		Scroll();
}

E 5
lastline()
{
	(void) wmove(scroll_w, SCROLL_Y-1, 0);
	(void) wclrtoeol(scroll_w);
	(void) wrefresh(scroll_w);
}

D 5
prompt()
E 5
I 5
prompt(p, ship)
register char *p;
struct ship *ship;
E 5
{
D 5
	(void) wmove(scroll_w, sline, 0);
	(void) wclrtoeol(scroll_w);
D 4
	(void) addch('~');
E 4
I 4
	(void) waddch(scroll_w, '~');
E 4
	(void) wmove(scroll_w, sline, 0);
E 5
I 5
	static char buf[60];

	if (ship != 0)
		p = sprintf(buf, p, ship->shipname, colours(ship),
			sterncolour(ship));
	sc_prompt = p;
	sc_buf = "";
	sc_hasprompt = 1;
	(void) waddstr(scroll_w, p);
E 5
	(void) wrefresh(scroll_w);
}

D 5
sgetch(flag)
E 5
I 5
endprompt(flag)
E 5
char flag;
{
I 5
	sc_hasprompt = 0;
	if (flag)
		Scroll();
}

sgetch(p, ship, flag)
char *p;
struct ship *ship;
char flag;
{
E 5
	register c;

I 5
	prompt(p, ship);
E 5
	while ((c = wgetch(scroll_w)) == EOF)
		;
D 5
	if (flag)
E 5
I 5
	if (flag && c >= ' ' && c < 0x7f)
E 5
		(void) waddch(scroll_w, c);
I 5
	endprompt(flag);
E 5
	return c;
}

D 5
sgetstr(buf, n)
char *buf;
E 5
I 5
sgetstr(pr, buf, n)
char *pr;
register char *buf;
register n;
E 5
{
	register c;
	register char *p = buf;

I 5
	prompt(pr, (struct ship *)0);
	sc_buf = buf;
E 5
	for (;;) {
I 5
		*p = 0;
E 5
I 4
		(void) wrefresh(scroll_w);
E 4
		while ((c = wgetch(scroll_w)) == EOF)
			;
		switch (c) {
		case '\n':
		case '\r':
D 5
			*p = 0;
E 5
I 5
			endprompt(1);
E 5
			return;
		case '\b':
D 2
			if (p > buf)
E 2
I 2
			if (p > buf) {
				(void) waddstr(scroll_w, "\b \b");
E 2
				p--;
I 2
			}
E 2
			break;
		default:
D 2
			if (p < &buf[n] - 1) {
E 2
I 2
D 4
			if (p < buf + n - 1) {
E 4
I 4
			if (c >= ' ' && c < 0x7f && p < buf + n - 1) {
E 4
E 2
				*p++ = c;
				(void) waddch(scroll_w, c);
D 4
				(void) wrefresh(scroll_w);
			} else {
E 4
I 4
			} else
E 4
				(void) putchar(CTRL(g));
D 4
				(void) fflush(stdout);
			}
E 4
		}
	}
}

newturn()
{
	repaired = loaded = fired = changed = 0;
I 3
	movebuf[0] = '\0';
E 3

	(void) alarm(0);
	if (mf->readyL & R_LOADING)
		if (mf->readyL & R_DOUBLE)
			mf->readyL = R_LOADING;
		else
			mf->readyL = R_LOADED;
	if (mf->readyR & R_LOADING)
		if (mf->readyR & R_DOUBLE)
			mf->readyR = R_LOADING;
		else
			mf->readyR = R_LOADED;
I 5

	if (sc_hasprompt) {
		(void) wmove(scroll_w, sc_line, 0);
		(void) wclrtoeol(scroll_w);
	}
E 5
D 3
	movebuf[0] = '\0';
E 3
	Sync();
I 5
	if (sc_hasprompt)
		(void) wprintw(scroll_w, "%s%s", sc_prompt, sc_buf);

E 5
	if (turn % 50 == 0)		/* still playing */
D 3
		Write(W_TIME, SHIP(0), 0, 1, 0, 0, 0); /* XXX */
	windspeed = cc->windspeed;
	winddir = cc->winddir;
	turn = cc->turn;
E 3
I 3
		Write(W_ALIVE, SHIP(0), 0, 0, 0, 0, 0); /* XXX */
E 3
	if (mf->FS == 1)
		Write(W_FS, ms, 0, 2, 0, 0, 0);
D 3
	readpos();
E 3
	adjustview();

	screen();

	(void) signal(SIGALRM, newturn);
	(void) alarm(7);
}

screen()
{
	draw_view();
	draw_turn();
	draw_stat();
	draw_slot();
	(void) wrefresh(scroll_w);
}

draw_view()
{
E 6
	register struct ship *sp;
I 6
	char buf[3];
	register char c;
E 6

D 6
	(void) werase(view_w);
E 6
I 6
	sgetstr("What ship? ", buf, sizeof buf);
E 6
	foreachship(sp) {
D 6
		if (sp->file->dir
		    && sp->file->row > viewrow
		    && sp->file->row < viewrow + VIEW_Y
		    && sp->file->col > viewcol
		    && sp->file->col < viewcol + VIEW_X) {
			(void) wmove(view_w, sp->file->row - viewrow,
				sp->file->col - viewcol);
			(void) waddch(view_w, colours(sp));
			(void) wmove(view_w,
				sternrow(sp) - viewrow,
				sterncol(sp) - viewcol);
			(void) waddch(view_w, sterncolour(sp));
E 6
I 6
		c = *countryname[sp->nationality];
		if ((c == *buf || tolower(c) == *buf || colours(sp) == *buf)
		    && (sp->file->stern == buf[1] || sterncolour(sp) == buf[1]
			|| buf[1] == '?')) {
			eyeball(sp);
E 6
		}
	}
D 6
	(void) wrefresh(view_w);
E 6
}

D 6
draw_turn()
E 6
I 6
char *
saywhat(sp, flag)
register struct ship *sp;
char flag;
E 6
{
D 6
	(void) wmove(turn_w, 0, 0);
	(void) wprintw(turn_w, "Turn %d", turn);
	(void) wrefresh(turn_w);
}

draw_stat()
{
	(void) wmove(stat_w, STAT_1, 0);
	(void) wprintw(stat_w, "Points  %3d\n", mf->points);
	(void) wprintw(stat_w, "Fouls    %2d\n", fouled(ms));
	(void) wprintw(stat_w, "Grapples %2d\n", grappled(ms));

	(void) wmove(stat_w, STAT_2, 0);
	(void) wprintw(stat_w, "    0 %c(%c)\n",
		maxmove(ms, winddir + 3, -1) + '0',
		maxmove(ms, winddir + 3, 1) + '0');
	(void) waddstr(stat_w, "   \\|/\n");
	(void) wprintw(stat_w, "   -^-%c(%c)\n",
		maxmove(ms, winddir + 2, -1) + '0',
		maxmove(ms, winddir + 2, 1) + '0');
	(void) waddstr(stat_w, "   /|\\\n");
	(void) wprintw(stat_w, "    | %c(%c)\n",
		maxmove(ms, winddir + 1, -1) + '0',
		maxmove(ms, winddir + 1, 1) + '0');
	(void) wprintw(stat_w, "   %c(%c)\n",
		maxmove(ms, winddir, -1) + '0',
		maxmove(ms, winddir, 1) + '0');

	(void) wmove(stat_w, STAT_3, 0);
	(void) wprintw(stat_w, "Load  %c%c %c%c\n",
		loadname[mf->loadL], readyname(mf->readyL),
		loadname[mf->loadR], readyname(mf->readyR));
	(void) wprintw(stat_w, "Hull %2d\n", mc->hull);
	(void) wprintw(stat_w, "Crew %2d %2d %2d\n",
		mc->crew1, mc->crew2, mc->crew3);
	(void) wprintw(stat_w, "Guns %2d %2d\n", mc->gunL, mc->gunR);
	(void) wprintw(stat_w, "Carr %2d %2d\n", mc->carR, mc->carL);
	(void) wprintw(stat_w, "Rigg %d %d %d ", mc->rig1, mc->rig2, mc->rig3);
	if (mc->rig4 < 0)
		(void) waddch(stat_w, '-');
E 6
I 6
	if (sp->file->captain[0])
		return sp->file->captain;
	else if (sp->file->struck)
		return "(struck)";
	else if (sp->file->captured != 0)
		return "(captured)";
	else if (flag)
		return "(available)";
E 6
	else
D 6
		(void) wprintw(stat_w, "%d", mc->rig4);
	(void) wrefresh(stat_w);
E 6
I 6
		return "(computer)";
E 6
}

D 6
draw_slot()
E 6
I 6
eyeball(ship)
register struct ship *ship;
E 6
{
D 6
	if (!boarding(ms, 0)) {
		(void) mvwaddstr(slot_w, 0, 0, "   ");
		(void) mvwaddstr(slot_w, 1, 0, "   ");
	} else
		(void) mvwaddstr(slot_w, 1, 0, "OBP");
	if (!boarding(ms, 1)) {
		(void) mvwaddstr(slot_w, 2, 0, "   ");
		(void) mvwaddstr(slot_w, 3, 0, "   ");
	} else
		(void) mvwaddstr(slot_w, 3, 0, "DBP");
E 6
I 6
	int i;
E 6

D 6
	(void) wmove(slot_w, SLOT_Y-4, 0);
	if (mf->RH)
		(void) wprintw(slot_w, "%dRH", mf->RH);
	else
		(void) waddstr(slot_w, "   ");
	(void) wmove(slot_w, SLOT_Y-3, 0);
	if (mf->RG)
		(void) wprintw(slot_w, "%dRG", mf->RG);
	else
		(void) waddstr(slot_w, "   ");
	(void) wmove(slot_w, SLOT_Y-2, 0);
	if (mf->RR)
		(void) wprintw(slot_w, "%dRR", mf->RR);
	else
		(void) waddstr(slot_w, "   ");

#define Y	(SLOT_Y/2)
	(void) wmove(slot_w, 7, 1);
	(void) wprintw(slot_w,"%d", windspeed);
	(void) mvwaddch(slot_w, Y, 0, ' ');
	(void) mvwaddch(slot_w, Y, 2, ' ');
	(void) mvwaddch(slot_w, Y-1, 0, ' ');
	(void) mvwaddch(slot_w, Y-1, 1, ' ');
	(void) mvwaddch(slot_w, Y-1, 2, ' ');
	(void) mvwaddch(slot_w, Y+1, 0, ' ');
	(void) mvwaddch(slot_w, Y+1, 1, ' ');
	(void) mvwaddch(slot_w, Y+1, 2, ' ');
	(void) wmove(slot_w, Y - dr[winddir], 1 - dc[winddir]);
	switch (winddir) {
	case 1:
	case 5:
		(void) waddch(slot_w, '|');
		break;
	case 2:
	case 6:
		(void) waddch(slot_w, '/');
		break;
	case 3:
	case 7:
		(void) waddch(slot_w, '-');
		break;
	case 4:
	case 8:
		(void) waddch(slot_w, '\\');
		break;
E 6
I 6
	if (ship->file->dir != 0) {
		Signal("Sail ho! (range %d, %s)",
			(struct ship *)0, range(ms, ship), saywhat(ship, 0));
		i = portside(ms, ship, 1) - mf->dir;
		if (i <= 0)
			i += 8;
		Signal("%s (%c%c) %s %s %s.",
			ship, countryname[ship->nationality],
			classname[ship->specs->class], directionname[i]);
E 6
	}
D 6
	(void) mvwaddch(slot_w, Y + dr[winddir], 1 + dc[winddir], '+');
	(void) wrefresh(slot_w);
}

board()
{
	register int n;

	(void) clear();
	(void) werase(view_w);
	(void) werase(slot_w);
	(void) werase(scroll_w);
	(void) werase(stat_w);
	(void) werase(turn_w);
I 5

	sc_line = 0;
E 5

	(void) move(BOX_T, BOX_L);
	for (n = 0; n < BOX_X; n++)
		(void) addch('-');
	(void) move(BOX_B, BOX_L);
	for (n = 0; n < BOX_X; n++)
		(void) addch('-');
	for (n = BOX_T+1; n < BOX_B; n++) {
		(void) mvaddch(n, BOX_L, '|');
		(void) mvaddch(n, BOX_R, '|');
	}
	(void) mvaddch(BOX_T, BOX_L, '+');
	(void) mvaddch(BOX_T, BOX_R, '+');
	(void) mvaddch(BOX_B, BOX_L, '+');
	(void) mvaddch(BOX_B, BOX_R, '+');
	(void) refresh();

#define WSaIM "Wooden Ships & Iron Men"
	(void) wmove(view_w, 2, (VIEW_X - sizeof WSaIM - 1) / 2);
	(void) waddstr(view_w, WSaIM);
	(void) wmove(view_w, 4, (VIEW_X - strlen(cc->name)) / 2);
	(void) waddstr(view_w, cc->name);
	(void) wrefresh(view_w);

	(void) move(LINE_T, LINE_L);
	(void) printw("Class %d %s (%d guns) '%s' (%c%c)",
		mc->class,
		classname[mc->class],
		mc->guns,
		ms->shipname,
		colours(ms),
		sterncolour(ms));
	(void) refresh();
}

initscreen()
{
	(void) initscr();
	view_w = newwin(VIEW_Y, VIEW_X, VIEW_T, VIEW_L);
	slot_w = newwin(SLOT_Y, SLOT_X, SLOT_T, SLOT_L);
	scroll_w = newwin(SCROLL_Y, SCROLL_X, SCROLL_T, SCROLL_L);
	stat_w = newwin(STAT_Y, STAT_X, STAT_T, STAT_L);
	turn_w = newwin(TURN_Y, TURN_X, TURN_T, TURN_L);
	done_curses++;
	noecho();
	crmode();
}

centerview()
{
	viewrow = mf->row - VIEW_Y / 2;
	viewcol = mf->col - VIEW_X / 2;
}

upview()
{
	viewrow -= VIEW_Y / 3;
}

downview()
{
	viewrow += VIEW_Y / 3;
}

leftview()
{
	viewcol -= VIEW_X / 5;
}

rightview()
{
	viewcol += VIEW_X / 5;
}

adjustview()
{
	if (dont_adjust)
		return;			/* don't adjust if out of sight */
	if (mf->row < viewrow + VIEW_Y/4)
		viewrow = mf->row - (VIEW_Y - VIEW_Y/4);
	else if (mf->row > viewrow + (VIEW_Y - VIEW_Y/4))
		viewrow = mf->row - VIEW_Y/4;
	if (mf->col < viewcol + VIEW_X/8)
		viewcol = mf->col - (VIEW_X - VIEW_X/8);
	else if (mf->col > viewcol + (VIEW_X - VIEW_X/8))
		viewcol = mf->col - VIEW_X/8;
E 6
}
E 1
