h09002
s 00009/00018/00021
d D 3.2 88/03/28 12:34:23 bostic 7 6
c add Berkeley specific header
e
s 00000/00000/00039
d D 3.1 87/08/11 10:18:55 minshall 6 5
c New version numbering.
e
s 00025/00000/00014
d D 1.5 87/07/17 10:03:29 minshall 5 4
c Install sccs headers and copyright notices.
e
s 00004/00116/00010
d D 1.4 87/05/24 14:35:21 minshall 4 3
c New OIA.
e
s 00007/00008/00119
d D 1.3 87/05/22 11:55:06 minshall 3 2
c Move OIA into global storage.
e
s 00020/00014/00107
d D 1.2 87/05/12 14:05:08 minshall 2 1
c First more-or-less working version.
e
s 00121/00000/00000
d D 1.1 87/05/11 13:12:01 minshall 1 0
c date and time created 87/05/11 13:12:01 by minshall
e
u
U
t
T
I 1
/*
I 5
D 7
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 7
I 7
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 7
 *
D 7
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
E 7
I 7
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif	/* not lint */
E 7
I 7
#endif /* not lint */
E 7

/*
E 5
 * Routines to maintain the Operator Information Area.
 */

I 4
#include "../general/general.h"

E 4
#include "oia.h"
I 3
#include "../general/globals.h"
E 3

D 3
OIA OperatorInformationArea;

E 3
D 4
static int
    Insert,
    SystemLocked,
    PWait,
    TWait,
    OnlineA,
    Ready3274,
    MyJob;
E 4

D 4
#define	X_AREA_SYSTEM	0xc6, "\xb2\xb8"
#define	X_AREA_CLOCK	0xc6, "\xf2\xf3"
#define	X_AREA_NULL	0xc6, ""

static void
D 2
SetXarea(x, xwhy)
E 2
I 2
OiaXArea(x, xwhy)
E 2
int	x;
char	*xwhy;
E 4
I 4
init_oia()
E 4
{
D 4
    register int i;

    OperatorInformationArea.x = x;
    for (i = 0; i < sizeof OperatorInformationArea.xwhy; i++) {
	if (*xwhy) {
	    OperatorInformationArea.xwhy[i] = *xwhy++;
	} else {
	    OperatorInformationArea.xwhy[i] = 0;
	}
    }
}


D 2
SetInsert(onoff)
E 2
I 2
OiaInsert(onoff)
E 2
int	onoff;
{
    Insert = onoff;

    if (onoff) {
	OperatorInformationArea.insert = OIA_INSERT_ON;
    } else {
	OperatorInformationArea.insert = 0;
    }
I 2
D 3
    ScreenOIA(&OperatorInformationArea);
E 3
I 3
    ScreenOIA();
E 3
E 2
}

D 2
SetSystemLocked(onoff)
E 2
I 2
OiaSystemLocked(onoff)
E 2
int	onoff;
{
    SystemLocked = onoff;

    if ((PWait == 0) && (TWait == 0)) {
D 2
	SetXArea(X_AREA_SYSTEM);
E 2
I 2
	OiaXArea(X_AREA_SYSTEM);
E 2
    }
I 2
D 3
    ScreenOIA(&OperatorInformationArea);
E 3
I 3
    ScreenOIA();
E 3
E 2
}

D 2
SetPWait(onoff)
E 2
I 2
OiaPWait(onoff)
E 2
int	onoff;
{
    PWait = onoff;

    if (onoff) {
D 2
	SetXArea(X_AREA_CLOCK);
E 2
I 2
	OiaXArea(X_AREA_CLOCK);
E 2
    } else {
	if (SystemLocked) {
D 2
	    SetXArea(X_AREA_SYSTEM);
E 2
I 2
	    OiaXArea(X_AREA_SYSTEM);
E 2
	} else {
D 2
	    SetXArea(X_AREA_NULL);
E 2
I 2
	    OiaXArea(X_AREA_NULL);
E 2
	}
    }
I 2
D 3
    ScreenOIA(&OperatorInformationArea);
E 3
I 3
    ScreenOIA();
E 3
E 2
}

D 2
SetTWait(onoff)
E 2
I 2
OiaTWait(onoff)
E 2
int	onoff;
{
    TWait = onoff;

D 2
    SetPWait(onoff);
E 2
I 2
    OiaPWait(onoff);
E 2
}

D 2
SetOnlineA(onoff)
E 2
I 2
OiaOnlineA(onoff)
E 2
int	onoff;
{
    OnlineA = onoff;

    if (onoff) {
D 2
	SetMyJob(1);
E 2
I 2
	OiaMyJob(1);
E 2
	OperatorInformationArea.online = OIA_ONLINE_A;
    } else {
	OperatorInformationArea.online = 0;
    }
I 2
D 3
    ScreenOIA(&OperatorInformationArea);
E 3
I 3
    ScreenOIA();
E 3
E 2
}

D 2
SetReady3274(onoff)
E 2
I 2
OiaReady3274(onoff)
E 2
int	onoff;
{
    Ready3274 = onoff;

    if (onoff) {
	OperatorInformationArea.ready = OIA_READY_3274;
    } else {
	OperatorInformationArea.ready = 0;
    }
I 2
D 3
    ScreenOIA(&OperatorInformationArea);
E 3
I 3
    ScreenOIA();
E 3
E 2
}

D 2
SetMyJob(onoff)
E 2
I 2
OiaMyJob(onoff)
E 2
int	onoff;
{
    MyJob = onoff;

    if (onoff) {
	OperatorInformationArea.ownership = OIA_OWNERSHIP_MYJOB;
    } else {
	OperatorInformationArea.ownership = 0;
    }
I 2
D 3
    ScreenOIA(&OperatorInformationArea);
E 3
I 3
    ScreenOIA();
E 4
I 4
    ClearElement(OperatorInformationArea);
E 4
E 3
E 2
}
E 1
