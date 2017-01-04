h32627
s 00000/00000/00082
d D 7.1 86/06/05 01:18:20 mckusick 4 3
c 4.3BSD release version
e
s 00023/00021/00059
d D 5.2 86/04/28 01:39:33 kjd 3 2
c Add DEC copyright
e
s 00006/00011/00074
d D 5.1 86/02/11 17:09:58 karels 2 1
c convert to 4.3
e
s 00085/00000/00000
d D 1.1 86/02/10 15:07:54 karels 1 0
c from DEC
e
u
U
t
T
I 2
/* %W% (Berkeley) %G% */
E 2
I 1

/*	@(#)tmscpreg.h	1.1	11/2/84	84/09/25	*/

D 3
/************************************************************************
 *									*
 *			Copyright (c) 1985 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
 *									*
 *	Permission to use, copy, modify, and distribute this software	*
 *	and its documentation is hereby granted to licensees of the	*
 *	Regents of the University of California pursuant to their	*
 *	license agreement for the "Fourth Berkeley Software		*
 *	Distribution".							*
 *									*
 *	The information in this software is subject to change without	*
 *	notice and should not be construed as a commitment by Digital	*
 *	Equipment Corporation.  Digital makes no representations	*
 *	about suitability of this software for any purpose. It is	*
 *	supplied "as is" without express or implied warranty.		*
 *									*
 *	This software is not subject to any license of the American	*
 *	Telephone and Telegraph Company.				*
 *									*
 ************************************************************************/
E 3
I 3
/****************************************************************
 *								*
 *        Licensed from Digital Equipment Corporation 		*
 *                       Copyright (c) 				*
 *               Digital Equipment Corporation			*
 *                   Maynard, Massachusetts 			*
 *                         1985, 1986 				*
 *                    All rights reserved. 			*
 *								*
 *        The Information in this software is subject to change *
 *   without notice and should not be construed as a commitment *
 *   by  Digital  Equipment  Corporation.   Digital   makes  no *
 *   representations about the suitability of this software for *
 *   any purpose.  It is supplied "As Is" without expressed  or *
 *   implied  warranty. 					*
 *								*
 *        If the Regents of the University of California or its *
 *   licensees modify the software in a manner creating  	*
 *   diriviative copyright rights, appropriate copyright  	*
 *   legends may be placed on  the drivative work in addition   *
 *   to that set forth above. 					*
 *								*
 ****************************************************************/
E 3
/*
 * TMSCP registers and structures
 */
 
struct tmscpdevice {
	short	tmscpip;	/* initialization and polling */
	short	tmscpsa;	/* status and address */
};
 
#define	TMSCP_ERR		0100000	/* error bit */
#define	TMSCP_STEP4	0040000	/* step 4 has started */
#define	TMSCP_STEP3	0020000	/* step 3 has started */
#define	TMSCP_STEP2	0010000	/* step 2 has started */
#define	TMSCP_STEP1	0004000	/* step 1 has started */
#define	TMSCP_NV		0002000	/* no host settable interrupt vector */
#define	TMSCP_QB		0001000	/* controller supports Q22 bus */
#define	TMSCP_DI		0000400	/* controller implements diagnostics */
D 2
#define	TMSCP_OD		0000200	/* port allows odd host addr's in the b
uffer descriptor */
E 2
I 2
#define	TMSCP_OD		0000200	/* port allows odd host addr's in the buffer descriptor */
E 2
#define	TMSCP_IE		0000200	/* interrupt enable */
#define	TMSCP_MP		0000100	/* port supports address mapping */
D 2
#define	TMSCP_LF		0000002	/* host requests last fail response pac
ket */
#define	TMSCP_PI		0000001	/* host requests adapter purge interrup
ts */
E 2
I 2
#define	TMSCP_LF		0000002	/* host requests last fail response packet */
#define	TMSCP_PI		0000001	/* host requests adapter purge interrupts */
E 2
#define	TMSCP_GO		0000001	/* start operation, after init */
 
 
/*
 * TMSCP Communications Area
 */
 
struct tmscpca {
	short	ca_xxx1;	/* unused */
	char	ca_xxx2;	/* unused */
	char	ca_bdp;		/* BDP to purge */
	short	ca_cmdint;	/* command queue transition interrupt flag */
	short	ca_rspint;	/* response queue transition interrupt flag */
	long	ca_rspdsc[NRSP];/* response descriptors */
	long	ca_cmddsc[NCMD];/* command descriptors */
};
 
#define	ca_ringbase	ca_rspdsc[0]
 
#define	TMSCP_OWN	0x80000000	/* port owns this descriptor (else host
 owns it) */
D 2
#define	TMSCP_INT	0x40000000	/* allow interrupt on ring transition *
/
E 2
I 2
#define	TMSCP_INT	0x40000000	/* allow interrupt on ring transition */
E 2
 
D 2
#define	TMSCP_MAP	0x80000000	/* modifier for mapped buffer descripto
rs */
E 2
I 2
#define	TMSCP_MAP	0x80000000	/* modifier for mapped buffer descriptors */
E 2
 
/*
 * TMSCP packet info (same as MSCP)
 */
struct mscp_header {
	short	tmscp_msglen;	/* length of MSCP packet */
	char	tmscp_credits;	/* low 4 bits: credits, high 4 bits: msgtype */
	char	tmscp_vcid;	/* virtual circuit id (connection id) */
};
D 2

E 2
E 1
