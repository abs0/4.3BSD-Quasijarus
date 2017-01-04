h34022
s 00001/00001/00161
d D 1.3 86/01/05 18:50:58 sam 3 2
c working (mostly)
e
s 00026/00053/00136
d D 1.2 86/01/03 23:47:00 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00189/00000/00000
d D 1.1 85/08/02 15:42:28 sam 1 0
c date and time created 85/08/02 15:42:28 by sam
e
u
U
t
T
I 1
D 2
	.data
	.comm	_errno,4
	.align	2
_log2:	.long	0x40317217, 0xf7d1cf7a # .double 0.69314718055994531
	.align	2
_ln10:	.long	0x41135d8d, 0xddaaa8ac # .double 2.3025850929940457
	.align	2
_sqrto2:
	.long	0x403504f3, 0x33f9de65 # .double 0.70710678118654753
	.align	2
_p0:	.long	0xc154114d, 0xeb0ba468 # .double -3.31355617479
	.align	2
_p1:	.long	0x40654226, 0x56bd0c4c # .double 0.89554061525
	.align	2
_q0:	.long	0xc0d4114c, 0xfdc7df02 # .double -1.65677797691
	.align	2
_q1:	.long	0x40800000, 0x00000000 # .double 1
E 2
I 2
/*	%M%	%I%	%E%	*/

D 3
#include "SYS.h"
E 3
I 3
#include "../tahoe/SYS.h"
E 3

E 2
	.text
D 2
LL0:	.align	1
	.globl	_Klogf
	.data
	.align	2
L54:	.long	0xfffffffe, 0xfffffffe # .double -1.7014117331926443e+38
	.text
	.data
	.align	2
L57:	.long	0x40000000, 0x00000000 # .double 0.5
	.text
	.data
	.align	2
L58:	.long	0x41000000, 0x00000000 # .double 2
	.text
	.data
	.align	2
L60:	.long	0x41000000, 0x00000000 # .double 2
	.text
	.data
	.align	2
L61:	.long	0x40800000, 0x00000000 # .double 1
	.align	2
L62:	.long	0x40800000, 0x00000000 # .double 1
	.text
	.set	L49,0x3c		# Using registers 2,3,4,5
	.data
	.text
_Klogf:	.word	L49
E 2
I 2
ENTRY(Klogf, R5|R4|R3|R2)
E 2
	subl3	$88,fp,sp
	clrl	8(fp)
	tstl	4(fp)
	jgtr	L53
D 2
	movl	$33,_errno
	movl	L54+4,r1
	movl	L54,r0
E 2
I 2
	movl	small+4,r1
	movl	small,r0
E 2
	ret
L53:	pushl	20(fp)			# hfs
	subl3	$88,fp,-(sp)		# &exp
	pushl	8(fp)			# arg
	pushl	4(fp)
	callf	$20,_Kfrexpf
	ldd	r0
					# movl	r1,-56(fp)
	std	-60(fp)			# movl	r0,-60(fp)
	jbr	L55
L2000001:
	pushl	20(fp)			# hfs
D 2
	ldd	L58			# 2.0
E 2
I 2
	ldd	two			# 2.0
E 2
	pushd
	ldd	-60(fp)			# x
	pushd	
	callf	$24,_Kmuld
	ldd	r0
	std	-60(fp)
	subl2	$1,-88(fp)
D 2
L55:	cmpd2	-60(fp),L57
E 2
I 2
L55:	cmpd2	-60(fp),half
E 2
	jlss	L2000001
	cmpd2	-60(fp),_sqrto2
	jgeq	L59
	pushl	20(fp)			# hfs
	ldd	-60(fp)			# x
	pushd
D 2
	ldd	L60			# 2.0
E 2
I 2
	ldd	two			# 2.0
E 2
	pushd
	callf	$24,_Kmuld
	ldd	r0
	std	-60(fp)
	subl2	$1,-88(fp)
L59:	pushl	20(fp)			# hfs
D 2
	ldd	L61			# 1.0
E 2
I 2
	ldd	one			# 1.0
E 2
	pushd
	ldd	-60(fp)			# x
	pushd
	callf	$24,_Ksubd	
	ldd	r0
	std	r2
	pushl	20(fp)			# hfs
D 2
	ldd	L62			# 1.0
E 2
I 2
	ldd	one			# 1.0
E 2
	pushd
	ldd	-60(fp)			# x
	pushd
	callf	$24,_Kaddd
	ldd	r0
	std	r4
	pushl	20(fp)			# hfs
	ldd	r4			# temp result of x-1
	pushd
	ldd	r2			# temp result of x+1
	pushd
	callf	$24,_Kdivd
	ldd	r0
	std	-68(fp)			# z
	pushl	20(fp)			# hfs
	pushd				# z
	pushd				# z
	callf	$24,_Kmuld
	ldd	r0
	std	-76(fp)			# zsq
	pushl	20(fp)			# hfs
	ldd	-76(fp)			# zsq
	pushd
	ldd	_p1			# p1
	pushd
	callf	$24,_Kmuld
	ldd	r0
	std	r2
	pushl	20(fp)			# hfs
	ldd 	_p0			# p0
	pushd
	ldd	r2
	pushd
	callf	$24,_Kaddd
	ldd	r0
	std	-84(fp)			# temp
	pushl	20(fp)			# hfs
	ldd	-76(fp)			# zsq
	pushd
	ldd	_q1
	pushd
	callf	$24,_Kmuld
	ldd	r0
	std	r2
	pushl	20(fp)			# hfs
	ldd	_q0			# q0
	pushd
	ldd	r2
	pushd
	callf	$24,_Kaddd
	ldd	r0
	std	r2			# temp result of (q1*zsq+q0)
	pushl	20(fp)			# hfs
	ldd	r2
	pushd
	ldd	-84(fp)			# temp
	pushd
	callf	$24,_Kdivd
	ldd	r0
	std	-84(fp)			# put in temp
	pushl	20(fp)			# hfs
	ldd	-68(fp)			# z
	pushd
	ldd	-84(fp)
	pushd
	callf	$24,_Kmuld
	ldd	r0
	std	r2
	pushl	20(fp)			#hfs
	pushl	$0			# 0 pad
	pushl	-88(fp)			# exp
	pushl	$0			# dummy
	pushl	$0			# dummy
	callf	$24,_Kcvtld
	pushl	20(fp)			# hfs
	ldd	_log2			# log2
	pushd
	pushl	r1			# exp converted
	pushl	r0			
	callf	$24,_Kmuld
	ldd	r0
	std	r4
	pushl	20(fp)			# hfs
	ldd	r2			# result of temp*z
	pushd
	ldd	r4
	pushd
	callf	$24,_Kaddd
	ldd	r0
	cvdf
	stf	r0
	clrl	r1
	ret
I 2

	.data
	.align	2
_log2:	.long	0x40317217, 0xf7d1cf7a # .double 0.69314718055994531
_ln10:	.long	0x41135d8d, 0xddaaa8ac # .double 2.3025850929940457
_sqrto2:.long	0x403504f3, 0x33f9de65 # .double 0.70710678118654753
_p0:	.long	0xc154114d, 0xeb0ba468 # .double -3.31355617479
_p1:	.long	0x40654226, 0x56bd0c4c # .double 0.89554061525
_q0:	.long	0xc0d4114c, 0xfdc7df02 # .double -1.65677797691
_q1:	.long	0x40800000, 0x00000000 # .double 1
small:	.long	0xfffffffe, 0xfffffffe # .double -1.7014117331926443e+38
half:	.long	0x40000000, 0x00000000 # .double 0.5
two:	.long	0x41000000, 0x00000000 # .double 2
one:	.long	0x40800000, 0x00000000 # .double 1
E 2
E 1
