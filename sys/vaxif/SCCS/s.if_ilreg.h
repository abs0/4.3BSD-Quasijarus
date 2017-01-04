h20757
s 00013/00002/00120
d D 7.2 88/08/04 15:25:50 bostic 7 6
c add Berkeley specific copyright
e
s 00001/00001/00121
d D 7.1 86/06/05 01:37:31 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00115
d D 6.2 85/06/08 13:58:37 mckusick 5 4
c Add copyright
e
s 00000/00000/00116
d D 6.1 83/07/29 07:38:20 sam 4 3
c 4.2 distribution
e
s 00006/00000/00110
d D 4.3 82/11/13 23:05:22 sam 3 2
c merge 4.1b with 4.1c
e
s 00063/00029/00047
d D 4.2 82/06/23 21:11:17 sam 2 1
c add error codes, don't use strings anymore
e
s 00076/00000/00000
d D 4.1 82/05/21 15:55:57 feldman 1 0
c date and time created 82/05/21 15:55:57 by feldman
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Interlan Ethernet Communications Controller interface
 */
struct ildevice {
	short	il_csr;		/* Command and Status Register */
	short	il_bar;		/* Buffer Address Register */
	short	il_bcr;		/* Byte Count Register */
};

/*
 * Command and status bits
 */
D 2
#define	IL_EUA		0xC000		/* Extended Unibus Address */
E 2
I 2
#define	IL_EUA		0xc000		/* Extended Unibus Address */
E 2
#define	IL_CMD		0x3f00		/* Command Function Code */
#define	IL_CDONE	0x0080		/* Command Done */
#define	IL_CIE		0x0040		/* Command Interrupt Enable */
#define	IL_RDONE	0x0020		/* Receive DMA Done */
#define	IL_RIE		0x0010		/* Receive Interrupt Enable */
#define	IL_STATUS	0x000f		/* Command Status Code */

D 2
#define	IL_BITS		"\10\10CDONE\7CIE\6RDONE\5RIE"
E 2
I 2
#define	IL_BITS		"\20\10CDONE\7CIE\6RDONE\5RIE"
E 2

D 2
/* Command definitions */

E 2
I 2
/* command definitions */
E 2
#define	ILC_MLPBAK	0x0100		/* Set Module Interface Loopback Mode */
#define	ILC_ILPBAK	0x0200		/* Set Internal Loopback Mode */
#define	ILC_CLPBAK	0x0300		/* Clear Loopback Mode */
#define	ILC_PRMSC	0x0400		/* Set Promiscuous Receive Mode */
#define	ILC_CLPRMSC	0x0500		/* Clear Promiscuous Receive Mode */
#define	ILC_RCVERR	0x0600		/* Set Receive-On-Error Bit */
#define	ILC_CRCVERR	0x0700		/* Clear Receive-On-Error Bit */
#define	ILC_OFFLINE	0x0800		/* Go Offline */
#define	ILC_ONLINE	0x0900		/* Go Online */
#define	ILC_DIAG	0x0a00		/* Run On-board Diagnostics */
I 3
#define	ILC_ISA		0x0d00		/* Set Insert Source Address Mode */
#define	ILC_CISA	0x0e00		/* Clear Insert Source Address Mode */
#define	ILC_DEFPA	0x0f00		/* Set Physical Address to Default */
#define	ILC_ALLMC	0x1000		/* Set Receive All Multicast Packets */
#define	ILC_CALLMC	0x1100		/* Clear Receive All Multicast */
E 3
#define	ILC_STAT	0x1800		/* Report and Reset Statistics */
#define	ILC_DELAYS	0x1900		/* Report Collision Delay Times */
#define	ILC_RCV		0x2000		/* Supply Receive Buffer */
#define	ILC_LDXMIT	0x2800		/* Load Transmit Data */
#define	ILC_XMIT	0x2900		/* Load Transmit Data and Send */
#define	ILC_LDGRPS	0x2a00		/* Load Group Addresses */
#define	ILC_RMGRPS	0x2b00		/* Delete Group Addresses */
I 3
#define	ILC_LDPA	0x2c00		/* Load Physical Address */
E 3
#define	ILC_FLUSH	0x3000		/* Flush Receive BAR/BCR Queue */
#define	ILC_RESET	0x3f00		/* Reset */

/*
D 2
 * Error codes
E 2
I 2
 * Error codes found in the status bits of the csr.
E 2
 */
D 2
char *ilerrs[] = {
			"success",			/* 0 */
			"success with retries", 	/* 01 */
			"illegal command",		/* 02 */
			"inappropriate command",	/* 03 */
			"failure",			/* 04 */
			"buffer size exceeded",		/* 05 */
			"frame too small",		/* 06 */
			0,				/* 07 */
			"excessive collisions",		/* 010 */
			0,				/* 011 */
			"buffer alignment error",	/* 012 */
			0,				/* 013 */
			0,				/* 014 */
			0,				/* 015 */
			0,				/* 016 */
			"non-existent memory"		/* 017 */
E 2
I 2
#define	ILERR_SUCCESS		0	/* command successful */
#define	ILERR_RETRIES		1	/* " " with retries */
#define	ILERR_BADCMD		2	/* illegal command */
#define	ILERR_INVCMD		3	/* invalid command */
#define	ILERR_RECVERR		4	/* receiver error */
#define	ILERR_BUFSIZ		5	/* buffer size too big */
#define	ILERR_FRAMESIZ		6	/* frame size too small */
#define	ILERR_COLLISIONS	8	/* excessive collisions */
#define	ILERR_BUFALIGNMENT	10	/* buffer not word aligned */
#define	ILERR_NXM		15	/* non-existent memory */

#define	NILERRS			16
#ifdef ILERRS
char *ilerrs[NILERRS] = {
	"success",			/*  0 */
	"success with retries", 	/*  1 */
	"illegal command",		/*  2 */
	"inappropriate command",	/*  3 */
	"failure",			/*  4 */
	"buffer size exceeded",		/*  5 */
	"frame too small",		/*  6 */
	0,				/*  7 */
	"excessive collisions",		/*  8 */
	0,				/*  9 */
	"buffer alignment error",	/* 10 */
	0,				/* 11 */
	0,				/* 12 */
	0,				/* 13 */
	0,				/* 14 */
	"non-existent memory"		/* 15 */
E 2
};
I 2
#endif
E 2

D 2
char *ildiag[] = {
			"success",			/* 0 */
			"checksum error",		/* 1 */
			"NM10 dma error",		/* 2 */
			"transmitter error",		/* 3 */
			"receiver error",		/* 4 */
			"loopback failure",		/* 5 */
E 2
I 2
/*
 * Diagnostics codes.
 */
#define	ILDIAG_SUCCESS		0	/* no problems */
#define	ILDIAG_CHKSUMERR	1	/* ROM/RAM checksum error */
#define	ILDIAG_DMAERR		2	/* DMA not working */
#define	ILDIAG_XMITERR		3	/* xmit circuitry failure */
#define	ILDIAG_RECVERR		4	/* rcvr circuitry failure */
#define	ILDIAG_LOOPBACK		5	/* loopback test failed */

#define	NILDIAGS		6
#ifdef ILDIAGS
char *ildiag[NILDIAGS] = {
	"success",			/* 0 */
	"checksum error",		/* 1 */
	"NM10 dma error",		/* 2 */
	"transmitter error",		/* 3 */
	"receiver error",		/* 4 */
	"loopback failure",		/* 5 */
E 2
};
I 2
#endif

/*
 * Frame status bits, returned in frame status byte
 * at the top of each received packet.
 */
#define	ILFSTAT_C	0x1		/* CRC error */
#define	ILFSTAT_A	0x2		/* alignment error */
#define	ILFSTAT_L	0x4		/* 1+ frames lost just before */
E 2
E 1
