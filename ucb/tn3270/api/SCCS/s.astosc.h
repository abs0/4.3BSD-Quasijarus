h09612
s 00014/00002/00023
d D 3.2 88/03/28 13:46:48 bostic 6 5
c add Berkeley specific header
e
s 00000/00000/00025
d D 3.1 87/08/11 10:17:39 minshall 5 4
c New version numbering.
e
s 00002/00000/00023
d D 1.4 87/07/17 10:01:31 minshall 4 3
c Install sccs headers and copyright notices.
e
s 00002/00000/00021
d D 1.3 87/06/19 12:37:39 minshall 3 2
c Add declaration of astosc[].
e
s 00001/00000/00020
d D 1.2 87/05/31 17:09:57 minshall 2 1
c Version without termcodes.m4.
e
s 00020/00000/00000
d D 1.1 87/05/31 14:34:19 minshall 1 0
c date and time created 87/05/31 14:34:19 by minshall
e
u
U
t
T
I 1
/*
I 6
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
E 6
 * This defines the structure used to translate:
 *
 *	ascii name ==> (scancode, shiftstate)
 *
 * (Actually, map3270 does "ascii name ==> index", and
 * termin does "index ==> (scancode, shiftstate)".  Both
 * mappings use this structure.)
I 4
D 6
 *
 * %W% (Berkeley) %G%
E 6
E 4
 */

#define	INCLUDED_ASTOSC

struct astosc {
    unsigned char
	scancode,		/* Scan code for this function */
	shiftstate;		/* Shift state for this function */
I 2
    enum ctlrfcn function;	/* Internal function identifier */
E 2
    char *name;			/* Name of this function */
};

int ascii_to_index();		/* Function to feed InitControl() */
I 3

extern struct astosc astosc[256];
E 3
E 1
