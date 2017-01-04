h01082
s 00010/00005/01820
d D 5.19 88/06/29 19:17:48 bostic 46 45
c install approved copyright notice
e
s 00005/00002/01820
d D 5.18 88/04/25 18:26:26 bostic 45 44
c fix usage message
e
s 00004/00004/01818
d D 5.17 88/01/03 00:01:34 bostic 44 43
c fix ctrl macro for ANSI C
e
s 00002/00001/01820
d D 5.16 87/12/21 18:04:09 bostic 43 42
c semantic cleanup; balance {}'s for Pyramids
e
s 00014/00011/01807
d D 5.15 87/12/02 14:31:23 bostic 42 41
c bug report 4.3BSD/ucb/147; use varargs
e
s 00064/00056/01754
d D 5.14 87/12/02 14:28:20 bostic 41 40
c bug report ucb/147; read executable header correctly; also, remove 
c old max file size constants (they were wrong, anyway) and use new #defines 
c make lint a little happier
e
s 00009/00004/01801
d D 5.13 87/09/28 20:52:36 bostic 40 39
c line specification fix; bug report 4.3BSD/ucb/115
e
s 00004/00001/01801
d D 5.12 87/05/13 17:09:53 mckusick 39 38
c back up over magic number properly (from Keith Muller)
e
s 00002/00001/01800
d D 5.11 87/05/11 22:06:26 karels 38 37
c don't go away mad
e
s 00002/00000/01799
d D 5.10 87/05/06 12:01:17 bostic 37 36
c bug report 4.2BSD/bin/161
e
s 00001/00001/01798
d D 5.9 87/04/22 07:20:45 bostic 36 35
c should have fixed it right
e
s 00001/00001/01798
d D 5.8 87/04/06 12:07:23 bostic 35 34
c printf format/argument mismatch
e
s 00000/00000/01799
d D 5.7 86/10/21 21:28:48 mckusick 34 32
i 33
c merge 5.4.1.1
e
s 00020/00012/01772
d D 5.4.1.1 86/10/21 21:27:53 mckusick 33 30
c make magic file number checking portable (from sam)
e
s 00006/00001/01785
d D 5.6 86/07/28 10:19:04 bloom 32 31
c add support for xn from donn@utah-cs.arpa
e
s 00005/00003/01781
d D 5.5 86/07/15 01:26:40 edward 31 30
c expand tabs for the tty driver (it gets confused by escape sequences)
c fixed tab expansion algorithm
e
s 00027/00003/01757
d D 5.4 86/04/03 18:13:09 donn 30 29
c Added SIGWINCH support.
e
s 00003/00000/01757
d D 5.3 85/11/27 11:58:10 mckusick 29 28
c uninitialized variable (from ks@purdue)
e
s 00044/00002/01713
d D 5.2 85/08/29 22:09:46 bloom 28 27
c add backwards scanning
e
s 00014/00002/01701
d D 5.1 85/06/04 15:27:01 dist 27 26
c Add copyright
e
s 00004/00003/01699
d D 4.23 85/04/10 09:10:25 ralph 26 25
c fix NULL pointer problem.
e
s 00014/00003/01688
d D 4.22 85/02/21 11:22:46 bloom 25 24
c get window size via ioctl
e
s 00025/00007/01666
d D 4.21 84/12/24 18:24:49 leres 24 23
c Reorder include files now that ioctl.h needs sys/types.h.
c Simulate "crt" style erase and kill if the local mode says to.
e
s 00001/00003/01672
d D 4.20 84/09/17 11:03:16 ralph 23 22
c don't call setbuf; make termcap buffer static.
e
s 00079/00037/01596
d D 4.19 84/07/12 01:46:05 jak 22 20
c changed -d messages, fixed prompt glitch, underline glitch (tvi's), shell stdin, execute() bugs
e
s 00079/00054/01579
d R 4.19 84/07/11 18:17:25 jak 21 20
c added code for terminals with underline glitch, changed -d messages, a few minor bug fixes
e
s 00029/00015/01604
d D 4.18 84/06/07 15:17:47 leres 20 18
c Wait until we're foreground before saving the terminal modes. Use
c the fileno() macro throughout.
e
s 00049/00035/01584
d R 4.18 84/05/24 17:39:21 leres 19 18
c Wait until we're foreground before grabbing the tty modes and use the
c fileno() macro where possible.
e
s 00003/00000/01616
d D 4.17 84/01/06 10:18:39 ralph 18 16
c make ^D scroll 1/2 screenful by default.
e
s 00000/00000/01616
d R 4.17 84/01/06 10:16:34 ralph 17 16
c make ^D scroll 1/2 a screenful by default.
e
s 00003/00000/01613
d D 4.16 83/08/26 17:05:22 karels 16 15
c ignore SIGTTOU while resetting on TSTP (else can stop before reset
c if at end of pipe, not child of csh, and csh grabs tty back before ioctl)
e
s 00004/00003/01609
d D 4.15 83/07/07 03:46:44 kre 15 14
c make it use termcap again ...
c leave terminal mode on exit as we found it on entry.
e
s 00004/00005/01608
d D 4.14 83/07/02 00:32:19 sam 14 13
c no more local/uparm.h
e
s 00002/00002/01611
d D 4.13 83/07/01 02:43:38 sam 13 12
c from sun
e
s 00002/00000/01611
d D 4.12 83/06/25 02:40:16 sam 12 11
c fix SIGTSTP for new signals
e
s 00036/00020/01575
d D 4.11 83/03/17 23:02:38 layer 11 10
c asthetic mods
e
s 00001/00001/01594
d D 4.10 83/02/17 23:35:25 layer 10 9
c -c and -N switches didn't work together...
e
s 00002/00002/01593
d D 4.9 83/02/14 10:37:32 layer 9 8
c bug fix from last version 
e
s 00003/00002/01592
d D 4.8 83/02/09 15:17:59 sam 8 7
c null pointer bugs
e
s 00001/00001/01593
d D 4.7 82/12/14 16:27:56 sklower 7 6
c fix a bug about too many backspaces making more exit.
e
s 00000/00001/01594
d D 4.6 82/05/11 11:26:52 mckusick 6 5
c update to new fs
e
s 00000/00030/01595
d D 4.5 82/03/15 04:34:10 wnj 5 4
c no conditionals on machine (or anything else)
e
s 00167/00071/01458
d D 4.4 81/04/23 05:42:07 root 4 3
c added -s and -u options
e
s 00001/00001/01528
d D 4.3 81/04/02 22:15:26 wnj 3 2
c restore sccsline
e
s 00150/00028/01379
d D 4.2 81/04/02 22:11:05 root 2 1
c new version per jkf
e
s 01407/00000/00000
d D 4.1 80/10/17 02:07:44 erics 1 0
c date and time created 80/10/17 02:07:44 by erics
e
u
U
f b 
t
T
I 27
/*
 * Copyright (c) 1980 Regents of the University of California.
D 41
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 41
I 41
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 46
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 46
I 46
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
E 46
E 41
 */

E 27
I 14
#ifndef lint
E 14
I 1
D 2
static char *SCCS_ID = "%W% (Berkeley) %G%";
E 2
I 2
D 3
static char *SCCS_ID = "@(#)more.c	4.2 (Berkeley) 3/27/81";
E 3
I 3
D 27
static	char *sccsid = "%W% (Berkeley) %E%";
I 14
#endif
E 27
I 27
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 41
#endif not lint
E 41
I 41
#endif /* not lint */
E 41

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 41
#endif not lint
E 41
I 41
#endif /* not lint */
E 41
E 27
E 14
I 4

E 4
E 3
E 2
/*
** more.c - General purpose tty output filter and file perusal program
**
**	by Eric Shienbrood, UC Berkeley
I 4
**
**	modified by Geoff Peck, UCB to add underlining, single spacing
**	modified by John Foderaro, UCB to add -c and MORE environment variable
E 4
*/

D 5
#include <whoami.h>
#ifdef V6
#include <retrofit.h>
#endif
E 5
#include <stdio.h>
I 24
D 41
#include <sys/types.h>
E 41
I 41
#include <sys/param.h>
E 41
E 24
#include <ctype.h>
#include <signal.h>
#include <errno.h>
#include <sgtty.h>
#include <setjmp.h>
D 24
#include <sys/types.h>
E 24
D 6
#include <sys/dir.h>
E 6
#include <sys/stat.h>
I 33
#include <sys/file.h>
D 41
#include <sys/exec.h>
E 41
I 41
#include <a.out.h>
#include <varargs.h>
E 41
E 33
D 14
#include <local/uparm.h>
E 14

D 14
/* Help file will eventually go in libpath(more.help) on all systems */

D 5
#ifdef INGRES
#define VI		"/usr/bin/vi"
#define HELPFILE	"/mntp/doucette/more/more.help"
#endif

#ifndef INGRES
#ifndef HELPFILE
E 5
#define HELPFILE	libpath(more.help)
D 5
#endif
E 5
#define VI		binpath(vi)
E 14
I 14
#define HELPFILE	"/usr/lib/more.help"
#define VI		"/usr/ucb/vi"
E 14
D 5
#endif
E 5

#define Fopen(s,m)	(Currline = 0,file_pos=0,fopen(s,m))
#define Ftell(f)	file_pos
#define Fseek(f,off)	(file_pos=off,fseek(f,off,0))
#define Getc(f)		(++file_pos, getc(f))
#define Ungetc(c,f)	(--file_pos, ungetc(c,f))

D 5
#ifdef V6
#define MBIT	RAW
#define CBREAK	~RAW
#else
E 5
#define MBIT	CBREAK
#define stty(fd,argp)	ioctl(fd,TIOCSETN,argp)
D 5
#endif
E 5

#define TBUFSIZ	1024
#define LINSIZ	256
D 44
#define ctrl(letter)	('letter' & 077)
E 44
I 44
#define ctrl(letter)	(letter & 077)
E 44
#define RUBOUT	'\177'
#define ESC	'\033'
#define QUIT	'\034'

D 15
struct sgttyb 	otty;
E 15
I 15
D 20
struct sgttyb 	otty, savetty;
E 20
I 20
struct sgttyb	otty, savetty;
E 20
E 15
long		file_pos, file_size;
int		fnum, no_intty, no_tty, slow_tty;
D 30
int		dum_opt, dlines, onquit(), end_it();
E 30
I 30
int		dum_opt, dlines, onquit(), end_it(), chgwinsz();
E 30
D 5
#ifdef SIGTSTP
E 5
int		onsusp();
D 5
#endif
E 5
int		nscroll = 11;	/* Number of lines scrolled by 'd' */
int		fold_opt = 1;	/* Fold long lines */
int		stop_opt = 1;	/* Stop after form feeds */
I 4
int		ssp_opt = 0;	/* Suppress white space */
int		ul_opt = 1;	/* Underline as best we can */
E 4
int		promptlen;
int		Currline;	/* Line we are currently at */
int		startup = 1;
int		firstf = 1;
int		notell = 1;
I 24
int		docrterase = 0;
int		docrtkill = 0;
E 24
int		bad_so;	/* True if overwriting does not turn off standout */
int		inwait, Pause, errors;
int		within;	/* true if we are within a file,
			false if we are between files */
D 2
int		hard, dumb, noscroll, hardtabs;
E 2
I 2
D 4
int		hard, dumb, noscroll, hardtabs,clreol;
E 4
I 4
D 32
int		hard, dumb, noscroll, hardtabs, clreol;
E 32
I 32
int		hard, dumb, noscroll, hardtabs, clreol, eatnl;
E 32
E 4
E 2
int		catch_susp;	/* We should catch the SIGTSTP signal */
char		**fnames;	/* The list of file names */
int		nfiles;		/* Number of files left to process */
char		*shell;		/* The name of the shell to use */
int		shellp;		/* A previous shell command exists */
char		ch;
jmp_buf		restore;
D 23
char		obuf[BUFSIZ];	/* stdout buffer */
E 23
char		Line[LINSIZ];	/* Line buffer */
int		Lpp = 24;	/* lines per page */
char		*Clear;		/* clear screen */
char		*eraseln;	/* erase line */
char		*Senter, *Sexit;/* enter and exit standout mode */
I 4
char		*ULenter, *ULexit;	/* enter and exit underline mode */
char		*chUL;		/* underline character */
char		*chBS;		/* backspace character */
E 4
I 2
char		*Home;		/* go to home */
char		*cursorm;	/* cursor movement */
char		cursorhome[40];	/* contains cursor movement to home */
D 4
char		*Cleareod;	/* clear rest of screen */
E 4
I 4
char		*EodClr;	/* clear rest of screen */
E 4
E 2
char		*tgetstr();
int		Mcol = 80;	/* number of columns */
int		Wrap = 1;	/* set if automargins */
I 22
int		soglitch;	/* terminal has standout mode glitch */
int		ulglitch;	/* terminal has underline mode glitch */
int		pstate = 0;	/* current UL state */
E 22
long		fseek();
I 2
char		*getenv();
E 2
struct {
    long chrctr, line;
} context, screen_start;
extern char	PC;		/* pad character */
extern short	ospeed;


main(argc, argv)
int argc;
char *argv[];
{
    register FILE	*f;
    register char	*s;
    register char	*p;
    register char	ch;
    register int	left;
D 20
    int			prnames = 0; 
E 20
I 20
    int			prnames = 0;
E 20
    int			initopt = 0;
    int			srchopt = 0;
    int			clearit = 0;
    int			initline;
    char		initbuf[80];
    FILE		*checkf();

    nfiles = argc;
    fnames = argv;
    initterm ();
I 18
    nscroll = Lpp/2 - 1;
    if (nscroll <= 0)
	nscroll = 1;
E 18
I 2
    if(s = getenv("MORE")) argscan(s);
E 2
    while (--nfiles > 0) {
	if ((ch = (*++fnames)[0]) == '-') {
D 2
	    for (s = fnames[0] + 1, dlines = 0; *s != '\0'; s++)
		if (isdigit(*s))
		    dlines = dlines*10 + *s - '0';
		else if (*s == 'd')
		    dum_opt = 1;
		else if (*s == 'l')
		    stop_opt = 0;
		else if (*s == 'f')
		    fold_opt = 0;
E 2
I 2
	    argscan(*fnames+1);
E 2
	}
	else if (ch == '+') {
	    s = *fnames;
	    if (*++s == '/') {
		srchopt++;
		for (++s, p = initbuf; p < initbuf + 79 && *s != '\0';)
		    *p++ = *s++;
		*p = '\0';
	    }
	    else {
		initopt++;
		for (initline = 0; *s != '\0'; s++)
		    if (isdigit (*s))
			initline = initline*10 + *s -'0';
		--initline;
	    }
	}
	else break;
    }
I 2
D 4
    /* allow clreol only if Home and eraseln and Cleareod strings are
E 4
I 4
    /* allow clreol only if Home and eraseln and EodClr strings are
E 4
     *  defined, and in that case, make sure we are in noscroll mode
     */
    if(clreol)
    {
D 4
	if((*Home == '\0') || (*eraseln == '\0') || (*Cleareod == '\0'))
	   clreol = 0;
E 4
I 4
D 26
	if ((*Home == '\0') || (*eraseln == '\0') || (*EodClr == '\0'))
	    clreol = 0;
E 26
I 26
        if((Home == NULL) || (*Home == '\0') ||
	   (eraseln == NULL) || (*eraseln == '\0') ||
           (EodClr == NULL) || (*EodClr == '\0') )
	      clreol = 0;
E 26
E 4
	else noscroll = 1;
    }
D 26

E 26
E 2
    if (dlines == 0)
	dlines = Lpp - (noscroll ? 1 : 2);
    left = dlines;
    if (nfiles > 1)
	prnames++;
    if (!no_intty && nfiles == 0) {
D 45
	fputs("Usage: ",stderr);
	fputs(argv[0],stderr);
E 45
I 45
	char *rindex();

	p = rindex(argv[0], '/');
	fputs("usage: ",stderr);
	fputs(p ? p + 1 : argv[0],stderr);
E 45
	fputs(" [-dfln] [+linenum | +/pattern] name1 name2 ...\n",stderr);
	exit(1);
    }
    else
	f = stdin;
    if (!no_tty) {
	signal(SIGQUIT, onquit);
	signal(SIGINT, end_it);
I 30
	signal(SIGWINCH, chgwinsz);
E 30
D 5
#ifdef SIGTSTP
E 5
	if (signal (SIGTSTP, SIG_IGN) == SIG_DFL) {
	    signal(SIGTSTP, onsusp);
	    catch_susp++;
	}
D 5
#endif
E 5
D 20
	stty (2, &otty);
E 20
I 20
	stty (fileno(stderr), &otty);
E 20
    }
    if (no_intty) {
	if (no_tty)
	    copy_file (stdin);
	else {
	    if ((ch = Getc (f)) == '\f')
D 4
		doclear ();
E 4
I 4
		doclear();
E 4
	    else {
		Ungetc (ch, f);
D 2
		if (noscroll)
		    doclear ();
E 2
I 2
D 4
		if (noscroll && (ch != EOF))
		{ if(clreol) home();
		  else doclear ();
E 4
I 4
		if (noscroll && (ch != EOF)) {
		    if (clreol)
			home ();
		    else
			doclear ();
E 4
		}
E 2
	    }
	    if (srchopt)
I 2
	    {
E 2
		search (initbuf, stdin, 1);
I 2
D 4
		if(noscroll) left--;
E 4
I 4
		if (noscroll)
		    left--;
E 4
	    }
E 2
	    else if (initopt)
		skiplns (initline, stdin);
	    screen (stdin, left);
	}
	no_intty = 0;
	prnames++;
	firstf = 0;
    }

    while (fnum < nfiles) {
	if ((f = checkf (fnames[fnum], &clearit)) != NULL) {
	    context.line = context.chrctr = 0;
	    Currline = 0;
	    if (firstf) setjmp (restore);
	    if (firstf) {
		firstf = 0;
		if (srchopt)
I 2
		{
E 2
		    search (initbuf, f, 1);
I 2
D 4
		    if(noscroll) left--;
E 4
I 4
		    if (noscroll)
			left--;
E 4
		}
E 2
		else if (initopt)
		    skiplns (initline, f);
	    }
	    else if (fnum < nfiles && !no_tty) {
		setjmp (restore);
		left = command (fnames[fnum], f);
	    }
	    if (left != 0) {
D 2
		if (noscroll || clearit)
		    doclear ();
E 2
I 2
D 4
		if((noscroll  || clearit) && (file_size != 0x7fffffffffffffffL))
		    if(clreol) home();
		    else doclear ();
E 4
I 4
D 41
		if ((noscroll || clearit) && (file_size != 0x7fffffffffffffffL))
E 41
I 41
		if ((noscroll || clearit) && (file_size != LONG_MAX))
E 41
		    if (clreol)
			home ();
		    else
			doclear ();
E 4
E 2
		if (prnames) {
		    if (bad_so)
			erase (0);
I 2
D 4
		    if(clreol)cleareol();
E 4
I 4
		    if (clreol)
			cleareol ();
E 4
E 2
		    pr("::::::::::::::");
		    if (promptlen > 14)
			erase (14);
D 2
		    printf ("\n%s\n::::::::::::::\n", fnames[fnum]);
E 2
I 2
		    printf ("\n");
		    if(clreol) cleareol();
		    printf("%s\n", fnames[fnum]);
		    if(clreol) cleareol();
D 35
		    printf("::::::::::::::\n", fnames[fnum]);
E 35
I 35
D 36
		    printf("::::::::::::::\n",);
E 36
I 36
		    printf("::::::::::::::\n");
E 36
E 35
E 2
		    if (left > Lpp - 4)
			left = Lpp - 4;
		}
		if (no_tty)
		    copy_file (f);
		else {
		    within++;
		    screen(f, left);
		    within = 0;
		}
	    }
	    setjmp (restore);
	    fflush(stdout);
	    fclose(f);
	    screen_start.line = screen_start.chrctr = 0L;
	    context.line = context.chrctr = 0L;
	}
	fnum++;
	firstf = 0;
    }
    reset_tty ();
    exit(0);
}

I 2
argscan(s)
char *s;
{
D 11
	    for (dlines = 0; *s != '\0'; s++)
		if (isdigit(*s))
		    dlines = dlines*10 + *s - '0';
		else if (*s == 'd')
		    dum_opt = 1;
		else if (*s == 'l')
		    stop_opt = 0;
		else if (*s == 'f')
		    fold_opt = 0;
		else if (*s == 'p')
		    noscroll++;
		else if (*s == 'c')
		    clreol++;
I 4
		else if (*s == 's')
		    ssp_opt = 1;
		else if (*s == 'u')
		    ul_opt = 0;
E 11
I 11
D 40
	for (dlines = 0; *s != '\0'; s++)
	{
		switch (*s)
		{
E 40
I 40
	int seen_num = 0;

	while (*s != '\0') {
		switch (*s) {
E 40
		  case '0': case '1': case '2':
		  case '3': case '4': case '5':
		  case '6': case '7': case '8':
		  case '9':
I 40
			if (!seen_num) {
				dlines = 0;
				seen_num = 1;
			}
E 40
			dlines = dlines*10 + *s - '0';
			break;
		  case 'd':
			dum_opt = 1;
			break;
		  case 'l':
			stop_opt = 0;
			break;
		  case 'f':
			fold_opt = 0;
			break;
		  case 'p':
			noscroll++;
			break;
		  case 'c':
			clreol++;
			break;
		  case 's':
			ssp_opt = 1;
			break;
		  case 'u':
			ul_opt = 0;
			break;
		}
I 40
		s++;
E 40
	}
E 11
E 4
}


E 2
/*
I 2
D 4

E 4
E 2
** Check whether the file named by fs is an ASCII file which the user may
** access.  If it is, return the opened file. Otherwise return NULL.
*/

FILE *
checkf (fs, clearfirst)
D 41
register char *fs;
int *clearfirst;
E 41
I 41
	register char *fs;
	int *clearfirst;
E 41
{
D 41
    struct stat stbuf;
    register FILE *f;
    char c;
E 41
I 41
	struct stat stbuf;
	register FILE *f;
	char c;
E 41

D 41
    if (stat (fs, &stbuf) == -1) {
	fflush(stdout);
I 2
D 4
	if(clreol)cleareol();
E 4
I 4
	if (clreol)
	    cleareol ();
E 4
E 2
	perror(fs);
	return (NULL);
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
	printf("\n*** %s: directory ***\n\n", fs);
	return (NULL);
    }
    if ((f=Fopen(fs, "r")) == NULL) {
	fflush(stdout);
	perror(fs);
	return (NULL);
    }
D 33
    c = Getc(f);

E 33
    /* Try to see whether it is an ASCII file */
D 33

    switch ((c | *f->_ptr << 8) & 0177777) {
    case 0405:
    case 0407:
    case 0410:
    case 0411:
    case 0413:
    case 0177545:
E 33
I 33
    if (magic(f)) {
E 33
	printf("\n******** %s: Not a text file ********\n\n", fs);
	fclose (f);
	return (NULL);
D 33
    default:
	break;
E 33
    }
I 33
    c = Getc(f);
E 33
    if (c == '\f')
	*clearfirst = 1;
    else {
	*clearfirst = 0;
E 41
I 41
	if (stat (fs, &stbuf) == -1) {
		(void)fflush(stdout);
		if (clreol)
			cleareol ();
		perror(fs);
		return((FILE *)NULL);
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
		printf("\n*** %s: directory ***\n\n", fs);
		return((FILE *)NULL);
	}
	if ((f = Fopen(fs, "r")) == NULL) {
		(void)fflush(stdout);
		perror(fs);
		return((FILE *)NULL);
	}
	if (magic(f, fs))
		return((FILE *)NULL);
	c = Getc(f);
	*clearfirst = c == '\f';
E 41
	Ungetc (c, f);
D 41
    }
    if ((file_size = stbuf.st_size) == 0)
	file_size = 0x7fffffffffffffffL;
    return (f);
E 41
I 41
	if ((file_size = stbuf.st_size) == 0)
		file_size = LONG_MAX;
	return(f);
E 41
I 33
}

/*
D 41
 * Check for file magic numbers. This code would best
 * be shared with the file(1) program or, perhaps, more
 * should not try and be so smart?
E 41
I 41
 * magic --
 *	check for file magic numbers.  This code would best be shared with
 *	the file(1) program or, perhaps, more should not try and be so smart?
E 41
 */
D 41
magic(f)
    FILE *f;
E 41
I 41
static
magic(f, fs)
	FILE *f;
	char *fs;
E 41
{
D 41
    long magic;
E 41
I 41
	struct exec ex;
E 41

D 41
    magic = getw(f);
D 39
    fseek(f, -sizeof (magic), L_INCR);		/* reset file position */
E 39
I 39
    if (ftell(f) < sizeof magic)
    	rewind(f);				/* reset file position */
    else
    	fseek(f, -sizeof (magic), L_INCR);	/* reset file position */
E 39
    return (magic == 0405 || magic == OMAGIC || magic == NMAGIC ||
	magic == 0411 || magic == ZMAGIC || magic == 0177545);
E 41
I 41
	if (fread(&ex, sizeof(ex), 1, f) == 1)
		switch(ex.a_magic) {
		case OMAGIC:
		case NMAGIC:
		case ZMAGIC:
		case 0405:
		case 0411:
		case 0177545:
			printf("\n******** %s: Not a text file ********\n\n", fs);
			(void)fclose(f);
			return(1);
		}
	(void)fseek(f, 0L, L_SET);		/* rewind() not necessary */
D 43
	return(NULL);
E 43
I 43
	return(0);
E 43
E 41
E 33
}

/*
** A real function, for the tputs routine in termlib
*/

putch (ch)
char ch;
{
    putchar (ch);
}

/*
** Print out the contents of the file f, one screenful at a time.
*/

#define STOP -10

screen (f, num_lines)
register FILE *f;
register int num_lines;
{
    register int c;
    register int nchars;
D 4
    int length;
E 4
I 4
    int length;			/* length of current line */
    static int prev_len = 1;	/* length of previous line */
E 4

    for (;;) {
	while (num_lines > 0 && !Pause) {
	    if ((nchars = getline (f, &length)) == EOF)
I 2
	    {
D 4
		if(clreol) cleareod();
E 4
I 4
		if (clreol)
		    clreos();
E 4
E 2
		return;
I 2
	    }
I 4
	    if (ssp_opt && length == 0 && prev_len == 0)
		continue;
	    prev_len = length;
E 4
E 2
	    if (bad_so || (Senter && *Senter == ' ') && promptlen > 0)
		erase (0);
I 2
D 4
	    if (clreol) cleareol();
E 4
I 4
	    /* must clear before drawing line since tabs on some terminals
	     * do not erase what they tab over.
	     */
	    if (clreol)
		cleareol ();
E 4
E 2
	    prbuf (Line, length);
	    if (nchars < promptlen)
		erase (nchars);	/* erase () sets promptlen to 0 */
	    else promptlen = 0;
I 4
	    /* is this needed?
	     * if (clreol)
	     *	cleareol();	/* must clear again in case we wrapped *
	     */
E 4
	    if (nchars < Mcol || !fold_opt)
D 22
		putchar('\n');
E 22
I 22
		prbuf("\n", 1);	/* will turn off UL if necessary */
E 22
	    if (nchars == STOP)
		break;
	    num_lines--;
	}
I 22
	if (pstate) {
		tputs(ULexit, 1, putch);
		pstate = 0;
	}
E 22
	fflush(stdout);
	if ((c = Getc(f)) == EOF)
I 2
	{
D 4
	    if(clreol) cleareod();
E 4
I 4
	    if (clreol)
		clreos ();
E 4
E 2
	    return;
I 2
	}

D 4
	if(Pause && clreol) cleareod();

E 4
I 4
	if (Pause && clreol)
	    clreos ();
E 4
E 2
	Ungetc (c, f);
	setjmp (restore);
	Pause = 0; startup = 0;
	if ((num_lines = command (NULL, f)) == 0)
	    return;
	if (hard && promptlen > 0)
		erase (0);
D 10
	if (noscroll && num_lines == dlines)
E 10
I 10
	if (noscroll && num_lines >= dlines)
E 10
D 2
		doclear ();
E 2
I 2
D 20
	{ 
E 20
I 20
	{
E 20
D 4
	    if(clreol) home();
	    else doclear ();
E 4
I 4
	    if (clreol)
		home();
	    else
		doclear ();
E 4
	}
E 2
	screen_start.line = Currline;
	screen_start.chrctr = Ftell (f);
    }
}

/*
** Come here if a quit signal is received
*/

onquit()
{
    signal(SIGQUIT, SIG_IGN);
    if (!inwait) {
	putchar ('\n');
	if (!startup) {
	    signal(SIGQUIT, onquit);
	    longjmp (restore, 1);
	}
	else
	    Pause++;
    }
    else if (!dum_opt && notell) {
	write (2, "[Use q or Q to quit]", 20);
	promptlen += 20;
	notell = 0;
    }
    signal(SIGQUIT, onquit);
}

/*
I 30
** Come here if a signal for a window size change is received
*/

chgwinsz()
{
    struct winsize win;

    (void) signal(SIGWINCH, SIG_IGN);
    if (ioctl(fileno(stdout), TIOCGWINSZ, &win) != -1) {
	if (win.ws_row != 0) {
	    Lpp = win.ws_row;
	    nscroll = Lpp/2 - 1;
	    if (nscroll <= 0)
		nscroll = 1;
	    dlines = Lpp - (noscroll ? 1 : 2);
	}
	if (win.ws_col != 0)
	    Mcol = win.ws_col;
    }
    (void) signal(SIGWINCH, chgwinsz);
}

/*
E 30
** Clean up terminal state and exit. Also come here if interrupt signal received
*/

end_it ()
{

    reset_tty ();
D 2
    if (promptlen > 0) {
E 2
I 2
D 4
    if(clreol) { putchar('\r'); cleareod(); fflush(stdout); }
E 4
I 4
    if (clreol) {
	putchar ('\r');
	clreos ();
	fflush (stdout);
    }
E 4
    else if (!clreol && (promptlen > 0)) {
E 2
	kill_line ();
	fflush (stdout);
    }
    else
	write (2, "\n", 1);
    _exit(0);
}

copy_file(f)
register FILE *f;
{
    register int c;

    while ((c = getc(f)) != EOF)
	putchar(c);
}

/* Simplified printf function */

D 42
printf (fmt, args)
E 42
I 42
printf (fmt, va_alist)
E 42
register char *fmt;
D 42
int args;
E 42
I 42
va_dcl
E 42
{
D 42
	register int *argp;
E 42
I 42
	va_list ap;
E 42
	register char ch;
	register int ccount;

	ccount = 0;
D 42
	argp = &args;
E 42
I 42
	va_start(ap);
E 42
	while (*fmt) {
		while ((ch = *fmt++) != '%') {
			if (ch == '\0')
				return (ccount);
			ccount++;
			putchar (ch);
		}
		switch (*fmt++) {
		case 'd':
D 42
			ccount += printd (*argp);
E 42
I 42
			ccount += printd (va_arg(ap, int));
E 42
			break;
		case 's':
D 42
			ccount += pr ((char *)*argp);
E 42
I 42
			ccount += pr (va_arg(ap, char *));
E 42
			break;
		case '%':
			ccount++;
D 42
			argp--;
E 42
			putchar ('%');
			break;
		case '0':
			return (ccount);
		default:
			break;
		}
D 42
		++argp;
E 42
	}
I 42
	va_end(ap);
E 42
	return (ccount);

}

/*
** Print an integer as a string of decimal digits,
** returning the length of the print representation.
*/

printd (n)
int n;
{
    int a, nchars;

    if (a = n/10)
	nchars = 1 + printd(a);
    else
	nchars = 1;
    putchar (n % 10 + '0');
    return (nchars);
}

/* Put the print representation of an integer into a string */
static char *sptr;

scanstr (n, str)
int n;
char *str;
{
    sptr = str;
D 11
    sprintf (n);
E 11
I 11
    Sprintf (n);
E 11
    *sptr = '\0';
}

D 11
sprintf (n)
E 11
I 11
Sprintf (n)
E 11
{
    int a;

    if (a = n/10)
D 11
	sprintf (a);
E 11
I 11
	Sprintf (a);
E 11
    *sptr++ = n % 10 + '0';
}

D 44
static char bell = ctrl(G);
E 44
I 44
static char bell = ctrl('G');
E 44

strlen (s)
char *s;
{
    register char *p;

    p = s;
    while (*p++)
	;
    return (p - s - 1);
}

/* See whether the last component of the path name "path" is equal to the
** string "string"
*/

tailequ (path, string)
char *path;
register char *string;
{
	register char *tail;

	tail = path + strlen(path);
	while (tail >= path)
		if (*(--tail) == '/')
			break;
	++tail;
	while (*tail++ == *string++)
		if (*tail == '\0')
			return(1);
	return(0);
}

prompt (filename)
char *filename;
{
D 2
    if (promptlen > 0)
E 2
I 2
D 4
    if(clreol)cleareol();
E 4
I 4
    if (clreol)
	cleareol ();
E 4
    else if (promptlen > 0)
E 2
	kill_line ();
    if (!hard) {
	promptlen = 8;
D 22
	if (Senter && Sexit)
E 22
I 22
	if (Senter && Sexit) {
E 22
	    tputs (Senter, 1, putch);
I 22
	    promptlen += (2 * soglitch);
	}
E 22
I 2
D 4
	if(clreol)cleareol();
E 4
I 4
	if (clreol)
	    cleareol ();
E 4
E 2
	pr("--More--");
	if (filename != NULL) {
	    promptlen += printf ("(Next file: %s)", filename);
	}
	else if (!no_intty) {
	    promptlen += printf ("(%d%%)", (int)((file_pos * 100) / file_size));
	}
	if (dum_opt) {
D 22
	    promptlen += pr("[Hit space to continue, Rubout to abort]");
E 22
I 22
	    promptlen += pr("[Press space to continue, 'q' to quit.]");
E 22
	}
	if (Senter && Sexit)
	    tputs (Sexit, 1, putch);
I 4
	if (clreol)
	    clreos ();
E 4
	fflush(stdout);
    }
    else
	write (2, &bell, 1);
    inwait++;
}

/*
** Get a logical line
*/

getline(f, length)
register FILE *f;
int *length;
{
    register int	c;
    register char	*p;
    register int	column;
    static int		colflg;

    p = Line;
    column = 0;
    c = Getc (f);
    if (colflg && c == '\n') {
	Currline++;
	c = Getc (f);
    }
    while (p < &Line[LINSIZ - 1]) {
	if (c == EOF) {
	    if (p > Line) {
		*p = '\0';
		*length = p - Line;
		return (column);
	    }
	    *length = p - Line;
	    return (EOF);
	}
	if (c == '\n') {
	    Currline++;
	    break;
	}
	*p++ = c;
	if (c == '\t')
D 31
	    if (hardtabs && column < promptlen && !hard) {
		if (eraseln && !dumb) {
E 31
I 31
	    if (!hardtabs || column < promptlen && !hard) {
		if (hardtabs && eraseln && !dumb) {
E 31
		    column = 1 + (column | 7);
		    tputs (eraseln, 1, putch);
		    promptlen = 0;
		}
		else {
D 31
		    for (--p; column & 7 && p < &Line[LINSIZ - 1]; column++) {
E 31
I 31
		    for (--p; p < &Line[LINSIZ - 1];) {
E 31
			*p++ = ' ';
I 31
			if ((++column & 7) == 0)
			    break;
E 31
		    }
		    if (column >= promptlen) promptlen = 0;
		}
	    }
	    else
		column = 1 + (column | 7);
D 7
	else if (c == '\b')
E 7
I 7
	else if (c == '\b' && column > 0)
E 7
	    column--;
	else if (c == '\r')
	    column = 0;
	else if (c == '\f' && stop_opt) {
		p[-1] = '^';
		*p++ = 'L';
		column += 2;
		Pause++;
	}
	else if (c == EOF) {
	    *length = p - Line;
	    return (column);
	}
	else if (c >= ' ' && c != RUBOUT)
	    column++;
	if (column >= Mcol && fold_opt) break;
	c = Getc (f);
    }
    if (column >= Mcol && Mcol > 0) {
	if (!Wrap) {
	    *p++ = '\n';
	}
    }
    colflg = column == Mcol && fold_opt;
I 32
    if (colflg && eatnl && Wrap) {
	*p++ = '\n'; /* simulate normal wrap */
    }
E 32
    *length = p - Line;
    *p = 0;
    return (column);
}

/*
** Erase the rest of the prompt, assuming we are starting at column col.
*/

erase (col)
register int col;
{

    if (promptlen == 0)
	return;
    if (hard) {
	putchar ('\n');
    }
    else {
	if (col == 0)
	    putchar ('\r');
	if (!dumb && eraseln)
	    tputs (eraseln, 1, putch);
	else
	    for (col = promptlen - col; col > 0; col--)
		putchar (' ');
    }
    promptlen = 0;
}

/*
** Erase the current line entirely
*/

kill_line ()
{
    erase (0);
    if (!eraseln || dumb) putchar ('\r');
}

/*
I 2
 * force clear to end of line
 */
cleareol()
{
D 4
    tputs(eraseln,1,putch);
E 4
I 4
    tputs(eraseln, 1, putch);
E 4
}

D 4
cleareod()
E 4
I 4
clreos()
E 4
{
D 4
    tputs(Cleareod,1,putch);
E 4
I 4
    tputs(EodClr, 1, putch);
E 4
}

/*
E 2
**  Print string and return number of characters
*/

pr(s1)
char	*s1;
{
    register char	*s;
    register char	c;

    for (s = s1; c = *s++; )
	putchar(c);
    return (s - s1 - 1);
}


/* Print a buffer of n characters */

prbuf (s, n)
register char *s;
register int n;
{
D 4
    while (n-- > 0)
	putchar (*s++);
E 4
I 4
D 22
    char c;				/* next ouput character */
E 22
I 22
    register char c;			/* next output character */
E 22
    register int state;			/* next output char's UL state */
D 22
    static int pstate = 0;		/* current terminal UL state (off) */
E 22
I 22
#define wouldul(s,n)	((n) >= 2 && (((s)[0] == '_' && (s)[1] == '\b') || ((s)[1] == '\b' && (s)[2] == '_')))
E 22

    while (--n >= 0)
	if (!ul_opt)
	    putchar (*s++);
	else {
D 22
	    if (n >= 2 && s[0] == '_' && s[1] == '\b') {
E 22
I 22
	    if (*s == ' ' && pstate == 0 && ulglitch && wouldul(s+1, n-1)) {
		s++;
		continue;
	    }
	    if (state = wouldul(s, n)) {
		c = (*s == '_')? s[2] : *s ;
E 22
		n -= 2;
D 22
	        s += 2;
E 22
I 22
		s += 3;
	    } else
E 22
		c = *s++;
D 22
		state = 1;
	    } else if (n >= 2 && s[1] == '\b' && s[2] == '_') {
		n -= 2;
		c = *s++;
		s += 2;
		state = 1;
	    } else {
		c = *s++;
		state = 0;
E 22
I 22
	    if (state != pstate) {
		if (c == ' ' && state == 0 && ulglitch && wouldul(s, n-1))
		    state = 1;
		else
		    tputs(state ? ULenter : ULexit, 1, putch);
E 22
	    }
D 22
	    if (state != pstate)
		tputs(state ? ULenter : ULexit, 1, putch);
	    pstate = state;
	    putchar(c);
E 22
I 22
	    if (c != ' ' || pstate == 0 || state != 0 || ulglitch == 0)
	        putchar(c);
E 22
	    if (state && *chUL) {
		pr(chBS);
		tputs(chUL, 1, putch);
	    }
I 22
	    pstate = state;
E 22
	}
E 4
}

/*
**  Clear the screen
*/

doclear()
{
    if (Clear && !hard) {
	tputs(Clear, 1, putch);

	/* Put out carriage return so that system doesn't
	** get confused by escape sequences when expanding tabs
	*/
	putchar ('\r');
	promptlen = 0;
    }
}

I 2
/*
 * Go to home position
 */
home()
{
    tputs(Home,1,putch);
}

E 2
static int lastcmd, lastarg, lastp;
static int lastcolon;
char shell_line[132];

/*
** Read a command and do it. A command consists of an optional integer
** argument followed by the command character.  Return the number of lines
** to display in the next screenful.  If there is nothing more to display
** in the current file, zero is returned.
*/

command (filename, f)
char *filename;
register FILE *f;
{
    register int nlines;
    register int retval;
    register char c;
    char colonch;
    FILE *helpf;
    int done;
    char comchar, cmdbuf[80], *p;

#define ret(val) retval=val;done++;break

    done = 0;
    if (!errors)
	prompt (filename);
    else
	errors = 0;
    if (MBIT == RAW && slow_tty) {
	otty.sg_flags |= MBIT;
D 20
	stty(2, &otty);
E 20
I 20
	stty(fileno(stderr), &otty);
E 20
    }
    for (;;) {
	nlines = number (&comchar);
	lastp = colonch = 0;
	if (comchar == '.') {	/* Repeat last command */
		lastp++;
		comchar = lastcmd;
		nlines = lastarg;
		if (lastcmd == ':')
			colonch = lastcolon;
	}
	lastcmd = comchar;
	lastarg = nlines;
	if (comchar == otty.sg_erase) {
	    kill_line ();
	    prompt (filename);
	    continue;
	}
	switch (comchar) {
	case ':':
	    retval = colon (filename, colonch, nlines);
	    if (retval >= 0)
		done++;
	    break;
I 28
	case 'b':
D 44
	case ctrl(B):
E 44
I 44
	case ctrl('B'):
E 44
	    {
		register int initline;

		if (no_intty) {
		    write(2, &bell, 1);
		    return (-1);
		}

		if (nlines == 0) nlines++;

		putchar ('\r');
		erase (0);
		printf ("\n");
		if (clreol)
			cleareol ();
		printf ("...back %d page", nlines);
		if (nlines > 1)
			pr ("s\n");
		else
			pr ("\n");

		if (clreol)
			cleareol ();
		pr ("\n");

		initline = Currline - dlines * (nlines + 1);
		if (! noscroll)
		    --initline;
		if (initline < 0) initline = 0;
		Fseek(f, 0L);
		Currline = 0;	/* skiplns() will make Currline correct */
		skiplns(initline, f);
		if (! noscroll) {
		    ret(dlines + 1);
		}
		else {
		    ret(dlines);
		}
	    }
E 28
	case ' ':
	case 'z':
	    if (nlines == 0) nlines = dlines;
	    else if (comchar == 'z') dlines = nlines;
	    ret (nlines);
	case 'd':
D 44
	case ctrl(D):
E 44
I 44
	case ctrl('D'):
E 44
	    if (nlines != 0) nscroll = nlines;
	    ret (nscroll);
D 28
	case RUBOUT:
E 28
	case 'q':
	case 'Q':
	    end_it ();
	case 's':
	case 'f':
	    if (nlines == 0) nlines++;
	    if (comchar == 'f')
		nlines *= dlines;
	    putchar ('\r');
	    erase (0);
D 2
	    printf("\n...skipping %d line", nlines);
E 2
I 2
D 4
	    printf("\n");
	    if(clreol)cleareol();
	    printf("...skipping %d line", nlines);
E 4
I 4
	    printf ("\n");
	    if (clreol)
		cleareol ();
	    printf ("...skipping %d line", nlines);
E 4
E 2
	    if (nlines > 1)
D 2
		pr("s\n\n");
E 2
I 2
D 4
	    {
		pr("s\n");
	        if(clreol)cleareol();
		pr("\n");
	    }
E 4
I 4
		pr ("s\n");
E 4
E 2
	    else
D 2
		pr("\n\n");
E 2
I 2
D 4
	    {
		pr("\n");
	        if(clreol)cleareol();
		pr("\n");
	    }
E 4
I 4
		pr ("\n");

	    if (clreol)
		cleareol ();
	    pr ("\n");

E 4
E 2
	    while (nlines > 0) {
		while ((c = Getc (f)) != '\n')
		    if (c == EOF) {
			retval = 0;
			done++;
			goto endsw;
		    }
		    Currline++;
		    nlines--;
	    }
	    ret (dlines);
	case '\n':
	    if (nlines != 0)
		dlines = nlines;
	    else
		nlines = 1;
	    ret (nlines);
	case '\f':
	    if (!no_intty) {
		doclear ();
		Fseek (f, screen_start.chrctr);
		Currline = screen_start.line;
		ret (dlines);
	    }
	    else {
		write (2, &bell, 1);
		break;
	    }
	case '\'':
	    if (!no_intty) {
		kill_line ();
		pr ("\n***Back***\n\n");
		Fseek (f, context.chrctr);
		Currline = context.line;
		ret (dlines);
	    }
	    else {
		write (2, &bell, 1);
		break;
	    }
	case '=':
	    kill_line ();
	    promptlen = printd (Currline);
	    fflush (stdout);
	    break;
	case 'n':
	    lastp++;
	case '/':
	    if (nlines == 0) nlines++;
	    kill_line ();
	    pr ("/");
	    promptlen = 1;
	    fflush (stdout);
	    if (lastp) {
		write (2,"\r", 1);
		search (NULL, f, nlines);	/* Use previous r.e. */
	    }
	    else {
		ttyin (cmdbuf, 78, '/');
		write (2, "\r", 1);
		search (cmdbuf, f, nlines);
	    }
D 2
	    ret (dlines);
E 2
I 2
	    ret (dlines-1);
E 2
	case '!':
	    do_shell (filename);
	    break;
I 28
	case '?':
E 28
	case 'h':
	    if ((helpf = fopen (HELPFILE, "r")) == NULL)
		error ("Can't open help file");
	    if (noscroll) doclear ();
	    copy_file (helpf);
D 30
	    close (helpf);
E 30
I 30
	    fclose (helpf);
E 30
	    prompt (filename);
	    break;
	case 'v':	/* This case should go right before default */
	    if (!no_intty) {
		kill_line ();
		cmdbuf[0] = '+';
D 28
		scanstr (Currline, &cmdbuf[1]);
E 28
I 28
		scanstr (Currline - dlines < 0 ? 0
				: Currline - (dlines + 1) / 2, &cmdbuf[1]);
E 28
		pr ("vi "); pr (cmdbuf); putchar (' '); pr (fnames[fnum]);
		execute (filename, VI, "vi", cmdbuf, fnames[fnum], 0);
		break;
	    }
	default:
D 22
	    write (2, &bell, 1);
E 22
I 22
	    if (dum_opt) {
   		kill_line ();
		if (Senter && Sexit) {
		    tputs (Senter, 1, putch);
		    promptlen = pr ("[Press 'h' for instructions.]") + (2 * soglitch);
		    tputs (Sexit, 1, putch);
		}
		else
		    promptlen = pr ("[Press 'h' for instructions.]");
		fflush (stdout);
	    }
	    else
		write (2, &bell, 1);
E 22
	    break;
	}
	if (done) break;
    }
    putchar ('\r');
endsw:
    inwait = 0;
    notell++;
    if (MBIT == RAW && slow_tty) {
	otty.sg_flags &= ~MBIT;
D 20
	stty(2, &otty);
E 20
I 20
	stty(fileno(stderr), &otty);
E 20
    }
    return (retval);
}

char ch;

/*
 * Execute a colon-prefixed command.
 * Returns <0 if not a command that should cause
 * more of the file to be printed.
 */

colon (filename, cmd, nlines)
char *filename;
int cmd;
int nlines;
{
	if (cmd == 0)
		ch = readch ();
	else
		ch = cmd;
	lastcolon = ch;
	switch (ch) {
	case 'f':
		kill_line ();
		if (!no_intty)
			promptlen = printf ("\"%s\" line %d", fnames[fnum], Currline);
		else
			promptlen = printf ("[Not a file] line %d", Currline);
		fflush (stdout);
		return (-1);
	case 'n':
		if (nlines == 0) {
			if (fnum >= nfiles - 1)
				end_it ();
			nlines++;
		}
		putchar ('\r');
		erase (0);
		skipf (nlines);
		return (0);
	case 'p':
		if (no_intty) {
			write (2, &bell, 1);
			return (-1);
		}
		putchar ('\r');
		erase (0);
		if (nlines == 0)
			nlines++;
		skipf (-nlines);
		return (0);
	case '!':
		do_shell (filename);
		return (-1);
	case 'q':
	case 'Q':
		end_it ();
	default:
		write (2, &bell, 1);
		return (-1);
	}
}

/*
** Read a decimal number from the terminal. Set cmd to the non-digit which
** terminates the number.
*/

number(cmd)
char *cmd;
{
	register int i;

	i = 0; ch = otty.sg_kill;
	for (;;) {
		ch = readch ();
		if (ch >= '0' && ch <= '9')
			i = i*10 + ch - '0';
		else if (ch == otty.sg_kill)
			i = 0;
		else {
			*cmd = ch;
			break;
		}
	}
	return (i);
}

do_shell (filename)
char *filename;
{
	char cmdbuf[80];

	kill_line ();
	pr ("!");
	fflush (stdout);
	promptlen = 1;
	if (lastp)
		pr (shell_line);
	else {
		ttyin (cmdbuf, 78, '!');
		if (expand (shell_line, cmdbuf)) {
			kill_line ();
			promptlen = printf ("!%s", shell_line);
		}
	}
	fflush (stdout);
	write (2, "\n", 1);
	promptlen = 0;
	shellp = 1;
	execute (filename, shell, shell, "-c", shell_line, 0);
}

/*
** Search for nth ocurrence of regular expression contained in buf in the file
*/

search (buf, file, n)
char buf[];
FILE *file;
register int n;
{
    long startline = Ftell (file);
    register long line1 = startline;
    register long line2 = startline;
    register long line3 = startline;
    register int lncount;
    int saveln, rv, re_exec();
    char *s, *re_comp();

    context.line = saveln = Currline;
    context.chrctr = startline;
    lncount = 0;
    if ((s = re_comp (buf)) != 0)
	error (s);
    while (!feof (file)) {
	line3 = line2;
	line2 = line1;
	line1 = Ftell (file);
	rdline (file);
	lncount++;
	if ((rv = re_exec (Line)) == 1)
		if (--n == 0) {
		    if (lncount > 3 || (lncount > 1 && no_intty))
D 2
			pr ("\n...skipping\n");
E 2
I 2
		    {
			pr ("\n");
D 4
			if(clreol) cleareol();
E 4
I 4
			if (clreol)
			    cleareol ();
E 4
			pr("...skipping\n");
		    }
E 2
		    if (!no_intty) {
			Currline -= (lncount >= 3 ? 3 : lncount);
			Fseek (file, line3);
I 2
D 4
			if(noscroll)
			  if(clreol)
			  {
			     home(); 
			     cleareol();
			  } 
			  else doclear();
E 4
I 4
			if (noscroll)
			    if (clreol) {
				home ();
				cleareol ();
D 20
			    } 
E 20
I 20
			    }
E 20
			    else
				doclear ();
E 4
E 2
		    }
		    else {
			kill_line ();
I 2
D 4
			if(noscroll)
			  if(clreol)
			  {
			     home(); 
			     cleareol();
			  } 
			  else doclear();
E 4
I 4
			if (noscroll)
			    if (clreol) {
D 20
			        home (); 
E 20
I 20
			        home ();
E 20
			        cleareol ();
D 20
			    } 
E 20
I 20
			    }
E 20
			    else
				doclear ();
E 4
E 2
			pr (Line);
			putchar ('\n');
		    }
		    break;
		}
	else if (rv == -1)
	    error ("Regular expression botch");
    }
    if (feof (file)) {
	if (!no_intty) {
D 5
#ifdef V6
E 5
	    file->_flag &= ~_IOEOF; /* why doesn't fseek do this ??!!??! */
D 5
#endif
E 5
	    Currline = saveln;
	    Fseek (file, startline);
	}
	else {
	    pr ("\nPattern not found\n");
	    end_it ();
	}
	error ("Pattern not found");
    }
}

D 42
execute (filename, cmd, args)
E 42
I 42
/*VARARGS2*/
execute (filename, cmd, va_alist)
E 42
char *filename;
D 42
char *cmd, *args;
E 42
I 42
char *cmd;
va_dcl
E 42
{
	int id;
I 22
	int n;
I 42
	va_list argp;
E 42
E 22

	fflush (stdout);
	reset_tty ();
D 22
	while ((id = fork ()) < 0)
E 22
I 22
	for (n = 10; (id = fork ()) < 0 && n > 0; n--)
E 22
	    sleep (5);
	if (id == 0) {
I 22
	    if (!isatty(0)) {
		close(0);
		open("/dev/tty", 0);
	    }
E 22
D 42
	    execv (cmd, &args);
E 42
I 42
	    va_start(argp);
	    execv (cmd, argp);
E 42
	    write (2, "exec failed\n", 12);
	    exit (1);
I 43
	    va_end(argp);	/* balance {}'s for some UNIX's */
E 43
	}
D 22
	signal (SIGINT, SIG_IGN);
	signal (SIGQUIT, SIG_IGN);
D 5
#ifdef SIGTSTP
E 5
	if (catch_susp)
	    signal(SIGTSTP, SIG_DFL);
D 5
#endif
E 5
	wait (0);
	signal (SIGINT, end_it);
	signal (SIGQUIT, onquit);
D 5
#ifdef SIGTSTP
E 5
	if (catch_susp)
	    signal(SIGTSTP, onsusp);
E 22
I 22
	if (id > 0) {
	    signal (SIGINT, SIG_IGN);
	    signal (SIGQUIT, SIG_IGN);
	    if (catch_susp)
		signal(SIGTSTP, SIG_DFL);
	    while (wait(0) > 0);
	    signal (SIGINT, end_it);
	    signal (SIGQUIT, onquit);
	    if (catch_susp)
		signal(SIGTSTP, onsusp);
	} else
	    write(2, "can't fork\n", 11);
E 22
D 5
#endif
E 5
	set_tty ();
	pr ("------------------------\n");
	prompt (filename);
}
/*
** Skip n lines in the file f
*/

skiplns (n, f)
register int n;
register FILE *f;
{
    register char c;

    while (n > 0) {
	while ((c = Getc (f)) != '\n')
	    if (c == EOF)
		return;
	    n--;
	    Currline++;
    }
}

/*
** Skip nskip files in the file list (from the command line). Nskip may be
** negative.
*/

skipf (nskip)
register int nskip;
{
    if (nskip == 0) return;
    if (nskip > 0) {
	if (fnum + nskip > nfiles - 1)
	    nskip = nfiles - fnum - 1;
    }
    else if (within)
	++fnum;
    fnum += nskip;
    if (fnum < 0)
	fnum = 0;
I 4
    pr ("\n...Skipping ");
E 4
D 2
    pr ("\n...Skipping ");
E 2
I 2
    pr ("\n");
D 4
    if (clreol) cleareol();
E 4
I 4
    if (clreol)
	cleareol ();
E 4
    pr ("...Skipping ");
E 2
    pr (nskip > 0 ? "to file " : "back to file ");
    pr (fnames[fnum]);
D 2
    pr ("\n\n");
E 2
I 2
    pr ("\n");
D 4
    if (clreol) cleareol();
E 4
I 4
    if (clreol)
	cleareol ();
E 4
    pr ("\n");
E 2
    --fnum;
}

/*----------------------------- Terminal I/O -------------------------------*/

initterm ()
{
    char	buf[TBUFSIZ];
D 23
    char	clearbuf[100];
E 23
I 23
    static char	clearbuf[TBUFSIZ];
E 23
    char	*clearptr, *padstr;
D 2
    char	*getenv();
E 2
    int		ldisc;
I 24
    int		lmode;
E 24
I 8
    char	*term;
I 20
    int		tgrp;
I 25
    struct winsize win;
E 25
E 20
E 8

D 23
    setbuf(stdout, obuf);
E 23
D 20
    if (!(no_tty = gtty(1, &otty))) {
E 20
I 20
retry:
    if (!(no_tty = gtty(fileno(stdout), &otty))) {
I 24
	if (ioctl(fileno(stdout), TIOCLGET, &lmode) < 0) {
	    perror("TIOCLGET");
	    exit(1);
	}
	docrterase = ((lmode & LCRTERA) != 0);
	docrtkill = ((lmode & LCRTKIL) != 0);
E 24
	/*
D 24
	 * Wait until we're in the foreground before we get the
	 * save the terminal modes.
E 24
I 24
	 * Wait until we're in the foreground before we save the
	 * the terminal modes.
E 24
	 */
	if (ioctl(fileno(stdout), TIOCGPGRP, &tgrp) < 0) {
D 24
	    perror("ioctl");
E 24
I 24
	    perror("TIOCGPGRP");
E 24
	    exit(1);
	}
	if (tgrp != getpgrp(0)) {
	    kill(0, SIGTTOU);
	    goto retry;
	}
E 20
D 8
	if (tgetent(buf, getenv("TERM")) <= 0) {
E 8
I 8
D 9
	if ((term = getenv("TERM")) || tgetent(buf, term) <= 0) {
E 9
I 9
D 13
	if ((term = getenv("TERM")) && tgetent(buf, term) <= 0) {
E 13
I 13
D 15
	if ((term = getenv("TERM")) || tgetent(buf, term) <= 0) {
E 15
I 15
	if ((term = getenv("TERM")) == 0 || tgetent(buf, term) <= 0) {
E 15
E 13
E 9
E 8
D 4
	    dumb++;
E 4
I 4
	    dumb++; ul_opt = 0;
E 4
	}
	else {
D 25
	    if (((Lpp = tgetnum("li")) < 0) || tgetflag("hc")) {
E 25
I 25
	    if (ioctl(fileno(stdout), TIOCGWINSZ, &win) < 0) {
		Lpp = tgetnum("li");
		Mcol = tgetnum("co");
	    } else {
		if ((Lpp = win.ws_row) == 0)
		    Lpp = tgetnum("li");
		if ((Mcol = win.ws_col) == 0)
		    Mcol = tgetnum("co");
	    }
	    if ((Lpp <= 0) || tgetflag("hc")) {
E 25
		hard++;	/* Hard copy terminal */
		Lpp = 24;
	    }
I 32
	    if (tgetflag("xn"))
		eatnl++; /* Eat newline at last column + 1; dec, concept */
E 32
I 25
	    if (Mcol <= 0)
		Mcol = 80;

E 25
	    if (tailequ (fnames[0], "page") || !hard && tgetflag("ns"))
		noscroll++;
D 25
	    if ((Mcol = tgetnum("co")) < 0)
		Mcol = 80;
E 25
	    Wrap = tgetflag("am");
	    bad_so = tgetflag ("xs");
	    clearptr = clearbuf;
	    eraseln = tgetstr("ce",&clearptr);
	    Clear = tgetstr("cl", &clearptr);
	    Senter = tgetstr("so", &clearptr);
	    Sexit = tgetstr("se", &clearptr);
I 22
	    if ((soglitch = tgetnum("sg")) < 0)
		soglitch = 0;
E 22
I 4

	    /*
	     *  Set up for underlining:  some terminals don't need it;
	     *  others have start/stop sequences, still others have an
	     *  underline char sequence which is assumed to move the
	     *  cursor forward one character.  If underline sequence
	     *  isn't available, settle for standout sequence.
	     */

	    if (tgetflag("ul") || tgetflag("os"))
		ul_opt = 0;
	    if ((chUL = tgetstr("uc", &clearptr)) == NULL )
		chUL = "";
D 22
	    if ((ULenter = tgetstr("us", &clearptr)) == NULL &&
		(!*chUL) && (ULenter = tgetstr("so", &clearptr)) == NULL)
		ULenter = "";
	    if ((ULexit = tgetstr("ue", &clearptr)) == NULL &&
		(!*chUL) && (ULexit = tgetstr("se", &clearptr)) == NULL)
		ULexit = "";
E 22
I 22
	    if (((ULenter = tgetstr("us", &clearptr)) == NULL ||
	         (ULexit = tgetstr("ue", &clearptr)) == NULL) && !*chUL) {
	        if ((ULenter = Senter) == NULL || (ULexit = Sexit) == NULL) {
			ULenter = "";
			ULexit = "";
		} else
			ulglitch = soglitch;
	    } else {
		if ((ulglitch = tgetnum("ug")) < 0)
		    ulglitch = 0;
	    }
E 22
D 20
	    
E 20
I 20

E 20
E 4
	    if (padstr = tgetstr("pc", &clearptr))
		PC = *padstr;
I 2
	    Home = tgetstr("ho",&clearptr);
D 4
	    if(*Home == '\0')
E 4
I 4
D 8
	    if (*Home == '\0')
E 8
I 8
D 9
	    if (Home == 0 || *Home == '\0')
E 9
I 9
D 13
	    if (Home == 0 && *Home == '\0')
E 13
I 13
	    if (Home == 0 || *Home == '\0')
E 13
E 9
E 8
E 4
	    {
D 4
	       if(*(cursorm = tgetstr("cm",&clearptr)))
	       {
		    strcpy(cursorhome,tgoto(cursorm,0,0));
E 4
I 4
		if ((cursorm = tgetstr("cm", &clearptr)) != NULL) {
		    strcpy(cursorhome, tgoto(cursorm, 0, 0));
E 4
		    Home = cursorhome;
	       }
	    }
D 4
	    Cleareod = tgetstr("cd",&clearptr);
E 4
I 4
	    EodClr = tgetstr("cd", &clearptr);
I 29
	    if ((chBS = tgetstr("bc", &clearptr)) == NULL)
		chBS = "\b";

E 29
E 4
E 2
	}
	if ((shell = getenv("SHELL")) == NULL)
	    shell = "/bin/sh";
    }
D 20
    no_intty = gtty(0, &otty);
    gtty(2, &otty);
E 20
I 20
    no_intty = gtty(fileno(stdin), &otty);
    gtty(fileno(stderr), &otty);
E 20
I 15
    savetty = otty;
E 15
    ospeed = otty.sg_ospeed;
    slow_tty = ospeed < B1200;
D 30
    hardtabs =  !(otty.sg_flags & XTABS);
E 30
I 30
    hardtabs = (otty.sg_flags & TBDELAY) != XTABS;
E 30
    if (!no_tty) {
	otty.sg_flags &= ~ECHO;
	if (MBIT == CBREAK || !slow_tty)
	    otty.sg_flags |= MBIT;
    }
}

readch ()
{
	char ch;
	extern int errno;

I 38
	errno = 0;
E 38
	if (read (2, &ch, 1) <= 0)
		if (errno != EINTR)
D 38
			exit(0);
E 38
I 38
			end_it();
E 38
		else
			ch = otty.sg_kill;
	return (ch);
}

static char BS = '\b';
I 24
static char *BSB = "\b \b";
E 24
static char CARAT = '^';
I 24
#define ERASEONECHAR \
    if (docrterase) \
	write (2, BSB, sizeof(BSB)); \
    else \
	write (2, &BS, sizeof(BS));
E 24

ttyin (buf, nmax, pchar)
char buf[];
register int nmax;
char pchar;
{
    register char *sptr;
    register char ch;
    register int slash = 0;
    int	maxlen;
    char cbuf;

    sptr = buf;
    maxlen = 0;
    while (sptr - buf < nmax) {
	if (promptlen > maxlen) maxlen = promptlen;
	ch = readch ();
	if (ch == '\\') {
	    slash++;
	}
	else if ((ch == otty.sg_erase) && !slash) {
	    if (sptr > buf) {
		--promptlen;
D 24
		write (2, &BS, 1);
E 24
I 24
		ERASEONECHAR
E 24
		--sptr;
		if ((*sptr < ' ' && *sptr != '\n') || *sptr == RUBOUT) {
		    --promptlen;
D 24
		    write (2, &BS, 1);
E 24
I 24
		    ERASEONECHAR
E 24
		}
		continue;
	    }
	    else {
		if (!eraseln) promptlen = maxlen;
		longjmp (restore, 1);
	    }
	}
	else if ((ch == otty.sg_kill) && !slash) {
	    if (hard) {
		show (ch);
		putchar ('\n');
		putchar (pchar);
	    }
	    else {
		putchar ('\r');
		putchar (pchar);
		if (eraseln)
		    erase (1);
I 24
		else if (docrtkill)
		    while (promptlen-- > 1)
			write (2, BSB, sizeof(BSB));
E 24
		promptlen = 1;
	    }
	    sptr = buf;
	    fflush (stdout);
	    continue;
	}
	if (slash && (ch == otty.sg_kill || ch == otty.sg_erase)) {
D 24
	    write (2, &BS, 1);
E 24
I 24
	    ERASEONECHAR
E 24
	    --sptr;
	}
	if (ch != '\\')
	    slash = 0;
	*sptr++ = ch;
	if ((ch < ' ' && ch != '\n' && ch != ESC) || ch == RUBOUT) {
	    ch += ch == RUBOUT ? -0100 : 0100;
	    write (2, &CARAT, 1);
	    promptlen++;
	}
	cbuf = ch;
	if (ch != '\n' && ch != ESC) {
	    write (2, &cbuf, 1);
	    promptlen++;
	}
	else
	    break;
    }
    *--sptr = '\0';
    if (!eraseln) promptlen = maxlen;
    if (sptr - buf >= nmax - 1)
	error ("Line too long");
}

expand (outbuf, inbuf)
char *outbuf;
char *inbuf;
{
    register char *instr;
    register char *outstr;
    register char ch;
    char temp[200];
    int changed = 0;

    instr = inbuf;
    outstr = temp;
    while ((ch = *instr++) != '\0')
	switch (ch) {
	case '%':
	    if (!no_intty) {
		strcpy (outstr, fnames[fnum]);
		outstr += strlen (fnames[fnum]);
		changed++;
	    }
	    else
		*outstr++ = ch;
	    break;
	case '!':
	    if (!shellp)
		error ("No previous command to substitute for");
	    strcpy (outstr, shell_line);
	    outstr += strlen (shell_line);
	    changed++;
	    break;
	case '\\':
	    if (*instr == '%' || *instr == '!') {
		*outstr++ = *instr++;
		break;
	    }
	default:
	    *outstr++ = ch;
	}
    *outstr++ = '\0';
    strcpy (outbuf, temp);
    return (changed);
}

show (ch)
register char ch;
{
    char cbuf;

    if ((ch < ' ' && ch != '\n' && ch != ESC) || ch == RUBOUT) {
	ch += ch == RUBOUT ? -0100 : 0100;
	write (2, &CARAT, 1);
	promptlen++;
    }
    cbuf = ch;
    write (2, &cbuf, 1);
    promptlen++;
}

error (mess)
char *mess;
{
D 2
    kill_line ();
E 2
I 2
D 4
    if(clreol)cleareol();
    else kill_line ();
E 4
I 4
    if (clreol)
	cleareol ();
    else
	kill_line ();
E 4
E 2
    promptlen += strlen (mess);
    if (Senter && Sexit) {
	tputs (Senter, 1, putch);
	pr(mess);
	tputs (Sexit, 1, putch);
    }
    else
	pr (mess);
    fflush(stdout);
    errors++;
    longjmp (restore, 1);
}


set_tty ()
{
	otty.sg_flags |= MBIT;
	otty.sg_flags &= ~ECHO;
D 20
	stty(2, &otty);
E 20
I 20
	stty(fileno(stderr), &otty);
E 20
}

reset_tty ()
{
I 37
    if (no_tty)
	return;
E 37
I 22
    if (pstate) {
	tputs(ULexit, 1, putch);
	fflush(stdout);
	pstate = 0;
    }
E 22
    otty.sg_flags |= ECHO;
    otty.sg_flags &= ~MBIT;
D 15
    stty(2, &otty);
E 15
I 15
D 20
    stty(2, &savetty);
E 20
I 20
    stty(fileno(stderr), &savetty);
E 20
E 15
}

rdline (f)
register FILE *f;
{
    register char c;
    register char *p;

    p = Line;
    while ((c = Getc (f)) != '\n' && c != EOF && p - Line < LINSIZ - 1)
	*p++ = c;
    if (c == '\n')
	Currline++;
    *p = '\0';
}

/* Come here when we get a suspend signal from the terminal */

D 5
#ifdef SIGTSTP
E 5
onsusp ()
{
I 16
    /* ignore SIGTTOU so we don't get stopped if csh grabs the tty */
    signal(SIGTTOU, SIG_IGN);
E 16
    reset_tty ();
    fflush (stdout);
I 16
    signal(SIGTTOU, SIG_DFL);
E 16
    /* Send the TSTP signal to suspend our process group */
I 12
    signal(SIGTSTP, SIG_DFL);
    sigsetmask(0);
E 12
    kill (0, SIGTSTP);
    /* Pause for station break */

    /* We're back */
    signal (SIGTSTP, onsusp);
    set_tty ();
    if (inwait)
	    longjmp (restore);
}
D 5
#endif
E 5
E 1
