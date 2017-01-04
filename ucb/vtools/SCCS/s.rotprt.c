h22662
s 00007/00001/00085
d D 5.1 85/05/15 11:32:33 dist 3 2
c Add copyright notice
e
s 00004/00001/00082
d D 4.2 83/07/16 23:47:36 sam 2 1
c add useful sccs id's
e
s 00083/00000/00000
d D 4.1 83/04/28 15:18:45 ralph 1 0
c date and time created 83/04/28 15:18:45 by ralph
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
 * Print a rotated font.
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
	struct dispatch d[256];
	struct stat stb;
	off_t tell();
	int i,size;

	argc--, argv++;
	if (argc > 0) {
		close(0);
		if (open(argv[0], 0) < 0)
			perror(argv[0]), exit(1);
	}
	if (read(0, &h, sizeof(h)) != sizeof(h))
		fprintf(stderr, "header read error\n"), exit(1);
	if (h.magic != 0436)
		fprintf(stderr, "bad magic number\n"), exit(1);
	if (read(0, d, sizeof(d)) != sizeof(d))
		fprintf(stderr, "dispatch read error\n"), exit(1);
	fstat(0, &stb);
	size = stb.st_size - tell(0);
	fprintf(stderr, "%d bytes of characters\n", size);
	chp = sbrk(size);
	read(0, chp, size);
	/* write(1, &h, sizeof (h)); */
	for (i = 0; i < 256; i++)
		rprt(i, &d[i], chp+d[i].addr);
}

rprt(i, dp, cp)
	int i;
	struct dispatch *dp;
	char *cp;
{
	int bpl, j;

	if (dp->nbytes == 0)
		return;
	if (i >= 0200)
		printf("M-"), i -= 0200;
	if (i < 040)
		printf("^%c", i|'@');
	else if (i == 0177)
		printf("^?");
	else
		printf("%c", i);
	printf("%d bytes, l %d r %d u %d d %d:\n",
	    dp->nbytes, dp->left, dp->right, dp->up, dp->down);
	bpl = (dp->up+dp->down+7)/8;
	for (i = 0; i < dp->right+dp->left; i++) {
		for (j = 0; j < bpl; j++)
			pbits(cp[j]);
		cp += bpl;
		printf("\n");
	}
	printf("========\n");
}

pbits(i)
	register int i;
{
	register int j;

	for (j = 8; j > 0; j--) {
		printf((i & 0x80) ? " *" : "  ");
		i <<= 1;
	}
}
E 1
