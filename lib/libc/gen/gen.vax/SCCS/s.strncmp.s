h40124
s 00013/00008/00060
d D 5.5 88/06/27 17:25:26 bostic 10 9
c install approved copyright notice
e
s 00011/00005/00057
d D 5.4 88/05/25 17:14:17 bostic 9 8
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00060
d D 5.3 86/03/09 21:15:16 donn 8 7
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00061
d D 5.2 85/06/05 19:01:30 mckusick 7 6
c Fix copyright
e
s 00009/00001/00053
d D 5.1 85/05/30 15:18:00 dist 6 5
c Add copyright
e
s 00016/00009/00038
d D 4.5 84/12/06 17:22:43 mckusick 5 4
c Protect against unexpected page fault
e
s 00003/00003/00044
d D 4.4 84/12/02 14:09:15 mckusick 4 3
c fix bug in computing return value from non-equal strings
e
s 00024/00023/00023
d D 4.3 84/11/14 23:07:42 mckusick 3 2
c speedup by doing cmpc3 then locc; reduce chance for bogus page fault
e
s 00002/00003/00044
d D 4.2 84/11/01 23:52:26 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00047/00000/00000
d D 4.1 84/11/01 23:19:44 sam 1 0
c date and time created 84/11/01 23:19:44 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

D 8
#ifndef lint
E 8
I 8
D 9
#ifdef LIBC_SCCS
E 8
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
	.asciz	"%W% (Berkeley) %G%"
E 7
D 8
#endif not lint
E 8
I 8
#endif LIBC_SCCS
E 9
I 9
D 10
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 10
I 10
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 10
E 9
E 8
E 6

/*
 * Compare at most n characters of string
 * s1 lexicographically to string s2.
 * Return:
 *	0	s1 == s2
 *	> 0	s1 > s2
 *	< 0	s2 < s2
 *
 * strncmp(s1, s2, n)
 *	char *s1, *s2;
 *	int n;
 */
D 2
	.globl	_strncmp
E 2
I 2
#include "DEFS.h"
E 2

D 2
_strncmp:
	.word	0x0
E 2
I 2
ENTRY(strncmp, 0)
E 2
D 3
	movl	12(ap),r5	# r5 = n
	movq	4(ap),r3	# r3 = s1; r4 = s2
E 3
I 3
	movl	4(ap),r1	# r1 = s1
	movq	8(ap),r3	# r3 = s2; r4 = n
E 3
1:
D 3
	locc	$0,$65535,(r4)	# look for '\0' in s2
	bneq	2f
	cmpl	r5,$65535	# n > chunk size?
	bgtr	4f		# yes
	movl	r5,r1		# no, compare only n bytes
	jbr	5f
4:
	subl2	$65535,r5	# adjust n
	cmpc3	$65535,(r4),(r3)# compare full block
	bneq	3f
	movl	r1,r4		# advance s2
	jbr	1b		# matched, next block
E 3
I 3
D 5
	movl	$32,r5		# r5 = current blocksize
	cmpl	r4,r5		# r5 = min(n, 32);
	bgeq	2f
	movl	r4,r5
E 5
I 5
	clrl	r5		# calculate min bytes to next page boundry
	subb3	r1,$255,r5	# r5 = (bytes - 1) to end of page for s1
	subb3	r3,$255,r0	# r0 = (bytes - 1) to end of page for s2
	cmpb	r0,r5		# r5 = min(r0, r5);
	bgtru	2f
	movb	r0,r5
E 5
E 3
2:
I 5
	incl	r5		# r5 = min bytes to next page boundry
	cmpl	r4,r5		# r5 = min(n, r5);
	bgeq	3f
	movl	r4,r5
3:
E 5
D 3
	subl2	r4,r1		# calculate length
	incl	r1		# +1 for '\0'
	cmpl	r1,r5		# length <= n
	bleq	5f		# yes, compare full string
	movl	r5,r1		# no, compare only n bytes
5:
	cmpc3	r1,(r4),(r3)	# compare remainder
E 3
I 3
	cmpc3	r5,(r1),(r3)	# compare strings
E 3
D 5
	bneq	3f
E 5
I 5
	bneq	4f
E 5
D 3
	ret			# r0 = 0 already
E 3
I 3
	subl2	r5,r4		# check for end of comparison
D 5
	beql	4f
E 5
I 5
	beql	5f
E 5
	subl2	r5,r1		# check if found null yet
	locc	$0,r5,(r1)
	beql	1b		# not yet done, continue checking
D 4
	subl2	r5,r0
	mnegb	(r0)[r3],r0	# r0 = $0 - *s2
E 4
I 4
	subl2	r0,r3
	mnegb	(r3),r0		# r0 = '\0' - *s2
E 4
	cvtbl	r0,r0
	ret
E 3
D 5
3:
E 5
I 5
4:
E 5
D 3
	subb3	(r1),(r3),r0	# r0 = *s1 - *s2
E 3
I 3
	subl2	r0,r5		# check for null in matching string
	subl2	r5,r1
	locc	$0,r5,(r1)
D 5
	bneq	4f
E 5
I 5
	bneq	5f
E 5
D 4
	subb3	(r3),-(r1),r0	# r0 = *s1 - *s2
E 4
I 4
	subb3	(r3),(r1),r0	# r0 = *s1 - *s2
E 4
E 3
	cvtbl	r0,r0
I 3
	ret
D 5
4:
E 5
I 5
5:
E 5
	clrl	r0		# both the same to null
E 3
	ret
E 1
