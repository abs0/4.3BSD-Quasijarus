h17178
s 00003/00003/00106
d D 1.3 86/01/05 18:51:01 sam 3 2
c working (mostly)
e
s 00020/00023/00089
d D 1.2 86/01/03 23:47:04 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00112/00000/00000
d D 1.1 85/07/31 21:33:42 sam 1 0
c date and time created 85/07/31 21:33:42 by sam
e
u
U
t
T
I 2
/*	%M%	%I%	%E%	*/
E 2
I 1

D 2
#include 	"fp.h"
#include 	"fp_in_krnl.h"
E 2
I 2
D 3
#include "fp.h"
#include "Kfp.h"
#include "SYS.h"
E 3
I 3
#include "../tahoemath/fp.h"
#include "../tahoemath/Kfp.h"
#include "../tahoe/SYS.h"
E 3
E 2

I 2
#define	HIDDEN	23	/* here we count from 0 not from 1 as in fp.h */
E 2

D 2
 			/* here we count from 0 not from 1 as in fp.h */
#define	HIDDEN	23	

E 2
I 2
/*
 * _Kmuld(acc_most,acc_least,op_most,op_least,hfs)
 */
E 2
	.text
D 2
	.globl	_Kmuld	    # _Kmuld(acc_most,acc_least,op_most,op_least,hfs)
_Kmuld:	.word	0xffc
E 2
I 2
ENTRY(Kmuld, R9|R8|R7|R6|R5|R4|R3|R2)
E 2
	clrl	r3		/* r3 - sign: 0 for positive,1 for negative. */
	movl	4(fp),r0
	jgeq	1f
	movl	$1,r3
1:	movl	12(fp),r2
	jgeq	2f
	bbc	$0,r3,1f	/* seconed operand is negative. */
D 2
	clrl	r3		/* if first was negative, make result positive. */
E 2
I 2
	clrl	r3		/* if first was neg, make result pos */
E 2
	jmp	2f
D 2
1:	movl	$1,r3		/* if first was positive, make result negative. */
E 2
I 2
1:	movl	$1,r3		/* if first was pos, make result neg */
E 2
2:	andl2	$EXPMASK,r0	/* compute first 'pure'exponent. */
	jeql	retzero
	shrl	$EXPSHIFT,r0,r0
	subl2	$BIASP1,r0	
	andl2	$EXPMASK,r2	/* compute seconed 'pure'exponent. */
	jeql	retzero
	shrl	$EXPSHIFT,r2,r2
	subl2	$BIASP1,r2
	addl2	r0,r2		/* add the exponents. */
	addl2	$(BIASP1+2),r2
	jleq	underflow
	cmpl	r2,$258		/* normalization can make the exp. smaller. */
	jgeq	overflow
 /*
D 2
 *	We have the sign in r3,the exponent in r2,now is the time to
 * 	perform the multiplication...
 */
E 2
I 2
  *	We have the sign in r3,the exponent in r2,now is the time to
  * 	perform the multiplication...
  */
E 2
	/* fetch first fraction: (r0,r1) */
	andl3	$(0!(EXPMASK | SIGNBIT)),4(fp),r0
	orl2	$(0!CLEARHID),r0
	movl	8(fp),r1
	shlq	$7,r0,r0	/* leave the sign bit cleared. */
 
	/* fetch seconed fraction: (r4,r5) */
	andl3	$(0!(EXPMASK | SIGNBIT)),12(fp),r4
	orl2	$(0!CLEARHID),r4
	movl	16(fp),r5
	shlq	$7,r4,r4	/* leave the sign bit cleared. */

	/* in the following lp1 stands for least significant part of operand 1,
	*		   lp2 for least significant part of operand 2,
	*		   mp1 for most significant part of operand 1,
	*		   mp2 for most significant part of operand 2.
	*/
 
	clrl 	r6
	shrl	$1,r1,r1	/* clear the sign bit of the lp1. */
	jeql	1f
	emul	r1,r4,$0,r6	/* r6,r7 <-- lp1*mp2 */
	shlq	$1,r6,r6	/* to compensate for the shift we did to clear the sign bit. */
1:	shrl	$1,r5,r5	/* clear the sign bit of the lp2. */
	jeql	1f
	emul	r0,r5,$0,r8	/* r8,r9 <-- mp1*lp2 */
	shlq	$1,r8,r8
	addl2	r9,r7		/* r6,r7 <-- the sum of the products. */
	adwc	r8,r6
1:	emul	r0,r4,$0,r0	/* r0,r1 <-- mp1*mp2  */
	addl2	r6,r1		/* add the most sig. part of the sum. */
	adwc	$0,r0
	movl	r0,r4		/* to see how much we realy need to shift. */
	movl	$6,r5		/* r5 - shift counter. */
	shrl	$7,r4,r4	/* dummy shift. */
1:	bbs	$HIDDEN,r4,realshift
	shll	$1,r4,r4
	decl	r2		/* update exponent. */
	jeql	underflow
	decl	r5		/* update shift counter. */
	jmp	1b
realshift:
	shrq	r5,r0,r0
	bbc	$0,r1,shiftmore
	incl	r1		/* rounding. */
shiftmore:
	shrq	$1,r0,r0
comb:
	andl2	$CLEARHID,r0
	shll	$EXPSHIFT,r2,r4
	orl2	r4,r0
	cmpl	r2,$256
	jlss	1f
	orl2	$HFS_OVF,*20(fp)	
sign:
1:	bbc	$0,r3,done
	orl2	$SIGNBIT,r0
done:	ret

D 2


  retzero:
	  clrl	r0
	  clrl	r1
	  ret
  overflow:
E 2
I 2
retzero:
	clrl	r0
	clrl	r1
	ret
overflow:
E 2
	orl2	$HFS_OVF,*20(fp)
	ret
D 2
  underflow:
E 2
I 2
underflow:
E 2
	orl2	$HFS_UNDF,*20(fp)
	ret
D 2


	
E 2
E 1
