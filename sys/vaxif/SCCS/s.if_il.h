h33318
s 00013/00002/00050
d D 7.2 88/08/04 15:25:48 bostic 10 9
c add Berkeley specific copyright
e
s 00001/00001/00051
d D 7.1 86/06/05 01:37:17 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00045
d D 6.4 85/06/08 13:58:25 mckusick 8 7
c Add copyright
e
s 00003/00003/00043
d D 6.3 85/05/01 09:09:36 karels 7 6
c move interface addresses into protocols; remove struct ether_addr again
e
s 00003/00003/00043
d D 6.2 84/03/22 15:09:45 karels 6 5
c new address resolution protocol; struct ether_addr
e
s 00000/00000/00046
d D 6.1 83/07/29 07:38:18 sam 5 4
c 4.2 distribution
e
s 00000/00021/00046
d D 4.4 82/12/16 15:40:44 sam 4 3
c fix byte swapping problems in header
e
s 00002/00000/00065
d D 4.3 82/11/13 23:05:18 sam 3 2
c merge 4.1b with 4.1c
e
s 00002/00002/00063
d D 4.2 82/06/23 21:09:02 sam 2 1
c remove csr crap; add stat collection through watchdog routine
e
s 00065/00000/00000
d D 4.1 82/05/21 15:55:40 feldman 1 0
c date and time created 82/05/21 15:55:40 by feldman
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
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
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
E 10
 *
 *	%W% (Berkeley) %G%
 */
E 8

/*
D 4
 * Structure of an Ethernet header -- transmit format
I 3
 *	(source address insertion disabled)
E 3
 */
struct	il_xheader {
	u_char	ilx_dhost[6];		/* Destination Host */
I 3
	u_char	ilx_shost[6];		/* Source Host */
E 3
	u_short	ilx_type;		/* Type of packet */
};

/*
E 4
 * Structure of an Ethernet header -- receive format
 */
struct	il_rheader {
	u_char	ilr_status;		/* Frame Status */
	u_char	ilr_fill1;
	u_short	ilr_length;		/* Frame Length */
D 6
	u_char	ilr_dhost[6];		/* Destination Host */
	u_char	ilr_shost[6];		/* Source Host */
E 6
I 6
D 7
	struct ether_addr ilr_dhost;	/* Destination Host */
	struct ether_addr ilr_shost;	/* Source Host */
E 7
I 7
	u_char	ilr_dhost[6];		/* Destination Host */
	u_char	ilr_shost[6];		/* Source Host */
E 7
E 6
	u_short	ilr_type;		/* Type of packet */
};
D 4

#define	ILPUP_PUPTYPE	0x0400		/* PUP protocol */
#define	ILPUP_IPTYPE	0x0800		/* IP protocol */

/*
 * The ILPUP_NTRAILER packet types starting at ILPUP_TRAIL have
 * (type-ILPUP_TRAIL)*512 bytes of data followed
 * by a PUP type (as given above) and then the (variable-length) header.
 */
#define	ILPUP_TRAIL	0x1000		/* Trailer PUP */
#define	ILPUP_NTRAILER	16
E 4

/*
D 2
 * Structure of Statistics Record
E 2
I 2
 * Structure of statistics record
E 2
 */
D 2
struct	il_stat {
E 2
I 2
struct	il_stats {
E 2
	u_short	ils_fill1;
	u_short	ils_length;		/* Length (should be 62) */
D 6
	u_char	ils_addr[6];		/* Ethernet Address */
E 6
I 6
D 7
	struct ether_addr ils_addr;	/* Ethernet Address */
E 7
I 7
	u_char	ils_addr[6];		/* Ethernet Address */
E 7
E 6
	u_short	ils_frames;		/* Number of Frames Received */
	u_short	ils_rfifo;		/* Number of Frames in Receive FIFO */
	u_short	ils_xmit;		/* Number of Frames Transmitted */
	u_short	ils_xcollis;		/* Number of Excess Collisions */
	u_short	ils_frag;		/* Number of Fragments Received */
	u_short	ils_lost;		/* Number of Times Frames Lost */
	u_short	ils_multi;		/* Number of Multicasts Accepted */
	u_short	ils_rmulti;		/* Number of Multicasts Rejected */
	u_short	ils_crc;		/* Number of CRC Errors */
	u_short	ils_align;		/* Number of Alignment Errors */
	u_short	ils_collis;		/* Number of Collisions */
	u_short	ils_owcollis;		/* Number of Out-of-window Collisions */
	u_short	ils_fill2[8];
	char	ils_module[8];		/* Module ID */
	char	ils_firmware[8];	/* Firmware ID */
};

/*
 * Structure of Collision Delay Time Record
 */
struct	il_collis {
	u_short	ilc_fill1;
	u_short	ilc_length;		/* Length (should be 0-32) */
	u_short	ilc_delay[16];		/* Delay Times */
};
E 1
