h25938
s 00001/00001/00054
d D 7.6 99/01/09 18:19:46 msokolov 15 14
x 14
c Excluded delta 7.5 (record size auto-detection stuff).
c It causes MUCH more trouble than benefit.
e
s 00024/00025/00030
d D 7.5 88/05/24 13:32:49 bostic 14 11
c changes/cleanups; work for both tahoe and vax
e
s 00005/00038/00017
d R 7.5 88/03/03 21:00:31 bostic 13 11
c break out main copy loop
e
s 00004/00037/00018
d R 7.5 88/03/03 20:55:58 bostic 12 11
c break out main copy loop
e
s 00005/00022/00050
d D 7.4 88/02/23 16:06:55 bostic 11 10
c replace getdev with machine independent getfile
e
s 00001/00001/00071
d D 7.3 88/02/04 12:14:51 bostic 10 9
c put in SCCS header info
e
s 00009/00008/00063
d D 7.2 88/02/04 12:12:00 bostic 9 8
c minor cleanup, fbuf, tbuf not required
e
s 00001/00001/00070
d D 7.1 86/06/05 01:41:16 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00064
d D 6.2 85/06/08 13:07:52 mckusick 7 6
c Add copyright
e
s 00000/00000/00065
d D 6.1 83/07/29 07:46:46 sam 6 5
c 4.2 distribution
e
s 00005/00000/00060
d D 4.5 83/02/24 23:01:57 sam 5 4
c kludge for ht driver; returns incorrect transfer count
e
s 00002/00002/00058
d D 4.4 83/02/20 19:21:14 sam 4 3
c ignore bogus (large) return values from read
e
s 00007/00004/00053
d D 4.3 83/02/18 01:00:07 sam 3 2
c messed up parameters
e
s 00024/00006/00033
d D 4.2 83/02/16 21:48:55 sam 2 1
c more resilient to errors?
e
s 00039/00000/00000
d D 4.1 83/02/13 12:00:44 sam 1 0
c date and time created 83/02/13 12:00:44 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
D 14
D 15
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 15
E 14
I 14
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 14
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 9
 *	%W% (Berkeley) %G%
E 9
I 9
D 10
 *	@(#)copy.c	7.1 (Berkeley) 6/5/86
E 10
I 10
D 11
 * %W% (Berkeley) %G%
E 11
I 11
 *	%W% (Berkeley) %G%
E 11
E 10
E 9
 */
E 7

I 14
#define	BSIZE	10240

E 14
/*
D 14
 * Copy from to in 10K units.
 * Intended for use in system
 * installation.
E 14
I 14
 * Copy from from to to.  Intended for use in system installation.
E 14
 */
main()
{
D 11
	int from, to;
D 9
	char fbuf[50], tbuf[50];
E 9
	char buffer[10240];
D 2
	register int i;
E 2
I 2
	register int record;
E 11
	extern int errno;
I 11
D 14
	register int from, to, record;
	char buffer[10240];
E 14
I 14
	register int from, to, record, rcc, wcc;
	char buf[BSIZE];
E 14
E 11
E 2

D 9
	from = getdev("From", fbuf, 0);
	to = getdev("To", tbuf, 1);
E 9
I 9
D 11
	from = getdev("From", 0);
	to = getdev("To", 1);
E 11
I 11
	from = getfile("From", 0);
	to = getfile("To", 1);
E 11
E 9
D 2
	for (;;) {
		i = read(from, buffer, sizeof (buffer));
		if (i != sizeof (buffer))
E 2
I 2
D 14
	for (record = 0; ; record++) {
D 9
		int rcc, wcc;
E 9
I 9
		register int rcc, wcc;
E 9

		rcc = read(from, buffer, sizeof (buffer));
		if (rcc == 0)
E 14
I 14
	for (record = 0;; ++record) {
		if (!(rcc = read(from, buf, BSIZE)))
E 14
E 2
			break;
D 2
		(void) write(to, buffer, i);
E 2
I 2
		if (rcc < 0) {
D 3
			printf("Read error, errno=%d\n", errno);
E 3
I 3
			printf("Record %d: read error, errno=%d\n",
D 14
				record, errno);
E 14
I 14
			    record, errno);
E 14
E 3
			break;
		}
D 4
		if (rcc != sizeof (buffer))
E 4
I 4
D 14
		if (rcc < sizeof (buffer))
E 14
I 14
		if (!record && rcc != BSIZE) {
			rcc = BSIZE;
			printf("Block size set from input; %d bytes\n", BSIZE);
		}
		if (rcc < BSIZE)
E 14
E 4
			printf("Record %d: read short; expected %d, got %d\n",
D 3
				sizeof (buffer), rcc);
E 3
I 3
D 14
				record, sizeof (buffer), rcc);
I 5
		/*
		 * For bug in ht driver.
		 */
		if (rcc > sizeof (buffer))
			rcc = sizeof (buffer);
E 5
E 3
		wcc = write(to, buffer, rcc);
		if (wcc < 0) {
E 14
I 14
			    record, BSIZE, rcc);
#ifdef vax
		/* For bug in ht driver. */
		if (rcc > BSIZE)
			rcc = BSIZE;
#endif
		if ((wcc = write(to, buf, rcc)) < 0) {
E 14
D 3
			printf("Write error: errno=%d\n", errno);
E 3
I 3
			printf("Record %d: write error: errno=%d\n",
D 14
				record, errno);
E 14
I 14
			    record, errno);
E 14
E 3
			break;
		}
D 4
		if (wcc != rcc) {
E 4
I 4
		if (wcc < rcc) {
E 4
D 3
			printf("Write short; expected %d, got %d\n", rcc, wcc);
E 3
I 3
			printf("Record %d: write short; expected %d, got %d\n",
D 14
				record, rcc, wcc);
E 14
I 14
			    record, rcc, wcc);
E 14
E 3
			break;
		}
E 2
	}
D 2
	printf("Copy completed\n");
E 2
I 2
D 14
	printf("Copy completed: %d records copied\n", record);
E 2
	/* can't call exit here */
E 14
I 14
	printf("copy completed: %d records copied\n", record);
E 14
D 11
}

D 9
getdev(prompt, buf, mode)
	char *prompt, *buf;
E 9
I 9
static
getdev(prompt, mode)
	char *prompt;
E 9
	int mode;
{
D 9
	register int i;
E 9
I 9
	int i;
	char buf[100];
E 9

	do {
		printf("%s: ", prompt);
		gets(buf);
		i = open(buf, mode);
	} while (i <= 0);
	return (i);
E 11
}
E 1
