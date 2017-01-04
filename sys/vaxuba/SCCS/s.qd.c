h64558
s 00004/00004/03575
d D 1.13 04/12/08 07:47:33 msokolov 15 14
c CTRL macro debostication
e
s 00003/00003/03576
d D 1.12 04/02/05 00:38:34 msokolov 14 13
c q_key and q_shift_key tables back to char, since we don't implement compose
c we have no 8-bit keyboard input
e
s 00002/00000/03577
d D 1.11 89/02/07 20:06:30 tef 13 12
c try to replace standard console on qbus machines only
e
s 00027/00017/03550
d D 1.10 88/08/09 20:34:44 bostic 12 11
c add correct Berkeley copyright
e
s 00725/01072/02842
d D 1.9 88/06/14 14:06:13 marc 11 10
c lint, code cleanup, make less yucky
e
s 02233/02880/01681
d D 1.8 88/06/05 02:05:18 marc 10 7
c tahoe release - much reformating - put cursor motion back in
e
s 02235/02880/01681
d R 1.8 88/06/03 21:28:23 marc 9 7
c tahoe release - much reformatting - add cursor motion back in
e
s 02175/02865/01696
d R 1.8 88/06/03 17:53:42 marc 8 7
c tahoe release
e
s 00000/00000/04561
d D 1.7 88/06/01 20:38:27 marc 7 6
c damned sccs!!!  i was going to say, before i was so rudely
c interrupted, that this version also contains the change log which is
c present in the ultrix header, but really belongs in sccs.
e
s 01558/01040/03003
d D 1.6 88/06/01 20:33:34 marc 6 5
c This is the first X11R2 working version.  It has minimal
c changes from the ultrix X11 source, and is included so as to be
c diff'able with the ultrix versions - because i intend to reformat
c all the code and comments immediatly.  Also, this is the version
e
s 00016/00012/04027
d D 1.5 88/05/27 19:47:39 marc 5 4
c put back KERN_LOOP and UNLOOP as no-ops to keep the X11R2 qdss 
c server happy.
e
s 00001/00001/04038
d D 1.4 88/05/27 16:21:06 marc 4 3
c change DMA_BUFSIZ from 3 to 10 (*1024) for X11R2
e
s 00401/00576/03638
d D 1.3 88/05/26 16:50:48 marc 3 2
c reformat comments, fix header references, generally get disgusted
e
s 00837/00555/03377
d D 1.2 87/08/07 15:54:17 marc 2 1
c first 4.3 version
e
s 03932/00000/00000
d D 1.1 87/01/14 08:56:35 karels 1 0
c from DEC
e
u
U
t
T
I 1
D 2

E 2
D 3
#ifndef lint
D 2
static char *sccsid = "@(#)qd.c	1.40	ULTRIX	10/2/86";
E 2
I 2
static char *sccsid = "%W%  Berkeley  %G%";
static char *osccsid = "@(#)qd.c	1.40	ULTRIX	10/2/86";
E 2
#endif lint
E 3
I 3
/*
D 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * 	%W%  Berkeley  %G%
 *
D 6
 * derived from: "@(#)qd.c	1.40	ULTRIX	10/2/86";
E 6
I 6
 * derived from: "@(#)qd.c	ULTRIX";
E 6
 */
E 10
I 10
D 12
* Copyright (c) 1982, 1986 Regents of the University of California.
* All rights reserved.  The Berkeley software License Agreement
* specifies the terms and conditions for redistribution.
*
* 		%W%  Berkeley  %G%
*
*/
E 12
I 12
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	%W% (Berkeley) %G%
 */
E 12

E 10
E 3
D 6

E 6
/************************************************************************
D 3
 *									*
 *			Copyright (c) 1985, 1986 by			*
E 3
I 3
*									*
D 6
*			Copyright (c) 1985, 1986 by			*
E 6
I 6
*			Copyright (c) 1985-1988 by			*
E 6
E 3
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
*************************************************************************/
I 6

E 6
D 3

I 2

E 3
E 2
/*
D 3
 * qd.c
 *
 * Modification history
 *
 * QDSS workstation driver
 *
I 2
 *  Aug 1987 - marc@ucbvax.berkeley.edu
 *
 *	Modify for 4.3bsd with Mikes help.  Add cursor motion support 
 *	in glass tty.  Work around glass tty output bug (which causes 
 *	screen to freeze).  Reformat as many comments as patience would
 *	allow. Use 4.3 console redirect (TIOCCONS) instead of smashing
 *	cdevsw.  Supporting changes are in locore.s (for map),
 *	machdep.c, and conf.c. Note that the major number for qd
 *	is different from ultrix: on 4.3bsd its 41, and on
 *	ultrix its 42.
 *
E 2
 * 26-Aug-86 - rsp (Ricky Palmer)
 *
 *	Cleaned up devioctl code to (1) zero out devget structure
 *	upon entry and (2) use strlen instead of fixed storage
 *	for bcopy's.
 *
 * 21-Jul-86 - Ram Rao
 *	allowed cursor rectangle to hang (partially) off the
 *	top and left of screen
 *
 * 11-Jul-86 - ricky palmer
 *
 *	Added adpt and nexus fields to DEVIOCGET code.
 *
 * 02-July-86 - Brian Stevens
 *
 *	added support for console writing to second QDSS display
 *
 * 20-May-86 - ricky palmer
 *
 *	Added new DEVIOCGET ioctl request code. V2.0
 *
 * 16-Apr-86 -- darrell
 *	 badaddr is now called via the macro BADADDR
 *
 * 14-Apr-86 -- afd
 *	 Changed UMEMmap to QMEMmap and umem to qmem.
 *
 *	 v_console() is now refered to as v_consputc, and there is a
 *	 corresponding v_consgetc() (defined in /sys/vax/conf.c).
 *
 *	 Added "qdgetc()" routine for console read.  Needed to read
 *	 user's answer to the "root device?" prompt with a generic kernel.
 *
 * 19-Mar-86 -- pmk
 *	 Change DELAY to 20000, because microdelay now in real microsec.
 *
 * 18-mar-86  -- jaw	 br/cvec changed to NOT use registers.
 *
 * 11 mar 86  darrell	replaced percpu with cpusw, and removed all but
 *			 one global reference
 * 19 feb 86  bstevens	no report of motion event on puck/stylus button action
 * 18 feb 86  bstevens	put in cursor box support for tablets
 * 18-Mar-86 -- jaw  add routines to cpu switch for nexus/unibus addreses
 *		      also got rid of some globals like nexnum.
 *		      ka8800 cleanup.
 * 06 dec 85  longo  added LK-201 error reporting for graphics device ops
 * 03 dec 85  longo  made qddint() clear active bit on error
 * 02 dec 85  longo  fixed up some crocks in the error messages
 * 25 nov 85  longo  added error handling to DMA ISR and single user locking
 * 19 nov 85  longo  eliminated "set_defaults()" by breaking out sub-calls.
 *		     Changed init_shared to do real init of scroll struct
 * 12 nov 85  longo  fixed bug in open that broke alternate console re-direct
 * 11 nov 85  longo  changed "_vs_eventqueue" references to "qdinput"
 * 08 nov 85  longo  improved select service for read/write select wakeup.
 *		     Also set ISR's to ipl4 to allow the interval timer in.
 * 04 nov 85  longo  fixed bugs in mouse button reporting and dma request stuff
 * 30 oct 85  longo  DMA to/from user space is in place
 * 14 oct 85  longo  added kernel msg redirect and QD_RDCURSOR ioctl
 * 03 oct 85  longo  added support for multiple QDSS's
 * 02 oct 85  longo  added color map loading services in qdioctl() & qdaint()
 * 30 sep 85  longo  added DMA interrupt services
 * 18 sep 85  longo  added scroll services to "qdaint()" adder intrpt service
 *		     and put in supporting ioctl's
 * 04 sep 85  longo  initial implementation of DMA is working
 * 17 aug 85  longo  added support for the QDSS to be system console
 * 05 aug 85  longo  now using qfont (QVSS & QDSS) as linked object
 * 12 jun 85  longo  added mouse event loading to "qdiint()"
 * 31 may 85  longo  put live interrupts into the probe() routine
 * 30 may 85  longo  event queue shared memory implementation is now alive
 * 29 may 85  longo  LK-201 input is now interrupt driven
 * 25 apr 85  longo  MAPDEVICE works
 * 14 mar 85  longo  created
 *
 *	 todo:	 fix rlogin bug in console stuff
D 2
 *		 cat -u console redirection
E 2
 *		 check error return from strategy routine
 *		 verify TOY time stuff (what format?)
 *		 look at system based macro implementation of VTOP
 *
E 3
I 3
D 6
 * qd.c - QDSS display driver
E 6
I 6
D 10
 * qd.c
 *
 * Modification history
 *
 * QDSS workstation driver
 *
 *
 *  1-Dec-87 - Tim Burke
 *
 *	Added support for both System V termio(7) and POSIX termios(7).  These
 *	changes also include support for 8-bit canonical processing.  Changes
 *	involve:
 *
 *	- Default settings on first open depend on mode of open.  For termio
 *	  opens the defaults are "RAW" style, while non-termio opens default
 *	  to the traditional "cooked" style.
 *	- The driver now represents its terminal attributes and special 
 *	  characters in the POSIX termios data structure.  This contrasts the
 *	  original approach of storing attributes and special chars in the
 *	  t_flags, ltchars and tchars.
 *	- Addition of LPASS8 to local mode word for 8-bit canonical support.
 *
 * 28-Sep-87 - Ali Rafieymehr
 *    Fixed a bug in qddint() routine. The bug was discovered on CVAX.
 *    Incorrect logic was used when taking an entry from the request queue.
 *
 * 12-Oct-87 - Tim Burke
 *	Modified driver to provide 8-bit support to the console port.  To do 
 *	this characters are defined in the remainder of the first 15 rows of
 *	off screen memory as well as in next 15 rows.
 *
 *  2-Aug-87 - Fred Canter
 *    Use TANDEM mode on qconsole for flow control of writes to
 *    /dev/console.
 *
 * 12-Jun-87 - Tim Burke
 *
 *	Added full TERMIO functionality to terminal subsystem.
 *	Changed open routine to setup propper default settings if the line
 *	is not being used as a graphics device.  Added defines of defaults.
 *
 *
 * 14-May-87 - Fred Canter
 *	Changed default state of kernel_loop to on.
 *
 * 21-Apr-87 - Brian Stevens
 *	Xos support
 *
 * 16-Apr-87 - Fred Canter (for Brian Stevens)
 *	Multi-head GPX changes.
 *
 * 19-Mar-87 - Fred Canter (for Brian Stevens)
 *	Added X in the kernel support.
 *
 * 16-Dec-86 - Brian Stevens
 *
 *	added support so "select" could be called on tty type device
 *      fixed rlogin bug
 *
 * 30-Oct-86 - Brian Stevens
 *
 *	Removed the mprintf for "unexpected interrupts"
 *
 * 26-Aug-86 - rsp (Ricky Palmer)
 *
 *	Cleaned up devioctl code to (1) zero out devget structure
 *	upon entry and (2) use strlen instead of fixed storage
 *	for bcopy's.
 *
 * 21-Jul-86 - Ram Rao
 *	allowed cursor rectangle to hang (partially) off the
 *	top and left of screen
 *
 * 11-Jul-86 - ricky palmer
 *
 *	Added adpt and nexus fields to DEVIOCGET code.
 *
 * 02-July-86 - Brian Stevens
 *
 *	added support for console writing to second QDSS display
 *
 * 20-May-86 - ricky palmer
 *
 *	Added new DEVIOCGET ioctl request code. V2.0
 *
 * 16-Apr-86 -- darrell
 *	 badaddr is now called via the macro BADADDR
 *
 * 14-Apr-86 -- afd
 *	 Changed UMEMmap to QVmap and umem to qvmem.
 *
 *	 v_console() is now refered to as v_consputc, and there is a
 *	 corresponding v_consgetc() (defined in /sys/vax/conf.c).
 *
 *	 Added "qdgetc()" routine for console read.  Needed to read
 *	 user's answer to the "root device?" prompt with a generic kernel.
 *
 * 19-Mar-86 -- pmk
 *	 Change DELAY to 20000, because microdelay now in real microsec.
 *
 * 18-mar-86  -- jaw	 br/cvec changed to NOT use registers.
 *
 * 11 mar 86  darrell	replaced percpu with cpusw, and removed all but
 *			 one global reference
 * 19 feb 86  bstevens	no report of motion event on puck/stylus button action
 * 18 feb 86  bstevens	put in cursor box support for tablets
 * 18-Mar-86 -- jaw  add routines to cpu switch for nexus/unibus addreses
 *		      also got rid of some globals like nexnum.
 *		      ka8800 cleanup.
 * 06 dec 85  longo  added LK-201 error reporting for graphics device ops
 * 03 dec 85  longo  made qddint() clear active bit on error
 * 02 dec 85  longo  fixed up some crocks in the error messages
 * 25 nov 85  longo  added error handling to DMA ISR and single user locking
 * 19 nov 85  longo  eliminated "set_defaults()" by breaking out sub-calls.
 *		     Changed init_shared to do real init of scroll struct
 * 12 nov 85  longo  fixed bug in open that broke alternate console re-direct
 * 11 nov 85  longo  changed "_vs_eventqueue" references to "qdinput"
 * 08 nov 85  longo  improved select service for read/write select wakeup.
 *		     Also set ISR's to ipl4 to allow the interval timer in.
 * 04 nov 85  longo  fixed bugs in mouse button reporting and dma request stuff
 * 30 oct 85  longo  DMA to/from user space is in place
 * 14 oct 85  longo  added kernel msg redirect and QD_RDCURSOR ioctl
 * 03 oct 85  longo  added support for multiple QDSS's
 * 02 oct 85  longo  added color map loading services in qdioctl() & qdaint()
 * 30 sep 85  longo  added DMA interrupt services
 * 18 sep 85  longo  added scroll services to "qdaint()" adder intrpt service
 *		     and put in supporting ioctl's
 * 04 sep 85  longo  initial implementation of DMA is working
 * 17 aug 85  longo  added support for the QDSS to be system console
 * 05 aug 85  longo  now using qfont (QVSS & QDSS) as linked object
 * 12 jun 85  longo  added mouse event loading to "qdiint()"
 * 31 may 85  longo  put live interrupts into the probe() routine
 * 30 may 85  longo  event queue shared memory implementation is now alive
 * 29 may 85  longo  LK-201 input is now interrupt driven
 * 25 apr 85  longo  MAPDEVICE works
 * 14 mar 85  longo  created
 *
 *	 todo:	 fix rlogin bug in console stuff
 *		 cat -u console redirection
 *		 check error return from strategy routine
 *		 verify TOY time stuff (what format?)
 *		 look at system based macro implementation of VTOP
 *
E 10
I 10
 * qd.c - QDSS display driver for VAXSTATION-II GPX workstation
E 10
E 6
E 3
 */

D 2
#include "../data/qd_data.c"	/* include external references to data file */
E 2
I 2
D 3
#define mprintf printf
#include "qd.h" 	/* # of QDSS's the system is configured for */
E 3
I 3
D 6
#include "qd.h"
#if NQD > 0
E 6
I 6
D 10
#include "qd.h" 	/* # of QDSS's the system is configured for */
E 10
I 10
#include "qd.h"
E 10
E 6
E 3
E 2

D 2
/*---------------------------------------------------------------------
* macro to get system time.  Used to time stamp event queue entries */
E 2
I 2
D 3
#include "../vax/pte.h"	/* page table values */
#include "../vax/mtpr.h"	/* VAX register access stuff */
E 3
I 3
D 6
#include "../machine/pte.h"
#include "../machine/mtpr.h"
E 6
I 6
#if NQD > 0
#include "types.h"
D 10
#include "../machine/pte.h"	/* page table values */
#include "../machine/mtpr.h"	/* VAX register access stuff */
E 10
I 10
#include "../machine/pte.h"
#include "../machine/mtpr.h"
E 10
E 6
#include "../machine/cpu.h"
D 6
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "qdioctl.h"
E 6
I 6
D 10
#include "param.h" 	/* general system params & macros */
#include "conf.h"		/* "linesw" tty driver dispatch */
#include "dir.h"		/* for directory handling */
#include "user.h"		/* user structure (what else?) */
#include "qdioctl.h"	/* ioctl call values */
E 10
I 10
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "qdioctl.h"
E 10
E 6
#include "tty.h"
D 6
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "clist.h"
#include "file.h"
#include "uio.h"
#include "kernel.h"
#include "ubareg.h"
#include "ubavar.h"
E 6
I 6
D 10
#include "map.h"		/* resource allocation map struct */
#include "buf.h"		/* buf structs */
#include "vm.h"		/* includes 'vm' header files */
#include "bk.h"		/* BKINPUT macro for line stuff */
#include "clist.h" 	/* char list handling structs */
#include "file.h"		/* file I/O definitions */
#include "uio.h"		/* write/read call structs */
#include "kernel.h"	/* clock handling structs */
#ifdef notdef	/* notneeded */
#include "cpuconf.h"
#include "devio.h"
#endif
E 10
I 10
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "bk.h"
#include "clist.h"
#include "file.h"
#include "uio.h"
#include "kernel.h"
E 10
#include "exec.h"
#include "proc.h"
D 10

#include "ubareg.h"	/* uba & 'qba' register structs */
#include "ubavar.h"	/* uba structs & uba map externs */
E 10
I 10
#include "ubareg.h"
#include "ubavar.h"
E 10
E 6
#include "syslog.h"
D 6
#include "qduser.h"	/* definitions shared with client */
#include "qdreg.h"
E 6
E 3
E 2
D 10

I 2
D 3
#include "../h/param.h" 	/* general system params & macros */
#include "../h/conf.h"		/* "linesw" tty driver dispatch */
#include "../h/dir.h"		/* for directory handling */
#include "../h/user.h"		/* user structure (what else?) */
#include "../ultrix/qdioctl.h" 		/* ioctl call values */
#include "../h/tty.h"
#include "../h/map.h"		/* resource allocation map struct */
#include "../h/buf.h"		/* buf structs */
#include "../h/vm.h"		/* includes 'vm' header files */
#include "../h/clist.h" 	/* char list handling structs */
#include "../h/file.h"		/* file I/O definitions */
#include "../h/uio.h"		/* write/read call structs */
#include "../h/kernel.h"	/* clock handling structs */
#include "../vax/cpu.h" 	/* per cpu (pcpu) struct */

#include "../vaxuba/ubareg.h"	/* uba & 'qba' register structs */
#include "../vaxuba/ubavar.h"	/* uba structs & uba map externs */
#include "../h/syslog.h"

#include "../ultrix/qduser.h"	/* definitions shared with my client */
#include "../ultrix/qdreg.h"	/* QDSS device register structures */

E 3
D 6
/*
* QDSS driver status flags for tracking operational state 
*/
E 6
I 6
#include "qduser.h"	/* definitions shared with my client */
E 10
I 10
#include "qduser.h"	/* definitions shared with user level client */
E 10
#include "qdreg.h"	/* QDSS device register structures */
D 10
/*-----------------------------------------------------------
* QDSS driver status flags for tracking operational state */
E 10
E 6

D 6
struct qdflags {
E 6
I 6
D 10
	struct qdflags {
E 10
I 10
/*
 * QDSS driver status flags for tracking operational state 
 */
struct qdflags {
	u_int inuse;		/* which minor dev's are in use now */
	u_int config;		/* I/O page register content */
	u_int mapped;		/* user mapping status word */
	u_int kernel_loop;	/* if kernel console is redirected */
	u_int user_dma;		/* DMA from user space in progress */
	u_short pntr_id;	/* type code of pointing device */
	u_short duart_imask;	/* shadowing for duart intrpt mask reg */
	u_short adder_ie;	/* shadowing for adder intrpt enbl reg */
	u_short curs_acc;	/* cursor acceleration factor */
	u_short curs_thr;	/* cursor acceleration threshold level */
	u_short tab_res;	/* tablet resolution factor */
	u_short selmask;	/* mask for active qd select entries */
};
E 10
E 6

D 6
    u_int inuse;	    /* which minor dev's are in use now */
    u_int config;	    /* I/O page register content */
    u_int mapped;	    /* user mapping status word */
D 5
    u_int kernel_loop;	    /* if kernel console is redirected */
E 5
I 5
    u_int kernel_loop;	    /* if kernel console is redirected (DEFUNCT) */
E 5
    u_int user_dma;	    /* DMA from user space in progress */
    u_short pntr_id;	    /* type code of pointing device */
    u_short duart_imask;    /* shadowing for duart intrpt mask reg */
    u_short adder_ie;	    /* shadowing for adder intrpt enbl reg */
    u_short curs_acc;	    /* cursor acceleration factor */
    u_short curs_thr;	    /* cursor acceleration threshold level */
    u_short tab_res;	    /* tablet resolution factor */
    u_short selmask;	    /* mask for active qd select entries */
};
E 6
I 6
D 10
	    u_int inuse;	    /* which minor dev's are in use now */
	    u_int config;	    /* I/O page register content */
	    u_int mapped;	    /* user mapping status word */
	    u_int kernel_loop;	    /* if kernel console is redirected */
	    u_int user_dma;	    /* DMA from user space in progress */
	    u_short pntr_id;	    /* type code of pointing device */
	    u_short duart_imask;    /* shadowing for duart intrpt mask reg */
	    u_short adder_ie;	    /* shadowing for adder intrpt enbl reg */
	    u_short curs_acc;	    /* cursor acceleration factor */
	    u_short curs_thr;	    /* cursor acceleration threshold level */
	    u_short tab_res;	    /* tablet resolution factor */
	    u_short selmask;	    /* mask for active qd select entries */
	};
E 6

D 3
/* bit definitions for "inuse" entry  */
E 3
I 3
D 6
/* #define POSIXTTY (4.4BSD) */
E 6
I 6
	/* bit definitions for "inuse" entry  */
E 6
E 3

E 10
I 10
/*
 * bit definitions for 'inuse' entry  
 */
E 10
I 3
D 6
/* bit definitions for "inuse" entry  */
E 6
E 3
#define CONS_DEV	0x01
D 10
#define ALTCONS_DEV	0x02
E 10
#define GRAPHIC_DEV	0x04

D 6
/* bit definitions for 'mapped' member of flag structure */
E 6
I 6
D 10
	/* bit definitions for 'mapped' member of flag structure */

E 10
I 10
/*
 * bit definitions for 'mapped' member of flag structure 
 */
E 10
E 6
D 3

E 3
#define MAPDEV		0x01		/* hardware is mapped */
#define MAPDMA		0x02		/* DMA buffer mapped */
#define MAPEQ		0x04		/* event queue buffer mapped */
#define MAPSCR		0x08		/* scroll param area mapped */
#define MAPCOLOR	0x10		/* color map writing buffer mapped */

D 6
/* bit definitions for 'selmask' member of qdflag structure */
E 6
I 6
D 10
	/* bit definitions for 'selmask' member of qdflag structure */
E 6

E 10
I 10
/*
 * bit definitions for 'selmask' member of qdflag structure 
 */
E 10
#define SEL_READ	0x01		/* read select is active */
#define SEL_WRITE	0x02		/* write select is active */

D 6
/*
* constants used in shared memory operations 
*/
E 6
I 6
D 10
/*----------------------------------------------
* constants used in shared memory operations */
E 6

E 10
I 10
/*
D 11
* constants used in shared memory operations 
*/
E 11
I 11
 * constants used in shared memory operations 
 */
E 11
E 10
#define EVENT_BUFSIZE  1024	/* # of bytes per device's event buffer */
I 6
D 10

E 10
E 6
D 3

E 3
#define MAXEVENTS  ( (EVENT_BUFSIZE - sizeof(struct qdinput))	 \
D 10
		     / sizeof(struct _vs_event) )
I 6

E 10
I 10
	/ sizeof(struct _vs_event) )
E 10
E 6
D 3

E 3
D 4
#define DMA_BUFSIZ	(1024 * 3)
E 4
I 4
#define DMA_BUFSIZ	(1024 * 10)
I 6
D 10

E 10
E 6
E 4
D 3

E 3
#define COLOR_BUFSIZ  ((sizeof(struct color_buf) + 512) & ~0x01FF)

D 3


E 3
D 6
/*
E 6
I 6
D 10
/*******************************************************************/

extern char qvmem[][128*NBPG];
extern struct pte QVmap[][128];


/*--------------------------------------------------------------------------
E 10
I 10
/*
E 10
E 6
D 11
* reference to an array of "uba_device" structures built by the auto
* configuration program.  The uba_device structure decribes the device
* sufficiently for the driver to talk to it.  The auto configuration code
* fills in the uba_device structures (located in ioconf.c) from user
D 6
* maintained info.  
*/
E 6
I 6
D 10
* maintained info.  */
E 10
I 10
* maintained info.  
*/
E 11
I 11
 * reference to an array of "uba_device" structures built by the auto
 * configuration program.  The uba_device structure decribes the device
 * sufficiently for the driver to talk to it.  The auto configuration code
 * fills in the uba_device structures (located in ioconf.c) from user
 * maintained info.  
 */
E 11
struct uba_device *qdinfo[NQD];  /* array of pntrs to each QDSS's */
struct tty qd_tty[NQD*4];	/* teletype structures for each.. */
D 11
struct qd_softc qd_softc[NQD];
extern char qvmem[][128*NBPG];	/* XXX - *NQD - but can't test it */
E 11
I 11
extern char qvmem[][128*NBPG];
E 11
extern struct pte QVmap[][128];
#define CHUNK	  (64 * 1024)
#define QMEMSIZE  (1024 * 1024 * 4)	/* 4 meg */
E 10
E 6

D 6
struct uba_device *qdinfo[NQD];  /* array of pntrs to each QDSS's */
				 /* uba structures  */
struct tty qd_tty[NQD*4];	/* teletype structures for each.. */
				/* ..possible minor device */
E 6
I 6
D 10
	struct uba_device *qdinfo[NQD];  /* array of pntrs to each QDSS's */
					 /* uba structures  */
	struct tty qd_tty[NQD*4];	/* teletype structures for each.. */
					/* ..possible minor device */
E 10
I 10
/*
 * static storage used by multiple functions in this code  
 */
int Qbus_unmap[NQD];		/* Qbus mapper release code */
struct qdflags qdflags[NQD];	/* QDSS device status flags */
struct qdmap qdmap[NQD];	/* QDSS register map structure */
caddr_t qdbase[NQD];		/* base address of each QDSS unit */
struct buf qdbuf[NQD];		/* buf structs used by strategy */
short qdopened[NQD];		/* graphics device is open exclusive use */
E 10
E 6

D 6
struct qd_softc qd_softc[NQD];
E 6
I 6
D 10
	struct qd_softc qd_softc[NQD];
E 6

D 6
/*
D 3
* static storage used by multiple functions in this code  
*/

E 3
I 3
 * static storage used by multiple functions in this code  
 */
E 3
int Qbus_unmap[NQD];		/* Qbus mapper release code */
struct qdflags qdflags[NQD];	/* QDSS device status flags */
struct qdmap qdmap[NQD];	/* QDSS register map structure */
caddr_t qdbase[NQD];		/* base address of each QDSS unit */
struct buf qdbuf[NQD];		/* buf structs used by strategy */
char one_only[NQD];		/* lock for single process access */
E 6
I 6
/*----------------------------------------------------------
* static storage used by multiple functions in this code  */
E 6

D 6
/*
* The array "event_shared[]" is made up of a number of event queue buffers
E 6
I 6
	int Qbus_unmap[NQD];		/* Qbus mapper release code */
	struct qdflags qdflags[NQD];	/* QDSS device status flags */
	struct qdmap qdmap[NQD];	/* QDSS register map structure */
	caddr_t qdbase[NQD];		/* base address of each QDSS unit */
	struct buf qdbuf[NQD];		/* buf structs used by strategy */
	char one_only[NQD];		/* lock for single process access */

/*------------------------------------------------------------------------
E 10
I 10
/*
E 10
D 11
* the array "event_shared[]" is made up of a number of event queue buffers
E 6
* equal to the number of QDSS's configured into the running kernel (NQD).
* Each event queue buffer begins with an event queue header (struct qdinput)
* followed by a group of event queue entries (struct _vs_event).  The array
* "*eq_header[]" is an array of pointers to the start of each event queue
D 6
* buffer in "event_shared[]".  
*/
E 6
I 6
D 10
* buffer in "event_shared[]".  */
E 6

E 10
I 10
* buffer in "event_shared[]".  
*/
E 11
I 11
 * the array "event_shared[]" is made up of a number of event queue buffers
 * equal to the number of QDSS's configured into the running kernel (NQD).
 * Each event queue buffer begins with an event queue header (struct qdinput)
 * followed by a group of event queue entries (struct _vs_event).  The array
 * "*eq_header[]" is an array of pointers to the start of each event queue
 * buffer in "event_shared[]".  
 */
E 11
E 10
#define EQSIZE ((EVENT_BUFSIZE * NQD) + 512)

D 6
char event_shared[EQSIZE];	    /* reserve space for event bufs */
struct qdinput *eq_header[NQD];     /* event queue header pntrs */
E 6
I 6
D 10
	char event_shared[EQSIZE];	    /* reserve space for event bufs */
	struct qdinput *eq_header[NQD];     /* event queue header pntrs */
E 10
I 10
char event_shared[EQSIZE];	    /* reserve space for event bufs */
struct qdinput *eq_header[NQD];     /* event queue header pntrs */
E 10
E 6

D 6
/*
E 6
I 6
D 10
/*--------------------------------------------------------------------------
E 10
I 10
/*
E 10
E 6
D 11
* This allocation method reserves enough memory pages for NQD shared DMA I/O
* buffers.  Each buffer must consume an integral number of memory pages to
* guarantee that a following buffer will begin on a page boundary.  Also,
* enough space is allocated so that the FIRST I/O buffer can start at the
* 1st page boundary after "&DMA_shared".  Page boundaries are used so that
D 6
* memory protections can be turned on/off for individual buffers. 
*/
E 6
I 6
D 10
* memory protections can be turned on/off for individual buffers. */
E 6

E 10
I 10
* memory protections can be turned on/off for individual buffers. 
*/
E 11
I 11
 * This allocation method reserves enough memory pages for NQD shared DMA I/O
 * buffers.  Each buffer must consume an integral number of memory pages to
 * guarantee that a following buffer will begin on a page boundary.  Also,
 * enough space is allocated so that the FIRST I/O buffer can start at the
 * 1st page boundary after "&DMA_shared".  Page boundaries are used so that
 * memory protections can be turned on/off for individual buffers. 
 */
E 11
E 10
#define IOBUFSIZE  ((DMA_BUFSIZ * NQD) + 512)

D 6
char DMA_shared[IOBUFSIZE];	    /* reserve I/O buffer space */
struct DMAreq_header *DMAheader[NQD];  /* DMA buffer header pntrs */
E 6
I 6
D 10
	char DMA_shared[IOBUFSIZE];	    /* reserve I/O buffer space */
	struct DMAreq_header *DMAheader[NQD];  /* DMA buffer header pntrs */
E 10
I 10
char DMA_shared[IOBUFSIZE];	    /* reserve I/O buffer space */
struct DMAreq_header *DMAheader[NQD];  /* DMA buffer header pntrs */
E 10
E 6

D 6
/*
E 6
I 6
D 10
/*-------------------------------------------------------------------------
E 10
I 10
/*
E 10
E 6
D 11
* The driver assists a client in scroll operations by loading dragon
* registers from an interrupt service routine.	The loading is done using
* parameters found in memory shrade between the driver and it's client.
* The scroll parameter structures are ALL loacted in the same memory page
D 6
* for reasons of memory economy.  
*/
E 6
I 6
D 10
* for reasons of memory economy.  */
E 10
I 10
* for reasons of memory economy.  
*/
E 11
I 11
 * The driver assists a client in scroll operations by loading dragon
 * registers from an interrupt service routine.	The loading is done using
 * parameters found in memory shrade between the driver and it's client.
 * The scroll parameter structures are ALL loacted in the same memory page
 * for reasons of memory economy.  
 */
E 11
char scroll_shared[2 * 512];	/* reserve space for scroll structs */
struct scroll *scroll[NQD];	/* pointers to scroll structures */
E 10
E 6

D 6
char scroll_shared[2 * 512];	/* reserve space for scroll structs */
struct scroll *scroll[NQD];	/* pointers to scroll structures */
E 6
I 6
D 10
	char scroll_shared[2 * 512];	/* reserve space for scroll structs */
	struct scroll *scroll[NQD];	/* pointers to scroll structures */
E 6

D 6
/*
E 6
I 6
/*-----------------------------------------------------------------------
E 10
I 10
/*
E 10
E 6
D 11
* the driver is programmable to provide the user with color map write
* services at VSYNC interrupt time.  At interrupt time the driver loads
D 6
* the color map with any user-requested load data found in shared memory 
*/
E 6
I 6
D 10
* the color map with any user-requested load data found in shared memory */
E 6

E 10
I 10
* the color map with any user-requested load data found in shared memory 
*/
E 11
I 11
 * the driver is programmable to provide the user with color map write
 * services at VSYNC interrupt time.  At interrupt time the driver loads
 * the color map with any user-requested load data found in shared memory 
 */
E 11
E 10
#define COLOR_SHARED  ((COLOR_BUFSIZ * NQD) + 512)

D 3
char color_shared[COLOR_SHARED];      /* reserve space: color bufs */
E 3
I 3
D 6
char color_shared[COLOR_SHARED];      /* color bufs */
E 3
struct color_buf *color_buf[NQD];     /* pointers to color bufs */
E 6
I 6
D 10
	char color_shared[COLOR_SHARED];      /* reserve space: color bufs */
	struct color_buf *color_buf[NQD];     /* pointers to color bufs */
E 10
I 10
char color_shared[COLOR_SHARED];      /* reserve space: color bufs */
struct color_buf *color_buf[NQD];     /* pointers to color bufs */
E 10
E 6

D 6
/*
* mouse input event structures 
*/
E 6
I 6
D 10
/*--------------------------------
* mouse input event structures */
E 10
I 10
/*
D 11
* mouse input event structures 
*/
E 11
I 11
 * mouse input event structures 
 */
E 11
struct mouse_report last_rep[NQD];
struct mouse_report current_rep[NQD];
E 10
E 6

D 6
struct mouse_report last_rep[NQD];
struct mouse_report current_rep[NQD];
E 6
I 6
D 10
	struct mouse_report last_rep[NQD];
	struct mouse_report current_rep[NQD];
E 10
I 10
D 11
struct proc *rsel[NQD]; 	/* process waiting for select */
E 11
I 11
struct proc *qdrsel[NQD]; 	/* process waiting for select */
E 11
struct _vs_cursor cursor[NQD];	/* console cursor */
int qdcount = 0;		/* count of successfully probed qd's */
int nNQD = NQD;
int DMAbuf_size = DMA_BUFSIZ;
int QDlast_DMAtype;             /* type of the last DMA operation */
E 10
E 6

D 6
/*
* input event "select" use 
*/
E 6
I 6
D 10
/*----------------------------
* input event "select" use */
E 6

D 6
struct proc *rsel[NQD]; 	/* process waiting for select */
E 6
I 6
	struct proc *rsel[NQD]; 	/* process waiting for select */
E 6

D 6
/*
* console cursor structure 
*/
E 6
I 6
/*----------------------------
* console cursor structure */
E 6

D 6
struct _vs_cursor cursor[NQD];
E 6
I 6
	struct _vs_cursor cursor[NQD];
E 6

I 6
/*----------------------------
* count of successfully probed qd's */
E 6

I 6
	int qdcount = 0;
E 6

D 6
int nNQD = NQD;
E 6

D 6
int DMAbuf_size = DMA_BUFSIZ;
E 6
I 6
/************************************************************************/
E 6

I 6
	int nNQD = NQD;
E 6

D 6
/*
 * macro to get system time.  Used to time stamp event queue entries 
 */
E 6
I 6
	int DMAbuf_size = DMA_BUFSIZ;
E 6

E 2
D 6
#define TOY ((time.tv_sec * 100) + (time.tv_usec / 10000))
E 6

D 2
/*--------------------------------------------------------------------------
E 2
I 2
D 6
/*
E 2
* the "ioconf.c" program, built and used by auto config, externally refers
D 2
* to definitions below.  */
E 2
I 2
* to definitions below.  
*/
E 6
I 6
#define QDSSMAJOR	41		/* QDSS major device number */
#ifdef notdef	/* on ultrix */
extern	int	ws_display_type;
extern	int	ws_display_units;
#endif
/* don't need these  */
int	ws_display_type;
int	ws_display_units;
E 6
E 2

D 2
	int qdprobe();
	int qdattach();
	int qddint();			/* DMA gate array intrpt service */
	int qdaint();			/* Dragon ADDER intrpt service */
	int qdiint();
E 2
I 2
D 6
int qdprobe();
int qdattach();
int qddint();			/* DMA gate array intrpt service */
int qdaint();			/* Dragon ADDER intrpt service */
int qdiint();
E 6
I 6
int     QDlast_DMAtype;                 /* type of the last DMA operation */
E 6
E 2

D 2
	u_short qdstd[] = { 0 };
E 2
I 2
D 6
u_short qdstd[] = { 0 };
E 6
I 6
/*---------------------------------------------------------------------
* macro to get system time.  Used to time stamp event queue entries */
E 6
E 2

E 10
I 10
#define QDSSMAJOR	41	/* QDSS major device number */
/*
D 11
* macro to get system time.  Used to time stamp event queue entries 
*/
E 11
I 11
 * macro to get system time.  Used to time stamp event queue entries 
 */
E 11
E 10
D 2
	struct uba_driver qddriver = {	/* externally referenced: ioconf.c */
E 2
I 2
D 6
struct uba_driver qddriver = {	/* externally referenced: ioconf.c */
E 6
I 6
#define TOY ((time.tv_sec * 100) + (time.tv_usec / 10000))
E 6
E 2

D 2
	    qdprobe,			/* device probe entry */
	    0,				/* no slave device */
	    qdattach,			/* device attach entry */
	    0,				/* no "fill csr/ba to start" */
	    qdstd,			/* device addresses */
	    "qd",			/* device name string */
	    qdinfo			/* ptr to QDSS's uba_device struct */
	};
E 2
I 2
D 6
    qdprobe,			/* device probe entry */
    0,				/* no slave device */
    qdattach,			/* device attach entry */
    0,				/* no "fill csr/ba to start" */
    qdstd,			/* device addresses */
    "qd",			/* device name string */
    qdinfo			/* ptr to QDSS's uba_device struct */
};
E 6
I 6
D 10
/*--------------------------------------------------------------------------
* the "ioconf.c" program, built and used by auto config, externally refers
* to definitions below.  */
E 10
I 10
int qdprobe();
int qdattach();
int qddint();			/* DMA gate array intrpt service */
int qdaint();			/* Dragon ADDER intrpt service */
int qdiint();
E 10
E 6
E 2

D 2
/*-------------------
E 2
I 2
D 6
extern	char qvmem[][128*NBPG];
extern	struct pte QVmap[][128];
E 6
I 6
D 10
	int qdprobe();
	int qdattach();
	int qddint();			/* DMA gate array intrpt service */
	int qdaint();			/* Dragon ADDER intrpt service */
	int qdiint();
E 10
I 10
u_short qdstd[] = { 0 };
E 10
E 6

D 6
/*
 * v_putc is used to redirect the console cnputc to the virtual console
 * vputc.  consops is used to direct the console device to the qvss console.
 */
extern (*v_putc)();
extern struct cdevsw *consops;
E 6
I 6
D 10
	u_short qdstd[] = { 0 };
E 10
I 10
struct uba_driver qddriver = {
D 11
	qdprobe,			/* device probe entry */
	0,				/* no slave device */
	qdattach,			/* device attach entry */
	0,				/* no "fill csr/ba to start" */
E 11
I 11
	qdprobe,		/* device probe entry */
	0,			/* no slave device */
	qdattach,		/* device attach entry */
	0,			/* no "fill csr/ba to start" */
E 11
	qdstd,			/* device addresses */
	"qd",			/* device name string */
	qdinfo			/* ptr to QDSS's uba_device struct */
};
E 10
E 6

D 6
/*
E 6
I 6
D 10
	struct uba_driver qddriver = {	/* externally referenced: ioconf.c */

	    qdprobe,			/* device probe entry */
	    0,				/* no slave device */
	    qdattach,			/* device attach entry */
	    0,				/* no "fill csr/ba to start" */
	    qdstd,			/* device addresses */
	    "qd",			/* device name string */
	    qdinfo			/* ptr to QDSS's uba_device struct */
	};

/*-------------------
E 6
E 2
* general defines */

E 10
D 3
#define QDPRIOR (PZERO-1)		/* must be negative */
E 3
I 3
D 6
#define QDPRIOR (PZERO-1)
E 6
I 6
#define QDPRIOR (PZERO-1)		/* must be negative */
E 6
E 3
D 10

E 10
#define FALSE	0
#define TRUE	~FALSE
D 10

E 10
#define BAD	-1
#define GOOD	0

D 2
/*-----------------------------------------------------------------------
* macro to create a system virtual page number from system virtual adrs */
E 2
I 2
D 6
/*
 * Macro to create a system virtual page number from system virtual adrs.
 */
E 6
I 6
D 10
/*-----------------------------------------------------------------------
* macro to create a system virtual page number from system virtual adrs */
E 10
I 10
/*
 * macro to create a system virtual page number from system virtual adrs 
 */
#define VTOP(x)  (((int)x & ~0xC0000000) >> PGSHIFT)
E 10
E 6
E 2

D 2
#define VTOP(x)  (((int)x & ~0xC0000000) >> PGSHIFT) /* convert qmem adrs */
						     /* to system page # */
E 2
I 2
D 6
#define VTOP(x)  (((int)x & ~0xC0000000) >> PGSHIFT)
E 6
I 6
D 10
#define VTOP(x)  (((int)x & ~0xC0000000) >> PGSHIFT) /* convert qvmem adrs */
						     /* to system page # */
E 6
E 2

D 2
/*------------------------------------------------------------------
* QDSS register address offsets from start of QDSS address space */
E 2
I 2
D 6
/*
 * QDSS register address offsets from start of QDSS address space 
 */
E 6
I 6
/*------------------------------------------------------------------
* QDSS register address offsets from start of QDSS address space */
E 6
E 2

E 10
I 10
/*
 * QDSS register address offsets from start of QDSS address space 
 */
E 10
#define QDSIZE	 (52 * 1024)	/* size of entire QDSS foot print */
D 10

E 10
#define TMPSIZE  (16 * 1024)	/* template RAM is 8k SHORT WORDS */
#define TMPSTART 0x8000 	/* offset of template RAM from base adrs */
D 10

E 10
#define REGSIZE  (5 * 512)	/* regs touch 2.5k (5 pages) of addr space */
#define REGSTART 0xC000 	/* offset of reg pages from base adrs */
D 10

E 10
#define ADDER	(REGSTART+0x000)
#define DGA	(REGSTART+0x200)
#define DUART	(REGSTART+0x400)
#define MEMCSR	(REGSTART+0x800)
D 10

E 10
#define CLRSIZE  (3 * 512)		/* color map size */
#define CLRSTART (REGSTART+0xA00)	/* color map start offset from base */
D 10
					/*  0x0C00 really */
E 10
I 10
/*  0x0C00 really */
E 10
#define RED	(CLRSTART+0x000)
#define BLUE	(CLRSTART+0x200)
#define GREEN	(CLRSTART+0x400)

D 2
/*---------------------------------------------------------------
* values used in mapping QDSS hardware into the Q memory space */
E 2
I 2
D 6
/*
 * Values used in mapping QDSS hardware into the Q memory space.
 */
E 6
I 6
D 10
/*---------------------------------------------------------------
* values used in mapping QDSS hardware into the Q memory space */
E 10
E 6
E 2

D 10
#define CHUNK	  (64 * 1024)
D 2
#define QMEMSIZE  (1024 * 1024 * 4)	/* 4 meg */
E 2
I 2
D 6
#define QMEMSIZE  (1024 * 1024 * 4)
E 6
I 6
#define QMEMSIZE  (1024 * 1024 * 4)	/* 4 meg */
E 10
I 10
/*
 * QDSS minor device numbers.  The *real* minor device numbers are in
 * the bottom two bits of the major/minor device spec.  Bits 2 and up are
 * used to specify the QDSS device number (ie: which one?) 
 */
E 10
E 6
E 2

D 2
/*----------------------------------------------------------------------
E 2
I 2
D 6
/*
E 6
I 6
D 10
/*----------------------------------------------------------------------
E 6
E 2
* QDSS minor device numbers.  The *real* minor device numbers are in
* the bottom two bits of the major/minor device spec.  Bits 2 and up are
D 2
* used to specify the QDSS device number (ie: which one?) */
E 2
I 2
D 6
* used to specify the QDSS device number (ie: which one?)
*/
E 6
I 6
* used to specify the QDSS device number (ie: which one?) */
E 6
E 2

D 2
#define QDSSMAJOR	42		/* QDSS major device number */
E 2
I 2
D 6
#define QDSSMAJOR	41		/* QDSS major device number */
E 6
E 2

E 10
#define CONS		0
D 10
#define ALTCONS 	1
E 10
#define GRAPHIC 	2

D 2
/*----------------------------------------------
* console cursor bitmap (block cursor type)  */
E 2
I 2
D 6
/*
 * console cursor bitmap (block cursor type) 
 */
E 6
I 6
D 10
/*----------------------------------------------
* console cursor bitmap (block cursor type)  */
E 10
I 10
/*
 * console cursor bitmap (white block cursor)  
 */
short cons_cursor[32] = {
	/* A */ 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
	0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
	/* B */ 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
	0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF
};
E 10
E 6
E 2

D 10
	short cons_cursor[32] = {      /* white block cursor */

 /* A */ 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
	 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
 /* B */ 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
	 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF

	};

D 2
/*-------------------------------------
* constants used in font operations */
E 2
I 2
D 6
/*
 * constants used in font operations 
 */
E 6
I 6
/*-------------------------------------
* constants used in font operations */
E 6
E 2

D 6
#define CHARS		95			/* # of chars in the font */
E 6
I 6

/* Originaly this was CHARS 95 */
E 10
I 10
/*
 * constants used in font operations 
 */
E 10
#define CHARS		190 			/* # of chars in the font */
D 10

E 10
E 6
#define CHAR_HEIGHT	15			/* char height in pixels */
#define CHAR_WIDTH	8			/* char width in pixels*/
#define FONT_WIDTH	(CHAR_WIDTH * CHARS)	/* font width in pixels */
#define ROWS		CHAR_HEIGHT
D 10


E 10
#define FONT_X		0			/* font's off screen adrs */
#define FONT_Y		(2048 - CHAR_HEIGHT)
D 6
/*
#define FONT_Y		200
*/
E 6

D 2
	extern char q_font[];		/* reference font object code */
E 2
I 2
D 6
extern char q_font[];		/* reference font object code */
E 6
I 6
D 10
					/* Offset to second row characters */
E 10
I 10
/* Offset to second row characters (XXX - should remove) */
E 10
#define FONT_OFFSET	((MAX_SCREEN_X/CHAR_WIDTH)*CHAR_HEIGHT)
E 6
E 2

D 2
	extern	char q_key[];		/* reference key xlation tables */
	extern	char q_shift_key[];
	extern	char *q_special[];
E 2
I 2
D 6
extern	char q_key[];		/* reference key xlation tables */
extern	char q_shift_key[];
extern	char *q_special[];
E 6
I 6
D 10
	extern char q_font[];		/* reference font object code */
E 10
I 10
extern char q_font[];		/* reference font object code */
D 14
extern	u_short q_key[];	/* reference key xlation tables */
extern	u_short q_shift_key[];
E 14
I 14
extern	char q_key[];		/* reference key xlation tables */
extern	char q_shift_key[];
E 14
extern	char *q_special[];
E 10
E 6
E 2

D 2
/*--------------------------------------------------
* definitions for cursor acceleration reporting  */
E 2
I 2
D 6
/*
 * definitions for cursor acceleration reporting
 */
E 6
I 6
D 10
	extern	u_short q_key[];		/* reference key xlation tables */
	extern	u_short q_shift_key[];
	extern	char *q_special[];
E 6
E 2

I 6
/*--------------------------------------------------
* definitions for cursor acceleration reporting  */

E 10
I 10
/*
 * definitions for cursor acceleration reporting  
 */
E 10
E 6
#define ACC_OFF 	0x01		/* acceleration is inactive */

D 2
/*--------------------------------------------------------------------------
* v_consputc is the switch that is used to redirect the console cnputc() to
* the virtual console qdputc().
* v_consgetc is the switch that is used to redirect the console getchar() to
* the virtual console qdgetc().
*/
E 2
I 2
D 6
int qdputc();		/* used to direct kernel console output *
int qdstart();		/* used to direct /dev/console output *
E 6
I 6
D 10
/*--------------------------------------------------------------------------
* v_consputc is the switch that is used to redirect the console cnputc() to
* the virtual console qdputc().
* v_consgetc is the switch that is used to redirect the console getchar() to
* the virtual console qdgetc().
*/
E 10
I 10
/*
 * virtual console support.
 */
extern (*v_putc)();
extern struct cdevsw *consops;
int qdputc();
int qdstart();
E 10
E 6
E 2

D 2
	extern (*v_consputc)();
	int qdputc();		/* used to direct kernel console output */
	extern (*v_consgetc)();
	int qdgetc();		/* used to read kernel console input */
E 2
I 2
D 6
/*
 * LK-201 state storage for input console keyboard conversion to ASCII 
 */
E 6
I 6
D 10
#ifdef notdef
	extern (*v_consputc)();
	int qdputc();		/* used to direct kernel console output */
	extern (*v_consgetc)();
	int qdgetc();		/* used to read kernel console input */
E 10
I 10
/*
 * LK-201 state storage for input console keyboard conversion to ASCII 
 */
struct q_keyboard {
	int shift;			/* state variables	*/
	int cntrl;
	int lock;
	int lastcode;			/* last keycode typed	*/
	unsigned kup[8];		/* bits for each keycode*/
	unsigned dkeys[8];		/* down/up mode keys	*/
	char last;			/* last character	*/
} q_keyboard;
E 10
E 6
E 2

D 2
	int qdstart();		/* used to direct /dev/console output */
E 2
I 2
D 6
struct q_keyboard {
E 2
D 3

E 3
D 2
/*------------------------------------------------------------------------
* LK-201 state storage for input console keyboard conversion to ASCII */
E 2
I 2
    int shift;			/* state variables	*/
    int cntrl;
    int lock;
    int lastcode;		/* last keycode typed	*/
    unsigned kup[8];		/* bits for each keycode*/
    unsigned dkeys[8];		/* down/up mode keys	*/
    char last;			/* last character	*/
I 3
} q_keyboard;
E 6
I 6
D 10
	int qdstart();		/* used to direct /dev/console output */
#endif
	extern (*v_putc)();
	extern struct cdevsw *consops;
	int qdputc();
	int qdstart();
E 6
E 3
E 2

I 6
/*------------------------------------------------------------------------
* LK-201 state storage for input console keyboard conversion to ASCII */
E 6
D 2
	struct q_keyboard {
E 2
I 2
D 3
 } q_keyboard;
E 3
E 2

I 6
	struct q_keyboard {

	    int shift;			/* state variables	*/
	    int cntrl;
	    int lock;
	    int lastcode;		/* last keycode typed	*/
	    unsigned kup[8];		/* bits for each keycode*/
	    unsigned dkeys[8];		/* down/up mode keys	*/
	    char last;			/* last character	*/

	 } q_keyboard;

/*--------------------------------------------------
* ULTRIX settings for first open.		  */
 
E 10
I 10
/*
 * tty settings on first open
 */
E 10
#define IFLAGS	(EVENP|ECHO|XTABS|CRMOD)
D 10

/*------------------------------------------------------------------------
* termio flags will be set to these default values in non-termio mode to
* provide a backward compatible ULTRIX environment. */

E 10
#ifdef POSIXTTY
#define IFLAG (BRKINT|ISTRIP|IXON|IXANY|ICRNL|IEXTEN|IMAXBEL)
#define OFLAG (OPOST|OXTABS|ONLCR)
#define LFLAG (ISIG|ICANON|ECHO)
#define CFLAG (PARENB|CREAD|CS7|CLOCAL)
#endif

D 10
/*****************************************************************
******************************************************************
******************************************************************
*
*	DRIVER FUNCTIONS START HERE:
*
******************************************************************
******************************************************************
*****************************************************************/

E 10
E 6
D 2
	    int shift;			/* state variables	*/
	    int cntrl;
	    int lock;
	    int lastcode;		/* last keycode typed	*/
	    unsigned kup[8];		/* bits for each keycode*/
	    unsigned dkeys[8];		/* down/up mode keys	*/
	    char last;			/* last character	*/
E 2
D 3

D 2
	 } q_keyboard;


/*****************************************************************
******************************************************************
******************************************************************
E 2
I 2
/*
E 2
*
D 2
*	DRIVER FUNCTIONS START HERE:
E 2
I 2
*	DRIVER FUNCTIONS :
E 2
*
D 2
******************************************************************
******************************************************************
*****************************************************************/
E 2
I 2
*/
E 2

E 3
D 11
/*********************************************************************
*
D 3
*	qdcons_init()... init QDSS as console (before probe routine)
E 3
I 3
D 6
*	qdcons_init - init QDSS as console (BEFORE probe routine)
E 6
I 6
*	qdcons_init()... init QDSS as console (before probe routine)
E 6
E 3
*
*********************************************************************/
E 11
I 11
/*
 * Init QDSS as console (before probe routine)
 */
E 11

qdcons_init()
{
D 11
	register u_int unit;
D 10

E 10
I 2
D 6
	struct percpu *pcpu;		/* pointer to percpu structure */
	register struct qbus *qb;
E 6
E 2
	int *ptep;			/* page table entry pointer */
E 11
I 11
	register unit;
E 11
	caddr_t phys_adr;		/* physical QDSS base adrs */
D 6
	u_int mapix;			/* index into QMEMmap[] array */
E 6
I 6
	u_int mapix;			/* index into QVmap[] array */
E 6
D 10

E 10
I 6
	struct percpu *pcpu;		/* pointer to cpusw structure  */
	register struct qbus *qb;
E 6
D 2
	struct cpusw *cpup;		/* pointer to cpusw structure  */
E 2
	u_short *qdaddr;		/* address of QDSS IO page CSR */
	u_short *devptr;		/* vitual device space */
I 2
D 6
	extern	cnputc();		/* standard serial console putc */
E 6
I 6
	extern cnputc();
E 6
E 2

#define QDSSCSR 0x1F00

I 2
D 6
	/*
	 * if console already configured, dont do again.
	 */
E 6
	if (v_putc != cnputc)
D 10
		return;
E 10
I 10
D 11
	    return;
E 11
I 11
	    return 0;
E 11
E 10

E 2
	unit = 0;

D 2
/*----------------------------------------------------
* find the cpusw entry that matches this machine. */
E 2
I 2
D 6
	/*
	 * find the cpusw entry that matches this machine. 
	 */
E 6
I 6
D 10
/*----------------------------------------------------
* find the cpusw entry that matches this machine. */
E 6
E 2

E 10
I 10
	/*
	 * find the cpusw entry that matches this machine. 
	 */
E 10
D 2
	cpup = &cpusw[cpu];
				;
	if( cpup == NULL ) {
		return(0);
	}
E 2
I 2
	for (pcpu = percpu; pcpu && pcpu->pc_cputype != cpu; pcpu++)
		;
	if (pcpu == NULL)
D 10
		return;
E 10
I 10
D 11
	    return;
E 11
I 11
	    return 0;
I 13
	if (pcpu->pc_io->io_type != IO_QBUS)
	    return 0;
E 13
E 11
E 10
E 2

I 6
D 10
#ifdef notdef	/* the ultrix way */
/*------------------------------------------------------
* Map the Q-bus memory space into the system memory. */
E 6
D 2
/*------------------------------------------------------
* Map the Q-bus memory space into the system memory. */
E 2

I 6
	ubaaccess(((*cpup->v_umaddr)(0)), QVmap[0],
			cpup->pc_umsize, PG_V | PG_KW);

	ubaaccess(((*cpup->v_udevaddr)(0)), QVmap[0]+btop(cpup->pc_umsize),
			DEVSPACESIZE ,PG_V|PG_KW);

/*---------------------------------------------------------------------
* map the QDSS into the Qbus memory (which is now in system space)  */

	devptr = (u_short *)((char *)qvmem[0]+cpup->pc_umsize);
	qdaddr = (u_short *)((u_int)devptr + ubdevreg(QDSSCSR));

	if (BADADDR(qdaddr, sizeof(short)))
		return(0);

	/*---------------------------------------------------
	* tell QDSS which Q memory address base to decode */

	mapix = (int) VTOP(QMEMSIZE - CHUNK);
	ptep = (int *) QVmap[0] + mapix;
	phys_adr = (caddr_t) (((int)*ptep & 0x001FFFFF) << PGSHIFT);
	*qdaddr = (u_short) ((int)phys_adr >> 16);

	qdflags[unit].config = *(u_short *)qdaddr;

#endif /*notdef*/

	/* the BSD way */
E 10
E 6
D 2
	ubaaccess(((*cpup->v_umaddr)(0)), QMEMmap[0],
			cpup->pc_umsize, PG_V | PG_KW);
E 2
I 2
	/*
D 6
	 * Map device registers - the last 8K of umem.
E 6
I 6
	 * Map device registers - the last 8K of qvmem.
E 6
	 */
	qb = (struct qbus *)pcpu->pc_io->io_details;
	ioaccess(qb->qb_iopage, UMEMmap[0] + qb->qb_memsize,
D 10
		UBAIOPAGES * NBPG);
E 2

E 10
I 10
D 11
	UBAIOPAGES * NBPG);
E 11
I 11
		 UBAIOPAGES * NBPG);
E 11
E 10
D 2
	ubaaccess(((*cpup->v_udevaddr)(0)), QMEMmap[0]+btop(cpup->pc_umsize),
			DEVSPACESIZE ,PG_V|PG_KW);

/*---------------------------------------------------------------------
* map the QDSS into the Qbus memory (which is now in system space)  */

	devptr = (u_short *)((char *)qmem[0]+cpup->pc_umsize);
E 2
I 2
	devptr = (u_short *)((char *)umem[0]+(qb->qb_memsize * NBPG));
E 2
	qdaddr = (u_short *)((u_int)devptr + ubdevreg(QDSSCSR));
D 2

	if (BADADDR(qdaddr, sizeof(short)))
E 2
I 2
D 11
	if (badaddr(qdaddr, sizeof(short)))  {
D 6
		log(LOG_ERR, "Can't find qdss (badaddr)\n"); /* debug */
E 6
I 6
		printf("Can't find qdss (badaddr)\n"); /* debug */
E 6
E 2
		return(0);
I 2
	}
E 11
I 11
	if (badaddr((caddr_t)qdaddr, sizeof(short)))
		return 0;
E 11
I 6

D 10


E 10
E 6
	/*
	 * Map q-bus memory used by qdss. (separate map)
	 */
	mapix = QMEMSIZE - (CHUNK * (unit + 1));
	phys_adr = qb->qb_maddr + mapix;
	ioaccess(phys_adr, QVmap[0], (CHUNK*NQD));
E 2

D 2
	/*---------------------------------------------------
	* tell QDSS which Q memory address base to decode */
E 2
I 2
	/*
	 * tell QDSS which Q memory address base to decode 
I 10
	 * (shifted right 16 bits - its in 64K units)
E 10
	 */
E 2
D 10

D 2
	mapix = (int) VTOP(QMEMSIZE - CHUNK);
	ptep = (int *) QMEMmap[0] + mapix;
	phys_adr = (caddr_t) (((int)*ptep & 0x001FFFFF) << PGSHIFT);
	*qdaddr = (u_short) ((int)phys_adr >> 16);

E 2
I 2
	/* 
	 * shifted right 16 bits - its in 64K units
	 */
E 10
	*qdaddr = (u_short)((int)mapix >> 16);
E 2
	qdflags[unit].config = *(u_short *)qdaddr;

D 2
/*----------------------------------------------------------------------
* load qdmap struct with the virtual addresses of the QDSS elements */
E 2
I 2
D 6
	/*
	 * load qdmap struct with the virtual addresses of the QDSS elements 
	 */
E 6
I 6
D 10
/*----------------------------------------------------------------------
* load qdmap struct with the virtual addresses of the QDSS elements */
E 6
E 2

D 2
	qdbase[unit] = (caddr_t) (qmem[0] + QMEMSIZE - CHUNK);
E 2
I 2
D 6
	qdbase[unit] = (caddr_t) qvmem[0];
E 6
I 6
#ifdef notdef	/*ultrix way */
	qdbase[unit] = (caddr_t) (qvmem[0] + QMEMSIZE - CHUNK);
#endif
E 6
E 2

E 10
I 10
	/*
	 * load qdmap struct with the virtual addresses of the QDSS elements 
	 */
E 10
I 6
	qdbase[unit] = (caddr_t) (qvmem[0]);
D 10

E 10
E 6
	qdmap[unit].template = qdbase[unit] + TMPSTART;
	qdmap[unit].adder = qdbase[unit] + ADDER;
	qdmap[unit].dga = qdbase[unit] + DGA;
	qdmap[unit].duart = qdbase[unit] + DUART;
	qdmap[unit].memcsr = qdbase[unit] + MEMCSR;
	qdmap[unit].red = qdbase[unit] + RED;
	qdmap[unit].blue = qdbase[unit] + BLUE;
	qdmap[unit].green = qdbase[unit] + GREEN;

	qdflags[unit].duart_imask = 0;	/* init shadow variables */

D 2
/*------------------
* init the QDSS  */
E 2
I 2
D 6
	/*
	 * init the QDSS 
	 */
E 6
I 6
D 10
/*------------------
* init the QDSS  */
E 6
E 2

E 10
I 10
	/*
	 * init the QDSS  
	 */
	/* 
E 10
I 2
D 6
	/***
E 6
	printf("qdbase[0] = %x, qdmap[0].memcsr = %x\n",
D 6
		(char *)qdbase[0], qdmap[0].memcsr);
	***/
E 6
I 6
D 10
			(char *)qdbase[0], qdmap[0].memcsr);
E 10
I 10
		(char *)qdbase[0], qdmap[0].memcsr);
	*/
E 10
E 6

E 2
	*(short *)qdmap[unit].memcsr |= SYNC_ON; /* once only: turn on sync */

	cursor[unit].x = 0;
	cursor[unit].y = 0;
	init_shared(unit);		/* init shared memory */
	setup_dragon(unit);		/* init the ADDER/VIPER stuff */
	clear_qd_screen(unit);		/* clear the screen */
	ldfont(unit);			/* load the console font */
	ldcursor(unit, cons_cursor);	/* load default cursor map */
	setup_input(unit);		/* init the DUART */
D 10

I 6
/*----------------------------------------------------
* smash the system's virtual console address table */

#ifdef notdef	/* the ultrix way */
	v_consputc = qdputc;
	v_consgetc = qdgetc;
	cdevsw[0] = cdevsw[QDSSMAJOR];
#endif
	/* the bsd way */
E 6
D 2
/*----------------------------------------------------
* smash the system's virtual console address table */
E 2
I 2
	v_putc = qdputc;
	consops = &cdevsw[QDSSMAJOR];
E 2

I 6
 	ws_display_type = QDSSMAJOR;	/* Idenify QDSS as graphics device */
E 10
I 10
	v_putc = qdputc;		/* kernel console output to qdss */
	consops = &cdevsw[QDSSMAJOR];	/* virtual console is qdss */
E 10
E 6
D 2
	v_consputc = qdputc;
	v_consgetc = qdgetc;
	cdevsw[0] = cdevsw[QDSSMAJOR];
E 2
D 11
	return(1);
E 11
I 11
	return 1;
E 11

} /* qdcons_init */

D 11
/*********************************************************************
*
*	qdprobe()... configure QDSS into Q memory and make it intrpt
*
**********************************************************************
*
*  calling convention:
*			qdprobe(reg, ctlr);
*			caddr_t reg;
*			int ctlr;
*
*	where: reg - a character pointer to the QDSS I/O page register
*	       ctlr - controller number (?)
*
*  side effects: QDSS gets mapped into Qbus memory space at the first
*		 vacant 64kb boundary counting back from the top of
D 6
*		 Qbus memory space (qmem+4mb)
E 6
I 6
*		 Qbus memory space (qvmem+4mb)
E 6
*
*  return: QDSS bus request level and vector address returned in
*	   registers by UNIX convention.
*
*****************/

E 11
I 11
/*
 *  Configure QDSS into Q memory and make it intrpt.
 *
 *  side effects: QDSS gets mapped into Qbus memory space at the first
 *		 vacant 64kb boundary counting back from the top of
 *		 Qbus memory space (qvmem+4mb)
 *
 *  return: QDSS bus request level and vector address returned in
 *	   registers by UNIX convention.
 *
 */
E 11
qdprobe(reg)
D 10
caddr_t reg;
E 10
I 10
D 11
	caddr_t reg;
E 11
I 11
	caddr_t reg;	/* character pointer to the QDSS I/O page register */
E 11
E 10
{
D 2
	/* the variables MUST reside in the first two register declarations
	* by UNIX convention in order that they be loaded and returned
	* properly by the interrupt catching mechanism.  */
E 2
I 2
D 6
	register int br, cvec; 	/* value-result */
E 6
I 6
D 10
	register int br, cvec;  /* value-result */
E 6
E 2

E 10
I 10
	register int br, cvec;  	/* value-result */
E 10
	register int unit;
D 10

E 10
	struct dga *dga;		/* pointer to gate array structure */
D 11
	struct cpusw *cpup;		/* pointer to the cpusw structure */
D 10

E 10
	int *ptep;			/* page table entry pointer */
E 11
	int vector;
I 11
#ifdef notdef
	int *ptep;			/* page table entry pointer */
E 11
D 10

E 10
	caddr_t phys_adr;		/* physical QDSS base adrs */
	u_int mapix;
I 11
#endif
E 11

I 11
#ifdef lint
	br = 0; cvec = br; br = cvec; nNQD = br; br = nNQD;
	qddint(0); qdaint(0); qdiint(0); (void)qdgetc();
#endif

E 11
D 2
/*---------------------------------------------------------------
* calculate board unit number from I/O page register address  */
E 2
I 2
D 6
#ifdef lint
	br = 0; cvec = br; br = cvec;
#endif
E 6
I 6
D 10
/*---------------------------------------------------------------
* calculate board unit number from I/O page register address  */
E 6
E 2

E 10
I 10
	/*
	 * calculate board unit number from I/O page register address  
	 */
E 10
I 2
D 6
	/*
	* calculate board unit number from I/O page register address  
	*/

E 6
E 2
	unit = (int) (((int)reg >> 1) & 0x0007);

D 2
/*---------------------------------------------------------------------------
E 2
I 2
D 6
/*
E 6
I 6
D 10
/*---------------------------------------------------------------------------
E 6
E 2
* QDSS regs must be mapped to Qbus memory space at a 64kb physical boundary.
* The Qbus memory space is mapped into the system memory space at config
D 6
* time.  After config runs, "qmem[0]" (ubavar.h) holds the system virtual adrs
E 6
I 6
* time.  After config runs, "qvmem[0]" (ubavar.h) holds the system virtual adrs
E 6
* of the start of Qbus memory.	The Qbus memory page table is found via
D 6
* an array of pte ptrs called "QMEMmap[]" (ubavar.h) which is also loaded at
E 6
I 6
* an array of pte ptrs called "QVmap[]" (ubavar.h) which is also loaded at
E 6
* config time.	These are the variables used below to find a vacant 64kb
* boundary in Qbus memory, and load it's corresponding physical adrs into
D 2
* the QDSS's I/O page CSR.  */
E 2
I 2
D 6
* the QDSS's I/O page CSR.  
*/
E 6
I 6
* the QDSS's I/O page CSR.  */
E 10
I 10
	/*
	 * QDSS regs must be mapped to Qbus memory space at a 64kb
 	 * physical boundary.  The Qbus memory space is mapped into
	 * the system memory space at config time.  After config
	 * runs, "qvmem[0]" (ubavar.h) holds the system virtual adrs
	 * of the start of Qbus memory.   The Qbus memory page table
	 * is found via an array of pte ptrs called "QVmap[]" (ubavar.h)
	 * which is also loaded at config time.   These are the
	 * variables used below to find a vacant 64kb boundary in
	 * Qbus memory, and load it's corresponding physical adrs
	 * into the QDSS's I/O page CSR.  
	 */
E 10
E 6
E 2

I 6
	/*
	 * Only if QD is the graphics device.
	 */

D 10
	if (ws_display_type && (ws_display_type != QDSSMAJOR))
		return(0);

E 10
E 6
	/* if this QDSS is NOT the console, then do init here.. */

I 2
D 3
	/****** NOT FOR NOW - DO LATER (FARKLE) ***/
E 3
I 3
D 6
	/****** XXX - REMOVED (can't test) - STILL NEED TO DO FOR NQD > 1 ***/
E 3
#ifdef notdef
E 6
I 6
	if (unit != 0) {
		printf("qd: can't support two qdss's (yet)\n");
D 10
#ifdef notdef	/* notyet */
E 6
E 2
	if (v_consputc != qdputc  ||  unit != 0) {
E 10
I 10
D 11
#ifdef notdef	/* notyet - don't have two qd's so i can't test it */
E 11
I 11
#ifdef notdef	/* can't test */
E 11
		if (v_consputc != qdputc  ||  unit != 0) {
E 10

D 2
	    /*-------------------------
	    * read QDSS config info */

E 2
I 2
D 6
	    /*
	     * read QDSS config info
	     */
E 6
I 6
D 10
	    /*-------------------------
	    * read QDSS config info */
E 10
I 10
			/*
			* read QDSS config info 
			*/
			qdflags[unit].config = *(u_short *)reg;
E 10

E 6
E 2
D 10
	    qdflags[unit].config = *(u_short *)reg;
E 10
I 10
			/*
			* find an empty 64kb adrs boundary 
			*/
E 10

D 2
	    /*------------------------------------
	    * find an empty 64kb adrs boundary */

E 2
I 2
D 6
	    /*
	     * find an empty 64kb adrs boundary 
	     */
E 2
	    qdbase[unit] = (caddr_t) (qmem[0] + QMEMSIZE - CHUNK);
E 6
I 6
D 10
	    /*------------------------------------
	    * find an empty 64kb adrs boundary */
E 10
I 10
			qdbase[unit] = (caddr_t) (qvmem[0] + QMEMSIZE - CHUNK);
E 10
E 6

D 2
	    /*----------------------------------------------------
	    * find the cpusw entry that matches this machine. */

E 2
I 2
D 6
	    /*
	     * find the cpusw entry that matches this machine. 
	     */
E 6
I 6
D 10
	    qdbase[unit] = (caddr_t) (qvmem[0] + QMEMSIZE - CHUNK);
E 10
I 10
			/*
D 11
			* find the cpusw entry that matches this machine. */
E 10

E 11
I 11
			* find the cpusw entry that matches this machine. 
			*/
E 11
D 10
	    /*----------------------------------------------------
	    * find the cpusw entry that matches this machine. */
E 10
I 10
			cpup = &cpusw[cpu];
D 11
			while ( !(BADADDR(qdbase[unit], sizeof(short))) )
			    qdbase[unit] -= CHUNK;
E 11
I 11
			while (!(BADADDR(qdbase[unit], sizeof(short))))
				qdbase[unit] -= CHUNK;
E 11
E 10

E 6
E 2
D 10
	    cpup = &cpusw[cpu];
	    while ( !(BADADDR(qdbase[unit], sizeof(short))) )
		qdbase[unit] -= CHUNK;
E 10
I 10
			/*
D 11
			* tell QDSS which Q memory address base to decode */
E 10

E 11
I 11
			* tell QDSS which Q memory address base to decode 
			*/
E 11
D 2
	    /*---------------------------------------------------
	    * tell QDSS which Q memory address base to decode */

E 2
I 2
D 6
	    /*
	     * tell QDSS which Q memory address base to decode 
	     */
E 2
	    mapix = (int) (VTOP(qdbase[unit]) - VTOP(qmem[0]));
	    ptep = (int *) QMEMmap[0] + mapix;
E 6
I 6
D 10
	    /*---------------------------------------------------
	    * tell QDSS which Q memory address base to decode */
E 10
I 10
			mapix = (int) (VTOP(qdbase[unit]) - VTOP(qvmem[0]));
			ptep = (int *) QVmap[0] + mapix;
			phys_adr = (caddr_t)(((int)*ptep&0x001FFFFF)<<PGSHIFT);
			*(u_short *)reg = (u_short) ((int)phys_adr >> 16);
E 10

D 10
	    mapix = (int) (VTOP(qdbase[unit]) - VTOP(qvmem[0]));
	    ptep = (int *) QVmap[0] + mapix;
E 6
	    phys_adr = (caddr_t) (((int)*ptep & 0x001FFFFF) << PGSHIFT);
	    *(u_short *)reg = (u_short) ((int)phys_adr >> 16);
E 10
I 10
			/*
			* load QDSS adrs map with system addresses 
			* of device regs 
			*/
			qdmap[unit].template = qdbase[unit] + TMPSTART;
			qdmap[unit].adder = qdbase[unit] + ADDER;
			qdmap[unit].dga = qdbase[unit] + DGA;
			qdmap[unit].duart = qdbase[unit] + DUART;
			qdmap[unit].memcsr = qdbase[unit] + MEMCSR;
			qdmap[unit].red = qdbase[unit] + RED;
			qdmap[unit].blue = qdbase[unit] + BLUE;
			qdmap[unit].green = qdbase[unit] + GREEN;
E 10

D 2
	    /*-----------------------------------------------------------
	    * load QDSS adrs map with system addresses of device regs */

E 2
I 2
D 6
	    /*
	     * load QDSS adrs map with system addresses of device regs
	     */
E 6
I 6
D 10
	    /*-----------------------------------------------------------
	    * load QDSS adrs map with system addresses of device regs */
E 10
I 10
			/* device init */
E 10

E 6
E 2
D 10
	    qdmap[unit].template = qdbase[unit] + TMPSTART;
	    qdmap[unit].adder = qdbase[unit] + ADDER;
	    qdmap[unit].dga = qdbase[unit] + DGA;
	    qdmap[unit].duart = qdbase[unit] + DUART;
	    qdmap[unit].memcsr = qdbase[unit] + MEMCSR;
	    qdmap[unit].red = qdbase[unit] + RED;
	    qdmap[unit].blue = qdbase[unit] + BLUE;
	    qdmap[unit].green = qdbase[unit] + GREEN;
E 10
I 10
			cursor[unit].x = 0;
			cursor[unit].y = 0;
			init_shared(unit);		/* init shared memory */
			setup_dragon(unit); 	/* init the ADDER/VIPER stuff */
			ldcursor(unit, cons_cursor);	/* load default cursor map */
			setup_input(unit);		/* init the DUART */
			clear_qd_screen(unit);
			ldfont(unit);			/* load the console font */
E 10

D 10
	    /* device init */
E 10
I 10
			/* once only: turn on sync */
E 10

D 10
	    cursor[unit].x = 0;
	    cursor[unit].y = 0;
	    init_shared(unit);		/* init shared memory */
	    setup_dragon(unit); 	/* init the ADDER/VIPER stuff */
	    ldcursor(unit, cons_cursor);	/* load default cursor map */
	    setup_input(unit);		/* init the DUART */
	    clear_qd_screen(unit);
	    ldfont(unit);			/* load the console font */

	    /* once only: turn on sync */

	    *(short *)qdmap[unit].memcsr |= SYNC_ON;
E 10
I 10
			*(short *)qdmap[unit].memcsr |= SYNC_ON;
		}
E 10
I 6
#endif /*notdef*/
E 6
	}
I 2
D 3
#endif notdef
E 3
I 3
D 6
#endif /* notdef */
E 6
E 3
E 2

D 2
/*--------------------------------------------------------------------------
* the QDSS interrupts at HEX vectors xx0 (DMA) xx4 (ADDER) and xx8 (DUART).
* Therefore, we take three vectors from the vector pool, and then continue
* to take them until we get a xx0 HEX vector.  The pool provides vectors
* in contiguous decending order.  */
E 2
I 2
D 6
/*
 * the QDSS interrupts at HEX vectors xx0 (DMA) xx4 (ADDER) and xx8 (DUART).
 * Therefore, we take three vectors from the vector pool, and then continue
 * to take them until we get a xx0 HEX vector.  The pool provides vectors
 * in contiguous decending order.  
 */
E 6
I 6
D 10
/*--------------------------------------------------------------------------
* the QDSS interrupts at HEX vectors xx0 (DMA) xx4 (ADDER) and xx8 (DUART).
* Therefore, we take three vectors from the vector pool, and then continue
* to take them until we get a xx0 HEX vector.  The pool provides vectors
* in contiguous decending order.  */
E 10
I 10
	/*
	* The QDSS interrupts at HEX vectors xx0 (DMA) xx4
	* (ADDER) and xx8 (DUART).  Therefore, we take three
	* vectors from the vector pool, and then continue
	* to take them until we get a xx0 HEX vector.  The
	* pool provides vectors in contiguous decending
	* order.  
	*/
E 10
E 6
E 2

	vector = (uba_hd[0].uh_lastiv -= 4*3);	/* take three vectors */

D 10
	while (vector & 0x0F) { 		   /* if lo nibble != 0.. */
	    vector = (uba_hd[0].uh_lastiv -= 4);  /* ..take another vector */
E 10
I 10
	while (vector & 0x0F) {		   /* if lo nibble != 0.. */
		/* ..take another vector */
		vector = (uba_hd[0].uh_lastiv -= 4);  
E 10
	}

D 2
	/*---------------------------------------------------------
	* setup DGA to do a DMA interrupt (transfer count = 0)	*/
E 2
I 2
D 6
	/*
	 * setup DGA to do a DMA interrupt (transfer count = 0)
	 */
E 6
I 6
D 10
	/*---------------------------------------------------------
	* setup DGA to do a DMA interrupt (transfer count = 0)	*/
E 6
E 2

E 10
I 10
	/*
	* setup DGA to do a DMA interrupt (transfer count = 0)	
	*/
E 10
	dga = (struct dga *) qdmap[unit].dga;
D 10

	dga->csr = (short) HALT;	      /* disable everything */
	dga->ivr = (short) vector;	      /* load intrpt base vector */
	dga->bytcnt_lo = (short) 0;	      /* DMA xfer count = 0 */
E 10
I 10
	dga->csr = (short) HALT;	/* disable everything */
	dga->ivr = (short) vector;	/* load intrpt base vector */
	dga->bytcnt_lo = (short) 0;	/* DMA xfer count = 0 */
E 10
	dga->bytcnt_hi = (short) 0;

D 10
	/* turn on DMA interrupts */

E 10
I 10
	/* 
	* turn on DMA interrupts 
	*/
E 10
	dga->csr &= ~SET_DONE_FIFO;
	dga->csr |= DMA_IE | DL_ENB;

	DELAY(20000);			/* wait for the intrpt */
D 10

E 10
	dga->csr = HALT;		/* stop the wheels */

I 6
D 10
/*----------
* exits  */

E 10
E 6
D 2
/*----------
* exits  */

E 2
	if (cvec != vector)		/* if vector != base vector.. */
D 11
	    return(0);			/* ..return = 'no device' */
E 11
I 11
		return(0);		/* ..return = 'no device' */
E 11

I 6
	/*
D 10
	 * score this as an existing qdss
	 */
E 10
I 10
	* score this as an existing qdss
	*/
E 10
	qdcount++;
D 10
 	ws_display_units |= (1 << unit);
E 10

E 6
	return(sizeof(short));	    /* return size of QDSS I/O page reg */

} /* qdprobe */

D 11
/*****************************************************************
*
D 3
*	qdattach()... do the one-time initialization
E 3
I 3
D 6
*	qdattach - one-time initialization
E 6
I 6
*	qdattach()... do the one-time initialization
E 6
E 3
*
******************************************************************
*
*  calling convention:
*			qdattach(ui);
*			struct uba_device *ui;
*
*		where: ui - pointer to the QDSS's uba_device structure
*
*  side effects: none
*	 return: none
*
*************************/

E 11
qdattach(ui)
D 10
struct uba_device *ui;
E 10
I 10
	struct uba_device *ui;
E 10
{
D 11
	register u_int unit;		/* QDSS module # for this call */
E 11
I 11
	register unit;			/* QDSS module # for this call */
E 11

	unit = ui->ui_unit;		/* get QDSS number */

D 2
/*----------------------------------
* init "qdflags[]" for this QDSS */
E 2
I 2
D 3
/*
* init "qdflags[]" for this QDSS 
*/
E 3
I 3
D 6
	/*
	 * init "qdflags[]" for this QDSS 
	 */
E 6
I 6
D 10
/*----------------------------------
* init "qdflags[]" for this QDSS */
E 6
E 3
E 2

E 10
I 10
	/*
	* init "qdflags[]" for this QDSS 
	*/
E 10
	qdflags[unit].inuse = 0;	/* init inuse variable EARLY! */
	qdflags[unit].mapped = 0;
D 6
	qdflags[unit].kernel_loop = 0;
E 6
I 6
	qdflags[unit].kernel_loop = -1;
E 6
	qdflags[unit].user_dma = 0;
	qdflags[unit].curs_acc = ACC_OFF;
	qdflags[unit].curs_thr = 128;
	qdflags[unit].tab_res = 2;	/* default tablet resolution factor */
	qdflags[unit].duart_imask = 0;	/* init shadow variables */
	qdflags[unit].adder_ie = 0;

D 2
/*----------------------------------------------------------------------
E 2
I 2
D 3
/*
E 2
* init structures used in kbd/mouse interrupt service.	This code must
* come after the "init_shared()" routine has run since that routine inits
D 2
* the eq_header[unit] structure used here.   */
E 2
I 2
* the eq_header[unit] structure used here.   
*/
E 3
I 3
D 6
	/*
	* init structures used in kbd/mouse interrupt service.	This code must
	* come after the "init_shared()" routine has run since that routine 
	* inits the eq_header[unit] structure used here.   
	*/
E 6
I 6
D 10
/*----------------------------------------------------------------------
* init structures used in kbd/mouse interrupt service.	This code must
* come after the "init_shared()" routine has run since that routine inits
* the eq_header[unit] structure used here.   */
E 10
I 10
	/*
	* init structures used in kbd/mouse interrupt service.	This code must
	* come after the "init_shared()" routine has run since that routine 
	* inits the eq_header[unit] structure used here.   
	*/
E 10
E 6
E 3
E 2

D 2
	/*--------------------------------------------
	* init the "latest mouse report" structure */
E 2
I 2
D 6
	/*
	* init the "latest mouse report" structure 
	*/
E 6
I 6
D 10
	/*--------------------------------------------
	* init the "latest mouse report" structure */
E 6
E 2

E 10
I 10
	/*
	* init the "latest mouse report" structure 
	*/
E 10
	last_rep[unit].state = 0;
	last_rep[unit].dx = 0;
	last_rep[unit].dy = 0;
	last_rep[unit].bytcnt = 0;

D 3
	/*------------------------------------------------
	* init the event queue (except mouse position) */
E 3
I 3
D 6
	/*
	* init the event queue (except mouse position)
	*/
E 6
I 6
D 10
	/*------------------------------------------------
E 10
I 10
	/*
E 10
D 11
	* init the event queue (except mouse position) */
E 11
I 11
	* init the event queue (except mouse position) 
	*/
	eq_header[unit]->header.events = 
	    (struct _vs_event *)((int)eq_header[unit] + sizeof(struct qdinput));
E 11
E 6
E 3

D 11
	eq_header[unit]->header.events = (struct _vs_event *)
D 10
					  ((int)eq_header[unit]
					   + sizeof(struct qdinput));
E 10
I 10
	    ((int)eq_header[unit]
	    + sizeof(struct qdinput));
E 10

E 11
	eq_header[unit]->header.size = MAXEVENTS;
	eq_header[unit]->header.head = 0;
	eq_header[unit]->header.tail = 0;

D 2
/*------------------------------------------
* init single process access lock switch */
E 2
I 2
D 6
	/*
	* init single process access lock switch 
	*/
E 6
I 6
D 10
/*------------------------------------------
* init single process access lock switch */
E 10
I 10
	/*
	 * open exclusive for graphics device.
	 */
	qdopened[unit] = 0;
E 10
E 6
E 2

D 10
	one_only[unit] = 0;

E 10
} /* qdattach */

D 11
/***************************************************************
*
D 3
*	qdopen()... open a minor device
E 3
I 3
D 6
*	qdopen - open a minor device
E 6
I 6
*	qdopen()... open a minor device
E 6
E 3
*
****************************************************************
*
*  calling convention: qdopen(dev, flag);
*		       dev_t dev;
*		       int flag;
*
*  side effects: none
*
*********************/

E 11
I 11
/*ARGSUSED*/
E 11
qdopen(dev, flag)
D 10
dev_t dev;
int flag;
E 10
I 10
	dev_t dev;
	int flag;
E 10
{
	register struct uba_device *ui; /* ptr to uba structures */
	register struct dga *dga;	/* ptr to gate array struct */
	register struct tty *tp;
I 2
D 6
	int qdstart();
E 6
E 2
D 10

E 10
D 11
	struct adder *adder;
E 11
	struct duart *duart;
D 10

E 10
D 11
	u_int unit;
	u_int minor_dev;
	int s;
E 11
I 11
	int unit;
	int minor_dev;
E 11

	minor_dev = minor(dev); /* get QDSS minor device number */
	unit = minor_dev >> 2;

D 2
/*---------------------------------
* check for illegal conditions	*/
E 2
I 2
D 6
	/* check for illegal conditions	*/
E 6
I 6
D 10
/*---------------------------------
* check for illegal conditions	*/
E 6
E 2

E 10
I 10
	/*
	* check for illegal conditions	
	*/
E 10
	ui = qdinfo[unit];		/* get ptr to QDSS device struct */
D 10

E 10
	if (ui == 0  || ui->ui_alive == 0)
D 10
	    return(ENXIO);		/* no such device or address */
E 10
I 10
		return(ENXIO);		/* no such device or address */
E 10

D 2
/*--------------
* init stuff */
E 2
I 2
D 6
	/* init stuff */
E 6
I 6
D 10
/*--------------
* init stuff */
E 6
E 2

E 10
D 11
	adder = (struct adder *) qdmap[unit].adder;
E 11
	duart = (struct duart *) qdmap[unit].duart;
	dga = (struct dga *) qdmap[unit].dga;

D 2
/*------------------------------------
* if this is the graphic device... */
E 2
I 2
D 6
	/* if this is the graphic device... */
E 6
I 6
D 10
/*------------------------------------
* if this is the graphic device... */
E 6
E 2

E 10
	if ((minor_dev & 0x03) == 2) {
D 10

	    if (one_only[unit] != 0)
		return(EBUSY);
	    else
		one_only[unit] = 1;

	    qdflags[unit].inuse |= GRAPHIC_DEV;  /* graphics dev is open */

	    /* enble kbd & mouse intrpts in DUART mask reg */

	    qdflags[unit].duart_imask |= 0x22;
	    duart->imask = qdflags[unit].duart_imask;

D 2
/*------------------------------------------------------------------
* if the open call is to the console or the alternate console... */
E 2
I 2
D 6
	/*
	 * if the open call is to the console or the alternate console... 
	 */
	} else { 
E 6
I 6
/*------------------------------------------------------------------
* if the open call is to the console or the alternate console... */
E 6
E 2

I 6
	} else if ((minor_dev & 0x03) != 2) {

E 6
D 2
	} else if ((minor_dev & 0x03) != 2) {

E 2
	    qdflags[unit].inuse |= CONS_DEV;  /* mark console as open */
	    dga->csr |= CURS_ENB;

	    qdflags[unit].duart_imask |= 0x02;
	    duart->imask = qdflags[unit].duart_imask;

	    /*-------------------------------
	    * some setup for tty handling */

	    tp = &qd_tty[minor_dev];

	    tp->t_addr = ui->ui_addr;
	    tp->t_oproc = qdstart;
I 6
#ifdef notdef	/* never */
	/*---------------------------------------------------------------------
	* Look at the compatibility mode to specify correct default parameters
	* and to insure only standard specified functionality. */
	if ((u.u_procp->p_progenv == A_SYSV) || 
		(u.u_procp->p_progenv == A_POSIX)) {
		flag |= O_TERMIO;
		tp->t_line = TERMIODISC;
	}
#endif /*notdef*/
E 6

	    if ((tp->t_state & TS_ISOPEN) == 0) {

		ttychars(tp);
D 6
		tp->t_state = TS_ISOPEN | TS_CARR_ON;
E 6
I 6
		tp->t_flags = IFLAGS;
E 6
		tp->t_ispeed = B9600;
		tp->t_ospeed = B9600;
I 6
		tp->t_state = TS_ISOPEN | TS_CARR_ON;
E 6

D 2
		if( (minor_dev & 0x03) == 0 )
E 2
I 2
D 6
		if( (minor_dev & 0x03) == 0 ) {	
E 2
		    tp->t_flags = XTABS|EVENP|ECHO|CRMOD;
I 3
#ifdef POSIXTTY
		    tp->t_iflag = TTYDEF_IFLAG;
		    tp->t_oflag = TTYDEF_OFLAG;
		    tp->t_lflag = TTYDEF_LFLAG;
		    tp->t_cflag = TTYDEF_CFLAG;
#endif
E 6
I 6
#ifdef notdef	/* never */
		tp->t_cflag = tp->t_cflag_ext = B9600;
		tp->t_iflag_ext = 0;
		tp->t_oflag_ext = 0;
		tp->t_lflag_ext = 0;

		if( (minor_dev & 0x03) == 0 ) {
			/*----------------------------------------------------
			* Ultrix defaults to a "COOKED" mode on the first
			* open, while termio defaults to a "RAW" style.
			* Base this decision by a flag set in the termio
			* emulation routine for open, or set by an explicit
			* ioctl call. */
			
			if ( flag & O_TERMIO ) {
				/*--------------------------------------
				* Provide a termio style environment.
				* "RAW" style by default. */
				
				tp->t_flags = RAW;   
				tp->t_iflag = 0;
				tp->t_oflag = 0;
				tp->t_cflag |= CS8|CREAD|HUPCL; 
				tp->t_lflag = 0;
	
				/*-------------------------------------
				 * Change to System V line discipline.*/
				 
				tp->t_line = TERMIODISC;
				/*-----------------------------------------
				* The following three control chars have 
				* different default values than ULTRIX.	*/
				
	 			tp->t_cc[VERASE] = '#';
	 			tp->t_cc[VKILL] = '@';
	 			tp->t_cc[VINTR] = 0177;
 				tp->t_cc[VMIN] = 6;
 				tp->t_cc[VTIME] = 1;
			} else {
				/*--------------------------------------
				* Provide a backward compatible ULTRIX 
				* environment.  "COOKED" style.	*/
				
				tp->t_flags = IFLAGS;
				tp->t_iflag = IFLAG;
				tp->t_oflag = OFLAG;
				tp->t_lflag = LFLAG;
				tp->t_cflag |= CFLAG;
			}
E 10
I 10
		/*
		* this is the graphic device... 
		*/
		if (qdopened[unit] != 0)
D 11
		    return(EBUSY);
E 11
I 11
			return(EBUSY);
E 11
		else
			qdopened[unit] = 1;
		qdflags[unit].inuse |= GRAPHIC_DEV;  /* graphics dev is open */
		/*
		 * enble kbd & mouse intrpts in DUART mask reg 
		 */
		qdflags[unit].duart_imask |= 0x22;
		duart->imask = qdflags[unit].duart_imask;
	} else {
		/*
		* this is the console 
		*/
		qdflags[unit].inuse |= CONS_DEV;  /* mark console as open */
		dga->csr |= CURS_ENB;
		qdflags[unit].duart_imask |= 0x02;
		duart->imask = qdflags[unit].duart_imask;
		/*
		* some setup for tty handling 
		*/
		tp = &qd_tty[minor_dev];
		tp->t_addr = ui->ui_addr;
		tp->t_oproc = qdstart;
		if ((tp->t_state & TS_ISOPEN) == 0) {
			ttychars(tp);
			tp->t_flags = IFLAGS;
			tp->t_ispeed = B9600;
			tp->t_ospeed = B9600;
			tp->t_state = TS_ISOPEN | TS_CARR_ON;
#ifdef POSIXTTY
			tp->t_iflag = TTYDEF_IFLAG;
			tp->t_oflag = TTYDEF_OFLAG;
			tp->t_lflag = TTYDEF_LFLAG;
			tp->t_cflag = TTYDEF_CFLAG;
#endif
E 10
E 6
E 3
D 2
		else
E 2
I 2
		}
D 10
		else {
E 2
		    tp->t_flags = RAW;
I 6
		    tp->t_iflag = 0;
		    tp->t_oflag = 0;
		    tp->t_cflag |= CS8|CREAD|HUPCL; 
		    tp->t_lflag = 0;
E 6
I 2
		}
I 6
                if( (minor_dev & 0x03) == 1 )
                    tp->t_iflag |= IXOFF;	/* flow control for qconsole */
#endif /*notdef*/
E 6
E 2
	    }

	    /*----------------------------------------
	    * enable intrpts, open line discipline */

	    dga->csr |= GLOBAL_IE;	/* turn on the interrupts */
	    return ((*linesw[tp->t_line].l_open)(dev, tp));
E 10
I 10
		/*
		* enable intrpts, open line discipline 
		*/
		dga->csr |= GLOBAL_IE;	/* turn on the interrupts */
		return ((*linesw[tp->t_line].l_open)(dev, tp));
E 10
	}
D 10

E 10
	dga->csr |= GLOBAL_IE;	/* turn on the interrupts */
	return(0);

} /* qdopen */

D 11
/***************************************************************
*
D 3
*	qdclose()... clean up on the way out
E 3
I 3
D 6
*	qdclose - clean up on the way out
E 6
I 6
*	qdclose()... clean up on the way out
E 6
E 3
*
****************************************************************
*
*  calling convention: qdclose();
*
*  side effects: none
*
*  return: none
*
*********************/

E 11
I 11
/*ARGSUSED*/
E 11
qdclose(dev, flag)
D 10
dev_t dev;
int flag;
E 10
I 10
	dev_t dev;
	int flag;
E 10
{
	register struct tty *tp;
	register struct qdmap *qd;
	register int *ptep;
D 10
	int i;				/* SIGNED index */

E 10
	struct dga *dga;		/* gate array register map pointer */
	struct duart *duart;
	struct adder *adder;
D 10

E 10
D 11
	u_int unit;
	u_int minor_dev;
E 11
I 11
	int unit;
	int minor_dev;
E 11
	u_int mapix;
I 10
	int i;				/* SIGNED index */
E 10

	minor_dev = minor(dev); 	/* get minor device number */
	unit = minor_dev >> 2;		/* get QDSS number */
	qd = &qdmap[unit];

D 2
/*------------------------------------
* if this is the graphic device... */
E 2
I 2
D 6
	/*
	 * if this is the graphic device... 
	 */
E 6
I 6
D 10
/*------------------------------------
* if this is the graphic device... */
E 6
E 2

E 10
	if ((minor_dev & 0x03) == 2) {
D 3

	    /*-----------------
	    * unlock driver */

	    if (one_only[unit] != 1)
E 3
I 3
D 6
	    if (one_only[unit] != 1)	/* unlock driver */
E 6
I 6
D 10

	    /*-----------------
	    * unlock driver */

	    if (one_only[unit] != 1)
E 6
E 3
		return(EBUSY);
	    else
		one_only[unit] = 0;

D 3
	    /*----------------------------
	    * re-protect device memory */
E 3
I 3
D 6
	    /*
	    * re-protect device memory 
	    */
E 6
I 6
	    /*----------------------------
	    * re-protect device memory */
E 6
E 3

	    if (qdflags[unit].mapped & MAPDEV) {

D 3
		/*----------------
		* TEMPLATE RAM */
E 3
I 3
D 6
		/* TEMPLATE RAM */
E 6
I 6
		/*----------------
		* TEMPLATE RAM */
E 10
I 10
		/*
		* this is the graphic device... 
		*/
		if (qdopened[unit] != 1)
D 11
		    return(EBUSY);
E 11
I 11
		    	return(EBUSY);
E 11
		else
			qdopened[unit] = 0;	/* allow it to be re-opened */
		/*
		* re-protect device memory 
		*/
		if (qdflags[unit].mapped & MAPDEV) {
			/*
			* TEMPLATE RAM 
			*/
			mapix = VTOP((int)qd->template) - VTOP(qvmem[0]);
			ptep = (int *)(QVmap[0] + mapix);
D 11
			for (i = VTOP(TMPSIZE); i > 0; --i)
				*ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
I 11
			for (i = 0; i < btop(TMPSIZE); i++, ptep++)
				*ptep = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
			/*
			* ADDER 
			*/
			mapix = VTOP((int)qd->adder) - VTOP(qvmem[0]);
			ptep = (int *)(QVmap[0] + mapix);
D 11
			for (i = VTOP(REGSIZE); i > 0; --i)
				*ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
I 11
			for (i = 0; i < btop(REGSIZE); i++, ptep++)
				*ptep = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
			/*
			* COLOR MAPS 
			*/
			mapix = VTOP((int)qd->red) - VTOP(qvmem[0]);
			ptep = (int *)(QVmap[0] + mapix);
D 11
			for (i = VTOP(CLRSIZE); i > 0; --i)
				*ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
I 11
			for (i = 0; i < btop(CLRSIZE); i++, ptep++)
				*ptep = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
		}
E 10
E 6
E 3

D 2
		mapix = VTOP((int)qd->template) - VTOP(qmem[0]);
		ptep = (int *)(QMEMmap[0] + mapix);
E 2
I 2
D 10
		mapix = VTOP((int)qd->template) - VTOP(qvmem[0]);
		ptep = (int *)(QVmap[0] + mapix);
E 2

		for (i = VTOP(TMPSIZE); i > 0; --i)
		    *ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;

D 3
		/*---------
		* ADDER */
E 3
I 3
D 6
		/* ADDER */
E 6
I 6
		/*---------
		* ADDER */
E 6
E 3

D 2
		mapix = VTOP((int)qd->adder) - VTOP(qmem[0]);
		ptep = (int *)(QMEMmap[0] + mapix);
E 2
I 2
		mapix = VTOP((int)qd->adder) - VTOP(qvmem[0]);
		ptep = (int *)(QVmap[0] + mapix);
E 2

		for (i = VTOP(REGSIZE); i > 0; --i)
		    *ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;

D 3
		/*--------------
		* COLOR MAPS */
E 3
I 3
D 6
		/* COLOR MAPS */
E 6
I 6
		/*--------------
		* COLOR MAPS */
E 6
E 3

D 2
		mapix = VTOP((int)qd->red) - VTOP(qmem[0]);
		ptep = (int *)(QMEMmap[0] + mapix);
E 2
I 2
		mapix = VTOP((int)qd->red) - VTOP(qvmem[0]);
		ptep = (int *)(QVmap[0] + mapix);
E 2

		for (i = VTOP(CLRSIZE); i > 0; --i)
		    *ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;
	    }

D 3
	    /*----------------------------------------------------
	    * re-protect DMA buffer and free the map registers */
E 3
I 3
D 6
	    /* 
	     * re-protect DMA buffer and free the map registers 
	     */
E 6
I 6
	    /*----------------------------------------------------
	    * re-protect DMA buffer and free the map registers */
E 6
E 3

	    if (qdflags[unit].mapped & MAPDMA) {

		dga = (struct dga *) qdmap[unit].dga;
		adder = (struct adder *) qdmap[unit].adder;

		dga->csr &= ~DMA_IE;
		dga->csr &= ~0x0600;	     /* kill DMA */
		adder->command = CANCEL;

		/* if DMA was running, flush spurious intrpt */

		if (dga->bytcnt_lo != 0) {
		    dga->bytcnt_lo = 0;
		    dga->bytcnt_hi = 0;
		    DMA_SETIGNORE(DMAheader[unit]);
		    dga->csr |= DMA_IE;
		    dga->csr &= ~DMA_IE;
E 10
I 10
		/*
		* re-protect DMA buffer and free the map registers 
		*/
		if (qdflags[unit].mapped & MAPDMA) {
			dga = (struct dga *) qdmap[unit].dga;
			adder = (struct adder *) qdmap[unit].adder;
			dga->csr &= ~DMA_IE;
			dga->csr &= ~0x0600;	     /* kill DMA */
			adder->command = CANCEL;
			/* 
			 * if DMA was running, flush spurious intrpt 
			 */
			if (dga->bytcnt_lo != 0) {
				dga->bytcnt_lo = 0;
				dga->bytcnt_hi = 0;
				DMA_SETIGNORE(DMAheader[unit]);
				dga->csr |= DMA_IE;
				dga->csr &= ~DMA_IE;
			}
			ptep = (int *)
			   ((VTOP(DMAheader[unit]*4)) + (mfpr(SBR)|0x80000000));
D 11
			for (i = (DMAbuf_size >> PGSHIFT); i > 0; --i)
				*ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
I 11
			for (i = 0; i < btop(DMAbuf_size); i++, ptep++)
				*ptep = (*ptep & ~PG_PROT) | PG_V | PG_KW;
E 11
			ubarelse(0, &Qbus_unmap[unit]);
E 10
		}

D 10
		ptep = (int *)
			((VTOP(DMAheader[unit]*4)) + (mfpr(SBR)|0x80000000));
E 10
I 10
		/*
		* re-protect 1K (2 pages) event queue 
		*/
		if (qdflags[unit].mapped & MAPEQ) {
			ptep = (int *)
			   ((VTOP(eq_header[unit])*4) + (mfpr(SBR)|0x80000000));
E 10
D 11

D 10
		for (i = (DMAbuf_size >> PGSHIFT); i > 0; --i)
		    *ptep++ = (*ptep & ~PG_PROT) | PG_V | PG_KW;

		ubarelse(0, &Qbus_unmap[unit]);
	    }

D 3
	    /*---------------------------------------
	    * re-protect 1K (2 pages) event queue */
E 3
I 3
D 6
	    /*
	     * re-protect 1K (2 pages) event queue 
	     */
E 6
I 6
	    /*---------------------------------------
	    * re-protect 1K (2 pages) event queue */
E 6
E 3

	    if (qdflags[unit].mapped & MAPEQ) {

		ptep = (int *)
			((VTOP(eq_header[unit])*4) + (mfpr(SBR)|0x80000000));

		*ptep++ = (*ptep & ~PG_PROT) | PG_KW | PG_V;
		*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;
	    }

D 3
	    /*------------------------------------------------------------
	    * re-protect scroll param area and disable scroll intrpts  */
E 3
I 3
D 6
	    /*
	     * re-protect scroll param area and disable scroll intrpts  
	     */
E 6
I 6
	    /*------------------------------------------------------------
	    * re-protect scroll param area and disable scroll intrpts  */
E 6
E 3

	    if (qdflags[unit].mapped & MAPSCR) {

		ptep = (int *) ((VTOP(scroll[unit]) * 4)
				    + (mfpr(SBR) | 0x80000000));

		/* re-protect 512 scroll param area */

		*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;

		adder = (struct adder *) qdmap[unit].adder;
		qdflags[unit].adder_ie &= ~FRAME_SYNC;
		adder->interrupt_enable = qdflags[unit].adder_ie;
	    }

D 3
	    /*-----------------------------------------------------------
	    * re-protect color map write buffer area and kill intrpts */
E 3
I 3
D 6
	    /*
	     * re-protect color map write buffer area and kill intrpts 
	     */
E 6
I 6
	    /*-----------------------------------------------------------
	    * re-protect color map write buffer area and kill intrpts */
E 6
E 3

	    if (qdflags[unit].mapped & MAPCOLOR) {

		ptep = (int *) ((VTOP(color_buf[unit]) * 4)
				    + (mfpr(SBR) | 0x80000000));

		*ptep++ = (*ptep & ~PG_PROT) | PG_KW | PG_V;
		*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;

		color_buf[unit]->status = 0;

		adder = (struct adder *) qdmap[unit].adder;
		qdflags[unit].adder_ie &= ~VSYNC;
		adder->interrupt_enable = qdflags[unit].adder_ie;
	    }

D 3
	    /*-----------------------------------
	    * flag that everthing is unmapped */
E 3
I 3
D 6
	    /*
	     * flag that everthing is unmapped 
	     */
E 6
I 6
	    /*-----------------------------------
	    * flag that everthing is unmapped */
E 6
E 3

D 3
	    mtpr(TBIA, 0);		/* smash CPU's translation buf */
	    qdflags[unit].mapped = 0;	/* flag everything now unmapped */
E 3
I 3
D 6
	    mtpr(TBIA, 0);		/* invalidate translation buf */
	    qdflags[unit].mapped = 0;	/* flag everything unmapped */
E 6
I 6
	    mtpr(TBIA, 0);		/* smash CPU's translation buf */
	    qdflags[unit].mapped = 0;	/* flag everything now unmapped */
E 6
E 3
	    qdflags[unit].inuse &= ~GRAPHIC_DEV;
	    qdflags[unit].curs_acc = ACC_OFF;
	    qdflags[unit].curs_thr = 128;

D 3
	    /*---------------------
	    * restore the console */
E 3
I 3
D 6
	    /*
	     * restore the console 
	     */
E 6
I 6
	    /*---------------------
	    * restore the console */
E 6
E 3

E 10
I 10
			*ptep++ = (*ptep & ~PG_PROT) | PG_KW | PG_V;
E 11
I 11
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V; ptep++;
E 11
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;
		}
		/*
		* re-protect scroll param area and disable scroll intrpts  
		*/
		if (qdflags[unit].mapped & MAPSCR) {
			ptep = (int *) ((VTOP(scroll[unit]) * 4)
				+ (mfpr(SBR) | 0x80000000));
			/*
			 * re-protect 512 scroll param area 
			 */
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;
			adder = (struct adder *) qdmap[unit].adder;
			qdflags[unit].adder_ie &= ~FRAME_SYNC;
			adder->interrupt_enable = qdflags[unit].adder_ie;
		}
		/*
		* re-protect color map write buffer area and kill intrpts 
		*/
		if (qdflags[unit].mapped & MAPCOLOR) {
			ptep = (int *) ((VTOP(color_buf[unit]) * 4)
				+ (mfpr(SBR) | 0x80000000));
D 11
			*ptep++ = (*ptep & ~PG_PROT) | PG_KW | PG_V;
E 11
I 11
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V; ptep++;
E 11
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;
			color_buf[unit]->status = 0;
			adder = (struct adder *) qdmap[unit].adder;
			qdflags[unit].adder_ie &= ~VSYNC;
			adder->interrupt_enable = qdflags[unit].adder_ie;
		}
		mtpr(TBIA, 0);		
		/* flag everything now unmapped */
		qdflags[unit].mapped = 0;   
		qdflags[unit].inuse &= ~GRAPHIC_DEV;
		qdflags[unit].curs_acc = ACC_OFF;
		qdflags[unit].curs_thr = 128;
		/*
		* restore the console 
		*/
E 10
		dga = (struct dga *) qdmap[unit].dga;
		adder = (struct adder *) qdmap[unit].adder;
D 10

E 10
		dga->csr &= ~DMA_IE;
		dga->csr &= ~0x0600;	/* halt the DMA! (just in case...) */
		dga->csr |= DMA_ERR;	/* clear error condition */
		adder->command = CANCEL;
D 10

		/* if DMA was running, flush spurious intrpt */

E 10
I 10
		/*
		 * if DMA was running, flush spurious intrpt 
		 */
E 10
		if (dga->bytcnt_lo != 0) {
D 10
		    dga->bytcnt_lo = 0;
		    dga->bytcnt_hi = 0;
		    DMA_SETIGNORE(DMAheader[unit]);
		    dga->csr |= DMA_IE;
		    dga->csr &= ~DMA_IE;
E 10
I 10
			dga->bytcnt_lo = 0;
			dga->bytcnt_hi = 0;
			DMA_SETIGNORE(DMAheader[unit]);
			dga->csr |= DMA_IE;
			dga->csr &= ~DMA_IE;
E 10
		}
D 10

E 10
		init_shared(unit);		/* init shared memory */
		setup_dragon(unit);		/* init ADDER/VIPER */
		ldcursor(unit, cons_cursor);	/* load default cursor map */
		setup_input(unit);		/* init the DUART */
		ldfont(unit);
		cursor[unit].x = 0;
		cursor[unit].y = 0;
D 10

D 3
	    /* shut off the mouse rcv intrpt and turn on kbd intrpts */

E 3
I 3
D 6
	    /* 
	     * shut off the mouse rcv intrpt and turn on kbd intrpts 
	     */
E 6
I 6
	    /* shut off the mouse rcv intrpt and turn on kbd intrpts */

E 6
E 3
	    duart = (struct duart *) qdmap[unit].duart;
	    qdflags[unit].duart_imask &= ~(0x20);
	    qdflags[unit].duart_imask |= 0x02;
	    duart->imask = qdflags[unit].duart_imask;
D 3

	    /*-----------------------------------------
	    * shut off interrupts if all is closed  */

E 3
I 3
D 6
	    /*
	     * shut off interrupts if all is closed  
	     */
E 6
I 6

	    /*-----------------------------------------
	    * shut off interrupts if all is closed  */

E 6
E 3
	    if (!(qdflags[unit].inuse & (CONS_DEV | ALTCONS_DEV))) {
I 6

E 6
D 3

E 3
		dga = (struct dga *) qdmap[unit].dga;
		dga->csr &= ~(GLOBAL_IE | DMA_IE);
	    }
E 10
I 10
		/*
		 * shut off the mouse rcv intrpt and turn on kbd intrpts 
		 */
		duart = (struct duart *) qdmap[unit].duart;
		qdflags[unit].duart_imask &= ~(0x20);
		qdflags[unit].duart_imask |= 0x02;
		duart->imask = qdflags[unit].duart_imask;
		/*
		* shut off interrupts if all is closed  
		*/
		if (!(qdflags[unit].inuse & CONS_DEV)) {
			dga = (struct dga *) qdmap[unit].dga;
			dga->csr &= ~(GLOBAL_IE | DMA_IE);
		}
	} else {
		/*
		* this is the console 
		*/
		tp = &qd_tty[minor_dev];
		(*linesw[tp->t_line].l_close)(tp);
		ttyclose(tp);
		tp->t_state = 0;
		qdflags[unit].inuse &= ~CONS_DEV;
		/*
		* if graphics device is closed, kill interrupts 
		*/
		if (!(qdflags[unit].inuse & GRAPHIC_DEV)) {
			dga = (struct dga *) qdmap[unit].dga;
			dga->csr &= ~(GLOBAL_IE | DMA_IE);
		}
E 10
	}
D 2

/*----------------------------------------------------
* if this is the console or the alternate console  */

E 2
D 3
	else {
I 2
	    /* if this is the console or the alternate console  */
E 2

E 3
I 3
D 6
	else { /* if this is the console or the alternate console  */
E 6
I 6

D 10
/*----------------------------------------------------
* if this is the console or the alternate console  */

	else {

E 6
E 3
	    tp = &qd_tty[minor_dev];

	    (*linesw[tp->t_line].l_close)(tp);
	    ttyclose(tp);
I 6

E 6
D 3

E 3
	    tp->t_state = 0;
I 6
	    /* Remove termio flags that do not map */
#ifdef notdef	/* never */
	    tp->t_iflag &= ~TERMIO_ONLY_IFLAG;
	    tp->t_oflag &= ~TERMIO_ONLY_OFLAG;
	    tp->t_cflag &= ~TERMIO_ONLY_CFLAG;
	    tp->t_lflag &= ~TERMIO_ONLY_LFLAG;
#endif /*notdef*/

E 6
D 3

E 3
	    qdflags[unit].inuse &= ~CONS_DEV;
D 3

	    /*-------------------------------------------------
	    * if graphics device is closed, kill interrupts */

E 3
I 3
D 6
	    /*
	     * if graphics device is closed, kill interrupts 
	     */
E 6
I 6

	    /*-------------------------------------------------
	    * if graphics device is closed, kill interrupts */

E 6
E 3
	    if (!(qdflags[unit].inuse & GRAPHIC_DEV)) {
		dga = (struct dga *) qdmap[unit].dga;
		dga->csr &= ~(GLOBAL_IE | DMA_IE);
	    }
	}

I 6
/*--------
* exit */

E 10
E 6
D 2
/*--------
* exit */

E 2
	return(0);

} /* qdclose */

D 11
/***************************************************************
*
D 3
*	qdioctl()... provide QDSS control services
E 3
I 3
D 6
*	qdioctl - provide QDSS control services
E 6
I 6
*	qdioctl()... provide QDSS control services
E 6
E 3
*
****************************************************************
*
*  calling convention:	qdioctl(dev, cmd, datap, flags);
*
*		where:	dev - the major/minor device number
*			cmd - the user-passed command argument
*			datap - ptr to user input buff (128 bytes max)
*			flags - "f_flags" from "struct file" in file.h
*
*
*	- here is the format for the input "cmd" argument
*
*	31     29 28	23 22	      16 15		8 7		 0
*	+----------------------------------------------------------------+
*	|I/O type|	  | buff length | device ID char |  user command |
*	+----------------------------------------------------------------+
*
*  Return data is in the data buffer pointed to by "datap" input spec
*
*********************/

E 11
qdioctl(dev, cmd, datap, flags)
D 10
dev_t dev;
int cmd;
caddr_t datap;
int flags;
E 10
I 10
	dev_t dev;
	int cmd;
D 11
	caddr_t datap;
E 11
I 11
	register caddr_t datap;
E 11
	int flags;
E 10
{
	register int *ptep;		/* page table entry pointer */
D 2
	register int mapix;		/* QMEMmap[] page table index */
E 2
I 2
	register int mapix;		/* QVmap[] page table index */
E 2
	register struct _vs_event *event;
	register struct tty *tp;
I 11
	register i;
E 11
I 6
D 10

E 10
E 6
D 5

E 5
	struct qdmap *qd;		/* pointer to device map struct */
	struct dga *dga;		/* Gate Array reg structure pntr */
	struct duart *duart;		/* DUART reg structure pointer */
	struct adder *adder;		/* ADDER reg structure pointer */
I 6
D 10

E 10
E 6
D 5

E 5
	struct prgkbd *cmdbuf;
	struct prg_cursor *curs;
	struct _vs_cursor *pos;
I 6
D 10

E 10
E 6
D 5

E 5
D 11
	u_int unit = minor(dev) >> 2;	/* number of caller's QDSS */
E 11
I 11
	int unit = minor(dev) >> 2;	/* number of caller's QDSS */
E 11
	u_int minor_dev = minor(dev);
D 11
	struct uba_device *ui = qdinfo[unit];
	struct qd_softc *sc = &qd_softc[ui->ui_unit];
E 11
D 2
	struct devget *devget;
E 2
I 2
D 6
	/* struct devget *devget; */
E 6
I 6
D 10
#ifdef notdef
	struct devget *devget;
#endif

E 10
E 6
E 2
D 5

E 5
	int error;
	int s;
I 6
D 10

E 10
E 6
D 5

E 5
D 11
	int i;				/* SIGNED index */
	int sbr;			/* SBR variable (you silly boy) */
	u_int ix;
I 6
D 10

E 10
E 6
D 5

E 5
	short status;
	short *shortp;			/* generic pointer to a short */
	char *chrp;			/* generic character pointer */
E 11
I 6
D 10

E 10
E 6
D 5

E 5
	short *temp;			/* a pointer to template RAM */

D 2
/*-----------------------------------------
* service graphic device ioctl commands */

E 2
I 2
D 6
	/* service graphic device ioctl commands */
E 6
I 6
D 10
/*-----------------------------------------
* service graphic device ioctl commands */

E 10
I 10
	/*
	* service graphic device ioctl commands 
	*/
E 10
E 6
E 2
	switch (cmd) {
D 3

	    /*-------------------------------------------------
	    * extract the oldest event from the event queue */

E 3
I 3
D 6
	    /*
	     * extract the oldest event from the event queue 
	     */
E 6
I 6

D 10
	    /*-------------------------------------------------
	    * extract the oldest event from the event queue */

E 6
E 3
	    case QD_GETEVENT:
I 6

E 10
I 10
	case QD_GETEVENT:
		/*
		* extract the oldest event from the event queue 
		*/
E 10
E 6
D 3

E 3
		if (ISEMPTY(eq_header[unit])) {
D 10
		    event = (struct _vs_event *) datap;
		    event->vse_device = VSE_NULL;
		    break;
E 10
I 10
			event = (struct _vs_event *) datap;
			event->vse_device = VSE_NULL;
			break;
E 10
		}
I 6
D 10

E 10
E 6
D 3

E 3
		event = (struct _vs_event *) GETBEGIN(eq_header[unit]);
D 2
		s = spl5();
E 2
I 2
D 6
		s = spltty();
E 6
I 6
		s = spl5();
E 6
E 2
		GETEND(eq_header[unit]);
		splx(s);
D 11
		bcopy(event, datap, sizeof(struct _vs_event));
E 11
I 11
		bcopy((caddr_t)event, datap, sizeof(struct _vs_event));
E 11
		break;

D 10
	    /*-------------------------------------------------------
	    * init the dragon stuff, DUART, and driver variables  */

	    case QD_RESET:

E 10
I 10
	case QD_RESET:
		/*
		* init the dragon stuff, DUART, and driver variables  
		*/
E 10
		init_shared(unit);		/* init shared memory */
		setup_dragon(unit);	      /* init the ADDER/VIPER stuff */
		clear_qd_screen(unit);
		ldcursor(unit, cons_cursor);	/* load default cursor map */
		ldfont(unit);			/* load the console font */
		setup_input(unit);		/* init the DUART */
		break;

D 10
	    /*----------------------------------------
	    * init the DUART and driver variables  */

	    case QD_SET:

E 10
I 10
	case QD_SET:
		/*
		* init the DUART and driver variables  
		*/
E 10
		init_shared(unit);
		setup_input(unit);
		break;

D 10
	    /*---------------------------------------------------------------
	    * clear the QDSS screen.  (NOTE that this reinits the dragon) */

	    case QD_CLRSCRN:

E 10
I 10
	case QD_CLRSCRN:
		/*
		* clear the QDSS screen.  (NOTE that this reinits the dragon) 
		*/
E 10
I 6
D 11
#ifdef notdef	/* has caused problems and is not necessary */
E 11
I 11
#ifdef notdef	/* has caused problems and isn't necessary */
E 11
E 6
		setup_dragon(unit);
		clear_qd_screen(unit);
I 6
#endif
E 6
		break;

D 10
	    /*------------------------------------
	    * load a cursor into template RAM  */

	    case QD_WTCURSOR:

E 10
I 10
	case QD_WTCURSOR:
		/*
		* load a cursor into template RAM  
		*/
E 10
D 11
		ldcursor(unit, datap);
E 11
I 11
		ldcursor(unit, (short *)datap);
E 11
		break;

D 10
	    case QD_RDCURSOR:
E 10
I 10
	case QD_RDCURSOR:
E 10

		temp = (short *) qdmap[unit].template;
D 10

		/* cursor is 32 WORDS from the end of the 8k WORD...
		*  ...template space */

E 10
I 10
		/*
		 * cursor is 32 WORDS from the end of the 8k WORD...
		 *  ...template space 
		 */
E 10
		temp += (8 * 1024) - 32;
D 10

E 10
		for (i = 0; i < 32; ++i, datap += sizeof(short))
D 10
		    *(short *)datap = *temp++;
E 10
I 10
			*(short *)datap = *temp++;
E 10
		break;

D 10
	    /*------------------------------
	    * position the mouse cursor  */

	    case QD_POSCURSOR:

E 10
I 10
	case QD_POSCURSOR:
		/*
		* position the mouse cursor  
		*/
E 10
		dga = (struct dga *) qdmap[unit].dga;
		pos = (struct _vs_cursor *) datap;
D 2
		s = spl5();
E 2
I 2
D 6
		s = spltty();
E 6
I 6
		s = spl5();
E 6
E 2
		dga->x_cursor = TRANX(pos->x);
		dga->y_cursor = TRANY(pos->y);
		eq_header[unit]->curs_pos.x = pos->x;
		eq_header[unit]->curs_pos.y = pos->y;
		splx(s);
		break;

D 10
	    /*--------------------------------------
	    * set the cursor acceleration factor */

	    case QD_PRGCURSOR:

E 10
I 10
	case QD_PRGCURSOR:
		/*
		* set the cursor acceleration factor 
		*/
E 10
		curs = (struct prg_cursor *) datap;
D 2
		s = spl5();
E 2
I 2
D 6
		s = spltty();
E 6
I 6
		s = spl5();
E 6
E 2
		qdflags[unit].curs_acc = curs->acc_factor;
		qdflags[unit].curs_thr = curs->threshold;
		splx(s);
		break;

D 10
	    /*---------------------------------------
	    * enable 'user write' to device pages */

	    case QD_MAPDEVICE:

		/*--------------
		* init stuff */

E 10
I 10
	case QD_MAPDEVICE:
		/*
		* enable 'user write' to device pages 
		*/
E 10
		qdflags[unit].mapped |= MAPDEV;
		qd = (struct qdmap *) &qdmap[unit];
D 10

		/*-------------------------------------
		* enable user write to template RAM */

E 10
I 10
		/*
		* enable user write to template RAM 
		*/
E 10
D 2
		mapix = VTOP((int)qd->template) - VTOP(qmem[0]);
		ptep = (int *)(QMEMmap[0] + mapix);
E 2
I 2
		mapix = VTOP((int)qd->template) - VTOP(qvmem[0]);
		ptep = (int *)(QVmap[0] + mapix);
E 2
D 10

E 10
D 11
		for (i = VTOP(TMPSIZE); i > 0; --i)
D 10
		    *ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;

		/*----------------------------------
		* enable user write to registers */

E 10
I 10
			*ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
I 11
		for (i = 0; i < btop(TMPSIZE); i++, ptep++)
			*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
		/*
		* enable user write to registers 
		*/
E 10
D 2
		mapix = VTOP((int)qd->adder) - VTOP(qmem[0]);
		ptep = (int *)(QMEMmap[0] + mapix);
E 2
I 2
		mapix = VTOP((int)qd->adder) - VTOP(qvmem[0]);
		ptep = (int *)(QVmap[0] + mapix);
E 2
D 11

		for (i = VTOP(REGSIZE); i > 0; --i)
D 10
		    *ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;

		/*-----------------------------------
		* enable user write to color maps */

E 10
I 10
			*ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
I 11
		for (i = 0; i < btop(REGSIZE); i++, ptep++)
			*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
		/*
		* enable user write to color maps 
		*/
E 10
D 2
		mapix = VTOP((int)qd->red) - VTOP(qmem[0]);
		ptep = (int *)(QMEMmap[0] + mapix);
E 2
I 2
		mapix = VTOP((int)qd->red) - VTOP(qvmem[0]);
		ptep = (int *)(QVmap[0] + mapix);
E 2
D 10

E 10
D 11
		for (i = VTOP(CLRSIZE); i > 0; --i)
D 10
		    *ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;

		/*------------------------------
		* enable user write to DUART */

E 10
I 10
			*ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
I 11
		for (i = 0; i < btop(CLRSIZE); i++, ptep++)
			*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
		/*
		* enable user write to DUART 
		*/
E 10
D 2
		mapix = VTOP((int)qd->duart) - VTOP(qmem[0]);
		ptep = (int *)(QMEMmap[0] + mapix);
E 2
I 2
		mapix = VTOP((int)qd->duart) - VTOP(qvmem[0]);
		ptep = (int *)(QVmap[0] + mapix);
E 2
		*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V; /* duart page */

D 11
		mtpr(TBIA, 0);		/* smash CPU's translation buffer */
E 11
I 11
		mtpr(TBIA, 0);		/* invalidate translation buffer */
E 11

D 10
		/*------------------------------------------
		* stuff qdmap structure in return buffer */

E 10
I 10
		/*
D 11
		* stuff qdmap structure in return buffer 
		*/
E 10
		bcopy(qd, datap, sizeof(struct qdmap));
E 11
I 11
		 * stuff qdmap structure in return buffer 
		 */
		bcopy((caddr_t)qd, datap, sizeof(struct qdmap));
E 11
		break;

D 10
	    /*-------------------------------------
	    * do setup for DMA by user process	*/

	    case QD_MAPIOBUF:

		/*------------------------------------------------
		* set 'user write enable' bits for DMA buffer  */

E 10
I 10
	case QD_MAPIOBUF:
		/*
		 * do setup for DMA by user process	
		 *
		 * set 'user write enable' bits for DMA buffer  
		 */
E 10
		qdflags[unit].mapped |= MAPDMA;
D 10

E 10
		ptep = (int *) ((VTOP(DMAheader[unit]) * 4)
D 10
				+ (mfpr(SBR) | 0x80000000));

E 10
I 10
			+ (mfpr(SBR) | 0x80000000));
E 10
D 11
		for (i = (DMAbuf_size >> PGSHIFT); i > 0; --i)
D 10
		    *ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;

E 10
I 10
			*ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 10
		mtpr(TBIA, 0);			/* clr CPU translation buf */
E 11
I 11
		for (i = 0; i < btop(DMAbuf_size); i++, ptep++)
			*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V;
		mtpr(TBIA, 0);		/* invalidate translation buffer */
E 11
D 10

		/*-------------------------------------
		* set up QBUS map registers for DMA */

E 10
I 10
		/*
		* set up QBUS map registers for DMA 
		*/
E 10
		DMAheader[unit]->QBAreg =
D 10
				uballoc(0, DMAheader[unit], DMAbuf_size, 0);

E 10
I 10
D 11
		    uballoc(0, DMAheader[unit], DMAbuf_size, 0);
E 11
I 11
		    uballoc(0, (caddr_t)DMAheader[unit], DMAbuf_size, 0);
E 11
E 10
		if (DMAheader[unit]->QBAreg == 0)
D 3
		    mprintf("\nqd%d: qdioctl: QBA setup error", unit);
E 3
I 3
D 6
		    printf("qd%d: qdioctl: QBA setup error\n", unit);
E 6
I 6
D 11
		    printf("\nqd%d: qdioctl: QBA setup error", unit);
E 11
I 11
		    printf("qd%d: qdioctl: QBA setup error\n", unit);
E 11
E 6
E 3
D 10

E 10
		Qbus_unmap[unit] = DMAheader[unit]->QBAreg;
		DMAheader[unit]->QBAreg &= 0x3FFFF;
D 10

		/*----------------------
		* return I/O buf adr */

E 10
I 10
		/*
		* return I/O buf adr 
		*/
E 10
		*(int *)datap = (int) DMAheader[unit];
		break;

D 10
	    /*----------------------------------------------------------------
	    * map the shared scroll param area and enable scroll interpts  */

	    case QD_MAPSCROLL:

E 10
I 10
	case QD_MAPSCROLL:
		/*
		* map the shared scroll param area and enable scroll interpts  
		*/
E 10
		qdflags[unit].mapped |= MAPSCR;
D 10

E 10
		ptep = (int *) ((VTOP(scroll[unit]) * 4)
D 10
				+ (mfpr(SBR) | 0x80000000));

		/* allow user write to scroll area */

E 10
I 10
			+ (mfpr(SBR) | 0x80000000));
		/*
		 * allow user write to scroll area 
		 */
E 10
		*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V;
D 10

E 10
D 11
		mtpr(TBIA, 0);			/* clr CPU translation buf */
E 11
I 11
		mtpr(TBIA, 0);			/* invalidate translation buf */
E 11
D 10

E 10
		scroll[unit]->status = 0;
D 10

E 10
		adder = (struct adder *) qdmap[unit].adder;
D 10

E 10
		qdflags[unit].adder_ie |= FRAME_SYNC;
		adder->interrupt_enable = qdflags[unit].adder_ie;
D 10

I 6

E 6
		/* return scroll area address */

		*(int *)datap = (int) scroll[unit];
E 10
I 10
		*(int *)datap = (int) scroll[unit]; /* return scroll area */
E 10
		break;

D 10
	    /*-------------------------------------------------------------
	    * unmap shared scroll param area and disable scroll intrpts */

	    case QD_UNMAPSCROLL:

E 10
I 10
	case QD_UNMAPSCROLL:
		/*
		* unmap shared scroll param area and disable scroll intrpts 
		*/
E 10
		if (qdflags[unit].mapped & MAPSCR) {
D 10

		    qdflags[unit].mapped &= ~MAPSCR;

		    ptep = (int *) ((VTOP(scroll[unit]) * 4)
				    + (mfpr(SBR) | 0x80000000));

		    /* re-protect 512 scroll param area */

		    *ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;

		    mtpr(TBIA, 0);	/* smash CPU's translation buf */

		    adder = (struct adder *) qdmap[unit].adder;
		    qdflags[unit].adder_ie &= ~FRAME_SYNC;
		    adder->interrupt_enable = qdflags[unit].adder_ie;
E 10
I 10
			qdflags[unit].mapped &= ~MAPSCR;
			ptep = (int *) ((VTOP(scroll[unit]) * 4)
				+ (mfpr(SBR) | 0x80000000));
			/*
			 * re-protect 512 scroll param area 
			 */
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;
			mtpr(TBIA, 0);	/* smash CPU's translation buf */
			adder = (struct adder *) qdmap[unit].adder;
			qdflags[unit].adder_ie &= ~FRAME_SYNC;
			adder->interrupt_enable = qdflags[unit].adder_ie;
E 10
		}
		break;

D 10
	    /*-----------------------------------------------------------
	    * map shared color map write buf and turn on vsync intrpt */

	    case QD_MAPCOLOR:

E 10
I 10
	case QD_MAPCOLOR:
		/*
		* map shared color map write buf and turn on vsync intrpt 
		*/
E 10
		qdflags[unit].mapped |= MAPCOLOR;
D 10

E 10
		ptep = (int *) ((VTOP(color_buf[unit]) * 4)
D 10
				+ (mfpr(SBR) | 0x80000000));
E 10
I 10
			+ (mfpr(SBR) | 0x80000000));
E 10
D 11

		/* allow user write to color map write buffer */

		*ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
I 11
		/*
		 * allow user write to color map write buffer 
		 */
		*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V; ptep++;
E 11
		*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V;
D 10

E 10
		mtpr(TBIA, 0);			/* clr CPU translation buf */
D 6

		adder = (struct adder *) qdmap[unit].adder;

E 6
I 6
D 10
		
		adder = (struct adder *) qdmap[unit].adder.
E 10
I 10
		adder = (struct adder *) qdmap[unit].adder;
E 10
E 6
		qdflags[unit].adder_ie |= VSYNC;
		adder->interrupt_enable = qdflags[unit].adder_ie;
D 10

E 10
D 6
		/* return scroll area address */
E 6
I 6
D 11
		/* return color area address */
E 11
I 11
		/*
		 * return color area address 
		 */
E 11
E 6
D 10

E 10
		*(int *)datap = (int) color_buf[unit];
		break;

D 10
	    /*--------------------------------------------------------------
	    * unmap shared color map write buffer and kill VSYNC intrpts */

	    case QD_UNMAPCOLOR:

E 10
I 10
	case QD_UNMAPCOLOR:
		/*
D 11
		* unmap shared color map write buffer and kill VSYNC intrpts 
		*/
E 11
I 11
		 * unmap shared color map write buffer and kill VSYNC intrpts 
		 */
E 11
E 10
		if (qdflags[unit].mapped & MAPCOLOR) {
D 10

		    qdflags[unit].mapped &= ~MAPCOLOR;

		    ptep = (int *) ((VTOP(color_buf[unit]) * 4)
				    + (mfpr(SBR) | 0x80000000));

		    /* re-protect color map write buffer */

		    *ptep++ = (*ptep & ~PG_PROT) | PG_KW | PG_V;
		    *ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;

		    mtpr(TBIA, 0);	/* smash CPU's translation buf */

		    adder = (struct adder *) qdmap[unit].adder;

		    qdflags[unit].adder_ie &= ~VSYNC;
		    adder->interrupt_enable = qdflags[unit].adder_ie;
E 10
I 10
			qdflags[unit].mapped &= ~MAPCOLOR;
			ptep = (int *) ((VTOP(color_buf[unit]) * 4)
				+ (mfpr(SBR) | 0x80000000));
D 11
			/* re-protect color map write buffer */
			*ptep++ = (*ptep & ~PG_PROT) | PG_KW | PG_V;
E 11
I 11
			/*
			 * re-protect color map write buffer 
			 */
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V; ptep++;
E 11
			*ptep = (*ptep & ~PG_PROT) | PG_KW | PG_V;
D 11
			mtpr(TBIA, 0);	/* smash CPU's translation buf */
E 11
I 11
			mtpr(TBIA, 0);
E 11
			adder = (struct adder *) qdmap[unit].adder;
			qdflags[unit].adder_ie &= ~VSYNC;
			adder->interrupt_enable = qdflags[unit].adder_ie;
E 10
		}
		break;

D 10
	    /*---------------------------------------------
	    * give user write access to the event queue */

	    case QD_MAPEVENT:

E 10
I 10
	case QD_MAPEVENT:
		/*
		* give user write access to the event queue 
		*/
E 10
		qdflags[unit].mapped |= MAPEQ;
D 10

E 10
		ptep = (int *) ((VTOP(eq_header[unit]) * 4)
D 10
				+ (mfpr(SBR) | 0x80000000));

E 10
I 10
			+ (mfpr(SBR) | 0x80000000));
E 10
D 11
		/* allow user write to 1K event queue */
D 10

E 10
		*ptep++ = (*ptep & ~PG_PROT) | PG_UW | PG_V;
E 11
I 11
		/*
		 * allow user write to 1K event queue 
		 */
		*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V; ptep++;
E 11
		*ptep = (*ptep & ~PG_PROT) | PG_UW | PG_V;
D 10

E 10
		mtpr(TBIA, 0);			/* clr CPU translation buf */
D 10

E 10
D 11
		/* return event queue address */
D 10

E 10
		*(int *)datap = (int) eq_header[unit];
E 11
I 11
		/*
		 * return event queue address 
		 */
		*(int *)datap = (int)eq_header[unit];
E 11
		break;

D 10
	    /*-----------------------------------------------
	    * pass caller's programming commands to LK201 */

	    case QD_PRGKBD:

E 10
I 10
	case QD_PRGKBD:
		/*
		* pass caller's programming commands to LK201 
		*/
E 10
D 11
		duart = (struct duart *) qdmap[unit].duart;
		cmdbuf = (struct prgkbd *) datap;    /* pnt to kbd cmd buf */
E 11
I 11
		duart = (struct duart *)qdmap[unit].duart;
		cmdbuf = (struct prgkbd *)datap;    /* pnt to kbd cmd buf */
E 11
D 10

		/*----------------
		* send command */

E 10
I 10
		/*
		* send command 
		*/
E 10
		for (i = 1000; i > 0; --i) {
D 10
		    if ((status = duart->statusA) & XMT_RDY) {
			duart->dataA = cmdbuf->cmd;
			break;
		    }
E 10
I 10
D 11
			if ((status = duart->statusA) & XMT_RDY) {
E 11
I 11
			if (duart->statusA&XMT_RDY) {
E 11
				duart->dataA = cmdbuf->cmd;
				break;
			}
E 10
		}
D 10

E 10
		if (i == 0) {
D 3
		    mprintf("\nqd%d: qdioctl: timeout on XMT_RDY [1]", unit);
E 3
I 3
D 6
		    printf("qd%d: qdioctl: timeout on XMT_RDY [1]\n", unit);
E 6
I 6
D 10
		    printf("\nqd%d: qdioctl: timeout on XMT_RDY [1]", unit);
E 6
E 3
		    break;
E 10
I 10
D 11
			printf("\nqd%d: qdioctl: timeout on XMT_RDY [1]", unit);
E 11
I 11
			printf("qd%d: qdioctl: timeout on XMT_RDY [1]\n", unit);
E 11
			break;
E 10
		}
D 10

		/*----------------
		* send param1? */

E 10
I 10
		/*
		* send param1? 
		*/
E 10
		if (cmdbuf->cmd & LAST_PARAM)
D 10
		    break;

		for (i = 1000; i > 0; --i) {
		    if ((status = duart->statusA) & XMT_RDY) {
			duart->dataA = cmdbuf->param1;
E 10
			break;
D 10
		    }
E 10
I 10
		for (i = 1000; i > 0; --i) {
D 11
			if ((status = duart->statusA) & XMT_RDY) {
E 11
I 11
			if (duart->statusA&XMT_RDY) {
E 11
				duart->dataA = cmdbuf->param1;
				break;
			}
E 10
		}
D 10

E 10
		if (i == 0) {
D 3
		    mprintf("\nqd%d: qdioctl: timeout on XMT_RDY [2]", unit);
E 3
I 3
D 6
		    printf("\nqd%d: qdioctl: timeout on XMT_RDY [2]\n", unit);
E 6
I 6
D 10
		    printf("\nqd%d: qdioctl: timeout on XMT_RDY [2]", unit);
E 6
E 3
		    break;
E 10
I 10
D 11
			printf("\nqd%d: qdioctl: timeout on XMT_RDY [2]", unit);
E 11
I 11
			printf("qd%d: qdioctl: timeout on XMT_RDY [2]\n", unit);
E 11
			break;
E 10
		}
D 10

		/*----------------
		* send param2? */

E 10
I 10
		/*
		* send param2? 
		*/
E 10
		if (cmdbuf->param1 & LAST_PARAM)
		    break;
D 10

E 10
		for (i = 1000; i > 0; --i) {
D 10
		    if ((status = duart->statusA) & XMT_RDY) {
			duart->dataA = cmdbuf->param2;
			break;
		    }
E 10
I 10
D 11
			if ((status = duart->statusA) & XMT_RDY) {
E 11
I 11
			if (duart->statusA&XMT_RDY) {
E 11
				duart->dataA = cmdbuf->param2;
				break;
			}
E 10
		}
D 10

E 10
		if (i == 0) {
D 3
		    mprintf("\nqd%d: qdioctl: timeout on XMT_RDY [3]", unit);
E 3
I 3
D 6
		    printf("qd%d: qdioctl: timeout on XMT_RDY [3]\n", unit);
E 6
I 6
D 10
		    printf("\nqd%d: qdioctl: timeout on XMT_RDY [3]", unit);
E 6
E 3
		    break;
E 10
I 10
D 11
			printf("\nqd%d: qdioctl: timeout on XMT_RDY [3]", unit);
E 11
I 11
			printf("qd%d: qdioctl: timeout on XMT_RDY [3]\n", unit);
E 11
			break;
E 10
		}
D 10

E 10
		break;

D 10
	    /*----------------------------------------------------
	    * pass caller's programming commands to the mouse  */

	    case QD_PRGMOUSE:

E 10
I 10
	case QD_PRGMOUSE:
		/*
		* pass caller's programming commands to the mouse  
		*/
E 10
		duart = (struct duart *) qdmap[unit].duart;
D 10

E 10
		for (i = 1000; i > 0; --i) {
D 10
		    if ((status = duart->statusB) & XMT_RDY) {
			duart->dataB = *datap;
			break;
		    }
E 10
I 10
D 11
			if ((status = duart->statusB) & XMT_RDY) {
E 11
I 11
			if (duart->statusB&XMT_RDY) {
E 11
				duart->dataB = *datap;
				break;
			}
E 10
		}
D 10

E 10
		if (i == 0) {
D 3
		    mprintf("\nqd%d: qdioctl: timeout on XMT_RDY [4]", unit);
E 3
I 3
D 6
		    printf("qd%d: qdioctl: timeout on XMT_RDY [4]\n", unit);
E 6
I 6
D 10
		    printf("\nqd%d: qdioctl: timeout on XMT_RDY [4]", unit);
E 10
I 10
D 11
			printf("\nqd%d: qdioctl: timeout on XMT_RDY [4]", unit);
E 11
I 11
			printf("qd%d: qdioctl: timeout on XMT_RDY [4]\n", unit);
E 11
E 10
E 6
E 3
		}
D 10

E 10
		break;

D 10
	    /*----------------------------------------------
	    * get QDSS configuration word and return it  */

	    case QD_RDCONFIG:

E 10
I 10
	case QD_RDCONFIG:
		/*
		* get QDSS configuration word and return it  
		*/
E 10
		*(short *)datap = qdflags[unit].config;
		break;

I 6
D 10
	    /*--------------------------------------------------------------
	    * re-route kernel console messages to the alternate console  */

	    case QD_KERN_LOOP:

		qdflags[unit].kernel_loop = -1;
E 10
I 10
	case QD_KERN_LOOP:
	case QD_KERN_UNLOOP:
		/*
		 * vestige from ultrix.  BSD uses TIOCCONS to redirect
		 * kernel console output.
		 */
E 10
		break;

D 10
	    case QD_KERN_UNLOOP:

		qdflags[unit].kernel_loop = 0;
		break;

E 6
D 2
	    /*--------------------------------------------------------------
	    * re-route kernel console messages to the alternate console  */

	    case QD_KERN_LOOP:

		qdflags[unit].kernel_loop = -1;
		break;

	    case QD_KERN_UNLOOP:

		qdflags[unit].kernel_loop = 0;
		break;

E 2
	    /*----------------------
	    * program the tablet */

	    case QD_PRGTABLET:

E 10
I 10
	case QD_PRGTABLET:
		/*
		* program the tablet 
		*/
E 10
		duart = (struct duart *) qdmap[unit].duart;
D 10

E 10
		for (i = 1000; i > 0; --i) {
D 10
		    if ((status = duart->statusB) & XMT_RDY) {
			duart->dataB = *datap;
			break;
		    }
E 10
I 10
D 11
			if ((status = duart->statusB) & XMT_RDY) {
E 11
I 11
			if (duart->statusB&XMT_RDY) {
E 11
				duart->dataB = *datap;
				break;
			}
E 10
		}
D 10

E 10
		if (i == 0) {
D 3
		    mprintf("\nqd%d: qdioctl: timeout on XMT_RDY [5]", unit);
E 3
I 3
D 6
		    printf("qd%d: qdioctl: timeout on XMT_RDY [5]\n", unit);
E 6
I 6
D 10
		    printf("\nqd%d: qdioctl: timeout on XMT_RDY [5]", unit);
E 10
I 10
D 11
			printf("\nqd%d: qdioctl: timeout on XMT_RDY [5]", unit);
E 11
I 11
			printf("qd%d: qdioctl: timeout on XMT_RDY [5]\n", unit);
E 11
E 10
E 6
E 3
		}
D 10

E 10
		break;

D 10
	    /*-----------------------------------------------
	    * program the tablet report resolution factor */

	    case QD_PRGTABRES:

E 10
I 10
	case QD_PRGTABRES:
		/*
		* program the tablet report resolution factor 
		*/
E 10
		qdflags[unit].tab_res = *(short *)datap;
		break;
I 6
D 10
#ifdef notdef	/* never */
	    case DEVIOCGET:			    /* device status */
		    devget = (struct devget *)datap;
		    bzero(devget,sizeof(struct devget));
		    devget->category = DEV_TERMINAL;
		    devget->bus = DEV_QB;
		    bcopy(DEV_VCB02,devget->interface,
			  strlen(DEV_VCB02));
		    bcopy(DEV_VR290,devget->device,
			  strlen(DEV_VR290));		    /* terminal */
		    devget->adpt_num = ui->ui_adpt;	    /* which adapter*/
		    devget->nexus_num = ui->ui_nexus;	    /* which nexus  */
		    devget->bus_num = ui->ui_ubanum;	    /* which QB     */
		    devget->ctlr_num = unit;		    /* which interf.*/
		    devget->slave_num = unit;		    /* which line   */
		    bcopy(ui->ui_driver->ud_dname,
			  devget->dev_name,
			  strlen(ui->ui_driver->ud_dname)); /* Ultrix "qd"  */
		    devget->unit_num = unit;		    /* qd line?     */
		    devget->soft_count =
			  sc->sc_softcnt;		    /* soft er. cnt.*/
		    devget->hard_count =
			  sc->sc_hardcnt;		    /* hard er cnt. */
		    devget->stat = sc->sc_flags;	    /* status	    */
		    devget->category_stat =
			  sc->sc_category_flags;	    /* cat. stat.   */
		    break;
#endif /*notdef*/
E 10
E 6

I 5
D 6
	    /*
	     * ultrix has a bizarre scheme for routing console output
	     * to an alternate window (xcons).  these ioctls are
	     * left in as no-ops so the X11R2 qdss server code doesn't
	     * have to be modified. console redirection is accomplished
	     * by a more sensible method using TIOCCONS in 4.3.tahoe BSD.
	     */
	    case QD_KERN_LOOP:
	    case QD_KERN_UNLOOP:
		break;

E 6
E 5
I 2
D 3
#ifdef notdef
E 2
	    case DEVIOCGET:			    /* device status */
		    devget = (struct devget *)datap;
		    bzero(devget,sizeof(struct devget));
		    devget->category = DEV_TERMINAL;
		    devget->bus = DEV_QB;
		    bcopy(DEV_VCB02,devget->interface,
			  strlen(DEV_VCB02));
		    bcopy(DEV_VR290,devget->device,
			  strlen(DEV_VR290));		    /* terminal */
		    devget->adpt_num = ui->ui_adpt;	    /* which adapter*/
		    devget->nexus_num = ui->ui_nexus;	    /* which nexus  */
		    devget->bus_num = ui->ui_ubanum;	    /* which QB     */
		    devget->ctlr_num = unit;		    /* which interf.*/
		    devget->slave_num = unit;		    /* which line   */
		    bcopy(ui->ui_driver->ud_dname,
			  devget->dev_name,
			  strlen(ui->ui_driver->ud_dname)); /* Ultrix "qd"  */
		    devget->unit_num = unit;		    /* qd line?     */
		    devget->soft_count =
			  sc->sc_softcnt;		    /* soft er. cnt.*/
		    devget->hard_count =
			  sc->sc_hardcnt;		    /* hard er cnt. */
		    devget->stat = sc->sc_flags;	    /* status	    */
		    devget->category_stat =
			  sc->sc_category_flags;	    /* cat. stat.   */
		    break;
I 2
#endif /* notdef */
E 2

E 3
D 10
	    default:
		/*-----------------------------
		* service tty type ioctl's  */

		    if (!(minor_dev & 0x02)) {

E 10
I 10
	default:
		/*
		* service tty ioctl's  
		*/
		if (!(minor_dev & 0x02)) {
E 10
			tp = &qd_tty[minor_dev];
D 10

			error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, datap, flags);
E 10
I 10
			error = 
			   (*linesw[tp->t_line].l_ioctl)(tp, cmd, datap, flags);
E 10
			if (error >= 0) {
D 10
			    return(error);
E 10
I 10
				return(error);
E 10
			}
D 10

E 10
			error = ttioctl(tp, cmd, datap, flags);
			if (error >= 0) {
D 10
			    return(error);
E 10
I 10
				return(error);
E 10
			}
D 10
		    }
		    break;
E 10
I 10
		}
		break;
E 10
	}

D 10
/*--------------------------------
* clean up and get outta here  */

E 10
	return(0);

} /* qdioctl */

D 11
/**********************************************************************
*
*	qdselect()... service select call for event queue input
*
**********************************************************************/

E 11
qdselect(dev, rw)
D 10
dev_t dev;
int rw;
E 10
I 10
	dev_t dev;
	int rw;
E 10
{
D 11
	register int s;
	register int unit;
E 11
I 11
	register s;
	register unit;
E 11
I 6
	register struct tty *tp;
	u_int minor_dev = minor(dev);
E 6

D 2
	s = spl5();
E 2
I 2
D 6
	s = spltty();
E 2
	unit = minor(dev) >> 2;
E 6
I 6
	s = spl5();
	unit = minor_dev >> 2;
E 6

	switch (rw) {
D 10

D 6
	    case FREAD: 		/* event available? */
E 6
I 6
	    case FREAD:
E 6

D 6
		if(!(ISEMPTY(eq_header[unit]))) {
E 6
I 6
		if ((minor_dev & 0x03) == 2)
		{
		    /*
		     * this is a graphics device, so check for events
		     */
		    if(!(ISEMPTY(eq_header[unit])))
		    {
		        splx(s);
		        return(1);
		    }
		    rsel[unit] = u.u_procp;
		    qdflags[unit].selmask |= SEL_READ;
E 6
		    splx(s);
D 6
		    return(1);		/* return "1" if event exists */
E 6
I 6
		    return(0);
E 10
I 10
	case FREAD:
		if ((minor_dev & 0x03) == 2) {
			/*
			* this is a graphics device, so check for events
			*/
D 11
			if(!(ISEMPTY(eq_header[unit])))
			    {
E 11
I 11
			if(!(ISEMPTY(eq_header[unit]))) {
E 11
				splx(s);
				return(1);
			}
D 11
			rsel[unit] = u.u_procp;
E 11
I 11
			qdrsel[unit] = u.u_procp;
E 11
			qdflags[unit].selmask |= SEL_READ;
			splx(s);
			return(0);
		} else {
			/*
			* this is a tty device
			*/
			tp = &qd_tty[minor_dev];
			if (ttnread(tp))
			    return(1);
			tp->t_rsel = u.u_procp;
			splx(s);
			return(0);
E 10
E 6
		}
D 6
		rsel[unit] = u.u_procp;
		qdflags[unit].selmask |= SEL_READ;
		splx(s);
		return(0);
E 6
I 6
D 10
		else
		{
		    /*
		     * this is a tty device
		     */
	    	    tp = &qd_tty[minor_dev];
		    if (ttnread(tp))
			return(1);
		    tp->t_rsel = u.u_procp;
		    splx(s);
		    return(0);
		}
E 10
E 6

D 6
	    case FWRITE:		/* DMA done? */
E 6
I 6
D 10
	    case FWRITE:
E 6

D 6
		if (DMA_ISEMPTY(DMAheader[unit])) {
E 6
I 6
		if ((minor(dev) & 0x03) == 2)
		{
		    /*
		     * this is a graphics device, so check for dma buffers
		     */
		    if (DMA_ISEMPTY(DMAheader[unit]))
		    {
		        splx(s);
		        return(1);
		    }
		    rsel[unit] = u.u_procp;
		    qdflags[unit].selmask |= SEL_WRITE;
E 6
		    splx(s);
D 6
		    return(1);		/* return "1" if DMA is done */
E 6
I 6
		    return(0);
E 10
I 10
	case FWRITE:
		if ((minor(dev) & 0x03) == 2) {
			/*
			* this is a graphics device, so check for dma buffers
			*/
			if (DMA_ISEMPTY(DMAheader[unit]))
			    {
				splx(s);
				return(1);
			}
D 11
			rsel[unit] = u.u_procp;
E 11
I 11
			qdrsel[unit] = u.u_procp;
E 11
			qdflags[unit].selmask |= SEL_WRITE;
			splx(s);
			return(0);
		} else {
			/*
			* this is a tty device
			*/
			tp = &qd_tty[minor_dev];
			if (tp->t_outq.c_cc <= TTLOWAT(tp))
			    return(1);
			tp->t_wsel = u.u_procp;
			splx(s);
			return(0);
E 10
E 6
		}
D 6
		rsel[unit] = u.u_procp;
		qdflags[unit].selmask |= SEL_WRITE;
		splx(s);
		return(0);
E 6
I 6
D 10
		else
		{
		    /*
		     * this is a tty device
		     */
	    	    tp = &qd_tty[minor_dev];
		    if (tp->t_outq.c_cc <= TTLOWAT(tp))
			return(1);
		    tp->t_wsel = u.u_procp;
		    splx(s);
		    return(0);
		}
E 10
E 6
	}
I 11
	splx(s);
	return(0);
E 11

} /* qdselect() */

D 11
/***************************************************************
*
*	qdwrite()... output to the QDSS screen as a TTY
*
***************************************************************/

E 11
extern qd_strategy();

qdwrite(dev, uio)
D 10
dev_t dev;
struct uio *uio;
E 10
I 10
	dev_t dev;
	struct uio *uio;
E 10
{
	register struct tty *tp;
D 11
	register int minor_dev;
	register int unit;
E 11
I 11
	register minor_dev;
	register unit;
E 11

	minor_dev = minor(dev);
	unit = (minor_dev >> 2) & 0x07;

D 10
	/*------------------------------
	* if this is the console...  */

	if ((minor_dev & 0x03) != 0x02	&&
	     qdflags[unit].inuse & CONS_DEV) {
	    tp = &qd_tty[minor_dev];
	    return ((*linesw[tp->t_line].l_write)(tp, uio));
E 10
I 10
	if (((minor_dev&0x03) != 0x02) && (qdflags[unit].inuse&CONS_DEV)) {
		/*
		* this is the console...  
		*/
		tp = &qd_tty[minor_dev];
		return ((*linesw[tp->t_line].l_write)(tp, uio));
	} else if (qdflags[unit].inuse & GRAPHIC_DEV) {
		/*
		* this is a DMA xfer from user space 
		*/
		return (physio(qd_strategy, &qdbuf[unit],
		dev, B_WRITE, minphys, uio));
E 10
	}
I 11
	return (ENXIO);
E 11
D 10

	/*------------------------------------------------
	* else this must be a DMA xfer from user space */

	else if (qdflags[unit].inuse & GRAPHIC_DEV) {
	    return (physio(qd_strategy, &qdbuf[unit],
			   dev, B_WRITE, minphys, uio));
	}
E 10
}

D 11
/***************************************************************
*
*	qdread()... read from QDSS keyboard as a TTY
*
***************************************************************/

E 11
qdread(dev, uio)
D 10
dev_t dev;
struct uio *uio;
E 10
I 10
	dev_t dev;
	struct uio *uio;
E 10
{
	register struct tty *tp;
D 11
	register int minor_dev;
	register int unit;
E 11
I 11
	register minor_dev;
	register unit;
E 11

	minor_dev = minor(dev);
	unit = (minor_dev >> 2) & 0x07;

D 10
	/*------------------------------
	* if this is the console...  */

	if ((minor_dev & 0x03) != 0x02	&&
	     qdflags[unit].inuse & CONS_DEV) {
	    tp = &qd_tty[minor_dev];
	    return ((*linesw[tp->t_line].l_read)(tp, uio));
E 10
I 10
	if ((minor_dev & 0x03) != 0x02 && qdflags[unit].inuse & CONS_DEV) {
		/*
		* this is the console
		*/
		tp = &qd_tty[minor_dev];
		return ((*linesw[tp->t_line].l_read)(tp, uio));
	} else if (qdflags[unit].inuse & GRAPHIC_DEV) {
		/*
		* this is a bitmap-to-processor xfer 
		*/
		return (physio(qd_strategy, &qdbuf[unit],
		dev, B_READ, minphys, uio));
E 10
	}
I 11
	return (ENXIO);
E 11
D 10

	/*------------------------------------------------
	* else this must be a bitmap-to-processor xfer */

	else if (qdflags[unit].inuse & GRAPHIC_DEV) {
	    return (physio(qd_strategy, &qdbuf[unit],
			   dev, B_READ, minphys, uio));
	}
E 10
}

/***************************************************************
*
*	qd_strategy()... strategy routine to do DMA
*
***************************************************************/

qd_strategy(bp)
D 10
register struct buf *bp;
E 10
I 10
	register struct buf *bp;
E 10
{
	register struct dga *dga;
	register struct adder *adder;
D 10

E 10
D 11
	char *DMAbufp;
E 11
I 11
	register unit;
E 11
D 10

E 10
	int QBAreg;
D 11
	int bytcnt;
E 11
	int s;
D 11
	int unit;
E 11
	int cookie;
D 10

E 10
D 11
	int i,j,k;
E 11

	unit = (minor(bp->b_dev) >> 2) & 0x07;

D 2
/*-----------------
* init pointers */
E 2
I 2
D 6
	/*
	* init pointers 
	*/
E 6
I 6
D 10
/*-----------------
* init pointers */
E 6
E 2

E 10
I 10
	/*
	* init pointers 
	*/
E 10
	if ((QBAreg = ubasetup(0, bp, 0)) == 0) {
D 3
	    mprintf("\nqd%d: qd_strategy: QBA setup error", unit);
E 3
I 3
D 6
	    printf("qd%d: qd_strategy: QBA setup error\n", unit);
E 6
I 6
D 10
	    printf("\nqd%d: qd_strategy: QBA setup error", unit);
E 6
E 3
	    goto STRAT_ERR;
E 10
I 10
D 11
		printf("\nqd%d: qd_strategy: QBA setup error", unit);
E 11
I 11
		printf("qd%d: qd_strategy: QBA setup error\n", unit);
E 11
		goto STRAT_ERR;
E 10
	}
D 10

E 10
	dga = (struct dga *) qdmap[unit].dga;
D 10

E 10
D 2
	s = spl5();
E 2
I 2
D 6
	s = spltty();
E 6
I 6
	s = spl5();
E 6
E 2
D 10

E 10
	qdflags[unit].user_dma = -1;
D 10

E 10
	dga->csr |= DMA_IE;
D 10

E 10
	cookie = QBAreg & 0x3FFFF;
	dga->adrs_lo = (short) cookie;
	dga->adrs_hi = (short) (cookie >> 16);
D 10

E 10
	dga->bytcnt_lo = (short) bp->b_bcount;
	dga->bytcnt_hi = (short) (bp->b_bcount >> 16);

	while (qdflags[unit].user_dma) {
D 10
	    sleep((caddr_t)&qdflags[unit].user_dma, QDPRIOR);
E 10
I 10
		sleep((caddr_t)&qdflags[unit].user_dma, QDPRIOR);
E 10
	}
D 10

E 10
	splx(s);
	ubarelse(0, &QBAreg);
D 10

E 10
	if (!(dga->csr & DMA_ERR)) {
D 10
	    iodone(bp);
	    return;
E 10
I 10
		iodone(bp);
		return;
E 10
	}

STRAT_ERR:
	adder = (struct adder *) qdmap[unit].adder;
D 10
	adder->command = CANCEL;		/* cancel adder activity */
E 10
I 10
	adder->command = CANCEL;	/* cancel adder activity */
E 10
	dga->csr &= ~DMA_IE;
	dga->csr &= ~0x0600;		/* halt DMA (reset fifo) */
	dga->csr |= DMA_ERR;		/* clear error condition */
	bp->b_flags |= B_ERROR; 	/* flag an error to physio() */

D 10
	/* if DMA was running, flush spurious intrpt */

E 10
I 10
	/*
	 * if DMA was running, flush spurious intrpt 
	 */
E 10
	if (dga->bytcnt_lo != 0) {
D 10
	    dga->bytcnt_lo = 0;
	    dga->bytcnt_hi = 0;
	    DMA_SETIGNORE(DMAheader[unit]);
	    dga->csr |= DMA_IE;
E 10
I 10
		dga->bytcnt_lo = 0;
		dga->bytcnt_hi = 0;
		DMA_SETIGNORE(DMAheader[unit]);
		dga->csr |= DMA_IE;
E 10
	}
D 10

E 10
	iodone(bp);

} /* qd_strategy */

D 11
/*******************************************************************
*
*	qdstart()... startup output to the console screen
*
********************************************************************
I 3
D 6
* NOTE - You must have tty.c fixed so it doesn't try to sleep
*	waiting for a transmitter interrupt (which would never occur).
*	Writes to the QDSS are synchronous and have (essentially)
*	completed by the time the start routine returns.
E 6
E 3
*
*	calling convention:
*
*		qdstart(tp);
D 3
*		struct tty *tp; 	;pointer to tty structure
E 3
I 3
D 6
*		struct tty *tp; 	# pointer to tty structure
E 6
I 6
*		struct tty *tp; 	;pointer to tty structure
E 6
E 3
*
********/

E 11
I 11
/*
 *  Start output to the console screen
 */
E 11
qdstart(tp)
D 10
register struct tty *tp;
E 10
I 10
	register struct tty *tp;
E 10
{
D 11
	register int which_unit, unit, c;
E 11
I 11
	register which_unit, unit, c;
E 11
I 6
D 10
	register struct tty *tp0;
E 10
E 6
D 3
	register struct tty *tp0;
I 2
	int needwakeup = 0;
	static int qdwakeuptime = 5;
	int wakeup();
E 3
E 2
	int s;
D 10

E 10
I 6
D 11
	int curs_on;
	struct dga *dga;
E 11

E 6
D 3
	int curs_on;
	struct dga *dga;

E 3
	unit = minor(tp->t_dev);
I 6
D 10

	tp0 = &qd_tty[(unit & 0x0FC)+1];
E 10
E 6
D 3

	tp0 = &qd_tty[(unit & 0x0FC)+1];
E 3
	which_unit = (unit >> 2) & 0x3;
D 3
	unit &= 0x03;
E 3
I 3
D 6
	/* unit &= 0x03; */
E 6
I 6
	unit &= 0x03;
E 6
E 3

D 2
	s = spl5();
E 2
I 2
D 3
	s = spltty();
E 2

E 3
D 2
/*------------------------------------------------------------------
* If it's currently active, or delaying, no need to do anything. */

E 2
I 2
D 6
	/* If it's currently active, or delaying, no need to do anything. */
I 3
	s = spltty();
E 6
I 6
	s = spl5();

D 10
/*------------------------------------------------------------------
* If it's currently active, or delaying, no need to do anything. */

E 10
I 10
	/*
	* If it's currently active, or delaying, no need to do anything. 
	*/
E 10
E 6
E 3
E 2
	if (tp->t_state & (TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
		goto out;

D 2
/*-------------------------------------------------------------------
* Display chars until the queue is empty, if the alternate console device
* is open direct chars there.  Drop input from anything but the console
* device on the floor.	*/
E 2
I 2
D 6
	/*
D 3
	 * XXX  FARKLE
	 *
	 * Check if the caller is going to sleep and prepare to
	 * wake him up with a timeout.  This is a temporary hack.
E 3
I 3
	 * XXX - this loop is at spltty.  not good, but hardly worth
	 * fixing since the glass tty is only used when the window
	 * system isn't running.  if you debug window systems you
	 * might want to rethink this.
E 3
	 */
D 3
	if (tp->t_outq.c_cc > TTHIWAT(tp))
		needwakeup++;
E 2

I 2
	/*
	 * Drain the queue.
	 * Drop input from anything but the console
	 * device on the floor.	
	 */

E 3
E 2
	while (tp->t_outq.c_cc) {
E 6
I 6
D 10
/*-------------------------------------------------------------------
* Display chars until the queue is empty, if the alternate console device
* is open direct chars there.  Drop input from anything but the console
* device on the floor.	*/
/* TANDEM is set on the second subchannel for flow control. */

	while ( tp->t_outq.c_cc ) {
E 10
I 10
	/*
	* Display chars until the queue is empty.
	* Drop input from anything but the console
	* device on the floor.	
	*
	* XXX - this loop is done at spltty.
	*
	*/
	while (tp->t_outq.c_cc) {
E 10
E 6
D 3
	    c = getc(&tp->t_outq);
D 2
	    if (unit == 0) {
		if (tp0->t_state & TS_ISOPEN)
		    (*linesw[tp0->t_line].l_rint)(c, tp0);
		else
		    blitc(which_unit, c & 0xFF);
	    }
E 2
I 2
	    if (unit == 0) 
	    	blitc(which_unit, c & 0xFF);
E 3
I 3
		c = getc(&tp->t_outq);
D 6
		blitc(which_unit, c & 0xFF);
E 6
I 6
		if (unit == 0)
D 10
		    blitc(which_unit, (char)(c & 0xFF));
#ifdef notdef	/* never never never */
	    if (unit == 0) {		/* console device */
		if (tp0->t_state & TS_ISOPEN) {
		    if (tp0->t_state & TS_TBLOCK)
			goto out;
		    c = getc(&tp->t_outq);
		    (*linesw[tp0->t_line].l_rint)(c, tp0);
		} else {
		    c = getc(&tp->t_outq);
		    blitc(which_unit, (char)(c & 0xFF));
		}
	    } else if (unit == 1) {	/* qconsole, do flow control */
		    c = getc(&tp->t_outq);
		    if ((tp0->t_state&TS_TBLOCK) == 0) {
			tp = &qd_tty[0];
			unit = minor(tp->t_dev);
			unit &= 0x03;
			continue;
		    } else
			goto out;
	    } else
		c = getc(&tp->t_outq);
#endif
E 10
I 10
D 11
			blitc(which_unit, (char)(c & 0xFF));
E 11
I 11
			blitc(which_unit, (u_char)c);
E 11
E 10
E 6
E 3
E 2
	}
D 3

D 2
/*--------------------------------------------------------
* If there are sleepers, and output has drained below low
* water mark, wake up the sleepers. */
E 2
I 2
	/*
	 *  - FARKLE - 
	 *  We are not a real hardware tty device that incures transmitter
	 *  interrupts.  This breaks the paradigm used in tty.c for
	 *  flow control. I.e.
	 *
	 *	spltty();
	 *	 ttstart();  /* schedule output which should interrupt*
	 *	 set TT_SLEEP flag
	 *	 sleep(outq)
	 *	splx();
	 *	
	 *  Don't know what to do about this one.  In the meantime we schedule
	 *  a wakeup for the sleep that will occur.  Its gross - but works
	 *  for now.  This will all be rewritten anyway.
	 *	
	 */
E 2

	if ( tp->t_outq.c_cc <= TTLOWAT(tp) ) {
I 2
		if (needwakeup)
			timeout(wakeup,(caddr_t)&tp->t_outq,qdwakeuptime); /*XXX*/
E 2
		if (tp->t_state & TS_ASLEEP){
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t) &tp->t_outq);
D 2
		}
E 2
I 2
		} 
E 3
I 3
D 6
	tp->t_state &= ~TS_BUSY;
	if (tp->t_state&TS_ASLEEP) {
		tp->t_state &= ~TS_ASLEEP;
		wakeup((caddr_t)&tp->t_outq);
E 6
I 6
D 10

/*--------------------------------------------------------
* If there are sleepers, and output has drained below low
* water mark, wake up the sleepers. */

	if ( tp->t_outq.c_cc <= TTLOWAT(tp) ) {
E 10
I 10
	/*
	* If there are sleepers, and output has drained below low
	* water mark, wake up the sleepers. 
	*/
	if (tp->t_outq.c_cc <= TTLOWAT(tp)) {
E 10
		if (tp->t_state & TS_ASLEEP){
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t) &tp->t_outq);
		}
E 6
E 3
E 2
	}

I 6
	tp->t_state &= ~TS_BUSY;

E 6
D 3
	tp->t_state &= ~TS_BUSY;

E 3
out:
	splx(s);

} /* qdstart */

D 11

/*******************************************************************
*
*	qdstop()... stop the tty
*
*******************************************************************/

E 11
I 11
/*ARGSUSED*/
E 11
qdstop(tp, flag)
D 10
register struct tty *tp;
int flag;
E 10
I 10
	register struct tty *tp;
	int flag;
E 10
{
	register int s;

D 2
	s = spl5();	/* block intrpts during state modification */
E 2
I 2
D 3
	log(LOG_NOTICE, "*qdstop*");
E 3
I 3
D 6
#ifdef notdef	/* not needed - qdss is synchronous */
E 3
	s = spltty();	/* block intrpts during state modification */
E 6
I 6
	s = spl5();	/* block intrpts during state modification */
D 10

E 10
E 6
E 2
D 3

E 3
D 11
	if (tp->t_state & TS_BUSY) {
D 10
	    if ((tp->t_state & TS_TTSTOP) == 0) {
		tp->t_state |= TS_FLUSH;
	    } else
		tp->t_state &= ~TS_BUSY;
E 10
I 10
		if ((tp->t_state & TS_TTSTOP) == 0) {
E 11
I 11
	if (tp->t_state & TS_BUSY)
		if ((tp->t_state & TS_TTSTOP) == 0)
E 11
			tp->t_state |= TS_FLUSH;
D 11
		} 
E 11
		else
			tp->t_state &= ~TS_BUSY;
E 10
D 11
	}
E 11
	splx(s);
I 3
D 6
#endif
E 6
E 3
}

D 11
/*******************************************************************
*
*	blitc()... output a character to the QDSS screen
*
********************************************************************
*
*	calling convention:
*
*		blitc(chr);
D 10
*		char chr;		;character to be displayed
E 10
I 10
*		char chr;		# character to be displayed
E 10
*
********/
E 11
I 11
/*
 *  Output a character to the QDSS screen
 */
E 11

blitc(unit, chr)
D 10
int unit;
D 6
char chr;
E 6
I 6
unsigned char chr;
E 10
I 10
D 11
	int unit;
	unsigned char chr;
E 11
I 11
	register unit;
	register u_char chr;
E 11
E 10
E 6
{
	register struct adder *adder;
	register struct dga *dga;
	register int i;
I 2
D 6
	static	 short inescape[NQD];
E 6
E 2
D 10

	short x;
E 10
I 10
	int nograph = !(qdflags[unit].inuse&GRAPHIC_DEV);
E 10
I 6
D 11
	unsigned char savechar;
I 10
	short x;
E 11
	static short inescape[NQD];
E 10
E 6

D 2
/*---------------
* init stuff  */
E 2
I 2
D 6
	/* init stuff  */
E 6
I 6
D 10
/*---------------
* init stuff  */
E 6
E 2

E 10
D 11
	adder = (struct adder *) qdmap[unit].adder;
E 11
I 11
	adder = (struct adder *)qdmap[unit].adder;
E 11
	dga = (struct dga *) qdmap[unit].dga;
I 10
	/* 
	 * BSD comment: this (&=0177) defeats the extended character 
	 * set code for the glass tty, but if i had the time i would 
	 * spend it ripping out the code completely.  This driver
	 * is too big for its own good.
	 */
	chr &= 0177;
	/*
D 11
	 * Cursor addressing (so vi will work when i really need it).
E 11
I 11
	 * Cursor addressing (so vi will work).
E 11
	 * Decode for "\E=%.%." cursor motion description.
D 11
	 * Corresponds to type "qdcons" in /etc/termcap, or if you
	 * don't have it:
E 11
I 11
	 * Corresponds to type "qdcons" in /etc/termcap:
E 11
	 *
	 *    qd|qdss|qdcons|qdss glass tty (4.4 BSD):\
	 *      :am:do=^J:le=^H:bs:cm=\E=%.%.:cl=1^Z:co#128:li#57::nd=^L:up=^K:
	 *
	 */
	if (inescape[unit] && nograph) {	
		switch (inescape[unit]++) {
		case 1:
			if (chr != '=') {
				/* abort escape sequence */
				inescape[unit] = 0;
				blitc(unit, chr);
			}
D 11
			return(0);
E 11
I 11
			return;
E 11
		case 2:
			/* position row */
			cursor[unit].y = CHAR_HEIGHT * chr;
			if (cursor[unit].y > 863 - CHAR_HEIGHT)
				cursor[unit].y = 863 - CHAR_HEIGHT;
			dga->y_cursor = TRANY(cursor[unit].y);
D 11
			return(0);
E 11
I 11
			return;
E 11
		case 3:
			/* position column */
			cursor[unit].x = CHAR_WIDTH * chr;
			if (cursor[unit].x > 1024 - CHAR_WIDTH)
				cursor[unit].x = 1023 - CHAR_WIDTH;
			dga->x_cursor = TRANX(cursor[unit].x);
			inescape[unit] = 0;
D 11
			return(0);
E 11
I 11
			return;
E 11
		default:
			inescape[unit] = 0;
			blitc(unit, chr);
		}
	}
E 10

D 2
/*---------------------------
* non display character?  */

E 2
D 6
	chr &= 0x7F;
E 6
I 6
D 10
/*---------------------------
* non display character?  */
E 6

I 2
D 6
	/*
	 *  Support cursor addressing so vi will work.
	 *  Decode for "\E=%.%." cursor motion description.
	 *
	 *  If we've seen an escape, grab up to three more
	 *  characters, bailing out if necessary. 
	 */
	if (inescape[unit]) {	
		switch (inescape[unit]++) {
		case 1:
			if (chr != '=') {
				/* bogus escape sequence */
				inescape[unit] = 0;
				blitc(unit, chr);
			}
			return(0);
		case 2:
			/* position row */
			cursor[unit].y = CHAR_HEIGHT * chr;
			if (cursor[unit].y > 863 - CHAR_HEIGHT)
				cursor[unit].y = 863 - CHAR_HEIGHT;
			dga->y_cursor = TRANY(cursor[unit].y);
			return(0);
		case 3:
			/* position column */
			cursor[unit].x = CHAR_WIDTH * chr;
			if (cursor[unit].x > 1024 - CHAR_WIDTH)
				cursor[unit].x = 1023 - CHAR_WIDTH;
			dga->x_cursor = TRANX(cursor[unit].x);
			inescape[unit] = 0;
			return(0);
		default:
			inescape[unit] = 0;
			blitc(unit, chr);
		}
	}
			
E 6
I 6
	chr &= 0xFF;
E 6

E 10
E 2
	switch (chr) {
D 10

	    case '\r':			/* return char */
E 10
I 10
	case '\r':			/* return char */
E 10
		cursor[unit].x = 0;
D 6
		dga->x_cursor = TRANX(cursor[unit].x);
E 6
I 6
D 10
	        if (!(qdflags[unit].inuse & GRAPHIC_DEV))
		    dga->x_cursor = TRANX(cursor[unit].x);
E 10
I 10
		if (nograph)
			dga->x_cursor = TRANX(cursor[unit].x);
E 10
E 6
D 11
		return(0);
E 11
I 11
		return;
E 11

D 10
	    case '\t':			/* tab char */

E 10
I 10
	case '\t':			/* tab char */
E 10
		for (i = 8 - ((cursor[unit].x >> 3) & 0x07); i > 0; --i) {
D 10
		    blitc(unit, ' ');
E 10
I 10
			blitc(unit, ' ');
E 10
		}
D 11
		return(0);
E 11
I 11
		return;
E 11

D 10
	    case '\n':			/* line feed char */

E 10
I 10
	case '\n':			/* line feed char */
E 10
		if ((cursor[unit].y += CHAR_HEIGHT) > (863 - CHAR_HEIGHT)) {
D 10
		    if (qdflags[unit].inuse & GRAPHIC_DEV) {
			cursor[unit].y = 0;
		    } else {
			cursor[unit].y -= CHAR_HEIGHT;
			scroll_up(adder);
		    }
E 10
I 10
			if (nograph) {
				cursor[unit].y -= CHAR_HEIGHT;
				scroll_up(adder);
			} else
				cursor[unit].y = 0;
E 10
		}
D 6
		dga->y_cursor = TRANY(cursor[unit].y);
E 6
I 6
D 10
	        if (!(qdflags[unit].inuse & GRAPHIC_DEV))
		    dga->y_cursor = TRANY(cursor[unit].y);
E 10
I 10
		if (nograph)
			dga->y_cursor = TRANY(cursor[unit].y);
E 10
E 6
D 11
		return(0);
E 11
I 11
		return;
E 11

D 10
	    case '\b':			/* backspace char */
E 10
I 10
	case '\b':			/* backspace char */
E 10
		if (cursor[unit].x > 0) {
I 2
D 3
		    /**** - REMOVED - CRTBS is a function of the line discipline
E 3
E 2
D 10
		    cursor[unit].x -= CHAR_WIDTH;
D 3
		    blitc(unit, ' ');
I 2
		    ****/
E 2
		    cursor[unit].x -= CHAR_WIDTH;
E 3
D 6
		    dga->x_cursor = TRANX(cursor[unit].x);
E 6
I 6
		    blitc(unit, ' ');
		    cursor[unit].x -= CHAR_WIDTH;
	            if (!(qdflags[unit].inuse & GRAPHIC_DEV))
		        dga->x_cursor = TRANX(cursor[unit].x);
E 10
I 10
			cursor[unit].x -= CHAR_WIDTH;
			if (nograph)
				dga->x_cursor = TRANX(cursor[unit].x);
E 10
E 6
		}
D 11
		return(0);
E 11
I 11
		return;
E 11
I 10
D 15
	case CTRL('k'):		/* cursor up */
E 15
I 15
	case CTRL(k):		/* cursor up */
E 15
		if (nograph && cursor[unit].y > 0) {
			cursor[unit].y -= CHAR_HEIGHT;
			dga->y_cursor = TRANY(cursor[unit].y);
		}
D 11
		return(0);
E 11
I 11
		return;
E 11
E 10

I 2
D 3
	    case CTRL(k):		/* cursor up */
E 3
I 3
D 6
	    case CTRL('k'):		/* cursor up */
E 3
		if (cursor[unit].y > 0) {
			cursor[unit].y -= CHAR_HEIGHT;
			dga->y_cursor = TRANY(cursor[unit].y);
		}
		return(0);

D 3
	    case CTRL(^):		/* home cursor */
E 3
I 3
	    case CTRL('^'):		/* home cursor */
E 3
		cursor[unit].x = 0;
		dga->x_cursor = TRANX(cursor[unit].x);
		cursor[unit].y = 0;
		dga->y_cursor = TRANY(cursor[unit].y);
		return(0);

D 3
	    case CTRL(l):		/* cursor right */
E 3
I 3
	    case CTRL('l'):		/* cursor right */
E 3
		if (cursor[unit].x < 1023 - CHAR_WIDTH) {
			cursor[unit].x += CHAR_WIDTH;
			dga->x_cursor = TRANX(cursor[unit].x);
		}
		return(0);

D 3
	    case CTRL(z):		/* clear screen */
E 3
I 3
	    case CTRL('z'):		/* clear screen */
E 3
		setup_dragon(unit);  	
		clear_qd_screen(unit);
		/* and home cursor - termcap seems to assume this */
		cursor[unit].x = 0;
		dga->x_cursor = TRANX(cursor[unit].x);
		cursor[unit].y = 0;
		dga->y_cursor = TRANY(cursor[unit].y);
		return(0);

	    case '\033':		/* start escape sequence */
		inescape[unit] = 1;
		return(0);

E 6
E 2
D 10
	    default:
D 6
		if (chr < ' ' || chr > '~')
E 6
I 6
		/*----------------------------------------------------------
		 * Weed out unprintable characters.  Printable characters fall
		 * between space (0x20) and tilde (0x7E).  For 8-bit support
		 * another range of printable characters are those between
		 * 0xA1 and 0xFD. */
E 10
I 10
D 15
	case CTRL('^'):		/* home cursor */
E 15
I 15
	case CTRL(^):		/* home cursor */
E 15
		if (nograph) {
			cursor[unit].x = 0;
			dga->x_cursor = TRANX(cursor[unit].x);
			cursor[unit].y = 0;
			dga->y_cursor = TRANY(cursor[unit].y);
		}
D 11
		return(0);
E 11
I 11
		return;
E 11
E 10

D 10
		if ((chr < ' ') || (chr > 0xFD) || (chr < 0xA1 && chr > '~'))
E 6
		    return(0);
	}
E 10
I 10
D 15
	case CTRL('l'):		/* cursor right */
E 15
I 15
	case CTRL(l):		/* cursor right */
E 15
		if (nograph && cursor[unit].x < 1023 - CHAR_WIDTH) {
			cursor[unit].x += CHAR_WIDTH;
			dga->x_cursor = TRANX(cursor[unit].x);
		}
D 11
		return(0);
E 11
I 11
		return;
E 11
E 10

D 2
/*------------------------------------------
* setup VIPER operand control registers  */
E 2
I 2
D 6
	/* setup VIPER operand control registers  */
E 6
I 6
D 10
/*------------------------------------------
* setup VIPER operand control registers  */
E 10
I 10
D 15
	case CTRL('z'):		/* clear screen */
E 15
I 15
	case CTRL(z):		/* clear screen */
E 15
		if (nograph) {
			setup_dragon(unit);  	
			clear_qd_screen(unit);
			/* home cursor - termcap seems to assume this */
			cursor[unit].x = 0;
			dga->x_cursor = TRANX(cursor[unit].x);
			cursor[unit].y = 0;
			dga->y_cursor = TRANY(cursor[unit].y);
		}
D 11
		return(0);
E 11
I 11
		return;
E 11
E 10
E 6
E 2

I 10
	case '\033':		/* start escape sequence */
		if (nograph)
			inescape[unit] = 1;
D 11
		return(0);
E 11
I 11
		return;
E 11

	default:
		if ((chr < ' ') || (chr > '~'))
D 11
			return(0);
E 11
I 11
			return;
E 11
	}
	/*
	 * setup VIPER operand control registers  
	 */
E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0001);  /* select plane #0 */
	write_ID(adder, SRC1_OCR_B,
D 10
			EXT_NONE | INT_SOURCE | ID | BAR_SHIFT_DELAY);

E 10
I 10
	EXT_NONE | INT_SOURCE | ID | BAR_SHIFT_DELAY);
E 10
	write_ID(adder, CS_UPDATE_MASK, 0x00FE);  /* select other planes */
	write_ID(adder, SRC1_OCR_B,
D 10
			EXT_SOURCE | INT_NONE | NO_ID | BAR_SHIFT_DELAY);

E 10
I 10
	EXT_SOURCE | INT_NONE | NO_ID | BAR_SHIFT_DELAY);
E 10
	write_ID(adder, CS_UPDATE_MASK, 0x00FF);  /* select all planes */
	write_ID(adder, DST_OCR_B,
D 10
			EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);

E 10
I 10
	EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);
E 10
	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 1);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);
D 10

D 2
/*----------------------------------------
* load DESTINATION origin and vectors  */
E 2
I 2
D 6
	/* load DESTINATION origin and vectors  */
E 6
I 6
        adder->x_clip_min = 0;
        adder->x_clip_max = 1024;
        adder->y_clip_min = 0;
        adder->y_clip_max = 864;
E 6
E 2

I 6
/*----------------------------------------
* load DESTINATION origin and vectors  */

E 10
I 10
	adder->x_clip_min = 0;
	adder->x_clip_max = 1024;
	adder->y_clip_min = 0;
	adder->y_clip_max = 864;
	/*
	 * load DESTINATION origin and vectors  
	 */
E 10
E 6
	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->error_1 = 0;
	adder->error_2 = 0;
D 10

E 10
	adder->rasterop_mode = DST_WRITE_ENABLE | NORMAL;
D 10

E 10
D 11
	wait_status(adder, RASTEROP_COMPLETE);
E 11
I 11
	(void)wait_status(adder, RASTEROP_COMPLETE);
E 11
D 10

E 10
	adder->destination_x = cursor[unit].x;
	adder->fast_dest_dx = CHAR_WIDTH;
D 10

E 10
	adder->destination_y = cursor[unit].y;
	adder->slow_dest_dy = CHAR_HEIGHT;
D 10

D 2
/*-----------------------------------
* load SOURCE origin and vectors  */
E 2
I 2
D 6
	/* load SOURCE origin and vectors  */
E 6
I 6
/*-----------------------------------
* load SOURCE origin and vectors  */
E 6
E 2

D 6
	adder->source_1_x = FONT_X + ((chr - ' ') * CHAR_WIDTH);
	adder->source_1_y = FONT_Y;
E 6
I 6
	if (chr > '~') {
		savechar = chr;
		chr -= 34; /* These are to skip the (32) 8-bit control chars. 
			      as well as DEL and 0xA0 which aren't printable */
	}
E 10
I 10
	/*
	 * load SOURCE origin and vectors  
	 */
E 10
	if ((chr - ' ') > (CHARS - 1))  {
		printf("Invalid character (x)%x in blitc\n",chr);
		chr = ' ';
	}
D 10
	/* X position is modulo the number of characters per line */
E 10
I 10
	/*
	 * X position is modulo the number of characters per line 
	 */
E 10
	adder->source_1_x = FONT_X + 
D 10
		(((chr - ' ') % (MAX_SCREEN_X/CHAR_WIDTH)) * CHAR_WIDTH);
	/* Point to either first or second row */
E 10
I 10
	    (((chr - ' ') % (MAX_SCREEN_X/CHAR_WIDTH)) * CHAR_WIDTH);
	/*
	 * Point to either first or second row 
	 */
E 10
	adder->source_1_y = 2048 - 15 * 
D 10
		(((chr - ' ')/(MAX_SCREEN_X/CHAR_WIDTH)) + 1);
E 6

E 10
I 10
	    (((chr - ' ')/(MAX_SCREEN_X/CHAR_WIDTH)) + 1);
E 10
	adder->source_1_dx = CHAR_WIDTH;
	adder->source_1_dy = CHAR_HEIGHT;
D 10

E 10
	write_ID(adder, LU_FUNCTION_R1, FULL_SRC_RESOLUTION | LF_SOURCE);
	adder->cmd = RASTEROP | OCRB | 0 | S1E | DTE;
D 10

D 2
/*-------------------------------------
* update console cursor coordinates */
E 2
I 2
D 6
	/* update console cursor coordinates */
E 6
I 6
/*-------------------------------------
* update console cursor coordinates */
E 6
E 2

E 10
I 10
	/*
	 * update console cursor coordinates 
	 */
E 10
	cursor[unit].x += CHAR_WIDTH;
D 6
	dga->x_cursor = TRANX(cursor[unit].x);
E 6
I 6
D 10
	if (!(qdflags[unit].inuse & GRAPHIC_DEV))
	    dga->x_cursor = TRANX(cursor[unit].x);
E 6

E 10
I 10
	if (nograph)
		dga->x_cursor = TRANX(cursor[unit].x);
E 10
I 2
D 6
	/* auto-wrap margin */
E 6
E 2
	if (cursor[unit].x > (1024 - CHAR_WIDTH)) {
D 10
	    blitc(unit, '\r');
	    blitc(unit, '\n');
E 10
I 10
		blitc(unit, '\r');
		blitc(unit, '\n');
E 10
	}

} /* blitc */

D 10
qdreset(){}
qd_init(){}
E 10
I 10
D 11
qdreset()
{
}
qd_init()
{
}
E 11
I 11
qdreset() { }
E 11
E 10

D 11
/******************************************************************
I 6
*******************************************************************
*******************************************************************
E 6
D 2
*******************************************************************
*******************************************************************
E 2
*
D 10
*	INTERRUPT SERVICE ROUTINES START HERE:
E 10
I 10
*	INTERRUPT SERVICE ROUTINES
E 10
*
I 6
*******************************************************************
*******************************************************************
E 6
D 2
*******************************************************************
*******************************************************************
E 2
******************************************************************/

/*****************************************************************
*
*	qddint()... service "DMA DONE" interrupt condition
*
*****************************************************************/
E 11
I 11
/*
 *  INTERRUPT SERVICE ROUTINES
 */
E 11

I 11
/*
 *  Service "DMA DONE" interrupt condition
 */
E 11
qddint(qd)
D 10
int qd;
E 10
I 10
D 11
	int qd;
E 11
I 11
	register qd;
E 11
E 10
{
	register struct DMAreq_header *header;
	register struct DMAreq *request;
	register struct dga *dga;
	struct adder *adder;
D 11

E 11
	int cookie;			/* DMA adrs for QDSS */
D 11
	int i;
E 11

D 11
	spl4(); 			/* allow interval timer in */
E 11
I 11
	(void)spl4(); 			/* allow interval timer in */
E 11

D 2
/*-----------------
* init pointers */
E 2
I 2
D 6
	/*
	* init pointers 
	*/
E 6
I 6
D 10
/*-----------------
* init pointers */
E 6
E 2

E 10
I 10
	/*
	* init pointers 
	*/
E 10
	header = DMAheader[qd]; 	    /* register for optimization */
	dga = (struct dga *) qdmap[qd].dga;
	adder = (struct adder *) qdmap[qd].adder;

D 2
/*------------------------------------------------------------------------
* if this interrupt flagged as bogus for interrupt flushing purposes.. */
E 2
I 2
D 6
	/*
	* if this interrupt flagged as bogus for interrupt flushing purposes.. 
	*/
E 6
I 6
D 10
/*------------------------------------------------------------------------
* if this interrupt flagged as bogus for interrupt flushing purposes.. */
E 6
E 2

E 10
I 10
	/*
	* if this interrupt flagged as bogus for interrupt flushing purposes.. 
	*/
E 10
	if (DMA_ISIGNORE(header)) {
D 10
	    DMA_CLRIGNORE(header);
	    return;
E 10
I 10
		DMA_CLRIGNORE(header);
		return;
E 10
	}

D 10
/*----------------------------------------------------
* dump a DMA hardware error message if appropriate */

E 10
I 10
	/*
	* dump a DMA hardware error message if appropriate
	*/
E 10
	if (dga->csr & DMA_ERR) {

D 10
	    if (dga->csr & PARITY_ERR)
D 3
		mprintf("\nqd%d: qddint: DMA hardware parity fault.", qd);
E 3
I 3
D 6
		printf("qd%d: qddint: DMA hardware parity fault.\n", qd);
E 6
I 6
		printf("\nqd%d: qddint: DMA hardware parity fault.", qd);
E 10
I 10
		if (dga->csr & PARITY_ERR)
D 11
		    printf("\nqd%d: qddint: DMA hardware parity fault.", qd);
E 11
I 11
		    printf("qd%d: qddint: DMA hardware parity fault.\n", qd);
E 11
E 10
E 6
E 3

D 10
	    if (dga->csr & BUS_ERR)
D 3
		mprintf("\nqd%d: qddint: DMA hardware bus error.", qd);
E 3
I 3
D 6
		printf("qd%d: qddint: DMA hardware bus error.\n", qd);
E 6
I 6
		printf("\nqd%d: qddint: DMA hardware bus error.", qd);
E 10
I 10
		if (dga->csr & BUS_ERR)
D 11
		    printf("\nqd%d: qddint: DMA hardware bus error.", qd);
E 11
I 11
		    printf("qd%d: qddint: DMA hardware bus error.\n", qd);
E 11
E 10
E 6
E 3
	}

D 10
/*----------------------------------------
* if this was a DMA from user space... */

E 10
I 10
	/*
	* if this was a DMA from user space... 
	*/
E 10
	if (qdflags[qd].user_dma) {
D 10
	    qdflags[qd].user_dma = 0;
	    wakeup((caddr_t)&qdflags[qd].user_dma);
	    return;
E 10
I 10
		qdflags[qd].user_dma = 0;
		wakeup((caddr_t)&qdflags[qd].user_dma);
		return;
E 10
	}

D 10
/*------------------------------------------------------------------------
* if we're doing DMA request queue services, field the error condition */

E 10
I 10
	/*
	* if we're doing DMA request queue services, field the error condition 
	*/
E 10
	if (dga->csr & DMA_ERR) {

D 10
	    dga->csr &= ~0x0600;		/* halt DMA (reset fifo) */
	    dga->csr |= DMA_ERR;		/* clear error condition */
	    adder->command = CANCEL;		/* cancel adder activity */
E 10
I 10
		dga->csr &= ~0x0600;		/* halt DMA (reset fifo) */
		dga->csr |= DMA_ERR;		/* clear error condition */
		adder->command = CANCEL;	/* cancel adder activity */
E 10

D 10
	    DMA_SETERROR(header);	/* flag error in header status word */
	    DMA_CLRACTIVE(header);
	    header->DMAreq[header->oldest].DMAdone |= HARD_ERROR;
	    header->newest = header->oldest;
	    header->used = 0;
E 10
I 10
		DMA_SETERROR(header);	/* flag error in header status word */
		DMA_CLRACTIVE(header);
		header->DMAreq[header->oldest].DMAdone |= HARD_ERROR;
		header->newest = header->oldest;
		header->used = 0;
E 10

D 10
	    if (rsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
		selwakeup(rsel[qd], 0);
		rsel[qd] = 0;
		qdflags[qd].selmask &= ~SEL_WRITE;
	    }
E 10
I 10
D 11
		if (rsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
			selwakeup(rsel[qd], 0);
			rsel[qd] = 0;
E 11
I 11
		if (qdrsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
			selwakeup(qdrsel[qd], 0);
			qdrsel[qd] = 0;
E 11
			qdflags[qd].selmask &= ~SEL_WRITE;
		}
E 10

D 10
	    if (dga->bytcnt_lo != 0) {
		dga->bytcnt_lo = 0;
		dga->bytcnt_hi = 0;
		DMA_SETIGNORE(header);
	    }

	    return;
E 10
I 10
		if (dga->bytcnt_lo != 0) {
			dga->bytcnt_lo = 0;
			dga->bytcnt_hi = 0;
			DMA_SETIGNORE(header);
		}
		return;
E 10
	}

D 10
/*----------------------------------------------------------------------------
* if the DMA request queue is now becoming non-full, wakeup "select" client */

E 10
I 10
	/*
	* if the DMA request queue is now becoming non-full, 
	* wakeup "select" client.
	*/
E 10
	if (DMA_ISFULL(header)) {
D 11

D 10
	    if (rsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
		selwakeup(rsel[qd], 0);
		rsel[qd] = 0;
		qdflags[qd].selmask &= ~SEL_WRITE;
	    }
E 10
I 10
		if (rsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
			selwakeup(rsel[qd], 0);
			rsel[qd] = 0;
E 11
I 11
		if (qdrsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
			selwakeup(qdrsel[qd], 0);
			qdrsel[qd] = 0;
E 11
			qdflags[qd].selmask &= ~SEL_WRITE;
		}
E 10
	}

	header->DMAreq[header->oldest].DMAdone |= REQUEST_DONE;
I 6
D 10
        QDlast_DMAtype = header->DMAreq[header->oldest].DMAtype;
E 10
I 10
	QDlast_DMAtype = header->DMAreq[header->oldest].DMAtype;
E 10
E 6

D 6
	if (DMA_ISEMPTY(header)) {
D 3
	    mprintf("\nqd%d: qddint: unexpected interrupt", qd);
E 3
I 3
	    printf("qd%d: qddint: unexpected interrupt\n", qd);
E 6
I 6
	/* check for unexpected interrupt */
	if (DMA_ISEMPTY(header))
E 6
E 3
	    return;
D 6
	}
E 6

	DMA_GETEND(header);	/* update request queue indices */

D 10
/*------------------------------------------------------------
* if no more DMA pending, wake up "select" client and exit */
E 10
I 10
	/*
D 11
	* if no more DMA pending, wake up "select" client and exit */
E 10

E 11
I 11
	* if no more DMA pending, wake up "select" client and exit 
	*/
E 11
	if (DMA_ISEMPTY(header)) {

D 10
	    if (rsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
		selwakeup(rsel[qd], 0);
		rsel[qd] = 0;
		qdflags[qd].selmask &= ~SEL_WRITE;
	    }
E 10
I 10
D 11
		if (rsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
			selwakeup(rsel[qd], 0);
			rsel[qd] = 0;
E 11
I 11
		if (qdrsel[qd] && qdflags[qd].selmask & SEL_WRITE) {
			selwakeup(qdrsel[qd], 0);
			qdrsel[qd] = 0;
E 11
			qdflags[qd].selmask &= ~SEL_WRITE;
		}
E 10

D 10
	    DMA_CLRACTIVE(header);  /* flag DMA done */
	    return;
E 10
I 10
		DMA_CLRACTIVE(header);  /* flag DMA done */
		return;
E 10
	}

D 10
/*---------------------------
* initiate next DMA xfer  */
E 10
I 10
	/*
D 11
	* initiate next DMA xfer  */
E 10

E 11
I 11
	* initiate next DMA xfer  
	*/
E 11
	request = DMA_GETBEGIN(header);
I 6
	if (request->DMAtype != QDlast_DMAtype) {
D 10
	    	dga->csr &= ~0x0600;	  /* halt DMA (reset fifo) */
	    	adder->command = CANCEL;  /* cancel adder activity */
E 10
I 10
		dga->csr &= ~0x0600;	  /* halt DMA (reset fifo) */
		adder->command = CANCEL;  /* cancel adder activity */
E 10
	}
E 6

I 6

E 6
	switch (request->DMAtype) {

D 10
	    case DISPLIST:
E 10
I 10
	case DISPLIST:
E 10
D 6
		dga->csr |= DL_ENB;
E 6
I 6
		if (request->DMAtype != QDlast_DMAtype) {
			dga->csr |= DL_ENB;
			dga->csr &= ~(BTOP_ENB | BYTE_DMA);
		}
E 6
		break;

D 10
	    case PTOB:
E 10
I 10
	case PTOB:
E 10
D 6
		dga->csr |= PTOB_ENB;
E 6
I 6
		if (request->DMAtype != QDlast_DMAtype) {
			if (request->DMAdone & BYTE_PACK)
D 10
				dga->csr |= (PTOB_ENB | BYTE_DMA);
E 10
I 10
			    dga->csr |= (PTOB_ENB | BYTE_DMA);
E 10
			else {
				dga->csr |= PTOB_ENB;
				dga->csr &= ~BYTE_DMA;
			}
		}
E 6
		break;

D 10
	    case BTOP:
E 10
I 10
	case BTOP:
E 10
D 6
		dga->csr |= BTOP_ENB;
E 6
I 6
		if (request->DMAtype != QDlast_DMAtype) {
			if (request->DMAdone & BYTE_PACK) {
				dga->csr &= ~DL_ENB;
				dga->csr |= (BTOP_ENB | BYTE_DMA);
			}
			else {
				dga->csr |= BTOP_ENB;
				dga->csr &= ~(BYTE_DMA | DL_ENB);
			}
		}
E 6
		break;
D 6

E 6
D 10
	    default:
E 10
I 10
	default:
E 10
D 3
		mprintf("\nqd%d: qddint: illegal DMAtype parameter.", qd);
E 3
I 3
D 6
		printf("qd%d: qddint: illegal DMAtype parameter.\n", qd);
E 6
I 6
D 11
		printf("\nqd%d: qddint: illegal DMAtype parameter.", qd);
E 11
I 11
		printf("qd%d: qddint: illegal DMAtype parameter.\n", qd);
E 11
E 6
E 3
		DMA_CLRACTIVE(header);	/* flag DMA done */
		return;
	}

	if (request->DMAdone & COUNT_ZERO) {
D 10
	    dga->csr &= ~SET_DONE_FIFO;
	} else if (request->DMAdone & FIFO_EMPTY) {
	    dga->csr |= SET_DONE_FIFO;
E 10
I 10
		dga->csr &= ~SET_DONE_FIFO;
	} 
	else if (request->DMAdone & FIFO_EMPTY) {
		dga->csr |= SET_DONE_FIFO;
E 10
	}

	if (request->DMAdone & WORD_PACK)
	    dga->csr &= ~BYTE_DMA;
	else if (request->DMAdone & BYTE_PACK)
	    dga->csr |= BYTE_DMA;

	dga->csr |= DMA_IE;
I 6
D 10
        QDlast_DMAtype = request->DMAtype;
E 10
I 10
	QDlast_DMAtype = request->DMAtype;
E 10
E 6

	cookie = ((int)request->bufp - (int)header) + (int)header->QBAreg;

	dga->adrs_lo = (short) cookie;
	dga->adrs_hi = (short) (cookie >> 16);

	dga->bytcnt_lo = (short) request->length;
	dga->bytcnt_hi = (short) (request->length >> 16);

	return;
}

D 11
/*****************************************************************
*
*	qdaint()... ADDER interrupt service
*
*****************************************************************/
I 6
int Nqdaint;
E 6

E 11
I 11
/*
 * ADDER interrupt service routine
 */
E 11
qdaint(qd)
D 10
register int qd;
E 10
I 10
D 11
	register int qd;
E 11
I 11
	register qd;
E 11
E 10
{
	register struct adder *adder;
	struct color_buf *cbuf;
D 11

	short stat;
E 11
	int i;
	register struct rgb *rgbp;
	register short *red;
	register short *green;
	register short *blue;

D 11
	spl4(); 			/* allow interval timer in */
I 6
	Nqdaint++;			/* debug */
E 11
I 11
	(void)spl4(); 			/* allow interval timer in */
E 11
E 6

	adder = (struct adder *) qdmap[qd].adder;

D 10
/*------------------------------------------------------------------------
* service the vertical blank interrupt (VSYNC bit) by loading any pending
* color map load request  */

E 10
I 10
	/*
	* service the vertical blank interrupt (VSYNC bit) by loading 
	* any pending color map load request  
	*/
E 10
	if (adder->status & VSYNC) {
D 10
	    adder->status &= ~VSYNC;		/* clear the interrupt */
E 10
I 10
		adder->status &= ~VSYNC;	/* clear the interrupt */
		cbuf = color_buf[qd];
		if (cbuf->status & LOAD_COLOR_MAP) {
E 10

D 10
	    cbuf = color_buf[qd];
	    if (cbuf->status & LOAD_COLOR_MAP) {
E 10
I 10
			red = (short *) qdmap[qd].red;
			green = (short *) qdmap[qd].green;
			blue = (short *) qdmap[qd].blue;
E 10

D 10
		red = (short *) qdmap[qd].red;
		green = (short *) qdmap[qd].green;
		blue = (short *) qdmap[qd].blue;
E 10
I 10
			for (i = cbuf->count, rgbp = cbuf->rgb;
			     --i >= 0; rgbp++) {
				red[rgbp->offset] = (short) rgbp->red;
				green[rgbp->offset] = (short) rgbp->green;
				blue[rgbp->offset] = (short) rgbp->blue;
			}
E 10

D 10
		for (i = cbuf->count, rgbp = cbuf->rgb; --i >= 0; rgbp++) {

		    red[rgbp->offset] = (short) rgbp->red;
		    green[rgbp->offset] = (short) rgbp->green;
		    blue[rgbp->offset] = (short) rgbp->blue;
E 10
I 10
			cbuf->status &= ~LOAD_COLOR_MAP;
E 10
		}
D 10

		cbuf->status &= ~LOAD_COLOR_MAP;
	    }
E 10
	}

D 10
/*-------------------------------------------------
* service the scroll interrupt (FRAME_SYNC bit) */

E 10
I 10
	/*
	* service the scroll interrupt (FRAME_SYNC bit) 
	*/
E 10
	if (adder->status & FRAME_SYNC) {
D 10
	    adder->status &= ~FRAME_SYNC;	/* clear the interrupt */
E 10
I 10
		adder->status &= ~FRAME_SYNC;	/* clear the interrupt */
E 10

D 10
	    if (scroll[qd]->status & LOAD_REGS) {
E 10
I 10
		if (scroll[qd]->status & LOAD_REGS) {
E 10

D 10
		for ( i = 1000, adder->status = 0
		    ; i > 0  &&  !((stat = adder->status) & ID_SCROLL_READY)
		    ; --i);
E 10
I 10
D 11
			for ( i = 1000, adder->status = 0; i > 0  
			      &&  !((stat = adder->status) & ID_SCROLL_READY);
			      --i)
E 11
I 11
			for (i = 1000, adder->status = 0; i > 0 && 
			     !(adder->status&ID_SCROLL_READY); --i)
E 11
			      ;
E 10

D 10
		if (i == 0) {
D 3
		    mprintf("\nqd%d: qdaint: timeout on ID_SCROLL_READY", qd);
E 3
I 3
D 6
		    printf("qd%d: qdaint: timeout on ID_SCROLL_READY\n", qd);
E 6
I 6
		    printf("\nqd%d: qdaint: timeout on ID_SCROLL_READY", qd);
E 6
E 3
		    return;
		}
E 10
I 10
			if (i == 0) {
D 11
			    printf("\nqd%d: qdaint: timeout on ID_SCROLL_READY",
E 11
I 11
			    printf("qd%d: qdaint: timeout on ID_SCROLL_READY\n",
E 11
				qd);
				return;
			}
E 10

D 10
		adder->ID_scroll_data = scroll[qd]->viper_constant;
		adder->ID_scroll_command = ID_LOAD | SCROLL_CONSTANT;
E 10
I 10
			adder->ID_scroll_data = scroll[qd]->viper_constant;
			adder->ID_scroll_command = ID_LOAD | SCROLL_CONSTANT;
E 10

D 10
		adder->y_scroll_constant = scroll[qd]->y_scroll_constant;
		adder->y_offset_pending = scroll[qd]->y_offset;
E 10
I 10
			adder->y_scroll_constant =
				scroll[qd]->y_scroll_constant;
			adder->y_offset_pending = scroll[qd]->y_offset;
E 10

D 10
		if (scroll[qd]->status & LOAD_INDEX) {
E 10
I 10
			if (scroll[qd]->status & LOAD_INDEX) {
E 10

D 10
		    adder->x_index_pending = scroll[qd]->x_index_pending;
		    adder->y_index_pending = scroll[qd]->y_index_pending;
		}
E 10
I 10
				adder->x_index_pending = 
					scroll[qd]->x_index_pending;
				adder->y_index_pending = 
					scroll[qd]->y_index_pending;
			}
E 10

D 10
	    scroll[qd]->status = 0x00;
	    }
E 10
I 10
			scroll[qd]->status = 0x00;
		}
E 10
	}
}

D 11
/*****************************************************************
*
*	qdiint()... DUART input interrupt service routine
*
I 10
*	XXX - this routine should be broken out - it is essentially
*	      straight line code.
*
E 10
*****************************************************************/
E 11
I 11
/*
 *  DUART input interrupt service routine
 *
 *  XXX - this routine should be broken out - it is essentially
 *	      straight line code.
 */
E 11

qdiint(qd)
D 10
register int qd;
E 10
I 10
D 11
	register int qd;
E 11
I 11
	register qd;
E 11
E 10
{
	register struct _vs_event *event;
	register struct qdinput *eqh;
D 11

E 11
	struct dga *dga;
	struct duart *duart;
	struct mouse_report *new_rep;
D 11

E 11
	struct uba_device *ui;
	struct tty *tp;
D 11

E 11
D 6
	char chr;
E 6
I 6
	u_short chr;
E 6
D 11
	int i,j;
	int k,l;

E 11
	u_short status;
	u_short data;
	u_short key;
D 11

E 11
	char do_wakeup = 0;		/* flag to do a select wakeup call */
	char a, b, c;			/* mouse button test variables */

D 11
	spl4(); 			/* allow interval timer in */
E 11
I 11
	(void)spl4(); 			/* allow interval timer in */
E 11

	eqh = eq_header[qd];		/* optimized as a register */
	new_rep = &current_rep[qd];
	duart = (struct duart *) qdmap[qd].duart;

D 10
/*-----------------------------------------
* if the graphic device is turned on..	*/
E 10
I 10
	/*
D 11
	* if the graphic device is turned on..	*/
E 10

E 11
I 11
	* if the graphic device is turned on..	
	*/
E 11
	if (qdflags[qd].inuse & GRAPHIC_DEV) {
D 11

E 11
D 10
	    /*---------------
	    * empty DUART */
E 10
I 10
		/*
		* empty DUART 
		*/
D 11
		while ((status = duart->statusA) & RCV_RDY	||
		    (status = duart->statusB) & RCV_RDY) {
E 10

E 11
I 11
		while (duart->statusA&RCV_RDY || duart->statusB&RCV_RDY) {
E 11
D 10
	    while ((status = duart->statusA) & RCV_RDY	||
		   (status = duart->statusB) & RCV_RDY) {
E 10
I 10
			/*
D 11
			* pick up LK-201 input (if any) */
E 11
I 11
			 * pick up LK-201 input (if any) 
			 */
			if (duart->statusA&RCV_RDY) {
E 11
E 10

D 10
		/*---------------------------------
		* pick up LK-201 input (if any) */
E 10
I 10
D 11
			if ((status = duart->statusA) & RCV_RDY) {
E 10

E 11
D 10
		if ((status = duart->statusA) & RCV_RDY) {
E 10
I 10
				/* if error condition, then reset it */
E 10

D 10
		    /* if error condition, then reset it */
E 10
I 10
D 11
				if ((status = duart->statusA) & 0x70) {
E 11
I 11
				if (duart->statusA&0x70) {
E 11
					duart->cmdA = 0x40;
					continue;
				}
E 10

D 10
		    if ((status = duart->statusA) & 0x70) {
			duart->cmdA = 0x40;
			continue;
		    }
E 10
I 10
				/* event queue full now? (overflow condition) */
E 10

D 10
		    /* event queue full now? (overflow condition) */
E 10
I 10
				if (ISFULL(eqh) == TRUE) {
					printf(
D 11
					 "\nqd%d: qdiint: event queue overflow",
E 11
I 11
					 "qd%d: qdiint: event queue overflow\n",
E 11
					   qd);
					break;
				}
E 10

D 10
		    if (ISFULL(eqh) == TRUE) {
D 3
			mprintf("\nqd%d: qdiint: event queue overflow", qd);
E 3
I 3
D 6
			printf("qd%d: qdiint: event queue overflow\n", qd);
E 6
I 6
			printf("\nqd%d: qdiint: event queue overflow", qd);
E 6
E 3
			break;
		    }
E 10
I 10
				/*
				* Check for various keyboard errors  */
E 10

D 10
		    /*--------------------------------------
		    * Check for various keyboard errors  */
E 10
I 10
				key = duart->dataA & 0xFF;
E 10

D 10
		    key = duart->dataA & 0xFF;
E 10
I 10
				if (key==LK_POWER_ERROR ||
				    key==LK_KDOWN_ERROR ||
				    key == LK_INPUT_ERROR || 
				    key == LK_OUTPUT_ERROR) {
					printf(
D 11
				    "\nqd%d: qdiint: keyboard error, code = %x",
E 11
I 11
				    "qd%d: qdiint: keyboard error, code = %x\n",
E 11
					qd,key);
D 11
					return(0);
E 11
I 11
					return;
E 11
				}
E 10

D 10
		    if( key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
			key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
D 3
			mprintf("\nqd%d: qdiint: keyboard error, code = %x",qd,key);
E 3
I 3
D 6
			printf("qd%d: qdiint: keyboard error, code = %x\n",
				qd, key);
E 6
I 6
			printf("\nqd%d: qdiint: keyboard error, code = %x",qd,key);
E 6
E 3
			return(0);
		    }
E 10
I 10
				if (key < LK_LOWEST)
D 11
				    return(0);
E 11
I 11
				    return;
E 11
E 10

D 10
		    if (key < LK_LOWEST)
			return(0);
E 10
I 10
				++do_wakeup;  /* request a select wakeup call */
E 10

D 10
		    ++do_wakeup;	/* request a select wakeup call */
E 10
I 10
				event = PUTBEGIN(eqh);
				PUTEND(eqh);
E 10

D 10
		    event = PUTBEGIN(eqh);
		    PUTEND(eqh);
E 10
I 10
				event->vse_key = key;
				event->vse_key &= 0x00FF;
				event->vse_x = eqh->curs_pos.x;
				event->vse_y = eqh->curs_pos.y;
				event->vse_time = TOY;
				event->vse_type = VSE_BUTTON;
				event->vse_direction = VSE_KBTRAW;
				event->vse_device = VSE_DKB;
			}
E 10

D 10
		    event->vse_key = key;
		    event->vse_key &= 0x00FF;
		    event->vse_x = eqh->curs_pos.x;
		    event->vse_y = eqh->curs_pos.y;
		    event->vse_time = TOY;
		    event->vse_type = VSE_BUTTON;
		    event->vse_direction = VSE_KBTRAW;
		    event->vse_device = VSE_DKB;
		}
E 10
I 10
			/*
			* pick up the mouse input (if any)  */
E 10

D 10
		/*-------------------------------------
		* pick up the mouse input (if any)  */
E 10
I 10
			if ((status = duart->statusB) & RCV_RDY  &&
			    qdflags[qd].pntr_id == MOUSE_ID) {
E 10

D 10
		if ((status = duart->statusB) & RCV_RDY  &&
		     qdflags[qd].pntr_id == MOUSE_ID) {
E 10
I 10
				if (status & 0x70) {
					duart->cmdB = 0x40;
					continue;
				}
E 10

D 10
		    if (status & 0x70) {
			duart->cmdB = 0x40;
			continue;
		    }
E 10
I 10
				/* event queue full now? (overflow condition) */
E 10

D 10
		    /* event queue full now? (overflow condition) */
E 10
I 10
				if (ISFULL(eqh) == TRUE) {
					printf(
D 11
					"\nqd%d: qdiint: event queue overflow",
E 11
I 11
					"qd%d: qdiint: event queue overflow\n",
E 11
					     qd);
					break;
				}
E 10

D 10
		    if (ISFULL(eqh) == TRUE) {
D 3
			mprintf("\nqd%d: qdiint: event queue overflow", qd);
E 3
I 3
D 6
			printf("qd%d: qdiint: event queue overflow\n", qd);
E 6
I 6
			printf("\nqd%d: qdiint: event queue overflow", qd);
E 6
E 3
			break;
		    }
E 10
I 10
				data = duart->dataB;      /* get report byte */
				++new_rep->bytcnt; /* bump report byte count */
E 10

D 10
		    data = duart->dataB;      /* get report byte */
		    ++new_rep->bytcnt;	      /* bump report byte count */
E 10
I 10
				/*
				* if 1st byte of report.. */
E 10

D 10
		    /*---------------------------
		    * if 1st byte of report.. */
E 10
I 10
				if ( data & START_FRAME) {
					new_rep->state = data;
					if (new_rep->bytcnt > 1) {
						/* start of new frame */
						new_rep->bytcnt = 1;    
						/* ..continue looking */
						continue;		    
					}
				}
E 10

D 10
		    if ( data & START_FRAME) {
			new_rep->state = data;
			if (new_rep->bytcnt > 1) {
			    new_rep->bytcnt = 1;    /* start of new frame */
			    continue;		    /* ..continue looking */
			}
		    }
E 10
I 10
				/*
				* if 2nd byte of report.. */
E 10

D 10
		    /*---------------------------
		    * if 2nd byte of report.. */
E 10
I 10
				else if (new_rep->bytcnt == 2) {
					new_rep->dx = data & 0x00FF;
				}
E 10

D 10
		    else if (new_rep->bytcnt == 2) {
			new_rep->dx = data & 0x00FF;
		    }
E 10
I 10
				/*
				* if 3rd byte of report, load input event queue */
E 10

D 10
		    /*-------------------------------------------------
		    * if 3rd byte of report, load input event queue */
E 10
I 10
				else if (new_rep->bytcnt == 3) {
E 10

D 10
		    else if (new_rep->bytcnt == 3) {
E 10
I 10
					new_rep->dy = data & 0x00FF;
					new_rep->bytcnt = 0;
E 10

D 10
			new_rep->dy = data & 0x00FF;
			new_rep->bytcnt = 0;
E 10
I 10
					/*
					* if mouse position has changed.. */
E 10

D 10
			/*-----------------------------------
			* if mouse position has changed.. */
E 10
I 10
					if (new_rep->dx != 0  ||  new_rep->dy != 0) {
E 10

D 10
			if (new_rep->dx != 0  ||  new_rep->dy != 0) {
E 10
I 10
						/*
						* calculate acceleration factor, if needed	*/
E 10

D 10
			    /*---------------------------------------------
			    * calculate acceleration factor, if needed	*/
E 10
I 10
						if (qdflags[qd].curs_acc > ACC_OFF) {
E 10

D 10
			    if (qdflags[qd].curs_acc > ACC_OFF) {
E 10
I 10
							if (qdflags[qd].curs_thr <= new_rep->dx)
							    new_rep->dx +=
							    (new_rep->dx - qdflags[qd].curs_thr)
							    * qdflags[qd].curs_acc;
E 10

D 10
				if (qdflags[qd].curs_thr <= new_rep->dx)
				    new_rep->dx +=
					(new_rep->dx - qdflags[qd].curs_thr)
					 * qdflags[qd].curs_acc;
E 10
I 10
							if (qdflags[qd].curs_thr <= new_rep->dy)
							    new_rep->dy +=
							    (new_rep->dy - qdflags[qd].curs_thr)
							    * qdflags[qd].curs_acc;
						}
E 10

D 10
				if (qdflags[qd].curs_thr <= new_rep->dy)
				    new_rep->dy +=
					(new_rep->dy - qdflags[qd].curs_thr)
					 * qdflags[qd].curs_acc;
			    }
E 10
I 10
						/*
						* update cursor position coordinates */
E 10

D 10
			    /*-------------------------------------
			    * update cursor position coordinates */
E 10
I 10
						if (new_rep->state & X_SIGN) {
							eqh->curs_pos.x += new_rep->dx;
							if (eqh->curs_pos.x > 1023)
							    eqh->curs_pos.x = 1023;
						}
						else {
							eqh->curs_pos.x -= new_rep->dx;
							if (eqh->curs_pos.x < -15)
							    eqh->curs_pos.x = -15;
						}
E 10

D 10
			    if (new_rep->state & X_SIGN) {
				eqh->curs_pos.x += new_rep->dx;
				if (eqh->curs_pos.x > 1023)
				    eqh->curs_pos.x = 1023;
			    }
			    else {
				eqh->curs_pos.x -= new_rep->dx;
				if (eqh->curs_pos.x < -15)
				    eqh->curs_pos.x = -15;
			    }
E 10
I 10
						if (new_rep->state & Y_SIGN) {
							eqh->curs_pos.y -= new_rep->dy;
							if (eqh->curs_pos.y < -15)
							    eqh->curs_pos.y = -15;
						}
						else {
							eqh->curs_pos.y += new_rep->dy;
							if (eqh->curs_pos.y > 863)
							    eqh->curs_pos.y = 863;
						}
E 10

D 10
			    if (new_rep->state & Y_SIGN) {
				 eqh->curs_pos.y -= new_rep->dy;
				 if (eqh->curs_pos.y < -15)
				     eqh->curs_pos.y = -15;
			    }
			    else {
				eqh->curs_pos.y += new_rep->dy;
				if (eqh->curs_pos.y > 863)
				    eqh->curs_pos.y = 863;
			    }
E 10
I 10
						/*
						* update cursor screen position */
E 10

D 10
			    /*---------------------------------
			    * update cursor screen position */
E 10
I 10
						dga = (struct dga *) qdmap[qd].dga;
						dga->x_cursor = TRANX(eqh->curs_pos.x);
						dga->y_cursor = TRANY(eqh->curs_pos.y);
E 10

D 10
			    dga = (struct dga *) qdmap[qd].dga;
			    dga->x_cursor = TRANX(eqh->curs_pos.x);
			    dga->y_cursor = TRANY(eqh->curs_pos.y);
E 10
I 10
						/*
						* if cursor is in the box, no event report */
E 10

D 10
			    /*--------------------------------------------
			    * if cursor is in the box, no event report */
E 10
I 10
						if (eqh->curs_pos.x <= eqh->curs_box.right	&&
						    eqh->curs_pos.x >= eqh->curs_box.left  &&
						    eqh->curs_pos.y >= eqh->curs_box.top  &&
						    eqh->curs_pos.y <= eqh->curs_box.bottom ) {
							goto GET_MBUTTON;
						}
E 10

D 10
			    if (eqh->curs_pos.x <= eqh->curs_box.right	&&
				eqh->curs_pos.x >= eqh->curs_box.left  &&
				eqh->curs_pos.y >= eqh->curs_box.top  &&
				eqh->curs_pos.y <= eqh->curs_box.bottom ) {
				    goto GET_MBUTTON;
			    }
E 10
I 10
						/*
						* report the mouse motion event */
E 10

D 10
			    /*---------------------------------
			    * report the mouse motion event */
E 10
I 10
						event = PUTBEGIN(eqh);
						PUTEND(eqh);
E 10

D 10
			    event = PUTBEGIN(eqh);
			    PUTEND(eqh);
E 10
I 10
						++do_wakeup;   /* request a select wakeup call */
E 10

D 10
			    ++do_wakeup;   /* request a select wakeup call */
E 10
I 10
						event->vse_x = eqh->curs_pos.x;
						event->vse_y = eqh->curs_pos.y;
E 10

D 10
			    event->vse_x = eqh->curs_pos.x;
			    event->vse_y = eqh->curs_pos.y;
E 10
I 10
						event->vse_device = VSE_MOUSE;  /* mouse */
						event->vse_type = VSE_MMOTION;  /* pos changed */
						event->vse_key = 0;
						event->vse_direction = 0;
						event->vse_time = TOY;	/* time stamp */
					}
E 10

D 10
			    event->vse_device = VSE_MOUSE;  /* mouse */
			    event->vse_type = VSE_MMOTION;  /* pos changed */
			    event->vse_key = 0;
			    event->vse_direction = 0;
			    event->vse_time = TOY;	/* time stamp */
			}

E 10
GET_MBUTTON:
D 10
			/*-------------------------------
			* if button state has changed */
E 10
I 10
					/*
					* if button state has changed */
E 10

D 10
			a = new_rep->state & 0x07;    /*mask nonbutton bits */
			b = last_rep[qd].state & 0x07;
E 10
I 10
					a = new_rep->state & 0x07;    /*mask nonbutton bits */
					b = last_rep[qd].state & 0x07;
E 10

D 10
			if (a ^ b) {
E 10
I 10
					if (a ^ b) {
E 10

D 10
			    for ( c = 1;  c < 8; c <<= 1) {
E 10
I 10
						for ( c = 1;  c < 8; c <<= 1) {
E 10

D 10
				if (!( c & (a ^ b))) /* this button change? */
				    continue;
E 10
I 10
							if (!( c & (a ^ b))) /* this button change? */
							    continue;
E 10

D 10
				/* event queue full? (overflow condition) */
E 10
I 10
							/* event queue full? (overflow condition) */
E 10

D 10
				if (ISFULL(eqh) == TRUE) {
D 3
				    mprintf("\nqd%d: qdiint: event queue overflow", qd);
E 3
I 3
D 6
				    printf("qd%d: qdiint: event queue overflow\n", qd);
E 6
I 6
				    printf("\nqd%d: qdiint: event queue overflow", qd);
E 6
E 3
				    break;
				}
E 10
I 10
							if (ISFULL(eqh) == TRUE) {
D 11
								printf("\nqd%d: qdiint: event queue overflow", qd);
E 11
I 11
								printf("qd%d: qdiint: event queue overflow\n", qd);
E 11
								break;
							}
E 10

D 10
				event = PUTBEGIN(eqh);	/* get new event */
				PUTEND(eqh);
E 10
I 10
							event = PUTBEGIN(eqh);	/* get new event */
							PUTEND(eqh);
E 10

D 10
				++do_wakeup;   /* request select wakeup */
E 10
I 10
							++do_wakeup;   /* request select wakeup */
E 10

D 10
				event->vse_x = eqh->curs_pos.x;
				event->vse_y = eqh->curs_pos.y;
E 10
I 10
							event->vse_x = eqh->curs_pos.x;
							event->vse_y = eqh->curs_pos.y;
E 10

D 10
				event->vse_device = VSE_MOUSE;	/* mouse */
				event->vse_type = VSE_BUTTON; /* new button */
				event->vse_time = TOY;	      /* time stamp */
E 10
I 10
							event->vse_device = VSE_MOUSE;	/* mouse */
							event->vse_type = VSE_BUTTON; /* new button */
							event->vse_time = TOY;	      /* time stamp */
E 10

D 10
				/* flag changed button and if up or down */
E 10
I 10
							/* flag changed button and if up or down */
E 10

D 10
				if (c == RIGHT_BUTTON)
				    event->vse_key = VSE_RIGHT_BUTTON;
				else if (c == MIDDLE_BUTTON)
				    event->vse_key = VSE_MIDDLE_BUTTON;
				else if (c == LEFT_BUTTON)
				    event->vse_key = VSE_LEFT_BUTTON;
E 10
I 10
							if (c == RIGHT_BUTTON)
							    event->vse_key = VSE_RIGHT_BUTTON;
							else if (c == MIDDLE_BUTTON)
							    event->vse_key = VSE_MIDDLE_BUTTON;
							else if (c == LEFT_BUTTON)
							    event->vse_key = VSE_LEFT_BUTTON;
E 10

D 10
				/* set bit = button depressed */
E 10
I 10
							/* set bit = button depressed */
E 10

D 10
				if (c & a)
				    event->vse_direction = VSE_KBTDOWN;
				else
				    event->vse_direction = VSE_KBTUP;
			    }
			}
E 10
I 10
							if (c & a)
							    event->vse_direction = VSE_KBTDOWN;
							else
								event->vse_direction = VSE_KBTUP;
						}
					}
E 10

D 10
			/* refresh last report */
E 10
I 10
					/* refresh last report */
E 10

D 10
			last_rep[qd] = current_rep[qd];
E 10
I 10
					last_rep[qd] = current_rep[qd];
E 10

D 10
		    }  /* get last byte of report */
		} /* pickup mouse input */
E 10
I 10
				}  /* get last byte of report */
D 11
			} /* pickup mouse input */
E 10

D 10
		/*--------------------------------
		* pickup tablet input, if any  */
E 10
I 10
			/*
			* pickup tablet input, if any  */
E 10

D 10
		else if ((status = duart->statusB) & RCV_RDY  &&
			 qdflags[qd].pntr_id == TABLET_ID) {
E 10
I 10
			else if ((status = duart->statusB) & RCV_RDY  &&
			    qdflags[qd].pntr_id == TABLET_ID) {
E 10

D 10
		    if (status & 0x70) {
			duart->cmdB = 0x40;
			continue;
		    }
E 10
I 10
				if (status & 0x70) {
E 11
I 11
			} else if ((status = duart->statusB)&RCV_RDY &&
			           qdflags[qd].pntr_id == TABLET_ID) {
				/*
				* pickup tablet input, if any  
				*/
				if (status&0x70) {
E 11
					duart->cmdB = 0x40;
					continue;
				}
E 10
D 11

D 10
		    /* event queue full now? (overflow condition) */
E 10
I 10
				/* event queue full now? (overflow condition) */
E 10

E 11
I 11
				/* 
				 * event queue full now? (overflow condition) 
				 */
E 11
D 10
		    if (ISFULL(eqh) == TRUE) {
D 3
			mprintf("\nqd%d: qdiint: event queue overflow", qd);
E 3
I 3
D 6
			printf("qd%d: qdiint: event queue overflow\n", qd);
E 6
I 6
			printf("\nqd%d: qdiint: event queue overflow", qd);
E 6
E 3
			break;
		    }
E 10
I 10
				if (ISFULL(eqh) == TRUE) {
D 11
					printf("\nqd%d: qdiint: event queue overflow", qd);
E 11
I 11
					printf("qd%d: qdiint: event queue overflow\n", qd);
E 11
					break;
				}
E 10

D 10
		    data = duart->dataB;      /* get report byte */
		    ++new_rep->bytcnt;	      /* bump report byte count */
E 10
I 10
				data = duart->dataB;      /* get report byte */
				++new_rep->bytcnt;	      /* bump report byte count */
E 10

D 10
		    /*---------------------------
		    * if 1st byte of report.. */
E 10
I 10
				/*
				* if 1st byte of report.. */
E 10

D 10
		    if (data & START_FRAME) {
			new_rep->state = data;
			if (new_rep->bytcnt > 1) {
			    new_rep->bytcnt = 1;    /* start of new frame */
			    continue;		    /* ..continue looking */
			}
		    }
E 10
I 10
				if (data & START_FRAME) {
					new_rep->state = data;
					if (new_rep->bytcnt > 1) {
						new_rep->bytcnt = 1;    /* start of new frame */
						continue;		    /* ..continue looking */
					}
				}
E 10

D 10
		    /*---------------------------
		    * if 2nd byte of report.. */
E 10
I 10
				/*
				* if 2nd byte of report.. */
E 10

D 10
		    else if (new_rep->bytcnt == 2) {
			new_rep->dx = data & 0x3F;
		    }
E 10
I 10
				else if (new_rep->bytcnt == 2) {
					new_rep->dx = data & 0x3F;
				}
E 10

D 10
		    /*---------------------------
		    * if 3rd byte of report.. */
E 10
I 10
				/*
				* if 3rd byte of report.. */
E 10

D 10
		    else if (new_rep->bytcnt == 3) {
			new_rep->dx |= (data & 0x3F) << 6;
		    }
E 10
I 10
				else if (new_rep->bytcnt == 3) {
					new_rep->dx |= (data & 0x3F) << 6;
				}
E 10

D 10
		    /*---------------------------
		    * if 4th byte of report.. */
E 10
I 10
				/*
				* if 4th byte of report.. */
E 10

D 10
		    else if (new_rep->bytcnt == 4) {
			new_rep->dy = data & 0x3F;
		    }
E 10
I 10
				else if (new_rep->bytcnt == 4) {
					new_rep->dy = data & 0x3F;
				}
E 10

D 10
		    /*-------------------------------------------------
		    * if 5th byte of report, load input event queue */
E 10
I 10
				/*
				* if 5th byte of report, load input event queue */
E 10

D 10
		    else if (new_rep->bytcnt == 5) {
E 10
I 10
				else if (new_rep->bytcnt == 5) {
E 10

D 10
			new_rep->dy |= (data & 0x3F) << 6;
			new_rep->bytcnt = 0;
E 10
I 10
					new_rep->dy |= (data & 0x3F) << 6;
					new_rep->bytcnt = 0;
E 10

D 10
			/*-------------------------------------
			* update cursor position coordinates */
E 10
I 10
					/*
					* update cursor position coordinates */
E 10

D 10
			new_rep->dx /= qdflags[qd].tab_res;
			new_rep->dy = (2200 - new_rep->dy)
				      / qdflags[qd].tab_res;
E 10
I 10
					new_rep->dx /= qdflags[qd].tab_res;
					new_rep->dy = (2200 - new_rep->dy)
					    / qdflags[qd].tab_res;
E 10

D 10
			if (new_rep->dx > 1023) {
			    new_rep->dx = 1023;
			}
			if (new_rep->dy > 863) {
			    new_rep->dy = 863;
			}
E 10
I 10
					if (new_rep->dx > 1023) {
						new_rep->dx = 1023;
					}
					if (new_rep->dy > 863) {
						new_rep->dy = 863;
					}
E 10

D 10
			/*
			 * report an event if the puck/stylus has moved
			 */
E 10
I 10
					/*
					* report an event if the puck/stylus has moved
					*/
E 10

D 10
			if (eqh->curs_pos.x != new_rep->dx ||
			    eqh->curs_pos.y != new_rep->dy) {
E 10
I 10
					if (eqh->curs_pos.x != new_rep->dx ||
					    eqh->curs_pos.y != new_rep->dy) {
E 10

D 10
			    eqh->curs_pos.x = new_rep->dx;
			    eqh->curs_pos.y = new_rep->dy;
E 10
I 10
						eqh->curs_pos.x = new_rep->dx;
						eqh->curs_pos.y = new_rep->dy;
E 10

D 10
			    /*---------------------------------
			    * update cursor screen position */
E 10
I 10
						/*
						* update cursor screen position */
E 10

D 10
			    dga = (struct dga *) qdmap[qd].dga;
			    dga->x_cursor = TRANX(eqh->curs_pos.x);
			    dga->y_cursor = TRANY(eqh->curs_pos.y);
E 10
I 10
						dga = (struct dga *) qdmap[qd].dga;
						dga->x_cursor = TRANX(eqh->curs_pos.x);
						dga->y_cursor = TRANY(eqh->curs_pos.y);
E 10

D 10
			    /*
			     * if cursor is in the box, no event report
			     */
E 10
I 10
						/*
						* if cursor is in the box, no event report
						*/
E 10

D 10
			    if (eqh->curs_pos.x <= eqh->curs_box.right	&&
				eqh->curs_pos.x >= eqh->curs_box.left  &&
				eqh->curs_pos.y >= eqh->curs_box.top  &&
				eqh->curs_pos.y <= eqh->curs_box.bottom ) {
				goto GET_TBUTTON;
			    }
E 10
I 10
						if (eqh->curs_pos.x <= eqh->curs_box.right	&&
						    eqh->curs_pos.x >= eqh->curs_box.left  &&
						    eqh->curs_pos.y >= eqh->curs_box.top  &&
						    eqh->curs_pos.y <= eqh->curs_box.bottom ) {
							goto GET_TBUTTON;
						}
E 10

D 10
			    /*---------------------------------
			    * report the tablet motion event */
E 10
I 10
						/*
						* report the tablet motion event */
E 10

D 10
			    event = PUTBEGIN(eqh);
			    PUTEND(eqh);
E 10
I 10
						event = PUTBEGIN(eqh);
						PUTEND(eqh);
E 10

D 10
			    ++do_wakeup;   /* request a select wakeup call */
E 10
I 10
						++do_wakeup;   /* request a select wakeup call */
E 10

D 10
			    event->vse_x = eqh->curs_pos.x;
			    event->vse_y = eqh->curs_pos.y;
E 10
I 10
						event->vse_x = eqh->curs_pos.x;
						event->vse_y = eqh->curs_pos.y;
E 10

D 10
			    event->vse_device = VSE_TABLET;  /* tablet */
			    /*
			     * right now, X handles tablet motion the same
			     * as mouse motion
			     */
			    event->vse_type = VSE_MMOTION;   /* pos changed */
			    event->vse_key = 0;
			    event->vse_direction = 0;
			    event->vse_time = TOY;	/* time stamp */
			}
E 10
I 10
						event->vse_device = VSE_TABLET;  /* tablet */
						/*
						* right now, X handles tablet motion the same
						* as mouse motion
						*/
						event->vse_type = VSE_MMOTION;   /* pos changed */
						event->vse_key = 0;
						event->vse_direction = 0;
						event->vse_time = TOY;	/* time stamp */
					}
E 10
GET_TBUTTON:
D 10
			/*-------------------------------
			* if button state has changed */
E 10
I 10
					/*
					* if button state has changed */
E 10

D 10
			a = new_rep->state & 0x1E;   /* mask nonbutton bits */
			b = last_rep[qd].state & 0x1E;
E 10
I 10
					a = new_rep->state & 0x1E;   /* mask nonbutton bits */
					b = last_rep[qd].state & 0x1E;
E 10

D 10
			if (a ^ b) {
E 10
I 10
					if (a ^ b) {
E 10

D 10
			    /* event queue full now? (overflow condition) */
E 10
I 10
						/* event queue full now? (overflow condition) */
E 10

D 10
			    if (ISFULL(eqh) == TRUE) {
D 3
				mprintf("\nqd%d: qdiint: event queue overflow",qd);
E 3
I 3
D 6
				printf("qd%d: qdiint: event queue overflow\n",
					qd);
E 6
I 6
				printf("\nqd%d: qdiint: event queue overflow",qd);
E 6
E 3
				break;
			    }
E 10
I 10
						if (ISFULL(eqh) == TRUE) {
D 11
							printf("\nqd%d: qdiint: event queue overflow",qd);
E 11
I 11
							printf("qd%d: qdiint: event queue overflow\n",qd);
E 11
							break;
						}
E 10

D 10
			    event = PUTBEGIN(eqh);  /* get new event */
			    PUTEND(eqh);
E 10
I 10
						event = PUTBEGIN(eqh);  /* get new event */
						PUTEND(eqh);
E 10

D 10
			    ++do_wakeup;   /* request a select wakeup call */
E 10
I 10
						++do_wakeup;   /* request a select wakeup call */
E 10

D 10
			    event->vse_x = eqh->curs_pos.x;
			    event->vse_y = eqh->curs_pos.y;
E 10
I 10
						event->vse_x = eqh->curs_pos.x;
						event->vse_y = eqh->curs_pos.y;
E 10

D 10
			    event->vse_device = VSE_TABLET;  /* tablet */
			    event->vse_type = VSE_BUTTON; /* button changed */
			    event->vse_time = TOY;	   /* time stamp */
E 10
I 10
						event->vse_device = VSE_TABLET;  /* tablet */
						event->vse_type = VSE_BUTTON; /* button changed */
						event->vse_time = TOY;	   /* time stamp */
E 10

D 10
			    /* define the changed button and if up or down */
E 10
I 10
						/* define the changed button and if up or down */
E 10

D 10
			    for ( c = 1;  c <= 0x10; c <<= 1) {
				if (c & (a ^ b)) {
				    if (c == T_LEFT_BUTTON)
					event->vse_key = VSE_T_LEFT_BUTTON;
				    else if (c == T_FRONT_BUTTON)
					event->vse_key = VSE_T_FRONT_BUTTON;
				    else if (c == T_RIGHT_BUTTON)
					event->vse_key = VSE_T_RIGHT_BUTTON;
				    else if (c == T_BACK_BUTTON)
					event->vse_key = VSE_T_BACK_BUTTON;
				    break;
				}
			    }
E 10
I 10
						for ( c = 1;  c <= 0x10; c <<= 1) {
							if (c & (a ^ b)) {
								if (c == T_LEFT_BUTTON)
								    event->vse_key = VSE_T_LEFT_BUTTON;
								else if (c == T_FRONT_BUTTON)
								    event->vse_key = VSE_T_FRONT_BUTTON;
								else if (c == T_RIGHT_BUTTON)
								    event->vse_key = VSE_T_RIGHT_BUTTON;
								else if (c == T_BACK_BUTTON)
								    event->vse_key = VSE_T_BACK_BUTTON;
								break;
							}
						}
E 10

D 10
			    /* set bit = button depressed */
E 10
I 10
						/* set bit = button depressed */
E 10

D 10
			    if (c & a)
				event->vse_direction = VSE_KBTDOWN;
			    else
				event->vse_direction = VSE_KBTUP;
			}
E 10
I 10
						if (c & a)
						    event->vse_direction = VSE_KBTDOWN;
						else
							event->vse_direction = VSE_KBTUP;
					}
E 10

D 10
			/* refresh last report */
E 10
I 10
					/* refresh last report */
E 10

D 10
			last_rep[qd] = current_rep[qd];
E 10
I 10
					last_rep[qd] = current_rep[qd];
E 10

D 10
		    } /* get last byte of report */
		} /* pick up tablet input */
E 10
I 10
				} /* get last byte of report */
			} /* pick up tablet input */
E 10

D 10
	    } /* while input available.. */
E 10
I 10
		} /* while input available.. */
E 10

D 10
	    /*---------------------
	    * do select wakeup	*/

I 6

E 6
	    if (rsel[qd] && do_wakeup && qdflags[qd].selmask & SEL_READ) {
		selwakeup(rsel[qd], 0);
		rsel[qd] = 0;
		qdflags[qd].selmask &= ~SEL_READ;
		do_wakeup = 0;
	    }
E 10
I 10
		/*
		* do select wakeup	
		*/
D 11
		if (rsel[qd] && do_wakeup && qdflags[qd].selmask & SEL_READ) {
			selwakeup(rsel[qd], 0);
			rsel[qd] = 0;
E 11
I 11
		if (qdrsel[qd] && do_wakeup && qdflags[qd].selmask & SEL_READ) {
			selwakeup(qdrsel[qd], 0);
			qdrsel[qd] = 0;
E 11
			qdflags[qd].selmask &= ~SEL_READ;
			do_wakeup = 0;
		}
E 10
D 11
	}

D 3
/*-----------------------------------------------------------------
* if the graphic device is not turned on, this is console input */
E 3
I 3
D 6
	/*-----------------------------------------------------------------
	* if the graphic device is not turned on, this is console input */
E 6
I 6
D 10
/*-----------------------------------------------------------------
* if the graphic device is not turned on, this is console input */
E 10
I 10
	/*
	* if the graphic device is not turned on, this is console input */
E 10
E 6
E 3

	else {

E 11
I 11
	} else {
		/*
		 * if the graphic device is not turned on, this is console input
		 */
E 11
D 10
	    ui = qdinfo[qd];
	    if (ui == 0 || ui->ui_alive == 0)
		return(0);
E 10
I 10
		ui = qdinfo[qd];
		if (ui == 0 || ui->ui_alive == 0)
D 11
		    return(0);
E 11
I 11
			return;
E 11
E 10

D 10
	    tp = &qd_tty[qd << 2];
E 10
I 10
		tp = &qd_tty[qd << 2];
E 10

D 10
	    /*--------------------------------------
	    * Get a character from the keyboard. */
E 10
I 10
		/*
D 11
		* Get a character from the keyboard. */
E 10

D 10
	    while ((status = duart->statusA) & RCV_RDY) {
E 10
I 10
		while ((status = duart->statusA) & RCV_RDY) {
E 10

E 11
I 11
		 * Get a character from the keyboard. 
		 */
		while (duart->statusA&RCV_RDY) {
E 11
D 10
		key = duart->dataA;
		key &= 0xFF;
E 10
I 10
			key = duart->dataA;
			key &= 0xFF;
E 10
D 11

E 11
D 10
		/*--------------------------------------
		* Check for various keyboard errors  */
E 10
I 10
			/*
D 11
			* Check for various keyboard errors  */
E 10

D 10
		if( key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
		    key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
D 3
			mprintf("\nqd%d: qdiint: Keyboard error, code = %x",qd,key);
E 3
I 3
D 6
			printf("qd%d: qdiint: Keyboard error, code = %x\n",
				qd, key);
E 6
I 6
			printf("\nqd%d: qdiint: Keyboard error, code = %x",qd,key);
E 6
E 3
			return(0);
		}
E 10
I 10
			if( key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
E 11
I 11
			* Check for various keyboard errors  
			*/
			if (key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
E 11
			    key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
D 11
				printf("\nqd%d: qdiint: Keyboard error, code = %x",qd,key);
				return(0);
E 11
I 11
				printf("qd%d: qdiint: Keyboard error, code = %x\n",qd,key);
				return;
E 11
			}
E 10

D 10
		if (key < LK_LOWEST)
		    return(0);
E 10
I 10
			if (key < LK_LOWEST)
D 11
			    return(0);
E 11
I 11
			    return;
E 11
E 10

D 10
		/*---------------------------------
		* See if its a state change key */
E 10
I 10
			/*
			* See if its a state change key */
E 10

D 10
		switch (key) {
E 10
I 10
			switch (key) {
E 10

D 10
		    case LOCK:
			q_keyboard.lock ^= 0xffff;	/* toggle */
			if (q_keyboard.lock)
			    led_control(qd, LK_LED_ENABLE, LK_LED_LOCK);
			else
			    led_control(qd, LK_LED_DISABLE, LK_LED_LOCK);
			return;
E 10
I 10
			case LOCK:
				q_keyboard.lock ^= 0xffff;	/* toggle */
				if (q_keyboard.lock)
D 11
				    led_control(qd, LK_LED_ENABLE, LK_LED_LOCK);
E 11
I 11
					(void)led_control(qd, LK_LED_ENABLE,
							  LK_LED_LOCK);
E 11
				else
D 11
					led_control(qd, LK_LED_DISABLE, LK_LED_LOCK);
E 11
I 11
					(void)led_control(qd, LK_LED_DISABLE,
							  LK_LED_LOCK);
E 11
				return;
E 10

D 10
		    case SHIFT:
			q_keyboard.shift ^= 0xFFFF;
			return;
E 10
I 10
			case SHIFT:
				q_keyboard.shift ^= 0xFFFF;
				return;
E 10

D 10
		    case CNTRL:
			q_keyboard.cntrl ^= 0xFFFF;
			return;
E 10
I 10
			case CNTRL:
				q_keyboard.cntrl ^= 0xFFFF;
				return;
E 10

D 10
		    case ALLUP:
			q_keyboard.cntrl = 0;
			q_keyboard.shift = 0;
			return;
E 10
I 10
			case ALLUP:
				q_keyboard.cntrl = 0;
				q_keyboard.shift = 0;
				return;
E 10

D 10
		    case REPEAT:
			chr = q_keyboard.last;
			break;
E 10
I 10
			case REPEAT:
				chr = q_keyboard.last;
				break;
E 10

D 10
		    /*-------------------------------------------------------
		    * Test for cntrl characters. If set, see if the character
		    * is elligible to become a control character. */
E 10
I 10
				/*
				* Test for cntrl characters. If set, see if the character
				* is elligible to become a control character. */
E 10

D 10
		    default:
E 10
I 10
			default:
E 10

D 10
			if (q_keyboard.cntrl) {
				chr = q_key[key];
				if (chr >= ' ' && chr <= '~')
				    chr &= 0x1F;
I 6
				else if (chr >= 0xA1 && chr <= 0xFE)
				    chr &= 0x9F;
E 10
I 10
				if (q_keyboard.cntrl) {
					chr = q_key[key];
					if (chr >= ' ' && chr <= '~')
					    chr &= 0x1F;
					else if (chr >= 0xA1 && chr <= 0xFE)
					    chr &= 0x9F;
				}
				else if( q_keyboard.lock || q_keyboard.shift )
				    chr = q_shift_key[key];
				else
					chr = q_key[key];
				break;
E 10
E 6
			}
D 10
			else if( q_keyboard.lock || q_keyboard.shift )
			    chr = q_shift_key[key];
			else
			    chr = q_key[key];
			break;
		}
E 10

D 10
		q_keyboard.last = chr;
E 10
I 10
			q_keyboard.last = chr;
E 10

D 10
		/*-----------------------------------
		* Check for special function keys */
E 10
I 10
			/*
			* Check for special function keys */
E 10

D 6
		if (chr & 0x80) {
E 6
I 6
D 10
		if (chr & 0x100) {
E 6
			char *string;
			string = q_special[chr & 0x7F];
			while(*string)
			    (*linesw[tp->t_line].l_rint)(*string++, tp);
		}
		else {
I 6
#ifdef notdef	/* notneeded */
			if (tp->t_iflag & ISTRIP)	/* Strip to 7 bits. */
				c &= 0177;	
			else {			/* Take the full 8-bits */
				/* If ISTRIP is not set a valid character of 377
			 	* is read as 0377,0377 to avoid ambiguity with
			 	* the PARMARK sequence.
			 	*/ 
				if ((c == 0377) && (tp->t_line == TERMIODISC))
					(*linesw[tp->t_line].l_rint)(0377,tp);
			
E 10
I 10
D 14
			if (chr & 0x100) {
E 14
I 14
			if (chr & 0x80) {
E 14
				char *string;
				string = q_special[chr & 0x7F];
				while(*string)
				    (*linesw[tp->t_line].l_rint)(*string++, tp);
E 10
			}
D 10
#endif /*notdef*/
E 6
			(*linesw[tp->t_line].l_rint)(chr, tp);
E 10
I 10
			else {
				(*linesw[tp->t_line].l_rint)(chr&0177, tp);
			}
E 10
		}
D 10
	    }
E 10
	}
D 11

I 6
D 10
/*----------------------
* cleanup and exit  */
E 10
I 10
	/*
	* cleanup and exit  */
E 10

E 6
D 2
/*----------------------
* cleanup and exit  */

E 2
	return(0);

E 11
} /* qdiint */

D 11
/******************************************************************
I 6
*******************************************************************
*******************************************************************
E 6
D 2
*******************************************************************
*******************************************************************
E 2
*
*	THE SUBROUTINES START HERE:
*
******************************************************************/

/*****************************************************************
*
*	clear_qd_screen()... clear the QDSS screen
*
******************************************************************
*
*			     >>> NOTE <<<
*
*   This code requires that certain adder initialization be valid.  To
*   assure that this requirement is satisfied, this routine should be
*   called only after calling the "setup_dragon()" function.
*
*   Clear the bitmap a piece at a time. Since the fast scroll clear
*   only clears the current displayed portion of the bitmap put a
*   temporary value in the y limit register so we can access whole
*   bitmap
*
****************/

E 11
I 11
/*
 *
 * Clear the QDSS screen
 *
 *			     >>> NOTE <<<
 *
 *   This code requires that certain adder initialization be valid.  To
 *   assure that this requirement is satisfied, this routine should be
 *   called only after calling the "setup_dragon()" function.
 *
 *   Clear the bitmap a piece at a time. Since the fast scroll clear
 *   only clears the current displayed portion of the bitmap put a
 *   temporary value in the y limit register so we can access whole
 *   bitmap
 *
 */
E 11
clear_qd_screen(unit)
D 11
int unit;
E 11
I 11
	int unit;
E 11
{
	register struct adder *adder;
	adder = (struct adder *) qdmap[unit].adder;

	adder->x_limit = 1024;
	adder->y_limit = 2048 - CHAR_HEIGHT;
	adder->y_offset_pending = 0;
D 10

	wait_status(adder, VSYNC);	/* wait at LEAST 1 full frame */
	wait_status(adder, VSYNC);

E 10
I 10
D 11
#define WSV	wait_status(adder, VSYNC); wait_status(adder, VSYNC)
E 11
I 11
#define WSV  (void)wait_status(adder, VSYNC); (void)wait_status(adder, VSYNC)
E 11
	WSV;
E 10
	adder->y_scroll_constant = SCROLL_ERASE;
D 10

	wait_status(adder, VSYNC);
	wait_status(adder, VSYNC);

E 10
I 10
	WSV;
E 10
	adder->y_offset_pending = 864;
D 10

	wait_status(adder, VSYNC);
	wait_status(adder, VSYNC);

E 10
I 10
	WSV;
E 10
	adder->y_scroll_constant = SCROLL_ERASE;
D 10

	wait_status(adder, VSYNC);
	wait_status(adder, VSYNC);

E 10
I 10
	WSV;
E 10
	adder->y_offset_pending = 1728;
D 10

	wait_status(adder, VSYNC);
	wait_status(adder, VSYNC);

E 10
I 10
	WSV;
E 10
	adder->y_scroll_constant = SCROLL_ERASE;
D 10

	wait_status(adder, VSYNC);
	wait_status(adder, VSYNC);

E 10
I 10
	WSV;
E 10
	adder->y_offset_pending = 0;	 /* back to normal */
D 10

	wait_status(adder, VSYNC);
	wait_status(adder, VSYNC);

E 10
I 10
	WSV;
E 10
	adder->x_limit = MAX_SCREEN_X;
	adder->y_limit = MAX_SCREEN_Y + FONT_HEIGHT;
I 10
#undef WSV
E 10

} /* clear_qd_screen */

D 11
/**********************************************************************
*
D 10
*	qdputc()... route kernel console output to display destination
E 10
I 10
*	qdputc()... route kernel console output to the glass tty
E 10
*
***********************************************************************
*
*	calling convention:
*
*		qdputc(chr);
*
*	where:	char chr;	 ;character for output
*
****************/

E 11
I 11
/*
 *  kernel console output to the glass tty
 */
E 11
qdputc(chr)
D 10
register char chr;
E 10
I 10
	register char chr;
E 10
{
I 6
D 10
	register struct tty *tp0;
E 10
E 6
D 2
	register struct tty *tp0;
E 2

D 2
/*---------------------------------------------------------
* if system is now physical, forget it (ie: crash DUMP) */

E 2
I 2
D 6
	/* if system is now physical, forget it (ie: crash DUMP) */
E 6
I 6
D 10
/*---------------------------------------------------------
* if system is now physical, forget it (ie: crash DUMP) */
E 10
I 10
	/*
	 * if system is now physical, forget it (ie: crash DUMP) 
	 */
	if ((mfpr(MAPEN) & 1) == 0)
		return;
E 10

E 6
E 2
D 10
	if ( (mfpr(MAPEN) & 1) == 0 )
	    return;

D 2
/*--------------------------------------------------
* direct kernel output char to the proper place  */
E 2
I 2
D 6
        blitc(0, chr & 0xff);
E 6
I 6
/*--------------------------------------------------
* direct kernel output char to the proper place  */

#ifdef notdef	/* never */
	tp0 = &qd_tty[1];

	if (qdflags[0].kernel_loop != 0  &&  tp0->t_state & TS_ISOPEN) {
	    (*linesw[tp0->t_line].l_rint)(chr, tp0);
	} else {
	    blitc(0, chr & 0xff);
	}
#endif /*notdef*/
E 10
D 11
	blitc(0, chr & 0xff);
E 11
I 11
	blitc(0, (u_char)(chr & 0xff));
E 11
E 6
	if ((chr & 0177) == '\n')
		blitc(0, '\r');
E 2

D 2
	tp0 = &qd_tty[1];
E 2
D 10

E 10
D 2
	if (qdflags[0].kernel_loop != 0  &&  tp0->t_state & TS_ISOPEN) {
	    (*linesw[tp0->t_line].l_rint)(chr, tp0);
	} else {
	    blitc(0, chr & 0xff);
	}

E 2
} /* qdputc */

D 11
/*******************************************************************
*
*	qdgetc()... get a character from the LK201
*
*******************************************************************
*
*	calling convention:
*
*		qdgetc();
*
*	returns:  the character read.
*
****************/

qdgetc()
{
	register short key;
	register char chr;
	register struct duart *duart;

	u_int status;

	duart = (struct duart *) qdmap[0].duart;

D 10
	/*--------------------------------------
E 10
I 10
	/*
E 10
	* Get a character from the keyboard. */

I 10
LOOP:
	while (!((status = duart->statusA) & RCV_RDY))
	    ;

	key = duart->dataA;
	key &= 0xFF;

	/*
	* Check for various keyboard errors  */

	if (key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
	    key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
		printf("Keyboard error, code = %x\n", key);
		return(0);
	}

	if (key < LK_LOWEST)
	    return(0);

	/*
	* See if its a state change key */

	switch (key) {

	case LOCK:
		q_keyboard.lock ^= 0xffff;	/* toggle */
		if (q_keyboard.lock)
		    led_control(LK_LED_ENABLE, LK_LED_LOCK);
		else
			led_control(LK_LED_DISABLE, LK_LED_LOCK);
		goto LOOP;

	case SHIFT:
		q_keyboard.shift ^= 0xFFFF;
		goto LOOP;

	case CNTRL:
		q_keyboard.cntrl ^= 0xFFFF;
		goto LOOP;

	case ALLUP:
		q_keyboard.cntrl = 0;
		q_keyboard.shift = 0;
		goto LOOP;

	case REPEAT:
		chr = q_keyboard.last;
		break;

		/*
		* Test for cntrl characters. If set, see if the character
		* is elligible to become a control character. */

	default:

		if (q_keyboard.cntrl) {
			chr = q_key[key];
			if (chr >= ' ' && chr <= '~')
			    chr &= 0x1F;
		}
		else if ( q_keyboard.lock || q_keyboard.shift )
		    chr = q_shift_key[key];
		else
			chr = q_key[key];
		break;
	}

	if (chr < ' ' && chr > '~')	/* if input is non-displayable */
		return(0);		/* ..then pitch it! */

	q_keyboard.last = chr;

	/*
	* Check for special function keys */

	if (chr & 0x80) 		/* pitch the function keys */
		return(0);
	else
		return(chr);

} /* qdgetc */

/**********************************************************************
*
*	ldcursor()... load the mouse cursor's template RAM bitmap
*
*********************************************************************
*
*	calling convention:
*
*		ldcursor(unit, bitmap);
*		u_int unit;
*		short *bitmap;
*
****************/

E 11
I 11
/*
 *  load the mouse cursor's template RAM bitmap
 */
E 11
ldcursor(unit, bitmap)
D 11
	u_int unit;
	short *bitmap;
E 11
I 11
	int unit;
	register short *bitmap;
E 11
{
	register struct dga *dga;
	register short *temp;
	register int i;
I 11
	int curs;
E 11

D 11
	int cursor;

E 11
	dga = (struct dga *) qdmap[unit].dga;
	temp = (short *) qdmap[unit].template;

	if (dga->csr & CURS_ENB) {	/* if the cursor is enabled.. */
D 11
		cursor = -1;		/* ..note that.. */
E 11
I 11
		curs = -1;		/* ..note that.. */
E 11
		dga->csr &= ~CURS_ENB;	/* ..and shut it off */
D 11
	}
	else {
		cursor = 0;
	}
E 11
I 11
	} else 
		curs = 0;
E 11

	dga->csr &= ~CURS_ENB;		/* shut off the cursor */

	temp += (8 * 1024) - 32;	/* cursor is 32 WORDS from the end */
	/* ..of the 8k WORD template space */
	for (i = 0; i < 32; ++i)
		*temp++ = *bitmap++;

D 11
	if (cursor) {			/* if cursor was enabled.. */
E 11
I 11
	if (curs) {			/* if cursor was enabled.. */
E 11
		dga->csr |= CURS_ENB;	/* ..turn it back on */
	}

D 11
	return(0);

E 11
} /* ldcursor */

D 11
/**********************************************************************
*
*	ldfont()... put the console font in the QDSS off-screen memory
*
***********************************************************************
*
*	calling convention:
*
*		ldfont(unit);
*		u_int unit;	;QDSS unit number
*
****************/

E 11
I 11
/*
 *  Put the console font in the QDSS off-screen memory
 */
E 11
ldfont(unit)
D 11
	u_int unit;
E 11
I 11
	int unit;
E 11
{
	register struct adder *adder;

D 11
	int i;		/* scratch variables */
	int j;
	int k;
	short packed;
	int max_chars_line;
E 11
I 11
	register i, j, k, max_chars_line;
	register short packed;
E 11

	adder = (struct adder *) qdmap[unit].adder;

	/*
D 11
	* setup VIPER operand control registers  */

E 11
I 11
	* setup VIPER operand control registers  
	*/
E 11
	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 255);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);

	write_ID(adder, SRC1_OCR_B,
	EXT_NONE | INT_NONE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, SRC2_OCR_B,
	EXT_NONE | INT_NONE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
	EXT_SOURCE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);

	adder->rasterop_mode = DST_WRITE_ENABLE | DST_INDEX_ENABLE | NORMAL;

	/*
D 11
	* load destination data  */
E 11
I 11
	* load destination data  
	*/
	(void)wait_status(adder, RASTEROP_COMPLETE);
E 11

D 11
	wait_status(adder, RASTEROP_COMPLETE);

E 11
	adder->destination_x = FONT_X;
	adder->destination_y = FONT_Y;
D 11
	if (FONT_WIDTH > MAX_SCREEN_X)
	    adder->fast_dest_dx = MAX_SCREEN_X;
	else
		adder->fast_dest_dx = FONT_WIDTH;
E 11
I 11
#if FONT_WIDTH > MAX_SCREEN_X
	adder->fast_dest_dx = MAX_SCREEN_X;
#else
	adder->fast_dest_dx = FONT_WIDTH;
#endif
E 11
	adder->slow_dest_dy = CHAR_HEIGHT;

	/*
	* setup for processor to bitmap xfer  */

	write_ID(adder, CS_UPDATE_MASK, 0x0001);
	adder->cmd = PBT | OCRB | 2 | DTE | 2;

	/*
	* Figure out how many characters can be stored on one "line" of 
	* offscreen memory.
	*/
	max_chars_line = MAX_SCREEN_X/(CHAR_WIDTH*2);
	if ((CHARS/2 + CHARS%2) < max_chars_line)
	    max_chars_line = CHARS/2 + CHARS%2;

	/*
	* iteratively do the processor to bitmap xfer */

	for (i = 0; i < ROWS; ++i) {

		/* PTOB a scan line */

		for (j = 0, k = i; j < max_chars_line; ++j) {
			/* PTOB one scan of a char cell */

			packed = q_font[k];
			k += ROWS;
			packed |= ((short)q_font[k] << 8);
			k += ROWS;

D 11
			wait_status(adder, TX_READY);
E 11
I 11
			(void)wait_status(adder, TX_READY);
E 11
			adder->id_data = packed;
		}
	}

	/*
	 * (XXX XXX XXX - should remove)
	 *
	 * Copy the second row of characters.  Subtract the first
	 * row from the total number.  Divide this quantity by 2
	 * because 2 chars are stored in a short in the PTOB loop
	 * below.  Figure out how many characters can be stored on
	 * one "line" of offscreen memory 
	 */

	max_chars_line = MAX_SCREEN_X/(CHAR_WIDTH*2);
	if ((CHARS/2 + CHARS%2) < max_chars_line)
	    return;
	max_chars_line = (CHARS/2 + CHARS%2) - max_chars_line; /* 95 - 64 */
	/* Paranoia check to see if 3rd row may be needed */
	if (max_chars_line > (MAX_SCREEN_X/(CHAR_WIDTH*2)))
	    max_chars_line = MAX_SCREEN_X/(CHAR_WIDTH*2);

	adder->destination_x = FONT_X;
	adder->destination_y = FONT_Y - CHAR_HEIGHT;
	adder->fast_dest_dx = max_chars_line * CHAR_WIDTH * 2;
	adder->slow_dest_dy = CHAR_HEIGHT;

	/*
	* setup for processor to bitmap xfer  
	*/
	write_ID(adder, CS_UPDATE_MASK, 0x0001);
	adder->cmd = PBT | OCRB | 2 | DTE | 2;

	/*
	* iteratively do the processor to bitmap xfer 
	*/
	for (i = 0; i < ROWS; ++i) {
		/* 
		 * PTOB a scan line 
		 */
		for (j = 0, k = i; j < max_chars_line; ++j) {
			/*
			 * PTOB one scan of a char cell 
			 */
			packed = q_font[k + FONT_OFFSET];
			k += ROWS;
			packed |= ((short)q_font[k + FONT_OFFSET] << 8);
			k += ROWS;
D 11
			wait_status(adder, TX_READY);
E 11
I 11
			(void)wait_status(adder, TX_READY);
E 11
			adder->id_data = packed;
		}
	}

}  /* ldfont */

D 11
/*********************************************************************
*
*	led_control()... twiddle LK-201 LED's
*
**********************************************************************
*
*	led_control(unit, cmd, led_mask);
*	u_int unit;	QDSS number
*	int cmd;	LED enable/disable command
*	int led_mask;	which LED(s) to twiddle
*
*************/
E 11
I 11
/*
 *  Get a character from the LK201 (polled)
 */
qdgetc()
{
	register short key;
	register char chr;
	register struct duart *duart;
E 11

I 11
	duart = (struct duart *) qdmap[0].duart;

	/*
	* Get a character from the keyboard. 
	*/
LOOP:
	while (!(duart->statusA&RCV_RDY))
		;

	key = duart->dataA;
	key &= 0xFF;

	/*
	* Check for various keyboard errors  */

	if (key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
	    key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
		printf("Keyboard error, code = %x\n", key);
		return(0);
	}

	if (key < LK_LOWEST)
		return(0);

	/*
	 * See if its a state change key 
	 */
	switch (key) {

	case LOCK:
		q_keyboard.lock ^= 0xffff;	/* toggle */
		if (q_keyboard.lock)
			(void)led_control(0, LK_LED_ENABLE, LK_LED_LOCK);
		else
			(void)led_control(0, LK_LED_DISABLE, LK_LED_LOCK);
		goto LOOP;

	case SHIFT:
		q_keyboard.shift ^= 0xFFFF;
		goto LOOP;

	case CNTRL:
		q_keyboard.cntrl ^= 0xFFFF;
		goto LOOP;

	case ALLUP:
		q_keyboard.cntrl = 0;
		q_keyboard.shift = 0;
		goto LOOP;

	case REPEAT:
		chr = q_keyboard.last;
		break;

		/*
		* Test for cntrl characters. If set, see if the character
		* is elligible to become a control character. 
		*/
	default:

		if (q_keyboard.cntrl) {
			chr = q_key[key];
			if (chr >= ' ' && chr <= '~')
			    chr &= 0x1F;
		}
		else if ( q_keyboard.lock || q_keyboard.shift )
		    chr = q_shift_key[key];
		else
			chr = q_key[key];
		break;
	}

	if (chr < ' ' && chr > '~')	/* if input is non-displayable */
		return(0);		/* ..then pitch it! */

	q_keyboard.last = chr;

	/*
	* Check for special function keys */

	if (chr & 0x80) 		/* pitch the function keys */
		return(0);
	else
		return(chr);

} /* qdgetc */

/*
 *  led_control()... twiddle LK-201 LED's
 */
E 11
led_control(unit, cmd, led_mask)
D 11
	u_int unit;
	int cmd;
	int led_mask;
E 11
I 11
	int unit, cmd, led_mask;
E 11
{
D 11
	register int i;
	register int status;
E 11
I 11
	register i;
E 11
	register struct duart *duart;

D 11
	duart = (struct duart *) qdmap[unit].duart;
E 11
I 11
	duart = (struct duart *)qdmap[unit].duart;
E 11

	for (i = 1000; i > 0; --i) {
D 11
		if ((status = duart->statusA) & XMT_RDY) {
E 11
I 11
		if (duart->statusA&XMT_RDY) {
E 11
			duart->dataA = cmd;
			break;
		}
	}
	for (i = 1000; i > 0; --i) {
D 11
		if ((status = duart->statusA) & XMT_RDY) {
E 11
I 11
		if (duart->statusA&XMT_RDY) {
E 11
			duart->dataA = led_mask;
			break;
		}
	}
	if (i == 0)
		return(BAD);
	return(GOOD);

} /* led_control */

D 11
/*******************************************************************
*
*	scroll_up()... move the screen up one character height
*
********************************************************************
*
*	calling convention:
*
*		scroll_up(adder);
*		struct adder *adder;	;address of adder
*
********/

E 11
I 11
/*
 *  scroll_up()... move the screen up one character height
 */
E 11
scroll_up(adder)
	register struct adder *adder;
{
	/*
	* setup VIPER operand control registers  
	*/
D 11
	wait_status(adder, ADDRESS_COMPLETE);
E 11
I 11
	(void)wait_status(adder, ADDRESS_COMPLETE);
E 11
	write_ID(adder, CS_UPDATE_MASK, 0x00FF);  /* select all planes */
	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 255);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);
	write_ID(adder, SRC1_OCR_B,
	EXT_NONE | INT_SOURCE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
	EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);
	/*
	 * load DESTINATION origin and vectors  
	 */
	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->error_1 = 0;
	adder->error_2 = 0;
	adder->rasterop_mode = DST_WRITE_ENABLE | NORMAL;
	adder->destination_x = 0;
	adder->fast_dest_dx = 1024;
	adder->destination_y = 0;
	adder->slow_dest_dy = 864 - CHAR_HEIGHT;
	/*
	 * load SOURCE origin and vectors  
	 */
	adder->source_1_x = 0;
	adder->source_1_dx = 1024;
	adder->source_1_y = 0 + CHAR_HEIGHT;
	adder->source_1_dy = 864 - CHAR_HEIGHT;
	write_ID(adder, LU_FUNCTION_R1, FULL_SRC_RESOLUTION | LF_SOURCE);
	adder->cmd = RASTEROP | OCRB | 0 | S1E | DTE;
	/*
	 * do a rectangle clear of last screen line 
	 */
	write_ID(adder, MASK_1, 0xffff);
	write_ID(adder, SOURCE, 0xffff);
	write_ID(adder,DST_OCR_B,
	(EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY));
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 0);
	adder->error_1 = 0;
	adder->error_2 = 0;
	adder->slow_dest_dx = 0;		/* set up the width of	*/
	adder->slow_dest_dy = CHAR_HEIGHT;	/* rectangle */
	adder->rasterop_mode = (NORMAL | DST_WRITE_ENABLE) ;
D 11
	wait_status(adder, RASTEROP_COMPLETE);
E 11
I 11
	(void)wait_status(adder, RASTEROP_COMPLETE);
E 11
	adder->destination_x = 0;
	adder->destination_y = 864 - CHAR_HEIGHT;
	adder->fast_dest_dx = 1024;	/* set up the height	*/
	adder->fast_dest_dy = 0;	/* of rectangle 	*/
	write_ID(adder, LU_FUNCTION_R2, (FULL_SRC_RESOLUTION | LF_SOURCE));
	adder->cmd = (RASTEROP | OCRB | LF_R2 | DTE ) ;

} /* scroll_up */

D 11
/********************************************************************
*
*	init_shared()... init shared memory pointers and structures
*
*********************************************************************
*
*	calling convention:
*
*		init_shared(unit);
*		u_int unit;
*
****************/

E 11
I 11
/*
 *  init shared memory pointers and structures
 */
E 11
init_shared(unit)
D 11
	register u_int unit;
E 11
I 11
	register unit;
E 11
{
	register struct dga *dga;

	dga = (struct dga *) qdmap[unit].dga;

	/*
	* initialize the event queue pointers and header */

	eq_header[unit] = (struct qdinput *)
	    ((((int)event_shared & ~(0x01FF)) + 512)
		+ (EVENT_BUFSIZE * unit));
	eq_header[unit]->curs_pos.x = 0;
	eq_header[unit]->curs_pos.y = 0;
	dga->x_cursor = TRANX(eq_header[unit]->curs_pos.x);
	dga->y_cursor = TRANY(eq_header[unit]->curs_pos.y);
	eq_header[unit]->curs_box.left = 0;
	eq_header[unit]->curs_box.right = 0;
	eq_header[unit]->curs_box.top = 0;
	eq_header[unit]->curs_box.bottom = 0;
	/*
	 * assign a pointer to the DMA I/O buffer for this QDSS. 
	 */
	DMAheader[unit] = (struct DMAreq_header *)
	    (((int)(&DMA_shared[0] + 512) & ~0x1FF)
		+ (DMAbuf_size * unit));
	DMAheader[unit]->DMAreq = (struct DMAreq *) ((int)DMAheader[unit]
	    + sizeof(struct DMAreq_header));
	DMAheader[unit]->QBAreg = 0;
	DMAheader[unit]->status = 0;
	DMAheader[unit]->shared_size = DMAbuf_size;
	DMAheader[unit]->used = 0;
	DMAheader[unit]->size = 10;	/* default = 10 requests */
	DMAheader[unit]->oldest = 0;
	DMAheader[unit]->newest = 0;
	/*
	* assign a pointer to the scroll structure for this QDSS. 
	*/
	scroll[unit] = (struct scroll *)
	    (((int)(&scroll_shared[0] + 512) & ~0x1FF)
		+ (sizeof(struct scroll) * unit));
	scroll[unit]->status = 0;
	scroll[unit]->viper_constant = 0;
	scroll[unit]->y_scroll_constant = 0;
	scroll[unit]->y_offset = 0;
	scroll[unit]->x_index_pending = 0;
	scroll[unit]->y_index_pending = 0;
	/*
	* assign a pointer to the color map write buffer for this QDSS 
	*/
	color_buf[unit] = (struct color_buf *)
	    (((int)(&color_shared[0] + 512) & ~0x1FF)
		+ (COLOR_BUFSIZ * unit));
	color_buf[unit]->status = 0;
	color_buf[unit]->count = 0;

} /* init_shared */

D 11
/*********************************************************************
*
*	setup_dragon()... init the ADDER, VIPER, bitmaps, & color map
*
**********************************************************************
*
*	calling convention:
*
*		setup_dragon();
*
*	return: NONE
*
************************/

E 11
I 11
/*
 * init the ADDER, VIPER, bitmaps, & color map
 */
E 11
setup_dragon(unit)
D 11
	u_int unit;
E 11
I 11
	int unit;
E 11
{

	register struct adder *adder;
	register struct dga *dga;
	short *memcsr;
D 11
	int i;			/* general purpose variables */
	int status;
E 11
I 11
	register i;
E 11
	short top;		/* clipping/scrolling boundaries */
	short bottom;
	short right;
	short left;
	short *red;		/* color map pointers */
	short *green;
	short *blue;

	/*
	* init for setup 
	*/
	adder = (struct adder *) qdmap[unit].adder;
	dga = (struct dga *) qdmap[unit].dga;
	memcsr = (short *) qdmap[unit].memcsr;
	dga->csr &= ~(DMA_IE | 0x700);	/* halt DMA and kill the intrpts */
	*memcsr = SYNC_ON;		/* blank screen and turn off LED's */
	adder->command = CANCEL;
	/*
	* set monitor timing 
	*/
	adder->x_scan_count_0 = 0x2800;
	adder->x_scan_count_1 = 0x1020;
	adder->x_scan_count_2 = 0x003A;
	adder->x_scan_count_3 = 0x38F0;
	adder->x_scan_count_4 = 0x6128;
	adder->x_scan_count_5 = 0x093A;
	adder->x_scan_count_6 = 0x313C;
	adder->sync_phase_adj = 0x0100;
	adder->x_scan_conf = 0x00C8;
	/*
	 * got a bug in secound pass ADDER! lets take care of it 
	 *
	 * normally, just use the code in the following bug fix code, but to
	 * make repeated demos look pretty, load the registers as if there was
	 * no bug and then test to see if we are getting sync 
	 */
	adder->y_scan_count_0 = 0x135F;
	adder->y_scan_count_1 = 0x3363;
	adder->y_scan_count_2 = 0x2366;
	adder->y_scan_count_3 = 0x0388;
	/*
	 * if no sync, do the bug fix code 
	 */
	if (wait_status(adder, VSYNC) == BAD) {
		/* first load all Y scan registers with very short frame and
		 * wait for scroll service.  This guarantees at least one SYNC
		 * to fix the pass 2 Adder initialization bug (synchronizes
		 * XCINCH with DMSEEDH) 
		 */
		adder->y_scan_count_0 = 0x01;
		adder->y_scan_count_1 = 0x01;
		adder->y_scan_count_2 = 0x01;
		adder->y_scan_count_3 = 0x01;
		/*
		 * delay at least 1 full frame time 
		 */
D 11
		wait_status(adder, VSYNC);	
		wait_status(adder, VSYNC);
E 11
I 11
		(void)wait_status(adder, VSYNC);	
		(void)wait_status(adder, VSYNC);
E 11
		/*
		 * now load the REAL sync values (in reverse order just to
		 * be safe.  
		 */
		adder->y_scan_count_3 = 0x0388;
		adder->y_scan_count_2 = 0x2366;
		adder->y_scan_count_1 = 0x3363;
		adder->y_scan_count_0 = 0x135F;
	}
	*memcsr = SYNC_ON | UNBLANK;	/* turn off leds and turn on video */
	/*
	 * zero the index registers 
	 */
	adder->x_index_pending = 0;
	adder->y_index_pending = 0;
	adder->x_index_new = 0;
	adder->y_index_new = 0;
	adder->x_index_old = 0;
	adder->y_index_old = 0;
	adder->pause = 0;
	/*
	 * set rasterop mode to normal pen down 
	 */
	adder->rasterop_mode = DST_WRITE_ENABLE | DST_INDEX_ENABLE | NORMAL;
	/*
	 * set the rasterop registers to a default values 
	 */
	adder->source_1_dx = 1;
	adder->source_1_dy = 1;
	adder->source_1_x = 0;
	adder->source_1_y = 0;
	adder->destination_x = 0;
	adder->destination_y = 0;
	adder->fast_dest_dx = 1;
	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->slow_dest_dy = 1;
	adder->error_1 = 0;
	adder->error_2 = 0;
	/*
D 11
	 * scale factor = unity 
E 11
I 11
	 * scale factor = UNITY 
E 11
	 */
	adder->fast_scale = UNITY;
	adder->slow_scale = UNITY;
	/*
	 * set the source 2 parameters 
	 */
	adder->source_2_x = 0;
E 10
D 10
LOOP:
	while (!((status = duart->statusA) & RCV_RDY))
			;

	key = duart->dataA;
	key &= 0xFF;
D 6

	/*--------------------------------------
	* Check for various keyboard errors  */

	if( key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
	    key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
		printf("Keyboard error, code = %x\n", key);
		return(0);
	}

	if (key < LK_LOWEST)
	    return(0);

	/*---------------------------------
	* See if its a state change key */

	switch (key) {

	    case LOCK:
		q_keyboard.lock ^= 0xffff;	/* toggle */
		if (q_keyboard.lock)
		    led_control(LK_LED_ENABLE, LK_LED_LOCK);
		else
		    led_control(LK_LED_DISABLE, LK_LED_LOCK);
		goto LOOP;

	    case SHIFT:
		q_keyboard.shift ^= 0xFFFF;
		goto LOOP;

	    case CNTRL:
		q_keyboard.cntrl ^= 0xFFFF;
		goto LOOP;

	    case ALLUP:
		q_keyboard.cntrl = 0;
		q_keyboard.shift = 0;
		goto LOOP;

	    case REPEAT:
		chr = q_keyboard.last;
		break;

	    /*-------------------------------------------------------
	    * Test for cntrl characters. If set, see if the character
	    * is elligible to become a control character. */

	    default:

		if (q_keyboard.cntrl) {
		    chr = q_key[key];
		    if (chr >= ' ' && chr <= '~')
			chr &= 0x1F;
		}
		else if ( q_keyboard.lock || q_keyboard.shift )
		    chr = q_shift_key[key];
		else
		    chr = q_key[key];
		break;
	}

	if (chr < ' ' && chr > '~')	/* if input is non-displayable */
	    return(0);			/* ..then pitch it! */

	q_keyboard.last = chr;

	/*-----------------------------------
	* Check for special function keys */

	if (chr & 0x80) 		/* pitch the function keys */
	    return(0);
	else
	    return(chr);

} /* qdgetc */

/**********************************************************************
*
*	ldcursor()... load the mouse cursor's template RAM bitmap
*
*********************************************************************
*
*	calling convention:
*
*		ldcursor(unit, bitmap);
*		u_int unit;
*		short *bitmap;
*
****************/

ldcursor(unit, bitmap)
u_int unit;
short *bitmap;
{
	register struct dga *dga;
	register short *temp;
	register int i;

	int cursor;

	dga = (struct dga *) qdmap[unit].dga;
	temp = (short *) qdmap[unit].template;

	if (dga->csr & CURS_ENB) {	/* if the cursor is enabled.. */
	    cursor = -1;		/* ..note that.. */
	    dga->csr &= ~CURS_ENB;	/* ..and shut it off */
	}
	else {
	    cursor = 0;
	}

	dga->csr &= ~CURS_ENB;		/* shut off the cursor */

	temp += (8 * 1024) - 32;	/* cursor is 32 WORDS from the end */
					/* ..of the 8k WORD template space */
	for (i = 0; i < 32; ++i)
	    *temp++ = *bitmap++;

	if (cursor) {			/* if cursor was enabled.. */
	    dga->csr |= CURS_ENB;	/* ..turn it back on */
	}

	return(0);

} /* ldcursor */

/**********************************************************************
*
*	ldfont()... put the console font in the QDSS off-screen memory
*
***********************************************************************
*
*	calling convention:
*
*		ldfont(unit);
*		u_int unit;	;QDSS unit number
*
****************/

ldfont(unit)
u_int unit;
{
	register struct adder *adder;

	int i;		/* scratch variables */
	int j;
	int k;
	short packed;

	adder = (struct adder *) qdmap[unit].adder;

D 3
/*------------------------------------------
* setup VIPER operand control registers  */
E 3
I 3
	/*------------------------------------------
	* setup VIPER operand control registers  */
E 3

	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 255);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);

	write_ID(adder, SRC1_OCR_B,
			EXT_NONE | INT_NONE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, SRC2_OCR_B,
			EXT_NONE | INT_NONE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
			EXT_SOURCE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);

	adder->rasterop_mode = DST_WRITE_ENABLE | DST_INDEX_ENABLE | NORMAL;

D 3
/*--------------------------
* load destination data  */
E 3
I 3
	/*--------------------------
	* load destination data  */
E 3

	wait_status(adder, RASTEROP_COMPLETE);

	adder->destination_x = FONT_X;
	adder->destination_y = FONT_Y;
	adder->fast_dest_dx = FONT_WIDTH;
	adder->slow_dest_dy = CHAR_HEIGHT;

D 3
/*---------------------------------------
* setup for processor to bitmap xfer  */
E 3
I 3
	/*---------------------------------------
	* setup for processor to bitmap xfer  */
E 3

	write_ID(adder, CS_UPDATE_MASK, 0x0001);
	adder->cmd = PBT | OCRB | 2 | DTE | 2;

D 3
/*-----------------------------------------------
* iteratively do the processor to bitmap xfer */
E 3
I 3
	/*-----------------------------------------------
	* iteratively do the processor to bitmap xfer */
E 3

	for (i = 0; i < ROWS; ++i) {

	    /* PTOB a scan line */

	    for (j = 0, k = i; j < 48; ++j) {

		/* PTOB one scan of a char cell */

		packed = q_font[k];
		k += ROWS;
		packed |= ((short)q_font[k] << 8);
		k += ROWS;

		wait_status(adder, TX_READY);
		adder->id_data = packed;
	    }
	}

}  /* ldfont */

/*********************************************************************
*
*	led_control()... twiddle LK-201 LED's
*
**********************************************************************
*
*	led_control(unit, cmd, led_mask);
*	u_int unit;	QDSS number
*	int cmd;	LED enable/disable command
*	int led_mask;	which LED(s) to twiddle
*
*************/

led_control(unit, cmd, led_mask)
u_int unit;
int cmd;
int led_mask;
{
	register int i;
	register int status;
	register struct duart *duart;

	duart = (struct duart *) qdmap[unit].duart;

	for (i = 1000; i > 0; --i) {
	    if ((status = duart->statusA) & XMT_RDY) {
		duart->dataA = cmd;
		break;
	    }
	}

	for (i = 1000; i > 0; --i) {
	    if ((status = duart->statusA) & XMT_RDY) {
		duart->dataA = led_mask;
		break;
	    }
	}

	if (i == 0)
	    return(BAD);

	return(GOOD);

} /* led_control */

/*******************************************************************
*
*	scroll_up()... move the screen up one character height
*
********************************************************************
*
*	calling convention:
*
*		scroll_up(adder);
*		struct adder *adder;	;address of adder
*
********/

scroll_up(adder)
register struct adder *adder;
{

D 3
/*------------------------------------------
* setup VIPER operand control registers  */
E 3
I 3
	/*------------------------------------------
	* setup VIPER operand control registers  */
E 3

	wait_status(adder, ADDRESS_COMPLETE);

	write_ID(adder, CS_UPDATE_MASK, 0x00FF);  /* select all planes */

	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 255);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);

I 3
	write_ID(adder, SRC1_OCR_B,
			EXT_NONE | INT_SOURCE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
			EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);

	/*----------------------------------------
	* load DESTINATION origin and vectors  */

	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->error_1 = 0;
	adder->error_2 = 0;

	adder->rasterop_mode = DST_WRITE_ENABLE | NORMAL;

	adder->destination_x = 0;
	adder->fast_dest_dx = 1024;

	adder->destination_y = 0;
	adder->slow_dest_dy = 864 - CHAR_HEIGHT;

	/*-----------------------------------
	* load SOURCE origin and vectors  */

	adder->source_1_x = 0;
	adder->source_1_dx = 1024;

	adder->source_1_y = 0 + CHAR_HEIGHT;
	adder->source_1_dy = 864 - CHAR_HEIGHT;

	write_ID(adder, LU_FUNCTION_R1, FULL_SRC_RESOLUTION | LF_SOURCE);
	adder->cmd = RASTEROP | OCRB | 0 | S1E | DTE;

	/*--------------------------------------------
	* do a rectangle clear of last screen line */

	write_ID(adder, MASK_1, 0xffff);
	write_ID(adder, SOURCE, 0xffff);
	write_ID(adder,DST_OCR_B,
		(EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY));
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 0);
	adder->error_1 = 0;
	adder->error_2 = 0;
	adder->slow_dest_dx = 0;	/* set up the width of	*/
	adder->slow_dest_dy = CHAR_HEIGHT;	/* rectangle */

	adder->rasterop_mode = (NORMAL | DST_WRITE_ENABLE) ;
	wait_status(adder, RASTEROP_COMPLETE);
	adder->destination_x = 0;
	adder->destination_y = 864 - CHAR_HEIGHT;

	adder->fast_dest_dx = 1024;	/* set up the height	*/
	adder->fast_dest_dy = 0;	/* of rectangle 	*/

	write_ID(adder, LU_FUNCTION_R2, (FULL_SRC_RESOLUTION | LF_SOURCE));
	adder->cmd = (RASTEROP | OCRB | LF_R2 | DTE ) ;

} /* scroll_up */

/********************************************************************
*
*	init_shared()... init shared memory pointers and structures
*
*********************************************************************
*
*	calling convention:
*
*		init_shared(unit);
*		u_int unit;
*
****************/

init_shared(unit)
register u_int unit;
{
	register struct dga *dga;

	dga = (struct dga *) qdmap[unit].dga;

	/*--------------------------------------------------
	* initialize the event queue pointers and header */

	eq_header[unit] = (struct qdinput *)
			  ((((int)event_shared & ~(0x01FF)) + 512)
			   + (EVENT_BUFSIZE * unit));

	eq_header[unit]->curs_pos.x = 0;
	eq_header[unit]->curs_pos.y = 0;

	dga->x_cursor = TRANX(eq_header[unit]->curs_pos.x);
	dga->y_cursor = TRANY(eq_header[unit]->curs_pos.y);

	eq_header[unit]->curs_box.left = 0;
	eq_header[unit]->curs_box.right = 0;
	eq_header[unit]->curs_box.top = 0;
	eq_header[unit]->curs_box.bottom = 0;

	/*---------------------------------------------------------
	* assign a pointer to the DMA I/O buffer for this QDSS. */

	DMAheader[unit] = (struct DMAreq_header *)
			  (((int)(&DMA_shared[0] + 512) & ~0x1FF)
			   + (DMAbuf_size * unit));

	DMAheader[unit]->DMAreq = (struct DMAreq *) ((int)DMAheader[unit]
				  + sizeof(struct DMAreq_header));

	DMAheader[unit]->QBAreg = 0;
	DMAheader[unit]->status = 0;
	DMAheader[unit]->shared_size = DMAbuf_size;
	DMAheader[unit]->used = 0;
	DMAheader[unit]->size = 10;	/* default = 10 requests */
	DMAheader[unit]->oldest = 0;
	DMAheader[unit]->newest = 0;

	/*-----------------------------------------------------------
	* assign a pointer to the scroll structure for this QDSS. */

	scroll[unit] = (struct scroll *)
			 (((int)(&scroll_shared[0] + 512) & ~0x1FF)
			   + (sizeof(struct scroll) * unit));

	scroll[unit]->status = 0;
	scroll[unit]->viper_constant = 0;
	scroll[unit]->y_scroll_constant = 0;
	scroll[unit]->y_offset = 0;
	scroll[unit]->x_index_pending = 0;
	scroll[unit]->y_index_pending = 0;

	/*----------------------------------------------------------------
	* assign a pointer to the color map write buffer for this QDSS */

	color_buf[unit] = (struct color_buf *)
			   (((int)(&color_shared[0] + 512) & ~0x1FF)
			    + (COLOR_BUFSIZ * unit));

	color_buf[unit]->status = 0;
	color_buf[unit]->count = 0;

} /* init_shared */

/*********************************************************************
*
*	setup_dragon()... init the ADDER, VIPER, bitmaps, & color map
*
**********************************************************************
*
*	calling convention:
*
*		setup_dragon();
*
*	return: NONE
*
************************/

setup_dragon(unit)
u_int unit;
{

	register struct adder *adder;
	register struct dga *dga;
	short *memcsr;

	int i;			/* general purpose variables */
	int status;

	short top;		/* clipping/scrolling boundaries */
	short bottom;
	short right;
	short left;

	short *red;		/* color map pointers */
	short *green;
	short *blue;

	/*------------------
	* init for setup */

	adder = (struct adder *) qdmap[unit].adder;
	dga = (struct dga *) qdmap[unit].dga;
	memcsr = (short *) qdmap[unit].memcsr;
E 3
D 2
	write_ID(adder, SRC1_OCR_B,
			EXT_NONE | INT_SOURCE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
			EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);

/*----------------------------------------
* load DESTINATION origin and vectors  */

	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->error_1 = 0;
	adder->error_2 = 0;

	adder->rasterop_mode = DST_WRITE_ENABLE | NORMAL;

	adder->destination_x = 0;
	adder->fast_dest_dx = 1024;

	adder->destination_y = 0;
	adder->slow_dest_dy = 864 - CHAR_HEIGHT;

/*-----------------------------------
* load SOURCE origin and vectors  */

	adder->source_1_x = 0;
	adder->source_1_dx = 1024;

	adder->source_1_y = 0 + CHAR_HEIGHT;
	adder->source_1_dy = 864 - CHAR_HEIGHT;

	write_ID(adder, LU_FUNCTION_R1, FULL_SRC_RESOLUTION | LF_SOURCE);
	adder->cmd = RASTEROP | OCRB | 0 | S1E | DTE;

/*--------------------------------------------
* do a rectangle clear of last screen line */

	write_ID(adder, MASK_1, 0xffff);
	write_ID(adder, SOURCE, 0xffff);
	write_ID(adder,DST_OCR_B,
		(EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY));
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 0);
	adder->error_1 = 0;
	adder->error_2 = 0;
	adder->slow_dest_dx = 0;	/* set up the width of	*/
	adder->slow_dest_dy = CHAR_HEIGHT;	/* rectangle */

	adder->rasterop_mode = (NORMAL | DST_WRITE_ENABLE) ;
	wait_status(adder, RASTEROP_COMPLETE);
	adder->destination_x = 0;
	adder->destination_y = 864 - CHAR_HEIGHT;

	adder->fast_dest_dx = 1024;	/* set up the height	*/
	adder->fast_dest_dy = 0;	/* of rectangle 	*/

	write_ID(adder, LU_FUNCTION_R2, (FULL_SRC_RESOLUTION | LF_SOURCE));
	adder->cmd = (RASTEROP | OCRB | LF_R2 | DTE ) ;

} /* scroll_up */

/********************************************************************
*
*	init_shared()... init shared memory pointers and structures
*
*********************************************************************
*
*	calling convention:
*
*		init_shared(unit);
*		u_int unit;
*
****************/

init_shared(unit)
register u_int unit;
{
	register struct dga *dga;

	dga = (struct dga *) qdmap[unit].dga;

/*--------------------------------------------------
* initialize the event queue pointers and header */

	eq_header[unit] = (struct qdinput *)
			  ((((int)event_shared & ~(0x01FF)) + 512)
			   + (EVENT_BUFSIZE * unit));

	eq_header[unit]->curs_pos.x = 0;
	eq_header[unit]->curs_pos.y = 0;

	dga->x_cursor = TRANX(eq_header[unit]->curs_pos.x);
	dga->y_cursor = TRANY(eq_header[unit]->curs_pos.y);

	eq_header[unit]->curs_box.left = 0;
	eq_header[unit]->curs_box.right = 0;
	eq_header[unit]->curs_box.top = 0;
	eq_header[unit]->curs_box.bottom = 0;

/*---------------------------------------------------------
* assign a pointer to the DMA I/O buffer for this QDSS. */

	DMAheader[unit] = (struct DMAreq_header *)
			  (((int)(&DMA_shared[0] + 512) & ~0x1FF)
			   + (DMAbuf_size * unit));

	DMAheader[unit]->DMAreq = (struct DMAreq *) ((int)DMAheader[unit]
				  + sizeof(struct DMAreq_header));

	DMAheader[unit]->QBAreg = 0;
	DMAheader[unit]->status = 0;
	DMAheader[unit]->shared_size = DMAbuf_size;
	DMAheader[unit]->used = 0;
	DMAheader[unit]->size = 10;	/* default = 10 requests */
	DMAheader[unit]->oldest = 0;
	DMAheader[unit]->newest = 0;

/*-----------------------------------------------------------
* assign a pointer to the scroll structure for this QDSS. */

	scroll[unit] = (struct scroll *)
			 (((int)(&scroll_shared[0] + 512) & ~0x1FF)
			   + (sizeof(struct scroll) * unit));

	scroll[unit]->status = 0;
	scroll[unit]->viper_constant = 0;
	scroll[unit]->y_scroll_constant = 0;
	scroll[unit]->y_offset = 0;
	scroll[unit]->x_index_pending = 0;
	scroll[unit]->y_index_pending = 0;

/*----------------------------------------------------------------
* assign a pointer to the color map write buffer for this QDSS */

	color_buf[unit] = (struct color_buf *)
			   (((int)(&color_shared[0] + 512) & ~0x1FF)
			    + (COLOR_BUFSIZ * unit));

	color_buf[unit]->status = 0;
	color_buf[unit]->count = 0;

} /* init_shared */

/*********************************************************************
*
*	setup_dragon()... init the ADDER, VIPER, bitmaps, & color map
*
**********************************************************************
*
*	calling convention:
*
*		setup_dragon();
*
*	return: NONE
*
************************/

setup_dragon(unit)
u_int unit;
{

	register struct adder *adder;
	register struct dga *dga;
	short *memcsr;

	int i;			/* general purpose variables */
	int status;

	short top;		/* clipping/scrolling boundaries */
	short bottom;
	short right;
	short left;

	short *red;		/* color map pointers */
	short *green;
	short *blue;

/*------------------
* init for setup */

	adder = (struct adder *) qdmap[unit].adder;
	dga = (struct dga *) qdmap[unit].dga;
	memcsr = (short *) qdmap[unit].memcsr;

	dga->csr &= ~(DMA_IE | 0x700);	/* halt DMA and kill the intrpts */
	*memcsr = SYNC_ON;		/* blank screen and turn off LED's */
	adder->command = CANCEL;

/*----------------------
* set monitor timing */

	adder->x_scan_count_0 = 0x2800;
	adder->x_scan_count_1 = 0x1020;
	adder->x_scan_count_2 = 0x003A;
	adder->x_scan_count_3 = 0x38F0;
	adder->x_scan_count_4 = 0x6128;
	adder->x_scan_count_5 = 0x093A;
	adder->x_scan_count_6 = 0x313C;
	adder->sync_phase_adj = 0x0100;
	adder->x_scan_conf = 0x00C8;

/*---------------------------------------------------------
* got a bug in secound pass ADDER! lets take care of it */

	/* normally, just use the code in the following bug fix code, but to
	* make repeated demos look pretty, load the registers as if there was
	* no bug and then test to see if we are getting sync */

	adder->y_scan_count_0 = 0x135F;
	adder->y_scan_count_1 = 0x3363;
	adder->y_scan_count_2 = 0x2366;
	adder->y_scan_count_3 = 0x0388;

	/* if no sync, do the bug fix code */

	if (wait_status(adder, VSYNC) == BAD) {

	    /* first load all Y scan registers with very short frame and
	    * wait for scroll service.	This guarantees at least one SYNC
	    * to fix the pass 2 Adder initialization bug (synchronizes
	    * XCINCH with DMSEEDH) */

	    adder->y_scan_count_0 = 0x01;
	    adder->y_scan_count_1 = 0x01;
	    adder->y_scan_count_2 = 0x01;
	    adder->y_scan_count_3 = 0x01;

	    wait_status(adder, VSYNC);	/* delay at least 1 full frame time */
	    wait_status(adder, VSYNC);

	    /* now load the REAL sync values (in reverse order just to
	    *  be safe.  */

	    adder->y_scan_count_3 = 0x0388;
	    adder->y_scan_count_2 = 0x2366;
	    adder->y_scan_count_1 = 0x3363;
	    adder->y_scan_count_0 = 0x135F;
	}

	*memcsr = SYNC_ON | UNBLANK;	/* turn off leds and turn on video */

/*----------------------------
* zero the index registers */

	adder->x_index_pending = 0;
	adder->y_index_pending = 0;
	adder->x_index_new = 0;
	adder->y_index_new = 0;
	adder->x_index_old = 0;
	adder->y_index_old = 0;

	adder->pause = 0;

/*----------------------------------------
* set rasterop mode to normal pen down */

	adder->rasterop_mode = DST_WRITE_ENABLE | DST_INDEX_ENABLE | NORMAL;

/*--------------------------------------------------
* set the rasterop registers to a default values */

	adder->source_1_dx = 1;
	adder->source_1_dy = 1;
	adder->source_1_x = 0;
	adder->source_1_y = 0;
	adder->destination_x = 0;
	adder->destination_y = 0;
	adder->fast_dest_dx = 1;
	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->slow_dest_dy = 1;
	adder->error_1 = 0;
	adder->error_2 = 0;

/*------------------------
* scale factor = unity */

	adder->fast_scale = UNITY;
	adder->slow_scale = UNITY;

/*-------------------------------
* set the source 2 parameters */

	adder->source_2_x = 0;
E 2
I 2
D 3
	write_ID(adder, SRC1_OCR_B,
			EXT_NONE | INT_SOURCE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
			EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);
E 3

D 3
/*----------------------------------------
* load DESTINATION origin and vectors  */

	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->error_1 = 0;
	adder->error_2 = 0;

	adder->rasterop_mode = DST_WRITE_ENABLE | NORMAL;

	adder->destination_x = 0;
	adder->fast_dest_dx = 1024;

	adder->destination_y = 0;
	adder->slow_dest_dy = 864 - CHAR_HEIGHT;

/*-----------------------------------
* load SOURCE origin and vectors  */

	adder->source_1_x = 0;
	adder->source_1_dx = 1024;

	adder->source_1_y = 0 + CHAR_HEIGHT;
	adder->source_1_dy = 864 - CHAR_HEIGHT;

	write_ID(adder, LU_FUNCTION_R1, FULL_SRC_RESOLUTION | LF_SOURCE);
	adder->cmd = RASTEROP | OCRB | 0 | S1E | DTE;

/*--------------------------------------------
* do a rectangle clear of last screen line */

	write_ID(adder, MASK_1, 0xffff);
	write_ID(adder, SOURCE, 0xffff);
	write_ID(adder,DST_OCR_B,
		(EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY));
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 0);
	adder->error_1 = 0;
	adder->error_2 = 0;
	adder->slow_dest_dx = 0;	/* set up the width of	*/
	adder->slow_dest_dy = CHAR_HEIGHT;	/* rectangle */

	adder->rasterop_mode = (NORMAL | DST_WRITE_ENABLE) ;
	wait_status(adder, RASTEROP_COMPLETE);
	adder->destination_x = 0;
	adder->destination_y = 864 - CHAR_HEIGHT;

	adder->fast_dest_dx = 1024;	/* set up the height	*/
	adder->fast_dest_dy = 0;	/* of rectangle 	*/

	write_ID(adder, LU_FUNCTION_R2, (FULL_SRC_RESOLUTION | LF_SOURCE));
	adder->cmd = (RASTEROP | OCRB | LF_R2 | DTE ) ;

} /* scroll_up */

/********************************************************************
*
*	init_shared()... init shared memory pointers and structures
*
*********************************************************************
*
*	calling convention:
*
*		init_shared(unit);
*		u_int unit;
*
****************/

init_shared(unit)
register u_int unit;
{
	register struct dga *dga;

	dga = (struct dga *) qdmap[unit].dga;

/*--------------------------------------------------
* initialize the event queue pointers and header */

	eq_header[unit] = (struct qdinput *)
			  ((((int)event_shared & ~(0x01FF)) + 512)
			   + (EVENT_BUFSIZE * unit));

	eq_header[unit]->curs_pos.x = 0;
	eq_header[unit]->curs_pos.y = 0;

	dga->x_cursor = TRANX(eq_header[unit]->curs_pos.x);
	dga->y_cursor = TRANY(eq_header[unit]->curs_pos.y);

	eq_header[unit]->curs_box.left = 0;
	eq_header[unit]->curs_box.right = 0;
	eq_header[unit]->curs_box.top = 0;
	eq_header[unit]->curs_box.bottom = 0;

/*---------------------------------------------------------
* assign a pointer to the DMA I/O buffer for this QDSS. */

	DMAheader[unit] = (struct DMAreq_header *)
			  (((int)(&DMA_shared[0] + 512) & ~0x1FF)
			   + (DMAbuf_size * unit));

	DMAheader[unit]->DMAreq = (struct DMAreq *) ((int)DMAheader[unit]
				  + sizeof(struct DMAreq_header));

	DMAheader[unit]->QBAreg = 0;
	DMAheader[unit]->status = 0;
	DMAheader[unit]->shared_size = DMAbuf_size;
	DMAheader[unit]->used = 0;
	DMAheader[unit]->size = 10;	/* default = 10 requests */
	DMAheader[unit]->oldest = 0;
	DMAheader[unit]->newest = 0;

/*-----------------------------------------------------------
* assign a pointer to the scroll structure for this QDSS. */

	scroll[unit] = (struct scroll *)
			 (((int)(&scroll_shared[0] + 512) & ~0x1FF)
			   + (sizeof(struct scroll) * unit));

	scroll[unit]->status = 0;
	scroll[unit]->viper_constant = 0;
	scroll[unit]->y_scroll_constant = 0;
	scroll[unit]->y_offset = 0;
	scroll[unit]->x_index_pending = 0;
	scroll[unit]->y_index_pending = 0;

/*----------------------------------------------------------------
* assign a pointer to the color map write buffer for this QDSS */

	color_buf[unit] = (struct color_buf *)
			   (((int)(&color_shared[0] + 512) & ~0x1FF)
			    + (COLOR_BUFSIZ * unit));

	color_buf[unit]->status = 0;
	color_buf[unit]->count = 0;

} /* init_shared */

/*********************************************************************
*
*	setup_dragon()... init the ADDER, VIPER, bitmaps, & color map
*
**********************************************************************
*
*	calling convention:
*
*		setup_dragon();
*
*	return: NONE
*
************************/

setup_dragon(unit)
u_int unit;
{

	register struct adder *adder;
	register struct dga *dga;
	short *memcsr;

	int i;			/* general purpose variables */
	int status;

	short top;		/* clipping/scrolling boundaries */
	short bottom;
	short right;
	short left;

	short *red;		/* color map pointers */
	short *green;
	short *blue;

/*------------------
* init for setup */

	adder = (struct adder *) qdmap[unit].adder;
	dga = (struct dga *) qdmap[unit].dga;
	memcsr = (short *) qdmap[unit].memcsr;

E 3
	dga->csr &= ~(DMA_IE | 0x700);	/* halt DMA and kill the intrpts */
	*memcsr = SYNC_ON;		/* blank screen and turn off LED's */
E 6
D 6
	adder->command = CANCEL;
E 6

D 3
/*----------------------
* set monitor timing */
E 3
I 3
D 6
	/*----------------------
	* set monitor timing */
E 6
I 6
	/*--------------------------------------
	* Check for various keyboard errors  */
E 6
E 3

I 6
	if( key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
	    key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
		printf("Keyboard error, code = %x\n", key);
		return(0);
	}

	if (key < LK_LOWEST)
	    return(0);

	/*---------------------------------
	* See if its a state change key */

	switch (key) {

	    case LOCK:
		q_keyboard.lock ^= 0xffff;	/* toggle */
		if (q_keyboard.lock)
		    led_control(LK_LED_ENABLE, LK_LED_LOCK);
		else
		    led_control(LK_LED_DISABLE, LK_LED_LOCK);
		goto LOOP;

	    case SHIFT:
		q_keyboard.shift ^= 0xFFFF;
		goto LOOP;

	    case CNTRL:
		q_keyboard.cntrl ^= 0xFFFF;
		goto LOOP;

	    case ALLUP:
		q_keyboard.cntrl = 0;
		q_keyboard.shift = 0;
		goto LOOP;

	    case REPEAT:
		chr = q_keyboard.last;
		break;

	    /*-------------------------------------------------------
	    * Test for cntrl characters. If set, see if the character
	    * is elligible to become a control character. */

	    default:

		if (q_keyboard.cntrl) {
		    chr = q_key[key];
		    if (chr >= ' ' && chr <= '~')
			chr &= 0x1F;
		}
		else if ( q_keyboard.lock || q_keyboard.shift )
		    chr = q_shift_key[key];
		else
		    chr = q_key[key];
		break;
	}

	if (chr < ' ' && chr > '~')	/* if input is non-displayable */
	    return(0);			/* ..then pitch it! */

	q_keyboard.last = chr;

	/*-----------------------------------
	* Check for special function keys */

	if (chr & 0x80) 		/* pitch the function keys */
	    return(0);
	else
	    return(chr);

} /* qdgetc */

/**********************************************************************
*
*	ldcursor()... load the mouse cursor's template RAM bitmap
*
*********************************************************************
*
*	calling convention:
*
*		ldcursor(unit, bitmap);
*		u_int unit;
*		short *bitmap;
*
****************/

ldcursor(unit, bitmap)
u_int unit;
short *bitmap;
{
	register struct dga *dga;
	register short *temp;
	register int i;

	int cursor;

	dga = (struct dga *) qdmap[unit].dga;
	temp = (short *) qdmap[unit].template;

	if (dga->csr & CURS_ENB) {	/* if the cursor is enabled.. */
	    cursor = -1;		/* ..note that.. */
	    dga->csr &= ~CURS_ENB;	/* ..and shut it off */
	}
	else {
	    cursor = 0;
	}

	dga->csr &= ~CURS_ENB;		/* shut off the cursor */

	temp += (8 * 1024) - 32;	/* cursor is 32 WORDS from the end */
					/* ..of the 8k WORD template space */
	for (i = 0; i < 32; ++i)
	    *temp++ = *bitmap++;

	if (cursor) {			/* if cursor was enabled.. */
	    dga->csr |= CURS_ENB;	/* ..turn it back on */
	}

	return(0);

} /* ldcursor */

/**********************************************************************
*
*	ldfont()... put the console font in the QDSS off-screen memory
*
***********************************************************************
*
*	calling convention:
*
*		ldfont(unit);
*		u_int unit;	;QDSS unit number
*
****************/

ldfont(unit)
u_int unit;
{
	register struct adder *adder;

	int i;		/* scratch variables */
	int j;
	int k;
	short packed;
	int max_chars_line;

	adder = (struct adder *) qdmap[unit].adder;

/*------------------------------------------
* setup VIPER operand control registers  */

	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 255);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);

	write_ID(adder, SRC1_OCR_B,
			EXT_NONE | INT_NONE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, SRC2_OCR_B,
			EXT_NONE | INT_NONE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
			EXT_SOURCE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);

	adder->rasterop_mode = DST_WRITE_ENABLE | DST_INDEX_ENABLE | NORMAL;

/*--------------------------
* load destination data  */

	wait_status(adder, RASTEROP_COMPLETE);

	adder->destination_x = FONT_X;
	adder->destination_y = FONT_Y;
	if (FONT_WIDTH > MAX_SCREEN_X)
		adder->fast_dest_dx = MAX_SCREEN_X;
	else
		adder->fast_dest_dx = FONT_WIDTH;
	adder->slow_dest_dy = CHAR_HEIGHT;

/*---------------------------------------
* setup for processor to bitmap xfer  */

	write_ID(adder, CS_UPDATE_MASK, 0x0001);
	adder->cmd = PBT | OCRB | 2 | DTE | 2;

/*---------------------------------------
* Figure out how many characters can be stored on one "line" of offscreen memory
*/
	    max_chars_line = MAX_SCREEN_X/(CHAR_WIDTH*2);
	    if ((CHARS/2 + CHARS%2) < max_chars_line)
		max_chars_line = CHARS/2 + CHARS%2;

/*-----------------------------------------------
* iteratively do the processor to bitmap xfer */

	for (i = 0; i < ROWS; ++i) {

	    /* PTOB a scan line */

	    for (j = 0, k = i; j < max_chars_line; ++j) {
		/* PTOB one scan of a char cell */

		packed = q_font[k];
		k += ROWS;
		packed |= ((short)q_font[k] << 8);
		k += ROWS;

		wait_status(adder, TX_READY);
		adder->id_data = packed;
	    }
	}

/*---------------------------------------
* Copy the second row of characters.
* Subtract the first row from the total number.  Divide this quantity by 2 
* because 2 chars are stored in a short in the PTOB loop below.
* Figure out how many characters can be stored on one "line" of offscreen memory
*/
	    max_chars_line = MAX_SCREEN_X/(CHAR_WIDTH*2);
	    if ((CHARS/2 + CHARS%2) < max_chars_line)
		return;
	    max_chars_line = (CHARS/2 + CHARS%2) - max_chars_line; /* 95 - 64 */
	    /* Paranoia check to see if 3rd row may be needed */
	    if (max_chars_line > (MAX_SCREEN_X/(CHAR_WIDTH*2)))
	    	max_chars_line = MAX_SCREEN_X/(CHAR_WIDTH*2);


/*-----------------------------------------------*/

	adder->destination_x = FONT_X;
	adder->destination_y = FONT_Y - CHAR_HEIGHT;
	adder->fast_dest_dx = max_chars_line * CHAR_WIDTH * 2;
	adder->slow_dest_dy = CHAR_HEIGHT;

/*---------------------------------------
* setup for processor to bitmap xfer  */

	write_ID(adder, CS_UPDATE_MASK, 0x0001);
	adder->cmd = PBT | OCRB | 2 | DTE | 2;

/*-----------------------------------------------
* iteratively do the processor to bitmap xfer */

	for (i = 0; i < ROWS; ++i) {

	    /* PTOB a scan line */

	    for (j = 0, k = i; j < max_chars_line; ++j) {

		/* PTOB one scan of a char cell */

		packed = q_font[k + FONT_OFFSET];
		k += ROWS;
		packed |= ((short)q_font[k + FONT_OFFSET] << 8);
		k += ROWS;

		wait_status(adder, TX_READY);
		adder->id_data = packed;
	    }
	}

}  /* ldfont */

/*********************************************************************
*
*	led_control()... twiddle LK-201 LED's
*
**********************************************************************
*
*	led_control(unit, cmd, led_mask);
*	u_int unit;	QDSS number
*	int cmd;	LED enable/disable command
*	int led_mask;	which LED(s) to twiddle
*
*************/

led_control(unit, cmd, led_mask)
u_int unit;
int cmd;
int led_mask;
{
	register int i;
	register int status;
	register struct duart *duart;

	duart = (struct duart *) qdmap[unit].duart;

	for (i = 1000; i > 0; --i) {
	    if ((status = duart->statusA) & XMT_RDY) {
		duart->dataA = cmd;
		break;
	    }
	}

	for (i = 1000; i > 0; --i) {
	    if ((status = duart->statusA) & XMT_RDY) {
		duart->dataA = led_mask;
		break;
	    }
	}

	if (i == 0)
	    return(BAD);

	return(GOOD);

} /* led_control */

/*******************************************************************
*
*	scroll_up()... move the screen up one character height
*
********************************************************************
*
*	calling convention:
*
*		scroll_up(adder);
*		struct adder *adder;	;address of adder
*
********/

scroll_up(adder)
register struct adder *adder;
{

/*------------------------------------------
* setup VIPER operand control registers  */

	wait_status(adder, ADDRESS_COMPLETE);

	write_ID(adder, CS_UPDATE_MASK, 0x00FF);  /* select all planes */

	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 255);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);

	write_ID(adder, SRC1_OCR_B,
			EXT_NONE | INT_SOURCE | ID | BAR_SHIFT_DELAY);
	write_ID(adder, DST_OCR_B,
			EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY);

/*----------------------------------------
* load DESTINATION origin and vectors  */

	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->error_1 = 0;
	adder->error_2 = 0;

	adder->rasterop_mode = DST_WRITE_ENABLE | NORMAL;

	adder->destination_x = 0;
	adder->fast_dest_dx = 1024;

	adder->destination_y = 0;
	adder->slow_dest_dy = 864 - CHAR_HEIGHT;

/*-----------------------------------
* load SOURCE origin and vectors  */

	adder->source_1_x = 0;
	adder->source_1_dx = 1024;

	adder->source_1_y = 0 + CHAR_HEIGHT;
	adder->source_1_dy = 864 - CHAR_HEIGHT;

	write_ID(adder, LU_FUNCTION_R1, FULL_SRC_RESOLUTION | LF_SOURCE);
	adder->cmd = RASTEROP | OCRB | 0 | S1E | DTE;

/*--------------------------------------------
* do a rectangle clear of last screen line */

	write_ID(adder, MASK_1, 0xffff);
	write_ID(adder, SOURCE, 0xffff);
	write_ID(adder,DST_OCR_B,
		(EXT_NONE | INT_NONE | NO_ID | NO_BAR_SHIFT_DELAY));
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 0);
	adder->error_1 = 0;
	adder->error_2 = 0;
	adder->slow_dest_dx = 0;	/* set up the width of	*/
	adder->slow_dest_dy = CHAR_HEIGHT;	/* rectangle */

	adder->rasterop_mode = (NORMAL | DST_WRITE_ENABLE) ;
	wait_status(adder, RASTEROP_COMPLETE);
	adder->destination_x = 0;
	adder->destination_y = 864 - CHAR_HEIGHT;

	adder->fast_dest_dx = 1024;	/* set up the height	*/
	adder->fast_dest_dy = 0;	/* of rectangle 	*/

	write_ID(adder, LU_FUNCTION_R2, (FULL_SRC_RESOLUTION | LF_SOURCE));
	adder->cmd = (RASTEROP | OCRB | LF_R2 | DTE ) ;

} /* scroll_up */

/********************************************************************
*
*	init_shared()... init shared memory pointers and structures
*
*********************************************************************
*
*	calling convention:
*
*		init_shared(unit);
*		u_int unit;
*
****************/

init_shared(unit)
register u_int unit;
{
	register struct dga *dga;

	dga = (struct dga *) qdmap[unit].dga;

/*--------------------------------------------------
* initialize the event queue pointers and header */

	eq_header[unit] = (struct qdinput *)
			  ((((int)event_shared & ~(0x01FF)) + 512)
			   + (EVENT_BUFSIZE * unit));

	eq_header[unit]->curs_pos.x = 0;
	eq_header[unit]->curs_pos.y = 0;

	dga->x_cursor = TRANX(eq_header[unit]->curs_pos.x);
	dga->y_cursor = TRANY(eq_header[unit]->curs_pos.y);

	eq_header[unit]->curs_box.left = 0;
	eq_header[unit]->curs_box.right = 0;
	eq_header[unit]->curs_box.top = 0;
	eq_header[unit]->curs_box.bottom = 0;

/*---------------------------------------------------------
* assign a pointer to the DMA I/O buffer for this QDSS. */

	DMAheader[unit] = (struct DMAreq_header *)
			  (((int)(&DMA_shared[0] + 512) & ~0x1FF)
			   + (DMAbuf_size * unit));

	DMAheader[unit]->DMAreq = (struct DMAreq *) ((int)DMAheader[unit]
				  + sizeof(struct DMAreq_header));

	DMAheader[unit]->QBAreg = 0;
	DMAheader[unit]->status = 0;
	DMAheader[unit]->shared_size = DMAbuf_size;
	DMAheader[unit]->used = 0;
	DMAheader[unit]->size = 10;	/* default = 10 requests */
	DMAheader[unit]->oldest = 0;
	DMAheader[unit]->newest = 0;

/*-----------------------------------------------------------
* assign a pointer to the scroll structure for this QDSS. */

	scroll[unit] = (struct scroll *)
			 (((int)(&scroll_shared[0] + 512) & ~0x1FF)
			   + (sizeof(struct scroll) * unit));

	scroll[unit]->status = 0;
	scroll[unit]->viper_constant = 0;
	scroll[unit]->y_scroll_constant = 0;
	scroll[unit]->y_offset = 0;
	scroll[unit]->x_index_pending = 0;
	scroll[unit]->y_index_pending = 0;

/*----------------------------------------------------------------
* assign a pointer to the color map write buffer for this QDSS */

	color_buf[unit] = (struct color_buf *)
			   (((int)(&color_shared[0] + 512) & ~0x1FF)
			    + (COLOR_BUFSIZ * unit));

	color_buf[unit]->status = 0;
	color_buf[unit]->count = 0;

} /* init_shared */

/*********************************************************************
*
*	setup_dragon()... init the ADDER, VIPER, bitmaps, & color map
*
**********************************************************************
*
*	calling convention:
*
*		setup_dragon();
*
*	return: NONE
*
************************/

setup_dragon(unit)
u_int unit;
{

	register struct adder *adder;
	register struct dga *dga;
	short *memcsr;

	int i;			/* general purpose variables */
	int status;

	short top;		/* clipping/scrolling boundaries */
	short bottom;
	short right;
	short left;

	short *red;		/* color map pointers */
	short *green;
	short *blue;

/*------------------
* init for setup */

	adder = (struct adder *) qdmap[unit].adder;
	dga = (struct dga *) qdmap[unit].dga;
	memcsr = (short *) qdmap[unit].memcsr;

	dga->csr &= ~(DMA_IE | 0x700);	/* halt DMA and kill the intrpts */
	*memcsr = SYNC_ON;		/* blank screen and turn off LED's */
	adder->command = CANCEL;

/*----------------------
* set monitor timing */

E 6
	adder->x_scan_count_0 = 0x2800;
	adder->x_scan_count_1 = 0x1020;
	adder->x_scan_count_2 = 0x003A;
	adder->x_scan_count_3 = 0x38F0;
	adder->x_scan_count_4 = 0x6128;
	adder->x_scan_count_5 = 0x093A;
	adder->x_scan_count_6 = 0x313C;
	adder->sync_phase_adj = 0x0100;
	adder->x_scan_conf = 0x00C8;

D 3
/*---------------------------------------------------------
* got a bug in secound pass ADDER! lets take care of it */
E 3
I 3
D 6
	/*---------------------------------------------------------
	* got a bug in secound pass ADDER! lets take care of it */
E 6
I 6
/*---------------------------------------------------------
* got a bug in secound pass ADDER! lets take care of it */
E 6
E 3

	/* normally, just use the code in the following bug fix code, but to
	* make repeated demos look pretty, load the registers as if there was
	* no bug and then test to see if we are getting sync */

	adder->y_scan_count_0 = 0x135F;
	adder->y_scan_count_1 = 0x3363;
	adder->y_scan_count_2 = 0x2366;
	adder->y_scan_count_3 = 0x0388;

	/* if no sync, do the bug fix code */

	if (wait_status(adder, VSYNC) == BAD) {

	    /* first load all Y scan registers with very short frame and
	    * wait for scroll service.	This guarantees at least one SYNC
	    * to fix the pass 2 Adder initialization bug (synchronizes
	    * XCINCH with DMSEEDH) */

	    adder->y_scan_count_0 = 0x01;
	    adder->y_scan_count_1 = 0x01;
	    adder->y_scan_count_2 = 0x01;
	    adder->y_scan_count_3 = 0x01;

	    wait_status(adder, VSYNC);	/* delay at least 1 full frame time */
	    wait_status(adder, VSYNC);

	    /* now load the REAL sync values (in reverse order just to
	    *  be safe.  */

	    adder->y_scan_count_3 = 0x0388;
	    adder->y_scan_count_2 = 0x2366;
	    adder->y_scan_count_1 = 0x3363;
	    adder->y_scan_count_0 = 0x135F;
	}

	*memcsr = SYNC_ON | UNBLANK;	/* turn off leds and turn on video */

D 3
/*----------------------------
* zero the index registers */
E 3
I 3
D 6
	/*----------------------------
	* zero the index registers */
E 6
I 6
/*----------------------------
* zero the index registers */
E 6
E 3

	adder->x_index_pending = 0;
	adder->y_index_pending = 0;
	adder->x_index_new = 0;
	adder->y_index_new = 0;
D 5
	adder->x_index_old = 0;
	adder->y_index_old = 0;

	adder->pause = 0;
E 5
I 5
	adder->x_index_old = 0;
	adder->y_index_old = 0;

	adder->pause = 0;
E 5

D 3
/*----------------------------------------
* set rasterop mode to normal pen down */
E 3
I 3
D 6
	/*----------------------------------------
	* set rasterop mode to normal pen down */
E 6
I 6
/*----------------------------------------
* set rasterop mode to normal pen down */
E 6
E 3

	adder->rasterop_mode = DST_WRITE_ENABLE | DST_INDEX_ENABLE | NORMAL;

D 3
/*--------------------------------------------------
* set the rasterop registers to a default values */
E 3
I 3
D 6
	/*--------------------------------------------------
	* set the rasterop registers to a default values */
E 6
I 6
/*--------------------------------------------------
* set the rasterop registers to a default values */
E 6
E 3

	adder->source_1_dx = 1;
	adder->source_1_dy = 1;
	adder->source_1_x = 0;
	adder->source_1_y = 0;
	adder->destination_x = 0;
	adder->destination_y = 0;
	adder->fast_dest_dx = 1;
	adder->fast_dest_dy = 0;
	adder->slow_dest_dx = 0;
	adder->slow_dest_dy = 1;
	adder->error_1 = 0;
	adder->error_2 = 0;

D 3
/*------------------------
* scale factor = unity */
E 3
I 3
D 6
	/*------------------------
	* scale factor = unity */
E 6
I 6
/*------------------------
* scale factor = unity */
E 6
E 3

	adder->fast_scale = UNITY;
	adder->slow_scale = UNITY;

D 3
/*-------------------------------
* set the source 2 parameters */
E 3
I 3
D 6
	/*-------------------------------
	* set the source 2 parameters */
E 6
I 6
/*-------------------------------
* set the source 2 parameters */
E 6
E 3

	adder->source_2_x = 0;
E 10
E 2
	adder->source_2_y = 0;
	adder->source_2_size = 0x0022;
D 10

D 3
/*-----------------------------------------------
* initialize plane addresses for eight vipers */
E 3
I 3
D 6
	/*-----------------------------------------------
	* initialize plane addresses for eight vipers */
E 6
I 6
/*-----------------------------------------------
* initialize plane addresses for eight vipers */
E 6
E 3

E 10
I 10
	/*
	* initialize plane addresses for eight vipers 
	*/
E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0001);
	write_ID(adder, PLANE_ADDRESS, 0x0000);
D 10

E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0002);
	write_ID(adder, PLANE_ADDRESS, 0x0001);
D 10

E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0004);
	write_ID(adder, PLANE_ADDRESS, 0x0002);
D 10

E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0008);
	write_ID(adder, PLANE_ADDRESS, 0x0003);
D 10

E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0010);
	write_ID(adder, PLANE_ADDRESS, 0x0004);
D 10

E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0020);
	write_ID(adder, PLANE_ADDRESS, 0x0005);
D 10

E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0040);
	write_ID(adder, PLANE_ADDRESS, 0x0006);
D 10

E 10
	write_ID(adder, CS_UPDATE_MASK, 0x0080);
	write_ID(adder, PLANE_ADDRESS, 0x0007);
D 10

	/* initialize the external registers. */

E 10
I 10
	/*
	 * initialize the external registers. 
	 */
E 10
	write_ID(adder, CS_UPDATE_MASK, 0x00FF);
	write_ID(adder, CS_SCROLL_MASK, 0x00FF);
D 10

	/* initialize resolution mode */

E 10
I 10
	/*
	 * initialize resolution mode 
	 */
E 10
	write_ID(adder, MEMORY_BUS_WIDTH, 0x000C);     /* bus width = 16 */
	write_ID(adder, RESOLUTION_MODE, 0x0000);      /* one bit/pixel */
D 10

	/* initialize viper registers */

E 10
I 10
	/*
	 * initialize viper registers 
	 */
E 10
	write_ID(adder, SCROLL_CONSTANT, SCROLL_ENABLE|VIPER_LEFT|VIPER_UP);
	write_ID(adder, SCROLL_FILL, 0x0000);
D 10

D 3
/*----------------------------------------------------
* set clipping and scrolling limits to full screen */
E 3
I 3
D 6
	/*----------------------------------------------------
	* set clipping and scrolling limits to full screen */
E 6
I 6
/*----------------------------------------------------
* set clipping and scrolling limits to full screen */
E 6
E 3

	for ( i = 1000, adder->status = 0
	    ; i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE)
	    ; --i);

E 10
I 10
	/*
	 * set clipping and scrolling limits to full screen 
	 */
D 11
	for ( i = 1000, adder->status = 0 ; 
	      i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE) ; --i)
E 11
I 11
	for (i = 1000, adder->status = 0; 
	     i > 0 && !(adder->status&ADDRESS_COMPLETE); --i)
E 11
		;
E 10
	if (i == 0)
D 3
	    mprintf("\nqd%d: setup_dragon: timeout on ADDRESS_COMPLETE",unit);
E 3
I 3
D 6
	    printf("qd%d: setup_dragon: timeout on ADDRESS_COMPLETE\n", unit);
E 6
I 6
D 11
	    printf("\nqd%d: setup_dragon: timeout on ADDRESS_COMPLETE",unit);
E 11
I 11
	    printf("qd%d: setup_dragon: timeout on ADDRESS_COMPLETE\n",unit);
E 11
E 6
E 3
D 10

E 10
	top = 0;
	bottom = 2048;
	left = 0;
	right = 1024;
D 10

E 10
	adder->x_clip_min = left;
	adder->x_clip_max = right;
	adder->y_clip_min = top;
	adder->y_clip_max = bottom;
D 10

E 10
	adder->scroll_x_min = left;
	adder->scroll_x_max = right;
	adder->scroll_y_min = top;
	adder->scroll_y_max = bottom;
D 10

E 10
D 11
	wait_status(adder, VSYNC);	/* wait at LEAST 1 full frame */
	wait_status(adder, VSYNC);
E 11
I 11
	(void)wait_status(adder, VSYNC);	/* wait at LEAST 1 full frame */
	(void)wait_status(adder, VSYNC);
E 11
D 10

E 10
	adder->x_index_pending = left;
	adder->y_index_pending = top;
	adder->x_index_new = left;
	adder->y_index_new = top;
	adder->x_index_old = left;
	adder->y_index_old = top;

D 10
	for ( i = 1000, adder->status = 0
	    ; i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE)
	    ; --i);

E 10
I 10
D 11
	for ( i = 1000, adder->status = 0 ; 
	      i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE) ;
	      --i)
E 11
I 11
	for (i = 1000, adder->status = 0; i > 0 && 
	     !(adder->status&ADDRESS_COMPLETE) ; --i)
E 11
		;
E 10
	if (i == 0)
D 3
	    mprintf("\nqd%d: setup_dragon: timeout on ADDRESS_COMPLETE",unit);
E 3
I 3
D 6
	    printf("qd%d: setup_dragon: timeout on ADDRESS_COMPLETE\n", unit);
E 6
I 6
D 10
	    printf("\nqd%d: setup_dragon: timeout on ADDRESS_COMPLETE",unit);
E 10
I 10
D 11
	       printf("\nqd%d: setup_dragon: timeout on ADDRESS_COMPLETE",unit);
E 11
I 11
	       printf("qd%d: setup_dragon: timeout on ADDRESS_COMPLETE\n",unit);
E 11
E 10
E 6
E 3

	write_ID(adder, LEFT_SCROLL_MASK, 0x0000);
	write_ID(adder, RIGHT_SCROLL_MASK, 0x0000);
D 10

D 3
/*------------------------------------------------------------
* set source and the mask register to all ones (ie: white) */
E 3
I 3
D 6
	/*------------------------------------------------------------
	* set source and the mask register to all ones (ie: white) */
E 6
I 6
/*------------------------------------------------------------
* set source and the mask register to all ones (ie: white) */
E 6
E 3

E 10
I 10
	/*
	* set source and the mask register to all ones (ie: white) o
	*/
E 10
	write_ID(adder, SOURCE, 0xFFFF);
	write_ID(adder, MASK_1, 0xFFFF);
	write_ID(adder, VIPER_Z_LOAD | FOREGROUND_COLOR_Z, 255);
	write_ID(adder, VIPER_Z_LOAD | BACKGROUND_COLOR_Z, 0);
D 10

D 3
/*--------------------------------------------------------------
* initialize Operand Control Register banks for fill command */
E 3
I 3
D 6
	/*--------------------------------------------------------------
	* initialize Operand Control Register banks for fill command */
E 6
I 6
/*--------------------------------------------------------------
* initialize Operand Control Register banks for fill command */
E 6
E 3

E 10
I 10
	/*
	* initialize Operand Control Register banks for fill command 
	*/
E 10
	write_ID(adder, SRC1_OCR_A, EXT_NONE | INT_M1_M2  | NO_ID | WAIT);
	write_ID(adder, SRC2_OCR_A, EXT_NONE | INT_SOURCE | NO_ID | NO_WAIT);
	write_ID(adder, DST_OCR_A, EXT_NONE | INT_NONE	 | NO_ID | NO_WAIT);
D 10

E 10
	write_ID(adder, SRC1_OCR_B, EXT_NONE | INT_SOURCE | NO_ID | WAIT);
	write_ID(adder, SRC2_OCR_B, EXT_NONE | INT_M1_M2  | NO_ID | NO_WAIT);
	write_ID(adder, DST_OCR_B, EXT_NONE | INT_NONE | NO_ID | NO_WAIT);
D 10

D 3
/*------------------------------------------------------------------
* init Logic Unit Function registers, (these are just common values,
E 3
I 3
D 6
	/*------------------------------------------------------------------
	* init Logic Unit Function registers, (these are just common values,
E 6
I 6
/*------------------------------------------------------------------
* init Logic Unit Function registers, (these are just common values,
E 6
E 3
* and may be changed as required).  */

E 10
I 10
	/*
	* init Logic Unit Function registers, (these are just common values,
	* and may be changed as required).  
	*/
E 10
	write_ID(adder, LU_FUNCTION_R1, FULL_SRC_RESOLUTION | LF_SOURCE);
D 10
	write_ID(adder, LU_FUNCTION_R2, FULL_SRC_RESOLUTION | LF_SOURCE | INV_M1_M2);
E 10
I 10
	write_ID(adder, LU_FUNCTION_R2, FULL_SRC_RESOLUTION | LF_SOURCE |
		 INV_M1_M2);
E 10
	write_ID(adder, LU_FUNCTION_R3, FULL_SRC_RESOLUTION | LF_D_OR_S);
	write_ID(adder, LU_FUNCTION_R4, FULL_SRC_RESOLUTION | LF_D_XOR_S);
I 10
	/*
	* load the color map for black & white 
	*/
D 11
	for ( i = 0, adder->status = 0; i < 10000  &&  
E 11
I 11
	for (i = 0, adder->status = 0; i < 10000 && !(adder->status&VSYNC); ++i)
		;

	if (i == 0)
		printf("qd%d: setup_dragon: timeout on VSYNC\n", unit);

	red = (short *) qdmap[unit].red;
	green = (short *) qdmap[unit].green;
	blue = (short *) qdmap[unit].blue;

	*red++ = 0x00;			/* black */
	*green++ = 0x00;
	*blue++ = 0x00;

	*red-- = 0xFF;			/* white */
	*green-- = 0xFF;
	*blue-- = 0xFF;

	/*
	* set color map for mouse cursor 
	*/

	red += 254;
	green += 254;
	blue += 254;

	*red++ = 0x00;			/* black */
	*green++ = 0x00;
	*blue++ = 0x00;

	*red = 0xFF;			/* white */
	*green = 0xFF;
	*blue = 0xFF;

} /* setup_dragon */

/*
 * Init the DUART and set defaults in input
 */
setup_input(unit)
	int unit;
{
	register struct duart *duart;	/* DUART register structure pointer */
	register i, bits;
	char id_byte;

	duart = (struct duart *) qdmap[unit].duart;
	duart->imask = 0;

	/*
	* setup the DUART for kbd & pointing device 
	*/
	duart->cmdA = RESET_M;	/* reset mode reg ptr for kbd */
	duart->modeA = 0x13;	/* 8 bits, no parity, rcv IE, */
				/* no RTS control,char error mode */
	duart->modeA = 0x07;	/* 1 stop bit,CTS does not IE XMT */
				/* no RTS control,no echo or loop */
	duart->cmdB = RESET_M;	/* reset mode reg pntr for host */
	duart->modeB = 0x07;	/* 8 bits, odd parity, rcv IE.. */
				/* ..no RTS cntrl, char error mode */
	duart->modeB = 0x07;	/* 1 stop bit,CTS does not IE XMT */
				/* no RTS control,no echo or loop */
	duart->auxctl = 0x00;	/* baud rate set 1 */
	duart->clkselA = 0x99;	/* 4800 baud for kbd */
	duart->clkselB = 0x99;	/* 4800 baud for mouse */

	/* reset everything for keyboard */

	for (bits = RESET_M; bits < START_BREAK; bits += 0x10)
		duart->cmdA = bits;

	/* reset everything for host */

	for (bits = RESET_M; bits < START_BREAK; bits += 0x10)
		duart->cmdB = bits;

	duart->cmdA = EN_RCV | EN_XMT; /* enbl xmt & rcv for kbd */
	duart->cmdB = EN_RCV | EN_XMT; /* enbl xmt & rcv for pointer device */

	/*
	* init keyboard defaults (DUART channel A) 
	*/
	for (i = 500; i > 0; --i) {
		if (duart->statusA&XMT_RDY) {
			duart->dataA = LK_DEFAULTS;
			break;
		}
	}

	for (i = 100000; i > 0; --i) {
		if (duart->statusA&RCV_RDY) {
			break;
		}
	}

	if (duart->dataA)	/* flush the ACK */
		;		

	/*
	* identify the pointing device 
	*/
	for (i = 500; i > 0; --i) {
		if (duart->statusB&XMT_RDY) {
			duart->dataB = SELF_TEST;
			break;
		}
	}

	/*
	* wait for 1st byte of self test report */

	for (i = 100000; i > 0; --i) {
		if (duart->statusB&RCV_RDY) {
			break;
		}
	}

	if (i == 0) {
		printf("qd[%d]: setup_input: timeout on 1st byte of self test\n"
		       ,unit);
		goto OUT;
	}

	if (duart->dataB)
		;

	/*
	* wait for ID byte of self test report	
	*/
	for (i = 100000; i > 0; --i) {
		if (duart->statusB&RCV_RDY) {
			break;
		}
	}

	if (i == 0) {
		printf("qd[%d]: setup_input: timeout on 2nd byte of self test\n", unit);
		goto OUT;
	}

	id_byte = duart->dataB;

	/*
	* wait for other bytes to come in  
	*/
	for (i = 100000; i > 0; --i) {
		if (duart->statusB & RCV_RDY) {
			if (duart->dataB)
				;
			break;
		}
	}
	if (i == 0) {
		printf("qd[%d]: setup_input: timeout on 3rd byte of self test\n", unit);
		goto OUT;
	}
	for (i = 100000; i > 0; --i) {
		if (duart->statusB&RCV_RDY) {
			if (duart->dataB)
				;
			break;
		}
	}
	if (i == 0) {
		printf("qd[%d]: setup_input: timeout on 4th byte of self test\n", unit);
		goto OUT;
	}
	/*
	* flag pointing device type and set defaults 
	*/
	for (i=100000; i>0; --i)
		;		/*XXX*/

	if ((id_byte & 0x0F) != TABLET_ID) {
		qdflags[unit].pntr_id = MOUSE_ID;

		for (i = 500; i > 0; --i) {
			if (duart->statusB&XMT_RDY) {
				duart->dataB = INC_STREAM_MODE;
D 12
				break;
			}
		}
	} 
	else {
		qdflags[unit].pntr_id = TABLET_ID;

		for (i = 500; i > 0; --i) {
			if (duart->statusB&XMT_RDY) {
				duart->dataB = T_STREAM;
E 12
				break;
			}
		}
I 12
	} 
	else {
		qdflags[unit].pntr_id = TABLET_ID;

		for (i = 500; i > 0; --i) {
			if (duart->statusB&XMT_RDY) {
				duart->dataB = T_STREAM;
				break;
			}
		}
E 12
	}
OUT:
	duart->imask = qdflags[unit].duart_imask;

} /* setup_input */

/*
 * delay for at least one display frame time
 *
 *	return: BAD means that we timed out without ever seeing the
 *		      vertical sync status bit
 *		GOOD otherwise
 */
wait_status(adder, mask)
	register struct adder *adder;
	register int mask;
{
	register i;

	for (i = 10000, adder->status = 0 ; i > 0  &&  
	     !(adder->status&mask) ; --i)
		;

	if (i == 0) {
		printf("wait_status: timeout polling for 0x%x in adder->status\n", mask);
		return(BAD);
	}

	return(GOOD);

} /* wait_status */

/*
 * write out onto the ID bus
 */
write_ID(adder, adrs, data)
	register struct adder *adder;
	register short adrs;
	register short data;
{
	register i;

	for (i = 100000, adder->status = 0 ; 
	      i > 0  &&  !(adder->status&ADDRESS_COMPLETE) ; --i)
		;

	if (i == 0)
		goto ERR;

	for (i = 100000, adder->status = 0 ; 
	      i > 0  &&  !(adder->status&TX_READY) ; --i)
		;

	if (i > 0) {
		adder->id_data = data;
		adder->command = ID_LOAD | adrs;
		return ;
	}

ERR:
	printf("write_ID: timeout trying to write to VIPER\n");
	return ;

} /* write_ID */
#endif
E 11
D 11
	      !((status = adder->status) & VSYNC) ; ++i)
		;
E 10

D 3
/*----------------------------------------
* load the color map for black & white */
E 3
I 3
D 6
	/*----------------------------------------
	* load the color map for black & white */
E 6
I 6
D 10
/*----------------------------------------
* load the color map for black & white */
E 6
E 3

	for ( i = 0, adder->status = 0
	    ; i < 10000  &&  !((status = adder->status) & VSYNC)
	    ; ++i);

E 10
	if (i == 0)
D 3
	    mprintf("\nqd%d: setup_dragon: timeout on VSYNC", unit);
E 3
I 3
D 6
	    printf("qd%d: setup_dragon: timeout on VSYNC\n", unit);
E 6
I 6
	    printf("\nqd%d: setup_dragon: timeout on VSYNC", unit);
E 6
E 3

	red = (short *) qdmap[unit].red;
	green = (short *) qdmap[unit].green;
	blue = (short *) qdmap[unit].blue;

	*red++ = 0x00;			/* black */
	*green++ = 0x00;
	*blue++ = 0x00;

	*red-- = 0xFF;			/* white */
	*green-- = 0xFF;
	*blue-- = 0xFF;

D 10
	/*----------------------------------
E 10
I 10
	/*
E 10
	* set color map for mouse cursor */

	red += 254;
	green += 254;
	blue += 254;

	*red++ = 0x00;			/* black */
	*green++ = 0x00;
	*blue++ = 0x00;

	*red = 0xFF;			/* white */
	*green = 0xFF;
	*blue = 0xFF;

	return(0);

} /* setup_dragon */

/******************************************************************
*
*	setup_input()... init the DUART and set defaults in input
*			 devices
*
*******************************************************************
*
*	calling convention:
*
*		setup_input(unit);
*
*	where: unit - is the QDSS unit number to be setup
*
*********/

setup_input(unit)
u_int unit;
{
	register struct duart *duart;	/* DUART register structure pointer */
	register int i; 		/* scratch variable */
	register int bits;
D 10

E 10
	char id_byte;
	short status;

D 3
/*---------------
* init stuff */
E 3
I 3
D 6
	/*---------------
	* init stuff */
E 6
I 6
D 10
/*---------------
* init stuff */
E 6
E 3

E 10
	duart = (struct duart *) qdmap[unit].duart;
	duart->imask = 0;

D 3
/*---------------------------------------------
* setup the DUART for kbd & pointing device */
E 3
I 3
D 6
	/*---------------------------------------------
	* setup the DUART for kbd & pointing device */
E 6
I 6
D 10
/*---------------------------------------------
* setup the DUART for kbd & pointing device */
E 6
E 3

E 10
I 10
	/*
	* setup the DUART for kbd & pointing device 
	*/
E 10
	duart->cmdA = RESET_M;	  /* reset mode reg ptr for kbd */
	duart->modeA = 0x13;	  /* 8 bits, no parity, rcv IE, */
D 10
				  /* no RTS control,char error mode */
E 10
I 10
	/* no RTS control,char error mode */
E 10
	duart->modeA = 0x07;	  /* 1 stop bit,CTS does not IE XMT */
D 10
				  /* no RTS control,no echo or loop */
E 10
I 10
	/* no RTS control,no echo or loop */
E 10
	duart->cmdB = RESET_M;	  /* reset mode reg pntr for host */
	duart->modeB = 0x07;	  /* 8 bits, odd parity, rcv IE.. */
D 10
				  /* ..no RTS cntrl, char error mode */
E 10
I 10
	/* ..no RTS cntrl, char error mode */
E 10
	duart->modeB = 0x07;	  /* 1 stop bit,CTS does not IE XMT */
D 10
				  /* no RTS control,no echo or loop */
E 10
I 10
	/* no RTS control,no echo or loop */
E 10

	duart->auxctl = 0x00;	  /* baud rate set 1 */

	duart->clkselA = 0x99;	  /* 4800 baud for kbd */
	duart->clkselB = 0x99;	  /* 4800 baud for mouse */

	/* reset everything for keyboard */

	for (bits = RESET_M; bits < START_BREAK; bits += 0x10)
D 10
	    duart->cmdA = bits;
E 10
I 10
		duart->cmdA = bits;
E 10

	/* reset everything for host */

	for (bits = RESET_M; bits < START_BREAK; bits += 0x10)
D 10
	     duart->cmdB = bits;
E 10
I 10
		duart->cmdB = bits;
E 10

	duart->cmdA = EN_RCV | EN_XMT; /* enbl xmt & rcv for kbd */
	duart->cmdB = EN_RCV | EN_XMT; /* enbl xmt & rcv for pointer device */

D 3
/*--------------------------------------------
* init keyboard defaults (DUART channel A) */
E 3
I 3
D 6
	/*--------------------------------------------
	* init keyboard defaults (DUART channel A) */
E 6
I 6
D 10
/*--------------------------------------------
* init keyboard defaults (DUART channel A) */
E 10
I 10
	/*
	* init keyboard defaults (DUART channel A) */
E 10
E 6
E 3

	for (i = 500; i > 0; --i) {
D 10
	    if ((status = duart->statusA) & XMT_RDY) {
		duart->dataA = LK_DEFAULTS;
		break;
	    }
E 10
I 10
		if ((status = duart->statusA) & XMT_RDY) {
			duart->dataA = LK_DEFAULTS;
			break;
		}
E 10
	}

	for (i = 100000; i > 0; --i) {
D 10
	    if ((status = duart->statusA) & RCV_RDY) {
		break;
	    }
E 10
I 10
		if ((status = duart->statusA) & RCV_RDY) {
			break;
		}
E 10
	}

	status = duart->dataA;		/* flush the ACK */

D 3
/*--------------------------------
* identify the pointing device */
E 3
I 3
D 6
	/*--------------------------------
	* identify the pointing device */
E 6
I 6
D 10
/*--------------------------------
* identify the pointing device */
E 10
I 10
	/*
	* identify the pointing device */
E 10
E 6
E 3

	for (i = 500; i > 0; --i) {
D 10
	    if ((status = duart->statusB) & XMT_RDY) {
		duart->dataB = SELF_TEST;
		break;
	    }
E 10
I 10
		if ((status = duart->statusB) & XMT_RDY) {
			duart->dataB = SELF_TEST;
			break;
		}
E 10
	}

D 10
	/*-----------------------------------------
E 10
I 10
	/*
E 10
	* wait for 1st byte of self test report */

	for (i = 100000; i > 0; --i) {
D 10
	    if ((status = duart->statusB) & RCV_RDY) {
		break;
	    }
E 10
I 10
		if ((status = duart->statusB) & RCV_RDY) {
			break;
		}
E 10
	}

	if (i == 0) {
D 3
	    mprintf("\nqd[%d]: setup_input: timeout on 1st byte of self test",unit);
E 3
I 3
D 6
	    printf("qd[%d]: setup_input: timeout on 1st byte of self test\n",
		   unit);
E 6
I 6
D 10
	    printf("\nqd[%d]: setup_input: timeout on 1st byte of self test",unit);
E 6
E 3
	    goto OUT;
E 10
I 10
		printf("\nqd[%d]: setup_input: timeout on 1st byte of self test"
		       ,unit);
		goto OUT;
E 10
	}

	status = duart->dataB;

D 10
	/*-----------------------------------------
E 10
I 10
	/*
E 10
	* wait for ID byte of self test report	*/

	for (i = 100000; i > 0; --i) {
D 10
	    if ((status = duart->statusB) & RCV_RDY) {
		break;
	    }
E 10
I 10
		if ((status = duart->statusB) & RCV_RDY) {
			break;
		}
E 10
	}

	if (i == 0) {
D 3
	    mprintf("\nqd[%d]: setup_input: timeout on 2nd byte of self test", unit);
E 3
I 3
D 6
	    printf("qd[%d]: setup_input: timeout on 2nd byte of self test\n",
		   unit);
E 6
I 6
D 10
	    printf("\nqd[%d]: setup_input: timeout on 2nd byte of self test", unit);
E 6
E 3
	    goto OUT;
E 10
I 10
		printf("\nqd[%d]: setup_input: timeout on 2nd byte of self test", unit);
		goto OUT;
E 10
	}

	id_byte = duart->dataB;

D 10
	/*------------------------------------
E 10
I 10
	/*
E 10
	* wait for other bytes to come in  */

	for (i = 100000; i > 0; --i) {
D 10
	    if ((status = duart->statusB) & RCV_RDY) {
		status = duart->dataB;
		break;
	    }
E 10
I 10
		if ((status = duart->statusB) & RCV_RDY) {
			status = duart->dataB;
			break;
		}
E 10
	}

	if (i == 0) {
D 3
	    mprintf("\nqd[%d]: setup_input: timeout on 3rd byte of self test", unit);
E 3
I 3
D 6
	    printf("qd[%d]: setup_input: timeout on 3rd byte of self test\n",
		   unit);
E 6
I 6
D 10
	    printf("\nqd[%d]: setup_input: timeout on 3rd byte of self test", unit);
E 6
E 3
	    goto OUT;
E 10
I 10
		printf("\nqd[%d]: setup_input: timeout on 3rd byte of self test", unit);
		goto OUT;
E 10
	}

	for (i = 100000; i > 0; --i) {
D 10
	    if ((status = duart->statusB) & RCV_RDY) {
		status = duart->dataB;
		break;
	    }
E 10
I 10
		if ((status = duart->statusB) & RCV_RDY) {
			status = duart->dataB;
			break;
		}
E 10
	}

	if (i == 0) {
D 3
	    mprintf("\nqd[%d]: setup_input: timeout on 4th byte of self test\n", unit);
E 3
I 3
D 6
	    printf("qd[%d]: setup_input: timeout on 4th byte of self test\n",
		   unit);
E 6
I 6
D 10
	    printf("\nqd[%d]: setup_input: timeout on 4th byte of self test\n", unit);
E 6
E 3
	    goto OUT;
E 10
I 10
		printf("\nqd[%d]: setup_input: timeout on 4th byte of self test\n", unit);
		goto OUT;
E 10
	}

D 10
	/*----------------------------------------------
E 10
I 10
	/*
E 10
	* flag pointing device type and set defaults */

	for (i=100000; i>0; --i);

	if ((id_byte & 0x0F) != TABLET_ID) {

D 10
	    qdflags[unit].pntr_id = MOUSE_ID;
E 10
I 10
		qdflags[unit].pntr_id = MOUSE_ID;
E 10

D 10
	    for (i = 500; i > 0; --i) {
		if ((status = duart->statusB) & XMT_RDY) {
		    duart->dataB = INC_STREAM_MODE;
		    break;
E 10
I 10
		for (i = 500; i > 0; --i) {
			if ((status = duart->statusB) & XMT_RDY) {
				duart->dataB = INC_STREAM_MODE;
				break;
			}
E 10
		}
D 10
	    }
	} else {
E 10
I 10
	} 
	else {
E 10

D 10
	    qdflags[unit].pntr_id = TABLET_ID;
E 10
I 10
		qdflags[unit].pntr_id = TABLET_ID;
E 10

D 10
	    for (i = 500; i > 0; --i) {
		if ((status = duart->statusB) & XMT_RDY) {
		    duart->dataB = T_STREAM;
		    break;
E 10
I 10
		for (i = 500; i > 0; --i) {
			if ((status = duart->statusB) & XMT_RDY) {
				duart->dataB = T_STREAM;
				break;
			}
E 10
		}
D 10
	    }
E 10
	}

D 3
/*--------
* exit */
E 3
I 3
D 6
	/*--------
	* exit */
E 6
I 6
D 10
/*--------
* exit */
E 10
I 10
	/*
	* exit */
E 10
E 6
E 3

OUT:
	duart->imask = qdflags[unit].duart_imask;
	return(0);

} /* setup_input */

/**********************************************************************
*
*	wait_status()... delay for at least one display frame time
*
***********************************************************************
*
*	calling convention:
*
*		wait_status(adder, mask);
*		struct *adder adder;
*		int mask;
*
*	return: BAD means that we timed out without ever seeing the
*		      vertical sync status bit
*		GOOD otherwise
*
**************/

wait_status(adder, mask)
D 10
register struct adder *adder;
register int mask;
E 10
I 10
	register struct adder *adder;
	register int mask;
E 10
{
	register short status;
	int i;

D 10
	for ( i = 10000, adder->status = 0
	    ; i > 0  &&  !((status = adder->status) & mask)
	    ; --i);
E 10
I 10
	for ( i = 10000, adder->status = 0 ; i > 0  &&  
	     !((status = adder->status) & mask) ; --i)
		;
E 10

	if (i == 0) {
D 3
	    mprintf("\nwait_status: timeout polling for 0x%x in adder->status", mask);
E 3
I 3
D 6
	    printf("wait_status: timeout polling for 0x%x in adder->status\n",
		   mask);
E 6
I 6
D 10
	    printf("\nwait_status: timeout polling for 0x%x in adder->status", mask);
E 6
E 3
	    return(BAD);
E 10
I 10
		printf("\nwait_status: timeout polling for 0x%x in adder->status", mask);
		return(BAD);
E 10
	}

	return(GOOD);

} /* wait_status */

/**********************************************************************
*
*	write_ID()... write out onto the ID bus
*
***********************************************************************
*
*	calling convention:
*
*		struct *adder adder;	;pntr to ADDER structure
*		short adrs;		;VIPER address
*		short data;		;data to be written
*		write_ID(adder);
*
*	return: BAD means that we timed out waiting for status bits
*		      VIPER-access-specific status bits
*		GOOD otherwise
*
**************/

write_ID(adder, adrs, data)
D 10
register struct adder *adder;
register short adrs;
register short data;
E 10
I 10
	register struct adder *adder;
	register short adrs;
	register short data;
E 10
{
	int i;
	short status;

D 3
	for ( i = 100000, adder->status = 0
	    ; i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE)
	    ; --i);
E 3
I 3
D 6
	for ( i = 100000, adder->status = 0;
	      i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE); --i)
		;
E 6
I 6
D 10
	for ( i = 100000, adder->status = 0
	    ; i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE)
	    ; --i);
E 10
I 10
	for ( i = 100000, adder->status = 0 ; 
	      i > 0  &&  !((status = adder->status) & ADDRESS_COMPLETE) ;
	      --i)
		;
E 10
E 6
E 3

	if (i == 0)
	    goto ERR;

D 3
	for ( i = 100000, adder->status = 0
	    ; i > 0  &&  !((status = adder->status) & TX_READY)
	    ; --i);
E 3
I 3
D 6
	for ( i = 100000, adder->status = 0;
	      i > 0  &&  !((status = adder->status) & TX_READY); --i)
		;
E 6
I 6
D 10
	for ( i = 100000, adder->status = 0
	    ; i > 0  &&  !((status = adder->status) & TX_READY)
	    ; --i);
E 10
I 10
	for ( i = 100000, adder->status = 0 ; 
	      i > 0  &&  !((status = adder->status) & TX_READY) ; --i)
		;
E 10
E 6
E 3

	if (i > 0) {
D 10
	    adder->id_data = data;
	    adder->command = ID_LOAD | adrs;
	    return(GOOD);
E 10
I 10
		adder->id_data = data;
		adder->command = ID_LOAD | adrs;
		return(GOOD);
E 10
	}

ERR:
D 3
	mprintf("\nwrite_ID: timeout trying to write to VIPER");
E 3
I 3
D 6
	printf("write_ID: timeout trying to write to VIPER\n");
E 6
I 6
	printf("\nwrite_ID: timeout trying to write to VIPER");
E 6
E 3
	return(BAD);

} /* write_ID */
I 6
D 10

E 10
E 6
I 3
#endif
E 11
E 3
E 1
