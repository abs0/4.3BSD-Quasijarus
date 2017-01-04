h24210
s 00013/00008/00053
d D 1.3 88/06/27 17:47:22 bostic 3 2
c install approved copyright notice
e
s 00018/00003/00043
d D 1.2 88/05/23 21:33:56 bostic 2 1
c add Berkeley/CCI specific header; fix sccsid
e
s 00046/00000/00000
d D 1.1 87/12/11 19:08:47 donn 1 0
c date and time created 87/12/11 19:08:47 by donn
e
u
U
t
T
I 1
D 2
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley/CCI) %G%"
#endif LIBC_SCCS
E 2
I 2
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
I 3
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
E 3
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
D 3
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
 */

#if defined(LIBC_SCCS) && !defined(lint)
D 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 3
I 3
	.asciz "%W% (Berkeley) %G%"
E 3
#endif /* LIBC_SCCS and not lint */
E 2

/*
 * Unsigned remainder.
 *
 * urem(dividend, divisor)
 */
#include "DEFS.h"

ASENTRY(urem, 0)
	bitl	$0x80000000,8(fp)	#  if (divisor & 0x80000000){
	jeql	1f			  
	movl	4(fp),r0
	cmpl	8(fp),r0		#  if (divisor <= dividend )
	jgtru	2f
	subl2	8(fp),r0		#       return(dividend-divisor);
2:					#  else return(dividend);}
	ret
1:
	clrl	r2			#  return(dividend%divisor);
	movl	4(fp),r3
	ediv	8(fp),r2,r1,r0
	ret

/*
 * aurem(dividendp, divisor) -- like urem but uses address of dividend.
 *	Implements %= avoiding side effects in the dividend expression.
 */
ASENTRY(aurem, 0)
	bitl	$0x80000000,8(fp)	#  if (divisor & 0x80000000){
	jeql	1f			  
	movl	*4(fp),r0
	cmpl	8(fp),r0		#  if (divisor <= dividend )
	jgtru	2f
	subl2	8(fp),r0		#       return(dividend-divisor);
					#  else return(dividend);}
	jbr	2f
1:
	clrl	r2			#  return(dividend%divisor);
	movl	*4(fp),r3
	ediv	8(fp),r2,r1,r0
2:
	movl	r0,*4(fp)
	ret
E 1
