h46133
s 00007/00001/00127
d D 5.1 85/06/05 08:44:50 dist 5 4
c Add copyright
e
s 00002/00003/00126
d D 1.4 83/08/11 22:59:05 sam 4 3
c standardize sccs keyword lines
e
s 00003/00006/00126
d D 1.3 83/06/12 16:24:33 sam 3 2
c new fstab and utmp
e
s 00013/00012/00119
d D 1.2 83/04/28 15:04:41 mckusick 2 1
c convert to work on 4.1c
e
s 00131/00000/00000
d D 1.1 80/10/13 17:30:23 root 1 0
c date and time created 80/10/13 17:30:23 by root
e
u
U
t
T
I 1
D 4
/*
 * "%W% (Berkeley) %G%"
 */
E 4
I 4
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

E 4
#define	NI	16
#define	DIRPB	(BSIZE/sizeof(struct direct))

#include <stdio.h>
#include <ctype.h>
I 3
#include <fstab.h>
#include <signal.h>
#include <utmp.h>
E 3
D 2
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/filsys.h>
#include <sys/ino.h>
#include <sys/inode.h>
#include <sys/fblk.h>
#include <sys/dir.h>
#include <utmp.h>
#include <time.h>
#include <signal.h>
#include <dumprestor.h>
#include <fstab.h>
E 2
I 2
#include "include.4.1/sys/param.h"
#include "include.4.1/sys/stat.h"
#include "include.4.1/sys/filsys.h"
#include "include.4.1/sys/ino.h"
#include "include.4.1/sys/inode.h"
#include "include.4.1/sys/fblk.h"
#include "include.4.1/sys/dir.h"
D 3
#include "include.4.1/utmp.h"
E 3
#include "include.4.1/time.h"
D 3
#include "include.4.1/signal.h"
E 3
#include "include.4.1/dumprestor.h"
D 3
#include "include.4.1/fstab.h"
E 3
E 2

#define	MWORD(m,i)	(m[(unsigned)(i-1)/MLEN])
#define	MBIT(i)		(1<<((unsigned)(i-1)%MLEN))
#define	BIS(i,w)	(MWORD(w,i) |=  MBIT(i))
#define	BIC(i,w)	(MWORD(w,i) &= ~MBIT(i))
#define	BIT(i,w)	(MWORD(w,i) & MBIT(i))

short	clrmap[MSIZ];
short	dirmap[MSIZ];
short	nodmap[MSIZ];

/*
 *	All calculations done in 0.1" units!
 */

char	*disk;		/* name of the disk file */
char	*tape;		/* name of the tape file */
I 2
char	pipeout;	/* true => output to standard output */
E 2
char	*increm;	/* name of the file containing incremental information*/
char	incno;		/* increment number */
int	uflag;		/* update flag */
int	fi;		/* disk file descriptor */
int	to;		/* tape file descriptor */
ino_t	ino;		/* current inumber; used globally */
int	nsubdir;
int	newtape;	/* new tape flag */
int	nadded;		/* number of added sub directories */
int	dadded;		/* directory added flag */
int	density;	/* density in 0.1" units */
long	tsize;		/* tape size in 0.1" units */
long	esize;		/* estimated tape size, blocks */
long	asize;		/* number of 0.1" units written on current tape */
int	etapes;		/* estimated number of tapes */

int	notify;		/* notify operator flag */
int	blockswritten;	/* number of blocks written on current tape */
int	tapeno;		/* current tape number */
time_t	tstart_writing;	/* when started writing the first tape block */
char	*processname;

char	*ctime();
char	*prdate();
long	atol();
int	mark();
int	add();
int	dump();
int	tapsrec();
int	dmpspc();
int	dsrch();
int	nullf();
char	*getsuffix();
char	*rawname();

int	interrupt();		/* in case operator bangs on console */

#define	HOUR	(60L*60L)
#define	DAY	(24L*HOUR)
#define	YEAR	(365L*DAY)

/*
 *	Exit status codes
 */
#define	X_FINOK		1	/* normal exit */
#define	X_REWRITE	2	/* restart writing from the check point */
#define	X_ABORT		3	/* abort all of dump; don't attempt checkpointing*/

#ifdef DEBUG
#define	OINCREM	"./ddate"		/*old format incremental info*/
#define	NINCREM	"./dumpdates"		/*new format incremental info*/
#else not DEBUG
#define	OINCREM	"/etc/ddate"		/*old format incremental info*/
#define	NINCREM	"/etc/dumpdates"	/*new format incremental info*/
#endif

#define	TAPE	"/dev/rmt8"		/* default tape device */
#define	DISK	"/dev/rrp1g"		/* default disk */
#define	OPGRENT	"operator"		/* group entry to notify */
#define DIALUP	"ttyd"			/* prefix for dialups */

D 3
#define	MAXFSTAB		32
struct	fstab	fstab[MAXFSTAB];
E 3
struct	fstab	*fstabsearch();	/* search in fs_file and fs_spec */
D 3
int	nfstab;
E 3

/*
 *	The contents of the file NINCREM is maintained both on
 *	a linked list, and then (eventually) arrayified.
 */
struct	itime{
	struct	idates	it_value;
	struct	itime	*it_next;
};
struct	itime	*ithead;	/* head of the list version */
int	nidates;		/* number of records (might be zero) */
int	idates_in;		/* we have read the increment file */
struct	idates	**idatev;	/* the arrayfied version */
#define	ITITERATE(i, ip) for (i = 0,ip = idatev[0]; i < nidates; i++, ip = idatev[i])

/*
 *	We catch these interrupts
 */
int	sighup();
int	sigquit();
int	sigill();
int	sigtrap();
int	sigfpe();
int	sigkill();
int	sigbus();
int	sigsegv();
int	sigsys();
int	sigalrm();
int	sigterm();
E 1
