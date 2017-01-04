h02778
s 00002/00011/00054
d D 5.2 87/04/07 15:53:31 mckusick 3 2
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00057
d D 5.1 85/06/06 08:18:14 dist 2 1
c Add copyright
e
s 00060/00000/00000
d D 1.1 82/01/18 19:20:15 linton 1 0
c date and time created 82/01/18 19:20:15 by linton
e
u
U
t
T
I 1
D 2
/* Copyright (c) 1982 Regents of the University of California */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 2

D 2
static char sccsid[] = "%Z%%M% %I% %G%";

E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2
/*
 * print contents of data addresses in octal
 *
 * There are two entries:  one is given a range of addresses,
 * the other is given a count and a starting address.
 */

#include "defs.h"
#include "machine.h"
#include "process.h"
#include "object.h"
I 3
#include "process/process.rep"
#include "process/pxinfo.h"
E 3

#define WORDSPERLINE 4

/*
 * print words from lowaddr to highaddr
 */

printdata(lowaddr, highaddr)
ADDRESS lowaddr;
ADDRESS highaddr;
{
	register int count;
	register ADDRESS addr;
	int val;

	if (lowaddr > highaddr) {
		error("first address larger than second");
	}
	count = 0;
	for (addr = lowaddr; addr <= highaddr; addr += sizeof(int)) {
		if (count == 0) {
			printf("%8x: ", addr);
		}
		dread(&val, addr, sizeof(val));
		printf("  %8x", val);
		if (++count >= WORDSPERLINE) {
			putchar('\n');
			count = 0;
		}
	}
	if (count != 0) {
		putchar('\n');
	}
D 3
}

/*
 * print count words starting at address
 */

printndata(count, addr)
int count;
ADDRESS addr;
{
	printdata(addr, addr + (count - 1)*sizeof(int));
E 3
}
E 1
