h06534
s 00004/00001/00267
d D 5.4 88/05/13 14:51:59 mckusick 56 54
c add Nflag to request not to do any writes
e
s 00003/00000/00268
d R 5.4 88/05/13 14:47:53 mckusick 55 54
c add Nflag to request not to do any writes
e
s 00001/00000/00267
d D 5.3 86/04/23 12:04:51 mckusick 54 53
c do not dump core when missing `.' or `..' entries in directories
e
s 00001/00001/00266
d D 5.2 85/06/18 21:11:35 mckusick 53 52
c dumprestor.h moves to /usr/include/protocols
e
s 00013/00003/00254
d D 5.1 85/05/28 15:12:52 dist 52 51
c Add copyright
e
s 00003/00002/00254
d D 3.16 85/03/24 18:10:14 mckusick 51 50
c dynamically calculate tape block size unless specified on command line
e
s 00000/00147/00256
d D 3.15 85/01/18 22:38:30 mckusick 50 49
c reorganize to split out interactive shell
e
s 00017/00000/00386
d D 3.14 85/01/14 16:07:11 mckusick 49 48
c add 'b' flag to set number of tape records
e
s 00006/00000/00380
d D 3.13 84/02/07 18:55:38 mckusick 48 47
c add "Resetmodes" option to interactive restore
e
s 00002/00002/00378
d D 3.12 83/08/11 23:04:59 sam 47 46
c standardize sccs keyword lines
e
s 00001/00000/00379
d D 3.11 83/06/19 18:39:41 mckusick 46 45
c make both 'q' and 'x' exit the interactive mode
e
s 00012/00000/00367
d D 3.10 83/05/15 00:43:52 mckusick 45 44
c add the (undocumented) 'D' command to turn on debugging in interactive restore
e
s 00192/00044/00175
d D 3.9 83/04/19 02:11:56 mckusick 44 43
c add and debug interactive extraction mode
e
s 00002/00008/00217
d D 3.8 83/03/27 18:33:05 mckusick 43 42
c pass pruning argument back to treescan
e
s 00001/00001/00224
d D 3.7 83/03/08 13:37:16 mckusick 42 41
c get 'r' and 'R' commands working
e
s 00022/00026/00203
d D 3.6 83/01/16 06:02:52 mckusick 41 40
c new incremental restore algorithm
e
s 00015/00028/00214
d D 3.5 83/03/05 16:18:04 mckusick 40 39
c fix debugging across tapes; account for dumpmap at start of every tape
e
s 00013/00009/00229
d D 3.4 83/02/28 00:36:29 mckusick 39 38
c canonicalize names on command line and ignore dups
e
s 00006/00003/00232
d D 3.3 83/02/27 14:38:30 mckusick 38 37
c get "x" command working
e
s 00005/00001/00230
d D 3.2 83/02/26 18:26:20 mckusick 37 36
c get the tape subsystem working; get "t" command working
e
s 00151/01317/00080
d D 3.1 83/02/18 00:38:03 mckusick 36 35
c update to allow incremental restores
e
s 00109/00148/01288
d D 2.17 83/01/08 18:51:40 mckusick 35 34
c speed-ups and clean-ups
e
s 00006/00016/01430
d D 2.16 82/12/22 15:23:46 sam 34 33
c use mkdir sys call
e
s 00001/00000/01445
d D 2.15 82/12/02 18:13:06 mckusick 33 32
c rrestor needs to run as root to set up remote host
e
s 00013/00000/01432
d D 2.14 82/12/02 17:41:06 sam 32 31
c handle grot from old dump tapes (symlinks with no data blocks)
e
s 00041/00061/01391
d D 2.13 82/10/11 17:56:07 mckusick 31 30
c fix up directory mod time calculations
e
s 00001/00001/01451
d D 2.12 82/10/11 11:24:11 mckusick 30 29
c save time, use vfork!
e
s 00080/00037/01372
d D 2.11 82/10/10 19:14:34 mckusick 29 28
c reduce working set; clean-up bad block code; produce old i-number to name map
e
s 00042/00021/01367
d D 2.10 82/10/07 19:26:42 mckusick 28 27
c add verbose flag (-v) and perseverence flag (-y) for tape errors
e
s 00011/00011/01377
d D 2.9 82/10/07 18:23:07 mckusick 27 26
c check for conversion to new file system format
e
s 00063/00005/01325
d D 2.8 82/10/04 00:00:04 mckusick 26 25
c add inode conversion routine
e
s 00001/00000/01329
d D 2.7 82/10/03 19:30:35 mckusick 25 24
c add sys/ioctl.h header file ahead of mtio.h
e
s 00064/00000/01265
d D 2.6 82/05/19 01:16:56 mckusick 24 23
c add conditional code (-DRRESTOR) to allow remote restores
e
s 00052/00018/01213
d D 2.5 82/05/19 01:14:55 mckusick 23 22
c fixes for multi-reel dumps
e
s 00038/00022/01193
d D 2.4 82/05/19 01:12:54 mckusick 22 21
c minor fixes to restart code; lots of lint
e
s 00019/00005/01196
d D 2.3 82/05/19 01:10:47 mckusick 21 20
c allow continuation after read errors
e
s 00114/00339/01087
d D 2.2 82/05/19 01:07:19 mckusick 20 19
c make file system independent
e
s 00007/00007/01419
d D 2.1 82/05/10 00:17:28 mckusick 19 18
c update to version 2 in new fs
e
s 00001/00000/01425
d D 1.16 82/03/25 02:31:44 mckusick 18 17
c update to the current system
e
s 00077/00008/01348
d D 1.15 82/03/23 12:53:42 mckusick 17 16
c add symbolic links
e
s 00021/00019/01335
d D 1.14 82/02/26 00:04:24 mckusic 16 15
c keep "fs" cached in incore inode to avoid constant calling of ``getfs''
e
s 00003/00001/01351
d D 1.13 82/02/24 20:40:59 mckusic 15 14
c release buffer after bread error
e
s 00172/00105/01180
d D 1.12 82/02/23 13:21:38 mckusic 14 13
c convert to new directory format
e
s 00002/00002/01283
d D 1.11 82/01/12 22:21:37 mckusic 13 12
c change all macros taking "fs" to have it as their first argument
e
s 00002/00002/01283
d D 1.10 82/01/06 23:35:10 mckusic 12 11
c incorporate fs.h -r1.10, and param.h -r1.8 reorganization
e
s 00006/00000/01279
d D 1.9 82/01/06 21:13:30 mckusic 11 10
c delete lost+found when doing full level 0 restor
e
s 00046/00029/01233
d D 1.8 82/01/05 01:34:12 mckusic 10 9
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00270/00120/00992
d D 1.7 81/11/22 19:58:16 mckusic 9 8
c understand long inodes; convert from old to new directory format
e
s 00263/00315/00849
d D 1.6 81/11/10 00:37:26 mckusic 8 7
c remove -v; reorder subroutines; fix bug in linking code
e
s 00475/00568/00689
d D 1.5 81/11/08 23:44:48 mckusic 7 6
c clean up -h -m; add -v; set mode, owner, and time of restored dirs
e
s 00142/00071/01115
d D 1.4 81/11/07 15:00:47 mckusic 6 4
c restor from "standard" (ie 1K file system) dump tapes
e
s 00091/00046/01140
d R 1.4 81/11/01 02:03:26 mckusic 5 4
c restor from "standard" (ie 1K file system) dump tapes
e
s 00254/00507/00932
d D 1.3 81/10/31 18:28:41 mckusic 4 2
c 8K only dump/restor
e
s 00224/00508/00931
d R 1.3 81/10/31 18:15:57 mckusic 3 2
c 8K only dump/restor
e
s 00003/00003/01436
d D 1.2 81/10/25 19:00:26 mckusic 2 1
c bring version 4.1 up to 4.3
e
s 01439/00000/00000
d D 1.1 81/10/25 17:48:17 mckusick 1 0
c date and time created 81/10/25 17:48:17 by mckusick
e
u
U
f b 
t
T
I 52
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 52
I 1
D 23
/* Copyright (c) 1981 Regents of the University of California */
E 23
I 23
D 36
/* Copyright (c) 1982 Regents of the University of California */
E 36
I 36
D 47
/* Copyright (c) 1983 Regents of the University of California */
E 36
E 23

E 47
I 22
#ifndef lint
E 22
D 36
char version[] = "%Z%%M% %I% %G%";
E 36
I 36
D 52
static char sccsid[] = "%W%	(Berkeley)	%E%";
E 36
I 22
#endif
E 52
I 52
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint
E 52
I 47

D 52
/* Copyright (c) 1983 Regents of the University of California */
E 52
I 52
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 52
E 47
E 22

D 36
/*	Modified to include h option (recursively extract all files within
 *	a subtree) and m option (recreate the heirarchical structure of
 *	that subtree and move extracted files to their proper homes).
E 36
I 36
/*
 *	Modified to recursively extract all files within a subtree
 *	(supressed by the h option) and recreate the heirarchical
 *	structure of that subtree and move extracted files to their
 *	proper homes (supressed by the m option).
 *	Includes the s (skip files) option for use with multiple
 *	dumps on a single tape.
E 36
 *	8/29/80		by Mike Litzkow
 *
I 22
D 36
 *	Modified to work on the new file system
E 36
I 36
 *	Modified to work on the new file system and to recover from
 *	tape read errors.
E 36
 *	1/19/82		by Kirk McKusick
 *
E 22
D 36
 *	Includes the s (skip files) option for use with multiple dumps on
 *	a single tape.
E 36
I 36
D 44
 *	Full incremental restore running entirely in user code.
E 44
I 44
 *	Full incremental restore running entirely in user code and
 *	interactive tape browser.
E 44
 *	1/19/83		by Kirk McKusick
E 36
 */

D 2
/* static char *sccsid = "@(#)restor.c	4.1 (Berkeley) 10/1/80"; */
E 2
I 2
D 20
/* static char *sccsid = "@(#)restor.c	4.3 (Berkeley) 6/3/81"; */
E 2

E 20
D 36
#define MAXINO	3000
#define BITS	8
#define NCACHE	3
D 7
#define NSIZE   100
E 7
#define SIZEINC 10

D 20
#ifndef STANDALONE
E 20
#include <stdio.h>
E 36
I 36
#include "restore.h"
I 49
D 53
#include <dumprestor.h>
E 53
I 53
#include <protocols/dumprestore.h>
E 53
E 49
E 36
#include <signal.h>
D 20
#endif
D 4
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/ino.h>
#include <sys/fblk.h>
#include <sys/filsys.h>
#include <sys/dir.h>
#include <dumprestor.h>
E 4
I 4
D 19
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/buf.h"
I 18
#include "../h/ndir.h"
E 18
D 14
#include "../h/dir.h"
E 14
#include "../h/user.h"
#include "../h/dumprestor.h"
E 19
I 19
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include <sys/buf.h>
#include <sys/ndir.h>
#include <sys/user.h>
#include <dumprestor.h>
E 20
I 20
D 36
#include <fstab.h>
I 23
D 35
#ifndef SIMFS
E 35
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include <dir.h>
#include <stat.h>
#include <dumprestor.h>
D 35
#else
E 23
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/stat.h"
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/dumprestor.h"
I 23
#endif
E 35
I 25
#include <sys/ioctl.h>
E 25
E 23
E 20
E 19
I 9
#include <sys/mtio.h>
E 36
E 9
E 4

I 14
D 36
#define ODIRSIZ 14
E 14
I 9
struct odirect {
	u_short	d_ino;
D 14
	char	d_name[DIRSIZ];
E 14
I 14
	char	d_name[ODIRSIZ];
E 14
};

E 9
D 10
#define	MWORD(m,i) (m[(unsigned)(i-1)/MLEN])
#define	MBIT(i)	(1<<((unsigned)(i-1)%MLEN))
E 10
I 10
#define	MWORD(m,i) (m[(unsigned)(i-1)/NBBY])
#define	MBIT(i)	(1<<((unsigned)(i-1)%NBBY))
E 10
#define	BIS(i,w)	(MWORD(w,i) |=  MBIT(i))
#define	BIC(i,w)	(MWORD(w,i) &= ~MBIT(i))
#define	BIT(i,w)	(MWORD(w,i) & MBIT(i))

D 4
struct	filsys	sblock;
E 4
D 7
struct  direct	dir;

int	fi;
E 7
D 4
ino_t	ino, maxi, curino;
E 4
I 4
D 22
ino_t	ino, maxi;
I 9
struct inode *cur_ip;
E 22
I 22
ino_t	ino;
E 22
E 9
E 4

D 4
int	mt, hflag, mflag, i;
E 4
I 4
D 6
int	mt, i;
E 6
I 6
D 9
int	mt;
E 9
I 9
D 26
int	eflag = 0, hflag = 0, mflag = 0, cvtdir = 0;
E 26
I 26
D 28
int	eflag = 0, hflag = 0, mflag = 0, cvtflag = 0, cvtdir = 0;
E 28
I 28
D 35
int	eflag = 0, hflag = 0, mflag = 0, vflag = 0, yflag = 0;
int	cvtflag = 0, cvtdir = 0;
E 35
I 35
int	eflag = 0, hflag = 1, mflag = 1, tflag = 0, vflag = 0, yflag = 0;
int	cvtflag = 0;
#define vprintf		if (vflag) fprintf
E 35
E 28
E 26
E 9

E 6
D 7
int	eflag, hflag, mflag;
E 7
I 7
D 8
int	eflag, hflag, mflag, vflag;
E 8
I 8
D 9
int	eflag = 0, hflag = 0, mflag = 0;
E 8
E 7
E 4

E 9
I 4
D 17
char	mounted = 0;
E 17
I 17
D 20
extern	long mounted;
E 20
I 20
long	fssize;
E 20
E 17
D 22
dev_t	dev = 0;
E 22
I 16
D 20
struct fs *fsptr;
struct inode parentino;
E 20
E 16
E 4
char	tapename[] = "/dev/rmt8";
char	*magtape = tapename;
I 9
int	mt;
int	dumpnum = 1;
int	volno = 1;
int	curblk = 0;
int	bct = NTREC+1;
char	tbf[NTREC*TP_BSIZE];
E 9

D 20
#ifdef STANDALONE
char	mbuf[50];
#endif

E 20
D 7
#ifndef STANDALONE
E 7
daddr_t	seekpt;
D 7
int	df, ofile;
E 7
I 7
FILE	*df;
I 14
DIR	*dirp;
E 14
int	ofile;
E 7
D 23
char	dirfile[] = "rstXXXXXX";
E 23
I 23
D 29
char	dirfile[] = "/tmp/rstXXXXXX";
E 29
I 29
char	dirfile[] = "/tmp/rstaXXXXXX";
D 31
char	entryfile[] = "/tmp/rstbXXXXXX";
E 31
E 29
E 23
I 17
char	lnkbuf[MAXPATHLEN + 1];
int	pathlen;
E 17

D 7
struct {
E 7
I 7
#define INOHASH(val) (val % MAXINO)
struct inotab {
	struct inotab *t_next;
E 7
	ino_t	t_ino;
	daddr_t	t_seekpt;
I 35
	time_t t_timep[2];
E 35
D 7
} inotab[MAXINO];
int	ipos;
E 7
I 7
} *inotab[MAXINO];
I 29
int maxino = 0;
E 29
D 8
struct inotab *getinotab();
E 8
E 7

D 7
#define ONTAPE	1
E 7
I 7
#define XISDIR	1
E 7
#define XTRACTD	2
#define XINUSE	4
I 6
D 7
#define LINKED	8
E 7
I 7
#define XLINKED	8
E 7
E 6
struct xtrlist {
D 7
	ino_t	x_ino;
I 6
	int	x_linkedto;
E 6
	char	x_flags;
	char 	*x_name;
} *xtrlist;
E 7
I 7
	struct xtrlist	*x_next;
	struct xtrlist	*x_linkedto;
I 29
D 31
	struct xtrlist	*x_self;
E 31
E 29
D 8
	char 		*x_name;
	ino_t		x_ino;
E 8
D 35
	time_t		x_timep[2];
E 35
I 8
	ino_t		x_ino;
E 8
	char		x_flags;
I 8
	char 		x_name[1];
	/* actually longer */
E 8
} *xtrlist[MAXINO];
D 8
struct xtrlist *getxtr();
E 8
E 7
I 6
int xtrcnt = 0;
I 29
D 31
int maxentry = 0;
union {
	struct xtrlist u_xtrlist;
	char dummy[BUFSIZ];
} entry;
E 31
I 31
struct xtrlist *entry;
struct xtrlist *unknown;
struct xtrlist *allocxtr();
E 31
E 29
E 6

D 7
char	name[100];
E 7
I 7
D 8
char	name[BUFSIZ + 1];
E 7

E 8
D 7
char	drblock[BSIZE];
int	bpt, nread, xsize,
	init = 1;

E 7
D 4

E 4
D 9
#include <sys/mtio.h>
struct mtop tcom;

D 4

E 4
int dumpnum = 1;
int	volno = 1;

I 4
struct inode *cur_ip;
E 4

E 9
D 4
int	eflag;

struct dinode tino, dino;
daddr_t	taddr[NADDR];

daddr_t	curbno;

E 4
D 10
short	dumpmap[MSIZ];
short	clrimap[MSIZ];
I 4
char	clearedbuf[BSIZE];
E 10
I 10
D 20
#ifdef STANDALONE
#define msiz 8192
char	dumpmap[msiz];
char	clrimap[msiz];
#else
E 20
D 22
int	msiz;
E 22
char	*dumpmap;
E 36
I 36
D 51
int	cvtflag = 0, dflag = 0, vflag = 0, yflag = 0;
E 51
I 51
int	bflag = 0, cvtflag = 0, dflag = 0, vflag = 0, yflag = 0;
E 51
D 56
int	hflag = 1, mflag = 1;
E 56
I 56
int	hflag = 1, mflag = 1, Nflag = 0;
E 56
char	command = '\0';
long	dumpnum = 1;
D 42
long	volno = 1;
E 42
I 42
long	volno = 0;
I 49
D 51
long	ntrec = NTREC;
E 51
I 51
long	ntrec;
E 51
E 49
E 42
char	*dumpmap;
E 36
char	*clrimap;
I 36
ino_t	maxino;
time_t	dumptime;
I 37
time_t	dumpdate;
I 44
FILE 	*terminal;
E 44
E 37
D 41
struct	entry **entry;
E 41
E 36
D 20
#endif
E 20
E 10
E 4

I 10
D 36
char	clearedbuf[MAXBSIZE];

E 10
I 6
D 9
int curblk = 0;

E 6
D 4

E 4
int bct = NTREC+1;
D 6
char tbf[NTREC*BSIZE];
E 6
I 6
char tbf[NTREC*TP_BSIZE];
E 6

E 9
I 7
extern char *ctime();
I 22
extern int seek();
E 22
I 8
ino_t search();
I 14
int dirwrite();
I 24
#ifdef RRESTOR
char *host;
#endif
E 24
E 14
E 8
E 7
D 4
struct	cache {
	daddr_t	c_bno;
	int	c_time;
	char	c_block[BSIZE];
} cache[NCACHE];
int	curcache;
E 4
I 4
D 20
char **envp;
E 20
E 4

E 36
D 4
main(argc, argv)
char *argv[];
E 4
I 4
D 22
main(argc, argv, arge)
E 22
I 22
main(argc, argv)
E 22
	int argc;
	char *argv[];
D 22
	char **arge;
E 22
E 4
{
	register char *cp;
I 38
	ino_t ino;
E 38
D 36
	char command;
E 36
I 36
	char *inputdev = "/dev/rmt8";
D 38
	char *symtbl = "./lost+found/restoresymtable";
	char *dirmodefile = "./lost+found/dirmodes";
E 38
I 38
	char *symtbl = "./restoresymtable";
D 44
	char *dirmodefile = "./dirmodes";
I 39
	char name[BUFSIZ];
E 44
I 44
	char name[MAXPATHLEN];
E 44
E 39
E 38
E 36
I 4
	int (*signal())();
E 4
D 36
	int done();
E 36
I 36
	extern int onintr();
D 38
	ino_t ino;
E 38
E 36

I 8
D 36
	if (signal(SIGINT, done) == SIG_IGN)
E 36
I 36
	if (signal(SIGINT, onintr) == SIG_IGN)
E 36
D 41
		signal(SIGINT, SIG_IGN);
E 41
I 41
		(void) signal(SIGINT, SIG_IGN);
E 41
D 36
	if (signal(SIGTERM, done) == SIG_IGN)
E 36
I 36
	if (signal(SIGTERM, onintr) == SIG_IGN)
E 36
D 41
		signal(SIGTERM, SIG_IGN);
E 41
I 41
		(void) signal(SIGTERM, SIG_IGN);
E 41
I 38
	setlinebuf(stderr);
E 38
E 8
D 20
#ifndef STANDALONE
D 4
	mktemp(dirfile);
E 4
I 4
	envp = arge;
	mktmp(dirfile);
E 20
I 20
D 36
	mktemp(dirfile);
E 36
E 20
E 4
	if (argc < 2) {
usage:
D 4
		printf("Usage: restor x[s|m|h] file file..., restor r filesys, or restor t\n");
		exit(1);
E 4
I 4
D 7
		fprintf(stderr, "Usage: restor x[s|m|h] file file..., restor r filesys, or restor t\n");
E 7
I 7
D 35
		fprintf(stderr, "Usage: restor x[s|m|h|v] file file..., restor r|R filesys, or restor t\n");
E 35
I 35
D 36
		fprintf(stderr, "Usage: restor xfhmsvy file file... or restor tf\n");
E 36
I 36
D 44
		fprintf(stderr, "Usage: restor xtfhmsvy file file... or restor rRfsvy\n");
E 44
I 44
		fprintf(stderr, "Usage:\n%s%s%s%s%s",
			"\trestore tfhsvy [file file ...]\n",
			"\trestore xfhmsvy [file file ...]\n",
			"\trestore ifhmsvy\n",
			"\trestore rfsvy\n",
			"\trestore Rfsvy\n");
E 44
E 36
E 35
E 7
		done(1);
E 4
	}
	argv++;
	argc -= 2;
I 35
	command = '\0';
E 35
	for (cp = *argv++; *cp; cp++) {
		switch (*cp) {
		case '-':
			break;
I 26
		case 'c':
			cvtflag++;
			break;
E 26
D 36
		case 'f':
			magtape = *argv++;
I 24
#ifdef RRESTOR
		{ char *index();
		  host = magtape;
		  magtape = index(host, ':');
		  if (magtape == 0) {
nohost:
			msg("need keyletter ``f'' and device ``host:tape''");
			done(1);
		  }
		  *magtape++ = 0;
		  if (rmthost(host) == 0)
			done(1);
		}
#endif
E 24
			argc--;
E 36
I 36
		case 'd':
			dflag++;
E 36
			break;
D 36
		/* s dumpnum (skip to) for multifile dump tapes */
		case 's':
			dumpnum = atoi(*argv++);
D 23
			if(dumpnum <= 0) {
E 23
I 23
			if (dumpnum <= 0) {
E 23
D 4
				printf("Dump number must be a positive integer\n");
				exit(1);
E 4
I 4
				fprintf(stderr, "Dump number must be a positive integer\n");
				done(1);
E 4
			}
			argc--;
			break;
E 36
		case 'h':
D 35
			hflag++;
E 35
I 35
			hflag = 0;
E 35
			break;
		case 'm':
D 35
			mflag++;
E 35
I 35
			mflag = 0;
I 56
			break;
		case 'N':
			Nflag++;
E 56
E 35
			break;
I 28
D 36
		case 'x':
D 35
			command = *cp;
			/* set verbose mode by default */
E 35
I 35
			if (command != '\0') {
				fprintf(stderr, "x and t are exclusive\n");
				goto usage;
			}
			command = 'x';
			break;
E 36
E 35
		case 'v':
			vflag++;
			break;
		case 'y':
			yflag++;
			break;
I 36
		case 'f':
I 40
			if (argc < 1) {
				fprintf(stderr, "missing device specifier\n");
				done(1);
			}
E 40
			inputdev = *argv++;
I 49
			argc--;
			break;
		case 'b':
			/*
			 * change default tape blocksize
			 */
I 51
			bflag++;
E 51
			if (argc < 1) {
				fprintf(stderr, "missing block size\n");
				done(1);
			}
			ntrec = atoi(*argv++);
			if (ntrec <= 0) {
				fprintf(stderr, "Block size must be a positive integer\n");
				done(1);
			}
E 49
			argc--;
			break;
		case 's':
			/*
			 * dumpnum (skip to) for multifile dump tapes
			 */
I 40
			if (argc < 1) {
				fprintf(stderr, "missing dump number\n");
				done(1);
			}
E 40
			dumpnum = atoi(*argv++);
			if (dumpnum <= 0) {
				fprintf(stderr, "Dump number must be a positive integer\n");
				done(1);
			}
			argc--;
			break;
E 36
E 28
D 35
		case 'r':
		case 'R':
I 20
			hflag++;
			mflag++;
E 35
E 20
		case 't':
D 28
		case 'x':
E 28
D 35
			command = *cp;
E 35
I 35
D 40
			if (command != '\0') {
D 36
				fprintf(stderr, "x and t are exclusive\n");
E 36
I 36
				fprintf(stderr,
					"t and %c are mutually exclusive\n",
					command);
E 36
				goto usage;
			}
			command = 't';
I 37
			break;
E 40
E 37
D 36
			tflag++;		
			vflag++;
E 36
I 36
		case 'R':
D 40
			if (command != '\0') {
				fprintf(stderr,
					"R and %c are mutually exclusive\n",
					command);
				goto usage;
			}
			command = 'R';
I 37
			break;
E 40
E 37
		case 'r':
D 40
			if (command != '\0') {
				fprintf(stderr,
					"r and %c are mutually exclusive\n",
					command);
				goto usage;
			}
			command = 'r';
I 37
			break;
E 40
E 37
		case 'x':
I 44
		case 'i':
E 44
			if (command != '\0') {
				fprintf(stderr,
D 40
					"x and %c are mutually exclusive\n",
					command);
E 40
I 40
					"%c and %c are mutually exclusive\n",
					*cp, command);
E 40
				goto usage;
			}
D 40
			command = 'x';
E 40
I 40
			command = *cp;
E 40
E 36
E 35
			break;
I 7
D 8
		case 'v':
			vflag++;
			break;
E 8
E 7
		default:
D 4
			printf("Bad key character %c\n", *cp);
E 4
I 4
			fprintf(stderr, "Bad key character %c\n", *cp);
E 4
			goto usage;
		}
	}
I 35
	if (command == '\0') {
D 36
		fprintf(stderr, "must specify x or t\n");
E 36
I 36
D 44
		fprintf(stderr, "must specify t, r, R, or x\n");
E 44
I 44
		fprintf(stderr, "must specify i, t, r, R, or x\n");
E 44
E 36
		goto usage;
	}
E 35
I 24
D 36
#ifdef RRESTOR
	if (host == 0)
		goto nohost;
#endif
I 33
	setuid(getuid());	/* no longer need or want root privileges */
E 33
E 24
D 20
	if (command == 'x') {
D 8
		if (signal(SIGINT, done) == SIG_IGN)
			signal(SIGINT, SIG_IGN);
		if (signal(SIGTERM, done) == SIG_IGN)
			signal(SIGTERM, SIG_IGN);

E 8
D 7
		df = creat(dirfile, 0666);
		if (df < 0) {
E 7
I 7
		df = fopen(dirfile, "w");
		if (df == 0) {
E 7
D 4
			printf("restor: %s - cannot create directory temporary\n", dirfile);
			exit(1);
E 4
I 4
			fprintf(stderr, "restor: %s - cannot create directory temporary\n", dirfile);
			done(1);
E 4
		}
D 7
		close(df);
E 7
I 4
D 17
		xmount(envp);
E 17
		mounted++;
I 17
		xmount(envp);
E 17
E 4
D 7
		df = open(dirfile, 2);
E 7
	}
E 20
	doit(command, argc, argv);
D 8
	if (command == 'x')
		unlink(dirfile);
E 8
D 4
	exit(0);
E 4
I 4
	done(0);
E 4
D 20
#else
	magtape = "tape";
	doit('r', 1, 0);
#endif
E 20
}

doit(command, argc, argv)
D 4
char	command;
int	argc;
char	*argv[]; 
E 4
I 4
	char	command;
	int	argc;
	char	*argv[]; 
E 4
{
I 9
	struct mtop tcom;
I 35
	char	*ststore();
	register struct inotab *itp;
	register struct xtrlist *xp;
	struct xtrlist **xpp;
	ino_t	d;
	int	xtrfile(), xtrskip(), xtrcvtdir(), xtrcvtskip(),
		xtrlnkfile(), xtrlnkskip(), null();
	int	mode, uid, gid, i;
	struct	stat stbuf;
	time_t	timep[2];
	char	name[BUFSIZ + 1];
E 35

E 36
I 36
	setinput(inputdev);
E 36
I 35
	if (argc == 0) {
D 36
		argc++;
E 36
I 36
		argc = 1;
E 36
		*--argv = ".";
	}
E 35
I 24
D 36
#ifdef RRESTOR
	if ((mt = rmtopen(magtape, 0)) < 0) {
#else
E 24
E 9
D 7
	extern char *ctime();
	char *ststore();
D 6
	register k;
E 6
I 6
	register int k;
	register struct xtrlist *xp;
	int i;
E 6
	ino_t	d;
E 7
D 20
#ifndef STANDALONE
E 20
D 2
	int	xtrfile(), skip();
E 2
I 2
D 7
	int	xtrfile(), skip(), null();
E 2
#endif
	int	rstrfile(), rstrskip();
D 4
	struct dinode *ip, *ip1;
E 4
I 4
	register struct dinode *dp;
	register struct inode *ip;
	struct fs *fs;
I 6
	int mode;
	time_t timep[2];
E 6
E 4

#ifndef STANDALONE
	getxtrlist();
E 7
	if ((mt = open(magtape, 0)) < 0) {
I 24
#endif
E 24
D 4
		printf("%s: cannot open tape\n", magtape);
		exit(1);
E 4
I 4
		fprintf(stderr, "%s: cannot open tape\n", magtape);
		done(1);
E 4
	}
D 8
	if(dumpnum != 1) {
E 8
I 8
	if (dumpnum != 1) {
E 8
		tcom.mt_op = MTFSF;
		tcom.mt_count = dumpnum -1;
I 24
#ifdef RRESTOR
		rmtioctl(MTFSF,dumpnum - 1);
#else
E 24
D 8
		if( ioctl(mt,MTIOCTOP,&tcom) < 0)
E 8
I 8
		if (ioctl(mt,MTIOCTOP,&tcom) < 0)
E 8
			perror("ioctl MTFSF");
I 24
#endif
E 24
	}
D 20
#else
	do {
D 4
		printf("Tape? ");
E 4
I 4
		fprintf(stderr, "Tape? ");
E 4
		gets(mbuf);
		mt = open(mbuf, 0);
	} while (mt == -1);
	magtape = mbuf;
I 4
D 9
	clearbuf(clearedbuf);
E 9
I 9
D 10
	blkclr(clearedbuf, BSIZE);
E 10
E 9
E 4
#endif
E 20
I 10
D 22
	blkclr(clearedbuf, MAXBSIZE);
E 22
I 22
D 35
	blkclr(clearedbuf, (long)MAXBSIZE);
E 35
I 35
	bzero(clearedbuf, (long)MAXBSIZE);
E 35
E 22
E 10
D 27
	switch(command) {
D 20
#ifndef STANDALONE
E 20
	case 't':
E 27
I 27
	if (readhdr(&spcl) == 0) {
		bct--; /* push back this block */
		cvtflag++;
E 27
		if (readhdr(&spcl) == 0) {
D 4
			printf("Tape is not a dump tape\n");
			exit(1);
E 4
I 4
			fprintf(stderr, "Tape is not a dump tape\n");
			done(1);
E 4
		}
I 27
		fprintf(stderr, "Converting to new file system format.\n");
	}
D 35
	switch(command) {
	case 't':
E 35
I 35
	if (vflag) {
E 35
E 27
D 4
		printf("Dump   date: %s", ctime(&spcl.c_date));
		printf("Dumped from: %s", ctime(&spcl.c_ddate));
E 4
I 4
D 8
		fprintf(stderr, "Dump   date: %s", ctime(&spcl.c_date));
		fprintf(stderr, "Dumped from: %s", ctime(&spcl.c_ddate));
E 8
I 8
		fprintf(stdout, "Dump   date: %s", ctime(&spcl.c_date));
		fprintf(stdout, "Dumped from: %s", ctime(&spcl.c_ddate));
E 8
E 4
D 35
		return;
I 20
	case 'R':
	case 'r':
		setdir(*argv);
		argc = 1;
		*argv = ".";
		/* and then extract it all */
E 20
	case 'x':
I 20
		df = fopen(dirfile, "w");
		if (df == 0) {
			fprintf(stderr, "restor: %s - cannot create directory temporary\n", dirfile);
			done(1);
		}
E 20
D 7
		if (readhdr(&spcl) == 0) {
D 4
			printf("Tape is not a dump tape\n");
			exit(1);
E 4
I 4
			fprintf(stderr, "Tape is not a dump tape\n");
			done(1);
E 7
I 7
		extractfiles(argc, argv);
		return;
E 35
I 10
D 20
#endif
E 10
	case 'r':
	case 'R':
		restorfiles(command, argv);
		return;
E 20
	}
D 10
#endif
E 10
D 35
}

D 20
#ifndef STANDALONE
E 20
extractfiles(argc, argv)
	int argc;
	char **argv;
{
D 8
	char *ststore();
E 8
I 8
	char	*ststore();
E 8
	register struct xtrlist *xp;
	struct xtrlist **xpp;
I 10
D 16
	struct fs *fs;
E 16
E 10
	ino_t	d;
D 9
	int	xtrfile(), skip(), null();
E 9
I 9
D 17
	int	xtrfile(), xtrskip(), xtrcvtdir(), xtrcvtskip(), null();
E 9
D 8
	int mode;
	time_t timep[2];
E 8
I 8
	int	mode;
E 17
I 17
	int	xtrfile(), xtrskip(), xtrcvtdir(), xtrcvtskip(),
		xtrlnkfile(), xtrlnkskip(), null();
D 21
	int	mode, uid, gid;
E 21
I 21
	int	mode, uid, gid, i;
E 21
E 17
D 29
	char	name[BUFSIZ + 1];
E 29
I 29
D 31
	FILE	*fe;
E 31
E 29
I 20
	struct	stat stbuf;
I 29
	char	name[BUFSIZ + 1];
E 29
E 20
E 8

E 35
I 35
	df = fopen(dirfile, "w");
	if (df == 0) {
		fprintf(stderr,
		    "restor: %s - cannot create directory temporary\n",
		    dirfile);
		done(1);
	}
E 35
I 20
	if (stat(".", &stbuf) < 0) {
		fprintf(stderr, "cannot stat .\n");
		done(1);
	}
D 29
	/*
	 * should be!!!
	 *
E 29
	fssize = stbuf.st_blksize;
D 29
	 */
	fssize = MAXBSIZE;
E 29
I 29
	if (fssize <= 0 || ((fssize - 1) & fssize) != 0) {
		fprintf(stderr, "bad block size %d\n", fssize);
		done(1);
	}
E 29
E 20
D 27
	if (readhdr(&spcl) == 0) {
		fprintf(stderr, "Tape is not a dump tape\n");
		done(1);
	}
E 27
	if (checkvol(&spcl, 1) == 0) {
		fprintf(stderr, "Tape is not volume 1 of the dump\n");
	}
I 10
D 16
	fs = getfs(dev);
	msiz = roundup(howmany(fs->fs_ipg * fs->fs_ncg, NBBY), TP_BSIZE);
E 16
I 16
D 20
	fsptr = getfs(dev);
	msiz = roundup(howmany(fsptr->fs_ipg * fsptr->fs_ncg, NBBY), TP_BSIZE);
E 16
	clrimap = (char *)calloc(msiz, sizeof(char));
	dumpmap = (char *)calloc(msiz, sizeof(char));
E 20
I 20
	clrimap = 0;
	dumpmap = 0;
I 31
	unknown = allocxtr(0, "name unknown - not extracted", 0);
E 31
E 20
E 10
D 9
	pass1();  /* This sets the various maps on the way by */
E 9
I 9
D 35
	pass1(1);  /* This sets the various maps on the way by */
E 35
I 35
	pass1();  /* This sets the various maps on the way by */
E 35
E 9
D 8
	while( argc-- ) {
E 8
I 8
	while (argc--) {
E 8
		if ((d = psearch(*argv)) == 0 || BIT(d,dumpmap) == 0) {
I 20
D 27
			printf("d = %d\n", d);
E 27
E 20
D 8
			fprintf(stderr,  "%s: not on tape\n", *argv++ );
E 8
I 8
D 28
			fprintf(stdout, "%s: not on tape\n", *argv++);
E 28
I 28
			fprintf(stderr, "%s: not on tape\n", *argv++);
E 28
E 8
			continue;
E 7
E 4
		}
I 8
D 35
		if (mflag)
E 35
I 35
		if (mflag && !tflag)
E 35
			checkdir(*argv);
E 8
D 7
		if (checkvol(&spcl, 1) == 0) {
D 4
			printf("Tape is not volume 1 of the dump\n");
E 4
I 4
			fprintf(stderr, "Tape is not volume 1 of the dump\n");
E 7
I 7
D 23
		if(hflag)
E 23
I 23
		if (hflag)
E 23
			getleaves(d, *argv++);
D 8
		else {
			xp = getxtr(d);
			xp->x_flags |= XINUSE;
			if( mflag )
				xp->x_name = ststore( *argv );
			fprintf(stderr,  "%s: inode %u\n", *argv, d );
			argv++;
E 7
E 4
		}
E 8
I 8
		else
D 31
			allocxtr(d, *argv++, XINUSE);
E 31
I 31
			(void)allocxtr(d, *argv++, XINUSE);
E 31
E 8
D 7
		pass1();  /* This sets the various maps on the way by */
D 6
		i = 0;
E 6
		while( argc-- ) {
			if(hflag)
				getleaves( *argv++ );
			else {
				if( (d = psearch(*argv)) == 0 ||
							BIT(d,dumpmap) == 0 ) {
D 4
					printf( "%s: not on tape\n", *argv++ );
E 4
I 4
					fprintf(stderr,  "%s: not on tape\n", *argv++ );
E 4
					continue;
				}
D 6
				xtrlist[i].x_ino = d;
				xtrlist[i].x_flags |= XINUSE;
E 6
I 6
				xtrlist[xtrcnt].x_ino = d;
				xtrlist[xtrcnt].x_flags |= XINUSE;
E 6
				if( mflag )
D 6
					xtrlist[i].x_name = ststore( *argv );
E 6
I 6
					xtrlist[xtrcnt].x_name = ststore( *argv );
E 6
D 4
				printf( "%s: inode %u\n", *argv, d );
E 4
I 4
				fprintf(stderr,  "%s: inode %u\n", *argv, d );
E 4
				argv++;
D 6
				if( ++i >= xsize ) getxtrlist();
E 6
I 6
				if( ++xtrcnt >= xsize ) getxtrlist();
E 6
			}
		}
E 7
I 7
	}
I 29
D 31
	mktemp(entryfile);
	fe = fopen(entryfile, "w");
	if (fe == 0) {
		fprintf(stderr, "restor: %s - cannot create directory temporary\n", entryfile);
		done(1);
	}
	for (d = 0; d <= maxino; d++) {
		for (xp = xtrlist[INOHASH(d)]; xp; xp = xp->x_next) {
			if (d != xp->x_ino || (xp->x_flags & XLINKED))
				continue;
			blkcpy(xp, &entry, maxentry);
			fwrite(&entry, maxentry, 1, fe);
			break;
		}
	}
	fclose(fe);
	fe = fopen(entryfile, "r");
	xp = &entry.u_xtrlist;
	xp->x_ino = 0;
E 31
E 29
E 7
D 9


D 7
		if(dumpnum > 1)
			tcom.mt_op = MTBSF;
		else	tcom.mt_op = MTREW;
		tcom.mt_count = 1;
E 7
I 7
	if(dumpnum > 1)
		tcom.mt_op = MTBSF;
	else	tcom.mt_op = MTREW;
	tcom.mt_count = 1;
E 7

newvol:
D 7
		flsht();
E 7
I 7
	flsht();
	ioctl(mt,MTIOCTOP,&tcom);
E 9
D 8
	if( dumpnum > 1 ) {
E 8
I 8
	if (dumpnum > 1) {
E 8
D 9
		tcom.mt_op = MTFSF;
		tcom.mt_count = 1;
E 7
		ioctl(mt,MTIOCTOP,&tcom);
E 9
I 9
		/*
		 * if this is a multi-dump tape we always start with 
		 * volume 1, so as to avoid accidentally restoring
		 * from a different dump!
		 */
		resetmt();
		dumpnum = 1;
		volno = 1;
		readhdr(&spcl);
		goto rbits;
E 9
D 7
		if( dumpnum > 1 ) {
			tcom.mt_op = MTFSF;
			tcom.mt_count = 1;
			ioctl(mt,MTIOCTOP,&tcom);
		}
I 4
		lseek(mt, 0, 0);
E 7
I 7
	}
D 9
	lseek(mt, (long)0, 0);
E 7
E 4


E 9
I 9
newvol:
I 24
#ifdef RRESTOR
	rmtclose();
#else
E 24
D 23
	resetmt();
E 23
I 23
	close(mt);
I 24
#endif
I 35
	if (tflag)
		return;
E 35
E 24
E 23
E 9
getvol:
D 4
		printf("Mount desired tape volume: Specify volume #: ");
E 4
I 4
D 7
		fprintf(stderr, "Mount desired tape volume: Specify volume #: ");
E 4
		if (gets(tbf) == NULL)
			return;
		volno = atoi(tbf);
		if (volno <= 0) {
D 4
			printf("Volume numbers are positive numerics\n");
E 4
I 4
			fprintf(stderr, "Volume numbers are positive numerics\n");
E 4
			goto getvol;
		}
		if (readhdr(&spcl) == 0) {
D 4
			printf("tape is not dump tape\n");
E 4
I 4
			fprintf(stderr, "tape is not dump tape\n");
E 4
			goto newvol;
		}
		if (checkvol(&spcl, volno) == 0) {
D 4
			printf("Wrong volume (%d)\n", spcl.c_volume);
E 4
I 4
			fprintf(stderr, "Wrong volume (%d)\n", spcl.c_volume);
E 4
			goto newvol;
		}
E 7
I 7
D 9
	fprintf(stderr, "Mount desired tape volume: Specify volume #: ");
E 9
I 9
	fprintf(stderr, "Mount desired tape volume; Specify volume #: ");
E 9
	if (gets(tbf) == NULL)
		return;
	volno = atoi(tbf);
	if (volno <= 0) {
		fprintf(stderr, "Volume numbers are positive numerics\n");
		goto getvol;
	}
I 24
#ifdef RRESTOR
	if ((mt = rmtopen(magtape, 0)) == -1) {
#else
E 24
I 23
	if ((mt = open(magtape, 0)) == -1) {
I 24
#endif
E 24
		fprintf(stderr, "Cannot open tape!\n");
		goto getvol;
	}
	if (dumpnum > 1)
		resetmt();
E 23
	if (readhdr(&spcl) == 0) {
		fprintf(stderr, "tape is not dump tape\n");
		goto newvol;
	}
	if (checkvol(&spcl, volno) == 0) {
		fprintf(stderr, "Wrong volume (%d)\n", spcl.c_volume);
		goto newvol;
	}
E 7
rbits:
D 7
		while (gethead(&spcl) == 0)
			;
		if (checktype(&spcl, TS_INODE) == 1) {
D 4
			printf("Can't find inode mask!\n");
E 4
I 4
			fprintf(stderr, "Can't find inode mask!\n");
E 4
			goto newvol;
E 7
I 7
	while (gethead(&spcl) == 0)
		;
	if (checktype(&spcl, TS_INODE) == 1) {
		fprintf(stderr, "Can't find inode mask!\n");
		goto newvol;
	}
	if (checktype(&spcl, TS_BITS) == 0)
		goto rbits;
D 20
	readbits(dumpmap);
E 20
I 20
	readbits(&dumpmap);
E 20
	while (xtrcnt > 0) {
again:
D 21
		if (ishead(&spcl) == 0)
E 21
I 21
		if (ishead(&spcl) == 0) {
			i = 0;
E 21
D 23
			while(gethead(&spcl) == 0)
E 23
I 23
			while (gethead(&spcl) == 0)
E 23
D 21
				;
E 21
I 21
				i++;
D 29
			fprintf(stderr, "resync restor, skipped %i blocks\n",
E 29
I 29
			fprintf(stderr, "resync restor, skipped %d blocks\n",
E 29
			    i);
		}
E 21
		if (checktype(&spcl, TS_END) == 1) {
			fprintf(stderr, "end of tape\n");
			break;
E 7
		}
D 7
		if (checktype(&spcl, TS_BITS) == 0)
			goto rbits;
		readbits(dumpmap);
		i = 0;
		for (k = 0; xtrlist[k].x_flags; k++) {
			if (BIT(xtrlist[k].x_ino, dumpmap)) {
				xtrlist[k].x_flags |= ONTAPE;
				i++;
			}
E 7
I 7
		if (checktype(&spcl, TS_INODE) == 0) {
			gethead(&spcl);
			goto again;
E 7
		}
D 7
		while (i > 0) {
again:
			if (ishead(&spcl) == 0)
				while(gethead(&spcl) == 0)
					;
			if (checktype(&spcl, TS_END) == 1) {
D 4
				printf("end of tape\n");
E 4
I 4
				fprintf(stderr, "end of tape\n");
E 4
checkdone:
D 6
				for (k = 0; xtrlist[k].x_flags; k++)
					if ((xtrlist[k].x_flags&XTRACTD) == 0) {
						/* get next tape */
						tcom.mt_op = MTREW;

						goto newvol;
E 6
I 6
				for (xp = xtrlist; xp->x_flags; xp++) {
					if ((xp->x_flags&XTRACTD) == 0)
						if ((xp->x_flags&LINKED) == 0) {
							fprintf(stderr, "cannot find file %s\n",
								xp->x_name);
					} else {
						fprintf(stderr, "link %s to %s\n",
							xtrlist[xp->x_linkedto].x_name,
							xp->x_name);
						if (xlink(xtrlist[xp->x_linkedto].x_name, xp->x_name) < 0)
							fprintf(stderr, "link failed\n");
E 6
					}
E 7
I 7
		d = spcl.c_inumber;
D 29
		for (xp = xtrlist[INOHASH(d)]; xp; xp = xp->x_next) {
			if (d != xp->x_ino)
				continue;
			if (xp->x_flags & XLINKED)
				continue;
E 29
I 29
D 31
		if (d < xp->x_ino) {
			fseek(fe, 0, 0);
			xp->x_ino = 0;
		}
		while (d > xp->x_ino)
			fread(xp, maxentry, 1, fe);
		if (d == xp->x_ino) {
E 31
I 31
		entry = unknown;
		entry->x_ino = d;
		for (xp = xtrlist[INOHASH(d)]; xp; xp = xp->x_next) {
			if (d != xp->x_ino || (xp->x_flags & XLINKED))
E 36
I 36
	switch (command) {
D 44

	case 't':
E 44
I 44
	/*
	 * Interactive mode.
	 */
	case 'i':
E 44
		setup();
D 44
		extractdirs((char *)0);
		while (argc--) {
D 39
			if ((ino = psearch(*argv)) == 0 ||
E 39
I 39
			canon(*argv++, name);
			if ((ino = psearch(name)) == 0 ||
E 39
			    BIT(ino, dumpmap) == 0) {
D 39
				fprintf(stderr, "%s: not on tape\n", *argv++);
E 39
I 39
				fprintf(stderr, "%s: not on tape\n", name);
E 39
E 36
				continue;
D 36
			entry = xp;
E 31
E 29
D 35
			xp->x_timep[0] = spcl.c_dinode.di_atime;
			xp->x_timep[1] = spcl.c_dinode.di_mtime;
E 35
I 35
			timep[0] = spcl.c_dinode.di_atime;
			timep[1] = spcl.c_dinode.di_mtime;
E 35
			mode = spcl.c_dinode.di_mode;
			if (mflag)
D 8
				sprintf(name, "%s", xp->x_name);
E 8
I 8
				strcpy(name, xp->x_name);
E 8
			else
				sprintf(name, "%u", xp->x_ino);
			switch (mode & IFMT) {
			default:
D 8
				fprintf(stderr, "%s: unknown file type\n");
E 8
I 8
D 23
				fprintf(stderr, "%s: unknown file type\n", name);
E 23
I 23
				fprintf(stderr, "%s: unknown file mode 0%o\n",
				    name, mode);
E 23
E 8
D 29
				xp->x_flags |= XTRACTD;
E 29
I 29
D 31
				xp->x_self->x_flags |= XTRACTD;
E 31
I 31
				xp->x_flags |= XTRACTD;
E 31
E 29
				xtrcnt--;
				goto skipfile;
			case IFCHR:
			case IFBLK:
D 8
				if (vflag)
					fprintf(stderr, "extract special file %s\n", name);
E 8
I 8
D 28
				fprintf(stdout, "extract special file %s\n", name);
E 28
I 28
D 35
				if (vflag)
					fprintf(stdout, "extract special file %s\n", name);
E 35
I 35
				vprintf(stdout, "extract special file %s\n", name);
E 35
E 28
E 8
D 20
				if (xmknod(name, mode, spcl.c_dinode.di_rdev)) {
E 20
I 20
				if (mknod(name, mode, spcl.c_dinode.di_rdev)) {
E 20
					fprintf(stderr, "%s: cannot create special file\n", name);
D 29
					xp->x_flags |= XTRACTD;
E 29
I 29
D 31
					xp->x_self->x_flags |= XTRACTD;
E 31
I 31
					xp->x_flags |= XTRACTD;
E 31
E 29
					xtrcnt--;
					goto skipfile;
E 7
I 6
				}
E 6
D 7
				return;
			}
			if (checktype(&spcl, TS_INODE) == 0) {
				gethead(&spcl);
				goto again;
			}
			d = spcl.c_inumber;
			for (k = 0; xtrlist[k].x_flags; k++) {
				if (d == xtrlist[k].x_ino) {
					if( mflag ) {
						sprintf(name, "%s", xtrlist[k].x_name);
D 4
						printf("extract file %s\n",name);
E 4
I 4
						fprintf(stderr, "extract file %s\n",name);
E 4
						checkdir( name );
					}
					else {
D 4
						printf("extract file %u\n", xtrlist[k].x_ino );
E 4
I 4
						fprintf(stderr, "extract file %u\n", xtrlist[k].x_ino );
E 4
						sprintf(name, "%u", xtrlist[k].x_ino);
					}
D 4
					if ((ofile = creat(name, 0666)) < 0) {
						printf("%s: cannot create file\n", name);
E 4
I 4
D 6
					if ((ofile = xcreat(name, 0666)) < 0) {
						fprintf(stderr, "%s: cannot create file\n", name);
E 6
I 6
					timep[0] = spcl.c_dinode.di_atime;
					timep[1] = spcl.c_dinode.di_mtime;
					mode = spcl.c_dinode.di_mode;
					switch (mode & IFMT) {
					default:
						fprintf(stderr, "%s: unknown file type\n");
E 6
E 4
						i--;
						continue;
I 6
					case IFDIR:
						fprintf(stderr, "%s: missing directory\n", name);
						i--;
						continue;
					case IFCHR:
					case IFBLK:
						if (xmknod(name, mode, spcl.c_dinode.di_rdev)) {
							fprintf(stderr, "%s: cannot create special file\n", name);
							i--;
							continue;
						}
						break;
					case IFREG:
						if ((ofile = xcreat(name, 0666)) < 0) {
							fprintf(stderr, "%s: cannot create file\n", name);
							i--;
							continue;
						}
						getfile(xtrfile, skip, spcl.c_dinode.di_size);
						xclose(ofile);
						break;
E 6
					}
E 7
I 7
				getfile(null, null, spcl.c_dinode.di_size);
				break;
			case IFDIR:
				if (mflag) {
D 8
					if (vflag)
						fprintf(stderr, "extract directory %s\n", name);
E 8
I 8
D 28
					fprintf(stdout, "extract directory %s\n", name);
E 28
I 28
D 35
					if (vflag)
						fprintf(stdout, "extract directory %s\n", name);
E 35
I 35
					for (itp = inotab[INOHASH(d)];
					     itp; itp = itp->t_next) {
						if (itp->t_ino != d)
							continue;
						itp->t_timep[0] = timep[0];
						itp->t_timep[1] = timep[1];
						break;
					}
					if (itp == 0) 
						fprintf(stderr, "missing directory entry\n");
					vprintf(stdout, "extract directory %s\n", name);
E 35
E 28
E 8
					strncat(name, "/.", BUFSIZ);
D 8
					checkdir( name );
E 7
D 4
					chown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
					getfile(ino, xtrfile, skip, spcl.c_dinode.di_size);
E 4
I 4
					xchown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 8
I 8
					checkdir(name);
D 20
					xchown(xp->x_name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 20
I 20
					chown(xp->x_name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 20
E 8
D 6
					getfile(xtrfile, skip, spcl.c_dinode.di_size);
E 4
					i--;
E 6
I 6
D 7
					xutime(name, timep);
E 6
					xtrlist[k].x_flags |= XTRACTD;
D 4
					close(ofile);
					goto done;
E 4
I 4
D 6
					xclose(ofile);
E 6
I 6
					i--;
E 6
					goto finished;
E 7
I 7
					getfile(null, null, spcl.c_dinode.di_size);
					break;
E 7
E 4
				}
I 7
D 9
				/* else fall through */
E 9
I 9
D 28
				fprintf(stdout, "extract file %s\n", name);
E 28
I 28
D 35
				if (vflag)
					fprintf(stdout, "extract file %s\n", name);
E 35
I 35
				vprintf(stdout, "extract file %s\n", name);
E 35
E 28
D 20
				if ((ofile = xcreat(name, 0666)) < 0) {
E 20
I 20
				if ((ofile = creat(name, 0666)) < 0) {
E 20
					fprintf(stderr, "%s: cannot create file\n", name);
D 29
					xp->x_flags |= XTRACTD;
E 29
I 29
D 31
					xp->x_self->x_flags |= XTRACTD;
E 31
I 31
					xp->x_flags |= XTRACTD;
E 31
E 29
					xtrcnt--;
					goto skipfile;
				}
D 20
				xchown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 20
I 20
				chown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 20
D 14
				if (cvtdir)
E 14
I 14
D 35
				if (cvtdir) {
E 35
I 35
				if (cvtflag) {
E 35
E 14
					getfile(xtrcvtdir, xtrcvtskip,
					    spcl.c_dinode.di_size);
D 14
				else
E 14
I 14
					flushent(xtrfile);
				} else
E 14
					getfile(xtrfile, xtrskip,
					    spcl.c_dinode.di_size);
D 20
				xclose(ofile);
E 20
I 20
				close(ofile);
E 20
				break;
I 17
			case IFLNK:
I 32
				/*
				 * Some early dump tapes have symbolic links
				 * present without the associated data blocks.
				 * This hack avoids trashing a file system with
				 * inodes with missing data blocks.
				 */
				if (spcl.c_count == 0) {
D 35
					if (vflag)
						printf("%s: 0 length symbolic link (ignored)\n", name);
E 35
I 35
					vprintf(stdout, "%s: 0 length symbolic link (ignored)\n", name);
E 35
					xp->x_flags |= XTRACTD;
					xtrcnt--;
					goto skipfile;
				}
E 32
D 28
				fprintf(stdout, "extract symbolic link %s\n", name);
E 28
I 28
D 35
				if (vflag)
					fprintf(stdout, "extract symbolic link %s\n", name);
E 35
I 35
				vprintf(stdout, "extract symbolic link %s\n", name);
E 35
E 28
				uid = spcl.c_dinode.di_uid;
				gid = spcl.c_dinode.di_gid;
				lnkbuf[0] = '\0';
				pathlen = 0;
				getfile(xtrlnkfile, xtrlnkskip, spcl.c_dinode.di_size);
D 20
				if (xsymlink(lnkbuf, name) < 0) {
E 20
I 20
				if (symlink(lnkbuf, name) < 0) {
E 20
					fprintf(stderr, "%s: cannot create symbolic link\n", name);
D 29
					xp->x_flags |= XTRACTD;
E 29
I 29
D 31
					xp->x_self->x_flags |= XTRACTD;
E 31
I 31
					xp->x_flags |= XTRACTD;
E 31
E 29
					xtrcnt--;
					goto finished;
				}
D 20
				xchown(name, uid, gid);
E 20
I 20
				chown(name, uid, gid);
E 20
				break;
E 17
E 9
			case IFREG:
D 8
				if (vflag)
					fprintf(stderr, "extract file %s\n", name);
E 8
I 8
D 28
				fprintf(stdout, "extract file %s\n", name);
E 28
I 28
D 35
				if (vflag)
					fprintf(stdout, "extract file %s\n", name);
E 35
I 35
				vprintf(stdout, "extract file %s\n", name);
E 35
E 28
E 8
D 20
				if ((ofile = xcreat(name, 0666)) < 0) {
E 20
I 20
				if ((ofile = creat(name, 0666)) < 0) {
E 20
					fprintf(stderr, "%s: cannot create file\n", name);
D 29
					xp->x_flags |= XTRACTD;
E 29
I 29
D 31
					xp->x_self->x_flags |= XTRACTD;
E 31
I 31
					xp->x_flags |= XTRACTD;
E 31
E 29
					xtrcnt--;
					goto skipfile;
				}
D 20
				xchown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 20
I 20
				chown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 20
D 9
				getfile(xtrfile, skip, spcl.c_dinode.di_size);
E 9
I 9
				getfile(xtrfile, xtrskip, spcl.c_dinode.di_size);
E 9
D 20
				xclose(ofile);
E 20
I 20
				close(ofile);
E 20
				break;
E 36
E 7
			}
D 2
			gethead(&spcl);
E 2
I 2
D 4
			getfile(d, null, null, spcl.c_dinode.di_size);
E 2
done:
E 4
I 4
D 7
			getfile(null, null, spcl.c_dinode.di_size);
E 7
I 7
D 20
			xchmod(name, mode);
			xutime(name, xp->x_timep);
E 20
I 20
D 36
			chmod(name, mode);
D 35
			utime(name, xp->x_timep);
E 35
I 35
			utime(name, timep);
E 35
E 20
D 29
			xp->x_flags |= XTRACTD;
E 29
I 29
D 31
			xp->x_self->x_flags |= XTRACTD;
E 31
I 31
			xp->x_flags |= XTRACTD;
E 31
E 29
			xtrcnt--;
			goto finished;
E 36
I 36
D 39
			treescan(*argv++, ino, listfile);
E 39
I 39
D 40
			treescan(name, ino, listfile);
E 40
I 40
D 43
			if (hflag)
				treescan(name, ino, listfile);
			else
				listfile(name, ino, inodetype(ino));
E 43
I 43
			treescan(name, ino, listfile);
E 43
E 40
E 39
E 36
		}
D 36
skipfile:
		getfile(null, null, spcl.c_dinode.di_size);
E 7
finished:
E 4
D 7
			;
E 7
I 7
		;
	}
	if (xtrcnt == 0 && !mflag)
		return;
	for (xpp = xtrlist; xpp < &xtrlist[MAXINO]; xpp++) {
		for (xp = *xpp; xp; xp = xp->x_next) {
D 35
			if (mflag && (xp->x_flags & XISDIR))
D 20
				xutime(xp->x_name, xp->x_timep);
E 20
I 20
				utime(xp->x_name, xp->x_timep);
E 35
I 35
			if (mflag && (xp->x_flags & XISDIR)) {
				for (itp = inotab[INOHASH(xp->x_ino)];
				     itp; itp = itp->t_next) {
					if (itp->t_ino != xp->x_ino)
						continue;
					utime(xp->x_name, itp->t_timep);
					break;
				}
				if (itp == 0)
					fprintf(stderr, "missing dir entry\n");
			}
E 35
E 20
			if (xp->x_flags & XTRACTD)
				continue;
			if ((xp->x_flags & XLINKED) == 0) {
				fprintf(stderr, "cannot find file %s\n",
					xp->x_name);
				continue;
			}
D 8
			if (vflag)
				fprintf(stderr, "link %s to %s\n",
					xp->x_linkedto->x_name, xp->x_name);
E 8
I 8
			if (!mflag)
				continue;
D 28
			fprintf(stdout, "link %s to %s\n",
				xp->x_linkedto->x_name, xp->x_name);
E 28
I 28
D 35
			if (vflag)
				fprintf(stdout, "link %s to %s\n",
E 35
I 35
			vprintf(stdout, "link %s to %s\n",
E 35
					xp->x_linkedto->x_name, xp->x_name);
E 28
E 8
D 20
			if (xlink(xp->x_linkedto->x_name, xp->x_name) < 0)
E 20
I 20
			if (link(xp->x_linkedto->x_name, xp->x_name) < 0)
E 20
D 8
				fprintf(stderr, "link failed\n");
E 8
I 8
				fprintf(stderr, "link %s to %s failed\n",
					xp->x_linkedto->x_name, xp->x_name);
E 8
E 7
		}
D 7
		goto checkdone;
E 7
I 7
	}
}
E 36
I 36
		done(0);
E 36
E 7
D 20
#endif
E 20
D 7
	case 'r':
	case 'R':
#ifndef STANDALONE
D 4
		if ((fi = open(*argv, 2)) < 0) {
			printf("%s: cannot open\n", *argv);
			exit(1);
E 4
I 4
		{
			char mount[80];
			char *ptr[2];
E 7

D 7
			strcpy(mount, "MOUNT=");
			strcat(mount, *argv);
			ptr[0] = mount;
			ptr[1] = 0;
			xmount(ptr);
			iput(u.u_cdir); /* release root inode */
			iput(u.u_rdir); /* release root inode */
			mounted++;
E 4
		}
#else
		do {
			char charbuf[50];
E 7
I 7
D 20
restorfiles(command, argv)
	char command;
	char **argv;
{
D 9
	int	rstrfile(), rstrskip();
E 9
I 9
D 14
	int	rstrfile(), rstrskip(), rstrcvtdir(), rstrcvtskip();
E 14
I 14
	int null(), rstrfile(), rstrskip(), rstrcvtdir(), rstrcvtskip();
E 14
E 9
	register struct dinode *dp;
	register struct inode *ip;
D 16
	struct fs *fs;
E 16
D 9
	int mode;
E 9
I 9
	int mode, type;
E 9
	char mount[BUFSIZ + 1];
	char *ptr[2];
E 7

D 4
			printf("Disk? ");
E 4
I 4
D 7
			fprintf(stderr, "Disk? ");
E 4
			gets(charbuf);
			fi = open(charbuf, 2);
		} while (fi == -1);
E 7
I 7
D 10
#ifndef STANDALONE
E 10
	mount[0] = '\0';
	strcpy(mount, "MOUNT=");
I 10
#ifndef STANDALONE
E 10
	strncat(mount, *argv, BUFSIZ);
I 10
#else
	fprintf(stderr, "Disk? ");
	gets(&mount[6]);
#endif
E 10
	ptr[0] = mount;
	ptr[1] = 0;
D 17
	xmount(ptr);
E 17
I 10
	mounted++;
I 17
	xmount(ptr);
E 17
E 10
	iput(u.u_cdir); /* release root inode */
	iput(u.u_rdir); /* release root inode */
D 10
	mounted++;
#else
	do {
		fprintf(stderr, "Disk? ");
		gets(mount);
		fi = open(mount, 2);
	} while (fi == -1);
E 7
#endif
E 10
I 10
D 16
	fs = getfs(dev);
	maxi = fs->fs_ipg * fs->fs_ncg;
E 16
I 16
	fsptr = getfs(dev);
	parentino.i_fs = fsptr;
	parentino.i_dev = dev;
	maxi = fsptr->fs_ipg * fsptr->fs_ncg;
E 16
E 10
#ifndef STANDALONE
I 10
	msiz = roundup(howmany(maxi, NBBY), TP_BSIZE);
	clrimap = (char *)calloc(msiz, sizeof(char));
	dumpmap = (char *)calloc(msiz, sizeof(char));
E 10
D 7
		if (command == 'R') {
D 4
			printf("Enter starting volume number: ");
E 4
I 4
			fprintf(stderr, "Enter starting volume number: ");
E 4
			if (gets(tbf) == EOF) {
				volno = 1;
D 4
				printf("\n");
E 4
I 4
				fprintf(stderr, "\n");
E 4
			}
			else
				volno = atoi(tbf);
E 7
I 7
	if (command == 'R') {
		fprintf(stderr, "Enter starting volume number: ");
		if (gets(tbf) == EOF) {
			volno = 1;
			fprintf(stderr, "\n");
E 7
		}
		else
I 7
			volno = atoi(tbf);
	}
	else
E 7
#endif
D 7
			volno = 1;
D 4
		printf("Last chance before scribbling on %s. ",
E 4
I 4
		fprintf(stderr, "Last chance before scribbling on %s. ",
E 7
I 7
		volno = 1;
	fprintf(stderr, "Last chance before scribbling on %s. ",
E 7
E 4
#ifdef STANDALONE
D 7
								"disk");
E 7
I 7
							"disk");
E 7
#else
D 7
								*argv);
E 7
I 7
							*argv);
E 7
#endif
D 7
		while (getchar() != '\n');
D 4
		dread((daddr_t)1, (char *)&sblock, sizeof(sblock));
		maxi = (sblock.s_isize-2)*INOPB;
E 4
I 4
		fs = getfs(dev);
		maxi = fs->fs_ipg * fs->fs_ncg;
E 4
		if (readhdr(&spcl) == 0) {
D 4
			printf("Missing volume record\n");
			exit(1);
E 4
I 4
			fprintf(stderr, "Missing volume record\n");
			done(1);
E 7
I 7
	while (getchar() != '\n');
D 10
	fs = getfs(dev);
	maxi = fs->fs_ipg * fs->fs_ncg;
E 10
	if (readhdr(&spcl) == 0) {
		fprintf(stderr, "Missing volume record\n");
		done(1);
	}
	if (checkvol(&spcl, volno) == 0) {
		fprintf(stderr, "Tape is not volume %d\n", volno);
		done(1);
	}
I 9
	pass1(0);
	gethead(&spcl); /* volume header already checked above */
E 9
	gethead(&spcl);
	for (;;) {
D 14
ragain:
E 14
		if (ishead(&spcl) == 0) {
			fprintf(stderr, "Missing header block\n");
			while (gethead(&spcl) == 0)
				;
			eflag++;
E 7
E 4
		}
D 7
		if (checkvol(&spcl, volno) == 0) {
D 4
			printf("Tape is not volume %d\n", volno);
			exit(1);
E 4
I 4
			fprintf(stderr, "Tape is not volume %d\n", volno);
			done(1);
E 7
I 7
		if (checktype(&spcl, TS_END) == 1) {
			fprintf(stderr, "End of tape\n");
			close(mt);
			return;
E 7
E 4
		}
D 7
		gethead(&spcl);
		for (;;) {
ragain:
			if (ishead(&spcl) == 0) {
D 4
				printf("Missing header block\n");
E 4
I 4
				fprintf(stderr, "Missing header block\n");
E 4
				while (gethead(&spcl) == 0)
					;
				eflag++;
			}
			if (checktype(&spcl, TS_END) == 1) {
D 4
				printf("End of tape\n");
E 4
I 4
				fprintf(stderr, "End of tape\n");
E 4
				close(mt);
D 4
				dwrite( (daddr_t) 1, (char *) &sblock);
E 4
				return;
			}
			if (checktype(&spcl, TS_CLRI) == 1) {
				readbits(clrimap);
				for (ino = 1; ino <= maxi; ino++)
					if (BIT(ino, clrimap) == 0) {
D 4
						getdino(ino, &tino);
						if (tino.di_mode == 0)
E 4
I 4
						if (!iexist(dev, ino))
E 4
							continue;
D 4
						itrunc(&tino);
						clri(&tino);
						putdino(ino, &tino);
E 4
I 4
						ip = iget(dev, ino);
						if (ip == NULL) {
							fprintf(stderr, "can't find inode %u\n", ino);
							done(1);
						}
						ip->i_nlink = 0;
						ip->i_flag |= ICHG;
						iput(ip);
E 7
I 7
		if (checktype(&spcl, TS_CLRI) == 1) {
			readbits(clrimap);
I 11
			/*
			 * if throwing away the root inode, must also
			 * discard the predefined lost+found directory.
			 */
			if (BIT(ROOTINO, clrimap))
				BIS(LOSTFOUNDINO + 1, clrimap);
E 11
D 12
			for (ino = 1; ino <= maxi; ino++)
E 12
I 12
			for (ino = ROOTINO; ino <= maxi; ino++)
E 12
				if (BIT(ino, clrimap) == 0) {
D 16
					if (!iexist(dev, ino))
E 16
I 16
					if (!iexist(&parentino, ino))
E 16
						continue;
D 16
					ip = iget(dev, ino);
E 16
I 16
					ip = iget(dev, fsptr, ino);
E 16
					if (ip == NULL) {
						fprintf(stderr, "can't find inode %u\n", ino);
						done(1);
E 7
E 4
					}
D 4
				dwrite( (daddr_t) 1, (char *) &sblock);
E 4
D 7
				goto ragain;
			}
			if (checktype(&spcl, TS_BITS) == 1) {
				readbits(dumpmap);
				goto ragain;
			}
			if (checktype(&spcl, TS_INODE) == 0) {
D 4
				printf("Unknown header type\n");
E 4
I 4
				fprintf(stderr, "Unknown header type\n");
E 4
				eflag++;
				gethead(&spcl);
				goto ragain;
			}
			ino = spcl.c_inumber;
			if (eflag)
D 4
				printf("Resynced at inode %u\n", ino);
E 4
I 4
				fprintf(stderr, "Resynced at inode %u\n", ino);
E 4
			eflag = 0;
			if (ino > maxi) {
D 4
				printf("%u: ilist too small\n", ino);
E 4
I 4
				fprintf(stderr, "%u: ilist too small\n", ino);
E 4
				gethead(&spcl);
				goto ragain;
			}
D 4
			dino = spcl.c_dinode;
			getdino(ino, &tino);
			curbno = 0;
			itrunc(&tino);
			clri(&tino);
			for (i = 0; i < NADDR; i++)
				taddr[i] = 0;
			l3tol(taddr, dino.di_addr, 1);
			getfile(d, rstrfile, rstrskip, dino.di_size);
			ip = &tino;
			ltol3(ip->di_addr, taddr, NADDR);
			ip1 = &dino;
			ip->di_mode = ip1->di_mode;
			ip->di_nlink = ip1->di_nlink;
			ip->di_uid = ip1->di_uid;
			ip->di_gid = ip1->di_gid;
			ip->di_size = ip1->di_size;
			ip->di_atime = ip1->di_atime;
			ip->di_mtime = ip1->di_mtime;
			ip->di_ctime = ip1->di_ctime;
			putdino(ino, &tino);
E 4
I 4
			if (iexist(dev, ino)) {
				ip = iget(dev, ino);
				if (ip == NULL) {
					fprintf(stderr, "can't find inode %u\n",
						ino);
					done(1);
E 7
I 7
					ip->i_nlink = 0;
					ip->i_flag |= ICHG;
					iput(ip);
E 7
				}
D 7
				ip->i_nlink = 0;
				ip->i_flag |= ICHG;
				iput(ip);
			}
			dp = &spcl.c_dinode;
			ip = ialloc(dev, ino, dp->di_mode);
			if (ip == NULL || ip->i_number != ino) {
				fprintf(stderr, "can't create inode %u\n", ino);
E 7
I 7
D 14
			goto ragain;
E 14
I 14
			continue;
E 14
		}
		if (checktype(&spcl, TS_BITS) == 1) {
			readbits(dumpmap);
D 14
			goto ragain;
E 14
I 14
			continue;
E 14
		}
		if (checktype(&spcl, TS_INODE) == 0) {
			fprintf(stderr, "Unknown header type\n");
			eflag++;
			gethead(&spcl);
D 14
			goto ragain;
E 14
I 14
			continue;
E 14
		}
		ino = spcl.c_inumber;
		if (eflag)
			fprintf(stderr, "Resynced at inode %u\n", ino);
		eflag = 0;
		if (ino > maxi) {
			fprintf(stderr, "%u: ilist too small\n", ino);
			gethead(&spcl);
D 14
			goto ragain;
E 14
I 14
			continue;
E 14
		}
I 14
		dp = &spcl.c_dinode;
		if (ino < ROOTINO) {
			getfile(null, null, dp->di_size);
			continue;
		}
E 14
D 16
		if (iexist(dev, ino)) {
			ip = iget(dev, ino);
E 16
I 16
		if (iexist(&parentino, ino)) {
			ip = iget(dev, fsptr, ino);
E 16
			if (ip == NULL) {
				fprintf(stderr, "can't find inode %u\n",
					ino);
E 7
				done(1);
			}
D 6
			ip->i_mode = dp->di_mode;
E 6
I 6
D 7
			ip->i_mode = mode = dp->di_mode;
E 6
			ip->i_nlink = dp->di_nlink;
			ip->i_uid = dp->di_uid;
			ip->i_gid = dp->di_gid;
D 6
			ip->i_size = dp->di_size;
E 6
			ip->i_atime = dp->di_atime;
			ip->i_mtime = dp->di_mtime;
			ip->i_ctime = dp->di_ctime;
I 6
			if ((ip->i_mode & IFMT) == IFCHR ||
			    (ip->i_mode & IFMT) == IFBLK)
				ip->i_rdev = dp->di_rdev;
			ip->i_size = 0;
E 6
			cur_ip = ip;
			u.u_offset = 0;
			u.u_segflg = 1;
			getfile(rstrfile, rstrskip, dp->di_size);
I 6
			ip->i_mode = mode;
			ip->i_flag &= ~(IUPD|IACC);
E 7
I 7
			ip->i_nlink = 0;
E 7
E 6
			ip->i_flag |= ICHG;
			iput(ip);
E 4
		}
I 7
D 14
		dp = &spcl.c_dinode;
E 14
D 16
		ip = ialloc(dev, ino, dp->di_mode);
E 16
I 16
		ip = ialloc(&parentino, ino, dp->di_mode);
E 16
		if (ip == NULL || ip->i_number != ino) {
			fprintf(stderr, "can't create inode %u\n", ino);
			done(1);
		}
		ip->i_mode = mode = dp->di_mode;
		ip->i_nlink = dp->di_nlink;
		ip->i_uid = dp->di_uid;
		ip->i_gid = dp->di_gid;
		ip->i_atime = dp->di_atime;
		ip->i_mtime = dp->di_mtime;
		ip->i_ctime = dp->di_ctime;
D 9
		if ((ip->i_mode & IFMT) == IFCHR ||
		    (ip->i_mode & IFMT) == IFBLK)
E 9
I 9
		type = ip->i_mode & IFMT;
		if (type == IFCHR || type == IFBLK)
E 9
			ip->i_rdev = dp->di_rdev;
		ip->i_size = 0;
		cur_ip = ip;
		u.u_offset = 0;
		u.u_segflg = 1;
D 9
		getfile(rstrfile, rstrskip, dp->di_size);
E 9
I 9
D 14
		if (cvtdir && type == IFDIR)
E 14
I 14
		if (cvtdir && type == IFDIR) {
E 14
			getfile(rstrcvtdir, rstrcvtskip, dp->di_size);
D 14
		else
E 14
I 14
			flushent(rstrfile);
		} else
E 14
			getfile(rstrfile, rstrskip, dp->di_size);
E 9
		ip->i_mode = mode;
		ip->i_flag &= ~(IUPD|IACC);
		ip->i_flag |= ICHG;
		iput(ip);
E 7
	}
}

E 20
D 36
/*
 * Read the tape, bulding up a directory structure for extraction
 * by name
 */
D 20
#ifndef STANDALONE
E 20
D 9
pass1()
E 9
I 9
D 35
pass1(savedir)
	int savedir;
E 35
I 35
pass1()
E 35
E 9
{
D 6
	register i;
E 6
I 6
	register int i;
E 6
D 7
	struct dinode *ip;
E 7
I 7
	register struct dinode *ip;
	struct direct nulldir;
D 8
	register struct inotab *itp;
E 8
E 7
D 9
	int	putdir(), null();
E 9
I 9
	char buf[TP_BSIZE];
D 14
	int putdir(), null();
E 14
I 14
	int putdir(), null(), dirwrite();
E 14
E 9

I 7
D 14
	nulldir.d_ino = 0;
	strncpy(nulldir.d_name, "/", DIRSIZ);
E 14
I 14
	nulldir.d_ino = 1;
	nulldir.d_namlen = 1;
	strncpy(nulldir.d_name, "/", nulldir.d_namlen);
	nulldir.d_reclen = DIRSIZ(&nulldir);
E 14
E 7
	while (gethead(&spcl) == 0) {
D 4
		printf("Can't find directory header!\n");
E 4
I 4
		fprintf(stderr, "Can't find directory header!\n");
E 4
	}
	for (;;) {
		if (checktype(&spcl, TS_BITS) == 1) {
D 20
			readbits(dumpmap);
E 20
I 20
			readbits(&dumpmap);
E 20
			continue;
		}
		if (checktype(&spcl, TS_CLRI) == 1) {
D 20
			readbits(clrimap);
E 20
I 20
			readbits(&clrimap);
E 20
			continue;
		}
		if (checktype(&spcl, TS_INODE) == 0) {
finish:
D 7
			flsh();
E 7
D 9
/*	
			close(mt);
*/
I 7
			freopen(dirfile, "r", df);
E 9
I 9
D 14
			if (savedir)
				freopen(dirfile, "r", df);
E 14
I 14
D 35
			if (savedir) {
				fclose(df);
				dirp = opendir(dirfile);
				if (dirp == NULL)
					perror("opendir");
			}
E 35
I 35
			fclose(df);
			dirp = opendir(dirfile);
			if (dirp == NULL)
				perror("opendir");
E 35
E 14
			resetmt();
E 9
E 7
			return;
		}
		ip = &spcl.c_dinode;
		i = ip->di_mode & IFMT;
		if (i != IFDIR) {
			goto finish;
		}
I 9
D 35
		if (spcl.c_inumber == ROOTINO) {
			readtape(buf);
			bct--; /* push back this block */
			if (((struct direct *)buf)->d_ino != ROOTINO) {
				if (((struct odirect *)buf)->d_ino != ROOTINO) {
					fprintf(stderr, "bad root directory\n");
					done(1);
				}
				fprintf(stderr, "converting to new directory format\n");
				cvtdir = 1;
I 26
				cvtflag = 1;
E 26
			}
			if (!savedir && !cvtdir) {
				/* if no conversion, just return */
				goto finish;
			}
		}
E 35
E 9
D 7
		inotab[ipos].t_ino = spcl.c_inumber;
		inotab[ipos++].t_seekpt = seekpt;
E 7
I 7
D 8
		itp = getinotab(spcl.c_inumber);
		itp->t_seekpt = seekpt;
E 8
I 8
		allocinotab(spcl.c_inumber, seekpt);
E 8
E 7
D 4
		getfile(spcl.c_inumber, putdir, null, spcl.c_dinode.di_size);
E 4
I 4
D 9
		getfile(putdir, null, spcl.c_dinode.di_size);
E 4
D 7
		putent("\000\000/");
E 7
I 7
		putent(&nulldir);
E 9
I 9
D 35
		if (savedir) {
			getfile(putdir, null, spcl.c_dinode.di_size);
D 14
			putent(&nulldir);
E 14
I 14
			putent(&nulldir, dirwrite);
			flushent(dirwrite);
E 14
		} else {
			getfile(null, null, spcl.c_dinode.di_size);
		}
E 35
I 35
		getfile(putdir, null, spcl.c_dinode.di_size);
		putent(&nulldir, dirwrite);
		flushent(dirwrite);
E 35
E 9
E 7
	}
}
D 20
#endif
E 20

/*
I 8
 * Put the directory entries in the directory file
 */
D 20
#ifndef STANDALONE
E 20
putdir(buf, size)
	char *buf;
	int size;
{
I 9
	struct direct cvtbuf;
	register struct odirect *odp;
	struct odirect *eodp;
E 9
	register struct direct *dp;
D 9
	register int i;
E 9
I 9
D 14
	struct direct *edp;
E 14
I 14
D 17
	long loc;
E 17
I 17
	long loc, i;
E 17
E 14
E 9

D 9
	for (dp = (struct direct *)buf, i = 0; i < size; dp++, i += sizeof(*dp))
		if (dp->d_ino != 0)
			putent(dp);
E 9
I 9
D 35
	if (cvtdir) {
E 35
I 35
	if (cvtflag) {
E 35
		eodp = (struct odirect *)&buf[size];
		for (odp = (struct odirect *)buf; odp < eodp; odp++)
			if (odp->d_ino != 0) {
				dcvt(odp, &cvtbuf);
D 14
				putent(&cvtbuf);
E 14
I 14
				putent(&cvtbuf, dirwrite);
E 14
			}
	} else {
D 14
		edp = (struct direct *)&buf[size];
		for (dp = (struct direct *)buf; dp < edp; dp++)
E 14
I 14
		for (loc = 0; loc < size; ) {
			dp = (struct direct *)(buf + loc);
I 17
			i = DIRBLKSIZ - (loc & (DIRBLKSIZ - 1));
			if (dp->d_reclen <= 0 || dp->d_reclen > i) {
				loc += i;
E 36
I 36
	case 'x':
		setup();
		extractdirs(dirmodefile);
E 44
I 44
		extractdirs(1);
E 44
D 41
		entry = (struct entry **)
			calloc((int)maxino, sizeof(struct entry *));
		if (entry == (struct entry **)NIL)
			panic("no memory for entry table\n");
		(void)addentry(".", ROOTINO, NODE);
E 41
I 41
		initsymtable((char *)0);
E 41
D 44
		while (argc--) {
D 39
			if ((ino = psearch(*argv)) == 0 ||
E 39
I 39
			canon(*argv++, name);
			if ((ino = psearch(name)) == 0 ||
E 39
			    BIT(ino, dumpmap) == 0) {
D 39
				fprintf(stderr, "%s: not on tape\n", *argv++);
E 39
I 39
				fprintf(stderr, "%s: not on tape\n", name);
E 39
E 36
				continue;
			}
D 36
			loc += dp->d_reclen;
E 17
E 14
D 23
			if (dp->d_ino != 0)
E 23
I 23
			if (dp->d_ino != 0) {
E 23
D 14
				putent(dp);
E 14
I 14
				putent(dp, dirwrite);
I 23
			}
E 36
I 36
			if (mflag)
D 39
				pathcheck(*argv, NEW);
E 39
I 39
D 41
				pathcheck(name, NULL);
E 41
I 41
				pathcheck(name);
E 41
E 39
D 43
			if (hflag)
D 39
				treescan(*argv++, ino, addfile);
E 39
I 39
				treescan(name, ino, addfile);
E 39
			else
D 39
				addfile(*argv++, ino, LEAF);
E 39
I 39
				addfile(name, ino, inodetype(ino));
E 43
I 43
			treescan(name, ino, addfile);
E 43
E 39
E 36
E 23
		}
I 38
D 39
		createnodes();
E 39
E 38
E 14
D 36
	}
E 9
}
E 36
I 36
		createfiles();
I 38
		createlinks();
E 38
		setdirmodes(dirmodefile);
		if (dflag)
			checkrestore();
E 44
I 44
		runcmdshell();
E 44
		done(0);
E 36
D 44

E 44
I 44
	/*
	 * Incremental restoration of a file system.
	 */
E 44
D 14
putent(dp)
	struct direct *dp;
{
	fwrite(dp, 1, sizeof(struct direct), df);
	seekpt = ftell(df);
}

I 9
dcvt(odp, ndp)
	register struct odirect *odp;
	register struct direct *ndp;
{
	register struct inotab *itp;

	blkclr(ndp, sizeof *ndp);
	ndp->d_ino =  odp->d_ino;
	strncpy(ndp->d_name, odp->d_name, DIRSIZ);
	for (itp = inotab[INOHASH(odp->d_ino)]; itp; itp = itp->t_next) {
		if (itp->t_ino != odp->d_ino)
			continue;
D 12
		ndp->d_mode = IFDIR;
E 12
I 12
		ndp->d_fmt = IFDIR;
E 12
		break;
	}
}

E 14
E 9
D 36
/*
 *	Recursively find names and inumbers of all files in subtree 
 *	pname and put them in xtrlist[]
 */
getleaves(ino, pname)
	ino_t ino;
	char *pname;
{
	register struct inotab *itp;
	int namelen;
D 14
	daddr_t	bpt;
	struct direct dir;
	char 	locname[BUFSIZ + 1];
E 14
I 14
D 22
	long bpt;
E 22
I 22
	daddr_t bpt;
E 22
	register struct direct *dp;
	char locname[BUFSIZ + 1];
E 14

	if (BIT(ino, dumpmap) == 0) {
D 28
		fprintf(stdout, "%s: not on the tape\n", pname);
E 28
I 28
D 35
		if (vflag)
			fprintf(stdout, "%s: not on the tape\n", pname);
E 35
I 35
		vprintf(stdout, "%s: not on the tape\n", pname);
E 35
E 28
		return;
	}
	for (itp = inotab[INOHASH(ino)]; itp; itp = itp->t_next) {
		if (itp->t_ino != ino)
			continue;
		/*
		 * pname is a directory name 
		 */
D 31
		allocxtr(ino, pname, XISDIR);
E 31
I 31
		(void)allocxtr(ino, pname, XISDIR);
E 31
		/*
		 * begin search through the directory
		 * skipping over "." and ".."
		 */
		strncpy(locname, pname, BUFSIZ);
		strncat(locname, "/", BUFSIZ);
		namelen = strlen(locname);
D 14
		fseek(df, itp->t_seekpt, 0);
		fread(&dir, 1, sizeof(struct direct), df);
		fread(&dir, 1, sizeof(struct direct), df);
		fread(&dir, 1, sizeof(struct direct), df);
		bpt = ftell(df);
E 14
I 14
		seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
		dp = readdir(dirp);
		dp = readdir(dirp);
		dp = readdir(dirp);
		bpt = telldir(dirp);
E 14
		/*
		 * "/" signals end of directory
		 */
D 14
		while (strncmp(dir.d_name, "/", DIRSIZ)) {
E 14
I 14
D 35
		while (dp->d_namlen != 1 || dp->d_name[0] != '/') {
E 35
I 35
		while (dp != NULL && 
		    !(dp->d_namlen == 1 && dp->d_name[0] == '/')) {
E 35
E 14
			locname[namelen] = '\0';
D 14
			strncat(locname, dir.d_name, DIRSIZ);
			if (strlen(locname) >= BUFSIZ) {
				fprintf(stderr, "%s: name exceedes %d char\n",
					locname, BUFSIZ);
E 14
I 14
			if (namelen + dp->d_namlen >= BUFSIZ) {
D 35
				fprintf(stderr, "%s%s: name exceedes %d char\n",
E 35
I 35
				fprintf(stderr, "%s%s: name exceeds %d char\n",
E 35
					locname, dp->d_name, BUFSIZ);
E 14
D 35
				continue;
E 35
I 35
			} else {
				strncat(locname, dp->d_name, dp->d_namlen);
				getleaves(dp->d_ino, locname);
				seekdir(dirp, bpt, itp->t_seekpt);
E 35
			}
D 14
			getleaves(dir.d_ino, locname);
			fseek(df, bpt, 0);
			fread(&dir, 1, sizeof(struct direct), df);
			bpt = ftell(df);
E 14
I 14
D 35
			strncat(locname, dp->d_name, dp->d_namlen);
			getleaves(dp->d_ino, locname);
			seekdir(dirp, bpt, itp->t_seekpt);
E 35
			dp = readdir(dirp);
			bpt = telldir(dirp);
E 36
I 36
	case 'r':
		setup();
D 37
		extractdirs(dirmodefile);
E 37
		if (dumptime > 0) {
I 41
			/*
			 * This is an incremental dump tape.
			 */
			vprintf(stdout, "Begin incremental restore\n");
E 41
			initsymtable(symtbl);
I 41
D 44
			extractdirs(dirmodefile);
E 44
I 44
			extractdirs(1);
E 44
			removeoldleaves();
			vprintf(stdout, "Calculate node updates.\n");
			treescan(".", ROOTINO, nodeupdates);
			findunreflinks();
			removeoldnodes();
E 41
		} else {
D 41
			entry = (struct entry **)
				calloc((int)maxino, sizeof(struct entry *));
			if (entry == (struct entry **)NIL)
				panic("no memory for entry table\n");
			(void)addentry(".", ROOTINO, NODE);
E 41
I 41
			/*
			 * This is a level zero dump tape.
			 */
			vprintf(stdout, "Begin level 0 restore\n");
			initsymtable((char *)0);
D 44
			extractdirs(dirmodefile);
E 44
I 44
			extractdirs(1);
E 44
			vprintf(stdout, "Calculate extraction list.\n");
			treescan(".", ROOTINO, nodeupdates);
E 41
E 36
E 14
		}
I 37
D 41
		extractdirs(dirmodefile);
E 37
D 36
		return;
	}
	/*
	 * locname is name of a simple file 
	 */
D 31
	allocxtr(ino, pname, XINUSE);
E 31
I 31
	(void)allocxtr(ino, pname, XINUSE);
E 31
}

/*
 * Search the directory tree rooted at inode ROOTINO
 * for the path pointed at by n
 */
psearch(n)
	char	*n;
{
	register char *cp, *cp1;
	char c;

	ino = ROOTINO;
	if (*(cp = n) == '/')
		cp++;
next:
	cp1 = cp + 1;
	while (*cp1 != '/' && *cp1)
		cp1++;
	c = *cp1;
	*cp1 = 0;
	ino = search(ino, cp);
	if (ino == 0) {
		*cp1 = c;
		return(0);
	}
	*cp1 = c;
	if (c == '/') {
		cp = cp1+1;
		goto next;
	}
	return(ino);
}

/*
 * search the directory inode ino
 * looking for entry cp
 */
ino_t
search(inum, cp)
	ino_t	inum;
	char	*cp;
{
D 14
	struct direct dir;
E 14
I 14
	register struct direct *dp;
E 14
	register struct inotab *itp;
I 14
	int len;
E 14

	for (itp = inotab[INOHASH(inum)]; itp; itp = itp->t_next)
		if (itp->t_ino == inum)
			goto found;
	return(0);
found:
D 14
	fseek(df, itp->t_seekpt, 0);
E 14
I 14
	seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
	len = strlen(cp);
E 14
	do {
D 14
		fread(&dir, 1, sizeof(struct direct), df);
		if (!strncmp(dir.d_name, "/", DIRSIZ))
E 14
I 14
		dp = readdir(dirp);
		if (dp->d_namlen == 1 && dp->d_name[0] == '/')
E 14
			return(0);
D 14
	} while (strncmp(dir.d_name, cp, DIRSIZ));
	return(dir.d_ino);
E 14
I 14
	} while (dp->d_namlen != len || strncmp(dp->d_name, cp, len));
	return(dp->d_ino);
E 14
}
D 20
#endif
E 20

/*
E 8
 * Do the file extraction, calling the supplied functions
 * with the blocks
 */
D 4
getfile(n, f1, f2, size)
ino_t	n;
int	(*f2)(), (*f1)();
long	size;
E 4
I 4
getfile(f1, f2, size)
	int	(*f2)(), (*f1)();
D 22
	long	size;
E 22
I 22
	off_t	size;
E 22
E 4
{
D 6
	register i;
	struct spcl addrblock;
	char buf[BSIZE];
E 6
I 6
	register int i;
D 7
	union u_spcl addrblock;
E 7
D 10
	char buf[BLKING * FRAG][TP_BSIZE];
E 10
I 10
	char buf[MAXBSIZE / TP_BSIZE][TP_BSIZE];
E 10
I 7
	union u_spcl addrblk;
I 10
D 16
	register struct fs *fs;
E 16
E 10
#	define addrblock addrblk.s_spcl
E 7
E 6

D 6
	addrblock = spcl;
E 6
I 6
D 7
	addrblock.s_spcl = spcl;
E 7
I 7
	addrblock = spcl;
I 10
D 16
	fs = getfs(dev);
E 16
E 10
E 7
E 6
D 4
	curino = n;
	goto start;
E 4
	for (;;) {
D 4
		if (gethead(&addrblock) == 0) {
			printf("Missing address (header) block\n");
			goto eloop;
		}
		if (checktype(&addrblock, TS_ADDR) == 0) {
			spcl = addrblock;
			curino = 0;
			curino = 0;
			return;
		}
start:
E 4
D 6
		for (i = 0; i < addrblock.c_count; i++) {
			if (addrblock.c_addr[i]) {
				readtape(buf);
				(*f1)(buf, size > BSIZE ? (long) BSIZE : size);
E 6
I 6
D 7
		for (i = 0; i < addrblock.s_spcl.c_count; i++) {
			if (addrblock.s_spcl.c_addr[i]) {
E 7
I 7
		for (i = 0; i < addrblock.c_count; i++) {
			if (addrblock.c_addr[i]) {
E 7
				readtape(&buf[curblk++][0]);
D 10
				if (curblk == BLKING * FRAG) {
E 10
I 10
D 16
				if (curblk == BLKING(fs) * fs->fs_frag) {
E 16
I 16
D 20
				if (curblk == BLKING(fsptr) * fsptr->fs_frag) {
E 20
I 20
				if (curblk == fssize / TP_BSIZE) {
E 20
E 16
E 10
					(*f1)(buf, size > TP_BSIZE ?
D 10
					     (long) (BLKING * FRAG * TP_BSIZE) :
E 10
I 10
D 16
					     (long) (BLKING(fs) * fs->fs_frag * TP_BSIZE) :
E 16
I 16
D 20
					     (long) (BLKING(fsptr) * fsptr->fs_frag * TP_BSIZE) :
E 20
I 20
					     (long) (fssize) :
E 20
E 16
E 10
					     (curblk - 1) * TP_BSIZE + size);
					curblk = 0;
				}
E 6
D 10
			}
			else {
E 10
I 10
			} else {
E 10
D 4
				clearbuf(buf);
				(*f2)(buf, size > BSIZE ? (long) BSIZE : size);
E 4
I 4
D 6
				(*f2)(clearedbuf, size > BSIZE ? (long) BSIZE : size);
E 6
I 6
				if (curblk > 0) {
					(*f1)(buf, size > TP_BSIZE ?
					     (long) (curblk * TP_BSIZE) :
					     (curblk - 1) * TP_BSIZE + size);
					curblk = 0;
				}
D 10
				(*f2)(clearedbuf, size > TP_BSIZE ? (long) TP_BSIZE : size);
E 10
I 10
				(*f2)(clearedbuf, size > TP_BSIZE ?
					(long) TP_BSIZE : size);
E 10
E 6
E 4
			}
D 6
			if ((size -= BSIZE) <= 0) {
E 6
I 6
			if ((size -= TP_BSIZE) <= 0) {
E 6
D 29
eloop:
				while (gethead(&spcl) == 0)
					;
				if (checktype(&spcl, TS_ADDR) == 1)
					goto eloop;
E 29
I 29
				gethead(&spcl);
E 29
D 4
				curino = 0;
E 4
D 6
				return;
E 6
I 6
				goto out;
E 6
			}
		}
I 4
D 6
		if (gethead(&addrblock) == 0) {
			fprintf(stderr, "Missing address (header) block\n");
E 6
I 6
D 7
		if (gethead(&addrblock.s_spcl) == 0) {
E 7
I 7
		if (gethead(&addrblock) == 0) {
E 7
D 29
			fprintf(stderr, "Missing address (header) block, ino%u\n", ino);
E 6
			goto eloop;
E 29
I 29
			fprintf(stderr, "Missing address (header) block for %s\n",
D 31
				entry.u_xtrlist.x_name);
E 31
I 31
				entry->x_name);
E 31
			spcl.c_magic = 0;
			goto out;
E 29
		}
D 6
		if (checktype(&addrblock, TS_ADDR) == 0) {
			spcl = addrblock;
			return;
E 6
I 6
D 7
		if (checktype(&addrblock.s_spcl, TS_ADDR) == 0) {
			spcl = addrblock.s_spcl;
E 7
I 7
		if (checktype(&addrblock, TS_ADDR) == 0) {
			spcl = addrblock;
E 7
			goto out;
E 6
		}
E 4
	}
I 6
out:
	if (curblk > 0) {
		(*f1)(buf, (curblk * TP_BSIZE) + size);
		curblk = 0;
	}
E 6
}

/*
I 8
 * The next routines are called during file extraction to
 * put the data into the right form and place.
 */
D 20
#ifndef STANDALONE
E 20
xtrfile(buf, size)
	char	*buf;
	long	size;
{
I 23

E 23
D 20
	if (xwrite(ofile, buf, (int) size) == -1) {
E 20
I 20
	if (write(ofile, buf, (int) size) == -1) {
E 20
D 9
		perror("extract write:");
E 9
I 9
		perror("extract write");
E 9
		done(1);
	}
}

D 9
skip(buf, size)
E 9
I 9
xtrskip(buf, size)
E 9
	char *buf;
	long size;
{
I 23

E 23
I 22
#ifdef lint
	buf = buf;
#endif
E 22
D 20
	if (xseek(ofile, size, 1) == -1) {
E 20
I 20
	if (lseek(ofile, size, 1) == -1) {
E 20
D 9
		perror("extract seek:");
E 9
I 9
		perror("extract seek");
E 9
		done(1);
	}
}
D 9
#endif
E 9

I 9
xtrcvtdir(buf, size)
	struct odirect *buf;
	long size;
{
D 10
	struct direct cvtbuf[BLKING * FRAG * TP_BSIZE / sizeof(struct odirect)];
E 10
I 10
D 14
	struct direct
		cvtbuf[MAXBSIZE / sizeof(struct odirect)];
E 14
E 10
	struct odirect *odp, *edp;
D 14
	struct direct *dp;
E 14
I 14
D 22
	struct direct *dp, cvtbuf;
E 22
I 22
	struct direct cvtbuf;
E 22
E 14
E 9

I 9
	edp = &buf[size / sizeof(struct odirect)];
D 14
	for (odp = buf, dp = cvtbuf; odp < edp; odp++, dp++) 
		dcvt(odp, dp);
	size = size * sizeof(struct direct) / sizeof(struct odirect);
	if (xwrite(ofile, cvtbuf, (int) size) == -1) {
		perror("extract write");
		done(1);
E 14
I 14
	for (odp = buf; odp < edp; odp++) {
		dcvt(odp, &cvtbuf);
		putent(&cvtbuf, xtrfile);
E 14
	}
}

xtrcvtskip(buf, size)
	char *buf;
	long size;
{
I 23

E 23
D 29
	fprintf(stderr, "unallocated block in directory\n");
E 29
I 29
	fprintf(stderr, "unallocated block in directory %s\n",
D 31
		entry.u_xtrlist.x_name);
E 31
I 31
		entry->x_name);
E 31
E 29
D 14
	if (xseek(ofile, size, 1) == -1) {
		perror("extract seek");
		done(1);
	}
E 14
I 14
	xtrskip(buf, size);
E 14
}
I 17

xtrlnkfile(buf, size)
	char	*buf;
	long	size;
{
I 23

E 23
	pathlen += size;
	if (pathlen > MAXPATHLEN) {
		fprintf(stderr, "symbolic link name: %s; too long %d\n",
		    buf, size);
		done(1);
	}
	strcat(lnkbuf, buf);
}

xtrlnkskip(buf, size)
	char *buf;
	long size;
{
I 23

E 23
I 22
#ifdef lint
	buf = buf, size = size;
#endif
E 22
D 29
	fprintf(stderr, "unallocated block in symbolic link\n");
E 29
I 29
	fprintf(stderr, "unallocated block in symbolic link %s\n",
D 31
		entry.u_xtrlist.x_name);
E 31
I 31
		entry->x_name);
E 31
E 29
	done(1);
}
E 17
D 20
#endif
E 20

E 9
D 20
rstrfile(buf, size)
	char *buf;
	long size;
{
	u.u_base = buf;
	u.u_count = size;
	writei(cur_ip);
	if (u.u_error) {
D 9
		perror("restor write:");
E 9
I 9
		perror("restor write");
E 9
		done(1);
	}
}

rstrskip(buf, size)
	char *buf;
	long size;
{
	u.u_offset += size;
}

I 9
rstrcvtdir(buf, size)
	struct odirect *buf;
	long size;
{
D 10
	struct direct cvtbuf[BLKING * FRAG * TP_BSIZE / sizeof(struct odirect)];
E 10
I 10
D 14
	struct direct
		cvtbuf[MAXBSIZE / sizeof(struct odirect)];
E 14
E 10
	struct odirect *odp, *edp;
D 14
	struct direct *dp;
E 14
I 14
	struct direct *dp, cvtbuf;
E 14

	edp = &buf[size / sizeof(struct odirect)];
D 14
	for (odp = buf, dp = cvtbuf; odp < edp; odp++, dp++) 
		dcvt(odp, dp);
	u.u_base = (char *)cvtbuf;
	u.u_count = size * sizeof(struct direct) / sizeof(struct odirect);
	writei(cur_ip);
	if (u.u_error) {
		perror("restor write");
		done(1);
E 14
I 14
	for (odp = buf; odp < edp; odp++) {
		dcvt(odp, &cvtbuf);
		putent(&cvtbuf, rstrfile);
E 14
	}
}

rstrcvtskip(buf, size)
	char *buf;
	long size;
{
	fprintf(stderr, "unallocated block in directory\n");
D 14
	u.u_offset += size;
E 14
I 14
	rstrskip(buf, size);
E 14
}

E 20
E 9
null() {;}

/*
E 8
D 6
 * Do the tape i\/o, dealling with volume changes
E 6
I 6
 * Do the tape i/o, dealing with volume changes
E 6
 * etc..
 */
readtape(b)
D 4
char *b;
E 4
I 4
	char *b;
E 4
{
D 6
	register i;
	struct spcl tmpbuf;
E 6
I 6
D 22
	register int i;
E 22
I 22
	register long i;
E 22
D 7
	union u_spcl tmpbuf;
E 7
I 7
D 23
	struct s_spcl tmpbuf;
E 23
I 23
	struct u_spcl tmpbuf;
E 23
I 21
	char c;
E 21
E 7
E 6

	if (bct >= NTREC) {
		for (i = 0; i < NTREC; i++)
D 6
			((struct spcl *)&tbf[i*BSIZE])->c_magic = 0;
E 6
I 6
			((struct s_spcl *)&tbf[i*TP_BSIZE])->c_magic = 0;
E 6
		bct = 0;
I 24
#ifdef RRESTOR
		if ((i = rmtread(tbf, NTREC*TP_BSIZE)) < 0) {
#else
E 24
D 6
		if ((i = read(mt, tbf, NTREC*BSIZE)) < 0) {
E 6
I 6
		if ((i = read(mt, tbf, NTREC*TP_BSIZE)) < 0) {
I 24
#endif
E 24
E 6
D 4
			printf("Tape read error: inode %u\n", curino);
E 4
I 4
D 21
			perror("Tape read error");
E 21
I 21
D 28
			fprintf(stderr, "Tape read error, continue?");
			do	{
				fprintf(stderr, "[yn]\n");
				c = getchar();
				while (getchar() != '\n')
					/* void */;
			} while (c != 'y' && c != 'n');
E 28
I 28
D 29
			fprintf(stderr, "Tape read error");
E 29
I 29
			fprintf(stderr, "Tape read error while restoring %s\n",
D 31
				entry.u_xtrlist.x_name);
E 31
I 31
				entry->x_name);
E 31
E 29
			if (!yflag) {
D 29
				fprintf(stderr, "continue?");
E 29
I 29
				fprintf(stderr, "continue? ");
E 29
				do	{
D 29
					fprintf(stderr, "[yn]\n");
E 29
I 29
					fprintf(stderr, "[yn] ");
E 29
					c = getchar();
					while (getchar() != '\n')
						/* void */;
				} while (c != 'y' && c != 'n');
				if (c == 'n')
					done(1);
			}
E 28
E 21
E 4
			eflag++;
D 4
			exit(1);
E 4
I 4
D 21
			done(1);
E 21
I 21
D 28
			if (c == 'n')
				done(1);
E 28
			i = NTREC*TP_BSIZE;
D 35
			blkclr(tbf, i);
E 35
I 35
			bzero(tbf, i);
E 35
I 24
#ifdef RRESTOR
			if (rmtseek(i, 1) < 0) {
#else
E 24
I 22
			if (lseek(mt, i, 1) < 0) {
I 24
#endif
E 24
				fprintf(stderr, "continuation failed\n");
				done(1);
			}
E 22
E 21
E 4
		}
		if (i == 0) {
			bct = NTREC + 1;
			volno++;
loop:
			flsht();
I 24
#ifdef RRESTOR
			rmtclose();
#else
E 24
			close(mt);
I 24
#endif
E 24
D 4
			printf("Mount volume %d\n", volno);
E 4
I 4
			fprintf(stderr, "Mount volume %d\n", volno);
E 4
			while (getchar() != '\n')
				;
I 24
#ifdef RRESTOR
			if ((mt = rmtopen(magtape, 0)) == -1) {
#else
E 24
			if ((mt = open(magtape, 0)) == -1) {
I 24
#endif
E 24
D 4
				printf("Cannot open tape!\n");
E 4
I 4
				fprintf(stderr, "Cannot open tape!\n");
E 4
				goto loop;
			}
			if (readhdr(&tmpbuf) == 0) {
D 4
				printf("Not a dump tape.Try again\n");
E 4
I 4
				fprintf(stderr, "Not a dump tape.Try again\n");
E 4
				goto loop;
			}
			if (checkvol(&tmpbuf, volno) == 0) {
D 4
				printf("Wrong tape. Try again\n");
E 4
I 4
				fprintf(stderr, "Wrong tape. Try again\n");
E 4
				goto loop;
			}
			readtape(b);
			return;
		}
	}
D 6
	copy(&tbf[(bct++*BSIZE)], b, BSIZE);
E 6
I 6
D 14
	copy(&tbf[(bct++*TP_BSIZE)], b, TP_BSIZE);
E 14
I 14
D 22
	blkcpy(&tbf[(bct++*TP_BSIZE)], b, TP_BSIZE);
E 22
I 22
D 35
	blkcpy(&tbf[(bct++*TP_BSIZE)], b, (long)TP_BSIZE);
E 35
I 35
	bcopy(&tbf[(bct++*TP_BSIZE)], b, (long)TP_BSIZE);
E 35
E 22
E 14
E 6
}

flsht()
{
I 23

E 23
	bct = NTREC+1;
}

D 14
copy(f, t, s)
D 4
register char *f, *t;
E 4
I 4
	register char *f, *t;
E 14
I 14
D 35
blkcpy(from, to, size)
	char *from, *to;
D 22
	int size;
E 22
I 22
	long size;
E 22
E 14
E 4
{
I 23

E 23
I 22
#ifdef lint
	from = from, to = to, size = size;
#endif
E 22
D 6
	register i;
E 6
I 6
D 14
	register int i;
E 6

	i = s;
	do
		*t++ = *f++;
	while (--i);
E 14
I 14
	asm("	movc3	12(ap),*4(ap),*8(ap)");
E 14
}

I 9
blkclr(buf, size)
	char *buf;
D 22
	int size;
E 22
I 22
	long size;
E 22
{
I 23

E 23
I 22
#ifdef lint
	buf = buf, size = size;
#endif
E 22
	asm("movc5	$0,(r0),$0,8(ap),*4(ap)");
}

E 35
resetmt()
{
	struct mtop tcom;

D 23
	if(dumpnum > 1)
E 23
I 23
	if (dumpnum > 1)
E 23
		tcom.mt_op = MTBSF;
	else
		tcom.mt_op = MTREW;
	tcom.mt_count = 1;
	flsht();
I 24
#ifdef RRESTOR
	if (rmtioctl(tcom.mt_op, 1) == -1) {
		/* kludge for disk dumps */
		rmtseek((long)0, 0);
	}
#else
E 24
	if (ioctl(mt,MTIOCTOP,&tcom) == -1) {
		/* kludge for disk dumps */
		lseek(mt, (long)0, 0);
	}
I 24
#endif
E 24
	if (dumpnum > 1) {
I 24
#ifdef RRESTOR
		rmtioctl(MTFSF, 1);
#else
E 24
		tcom.mt_op = MTFSF;
		tcom.mt_count = 1;
		ioctl(mt,MTIOCTOP,&tcom);
I 24
#endif
E 24
	}
}

E 9
D 7
clearbuf(cp)
D 4
register char *cp;
E 4
I 4
	register char *cp;
E 4
{
D 6
	register i;
E 6
I 6
	register int i;
E 6

	i = BSIZE;
	do
		*cp++ = 0;
	while (--i);
}

E 7
D 8
/*
D 7
 * Put and get the directory entries from the compressed
 * directory file
E 7
I 7
 * Put the directory entries in the directory file
E 7
 */
#ifndef STANDALONE
D 7
putent(cp)
D 4
char	*cp;
E 4
I 4
	char	*cp;
E 7
I 7
putdir(buf, size)
	char *buf;
	int size;
E 8
I 8
checkvol(b, t)
	struct s_spcl *b;
	int t;
E 8
E 7
E 4
{
I 23

E 23
I 7
D 8
	register struct direct *dp;
E 7
D 6
	register i;
E 6
I 6
	register int i;
E 6

D 7
	for (i = 0; i < sizeof(ino_t); i++)
		writec(*cp++);
	for (i = 0; i < DIRSIZ; i++) {
		writec(*cp);
		if (*cp++ == 0)
			return;
	}
	return;
E 7
I 7
	for (dp = (struct direct *)buf, i = 0; i < size; dp++, i += sizeof(*dp))
		if (dp->d_ino != 0)
			putent(dp);
E 7
}

D 7
getent(bf)
D 4
register char *bf;
E 4
I 4
	register char *bf;
E 7
I 7
putent(dp)
	struct direct *dp;
E 7
E 4
{
D 6
	register i;
E 6
I 6
D 7
	register int i;
E 6

	for (i = 0; i < sizeof(ino_t); i++)
		*bf++ = readc();
	for (i = 0; i < DIRSIZ; i++)
		if ((*bf++ = readc()) == 0)
			return;
	return;
E 7
I 7
	fwrite(dp, 1, sizeof(struct direct), df);
	seekpt = ftell(df);
E 7
}

/*
D 6
 * read/write te directory file
E 6
I 6
D 7
 * read/write the directory file
E 6
 */
writec(c)
D 4
char c;
E 4
I 4
	char c;
E 4
{
	drblock[bpt++] = c;
	seekpt++;
	if (bpt >= BSIZE) {
		bpt = 0;
		write(df, drblock, BSIZE);
	}
}

readc()
{
	if (bpt >= BSIZE) {
		nread = read(df, drblock, BSIZE);
		bpt = 0;
	}
	return(drblock[bpt++]);
}

mseek(pt)
D 4
daddr_t pt;
E 4
I 4
	daddr_t pt;
E 4
{
	bpt = BSIZE;
	lseek(df, pt, 0);
}

flsh()
{
	write(df, drblock, bpt+1);
}

/*
E 7
 * search the directory inode ino
 * looking for entry cp
 */
ino_t
search(inum, cp)
D 4
ino_t	inum;
char	*cp;
E 4
I 4
	ino_t	inum;
	char	*cp;
E 4
{
D 6
	register i;
E 6
I 6
	register int i;
I 7
	struct direct dir;
	register struct inotab *itp;
E 7
E 6

D 7
	for (i = 0; i < MAXINO; i++)
		if (inotab[i].t_ino == inum) {
E 7
I 7
	for (itp = inotab[INOHASH(inum)]; itp; itp = itp->t_next)
		if (itp->t_ino == inum)
E 7
			goto found;
E 8
I 8
	if (b->c_volume == t)
		return(1);
E 8
D 7
		}
E 7
	return(0);
D 8
found:
D 7
	mseek(inotab[i].t_seekpt);
E 7
I 7
	fseek(df, itp->t_seekpt, 0);
E 7
	do {
D 7
		getent((char *)&dir);
		if (direq(dir.d_name, "/"))
E 7
I 7
		fread(&dir, 1, sizeof(struct direct), df);
		if (!strncmp(dir.d_name, "/", DIRSIZ))
E 7
			return(0);
D 7
	} while (direq(dir.d_name, cp) == 0);
E 7
I 7
	} while (strncmp(dir.d_name, cp, DIRSIZ));
E 7
	return(dir.d_ino);
E 8
}

D 8
/*
D 4
 * Search the directory tree rooted at inode 2
E 4
I 4
 * Search the directory tree rooted at inode ROOTINO
E 4
 * for the path pointed at by n
 */
psearch(n)
D 4
char	*n;
E 4
I 4
	char	*n;
E 8
I 8
readhdr(b)
	struct s_spcl *b;
E 8
E 4
{
I 23

E 23
D 8
	register char *cp, *cp1;
	char c;

D 4
	ino = 2;
E 4
I 4
	ino = ROOTINO;
E 4
	if (*(cp = n) == '/')
		cp++;
next:
	cp1 = cp + 1;
	while (*cp1 != '/' && *cp1)
		cp1++;
	c = *cp1;
	*cp1 = 0;
	ino = search(ino, cp);
	if (ino == 0) {
		*cp1 = c;
E 8
I 8
	if (gethead(b) == 0)
E 8
		return(0);
D 8
	}
	*cp1 = c;
	if (c == '/') {
		cp = cp1+1;
		goto next;
	}
	return(ino);
E 8
I 8
	if (checktype(b, TS_TAPE) == 0)
		return(0);
	return(1);
E 8
}
D 7

direq(s1, s2)
D 4
register char *s1, *s2;
E 4
I 4
	register char *s1, *s2;
E 4
{
D 6
	register i;
E 6
I 6
	register int i;
E 6

	for (i = 0; i < DIRSIZ; i++)
		if (*s1++ == *s2) {
			if (*s2++ == 0)
				return(1);
		} else
			return(0);
	return(1);
}
E 7
D 8
#endif
E 8

/*
D 4
 * read/write a disk block, be sure to update the buffer
 * cache if needed.
 */
dwrite(bno, b)
daddr_t	bno;
char	*b;
{
	register i;

	for (i = 0; i < NCACHE; i++) {
		if (cache[i].c_bno == bno) {
			copy(b, cache[i].c_block, BSIZE);
			cache[i].c_time = 0;
			break;
		}
		else
			cache[i].c_time++;
	}
	lseek(fi, bno*BSIZE, 0);
	if(write(fi, b, BSIZE) != BSIZE) {
#ifdef STANDALONE
		printf("disk write error %D\n", bno);
#else
		fprintf(stderr, "disk write error %ld\n", bno);
#endif
		exit(1);
	}
}

dread(bno, buf, cnt)
daddr_t bno;
char *buf;
{
	register i, j;

	j = 0;
	for (i = 0; i < NCACHE; i++) {
		if (++curcache >= NCACHE)
			curcache = 0;
		if (cache[curcache].c_bno == bno) {
			copy(cache[curcache].c_block, buf, cnt);
			cache[curcache].c_time = 0;
			return;
		}
		else {
			cache[curcache].c_time++;
			if (cache[j].c_time < cache[curcache].c_time)
				j = curcache;
		}
	}

	lseek(fi, bno*BSIZE, 0);
	if (read(fi, cache[j].c_block, BSIZE) != BSIZE) {
#ifdef STANDALONE
		printf("read error %D\n", bno);
#else
		printf("read error %ld\n", bno);
#endif
		exit(1);
	}
	copy(cache[j].c_block, buf, cnt);
	cache[j].c_time = 0;
	cache[j].c_bno = bno;
}

/*
 * the inode manpulation routines. Like the system.
 *
 * clri zeros the inode
 */
clri(ip)
struct dinode *ip;
{
	int i, *p;
	if (ip->di_mode&IFMT)
		sblock.s_tinode++;
	i = sizeof(struct dinode)/sizeof(int);
	p = (int *)ip;
	do
		*p++ = 0;
	while(--i);
}

/*
 * itrunc/tloop/bfree free all of the blocks pointed at by the inode
 */
itrunc(ip)
register struct dinode *ip;
{
	register i;
	daddr_t bn, iaddr[NADDR];

	if (ip->di_mode == 0)
		return;
	i = ip->di_mode & IFMT;
	if (i != IFDIR && i != IFREG)
		return;
	l3tol(iaddr, ip->di_addr, NADDR);
	for(i=NADDR-1;i>=0;i--) {
		bn = iaddr[i];
		if(bn == 0) continue;
		switch(i) {

		default:
			bfree(bn);
			break;

		case NADDR-3:
			tloop(bn, 0, 0);
			break;

		case NADDR-2:
			tloop(bn, 1, 0);
			break;

		case NADDR-1:
			tloop(bn, 1, 1);
		}
	}
	ip->di_size = 0;
}

tloop(bn, f1, f2)
daddr_t	bn;
int	f1, f2;
{
	register i;
	daddr_t nb;
	union {
		char	data[BSIZE];
		daddr_t	indir[NINDIR];
	} ibuf;

	dread(bn, ibuf.data, BSIZE);
	for(i=NINDIR-1;i>=0;i--) {
		nb = ibuf.indir[i];
		if(nb) {
			if(f1)
				tloop(nb, f2, 0);
			else
				bfree(nb);
		}
	}
	bfree(bn);
}

bfree(bn)
daddr_t	bn;
{
	register i;
	union {
		char	data[BSIZE];
		struct	fblk frees;
	} fbun;
#define	fbuf fbun.frees

	if(sblock.s_nfree >= NICFREE) {
		fbuf.df_nfree = sblock.s_nfree;
		for(i=0;i<NICFREE;i++)
			fbuf.df_free[i] = sblock.s_free[i];
		sblock.s_nfree = 0;
		dwrite(bn, fbun.data);
	}
	sblock.s_free[sblock.s_nfree++] = bn;
	sblock.s_tfree++;
}

/*
 * allocate a block off the free list.
 */
daddr_t
balloc()
{
	daddr_t	bno;
	register i;
	static char zeroes[BSIZE];
	union {
		char	data[BSIZE];
		struct	fblk frees;
	} fbun;
#undef		fbuf
#define		fbuf fbun.frees

	if(sblock.s_nfree == 0 || (bno=sblock.s_free[--sblock.s_nfree]) == 0) {
#ifdef STANDALONE
		printf("Out of space\n");
#else
		fprintf(stderr, "Out of space.\n");
#endif
		exit(1);
	}
	if(sblock.s_nfree == 0) {
		dread(bno, (char * )&fbuf, BSIZE);
		sblock.s_nfree = fbuf.df_nfree;
		for(i=0;i<NICFREE;i++)
			sblock.s_free[i] = fbuf.df_free[i];
	}
	dwrite(bno, zeroes);
	sblock.s_tfree--;
	return(bno);
}

/*
 * map a block number into a block address, ensuring
 * all of the correct indirect blocks are around. Allocate
 * the block requested.
 */
daddr_t
bmap(iaddr, bn)
daddr_t	iaddr[NADDR];
daddr_t	bn;
{
	register i;
	int j, sh;
	daddr_t nb, nnb;
	daddr_t indir[NINDIR];

	/*
	 * blocks 0..NADDR-4 are direct blocks
	 */
	if(bn < NADDR-3) {
		iaddr[bn] = nb = balloc();
		return(nb);
	}

	/*
	 * addresses NADDR-3, NADDR-2, and NADDR-1
	 * have single, double, triple indirect blocks.
	 * the first step is to determine
	 * how many levels of indirection.
	 */
	sh = 0;
	nb = 1;
	bn -= NADDR-3;
	for(j=3; j>0; j--) {
		sh += NSHIFT;
		nb <<= NSHIFT;
		if(bn < nb)
			break;
		bn -= nb;
	}
	if(j == 0) {
		return((daddr_t)0);
	}

	/*
	 * fetch the address from the inode
	 */
	if((nb = iaddr[NADDR-j]) == 0) {
		iaddr[NADDR-j] = nb = balloc();
	}

	/*
	 * fetch through the indirect blocks
	 */
	for(; j<=3; j++) {
		dread(nb, (char *)indir, BSIZE);
		sh -= NSHIFT;
		i = (bn>>sh) & NMASK;
		nnb = indir[i];
		if(nnb == 0) {
			nnb = balloc();
			indir[i] = nnb;
			dwrite(nb, (char *)indir);
		}
		nb = nnb;
	}
	return(nb);
}

/*
E 4
 * read the tape into buf, then return whether or
 * or not it is a header block.
 */
gethead(buf)
D 4
struct spcl *buf;
E 4
I 4
D 6
	struct spcl *buf;
E 6
I 6
D 7
	union u_spcl *buf;
E 7
I 7
	struct s_spcl *buf;
E 7
E 6
E 4
{
I 26
	union u_ospcl {
		char dummy[TP_BSIZE];
		struct	s_ospcl {
			int	c_type;
			time_t	c_date;
			time_t	c_ddate;
			int	c_volume;
			daddr_t	c_tapea;
			ino_t	c_inumber;
			int	c_magic;
			int	c_checksum;
			struct odinode {
				unsigned short odi_mode;
				short	odi_nlink;
				short	odi_uid;
				short	odi_gid;
				off_t	odi_size;
				daddr_t	odi_rdev;
				char	odi_addr[36];
				time_t	odi_atime;
				time_t	odi_mtime;
				time_t	odi_ctime;
			} c_dinode;
			int	c_count;
			char	c_addr[TP_NINDIR];
		} s_ospcl;
	} u_ospcl;
E 26
I 23

E 23
I 6
D 7
	int i;

E 7
E 6
D 26
	readtape((char *)buf);
D 6
	if (buf->c_magic != MAGIC || checksum((int *) buf) == 0)
E 6
I 6
D 7
	if (buf->s_spcl.c_magic != MAGIC || checksum((int *) &buf->s_spcl) == 0)
E 7
I 7
	if (buf->c_magic != MAGIC || checksum((int *)buf) == 0)
E 26
I 26
	if (!cvtflag) {
		readtape((char *)buf);
D 27
		if (buf->c_magic != MAGIC || checksum((int *)buf) == 0)
E 27
I 27
		if (buf->c_magic != NFS_MAGIC || checksum((int *)buf) == 0)
E 27
			return(0);
		return(1);
	}
	readtape((char *)(&u_ospcl.s_ospcl));
D 27
	if (u_ospcl.s_ospcl.c_magic != MAGIC ||
E 27
I 27
D 29
	if (u_ospcl.s_ospcl.c_magic != OFS_MAGIC ||
E 27
	    checksum((int *)(&u_ospcl.s_ospcl)) == 0)
E 26
E 7
E 6
		return(0);
E 29
I 26
D 35
	blkclr((char *)buf, TP_BSIZE);
E 35
I 35
	bzero((char *)buf, TP_BSIZE);
E 35
	buf->c_type = u_ospcl.s_ospcl.c_type;
	buf->c_date = u_ospcl.s_ospcl.c_date;
	buf->c_ddate = u_ospcl.s_ospcl.c_ddate;
	buf->c_volume = u_ospcl.s_ospcl.c_volume;
	buf->c_tapea = u_ospcl.s_ospcl.c_tapea;
	buf->c_inumber = u_ospcl.s_ospcl.c_inumber;
D 27
	buf->c_magic = u_ospcl.s_ospcl.c_magic;
E 27
I 27
D 29
	buf->c_magic = NFS_MAGIC;
E 29
E 27
	buf->c_checksum = u_ospcl.s_ospcl.c_checksum;
I 29
	buf->c_magic = u_ospcl.s_ospcl.c_magic;
E 29
	buf->c_dinode.di_mode = u_ospcl.s_ospcl.c_dinode.odi_mode;
	buf->c_dinode.di_nlink = u_ospcl.s_ospcl.c_dinode.odi_nlink;
	buf->c_dinode.di_uid = u_ospcl.s_ospcl.c_dinode.odi_uid;
	buf->c_dinode.di_gid = u_ospcl.s_ospcl.c_dinode.odi_gid;
	buf->c_dinode.di_size = u_ospcl.s_ospcl.c_dinode.odi_size;
	buf->c_dinode.di_rdev = u_ospcl.s_ospcl.c_dinode.odi_rdev;
	buf->c_dinode.di_atime = u_ospcl.s_ospcl.c_dinode.odi_atime;
	buf->c_dinode.di_mtime = u_ospcl.s_ospcl.c_dinode.odi_mtime;
	buf->c_dinode.di_ctime = u_ospcl.s_ospcl.c_dinode.odi_ctime;
	buf->c_count = u_ospcl.s_ospcl.c_count;
D 35
	blkcpy(u_ospcl.s_ospcl.c_addr, buf->c_addr, TP_NINDIR);
E 35
I 35
	bcopy(u_ospcl.s_ospcl.c_addr, buf->c_addr, TP_NINDIR);
E 35
I 29
	if (u_ospcl.s_ospcl.c_magic != OFS_MAGIC ||
	    checksum((int *)(&u_ospcl.s_ospcl)) == 0)
		return(0);
	buf->c_magic = NFS_MAGIC;
E 29
E 26
	return(1);
}

/*
 * return whether or not the buffer contains a header block
 */
ishead(buf)
D 4
struct spcl *buf;
E 4
I 4
D 6
	struct spcl *buf;
E 6
I 6
D 7
	union u_spcl *buf;
E 7
I 7
	struct s_spcl *buf;
E 7
E 6
E 4
{
I 23

E 23
D 6
	if (buf->c_magic != MAGIC || checksum((int *) buf) == 0)
E 6
I 6
D 7
	if (buf->s_spcl.c_magic != MAGIC || checksum((int *) &buf->s_spcl) == 0)
E 7
I 7
D 26
	if (buf->c_magic != MAGIC || checksum((int *)buf) == 0)
E 26
I 26
D 27
	if (buf->c_magic != MAGIC)
E 27
I 27
	if (buf->c_magic != NFS_MAGIC)
E 27
E 26
E 7
E 6
		return(0);
	return(1);
}

checktype(b, t)
D 4
struct	spcl *b;
int	t;
E 4
I 4
D 6
	struct	spcl *b;
E 6
I 6
D 7
	union u_spcl *b;
E 7
I 7
	struct s_spcl *b;
E 7
E 6
	int	t;
E 4
{
I 23

E 23
D 6
	return(b->c_type == t);
E 6
I 6
D 7
	return(b->s_spcl.c_type == t);
E 7
I 7
	return(b->c_type == t);
E 7
E 6
}

I 9
/*
 * read a bit mask from the tape into m.
 */
D 20
readbits(m)
D 10
	short	*m;
E 10
I 10
	char	*m;
E 20
I 20
readbits(mapp)
	char **mapp;
E 20
E 10
{
	register int i;
I 20
	char	*m;
E 20
E 9

I 9
	i = spcl.c_count;

I 20
	if (*mapp == 0)
D 22
		*mapp = (char *)(calloc(i, (TP_BSIZE/(NBBY/BITS))));
E 22
I 22
		*mapp = (char *)calloc(i, (TP_BSIZE/(NBBY/BITS)));
E 22
	m = *mapp;
E 20
	while (i--) {
		readtape((char *) m);
D 10
		m += (TP_BSIZE/(MLEN/BITS));
E 10
I 10
		m += (TP_BSIZE/(NBBY/BITS));
E 10
	}
	while (gethead(&spcl) == 0)
		;
}

E 9
checksum(b)
D 4
int *b;
E 4
I 4
D 26
	int *b;
E 26
I 26
	register int *b;
E 26
E 4
{
D 6
	register i, j;
E 6
I 6
	register int i, j;
E 6

D 6
	j = BSIZE/sizeof(int);
E 6
I 6
	j = sizeof(union u_spcl) / sizeof(int);
E 6
	i = 0;
	do
		i += *b++;
	while (--j);
	if (i != CHECKSUM) {
D 4
		printf("Checksum error %o\n", i);
E 4
I 4
D 6
		fprintf(stderr, "Checksum error %o\n", i);
E 6
I 6
D 29
		fprintf(stderr, "Checksum error %o, ino %u\n", i, ino);
E 29
I 29
		fprintf(stderr, "Checksum error %o, file %s\n", i,
D 31
			entry.u_xtrlist.x_name);
E 31
I 31
			entry->x_name);
E 31
E 29
E 6
E 4
		return(0);
	}
	return(1);
}

D 8
checkvol(b, t)
D 4
struct spcl *b;
int t;
E 4
I 4
D 6
	struct spcl *b;
E 6
I 6
D 7
	union u_spcl *b;
E 7
I 7
	struct s_spcl *b;
E 7
E 6
	int t;
E 4
{
D 6
	if (b->c_volume == t)
E 6
I 6
D 7
	if (b->s_spcl.c_volume == t)
E 7
I 7
	if (b->c_volume == t)
E 7
E 6
		return(1);
	return(0);
}

readhdr(b)
D 4
struct	spcl *b;
E 4
I 4
D 6
	struct	spcl *b;
E 6
I 6
D 7
	union u_spcl *b;
E 7
I 7
	struct s_spcl *b;
E 7
E 6
E 4
{
	if (gethead(b) == 0)
		return(0);
	if (checktype(b, TS_TAPE) == 0)
		return(0);
	return(1);
}

E 8
/*
I 9
 *	Check for access into each directory in the pathname of an extracted
 *	file and create such a directory if needed in preparation for moving 
 *	the file to its proper home.
 */
checkdir(name)
	register char *name;
{
	register char *cp;
	int i;

	for (cp = name; *cp; cp++) {
D 34
		if (*cp == '/') {
			*cp = '\0';
D 20
			if (xaccess(name, 01) < 0) {
E 20
I 20
			if (access(name, 01) < 0) {
E 20
				register int pid, rp;

D 20
				xumount();
I 17
				mounted = 0;
E 20
E 17
D 30
				if ((pid = fork()) == 0) {
E 30
I 30
				if ((pid = vfork()) == 0) {
E 30
D 20
					execl("/bin/xmkdir", "xmkdir", name, 0);
					execl("/usr/bin/xmkdir", "xmkdir", name, 0);
					execl("./xmkdir", "xmkdir", name, 0);
					fprintf(stderr, "xrestor: cannot find xmkdir!\n");
E 20
I 20
					execl("/bin/mkdir", "mkdir", name, 0);
					execl("/usr/bin/mkdir", "mkdir", name, 0);
					fprintf(stderr, "restor: cannot find mkdir!\n");
E 20
					done(0);
				}
				while ((rp = wait(&i)) >= 0 && rp != pid)
					;
I 17
D 20
				mounted++;
E 17
				xmount(envp);
I 16
				fsptr = getfs(dev);
				parentino.i_fs = fsptr;
E 20
E 16
			}
			*cp = '/';
		}
E 34
I 34
		if (*cp != '/')
			continue;
		*cp = '\0';
		if (access(name, 01) < 0 && mkdir(name, 0777) < 0)
			fprintf(stderr, "restor: "), perror(name);
		*cp = '/';
E 34
	}
I 14
}

I 20
setdir(dev)
	char *dev;
{
	struct fstab *fsp;

	if (setfsent() == 0) {
		fprintf(stderr, "Can't open checklist file: %s\n", FSTAB);
		done(1);
	}
	while ((fsp = getfsent()) != 0) {
		if (strcmp(fsp->fs_spec, dev) == 0) {
D 28
			printf("%s mounted on %s\n", dev, fsp->fs_file);
E 28
I 28
			fprintf(stderr, "%s mounted on %s\n", dev, fsp->fs_file);
E 28
			if (chdir(fsp->fs_file) >= 0)
				return;
			fprintf(stderr, "%s cannot chdir to %s\n",
			    fsp->fs_file);
			done(1);
E 36
I 36
		markremove();
		if ((ino = psearch(".")) == 0 || BIT(ino, dumpmap) == 0)
			panic("Root directory is not on tape\n");
		vprintf(stdout, "Calculate extraction list.\n");
		treescan(".", ino, markfile);
		findunref();
		removeleaves();
		renamenodes();
		createnodes();
		renameleaves();
		removenodes();
E 41
		createleaves(symtbl);
		createlinks();
D 44
		setdirmodes(dirmodefile);
E 44
I 44
		setdirmodes();
E 44
		checkrestore();
		if (dflag) {
			vprintf(stdout, "Verify the directory structure\n");
			treescan(".", ROOTINO, verifyfile);
E 36
		}
D 36
	}
	fprintf(stderr, "%s not mounted\n", dev);
	done(1);
}
E 36
I 36
		dumpsymtable(symtbl, (long)1);
		done(0);
E 36
D 44

E 44
I 44
	/*
	 * Resume an incremental file system restoration.
	 */
E 44
E 20
D 36
/*
 * These variables are "local" to the following two functions.
 */
char dirbuf[DIRBLKSIZ];
long dirloc = 0;
long prev = 0;

/*
 * add a new directory entry to a file.
 */
putent(dp, wrtfunc)
	struct direct *dp;
	int (*wrtfunc)();
{
I 23

E 23
	if (dp->d_ino == 0)
		return;
D 23
	for (;;) {
		if (dp->d_reclen < DIRBLKSIZ - dirloc) {
D 22
			blkcpy(dp, dirbuf + dirloc, dp->d_reclen);
E 22
I 22
			blkcpy((char *)dp, dirbuf + dirloc, (long)dp->d_reclen);
E 22
			prev = dirloc;
			dirloc += dp->d_reclen;
			return;
		}
		((struct direct *)(dirbuf + prev))->d_reclen = DIRBLKSIZ - prev;
E 23
I 23
	if (dirloc + dp->d_reclen > DIRBLKSIZ) {
		((struct direct *)(dirbuf + prev))->d_reclen =
		    DIRBLKSIZ - prev;
E 23
		(*wrtfunc)(dirbuf, DIRBLKSIZ);
		dirloc = 0;
E 36
I 36
	case 'R':
		initsymtable(symtbl);
I 39
		skipmaps();
		skipdirs();
E 39
		createleaves(symtbl);
		createlinks();
D 44
		setdirmodes(dirmodefile);
E 44
I 44
		setdirmodes();
E 44
		checkrestore();
		dumpsymtable(symtbl, (long)1);
		done(0);
I 44
	/*
	 * List contents of tape.
	 */
	case 't':
		setup();
		extractdirs(0);
I 54
		initsymtable((char *)0);
E 54
		while (argc--) {
			canon(*argv++, name);
			ino = dirlookup(name);
			if (ino == 0)
				continue;
			treescan(name, ino, listfile);
		}
		done(0);
	/*
	 * Batch extraction of tape contents.
	 */
	case 'x':
		setup();
		extractdirs(1);
		initsymtable((char *)0);
		while (argc--) {
			canon(*argv++, name);
			ino = dirlookup(name);
			if (ino == 0)
				continue;
			if (mflag)
				pathcheck(name);
			treescan(name, ino, addfile);
		}
		createfiles();
		createlinks();
		setdirmodes();
		if (dflag)
			checkrestore();
		done(0);
E 44
E 36
	}
I 44
}
D 50

/*
 * Read and execute commands from the terminal.
 */
runcmdshell()
{
	register struct entry *np;
	ino_t ino;
	char curdir[MAXPATHLEN];
	char name[MAXPATHLEN];
	char cmd[BUFSIZ];

	canon("/", curdir);
loop:
	getcmd(curdir, cmd, name);
	switch (cmd[0]) {
	/*
	 * Add elements to the extraction list.
	 */
	case 'a':
		ino = dirlookup(name);
		if (ino == 0)
			break;
		if (mflag)
			pathcheck(name);
		treescan(name, ino, addfile);
		break;
	/*
	 * Change working directory.
	 */
	case 'c':
		ino = dirlookup(name);
		if (ino == 0)
			break;
		if (inodetype(ino) == LEAF) {
			fprintf(stderr, "%s: not a directory\n", name);
			break;
		}
		(void) strcpy(curdir, name);
		break;
	/*
	 * Delete elements from the extraction list.
	 */
	case 'd':
		np = lookupname(name);
		if (np == NIL || (np->e_flags & NEW) == 0) {
			fprintf(stderr, "%s: not on extraction list\n", name);
			break;
		}
		treescan(name, np->e_ino, deletefile);
		break;
	/*
	 * Extract the requested list.
	 */
	case 'e':
		createfiles();
		createlinks();
		setdirmodes();
		if (dflag)
			checkrestore();
		volno = 0;
		break;
	/*
	 * List available commands.
	 */
	case 'h':
	case '?':
		fprintf(stderr, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			"Available commands are:\n",
			"\tls [arg] - list directory\n",
			"\tcd arg - change directory\n",
			"\tpwd - print current directory\n",
			"\tadd [arg] - add `arg' to list of",
			" files to be extracted\n",
			"\tdelete [arg] - delete `arg' from",
			" list of files to be extracted\n",
			"\textract - extract requested files\n",
			"\tquit - immediately exit program\n",
			"\tverbose - toggle verbose flag",
			" (useful with ``ls'')\n",
			"\thelp or `?' - print this list\n",
			"If no `arg' is supplied, the current",
			" directory is used\n");
		break;
	/*
	 * List a directory.
	 */
	case 'l':
		ino = dirlookup(name);
		if (ino == 0)
			break;
		printlist(name, ino);
		break;
	/*
	 * Print current directory.
	 */
	case 'p':
		if (curdir[1] == '\0')
			fprintf(stderr, "/\n");
		else
			fprintf(stderr, "%s\n", &curdir[1]);
		break;
	/*
	 * Quit.
	 */
	case 'q':
I 46
	case 'x':
E 46
		return;
	/*
	 * Toggle verbose mode.
	 */
	case 'v':
		if (vflag) {
			fprintf(stderr, "verbose mode off\n");
			vflag = 0;
			break;
		}
		fprintf(stderr, "verbose mode on\n");
		vflag++;
		break;
	/*
I 48
	 * Just restore requested directory modes.
	 */
	case 'R':
		setdirmodes();
		break;
	/*
E 48
I 45
	 * Turn on debugging.
	 */
	case 'D':
		if (dflag) {
			fprintf(stderr, "debugging mode off\n");
			dflag = 0;
			break;
		}
		fprintf(stderr, "debugging mode on\n");
		dflag++;
		break;
	/*
E 45
	 * Unknown command.
	 */
	default:
		fprintf(stderr, "%s: unknown command; type ? for help\n", cmd);
		break;
	}
	goto loop;
E 44
I 23
D 35
	blkcpy((char *)dp, dirbuf + dirloc, (long)dp->d_reclen);
E 35
I 35
D 36
	bcopy((char *)dp, dirbuf + dirloc, (long)dp->d_reclen);
E 35
	prev = dirloc;
	dirloc += dp->d_reclen;
E 23
}

/*
 * flush out a directory that is finished.
 */
flushent(wrtfunc)
	int (*wrtfunc)();
{
I 23

E 23
	((struct direct *)(dirbuf + prev))->d_reclen = DIRBLKSIZ - prev;
	(*wrtfunc)(dirbuf, dirloc);
	dirloc = 0;
}

dirwrite(buf, size)
	char *buf;
	int size;
{
I 23

E 23
	fwrite(buf, 1, size, df);
	seekpt = ftell(df);
}

dcvt(odp, ndp)
	register struct odirect *odp;
	register struct direct *ndp;
{
I 23

E 23
D 22
	struct inotab *itp;

	blkclr(ndp, sizeof *ndp);
E 22
I 22
D 35
	blkclr((char *)ndp, (long)(sizeof *ndp));
E 35
I 35
	bzero((char *)ndp, (long)(sizeof *ndp));
E 35
E 22
	ndp->d_ino =  odp->d_ino;
	strncpy(ndp->d_name, odp->d_name, ODIRSIZ);
	ndp->d_namlen = strlen(ndp->d_name);
	ndp->d_reclen = DIRSIZ(ndp);
	/*
	 * this quickly calculates if this inode is a directory.
	 * Currently not maintained.
	 *
	for (itp = inotab[INOHASH(odp->d_ino)]; itp; itp = itp->t_next) {
		if (itp->t_ino != odp->d_ino)
			continue;
		ndp->d_fmt = IFDIR;
		break;
	}
	 */
}

/*
D 17
 * seek to an entry in a directory.
E 17
I 17
 * Open a directory.
 * Modified to allow any random file to be a legal directory.
 */
DIR *
opendir(name)
	char *name;
{
	register DIR *dirp;

	dirp = (DIR *)malloc(sizeof(DIR));
	dirp->dd_fd = open(name, 0);
	if (dirp->dd_fd == -1) {
D 22
		free(dirp);
E 22
I 22
		free((char *)dirp);
E 22
		return NULL;
	}
	dirp->dd_loc = 0;
	return dirp;
}

/*
 * Seek to an entry in a directory.
E 17
 * Only values returned by ``telldir'' should be passed to seekdir.
 * Modified to have many directories based in one file.
 */
void
seekdir(dirp, loc, base)
	register DIR *dirp;
D 22
	long loc, base;
E 22
I 22
	daddr_t loc, base;
E 22
{
I 23

E 23
	if (loc == telldir(dirp))
		return;
	loc -= base;
	if (loc < 0)
		fprintf(stderr, "bad seek pointer to seekdir %d\n", loc);
D 22
	lseek(dirp->dd_fd, base + (loc & ~(DIRBLKSIZ - 1)), 0);
E 22
I 22
	(void)lseek(dirp->dd_fd, base + (loc & ~(DIRBLKSIZ - 1)), 0);
E 22
	dirp->dd_loc = loc & (DIRBLKSIZ - 1);
	if (dirp->dd_loc != 0)
		dirp->dd_size = read(dirp->dd_fd, dirp->dd_buf, DIRBLKSIZ);
E 14
}

/*
E 9
D 8
 * The next routines are called during file extraction to
 * put the data into the right form and place.
 */
#ifndef STANDALONE
D 4
xtrfile(b, size)
char	*b;
long	size;
E 4
I 4
xtrfile(buf, size)
	char	*buf;
	long	size;
E 4
{
D 4
	write(ofile, b, (int) size);
E 4
I 4
D 7
	xwrite(ofile, buf, (int) size);
E 7
I 7
	if (xwrite(ofile, buf, (int) size) == -1) {
		perror("extract write:");
		done(1);
	}
E 7
E 4
}

null() {;}

D 4
skip()
E 4
I 4
skip(buf, size)
	char *buf;
	long size;
E 4
{
D 4
	lseek(ofile, (long) BSIZE, 1);
E 4
I 4
D 7
	xseek(ofile, size, 1);
E 7
I 7
	if (xseek(ofile, size, 1) == -1) {
		perror("extract seek:");
		done(1);
	}
E 7
E 4
}
#endif


D 4
rstrfile(b, s)
char *b;
long s;
E 4
I 4
rstrfile(buf, size)
	char *buf;
	long size;
E 4
{
D 4
	daddr_t d;
E 4
I 4
	u.u_base = buf;
	u.u_count = size;
	writei(cur_ip);
I 7
	if (u.u_error) {
		perror("restor write:");
		done(1);
	}
E 7
}
E 4

D 4
	d = bmap(taddr, curbno);
	dwrite(d, b);
	curbno += 1;
E 4
I 4
rstrskip(buf, size)
	char *buf;
	long size;
{
	u.u_offset += size;
E 4
}

D 4
rstrskip(b, s)
char *b;
long s;
E 4
I 4
/*
E 8
D 20
 * tell whether an inode is allocated
 * this is drawn from ialloccg in sys/alloc.c
E 20
I 20
 * get next entry in a directory.
E 20
 */
D 16
iexist(dev, ino)
	dev_t dev;
E 16
I 16
D 20
iexist(ip, ino)
	struct inode *ip;
E 16
	ino_t ino;
E 20
I 20
struct direct *
readdir(dirp)
	register DIR *dirp;
E 20
E 4
{
D 4
	curbno += 1;
E 4
I 4
D 20
	register struct fs *fs;
	register struct cg *cgp;
	register struct buf *bp;
	int cg;
E 20
I 20
	register struct direct *dp;
E 20

D 16
	fs = getfs(dev);
E 16
I 16
D 20
	fs = ip->i_fs;
E 16
	if ((unsigned)ino >= fs->fs_ipg*fs->fs_ncg)
		return (0);
D 13
	cg = itog(ino, fs);
D 10
	bp = bread(dev, cgtod(cg, fs), BSIZE);
E 10
I 10
	bp = bread(dev, fsbtodb(fs, cgtod(cg, fs)), fs->fs_bsize);
E 13
I 13
	cg = itog(fs, ino);
D 16
	bp = bread(dev, fsbtodb(fs, cgtod(fs, cg)), fs->fs_bsize);
E 16
I 16
	bp = bread(ip->i_dev, fsbtodb(fs, cgtod(fs, cg)), fs->fs_bsize);
E 16
E 13
E 10
D 15
	if (bp->b_flags & B_ERROR)
E 15
I 15
	if (bp->b_flags & B_ERROR) {
		brelse(bp);
E 15
		return(0);
E 20
I 20
	for (;;) {
		if (dirp->dd_loc == 0) {
			dirp->dd_size = read(dirp->dd_fd, dirp->dd_buf, 
			    DIRBLKSIZ);
			if (dirp->dd_size <= 0)
				return NULL;
		}
		if (dirp->dd_loc >= dirp->dd_size) {
			dirp->dd_loc = 0;
			continue;
		}
		dp = (struct direct *)(dirp->dd_buf + dirp->dd_loc);
		if (dp->d_reclen <= 0 ||
		    dp->d_reclen > DIRBLKSIZ + 1 - dirp->dd_loc)
			return NULL;
		dirp->dd_loc += dp->d_reclen;
		if (dp->d_ino == 0)
			continue;
		return (dp);
E 20
I 15
	}
E 15
D 20
	cgp = bp->b_un.b_cg;
	ino %= fs->fs_ipg;
	if (isclr(cgp->cg_iused, ino)) {
		brelse(bp);
		return(0);
	}
	brelse(bp);
	return (1);
E 20
E 4
}

D 7
#ifndef STANDALONE
D 4
putdir(b)
char *b;
E 4
I 4
putdir(buf, size)
	char *buf;
	int size;
E 4
{
	register struct direct *dp;
D 6
	register i;
E 6
I 6
	register int i;
E 6

D 4
	for (dp = (struct direct *) b, i = 0; i < BSIZE; dp++, i += sizeof(*dp)) {
E 4
I 4
	for (dp = (struct direct *) buf, i = 0; i < size; dp++, i += sizeof(*dp)) {
E 4
		if (dp->d_ino == 0)
			continue;
		putent((char *) dp);
	}
}
#endif

E 7
D 9
/*
D 4
 * read/write an inode from the disk
 */
getdino(inum, b)
ino_t	inum;
struct	dinode *b;
{
	daddr_t	bno;
	char buf[BSIZE];

	bno = (ino - 1)/INOPB;
	bno += 2;
	dread(bno, buf, BSIZE);
	copy(&buf[((inum-1)%INOPB)*sizeof(struct dinode)], (char *) b, sizeof(struct dinode));
}

putdino(inum, b)
ino_t	inum;
struct	dinode *b;
{
	daddr_t bno;
	char buf[BSIZE];
	if (b->di_mode&IFMT)
		sblock.s_tinode--;

	bno = ((ino - 1)/INOPB) + 2;
	dread(bno, buf, BSIZE);
	copy((char *) b, &buf[((inum-1)%INOPB)*sizeof(struct dinode)], sizeof(struct dinode));
	dwrite(bno, buf);
}

/*
E 4
 * read a bit mask from the tape into m.
 */
readbits(m)
D 4
short	*m;
E 4
I 4
	short	*m;
E 4
{
D 6
	register i;
E 6
I 6
	register int i;
E 6

	i = spcl.c_count;

	while (i--) {
		readtape((char *) m);
D 6
		m += (BSIZE/(MLEN/BITS));
E 6
I 6
		m += (TP_BSIZE/(MLEN/BITS));
E 6
	}
	while (gethead(&spcl) == 0)
		;
}

D 4
done()
E 4
I 4
done(exitcode)
	int exitcode;
E 4
{
#ifndef STANDALONE
	unlink(dirfile);
#endif
D 4
	exit(0);
E 4
I 4
	if (mounted)
		xumount();
	exit(exitcode);
E 4
}

E 9
D 7
stcopy( sourcep, destp, max )
D 4
char *sourcep, *destp;
int max;
E 4
I 4
	char *sourcep, *destp;
	int max;
E 7
I 7
D 8
struct inotab *
getinotab(ino)
E 8
I 8
allocinotab(ino, seekpt)
E 8
	ino_t ino;
I 8
	daddr_t seekpt;
E 8
E 7
E 4
{
D 7
	int i;
E 7
I 7
	register struct inotab	*itp;
E 7
D 6
	for( i=1; i<=max && (*destp++ = *sourcep++); i++ )
E 6
I 6

D 7
	for( i = 1; i <= max && (*destp++ = *sourcep++); i++ )
E 6
		;
	if( i > max )	return( 0 );
	else		return( 1 );
E 7
I 7
	itp = (struct inotab *)calloc(1, sizeof(struct inotab));
	itp->t_next = inotab[INOHASH(ino)];
	inotab[INOHASH(ino)] = itp;
	itp->t_ino = ino;
D 8
	return itp;
E 8
I 8
	itp->t_seekpt = seekpt;
E 8
E 7
}

I 31
struct xtrlist *
E 31
D 7
append( sourcep, destp, max )
D 4
char *sourcep, *destp;
int max;
E 4
I 4
	char *sourcep, *destp;
	int max;
E 7
I 7
D 8
struct xtrlist *
getxtr(ino)
E 8
I 8
allocxtr(ino, name, flags)
E 8
	ino_t ino;
I 8
	char *name;
	char flags;
E 8
E 7
E 4
{
D 7
	int i;
E 7
I 7
D 8
	struct xtrlist	*xp;
E 8
I 8
	register struct xtrlist	*xp, *pxp;
I 29
	int size;
E 29
E 8
E 7
I 6

E 6
D 7
	for( i=0; *destp; i++ )
		*destp++;
	if( ++i <= max ) *destp++ = '/';
	while( ++i<=max && (*destp++ = *sourcep++) )
		;
	if( i > max )	return( 0 );
	else		return( 1 );
E 7
I 7
D 8
	xp = (struct xtrlist *)calloc(1, sizeof(struct xtrlist));
E 8
I 8
D 29
	xp = (struct xtrlist *)calloc(1, sizeof(struct xtrlist) + strlen(name));
E 29
I 29
	size = sizeof(struct xtrlist) + strlen(name);
D 31
	if (maxentry < size)
		maxentry = size;
	if (maxino < ino)
		maxino = ino;
E 31
	xp = (struct xtrlist *)calloc(1, size);
D 31
	xp->x_self = xp;
E 29
E 8
	xp->x_next = xtrlist[INOHASH(ino)];
	xtrlist[INOHASH(ino)] = xp;
E 31
	xp->x_ino = ino;
I 31
	xp->x_flags = flags;
E 31
I 8
	strcpy(xp->x_name, name);
I 31
	if (flags == 0)
		return (xp);
	xp->x_next = xtrlist[INOHASH(ino)];
	xtrlist[INOHASH(ino)] = xp;
E 31
E 8
	xtrcnt++;
D 8
	return xp;
E 8
I 8
D 31
	xp->x_flags = flags;
E 31
	for (pxp = xp->x_next; pxp; pxp = pxp->x_next)
		if (pxp->x_ino == ino && (pxp->x_flags & XLINKED) == 0) {
			xp->x_flags |= XLINKED;
			xp->x_linkedto = pxp;
			xtrcnt--;
			break;
		}
I 28
D 35
	if (!vflag)
E 35
I 35
	if (!vflag && !tflag)
E 35
D 31
		return;
E 31
I 31
		return (xp);
E 31
E 28
	if (xp->x_flags & XLINKED)
		fprintf(stdout, "%s: linked to %s\n", xp->x_name, pxp->x_name);
	else if (xp->x_flags & XISDIR)
		fprintf(stdout, "%s: directory inode %u\n", xp->x_name, ino);
	else
		fprintf(stdout, "%s: inode %u\n", xp->x_name, ino);
I 31
	return (xp);
E 31
E 8
E 7
}
D 7
/*
 *	Truncate the rightmost file or directory name from a pathname      
 */
E 7

I 31
#ifdef RRESTOR
msg(cp, a1, a2, a3)
	char *cp;
{

	fprintf(stderr, cp, a1, a2, a3);
}
#endif RRESTOR

E 31
D 7
trunc( cp )
D 4
char *cp;
E 4
I 4
	char *cp;
E 4
{
	char *lstslsh;
	lstslsh = 0;
	while( *cp++ )
		if( *cp == '/' ) lstslsh = cp;
	if( lstslsh == 0 )
		return( 0 );
	else {
		*lstslsh = '\0';
		return( 1 );
	}
}
getxtrlist() {
	struct xtrlist	*malloc(),
			*realloc();

	if( init ) {
		init = 0;
		xtrlist = malloc( SIZEINC*sizeof(struct xtrlist) );
		xsize = SIZEINC;
	}
	else {
		xtrlist = realloc( xtrlist, (SIZEINC+xsize) *
						sizeof(struct xtrlist) );
		xsize += SIZEINC;
	}

}

E 7
D 9
/*
 *	Check for access into each directory in the pathname of an extracted
 *	file and create such a directory if needed in preparation for moving 
 *	the file to its proper home.
 */
checkdir(name)
D 4
register char *name;
E 4
I 4
	register char *name;
E 9
I 9
done(exitcode)
	int exitcode;
E 9
E 4
{
I 23

E 23
D 9
	register char *cp;
	int i;
I 6

E 6
	for (cp = name; *cp; cp++) {
		if (*cp == '/') {
			*cp = '\0';
D 4
			if (access(name, 01) < 0) {
E 4
I 4
			if (xaccess(name, 01) < 0) {
E 4
				register int pid, rp;

I 4
				xumount();
E 4
				if ((pid = fork()) == 0) {
D 4
					execl("/bin/mkdir", "mkdir", name, 0);
					execl("/usr/bin/mkdir", "mkdir", name, 0);
					fprintf(stderr, "tar: cannot find mkdir!\n");
E 4
I 4
					execl("/bin/xmkdir", "xmkdir", name, 0);
					execl("/usr/bin/xmkdir", "xmkdir", name, 0);
					execl("./xmkdir", "xmkdir", name, 0);
					fprintf(stderr, "xrestor: cannot find xmkdir!\n");
E 4
					done(0);
				}
				while ((rp = wait(&i)) >= 0 && rp != pid)
					;
D 4
				chown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 4
I 4
				xmount(envp);
D 7
				xchown(name, spcl.c_dinode.di_uid, spcl.c_dinode.di_gid);
E 7
E 4
			}
			*cp = '/';
		}
	}
E 9
I 9
D 20
#ifndef STANDALONE
E 20
	unlink(dirfile);
I 29
D 31
#ifdef notdef
	/* should decide what to do with this file */
	unlink(entryfile);
#endif notdef
E 31
E 29
D 20
#endif
D 17
	if (mounted)
E 17
I 17
	if (mounted) {
E 17
		xumount();
I 17
		mounted = 0;
	}
E 20
E 17
	exit(exitcode);
E 36
E 9
D 8
}

/*
 *	Store a string in core returning a pointer to it.  Allocate space
 *	as needed.
 */
char *
ststore( stringp )
D 4
char *stringp;
E 4
I 4
	char *stringp;
E 4
{
	static char *spacep;
	static int spaceleft;
	char *rtnp, *savep;

	rtnp = spacep;
	savep = stringp;
	while( spaceleft-- && (*spacep++ = *stringp++) );
	if( spaceleft >= 0 )
		return( rtnp );
	else {
D 7
		spaceleft = 10 * NSIZE;
E 7
I 7
		spaceleft = 10 * BUFSIZ;
E 7
		spacep = (char *)malloc( spaceleft );
		return( ststore(savep) );
	}
}

/*
 *	Recursively find names and inumbers of all files in subtree 
 *	pname and put them in xtrlist[]
 */
D 7
getleaves( pname )
E 7
I 7
getleaves(ino, pname)
	ino_t ino;
E 7
D 4
char *pname;
E 4
I 4
	char *pname;
E 4
{
I 6
D 7
	static int xtrcnt = 0;	/* number of entries to extract */
E 6
	int 	n, 		/* loop counter */
		bptsave, 	/* placeholder for pointer into drblock */
		readsize;	/* nbytes read into drblock at cur level
				   of recursion */
	char 	locname[NSIZE];	/* pname + an entry from drblock */
	daddr_t dptsave, 	/* disk loc where cur drblock came from */
		disk_loc;	/* used to see if getent() causes a phys read */
	ino_t 	d;		/* inode no of pname */
E 7
I 7
	register struct xtrlist *xp, *pxp;
	register struct inotab *itp;
	int namelen;
	daddr_t	bpt;
	char 	locname[BUFSIZ];
	struct direct dir;
E 7

D 7
	stcopy( pname, locname, NSIZE );
	if( (d = psearch(locname)) == 0 || BIT( d, dumpmap) == 0 ) {
D 4
		printf("%s: not on the tape\n", locname );
E 4
I 4
		fprintf(stderr, "%s: not on the tape\n", locname );
E 7
I 7
	if (BIT(ino, dumpmap) == 0) {
		fprintf(stderr, "%s: not on the tape\n", pname);
E 7
E 4
		return;
	}
D 7

	for( n=0; n<MAXINO; n++ ) {
		if( inotab[n].t_ino == d ) {
E 7
I 7
	for (itp = inotab[INOHASH(ino)]; itp; itp = itp->t_next) {
		if (itp->t_ino != ino)
			continue;
		/*
		 * pname is a directory name 
		 */
		xp = getxtr(ino);
		xp->x_flags |= (XINUSE | XISDIR);
		xp->x_name = ststore(pname);
		if (vflag)
			fprintf(stderr, "%s: directory inode %u\n", pname, ino);
		/*
		 * begin search through the directory
		 * skipping over "." and ".."
		 */
		strncpy(locname, pname, BUFSIZ);
		strncat(locname, "/", BUFSIZ);
		namelen = strlen(locname);
		bpt = itp->t_seekpt;
		fseek(df, bpt, 0);
		fread(&dir, 1, sizeof(struct direct), df);
		fread(&dir, 1, sizeof(struct direct), df);
		fread(&dir, 1, sizeof(struct direct), df);
		bpt = ftell(df);
		/*
		 * "/" signals end of directory
		 */
		while (strncmp(dir.d_name, "/", DIRSIZ)) {
			locname[namelen] = '\0';
			strncat(locname, dir.d_name, DIRSIZ);
			if (strlen(locname) >= BUFSIZ) {
				fprintf(stderr, "%s: name exceedes %d char\n",
					locname, BUFSIZ);
				continue;
			}
E 7
			/*
D 7
			 * locname is a directory name 
E 7
I 7
			 * info for rereading drblock later
E 7
			 */
D 7
				/* phys disk read forced so reset readsize */
			mseek( inotab[n].t_seekpt);
			getent( (char *)&dir );
			readsize = nread;
	
				/* "/" signals end of directory */
			while( !direq(dir.d_name,"/") ) {

				if( direq(dir.d_name,".") ) {
					getent( (char *)&dir );
					continue;
				}

				if( direq(dir.d_name,"..") ) {
					getent( (char *)&dir );
					continue;
				}

				if( append(dir.d_name,locname,NSIZE) == 0 ) {
D 4
					printf("name exceedes %d char\n",NSIZE);
E 4
I 4
					fprintf(stderr, "name exceedes %d char\n",NSIZE);
E 4
					continue;
				}

					/* info for rereading drblock later */
				dptsave = lseek( df, 0L, 1 ) - readsize;
				bptsave = bpt;

				getleaves( locname );
	
					/* reread drblock after recursion rtn */
				lseek( df, dptsave, 0 );
				read( df, drblock, BSIZE );
				bpt = bptsave;

				if( trunc(locname) == 0 ) {
D 4
					printf( "Trouble with name trunc\n" );
E 4
I 4
					fprintf(stderr,  "Trouble with name trunc\n" );
E 4
					abort();
				}
					/* get next entry from drblock; reset
					 * readsize iff physical disk read */
				disk_loc = lseek( df, 0L, 1 );
				getent( (char *)&dir );
				if( lseek(df,0L,1) != disk_loc )
					readsize = nread;
			}
			return;
E 7
I 7
			getleaves(dir.d_ino, locname);
			/*
			 * get next entry from drblock; reset
			 * readsize iff physical disk read
			 */
			fseek(df, bpt, 0);
			fread(&dir, 1, sizeof(struct direct), df);
			bpt = ftell(df);
E 7
		}
I 7
		return;
E 7
	}
	/*
	 * locname is name of a simple file 
	 */
D 6
	xtrlist[i].x_ino = d;
	xtrlist[i].x_flags |= XINUSE;
	xtrlist[i].x_name = (char *)ststore( locname );
	if( ++i >= xsize ) getxtrlist();
E 6
I 6
D 7
	xtrlist[xtrcnt].x_ino = d;
	xtrlist[xtrcnt].x_flags |= XINUSE;
	xtrlist[xtrcnt].x_name = (char *)ststore( locname );
	for (n = 0; n < xtrcnt; n++)
		if (xtrlist[n].x_ino == d) {
			xtrlist[xtrcnt].x_flags |= LINKED;
			xtrlist[xtrcnt].x_linkedto = n;
E 7
I 7
	xp = getxtr(ino);
	xp->x_flags |= XINUSE;
	xp->x_name = ststore(pname);
	for (pxp = xp->x_next; pxp; pxp = pxp->x_next)
		if (pxp->x_ino == ino && (pxp->x_flags & XLINKED) == 0) {
			xp->x_flags |= XLINKED;
			xp->x_linkedto = pxp;
			break;
E 7
		}
D 7
	if( ++xtrcnt >= xsize ) getxtrlist();
E 6
D 4
	printf( "%s: inode %u\n", locname, d );
E 4
I 4
	fprintf(stderr,  "%s: inode %u\n", locname, d );
E 4

E 7
I 7
	if (!vflag)
		return;
	if (xp->x_flags & XLINKED)
		fprintf(stderr, "%s: linked to %s\n", xp->x_name, pxp->x_name);
	else
		fprintf(stderr, "%s: inode %u\n", xp->x_name, ino);
E 8
E 7
}
E 50
D 7


E 7
E 1
