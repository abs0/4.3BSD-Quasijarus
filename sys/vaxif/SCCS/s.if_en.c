h41343
s 00013/00002/00733
d D 7.2 88/08/04 15:17:19 bostic 102 101
c add Berkeley specific copyright
e
s 00001/00001/00734
d D 7.1 86/06/05 17:04:58 mckusick 101 100
c 4.3BSD release version
e
s 00000/00003/00735
d D 6.13 85/12/19 15:44:01 karels 100 99
c rm bbnnet
e
s 00042/00000/00696
d D 6.12 85/12/17 15:22:10 sklower 99 98
c add simple-minded XNS support
e
s 00004/00000/00692
d D 6.11 85/11/08 19:18:14 karels 98 97
c ifconfig down resets interface, ifconfig up reinitializes;
c return error when attempting to send to down interface
e
s 00002/00000/00690
d D 6.10 85/10/24 10:06:47 bloom 97 96
c add "#if N?? > 0" 
e
s 00015/00002/00675
d D 6.9 85/09/16 22:20:30 karels 96 95
c pass ifp to if_{r,}ubaget, shuffle it up if receiving trailer
e
s 00007/00001/00670
d D 6.8 85/06/08 13:54:14 mckusick 95 94
c Add copyright
e
s 00002/00000/00669
d D 6.7 85/05/04 22:54:53 bloom 94 93
c ifdef PUP include files
e
s 00039/00038/00630
d D 6.6 85/05/01 09:08:44 karels 93 92
c move interface addresses into protocols; remove struct ether_addr again
e
s 00001/00001/00667
d D 6.5 84/12/20 15:51:39 karels 92 91
c use MGET macro
e
s 00012/00012/00656
d D 6.4 84/08/29 20:43:11 bloom 91 90
c change ot includes.  no more ../h
e
s 00003/00001/00665
d D 6.3 84/05/18 16:56:04 karels 90 89
c must splimp before messing with inqueues if device interrupts at lower ipl
e
s 00011/00006/00655
d D 6.2 84/04/12 12:17:40 karels 89 88
c subnet routing requires change to ensetaddr; purge if_host
e
s 00000/00000/00661
d D 6.1 83/07/29 07:37:35 sam 88 87
c 4.2 distribution
e
s 00023/00014/00638
d D 4.82 83/06/30 01:24:43 sam 87 86
c put etherlink support in, but #ifdef notdef
e
s 00054/00000/00598
d D 4.81 83/06/26 13:33:50 sam 86 84
c conditional kludge for byte swapping -- quiet cmu-stanford mafia
e
s 00046/00000/00598
d R 4.81 83/06/26 13:25:54 sam 85 84
c put in byte swapping for stanford mafia
e
s 00000/00003/00598
d D 4.80 83/06/13 22:45:56 sam 84 83
c lint
e
s 00057/00038/00544
d D 4.79 83/06/12 23:10:11 sam 83 82
c ioctls
e
s 00005/00003/00577
d D 4.78 83/05/30 18:50:10 sam 82 81
c track pup changes
e
s 00014/00013/00566
d D 4.77 83/05/10 11:35:52 sam 81 80
c fix header byte swapping problems and incorrect Ethernet types
e
s 00037/00012/00542
d D 4.76 83/05/10 10:10:53 sam 80 79
c allow network address to be set at boot time
e
s 00001/00001/00553
d D 4.75 82/12/17 12:13:43 sam 79 78
c sun merge
e
s 00001/00001/00553
d D 4.74 82/12/14 17:21:31 sam 78 77
c typed mbufs
e
s 00005/00000/00549
d D 4.73 82/11/17 00:15:13 sam 77 76
c don't allow multiple units to allocate > 2 bdps on a 750
e
s 00001/00001/00548
d D 4.72 82/11/13 23:04:51 sam 76 75
c merge 4.1b with 4.1c
e
s 00001/00001/00548
d D 4.71 82/10/31 15:05:10 root 75 73
c ubareset routines now just if_reset!
e
s 00001/00001/00548
d R 4.71 82/10/24 14:38:28 wnj 74 73
c create netif directory
e
s 00001/00001/00548
d D 4.70 82/10/17 15:17:26 root 73 72
c lint
e
s 00013/00010/00536
d D 4.69 82/10/10 17:02:04 root 72 71
c put vax headers in their place
e
s 00007/00007/00539
d D 4.68 82/10/09 06:10:07 wnj 71 70
c fix includes
e
s 00000/00008/00546
d D 4.67 82/06/20 00:52:18 sam 70 69
c purge COUNT stuff now that we can use gprof
e
s 00000/00004/00554
d D 4.66 82/06/14 09:26:38 sam 69 68
c tired of those old printfs
e
s 00001/00047/00557
d D 4.65 82/06/13 23:00:18 sam 68 67
c add class a/b/c net #'s and purge logical host kludge code
e
s 00002/00002/00602
d D 4.64 82/06/12 23:18:11 wnj 67 66
c now the routing code might wokr
e
s 00003/00002/00601
d D 4.63 82/05/27 13:00:07 sam 66 64
c one more time
e
s 00003/00002/00601
d R 4.63 82/05/27 12:43:33 sam 65 64
c try one more time to do it right
e
s 00001/00001/00602
d D 4.62 82/05/27 08:54:12 wnj 64 62
c raise enlastdel to 50
e
s 00001/00001/00602
d R 4.62 82/05/27 08:50:57 wnj 63 62
c patch lastdel to 100 temporarily
e
s 00001/00001/00602
d D 4.61 82/05/25 16:14:15 sam 62 61
c logical host route needs RTF_HOST
e
s 00017/00031/00586
d D 4.60 82/05/24 17:15:53 wnj 61 60
c pt-pt, loopback can transmit, fixed en bug that bugged sam
e
s 00008/00001/00609
d D 4.59 82/04/24 18:20:12 sam 60 59
c flags now indicate address of gateway; lh filled in from ether address
e
s 00003/00001/00607
d D 4.58 82/04/20 14:02:22 sam 59 58
c make 3com kludge conditional
e
s 00001/00001/00607
d D 4.57 82/04/16 14:19:26 sam 58 57
c don't let driver sleep on interrupt stack if can't get bdp
e
s 00002/00002/00606
d D 4.56 82/04/11 15:15:27 sam 57 56
c reverse src and dst to raw_input
e
s 00001/00000/00607
d D 4.55 82/04/11 02:38:39 feldman 56 55
c raise splimp for ec hack (temporary)
e
s 00017/00011/00590
d D 4.54 82/04/10 18:25:55 sam 55 54
c invert output path to pass back error indications
e
s 00001/00001/00600
d D 4.53 82/04/07 17:48:14 wnj 54 53
c repair kludge
e
s 00009/00004/00592
d D 4.52 82/04/07 17:20:06 wnj 53 52
c kludge to properly restrict broadcast
e
s 00003/00000/00593
d D 4.51 82/04/04 17:58:37 wnj 52 50
c restore missing default
e
s 00007/00007/00586
d R 4.51 82/04/04 13:53:56 root 51 50
c put up logical host if ui->ui_flags &~ 0xff, not dependent on NIMP
e
s 00033/00051/00560
d D 4.50 82/04/04 13:42:36 root 50 49
c reverse packet encaps; no trailers for pup
e
s 00001/00001/00610
d D 4.49 82/04/01 18:36:51 sam 49 48
c flags masked incorrectly
e
s 00001/00001/00610
d D 4.48 82/04/01 11:44:34 root 48 47
c extra arg to enlhinit
e
s 00054/00001/00557
d D 4.47 82/03/31 20:36:17 sam 47 46
c routing tried and working, add logical host stuff
e
s 00002/00004/00556
d D 4.46 82/03/30 19:38:17 sam 46 45
c trailer's handled wrong on pup's
e
s 00002/00000/00558
d D 4.45 82/03/30 11:31:31 sam 45 44
c with routing, but not forwarding
e
s 00051/00052/00507
d D 4.44 82/03/28 14:21:19 sam 44 43
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00558
d D 4.43 82/03/19 01:48:36 wnj 43 42
c fix to use only one soft intr for net thereby fixing bug in raw sockets
e
s 00017/00008/00542
d D 4.42 82/03/15 20:52:01 root 42 41
c better error handling
e
s 00004/00004/00546
d D 4.41 82/03/15 15:57:58 root 41 40
c print only occasional error messages
e
s 00011/00001/00539
d D 4.40 82/03/15 04:43:19 wnj 40 39
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00001/00003/00539
d D 4.39 82/03/13 16:43:42 sam 39 38
c fix pup stuff
e
s 00002/00001/00540
d D 4.38 82/03/13 12:51:42 sam 38 37
c lint
e
s 00002/00000/00539
d D 4.37 82/03/09 17:39:28 root 37 36
c handle broadcast packets
e
s 00048/00003/00491
d D 4.36 82/03/03 11:04:18 sam 36 35
c cleanup raw pup interface
e
s 00001/00001/00493
d D 4.35 82/03/03 09:06:56 root 35 34
c typo in printf
e
s 00001/00000/00493
d D 4.34 82/02/21 14:26:27 root 34 33
c missing counter
e
s 00001/00001/00492
d D 4.33 82/02/05 23:56:03 root 33 32
c btop should really be btoc (round up vs. down)
e
s 00005/00004/00488
d D 4.32 82/02/03 19:39:10 root 32 31
c handles new uba stuff and fix page freeing problem
e
s 00002/00000/00490
d D 4.31 82/01/30 19:32:07 wnj 31 30
c print en errors only if enprintierrors
e
s 00001/00001/00489
d D 4.30 82/01/19 07:29:42 root 30 29
c m_get(0) -> m_get(M_DONTWAIT)
e
s 00000/00001/00490
d D 4.29 82/01/19 01:56:53 wnj 29 28
c en.c: no more kludge; timer: no more printf on rexmt
e
s 00002/00000/00489
d D 4.28 82/01/07 22:11:04 root 28 27
c more ENKLUDGE stuff
e
s 00000/00000/00489
d D 4.27 81/12/22 23:10:02 root 27 26
c new version
e
s 00011/00000/00478
d D 4.26 81/12/22 23:07:50 root 26 25
c 
e
s 00000/00000/00478
d D 4.25 81/12/22 23:01:13 root 25 24
c 
e
s 00000/00000/00478
d D 4.24 81/12/22 22:55:27 root 24 23
c with ENKLUDGE
e
s 00004/00003/00474
d D 4.23 81/12/20 21:39:56 wnj 23 22
c race in if_en.c; no PERSIST before SYN; implement LETDATADRAIN
e
s 00000/00001/00477
d D 4.22 81/12/12 18:04:30 root 22 21
c clean out printf
e
s 00000/00002/00478
d D 4.21 81/12/12 12:58:13 root 21 20
c with crud (first working version)
e
s 00005/00002/00475
d D 4.20 81/12/11 22:13:31 root 20 19
c bug fixes
e
s 00000/00013/00477
d D 4.19 81/12/09 20:38:53 wnj 19 18
c remove debugging crud
e
s 00027/00010/00463
d D 4.18 81/12/09 20:35:11 wnj 18 17
c version with printing crud
e
s 00055/00047/00418
d D 4.17 81/12/03 17:29:03 wnj 17 16
c cleanup
e
s 00002/00001/00463
d D 4.16 81/12/02 16:58:06 wnj 16 15
c yet more lint
e
s 00204/00062/00260
d D 4.15 81/11/29 21:58:42 wnj 15 14
c lint and interface cleanups
e
s 00189/00338/00133
d D 4.14 81/11/26 11:55:51 wnj 14 13
c before carry to ARPAVAX
e
s 00000/00000/00471
d D 4.13 81/11/24 07:53:39 wnj 13 12
c minor fixups pre tcp<->spec coordination
e
s 00008/00000/00463
d D 4.12 81/11/23 15:38:30 wnj 12 11
c band-aid to setup ifen
e
s 00003/00001/00460
d D 4.11 81/11/20 14:41:32 wnj 11 10
c more lint
e
s 00001/00001/00460
d D 4.10 81/11/18 15:36:32 wnj 10 9
c more cleanup
e
s 00014/00033/00447
d D 4.9 81/11/16 14:16:12 wnj 9 8
c more lint
e
s 00004/00001/00476
d D 4.8 81/11/15 12:59:08 wnj 8 7
c listing
e
s 00003/00003/00474
d D 4.7 81/11/14 16:39:27 wnj 7 6
c before overlay
e
s 00011/00011/00466
d D 4.6 81/11/08 16:23:55 wnj 6 5
c first listing
e
s 00006/00006/00471
d D 4.5 81/11/07 14:12:17 wnj 5 4
c constants EN_&
e
s 00001/00001/00476
d D 4.4 81/11/04 00:28:51 wnj 4 3
c more cleanups, fields in ucb.h
e
s 00015/00005/00462
d D 4.3 81/11/01 22:31:49 wnj 3 2
c minor fixups
e
s 00042/00020/00425
d D 4.2 81/10/31 12:01:19 wnj 2 1
c faster imp code...
e
s 00445/00000/00000
d D 4.1 81/10/31 11:03:39 wnj 1 0
c date and time created 81/10/31 11:03:39 by wnj
e
u
U
t
T
I 1
D 14
/* %M% %I% %E% */
E 14
I 14
D 95
/*	%M%	%I%	%E%	*/
E 95
I 95
/*
D 101
 * Copyright (c) 1982 Regents of the University of California.
E 101
I 101
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 101
D 102
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 102
I 102
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
E 102
 *
 *	%W% (Berkeley) %G%
 */
E 95
E 14

I 26
D 29
#define ENKLUDGE
E 29
E 26
#include "en.h"
I 97
#if NEN > 0
E 97
I 47
D 68
#include "imp.h"
E 68
E 47
I 15

E 15
/*
D 15
 * Ethernet interface driver
E 15
I 15
 * Xerox prototype (3 Mb) Ethernet interface driver.
E 15
 */
I 79
#include "../machine/pte.h"
E 79

D 91
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 6
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/imp.h"
#include "../inet/ip.h"
#include "../inet/tcp.h"			/* ### */
E 6
I 6
D 14
#include "../net/inet.h"
I 8
#include "../net/inet_pcb.h"
I 12
#include "../net/if.h"
E 12
E 8
#include "../net/inet_systm.h"
#include "../net/imp.h"
#include "../net/ip.h"
I 8
#include "../net/ip_var.h"
E 8
D 7
#include "../net/tcp.h"			/* ### */
E 7
I 7
#include "../net/tcp.h"			/* XXX */
I 8
#include "../net/tcp_var.h"
E 8
E 7
E 6
#include "../h/map.h"
E 14
D 79
#include "../h/pte.h"
E 79
#include "../h/buf.h"
I 14
#include "../h/protosw.h"
#include "../h/socket.h"
E 14
D 72
#include "../h/ubareg.h"
#include "../h/ubavar.h"
D 14
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
E 14
#include "../h/enreg.h"
D 14
#include "../h/mtpr.h"
E 14
#include "../h/cpu.h"
D 14
#include "../h/cmap.h"
E 14
I 14
#include "../h/mtpr.h"
E 72
#include "../h/vmmac.h"
I 72
D 83
#include <errno.h>
E 83
I 83
#include "../h/errno.h"
#include "../h/ioctl.h"
E 91
I 91
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "errno.h"
#include "ioctl.h"
E 91
E 83

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
I 96

D 100
#ifdef	BBNNET
#define	INET
#endif
E 100
#ifdef	INET
E 96
E 72
D 71
#include "../net/in.h"
#include "../net/in_systm.h"
E 71
I 71
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 93
#include "../netinet/in_var.h"
E 93
E 71
D 72
#include "../net/if.h"
D 71
#include "../net/if_en.h"
#include "../net/if_uba.h"
#include "../net/ip.h"
#include "../net/ip_var.h"
I 36
#include "../net/pup.h"
E 71
I 71
#include "../vaxif/if_en.h"
#include "../vaxif/if_uba.h"
E 72
#include "../netinet/ip.h"
D 96
#include "../netinet/ip_var.h"
E 96
I 96
#endif

E 96
I 94
#ifdef PUP
E 94
#include "../netpup/pup.h"
I 87
#include "../netpup/ether.h"
I 94
#endif
E 94
E 87
E 71
I 45
D 72
#include "../net/route.h"
I 55
#include <errno.h>
E 72
I 72

I 99
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif

E 99
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 91
#include "../vaxif/if_en.h"
#include "../vaxif/if_enreg.h"
#include "../vaxif/if_uba.h"
E 91
I 91
#include "if_en.h"
#include "if_enreg.h"
#include "if_uba.h"
E 91
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 72
E 55
E 45
E 36
E 14

D 9
int	enrswaps, enwswaps;
E 9
I 9
D 14
int	enrswaps;
/* int	enwswaps; */
E 14
I 14
D 18
#define	ENMTU	1024
E 18
I 18
#define	ENMTU	(1024+512)
I 61
#define	ENMRU	(1024+512+16)		/* 16 is enough to receive trailer */
E 61
E 18

E 14
E 9
int	enprobe(), enattach(), enrint(), enxint(), encollide();
struct	uba_device *eninfo[NEN];
u_short enstd[] = { 0 };
struct	uba_driver endriver =
D 14
	{ enprobe, 0, enattach, 0, enstd, "en", eninfo };

E 14
I 14
D 17
	{ enprobe, 0, enattach, 0, enstd, "es", eninfo };
E 17
I 17
	{ enprobe, 0, enattach, 0, enstd, "en", eninfo };
E 17
E 14
#define	ENUNIT(x)	minor(x)

I 15
D 83
int	eninit(),enoutput(),enreset();
E 83
I 83
int	eninit(),enoutput(),enreset(),enioctl();
E 83

I 86
#ifdef notdef
E 86
/*
I 86
 * If you need to byte swap IP's in the system, define
 * this and do a SIOCSIFFLAGS at boot time.
 */
D 93
#define	ENF_SWABIPS	0x100
E 93
I 93
#define	ENF_SWABIPS	0x1000
E 93
#endif

/*
E 86
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * es_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
E 15
D 14
struct	en_packet *xpkt, *rpkt;
struct	en_prefix {
	struct en_header enp_h;
D 7
	struct th enp_th;
E 7
I 7
	struct tcpiphdr enp_th;
E 7
};
struct	uba_regs *enuba;
D 2
struct	pte *enrmr;
E 2
I 2
struct	pte *enrmr, *enxmr;
E 2
int	enrbdp, enwbdp;
int	enrproto, enwproto;
D 2
int	enxmap[1];
E 2
I 2
struct	pte enxmap[2];
int	enxswapd;
E 14
I 14
struct	en_softc {
D 15
	struct	ifnet *es_if;
	struct	ifuba *es_ifuba;
	short	es_delay;
	short	es_mask;
	u_char	es_addr;
	u_char	es_lastx;
	short	es_oactive;
	short	es_olen;
E 15
I 15
	struct	ifnet es_if;		/* network-visible interface */
	struct	ifuba es_ifuba;		/* UNIBUS resources */
I 89
	short	es_host;		/* hardware host number */
E 89
	short	es_delay;		/* current output delay */
	short	es_mask;		/* mask for current output delay */
D 50
	u_char	es_lastx;		/* host last transmitted to */
E 50
I 50
	short	es_lastx;		/* host last transmitted to */
E 50
	short	es_oactive;		/* is output active? */
	short	es_olen;		/* length of last output */
I 99
	short	es_nsactive;		/* is interface enabled for ns? */
E 99
E 15
} en_softc[NEN];
E 14
E 2

I 15
/*
 * Do output DMA to determine interface presence and
 * interrupt vector.  DMA is too short to disturb other hosts.
 */
E 15
enprobe(reg)
	caddr_t reg;
{
D 17
	register int br, cvec;
E 17
I 17
	register int br, cvec;		/* r11, r10 value-result */
E 17
	register struct endevice *addr = (struct endevice *)reg;

I 14
D 70
COUNT(ENPROBE);
E 70
E 14
#ifdef lint
	br = 0; cvec = br; br = cvec;
I 9
D 10
	enrint(), enxint(), encollide();
E 10
I 10
	enrint(0); enxint(0); encollide(0);
E 10
E 9
#endif
D 14

E 14
	addr->en_istat = 0;
D 14
	addr->en_ostat = 0;
E 14
	addr->en_owc = -1;
	addr->en_oba = 0;
D 5
	addr->en_ostat = IEN|GO;
E 5
I 5
	addr->en_ostat = EN_IEN|EN_GO;
E 5
	DELAY(100000);
	addr->en_ostat = 0;
I 56
D 59
	br = 0x16;		/* temporary ec hack */
E 59
I 59
D 84
#ifdef ECHACK
	br = 0x16;
#endif
E 84
E 59
E 56
D 14
	printf("ethernet address %d\n", ~addr->en_addr&0xff);
E 14
	return (1);
}

I 9
D 15
/*ARGSUSED*/
E 15
I 15
/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
E 15
E 9
enattach(ui)
	struct uba_device *ui;
{
I 12
D 14
	extern struct ifnet ifen;
E 14
E 12
D 2
	/* no local state to set up */
E 2
I 2
D 15

E 15
I 15
	register struct en_softc *es = &en_softc[ui->ui_unit];
I 44
D 80
	register struct sockaddr_in *sin;
E 80
E 44
E 15
I 12
D 14
	ifen.if_mtu = 1024;
	ifen.if_net = 10;
	ifen.if_addr.s_host = LOCALHST;
	ifen.if_addr.s_net = LOCALNET;
	ifen.if_addr.s_imp = LOCALIMP;
	n_lhost = ifen.if_addr;
E 14
I 14
D 70
COUNT(ENATTACH);
E 70
D 15
	eninit(ui->ui_unit);
	/* net initialization, based on ui->ui_flags?!? */
E 15
I 15

	es->es_if.if_unit = ui->ui_unit;
I 17
	es->es_if.if_name = "en";
E 17
	es->es_if.if_mtu = ENMTU;
I 93
	es->es_if.if_flags = IFF_BROADCAST;
E 93
D 47
	es->es_if.if_net = ui->ui_flags;
E 47
I 47
D 49
	es->es_if.if_net = ui->ui_flags & 0xffff;
E 49
I 49
D 68
	es->es_if.if_net = ui->ui_flags & 0xff;
E 68
I 68
D 80
	es->es_if.if_net = ui->ui_flags;
E 68
E 49
E 47
	es->es_if.if_host[0] =
D 18
	    ~(((struct endevice *)eninfo[ui->ui_unit])->en_addr) & 0xff;
E 18
I 18
D 44
	    (~(((struct endevice *)eninfo[ui->ui_unit]->ui_addr)->en_addr)) & 0xff;
I 26
#ifdef ENKLUDGE
	if (es->es_if.if_net == 10) {
		es->es_if.if_host[0] <<= 16;
		es->es_if.if_host[0] |= 0x4e;
	}
#endif
E 26
E 18
	es->es_if.if_addr =
	    if_makeaddr(es->es_if.if_net, es->es_if.if_host[0]);
I 37
	es->es_if.if_broadaddr =
	    if_makeaddr(es->es_if.if_net, 0);
E 44
I 44
	 (~(((struct endevice *)eninfo[ui->ui_unit]->ui_addr)->en_addr)) & 0xff;
	sin = (struct sockaddr_in *)&es->es_if.if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(es->es_if.if_net, es->es_if.if_host[0]);
	sin = (struct sockaddr_in *)&es->es_if.if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(es->es_if.if_net, 0);
	es->es_if.if_flags = IFF_BROADCAST;
E 80
I 80
D 83
	if (ui->ui_flags)
		ensetaddr(es, ui->ui_flags);
E 83
E 80
E 44
E 37
D 17
	es->es_if.if_output = enoutput;
E 17
	es->es_if.if_init = eninit;
I 17
	es->es_if.if_output = enoutput;
I 83
	es->es_if.if_ioctl = enioctl;
E 83
E 17
D 75
	es->es_if.if_ubareset = enreset;
E 75
I 75
	es->es_if.if_reset = enreset;
E 75
I 32
D 58
	es->es_ifuba.ifu_flags = UBA_NEEDBDP | UBA_NEED16;
E 58
I 58
	es->es_ifuba.ifu_flags = UBA_NEEDBDP | UBA_NEED16 | UBA_CANTWAIT;
I 77
#if defined(VAX750)
	/* don't chew up 750 bdp's */
	if (cpu == VAX_750 && ui->ui_unit > 0)
		es->es_ifuba.ifu_flags &= ~UBA_NEEDBDP;
#endif
E 77
E 58
E 32
I 16
	if_attach(&es->es_if);
I 47
D 68
#if NIMP == 0
	/* here's one for you john baby.... */
D 48
	enlhinit(&es->es_if, (ui->ui_flags &~ 0xff) | 0x0a);
E 48
I 48
D 60
	enlhinit((ui->ui_flags &~ 0xff) | 0x0a);
E 60
I 60
D 61
	if (ui->ui_flags &~ 0xff) {
		struct in_addr logicaladdr;

		logicaladdr.s_addr = ui->ui_flags;	/* gateway */
		logicaladdr.s_lh = es->es_if.if_host[0];
		logicaladdr.s_net = 10;
		enlhinit(logicaladdr);
	}
E 61
I 61
	if (ui->ui_flags &~ 0xff)
		enlhinit(&es->es_if, (ui->ui_flags &~ 0xff) | 0x0a);
E 61
E 60
E 48
#endif
E 68
E 47
E 16
E 15
E 14
E 12
E 2
}

D 2
imp_init(unit)
E 2
I 2
D 15
eninit(unit)
E 2
	int unit;
E 15
I 15
/*
I 80
D 83
 * Set interface's Internet address
 * given the network number.  The station
 * number, taken from the on-board register,
 * is used as the local part.
 */
ensetaddr(es, net)
	register struct en_softc *es;
	int net;
{
	struct endevice *enaddr;
	register struct sockaddr_in *sin;

	es->es_if.if_net = net;
	enaddr = (struct endevice *)eninfo[es->es_if.if_unit]->ui_addr;
	es->es_if.if_host[0] = (~enaddr->en_addr) & 0xff;
	sin = (struct sockaddr_in *)&es->es_if.if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(net, es->es_if.if_host[0]);
	sin = (struct sockaddr_in *)&es->es_if.if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(net, INADDR_ANY);
	es->es_if.if_flags |= IFF_BROADCAST;
}

/*
E 83
E 80
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
enreset(unit, uban)
	int unit, uban;
E 15
D 14
{	
	register struct endevice *addr;
E 14
I 14
{
E 14
	register struct uba_device *ui;
D 14
	int uban, x;
	static reenter;
E 14
I 14
D 15
	register struct endevice *addr;
	register struct en_softc *es;
E 15
I 15
D 70
COUNT(ENRESET);
E 70
E 15
E 14

I 14
D 15
COUNT(ENINIT);
E 15
E 14
D 17
	if (unit >= NEN || (ui = eninfo[unit]) == 0 || ui->ui_alive == 0) {
D 14
		printf("en%d: not alive\n", unit);
E 14
I 14
		printf("es%d: not alive\n", unit);
E 17
I 17
	if (unit >= NEN || (ui = eninfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
E 17
E 14
		return;
D 17
	}
I 15
	if (ui->ui_ubanum != uban)
		return;
E 17
I 17
	printf(" en%d", unit);
E 17
	eninit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
eninit(unit)
	int unit;
{
D 17
	register struct uba_device *ui;
E 17
I 17
	register struct en_softc *es = &en_softc[unit];
	register struct uba_device *ui = eninfo[unit];
E 17
	register struct endevice *addr;
D 17
	register struct en_softc *es;
E 17
D 80
	int s;
E 80
I 80
D 93
	struct sockaddr_in *sin = (struct sockaddr_in *)&es->es_if.if_addr;
E 93
D 83
	int net, s;
E 83
I 83
	int s;
E 83
E 80

I 80
D 83
	net = in_netof(sin->sin_addr);
	if (net == 0)
E 83
I 83
D 93
	if (in_netof(sin->sin_addr) == 0)
E 93
I 93
	if (es->es_if.if_addrlist == (struct ifaddr *)0)
E 93
E 83
		return;
D 83
	ensetaddr(es, net);
#ifdef notdef
	if (es->es_if.if_flags & IFF_UP)
		return;
#endif
E 83
E 80
E 15
D 14
	x = splimp();
	if (reenter == 0) {
		int n, j, i, k; char *cp;
		reenter = 1;
		n = 10;
		k = n<<1;
D 6
		i = rmalloc(netmap, n*2);
E 6
I 6
		i = rmalloc(mbmap, n*2);
E 6
		if (i == 0)
D 2
			panic("imp_init");
E 2
I 2
			panic("eninit");
E 2
		j = i << 1;
		cp = (char *)pftom(i);
D 6
		if (memall(&Netmap[j], k, proc, CSYS) == 0)
E 6
I 6
		if (memall(&Mbmap[j], k, proc, CSYS) == 0)
E 6
D 9
			return (0);
E 9
I 9
			panic("eninit");
E 9
D 6
		vmaccess(&Netmap[j], (caddr_t)cp, k);
E 6
I 6
		vmaccess(&Mbmap[j], (caddr_t)cp, k);
E 6
		rpkt = (struct en_packet *)
		    (cp + 1024 - sizeof (struct en_prefix));
		xpkt = (struct en_packet *)
		    (cp + 5 * 1024 + 1024 - sizeof (struct en_prefix));
		for (j = 0; j < n; j++)
			mprefcnt[i+j] = 1;
E 14
I 14
D 17
	es = &en_softc[unit];
D 15
	if (if_ubainit(es->es_ifuba, ui->ui_ubanum,
	    sizeof (struct en_header), btop(ENMTU)) == 0) { 
E 15
I 15
	ui = eninfo[unit];
E 17
	if (if_ubainit(&es->es_ifuba, ui->ui_ubanum,
D 33
	    sizeof (struct en_header), (int)btop(ENMTU)) == 0) { 
E 33
I 33
D 61
	    sizeof (struct en_header), (int)btoc(ENMTU)) == 0) { 
E 61
I 61
	    sizeof (struct en_header), (int)btoc(ENMRU)) == 0) { 
E 61
E 33
E 15
D 17
		printf("es%d: can't initialize\n", unit);
E 17
I 17
		printf("en%d: can't initialize\n", unit);
I 44
		es->es_if.if_flags &= ~IFF_UP;
E 44
E 17
		return;
E 14
	}
D 14
	uban = ui->ui_ubanum;
E 14
	addr = (struct endevice *)ui->ui_addr;
D 14
	addr->en_istat = 0;
	addr->en_ostat = 0;
	imp_stat.iaddr =
	    uballoc(uban, (caddr_t)rpkt, 1024+512, UBA_NEED16|UBA_NEEDBDP);
	imp_stat.oaddr =
	    uballoc(uban, (caddr_t)xpkt, 1024+512, UBA_NEED16|UBA_NEEDBDP);
	enuba = ui->ui_hd->uh_uba;
	enrbdp = (imp_stat.iaddr >> 28) & 0xf;
	enwbdp = (imp_stat.oaddr >> 28) & 0xf;
	enrproto = UBAMR_MRV | (enrbdp << 21);
	enwproto = UBAMR_MRV | (enwbdp << 21);
	enrmr = &enuba->uba_map[((imp_stat.iaddr>>9)&0x1ff) + 1];
I 2
	enxmr = &enuba->uba_map[((imp_stat.oaddr>>9)&0x1ff) + 1];
	enxmap[0] = enxmr[0];
	enxmap[1] = enxmr[1];
	enxswapd = 0;
E 2
	printf("enrbdp %x enrproto %x enrmr %x imp_stat.iaddr %x\n",
	    enrbdp, enrproto, enrmr, imp_stat.iaddr);
	imp_stat.impopen = 1;
	imp_stat.flush = 0;
	splx(x);
#ifdef IMPDEBUG
	printf("eninit(%d): iaddr = %x, oaddr = %x\n",
		unit, imp_stat.iaddr, imp_stat.oaddr);
#endif
E 14
I 14
	addr->en_istat = addr->en_ostat = 0;
E 14
D 15
}
E 15

I 11
D 14
#if 0
E 14
E 11
D 15
enreset(uban)
	int uban;
{
	register int unit;
	struct uba_device *ui;

I 14
COUNT(ENRESET);
E 14
	for (unit = 0; unit < NEN; unit++) {
		ui = eninfo[unit];
		if (ui == 0 || ui->ui_ubanum != uban || ui->ui_alive == 0)
			continue;
D 14
		if (imp_stat.iaddr)
D 9
			ubarelse(uban, imp_stat.iaddr);
E 9
I 9
			ubarelse(uban, &imp_stat.iaddr);
E 9
		if (imp_stat.oaddr)
D 9
			ubarelse(uban, imp_stat.oaddr);
E 9
I 9
			ubarelse(uban, &imp_stat.oaddr);
E 14
E 9
D 2
		imp_init(unit);
E 2
I 2
		eninit(unit);
E 2
D 14
		printf("en%d ", unit);
E 14
I 14
		printf("es%d ", unit);
E 14
	}
E 15
I 15
	/*
D 17
	 * Hang pending read, start any writes.
E 17
I 17
	 * Hang a receive and start any
	 * pending writes by faking a transmit complete.
E 17
	 */
	s = splimp();
D 17
	enstart(unit);
E 17
I 17
	addr->en_iba = es->es_ifuba.ifu_r.ifrw_info;
D 61
	addr->en_iwc = -(sizeof (struct en_header) + ENMTU) >> 1;
E 61
I 61
	addr->en_iwc = -(sizeof (struct en_header) + ENMRU) >> 1;
E 61
	addr->en_istat = EN_IEN|EN_GO;
	es->es_oactive = 1;
I 44
D 83
	es->es_if.if_flags |= IFF_UP;
E 83
I 83
D 93
	es->es_if.if_flags |= IFF_UP|IFF_RUNNING;
E 93
I 93
	es->es_if.if_flags |= IFF_RUNNING;
E 93
E 83
E 44
E 17
	enxint(unit);
	splx(s);
I 45
D 67
	if_rtinit(&es->es_if, RTF_DIRECT|RTF_UP);
E 67
I 67
D 93
	if_rtinit(&es->es_if, RTF_UP);
E 93
E 67
E 45
E 15
}
I 11
D 14
#endif
E 14
E 11

I 50
int	enalldelay = 0;
E 50
I 3
D 64
int	enlastdel = 25;
E 64
I 64
int	enlastdel = 50;
E 64
I 50
int	enlastmask = (~0) << 5;
E 50
D 14
int	enlastx = 0;
E 14
I 14

I 15
/*
 * Start or restart output on interface.
 * If interface is already active, then this is a retransmit
 * after a collision, and just restuff registers and delay.
 * If interface is not already active, get another datagram
 * to send off of the interface queue, and map it to the interface
 * before starting the output.
 */
E 15
E 14
E 3
D 2
imp_output(dev)
E 2
I 2
enstart(dev)
E 2
	dev_t dev;
{
D 14
	register struct mbuf *m, *mp;
	register struct endevice *addr;
	register caddr_t cp, top;
E 14
D 17
        int unit;
D 14
        register int len;
E 14
D 9
	u_short uaddr;
E 9
	struct uba_device *ui;
E 17
I 17
        int unit = ENUNIT(dev);
	struct uba_device *ui = eninfo[unit];
	register struct en_softc *es = &en_softc[unit];
E 17
D 2
COUNT(IMP_OUTPUT);
E 2
I 2
D 14
	int enxswapnow = 0;
E 14
I 14
	register struct endevice *addr;
I 89
	register struct en_header *en;
E 89
D 17
	register struct en_softc *es;
E 17
D 15
	register struct ifuba *ifu;
E 15
	struct mbuf *m;
	int dest;
E 14
D 70
COUNT(ENSTART);
E 70
E 2

D 17
	unit = ENUNIT(dev);
	ui = eninfo[unit];
D 14
	if (ui == 0 || ui->ui_alive == 0) {
		printf("en%d (imp_output): not alive\n", unit);
E 14
I 14
	es = &en_softc[unit];
E 17
	if (es->es_oactive)
		goto restart;
D 15
	IF_DEQUEUE(&es->es_if->if_snd, m);
E 15
I 15

	/*
	 * Not already active: dequeue another request
	 * and map it to the UNIBUS.  If no more requests,
	 * just return.
	 */
	IF_DEQUEUE(&es->es_if.if_snd, m);
E 15
	if (m == 0) {
		es->es_oactive = 0;
E 14
		return;
	}
I 18
D 89
	dest = mtod(m, struct en_header *)->en_dhost;
E 89
I 89
	en = mtod(m, struct en_header *);
	dest = en->en_dhost;
	en->en_shost = es->es_host;
E 89
D 19
printf("if_wubaput m=%x\n", m);
E 19
E 18
I 14
D 15
	dest = mtod(m, struct en_header *)->en_dhost;
E 15
	es->es_olen = if_wubaput(&es->es_ifuba, m);
I 86
#ifdef ENF_SWABIPS
	/*
	 * The Xerox interface does word at a time DMA, so
	 * someone must do byte swapping of user data if high
	 * and low ender machines are to communicate.  It doesn't
	 * belong here, but certain people depend on it, so...
	 *
	 * Should swab everybody, but this is a kludge anyway.
	 */
	if (es->es_if.if_flags & ENF_SWABIPS) {
D 89
		register struct en_header *en;
E 86
I 18
D 19
printf("wubaput to %x len %d\n", es->es_ifuba.ifu_w.ifrw_addr, es->es_olen);
asm("halt");
E 19
E 18
I 15

E 89
I 86
		en = (struct en_header *)es->es_ifuba.ifu_w.ifrw_addr;
		if (en->en_type == ENTYPE_IP)
			enswab((caddr_t)(en + 1), (caddr_t)(en + 1),
			    es->es_olen - sizeof (struct en_header) + 1);
	}
#endif

E 86
	/*
	 * Ethernet cannot take back-to-back packets (no
D 50
	 * buffering in interface.  To avoid overrunning
	 * receiver, enforce a small delay (about 1ms) in interface
	 * on successive packets sent to same host.
E 50
I 50
	 * buffering in interface.  To help avoid overrunning
	 * receivers, enforce a small delay (about 1ms) in interface:
	 *	* between all packets when enalldelay
	 *	* whenever last packet was broadcast
	 *	* whenever this packet is to same host as last packet
E 50
	 */
D 18
	dest = mtod(m, struct en_header *)->en_dhost;
E 18
E 15
D 50
	if (es->es_lastx && es->es_lastx == dest)
E 50
I 50
	if (enalldelay || es->es_lastx == 0 || es->es_lastx == dest) {
E 50
		es->es_delay = enlastdel;
D 50
	else
		es->es_lastx = dest;
E 50
I 50
		es->es_mask = enlastmask;
	}
	es->es_lastx = dest;
E 50
I 15

E 15
restart:
D 15
	ifu = es->es_ifuba;
	UBAPURGE(ifu->ifu_uba, ifu->ifu_w.ifrw_bdp);
E 15
I 15
	/*
	 * Have request mapped to UNIBUS for transmission.
	 * Purge any stale data from this BDP, and start the otput.
	 */
D 44
	UBAPURGE(es->es_ifuba.ifu_uba, es->es_ifuba.ifu_w.ifrw_bdp);
E 44
I 44
	if (es->es_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(es->es_ifuba.ifu_uba, es->es_ifuba.ifu_w.ifrw_bdp);
E 44
E 15
E 14
	addr = (struct endevice *)ui->ui_addr;
D 14
	if (!imp_stat.outactive) {
		if ((m = imp_stat.outq_head) == NULL)
			return;
		imp_stat.outactive = 1;      /* set myself active */
		imp_stat.outq_head = m->m_act;  /* -> next packet chain */
		/*
		 * Pack mbufs into ethernet packet.
		 */
		cp = (caddr_t)xpkt;
		top = (caddr_t)xpkt + sizeof(struct en_packet);
		while (m != NULL) {
I 2
			char *dp;
E 2
			if (cp + m->m_len > top) {
				printf("imp_snd: my packet runneth over\n");
				m_freem(m);
				return;
			}
D 2
			bcopy((int)m + m->m_off, cp, m->m_len);
E 2
I 2
			dp = mtod(m, char *);
			if (((int)cp&0x3ff)==0 && ((int)dp&0x3ff)==0) {
D 6
				struct pte *pte = &Netmap[mtopf(dp)*2];
E 6
I 6
				struct pte *pte = &Mbmap[mtopf(dp)*2];
E 6
				*(int *)enxmr = enwproto | pte++->pg_pfnum;
				*(int *)(enxmr+1) = enwproto | pte->pg_pfnum;
				enxswapd = enxswapnow = 1;
			} else
D 9
				bcopy((int)m + m->m_off, cp, m->m_len);
E 9
I 9
				bcopy(mtod(m, caddr_t), cp,
				    (unsigned)m->m_len);
E 9
E 2
			cp += m->m_len;
I 2
			/* too soon! */
E 2
			MFREE(m, mp);
			m = mp;
		}
I 3
		if (enxswapnow == 0 && enxswapd) {
			enxmr[0] = enxmap[0];
			enxmr[1] = enxmap[1];
		}
		if (enlastx && enlastx == xpkt->Header.en_dhost)
			imp_stat.endelay = enlastdel;
		else
			enlastx = xpkt->Header.en_dhost;
E 3
	}
I 2
D 3
	if (enxswapnow == 0 && enxswapd) {
		enxmr[0] = enxmap[0];
		enxmr[1] = enxmap[1];
	}
E 3
E 2
D 9
	len = ntohs(((struct ip *)((int)xpkt + L1822))->ip_len) + L1822;
E 9
I 9
	len = ntohs((u_short)(((struct ip *)((int)xpkt + L1822))->ip_len)) +
	    L1822;
E 9
	if (len > sizeof(struct en_packet)) {
		printf("imp_output: ridiculous IP length %d\n", len);
		return;
	}
#if defined(VAX780) || defined(VAX750)
	switch (cpu) {
#if defined(VAX780)
	case VAX_780:
D 2
		UBA_PURGE780(ui->ui_hd->uh_uba, imp_stat.oaddr>>28);
E 2
I 2
		UBA_PURGE780(enuba, enwbdp);
E 2
		break;
#endif
#if defined(VAX750)
	case VAX_750:
D 2
		UBA_PURGE750(ui->ui_hd->uh_uba, imp_stat.oaddr>>28);
E 2
I 2
		UBA_PURGE750(enuba, enwbdp);
E 2
		break;
#endif
	}
#endif
	addr->en_oba = imp_stat.oaddr;
	addr->en_odelay = imp_stat.endelay;
	addr->en_owc = -((len + 1) >> 1);
#ifdef IMPDEBUG
	printf("en%d: sending packet (%d bytes)\n", unit, len);
	prt_byte(xpkt, len);
#endif
E 14
I 14
D 15
	addr->en_oba = (int)ifu->ifu_w.ifrw_addr;
E 15
I 15
D 16
	addr->en_oba = (int)es->es_ifuba.ifu_w.ifrw_addr;
E 16
I 16
	addr->en_oba = (int)es->es_ifuba.ifu_w.ifrw_info;
E 16
E 15
	addr->en_odelay = es->es_delay;
	addr->en_owc = -((es->es_olen + 1) >> 1);
E 14
D 5
	addr->en_ostat = IEN|GO;
E 5
I 5
	addr->en_ostat = EN_IEN|EN_GO;
I 14
	es->es_oactive = 1;
E 14
E 5
}

I 15
/*
 * Ethernet interface transmitter interrupt.
 * Start another output if more data to send.
 */
E 15
D 14
/*
D 2
 * Start a read operation.
E 2
I 2
D 9
 * Setup for a read
E 2
 */
D 2
imp_read(dev)
E 2
I 2
ensetup(dev)
E 2
	dev_t dev;
{
	register struct endevice *addr;
	register struct uba_device *ui;
        register unsigned ubaddr;
	register int sps;
D 2
COUNT(IMP_READ);
E 2
I 2
COUNT(ENSETUP);
E 2

	ui = eninfo[ENUNIT(dev)];
	if (ui == 0 || ui->ui_alive == 0) {
		printf("en%d (imp_read): not alive\n", ENUNIT(dev));
		return;
	}
	addr = (struct endevice *)ui->ui_addr;
	addr->en_iba = imp_stat.iaddr;
	addr->en_iwc = -600;	/* a little extra to avoid hardware bugs */
D 5
	addr->en_istat = IEN|GO;
E 5
I 5
	addr->en_istat = EN_IEN|EN_GO;
E 5
}

/*
E 9
 * Output interrupt handler.
 */
E 14
enxint(unit)
	int unit;
{
I 17
	register struct uba_device *ui = eninfo[unit];
	register struct en_softc *es = &en_softc[unit];
E 17
D 42
	register struct endevice *addr;
E 42
I 42
	register struct endevice *addr = (struct endevice *)ui->ui_addr;
E 42
D 17
	register struct uba_device *ui;
I 14
	register struct en_softc *es;
E 17
E 14
D 70
COUNT(ENXINT);
E 70

I 18
D 19
printf("enxint\n");
E 19
E 18
D 17
	ui = eninfo[unit];
I 14
	es = &en_softc[unit];
E 17
	if (es->es_oactive == 0)
		return;
E 14
D 42
	addr = (struct endevice *)ui->ui_addr;
D 14

#ifdef IMPDEBUG
	printf("en%d: enxint ostat=%b\n", unit, addr->en_ostat, EN_BITS);
#endif
	if (!imp_stat.outactive) {
		printf("en%d: phantom output intr ostat=%b\n",
			unit, addr->en_ostat, EN_BITS);
E 14
I 14
D 17
	es = &en_softc[unit];
E 17
I 17
	es->es_if.if_opackets++;
E 17
	es->es_oactive = 0;
	es->es_delay = 0;
	es->es_mask = ~0;
D 23
	if (addr->en_ostat&EN_OERROR)
E 23
I 23
	if (addr->en_ostat&EN_OERROR) {
E 42
I 42
	if (es->es_mask && (addr->en_ostat&EN_OERROR)) {
E 42
		es->es_if.if_oerrors++;
E 23
D 18
		printf("es%d: output error\n", unit);
E 18
I 18
D 41
		printf("en%d: output error\n", unit);
E 41
I 41
D 69
		if (es->es_if.if_oerrors % 100 == 0)
			printf("en%d: += 100 output errors\n", unit);
E 69
I 42
		endocoll(unit);
		return;
E 42
E 41
I 23
	}
I 42
	es->es_if.if_opackets++;
	es->es_oactive = 0;
	es->es_delay = 0;
	es->es_mask = ~0;
E 42
I 32
	if (es->es_ifuba.ifu_xtofree) {
		m_freem(es->es_ifuba.ifu_xtofree);
		es->es_ifuba.ifu_xtofree = 0;
	}
E 32
E 23
E 18
D 15
	if (es->es_if->if_snd.ifq_head == 0) {
E 15
I 15
	if (es->es_if.if_snd.ifq_head == 0) {
I 17
D 23
		es->es_if.if_oerrors++;
E 23
D 32
		if (es->es_ifuba.ifu_xtofree) {
			m_freem(es->es_ifuba.ifu_xtofree);
			es->es_ifuba.ifu_xtofree = 0;
		}
E 32
E 17
E 15
D 50
		es->es_lastx = 0;
E 50
I 50
		es->es_lastx = 256;		/* putatively illegal */
E 50
E 14
		return;
	}
D 14
	imp_stat.endelay = 0;
	imp_stat.enmask = ~0;
D 5
	if (addr->en_ostat&ERROR)
E 5
I 5
	if (addr->en_ostat&EN_OERROR)
E 5
		printf("en%d: output error ostat=%b\n", unit,
			addr->en_ostat, EN_BITS);
	imp_stat.outactive = 0;
D 2
	imp_output(unit);
E 2
I 2
	if (imp_stat.outq_head)
		enstart(unit);
I 3
	else
		enlastx = 0;
E 14
I 14
	enstart(unit);
E 14
E 3
E 2
}

I 15
/*
 * Collision on ethernet interface.  Do exponential
 * backoff, and retransmit.  If have backed off all
D 44
 * the way printing warning diagnostic, and drop packet.
E 44
I 44
 * the way print warning diagnostic, and drop packet.
E 44
 */
E 15
I 3
D 14
int collisions;
E 14
E 3
encollide(unit)
	int unit;
{
D 14
	register struct endevice *addr;
	register struct uba_device *ui;
E 14
I 14
D 17
	register struct en_softc *es;
E 17
I 17
D 42
	register struct en_softc *es = &en_softc[unit];
E 42
I 42
	struct en_softc *es = &en_softc[unit];
E 42
E 17
E 14
D 70
COUNT(ENCOLLIDE);
E 70

I 18
D 19
printf("encollide\n");
E 19
E 18
I 3
D 14
	collisions++;
E 3
	ui = eninfo[unit];
	addr = (struct endevice *)ui->ui_addr;

#ifdef IMPDEBUG
	printf("en%d: collision ostat=%b\n", unit, addr->en_ostat, EN_BITS);
#endif
	if (!imp_stat.outactive) {
		printf("en%d: phantom collision intr ostat=%b\n",
			unit, addr->en_ostat, EN_BITS);
E 14
I 14
D 17
	es = &en_softc[unit];
E 17
D 15
	es->es_if->if_collisions++;
E 15
I 15
	es->es_if.if_collisions++;
E 15
	if (es->es_oactive == 0)
E 14
		return;
I 42
	endocoll(unit);
}

endocoll(unit)
	int unit;
{
	register struct en_softc *es = &en_softc[unit];

E 42
I 17
	/*
	 * Es_mask is a 16 bit number with n low zero bits, with
	 * n the number of backoffs.  When es_mask is 0 we have
	 * backed off 16 times, and give up.
	 */
E 17
D 14
	}
	if (imp_stat.enmask == 0) {
		printf("en%d: output error ostat=%b\n", unit,
			addr->en_ostat, EN_BITS);
E 14
I 14
	if (es->es_mask == 0) {
D 18
		printf("es%d: send error\n", unit);
E 18
I 18
		printf("en%d: send error\n", unit);
E 18
		enxint(unit);
E 14
D 17
	} else {
D 14
		imp_stat.enmask <<= 1;
D 3
		imp_stat.endelay = time & ~imp_stat.enmask;
E 3
I 3
		imp_stat.endelay = mfpr(ICR) & ~imp_stat.enmask;
E 14
I 14
		es->es_mask <<= 1;
		es->es_delay = mfpr(ICR) &~ es->es_mask;
		enstart(unit);
E 17
I 17
		return;
E 17
E 14
E 3
	}
I 17
	/*
	 * Another backoff.  Restart with delay based on n low bits
	 * of the interval timer.
	 */
	es->es_mask <<= 1;
	es->es_delay = mfpr(ICR) &~ es->es_mask;
	enstart(unit);
E 17
D 2
	imp_output(unit);
E 2
I 2
D 14
	enstart(unit);
E 14
E 2
}

I 31
D 41
int	enprintierrors;
E 41
I 36
D 87
struct	sockaddr_pup pupsrc = { AF_PUP };
struct	sockaddr_pup pupdst = { AF_PUP };
struct	sockproto pupproto = { PF_PUP };
E 87
I 87
#ifdef notdef
struct	sockproto enproto = { AF_ETHERLINK };
struct	sockaddr_en endst = { AF_ETHERLINK };
struct	sockaddr_en ensrc = { AF_ETHERLINK };
#endif
E 87
E 36
E 31
I 15
/*
 * Ethernet interface receiver interrupt.
 * If input error just drop packet.
 * Otherwise purge input buffered data path and examine 
 * packet to determine type.  If can't determine length
 * from type, then have to drop packet.  Othewise decapsulate
 * packet based on type and pass to type specific higher-level
 * input routine.
 */
E 15
enrint(unit)
	int unit;
{
D 14
    	register struct mbuf *m;
	struct mbuf *mp;
	register struct endevice *addr;
	register struct uba_device *ui;
E 14
I 14
D 17
	struct endevice *addr;
	register struct en_softc *es;
D 15
	register struct ifuba *ifu;
E 15
	struct en_header *en;
E 17
I 17
	register struct en_softc *es = &en_softc[unit];
	struct endevice *addr = (struct endevice *)eninfo[unit]->ui_addr;
	register struct en_header *en;
E 17
    	struct mbuf *m;
D 17
	struct ifqueue *inq;
E 14
	register int len;
E 17
I 17
D 50
	int len;
E 50
I 50
D 73
	int len, plen; short resid;
E 73
I 73
	int len; short resid;
E 73
E 50
	register struct ifqueue *inq;
E 17
D 14
	register caddr_t cp;
	struct mbuf *p, *top = 0;
	struct ip *ip;
D 9
	int j, hlen;
E 9
I 9
	u_int hlen;
E 14
I 14
D 90
	int off;
E 90
I 90
	int off, s;
E 90
E 14
E 9
D 70
COUNT(ENRINT);
E 70

I 18
D 19
printf("enrint\n");
E 19
E 18
I 15
D 17
	es = &en_softc[unit];
E 15
D 14
	ui = eninfo[unit];
	addr = (struct endevice *)ui->ui_addr;
#ifdef IMPDEBUG
	printf("en%d: enrint istat=%b\n", unit, addr->en_istat, EN_BITS);
#endif
	if (imp_stat.flush)
		goto flush;
E 14
I 14
	addr = (struct endevice *)eninfo[unit]->ui_addr;
E 17
I 17
	es->es_if.if_ipackets++;
E 17
I 15

	/*
D 17
	 * Purge BDP; drop error packets.
E 17
I 17
	 * Purge BDP; drop if input error indicated.
E 17
	 */
D 44
	UBAPURGE(es->es_ifuba.ifu_uba, es->es_ifuba.ifu_r.ifrw_bdp);
E 44
I 44
	if (es->es_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(es->es_ifuba.ifu_uba, es->es_ifuba.ifu_r.ifrw_bdp);
E 44
E 15
E 14
D 5
	if (addr->en_istat&ERROR) {
E 5
I 5
	if (addr->en_istat&EN_IERROR) {
E 5
D 14
#ifdef notdef
		printf("en%d: input error istat=%b\n", unit,
			addr->en_istat, EN_BITS);
#endif
		goto flush;
E 14
I 14
D 15
		es->es_if->if_ierrors++;
E 15
I 15
		es->es_if.if_ierrors++;
I 31
D 41
		if (enprintierrors)
E 31
E 15
D 18
		printf("es%d: input error\n", unit);
E 18
I 18
		printf("en%d: input error\n", unit);
E 41
I 41
D 69
		if (es->es_if.if_ierrors % 100 == 0)
			printf("en%d: += 100 input errors\n", unit);
E 69
E 41
E 18
		goto setup;
E 14
	}
D 14
#if defined(VAX780) || defined(VAX750)
	switch (cpu) {
#if defined(VAX780)
	case VAX_780:
		UBA_PURGE780(enuba, enrbdp);
E 14
I 14
D 15
	ifu = en_softc[unit].es_ifuba;
	UBAPURGE(ifu->ifu_uba, ifu->ifu_r.ifrw_bdp);
	en = (struct en_header *)(ifu->ifu_r.ifrw_addr);
E 15
I 15

	/*
I 50
	 * Calculate input data length.
E 50
	 * Get pointer to ethernet header (in input buffer).
	 * Deal with trailer protocol: if type is PUP trailer
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
I 50
	resid = addr->en_iwc;
	if (resid)
		resid |= 0176000;
D 61
	len = (((sizeof (struct en_header) + ENMTU) >> 1) + resid) << 1;
E 61
I 61
	len = (((sizeof (struct en_header) + ENMRU) >> 1) + resid) << 1;
E 61
	len -= sizeof (struct en_header);
D 61
	if (len >= ENMTU)
E 61
I 61
	if (len > ENMRU)
E 61
		goto setup;			/* sanity */
E 50
	en = (struct en_header *)(es->es_ifuba.ifu_r.ifrw_addr);
I 81
	en->en_type = ntohs(en->en_type);
E 81
I 18
D 19
printf("en %x, en->en_type %d\n", en, en->en_type);
E 19
E 18
E 15
#define	endataaddr(en, off, type)	((type)(((caddr_t)((en)+1)+(off))))
D 81
	if (en->en_type >= ENPUP_TRAIL &&
	    en->en_type < ENPUP_TRAIL+ENPUP_NTRAILER) {
		off = (en->en_type - ENPUP_TRAIL) * 512;
E 81
I 81
	if (en->en_type >= ENTYPE_TRAIL &&
	    en->en_type < ENTYPE_TRAIL+ENTYPE_NTRAILER) {
		off = (en->en_type - ENTYPE_TRAIL) * 512;
E 81
I 17
D 61
		if (off >= ENMTU)
E 61
I 61
		if (off > ENMTU)
E 61
			goto setup;		/* sanity */
E 17
D 81
		en->en_type = *endataaddr(en, off, u_short *);
I 50
		resid = *(endataaddr(en, off+2, u_short *));
E 81
I 81
		en->en_type = ntohs(*endataaddr(en, off, u_short *));
		resid = ntohs(*(endataaddr(en, off+2, u_short *)));
E 81
		if (off + resid > len)
			goto setup;		/* sanity */
		len = off + resid;
E 50
D 17
		off += 2;
E 17
	} else
		off = 0;
I 15
D 50

I 18
D 19
printf("off %d\n", off);
E 19
E 18
	/*
	 * Attempt to infer packet length from type;
	 * can't deal with packet if can't infer length.
	 */
E 15
	switch (en->en_type) {

#ifdef INET
	case ENPUP_IPTYPE:
D 18
		len = endataaddr(en, off, struct ip *)->ip_len;
E 18
I 18
D 20
		len = htons(endataaddr(en, off+2, struct ip *)->ip_len)+2;
E 20
I 20
D 44
		len = htons((u_short)endataaddr(en, off ? off+2 : 0, struct ip *)->ip_len);
E 44
I 44
		len = htons((u_short)endataaddr(en,
			off ? off + sizeof (u_short) : 0, struct ip *)->ip_len);
E 44
D 46
		if (off)
D 44
			len += 2;
E 44
I 44
			len += sizeof (u_short);
E 46
E 44
D 22
printf("enet rcvd len %d\n", len);
E 22
E 20
E 18
D 36
		setipintr();
		inq = &ipintrq;
E 36
E 14
		break;
#endif
D 14
#if defined(VAX750)
	case VAX_750:
		UBA_PURGE750(enuba, enrbdp);
		break;
#endif
	}
#endif
	ip = (struct ip *)((int)rpkt + L1822);
D 11
	len = ntohs(ip->ip_len) + L1822;
E 11
I 11
	len = ntohs((u_short *)ip->ip_len) + L1822;
E 11
	if (len > sizeof(struct en_packet) || len < sizeof (struct ip)) {
		printf("enrint: bad ip length %d\n", len);
		goto flush;
	}
	hlen = L1822 + sizeof (struct ip);
	switch (ip->ip_p) {
E 14
D 36

E 36
I 36
#ifdef PUP
	case ENPUP_PUPTYPE:
D 44
		len = endataaddr(en, off, struct pup_header *)->pup_length;
E 44
I 44
		len = endataaddr(en, off ? off + sizeof (u_short) : 0,
			struct pup_header *)->pup_length;
E 44
D 46
		if (off)
D 44
			len -= 2;
E 44
I 44
			len -= sizeof (u_short);
E 46
E 44
		break;
#endif
		
E 36
D 4
	case TCPROTO:
E 4
I 4
D 14
	case IPPROTO_TCP:
E 4
D 7
		hlen += ((struct th *)ip)->t_off * 4;
E 7
I 7
D 8
		hlen += ((struct tcpiphdr *)ip)->t_off * 4;
E 8
I 8
		hlen += ((struct tcpiphdr *)ip)->ti_off << 2;
E 8
E 7
		break;
E 14
I 14
	default:
D 35
		printf("en%d: unknow pkt type 0x%x\n", en->en_type);
E 35
I 35
		printf("en%d: unknown pkt type 0x%x\n", unit, en->en_type);
E 35
		goto setup;
E 14
	}
I 46
	if (off)
		len += sizeof (u_short);
E 50
E 46
D 14
	MGET(m, 0);
	if (m == 0)
		goto flush;
	top = m;
	m->m_off = MMINOFF;
	m->m_len = hlen;
D 9
	bcopy(rpkt, mtod(m, caddr_t), hlen);
E 9
I 9
	bcopy((caddr_t)rpkt, mtod(m, caddr_t), hlen);
E 9
	len -= hlen;
	cp = (caddr_t)rpkt + hlen;
	mp = m;
	while (len > 0) {
		MGET(m, 0);
		if (m == NULL)
			goto flush;
		if (len >= PGSIZE) {
			MPGET(p, 1);
			if (p == 0)
				goto nopage;
			m->m_len = PGSIZE;
			m->m_off = (int)p - (int)m;
			if (((int)cp & 0x3ff) == 0) {
D 6
				struct pte *cpte = &Netmap[mtopf(cp)*2];
				struct pte *ppte = &Netmap[mtopf(p)*2];
E 6
I 6
				struct pte *cpte = &Mbmap[mtopf(cp)*2];
				struct pte *ppte = &Mbmap[mtopf(p)*2];
E 6
				struct pte t;
				enrswaps++;
				t = *ppte; *ppte++ = *cpte; *cpte++ = t;
				t = *ppte; *ppte = *cpte; *cpte = t;
				mtpr(TBIS, (caddr_t)cp);
				mtpr(TBIS, (caddr_t)cp+512);
				mtpr(TBIS, (caddr_t)p);
				mtpr(TBIS, (caddr_t)p+512);
				*(int *)(enrmr+1) =
				    cpte[0].pg_pfnum | enrproto;
				*(int *)(enrmr) =
				    cpte[-1].pg_pfnum | enrproto;
				goto nocopy;
			}
		} else {
nopage:
			m->m_len = MIN(MLEN, len);
			m->m_off = MMINOFF;
		}
D 9
		bcopy(cp, (int)m + m->m_off, m->m_len);
E 9
I 9
		bcopy(cp, mtod(m, caddr_t), (unsigned)m->m_len);
E 9
nocopy:
		cp += m->m_len;
		len -= m->m_len;
		mp->m_next = m;
		mp = m;
	}
	m = top;
	if (imp_stat.inq_head != NULL)
		imp_stat.inq_tail->m_act = m;
	else
		imp_stat.inq_head = m;
	imp_stat.inq_tail = m;
#ifdef IMPDEBUG
	printf("en%d: received packet (%d bytes)\n", unit, len);
	prt_byte(rpkt, len);
#endif
	setsoftnet();
D 2
	imp_read(0);			/* begin next read */
	return;
E 2
I 2
	goto setup;
E 2
flush:
	m_freem(top);
#ifdef IMPDEBUG
	printf("en%d: flushing packet %x\n", unit, top);
#endif
E 14
I 14
	if (len == 0)
		goto setup;
I 86
#ifdef ENF_SWABIPS
	if (es->es_if.if_flags & ENF_SWABIPS && en->en_type == ENTYPE_IP)
		enswab((caddr_t)(en + 1), (caddr_t)(en + 1), len);
#endif
E 86
D 15
	m = if_rubaget(&ifu->ifu_r, len, off);
E 15
I 15
D 50

E 50
	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; if_rubaget will then force this header
	 * information to be at the front, but we still have to drop
D 17
	 * the two-byte type which is at the front of the trailer data
	 * (which we ``consumed'' above).
E 17
I 17
D 50
	 * the two-byte type which is at the front of any trailer data.
E 50
I 50
	 * the type and length which are at the front of any trailer data.
E 50
E 17
	 */
D 96
	m = if_rubaget(&es->es_ifuba, len, off);
E 96
I 96
	m = if_rubaget(&es->es_ifuba, len, off, &es->es_if);
E 96
I 18
	if (m == 0)
		goto setup;
D 21
	printf("rubaget returns m %x\n", m);
	asm("halt");
E 21
E 18
	if (off) {
I 96
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
E 96
D 44
		m->m_off += 2;
		m->m_len -= 2;
E 44
I 44
D 50
		m->m_off += sizeof (u_short);
		m->m_len -= sizeof (u_short);
E 50
I 50
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
I 96
		*(mtod(m, struct ifnet **)) = ifp;
E 96
E 50
E 44
	}
I 36
	switch (en->en_type) {

#ifdef INET
D 81
	case ENPUP_IPTYPE:
E 81
I 81
	case ENTYPE_IP:
E 81
D 43
		setipintr();
E 43
I 43
		schednetisr(NETISR_IP);
E 43
		inq = &ipintrq;
		break;
#endif
I 44
#ifdef PUP
E 44
D 81
	case ENPUP_PUPTYPE: {
E 81
I 81
D 87
	case ENTYPE_PUP: {
E 81
		struct pup_header *pup = mtod(m, struct pup_header *);

		pupproto.sp_protocol = pup->pup_type;
D 82
		pupdst.spup_addr = pup->pup_dport;
		pupsrc.spup_addr = pup->pup_sport;
E 82
I 82
		bcopy((caddr_t)pup->pup_dnet, (caddr_t)pupdst.spup_net,
		    sizeof (struct pupport));
		bcopy((caddr_t)pup->pup_snet, (caddr_t)pupsrc.spup_net,
		    sizeof (struct pupport));
E 82
D 38
		raw_input(m, &pupproto, &pupdst, &pupsrc);
E 38
I 38
D 57
		raw_input(m, &pupproto, (struct sockaddr *)&pupdst,
D 44
		 (struct sockaddr *)&pupsrc);
E 44
I 44
		  (struct sockaddr *)&pupsrc);
E 57
I 57
		raw_input(m, &pupproto, (struct sockaddr *)&pupsrc,
		  (struct sockaddr *)&pupdst);
E 87
I 87
	case ENTYPE_PUP:
		rpup_input(m);
E 87
E 57
E 44
E 38
		goto setup;
D 44
		}
E 44
D 87
	}
E 87
I 44
#endif
I 99
#ifdef NS
	case ETHERTYPE_NS:
		if (es->es_nsactive) {
			schednetisr(NETISR_NS);
			inq = &nsintrq;
		} else {
			m_freem(m);
			goto setup;
		}
		break;
#endif

E 99
I 52
	default:
I 87
#ifdef notdef
		enproto.sp_protocol = en->en_type;
		endst.sen_host = en->en_dhost;
		endst.sen_net = ensrc.sen_net = es->es_if.if_net;
		ensrc.sen_host = en->en_shost;
		raw_input(m, &enproto,
		    (struct sockaddr *)&ensrc, (struct sockaddr *)&endst);
#else
E 87
		m_freem(m);
I 87
#endif
E 87
		goto setup;
E 52
	}

I 90
	s = splimp();
E 90
E 44
E 36
E 15
D 40
	IF_ENQUEUE(inq, m);
E 40
I 40
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
D 44
		(void) m_freem(m);
E 44
I 44
		m_freem(m);
E 44
	} else
		IF_ENQUEUE(inq, m);
I 90
	splx(s);
E 90
E 40
I 15

E 15
E 14
D 2
	imp_read(0);			/* begin next read */
}	
E 2
I 2
setup:
D 14
	addr->en_iba = imp_stat.iaddr;
	addr->en_iwc = -600;
E 14
I 14
D 15
	addr->en_iba = es->es_ifuba->ifu_r.ifrw_info;
E 15
I 15
	/*
	 * Reset for next packet.
	 */
	addr->en_iba = es->es_ifuba.ifu_r.ifrw_info;
E 15
D 61
	addr->en_iwc = -(sizeof (struct en_header) + ENMTU) >> 1;
E 61
I 61
	addr->en_iwc = -(sizeof (struct en_header) + ENMRU) >> 1;
E 61
E 14
D 5
	addr->en_istat = IEN|GO;
E 5
I 5
	addr->en_istat = EN_IEN|EN_GO;
E 5
}
E 2

D 14
#ifdef IMPDEBUG
prt_byte(s, ct)
	register char *s;
	int ct;
E 14
I 14
/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
I 15
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
E 15
 */
D 44
enoutput(ifp, m0, pf)
E 44
I 44
enoutput(ifp, m0, dst)
E 44
	struct ifnet *ifp;
	struct mbuf *m0;
D 44
	int pf;
E 44
I 44
	struct sockaddr *dst;
E 44
E 14
{
D 14
	register i, j, c;
E 14
I 14
D 39
	int type, dest;
E 39
I 39
D 44
	int type, dest, s, off;
E 44
I 44
D 55
	int type, dest, s;
E 55
I 55
	int type, dest, s, error;
E 55
E 44
E 39
D 15
	register struct mbuf *m;
E 15
I 15
	register struct mbuf *m = m0;
E 15
	register struct en_header *en;
I 44
	register int off;
E 44
D 39
	int s;
E 39
E 14

I 98
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
		error = ENETDOWN;
		goto bad;
	}
E 98
I 34
D 70
COUNT(ENOUTPUT);
E 70
E 34
D 14
	for (i=0; i<ct; i++) {
		c = *s++;
		for (j=0; j<2 ; j++)
			putchar("0123456789abcdef"[(c>>((1-j)*4))&0xf]);
		putchar(' ');
E 14
I 14
D 44
	switch (pf) {
E 44
I 44
	switch (dst->sa_family) {
E 44

#ifdef INET
D 44
	case PF_INET: {
		register struct ip *ip = mtod(m0, struct ip *);
D 39
		int off;
E 39

I 26
#ifndef ENKLUDGE
E 26
D 15
		off = ip->ip_len - (ip->ip_hl << 2);
		if (off && off % 512 == 0 && m0->m_off >= MMINOFF + 2) {
E 15
I 15
		dest = ip->ip_dst.s_addr >> 24;
I 26
#else
		dest = (ip->ip_dst.s_addr >> 8) & 0xff;
#endif
E 26
D 18
		off = ip->ip_len - m->m_len;
E 18
I 18
D 20
		off = ntohs(ip->ip_len) - m->m_len;
E 20
I 20
		off = ntohs((u_short)ip->ip_len) - m->m_len;
I 28
#ifndef ENKLUDGE
E 28
E 20
D 19
printf("PF_INET enoutput off %d m->m_off %d m->m_len %d\n", off, m->m_off, m->m_len);
E 19
E 18
D 17
		if (off && off % 512 == 0 && m->m_off >= MMINOFF + 2) {
E 17
I 17
		if (off > 0 && (off & 0x1ff) == 0 && m->m_off >= MMINOFF + 2) {
E 44
I 44
	case AF_INET:
D 53
		dest = ((struct sockaddr_in *)dst)->sin_addr.s_addr >> 24;
E 53
I 53
D 93
		dest = ((struct sockaddr_in *)dst)->sin_addr.s_addr;
D 55
		if (dest & 0x00ffff00)
E 55
I 55
D 76
		if (dest & 0x00ffff00) {
E 76
I 76
		if (in_lnaof(*((struct in_addr *)&dest)) >= 0x100) {
E 93
I 93
		{
		struct in_addr in;

		in = ((struct sockaddr_in *)dst)->sin_addr;
		if (in_broadcast(in))
			dest = EN_BROADCAST;
		else
			dest = in_lnaof(in);
		}
		if (dest >= 0x100) {
E 93
E 76
			error = EPERM;		/* ??? */
E 55
D 54
			goto drop;
E 54
I 54
			goto bad;
I 55
		}
E 55
E 54
D 93
		dest = (dest >> 24) & 0xff;
E 93
E 53
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
I 83
		/* need per host negotiation */
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
E 83
		if (off > 0 && (off & 0x1ff) == 0 &&
D 50
		    m->m_off >= MMINOFF + sizeof (u_short)) {
E 50
I 50
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
E 50
E 44
E 17
E 15
D 81
			type = ENPUP_TRAIL + (off>>9);
E 81
I 81
			type = ENTYPE_TRAIL + (off>>9);
E 81
D 15
			m0->m_off -= 2;
			m0->m_len += 2;
			*mtod(m0, u_short *) = ENPUP_IPTYPE;
		} else {
			type = ENPUP_IPTYPE;
			off = 0;
E 15
I 15
D 44
			m->m_off -= 2;
			m->m_len += 2;
E 44
I 44
D 50
			m->m_off -= sizeof (u_short);
			m->m_len += sizeof (u_short);
E 50
I 50
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
E 50
E 44
D 81
			*mtod(m, u_short *) = ENPUP_IPTYPE;
I 50
			*(mtod(m, u_short *) + 1) = m->m_len;
E 81
I 81
			*mtod(m, u_short *) = htons((u_short)ENTYPE_IP);
			*(mtod(m, u_short *) + 1) = ntohs((u_short)m->m_len);
E 81
E 50
			goto gottrailertype;
E 15
		}
I 28
D 44
#endif
E 44
E 28
D 15
		dest = ip->ip_dst.s_addr >> 24;
E 15
I 15
D 81
		type = ENPUP_IPTYPE;
E 81
I 81
		type = ENTYPE_IP;
E 81
I 36
		off = 0;
		goto gottype;
D 44
		}
E 44
#endif
I 99
#ifdef NS
	case AF_NS:
	{
		u_char *up;

		type = ETHERTYPE_NS;
		up = ((struct sockaddr_ns *)dst)->sns_addr.x_host.c_host;
		if (*up & 1)
			dest = EN_BROADCAST;
		else
			dest = up[5];

		off = 0;
		goto gottype;
	}
#endif
E 99
#ifdef PUP
D 44
	case PF_PUP: {
		register struct pup_header *pup = mtod(m, struct pup_header *);

		dest = pup->pup_dhost;
		off = pup->pup_length - m->m_len;
		if (off > 0 && (off & 0x1ff) == 0 && m->m_off >= MMINOFF + 2) {
E 44
I 44
	case AF_PUP:
D 82
		dest = ((struct sockaddr_pup *)dst)->spup_addr.pp_host;
E 82
I 82
		dest = ((struct sockaddr_pup *)dst)->spup_host;
E 82
D 50
		off = mtod(m, struct pup_header *)->pup_length - m->m_len;
		if (off > 0 && (off & 0x1ff) == 0 &&
		    m->m_off >= MMINOFF + sizeof (u_short)) {
E 44
			type = ENPUP_TRAIL + (off>>9);
D 44
			m->m_off -= 2;
			m->m_len += 2;
E 44
I 44
			m->m_off -= sizeof (u_short);
			m->m_len += sizeof (u_short);
E 44
			*mtod(m, u_short *) = ENPUP_PUPTYPE;
			goto gottrailertype;
		}
E 50
D 81
		type = ENPUP_PUPTYPE;
E 81
I 81
		type = ENTYPE_PUP;
E 81
E 36
		off = 0;
		goto gottype;
E 15
D 44
		}
E 44
D 15
		break;
E 15
#endif

I 87
#ifdef notdef
	case AF_ETHERLINK:
		goto gotheader;
#endif

E 87
	default:
D 44
		printf("en%d: can't encapsulate pf%d\n", ifp->if_unit, pf);
E 44
I 44
		printf("en%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
E 44
D 55
		m_freem(m0);
		return (0);
E 55
I 55
		error = EAFNOSUPPORT;
		goto bad;
E 55
E 14
	}
D 14
	putchar('\n');
E 14
I 14
D 15
	if (MMINOFF + sizeof (struct en_header) > m0->m_off) {
E 15
I 15

I 17
gottrailertype:
E 17
	/*
	 * Packet to be sent as trailer: move first packet
	 * (control information) to end of chain.
	 */
D 17
gottrailertype:
E 17
	while (m->m_next)
		m = m->m_next;
	m->m_next = m0;
	m = m0->m_next;
	m0->m_next = 0;
I 17
	m0 = m;
E 17

I 18
D 19
printf("m %x after trailer futz\n", m);
asm("halt");
E 19
E 18
I 17
gottype:
E 17
	/*
	 * Add local net header.  If no space in first mbuf,
	 * allocate another.
	 */
D 17
gottype:
	m0 = m;
E 17
D 18
	if (MMINOFF + sizeof (struct en_header) > m->m_off) {
E 18
I 18
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof (struct en_header) > m->m_off) {
E 18
E 15
D 30
		m = m_get(0);
E 30
I 30
D 78
		m = m_get(M_DONTWAIT);
E 78
I 78
D 92
		m = m_get(M_DONTWAIT, MT_HEADER);
E 92
I 92
		MGET(m, M_DONTWAIT, MT_HEADER);
E 92
E 78
E 30
		if (m == 0) {
D 55
			m_freem(m0);
			return (0);
E 55
I 55
			error = ENOBUFS;
			goto bad;
E 55
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof (struct en_header);
	} else {
D 18
		m = m0;
E 18
		m->m_off -= sizeof (struct en_header);
		m->m_len += sizeof (struct en_header);
	}
	en = mtod(m, struct en_header *);
D 89
	en->en_shost = ifp->if_host[0];
E 89
I 89
	/* add en_shost later */
E 89
	en->en_dhost = dest;
D 81
	en->en_type = type;
E 81
I 81
	en->en_type = htons((u_short)type);
E 81
I 15

I 96
#ifdef notdef
E 96
I 87
gotheader:
I 96
#endif
E 96
E 87
	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
E 15
	s = splimp();
I 40
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
D 53
		m_freem(m);
		splx(s);
		return (0);
E 53
I 53
D 55
		goto bad;
E 55
I 55
		error = ENOBUFS;
		goto qfull;
E 55
E 53
	}
E 40
I 18
D 19
printf("queueing %x\n", m);
asm("halt");
E 19
E 18
	IF_ENQUEUE(&ifp->if_snd, m);
D 23
	splx(s);
E 23
	if (en_softc[ifp->if_unit].es_oactive == 0)
		enstart(ifp->if_unit);
I 23
	splx(s);
E 23
I 15
D 55
	return (1);
I 53
bad:
	m_freem(m);
	splx(s);
E 55
	return (0);
I 55
qfull:
	m0 = m;
	splx(s);
bad:
	m_freem(m0);
	return (error);
I 83
}

/*
 * Process an ioctl request.
 */
enioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 93
	struct ifreq *ifr = (struct ifreq *)data;
E 93
I 93
	register struct en_softc *es = ((struct en_softc *)ifp);
	struct ifaddr *ifa = (struct ifaddr *) data;
E 93
	int s = splimp(), error = 0;
I 93
	struct endevice *enaddr;
E 93

	switch (cmd) {

	case SIOCSIFADDR:
D 93
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		ensetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, RTF_UP);
		else
E 93
I 93
		enaddr = (struct endevice *)eninfo[ifp->if_unit]->ui_addr;
		es->es_host = (~enaddr->en_addr) & 0xff;
		/*
		 * Attempt to check agreement of protocol address
		 * and board address.
		 */
		switch (ifa->ifa_addr.sa_family) {
		case AF_INET:
			if (in_lnaof(IA_SIN(ifa)->sin_addr) != es->es_host)
				return (EADDRNOTAVAIL);
			break;
I 99
#ifdef NS
		case AF_NS:
			if (IA_SNS(ifa)->sns_addr.x_host.c_host[5]
							!= es->es_host)
				return (EADDRNOTAVAIL);
			es->es_nsactive = 1;
			break;
#endif
E 99
		}
		ifp->if_flags |= IFF_UP;
		if ((ifp->if_flags & IFF_RUNNING) == 0)
E 93
			eninit(ifp->if_unit);
		break;

	default:
		error = EINVAL;
I 96
		break;
E 96
	}
	splx(s);
	return (error);
}

D 93
ensetaddr(ifp, sin)
	register struct ifnet *ifp;
	register struct sockaddr_in *sin;
{
	struct endevice *enaddr;

I 89
	/* set address once for in_netof, so subnets will be recognized */
	ifp->if_addr = *(struct sockaddr *)sin;
E 89
	ifp->if_net = in_netof(sin->sin_addr);
	enaddr = (struct endevice *)eninfo[ifp->if_unit]->ui_addr;
D 89
	ifp->if_host[0] = (~enaddr->en_addr) & 0xff;
E 89
I 89
	((struct en_softc *) ifp)->es_host = (~enaddr->en_addr) & 0xff;
E 89
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
D 89
	sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
E 89
I 89
	sin->sin_addr = if_makeaddr(ifp->if_net,
	    ((struct en_softc *)ifp)->es_host);
E 89
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags |= IFF_BROADCAST;
E 83
E 55
E 53
E 15
E 14
}
I 86

E 93
#ifdef ENF_SWABIPS
/*
 * Swab bytes
 * Jeffrey Mogul, Stanford
 */
enswab(from, to, n)
D 93
	register caddr_t *from, *to;
E 93
I 93
	register unsigned char *from, *to;
E 93
	register int n;
{
	register unsigned long temp;
I 93

	if ((n <= 0) || (n > 0xFFFF)) {
		printf("enswab: bad len %d\n", n);
		return;
	}
E 93
	
	n >>= 1; n++;
D 93
#define	STEP	temp = *from++,*to++ = *from++,*to++ = temp
E 93
I 93
#define	STEP	{temp = *from++;*to++ = *from++;*to++ = temp;}
E 93
	/* round to multiple of 8 */
	while ((--n) & 07)
		STEP;
	n >>= 3;
	while (--n >= 0) {
		STEP; STEP; STEP; STEP;
		STEP; STEP; STEP; STEP;
	}
}
I 97
#endif
E 97
#endif
E 86
I 47
D 68

#if NIMP == 0 && NEN > 0
/*
 * Logical host interface driver.
 * Allows host to appear as an ARPAnet
 * logical host.  Must also have routing
 * table entry set up to forward packets
 * to appropriate gateway on localnet.
 */

struct	ifnet enlhif;
D 61
int	enlhoutput();
E 61
I 61
int	looutput();
E 61

/*
 * Called by localnet interface to allow logical
D 61
 * host interface to "attach".  Nothing should ever
 * be sent locally to this interface, it's purpose
E 61
I 61
 * host interface to "attach", it's purpose
E 61
 * is simply to establish the host's arpanet address.
 */
D 61
enlhinit(addr)
E 61
I 61
enlhinit(esifp, addr)
	struct ifnet *esifp;
E 61
	int addr;
{
	register struct ifnet *ifp = &enlhif;
D 66
	register struct sockaddr_in *sin;
E 66
I 66
	struct sockaddr_in *sin;
E 66

COUNT(ENLHINIT);
	ifp->if_name = "lh";
	ifp->if_mtu = ENMTU;
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = addr;
I 66
	sin->sin_addr.s_lh = esifp->if_host[0];
E 66
	ifp->if_net = sin->sin_addr.s_net;
D 61
	ifp->if_flags = IFF_UP;
	ifp->if_output = enlhoutput;	/* should never be used */
E 61
I 61
	ifp->if_flags = IFF_UP|IFF_POINTOPOINT;
D 66
	ifp->if_dstaddr = esifp->if_addr;
E 66
I 66
	ifp->if_dstaddr = ifp->if_addr;
E 66
	ifp->if_output = looutput;
E 61
	if_attach(ifp);
D 61
}

enlhoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
COUNT(ENLHOUTPUT);
	ifp->if_oerrors++;
	m_freem(m0);
	return (0);
E 61
I 61
D 62
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_DIRECT);
E 62
I 62
D 67
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_DIRECT|RTF_HOST);
E 67
I 67
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_HOST);
E 67
E 62
E 61
}
#endif
E 68
E 47
D 14
#endif IMPDEBUG
E 14
E 1
