/*
 * Operand specifier decoding for instruction emulation without microcode
 * assistance.  Used by the floating point instruction emulator.
 * Written by Michael Sokolov.
 *
 *	@(#)emul_opspec.s	7.3 (Berkeley) 2011/10/17
 */

#include "../vax/cpucond.h"
#if EMULFFLT || EMULDFLT || EMULGFLT || EMULHFLT
#define	LOCORE
#include "signal.h"
#include "../vax/trap.h"
#include "../vax/psl.h"
#include "../vax/emul/emul_opspec.h"
#define	PANIC(msg)	pushab 0f; calls $1,_panic; 0: .asciz msg

/*
 * The following routine decodes the operands of an instruction per operand
 * specification provided by the caller.  The specification is a string of bytes
 * encoding the type and size of each operand.  We support read, modify, write,
 * and address access types and byte, word, longword, and quadword sizes.  We do
 * not need to distinguish between integral and floating point operands except
 * when converting short literals into full-sized read operands.  We handle this
 * by creating two different read operand types, read integral and read
 * floating.  (Literal operands are allowed only for read access type.)
 *
 * Operand decoding is done per VAX-11 Architecture Reference Manual, Revision
 * 6.1 1982-05-20 section 3.7.
 *
 * We store the decoded operands into a buffer provided by the caller, in which
 * each decoded operand takes up some fixed whole number of longwords (fixed for
 * a given operand position in a given instruction).  For read operands the
 * value is stored as one longword for byte, word, and longword operands and as
 * two longwords for quadword operands.  (Byte and word operands are zero-
 * extended to longword.)  For modify operands the value is stored followed by
 * address.  For write and address operands only the address is stored.
 * Addresses may point into the register file in the emulator stack frame.
 *
 * Operand specifiers which are required to cause a reserved addressing mode
 * fault are caught and the fault is generated automatically, without returning
 * control to the caller.  VARM specifies PC, (PC), and -(PC) as UNPREDICTABLE.
 * We generate a reserved addressing mode fault for operands reading or writing
 * PC, either directly or as second half of a quadword.  We make no special
 * checks for (PC) or -(PC).  (The UNPREDICTABLE definition allows us to save
 * time by omitting the checks.)  Reading or writing (PC) will result in reading
 * or writing over the beginning of the instruction opcode and the next operand
 * will be sought the next byte after the (PC) specifier byte.  If a -(PC)
 * operand is used, our notion of the instruction start PC will be screwed up.
 * Operand specifier decoding will continue with the byte following the -(PC)
 * specifier byte.  If no faults occur subsequently the instruction will be
 * emulated normally and control will return to the next instruction.  If a
 * fault occurs subsequently, however, _EMF_operand_backup (see below) will go
 * south, and the contents of the register file and PC on the fault will be
 * UNPREDICTABLE.
 *
 * Autoincrement and autodecrement operands will alter the register file in the
 * frame as they are processed.  If a fault occurs subsequently these
 * autoincrements and autodecrements will need to be undone to back up the
 * instruction to the beginning.  This is done by the _EMF_operand_backup
 * routine below using the same operand specification.  In order to allow fault
 * generation and instruction backup to be performed at any point in the
 * emulation, including in the middle of operand decoding (needed for reserved
 * addressing mode faults), we maintain a count in AP of how many operand
 * specifiers we have already processed, and only this many operands will have
 * their autoincrements and autodecrements reversed by _EMF_operand_backup.  We
 * also save the starting address of the operand specification in R11 for the
 * duration of the emulation so it's available to _EMF_operand_backup.
 *
 * This routine must be called with:
 *
 * R0 - points to the operand specification
 * R1 - points to the decoded operand buffer
 * FP - points to the emulator stack frame
 *
 * On return the buffer is filled with decoded operands, the return PC field in
 * the frame is filled in with the next instruction address, and AP contains the
 * total number of operands.  If any operand writes to SP the X bit is set in
 * the frame.
 *
 * This routine is allowed to freely use and not preserve R0-R10.
 *
 * Register usage inside this routine is:
 *
 * R0 - advancing pointer in the operand specification
 * R1 - advancing pointer in the decoded operand buffer
 * R2 - advancing pointer in the instruction opcode
 * R3 - current operand type from the operand specification
 * R4 - current operand size from the operand specification as power of 2
 * R5 - current operand size in bytes
 * R6 - current operand specifier byte
 * R7 - points to the index reg in the regfile if indexed, 0 otherwise
 * R8 - will contain the operand address at the convergence of diff addr modes
 * R10 - points at the beginning of the register file in the frame
 * R11 - saved starting address of the operand specification
 *
 * We have two entry points: one for single-byte F/D instructions,
 * the other for double-byte G/H ones.
 */

	.globl	_EMF_operand_decode
	.globl	_EMF_operand_decode_gh
	.align	2
_EMF_operand_decode_gh:
	addl3	0x50(fp),$2,r2		/* current operand specifier ptr */
	brb	1f

	.align	2
_EMF_operand_decode:
	/* Initialise before the loop */
	addl3	0x50(fp),$1,r2		/* current operand specifier ptr */
1:	clrl	ap
	moval	0x14(fp),r10
	movl	r0,r11
opdec_loop:
	movzbl	(r0)+,r3		/* operand type */
	jeql	opdec_done
	movzbl	(r0)+,r4		/* operand size as power of 2 */
	ashl	r4,$1,r5		/* operand size in bytes */
	clrl	r7			/* if index will point to reg in file */
opdec_indexloop:
	movb	(r2)+,r6		/* fetch the operand specifier byte */
	extzv	$4,$4,r6,r8		/* get addressing mode */
	casel	r8,$0,$15
0:	.word	opdec_literal-0b
	.word	opdec_literal-0b
	.word	opdec_literal-0b
	.word	opdec_literal-0b
	.word	opdec_index-0b
	.word	opdec_reg-0b
	.word	opdec_regdef-0b
	.word	opdec_autodec-0b
	.word	opdec_autoinc-0b
	.word	opdec_autoincdef-0b
	.word	opdec_bdisp-0b
	.word	opdec_bdispdef-0b
	.word	opdec_wdisp-0b
	.word	opdec_wdispdef-0b
	.word	opdec_ldisp-0b
	.word	opdec_ldispdef-0b
opdec_literal:
	tstl	r7			/* reserved addr mode if indexed */
	jneq	_EMF_reserved_addrmode_fault
	extzv	$0,$6,r6,r6		/* isolate the literal */
	casel	r3,$1,$6
0:	.word	1f-0b			/* integral literal */
	.word	2f-0b			/* F/D floating literal */
	.word	3f-0b			/* G-float literal */
	.word	4f-0b			/* H-float literal */
	.word	_EMF_reserved_addrmode_fault-0b	/* modify */
	.word	_EMF_reserved_addrmode_fault-0b	/* write */
	.word	_EMF_reserved_addrmode_fault-0b	/* address */
1:	movl	r6,(r1)+
	brb	6f
2:	ashl	$4,r6,r6
	brb	5f
3:	ashl	$1,r6,r6
	brb	5f
4:	rotl	$-3,r6,r6
5:	bisl3	$0x4000,r6,(r1)+
6:	cmpl	r5,$8			/* quadword? */
	jlssu	opdec_next
	clrl	(r1)+			/* zero high longword if so */
	cmpl	r5,$16			/* handle octawords too */
	jlssu	opdec_next
	clrq	(r1)+
	jbr	opdec_next
opdec_index:
	tstl	r7			/* cannot nest */
	jneq	_EMF_reserved_addrmode_fault
	extzv	$0,$4,r6,r6		/* isolate register */
	cmpl	r6,$15			/* PC must fault */
	jeql	_EMF_reserved_addrmode_fault
	moval	(r10)[r6],r7
	jbr	opdec_indexloop
opdec_reg:
	tstl	r7			/* reserved addr mode if indexed */
	jneq	_EMF_reserved_addrmode_fault
	cmpl	r3,$TYPA		/* ditto if access type address */
	jeql	_EMF_reserved_addrmode_fault
	extzv	$0,$4,r6,r6		/* isolate register */
	moval	(r10)[r6],r8
	/* we've got the address, but we also need to check for writes to SP */
	/* can block PC at the same time */
	/* this depends on the operand size (different for quadword) */
	cmpl	r5,$8
	jgequ	1f
	cmpl	r6,$14
	jeql	2f			/* SP, check for write */
	jgtru	_EMF_reserved_addrmode_fault	/* PC */
	jbr	opdec_haveaddr
1:	jeql	1f			/* quadword, not octaword */
	/* handle octaword */
	cmpl	r6,$11
	jeql	2f			/* spills into SP, check for write */
	jgtru	_EMF_reserved_addrmode_fault	/* PC or spilling into PC */
	jbr	opdec_haveaddr
	/* handle quadword */
1:	cmpl	r6,$13
	jeql	2f			/* spills into SP, check for write */
	jgtru	_EMF_reserved_addrmode_fault	/* PC or SP spilling into PC */
	jbr	opdec_haveaddr
2:	cmpl	r3,$TYPW
	jeql	3f
	cmpl	r4,$TYPM
	jneq	opdec_haveaddr
	/* Write into SP. Set X flag unless in kernel, in which case panic. */
3:	movpsl	r9
	bitl	$PSL_CURMOD,r9
	jneq	4f
	PANIC("emulated instruction write into SP in kernel");
4:	bisl2	$0x1000,6(fp)
	jbr	opdec_haveaddr
opdec_regdef:
	extzv	$0,$4,r6,r6		/* isolate register */
	movl	(r10)[r6],r8
	jbr	opdec_havebase
opdec_autodec:
	extzv	$0,$4,r6,r6		/* isolate register */
	subl2	r5,(r10)[r6]
	movl	(r10)[r6],r8
	jbr	opdec_havebase
opdec_autoinc:
	extzv	$0,$4,r6,r6		/* isolate register */
	cmpl	r6,$15
	jeql	1f			/* immediate */
	movl	(r10)[r6],r8
	addl2	r5,(r10)[r6]
	jbr	opdec_havebase
1:	movl	r2,r8
	addl2	r5,r2
	jbr	opdec_havebase
opdec_autoincdef:
	extzv	$0,$4,r6,r6		/* isolate register */
	cmpl	r6,$15
	jeql	1f			/* absolute */
	movl	(r10)[r6],r9
	movl	(r9)+,r8
	movl	r9,(r10)[r6]
	jbr	opdec_havebase
1:	movl	(r2)+,r8
	jbr	opdec_havebase
opdec_bdisp:
	cvtbl	(r2)+,r9
	jbr	1f
opdec_wdisp:
	cvtwl	(r2)+,r9
	jbr	1f
opdec_ldisp:
	movl	(r2)+,r9
1:	cmpl	r6,$15
	jeql	2f			/* relative */
	addl3	(r10)[r6],r9,r8
	jbr	opdec_havebase
2:	addl3	r2,r9,r8
	jbr	opdec_havebase
opdec_bdispdef:
	cvtbl	(r2)+,r9
	jbr	1f
opdec_wdispdef:
	cvtwl	(r2)+,r9
	jbr	1f
opdec_ldispdef:
	movl	(r2)+,r9
1:	cmpl	r6,$15
	jeql	2f			/* relative */
	addl2	(r10)[r6],r9
	movl	(r9),r8
	jbr	opdec_havebase
2:	addl2	r2,r9
	movl	(r9),r8
opdec_havebase:
	tstl	r7
	jeql	opdec_haveaddr
	movl	(r7),r9
	ashl	r4,r9,r9
	addl2	r9,r8
opdec_haveaddr:
	/* We've got the operand address. What we store depends on the type. */
	cmpl	r3,$TYPM
	jgtru	opdec_storeaddr
	casel	r4,$0,$4		/* how we store depends on its size */
0:	.word	1f-0b			/* byte */
	.word	2f-0b			/* word */
	.word	3f-0b			/* longword */
	.word	4f-0b			/* quadword */
	.word	6f-0b			/* octaword */
1:	movzbl	(r8),(r1)+
	jbr	5f
2:	movzwl	(r8),(r1)+
	jbr	5f
3:	movl	(r8),(r1)+
	jbr	5f
4:	movq	(r8),(r1)+
	jbr	5f
6:	movq	(r8),(r1)+
	movq	8(r8),(r1)+
5:	cmpl	r3,$TYPM		/* need address too? */
	jneq	opdec_next
opdec_storeaddr:
	movl	r8,(r1)+
opdec_next:
	incl	ap
	jbr	opdec_loop
opdec_done:
	movl	r2,0x10(fp)
	rsb

/*
 * The following routine backs up the instruction by reversing all
 * autoincrements and autodecrements done by _EMF_operand_decode.  We repeat the
 * parsing of operand specifiers, and we use the same operand specification used
 * by _EMF_operand_decode (so we know the operand sizes).  We skip over all
 * operands except those using autoincrement, autoincrement deferred, and
 * autodecrement modes.  For autoincrement we DECREMENT the register by the
 * operand size.  For autoincrement deferred we decrement the register by 4.
 * For autodecrement we INCREMENT the register by the operand size.
 *
 * No stringent checks are done because this routine passes over the same
 * operand specifiers that _EMF_operand_decode has already successfully decoded
 * and validated.  If you fool this routine by having a signal handler
 * interrupting change the code, or by throwing it off with a -(PC) operand,
 * results are UNPREDICTABLE.
 *
 * This routine relies on R11 pointing to the operand specification, AP
 * containing the number of operands successfully processed by
 * _EMF_operand_decode, and FP pointing to the emulator frame.
 *
 * R0, R2-R6, R8, and R10 are used similarly to _EMF_operand_decode.
 */
	.globl	_EMF_operand_backup
_EMF_operand_backup:
	/* Initialise before the loop */
	movl	0x50(fp),r2
	cmpb	(r2)+,$0xFD
	bneq	1f
	incl	r2
1:	moval	0x14(fp),r10
	movl	r11,r0
opback_loop:
	tstl	ap
	jeql	opback_done
	movzbl	(r0)+,r3		/* operand type */
	jeql	opback_done
	movzbl	(r0)+,r4		/* operand size as power of 2 */
	ashl	r4,$1,r5		/* operand size in bytes */
opback_indexloop:
	movb	(r2)+,r6		/* fetch the operand specifier byte */
	extzv	$4,$4,r6,r8		/* get addressing mode */
	casel	r8,$0,$15
0:	.word	opback_next-0b
	.word	opback_next-0b
	.word	opback_next-0b
	.word	opback_next-0b
	.word	opback_indexloop-0b
	.word	opback_next-0b
	.word	opback_next-0b
	.word	opback_autodec-0b
	.word	opback_autoinc-0b
	.word	opback_autoincdef-0b
	.word	opback_skipb-0b
	.word	opback_skipb-0b
	.word	opback_skipw-0b
	.word	opback_skipw-0b
	.word	opback_skipl-0b
	.word	opback_skipl-0b
opback_autodec:
	extzv	$0,$4,r6,r6		/* isolate register */
	addl2	r5,(r10)[r6]
	jbr	opback_next
opback_autoinc:
	extzv	$0,$4,r6,r6		/* isolate register */
	cmpl	r6,$15
	jeql	1f			/* immediate */
	subl2	r5,(r10)[r6]
	jbr	opback_next
1:	addl2	r5,r2
	jbr	opback_next
opback_autoincdef:
	extzv	$0,$4,r6,r6		/* isolate register */
	cmpl	r6,$15
	jeql	opback_skipl		/* absolute */
	subl2	$4,(r10)[r6]
	jbr	opback_next
opback_skipb:
	addl2	$1,r2
	jbr	opback_next
opback_skipw:
	addl2	$2,r2
	jbr	opback_next
opback_skipl:
	addl2	$4,r2
opback_next:
	decl	ap
	jbr	opback_loop
opback_done:
	rsb

	.globl	_EMF_reserved_addrmode_fault
_EMF_reserved_addrmode_fault:
	movpsl	r0
	bitl	$PSL_CURMOD,r0
	jneq	1f
	PANIC("emulated instruction reserved addressing mode in kernel")
1:	jsb	_EMF_operand_backup
	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	movl	$SIGILL,0x4C(fp)
	movl	$T_RESADFLT,0x50(fp)
	jmp	_EMF_sigemu

#endif
