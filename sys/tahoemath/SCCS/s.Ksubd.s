h07875
s 00001/00001/00034
d D 1.3 86/01/05 18:51:11 sam 3 2
c working (mostly)
e
s 00013/00017/00022
d D 1.2 86/01/03 23:47:15 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00039/00000/00000
d D 1.1 85/08/02 15:42:32 sam 1 0
c date and time created 85/08/02 15:42:32 by sam
e
u
U
t
T
I 1
D 2
	.data
E 2
I 2
/*	%M%	%I%	%E%	*/

D 3
#include "SYS.h"
E 3
I 3
#include "../tahoe/SYS.h"
E 3

/*
 * double 
 * Ksubd(d1,d2)
 * double d1,d2;
 * {
 * 	return(d1+(-d2));
 * }
 */
E 2
	.text
D 2
LL0:	.align	1
	.globl	_Ksubd
	.set	L12,0x0
	.data
	.text
_Ksubd:	.word	L12	# _Ksubd(acc_most,acc_least,op_most,op_least,hfs)
E 2
I 2
ENTRY(Ksubd, 0)
E 2
	tstl	4(fp)
	jneq	next
	movl	16(fp),r1
	movl	12(fp),r0
	lnd	r0
	std	r0
	ret
next:
	tstl	12(fp)
	jneq	doit
	movl	8(fp),r1
	movl	4(fp),r0
	ret
doit:
	lnd	12(fp)		# -op
	pushl	20(fp)		# hfs
	pushd			# push op_least op_most
	pushl	8(fp)
	pushl	4(fp)		# acc
	callf	$24,_Kaddd
	ret
D 2


/*
 * double 
 * subd(d1,d2)
 * double d1,d2;
 * {
 * 	return(d1+(-d2));
 * }
*/
E 2
E 1
