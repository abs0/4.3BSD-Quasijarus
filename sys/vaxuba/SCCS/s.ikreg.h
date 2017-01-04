h06162
s 00001/00001/00113
d D 7.1 86/06/05 01:11:02 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00107
d D 6.2 85/06/08 14:17:29 mckusick 7 6
c Add copyright
e
s 00000/00000/00108
d D 6.1 83/08/13 12:39:37 sam 6 5
c 4.2 distribution
e
s 00001/00001/00107
d D 4.4 83/08/13 12:37:08 sam 5 3
c update from reeves; tested with 4.2
e
s 00000/00000/00108
d R 6.1 83/07/29 07:27:57 sam 4 3
c 4.2 distribution
e
s 00008/00008/00100
d D 4.3 82/10/21 21:20:22 root 3 2
c lint
e
s 00004/00002/00104
d D 4.2 82/08/01 19:20:12 sam 2 1
c new ioctl's
e
s 00106/00000/00000
d D 4.1 82/06/26 14:04:59 sam 1 0
c date and time created 82/06/26 14:04:59 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

struct ikdevice {
D 3
	short int ik_wc;			/* Unibus word count reg */
	unsigned short int ik_ubaddr;		/* Unibus address register */
	unsigned short int ik_ustat;		/* Unibus status/command reg */
	unsigned short int ik_data;		/* Data register */
	unsigned short int ik_xaddr;		/* X address in frame buffer */
	unsigned short int ik_yaddr;		/* Y address in frame buffer */
	unsigned short int ik_istat;		/* Ikonas status/command reg */
	unsigned short int ik_dummy;
E 3
I 3
	short	ik_wc;			/* Unibus word count reg */
	u_short	ik_ubaddr;		/* Unibus address register */
	u_short	ik_ustat;		/* Unibus status/command reg */
	u_short	ik_data;		/* Data register */
	u_short	ik_xaddr;		/* X address in frame buffer */
	u_short	ik_yaddr;		/* Y address in frame buffer */
	u_short	ik_istat;		/* Ikonas status/command reg */
D 5
	u_short	ik_dummy;
E 5
I 5
	u_short	ik_chan;		/* Channel control register */
E 5
E 3
};

D 2
#define IK_GETADDR (('i'<<8)|0)
#define IK_WAITINT (('i'<<8)|1)
E 2
I 2
#define IK_GETADDR 	IKIOGETADDR
#define IK_WAITINT 	IKIOWAITINT
#define	IKIOGETADDR	_IOR(i, 0, caddr_t)	/* get Unibus device address */
#define	IKIOWAITINT	_IO(i, 1)		/* await device interrupt */
E 2

/*
 * Unibus status/command register bits
 */

#define IK_GO		01
#define IK_IENABLE	0100
#define IK_READY	0200
#define IK_IKONAS_INTR	0100000

/*
 * Ikonas status/command register bits
 */

#define WORD32		0
#define RES512		2
#define RES1024		3
#define READ_SELECT	0
#define WRITE_MASK	010
#define WRITE_SELECT	020
#define HALFWORD	040
#define DMAENABLE	0100
#define INVISIBLE_IO	0200
#define AUTOINCREMENT	0400
#define RUN_PROCESSOR	01000
#define CLEAR		02000
#define BYTE_MODE	04000
#define FRAME_ENABLE	010000
#define PROC_ENABLE	020000
#define RED_SELECT	0
#define GREEN_SELECT	040000
#define BLUE_SELECT	0100000
#define ALPHA_SELECT	0140000

/*
 * Frame buffer controller
 */

#define FBC0		060000000
#define FBC1		062000000

#define VIEWPORT_LOC	0
#define VIEWPORT_SIZE	1
#define WINDOW_LOC	2
#define ZOOM		3
#define DISPLAY_RATE	4
#define VIDEO_CONTROL	5
#define		FORMAT_CONTROL_MASK	03
#define		CURSOR_ON		04
#define		LOW_RESOL		0
#define		HIGH_RESOL		010
#define		AUTO_CLEAR		040
#define		EXT_SYNC		0100
#define		COLOR_MAP_PAGES		0600
#define		HIGH_RESOL_SYNC		01000
#define		REPEAT_FIELD		02000
#define		PIXEL_CLOCK_RATE_MASK	077
#define CURSOR_LOC	6
#define CURSOR_SHADE	7

#define CURSOR_MAP	0400

/*
 * Color map lookup table
 */

#define CMAP0		040600000
#define CMAP1		040610000

#define CHAN_SELECT	02000

/*
 * Frame buffer memories
 */

#define MEM0		000000000
#define MEM1		004000000

/*
 * Bit-slice processor
 */

#define UMEM		040000000
#define SCRPAD		040400000
#define PROC		041200000

/*
 * Frame grabber
 */

#define FMG0		060200000
E 1
