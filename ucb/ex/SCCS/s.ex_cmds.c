h47129
s 00003/00003/00885
d D 7.13 03/04/13 15:18:46 msokolov 27 26
c 8-bit ex
e
s 00004/00004/00884
d D 7.12 88/01/02 23:12:17 bostic 26 25
c fix CTRL macro for ANSI C
e
s 00015/00016/00873
d D 7.11 87/03/09 12:47:17 conrad 25 24
c make ex/vi work on vms
e
s 00001/00001/00888
d D 7.10 85/06/07 18:18:26 bloom 24 23
c fix sccsid and copyright for xstr
e
s 00010/00002/00879
d D 7.9 85/05/31 13:51:27 dist 23 21
c Add copyright
e
s 00010/00002/00868
d D 5.3.1.1 85/05/31 11:57:16 dist 22 8
c Add copyright
e
s 00000/00001/00881
d D 7.8 85/03/19 19:04:27 mckusick 21 20
c delete unneeded sync() (from sun!shannon)
e
s 00010/00000/00872
d D 7.7 83/06/10 14:04:23 ralph 20 18
c fixed Not Edited and not Modified when errors occur.
e
s 00008/00000/00872
d R 7.7 83/06/10 12:09:05 ralph 19 18
c fixed Not Edited and not Modified when errors occur.
e
s 00000/00000/00872
d D 7.6 81/10/31 14:49:34 mark 18 17
c fixed C/70 bug with peekc being saved in a char
e
s 00000/00000/00872
d D 7.5 81/10/16 08:30:54 mark 17 16
c last minute fixes before release of 3.7
e
s 00000/00000/00872
d D 7.4 81/09/09 14:25:08 mark 16 15
c improved vt100 interface.  also uses parm termcap entries.
e
s 00001/00000/00871
d D 7.3 81/07/26 20:27:58 mark 15 14
c fixed to include ex_vis.h that defines WECHO
e
s 00000/00000/00871
d D 7.2 81/07/26 20:02:26 mark 14 13
c fixes for 3b
e
s 00000/00000/00871
d D 7.1 81/07/09 23:20:15 mark 13 12
c release 3.7
e
s 00002/00002/00869
d D 6.4 81/07/08 22:28:27 mark 12 11
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00871
d D 6.3 80/11/03 09:11:26 mark 11 10
c final 3.6 release - took out TIMEBOMB code
e
s 00001/00001/00870
d D 6.2 80/10/23 16:10:13 mark 10 9
c fixed various bugs prior to 3.6 release
e
s 00008/00007/00863
d D 6.1 80/10/19 01:20:17 mark 9 8
c preliminary release 3.6 10/18/80
e
s 00001/00001/00869
d D 5.3 80/09/12 08:32:22 mark 8 7
c separated TIOCLGET and SIGTSTP since Cory only has the former
e
s 00006/00003/00864
d D 5.2 80/08/28 20:26:21 mark 7 6
c Release 3.5, 8/28/80, previous "release" not released
c fixed rewind, deleted misfeature where arguments to :, ^^,
c ]], [[, ``, '', /, and ? reset the window size.
e
s 00000/00000/00867
d D 5.1 80/08/20 16:08:21 mark 6 5
c Release 3.5, August 20, 1980
e
s 00003/00003/00864
d D 4.2 80/08/01 20:38:52 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00073/00008/00794
d D 4.1 80/08/01 00:10:00 mark 4 3
c release 3.4, June 24, 1980
e
s 00019/00008/00783
d D 3.1 80/07/31 23:36:19 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00003/00001/00788
d D 2.1 80/07/31 23:17:44 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00789/00000/00000
d D 1.1 80/07/31 23:00:06 mark 1 0
c date and time created 80/07/31 23:00:06 by mark
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
D 12
D 22
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 22
I 22
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 22
E 12
I 12
D 23
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 23
I 23
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 24
static char sccsid[] = "%W% (Berkeley) %G%";
E 24
I 24
static char *sccsid = "%W% (Berkeley) %G%";
E 24
#endif not lint

E 23
E 12
E 5
#include "ex.h"
#include "ex_argv.h"
#include "ex_temp.h"
#include "ex_tty.h"
I 15
#include "ex_vis.h"
E 15

bool	pflag, nflag;
int	poffset;

#define	nochng()	lchng = chng

/*
 * Main loop for command mode command decoding.
 * A few commands are executed here, but main function
 * is to strip command addresses, do a little address oriented
 * processing and call command routines to do the real work.
 */
commands(noprompt, exitoneof)
	bool noprompt, exitoneof;
{
	register line *addr;
	register int c;
	register int lchng;
	int given;
	int seensemi;
	int cnt;
	bool hadpr;

	resetflav();
	nochng();
	for (;;) {
		/*
		 * If dot at last command
		 * ended up at zero, advance to one if there is a such.
		 */
		if (dot <= zero) {
			dot = zero;
			if (dol > zero)
				dot = one;
		}
		shudclob = 0;

		/*
		 * If autoprint or trailing print flags,
		 * print the line at the specified offset
		 * before the next command.
		 */
		if (pflag ||
		    lchng != chng && value(AUTOPRINT) && !inglobal && !inopen && endline) {
			pflag = 0;
			nochng();
			if (dol != zero) {
				addr1 = addr2 = dot + poffset;
				if (addr1 < one || addr1 > dol)
error("Offset out-of-bounds|Offset after command too large");
				setdot1();
				goto print;
			}
		}
		nochng();

		/*
		 * Print prompt if appropriate.
		 * If not in global flush output first to prevent
		 * going into pfast mode unreasonably.
		 */
		if (inglobal == 0) {
			flush();
			if (!hush && value(PROMPT) && !globp && !noprompt && endline) {
D 25
				putchar(':');
E 25
I 25
				ex_putchar(':');
E 25
				hadpr = 1;
			}
			TSYNC();
		}

		/*
		 * Gobble up the address.
		 * Degenerate addresses yield ".".
		 */
		addr2 = 0;
		given = seensemi = 0;
		do {
			addr1 = addr2;
D 25
			addr = address(0);
E 25
I 25
D 27
			addr = address((char *) 0);
E 27
I 27
			addr = address((u_char *) 0);
E 27
E 25
			c = getcd();
			if (addr == 0)
				if (c == ',')
					addr = dot;
				else if (addr1 != 0) {
					addr2 = dot;
					break;
				} else
					break;
			addr2 = addr;
			given++;
			if (c == ';') {
				c = ',';
				dot = addr;
				seensemi = 1;
			}
		} while (c == ',');
		if (c == '%') {
			/* %: same as 1,$ */
			addr1 = one;
			addr2 = dol;
			given = 2;
D 25
			c = getchar();
E 25
I 25
			c = ex_getchar();
E 25
		}
		if (addr1 == 0)
			addr1 = addr2;
		if (c == ':')
D 25
			c = getchar();
E 25
I 25
			c = ex_getchar();
E 25

		/*
		 * Set command name for special character commands.
		 */
		tailspec(c);

		/*
		 * If called via : escape from open or visual, limit
		 * the set of available commands here to save work below.
		 */
		if (inopen) {
D 26
			if (c=='\n' || c=='\r' || c==CTRL(d) || c==EOF) {
E 26
I 26
			if (c=='\n' || c=='\r' || c==CTRL('d') || c==EOF) {
E 26
				if (addr2)
					dot = addr2;
				if (c == EOF)
					return;
				continue;
			}
			if (any(c, "o"))
notinvis:
				tailprim(Command, 1, 1);
		}
D 25
choice:
E 25
		switch (c) {

		case 'a':

D 4
			if (peekchar() == 'r') {
E 4
I 4
			switch(peekchar()) {
			case 'b':
/* abbreviate */
				tail("abbreviate");
				setnoaddr();
				mapcmd(0, 1);
				anyabbrs = 1;
				continue;
			case 'r':
E 4
/* args */
				tail("args");
				setnoaddr();
				eol();
				pargs();
				continue;
			}

/* append */
			if (inopen)
				goto notinvis;
			tail("append");
			setdot();
			aiflag = exclam();
			newline();
I 4
			vmacchng(0);
E 4
			deletenone();
			setin(addr2);
I 4
			inappend = 1;
E 4
			ignore(append(gettty, addr2));
I 4
			inappend = 0;
E 4
			nochng();
			continue;

		case 'c':
			switch (peekchar()) {

/* copy */
			case 'o':
				tail("copy");
I 4
				vmacchng(0);
E 4
				move();
				continue;

#ifdef CHDIR
/* cd */
			case 'd':
				tail("cd");
				goto changdir;

/* chdir */
			case 'h':
				ignchar();
				if (peekchar() == 'd') {
D 27
					register char *p;
E 27
I 27
					register u_char *p;
E 27
					tail2of("chdir");
changdir:
					if (savedfile[0] == '/' || !value(WARN))
						ignore(exclam());
					else
						ignore(quickly());
					if (skipend()) {
						p = getenv("HOME");
						if (p == NULL)
							error("Home directory unknown");
					} else
						getone(), p = file;
					eol();
					if (chdir(p) < 0)
						filioerr(p);
					if (savedfile[0] != '/')
						edited = 0;
					continue;
				}
				if (inopen)
					tailprim("change", 2, 1);
				tail2of("change");
				break;

#endif
			default:
				if (inopen)
					goto notinvis;
				tail("change");
				break;
			}
/* change */
			aiflag = exclam();
			setCNL();
I 4
			vmacchng(0);
E 4
			setin(addr1);
D 25
			delete(0);
E 25
I 25
			ex_delete(0);
E 25
I 4
			inappend = 1;
E 4
			ignore(append(gettty, addr1 - 1));
I 4
			inappend = 0;
E 4
			nochng();
			continue;

/* delete */
		case 'd':
			/*
			 * Caution: dp and dl have special meaning already.
			 */
			tail("delete");
			c = cmdreg();
			setCNL();
I 4
			vmacchng(0);
E 4
			if (c)
				YANKreg(c);
D 25
			delete(0);
E 25
I 25
			ex_delete(0);
E 25
			appendnone();
			continue;

/* edit */
/* ex */
		case 'e':
			tail(peekchar() == 'x' ? "ex" : "edit");
I 4
editcmd:
E 4
			if (!exclam() && chng)
				c = 'E';
			filename(c);
			if (c == 'E') {
				ungetchar(lastchar());
				ignore(quickly());
			}
			setnoaddr();
doecmd:
			init();
			addr2 = zero;
			laste++;
D 25
			sync();
E 25
I 25
			ex_sync();
E 25
			rop(c);
I 20
#ifdef VMUNIX
			tlaste();
#endif
			laste = 0;
D 25
			sync();
E 25
I 25
			ex_sync();
E 25
E 20
			nochng();
			continue;

/* file */
		case 'f':
			tail("file");
			setnoaddr();
			filename(c);
			noonl();
I 2
/*
E 2
			synctmp();
I 2
*/
E 2
			continue;

/* global */
		case 'g':
			tail("global");
			global(!exclam());
			nochng();
			continue;

/* insert */
		case 'i':
			if (inopen)
				goto notinvis;
			tail("insert");
			setdot();
			nonzero();
			aiflag = exclam();
			newline();
I 4
			vmacchng(0);
E 4
			deletenone();
			setin(addr2);
I 4
			inappend = 1;
E 4
			ignore(append(gettty, addr2 - 1));
I 4
			inappend = 0;
E 4
			if (dot == zero && dol > zero)
				dot = one;
			nochng();
			continue;

/* join */
		case 'j':
			tail("join");
			c = exclam();
			setcount();
			nonzero();
			newline();
I 4
			vmacchng(0);
E 4
			if (given < 2 && addr2 != dol)
				addr2++;
			join(c);
			continue;

/* k */
		case 'k':
casek:
			pastwh();
D 25
			c = getchar();
E 25
I 25
			c = ex_getchar();
E 25
			if (endcmd(c))
				serror("Mark what?|%s requires following letter", Command);
			newline();
			if (!islower(c))
				error("Bad mark|Mark must specify a letter");
			setdot();
			nonzero();
			names[c - 'a'] = *addr2 &~ 01;
			anymarks = 1;
			continue;

/* list */
		case 'l':
			tail("list");
			setCNL();
			ignorf(setlist(1));
			pflag = 0;
			goto print;

		case 'm':
			if (peekchar() == 'a') {
				ignchar();
				if (peekchar() == 'p') {
/* map */
					tail2of("map");
					setnoaddr();
D 4
					mapcmd(0);
E 4
I 4
					mapcmd(0, 0);
E 4
					continue;
				}
/* mark */
				tail2of("mark");
				goto casek;
			}
/* move */
			tail("move");
I 4
			vmacchng(0);
E 4
			move();
			continue;

		case 'n':
			if (peekchar() == 'u') {
				tail("number");
				goto numberit;
			}
/* next */
			tail("next");
			setnoaddr();
			ckaw();
			ignore(quickly());
			if (getargs())
				makargs();
			next();
			c = 'e';
			filename(c);
			goto doecmd;

/* open */
		case 'o':
			tail("open");
			oop();
			pflag = 0;
			nochng();
			continue;

		case 'p':
		case 'P':
			switch (peekchar()) {

/* put */
			case 'u':
				tail("put");
				setdot();
				c = cmdreg();
				eol();
I 4
				vmacchng(0);
E 4
				if (c)
					putreg(c);
				else
					put();
				continue;

			case 'r':
				ignchar();
				if (peekchar() == 'e') {
/* preserve */
					tail2of("preserve");
					eol();
					if (preserve() == 0)
						error("Preserve failed!");
					else
						error("File preserved.");
				}
				tail2of("print");
				break;

			default:
				tail("print");
				break;
			}
/* print */
			setCNL();
			pflag = 0;
print:
			nonzero();
			if (CL && span() > LINES) {
				flush1();
				vclear();
			}
			plines(addr1, addr2, 1);
			continue;

/* quit */
		case 'q':
			tail("quit");
			setnoaddr();
			c = quickly();
			eol();
			if (!c)
quit:
				nomore();
			if (inopen) {
				vgoto(WECHO, 0);
				if (!ateopr())
					vnfl();
				else {
I 4
					tostop();
D 9
					/* replaced by tostop
E 4
					putpad(VE);
					putpad(KE);
I 4
					*/
E 9
E 4
				}
				flush();
D 25
				setty(normf);
E 25
I 25
				ignore(setty(normf));
E 25
			}
			cleanup(1);
D 25
			exit(0);
E 25
I 25
			ex_exit(0);
E 25

		case 'r':
			if (peekchar() == 'e') {
				ignchar();
				switch (peekchar()) {

/* rewind */
				case 'w':
					tail2of("rewind");
					setnoaddr();
I 7
					if (!exclam()) {
						ckaw();
						if (chng && dol > zero)
							error("No write@since last chage (:rewind! overrides)");
					}
E 7
D 4
					ignore(quickly());
E 4
					eol();
I 4
D 7
					ckaw();
					ignore(quickly());
E 7
E 4
					erewind();
					next();
					c = 'e';
					ungetchar(lastchar());
					filename(c);
					goto doecmd;

/* recover */
				case 'c':
					tail2of("recover");
					setnoaddr();
					c = 'e';
					if (!exclam() && chng)
						c = 'E';
					filename(c);
					if (c == 'E') {
						ungetchar(lastchar());
						ignore(quickly());
					}
					init();
					addr2 = zero;
					laste++;
D 25
					sync();
E 25
I 25
					ex_sync();
E 25
					recover();
					rop2();
					revocer();
					if (status == 0)
						rop3(c);
					if (dol != zero)
						change();
I 20
#ifdef VMUNIX
					tlaste();
#endif
					laste = 0;
D 21
					sync();
E 21
E 20
					nochng();
					continue;
				}
				tail2of("read");
			} else
				tail("read");
/* read */
			if (savedfile[0] == 0 && dol == zero)
				c = 'e';
			pastwh();
I 4
			vmacchng(0);
E 4
			if (peekchar() == '!') {
				setdot();
				ignchar();
				unix0(0);
				filter(0);
				continue;
			}
			filename(c);
			rop(c);
			nochng();
			if (inopen && endline && addr1 > zero && addr1 < dol)
				dot = addr1 + 1;
			continue;

		case 's':
			switch (peekchar()) {
			/*
			 * Caution: 2nd char cannot be c, g, or r
			 * because these have meaning to substitute.
			 */

/* set */
			case 'e':
				tail("set");
				setnoaddr();
				set();
				continue;

/* shell */
			case 'h':
				tail("shell");
				setNAEOL();
				vnfl();
				putpad(TE);
				flush();
D 27
				unixwt(1, unixex("-i", (char *) 0, 0, 0));
E 27
I 27
				unixwt(1, unixex("-i", (u_char *) 0, 0, 0));
E 27
				vcontin(0);
D 3
				putpad(TI);
E 3
				continue;

/* source */
			case 'o':
I 9
#ifdef notdef
E 9
				if (inopen)
					goto notinvis;
I 9
#endif
E 9
				tail("source");
				setnoaddr();
				getone();
				eol();
				source(file, 0);
				continue;
I 4
D 8
#ifdef TIOCLGET
E 8
I 8
#ifdef SIGTSTP
E 8
D 9
/* stop */
E 9
I 9
/* stop, suspend */
E 9
			case 't':
				tail("stop");
I 9
				goto suspend;
			case 'u':
				tail("suspend");
suspend:
E 9
				if (!ldisc)
					error("Old tty driver|Not using new tty driver/shell");
				c = exclam();
				eol();
				if (!c)
					ckaw();
D 9
				eol();
E 9
				onsusp();
				continue;
#endif

E 4
			}
			/* fall into ... */

/* & */
/* ~ */
/* substitute */
		case '&':
		case '~':
			Command = "substitute";
			if (c == 's')
				tail(Command);
I 4
			vmacchng(0);
E 4
			if (!substitute(c))
				pflag = 0;
			continue;

/* t */
		case 't':
			if (peekchar() == 'a') {
				tail("tag");
				tagfind(exclam());
				if (!inopen)
					lchng = chng - 1;
				else
					nochng();
				continue;
			}
			tail("t");
I 4
			vmacchng(0);
E 4
			move();
			continue;

		case 'u':
			if (peekchar() == 'n') {
D 4
/* unmap */
E 4
				ignchar();
D 4
				if (peekchar() == 'm') {
E 4
I 4
				switch(peekchar()) {
/* unmap */
				case 'm':
E 4
					tail2of("unmap");
					setnoaddr();
D 4
					mapcmd(1);
E 4
I 4
					mapcmd(1, 0);
E 4
					continue;
I 4
/* unabbreviate */
				case 'a':
					tail2of("unabbreviate");
					setnoaddr();
					mapcmd(1, 1);
					anyabbrs = 1;
					continue;
E 4
				}
/* undo */
				tail2of("undo");
			} else
				tail("undo");
			setnoaddr();
			markDOT();
			c = exclam();
			newline();
			undo(c);
			continue;

		case 'v':
			switch (peekchar()) {

			case 'e':
/* version */
				tail("version");
				setNAEOL();
D 5
				/* should use SCCS subst here */
D 2
				printf("Version 3.1, November 11, 1979");
E 2
I 2
D 3
				printf("Version 3.2, January 4, 1980");
E 3
I 3
D 4
				printf("Version 3.3, February 2, 1980");
E 4
I 4
				printf("Version 3.4, June 24, 1980");
E 5
I 5
D 7
				printf("@(#) Version 3.%R%, %G%"+5);
E 7
I 7
D 9
				printf("@(#) Version 3.%R%, %G%."+5);
E 9
I 9
D 10
				printf("@(#) Version 3.%R%, %G%. (EXPERIMENTAL version 3.6, Oct 1980)"+5);
E 10
I 10
D 25
				printf("@(#) Version 3.%R%, %G%."+5);
E 25
I 25
				ex_printf("@(#) Version 3.7, 6/7/85."+5);
E 25
E 10
E 9
E 7
E 5
E 4
E 3
E 2
				noonl();
				continue;

/* visual */
			case 'i':
				tail("visual");
I 4
				if (inopen) {
					c = 'e';
					goto editcmd;
				}
E 4
				vop();
				pflag = 0;
				nochng();
				continue;
			}
/* v */
			tail("v");
			global(0);
			nochng();
			continue;

/* write */
		case 'w':
			c = peekchar();
			tail(c == 'q' ? "wq" : "write");
I 3
wq:
E 3
			if (skipwh() && peekchar() == '!') {
I 3
				pofix();
E 3
				ignchar();
				setall();
				unix0(0);
				filter(1);
			} else {
				setall();
				wop(1);
				nochng();
			}
			if (c == 'q')
				goto quit;
			continue;

I 3
/* xit */
		case 'x':
			tail("xit");
			if (!chng)
				goto quit;
			c = 'q';
			goto wq;

E 3
/* yank */
		case 'y':
			tail("yank");
			c = cmdreg();
			setcount();
			eol();
I 4
			vmacchng(0);
E 4
			if (c)
				YANKreg(c);
			else
				yank();
			continue;

/* z */
		case 'z':
			zop(0);
			pflag = 0;
			continue;

/* * */
/* @ */
		case '*':
		case '@':
D 25
			c = getchar();
E 25
I 25
			c = ex_getchar();
E 25
			if (c=='\n' || c=='\r')
				ungetchar(c);
			if (any(c, "@*\n\r"))
				c = lastmac;
			if (isupper(c))
				c = tolower(c);
			if (!islower(c))
				error("Bad register");
			newline();
			setdot();
			cmdmac(c);
			continue;

/* | */
		case '|':
			endline = 0;
			goto caseline;

/* \n */
		case '\n':
			endline = 1;
caseline:
			notempty();
			if (addr2 == 0) {
D 3
				if (dot == dol)
					error("At EOF|At end-of-file");
E 3
				if (UP != NOSTR && c == '\n' && !inglobal)
D 26
					c = CTRL(k);
E 26
I 26
					c = CTRL('k');
E 26
				if (inglobal)
					addr1 = addr2 = dot;
D 3
				else
E 3
I 3
				else {
					if (dot == dol)
						error("At EOF|At end-of-file");
E 3
					addr1 = addr2 = dot + 1;
I 3
				}
E 3
			}
			setdot();
			nonzero();
			if (seensemi)
				addr1 = addr2;
			getline(*addr1);
D 26
			if (c == CTRL(k)) {
E 26
I 26
			if (c == CTRL('k')) {
E 26
				flush1();
				destline--;
				if (hadpr)
					shudclob = 1;
			}
			plines(addr1, addr2, 1);
			continue;

I 4
/* " */
		case '"':
			comment();
			continue;

E 4
/* # */
		case '#':
numberit:
			setCNL();
			ignorf(setnumb(1));
			pflag = 0;
			goto print;

/* = */
		case '=':
			newline();
			setall();
I 3
			if (inglobal == 2)
				pofix();
E 3
D 25
			printf("%d", lineno(addr2));
E 25
I 25
			ex_printf("%d", lineno(addr2));
E 25
			noonl();
			continue;

/* ! */
		case '!':
			if (addr2 != 0) {
I 4
				vmacchng(0);
E 4
				unix0(0);
				setdot();
				filter(2);
			} else {
				unix0(1);
D 3
				vnfl();
E 3
I 3
				pofix();
E 3
				putpad(TE);
				flush();
				unixwt(1, unixex("-c", uxb, 0, 0));
D 3
				vcontin(1);
				putpad(TI);
E 3
I 3
D 4
				vcontin(0);
E 4
I 4
				vclrech(1);	/* vcontin(0); */
E 4
E 3
				nochng();
			}
			continue;

/* < */
/* > */
		case '<':
		case '>':
			for (cnt = 1; peekchar() == c; cnt++)
				ignchar();
			setCNL();
I 4
			vmacchng(0);
E 4
			shift(c, cnt);
			continue;

/* ^D */
/* EOF */
D 26
		case CTRL(d):
E 26
I 26
		case CTRL('d'):
E 26
		case EOF:
			if (exitoneof) {
				if (addr2 != 0)
					dot = addr2;
				return;
			}
			if (!isatty(0)) {
				if (intty)
					/*
					 * Chtty sys call at UCB may cause a
					 * input which was a tty to suddenly be
					 * turned into /dev/null.
					 */
					onhup();
				return;
			}
			if (addr2 != 0) {
				setlastchar('\n');
				putnl();
			}
			if (dol == zero) {
				if (addr2 == 0)
					putnl();
				notempty();
			}
			ungetchar(EOF);
			zop(hadpr);
			continue;

		default:
			if (!isalpha(c))
				break;
			ungetchar(c);
			tailprim("", 0, 0);
		}
		error("What?|Unknown command character '%c'", c);
	}
}
E 1
