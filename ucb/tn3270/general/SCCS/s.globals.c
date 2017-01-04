h62668
s 00010/00019/00043
d D 3.2 88/03/28 12:28:45 bostic 11 10
c add Berkeley specific headers
e
s 00000/00000/00062
d D 3.1 87/08/11 10:19:12 minshall 10 9
c New version numbering.
e
s 00002/00002/00060
d D 1.9 87/07/17 10:04:13 minshall 9 8
c Install sccs headers and copyright notices.
e
s 00000/00003/00062
d D 1.8 87/06/19 12:51:46 minshall 8 7
c Directory changes, plus move some globals out of here.
e
s 00000/00006/00065
d D 1.7 87/06/18 16:01:47 minshall 7 6
c Remove Terminal definition (is, and should be, in
c ../sys_curses/termout.c.
e
s 00001/00000/00070
d D 1.6 87/05/24 14:33:59 minshall 6 5
c Include oia.h
e
s 00002/00002/00068
d D 1.5 87/05/22 11:18:45 minshall 5 4
c New directory structure
e
s 00006/00005/00064
d D 1.4 87/05/10 14:48:45 minshall 4 3
c Get rid of FieldForward, FieldReverse, and Terminal (Terminal 
c from here at least).
e
s 00001/00001/00068
d D 1.3 87/05/10 11:15:34 minshall 3 2
c 
e
s 00029/00000/00040
d D 1.2 87/04/01 16:10:08 minshall 2 1
c Make close/open sequences work in a more rational manner.
e
s 00040/00000/00000
d D 1.1 87/03/26 14:52:42 minshall 1 0
c date and time created 87/03/26 14:52:42 by minshall
e
u
U
t
T
I 1
/*
D 9
 *	Copyright (c) 1984, 1985, 1986 by the Regents of the
E 9
I 9
D 11
 *	Copyright (c) 1984-1987 by the Regents of the
E 9
 *	University of California and by Gregory Glenn Minshall.
E 11
I 11
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 11
 *
D 11
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 11
I 11
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
 */

D 11
#ifndef	lint
E 11
I 11
#ifndef lint
E 11
D 9
static	char	sccsid[] = "@(#)globals.c	3.1  10/29/86";
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
E 9
D 11
#endif	/* ndef lint */
E 11
I 11
#endif /* not lint */
E 11

/*
 *	Do the defining instances for the globals of tn3270.
 */

#include	"../ctlr/hostctlr.h"
D 8
#include	"../ascii/ascebc.h"
#include	"../ctlr/dctype.h"
E 8
I 6
#include	"../ctlr/oia.h"
E 6
#include	"../ctlr/options.h"
#include	"../ctlr/screen.h"
D 5
#include	"../keyboard/state.h"
E 5
I 5
D 8
#include	"../ascii/state.h"
E 8
E 5


#define DEFINING_INSTANCES

#include	"globals.h"
I 2

D 3
#include	"general.h"
E 3
I 3
D 5
#include	"../general.h"
E 5
I 5
#include	"../general/general.h"
E 5
E 3

I 4
D 7
#if	defined(SLOWSCREEN)

ScreenImage Terminal[MAXSCREENSIZE];

#endif	/* defined(SLOWSCREEN) */

E 7
E 4
/*
 * init_system()
 *
 * Initialize the global values in case of a restart.
 */

void
init_system()
{
    OptHome = OptLeftMargin = OptAPLmode = OptNullProcessing = 0;
    OptZonesMode = OptEnterNL = OptColFieldTab = OptPacing = 0;
    OptAlphaInNumeric = OptHome = OptLeftMargin = OptWordWrap = 0;

    ClearArray(Host);
D 4
#if	defined(SLOWSCREEN)
    ClearArray(Terminal);
#endif	/* defined(SLOWSCREEN) */
    ClearArray(FieldForward);
    ClearArray(FieldReverse);
E 4
    CursorAddress = BufferAddress = 0;

    Lowest = Highest = 0;

    UnLocked = AidByte = 0;

}
E 2
E 1
