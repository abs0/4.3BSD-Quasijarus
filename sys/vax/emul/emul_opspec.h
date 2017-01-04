/*
 * Definitions for the operand specification for _EMF_operand_decode
 *
 *	@(#)emul_opspec.h	7.3 (Berkeley) 2011/10/17
 */

/* operand types */
#define	TYPRI	1	/* read, integral literals */
#define	TYPRF	2	/* read, F/D floating literals */
#define	TYPRG	3	/* read, G-float literals */
#define	TYPRH	4	/* read, H-float literals */
#define	TYPM	5	/* modify */
#define	TYPW	6	/* write */
#define	TYPA	7	/* address */

/* operand sizes given as power of 2 */
#define	SIZB	0	/* byte */
#define	SIZW	1	/* word */
#define	SIZL	2	/* longword */
#define	SIZQ	3	/* quadword */
#define	SIZO	4	/* octaword */
