h65406
s 00001/00000/00140
d D 5.4 87/02/23 17:57:06 mckusick 17 16
c generalize dev_bsize
e
s 00001/00001/00139
d D 5.3 86/05/23 10:57:02 mckusick 16 15
c use standard exit codes
e
s 00001/00001/00139
d D 5.2 85/06/18 21:06:52 mckusick 15 14
c dumpretore.h moves into protocols
e
s 00007/00001/00133
d D 5.1 85/06/05 08:49:58 dist 14 13
c Add copyright
e
s 00001/00000/00133
d D 1.13 84/10/05 15:56:20 mckusick 13 12
c maintain consistent dump tapes on active systems (decvax!watmath!srradia)
e
s 00003/00004/00130
d D 1.12 83/07/01 23:55:27 sam 12 11
c include fix
e
s 00001/00001/00133
d D 1.11 83/07/01 03:06:32 sam 11 10
c include fix
e
s 00003/00006/00131
d D 1.10 83/06/15 15:06:12 sam 10 9
c from kirk; handle locking of dumpdates data base
e
s 00000/00004/00137
d D 1.9 83/06/12 16:15:13 sam 9 8
c new fstab format
e
s 00001/00000/00140
d D 1.8 83/05/08 19:11:14 mckusick 8 7
c add ability to dump to standard output
e
s 00006/00000/00134
d D 1.7 82/10/07 19:28:11 mckusick 7 6
c move struct itime out of dumprestor.h into dump.h
e
s 00005/00005/00129
d D 1.6 82/05/07 15:27:42 sam 6 5
c old stuff
e
s 00000/00003/00134
d D 1.5 82/02/23 12:56:42 mckusic 5 4
c convert to new directory format
e
s 00013/00007/00124
d D 1.4 82/01/05 01:37:05 mckusic 4 3
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00001/00001/00130
d D 1.3 81/11/07 14:53:02 mckusic 3 2
c dump to "standard" (ie 1K file system) dump tapes
e
s 00007/00007/00124
d D 1.2 81/10/31 18:29:53 mckusic 2 1
c 8K only dump/restor
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
D 12
/*
 * "%W% (Berkeley) %G%"
 */
E 12
I 12
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 14

E 12
D 4
#define	NI	16
#define	DIRPB	(BSIZE/sizeof(struct direct))
E 4
I 4
#define	NI		16
D 5
#define	DIRPB(fs)	((fs)->fs_bsize / sizeof(struct direct))
#define	MAXDIRPB	(MAXBSIZE / sizeof(struct direct))
E 5
#define MAXINOPB	(MAXBSIZE / sizeof(struct dinode))
#define MAXNINDIR	(MAXBSIZE / sizeof(daddr_t))
E 4

#include <stdio.h>
#include <ctype.h>
D 2
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/filsys.h>
#include <sys/ino.h>
#include <sys/inode.h>
#include <sys/fblk.h>
#include <sys/dir.h>
E 2
I 2
D 6
#include "../../h/param.h"
#include "../../h/stat.h"
#include "../../h/fs.h"
#include "../../h/inode.h"
D 5
#include "../../h/dir.h"
E 5
I 3
#include "../../h/dumprestor.h"
E 6
I 6
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/fs.h>
#include <sys/inode.h>
D 15
#include <dumprestor.h>
E 15
I 15
#include <protocols/dumprestore.h>
E 15
I 7
D 11
#include <dir.h>
E 11
I 11
#include <sys/dir.h>
E 11
E 7
E 6
E 3
E 2
#include <utmp.h>
D 12
#include <time.h>
E 12
I 12
#include <sys/time.h>
E 12
#include <signal.h>
I 2
D 9
int (*signal())();
E 9
E 2
D 3
#include <dumprestor.h>
E 3
#include <fstab.h>

D 4
#define	MWORD(m,i)	(m[(unsigned)(i-1)/MLEN])
#define	MBIT(i)		(1<<((unsigned)(i-1)%MLEN))
E 4
I 4
#define	MWORD(m,i)	(m[(unsigned)(i-1)/NBBY])
#define	MBIT(i)		(1<<((unsigned)(i-1)%NBBY))
E 4
#define	BIS(i,w)	(MWORD(w,i) |=  MBIT(i))
#define	BIC(i,w)	(MWORD(w,i) &= ~MBIT(i))
#define	BIT(i,w)	(MWORD(w,i) & MBIT(i))

D 4
short	clrmap[MSIZ];
short	dirmap[MSIZ];
short	nodmap[MSIZ];
E 4
I 4
int	msiz;
char	*clrmap;
char	*dirmap;
char	*nodmap;
E 4

/*
 *	All calculations done in 0.1" units!
 */

char	*disk;		/* name of the disk file */
char	*tape;		/* name of the tape file */
char	*increm;	/* name of the file containing incremental information*/
I 10
char	*temp;		/* name of the file for doing rewrite of increm */
char	lastincno;	/* increment number of previous dump */
E 10
char	incno;		/* increment number */
int	uflag;		/* update flag */
int	fi;		/* disk file descriptor */
int	to;		/* tape file descriptor */
I 8
int	pipeout;	/* true => output to standard output */
E 8
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
I 4
struct fs *sblock;	/* the file system super block */
char	buf[MAXBSIZE];
I 17
long	dev_bsize;
E 17
E 4

char	*ctime();
char	*prdate();
long	atol();
int	mark();
int	add();
I 13
int	dirdump();
E 13
int	dump();
int	tapsrec();
int	dmpspc();
int	dsrch();
int	nullf();
char	*getsuffix();
char	*rawname();
I 2
struct dinode *getino();
E 2

int	interrupt();		/* in case operator bangs on console */

#define	HOUR	(60L*60L)
#define	DAY	(24L*HOUR)
#define	YEAR	(365L*DAY)

/*
 *	Exit status codes
 */
D 16
#define	X_FINOK		1	/* normal exit */
E 16
I 16
#define	X_FINOK		0	/* normal exit */
E 16
#define	X_REWRITE	2	/* restart writing from the check point */
#define	X_ABORT		3	/* abort all of dump; don't attempt checkpointing*/

D 10
#ifdef DEBUG
#define	OINCREM	"./ddate"		/*old format incremental info*/
#define	NINCREM	"./dumpdates"		/*new format incremental info*/
#else not DEBUG
#define	OINCREM	"/etc/ddate"		/*old format incremental info*/
E 10
#define	NINCREM	"/etc/dumpdates"	/*new format incremental info*/
D 10
#endif
E 10
I 10
#define	TEMP	"/etc/dtmp"		/*output temp file*/
E 10

#define	TAPE	"/dev/rmt8"		/* default tape device */
#define	DISK	"/dev/rrp1g"		/* default disk */
#define	OPGRENT	"operator"		/* group entry to notify */
#define DIALUP	"ttyd"			/* prefix for dialups */

D 9
#define	MAXFSTAB		32
struct	fstab	fstab[MAXFSTAB];
E 9
struct	fstab	*fstabsearch();	/* search in fs_file and fs_spec */
D 9
int	nfstab;
E 9

/*
 *	The contents of the file NINCREM is maintained both on
 *	a linked list, and then (eventually) arrayified.
 */
I 7
struct	idates {
	char	id_name[MAXNAMLEN+3];
	char	id_incno;
	time_t	id_ddate;
};
E 7
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
