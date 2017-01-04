h59099
s 00003/00001/00064
d D 7.1 88/05/21 18:36:19 karels 3 2
c bring up to revision 7 for tahoe release
e
s 00057/00050/00008
d D 1.2 86/01/12 15:38:38 sam 2 1
c 4.3- plus start of autoconfig
e
s 00058/00000/00000
d D 1.1 86/01/05 18:46:23 sam 1 0
c date and time created 86/01/05 18:46:23 by sam
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
 *	%W% (Berkeley) %G%
 */
E 3

/*
 * System control block.
 */
struct	scb {
	int	(*scb_vec0)();		/* 000: reserved */
D 2
	int	(*scb_powfail)();	/* 004: power failure */
	int	(*scb_doadump)();	/* 008: power restore */
	int	(*scb_vec3)();		/* 00c: reserved */
	int	(*scb_vec4)();		/* 010: reserved */
	int	(*scb_vec5)();		/* 014: reserved */
	int	(*scb_vec6)();		/* 018: reserved */
	int	(*scb_hardclock)();	/* 01c: interval timer (clock) */
	int	(*scb_vec8)();		/* 020: reserved */
	int	(*scb_vec9)();		/* 024: reserved */
	int	(*scb_cnrint)();	/* 028: console receive */
	int	(*scb_cnxint)();	/* 02c: console transmit */
	int	(*scb_rmtrint)();	/* 030: remote line receive */
	int	(*scb_rmtxint)();	/* 034: remote line transmit */
	int	(*scb_vec14)();		/* 038: reserved */
	int	(*scb_vec15)();		/* 03c: reserved */
	int	(*scb_softint[15])();	/* 040: software ints (ipl 1f-1) */
	int	(*scb_vec31)();		/* 07c: reserved */
	int	(*scb_buserr)();	/* 080: bus error */
	int	(*scb_vec33)();		/* 084: reserved */
	int	(*scb_vec34)();		/* 088: reserved */
	int	(*scb_vec35)();		/* 08c: reserved */
	int	(*scb_vec36)();		/* 090: reserved */
	int	(*scb_vec37)();		/* 094: reserved */
	int	(*scb_vec38)();		/* 098: reserved */
	int	(*scb_vec39)();		/* 09c: reserved */
	int	(*scb_vec40)();		/* 0a0: reserved */
	int	(*scb_vec41)();		/* 0a4: reserved */
	int	(*scb_vec42)();		/* 0a8: reserved */
	int	(*scb_syscall)();	/* 0ac: system call (kcall) */
	int	(*scb_privinflt)();	/* 0b0: privileged/reserved inst */ 
	int	(*scb_respoflt)();	/* 0b4: reserved operand */
	int	(*scb_resadflt)();	/* 0b8: reserved addressing mode */
	int	(*scb_protflt)();	/* 0bc: access control violation */
	int	(*scb_transflt)();	/* 0c0: translation not valid */
	int	(*scb_kspnotval)();	/* 0c4: kernel stack invalid */
	int	(*scb_tracep)();	/* 0c8: trace trap */
	int	(*scb_bptflt)();	/* 0cc: breakpoint */
	int	(*scb_arithtrap)();	/* 0d0: arithmetic exception */
	int	(*scb_alignflt)();	/* 0d4: alignment fault */
	int	(*scb_sfexcep)();	/* 0d8: system forced exception */
	int	(*scb_fpm)();		/* 0dc: floating point emulation */
	int	(*scb_vec56)();		/* 0e0: reserved */
	int	(*scb_vec57)();		/* 0e4: reserved */
	int	(*scb_vec58)();		/* 0e8: reserved */
	int	(*scb_vec59)();		/* 0ec: reserved */
	int	(*scb_vec60)();		/* 0f0: reserved */
	int	(*scb_vec61)();		/* 0f4: reserved */
	int	(*scb_vec62)();		/* 0f8: reserved */
	int	(*scb_vec63)();		/* 0fc: reserved */
	int	(*scb_devint[192])();	/* 100: device vectors */
E 2
I 2
	int	(*scb_powfail)();	/* 001: power failure */
	int	(*scb_doadump)();	/* 002: power restore */
	int	(*scb_vec3)();		/* 003: reserved */
	int	(*scb_vec4)();		/* 004: reserved */
	int	(*scb_vec5)();		/* 005: reserved */
	int	(*scb_vec6)();		/* 006: reserved */
	int	(*scb_hardclock)();	/* 007: interval timer (clock) */
	int	(*scb_vec8)();		/* 008: reserved */
	int	(*scb_vec9)();		/* 009: reserved */
	int	(*scb_cnrint)();	/* 00a: console receive */
	int	(*scb_cnxint)();	/* 00b: console transmit */
	int	(*scb_rmtrint)();	/* 00c: remote line receive */
	int	(*scb_rmtxint)();	/* 00d: remote line transmit */
	int	(*scb_vec14)();		/* 00e: reserved */
	int	(*scb_vec15)();		/* 00f: reserved */
	int	(*scb_softint[15])();	/* 010: software ints (ipl 1f-1) */
	int	(*scb_vec31)();		/* 01f: reserved */
	int	(*scb_buserr)();	/* 020: bus error */
	int	(*scb_vec33)();		/* 021: reserved */
	int	(*scb_vec34)();		/* 022: reserved */
	int	(*scb_vec35)();		/* 023: reserved */
	int	(*scb_vec36)();		/* 024: reserved */
	int	(*scb_vec37)();		/* 025: reserved */
	int	(*scb_vec38)();		/* 026: reserved */
	int	(*scb_vec39)();		/* 027: reserved */
	int	(*scb_vec40)();		/* 028: reserved */
	int	(*scb_vec41)();		/* 029: reserved */
	int	(*scb_vec42)();		/* 02a: reserved */
	int	(*scb_syscall)();	/* 02b: system call (kcall) */
	int	(*scb_privinflt)();	/* 02c: privileged/reserved inst */ 
	int	(*scb_respoflt)();	/* 02d: reserved operand */
	int	(*scb_resadflt)();	/* 02e: reserved addressing mode */
	int	(*scb_protflt)();	/* 02f: access control violation */
	int	(*scb_transflt)();	/* 030: translation not valid */
	int	(*scb_kspnotval)();	/* 031: kernel stack invalid */
	int	(*scb_tracep)();	/* 032: trace trap */
	int	(*scb_bptflt)();	/* 033: breakpoint */
	int	(*scb_arithtrap)();	/* 034: arithmetic exception */
	int	(*scb_alignflt)();	/* 035: alignment fault */
	int	(*scb_sfexcep)();	/* 036: system forced exception */
	int	(*scb_fpm)();		/* 037: floating point emulation */
	int	(*scb_vec56)();		/* 038: reserved */
	int	(*scb_vec57)();		/* 039: reserved */
	int	(*scb_vec58)();		/* 03a: reserved */
	int	(*scb_vec59)();		/* 03b: reserved */
	int	(*scb_vec60)();		/* 03c: reserved */
	int	(*scb_vec61)();		/* 03d: reserved */
	int	(*scb_vec62)();		/* 03e: reserved */
	int	(*scb_vec63)();		/* 03f: reserved */
	int	(*scb_devint[191])();	/* 040: device vectors */
E 2
};
I 2

#define	SCB_LASTIV	(sizeof (((struct scb *)0)->scb_devint) / \
    sizeof (((struct scb *)0)->scb_devint[0]))

#ifdef KERNEL
extern	struct scb scb;
#endif
E 2
E 1
