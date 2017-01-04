h30159
s 00034/00034/00837
d D 7.7 03/04/13 15:19:09 msokolov 19 17
c 8-bit ex
e
s 00000/00176/00695
d D 7.6.1.1 88/08/08 18:31:08 mckusick 18 17
c delete decryption for the foreign sites (4.3BSD Tahoe)
e
s 00051/00011/00820
d D 7.6 87/03/09 12:47:00 conrad 17 15
c make ex/vi work on vms
e
s 00000/00172/00659
d D 7.5.1.1 86/08/12 15:51:59 mckusick 16 15
c delete decryption for the foreign sites
e
s 00010/00002/00821
d D 7.5 85/06/07 18:20:53 bloom 15 14
c fix sccsid and copyright for xstr
e
s 00009/00000/00814
d D 7.4 83/07/30 13:34:25 sam 14 12
c mark spot to put fsync for the paranoid
e
s 00001/00000/00814
d R 7.4 83/07/30 13:23:16 sam 13 12
c force system i/o when syncing file
e
s 00005/00009/00809
d D 7.3 81/09/03 11:44:58 mark 12 11
c updates for Unix/370 and ins/del line on vt100
e
s 00001/00001/00817
d D 7.2 81/07/26 20:04:21 mark 11 10
c fixes for 3b
e
s 00004/00004/00814
d D 7.1 81/07/08 22:31:19 mark 10 9
c release 3.7 - a few bug fixes and a few new features.
e
s 00003/00000/00815
d D 6.2 80/10/23 16:12:52 mark 9 8
c fixed various bugs prior to 3.6 release
e
s 00000/00000/00815
d D 6.1 80/10/19 01:21:27 mark 8 7
c preliminary release 3.6 10/18/80
e
s 00000/00000/00815
d D 5.1 80/08/20 16:11:32 mark 7 6
c Release 3.5, August 20, 1980
e
s 00012/00000/00803
d D 4.3 80/08/20 00:24:37 mark 6 5
c made CRYPT an #ifdef
e
s 00057/00001/00746
d D 4.2 80/08/01 20:41:16 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00176/00004/00571
d D 4.1 80/08/01 00:15:34 mark 4 3
c release 3.4, June 24, 1980
e
s 00009/00002/00566
d D 3.1 80/07/31 23:39:31 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00004/00004/00564
d D 2.1 80/07/31 23:19:27 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00568/00000/00000
d D 1.1 80/07/31 23:00:27 mark 1 0
c date and time created 80/07/31 23:00:27 by mark
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
D 10
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 10
I 10
D 15
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 15
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif not lint

E 15
E 10
E 5
#include "ex.h"
#include "ex_temp.h"
#include "ex_vis.h"
#include "ex_tty.h"

/*
 * Editor temporary file routines.
 * Very similar to those of ed, except uses 2 input buffers.
 */
#define	READ	0
#define	WRITE	1

I 17
#ifndef vms
#define	EPOSITION	7
#else
#define	EPOSITION	13
#endif

E 17
D 19
char	tfname[40];
char	rfname[40];
E 19
I 19
u_char	tfname[40];
u_char	rfname[40];
E 19
int	havetmp;
D 10
short	tfile = -1;
E 10
I 10
D 11
/* short	tfile = -1;	mjm: in ex_space.c */
E 11
I 11
short	tfile = -1;
E 11
E 10
short	rfile = -1;

fileinit()
{
D 19
	register char *p;
E 19
I 19
	register u_char *p;
E 19
	register int i, j;
	struct stat stbuf;

D 2
	if (tline == INCRMT * 3)
E 2
I 2
	if (tline == INCRMT * (HBLKS+2))
E 2
		return;
	cleanup(0);
D 17
	close(tfile);
E 17
I 17
	if (tfile >= 0)
		close(tfile);
E 17
D 2
	tline = INCRMT * 3;
	blocks[0] = 1;
	blocks[1] = 2;
E 2
I 2
	tline = INCRMT * (HBLKS+2);
	blocks[0] = HBLKS;
	blocks[1] = HBLKS+1;
E 2
	blocks[2] = -1;
	dirtcnt = 0;
	iblock = -1;
	iblock2 = -1;
	oblock = -1;
	CP(tfname, svalue(DIRECTORY));
D 17
	if (stat(tfname, &stbuf)) {
E 17
I 17
#ifndef vms
	if (stat(tfname, &stbuf))
#else
	goto vms_no_check_dir;
#endif
	{
E 17
dumbness:
		if (setexit() == 0)
			filioerr(tfname);
		else
			putNFL();
		cleanup(1);
D 17
		exit(1);
E 17
I 17
		ex_exit(1);
E 17
	}
I 17
#ifndef	vms
E 17
	if ((stbuf.st_mode & S_IFMT) != S_IFDIR) {
		errno = ENOTDIR;
		goto dumbness;
	}
I 17
#else
vms_no_check_dir:
#endif
E 17
	ichanged = 0;
	ichang2 = 0;
I 17
#ifndef	vms
E 17
	ignore(strcat(tfname, "/ExXXXXX"));
I 17
#else
	ignore(strcat(tfname, "ExXXXXX"));
#endif
E 17
	for (p = strend(tfname), i = 5, j = getpid(); i > 0; i--, j /= 10)
		*--p = j % 10 | '0';
I 17
#ifdef vms
	ignore(strcat(tfname, ".txt.1"));
	unlink(tfname);
#endif
E 17
	tfile = creat(tfname, 0600);
	if (tfile < 0)
		goto dumbness;
I 5
#ifdef VMUNIX
	{
		extern stilinc;		/* see below */
		stilinc = 0;
	}
#endif
E 5
	havetmp = 1;
D 17
	close(tfile);
E 17
I 17
	if (tfile >= 0)
		close(tfile);
E 17
	tfile = open(tfname, 2);
	if (tfile < 0)
		goto dumbness;
I 17
#ifdef UNIX_SBRK
E 17
D 19
/* 	brk((char *)fendcore); */
E 19
I 19
/* 	brk((u_char *)fendcore); */
E 19
I 17
#endif
E 17
}

cleanup(all)
	bool all;
{
	if (all) {
		putpad(TE);
		flush();
	}
D 17
	if (havetmp)
E 17
I 17
	if (havetmp) {
		if (tfile >= 0)
			close(tfile);
E 17
		unlink(tfname);
I 17
	}
E 17
	havetmp = 0;
	if (all && rfile >= 0) {
I 17
		if (rfile >= 0)
			close(rfile);
E 17
		unlink(rfname);
D 17
		close(rfile);
E 17
		rfile = -1;
	}
}

getline(tl)
	line tl;
{
D 19
	register char *bp, *lp;
E 19
I 19
	register u_char *bp, *lp;
E 19
	register int nl;

	lp = linebuf;
	bp = getblock(tl, READ);
	nl = nleft;
	tl &= ~OFFMSK;
	while (*lp++ = *bp++)
		if (--nl == 0) {
			bp = getblock(tl += INCRMT, READ);
			nl = nleft;
		}
}

putline()
{
D 19
	register char *bp, *lp;
E 19
I 19
	register u_char *bp, *lp;
E 19
	register int nl;
	line tl;

	dirtcnt++;
	lp = linebuf;
	change();
	tl = tline;
	bp = getblock(tl, WRITE);
	nl = nleft;
	tl &= ~OFFMSK;
	while (*bp = *lp++) {
		if (*bp++ == '\n') {
			*--bp = 0;
			linebp = lp;
			break;
		}
		if (--nl == 0) {
			bp = getblock(tl += INCRMT, WRITE);
			nl = nleft;
		}
	}
	tl = tline;
	tline += (((lp - linebuf) + BNDRY - 1) >> SHFT) & 077776;
	return (tl);
}

int	read();
int	write();

D 19
char *
E 19
I 19
u_char *
E 19
getblock(atl, iof)
	line atl;
	int iof;
{
	register int bno, off;
I 17
D 18
#ifdef CRYPT
E 17
I 4
D 19
        register char *p1, *p2;
E 19
I 19
        register u_char *p1, *p2;
E 19
        register int n;
I 17
#endif
E 18
E 17
E 4
	
	bno = (atl >> OFFBTS) & BLKMSK;
	off = (atl << SHFT) & LBTMSK;
	if (bno >= NMBLKS)
		error(" Tmp file too large");
	nleft = BUFSIZ - off;
	if (bno == iblock) {
		ichanged |= iof;
		hitin2 = 0;
		return (ibuff + off);
	}
	if (bno == iblock2) {
		ichang2 |= iof;
		hitin2 = 1;
		return (ibuff2 + off);
	}
	if (bno == oblock)
		return (obuff + off);
	if (iof == READ) {
		if (hitin2 == 0) {
D 4
			if (ichang2)
E 4
I 4
			if (ichang2) {
I 6
D 16
D 18
#ifdef CRYPT
E 6
				if(xtflag)
					crblock(tperm, ibuff2, CRSIZE, (long)0);
I 6
#endif
E 18
E 16
E 6
E 4
				blkio(iblock2, ibuff2, write);
I 4
			}
E 4
			ichang2 = 0;
			iblock2 = bno;
			blkio(bno, ibuff2, read);
I 6
D 16
D 18
#ifdef CRYPT
E 6
I 4
			if(xtflag)
				crblock(tperm, ibuff2, CRSIZE, (long)0);
I 6
#endif
E 18
E 16
E 6
E 4
			hitin2 = 1;
			return (ibuff2 + off);
		}
		hitin2 = 0;
D 4
		if (ichanged)
E 4
I 4
		if (ichanged) {
I 6
D 16
D 18
#ifdef CRYPT
E 6
			if(xtflag)
				crblock(tperm, ibuff, CRSIZE, (long)0);
I 6
#endif
E 18
E 16
E 6
E 4
			blkio(iblock, ibuff, write);
I 4
		}
E 4
		ichanged = 0;
		iblock = bno;
		blkio(bno, ibuff, read);
I 6
D 16
D 18
#ifdef CRYPT
E 6
I 4
		if(xtflag)
			crblock(tperm, ibuff, CRSIZE, (long)0);
I 6
#endif
E 18
E 16
E 6
E 4
		return (ibuff + off);
	}
D 4
	if (oblock >= 0)
		blkio(oblock, obuff, write);
E 4
I 4
	if (oblock >= 0) {
I 6
D 16
D 18
#ifdef CRYPT
E 6
		if(xtflag) {
			/*
			 * Encrypt block before writing, so some devious
			 * person can't look at temp file while editing.
			 */
			p1 = obuff;
			p2 = crbuf;
			n = CRSIZE;
			while(n--)
				*p2++ = *p1++;
			crblock(tperm, crbuf, CRSIZE, (long)0);
			blkio(oblock, crbuf, write);
		} else
I 6
#endif
E 18
E 16
E 6
			blkio(oblock, obuff, write);
	}
E 4
	oblock = bno;
	return (obuff + off);
}

I 5
#ifdef	VMUNIX
I 17
#ifdef	vms
#define	INCORB	32
#else
E 17
#define	INCORB	64
I 17
#endif
E 17
D 19
char	incorb[INCORB+1][BUFSIZ];
#define	pagrnd(a)	((char *)(((int)a)&~(BUFSIZ-1)))
E 19
I 19
u_char	incorb[INCORB+1][BUFSIZ];
#define	pagrnd(a)	((u_char *)(((int)a)&~(BUFSIZ-1)))
E 19
int	stilinc;	/* up to here not written yet */
#endif

E 5
blkio(b, buf, iofcn)
	short b;
D 19
	char *buf;
E 19
I 19
	u_char *buf;
E 19
	int (*iofcn)();
{

I 5
#ifdef VMUNIX
	if (b < INCORB) {
		if (iofcn == read) {
			bcopy(pagrnd(incorb[b+1]), buf, BUFSIZ);
			return;
		}
		bcopy(buf, pagrnd(incorb[b+1]), BUFSIZ);
		if (laste) {
			if (b >= stilinc)
				stilinc = b + 1;
			return;
		}
	} else if (stilinc)
		tflush();
#endif
E 5
	lseek(tfile, (long) (unsigned) b * BUFSIZ, 0);
	if ((*iofcn)(tfile, buf, BUFSIZ) != BUFSIZ)
		filioerr(tfname);
}

I 5
#ifdef VMUNIX
tlaste()
{

	if (stilinc)
		dirtcnt = 0;
}

tflush()
{
	int i = stilinc;
	
	stilinc = 0;
	lseek(tfile, (long) 0, 0);
	if (write(tfile, pagrnd(incorb[1]), i * BUFSIZ) != (i * BUFSIZ))
		filioerr(tfname);
}
#endif

E 5
/*
 * Synchronize the state of the temporary file in case
 * a crash occurs.
 */
synctmp()
{
	register int cnt;
	register line *a;
	register short *bp;

I 5
#ifdef VMUNIX
	if (stilinc)
		return;
#endif
E 5
	if (dol == zero)
		return;
	if (ichanged)
		blkio(iblock, ibuff, write);
	ichanged = 0;
	if (ichang2)
		blkio(iblock2, ibuff2, write);
	ichang2 = 0;
	if (oblock != -1)
		blkio(oblock, obuff, write);
	time(&H.Time);
	uid = getuid();
	*zero = (line) H.Time;
	for (a = zero, bp = blocks; a <= dol; a += BUFSIZ / sizeof *a, bp++) {
		if (*bp < 0) {
			tline = (tline + OFFMSK) &~ OFFMSK;
			*bp = ((tline >> OFFBTS) & BLKMSK);
I 4
			if (*bp > NMBLKS)
				error(" Tmp file too large");
E 4
			tline += INCRMT;
			oblock = *bp + 1;
			bp[1] = -1;
		}
		lseek(tfile, (long) (unsigned) *bp * BUFSIZ, 0);
		cnt = ((dol - a) + 2) * sizeof (line);
		if (cnt > BUFSIZ)
			cnt = BUFSIZ;
D 19
		if (write(tfile, (char *) a, cnt) != cnt) {
E 19
I 19
		if (write(tfile, (u_char *) a, cnt) != cnt) {
E 19
oops:
			*zero = 0;
			filioerr(tfname);
		}
		*zero = 0;
	}
	flines = lineDOL();
	lseek(tfile, 0l, 0);
D 19
	if (write(tfile, (char *) &H, sizeof H) != sizeof H)
E 19
I 19
	if (write(tfile, (u_char *) &H, sizeof H) != sizeof H)
E 19
		goto oops;
I 14
#ifdef notdef
	/*
	 * This will insure that exrecover gets as much
	 * back after a crash as is absolutely possible,
	 * but can result in pregnant pauses between commands
	 * when the TSYNC call is made, so...
	 */
I 17
#ifndef vms
E 17
	(void) fsync(tfile);
#endif
I 17
#endif
E 17
E 14
}

TSYNC()
{

D 10
	if (dirtcnt > 12) {
E 10
I 10
	if (dirtcnt > MAXDIRT) {	/* mjm: 12 --> MAXDIRT */
E 10
I 5
#ifdef VMUNIX
		if (stilinc)
			tflush();
#endif
E 5
		dirtcnt = 0;
		synctmp();
	}
}

/*
 * Named buffer routines.
 * These are implemented differently than the main buffer.
 * Each named buffer has a chain of blocks in the register file.
 * Each block contains roughly 508 chars of text,
 * and a previous and next block number.  We also have information
 * about which blocks came from deletes of multiple partial lines,
 * e.g. deleting a sentence or a LISP object.
 *
 * We maintain a free map for the temp file.  To free the blocks
 * in a register we must read the blocks to find how they are chained
 * together.
 *
 * BUG:		The default savind of deleted lines in numbered
 *		buffers may be rather inefficient; it hasn't been profiled.
 */
struct	strreg {
	short	rg_flags;
	short	rg_nleft;
	short	rg_first;
	short	rg_last;
} strregs[('z'-'a'+1) + ('9'-'0'+1)], *strp;

struct	rbuf {
	short	rb_prev;
	short	rb_next;
D 19
	char	rb_text[BUFSIZ - 2 * sizeof (short)];
E 19
I 19
	u_char	rb_text[BUFSIZ - 2 * sizeof (short)];
E 19
D 12
} *rbuf;
E 12
I 12
} *rbuf, KILLrbuf, putrbuf, YANKrbuf, regrbuf;
E 12
I 3
#ifdef VMUNIX
short	rused[256];
#else
E 3
short	rused[32];
I 3
#endif
E 3
short	rnleft;
short	rblock;
short	rnext;
D 19
char	*rbufcp;
E 19
I 19
u_char	*rbufcp;
E 19

regio(b, iofcn)
	short b;
	int (*iofcn)();
{

	if (rfile == -1) {
		CP(rfname, tfname);
D 17
		*(strend(rfname) - 7) = 'R';
E 17
I 17
		*(strend(rfname) - EPOSITION) = 'R';
E 17
		rfile = creat(rfname, 0600);
		if (rfile < 0)
oops:
			filioerr(rfname);
D 17
		close(rfile);
E 17
I 17
		else
			close(rfile);
E 17
		rfile = open(rfname, 2);
		if (rfile < 0)
			goto oops;
	}
	lseek(rfile, (long) b * BUFSIZ, 0);
	if ((*iofcn)(rfile, rbuf, BUFSIZ) != BUFSIZ)
		goto oops;
	rblock = b;
}

REGblk()
{
	register int i, j, m;

	for (i = 0; i < sizeof rused / sizeof rused[0]; i++) {
		m = (rused[i] ^ 0177777) & 0177777;
		if (i == 0)
			m &= ~1;
		if (m != 0) {
			j = 0;
			while ((m & 1) == 0)
				j++, m >>= 1;
			rused[i] |= (1 << j);
#ifdef RDEBUG
D 17
			printf("allocating block %d\n", i * 16 + j);
E 17
I 17
			ex_printf("allocating block %d\n", i * 16 + j);
E 17
#endif
			return (i * 16 + j);
		}
	}
	error("Out of register space (ugh)");
	/*NOTREACHED*/
}

struct	strreg *
mapreg(c)
	register int c;
{

	if (isupper(c))
		c = tolower(c);
	return (isdigit(c) ? &strregs[('z'-'a'+1)+(c-'0')] : &strregs[c-'a']);
}

int	shread();

KILLreg(c)
	register int c;
{
D 12
	struct rbuf arbuf;
E 12
	register struct strreg *sp;

D 12
	rbuf = &arbuf;
E 12
I 12
	rbuf = &KILLrbuf;
E 12
	sp = mapreg(c);
	rblock = sp->rg_first;
	sp->rg_first = sp->rg_last = 0;
	sp->rg_flags = sp->rg_nleft = 0;
	while (rblock != 0) {
#ifdef RDEBUG
D 17
		printf("freeing block %d\n", rblock);
E 17
I 17
		ex_printf("freeing block %d\n", rblock);
E 17
#endif
		rused[rblock / 16] &= ~(1 << (rblock % 16));
		regio(rblock, shread);
		rblock = rbuf->rb_next;
	}
}

/*VARARGS*/
shread()
{
	struct front { short a; short b; };

D 19
	if (read(rfile, (char *) rbuf, sizeof (struct front)) == sizeof (struct front))
E 19
I 19
	if (read(rfile, (u_char *) rbuf, sizeof (struct front)) == sizeof (struct front))
E 19
		return (sizeof (struct rbuf));
	return (0);
}

int	getREG();

putreg(c)
D 19
	char c;
E 19
I 19
	u_char c;
E 19
{
D 12
	struct rbuf arbuf;
E 12
	register line *odot = dot;
	register line *odol = dol;
	register int cnt;

	deletenone();
	appendnone();
D 12
	rbuf = &arbuf;
E 12
I 12
	rbuf = &putrbuf;
E 12
	rnleft = 0;
	rblock = 0;
	rnext = mapreg(c)->rg_first;
	if (rnext == 0) {
		if (inopen) {
			splitw++;
			vclean();
			vgoto(WECHO, 0);
		}
		vreg = -1;
		error("Nothing in register %c", c);
	}
	if (inopen && partreg(c)) {
I 3
		if (!FIXUNDO) {
			splitw++; vclean(); vgoto(WECHO, 0); vreg = -1;
			error("Can't put partial line inside macro");
		}
E 3
		squish();
		addr1 = addr2 = dol;
	}
D 3
	ignore(append(getREG, addr2));
E 3
I 3
	cnt = append(getREG, addr2);
E 3
	if (inopen && partreg(c)) {
		unddol = dol;
		dol = odol;
		dot = odot;
		pragged(0);
	}
D 3
	cnt = undap2 - undap1;
E 3
	killcnt(cnt);
	notecnt = cnt;
}

partreg(c)
D 19
	char c;
E 19
I 19
	u_char c;
E 19
{

	return (mapreg(c)->rg_flags);
}

notpart(c)
	register int c;
{

	if (c)
		mapreg(c)->rg_flags = 0;
}

getREG()
{
D 19
	register char *lp = linebuf;
E 19
I 19
	register u_char *lp = linebuf;
E 19
	register int c;

	for (;;) {
		if (rnleft == 0) {
			if (rnext == 0)
				return (EOF);
			regio(rnext, read);
			rnext = rbuf->rb_next;
			rbufcp = rbuf->rb_text;
			rnleft = sizeof rbuf->rb_text;
		}
		c = *rbufcp;
		if (c == 0)
			return (EOF);
		rbufcp++, --rnleft;
		if (c == '\n') {
			*lp++ = 0;
			return (0);
		}
		*lp++ = c;
	}
}

YANKreg(c)
	register int c;
{
D 12
	struct rbuf arbuf;
E 12
	register line *addr;
	register struct strreg *sp;
I 9
D 19
	char savelb[LBSIZE];
E 19
I 19
	u_char savelb[LBSIZE];
E 19
E 9

	if (isdigit(c))
		kshift();
	if (islower(c))
		KILLreg(c);
	strp = sp = mapreg(c);
	sp->rg_flags = inopen && cursor && wcursor;
D 12
	rbuf = &arbuf;
E 12
I 12
	rbuf = &YANKrbuf;
E 12
	if (sp->rg_last) {
		regio(sp->rg_last, read);
		rnleft = sp->rg_nleft;
		rbufcp = &rbuf->rb_text[sizeof rbuf->rb_text - rnleft];
	} else {
		rblock = 0;
		rnleft = 0;
	}
I 9
	CP(savelb,linebuf);
E 9
	for (addr = addr1; addr <= addr2; addr++) {
		getline(*addr);
		if (sp->rg_flags) {
			if (addr == addr2)
				*wcursor = 0;
			if (addr == addr1)
				strcpy(linebuf, cursor);
		}
		YANKline();
	}
	rbflush();
	killed();
I 9
	CP(linebuf,savelb);
E 9
}

kshift()
{
	register int i;

	KILLreg('9');
	for (i = '8'; i >= '0'; i--)
		copy(mapreg(i+1), mapreg(i), sizeof (struct strreg));
}

YANKline()
{
D 19
	register char *lp = linebuf;
E 19
I 19
	register u_char *lp = linebuf;
E 19
	register struct rbuf *rp = rbuf;
	register int c;

	do {
		c = *lp++;
		if (c == 0)
			c = '\n';
		if (rnleft == 0) {
			rp->rb_next = REGblk();
			rbflush();
			rblock = rp->rb_next;
			rp->rb_next = 0;
			rp->rb_prev = rblock;
			rnleft = sizeof rp->rb_text;
			rbufcp = rp->rb_text;
		}
		*rbufcp++ = c;
		--rnleft;
	} while (c != '\n');
	if (rnleft)
		*rbufcp = 0;
}

rbflush()
{
	register struct strreg *sp = strp;

	if (rblock == 0)
		return;
	regio(rblock, write);
	if (sp->rg_first == 0)
		sp->rg_first = rblock;
	sp->rg_last = rblock;
	sp->rg_nleft = rnleft;
}

/* Register c to char buffer buf of size buflen */
regbuf(c, buf, buflen)
D 19
char c;
char *buf;
E 19
I 19
u_char c;
u_char *buf;
E 19
int buflen;
{
D 12
	struct rbuf arbuf;
E 12
D 19
	register char *p, *lp;
E 19
I 19
	register u_char *p, *lp;
E 19

D 12
	rbuf = &arbuf;
E 12
I 12
	rbuf = &regrbuf;
E 12
	rnleft = 0;
	rblock = 0;
	rnext = mapreg(c)->rg_first;
	if (rnext==0) {
		*buf = 0;
		error("Nothing in register %c",c);
	}
	p = buf;
	while (getREG()==0) {
		for (lp=linebuf; *lp;) {
			if (p >= &buf[buflen])
				error("Register too long@to fit in memory");
			*p++ = *lp++;
		}
		*p++ = '\n';
	}
	if (partreg(c)) p--;
	*p = '\0';
	getDOT();
I 4
}

/*
 * Encryption routines.  These are essentially unmodified from ed.
 */

I 6
D 16
D 18
#ifdef CRYPT
E 6
/*
 * crblock: encrypt/decrypt a block of text.
 * buf is the buffer through which the text is both input and
 * output. nchar is the size of the buffer. permp is a work
 * buffer, and startn is the beginning of a sequence.
 */
crblock(permp, buf, nchar, startn)
D 19
char *permp;
char *buf;
E 19
I 19
u_char *permp;
u_char *buf;
E 19
int nchar;
long startn;
{
D 19
	register char *p1;
E 19
I 19
	register u_char *p1;
E 19
	int n1;
	int n2;
D 19
	register char *t1, *t2, *t3;
E 19
I 19
	register u_char *t1, *t2, *t3;
E 19

	t1 = permp;
	t2 = &permp[256];
	t3 = &permp[512];

	n1 = startn&0377;
	n2 = (startn>>8)&0377;
	p1 = buf;
	while(nchar--) {
		*p1 = t2[(t3[(t1[(*p1+n1)&0377]+n2)&0377]-n2)&0377]-n1;
		n1++;
		if(n1==256){
			n1 = 0;
			n2++;
			if(n2==256) n2 = 0;
		}
		p1++;
	}
}

/*
 * makekey: initialize buffers based on user key a.
 */
makekey(a, b)
D 19
char *a, *b;
E 19
I 19
u_char *a, *b;
E 19
{
       register int i;
	long t;
D 19
	char temp[KSIZE + 1];
E 19
I 19
	u_char temp[KSIZE + 1];
E 19

	for(i = 0; i < KSIZE; i++)
		temp[i] = *a++;
	time(&t);
	t += getpid();
	for(i = 0; i < 4; i++)
		temp[i] ^= (t>>(8*i))&0377;
	crinit(temp, b);
}

/*
 * crinit: besides initializing the encryption machine, this routine
 * returns 0 if the key is null, and 1 if it is non-null.
 */
crinit(keyp, permp)
D 19
char    *keyp, *permp;
E 19
I 19
u_char    *keyp, *permp;
E 19
{
D 19
       register char *t1, *t2, *t3;
E 19
I 19
       register u_char *t1, *t2, *t3;
E 19
	register i;
	int ic, k, temp;
	unsigned random;
D 19
	char buf[13];
E 19
I 19
	u_char buf[13];
E 19
	long seed;

	t1 = permp;
	t2 = &permp[256];
	t3 = &permp[512];
	if(*keyp == 0)
		return(0);
	strncpy(buf, keyp, 8);
	while (*keyp)
		*keyp++ = '\0';

	buf[8] = buf[0];
	buf[9] = buf[1];
	domakekey(buf);

	seed = 123;
	for (i=0; i<13; i++)
		seed = seed*buf[i] + i;
	for(i=0;i<256;i++){
		t1[i] = i;
		t3[i] = 0;
	}
	for(i=0; i<256; i++) {
		seed = 5*seed + buf[i%13];
		random = seed % 65521;
		k = 256-1 - i;
		ic = (random&0377) % (k+1);
		random >>= 8;
		temp = t1[k];
		t1[k] = t1[ic];
		t1[ic] = temp;
		if(t3[k]!=0) continue;
		ic = (random&0377) % k;
		while(t3[ic]!=0) ic = (ic+1) % k;
		t3[k] = ic;
		t3[ic] = k;
	}
	for(i=0; i<256; i++)
		t2[t1[i]&0377] = i;
	return(1);
}

/*
 * domakekey: the following is the major nonportable part of the encryption
 * mechanism. A 10 character key is supplied in buffer.
 * This string is fed to makekey (an external program) which
 * responds with a 13 character result. This result is placed
 * in buffer.
 */
domakekey(buffer)
D 19
char *buffer;
E 19
I 19
u_char *buffer;
E 19
{
       int pf[2];

	if (pipe(pf)<0)
		pf[0] = pf[1] = -1;
	if (fork()==0) {
		close(0);
		close(1);
		dup(pf[0]);
		dup(pf[1]);
		execl("/usr/lib/makekey", "-", 0);
		execl("/lib/makekey", "-", 0);
D 17
		exit(1);
E 17
I 17
		ex_exit(1);
E 17
	}
	write(pf[1], buffer, 10);
	if (wait((int *)NULL)==-1 || read(pf[0], buffer, 13)!=13)
		error("crypt: cannot generate key");
	close(pf[0]);
	close(pf[1]);
	/* end of nonportable part */
E 4
}
I 6
#endif
E 18
E 16
E 6
E 1
