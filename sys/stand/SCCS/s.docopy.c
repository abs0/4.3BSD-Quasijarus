h47264
s 00011/00005/00047
d D 7.2 88/06/29 18:19:13 bostic 2 1
c install approved copyright notice
e
s 00052/00000/00000
d D 7.1 88/03/03 21:03:40 bostic 1 0
c break out main copy loop
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 2
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 2
I 2
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
E 2
 *
 *	%W% (Berkeley) %G%
 */
I 2

E 2
#define	SIZE	10240

docopy(from, to, nrecs)
	register int from, to, nrecs;
{
	register int record, rcc, wcc;
	char buf[SIZE];

	for (record = 0;;) {
		if (!(rcc = read(from, buffer, SIZE)))
			break;
		if (rcc < 0) {
			printf("Record %d: read error, errno=%d\n",
			    record, errno);
			break;
		}
		if (rcc < SIZE)
			printf("Record %d: read short; expected %d, got %d\n",
			    record, SIZE, rcc);
#ifdef vax
		/* For bug in ht driver. */
		if (rcc > SIZE)
			rcc = SIZE;
#endif
		if ((wcc = write(to, buffer, rcc)) < 0) {
			printf("Record %d: write error: errno=%d\n",
			    record, errno);
			break;
		}
		if (wcc < rcc) {
			printf("Record %d: write short; expected %d, got %d\n",
			    record, rcc, wcc);
			break;
		}
		if (nrecs > 0 && ++record == nrecs)
			break;
	}
	printf("copy completed: %d records copied\n", record);
}
E 1
