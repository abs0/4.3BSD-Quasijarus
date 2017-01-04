h47051
s 00000/00000/00090
d D 1.3 88/06/03 17:54:20 marc 3 2
c tahoe release
e
s 00010/00004/00080
d D 1.2 88/05/27 20:06:09 marc 2 1
c add header
e
s 00084/00000/00000
d D 1.1 88/05/27 19:50:01 marc 1 0
c date and time created 88/05/27 19:50:01 by marc
e
u
U
t
T
I 1
D 2

E 2
I 2
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * 		%W%  Berkeley  %G%
 */
E 2
/************************************************************************
*									*
*			Copyright (c) 1985 by				*
*		Digital Equipment Corporation, Maynard, MA		*
*			All rights reserved.				*
*									*
*   This software is furnished under a license and may be used and	*
*   copied  only  in accordance with the terms of such license and	*
*   with the  inclusion  of  the  above  copyright  notice.   This	*
*   software  or  any  other copies thereof may not be provided or	*
*   otherwise made available to any other person.  No title to and	*
*   ownership of the software is hereby transferred.			*
*									*
*   The information in this software is subject to change  without	*
*   notice  and should not be construed as a commitment by Digital	*
*   Equipment Corporation.						*
*									*
*   Digital assumes no responsibility for the use  or  reliability	*
*   of its software on equipment which is not supplied by Digital.	*
*									*
************************************************************************/

/*
 * Event queue entries
 */

D 2
# ifndef _QEVENT_
# define _QEVENT_
E 2
I 2
#ifndef _QEVENT_
#define _QEVENT_
E 2

typedef struct  _vs_event {
        unsigned short vse_x;	/* x position */
        unsigned short vse_y;	/* y position */
        unsigned short vse_time;/* 10 millisecond units (button only) */
        char    vse_type;       /* button or motion? */
        unsigned char  vse_key;	/* the key (button only) */
        char    vse_direction;	/* which direction (button only) */
        char    vse_device;	/* which device (button only) */
} vsEvent;

/* vse_type field */
#define VSE_BUTTON      0               /* button moved */
#define VSE_MMOTION     1               /* mouse moved */
#define VSE_TMOTION     2               /* tablet moved */

/* vse_direction field */
#define VSE_KBTUP       0               /* up */
#define VSE_KBTDOWN     1               /* down */
#define VSE_KBTRAW	2		/* undetermined */

/* vse_device field */
#define VSE_NULL	0		/* NULL event (for QD_GETEVENT ret) */
#define VSE_MOUSE       1               /* mouse */
#define VSE_DKB         2               /* main keyboard */
#define VSE_TABLET      3               /* graphics tablet */
#define VSE_AUX         4               /* auxiliary */
#define VSE_CONSOLE     5               /* console */

/* The event queue */

typedef struct _vs_eventqueue {
	vsEvent *events;	/* input event buffer */
	int size;		/* size of event buffer */
	int head;		/* index into events */
	int tail;		/* index into events */
} vsEventQueue;

/* mouse cursor position */

typedef struct _vs_cursor {
        short x;
        short y;
} vsCursor;

/* mouse motion rectangle */

typedef struct _vs_box {
        short bottom;
        short right;
        short left;
        short top;
} vsBox;

D 2
# endif _QEVENT_
E 2
I 2
#endif /*_QEVENT_*/
E 2
E 1
