h48037
s 00000/00000/00082
d D 1.5 04/12/08 07:48:09 msokolov 5 4
x 2
c ioctl debostication
e
s 00000/00000/00082
d D 1.4 88/06/03 17:54:14 marc 4 3
c tahoe release
e
s 00011/00005/00071
d D 1.3 88/05/27 19:54:23 marc 3 2
c add header
e
s 00022/00022/00054
d D 1.2 87/12/22 12:38:45 bostic 2 1
c make ANSI compatible
e
s 00076/00000/00000
d D 1.1 87/12/22 12:37:24 bostic 1 0
c date and time created 87/12/22 12:37:24 by bostic
e
u
U
t
T
I 1
D 3

E 3
/*
I 3
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * 		%W%  Berkeley  %G%
 *
 *	derived from: qdioctl.h	1.1	(ULTRIX)	8/22/85
 */
/*
E 3
 * QDSS IOCTL definitions
D 3
 *	%W% (Berkeley) %G%
E 3
 */

D 3
/* static	char	*sccsid = "@(#)qdioctl.h	1.1	(ULTRIX)	8/22/85"; */
E 3

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
 *   This software is  derived  from  software  received  from  the	*
 *   University    of   California,   Berkeley,   and   from   Bell	*
 *   Laboratories.  Use, duplication, or disclosure is  subject  to	*
 *   restrictions  under  license  agreements  with  University  of	*
 *   California and with AT&T.						*
 *									*
 *   The information in this software is subject to change  without	*
 *   notice  and should not be construed as a commitment by Digital	*
 *   Equipment Corporation.						*
 *									*
 *   Digital assumes no responsibility for the use  or  reliability	*
 *   of its software on equipment which is not supplied by Digital.	*
 *									*
 ************************************************************************/
/***************************************************************************
D 3
*	revision history:
E 3
I 3
*	revision history: (belongs in sccs)
E 3
****************************************************************************
*
* 22 oct 85  longo  fixed QD_PRGTABRES cmd number to be 22 instead of 12
* 14 oct 85  longo  added QD_KERN_LOOP and QD_KERN_UNLOOP
* 02 oct 85  longo  added QD_MAPCOLOR and QD_UNMAPCOLOR
* 17 sep 85  longo  made QD_MAPIOBUF a read/write command type
*
***************************************************************************/


#ifdef KERNEL
D 3
#include "../h/ioctl.h"
E 3
I 3
#include "ioctl.h"
E 3
#else
#include <sys/ioctl.h>
#endif


D 2
#define QD_GETEVENT	_IOR(g, 1, struct _vs_event) /* get oldest event */
#define QD_WTCURSOR	_IOW(g, 2, short[32])       /* write cursor bitmap */
#define QD_RDCURSOR	_IOR(g, 3, 64)           /* read cursor bitmap */
#define QD_CLRSCRN	_IO(g, 4) 		/* clear the screen */
#define QD_RDCONFIG	_IOR(g, 5, short)        /* read QDSS configuration */
#define QD_PRGMOUSE	_IOW(g, 6, char)	/* program mouse */
#define QD_PRGTABLET	_IOW(g, 7, char) 	/* program tablet */
#define QD_PRGKBD	_IOW(g, 8, struct prgkbd) /* program LK201 kbd */
#define QD_MAPDEVICE	_IOR(g, 9, struct qdmap) /* map device to user */
#define QD_MAPIOBUF 	_IOWR(g, 10, caddr_t)     /* map DMA iobuf to user */
#define QD_MAPEVENT	_IOR(g, 11, caddr_t)     /* map event queue to user */
#define QD_PRGCURSOR	_IOW(g, 12, struct prg_cursor) /* program cursor */
#define QD_RESET	_IO(g, 13)  	    /* set device & driver defaults */
#define QD_POSCURSOR	_IOW(g, 14, struct _vs_cursor) /* position cursor */
#define QD_SET		_IO(g, 15)  	    /* set DUART & driver defaults */
#define QD_MAPSCROLL    _IOR(g, 16, caddr_t)  /* map scroll param area */
#define QD_UNMAPSCROLL  _IO(g, 17)            /* unmap scroll param area */
#define QD_MAPCOLOR     _IOR(g, 18, caddr_t)  /* map color map write buf */
#define QD_UNMAPCOLOR   _IO(g, 19)            /* unmap color map write buf */
#define QD_KERN_LOOP    _IO(g, 20)       /* detour kernel console output */
#define QD_KERN_UNLOOP  _IO(g, 21)       /* un-detour kernel console output */
#define QD_PRGTABRES	_IOW(g, 22, short) /* program tablet resolution */
E 2
I 2
#define QD_GETEVENT	_IOR('g', 1, struct _vs_event) /* get oldest event */
#define QD_WTCURSOR	_IOW('g', 2, short[32])       /* write cursor bitmap */
#define QD_RDCURSOR	_IOR('g', 3, 64)           /* read cursor bitmap */
#define QD_CLRSCRN	_IO('g', 4) 		/* clear the screen */
#define QD_RDCONFIG	_IOR('g', 5, short)        /* read QDSS configuration */
#define QD_PRGMOUSE	_IOW('g', 6, char)	/* program mouse */
#define QD_PRGTABLET	_IOW('g', 7, char) 	/* program tablet */
#define QD_PRGKBD	_IOW('g', 8, struct prgkbd) /* program LK201 kbd */
#define QD_MAPDEVICE	_IOR('g', 9, struct qdmap) /* map device to user */
#define QD_MAPIOBUF 	_IOWR('g', 10, caddr_t)     /* map DMA iobuf to user */
#define QD_MAPEVENT	_IOR('g', 11, caddr_t)     /* map event queue to user */
#define QD_PRGCURSOR	_IOW('g', 12, struct prg_cursor) /* program cursor */
#define QD_RESET	_IO('g', 13)  	    /* set device & driver defaults */
#define QD_POSCURSOR	_IOW('g', 14, struct _vs_cursor) /* position cursor */
#define QD_SET		_IO('g', 15)  	    /* set DUART & driver defaults */
#define QD_MAPSCROLL    _IOR('g', 16, caddr_t)  /* map scroll param area */
#define QD_UNMAPSCROLL  _IO('g', 17)            /* unmap scroll param area */
#define QD_MAPCOLOR     _IOR('g', 18, caddr_t)  /* map color map write buf */
#define QD_UNMAPCOLOR   _IO('g', 19)            /* unmap color map write buf */
#define QD_KERN_LOOP    _IO('g', 20)       /* detour kernel console output */
#define QD_KERN_UNLOOP  _IO('g', 21)       /* un-detour kernel console output */
#define QD_PRGTABRES	_IOW('g', 22, short) /* program tablet resolution */
E 2
E 1
