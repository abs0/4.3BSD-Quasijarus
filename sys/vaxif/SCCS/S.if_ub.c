h64257
s 00000/00000/00562
d D 6.5 85/12/19 15:47:49 karels 38 37
c rm bbnnet
e
s 00007/00001/00555
d D 6.4 85/07/01 16:01:10 mckusick 37 36
c add copyright
e
s 00014/00014/00542
d D 6.3 84/08/29 20:44:20 bloom 36 35
c change ot includes.  no more ../h
e
s 00017/00017/00539
d D 6.2 84/08/29 16:37:14 bloom 35 34
c Changed name from un to ub to avoid header file name conflicts
e
s 00000/00000/00556
d D 6.1 83/07/29 07:38:37 sam 34 33
c 4.2 distribution
e
s 00004/00006/00552
d D 4.29 83/06/13 22:46:59 sam 33 32
c lint
e
s 00053/00010/00505
d D 4.28 83/06/12 23:33:31 sam 32 31
c ioctls
e
s 00001/00001/00514
d D 4.27 82/12/18 18:36:20 sam 31 30
c typed mbufs
e
s 00003/00004/00512
d D 4.26 82/12/17 12:14:27 sam 30 29
c sun merge
e
s 00001/00001/00515
d D 4.25 82/12/14 17:22:06 sam 29 28
c typed mbufs
e
s 00001/00001/00515
d D 4.24 82/10/31 15:05:41 root 28 27
c ubareset routines now just if_reset!
e
s 00013/00012/00503
d D 4.23 82/10/10 17:03:01 root 27 26
c put vax headers in their place
e
s 00008/00006/00507
d D 4.22 82/10/09 06:11:28 wnj 26 25
c fix includes
e
s 00005/00003/00508
d D 4.21 82/09/12 03:26:00 root 25 24
c time now a structure
e
s 00001/00001/00510
d D 4.20 82/07/20 13:16:28 feldman 24 23
c fix restart timeout to 5 min (was 5 hours!)
e
s 00002/00001/00509
d D 4.19 82/06/23 21:10:10 sam 23 22
c added watchdog routines
e
s 00004/00003/00506
d D 4.18 82/06/20 01:01:14 sam 22 21
c don't install route until we know address (for routed)
e
s 00000/00010/00509
d D 4.17 82/06/20 00:53:21 sam 21 20
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00518
d D 4.16 82/06/12 23:18:59 wnj 20 19
c now the routing code might wokr
e
s 00001/00000/00518
d D 4.15 82/05/21 13:22:00 feldman 19 18
c set broadcast OK flag
e
s 00010/00002/00508
d D 4.14 82/05/20 13:00:04 feldman 18 17
c added broadcast capability
e
s 00003/00001/00507
d D 4.13 82/04/20 14:02:37 sam 17 16
c make 3com kludge conditional
e
s 00001/00001/00507
d D 4.12 82/04/16 14:19:42 sam 16 15
c don't let driver sleep on interrupt stack if can't get bdp
e
s 00000/00032/00508
d D 4.11 82/04/11 13:51:07 sam 15 14
c purge debugging crap
e
s 00001/00000/00539
d D 4.10 82/04/11 02:39:06 feldman 14 13
c raise splimp for ec hack (temporary)
e
s 00006/00006/00533
d D 4.9 82/04/10 18:26:28 sam 13 12
c invert output path to pass back error indications
e
s 00012/00000/00527
d D 4.8 82/03/30 11:32:04 sam 12 11
c with routing, but not forwarding
e
s 00113/00162/00414
d D 4.7 82/03/28 14:22:12 sam 11 10
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00575
d D 4.6 82/03/19 01:49:00 wnj 10 9
c fix to use only one soft intr for net thereby fixing bug in raw sockets
e
s 00117/00110/00459
d D 4.5 82/03/15 04:43:52 wnj 9 8
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00007/00006/00562
d D 4.4 82/03/13 12:52:04 sam 8 7
c lint
e
s 00001/00002/00567
d D 4.3 82/03/12 16:13:48 sam 7 6
c lint bugs
e
s 00001/00000/00568
d D 4.2 82/03/09 20:00:51 wnj 6 5
c fix bug in tcp_input using m->m_off -= instead of m_drop
e
s 00075/00020/00493
d D 4.1 82/03/04 15:36:08 feldman 5 4
c gets host address from device (no longer compiled in!)
e
s 00005/00002/00508
d D 1.4 82/02/25 17:07:00 root 4 3
c changed host address for Arpavax
e
s 00088/00010/00422
d D 1.3 82/02/25 13:14:20 wnj 3 2
c restar code
e
s 00003/00001/00429
d D 1.2 82/02/07 02:17:43 root 2 1
c increased maximum packet size to 600 bytes (feldman)
e
s 00430/00000/00000
d D 1.1 82/02/05 23:36:24 root 1 0
c date and time created 82/02/05 23:36:24 by root
e
u
U
t
T
I 1
D 37
/*	%M%	%I%	%E%	*/
E 37
I 37
/*
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 37

I 30
D 35
#include "un.h"
#if NUN > 0
E 35
I 35
#include "ub.h"
#if NUB > 0
E 35
E 30
/*
 * Ungermann-Bass network/DR11-W interface driver
D 11
 */

I 5
/*
 * To do:
 *	Make bdp usage patchable variable
 *	Ditto for debugging
E 11
I 11
D 15
 *
 * TODO:
E 11
 *	Discard trace list?
E 15
I 6
D 13
 *	Add COUNT's?
E 13
E 6
 */
I 30
#include "../machine/pte.h"
E 30

E 5
D 30
#include "un.h"
#if NUN > 0

E 30
D 36
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 30
#include "../h/pte.h"
E 30
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
D 27
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/unreg.h"
#include "../h/cpu.h"
#include "../h/mtpr.h"
E 27
#include "../h/vmmac.h"
D 26
#include "../net/in.h"
#include "../net/in_systm.h"
E 26
I 26
D 27
#ifdef INET
E 27
I 27
D 33
#include <errno.h>
#include <time.h>
E 33
I 33
#include "../h/errno.h"
#include "../h/time.h"
E 33
#include "../h/kernel.h"
I 33
#include "../h/ioctl.h"
E 36
I 36
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "errno.h"
#include "time.h"
#include "kernel.h"
#include "ioctl.h"
E 36
E 33

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
E 27
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
D 27
#endif
E 26
#include "../net/if.h"
E 27
I 27

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
E 27
D 26
#include "../net/if_un.h"
#include "../net/if_uba.h"
#include "../net/ip.h"
#include "../net/ip_var.h"
E 26
I 26
D 35
#include "../vaxif/if_un.h"
I 27
#include "../vaxif/if_unreg.h"
E 35
I 35
D 36
#include "../vaxif/if_ub.h"
#include "../vaxif/if_ubreg.h"
E 35
E 27
#include "../vaxif/if_uba.h"
E 36
I 36
#include "if_ub.h"
#include "if_ubreg.h"
#include "if_uba.h"
E 36
E 26
I 12
D 27
#include "../net/route.h"
I 13
#include <errno.h>
I 25
#include <time.h>
#include "../h/kernel.h"
E 27
I 27
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 27
E 25
E 13
E 12

D 2
#define	UNMTU		(580-sizeof (struct un_header))
E 2
D 3
/* #define	UN_DEBUG	1 */
/* #define	UN_BDP		1 */
I 2

E 3
#define	UNMTU		(600-sizeof (struct un_header))
I 3
D 11
#define	UNMAXTIME	3		/* Interval for error counting */
#define	UNMAXERR	10		/* Errors allowed in interval */
#define	UNRESTART	(5*60)		/* Time until restart attempt */
E 11
E 3

I 4
D 5
/*
 * This is a kludgey way of getting the address.
 * I'll try to work something better out later.
 */
E 4
E 2
#ifdef OSCAR
D 3
#define	UNHOST		((2<<16) | 86)
#endif
E 3
I 3
#define	UNHOST		((2<<16) | 93)
D 4
/* #define	UNHOST		((2<<16) | 86) */
E 4
#endif /* OSCAR */
#ifdef ARPA
D 4
#define	UNHOST		((2<<16) | 93)
E 4
I 4
#define	UNHOST		((2<<16) | 86)
E 4
#endif /* ARPA */
E 5
I 5
D 11
/* #define	UN_BDP		1	/* Use buffered data path */
E 11
I 11
#define	US_NULL		0	/* not doing anything state */
#define	US_IDLE 	1	/* waiting to transfer state */
#define	US_READ		2	/* reading state */
#define	US_WRITE	3	/* writing state */
#define	US_RESET	4	/* waiting for reset state */
E 11
E 5
E 3

I 3
D 5
/* #define	UN_DEBUG	1 */
/* #define	UN_BDP		1 */
E 5
I 5
D 11
/* #define	UN_DEBUG	1	/* print event messages */
E 5

E 3
#define		US_NULL		0	/* not doing anything state */
#define		US_IDLE 	1	/* waiting to transfer state */
#define		US_READ		2	/* reading state */
#define		US_WRITE	3	/* writing state */
#define		US_RESET	4	/* waiting for reset state */

E 11
I 3
D 15
short undbx = 0;
short undb[256];
D 11
#define	UNDB(x)	undb[undbx++]=x; undbx&=0xff;
E 11
I 11
#define	UNDB(x) {undb[undbx++]=(x); undbx&=0xff;}
E 11

E 15
E 3
int	unprobe(), unattach(), unintr();
struct	uba_device *uninfo[NUN];
u_short	unstd[] = { 0 };
struct	uba_driver undriver =
D 35
	{ unprobe, 0, unattach, 0, unstd, "un", uninfo };
E 35
I 35
	{ unprobe, 0, unattach, 0, unstd, "ub", uninfo };
E 35
#define	UNUNIT(dev)	(minor(dev))

D 32
int	uninit(), unoutput(), unreset();
E 32
I 32
int	uninit(), unioctl(), unoutput(), unreset();
E 32
I 3
int	unrestart();
E 3

/*
 * Ungermann-Bass software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * us_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address,
 * etc.  We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct un_softc {
	struct	ifnet us_if;		/* network-visible interface */
	struct	ifuba us_ifuba;		/* UNIBUS resources */
	short	us_state;		/* device state */
I 3
D 11
	short	us_enabled;		/* set if unit enabled */
E 11
I 11
	short	us_errcnt;		/* number of errors since time set */
	short	us_restart;		/* restart interval */
	u_char	us_maxtime;		/* interval for error counting */
	u_char	us_maxerr;		/* errors allowed in interval */
E 11
	time_t	us_errtime;		/* time for error counting */
D 11
	int	us_errcnt;		/* number of errors since time set */
E 11
E 3
} un_softc[NUN];

D 11

E 11
/*
 * Cause an interrupt to determine interface presence and
 * interrupt vector.
 */
unprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct undevice *addr = (struct undevice *)reg;

I 12
D 21
COUNT(UNPROBE);
E 21
E 12
#ifdef lint
D 11
	br = 0; cvec = br; br = cvec;		/* Fool lint */
E 11
I 11
	br = 0; cvec = br; br = cvec;
E 11
	unintr(0);
#endif
D 11
#ifdef UN_DEBUG
	printf("un: probing\n");
#endif
D 9
	addr->csr = IE | UNRESET;		/* reset command */
	addr->csr = IE | UNRESET | GO;		/* start operation */
E 9
I 9
	addr->csr = IE|UNRESET;		/* reset command */
	addr->csr = IE|UNRESET|GO;		/* start operation */
E 9
	DELAY(100000);				/* wait for interrupt */
	addr->csr =  0;				/* clear control bits */
#ifdef UN_DEBUG
	printf("un: probe done (br=%x cvec=%o csr=%b dar=%o)\n",
		br, cvec, addr->csr, UNBITS, addr->dar&0177777);
#endif
D 9
	return(1);				/* Success return */
E 9
I 9
	return (1);				/* Success return */
E 11
I 11
	addr->csr = IE|UNRESET;
	addr->csr = IE|UNRESET|GO;
	DELAY(100000);
	addr->csr = 0;
I 14
D 17
	br = 0x16;		/* temporary ec hack */
E 17
I 17
D 33
#ifdef ECHACK
	br = 0x16;
#endif
E 33
E 17
E 14
	return (1);
E 11
E 9
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
unattach(ui)
	struct uba_device *ui;
{
	register struct un_softc *us = &un_softc[ui->ui_unit];
I 11
D 33
	struct sockaddr_in *sin;
E 33
E 11

I 12
D 21
COUNT(UNATTACH);
E 21
E 12
D 11
#ifdef UN_DEBUG
	printf("un%d: attach\n", UNUNIT(ui->ui_unit));
#endif
E 11
	us->us_if.if_unit = ui->ui_unit;
D 35
	us->us_if.if_name = "un";
E 35
I 35
	us->us_if.if_name = "ub";
E 35
	us->us_if.if_mtu = UNMTU;
D 32
	us->us_if.if_net = ui->ui_flags;
D 5
	us->us_if.if_host[0] = UNHOST;
	us->us_if.if_addr =
	    if_makeaddr(us->us_if.if_net, us->us_if.if_host[0]);
#ifdef UN_DEBUG
	printf("un%d: if_addr=%x\n", UNUNIT(ui->ui_unit), us->us_if.if_addr);
#endif
E 5
I 5
D 11
	us->us_if.if_addr = if_makeaddr(us->us_if.if_net, 0);
/*
 * host number will be filled in later.
 */
E 11
I 11
	sin = (struct sockaddr_in *)&us->us_if.if_addr;
	sin->sin_family = AF_INET;
	/* host number will be filled in later. */
	sin->sin_addr = if_makeaddr(us->us_if.if_net, 0);
I 18
	sin = (struct sockaddr_in *)&us->us_if.if_broadaddr;
	sin->sin_family = AF_INET;
D 22
	sin->sin_addr = if_makeaddr(us->us_if.if_net, 0);
E 22
I 22
	sin->sin_addr = if_makeaddr(us->us_if.if_net, INADDR_ANY);
E 22
I 19
	us->us_if.if_flags |= IFF_BROADCAST;
E 32
E 19
E 18
E 11
E 5
	us->us_if.if_init = uninit;
I 32
	us->us_if.if_ioctl = unioctl;
E 32
	us->us_if.if_output = unoutput;
D 28
	us->us_if.if_ubareset = unreset;
E 28
I 28
	us->us_if.if_reset = unreset;
E 28
I 23
	us->us_if.if_watchdog = unrestart;
E 23
D 11
#ifdef UN_BDP
E 11
I 11
	us->us_maxtime = 3;
	us->us_maxerr = 10;
D 24
	us->us_restart = 5 * 60 * hz;
E 24
I 24
	us->us_restart = 5 * 60;
E 24
I 22
	us->us_ifuba.ifu_flags = UBA_CANTWAIT;
E 22
#ifdef notdef
E 11
D 16
	us->us_ifuba.ifu_flags = UBA_NEEDBDP;
E 16
I 16
D 22
	us->us_ifuba.ifu_flags = UBA_NEEDBDP | UBA_CANTWAIT;
E 22
I 22
	us->us_ifuba.ifu_flags |= UBA_NEEDBDP;
E 22
E 16
#endif
	if_attach(&us->us_if);
}

/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
D 11

E 11
unreset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;

I 12
D 21
COUNT(UNRESET);
E 21
E 12
D 11
#ifdef UN_DEBUG
	printf("un%d: reset\n", unit);
#endif
E 11
	if (unit >= NUN || (ui = uninfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
D 35
	printf(" un%d", unit);
E 35
I 35
	printf(" ub%d", unit);
E 35
	uninit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
D 11

E 11
uninit(unit)
	int unit;
{
	register struct un_softc *us = &un_softc[unit];
	register struct uba_device *ui = uninfo[unit];
	register struct undevice *addr;
I 32
	struct sockaddr_in *sin;
E 32
	int s;

I 32
	sin = (struct sockaddr_in *)&us->us_if.if_addr;
	if (in_netof(sin->sin_addr) == 0)
		return;
E 32
I 12
D 21
COUNT(UNINIT);
E 21
E 12
D 11
#ifdef UN_DEBUG
	printf("un%d: init\n", unit);
#endif
E 11
	if (if_ubainit(&us->us_ifuba, ui->ui_ubanum,
	    sizeof (struct un_header), (int)btoc(UNMTU)) == 0) {
D 35
		printf("un%d: can't initialize\n", unit);
E 35
I 35
		printf("ub%d: can't initialize\n", unit);
E 35
I 11
		us->us_if.if_flags &= ~IFF_UP;
E 11
		return;
	}
I 32
	us->us_if.if_flags |= IFF_RUNNING;
E 32
D 11
	addr = (struct undevice *)ui->ui_addr;

I 3
	us->us_enabled = 1;
E 11
	us->us_errcnt = 0;
D 25
	us->us_errtime = time;
E 25
I 25
	us->us_errtime = time.tv_sec;
E 25
I 5
	unwhoami(unit);
I 11

E 11
E 5
E 3
	/*
	 * Reset U-B interface, thus causing an interrupt which
	 * will start things going.
	 */
I 11
	addr = (struct undevice *)ui->ui_addr;
E 11
	s = splimp();
D 9
	addr->csr = IE | UNRESET;		/* reset command */
	addr->csr = IE | UNRESET | GO;	/* start operation */
E 9
I 9
D 11
	addr->csr = IE|UNRESET;		/* reset command */
	addr->csr = IE|UNRESET|GO;	/* start operation */
E 11
I 11
	addr->csr = IE|UNRESET;
	addr->csr = IE|UNRESET|GO;
E 11
E 9
	us->us_state = US_RESET;
I 3
D 15
	UNDB(0x10|US_RESET);
E 15
E 3
	splx(s);
I 12
D 20
	if_rtinit(&us->us_if, RTF_DIRECT|RTF_UP);
E 20
I 20
D 22
	if_rtinit(&us->us_if, RTF_UP);
E 22
E 20
E 12
I 5
D 11
#ifdef UN_DEBUG
	printf("un%d: init exit\n", unit);
#endif
E 11
E 5
}

D 11

E 11
/*
 * Try to start a write operation.
 * If interface is busy, it must be in idle state, so issue a reset.
 * Otherwise, get the datagram from the output queue, map it onto
 * the UNIBUS, and start the write.  This routine should not be
 * called if the output queue is empty.
 */
unstart(dev)
	dev_t dev;
{
	int unit = UNUNIT(dev);
	struct uba_device *ui = uninfo[unit];
	register struct un_softc *us = &un_softc[unit];
	register struct undevice *addr = (struct undevice *)ui->ui_addr;
	struct mbuf *m;
	int dataaddr, datalen;
	register short cmdcsr;

I 12
D 21
COUNT(UNSTART);
E 21
E 12
D 11
#ifdef UN_DEBUG
	printf("un%d: start\n", unit);
#endif
E 11
I 11
D 15
	if (us->us_if.if_flags & IFF_DEBUG)
		printf("un%d: start\n", unit);
E 15
E 11
	if (us->us_state != US_NULL) {
D 9
		addr->csr = IE | UNRESET;
		addr->csr = IE | UNRESET | GO;
E 9
I 9
		addr->csr = IE|UNRESET;
		addr->csr = IE|UNRESET|GO;
E 9
		us->us_state = US_RESET;
I 3
D 15
		UNDB(0x20|US_RESET);
E 3
D 11
#ifdef UN_DEBUG
		printf("un%d: reset (write)\n", unit);
#endif
E 11
I 11
		if (us->us_if.if_flags & IFF_DEBUG)
			printf("un%d: reset (write)\n", unit);
E 15
E 11
	} else {
		IF_DEQUEUE(&us->us_if.if_snd, m);
D 11
		if (m == 0) {
			printf("un%d: output queue empty.\n");
E 11
I 11
		if (m == 0)
E 11
			return;
D 11
		}
E 11
		us->us_state = US_WRITE;
I 3
D 15
		UNDB(0x20|US_WRITE);
E 15
E 3
		datalen = if_wubaput(&us->us_ifuba, m);
D 11
#ifdef UN_BDP
		UBAPURGE(us->us_ifuba.ifu_uba, us->us_ifuba.ifu_w.ifrw_bdp);
#endif
E 11
I 11
		if (us->us_ifuba.ifu_flags & UBA_NEEDBDP)
			UBAPURGE(us->us_ifuba.ifu_uba,
				us->us_ifuba.ifu_w.ifrw_bdp);
E 11
		dataaddr = us->us_ifuba.ifu_w.ifrw_info;
		addr->bar = dataaddr & 0xffff;
		addr->wcr = -(((datalen + 1) >> 1) + 1);
D 9
		cmdcsr = ((dataaddr >> 12) & 0x30) | IE | UNOUT;
E 9
I 9
D 11
		cmdcsr = ((dataaddr >> 12) & 0x30)|IE|UNOUT;
E 11
I 11
		cmdcsr = ((dataaddr >> 12) & 0x30) | IE | UNOUT;
E 11
E 9
		addr->csr = cmdcsr;
D 9
		addr->csr = cmdcsr | GO;
E 9
I 9
D 11
		addr->csr = cmdcsr|GO;
E 9
#ifdef UN_DEBUG
		printf("un%d: write\n", unit);
#endif
E 11
I 11
		addr->csr = cmdcsr | GO;
D 15
		if (us->us_if.if_flags & IFF_DEBUG)
			printf("un%d: write\n", unit);
E 15
E 11
	}
}

/*
 * Ungermann-Bass interface interrupt handler.
 * Determines reason for interrupt and acts accordingly.
 */
unintr(unit)
	int unit;
{
	register struct un_softc *us = &un_softc[unit];
	struct undevice *addr = (struct undevice *)uninfo[unit]->ui_addr;
	register struct un_header *un;
	struct mbuf *m;
	int len;
	register struct ifqueue *inq;
	int cmdcsr;

I 12
D 21
COUNT(ININTR);
E 21
E 12
D 11
#ifdef UN_DEBUG
	printf("un%d: interrupt csr=%b dar=%o state=%d\n",
	    unit, addr->csr&0177777, UNBITS, addr->dar&0177777, us->us_state);
#endif
E 11
I 11
D 15
	if (us->us_if.if_flags & IFF_DEBUG)
		printf("un%d: interrupt csr=%b dar=%o state=%d\n",
		    unit, addr->csr&0xffff, UNBITS, addr->dar&0xffff,
		    us->us_state);
E 11
D 3
	if ((addr->dar & RESETACK) && us->us_state != US_RESET)
		printf("un%d: unexpected reset\n");
E 3
I 3
	UNDB(0x30|us->us_state);
E 15
	if ((addr->dar & RESETACK) && us->us_state != US_RESET) {
I 11
		if ((us->us_if.if_flags & IFF_UP) == 0)
			return;
E 11
D 35
		printf("un%d: unexpected reset\n", unit);
E 35
I 35
		printf("ub%d: unexpected reset\n", unit);
E 35
		unerror(unit);
D 11
		if (!us->us_enabled)
			return;
E 11
	}
E 3
		
	switch (us->us_state) {
D 9
		case US_NULL:
D 3
			printf("un%d: Unexpected interrupt");
E 3
I 3
			printf("un%d: Unexpected interrupt\n", unit);
E 3
			break;
E 9

D 9
		case US_RESET:
D 3
			if (!(addr->dar & RESETACK))
E 3
I 3
			if (!(addr->dar & RESETACK)) {
				addr->csr = IE | UNRESET;
				addr->csr = IE | UNRESET | GO;
E 3
				return;
I 3
			}
E 3
			break;
E 9
I 9
	case US_NULL:
D 11
		printf("un%d: Unexpected interrupt\n", unit);
E 11
I 11
D 35
		printf("un%d: stray interrupt\n", unit);
E 35
I 35
		printf("ub%d: stray interrupt\n", unit);
E 35
E 11
		break;
E 9

D 9
		case US_IDLE:
			break;
E 9
I 9
	case US_RESET:
		if (!(addr->dar & RESETACK)) {
			addr->csr = IE|UNRESET;
			addr->csr = IE|UNRESET|GO;
			return;
		}
		break;
E 9

D 9
		case US_READ:
			us->us_if.if_ipackets++;
E 9
I 9
	case US_IDLE:
		break;

	case US_READ:
		us->us_if.if_ipackets++;
E 9
D 11
#ifdef UN_BDP
D 9
			UBAPURGE(us->us_ifuba.ifu_uba,
			    us->us_ifuba.ifu_r.ifrw_bdp);
E 9
I 9
		UBAPURGE(us->us_ifuba.ifu_uba, us->us_ifuba.ifu_r.ifrw_bdp);
E 9
#endif
E 11
I 11
		if (us->us_ifuba.ifu_flags & UBA_NEEDBDP)
			UBAPURGE(us->us_ifuba.ifu_uba,
				us->us_ifuba.ifu_r.ifrw_bdp);
E 11
D 9
			if (addr->csr & STATA) {
				printf("un%d: input error csr=%b\n",
				    unit, addr->csr&0177777, UNBITS);
				us->us_if.if_ierrors++;
I 3
				unerror(unit);
				if (!us->us_enabled)
					return;
				break;
E 3
			}
			un = (struct un_header *)(us->us_ifuba.ifu_r.ifrw_addr);
			switch (un->un_ptype) {
E 9
I 9
		if (addr->csr & STATA) {
D 11
			printf("un%d: input error csr=%b\n",
			    unit, addr->csr&0177777, UNBITS);
E 11
I 11
			if ((us->us_if.if_flags & IFF_UP) == 0)
				return;
D 35
			printf("un%d: input error csr=%b\n", unit,
E 35
I 35
			printf("ub%d: input error csr=%b\n", unit,
E 35
				addr->csr&0xffff, UNBITS);
E 11
			us->us_if.if_ierrors++;
			unerror(unit);
D 11
			if (!us->us_enabled)
				return;
E 11
			break;
		}
		un = (struct un_header *)(us->us_ifuba.ifu_r.ifrw_addr);
		switch (un->un_ptype) {
E 9
#ifdef INET
D 5
				case PF_INET:
E 5
I 5
D 9
				case UNTYPE_IP:
E 5
					len = htons((u_short)
					    ((struct ip *) (un+1))->ip_len);
					setipintr();
					inq = &ipintrq;
					break;
E 9
I 9
		case UNTYPE_IP:
			len = htons((u_short)((struct ip *) (un+1))->ip_len);
D 10
			setipintr();
E 10
I 10
			schednetisr(NETISR_IP);
E 10
			inq = &ipintrq;
			break;
E 9
#endif
I 5
D 9
				case UNTYPE_INQUIRE:
					us->us_if.if_host[0] =
					    un->un_dport<<16
					        | htons(un->un_dniu);
					us->us_if.if_addr =
					    if_makeaddr(us->us_if.if_net,
					        us->us_if.if_host[0]);
					printf("un%d: net addr=%x\n",
					    unit, us->us_if.if_addr);
					goto setup;
E 9
I 9
D 11
		case UNTYPE_INQUIRE:
E 11
I 11
		case UNTYPE_INQUIRE: {
			struct sockaddr_in *sin;

E 11
			us->us_if.if_host[0] =
D 11
			    un->un_dport<<16|htons(un->un_dniu);
			us->us_if.if_addr =
			    if_makeaddr(us->us_if.if_net,us->us_if.if_host[0]);
			printf("un%d: net addr=%x\n", unit, us->us_if.if_addr);
E 11
I 11
			    un->un_dport << 16 | htons(un->un_dniu);
			sin = (struct sockaddr_in *)&us->us_if.if_addr;
			sin->sin_addr = if_makeaddr(us->us_if.if_net,
				us->us_if.if_host[0]);
			us->us_if.if_flags |= IFF_UP;
I 22
			if_rtinit(&us->us_if, RTF_UP);
E 22
D 15
			if (us->us_if.if_flags & IFF_DEBUG)
				printf("un%d: net addr=%x\n", unit,
					us->us_if.if_addr);
E 15
E 11
			goto setup;
I 11
		}
E 11
E 9

E 5
D 9
				default:
D 3
					printf("en%d: bad packet type %d\n",
E 3
I 3
					printf("un%d: bad packet type %d\n",
E 3
						un->un_ptype);
					goto setup;
			}
E 9
I 9
		default:
D 35
			printf("un%d: bad packet type %d\n", un->un_ptype);
E 35
I 35
			printf("ub%d: bad packet type %d\n", un->un_ptype);
E 35
			goto setup;
		}
E 9

D 9
			m = if_rubaget(&us->us_ifuba, len, 0);
			if (m != 0)
E 9
I 9
		m = if_rubaget(&us->us_ifuba, len, 0);
		if (m != 0)
			if (IF_QFULL(inq)) {
				IF_DROP(inq);
				m_freem(m);
			} else
E 9
				IF_ENQUEUE(inq, m);
D 9
			break;
E 9
I 9
		break;
E 9

D 9
		case US_WRITE:
			us->us_if.if_opackets++;
			if (addr->csr & STATA) {
				printf("un%d: output error csr=%b\n",
				    unit, addr->csr, UNBITS);
				us->us_if.if_oerrors++;
I 3
				unerror(unit);
				if (!us->us_enabled)
					return;
E 3
			}
			if (us->us_ifuba.ifu_xtofree) {
				m_freem(us->us_ifuba.ifu_xtofree);
D 7
				us->us_ifuba.ifu_xtofree == 0;
E 7
I 7
				us->us_ifuba.ifu_xtofree = 0;
E 7
			}
			break;
E 9
I 9
	case US_WRITE:
		us->us_if.if_opackets++;
		if (addr->csr & STATA) {
I 11
			if ((us->us_if.if_flags & IFF_UP) == 0)
				return;
E 11
D 35
			printf("un%d: output error csr=%b\n",
E 35
I 35
			printf("ub%d: output error csr=%b\n",
E 35
			    unit, addr->csr, UNBITS);
			us->us_if.if_oerrors++;
			unerror(unit);
D 11
			if (!us->us_enabled)
				return;
E 11
		}
		if (us->us_ifuba.ifu_xtofree) {
			m_freem(us->us_ifuba.ifu_xtofree);
			us->us_ifuba.ifu_xtofree = 0;
		}
		break;
E 9

D 9
		default:
			printf("un%d: invalid state %d csr=%b\n",
			    us->us_state, addr->csr, UNBITS);
E 9
I 9
	default:
D 35
		printf("un%d: invalid state %d csr=%b\n",
E 35
I 35
		printf("ub%d: invalid state %d csr=%b\n",
E 35
		    us->us_state, addr->csr, UNBITS);
E 9
	}

setup:
	us->us_state = US_NULL;
I 3
D 15
	UNDB(0x30|us->us_state);
E 15
E 3
	if (addr->csr & STATB) {
		us->us_state = US_READ;
I 3
D 15
		UNDB(0x30|us->us_state);
E 15
E 3
		addr->wcr = -((sizeof (struct un_header) + UNMTU + 1)/2+1);
		addr->bar = us->us_ifuba.ifu_r.ifrw_info & 0xffff;
D 11
		cmdcsr = ((us->us_ifuba.ifu_r.ifrw_info >> 12) & 0x30)
D 9
		     | IE | UNRDDG;
E 9
I 9
		    |IE|UNRDDG;
E 11
I 11
		cmdcsr = ((us->us_ifuba.ifu_r.ifrw_info >> 12) & 0x30);
		cmdcsr |= IE|UNRDDG;
E 11
E 9
		addr->csr = cmdcsr;
D 9
		addr->csr = cmdcsr | GO;
E 9
I 9
D 11
		addr->csr = cmdcsr|GO;
E 9
#ifdef UN_DEBUG
		printf("un%d: read\n", unit);
#endif
E 11
I 11
		addr->csr = cmdcsr | GO;
D 15
		if (us->us_if.if_flags & IFF_DEBUG)
			printf("un%d: read\n", unit);
E 15
E 11
	} else if (us->us_if.if_snd.ifq_head != 0 && (addr->csr & STATC))
		unstart(unit);
	
	if (us->us_state == US_NULL) {
		us->us_state = US_IDLE;
I 3
D 15
		UNDB(0x30|us->us_state);
E 15
E 3
D 9
		addr->csr = IE | UNIDLE;
		addr->csr = IE | UNIDLE | GO;
E 9
I 9
		addr->csr = IE|UNIDLE;
		addr->csr = IE|UNIDLE|GO;
E 9
D 11
#ifdef UN_DEBUG
		printf("un%d: idle\n", unit);
#endif
E 11
I 11
D 15
		if (us->us_if.if_flags & IFF_DEBUG)
			printf("un%d: idle\n", unit);
E 15
E 11
	}
}

/*
 * Ungermann-Bass output routine.
D 11
 * Encapsulate a packet of type family for the local net.
E 11
I 11
 * Encapsulate a packet destined for dst for the local net.
E 11
 */
D 9
unoutput(ipf, m0, pf)
	struct ifnet *ipf;
E 9
I 9
D 11
unoutput(ifp, m0, pf)
E 11
I 11
unoutput(ifp, m0, dst)
E 11
	struct ifnet *ifp;
E 9
	struct mbuf *m0;
D 11
	int pf;
E 11
I 11
	struct sockaddr *dst;
E 11
{
	int type, destniu, destport, len;
	register struct mbuf *m = m0;
	register struct un_header *un;
I 11
	register struct un_softc *us = &un_softc[ifp->if_unit];
E 11
	int s;

I 12
D 21
COUNT(UNOUTPUT);
E 21
E 12
D 11
#ifdef UN_DEBUG
D 9
		printf("un%d: output\n", ipf->if_unit);
E 9
I 9
	printf("un%d: output\n", ifp->if_unit);
E 9
#endif
I 3
D 9
	if (!un_softc[ipf->if_unit].us_enabled)
		return(0);
E 9
I 9
	if (!un_softc[ifp->if_unit].us_enabled)
E 11
I 11
	if ((us->us_if.if_flags & IFF_UP) == 0)
E 11
D 13
		return (0);
E 13
I 13
		return (ENETDOWN);
E 13
E 9
E 3
D 11
	switch (pf) {
E 11
I 11
	switch (dst->sa_family) {
E 11

#ifdef INET
D 9
		case PF_INET: {
			register struct ip *ip = mtod(m0, struct ip *);
E 9
I 9
D 11
	case PF_INET: {
		register struct ip *ip = mtod(m0, struct ip *);
E 11
I 11
	case AF_INET: {
		struct sockaddr_in *sin = (struct sockaddr_in *)dst;
		struct ip *ip = mtod(m, struct ip *);
E 11
E 9

D 9
			destniu = ip->ip_dst.s_addr >> 24;
			destport = (ip->ip_dst.s_addr >> 8) & 0xff;
			len = htons((u_short) ip->ip_len);
D 5
			type = PF_INET;
E 5
I 5
			type = UNTYPE_IP;
E 5
			break;
		}
E 9
I 9
D 11
		destniu = ip->ip_dst.s_addr >> 24;
		destport = (ip->ip_dst.s_addr >> 8) & 0xff;
E 11
I 11
D 18
		destniu = sin->sin_addr.s_addr >> 24;
		destport = (sin->sin_addr.s_addr >> 8) & 0xff;
E 18
I 18
		if (sin->sin_addr.s_addr & 0xffffff00) {
			destniu = sin->sin_addr.s_addr >> 24;
			destport = (sin->sin_addr.s_addr >> 8) & 0xff;
		} else {
			destniu = 0xffff;
			destport = 0xff;
		}
E 18
E 11
		len = htons((u_short) ip->ip_len);
		type = UNTYPE_IP;
		break;
	}
E 9
#endif
D 9
		default:
			printf("un%d: can't encapsulate pf%d\n",
			    ipf->if_unit, pf);
			m_freem(m0);
			return(0);
E 9
I 9
	default:
D 11
		printf("un%d: can't encapsulate pf%d\n", ifp->if_unit, pf);
E 11
I 11
D 35
		printf("un%d: can't handle af%d\n", ifp->if_unit,
E 35
I 35
		printf("ub%d: can't handle af%d\n", ifp->if_unit,
E 35
			dst->sa_family);
E 11
		m_freem(m0);
D 13
		return (0);
E 13
I 13
		return (EAFNOSUPPORT);
E 13
E 9
	}
	
	/*
	 * Add local net header.  If no space in first mbuf,
	 * allocate another.
	 */
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof (struct un_header) > m->m_off) {
D 29
		m = m_get(M_DONTWAIT);
E 29
I 29
		m = m_get(M_DONTWAIT, MT_HEADER);
E 29
		if (m == 0) {
			m_freem(m0);
D 9
			return(0);
E 9
I 9
D 13
			return (0);
E 13
I 13
			return (ENOBUFS);
E 13
E 9
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof (struct un_header);
	} else {
		m->m_off -= sizeof (struct un_header);
		m->m_len += sizeof (struct un_header);
	}
	un = mtod(m, struct un_header *);
D 8
	un->un_length = htons(len + sizeof (struct un_header));
E 8
I 8
D 11
	un->un_length =
		htons((u_short)(len + sizeof (struct un_header)));
E 8
	un->un_type = 0;
	un->un_control = 0;
D 8
	un->un_dnet = htons(0);
	un->un_dniu = htons(destniu);
E 8
I 8
	un->un_dnet = 0;
E 11
I 11
	bzero((caddr_t)un, sizeof (struct un_header));
	un->un_length = htons((u_short)(len + sizeof (struct un_header)));
E 11
	un->un_dniu = htons((u_short)destniu);
E 8
	un->un_dport = destport;
	un->un_dtype = 5;
D 8
	un->un_snet = htons(0);
	un->un_sniu = htons(ipf->if_host[0] >> 24);
E 8
I 8
D 11
	un->un_snet = 0;
E 11
D 9
	un->un_sniu = htons((u_short)(ipf->if_host[0] >> 24));
E 8
	un->un_sport = (ipf->if_host[0] >> 8) & 0xff;
E 9
I 9
	un->un_sniu = htons((u_short)(ifp->if_host[0] >> 24));
	un->un_sport = (ifp->if_host[0] >> 8) & 0xff;
E 9
	un->un_stype = 5;
D 11
	un->un_option = 0;
	un->un_bcc = 0;
E 11
	un->un_ptype = type;

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
D 9
	IF_ENQUEUE(&ipf->if_snd, m);
I 3
	UNDB(0x40|un_softc[ipf->if_unit].us_state);
E 3
	if (un_softc[ipf->if_unit].us_state == US_IDLE)
		unstart(ipf->if_unit);
E 9
I 9
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
D 11
		(void) m_freem(m);
E 11
I 11
		m_freem(m);
E 11
		splx(s);
D 13
		return (0);
E 13
I 13
		return (ENOBUFS);
E 13
	}
	IF_ENQUEUE(&ifp->if_snd, m);
D 11
	UNDB(0x40|un_softc[ifp->if_unit].us_state);
	if (un_softc[ifp->if_unit].us_state == US_IDLE)
E 11
I 11
D 15
	UNDB(0x40|us->us_state);
E 15
	if (us->us_state == US_IDLE)
E 11
		unstart(ifp->if_unit);
E 9
	splx(s);
D 9
	return(1);
E 9
I 9
D 13
	return (1);
E 13
I 13
	return (0);
E 13
E 9
I 3
}

/*
D 11
 * U-B error handler:
 *	If UNMAXERR errors have occured in UNMAXTIME seconds,
 *	disable interface.
E 11
I 11
 * U-B error handler, if maxerr errors have occured
 * in maxtime seconds, disable the interface.
E 11
 */
unerror(unit)
I 9
	int unit;
E 9
{
	register struct un_softc *us = &un_softc[unit];
	struct undevice *addr = (struct undevice *)uninfo[unit]->ui_addr;

I 12
D 21
COUNT(UNERROR);
E 21
E 12
D 11
	if (time - us->us_errtime > UNMAXTIME) {
E 11
I 11
D 25
	if (time - us->us_errtime > us->us_maxtime) {
E 11
		us->us_errtime = time;
E 25
I 25
	if (time.tv_sec - us->us_errtime > us->us_maxtime) {
		us->us_errtime = time.tv_sec;
E 25
		us->us_errcnt = 1;
D 11
	} else if (++us->us_errcnt >= UNMAXERR) {
E 11
I 11
	} else if (++us->us_errcnt >= us->us_maxerr) {
E 11
D 35
		printf("un%d: error limit exceeded\n", unit);
E 35
I 35
		printf("ub%d: error limit exceeded\n", unit);
E 35
D 11
		us->us_enabled = 0;
E 11
I 11
		us->us_if.if_flags &= ~IFF_UP;
E 11
		addr->csr = 0;
D 8
		timeout(unrestart, unit, UNRESTART*hz);
E 8
I 8
D 11
		timeout(unrestart, (caddr_t)unit, UNRESTART*hz);
E 11
I 11
D 23
		timeout(unrestart, (caddr_t)unit, us->us_restart);
E 23
I 23
		us->us_if.if_timer = us->us_restart;
E 23
E 11
E 8
	}
}

unrestart(unit)
I 9
	int unit;
E 9
{
	register struct un_softc *us = &un_softc[unit];
	struct undevice *addr = (struct undevice *)uninfo[unit]->ui_addr;
	int s;

I 12
D 21
COUNT(UNRESTART);
E 21
E 12
D 11
	us->us_enabled = 1;
E 11
I 11
	us->us_if.if_flags |= IFF_UP;
E 11
D 35
	printf("un%d: restarting\n", unit);
E 35
I 35
	printf("ub%d: restarting\n", unit);
E 35
I 5
	unwhoami(unit);
E 5
	s = splimp();
D 9
	addr->csr = IE | UNRESET;
	addr->csr = IE | UNRESET | GO;
E 9
I 9
	addr->csr = IE|UNRESET;
	addr->csr = IE|UNRESET|GO;
E 9
	us->us_state = US_RESET;
	splx(s);
I 5
}

/*
D 11
 * Send a "Who am I?" message to the interface.  Interface should respond
 * with an copy of the packet with its real address filled in.
 * The message is placed at the head of the output queue.  An interface
 * reset should be done next to start things rolling.
E 11
I 11
 * Send a "Who am I?" message to the interface. 
 * Interface should respond with an copy of the
 * packet with its real address filled in.  The
 * message is placed at the head of the output queue.
 * An interface reset should be done next to start
 * things rolling.
E 11
 */
unwhoami(unit)             
I 9
	int unit;
E 9
{
D 7
	register i;
E 7
	register struct mbuf *m;
	register struct un_softc *us = &un_softc[unit];
	register struct un_header *un;
	int s;

I 12
D 21
COUNT(UNWHOAMI);
E 21
E 12
D 11
#ifdef UN_DEBUG
	printf("un%d: whoami\n", unit);
#endif
	if ((m = m_getclr(M_DONTWAIT)) == 0) 
E 11
I 11
D 31
	if ((m = m_get(M_DONTWAIT)) == 0) 
E 31
I 31
	if ((m = m_get(M_DONTWAIT, MT_HEADER)) == 0) 
E 31
E 11
		return;
	m->m_off = MMINOFF;
	m->m_len = sizeof(struct un_header);
	un = mtod(m, struct un_header *);
I 11
	bzero((caddr_t)un, sizeof (struct un_header));
E 11
	un->un_length = htons(sizeof (struct un_header));
D 11
	un->un_type = 0;
	un->un_control = 0;
	un->un_dnet = htons(0);
	un->un_dniu = htons(0);
	un->un_dport = 0;
	un->un_dtype = 5;
	un->un_snet = htons(0);
	un->un_sniu = htons(0);
	un->un_sport = 0;
	un->un_stype = 5;
	un->un_option = 0;
	un->un_bcc = 0;
E 11
I 11
	un->un_dtype = un->un_stype = 5;
E 11
	un->un_ptype = UNTYPE_INQUIRE;
	s = splimp();
	IF_PREPEND(&us->us_if.if_snd, m);
	splx(s);
I 32
}

/*
 * Process an ioctl request.
 */
unioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	struct ifreq *ifr = (struct ifreq *)data;
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		unsetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, RTF_UP);
		else
			uninit(ifp->if_unit);
		break;

	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
}

unsetaddr(ifp, sin)
	register struct ifnet *ifp;
	register struct sockaddr_in *sin;
{

	ifp->if_net = in_netof(sin->sin_addr);
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
	/* host number filled in already, or filled in later */
	sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags |= IFF_BROADCAST;
E 32
D 11
#ifdef UN_DEBUG
	printf("un%d: whoami exit\n", unit);
#endif
E 11
E 5
E 3
}
I 33
#endif
E 33
E 1
