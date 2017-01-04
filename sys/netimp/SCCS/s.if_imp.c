h48154
s 00017/00000/00955
d D 7.9 02/08/02 23:40:20 msokolov 74 73
c notify netmon on major state transitions
e
s 00011/00006/00944
d D 7.8 88/06/29 16:58:02 bostic 73 72
c install approved copyright notice
e
s 00007/00007/00943
d D 7.7 88/05/26 09:43:27 karels 72 70
c lint
e
s 00001/00002/00948
d R 7.7 88/05/24 11:12:16 karels 71 70
c lint
e
s 00004/00001/00946
d D 7.6 88/05/14 11:03:00 karels 70 69
c increment drop count when blocked by rfnm
e
s 00111/00120/00836
d D 7.5 88/05/06 12:32:55 karels 69 68
c clean up queuing, keep message counts correctly, check for 1822L NOPs, etc
e
s 00273/00145/00683
d D 7.4 88/02/08 10:30:05 karels 68 67
c new copyrights; new IMP interface with H/W, using cb_output rather
c than cb_start (so can start RFNM timer when packet goes out, and output is
c round-robin by destination)
e
s 00208/00154/00620
d D 7.3 88/02/03 17:26:39 karels 67 66
c working with new up/down FSM, dropcount, statistics and host entry
e
s 00006/00006/00768
d D 7.2 87/10/31 14:52:18 bostic 66 65
c impinit should reset spl level
e
s 00001/00001/00773
d D 7.1 86/06/04 23:55:06 mckusick 65 64
c 4.3BSD release version
e
s 00066/00047/00708
d D 6.10 86/05/27 19:48:54 karels 64 62
c more errors, etc sent to raw socket; sundry cleanups
e
s 00010/00008/00747
d R 6.10 86/05/04 19:53:17 karels 63 62
c lemme see the goodies
e
s 00012/00007/00743
d D 6.9 86/02/23 23:36:44 karels 62 61
c lint
e
s 00001/00001/00749
d D 6.8 85/11/06 17:39:44 karels 61 60
c typo
e
s 00085/00044/00665
d D 6.7 85/09/16 21:29:52 karels 60 59
c fix races: queue error messages for processing at splnet, don't lose
c if timing out host entries while walking queue; keep timer on rfnm's, restart
c if it expires; don't restart hostdead timer when touching entry, or a ping
c will keep it down forever
e
s 00007/00001/00702
d D 6.6 85/06/08 12:31:31 mckusick 59 58
c Add copyright
e
s 00001/00001/00702
d D 6.5 85/05/27 21:59:20 karels 58 57
c use pfctlinput instead of ip_ctlinput (let everyone see it)
e
s 00045/00057/00658
d D 6.4 85/03/19 16:17:53 karels 57 56
c move net addresses from interface layer into protocols
e
s 00099/00045/00616
d D 6.3 85/02/28 14:27:13 karels 56 55
c mods for Classs B,C support, RFNM fixes from BRL
e
s 00013/00013/00648
d D 6.2 84/08/29 16:17:30 bloom 55 54
c Change to include files.  No more ../h
e
s 00000/00000/00661
d D 6.1 83/07/29 07:15:19 sam 54 53
c 4.2 distribution
e
s 00002/00003/00659
d D 4.51 83/06/13 23:02:50 sam 53 52
c lint
e
s 00046/00006/00616
d D 4.50 83/06/13 00:28:55 sam 52 50
c ioctls
e
s 00045/00006/00616
d R 4.50 83/06/13 00:21:04 sam 51 50
c ioctls
e
s 00004/00010/00618
d D 4.49 83/02/23 00:01:19 sam 50 49
c cleanup splnet's; if_imphost code interlocks at splimp now
e
s 00002/00001/00626
d D 4.48 83/02/10 22:17:07 sam 49 48
c remove /usr/include dependencies
e
s 00002/00000/00625
d D 4.47 83/02/10 19:54:09 sam 48 47
c hz now only in kernel.h
e
s 00002/00001/00623
d D 4.46 82/12/17 12:15:53 sam 47 46
c sun merge
e
s 00002/00002/00622
d D 4.45 82/12/14 17:18:34 sam 46 45
c typed mbufs
e
s 00001/00001/00623
d D 4.44 82/10/31 16:52:09 root 45 44
c if_reset instead of if_ubareset
e
s 00003/00001/00621
d D 4.43 82/10/22 01:02:18 root 44 43
c lint
e
s 00003/00004/00619
d D 4.42 82/10/21 21:22:36 root 43 42
c lint
e
s 00013/00010/00610
d D 4.41 82/10/20 01:43:55 root 42 41
c lint
e
s 00001/00001/00619
d D 4.40 82/10/13 22:45:01 root 41 40
c move mtpr.h to vax directory
e
s 00007/00006/00613
d D 4.39 82/10/09 05:49:02 wnj 40 39
c fix header files
e
s 00000/00002/00619
d D 4.38 82/10/05 18:49:04 root 39 38
c m_get inits m_off; remove TCPTRUEOOB
e
s 00000/00009/00621
d D 4.37 82/06/20 00:52:48 sam 38 37
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00629
d D 4.36 82/06/15 21:04:13 sam 37 36
c add route only after host address discovered (for routed)
e
s 00005/00006/00625
d D 4.35 82/06/15 15:16:05 sam 36 35
c clean up imp code after fixing problems
e
s 00046/00001/00585
d D 4.34 82/06/14 09:28:16 sam 35 33
c before carry to calder
e
s 00046/00001/00585
d R 4.34 82/06/13 23:00:51 sam 34 33
c add class a/b/c net #'s and purge logical host kludge code
e
s 00001/00001/00585
d D 4.33 82/06/12 23:18:40 wnj 33 32
c now the routing code might wokr
e
s 00002/00002/00584
d D 4.32 82/05/14 16:46:08 sam 32 31
c clean up
e
s 00001/00001/00585
d D 4.31 82/05/06 15:52:15 sam 31 30
c splx in wrong place (from croft@sri)
e
s 00001/00006/00585
d D 4.30 82/05/02 17:04:48 sam 30 29
c clean up some icmp stuff; add EHOSTDOWN & EHOSTUNREACH
e
s 00001/00001/00590
d D 4.29 82/04/28 19:09:10 sam 29 28
c blew the last mod
e
s 00002/00000/00589
d D 4.28 82/04/28 19:07:06 sam 28 27
c only look at one of (possibly) many going down messages (NCC likes to 
c give out many)
e
s 00049/00032/00540
d D 4.27 82/04/25 18:34:34 sam 27 26
c make host structure deletion timer based
e
s 00041/00071/00531
d D 4.26 82/04/24 20:37:43 sam 26 25
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00002/00002/00600
d D 4.25 82/04/11 15:15:40 sam 25 24
c reverse src and dst to raw_input
e
s 00013/00006/00589
d D 4.24 82/04/10 18:26:13 sam 24 23
c invert output path to pass back error indications
e
s 00014/00009/00581
d D 4.23 82/04/10 15:21:22 sam 23 22
c unsatisfactory attempt to fix up imp
e
s 00001/00002/00589
d D 4.22 82/04/07 11:47:30 sam 22 21
c checking wrong state to see if imp down
e
s 00003/00000/00588
d D 4.21 82/03/30 11:31:47 sam 21 20
c with routing, but not forwarding
e
s 00025/00046/00563
d D 4.20 82/03/28 14:21:39 sam 20 19
c convert interfaces to sockaddr's and add hooks for routing
e
s 00004/00004/00605
d D 4.19 82/03/19 17:09:02 root 19 18
c IMPMTU fixup
e
s 00001/00001/00608
d D 4.18 82/03/19 01:48:46 wnj 18 17
c fix to use only one soft intr for net thereby fixing bug in raw sockets
e
s 00007/00020/00602
d D 4.17 82/03/19 00:14:34 root 17 16
c set if_mtu respecting our need for a leader; cleanup comments and delete setting of il_length
e
s 00006/00005/00616
d D 4.16 82/03/16 13:53:37 root 16 15
c fixes to imp
e
s 00039/00000/00582
d D 4.15 82/03/15 04:43:31 wnj 15 14
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00011/00007/00571
d D 4.14 82/03/13 12:51:53 sam 14 13
c lint
e
s 00001/00008/00577
d D 4.13 82/03/12 16:10:34 sam 13 12
c remove some lint
e
s 00007/00013/00578
d D 4.12 82/03/10 11:23:56 wnj 12 11
c redo fixes lost by crash
e
s 00008/00008/00583
d D 4.11 82/03/05 14:06:45 wnj 11 10
c minor fixes
e
s 00003/00005/00588
d D 4.10 82/02/27 13:01:48 root 10 9
c clean up cruft after getting new IMP microcode
e
s 00001/00001/00592
d D 4.9 82/02/21 15:28:17 root 9 8
c counter wrong
e
s 00017/00054/00576
d D 4.8 82/02/21 13:08:33 root 8 7
c cleanup code a bit
e
s 00016/00010/00614
d D 4.7 82/02/16 17:09:17 root 7 6
c messed up rfnm q's
e
s 00002/00009/00622
d D 4.6 82/02/16 15:14:57 root 6 5
c wire in host address -- IMP is broke
e
s 00021/00014/00610
d D 4.5 82/02/16 15:11:37 root 5 4
c first "working" imp driver
e
s 00158/00062/00466
d D 4.4 82/02/12 15:17:17 wnj 4 3
c closer to a working imp driver
e
s 00057/00024/00471
d D 4.3 82/02/01 22:49:59 sam 3 2
c cleanup before start of testing
e
s 00007/00005/00488
d D 4.2 82/02/01 17:50:13 sam 2 1
c raw interfaces brought up to date
e
s 00493/00000/00000
d D 4.1 82/02/01 13:56:19 root 1 0
c date and time created 82/02/01 13:56:19 by root
e
u
U
t
T
I 1
D 59
/*	%M%	%I%	%E%	*/
E 59
I 59
/*
D 65
 * Copyright (c) 1982 Regents of the University of California.
E 65
I 65
D 68
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 65
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 68
I 68
D 73
 * Copyright (c) 1982,1986,1988 Regents of the University of California.
E 73
I 73
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 73
 * All rights reserved.
E 68
 *
I 68
 * Redistribution and use in source and binary forms are permitted
D 73
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 73
I 73
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
E 73
 *
E 68
 *	%W% (Berkeley) %G%
 */
E 59

#include "imp.h"
#if NIMP > 0
/*
D 26
 * ARPAnet IMP interface driver.
E 26
I 26
D 68
 * ARPANET IMP interface driver.
E 68
I 68
 * ARPANET IMP (PSN) interface driver.
E 68
E 26
 *
D 68
 * The IMP-host protocol is handled here, leaving
E 68
I 68
 * The IMP-host protocol (AHIP) is handled here, leaving
E 68
 * hardware specifics to the lower level interface driver.
I 52
D 56
 *
 * NB: only handles IMPS on class A networks.
E 56
E 52
I 4
D 26
 *
 * TODO:
D 20
 *	rethink coupling between this module and device driver
E 20
 *	pass more error indications up to protocol modules
E 26
D 5
 *	test raw imp interface
E 5
E 4
 */
I 47
D 68
#include "../machine/pte.h"

E 68
E 47
D 55
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 47
#include "../h/pte.h"
E 47
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
D 42
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/cpu.h"
D 41
#include "../h/mtpr.h"
E 41
I 41
#include "../vax/mtpr.h"
E 42
E 41
#include "../h/vmmac.h"
I 48
#include "../h/time.h"
#include "../h/kernel.h"
I 49
#include "../h/errno.h"
I 52
#include "../h/ioctl.h"
E 55
I 55
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
D 68
#include "vmmac.h"
E 68
#include "time.h"
#include "kernel.h"
#include "errno.h"
#include "ioctl.h"
I 67
#include "syslog.h"
E 67
E 55
E 52
E 49
E 48
D 40
#include "../net/in.h"
#include "../net/in_systm.h"
E 40
I 40
D 42
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 42
I 42

D 68
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 43
#include "../vax/ubareg.h"
#include "../vax/ubavar.h"
E 43
I 43
#include "../vaxuba/ubareg.h"
E 68
I 68
#include "../machine/mtpr.h"

E 68
D 69
#include "../vaxuba/ubavar.h"
E 43

E 69
E 42
E 40
#include "../net/if.h"
I 42
D 68
#include "../net/route.h"
E 68
I 49
D 69

E 69
E 49
E 42
I 40
#include "../net/netisr.h"
I 42
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 57
#include "../netinet/in_var.h"
E 57
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
I 67
#define IMPMESSAGES
E 67
E 42
E 40
I 35
D 36
#define	IMPLEADERS
E 36
I 36
/* define IMPLEADERS here to get leader printing code */
I 67
D 68
#define IMPLEADERS
#define IMPINIT
E 68
E 67
E 36
E 35
I 4
D 5
#define	IMPLEADERS
E 5
E 4
D 40
#include "../net/if_imp.h"
D 5
#include "../net/host.h"
E 5
I 5
#include "../net/if_imphost.h"
E 5
#include "../net/ip.h"
#include "../net/ip_var.h"
E 40
I 40
D 55
#include "../netimp/if_imp.h"
#include "../netimp/if_imphost.h"
E 55
I 55
#include "if_imp.h"
#include "if_imphost.h"
E 55
D 42
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
E 40
I 21
#include "../net/route.h"
E 42
I 24
D 49
#include <errno.h>
E 49
E 24
E 21

I 74
#include "netmon.h"

E 74
D 67
/*
 * IMP software status per interface.
 * (partially shared with the hardware specific module)
 *
 * Each interface is referenced by a network interface structure,
 * imp_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its
 * address, ...  IMP specific structures used in connecting the
 * IMP software modules to the hardware specific interface routines
D 4
 * are also stored here.  These structures are visible in the interface
 * driver through back pointers set up in the hardware's attach routine.
E 4
I 4
 * are stored here.  The common structures are made visible to the
 * interface driver by passing a pointer to the hardware routine
 * at "attach" time.
E 4
 *
 * NOTE: imp_if and imp_cb are assumed adjacent in hardware code.
 */
struct imp_softc {
	struct	ifnet imp_if;		/* network visible interface */
	struct	impcb imp_cb;		/* hooks to hardware module */
	u_char	imp_state;		/* current state of IMP */
	char	imp_dropcnt;		/* used during initialization */
D 4
	short	imp_timer;		/* going down timer */
E 4
} imp_softc[NIMP];

E 67
I 67
struct	imp_softc imp_softc[NIMP];
I 68
#ifndef lint
int	nimp = NIMP;			/* for netstat */
#endif
E 68
E 67
I 60
D 64
struct ifqueue impintrq;
E 64
I 64
struct	ifqueue impintrq;
int	impqmaxlen = IFQ_MAXLEN;
I 67
D 68
int	imphqlen = 12;			/* max packets to queue per host */
E 68
I 68
int	imphqlen = 12 + IMP_MAXHOSTMSG;	/* max packets to queue per host */
E 68
E 67
E 64

E 60
D 67
/*
 * Messages from IMP regarding why
 * it's going down.
 */
D 8
static char *impmsg[] = {
E 8
I 8
static char *impmessage[] = {
E 8
	"in 30 seconds",
	"for hardware PM",
	"to reload software",
	"for emergency reset"
};
E 67
I 67
int	imppri = LOG_ERR;
#ifdef IMPLEADERS
int	impprintfs = 0;
#endif
#ifdef IMPINIT
int	imptraceinit = 0;
#endif
E 67

I 68

E 68
I 56
D 67
#define HOSTDEADTIMER	10		/* How long to wait when down */
E 67
I 67
#define HOSTDEADTIMER	(30 * PR_SLOWHZ)	/* How long to wait when down */
E 67

E 56
I 4
D 52
int	impdown(), impinit(), impoutput();
E 52
I 52
D 68
int	impdown(), impinit(), impioctl(), impoutput();
E 68
I 68
int	impdown(), impinit(), impioctl(), impoutput(), imptimo();
E 68
E 52

E 4
/*
 * IMP attach routine.  Called from hardware device attach routine
D 67
 * at configuration time with a pointer to the UNIBUS device structure.
E 67
I 67
 * at configuration time with a pointer to the device structure.
E 67
 * Sets up local state and returns pointer to base of ifnet+impcb
 * structures.  This is then used by the device's attach routine
 * set up its back pointers. 
 */
I 67
struct imp_softc *
E 67
D 44
impattach(ui)
E 44
I 44
D 69
impattach(ui, reset)
E 44
	struct uba_device *ui;
E 69
I 69
impattach(hwname, hwunit, reset)
	char *hwname;
	int hwunit;
E 69
I 44
	int (*reset)();
E 44
{
D 60
	struct imp_softc *sc = &imp_softc[ui->ui_unit];
	register struct ifnet *ifp = &sc->imp_if;
E 60
I 60
	struct imp_softc *sc;
	register struct ifnet *ifp;
I 67
	static int impunit;
E 67
E 60
I 20
D 53
	struct sockaddr_in *sin;
E 53
E 20

I 62
#ifdef lint
	impintr();
#endif
E 62
I 60
D 67
	if (ui->ui_unit >= NIMP) {
		printf("imp%d: not configured\n", ui->ui_unit);
E 67
I 67
	if (impunit >= NIMP) {
		printf("imp%d: not configured\n", impunit++);
E 67
		return (0);
	}
D 67
	sc = &imp_softc[ui->ui_unit];
E 67
I 67
	sc = &imp_softc[impunit];
E 67
	ifp = &sc->imp_if;
E 60
D 38
COUNT(IMPATTACH);
E 38
D 67
	/* UNIT COULD BE AMBIGUOUS */
	ifp->if_unit = ui->ui_unit;
E 67
I 67
D 69
	sc->imp_cb.ic_hwunit = ui->ui_unit;
	sc->imp_cb.ic_hwname = ui->ui_driver->ud_dname;
E 69
I 69
	sc->imp_cb.ic_hwname = hwname;
	sc->imp_cb.ic_hwunit = hwunit;
E 69
	ifp->if_unit = impunit;
E 67
	ifp->if_name = "imp";
D 17
	ifp->if_mtu = IMP_MTU;
E 17
I 17
D 19
	ifp->if_mtu = IMP_MTU - sizeof (struct imp_leader);
E 19
I 19
	ifp->if_mtu = IMPMTU - sizeof(struct imp_leader);
E 19
E 17
D 52
	ifp->if_net = ui->ui_flags;
E 52
I 44
D 45
	ifp->if_ubareset = reset;
E 45
I 45
	ifp->if_reset = reset;
E 45
E 44
D 4
/*	ifp->if_host = ...	*/
/*	ifp->if_addr = if_makeaddr(ifp->if_net, ifp->if_host);	*/
E 4
I 4
D 6
#ifdef notdef
	/* this should get cleaned after we talk to the imp */
	ifp->if_addr = if_makeaddr(ifp->if_net, ifp->if_host);
#endif
E 6
I 6
D 10
	/* this should be found by talking to the imp */
D 7
	ifp->if_addr = 0x4e00000a;;
E 7
I 7
D 8
	ifp->if_addr.s_addr = 0x4e00000a;;
E 8
I 8
	ifp->if_addr.s_addr = 0x4e00000a;
E 10
I 10
D 52
	/* the host and imp fields will be filled in by the imp */
D 11
	ifp->if_addr.s_addr = if_makeaddr(ifp->if_net, 0);
E 11
I 11
D 20
	ifp->if_addr = if_makeaddr(ifp->if_net, 0);
E 20
I 20
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, 0);
E 52
E 20
E 11
E 10
E 8
E 7
E 6
	ifp->if_init = impinit;
I 52
	ifp->if_ioctl = impioctl;
E 52
	ifp->if_output = impoutput;
I 68
	ifp->if_watchdog = imptimo;
E 68
D 67
	/* reset is handled at the hardware level */
E 67
E 4
	if_attach(ifp);
D 20
	/* kludge to hand pointers back to hardware attach routine */
E 20
D 60
	return ((int)&sc->imp_if);
E 60
I 60
D 67
	return ((int)ifp);
E 67
I 67
	impunit++;
	return (sc);
E 67
E 60
}

I 15
D 20
#ifdef notdef
E 20
E 15
/*
I 15
D 20
 * Timer routine to keep priming the IMP until it sends
 * us the noops we need.  Since we depend on the host and
 * imp values returned in the noop messages, we must wait
 * for them before we allow any outgoing traffic.
 */
imptimer(sc)
	register struct imp_softc *sc;
{
	int s = splimp();

	if (sc->imp_state != IMPS_INIT) {
		splx(s);
		return;
	}
	sc->imp_dropcnt = IMP_DROPCNT;
	impnoops(sc);
	timeout(imptimer, (caddr_t)sc, 30 * hz);
	splx(s);
}
#endif

/*
E 20
E 15
 * IMP initialization routine: call hardware module to
D 67
 * setup UNIBUS resources, init state and get ready for
E 67
I 67
 * setup resources, init state and get ready for
E 67
 * NOOPs the IMP should send us, and that we want to drop.
 */
impinit(unit)
	int unit;
{
I 23
D 66
	int s = splimp();
E 66
I 66
	int s;
E 66
E 23
	register struct imp_softc *sc = &imp_softc[unit];
I 52
D 57
	struct sockaddr_in *sin;
E 57
E 52
I 21
D 23
	struct ifnet *ifp;
E 23
E 21

I 52
D 53
	sin = (struct sockaddr_in *)&sc->sc_if;
E 53
I 53
D 57
	sin = (struct sockaddr_in *)&sc->imp_if.if_addr;
E 53
	if (in_netof(sin->sin_addr) == 0)
E 57
I 57
	if (sc->imp_if.if_addrlist == 0)
E 57
		return;
I 66
	s = splimp();
E 66
E 52
I 23
D 38
COUNT(IMPINIT);
E 38
E 23
D 4
	(*sc->imp_cb.ic_init)(unit);
E 4
I 4
D 67
	if ((*sc->imp_cb.ic_init)(unit) == 0) {
		sc->imp_state = IMPS_DOWN;
E 67
I 67
#ifdef IMPINIT
	if (imptraceinit)
		log(imppri, "impinit\n");
#endif
	sc->imp_state = IMPS_WINIT;
	if ((*sc->imp_cb.ic_init)(sc->imp_cb.ic_hwunit) == 0)
E 67
I 20
		sc->imp_if.if_flags &= ~IFF_UP;
I 23
D 66
		splx(s);
E 23
E 20
		return;
E 66
I 66
D 67
	} else {
		sc->imp_state = IMPS_INIT;
		impnoops(sc);
		impintrq.ifq_maxlen = impqmaxlen;
E 66
	}
E 67
I 67
	impintrq.ifq_maxlen = impqmaxlen;
I 74
#if NNETMON > 0
	netmon_ifevent(&sc->imp_if);
#endif
E 74
E 67
I 52
D 53
	sc->sc_if.if_flags |= IFF_RUNNING;
E 53
I 53
D 57
	sc->imp_if.if_flags |= IFF_RUNNING;
E 57
E 53
E 52
E 4
D 66
	sc->imp_state = IMPS_INIT;
I 15
D 20
#ifdef notdef
	imptimer(sc);
#else
E 20
E 15
D 23
	sc->imp_dropcnt = IMP_DROPCNT;
E 23
I 4
	impnoops(sc);
I 64
	impintrq.ifq_maxlen = impqmaxlen;
E 66
E 64
I 21
D 33
	if_rtinit(&sc->imp_if, RTF_DIRECT|RTF_UP);
E 33
I 33
D 37
	if_rtinit(&sc->imp_if, RTF_UP);
E 37
E 33
I 23
	splx(s);
E 23
E 21
I 15
D 20
#endif
E 20
E 15
E 4
}

D 60
struct sockproto impproto = { PF_IMPLINK };
D 2
struct sockaddr_in impaddr = { AF_IMPLINK };
E 2
I 2
struct sockaddr_in impdst = { AF_IMPLINK };
struct sockaddr_in impsrc = { AF_IMPLINK };
E 60
I 36
D 67
#ifdef IMPLEADERS
E 36
I 35
int	impprintfs = 0;
I 36
#endif
E 36
E 35
E 2

E 67
/*
D 68
 * ARPAnet 1822 input routine.
E 68
I 68
 * ARPAnet 1822/AHIP input routine.
E 68
 * Called from hardware input interrupt routine to handle 1822
D 68
 * IMP-host messages.  Type 0 messages (non-control) are
 * passed to higher level protocol processors on the basis
 * of link number.  Other type messages (control) are handled here.
E 68
I 68
 * IMP-host messages.  Data messages are passed to higher-level
 * protocol processors on the basis of link number.
 * Other type messages (control) are handled here.
E 68
 */
D 4
impinput(unit, m0)
E 4
I 4
impinput(unit, m)
E 4
	int unit;
D 4
	struct mbuf *m0;
E 4
I 4
	register struct mbuf *m;
E 4
{
D 13
	int s;
E 13
D 4
	register struct mbuf *m;
E 4
D 67
	register struct imp_leader *ip;
E 67
I 67
	register struct control_leader *cp;
#define	ip	((struct imp_leader *)cp)
E 67
	register struct imp_softc *sc = &imp_softc[unit];
I 60
	struct ifnet *ifp;
E 60
	register struct host *hp;
	register struct ifqueue *inq;
I 4
D 67
	struct control_leader *cp;
E 4
	struct in_addr addr;
E 67
I 8
D 72
	struct mbuf *next;
E 72
I 20
	struct sockaddr_in *sin;
I 68
	int s;
E 68
E 20
E 8

I 60
	/*
	 * Pull the interface pointer out of the mbuf
	 * and save for later; adjust mbuf to look at rest of data.
	 */
	ifp = *(mtod(m, struct ifnet **));
	IF_ADJ(m);
E 60
D 9
COUNT(IMP_INPUT);
E 9
I 9
D 38
COUNT(IMPINPUT);
E 38
E 9
D 4
	m = m0;
I 3

E 4
I 4
D 5
printf("impinput(%d, %x), len=%d\n", unit, m, m->m_len);
printleader("impinput", mtod(m, struct imp_leader *));
E 5
E 4
D 17
	/*
I 4
	 * Verify leader length.  Be careful with control
	 * message which don't get a length included.
E 4
	 * We should generate a "bad leader" message
	 * to the IMP about messages too short.
	 */
E 17
I 17
	/* verify leader length. */
E 17
E 3
D 4
	if (m->m_len < sizeof(struct imp_leader) &&
	    m_pullup(m, sizeof(struct imp_leader)) == 0)
		goto drop;
E 4
I 4
	if (m->m_len < sizeof(struct control_leader) &&
	    (m = m_pullup(m, sizeof(struct control_leader))) == 0)
		return;
	cp = mtod(m, struct control_leader *);
D 67
	if (cp->dl_mtype == IMPTYPE_DATA)
		if (m->m_len < sizeof(struct imp_leader) &&
		    (m = m_pullup(m, sizeof(struct imp_leader))) == 0)
E 67
I 67
	if (cp->dl_mtype == IMPTYPE_DATA &&
	    m->m_len < sizeof(struct imp_leader)) {
		if ((m = m_pullup(m, sizeof(struct imp_leader))) == 0)
E 67
			return;
E 4
D 67
	ip = mtod(m, struct imp_leader *);
E 67
I 67
		cp = mtod(m, struct control_leader *);
	}
E 67
I 36
#ifdef IMPLEADERS
E 36
I 35
	if (impprintfs)
		printleader("impinput", ip);
I 36
#endif
I 64
	inq = &impintrq;
E 64
E 36
E 35

D 3
	/* check leader type. */
E 3
I 3
D 17
	/*
	 * Check leader type -- should notify IMP
	 * in case of failure...
	 */
E 17
I 17
	/* check leader type */
E 17
E 3
D 4
	if (ip->il_format != IMP_NFF)
E 4
I 4
D 67
	if (ip->il_format != IMP_NFF) {
E 67
I 67
	if (cp->dl_format != IMP_NFF) {
D 68
		sc->imp_garbage++;
E 67
		sc->imp_if.if_collisions++;	/* XXX */
E 68
I 68
D 69
		/* ignore old-style noops on reset */
		if (cp->dl_mtype != IMPTYPE_NOOP &&
		    cp->dl_mtype != IMPTYPE_RESET) {
E 69
I 69
		/*
		 * We get 1822L NOOPs and RESET
		 * at initialization.
		 */
#ifdef IMPINIT
		if (imptraceinit)
			log(imppri, "input, format %x mtype %d\n",
			    cp->dl_format, cp->dl_mtype);
#endif
		if (cp->dl_format != IMP_1822L_I2H ||
		    (cp->dl_mtype != IMPTYPE_NOOP &&
		    cp->dl_mtype != IMPTYPE_RESET)) {
E 69
			sc->imp_garbage++;
			sc->imp_if.if_collisions++;	/* XXX */
		}
E 68
E 4
D 64
		goto drop;
E 64
I 64
D 67
		goto rawlinkin;
E 64
I 4
	}
E 67
I 67
	} else switch (cp->dl_mtype) {
E 67
E 4

D 27
	/*
	 * Certain messages require a host structure.
	 * Do this in one shot here.
	 */
	switch (ip->il_mtype) {

	case IMPTYPE_RFNM:
	case IMPTYPE_INCOMPLETE:
	case IMPTYPE_HOSTDEAD:
	case IMPTYPE_HOSTUNREACH:
	case IMPTYPE_BADDATA:
E 27
I 27
D 67
	if (ip->il_mtype != IMPTYPE_DATA) {
E 27
I 5
D 56
#ifdef notdef
E 5
D 3
		addr.s_host = ntohs(ip->il_host);
E 3
I 3
D 4
		addr.s_host = ntohs(ip->il_host);	/* XXX */
E 3
		hp = h_lookup(addr);
E 4
I 4
		addr.s_net = ip->il_network;
I 5
#else
D 27
		addr.s_net = 0;
E 27
I 27
		addr.s_net = sc->imp_if.if_net;
E 27
#endif
E 5
		addr.s_imp = ip->il_imp;
		addr.s_host = ip->il_host;
E 56
I 56
		/* If not data packet, build IP addr from leader (BRL) */
D 57
		imp_leader_to_addr( &addr, ip, &sc->imp_if );
E 57
I 57
		imp_leader_to_addr(&addr, ip, &sc->imp_if);
E 57
E 56
D 27
		hp = hostlookup(addr);
E 4
		break;
E 27
	}
I 64

E 64
D 27

E 27
	switch (ip->il_mtype) {

E 67
D 17
	/*
	 * Data for a protocol.  Dispatch to the appropriate
	 * protocol routine (running at software interrupt).
	 * If this isn't a raw interface, advance pointer
D 3
	 * into mbuf past leader.
E 3
I 3
	 * into mbuf past leader (done below).
E 3
	 */
E 17
	case IMPTYPE_DATA:
I 64
		/*
		 * Data for a protocol.  Dispatch to the appropriate
		 * protocol routine (running at software interrupt).
		 * If this isn't a raw interface, advance pointer
		 * into mbuf past leader.
		 */
D 67
		switch (ip->il_link) {
E 67
I 67
		switch (cp->dl_link) {
E 67

		case IMPLINK_IP:
			m->m_len -= sizeof(struct imp_leader);
			m->m_off += sizeof(struct imp_leader);
			schednetisr(NETISR_IP);
			inq = &ipintrq;
			break;

		default:
			break;
		}
E 64
D 4
		ip->il_length = ntohs(ip->il_length) >> 3;
E 4
I 4
D 17
		ip->il_length =
			(ntohs(ip->il_length) >> 3) - sizeof(struct imp_leader);
E 17
E 4
		break;

	/*
	 * IMP leader error.  Reset the IMP and discard the packet.
	 */
	case IMPTYPE_BADLEADER:
D 3
		imperr(sc, "leader error");
		h_reset(sc->imp_if.if_net);	/* XXX */
		impnoops(sc);
E 3
I 3
		/*
		 * According to 1822 document, this message
		 * will be generated in response to the
		 * first noop sent to the IMP after
		 * the host resets the IMP interface.
		 */
I 67
#ifdef IMPINIT
		if (imptraceinit)
			log(imppri, "badleader\n");
#endif
E 67
D 4
		if (sc->imp_state != IMPS_RESET) {
E 4
I 4
		if (sc->imp_state != IMPS_INIT) {
E 4
D 8
			imperr(sc, "leader error");
E 8
I 8
			impmsg(sc, "leader error");
I 68
			sc->imp_msgready = 0;
E 68
E 8
D 4
			h_reset(sc->imp_if.if_net);	/* XXX */
E 4
I 4
D 26
			hostreset(sc->imp_if.if_net);	/* XXX */
E 26
I 26
D 57
			hostreset(sc->imp_if.if_net);
E 57
I 57
D 67
			hostreset(((struct in_ifaddr *)&sc->imp_if.if_addrlist)->ia_net);
E 67
I 67
			hostreset(unit);
E 67
E 57
E 26
E 4
			impnoops(sc);
I 68
			sc->imp_garbage++;
E 68
		}
I 67
D 68
		sc->imp_garbage++;
E 68
E 67
E 3
D 11
		goto drop;
E 11
I 11
D 26
		goto rawlinkin;
E 26
I 26
D 64
		goto drop;
E 64
I 64
		break;
E 64
E 26
E 11

	/*
	 * IMP going down.  Print message, and if not immediate,
	 * set off a timer to insure things will be reset at the
	 * appropriate time.
	 */
	case IMPTYPE_DOWN:
I 28
D 29
		if (sc->imp_state == IMPS_DOINGDOWN)
E 29
I 29
D 67
		if (sc->imp_state < IMPS_INIT)
E 67
I 67
	    {	int type, when;

		type = cp->dl_link & IMP_DMASK;
		when = (cp->dl_link & IMPDOWN_WHENMASK) >> IMPDOWN_WHENSHIFT;
#ifdef IMPINIT
		if (imptraceinit)
			log(imppri, "input DOWN %s %d\n",
			    impmessage[type], when * IMPDOWN_WHENUNIT);
#endif
		if (type != IMPDOWN_GOING && when)
			impmsg(sc, "going down %s in %d minutes",
			    (u_int)impmessage[type], when * IMPDOWN_WHENUNIT);
		else
			impmsg(sc, "going down %s", (u_int)impmessage[type]);
I 74
#if NNETMON > 0
		netmon_ifevent(ifp);
#endif
E 74
		if (sc->imp_state != IMPS_UP)
E 67
E 29
D 64
			goto drop;
E 64
I 64
			break;
E 64
E 28
D 67
		if ((ip->il_link & IMP_DMASK) == 0) {
E 67
I 67
		if (type == IMPDOWN_GOING) {
E 67
			sc->imp_state = IMPS_GOINGDOWN;
D 3
			sc->imp_timer = IMPTV_DOWN;
E 3
I 3
D 4
			timeout(impdown, sc, 30 * 60 * HZ);
E 4
I 4
D 14
			timeout(impdown, sc, 30 * hz);
E 14
I 14
D 67
			timeout(impdown, (caddr_t)sc, 30 * hz);
E 14
E 4
E 3
		}
D 8
		imperr(sc, "going down %s", impmsg[ip->il_link & IMP_DMASK]);
E 8
I 8
D 14
		impmsg(sc, "going down %s", impmessage[ip->il_link&IMP_DMASK]);
E 14
I 14
		impmsg(sc, "going down %s",
			(u_int)impmessage[ip->il_link&IMP_DMASK]);
E 67
I 67
			timeout(impdown, (caddr_t)sc, IMPTV_DOWN * hz);
		} else if (when == 0)
			sc->imp_state = IMPS_WINIT;
		sc->imp_dropcnt = 0;
E 67
E 14
E 8
D 11
		goto drop;
E 11
I 11
D 26
		goto rawlinkin;
E 26
I 26
D 64
		goto drop;
E 64
I 64
		break;
I 67
	    }
E 67
E 64
E 26
E 11

	/*
D 67
	 * A NOP usually seen during the initialization sequence.
E 67
I 67
	 * A NOP, usually seen during the initialization sequence.
E 67
	 * Compare the local address with that in the message.
	 * Reset the local address notion if it doesn't match.
	 */
D 4
	case IMPTYPE_NOOP:
E 4
I 4
D 20
	case IMPTYPE_NOOP: {
		register struct in_addr *sin;

E 20
I 20
	case IMPTYPE_NOOP:
E 20
E 4
I 3
D 67
		if (sc->imp_state == IMPS_DOWN) {
E 67
I 67
#ifdef IMPINIT
		if (imptraceinit)
			log(imppri, "noop\n");
#endif
		if (sc->imp_state == IMPS_WINIT) {
			sc->imp_dropcnt = 0;
			impnoops(sc);
E 67
			sc->imp_state = IMPS_INIT;
D 67
			sc->imp_dropcnt = IMP_DROPCNT;
E 67
		}
E 3
D 4
		if (sc->imp_state == IMPS_INIT && --sc->imp_dropcnt == 0) {
			sc->imp_state = IMPS_UP;
			/* restart output in case something was q'd */
			(*sc->imp_cb.ic_start)(sc->imp_if.if_unit);
		}
		if (ip->il_host != sc->imp_if.if_addr.s_host ||
		    ip->il_impno != sc->imp_if.if_addr.s_imp) {
			sc->imp_if.if_addr.s_host = ip->il_host;
			sc->imp_if.if_addr.s_imp = ip->il_imp;
			imperr(sc, "imp%d: address set to %d/%d\n",
				ip->il_host, ip->il_impno);
		}
E 4
I 4
D 12
		if (sc->imp_state != IMPS_INIT)
E 12
I 12
D 23
		if (sc->imp_state != IMPS_INIT || --sc->imp_dropcnt > 0)
E 23
I 23
D 67
		if (sc->imp_state == IMPS_INIT && --sc->imp_dropcnt > 0)
E 23
E 12
D 11
			goto drop;
E 11
I 11
D 19
			goto rawlinkin;
E 19
I 19
D 64
			goto drop;
E 64
I 64
			break;
E 64
I 23
D 57
		sin = (struct sockaddr_in *)&sc->imp_if.if_addr;
D 56
		if (sin->sin_addr.s_host != ip->il_host ||
		    sin->sin_addr.s_imp != ip->il_imp) {
			sc->imp_if.if_host[0] =
				sin->sin_addr.s_host = ip->il_host;
			sin->sin_addr.s_imp = ip->il_imp;
			impmsg(sc, "reset (host %d/imp %d)", (u_int)ip->il_host,
				ntohs(ip->il_imp));
E 56
I 56
		if( ip->il_imp != 0 )  {	/* BRL */
E 57
I 57
		sin = (struct sockaddr_in *)&sc->imp_if.if_addrlist->ifa_addr;
D 64
		if (ip->il_imp != 0) {	/* BRL */
E 64
I 64
		if (ip->il_imp != 0) {
E 67
I 67
		sc->imp_dropcnt++;
		if (sc->imp_state == IMPS_INIT && cp->dl_imp != 0) {
E 67
E 64
E 57
			struct in_addr leader_addr;
I 64

E 64
D 57
			imp_leader_to_addr( &leader_addr, ip, &sc->imp_if );
			if( sin->sin_addr.s_addr != leader_addr.s_addr )  {
				impmsg(sc, "address x%x (%d/%d)",
					htonl( leader_addr.s_addr ),
E 57
I 57
D 67
			imp_leader_to_addr(&leader_addr, ip, &sc->imp_if);
E 67
I 67
			sin = (struct sockaddr_in *)&sc->imp_if.if_addrlist->ifa_addr;
			imp_leader_to_addr(&leader_addr, cp, &sc->imp_if);
E 67
			if (sin->sin_addr.s_addr != leader_addr.s_addr) {
				impmsg(sc, "address reset to x%x (%d/%d)",
D 64
					htonl(leader_addr.s_addr),
E 64
I 64
					ntohl(leader_addr.s_addr),
E 64
E 57
D 67
					(u_int)ip->il_host,
D 57
					htons(ip->il_imp) );
E 57
I 57
D 64
					htons(ip->il_imp));
E 64
I 64
					ntohs(ip->il_imp));
E 67
I 67
					(u_int)cp->dl_host,
					ntohs(cp->dl_imp));
E 67
E 64
E 57
				sin->sin_addr.s_addr = leader_addr.s_addr;
I 74
#if NNETMON > 0
				netmon_ifevent(ifp);
#endif
E 74
D 57
				sc->imp_if.if_host[0] = in_lnaof( leader_addr.s_addr );
E 57
			}
E 56
		}
E 23
E 19
E 11
D 12
		if (--sc->imp_dropcnt > 0)
D 11
			goto drop;
E 11
I 11
			goto rawlinkin;
E 12
E 11
D 67
		sc->imp_state = IMPS_UP;
D 20
		sin = &sc->imp_if.if_addr;
		sc->imp_if.if_host[0] = sin->s_host = ip->il_host;
		sin->s_imp = ip->il_imp;
E 20
I 20
		sc->imp_if.if_flags |= IFF_UP;
E 67
I 37
D 57
		if_rtinit(&sc->imp_if, RTF_UP);
E 57
E 37
I 35
D 36
#ifdef notdef
E 35
D 23
		sin = (struct sockaddr_in *)&sc->imp_if.if_addr;
		sc->imp_if.if_host[0] = sin->sin_addr.s_host = ip->il_host;
		sin->sin_addr.s_imp = ip->il_imp;
E 20
D 8
		imperr(sc, "reset (host %d/imp %d)", ip->il_host,
E 8
I 8
D 14
		impmsg(sc, "reset (host %d/imp %d)", ip->il_host,
E 14
I 14
		impmsg(sc, "reset (host %d/imp %d)", (u_int)ip->il_host,
E 14
E 8
			ntohs(ip->il_imp));
E 23
		/* restart output in case something was q'd */
D 35
		(*sc->imp_cb.ic_start)(sc->imp_if.if_unit);
E 35
I 35
		if (sc->imp_cb.ic_oactive == 0)
			(*sc->imp_cb.ic_start)(sc->imp_if.if_unit);
#endif
E 36
E 35
E 4
D 11
		goto drop;
E 11
I 11
D 19
		goto rawlinkin;
E 19
I 19
D 64
		goto drop;
E 64
I 64
		break;
E 64
E 19
E 11
I 4
D 10
		}
E 10
I 10
D 20
	}
E 20
E 10
E 4

	/*
D 26
	 * RFNM or INCOMPLETE message, record in
	 * host table and prime output routine.
	 *
D 3
	 * SHOULD RETRANSMIT ON INCOMPLETE.
E 3
I 3
	 * SHOULD NOTIFY PROTOCOL ABOUT INCOMPLETES.
E 26
I 26
D 68
	 * RFNM or INCOMPLETE message, send next
	 * message on the q.  We could pass incomplete's
	 * up to the next level, but this currently isn't
	 * needed.
E 68
I 68
	 * RFNM or INCOMPLETE message, decrement rfnm count
	 * and prepare to send next message.
I 69
	 * If the rfnm allows another queued
	 * message to be sent, bump msgready
	 * and start IMP if idle.
E 69
	 * We could pass incomplete's up to the next level,
	 * but this currently isn't needed.
D 69
	 * Pass "bad" incompletes and rfnms to the log.
E 69
I 69
	 * Pass "bad" incompletes and rfnms to the raw socket.
E 69
E 68
E 26
E 3
	 */
D 67
	case IMPTYPE_RFNM:
E 67
	case IMPTYPE_INCOMPLETE:
D 8
		if (hp && hp->h_rfnm) {
			register struct mbuf *n;

			hp->h_rfnm--;
			/* poke holding queue */
			if (n = hp->h_q) {
D 4
				if (n->m_act == n)
E 4
I 4
D 7
				if (n->m_next == n)
E 7
I 7
				if (n->m_act == n)
E 7
E 4
					hp->h_q = 0;
				else {
D 4
					n = n->m_act;
					hp->h_q->m_act = n->m_act;
E 4
I 4
D 7
					n = n->m_next;
					hp->h_q->m_next = n->m_next;
E 7
I 7
					n = n->m_act;
					hp->h_q->m_act = n->m_act;
E 7
E 4
				}
D 4
				(void) impsnd(n, sc);
E 4
I 4
				(void) impsnd(sc, n);
D 7
				break;
E 7
I 7
				goto rawlinkin;
E 7
E 4
			}
I 4
			if (hp->h_rfnm == 0)
				hostfree(hp);
E 4
		}
E 8
I 8
D 26
		if (hp && hp->h_rfnm)
			if (next = hostdeque(hp))
D 14
				(void) impsnd(sc, next);
E 14
I 14
				(void) impsnd(&sc->imp_if, next);
E 26
I 26
D 27
		if (hp && hp->h_rfnm && (next = hostdeque(hp)))
			(void) impsnd(&sc->imp_if, next);
E 27
I 27
D 67
		if (hp = hostlookup(addr)) {
I 60
			hp->h_timer = HOSTTIMER;
E 67
I 67
		sc->imp_incomplete++;
		/* FALL THROUGH */
	case IMPTYPE_RFNM:
D 69
		if (hp = hostlookup(cp->dl_imp, cp->dl_host, unit)) {
E 67
E 60
D 68
			if (hp->h_rfnm == 0)
E 68
I 68
			if (hp->h_rfnm == 0) {
E 68
D 67
				hp->h_flags &= ~HF_INUSE;
			else if (next = hostdeque(hp))
				(void) impsnd(&sc->imp_if, next);
		}
E 27
E 26
E 14
E 8
D 5
		break;
E 5
I 5
D 19
		goto rawlinkin;
E 19
I 19
		goto drop;
E 67
I 67
				sc->imp_badrfnm++;
D 68
			else if (--hp->h_rfnm == 0) {
				hostfree(hp);
				hp->h_timer = HOSTTIMER;
			} else {
				hp->h_timer = RFNMTIMER;
				HOST_DEQUE(hp, next);
				if (next)
					(void) impsnd(&sc->imp_if, next);
E 68
I 68
				break;
E 68
			}
I 68
			if (--hp->h_rfnm > 0) {
				hp->h_timer = RFNMTIMER;
				if (hp->h_qcnt) {
					/*
					 * If the rfnm allows another queued
					 * message to be sent, bump msgready
					 * and start IMP if idle.
					 */
					if (hp->h_qcnt >
					   IMP_MAXHOSTMSG - 1 - hp->h_rfnm)
						sc->imp_msgready++;
					if (sc->imp_cb.ic_oactive == 0)
						impstarthost(sc, hp);
				}
			} else if (hp->h_qcnt == 0)
E 69
I 69
D 72
		if ((hp = hostlookup(cp->dl_imp, cp->dl_host, unit)) == 0 ||
		    hp->h_rfnm == 0) {
E 72
I 72
		if ((hp = hostlookup((int)cp->dl_imp, (int)cp->dl_host,
		    unit)) == 0 || hp->h_rfnm == 0) {
E 72
			sc->imp_badrfnm++;
			if (hp)
E 69
				hostfree(hp);
D 69
			/* else messages on queue waiting their turn */
E 69
I 69
			break;
		}
		imprestarthost(sc, hp);
		if (cp->dl_mtype == IMPTYPE_RFNM)
E 69
E 68
			goto drop;
D 69
		} else
			sc->imp_badrfnm++;
E 69
		break;
E 67
E 19
E 5

	/*
	 * Host or IMP can't be reached.  Flush any packets
	 * awaiting transmission and release the host structure.
I 60
	 * Enqueue for notifying protocols at software interrupt time.
E 60
D 26
	 *
D 4
	 * HOW DO WE NOTIFY THE PROTOCOL?
	 * HOW DO WE AGE THE HOST STRUCTURE TO SAVE STATUS?
E 4
I 4
	 * TODO: NOTIFY THE PROTOCOL
E 26
E 4
	 */
	case IMPTYPE_HOSTDEAD:
I 4
D 8
		imperr(sc, "host dead");	/* XXX */
E 8
I 8
D 26
		impmsg(sc, "host dead");	/* XXX */
E 8
		goto common;			/* XXX */

	/* SHOULD SIGNAL ROUTING DAEMON */
E 26
E 4
D 27
	case IMPTYPE_HOSTUNREACH:
I 4
D 8
		imperr(sc, "host unreachable");	/* XXX */
E 8
I 8
D 26
		impmsg(sc, "host unreachable");	/* XXX */
E 8
	common:
E 4
		if (hp)
D 4
			h_free(hp);		/* won't work right */
E 4
I 4
			hostfree(hp);		/* won't work right */
E 26
I 26
		impnotify(ip->il_mtype, ip, hp);
E 27
I 27
D 50
	case IMPTYPE_HOSTUNREACH: {
		int s = splnet();
E 50
I 50
	case IMPTYPE_HOSTUNREACH:
E 50
D 42
		impnotify(ip->il_mtype, ip, hostlookup(addr));
E 42
I 42
D 60
		impnotify((int)ip->il_mtype, (struct control_leader *)ip,
D 56
		    hostlookup(addr));
E 56
I 56
D 57
		    hostlookup(addr), sc->imp_if);
E 57
I 57
		    hostlookup(addr), &sc->imp_if);
E 60
I 60
D 67
		if (hp = hostlookup(addr)) {
			hp->h_flags |= (1 << (int)ip->il_mtype);
E 67
I 67
D 72
		if (hp = hostlookup(cp->dl_imp, cp->dl_host, unit)) {
E 72
I 72
		if (hp = hostlookup((int)cp->dl_imp, (int)cp->dl_host, unit)) {
E 72
			hp->h_flags |= (1 << (int)cp->dl_mtype);
I 68
			sc->imp_msgready -=
			   MIN(hp->h_qcnt, IMP_MAXHOSTMSG - hp->h_rfnm);
E 68
			hp->h_rfnm = 0;
E 67
D 68
			hostfree(hp);
E 68
I 68
			hostflush(hp);
E 68
			hp->h_timer = HOSTDEADTIMER;
		}
E 60
E 57
E 56
E 42
D 50
		splx(s);
E 50
E 27
E 26
E 4
D 5
		break;
E 5
I 5
D 64
		goto rawlinkin;
E 64
I 64
		break;
E 64
I 27
D 50
	}
E 50
E 27
E 5

	/*
	 * Error in data.  Clear RFNM status for this host and send
	 * noops to the IMP to clear the interface.
	 */
D 27
	case IMPTYPE_BADDATA:
E 27
I 27
D 50
	case IMPTYPE_BADDATA: {
		int s;

E 50
I 50
	case IMPTYPE_BADDATA:
E 50
E 27
D 8
		imperr(sc, "data error");
E 8
I 8
		impmsg(sc, "data error");
E 8
D 27
		if (hp)
E 27
I 27
D 50
		s = splnet();
E 50
D 67
		if (hp = hostlookup(addr))
E 67
I 67
D 69
		if ((hp = hostlookup(cp->dl_imp, cp->dl_host, unit)) &&
		    hp->h_rfnm) {
E 69
I 69
D 72
		if (hp = hostlookup(cp->dl_imp, cp->dl_host, unit)) {
E 72
I 72
		if (hp = hostlookup((int)cp->dl_imp, (int)cp->dl_host, unit)) {
E 72
E 69
E 67
E 27
D 68
			hp->h_rfnm = 0;
I 67
			hostfree(hp);
E 68
I 68
			sc->imp_msgready -=
			   MIN(hp->h_qcnt, IMP_MAXHOSTMSG - hp->h_rfnm);
D 69
			hostrelease(hp);
E 69
I 69
			if (hp->h_rfnm)
				hostrelease(hp);
			else
				hostfree(hp);
E 69
E 68
		}
D 68
		sc->imp_garbage++;
E 68
E 67
I 27
D 50
		splx(s);
E 50
E 27
		impnoops(sc);
D 5
		break;
E 5
I 5
D 26
		goto rawlinkin;
E 26
I 26
D 64
		goto drop;
E 64
I 64
		break;
E 64
I 27
D 50
	}
E 50
E 27
E 26
E 5

	/*
D 3
	 * IMP reset complete.
E 3
I 3
	 * Interface reset.
E 3
	 */
	case IMPTYPE_RESET:
D 3
		if (sc->imp_state == IMPS_DOWN)
			sc->imp_state = IMPS_UP;
		else
			imperr(sc, "unexpected reset");
E 3
I 3
D 8
		imperr(sc, "interface reset");
E 8
I 8
D 67
		impmsg(sc, "interface reset");
E 67
I 67
#ifdef IMPINIT
		if (imptraceinit)
			log(imppri, "reset complete\n");
#endif
		if (sc->imp_state != IMPS_INIT) {
			impmsg(sc, "interface reset");
			impnoops(sc);
		}
E 67
I 56
D 57
		hostreset(sc->imp_if.if_net);	/* clear RFNM counts */
E 57
I 57
		/* clear RFNM counts */
I 68
		sc->imp_msgready = 0;
E 68
D 67
		hostreset(((struct in_ifaddr *)&sc->imp_if.if_addrlist)->ia_net);
E 57
E 56
E 8
D 4
		sc->imp_state = IMPS_RESET;
E 4
		impnoops(sc);
E 67
I 67
		hostreset(unit);
		if (sc->imp_state != IMPS_DOWN) {
			sc->imp_state = IMPS_UP;
			sc->imp_if.if_flags |= IFF_UP;
#ifdef IMPINIT
			if (imptraceinit)
				log(imppri, "IMP UP\n");
#endif
		}
I 74
#if NNETMON > 0
		netmon_ifevent(ifp);
#endif
E 74
E 67
E 3
D 11
		goto drop;
E 11
I 11
D 26
		goto rawlinkin;
E 26
I 26
D 64
		goto drop;
E 64
I 64
		break;
E 64
E 26
E 11

	default:
I 67
		sc->imp_garbage++;
E 67
		sc->imp_if.if_collisions++;		/* XXX */
D 11
		goto drop;
E 11
I 11
D 26
		goto rawlinkin;
E 26
I 26
D 64
		goto drop;
E 64
I 64
		break;
E 64
E 26
E 11
	}

D 64
	/*
D 17
	 * Queue on protocol's input queue.
E 17
I 17
	 * Data for a protocol.  Dispatch to the appropriate
	 * protocol routine (running at software interrupt).
	 * If this isn't a raw interface, advance pointer
	 * into mbuf past leader.
E 17
	 */
	switch (ip->il_link) {

D 60
#ifdef INET
E 60
	case IMPLINK_IP:
		m->m_len -= sizeof(struct imp_leader);
		m->m_off += sizeof(struct imp_leader);
D 18
		setipintr();
E 18
I 18
		schednetisr(NETISR_IP);
E 18
		inq = &ipintrq;
		break;
D 60
#endif
E 60

	default:
I 5
D 7
rawlinkin:
E 7
I 7
	rawlinkin:
E 64
I 64
D 67
rawlinkin:
E 67
	if (inq == &impintrq)
E 64
E 7
E 5
D 60
		impproto.sp_protocol = ip->il_link;
D 2
		impaddr.sin_addr.s_net = ip->il_network;
		impaddr.sin_addr.s_host = ip->il_host;
		impaddr.sin_addr.s_imp = ip->il_imp;
		raw_input(m, impproto, impaddr);
E 2
I 2
D 20
		impdst.sin_addr = sc->imp_if.if_addr;
E 20
I 20
D 57
		sin = (struct sockaddr_in *)&sc->imp_if.if_addr;
E 57
I 57
		sin = (struct sockaddr_in *)&sc->imp_if.if_addrlist->ifa_addr;
E 57
D 56
		impdst.sin_addr = sin->sin_addr;;
E 20
		impsrc.sin_addr.s_net = ip->il_network;
		impsrc.sin_addr.s_host = ip->il_host;
		impsrc.sin_addr.s_imp = ip->il_imp;
E 56
I 56
		impdst.sin_addr = sin->sin_addr;
D 57
		imp_leader_to_addr( &impsrc.sin_addr, ip, &sc->imp_if );
E 57
I 57
		imp_leader_to_addr(&impsrc.sin_addr, ip, &sc->imp_if);
E 57
E 56
D 4
		raw_input(m, impproto, impdst, impsrc);
E 4
I 4
D 14
		raw_input(m, &impproto, &impdst, &impsrc);
E 14
I 14
D 25
		raw_input(m, &impproto, (struct sockaddr *)&impdst,
		  (struct sockaddr *)&impsrc);
E 25
I 25
		raw_input(m, &impproto, (struct sockaddr *)&impsrc,
		  (struct sockaddr *)&impdst);
E 25
E 14
E 4
E 2
		return;
E 60
I 60
		schednetisr(NETISR_IMP);
D 64
		inq = &impintrq;
		break;
E 60
	}
E 64
I 60
	/*
	 * Re-insert interface pointer in the mbuf chain
	 * for the next protocol up.
	 */
I 64
	if (M_HASCL(m) && (mtod(m, int) & CLOFSET) < sizeof(struct ifnet *)) {
		struct mbuf *n;

		MGET(n, M_DONTWAIT, MT_HEADER);
		if (n == 0)
			goto drop;
		n->m_next = m;
		m = n;
		m->m_len = 0;
		m->m_off = MMINOFF + sizeof(struct ifnet  *);
	}
E 64
	m->m_off -= sizeof(struct ifnet *);
	m->m_len += sizeof(struct ifnet *);
	*(mtod(m, struct ifnet **)) = ifp;
I 64

E 64
E 60
I 15
D 68
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		goto drop;
E 68
I 68
	s = splimp();
	if (!IF_QFULL(inq)) {
		IF_ENQUEUE(inq, m);
		splx(s);
		return;
E 68
	}
E 15
D 68
	IF_ENQUEUE(inq, m);
	return;

E 68
I 68
	splx(s);
E 68
D 69
drop:
E 69
I 68
	IF_DROP(inq);
I 69
drop:
E 69
E 68
	m_freem(m);
I 67
#undef ip
E 67
}

I 3
/*
I 67
D 68
 * Restart output for a host that has timed out
 * while waiting for a RFNM.
 */
imprestarthost(hp)
	register struct host *hp;
{
	struct mbuf *next;

	hp->h_timer = RFNMTIMER;
	while (hp->h_rfnm < 8) {
		HOST_DEQUE(hp, next);
		if (next == 0)
			break;
		(void) impsnd(&imp_softc[hp->h_unit].imp_if, next);
	}
}

/*
E 68
E 67
 * Bring the IMP down after notification.
 */
impdown(sc)
	struct imp_softc *sc;
{
I 50
	int s = splimp();
E 50
I 15

I 27
D 38
COUNT(IMPDOWN);
E 38
E 27
E 15
D 67
	sc->imp_state = IMPS_DOWN;
I 20
D 26
	sc->imp_if.if_flags &= ~IFF_UP;
E 26
E 20
I 4
D 8
	imperr(sc, "marked down");
E 8
I 8
	impmsg(sc, "marked down");
I 27
D 57
	hostreset(sc->imp_if.if_net);
E 57
I 57
	hostreset(((struct in_ifaddr *)&sc->imp_if.if_addrlist)->ia_net);
E 57
E 27
E 8
E 4
D 26
	/* notify protocols with messages waiting? */
E 26
I 26
	if_down(&sc->imp_if);
E 67
I 67
	if (sc->imp_state == IMPS_GOINGDOWN) {
		sc->imp_state = IMPS_WINIT;
		impmsg(sc, "marked down");
I 69
		sc->imp_msgready = 0;
E 69
		hostreset(sc->imp_if.if_unit);
		if_down(&sc->imp_if);
	}
#ifdef IMPINIT
	else if (imptraceinit)
		log(imppri, "impdown, state now %d (ignored)\n", sc->imp_state);
I 74
#endif
#if NNETMON > 0
	netmon_ifevent(&sc->imp_if);
E 74
#endif
E 67
I 50
	splx(s);
E 50
E 26
}

E 3
D 62
/*VARARGS*/
E 62
I 62
/*VARARGS2*/
E 62
D 8
imperr(sc, fmt, a1, a2)
E 8
I 8
D 56
impmsg(sc, fmt, a1, a2)
E 56
I 56
D 72
impmsg(sc, fmt, a1, a2, a3)
E 72
I 72
impmsg(sc, fmt, a1)
E 72
E 56
E 8
	struct imp_softc *sc;
	char *fmt;
I 14
	u_int a1;
E 14
{
I 15

I 27
D 38
COUNT(IMPMSG);
E 38
E 27
E 15
D 67
	printf("imp%d: ", sc->imp_if.if_unit);
D 56
	printf(fmt, a1, a2);
E 56
I 56
	printf(fmt, a1, a2, a3);
E 56
	printf("\n");
E 67
I 67
	log(imppri, "imp%d: %r\n", sc->imp_if.if_unit, fmt, &a1);
E 67
}

I 60
struct sockproto impproto = { PF_IMPLINK };
struct sockaddr_in impdst = { AF_IMPLINK };
struct sockaddr_in impsrc = { AF_IMPLINK };

E 60
/*
I 26
D 60
 * Process an IMP "error" message, passing this
 * up to the higher level protocol.
E 60
I 60
 * Pick up the IMP "error" messages enqueued earlier,
 * passing these up to the higher level protocol
 * and the raw interface.
E 60
 */
D 56
impnotify(what, cp, hp)
E 56
I 56
D 60
impnotify(what, cp, hp, ifp)
E 56
	int what;
	struct control_leader *cp;
	struct host *hp;
I 56
	struct ifnet *ifp;		/* BRL */
E 60
I 60
impintr()
E 60
E 56
{
D 60
	struct in_addr in;
E 60
I 60
	register struct mbuf *m;
	register struct control_leader *cp;
	struct ifnet *ifp;
	int s;
E 60

I 27
D 38
COUNT(IMPNOTIFY);
E 38
E 27
D 56
#ifdef notdef
	in.s_net = cp->dl_network;
#else
D 27
	in.s_net = 10;
E 27
I 27
	in.s_net = 10;			/* XXX */
E 27
#endif
	in.s_host = cp->dl_host;
	in.s_imp = cp->dl_imp;
E 56
I 56
D 57
	imp_leader_to_addr( &in, (struct imp_leader *) cp, ifp );  /* BRL */
E 57
I 57
D 60
	imp_leader_to_addr(&in, (struct imp_leader *)cp, ifp);  /* BRL */
E 60
I 60
	for (;;) {
		s = splimp();
		IF_DEQUEUEIF(&impintrq, m, ifp);
		splx(s);
		if (m == 0)
			return;
E 60
E 57

E 56
D 60
	if (cp->dl_link != IMPLINK_IP)
		raw_ctlinput(what, (caddr_t)&in);
	else
D 58
		ip_ctlinput(what, (caddr_t)&in);
E 58
I 58
		pfctlinput(what, (caddr_t)&in);
E 58
D 27
	if (hp)
E 27
I 27
	if (hp) {
		hp->h_flags |= (1 << what);
E 27
		hostfree(hp);
I 56
		hp->h_timer = HOSTDEADTIMER;
E 60
I 60
		cp = mtod(m, struct control_leader *);
D 67
		imp_leader_to_addr(&impsrc.sin_addr, (struct imp_leader *)cp,
		    ifp);
E 67
I 67
		imp_leader_to_addr(&impsrc.sin_addr, cp, ifp);
E 67
		impproto.sp_protocol = cp->dl_link;
D 61
		impdst.sin_addr = IA_SIN(ifp->if_addrlist->ifa_addr)->sin_addr;
E 61
I 61
		impdst.sin_addr = IA_SIN(ifp->if_addrlist)->sin_addr;
E 61

D 64
		switch (cp->dl_link) {
E 64
I 64
		if (cp->dl_mtype == IMPTYPE_HOSTDEAD ||
		    cp->dl_mtype == IMPTYPE_HOSTUNREACH)
			switch (cp->dl_link) {
E 64

D 64
		case IMPLINK_IP:
D 62
			pfctlinput(cp->dl_mtype, (caddr_t)&impsrc);
E 62
I 62
			pfctlinput((int)cp->dl_mtype,
			    (struct sockaddr *)&impsrc);
E 62
			break;
		default:
D 62
			raw_ctlinput(cp->dl_mtype, (caddr_t)&impsrc);
E 62
I 62
			raw_ctlinput((int)cp->dl_mtype,
			    (struct sockaddr *)&impsrc);
E 62
			break;
		}
E 64
I 64
			case IMPLINK_IP:
				pfctlinput((int)cp->dl_mtype,
				    (struct sockaddr *)&impsrc);
				break;
			default:
				raw_ctlinput((int)cp->dl_mtype,
				    (struct sockaddr *)&impsrc);
				break;
			}
E 64

		raw_input(m, &impproto, (struct sockaddr *)&impsrc,
		  (struct sockaddr *)&impdst);
E 60
E 56
I 27
	}
E 27
}

/*
E 26
 * ARPAnet 1822 output routine.
 * Called from higher level protocol routines to set up messages for
 * transmission to the imp.  Sets up the header and calls impsnd to
 * enqueue the message for this IMP's hardware driver.
 */
D 20
impoutput(ifp, m0, pf)
E 20
I 20
impoutput(ifp, m0, dst)
E 20
	register struct ifnet *ifp;
	struct mbuf *m0;
I 20
	struct sockaddr *dst;
E 20
{
	register struct imp_leader *imp;
	register struct mbuf *m = m0;
I 69
	caddr_t pkt = mtod(m, caddr_t);
E 69
D 4
	int x, dhost, dimp, dlink, len;
E 4
I 4
D 13
	int x, dhost, dimp, dlink, len, dnet;
E 13
I 13
D 16
	int x, dhost, dimp, dlink, len;
E 16
I 16
D 43
	int x, dhost, dimp, dlink, len, dnet;
E 43
I 43
D 57
	int dhost, dimp, dlink, len, dnet;
E 57
I 57
D 68
	int dlink, len;
E 68
E 57
E 43
I 24
	int error = 0;
E 24
E 16
E 13
E 4

I 4
D 38
COUNT(IMPOUTPUT);
E 38
D 5
printf("impoutput(%x, %x, %x)\n", ifp, m0, pf);

E 5
D 10
#ifdef notdef
E 10
E 4
	/*
	 * Don't even try if the IMP is unavailable.
	 */
D 3
	if (imp_softc[ifp->if_unit].imp_state == IMPS_DOWN) {
		m_freem(m0);
		return (0);
	}
E 3
I 3
D 22
	x = imp_softc[ifp->if_unit].imp_state;
	if (x == IMPS_DOWN || x == IMPS_GOINGDOWN)
E 22
I 22
D 24
	if (imp_softc[ifp->if_unit].imp_state != IMPS_UP)
E 24
I 24
D 67
	if (imp_softc[ifp->if_unit].imp_state != IMPS_UP) {
E 67
I 67
	if (!IMPS_RUNNING(imp_softc[ifp->if_unit].imp_state)) {
E 67
		error = ENETDOWN;
E 24
E 22
		goto drop;
I 24
	}
E 24
I 4
D 10
#endif
E 10
E 4
E 3

D 20
	switch (pf) {
E 20
I 20
D 68
	switch (dst->sa_family) {
E 68
I 68
	/*
	 * If AF_IMPLINK, leader exists; just send.
	 * Otherwise, construct leader according to address family.
	 */
	if (dst->sa_family != AF_IMPLINK) {
		/*
		 * Add IMP leader.  If there's not enough space in the
		 * first mbuf, allocate another.  If that should fail, we
		 * drop this sucker.
		 */
		if (m->m_off > MMAXOFF ||
		    MMINOFF + sizeof(struct imp_leader) > m->m_off) {
D 69
			m = m_get(M_DONTWAIT, MT_HEADER);
E 69
I 69
			MGET(m, M_DONTWAIT, MT_HEADER);
E 69
			if (m == 0) {
				error = ENOBUFS;
				goto drop;
			}
			m->m_next = m0;
			m->m_len = sizeof(struct imp_leader);
		} else {
			m->m_off -= sizeof(struct imp_leader);
			m->m_len += sizeof(struct imp_leader);
		}
		imp = mtod(m, struct imp_leader *);
		imp->il_format = IMP_NFF;
		imp->il_mtype = IMPTYPE_DATA;
D 69
		imp->il_flags = imp->il_htype = imp->il_subtype = 0;
E 69
I 69
		imp->il_flags = 0;
		imp->il_htype = 0;
		imp->il_subtype = 0;
E 69
E 68
E 20

D 60
#ifdef INET
E 60
D 20
	case PF_INET: {
		register struct ip *ip = mtod(m0, struct ip *);
E 20
I 20
D 68
	case AF_INET: {
D 60
		struct ip *ip = mtod(m0, struct ip *);
		struct sockaddr_in *sin = (struct sockaddr_in *)dst;
E 60
I 60
		struct ip *ip = mtod(m, struct ip *);
E 68
I 68
		switch (dst->sa_family) {
E 68
E 60
E 20

I 4
D 13
		dnet = ip->ip_dst.s_net;
E 13
E 4
D 20
		dhost = ip->ip_dst.s_host;
D 16
		dimp = ip->ip_dst.s_imp;
E 16
I 16
		dimp = ip->ip_dst.s_impno;
E 20
I 20
D 57
		dhost = sin->sin_addr.s_host;
		dimp = sin->sin_addr.s_impno;
E 57
E 20
E 16
D 68
		dlink = IMPLINK_IP;
I 16
D 57
		dnet = 0;
E 57
E 16
D 14
		len = ntohs(ip->ip_len);
E 14
I 14
		len = ntohs((u_short)ip->ip_len);
E 14
I 4
D 5
printf("impoutput: net=%d,host=%d,imp=%d,len=%d\n",dnet,dhost,dimp,len);
E 5
E 4
		break;
	}
E 68
I 68
D 69
		case AF_INET: {
			struct ip *ip = mtod(m, struct ip *);
E 68
D 60
#endif
E 60
I 60

E 69
I 69
		case AF_INET:
E 69
E 60
D 20
	case PF_IMPLINK:
E 20
I 20
D 68
	case AF_IMPLINK:
I 60
		len = 0;
		do
			len += m->m_len;
		while (m = m->m_next);
		m = m0;
E 60
E 20
		goto leaderexists;
E 68
I 68
			imp->il_link = IMPLINK_IP;
			imp_addr_to_leader((struct control_leader *)imp,
				((struct sockaddr_in *)dst)->sin_addr.s_addr);
D 69
			imp->il_length = htons(ntohs((u_short)ip->ip_len) << 3);
E 69
I 69
			imp->il_length = htons(ntohs((u_short)
			    ((struct ip *)pkt)->ip_len) << 3);
E 69
			break;
D 69
		}
E 69
E 68

D 68
	default:
D 20
		printf("imp%d: can't encapsulate pf%d\n", ifp->if_unit, pf);
E 20
I 20
		printf("imp%d: can't handle af%d\n", ifp->if_unit, 
			dst->sa_family);
I 24
		error = EAFNOSUPPORT;
E 24
E 20
D 3
		m_freem(m0);
		return (0);
E 3
I 3
		goto drop;
E 3
	}

	/*
	 * Add IMP leader.  If there's not enough space in the
	 * first mbuf, allocate another.  If that should fail, we
	 * drop this sucker.
	 */
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof(struct imp_leader) > m->m_off) {
D 46
		m = m_get(M_DONTWAIT);
E 46
I 46
		m = m_get(M_DONTWAIT, MT_HEADER);
E 46
D 3
		if (m == 0) {
			m_freem(m0);
			return (0);
		}
E 3
I 3
D 24
		if (m == 0)
E 24
I 24
		if (m == 0) {
			error = ENOBUFS;
E 68
I 68
		default:
			printf("imp%d: can't handle af%d\n", ifp->if_unit, 
				dst->sa_family);
			error = EAFNOSUPPORT;
I 69
			m0 = m;
E 69
E 68
E 24
			goto drop;
I 24
		}
E 24
E 3
D 68
		m->m_next = m0;
D 39
		m->m_off = MMINOFF;
E 39
		m->m_len = sizeof(struct imp_leader);
	} else {
		m->m_off -= sizeof(struct imp_leader);
		m->m_len += sizeof(struct imp_leader);
E 68
	}
D 68
	imp = mtod(m, struct imp_leader *);
	imp->il_format = IMP_NFF;
I 5
	imp->il_mtype = IMPTYPE_DATA;
I 7
D 13
#ifdef notdef
E 7
E 5
I 4
	imp->il_network = dnet;
I 7
#else
E 13
D 16
	imp->il_network = 0;
E 16
I 16
D 56
	imp->il_network = dnet;
E 16
D 13
#endif
E 13
E 7
E 4
	imp->il_host = dhost;
D 4
	imp->il_impno = dimp;
	imp->il_length = (len + sizeof(struct imp_leader)) << 3;
E 4
I 4
D 16
	imp->il_imp = dimp;
E 16
I 16
	imp->il_imp = htons((u_short)dimp);
E 16
D 14
	imp->il_length = htons((len + sizeof(struct imp_leader)) << 3);
E 14
I 14
	imp->il_length =
		htons((u_short)(len + sizeof(struct imp_leader)) << 3);
E 56
I 56
D 67
	imp_addr_to_leader(imp,
E 67
I 67
	imp_addr_to_leader((struct control_leader *)imp,
E 67
D 57
		((struct sockaddr_in *) dst)->sin_addr.s_addr ); /* BRL */
	imp->il_length = htons( (u_short) len << 3 );		/* BRL */
E 57
I 57
		((struct sockaddr_in *)dst)->sin_addr.s_addr); /* BRL */
	imp->il_length = htons((u_short)len << 3);		/* BRL */
E 57
E 56
E 14
E 4
	imp->il_link = dlink;
I 5
	imp->il_flags = imp->il_htype = imp->il_subtype = 0;
E 5

leaderexists:
E 68
D 26
	/*
	 * Hand message to impsnd to perform RFNM counting
	 * and eventual transmission.
	 */
E 26
	return (impsnd(ifp, m));
I 3
drop:
	m_freem(m0);
D 24
	return (0);
E 24
I 24
	return (error);
E 24
E 3
}

/* 
 * Put a message on an interface's output queue. 
 * Perform RFNM counting: no more than 8 message may be
 * in flight to any one host.
 */
impsnd(ifp, m)             
	struct ifnet *ifp;
	struct mbuf *m;
{
D 67
	register struct imp_leader *ip;
E 67
I 67
	register struct control_leader *imp;
E 67
	register struct host *hp;
D 68
	struct impcb *icp;
D 27
	int x;
E 27
I 27
	int s, error;
E 68
I 68
	register struct imp_softc *sc = &imp_softc[ifp->if_unit];
	int s, error = 0;
E 68
E 27

I 4
D 38
COUNT(IMPSND);
E 38
D 5
printf("impsnd(%x, %x)\n", ifp, m);
E 5
E 4
D 67
	ip = mtod(m, struct imp_leader *);
E 67
I 67
	imp = mtod(m, struct control_leader *);
E 67

	/*
	 * Do RFNM counting for data messages
D 68
	 * (no more than 8 outstanding to any host)
E 68
I 68
	 * (no more than 8 outstanding to any host).
	 * Queue data messages per host if 8 are already outstanding
	 * or if the hardware interface is already doing output.
	 * Increment imp_msgready if the message could be sent now,
	 * but must be queued because the imp output is busy.
E 68
	 */ 
I 12
D 27
	x = splimp();
E 27
I 27
	s = splimp();
E 27
E 12
D 67
	if (ip->il_mtype == IMPTYPE_DATA) {
		struct in_addr addr;

I 5
D 56
#ifdef notdef
E 5
D 4
                addr.s_net = ifp->if_net;
E 4
I 4
                addr.s_net = ip->il_network;
I 5
#else
D 27
		addr.s_net = 0;
E 27
I 27
		addr.s_net = ifp->if_net;	/* XXX */
E 27
#endif
E 5
E 4
                addr.s_host = ip->il_host;
                addr.s_imp = ip->il_imp;
E 56
I 56
D 57
		imp_leader_to_addr( &addr, ip, ifp );	/* BRL */
E 57
I 57
		imp_leader_to_addr(&addr, ip, ifp);	/* BRL */
E 57
E 56
I 5
D 12
		x = splimp();
E 12
E 5
D 4
        	hp = h_enter(addr);
E 4
I 4
		if ((hp = hostlookup(addr)) == 0)
			hp = hostenter(addr);
E 67
I 67
	if (imp->dl_mtype == IMPTYPE_DATA) {
D 72
		hp = hostenter(imp->dl_imp, imp->dl_host, ifp->if_unit);
E 72
I 72
		hp = hostenter((int)imp->dl_imp, (int)imp->dl_host,
		    ifp->if_unit);
E 72
E 67
I 27
D 69
		if (hp && (hp->h_flags & (HF_DEAD|HF_UNREACH))) {
D 30
#ifdef notdef
			error = hp->h_flags & HF_DEAD ?
				EHOSTDEAD : EHOSTUNREACH;
#else
			error = ENETUNREACH;
E 30
I 30
			error = hp->h_flags&HF_DEAD ? EHOSTDOWN : EHOSTUNREACH;
E 30
D 56
			hp->h_timer = HOSTTIMER;
E 56
I 56
D 60
			hp->h_timer = HOSTDEADTIMER;
E 60
E 56
D 68
			hp->h_flags &= ~HF_INUSE;
E 68
			goto bad;
D 30
#endif
E 30
		}
E 27
E 4

		/*
D 3
		 * If IMP would block, queue until rfnm
E 3
I 3
D 68
		 * If IMP would block, queue until RFNM
E 68
I 68
		 * If IMP would block, queue until RFNM;
		 * if IMP is busy, queue until our turn.
E 68
E 3
		 */
E 69
		if (hp) {
D 8
			register struct mbuf *n;
			int cnt;

E 8
D 56
			if (hp->h_rfnm < 8) {
E 56
I 56
D 60
#ifndef NORFNM					/* BRL */
E 60
I 60
D 67
#ifndef NORFNM
E 60
			if (hp->h_rfnm < 8)
#endif
			{
I 60
				hp->h_timer = HOSTTIMER;
E 60
E 56
				hp->h_rfnm++;
E 67
I 67
D 68
			if (hp->h_rfnm < 8) {
				if (hp->h_rfnm++ == 0)
					hp->h_timer = RFNMTIMER;
E 67
I 5
D 12
				splx(x);
E 12
E 5
				goto enque;
			}
D 8
			/*
			 * Keeping the count in the host structure
			 * causes the packing scheme to lose too much.
			 */
D 4
			cnt = 0, n = hp->h_q;
			for (; n != (struct mbuf *)hp; n = n->m_act)
				cnt++;
E 4
I 4
			cnt = 0;
			if (n = hp->h_q)
D 7
				for (; n != hp->h_q; n = n->m_next)
E 7
I 7
				do {
					n = n->m_act;
E 7
					cnt++;
I 7
				} while (n != hp->h_q);
E 7
E 4
			if (cnt >= 8)
E 8
I 8
D 12
			if (hp->h_qcnt >= 8)	/* high water mark */
E 8
				goto drop;
I 3
D 8

			/*
D 4
			 * Q is kept as circulare list with h_q
E 4
I 4
			 * Q is kept as circular list with h_q
E 4
			 * (head) pointing to the last entry.
			 */
E 3
			if ((n = hp->h_q) == 0)
D 4
				hp->h_q = m->m_act = m;
E 4
I 4
D 7
				hp->h_q = m->m_next = m;
E 7
I 7
				hp->h_q = m->m_act = m;
E 7
E 4
			else {
D 4
				m->m_act = n->m_act;
				hp->h_q = n->m_act = m;
E 4
I 4
D 7
				m->m_next = n->m_next;
				hp->h_q = n->m_next = m;
E 7
I 7
				m->m_act = n->m_act;
				hp->h_q = n->m_act = m;
E 7
E 4
			}
E 8
I 8
			HOST_ENQUE(hp, m);
E 8
I 5
			splx(x);
E 5
			goto start;
E 12
I 12
D 67
			if (hp->h_qcnt < 8) {	/* high water mark */
E 67
I 67
			if (hp->h_qcnt < imphqlen) {	/* high water mark */
E 68
I 68
D 69
			if (hp->h_rfnm < IMP_MAXHOSTMSG) {
				if (sc->imp_cb.ic_oactive == 0) {
					/*
					 * Send without queuing;
					 * adjust rfnm count and timer.
					 */
					if (hp->h_rfnm++ == 0)
					    hp->h_timer = RFNMTIMER;
					goto send;
				} else {
					sc->imp_msgready++;
					goto q;
				}
E 69
I 69
			if (hp->h_flags & (HF_DEAD|HF_UNREACH))
				error = hp->h_flags & HF_DEAD ?
				    EHOSTDOWN : EHOSTUNREACH;
			else if (hp->h_rfnm < IMP_MAXHOSTMSG &&
			    sc->imp_cb.ic_oactive == 0) {
				/*
				 * Send without queuing;
				 * adjust rfnm count and timer.
				 */
				if (hp->h_rfnm++ == 0)
				    hp->h_timer = RFNMTIMER;
				goto send;
E 69
			} else if (hp->h_rfnm + hp->h_qcnt < imphqlen) {
D 69
		q:
E 69
E 68
E 67
				HOST_ENQUE(hp, m);
I 69
				if (hp->h_rfnm + hp->h_qcnt <= IMP_MAXHOSTMSG)
					sc->imp_msgready++;
E 69
D 68
				goto start;
E 68
I 68
D 70
			} else
E 70
I 70
			} else {
E 70
				error = ENOBUFS;
I 70
				IF_DROP(&ifp->if_snd);
			}
E 70
		} else
			error = ENOBUFS;
	} else if (sc->imp_cb.ic_oactive == 0)
		goto send;
	else
		IF_ENQUEUE(&ifp->if_snd, m);
I 69

E 69
	splx(s);
D 69
	return (0);
E 69
I 69
	if (error)
		m_freem(m);
	return (error);
E 69

send:
	sc->imp_if.if_timer = IMP_OTIMER;
	(*sc->imp_cb.ic_output)(sc->imp_cb.ic_hwunit, m);
	splx(s);
	return (0);
D 69
bad:
	m_freem(m);
	splx(s);
	return (error);
E 69
}

/*
 * Start another output operation on IMP; called from hardware
 * transmit-complete interrupt routine at splimp or from imp routines
D 69
 * when output is not in progress and more output is ready.  If any packets
 * on shared output queue, send them, otherwise send the next data
 * packet for a host.  Host data packets are sent round-robin based
 * on destination.
E 69
I 69
 * when output is not in progress.  If there are any packets on shared
 * output queue, send them, otherwise send the next data packet for a host.
 * Host data packets are sent round-robin based on destination by walking
 * the host list.
E 69
 */
impstart(sc)
	register struct imp_softc *sc;
{
	register struct mbuf *m;
D 69
	struct mbuf *m0;
E 69
I 69
	int first = 1;				/* XXX */
E 69
	register struct host *hp;
	int index;

	IF_DEQUEUE(&sc->imp_if.if_snd, m);
	if (m) {
		sc->imp_if.if_timer = IMP_OTIMER;
		(*sc->imp_cb.ic_output)(sc->imp_cb.ic_hwunit, m);
		return;
	}
	if (sc->imp_msgready) {
		if ((m = sc->imp_hostq) == 0 && (m = sc->imp_hosts) == 0)
D 69
			panic ("imp msgready");
		if ((index = sc->imp_hostent) >= HPMBUF)
			index = 0;
		m0 = m;
		for (;;) {
			for (hp = &mtod(m, struct hmbuf *)->hm_hosts[index];
			    index < HPMBUF; hp++, index++) {
				if (hp->h_q && hp->h_rfnm < IMP_MAXHOSTMSG) {
					impstarthost(sc, hp);
					sc->imp_hostq = m;
					sc->imp_hostent = index;
					return;
				}
E 69
I 69
			panic("imp msgready");
		index = sc->imp_hostent;
		for (hp = &mtod(m, struct hmbuf *)->hm_hosts[index]; ;
		    hp++, index++) {
			if (index >= HPMBUF) {
				if ((m = m->m_next) == 0)
					m = sc->imp_hosts;
				index = 0;
				hp = mtod(m, struct hmbuf *)->hm_hosts;
				first = 0;		/* XXX */
E 69
E 68
			}
I 68
D 69
			if ((m = m->m_next) == 0)
				m = sc->imp_hosts;
			if (m == m0) {
				if (sc->imp_hostent != 0)
					sc->imp_hostent = 0;
				else {
					log(LOG_ERR,
					    "imp can't find %d msgready\n",
					    sc->imp_msgready);
					sc->imp_msgready = 0;
					break;
				}
E 69
I 69
			if (hp->h_qcnt && hp->h_rfnm < IMP_MAXHOSTMSG) {
				/*
				 * Found host entry with another message
				 * to send.  Deliver it to the IMP.
				 * Start with succeeding host next time.
				 */
				impstarthost(sc, hp);
				sc->imp_hostq = m;
				sc->imp_hostent = index + 1;
				return;
E 69
			}
D 69
			index = 0;
E 69
I 69
			if (m == sc->imp_hostq && !first &&
			    index + 1 >= sc->imp_hostent) {	/* XXX */
				log(imppri, "imp: can't find %d msgready\n",
				    sc->imp_msgready);
				sc->imp_msgready = 0;
				break;
			}
E 69
E 68
E 12
		}
D 13
drop:
E 13
D 27
		m_freem(m);
I 5
		splx(x);
E 5
D 24
		return (0);
E 24
I 24
		return (ENOBUFS);	/* XXX */
E 27
I 27
D 68
		error = ENOBUFS;
		goto bad;
E 68
E 27
E 24
	}
D 68
enque:
I 15
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
I 27
		error = ENOBUFS;
I 60
D 67
		if (ip->il_mtype == IMPTYPE_DATA)
E 67
I 67
		if (imp->dl_mtype == IMPTYPE_DATA)
E 67
			hp->h_rfnm--;
E 60
bad:
E 27
		m_freem(m);
D 27
		splx(x);
D 24
		return (0);
E 24
I 24
		return (ENOBUFS);	/* XXX */
E 27
I 27
		splx(s);
		return (error);
E 68
I 68
	sc->imp_if.if_timer = 0;
}

/*
D 69
 * Restart output for a host that has timed out
 * while waiting for a RFNM and has more packets to send.
E 69
I 69
 * Restart output for a host that has received a RFNM
 * or incomplete or has timed out while waiting for a RFNM.
E 69
 * Must be called at splimp.
 */
D 69
imprestarthost(unit, hp)
	int unit;
E 69
I 69
imprestarthost(sc, hp)
	register struct imp_softc *sc;
E 69
	struct host *hp;
{
D 69
	register struct imp_softc *sc = &imp_softc[unit];
E 69

D 69
	sc->imp_lostrfnm++;
E 69
	if (--hp->h_rfnm > 0)
		hp->h_timer = RFNMTIMER;
D 69
	if (hp->h_qcnt) {
		/*
		 * If the rfnm allows another queued
		 * message to be sent, bump msgready
		 * and start IMP if idle.
		 */
		if (hp->h_qcnt >
		   IMP_MAXHOSTMSG - 1 - hp->h_rfnm)
			sc->imp_msgready++;
E 69
I 69
	/*
	 * If the RFNM moved a queued message into the window,
	 * update msgready and start IMP if idle.
	 */
	if (hp->h_qcnt > IMP_MAXHOSTMSG - 1 - hp->h_rfnm) {
		sc->imp_msgready++;
E 69
		if (sc->imp_cb.ic_oactive == 0)
			impstarthost(sc, hp);
E 68
E 27
E 24
	}
I 69
	if (hp->h_rfnm == 0 && hp->h_qcnt == 0)
		hostidle(hp);
E 69
E 15
I 4
D 5
printleader("impsnd", mtod(m, struct imp_leader *));
E 5
E 4
D 12
        x = splimp();
E 12
D 68
	IF_ENQUEUE(&ifp->if_snd, m);
D 12
	splx(x);

E 12
start:
I 12
D 27
	splx(x);
E 27
I 27
D 31
	splx(s);
E 31
E 27
E 12
	icp = &imp_softc[ifp->if_unit].imp_cb;
	if (icp->ic_oactive == 0)
D 67
		(*icp->ic_start)(ifp->if_unit);
E 67
I 67
		(*icp->ic_start)(icp->ic_hwunit);
E 67
I 31
	splx(s);
E 31
D 24
	return (1);
E 24
I 24
	return (0);
E 68
E 24
}

/*
I 68
 * Send the next message queued for a host
 * when ready to send another message to the IMP.
 * Called only when output is not in progress.
 * Bump RFNM counter and start RFNM timer
 * when we send the message to the IMP.
 * Must be called at splimp.
 */
impstarthost(sc, hp)
	register struct imp_softc *sc;
	register struct host *hp;
{
	struct mbuf *m;

	if (hp->h_rfnm++ == 0)
		hp->h_timer = RFNMTIMER;
	HOST_DEQUE(hp, m);
	sc->imp_if.if_timer = IMP_OTIMER;
	(*sc->imp_cb.ic_output)(sc->imp_cb.ic_hwunit, m);
	sc->imp_msgready--;
}

/*
 * "Watchdog" timeout.  When the output timer expires,
 * we assume we have been blocked by the imp.
 * No need to restart, just collect statistics.
 */
imptimo(unit)
	int unit;
{

	imp_softc[unit].imp_block++;
}

/*
E 68
 * Put three 1822 NOOPs at the head of the output queue. 
 * Part of host-IMP initialization procedure.
 * (Should return success/failure, but noone knows
 * what to do with this, so why bother?)
I 32
 * This routine is always called at splimp, so we don't
 * protect the call to IF_PREPEND.
E 32
 */
impnoops(sc)             
	register struct imp_softc *sc;
{
	register i;
	register struct mbuf *m;
D 4
	register struct imp_leader *ip;
E 4
I 4
	register struct control_leader *cp;
E 4
D 43
	int x;
E 43

I 4
D 38
COUNT(IMPNOOPS);
E 38
E 4
D 23
	sc->imp_state = IMPS_INIT;
E 23
D 67
	sc->imp_dropcnt = IMP_DROPCNT;
D 4
	for (i = 0; i < IMP_DROPCNT; i++ ) { 
E 4
I 4
D 57
	for (i = 0; i < IMP_DROPCNT + 1; i++ ) { 
E 57
I 57
	for (i = 0; i < IMP_DROPCNT + 1; i++) { 
E 67
I 67
#ifdef IMPINIT
	if (imptraceinit)
		log(imppri, "impnoops\n");
#endif
	for (i = 0; i < IMP_NOOPCNT; i++) { 
E 67
E 57
E 4
D 46
		if ((m = m_getclr(M_DONTWAIT)) == 0) 
E 46
I 46
		if ((m = m_getclr(M_DONTWAIT, MT_HEADER)) == 0) 
E 46
			return;
D 39
		m->m_off = MMINOFF;
E 39
D 4
		m->m_len = sizeof(struct imp_leader);
		ip = mtod(m, struct imp_leader *);
		ip->il_format = IMP_NFF;
                ip->il_link = i;
                ip->il_mtype = IMPTYPE_NOOP;
E 4
I 4
		m->m_len = sizeof(struct control_leader);
		cp = mtod(m, struct control_leader *);
		cp->dl_format = IMP_NFF;
D 67
                cp->dl_link = i;
                cp->dl_mtype = IMPTYPE_NOOP;
E 67
I 67
		cp->dl_link = i;
		cp->dl_mtype = IMPTYPE_NOOP;
E 67
D 6
#ifdef notdef
		cp->dl_network = sc->imp_if.if_net;	/* XXX */
		cp->dl_host = sc->imp_if.if_addr.s_host;/* XXX */
		cp->dl_imp = sc->imp_if.if_addr.s_imp;	/* XXX */
#endif
E 6
D 5
printleader("impnoops", cp);
E 5
E 4
D 32
		x = splimp();
E 32
		IF_PREPEND(&sc->imp_if.if_snd, m);
D 32
		splx(x);
E 32
	}
	if (sc->imp_cb.ic_oactive == 0)
D 67
		(*sc->imp_cb.ic_start)(sc->imp_if.if_unit);
E 67
I 67
D 68
		(*sc->imp_cb.ic_start)(sc->imp_cb.ic_hwunit);
E 68
I 68
		impstart(sc);
E 68
E 67
I 52
}

/*
 * Process an ioctl request.
 */
impioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 57
	struct ifreq *ifr = (struct ifreq *)data;
	struct sockaddr_in *sin;
E 57
I 57
	struct ifaddr *ifa = (struct ifaddr *) data;
E 57
	int s = splimp(), error = 0;
I 67
#define sc	((struct imp_softc *)ifp)
E 67

	switch (cmd) {

	case SIOCSIFADDR:
D 57
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		sin = (struct sockaddr_in *)&ifr->ifr_addr;
		ifp->if_net = in_netof(sin->sin_addr);
		sin = (struct sockaddr_in *)&ifp->if_addr;
		sin->sin_family = AF_INET;
		/* host number filled in already, or filled in later */
		sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, RTF_UP);
		else
E 57
I 57
		if (ifa->ifa_addr.sa_family != AF_INET) {
			error = EINVAL;
			break;
		}
D 67
		if ((ifp->if_flags & IFF_RUNNING) == 0)
E 67
I 67
		if ((ifp->if_flags & IFF_UP) == 0)
E 67
E 57
			impinit(ifp->if_unit);
		break;

I 67
	case SIOCSIFFLAGS:
		if ((ifp->if_flags & IFF_UP) == 0 &&
		    sc->imp_state != IMPS_DOWN) {
D 68
			if (sc->imp_cb.ic_stop &&
			    (*sc->imp_cb.ic_stop)(sc->imp_cb.ic_hwunit))
E 68
I 68
			if (sc->imp_cb.ic_down &&
D 69
			    (*sc->imp_cb.ic_down)(sc->imp_cb.ic_hwunit))
E 69
I 69
			    (*sc->imp_cb.ic_down)(sc->imp_cb.ic_hwunit)) {
E 69
E 68
				sc->imp_state = IMPS_DOWN;
I 69
				sc->imp_msgready = 0;
				hostreset(ifp->if_unit);
I 70
				if_down(ifp);
E 70
			}
E 69
		} else if (ifp->if_flags & IFF_UP && sc->imp_state == IMPS_DOWN)
			impinit(ifp->if_unit);
		break;

E 67
	default:
		error = EINVAL;
I 67
		break;
E 67
	}
	splx(s);
	return (error);
E 52
I 4
}
I 35

#ifdef IMPLEADERS
printleader(routine, ip)
	char *routine;
	register struct imp_leader *ip;
{
	printf("%s: ", routine);
	printbyte((char *)ip, 12);
	printf("<fmt=%x,net=%x,flags=%x,mtype=", ip->il_format, ip->il_network,
		ip->il_flags);
	if (ip->il_mtype <= IMPTYPE_READY)
		printf("%s,", impleaders[ip->il_mtype]);
	else
		printf("%x,", ip->il_mtype);
	printf("htype=%x,host=%x,imp=%x,link=", ip->il_htype, ip->il_host,
		ntohs(ip->il_imp));
	if (ip->il_link == IMPLINK_IP)
		printf("ip,");
	else
		printf("%x,", ip->il_link);
	printf("subtype=%x,len=%x>\n",ip->il_subtype,ntohs(ip->il_length)>>3);
}

printbyte(cp, n)
	register char *cp;
	int n;
{
	register i, j, c;

	for (i=0; i<n; i++) {
		c = *cp++;
		for (j=0; j<2; j++)
D 60
			putchar("0123456789abcdef"[(c>>((1-j)*4))&0xf]);
		putchar(' ');
E 60
I 60
			putchar("0123456789abcdef"[(c>>((1-j)*4))&0xf], 0);
		putchar(' ', 0);
E 60
	}
D 60
	putchar('\n');
E 60
I 60
	putchar('\n', 0);
E 60
}
#endif
I 56

/*
 * Routine to convert from IMP Leader to InterNet Address.
 *
 * This procedure is necessary because IMPs may be assigned Class A, B, or C
 * network numbers, but only have 8 bits in the leader to reflect the
 * IMP "network number".  The strategy is to take the network number from
 * the ifnet structure, and blend in the host-on-imp and imp-on-net numbers
 * from the leader.
 *
 * There is no support for "Logical Hosts".
 *
 * Class A:	Net.Host.0.Imp
 * Class B:	Net.net.Host.Imp
 * Class C:	Net.net.net.(Host4|Imp4)
 */
D 57
imp_leader_to_addr( ap, ip, ifp )
register struct in_addr *ap;
register struct imp_leader *ip;
register struct ifnet *ifp;
E 57
I 57
D 67
imp_leader_to_addr(ap, ip, ifp)
E 67
I 67
imp_leader_to_addr(ap, cp, ifp)
E 67
	struct in_addr *ap;
D 67
	register struct imp_leader *ip;
E 67
I 67
	register struct control_leader *cp;
E 67
	struct ifnet *ifp;
E 57
{
D 62
	register long final;
E 62
I 62
	register u_long final;
E 62
I 57
D 60
	struct in_ifaddr *ia;
E 60
E 57
	register struct sockaddr_in *sin;
D 64
	int imp = htons(ip->il_imp);
E 64
I 64
D 67
	int imp = ntohs(ip->il_imp);
E 67
I 67
	int imp = ntohs(cp->dl_imp);
E 67
E 64

D 57
	sin = (struct sockaddr_in *) (&ifp->if_addr);
	final = htonl( sin->sin_addr.s_addr );		/* host order */
E 57
I 57
	sin = (struct sockaddr_in *)(&ifp->if_addrlist->ifa_addr);
D 64
	final = htonl(sin->sin_addr.s_addr);
E 64
I 64
	final = ntohl(sin->sin_addr.s_addr);
E 64
E 57

D 57
	if( IN_CLASSA( final ) )  {
E 57
I 57
	if (IN_CLASSA(final)) {
E 57
		final &= IN_CLASSA_NET;
D 67
		final |= (imp & 0xFF) | ((ip->il_host & 0xFF)<<16);
E 67
I 67
		final |= (imp & 0xFF) | ((cp->dl_host & 0xFF)<<16);
E 67
D 57
	} else if( IN_CLASSB( final ) )  {
E 57
I 57
	} else if (IN_CLASSB(final)) {
E 57
		final &= IN_CLASSB_NET;
D 67
		final |= (imp & 0xFF) | ((ip->il_host & 0xFF)<<8);
E 67
I 67
		final |= (imp & 0xFF) | ((cp->dl_host & 0xFF)<<8);
E 67
	} else {
		final &= IN_CLASSC_NET;
D 67
		final |= (imp & 0x0F) | ((ip->il_host & 0x0F)<<4);
E 67
I 67
		final |= (imp & 0x0F) | ((cp->dl_host & 0x0F)<<4);
E 67
	}
D 57
	ap->s_addr = htonl( final );
E 57
I 57
	ap->s_addr = htonl(final);
E 57
}

/*
 * Function to take InterNet address and fill in IMP leader fields.
 */
D 57
imp_addr_to_leader( imp, a )
register struct imp_leader *imp;
long a;
E 57
I 57
imp_addr_to_leader(imp, a)
D 67
	register struct imp_leader *imp;
E 67
I 67
	register struct control_leader *imp;
E 67
D 62
	long a;
E 62
I 62
	u_long a;
E 62
E 57
{
D 57
	register long addr = htonl( a );		/* host order */
E 57
I 57
D 62
	register long addr = htonl(a);		/* host order */
E 62
I 62
D 64
	register u_long addr = htonl(a);
E 64
I 64
	register u_long addr = ntohl(a);
E 64
E 62
E 57

D 67
	imp->il_network = 0;	/* !! */
E 67
I 67
	imp->dl_network = 0;	/* !! */
E 67

D 57
	if( IN_CLASSA( addr ) )  {
E 57
I 57
	if (IN_CLASSA(addr)) {
E 57
D 67
		imp->il_host = ((addr>>16) & 0xFF);
		imp->il_imp = addr & 0xFF;
E 67
I 67
		imp->dl_host = ((addr>>16) & 0xFF);
		imp->dl_imp = addr & 0xFF;
E 67
D 57
	} else if ( IN_CLASSB( addr ) )  {
E 57
I 57
	} else if (IN_CLASSB(addr)) {
E 57
D 67
		imp->il_host = ((addr>>8) & 0xFF);
		imp->il_imp = addr & 0xFF;
E 67
I 67
		imp->dl_host = ((addr>>8) & 0xFF);
		imp->dl_imp = addr & 0xFF;
E 67
	} else {
D 67
		imp->il_host = ((addr>>4) & 0xF);
		imp->il_imp = addr & 0xF;
E 67
I 67
		imp->dl_host = ((addr>>4) & 0xF);
		imp->dl_imp = addr & 0xF;
E 67
	}
D 62
	imp->il_imp = htons(imp->il_imp);	/* network order! */
E 62
I 62
D 67
	imp->il_imp = htons(imp->il_imp);
E 67
I 67
	imp->dl_imp = htons(imp->dl_imp);
E 67
E 62
}
E 56
E 35
D 26

I 5
#ifdef IMPLEADERS
E 5
printleader(routine, ip)
	char *routine;
	register struct imp_leader *ip;
{
	printf("%s: ", routine);
	printbyte((char *)ip, 12);
	printf("<fmt=%x,net=%x,flags=%x,mtype=", ip->il_format, ip->il_network,
		ip->il_flags);
	if (ip->il_mtype <= IMPTYPE_READY)
		printf("%s,", impleaders[ip->il_mtype]);
	else
		printf("%x,", ip->il_mtype);
	printf("htype=%x,host=%x,imp=%x,link=", ip->il_htype, ip->il_host,
D 16
		ip->il_impno);
E 16
I 16
		ntohs(ip->il_imp));
E 16
	if (ip->il_link == IMPLINK_IP)
		printf("ip,");
	else
		printf("%x,", ip->il_link);
	printf("subtype=%x,len=%x>\n",ip->il_subtype,ntohs(ip->il_length)>>3);
}

printbyte(cp, n)
	register char *cp;
	int n;
{
	register i, j, c;

	for (i=0; i<n; i++) {
		c = *cp++;
		for (j=0; j<2; j++)
			putchar("0123456789abcdef"[(c>>((1-j)*4))&0xf]);
		putchar(' ');
	}
	putchar('\n');
E 4
}
I 5
#endif
E 26
E 5
#endif
E 1
