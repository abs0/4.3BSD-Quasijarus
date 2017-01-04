h13829
s 00008/00005/00013
d D 7.3 2011/10/17 04:08:48 msokolov 3 2
c a couple of bugs fixed, extended to support G and H
e
s 00001/00001/00017
d D 7.2 04/12/01 22:45:32 msokolov 2 1
c fix SCCS keyword line
e
s 00018/00000/00000
d D 7.1 04/02/03 10:51:28 msokolov 1 0
c kernel builds with F-float emulator
e
u
U
t
T
I 1
/*
 * Definitions for the operand specification for _EMF_operand_decode
 *
D 2
 *	%W% (Berkeley) %W%
E 2
I 2
D 3
 *	%W% (Berkeley) %G%
E 3
I 3
 *	%W% (Berkeley) %E%
E 3
E 2
 */

/* operand types */
#define	TYPRI	1	/* read, integral literals */
D 3
#define	TYPRF	2	/* read, floating literals */
#define	TYPM	3	/* modify */
#define	TYPW	4	/* write */
#define	TYPA	5	/* address */
E 3
I 3
#define	TYPRF	2	/* read, F/D floating literals */
#define	TYPRG	3	/* read, G-float literals */
#define	TYPRH	4	/* read, H-float literals */
#define	TYPM	5	/* modify */
#define	TYPW	6	/* write */
#define	TYPA	7	/* address */
E 3

/* operand sizes given as power of 2 */
#define	SIZB	0	/* byte */
#define	SIZW	1	/* word */
#define	SIZL	2	/* longword */
#define	SIZQ	3	/* quadword */
I 3
#define	SIZO	4	/* octaword */
E 3
E 1
