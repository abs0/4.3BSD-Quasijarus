h57617
s 00001/00001/00104
d D 7.1 86/06/05 01:16:35 mckusick 14 13
c 4.3BSD release version
e
s 00007/00001/00098
d D 6.3 85/06/08 14:22:26 mckusick 13 12
c Add copyright
e
s 00005/00000/00094
d D 6.2 84/08/29 19:51:11 bloom 12 11
c fix include to use "ioctl.h" instead of /usr/include/sys/ioctl.h for kernel
e
s 00000/00000/00094
d D 6.1 83/07/29 07:28:59 sam 11 10
c 4.2 distribution
e
s 00005/00005/00089
d D 4.7 83/05/07 15:16:46 helge 10 9
c fixed all ioctl's (according to ioctl.h) and deleted RXIOC_MASK
e
s 00001/00000/00093
d D 4.6 83/05/06 17:47:24 helge 9 7
c added RXIOC_MASK
e
s 00001/00000/00093
d R 4.6 83/04/23 18:01:36 helge 8 7
c added RXIOC_MASK
e
s 00001/00000/00092
d D 4.5 83/04/12 14:22:34 helge 7 6
c new ioctl code
e
s 00002/00001/00090
d D 4.4 83/04/11 15:05:53 helge 6 3
c added RXES_DBLDEN
e
s 00001/00001/00090
d R 4.4 83/04/11 14:32:46 helge 5 3
c changed RXES_DENERR to RXES_DBLDEN
e
s 00002/00002/00089
d R 4.4 83/04/08 11:12:46 helge 4 3
c forgot to checkin ...
e
s 00011/00001/00080
d D 4.3 83/02/21 18:26:05 helge 3 2
c minor changes to make rx.c compile
e
s 00002/00000/00079
d D 4.2 83/02/21 15:11:40 sam 2 1
c don't include strings unless needed
e
s 00079/00000/00000
d D 4.1 83/02/08 23:13:50 sam 1 0
c date and time created 83/02/08 23:13:50 by sam
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 13

I 12
#ifdef KERNEL
#include "ioctl.h"
#else
E 12
I 10
#include <sys/ioctl.h>
I 12
#endif

E 12
E 10
/*
 * RX02 registers
 */
struct rxdevice {
	short	rxcs;		/* control/status register */
	short	rxdb;		/* data buffer register */
};

/*
 * RX211 Command and Status Register (RX2CS)
 */
#define	RX_DRV0		0x0000	/* select drive 0 */
#define	RX_DRV1		0x0010	/* select drive 1 */
#define	RX_DONE		0x0020	/* function complete */
#define	RX_INTR		0x0040	/* interrupt enable */
#define	RX_TREQ		0x0080	/* transfer request (data only)	*/
#define	RX_SDEN		0x0000	/* single density */
#define	RX_DDEN		0x0100	/* double density */
#define	RX_EXT		0x3000	/* extended address bits */
#define	RX_INIT		0x4000	/* initialize RX211 interface */
#define	RX_ERR		0x8000	/* general error bit */

/*
 * RX211 control function bits (0-3 of RX2CS)
 */
#define	RX_FILL		0x0001	/* fill the buffer */
#define	RX_EMPTY	0x0003	/* empty the buffer */
#define	RX_WRITE	0x0005	/* write the buffer to disk */
#define	RX_READ		0x0007	/* read a disk sector to the buffer */
#define	RX_FORMAT	0x0009	/* set the media density (format) */
#define	RX_RDSTAT	0x000b	/* read the disk status */
#define	RX_WDDS		0x000d	/* write a deleted-data sector */
#define	RX_RDERR	0x000f	/* read the error registers */

#define	RXCS_BITS \
"\20\20RX_ERR\17RX_INIT\11RX_DDEN\10RX_TREQ\7RX_IE\6RX_DONE\5RX_DRV1"

/*
 * RX211 Error and Status Register (RX2ES) --
 * information is located in RX2DB after completion of function.
 * The READY bit's value is available only after a "read status".
 */
#define	RXES_CRCERR	0x0001	/* CRC error (data read error) */
#define	RXES_IDONE	0x0004	/* reinitialization complete */
D 6
#define	RXES_DENERR	0x0010	/* density error (mismatch) */
E 6
I 6
#define RXES_DENERR	0x0010	/* density error */
#define	RXES_DBLDEN	0x0020	/* set if double density */
E 6
#define	RXES_DDMARK	0x0040	/* deleted-data mark */
#define	RXES_READY	0x0080	/* drive is ready */

#define	RXES_BITS \
"\20\14RXES_NXM\13RXES_WCOF\11RXES_DRV1\10RXES_RDY\7RXES_DDMK\6RXES_DDEN\5\
RXES_DNER\4RXES_ACLO\3RXES_ID\1RXES_CRC"

I 3
/* 
 * Ioctl commands, move to dkio.h later
 */
D 10
#define RXIOC_FORMAT	(('d'<<8)|1)	/* format the disk */
#define RXIOC_WDDS	(('d'<<8)|2)	/* write `deleted data' mark */
E 10
I 10
#define RXIOC_FORMAT	_IOW(d, 1, int)	/* format the disk */
#define RXIOC_WDDS	_IOW(d, 2, int)	/* write `deleted data' mark */
E 10
					/* on next sector */
D 10
#define RXIOC_RDDSMK	(('d'<<8)|3)	/* did last read sector contain */
E 10
I 10
#define RXIOC_RDDSMK	_IOR(d, 3, int)	/* did last read sector contain */
E 10
					/* `deleted data'?*/
I 7
D 10
#define	RXIOC_GDENS	(('d'<<8)|4)	/* return density of current disk */
I 9
#define	RXIOC_MASK	0x0ffff		/* mask for ioctl codes */
E 10
I 10
#define	RXIOC_GDENS	_IOR(d, 4, int)	/* return density of current disk */
E 10
E 9
E 7

E 3
I 2
#ifdef RXDEFERR
E 2
/*
 * Table of values for definitive error code (rxxt[0] & 0xff)
 */
struct rxdeferr {
	short	errval;
	char	*errmsg;
} rxdeferr[] = {
	{ 0010,	"Can't find home on drive 0" },
	{ 0020,	"Can't find home on drive 1" },
	{ 0040,	"Bad track number requested" },
	{ 0050,	"Home found too soon" },
	{ 0070,	"Can't find desired sector" },
	{ 0110,	"No SEP clock seen" },
	{ 0120,	"No preamble found" },
	{ 0130,	"Preamble, but no ID mark" },
I 3
	{ 0140, "Header CRC error"},
E 3
	{ 0150,	"Track addr wrong in header" },
	{ 0160,	"Too many tries for ID AM" },
	{ 0170,	"No data AM found" },
D 3
	{ 0200,	"CRC error" },
E 3
I 3
	{ 0200,	"Data CRC error" },
E 3
	{ 0220,	"Maintenance test failure" },
	{ 0230,	"Word count overflow" },
	{ 0240,	"Density error" },
	{ 0250,	"Set-density protocol bad" },
	{ 0,	"Undefined error code" }
};
I 2
#endif
E 2
E 1
