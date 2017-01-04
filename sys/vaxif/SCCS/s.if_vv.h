h51527
s 00013/00002/00110
d D 7.2 88/08/04 15:31:21 bostic 13 12
c add Berkeley specific copyright
e
s 00001/00001/00111
d D 7.1 86/06/05 01:38:52 mckusick 12 11
c 4.3BSD release version
e
s 00002/00006/00110
d D 4.10 86/03/27 16:25:00 jas 11 10
c New trailer shceme that is not antisocial
c 
e
s 00001/00001/00115
d D 4.9 86/03/18 19:02:56 jas 10 9
c - Add data present to the list of receive error bits
c 				john shriver, proteon
c 
e
s 00007/00001/00109
d D 4.8 85/06/08 14:01:47 mckusick 9 8
c Add copyright
e
s 00036/00013/00074
d D 4.7 85/06/03 08:42:49 karels 8 7
c now they compile at least
e
s 00003/00001/00084
d D 4.6 84/01/03 16:46:22 leres 7 6
c Add defines for the identify loop retry limit and transmit timeout time
e
s 00001/00001/00084
d D 4.5 83/07/29 07:40:16 sam 6 4
c 4.2 distribution
e
s 00000/00000/00085
d R 6.1 83/07/29 07:38:58 sam 5 4
c 4.2 distribution
e
s 00002/00002/00083
d D 4.4 83/05/10 10:55:33 mo 4 3
c changed sleeps on lbolt to delays 'cause lbolt doesn't run 
e
s 00009/00007/00076
d D 4.3 83/02/20 23:36:32 sam 3 2
c new version from mike odell
e
s 00006/00001/00077
d D 4.2 82/08/01 19:31:46 sam 2 1
c added trailers (from mo@lbl-unix)
e
s 00078/00000/00000
d D 4.1 82/06/04 10:57:10 sam 1 0
c date and time created 82/06/04 10:57:10 by sam
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
D 6
/*	if_vv.h	4.3	83/02/20	*/
E 6
I 6
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 12
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
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
E 13
 *
 *	%W% (Berkeley) %G%
 */
E 9
I 8

E 8
E 6
E 4
/*
D 8
 * Local network header for V2LNI Ring
 * This is arbitrated by "V2LNI-PEOPLE@MIT-MC"
 * (aka Joel N. Chiappa)
E 8
I 8
 * ECO 176-748 changed the braodcast address from 0 to 0xff, at
 * CTL (p1002) serial number around 150.
 * It was implemented in August, 1982. This is a field-installable ECO,
 * which improves net reliability. If the broadcast address has not been
 * changed, comment out the following line.
E 8
 */
I 8
#define	NEW_BROADCAST		/* new chip for broadcast problem */
E 8
I 3

D 4
#undef	NEW_BROADCAST		/* new plas for broadcast problem */
E 4
I 4
D 8
#define	NEW_BROADCAST		/* new plas for broadcast problem */
E 8
I 8
/*
 * Local network header for proNET Ring
 * This is arbitrated by "jas@proteon"
 * (aka John Shriver, 617-655-3340)
 */
E 8
E 4

E 3
D 2

E 2
struct vv_header {
	 /* the first two fields are required by the hardware */
	u_char	vh_dhost;	/* destination address */
	u_char	vh_shost;	/* source address */
	/* the next three fields are the local network header */
	u_char	vh_version;	/* header version */
	u_char	vh_type;	/* packet type => protocol number */
	short	vh_info;	/* protocol-specific information */
};

D 3
#define	RING_VERSION	1	/* current version of v2lni header */
E 3
I 3
#define	RING_VERSION	2	/* current version of v2lni header */
E 3

/*
D 8
 * Packet types (protocol numbers) in v2lni header
E 8
I 8
 * Packet types (protocol numbers) in proNET protocol header
 * Other types are defined, but are proprietary.
E 8
I 2
D 3
 *
 * NOTE: the Trailer format stuff is lifted right out of
 * the other drivers.  It will be changed to take advantage
 * of the fields in the vv_header, but the packet throw-away
 * code must first be improved.
E 3
E 2
 */
#define	RING_IP		1
D 8
#define	RING_IPTrailer	2
I 2
#define	RING_IPNTrailer	16
E 2
#define	RING_WHOAMI	0xa5	/* insure some bit transitions */
E 8
I 8
D 11
#define	RING_IPTrailer	2	/* really, 3 = 512 bytes */
				/*         4 = 1024 bytes */
				/*         5 = 1536 bytes */
				/* it's really very messed-up! */
#define	RING_IPNTrailer	4	/* not a number, but a range */
#define RING_ARP	3	/* the next three conflict with trailers */
E 11
I 11
#define	RING_TRAILER	2	/* offset now in vh_info only */
#define RING_ARP	3
E 11
#define RING_HDLC	4
#define RING_VAXDB	5
#define RING_RINGWAY	6
#define RING_RINGWAYM	8
#define	RING_NOVELL	10
#define RING_PUP	12
#define RING_XNS	14
#define	RING_DIAGNOSTICS 15	/* protocol type for testing */
#define	RING_ECHO	16
E 8

D 3
#define	VV_BROADCAST	0	/* hardware-defined broadcast address */
E 3
I 3
#ifdef NEW_BROADCAST
#define	VV_BROADCAST	0xff	/* hardware-defined broadcast address */
#else
#define	VV_BROADCAST	0x00	/* hardware-defined broadcast address */
#endif
E 3

/*
D 8
 * Proteon V2LNI Hardware definitions
 * register bit definitions - new style
E 8
I 8
 * Proteon proNET Hardware definitions
 * register bit definitions
E 8
 */
#define	VV_ENB	01		/* Enable Operation */
#define	VV_DEN	02		/* Enable DMA */
#define	VV_HEN	04		/* Host Relay Enable (Rcv) */
#define	VV_CPB	04		/* Clear Packet Buffer (Xmit) */
#define	VV_STE	010		/* Self Test Enable (Rcv) */
#define	VV_UT1	010		/* Unused (Xmit) */
#define	VV_LPB	020		/* Modem Disable (Rcv) */
#define	VV_INR	020		/* Initialize Ring (Xmit) */
#define	VV_RST	040		/* Reset */
#define	VV_IEN	0100		/* Interrupt Enable */
#define	VV_RDY	0200		/* Done */
#define	VV_DPR	0400		/* Data Present (Rcv) */
#define	VV_RFS	0400		/* Refused (Xmit) */
#define	VV_NXM	01000		/* Non Existent Memory */
#define	VV_OVR	02000		/* Overrun */
D 8
#define	VV_ODB	04000		/* Odd Byte (Achtung, mein Fuehrer) (Rcv) */
E 8
I 8
#define	VV_ODB	04000		/* Odd Byte (Rcv) */
E 8
#define	VV_UT2	04000		/* Unused (Xmit) */
D 8
#define	VV_LDE	010000		/* Link Data Error (Rcv) */
E 8
I 8
#define	VV_LDE	010000		/* Parity on 10 megabit (Rcv), */
				/* Link Data Error on 80 megabit (Rcv) */
E 8
#define	VV_OPT	010000		/* Output Timeout (Xmit) */
#define	VV_NOK	020000		/* Ring Not OK */
#define	VV_BDF	040000		/* Bad Format in Operation */
#define	VV_NIR	0100000		/* Not in Ring */

#define	VVXERR	(VV_NXM|VV_OVR|VV_OPT|VV_BDF)	/* Xmit errs */
D 10
#define	VVRERR	(VV_NXM|VV_OVR|VV_ODB|VV_BDF)	/* Rcv errs */
E 10
I 10
#define	VVRERR	(VV_NXM|VV_OVR|VV_ODB|VV_BDF|VV_DPR)	/* Rcv errs */
E 10
#define	VVFE	(VV_NXM|VV_OVR)			/* Fatal errors */

#define VV_IBITS \
"\10\20NIR\17BDF\16NOK\15LDE\14ODB\13OVR\12NXM\11DPR\10RDY\7IEN\6RST\5LPB\4STE\3HEN\2DEN\1ENB"

#define VV_OBITS \
"\10\20NIR\17BDF\16NOK\15OPT\13OVR\12NXM\11RFS\10RDY\7IEN\6RST\5INR\3HEN\2DEN\1ENB"

/* device registers */
struct vvreg {
	short	vvicsr;		/* input csr */
	u_short	vviwc;		/* input word count */
	u_short	vviba;		/* input addr lo */
	u_short	vviea;		/* input addr hi */
	short	vvocsr;		/* output csr */
	u_short	vvowc;		/* output word count */
	u_short	vvoba;		/* output addr lo */
	u_short	vvoea;		/* output addr hi */
};

D 7
#define	VVRETRY	7
E 7
I 7
#define	VVRETRY	7		/* output retry limit */
D 8
#define VVIDENTRETRY 10		/* identify loop retry limit */
E 8
I 8
#define VVIDENTSUCC 5		/* number of successes required in self-test */
#define VVIDENTRETRY 10		/* identify loop attempt limit */
E 8
#define VVTIMEOUT 60		/* seconds before a transmit timeout */
E 7
E 1
