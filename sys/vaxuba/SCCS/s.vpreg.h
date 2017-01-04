h15111
s 00001/00001/00031
d D 7.1 86/06/05 01:24:18 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00025
d D 6.2 85/06/08 14:31:22 mckusick 3 2
c Add copyright
e
s 00000/00000/00026
d D 6.1 83/07/29 07:31:12 sam 2 1
c 4.2 distribution
e
s 00026/00000/00000
d D 4.1 83/06/22 10:50:20 sam 1 0
c date and time created 83/06/22 10:50:20 by sam
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

#define	VPPRI	(PZERO-1)

struct	vpdevice {
	short	plbcr;
	short	pbxaddr;
	short	prbcr;
	u_short pbaddr;
	short	plcsr;
	short	plbuf;
	short	prcsr;
	u_short prbuf;
};

#define	VP_ERROR	0100000
#define	VP_DTCINTR	0040000
#define	VP_DMAACT	0020000
#define	VP_READY	0000200
#define	VP_IENABLE	0000100
#define	VP_TERMCOM	0000040
#define	VP_FFCOM	0000020
#define	VP_EOTCOM	0000010
#define	VP_CLRCOM	0000004
#define	VP_RESET	0000002
#define	VP_SPP		0000001
E 1
