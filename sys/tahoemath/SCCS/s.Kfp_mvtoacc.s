h25143
s 00002/00002/00022
d D 1.3 86/01/05 18:50:54 sam 3 2
c working (mostly)
e
s 00015/00014/00009
d D 1.2 86/01/03 23:46:55 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00023/00000/00000
d D 1.1 85/08/02 15:42:26 sam 1 0
c date and time created 85/08/02 15:42:26 by sam
e
u
U
t
T
I 1
D 2
#include	"fp.h"
E 2
I 2
/*	%M%	%I%	%E%	*/
E 2

D 2
	.globl	_mvtofacc	# mvtofacc(value, acc_addr)
_mvtofacc:
	.word	0x0000
E 2
I 2
D 3
#include "fp.h"
#include "SYS.h"
E 3
I 3
#include "../tahoemath/fp.h"
#include "../tahoe/SYS.h"
E 3
E 2

D 2
    #
    # move value to floating point accumulator
    #
E 2
I 2
/*
 * mvtofacc(value, acc_addr)
 *
 * move value to floating point accumulator
 */
ENTRY(mvtofacc, 0)
E 2
	movl	4(fp),*12(fp)
	ret

D 2
	.globl	_mvtodacc	# mvtodacc(value_hi, value_lo, acc_addr)
_mvtodacc:
	.word	0x0000

    #
    # move value to double precision accumulator
    #
E 2
I 2
/*
 * mvtodacc(value_hi, value_lo, acc_addr)
 *
 * move value to double precision accumulator
 */
ENTRY(mvtodacc, 0)
E 2
	movl	12(fp),r0	# address of accumulator
	movl	4(fp),(r0)	# most significant longword
	movl	8(fp),4(r0)	# least significant longword
	ret
E 1
