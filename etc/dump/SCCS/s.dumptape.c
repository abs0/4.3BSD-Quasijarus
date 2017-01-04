h28148
s 00001/00001/00491
d D 5.8 87/02/23 18:06:28 mckusick 19 18
c convert SBLOCK to SBOFF; generalize dev_bsize
e
s 00002/00000/00490
d D 5.7 87/01/28 19:03:09 mckusick 18 17
c backward compatibility
e
s 00012/00003/00478
d D 5.6 86/10/21 15:52:03 mckusick 17 16
c new TS_TAPE header indicates the number of tape blocks to skip
c (in the c_count field) to find the first valid header on the volume
e
s 00001/00001/00480
d D 5.5 86/05/23 11:27:40 mckusick 16 15
c add newline to message
e
s 00019/00009/00462
d D 5.4 86/03/05 19:49:45 mckusick 15 14
c make lockfile generate a more senible error message
e
s 00105/00124/00366
d D 5.3 85/10/16 20:31:02 mckusick 14 13
c latest update from Don Speck
e
s 00160/00148/00330
d D 5.2 85/08/05 18:58:44 mckusick 13 12
c use flock instead of pipes to syncronize the slaves (from speck@cit-vlsi)
e
s 00008/00002/00470
d D 5.1 85/06/05 08:47:11 dist 12 11
c Add copyright
e
s 00038/00013/00434
d D 1.11 85/05/07 18:49:42 mckusick 11 10
c more fully check return values to isolate ring errors
e
s 00024/00002/00423
d D 1.10 85/05/04 16:44:34 mckusick 10 9
c must batch up reads from pipes
e
s 00249/00119/00176
d D 1.9 85/02/19 16:05:12 mckusick 9 8
c streaming dump mods using a ring of pipes (Caltech via speck@cit-vax)
e
s 00004/00003/00291
d D 1.8 84/12/16 17:57:17 sam 8 7
c replace copy loop with block copy
e
s 00017/00002/00277
d D 1.7 83/05/08 19:11:07 mckusick 7 6
c add ability to dump to standard output
e
s 00028/00008/00251
d D 1.6 83/02/11 12:58:39 sam 6 5
c merge from sun
e
s 00012/00011/00247
d D 1.5 82/01/05 01:37:27 mckusic 5 4
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00022/00028/00236
d D 1.4 81/11/07 14:53:17 mckusic 4 3
c dump to "standard" (ie 1K file system) dump tapes
e
s 00006/00003/00258
d D 1.3 81/03/11 18:52:17 wnj 3 2
c dont wait for rewind a fixed length of time;;; use reopen until succeed
e
s 00003/00031/00258
d D 1.2 80/12/18 00:52:52 wnj 2 1
c dump moans about ``Mount next tape'' unnecessarily; dump is rude
e
s 00289/00000/00000
d D 1.1 80/10/13 17:30:30 root 1 0
c date and time created 80/10/13 17:30:30 by root
e
u
U
f b 
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 12
I 8
#ifndef lint
E 8
I 1
D 12
static	char *sccsid = "%W% (Berkeley) %G%";
I 8
#endif
E 12
I 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12

E 8
D 14
#include "dump.h"
E 14
I 9
D 13
#include <signal.h>
E 13
I 13
#include <sys/file.h>
I 14
#include "dump.h"
E 14
E 13
E 9

D 4
char	tblock[NTREC][BSIZE];
daddr_t	tdaddr[NTREC];
int	trecno;
E 4
I 4
D 6
char	tblock[NTREC][TP_BSIZE];
E 6
I 6
D 17
char	(*tblock)[TP_BSIZE];	/* Pointer to malloc()ed buffer for tape */
int	writesize;		/* Size of malloc()ed buffer for tape */
E 6
int	trecno = 0;
E 17
I 17
char	(*tblock)[TP_BSIZE];	/* pointer to malloc()ed buffer for tape */
int	writesize;		/* size of malloc()ed buffer for tape */
long	lastspclrec = -1;	/* tape block number of last written header */
int	trecno = 0;		/* next record to write in current block */
E 17
I 6
D 9
extern int ntrec;		/* blocking factor on tape */
E 9
I 9
D 14
extern	int ntrec;		/* blocking factor on tape */
I 13
extern	int cartridge;
int	tenths; 		/* length of tape used per block written */
E 14
I 14
extern int ntrec;		/* blocking factor on tape */
extern int cartridge;
extern int read(), write();
#ifdef RDUMP
extern char *host;
#endif RDUMP
E 14
E 13
E 9
E 6
E 4

I 6
/*
D 9
 * Allocate the buffer for tape operations.
 *
 * Depends on global variable ntrec, set from 'b' option in command line.
 * Returns 1 if successful, 0 if failed.
 *
 * For later kernel performance improvement, this buffer should be allocated
 * on a page boundary.
E 9
I 9
D 13
 * Streaming dump mods (Caltech) - disk block reading and tape writing
E 13
I 13
 * Concurrent dump mods (Caltech) - disk block reading and tape writing
E 13
 * are exported to several slave processes.  While one slave writes the
 * tape, the others read disk blocks; they pass control of the tape in
D 13
 * a ring via pipes.  The parent process traverses the filesystem and
 * sends daddr's, inode records, etc, through pipes to each slave.
 * Speed from Eagle to TU77 on VAX/780 is about 140 Kbytes/second.
 * #ifdef RDUMP version is CPU-limited to about 40 Kbytes/second.
E 13
I 13
 * a ring via flock().	The parent process traverses the filesystem and
D 14
 * sends spclrec()'s and lists of daddr's to each slave via pipes.
 *
 * from "@(#)dumptape.c 2.1 (Berkeley+Caltech mods) 4/7/85";
E 14
I 14
 * sends spclrec()'s and lists of daddr's to the slaves via pipes.
E 14
E 13
E 9
 */
I 9
struct req {			/* instruction packets sent to slaves */
	daddr_t dblk;
	int count;
} *req;
int reqsiz;

D 13
#define SLAVES 3		/* 2 slaves read disk while 3rd writes tape */
#define LAG 2			/* Write behind by LAG tape blocks (rdump) */
E 13
I 13
#define SLAVES 3		/* 1 slave writing, 1 reading, 1 for slack */
D 14
int slavepid[SLAVES];
E 13
int slavefd[SLAVES];		/* Pipes from master to each slave */
int rotor;			/* Current slave number */
int master;			/* Pid of master, for sending error signals */
int trace = 0;			/* Protocol trace; easily patchable with adb */
#define  tmsg	if (trace) msg
E 14
I 14
int slavefd[SLAVES];		/* pipes from master to each slave */
int slavepid[SLAVES];		/* used by killall() */
int rotor;			/* next slave to be instructed */
int master;			/* pid of master, for sending error signals */
int tenths;			/* length of tape used per block written */
E 14

D 13
#ifdef RDUMP
extern int rmtape;
#endif

E 13
D 14
/*
D 13
 * Allocate tape buffer contiguous with the array of instruction packets,
 * so they can be written with a single write call in flusht().
E 13
I 13
/* Allocate tape buffer contiguous with the array of instruction
 * packets, so flusht() can write them together with one write().
 * Align tape buffer on page boundary to speed up tape write().
E 13
 */
E 14
E 9
alloctape()
{
D 14

E 14
I 13
	int pgoff = getpagesize() - 1;
I 14

E 14
E 13
	writesize = ntrec * TP_BSIZE;
I 14
	reqsiz = ntrec * sizeof(struct req);
E 14
I 13
	/*
D 14
	 * 92185 NEEDS 0.4"; 92181 NEEDS 0.8" to start/stop (see TU80 manual)
E 14
I 14
	 * CDC 92181's and 92185's make 0.8" gaps in 1600-bpi start/stop mode
	 * (see DEC TU80 User's Guide).  The shorter gaps of 6250-bpi require
	 * repositioning after stopping, i.e, streaming mode, where the gap is
	 * variable, 0.30" to 0.45".  The gap is maximal when the tape stops.
E 14
	 */
D 14
	tenths = writesize/density + (cartridge ? 16 : density == 625 ? 4 : 8);

E 13
D 9
	tblock = (char (*)[TP_BSIZE])malloc(writesize);
	return (tblock != NULL);
E 9
I 9
	reqsiz = ntrec * sizeof(struct req);
E 14
I 14
	tenths = writesize/density + (cartridge ? 16 : density == 625 ? 5 : 8);
	/*
	 * Allocate tape buffer contiguous with the array of instruction
	 * packets, so flusht() can write them together with one write().
	 * Align tape buffer on page boundary to speed up tape write().
	 */
E 14
D 13
	req = (struct req *)malloc(reqsiz+writesize);	/* array of packets */
	tblock = (char (*)[TP_BSIZE]) &req[ntrec];	/* Tape buffer */
	return (req != NULL);
E 13
I 13
	req = (struct req *)malloc(reqsiz + writesize + pgoff);
	if (req == NULL)
		return(0);
	tblock = (char (*)[TP_BSIZE]) (((long)&req[ntrec] + pgoff) &~ pgoff);
D 14
	req = (struct req *)tblock;
	req = &req[-ntrec];	/* Cmd packets go in front of tape buffer */
E 14
I 14
	req = (struct req *)tblock - ntrec;
E 14
	return(1);
E 13
E 9
}

D 9

E 9
I 9
D 14
/*
D 13
 * Send special record to be put on tape
E 13
I 13
 * Make copy of spclrec, to later send to tape writer.
E 13
 */
E 14
I 14

E 14
E 9
E 6
taprec(dp)
D 5
char *dp;
E 5
I 5
	char *dp;
E 5
{
D 8
	register i;
E 8
D 14

D 4
	for(i=0; i<BSIZE; i++)
E 4
I 4
D 5
	for(i=0; i<TP_BSIZE; i++)
E 5
I 5
D 8
	for (i=0; i < TP_BSIZE; i++)
E 5
E 4
		tblock[trecno][i] = *dp++;
E 8
I 8
D 9
	bcopy(dp, tblock[trecno], TP_BSIZE);
E 8
D 4
	tdaddr[trecno] = 0;
E 4
	trecno++;
E 9
I 9
	tmsg("taprec %d\n", trecno);
E 14
	req[trecno].dblk = (daddr_t)0;
	req[trecno].count = 1;
D 13
	*(union u_spcl *)(*tblock++) = *(union u_spcl *)dp;
E 13
I 13
	*(union u_spcl *)(*tblock++) = *(union u_spcl *)dp;	/* movc3 */
I 17
	lastspclrec = spcl.c_tapea;
E 17
	trecno++;
E 13
E 9
	spcl.c_tapea++;
D 6
	if(trecno >= NTREC)
E 6
I 6
D 9
	if(trecno >= ntrec)
E 9
I 9
D 13
	if (++trecno >= ntrec)
E 13
I 13
	if(trecno >= ntrec)
E 13
E 9
E 6
		flusht();
}

D 4
tapsrec(d)
daddr_t d;
E 4
I 4
dmpblk(blkno, size)
	daddr_t blkno;
	int size;
E 4
{
I 4
D 5
	int avail, blks;
E 5
I 5
D 9
	int avail, tpblks, dblkno;
E 9
I 9
D 14
	int tpblks, dblkno;
	register int avail;
E 14
I 14
	int avail, tpblks, dblkno;
E 14
E 9
E 5
E 4

D 4
	if(d == 0)
		return;
	tdaddr[trecno] = d;
	trecno++;
	spcl.c_tapea++;
E 4
I 4
D 5
	if (size % FRAG != 0)
E 5
I 5
D 13
	if (size % TP_BSIZE != 0)
E 5
		msg("bad size to dmpblk: %d\n", size);
E 13
D 6
	avail = NTREC - trecno;
E 6
I 6
D 9
	avail = ntrec - trecno;
E 9
E 6
D 5
	for (blks = size / TP_BSIZE; blks > avail; ) {
		bread(blkno, tblock[trecno], TP_BSIZE * avail);
E 5
I 5
	dblkno = fsbtodb(sblock, blkno);
D 9
	for (tpblks = size / TP_BSIZE; tpblks > avail; ) {
		bread(dblkno, tblock[trecno], TP_BSIZE * avail);
E 9
I 9
	tpblks = size / TP_BSIZE;
	while ((avail = MIN(tpblks, ntrec - trecno)) > 0) {
D 14
		tmsg("dmpblk %d\n", avail);
E 14
		req[trecno].dblk = dblkno;
		req[trecno].count = avail;
I 14
		trecno += avail;
E 14
E 9
E 5
D 13
		trecno += avail;
E 13
		spcl.c_tapea += avail;
D 9
		flusht();
E 9
I 9
D 13
		if (trecno >= ntrec)
E 13
I 13
D 14
		if ((trecno += avail) >= ntrec)
E 14
I 14
		if (trecno >= ntrec)
E 14
E 13
			flusht();
E 9
D 5
		blkno += avail;
		blks -= avail;
E 5
I 5
D 19
		dblkno += avail * (TP_BSIZE / DEV_BSIZE);
E 19
I 19
		dblkno += avail * (TP_BSIZE / dev_bsize);
E 19
		tpblks -= avail;
E 5
D 6
		avail = NTREC - trecno;
E 6
I 6
D 9
		avail = ntrec - trecno;
E 9
E 6
	}
D 5
	bread(blkno, tblock[trecno], TP_BSIZE * blks);
	trecno += blks;
	spcl.c_tapea += blks;
E 5
I 5
D 9
	bread(dblkno, tblock[trecno], TP_BSIZE * tpblks);
	trecno += tpblks;
	spcl.c_tapea += tpblks;
E 5
E 4
D 6
	if(trecno >= NTREC)
E 6
I 6
	if(trecno >= ntrec)
E 6
		flusht();
E 9
}

int	nogripe = 0;

I 9
tperror() {
	if (pipeout) {
		msg("Tape write error on %s\n", tape);
		msg("Cannot recover\n");
		dumpabort();
		/* NOTREACHED */
	}
D 14
	msg("Tape write error on tape %d\n", tapeno);
E 14
I 14
	msg("Tape write error %d feet into tape %d\n", asize/120L, tapeno);
E 14
	broadcast("TAPE ERROR!\n");
	if (!query("Do you want to restart?"))
		dumpabort();
	msg("This tape will rewind.  After it is rewound,\n");
	msg("replace the faulty tape with a new one;\n");
	msg("this dump volume will be rewritten.\n");
I 13
	killall();
E 13
	nogripe = 1;
	close_rewind();
	Exit(X_REWRITE);
}

D 13
senderr()
{

D 11
	perror("dump: pipe error in command to slave");
E 11
I 11
	perror("  DUMP: pipe error in command to slave");
E 11
	dumpabort();
}

E 13
D 14
#ifdef RDUMP
tflush(cnt)
	int cnt;
E 14
I 14
sigpipe()
E 14
{
I 14

	msg("Broken pipe\n");
	dumpabort();
}

#ifdef RDUMP
/*
 * compatibility routine
 */
tflush(i)
E 14
	int i;
I 14
{
E 14

	for (i = 0; i < ntrec; i++)
		spclrec();
}
#endif RDUMP

E 9
flusht()
{
D 9
	register i, si;
	daddr_t d;
E 9
I 9
D 14
	int sig, siz = (char *)tblock - (char *)req;
E 14
I 14
	int siz = (char *)tblock - (char *)req;
E 14
E 9

I 9
D 14
	tmsg("flusht %d\n", siz);
D 13
	sig = sigblock(1<<SIGINT-1 | 1<<SIGIOT-1);  /* Don't interrupt write */
	if (write(slavefd[rotor], req, siz) != siz)
		senderr();
E 13
I 13
	sig = sigblock(1 << SIGINT-1);		/* Don't abort pipe write */
	if (write(slavefd[rotor], req, siz) != siz) {
		perror("  DUMP: pipe error in command to slave");
E 14
I 14
	if (atomic(write, slavefd[rotor], req, siz) != siz) {
		perror("  DUMP: error writing command pipe");
E 14
		dumpabort();
	}
E 13
D 14
	sigsetmask(sig);
E 14
	if (++rotor >= SLAVES) rotor = 0;
	tblock = (char (*)[TP_BSIZE]) &req[ntrec];
E 9
D 4
	while(trecno < NTREC)
		tdaddr[trecno++] = 1;

loop:
	d = 0;
	for(i=0; i<NTREC; i++)
		if(tdaddr[i] != 0)
		if(d == 0 || tdaddr[i] < d) {
			si = i;
			d = tdaddr[i];
		}
	if(d != 0) {
		bread(d, tblock[si], BSIZE);
		tdaddr[si] = 0;
		goto loop;
	}
E 4
	trecno = 0;
D 6
	if (write(to, tblock[0], sizeof(tblock)) != sizeof(tblock) ){
E 6
I 6
D 9
	if (write(to, tblock[0], writesize) != writesize){
I 7
		if (pipeout) {
			msg("Tape write error on %s\n", tape);
			msg("Cannot recover\n");
			dumpabort();
			/* NOTREACHED */
		}
E 7
E 6
		msg("Tape write error on tape %d\n", tapeno);
		broadcast("TAPE ERROR!\n");
		if (query("Do you want to restart?")){
			msg("This tape will rewind.  After it is rewound,\n");
			msg("replace the faulty tape with a new one;\n");
D 2
			msg("this dump volumne will be rewritten.\n");
E 2
I 2
			msg("this dump volume will be rewritten.\n");
E 2
			/*
			 *	Temporarily change the tapeno identification
			 */
			tapeno--;
			nogripe = 1;
			close_rewind();
			nogripe = 0;
			tapeno++;
			Exit(X_REWRITE);
		} else {
			dumpabort();
			/*NOTREACHED*/
		}
	}

E 9
D 6
	asize += sizeof(tblock)/density;
E 6
I 6
D 13
	asize += writesize/density;
E 6
D 9
	asize += 7;
E 9
I 9
	asize += 7;			/* inter-record gap (why fixed?) */
E 13
I 13
	asize += tenths;
E 13
E 9
D 6
	blockswritten += NTREC;
E 6
I 6
	blockswritten += ntrec;
E 6
D 7
	if (asize > tsize) {
E 7
I 7
	if (!pipeout && asize > tsize) {
E 7
		close_rewind();
		otape();
	}
	timeest();
}

rewind()
{
D 9
	int	secs;
I 3
	int f;
E 9
I 9
D 13
	register int f;
E 13
I 13
	int f;
E 13
E 9
I 7

	if (pipeout)
		return;
E 7
E 3
D 9
#ifdef DEBUG
	msg("Waiting 10 seconds to rewind.\n");
	sleep(10);
E 9
I 9
	for (f = 0; f < SLAVES; f++)
		close(slavefd[f]);
	while (wait(NULL) >= 0)    ;	/* wait for any signals from slaves */
	msg("Tape rewinding\n");
#ifdef RDUMP
D 14
	rmtclose();
	while (rmtopen(tape, 0) < 0)
		sleep(10);
	rmtclose();
E 9
#else
E 14
I 14
	if (host) {
		rmtclose();
		while (rmtopen(tape, 0) < 0)
			sleep(10);
		rmtclose();
		return;
	}
#endif RDUMP
E 14
D 9
	/*
	 *	It takes about 3 minutes, 25secs to rewind 2300' of tape
	 */
D 3
	secs = (( (60*3) + 25)*asize)/(2300L*12L*10L);
	msg("Waiting %d seconds to rewind.\n", secs);
	sleep(secs);
E 3
I 3
	msg("Tape rewinding\n", secs);
E 9
	close(to);
	while ((f = open(tape, 0)) < 0)
		sleep (10);
	close(f);
E 3
D 13
#endif
E 13
I 13
D 14
#endif RDUMP
E 14
E 13
}

close_rewind()
{
I 7
D 9

	if (pipeout)
		return;
E 7
	close(to);
	if (!nogripe){
		rewind();
E 9
I 9
	rewind();
	if (!nogripe) {
E 9
		msg("Change Tapes: Mount tape #%d\n", tapeno+1);
		broadcast("CHANGE TAPES!\7\7\n");
	}
D 9
	do{
		if (query ("Is the new tape mounted and ready to go?"))
			break;
		if (query ("Do you want to abort?")){
E 9
I 9
	while (!query("Is the new tape mounted and ready to go?"))
D 14
		if (query("Do you want to abort?"))
E 14
I 14
		if (query("Do you want to abort?")) {
E 14
E 9
			dumpabort();
I 14
			/*NOTREACHED*/
		}
E 14
D 9
			/*NOTREACHED*/
		}
	} while (1);
E 9
}

/*
D 9
 *	We implement taking and restoring checkpoints on
 *	the tape level.
E 9
I 9
 *	We implement taking and restoring checkpoints on the tape level.
E 9
 *	When each tape is opened, a new process is created by forking; this
 *	saves all of the necessary context in the parent.  The child
 *	continues the dump; the parent waits around, saving the context.
 *	If the child returns X_REWRITE, then it had problems writing that tape;
 *	this causes the parent to fork again, duplicating the context, and
 *	everything continues as if nothing had happened.
 */

otape()
{
	int	parentpid;
	int	childpid;
	int	status;
	int	waitpid;
D 9
	int	sig_ign_parent();
E 9
D 13
	int	interrupt();
E 13
I 13
D 14
	int	(*interrupt)();
E 14
I 14
	int	(*interrupt)() = signal(SIGINT, SIG_IGN);
I 17
	int	blks, i;
E 17
E 14
E 13

D 9
	/*
	 *	Force the tape to be closed
	 */
	close(to);
E 9
	parentpid = getpid();

    restore_check_point:
D 13
	signal(SIGINT, interrupt);
	/*
	 *	All signals are inherited...
	 */
E 13
I 13
D 14
	interrupt = signal(SIGINT, SIG_IGN);
E 14
I 14
	signal(SIGINT, interrupt);
	/*
	 *	All signals are inherited...
	 */
E 14
E 13
	childpid = fork();
D 9
	if (childpid < 0){
E 9
I 9
	if (childpid < 0) {
E 9
		msg("Context save fork fails in parent %d\n", parentpid);
		Exit(X_ABORT);
	}
D 9
	if (childpid != 0){
E 9
I 9
	if (childpid != 0) {
E 9
		/*
		 *	PARENT:
		 *	save the context by waiting
		 *	until the child doing all of the work returns.
D 9
		 *	don't catch the interrupt 
E 9
I 9
		 *	don't catch the interrupt
E 9
		 */
I 14
		signal(SIGINT, SIG_IGN);
E 14
D 13
		signal(SIGINT, SIG_IGN);
E 13
#ifdef TDEBUG
		msg("Tape: %d; parent process: %d child process %d\n",
			tapeno+1, parentpid, childpid);
#endif TDEBUG
D 9
		for (;;){
			waitpid = wait(&status);
			if (waitpid != childpid){
				msg("Parent %d waiting for child %d has another child %d return\n",
					parentpid, childpid, waitpid);
			} else
				break;
		}
		if (status & 0xFF){
E 9
I 9
		while ((waitpid = wait(&status)) != childpid)
			msg("Parent %d waiting for child %d has another child %d return\n",
				parentpid, childpid, waitpid);
		if (status & 0xFF) {
E 9
			msg("Child %d returns LOB status %o\n",
				childpid, status&0xFF);
		}
		status = (status >> 8) & 0xFF;
#ifdef TDEBUG
D 9
		switch(status){
E 9
I 9
		switch(status) {
E 9
			case X_FINOK:
				msg("Child %d finishes X_FINOK\n", childpid);
				break;
			case X_ABORT:
				msg("Child %d finishes X_ABORT\n", childpid);
				break;
			case X_REWRITE:
				msg("Child %d finishes X_REWRITE\n", childpid);
				break;
			default:
D 9
				msg("Child %d finishes unknown %d\n", childpid,status);
E 9
I 9
				msg("Child %d finishes unknown %d\n",
D 14
				    childpid, status);
E 14
I 14
					childpid, status);
E 14
E 9
				break;
		}
#endif TDEBUG
D 9
		switch(status){
E 9
I 9
		switch(status) {
E 9
			case X_FINOK:
				Exit(X_FINOK);
			case X_ABORT:
				Exit(X_ABORT);
			case X_REWRITE:
				goto restore_check_point;
			default:
				msg("Bad return code from dump: %d\n", status);
				Exit(X_ABORT);
		}
		/*NOTREACHED*/
	} else {	/* we are the child; just continue */
#ifdef TDEBUG
		sleep(4);	/* allow time for parent's message to get out */
		msg("Child on Tape %d has parent %d, my pid = %d\n",
			tapeno+1, parentpid, getpid());
D 14
#endif
I 13
		signal(SIGINT, interrupt);
E 14
I 14
#endif TDEBUG
E 14
E 13
D 9
		do{
D 7
			to = creat(tape, 0666);
E 7
I 7
			if (pipeout)
				to = 1;
			else
				to = creat(tape, 0666);
E 7
			if (to < 0) {
				if (!query("Cannot open tape. Do you want to retry the open?"))
					dumpabort();
			} else break;
		} while (1);
E 9
I 9
#ifdef RDUMP
D 14
		while ((to = rmtopen(tape, 2)) < 0)
#else
E 14
I 14
		while ((to = (host ? rmtopen(tape, 2) :
			pipeout ? 1 : creat(tape, 0666))) < 0)
#else RDUMP
E 14
		while ((to = pipeout ? 1 : creat(tape, 0666)) < 0)
D 13
#endif
E 13
I 13
#endif RDUMP
E 13
			if (!query("Cannot open tape.  Do you want to retry the open?"))
				dumpabort();
E 9

I 9
		enslave();  /* Share open tape file descriptor with slaves */

E 9
		asize = 0;
		tapeno++;		/* current tape sequence */
		newtape++;		/* new tape signal */
I 17
		blks = 0;
		if (spcl.c_type != TS_END)
			for (i = 0; i < spcl.c_count; i++)
				if (spcl.c_addr[i] != 0)
					blks++;
		spcl.c_count = blks + 1 - spcl.c_tapea + lastspclrec;
E 17
		spcl.c_volume++;
		spcl.c_type = TS_TAPE;
I 18
		spcl.c_flags |= DR_NEWHEADER;
E 18
		spclrec();
I 18
		spcl.c_flags &=~ DR_NEWHEADER;
E 18
		if (tapeno > 1)
			msg("Tape %d begins with blocks from ino %d\n",
				tapeno, ino);
	}
}

D 9
/*
 *	The parent still catches interrupts, but does nothing with them
 */
sig_ign_parent()
{
	msg("Waiting parent receives interrupt\n");
	signal(SIGINT, sig_ign_parent);
}

E 9
dumpabort()
{
I 9
	if (master != 0 && master != getpid())
D 13
		kill(master, SIGIOT);
E 9
D 2
	msg("The ENTIRE dump is aborted.  NO second chances (tough luck sucker).\n");
E 2
I 2
	msg("The ENTIRE dump is aborted.\n");
E 13
I 13
D 14
		kill(master, SIGPIPE);
E 14
I 14
		kill(master, SIGTERM);	/* Signals master to call dumpabort */
E 14
	else {
		killall();
		msg("The ENTIRE dump is aborted.\n");
	}
E 13
E 2
	Exit(X_ABORT);
}

Exit(status)
{
#ifdef TDEBUG
	msg("pid = %d exits with status %d\n", getpid(), status);
#endif TDEBUG
D 2
	henryexit(status);
}

#ifdef TDEBUG
exit(status)
	/*ARGSUSED*/
{
	fflush(stdout);
	fprintf(stderr, "Somebody called exit: halt executed\n");
	fflush(stderr);
	abort();
}

_exit(status)
	/*ARGSUSED*/
{
	fflush(stdout);
	fprintf(stderr, "Somebody called _exit: halt executed\n");
	fflush(stderr);
	abort();
}
#endif TDEBUG

henryexit(status)
	/* ARGSUSED */
{
	_cleanup();
	asm("	chmk	$1");
	asm("halt");
E 2
I 2
	exit(status);
I 9
}

D 13
#define OK 020
char tok = OK;
E 13
I 13
/*
D 14
 * prefer pipe(), but flock() barfs on them
E 14
I 14
 * could use pipe() for this if flock() worked on pipes
E 14
 */
lockfile(fd)
	int fd[2];
{
	char tmpname[20];
E 13

I 13
	strcpy(tmpname, "/tmp/dumplockXXXXXX");
	mktemp(tmpname);
D 15
	if ((fd[1] = creat(tmpname, 0400)) < 0)
		return(fd[1]);
	fd[0] = open(tmpname, 0);
E 15
I 15
	if ((fd[1] = creat(tmpname, 0400)) < 0) {
		msg("Could not create lockfile ");
		perror(tmpname);
		dumpabort();
	}
	if ((fd[0] = open(tmpname, 0)) < 0) {
		msg("Could not reopen lockfile ");
		perror(tmpname);
		dumpabort();
	}
E 15
	unlink(tmpname);
D 15
	return (fd[0] < 0 ? fd[0] : 0);
E 15
}

E 13
enslave()
{
D 13
	int prev[2], next[2], cmd[2];	/* file descriptors for pipes */
D 11
	int i, j, slavepid;
E 11
I 11
	int i, j, ret, slavepid;
E 13
I 13
	int first[2], prev[2], next[2], cmd[2];     /* file descriptors */
	register int i, j;
E 13
E 11

	master = getpid();
D 13
	signal(SIGPIPE, dumpabort);
	signal(SIGIOT, tperror); /* SIGIOT asks for restart from checkpoint */
	pipe(prev);
	for (i = rotor = 0; i < SLAVES; ++i) {
		if ((i < SLAVES - 1 && pipe(next) < 0) || pipe(cmd) < 0
				|| (slavepid = fork()) < 0) {
			perror("  DUMP: too many slaves");
E 13
I 13
D 14
	signal(SIGPIPE, dumpabort);  /* Slave quit/died/killed -> abort */
	signal(SIGIOT, tperror);     /* SIGIOT -> restart from checkpoint */
E 14
I 14
	signal(SIGTERM, dumpabort); /* Slave sends SIGTERM on dumpabort() */
	signal(SIGPIPE, sigpipe);
	signal(SIGUSR1, tperror);    /* Slave sends SIGUSR1 on tape errors */
E 14
	lockfile(first);
	for (i = 0; i < SLAVES; i++) {
		if (i == 0) {
			prev[0] = first[1];
			prev[1] = first[0];
		} else {
			prev[0] = next[0];
			prev[1] = next[1];
			flock(prev[1], LOCK_EX);
		}
D 15
		next[0] = first[0];
		next[1] = first[1];	    /* Last slave loops back */
		if ((i < SLAVES-1 && lockfile(next) < 0) || pipe(cmd) < 0
				|| (slavepid[i] = fork()) < 0) {
			perror("  DUMP: too many slaves (recompile smaller)");
E 15
I 15
		if (i < SLAVES - 1) {
			lockfile(next);
		} else {
			next[0] = first[0];
			next[1] = first[1];	    /* Last slave loops back */
		}
		if (pipe(cmd) < 0 || (slavepid[i] = fork()) < 0) {
			msg("too many slaves, %d (recompile smaller) ", i);
			perror("");
E 15
E 13
			dumpabort();
		}
D 13
		if (i >= SLAVES - 1)
			next[1] = prev[1];	    /* Last slave loops back */
E 13
		slavefd[i] = cmd[1];
D 13
		if (slavepid == 0) {		    /* Slave starts up here */
E 13
I 13
D 14
		if (slavepid[i] == 0) {		    /* Slave starts up here */
E 14
I 14
		if (slavepid[i] == 0) { 	    /* Slave starts up here */
E 14
E 13
			for (j = 0; j <= i; j++)
				close(slavefd[j]);
D 13
			if (i < SLAVES - 1) {
				close(prev[1]);
				close(next[0]);
			} else {		    /* Insert initial token */
D 11
				if (write(next[1], &tok, 1) != 1)
					ringerr();
E 11
I 11
				if ((ret = write(next[1], &tok, 1)) != 1)
					ringerr(ret, "cannot start token");
E 11
			}
			doslave(i, cmd[0], prev[0], next[1]);
			close(next[1]);
			j = read(prev[0], &tok, 1);   /* Eat the final token */
#ifdef RDUMP				    /* Read remaining acknowledges */
			for (; j > 0 && (tok &~ OK) > 0; tok--) {
				if (rmtwrite2() != writesize && (tok & OK)) {
					kill(master, SIGIOT);
					tok &= ~OK;
				}
			}
#endif
E 13
I 13
D 14
			signal(SIGINT, SIG_IGN);     /* Master handles these */
			signal(SIGTERM, SIG_IGN);
			doslave(i, cmd[0], prev, next);
E 14
I 14
			signal(SIGINT, SIG_IGN);    /* Master handles this */
			doslave(cmd[0], prev, next);
E 14
E 13
			Exit(X_FINOK);
		}
		close(cmd[0]);
D 13
		close(next[1]);
		close(prev[0]);
		prev[0] = next[0];
E 13
I 13
		if (i > 0) {
			close(prev[0]);
			close(prev[1]);
		}
E 13
	}
D 13
	master = 0;
E 13
I 13
	close(first[0]);
	close(first[1]);
	master = 0; rotor = 0;
E 13
}

D 13
/*
 * Somebody must have died, should never happen
 */
D 11
ringerr()
E 11
I 11
ringerr(code, msg, a1, a2)
	int code;
	char *msg;
	int a1, a2;
E 13
I 13
killall()
E 13
E 11
{
D 11
	perror("  DUMP: token passing error");
E 11
I 11
D 13
	char buf[BUFSIZ];
E 13
I 13
	register int i;
E 13

D 13
	fprintf(stderr, "  DUMP: ");
	sprintf(buf, msg, a1, a2);
	if (code < 0)
		perror(msg);
	else if (code == 0)
		fprintf(stderr, "%s: unexpected EOF\n", buf);
	else
		fprintf(stderr, "%s: code %d\n", buf, code);
E 11
	kill(master, SIGPIPE);
	Exit(X_ABORT);
E 13
I 13
	for (i = 0; i < SLAVES; i++)
		if (slavepid[i] > 0)
			kill(slavepid[i], SIGKILL);
E 13
}

I 11
D 13
int childnum;
sigpipe()
E 13
I 13
/*
 * Synchronization - each process has a lockfile, and shares file
 * descriptors to the following process's lockfile.  When our write
 * completes, we release our lock on the following process's lock-
 * file, allowing the following process to lock it and proceed. We
 * get the lock back for the next cycle by swapping descriptors.
 */
D 14
doslave(mynum,cmd,prev,next)
	int mynum, cmd, prev[2], next[2];
E 14
I 14
doslave(cmd, prev, next)
	register int cmd, prev[2], next[2];
E 14
E 13
{
I 13
D 14
	register int toggle = 0, firstdone = mynum;
E 14
I 14
	register int nread, toggle = 0;
E 14
E 13

D 13
	ringerr(childnum, "SIGPIPE raised");
}

E 11
doslave(num, cmd, prev, next)
	int num, cmd, prev, next;
{
I 11
	int ret;

E 11
	tmsg("slave %d\n", num);
	signal(SIGINT, SIG_IGN); 		/* Master handles it */
	signal(SIGTERM, SIG_IGN);
D 11
	signal(SIGPIPE, ringerr);
E 11
I 11
	signal(SIGPIPE, sigpipe);
	childnum = num;
E 13
I 13
D 14
	tmsg("slave %d\n", mynum);
E 14
E 13
E 11
	close(fi);
D 14
	if ((fi = open(disk, 0)) < 0) {		/* Need our own seek pointer */
E 14
I 14
	if ((fi = open(disk, 0)) < 0) { 	/* Need our own seek pointer */
E 14
D 13
		perror("  DUMP: can't reopen disk");
		kill(master, SIGPIPE);
E 13
I 13
		perror("  DUMP: slave couldn't reopen disk");
D 14
		kill(master, SIGPIPE);		/* dumpabort */
E 13
		Exit(X_ABORT);
E 14
I 14
		dumpabort();
E 14
	}
D 10
	while (read(cmd, req, reqsiz) == reqsiz) {
E 10
I 10
D 11
	while (readpipe(cmd, req, reqsiz) == reqsiz) {
E 11
I 11
D 13
	while ((ret = readpipe(cmd, req, reqsiz)) == reqsiz) {
E 13
I 13
	/*
D 14
	 * Get list of blocks to dump
E 14
I 14
	 * Get list of blocks to dump, read the blocks into tape buffer
E 14
	 */
D 14
	while (readpipe(cmd, req, reqsiz) > 0) {
E 14
I 14
	while ((nread = atomic(read, cmd, req, reqsiz)) == reqsiz) {
E 14
E 13
E 11
E 10
		register struct req *p = req;
		for (trecno = 0; trecno < ntrec; trecno += p->count, p += p->count) {
			if (p->dblk) {
D 13
				tmsg("%d READS %d\n", num, p->count);
E 13
I 13
D 14
				tmsg("%d READS %d\n", mynum, p->count);
E 14
E 13
				bread(p->dblk, tblock[trecno],
D 14
				    p->count * TP_BSIZE);
E 14
I 14
					p->count * TP_BSIZE);
E 14
			} else {
D 13
				tmsg("%d PIPEIN %d\n", num, p->count);
				if (p->count != 1)
D 11
					ringerr();
E 11
I 11
					ringerr(11, "%d PIPEIN %d", num,
						p->count);
E 11
D 10
				if (read(cmd, tblock[trecno], TP_BSIZE) != TP_BSIZE)
E 10
I 10
				if (readpipe(cmd, tblock[trecno], TP_BSIZE) != TP_BSIZE)
E 10
					senderr();
E 13
I 13
D 14
				tmsg("%d PIPEIN %d\n", mynum, p->count);
				if (p->count != 1 ||
				    readpipe(cmd, tblock[trecno], TP_BSIZE) <= 0) {
E 14
I 14
				if (p->count != 1 || atomic(read, cmd,
				    tblock[trecno], TP_BSIZE) != TP_BSIZE) {
E 14
D 16
					msg("Master/slave protocol botched");
E 16
I 16
					msg("Master/slave protocol botched.\n");
E 16
					dumpabort();
				}
E 13
			}
		}
D 11
		if (read(prev, &tok, 1) != 1)
			ringerr();	/* Wait your turn */
E 11
I 11
D 13
		if ((ret = read(prev, &tok, 1)) != 1)
			ringerr(ret, "read token");	/* Wait your turn */
E 11
		tmsg("%d WRITE\n", num);
E 13
I 13
		flock(prev[toggle], LOCK_EX);	/* Wait our turn */
D 14
		tmsg("%d WRITE\n", mynum);
E 14
I 14

E 14
E 13
#ifdef RDUMP
D 13
		if (tok & OK) {
			rmtwrite0(writesize);
			rmtwrite1(tblock[0], writesize);
			tok++;		/* Number of writes in progress */
		}
		if (tok > (LAG|OK) && (--tok, rmtwrite2() != writesize)) {
E 13
I 13
D 14
#ifndef sun	/* Defer checking first write until next one is started */
		rmtwrite0(writesize);
		rmtwrite1(tblock[0],writesize);
		if (firstdone == 0) firstdone = -1;
		else if (rmtwrite2() != writesize) {
			rmtwrite2();		/* Don't care if another err */
E 13
#else
D 13
		if ((tok & OK) &&
		    write(to, tblock[0], writesize) != writesize) {
E 13
I 13
		/* Asynchronous writes can hang Suns; do it synchronously */
		if (rmtwrite(tblock[0],writesize) != writesize) {
#endif sun
#else		/* Local tape drive */
		if (write(to,tblock[0],writesize) != writesize) {
E 13
			perror(tape);
E 14
I 14
		if ((host ? rmtwrite(tblock[0], writesize)
			: write(to, tblock[0], writesize)) != writesize) {
#else RDUMP
		if (write(to, tblock[0], writesize) != writesize) {
E 14
D 13
#endif
E 13
I 13
#endif RDUMP
E 13
D 14
			kill(master, SIGIOT);	/* restart from checkpoint */
D 13
			tok &= ~OK;
E 13
I 13
			for (;;) sigpause(0);
E 14
I 14
			kill(master, SIGUSR1);
			for (;;)
				sigpause(0);
E 14
E 13
		}
D 11
		if (write(next, &tok, 1) != 1)
			ringerr(); /* Next slave's turn */
E 11
I 11
D 13
		if ((ret = write(next, &tok, 1)) != 1)
			ringerr(ret, "write token"); /* Next slave's turn */
E 13
I 13
		toggle ^= 1;
		flock(next[toggle], LOCK_UN);	/* Next slave's turn */
	}					/* Also jolts him awake */
D 14
#ifdef RDUMP			/* One more time around, to check last write */
#ifndef sun
	flock(prev[toggle], LOCK_EX);
	tmsg("%d LAST\n", mynum);
	if (firstdone < 0 && rmtwrite2() != writesize) {
		kill(master, SIGIOT);
		for (;;)
			sigpause(0);
E 14
I 14
	if (nread != 0) {
		perror("  DUMP: error reading command pipe");
		dumpabort();
E 14
E 13
E 11
	}
I 11
D 13
	if (ret != 0)
		ringerr(ret, "partial record?");
E 11
	tmsg("%d CLOSE\n", num);
E 13
I 13
D 14
	toggle ^= 1;
	flock(next[toggle], LOCK_UN);
#endif sun
#endif RDUMP
E 14
E 13
I 10
}

/*
D 14
 * Since a read from a pipe may not return all we asked for
 * we must loop until we get all we need
E 14
I 14
 * Since a read from a pipe may not return all we asked for,
 * or a write may not write all we ask if we get a signal,
 * loop until the count is satisfied (or error).
E 14
 */
D 14
readpipe(fd, buf, cnt)
	int fd;
E 14
I 14
atomic(func, fd, buf, count)
	int (*func)(), fd, count;
E 14
	char *buf;
D 14
	int cnt;
E 14
{
D 14
	int rd, got;
E 14
I 14
	int got, need = count;
E 14

D 14
	for (rd = cnt; rd > 0; rd -= got) {
		got = read(fd, buf, rd);
D 13
		if (got < 0)
			return (got);
		if (got == 0)
			return (cnt - rd);
E 13
I 13
		if (got <= 0) {
			if (rd == cnt && got == 0)
				return (0);		/* Normal EOF */
			msg("short pipe read");
			dumpabort();
		}
E 14
I 14
	while ((got = (*func)(fd, buf, need)) > 0 && (need -= got) > 0)
E 14
E 13
		buf += got;
D 14
	}
	return (cnt);
E 14
I 14
	return (got < 0 ? got : count - need);
E 14
E 10
E 9
E 2
}
E 1
