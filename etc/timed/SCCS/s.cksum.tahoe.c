h22811
s 00010/00005/00070
d D 2.3 88/06/18 14:08:06 bostic 3 2
c install approved copyright notice
e
s 00009/00003/00066
d D 2.2 87/12/23 14:30:01 bostic 2 1
c append Berkeley header; NASA wants a copy
e
s 00069/00000/00000
d D 2.1 86/10/13 15:48:00 sam 1 0
c date and time created 86/10/13 15:48:00 by sam
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
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
#endif /* not lint */
E 2

#include <sys/types.h>

/*
 * Checksum routine for Internet Protocol family headers.
 *
 * This routine is very heavily used in the network
 * code and should be modified for each CPU to be as fast as possible.
 * 
 * This implementation is TAHOE version.
 */

#undef	ADDCARRY
#define ADDCARRY(sum) { \
	if (sum & 0xffff0000) {	\
		sum &= 0xffff; \
		sum++; \
	} \
}

in_cksum(addr, len)
	register u_short *addr;
	register int len;
{
	union word {
		char	c[2];
		u_short	s;
	} u;
	register int sum = 0;

	while (len > 0) {
		/*
		 * add by words.
		 */
		while ((len -= 2) >= 0) {
			if ((int)addr & 0x1) {
				/* word is not aligned */
				u.c[0] = *(char *)addr;
				u.c[1] = *((char *)addr+1);
				sum += u.s;
				addr++;
			} else
				sum += *addr++;
			ADDCARRY(sum);
		}
		if (len == -1)
			/*
			 * Odd number of bytes. 
			 */
			u.c[0] = *(u_char *)addr;
	}
	if (len == -1) {
		/* The last mbuf has odd # of bytes. Follow the
		   standard (the odd byte is shifted left by 8 bits) */
		u.c[1] = 0;
		sum += u.s;
		ADDCARRY(sum);
	}
	return (~sum & 0xffff);
}
E 1
