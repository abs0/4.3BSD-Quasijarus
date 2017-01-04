h05961
s 00001/00001/00210
d D 1.3 86/01/05 18:50:49 sam 3 2
c working (mostly)
e
s 00058/00108/00153
d D 1.2 86/01/03 23:46:49 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00261/00000/00000
d D 1.1 85/08/02 15:42:25 sam 1 0
c date and time created 85/08/02 15:42:25 by sam
e
u
U
t
T
I 1
D 2
/* file: Kexpf.x
 */
	.data
	.comm	_errno,4
	.align	2
_p0:	.long	0x45BD3D04, 0x7F734DBD # .double 1513.9067990543389
	.align	2
_p1:	.long	0x42A19DD4, 0x989F60DA # .double 20.202065651286927
	.align	2
_p2:	.long	0x3DBD2E42, 0xAB70BDA9 # .double .023093347753750233
	.align	2
_q0:	.long	0x468881B1, 0x7C3A6529 # .double 4368.2116627275583
	.align	2
_q1:	.long	0x44692F28, 0x7AE89541 # .double 233.18421142748162
	.align	2
_q2:	.long	0x40800000, 0x00000000 # .double 1
	.align	2
_log2e:	.long	0x40B8AA3B, 0x295C17F0 # .double 1.4426950408889634
	.align	2
_sqrt2:	.long	0x40B504F3, 0x33F9DE64 # .double 1.414213562373095
	.align	2
_maxf:	.long	0x471C4000, 0x00000000 # .double 10000
	.align	2
_HUGE:	.long	0x7FFFFFFE, 0xFFFFFFFC # .double 1.701411733192644e+38
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
	.globl	_Kexpf
	.data
	.align	2
L28:	.long	0x40800000 # .float 1
	.text
	.data
	.align	2
L32:	.long	0x40000000, 0x00000000 # .double .5
	.text
	.set	L23,0xC
	.data
	.text
_Kexpf:.word	L23
E 2
I 2
ENTRY(Kexpf, R4|R3)
E 2
	subl3	$88,fp,sp
	tstl	4(fp)
D 2
	jneq	L27
	movl	L28,r0
E 2
I 2
	jneq	1f
	movl	one,r0
E 2
	ret
D 2
L27:	lnd	_maxf
E 2
I 2
1:
	lnd	_maxf
E 2
	cmpd	4(fp)
D 2
	jleq	L29
E 2
I 2
	jleq	1f
E 2
	clrl	r0
	ret
D 2
L29:	cmpd2	4(fp),_maxf
	jleq	L30
	movl	$34,_errno
E 2
I 2
1:
	cmpd2	4(fp),_maxf
	jleq	1f
E 2
	ldd	_HUGE
	cvdf
	stf	r0
	ret
D 2
L30:	
E 2
I 2
1:	
E 2
	pushl	20(fp)		# hfs
D 2
	ldd	_log2e
	pushd
	ldd	4(fp)
	pushd
E 2
I 2
	ldd	_log2e; pushd
	ldd	4(fp); pushd
E 2
	callf	$24,_Kmuld
	ldd	r0
	std	4(fp)

	pushl	20(fp)		# hfs
	pushl	8(fp)
	pushl	4(fp)
	callf	$16,_Kfloorf
	movl	r0,-88(fp)	# (int)ent from Kfloorf

	cvlf	-88(fp)
	clrl	r1
	stf	r0
	pushl	20(fp)		# hfs
	pushl	r1
	pushl	r0
D 2
	ldd	4(fp)
	pushd
E 2
I 2
	ldd	4(fp); pushd
E 2
	callf	$24,_Ksubd	# (arg - ent)

	pushl	20(fp)		# hfs
D 2
	ldd	L32
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	half; pushd
	ldd	r0; pushd
E 2
	callf	$24,_Ksubd
D 2
	ldd	r0
	std	-60(fp)		# fract
E 2
I 2
	ldd	r0; std	-60(fp)	# fract
E 2

	pushl	20(fp)		# hfs
	pushd
	pushd
	callf	$24,_Kmuld
D 2
	ldd	r0
	std	-84(fp)		# xsq
E 2
I 2
	ldd	r0; std	-84(fp)	# xsq
E 2

	pushl	20(fp)		# hfs
	pushd			# xsq
D 2
	ldd	_p2
	pushd
E 2
I 2
	ldd	_p2; pushd
E 2
	callf	$24,_Kmuld

	pushl	20(fp)		# hfs
D 2
	ldd	_p1
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	_p1; pushd
	ldd	r0; pushd
E 2
	callf	$24,_Kaddd

	pushl	20(fp)		# hfs
D 2
	ldd	-84(fp)
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	-84(fp); pushd
	ldd	r0; pushd
E 2
	callf	$24,_Kmuld

	pushl	20(fp)		# hfs
D 2
	ldd	_p0
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	_p0; pushd
	ldd	r0; pushd
E 2
	callf	$24,_Kaddd

	pushl	20(fp)		# hfs
D 2
	ldd	-60(fp)		# fract
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	-60(fp); pushd	# fract
	ldd	r0; pushd
E 2
	callf	$24,_Kmuld
D 2
	ldd	r0
	std	-68(fp)		# temp1
E 2
I 2
	ldd	r0; std	-68(fp)	# temp1
E 2

	pushl	20(fp)		# hfs
D 2
	ldd	-84(fp)		# xsq
	pushd
	ldd	_q2
	pushd
E 2
I 2
	ldd	-84(fp); pushd	# xsq
	ldd	_q2; pushd
E 2
	callf	$24,_Kmuld

	pushl	20(fp)		# hfs
D 2
	ldd	_q1
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	_q1; pushd
	ldd	r0; pushd
E 2
	callf	$24,_Kaddd

	pushl	20(fp)		# hfs
D 2
	ldd	-84(fp)
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	-84(fp); pushd
	ldd	r0; pushd
E 2
	callf	$24,_Kmuld

	pushl	20(fp)		# hfs
D 2
	ldd	_q0
	pushd
	ldd	r0
	pushd
E 2
I 2
	ldd	_q0; pushd
	ldd	r0; pushd
E 2
	callf	$24,_Kaddd
D 2
	ldd	r0
	std	-76(fp)		# temp2
E 2
I 2
	ldd	r0; std	-76(fp)	# temp2
E 2

	pushl	20(fp)		# hfs for Kldexpf
	pushl	-88(fp)		# ent

	pushl	20(fp)		# hfs tor temp2+temp1
D 2
	ldd	-68(fp)		# temp1
	pushd
	ldd	-76(fp)		# temp2
	pushd
E 2
I 2
	ldd	-68(fp); pushd	# temp1
	ldd	-76(fp); pushd	# temp2
E 2
	callf	$24,_Kaddd

	pushl	20(fp)		# hfs
D 2
	ldd	_sqrt2
	pushd
	ldd	r0		# temp2+temp1
	pushd
E 2
I 2
	ldd	_sqrt2; pushd
	ldd	r0; pushd	# temp2+temp1
E 2
	callf	$24,_Kmuld
D 2
	ldd	r0
	std	r2		# sqrt2*(temp2+temp1)
E 2
I 2
	ldd	r0; std	r2		# sqrt2*(temp2+temp1)
E 2

	pushl	20(fp)		# hfs
	ldd	-68(fp)
	pushd
	ldd	-76(fp)
	pushd
	callf	$24,_Ksubd	# temp2-temp1

	pushl	20(fp)		# hfs
	ldd	r0
	pushd			# temp2-temp1
	ldd	r2
	pushd
	callf	$24,_Kdivd

	ldd	r0
	pushd
	callf	$20,_Kldexpf

	#pushl	20(fp)		# hfs
	#pushl	$0
	#pushl	r0		# cvlf	r0
	#pushl	$0
	#pushl	$0
	#callf	$24,_Kcvtld

	#ldd	r0
	#cvdf
	#stf	r0
	ret

/* file : Kfloorf.x
*/
	.text
	.globl	_Kfloorf
	.data
	.align	2
L19:	.long	0x40800000, 0x00000000 # .double 1
	.text
	.set	L13,0x0
	.data
	.text
_Kfloorf:
	.word	L13
	subl3	$60,fp,sp
	tstl	4(fp)		# if (d<0.0) {
	jgeq	L17
	lnd	4(fp)
	std	4(fp)		# d = -d;
	pushl	12(fp)		# hfs
	addl3	$4,fp,-(sp)	# &d
	pushl	8(fp)
	pushl	4(fp)
	callf	$20,_Kmodf
	clrl	-60+4(fp)
	movl	r0,-60(fp)	# fract = modf(d,&d);
	tstl	r0		# if (fract != 0.0)
	jeql	L18
	pushl	12(fp)		# hfs
	ldd	L19
	pushd
	ldd	4(fp)
	pushd
	callf	$24,_Kaddd
	ldd	r0
	std	4(fp)		# d +=1;
L18:	lnd	4(fp)
	std	4(fp)		# d = -d;
	jbr	L20
L17:	
	pushl	12(fp)		# hfs
	addl3	$4,fp,-(sp)
	pushl	8(fp)
	pushl	4(fp)
	callf	$20,_Kmodf
L20:	ldd	4(fp)
	cvdl	r0		# for Kexpf call only!
	ret
	
I 2
	.data
_p0:	.long	0x45BD3D04, 0x7F734DBD # .double 1513.9067990543389
_p1:	.long	0x42A19DD4, 0x989F60DA # .double 20.202065651286927
_p2:	.long	0x3DBD2E42, 0xAB70BDA9 # .double .023093347753750233
_q0:	.long	0x468881B1, 0x7C3A6529 # .double 4368.2116627275583
_q1:	.long	0x44692F28, 0x7AE89541 # .double 233.18421142748162
_q2:	.long	0x40800000, 0x00000000 # .double 1
_log2e:	.long	0x40B8AA3B, 0x295C17F0 # .double 1.4426950408889634
_sqrt2:	.long	0x40B504F3, 0x33F9DE64 # .double 1.414213562373095
_maxf:	.long	0x471C4000, 0x00000000 # .double 10000
_HUGE:	.long	0x7FFFFFFE, 0xFFFFFFFC # .double 1.701411733192644e+38
one:	.long	0x40800000 # .float 1
half:	.long	0x40000000, 0x00000000 # .double .5
E 2
E 1
