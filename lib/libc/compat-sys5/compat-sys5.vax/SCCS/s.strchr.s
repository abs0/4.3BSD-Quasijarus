h28415
s 00013/00008/00074
d D 5.2 88/06/27 18:16:35 bostic 2 1
c install approved copyright notice
e
s 00082/00000/00000
d D 5.1 88/06/03 18:56:30 bostic 1 0
c date and time created 88/06/03 18:56:30 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 2
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 2
I 2
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
E 2
 */

D 2
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 2
I 2
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 2

#ifdef notdef
_sccsid:.asciz	"@(#)index.s	5.4 (Berkeley) 5/25/88"
#endif

/*
 * Find the first occurence of c in the string cp.
 * Return pointer to match or null pointer.
 *
 * char *
 * index(cp, c)
 *	char *cp, c;
 */
#include "DEFS.h"

ENTRY(strchr, 0)
	movq	4(ap),r1	# r1 = cp; r2 = c
	tstl	r2		# check for special case c == '\0'
	bneq	2f
1:
	locc	$0,$65535,(r1)	# just find end of string
	beql	1b		# still looking
	movl	r1,r0		# found it
	ret
2:
	moval	tbl,r3		# r3 = address of table
	bbss	$0,(r3),5f	# insure not reentering
	movab	(r3)[r2],r5	# table entry for c
	incb	(r5)
	movzwl	$65535,r4	# fast access
3:
	scanc	r4,(r1),(r3),$1	# look for c or '\0'
	beql	3b		# still looking
	movl	r1,r0		# return pointer to char
	tstb	(r0)		#    if have found '\0'
	bneq	4f
	clrl	r0		# else return 0
4:
	clrb	(r5)		# clean up table
	clrb	(r3)
	ret

	.data
tbl:	.space	256
	.text

/*
 * Reentrant, but slower version of index
 */
5:
	movl	r1,r3
6:
	locc	$0,$65535,(r3)	# look for '\0'
	bneq	7f
	locc	r2,$65535,(r3)	# look for c
	bneq	8f
	movl	r1,r3		# reset pointer and ...
	jbr	6b		# ... try again
7:
	subl3	r3,r1,r4	# length of short block
	incl	r4		# +1 for '\0'
	locc	r2,r4,(r3)	# look for c
	bneq	8f
	ret
8:
	movl	r1,r0		# return pointer to char
	ret
E 1
