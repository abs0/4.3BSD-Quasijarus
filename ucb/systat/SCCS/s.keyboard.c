h11662
s 00003/00003/00088
d D 5.2 87/12/22 13:47:56 bostic 7 6
c make ANSI C compatible
e
s 00007/00001/00084
d D 5.1 85/05/30 16:22:28 mckusick 6 5
c Add copyright
e
s 00000/00001/00085
d D 1.5 85/05/01 01:33:43 sam 5 4
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00002/00002/00084
d D 1.4 85/04/28 22:25:24 sam 4 3
c isspace lets too much in allow just spaces
e
s 00001/00001/00085
d D 1.3 85/04/28 00:37:27 sam 3 2
c add vsta in; add help command (minimal); make loadav display something 
c which can be turned off
e
s 00012/00006/00074
d D 1.2 84/08/09 19:13:43 mckusick 2 1
c update to new sources from sam; weed out unnecessary #includes
e
s 00080/00000/00000
d D 1.1 83/10/02 21:41:07 sam 1 0
c date and time created 83/10/02 21:41:07 by sam
e
u
U
t
T
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% (Lucasfilm) %G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
D 6
#endif
E 6
I 6
#endif not lint
E 6

/*
 * Keyboard input support.
 */

#include "systat.h"
I 2
D 5
#include <signal.h>
E 5
#include <ctype.h>
E 2

keyboard()
{
        char ch, line[80];
I 2
	int oldmask;
E 2

        for (;;) {
                col = 0;
D 2
                move(22, 0);
E 2
I 2
                move(CMDLINE, 0);
E 2
                do {
                        refresh();
                        ch = getch() & 0177;
                        if (ch == 0177 && ferror(stdin)) {
                                clearerr(stdin);
                                continue;
                        }
                        if (ch >= 'A' && ch <= 'Z')
                                ch += 'a' - 'A';
                        if (col == 0) {
#define	mask(s)	(1 << ((s) - 1))
D 7
                                if (ch == CTRL(l)) {
E 7
I 7
                                if (ch == CTRL('l')) {
E 7
D 2
					int oldmask = sigblock(mask(SIGALRM));

E 2
I 2
					oldmask = sigblock(mask(SIGALRM));
E 2
					wrefresh(curscr);
					sigsetmask(oldmask);
                                        continue;
                                }
D 7
				if (ch == CTRL(g)) {
E 7
I 7
				if (ch == CTRL('g')) {
E 7
I 2
					oldmask = sigblock(mask(SIGALRM));
E 2
					status();
I 2
					sigsetmask(oldmask);
E 2
					continue;
				}
                                if (ch != ':')
                                        continue;
D 2
                                move(22, 0);
E 2
I 2
                                move(CMDLINE, 0);
E 2
                                clrtoeol();
                        }
                        if (ch == _tty.sg_erase && col > 0) {
                                if (col == 1 && line[0] == ':')
                                        continue;
                                col--;
                                goto doerase;
                        }
D 7
                        if (ch == CTRL(w) && col > 0) {
E 7
I 7
                        if (ch == CTRL('w') && col > 0) {
E 7
                                while (--col >= 0 && isspace(line[col]))
                                        ;
                                col++;
                                while (--col >= 0 && !isspace(line[col]))
                                        if (col == 0 && line[0] == ':')
                                                break;
                                col++;
                                goto doerase;
                        }
                        if (ch == _tty.sg_kill && col > 0) {
                                col = 0;
                                if (line[0] == ':')
                                        col++;
                doerase:
D 2
                                move(22, col);
E 2
I 2
                                move(CMDLINE, col);
E 2
                                clrtoeol();
                                continue;
                        }
D 3
                        if (isprint(ch)) {
E 3
I 3
D 4
                        if (isprint(ch) || isspace(ch)) {
E 4
I 4
                        if (isprint(ch) || ch == ' ') {
E 4
E 3
                                line[col] = ch;
D 2
                                mvaddch(22, col, ch);
E 2
I 2
                                mvaddch(CMDLINE, col, ch);
E 2
                                col++;
                        }
                } while (col == 0 || (ch != '\r' && ch != '\n'));
                line[col] = '\0';
I 2
		oldmask = sigblock(mask(SIGALRM));
E 2
                command(line + 1);
I 2
		sigsetmask(oldmask);
E 2
        }
	/*NOTREACHED*/
}
E 1
