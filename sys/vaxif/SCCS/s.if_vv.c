h35605
s 00036/00017/01000
d D 7.4 88/10/22 16:57:55 karels 51 50
c automatic priority calculation with qbgetpri; flags-handling fixes
e
s 00036/00031/00981
d D 7.3 88/10/12 22:10:46 karels 50 49
c fixes from proteon:
c D 6.22  88/03/08 16:36:44       jas     48      47      00018/00013/00988
c Increase default VVMTU, and correct allocation for trailer header.
c Pass VVMRU to ubainit, not VVMTU.
c Fix bug in non-class C address setting.
c 
c D 6.21  88/03/08 16:05:01       jas     47      46      00005/00005/00996
c Mask data being placed into ubainfo down to 18 bits, don't rely on
c p1000/p1100 masking it down in hardware.
e
s 00013/00002/00999
d D 7.2 88/08/04 15:31:15 bostic 49 48
c add Berkeley specific copyright
e
s 00001/00001/01000
d D 7.1 86/06/05 17:12:02 mckusick 48 47
c 4.3BSD release version
e
s 00004/00004/00997
d D 6.21 86/06/02 14:45:57 karels 47 46
c lint
e
s 00013/00012/00988
d D 6.20 86/03/27 16:23:05 jas 46 45
c New trailer scheme that is not antisocial
c 
e
s 00035/00028/00965
d D 6.19 86/03/18 19:02:09 jas 45 44
c - Correct comments about old HSBU's, explain addition of UBA_NEED16
c - Added method of setting 80-megabitness via flags
c - Eliminated inifinite loop as splimp() in vvidentify()
c - Eliminate double start of timeout in vvstart()
c - Put all 16-bit fields in trailer packets (type and length) in proper
c   network byte order (bigindian)
c - Have vvioctl() return an error if self testing by vvinit()/vvidentify()
c   fails
c 				john shriver, proteon
c 
e
s 00002/00002/00991
d D 6.18 86/02/23 23:30:08 karels 44 43
c lint
e
s 00006/00004/00987
d D 6.17 86/02/21 11:47:59 karels 43 42
c missed one; use a #define for nasty number
e
s 00004/00004/00987
d D 6.16 86/02/20 20:23:18 karels 42 40
c lint
e
s 00004/00004/00987
d R 6.16 86/02/20 17:13:41 karels 41 40
c 
e
s 00001/00001/00990
d D 6.15 86/02/17 14:34:44 karels 40 39
c don't NEED16
e
s 00000/00003/00991
d D 6.14 85/12/19 15:48:16 karels 39 38
c rm bbnnet
e
s 00002/00000/00992
d D 6.13 85/10/24 10:07:48 bloom 38 37
c add "#if N?? > 0" 
e
s 00001/00001/00991
d D 6.12 85/10/14 17:07:49 karels 37 36
c minor nit
e
s 00015/00000/00977
d D 6.11 85/10/13 20:00:00 karels 36 35
c missing vvprt_hdr
e
s 00017/00008/00960
d D 6.10 85/09/16 22:21:55 karels 35 34
c pass ifp to if_{r,}ubaget, shuffle it up if receiving trailer
e
s 00007/00001/00961
d D 6.9 85/06/08 14:01:09 mckusick 34 33
c Add copyright
e
s 00034/00077/00928
d D 6.8 85/06/03 08:42:10 karels 33 32
c now they compile at least
e
s 00321/00148/00684
d D 6.7 85/05/22 13:32:24 karels 32 31
c from proteon
e
s 00011/00011/00821
d D 6.6 84/08/29 20:44:41 bloom 31 30
c change ot includes.  no more ../h
e
s 00062/00031/00770
d D 6.5 84/06/07 14:49:28 karels 30 29
c new version from leres
e
s 00098/00050/00703
d D 6.4 84/01/03 18:35:05 leres 29 28
c In vvidentify(), avoid losing a mbuf on failure; also remove an UBAPURGE.
c Raise to spl imp when accessing mbuf queues in vvoutput() in vvstart().
c Add vvwatchdog() and implement packet transmit timeout.
c Make printfs unique (and imformative) when dropping packets in vvrint()
c and take unnecessary mbuf queue test out of end of vvxint().
c Keep track of hardware address of last packet received in vs_lastr.
e
s 00000/00007/00753
d D 6.3 83/12/22 19:55:52 leres 28 27
c Remove software loopback code; it probably eats mbufs since looutput()
c lowers the ipl. (See what I get for reading net.wizards?)
e
s 00105/00273/00655
d D 6.2 83/12/22 13:18:19 leres 27 25
c Major league reorganization; fixed the N+1 bugs that kept broadcasts
c from working. Removed the (too) elaborate error recovery code. (Only
c impossible error rates would invoke it anyway...) Use the software
c loopback for local-bound packets.
e
s 00105/00273/00655
d R 6.2 83/12/22 12:34:38 leres 26 25
c Major league reorganization; fixed the N+1 bugs that kept broadcasts
c from working. Removed the (too) elaborate error recovery code. (Only
c impossible error rates would invoke it anyway...) Use the software
c loopback for local-bound packets.
e
s 00000/00000/00928
d D 6.1 83/07/29 07:38:48 sam 25 24
c 4.2 distribution
e
s 00005/00003/00923
d D 4.22 83/06/13 22:47:14 sam 24 23
c lint
e
s 00046/00019/00880
d D 4.21 83/06/12 23:13:54 sam 23 22
c ioctls and trailers
e
s 00009/00006/00890
d D 4.20 83/05/27 13:50:57 sam 22 21
c lint
e
s 00001/00001/00895
d D 4.19 83/05/10 18:48:17 sam 21 20
c incorrect check on header lengths; from rws@mit-xx
e
s 00005/00000/00891
d D 4.18 83/05/10 11:48:07 mo 20 19
c added "don't chew up 750 bdp's" code
e
s 00002/00003/00889
d D 4.17 83/05/10 11:17:05 mo 19 17
c missed a sleep() and removed UNTESTED comment
e
s 00004/00004/00888
d R 4.17 83/05/10 10:54:58 mo 18 17
c changed sleeps on lbolt to delays 'cause lbolt doesn't run 
e
s 00001/00001/00891
d D 4.16 83/05/01 19:32:54 sam 17 16
c improper check on output length; from rws@mit-xx
e
s 00001/00002/00891
d D 4.15 83/05/01 18:17:20 sam 16 15
c too early in system startup to sleep
e
s 00088/00146/00805
d D 4.14 83/02/21 16:57:44 sam 15 14
c various cleanups and conversions to 4.1c
e
s 00330/00064/00621
d D 4.13 83/02/20 23:36:11 sam 14 13
c new version from mike odell
e
s 00005/00002/00680
d D 4.12 82/12/23 00:49:42 sam 13 12
c hadn't been updated in a while
e
s 00005/00001/00677
d D 4.11 82/12/17 12:14:47 sam 12 11
c sun merge
e
s 00002/00002/00676
d D 4.10 82/12/14 17:22:17 sam 11 10
c typed mbufs
e
s 00001/00001/00677
d D 4.9 82/10/31 15:05:54 root 10 8
c ubareset routines now just if_reset!
e
s 00001/00001/00677
d R 4.9 82/10/24 14:38:47 wnj 9 8
c create netif directory
e
s 00009/00009/00669
d D 4.8 82/10/10 17:03:15 root 8 7
c put vax headers in their place
e
s 00008/00006/00670
d D 4.7 82/10/09 06:11:47 wnj 7 6
c fix includes
e
s 00188/00105/00488
d D 4.6 82/08/01 19:33:37 sam 6 5
c lots of changes from mo@lbl-unix, but I couldn't keep my 
c bloody hands off it -- forgive me mike
e
s 00000/00005/00593
d D 4.5 82/06/20 00:53:35 sam 5 4
c purge COUNT stuff now that we can use gprof
e
s 00003/00000/00595
d D 4.4 82/06/15 21:02:30 sam 4 3
c didn't set IFF_UP properly
e
s 00000/00041/00595
d D 4.3 82/06/13 23:01:09 sam 3 2
c add class a/b/c net #'s and purge logical host kludge code
e
s 00002/00002/00634
d D 4.2 82/06/12 23:22:21 wnj 2 1
c now routing code might work
e
s 00636/00000/00000
d D 4.1 82/06/04 10:57:08 sam 1 0
c date and time created 82/06/04 10:57:08 by sam
e
u
U
t
T
I 1
D 34
/*	%M%	%I%	%E%	*/
E 34
I 34
/*
D 48
 * Copyright (c) 1982 Regents of the University of California.
E 48
I 48
D 51
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 51
I 51
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 51
E 48
D 49
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 49
I 49
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
E 49
 *
 *	%W% (Berkeley) %G%
 */
E 34

I 12
#include "vv.h"
I 38
#if NVV > 0
E 38
D 14
#if NVV > 0
E 14
I 14

E 14
E 12
/*
D 32
 * Proteon 10 Meg Ring Driver.
 * This device is called "vv" because its "real name",
 * V2LNI won't work if shortened to the obvious "v2".
 * Hence the subterfuge.
E 32
I 32
D 50
 * Proteon proNET-10 and proNET-80 token ring driver.
E 50
I 50
 * Proteon ProNET-10 and ProNET-80 token ring driver.
E 50
 * The name of this device driver derives from the old MIT
 * name of V2LNI for the proNET hardware, would would abbreviate
D 50
 * to "v2", but this won't work right. Thus the name is "vv".
E 50
I 50
 * to "v2", but this won't work right in config. Thus the name is "vv".
E 50
E 32
I 14
 *
I 32
D 50
 * This driver is compatible with the proNET 10 meagbit and
E 50
I 50
 * This driver is compatible with the Unibus ProNET 10 megabit and
E 50
 * 80 megabit token ring interfaces (models p1000 and p1080).
I 45
 * A unit may be marked as 80 megabit using "flags 1" in the
 * config file.
E 45
 *
I 50
 * This driver is also compatible with the Q-bus ProNET 10 megabit and
 * 80 megabit token ring interfaces (models p1100 and p1180), but
 * only on a MicroVAX-II or MicroVAX-III.  No attempt is made to
 * support the MicroVAX-I.
 *
E 50
D 46
 * TRAILERS: You must turn off trailers via ifconfig if you want to share
 * a ring with software using the following protocol types:
 *  3: Address Resolution Protocol
 *  4: HDLC (old Proteon drivers)
 *  5: VAX Debugging Protocol (never used)
 * This is because the protocol type values chosen for trailers
 * conflict with these protocols. It's too late to change either now.
E 46
I 46
 * TRAILERS: This driver has a new implementation of trailers that
 * is at least a tolerable neighbor on the ring. The offset is not
 * stored in the protocol type, but instead only in the vh_info
 * field. Also, the vh_info field, and the two shorts before the
 * trailing header, are in network byte order, not VAX byte order.
E 46
 *
I 46
 * Of course, nothing but BSD UNIX supports trailers on ProNET.
D 50
 * If you need interoperability with anything else, turn off
 * trailers using the -trailers option to /etc/ifconfig!
E 50
I 50
 * If you need interoperability with anything else (like the p4200),
 * turn off trailers using the -trailers option to /etc/ifconfig!
E 50
 *
E 46
D 45
 * HARDWARE COMPATABILITY: This driver requires that the HSBU (p1001)
E 45
I 45
 * HARDWARE COMPATABILITY: This driver prefers that the HSBU (p1001)
E 45
 * have a serial number >= 040, which is about March, 1982. Older
D 45
 * HSBUs do not carry across 64kbyte boundaries. The old warning
 * about use without Wire Centers applies only to CTL (p1002) cards with
 * serial <= 057, which have not received ECO 176-743, which was
 * implemented in March, 1982. Most such CTLs have received this ECO,
 * but they are only compatible with the old HSBUs (<=039) anyways.
E 45
I 45
 * HSBUs do not carry across 64kbyte boundaries. They can be supported
 * by adding "| UBA_NEED16" to the vs_ifuba.ifu_flags initialization
 * in vvattach().
 *
 * The old warning about use without Wire Centers applies only to CTL
 * (p1002) cards with serial <= 057, which have not received ECO 176-743,
 * which was implemented in March, 1982. Most such CTLs have received
 * this ECO.
E 45
E 32
D 15
 * MUST BE UPDATE FOR 4.1C
E 15
I 15
D 19
 * UNTESTED WITH 4.1C
E 19
E 15
E 14
 */
I 12
D 14
#include "../machine/pte.h"
E 14
I 14
D 15
#include "../h/pte.h"
E 15
I 15
#include "../machine/pte.h"
E 15
E 14

E 12
D 31
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 12
#include "../h/pte.h"
E 12
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
I 14
D 15
#include "../h/cpu.h"
#include "../h/mtpr.h"
E 15
E 14
D 8
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/cpu.h"
#include "../h/mtpr.h"
E 8
#include "../h/vmmac.h"
I 13
D 14
#include <time.h>
#include "../h/kernel.h"
E 13
D 7
#include "../net/in.h"
#include "../net/in_systm.h"
E 7
I 7
D 8
#ifdef INET
E 8
I 8
#include <errno.h>
E 14
I 14
#include "../h/errno.h"
I 15
D 29
#include "../h/time.h"
#include "../h/kernel.h"
E 29
I 23
#include "../h/ioctl.h"
E 31
I 31
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "errno.h"
#include "ioctl.h"
E 31
E 23
E 15
E 14

#include "../net/if.h"
I 15
#include "../net/netisr.h"
E 15
I 13
D 14
#include "../net/netisr.h"
E 14
E 13
#include "../net/route.h"
I 35

D 39
#ifdef	BBNNET
#define	INET
#endif
E 39
#ifdef	INET
E 35
I 14
D 29

E 29
E 14
E 8
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 33
#include "../netinet/in_var.h"
E 33
#include "../netinet/ip.h"
D 35
#include "../netinet/ip_var.h"
E 35
I 35
#endif
E 35
D 8
#endif
E 7
#include "../net/if.h"
E 8
I 8

D 14
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
E 14
E 8
D 7
#include "../net/if_vv.h"
#include "../net/if_uba.h"
#include "../net/ip.h"
#include "../net/ip_var.h"
E 7
I 7
D 15
#include "../vaxif/if_vv.h"
#include "../vaxif/if_uba.h"
E 15
I 15
D 29
#include "../vax/mtpr.h"
E 29
#include "../vax/cpu.h"
E 15
I 14
D 29

E 29
I 29
#include "../vax/mtpr.h"
D 31
#include "../vaxif/if_vv.h"
#include "../vaxif/if_uba.h"
E 31
I 31
#include "if_vv.h"
#include "if_uba.h"
E 31
E 29
E 14
E 7
D 8
#include "../net/route.h"
I 6
#include <errno.h>
E 8
I 8
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 8
E 6

I 15
D 29
#include "../vaxif/if_vv.h"
#include "../vaxif/if_uba.h"

E 29
E 15
D 14
#include "vv.h"
D 3
#include "imp.h"
E 3

E 14
/*
D 32
 * N.B. - if WIRECENTER is defined wrong, it can well break
 * the hardware!!
E 32
I 32
D 45
 * 80 megabit configuration
 * Uncomment the next line if you are using the 80 megabit system. The
 * only change is the disposition of packets with parity/link_data_error
 * indication.
E 32
 */
D 6
#undef AUTOIDENTIFY
E 6
I 6
D 15

E 15
E 6
D 32
#define	WIRECENTER
E 32
I 32
/* #define PRONET80 */
E 32

D 32
#ifdef WIRECENTER
#define	VV_CONF	VV_HEN		/* drive wire center relay */
#else
#define	VV_CONF	VV_STE		/* allow operation without wire center */
#endif
E 32
I 32
/*
E 45
 *    maximum transmission unit definition --
D 50
 *        you can set VVMTU at anything from 576 to 2024.
E 50
I 50
 *        you can set VVMTU at anything from 576 to 2036.
E 50
 *        1536 is a popular "large" value, because it is a multiple
 *	  of 512, which the trailer scheme likes.
D 50
 *        The absolute maximum size is 2024, which is enforced.
E 50
I 50
 *        The absolute maximum size is 2036, which is enforced.
E 50
 */
E 32

D 32
#define	VVMTU	(1024+512)
I 6
#define VVMRU	(1024+512+16)	/* space for trailer */
E 32
I 32
D 35
#define VVMTU (1024)
E 35
I 35
D 50
#define VVMTU (1536)
E 50
I 50
#define VVMTU (2036)
E 50
E 35
E 32
E 6

I 32
D 50
#define VVMRU (VVMTU + 16)
E 50
I 50
#define VVMRU (VVMTU + (2 * sizeof(u_short)))
E 50
#define VVBUFSIZE (VVMRU + sizeof(struct vv_header))
D 50
#if VVMTU>2024
E 50
I 50
#if VVMTU>2036
E 50
#undef VVMTU
#undef VVMRU
#undef VVBUFSIZE
#define VVBUFSIZE (2046)
#define VVMRU (VVBUFSIZE - sizeof (struct vv_header))
D 50
#define VVMTU (VVMRU - 16)
E 50
I 50
#define VVMTU (VVMRU - (2 * sizeof(u_short)))
E 50
#endif

/*
 *   debugging and tracing stuff
 */
E 32
I 27
D 28
extern struct ifnet loif;	/* loopback */

E 28
E 27
I 6
D 14
int vv_dotrailer = 1,		/* so can do trailers selectively */
    vv_trace = 0;
E 14
I 14
D 23
int vv_dotrailer = 0,		/* 1 => do trailer protocol */
    vv_tracehdr = 0,		/* 1 => trace headers (slowly!!) */
E 23
I 23
D 30
int vv_tracehdr = 0,		/* 1 => trace headers (slowly!!) */
E 23
D 27
    vv_tracetimeout = 1;	/* 1 => trace input error-rate limiting */
    vv_logreaderrors = 0;	/* 1 => log all read errors */
E 27
I 27
    vv_logreaderrors = 1;	/* 1 => log all read errors */
E 30
I 30
int	vv_tracehdr = 0;	/* 1 => trace headers (slowly!!) */
I 32
D 33
#ifndef proteon
E 32
int	vv_logreaderrors = 1;	/* 1 => log all read errors */
I 32
#else proteon
int	vv_logerrors = 0;	/* 1 => log all i/o errors */
#endif proteon
E 33
E 32
E 30
E 27
E 14

I 14
D 32
#define vvtracehdr	if (vv_tracehdr) vvprt_hdr
E 32
I 32
#define vvtracehdr  if (vv_tracehdr) vvprt_hdr
D 33
#define vvprintf    if (vv_logerrors && vs->vs_if.if_flags & IFF_DEBUG) printf
E 33
I 33
#define vvprintf    if (vs->vs_if.if_flags & IFF_DEBUG) printf
E 33
E 32
D 27
#define	vvtrprintf	if (vv_tracetimeout) printf
E 27

I 32
/*
 * externals, types, etc.
 */
E 32
D 27
int vv_ticking = 0;		/* error flywheel is running */

D 15
#define VV_FLYWHEEL		3	/* interval in HZ - 50 msec.
					   N.B. all times below are 
					   in units of flywheel ticks */
E 15
I 15
/*
 * Interval in HZ - 50 msec.
 * N.B. all times below are in units of flywheel ticks
 */
#define VV_FLYWHEEL		3
E 15
#define	VV_ERRORTHRESHOLD	100	/* errors/flywheel-interval */
#define	VV_MODE1ATTEMPTS	10	/* number mode 1 retries */
#define	VV_MODE1DELAY		2	/* period interface is PAUSEd - 100ms */
#define VV_MODE2DELAY		4	/* base interval host relay is off - 200ms */
#define	VV_MAXDELAY		6400	/* max interval host relay is off - 2 minutes */

E 27
E 14
E 6
D 29
int	vvprobe(), vvattach(), vvrint(), vvxint();
E 29
I 29
D 30
int	vvprobe(), vvattach(), vvrint(), vvxint(), vvwatchdog();
E 30
I 30
int	vvprobe(), vvattach(), vvreset(), vvinit();
int	vvidentify(), vvstart(), vvxint(), vvwatchdog();
D 44
int	vvrint(), vvoutput(), vvioctl(), vvsetaddr();
E 44
I 44
int	vvrint(), vvoutput(), vvioctl();
E 44
E 30
E 29
struct	uba_device *vvinfo[NVV];
u_short vvstd[] = { 0 };
struct	uba_driver vvdriver =
	{ vvprobe, 0, vvattach, 0, vvstd, "vv", vvinfo };
#define	VVUNIT(x)	minor(x)
D 23
int	vvinit(),vvoutput(),vvreset();
E 23
I 23
D 27
int	vvinit(),vvioctl(),vvoutput(),vvreset();
E 27
I 27
D 30
int	vvinit(),vvioctl(),vvoutput(),vvreset(),vvsetaddr();
E 30
E 27
E 23

I 32
#define LOOPBACK		/* use loopback for packets meant for us */
#ifdef	LOOPBACK
extern struct ifnet loif;
#endif

E 32
/*
 * Software status of each interface.
 *
 * Each interface is referenced by a network interface structure,
 * vs_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct	vv_softc {
	struct	ifnet vs_if;		/* network-visible interface */
	struct	ifuba vs_ifuba;		/* UNIBUS resources */
I 33
D 42
	int	vs_host;
E 42
I 42
	u_short	vs_host;		/* this interface address */
E 42
E 33
D 14
	short	vs_oactive;		/* is output active? */
E 14
I 14
	short	vs_oactive;		/* is output active */
I 45
	short	vs_is80;		/* is 80 megabit version */
E 45
D 27
	short	vs_iactive;		/* is input active */
E 27
E 14
	short	vs_olen;		/* length of last output */
D 29
	u_short	vs_lastx;		/* last destination address */
E 29
I 29
	u_short	vs_lastx;		/* address of last packet sent */
	u_short	vs_lastr;		/* address of last packet received */
E 29
D 14
	short	vs_tries;		/* current retry count */
E 14
I 14
	short	vs_tries;		/* transmit current retry count */
E 14
	short	vs_init;		/* number of ring inits */
D 14
	short	vs_flush;		/* number of flushed packets */
E 14
D 32
	short	vs_nottaken;		/* number of packets refused */
E 32
I 32
	short	vs_refused;		/* number of packets refused */
E 32
I 29
	short	vs_timeouts;		/* number of transmit timeouts */
I 32
	short	vs_otimeout;		/* number of output timeouts */
	short	vs_ibadf;		/* number of input bad formats */
	short	vs_parity;		/* number of parity errors on 10 meg, */
					/* link data errors on 80 meg */
I 51
	short	vs_ipl;			/* interrupt priority on Q-bus */
E 51
E 32
E 29
I 14
D 27
	/* input error rate limiting state */
	short	vs_major;		/* recovery major state */
	short	vs_minor;		/* recovery minor state */
	short	vs_retry;		/* recovery retry count */
	short	vs_delayclock;		/* recovery delay clock */
	short	vs_delayrange;		/* increasing delay interval */
	short	vs_dropped;		/* number of packes tossed in last dt */
E 27
E 14
} vv_softc[NVV];

I 43
#define	NOHOST	0xffff			/* illegal host number */

E 43
I 32
/*
 * probe the interface to see that the registers exist, and then
 * cause an interrupt to find its vector
 */
E 32
I 14
D 27
/*
D 15
 * states of vs_iactive
E 15
I 15
 * States of vs_iactive.
E 15
 */
D 15

E 15
#define	ACTIVE	1		/* interface should post new receives */
#define	PAUSE	0		/* interface should NOT post new receives */
#define	OPEN	-1		/* PAUSE and open host relay */

/*
D 15
 * recovery major states
E 15
I 15
 * Recovery major states.
E 15
 */
D 15

E 15
#define	MODE0	0		/* everything is wonderful */
#define	MODE1	1		/* hopefully whatever will go away */
D 15
#define	MODE2	2		/* drastic measures - open host relay 
				   for increasing intervals */
E 15
I 15
#define	MODE2	2		/* drastic measures - open host relay for increasing intervals */
E 15

E 27
E 14
D 51
vvprobe(reg)
E 51
I 51
vvprobe(reg, ui)
E 51
	caddr_t reg;
I 51
	struct uba_device *ui;
E 51
{
	register int br, cvec;
D 30
	register struct vvreg *addr = (struct vvreg *)reg;
E 30
I 30
	register struct vvreg *addr;
E 30

#ifdef lint
D 22
	br = 0; cvec = br; br = cvec;
E 22
I 22
D 27
	br = 0; cvec = br; br = cvec; vvrint(0);
E 27
I 27
	br = 0; cvec = br; br = cvec;
E 27
E 22
#endif
I 30
	addr = (struct vvreg *)reg;
I 32

E 32
E 30
	/* reset interface, enable, and wait till dust settles */
I 51
#ifdef QBA
	(void) spl6();
#endif
E 51
	addr->vvicsr = VV_RST;
	addr->vvocsr = VV_RST;
D 19
	DELAY(100000);
E 19
I 19
D 27
	DELAY(10000);
E 27
I 27
	DELAY(100000);
I 32

E 32
E 27
E 19
	/* generate interrupt by doing 1 word DMA from 0 in uba space!! */
D 32
	addr->vvocsr = VV_IEN;		/* enable interrupt */
E 32
	addr->vvoba = 0;		/* low 16 bits */
	addr->vvoea = 0;		/* extended bits */
	addr->vvowc = -1;		/* for 1 word */
D 32
	addr->vvocsr |= VV_DEN;		/* start the DMA */
E 32
I 32
	addr->vvocsr = VV_IEN | VV_DEN;	/* start the DMA, with interrupt */
E 32
	DELAY(100000);
I 51
#ifdef QBA
	vv_softc[ui->ui_unit].vs_ipl = br = qbgetpri();
#endif
E 51
D 32
	addr->vvocsr = 0;
E 32
I 32
	addr->vvocsr = VV_RST;		/* clear out the CSR */
E 32
	if (cvec && cvec != 0x200)
D 27
		cvec -= 4;		/* backup so vector => recieve */
E 27
I 27
		cvec -= 4;		/* backup so vector => receive */
E 27
D 51
	return(1);
E 51
I 51
	return (sizeof(struct vvreg));
E 51
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
vvattach(ui)
	struct uba_device *ui;
{
D 27
	register struct vv_softc *vs = &vv_softc[ui->ui_unit];
E 27
I 27
	register struct vv_softc *vs;
E 27
D 23
	register struct sockaddr_in *sin;
E 23
D 5
COUNT(VVATTACH);
E 5

I 27
	vs = &vv_softc[ui->ui_unit];
E 27
	vs->vs_if.if_unit = ui->ui_unit;
	vs->vs_if.if_name = "vv";
	vs->vs_if.if_mtu = VVMTU;
I 33
	vs->vs_if.if_flags = IFF_BROADCAST;
E 33
D 23
	vs->vs_if.if_net = ui->ui_flags;
	vs->vs_if.if_host[0] = 0;	/* this will be reset in vvinit() */
D 15

E 15
	sin = (struct sockaddr_in *)&vs->vs_if.if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(vs->vs_if.if_net, vs->vs_if.if_host[0]);
D 15

E 15
	sin = (struct sockaddr_in *)&vs->vs_if.if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(vs->vs_if.if_net, VV_BROADCAST);
	vs->vs_if.if_flags = IFF_BROADCAST;
E 23
D 15

E 15
	vs->vs_if.if_init = vvinit;
I 23
	vs->vs_if.if_ioctl = vvioctl;
E 23
	vs->vs_if.if_output = vvoutput;
D 10
	vs->vs_if.if_ubareset = vvreset;
E 10
I 10
D 14
	vs->vs_if.if_reset = vvreset;
E 14
I 14
D 15
	vs->vs_if.if_ubareset = vvreset;
E 15
I 15
	vs->vs_if.if_reset = vvreset;
I 29
	vs->vs_if.if_timer = 0;
	vs->vs_if.if_watchdog = vvwatchdog;
E 29
E 15
E 14
E 10
D 6
	vs->vs_ifuba.ifu_flags = UBA_NEEDBDP | UBA_NEED16;
E 6
I 6
D 40
	vs->vs_ifuba.ifu_flags = UBA_CANTWAIT | UBA_NEEDBDP | UBA_NEED16;
E 40
I 40
	vs->vs_ifuba.ifu_flags = UBA_CANTWAIT | UBA_NEEDBDP;
I 45

	/* use flag to determine if this is proNET-80 */
	vs->vs_is80 = (short)(ui->ui_flags & 01);

E 45
E 40
I 20
#if defined(VAX750)
	/* don't chew up 750 bdp's */
	if (cpu == VAX_750 && ui->ui_unit > 0)
		vs->vs_ifuba.ifu_flags &= ~UBA_NEEDBDP;
#endif
E 20
E 6
	if_attach(&vs->vs_if);
D 3
#if NIMP == 0
	if (ui->ui_flags & ~0xff)
		vvlhinit((ui->ui_flags &~ 0xff) | 0x0a);
#endif
E 3
}

/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
vvreset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;
D 5
COUNT(VVRESET);
E 5

	if (unit >= NVV || (ui = vvinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
	printf(" vv%d", unit);
	vvinit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
vvinit(unit)
	int unit;
{
D 27
	register struct vv_softc *vs = &vv_softc[unit];
	register struct uba_device *ui = vvinfo[unit];
E 27
I 27
	register struct vv_softc *vs;
	register struct uba_device *ui;
E 27
	register struct vvreg *addr;
D 30
	struct sockaddr_in *sin;
D 6
	struct mbuf *m;
	struct vv_header *v;
	int ubainfo, retrying, attempts, waitcount, s;
E 6
I 6
	int ubainfo, s;
E 30
I 30
D 33
	register struct sockaddr_in *sin;
E 33
D 50
	register int ubainfo, s;
E 50
I 50
	register int ubaaddr, s;
E 50
E 30
I 14
D 27
	int vvtimeout();
E 27
E 14
E 6

I 23
D 27
	if (vs->vs_if.if_net == 0)
E 27
I 27
	vs = &vv_softc[unit];
	ui = vvinfo[unit];
D 33
	sin = (struct sockaddr_in *)&vs->vs_if.if_addr;
E 33
I 32

E 32
D 33
	/*
	 * If the network number is still zero, we've been
	 * called too soon.
	 */
	if (in_netof(sin->sin_addr) == 0)
E 33
I 33
	if (vs->vs_if.if_addrlist == (struct ifaddr *)0)
E 33
E 27
		return;
I 32

E 32
E 23
I 6
	addr = (struct vvreg *)ui->ui_addr;
E 6
D 51
	if (if_ubainit(&vs->vs_ifuba, ui->ui_ubanum,
D 27
	    sizeof (struct vv_header), (int)btoc(VVMTU)) == 0) { 
E 27
I 27
D 50
	    sizeof (struct vv_header), (int)btoc(VVMTU)) == 0) {
E 50
I 50
	    sizeof (struct vv_header), (int)btoc(VVMRU)) == 0) {
E 51
I 51
	if ((vs->vs_if.if_flags & IFF_RUNNING) == 0 &&
	    if_ubainit(&vs->vs_ifuba, ui->ui_ubanum,
	      sizeof (struct vv_header), (int)btoc(VVMRU)) == 0) {
E 51
E 50
E 27
I 6
D 14
nogo:
E 14
E 6
D 29
		printf("vv%d: can't initialize\n", unit);
E 29
I 29
		printf("vv%d: can't initialize, if_ubainit() failed\n", unit);
E 29
I 4
D 6
		vs->vs_ifuba.if_flags &= ~IFF_UP;
E 6
I 6
		vs->vs_if.if_flags &= ~IFF_UP;
E 6
E 4
		return;
	}
I 51
	vs->vs_if.if_flags |= IFF_RUNNING;
E 51
I 32

E 32
D 6
	addr = (struct vvreg *)ui->ui_addr;
E 6
D 15

I 14
	if (vv_ticking++ == 0) timeout(vvtimeout, (caddr_t) 0, VV_FLYWHEEL);

E 15
I 15
D 27
	if (vv_ticking++ == 0)
		timeout(vvtimeout, (caddr_t) 0, VV_FLYWHEEL);
E 27
E 15
E 14
D 6
#ifdef AUTOIDENTIFY
E 6
	/*
I 6
D 15
	 * discover our host address and post it
E 15
I 15
D 27
	 * Discover our host address and post it
E 27
I 27
	 * Now that the uba is set up, figure out our address and
	 * update complete our host address.
E 27
E 15
	 */
D 15

E 15
D 29
	vs->vs_if.if_host[0] = vvidentify(unit);
E 29
I 29
D 32
	if ((vs->vs_if.if_host[0] = vvidentify(unit)) == 0) {
E 32
I 32
D 33
	if ((vs->vs_if.if_host[0] = vvidentify(unit)) == -1) {
E 33
I 33
D 43
	if ((vs->vs_host = vvidentify(unit)) == -1) {
E 43
I 43
	if ((vs->vs_host = vvidentify(unit)) == NOHOST) {
E 43
E 33
E 32
		vs->vs_if.if_flags &= ~IFF_UP;
		return;
	}
E 29
D 14
	if (vs->vs_if.if_host[0] == 0)
		goto nogo;
E 14
D 33
	printf("vv%d: host %d\n", unit, vs->vs_if.if_host[0]);
D 27
	sin = (struct sockaddr_in *)&vs->vs_if.if_addr;
	sin->sin_family = AF_INET;
E 27
D 15
	sin->sin_addr =
	    if_makeaddr(vs->vs_if.if_net, vs->vs_if.if_host[0]);
E 15
I 15
	sin->sin_addr = if_makeaddr(vs->vs_if.if_net, vs->vs_if.if_host[0]);
E 33
I 33
D 45
	printf("vv%d: host %d\n", unit, vs->vs_host);
E 45
I 45
	printf("vv%d: host %u\n", unit, vs->vs_host);
E 45
E 33
I 32

E 32
I 23
D 27
	sin = (struct sockaddr_in *)&vs->vs_if.if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(vs->vs_if.if_net, VV_BROADCAST);
E 23
E 15

E 27
	/*
D 32
	 * Reset the interface, and join the ring
E 32
I 32
	 * Reset the interface, and stay in the ring
E 32
	 */
D 32
	addr->vvocsr = VV_RST | VV_CPB;		/* clear packet buffer */
	addr->vvicsr = VV_RST | VV_CONF;	/* close logical relay */
E 32
I 32
	addr->vvocsr = VV_RST;			/* take over output */
	addr->vvocsr = VV_CPB;			/* clear packet buffer */
	addr->vvicsr = VV_RST | VV_HEN;		/* take over input, */
						/* keep relay closed */
E 32
D 19
	sleep((caddr_t)&lbolt, PZERO);		/* let contacts settle */
E 19
I 19
	DELAY(500000);				/* let contacts settle */
E 19
D 32
	vs->vs_init = 0;
D 14
	vs->vs_flush = 0;
E 14
I 14
D 27
	vs->vs_dropped = 0;
E 27
E 14
	vs->vs_nottaken = 0;
E 32
I 32

	vs->vs_init = 0;			/* clear counters, etc. */
	vs->vs_refused = 0;
E 32
I 29
	vs->vs_timeouts = 0;
I 32
	vs->vs_otimeout = 0;
	vs->vs_ibadf = 0;
	vs->vs_parity = 0;
E 32
	vs->vs_lastx = 256;			/* an invalid address */
	vs->vs_lastr = 256;			/* an invalid address */
I 32

E 32
E 29
D 27

E 27
	/*
	 * Hang a receive and start any
	 * pending writes by faking a transmit complete.
	 */
	s = splimp();
D 50
	ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
D 23
	addr->vviba = (u_short) ubainfo;
	addr->vviea = (u_short) (ubainfo >> 16);
E 23
I 23
	addr->vviba = (u_short)ubainfo;
	addr->vviea = (u_short)(ubainfo >> 16);
E 50
I 50
	ubaaddr = UBAI_ADDR(vs->vs_ifuba.ifu_r.ifrw_info);
	addr->vviba = (u_short)ubaaddr;
	addr->vviea = (u_short)(ubaaddr >> 16);
E 50
E 23
D 32
	addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
	addr->vvicsr = VV_IEN | VV_CONF | VV_DEN | VV_ENB;
E 32
I 32
	addr->vviwc = -(VVBUFSIZE) >> 1;
	addr->vvicsr = VV_IEN | VV_HEN | VV_DEN | VV_ENB;
E 32
I 14
D 27
	vs->vs_iactive = ACTIVE;
E 27
E 14
	vs->vs_oactive = 1;
D 23
	vs->vs_if.if_flags |= IFF_UP;
E 23
I 23
D 33
	vs->vs_if.if_flags |= IFF_UP | IFF_RUNNING;
E 33
I 33
D 51
	vs->vs_if.if_flags |= IFF_RUNNING;
E 51
I 51
	vs->vs_if.if_flags |= IFF_UP;
E 51
E 33
E 23
	vvxint(unit);
	splx(s);
D 33
	if_rtinit(&vs->vs_if, RTF_UP);
E 33
}

/*
D 27
 * vvidentify() - return our host address
E 27
I 27
D 32
 * Return our host address.
E 32
I 32
 * Do a moderately thorough self-test in all three modes. Mostly
 * to keeps defective nodes off the ring, rather than to be especially
 * thorough. The key issue is to detect any cable breaks before joining
 * the ring. Return our node address on success, return -1 on failure.
 *
E 32
E 27
 */
I 32

/* the three self-test modes */
static u_short vv_modes[] = {
	VV_STE|VV_LPB,			/* digital loopback */
	VV_STE,				/* analog loopback */
	VV_HEN				/* network mode */
};

E 32
D 14
vvidentify(unit)
{
E 14
I 14
D 15

vvidentify(unit) {

E 15
I 15
vvidentify(unit)
I 23
	int unit;
E 23
{
E 15
E 14
D 27
	register struct vv_softc *vs = &vv_softc[unit];
	register struct uba_device *ui = vvinfo[unit];
E 27
I 27
	register struct vv_softc *vs;
	register struct uba_device *ui;
E 27
	register struct vvreg *addr;
D 30
	struct mbuf *m;
	struct vv_header *v;
D 22
	int ubainfo, retrying, attempts, waitcount, s;
E 22
I 22
	int ubainfo, attempts, waitcount;
E 30
I 30
	register struct mbuf *m;
	register struct vv_header *v;
D 32
	register int ubainfo, attempts, waitcount;
E 32
I 32
D 50
	register int ubainfo;
E 50
I 50
	register int ubaaddr;
E 50
	register int i, successes, failures, waitcount;
D 42
	u_short shost = -1;
E 42
I 42
D 43
	u_short shost = 0xffff;
E 43
I 43
	u_short shost = NOHOST;
E 43
E 42
E 32
E 30
E 22

D 32
	/*
E 6
	 * Build a multicast message to identify our address
	 */
E 32
I 27
	vs = &vv_softc[unit];
	ui = vvinfo[unit];
E 27
I 14
D 15

E 15
E 14
I 6
	addr = (struct vvreg *)ui->ui_addr;
I 14
D 15

E 15
E 14
E 6
D 32
	attempts = 0;		/* total attempts, including bad msg type */
E 32
I 32

	/*
	 * Build a multicast message to identify our address
	 * We need do this only once, since nobody else is about to use
	 * the intermediate transmit buffer (ifu_w.ifrw_addr) that
	 * if_ubainit() aquired for us.
	 */
E 32
D 6
top:
E 6
D 22
	retrying = 0;		/* first time through */
E 22
D 11
	m = m_get(M_DONTWAIT);
E 11
I 11
D 14
	m = m_get(M_DONTWAIT, MT_HEADER);
E 11
D 6
	if (m == 0)
		panic("vvinit: can't get mbuf");
	m->m_next = 0;
E 6
I 6
	if (m == 0) {
		printf("vvinit: can't get mbuf");
		return (0);
	}
E 14
I 14
D 15
	m = m_get(M_DONTWAIT);
E 15
I 15
	m = m_get(M_DONTWAIT, MT_HEADER);
E 15
D 22
	if (m == 0)
E 22
I 22
D 29
	if (m == NULL)
E 29
I 29
	if (m == NULL) {
		printf("vv%d: can't initialize, m_get() failed\n", unit);
E 29
E 22
D 23
		panic("vvinit: can't get mbuf");
E 23
I 23
		return (0);
I 29
	}
E 29
E 23
	m->m_next = 0;
E 14
E 6
	m->m_off = MMINOFF;
	m->m_len = sizeof(struct vv_header);
D 15

E 15
	v = mtod(m, struct vv_header *);
D 14
	v->vh_dhost = 0;		/* multicast destination address */
E 14
I 14
	v->vh_dhost = VV_BROADCAST;	/* multicast destination address */
E 14
	v->vh_shost = 0;		/* will be overwritten with ours */
	v->vh_version = RING_VERSION;
D 32
	v->vh_type = RING_WHOAMI;
E 32
I 32
	v->vh_type = RING_DIAGNOSTICS;
E 32
	v->vh_info = 0;
I 14
D 15

E 15
D 32
	/* map xmit message into uba */
D 15

E 15
E 14
I 6
	vs->vs_olen =  if_wubaput(&vs->vs_ifuba, m);
	if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(vs->vs_ifuba.ifu_uba, vs->vs_ifuba.ifu_w.ifrw_bdp);
E 32
I 32
	/* map xmit message into uba, copying to intermediate buffer */
	vs->vs_olen = if_wubaput(&vs->vs_ifuba, m);

E 32
E 6
D 15

E 15
	/*
D 32
	 * Reset interface, establish Digital Loopback Mode, and
	 * send the multicast (to myself) with Input Copy enabled.
E 32
I 32
	 * For each of the modes (digital, analog, network), go through
	 * a self-test that requires me to send VVIDENTSUCC good packets
	 * in VVIDENTRETRY attempts. Use broadcast destination to find out
	 * who I am, then use this as my address to check my address match
	 * logic. Only data checked is the vh_type field.
E 32
	 */
D 32
retry:
	ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
	addr->vvicsr = VV_RST;
	addr->vviba = (u_short) ubainfo;
	addr->vviea = (u_short) (ubainfo >> 16);
	addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
	addr->vvicsr = VV_STE | VV_DEN | VV_ENB | VV_LPB;
E 32
D 6
	/* map xmit message into uba if not already there */
	if (!retrying)
		vs->vs_olen =  if_wubaput(&vs->vs_ifuba, m);
	if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(vs->vs_ifuba.ifu_uba, vs->vs_ifuba.ifu_w.ifrw_bdp);
E 6
I 6

D 32
	/* let flag timers fire so ring will initialize */
I 14
D 15

E 15
E 14
D 16
	sleep((caddr_t) &lbolt, PZERO);
	sleep((caddr_t) &lbolt, PZERO);
E 16
I 16
D 27
	DELAY(2000000);
E 27
I 27
	DELAY(2000000);			/* about 2 SECONDS on a 780!! */
E 32
I 32
	for (i = 0; i < 3; i++) {
		successes = 0;	/* clear successes for this mode */
		failures = 0;	/* and clear failures, too */
E 32
E 27
E 16

E 6
D 32
	addr->vvocsr = VV_RST | VV_CPB;	/* clear packet buffer */
	ubainfo = vs->vs_ifuba.ifu_w.ifrw_info;
	addr->vvoba = (u_short) ubainfo;
	addr->vvoea = (u_short) (ubainfo >> 16);
	addr->vvowc = -((vs->vs_olen + 1) >> 1);
	addr->vvocsr = VV_CPB | VV_DEN | VV_INR | VV_ENB;
D 15

E 15
	/*
	 * Wait for receive side to finish.
D 6
	 * Extract source address (which will our own),
E 6
I 6
D 14
	 * Extract source address (which will be our own),
E 14
I 14
D 29
	 * Extract source address (which will our own),
E 29
I 29
	 * Extract source address (which will be our own),
E 29
E 14
E 6
	 * and post to interface structure.
	 */
D 27
	DELAY(1000);
E 27
I 27
	DELAY(10000);
E 27
D 6
	for (waitcount = 0; ((addr->vvicsr) & VV_RDY) == 0; waitcount++) {
E 6
I 6
D 14
	for (waitcount = 0; (addr->vvicsr & VV_RDY) == 0; waitcount++)
E 14
I 14
	for (waitcount = 0; (addr->vvicsr & VV_RDY) == 0; waitcount++) {
E 14
E 6
D 13
		if (waitcount < 10)
E 13
I 13
		if (waitcount < 10) {
E 13
			DELAY(1000);
E 32
I 32
		/* take over device, and leave ring */
		addr->vvicsr = VV_RST;
		addr->vvocsr = VV_RST;
		addr->vvicsr = vv_modes[i];	/* test mode */

		/*
		 * let the flag and token timers pop so that the init ring bit
		 * will be allowed to work, by waiting about 1 second
		 */
		DELAY(1000000L);

		/*
		 * retry loop
 		 */
		while ((successes < VVIDENTSUCC) && (failures < VVIDENTRETRY))
		{
			/* start a receive */
D 50
			ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
E 50
I 50
			ubaaddr = UBAI_ADDR(vs->vs_ifuba.ifu_r.ifrw_info);
E 50
			addr->vvicsr = VV_RST | vv_modes[i]; /* abort last */
D 50
			addr->vviba = (u_short) ubainfo;
			addr->vviea = (u_short) (ubainfo >> 16);
E 50
I 50
			addr->vviba = (u_short) ubaaddr;
			addr->vviea = (u_short) (ubaaddr >> 16);
E 50
			addr->vviwc = -(VVBUFSIZE) >> 1;
			addr->vvicsr = vv_modes[i] | VV_DEN | VV_ENB;

			/* purge stale data from BDP */
			if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
				UBAPURGE(vs->vs_ifuba.ifu_uba,
				    vs->vs_ifuba.ifu_w.ifrw_bdp);

			/* do a transmit */
D 50
			ubainfo = vs->vs_ifuba.ifu_w.ifrw_info;
E 50
I 50
			ubaaddr = UBAI_ADDR(vs->vs_ifuba.ifu_w.ifrw_info);
E 50
			addr->vvocsr = VV_RST;	/* abort last try */
D 50
			addr->vvoba = (u_short) ubainfo;
			addr->vvoea = (u_short) (ubainfo >> 16);
E 50
I 50
			addr->vvoba = (u_short) ubaaddr;
			addr->vvoea = (u_short) (ubaaddr >> 16);
E 50
			addr->vvowc = -((vs->vs_olen + 1) >> 1);
			addr->vvocsr = VV_CPB | VV_DEN | VV_INR | VV_ENB;

			/* poll receive side for completion */
			DELAY(10000);		/* give it a chance */
			for (waitcount = 0; waitcount < 10; waitcount++) {
				if (addr->vvicsr & VV_RDY)
					goto gotit;
				DELAY(1000);
			}
			failures++;		/* no luck */
E 32
I 15
			continue;
I 32

gotit:			/* we got something--is it any good? */
			if ((addr->vvicsr & (VVRERR|VV_LDE)) ||
D 33
			    (ADDR->vvocsr & (VVXERR|VV_RFS))) {
E 33
I 33
			    (addr->vvocsr & (VVXERR|VV_RFS))) {
E 33
				failures++;
				continue;
			}

			/* Purge BDP before looking at received packet */
			if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
				UBAPURGE(vs->vs_ifuba.ifu_uba,
				    vs->vs_ifuba.ifu_r.ifrw_bdp);
D 35
			m = if_rubaget(&vs->vs_ifuba,
			    sizeof(struct vv_header), 0);
E 35
I 35
			m = if_rubaget(&vs->vs_ifuba, sizeof(struct vv_header),
D 44
				0, 0);
E 44
I 44
				0, &vs->vs_if);
E 44
E 35
			if (m != NULL)
				m_freem(m);
			
			v = (struct vv_header *)(vs->vs_ifuba.ifu_r.ifrw_addr);

			/* check message type, catch our node address */
			if ((v->vh_type & 0xff) == RING_DIAGNOSTICS) {
D 42
				if (shost == -1) {
E 42
I 42
D 43
				if (shost == 0xffff) {
E 43
I 43
				if (shost == NOHOST) {
E 43
E 42
					shost = v->vh_shost & 0xff;
					/* send to ourself now */
					((struct vv_header *)
					    (vs->vs_ifuba.ifu_r.ifrw_addr))
					    ->vh_dhost = shost;
				}
				successes++;
D 45
				v->vh_type = 0;  /* clear to check again */
E 45
I 45
			} else {
				failures++;
E 45
			}
I 45
			v->vh_type = 0;  /* clear to check again */
E 45
E 32
E 15
D 13
		else {
E 13
I 13
D 14
		} else {
E 13
D 6
			if (attempts++ < 10)s
E 6
I 6
			if (attempts++ < 10)
E 14
I 14
		}
D 15
		else {
			if (attempts++ < 10){
E 14
E 6
				goto retry;
I 14
			}
E 14
			else {
				printf("vv%d: can't initialize\n", unit);
				printf("vvinit loopwait: icsr = %b\n",
					0xffff&(addr->vvicsr),VV_IBITS);
I 4
D 6
				vs->vs_ifuba.if_flags &= ~IFF_UP;
E 4
				return;
E 6
I 6
				vs->vs_if.if_flags &= ~IFF_UP;
D 14
				return (0);
E 14
I 14
				return;
E 14
E 6
			}
E 15
I 15
D 29
		if (attempts++ >= 10) {
			printf("vv%d: can't initialize\n", unit);
			printf("vvinit loopwait: icsr = %b\n",
				0xffff&(addr->vvicsr), VV_IBITS);
			vs->vs_if.if_flags &= ~IFF_UP;
D 22
			return;
E 22
I 22
			return (0);
E 22
E 15
		}
I 15
		goto retry;
E 29
I 29
D 32
		if (attempts++ < VVIDENTRETRY)
			goto retry;
E 32
I 32

		if (failures >= VVIDENTRETRY)
		{
			printf("vv%d: failed self-test after %d tries \
in %s mode\n",
			    unit, VVIDENTRETRY, i == 0 ? "digital loopback" :
			    (i == 1 ? "analog loopback" : "network"));
			printf("vv%d: icsr = %b, ocsr = %b\n",
			    unit, 0xffff & addr->vvicsr, VV_IBITS,
			    0xffff & addr->vvocsr, VV_OBITS);
			addr->vvicsr = VV_RST;	/* kill the sick board */
			addr->vvocsr = VV_RST;
D 42
			shost = -1;
E 42
I 42
D 43
			shost = 0xffff;
E 43
I 43
			shost = NOHOST;
E 43
E 42
			goto done;
		}
E 32
E 29
E 15
I 14
	}
D 15

E 15
E 14
D 6
	}

E 6
D 29
	if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(vs->vs_ifuba.ifu_uba, vs->vs_ifuba.ifu_w.ifrw_bdp);
	if (vs->vs_ifuba.ifu_xtofree)
E 29
I 29
D 32
	/* deallocate mbuf used for send packet */
E 32
I 32

done:
	/* deallocate mbuf used for send packet (won't be one, anyways) */
E 32
	if (vs->vs_ifuba.ifu_xtofree) {
E 29
		m_freem(vs->vs_ifuba.ifu_xtofree);
I 29
		vs->vs_ifuba.ifu_xtofree = 0;
	}
D 32
	if (attempts >= VVIDENTRETRY) {
		printf("vv%d: can't initialize after %d tries, icsr = %b\n",
		    unit, VVIDENTRETRY, 0xffff&(addr->vvicsr), VV_IBITS);
		return (0);
	}
	/* Purge BDP before looking at packet we just received */
E 29
	if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(vs->vs_ifuba.ifu_uba, vs->vs_ifuba.ifu_r.ifrw_bdp);
	m = if_rubaget(&vs->vs_ifuba, sizeof(struct vv_header), 0);
D 15
	if (m)
E 15
I 15
	if (m != NULL)
E 15
		m_freem(m);
	/*
D 15
	 * check message type before we believe the source host address
E 15
I 15
	 * Check message type before we believe the source host address
E 15
	 */
	v = (struct vv_header *)(vs->vs_ifuba.ifu_r.ifrw_addr);
D 6
	if (v->vh_type == RING_WHOAMI)
		vs->vs_if.if_host[0] = v->vh_shost;
	else
		goto top;
#else
	vs->vs_if.if_host[0] = 24;
#endif

	printf("vv%d: host %d\n", unit, vs->vs_if.if_host[0]);
	sin = (struct sockaddr_in *)&vs->vs_if.if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr =
	    if_makeaddr(vs->vs_if.if_net, vs->vs_if.if_host[0]);

	/*
	 * Reset the interface, and join the ring
	 */
	addr->vvocsr = VV_RST | VV_CPB;		/* clear packet buffer */
	addr->vvicsr = VV_RST | VV_CONF;	/* close logical relay */
	sleep((caddr_t)&lbolt, PZERO);		/* let contacts settle */
	vs->vs_init = 0;
	vs->vs_flush = 0;
	vs->vs_nottaken = 0;

	/*
	 * Hang a receive and start any
	 * pending writes by faking a transmit complete.
	 */
	s = splimp();
	ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
	addr->vviba = (u_short) ubainfo;
	addr->vviea = (u_short) (ubainfo >> 16);
	addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
	addr->vvicsr = VV_IEN | VV_CONF | VV_DEN | VV_ENB;
	vs->vs_oactive = 1;
I 4
	vs->vs_ifuba.if_flags |= IFF_UP;
E 4
	vvxint(unit);
	splx(s);
D 2
	if_rtinit(&vs->vs_if, RTF_DIRECT|RTF_UP);
E 2
I 2
	if_rtinit(&vs->vs_if, RTF_UP);
E 6
I 6
D 14
	if (v->vh_type != RING_WHOAMI)
E 14
I 14
D 15
	if (v->vh_type == RING_WHOAMI)
		return(v->vh_shost);
	else
E 15
I 15
	if (v->vh_type != RING_WHOAMI)
E 15
E 14
		goto retry;
I 15
	return(v->vh_shost);
E 32
I 32

	return(shost);
E 32
E 15
D 14
	return (v->vh_shost);
E 14
E 6
E 2
}

/*
I 14
D 27
 * vvtimeout() - called by timer flywheel to monitor input packet
 * discard rate.  Interfaces getting too many errors are shut
 * down for a while.  If the condition persists, the interface
 * is marked down.
 */
I 22
/*ARGSUSED*/
E 22
D 15

E 15
vvtimeout(junk)
D 15
int junk;
E 15
I 15
	int junk;
E 15
{
	register struct vv_softc *vs;
	register int i;
	register struct vvreg *addr;
	int ubainfo;

	timeout(vvtimeout, (caddr_t) 0, VV_FLYWHEEL);
D 15

	for (i=0; i<NVV; i++) {
E 15
I 15
	for (i = 0; i < NVV; i++) {
E 15
		vs = &vv_softc[i];
		addr = (struct vvreg *)vvinfo[i]->ui_addr;
D 22
		if (vs->vs_if.if_flags & IFF_UP == 0) continue;
E 22
I 22
		if ((vs->vs_if.if_flags & IFF_UP) == 0)
			continue;
E 22
		switch (vs->vs_major) {

		/*
		 * MODE0: generally OK, just check error rate 
		 */
D 15

E 15
		case MODE0:
			if (vs->vs_dropped < VV_ERRORTHRESHOLD) {
				vs->vs_dropped = 0;
				continue;
			}
D 15
			else {
				/* suspend reads for a while */
				vvtrprintf("vv%d going MODE1 in vvtimeout\n",i);
				vs->vs_major = MODE1;
				vs->vs_iactive = PAUSE;	/* no new reads */
				vs->vs_retry = VV_MODE1ATTEMPTS;
				vs->vs_delayclock = VV_MODE1DELAY;
				vs->vs_minor = 0;
				continue;
			}
E 15
I 15
			/* suspend reads for a while */
			vvtrprintf("vv%d going MODE1 in vvtimeout\n",i);
			vs->vs_major = MODE1;
			vs->vs_iactive = PAUSE;	/* no new reads */
			vs->vs_retry = VV_MODE1ATTEMPTS;
			vs->vs_delayclock = VV_MODE1DELAY;
			vs->vs_minor = 0;
			continue;
E 15

		/*
		 * MODE1: excessive error rate observed
		 * Scheme: try simply suspending reads for a
		 * short while a small number of times
		 */
D 15

E 15
		case MODE1:
			if (vs->vs_delayclock > 0) {
				vs->vs_delayclock--;
				continue;
			}
			switch (vs->vs_minor) {
I 15

E 15
			case 0:				/* reenable reads */
				vvtrprintf("vv%d M1m0\n",i);
				vs->vs_dropped = 0;
				vs->vs_iactive = ACTIVE;
				vs->vs_minor = 1;	/* next state */
				ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
				addr->vviba = (u_short) ubainfo;
				addr->vviea = (u_short) (ubainfo >> 16);
D 15
				addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
E 15
I 15
				addr->vviwc =
				  -(sizeof (struct vv_header) + VVMTU) >> 1;
E 15
				addr->vvicsr = VV_RST | VV_CONF;
				addr->vvicsr |= VV_IEN | VV_DEN | VV_ENB;
				continue;
I 15

E 15
			case 1:				/* see if it worked */
				vvtrprintf("vv%d M1m1\n",i);
				if (vs->vs_dropped < VV_ERRORTHRESHOLD) {
					vs->vs_dropped = 0;
					vs->vs_major = MODE0;	/* yeah!! */
					continue;
				}
D 15
				else {
					if (vs->vs_retry -- > 0) {
						vs->vs_dropped = 0;
						vs->vs_iactive = PAUSE;
						vs->vs_delayclock = VV_MODE1DELAY;
						vs->vs_minor = 0; /* recheck */
						continue;
					}
					else {
						vs->vs_major = MODE2;
						vs->vs_minor = 0;
						vs->vs_dropped = 0;
						vs->vs_iactive = OPEN;
						vs->vs_delayrange = VV_MODE2DELAY;
						vs->vs_delayclock = VV_MODE2DELAY;
					}
E 15
I 15
				if (vs->vs_retry -- > 0) {
					vs->vs_dropped = 0;
					vs->vs_iactive = PAUSE;
					vs->vs_delayclock = VV_MODE1DELAY;
					vs->vs_minor = 0; /* recheck */
					continue;
E 15
				}
I 15
				vs->vs_major = MODE2;
				vs->vs_minor = 0;
				vs->vs_dropped = 0;
				vs->vs_iactive = OPEN;
				vs->vs_delayrange = VV_MODE2DELAY;
				vs->vs_delayclock = VV_MODE2DELAY;
				/* fall thru ... */
E 15
			}

		/*
		 * MODE2: simply ignoring traffic didn't relieve condition
		 * Scheme: open host relay for intervals linearly
		 * increasing up to some maximum of a several minutes.
		 * This allows broken networks to return to operation
		 * without rebooting.
		 */
D 15

E 15
		case MODE2:
			if (vs->vs_delayclock > 0) {
				vs->vs_delayclock--;
				continue;
			}
			switch (vs->vs_minor) {
I 15

E 15
			case 0:		/* close relay and reenable reads */
				vvtrprintf("vv%d M2m0\n",i);
				vs->vs_dropped = 0;
				vs->vs_iactive = ACTIVE;
				vs->vs_minor = 1;	/* next state */
				ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
				addr->vviba = (u_short) ubainfo;
				addr->vviea = (u_short) (ubainfo >> 16);
D 15
				addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
E 15
I 15
				addr->vviwc =
				  -(sizeof (struct vv_header) + VVMTU) >> 1;
E 15
				addr->vvicsr = VV_RST | VV_CONF;
				addr->vvicsr |= VV_IEN | VV_DEN | VV_ENB;
				continue;
I 15

E 15
			case 1:				/* see if it worked */
				vvtrprintf("vv%d M2m1\n",i);
				if (vs->vs_dropped < VV_ERRORTHRESHOLD) {
					vs->vs_dropped = 0;
					vs->vs_major = MODE0;	/* yeah!! */
					continue;
				}
D 15
				else {
					vvtrprintf("vv%d M2m1 ++ delay\n",i);
					vs->vs_dropped = 0;
					vs->vs_iactive = OPEN;
					vs->vs_minor = 0;
					if (vs->vs_delayrange < VV_MAXDELAY)
						vs->vs_delayrange += (vs->vs_delayrange/2);
					vs->vs_delayclock = vs->vs_delayrange;
					continue;
				}
E 15
I 15
				vvtrprintf("vv%d M2m1 ++ delay\n",i);
				vs->vs_dropped = 0;
				vs->vs_iactive = OPEN;
				vs->vs_minor = 0;
				if (vs->vs_delayrange < VV_MAXDELAY)
					vs->vs_delayrange +=
					  (vs->vs_delayrange/2);
				vs->vs_delayclock = vs->vs_delayrange;
				continue;
E 15
			}

D 15

E 15
		default:
			printf("vv%d: major state screwed\n", i);
			vs->vs_if.if_flags &= ~IFF_UP;
		}
	}
}

/*
E 27
E 14
 * Start or restart output on interface.
I 14
 * If interface is active, this is a retransmit, so just
 * restuff registers and go.
E 14
 * If interface is not already active, get another datagram
 * to send off of the interface queue, and map it to the interface
 * before starting the output.
 */
vvstart(dev)
	dev_t dev;
{
D 30
        int unit = VVUNIT(dev);
D 27
	struct uba_device *ui = vvinfo[unit];
	register struct vv_softc *vs = &vv_softc[unit];
E 27
I 27
	struct uba_device *ui;
E 30
I 30
	register struct uba_device *ui;
E 30
	register struct vv_softc *vs;
E 27
	register struct vvreg *addr;
D 30
	struct mbuf *m;
D 6
	int ubainfo;
	int dest;
E 6
I 6
D 14
	int ubainfo, dest;
E 14
I 14
D 29
	int ubainfo;
	int dest;
E 29
I 29
	int ubainfo, dest, s;
E 30
I 30
	register struct mbuf *m;
D 50
	register int unit, ubainfo, dest, s;
E 50
I 50
	register int unit, ubaaddr, dest, s;
E 50
E 30
E 29
E 14
E 6
D 5
COUNT(VVSTART);
E 5

I 30
	unit = VVUNIT(dev);
E 30
I 27
	ui = vvinfo[unit];
	vs = &vv_softc[unit];
E 27
	if (vs->vs_oactive)
		goto restart;
I 14
D 15

E 15
E 14
D 6

E 6
	/*
	 * Not already active: dequeue another request
	 * and map it to the UNIBUS.  If no more requests,
	 * just return.
	 */
I 29
	s = splimp();
E 29
	IF_DEQUEUE(&vs->vs_if.if_snd, m);
I 29
	splx(s);
E 29
D 15
	if (m == 0) {
E 15
I 15
	if (m == NULL) {
E 15
		vs->vs_oactive = 0;
		return;
	}
	dest = mtod(m, struct vv_header *)->vh_dhost;
	vs->vs_olen = if_wubaput(&vs->vs_ifuba, m);
	vs->vs_lastx = dest;
D 15

E 15
restart:
I 14
D 15

E 15
E 14
	/*
	 * Have request mapped to UNIBUS for transmission.
D 29
	 * Purge any stale data from this BDP, and start the otput.
E 29
I 29
	 * Purge any stale data from this BDP, and start the output.
	 *
	 * Make sure this packet will fit in the interface.
E 29
	 */
I 27
D 29
	/*
	 * The following test is questionable and isn't done in
	 * the en driver...
	 */
E 29
E 27
I 14
D 15

E 15
D 17
	if (vs->vs_olen > VVMTU) {
E 17
I 17
D 21
	if (vs->vs_olen > VVMTU + sizeof (struct vvheader)) {
E 21
I 21
D 32
	if (vs->vs_olen > VVMTU + sizeof (struct vv_header)) {
E 21
E 17
		printf("vv%d vs_olen: %d > VVMTU\n", unit, vs->vs_olen);
E 32
I 32
	if (vs->vs_olen > VVBUFSIZE) {
		printf("vv%d vs_olen: %d > VVBUFSIZE\n", unit, vs->vs_olen);
E 32
		panic("vvdriver vs_olen botch");
	}
I 32

	vs->vs_if.if_timer = VVTIMEOUT;
	vs->vs_oactive = 1;

	/* ship it */
I 51
#ifdef notdef
E 51
E 32
E 14
	if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(vs->vs_ifuba.ifu_uba, vs->vs_ifuba.ifu_w.ifrw_bdp);
I 51
#endif
E 51
	addr = (struct vvreg *)ui->ui_addr;
D 50
	ubainfo = vs->vs_ifuba.ifu_w.ifrw_info;
	addr->vvoba = (u_short) ubainfo;
	addr->vvoea = (u_short) (ubainfo >> 16);
E 50
I 50
	ubaaddr = UBAI_ADDR(vs->vs_ifuba.ifu_w.ifrw_info);
	addr->vvoba = (u_short) ubaaddr;
	addr->vvoea = (u_short) (ubaaddr >> 16);
E 50
	addr->vvowc = -((vs->vs_olen + 1) >> 1);
I 32
	addr->vvowc = -((vs->vs_olen + 1) >> 1); /* extra byte is garbage */
	if (addr->vvocsr & VV_NOK)
		vs->vs_init++;			/* count ring inits */
E 32
	addr->vvocsr = VV_IEN | VV_CPB | VV_DEN | VV_INR | VV_ENB;
I 29
D 45
	vs->vs_if.if_timer = VVTIMEOUT;
E 29
	vs->vs_oactive = 1;
E 45
}

/*
D 32
 * VVLNI transmit interrupt
E 32
I 32
 * proNET transmit interrupt
E 32
 * Start another output if more data to send.
 */
vvxint(unit)
	int unit;
{
D 27
	register struct uba_device *ui = vvinfo[unit];
	register struct vv_softc *vs = &vv_softc[unit];
E 27
I 27
	register struct uba_device *ui;
	register struct vv_softc *vs;
E 27
	register struct vvreg *addr;
	register int oc;
D 5
COUNT(ENXINT);
E 5

I 51
#ifdef QBA
	splx(vv_softc[unit].vs_ipl);
#endif
E 51
I 27
	ui = vvinfo[unit];
	vs = &vv_softc[unit];
I 29
	vs->vs_if.if_timer = 0;
E 29
E 27
	addr = (struct vvreg *)ui->ui_addr;
	oc = 0xffff & (addr->vvocsr);
	if (vs->vs_oactive == 0) {
D 6
		printf("vv%d: stray interrupt vvocsr = %b\n", unit,
E 6
I 6
D 14
		printf("vv%d: stray interrupt, vvocsr=%b\n", unit,
E 14
I 14
D 32
		printf("vv%d: stray interrupt vvocsr = %b\n", unit,
E 32
I 32
		vvprintf("vv%d: stray interrupt vvocsr = %b\n", unit,
E 32
E 14
E 6
D 27
			oc, VV_OBITS);
E 27
I 27
		    oc, VV_OBITS);
E 27
		return;
	}
D 32
	if (oc &  (VV_OPT | VV_RFS)) {
I 6
		vs->vs_if.if_collisions++;
E 32
I 32

	/*
	 * we retransmit on soft error
	 * TODO: sort retransmits to end of queue if possible!
	 */
	if (oc & (VV_OPT | VV_RFS)) {
E 32
E 6
D 14
		if (++(vs->vs_tries) < VVRETRY) {
E 14
I 14
		if (vs->vs_tries++ < VVRETRY) {
E 14
			if (oc & VV_OPT)
D 32
				vs->vs_init++;
			if (oc & VV_RFS)
				vs->vs_nottaken++;
E 32
I 32
				vs->vs_otimeout++;
			if (oc & VV_RFS) {
				vs->vs_if.if_collisions++;
				vs->vs_refused++;
			}
E 32
D 14
			addr->vvocsr = VV_IEN | VV_ENB | VV_INR;
E 14
I 14
			vvstart(unit);		/* restart this message */
E 14
			return;
		}
D 32
		if (oc & VV_OPT)
D 27
			printf("vv%d: output timeout\n");
E 27
I 27
			printf("vv%d: output timeout\n", unit);
E 32
E 27
	}
	vs->vs_if.if_opackets++;
	vs->vs_oactive = 0;
	vs->vs_tries = 0;
I 32

E 32
	if (oc & VVXERR) {
		vs->vs_if.if_oerrors++;
D 6
		printf("vv%d: error vvocsr = %b\n", unit, 0xffff & oc,
E 6
I 6
D 14
		printf("vv%d: error, vvocsr=%b\n", unit, 0xffff & oc,
E 14
I 14
D 33
		printf("vv%d: error vvocsr = %b\n", unit, 0xffff & oc,
E 33
I 32
		vvprintf("vv%d: error vvocsr = %b\n", unit, 0xffff & oc,
E 32
E 14
E 6
D 27
			VV_OBITS);
E 27
I 27
		    VV_OBITS);
E 27
	}
	if (vs->vs_ifuba.ifu_xtofree) {
		m_freem(vs->vs_ifuba.ifu_xtofree);
		vs->vs_ifuba.ifu_xtofree = 0;
	}
D 29
	if (vs->vs_if.if_snd.ifq_head == 0) {
D 6
		vs->vs_lastx = 0;
E 6
I 6
D 14
		vs->vs_lastx = 256;
E 14
I 14
		vs->vs_lastx = 256;		/* an invalid address */
E 14
E 6
		return;
	}
E 29
	vvstart(unit);
}

/*
I 29
 * Transmit watchdog timer routine.
 * This routine gets called when we lose a transmit interrupt.
 * The best we can do is try to restart output.
 */
vvwatchdog(unit)
	int unit;
{
	register struct vv_softc *vs;
	register int s;

	vs = &vv_softc[unit];
D 32
	if (vs->vs_if.if_flags & IFF_DEBUG)
		printf("vv%d: lost a transmit interrupt.\n", unit);
E 32
I 32
	vvprintf("vv%d: lost a transmit interrupt.\n", unit);
E 32
	vs->vs_timeouts++;
	s = splimp();
	vvstart(unit);
	splx(s);
}

/*
E 29
D 32
 * V2lni interface receiver interrupt.
E 32
I 32
 * proNET interface receiver interrupt.
E 32
 * If input error just drop packet.
D 27
 * Otherwise purge input buffered data path and examine 
E 27
I 27
 * Otherwise purge input buffered data path and examine
E 27
 * packet to determine type.  If can't determine length
D 27
 * from type, then have to drop packet.  Othewise decapsulate
E 27
I 27
 * from type, then have to drop packet.  Otherwise decapsulate
E 27
 * packet based on type and pass to type specific higher-level
 * input routine.
 */
vvrint(unit)
	int unit;
{
D 27
	register struct vv_softc *vs = &vv_softc[unit];
	struct vvreg *addr = (struct vvreg *)vvinfo[unit]->ui_addr;
E 27
I 27
	register struct vv_softc *vs;
D 30
	struct vvreg *addr;
E 30
I 30
	register struct vvreg *addr;
E 30
E 27
	register struct vv_header *vv;
	register struct ifqueue *inq;
D 27
    	struct mbuf *m;
E 27
I 27
D 30
	struct mbuf *m;
E 30
I 30
	register struct mbuf *m;
E 30
E 27
D 29
	int ubainfo, len, off;
E 29
I 29
D 50
	int ubainfo, len, off, s;
E 50
I 50
	int ubaaddr, len, off, s;
E 50
E 29
I 6
	short resid;
E 6
D 5
COUNT(VVRINT);
E 5

I 51
#ifdef QBA
	splx(vv_softc[unit].vs_ipl);
#endif
E 51
I 27
	vs = &vv_softc[unit];
D 30
	addr = (struct vvreg *)vvinfo[unit]->ui_addr;
E 30
E 27
	vs->vs_if.if_ipackets++;
I 30
	addr = (struct vvreg *)vvinfo[unit]->ui_addr;
I 32

E 32
E 30
I 14
D 15

E 15
E 14
	/*
D 45
	 * Purge BDP; drop if input error indicated.
E 45
I 45
	 * Purge BDP
E 45
	 */
I 14
D 15

E 15
E 14
	if (vs->vs_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(vs->vs_ifuba.ifu_uba, vs->vs_ifuba.ifu_r.ifrw_bdp);
I 32

	/*
	 * receive errors?
	 */
E 32
	if (addr->vvicsr & VVRERR) {
D 6
		vs->vs_if.if_ierrors++;
E 6
I 6
D 14
		/*
E 6
		printf("vv%d: error vvicsr = %b\n", unit,
			0xffff&(addr->vvicsr), VV_IBITS);
D 6
		goto setup;
E 6
I 6
		*/
E 14
I 14
D 27
		if (vv_logreaderrors)
E 27
I 27
D 29
		if (vs->vs_if.if_flags & IFF_DEBUG && vv_logreaderrors)
E 27
			printf("vv%d: error vvicsr = %b\n", unit,
E 29
I 29
D 32
		if (vv_logreaderrors && vs->vs_if.if_flags & IFF_DEBUG)
			printf("vv%d: VVRERR, vvicsr = %b\n", unit,
E 29
D 27
				0xffff&(addr->vvicsr), VV_IBITS);
E 27
I 27
			    0xffff&(addr->vvicsr), VV_IBITS);
E 32
I 32
		vvprintf("vv%d: receive error, vvicsr = %b\n", unit,
		    0xffff&(addr->vvicsr), VV_IBITS);
		if (addr->vvicsr & VV_BDF)
			vs->vs_ibadf++;
E 32
E 27
E 14
		goto dropit;
E 6
	}
D 6
	off = 0;
	len = 0;
	vv = (struct vv_header *)(vs->vs_ifuba.ifu_r.ifrw_addr);
E 6
I 6

E 6
	/*
D 6
	 * Demultiplex on packet type and deal with oddities of
	 * trailer protocol format
E 6
I 6
D 32
	 * Get packet length from word count residue
E 32
I 32
	 * parity errors?
	 */
	if (addr->vvicsr & VV_LDE) {
		/* we don't have to clear it because the receive command */
		/* writes 0 to parity bit */
		vs->vs_parity++;
D 45
#ifndef PRONET80
E 45
I 45

E 45
		/*
		 * only on 10 megabit proNET is VV_LDE an end-to-end parity
		 * bit. On 80 megabit, it returns to the intended use of
		 * node-to-node parity. End-to-end parity errors on 80 megabit
		 * give VV_BDF.
		 */
D 45
		goto dropit;
#endif
E 45
I 45
		if (vs->vs_is80 == 0)
		    goto dropit;
E 45
	}

	/*
	 * Get packet length from residual word count
E 32
	 *
	 * Compute header offset if trailer protocol
	 *
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; if_rubaget will then force this header
	 * information to be at the front.  The vh_info field
	 * carries the offset to the trailer data in trailer
	 * format packets.
E 6
	 */
I 14
D 15

E 15
E 14
I 6
	vv = (struct vv_header *)(vs->vs_ifuba.ifu_r.ifrw_addr);
D 14
	if (vv_trace)
		vvprt_hdr("vi", vv);
E 14
I 14
D 15

E 15
	vvtracehdr("vi", vv);
D 15

E 15
E 14
D 32
	resid = addr->vviwc;
E 32
I 32
	resid = addr->vviwc & 01777;	/* only low 10 bits valid */
E 32
	if (resid)
D 32
		resid |= 0176000;		/* ugly!!!! */
	len = (((sizeof (struct vv_header) + VVMRU) >> 1) + resid) << 1;
E 32
I 32
		resid |= 0176000;	/* high 6 bits are undefined */
	len = ((VVBUFSIZE >> 1) + resid) << 1;
E 32
	len -= sizeof(struct vv_header);
D 14
	if (len > VVMRU)
E 14
I 14
D 29
	if (len > VVMRU || len <= 0)
E 29
I 29
D 32
	if (len > VVMRU || len <= 0) {
		if (vv_logreaderrors && vs->vs_if.if_flags & IFF_DEBUG)
			printf("vv%d: len too big, len = %d, vvicsr = %b\n",
E 32
I 32

	if ((addr->vvicsr & VV_DPR) || len > VVMRU || len <= 0) {
		vvprintf("vv%d: len too long or short, \
len = %d, vvicsr = %b\n",
E 32
			    unit, len, 0xffff&(addr->vvicsr), VV_IBITS);
E 29
E 14
		goto dropit;
I 29
	}
I 32

	/* check the protocol header version */
	if (vv->vh_version != RING_VERSION) {
		vvprintf("vv%d: bad protocol header version %d\n",
		    unit, vv->vh_version & 0xff);
		goto dropit;
	}

E 32
E 29
I 14
D 15
	
E 15
E 14
#define	vvdataaddr(vv, off, type)	((type)(((caddr_t)((vv)+1)+(off))))
I 14
D 15

E 15
E 14
D 23
	if (vv_dotrailer && vv->vh_type >= RING_IPTrailer &&
	     vv->vh_type < RING_IPTrailer+RING_IPNTrailer){
E 23
I 23
D 24
	if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
E 24
D 46
	if (vv->vh_type >= RING_IPTrailer &&
	     vv->vh_type < RING_IPTrailer+RING_IPNTrailer) {
E 23
		off = (vv->vh_type - RING_IPTrailer) * 512;
E 46
I 46
	if (vv->vh_type == RING_TRAILER ) {
D 47
		off = ntohs(vv->vh_info);
E 47
I 47
		off = ntohs((u_short)vv->vh_info);
E 47
E 46
D 29
		if (off > VVMTU)
E 29
I 29
		if (off > VVMTU) {
D 32
			if (vv_logreaderrors && vs->vs_if.if_flags & IFF_DEBUG)
				printf("vv%d: VVMTU, off = %d, vvicsr = %b\n",
E 32
I 32
			vvprintf("vv%d: off > VVMTU, off = %d, vvicsr = %b\n",
E 32
				    unit, off, 0xffff&(addr->vvicsr), VV_IBITS);
E 29
			goto dropit;
I 29
		}
E 29
D 45
		vv->vh_type = *vvdataaddr(vv, off, u_short *);
		resid = *(vvdataaddr(vv, off+2, u_short *));
E 45
I 45
		vv->vh_type = ntohs(*vvdataaddr(vv, off, u_short *));
D 46
		resid = ntohs(*(vvdataaddr(vv, off+2, u_short *)));
E 46
I 46
		resid = ntohs(*(vvdataaddr(vv, off+sizeof(u_short), u_short *)));
E 46
E 45
D 29
		if (off + resid > len)
E 29
I 29
		if (off + resid > len) {
D 32
			if (vv_logreaderrors && vs->vs_if.if_flags & IFF_DEBUG)
				printf(
				    "vv%d: off = %d, resid = %d, vvicsr = %b\n",
E 32
I 32
			vvprintf("vv%d: trailer packet too short\n", unit);
			vvprintf("vv%d: off = %d, resid = %d, vvicsr = %b\n",
E 32
				    unit, off, resid,
				    0xffff&(addr->vvicsr), VV_IBITS);
E 29
			goto dropit;
I 29
		}
E 29
		len = off + resid;
D 14
	} else
E 14
I 14
D 15
	} else {
E 15
I 15
	} else
E 15
E 14
		off = 0;
I 32

E 32
I 14
D 15
	}
E 15
E 14
D 29
	if (len == 0)
E 29
I 29
	if (len == 0) {
D 32
		if (vv_logreaderrors && vs->vs_if.if_flags & IFF_DEBUG)
			printf("vv%d: len is zero, vvicsr = %b\n", unit,
E 32
I 32
		vvprintf("vv%d: len is zero, vvicsr = %b\n", unit,
E 32
			    0xffff&(addr->vvicsr), VV_IBITS);
E 29
		goto dropit;
I 29
	}
I 32

E 32
E 29
I 14
D 15

E 15
E 14
D 35
	m = if_rubaget(&vs->vs_ifuba, len, off);
E 35
I 35
	m = if_rubaget(&vs->vs_ifuba, len, off, &vs->vs_if);
E 35
D 15
	if (m == 0)
E 15
I 15
D 29
	if (m == NULL)
E 29
I 29
	if (m == NULL) {
D 32
		if (vv_logreaderrors && vs->vs_if.if_flags & IFF_DEBUG)
			printf("vv%d: if_rubaget failed, vvicsr = %b\n", unit,
E 32
I 32
		vvprintf("vv%d: if_rubaget() failed, vvicsr = %b\n", unit,
E 32
			    0xffff&(addr->vvicsr), VV_IBITS);
E 29
E 15
		goto dropit;
I 29
	}
E 29
I 14
D 15

E 15
E 14
	if (off) {
D 35
		m->m_off += 2 * sizeof(u_short);
		m->m_len -= 2 * sizeof(u_short);
E 35
I 35
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
		*(mtod(m, struct ifnet **)) = ifp;
E 35
	}
I 14

I 29
	/* Keep track of source address of this packet */
	vs->vs_lastr = vv->vh_shost;
I 32

E 32
E 29
	/*
D 27
	 * Demultiplex on packet type 
E 27
I 27
	 * Demultiplex on packet type
E 27
	 */
D 15

E 15
E 14
E 6
	switch (vv->vh_type) {
I 14

E 14
D 6

E 6
#ifdef INET
	case RING_IP:
D 6
		len = htons((u_short)((struct ip *) vv)->ip_len);
E 6
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
#endif
	default:
D 32
		printf("vv%d: unknown pkt type 0x%x\n", unit, vv->vh_type);
E 32
I 32
		vvprintf("vv%d: unknown pkt type 0x%x\n", unit, vv->vh_type);
E 32
I 6
		m_freem(m);
E 6
		goto setup;
	}
I 29
	s = splimp();
E 29
D 6
	if (len == 0)
		goto setup;
	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; if_rubaget will then force this header
	 * information to be at the front, but we still have to drop
	 * the two-byte type which is at the front of any trailer data.
	 */
	m = if_rubaget(&vs->vs_ifuba, len, off);
	if (m == 0)
		goto setup;
	IF_ENQUEUE(inq, m);
E 6
I 6
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		m_freem(m);
D 14
	} else
E 14
I 14
D 15
	} else {
E 15
I 15
	} else
E 15
E 14
		IF_ENQUEUE(inq, m);
I 14
D 15
	}
E 14
E 6

E 15
D 27
setup:
E 27
I 27

I 29
	splx(s);
E 29
E 27
	/*
D 6
	 * Reset for next packet.
E 6
I 6
D 14
	 * Restart the read for next packet.
E 14
I 14
D 27
	 * Check the error rate and start recovery if needed
	 * this has to go here since the timer flywheel runs at
	 * a lower ipl and never gets a chance to change the mode
E 27
I 27
	 * Reset for the next packet.
E 27
E 14
E 6
	 */
D 14
	ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
	addr->vviba = (u_short) ubainfo;
	addr->vviea = (u_short) (ubainfo >> 16);
	addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
	addr->vvicsr = VV_RST | VV_CONF;
	addr->vvicsr |= VV_IEN | VV_DEN | VV_ENB;
I 6
	return;
E 14
I 14
D 27
	if (vs->vs_major == MODE0 && vs->vs_dropped > VV_ERRORTHRESHOLD) {
E 14
E 6
D 15

E 15
I 14
		vvtrprintf("vv%d going MODE1 in vvrint\n",unit);
		vs->vs_major = MODE1;
		vs->vs_iactive = PAUSE;		/* no new reads */
		vs->vs_retry = VV_MODE1ATTEMPTS;
		vs->vs_delayclock = VV_MODE1DELAY;
		vs->vs_minor = 0;
		vs->vs_dropped = 0;
	}
D 15

E 15
	switch (vs->vs_iactive) {
E 27
I 27
setup:
D 50
	ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
	addr->vviba = (u_short) ubainfo;
	addr->vviea = (u_short) (ubainfo >> 16);
E 50
I 50
	ubaaddr = UBAI_ADDR(vs->vs_ifuba.ifu_r.ifrw_info);
	addr->vviba = (u_short) ubaaddr;
	addr->vviea = (u_short) (ubaaddr >> 16);
E 50
D 32
	addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
	addr->vvicsr = VV_RST | VV_CONF;
	addr->vvicsr |= VV_IEN | VV_DEN | VV_ENB;
E 32
I 32
	addr->vviwc = -(VVBUFSIZE) >> 1;
	addr->vvicsr = VV_HEN | VV_IEN | VV_DEN | VV_ENB;
E 32
	return;
E 27

D 15
	case ACTIVE:

		 /* Restart the read for next packet */

E 15
I 15
D 27
	case ACTIVE:		/* Restart the read for next packet */
E 15
		ubainfo = vs->vs_ifuba.ifu_r.ifrw_info;
		addr->vviba = (u_short) ubainfo;
		addr->vviea = (u_short) (ubainfo >> 16);
		addr->vviwc = -(sizeof (struct vv_header) + VVMTU) >> 1;
		addr->vvicsr = VV_RST | VV_CONF;
		addr->vvicsr |= VV_IEN | VV_DEN | VV_ENB;
		return;

D 15
	case PAUSE:

		/* requested to not start any new reads */
E 15
I 15
	case PAUSE:		/* requested to not start any new reads */
E 15
		vs->vs_dropped = 0;
		return;

D 15
	case OPEN:

		/* request to open host relay */
E 15
I 15
	case OPEN:		/* request to open host relay */
E 15
		vs->vs_dropped = 0;
		addr->vvicsr = 0;
		return;

	default:
		printf("vv%d: vs_iactive = %d\n", unit, vs->vs_iactive);
		return;
	}
E 27
D 15

E 15
	/*
D 15
	 * drop packet on floor -- count them!!
E 15
I 15
	 * Drop packet on floor -- count them!!
E 15
	 */
D 15

E 15
E 14
I 6
dropit:
	vs->vs_if.if_ierrors++;
I 14
D 27
	vs->vs_dropped++;
E 14
	/*
	printf("vv%d: error vvicsr = %b\n", unit,
		0xffff&(addr->vvicsr), VV_IBITS);
	*/
E 27
I 27
D 29
	if (vs->vs_if.if_flags & IFF_DEBUG && vv_logreaderrors)
		printf("vv%d: error vvicsr = %b\n", unit,
		    0xffff&(addr->vvicsr), VV_IBITS);
E 29
E 27
	goto setup;
I 14
D 15

E 15
E 14
E 6
}

/*
D 32
 * V2lni output routine.
E 32
I 32
 * proNET output routine.
E 32
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
vvoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
D 30
	register struct mbuf *m = m0;
E 30
I 30
	register struct mbuf *m;
E 30
	register struct vv_header *vv;
D 6
	int type, dest, s;
E 6
I 6
	register int off;
D 30
	int type, dest, s, error;
E 30
I 30
	register int unit;
	register struct vvreg *addr;
	register struct vv_softc *vs;
	register int s;
	int type, dest, error;
E 30
E 6

I 30
	m = m0;
	unit = ifp->if_unit;
	addr = (struct vvreg *)vvinfo[unit]->ui_addr;
	vs = &vv_softc[unit];
I 32

E 32
	/*
D 32
	 * Check to see if the input side has wedged.
E 32
I 32
	 * Check to see if the input side has wedged due the UBA
	 * vectoring through 0.
E 32
	 *
	 * We are lower than device ipl when we enter this routine,
	 * so if the interface is ready with an input packet then
	 * an input interrupt must have slipped through the cracks.
	 *
	 * Avoid the race with an input interrupt by watching to see
	 * if any packets come in.
	 */
	s = vs->vs_if.if_ipackets;
	if (addr->vvicsr & VV_RDY && s == vs->vs_if.if_ipackets) {
D 32
		if (vs->vs_if.if_flags & IFF_DEBUG)
			printf("vv%d: lost a receive interrupt, icsr = %b\n",
E 32
I 32
		vvprintf("vv%d: lost a receive interrupt, icsr = %b\n",
E 32
			    unit, 0xffff&(addr->vvicsr), VV_IBITS);
		s = splimp();
		vvrint(unit);
		splx(s);
	}

E 30
	switch (dst->sa_family) {
I 14

E 14
D 6

E 6
#ifdef INET
D 27
	case AF_INET: {
E 27
I 27
	case AF_INET:
E 27
D 6
		register struct ip *ip = mtod(m0, struct ip *);
		int off;

		dest = ip->ip_dst.s_addr >> 24;
E 6
I 6
D 33
		dest = ((struct sockaddr_in *)dst)->sin_addr.s_addr;
E 33
I 33
		if (in_broadcast(((struct sockaddr_in *)dst)->sin_addr))
			dest = VV_BROADCAST;
		else
			dest = in_lnaof(((struct sockaddr_in *)dst)->sin_addr);
E 33
I 32
#ifdef LOOPBACK
D 33
		if ((dest == ((struct sockaddr_in *)&ifp->if_addr)->sin_addr.s_addr) &&
		   ((loif.if_flags & IFF_UP) != 0))
			return(looutput(&loif, m0, dst));
E 33
I 33
		if (dest == vs->vs_host && (loif.if_flags & IFF_UP))
			return (looutput(&loif, m0, dst));
E 33
#endif LOOPBACK
E 32
I 27
D 28
		/* Check if the loopback can be used */
		if ((dest ==
		   ((struct sockaddr_in *)&ifp->if_addr)->sin_addr.s_addr) &&
		   ((loif.if_flags & IFF_UP) != 0))
		    return(looutput(&loif, m0, dst));
E 28
E 27
D 14
		if (dest & 0x00ffff00) {
E 14
I 14
D 15

		/* check address range */

E 15
D 33
		if ((dest = in_lnaof(*((struct in_addr *)&dest))) >= 0x100) {
E 33
I 33
		if (dest >= 0x100) {
E 33
E 14
			error = EPERM;
			goto bad;
		}
D 14
		dest = (dest >> 24) & 0xff;
E 14
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
I 27
D 32
		/* Need per host negotiation. */
E 32
I 32
		/*
		 * Trailerize, if the configuration allows it.
		 * TODO: Need per host negotiation.
		 */
E 32
E 27
D 24
		if (vv_dotrailer && off > 0 && (off & 0x1ff) == 0 &&
E 24
I 24
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
		if (off > 0 && (off & 0x1ff) == 0 &&
E 24
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
D 46
			type = RING_IPTrailer + (off>>9);
E 46
I 46
			type = RING_TRAILER;
E 46
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
D 45
			*mtod(m, u_short *) = RING_IP;
			*(mtod(m, u_short *) + 1) = m->m_len;
E 45
I 45
D 47
			*mtod(m, u_short *) = htons(RING_IP);
			*(mtod(m, u_short *) + 1) = htons(m->m_len);
E 47
I 47
			*mtod(m, u_short *) = htons((short)RING_IP);
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
E 47
E 45
			goto gottrailertype;
		}
E 6
		type = RING_IP;
		off = 0;
		goto gottype;
D 27
		}
E 27
#endif
	default:
D 30
		printf("vv%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
E 30
I 30
		printf("vv%d: can't handle af%d\n", unit, dst->sa_family);
E 30
D 6
		m_freem(m0);
		return (0);
E 6
I 6
		error = EAFNOSUPPORT;
		goto bad;
E 6
	}

gottrailertype:
	/*
	 * Packet to be sent as trailer: move first packet
	 * (control information) to end of chain.
	 */
	while (m->m_next)
		m = m->m_next;
	m->m_next = m0;
	m = m0->m_next;
	m0->m_next = 0;
	m0 = m;
D 15

E 15
gottype:
	/*
	 * Add local net header.  If no space in first mbuf,
	 * allocate another.
	 */
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof (struct vv_header) > m->m_off) {
D 11
		m = m_get(M_DONTWAIT);
E 11
I 11
D 14
		m = m_get(M_DONTWAIT, MT_HEADER);
E 14
I 14
D 15
		m = m_get(M_DONTWAIT);
E 14
E 11
		if (m == 0) {
E 15
I 15
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == NULL) {
E 15
D 6
			m_freem(m0);
			return (0);
E 6
I 6
			error = ENOBUFS;
			goto bad;
E 6
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof (struct vv_header);
	} else {
		m->m_off -= sizeof (struct vv_header);
		m->m_len += sizeof (struct vv_header);
	}
	vv = mtod(m, struct vv_header *);
D 33
	vv->vh_shost = ifp->if_host[0];
D 27
	vv->vh_dhost = dest;
E 27
I 27
	/* Map the destination address if it's a broadcast */
	if ((vv->vh_dhost = dest) == INADDR_ANY)
		vv->vh_dhost = VV_BROADCAST;
E 33
I 33
	vv->vh_shost = vs->vs_host;
	vv->vh_dhost = dest;
E 33
E 27
	vv->vh_version = RING_VERSION;
	vv->vh_type = type;
D 6
	vv->vh_info = m->m_len;
E 6
I 6
D 45
	vv->vh_info = off;
E 45
I 45
D 47
	vv->vh_info = htons(off);
E 47
I 47
	vv->vh_info = htons((u_short)off);
E 47
E 45
D 14
	if (vv_trace)
		vvprt_hdr("vo", vv);
E 14
I 14
	vvtracehdr("vo", vv);
E 14
E 6

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
I 6
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		error = ENOBUFS;
		goto qfull;
	}
E 6
	IF_ENQUEUE(&ifp->if_snd, m);
D 30
	if (vv_softc[ifp->if_unit].vs_oactive == 0)
		vvstart(ifp->if_unit);
E 30
I 30
	if (vs->vs_oactive == 0)
		vvstart(unit);
E 30
	splx(s);
D 6
	return (1);
E 6
I 6
	return (0);
D 15

E 15
qfull:
	m0 = m;
	splx(s);
bad:
	m_freem(m0);
	return(error);
I 23
}

/*
 * Process an ioctl request.
 */
vvioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 27
	struct ifreq *ifr = (struct ifreq *)data;
	int s = splimp(), error = 0;
E 27
I 27
D 30
	struct ifreq *ifr;
	int s, error;
E 30
I 30
D 33
	register struct ifreq *ifr;
	register int s;
	int error;
E 33
I 33
	struct ifaddr *ifa = (struct ifaddr *) data;
	int s = splimp(), error = 0;
E 33
E 30
E 27

I 27
D 33
	ifr = (struct ifreq *)data;
	error = 0;
	s = splimp();
E 33
E 27
	switch (cmd) {

	case SIOCSIFADDR:
I 35
D 51
		ifp->if_flags |= IFF_UP;
E 51
E 35
D 29
		/* too difficult to change addr while running */
E 29
I 29
D 30
		/* too difficult to change address while running */
E 29
		if ((ifp->if_flags & IFF_RUNNING) == 0) {
D 24
			ifp->if_net = in_netof(ifr->ifr_addr.sin_addr);
E 24
I 24
D 27
			struct sockaddr_in *sin =
			    (struct sockaddr_in *)&ifr->ifr_addr;
			ifp->if_net = in_netof(sin->sin_addr);
E 27
I 27
			vvsetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
E 30
I 30
D 33
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		vvsetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, RTF_UP);
		else
E 33
I 33
		if ((ifp->if_flags & IFF_RUNNING) == 0)
E 33
E 30
E 27
E 24
			vvinit(ifp->if_unit);
I 45
		/*
		 * Did self-test succeed?
		 */
		if ((ifp->if_flags & IFF_UP) == 0)
			error = ENETDOWN;
E 45
I 33
D 51
                /*
                 * Attempt to check agreement of protocol address
                 * and board address.
                 */
		switch (ifa->ifa_addr.sa_family) {
                case AF_INET:
			if (in_lnaof(IA_SIN(ifa)->sin_addr) !=
			    vv_softc[ifp->if_unit].vs_host)
D 37
				return (EADDRNOTAVAIL);
E 37
I 37
				error = EADDRNOTAVAIL;
E 37
			break;
E 51
I 51
		else {
			/*
			 * Attempt to check agreement of protocol address
			 * and board address.
			 */
			switch (ifa->ifa_addr.sa_family) {
			case AF_INET:
				if ((in_lnaof(IA_SIN(ifa)->sin_addr) & 0xff) !=
				    vv_softc[ifp->if_unit].vs_host)
					error = EADDRNOTAVAIL;
				break;
			}
E 51
		}
D 35
		ifp->if_flags |= IFF_UP;
E 35
E 33
D 30
		} else
			error = EINVAL;
E 30
		break;

	default:
		error = EINVAL;
	}
	splx(s);
D 30
	return (error);
E 30
I 30
D 33
	return(error);
E 30
E 23
E 6
}

D 6
#ifdef notdef
E 6
/*
I 27
 * Set up the address for this interface. We use the network number
D 29
 * from the passed address and an invalid host number because vvinit()
 * is smart enough to figure out the host number out.
E 29
I 29
 * from the passed address and an invalid host number; vvinit() will
 * figure out the host number and insert it later.
E 29
 */
vvsetaddr(ifp, sin)
	register struct ifnet *ifp;
	register struct sockaddr_in *sin;
{
	ifp->if_net = in_netof(sin->sin_addr);
	ifp->if_host[0] = 256;			/* an invalid host number */
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags |= IFF_BROADCAST;
}

/*
E 27
 * vvprt_hdr(s, v) print the local net header in "v"
D 27
 * 	with title is "s"
E 27
I 27
 *	with title is "s"
E 27
 */
vvprt_hdr(s, v)
	char *s;
	register struct vv_header *v;
{
	printf("%s: dsvti: 0x%x 0x%x 0x%x 0x%x 0x%x\n",
		s,
		0xff & (int)(v->vh_dhost), 0xff & (int)(v->vh_shost),
		0xff & (int)(v->vh_version), 0xff & (int)(v->vh_type),
		0xffff & (int)(v->vh_info));
E 33
I 33
	return (error);
E 33
}
I 36

/*
 * vvprt_hdr(s, v) print the local net header in "v"
 *	with title is "s"
 */
vvprt_hdr(s, v)
	char *s;
	register struct vv_header *v;
{
	printf("%s: dsvti: 0x%x 0x%x 0x%x 0x%x 0x%x\n",
		s,
		0xff & (int)(v->vh_dhost), 0xff & (int)(v->vh_shost),
		0xff & (int)(v->vh_version), 0xff & (int)(v->vh_type),
		0xffff & (int)(v->vh_info));
}
I 38
D 45
#endif
E 45
I 45
#endif NVV
E 45
E 38
E 36
D 32

I 22
#ifdef notdef
E 22
/*
 * print "l" hex bytes starting at "s"
 */
D 27
vvprt_hex(s, l) 
E 27
I 27
vvprt_hex(s, l)
E 27
	char *s;
	int l;
{
	register int i;
	register int z;

	for (i=0 ; i < l; i++) {
		z = 0xff & (int)(*(s + i));
		printf("%c%c ",
		"0123456789abcdef"[(z >> 4) & 0x0f],
		"0123456789abcdef"[z & 0x0f]
		);
	}
D 3
}
#endif

#if NIMP == 0 && NVV > 0
/*
 * Logical host interface driver.
 * Allows host to appear as an ARPAnet
 * logical host.  Must also have routing
 * table entry set up to forward packets
 * to appropriate geteway on localnet.
 */
struct	ifnet vvlhif;
int	looutput();

/*
 * Called by localnet interface to allow logical
 * host interface to "attach".  
 */
vvlhinit(vvifp, addr)
	struct ifnet *vvifp;
	int addr;
{
	register struct ifnet *ifp = &vvlhif;
	register struct sockaddr_in *sin;

COUNT(VVLHINIT);
	ifp->if_name = "lh";
	ifp->if_mtu = VVMTU;
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = addr;
	ifp->if_net = netpart(sin->sin_addr);
	ifp->if_flags = IFF_UP;
	ifp->if_output = looutput;
	if_attach(ifp);
D 2
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_DIRECT|RTF_UP|RTF_HOST);
E 2
I 2
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_HOST);
E 3
E 2
}
I 22
#endif
E 32
E 22
I 12
D 14
#endif
E 14
E 12
D 6
#endif
E 6
E 1
