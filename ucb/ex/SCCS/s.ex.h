h31328
s 00068/00047/00385
d D 7.10 03/04/13 15:18:41 msokolov 21 19
c 8-bit ex
e
s 00000/00015/00417
d D 7.9.1.1 88/08/08 18:28:25 mckusick 20 19
c delete decryption for the foreign sites (4.3BSD Tahoe)
e
s 00003/00003/00429
d D 7.9 88/01/02 23:12:14 bostic 19 18
c fix CTRL macro for ANSI C
e
s 00027/00006/00405
d D 7.8 87/03/09 12:46:55 conrad 18 16
c make ex/vi work on vms
e
s 00000/00015/00396
d D 7.7.1.1 86/08/12 15:51:50 mckusick 17 16
c delete decryption for the foreign sites
e
s 00008/00002/00403
d D 7.7 85/05/31 15:36:58 dist 16 14
c Add copyright
e
s 00008/00002/00392
d D 5.1.1.1 85/05/31 11:50:18 dist 15 7
c Add copyright
e
s 00002/00001/00403
d D 7.6 85/03/27 11:57:19 bloom 14 13
c use optimal size for i/o
e
s 00002/00001/00402
d D 7.5 83/06/10 10:08:29 ralph 13 12
c updating sccs files due to restoring an older SCCS directory
e
s 00004/00000/00399
d D 7.4 81/09/03 11:44:08 mark 12 11
c updates for Unix/370 and ins/del line on vt100
e
s 00001/00001/00398
d D 7.3 81/07/26 20:24:12 mark 11 10
c fixed typo
e
s 00095/00092/00304
d D 7.2 81/07/26 20:02:02 mark 10 9
c fixes for 3b
e
s 00094/00094/00302
d D 7.1 81/07/08 22:27:50 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00002/00000/00394
d D 6.1 80/10/19 01:20:01 mark 8 7
c preliminary release 3.6 10/18/80
e
s 00000/00000/00394
d D 5.1 80/08/20 16:07:39 mark 7 6
c Release 3.5, August 20, 1980
e
s 00002/00000/00392
d D 4.3 80/08/20 00:24:16 mark 6 5
c made CRYPT an #ifdef
e
s 00002/00001/00390
d D 4.2 80/08/01 17:58:44 mark 5 4
c added sccs, Bill put in more buffers
e
s 00039/00004/00352
d D 4.1 80/08/01 00:09:34 mark 4 3
c release 3.4, June 24, 1980
e
s 00011/00006/00345
d D 3.1 80/07/31 23:35:54 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00016/00006/00335
d D 2.1 80/07/31 23:17:16 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00341/00000/00000
d D 1.1 80/07/31 23:00:00 mark 1 0
c date and time created 80/07/31 23:00:00 by mark
e
u
U
f b 
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 9
D 15
/* Copyright (c) 1980 Regents of the University of California */
/* sccs id:	%W% %G%  */
E 15
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 15
E 9
I 9
D 16
/* Copyright (c) 1981 Regents of the University of California */
/* sccs id:	%W%	%G%  */
E 16
I 16
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 16
E 9
E 5
#ifdef V6
#include <retrofit.h>
#endif

/*
D 4
 * Ex version 3.1
E 4
I 4
 * Ex version 3 (see exact version in ex_cmds.c, search for /Version/)
E 4
 *
 * Mark Horton, UC Berkeley
 * Bill Joy, UC Berkeley
 * November 1979
 *
 * This file contains most of the declarations common to a large number
 * of routines.  The file ex_vis.h contains declarations
 * which are used only inside the screen editor.
 * The file ex_tune.h contains parameters which can be diddled per installation.
 *
 * The declarations relating to the argument list, regular expressions,
 * the temporary file data structure used by the editor
 * and the data describing terminals are each fairly substantial and
 * are kept in the files ex_{argv,re,temp,tty}.h which
 * we #include separately.
 *
 * If you are going to dig into ex, you should look at the outline of the
 * distribution of the code into files at the beginning of ex.c and ex_v.c.
 * Code which is similar to that of ed is lightly or undocumented in spots
 * (e.g. the regular expression code).  Newer code (e.g. open and visual)
 * is much more carefully documented, and still rough in spots.
 *
 * Please forward bug reports to
 *
D 4
 *	Bill Joy
E 4
I 4
 *	Mark Horton
E 4
 *	Computer Science Division, EECS
 *	EVANS HALL
 *	U.C. Berkeley 94704
 *	(415) 642-4948
 *	(415) 642-1024 (dept. office)
 *
D 4
 * or to wnj@mit-mc on the ARPA-net.  I would particularly like to hear
E 4
I 4
 * or to csvax.mark@berkeley on the ARPA-net.  I would particularly like to hear
E 4
 * of additional terminal descriptions you add to the termcap data base.
 */

I 18
#ifndef	vms
E 18
D 13
#include <sys/types.h>
E 13
I 13
#include <sys/param.h>
I 18
#else
#define	MAXBSIZE	1024	/* Maximum block size */
#include <types.h>
#endif
E 18
E 13
#include <ctype.h>
#include <errno.h>
D 4
#include <sgtty.h>
E 4
#include <signal.h>
#include <setjmp.h>
I 18
#ifndef	vms
E 18
#include <sys/stat.h>
I 18
#else
#include <stat.h>
#endif
E 18

I 10
#ifndef var
D 11
#define var	var
E 11
I 11
#define var	extern
E 11
#endif
E 10
I 4
/*
 *	The following little dance copes with the new USG tty handling.
 *	This stuff has the advantage of considerable flexibility, and
 *	the disadvantage of being incompatible with anything else.
 *	The presence of the symbol USG3TTY will indicate the new code:
 *	in this case, we define CBREAK (because we can simulate it exactly),
 *	but we won't actually use it, so we set it to a value that will
 *	probably blow the compilation if we goof up.
 */
#ifdef USG3TTY
#include <termio.h>
#define CBREAK xxxxx
#else
I 18
#ifndef	vms
E 18
#include <sgtty.h>
I 18
#else
#include "vmstty.h"
E 18
#endif
I 18
#endif
E 18

E 4
extern	int errno;

I 2
#ifndef VMUNIX
E 2
typedef	short	line;
I 2
#else
typedef	int	line;
#endif
E 2
typedef	short	bool;

#include "ex_tune.h"
#include "ex_vars.h"
/*
 * Options in the editor are referred to usually by "value(name)" where
 * name is all uppercase, i.e. "value(PROMPT)".  This is actually a macro
 * which expands to a fixed field in a static structure and so generates
 * very little code.  The offsets for the option names in the structure
 * are generated automagically from the structure initializing them in
 * ex_data.c... see the shell script "makeoptions".
 */
struct	option {
D 21
	char	*oname;
	char	*oabbrev;
E 21
I 21
	u_char	*oname;
	u_char	*oabbrev;
E 21
	short	otype;		/* Types -- see below */
	short	odefault;	/* Default value */
	short	ovalue;		/* Current value */
D 21
	char	*osvalue;
E 21
I 21
	u_char	*osvalue;
E 21
};

#define	ONOFF	0
#define	NUMERIC	1
#define	STRING	2		/* SHELL or DIRECTORY */
#define	OTERM	3

#define	value(a)	options[a].ovalue
#define	svalue(a)	options[a].osvalue

D 9
struct	option options[NOPTS + 1];
E 9
I 9
D 10
extern struct	option options[NOPTS + 1];
E 10
I 10
extern	 struct	option options[NOPTS + 1];
E 10
E 9

I 18
#ifdef vms
#define	st_blksize	st_fab_mrs
#define	_exit(n)	vms_exit(n)
#define	fork()		vfork()
#endif
E 18

/*
 * The editor does not normally use the standard i/o library.  Because
 * we expect the editor to be a heavily used program and because it
 * does a substantial amount of input/output processing it is appropriate
 * for it to call low level read/write primitives directly.  In fact,
 * when debugging the editor we use the standard i/o library.  In any
 * case the editor needs a printf which prints through "putchar" ala the
 * old version 6 printf.  Thus we normally steal a copy of the "printf.c"
 * and "strout" code from the standard i/o library and mung it for our
 * purposes to avoid dragging in the stdio library headers, etc if we
 * are not debugging.  Such a modified printf exists in "printf.c" here.
 */
#ifdef TRACE
D 18
#	include <stdio.h>
E 18
I 18
# include <stdio.h>
E 18
D 9
	FILE	*trace;
	bool	trubble;
	bool	techoin;
	char	tracbuf[BUFSIZ];
E 9
I 9
D 10
	extern FILE	*trace;
	extern bool	trubble;
	extern bool	techoin;
	extern char	tracbuf[BUFSIZ];
E 10
I 10
	var	FILE	*trace;
	var	bool	trubble;
	var	bool	techoin;
D 21
	var	char	tracbuf[BUFSIZ];
E 21
I 21
	var	u_char	tracbuf[BUFSIZ];
E 21
E 10
E 9
D 18
#	undef	putchar
#	undef	getchar
E 18
#else
I 2
D 3
#ifdef	VMUNIX
E 3
I 3
# ifdef	VMUNIX
E 3
#	define	BUFSIZ	1024
D 3
#else
E 3
I 3
# else
I 12
#  ifdef u370
#	define	BUFSIZ	4096
#  else
E 12
E 3
E 2
#	define	BUFSIZ	512
I 12
#  endif
E 12
I 2
D 3
#endif
E 3
I 3
# endif
E 3
E 2
#	define	NULL	0
#	define	EOF	-1
#endif

/*
 * Character constants and bits
 *
 * The editor uses the QUOTE bit as a flag to pass on with characters
 * e.g. to the putchar routine.  The editor never uses a simple char variable.
 * Only arrays of and pointers to characters are used and parameters and
D 21
 * registers are never declared character.
E 21
I 21
 * registers are never declared character. All char arrays and pointers are
 * declared as u_char to stop the @#$%^&* C from sign-extending 8-bit chars
 * when loaded into int registers.
 *
 * This is the 8-bit ex. We now handle all 8-bit codes from 1 to 0377 (0 is
 * still banned as this is a C program). We no longer abuse bit 7 as QUOTE.
 * Instead we take advantage of abovenoted fact that we don't use simple char
 * vars and use a non-char bit of int as QUOTE. We handle C1 control codes in
 * the same fashion as C0 ones have always been handled, i.e., we represent
 * them graphically and let the user edit them. The graphic representation is
 * ~@ thru ~_. (Very rarely ~@ may cause an inconvenience in vi, see the
 * comments in ex_vis.h) No actual C1 control code should ever be sent to the
 * tty unless there is a bug somewhere. 0377 is assumed to be a normal
 * printable char, i.e., a 96-character set in ISO 2022 terms.
 *
 * In order not to shock our American users the 8-bit support is controlled by
 * on/off option eightbit which is off by default, but it only controls whether
 * we allow or block 8-bit chars when reading files or taking keyboard input.
 * Internally we are always 100% 8-bit now.
E 21
 */
D 21
#define	QUOTE	0200
#define	TRIM	0177
E 21
I 21
#define	QUOTE	0400
#define	TRIM7	0177
#define	TRIM8	0377
E 21
I 18
#ifndef vms
E 18
I 13
#undef CTRL
I 18
#endif
E 18
E 13
D 19
#define	CTRL(c)	('c' & 037)
#define	NL	CTRL(j)
#define	CR	CTRL(m)
E 19
I 19
#define	CTRL(c)	(c & 037)
#define	NL	CTRL('j')
#define	CR	CTRL('m')
E 19
#define	DELETE	0177		/* See also ATTN, QUIT in ex_tune.h */
#define	ESCAPE	033
I 21
#define	isC1(c)		((c) >= 0200 && (c) <= 0237)
#define	ishichar(c)	((c) >= 0240)
E 21

/*
 * Miscellaneous random variables used in more than one place
 */
D 9
bool	aiflag;			/* Append/change/insert with autoindent */
bool	anymarks;		/* We have used '[a-z] */
D 2
short	chng;			/* Warn "No write" */
E 2
I 2
int	chng;			/* Warn "No write" */
E 2
char	*Command;
short	defwind;		/* -w# change default window size */
D 2
short	dirtcnt;		/* When >= MAXDIRT, should sync temporary */
E 2
I 2
int	dirtcnt;		/* When >= MAXDIRT, should sync temporary */
E 9
I 9
D 10
extern bool	aiflag;		/* Append/change/insert with autoindent */
extern bool	anymarks;	/* We have used '[a-z] */
extern int	chng;		/* Warn "No write" */
extern char	*Command;
extern short	defwind;	/* -w# change default window size */
extern int	dirtcnt;	/* When >= MAXDIRT, should sync temporary */
E 10
I 10
var	bool	aiflag;		/* Append/change/insert with autoindent */
var	bool	anymarks;	/* We have used '[a-z] */
var	int	chng;		/* Warn "No write" */
D 21
var	char	*Command;
E 21
I 21
var	u_char	*Command;
E 21
var	short	defwind;	/* -w# change default window size */
var	int	dirtcnt;	/* When >= MAXDIRT, should sync temporary */
E 10
E 9
I 4
#ifdef TIOCLGET
D 9
bool	dosusp;			/* Do SIGTSTP in visual when ^Z typed */
E 9
I 9
D 10
extern bool	dosusp;		/* Do SIGTSTP in visual when ^Z typed */
E 10
I 10
var	bool	dosusp;		/* Do SIGTSTP in visual when ^Z typed */
E 10
E 9
#endif
E 4
E 2
D 9
bool	edited;			/* Current file is [Edited] */
line	*endcore;		/* Last available core location */
bool	endline;		/* Last cmd mode command ended with \n */
E 9
I 9
D 10
extern bool	edited;		/* Current file is [Edited] */
extern line	*endcore;	/* Last available core location */
extern bool	endline;	/* Last cmd mode command ended with \n */
E 10
I 10
var	bool	edited;		/* Current file is [Edited] */
var	line	*endcore;	/* Last available core location */
extern	 bool	endline;	/* Last cmd mode command ended with \n */
E 10
E 9
I 2
D 18
#ifndef VMUNIX
E 18
I 18
#ifdef EXSTRINGS
E 18
E 2
D 9
short	erfile;			/* Error message file unit */
E 9
I 9
D 10
extern short	erfile;		/* Error message file unit */
E 10
I 10
var	short	erfile;		/* Error message file unit */
E 10
E 9
I 2
#endif
E 2
D 9
line	*fendcore;		/* First address in line pointer space */
char	file[FNSIZE];		/* Working file name */
char	genbuf[LBSIZE];		/* Working buffer when manipulating linebuf */
bool	hush;			/* Command line option - was given, hush up! */
char	*globp;			/* (Untyped) input string to command mode */
bool	holdcm;			/* Don't cursor address */
I 4
bool	inappend;		/* in ex command append mode */
E 4
bool	inglobal;		/* Inside g//... or v//... */
char	*initev;		/* Initial : escape for visual */
bool	inopen;			/* Inside open or visual */
char	*input;			/* Current position in cmd line input buffer */
bool	intty;			/* Input is a tty */
short	io;			/* General i/o unit (auto-closed on error!) */
short	lastc;			/* Last character ret'd from cmd input */
bool	laste;			/* Last command was an "e" (or "rec") */
char	lastmac;		/* Last macro called for ** */
char	lasttag[TAGSIZE];	/* Last argument to a tag command */
char	*linebp;		/* Used in substituting in \n */
char	linebuf[LBSIZE];	/* The primary line buffer */
bool	listf;			/* Command should run in list mode */
char	*loc1;			/* Where re began to match (in linebuf) */
char	*loc2;			/* First char after re match (") */
line	names['z'-'a'+2];	/* Mark registers a-z,' */
D 2
short	notecnt;		/* Count for notify (to visual from cmd) */
E 2
I 2
int	notecnt;		/* Count for notify (to visual from cmd) */
E 2
bool	numberf;		/* Command should run in number mode */
char	obuf[BUFSIZ];		/* Buffer for tty output */
I 4
short	oprompt;		/* Saved during source */
E 4
short	ospeed;			/* Output speed (from gtty) */
D 2
short	otchng;			/* Backup tchng to find changes in macros */
E 2
I 2
int	otchng;			/* Backup tchng to find changes in macros */
E 2
short	peekc;			/* Peek ahead character (cmd mode input) */
char	*pkill[2];		/* Trim for put with ragged (LISP) delete */
bool	pfast;			/* Have stty -nl'ed to go faster */
int	pid;			/* Process id of child */
int	ppid;			/* Process id of parent (e.g. main ex proc) */
jmp_buf	resetlab;		/* For error throws to top level (cmd mode) */
int	rpid;			/* Pid returned from wait() */
bool	ruptible;		/* Interruptible is normal state */
I 8
bool	seenprompt;		/* 1 if have gotten user input */
E 8
bool	shudclob;		/* Have a prompt to clobber (e.g. on ^D) */
int	status;			/* Status returned from wait() */
D 2
short	tchng;			/* If nonzero, then [Modified] */
E 2
I 2
int	tchng;			/* If nonzero, then [Modified] */
E 2
short	tfile;			/* Temporary file unit */
bool	vcatch;			/* Want to catch an error (open/visual) */
jmp_buf	vreslab;		/* For error throws to a visual catch */
I 8
bool	writing;		/* 1 if in middle of a file write */
E 8
D 2
short	xchng;			/* Suppresses multiple "No writes" in !cmd */
E 2
I 2
int	xchng;			/* Suppresses multiple "No writes" in !cmd */
E 9
I 9
D 10
extern line	*fendcore;	/* First address in line pointer space */
extern char	file[FNSIZE];	/* Working file name */
extern char	genbuf[LBSIZE];	/* Working buffer when manipulating linebuf */
extern bool	hush;		/* Command line option - was given, hush up! */
extern char	*globp;		/* (Untyped) input string to command mode */
extern bool	holdcm;		/* Don't cursor address */
extern bool	inappend;	/* in ex command append mode */
extern bool	inglobal;	/* Inside g//... or v//... */
extern char	*initev;	/* Initial : escape for visual */
extern bool	inopen;		/* Inside open or visual */
extern char	*input;		/* Current position in cmd line input buffer */
extern bool	intty;		/* Input is a tty */
extern short	io;		/* General i/o unit (auto-closed on error!) */
extern short	lastc;		/* Last character ret'd from cmd input */
extern bool	laste;		/* Last command was an "e" (or "rec") */
extern char	lastmac;	/* Last macro called for ** */
extern char	lasttag[TAGSIZE];	/* Last argument to a tag command */
extern char	*linebp;	/* Used in substituting in \n */
extern char	linebuf[LBSIZE];	/* The primary line buffer */
extern bool	listf;		/* Command should run in list mode */
extern char	*loc1;		/* Where re began to match (in linebuf) */
extern char	*loc2;		/* First char after re match (") */
extern line	names['z'-'a'+2];	/* Mark registers a-z,' */
extern int	notecnt;	/* Count for notify (to visual from cmd) */
extern bool	numberf;	/* Command should run in number mode */
extern char	obuf[BUFSIZ];	/* Buffer for tty output */
extern short	oprompt;	/* Saved during source */
extern short	ospeed;		/* Output speed (from gtty) */
extern int	otchng;		/* Backup tchng to find changes in macros */
extern short	peekc;		/* Peek ahead character (cmd mode input) */
extern char	*pkill[2];	/* Trim for put with ragged (LISP) delete */
extern bool	pfast;		/* Have stty -nl'ed to go faster */
extern int	pid;		/* Process id of child */
extern int	ppid;		/* Process id of parent (e.g. main ex proc) */
extern jmp_buf	resetlab;	/* For error throws to top level (cmd mode) */
extern int	rpid;		/* Pid returned from wait() */
extern bool	ruptible;	/* Interruptible is normal state */
extern bool	seenprompt;	/* 1 if have gotten user input */
extern bool	shudclob;	/* Have a prompt to clobber (e.g. on ^D) */
extern int	status;		/* Status returned from wait() */
extern int	tchng;		/* If nonzero, then [Modified] */
extern short	tfile;		/* Temporary file unit */
extern bool	vcatch;		/* Want to catch an error (open/visual) */
extern jmp_buf	vreslab;	/* For error throws to a visual catch */
extern bool	writing;	/* 1 if in middle of a file write */
extern int	xchng;		/* Suppresses multiple "No writes" in !cmd */
E 10
I 10
var	line	*fendcore;	/* First address in line pointer space */
D 21
var	char	file[FNSIZE];	/* Working file name */
D 14
var	char	genbuf[LBSIZE];	/* Working buffer when manipulating linebuf */
E 14
I 14
var	char	genbuf[MAXBSIZE]; /* Working buffer when manipulating linebuf */
E 21
I 21
var	u_char	file[FNSIZE];	/* Working file name */
var	u_char	genbuf[MAXBSIZE]; /* Working buffer when manipulating linebuf */
E 21
E 14
var	bool	hush;		/* Command line option - was given, hush up! */
D 21
var	char	*globp;		/* (Untyped) input string to command mode */
E 21
I 21
var	u_char	*globp;		/* (Untyped) input string to command mode */
E 21
var	bool	holdcm;		/* Don't cursor address */
var	bool	inappend;	/* in ex command append mode */
var	bool	inglobal;	/* Inside g//... or v//... */
D 21
var	char	*initev;	/* Initial : escape for visual */
E 21
I 21
var	u_char	*initev;	/* Initial : escape for visual */
E 21
var	bool	inopen;		/* Inside open or visual */
D 21
var	char	*input;		/* Current position in cmd line input buffer */
E 21
I 21
var	u_char	*input;		/* Current position in cmd line input buffer */
E 21
var	bool	intty;		/* Input is a tty */
var	short	io;		/* General i/o unit (auto-closed on error!) */
extern	 short	lastc;		/* Last character ret'd from cmd input */
var	bool	laste;		/* Last command was an "e" (or "rec") */
D 21
var	char	lastmac;	/* Last macro called for ** */
var	char	lasttag[TAGSIZE];	/* Last argument to a tag command */
var	char	*linebp;	/* Used in substituting in \n */
var	char	linebuf[LBSIZE];	/* The primary line buffer */
E 21
I 21
var	u_char	lastmac;	/* Last macro called for ** */
var	u_char	lasttag[TAGSIZE];	/* Last argument to a tag command */
var	u_char	*linebp;	/* Used in substituting in \n */
var	u_char	linebuf[LBSIZE];	/* The primary line buffer */
E 21
var	bool	listf;		/* Command should run in list mode */
D 21
var	char	*loc1;		/* Where re began to match (in linebuf) */
var	char	*loc2;		/* First char after re match (") */
E 21
I 21
var	u_char	*loc1;		/* Where re began to match (in linebuf) */
var	u_char	*loc2;		/* First char after re match (") */
E 21
var	line	names['z'-'a'+2];	/* Mark registers a-z,' */
var	int	notecnt;	/* Count for notify (to visual from cmd) */
var	bool	numberf;	/* Command should run in number mode */
D 21
var	char	obuf[BUFSIZ];	/* Buffer for tty output */
E 21
I 21
var	u_char	obuf[BUFSIZ];	/* Buffer for tty output */
E 21
var	short	oprompt;	/* Saved during source */
extern	short	ospeed;		/* Output speed (from gtty) */
var	int	otchng;		/* Backup tchng to find changes in macros */
var	short	peekc;		/* Peek ahead character (cmd mode input) */
D 21
var	char	*pkill[2];	/* Trim for put with ragged (LISP) delete */
E 21
I 21
var	u_char	*pkill[2];	/* Trim for put with ragged (LISP) delete */
E 21
var	bool	pfast;		/* Have stty -nl'ed to go faster */
var	int	pid;		/* Process id of child */
var	int	ppid;		/* Process id of parent (e.g. main ex proc) */
var	jmp_buf	resetlab;	/* For error throws to top level (cmd mode) */
var	int	rpid;		/* Pid returned from wait() */
var	bool	ruptible;	/* Interruptible is normal state */
var	bool	seenprompt;	/* 1 if have gotten user input */
var	bool	shudclob;	/* Have a prompt to clobber (e.g. on ^D) */
var	int	status;		/* Status returned from wait() */
var	int	tchng;		/* If nonzero, then [Modified] */
extern	short	tfile;		/* Temporary file unit */
var	bool	vcatch;		/* Want to catch an error (open/visual) */
var	jmp_buf	vreslab;	/* For error throws to a visual catch */
var	bool	writing;	/* 1 if in middle of a file write */
var	int	xchng;		/* Suppresses multiple "No writes" in !cmd */
I 14
var	long	bsize;		/* Block size for disk i/o */
E 14
E 10
E 9
E 2

/*
 * Macros
 */
#define	CP(a, b)	(ignore(strcpy(a, b)))
I 3
			/*
			 * FIXUNDO: do we want to mung undo vars?
			 * Usually yes unless in a macro or global.
			 */
#define FIXUNDO		(inopen >= 0 && (inopen || !inglobal))
E 3
#define ckaw()		{if (chng && value(AUTOWRITE)) wop(0);}
D 21
#define	copy(a,b,c)	Copy((char *) a, (char *) b, c)
E 21
I 21
#define	copy(a,b,c)	Copy((u_char *) a, (u_char *) b, c)
E 21
#define	eq(a, b)	((a) && (b) && strcmp(a, b) == 0)
#define	getexit(a)	copy(a, resetlab, sizeof (jmp_buf))
#define	lastchar()	lastc
#define	outchar(c)	(*Outchar)(c)
#define	pastwh()	(ignore(skipwh()))
#define	pline(no)	(*Pline)(no)
#define	reset()		longjmp(resetlab,1)
#define	resexit(a)	copy(resetlab, a, sizeof (jmp_buf))
#define	setexit()	setjmp(resetlab)
#define	setlastchar(c)	lastc = c
#define	ungetchar(c)	peekc = c

#define	CATCH		vcatch = 1; if (setjmp(vreslab) == 0) {
#define	ONERR		} else { vcatch = 0;
#define	ENDCATCH	} vcatch = 0;

/*
 * Environment like memory
 */
D 9
char	altfile[FNSIZE];	/* Alternate file name */
D 3
char	direct[32];		/* Temp file goes here */
char	shell[32];		/* Copied to be settable */
char	ttytype[16];		/* A long and pretty name */
E 3
I 3
char	direct[ONMSZ];		/* Temp file goes here */
char	shell[ONMSZ];		/* Copied to be settable */
char	ttytype[ONMSZ];		/* A long and pretty name */
E 3
char	uxb[UXBSIZE + 2];	/* Last !command for !! */
E 9
I 9
D 10
extern char	altfile[FNSIZE];	/* Alternate file name */
extern char	direct[ONMSZ];		/* Temp file goes here */
extern char	shell[ONMSZ];		/* Copied to be settable */
extern char	ttytype[ONMSZ];		/* A long and pretty name */
extern char	uxb[UXBSIZE + 2];	/* Last !command for !! */
E 10
I 10
D 21
var	char	altfile[FNSIZE];	/* Alternate file name */
extern	 char	direct[ONMSZ];		/* Temp file goes here */
extern	 char	shell[ONMSZ];		/* Copied to be settable */
extern	 char	ttytype[ONMSZ];		/* A long and pretty name */
var	char	uxb[UXBSIZE + 2];	/* Last !command for !! */
E 21
I 21
var	u_char	altfile[FNSIZE];	/* Alternate file name */
extern	 u_char	direct[ONMSZ];		/* Temp file goes here */
extern	 u_char	shell[ONMSZ];		/* Copied to be settable */
extern	 u_char	ttytype[ONMSZ];		/* A long and pretty name */
var	u_char	uxb[UXBSIZE + 2];	/* Last !command for !! */
E 21
E 10
E 9

/*
 * The editor data structure for accessing the current file consists
 * of an incore array of pointers into the temporary file tfile.
 * Each pointer is 15 bits (the low bit is used by global) and is
 * padded with zeroes to make an index into the temp file where the
 * actual text of the line is stored.
 *
 * To effect undo, copies of affected lines are saved after the last
 * line considered to be in the buffer, between dol and unddol.
 * During an open or visual, which uses the command mode undo between
 * dol and unddol, a copy of the entire, pre-command buffer state
 * is saved between unddol and truedol.
 */
D 9
line	*addr1;			/* First addressed line in a command */
line	*addr2;			/* Second addressed line */
line	*dol;			/* Last line in buffer */
line	*dot;			/* Current line */
line	*one;			/* First line */
line	*truedol;		/* End of all lines, including saves */
line	*unddol;		/* End of undo saved lines */
line	*zero;			/* Points to empty slot before one */
E 9
I 9
D 10
extern line	*addr1;			/* First addressed line in a command */
extern line	*addr2;			/* Second addressed line */
extern line	*dol;			/* Last line in buffer */
extern line	*dot;			/* Current line */
extern line	*one;			/* First line */
extern line	*truedol;		/* End of all lines, including saves */
extern line	*unddol;		/* End of undo saved lines */
extern line	*zero;			/* Points to empty slot before one */
E 10
I 10
var	line	*addr1;			/* First addressed line in a command */
var	line	*addr2;			/* Second addressed line */
var	line	*dol;			/* Last line in buffer */
var	line	*dot;			/* Current line */
var	line	*one;			/* First line */
var	line	*truedol;		/* End of all lines, including saves */
var	line	*unddol;		/* End of undo saved lines */
var	line	*zero;			/* Points to empty slot before one */
E 10
E 9

/*
 * Undo information
 *
 * For most commands we save lines changed by salting them away between
 * dol and unddol before they are changed (i.e. we save the descriptors
 * into the temp file tfile which is never garbage collected).  The
 * lines put here go back after unddel, and to complete the undo
 * we delete the lines [undap1,undap2).
 *
 * Undoing a move is much easier and we treat this as a special case.
 * Similarly undoing a "put" is a special case for although there
 * are lines saved between dol and unddol we don't stick these back
 * into the buffer.
 */
D 9
short	undkind;
E 9
I 9
D 10
extern short	undkind;
E 10
I 10
var	short	undkind;
E 10
E 9

D 9
line	*unddel;		/* Saved deleted lines go after here */
line	*undap1;		/* Beginning of new lines */
line	*undap2;		/* New lines end before undap2 */
line	*undadot;		/* If we saved all lines, dot reverts here */
E 9
I 9
D 10
extern line	*unddel;	/* Saved deleted lines go after here */
extern line	*undap1;	/* Beginning of new lines */
extern line	*undap2;	/* New lines end before undap2 */
extern line	*undadot;	/* If we saved all lines, dot reverts here */
E 10
I 10
var	line	*unddel;	/* Saved deleted lines go after here */
var	line	*undap1;	/* Beginning of new lines */
var	line	*undap2;	/* New lines end before undap2 */
var	line	*undadot;	/* If we saved all lines, dot reverts here */
E 10
E 9

#define	UNDCHANGE	0
#define	UNDMOVE		1
#define	UNDALL		2
#define	UNDNONE		3
#define	UNDPUT		4

I 6
D 17
D 20
#ifdef CRYPT
E 6
/*
I 4
 * Various miscellaneous flags and buffers needed by the encryption routines.
 */
#define	KSIZE   9       /* key size for encryption */
#define	KEYPROMPT       "Key: "
D 9
int	xflag;		/* True if we are in encryption mode */
int	xtflag;		/* True if the temp file is being encrypted */
int	kflag;		/* True if the key has been accepted */
char	perm[768];
char	tperm[768];
char	*key;
char	crbuf[CRSIZE];
E 9
I 9
D 10
extern int	xflag;		/* True if we are in encryption mode */
extern int	xtflag;		/* True if the temp file is being encrypted */
extern int	kflag;		/* True if the key has been accepted */
extern char	perm[768];
extern char	tperm[768];
extern char	*key;
extern char	crbuf[CRSIZE];
E 10
I 10
var	int	xflag;		/* True if we are in encryption mode */
var	int	xtflag;		/* True if the temp file is being encrypted */
var	int	kflag;		/* True if the key has been accepted */
D 21
var	char	perm[768];
var	char	tperm[768];
var	char	*key;
var	char	crbuf[CRSIZE];
E 21
I 21
var	u_char	perm[768];
var	u_char	tperm[768];
var	u_char	*key;
var	u_char	crbuf[CRSIZE];
E 21
E 10
E 9
char	*getpass();
I 6
#endif
E 20
E 17
E 6

/*
E 4
 * Function type definitions
 */
D 21
#define	NOSTR	(char *) 0
E 21
I 21
#define	NOSTR	(u_char *) 0
E 21
#define	NOLINE	(line *) 0

D 9
int	(*Outchar)();
int	(*Pline)();
int	(*Putchar)();
int	(*oldhup)();
E 9
I 9
D 10
extern int	(*Outchar)();
extern int	(*Pline)();
extern int	(*Putchar)();
extern int	(*oldhup)();
E 10
I 10
extern	int	(*Outchar)();
extern	int	(*Pline)();
D 18
extern	int	(*Putchar)();
E 18
I 18
extern	int	(*Put_char)();
E 18
var	int	(*oldhup)();
E 10
E 9
int	(*setlist())();
int	(*setnorm())();
int	(*setnorm())();
int	(*setnumb())();
line	*address();
D 21
char	*cgoto();
char	*genindent();
char	*getblock();
E 21
I 21
u_char	*cgoto();
u_char	*genindent();
u_char	*getblock();
E 21
char	*getenv();
I 18
#ifdef	vms
char	*getlog();
#endif
E 18
line	*getmark();
D 21
char	*longname();
char	*mesg();
char	*place();
char	*plural();
E 21
I 21
u_char	*longname();
u_char	*mesg();
u_char	*place();
u_char	*plural();
E 21
line	*scanfor();
line	*setin();
char	*strcat();
char	*strcpy();
D 21
char	*strend();
char	*tailpath();
E 21
I 21
u_char	*strend();
u_char	*tailpath();
E 21
char	*tgetstr();
char	*tgoto();
char	*ttyname();
line	*vback();
D 21
char	*vfindcol();
char	*vgetline();
char	*vinit();
char	*vpastwh();
char	*vskipwh();
E 21
I 21
u_char	*vfindcol();
u_char	*vgetline();
u_char	*vinit();
u_char	*vpastwh();
u_char	*vskipwh();
E 21
int	put();
int	putreg();
int	YANKreg();
D 18
int	delete();
E 18
I 18
int	ex_delete();
E 18
int	execl();
int	filter();
int	getfile();
int	getsub();
int	gettty();
int	join();
int	listchar();
off_t	lseek();
int	normchar();
int	normline();
int	numbline();
D 9
int	(*oldquit)();
E 9
I 9
D 10
extern int	(*oldquit)();
E 10
I 10
var	int	(*oldquit)();
E 10
E 9
int	onhup();
int	onintr();
I 4
int	onsusp();
E 4
int	putch();
int	shift();
int	termchar();
int	vfilter();
#ifdef CBREAK
int	vintr();
#endif
int	vputch();
int	vshftop();
int	yank();

/*
 * C doesn't have a (void) cast, so we have to fake it for lint's sake.
 */
#ifdef lint
D 21
#	define	ignore(a)	Ignore((char *) (a))
E 21
I 21
#	define	ignore(a)	Ignore((u_char *) (a))
E 21
#	define	ignorf(a)	Ignorf((int (*) ()) (a))
#else
#	define	ignore(a)	a
#	define	ignorf(a)	a
#endif
E 1
