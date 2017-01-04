h34134
s 00001/00001/00078
d D 1.3 86/01/05 18:50:39 sam 3 2
c working (mostly)
e
s 00077/00079/00002
d D 1.2 86/01/03 23:46:38 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00081/00000/00000
d D 1.1 85/08/02 15:42:22 sam 1 0
c date and time created 85/08/02 15:42:22 by sam
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
.globl	Xcmpd
.set	L12,0x1e00
.data
.text
_cmpd:
Xcmpd:.word	L12
movl	4(fp),r12
movl	8(fp),r10
movl	12(fp),r11
movl	16(fp),r9
tstl	r12
jgeq	L16
xorl2	$-2147483648,r12
tstl	r10
jeql	L17
mnegl	r10,r10
mcoml	r12,r12
jbr	L16
L17:mnegl	r12,r12
L16:tstl	r11
jgeq	L19
xorl2	$-2147483648,r11
tstl	r9
jeql	L20
mnegl	r9,r9
mcoml	r11,r11
jbr	L19
L20:mnegl	r11,r11
L19:cmpl	r12,r11
jeql	L22
cmpl	r12,r11
jleq	L9999
movl	$1,r0
jbr	L9998
L9999:mnegl	$1,r0
L9998:ret
L22:cmpl	r10,r9
jeql	L23
cmpl	r10,r9
jlequ	L9997
movl	$1,r0
jbr	L9996
L9997:mnegl	$1,r0
L9996:ret
L23:clrl	r0
ret
E 2
I 2
/*	%M%	%I%	%E%	*/
E 2

D 2
 #
 # The assembler version is the output of cct for this whith minor editing
 # (_cmpd --> cmpd).
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
 #cmpd(hi1, lo1, hi2, lo2)
 #	register hi1, hi2;
 #	register unsigned lo1, lo2;
 #{
 #	if(hi1 < 0) {
 #		hi1 ^= 0x80000000;
 #		if(lo1) {
 #			lo1 = -lo1;
 #			hi1 = ~hi1;
 #		} else
 #			hi1 = -hi1;
 #	}
 #	if(hi2 < 0) {
 #		hi2 ^= 0x80000000;
 #		if(lo2) {
 #			lo2 = -lo2;
 #			hi2 = ~hi2;
 #		} else
 #			hi2 = -hi2;
 #	}
 #	if(hi1 != hi2)
 #		return(hi1>hi2 ? 1 : -1);
 #	if(lo1 != lo2)
 #		return(lo1>lo2 ? 1 : -1);
 #	return(0);
 #}
E 2
I 2
/*
 * cmpd(hi1, lo1, hi2, lo2)
 *	register hi1, hi2;
 *	register unsigned lo1, lo2;
 *{
 *	if(hi1 < 0) {
 *		hi1 ^= 0x80000000;
 *		if(lo1) {
 *			lo1 = -lo1;
 *			hi1 = ~hi1;
 *		} else
 *			hi1 = -hi1;
 *	}
 *	if(hi2 < 0) {
 *		hi2 ^= 0x80000000;
 *		if(lo2) {
 *			lo2 = -lo2;
 *			hi2 = ~hi2;
 *		} else
 *			hi2 = -hi2;
 *	}
 *	if(hi1 != hi2)
 *		return(hi1>hi2 ? 1 : -1);
 *	if(lo1 != lo2)
 *		return(lo1>lo2 ? 1 : -1);
 *	return(0);
 *}
 */
	.text
ENTRY(Kcmpd, 0)
	movl	8(fp),r3
	movl	12(fp),r4
	movl	16(fp),r2
	movl	4(fp),r5
	jgeq	1f
	xorl2	$0x80000000,r5
	tstl	r3
	jeql	2f
	mnegl	r3,r3
	mcoml	r5,r5
	jbr	1f
2:
	mnegl	r5,r5
1:
	tstl	r4
	jgeq	1f
	xorl2	$0x80000000,r4
	tstl	r2
	jeql	2f
	mnegl	r2,r2
	mcoml	r4,r4
	jbr	1f
2:
	mnegl	r4,r4
1:
	cmpl	r5,r4
	jeql	1f
	jleq	2f
	movl	$1,r0
	ret
2:
	mnegl	$1,r0
	ret
1:
	cmpl	r3,r2
	jeql	1f
	jlequ	2f
	movl	$1,r0
	ret
2:
	mnegl	$1,r0
	ret
1:
	clrl	r0
	ret
E 2
E 1
