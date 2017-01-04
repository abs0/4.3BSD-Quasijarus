h02340
s 00013/00008/00084
d D 5.5 88/06/27 17:25:16 bostic 8 7
c install approved copyright notice
e
s 00011/00005/00081
d D 5.4 88/05/25 17:13:55 bostic 7 6
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00084
d D 5.3 86/03/09 21:13:48 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00085
d D 5.2 85/06/05 18:59:47 mckusick 5 4
c Fix copyright
e
s 00009/00001/00077
d D 5.1 85/05/30 15:15:40 dist 4 3
c Add copyright
e
s 00040/00004/00038
d D 4.3 84/11/04 21:56:24 mckusick 3 2
c mods to make reentrant
e
s 00002/00003/00040
d D 4.2 84/11/01 23:51:59 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00043/00000/00000
d D 4.1 84/11/01 23:19:48 sam 1 0
c date and time created 84/11/01 23:19:48 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
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
E 7
 */

D 6
#ifndef lint
E 6
I 6
D 7
#ifdef LIBC_SCCS
E 6
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
	.asciz	"%W% (Berkeley) %G%"
E 5
D 6
#endif not lint
E 6
I 6
#endif LIBC_SCCS
E 7
I 7
D 8
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 8
I 8
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 8
E 7
E 6
E 4

/*
 * Find the last occurence of c in the string cp.
 * Return pointer to match or null pointer.
 *
 * char *
 * rindex(cp, c)
 *	char *cp, c;
 */
D 2
	.globl	_rindex
E 2
I 2
#include "DEFS.h"
E 2

D 2
_rindex:
	.word	0x0
E 2
I 2
ENTRY(rindex, 0)
E 2
	movq	4(ap),r1	# r1 = cp; r2 = c
	tstl	r2		# check for special case c == '\0'
	bneq	2f
1:
	locc	$0,$65535,(r1)	# just find end of string
	beql	1b		# still looking
	movl	r1,r0		# found it
	ret
2:
D 3
	movab	tbl[r2],r5	# table entry for c
E 3
I 3
	moval	tbl,r3		# r3 = address of table
	bbss	$0,(r3),5f	# insure not reentering
	movab	(r3)[r2],r5	# table entry for c
E 3
	incb	(r5)
	clrl	r4		# last found
3:
D 3
	scanc	$65535,(r1),tbl,$1	# look for c or '\0'
E 3
I 3
	scanc	$65535,(r1),(r3),$1	# look for c or '\0'
E 3
	beql	3b		# keep looking
	tstb	(r1)		# if have found '\0'
	beql	4f		#    we are done
	movl	r1,r4		# save most recently found
	incl	r1		# skip over character
	jbr	3b		# keep looking
4:
	movl	r4,r0		# return last found (if any)
	clrb	(r5)		# clean up table
I 3
	clrb	(r3)
E 3
	ret

	.data
D 3
tbl:	.byte	1
	.space	255
E 3
I 3
tbl:	.space	256
E 3
	.text
I 3

/*
 * Reentrant, but slower version of rindex
 */
5:
	movl	r1,r3
	clrl	r4		# r4 = pointer to last match
6:
	locc	$0,$65535,(r3)	# look for '\0'
	bneq	8f
	decw	r0		# r0 = 65535
1:
	locc	r2,r0,(r3)	# look for c
	bneq	7f
	movl	r1,r3		# reset pointer and ...
	jbr	6b		# ... try again
7:
	movl	r1,r4		# stash pointer ...
	addl3	$1,r1,r3	# ... skip over match and ...
	decl	r0		# ... decrement count
	jbr	6b		# ... try again
8:
	subl3	r3,r1,r0	# length of short block
	incl	r0		# +1 for '\0'
9:
	locc	r2,r0,(r3)	# look for c
	beql	0f
	movl	r1,r4		# stash pointer ...
	addl3	$1,r1,r3	# ... skip over match ...
	decl	r0		# ... adjust count and ...
	jbr	9b		# ... try again
0:
	movl	r4,r0		# return stashed pointer
	ret
E 3
E 1
