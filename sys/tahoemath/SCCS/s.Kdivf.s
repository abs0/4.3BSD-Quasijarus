h48066
s 00003/00003/00073
d D 1.3 86/01/05 18:50:48 sam 3 2
c working (mostly)
e
s 00007/00008/00069
d D 1.2 86/01/03 23:46:48 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00077/00000/00000
d D 1.1 85/07/31 21:33:40 sam 1 0
c date and time created 85/07/31 21:33:40 by sam
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
#define	HIDDEN	23	 	# here we count from 0 not from 1 as in fp.h
E 2

D 2
 			# here we count from 0 not from 1 as in fp.h
#define	HIDDEN	23	

E 2
	.text
D 2
	.globl	_Kdivf	    # _Kdivf(acc_most,acc_least,op_most,op_least,hfs)
_Kdivf:	.word	0xffc
E 2
I 2
ENTRY(Kdivf, R9|R8|R7|R6|R5|R4|R3|R2)
E 2
	clrl	r1
	clrl	r3		# r3 - sign: 0 for positive,1 for negative.
	movl	4(fp),r0
	jgeq	1f
	movl	$1,r3
1:	movl	12(fp),r2
	jgeq	2f
	bbc	$0,r3,1f	# seconed operand is negative.
	clrl	r3		# if first was negative, make result positive.
	jmp	2f
1:	movl	$1,r3		# if first was positive, make result negative.
2:	andl2	$EXPMASK,r0	# compute first 'pure'exponent.
	jeql	retz
	shrl	$EXPSHIFT,r0,r0
	subl2	$BIAS,r0	
	andl2	$EXPMASK,r2	# compute seconed 'pure'exponent.
	jeql	retz2
	shrl	$EXPSHIFT,r2,r2
	subl2	$BIAS,r2
	subl3	r2,r0,r2	# subtruct the exponents.
	addl2	$BIAS,r2
	jleq	underf
				# normalization can make the exp. smaller.
 #
 #	We have the sign in r3,the exponent in r2,now is the time to
 # 	perform the division...
 #
	# fetch dividend. (r0)
	andl3	$(0!(EXPMASK | SIGNBIT)),4(fp),r0
	orl2	$(0!CLEARHID),r0
	clrl	r1
 
	# fetch divisor : (r6)
	andl3	$(0!(EXPMASK | SIGNBIT)),12(fp),r6
	orl2	$(0!CLEARHID),r6

	shll	$2,r6,r6	# make the divisor bigger so we will not
				# get overflow at the divission.
	ediv	r6,r0,r0,r7	# quo to r0, rem to r7
	subl2	$6,r2		# to compensate for: normalization (-24),
				# ediv (+32), shifting r6 (-2).
	
over:
	pushl	20(fp)
D 2
	callf	$8,Kfnorm	# we can use fnorm because we have data
E 2
I 2
	callf	$8,_Kfnorm	# we can use fnorm because we have data
E 2
				# at r1 as well.(sfnorm takes care only 
				# of r0).
sign:
1:	bbc	$0,r3,done
	orl2	$SIGNBIT,r0
done:	ret

retz:
	clrl	r0
	ret

retz2:	bbc	$31,12(fp),z_div
	clrl	r0
	ret

underf:
	orl2	$HFS_UNDF,*20(fp)	
	ret
z_div:
	orl2	$HFS_DIVZ,*20(fp)
	ret
E 1
