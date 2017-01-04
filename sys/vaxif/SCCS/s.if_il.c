h37933
s 00013/00002/00773
d D 7.3 88/08/04 15:25:45 bostic 43 42
c add Berkeley specific copyright
e
s 00008/00000/00767
d D 7.2 86/08/07 15:10:23 sklower 42 41
c watch for physical address reverting.
e
s 00001/00001/00766
d D 7.1 86/06/05 17:08:54 mckusick 41 40
c 4.3BSD release version
e
s 00004/00007/00763
d D 6.14 86/02/13 18:04:02 karels 40 39
c print module and software rev if ildebug
e
s 00031/00029/00739
d D 6.13 86/02/12 15:29:17 sklower 39 38
c Reprogramming physaddr now works.
e
s 00079/00030/00689
d D 6.12 86/01/24 18:36:16 karels 38 37
c rm bbnnet; combine common code in ilwait; use per-host trailer option from ARP;
c (untested) setaddr routine (for sklower)
e
s 00047/00016/00672
d D 6.11 85/11/08 19:17:20 karels 37 36
c ifconfig down resets interface, ifconfig up reinitializes;
c return error when attempting to send to down interface
e
s 00002/00000/00686
d D 6.10 85/10/24 10:07:26 bloom 36 35
c add "#if N?? > 0" 
e
s 00008/00002/00678
d D 6.9 85/09/16 22:21:08 karels 35 34
c pass ifp to if_{r,}ubaget, shuffle it up if receiving trailer
e
s 00040/00001/00640
d D 6.8 85/06/19 09:06:20 sklower 34 33
c check in for 4.3 beta -- known problems with 2nd xns interfaces.
e
s 00002/00000/00639
d D 6.7 85/05/04 22:54:39 bloom 33 32
c ifdef PUP include files
e
s 00033/00044/00606
d D 6.6 85/05/01 09:09:10 karels 32 31
c move interface addresses into protocols; remove struct ether_addr again
e
s 00012/00012/00638
d D 6.5 84/08/29 20:43:55 bloom 31 30
c change ot includes.  no more ../h
e
s 00006/00009/00644
d D 6.4 84/03/22 15:09:26 karels 30 29
c new address resolution protocol; struct ether_addr
e
s 00005/00004/00648
d D 6.3 84/01/02 13:50:37 leres 29 28
c In ilrint(), raise to spl imp while fooling with mbuf queue
e
s 00003/00003/00649
d D 6.2 83/09/24 23:29:15 karels 28 27
c don't start watchdog until uba alloc'ed
e
s 00000/00000/00652
d D 6.1 83/07/29 07:38:10 sam 27 26
c 4.2 distribution
e
s 00001/00001/00651
d D 4.25 83/07/19 00:38:30 sam 26 25
c how did these ever work before?
e
s 00001/00001/00651
d D 4.24 83/06/13 22:46:41 sam 25 24
c lint
e
s 00015/00008/00637
d D 4.23 83/06/13 00:00:19 sam 24 23
c someday I'll get all this correct (sigh)
e
s 00001/00001/00644
d D 4.22 83/06/12 23:33:18 sam 23 22
c ioctls
e
s 00049/00014/00596
d D 4.21 83/06/12 23:13:38 sam 22 21
c ioctls and trailers
e
s 00005/00011/00605
d D 4.20 83/05/27 13:50:43 sam 21 20
c lint
e
s 00005/00004/00611
d D 4.19 83/05/18 01:18:32 sam 20 18
c must set board off-line before setting on-line (lepreau@utah-cs)
e
s 00005/00003/00612
d R 4.19 83/05/18 01:14:53 sam 19 18
c must make board go offline after ubareset (lepreauh@utah-cs)
e
s 00046/00029/00569
d D 4.18 83/03/15 18:21:26 sam 18 17
c ARP ARP
e
s 00002/00001/00596
d D 4.17 82/12/17 12:14:02 sam 17 16
c sun merge
e
s 00036/00036/00561
d D 4.16 82/12/16 15:40:27 sam 16 15
c fix byte swapping problems in header
e
s 00001/00001/00596
d D 4.15 82/12/14 17:21:48 sam 15 14
c typed mbufs
e
s 00030/00008/00567
d D 4.14 82/11/13 23:05:04 sam 14 13
c merge 4.1b with 4.1c
e
s 00001/00001/00574
d D 4.13 82/10/31 15:05:28 root 13 12
c ubareset routines now just if_reset!
e
s 00013/00010/00562
d D 4.12 82/10/10 17:02:22 root 12 11
c put vax headers in their place
e
s 00007/00007/00565
d D 4.11 82/10/09 06:10:34 wnj 11 10
c fix includes
e
s 00005/00004/00567
d D 4.10 82/06/24 21:31:42 sam 10 9
c must copy csr or lose status if RCVPENDING
e
s 00136/00091/00435
d D 4.9 82/06/23 21:08:47 sam 9 8
c remove csr crap; add stat collection through watchdog routine
e
s 00000/00007/00526
d D 4.8 82/06/20 00:52:36 sam 8 7
c purge COUNT stuff now that we can use gprof
e
s 00089/00099/00444
d D 4.7 82/06/18 15:12:58 sam 7 6
c eliminate cvtlw inst's on il_csr and other misc
e
s 00001/00048/00542
d D 4.6 82/06/13 23:00:38 sam 6 5
c add class a/b/c net #'s and purge logical host kludge code
e
s 00002/00002/00588
d D 4.5 82/06/12 23:18:29 wnj 5 4
c now the routing code might wokr
e
s 00002/00001/00588
d D 4.4 82/05/27 12:43:45 sam 4 3
c try one more time to do it right
e
s 00001/00001/00588
d D 4.3 82/05/25 16:14:27 sam 3 2
c logical host route needs RTF_HOST
e
s 00008/00016/00581
d D 4.2 82/05/24 17:16:12 wnj 2 1
c pt-pt, loopback can transmit, fixed en bug that bugged sam
e
s 00597/00000/00000
d D 4.1 82/05/21 15:54:55 feldman 1 0
c date and time created 82/05/21 15:54:55 by feldman
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
D 41
 * Copyright (c) 1982 Regents of the University of California.
E 41
I 41
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 41
D 43
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 43
I 43
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
E 43
 *
 *	%W% (Berkeley) %G%
 */
E 34

#include "il.h"
I 36
#if NIL > 0
E 36
D 6
#include "imp.h"
#include "loop.h"
E 6

/*
 * Interlan Ethernet Communications Controller interface
 */
I 17
#include "../machine/pte.h"

E 17
D 7

E 7
D 31
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 17
#include "../h/pte.h"
E 17
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
D 12
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/ilreg.h"
#include "../h/cpu.h"
#include "../h/mtpr.h"
E 12
#include "../h/vmmac.h"
I 12
D 22
#include <errno.h>
E 22
I 22
#include "../h/ioctl.h"
#include "../h/errno.h"
E 31
I 31
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"
I 42
#include "syslog.h"
E 42
E 31
E 22

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
I 34

I 35
D 38
#ifdef	BBNNET
#define	INET
#endif
E 38
E 35
#ifdef INET
E 34
E 12
D 11
#include "../net/in.h"
#include "../net/in_systm.h"
E 11
I 11
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 32
#include "../netinet/in_var.h"
E 32
E 11
D 12
#include "../net/if.h"
D 11
#include "../net/if_il.h"
#include "../net/if_uba.h"
#include "../net/ip.h"
#include "../net/ip_var.h"
#include "../net/pup.h"
E 11
I 11
#include "../vaxif/if_il.h"
#include "../vaxif/if_uba.h"
E 12
#include "../netinet/ip.h"
D 35
#include "../netinet/ip_var.h"
E 35
I 18
#include "../netinet/if_ether.h"
I 34
#endif

E 34
I 33
D 37
#ifdef PUP
E 33
E 18
#include "../netpup/pup.h"
I 33
#endif
E 33
E 11
D 12
#include "../net/route.h"
#include <errno.h>
E 12
I 12

E 37
I 34
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif

E 34
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 16
#include "../vaxif/if_ilreg.h"
E 16
I 16
D 18
#include "../vaxif/if_ether.h"
E 18
E 16
D 31
#include "../vaxif/if_il.h"
I 16
#include "../vaxif/if_ilreg.h"
E 16
#include "../vaxif/if_uba.h"
E 31
I 31
#include "if_il.h"
#include "if_ilreg.h"
#include "if_uba.h"
E 31
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 12

D 16
#define	ILMTU	1500
I 14
#define	ILMIN	(60-14)
E 14

E 16
int	ilprobe(), ilattach(), ilrint(), ilcint();
struct	uba_device *ilinfo[NIL];
u_short ilstd[] = { 0 };
struct	uba_driver ildriver =
	{ ilprobe, 0, ilattach, 0, ilstd, "il", ilinfo };
D 7
u_char	il_ectop[3] = { 0x02, 0x60, 0x8c };
E 7
#define	ILUNIT(x)	minor(x)
D 7

E 7
D 9
int	ilinit(),iloutput(),ilreset();
E 9
I 9
D 22
int	ilinit(),iloutput(),ilreset(),ilwatch();
E 22
I 22
int	ilinit(),iloutput(),ilioctl(),ilreset(),ilwatch();
I 40
int	ildebug = 0;
E 40
E 22
E 9

I 7
D 18
u_char	il_ectop[3] = { 0x02, 0x60, 0x8c };
u_char	ilbroadcastaddr[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

E 18
E 7
/*
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * is_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct	il_softc {
D 18
	struct	ifnet is_if;		/* network-visible interface */
E 18
I 18
	struct	arpcom is_ac;		/* Ethernet common part */
#define	is_if	is_ac.ac_if		/* network-visible interface */
#define	is_addr	is_ac.ac_enaddr		/* hardware Ethernet address */
E 18
	struct	ifuba is_ifuba;		/* UNIBUS resources */
D 9
	short	is_oactive;		/* is output active? */
	short	is_startrcv;		/* hang receive next chance */
	u_char	is_enaddr[6];		/* board's ethernet address */
E 9
I 9
	int	is_flags;
#define	ILF_OACTIVE	0x1		/* output is active */
#define	ILF_RCVPENDING	0x2		/* start rcv in ilcint */
#define	ILF_STATPENDING	0x4		/* stat cmd pending */
I 37
#define	ILF_RUNNING	0x8		/* board is running */
I 38
#define	ILF_SETADDR	0x10		/* physical address is changed */
E 38
E 37
	short	is_lastcmd;		/* can't read csr, so must save it */
	short	is_scaninterval;	/* interval of stat collection */
#define	ILWATCHINTERVAL	60		/* once every 60 seconds */
	struct	il_stats is_stats;	/* holds on-board statistics */
	struct	il_stats is_sum;	/* summation over time */
	int	is_ubaddr;		/* mapping registers of is_stats */
E 9
} il_softc[NIL];

D 9
/*
 * Do an OFFLINE command.  This will cause an interrupt for the
 * autoconfigure stuff.
 */
E 9
ilprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct ildevice *addr = (struct ildevice *)reg;
	register i;

D 8
COUNT(ILPROBE);
E 8
#ifdef lint
	br = 0; cvec = br; br = cvec;
D 9
	ilrint(0); ilcint(0);
E 9
I 9
D 14
	ilrint(0); ilcint(0); ilwatch(0);
E 14
I 14
	i = 0; ilrint(i); ilcint(i); ilwatch(i);
E 14
E 9
#endif

	addr->il_csr = ILC_OFFLINE|IL_CIE;
	DELAY(100000);
D 9
	i = addr->il_csr;		/* Clear CDONE */
E 9
I 9
	i = addr->il_csr;		/* clear CDONE */
E 9
	if (cvec > 0 && cvec != 0x200)
		cvec -= 4;
	return (1);
}

D 9
struct il_stat ilbuf;
E 9
/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.  A STATUS command is done to get the ethernet
 * address and other interesting data.
 */
ilattach(ui)
	struct uba_device *ui;
{
	register struct il_softc *is = &il_softc[ui->ui_unit];
D 7
	register struct sockaddr_in *sin;
E 7
I 7
	register struct ifnet *ifp = &is->is_if;
E 7
	register struct ildevice *addr = (struct ildevice *)ui->ui_addr;
D 7
	register int i;
	int s;
	int ubaddr;
E 7
I 7
D 9
	register short csr;
E 9
D 32
	struct sockaddr_in *sin;
E 32
D 9
	int i, s, ubaddr;
E 9
E 7
D 8
COUNT(ILATTACH);
E 8

D 7
	is->is_if.if_unit = ui->ui_unit;
	is->is_if.if_name = "il";
	is->is_if.if_mtu = ILMTU;
D 6
	is->is_if.if_net = ui->ui_flags & 0xff;
E 6
I 6
	is->is_if.if_net = ui->ui_flags;
E 7
I 7
	ifp->if_unit = ui->ui_unit;
	ifp->if_name = "il";
D 16
	ifp->if_mtu = ILMTU;
E 16
I 16
	ifp->if_mtu = ETHERMTU;
I 32
	ifp->if_flags = IFF_BROADCAST;
E 32
E 16
D 18
	ifp->if_net = ui->ui_flags;
E 18
E 7
E 6

	/*
D 9
	 * Reset the board
E 9
I 9
	 * Reset the board and map the statistics
	 * buffer onto the Unibus.
E 9
	 */
D 9
	s = splimp();
D 7
	addr->il_csr = ((ubaddr>>2)&0xc000)|ILC_RESET;
	while (!(addr->il_csr & IL_CDONE))
		/* Busy wait */;
	if (addr->il_csr & IL_STATUS)
		printf("il%d: %s\n", ui->ui_unit,
		    ildiag[addr->il_csr & IL_STATUS]);
E 7
I 7
	csr = ((ubaddr>>2)&0xc000)|ILC_RESET;
	addr->il_csr = csr;
	do
		csr = addr->il_csr;
	while ((csr&IL_CDONE) == 0);
	if (csr &= IL_STATUS)
		printf("il%d: %s\n", ui->ui_unit, ildiag[csr]);
E 7
	splx(s);
E 9
I 9
	addr->il_csr = ILC_RESET;
D 38
	while ((addr->il_csr&IL_CDONE) == 0)
		;
	if (addr->il_csr&IL_STATUS)
		printf("il%d: reset failed, csr=%b\n", ui->ui_unit,
			addr->il_csr, IL_BITS);
E 38
I 38
	(void)ilwait(ui, "reset");
E 38
E 9
	
D 9
	/*
	 * Map the status buffer to the Unibus, do the status command,
	 * and unmap the buffer.
	 */ 
	ubaddr = uballoc(ui->ui_ubanum, &ilbuf, sizeof(ilbuf), 0);
	s = splimp();
	addr->il_bar = ubaddr & 0xffff;
	addr->il_bcr = sizeof(ilbuf);
D 7
	addr->il_csr = ((ubaddr>>2)&0xc000)|ILC_STAT;
	while (!(addr->il_csr & IL_CDONE))
		/* Busy wait */;
	if (addr->il_csr & IL_STATUS)
		printf("il%d: %s\n", ui->ui_unit,
		    ilerrs[addr->il_csr & IL_STATUS]);
E 7
I 7
	csr = ((ubaddr>>2)&0xc000)|ILC_STAT;
	addr->il_csr = csr;
	do
		csr = addr->il_csr;
	while ((csr&IL_CDONE) == 0);
	if (csr &= IL_STATUS)
		printf("il%d: %s\n", ui->ui_unit, ilerrs[csr]);
E 7
	splx(s);
	ubarelse(ui->ui_ubanum, &ubaddr);
	/*
	 * Fill in the Ethernet address from the status buffer
	 */
D 7
	for (i=0; i<6; i++)
		is->is_enaddr[i] = ilbuf.ils_addr[i];
E 7
I 7
	bcopy(ilbuf.ils_addr, is->is_enaddr, 6);
E 9
I 9
D 14
	is->is_ubaddr = uballoc(ui->ui_ubanum, &is->is_stats,
E 14
I 14
	is->is_ubaddr = uballoc(ui->ui_ubanum, (caddr_t)&is->is_stats,
E 14
D 22
		sizeof (struct il_stats), 0);
E 22
I 22
	    sizeof (struct il_stats), 0);
E 22
	addr->il_bar = is->is_ubaddr & 0xffff;
	addr->il_bcr = sizeof (struct il_stats);
	addr->il_csr = ((is->is_ubaddr >> 2) & IL_EUA)|ILC_STAT;
D 38
	while ((addr->il_csr&IL_CDONE) == 0)
		;
	if (addr->il_csr&IL_STATUS)
		printf("il%d: status failed, csr=%b\n", ui->ui_unit,
			addr->il_csr, IL_BITS);
E 38
I 38
	(void)ilwait(ui, "status");
E 38
	ubarelse(ui->ui_ubanum, &is->is_ubaddr);
I 18
D 40
#ifdef notdef
E 18
E 9
E 7
D 38
	printf("il%d: addr=%x:%x:%x:%x:%x:%x module=%s firmware=%s\n",
		ui->ui_unit,
D 9
		is->is_enaddr[0]&0xff, is->is_enaddr[1]&0xff,
		is->is_enaddr[2]&0xff, is->is_enaddr[3]&0xff,
		is->is_enaddr[4]&0xff, is->is_enaddr[5]&0xff,
		ilbuf.ils_module, ilbuf.ils_firmware);
D 7
	is->is_if.if_host[0] = ((is->is_enaddr[3]&0xff)<<16) | 0x800000 |
E 7
I 7
	ifp->if_host[0] = ((is->is_enaddr[3]&0xff)<<16) | 0x800000 |
E 7
	    ((is->is_enaddr[4]&0xff)<<8) | (is->is_enaddr[5]&0xff);
E 9
I 9
		is->is_stats.ils_addr[0]&0xff, is->is_stats.ils_addr[1]&0xff,
		is->is_stats.ils_addr[2]&0xff, is->is_stats.ils_addr[3]&0xff,
		is->is_stats.ils_addr[4]&0xff, is->is_stats.ils_addr[5]&0xff,
E 38
I 38
	printf("il%d: module=%s firmware=%s\n", ui->ui_unit,
E 38
		is->is_stats.ils_module, is->is_stats.ils_firmware);
D 18
	ifp->if_host[0] =
	    ((is->is_stats.ils_addr[3]&0xff)<<16) | 0x800000 |
	    ((is->is_stats.ils_addr[4]&0xff)<<8) |
	    (is->is_stats.ils_addr[5]&0xff);
E 18
I 18
#endif
E 40
I 40
	if (ildebug)
		printf("il%d: module=%s firmware=%s\n", ui->ui_unit,
			is->is_stats.ils_module, is->is_stats.ils_firmware);
E 40
D 21
	bcopy(is->is_stats.ils_addr, is->is_addr, sizeof (is->is_addr));
E 21
I 21
D 30
	bcopy((caddr_t)is->is_stats.ils_addr, (caddr_t)is->is_addr,
	    sizeof (is->is_addr));
E 30
I 30
D 32
	is->is_addr = is->is_stats.ils_addr;
E 30
E 21
E 18
E 9
D 7
	sin = (struct sockaddr_in *)&is->is_if.if_addr;
E 7
I 7
	sin = (struct sockaddr_in *)&ifp->if_addr;
E 7
	sin->sin_family = AF_INET;
E 32
I 32
 	bcopy((caddr_t)is->is_stats.ils_addr, (caddr_t)is->is_addr,
 	    sizeof (is->is_addr));
I 38
	printf("il%d: hardware address %s\n", ui->ui_unit,
		ether_sprintf(is->is_addr));
E 38
E 32
D 7
	sin->sin_addr = if_makeaddr(is->is_if.if_net, is->is_if.if_host[0]);
E 7
I 7
D 18
	sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
E 18
I 18
D 21
	if (ui->ui_flags) {
		int i = ((is->is_addr[3]&0xff)<<16) |
		    ((is->is_addr[4]&0xff)<<8) |
		    (is->is_addr[5]&0xff);
		sin->sin_addr = if_makeaddr(ui->ui_flags, i);
	} else
		sin->sin_addr = arpmyaddr();
E 18
E 7

E 21
I 21
D 30
	sin->sin_addr = arpmyaddr((struct arpcom *)0);
E 30
E 21
D 7
	sin = (struct sockaddr_in *)&is->is_if.if_broadaddr;
E 7
I 7
D 18
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
E 7
	sin->sin_family = AF_INET;
D 7
	sin->sin_addr = if_makeaddr(is->is_if.if_net, 0);
	is->is_if.if_flags = IFF_BROADCAST;
E 7
I 7
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags = IFF_BROADCAST;
E 7

E 18
D 7
	is->is_if.if_init = ilinit;
	is->is_if.if_output = iloutput;
	is->is_if.if_ubareset = ilreset;
E 7
I 7
	ifp->if_init = ilinit;
	ifp->if_output = iloutput;
I 22
	ifp->if_ioctl = ilioctl;
E 22
D 13
	ifp->if_ubareset = ilreset;
E 13
I 13
	ifp->if_reset = ilreset;
E 13
I 9
D 28
	ifp->if_watchdog = ilwatch;
	is->is_scaninterval = ILWATCHINTERVAL;
	ifp->if_timer = is->is_scaninterval;
E 28
E 9
E 7
	is->is_ifuba.ifu_flags = UBA_CANTWAIT;
D 7
	if_attach(&is->is_if);
E 7
I 7
D 40
#ifdef notdef
	is->is_ifuba.ifu_flags |= UBA_NEEDBDP;
#endif
E 40
	if_attach(ifp);
E 7
D 6
#if NIMP == 0
	if (ui->ui_flags &~ 0xff)
D 2
		illhinit((ui->ui_flags &~ 0xff) | 0x0a);
E 2
I 2
		illhinit(&is->is_if, (ui->ui_flags &~ 0xff) | 0x0a);
E 2
#endif
E 6
}

I 38
ilwait(ui, op)
	struct uba_device *ui;
	char *op;
{
	register struct ildevice *addr = (struct ildevice *)ui->ui_addr;

	while ((addr->il_csr&IL_CDONE) == 0)
		;
	if (addr->il_csr&IL_STATUS) {
		printf("il%d: %s failed, csr=%b\n", ui->ui_unit, op,
			addr->il_csr, IL_BITS);
		return (-1);
	}
	return (0);
}

E 38
/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
ilreset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;
D 8
COUNT(ILRESET);
E 8

	if (unit >= NIL || (ui = ilinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
	printf(" il%d", unit);
I 37
	il_softc[unit].is_if.if_flags &= ~IFF_RUNNING;
	il_softc[unit].is_flags &= ~ILF_RUNNING;
E 37
	ilinit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
ilinit(unit)
	int unit;
{
	register struct il_softc *is = &il_softc[unit];
	register struct uba_device *ui = ilinfo[unit];
	register struct ildevice *addr;
D 7
	register i;
	int s;
E 7
I 7
D 9
	int i, s;
	short csr;
E 9
I 9
D 22
	int s;
E 22
I 18
	register struct ifnet *ifp = &is->is_if;
D 22
	register struct sockaddr_in *sin, *sinb;
E 22
I 22
D 32
	register struct sockaddr_in *sin;
E 32
	int s;
E 22
E 18
E 9
E 7

I 18
D 32
	sin = (struct sockaddr_in *)&ifp->if_addr;
D 22
	if (sin->sin_addr.s_addr == 0)	/* if address still unknown */
E 22
I 22
	if (sin->sin_addr.s_addr == 0)		/* address still unknown */
E 32
I 32
	/* not yet, if address still unknown */
	if (ifp->if_addrlist == (struct ifaddr *)0)
E 32
E 22
		return;
D 22
	ifp->if_net = in_netof(sin->sin_addr);
	ifp->if_host[0] = in_lnaof(sin->sin_addr);
	sinb = (struct sockaddr_in *)&ifp->if_broadaddr;
	sinb->sin_family = AF_INET;
	sinb->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags = IFF_BROADCAST;
E 22
D 37

I 22
	if (ifp->if_flags & IFF_RUNNING)
E 37
I 37
	if (is->is_flags & ILF_RUNNING)
E 37
D 32
		goto justarp;
E 32
I 32
		return;
E 32
E 22
E 18
D 37
	if (if_ubainit(&is->is_ifuba, ui->ui_ubanum,
D 16
	    sizeof (struct il_rheader), (int)btoc(ILMTU)) == 0) { 
E 16
I 16
	    sizeof (struct il_rheader), (int)btoc(ETHERMTU)) == 0) { 
E 16
		printf("il%d: can't initialize\n", unit);
		is->is_if.if_flags &= ~IFF_UP;
		return;
E 37
I 37

	if ((ifp->if_flags & IFF_RUNNING) == 0) {
		if (if_ubainit(&is->is_ifuba, ui->ui_ubanum,
		    sizeof (struct il_rheader), (int)btoc(ETHERMTU)) == 0) { 
			printf("il%d: can't initialize\n", unit);
			is->is_if.if_flags &= ~IFF_UP;
			return;
		}
		is->is_ubaddr = uballoc(ui->ui_ubanum, (caddr_t)&is->is_stats,
		    sizeof (struct il_stats), 0);
E 37
	}
I 9
D 14
	is->is_ubaddr = uballoc(ui->ui_ubanum, &is->is_stats,
E 14
I 14
D 37
	is->is_ubaddr = uballoc(ui->ui_ubanum, (caddr_t)&is->is_stats,
E 14
D 22
		sizeof (struct il_stats), 0);
E 22
I 22
	    sizeof (struct il_stats), 0);
E 37
I 28
	ifp->if_watchdog = ilwatch;
	is->is_scaninterval = ILWATCHINTERVAL;
	ifp->if_timer = is->is_scaninterval;
E 28
E 22
E 9
	addr = (struct ildevice *)ui->ui_addr;

	/*
I 14
	 * Turn off source address insertion (it's faster this way),
D 20
	 * and set board online.
E 20
I 20
	 * and set board online.  Former doesn't work if board is
	 * already online (happens on ubareset), so we put it offline
	 * first.
E 20
	 */
	s = splimp();
D 20
	addr->il_csr = ILC_CISA;
E 20
I 20
D 37
	addr->il_csr = ILC_OFFLINE;
E 37
I 37
	addr->il_csr = ILC_RESET;
E 37
E 20
D 38
	while ((addr->il_csr & IL_CDONE) == 0)
		;
I 37
 	if (addr->il_csr & IL_STATUS) {
 		printf("il%d failed hardware diag 0x%X\n", unit,
 		   addr->il_csr & 0xffff);
E 38
I 38
	if (ilwait(ui, "hardware diag")) {
E 38
 		is->is_if.if_flags &= ~IFF_UP;
 		splx(s);
 		return;
 	}
E 37
D 20
	addr->il_csr = ILC_ONLINE;
E 20
I 20
	addr->il_csr = ILC_CISA;
E 20
	while ((addr->il_csr & IL_CDONE) == 0)
		;
	/*
I 39
	 * If we must reprogram this board's physical ethernet
	 * address (as for secondary XNS interfaces), we do so
	 * before putting it on line, and starting receive requests.
	 * If you try this on an older 1010 board, it will total
	 * wedge the board.
	 */
	if (is->is_flags & ILF_SETADDR) {
		bcopy((caddr_t)is->is_addr, (caddr_t)&is->is_stats,
							sizeof is->is_addr);
		addr->il_bar = is->is_ubaddr & 0xffff;
		addr->il_bcr = sizeof is->is_addr;
		addr->il_csr = ((is->is_ubaddr >> 2) & IL_EUA)|ILC_LDPA;
		if (ilwait(ui, "setaddr"))
			return;
		addr->il_bar = is->is_ubaddr & 0xffff;
		addr->il_bcr = sizeof (struct il_stats);
		addr->il_csr = ((is->is_ubaddr >> 2) & IL_EUA)|ILC_STAT;
		if (ilwait(ui, "verifying setaddr"))
			return;
		if (bcmp((caddr_t)is->is_stats.ils_addr, (caddr_t)is->is_addr,
						sizeof (is->is_addr)) != 0) {
			printf("il%d: setaddr didn't work\n", ui->ui_unit);
			return;
		}
	}
	/*
E 39
E 14
	 * Set board online.
	 * Hang receive buffer and start any pending
	 * writes by faking a transmit complete.
D 37
	 * Receive bcr is not a muliple of 4 so buffer
E 37
I 37
	 * Receive bcr is not a multiple of 8 so buffer
E 37
	 * chaining can't happen.
	 */
D 20
	s = splimp();
E 20
	addr->il_csr = ILC_ONLINE;
D 7
	while (!(addr->il_csr & IL_CDONE))
		/* Busy wait */;
E 7
I 7
	while ((addr->il_csr & IL_CDONE) == 0)
		;
E 7
	addr->il_bar = is->is_ifuba.ifu_r.ifrw_info & 0xffff;
D 16
	addr->il_bcr = sizeof(struct il_rheader) + ILMTU + 6;
E 16
I 16
	addr->il_bcr = sizeof(struct il_rheader) + ETHERMTU + 6;
E 16
D 7
	addr->il_csr = ((is->is_ifuba.ifu_r.ifrw_info>>2)&0xc000)|
			ILC_RCV|IL_RIE;
	while (!(addr->il_csr & IL_CDONE))
		/* Busy wait */;
E 7
I 7
D 9
	csr = ((is->is_ifuba.ifu_r.ifrw_info>>2)&0xc000)|ILC_RCV|IL_RIE;
	addr->il_csr = csr;
E 9
I 9
	addr->il_csr =
D 22
		((is->is_ifuba.ifu_r.ifrw_info >> 2) & IL_EUA)|ILC_RCV|IL_RIE;
E 22
I 22
	    ((is->is_ifuba.ifu_r.ifrw_info >> 2) & IL_EUA)|ILC_RCV|IL_RIE;
E 22
E 9
	while ((addr->il_csr & IL_CDONE) == 0)
		;
E 7
D 9
	is->is_startrcv = 0;
	is->is_oactive = 1;
E 9
I 9
	is->is_flags = ILF_OACTIVE;
E 9
D 23
	is->is_if.if_flags |= IFF_UP;
E 23
I 23
D 32
	is->is_if.if_flags |= IFF_UP|IFF_RUNNING;
E 32
I 32
	is->is_if.if_flags |= IFF_RUNNING;
I 37
	is->is_flags |= ILF_RUNNING;
I 38
D 39
	if (is->is_flags & ILF_SETADDR)
		(void) il_setaddr(is->is_addr, is->is_if.if_unit);
E 39
E 38
E 37
E 32
E 23
I 9
	is->is_lastcmd = 0;
E 9
	ilcint(unit);
	splx(s);
I 22
D 32
justarp:
E 22
D 5
	if_rtinit(&is->is_if, RTF_DIRECT|RTF_UP);
E 5
I 5
	if_rtinit(&is->is_if, RTF_UP);
I 18
D 30
	arpattach(&is->is_ac);
E 30
	arpwhohas(&is->is_ac, &sin->sin_addr);
E 32
E 18
E 5
}

/*
 * Start output on interface.
 * Get another datagram to send off of the interface queue,
 * and map it to the interface before starting the output.
 */
ilstart(dev)
	dev_t dev;
{
D 7
        int unit = ILUNIT(dev);
E 7
I 7
D 14
        int unit = ILUNIT(dev), dest, len;
E 14
I 14
        int unit = ILUNIT(dev), len;
E 14
E 7
	struct uba_device *ui = ilinfo[unit];
	register struct il_softc *is = &il_softc[unit];
	register struct ildevice *addr;
D 7
	register len;
E 7
	struct mbuf *m;
D 7
	int dest;
E 7
I 7
	short csr;
E 7
D 8
COUNT(ILSTART);
E 8

D 7
	/*
	 * Dequeue another request and copy it into the buffer.
	 * If no more requests, just return.
	 */
E 7
	IF_DEQUEUE(&is->is_if.if_snd, m);
D 9
	if (m == 0)
		return;
E 9
I 9
	addr = (struct ildevice *)ui->ui_addr;
	if (m == 0) {
		if ((is->is_flags & ILF_STATPENDING) == 0)
			return;
D 14
		addr->il_bar = is->is_ubaddr & 0xfff;
E 14
I 14
		addr->il_bar = is->is_ubaddr & 0xffff;
E 14
		addr->il_bcr = sizeof (struct il_stats);
		csr = ((is->is_ubaddr >> 2) & IL_EUA)|ILC_STAT|IL_RIE|IL_CIE;
		is->is_flags &= ~ILF_STATPENDING;
		goto startcmd;
	}
E 9
	len = if_wubaput(&is->is_ifuba, m);
I 14
	/*
	 * Ensure minimum packet length.
	 * This makes the safe assumtion that there are no virtual holes
	 * after the data.
	 * For security, it might be wise to zero out the added bytes,
	 * but we're mainly interested in speed at the moment.
	 */
D 16
	if (len - sizeof(struct il_xheader) < ILMIN)
		len = ILMIN + sizeof(struct il_xheader);
E 16
I 16
	if (len - sizeof(struct ether_header) < ETHERMIN)
		len = ETHERMIN + sizeof(struct ether_header);
E 16
E 14
D 7

	/*
	 * Flush BDP, then start the output.
	 */
E 7
	if (is->is_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(is->is_ifuba.ifu_uba, is->is_ifuba.ifu_w.ifrw_bdp);
D 9
	addr = (struct ildevice *)ui->ui_addr;
E 9
	addr->il_bar = is->is_ifuba.ifu_w.ifrw_info & 0xffff;
	addr->il_bcr = len;
D 7
	addr->il_csr = ((is->is_ifuba.ifu_w.ifrw_info>>2)&0xc000)|
			ILC_XMIT|IL_CIE|IL_RIE;
E 7
I 7
D 9
	csr = ((is->is_ifuba.ifu_w.ifrw_info>>2)&0xc000)|ILC_XMIT|IL_CIE|IL_RIE;
E 9
I 9
	csr =
	  ((is->is_ifuba.ifu_w.ifrw_info >> 2) & IL_EUA)|ILC_XMIT|IL_CIE|IL_RIE;

startcmd:
	is->is_lastcmd = csr & IL_CMD;
E 9
	addr->il_csr = csr;
E 7
D 9
	is->is_oactive = 1;
E 9
I 9
	is->is_flags |= ILF_OACTIVE;
E 9
}

/*
 * Command done interrupt.
D 9
 * This should only happen after a transmit command,
 * so it is equivalent to a transmit interrupt.
 * Start another output if more data to send.
E 9
 */
ilcint(unit)
	int unit;
{
D 7
	register struct uba_device *ui = ilinfo[unit];
E 7
	register struct il_softc *is = &il_softc[unit];
I 7
	struct uba_device *ui = ilinfo[unit];
E 7
	register struct ildevice *addr = (struct ildevice *)ui->ui_addr;
D 7
	register int err;
E 7
I 7
D 9
	short csr;
E 9
I 9
D 10
	short status;
E 10
I 10
	short csr;
E 10
E 9
E 7
D 8
COUNT(ILCINT);
E 8

I 7
D 9
	csr = addr->il_csr;
E 7
	if (is->is_oactive == 0) {
E 9
I 9
	if ((is->is_flags & ILF_OACTIVE) == 0) {
E 9
D 7
		printf("il%d: strange xmit interrupt!\n", unit);
E 7
I 7
		printf("il%d: stray xmit interrupt, csr=%b\n", unit,
D 9
			csr, IL_BITS);
E 9
I 9
			addr->il_csr, IL_BITS);
E 9
E 7
		return;
	}
D 9
	is->is_if.if_opackets++;
	is->is_oactive = 0;
D 7
	if (err = (addr->il_csr & IL_STATUS)){
E 7
I 7
	if (csr &= IL_STATUS) {
E 7
		is->is_if.if_oerrors++;
D 7
		printf("il%d: output error %d\n", unit, err);
E 7
I 7
		printf("il%d: output error %d\n", unit, csr);
E 7
	}
E 9
I 7

I 10
	csr = addr->il_csr;
E 10
E 7
	/*
D 9
	 * Hang receive buffer if it couldn't be done earlier (in ilrint).
E 9
I 9
	 * Hang receive buffer if it couldn't
	 * be done earlier (in ilrint).
E 9
	 */
D 9
	if (is->is_startrcv) {
E 9
I 9
	if (is->is_flags & ILF_RCVPENDING) {
I 37
		int s;

E 37
E 9
		addr->il_bar = is->is_ifuba.ifu_r.ifrw_info & 0xffff;
D 16
		addr->il_bcr = sizeof(struct il_rheader) + ILMTU + 6;
E 16
I 16
		addr->il_bcr = sizeof(struct il_rheader) + ETHERMTU + 6;
E 16
D 7
		addr->il_csr = ((is->is_ifuba.ifu_r.ifrw_info>>2)&0xc000)|
				ILC_RCV|IL_RIE;
		while (!(addr->il_csr & IL_CDONE))
			/* Busy wait */;
E 7
I 7
D 9
		csr = ((is->is_ifuba.ifu_r.ifrw_info>>2)&0xc000)|ILC_RCV|IL_RIE;
		addr->il_csr = csr;
E 9
I 9
		addr->il_csr =
		  ((is->is_ifuba.ifu_r.ifrw_info >> 2) & IL_EUA)|ILC_RCV|IL_RIE;
I 37
		s = splhigh();
E 37
E 9
		while ((addr->il_csr & IL_CDONE) == 0)
			;
I 37
		splx(s);
E 37
E 7
D 9
		is->is_startrcv = 0;
E 9
I 9
		is->is_flags &= ~ILF_RCVPENDING;
E 9
	}
I 9
	is->is_flags &= ~ILF_OACTIVE;
D 10
	status = addr->il_csr & IL_STATUS;
E 10
I 10
	csr &= IL_STATUS;
E 10
	switch (is->is_lastcmd) {

	case ILC_XMIT:
		is->is_if.if_opackets++;
D 10
		if (status > ILERR_RETRIES)
E 10
I 10
		if (csr > ILERR_RETRIES)
E 10
			is->is_if.if_oerrors++;
		break;

	case ILC_STAT:
D 10
		if (status == ILERR_SUCCESS)
E 10
I 10
		if (csr == ILERR_SUCCESS)
E 10
			iltotal(is);
		break;
	}
E 9
	if (is->is_ifuba.ifu_xtofree) {
		m_freem(is->is_ifuba.ifu_xtofree);
		is->is_ifuba.ifu_xtofree = 0;
	}
D 7
	if (is->is_if.if_snd.ifq_head == 0) {
		return;
	}
	ilstart(unit);
E 7
I 7
D 9
	if (is->is_if.if_snd.ifq_head)
		ilstart(unit);
E 9
I 9
	ilstart(unit);
E 9
E 7
}

/*
 * Ethernet interface receiver interrupt.
 * If input error just drop packet.
 * Otherwise purge input buffered data path and examine 
 * packet to determine type.  If can't determine length
 * from type, then have to drop packet.  Othewise decapsulate
 * packet based on type and pass to type specific higher-level
 * input routine.
 */
ilrint(unit)
	int unit;
{
	register struct il_softc *is = &il_softc[unit];
	struct ildevice *addr = (struct ildevice *)ilinfo[unit]->ui_addr;
	register struct il_rheader *il;
    	struct mbuf *m;
D 29
	int len, off, resid;
E 29
I 29
	int len, off, resid, s;
E 29
	register struct ifqueue *inq;
I 7
D 9
	short csr;
E 9
E 7

D 8
COUNT(ILRINT);
E 8
	is->is_if.if_ipackets++;
	if (is->is_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(is->is_ifuba.ifu_uba, is->is_ifuba.ifu_r.ifrw_bdp);
	il = (struct il_rheader *)(is->is_ifuba.ifu_r.ifrw_addr);
	len = il->ilr_length - sizeof(struct il_rheader);
D 7
	if (il->ilr_status&0x3 || len < 46 || len > ILMTU) {
E 7
I 7
D 9
	if ((il->ilr_status&0x3) || len < 46 || len > ILMTU) {
E 9
I 9
D 16
	if ((il->ilr_status&(ILFSTAT_A|ILFSTAT_C)) || len < 46 || len > ILMTU) {
E 16
I 16
	if ((il->ilr_status&(ILFSTAT_A|ILFSTAT_C)) || len < 46 ||
	    len > ETHERMTU) {
E 16
E 9
E 7
		is->is_if.if_ierrors++;
#ifdef notdef
		if (is->is_if.if_ierrors % 100 == 0)
			printf("il%d: += 100 input errors\n", unit);
#endif
D 9
		printf("il%d: input error (status=%x, len=%d)\n", unit,
		    il->ilr_status, len);
E 9
		goto setup;
	}

	/*
D 32
	 * Deal with trailer protocol: if type is PUP trailer
E 32
I 32
	 * Deal with trailer protocol: if type is trailer type
E 32
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
I 16
	il->ilr_type = ntohs((u_short)il->ilr_type);
E 16
#define	ildataaddr(il, off, type)	((type)(((caddr_t)((il)+1)+(off))))
D 16
	if (il->ilr_type >= ILPUP_TRAIL &&
	    il->ilr_type < ILPUP_TRAIL+ILPUP_NTRAILER) {
		off = (il->ilr_type - ILPUP_TRAIL) * 512;
		if (off >= ILMTU)
E 16
I 16
D 32
	if (il->ilr_type >= ETHERPUP_TRAIL &&
	    il->ilr_type < ETHERPUP_TRAIL+ETHERPUP_NTRAILER) {
		off = (il->ilr_type - ETHERPUP_TRAIL) * 512;
E 32
I 32
	if (il->ilr_type >= ETHERTYPE_TRAIL &&
	    il->ilr_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (il->ilr_type - ETHERTYPE_TRAIL) * 512;
E 32
		if (off >= ETHERMTU)
E 16
			goto setup;		/* sanity */
D 16
		il->ilr_type = *ildataaddr(il, off, u_short *);
		resid = *(ildataaddr(il, off+2, u_short *));
E 16
I 16
		il->ilr_type = ntohs(*ildataaddr(il, off, u_short *));
		resid = ntohs(*(ildataaddr(il, off+2, u_short *)));
E 16
		if (off + resid > len)
			goto setup;		/* sanity */
		len = off + resid;
	} else
		off = 0;
	if (len == 0)
		goto setup;

	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; ilget will then force this header
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
D 35
	m = if_rubaget(&is->is_ifuba, len, off);
E 35
I 35
	m = if_rubaget(&is->is_ifuba, len, off, &is->is_if);
E 35
	if (m == 0)
		goto setup;
	if (off) {
I 35
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
E 35
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
I 35
		*(mtod(m, struct ifnet **)) = ifp;
E 35
	}
	switch (il->ilr_type) {

#ifdef INET
D 16
	case ILPUP_IPTYPE:
E 16
I 16
D 32
	case ETHERPUP_IPTYPE:
E 32
I 32
	case ETHERTYPE_IP:
E 32
E 16
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
I 18

D 32
	case ETHERPUP_ARPTYPE:
E 32
I 32
	case ETHERTYPE_ARP:
E 32
		arpinput(&is->is_ac, m);
D 26
		return;
E 26
I 26
		goto setup;
E 26
E 18
#endif
I 34
#ifdef NS
	case ETHERTYPE_NS:
		schednetisr(NETISR_NS);
		inq = &nsintrq;
		break;

#endif
E 34
	default:
		m_freem(m);
		goto setup;
	}

I 29
	s = splimp();
E 29
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		m_freem(m);
D 7
	} else
		IF_ENQUEUE(inq, m);
E 7
I 7
D 29
		goto setup;
	}
	IF_ENQUEUE(inq, m);
E 29
I 29
	} else
		IF_ENQUEUE(inq, m);
	splx(s);
E 29
E 7

setup:
	/*
	 * Reset for next packet if possible.
	 * If waiting for transmit command completion, set flag
	 * and wait until command completes.
	 */
D 7
	if (!is->is_oactive) {
		addr->il_bar = is->is_ifuba.ifu_r.ifrw_info & 0xffff;
		addr->il_bcr = sizeof(struct il_rheader) + ILMTU + 6;
		addr->il_csr = ((is->is_ifuba.ifu_r.ifrw_info>>2)&0xc000)|
				ILC_RCV|IL_RIE;
		while (!(addr->il_csr & IL_CDONE))
			/* Busy wait */;
	} else
E 7
I 7
D 9
	if (is->is_oactive) {
E 7
		is->is_startrcv = 1;
E 9
I 9
	if (is->is_flags & ILF_OACTIVE) {
		is->is_flags |= ILF_RCVPENDING;
E 9
I 7
		return;
	}
	addr->il_bar = is->is_ifuba.ifu_r.ifrw_info & 0xffff;
D 16
	addr->il_bcr = sizeof(struct il_rheader) + ILMTU + 6;
E 16
I 16
	addr->il_bcr = sizeof(struct il_rheader) + ETHERMTU + 6;
E 16
D 9
	csr = ((is->is_ifuba.ifu_r.ifrw_info>>2)&0xc000)|ILC_RCV|IL_RIE;
	addr->il_csr = csr;
E 9
I 9
	addr->il_csr =
		((is->is_ifuba.ifu_r.ifrw_info >> 2) & IL_EUA)|ILC_RCV|IL_RIE;
I 37
	s = splhigh();
E 37
E 9
	while ((addr->il_csr & IL_CDONE) == 0)
		;
I 37
	splx(s);
E 37
E 7
}

/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
iloutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
D 18
	int type, dest, s, error;
E 18
I 18
	int type, s, error;
D 30
	u_char edst[6];
E 30
I 30
D 32
	struct ether_addr edst;
E 32
I 32
 	u_char edst[6];
E 32
E 30
	struct in_addr idst;
E 18
	register struct il_softc *is = &il_softc[ifp->if_unit];
	register struct mbuf *m = m0;
D 16
	register struct il_xheader *il;
E 16
I 16
	register struct ether_header *il;
E 16
D 7
	register int off;
	register int i;
E 7
I 7
D 14
	register int off, i;
E 14
I 14
	register int off;
I 38
	int usetrailers;
E 38
E 14
E 7

I 37
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
		error = ENETDOWN;
		goto bad;
	}
E 37
D 8
COUNT(ILOUTPUT);
E 8
	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
D 18
		dest = ((struct sockaddr_in *)dst)->sin_addr.s_addr;
E 18
I 18
		idst = ((struct sockaddr_in *)dst)->sin_addr;
D 30
		if (!arpresolve(&is->is_ac, m, &idst, edst))
E 30
I 30
D 32
		if (!arpresolve(&is->is_ac, m, &idst, &edst))
E 32
I 32
D 38
 		if (!arpresolve(&is->is_ac, m, &idst, edst))
E 38
I 38
 		if (!arpresolve(&is->is_ac, m, &idst, edst, &usetrailers))
E 38
E 32
E 30
			return (0);	/* if not yet resolved */
E 18
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
I 22
D 38
		/* need per host negotiation */
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
E 22
		if (off > 0 && (off & 0x1ff) == 0 &&
E 38
I 38
		if (usetrailers && off > 0 && (off & 0x1ff) == 0 &&
E 38
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
D 16
			type = ILPUP_TRAIL + (off>>9);
E 16
I 16
D 32
			type = ETHERPUP_TRAIL + (off>>9);
E 32
I 32
			type = ETHERTYPE_TRAIL + (off>>9);
E 32
E 16
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
D 16
			*mtod(m, u_short *) = ILPUP_IPTYPE;
			*(mtod(m, u_short *) + 1) = m->m_len;
E 16
I 16
D 32
			*mtod(m, u_short *) = htons((u_short)ETHERPUP_IPTYPE);
E 32
I 32
			*mtod(m, u_short *) = htons((u_short)ETHERTYPE_IP);
E 32
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
E 16
			goto gottrailertype;
		}
D 16
		type = ILPUP_IPTYPE;
E 16
I 16
D 32
		type = ETHERPUP_IPTYPE;
E 32
I 32
		type = ETHERTYPE_IP;
E 32
E 16
		off = 0;
		goto gottype;
#endif
I 34
#ifdef NS
	case AF_NS:
		type = ETHERTYPE_NS;
 		bcopy((caddr_t)&(((struct sockaddr_ns *)dst)->sns_addr.x_host),
		(caddr_t)edst, sizeof (edst));
		off = 0;
		goto gottype;
#endif
E 34

I 18
	case AF_UNSPEC:
		il = (struct ether_header *)dst->sa_data;
D 21
		bcopy(il->ether_dhost, edst, sizeof (edst));
E 21
I 21
D 30
		bcopy((caddr_t)il->ether_dhost, (caddr_t)edst, sizeof (edst));
E 30
I 30
D 32
		edst = il->ether_dhost;
E 32
I 32
 		bcopy((caddr_t)il->ether_dhost, (caddr_t)edst, sizeof (edst));
E 32
E 30
E 21
		type = il->ether_type;
		goto gottype;

E 18
	default:
		printf("il%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		error = EAFNOSUPPORT;
		goto bad;
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

gottype:
	/*
	 * Add local net header.  If no space in first mbuf,
	 * allocate another.
	 */
	if (m->m_off > MMAXOFF ||
D 16
	    MMINOFF + sizeof (struct il_xheader) > m->m_off) {
E 16
I 16
	    MMINOFF + sizeof (struct ether_header) > m->m_off) {
E 16
D 15
		m = m_get(M_DONTWAIT);
E 15
I 15
		m = m_get(M_DONTWAIT, MT_HEADER);
E 15
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
D 16
		m->m_len = sizeof (struct il_xheader);
E 16
I 16
		m->m_len = sizeof (struct ether_header);
E 16
	} else {
D 16
		m->m_off -= sizeof (struct il_xheader);
		m->m_len += sizeof (struct il_xheader);
E 16
I 16
		m->m_off -= sizeof (struct ether_header);
		m->m_len += sizeof (struct ether_header);
E 16
	}
D 16
	il = mtod(m, struct il_xheader *);
E 16
I 16
	il = mtod(m, struct ether_header *);
E 16
D 18
	if ((dest &~ 0xff) == 0)
D 7
		for (i=0; i<6; i++)
			il->ilx_dhost[i] = 0xff;
E 7
I 7
D 14
		bcopy(ilbroadcastaddr, il->ilx_dhost, 6);
E 14
I 14
D 16
		bcopy((caddr_t)ilbroadcastaddr, (caddr_t)il->ilx_dhost, 6);
E 16
I 16
		bcopy((caddr_t)ilbroadcastaddr, (caddr_t)il->ether_dhost, 6);
E 16
E 14
E 7
	else {
D 7
		if (dest & 0x8000) {
			il->ilx_dhost[0] = is->is_enaddr[0];
			il->ilx_dhost[1] = is->is_enaddr[1];
			il->ilx_dhost[2] = is->is_enaddr[2];
		} else {
			il->ilx_dhost[0] = il_ectop[0];
			il->ilx_dhost[1] = il_ectop[1];
			il->ilx_dhost[2] = il_ectop[2];
		}
E 7
I 7
D 9
		u_char *to = dest & 0x8000 ? is->is_enaddr : il_ectop;
E 9
I 9
		u_char *to = dest & 0x8000 ? is->is_stats.ils_addr : il_ectop;
E 9

D 14
		bcopy(to, il->ilx_dhost, 3);
E 14
I 14
D 16
		bcopy((caddr_t)to, (caddr_t)il->ilx_dhost, 3);
E 14
E 7
		il->ilx_dhost[3] = (dest>>8) & 0x7f;
		il->ilx_dhost[4] = (dest>>16) & 0xff;
		il->ilx_dhost[5] = (dest>>24) & 0xff;
E 16
I 16
		bcopy((caddr_t)to, (caddr_t)il->ether_dhost, 3);
		il->ether_dhost[3] = (dest>>8) & 0x7f;
		il->ether_dhost[4] = (dest>>16) & 0xff;
		il->ether_dhost[5] = (dest>>24) & 0xff;
E 16
	}
I 14
D 16
	bcopy((caddr_t)is->is_stats.ils_addr, (caddr_t)il->ilx_shost, 6);
E 14
	il->ilx_type = type;
E 16
I 16
	bcopy((caddr_t)is->is_stats.ils_addr, (caddr_t)il->ether_shost, 6);
E 18
	il->ether_type = htons((u_short)type);
I 18
D 21
	bcopy(edst, il->ether_dhost, sizeof (edst));
E 21
I 21
D 30
	bcopy((caddr_t)edst, (caddr_t)il->ether_dhost, sizeof (edst));
E 21
	bcopy((caddr_t)is->is_addr, (caddr_t)il->ether_shost, 6);
E 30
I 30
D 32
	il->ether_dhost = edst;
	il->ether_shost = is->is_addr;
E 32
I 32
 	bcopy((caddr_t)edst, (caddr_t)il->ether_dhost, sizeof (edst));
 	bcopy((caddr_t)is->is_addr, (caddr_t)il->ether_shost,
	    sizeof(il->ether_shost));
E 32
E 30
E 18
E 16

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
D 7
		error = ENOBUFS;
		goto qfull;
E 7
I 7
		splx(s);
		m_freem(m);
		return (ENOBUFS);
E 7
	}
	IF_ENQUEUE(&ifp->if_snd, m);
D 9
	if (is->is_oactive == 0)
E 9
I 9
	if ((is->is_flags & ILF_OACTIVE) == 0)
E 9
		ilstart(ifp->if_unit);
	splx(s);
	return (0);
D 7
qfull:
	m0 = m;
	splx(s);
E 7
I 7

E 7
bad:
	m_freem(m0);
D 7
	return(error);
E 7
I 7
	return (error);
I 9
}

/*
 * Watchdog routine, request statistics from board.
 */
ilwatch(unit)
	int unit;
{
	register struct il_softc *is = &il_softc[unit];
	register struct ifnet *ifp = &is->is_if;
	int s;

	if (is->is_flags & ILF_STATPENDING) {
		ifp->if_timer = is->is_scaninterval;
		return;
	}
	s = splimp();
	is->is_flags |= ILF_STATPENDING;
	if ((is->is_flags & ILF_OACTIVE) == 0)
		ilstart(ifp->if_unit);
	splx(s);
	ifp->if_timer = is->is_scaninterval;
}

/*
 * Total up the on-board statistics.
 */
iltotal(is)
	register struct il_softc *is;
{
	register u_short *interval, *sum, *end;

	interval = &is->is_stats.ils_frames;
	sum = &is->is_sum.ils_frames;
	end = is->is_sum.ils_fill2;
	while (sum < end)
		*sum++ += *interval++;
	is->is_if.if_collisions = is->is_sum.ils_collis;
I 42
	if ((is->is_flags & ILF_SETADDR) &&
	    (bcmp((caddr_t)is->is_stats.ils_addr, (caddr_t)is->is_addr,
					sizeof (is->is_addr)) != 0)) {
		log(LOG_ERR, "il%d: physaddr reverted\n", is->is_if.if_unit);
		is->is_flags &= ~ILF_RUNNING;
		ilinit(is->is_if.if_unit);
	}
E 42
I 22
}

/*
 * Process an ioctl request.
 */
ilioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 32
	register struct ifreq *ifr = (struct ifreq *)data;
E 32
I 32
	register struct ifaddr *ifa = (struct ifaddr *)data;
I 37
	register struct il_softc *is = &il_softc[ifp->if_unit];
E 37
E 32
D 24
	register struct sockaddr_in *sin;
E 24
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
D 32
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
D 24
		ifp->if_addr = ifr->ifr_addr;
		ifp->if_net = in_netof(ifr->ifr_addr);
		ifp->if_host[0] = in_lnaof(ifr->ifr_addr);
		sin = (struct sockaddr_in *)&ifp->if_broadaddr;
		sin->sin_family = AF_INET;
		sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
		ifp->if_flags |= IFF_BROADCAST;
E 24
I 24
		ilsetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
E 32
I 32
		ifp->if_flags |= IFF_UP;
E 32
E 24
		ilinit(ifp->if_unit);
I 32

		switch (ifa->ifa_addr.sa_family) {
I 34
#ifdef INET
E 34
		case AF_INET:
			((struct arpcom *)ifp)->ac_ipaddr =
				IA_SIN(ifa)->sin_addr;
			arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
			break;
I 34
#endif
#ifdef NS
		case AF_NS:
D 38
			IA_SNS(ifa)->sns_addr.x_host =
				* (union ns_host *) 
D 37
				     (il_softc[ifp->if_unit].is_addr);
E 37
I 37
				     (is->is_addr);
E 38
I 38
		    {
			register struct ns_addr *ina = &(IA_SNS(ifa)->sns_addr);
			
			if (ns_nullhost(*ina)) {
				ina->x_host = * (union ns_host *) 
				     (il_softc[ifp->if_unit].is_addr);
			} else {
D 39
			    return
E 39
				il_setaddr(ina->x_host.c_host, ifp->if_unit);
I 39
				return (0);
E 39
			}
E 38
E 37
			break;
I 38
		    }
E 38
#endif
E 34
		}
I 37
		break;

	case SIOCSIFFLAGS:
		if ((ifp->if_flags & IFF_UP) == 0 &&
		    is->is_flags & ILF_RUNNING) {
			((struct ildevice *)
			   (ilinfo[ifp->if_unit]->ui_addr))->il_csr = ILC_RESET;
			is->is_flags &= ~ILF_RUNNING;
		} else if (ifp->if_flags & IFF_UP &&
		    (is->is_flags & ILF_RUNNING) == 0)
			ilinit(ifp->if_unit);
E 37
E 32
		break;

	default:
		error = EINVAL;
	}
	splx(s);
I 38
	return (error);
}

/*
 * set ethernet address for unit
 */
il_setaddr(physaddr, unit)
u_char *physaddr;
int unit;
{
	register struct il_softc *is = &il_softc[unit];
D 39
	register struct uba_device *ui = ilinfo[unit];
	register struct ildevice *addr= (struct ildevice *)ui->ui_addr;
	int error = 0, ubaddr;
E 39
	
	if (! (is->is_flags & ILF_RUNNING))
		return;
		
D 39
	bcopy((caddr_t)physaddr, (caddr_t)&is->is_stats, sizeof is->is_addr);
	addr->il_bar = is->is_ubaddr & 0xffff;
	addr->il_bcr = sizeof is->is_addr;
	addr->il_csr = ((is->is_ubaddr >> 2) & IL_EUA)|ILC_LDPA;
	if (ilwait(ui, "setaddr"))
		error = EADDRNOTAVAIL;
	addr->il_bar = is->is_ubaddr & 0xffff;
	addr->il_bcr = sizeof (struct il_stats);
	addr->il_csr = ((is->is_ubaddr >> 2) & IL_EUA)|ILC_STAT;
	if (ilwait(ui, "status"))
		error = ESRCH;
	if (is->is_flags & ILF_STATPENDING)
		is->is_flags &= ~ILF_STATPENDING;
	if (error == 0 &&
	    bcmp((caddr_t)is->is_stats.ils_addr, (caddr_t)physaddr,
						sizeof (is->is_addr)) == 0) {
		is->is_flags |= ILF_SETADDR;
		bcopy(physaddr, is->is_addr, sizeof is->is_addr);
	} else {
		error = EBUSY;
		printf("il%d: setaddr didn't work\n", ui->ui_unit);
	}
E 38
	return (error);
E 39
I 39
	bcopy((caddr_t)physaddr, (caddr_t)is->is_addr, sizeof is->is_addr);
	is->is_flags &= ~ILF_RUNNING;
	is->is_flags |= ILF_SETADDR;
	ilinit(unit);
E 39
I 24
D 32
}

D 25
ilsetaddr(ifp, sin);
E 25
I 25
ilsetaddr(ifp, sin)
E 25
	register struct ifnet *ifp;
	register struct sockaddr_in *sin;
{

	ifp->if_addr = *(struct sockaddr *)sin;
	ifp->if_net = in_netof(sin->sin_addr);
	ifp->if_host[0] = in_lnaof(sin->sin_addr);
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags |= IFF_BROADCAST;
E 32
E 24
E 22
E 9
E 7
}
I 36
#endif
E 36
D 6

#if NIMP == 0 && NIL > 0
/*
 * Logical host interface driver.
 * Allows host to appear as an ARPAnet
 * logical host.  Must also have routing
 * table entry set up to forward packets
 * to appropriate gateway on localnet.
 */

struct	ifnet illhif;
D 2
int	illhoutput();
E 2
I 2
int	looutput();
E 2

/*
 * Called by localnet interface to allow logical
 * host interface to "attach".  Nothing should ever
 * be sent locally to this interface, it's purpose
 * is simply to establish the host's arpanet address.
 */
D 2
illhinit(addr)
E 2
I 2
illhinit(ilifp, addr)
	struct ifnet *ilifp;
E 2
	int addr;
{
	register struct ifnet *ifp = &illhif;
	register struct sockaddr_in *sin;

COUNT(ILLHINIT);
	ifp->if_name = "lh";
	ifp->if_mtu = ILMTU;
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = addr;
I 4
	sin->sin_addr.s_lh = ilifp->if_host[0];
E 4
	ifp->if_net = sin->sin_addr.s_net;
D 2
	ifp->if_flags = IFF_UP;
	ifp->if_output = illhoutput;	/* should never be used */
E 2
I 2
D 4
	ifp->if_dstaddr = ilifp->if_addr;
E 4
I 4
	ifp->if_dstaddr = ifp->if_addr;
E 4
	ifp->if_flags = IFF_UP|IFF_POINTOPOINT;
	ifp->if_output = looutput;
E 2
	if_attach(ifp);
D 2
}

illhoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
COUNT(ILLHOUTPUT);
	ifp->if_oerrors++;
	m_freem(m0);
	return (0);
E 2
I 2
D 3
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_DIRECT);
E 3
I 3
D 5
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_DIRECT|RTF_HOST);
E 5
I 5
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_HOST);
E 5
E 3
E 2
}
#endif
E 6
E 1
