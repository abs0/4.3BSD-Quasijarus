h14965
s 00013/00008/00055
d D 5.5 88/06/27 17:25:27 bostic 7 6
c install approved copyright notice
e
s 00011/00005/00052
d D 5.4 88/05/25 17:14:18 bostic 6 5
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00055
d D 5.3 86/03/09 21:15:25 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00056
d D 5.2 85/06/05 19:01:46 mckusick 4 3
c Fix copyright
e
s 00009/00001/00048
d D 5.1 85/05/30 15:18:24 dist 3 2
c Add copyright
e
s 00002/00003/00047
d D 4.2 84/11/01 23:52:29 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00050/00000/00000
d D 4.1 84/11/01 23:19:45 sam 1 0
c date and time created 84/11/01 23:19:45 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
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
E 6
 */

D 5
#ifndef lint
E 5
I 5
D 6
#ifdef LIBC_SCCS
E 5
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
	.asciz	"%W% (Berkeley) %G%"
E 4
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS
E 6
I 6
D 7
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 7
I 7
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 7
E 6
E 5
E 3

/*
 * Copy string s2 over top of string s1.
 * Truncate or null-pad to n bytes.
 *
 * char *
 * strncpy(s1, s2, n)
 *	char *s1, *s2;
 */
D 2
	.globl	_strncpy
E 2
I 2
#include "DEFS.h"
E 2

D 2
_strncpy:
	.word	0x40
E 2
I 2
ENTRY(strncpy, R6)
E 2
	movl	12(ap),r6	# r6 = n
	bleq	done		# n <= 0
	movl	4(ap),r3	# r3 = s1
	movl	8(ap),r1	# r1 = s2
1:
	movzwl	$65535,r2	# r2 = bytes in first chunk
	cmpl	r6,r2		# r2 = min(bytes in chunk, n);
	jgeq	2f
	movl	r6,r2
2:
	subl2	r2,r6		# update n
	locc	$0,r2,(r1)	# '\0' found?
	jneq	3f
	subl2	r2,r1		# back up pointer updated by locc
	movc3	r2,(r1),(r3)	# copy in next piece
	tstl	r6		# run out of space?
	jneq	1b
	jbr	done
3:				# copy up to '\0' logic
	addl2	r0,r6		# r6 = number of null-pad bytes
	subl2	r0,r2		# r2 = number of bytes to move
	subl2	r2,r1		# back up pointer updated by locc
	movc3	r2,(r1),(r3)	# copy in last piece
4:				# null-pad logic
	movzwl	$65535,r2	# r2 = bytes in first chunk
	cmpl	r6,r2		# r2 = min(bytes in chunk, n);
	jgeq	5f
	movl	r6,r2
5:
	subl2	r2,r6		# update n
	movc5	$0,(r3),$0,r2,(r3)# pad with '\0's
	tstl	r6		# finished padding?
	jneq	4b
done:
	movl	4(ap),r0	# return s1
	ret
E 1
