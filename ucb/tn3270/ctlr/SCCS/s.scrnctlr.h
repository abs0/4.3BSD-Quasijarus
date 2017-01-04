h35167
s 00014/00002/00013
d D 3.2 88/03/28 12:34:34 bostic 4 3
c add Berkeley specific header
e
s 00000/00000/00015
d D 3.1 87/08/11 10:18:53 minshall 3 2
c New version numbering.
e
s 00002/00000/00013
d D 1.2 87/07/17 10:03:26 minshall 2 1
c Install sccs headers and copyright notices.
e
s 00013/00000/00000
d D 1.1 86/11/11 22:54:18 minshall 1 0
c date and time created 86/11/11 22:54:18 by minshall
e
u
U
t
T
I 1
/*
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

/*
E 4
 * definitions that have to do with the interface between the
 * controller and the screen.
I 2
D 4
 *
 * %W% (Berkeley) %G%
E 4
E 2
 */

#define	DISP_AMPERSAND		0x30
#define	DISP_BLANK		0x10
#define	DISP_CENTSIGN		0x1b
#define	DISP_DUP		0x9f
#define	DISP_FM			0x9e
#define	DISP_GREATER_THAN	0x08
#define	DISP_NULL		0x00
#define	DISP_QUESTION		0x18
E 1
