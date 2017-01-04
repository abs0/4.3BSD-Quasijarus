h42213
s 00158/00000/00000
d D 5.1 2012/06/20 05:00:30 msokolov 1 0
c date and time created 2012/06/20 05:00:30 by msokolov
e
u
U
t
T
I 1
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley) %E%"
#endif LIBC_SCCS

/* this is a hand-optimized version of ../mjd2weekday.c */

#include "DEFS.h"

tab9:	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006
	.long	0x6050403
	.long	0x3020100
	.long	0x60504

hitab:	.long	0x6050403
	.long	0x3020100
	.long	0x60504
	.long	0x4030201
	.long	0x4030201
	.long	0x1000605
	.long	0x5040302
	.long	0x2010006

ENTRY(mjd2weekday, 0)
	movl	4(ap),r1
	extzv	$27,$5,r1,r2
	movzbl	hitab[r2],r3
	extzv	$18,$9,r1,r2
	addb2	tab9[r2],r3
	extzv	$9,$9,r1,r2
	addb2	tab9[r2],r3
	extzv	$0,$9,r1,r2
	addb2	tab9[r2],r3
	movzbl	tab9[r3],r0
	ret
E 1
