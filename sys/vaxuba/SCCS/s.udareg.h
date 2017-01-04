h01388
s 00046/00028/00029
d D 7.2 87/10/23 11:17:53 bostic 5 4
c new version; (Chris Torek)
e
s 00001/00001/00056
d D 7.1 86/06/05 01:20:44 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00050
d D 6.2 85/06/08 14:26:52 mckusick 3 2
c Add copyright
e
s 00000/00000/00051
d D 6.1 83/07/29 07:30:03 sam 2 1
c 4.2 distribution
e
s 00051/00000/00000
d D 4.1 81/11/04 10:54:08 wnj 1 0
c date and time created 81/11/04 10:54:08 by wnj
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
D 4
 * Copyright (c) 1982 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

/*
D 5
 * UDA-50 registers and structures
E 5
I 5
 * UDA50 registers and structures
E 5
 */

I 5
/*
 * Writing any value to udaip starts initialisation.  Reading from it
 * when the UDA is running makes the UDA look through the command ring
 * to find any new commands.  Reading udasa gives status; writing it
 * during initialisation sets things up.
 */
E 5
struct udadevice {
D 5
	short	udaip;		/* initialization and polling */
	short	udasa;		/* status and address */
E 5
I 5
	u_short	udaip;		/* initialisation and polling */
	u_short	udasa;		/* status and address */
E 5
};

D 5
#define	UDA_ERR		0100000	/* error bit */
#define	UDA_STEP4	0040000	/* step 4 has started */
#define	UDA_STEP3	0020000	/* step 3 has started */
#define	UDA_STEP2	0010000	/* step 2 has started */
#define	UDA_STEP1	0004000	/* step 1 has started */
#define	UDA_NV		0002000	/* no host settable interrupt vector */
#define	UDA_QB		0001000	/* controller supports Q22 bus */
#define	UDA_DI		0000400	/* controller implements diagnostics */
#define	UDA_IE		0000200	/* interrupt enable */
#define	UDA_PI		0000001	/* host requests adapter purge interrupts */
#define	UDA_GO		0000001	/* start operation, after init */
E 5
I 5
/*
 * Bits in UDA status register during initialisation
 */
#define	UDA_ERR		0x8000	/* error */
#define	UDA_STEP4	0x4000	/* step 4 has started */
#define	UDA_STEP3	0x2000	/* step 3 has started */
#define	UDA_STEP2	0x1000	/* step 2 has started */
#define	UDA_STEP1	0x0800	/* step 1 has started */
#define	UDA_NV		0x0400	/* no host settable interrupt vector */
#define	UDA_QB		0x0200	/* controller supports Q22 bus */
#define	UDA_DI		0x0100	/* controller implements diagnostics */
#define	UDA_IE		0x0080	/* interrupt enable */
#define	UDA_NCNRMASK	0x003f	/* in STEP1, bits 0-2=NCMDL2, 3-5=NRSPL2 */
#define	UDA_IVECMASK	0x007f	/* in STEP2, bits 0-6 are interruptvec / 4 */
#define	UDA_PI		0x0001	/* host requests adapter purge interrupts */
E 5

D 5

E 5
/*
D 5
 * UDA Communications Area
E 5
I 5
 * Bits in UDA status register after initialisation
E 5
 */
I 5
#define	UDA_GO		0x0001	/* run */
E 5

I 5
#define	UDASR_BITS \
"\20\20ERR\17STEP4\16STEP3\15STEP2\14STEP1\13NV\12QB\11DI\10IE\1GO"

/*
 * UDA Communications Area.  Note that this structure definition
 * requires NRSP and NCMD to be defined already.
 */
E 5
struct udaca {
	short	ca_xxx1;	/* unused */
	char	ca_xxx2;	/* unused */
	char	ca_bdp;		/* BDP to purge */
D 5
	short	ca_cmdint;	/* command queue transition interrupt flag */
	short	ca_rspint;	/* response queue transition interrupt flag */
E 5
I 5
	short	ca_cmdint;	/* command ring transition flag */
	short	ca_rspint;	/* response ring transition flag */
E 5
	long	ca_rspdsc[NRSP];/* response descriptors */
	long	ca_cmddsc[NCMD];/* command descriptors */
};

D 5
#define	ca_ringbase	ca_rspdsc[0]

#define	UDA_OWN	0x80000000	/* UDA owns this descriptor */
#define	UDA_INT	0x40000000	/* allow interrupt on ring transition */

E 5
/*
D 5
 * MSCP packet info
E 5
I 5
 * Simplified routines (e.g., uddump) reprogram the UDA50 for one command
 * and one response at a time; uda1ca is like udaca except that it provides
 * exactly one command and response descriptor.
E 5
 */
D 5
struct mscp_header {
	short	uda_msglen;	/* length of MSCP packet */
	char	uda_credits;	/* low 4 bits: credits, high 4 bits: msgtype */
	char	uda_vcid;	/* virtual circuit id */
E 5
I 5
struct uda1ca {
	short	ca_xxx1;
	char	ca_xxx2;
	char	ca_bdp;
	short	ca_cmdint;
	short	ca_rspint;
	long	ca_rspdsc;
	long	ca_cmddsc;
E 5
};
E 1
