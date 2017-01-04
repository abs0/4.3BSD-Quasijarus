h39421
s 00001/00001/00040
d D 1.3 86/01/05 18:50:40 sam 3 2
c working (mostly)
e
s 00039/00048/00002
d D 1.2 86/01/03 23:46:39 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00050/00000/00000
d D 1.1 85/08/02 15:42:23 sam 1 0
c date and time created 85/08/02 15:42:23 by sam
e
u
U
t
T
I 1
D 2
.data
.text
LL0:.align	1
.globl	Xcmpf
.set	L12,0x1800
.data
.text
_cmpf:
Xcmpf:.word	L12
movl	4(fp),r12
movl	12(fp),r11
tstl	r12
jgeq	L16
xorl2	$-2147483648,r12
mnegl	r12,r12
L16:tstl	r11
jgeq	L19
xorl2	$-2147483648,r11
mnegl	r11,r11
L19:cmpl	r12,r11
jeql	L22
cmpl	r12,r11
jleq	L9999
movl	$1,r0
jbr	L9998
L9999:mnegl	$1,r0
L9998:ret
L22:clrl	r0
ret
E 2
I 2
/*	%M%	%I%	%E%	*/
E 2

D 2
 #
 # The assembler version is the output of cct for this whith minor editing
 # (_cmpf --> cmpf).
 #
E 2
I 2
D 3
#include "SYS.h"
E 3
I 3
#include "../tahoe/SYS.h"
E 3
E 2

D 2
 #cmpf(o1, o2)
 #	register o1, o2;
 #{
 #	if(o1 < 0) {
 #		o1 ^= 0x80000000;
 #		o1 = -o1;
 #	}
 #	if(o2 < 0) {
 #		o2 ^= 0x80000000;
 #		o2 = -o2;
 #	}
 #	if(o1 != o2)
 #		return(o1>o2 ? 1 : -1);
 #	return(0);
 #}
E 2
I 2
/*
 * cmpf(o1, o2)
 *	register o1, o2;
 *{
 *	if(o1 < 0) {
 *		o1 ^= 0x80000000;
 *		o1 = -o1;
 *	}
 *	if(o2 < 0) {
 *		o2 ^= 0x80000000;
 *		o2 = -o2;
 *	}
 *	if(o1 != o2)
 *		return(o1>o2 ? 1 : -1);
 *	return(0);
 *}
 */
	.text
ENTRY(Kcmpf, 0)
	movl	4(fp),r12
	jgeq	1f
	xorl2	$0x80000000,r12
	mnegl	r12,r12
1:
	movl	12(fp),r11
	jgeq	1f
	xorl2	$0x80000000,r11
	mnegl	r11,r11
1:
	cmpl	r12,r11
	jneq	1f
	clr	r0; ret
1:
	jleq	1f
	movl	$1,r0; ret
1:
	mnegl	$1,r0; ret
E 2
E 1
