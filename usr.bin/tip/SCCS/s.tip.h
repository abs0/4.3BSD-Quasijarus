h44059
s 00009/00004/00240
d D 5.3 86/10/19 23:14:53 sam 15 14
c correct byte ordering problem for tahoe
e
s 00002/00000/00242
d D 5.2 86/01/13 19:28:09 karels 14 13
c use setreuid to retain setuid uid for cleanup of lock files
e
s 00007/00001/00235
d D 5.1 85/04/30 12:33:14 dist 13 12
c Add copyright
e
s 00040/00085/00196
d D 4.11 83/06/25 01:14:41 sam 12 11
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00033/00002/00248
d D 4.10 83/06/15 14:00:37 ralph 11 9
c changes for local info, parity, vadic dialers
e
s 00000/00000/00250
d R 4.10 83/06/15 13:53:55 ralph 10 9
c changes for local info, parity, vadic auto dialers
e
s 00002/00000/00248
d D 4.9 83/05/17 11:50:11 root 9 8
c Now turns off local characters (suspend, etc)
e
s 00000/00001/00248
d D 4.8 82/12/24 18:49:08 sam 8 7
c unneeded anymore
e
s 00002/00002/00247
d D 4.7 82/07/29 14:38:48 shannon 7 6
c 68000 fixes
e
s 00001/00003/00248
d D 4.6 81/12/16 17:25:01 shannon 6 5
c new cu interface and phone numbers for tip
e
s 00001/00000/00250
d D 4.5 81/11/20 18:17:37 sam 5 4
c added cumode flag
e
s 00001/00000/00249
d D 4.4 81/07/11 14:05:20 sam 4 3
c cleanup after "hw" attribute addition (instead of shannon mods)
e
s 00001/00000/00248
d D 4.3 81/06/16 16:43:57 sam 3 2
c lots of patches to satisfy the DN-11's wants
e
s 00002/00000/00246
d D 4.2 81/06/02 10:00:16 sam 2 1
c added echocheck mode for ftp (from decvax!shannon)
e
s 00246/00000/00000
d D 4.1 81/05/09 16:45:24 root 1 0
c date and time created 81/05/09 16:45:24 by root
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 13
I 12

E 12
/*
 * tip - terminal interface program
D 12
 *
 * Samuel J. Leffler
E 12
 */

I 12
#include <sys/types.h>
#include <sys/file.h>

E 12
#include <sgtty.h>
#include <signal.h>
#include <stdio.h>
#include <pwd.h>
D 12
#include <sys/types.h>
E 12
I 6
#include <ctype.h>
I 12
#include <setjmp.h>
#include <errno.h>
E 12
E 6

/*
 * Remote host attributes
 */
char	*DV;			/* UNIX device(s) to open */
char	*EL;			/* chars marking an EOL */
char	*CM;			/* initial connection message */
char	*IE;			/* EOT to expect on input */
char	*OE;			/* EOT to send to complete FT */
char	*CU;			/* call unit if making a phone call */
char	*AT;			/* acu type */
char	*PN;			/* phone number(s) */
I 11
char	*DI;			/* disconnect string */
char	*PA;			/* parity to be generated */
E 11

char	*PH;			/* phone number file */
char	*RM;			/* remote file name */
char	*HO;			/* host name */

int	BR;			/* line speed for conversation */
int	FS;			/* frame size for transfers */

char	DU;			/* this host is dialed up */
I 3
char	HW;			/* this device is hardwired, see hunt.c */
I 11
char	*ES;			/* escape character */
char	*EX;			/* exceptions */
char	*FO;			/* force (literal next) char*/
char	*RC;			/* raise character */
char	*RE;			/* script record file */
char	*PR;			/* remote prompt */
int	DL;			/* line delay for file transfers to remote */
int	CL;			/* char delay for file transfers to remote */
int	ET;			/* echocheck timeout */
char	HD;			/* this host is half duplex - do local echo */
E 11
E 3

/*
 * String value table
 */
typedef
	struct {
		char	*v_name;	/* whose name is it */
		char	v_type;		/* for interpreting set's */
		char	v_access;	/* protection of touchy ones */
		char	*v_abrev;	/* possible abreviation */
		char	*v_value;	/* casted to a union later */
	}
	value_t;

#define STRING	01		/* string valued */
#define BOOL	02		/* true-false value */
#define NUMBER	04		/* numeric value */
#define CHAR	010		/* character value */

#define WRITE	01		/* write access to variable */
#define	READ	02		/* read access */

#define CHANGED	01		/* low bit is used to show modification */
#define PUBLIC	1		/* public access rights */
#define PRIVATE	03		/* private to definer */
#define ROOT	05		/* root defined */

#define	TRUE	1
#define FALSE	0

#define ENVIRON	020		/* initialize out of the environment */
#define IREMOTE	040		/* initialize out of remote structure */
#define INIT	0100		/* static data space used for initialization */
#define TMASK	017

/*
 * Definition of ACU line description
 */
typedef
	struct {
		char	*acu_name;
		int	(*acu_dialer)();
		int	(*acu_disconnect)();
		int	(*acu_abort)();
	}
	acu_t;

#define	equal(a, b)	(strcmp(a,b)==0)/* A nice function to string compare */
D 6
#define islower(c)	((c)>='a'&&(c)<='z')
#define toupper(c)	(c)-=('a'-'A')
#define isnum(c)	((c)>='0'&&(c)<= '9')
E 6
D 8
#define CTRL(c)		('c'&037)
E 8

/*
 * variable manipulation stuff --
 *   if we defined the value entry in value_t, then we couldn't
 *   initialize it in vars.c, so we cast it as needed to keep lint
 *   happy.
 */
typedef
	union {
		int	zz_number;
D 7
		short	zz_boolean;
		char	zz_character;
E 7
I 7
D 11
		int	zz_boolean;
		int	zz_character;
E 11
I 11
D 15
		short	zz_boolean;
		char	zz_character;
E 15
I 15
		short	zz_boolean[2];
		char	zz_character[4];
E 15
E 11
E 7
		int	*zz_address;
	}
	zzhack;

#define value(v)	vtable[v].v_value

D 15
#define boolean(v)	((((zzhack *)(&(v))))->zz_boolean)
E 15
#define number(v)	((((zzhack *)(&(v))))->zz_number)
D 15
#define character(v)	((((zzhack *)(&(v))))->zz_character)
E 15
I 15
#ifdef vax
#define boolean(v)	((((zzhack *)(&(v))))->zz_boolean[0])
#define character(v)	((((zzhack *)(&(v))))->zz_character[0])
#else
#define boolean(v)	((((zzhack *)(&(v))))->zz_boolean[1])
#define character(v)	((((zzhack *)(&(v))))->zz_character[3])
#endif
E 15
#define address(v)	((((zzhack *)(&(v))))->zz_address)

/*
 * Escape command table definitions --
 *   lookup in this table is performed when ``escapec'' is recognized
 *   at the begining of a line (as defined by the eolmarks variable).
*/

typedef
	struct {
		char	e_char;		/* char to match on */
		char	e_flags;	/* experimental, priviledged */
		char	*e_help;	/* help string */
		int 	(*e_func)();	/* command */
	}
	esctable_t;

#define NORM	00		/* normal protection, execute anyone */
#define EXP	01		/* experimental, mark it with a `*' on help */
#define PRIV	02		/* priviledged, root execute only */

extern int	vflag;		/* verbose during reading of .tiprc file */
extern value_t	vtable[];	/* variable table */

#ifndef ACULOG
#define logent(a, b, c, d)
#define loginit()
#endif

/*
 * Definition of indices into variable table so
 *  value(DEFINE) turns into a static address.
 */

#define BEAUTIFY	0
#define BAUDRATE	1
#define DIALTIMEOUT	2
#define EOFREAD		3
#define EOFWRITE	4
#define EOL		5
#define ESCAPE		6
#define EXCEPTIONS	7
#define FORCE		8
#define FRAMESIZE	9
#define HOST		10
D 12
#if ACULOG
#define LOCK		11
#define LOG		12
#define PHONES		13
#define PROMPT		14
#define RAISE		15
#define RAISECHAR	16
#define RECORD		17
#define REMOTE		18
#define SCRIPT		19
#define TABEXPAND	20
#define VERBOSE		21
#define SHELL		22
#define HOME		23
I 2
#define ECHOCHECK	24
I 11
#define DISCONNECT	25
#define TAND		26
#define LDELAY		27
#define CDELAY		28
#define ETIMEOUT	29
#define RAWFTP		30
#define HALFDUPLEX	31
#define	LECHO		32
#define	PARITY		33
E 11
E 2
#else
#define PHONES		11
#define PROMPT		12
#define RAISE		13
#define RAISECHAR	14
#define RECORD		15
#define REMOTE		16
#define SCRIPT		17
#define TABEXPAND	18
#define VERBOSE		19
#define SHELL		20
#define HOME		21
I 2
#define ECHOCHECK	22
I 11
#define DISCONNECT	23
#define TAND		24
#define LDELAY		25
#define CDELAY		26
#define ETIMEOUT	27
#define RAWFTP		28
#define HALFDUPLEX	29
#define	LECHO		30
#define	PARITY		31
E 11
E 2
#endif
E 12
I 12
#define LOG		11
#define PHONES		12
#define PROMPT		13
#define RAISE		14
#define RAISECHAR	15
#define RECORD		16
#define REMOTE		17
#define SCRIPT		18
#define TABEXPAND	19
#define VERBOSE		20
#define SHELL		21
#define HOME		22
#define ECHOCHECK	23
#define DISCONNECT	24
#define TAND		25
#define LDELAY		26
#define CDELAY		27
#define ETIMEOUT	28
#define RAWFTP		29
#define HALFDUPLEX	30
#define	LECHO		31
#define	PARITY		32
E 12

#define NOVAL	((value_t *)NULL)
#define NOACU	((acu_t *)NULL)
#define NOSTR	((char *)NULL)
#define NOFILE	((FILE *)NULL)
#define NOPWD	((struct passwd *)0)

struct sgttyb	arg;		/* current mode of local terminal */
struct sgttyb	defarg;		/* initial mode of local terminal */
struct tchars	tchars;		/* current state of terminal */
struct tchars	defchars;	/* initial state of terminal */
I 9
struct ltchars	ltchars;	/* current local characters of terminal */
struct ltchars	deflchars;	/* initial local characters of terminal */
E 9

FILE	*fscript;		/* FILE for scripting */

int	fildes[2];		/* file transfer synchronization channel */
int	repdes[2];		/* read process sychronization channel */
int	FD;			/* open file descriptor to remote host */
I 11
int	AC;			/* open file descriptor to dialer (v831 only) */
E 11
int	vflag;			/* print .tiprc initialization sequence */
int	sfd;			/* for ~< operation */
int	pid;			/* pid of tipout */
I 14
uid_t	uid, euid;		/* real and effective user id's */
gid_t	gid, egid;		/* real and effective group id's */
E 14
int	stop;			/* stop transfer session flag */
int	quit;			/* same; but on other end */
int	intflag;		/* recognized interrupt */
int	stoprompt;		/* for interrupting a prompt session */
int	timedout;		/* ~> transfer timedout */
I 5
int	cumode;			/* simulating the "cu" program */
E 5

char	fname[80];		/* file name buffer for ~< */
char	copyname[80];		/* file name buffer for ~> */
char	ccc;			/* synchronization character */
char	ch;			/* for tipout */
char	*uucplock;		/* name of lock file for uucp's */

D 12
/*
 * From <sys/tty.h> (PDP-11 V7) ... it's put in here to avoid lots
 *  of naming conflicts with stuff we have to pull in to use tty.h
 */
#ifndef TIOCFLUSH
#	define TIOCFLUSH	(('t'<<8)|16)
#endif

/*
 * On PDP-11 V7 systems with Rand's capacity call use this
 *  stuff, otherwise <assuming it's a VM system> use FIONREAD
 */
#ifndef FIONREAD
#define	FIOCAPACITY	(('f'<<8)|3)

struct capacity {
	off_t	cp_nbytes;
	char	cp_eof;
};
#endif

#ifdef VMUNIX
E 12
int	odisc;				/* initial tty line discipline */
I 4
D 12
extern int disc;			/* current tty discpline */
E 4
#endif
E 12
I 12
extern	int disc;			/* current tty discpline */
E 12

D 12
extern char		*ctrl();
extern char		*ctime();
extern long		time();
extern struct passwd 	*getpwuid();
extern char		*getlogin();
extern char		*vinterp();
extern char		*getenv();
extern char		*rindex();
extern char		*index();
extern char		*malloc();
extern char		*connect();
E 12
I 12
extern	char *ctrl();
extern	char *ctime();
extern	long time();
extern	struct passwd *getpwuid();
extern	char *getlogin();
extern	char *vinterp();
extern	char *getenv();
extern	char *rindex();
extern	char *index();
extern	char *malloc();
extern	char *connect();
E 12
E 1
