h05370
s 00010/00005/00133
d D 5.4 88/06/29 20:19:25 bostic 19 18
c install approved copyright notice
e
s 00008/00002/00130
d D 5.3 88/02/01 11:34:37 bostic 18 17
c add new Berkeley headers
e
s 00001/00000/00131
d D 5.2 86/03/20 15:46:38 sklower 17 16
c 1.) Don't abort when chown fails on suns
c 2.) Don't abort when uid's not in pw file, just use number
c 3.) Make effort to link when renaming targets.
e
s 00007/00001/00124
d D 5.1 85/06/06 08:55:39 dist 16 15
c Add copyright
e
s 00001/00004/00124
d D 4.15 85/02/04 14:33:56 ralph 15 14
c use yyerror instead of quitting on first error.
e
s 00013/00002/00115
d D 4.14 84/06/28 11:44:44 ralph 14 13
c handle symbolic and hard links.
e
s 00003/00003/00114
d D 4.13 84/05/03 11:40:53 ralph 13 12
c added regular expressions for exception pattern matching.
e
s 00010/00010/00107
d D 4.12 84/04/06 15:48:13 ralph 12 11
c added labels for partial updates.
e
s 00000/00001/00117
d D 4.11 84/02/24 13:55:06 ralph 11 10
c get rid of unused global reference.
e
s 00032/00014/00086
d D 4.10 84/02/09 16:06:15 ralph 10 9
c read entire distfile and sort entries by host.
e
s 00006/00001/00094
d D 4.9 83/11/29 16:35:51 ralph 9 8
c added version number.
e
s 00014/00005/00081
d D 4.8 83/11/29 15:59:53 ralph 8 7
c bug fixes and added `special' command.
e
s 00003/00002/00083
d D 4.7 83/11/01 14:29:16 ralph 7 6
c fixes for -r and -w.
e
s 00003/00002/00082
d D 4.6 83/10/26 11:41:48 ralph 6 5
c added -b option for binary compare. Fixed -r w/ except.
e
s 00024/00020/00060
d D 4.5 83/10/20 12:14:28 ralph 5 4
c added -r option to remove extra files.
e
s 00001/00002/00079
d D 4.4 83/10/12 16:38:29 ralph 4 3
c fixed install flags, file comparisons, mail addresses, added -c.
e
s 00012/00006/00069
d D 4.3 83/10/10 16:14:55 ralph 3 2
c stable version that works.
e
s 00022/00009/00053
d D 4.2 83/09/27 14:38:09 ralph 2 1
c First stable version.
e
s 00062/00000/00000
d D 4.1 83/09/07 13:16:46 ralph 1 0
c date and time created 83/09/07 13:16:46 by ralph
e
u
U
t
T
I 1
D 16
/*	%M%	%I%	%E%	*/
E 16
I 16
/*
 * Copyright (c) 1983 Regents of the University of California.
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
E 18
 *
 *	%W% (Berkeley) %G%
 */
E 16

#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
D 15
#include <signal.h>
#include <sys/types.h>
E 15
I 15
#include <sys/param.h>
E 15
#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <netinet/in.h>

D 3
#define	MAILCMD		"/usr/lib/sendmail -i -t"
E 3
I 3
D 9
#define	MAILCMD		"/usr/lib/sendmail -oi -t"
E 9
I 9
/*
D 10
 * The version number should be changed whenever the protocols change.
E 10
I 10
 * The version number should be changed whenever the protocol changes.
E 10
 */
D 14
#define VERSION	 2
E 14
I 14
#define VERSION	 3
E 14

#define	MAILCMD	 "/usr/lib/sendmail -oi -t"
E 9
E 3

	/* defines for yacc */
D 5
#define EQUAL 1
D 2
#define ARROW 2
#define LP 3
#define RP 4
#define NAME 5
#define INSTALL 6
#define VERIFY 7
#define NOTIFY 8
#define EXCEPT 9
E 2
I 2
#define LP 2
#define RP 3
#define ARROW 4
#define DCOLON 5
#define NAME 6
#define INSTALL 7
D 3
#define VERIFY 8
#define NOTIFY 9
#define EXCEPT 10
E 2

E 3
I 3
#define NOTIFY 8
#define EXCEPT 9
#define OPTION 10
E 3
I 2
#define VAR 11
E 5
I 5
#define EQUAL	1
#define LP	2
#define RP	3
#define SM	4
#define ARROW	5
D 12
#define DCOLON	6
#define NAME	7
D 8
#define INSTALL	8
#define NOTIFY	9
#define EXCEPT	10
#define OPTION	11
#define VAR	12
E 8
I 8
#define STRING	8
#define INSTALL	9
#define NOTIFY	10
#define EXCEPT	11
#define SPECIAL	12
#define OPTION	13
E 12
I 12
#define COLON	6
#define DCOLON	7
#define NAME	8
#define STRING	9
#define INSTALL	10
#define NOTIFY	11
#define EXCEPT	12
D 13
#define SPECIAL	13
#define OPTION	14
E 13
I 13
#define PATTERN	13
#define SPECIAL	14
#define OPTION	15
E 13
E 12
D 10
#define VAR	14
E 10
E 8
E 5

	/* lexical definitions */
#define	QUOTE 	0200		/* used internally for quoted characters */
#define	TRIM	0177		/* Mask to strip quote bit */

E 2
	/* table sizes */
D 5
#define HASHSIZE 1021
#define INMAX 3500
I 2
#define NCARGS 10240
#define GAVSIZ NCARGS / 6
#define NSTAMPS 15
E 5
I 5
#define HASHSIZE	1021
#define INMAX	3500
D 15
#define NCARGS	10240
#define GAVSIZ	NCARGS / 6
E 15
D 10
#define NSTAMPS	15
E 10
E 5
E 2

I 3
	/* option flags */
D 5
#define VERIFY 1
#define WHOLE 2
#define YOUNGER 4
#define STRIP 8
E 5
I 5
#define VERIFY	0x1
#define WHOLE	0x2
#define YOUNGER	0x4
D 6
#define STRIP	0x8
#define REMOVE	0x10
E 6
I 6
#define COMPARE	0x8
D 7
#define STRIP	0x10
#define REMOVE	0x20
E 7
I 7
#define REMOVE	0x10
I 14
#define FOLLOW	0x20
#define IGNLNKS	0x40
E 14
E 7
E 6

I 8
	/* expand type definitions */
#define E_VARS	0x1
#define E_SHELL	0x2
#define E_TILDE	0x4
#define E_ALL	0x7

I 10
	/* actions for lookup() */
#define LOOKUP	0
#define INSERT	1
#define REPLACE	2

E 10
E 8
#define ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
E 5
E 3
I 2

E 2
#define ALLOC(x) (struct x *) malloc(sizeof(struct x))

D 10
struct block {
D 3
	int	b_type;
E 3
I 3
	short	b_type;
	short	b_options;
E 3
	char	*b_name;
	struct	block *b_next;
	struct	block *b_args;
E 10
I 10
struct namelist {	/* for making lists of strings */
	char	*n_name;
	struct	namelist *n_next;
E 10
};

I 10
struct subcmd {
	short	sc_type;	/* type - INSTALL,NOTIFY,EXCEPT,SPECIAL */
	short	sc_options;
	char	*sc_name;
	struct	namelist *sc_args;
	struct	subcmd *sc_next;
};

struct cmd {
	int	c_type;		/* type - ARROW,DCOLON */
	char	*c_name;	/* hostname or time stamp file name */
I 12
	char	*c_label;	/* label for partial update */
E 12
	struct	namelist *c_files;
	struct	subcmd *c_cmds;
	struct	cmd *c_next;
};
D 14
	
E 14
I 14

struct linkbuf {
	ino_t	inum;
	dev_t	devnum;
	int	count;
	char	pathname[BUFSIZ];
I 17
	char	target[BUFSIZ];
E 17
	struct	linkbuf *nextp;
};

E 14
E 10
extern int debug;		/* debugging flag */
extern int nflag;		/* NOP flag, don't execute commands */
extern int qflag;		/* Quiet. don't print messages */
D 4
extern int vflag;		/* verify only */
extern int yflag;		/* update iff remote younger than master */
E 4
I 4
extern int options;		/* global options */
E 4

D 10
extern int errs;		/* number of errors seen */
E 10
I 10
extern int nerrs;		/* number of errors seen */
E 10
extern int rem;			/* remote file descriptor */
extern int iamremote;		/* acting as remote server */
D 12
extern int filec;		/* number of files to update */
extern char **filev;		/* list of files/directories to update */
E 12
D 2
extern char *tmpfile;		/* file name for logging changes */
E 2
I 2
extern char tmpfile[];		/* file name for logging changes */
I 14
extern struct linkbuf *ihead;	/* list of files with more than one link */
E 14
I 7
extern struct passwd *pw;	/* pointer to static area used by getpwent */
extern struct group *gr;	/* pointer to static area used by getgrent */
E 7
E 2
extern char host[];		/* host name of master copy */
D 11
extern char *rhost;		/* host name of remote being updated */
E 11
D 10
extern struct block *except;	/* list of files to exclude */
E 10
I 10
D 13
extern struct namelist *except;	/* list of files to exclude */
E 13
E 10
extern char buf[];		/* general purpose buffer */
extern int errno;		/* system error number */
extern char *sys_errlist[];

D 10
struct block *lookup();
I 2
struct block *makeblock();
E 2
struct block *expand();
E 10
I 10
char *makestr();
struct namelist *makenl();
struct subcmd *makesubcmd();
struct namelist *lookup();
struct namelist *expand();
E 10
I 8
char *exptilde();
E 8
I 3
char *malloc();
E 3
char *rindex();
I 2
char *index();
E 2
E 1
