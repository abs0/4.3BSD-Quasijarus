h19325
s 00007/00007/00115
d D 7.3 04/03/19 17:47:31 msokolov 3 2
c change some comments regarding unassigned SID codes
e
s 00006/00002/00116
d D 7.2 04/03/18 19:19:14 msokolov 2 1
c add BabyVAX support (beginnings thereof)
c a few other todo closures and fixes along the way
e
s 00118/00000/00000
d D 7.1 04/01/03 18:07:54 msokolov 1 0
c date and time created 04/01/03 18:07:54 by msokolov
e
u
U
t
T
I 1
/*
 * 4.3BSD-Quasijarus CPU identification logic.
 *
 * Deduces the CPU type from SID and SIE longwords.
 * Must run with MMU disabled to read SIE.
 *
 *	%W% (Berkeley) %G%
 */

#define	LOCORE
#include "../vax/cpu.h"
#include "../vax/mtpr.h"

	.text
	.globl	_cpuid
_cpuid:	.word	0x0000
	mfpr	$SID,r1
	movl	r1,_cpusid
	extzv	$24,$8,r1,r0
	casel	r0,$1,$0x14
0:	.word	out-0b		# 780
	.word	out-0b		# 750
	.word	out-0b		# 730
	.word	out-0b		# 8600
	.word	out-0b		# 8200
	.word	out-0b		# 8800
	.word	out-0b		# UV1
	.word	uv2-0b		# UV2
D 3
	.word	unident-0b	# 09 unassigned
E 3
I 3
	.word	unident-0b	# Virtual VAX unsupported
E 3
	.word	cvax-0b		# CVAX
	.word	rigel-0b	# Rigel
D 3
	.word	unident-0b	# 0C unassigned
	.word	unident-0b	# 0D unassigned
E 3
I 3
	.word	unident-0b	# 0C unassigned (?)
	.word	unident-0b	# 0D unassigned (?)
E 3
	.word	out-0b		# 9000
D 3
	.word	unident-0b	# 0F unassigned
	.word	unident-0b	# 10 unassigned
E 3
I 3
	.word	unident-0b	# 0F unassigned (?)
	.word	unident-0b	# 78R32 rtVAX can't run UNIX or VMS
E 3
	.word	polarstar-0b	# Polarstar
	.word	unident-0b	# don't know how to identify Mariah
	.word	unident-0b	# don't know how to identify NVAX
	.word	soc-0b		# SOC
unident:
/*
 * We can't identify this CPU or have no Quasijarus CPU ID code for it
 * return 0
 */
	clrl	r0
out:	movl	r0,_cpu
	ret

/* MicroVAX II chip */
uv2:	movl	*$0x20040004,r2	# get SIE
	movl	r2,_cpusie
	extzv	$24,$8,r2,r3
	casel	r3,$1,$4
0:	.word	ka630-0b	# KA630
D 3
	.word	unident-0b	# 02 unassigned
	.word	unident-0b	# 03 unassigned
E 3
I 3
	.word	unident-0b	# 02 unassigned (?)
	.word	unident-0b	# 03 unassigned (?)
E 3
D 2
	.word	unident-0b	# KA410, no QJ code for it currently
E 2
I 2
	.word	ka410-0b	# KA410
E 2
	jbr	unident
ka630:	movl	$VAX_630,r0
	jbr	out
I 2
ka410:	movl	$VAX_410,r0
	jbr	out
E 2

/* CVAX chip */
cvax:	movl	*$0x20040004,r2	# get SIE
	movl	r2,_cpusie
	extzv	$24,$8,r2,r3
	casel	r3,$1,$4
0:	.word	ka6xx-0b	# KA650 family
	.word	unident-0b	# VAX 6200/6300, no QJ code for it currently
	.word	unident-0b	# Firefox, no QJ code for it currently
D 2
	.word	unident-0b	# KA42/41, no QJ code for it currently
E 2
I 2
	.word	vs3100-0b	# VS3100 (KA42) or its MicroVAX variant (KA41)
E 2
	jbr	unident
I 2
vs3100:	movl	$VAX_3100,r0
	jbr	out
E 2

/* Rigel chip */
rigel:	movl	*$0x20040004,r2	# get SIE
	movl	r2,_cpusie
	extzv	$24,$8,r2,r3
	casel	r3,$1,$4
0:	.word	ka6xx-0b	# KA670
	.word	unident-0b	# VAX 6400, no QJ code for it currently
	.word	unident-0b	# 03 unassigned
	.word	unident-0b	# KA43, no QJ code for it currently
	jbr	unident

/*
 * Polarstar 8800.
 * Make it into a regular 8800.
 * Of course we support neither currently...
 */
polarstar:
	movl	$VAX_8800,r0
	jbr	out

/* SOC chip */
soc:	movl	*$0x20040004,r2	# get SIE
	movl	r2,_cpusie
	extzv	$24,$8,r2,r3
	casel	r3,$1,$4
0:	.word	ka6xx-0b	# KA660
	.word	unident-0b	# 02 unassigned
	.word	unident-0b	# 03 unassigned
	.word	unident-0b	# don't know how to identify SOC BabyVAXen
	jbr	unident

/*
 * KA6xx series boards starting with KA650 have a SYS_SUB_TYPE field in SIE
 * which identifies the exact KA6xx board.  This is what we use.
 */
ka6xx:	extzv	$8,$8,r2,r4
	casel	r4,$1,$5
0:	.word	ka650-0b	# KA650
	.word	ka650-0b	# KA640, supported by KA650 code
	.word	ka650-0b	# KA655, faster-clocked KA650
	.word	unident-0b	# KA670, no QJ code for it currently
	.word	ka650-0b	# KA660, supported by KA650 code
	jbr	unident
ka650:	movl	$VAX_650,r0
	jbr	out
E 1
