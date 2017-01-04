h24267
s 00010/00005/00134
d D 7.3 88/06/29 17:52:20 bostic 8 7
c install approved copyright notice
e
s 00009/00002/00130
d D 7.2 88/03/29 16:32:57 karels 7 6
c update copyrights, rm unnecessary inet includes
e
s 00001/00001/00131
d D 7.1 86/06/05 00:46:48 mckusick 6 5
c 4.3BSD release version
e
s 00001/00001/00131
d D 6.5 86/02/20 17:16:16 sklower 5 4
c shut lint up about register used only by asm's.
e
s 00003/00003/00129
d D 6.4 86/02/17 12:39:37 sklower 4 3
c fix defective copyright notice.  no more include "../h/*".
e
s 00029/00020/00103
d D 6.3 85/06/21 20:36:41 sklower 3 2
c attempts to  eliminate unnecessary forcing of word alignment broke it.
e
s 00007/00001/00116
d D 6.2 85/06/08 13:44:34 mckusick 2 1
c Add copyright
e
s 00117/00000/00000
d D 6.1 85/05/30 19:13:39 sklower 1 0
c date and time created 85/05/30 19:13:39 by sklower
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 4
 * Copyright (c) 1982 Regents of the University of California.
E 4
I 4
D 6
 * Copyright (c) 1985 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1985, 1986 Regents of the University of California.
E 6
E 4
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
E 7
 *
I 7
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
 *
E 7
 *	%W% (Berkeley) %G%
 */
I 7

E 7
I 3
D 4
#include "../h/types.h"
#include "../h/mbuf.h"
E 4
I 4
#include "types.h"
#include "mbuf.h"
E 4
E 3
E 2

D 3
#include "types.h"
#include "mbuf.h"
#include "../netns/ns.h"
E 3

/*
 * Checksum routine for Network Systems Protocol Packets (VAX Version).
 *
 * This routine is very heavily used in the network
 * code and should be modified for each CPU to be as fast as possible.
 */
I 3

E 3
u_short
ns_cksum(m, len)
	register struct mbuf *m;
	register int len;
{
	register u_short *w;		/* on vax, known to be r9 */
	register int sum = 0;		/* on vax, known to be r8 */
	register int low = 0;		/* on vax, known to be r7 */
D 5
	register int mlen = 0;
E 5
I 5
	register int mlen = low;	/* want 0, shuts lint up about low */
E 5

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
D 3
			 * about a carry-out here because although we may do
			 * the 16th and 17th additions, the contribution
			 * of this byte and the previous cannot cause
			 * more than 1 carry into the high order 16 bits.
E 3
I 3
			 * about a carry-out here because we make sure
			 * that high part of (32 bit) sum is small below.
E 3
			 */
			sum += *(u_char *)w << 8;
			sum += sum;
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
D 3
		 * This loop is unrolled to make overhead from
		 * branches &c small.
E 3
I 3
		 * Force to long boundary so we do longword aligned
		 * memory operations.  It is too hard to do byte
		 * adjustment, do only word adjustment.
		 */
		if (((int)w&0x2) && mlen >= 2) {
			sum += *w++;
			sum += sum;
			mlen -= 2;
		}
		/*
E 3
		 *
D 3
		 * We can do a 16 bit ones complement sum 32 bits at a time
		 * by using regular arithmetic for 16 additions, then
		 * folding the carries in.  Each addition can generate
		 * no more than one carry.
E 3
I 3
		 * We can do a 16 bit ones complement sum using
		 * 32 bit arithmetic registers for adding,
		 * with carries from the low added
		 * into the high (by normal carry-chaining)
		 * so long as we fold back before 16 carries have occured.
E 3
		 *
		 */
		while ((mlen -= 32) >= 0) {
I 3
			/*asm("bicpsw $1");		 clears carry */
E 3
#undef ADD
#define ADD asm("movw (r9)+,r7")asm("addl2 r7,r8")asm("addl2 r8,r8")
#define FOLD { asm("ashl $-16,r8,r0")asm(" addw2 r0,r8"); \
		  asm("adwc $0,r8")asm(" movzwl r8,r8"); }
			FOLD;
			ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD;
			FOLD;
			ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD;
		}
		mlen += 32;
D 3
		while ((mlen -= 16) >= 0) {
E 3
I 3
		while ((mlen -= 8) >= 0) {
			/*asm("bicpsw $1");		 clears carry */
E 3
			FOLD;
D 3
			ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD; 
E 3
I 3
			ADD; ADD; ADD; ADD;
E 3
		}
D 3
		mlen += 16;
E 3
I 3
		mlen += 8;
E 3
		/*
		 * Now eliminate the possibility of carry-out's by
		 * folding back to a 16 bit number (adding high and
		 * low parts together.)  Then mop up trailing words
D 3
		 * and maybe an odd byte. There can be at most 7
		 * words added in this loop, or 14 carries.
E 3
I 3
		 * and maybe an odd byte.
E 3
		 */
		FOLD;
		while ((mlen -= 2) >= 0) {
			ADD;
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
D 3
				printf("cksum: out of data\n");
E 3
I 3
				printf("idpcksum: out of data\n");
E 3
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
	FOLD;
I 3
	
E 3
	if(sum==0xffff) sum = 0;
D 3
	return ((u_short)sum);
E 3
I 3
	return (sum);
E 3
}
E 1
