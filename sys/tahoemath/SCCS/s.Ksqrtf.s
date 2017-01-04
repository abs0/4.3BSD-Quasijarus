h59756
s 00001/00001/00153
d D 1.3 86/01/05 18:51:10 sam 3 2
c working (mostly)
e
s 00020/00049/00134
d D 1.2 86/01/03 23:47:13 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00183/00000/00000
d D 1.1 85/08/02 15:42:31 sam 1 0
c date and time created 85/08/02 15:42:31 by sam
e
u
U
t
T
I 1
D 2
/* file: Ksqrtf.x
*/
	.data
	.comm	_errno,4
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
	.globl	_Ksqrtf
	.data
	.align	2
L22:	.long	0x40000000, 0x00000000 # .double .5
	.text
	.data
	.align	2
L23:	.long	0x41000000, 0x00000000 # .double 2
	.text
	.data
	.align	2
L25:	.long	0x41000000, 0x00000000 # .double 2
	.text
	.data
	.align	2
L26:	.long	0x40000000, 0x00000000 # .double .5
	.align	2
L27:	.long	0x40800000, 0x00000000 # .double 1
	.text
	.data
	.align	2
L30:	.long	0x4F800000, 0x00000000 # .double 1073741824
	.text
	.data
	.align	2
L33:	.long	0x4F800000, 0x00000000 # .double 1073741824
	.text
	.data
	.align	2
L39:	.long	0x40000000, 0x00000000 # .double .5
	.text
	.set	L14,0x0
	.data
	.text
_Ksqrtf:	.word	L14
E 2
I 2
ENTRY(Ksqrtf, 0)
E 2
	subl3	$76,fp,sp
	tstl	4(fp)			# if (arg <= 0.) {
	jgtr	L18
	jgeq	L19			# if (arg < 0.)
D 2
	movl	$33,_errno		# errno = EDOM;
E 2
L19:	clrl	r1
	clrl	r0
	ret				# return(0.);}
L18:	
	pushl	20(fp)			# hfs
	subl3	$72,fp,-(sp)
	pushl	8(fp)
	pushl	4(fp)
	callf	$20,_Kfrexpf
	clrl	-60+4(fp)
	movl	r0,-60(fp)		# x = frexp(arg,&exp);
	jbr	L20
L2000001:
	pushl	20(fp)			# hfs
D 2
	ldd	L23
E 2
I 2
	ldd	two
E 2
	pushd
	ldd	-60(fp)
	pushd
	callf	$24,_Kmuld		# x * 2
	ldd	r0
	std	-60(fp)			# x *= 2;
	decl	-72(fp)			# exp--;}
D 2
L20:	cmpd2	-60(fp),L22		# while(x < 0.5){
E 2
I 2
L20:	cmpd2	-60(fp),half		# while(x < 0.5){
E 2
	jlss	L2000001
	bitl	$1,-72(fp)		# if(exp & 1) {
	jeql	L24
	pushl	20(fp)			# hfs
D 2
	ldd	L25
E 2
I 2
	ldd	two
E 2
	pushd
	ldd	-60(fp)
	pushd
	callf	$24,_Kmuld		# x * 2
	ldd	r0
	std	-60(fp)			# x *= 2;
	decl	-72(fp)			# exp--;}
L24:	pushl	20(fp)			# hfs
	ldd	-60(fp)
	pushd
D 2
	ldd	L27
E 2
I 2
	ldd	one
E 2
	pushd
	callf	$24,_Kaddd		# (1.0+x)
	pushl	20(fp)			# hfs
	ldd	r0
	pushd
D 2
	ldd	L26
E 2
I 2
	ldd	half
E 2
	pushd
	callf	$24,_Kmuld
	ldd	r0
	std	-68(fp)			 # temp=0.5*(1.0+x);
	jbr	L28
L2000003:
	pushl	20(fp)			# hfs
D 2
	ldd	L30
E 2
I 2
	ldd	big
E 2
	pushd
	ldd	-68(fp)
	pushd
	callf	$24,_Kmuld		# temp*(1L<<30)
	ldd	r0
	std	-68(fp)			# temp *=(1L<<30);
	subl2	$60,-72(fp)		# exp -= 60;}
L28:	cmpl	-72(fp),$60		# while(exp > 60){
	jleq	L31
	jbr	L2000003
L2000005:
	pushl	20(fp)			# hfs
D 2
	ldd	L33
E 2
I 2
	ldd	big
E 2
	pushd
	ldd	-68(fp)
	pushd
	callf	$24,_Kdivd
	ldd	r0
	std	-68(fp)			# temp /= (1L<<30);
	addl2	$60,-72(fp)		# exp +=60;}
L31:	cmpl	-72(fp),$-60		# while(exp < -60) {
	jlss	L2000005
	tstl	-72(fp)			# if(exp >=0)
	jlss	L34
	divl3	$2,-72(fp),r0
	shll	r0,$1,r0
	pushl	20(fp)			# hfs
	pushl	$0
	pushl	r0
	pushl	$0
	pushl	$0
	callf	$24,_Kcvtld
	pushl	20(fp)			# hfs
	ldd	r0
	pushd
	ldd	-68(fp)
	pushd
	callf	$24,_Kmuld		# temp * (1L <<(exp/2))
	jbr	L2000006		# temp *= 1L << (exp/2));
L34:	mnegl	-72(fp),r0		# -exp
	divl2	$2,r0			# -exp/2
	shll	r0,$1,r0
	pushl	20(fp)			# hfs
	pushl	$0
	pushl	r0
	pushl	$0
	pushl	$0
	callf	$24,_Kcvtld
	pushl	20(fp)			# hfs
	ldd	r0
	pushd
	ldd	-68(fp)
	pushd
	callf	$24,_Kdivd		# temp / (1L <<(-exp/2))
L2000006:
	ldd	r0
	std	-68(fp)			# temp (*/)= 1L << (exp/2));
	clrl	-76(fp)
L2000008:
	pushl	20(fp)			# hfs
	ldd	-68(fp)
	pushd
	ldd	4(fp)
	pushd
	callf	$24,_Kdivd
	pushl	20(fp)			# hfs
	ldd	r0
	pushd
	ldd	-68(fp)
	pushd
	callf	$24,_Kaddd
	pushl	20(fp)			# hfs
	ldd	r0	
	pushd
D 2
	ldd	L39
E 2
I 2
	ldd	half
E 2
	pushd
	callf	$24,_Kmuld
	ldd	r0
	std	-68(fp)			# temp=0.5*(temp+arg/temp);
	aobleq	$3,-76(fp),L2000008
	ldd	-68(fp)
	cvdf
	stf	r0
	ret
I 2

	.data
	.align	2
half:	.long	0x40000000, 0x00000000 # .double .5
two:	.long	0x41000000, 0x00000000 # .double 2
one:	.long	0x40800000, 0x00000000 # .double 1
big:	.long	0x4F800000, 0x00000000 # .double (1<<30)
E 2
E 1
