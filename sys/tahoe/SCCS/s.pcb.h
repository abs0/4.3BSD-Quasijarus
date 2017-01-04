h02201
s 00007/00001/00063
d D 7.1 88/05/21 18:36:11 karels 3 2
c bring up to revision 7 for tahoe release
e
s 00015/00017/00049
d D 1.2 86/01/05 18:42:38 sam 2 1
c 1st working version
e
s 00066/00000/00000
d D 1.1 85/08/01 20:09:27 sam 1 0
c date and time created 85/08/01 20:09:27 by sam
e
u
U
t
T
I 2
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

E 2
I 1
/*
 * TAHOE process control block
 */
D 2

struct pcb
{
E 2
I 2
struct pcb {
E 2
	int	pcb_ksp; 	/* kernel stack pointer */
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
	int	pcb_r13; 
#define	pcb_fp pcb_r13
	int	pcb_pc; 	/* program counter */
	int	pcb_psl; 	/* program status longword */
	struct  pte *pcb_p0br; 	/* seg 0 base register */
	int	pcb_p0lr; 	/* seg 0 length register and astlevel */
	struct  pte *pcb_p1br; 	/* seg 1 base register */
	int	pcb_p1lr; 	/* seg 1 length register and pme */
	struct  pte *pcb_p2br; 	/* seg 2 base register */
	int	pcb_p2lr; 	/* seg 2 length register and pme */
	int	pcb_ach;	/* accumulator - high order longword */
	int	pcb_acl;	/* accumulator - low order longword */
#define ACH	pcb_ach
#define ACL	pcb_acl
D 2
	int	pcb_hfs;	/* f.p. status register.	*/
E 2
I 2
	int	pcb_hfs;	/* fp status register */
E 2
/*
 * Software pcb (extension)
 */
	union {
		float 	*faddr;	/* address of single precision accumulator */
		double	*daddr; /* address of double precision accumulator */
	} pcb_savacc;
#define FSAVACC	pcb_savacc.faddr
#define DSAVACC pcb_savacc.daddr
	int	pcb_szpt; 	/* number of pages of user page table */
	int	pcb_cmap2;
	int	*pcb_sswap;
D 2
	short	pcb_ckey;	/* cache code key (proc index if NPROC<255) */
	short	pcb_dkey;	/* cache data key */
	int	pcb_sigc[4];
E 2
I 2
	long	pcb_sigc[5];	/* sigcode actually 19 bytes */
E 2
};

extern long	*user_psl;

D 2
#define	aston() \
	{ \
		u.u_pcb.pcb_psl |= PSL_SFE; \
		if ((int)user_psl != 0) *user_psl |= PSL_SFE; \
	}
E 2
I 2
#define	aston() { \
	u.u_pcb.pcb_psl |= PSL_SFE; \
	if ((int)user_psl != 0) \
		*user_psl |= PSL_SFE; \
}
E 2

D 2
#define	astoff() \
	{ \
		u.u_pcb.pcb_psl &= ~ PSL_SFE; \
		if ((int)user_psl != 0) *user_psl &= ~PSL_SFE; \
	}
E 2
I 2
#define	astoff() { \
	u.u_pcb.pcb_psl &= ~ PSL_SFE; \
	if ((int)user_psl != 0) \
		*user_psl &= ~PSL_SFE; \
}
E 2
E 1
