h01451
s 00010/00005/00049
d D 2.3 88/06/18 14:08:05 bostic 3 2
c install approved copyright notice
e
s 00009/00003/00045
d D 2.2 87/12/23 14:29:59 bostic 2 1
c append Berkeley header; NASA wants a copy
e
s 00048/00000/00000
d D 2.1 86/06/06 20:18:53 mckusick 1 0
c date and time created 86/06/06 20:18:53 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
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
#endif not lint
E 2
I 2
#endif /* not lint */
E 2

#include "../globals.h"
#include <protocols/timed.h>

/* computes the checksum for ip packets for a Motorola 68000 base computer */

in_cksum(w, mlen)
	register u_short *w;
	register int mlen;
{
	register int sum = 0;

	if (mlen > 0) {
		if (((int)w & 1) == 0) {
			sum = ocsum(w, mlen>>1);
			w += mlen>>1;
			if (mlen & 1) {
				sum += *(u_char *)w << 8;
				mlen = -1;
			}
		} else {
			u_short swsum;

			sum = *(u_char *)w << 8;
			mlen--;
			w = (u_short *)(1 + (int)w);
			swsum = ocsum(w, mlen>>1);
			swab((char *)&swsum, (char *)&swsum, sizeof swsum);
			sum += swsum;
			w += mlen>>1;
			if (mlen & 1)
				sum += *(u_char *)w;
		}
	}
	sum = (sum & 0xFFFF) + (sum >> 16);
	sum = (sum & 0xFFFF) + (sum >> 16);
	sum = (~sum) & 0xFFFF;
	return (sum);
}
E 1
