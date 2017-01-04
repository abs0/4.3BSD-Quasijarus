h23183
s 00011/00011/00550
d D 7.7 03/04/13 15:18:48 msokolov 15 14
c 8-bit ex
e
s 00001/00001/00560
d D 7.6 88/01/02 23:12:19 bostic 14 13
c fix CTRL macro for ANSI C
e
s 00018/00014/00543
d D 7.5 87/03/09 12:46:04 conrad 13 12
c make ex/vi work on vms
e
s 00001/00001/00556
d D 7.4 85/06/07 18:18:38 bloom 12 11
c fix sccsid and copyright for xstr
e
s 00010/00002/00547
d D 7.3 85/05/31 13:52:30 dist 11 9
c Add copyright
e
s 00010/00002/00550
d D 5.1.1.1 85/05/31 11:57:42 dist 10 6
c Add copyright
e
s 00000/00007/00549
d D 7.2 83/06/10 12:08:36 ralph 9 8
c fixed Not Edited and not Modified when errors occur.
e
s 00004/00004/00552
d D 7.1 81/07/08 22:28:51 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00004/00000/00552
d D 6.1 80/10/19 01:20:27 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00552
d D 5.1 80/08/20 16:08:45 mark 6 5
c Release 3.5, August 20, 1980
e
s 00005/00001/00547
d D 4.2 80/08/01 20:39:13 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00023/00007/00525
d D 4.1 80/08/01 00:10:26 mark 4 3
c release 3.4, June 24, 1980
e
s 00036/00012/00496
d D 3.1 80/07/31 23:36:33 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00508
d D 2.1 80/07/31 23:17:56 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00508/00000/00000
d D 1.1 80/07/31 23:00:08 mark 1 0
c date and time created 80/07/31 23:00:08 by mark
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 8
D 10
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 10
E 8
I 8
D 11
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
E 12
I 12
static char *sccsid = "%W% (Berkeley) %G%";
E 12
#endif not lint

E 11
E 8
E 5
#include "ex.h"
#include "ex_argv.h"
#include "ex_temp.h"
#include "ex_tty.h"
#include "ex_vis.h"

D 8
bool	pflag, nflag;
int	poffset;
E 8
I 8
extern bool	pflag, nflag;		/* mjm: extern; also in ex_cmds.c */
extern int	poffset;		/* mjm: extern; also in ex_cmds.c */
E 8

/*
 * Subroutines for major command loop.
 */

/*
 * Is there a single letter indicating a named buffer next?
 */
cmdreg()
{
	register int c = 0;
	register int wh = skipwh();

	if (wh && isalpha(peekchar()))
D 13
		c = getchar();
E 13
I 13
		c = ex_getchar();
E 13
	return (c);
}

/*
 * Tell whether the character ends a command
 */
endcmd(ch)
	int ch;
{
	switch (ch) {
	
	case '\n':
	case EOF:
		endline = 1;
		return (1);
	
	case '|':
I 4
	case '"':
E 4
		endline = 0;
		return (1);
	}
	return (0);
}

/*
 * Insist on the end of the command.
 */
eol()
{

	if (!skipend())
		error("Extra chars|Extra characters at end of command");
	ignnEOF();
}

/*
 * Print out the message in the error message file at str,
 * with i an integer argument to printf.
 */
/*VARARGS2*/
error(str, i)
D 13
#ifdef lint
	register char *str;
E 13
I 13
#ifndef EXSTRINGS
D 15
	char *str;
E 15
I 15
	u_char *str;
E 15
E 13
#else
D 13
	register int str;
E 13
I 13
# ifdef lint
D 15
	char *str;
E 15
I 15
	u_char *str;
E 15
# else
	int str;
# endif
E 13
#endif
	int i;
{

	error0();
	merror(str, i);
I 7
	if (writing) {
		serror(" [Warning - %s is incomplete]", file);
		writing = 0;
	}
E 7
	error1(str);
}

/*
 * Rewind the argument list.
 */
erewind()
{

	argc = argc0;
	argv = argv0;
	args = args0;
	if (argc > 1 && !hush) {
D 13
		printf(mesg("%d files@to edit"), argc);
E 13
I 13
		ex_printf(mesg("%d files@to edit"), argc);
E 13
		if (inopen)
D 13
			putchar(' ');
E 13
I 13
			ex_putchar(' ');
E 13
		else
			putNFL();
	}
}

/*
 * Guts of the pre-printing error processing.
 * If in visual and catching errors, then we dont mung up the internals,
 * just fixing up the echo area for the print.
 * Otherwise we reset a number of externals, and discard unused input.
 */
error0()
{

I 4
D 9
	if (laste) {
I 5
#ifdef VMUNIX
		tlaste();
#endif
E 5
		laste = 0;
		sync();
	}
E 9
E 4
	if (vcatch) {
		if (splitw == 0)
			fixech();
		if (!SO || !SE)
			dingdong();
		return;
	}
	if (input) {
		input = strend(input) - 1;
		if (*input == '\n')
			setlastchar('\n');
		input = 0;
	}
	setoutt();
	flush();
	resetflav();
D 4
	if (laste) {
		laste = 0;
		sync();
	}
E 4
	if (!SO || !SE)
		dingdong();
	if (inopen) {
		/*
		 * We are coming out of open/visual ungracefully.
		 * Restore COLUMNS, undo, and fix tty mode.
		 */
		COLUMNS = OCOLUMNS;
		undvis();
		ostop(normf);
I 4
		/* ostop should be doing this
E 4
		putpad(VE);
		putpad(KE);
I 4
		*/
E 4
		putnl();
	}
	inopen = 0;
	holdcm = 0;
}

/*
 * Post error printing processing.
 * Close the i/o file if left open.
 * If catching in visual then throw to the visual catch,
 * else if a child after a fork, then exit.
 * Otherwise, in the normal command mode error case,
 * finish state reset, and throw to top.
 */
error1(str)
D 15
	char *str;
E 15
I 15
	u_char *str;
E 15
{
	bool die;

	if (io > 0) {
		close(io);
		io = -1;
	}
	die = (getpid() != ppid);	/* Only children die */
I 3
D 4
	inglobal = 0;
E 4
I 4
	inappend = inglobal = 0;
E 4
	globp = vglobp = vmacp = 0;
E 3
	if (vcatch && !die) {
D 3
		inglobal = 0;
		vglobp = vmacp = 0;
E 3
		inopen = 1;
		vcatch = 0;
I 3
		if (str)
			noonl();
E 3
		fixol();
		longjmp(vreslab,1);
	}
	if (str && !vcatch)
		putNFL();
	if (die)
D 13
		exit(1);
E 13
I 13
		ex_exit(1);
E 13
	lseek(0, 0L, 2);
	if (inglobal)
		setlastchar('\n');
D 3
	inglobal = 0;
	globp = 0;
E 3
	while (lastchar() != '\n' && lastchar() != EOF)
		ignchar();
	ungetchar(0);
	endline = 1;
	reset();
}

fixol()
{
	if (Outchar != vputchar) {
		flush();
		if (state == ONEOPEN || state == HARDOPEN)
			outline = destline = 0;
		Outchar = vputchar;
		vcontin(1);
	} else {
		if (destcol)
			vclreol();
		vclean();
	}
}

/*
 * Does an ! character follow in the command stream?
 */
exclam()
{

	if (peekchar() == '!') {
		ignchar();
		return (1);
	}
	return (0);
}

/*
 * Make an argument list for e.g. next.
 */
makargs()
{

	glob(&frob);
	argc0 = frob.argc0;
	argv0 = frob.argv;
	args0 = argv0[0];
	erewind();
}

/*
 * Advance to next file in argument list.
 */
next()
{
I 4
	extern short isalt;	/* defined in ex_io.c */
E 4

	if (argc == 0)
		error("No more files@to edit");
	morargc = argc;
I 4
	isalt = (strcmp(altfile, args)==0) + 1;
E 4
	if (savedfile[0])
		CP(altfile, savedfile);
	CP(savedfile, args);
	argc--;
	args = argv ? *++argv : strend(args) + 1;
}

/*
 * Eat trailing flags and offsets after a command,
 * saving for possible later post-command prints.
 */
newline()
{
	register int c;

	resetflav();
	for (;;) {
D 13
		c = getchar();
E 13
I 13
		c = ex_getchar();
E 13
		switch (c) {

		case '^':
		case '-':
			poffset--;
			break;

		case '+':
			poffset++;
			break;

		case 'l':
			listf++;
			break;

		case '#':
			nflag++;
			break;

		case 'p':
			listf = 0;
			break;

		case ' ':
		case '\t':
			continue;

I 4
		case '"':
			comment();
			setflav();
			return;

E 4
		default:
			if (!endcmd(c))
serror("Extra chars|Extra characters at end of \"%s\" command", Command);
			if (c == EOF)
				ungetchar(c);
			setflav();
			return;
		}
		pflag++;
	}
}

/*
 * Before quit or respec of arg list, check that there are
 * no more files in the arg list.
 */
nomore()
{

	if (argc == 0 || morargc == argc)
		return;
	morargc = argc;
	merror("%d more file", argc);
	serror("%s@to edit", plural((long) argc));
}

/*
 * Before edit of new file check that either an ! follows
 * or the file has not been changed.
 */
quickly()
{

	if (exclam())
		return (1);
	if (chng && dol > zero) {
/*
		chng = 0;
*/
		xchng = 0;
D 13
		error("No write@since last change (:%s! overrides)", Command);
E 13
I 13
		serror("No write@since last change (:%s! overrides)", Command);
E 13
	}
	return (0);
}

/*
 * Reset the flavor of the output to print mode with no numbering.
 */
resetflav()
{

	if (inopen)
		return;
	listf = 0;
	nflag = 0;
	pflag = 0;
	poffset = 0;
	setflav();
}

/*
 * Print an error message with a %s type argument to printf.
 * Message text comes from error message file.
 */
serror(str, cp)
#ifdef lint
D 15
	register char *str;
E 15
I 15
	register u_char *str;
E 15
#else
	register int str;
#endif
D 15
	char *cp;
E 15
I 15
	u_char *cp;
E 15
{

	error0();
	smerror(str, cp);
	error1(str);
}

/*
 * Set the flavor of the output based on the flags given
 * and the number and list options to either number or not number lines
 * and either use normally decoded (ARPAnet standard) characters or list mode,
 * where end of lines are marked and tabs print as ^I.
 */
setflav()
{

	if (inopen)
		return;
D 13
	setnumb(nflag || value(NUMBER));
	setlist(listf || value(LIST));
E 13
I 13
	ignorf(setnumb(nflag || value(NUMBER)));
	ignorf(setlist(listf || value(LIST)));
E 13
	setoutt();
}

/*
 * Skip white space and tell whether command ends then.
 */
skipend()
{

	pastwh();
D 4
	return (endcmd(peekchar()));
E 4
I 4
	return (endcmd(peekchar()) && peekchar() != '"');
E 4
}

/*
 * Set the command name for non-word commands.
 */
tailspec(c)
	int c;
{
D 15
	static char foocmd[2];
E 15
I 15
	static u_char foocmd[2];
E 15

	foocmd[0] = c;
	Command = foocmd;
}

/*
 * Try to read off the rest of the command word.
 * If alphabetics follow, then this is not the command we seek.
 */
tail(comm)
D 15
	char *comm;
E 15
I 15
	u_char *comm;
E 15
{

	tailprim(comm, 1, 0);
}

tail2of(comm)
D 15
	char *comm;
E 15
I 15
	u_char *comm;
E 15
{

	tailprim(comm, 2, 0);
}

D 15
char	tcommand[20];
E 15
I 15
u_char	tcommand[20];
E 15

tailprim(comm, i, notinvis)
D 15
	register char *comm;
E 15
I 15
	register u_char *comm;
E 15
	int i;
	bool notinvis;
{
D 15
	register char *cp;
E 15
I 15
	register u_char *cp;
E 15
	register int c;

	Command = comm;
	for (cp = tcommand; i > 0; i--)
		*cp++ = *comm++;
	while (*comm && peekchar() == *comm)
D 13
		*cp++ = getchar(), comm++;
E 13
I 13
		*cp++ = ex_getchar(), comm++;
E 13
	c = peekchar();
	if (notinvis || isalpha(c)) {
		/*
		 * Of the trailing lp funny business, only dl and dp
		 * survive the move from ed to ex.
		 */
		if (tcommand[0] == 'd' && any(c, "lp"))
			goto ret;
		if (tcommand[0] == 's' && any(c, "gcr"))
			goto ret;
		while (cp < &tcommand[19] && isalpha(peekchar()))
D 13
			*cp++ = getchar();
E 13
I 13
			*cp++ = ex_getchar();
E 13
		*cp = 0;
		if (notinvis)
			serror("What?|%s: No such command from open/visual", tcommand);
		else
			serror("What?|%s: Not an editor command", tcommand);
	}
ret:
	*cp = 0;
}

/*
D 3
 * Continue after a shell escape from open/visual.
E 3
I 3
 * Continue after a : command from open/visual.
E 3
 */
vcontin(ask)
	bool ask;
{

	if (vcnt > 0)
		vcnt = -vcnt;
	if (inopen) {
		if (state != VISUAL) {
D 3
/*
			vtube[WECHO][0] = '*';
			vnfl();
*/
E 3
I 3
			/*
			 * We don't know what a shell command may have left on
			 * the screen, so we move the cursor to the right place
			 * and then put out a newline.  But this makes an extra
			 * blank line most of the time so we only do it for :sh
			 * since the prompt gets left on the screen.
			 *
			 * BUG: :!echo longer than current line \\c
			 * will screw it up, but be reasonable!
			 */
			if (state == CRTOPEN) {
				termreset();
				vgoto(WECHO, 0);
			}
			if (!ask) {
				putch('\r');
				putch('\n');
			}
E 3
			return;
		}
		if (ask) {
			merror("[Hit return to continue] ");
			flush();
		}
#ifndef CBREAK
		vraw();
#endif
		if (ask) {
I 3
#ifdef EATQS
E 3
			/*
			 * Gobble ^Q/^S since the tty driver should be eating
			 * them (as far as the user can see)
			 */
D 14
			while (peekkey() == CTRL(Q) || peekkey() == CTRL(S))
E 14
I 14
			while (peekkey() == CTRL('Q') || peekkey() == CTRL('S'))
E 14
				ignore(getkey());
D 3
			if(getkey() == ':')
E 3
I 3
#endif
			if(getkey() == ':') {
				/* Ugh. Extra newlines, but no other way */
				putch('\n');
				outline = WECHO;
E 3
				ungetkey(':');
I 3
			}
E 3
		}
D 3
		putpad(VS);
		putpad(KS);
E 3
I 3
		vclrech(1);
D 4
		if (ask && Peekkey != ':') {
E 4
I 4
D 13
		if (Peekkey != ':') {
E 13
I 13
		if (Peek_key != ':') {
E 13
E 4
			putpad(TI);
I 4
			tostart();
			/* replaced by ostart.
E 4
			putpad(VS);
			putpad(KS);
I 4
			*/
E 4
		}
E 3
	}
}

/*
 * Put out a newline (before a shell escape)
 * if in open/visual.
 */
vnfl()
{

	if (inopen) {
		if (state != VISUAL && state != CRTOPEN && destline <= WECHO)
			vclean();
		else
			vmoveitup(1, 0);
		vgoto(WECHO, 0);
		vclrbyte(vtube[WECHO], WCOLS);
I 4
		tostop();
		/* replaced by the ostop above
E 4
		putpad(VE);
		putpad(KE);
I 4
		*/
E 4
	}
	flush();
}
E 1
