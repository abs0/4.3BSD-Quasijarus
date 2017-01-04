h36879
s 00001/00001/00066
d D 7.1 86/06/05 00:46:58 mckusick 14 13
c 4.3BSD release version
e
s 00007/00001/00060
d D 6.4 85/06/08 13:44:43 mckusick 13 12
c Add copyright
e
s 00001/00001/00060
d D 6.3 85/03/07 20:29:44 mckusick 12 11
c add instruction to trampoline code
e
s 00000/00002/00061
d D 6.2 84/07/31 17:14:24 karels 11 10
c ast's set only temporarily, cancelled by swtch;
c clear runrun in swtch after idle; break idle loop out of swtch
c and straighten out the path through swtch
e
s 00000/00000/00063
d D 6.1 83/07/29 07:20:53 sam 10 9
c 4.2 distribution
e
s 00001/00001/00062
d D 4.7 83/06/02 16:00:00 sam 9 8
c new signals
e
s 00001/00000/00062
d D 4.6 82/10/31 17:39:47 root 8 7
c add PME_CLR
e
s 00002/00000/00060
d D 4.5 81/05/14 20:03:40 root 7 6
c missing pcb_{fp,ap}
e
s 00000/00004/00060
d D 4.4 81/02/26 04:30:06 wnj 6 5
c cosmetics
e
s 00001/00001/00063
d D 4.3 81/02/19 21:41:45 wnj 5 4
c %G%->%E%
e
s 00020/00000/00044
d D 4.2 81/02/15 20:37:28 wnj 4 3
c ast and hard/soft clock
e
s 00000/00000/00044
d D 4.1 80/11/09 17:01:23 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00043
d D 3.2 80/06/07 02:59:31 bill 2 1
c %H%->%G%
e
s 00044/00000/00000
d D 3.1 80/04/09 16:24:48 bill 1 0
c date and time created 80/04/09 16:24:48 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 13
E 5
E 2

/*
 * VAX process control block
D 6
 *
 * THE SIZE OF THE pcb, AS INFLUENCED BY THE SIZE OF THE SOFTWARE
 * EXTENSION, IS KNOWN IN THE #ifdef FASTVAX'ed DEFINITIONS OF THE
 * OFFSETS OF U_ARG and U_QSAV IN THE FILE user.h.
E 6
 */

struct pcb
{
	int	pcb_ksp; 	/* kernel stack pointer */
	int	pcb_esp; 	/* exec stack pointer */
	int	pcb_ssp; 	/* supervisor stack pointer */
	int	pcb_usp; 	/* user stack pointer */
	int	pcb_r0; 
	int	pcb_r1; 
	int	pcb_r2; 
	int	pcb_r3; 
	int	pcb_r4; 
	int	pcb_r5; 
	int	pcb_r6; 
	int	pcb_r7; 
	int	pcb_r8; 
	int	pcb_r9; 
	int	pcb_r10; 
	int	pcb_r11; 
	int	pcb_r12; 
I 7
#define	pcb_ap pcb_r12
E 7
	int	pcb_r13; 
I 7
#define	pcb_fp pcb_r13
E 7
	int	pcb_pc; 	/* program counter */
	int	pcb_psl; 	/* program status longword */
	struct  pte *pcb_p0br; 	/* seg 0 base register */
	int	pcb_p0lr; 	/* seg 0 length register and astlevel */
	struct  pte *pcb_p1br; 	/* seg 1 base register */
	int	pcb_p1lr; 	/* seg 1 length register and pme */
/*
 * Software pcb (extension)
 */
	int	pcb_szpt; 	/* number of pages of user page table */
	int	pcb_cmap2;
	int	*pcb_sswap;
D 9
	int	pcb_sigc[3];
E 9
I 9
D 12
	int	pcb_sigc[4];
E 12
I 12
	int	pcb_sigc[5];
E 12
E 9
};
I 4

#define	AST_NONE	0x04000000	/* ast level */
#define	AST_USER	0x03000000	/* ast for user mode */

#define	ASTLVL_NONE	4
#define	ASTLVL_USER	3

#define	AST_CLR		0x07000000
I 8
#define	PME_CLR		0x80000000
E 8

#define	aston() \
	{ \
D 11
		u.u_pcb.pcb_p0lr = (u.u_pcb.pcb_p0lr &~ AST_CLR) | AST_USER; \
E 11
		mtpr(ASTLVL, ASTLVL_USER); \
	}

#define	astoff() \
	{ \
D 11
		u.u_pcb.pcb_p0lr = (u.u_pcb.pcb_p0lr &~ AST_CLR) | AST_NONE; \
E 11
		mtpr(ASTLVL, ASTLVL_NONE); \
	}
E 4
E 1
