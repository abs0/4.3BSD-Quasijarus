h51605
s 00012/00006/00161
d D 7.3 88/06/29 17:34:36 bostic 6 5
c install approved copyright notice
e
s 00002/00002/00165
d D 7.2 88/05/26 09:05:20 karels 5 4
c lint, header cleanups
e
s 00000/00000/00167
d D 7.1 88/05/21 18:36:09 karels 4 3
c bring up to revision 7 for tahoe release
e
s 00003/00004/00164
d D 1.3 88/03/02 17:43:44 sklower 3 2
c fix case of odd allignments
e
s 00151/00034/00017
d D 1.2 88/02/25 15:43:00 sklower 2 1
c This version avoids shifts, does as much native arithmetic as it
c can, and then inner loop consequently runs 10 times faster than the straight
c forward, but provably correct version.
e
s 00051/00000/00000
d D 1.1 86/01/23 12:59:52 sam 1 0
c date and time created 86/01/23 12:59:52 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/

E 2
/*
D 2
 * ns_cksum.c - Xerox Internet Datagram protocol checksum
E 2
I 2
 * Copyright (c) 1982, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
 *
D 6
 *      %W% (Berkeley) %G%
E 6
I 6
 *	%W% (Berkeley) %G%
E 6
E 2
 */
I 6

E 6
#include "types.h"
#include "mbuf.h"
D 3

E 3
/*
D 2
 * Perform (slowly) the Xerox Internet checksum algorithm on a
 *	chain of mbufs.  This means we add all the 16-bits words,
 *	shifting the sum after each 16-bit add.  Ones-complement
 *	arithmetic is required, so we fold the carry bits after
 *	each 16-bit add as well.
 * If the result is the *no-checksum* value 0xffff, return zero instead.
E 2
I 2
D 3
 * Checksum routine for Network Systems Protocol Packets.
E 3
I 3
 * Checksum routine for Network Systems Protocol Packets (Big-Endian).
E 3
E 2
 *
D 2
 * Chris Torek <chris@maryland>
 * James O'Toole <james@maryland>
E 2
I 2
 * This routine is very heavily used in the network
 * code and should be modified for each CPU to be as fast as possible.
E 2
 */
I 2

D 5
#define ADDCARRY(x)  (x > 65535 ? x -= 65535 : x)
#define FOLD(x) {l_util.l = x; x = l_util.s[0] + l_util.s[1]; ADDCARRY(x);}
E 5
I 5
#define ADDCARRY(x)  { if ((x) > 65535) (x) -= 65535; }
#define FOLD(x) {l_util.l = (x); (x) = l_util.s[0] + l_util.s[1]; ADDCARRY(x);}
E 5

E 2
u_short
ns_cksum(m, len)
	register struct mbuf *m;
	register int len;
{
D 2
	register int cksum = 0;
	register int shift = 8;
	register u_char *p;
	register int mlen;
E 2
I 2
	register u_short *w;
	register int sum = 0;
	register int mlen = 0;
	register int sum2;
E 2

D 2
	if (len & 1)
		printf("ns_cksum: odd length\n");
	while (m && len) {
		p = mtod(m, u_char *);
		mlen = m->m_len;
		if ((len -= mlen) < 0)
			mlen += len, len = 0;
		while (--mlen >= 0) {
			cksum += *p++ << shift;
			if ((shift = 8 - shift) != 0) {
				cksum <<= 1;
				cksum = (cksum & 0xffff) + (cksum >> 16);
			}
E 2
I 2
	union {
		u_short s[2];
		long	l;
	} l_util;

	for (;m && len; m = m->m_next) {
		if (m->m_len == 0)
			continue;
		/*
		 * Each trip around loop adds in
		 * word from one mbuf segment.
		 */
		w = mtod(m, u_short *);
		if (mlen == -1) {
			/*
			 * There is a byte left from the last segment;
			 * ones-complement add it into the checksum.
			 */
			sum  += *(u_char *)w; /* Big-Endian, else << 8 */
			sum += sum;
			w = (u_short *)(1 + (char *)w);
			mlen = m->m_len - 1;
			len--;
			FOLD(sum);
		} else
			mlen = m->m_len;
		if (len < mlen)
			mlen = len;
		len -= mlen;
		/*
		 * We can do a 16 bit ones complement sum using
		 * 32 bit arithmetic registers for adding,
		 * with carries from the low added
		 * into the high (by normal carry-chaining)
		 * so long as we fold back before 16 carries have occured.
		 */
		if (1 & (int) w)
			goto uuuuglyy;
#ifndef TINY
/* -DTINY reduces the size from 1250 to 550, but slows it down by 22% */
		while ((mlen -= 32) >= 0) {
			sum += w[0]; sum += sum; sum += w[1]; sum += sum;
			sum += w[2]; sum += sum; sum += w[3]; sum += sum;
			sum += w[4]; sum += sum; sum += w[5]; sum += sum;
			sum += w[6]; sum += sum; sum += w[7]; sum += sum;
			FOLD(sum);
			sum += w[8]; sum += sum; sum += w[9]; sum += sum;
			sum += w[10]; sum += sum; sum += w[11]; sum += sum;
			sum += w[12]; sum += sum; sum += w[13]; sum += sum;
			sum += w[14]; sum += sum; sum += w[15]; sum += sum;
			FOLD(sum);
			w += 16;
E 2
		}
D 2
		m = m->m_next;
	}
#ifdef notdef
	if (len)
		printf("ns_cksum: out of data\n");
E 2
I 2
		mlen += 32;
E 2
#endif
D 2
	return (cksum == 0xffff ? 0 : cksum);
E 2
I 2
		while ((mlen -= 8) >= 0) {
			sum += w[0]; sum += sum; sum += w[1]; sum += sum;
			sum += w[2]; sum += sum; sum += w[3]; sum += sum;
			FOLD(sum);
			w += 4;
		}
		mlen += 8;
		while ((mlen -= 2) >= 0) {
			sum += *w++; sum += sum;
		}
		goto commoncase;
uuuuglyy:
D 3
#define ww(n) (((char *)w)[n + n])
#define vv(n) (((char *)w)[n + n + 1])
E 3
/* Big-Endian; else reverse ww and vv */
I 3
#define ww(n) (((u_char *)w)[n + n + 1])
#define vv(n) (((u_char *)w)[n + n])
E 3
		sum2 = 0;
#ifndef TINY
		while ((mlen -= 32) >= 0) {
		    sum += ww(0); sum += sum; sum += ww(1); sum += sum;
		    sum += ww(2); sum += sum; sum += ww(3); sum += sum;
		    sum += ww(4); sum += sum; sum += ww(5); sum += sum;
		    sum += ww(6); sum += sum; sum += ww(7); sum += sum;
		    FOLD(sum);
		    sum += ww(8); sum += sum; sum += ww(9); sum += sum;
		    sum += ww(10); sum += sum; sum += ww(11); sum += sum;
		    sum += ww(12); sum += sum; sum += ww(13); sum += sum;
		    sum += ww(14); sum += sum; sum += ww(15); sum += sum;
		    FOLD(sum);
		    sum2 += vv(0); sum2 += sum2; sum2 += vv(1); sum2 += sum2;
		    sum2 += vv(2); sum2 += sum2; sum2 += vv(3); sum2 += sum2;
		    sum2 += vv(4); sum2 += sum2; sum2 += vv(5); sum2 += sum2;
		    sum2 += vv(6); sum2 += sum2; sum2 += vv(7); sum2 += sum2;
		    FOLD(sum2);
		    sum2 += vv(8); sum2 += sum2; sum2 += vv(9); sum2 += sum2;
		    sum2 += vv(10); sum2 += sum2; sum2 += vv(11); sum2 += sum2;
		    sum2 += vv(12); sum2 += sum2; sum2 += vv(13); sum2 += sum2;
		    sum2 += vv(14); sum2 += sum2; sum2 += vv(15); sum2 += sum2;
		    FOLD(sum2);
		    w += 16;
		}
		mlen += 32;
#endif
		while ((mlen -= 8) >= 0) {
		    sum += ww(0); sum += sum; sum += ww(1); sum += sum;
		    sum += ww(2); sum += sum; sum += ww(3); sum += sum;
		    FOLD(sum);
		    sum2 += vv(0); sum2 += sum2; sum2 += vv(1); sum2 += sum2;
		    sum2 += vv(2); sum2 += sum2; sum2 += vv(3); sum2 += sum2;
		    FOLD(sum2);
		    w += 4;
		}
		mlen += 8;
		while ((mlen -= 2) >= 0) {
			sum += ww(0); sum += sum;
			sum2 += vv(0); sum2 += sum2;
			w++;
		}
		sum += (sum2 << 8);
commoncase:
		if (mlen == -1) {
			sum += *(u_char *)w << 8; /* Big-Endian, else no << 8 */
		}
		FOLD(sum);
	}
	if (mlen == -1) {
		/* We had an odd number of bytes to sum; assume a garbage
		   byte of zero and clean up */
		sum += sum;
		FOLD(sum);
	}
	/*
	 * sum has already been kept to low sixteen bits.
	 * just examine result and exit.
	 */
	if(sum==0xffff) sum = 0;
	return (sum);
E 2
}
E 1
