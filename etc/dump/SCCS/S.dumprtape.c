h09010
s 00008/00001/00267
d D 1.5 83/08/11 14:27:46 mckusick 5 4
c allow recovery from bad tapes, but not crashed remote machines
e
s 00038/00013/00230
d D 1.4 83/02/11 12:58:33 sam 4 3
c merge from sun
e
s 00001/00002/00242
d D 1.3 82/10/11 18:15:45 mckusick 3 2
c give up when host goes down.
e
s 00020/00004/00224
d D 1.2 82/05/20 15:11:14 sam 2 1
c convert to calder
e
s 00228/00000/00000
d D 1.1 82/05/10 14:45:11 sam 1 0
c date and time created 82/05/10 14:45:11 by sam
e
u
U
t
T
I 1
static	char *sccsid = "%W% %E%";

#include "dump.h"

/*
D 4
 * tape buffering routines: double buffer for remote dump.
E 4
I 4
 * tape buffering routines double buffer for remote dump.
E 4
 * tblock[1-rotor] is written to remote in tape order
 * as tblock[rotor] is filled in in seek order.
 */
I 4

E 4
struct	atblock {
D 2
	char	tblock[BSIZE];
E 2
I 2
	char	tblock[TP_BSIZE];
E 2
D 4
} tblock[2][NTREC];
E 4
I 4
};
struct atblock *tblock[2]; 	/* Pointers to malloc()ed buffers for tape */
int	writesize;		/* Size of single malloc()ed buffer for tape */
E 4
int	trotor = 0;
D 4
daddr_t	tdaddr[NTREC];
E 4
I 4
daddr_t *tdaddr;		/* Pointer to array of disk addrs */
E 4
int	toldindex, tcurindex, trecno;
I 4
extern int ntrec;		/* blocking factor on tape */
E 4

I 4
/*
 * Allocate the buffer for tape operations.
 *
 * Depends on global variable ntrec, set from 'b' option in command line.
 * Returns 1 if successful, 0 if failed.
 *
 * For later kernel performance improvement, this buffer should be allocated
 * on a page boundary.
 */
alloctape()
{

	writesize = ntrec * TP_BSIZE;
	tblock[0] = (struct atblock *)malloc(2 * writesize);
	if (tblock[0] == 0)
		return (0);
	tblock[1] = tblock[0]+ntrec;	/* Point to second bigbuffer */
	tdaddr = (daddr_t *)malloc(ntrec * sizeof(daddr_t));
	return (tdaddr != NULL);
}

E 4
taprec(dp)
	char *dp;
{
	register i;
	register struct atblock *bp = tblock[tcurindex];

	tadvance();
	tdaddr[tcurindex] = 0;
	*(&tblock[trotor][tcurindex++]) = *(struct atblock *)dp;
	spcl.c_tapea++;
D 4
	if (tcurindex >= NTREC)
E 4
I 4
	if (tcurindex >= ntrec)
E 4
		flusht();
}

I 2
dmpblk(blkno, size)
	daddr_t blkno;
	int size;
{
	int tpblks, dblkno;

	if (size % TP_BSIZE != 0)
		msg("bad size to dmpblk: %d\n", size);
	dblkno = fsbtodb(sblock, blkno);
	for (tpblks = size / TP_BSIZE; tpblks > 0; tpblks--) {
		tapsrec(dblkno);
		dblkno += TP_BSIZE / DEV_BSIZE;
	}
}

E 2
int	nogripe = 0;

tadvance()
{

	if (trecno == 0)
		return;
	if (toldindex == 0)
D 2
		rmtwrite0(BSIZE * NTREC);
	rmtwrite1((char *)(&tblock[1 - trotor][toldindex++]), BSIZE);
E 2
I 2
D 4
		rmtwrite0(TP_BSIZE * NTREC);
E 4
I 4
		rmtwrite0(TP_BSIZE * ntrec);
E 4
	rmtwrite1((char *)(&tblock[1 - trotor][toldindex++]), TP_BSIZE);
E 2
D 4
	if (toldindex != NTREC)
E 4
I 4
	if (toldindex != ntrec)
E 4
		return;
	toldindex = 0;
D 4
	if (rmtwrite2() != sizeof (tblock[0])) {
E 4
I 4
	if (rmtwrite2() != writesize) {
E 4
		msg("Write error on tape %d\n", tapeno);
		broadcast("TAPE ERROR!\n");
		if (query("Restart this tape?") == 0)
			dumpabort();
		msg("After this tape rewinds, replace the reel\n");
		msg("and the dump volume will be rewritten.\n");
		close_rewind();
		exit(X_REWRITE);
	}
}

close_rewind()
{

	rewind();
	tnexttape();
}

/* pad out last tape block */
tfillspec()
{

	while (tcurindex)
		spclrec();
}

tapsrec(d)
	daddr_t d;
{

	if (d == 0)
		return;
	tdaddr[tcurindex] = d;
	tcurindex++;
	spcl.c_tapea++;
D 4
	if (tcurindex >= NTREC)
E 4
I 4
	if (tcurindex >= ntrec)
E 4
		flusht();
}

flusht()
{
	register i, si;
	daddr_t d;

D 4
	while (tcurindex < NTREC)
E 4
I 4
	while (tcurindex < ntrec)
E 4
		tdaddr[tcurindex++] = 1;
loop:
	d = 0;
D 4
	for (i=0; i<NTREC; i++)
E 4
I 4
	for (i=0; i<ntrec; i++)
E 4
		if (tdaddr[i] != 0)
			if (d == 0 || tdaddr[i] < d) {
				si = i;
				d = tdaddr[i];
			}
	if (d != 0) {
		tadvance();
D 2
		bread(d, (char *)&tblock[trotor][si], BSIZE);
E 2
I 2
		bread(d, (char *)&tblock[trotor][si], TP_BSIZE);
E 2
		tdaddr[si] = 0;
		goto loop;
	}
	tcurindex = 0;
	trecno++;
	trotor = 1 - trotor;
D 4
	asize += sizeof(tblock[trotor])/density;
E 4
I 4
	asize += writesize/density;
E 4
	asize += 7;
D 4
	blockswritten += NTREC;
E 4
I 4
	blockswritten += ntrec;
E 4
	if (asize > tsize) {
		tflush(0);
		rewind();
		msg("Change Tapes: Mount tape #%d\n", tapeno+1);
		broadcast("CHANGE TAPES!\7\7\n");
		tnexttape();
		otape();
		/* returns in child */
	}
	timeest();
}

tflush(eof)
	int eof;
{
	int i;

	if (eof) {
		do {
			spclrec();
		} while (tcurindex);
	}
D 4
	for (i = 0; i < NTREC; i++)
E 4
I 4
	for (i = 0; i < ntrec; i++)
E 4
		tadvance();
}

tnexttape()
{

again:
	if (query("Next tape ready?") == 1)
		return;
	if (query("Want to abort?") == 1)
		dumpabort();
	goto again;
}

rewind()
{

	msg("Tape rewinding\n");
	rmtclose();
	while (rmtopen(tape, 0, 0) < 0)
		sleep(10);
	rmtclose();
}

otape()
{
	int ppid, child, status;
	int w, interrupt();

	rmtclose();
	ppid = getpid();
again:
	signal(SIGINT, interrupt);
	child = fork();
	if (child < 0) {
		msg("Context save fork fails in parent %d\n", ppid);
		exit(X_ABORT);
	}
	if (child != 0) {
		signal(SIGINT, SIG_IGN);
		for (;;) {
			w = wait(&status);
			if (w == child)
				break;
msg("Parent %d waiting for %d has another child %d return\n", ppid, child, w);
		}
		if (status & 0xff)
msg("Child %d returns LOB status %o\n", child, status & 0xff);
		switch ((status >> 8) & 0xff) {

		case X_FINOK:
			exit(X_FINOK);

		case X_ABORT:
			exit(X_ABORT);

		case X_REWRITE:
			rmtclose();
D 3
			rmtreconnect();
			goto again;
E 3
I 3
D 5
			exit(X_ABORT);
E 5
I 5
#ifdef notdef
			do {
				if (!query("Retry conection to remote host?"))
					exit(X_ABORT);
				rmtgetconn();
			} while (rmtape < 0);
#endif
			goto again;
E 5
E 3

		default:
			msg("Bad return code from dump: %d\n", status);
			exit(X_ABORT);
		}
		/*NOTREACHED*/
	}
	for (;;) {
		if (rmtopen(tape, 2) >= 0)
			break;
		if (query("Tape open failed, try again?") == 0)
			dumpabort();
	}
	asize = 0;
	tapeno++, newtape++;
I 2
	trecno = 0;
E 2
	spcl.c_volume++;
	spcl.c_type = TS_TAPE;
	spclrec();
	if (tapeno > 1)
		msg("Tape %d begins with blocks from ino %d\n", tapeno, ino);
}

dumpabort()
{

	msg("The ENTIRE dump is aborted.\n");
	exit(X_ABORT);
}

Exit(code)
	int code;
{

	exit(code);
}
E 1
