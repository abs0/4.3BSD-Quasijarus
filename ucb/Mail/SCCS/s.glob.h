h38283
s 00008/00002/00084
d D 5.3 88/02/18 17:03:57 bostic 20 19
c written by Kurt Shoens; added Berkeley specific header
e
s 00002/00001/00084
d D 5.2 87/05/18 12:28:29 edward 19 18
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00007/00001/00078
d D 5.1 85/06/06 10:47:37 dist 18 17
c Add copyright
e
s 00002/00000/00077
d D 2.11 85/04/18 18:20:06 serge 17 16
c modified to work with new stdio; added retain command; fixed several bugs
e
s 00002/00004/00075
d D 2.10 83/08/11 22:16:11 sam 16 15
c standardize sccs keyword lines
e
s 00002/00001/00077
d D 2.9 83/01/29 18:48:32 leres 15 14
c Added pointer for local host names
e
s 00001/00000/00077
d D 2.8 82/07/28 23:17:01 kurt 14 13
c added ignored header hash table 
c 
e
s 00001/00002/00076
d D 2.7 82/06/24 23:55:48 kurt 13 12
c Made "mailname" an array rather than going through the subterfuge 
c of making mailname usually point to mailspace since you used to be able 
c to core dump mail using the old scheme... 
c 
e
s 00001/00000/00077
d D 2.6 82/02/13 21:24:01 kurt 12 11
c added global "loading" to indicate that reading of user's 
c .mailrc or /usr/lib/Mail.rc is in progress. 
c 
e
s 00001/00000/00076
d D 2.5 81/12/10 12:55:50 kurt 11 10
c added global variable baud -- output speed rate 
c 
e
s 00001/00000/00075
d D 2.4 81/09/16 14:36:21 kurt 10 9
c added global altnames -- list of alternative names for this user 
c 
e
s 00001/00001/00074
d D 2.3 81/08/12 17:21:59 kurt 9 8
c changed size of exponential string table so that it can make a string large
c enough to fill all of memory
e
s 00001/00000/00074
d D 2.2 81/07/20 17:09:00 kurt 8 7
c added global Tflag which is set to the file name given after -T:
c on exit from Mail, the article-id's of all messages read or deleted will
c be recorded here
e
s 00000/00000/00074
d D 2.1 81/07/01 11:11:19 kurt 7 6
c Release to Heidi Stettner
e
s 00001/00000/00073
d D 1.6 81/02/06 09:41:29 kas 6 5
c added noheader flag to suppress initial header print
e
s 00001/00000/00072
d D 1.5 80/10/18 18:15:34 kas 5 4
c added global variable cond -- current state of conditionals
e
s 00001/00001/00071
d D 1.4 80/10/17 00:41:44 kas 4 3
c max size of user names changed to PATHSIZE
e
s 00001/00000/00071
d D 1.3 80/10/16 16:18:09 kas 3 2
c added global flag shudann which causes lex() to print out
c the headers the next time it is convenient
e
s 00002/00000/00069
d D 1.2 80/10/10 11:59:59 kas 2 1
c added readonly flag; added pipef so that stop() can be sure
c to close the popen opened by type() with pclose instead of fclose()
e
s 00069/00000/00000
d D 1.1 80/10/08 09:53:39 kas 1 0
c date and time created 80/10/08 09:53:39 by kas
e
u
U
f b 
t
T
I 16
D 18
/*	%M%	%I%	%E%	*/
E 18
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
 *
 *	%W% (Berkeley) %G%
 */
E 18

E 16
I 1
/*
 * A bunch of global variable declarations lie herein.
 * def.h must be included first.
D 16
 */

/*
D 15
 * Sccs Id = "%W% %G%";
E 15
I 15
 * Sccs Id = "%W% %G%;
E 16
E 15
 */

int	msgCount;			/* Count of messages read in */
int	mypid;				/* Current process id */
int	rcvmode;			/* True if receiving mail */
int	sawcom;				/* Set after first command */
int	hflag;				/* Sequence number for network -h */
char	*rflag;				/* -r address for network */
I 8
char	*Tflag;				/* -T temp file for netnews */
E 8
char	nosrc;				/* Don't source /usr/lib/Mail.rc */
I 6
char	noheader;			/* Suprress initial header listing */
E 6
int	selfsent;			/* User sent self something */
int	senderr;			/* An error while checking */
int	edit;				/* Indicates editing a file */
I 2
int	readonly;			/* Will be unable to rewrite file */
E 2
int	noreset;			/* String resets suspended */
int	sourcing;			/* Currently reading variant file */
I 12
int	loading;			/* Loading user definitions */
E 12
I 3
D 19
int	shudann;			/* Print headers when possible */
E 19
I 5
int	cond;				/* Current state of conditional exc. */
E 5
E 3
FILE	*itf;				/* Input temp file buffer */
FILE	*otf;				/* Output temp file buffer */
I 2
FILE	*pipef;				/* Pipe file we have opened */
E 2
int	image;				/* File descriptor for image of msg */
FILE	*input;				/* Current command input file */
char	*editfile;			/* Name of file being edited */
char	*sflag;				/* Subject given from non tty */
int	outtty;				/* True if standard output a tty */
int	intty;				/* True if standard input a tty */
I 11
int	baud;				/* Output baud rate */
E 11
char	mbox[PATHSIZE];			/* Name of mailbox file */
D 13
char	*mailname;			/* Name of system mailbox */
char	mailspace[PATHSIZE];		/* Space norm alloc'd for name */
E 13
I 13
char	mailname[PATHSIZE];		/* Name of system mailbox */
E 13
int	uid;				/* The invoker's user id */
char	mailrc[PATHSIZE];		/* Name of startup file */
char	deadletter[PATHSIZE];		/* Name of #/dead.letter */
char	homedir[PATHSIZE];		/* Path name of home directory */
D 4
char	myname[9];			/* My login id */
E 4
I 4
char	myname[PATHSIZE];		/* My login id */
E 4
off_t	mailsize;			/* Size of system mailbox */
int	lexnumber;			/* Number of TNUMBER from scan() */
char	lexstring[STRINGLEN];		/* String from TSTRING, scan() */
int	regretp;			/* Pointer to TOS of regret tokens */
int	regretstack[REGDEP];		/* Stack of regretted tokens */
char	*stringstack[REGDEP];		/* Stack of regretted strings */
int	numberstack[REGDEP];		/* Stack of regretted numbers */
struct	message	*dot;			/* Pointer to current message */
struct	message	*message;		/* The actual message structure */
struct	var	*variables[HSHSIZE];	/* Pointer to active var list */
struct	grouphead	*groups[HSHSIZE];/* Pointer to active groups */
I 14
struct	ignore		*ignore[HSHSIZE];/* Pointer to ignored fields */
I 17
struct	ignore		*retain[HSHSIZE];/* Pointer to retained fields */
int	nretained;			/* Number of retained fields */
E 17
E 14
I 10
char	**altnames;			/* List of alternate names for user */
I 15
char	**localnames;			/* List of aliases for our local host */
E 15
E 10
int	debug;				/* Debug flag set */
int	rmail;				/* Being called as rmail */
I 19
int	screenwidth;			/* Screen width, or best guess */
int	screenheight;			/* Screen height, or best guess */
E 19

#include <setjmp.h>

jmp_buf	srbuf;


/*
 * The pointers for the string allocation routines,
 * there are NSPACE independent areas.
 * The first holds STRINGSIZE bytes, the next
 * twice as much, and so on.
 */

D 9
#define	NSPACE	8			/* Total number of string spaces */
E 9
I 9
#define	NSPACE	25			/* Total number of string spaces */
E 9
struct strings {
	char	*s_topFree;		/* Beginning of this area */
	char	*s_nextFree;		/* Next alloctable place here */
	unsigned s_nleft;		/* Number of bytes left here */
} stringdope[NSPACE];
E 1
