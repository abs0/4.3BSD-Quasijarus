h59561
s 00001/00001/00050
d D 7.1 86/06/05 00:43:26 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00044
d D 6.2 85/06/08 13:42:00 mckusick 8 7
c Add copyright
e
s 00000/00000/00045
d D 6.1 83/07/29 07:19:50 sam 7 6
c 4.2 distribution
e
s 00001/00001/00044
d D 4.4 81/02/25 23:35:53 wnj 6 5
c convert VAX=??? to VAX???
e
s 00001/00001/00044
d D 4.3 81/02/19 21:40:32 wnj 5 4
c %G%->%E%
e
s 00002/00000/00043
d D 4.2 80/12/17 11:46:01 wnj 4 3
c combined 750/780
e
s 00000/00000/00043
d D 4.1 80/11/09 17:00:59 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00042
d D 3.2 80/06/07 02:57:40 bill 2 1
c %H%->%G%
e
s 00043/00000/00000
d D 3.1 80/04/09 16:23:52 bill 1 0
c date and time created 80/04/09 16:23:52 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
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
E 5
E 2

I 4
D 6
#if VAX==780
E 6
I 6
#if VAX780
E 6
E 4
/*
 * Console floppy command/status and sectoring information.
 */
#define	FL_FFC		0x200		/* floppy function complete */
#define	FL_ERR		0x80		/* error bit in floppy status byte */
#define	FL_PERR		0x905		/* floppy protocol error */
#define	FL_DATA		0x100		/* floppy data select code */
#define	FL_RS		0x900		/* floppy read sector command */
#define	FL_WS		0x901		/* floppy write sector command*/
#define	FL_STAT		0x902		/* floppy get status command*/
#define	FL_CANCEL	0x904		/* cancel floppy function */

#define	RXFTRK	77		/* tracks/floppy */
#define	RXSTRK	26		/* sectors/track */
#define	RXBYSEC	128		/* bytes/sector */
#define	MAXSEC (RXFTRK*RXSTRK) 	/* sectors/floppy */

/*
 * In the floppy driver routines, the device active byte is used
 * not as a boolean, but as an indicator of the state we are in.
 * That is, it contains what to do on the next interrupt.
 */

#define	FL_IDLE		0	/* floppy idle */
#define	FL_MAND		1	/* about to send read/write command */
#define	FL_SEC		2	/* about to send sector # to LSI */
#define	FL_TRACK	3	/* about to send track # to LSI */
#define	FL_DAX		4	/* transmitting data */
#define	FL_DAR		5	/* receiving data */
#define	FL_COM		6	/* completing transmission */
#define	FL_CAN		7	/* give cancel order - we had an error,
				   and are to restart */

#define	FLERRS		5	/* number of retries before quitting */

/*
 * The state byte is used to retain exclusivity,
 * and contains the busy flag.
 */
#define	FL_OPEN		1
#define	FL_BUSY		2
I 4
#endif
E 4
E 1
