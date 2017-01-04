/*
 * Reserved instruction fault handling for the emulator.  This module contains
 * the routine called from the reserved instruction fault handler in locore.s to
 * check for emulated instructions.  Actual instruction emulation is implemented
 * in other modules.
 *
 *	@(#)emul_resinstr.s	7.1 (Berkeley) 2/3/04
 */

#include "../vax/cpucond.h"
#if EMULFFLT || EMULDFLT || EMULGFLT || EMULHFLT
#include "../vax/psl.h"
#include "../vax/mtpr.h"

/*
 * Design:
 *
 * The instructions emulated via the reserved instruction fault are F, D, G and
 * H floating point instructions, as well as octaword instructions along with
 * H-float.  The actual emulation code runs with the privileges of the original
 * instruction user.  The routine in this module checks if this is an emulated
 * instruction.  If not it simply returns and the reserved instruction handler
 * in locore.s proceeds normally.  If this is an emulated instruction this
 * routine does not return.  Instead we jump to the emulator directly if we are
 * working for the kernel or copy the exception to the user stack and REI to the
 * emulator in user mode if we are working for the user.
 *
 * Since we have to look in a table based on the opcode to determine whether
 * this is an emulated instruction or not, we can make that table contain
 * pointers to routines emulating the different instructions, and we can pass
 * the looked-up value to the emulator.
 */

#if EMULFFLT || EMULDFLT
/*
 * Emulation opcode dispatch table:
 *	ONLY GOES FROM 0x40 TO 0x76
 */
#define EMUMIN		0x40
#define EMUMAX		0x76
#define NOEMULATE	.long 0
#if EMULFFLT
#define	EMULF(a)	.long _EMF/**/a
#else
#define	EMULF(a)	.long 0
#endif
#if EMULDFLT
#define	EMULD(a)	.long _EMF/**/a
#else
#define	EMULD(a)	.long 0
#endif
	.text
	.globl	_EMF_dispatch_table
_EMF_dispatch_table:
/* 40 */	EMULF(addf2);	EMULF(addf3);	EMULF(subf2);	EMULF(subf3)
/* 44 */	EMULF(mulf2);	EMULF(mulf3);	EMULF(divf2);	EMULF(divf3)
/* 48 */	EMULF(cvtfb);	EMULF(cvtfw);	EMULF(cvtfl);	EMULF(cvtrfl)
/* 4C */	EMULF(cvtbf);	EMULF(cvtwf);	EMULF(cvtlf);	EMULF(acbf)
/* 50 */	EMULF(movf);	EMULF(cmpf);	EMULF(mnegf);	EMULF(tstf)
/* 54 */	EMULF(emodf);	EMULF(polyf);	EMULD(cvtfd);	NOEMULATE
/* 58 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 5C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 60 */	EMULD(addd2);	EMULD(addd3);	EMULD(subd2);	EMULD(subd3)
/* 64 */	EMULD(muld2);	EMULD(muld3);	EMULD(divd2);	EMULD(divd3)
/* 68 */	EMULD(cvtdb);	EMULD(cvtdw);	EMULD(cvtdl);	EMULD(cvtrdl)
/* 6C */	EMULD(cvtbd);	EMULD(cvtwd);	EMULD(cvtld);	EMULD(acbd)
/* 70 */	EMULD(movd);	EMULD(cmpd);	EMULD(mnegd);	EMULD(tstd)
/* 74 */	EMULD(emodd);	EMULD(polyd);	EMULD(cvtdf)
#endif

#if EMULGFLT || EMULHFLT
/*
 * Dispatch table for 2-byte opcodes (first byte FD).  For these we use a full
 * table (all 256).
 */
#define NOEMULATE	.long 0
#if EMULGFLT
#define	EMULG(a)	.long _EMF/**/a
#else
#define	EMULG(a)	.long 0
#endif
#if EMULHFLT
#define	EMULH(a)	.long _EMF/**/a
#else
#define	EMULH(a)	.long 0
#endif
	.text
	.globl	_EMF_dispatch_table2
_EMF_dispatch_table2:
/* 00 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 04 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 08 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 0C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 10 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 14 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 18 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 1C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 20 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 24 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 28 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 2C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 30 */	NOEMULATE;	NOEMULATE;	EMULH(cvtdh);	EMULG(cvtgf)
/* 34 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 38 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 3C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 40 */	EMULG(addg2);	EMULG(addg3);	EMULG(subg2);	EMULG(subg3)
/* 44 */	EMULG(mulg2);	EMULG(mulg3);	EMULG(divg2);	EMULG(divg3)
/* 48 */	EMULG(cvtgb);	EMULG(cvtgw);	EMULG(cvtgl);	EMULG(cvtrgl)
/* 4C */	EMULG(cvtbg);	EMULG(cvtwg);	EMULG(cvtlg);	EMULG(acbg)
/* 50 */	EMULG(movg);	EMULG(cmpg);	EMULG(mnegg);	EMULG(tstg)
/* 54 */	EMULG(emodg);	EMULG(polyg);	EMULH(cvtgh);	NOEMULATE
/* 58 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 5C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 60 */	EMULH(addh2);	EMULH(addh3);	EMULH(subh2);	EMULH(subh3)
/* 64 */	EMULH(mulh2);	EMULH(mulh3);	EMULH(divh2);	EMULH(divh3)
/* 68 */	EMULH(cvthb);	EMULH(cvthw);	EMULH(cvthl);	EMULH(cvtrhl)
/* 6C */	EMULH(cvtbh);	EMULH(cvtwh);	EMULH(cvtlh);	EMULH(acbh)
/* 70 */	EMULH(movh);	EMULH(cmph);	EMULH(mnegh);	EMULH(tsth)
/* 74 */	EMULH(emodh);	EMULH(polyh);	EMULH(cvthg);	NOEMULATE
/* 78 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 7C */	EMULH(clro);	EMULH(movo);	EMULH(movao);	EMULH(pushao)
/* 80 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 84 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 88 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 8C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 90 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 94 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 98 */	EMULH(cvtfh);	EMULG(cvtfg);	NOEMULATE;	NOEMULATE
/* 9C */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* A0 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* A4 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* A8 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* AC */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* B0 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* B4 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* B8 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* BC */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* C0 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* C4 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* C8 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* CC */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* D0 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* D4 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* D8 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* DC */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* E0 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* E4 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* E8 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* EC */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* F0 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* F4 */	NOEMULATE;	NOEMULATE;	EMULH(cvthf);	EMULH(cvthd)
/* F8 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* FC */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
#endif

	.text
	.globl	_Resinstr_check_emul
	.align	2
_Resinstr_check_emul:
	pushr	$0x0003
/*
 * Get the opcode.  We do not need to probe before fetching the first byte of
 * the since the CPU won't take the reserved instruction fault unless it was
 * able to fetch at least the first byte with the user's privileges.
 */
	movl	12(sp),r1
	movzbl	(r1)+,r0
#if EMULGFLT || EMULHFLT
	cmpl	r0,$0xFD
	jeql	9f
#endif
#if EMULFFLT || EMULDFLT
	subl2	$EMUMIN,r0
	jcs	8f
	cmpl	r0,$EMUMAX-EMUMIN
	jgtru	8f
	movl	_EMF_dispatch_table[r0],r0
#else
	jbr	8f
#endif
2:	jeql	8f
/*
 * OK, this one is for us.  Are we working for the user or the kernel?
 *
 * The emulator is run with:
 *
 *	  (sp) - saved user's R0
 *	 4(sp) - saved user's R1
 *	 8(sp) - free longword
 *	12(sp) - exception PC
 *	16(sp) - exception PSL
 *	20(sp) - top of user's stack at the instruction
 *
 * R0 = pointer to the instruction specific emulation routine
 * R1 = SP
 *
 * All other registers are user's.
 */
	bitl	$PSL_CURMOD,16(sp)
	jneq	1f			/* user */
	movl	sp,r1
	jmp	_Emulate_instr		/* kernel */
1:	mfpr	$USP,r1
	subl2	$20,r1
/*
 * We need to push the above frame on the user stack.  We must guard it with
 * PROBEW.  The problem is what do we do if PROBEW fails?  From one viewpoint
 * the right thing to do would be to simulate a SIGSEGV or SIGBUS for an access
 * control violation.  The greatest difficulty here, believe it or not, would be
 * deciding between SIGSEGV and SIGBUS, as well as deciding what code (offending
 * address) to give the user, as PROBEW doesn't tell us whether it would be a
 * length violation or a protection violation and whether the problem lies at
 * the start or the end of the probe region if it straddles a page boundary.
 *
 * On the other hand, architecturally the instructions we are emulating do not
 * push anything on the stack, so there is no *architectural* requirement for us
 * to "emulate" access control violation signals in this case.  Also the process
 * must be really hosed if it has no valid stack, and in the end I've decided
 * it's OK for this routine to return to the reserved instruction handler in
 * this case and let it proceed with the T_PRIVINFLT trap and SIGILL.
 */
	probew	$0,$20,(r1)
	jeql	8f
	mtpr	r1,$USP
	movq	(sp),(r1)		/* copy frame to user stack */
	movq	12(sp),12(r1)
	addl2	$12,sp
	movab	_Emulate_instr,(sp)
	movl	$(PSL_CURMOD|PSL_PRVMOD),4(sp)
	rei
8:	popr	$0x0003
	rsb
#if EMULGFLT || EMULHFLT
/*
 * We need to look at the 2nd opcode byte.  We must probe since if we are
 * running on a processor with no hardware/microcode support for any 2-byte ESCD
 * opcodes, it could take the reserved instruction fault immediately upon seeing
 * FD without checking the 2nd byte for accessibility.  We punt on probe
 * failures just like for stack probes above, for the same reasons (see comments
 * above).
 */
	prober	$0,$1,(r1)
	jeql	8b
	movzbl	(r1),r0
	movl	_EMF_dispatch_table2[r0],r0
	jbr	2b
#endif

#endif
