h42762
s 00010/00000/01088
d D 5.14 88/05/13 14:47:47 mckusick 43 42
c add Nflag to request not to do any writes
e
s 00001/00001/01087
d D 5.13 88/02/22 14:30:07 mckusick 42 41
c spelling error
e
s 00002/00001/01086
d D 5.12 87/12/26 12:05:23 bostic 41 40
c fix extern declarations for ANSI C
e
s 00002/00001/01085
d D 5.11 87/09/04 17:00:44 mckusick 40 39
c List epoch time as "the epoch" 4.3BSD/etc/86
e
s 00002/00003/01084
d D 5.10 87/01/28 15:18:23 mckusick 39 38
c backward compatibility
e
s 00001/00001/01086
d D 5.9 86/11/25 14:32:39 mckusick 38 37
c better heuristic
e
s 00028/00011/01059
d D 5.8 86/10/21 16:34:12 mckusick 37 36
c use the new header information
e
s 00014/00001/01056
d D 5.7 86/10/21 15:35:12 mckusick 36 35
c must avoid bogus dump headers when resynchronizing
e
s 00005/00000/01052
d D 5.6 86/05/02 11:04:55 mckusick 35 34
c ignore sockets gracefully
e
s 00071/00007/00981
d D 5.5 86/03/26 23:16:48 sklower 34 33
c Restore sun and cci tapes
e
s 00001/00001/00987
d D 5.4 85/10/14 15:37:48 mckusick 33 32
c double diction (from helge@nta-vax)
e
s 00006/00001/00982
d D 5.3 85/07/13 21:15:33 mckusick 32 31
c account for dumps taken on systems with fragment size greater than TP_BSIZE;
c the inode size may be small, but dump includes the whole fragment causing
c bogus resync messages. (from arizona!noao!rwolff (Richard Wolff))
e
s 00001/00001/00982
d D 5.2 85/06/18 21:11:58 mckusick 31 30
c dumprestor.h moves to /usr/include/protocols
e
s 00008/00004/00975
d D 5.1 85/05/28 15:16:25 dist 30 29
c Add copyright
e
s 00009/00009/00970
d D 3.28 85/04/23 16:10:45 mckusick 29 28
c don't forget partial reads on pipes
e
s 00108/00056/00871
d D 3.27 85/03/24 18:09:18 mckusick 28 27
c dynamically calculate tape block size unless specified on command line
e
s 00018/00011/00909
d D 3.26 85/02/18 18:50:32 mckusick 27 26
c allow a new input source to be specified for each new volume
e
s 00003/00001/00917
d D 3.25 85/01/18 22:14:59 mckusick 26 25
c reset longjmp flag when restarting extraction
e
s 00008/00003/00910
d D 3.24 85/01/14 17:46:00 mckusick 25 24
c don't give up when /dev/tty cannot be opened unless it must be read
e
s 00015/00009/00898
d D 3.23 85/01/14 16:06:28 mckusick 24 23
c add 'b' flag to set number of tape records
e
s 00007/00011/00900
d D 3.22 83/12/30 00:41:17 mckusick 23 22
c insure that fssize is initialized; use utility routine `linkit'
e
s 00002/00002/00909
d D 3.21 83/08/11 23:06:57 sam 22 21
c standardize sccs keyword lines
e
s 00001/00001/00910
d D 3.20 83/07/01 03:10:39 sam 21 20
c include fixes
e
s 00032/00002/00879
d D 3.19 83/06/19 18:37:22 mckusick 20 19
c clarify options availble when asked which volume to use next
e
s 00001/00001/00880
d D 3.18 83/06/02 17:06:34 sam 19 18
c file.h updated
e
s 00024/00018/00857
d D 3.17 83/05/19 01:22:32 mckusick 18 17
c use perror everywhere; lint
e
s 00003/00005/00872
d D 3.16 83/05/14 16:46:08 mckusick 17 16
c set "terminal" to stdin when doing rrestore
e
s 00003/00002/00874
d D 3.15 83/05/06 17:47:43 mckusick 16 15
c have to save the result of ctime()
e
s 00002/00002/00874
d D 3.14 83/05/06 00:17:54 mckusick 15 14
c get rid of "restor" in an error message!!!
e
s 00006/00004/00870
d D 3.13 83/05/03 23:41:59 mckusick 14 13
c always print times with "t" command; 
c be more specific about why volumes are unacceptable.
e
s 00019/00034/00855
d D 3.12 83/04/19 02:08:51 mckusick 13 12
c create a file descriptor for the terminal when stdin is used for pipe
e
s 00007/00004/00882
d D 3.11 83/04/18 13:10:52 mckusick 12 10
c lint from new lint library
e
s 00007/00004/00882
d R 3.11 83/04/17 19:47:35 mckusick 11 10
c new lint library
e
s 00008/00007/00878
d D 3.10 83/03/27 19:55:49 mckusick 10 9
c read maps properly
e
s 00036/00036/00849
d D 3.9 83/03/27 18:34:39 mckusick 9 8
c lint; fix bug in multi-dump tapes
e
s 00001/00000/00884
d D 3.8 83/03/08 13:38:44 mckusick 8 7
c get 'r' and 'R' commands working
e
s 00010/00008/00874
d D 3.7 83/03/06 17:43:31 mckusick 7 6
c lint
e
s 00055/00039/00827
d D 3.6 83/03/05 16:18:26 mckusick 6 5
c fix debugging across tapes; account for dumpmap at start of every tape
e
s 00027/00013/00839
d D 3.5 83/02/28 00:39:33 mckusick 5 4
c clean up interface with getvol() and findinode()
e
s 00049/00005/00803
d D 3.4 83/02/27 16:31:01 mckusick 4 3
c get input from a pipe to work
e
s 00006/00010/00802
d D 3.3 83/02/27 14:39:57 mckusick 3 2
c get "x" command working
e
s 00197/00110/00615
d D 3.2 83/02/26 18:26:52 mckusick 2 1
c get the tape subsystem working; get "t" command working
e
s 00725/00000/00000
d D 3.1 83/02/18 00:41:42 mckusick 1 0
c date and time created 83/02/18 00:41:42 by mckusick
e
u
U
t
T
I 1
D 22
/* Copyright (c) 1983 Regents of the University of California */

E 22
D 30
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif
E 30
I 30
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 30
I 22

D 30
/* Copyright (c) 1983 Regents of the University of California */
E 30
I 30
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 30
E 22

#include "restore.h"
D 31
#include <dumprestor.h>
E 31
I 31
#include <protocols/dumprestore.h>
E 31
#include <sys/ioctl.h>
#include <sys/mtio.h>
I 2
#include <sys/file.h>
E 2
#include <setjmp.h>
D 21
#include <stat.h>
E 21
I 21
#include <sys/stat.h>
E 21
D 2
#include <file.h>
E 2

D 2
long	fssize;
int	mt = -1;
char	*magtape;
int	insetup = 0;
int	bct = NTREC+1;
char	tbf[NTREC*TP_BSIZE];
jmp_buf	restart;
int	gettingfile = 0;	/* restart has a valid frame */
E 2
I 2
D 23
static long	fssize;
E 23
I 23
static long	fssize = MAXBSIZE;
E 23
static int	mt = -1;
static int	pipein = 0;
D 27
static char	*magtape;
E 27
I 27
static char	magtape[BUFSIZ];
E 27
D 5
static int	insetup = 0;
E 5
D 24
static int	bct = NTREC+1;
static char	tbf[NTREC*TP_BSIZE];
E 24
I 24
static int	bct;
static char	*tbf;
E 24
static union	u_spcl endoftapemark;
static long	blksread;
I 20
static long	tapesread;
E 20
static jmp_buf	restart;
static int	gettingfile = 0;	/* restart has a valid frame */
E 2

D 2
int	ofile;
char	*map;
char	lnkbuf[MAXPATHLEN + 1];
int	pathlen;
E 2
I 2
static int	ofile;
static char	*map;
static char	lnkbuf[MAXPATHLEN + 1];
static int	pathlen;
E 2

I 34
int		Bcvt;		/* Swap Bytes (for CCI or sun) */
static int	Qcvt;		/* Swap quads (for sun) */
E 34
/*
 * Set up an input source
 */
setinput(source)
	char *source;
{
I 18
#ifdef RRESTORE
E 18
D 17
#ifdef RRESTOR
E 17
D 27
	char *host;
E 27
I 27
	char *host, *tape;
E 27
I 18
#endif RRESTORE
E 18
D 17
	char *index();
E 17

I 24
	flsht();
D 28
	tbf = (char *)malloc(ntrec * TP_BSIZE);
	if (tbf == NULL) {
		fprintf(stderr, "Cannot allocate space for tape buffer\n");
		done(1);
	}
E 28
I 28
	if (bflag)
		newtapebuf(ntrec);
	else
		newtapebuf(NTREC > HIGHDENSITYTREC ? NTREC : HIGHDENSITYTREC);
E 28
E 24
I 17
	terminal = stdin;
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
E 17
	host = source;
D 27
	magtape = index(host, ':');
	if (magtape == 0) {
E 27
I 27
	tape = index(host, ':');
	if (tape == 0) {
E 27
nohost:
D 6
		msg("need keyletter ``f'' and device ``host:tape''");
E 6
I 6
		msg("need keyletter ``f'' and device ``host:tape''\n");
E 6
		done(1);
	}
D 27
	*magtape++ = '\0';
E 27
I 27
	*tape++ = '\0';
	(void) strcpy(magtape, tape);
E 27
	if (rmthost(host) == 0)
		done(1);
	setuid(getuid());	/* no longer need or want root privileges */
#else
I 2
D 13
	if (strcmp(source, "-") == 0) {
E 13
I 13
D 17
	if (strcmp(source, "-") != 0) {
		terminal = stdin;
	} else {
E 17
I 17
	if (strcmp(source, "-") == 0) {
E 17
		/*
		 * Since input is coming from a pipe we must establish
		 * our own connection to the terminal.
		 */
		terminal = fopen("/dev/tty", "r");
		if (terminal == NULL) {
D 25
			perror("open(\"/dev/tty\")");
			done(1);
E 25
I 25
			perror("Cannot open(\"/dev/tty\")");
			terminal = fopen("/dev/null", "r");
			if (terminal == NULL) {
				perror("Cannot open(\"/dev/null\")");
				done(1);
			}
E 25
		}
E 13
		pipein++;
D 13
		yflag++;
E 13
	}
E 2
D 27
	magtape = source;
E 27
I 27
	(void) strcpy(magtape, source);
E 27
D 18
#endif RRESTOR
E 18
I 18
#endif RRESTORE
E 18
}

I 28
newtapebuf(size)
	long size;
{
	static tbfsize = -1;

	ntrec = size;
	if (size <= tbfsize)
		return;
	if (tbf != NULL)
		free(tbf);
	tbf = (char *)malloc(size * TP_BSIZE);
	if (tbf == NULL) {
		fprintf(stderr, "Cannot allocate space for tape buffer\n");
		done(1);
	}
	tbfsize = size;
}

E 28
/*
 * Verify that the tape drive can be accessed and
 * that it actually is a dump tape.
 */
setup()
{
I 2
	int i, j, *ip;
E 2
D 9
	struct mtop tcom;
E 9
	struct stat stbuf;
D 41
	extern char *ctime();
E 41
	extern int xtrmap(), xtrmapskip();

	vprintf(stdout, "Verify tape and initialize maps\n");
D 5
	insetup = 1;
E 5
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
	if ((mt = rmtopen(magtape, 0)) < 0)
#else
D 2
	if ((mt = open(magtape, 0)) < 0)
E 2
I 2
	if (pipein)
		mt = 0;
	else if ((mt = open(magtape, 0)) < 0)
E 2
#endif
	{
D 18
		fprintf(stderr, "%s: cannot open tape\n", magtape);
E 18
I 18
		perror(magtape);
E 18
		done(1);
	}
D 9
	if (dumpnum != 1) {
I 2
		if (pipein) {
			fprintf(stderr,
				"Cannot have multiple dumps on pipe input\n");
			done(1);
		}
E 2
		tcom.mt_op = MTFSF;
D 2
		tcom.mt_count = dumpnum -1;
E 2
I 2
		tcom.mt_count = dumpnum - 1;
E 2
#ifdef RRESTOR
D 2
		rmtioctl(MTFSF,dumpnum - 1);
E 2
I 2
		rmtioctl(MTFSF, dumpnum - 1);
E 2
#else
D 2
		if (ioctl(mt,MTIOCTOP,&tcom) < 0)
E 2
I 2
		if (ioctl(mt, MTIOCTOP, &tcom) < 0)
E 2
			perror("ioctl MTFSF");
#endif
	}
E 9
I 9
	volno = 1;
	setdumpnum();
E 9
	flsht();
I 28
	if (!pipein && !bflag)
		findtapeblksize();
E 28
D 2
	if (readhdr(&spcl) == 0) {
E 2
I 2
D 6
	if (readhdr(&spcl) == FAIL) {
E 6
I 6
	if (gethead(&spcl) == FAIL) {
E 6
E 2
		bct--; /* push back this block */
		cvtflag++;
D 2
		if (readhdr(&spcl) == 0) {
E 2
I 2
D 6
		if (readhdr(&spcl) == FAIL) {
E 6
I 6
		if (gethead(&spcl) == FAIL) {
E 6
E 2
			fprintf(stderr, "Tape is not a dump tape\n");
			done(1);
		}
		fprintf(stderr, "Converting to new file system format.\n");
	}
I 2
	if (pipein) {
		endoftapemark.s_spcl.c_magic = cvtflag ? OFS_MAGIC : NFS_MAGIC;
		endoftapemark.s_spcl.c_type = TS_END;
		ip = (int *)&endoftapemark;
		j = sizeof(union u_spcl) / sizeof(int);
		i = 0;
		do
			i += *ip++;
		while (--j);
		endoftapemark.s_spcl.c_checksum = CHECKSUM - i;
	}
E 2
D 14
	vprintf(stdout, "Dump   date: %s", ctime(&spcl.c_date));
	vprintf(stdout, "Dumped from: %s", ctime(&spcl.c_ddate));
E 14
I 14
D 37
	if (vflag || command == 't') {
		fprintf(stdout, "Dump   date: %s", ctime(&spcl.c_date));
		fprintf(stdout, "Dumped from: %s", ctime(&spcl.c_ddate));
	}
E 37
I 37
	if (vflag || command == 't')
		printdumpinfo();
E 37
E 14
	dumptime = spcl.c_ddate;
I 2
	dumpdate = spcl.c_date;
E 2
	if (stat(".", &stbuf) < 0) {
D 18
		fprintf(stderr, "cannot stat .\n");
E 18
I 18
		perror("cannot stat .");
E 18
		done(1);
	}
D 23
	fssize = stbuf.st_blksize;
	if (fssize <= 0 || ((fssize - 1) & fssize) != 0) {
E 23
I 23
	if (stbuf.st_blksize > 0 && stbuf.st_blksize <= MAXBSIZE)
		fssize = stbuf.st_blksize;
	if (((fssize - 1) & fssize) != 0) {
E 23
		fprintf(stderr, "bad block size %d\n", fssize);
		done(1);
	}
D 2
	if (checkvol(&spcl, (long)1) == 0) {
E 2
I 2
	if (checkvol(&spcl, (long)1) == FAIL) {
E 2
		fprintf(stderr, "Tape is not volume 1 of the dump\n");
		done(1);
	}
I 8
D 9
	volno = 1;
E 9
E 8
D 2
	if (readhdr(&spcl) == 0 || checktype(&spcl, TS_CLRI) != 1) {
E 2
I 2
	if (readhdr(&spcl) == FAIL)
		panic("no header after volume mark!\n");
D 37
	findinode(&spcl, 1);
E 37
I 37
	findinode(&spcl);
E 37
	if (checktype(&spcl, TS_CLRI) == FAIL) {
E 2
		fprintf(stderr, "Cannot find file removal list\n");
		done(1);
	}
D 2
	maxino = spcl.c_count * TP_BSIZE + 1;
E 2
I 2
	maxino = (spcl.c_count * TP_BSIZE * NBBY) + 1;
D 9
	dprintf(stderr, "maxino = %d\n", maxino);
E 9
I 9
	dprintf(stdout, "maxino = %d\n", maxino);
E 9
E 2
D 7
	map = (char *)calloc(1, (int)howmany(maxino, NBBY));
E 7
I 7
	map = calloc((unsigned)1, (unsigned)howmany(maxino, NBBY));
E 7
	if (map == (char *)NIL)
		panic("no memory for file removal list\n");
I 10
	clrimap = map;
E 10
	curfile.action = USING;
	getfile(xtrmap, xtrmapskip);
D 10
	clrimap = map;
E 10
D 2
	if (checktype(&spcl, TS_BITS) != 1) {
E 2
I 2
	if (checktype(&spcl, TS_BITS) == FAIL) {
E 2
		fprintf(stderr, "Cannot find file dump list\n");
		done(1);
	}
D 7
	map = (char *)calloc(1, (int)howmany(maxino, NBBY));
E 7
I 7
	map = calloc((unsigned)1, (unsigned)howmany(maxino, NBBY));
E 7
	if (map == (char *)NULL)
		panic("no memory for file dump list\n");
I 10
	dumpmap = map;
E 10
	curfile.action = USING;
	getfile(xtrmap, xtrmapskip);
D 10
	dumpmap = map;
E 10
D 5
	insetup = 0;
E 5
}

I 20
/*
 * Prompt user to load a new dump volume.
 * "Nextvol" is the next suggested volume to use.
 * This suggested volume is enforced when doing full
 * or incremental restores, but can be overrridden by
 * the user when only extracting a subset of the files.
 */
E 20
getvol(nextvol)
	long nextvol;
{
	long newvol;
I 2
D 20
	long savecnt;
E 20
I 20
	long savecnt, i;
E 20
E 2
	union u_spcl tmpspcl;
#	define tmpbuf tmpspcl.s_spcl
I 37
	char buf[TP_BSIZE];
I 41
	extern char *ctime();
E 41
E 37

I 20
D 26
	if (nextvol == 1)
E 26
I 26
	if (nextvol == 1) {
E 26
		tapesread = 0;
I 26
		gettingfile = 0;
	}
E 26
E 20
D 9
	if (dumpnum > 1) {
		/*
		 * if this is a multi-dump tape we always start with 
		 * volume 1, so as to avoid accidentally restoring
		 * from a different dump!
		 */
D 2
		resetmt();
E 2
I 2
		if (volno != 1)
			panic("multiple dump at volno %d\n", volno);
E 2
		dumpnum = 1;
D 2
		volno = 1;
		goto rbits;
E 2
	}
E 9
I 2
	if (pipein) {
D 4
		if (volno != 1 || newvol != 1)
E 4
I 4
D 5
		if (volno != 1 || nextvol != 1)
E 5
I 5
		if (nextvol != 1)
E 5
E 4
			panic("Changing volumes on pipe input?\n");
D 5
		return;
E 5
I 5
		if (volno == 1)
			return;
		goto gethdr;
E 5
	}
	savecnt = blksread;
E 2
again:
I 5
	if (pipein)
		done(1); /* pipes do not get a second chance */
E 5
	if (command == 'R' || command == 'r' || curfile.action != SKIP)
		newvol = nextvol;
	else 
		newvol = 0;
	while (newvol <= 0) {
I 20
		if (tapesread == 0) {
			fprintf(stderr, "%s%s%s%s%s",
			    "You have not read any tapes yet.\n",
			    "Unless you know which volume your",
			    " file(s) are on you should start\n",
			    "with the last volume and work",
D 33
			    " towards towards the first.\n");
E 33
I 33
D 34
			    " towards the first.\n");
E 34
I 34
			    " towards towards the first.\n");
E 34
E 33
		} else {
			fprintf(stderr, "You have read volumes");
			strcpy(tbf, ": ");
			for (i = 1; i < 32; i++)
				if (tapesread & (1 << i)) {
					fprintf(stderr, "%s%d", tbf, i);
					strcpy(tbf, ", ");
				}
			fprintf(stderr, "\n");
		}
E 20
D 6
		fprintf(stderr, "Specify volume #: ");
E 6
I 6
D 13
		fprintf(stderr, "Specify next volume #: ");
E 13
E 6
D 12
		if (gets(tbf) == NULL)
D 2
			return;
E 2
I 2
			continue;
E 12
I 12
		do	{
D 13
			(void) fgets(tbf, BUFSIZ, stdin);
		} while (!feof(stdin) && tbf[0] == '\n');
		if (feof(stdin))
E 13
I 13
			fprintf(stderr, "Specify next volume #: ");
			(void) fflush(stderr);
			(void) fgets(tbf, BUFSIZ, terminal);
		} while (!feof(terminal) && tbf[0] == '\n');
		if (feof(terminal))
E 13
			done(1);
E 12
E 2
		newvol = atoi(tbf);
		if (newvol <= 0) {
			fprintf(stderr,
			    "Volume numbers are positive numerics\n");
		}
	}
D 20
	if (newvol == volno)
E 20
I 20
	if (newvol == volno) {
		tapesread |= 1 << volno;
E 20
		return;
I 20
	}
E 20
	closemt();
D 6
	fprintf(stderr, "Mount tape volume %d then type return: ", newvol);
E 6
I 6
D 27
	fprintf(stderr, "Mount tape volume %d then type return ", newvol);
E 27
I 27
	fprintf(stderr, "Mount tape volume %d\n", newvol);
	fprintf(stderr, "then enter tape name (default: %s) ", magtape);
E 27
E 6
D 13
	while (getchar() != '\n')
E 13
I 13
	(void) fflush(stderr);
D 27
	while (getc(terminal) != '\n')
E 13
D 25
		;
E 25
I 25
		if (feof(terminal))
			done(1);
E 27
I 27
	(void) fgets(tbf, BUFSIZ, terminal);
	if (feof(terminal))
		done(1);
	if (tbf[0] != '\n') {
		(void) strcpy(magtape, tbf);
		magtape[strlen(magtape) - 1] = '\0';
	}
E 27
E 25
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
	if ((mt = rmtopen(magtape, 0)) == -1)
#else
	if ((mt = open(magtape, 0)) == -1)
#endif
	{
D 27
		fprintf(stderr, "Cannot open tape!\n");
E 27
I 27
		fprintf(stderr, "Cannot open %s\n", magtape);
		volno = -1;
E 27
		goto again;
	}
I 5
gethdr:
E 5
	volno = newvol;
I 9
	setdumpnum();
E 9
	flsht();
D 2
	if (readhdr(&tmpbuf) == 0) {
E 2
I 2
	if (readhdr(&tmpbuf) == FAIL) {
E 2
		fprintf(stderr, "tape is not dump tape\n");
		volno = 0;
		goto again;
	}
D 2
	if (checkvol(&tmpbuf, volno) == 0) {
E 2
I 2
	if (checkvol(&tmpbuf, volno) == FAIL) {
E 2
		fprintf(stderr, "Wrong volume (%d)\n", tmpbuf.c_volume);
		volno = 0;
		goto again;
	}
D 2
rbits:
E 2
I 2
	if (tmpbuf.c_date != dumpdate || tmpbuf.c_ddate != dumptime) {
D 7
		fprintf(stderr, "Wrong dump date (%s)\n", ctime(tmpbuf.c_date));
E 7
I 7
D 14
		fprintf(stderr, "Wrong dump date (%s)\n",
			ctime(&tmpbuf.c_date));
E 14
I 14
D 15
		fprintf(stderr, "Wrong dump date got: %swanted %s",
E 15
I 15
D 16
		fprintf(stderr, "Wrong dump date\n\tgot: %s\twanted %s",
E 15
			ctime(&tmpbuf.c_date), ctime(dumpdate));
E 16
I 16
		fprintf(stderr, "Wrong dump date\n\tgot: %s",
			ctime(&tmpbuf.c_date));
		fprintf(stderr, "\twanted: %s", ctime(&dumpdate));
E 16
E 14
E 7
		volno = 0;
		goto again;
	}
I 20
	tapesread |= 1 << volno;
E 20
I 6
	blksread = savecnt;
E 6
E 2
	if (curfile.action == USING) {
		if (volno == 1)
			panic("active file into volume 1\n");
I 2
D 6
		blksread = savecnt;
E 6
E 2
		return;
	}
I 37
	/*
	 * Skip up to the beginning of the next record
	 */
D 39
	if (tmpbuf.c_type == TS_TAPE)
E 39
I 39
	if (tmpbuf.c_type == TS_TAPE && (tmpbuf.c_flags & DR_NEWHEADER))
E 39
		for (i = tmpbuf.c_count; i > 0; i--)
			readtape(buf);
E 37
I 5
D 6
	if (readhdr(&spcl) == FAIL)
		panic("no header after volume mark!\n");
E 6
I 6
	(void) gethead(&spcl);
E 6
E 5
D 37
	findinode(&spcl, curfile.action == UNKNOWN ? 1 : 0);
E 37
I 37
	findinode(&spcl);
E 37
	if (gettingfile) {
		gettingfile = 0;
		longjmp(restart, 1);
	}
}

I 9
/*
 * handle multiple dumps per tape by skipping forward to the
 * appropriate one.
 */
setdumpnum()
{
	struct mtop tcom;

	if (dumpnum == 1 || volno != 1)
		return;
	if (pipein) {
		fprintf(stderr, "Cannot have multiple dumps on pipe input\n");
		done(1);
	}
	tcom.mt_op = MTFSF;
	tcom.mt_count = dumpnum - 1;
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
	rmtioctl(MTFSF, dumpnum - 1);
#else
D 12
	if (ioctl(mt, MTIOCTOP, &tcom) < 0)
E 12
I 12
	if (ioctl(mt, (int)MTIOCTOP, (char *)&tcom) < 0)
E 12
		perror("ioctl MTFSF");
#endif
}

I 37
printdumpinfo()
{
I 41
	extern char *ctime();
E 41

	fprintf(stdout, "Dump   date: %s", ctime(&spcl.c_date));
D 40
	fprintf(stdout, "Dumped from: %s", ctime(&spcl.c_ddate));
E 40
I 40
	fprintf(stdout, "Dumped from: %s",
	    (spcl.c_ddate == 0) ? "the epoch\n" : ctime(&spcl.c_ddate));
E 40
	if (spcl.c_host[0] == '\0')
		return;
	fprintf(stderr, "Level %d dump of %s on %s:%s\n",
		spcl.c_level, spcl.c_filesys, spcl.c_host, spcl.c_dev);
	fprintf(stderr, "Label: %s\n", spcl.c_label);
}

E 37
E 9
extractfile(name)
	char *name;
{
	int mode;
	time_t timep[2];
	struct entry *ep;
	extern int xtrlnkfile(), xtrlnkskip();
	extern int xtrfile(), xtrskip();

	curfile.name = name;
	curfile.action = USING;
	timep[0] = curfile.dip->di_atime;
	timep[1] = curfile.dip->di_mtime;
	mode = curfile.dip->di_mode;
	switch (mode & IFMT) {

	default:
		fprintf(stderr, "%s: unknown file mode 0%o\n", name, mode);
		skipfile();
		return (FAIL);

I 35
	case IFSOCK:
		vprintf(stdout, "skipped socket %s\n", name);
		skipfile();
		return (GOOD);

E 35
	case IFDIR:
		if (mflag) {
			ep = lookupname(name);
			if (ep == NIL || ep->e_flags & EXTRACT)
				panic("unextracted directory %s\n", name);
			skipfile();
			return (GOOD);
		}
		vprintf(stdout, "extract file %s\n", name);
		return (genliteraldir(name, curfile.ino));

	case IFLNK:
		lnkbuf[0] = '\0';
		pathlen = 0;
		getfile(xtrlnkfile, xtrlnkskip);
		if (pathlen == 0) {
			vprintf(stdout,
			    "%s: zero length symbolic link (ignored)\n", name);
D 23
		} else if (symlink(lnkbuf, name) < 0) {
D 18
			fprintf(stderr, "%s: cannot create symbolic link\n",
			    name);
E 18
I 18
			fprintf(stderr, "%s: ", name);
			(void) fflush(stderr);
			perror("cannot create symbolic link");
E 18
			return (FAIL);
		} else
			vprintf(stdout, "extract symbolic link %s\n", name);
		return (GOOD);
E 23
I 23
			return (GOOD);
		}
		return (linkit(lnkbuf, name, SYMLINK));
E 23

	case IFCHR:
	case IFBLK:
		vprintf(stdout, "extract special file %s\n", name);
I 43
		if (Nflag) {
			skipfile();
			return (GOOD);
		}
E 43
		if (mknod(name, mode, (int)curfile.dip->di_rdev) < 0) {
D 18
			fprintf(stderr, "%s: cannot create special file\n",
			    name);
E 18
I 18
			fprintf(stderr, "%s: ", name);
			(void) fflush(stderr);
			perror("cannot create special file");
E 18
			skipfile();
			return (FAIL);
		}
D 9
		chown(name, curfile.dip->di_uid, curfile.dip->di_gid);
		chmod(name, mode);
E 9
I 9
		(void) chown(name, curfile.dip->di_uid, curfile.dip->di_gid);
		(void) chmod(name, mode);
E 9
		skipfile();
		utime(name, timep);
		return (GOOD);

	case IFREG:
		vprintf(stdout, "extract file %s\n", name);
I 43
		if (Nflag) {
			skipfile();
			return (GOOD);
		}
E 43
D 19
		if ((ofile = open(name, FWRONLY|FCREATE, 0666)) < 0) {
E 19
I 19
		if ((ofile = creat(name, 0666)) < 0) {
E 19
D 18
			fprintf(stderr, "%s: cannot create file\n", name);
E 18
I 18
			fprintf(stderr, "%s: ", name);
			(void) fflush(stderr);
			perror("cannot create file");
E 18
			skipfile();
			return (FAIL);
		}
D 9
		fchown(ofile, curfile.dip->di_uid, curfile.dip->di_gid);
		fchmod(ofile, mode);
E 9
I 9
		(void) fchown(ofile, curfile.dip->di_uid, curfile.dip->di_gid);
		(void) fchmod(ofile, mode);
E 9
		getfile(xtrfile, xtrskip);
D 9
		close(ofile);
E 9
I 9
		(void) close(ofile);
E 9
		utime(name, timep);
		return (GOOD);
	}
	/* NOTREACHED */
}

I 5
/*
 * skip over bit maps on the tape
 */
skipmaps()
{

	while (checktype(&spcl, TS_CLRI) == GOOD ||
	       checktype(&spcl, TS_BITS) == GOOD)
		skipfile();
}

/*
 * skip over a file on the tape
 */
E 5
skipfile()
{
	extern int null();

	curfile.action = SKIP;
	getfile(null, null);
}

/*
 * Do the file extraction, calling the supplied functions
 * with the blocks
 */
getfile(f1, f2)
	int	(*f2)(), (*f1)();
{
	register int i;
	int curblk = 0;
	off_t size = spcl.c_dinode.di_size;
	static char clearedbuf[MAXBSIZE];
	char buf[MAXBSIZE / TP_BSIZE][TP_BSIZE];
I 32
	char junk[TP_BSIZE];
E 32

D 2
	if (checktype(&spcl, TS_END) == 1)
E 2
I 2
	if (checktype(&spcl, TS_END) == GOOD)
E 2
		panic("ran off end of tape\n");
D 2
	if (checktype(&spcl, TS_INODE) == 0)
E 2
I 2
D 5
	if (!insetup && checktype(&spcl, TS_INODE) == FAIL)
E 5
I 5
	if (ishead(&spcl) == FAIL)
E 5
E 2
		panic("not at beginning of a file\n");
D 5
	if (setjmp(restart) != 0)
E 5
I 5
	if (!gettingfile && setjmp(restart) != 0)
E 5
		return;
	gettingfile++;
loop:
	for (i = 0; i < spcl.c_count; i++) {
		if (spcl.c_addr[i]) {
			readtape(&buf[curblk++][0]);
			if (curblk == fssize / TP_BSIZE) {
				(*f1)(buf, size > TP_BSIZE ?
				     (long) (fssize) :
				     (curblk - 1) * TP_BSIZE + size);
				curblk = 0;
			}
		} else {
			if (curblk > 0) {
				(*f1)(buf, size > TP_BSIZE ?
				     (long) (curblk * TP_BSIZE) :
				     (curblk - 1) * TP_BSIZE + size);
				curblk = 0;
			}
			(*f2)(clearedbuf, size > TP_BSIZE ?
				(long) TP_BSIZE : size);
		}
D 3
		if ((size -= TP_BSIZE) <= 0) {
			gethead(&spcl);
			goto out;
		}
E 3
I 3
D 32
		if ((size -= TP_BSIZE) <= 0)
E 32
I 32
		if ((size -= TP_BSIZE) <= 0) {
			for (i++; i < spcl.c_count; i++)
				if (spcl.c_addr[i])
					readtape(junk);
E 32
			break;
I 32
		}
E 32
E 3
	}
D 2
	if (gethead(&spcl) == 0 || checktype(&spcl, TS_ADDR) == 0) {
E 2
I 2
D 3
	if (gethead(&spcl) == FAIL || checktype(&spcl, TS_ADDR) == FAIL) {
E 3
I 3
D 6
	if (gethead(&spcl) == GOOD && size > 0) {
E 6
I 6
	if (readhdr(&spcl) == GOOD && size > 0) {
E 6
		if (checktype(&spcl, TS_ADDR) == GOOD)
			goto loop;
E 3
E 2
D 9
		fprintf(stderr, "Missing address (header) block for %s\n",
E 9
I 9
		dprintf(stdout, "Missing address (header) block for %s\n",
E 9
			curfile.name);
D 3
		goto out;
E 3
	}
D 3
	goto loop;
out:
	if (curblk > 0) {
E 3
I 3
	if (curblk > 0)
E 3
		(*f1)(buf, (curblk * TP_BSIZE) + size);
D 3
	}
E 3
D 37
	findinode(&spcl, 1);
E 37
I 37
	findinode(&spcl);
E 37
	gettingfile = 0;
}

/*
 * The next routines are called during file extraction to
 * put the data into the right form and place.
 */
xtrfile(buf, size)
	char	*buf;
	long	size;
{

I 43
	if (Nflag)
		return;
E 43
	if (write(ofile, buf, (int) size) == -1) {
		fprintf(stderr, "write error extracting inode %d, name %s\n",
			curfile.ino, curfile.name);
		perror("write");
		done(1);
	}
}

xtrskip(buf, size)
	char *buf;
	long size;
{

#ifdef lint
	buf = buf;
#endif
	if (lseek(ofile, size, 1) == (long)-1) {
		fprintf(stderr, "seek error extracting inode %d, name %s\n",
			curfile.ino, curfile.name);
		perror("lseek");
		done(1);
	}
}

xtrlnkfile(buf, size)
	char	*buf;
	long	size;
{

	pathlen += size;
	if (pathlen > MAXPATHLEN) {
		fprintf(stderr, "symbolic link name: %s->%s%s; too long %d\n",
		    curfile.name, lnkbuf, buf, pathlen);
		done(1);
	}
D 12
	strcat(lnkbuf, buf);
E 12
I 12
	(void) strcat(lnkbuf, buf);
E 12
}

xtrlnkskip(buf, size)
	char *buf;
	long size;
{

#ifdef lint
	buf = buf, size = size;
#endif
	fprintf(stderr, "unallocated block in symbolic link %s\n",
		curfile.name);
	done(1);
}

xtrmap(buf, size)
	char	*buf;
	long	size;
{

	bcopy(buf, map, size);
I 10
	map += size;
E 10
}

xtrmapskip(buf, size)
	char *buf;
	long size;
{

#ifdef lint
	buf = buf;
D 10
	size = size;
E 10
#endif
	panic("hole in map\n");
I 10
	map += size;
E 10
}

null() {;}

/*
 * Do the tape i/o, dealing with volume changes
 * etc..
 */
readtape(b)
	char *b;
{
	register long i;
D 4
	long newvol;
E 4
I 4
D 7
	long rd, cnt, newvol;
E 7
I 7
	long rd, newvol;
	int cnt;
E 7
E 4

D 24
	if (bct >= NTREC) {
		for (i = 0; i < NTREC; i++)
E 24
I 24
D 28
	if (bct >= ntrec) {
		for (i = 0; i < ntrec; i++)
E 24
			((struct s_spcl *)&tbf[i*TP_BSIZE])->c_magic = 0;
		bct = 0;
I 4
D 24
		cnt = NTREC*TP_BSIZE;
E 24
I 24
		cnt = ntrec*TP_BSIZE;
E 24
		rd = 0;
	getmore:
E 28
I 28
	if (bct < ntrec) {
		bcopy(&tbf[(bct++*TP_BSIZE)], b, (long)TP_BSIZE);
		blksread++;
		return;
	}
	for (i = 0; i < ntrec; i++)
		((struct s_spcl *)&tbf[i*TP_BSIZE])->c_magic = 0;
	bct = 0;
	cnt = ntrec*TP_BSIZE;
	rd = 0;
getmore:
E 28
E 4
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
D 4
		if ((i = rmtread(tbf, NTREC*TP_BSIZE)) < 0)
E 4
I 4
D 28
		i = rmtread(&tbf[rd], cnt);
E 28
I 28
	i = rmtread(&tbf[rd], cnt);
E 28
E 4
#else
D 4
		if ((i = read(mt, tbf, NTREC*TP_BSIZE)) < 0)
E 4
I 4
D 28
		i = read(mt, &tbf[rd], cnt);
E 28
I 28
	i = read(mt, &tbf[rd], cnt);
E 28
E 4
#endif
D 4
			{
E 4
I 4
D 24
		if (i > 0 && i != NTREC*TP_BSIZE) {
E 24
I 24
D 28
		if (i > 0 && i != ntrec*TP_BSIZE) {
E 24
			if (!pipein)
				panic("partial block read: %d should be %d\n",
D 24
					i, NTREC*TP_BSIZE);
E 24
I 24
					i, ntrec*TP_BSIZE);
E 28
I 28
	if (i > 0 && i != ntrec*TP_BSIZE) {
		if (pipein) {
E 28
E 24
			rd += i;
			cnt -= i;
			if (cnt > 0)
				goto getmore;
			i = rd;
I 28
		} else {
			if (i % TP_BSIZE != 0)
				panic("partial block read: %d should be %d\n",
					i, ntrec * TP_BSIZE);
			bcopy((char *)&endoftapemark, &tbf[i],
				(long)TP_BSIZE);
E 28
		}
D 28
		if (i < 0) {
E 4
			fprintf(stderr, "Tape read error while ");
			switch (curfile.action) {
I 4
			default:
				fprintf(stderr, "trying to set up tape\n");
				break;
E 4
			case UNKNOWN:
				fprintf(stderr, "trying to resyncronize\n");
				break;
			case USING:
				fprintf(stderr, "restoring %s\n", curfile.name);
				break;
			case SKIP:
				fprintf(stderr, "skipping over inode %d\n",
					curfile.ino);
				break;
			}
			if (!yflag && !reply("continue"))
				done(1);
D 24
			i = NTREC*TP_BSIZE;
E 24
I 24
			i = ntrec*TP_BSIZE;
E 24
			bzero(tbf, i);
E 28
I 28
	}
	if (i < 0) {
		fprintf(stderr, "Tape read error while ");
		switch (curfile.action) {
		default:
			fprintf(stderr, "trying to set up tape\n");
			break;
		case UNKNOWN:
D 42
			fprintf(stderr, "trying to resyncronize\n");
E 42
I 42
			fprintf(stderr, "trying to resynchronize\n");
E 42
			break;
		case USING:
			fprintf(stderr, "restoring %s\n", curfile.name);
			break;
		case SKIP:
			fprintf(stderr, "skipping over inode %d\n",
				curfile.ino);
			break;
		}
		if (!yflag && !reply("continue"))
			done(1);
		i = ntrec*TP_BSIZE;
		bzero(tbf, i);
E 28
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
D 28
			if (rmtseek(i, 1) < 0)
E 28
I 28
		if (rmtseek(i, 1) < 0)
E 28
#else
D 28
			if (lseek(mt, i, 1) == (long)-1)
E 28
I 28
		if (lseek(mt, i, 1) == (long)-1)
E 28
#endif
D 28
			{
D 18
				fprintf(stderr, "continuation failed\n");
E 18
I 18
				perror("continuation failed");
E 18
				done(1);
			}
E 28
I 28
		{
			perror("continuation failed");
			done(1);
E 28
		}
D 28
		if (i == 0) {
I 2
			if (pipein) {
				bcopy((char *)&endoftapemark, b,
					(long)TP_BSIZE);
				flsht();
				return;
			}
E 2
			newvol = volno + 1;
			volno = 0;
			getvol(newvol);
			readtape(b);
E 28
I 28
	}
	if (i == 0) {
D 29
		if (pipein) {
			bcopy((char *)&endoftapemark, b,
				(long)TP_BSIZE);
			flsht();
E 29
I 29
		if (!pipein) {
			newvol = volno + 1;
			volno = 0;
			getvol(newvol);
			readtape(b);
E 29
E 28
			return;
		}
I 28
D 29
		newvol = volno + 1;
		volno = 0;
		getvol(newvol);
		readtape(b);
		return;
E 29
I 29
		if (rd % TP_BSIZE != 0)
			panic("partial block read: %d should be %d\n",
				rd, ntrec * TP_BSIZE);
		bcopy((char *)&endoftapemark, &tbf[rd], (long)TP_BSIZE);
E 29
E 28
	}
	bcopy(&tbf[(bct++*TP_BSIZE)], b, (long)TP_BSIZE);
I 2
	blksread++;
I 28
}

findtapeblksize()
{
	register long i;

	for (i = 0; i < ntrec; i++)
		((struct s_spcl *)&tbf[i * TP_BSIZE])->c_magic = 0;
	bct = 0;
#ifdef RRESTORE
	i = rmtread(tbf, ntrec * TP_BSIZE);
#else
	i = read(mt, tbf, ntrec * TP_BSIZE);
#endif
	if (i <= 0) {
		perror("Tape read error");
		done(1);
	}
	if (i % TP_BSIZE != 0) {
		fprintf(stderr, "Tape block size (%d) %s (%d)\n",
			i, "is not a multiple of dump block size", TP_BSIZE);
		done(1);
	}
	ntrec = i / TP_BSIZE;
	vprintf(stdout, "Tape block size is %d\n", ntrec);
E 28
E 2
}

flsht()
{

D 24
	bct = NTREC+1;
E 24
I 24
	bct = ntrec+1;
E 24
}

D 2
resetmt()
{
	struct mtop tcom;

	if (dumpnum > 1)
		tcom.mt_op = MTBSF;
	else
		tcom.mt_op = MTREW;
	tcom.mt_count = 1;
	flsht();
#ifdef RRESTOR
	if (rmtioctl(tcom.mt_op, 1) == -1) {
		/* kludge for disk dumps */
		rmtseek((long)0, 0);
	}
#else
	if (ioctl(mt,MTIOCTOP,&tcom) == -1) {
		/* kludge for disk dumps */
		(void) lseek(mt, (long)0, 0);
	}
#endif
	if (dumpnum > 1) {
#ifdef RRESTOR
		rmtioctl(MTFSF, 1);
#else
		tcom.mt_op = MTFSF;
		tcom.mt_count = 1;
		ioctl(mt,MTIOCTOP,&tcom);
#endif
	}
}

E 2
closemt()
{
	if (mt < 0)
		return;
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
	rmtclose();
#else
D 9
	close(mt);
E 9
I 9
	(void) close(mt);
E 9
#endif
}

checkvol(b, t)
	struct s_spcl *b;
	long t;
{

D 2
	if (b->c_volume == t)
		return(1);
	return(0);
E 2
I 2
	if (b->c_volume != t)
		return(FAIL);
	return(GOOD);
E 2
}

readhdr(b)
	struct s_spcl *b;
{

D 2
	if (gethead(b) == 0)
		return(0);
	if (checktype(b, TS_TAPE) == 0)
		return(0);
	return(1);
E 2
I 2
D 6
	if (gethead(b) == FAIL)
E 6
I 6
	if (gethead(b) == FAIL) {
D 9
		dprintf(stderr, "readhdr fails at %d blocks\n", blksread);
E 9
I 9
		dprintf(stdout, "readhdr fails at %d blocks\n", blksread);
E 9
E 6
		return(FAIL);
I 6
	}
E 6
	return(GOOD);
E 2
}

/*
 * read the tape into buf, then return whether or
 * or not it is a header block.
 */
gethead(buf)
	struct s_spcl *buf;
{
I 6
D 34
	long i;
E 34
I 34
	long i, *j;
E 34
E 6
	union u_ospcl {
		char dummy[TP_BSIZE];
		struct	s_ospcl {
D 2
			int	c_type;
			time_t	c_date;
			time_t	c_ddate;
			int	c_volume;
			daddr_t	c_tapea;
			ino_t	c_inumber;
			int	c_magic;
			int	c_checksum;
E 2
I 2
			long	c_type;
			long	c_date;
			long	c_ddate;
			long	c_volume;
			long	c_tapea;
D 10
			short	c_inumber;
E 10
I 10
			u_short	c_inumber;
E 10
			long	c_magic;
			long	c_checksum;
E 2
			struct odinode {
				unsigned short odi_mode;
D 10
				short	odi_nlink;
				short	odi_uid;
				short	odi_gid;
E 10
I 10
				u_short	odi_nlink;
				u_short	odi_uid;
				u_short	odi_gid;
E 10
D 2
				off_t	odi_size;
				daddr_t	odi_rdev;
E 2
I 2
				long	odi_size;
				long	odi_rdev;
E 2
				char	odi_addr[36];
D 2
				time_t	odi_atime;
				time_t	odi_mtime;
				time_t	odi_ctime;
E 2
I 2
				long	odi_atime;
				long	odi_mtime;
				long	odi_ctime;
E 2
			} c_dinode;
D 2
			int	c_count;
			char	c_addr[TP_NINDIR];
E 2
I 2
			long	c_count;
			char	c_addr[256];
E 2
		} s_ospcl;
	} u_ospcl;

	if (!cvtflag) {
		readtape((char *)buf);
D 2
		if (buf->c_magic != NFS_MAGIC || checksum((int *)buf) == 0)
			return(0);
		return(1);
E 2
I 2
D 6
		if (buf->c_magic != NFS_MAGIC || checksum((int *)buf) == FAIL) {
			dprintf(stderr, "gethead fails at %d blocks\n",
				blksread);
E 6
I 6
D 34
		if (buf->c_magic != NFS_MAGIC || checksum((int *)buf) == FAIL)
E 6
			return(FAIL);
E 34
I 34
		if (buf->c_magic != NFS_MAGIC) {
			if (swabl(buf->c_magic) != NFS_MAGIC)
				return (FAIL);
			if (!Bcvt) {
				vprintf(stdout, "Note: Doing Byte swapping\n");
				Bcvt = 1;
			}
		}
		if (checksum((int *)buf) == FAIL)
			return (FAIL);
		if (Bcvt)
			swabst("8l4s31l", (char *)buf);
E 34
D 6
		}
		if (dflag)
			accthdr(buf);
		return(GOOD);
E 6
I 6
		goto good;
E 6
E 2
	}
	readtape((char *)(&u_ospcl.s_ospcl));
	bzero((char *)buf, (long)TP_BSIZE);
	buf->c_type = u_ospcl.s_ospcl.c_type;
	buf->c_date = u_ospcl.s_ospcl.c_date;
	buf->c_ddate = u_ospcl.s_ospcl.c_ddate;
	buf->c_volume = u_ospcl.s_ospcl.c_volume;
	buf->c_tapea = u_ospcl.s_ospcl.c_tapea;
	buf->c_inumber = u_ospcl.s_ospcl.c_inumber;
	buf->c_checksum = u_ospcl.s_ospcl.c_checksum;
	buf->c_magic = u_ospcl.s_ospcl.c_magic;
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
D 2
	bcopy(u_ospcl.s_ospcl.c_addr, buf->c_addr, (long)TP_NINDIR);
E 2
I 2
	bcopy(u_ospcl.s_ospcl.c_addr, buf->c_addr, (long)256);
E 2
	if (u_ospcl.s_ospcl.c_magic != OFS_MAGIC ||
D 2
	    checksum((int *)(&u_ospcl.s_ospcl)) == 0)
		return(0);
E 2
I 2
D 6
	    checksum((int *)(&u_ospcl.s_ospcl)) == FAIL) {
		dprintf(stderr, "gethead fails at %d blocks\n", blksread);
E 6
I 6
	    checksum((int *)(&u_ospcl.s_ospcl)) == FAIL)
E 6
		return(FAIL);
D 6
	}
E 6
E 2
	buf->c_magic = NFS_MAGIC;
I 6

good:
I 34
	j = buf->c_dinode.di_ic.ic_size.val;
	i = j[1];
	if (buf->c_dinode.di_size == 0 &&
	    (buf->c_dinode.di_mode & IFMT) == IFDIR && Qcvt==0) {
		if (*j || i) {
			printf("Note: Doing Quad swapping\n");
			Qcvt = 1;
		}
	}
	if (Qcvt) {
		j[1] = *j; *j = i;
	}
E 34
	switch (buf->c_type) {

	case TS_CLRI:
	case TS_BITS:
		/*
		 * Have to patch up missing information in bit map headers
		 */
		buf->c_inumber = 0;
		buf->c_dinode.di_size = buf->c_count * TP_BSIZE;
		for (i = 0; i < buf->c_count; i++)
			buf->c_addr[i]++;
		break;

I 37
D 39
	case TS_OTAPE:
E 39
E 37
	case TS_TAPE:
	case TS_END:
		buf->c_inumber = 0;
		break;

	case TS_INODE:
	case TS_ADDR:
		break;

	default:
		panic("gethead: unknown inode type %d\n", buf->c_type);
		break;
	}
E 6
D 2
	return(1);
E 2
I 2
	if (dflag)
		accthdr(buf);
	return(GOOD);
E 2
}

/*
I 2
 * Check that a header is where it belongs and predict the next header
 */
accthdr(header)
	struct s_spcl *header;
{
D 6
	static ino_t previno = 0;
E 6
I 6
D 7
	static ino_t previno = 0xffffffff;
E 7
I 7
	static ino_t previno = 0x7fffffff;
E 7
E 6
	static int prevtype;
	static long predict;
	long blks, i;

D 6
	if (previno == 0)
E 6
I 6
D 37
	if (header->c_type == TS_TAPE) {
E 37
I 37
D 39
	if (header->c_type == TS_TAPE || header->c_type == TS_OTAPE) {
E 39
I 39
	if (header->c_type == TS_TAPE) {
E 39
E 37
		fprintf(stderr, "Volume header\n");
I 36
		previno = 0x7fffffff;
E 36
		return;
	}
D 7
	if (previno == 0xffffffff)
E 7
I 7
	if (previno == 0x7fffffff)
E 7
E 6
		goto newcalc;
	switch (prevtype) {
D 6
	case TS_TAPE:
		fprintf(stderr, "Volume");
		break;
E 6
	case TS_BITS:
D 6
		fprintf(stderr, "Dump mask");
E 6
I 6
		fprintf(stderr, "Dump mask header");
E 6
		break;
	case TS_CLRI:
D 6
		fprintf(stderr, "Remove mask");
E 6
I 6
		fprintf(stderr, "Remove mask header");
E 6
		break;
	case TS_INODE:
D 6
		fprintf(stderr, "File");
E 6
I 6
		fprintf(stderr, "File header, ino %d", previno);
E 6
		break;
	case TS_ADDR:
D 6
		fprintf(stderr, "File continuation");
E 6
I 6
		fprintf(stderr, "File continuation header, ino %d", previno);
E 6
		break;
	case TS_END:
D 6
		fprintf(stderr, "End of tape");
E 6
I 6
		fprintf(stderr, "End of tape header");
E 6
		break;
	}
D 6
	fprintf(stderr, " header, ino %d", previno);
E 6
	if (predict != blksread - 1)
		fprintf(stderr, "; predicted %d blocks, got %d blocks",
			predict, blksread - 1);
	fprintf(stderr, "\n");
newcalc:
	blks = 0;
D 6
	if (header->c_type != TS_TAPE && header->c_type != TS_END)
E 6
I 6
	if (header->c_type != TS_END)
E 6
		for (i = 0; i < header->c_count; i++)
			if (header->c_addr[i] != 0)
				blks++;
	predict = blks;
	blksread = 0;
	prevtype = header->c_type;
	previno = header->c_inumber;
}

/*
E 2
 * Find an inode header.
 * Complain if had to skip, and complain is set.
 */
D 37
findinode(header, complain)
E 37
I 37
findinode(header)
E 37
	struct s_spcl *header;
D 37
	int complain;
E 37
{
D 2
	static int skipcnt = 0;
E 2
I 2
	static long skipcnt = 0;
I 36
	long i;
	char buf[TP_BSIZE];
E 36
D 6
	long i;
E 6
E 2

	curfile.name = "<name unknown>";
	curfile.action = UNKNOWN;
	curfile.dip = (struct dinode *)NIL;
	curfile.ino = 0;
D 2
	if (ishead(header) == 0)
		while (gethead(header) == 0)
E 2
I 2
	if (ishead(header) == FAIL) {
		skipcnt++;
D 36
		while (gethead(header) == FAIL)
E 36
I 36
D 38
		while (gethead(header) == FAIL || header->c_ddate != dumptime)
E 38
I 38
		while (gethead(header) == FAIL || header->c_date != dumpdate)
E 38
E 36
E 2
			skipcnt++;
I 2
	}
E 2
	for (;;) {
I 36
		if (checktype(header, TS_ADDR) == GOOD) {
			/*
			 * Skip up to the beginning of the next record
			 */
			for (i = 0; i < header->c_count; i++)
				if (header->c_addr[i])
					readtape(buf);
			(void) gethead(header);
			continue;
		}
E 36
D 2
		if (checktype(header, TS_INODE) == 1) {
E 2
I 2
		if (checktype(header, TS_INODE) == GOOD) {
E 2
			curfile.dip = &header->c_dinode;
			curfile.ino = header->c_inumber;
			break;
		}
D 2
		if (checktype(header, TS_END) == 1) {
E 2
I 2
		if (checktype(header, TS_END) == GOOD) {
E 2
			curfile.ino = maxino;
			break;
		}
D 2
		if (insetup && checktype(header, TS_CLRI) == 1) {
E 2
I 2
		if (checktype(header, TS_CLRI) == GOOD) {
E 2
			curfile.name = "<file removal list>";
D 6
			header->c_dinode.di_size = header->c_count * TP_BSIZE;
D 2
			break;
E 2
I 2
			for (i = 0; i < header->c_count; i++)
				header->c_addr[i]++;
E 6
D 5
			if (insetup)
				break;
			skipfile();
E 5
I 5
			break;
E 5
E 2
		}
D 2
		if (insetup && checktype(header, TS_BITS) == 1) {
E 2
I 2
		if (checktype(header, TS_BITS) == GOOD) {
E 2
			curfile.name = "<file dump list>";
D 6
			header->c_dinode.di_size = header->c_count * TP_BSIZE;
D 2
			break;
E 2
I 2
			for (i = 0; i < header->c_count; i++)
				header->c_addr[i]++;
E 6
D 5
			if (insetup)
				break;
			skipfile();
E 5
I 5
			break;
E 5
E 2
		}
D 2
		while (gethead(header) == 0)
E 2
I 2
		while (gethead(header) == FAIL)
E 2
			skipcnt++;
	}
D 37
	if (skipcnt > 0 && complain)
E 37
I 37
	if (skipcnt > 0)
E 37
D 15
		fprintf(stderr, "resync restor, skipped %d blocks\n", skipcnt);
E 15
I 15
		fprintf(stderr, "resync restore, skipped %d blocks\n", skipcnt);
E 15
	skipcnt = 0;
}

/*
 * return whether or not the buffer contains a header block
 */
ishead(buf)
	struct s_spcl *buf;
{

	if (buf->c_magic != NFS_MAGIC)
D 2
		return(0);
	return(1);
E 2
I 2
		return(FAIL);
	return(GOOD);
E 2
}

checktype(b, t)
	struct s_spcl *b;
	int	t;
{

D 2
	return(b->c_type == t);
E 2
I 2
	if (b->c_type != t)
		return(FAIL);
	return(GOOD);
E 2
}

checksum(b)
	register int *b;
{
	register int i, j;

	j = sizeof(union u_spcl) / sizeof(int);
	i = 0;
D 34
	do
		i += *b++;
	while (--j);
E 34
I 34
	if(!Bcvt) {
		do
			i += *b++;
		while (--j);
	} else {
		/* What happens if we want to read restore tapes
			for a 16bit int machine??? */
		do 
			i += swabl(*b++);
		while (--j);
	}
			
E 34
	if (i != CHECKSUM) {
		fprintf(stderr, "Checksum error %o, inode %d file %s\n", i,
			curfile.ino, curfile.name);
D 2
		return(0);
E 2
I 2
		return(FAIL);
E 2
	}
D 2
	return(1);
E 2
I 2
	return(GOOD);
E 2
D 13
}

I 4
/*
 * respond to interrupts
 */
onintr()
{
	if (pipein || reply("restore interrupted, continue") == FAIL)
		done(1);
	if (signal(SIGINT, onintr) == SIG_IGN)
D 7
		signal(SIGINT, SIG_IGN);
E 7
I 7
		(void) signal(SIGINT, SIG_IGN);
E 7
	if (signal(SIGTERM, onintr) == SIG_IGN)
D 7
		signal(SIGTERM, SIG_IGN);
E 7
I 7
		(void) signal(SIGTERM, SIG_IGN);
E 7
}

/*
 * handle unexpected inconsistencies
 */
/* VARARGS1 */
panic(msg, d1, d2)
	char *msg;
	long d1, d2;
{

	fprintf(stderr, msg, d1, d2);
	if (pipein || reply("abort") == GOOD)
		abort();
E 13
}

E 4
D 18
#ifdef RRESTOR
E 18
I 18
#ifdef RRESTORE
E 18
I 4
/* VARARGS1 */
E 4
msg(cp, a1, a2, a3)
	char *cp;
{

	fprintf(stderr, cp, a1, a2, a3);
}
D 18
#endif RRESTOR
E 18
I 18
#endif RRESTORE
I 34

swabst(cp, sp)
register char *cp, *sp;
{
	int n = 0;
	char c;
	while(*cp) {
		switch (*cp) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			n = (n * 10) + (*cp++ - '0');
			continue;
		
		case 's': case 'w': case 'h':
			c = sp[0]; sp[0] = sp[1]; sp[1] = c;
			sp++;
			break;

		case 'l':
			c = sp[0]; sp[0] = sp[3]; sp[3] = c;
			c = sp[2]; sp[2] = sp[1]; sp[1] = c;
			sp += 3;
		}
		sp++; /* Any other character, like 'b' counts as byte. */
		if (n <= 1) {
			n = 0; cp++;
		} else
			n--;
	}
}
swabl(x) { unsigned long l = x; swabst("l", (char *)&l); return l; }
E 34
E 18
E 1
