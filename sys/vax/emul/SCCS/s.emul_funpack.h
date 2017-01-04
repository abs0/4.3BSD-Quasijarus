h62495
s 00035/00000/00000
d D 7.1 04/02/03 10:51:28 msokolov 1 0
c kernel builds with F-float emulator
e
u
U
t
T
I 1
/*
 * Floating point datum unpack macros (converting to internal form described in
 * emul_float.s comments).
 *
 *	%W% (Berkeley) %G%
 */

#define	UNPACKF(off,sexr,mr)	\
	extzv	$7,$9,off(fp),sexr; \
	beql	1f; \
	cmpw	sexr,$0x100; \
	bneq	3f; \
	jmp	_EMF_reserved_operand_fault; \
3:	movl	$0x80000000,mr; \
	insv	off(fp),$24,$7,mr; \
	insv	off+2(fp),$8,$16,mr; \
	brb	2f; \
1:	clrl	mr; \
2:

#define	UNPACKD(off,sexr,mrlo,mrhi)	\
	clrl	mrlo; \
	extzv	$7,$9,off(fp),sexr; \
	beql	1f; \
	cmpw	sexr,$0x100; \
	bneq	3f; \
	jmp	_EMF_reserved_operand_fault; \
3:	movl	$0x80000000,mrhi; \
	insv	off(fp),$24,$7,mrhi; \
	insv	off+2(fp),$8,$16,mrhi; \
	insv	off+4(fp),$24,$16,mrlo; \
	insv	off+6(fp),$8,$16,mrlo; \
	brb	2f; \
1:	clrl	mrhi; \
2:
E 1
