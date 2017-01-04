h43330
s 00007/00000/00356
d D 7.3 04/01/27 21:37:37 msokolov 3 2
c CMPC3, CMPC5, LOCC, SKPC, SCANC, SPANC are now in base subset
c emulation needed only on MV II
e
s 00025/00000/00331
d D 7.2 04/01/12 21:55:27 msokolov 2 1
c MOVTC:	handle overlap as required by VARM
e
s 00331/00000/00000
d D 7.1 04/01/11 11:26:30 msokolov 1 0
c date and time created 04/01/11 11:26:30 by msokolov
e
u
U
t
T
I 1
/*
 * Copyright (c) 1986, 1987 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Mt. Xinu.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	%W% (Berkeley) %G%
 */

#include "../vax/cpucond.h"
#ifdef NEED_SAMEMODE_EMU
/*
 * String instruction emulation - MicroVAX only.  These routines are called
 * from locore.s when an "emulate" fault occurs on the MicroVAX.  They are
 * called with the stack set up as follows:
 *
 *	  (sp):	Return address of trap handler
 *	 4(sp):	Instruction Opcode	(also holds PSL result from emulator)
 *	 8(sp):	Instruction PC
 *	12(sp):	Operand 1
 *	16(sp):	Operand 2
 *	20(sp):	Operand 3
 *	24(sp):	Operand 4
 *	28(sp):	Operand 5
 *	32(sp):	Operand 6
 *	36(sp):	old Register 11
 *	40(sp):	old Register 10
 *	44(sp):	Return PC
 *	48(sp):	Return PSL
 *	52(sp): TOS before instruction
 *
 * R11 and r10 are available for use.  If any routine needs to use r9-r1
 * they need to save them first (unless those registers are SUPPOSED to be
 * messed with by the "instruction").  These routines leave their results
 * in registers 0-5 explicitly, as needed, and use the macros defined below
 * to link up with calling routine.
 */

#define return		rsb
#define savepsl		movpsl	4(sp)
#define setpsl(reg)	movl	reg,4(sp)
#define overflowpsl	movl	$2,4(sp)
#define arg1		12(sp)
#define arg2		16(sp)
#define arg3		20(sp)
#define arg4		24(sp)
#define arg5		28(sp)
#define arg6		32(sp)
#define argub(num,reg)	movzbl	8+4*num(sp),reg
#define arguw(num,reg)	movzwl	8+4*num(sp),reg
#define argul(num,reg)	movl	8+4*num(sp),reg
#define argb(num,reg)	cvtbl	8+4*num(sp),reg
#define argw(num,reg)	cvtwl	8+4*num(sp),reg
#define argl(num,reg)	movl	8+4*num(sp),reg
#define toarg(reg,num)	movl	reg,8+4*num(sp)


	.text
	.align	1
	.globl	_EMcrc
_EMcrc:
	argl(1,r11)		# (1) table address == r11
	argl(2,r0)		# (2) initial crc == r0
	argl(4,r3)		# (4) source address == r3
	arguw(3,r2)		# (3) source length == r2
	jeql	Lcrc_out
Lcrc_loop:
	xorb2	(r3)+,r0
	extzv	$0,$4,r0,r10
	extzv	$4,$28,r0,r1
	xorl3	r1,(r11)[r10],r0
	extzv	$0,$4,r0,r10
	extzv	$4,$28,r0,r1
	xorl3	r1,(r11)[r10],r0
	sobgtr	r2,Lcrc_loop
Lcrc_out:
	tstl	r0
	savepsl
	clrl	r1
	return


	.align	1
	.globl	_EMmovtc
_EMmovtc:
	arguw(1,r0)		# (1) source length == r0
	argl(2,r1)		# (2) source address == r1
	argub(3,r11)		# (3) fill character == r11
	argl(4,r3)		# (4) table address == r3
	argl(6,r5)		# (6) destination address == r5
	arguw(5,r4)		# (5) destination length == r4
	jeql	Lmovtc_out
I 2
	cmpl	r1,r5
	jlssu	Lmovtc_back
E 2
Lmovtc_loop:
	tstl	r0
	jeql	Lmovtc_2loop
	movzbl	(r1)+,r2
	movb	(r3)[r2],(r5)+
	decl	r0
	sobgtr	r4,Lmovtc_loop
	jbr	Lmovtc_out
Lmovtc_2loop:
	movb	r11,(r5)+
	sobgtr	r4,Lmovtc_2loop
Lmovtc_out:
I 2
	cmpl	r4,r0
	savepsl
	clrl	r2
	return
Lmovtc_back:
	addl2	r4,r5
	movl	r5,r10
1:	cmpl	r4,r0
	jlequ	2f
	movb	r11,-(r5)
	decl	r4
	jbr	1b
2:	addl2	r4,r1
	movl	r1,r11
	subl2	r4,r0
	tstl	r4
	jeql	Lmovtc_bout
3:	movzbl	-(r1),r2
	movb	(r3)[r2],-(r5)
	sobgtr	r4,3b
Lmovtc_bout:
	movl	r11,r1
	movl	r10,r5
E 2
	cmpl	r4,r0
	savepsl
	clrl	r2
	return


	.align	1
	.globl	_EMmovtuc
_EMmovtuc:
	arguw(1,r0)		# (1) source length == r0
	argl(2,r1)		# (2) source address == r1
	argub(3,r11)		# (3) escape character == r11
	argl(4,r3)		# (4) table address == r3
	argl(6,r5)		# (6) destination address == r5
	arguw(5,r4)		# (5) destination length == r4
	jeql	Lmovtuc_out
Lmovtuc_loop:
	tstl	r0
	jeql	Lmovtuc_out
	movzbl	(r1),r2
	movzbl	(r3)[r2],r2
	cmpl	r2,r11
	jeql	Lmovtuc_esc
	incl	r1
	movb	r2,(r5)+
	decl	r0
	sobgtr	r4,Lmovtuc_loop
Lmovtuc_out:
	cmpl	r4,r0
	savepsl
	clrl	r2
	return
Lmovtuc_esc:
	cmpl	r4,r0
	savepsl
	bisl2	$2,4(sp)
	clrl	r2
	return


	.align	1
	.globl	_EMmatchc
_EMmatchc:
	argl(2,r10)		# (2) substring address == r10
	arguw(3,r2)		# (3) source length == r2
	argl(4,r3)		# (4) source address == r3
	arguw(1,r11)		# (1) substring length == r11
	jeql	Lmatchc_null	# temp source address == r1
	addl2	r10,r11		# temp substring address == r0
	tstl	r2
	jeql	Lmatchc_null
Lmatchc_loop:
	cmpb	(r10),(r3)
	jneq	Lmatchc_fail
	movl	r3,r1
	movl	r10,r0
Lmatchc_2loop:
	cmpl	r0,r11
	jeql	Lmatchc_succ
	cmpb	(r0)+,(r1)+
	jeql	Lmatchc_2loop
Lmatchc_fail:
	incl	r3
	sobgtr	r2,Lmatchc_loop
	movl	r10,r1
	subl3	r10,r11,r0
	jbr	Lmatchc_out
Lmatchc_succ:	
	movl	r1,r3
	movl	r11,r1
	clrl	r0
Lmatchc_out:
	savepsl
	return
Lmatchc_null:			# set registers and condition codes right
	argl(2,r1)		# for either or both operands null
	arguw(1,r0)
	jbr	Lmatchc_out


I 3
#ifdef NEED_UV2_SUPPORT
/*
 * CMPC3, CMPC5, LOCC, SKPC, SCANC, and SPANC are in the base subset from 1986
 * onward.  They are missing only on MicroVAX II.
 */

E 3
	.align	1
	.globl	_EMspanc
_EMspanc:
	argl(2,r1)		# (2) string address == r1
	argub(4,r2)		# (4) character-mask == r2
	argl(3,r3)		# (3) table address == r3
	arguw(1,r0)		# (1) string length == r0
	jeql	Lspanc_out
Lspanc_loop:
	movzbl	(r1),r11
	mcomb	(r3)[r11],r11
	bicb3	r11,r2,r11
	jeql	Lspanc_out
	incl	r1
	sobgtr	r0,Lspanc_loop
Lspanc_out:
	savepsl
	clrl	r2
	return


	.align	1
	.globl	_EMscanc
_EMscanc:
	argl(2,r1)		# (2) string address == r1
	argub(4,r2)		# (4) character-mask == r2
	argl(3,r3)		# (3) table address == r3
	arguw(1,r0)		# (1) string length == r0
	jeql	Lscanc_out
Lscanc_loop:
	movzbl	(r1),r11
	mcomb	(r3)[r11],r11
	bicb3	r11,r2,r11
	jneq	Lscanc_out
	incl	r1
	sobgtr	r0,Lscanc_loop
Lscanc_out:
	savepsl
	clrl	r2
	return


	.align	1
	.globl	_EMskpc
_EMskpc:
	argub(1,r11)		# (1) character == r11
	argl(3,r1)		# (3) string address == r1
	arguw(2,r0)		# (2) string length == r0
	jeql	Lskpc_out	# forget zero length strings
Lskpc_loop:
	cmpb	(r1),r11
	jneq	Lskpc_out
	incl	r1
	sobgtr	r0,Lskpc_loop
Lskpc_out:
	tstl	r0		# be sure of condition codes
	savepsl
	return


	.align	1
	.globl	_EMlocc
_EMlocc:
	argub(1,r11)		# (1) character == r11
	argl(3,r1)		# (3) string address == r1
	arguw(2,r0)		# (2) string length == r0
	jeql	Lskpc_out	# forget zero length strings
Llocc_loop:
	cmpb	(r1),r11
	jeql	Llocc_out
	incl	r1
	sobgtr  r0,Llocc_loop
Llocc_out:
	tstl	r0		# be sure of condition codes
	savepsl
	return


	.align	1
	.globl	_EMcmpc3
_EMcmpc3:
	argl(2,r1)		# (2) string1 address == r1
	argl(3,r3)		# (3) string2 address == r3
	arguw(1,r0)		# (1) strings' length == r0
	jeql	Lcmpc3_out
Lcmpc3_loop:
	cmpb	(r1),(r3)
	jneq	Lcmpc3_out
	incl	r1
	incl	r3
	sobgtr	r0,Lcmpc3_loop
Lcmpc3_out:
	savepsl
	movl	r0,r2
	return


	.align	1
	.globl	_EMcmpc5
_EMcmpc5:
	argl(2,r1)		# (2) string1 address == r1
	argub(3,r11)		# (1) fill character == r11
	arguw(4,r2)		# (1) string2 length == r2
	argl(5,r3)		# (3) string2 address == r3
	arguw(1,r0)		# (1) string1 length == r0
	jeql	Lcmpc5_str2
Lcmpc5_loop:
	tstl	r2
	jeql	Lcmpc5_str1loop
	cmpb	(r1),(r3)
	jneq	Lcmpc5_out
	incl	r1
	incl	r3
	decl	r2
	sobgtr	r0,Lcmpc5_loop
Lcmpc5_str2:
	tstl	r2
	jeql	Lcmpc5_out
Lcmpc5_str2loop:
	cmpb	r11,(r3)
	jneq	Lcmpc5_out
	incl	r3
	sobgtr	r2,Lcmpc5_str2loop
	jbr	Lcmpc5_out
Lcmpc5_str1loop:
	cmpb	(r1),r11
	jneq	Lcmpc5_out
	incl	r1
	sobgtr	r0,Lcmpc5_str1loop
Lcmpc5_out:
	savepsl
	return
I 3
#endif NEED_UV2_SUPPORT
E 3

#endif NEED_SAMEMODE_EMU
E 1
