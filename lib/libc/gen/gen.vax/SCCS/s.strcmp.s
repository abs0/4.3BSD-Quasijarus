h31768
s 00013/00008/00056
d D 5.5 88/06/27 17:25:21 bostic 11 10
c install approved copyright notice
e
s 00011/00005/00053
d D 5.4 88/05/25 17:14:02 bostic 10 9
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00056
d D 5.3 86/03/09 21:14:33 donn 9 8
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00057
d D 5.2 85/06/05 19:00:33 mckusick 8 7
c Fix copyright
e
s 00009/00001/00049
d D 5.1 85/05/30 15:16:41 dist 7 6
c Add copyright
e
s 00004/00000/00046
d D 4.6 85/04/24 13:39:14 mckusick 6 5
c make quick check for different strings
e
s 00020/00011/00026
d D 4.5 84/12/06 17:22:39 mckusick 5 4
c Protect against unexpected page fault
e
s 00003/00002/00034
d D 4.4 84/12/02 14:09:11 mckusick 4 3
c fix bug in computing return value from non-equal strings
e
s 00015/00012/00021
d D 4.3 84/11/14 23:07:38 mckusick 3 2
c speedup by doing cmpc3 then locc; reduce chance for bogus page fault
e
s 00002/00003/00031
d D 4.2 84/11/01 23:52:07 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00034/00000/00000
d D 4.1 84/11/01 23:19:40 sam 1 0
c date and time created 84/11/01 23:19:40 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */

D 9
#ifndef lint
E 9
I 9
D 10
#ifdef LIBC_SCCS
E 9
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
	.asciz	"%W% (Berkeley) %G%"
E 8
D 9
#endif not lint
E 9
I 9
#endif LIBC_SCCS
E 10
I 10
D 11
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 11
I 11
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 11
E 10
E 9
E 7

/*
 * Compare string s1 lexicographically to string s2.
 * Return:
 *	0	s1 == s2
 *	> 0	s1 > s2
 *	< 0	s2 < s2
 *
 * strcmp(s1, s2)
 *	char *s1, *s2;
 */
D 2
	.globl	_strcmp
E 2
I 2
#include "DEFS.h"
E 2

D 2
_strcmp:
	.word	0x0
E 2
I 2
ENTRY(strcmp, 0)
E 2
D 3
	movq	4(ap),r3	# r3 = s1; r4 = s2
E 3
I 3
	movl	4(ap),r1	# r1 = s1
	movl	8(ap),r3	# r3 = s2
I 6
	subb3	(r3),(r1),r0	# quick check for first char different
	beql	1f		# have to keep checking
	cvtbl	r0,r0
	ret
E 6
E 3
1:
D 3
	locc	$0,$65535,(r4)	# look for '\0' in s2
E 3
I 3
D 5
	cmpc3	$32,(r1),(r3)	# compare strings
E 3
	bneq	2f
D 3
	cmpc3	$65535,(r4),(r3)# compare full block
	bneq	3f
	movl	r1,r4		# advance s2
	jbr	1b		# matched, next block
E 3
I 3
	locc	$0,$32,-32(r1)	# check if contain null
	beql	1b
D 4
	mnegb	-32(r0)[r3],r0	# r0 = $0 - *s2
E 4
I 4
	subl2	r0,r3		# back up r3 to same point
E 5
I 5
	clrl	r5		# calculate min bytes to next page boundry
	subb3	r1,$255,r5	# r5 = (bytes - 1) to end of page for s1
	subb3	r3,$255,r0	# r0 = (bytes - 1) to end of page for s2
	cmpb	r0,r5		# r5 = min(r0, r5);
	bgtru	2f
	movb	r0,r5
2:
	incl	r5		# r5 = min bytes to next page boundry
	cmpc3	r5,(r1),(r3)	# compare strings
	bneq	3f
	subl2	r5,r1		# check if found null yet
	locc	$0,r5,(r1)
	beql	1b		# not yet done, continue checking
	subl2	r0,r3
E 5
	mnegb	(r3),r0		# r0 = '\0' - *s2
E 4
	cvtbl	r0,r0
	ret
E 3
D 5
2:
D 3
	subl2	r4,r1		# calculate length
	incl	r1		# +1 for '\0'
	cmpc3	r1,(r4),(r3)	# compare remainder
E 3
I 3
	subl3	r0,$32,r0	# check for null in matching string
	subl2	r0,r1
	locc	$0,r0,(r1)
E 3
	bneq	3f
E 5
I 5
3:
	subl2	r0,r5		# check for null in matching string
	subl2	r5,r1
	locc	$0,r5,(r1)
	bneq	4f
E 5
D 3
	ret			# r0 = 0 already
3:
	subb3	(r1),(r3),r0	# r0 = *s1 - *s2
E 3
I 3
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
3:
E 5
I 5
4:
E 5
	clrl	r0		# both the same to null
E 3
	ret
E 1
