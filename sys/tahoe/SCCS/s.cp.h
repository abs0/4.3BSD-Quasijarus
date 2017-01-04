h59316
s 00003/00001/00056
d D 7.1 88/05/21 18:35:08 karels 4 3
c bring up to revision 7 for tahoe release
e
s 00010/00000/00047
d D 1.3 87/02/16 19:21:17 karels 3 2
c add magic locations for bootopts, etc.
e
s 00023/00023/00024
d D 1.2 86/12/06 22:34:36 sam 2 1
c set interval timer value at boot time according to hz
e
s 00047/00000/00000
d D 1.1 86/01/05 18:46:19 sam 1 0
c date and time created 86/01/05 18:46:19 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 *	%W% (Berkeley) %G%
 */
E 4
D 2
/*	Console Processor Interface 	*/
/*	Tahoe version, Nov. 1982	*/
E 2

D 2
/****************************************/
/*					*/
/*	Reduced DCB layout for byte	*/
/*	communication.			*/
/*					*/
/****************************************/
E 2
I 2
/*
 * Tahoe console processor interface
 */
E 2

I 2
/*
 * Reduced DCB layout for byte communication.
 */
E 2
#define	CPBUFLEN 200		/* Output buffer length */
#ifndef	LOCORE
D 2
struct	cphdr
{
E 2
I 2
struct	cphdr {
E 2
	char	cp_unit;	/* Done bit & unit # */
	char	cp_comm;	/* Command */
	short	cp_count;	/* Counter (when relevant) */
};

D 2
struct	cpdcb_o			/* Output structure */
{
E 2
I 2
struct	cpdcb_o {		/* Output structure */
E 2
	struct	cphdr	cp_hdr;
	char	cp_buf[CPBUFLEN]; /* Buffer for output or 'stty' */
};

D 2
struct	cpdcb_i			/* Structure for input */
{
E 2
I 2
struct	cpdcb_i {		/* Structure for input */
E 2
	struct	cphdr	cp_hdr;
	char	cpi_buf[4]; 	/* Buffer for input */
};
#endif

#define	CPDONE	0x80		/* 'Done' bit in cp_unit */
#define	CPTAKE	0x40		/* CP 'ack' to this cpdcb */

D 2
		/* Values for 'unit' */
#define	CPUNIT	0		/* The CP itself */
#define	CPCONS	1		/* Console line */
#define	CPREMOT	2		/* Remote line */
E 2
I 2
/* unit values */
#define	CPUNIT	0		/* the CP itself */
#define	CPCONS	1		/* console line */
#define	CPREMOT	2		/* remote line */
#define	CPCLOCK	4		/* realtime clock */
E 2

D 2
		/* Values for 'command' */
E 2
I 2
/* commands */
E 2
#define	CPRESET 0
D 2
#define	CPWRITE 1
#define	CPREAD	2
#define	CPSTTY	3
#define	CPBOOT	4
E 2
I 2
#define	CPWRITE 1		/* write device or register */
#define	CPREAD	2		/* read device or register */
#define	CPSTTY	3		/* set terminal configuration */
#define	CPBOOT	4		/* reboot system */

I 3
/*
 *	CP specific locations
 */
#define	CPBFLG	0xc0000500	/* System bootflag flags */
#define	CPYFLG	0xc0000504	/* Copy of the Y flag */
#define	CPOPTS	0xc0000508	/* copy of CP options */
#define CPRSRV	0xc000050c	/* reserved for CP usage */
#define	CPBDEV	0xc0000510	/* Bootstrap device, saved on boot */
#define	CPEDEV	0xc000052f	/* End of device name */

E 3
#if !defined(LOCORE) && defined(KERNEL)
struct	cphdr *cnlast;		/* last command sent to cp */
#endif
E 2
E 1
