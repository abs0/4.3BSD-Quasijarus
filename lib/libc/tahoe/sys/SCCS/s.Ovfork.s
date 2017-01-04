h07560
s 00011/00006/00048
d D 5.3 88/06/27 18:39:49 bostic 3 2
c install approved copyright notice
e
s 00010/00004/00044
d D 5.2 88/05/20 15:53:01 bostic 2 1
c add Berkeley specific header
e
s 00048/00000/00000
d D 5.1 86/07/02 16:22:59 sam 1 0
c date and time created 86/07/02 16:22:59 by sam
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
 * software without specific written prior permission. This software
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

D 2
#ifdef SYSLIBC_SCCS
E 2
I 2
#if defined(SYSLIBC_SCCS) && !defined(lint)
E 2
D 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 3
I 3
	.asciz "%W% (Berkeley) %G%"
E 3
D 2
#endif SYSLIBC_SCCS
E 2
I 2
#endif /* SYSLIBC_SCCS and not lint */
E 2

/*
 * C library -- vfork
 * pid = vfork();
 *
 * r1 == 0 in parent process, r1 == 1 in child process.
 * r0 == pid of child in parent, r0 == pid of parent in child.
 *
 * trickery here, due to keith sklower, uses ret to clear the stack,
 * and then returns with a jump indirect, since only one person can return
 * with a ret off this stack... we do the ret before we vfork!
 * 
 */

	.set	vfork,66
.globl	_vfork

_vfork:
	.word	0x0000
	movl	-8(fp),r2
	movab	here,-8(fp)
	ret
here:
	kcall	$vfork
	bcc	vforkok
	jmp	verror
vforkok:
	tstl	r1		# child process ?
	bneq	child	# yes
	jbr 	parent
.globl	_errno
verror:
	movl	r0,_errno
	mnegl	$1,r0
	jmp	(r2)
child:
	clrl	r0
parent:
	jmp	(r2)
E 1
