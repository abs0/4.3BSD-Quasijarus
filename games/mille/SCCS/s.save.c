h09864
s 00010/00006/00146
d D 5.4 88/06/18 19:38:32 bostic 4 3
c install approved copyright notice
e
s 00014/00005/00138
d D 5.3 87/12/29 17:16:21 bostic 3 2
c Berkeley header; fix file name print; evaluation order was undefined
e
s 00001/00001/00142
d D 5.2 87/10/22 12:00:31 bostic 2 1
c ANSI C; sprintf now returns an int.
e
s 00143/00000/00000
d D 5.1 86/11/26 13:36:26 bostic 1 0
c date and time created 86/11/26 13:36:26 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3
D 4

E 4
I 3

E 3
#include	"mille.h"
#include	<sys/types.h>
#include	<sys/stat.h>
#ifndef	unctrl
#include	"unctrl.h"
#endif

# ifdef	attron
#	include	<term.h>
#	define	_tty	cur_term->Nttyb
# endif	attron

/*
 * @(#)save.c	1.2 (Berkeley) 3/28/83
 */

typedef	struct stat	STAT;

char	*ctime();

int	read(), write();

/*
 *	This routine saves the current game for use at a later date
 */
extern int	errno;
extern char	*sys_errlist[];

save() {

	reg char	*sp;
	reg int		outf;
	reg time_t	*tp;
	char		buf[80];
	time_t		tme;
	STAT		junk;

	tp = &tme;
	if (Fromfile && getyn(SAMEFILEPROMPT))
		strcpy(buf, Fromfile);
	else {
over:
		prompt(FILEPROMPT);
		leaveok(Board, FALSE);
		refresh();
		sp = buf;
		while ((*sp = readch()) != '\n') {
			if (*sp == killchar())
				goto over;
			else if (*sp == erasechar()) {
				if (--sp < buf)
					sp = buf;
				else {
					addch('\b');
					/*
					 * if the previous char was a control
					 * char, cover up two characters.
					 */
					if (*sp < ' ')
						addch('\b');
					clrtoeol();
				}
			}
D 3
			else
				addstr(unctrl(*sp++));
E 3
I 3
			else {
				addstr(unctrl(*sp));
				++sp;
			}
E 3
			refresh();
		}
		*sp = '\0';
		leaveok(Board, TRUE);
	}

	/*
	 * check for existing files, and confirm overwrite if needed
	 */

	if (sp == buf || (!Fromfile && stat(buf, &junk) > -1
	    && getyn(OVERWRITEFILEPROMPT) == FALSE))
		return FALSE;

	if ((outf = creat(buf, 0644)) < 0) {
		error(sys_errlist[errno]);
		return FALSE;
	}
	mvwaddstr(Score, ERR_Y, ERR_X, buf);
	wrefresh(Score);
	time(tp);			/* get current time		*/
	strcpy(buf, ctime(tp));
	for (sp = buf; *sp != '\n'; sp++)
		continue;
	*sp = '\0';
	varpush(outf, write);
	close(outf);
	wprintw(Score, " [%s]", buf);
	wclrtoeol(Score);
	wrefresh(Score);
	return TRUE;
}

/*
 *	This does the actual restoring.  It returns TRUE if the
 * backup was made on exiting, in which case certain things must
 * be cleaned up before the game starts.
 */
rest_f(file)
reg char	*file; {

	reg char	*sp;
	reg int		inf;
	char		buf[80];
	STAT		sbuf;

	if ((inf = open(file, 0)) < 0) {
		perror(file);
		exit(1);
	}
	if (fstat(inf, &sbuf) < 0) {		/* get file stats	*/
		perror(file);
		exit(1);
	}
	varpush(inf, read);
	close(inf);
	strcpy(buf, ctime(&sbuf.st_mtime));
	for (sp = buf; *sp != '\n'; sp++)
		continue;
	*sp = '\0';
	/*
	 * initialize some necessary values
	 */
D 2
	sprintf(Initstr, "%s [%s]\n", file, buf);
E 2
I 2
	(void)sprintf(Initstr, "%s [%s]\n", file, buf);
E 2
	Fromfile = file;
	return !On_exit;
}

E 1
