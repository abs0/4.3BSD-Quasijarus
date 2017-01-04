h44778
s 00019/00008/00058
d D 7.2 88/05/07 14:20:12 karels 10 9
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00001/00001/00065
d D 7.1 86/06/05 00:47:54 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00059
d D 6.2 85/06/08 13:45:48 mckusick 8 7
c Add copyright
e
s 00000/00000/00060
d D 6.1 83/08/01 12:08:34 sam 7 5
c 4.2 distribution
e
s 00000/00000/00060
d R 4.5 83/08/01 12:05:15 sam 6 5
c 4.2 distribution
e
s 00001/00000/00059
d D 4.4 83/08/01 12:03:33 sam 5 3
c add support for second uba on 750; move rpb in front of 
c scb, otherwise it would be at variable location; add nexi numbers 
c for 64K chip controllers and ci
e
s 00000/00000/00059
d R 6.1 83/07/29 07:21:10 sam 4 3
c 4.2 distribution
e
s 00037/00036/00022
d D 4.3 81/02/21 21:29:55 wnj 3 2
c misc changes for first working interlockable version
e
s 00000/00000/00058
d D 4.2 81/02/19 21:42:10 wnj 2 1
c %G%->%E%
e
s 00058/00000/00000
d D 4.1 81/02/19 21:34:26 wnj 1 0
c date and time created 81/02/19 21:34:26 by wnj
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8

/*
 * VAX System control block layout
 */

D 3
struct	scb	{
	int	(*scb_stray)();			/* reverved */
	int	(*scb_machchk)();		/* machine chack */
	int	(*scb_kspinval)();		/* KSP invalid */
	int	(*scb_powfail)();		/* power fail */
	int	(*scb_resinstr)();		/* reserved instruction */
	int	(*scb_custinst)();		/* XFC instr */
	int	(*scb_resopnd)();		/* reserved operand */
	int	(*scb_resaddr)();		/* reserved addr mode */
	int	(*scb_acv)();			/* access control violation */
	int	(*scb_tnv)();			/* translation not valid */
	int	(*scb_tracep)();		/* trace pending */
	int	(*scb_bpt)();			/* breakpoint instr */
	int	(*scb_compat)();		/* compatibility mode fault */
	int	(*scb_arith)();			/* arithmetic fault */
E 3
I 3
struct scb {
D 10
	int	(*scb_stray)();		/* reserved */
E 10
I 10
	int	(*scb_passiverel)();	/* BI passive release */
E 10
	int	(*scb_machchk)();	/* machine chack */
	int	(*scb_kspinval)();	/* KSP invalid */
	int	(*scb_powfail)();	/* power fail */
	int	(*scb_resinstr)();	/* reserved instruction */
	int	(*scb_custinst)();	/* XFC instr */
	int	(*scb_resopnd)();	/* reserved operand */
	int	(*scb_resaddr)();	/* reserved addr mode */
	int	(*scb_acv)();		/* access control violation */
	int	(*scb_tnv)();		/* translation not valid */
	int	(*scb_tracep)();	/* trace pending */
	int	(*scb_bpt)();		/* breakpoint instr */
	int	(*scb_compat)();	/* compatibility mode fault */
	int	(*scb_arith)();		/* arithmetic fault */
E 3
	int	(*scb_stray2)();
	int	(*scb_stray3)();
D 3
	int	(*scb_chmk)();			/* CHMK instr */
	int	(*scb_chme)();			/* CHME instr */
	int	(*scb_chms)();			/* CHMS instr */
	int	(*scb_chmu)();			/* CHMU instr */
	int	(*scb_sbisilo)();		/* SBI silo compare */
	int	(*scb_cmrd)();			/* corrected mem read data */
	int	(*scb_sbialert)();		/* SBI alert */
	int	(*scb_sbiflt)();		/* SBI fault */
	int	(*scb_wtime)();			/* memory write timeout */
E 3
I 3
	int	(*scb_chmk)();		/* CHMK instr */
	int	(*scb_chme)();		/* CHME instr */
	int	(*scb_chms)();		/* CHMS instr */
	int	(*scb_chmu)();		/* CHMU instr */
	int	(*scb_sbisilo)();	/* SBI silo compare */
I 10
#define	scb_bierr scb_sbisilo		/*=BI error (8200) */
E 10
	int	(*scb_cmrd)();		/* corrected mem read data */
	int	(*scb_sbialert)();	/* SBI alert */
D 10
	int	(*scb_sbiflt)();	/* SBI fault */
E 10
I 10
	int	(*scb_sbifault)();	/* SBI fault */
E 10
	int	(*scb_wtime)();		/* memory write timeout */
E 3
D 10
	int	(*scb_stray4[8])();
E 10
I 10
#define scb_sbierr scb_wtime		/*=SBI error (8600) */
	int	(*scb_sbifail)();	/* SBI fail (8600) */
	int	(*scb_stray4[7])();
E 10
D 3
	int	(*scb_soft[15])();		/* software interrupt */
	int	(*scb_timer)();			/* interval timer interrupt */
E 3
I 3
	int	(*scb_soft[15])();	/* software interrupt */
	int	(*scb_timer)();		/* interval timer interrupt */
E 3
D 10
	int	(*scb_stray5[7])();
E 10
I 10
	int	(*scb_stray5)();
	int	(*scb_cn1rint)();	/* console terminal 1 rcv (8200) */
	int	(*scb_cn1xint)();	/* console terminal 1 xmt (8200) */
	int	(*scb_cn2rint)();	/* console 2 rcv (8200) */
	int	(*scb_cn2xint)();	/* console 2 xmt (8200) */
	int	(*scb_cn3rint)();	/* console 3 rcv (8200) */
	int	(*scb_cn3xint)();	/* console 3 xmt (8200) */
E 10
	int	(*scb_stray6[4])();
D 3
	int	(*scb_csdr)();			/* console storage receive */
	int	(*scb_csdx)();			/* console storage transmit */
	int	(*scb_ctr)();			/* console terminal receive */
	int	(*scb_ctx)();			/* console terminal transmit */
	int	(*scb_ipl14[16])();		/* device interrupts IPL 14 */
	int	(*scb_ipl15[16])();		/*   "		"    IPL 15 */
	int	(*scb_ipl16[16])();		/*   "		"    IPL 16 */
	int	(*scb_ipl17[16])();		/*   "		"    IPL 17 */
	int	(*scb_ubaint[128])();		/* Unibus device intr */
E 3
I 3
	int	(*scb_csdr)();		/* console storage receive */
	int	(*scb_csdx)();		/* console storage transmit */
	int	(*scb_ctr)();		/* console terminal receive */
	int	(*scb_ctx)();		/* console terminal transmit */
	int	(*scb_ipl14[16])();	/* device interrupts IPL 14 */
	int	(*scb_ipl15[16])();	/*   "		"    IPL 15 */
	int	(*scb_ipl16[16])();	/*   "		"    IPL 16 */
	int	(*scb_ipl17[16])();	/*   "		"    IPL 17 */
D 10
	int	(*scb_ubaint[128])();	/* Unibus device intr */
I 5
	int	(*scb_uba1int[128])();	/* Unibus 1 device intr */
E 10
I 10
	/*
	 * On the 8600, this is followed by a second copy of the SCB.
	 * On the 750, this is followed by 128 uba0 device interrupts,
	 * then 128 uba1 device interrupts.
	 */
E 10
E 5
E 3
};

#ifdef KERNEL
D 3
extern	struct scb Scbbase;
E 3
I 3
D 10
extern	struct scb scb;
/* scb.scb_ubaint is the same as UNIvec */
E 10
I 10
extern	struct scb scb[];
E 10
E 3
#endif

#define	scbentry(f, how)		((int (*)())(((int)f)+how))

#define	SCB_KSTACK	0
#define	SCB_ISTACK	1
#define	SCB_WCS		2
#define	SCB_HALT	3
E 1
