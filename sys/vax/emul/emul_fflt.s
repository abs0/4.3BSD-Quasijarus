/*
 * F-floating instruction emulator
 * Designed and written by Michael Sokolov
 *
 *	@(#)emul_fflt.s	7.3 (Berkeley) 2/3/04
 */

#include "../vax/cpucond.h"
#if EMULFFLT
#include "../vax/psl.h"
#include "../vax/emul/emul_opspec.h"
#include "../vax/emul/emul_funpack.h"

/* Operand specifications for _EMF_operand_decode */
arithf2_opspec:	.byte	TYPRF,SIZL,TYPM,SIZL,0
arithf3_opspec:	.byte	TYPRF,SIZL,TYPRF,SIZL,TYPW,SIZL,0
cmpf_opspec:	.byte	TYPRF,SIZL,TYPRF,SIZL,0
cvtbf_opspec:	.byte	TYPRI,SIZB,TYPW,SIZL,0
cvtwf_opspec:	.byte	TYPRI,SIZW,TYPW,SIZL,0
cvtlf_opspec:	.byte	TYPRI,SIZL,TYPW,SIZL,0
cvtfb_opspec:	.byte	TYPRF,SIZL,TYPW,SIZB,0
cvtfw_opspec:	.byte	TYPRF,SIZL,TYPW,SIZW,0
cvtfl_opspec:	.byte	TYPRF,SIZL,TYPW,SIZL,0
emodf_opspec:	.byte	TYPRF,SIZL,TYPRI,SIZB,TYPRF,SIZL,TYPW,SIZL,TYPW,SIZL,0
movf_opspec:	.byte	TYPRF,SIZL,TYPW,SIZL,0
polyf_opspec:	.byte	TYPRF,SIZL,TYPRI,SIZW,TYPA,SIZB,0
tstf_opspec:	.byte	TYPRF,SIZL,0
/* _EMF_operand_decode doesn't know about ACBx branch displacement */
acbf_opspec:	.byte	TYPRF,SIZL,TYPRF,SIZL,TYPM,SIZL,0

	.globl	_EMFtstf
	.align	2
_EMFtstf:
	subl2	$4,sp
	movab	tstf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movl	-4(fp),r0
	.globl	_EMF_tstfd_common
_EMF_tstfd_common:
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

	.globl	_EMFcmpf
	.align	2
_EMFcmpf:
	subl2	$8,sp
	movab	cmpf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKF(-8,r0,r2)
	UNPACKF(-4,r3,r5)
	bicw2	$PSL_ALLCC,4(fp)
	xorl3	r0,r3,r6
	jbs	$8,r6,cmpf_finish
	cmpb	r0,r3
	jlssu	cmpf_lss
	jgtru	cmpf_finish
	cmpl	r2,r5
	jlssu	cmpf_lss
	jgtru	cmpf_finish
	bisw2	$PSL_Z,4(fp)
	jbr	cmpf_out
cmpf_lss:
	bisw2	$PSL_N,4(fp)
cmpf_finish:
	jbc	$8,r0,cmpf_out
	xorw2	$PSL_N,4(fp)
cmpf_out:
	jmp	_EMF_normal_return

	.globl	_EMFmovf
	.align	2
_EMFmovf:
	subl2	$8,sp
	movab	movf_opspec,r0
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
2:	movl	r0,*-4(fp)
	jmp	_EMF_normal_return
3:	jmp	_EMF_reserved_operand_fault

	.globl	_EMFmnegf
	.align	2
_EMFmnegf:
	subl2	$8,sp
	movab	movf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movl	-8(fp),r0
	bicw2	$PSL_ALLCC,4(fp)
	bitw	$0x7F80,r0
	jeql	1f
	xorw2	$0x8000,r0
	jgeq	2f
	bisw2	$PSL_N,4(fp)
	jbr	2f
1:	jbs	$15,r0,3f
	bisw2	$PSL_Z,4(fp)
2:	movl	r0,*-4(fp)
	jmp	_EMF_normal_return
3:	jmp	_EMF_reserved_operand_fault

	.globl	_EMFaddf2
	.align	2
_EMFaddf2:
	subl2	$12,sp
	movab	arithf2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	addf_common

	.globl	_EMFaddf3
	.align	2
_EMFaddf3:
	subl2	$12,sp
	movab	arithf3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
addf_common:
	UNPACKF(-12,r0,r2)
addsubf_common:
	UNPACKF(-8,r3,r5)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	do_addsubf
	movl	-4(fp),r3
	extzv	$24,$7,r2,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r2,r5
	movw	r4,(r3)
	movw	r5,2(r3)
	jmp	_EMF_normal_return

	.globl	_EMFsubf2
	.align	2
_EMFsubf2:
	subl2	$12,sp
	movab	arithf2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	subf_common

	.globl	_EMFsubf3
	.align	2
_EMFsubf3:
	subl2	$12,sp
	movab	arithf3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
subf_common:
	UNPACKF(-12,r0,r2)
	jeql	addsubf_common
	xorw2	$0x100,r0
	jbr	addsubf_common

	.globl	_EMFmulf2
	.align	2
_EMFmulf2:
	subl2	$12,sp
	movab	arithf2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	mulf_common

	.globl	_EMFmulf3
	.align	2
_EMFmulf3:
	subl2	$12,sp
	movab	arithf3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
mulf_common:
	bicw2	$PSL_ALLCC,4(fp)
	UNPACKF(-12,r0,r2)
	bneq	1f
	/*
	 * Zero multiplicand.  Out with zero result, but must check the other
	 * operand for reserved first.
	 */
	cmpzv	$7,$9,-8(fp),$0x100
	bneq	muldivf_zero
	jmp	_EMF_reserved_operand_fault
1:	UNPACKF(-8,r3,r5)
	bneq	1f
muldivf_zero:
	bisw2	$PSL_Z,4(fp)
	clrl	*-4(fp)
	jmp	_EMF_normal_return
1:	xorw3	r0,r3,r6
	movzbl	r0,r0
	movzbl	r3,r3
	addw2	r3,r0
	subw2	$0x80,r0
	emul	r2,r5,$0,r7
	addl2	r2,r8
	addl2	r5,r8
	blss	muldivf_finish
	ashl	$1,r8,r8
	decw	r0
muldivf_finish:
	addl2	$0x80,r8
	bcc	1f
	ashl	$-1,r8,r8
	/* bisl2 $0x80000000,r8 don't need to set hidden bit, about to pack */
	incw	r0
1:	tstw	r0
	jleq	muldivf_underflow
	cmpw	r0,$0xFF
	bleq	1f
	jmp	_EMF_floating_overflow_fault
1:	bbc	$8,r6,1f
	bisw2	$0x100,r0
	bisw2	$PSL_N,4(fp)
1:	movl	-4(fp),r3
	extzv	$24,$7,r8,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r8,r5
	movw	r4,(r3)
	movw	r5,2(r3)
	jmp	_EMF_normal_return
muldivf_underflow:
	bitw	$PSL_FU,4(fp)
	jeql	muldivf_zero
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	muldivf_zero
	jmp	_EMF_floating_underflow_fault

	.globl	_EMFdivf2
	.align	2
_EMFdivf2:
	subl2	$12,sp
	movab	arithf2_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	jbr	divf_common

	.globl	_EMFdivf3
	.align	2
_EMFdivf3:
	subl2	$12,sp
	movab	arithf3_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
divf_common:
	bicw2	$PSL_ALLCC,4(fp)
	UNPACKF(-12,r0,r2)
	bneq	1f
	/*
	 * Zero divisor.  Out with devide by zero fault.  No need to check the
	 * dividend for reserved operand as VARM allows faults to occur in any
	 * order.
	 */
	jmp	_EMF_floating_divby0_fault
1:	UNPACKF(-8,r3,r5)
	jeql	muldivf_zero
	xorw3	r0,r3,r6
	movzbl	r0,r0
	movzbl	r3,r3
	subw2	r0,r3
	addw3	$129,r3,r0
	movl	$31,r3
	clrl	r8
1:	cmpl	r2,r5
	bgtru	3f
2:	subl2	r2,r5
	bbss	r3,r8,3f
3:	decl	r3
	cmpl	r3,$6
	blssu	4f
	ashl	$1,r5,r5
	bcs	2b
	brb	1b
4:	tstl	r8
	jlss	muldivf_finish
	ashl	$1,r8,r8
	decw	r0
	jbr	muldivf_finish

	.globl	_EMFcvtbf
	.align	2
_EMFcvtbf:
	subl2	$8,sp
	movab	cvtbf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	movw	$0x88,r1
	movb	-8(fp),r0
	jeql	cvtif_zero
	bgeq	1f
	mnegb	r0,r0
	bisw2	$0x100,r1
	bisw2	$PSL_N,4(fp)
1:	ashl	$24,r0,r0
cvtif_finish:
	tstl	r0
	blss	2f
1:	decb	r1
	ashl	$1,r0,r0
	bgeq	1b
2:	addl2	$0x80,r0
	bcc	3f
	ashl	$-1,r0,r0
	/* bisl2 $0x80000000,r0 don't need to set hidden bit, about to pack */
	incb	r1
3:	movl	-4(fp),r3
	extzv	$24,$7,r0,r4
	insv	r1,$7,$9,r4
	extzv	$8,$16,r0,r5
	movw	r4,(r3)
	movw	r5,2(r3)
	jmp	_EMF_normal_return
cvtif_zero:
	bisw2	$PSL_Z,4(fp)
	clrl	*-4(fp)
	jmp	_EMF_normal_return

	.globl	_EMFcvtwf
	.align	2
_EMFcvtwf:
	subl2	$8,sp
	movab	cvtwf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	movw	$0x90,r1
	movw	-8(fp),r0
	jeql	cvtif_zero
	bgeq	1f
	mnegw	r0,r0
	bisw2	$0x100,r1
	bisw2	$PSL_N,4(fp)
1:	ashl	$16,r0,r0
	jbr	cvtif_finish

	.globl	_EMFcvtlf
	.align	2
_EMFcvtlf:
	subl2	$8,sp
	movab	cvtlf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	movw	$0xA0,r1
	movl	-8(fp),r0
	jeql	cvtif_zero
	jgeq	cvtif_finish
	mnegl	r0,r0
	bisw2	$0x100,r1
	bisw2	$PSL_N,4(fp)
	jbr	cvtif_finish

	.globl	_EMFcvtfb
	.align	2
_EMFcvtfb:
	subl2	$8,sp
	movab	cvtfb_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKF(-8,r0,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_ffloat
	cvtlb	r5,*-4(fp)
	movpsl	r6
	mnegl	$PSL_N|PSL_Z|PSL_V,r7
	bicl2	r7,r6
	bisw2	r6,4(fp)
	jmp	_EMF_check_integer_overflow

	.globl	_EMFcvtfw
	.align	2
_EMFcvtfw:
	subl2	$8,sp
	movab	cvtfw_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKF(-8,r0,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_ffloat
	cvtlw	r5,*-4(fp)
	movpsl	r6
	mnegl	$PSL_N|PSL_Z|PSL_V,r7
	bicl2	r7,r6
	bisw2	r6,4(fp)
	jmp	_EMF_check_integer_overflow

	.globl	_EMFcvtfl
	.align	2
_EMFcvtfl:
	subl2	$8,sp
	movab	cvtfl_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKF(-8,r0,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_ffloat
	movl	r5,*-4(fp)
	movpsl	r6
	mnegl	$PSL_N|PSL_Z,r7
	bicl2	r7,r6
	bisw2	r6,4(fp)
	jmp	_EMF_check_integer_overflow

	.globl	_EMFcvtrfl
	.align	2
_EMFcvtrfl:
	subl2	$8,sp
	movab	cvtfl_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKF(-8,r0,r2)
	bicw2	$PSL_ALLCC,4(fp)
	jsb	integerize_ffloat
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

	.globl	_EMFemodf
	.align	2
_EMFemodf:
	subl2	$20,sp
	movab	emodf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	bicw2	$PSL_ALLCC,4(fp)
	UNPACKF(-20,r0,r2)
	bneq	1f
	/*
	 * Zero multiplier.  Out with zero result, but must check the
	 * multiplicand for reserved operand first.
	 */
	cmpzv	$7,$9,-12(fp),$0x100
	bneq	emodf_zero
	jmp	_EMF_reserved_operand_fault
1:	movb	-16(fp),r2	# pick up multiplier extension
	UNPACKF(-12,r3,r5)
	bneq	1f
emodf_zero:
	bisw2	$PSL_Z,4(fp)
	clrl	*-8(fp)
	clrl	*-4(fp)
	jmp	_EMF_normal_return
1:	xorw3	r0,r3,r6
	clrb	r6
	movzbl	r0,r0
	movzbl	r3,r3
	addw2	r3,r0
	subw2	$0x80,r0
	emul	r2,r5,$0,r7
	addl2	r2,r8
	addl2	r5,r8
	blss	1f
	ashl	$1,r8,r8
	decw	r0
1:	movl	r8,r2
	tstw	r0
	jleq	emodf_underflow
	cmpw	r0,$0xFF
	bleq	1f
	/* indicate floating overflow by integer overflow */
	bisw2	$PSL_Z|PSL_V,4(fp)
	clrl	*-8(fp)		# low part of huge integer is 0
	clrl	*-4(fp)		# fraction is 0
	jmp	_EMF_integer_overflow_return
1:	bisw2	r6,r0
	jsb	integerize_ffloat
	movl	r5,*-8(fp)
	tstw	r0
	bneq	1f
	clrl	*-4(fp)
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
emodf_underflow:
	bitw	$PSL_FU,4(fp)
	jeql	emodf_zero
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	emodf_zero
	jmp	_EMF_floating_underflow_fault

	.globl	_EMFpolyf
	.align	2
_EMFpolyf:
	bitl	$PSL_FPD,16(r1)
	jneq	polyf_fpd
	/* Initial entry processing */
	subl2	$12,sp
	movab	polyf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	movl	-12(fp),r0
	cmpzv	$7,$9,r0,$0x100
	bneq	1f
2:	jmp	_EMF_reserved_operand_fault
1:	movl	-8(fp),r1	# zero-extended to longword by operand decoder
	cmpl	r1,$31
	jgtru	2b
	movl	-4(fp),r2
	movl	(r2)+,r3
	extzv	$7,$9,r3,r4
	bneq	3f
	clrl	r3
	brb	4f
3:	cmpl	r4,$0x100
	beql	2b
4:	movl	fp,sp		# don't need operands any more
	movl	r3,0x14(fp)
	movl	r0,0x18(fp)
	movl	r1,0x1C(fp)
	movl	r2,0x20(fp)
	subl3	0x50(fp),0x10(fp),r0
	movb	r0,0x1E(fp)
	jbr	polyf_main
polyf_fpd:
	movzbl	0x1E(fp),r0
	addl3	0x50(fp),r0,0x10(fp)
polyf_main:
	extzv	$7,$8,0x18(fp),r3
	jeql	polyf_zeroarg
	movl	$0x80000000,r5
	insv	0x18(fp),$24,$7,r5
	insv	0x1A(fp),$8,$16,r5
	clrl	r2
	extzv	$7,$9,0x14(fp),r0
	beql	polyf_mainloop
	cmpw	r0,$0x100
	bneq	1f
	jmp	_EMF_reserved_operand_fpd
1:	movl	$0x80000000,r2
	insv	0x14(fp),$24,$7,r2
	insv	0x16(fp),$8,$16,r2
	bbc	$8,r0,polyf_mainloop
	bicw2	$0x100,r0
	bisl2	$0x10000,r0
polyf_mainloop:
	tstb	0x1C(fp)
	jeql	polyf_done
	/* Multiply accumulator by argument */
	tstw	r0
	jeql	polyf_add
	bbc	$15,0x18(fp),1f
	xorl2	$0x10000,r0
1:	addw2	r3,r0
	subw2	$0x80,r0
	emul	r2,r5,$0,r7
	addl2	r2,r8
	addl2	r5,r8
	blss	1f
	ashl	$1,r8,r8
	decw	r0
1:	movl	r8,r2
polyf_add:
	/* Add next coefficient */
	movl	*0x20(fp),r9
	extzv	$7,$9,r9,r6
	beql	1f
	cmpw	r6,$0x100
	bneq	3f
	jmp	_EMF_reserved_operand_fpd
3:	extzv	$0,$7,r9,r10
	extzv	$16,$16,r9,r11
	movl	$0x80000000,r8
	insv	r10,$24,$7,r8
	insv	r11,$8,$16,r8
	brb	2f
1:	clrl	r8
2:	bbc	$8,r6,1f
	bicw2	$0x100,r6
	bisl2	$0x10000,r6
1:
/* First equalise the exponents by shifting right the operand with lower exp */
	cmpw	r0,r6
	jeql	4f
	jgtru	3f
	subw3	r0,r6,r9
	movzwl	r9,r9
	subl3	r9,$32,r10
	blequ	1f
	extzv	r9,r10,r2,r2
	brb	2f
1:	clrl	r2
2:	movw	r6,r0
	jbr	4f
3:	subw3	r6,r0,r9
	movzbl	r9,r9
	subl3	r9,$32,r10
	blequ	1f
	extzv	r9,r10,r8,r8
	brb	2f
1:	clrl	r8
2:	movw	r0,r6
/* Now see if we need to add or subtract */
4:	cmpl	r0,r6	/* since exps are equalised this compares signs */
	jneq	polyf_dosub
	addl2	r8,r2
	bcc	polyf_round
	ashl	$-1,r2,r2
	bisl2	$0x80000000,r2
	incw	r0
polyf_round:
	addl2	$0x80,r2
	jcc	polyf_check
	ashl	$-1,r2,r2
	bisl2	$0x80000000,r2
	incw	r0
	jbr	polyf_check
polyf_dosub:
	cmpl	r2,r8
	jlssu	1f
	jgtru	3f
polyf_zeroafteradd:
	clrl	r0
	clrl	r2
	jbr	polyf_next
3:	subl2	r8,r2
	jbr	2f
1:	movl	r6,r0
	subl3	r2,r8,r2
2:	jlss	polyf_round			/* N means high bit set */
	decw	r0
	ashl	$1,r2,r2
	jbr	2b
polyf_underflow:
	bitw	$PSL_FU,4(fp)
	jeql	polyf_zeroafteradd
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	polyf_zeroafteradd
	jmp	_EMF_floating_underflow_fpd
polyf_check:
	/* Check for overflow and underflow */
1:	tstw	r0
	jleq	polyf_underflow
	cmpw	r0,$0xFF
	bleq	1f
	jmp	_EMF_floating_overflow_fpd
1:	clrb	r2
polyf_next:
	decb	0x1C(fp)
	addl2	$4,0x20(fp)
	extzv	$24,$7,r2,r6
	insv	r0,$7,$9,r6
	extzv	$8,$16,r2,r7
	movw	r6,0x14(fp)
	movw	r7,0x16(fp)
	jbr	polyf_mainloop
polyf_done:
	clrq	0x18(fp)
	bicw2	$PSL_ALLCC,4(fp)
	movl	0x14(fp),r0
	bitw	$0x7F80,r0
	bneq	1f
	bisw2	$PSL_Z,4(fp)
1:	tstw	r0
	bgeq	1f
	bisw2	$PSL_N,4(fp)
1:	jmp	_EMF_normal_return
polyf_zeroarg:
	bbc	$15,0x18(fp),1f
	jmp	_EMF_reserved_operand_fpd
1:	movzbl	0x1C(fp),r0
	jeql	polyf_done
	decl	r0
	ashl	$2,r0,r0
	movl	0x20(fp),r1
	addl2	r0,r1
	movl	(r1)+,r2
	cmpzv	$7,$9,r2,$0x100
	bneq	1f
	movb	$1,0x1C(fp)
	subl3	$4,r1,0x20(fp)
	jmp	_EMF_reserved_operand_fpd
1:	movl	r1,0x20(fp)
	movl	r2,0x14(fp)
	jbr	polyf_done

	.globl	_EMFacbf
	.align	2
_EMFacbf:
	subl2	$16,sp
	movab	acbf_opspec,r0
	movl	sp,r1
	jsb	_EMF_operand_decode
	UNPACKF(-8,r0,r2)
	UNPACKF(-12,r3,r5)
	bicw2	$PSL_N|PSL_Z|PSL_V,4(fp)
	jsb	do_addsubf
	clrb	r2
	UNPACKF(-16,r6,r8)
	movl	-4(fp),r3
	extzv	$24,$7,r2,r4
	insv	r0,$7,$9,r4
	extzv	$8,$16,r2,r5
	movw	r4,(r3)
	movw	r5,2(r3)
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
	jbr	4f
1:	mcoml	r9,r9
2:	jbc	$8,r0,3f
	mcoml	r9,r9
3:	tstw	-12(fp)
	jgeq	3f
	mcoml	r9,r9
3:	tstl	r9
	jeql	5f
4:	addl2	r4,r3
5:	movl	r3,0x10(fp)
	jmp	_EMF_normal_return

/* Common subroutines used by multiple emulated instructions */

/* The following routine does most of the work of ADDF, also used by ACBF */
	.align	2
do_addsubf:
/* First equalise the exponents by shifting right the operand with lower exp */
	cmpb	r0,r3
	jeql	4f
	jgtru	3f
	subb3	r0,r3,r6
	movzbl	r6,r6
	subl3	r6,$32,r7
	blequ	1f
	extzv	r6,r7,r2,r2
	brb	2f
1:	clrl	r2
2:	movb	r3,r0
	jbr	4f
3:	subb3	r3,r0,r6
	movzbl	r6,r6
	subl3	r6,$32,r7
	blequ	1f
	extzv	r6,r7,r5,r5
	brb	2f
1:	clrl	r5
2:	movb	r0,r3
/* Now see if we need to add or subtract */
4:	cmpw	r0,r3	/* since exps are equalised this compares signs */
	jneq	dosubf
	addl2	r5,r2
	bcc	addsubf_round
	ashl	$-1,r2,r2
	bisl2	$0x80000000,r2
	incb	r0
	bcc	addsubf_round
	jmp	_EMF_floating_overflow_fault
addsubf_round:
	addl2	$0x80,r2
	bcc	addsubf_finish
	ashl	$-1,r2,r2
	bisl2	$0x80000000,r2
	incb	r0
	bcc	addsubf_finish
	jmp	_EMF_floating_overflow_fault
addsubf_finish:
	tstw	r0
	bneq	1f
addsubf_zero:
	bisw2	$PSL_Z,4(fp)
	clrl	r0
	clrl	r2
	rsb
1:	bbc	$8,r0,2f
	bisw2	$PSL_N,4(fp)
2:	rsb
dosubf:
	cmpl	r2,r5
	jlssu	1f
	jgtru	3f
	jbr	addsubf_zero
3:	subl2	r5,r2
	jbr	2f
1:	movl	r3,r0
	subl3	r2,r5,r2
2:	jlss	addsubf_round			/* N means high bit set */
	decb	r0
	jeql	3f				/* underflow */
	ashl	$1,r2,r2
	jbr	2b
3:	bitw	$PSL_FU,4(fp)
	jeql	addsubf_zero
	movpsl	r6
	bitl	$PSL_CURMOD,r6
	jeql	addsubf_zero
	jmp	_EMF_floating_underflow_fault

	.align	2
integerize_ffloat:
	subb3	$0xA0,r0,r3
	jgtru	intf_overflow
	jlssu	1f
	movl	r2,r5
	clrb	r0
	clrl	r2
	jbr	intf_checkint
1:	subb3	$0x80,r0,r4
	jlequ	intf_toosmall
	movzbl	r4,r4
	subl3	r4,$32,r3
	extzv	r3,r4,r2,r5
	ashl	r4,r2,r2
	bneq	1f
	clrb	r0
	jbr	intf_finishint
1:	movb	$0x80,r0
	tstl	r2
	jlss	intf_finishint
1:	decb	r0
	ashl	$1,r2,r2
	bgeq	1b
	jbr	intf_finishint
intf_toosmall:
	clrl	r5
	rsb
intf_overflow:
	bisw2	$PSL_V,4(fp)
	movzbl	r3,r3
	ashl	r3,r2,r5
	clrb	r0
	clrl	r2
	jbr	intf_finishint
intf_checkint:
	cmpl	r5,0x80000000
	jlssu	intf_finishint
	jgtru	1f
	jbs	$8,r0,intf_finishint
1:	bisw2	$PSL_V,4(fp)
intf_finishint:
	jbc	$8,r0,1f
	mnegl	r5,r5
	tstb	r0
	jneq	1f
	clrw	r0			# don't output reserved operand on -0
1:	rsb

#endif
