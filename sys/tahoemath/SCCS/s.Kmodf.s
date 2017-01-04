h27856
s 00002/00002/00110
d D 1.3 86/01/05 18:51:00 sam 3 2
c working (mostly)
e
s 00016/00019/00096
d D 1.2 86/01/03 23:47:02 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00115/00000/00000
d D 1.1 85/08/02 15:42:29 sam 1 0
c date and time created 85/08/02 15:42:29 by sam
e
u
U
t
T
I 2
/*	%M%	%I%	%E%	*/
E 2
I 1

I 2
D 3
#include "SYS.h"
#include "fp.h"
E 3
I 3
#include "../tahoe/SYS.h"
#include "../tahoemath/fp.h"
E 3
E 2

D 2
/* 	Kmodf.x	4.2	84/02/27	*/

E 2
/* 
D 2
*  float Kmodf (value, iptr, hfs)
*  float value, *iptr;
*  int hfs;
* 
*  Modf returns the fractional part of "value",
*  and stores the integer part indirectly through "iptr".
*/ 
#include	"fp.h"
 
E 2
I 2
 *  float Kmodf (value, iptr, hfs)
 *  float value, *iptr;
 *  int hfs;
 * 
 *  Modf returns the fractional part of "value",
 *  and stores the integer part indirectly through "iptr".
 */ 
E 2
	.text
D 2
	.globl	_Kmodf
_Kmodf:	.word	0x1ffc		/* we use many registers */

E 2
I 2
ENTRY(Kmodf, R8|R7|R6|R5|R4|R3|R2)
E 2
 /*
 * Some initializations:
 */
	clrl	r3
	movl	4(fp),r0	/* fetch operand to r0. */
	movl	8(fp),r1
	movl	12(fp),r6	/* fetch addr of int to r6. */
 /*
D 2
 * get exponent
 */
E 2
I 2
  * get exponent
  */
E 2
	andl3	$EXPMASK,r0,r2	/* r2 will hold the exponent. */
	shrl	$EXPSHIFT,r2,r2
	subl2	$BIAS,r2	/* unbias it.  */
	jleq	allfrac		/* it's int part is  zero. */
	cmpl	r2,$56
	jgeq	allint		/* it's fraction part is zero. */
 /*
D 2
 * get fraction
 */
E 2
I 2
  * get fraction
  */
E 2
	movl	r0,r4		/* remember the original number. */
	movl	r1,r5
	bbc	$31,r0,positive	/* if negative remember it. */
	incl	r3
positive:
				/* clear the non fraction parts. */
	andl2	$(0!(EXPMASK | SIGNBIT)),r0
				/* add the hidden bit. */
	orl2	$(0!CLEARHID),r0

	cmpl	r2,$HID_POS	/* see if there are bits to clear only in r0 */
	jgtr	in_r1		/* some bytes in r1	*/
	jeql	onlyallr0	/* all r0 must be cleared. */
	mnegl	r2,r7		/* r7 - loop counter. */
	movl	$CLEARHID,r8	/* first bit to clear. */
1:
	andl2	r8,r0		/* clear int. bits from fraction part. */
	shar	$1,r8,r8
	aoblss	$0,r7,1b
1:
	andl2	r8,r4		/* clear frac bits for int calculation: */
	shar	$1,r8,r8
	cmpl	$0xffffffff,r8
	jneq	1b
	clrl	r5
	jmp	norm

onlyallr0:
	clrl	r0
	clrl	r5
	jmp 	norm

in_r1:
	clrl	r0
	subl3	r2,$HID_POS,r7
	movl	$0x7fffffff,r8
1:
	andl2	r8,r1
	shar	$1,r8,r8
	orl2	$0x80000000,r8
	aoblss	$0,r7,1b
1:
	andl2	r8,r5
	shar	$1,r8,r8
	cmpl	$0xffffffff,r8
	jneq	1b
norm:
	addl2	$BIAS,r2	/* fnorm expects it biased. */
	pushl	16(fp)		/* hfs */
D 2
	callf	$8,Kfnorm	/* normelize fraction part. */
E 2
I 2
	callf	$8,_Kfnorm	/* normelize fraction part. */
E 2
	cmpl	$0,r0
	jeql	1f
	bbc	$0,r3,1f
	orl2	$0x80000000,r0
1:
	movl	r4,(r6)		/* put int part in place. */
	movl	r5,4(r6)
	ret
 
allint:
	movl	r0,(r6)		/* copy the argument to the int addr. */
	movl	r1,4(r6)
	clrl	r0		/* clear the fraction part. */
	clrl	r1
	ret

allfrac:
				/* the fraction is ready in r0. */
	clrl	(r6)		/* zero the int part. */
	clrl	4(r6)
	ret

ret_zero:
	clrl	(r6)
 	clrl	4(r6)	
	clrl	r0
	clrl	r1
	ret
E 1
