h21658
s 00012/00006/00151
d D 7.3 88/06/29 17:34:34 bostic 7 6
c install approved copyright notice
e
s 00004/00002/00153
d D 7.2 88/05/26 09:05:15 karels 6 5
c lint, header cleanups
e
s 00000/00000/00155
d D 7.1 88/05/21 18:35:19 karels 5 4
c bring up to revision 7 for tahoe release
e
s 00009/00010/00146
d D 1.4 88/03/02 16:08:24 sklower 4 3
c fix logic in dealing with chaining; works now.
e
s 00104/00044/00052
d D 1.3 88/02/25 15:38:22 sklower 3 2
c This version uses the adwc instruction and runs fast.
e
s 00004/00142/00092
d D 1.2 86/01/05 18:42:24 sam 2 1
c 1st working version
e
s 00234/00000/00000
d D 1.1 85/07/25 22:50:52 sam 1 0
c date and time created 85/07/25 22:50:52 by sam
e
u
U
t
T
I 1
D 2
/*	in_cksum.c	6.1	83/07/29	*/
E 2
I 2
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1982, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
 *
D 7
 *      %W% (Berkeley) %G%
E 7
I 7
 *	%W% (Berkeley) %G%
E 7
 */
I 7

E 7
#include "types.h"
#include "mbuf.h"
E 3
E 2

D 3
#include "../h/types.h"
#include "../h/mbuf.h"
#include "../netinet/in.h"
#include "../netinet/in_systm.h"

E 3
D 2
#if defined(tahoe)
E 2
/*
D 3
 * Checksum routine for Internet Protocol family headers.
E 3
I 3
 * Checksum routine for Internet Protocol family headers (CCI Version).
E 3
 *
 * This routine is very heavily used in the network
 * code and should be modified for each CPU to be as fast as possible.
D 3
 * 
 * This implementation is TAHOE version.
E 3
 */

D 3
#undef	ADDCARRY
#define ADDCARRY(sum)  {				\
			if (sum & 0xffff0000) {		\
				sum &= 0xffff;		\
				sum++;			\
			}				\
		}
E 3
I 3
D 6
#define ADDCARRY(x)  (x > 65535 ? x -= 65535 : x)
E 6
I 6
#define ADDCARRY(x)  { if ((x) > 65535) (x) -= 65535; }
E 6
#define REDUCE {l_util.l = sum; sum = l_util.s[0] + l_util.s[1]; ADDCARRY(sum);}

#define ADD(n)	asm("adwc n (r10),r9")
#define MOP	asm("adwc $0,r9")
#define BOTCH	asm("addl2 r7,r9")

E 3
in_cksum(m, len)
	register struct mbuf *m;
	register int len;
{
D 3
	union word {
E 3
I 3
	register u_short *w;		/* On CCI, known to be r10 */
	register int sum = 0;		/* On CCI, known to be r9 */
	register int mlen = 0;
D 6
	register int ClearCarry = 0;	/* On CCI, known to be r7 */
E 6
I 6
#ifndef lint
	register int ClearCarry = 0;	/* On CCI, known to be r7; see BOTCH */
#endif
E 6
	int byte_swapped = 0;

	union {
E 3
		char	c[2];
		u_short	s;
D 3
	} u;
	register u_short *w;
	register int sum = 0;
	register int mlen = 0;
E 3
I 3
	} s_util;
	union {
		u_short s[2];
		long	l;
	} l_util;
E 3

	for (;m && len; m = m->m_next) {
D 2

		if (m->m_len == 0) {
E 2
I 2
		if (m->m_len == 0)
E 2
			continue;
D 2
		}

E 2
		w = mtod(m, u_short *);
		if (mlen == -1) {
			/*
			 * The first byte of this mbuf is the continuation
			 * of a word spanning between this mbuf and the
			 * last mbuf.
I 3
			 *
			 * s_util.c[0] is already saved when scanning previous 
			 * mbuf.  sum was REDUCEd when we found mlen == -1.
E 3
			 */
D 3

			/* u.c[0] is already saved when scanning previous 
			 * mbuf.
			 */
			u.c[1] = *(u_char *)w;
			sum += u.s;
			ADDCARRY(sum);
E 3
I 3
			s_util.c[1] = *(char *)w;
			sum += s_util.s;
E 3
D 2

E 2
			w = (u_short *)((char *)w + 1);
			mlen = m->m_len - 1;
			len--;
		} else
			mlen = m->m_len;
D 3

E 3
		if (len < mlen)
			mlen = len;
		len -= mlen;
D 3

E 3
		/*
D 3
		 * add by words.
E 3
I 3
		 * Force to long boundary so we do longword aligned
		 * memory operations.
E 3
		 */
D 3
		while ((mlen -= 2) >= 0) {
D 2
			
E 2
			if ((int)w & 0x1) {
				/* word is not aligned */
				u.c[0] = *(char *)w;
				u.c[1] = *((char *)w+1);
				sum += u.s;
				w++;
D 2
			}
			else {
E 2
I 2
			} else
E 3
I 3
		if (3 & (int) w) {
			REDUCE;
D 4
			if (1 & (int) w) {
E 4
I 4
			if ((1 & (int) w) && (mlen > 0)) {
E 4
				sum <<= 8;
D 4
				sum += *(u_char *)w;
E 4
I 4
				s_util.c[0] = *(char *)w;
E 4
				w = (u_short *)((char *)w + 1);
				mlen--;
				byte_swapped = 1;
			}
D 4
			if ((2 & (int) w) && mlen >= 2) {
E 4
I 4
			if ((2 & (int) w) && (mlen >= 2)) {
E 4
E 3
E 2
				sum += *w++;
D 2
			}
E 2
D 3
			ADDCARRY(sum);
E 3
I 3
				mlen -= 2;
			}
E 3
		}
I 3
		/*
		 * Do as much of the checksum as possible 32 bits at at time.
		 * In fact, this loop is unrolled to make overhead from
		 * branches &c small.
		 */
		while ((mlen -= 32) >= 0) {
			/*
			 * The loop construct clears carry for us
			 * on vaxen, however, on the CCI machine subtracting
			 * a small postive number from a larger one doesn't.
			 * 
			 * Doing a bicpsw is very slow (slows down the routine
			 * by a factor of 2); explicitly adding an immediate
			 * 0 to a register is optimized out; so we fake out
			 * the optimizer and add a register whose contents
			 * is always zero.
			 */
			BOTCH;
			ADD(0); ADD(4); ADD(8); ADD(12);
			ADD(16); ADD(20); ADD(24); ADD(28);
			MOP; w += 16;
		}
		mlen += 32;
		while ((mlen -= 8) >= 0) {
			BOTCH;
			ADD(0); ADD(4);
			MOP;
			w += 4;
		}
		mlen += 8;
		if (mlen == 0 && byte_swapped == 0)
			continue;	/* worth 1% maybe ?? */
		REDUCE;
		while ((mlen -= 2) >= 0) {
			sum += *w++;
		}
		if (byte_swapped) {
I 4
			sum <<= 8;
			byte_swapped = 0;
E 4
			if (mlen == -1) {
D 4
				s_util.c[0] = *(char *)w;
				s_util.c[1] = 0;
E 4
I 4
				s_util.c[1] = *(char *)w;
E 4
				sum += s_util.s;
				mlen = 0;
D 4
			}
			sum <<= 8;
			byte_swapped = 0;
		}
E 3
D 2
		if (mlen == -1) {
E 2
I 2
		if (mlen == -1)
E 4
I 4
			} else
				mlen = -1;
		} else if (mlen == -1)
E 4
E 2
			/*
			 * This mbuf has odd number of bytes. 
			 * There could be a word split betwen
			 * this mbuf and the next mbuf.
			 * Save the last byte (to prepend to next mbuf).
			 */
D 3
			u.c[0] = *(u_char *)w;
E 3
I 3
			s_util.c[0] = *(char *)w;
E 3
D 2
		}
E 2
	}
	if (len)
		printf("cksum: out of data\n");
	if (mlen == -1) {
		/* The last mbuf has odd # of bytes. Follow the
		   standard (the odd byte is shifted left by 8 bits) */
D 3
		u.c[1] = 0;
		sum += u.s;
		ADDCARRY(sum);
E 3
I 3
		s_util.c[1] = 0;
		sum += s_util.s;
E 3
	}
I 3
	REDUCE;
E 3
D 2
done:
E 2
	return (~sum & 0xffff);
}
D 2
#endif

#if defined(vax)

/*
 * Checksum routine for Internet Protocol family headers (VAX Version).
 *
 * This routine is very heavily used in the network
 * code and should be modified for each CPU to be as fast as possible.
 */

in_cksum(m, len)
	register struct mbuf *m;
	register int len;
{
	register u_short *w;		/* on Tahoe, known to be r10 */
	register int sum = 0;		/* on Tahoe, known to be r9 */
	register int mlen = 0;

	for (;;) {
		/*
		 * Each trip around loop adds in
		 * word from one mbuf segment.
		 */
		w = mtod(m, u_short *);
		if (mlen == -1) {
			/*
			 * There is a byte left from the last segment;
			 * add it into the checksum.  Don't have to worry
			 * about a carry-out here because we make sure
			 * that high part of (32 bit) sum is small below.
			 */
			sum += *(u_char *)w << 8;
			w = (u_short *)((char *)w + 1);
			mlen = m->m_len - 1;
			len--;
		} else
			mlen = m->m_len;
		m = m->m_next;
		if (len < mlen)
			mlen = len;
		len -= mlen;
		/*
		 * Force to long boundary so we do longword aligned
		 * memory operations.  
		 */
		if (((int)w&0x1) && mlen >= 1) {
			sum += *(u_char *)w++;
			mlen -= 1;
		}
		if (((int)w&0x2) && mlen >= 2) {
			sum += *w++;
			mlen -= 2;
		}
		/*
		 * Do as much of the checksum as possible 32 bits at at time.
		 * In fact, this loop is unrolled to make overhead from
		 * branches &c small.
		 *
		 * We can do a 16 bit ones complement sum 32 bits at a time
		 * because the 32 bit register is acting as two 16 bit
		 * registers for adding, with carries from the low added
		 * into the high (by normal carry-chaining) and carries
		 * from the high carried into the low on the next word
		 * by use of the adwc instruction.  This lets us run
		 * this loop at almost memory speed.
		 *
		 * Here there is the danger of high order carry out, and
		 * we carefully use adwc.
		 */
		while ((mlen -= 32) >= 0) {
#undef ADD
			asm("clrl r0");		/* clears carry */
#define ADD		asm("adwc (r10),r9;addl2 $4,r10; ");
			ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD;
			asm("adwc $0,r9");
		}
		mlen += 32;
		while ((mlen -= 8) >= 0) {
			asm("clrl r0");
			ADD; ADD;
			asm("adwc $0,r9");
		}
		mlen += 8;
		/*
		 * Now eliminate the possibility of carry-out's by
		 * folding back to a 16 bit number (adding high and
		 * low parts together.)  Then mop up trailing words
		 * and maybe an odd byte.
		 */
		{ asm("shal $-16,r9,r0; addw2 r0,r9");
		  asm("adwc $0,r9; movzwl r9,r9"); }
		while ((mlen -= 2) >= 0) {
			asm("movzwl (r10),r0;addl2 $4,r10;  addl2 r0,r9");
		}
		if (mlen == -1) {
			sum += *(u_char *)w;
		}
		if (len == 0)
			break;
		/*
		 * Locate the next block with some data.
		 * If there is a word split across a boundary we
		 * will wrap to the top with mlen == -1 and
		 * then add it in shifted appropriately.
		 */
		for (;;) {
			if (m == 0) {
				printf("cksum: out of data\n");
				goto done;
			}
			if (m->m_len)
				break;
			m = m->m_next;
		}
	}
done:
	/*
	 * Add together high and low parts of sum
	 * and carry to get cksum.
	 * Have to be careful to not drop the last
	 * carry here.
	 */
	{ asm("shal $-16,r9,r0; addw2 r0,r9; adwc $0,r9");
	  asm("mcoml r9,r9; movzwl r9,r9"); }
	return (sum);
}
#endif
E 2
E 1
