h25324
s 00005/00002/00130
d D 5.1 85/04/30 13:56:56 dist 6 5
c Add copyright
e
s 00006/00005/00126
d D 4.5 84/02/17 15:38:23 ralph 5 4
c use optimal block size.
e
s 00012/00005/00119
d D 4.4 82/02/14 16:32:03 rrh 4 3
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00001/00075/00123
d D 4.3 80/08/16 17:48:42 henry 3 2
c no fread/fwrite in assembler, so don't have local fast version
e
s 00000/00001/00198
d D 4.2 80/08/15 18:02:57 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00199/00000/00000
d D 4.1 80/08/13 18:55:12 bill 1 0
c date and time created 80/08/13 18:55:12 by bill
e
u
U
t
T
I 1
D 4
/* Coypright (c) 1980 Regents of the University of California */
static	char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
/*
D 6
 *	Copyright (c) 1982 Regents of the University of California
E 6
I 6
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
 */
I 6

E 6
#ifndef lint
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
#endif not lint

E 4
#include <stdio.h>
D 2
#include <sys/types.h>
E 2
#include "as.h"
/*
 *	Block I/O routines for logical I/O concurrently in
 *	more than one place in the same file.
 */
int	biofd;			/* file descriptor for block I/O file */
I 5
int	biobufsize;		/* optimal block size for I/O */
E 5
off_t	boffset;		/* physical position in logical file */
BFILE	*biobufs;		/* the block I/O buffers */

#define	error(severity, message) \
	{yyerror(message); if (severity) delexit();}

Flushfield(n)
	register int n;
{
	while (n>0) {
		outb(bitfield);
		bitfield >>= 8;
		n -= 8;
	}
	bitoff=0;
	bitfield=0;
}

D 3
#ifdef ASFWRITE
E 3
/*
D 3
 *	This is our version of fwrite...
 *	Hacked out fast version of fwrite that
 *	doesn't iterate over each and every character;
 *	We poke directly into the buffer area, and move things
 *	with a movc3.
E 3
I 3
 *	Block I/O Routines
E 3
 */
D 3
fwrite(p, n, m, f)
	register char *p;
	int n, m;
	register FILE *f;
{
	register int cnt = n * m;
	register int put;
	register char *to;

top:
	if (cnt == 0)
		return;
	if (f->_cnt) {
		put = f->_cnt;
		if (put > cnt)
			put = cnt;
		f->_cnt -= put;
		to = f->_ptr;
		asm("movc3 r8,(r11),(r7)");
		f->_ptr += put;
		p += put;
		cnt -= put;
		goto top;
	}
	if (cnt >= BUFSIZ) {
		fflush(f);
		put = cnt - cnt % BUFSIZ;
		if (write(f->_file, p, put) != put)
			error(1, "Output write error in fwrite");
		p += put;
		cnt -= put;
		goto top;
	}
	_flsbuf(*p++, f);
	--cnt;
	goto top;
}

/*
 *	This has been stolen from the usual place...
 *	It is put here so that the loader doesn't complain
 *	about multiple definitions in the archived object module.
 *
 *	archived in: /lib/libc.a
 *	object module from: /usr/src/libc/stdio/rdwr.c
 */
fread(ptr, size, count, iop)
	unsigned size, count;
	register char *ptr;
	register FILE *iop;
{
	register c;
	unsigned ndone, s;

	ndone = 0;
	if (size)
	for (; ndone<count; ndone++) {
		s = size;
		do {
			if ((c = getc(iop)) >= 0)
				*ptr++ = c;
			else
				return(ndone);
		} while (--s);
	}
	return(ndone);
}
#endif ASFWRITE

E 3
bopen(bp, off)
	struct biobuf *bp;
	off_t	off;
{

D 5
	bp->b_ptr = bp->b_buf;
	bp->b_nleft = BUFSIZ - off % BUFSIZ;
E 5
I 5
	bp->b_ptr = bp->b_buf = Calloc(1, biobufsize);
	bp->b_nleft = biobufsize - (off % biobufsize);
E 5
	bp->b_off = off;
	bp->b_link = biobufs;
	biobufs = bp;
}

int	bwrerror;

bwrite(p, cnt, bp)
	register char *p;
	register int cnt;
	register struct biobuf *bp;
{
	register int put;
	register char *to;

top:
	if (cnt == 0)
		return;
	if (bp->b_nleft) {
		put = bp->b_nleft;
		if (put > cnt)
			put = cnt;
		bp->b_nleft -= put;
		to = bp->b_ptr;
I 4
#ifdef lint
		*to = *to;
#endif lint
E 4
		asm("movc3 r8,(r11),(r7)");
		bp->b_ptr += put;
		p += put;
		cnt -= put;
		goto top;
	}
D 5
	if (cnt >= BUFSIZ) {
E 5
I 5
	if (cnt >= biobufsize) {
E 5
		if (bp->b_ptr != bp->b_buf)
			bflush1(bp);
D 5
		put = cnt - cnt % BUFSIZ;
E 5
I 5
		put = cnt - cnt % biobufsize;
E 5
		if (boffset != bp->b_off)
D 4
			lseek(biofd, bp->b_off, 0);
E 4
I 4
			(void)lseek(biofd, (long)bp->b_off, 0);
E 4
		if (write(biofd, p, put) != put) {
			bwrerror = 1;
			error(1, "Output write error");
		}
		bp->b_off += put;
		boffset = bp->b_off;
		p += put;
		cnt -= put;
		goto top;
	}
	bflush1(bp);
	goto top;
}

bflush()
{
	register struct biobuf *bp;

	if (bwrerror)
		return;
	for (bp = biobufs; bp; bp = bp->b_link)
		bflush1(bp);
}

bflush1(bp)
	register struct biobuf *bp;
{
	register int cnt = bp->b_ptr - bp->b_buf;

	if (cnt == 0)
		return;
	if (boffset != bp->b_off)
D 4
		lseek(biofd, bp->b_off, 0);
E 4
I 4
		(void)lseek(biofd, (long)bp->b_off, 0);
E 4
	if (write(biofd, bp->b_buf, cnt) != cnt) {
		bwrerror = 1;
		error(1, "Output write error");
	}
	bp->b_off += cnt;
	boffset = bp->b_off;
	bp->b_ptr = bp->b_buf;
D 5
	bp->b_nleft = BUFSIZ;
E 5
I 5
	bp->b_nleft = biobufsize;
E 5
}

bflushc(bp, c)
	register struct biobuf *bp;
	char	c;
{
D 4

E 4
	bflush1(bp);
	bputc(c, bp);
}
E 1
