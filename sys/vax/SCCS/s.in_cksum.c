h01275
s 00010/00005/00136
d D 7.3 88/06/29 17:52:18 bostic 25 24
c install approved copyright notice
e
s 00008/00004/00133
d D 7.2 88/03/29 16:32:55 karels 24 23
c update copyrights, rm unnecessary inet includes
e
s 00001/00001/00136
d D 7.1 86/06/05 00:43:52 mckusick 23 22
c 4.3BSD release version
e
s 00007/00001/00130
d D 6.4 85/06/08 13:42:26 mckusick 22 21
c Add copyright
e
s 00006/00002/00125
d D 6.3 85/05/01 11:31:09 karels 21 20
c remove "clrl r0", which didn't clear carry
e
s 00002/00002/00125
d D 6.2 84/08/28 18:09:45 bloom 20 19
c Change to includes.  No more ../h
e
s 00000/00000/00127
d D 6.1 83/07/29 07:19:57 sam 19 18
c 4.2 distribution
e
s 00003/00026/00124
d D 1.17 83/01/17 17:34:15 sam 18 17
c consider machine dependent now, so purge sun crud
e
s 00030/00007/00120
d D 1.16 82/10/31 14:52:00 root 17 16
c #ifdef sun
e
s 00001/00001/00126
d D 1.15 82/10/30 13:02:43 root 16 15
c get rid of conditional htons/ntohs etc
e
s 00002/00002/00125
d D 1.14 82/10/17 14:54:35 root 15 14
c fix lint
e
s 00002/00002/00125
d D 1.13 82/10/09 05:44:53 wnj 14 13
c localize header files
e
s 00000/00001/00127
d D 1.12 82/06/20 00:53:50 sam 13 12
c purge COUNT stuff now that we can use gprof
e
s 00004/00004/00124
d D 1.11 81/11/26 11:56:15 wnj 12 11
c before carry to ARPAVAX
e
s 00064/00017/00064
d D 1.10 81/11/18 15:36:44 wnj 11 10
c more cleanup
e
s 00001/00001/00080
d D 1.9 81/11/08 16:38:41 wnj 10 9
c restore sccs keywords
e
s 00005/00005/00076
d D 1.8 81/11/08 16:36:42 wnj 9 8
c first listing
e
s 00003/00003/00078
d D 1.7 81/10/29 20:27:10 wnj 8 7
c cleanup of header files
e
s 00006/00003/00075
d D 1.6 81/10/28 16:38:06 wnj 7 5
c first compiled halfbrid... not working yet
e
s 00022/00000/00078
d R 1.6 81/10/26 02:09:53 wnj 6 5
c first compile of major cleanup
e
s 00001/00000/00077
d D 1.5 81/10/21 19:07:03 wnj 5 4
c cleanup the headers
e
s 00013/00013/00064
d D 1.4 81/10/20 14:12:05 wnj 4 3
c faster cksum
e
s 00005/00002/00072
d D 1.3 81/10/18 09:59:56 wnj 3 2
c not fatal to run out of data in cksum (for now)
e
s 00002/00075/00072
d D 1.2 81/10/16 16:25:05 wnj 2 1
c first working version with software interrupts
e
s 00147/00000/00000
d D 1.1 81/10/14 19:16:27 wnj 1 0
c date and time created 81/10/14 19:16:27 by wnj
e
u
U
t
T
I 1
D 9
/* %M% %I% %E% */
E 9
I 9
D 10
/* inet_cksum.c 1.7 81/10/29 */
E 10
I 10
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
D 15
/* %M% %I% %E% */
E 15
I 15
D 22
/*	%M%	%I%	%E%	*/
E 22
I 22
/*
D 23
 * Copyright (c) 1982 Regents of the University of California.
E 23
I 23
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 23
D 24
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 24
I 24
 * All rights reserved.
E 24
 *
I 24
 * Redistribution and use in source and binary forms are permitted
D 25
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 25
I 25
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
E 25
 *
E 24
 *	%W% (Berkeley) %G%
 */
E 22
E 15
E 11
E 10
E 9

D 18
#include <sys/types.h>
E 18
I 18
D 20
#include "../h/types.h"
E 18
D 8
#include "../bbnnet/net.h"
I 5
#include "../bbnnet/mbuf.h"
E 5
#include "../bbnnet/count.h"
E 8
I 8
#include "../h/mbuf.h"
E 20
I 20
#include "types.h"
#include "mbuf.h"
E 20
D 9
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
E 9
I 9
D 12
#include "../net/inet.h"
#include "../net/inet_systm.h"
E 12
I 12
D 14
#include "../net/in.h"
#include "../net/in_systm.h"
E 14
I 14
D 24
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 24
E 14
E 12
E 9
E 8

/*
D 11
 * Network primitives; this file varies per-cpu,
 * and the code here is for VAX only.
E 11
I 11
D 18
 * Checksum routine for Internet Protocol family headers.
E 18
I 18
 * Checksum routine for Internet Protocol family headers (VAX Version).
 *
E 18
 * This routine is very heavily used in the network
D 17
 * code and should be rewritten for each CPU to be as fast as possible.
E 17
I 17
 * code and should be modified for each CPU to be as fast as possible.
E 17
E 11
 */
D 2
cksum(m, len)
register struct mbuf *m;
{
	int i,j;
	i = ncksum(m, len);
	j = ocksum(m, len);
	if (i != j) {
		printf("old %x new %x \n", i, j);
		while (m != 0) {
			printf("m->m_off %d m->m_len %d\n", m->m_off, m->m_len);
			m = m->m_next;
		}
	}
	return (j);
}
E 2

D 11
/*
 * Checksum routine for TCP/IP headers.  This
 * is very heavily used in the network
 * code and should be rewritten for each CPU
 * to be as fast as possible.
 */
E 11
I 11
D 15
#if vax
E 15
I 15
D 16
#if vax || pdp11 || ns16032
E 16
I 16
D 17
#if vax
E 17
E 16
E 15
E 11
D 2
ncksum(m, len)
E 2
I 2
D 9
cksum(m, len)
E 9
I 9
D 12
inet_cksum(m, len)
E 12
I 12
in_cksum(m, len)
E 12
E 9
E 2
	register struct mbuf *m;
	register int len;
{
D 4
	register u_short *w;		/* known to be r9 */
E 4
I 4
D 11
	register long *l;		/* known to be r9 */
E 11
I 11
D 17
	register u_short *w;		/* known to be r9 */
E 11
E 4
	register int sum = 0;		/* known to be r8 */
E 17
I 17
	register u_short *w;		/* on vax, known to be r9 */
	register int sum = 0;		/* on vax, known to be r8 */
E 17
I 4
D 11
	register u_short *w;		/* known to be r7 */
E 11
E 4
	register int mlen = 0;
D 2
COUNT(NCKSUM);
E 2
I 2
D 9
COUNT(CKSUM);
E 9
I 9
D 12
COUNT(INET_CKSUM);
E 12
I 12
D 13
COUNT(IN_CKSUM);
E 13
E 12
E 9
E 2

	for (;;) {
D 11
		w = (u_short *)((int)m + m->m_off);
E 11
I 11
		/*
		 * Each trip around loop adds in
		 * word from one mbuf segment.
		 */
		w = mtod(m, u_short *);
E 11
		if (mlen == -1) {
I 11
			/*
			 * There is a byte left from the last segment;
			 * add it into the checksum.  Don't have to worry
			 * about a carry-out here because we make sure
			 * that high part of (32 bit) sum is small below.
			 */
I 17
D 18
#ifdef sun
			sum += *(u_char *)w;
#endif
#ifdef vax
E 18
E 17
E 11
			sum += *(u_char *)w << 8;
I 17
D 18
#endif
E 18
E 17
D 7
			w = (unsigned short *)((char *)w + 1);
E 7
I 7
			w = (u_short *)((char *)w + 1);
E 7
			mlen = m->m_len - 1;
			len--;
		} else
			mlen = m->m_len;
		m = m->m_next;
		if (len < mlen)
			mlen = len;
		len -= mlen;
I 17
D 18
#ifdef sun
		sum += ocsum(w, mlen>>1);
		w += mlen>>1;
#endif
#ifdef vax
E 18
E 17
I 4
D 11
		l = (long *)w;
E 11
I 11
		/*
		 * Force to long boundary so we do longword aligned
		 * memory operations.  It is too hard to do byte
		 * adjustment, do only word adjustment.
		 */
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
E 11
E 4
		while ((mlen -= 32) >= 0) {
D 4
#define ADD		asm("movzwl (r9)+,r0; addl2 r0,r8");
E 4
I 4
D 17
			asm("clrl r0");		/* clears carry */
E 17
#undef ADD
I 17
D 21
			asm("clrl r0");		/* clears carry */
E 21
I 21
#ifdef unneeded		 /* The loop construct clears carry for us... */
			asm("bicpsr $1");		/* clears carry */
#endif
E 21
E 17
#define ADD		asm("adwc (r9)+,r8;");
E 4
			ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD;
D 4
			ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD;
E 4
I 4
			asm("adwc $0,r8");
E 4
		}
		mlen += 32;
		while ((mlen -= 8) >= 0) {
D 4
			ADD; ADD; ADD; ADD;
E 4
I 4
D 21
			asm("clrl r0");
E 21
I 21
#ifdef unneeded		 /* The loop construct clears carry for us... */
			asm("bicpsr $1");		/* clears carry */
#endif
E 21
			ADD; ADD;
			asm("adwc $0,r8");
E 4
		}
		mlen += 8;
I 4
D 11
		sum = ((sum >> 16) & 0xffff) + (sum & 0xffff);
		w = (u_short *)l;
E 11
I 11
		/*
		 * Now eliminate the possibility of carry-out's by
		 * folding back to a 16 bit number (adding high and
		 * low parts together.)  Then mop up trailing words
		 * and maybe an odd byte.
		 */
		{ asm("ashl $-16,r8,r0; addw2 r0,r8");
		  asm("adwc $0,r8; movzwl r8,r8"); }
E 11
E 4
		while ((mlen -= 2) >= 0) {
D 4
			ADD;
E 4
I 4
D 11
			asm("movzwl (r7)+,r0; addl2 r0,r8");
E 11
I 11
			asm("movzwl (r9)+,r0; addl2 r0,r8");
E 11
E 4
		}
D 17
		if (mlen == -1)
E 17
I 17
		if (mlen == -1) {
E 17
			sum += *(u_char *)w;
I 17
		}
D 18
#endif vax
#ifdef sun
		if (mlen & 1) {
			sum += *(u_char *)w << 8;
			mlen = -1;
		}
#endif
E 18
E 17
		if (len == 0)
			break;
I 11
		/*
		 * Locate the next block with some data.
		 * If there is a word split across a boundary we
		 * will wrap to the top with mlen == -1 and
		 * then add it in shifted appropriately.
		 */
E 11
		for (;;) {
D 3
			if (m == 0)
				panic("cksum: out of data");
E 3
I 3
			if (m == 0) {
D 7
				printf("cksum: out of data");
E 7
I 7
				printf("cksum: out of data\n");
E 7
				goto done;
			}
E 3
			if (m->m_len)
				break;
			m = m->m_next;
		}
	}
I 3
done:
E 3
D 7
	return(~(sum + (sum >> 16)) & 0xffff);
E 7
I 7
D 11
	/* add together high and low parts of sum and carry to get cksum */
E 11
I 11
	/*
	 * Add together high and low parts of sum
	 * and carry to get cksum.
	 * Have to be careful to not drop the last
	 * carry here.
	 */
I 17
D 18
#ifdef sun
	sum = (sum & 0xFFFF) + (sum >> 16);
	sum = (sum & 0xFFFF) + (sum >> 16);
	sum = (~sum) & 0xFFFF;
#endif
#ifdef vax
E 18
E 17
E 11
	{ asm("ashl $-16,r8,r0; addw2 r0,r8; adwc $0,r8");
	  asm("mcoml r8,r8; movzwl r8,r8"); }
I 17
D 18
#endif
E 18
E 17
	return (sum);
E 7
}
I 11
D 17
#endif
E 17
E 11
D 4

/*
 * These routines are implemented as inline expansions
 * and are mentioned here for reference only
 *
 *	htons and ntohs		do byte reverse of a 16 bit integer
 *	htonl and ntohl		do byte reverse of a 32 bit integer
 */
E 4
D 2
ocksum(m, len)
register struct mbuf *m;
register len;
{
	register unsigned short *w;
	register unsigned long sum;
	register mlen;
COUNT(OCKSUM);

	w = (unsigned short *)((int)m + m->m_off);
	mlen = m->m_len;
	sum = 0;

	for (; len > 0; len -= 2, mlen -= 2) {

try:            if (mlen > 1) {         /* can get a word */

			if (len > 1) {
				sum += *(w++);

			} else            /* trailing odd byte */

				sum += *((char *)w) & 0xff;

		} else if (mlen > 0) {  /* last byte of mbuf */

			sum += *((char *)w) & 0xff;

			if (len > 1) {

        			/* get next good mbuf for hi byte */
        
        			while ((m = m->m_next) != 0 && 
					(mlen = m->m_len + 1) == 1);
        			if (m != 0) {
        				w = (unsigned short *)((int)m + m->m_off);
        				sum += (*((char *)w) & 0xff) << 8;
					w = (unsigned short *)((int)w + 1);
        			} else
        				len = 0;        /* force loop exit */
			}

		} else {                /* end of mbuf, get next and try again */

			while ((m = m->m_next) != 0 && (mlen = m->m_len) == 0);
			if (m != 0) {
				w = (unsigned short *)((int)m + m->m_off);
				goto try;
			} else
				break;
		}
	}

	/* add in one's complement carry */

	sum = (sum + (sum >> 16)) & 0xffff;
	return(~sum & 0xffff);
}
E 2
E 1
