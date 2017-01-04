h14135
s 00005/00003/00103
d D 2.3 87/02/23 17:39:46 mckusick 6 5
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00004/00000/00102
d D 2.2 82/04/11 17:36:00 mckusick 5 4
c minor changes to use "simfs"
e
s 00007/00002/00095
d D 2.1 82/04/08 15:39:43 mckusick 4 3
c merge into the new kernel
e
s 00003/00003/00094
d D 1.3 82/01/12 22:17:35 mckusic 3 2
c change all macros taking "fs" to have it as their first argument
e
s 00036/00023/00061
d D 1.2 82/01/06 23:31:57 mckusic 2 1
c convert to new file system format
e
s 00084/00000/00000
d D 1.1 82/01/06 21:38:43 mckusick 1 0
c date and time created 82/01/06 21:38:43 by mckusick
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1981 Regents of the University of California */

E 4
static char sccsid[] = "%Z%%M% %I% %G%";

D 2
static char *sccsid = "@(#)clri.c	4.1 (Berkeley) 10/1/80";
E 2
I 2
/* static char *sccsid = "@(#)clri.c	4.1 (Berkeley) 10/1/80"; */
I 4

E 4
E 2
/*
 * clri filsys inumber ...
 */

I 4
#ifndef SIMFS
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#else
E 4
D 2
#include <sys/param.h>
#include <sys/ino.h>
E 2
I 2
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
I 4
#endif
E 4
E 2

#define ISIZE	(sizeof(struct dinode))
D 2
#define	NI	(BSIZE/ISIZE)
struct	ino
{
E 2
I 2
#define	NI	(MAXBSIZE/ISIZE)
struct	ino {
E 2
	char	junk[ISIZE];
};
struct	ino	buf[NI];
I 2

union {
	char		dummy[SBSIZE];
	struct fs	sblk;
} sb_un;
#define sblock sb_un.sblk

E 2
int	status;
I 6
long	dev_bsize = 1;
E 6

main(argc, argv)
D 2
char *argv[];
E 2
I 2
	int argc;
	char *argv[];
E 2
{
	register i, f;
	unsigned n;
	int j, k;
	long off;

D 2
	if(argc < 3) {
E 2
I 2
	if (argc < 3) {
E 2
		printf("usage: clri filsys inumber ...\n");
		exit(4);
	}
	f = open(argv[1], 2);
D 2
	if(f < 0) {
E 2
I 2
	if (f < 0) {
E 2
		printf("cannot open %s\n", argv[1]);
		exit(4);
	}
D 2
	for(i=2; i<argc; i++) {
		if(!isnumber(argv[i])) {
E 2
I 2
D 6
	lseek(f, SBLOCK * DEV_BSIZE, 0);
E 6
I 6
	lseek(f, SBOFF, 0);
E 6
	if (read(f, &sblock, SBSIZE) != SBSIZE) {
		printf("cannot read %s\n", argv[1]);
		exit(4);
	}
I 5
	if (sblock.fs_magic != FS_MAGIC) {
		printf("bad super block magic number\n");
		exit(4);
	}
I 6
	dev_bsize = sblock.fs_fsize / fsbtodb(&sblock, 1);
E 6
E 5
	for (i = 2; i < argc; i++) {
		if (!isnumber(argv[i])) {
E 2
			printf("%s: is not a number\n", argv[i]);
			status = 1;
			continue;
		}
		n = atoi(argv[i]);
D 2
		if(n == 0) {
E 2
I 2
		if (n == 0) {
E 2
			printf("%s: is zero\n", argv[i]);
			status = 1;
			continue;
		}
D 2
		off = itod(n) * BSIZE;
E 2
I 2
D 3
		off = fsbtodb(&sblock, itod(n, &sblock)) * DEV_BSIZE;
E 3
I 3
D 6
		off = fsbtodb(&sblock, itod(&sblock, n)) * DEV_BSIZE;
E 6
I 6
		off = fsbtodb(&sblock, itod(&sblock, n)) * dev_bsize;
E 6
E 3
E 2
		lseek(f, off, 0);
D 2
		if(read(f, (char *)buf, BSIZE) != BSIZE) {
E 2
I 2
		if (read(f, (char *)buf, sblock.fs_bsize) != sblock.fs_bsize) {
E 2
			printf("%s: read error\n", argv[i]);
			status = 1;
		}
	}
D 2
	if(status)
E 2
I 2
	if (status)
E 2
		exit(status);
D 2
	for(i=2; i<argc; i++) {
E 2
I 2
	for (i = 2; i < argc; i++) {
E 2
		n = atoi(argv[i]);
		printf("clearing %u\n", n);
D 2
		off = itod(n) * BSIZE;
E 2
I 2
D 3
		off = fsbtodb(&sblock, itod(n, &sblock)) * DEV_BSIZE;
E 3
I 3
D 6
		off = fsbtodb(&sblock, itod(&sblock, n)) * DEV_BSIZE;
E 6
I 6
		off = fsbtodb(&sblock, itod(&sblock, n)) * dev_bsize;
E 6
E 3
E 2
		lseek(f, off, 0);
D 2
		read(f, (char *)buf, BSIZE);
		j = itoo(n);
		for(k=0; k<ISIZE; k++)
E 2
I 2
		read(f, (char *)buf, sblock.fs_bsize);
D 3
		j = itoo(n, &sblock);
E 3
I 3
		j = itoo(&sblock, n);
E 3
		for (k = 0; k < ISIZE; k++)
E 2
			buf[j].junk[k] = 0;
		lseek(f, off, 0);
D 2
		write(f, (char *)buf, BSIZE);
E 2
I 2
		write(f, (char *)buf, sblock.fs_bsize);
E 2
	}
	exit(status);
}

isnumber(s)
D 2
char *s;
E 2
I 2
	char *s;
E 2
{
	register c;

	while(c = *s++)
D 2
		if(c < '0' || c > '9')
E 2
I 2
		if (c < '0' || c > '9')
E 2
			return(0);
	return(1);
}
E 1
