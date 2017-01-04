h06023
s 00007/00001/00108
d D 5.1 85/05/15 11:32:29 dist 3 2
c Add copyright notice
e
s 00004/00001/00105
d D 4.2 83/07/16 23:47:32 sam 2 1
c add useful sccs id's
e
s 00106/00000/00000
d D 4.1 83/04/28 15:18:18 ralph 1 0
c date and time created 83/04/28 15:18:18 by ralph
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
#endif not lint
E 3

E 2
/*
 * Rotate a Varian/Versatec font.
 */

#include <stdio.h>
#include <vfont.h>
#include <sys/types.h>
#include <sys/stat.h>

char	*chp;
char	*sbrk();

main(argc,argv)
char **argv;
{
	struct header h;
	struct dispatch d[256], nd;
	struct stat stb;
	off_t tell();
	int i,size;
	int beg;
	char scr[2048];

	argc--, argv++;
	if (argc > 0) {
		close(0);
		if (open(argv[0], 0) < 0)
			perror(argv[0]), exit(1);
	}
	if (read(0, &h, sizeof(h)) != sizeof(h)) {
		fprintf(stderr, "header read error\n");
		exit(1);
	}
	if (h.magic != 0436) {
		fprintf(stderr, "bad magic number\n");
		exit(1);
	}
	if (read(0, d, sizeof(d)) != sizeof(d)) {
		fprintf(stderr, "dispatch read error\n");
		exit(1);
	}
	fstat(0, &stb);
	size = stb.st_size - tell(0);
	fprintf(stderr, "%d bytes of characters\n", size);
	chp = sbrk(size + 1024);
	read(0, chp, size);
	write(1, &h, sizeof (h));
	write(1, d, sizeof (d));
	beg = tell(1);
	for (i = 0; i < 256; i++)
		if (d[i].nbytes) {
			if (d[i].addr + d[i].nbytes > size) {
				fprintf(stderr, "char %d out of range\n", i);
				continue;
			}
			cvt(&d[i], chp+d[i].addr, &nd, scr);
			d[i] = nd;
			d[i].addr = tell(1) - beg;
			write(1, scr, d[i].nbytes);
		}
	fprintf(stderr, "done, new size %d\n", tell(1) - beg);
	h.size = tell(1) - beg;
	lseek(1, 0, 0);
	write(1, &h, sizeof (h));
	write(1, d, sizeof (d));
}

cvt(odp, ocp, dp, cp)
	struct dispatch *odp, *dp;
	register char *ocp, *cp;
{
	int max;
	int bpl;
	int row,byte,bit;
	register char *ep;
	register int bitoff;
	register int bits;
	int extra;

	max = (odp->up+odp->down+7)/8;
	extra = max*8 - (odp->down+odp->up);
	dp->down = odp->down;
	dp->up = odp->up;
	dp->left = odp->left;
	dp->right = odp->right;
	dp->nbytes = max*(dp->right+dp->left);
	ep = cp;
	for (byte = 0; byte < dp->nbytes; byte++)
		*ep++ = 0;
	bpl = (dp->right+dp->left+7)/8;
	for (row = 0; row < odp->up+odp->down; row++) {
		for (byte = 0; byte < bpl; byte++) {
			bits = *ocp++;
			for (bit = 0; bit < 8; bit++) {
				if (bits & 0x80) {
					ep = cp + max*(byte*8+bit);
					bitoff = max*8 - row - 1 - extra;
					ep += (bitoff/8);
					*ep |= 0x80 >> (bitoff%8);
				}
				bits <<= 1;
			}
		}
	}
}
E 1
