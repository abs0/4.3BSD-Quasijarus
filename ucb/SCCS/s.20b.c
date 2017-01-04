h07341
s 00006/00002/00058
d D 5.6 04/04/07 11:44:22 msokolov 6 5
c print error messages on read/write errors
e
s 00002/00000/00058
d D 5.5 88/06/29 17:58:11 bostic 5 4
c used a random block size if not given an argv[1].
e
s 00010/00005/00048
d D 5.4 88/06/27 18:30:03 bostic 4 3
c install approved copyright notice
e
s 00017/00007/00036
d D 5.3 88/02/09 08:53:18 bostic 3 2
c add arg to specify block size.
e
s 00019/00011/00024
d D 5.2 88/02/08 21:16:02 bostic 2 1
c check read/writes for failure
e
s 00035/00000/00000
d D 5.1 86/12/03 14:26:02 mckusick 1 0
c date and time created 86/12/03 14:26:02 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1986 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 4
E 2
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1986 Regents of the University of California.\n\
 All rights reserved.\n";
D 2
#endif not lint
E 2
I 2
#endif /* not lint */
E 2

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif not lint
E 2
I 2
#endif /* not lint */
E 2

I 2
D 3
#define BSIZE	(20 * 512)
E 2
main()
E 3
I 3
#include <stdio.h>

main(argc, argv)
	int argc;
	char **argv;
E 3
{
I 3
	register int bsize, cc, want;
E 3
	register char *base, *current;
D 3
	register int cc, want;
E 3
D 2
	int bsize = 20 * 512;
E 2
	char *alloca();

D 2
	base = alloca(bsize);
	for(cc = bsize; cc > 0;) {
E 2
I 2
D 3
	base = alloca(BSIZE);
	for (cc = BSIZE; cc > 0;) {
E 3
I 3
	if (argc > 1) {
		bsize = atoi(argv[1]);
		if (bsize <= 0) {
			fputs("20b: bad block size.\n", stderr);
			exit(-1);
		}
	}
I 5
	else
		bsize = 20 * 512;
E 5
	base = alloca(bsize);
	for (cc = bsize; cc > 0;) {
E 3
E 2
		current = base;
D 2
		for(want = bsize; want > 0 && cc > 0; want -= cc) {
			cc = read(0,current,want);
E 2
I 2
D 3
		for (want = BSIZE; want > 0 && cc > 0; want -= cc) {
E 3
I 3
		for (want = bsize; want > 0 && cc > 0; want -= cc) {
E 3
D 6
			if ((cc = read(0, current, want)) < 0)
E 6
I 6
			if ((cc = read(0, current, want)) < 0) {
				perror("20b: read");
E 6
				return(-1);
I 6
			}
E 6
E 2
			current += cc;
		}
D 2
		if((want = bsize - want) > 0)
		    write(1,base,want);
E 2
I 2
D 3
		want = BSIZE - want;
E 3
I 3
		want = bsize - want;
E 3
D 6
		if (want && write(1, base, want) != want)
E 6
I 6
		if (want && write(1, base, want) != want) {
			perror("20b: write");
E 6
			return(-1);
I 6
		}
E 6
E 2
	}
	return(0);
}
E 1
