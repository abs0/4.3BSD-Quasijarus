h32724
s 00013/00008/00055
d D 1.4 88/06/27 17:47:19 bostic 4 3
c install approved copyright notice
e
s 00018/00003/00045
d D 1.3 88/05/23 21:33:54 bostic 3 2
c add Berkeley/CCI specific header; fix sccsid
e
s 00025/00004/00023
d D 1.2 87/12/11 19:05:24 donn 2 1
c Add audiv() routine similar to vax's.
e
s 00027/00000/00000
d D 1.1 86/08/01 08:49:41 sam 1 0
c date and time created 86/08/01 08:49:41 by sam
e
u
U
t
T
I 1
D 3
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley/CCI) %G%"
#endif LIBC_SCCS
E 3
I 3
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
I 4
 * Redistribution and use in source and binary forms are permitted
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
 *
E 4
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
D 4
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
 */

#if defined(LIBC_SCCS) && !defined(lint)
D 4
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 4
I 4
	.asciz "%W% (Berkeley) %G%"
E 4
#endif /* LIBC_SCCS and not lint */
E 3

/*
 * Unsigned divide.
 *
 * udiv(dividend, divisor)
 */
#include "DEFS.h"

ASENTRY(udiv, 0)
	bitl	$0x80000000,8(fp)	#  if (divisor & 0x80000000){
	jeql	1f			  
	cmpl	8(fp),4(fp)		#  if (divisor > dividend )
	jlequ	2f
	clrl	r0			#      return(0);
	ret
2:					#  else
	movl	$1,r0			#      return(1);}
	ret
1:
D 2
	clrl	r0			#  return(dividend/divisor);
	movl	4(fp),r1
	ediv	8(fp),r0,r2,r3
	movl	r2,r0
E 2
I 2
	clrl	r2			#  return(dividend/divisor);
	movl	4(fp),r3
	ediv	8(fp),r2,r0,r1
	ret

/*
 * audiv(dividendp, divisor) -- like udiv but uses address of dividend.
 *	Implements /= avoiding side effects in the dividend expression.
 */
ASENTRY(audiv, 0)
	bitl	$0x80000000,8(fp)	#  if (divisor & 0x80000000){
	jeql	1f			  
	cmpl	8(fp),*4(fp)		#  if (divisor > dividend )
	jlequ	2f
	clrl	r0			#      return(0);
	jbr	3f
2:					#  else
	movl	$1,r0			#      return(1);}
	jbr	3f
1:
	clrl	r2			#  return(dividend/divisor);
	movl	*4(fp),r3
	ediv	8(fp),r2,r0,r1
3:
	movl	r0,*4(fp)
E 2
	ret
E 1
