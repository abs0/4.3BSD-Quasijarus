h18475
s 00001/00001/00063
d D 1.3 86/01/05 18:50:56 sam 3 2
c working (mostly)
e
s 00034/00050/00030
d D 1.2 86/01/03 23:46:57 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00080/00000/00000
d D 1.1 85/08/02 15:42:27 sam 1 0
c date and time created 85/08/02 15:42:27 by sam
e
u
U
t
T
I 1
D 2
/* 	file : Kfrexpf.x 
*/
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
	.globl	_Kfrexpf
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
L25:	.long	0x40000000, 0x00000000 # .double .5
	.text
	.data
	.align	2
L28:	.long	0x40000000, 0x00000000 # .double .5
	.text
	.data
	.align	2
L29:	.long	0x41000000, 0x00000000 # .double 2
	.text
	.set	L12,0x0
	.data
	.text
_Kfrexpf:.word	L12
E 2
I 2
ENTRY(Kfrexpf, 0)
E 2
	subl3	$60,fp,sp
	clrl	-60(fp)		# j=0;
	clrl	-56(fp)		# neg=0;
	tstl	4(fp)		# if(x<0){
D 2
	jgeq	L16
E 2
I 2
	jgeq	1f
E 2
	lnd	4(fp)
	std	4(fp)		# x = -x;
	movl	$1,-56(fp)	# neg=1;}
D 2
L16:	cmpd2	4(fp),L18	# if (x>1){
	jleq	L17
L19:	cmpd2	4(fp),L21	# while(x>1){
	jleq	L23
E 2
I 2
1:
	cmpd2	4(fp),one	# if (x>1){
	jleq	1f
2:
	cmpd2	4(fp),one	# while(x>1){
	jleq	3f
E 2
	addl2	$1,-60(fp)	# j=j+1;
	pushl	16(fp)		# hfs	
D 2
	ldd	L22
E 2
I 2
	ldd	two
E 2
	pushd
	ldd	4(fp)
	pushd
	callf	$24,_Kdivd
	ldd	r0
	std	4(fp)		# x= x/2;
D 2
	jbr	L19
L17:	cmpd2	4(fp),L25	# if(x<0.5){
	jlss	L26
	jbr	L23
L2000001:
E 2
I 2
	jbr	2b
1:
	cmpd2	4(fp),half	# if(x<0.5){
	jlss	2f
	jbr	3f
0:
E 2
	subl2	$1,-60(fp)	# j = j-1;
	pushl	16(fp)		# hfs
	ldd	4(fp)
	pushd
D 2
	ldd	L29
E 2
I 2
	ldd	two
E 2
	pushd
	callf	$24,_Kmuld
	ldd	r0
	std	4(fp)		# x = 2*x;
D 2
L26:	cmpd2	4(fp),L28	# while (x<0.5){
	jlss	L2000001
L23:	movl	-60(fp),*12(fp)	# *i=j;
E 2
I 2
2:
	cmpd2	4(fp),half	# while (x<0.5){
	jlss	0b
3:
	movl	-60(fp),*12(fp)	# *i=j;
E 2
	tstl	-56(fp)		# if (neg)
D 2
	jeql	L30
E 2
I 2
	jeql	1f
E 2
	lnd	4(fp)
	std	4(fp)
D 2
L30:	ldd	4(fp)
E 2
I 2
1:
	ldd	4(fp)
E 2
	cvdf
	stf	r0
	ret
I 2

	.data
	.align	2
one:	.long	0x40800000, 0x00000000 # .double 1
two:	.long	0x41000000, 0x00000000 # .double 2
half:	.long	0x40000000, 0x00000000 # .double .5
E 2
E 1
