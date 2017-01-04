h31776
s 00010/00005/00057
d D 1.4 88/06/18 14:08:07 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00053
d D 1.3 87/12/23 14:30:02 bostic 3 2
c append Berkeley header; NASA wants a copy
e
s 00001/00002/00055
d D 1.2 85/09/18 10:32:01 bloom 2 1
c don't need all of the includes
e
s 00057/00000/00000
d D 1.1 85/06/22 22:05:35 gusella 1 0
c date and time created 85/06/22 22:05:35 by gusella
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
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
E 3
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

D 2
#include "../globals.h"
#include <protocols/timed.h>
E 2
I 2
#include <sys/types.h>
E 2

#define ADD	asm("adwc (r9)+,r8;");

/* computes the checksum for ip packets for the VAX */

in_cksum(addr, len)
u_short *addr;
int len;
{
	register int nleft = len;	/* on vax, (user mode), r11 */
#ifndef lint
	register int xxx;		/* on vax, (user mode), r10 */
#endif not lint
	register u_short *w = addr;	/* on vax, known to be r9 */
	register int sum = 0;		/* on vax, known to be r8 */

	if (((int)w&0x2) && nleft >= 2) {
		sum += *w++;
		nleft -= 2;
	}
	while ((nleft -= 32) >= 0) {
		asm("clrl r0");		/* clears carry */
		ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD;
		asm("adwc $0,r8");
	}
	nleft += 32;
	while ((nleft -= 8) >= 0) {
		asm("clrl r0");
		ADD; ADD;
		asm("adwc $0,r8");
	}
	nleft += 8;
	{ asm("ashl $-16,r8,r0; addw2 r0,r8");
	  asm("adwc $0,r8; movzwl r8,r8"); }
	while ((nleft -= 2) >= 0) {
		asm("movzwl (r9)+,r0; addl2 r0,r8");
	}
	if (nleft == -1) {
		sum += *(u_char *)w;
	}

	{ asm("ashl $-16,r8,r0; addw2 r0,r8; adwc $0,r8");
	  asm("mcoml r8,r8; movzwl r8,r8"); }
	return (sum);
}
E 1
