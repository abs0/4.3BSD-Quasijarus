h28423
s 00018/00000/01485
d D 7.2 88/08/04 15:25:04 bostic 21 20
c add Berkeley specific copyright
e
s 00000/00000/01485
d D 7.1 86/06/05 17:07:56 mckusick 20 19
c 4.3BSD release version
e
s 00001/00005/01484
d D 6.9 86/02/23 23:29:01 karels 19 18
c lint
e
s 00005/00007/01484
d D 6.8 86/02/20 17:08:23 karels 18 17
c lint
e
s 00000/00003/01491
d D 6.7 85/12/19 15:46:12 karels 17 16
c rm bbnnet
e
s 00010/00004/01484
d D 6.6 85/09/16 22:28:44 karels 16 15
c pass ifp to if_rubaget; fix up SIFADDR; bug fix, include fix
e
s 00007/00001/01481
d D 6.5 85/06/08 13:56:34 mckusick 15 14
c Add copyright
e
s 00027/00036/01455
d D 6.4 85/06/03 08:40:49 karels 14 13
c now they compile at least
e
s 00533/00316/00958
d D 6.3 85/05/28 14:08:51 karels 13 12
c from Glaser
e
s 00014/00014/01260
d D 6.2 84/08/29 20:43:31 bloom 12 11
c change ot includes.  no more ../h
e
s 00000/00000/01274
d D 6.1 83/07/29 07:37:51 sam 11 10
c 4.2 distribution
e
s 00001/00001/01273
d D 4.9 83/06/19 12:12:19 root 10 9
c lint
e
s 00028/00029/01246
d D 4.8 83/06/13 22:46:13 sam 9 8
c lint
e
s 00020/00003/01255
d D 4.7 83/06/13 00:12:52 sam 8 7
c just a little bit more
e
s 00001/00000/01257
d D 4.6 83/06/12 23:32:58 sam 7 6
c ioctls
e
s 00010/00019/01247
d D 4.5 83/06/12 23:18:17 sam 6 5
c ioctls
e
s 00014/00014/01252
d D 4.4 83/05/27 13:50:17 sam 5 4
c lint
e
s 00310/00291/00956
d D 4.3 83/02/21 16:56:57 sam 4 3
c various cleanups and conversions to 4.1c
e
s 00001/00001/01246
d D 4.2 83/02/21 00:10:40 sam 3 1
c moved some header files around
e
s 00001/00001/01246
d R 4.2 83/02/21 00:05:44 sam 2 1
c if_hy.h -> if_hyreg.h
e
s 01247/00000/00000
d D 4.1 83/02/20 23:36:59 sam 1 0
c date and time created 83/02/20 23:36:59 by sam
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
D 15
/*	%W% (Berkeley) %G% */
E 15
I 15
/*
I 21
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Tektronix Inc.
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
E 21
D 19
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
E 19
 *	%W% (Berkeley) %G%
 */
E 15
E 13

I 13
/*
 * 4.2 BSD Unix Kernel - Vax Network Interface Support
 *
 * $Header: if_hy.c,v 10.1 84/07/22 21:02:56 steveg Exp $
 * $Locker:  $
 *
 * Modifications from Berkeley 4.2 BSD
 * Copyright (c) 1983, Tektronix Inc.
 * All Rights Reserved
 *
 * $Log:	if_hy.c,v $
 *	Revision 10.1  84/07/22  21:02:56  steveg
 *	define PI13 (moved from if_hyreg.h, somehow got dropped in the process)
 *	rework hywatch to check for power fails first
 *	
 *	Revision 10.0  84/06/30  19:54:27  steveg
 *	Big Build
 *	
 *	Revision 3.17  84/06/20  19:20:28  steveg
 *	increment hy_ntime in hywatch
 *	print out state name, csr, last command, and hy_flags when watchdog timer
 *	expires
 *	
 *	Revision 3.16  84/06/20  19:09:34  steveg
 *	turn on continuous logging by default
 *	
 *	Revision 3.15  84/05/30  22:19:09  steveg
 *	changes to reflect new layout ot statistics data
 *	
 *	Revision 3.14  84/05/30  19:25:15  steveg
 *	move driver states to if_hy.h so log printing programs can use them
 *	
 *	Revision 3.13  84/05/30  17:13:26  steveg
 *	make it compile
 *	
 *	Revision 3.12  84/05/30  13:46:16  steveg
 *	rework logging
 *	
 *	Revision 3.11  84/05/18  19:35:02  steveg
 *	clear IFF_RUNNING and IFF_UP on unibus reset to force resource allocation
 *	by the init routine
 *	
 *	Revision 3.10  84/05/04  12:14:44  steveg
 *	more rework to make it actually work under 4.2
 *	
 *	Revision 3.9  84/05/01  23:34:52  steveg
 *	fix typo so it compiles (unit -> ui->ui_unit)
 *	
 *	Revision 3.8  84/05/01  23:18:30  steveg
 *	changes after talking with rickk
 *	- check power off more closely
 *	- support remote loopback through A710 adapters
 *	- IMPLINK -> HYLINK
 *	- return EHOSTUNREACH on hyroute failure
 *	- bump if_collisions on abnormal interrupts that aren't input or output
 *	
 *
 */


E 13
#include "hy.h"
#if NHY > 0

/*
 * Network Systems Copropration Hyperchanel interface
D 13
 *
D 4
 * MUST BE UPDATED FOR 4.1C
E 4
I 4
D 6
 * UNTESTED WITH 4.1C
E 6
I 6
 * UNTESTED WITH 4.2
E 13
E 6
E 4
 */
D 13
#include "../machine/pte.h"
E 13
I 13
#include "machine/pte.h"
E 13

D 12
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
D 4
#include "../h/cpu.h"
E 4
#include "../h/vmmac.h"
D 4
#include "../h/dir.h"
#include "../h/user.h"
E 4
#include "../h/errno.h"
I 4
#include "../h/time.h"
#include "../h/kernel.h"
#include "../h/ioctl.h"
E 12
I 12
D 13
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
E 13
I 13
D 14
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/vmmac.h"
#include "../h/errno.h"
#include "../h/time.h"
#include "../h/kernel.h"
#include "../h/ioctl.h"
E 14
I 14
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
E 14
E 13
E 12
I 9

E 9
E 4
D 6

E 6
#include "../net/if.h"
I 4
#include "../net/netisr.h"
E 4
#include "../net/route.h"
I 16

D 17
#ifdef	BBNNET
#define	INET
#endif
E 17
#ifdef	INET
E 16
D 6

E 6
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 16
#include "../netinet/in_var.h"
E 16
#include "../netinet/ip.h"
D 16
#include "../netinet/ip_var.h"
E 16
I 16
#endif
E 16

D 4
#include "../vaxif/if_hy.h"
I 3
#include "../vaxif/if_hyreg.h"
E 3
#include "../vaxif/if_uba.h"
D 3
#include "../vaxif/if_hyroute.h"
E 3

E 4
I 4
#include "../vax/cpu.h"
E 4
#include "../vax/mtpr.h"
I 4
D 6

E 6
E 4
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
D 6

E 6
I 4
D 12
#include "../vaxif/if_hy.h"
#include "../vaxif/if_hyreg.h"
#include "../vaxif/if_uba.h"
E 12
I 12
D 13
#include "if_hy.h"
#include "if_hyreg.h"
#include "if_uba.h"
E 13
E 12

E 4
D 13
#define HYROUTE
#define HYELOG
#define	HYMTU	576
E 13
I 13
/*
 * configuration specific paramters
 *	- change as appropriate for particular installaions
 */
#define	HYROUTE
#define	HYELOG
#define	HYLOG
#define	HYMTU	1100
#define PI13
E 13

I 13
#ifdef	DEBUG
#define	HYLOG
#endif

D 14
#include "../vaxif/if_hy.h"
#include "../vaxif/if_hyreg.h"
#include "../vaxif/if_uba.h"
E 14
I 14
#include "if_hy.h"
#include "if_hyreg.h"
#include "if_uba.h"
E 14

E 13
D 6
int	hyprobe(), hyattach(), hyinit(), hyoutput(), hyreset(), hywatch();
E 6
I 6
int	hyprobe(), hyattach(), hyinit(), hyioctl();
int	hyoutput(), hyreset(), hywatch();
E 6
struct	uba_device *hyinfo[NHY];
u_short hystd[] = { 0772410, 0 };
struct	uba_driver hydriver =
	{ hyprobe, 0, hyattach, 0, hystd, "hy", hyinfo };

/*
 * Hyperchannel software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * hy_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct	hy_softc {
	struct	ifnet hy_if;		/* network-visible interface */
	struct	ifuba hy_ifuba;		/* UNIBUS resources */
D 4
	short	hy_flags;		/* flags                        */
	short	hy_state;		/* driver state                 */
E 4
I 4
	short	hy_flags;		/* flags */
	short	hy_state;		/* driver state */
I 14
	u_short	hy_host;		/* local host number */
	struct	in_addr hy_addr;	/* internet address */
E 14
E 4
D 13
	int	hy_ilen;		/* mp length on input */
E 13
	int	hy_olen;		/* packet length on output */
	int	hy_lastwcr;		/* last command's word count */
	short	hy_savedstate;		/* saved for reissue after status */
	short	hy_savedcmd;		/* saved command for reissue */
	int	hy_savedcount;		/* saved byte count for reissue */
	int	hy_savedaddr;		/* saved unibus address for reissue */
	int	hy_ntime;		/* number of timeouts since last cmd */
	int	hy_retry;		/* retry counter */
D 4
	struct hy_stat	hy_stat;	/* statistics */
	struct hy_status hy_status;	/* status */
E 4
I 4
	struct	hy_stat hy_stat;	/* statistics */
	struct	hy_status hy_status;	/* status */
E 4
} hy_softc[NHY];

#ifdef HYELOG
D 4
#define HYE_MAX	0x18	/* max error code is 0x17, 0x18 bin gets out of range */

unsigned long	hy_elog[(HYE_MAX+1)*4];
E 4
I 4
D 13
#define HYE_MAX	0x18
u_long	hy_elog[(HYE_MAX+1)*4];
E 13
I 13
u_long	hy_elog[HYE_SIZE];
E 13
E 4
#endif

I 13
#ifdef HYLOG
struct hy_log hy_log;
#endif

#ifdef HYROUTE
struct hy_route hy_route[NHY];
#endif

E 13
D 4

E 4
#ifdef DEBUG
D 13
#define printL	lprintf
#define printD	if (hy_debug_flag) lprintf
E 13
I 13
#define printL	printf
#define printD	if (hy_debug_flag) printf
E 13
int	hy_debug_flag = 0;
/*
 * hy_nodebug bit 0x01	set hy_debug_flag on hycancel
 * hy_nodebug bit 0x02	set hy_debug_flag on command reissue
 * hy_nodebug bit 0x04	set hy_debug_flag on abnormal interrupt
D 13
 * hy_nodebug bit 0x08	set hy_debug_flag on hyouput
 * hy_nodebug bit 0x10	set hy_debug_flag on hyouput with associated data
E 13
 */
int	hy_nodebug = 0x0;
D 13
#else
#define printD	hyvoid
E 13
#endif

D 13
/*
D 4
 * requests for service (in order by descending priority)
E 4
I 4
 * Requests for service (in order by descending priority).
E 4
 */
D 4

E 4
#define RQ_ENDOP	001	/* end the last adapter function */
#define RQ_REISSUE	002	/* reissue previous cmd after status */
#define RQ_STATUS	004	/* get the status of the adapter */
#define RQ_STATISTICS	010	/* get the statistics of the adapter */
#define RQ_MARKDOWN	020	/* mark this adapter port down */
#define RQ_MARKUP	040	/* mark this interface up */

D 4
/*
 *  more flags
 */

E 4
#define RQ_XASSOC	0100	/* associated data to transmit */

/* 
D 4
 * driver states
E 4
I 4
 * Driver states.
E 4
 */
D 4

E 4
#define	STARTUP		0	/* initial state (before fully there) */
#define	IDLE		1	/* idle state */
#define	STATSENT	2	/* status cmd sent to adapter */
#define	ENDOPSENT	3	/* end operation cmd sent */
#define	RECVSENT	4	/* input message cmd sent */
#define	RECVDATASENT	5	/* input data cmd sent */
#define	XMITSENT	6	/* transmit message cmd sent */
#define	XMITDATASENT	7	/* transmit data cmd sent */
#define	WAITING		8	/* waiting for messages */
#define	CLEARSENT	9	/* clear wait for message cmd sent */
#define MARKPORT	10	/* mark this host's adapter port down issued */
#define RSTATSENT	11	/* read statistics cmd sent to adapter */

#ifdef DEBUG
char *hy_state_names[] = {
	"Startup",
	"Idle",
	"Status Sent",
	"End op Sent",
	"Recieve Message Proper Sent",
	"Recieve Data Sent",
	"Transmit Message Proper Sent",
	"Transmit Data Sent",
	"Wait for Message Sent",
	"Clear Wait for Message Sent",
	"Mark Port Down Sent",
	"Read Statistics Sent"
};
#endif

E 13
#define SCANINTERVAL	10	/* seconds */
#define MAXINTERVAL	20	/* seconds (max action) */

/*
 * Cause a device interrupt.  This code uses a buffer starting at
 * location zero on the unibus (which is already mapped by the
 * autoconfigure code in the kernel).
 */
hyprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct hydevice *addr = (struct hydevice *) reg;

#ifdef lint
	br = 0; cvec = br; br = cvec;
	hyint(0);
#endif
	/*
	 * request adapter status to a buffer starting at unibus location 0
	 */
	addr->hyd_bar = 0;
	addr->hyd_wcr = -((sizeof(struct hy_status) + 1) >> 1);
	addr->hyd_dbuf = HYF_STATUS;
#ifdef PI13
	addr->hyd_csr |= S_GO | S_IE | S_IATTN;
#else
	addr->hyd_csr |= S_GO | S_IE;
#endif
	DELAY(10000);
#ifdef PI13
	addr->hyd_csr |= S_CLRINT;	/* clear any stacked interrupts */
#endif
	addr->hyd_csr &= ~(S_IE | S_CLRINT);	/* disable further interrupts */
D 13
	return(1);
E 13
I 13
	return(sizeof(struct hydevice));
E 13
D 4
} /* hyprobe */
E 4
I 4
}
E 4

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
hyattach(ui)
	struct uba_device *ui;
{
	register struct hy_softc *is = &hy_softc[ui->ui_unit];
	register struct ifnet *ifp = &is->hy_if;
I 13
D 14
	register struct sockaddr_in *sin;
E 14
E 13

	ifp->if_unit = ui->ui_unit;
	ifp->if_name = "hy";
	ifp->if_mtu = HYMTU;
D 8
	ifp->if_net = ui->ui_flags;
E 8
D 4

E 4
	is->hy_state = STARTUP;		/* don't allow state transitions yet */
I 13
D 14
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
E 14
E 13
D 4

E 4
	ifp->if_init = hyinit;
I 6
	ifp->if_ioctl = hyioctl;
E 6
	ifp->if_output = hyoutput;
D 4
	ifp->if_ubareset = hyreset;
E 4
I 4
	ifp->if_reset = hyreset;
E 4
	ifp->if_watchdog = hywatch;
	ifp->if_timer = SCANINTERVAL;
	is->hy_ifuba.ifu_flags = UBA_CANTWAIT;
D 4
#ifdef SUPBDP
E 4
I 4
#ifdef notdef
E 4
	is->hy_ifuba.ifu_flags |= UBA_NEEDBDP;
#endif
	if_attach(ifp);
D 4
} /* hyattach */
E 4
I 4
}
E 4

/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
hyreset(unit, uban)
	int unit, uban;
{
D 13
	register struct uba_device *ui = hyinfo[unit];
E 13
I 13
	register struct uba_device *ui;
	register struct hy_softc *is;
E 13
D 5
	register struct hy_softc *is;
E 5

D 4
	if (unit >= NHY || ui == 0 || ui->ui_alive == 0 || ui->ui_ubanum != uban)
E 4
I 4
D 13
	if (unit >= NHY || ui == 0 || ui->ui_alive == 0 ||
E 13
I 13
	if (unit >= NHY || (ui = hyinfo[unit]) == 0 || ui->ui_alive == 0 ||
E 13
	  ui->ui_ubanum != uban)
E 4
		return;
D 4

E 4
	printf(" hy%d", unit);
I 13
	is = &hy_softc[unit];		/* force unibus resource allocation */
	is->hy_if.if_flags &= ~(IFF_UP|IFF_RUNNING);
E 13
	hyinit(unit);
D 4
} /* hyreset */
E 4
I 4
}
E 4

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
hyinit(unit)
	int unit;
{
	register struct hy_softc *is = &hy_softc[unit];
	register struct uba_device *ui = hyinfo[unit];
I 13
	register struct mbuf *m;
E 13
I 8
D 14
	struct sockaddr_in *sin;
E 14
E 8
	int s;

I 8
D 9
	sin = (struct sockaddr_in *)&is->is_if.if_addr;
E 9
I 9
D 14
	sin = (struct sockaddr_in *)&is->hy_if.if_addr;
E 9
D 13
	if (in_netof(sin->sin_addr) == 0)
E 13
I 13
	if (sin->sin_addr.s_addr == 0)		/* address still unknown */
E 14
I 14
	if (is->hy_if.if_addrlist == 0)		/* address still unknown */
E 14
E 13
		return;
I 13
	if (is->hy_if.if_flags & IFF_RUNNING)	/* just reset the device */
		goto justreset;
E 13
E 8
	if (if_ubainit(&is->hy_ifuba, ui->ui_ubanum,
D 13
	    sizeof (struct hy_hdr), (int)btoc(HYMTU)) == 0) { 
E 13
I 13
	    sizeof (struct hym_hdr), (int)btoc(HYMTU)) == 0) { 
E 13
#ifdef DEBUG
D 4
		if (hy_nodebug & 4) hy_debug_flag = 1;
E 4
I 4
		if (hy_nodebug & 4)
			hy_debug_flag = 1;
E 4
#endif
		printf("hy%d: can't initialize\n", unit);
		is->hy_if.if_flags &= ~IFF_UP;
		return;
	}
I 7
D 9
	is->is_hy.if_flags |= IFF_RUNNING;
E 9
I 9
	is->hy_if.if_flags |= IFF_RUNNING;
I 13

justreset:
E 13
E 9
E 7
D 4

E 4
	/*
D 4
	 * issue wait for message and start the state machine
E 4
I 4
D 13
	 * Issue wait for message and start the state machine
E 13
I 13
	 * remove any left over outgoing messages, reset the hardware and
	 * start the state machine
E 13
E 4
	 */
	s = splimp();
I 13
#ifdef HYLOG
	hylog(HYL_RESET, 0, (char *)0);
#endif
E 13
	is->hy_state = IDLE;
	is->hy_flags = RQ_STATUS | RQ_STATISTICS | RQ_MARKUP;
	is->hy_retry = 0;
D 13
	hyact(ui);
E 13
I 13
	for(;;) {
		IF_DEQUEUE(&is->hy_if.if_snd, m);
		if (m != NULL)
			m_freem(m);
		else
			break;
	}
	hycancel(ui);		/* also bumps the state machine */
E 13
	splx(s);
D 4
} /* hyinit */
E 4
I 4
}
E 4

D 4

E 4
/*
D 4
 * issue a command to the adapter
E 4
I 4
 * Issue a command to the adapter
E 4
 */
hystart(ui, cmd, count, ubaddr)
	struct uba_device *ui;
D 4
	int cmd;
	int count;
	int ubaddr;
E 4
I 4
	int cmd, count, ubaddr;
E 4
{
	register struct hy_softc *is = &hy_softc[ui->ui_unit];
	register struct hydevice *addr = (struct hydevice *)ui->ui_addr;

#ifdef DEBUG
D 4
	printD("hy%d: hystart cmd = 0x%x count=%d ubaddr=0x%x\n", ui->ui_unit, cmd, count, ubaddr);
E 4
I 4
	printD("hy%d: hystart cmd = 0x%x count=%d ubaddr=0x%x\n",
		ui->ui_unit, cmd, count, ubaddr);
E 4
	printD("hy%d: - csr = 0x%b, bar = 0x%x, wcr = 0x%x\n",
D 4
		ui->ui_unit, addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar, addr->hyd_wcr);
E 4
I 4
		ui->ui_unit, addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar,
		addr->hyd_wcr);
E 4
#endif
D 4

	if (((is->hy_flags & RQ_REISSUE) == 0) && (cmd != HYF_STATUS) && (cmd != HYF_END_OP) && (cmd != HYF_RSTATS)) {
E 4
I 4
	if (((is->hy_flags & RQ_REISSUE) == 0) &&
	  (cmd != HYF_STATUS) && (cmd != HYF_END_OP) && (cmd != HYF_RSTATS)) {
E 4
		is->hy_savedstate = is->hy_state;
		is->hy_savedcmd = cmd;
		is->hy_savedcount = count;
		is->hy_savedaddr = ubaddr;
	}
I 13
#ifdef PI13
	if (addr->hyd_csr & S_POWEROFF) {
		printf("hy%d: \"Soft\" Adapter Power Failure (hystart)\n", ui->ui_unit);
		addr->hyd_csr |= S_POWEROFF;
		DELAY(100);
		if (addr->hyd_csr & S_POWEROFF) {
			printf( "hy%d: \"Hard\" Adapter Power Failure, Network Shutdown (hystart)\n", ui->ui_unit);
			if_down(&is->hy_if);
			is->hy_if.if_flags &= ~IFF_UP;
			is->hy_state = STARTUP;
		} else {
			printf("hy%d: Adapter Power Restored (hystart)\n", ui->ui_unit);
		}
		return;
	}
#endif
E 13
D 4

E 4
	addr->hyd_bar = ubaddr & 0xffff;
D 4
	addr->hyd_wcr = is->hy_lastwcr = -((count+1) >> 1);	/* was byte count */
E 4
I 4
	addr->hyd_wcr = is->hy_lastwcr = -((count+1) >> 1);
E 4
	addr->hyd_dbuf = cmd;
#ifdef PI13
	addr->hyd_csr = ((ubaddr >> XBASHIFT) & S_XBA) | S_GO | S_IE | S_IATTN;
#else
	addr->hyd_csr = ((ubaddr >> XBASHIFT) & S_XBA) | S_GO | S_IE;
#endif
#ifdef DEBUG
	printD("hy%d: exit hystart - csr = 0x%b, bar = 0x%x, wcr = 0x%x\n",
D 4
		ui->ui_unit, addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar, addr->hyd_wcr);
E 4
I 4
		ui->ui_unit, addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar,
		addr->hyd_wcr);
E 4
#endif
#ifdef HYLOG
	{
		struct {
D 4
			unsigned char hcmd;
			unsigned char hstate;
			short hcount;
E 4
I 4
			u_char	hcmd;
			u_char	hstate;
			short	hcount;
E 4
		} hcl;

		hcl.hcmd = cmd;
		hcl.hstate = is->hy_state;
		hcl.hcount = count;
		hylog(HYL_CMD, sizeof(hcl), (char *)&hcl);
	}
#endif
	is->hy_ntime = 0;
D 4
} /* hystart */
E 4
I 4
}
E 4

int hyint_active = 0;		/* set during hy interrupt */
D 4

E 4
/*
D 4
 * hyperchannel interface interrupt.
E 4
I 4
 * Hyperchannel interface interrupt.
E 4
 *
 * An interrupt can occur for many reasons.  Examine the status of
 * the hyperchannel status bits to determine what to do next.
 *
 * If input error just drop packet.
 * Otherwise purge input buffered data path and examine 
 * packet to determine type.  Othewise decapsulate
 * packet based on type and pass to type specific higher-level
 * input routine.
 */
hyint(unit)
	int unit;
{
	register struct hy_softc *is = &hy_softc[unit];
	register struct uba_device *ui = hyinfo[unit];
D 4
	register struct hydevice *addr =
		(struct hydevice *)ui->ui_addr;
E 4
I 4
	register struct hydevice *addr = (struct hydevice *)ui->ui_addr;
E 4

D 4
	if (hyint_active) {
E 4
I 4
	if (hyint_active)
E 4
		panic("RECURSIVE HYPERCHANNEL INTERRUPT");
D 4
	}

E 4
	hyint_active++;
D 4

E 4
#ifdef DEBUG
	printD("hy%d: hyint enter - csr = 0x%b, bar = 0x%x, wcr = 0x%x\n",
		unit, addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar, addr->hyd_wcr);
#endif
#ifdef HYLOG
logit:
	{
		struct {
D 4
			unsigned char hstate;
			unsigned char hflags;
			short hcsr;
			short hwcr;
E 4
I 4
			u_char	hstate;
			u_char	hflags;
			short	hcsr;
			short	hwcr;
E 4
		} hil;
		hil.hstate = is->hy_state;
		hil.hflags = is->hy_flags;
		hil.hcsr = addr->hyd_csr;
		hil.hwcr = addr->hyd_wcr;
		hylog(HYL_INT, sizeof(hil), (char *)&hil);
	}
#endif
D 4

	if (ERROR(addr) && ((addr->hyd_csr & S_ATTN) == 0)) {
E 4
I 4
	if (HYS_ERROR(addr) && ((addr->hyd_csr & S_ATTN) == 0)) {
E 4
		/*
D 4
		 * error bit set, some sort of error in the interface
E 4
I 4
		 * Error bit set, some sort of error in the interface.
E 4
		 *
D 4
		 * the adapter sets attn on command completion so that's not
		 * a real error even though the interface considers it one
E 4
I 4
		 * The adapter sets attn on command completion so that's not
		 * a real error even though the interface considers it one.
E 4
		 */
#ifdef DEBUG
D 4
		if (hy_nodebug & 4) hy_debug_flag = 1;
E 4
I 4
		if (hy_nodebug & 4)
			hy_debug_flag = 1;
E 4
#endif
D 4
		printf("csr = 0x%b\nbar = 0x%x\nwcr = 0x%x\n", addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar, addr->hyd_wcr);

		if ((addr->hyd_csr & S_NEX) != 0) {
E 4
I 4
		printf("csr = 0x%b\nbar = 0x%x\nwcr = 0x%x\n",
			addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar,
			addr->hyd_wcr);
		if (addr->hyd_csr & S_NEX) {
E 4
			printf("hy%d: NEX - Non Existant Memory\n", unit);
#ifdef PI13
			addr->hyd_csr |= S_NEX;  /* as per PI13 manual */
#else
			addr->hyd_csr &= ~S_NEX;
#endif
			hycancel(ui);
#ifdef PI13
D 4
		} else if ((addr->hyd_csr & S_POWEROFF) != 0) {
			printf("hy%d: Power Off bit set, trying to reset\n", unit);
E 4
I 4
		} else if (addr->hyd_csr & S_POWEROFF) {
D 13
			printf("hy%d: Power Off bit set, trying to reset\n",
				unit);
E 13
I 13
			printf("hy%d: \"Soft\" Adapter Power Failure (hyint)\n", unit);
E 13
E 4
			addr->hyd_csr |= S_POWEROFF;
			DELAY(100);
D 4
			if ((addr->hyd_csr & S_POWEROFF) != 0) {
E 4
I 4
			if (addr->hyd_csr & S_POWEROFF) {
I 13
				printf( "hy%d: \"Hard\" Adapter Power Failure, Network Shutdown (hyint)\n", unit);
E 13
E 4
				if_down(&is->hy_if);
I 13
				is->hy_if.if_flags &= ~IFF_UP;
E 13
				is->hy_state = STARTUP;
D 4
				printf("hy%d: Power Off Error, network shutdown\n", unit);
E 4
I 4
D 13
				printf(
				  "hy%d: Power Off Error, network shutdown\n",
				  unit);
E 13
I 13
			} else {
				printf("hy%d: Adapter Power Restored (hyint)\n", unit);
E 13
E 4
			}
#endif
		} else {
			printf("hy%d:  BAR overflow\n", unit);
			hycancel(ui);
		}
D 4
	} else if (NORMAL(addr)) {
E 4
I 4
	} else if (HYS_NORMAL(addr)) {
E 4
		/*
D 4
		 * normal interrupt, bump state machine unless in state
E 4
I 4
		 * Normal interrupt, bump state machine unless in state
E 4
		 * waiting and no data present (assumed to be word count
D 4
		 * zero interrupt or other hardware botch)
E 4
I 4
		 * zero interrupt or other hardware botch).
E 4
		 */
D 4
		if (is->hy_state != WAITING || RECV_DATA(addr))
E 4
I 4
		if (is->hy_state != WAITING || HYS_RECVDATA(addr))
E 4
			hyact(ui);
D 4

	} else if (ABNORMAL(addr)) {
E 4
I 4
	} else if (HYS_ABNORMAL(addr)) {
E 4
		/*
D 4
		 * abnormal termination.
E 4
I 4
		 * Abnormal termination.
E 4
		 * bump error counts, retry the last function
		 * 'MAXRETRY' times before kicking the bucket.
		 *
D 4
		 * don't reissue the cmd if in certain states, abnormal
		 * on a reissued cmd or max retry exceeded
E 4
I 4
		 * Don't reissue the cmd if in certain states, abnormal
		 * on a reissued cmd or max retry exceeded.
E 4
		 */
#ifdef HYLOG
		if (hy_log.hyl_enable != hy_log.hyl_onerr) {
			hy_log.hyl_enable = hy_log.hyl_onerr;
			goto logit;
		}
#endif
#ifdef DEBUG
D 4
		if (hy_nodebug & 4) hy_debug_flag = 1;
E 4
I 4
		if (hy_nodebug & 4)
			hy_debug_flag = 1;
E 4
		printD("hy%d: abnormal interrupt, driver state \"%s\" (%d)\n",
			unit, hy_state_names[is->hy_state], is->hy_state);
D 4
		printD("\tflags 0x%x ilen %d olen %d lastwcr %d retry %d\n\tsaved: state %d count %d cmd 0x%x ptr 0x%x\n",
			is->hy_flags, is->hy_ilen, is->hy_olen, is->hy_lastwcr, is->hy_retry,
			is->hy_savedstate, is->hy_savedcount, is->hy_savedaddr, is->hy_savedcmd);
E 4
I 4
D 13
		printD("\tflags 0x%x ilen %d olen %d lastwcr %d retry %d\n",
			is->hy_flags, is->hy_ilen, is->hy_olen,
			is->hy_lastwcr, is->hy_retry);
E 13
I 13
		printD("\tflags 0x%x olen %d lastwcr %d retry %d\n",
			is->hy_flags, is->hy_olen, is->hy_lastwcr, is->hy_retry);
E 13
		printD("\tsaved: state %d count %d cmd 0x%x ptr 0x%x\n",
			is->hy_savedstate, is->hy_savedcount,
			is->hy_savedaddr, is->hy_savedcmd);
E 4
#endif
#ifdef PI13
		addr->hyd_csr &= ~S_C;  /* clear the damned PI-13 */
#endif
D 4
		if (is->hy_state == XMITSENT || is->hy_state == XMITDATASENT) {
E 4
I 4
		if (is->hy_state == XMITSENT || is->hy_state == XMITDATASENT)
E 4
			is->hy_if.if_oerrors++;
D 4
		} else if (is->hy_state == RECVSENT || is->hy_state == RECVDATASENT) {
E 4
I 4
D 13
		if (is->hy_state == RECVSENT || is->hy_state == RECVDATASENT)
E 13
I 13
		else if (is->hy_state == RECVSENT || is->hy_state == RECVDATASENT)
E 13
E 4
			is->hy_if.if_ierrors++;
I 13
		else
			is->hy_if.if_collisions++;	/* other errors */
E 13
D 4
		}

E 4
		if (is->hy_state == XMITDATASENT ||
		    is->hy_state == RECVSENT ||
		    is->hy_state == RECVDATASENT ||
D 4
		    (is->hy_flags & RQ_REISSUE) != 0 || is->hy_retry > MAXRETRY) {
E 4
I 4
		    (is->hy_flags & RQ_REISSUE) != 0 || is->hy_retry > MAXRETRY)
E 4
			hycancel(ui);
D 4
		} else {
E 4
I 4
		else {
E 4
#ifdef DEBUG
D 4
			if (hy_nodebug & 2) hy_debug_flag = 1;
E 4
I 4
			if (hy_nodebug & 2)
				hy_debug_flag = 1;
E 4
#endif
			is->hy_retry++;
			is->hy_flags |= RQ_ENDOP | RQ_STATUS | RQ_REISSUE;
			is->hy_state = IDLE;
			hyact(ui);
		}
	} else {
		/*
		 * Interrupt is neither normal, abnormal, or interface error.
		 * Ignore it. It's either stacked or a word count 0.
		 */
#ifdef HYLOG
		if (hy_log.hyl_enable != hy_log.hyl_onerr) {
			hy_log.hyl_enable = hy_log.hyl_onerr;
			goto logit;
		}
#endif
#ifdef DEBUG
		printD("hy%d: possible stacked interrupt ignored\n", unit);
#endif
	}
D 4

E 4
#ifdef DEBUG
	printD("hy%d: hyint exit\n\n", unit);
#endif
	hyint_active = 0;

D 4
} /* hyint */
E 4
I 4
}
E 4

I 13
int hyoutprint = 0;

E 13
/*
 * Encapsulate a packet of type family for the local net.
D 9
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
E 9
 */
hyoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
	register struct hym_hdr *hym;
	register struct mbuf *m;
I 13
	register char *mp;
E 13
D 18
#ifdef HYROUTE
D 13
	register struct hyroute *r = &hy_route[ifp->if_unit];
E 13
I 13
	register struct hy_route *r = &hy_route[ifp->if_unit];
E 13
#endif
E 18
D 13
	short dtype;		/* packet type */
	int dhost;		/* destination adapter address */
	int dlen;
	int mplen = 0;		/* message proper length */
	short loopback = 0;	/* hardware loopback requested */
E 13
I 13
	int dlen;	/* packet size, incl hardware header, but not sw header */
E 13
	int error = 0;
	int s;

D 13
#ifdef DEBUG
D 4
	if (hy_nodebug & 8) hy_debug_flag = 1;
E 4
I 4
	if (hy_nodebug & 8)
		hy_debug_flag = 1;
E 4
#endif
E 13
I 13
	/*
	 * Calculate packet length for later deciding whether it will fit
	 * in a message proper or we also need associated data.
	 */
E 13
	dlen = 0;
	for (m = m0; m; m = m->m_next)
		dlen += m->m_len;
	m = m0;
I 13
	if (dst->sa_family == AF_HYLINK) {	/* don't add header */
		dlen -= HYM_SWLEN;
		goto headerexists;
	}

	/*
	 * Add the software and hardware hyperchannel headers.
	 * If there's not enough space in the first mbuf, allocate another.
	 * If that should fail, drop this sucker.
	 * No extra space for headers is allocated.
	 */
	mp = mtod(m, char *);	/* save pointer to real message */
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof(struct hym_hdr) > m->m_off) {
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			m = m0;
			error = ENOBUFS;
			goto drop;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof(struct hym_hdr);
	} else {
		m->m_off -= sizeof(struct hym_hdr);
		m->m_len += sizeof(struct hym_hdr);
	}

	dlen += sizeof(struct hym_hdr) - HYM_SWLEN;

	hym = mtod(m, struct hym_hdr *);

	bzero((caddr_t)hym, sizeof(struct hym_hdr));

E 13
D 4

E 4
	switch(dst->sa_family) {

#ifdef INET
	case AF_INET: {
D 13
		register struct ip *ip = mtod(m, struct ip *);
		register struct sockaddr_in *sin = (struct sockaddr_in *)dst;
		register long hostaddr = in_lnaof(sin->sin_addr);
E 13
I 13
		int i;
E 13

D 13
		dhost = hostaddr & 0xffff;
		dtype = HYLINK_IP;
#ifdef DEBUG
D 4
		printD("hy%d: output to host %x, dhost %x\n", ifp->if_unit, sin->sin_addr.s_addr, dhost);
E 4
I 4
		printD("hy%d: output to host %x, dhost %x\n",
			ifp->if_unit, sin->sin_addr.s_addr, dhost);
E 4
#endif
E 13
		/*
D 4
		 * debugging loopback support:
E 4
I 4
D 13
		 * Debugging loopback support:
E 4
		 * upper byte of 24 bit host number interpreted as follows
		 *	0x00 --> no loopback
		 *	0x01 --> hardware loop through remote adapter
		 *	other --> software loop through remote ip layer
E 13
I 13
		 * if loopback address, swizzle ip header so when
		 * it comes back it looks like it was addressed to us
E 13
		 */
D 13
		if (hostaddr & 0xff0000) {
E 13
I 13
		i = hyroute(ifp, (u_long)in_lnaof(((struct sockaddr_in *)dst)->sin_addr), hym);
		if (i < 0)
			goto notfound;
		if (i > 0) {
E 13
			struct in_addr temp;

D 13
			temp = ip->ip_dst;
			ip->ip_dst = ip->ip_src;
			ip->ip_src = temp;
			if ((hostaddr & 0xff0000) == 0x10000)
				loopback = H_LOOPBK;
E 13
I 13
			temp.s_addr = ((struct ip *)mp)->ip_dst.s_addr;
			((struct ip *)mp)->ip_dst.s_addr = ((struct ip *)mp)->ip_src.s_addr;
			((struct ip *)mp)->ip_src.s_addr = temp.s_addr;
E 13
		}
		/*
		 * If entire packet won't fit in message proper, just
		 * send hyperchannel hardware header and ip header in
D 13
		 * message proper.  If that won't fit either, just send
		 * the maximum message proper.
E 13
I 13
		 * message proper.
E 13
		 *
		 * This insures that the associated data is at least a
		 * TCP/UDP header in length and thus prevents potential
		 * problems with very short word counts.
		 */
D 13
		if (dlen > MPSIZE - sizeof (struct hy_hdr)) {
			mplen = sizeof(struct hy_hdr) + (ip->ip_hl << 2);
			if (mplen > MPSIZE)
				mplen = MPSIZE;
		}
E 13
I 13
		if (dlen > MPSIZE)
			hym->hym_mplen = sizeof(struct hy_hdr) + (((struct ip *)mp)->ip_hl << 2);
		hym->hym_type = HYLINK_IP;
E 13
		break;
	}
#endif

	default:
D 4
		printf("hy%d: can't handle af%d\n", ifp->if_unit, dst->sa_family);
E 4
I 4
		printf("hy%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
E 4
D 13
#ifdef DEBUG
D 4
		if (hy_nodebug & 4) hy_debug_flag = 1;
E 4
I 4
		if (hy_nodebug & 4)
			hy_debug_flag = 1;
E 4
#endif
E 13
		error = EAFNOSUPPORT;
		goto drop;
	}

I 13

headerexists:

E 13
	/*
D 4
	 * add the software and hardware hyperchannel headers.
E 4
I 4
D 13
	 * Add the software and hardware hyperchannel headers.
E 4
	 * If there's not enough space in the first mbuf, allocate another.
	 * If that should fail, drop this sucker.
	 * No extra space for headers is allocated.
E 13
I 13
	 * insure message proper is below the maximum
E 13
	 */
D 13
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof(struct hym_hdr) > m->m_off) {
D 4
		m = m_get(M_DONTWAIT);
E 4
I 4
		m = m_get(M_DONTWAIT, MT_HEADER);
E 4
		if (m == 0) {
			m = m0;
			error = ENOBUFS;
			goto drop;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof(struct hym_hdr);
	} else {
		m->m_off -= sizeof(struct hym_hdr);
		m->m_len += sizeof(struct hym_hdr);
	}
	hym = mtod(m, struct hym_hdr *);
	hym->hym_mplen = mplen;
	hym->hym_hdr.hyh_type = dtype;
	hym->hym_hdr.hyh_off = 0;
D 5
	hym->hym_hdr.hyh_from = htons(ifp->if_host[0]);
E 5
I 5
	hym->hym_hdr.hyh_from = htons((u_short)ifp->if_host[0]);
E 5
	hym->hym_hdr.hyh_param = loopback;
#ifdef HYROUTE
D 4
	if (r->hyr_lasttime != 0) {
E 4
I 4
	if (r->hyr_lasttime.tv_sec != 0) {
E 4
		register struct hy_hash *rh;
		register int i;
E 13
I 13
	if (hym->hym_mplen > MPSIZE || (dlen > MPSIZE && hym->hym_mplen == 0))
		hym->hym_mplen = MPSIZE;
E 13

D 13
		i = HYRHASH(dhost);
		rh = &r->hyr_hash[i];
		i = 0;
		while (rh->hyr_key != dhost) {
			rh++; i++;
			if (rh > &r->hyr_hash[HYRSIZE])
				rh = &r->hyr_hash[0];
			if (rh->hyr_flags == 0 || i > HYRSIZE)
				goto notfound;
		}
		if (rh->hyr_flags & HYR_GATE) {
			loopback = 0;	/* no hardware loopback on gateways */
			i = rh->hyr_nextgate;
			if (i >= rh->hyr_egate)
				rh->hyr_nextgate = rh->hyr_pgate;
			else
				rh->hyr_nextgate++;
			rh = &r->hyr_hash[r->hyr_gateway[i]];
			if ((rh->hyr_flags & HYR_DIR) == 0)
				goto notfound;
		}
		hym->hym_hdr.hyh_ctl = rh->hyr_ctl;
		hym->hym_hdr.hyh_access = rh->hyr_access;
		hym->hym_hdr.hyh_to = rh->hyr_dst;
	} else {
		hym->hym_hdr.hyh_ctl = H_XTRUNKS | H_RTRUNKS;
		hym->hym_hdr.hyh_access = 0;
D 5
		hym->hym_hdr.hyh_to = htons(dhost);
E 5
I 5
		hym->hym_hdr.hyh_to = htons((u_short)dhost);
E 5
	}
#else
	hym->hym_hdr.hyh_ctl = H_XTRUNKS | H_RTRUNKS;
	hym->hym_hdr.hyh_access = 0;
	hym->hym_hdr.hyh_to = htons(dhost);
#endif

D 5
headerexists:
E 5
D 4

E 4
	if (hym->hym_mplen) {
		hym->hym_hdr.hyh_ctl |= H_ASSOC;
E 13
I 13
D 14
	hym->hym_from = htons((u_short)ifp->if_host[0]);
E 14
I 14
	hym->hym_from = htons(hy_softc[ifp->if_unit].hy_host);
E 14
	if (hym->hym_mplen)
		hym->hym_ctl |= H_ASSOC;
	else
		hym->hym_ctl &= ~H_ASSOC;
	if (hyoutprint) printf("hy%d: output mplen=%x ctl=%x access=%x to=%x from=%x param=%x type=%x\n",
		ifp->if_unit, hym->hym_mplen, hym->hym_ctl,
		hym->hym_access, hym->hym_to, hym->hym_from,
		hym->hym_param, hym->hym_type);
E 13
#ifdef DEBUG
D 4
		if (hy_nodebug & 16) hy_debug_flag = 1;
E 4
I 4
D 13
		if (hy_nodebug & 16)
			hy_debug_flag = 1;
E 13
I 13
	printD("hy%d: output mplen=%x ctl=%x access=%x to=%x from=%x param=%x type=%x\n",
		ifp->if_unit, hym->hym_mplen, hym->hym_ctl,
		hym->hym_access, hym->hym_to, hym->hym_from,
		hym->hym_param, hym->hym_type);
E 13
E 4
#endif
D 4
	} else hym->hym_hdr.hyh_ctl &= ~H_ASSOC;

E 4
I 4
D 13
	} else
		hym->hym_hdr.hyh_ctl &= ~H_ASSOC;
E 4
#ifdef DEBUG
D 4
	printD("hy%d: output mplen=%x ctl=%x access=%x to=%x (adapter %x) from=%x param=%x type=%x off=%x\n",
E 4
I 4
	printD("hy%d: output mplen=%x ctl=%x access=%x to=%x",
E 4
		ifp->if_unit, hym->hym_mplen, hym->hym_hdr.hyh_ctl,
D 4
		hym->hym_hdr.hyh_access, hym->hym_hdr.hyh_to,
E 4
I 4
		hym->hym_hdr.hyh_access, hym->hym_hdr.hyh_to);
	printD(" (adapter %x) from=%x param=%x type=%x off=%x\n",
E 4
		hym->hym_hdr.hyh_to_adapter,
		hym->hym_hdr.hyh_from, hym->hym_hdr.hyh_param,
		hym->hym_hdr.hyh_type, hym->hym_hdr.hyh_off);
#endif
E 13
D 4


E 4
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		error = ENOBUFS;
		splx(s);
		goto drop;
	}
	IF_ENQUEUE(&ifp->if_snd, m);
	if (hy_softc[ifp->if_unit].hy_state == WAITING)
		hyact(hyinfo[ifp->if_unit]);
	splx(s);
D 4
	return(0);

E 4
I 4
	return (0);
E 4
notfound:
D 4
	error = ENETUNREACH;	/* KLUDGE - should produce better error number */
E 4
I 4
D 13
	error = ENETUNREACH;			/* XXX */
E 13
I 13
	error = EHOSTUNREACH;
E 13
E 4
drop:
	m_freem(m);
D 4
	return(error);
} /* hyoutput */
E 4
I 4
	return (error);
}
E 4

I 13
int
hyroute(ifp, dest, hym)
	register struct ifnet *ifp;
	u_long dest;
	register struct hym_hdr *hym;
{
#ifdef HYROUTE
	register struct hy_route *rt = &hy_route[ifp->if_unit];
	register struct hyr_hash *rhash;
	register int i;
#endif

	hym->hym_param = 0;
#ifdef HYROUTE
	if (rt->hyr_lasttime != 0) {
		i = HYRHASH(dest);
		rhash = &rt->hyr_hash[i];
		i = 0;
		while (rhash->hyr_key != dest) {
			if (rhash->hyr_flags == 0 || i > HYRSIZE)
				return(-1);
			rhash++; i++;
			if (rhash >= &rt->hyr_hash[HYRSIZE])
				rhash = &rt->hyr_hash[0];
		}
		if (rhash->hyr_flags & HYR_GATE) {
			i = rhash->hyr_nextgate;
			if (i >= rhash->hyr_egate)
				rhash->hyr_nextgate = rhash->hyr_pgate;
			else
				rhash->hyr_nextgate++;
			rhash = &rt->hyr_hash[rt->hyr_gateway[i]];
			if ((rhash->hyr_flags & HYR_DIR) == 0)
				return(-1);
		} else if (rhash->hyr_flags & HYR_LOOP) {
			hym->hym_param = H_LOOPBK;	/* adapter loopback */
		} else if (rhash->hyr_flags & HYR_RLOOP) {
			hym->hym_param = H_RLOOPBK;	/* A710 remote loopback */
		}
		hym->hym_ctl = rhash->hyr_ctl;
		hym->hym_access = rhash->hyr_access;
		hym->hym_to = rhash->hyr_dst;
	} else {
#endif
		hym->hym_ctl = H_XTRUNKS | H_RTRUNKS;
		hym->hym_access = 0;
		hym->hym_to = htons((u_short)dest);
		if (dest & 0x010000)
			hym->hym_param = H_LOOPBK;	/* adapter loopback */
		else if (dest & 0x020000)
			hym->hym_param = H_RLOOPBK;	/* A710 remote loopback */
#ifdef HYROUTE
	}
#endif

D 14
	hym->hym_from = htons((u_short)ifp->if_host[0]);
E 14
	if (hym->hym_param == 0)
		return(0);
	else
		return(1);
}

E 13
hyact(ui)
	register struct uba_device *ui;
{
	register struct hy_softc *is = &hy_softc[ui->ui_unit];
	register struct hydevice *addr = (struct hydevice *)ui->ui_addr;

actloop:
D 4

E 4
#ifdef DEBUG
D 4
	printD("hy%d: hyact, enter state \"%s\"\n", ui->ui_unit, hy_state_names[is->hy_state]);
E 4
I 4
	printD("hy%d: hyact, enter state \"%s\"\n", ui->ui_unit,
		hy_state_names[is->hy_state]);
E 4
#endif
D 4

E 4
	switch (is->hy_state) {

	case STARTUP:
		goto endintr;

	case IDLE: {
		register rq = is->hy_flags;

		if (rq & RQ_STATUS) {
			is->hy_flags &= ~RQ_STATUS;
			is->hy_state = STATSENT;
D 4
			hystart(ui, HYF_STATUS, sizeof(is->hy_status), is->hy_ifuba.ifu_r.ifrw_info);
E 4
I 4
			hystart(ui, HYF_STATUS, sizeof (is->hy_status),
D 9
				is->hy_ifuba.ifu_r.ifrw_info);
E 9
I 9
			    is->hy_ifuba.ifu_r.ifrw_info);
E 9
E 4
		} else if (rq & RQ_ENDOP) {
			is->hy_flags &= ~RQ_ENDOP;
			is->hy_state = ENDOPSENT;
			hystart(ui, HYF_END_OP, 0, 0);
		} else if (rq & RQ_STATISTICS) {
			is->hy_flags &= ~RQ_STATISTICS;
			is->hy_state = RSTATSENT;
D 4
			hystart(ui, HYF_RSTATS, sizeof(is->hy_stat), is->hy_ifuba.ifu_r.ifrw_info);
		} else if (RECV_DATA(addr)) {
E 4
I 4
			hystart(ui, HYF_RSTATS, sizeof (is->hy_stat),
D 9
				is->hy_ifuba.ifu_r.ifrw_info);
E 9
I 9
			    is->hy_ifuba.ifu_r.ifrw_info);
E 9
		} else if (HYS_RECVDATA(addr)) {
E 4
			is->hy_state = RECVSENT;
			is->hy_retry = 0;
D 4
			hystart(ui, HYF_INPUTMSG, MPSIZE, is->hy_ifuba.ifu_r.ifrw_info);
E 4
I 4
D 13
			hystart(ui, HYF_INPUTMSG, MPSIZE,
D 9
				is->hy_ifuba.ifu_r.ifrw_info);
E 9
I 9
			    is->hy_ifuba.ifu_r.ifrw_info);
E 13
I 13
			hystart(ui, HYF_INPUTMSG, MPSIZE, is->hy_ifuba.ifu_r.ifrw_info + HYM_SWLEN);
E 13
E 9
E 4
		} else if (rq & RQ_REISSUE) {
			is->hy_flags &= ~RQ_REISSUE;
			is->hy_state = is->hy_savedstate;
#ifdef DEBUG
D 4
			printD("hy%d: reissue cmd=0x%x count=%d ubaddr=0x%x retry=%d\n",
				ui->ui_unit, is->hy_savedcmd,
				is->hy_savedcount, is->hy_savedaddr, is->hy_retry);
E 4
I 4
			printD("hy%d: reissue cmd=0x%x count=%d",
			  ui->ui_unit, is->hy_savedcmd, is->hy_savedcount);
			printD(" ubaddr=0x%x retry=%d\n",
			  is->hy_savedaddr, is->hy_retry);
E 4
#endif
D 4
			hystart(ui, is->hy_savedcmd, is->hy_savedcount, is->hy_savedaddr);
E 4
I 4
			hystart(ui, is->hy_savedcmd, is->hy_savedcount,
D 9
				is->hy_savedaddr);
E 9
I 9
			    is->hy_savedaddr);
E 9
E 4
		} else {
			register struct mbuf *m;

			IF_DEQUEUE(&is->hy_if.if_snd, m);
D 4
			if (m != 0) {
E 4
I 4
			if (m != NULL) {
E 4
				register struct hym_hdr *hym;
				register int mplen;
				register int cmd;

				is->hy_state = XMITSENT;
				is->hy_retry = 0;
				hym = mtod(m, struct hym_hdr *);
#ifdef HYLOG
D 4
				hylog(HYL_XMIT, sizeof(struct hym_hdr), (char *)hym);
E 4
I 4
				hylog(HYL_XMIT, sizeof(struct hym_hdr),
D 9
					(char *)hym);
E 9
I 9
				    (char *)hym);
E 9
E 4
#endif
				mplen = hym->hym_mplen;
D 4
				cmd = (hym->hym_hdr.hyh_to_adapter == hym->hym_hdr.hyh_from_adapter) ?
					HYF_XMITLOCMSG : HYF_XMITMSG;
E 4
I 4
D 13
				if (hym->hym_hdr.hyh_to_adapter ==
D 9
				  hym->hym_hdr.hyh_from_adapter)
E 9
I 9
				    hym->hym_hdr.hyh_from_adapter)
E 13
I 13
				if (hym->hym_to_adapter == hym->hym_from_adapter)
E 13
E 9
					cmd = HYF_XMITLOCMSG;
				else
					cmd = HYF_XMITMSG;
E 4
#ifdef DEBUG
				printD("hy%d: hym_hdr = ", ui->ui_unit);
D 4
				if (hy_debug_flag) hyprintdata((char *)hym, sizeof(struct hym_hdr));
E 4
I 4
				if (hy_debug_flag)
					hyprintdata((char *)hym,
D 9
					  sizeof (struct hym_hdr));
E 9
I 9
					    sizeof (struct hym_hdr));
E 9
E 4
#endif
D 13
				/*
D 4
				 * strip off the software part of
E 4
I 4
				 * Strip off the software part of
E 4
				 * the hyperchannel header
				 */
				m->m_off += sizeof(struct hym_data);
				m->m_len -= sizeof(struct hym_data);
				is->hy_olen = if_wubaput(&is->hy_ifuba, m);
E 13
I 13
				is->hy_olen = if_wubaput(&is->hy_ifuba, m) - HYM_SWLEN;
E 13
D 4
#ifdef SUPBDP
E 4
				if (is->hy_ifuba.ifu_flags & UBA_NEEDBDP)
D 4
					UBAPURGE(is->hy_ifuba.ifu_uba, is->hy_ifuba.ifu_w.ifrw_bdp);
#endif
E 4
I 4
					UBAPURGE(is->hy_ifuba.ifu_uba,
						is->hy_ifuba.ifu_w.ifrw_bdp);
E 4
#ifdef DEBUG
D 4
				printD("hy%d: sending packet (mplen = %d, hy_olen = %d) data = ",
E 4
I 4
				printD(
		"hy%d: sending packet (mplen = %d, hy_olen = %d) data = ",
E 4
					ui->ui_unit, mplen, is->hy_olen);
D 4
				if (hy_debug_flag) hyprintdata(is->hy_ifuba.ifu_w.ifrw_addr, is->hy_olen);
E 4
I 4
				if (hy_debug_flag)
					hyprintdata(
D 9
					  is->hy_ifuba.ifu_w.ifrw_addr,
					  is->hy_olen);
E 9
I 9
					    is->hy_ifuba.ifu_w.ifrw_addr,
D 13
					    is->hy_olen);
E 13
I 13
					    is->hy_olen + HYM_SWLEN);
E 13
E 9
E 4
#endif
D 4
				hystart(ui, cmd, (mplen == 0) ? is->hy_olen : mplen,
					is->hy_ifuba.ifu_w.ifrw_info);
E 4
I 4
D 13
				hystart(ui, cmd,
D 9
				   (mplen == 0) ? is->hy_olen : mplen,
				   is->hy_ifuba.ifu_w.ifrw_info);
E 9
I 9
				    (mplen == 0) ? is->hy_olen : mplen,
				    is->hy_ifuba.ifu_w.ifrw_info);
E 9
E 4
				if (mplen != 0)
E 13
I 13
				if (mplen == 0) {
					is->hy_flags &= ~RQ_XASSOC;
					mplen = is->hy_olen;
				} else {
E 13
					is->hy_flags |= RQ_XASSOC;
I 13
				}
				hystart(ui, cmd, mplen, is->hy_ifuba.ifu_w.ifrw_info + HYM_SWLEN);
E 13
			} else if (rq & RQ_MARKDOWN) {
				is->hy_flags &= ~(RQ_MARKUP | RQ_MARKDOWN);
				is->hy_state = MARKPORT;
				is->hy_retry = 0;
				/*
D 4
				 * port number is taken from status data
E 4
I 4
				 * Port number is taken from status data
E 4
				 */
D 4
				hystart(ui, HYF_MARKP0 | (PORTNUM(&is->hy_status) << 2), 0, 0);
E 4
I 4
				hystart(ui,
D 5
				  HYF_MARKP0 | (PORTNUM(&is->hy_status) << 2),
				  0, 0);
E 5
I 5
				 (int)(HYF_MARKP0|(PORTNUM(&is->hy_status)<<2)),
				 0, 0);
E 5
E 4
			} else if (rq & RQ_MARKUP) {
				register struct ifnet *ifp = &is->hy_if;
D 4
				register struct sockaddr_in *sin = (struct sockaddr_in *)&ifp->if_addr;
E 4
I 4
D 14
				register struct sockaddr_in *sin =
				   (struct sockaddr_in *)&ifp->if_addr;
E 14
E 4

D 4
				is->hy_flags &= ~(RQ_MARKUP);
E 4
I 4
				is->hy_flags &= ~RQ_MARKUP;
E 4
				is->hy_retry = 0;
				/*
D 4
				 * Fill in the internet address from the status buffer
E 4
I 4
D 8
				 * Fill in the Internet address
E 8
I 8
				 * Fill in the host number
E 8
				 * from the status buffer
E 4
				 */
D 4
				printf("hy%d: unit number 0x%x port %d type %x microcode level 0x%x\n",
E 4
I 4
				printf(
	"hy%d: unit number 0x%x port %d type %x microcode level 0x%x\n",
E 4
					ui->ui_unit,
					is->hy_stat.hyc_uaddr,
					PORTNUM(&is->hy_status),
D 4
					(is->hy_stat.hyc_atype[0]<<8) | is->hy_stat.hyc_atype[1],
E 4
I 4
					(is->hy_stat.hyc_atype[0]<<8) |
						is->hy_stat.hyc_atype[1],
E 4
					is->hy_stat.hyc_atype[2]);

D 4
				ifp->if_host[0] = (is->hy_stat.hyc_uaddr << 8) | PORTNUM(&is->hy_status);
E 4
I 4
D 14
				ifp->if_host[0] =
E 14
I 14
				is->hy_host =
E 14
				  (is->hy_stat.hyc_uaddr << 8) |
					PORTNUM(&is->hy_status);
E 4
D 8
				sin->sin_family = AF_INET;
E 8
D 4
				sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
E 4
I 4
D 13
				sin->sin_addr =
				   if_makeaddr(ifp->if_net, ifp->if_host[0]);
E 13
E 4
				ifp->if_flags |= IFF_UP;
D 14
				if_rtinit(ifp, RTF_UP);
E 14
#ifdef HYLOG
				hylog(HYL_UP, 0, (char *)0);
#endif
D 4

E 4
			} else {
				is->hy_state = WAITING;
				is->hy_retry = 0;
				hystart(ui, HYF_WAITFORMSG, 0, 0);
			}
		}
I 4
		break;
E 4
	}
D 4
	break;
E 4

	case STATSENT:
D 4

		bcopy(is->hy_ifuba.ifu_r.ifrw_addr, &is->hy_status, sizeof(struct hy_status));
E 4
I 4
D 5
		bcopy(is->hy_ifuba.ifu_r.ifrw_addr, &is->hy_status,
E 5
I 5
		bcopy(is->hy_ifuba.ifu_r.ifrw_addr, (caddr_t)&is->hy_status,
E 5
		  sizeof (struct hy_status));
E 4
#ifdef DEBUG
D 4
		printD("hy%d: status - %x %x %x %x %x %x %x %x\n", ui->ui_unit,
			is->hy_status.hys_gen_status, is->hy_status.hys_last_fcn,
			is->hy_status.hys_resp_trunk, is->hy_status.hys_status_trunk,
			is->hy_status.hys_recd_resp, is->hy_status.hys_error,
			is->hy_status.hys_caddr, is->hy_status.hys_pad);
E 4
I 4
		printD("hy%d: status - %x %x %x %x %x %x %x %x\n",
			ui->ui_unit, is->hy_status.hys_gen_status,
			is->hy_status.hys_last_fcn,
			is->hy_status.hys_resp_trunk,
			is->hy_status.hys_status_trunk,
			is->hy_status.hys_recd_resp,
			is->hy_status.hys_error,
			is->hy_status.hys_caddr,
			is->hy_status.hys_pad);
E 4
#endif
		is->hy_state = IDLE;
#ifdef HYLOG
D 4
		hylog(HYL_STATUS, sizeof(struct hy_status), (char *)&is->hy_status);
E 4
I 4
		hylog(HYL_STATUS, sizeof (struct hy_status),
			(char *)&is->hy_status);
E 4
#endif
#ifdef HYELOG
		{
			register int i;
			
			i = is->hy_status.hys_error;
D 13
			if (i < HYE_MAX)
E 13
I 13
			if (i > HYE_MAX)
E 13
				i = HYE_MAX;
			switch (is->hy_status.hys_last_fcn) {
				case HYF_XMITLOCMSG:
					i += HYE_MAX+1;	/* fall through */
				case HYF_XMITLSTDATA:
					i += HYE_MAX+1;	/* fall through */
				case HYF_XMITMSG:
					i += HYE_MAX+1;
			}
			hy_elog[i]++;
		}
#endif
		break;

	case RSTATSENT: {
D 4
		register struct hy_stat *p = (struct hy_stat *) is->hy_ifuba.ifu_r.ifrw_addr;
E 4
I 4
		register struct hy_stat *p =
			(struct hy_stat *)is->hy_ifuba.ifu_r.ifrw_addr;
E 4

D 13
		is->hy_stat.hyc_msgcnt = ntohl(p->hyc_msgcnt);
		is->hy_stat.hyc_dbcnt = ntohl(p->hyc_dbcnt);
		is->hy_stat.hyc_tbusy = ntohl(p->hyc_tbusy);
		is->hy_stat.hyc_hwret = ntohl(p->hyc_hwret);
		is->hy_stat.hyc_crcbad = ntohl(p->hyc_crcbad);
		is->hy_stat.hyc_mcret = ntohl(p->hyc_mcret);
		is->hy_stat.hyc_tdabort = ntohl(p->hyc_tdabort);
		is->hy_stat.hyc_atype[0] = p->hyc_atype[0];
		is->hy_stat.hyc_atype[1] = p->hyc_atype[1];
		is->hy_stat.hyc_atype[2] = p->hyc_atype[2];
		is->hy_stat.hyc_uaddr = p->hyc_uaddr;
E 13
I 13
		bcopy((caddr_t)p, (caddr_t)&is->hy_stat, sizeof(struct hy_stat));
E 13
D 4

E 4
#ifdef DEBUG
D 4
		printD("hy%d: statistics - msgcnt %d dbcnt %d hwret %d tbusy %d crcbad %d\n",
E 4
I 4
D 13
		printD(
	"hy%d: statistics - msgcnt %d dbcnt %d hwret %d tbusy %d crcbad %d\n",
E 13
I 13

		printD("hy%d: statistics - df0 %d df1 %d df2 %d df3 %d\n",
E 13
E 4
			ui->ui_unit,
D 13
			is->hy_stat.hyc_msgcnt, is->hy_stat.hyc_dbcnt,
			is->hy_stat.hyc_tbusy, is->hy_stat.hyc_hwret,
			is->hy_stat.hyc_crcbad);
		printD("	mcret %d tdabort %d atype %x %x %x uaddr %x\n",
			is->hy_stat.hyc_mcret, is->hy_stat.hyc_tdabort,
E 13
I 13
			(is->hy_stat.hyc_df0[0]<<16) | (is->hy_stat.hyc_df0[1]<<8) | is->hy_stat.hyc_df0[2],
			(is->hy_stat.hyc_df1[0]<<16) | (is->hy_stat.hyc_df1[1]<<8) | is->hy_stat.hyc_df1[2],
			(is->hy_stat.hyc_df2[0]<<16) | (is->hy_stat.hyc_df2[1]<<8) | is->hy_stat.hyc_df2[2],
			(is->hy_stat.hyc_df3[0]<<16) | (is->hy_stat.hyc_df3[1]<<8) | is->hy_stat.hyc_df3[2]);
		printD("	ret0 %d ret1 %d ret2 %d ret3 %d\n",
			(is->hy_stat.hyc_ret0[0]<<16) | (is->hy_stat.hyc_ret0[1]<<8) | is->hy_stat.hyc_ret0[2],
			(is->hy_stat.hyc_ret1[0]<<16) | (is->hy_stat.hyc_ret1[1]<<8) | is->hy_stat.hyc_ret1[2],
			(is->hy_stat.hyc_ret2[0]<<16) | (is->hy_stat.hyc_ret2[1]<<8) | is->hy_stat.hyc_ret2[2],
			(is->hy_stat.hyc_ret3[0]<<16) | (is->hy_stat.hyc_ret3[1]<<8) | is->hy_stat.hyc_ret3[2]);
		printD("	cancel %d abort %d atype %x %x %x uaddr %x\n",
			(is->hy_stat.hyc_cancel[0]<<8) | is->hy_stat.hyc_cancel[1],
			(is->hy_stat.hyc_abort[0]<<8) | is->hy_stat.hyc_abort[1],
E 13
			is->hy_stat.hyc_atype[0], is->hy_stat.hyc_atype[1],
			is->hy_stat.hyc_atype[2], is->hy_stat.hyc_uaddr);
#endif
		is->hy_state = IDLE;
#ifdef HYLOG
D 4
		hylog(HYL_STATISTICS, sizeof(struct hy_stat), (char *)&is->hy_stat);
E 4
I 4
		hylog(HYL_STATISTICS, sizeof (struct hy_stat),
			(char *)&is->hy_stat);
E 4
#endif
		break;
	}

	case CLEARSENT:
		is->hy_state = IDLE;
		break;

	case ENDOPSENT:
		is->hy_state = IDLE;
		break;

	case RECVSENT: {
D 4
			register struct hy_hdr *hyh;
			register unsigned len;
E 4
I 4
D 13
		register struct hy_hdr *hyh;
E 13
I 13
		register struct hym_hdr *hym;
E 13
		register unsigned len;
E 4

D 4
#ifdef SUPBDP
			if (is->hy_ifuba.ifu_flags & UBA_NEEDBDP)	/* purge the BDP */
				UBAPURGE(is->hy_ifuba.ifu_uba, is->hy_ifuba.ifu_r.ifrw_bdp);
#endif
			hyh = (struct hy_hdr *) (is->hy_ifuba.ifu_r.ifrw_addr);
			len = (0xffff & (addr->hyd_wcr - is->hy_lastwcr)) << 1;
			if (len > MPSIZE) {
				printf("hy%d: RECVD MP > MPSIZE (%d)\n", ui->ui_unit, len);
E 4
I 4
		if (is->hy_ifuba.ifu_flags & UBA_NEEDBDP)
			UBAPURGE(is->hy_ifuba.ifu_uba,
D 9
				is->hy_ifuba.ifu_r.ifrw_bdp);
E 9
I 9
			    is->hy_ifuba.ifu_r.ifrw_bdp);
E 9
D 13
		hyh = (struct hy_hdr *) (is->hy_ifuba.ifu_r.ifrw_addr);
E 13
I 13
		hym = (struct hym_hdr *) (is->hy_ifuba.ifu_r.ifrw_addr);
E 13
		len = (0xffff & (addr->hyd_wcr - is->hy_lastwcr)) << 1;
		if (len > MPSIZE) {
			printf("hy%d: RECVD MP > MPSIZE (%d)\n",
D 9
				ui->ui_unit, len);
E 9
I 9
			    ui->ui_unit, len);
I 13
			is->hy_state = IDLE;
E 13
E 9
E 4
#ifdef DEBUG
D 4
				hy_debug_flag = 1;
				printD("hy%d: csr = 0x%b, bar = 0x%x, wcr = 0x%x\n",
					ui->ui_unit, addr->hyd_csr, HY_CSR_BITS, addr->hyd_bar, addr->hyd_wcr);
E 4
I 4
			hy_debug_flag = 1;
			printD("hy%d: csr = 0x%b, bar = 0x%x, wcr = 0x%x\n",
				ui->ui_unit, addr->hyd_csr, HY_CSR_BITS,
				addr->hyd_bar, addr->hyd_wcr);
E 4
#endif
D 4
			}

E 4
I 4
		}
I 13
		hym->hym_mplen = len;
E 13
E 4
#ifdef DEBUG
D 4
			printD("hy%d: recvd mp, len = %d, data = ", ui->ui_unit, len);
			if (hy_debug_flag) hyprintdata((char *)hyh, len);
E 4
I 4
		printD("hy%d: recvd mp, len = %d, data = ", ui->ui_unit, len);
		if (hy_debug_flag)
D 13
			hyprintdata((char *)hyh, len);
E 13
I 13
			hyprintdata((char *)hym, len + HYM_SWLEN);
E 13
E 4
#endif
D 4
			if (hyh->hyh_ctl & H_ASSOC) {
				is->hy_state = RECVDATASENT;
				is->hy_ilen = len;
				is->hy_retry = 0;
				hystart(ui, HYF_INPUTDATA, HYMTU-len+sizeof(struct hy_hdr), is->hy_ifuba.ifu_r.ifrw_info + len);
			} else {
				hyrecvdata(ui, hyh, len);
				is->hy_state = IDLE;
			}
			break;
E 4
I 4
D 13
		if (hyh->hyh_ctl & H_ASSOC) {
E 13
I 13
		if (hym->hym_ctl & H_ASSOC) {
E 13
			is->hy_state = RECVDATASENT;
D 13
			is->hy_ilen = len;
E 13
			is->hy_retry = 0;
			hystart(ui, HYF_INPUTDATA,
D 5
			  HYMTU-len+sizeof (struct hy_hdr),
			  is->hy_ifuba.ifu_r.ifrw_info + len);
E 5
I 5
D 9
			  (int)(HYMTU-len+sizeof (struct hy_hdr)),
			  (int)(is->hy_ifuba.ifu_r.ifrw_info + len));
E 9
I 9
D 13
			    (int)(HYMTU-len+sizeof (struct hy_hdr)),
			    (int)(is->hy_ifuba.ifu_r.ifrw_info + len));
E 13
I 13
			    (int)(HYMTU + sizeof (struct hy_hdr) - len),
			    (int)(HYM_SWLEN + is->hy_ifuba.ifu_r.ifrw_info + len));
E 13
E 9
E 5
		} else {
D 5
			hyrecvdata(ui, hyh, len);
E 5
I 5
D 13
			hyrecvdata(ui, hyh, (int)len);
E 13
I 13
			hyrecvdata(ui, hym, (int)len + HYM_SWLEN);
E 13
E 5
			is->hy_state = IDLE;
E 4
		}
I 4
		break;
	}
E 4

	case RECVDATASENT: {
D 4
			register struct hy_hdr *hyh;
			register unsigned len;
E 4
I 4
D 13
		register struct hy_hdr *hyh;
E 13
I 13
		register struct hym_hdr *hym;
E 13
		register unsigned len;
E 4

D 4
#ifdef SUPBDP
			if (is->hy_ifuba.ifu_flags & UBA_NEEDBDP)	/* purge the BDP */
				UBAPURGE(is->hy_ifuba.ifu_uba, is->hy_ifuba.ifu_r.ifrw_bdp);
#endif
			hyh = (struct hy_hdr *) (is->hy_ifuba.ifu_r.ifrw_addr);
			len = (0xffff & (addr->hyd_wcr - is->hy_lastwcr)) << 1;
E 4
I 4
		if (is->hy_ifuba.ifu_flags & UBA_NEEDBDP)
			UBAPURGE(is->hy_ifuba.ifu_uba,
D 9
				is->hy_ifuba.ifu_r.ifrw_bdp);
E 9
I 9
			    is->hy_ifuba.ifu_r.ifrw_bdp);
E 9
D 13
		hyh = (struct hy_hdr *) (is->hy_ifuba.ifu_r.ifrw_addr);
E 13
I 13
		hym = (struct hym_hdr *) (is->hy_ifuba.ifu_r.ifrw_addr);
E 13
		len = (0xffff & (addr->hyd_wcr - is->hy_lastwcr)) << 1;
E 4
#ifdef DEBUG
D 4
			printD("hy%d: recvd assoc data, len = %d, data = ", ui->ui_unit, len);
			if (hy_debug_flag) hyprintdata((char *)hyh + is->hy_ilen, len);
E 4
I 4
		printD("hy%d: recvd assoc data, len = %d, data = ",
			ui->ui_unit, len);
		if (hy_debug_flag)
D 13
			hyprintdata((char *)hyh + is->hy_ilen, len);
E 13
I 13
			hyprintdata((char *)hym + hym->hym_mplen, len);
E 13
E 4
#endif
D 4
			hyrecvdata(ui, hyh, len + is->hy_ilen);
			is->hy_state = IDLE;
			break;
		}
E 4
I 4
D 5
		hyrecvdata(ui, hyh, len + is->hy_ilen);
E 5
I 5
D 13
		hyrecvdata(ui, hyh, (int)(len + is->hy_ilen));
E 13
I 13
		hyrecvdata(ui, hym, (int)(len + hym->hym_mplen + HYM_SWLEN));
E 13
E 5
		is->hy_state = IDLE;
		break;
	}
E 4

	case XMITSENT:
D 4
			if (is->hy_flags & RQ_XASSOC) {
				register unsigned len;	/* number of bytes sent in message proper */
E 4
I 4
		if (is->hy_flags & RQ_XASSOC) {
D 10
			register unsigned len;
E 10
I 10
			register int len;
E 10
E 4

D 4
				is->hy_flags &= ~RQ_XASSOC;
				is->hy_state = XMITDATASENT;
				is->hy_retry = 0;
				len = (0xffff & (addr->hyd_wcr - is->hy_lastwcr)) << 1;
				if (len > is->hy_olen) {
					printf("hy%d: xmit error - len > hy_olen [%d > %d]\n", ui->ui_unit, len, is->hy_olen);
E 4
I 4
			is->hy_flags &= ~RQ_XASSOC;
			is->hy_state = XMITDATASENT;
			is->hy_retry = 0;
			len = (0xffff & (addr->hyd_wcr - is->hy_lastwcr)) << 1;
			if (len > is->hy_olen) {
				printf(
				"hy%d: xmit error - len > hy_olen [%d > %d]\n",
				ui->ui_unit, len, is->hy_olen);
E 4
#ifdef DEBUG
D 4
					hy_debug_flag = 1;
E 4
I 4
				hy_debug_flag = 1;
E 4
#endif
D 4
				}
				hystart(ui, HYF_XMITLSTDATA, is->hy_olen - len,
					is->hy_ifuba.ifu_w.ifrw_info + len);
				break;
E 4
			}
D 4

			/* fall through to ... */
E 4
I 4
			hystart(ui, HYF_XMITLSTDATA, is->hy_olen - len,
D 9
				is->hy_ifuba.ifu_w.ifrw_info + len);
E 9
I 9
D 13
			    is->hy_ifuba.ifu_w.ifrw_info + len);
E 13
I 13
			    is->hy_ifuba.ifu_w.ifrw_info + HYM_SWLEN + len);
E 13
E 9
			break;
		}
		/* fall through to ... */
E 4
		
	case XMITDATASENT:
D 4
			hyxmitdata(ui);
			is->hy_state = IDLE;
			break;
E 4
I 4
		hyxmitdata(ui);
		is->hy_state = IDLE;
		break;
E 4

	case WAITING:	/* wait for message complete or output requested */
D 4
		if (RECV_DATA(addr))
E 4
I 4
		if (HYS_RECVDATA(addr))
E 4
			is->hy_state = IDLE;
		else {
			is->hy_state = CLEARSENT;
			is->hy_retry = 0;
			hystart(ui, HYF_CLRWFMSG, 0, 0);
		}
		break;

	case MARKPORT:
		is->hy_state = STARTUP;
I 13
		if_down(&is->hy_if);
E 13
		is->hy_if.if_flags &= ~IFF_UP;
		goto endintr;
	
	default:
D 4
		printf("hy%d: DRIVER BUG - INVALID STATE %d\n", ui->ui_unit, is->hy_state);
E 4
I 4
		printf("hy%d: DRIVER BUG - INVALID STATE %d\n",
			ui->ui_unit, is->hy_state);
E 4
		panic("HYPERCHANNEL IN INVALID STATE");
		/*NOTREACHED*/
D 4

	} /* end of switch */

E 4
I 4
	}
E 4
	if (is->hy_state == IDLE)
		goto actloop;
endintr:
I 9
	;
E 9
D 4

E 4
#ifdef DEBUG
D 4
	printD("hy%d: hyact, exit at \"%s\"\n", ui->ui_unit, hy_state_names[is->hy_state]);
E 4
I 4
	printD("hy%d: hyact, exit at \"%s\"\n", ui->ui_unit,
		hy_state_names[is->hy_state]);
E 4
#endif
D 4
	return(0);
} /* hyact */
E 4
I 4
D 5
	return (0);
E 5
}
E 4

I 13
struct sockproto hypproto = { PF_HYLINK };
struct sockaddr_in hypdst = { AF_HYLINK };
struct sockaddr_in hypsrc = { AF_HYLINK };

E 13
/*
D 9
 * Called from device interrupt when recieving data.
E 9
I 9
 * Called from device interrupt when receiving data.
E 9
 * Examine packet to determine type.  Decapsulate packet
 * based on type and pass to type specific higher-level
 * input routine.
 */
D 9
hyrecvdata(ui, hyh0, len)
E 9
I 9
D 13
hyrecvdata(ui, hyh, len)
E 13
I 13
hyrecvdata(ui, hym, len)
E 13
E 9
	struct uba_device *ui;
D 9
	struct hy_hdr *hyh0;
E 9
I 9
D 13
	register struct hy_hdr *hyh;
E 13
I 13
	register struct hym_hdr *hym;
E 13
E 9
	int len;
{
	register struct hy_softc *is = &hy_softc[ui->ui_unit];
D 9
	register struct hy_hdr *hyh = hyh0;
E 9
    	struct mbuf *m;
	register struct ifqueue *inq;

	is->hy_if.if_ipackets++;
#ifdef DEBUG
D 4
	printD("hy%d: recieved packet, len = %d (actual %d)\n", ui->ui_unit, len, len - (hyh->hyh_off + sizeof(struct hy_hdr)));
E 4
I 4
D 13
	printD("hy%d: recieved packet, len = %d (actual %d)\n",
		ui->ui_unit, len,
		len - (hyh->hyh_off + sizeof (struct hy_hdr)));
E 13
I 13
	printD("hy%d: recieved packet, len = %d\n", ui->ui_unit, len);
E 13
E 4
#endif
#ifdef HYLOG
	{
		struct {
			short hlen;
D 13
			struct hy_hdr hhdr;
E 13
I 13
			struct hym_hdr hhdr;
E 13
		} hh;
		hh.hlen = len;
D 13
		hh.hhdr = *hyh;
E 13
I 13
		hh.hhdr = *hym;
E 13
		hylog(HYL_RECV, sizeof(hh), (char *)&hh);
	}
#endif
D 4

E 4
	if (len > HYMTU + MPSIZE || len == 0)
		return;			/* sanity */
D 4

E 4
	/*
	 * Pull packet off interface.
	 */
D 16
	m = if_rubaget(&is->hy_ifuba, len, 0);
E 16
I 16
	m = if_rubaget(&is->hy_ifuba, len, 0, &is->hy_if);
E 16
D 4
	if (m == 0)
E 4
I 4
	if (m == NULL)
E 4
		return;
D 4

E 4
D 13
	switch (hyh->hyh_type) {
E 13

I 13
	/*
	 * if normal or adapter loopback response packet believe hym_type,
	 * otherwise, use the raw input queue cause it's a response from an
	 * adapter command.
	 */
	if (hym->hym_param != 0 && (u_short)hym->hym_param != 0x80ff)
		goto rawlinkin;

	switch (hym->hym_type) {

E 13
#ifdef INET
	case HYLINK_IP:
D 13
		/*
D 4
		 * strip the variable portion of the hyperchannel header
		 * (fixed portion stripped in if_rubaget)
E 4
I 4
		 * Strip the variable portion of the hyperchannel header
		 * (fixed portion stripped in if_rubaget).
E 4
		 */
		m->m_len -= hyh->hyh_off;
		m->m_off += hyh->hyh_off;
E 13
D 4
		/*
		 * sent the packet up the chain to IP
		 */
E 4
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
#endif
	default:
D 13
		m_freem(m);
		return;
E 13
I 13
	rawlinkin:
		{
			struct mbuf *m0;

			MGET(m0, M_DONTWAIT, MT_DATA);
D 16
			if (m == 0) {
E 16
I 16
			if (m0 == 0) {
E 16
				m_freem(m);
				return;
			}
			m0->m_off = MMINOFF;
			m0->m_len = sizeof(struct hym_hdr);
			m0->m_next = m;
			bcopy((caddr_t)hym, mtod(m0, caddr_t), sizeof(struct hym_hdr));
			m = m0;
			hypproto.sp_protocol = 0;
D 14
			hypdst.sin_addr = ((struct sockaddr_in *)&is->hy_if.if_addr)->sin_addr;
			hypsrc.sin_addr = if_makeaddr(is->hy_if.if_net, is->hy_if.if_host[0]);
E 14
I 14
			hypdst.sin_addr = is->hy_addr;
			hypsrc.sin_addr = is->hy_addr;
E 14
			raw_input(m, &hypproto, (struct sockaddr *)&hypsrc,
				(struct sockaddr *)&hypdst);
			return;
		}
E 13
	}
D 4

E 4
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		m_freem(m);
	} else
		IF_ENQUEUE(inq, m);
D 4
} /* hyrecvdata */
E 4
I 4
}
E 4

/*
D 4
 * transmit done, release resources, bump counters
E 4
I 4
 * Transmit done, release resources, bump counters.
E 4
 */
hyxmitdata(ui)
	struct uba_device *ui;
{
	register struct hy_softc *is = &hy_softc[ui->ui_unit];

	is->hy_if.if_opackets++;
D 4

	if (is->hy_ifuba.ifu_xtofree) {		/* free left over pages */
E 4
I 4
	if (is->hy_ifuba.ifu_xtofree) {
E 4
		m_freem(is->hy_ifuba.ifu_xtofree);
		is->hy_ifuba.ifu_xtofree = 0;
	}
D 4
} /* hyxmitdata */
E 4
I 4
}
E 4

hycancel(ui)
	register struct uba_device *ui;
{
	register struct hy_softc *is = &hy_softc[ui->ui_unit];

D 4
	if (is->hy_ifuba.ifu_xtofree) {		/* free left over pages */
E 4
I 4
	if (is->hy_ifuba.ifu_xtofree) {
E 4
		m_freem(is->hy_ifuba.ifu_xtofree);
		is->hy_ifuba.ifu_xtofree = 0;
	}
I 13
#ifdef HYLOG
	hylog(HYL_CANCEL, 0, (char *)0);
#endif
E 13
D 4

E 4
#ifdef DEBUG
D 4
	if (hy_nodebug & 1) hy_debug_flag = 1;
E 4
I 4
	if (hy_nodebug & 1)
		hy_debug_flag = 1;
E 4
#endif
D 4

E 4
#ifdef DEBUG
	printD("hy%d: cancel from state \"%s\" cmd=0x%x count=%d ptr=0x%x\n",
		ui->ui_unit, hy_state_names[is->hy_state], is->hy_savedcmd,
		is->hy_savedcount, is->hy_savedaddr);
D 4
	printD("\tflags 0x%x ilen %d olen %d lastwcr %d retry %d\n\tsaved: state %d count %d ptr 0x%x cmd 0x%x\n",
		is->hy_flags, is->hy_ilen, is->hy_olen, is->hy_lastwcr, is->hy_retry,
		is->hy_savedstate, is->hy_savedcount, is->hy_savedaddr, is->hy_savedcmd);
E 4
I 4
D 13
	printD("\tflags 0x%x ilen %d olen %d lastwcr %d retry %d\n",
		is->hy_flags, is->hy_ilen, is->hy_olen, is->hy_lastwcr,
		is->hy_retry);
E 13
I 13
	printD("\tflags 0x%x olen %d lastwcr %d retry %d\n",
		is->hy_flags, is->hy_olen, is->hy_lastwcr, is->hy_retry);
E 13
	printD("\tsaved: state %d count %d ptr 0x%x cmd 0x%x\n",
		is->hy_savedstate, is->hy_savedcount, is->hy_savedaddr,
		is->hy_savedcmd);
E 4
#endif
	is->hy_state = IDLE;
	is->hy_flags |= (RQ_ENDOP | RQ_STATUS);
	hyact(ui);
D 4
} /* hycancel */
E 4
I 4
}
E 4

#ifdef DEBUG
hyprintdata(cp, len)
	register char *cp;
	register int len;
{
	register int count = 16;
	register char *fmt;
	static char regfmt[] = "\n\t %x";

	fmt = &regfmt[2];
	while (--len >= 0) {
		printL(fmt, *cp++ & 0xff);
		fmt = &regfmt[2];
		if (--count <= 0) {
			fmt = &regfmt[0];
			count = 16;
		}
	}
	printL("\n");
}
#endif

hywatch(unit)
D 9
int unit;
E 9
I 9
	int unit;
E 9
{
	register struct hy_softc *is = &hy_softc[unit];
	register struct uba_device *ui = hyinfo[unit];
	register struct hydevice *addr = (struct hydevice *)ui->ui_addr;
	int s;

	s = splimp();
D 13
	is->hy_if.if_timer = SCANINTERVAL;
D 4
	if (is->hy_ntime > 2 && is->hy_state != WAITING && is->hy_state != STARTUP && is->hy_state != IDLE) {
E 4
I 4
	if (is->hy_ntime > 2 && is->hy_state != WAITING &&
	  is->hy_state != STARTUP && is->hy_state != IDLE) {
E 4
		printf("hy%d: watchdog timer expired\n", unit);
		hycancel(ui);
	}
E 13
#ifdef PI13
	if ((addr->hyd_csr & S_POWEROFF) != 0) {
		addr->hyd_csr |= S_POWEROFF;
		DELAY(100);
		if ((addr->hyd_csr & S_POWEROFF) == 0) {
D 13
			printf("hy%d: adapter power restored\n", unit);
E 13
I 13
			printf("hy%d: Adapter Power Restored (hywatch)\n", unit);
E 13
			is->hy_state = IDLE;
D 4
			is->hy_flags |= (RQ_MARKUP | RQ_STATISTICS | RQ_ENDOP | RQ_STATUS);
E 4
I 4
			is->hy_flags |=
			  (RQ_MARKUP | RQ_STATISTICS | RQ_ENDOP | RQ_STATUS);
E 4
			hyact(ui);
		}
	}
#endif
I 13
	if (++is->hy_ntime >= 2 && is->hy_state != WAITING &&
	  is->hy_state != STARTUP && is->hy_state != IDLE) {
#ifdef HYLOG
		printf("hy%d: watchdog timer expired in state \"%s\"\n", unit,
			hy_state_names[is->hy_state]);
#else
		printf("hy%d: watchdog timer expired in state %d\n", unit,
			is->hy_state);
#endif
		printf("hy%d: last command 0x%x, flags 0x%x, csr 0x%b\n", unit,
			is->hy_savedcmd, is->hy_flags, addr->hyd_csr, HY_CSR_BITS);
		hycancel(ui);
	}
E 13
	splx(s);
I 13
	is->hy_if.if_timer = SCANINTERVAL;
E 13
}

#ifdef HYLOG
hylog(code, len, ptr)
D 9
	int code;
	int len;
E 9
I 9
	int code, len;
E 9
	char *ptr;
{
	register unsigned char *p;
	int s;

	s = splimp();
D 4

E 4
	if (hy_log.hyl_self != &hy_log) {
		hy_log.hyl_eptr = &hy_log.hyl_buf[HYL_SIZE];
		hy_log.hyl_ptr = &hy_log.hyl_buf[0];
		hy_log.hyl_self = &hy_log;
D 13
		hy_log.hyl_enable = HYL_DISABLED;
		hy_log.hyl_onerr = HYL_CATCH1;
E 13
I 13
		hy_log.hyl_enable = HYL_CONTINUOUS;
		hy_log.hyl_onerr = HYL_CONTINUOUS;
		hy_log.hyl_count = 0;
		hy_log.hyl_icount = 16;
		hy_log.hyl_filter = 0xffff;	/* enable all */
E 13
	}
D 4

	if (hy_log.hyl_enable == HYL_DISABLED
		|| hy_log.hyl_enable == HYL_CAUGHT1
		|| hy_log.hyl_enable == HYL_CAUGHTSTATUS
		|| (hy_log.hyl_enable == HYL_CATCHSTATUS && code != HYL_STATUS))
			goto out;

E 4
I 4
D 13
	if (hy_log.hyl_enable == HYL_DISABLED ||
	  hy_log.hyl_enable == HYL_CAUGHT1 ||
	  hy_log.hyl_enable == HYL_CAUGHTSTATUS ||
	  (hy_log.hyl_enable == HYL_CATCHSTATUS && code != HYL_STATUS))
E 13
I 13
	if (hy_log.hyl_enable == HYL_DISABLED || ((1 << code) & hy_log.hyl_filter) == 0)
E 13
		goto out;
E 4
	p = hy_log.hyl_ptr;
D 4

E 4
D 13
	if (p + len + 2 >= hy_log.hyl_eptr) {
E 13
I 13
	if (p + len + 3 >= hy_log.hyl_eptr) {
E 13
D 5
		bzero(p, hy_log.hyl_eptr - p);
E 5
I 5
		bzero((caddr_t)p, (unsigned)(hy_log.hyl_eptr - p));
E 5
		p = &hy_log.hyl_buf[0];
D 13
		if (hy_log.hyl_enable == HYL_CATCH1) {
			hy_log.hyl_enable = hy_log.hyl_onerr = HYL_CAUGHT1;
E 13
I 13
		if (hy_log.hyl_enable != HYL_CONTINUOUS) {
			hy_log.hyl_enable = HYL_DISABLED;
E 13
			goto out;
		}
D 13
		if (hy_log.hyl_enable == HYL_CATCHSTATUS) {
			hy_log.hyl_enable = hy_log.hyl_onerr = HYL_CAUGHTSTATUS;
			goto out;
		}
E 13
	}
D 4

E 4
	*p++ = code;
	*p++ = len;
D 5
	bcopy(ptr, p, len);
E 5
I 5
D 9
	bcopy(ptr, (caddr_t)p, (unsigned)len);
E 9
I 9
	bcopy((caddr_t)ptr, (caddr_t)p, (unsigned)len);
I 13
	if (hy_log.hyl_count != 0 && --hy_log.hyl_count == 0) {
		*p++ = '\0';
		hy_log.hyl_enable = HYL_DISABLED;
		hy_log.hyl_count = hy_log.hyl_icount;
	}
I 18
	p += len;
E 18
	if (hy_log.hyl_wait != 0) {		/* wakeup HYGETLOG if wanted */
D 18
		hy_log.hyl_wait -= (p - hy_log.hyl_ptr) + len;
		if (hy_log.hyl_wait <= 0) {
E 18
I 18
		if (hy_log.hyl_wait <= p - hy_log.hyl_ptr) {
E 18
			wakeup((caddr_t)&hy_log);
			hy_log.hyl_wait = 0;
D 18
		}
E 18
I 18
		} else
			hy_log.hyl_wait -= p - hy_log.hyl_ptr;
E 18
	}
E 13
E 9
E 5
D 18
	hy_log.hyl_ptr = p + len;
E 18
I 18
	hy_log.hyl_ptr = p;
E 18
out:
	splx(s);
}
#endif

I 5
D 6
#ifdef notdef
E 6
/*ARGSUSED*/
E 5
D 4
hyioctl(dev, cmd, addr, flag)
	dev_t	dev;
	int	cmd;
	caddr_t	addr;
	int	flag;
E 4
I 4
D 6
hyioctl(dev, cmd, data, flag)
	dev_t dev;
E 6
I 6
hyioctl(ifp, cmd, data)
	register struct ifnet *ifp;
E 6
	int cmd;
	caddr_t	data;
D 6
	int flag;
E 6
E 4
{
I 8
D 13
	struct sockaddr_in *sin;
I 9
	struct ifreq *ifr = (struct ifreq *)data;
E 13
I 13
D 14
	struct sockaddr_in *sin = (struct sockaddr_in *)data;
E 14
I 14
	struct ifaddr *ifa = (struct ifaddr *) data;
E 14
	struct hyrsetget *sg = (struct hyrsetget *)data;
#if defined(HYLOG) || defined(HYELOG)
	struct hylsetget *sgl = (struct hylsetget *)data;
#endif
	struct hy_route *r = (struct hy_route *)&hy_route[ifp->if_unit];
E 13
E 9
E 8
D 4
	register struct hyroute *r = &hy_route[minor(dev)];
	register int s;
E 4
I 4
	int s = splimp(), error = 0;
I 13
#ifdef HYLOG
	struct hy_softc *is = &hy_softc[ifp->if_unit];
	struct {
		u_char	hstate;
		u_char	hflags;
		u_short	iflags;
		int	hcmd;	
		int	herror;
		u_long	haddr;
		u_long	hmisc;
	} hil;
E 13
E 4

I 13
	hil.hmisc = -1;
	hil.hstate = is->hy_state;
	hil.hflags = is->hy_flags;
	hil.hcmd = cmd;
#endif

E 13
D 6
	if (minor(dev) >= NHY) {
D 4
		u.u_error = ENXIO;
		return;
E 4
I 4
		error = ENXIO;
		goto bad;
E 4
	}
E 6
D 4
	s = splimp();

E 4
	switch(cmd) {
I 8

	case SIOCSIFADDR:
I 13
D 16
		if (sin->sin_family != AF_INET)
E 16
I 16
		if (ifa->ifa_addr.sa_family != AF_INET)
E 16
			return(EINVAL);
E 13
D 14
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);
E 14
I 14
		if ((ifp->if_flags & IFF_RUNNING) == 0)
			hyinit(ifp->if_unit);
		hy_softc[ifp->if_unit].hy_addr = IA_SIN(ifa)->sin_addr;
E 14
D 13
		sin = (struct sockaddr_in *)&ifr->ifr_addr;
E 13
I 13
#ifdef HYLOG
D 14
		hil.haddr = ((struct sockaddr_in *)&ifp->if_addr)->sin_addr.s_addr;
E 14
I 14
		hil.haddr = is->hy_addr.s_addr;
E 14
#endif
D 14
		ifp->if_addr = *(struct sockaddr *)sin;
E 13
		ifp->if_net = in_netof(sin->sin_addr);
D 13
		sin = (struct sockaddr_in *)&ifp->if_addr;
		sin->sin_family = AF_INET;
		sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, RTF_UP);
		else
			hyinit(ifp->if_unit);
E 13
I 13
		hyinit(ifp->if_unit);
E 14
E 13
		break;
E 8

	case HYSETROUTE:
D 4
		if (suser()) {
			if (copyin(addr, (caddr_t)r, sizeof(*r)))
				u.u_error = EFAULT;
			r->hyr_lasttime = time;
E 4
I 4
		if (!suser()) {
			error = EPERM;
D 13
			goto bad;
E 13
I 13
			goto out;
E 13
E 4
		}
I 4
D 6
		hy_route[minor(dev)] = *(struct hyroute *)data;
		hy_route[minor(dev)].hyr_lasttime = time;
E 6
I 6
D 13
		hy_route[ifp->if_unit] = *(struct hyroute *)ifr->ifr_data;
		hy_route[ifp->if_unit].hyr_lasttime = time;
E 13
I 13

		if (sg->hyrsg_len != sizeof(struct hy_route)) {
			error = EINVAL;
			goto out;
		}
		if (copyin((caddr_t)(sg->hyrsg_ptr), (caddr_t)r, sg->hyrsg_len)) {
			r->hyr_lasttime = 0;	/* disable further routing if trouble */
			error = EFAULT;
			goto out;
		}
		r->hyr_lasttime = time.tv_sec;
#ifdef HYLOG
		hil.hmisc = r->hyr_lasttime;
#endif
E 13
E 6
E 4
		break;

	case HYGETROUTE:
D 4
		if (copyout((caddr_t)r, addr, sizeof(*r)))
			u.u_error = EFAULT;
E 4
I 4
D 6
		*(struct hyroute *)data = hy_route[minor(dev)];
E 6
I 6
D 13
		*(struct hyroute *)ifr->ifr_data = hy_route[ifp->if_unit];
E 13
I 13
		if (sg->hyrsg_len < sizeof(struct hy_route)) {
			error = EINVAL;
			goto out;
		}
		if (copyout((caddr_t)r, (caddr_t) (sg->hyrsg_ptr), sizeof(struct hy_route))) {
			error = EFAULT;
			goto out;
		}
E 13
E 6
E 4
		break;

I 13
#ifdef HYELOG
	case HYGETELOG:
		if (sgl->hylsg_len < sizeof(hy_elog)) {
			error = EINVAL;
			goto out;
		}
		if (copyout((caddr_t)hy_elog, sgl->hylsg_ptr, sizeof(hy_elog))) {
			error = EFAULT;
			goto out;
		}
		if (sgl->hylsg_cmd) {
			if (!suser()) {
				error = EPERM;
				goto out;
			}
			bzero((caddr_t)hy_elog, sizeof(hy_elog));
		}
		break;
#endif

#ifdef HYLOG
	case HYSETLOG:
		if (!suser()) {
			error = EPERM;
			goto out;
		}
		hy_log.hyl_enable = HYL_DISABLED;
		hylog(HYL_NOP, 0, (char *)0);		/* force log init */
		hy_log.hyl_enable = sgl->hylsg_cmd & 0x0f;
		hy_log.hyl_onerr = (sgl->hylsg_cmd >> 4) & 0x0f;
		hy_log.hyl_filter = (sgl->hylsg_cmd >> 8) & 0xffffff;
		hy_log.hyl_count = hy_log.hyl_icount = sgl->hylsg_len;
		wakeup((caddr_t)&hy_log);	/* wakeup sleeping HYGETLOG */
		break;

	case HYGETLOG:
		if (sgl->hylsg_len < sizeof(hy_log)) {
			error = EINVAL;
			goto out;
		}
		if (sgl->hylsg_cmd != 0) {
			if (hy_log.hyl_wait) {
				error = EBUSY;
				goto out;
			}
			hy_log.hyl_wait = sgl->hylsg_cmd;
D 19
			sleep((caddr_t)&hy_log);
E 19
I 19
			sleep((caddr_t)&hy_log, PZERO - 1);
E 19
		}

		if (copyout((caddr_t)&hy_log, sgl->hylsg_ptr, sizeof(hy_log))) {
			error = EFAULT;
			goto out;
		}
		break;
#endif

E 13
	default:
D 4
		u.u_error = ENXIO;
E 4
I 4
D 6
		error = ENXIO;
E 6
I 6
		error = EINVAL;
E 6
E 4
		break;
	}
I 4
D 13
bad:
E 13
I 13
out:
#ifdef HYLOG
	hil.herror = error;
	hil.iflags = ifp->if_flags;
D 14
	hil.haddr = ((struct sockaddr_in *)&ifp->if_addr)->sin_addr.s_addr;
E 14
I 14
	hil.haddr = is->hy_addr.s_addr;
E 14
	hylog(HYL_IOCTL, sizeof(hil), (char *)&hil);
#endif
E 13
E 4
	splx(s);
I 4
	return (error);
E 4
}
I 5
D 6
#endif
E 6
E 5
I 4
#endif
E 4
E 1
