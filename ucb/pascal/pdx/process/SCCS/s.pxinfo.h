h03952
s 00017/00000/00038
d D 5.2 87/04/07 15:55:09 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00007/00003/00031
d D 5.1 85/06/06 16:18:47 dist 3 2
c Add copyright
e
s 00001/00001/00033
d D 1.2 82/01/18 21:59:31 linton 2 1
c sccsid
e
s 00034/00000/00000
d D 1.1 82/01/18 19:20:47 linton 1 0
c date and time created 82/01/18 19:20:47 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
 * This is the information we get after the initial trap that px does.
 * By passing the "-d" flag, we cause px to call a procedure with the
 * the following information:
 *
 *	address of the display
 *	address of the display pointer
 *	address of the beginning of the object code
 *
 *	the address of a variable containing the address of the first local
 *		variable in the interpreter procedure
 *		(this is used to find the frame where the pc is)
 *	the address of the main interpreter loop
 */

I 4
#ifdef tahoe
E 4
typedef struct {
I 4
	short trp_savemask;
	short trp_removed;
	int trp_oldfp;
	ADDRESS *disp;
	ADDRESS *dp;
	ADDRESS objstart;
	ADDRESS pcaddrp;
	ADDRESS loopaddr;
} TRAPARGS;
#else
typedef struct {
E 4
	int nargs;
	ADDRESS *disp;
	ADDRESS *dp;
	ADDRESS objstart;
	ADDRESS pcaddrp;
	ADDRESS loopaddr;
} TRAPARGS;
I 4
#endif
E 4

ADDRESS *DISPLAY;
ADDRESS *DP;
ADDRESS ENDOFF;
ADDRESS PCADDRP;
ADDRESS LOOPADDR;
ADDRESS *pcframe;
I 4
#ifdef tahoe
ADDRESS RETLOC;
ADDRESS INTFP;
#endif
E 4
E 1
