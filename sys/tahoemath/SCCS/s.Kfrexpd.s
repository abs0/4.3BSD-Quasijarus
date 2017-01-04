h10681
s 00001/00001/00057
d D 1.3 86/01/05 18:50:55 sam 3 2
c working (mostly)
e
s 00033/00053/00025
d D 1.2 86/01/03 23:46:56 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00078/00000/00000
d D 1.1 85/08/02 15:42:26 sam 1 0
c date and time created 85/08/02 15:42:26 by sam
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

E 2
	.text
D 2
LL0:	.align	1
	.globl	_Kfrexpd
	.data
	.align	2
L18:	.long	0x40800000, 0x00000000 # .double 1
	.text
	.data
	.align	2
L21:	.long	0x40800000, 0x00000000 # .double 1
	.text
	.data
	.align	2
L22:	.long	0x41000000, 0x00000000 # .double 2
	.text
	.data
	.align	2
L25:	.long	0x40000000, 0x00000000 # .double 0.5
	.text
	.data
	.align	2
L28:	.long	0x40000000, 0x00000000 # .double 0.5
	.text
	.data
	.align	2
L29:	.long	0x41000000, 0x00000000 # .double 2
	.text
	.set	L12,0x0
	.data
	.text
_Kfrexpd:
	.word	L12
E 2
I 2
ENTRY(Kfrexpd, 0)
E 2
	subl3	$60,fp,sp
	clrl	-60(fp)
	clrl	-56(fp)
	tstl	4(fp)
D 2
	jgeq	L16
E 2
I 2
	jgeq	1f
E 2
	lnd	4(fp)
	std	4(fp)
	movl	$1,-56(fp)
D 2
L16:	cmpd2	4(fp),L18
	jleq	L17
L19:	cmpd2	4(fp),L21
	jleq	L23
E 2
I 2
1:
	cmpd2	4(fp),one
	jleq	1f
2:
	cmpd2	4(fp),one
	jleq	3f
E 2
	addl2	$1,-60(fp)
	pushl	16(fp)		# hfs
D 2
	pushl	L22+4		# ldd	L22		# 2.0
	pushl	L22
E 2
I 2
	pushl	two+4		# ldd	2.0
	pushl	two
E 2
	pushl	8(fp)
	pushl	4(fp)		# acc
	callf	$24,_Kdivd
	ldd	r0
	std	4(fp)
D 2
	jbr	L19
L17:	cmpd2	4(fp),L25
	jlss	L26
	jbr	L23
L2000001:
E 2
I 2
	jbr	2b
1:	cmpd2	4(fp),half
	jlss	2f
	jbr	3f
0:
E 2
	subl2	$1,-60(fp)
	pushl	16(fp)		# hfs
D 2
	ldd	L22		# 2.0
	pushd
	ldd	4(fp)		# acc
	pushd
E 2
I 2
	ldd	two; pushd	# 2.0
	ldd	4(fp); pushd	# acc
E 2
	callf	$24,_Kmuld
	ldd	r0
	std	4(fp)
D 2
L26:	cmpd2	4(fp),L28
	jlss	L2000001
L23:	movl	-60(fp),*12(fp)
E 2
I 2
2:
	cmpd2	4(fp),half
	jlss	0b
3:	movl	-60(fp),*12(fp)
E 2
	tstl	-56(fp)
D 2
	jeql	L30
E 2
I 2
	jeql	1f
E 2
	lnd	4(fp)
	std	4(fp)
D 2
L30:	movl	8(fp),r1
E 2
I 2
1:
	movl	8(fp),r1
E 2
	movl	4(fp),r0
	ret
I 2
	.data
	.align 2
one:	.long	0x40800000, 0x00000000 # .double 1
two:	.long	0x41000000, 0x00000000 # .double 2
half:	.long	0x40000000, 0x00000000 # .double 0.5
E 2
E 1
