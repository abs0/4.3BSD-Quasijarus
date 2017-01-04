h47664
s 00004/00001/00024
d D 7.1 88/05/21 18:36:37 karels 2 1
c bring up to revision 7 for tahoe release
e
s 00025/00000/00000
d D 1.1 86/01/05 18:46:24 sam 1 0
c date and time created 86/01/05 18:46:24 by sam
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
 *	%W% (Berkeley) %G%
 */
E 2

#include "../tahoe/SYS.h"
I 2

E 2
/*
 * result = udiv(dividend, divisor)
 *
 * unsigned long division
 */
	.text
ASENTRY(udiv, R2|R3)
	bitl	$0x80000000,8(fp)	# if (divisor & 0x80000000) {
	jeql	2f			  
	cmpl	8(fp),4(fp)		# if (divisor > dividend)
	jlequ	1f
	clrl	r0			#	return (0);
	ret
1:					# else
	movl	$1,r0			#  	return (1);
	ret				# }
2:
	clrl	r0			# return (dividend / divisor);
	movl	4(fp),r1
	ediv	8(fp),r0,r2,r3
	movl	r2,r0
	ret
E 1
