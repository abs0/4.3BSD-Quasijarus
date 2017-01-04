h56606
s 01088/00000/00000
d D 7.1 04/02/03 18:26:35 msokolov 1 0
c D-float emulator completed, builds
e
u
U
t
T
I 1
/*
 * D-floating instruction emulator
 * Designed and written by Michael Sokolov
 *
 *	%W% (Berkeley) %G%
 */

#include "../vax/cpucond.h"
#if EMULDFLT
#include "../vax/psl.h"
#include "../vax/emul/emul_opspec.h"
#include "../vax/emul/emul_funpack.h"

/* Operand specifications for _EMF_operand_decode */
arithd2_opspec:	.byte	TYPRF,SIZQ,TYPM,SIZQ,0
arithd3_opspec:	.byte	TYPRF,SIZQ,TYPRF,SIZQ,TYPW,SIZQ,0
cmpd_opspec:	.byte	TYPRF,SIZQ,TYPRF,SIZQ,0
cvtbd_opspec:	.byte	TYPRI,SIZB,TYPW,SIZQ,0
cvtwd_opspec:	.byte	TYPRI,SIZW,TYPW,SIZQ,0
cvtld_opspec:	.byte	TYPRI,SIZL,TYPW,SIZQ,0
cvtdb_opspec:	.byte	TYPRF,SIZQ,TYPW,SIZB,0
cvtdw_opspec:	.byte	TYPRF,SIZQ,TYPW,SIZW,0
cvtdl_opspec:	.byte	TYPRF,SIZQ,TYPW,SIZL,0
cvtfd_opspec:	.byte	TYPRF,SIZL,TYPW,SIZQ,0
cvtdf_opspec:	.byte	TYPRF,SIZQ,TYPW,SIZL,0
emodd_opspec:	.byte	TYPRF,SIZQ,TYPRI,SIZB,TYPRF,SIZQ,TYPW,SIZL,TYPW,SIZQ,0
movd_opspec:	.byte	TYPRF,SIZQ,TYPW,SIZQ,0
polyd_opspec:	.byte	TYPRF,SIZQ,TYPRI,SIZW,TYPA,SIZB,0
tstd_opspec:	.byte	TYPRF,SIZQ,0
/* _EMF_operand_decode doesn't know about ACBx branch displacement */
acbd_opspec:	.byte	TYPRF,SIZQ,TYPRF,SIZQ,TYPM,SIZQ,0

	.globl	_EMFtstd
	.align	2
_EMFtstd:
	subl2	$8,sp
	movab	tstd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movl	-8(fp),r0
#if EMULFFLT
	jmp	_EMF_tstfd_common
#else
	bicw2	$PSL_ALLCC,4(fp)
	bitw	$0x7F80,r0
	beql	1f
	bbc	$15,r0,2f
	bisw2	$PSL_N,4(fp)
2:	jmp	_EMF_normal_return
1:	bbs	$15,r0,3f
	bisw2	$PSL_Z,4(fp)
	brb	2b
3:	jmp	_EMF_reserved_operand_fault
#endif

	.globl	_EMFcmpd
	.align	2
_EMFcmpd:
	subl2	$16,sp
	movab	cmpd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKD(-16,r0,r1,r2)
	UNPACKD(-8,r3,r4,r5)
	bicw2	$PSL_ALLCC,4(fp)
	xorl3	r0,r3,r6
	jbs	$8,r6,cmpd_finish
	cmpb	r0,r3
	jlssu	cmpd_lss
	jgtru	cmpd_finish
	cmpl	r2,r5
	jlssu	cmpd_lss
	jgtru	cmpd_finish
	cmpl	r1,r4
	jlssu	cmpd_lss
	jgtru	cmpd_finish
	bisw2	$PSL_Z,4(fp)
	jbr	cmpd_out
cmpd_lss:
	bisw2	$PSL_N,4(fp)
cmpd_finish:
	jbc	$8,r0,cmpd_out
	xorw2	$PSL_N,4(fp)
cmpd_out:
	jmp	_EMF_normal_return

	.globl	_EMFmovd
	.align	2
_EMFmovd:
	subl2	$12,sp
	movab	movd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movq	-12(fp),r0
	bicw2	$PSL_ALLCC,4(fp)
	bitw	$0x7F80,r0
	jeql	1f
	jbc	$15,r0,2f
	bisw2	$PSL_N,4(fp)
	jbr	2f
1:	jbs	$15,r0,3f
	bisw2	$PSL_Z,4(fp)
2:	movq	r0,*-4(fp)
	jmp	_EMF_normal_return
3:	jmp	_EMF_reserved_operand_fault

	.globl	_EMFmnegd
	.align	2
_EMFmnegd:
	subl2	$12,sp
	movab	movd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movq	-12(fp),r0
	bicw2	$PSL_ALLCC,4(fp)
	bitw	$0x7F80,r0
	jeql	1f
	xorw2	$0x8000,r0
	jgeq	2f
	bisw2	$PSL_N,4(fp)
	jbr	2f
1:	jbs	$15,r0,3f
	bisw2	$PSL_Z,4(fp)
2:	movq	r0,*-4(fp)
	jmp	_EMF_normal_return
3:	jmp	_EMF_reserved_operand_fault

	.globl	_EMFaddd2
	.align	2
_EMFaddd2:
	subl2	$20,sp
	movab	arithd2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	addd_common

	.globl	_EMFaddd3
	.align	2
_EMFaddd3:
	subl2	$20,sp
	movab	arithd3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
addd_common:
	UNPACKD(-20,r0,r1,r2)
addsubd_common:
	UNPACKD(-12,r3,r4,r5)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	do_addsubd
	movl	-4(fp),r3
	extzv	$24,$7,r2,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r2,r5
	extzv	$24,$16,r1,r6
	extzv	$8,$16,r1,r7
	movw	r4,(r3)
	movw	r5,2(r3)
	movw	r6,4(r3)
	movw	r7,6(r3)
	jmp	_EMF_normal_return

	.globl	_EMFsubd2
	.align	2
_EMFsubd2:
	subl2	$20,sp
	movab	arithd2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	subd_common

	.globl	_EMFsubd3
	.align	2
_EMFsubd3:
	subl2	$20,sp
	movab	arithd3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
subd_common:
	UNPACKD(-20,r0,r1,r2)
	jeql	addsubd_common
	xorw2	$0x100,r0
	jbr	addsubd_common

	.globl	_EMFmuld2
	.align	2
_EMFmuld2:
	subl2	$20,sp
	movab	arithd2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	muld_common

	.globl	_EMFmuld3
	.align	2
_EMFmuld3:
	subl2	$20,sp
	movab	arithd3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
muld_common:
	bicw2	$PSL_ALLCC,4(fp)
	UNPACKD(-20,r0,r1,r2)
	bneq	1f
	/*
	 * Zero multiplicand.  Out with zero result, but must check the other
	 * operand for reserved first.
	 */
	cmpzv	$7,$9,-12(fp),$0x100
	bneq	muldivd_zero
	jmp	_EMF_reserved_operand_fault
1:	UNPACKD(-12,r3,r4,r5)
	bneq	1f
muldivd_zero:
	bisw2	$PSL_Z,4(fp)
	clrq	*-4(fp)
	jmp	_EMF_normal_return
1:	xorw3	r0,r3,r6
	movzbl	r0,r0
	movzbl	r3,r3
	bbc	$8,r6,1f
	bisl2	$0x10000,r0
1:	jsb	muld_core
muldivd_finish:
	addl2	$0x80,r7
	adwc	$0,r8
	bcc	1f
	ashq	$-1,r7,r7
	/* bisl2 $0x80000000,r8 don't need to set hidden bit, about to pack */
	incw	r0
1:	tstw	r0
	jleq	muldivd_underflow
	cmpw	r0,$0xFF
	bleq	1f
	jmp	_EMF_floating_overflow_fault
1:	bbc	$16,r0,1f
	bisw2	$0x100,r0
	bisw2	$PSL_N,4(fp)
1:	movl	-4(fp),r3
	extzv	$24,$7,r8,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r8,r5
	extzv	$24,$16,r7,r6
	extzv	$8,$16,r7,r7
	movw	r4,(r3)
	movw	r5,2(r3)
	movw	r6,4(r3)
	movw	r7,6(r3)
	jmp	_EMF_normal_return
muldivd_underflow:
	bitw	$PSL_FU,4(fp)
	jeql	muldivd_zero
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	muldivd_zero
	jmp	_EMF_floating_underflow_fault

	.globl	_EMFdivd2
	.align	2
_EMFdivd2:
	subl2	$20,sp
	movab	arithd2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	divd_common

	.globl	_EMFdivd3
	.align	2
_EMFdivd3:
	subl2	$20,sp
	movab	arithd3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
divd_common:
	bicw2	$PSL_ALLCC,4(fp)
	UNPACKD(-20,r0,r1,r2)
	bneq	1f
	/*
	 * Zero divisor.  Out with devide by zero fault.  No need to check the
	 * dividend for reserved operand as VARM allows faults to occur in any
	 * order.
	 */
	jmp	_EMF_floating_divby0_fault
1:	UNPACKD(-12,r3,r4,r5)
	jeql	muldivd_zero
	xorw3	r0,r3,r6
	movzbl	r0,r0
	movzbl	r3,r3
	bbc	$8,r6,1f
	bisl2	$0x10000,r0
1:	subw2	r0,r3
	addw3	$129,r3,r0
	movl	$31,r3
	clrq	r7
1:	cmpl	r2,r5
	blssu	2f
	bgtru	3f
	cmpl	r1,r4
	bgtru	3f
2:	subl2	r1,r4
	sbwc	r2,r5
	bbss	r3,r8,3f
3:	decl	r3
	blss	4f
	ashq	$1,r4,r4
	bcs	2b
	brb	1b
4:	movl	$31,r3
1:	cmpl	r2,r5
	blssu	2f
	bgtru	3f
	cmpl	r1,r4
	bgtru	3f
2:	subl2	r1,r4
	sbwc	r2,r5
	bbss	r3,r7,3f
3:	decl	r3
	cmpl	r3,$6
	blssu	4f
	ashq	$1,r4,r4
	bcs	2b
	brb	1b
4:	tstl	r8
	jlss	muldivd_finish
	ashq	$1,r7,r7
	decw	r0
	jbr	muldivd_finish

	.globl	_EMFcvtbd
	.align	2
_EMFcvtbd:
	subl2	$8,sp
	movab	cvtbd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	movw	$0x88,r1
	movb	-8(fp),r0
	jeql	cvtid_zero
	bgeq	1f
	mnegb	r0,r0
	bisw2	$0x100,r1
	bisw2	$PSL_N,4(fp)
1:	ashl	$24,r0,r0
cvtid_finish:
	tstl	r0
	blss	2f
1:	decb	r1
	ashl	$1,r0,r0
	bgeq	1b
2:	movl	-4(fp),r3
	extzv	$24,$7,r0,r4
	insv	r1,$7,$9,r4
	extzv	$8,$16,r0,r5
	movw	r4,(r3)
	movw	r5,2(r3)
	clrl	4(r3)
	movb	r0,5(r3)
	jmp	_EMF_normal_return
cvtid_zero:
	bisw2	$PSL_Z,4(fp)
	clrq	*-4(fp)
	jmp	_EMF_normal_return

	.globl	_EMFcvtwd
	.align	2
_EMFcvtwd:
	subl2	$8,sp
	movab	cvtwd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	movw	$0x90,r1
	movw	-8(fp),r0
	jeql	cvtid_zero
	bgeq	1f
	mnegw	r0,r0
	bisw2	$0x100,r1
	bisw2	$PSL_N,4(fp)
1:	ashl	$16,r0,r0
	jbr	cvtid_finish

	.globl	_EMFcvtld
	.align	2
_EMFcvtld:
	subl2	$8,sp
	movab	cvtld_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	movw	$0xA0,r1
	movl	-8(fp),r0
	jeql	cvtid_zero
	jgeq	cvtid_finish
	mnegl	r0,r0
	bisw2	$0x100,r1
	bisw2	$PSL_N,4(fp)
	jbr	cvtid_finish

	.globl	_EMFcvtdb
	.align	2
_EMFcvtdb:
	subl2	$12,sp
	movab	cvtdb_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKD(-12,r0,r1,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_dfloat
	cvtlb	r5,*-4(fp)
	movpsl	r6
	mnegl	$PSL_N|PSL_Z|PSL_V,r7
	bicl2	r7,r6
	bisw2	r6,4(fp)
	jmp	_EMF_check_integer_overflow

	.globl	_EMFcvtdw
	.align	2
_EMFcvtdw:
	subl2	$12,sp
	movab	cvtdw_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKD(-12,r0,r1,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_dfloat
	cvtlw	r5,*-4(fp)
	movpsl	r6
	mnegl	$PSL_N|PSL_Z|PSL_V,r7
	bicl2	r7,r6
	bisw2	r6,4(fp)
	jmp	_EMF_check_integer_overflow

	.globl	_EMFcvtdl
	.align	2
_EMFcvtdl:
	subl2	$12,sp
	movab	cvtdl_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKD(-12,r0,r1,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_dfloat
	movl	r5,*-4(fp)
	movpsl	r6
	mnegl	$PSL_N|PSL_Z,r7
	bicl2	r7,r6
	bisw2	r6,4(fp)
	jmp	_EMF_check_integer_overflow

	.globl	_EMFcvtrdl
	.align	2
_EMFcvtrdl:
	subl2	$8,sp
	movab	cvtdl_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKD(-12,r0,r1,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_dfloat
	tstl	r2
	jgeq	1f
	cmpw	r0,$0x80
	jeql	2f
	cmpw	r0,$0x180
	jeql	3f
1:	movl	r5,*-4(fp)
	movpsl	r6
	mnegl	$PSL_N|PSL_Z,r7
	bicl2	r7,r6
	bisw2	r6,4(fp)
	jmp	_EMF_check_integer_overflow
2:	incl	r5
	brb	4f
3:	decl	r5
4:	jvc	1b
	bisw2	$PSL_V,4(fp)
	jbr	1b

	.globl	_EMFcvtfd
	.align	2
_EMFcvtfd:
	subl2	$8,sp
	movab	cvtfd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movl	-8(fp),r0
	bicw2	$PSL_ALLCC,4(fp)
	bitw	$0x7F80,r0
	jeql	1f
	jbc	$15,r0,2f
	bisw2	$PSL_N,4(fp)
	jbr	2f
1:	jbs	$15,r0,3f
	bisw2	$PSL_Z,4(fp)
	clrl	r0		# canonicalise zero
2:	clrl	r1
	movq	r0,*-4(fp)
	jmp	_EMF_normal_return
3:	jmp	_EMF_reserved_operand_fault

	.globl	_EMFcvtdf
	.align	2
_EMFcvtdf:
	subl2	$12,sp
	movab	cvtdf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	UNPACKD(-12,r0,r1,r2)
	bneq	1f
	bisw2	$PSL_Z,4(fp)
	clrl	*-4(fp)
	jmp	_EMF_normal_return
1:	addl2	$0x80,r2
	bcc	1f
	ashl	$-1,r2,r2
	/* bisl2 $0x80000000,r2 don't need to set hidden bit, about to pack */
	incb	r0
	bcc	1f
	jmp	_EMF_floating_overflow_fault
1:	bbc	$8,r0,1f
	bisw2	$PSL_N,4(fp)
1:	movl	-4(fp),r3
	extzv	$24,$7,r2,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r2,r5
	movw	r4,(r3)
	movw	r5,2(r3)
	jmp	_EMF_normal_return

	.globl	_EMFemodd
	.align	2
_EMFemodd:
	subl2	$28,sp
	movab	emodd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	UNPACKD(-28,r0,r1,r2)
	bneq	1f
	/*
	 * Zero multiplier.  Out with zero result, but must check the
	 * multiplicand for reserved operand first.
	 */
	cmpzv	$7,$9,-16(fp),$0x100
	bneq	emodd_zero
	jmp	_EMF_reserved_operand_fault
1:	movb	-20(fp),r1	# pick up multiplier extension
	UNPACKD(-16,r3,r4,r5)
	bneq	1f
emodd_zero:
	bisw2	$PSL_Z,4(fp)
	clrl	*-8(fp)
	clrq	*-4(fp)
	jmp	_EMF_normal_return
1:	xorw3	r0,r3,r6
	movzbl	r0,r0
	movzbl	r3,r3
	bbc	$8,r6,1f
	bisl2	$0x10000,r0
1:	jsb	muld_core
	movq	r7,r1
	tstw	r0
	jleq	emodd_underflow
	cmpw	r0,$0xFF
	bleq	1f
	/* indicate floating overflow by integer overflow */
	bisw2	$PSL_Z|PSL_V,4(fp)
	clrl	*-8(fp)		# low part of huge integer is 0
	clrq	*-4(fp)		# fraction is 0
	jmp	_EMF_integer_overflow_return
1:	bbc	$16,r0,1f
	bisw2	$0x100,r0
1:	jsb	integerize_dfloat
	movl	r5,*-8(fp)
	tstw	r0
	bneq	1f
	clrq	*-4(fp)
	bisw2	$PSL_Z,4(fp)
	brb	2f
1:	bbc	$8,r0,1f
	bisw2	$PSL_N,4(fp)
1:	movl	-4(fp),r3
	extzv	$24,$7,r2,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r2,r5
	movw	r4,(r3)
	movw	r5,2(r3)
2:	jmp	_EMF_check_integer_overflow
emodd_underflow:
	bitw	$PSL_FU,4(fp)
	jeql	emodd_zero
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	emodd_zero
	jmp	_EMF_floating_underflow_fault

	.globl	_EMFpolyd
	.align	2
_EMFpolyd:
	bitl	$PSL_FPD,16(r1)
	jneq	polyd_fpd
	/* Initial entry processing */
	subl2	$16,sp
	movab	polyd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movq	-16(fp),r0
	cmpzv	$7,$9,r0,$0x100
	bneq	1f
2:	jmp	_EMF_reserved_operand_fault
1:	movl	-8(fp),r5	# zero-extended to longword by operand decoder
	cmpl	r5,$31
	jgtru	2b
	movl	-4(fp),r2
	movq	(r2)+,r3
	extzv	$7,$9,r3,r6
	bneq	3f
	clrq	r3
	brb	4f
3:	cmpl	r6,$0x100
	beql	2b
4:	movl	fp,sp		# don't need operands any more
	movq	r3,0x14(fp)
	movq	r0,0x24(fp)
	movl	r5,0x1C(fp)
	movl	r2,0x20(fp)
	subl3	0x50(fp),0x10(fp),r0
	movb	r0,0x1E(fp)
	jbr	polyd_main
polyd_fpd:
	movzbl	0x1E(fp),r0
	addl3	0x50(fp),r0,0x10(fp)
polyd_main:
	extzv	$7,$8,0x24(fp),r3
	jeql	polyd_zeroarg
	movl	$0x80000000,r5
	insv	0x24(fp),$24,$7,r5
	insv	0x26(fp),$8,$16,r5
	clrl	r4
	insv	0x28(fp),$24,$16,r4
	insv	0x2A(fp),$8,$16,r4
	clrq	r1
	extzv	$7,$9,0x14(fp),r0
	beql	polyd_mainloop
	cmpw	r0,$0x100
	bneq	1f
	jmp	_EMF_reserved_operand_fpd
1:	movl	$0x80000000,r2
	insv	0x14(fp),$24,$7,r2
	insv	0x16(fp),$8,$16,r2
	insv	0x18(fp),$24,$16,r1
	insv	0x1A(fp),$8,$16,r1
	bbc	$8,r0,polyd_mainloop
	bicw2	$0x100,r0
	bisl2	$0x10000,r0
polyd_mainloop:
	tstb	0x1C(fp)
	jeql	polyd_done
	/* Multiply accumulator by argument */
	tstw	r0
	jeql	polyd_add
	bbc	$15,0x24(fp),1f
	xorl2	$0x10000,r0
1:	jsb	muld_core
	movq	r7,r1
polyd_add:
	/* Add next coefficient */
	movq	*0x20(fp),r9
	clrl	r7
	extzv	$7,$9,r9,r6
	beql	1f
	cmpw	r6,$0x100
	bneq	3f
	jmp	_EMF_reserved_operand_fpd
3:	movl	$0x80000000,r8
	extzv	$0,$7,r9,r11
	insv	r11,$24,$7,r8
	extzv	$16,$16,r9,r11
	insv	r11,$8,$16,r8
	extzv	$16,$16,r10,r11
	insv	r10,$24,$16,r7
	insv	r11,$8,$16,r7
	brb	2f
1:	clrl	r8
2:	bbc	$8,r6,1f
	bicw2	$0x100,r6
	bisl2	$0x10000,r6
1:	tstw	r6
	jeql	polyd_check
	tstw	r0
	jneq	1f
	movl	r6,r0
	movq	r7,r1
	jbr	polyd_check
/* First equalise the exponents by shifting right the operand with lower exp */
1:	cmpw	r0,r6
	jeql	4f
	jgtru	3f
	subw3	r0,r6,r9
	movzwl	r9,r9
	subl3	r9,$63,r11
	jlssu	1f
	bicl2	$0x80000000,r2
	mnegl	r9,r10
	ashq	r10,r1,r1
	cmpl	r11,$32
	jgequ	5f
	jbcs	r11,r1,2f
5:	subl2	$32,r11
	jbcs	r11,r2,2f
1:	clrq	r1
2:	movw	r6,r0
	jbr	4f
3:	subw3	r6,r0,r9
	movzwl	r9,r9
	subl3	r9,$63,r11
	jlssu	1f
	bicl2	$0x80000000,r8
	mnegl	r9,r10
	ashq	r10,r7,r7
	cmpl	r11,$32
	jgequ	5f
	jbcs	r11,r7,2f
5:	subl2	$32,r11
	jbcs	r11,r8,2f
1:	clrq	r7
2:	movw	r0,r6
/* Now see if we need to add or subtract */
4:	cmpl	r0,r6	/* since exps are equalised this compares signs */
	jneq	polyd_dosub
	addl2	r7,r1
	adwc	r8,r2
	bcc	polyd_round
	ashq	$-1,r1,r1
	bisl2	$0x80000000,r2
	incw	r0
polyd_round:
	addl2	$0x80,r1
	adwc	$0,r2
	jcc	polyd_check
	ashq	$-1,r1,r1
	bisl2	$0x80000000,r2
	incw	r0
	jbr	polyd_check
polyd_dosub:
	cmpl	r2,r8
	jlssu	1f
	jgtru	3f
	cmpl	r1,r7
	jlssu	1f
	jgtru	3f
polyd_zeroafteradd:
	clrl	r0
	clrq	r1
	jbr	polyd_next
3:	subl2	r7,r1
	sbwc	r8,r2
	jbr	2f
1:	movl	r6,r0
	subl3	r1,r7,r1
	sbwc	r2,r8
	movl	r8,r2
2:	jlss	polyd_round			/* N means high bit set */
	decw	r0
	ashq	$1,r1,r1
	jbr	2b
polyd_underflow:
	bitw	$PSL_FU,4(fp)
	jeql	polyd_zeroafteradd
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	polyd_zeroafteradd
	jmp	_EMF_floating_underflow_fpd
polyd_check:
	/* Check for overflow and underflow */
1:	tstw	r0
	jleq	polyd_underflow
	cmpw	r0,$0xFF
	bleq	1f
	jmp	_EMF_floating_overflow_fpd
1:	clrb	r1
polyd_next:
	decb	0x1C(fp)
	addl2	$8,0x20(fp)
	extzv	$24,$7,r2,r6
	insv	r0,$7,$9,r6
	extzv	$8,$16,r2,r7
	extzv	$24,$16,r1,r8
	extzv	$8,$16,r1,r9
	movw	r6,0x14(fp)
	movw	r7,0x16(fp)
	movw	r8,0x18(fp)
	movw	r9,0x1A(fp)
	jbr	polyd_mainloop
polyd_done:
	clrl	0x1C(fp)
	clrq	0x24(fp)
	bicw2	$PSL_ALLCC,4(fp)
	movl	0x14(fp),r0
	bitw	$0x7F80,r0
	bneq	1f
	bisw2	$PSL_Z,4(fp)
1:	tstw	r0
	bgeq	1f
	bisw2	$PSL_N,4(fp)
1:	jmp	_EMF_normal_return
polyd_zeroarg:
	bbc	$15,0x24(fp),1f
	jmp	_EMF_reserved_operand_fpd
1:	movzbl	0x1C(fp),r0
	jeql	polyd_done
	decl	r0
	ashl	$3,r0,r0
	movl	0x20(fp),r1
	addl2	r0,r1
	movq	(r1)+,r2
	cmpzv	$7,$9,r2,$0x100
	bneq	1f
	movb	$1,0x1C(fp)
	subl3	$8,r1,0x20(fp)
	jmp	_EMF_reserved_operand_fpd
1:	movl	r1,0x20(fp)
	movq	r2,0x14(fp)
	jbr	polyd_done

	.globl	_EMFacbd
	.align	2
_EMFacbd:
	subl2	$28,sp
	movab	acbd_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKD(-12,r0,r1,r2)
	UNPACKD(-20,r3,r4,r5)
	bicw2	$PSL_N|PSL_Z|PSL_V,4(fp)
	jsb	do_addsubd
	clrb	r1
	UNPACKD(-28,r6,r7,r8)
	movl	-4(fp),r3
	extzv	$24,$7,r2,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r2,r5
	extzv	$24,$16,r1,r9
	extzv	$8,$16,r1,r10
	movw	r4,(r3)
	movw	r5,2(r3)
	movw	r9,4(r3)
	movw	r10,6(r3)
	movl	0x10(fp),r3
	cvtwl	(r3)+,r4
	clrl	r9
	xorl3	r0,r6,r5
	jbs	$8,r6,2f
	cmpb	r0,r6
	jlssu	1f
	jgtru	2f
	cmpl	r2,r8
	jlssu	1f
	jgtru	2f
	cmpl	r1,r7
	jlssu	1f
	jgtru	2f
	jbr	4f
1:	mcoml	r9,r9
2:	jbc	$8,r0,3f
	mcoml	r9,r9
3:	tstw	-20(fp)
	jgeq	3f
	mcoml	r9,r9
3:	tstl	r9
	jeql	5f
4:	addl2	r4,r3
5:	movl	r3,0x10(fp)
	jmp	_EMF_normal_return

/* Common subroutines used by multiple emulated instructions */

/* The following routine does most of the work of ADDD, also used by ACBD */
	.align	2
do_addsubd:
	tstw	r3
	jeql	addsubd_finish
	tstw	r0
	jneq	1f
	movl	r3,r0
	movq	r4,r1
	jbr	addsubd_finish
/* First equalise the exponents by shifting right the operand with lower exp */
1:	cmpb	r0,r3
	jeql	4f
	jgtru	3f
	subb3	r0,r3,r6
	movzbl	r6,r6
	subl3	r6,$63,r8
	jlssu	1f
	bicl2	$0x80000000,r2
	mnegl	r6,r7
	ashq	r7,r1,r1
	cmpl	r8,$32
	jgequ	5f
	jbcs	r8,r1,2f
5:	subl2	$32,r8
	jbcs	r8,r2,2f
1:	clrq	r1
2:	movb	r3,r0
	jbr	4f
3:	subb3	r3,r0,r6
	movzbl	r6,r6
	subl3	r6,$63,r8
	jlssu	1f
	bicl2	$0x80000000,r5
	mnegl	r6,r7
	ashq	r7,r4,r4
	cmpl	r8,$32
	jgequ	5f
	jbcs	r8,r4,2f
5:	subl2	$32,r8
	jbcs	r8,r5,2f
1:	clrq	r4
2:	movb	r0,r3
/* Now see if we need to add or subtract */
4:	cmpw	r0,r3	/* since exps are equalised this compares signs */
	jneq	dosubd
	addl2	r4,r1
	adwc	r5,r2
	bcc	addsubd_round
	ashq	$-1,r1,r1
	bisl2	$0x80000000,r2
	incb	r0
	bcc	addsubd_round
	jmp	_EMF_floating_overflow_fault
addsubd_round:
	addl2	$0x80,r1
	adwc	$0,r2
	bcc	addsubd_finish
	ashq	$-1,r1,r1
	bisl2	$0x80000000,r2
	incb	r0
	bcc	addsubd_finish
	jmp	_EMF_floating_overflow_fault
addsubd_finish:
	tstw	r0
	bneq	1f
addsubd_zero:
	bisw2	$PSL_Z,4(fp)
	clrl	r0
	clrq	r1
	rsb
1:	bbc	$8,r0,2f
	bisw2	$PSL_N,4(fp)
2:	rsb
dosubd:
	cmpl	r2,r5
	jlssu	1f
	jgtru	3f
	cmpl	r1,r4
	jlssu	1f
	jgtru	3f
	jbr	addsubd_zero
3:	subl2	r4,r1
	sbwc	r5,r2
	jbr	2f
1:	movl	r3,r0
	subl3	r1,r4,r1
	sbwc	r2,r5
	movl	r5,r2
2:	jlss	addsubd_round			/* N means high bit set */
	decb	r0
	jeql	3f				/* underflow */
	ashq	$1,r1,r1
	jbr	2b
3:	bitw	$PSL_FU,4(fp)
	jeql	addsubd_zero
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	addsubd_zero
	jmp	_EMF_floating_underflow_fault

	.align	2
muld_core:
	addw2	r3,r0
	subw2	$0x80,r0
	emul	r1,r4,$0,r7
	emul	r1,r5,$0,r6
	addl2	r1,r7
	emul	r2,r4,$0,r9
	addl2	r4,r10
	tstl	r1
	bgeq	1f
	addl2	r4,r8
	addl2	r5,r7
1:	tstl	r4
	bgeq	1f
	addl2	r1,r8
	addl2	r2,r10
1:	addl2	r8,r6
	adwc	$0,r7
	clrl	r8
	addl2	r9,r6
	adwc	r10,r7
	adwc	$0,r8
	emul	r2,r5,$0,r9
	addl2	r2,r10
	addl2	r5,r10
	addl2	r9,r7
	adwc	r10,r8
	blss	1f
	ashq	$1,r7,r7
	decw	r0
1:	rsb

	.align	2
integerize_dfloat:
	subb3	$0xC0,r0,r3
	jgtru	intd_wayoverflow
	jlssu	1f
	bisw2	$PSL_V,4(fp)
	movl	r1,r5
	clrb	r0
	clrq	r1
	jbr	intd_checkint
1:	subb3	$0xA0,r0,r3
	jgtru	intd_overflow
	jlssu	intd_checksmall
	movl	r2,r5
	movl	r1,r2
intd_fract32:
	clrl	r1
	tstl	r2
	bneq	1f
	clrb	r0
	jbr	intd_checkint
1:	movb	$0x80,r0
	tstl	r2
	jlss	intd_checkint
1:	decb	r0
	ashl	$1,r2,r2
	bgeq	1b
	jbr	intd_checkint
intd_checksmall:
	subb3	$0x80,r0,r4
	jlequ	intd_toosmall
	movzbl	r4,r4
	subl3	r4,$32,r3
	extzv	r3,r4,r2,r5
	ashq	r4,r1,r1
	bneq	1f
	clrb	r0
	jbr	intd_finishint
1:	movb	$0x80,r0
	tstl	r2
	jlss	intd_finishint
1:	decb	r0
	ashq	$1,r1,r1
	bgeq	1b
	jbr	intd_finishint
intd_toosmall:
	clrl	r5
	rsb
intd_overflow:
	bisw2	$PSL_V,4(fp)
	movzbl	r3,r3
	ashq	r3,r1,r4
	movl	r4,r2
	jbr	intd_fract32
intd_wayoverflow:
	bisw2	$PSL_V,4(fp)
	movzbl	r3,r3
	ashl	r3,r1,r5
	clrb	r0
	clrq	r1
	jbr	intd_finishint
intd_checkint:
	cmpl	r5,0x80000000
	jlssu	intd_finishint
	jgtru	1f
	jbs	$8,r0,intd_finishint
1:	bisw2	$PSL_V,4(fp)
intd_finishint:
	jbc	$8,r0,1f
	mnegl	r5,r5
	tstb	r0
	jneq	1f
	clrw	r0			# don't output reserved operand on -0
1:	rsb

#endif
E 1
