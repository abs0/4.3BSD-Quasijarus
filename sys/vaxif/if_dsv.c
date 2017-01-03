/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
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
 *	@(#)if_dsv.c	7.1 (Berkeley) 3/26/00
 */

#include "dsv.h"
#if NDSV > 0

/*
 * DEC DSV11 interface
 *
 *	Michael Sokolov
 *	Quasijarus Project
 *	International Free Computing Task Force
 */
#include "../machine/pte.h"

#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"
#include "syslog.h"

#include "../net/if.h"
#include "../net/if_hdlc.h"
#include "../net/netisr.h"
#include "../net/route.h"

#ifdef INET
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"
#include "../netinet/if_ether.h"
#endif

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "if_dsvreg.h"
#include "if_uba.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"

/*
 * The DSV11 is one device bus-wise (CSR, vector, etc.) and appears as one
 * device in the kernel config file (the dsv device). However, each DSV11 has 2
 * sync serial channels, each of which is one network interface for us. Thus we
 * are one device to the autoconf code, but two interfaces to the network code.
 * We call each DSV11 channel interface dsvc<n>, where n is the number of the
 * dsv device times 2 plus the channel number on the device.
 * We maintain DMA structures per channel/interface, since it's much easier and
 * possible because the device doesn't do DMA other than when receiving or
 * transmitting a packet on a channel.
 */

#define	NDSVC	(NDSV*2)

#define	NXMT	3	/* number of transmit buffers */
#define	NRCV	7	/* number of receive buffers (must be > 1) */

#define	USERFLAGS_INTLOOP	0x0001		/* Internal Loopback */
#define	USERFLAGS_INTCLKENAB	0x0002		/* Internal Clock Enable */
#define	USERFLAGS_INTCLKRATE	0x001C		/* Internal Clock Rate */
#define	USERFLAGS_INTCLKRATE_SHIFT	2
#define	USERFLAGS_DRIVER	0x01E0		/* Cable Driver Select */
#define	USERFLAGS_DRIVER_SHIFT		5
#define	USERFLAGS_NRZI		0x0200		/* NRZI */
#define	USERFLAGS_USEINTCLK	0x0400		/* Clock TX from internal */

int	dsvdebug = 0;

int	dsvprobe(), dsvattach(), dsvintr();
struct	uba_device *dsvinfo[NDSV];
u_short dsvstd[] = { 0 };
struct	uba_driver dsvdriver =
	{ dsvprobe, 0, dsvattach, 0, dsvstd, "dsv", dsvinfo };
int	dsvcinit(),dsvcoutput(),dsvcioctl(),dsvcreset();


/*
 * Device software status per device.
 */
struct	dsv_softc {
	int	dds_vector;		/* Q-bus interrupt vector */
	int	dds_ipl;		/* Q-bus IPL */
	u_char	dds_hwrev;		/* board hardware rev */
	u_char	dds_fwrev;		/* board firmware rev */
	u_char	dds_macaddr[6];		/* hardware MAC address */
	int	dds_flags;
#define	DDSF_STARTED	1		/* FLAG_RUN set */
#define	DDSF_INITDONE	2		/* the initial command completed */
	u_char	dds_lastcmd;		/* cmd blk # for last command issued */
	u_char	dds_lastrsp;		/* cmd blk # for last response reaped */
	u_char	dds_cbinfo[NCMDBLKS];	/* info associated with cmd blks */
	u_char	dds_freelisthead;	/* free command blocks list head */
} dsv_softc[NDSV];

/*
 * Channel/interface software status per channel/interface.
 *
 * Each interface is referenced by a network interface structure,
 * ds_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct	dsvc_softc {
	struct	ifnet ds_if;		/* network-visible interface */
	int	ds_flags;
#define	DSF_INTRANS	1		/* in state transition */
#define	DSF_WEDGED	2		/* wedged, don't touch */
	int	ds_state;
#define	DSS_SHUTDOWN	0		/* channel shut down */
#define	DSS_PARAMSET	1		/* channel parameters set */
#define	DSS_RUNNING	2		/* channel fully up and running */
	struct	ifubinfo ds_deuba;	/* unibus resource structure */
	struct	ifrw ds_ifr[NRCV];	/* unibus receive maps */
	u_char	ds_rbufstat[NRCV];	/* receive buffer status */
	struct	ifxmt ds_ifw[NXMT];	/* unibus xmt maps */
	u_char	ds_xbuffreelist[NXMT];	/* transmit buffer free list */
	u_char	ds_xbuffreelisthead;	/* transmit buffer free list head */
} dsvc_softc[NDSVC];

/*
 * Device management routines.
 */

dsvprobe(reg, ui)
	caddr_t reg;
	struct uba_device *ui;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct dsvdevice *addr = (struct dsvdevice *)reg;
	register struct dsv_softc *dds = &dsv_softc[ui->ui_unit];
	register i;
	int s;

#ifdef lint
	br = 0; cvec = br; br = cvec;
	i = 0; dsvintr(i);
#endif

	/*
	 * Here if the DSV11 is present, it will be in the processing of
	 * resetting after the Q-bus reset. First we wait for this reset to
	 * finish. According to EK-DSV11-TD the reset takes up to 8 s.
	 * After that we check the device type code in the FLAG register to
	 * make sure that it's the DSV11 code and make sure that the RUN bit is
	 * not set (if it is, something really weird must be going on).
	 * Finally, we check CMDRL for the successful self-test code.
	 */
	for (i = 0; i < 90 && (addr->reg_flag & FLAG_RSET); i++)
		DELAY(100000);
	if ((addr->reg_flag & (FLAG_RSET | FLAG_RUN)) ||
	    ((addr->reg_flag & FLAG_DEVTYPE) >> FLAG_DEVTYPE_SHIFT) !=
	    DEVTYPE_DSV11)
		return(0);
	if (addr->reg_cmdrl != 0xAAAA)
		return(0);

	/*
	 * Now we do a minimal run of the device to make it interrupt. After
	 * that we reset it to put it back in its undisturbed state.
	 */
	addr->reg_cmar = INITBLK_OFF_LSTHEADS;
	addr->reg_cmdrl = CMDBLK_SIZE;
	addr->reg_cmdrh = 0;
	addr->reg_cmar = INITBLK_OFF_VECTOR;
	addr->reg_cmdr = uba_hd[numuba].uh_lastiv - 4;
	addr->reg_cmar = CMDBLK_SIZE + CMDBLK_OFF_LINKS;
	addr->reg_cmdrl = 0;
	addr->reg_cmdrh = 0;
	addr->reg_cmar = CMDBLK_SIZE + CMDBLK_OFF_FUNC;
	addr->reg_cmdr = CMD_DEVPARAM;
	addr->reg_cmar = CMDBLK_SIZE + CMDBLK_OFF_BUFLEN;
	addr->reg_cmdr = 0;
	addr->reg_cmar = CMDBLK_SIZE + CMDBLK_OFF_BUFADDR;
	addr->reg_cmdr = 0;

	s = spl6();
	addr->reg_flag = FLAG_INTE | FLAG_RUN | FLAG_CMDLISTVAL | FLAG_CMDAVAIL;
	DELAY(100000);
	dds->dds_ipl = br = qbgetpri();
	splx(s);
	addr->reg_flag = FLAG_RSET;
	return(sizeof(struct dsvdevice));
}

/*
 * Device exists. We bring it up here because it doesn't cost us anything (no
 * uba DMA resources allocated and the device won't bother us with interrupts
 * while it's idle). Then we inform the system about its two
 * channels/interfaces. The system will initialize each channel/interface if
 * and when it needs it.
 */
dsvattach(ui)
	struct uba_device *ui;
{
	register struct dsv_softc *dds = &dsv_softc[ui->ui_unit];
	int chan;
	register i;

	/*
	 * As first-order business, permanently reserve our vector for
	 * ourselves.
	 */
	dds->dds_vector = (uba_hd[numuba].uh_lastiv -= 4);
	/* Now initialize the device. */
	if (!dsvinit(ui->ui_unit))
		return;
	for (i = 0; i < 1000 && !(dds->dds_flags & DDSF_INITDONE); i++)
		DELAY(100);
	if (!(dds->dds_flags & DDSF_INITDONE)) {
		printf("dsv%d: no response to Return Device Parameters\n",
		    ui->ui_unit);
		return;
	}
	printf("dsv%d: hardware rev %d, firmware rev %d, MAC address %s\n",
	    ui->ui_unit, dds->dds_hwrev, dds->dds_fwrev,
	    ether_sprintf(dds->dds_macaddr));

	/* Now inform the system about our two interfaces. */
	for (chan = 0; chan < 2; chan++) {
		register struct dsvc_softc *ds =
					&dsvc_softc[(ui->ui_unit << 1) + chan];
		register struct ifnet *ifp = &ds->ds_if;

		ifp->if_unit = (ui->ui_unit << 1) + chan;
		ifp->if_name = "dsvc";
		ifp->if_mtu = ETHERMTU;
		ifp->if_flags = IFF_POINTOPOINT;
		ifp->if_init = dsvcinit;
		ifp->if_output = dsvcoutput;
		ifp->if_ioctl = dsvcioctl;
		ifp->if_reset = dsvcreset;
		ds->ds_deuba.iff_flags = UBA_CANTWAIT;
		if_attach(ifp);
	}
}

/*
 * Initialize the DSV11 device.
 */
dsvinit(unit)
	int unit;
{
	register struct dsv_softc *dds = &dsv_softc[unit];
	register struct dsvdevice *addr =
				(struct dsvdevice *) dsvinfo[unit]->ui_addr;
	register i;
	int s;
	struct dsv_cmdblk cmd;

	/*
	 * Here we expect the device to be finishing its reset just like in
	 * dsvprobe, either after the FLAG_RSET we do at the end of dsvprobe or
	 * after a uba reset.
	 */
	for (i = 0; i < 90 && (addr->reg_flag & FLAG_RSET); i++)
		DELAY(100000);
	if (addr->reg_flag & (FLAG_RSET | FLAG_RUN)) {
		printf("dsv%d: reset failed, FLAG=%b\n", unit, addr->reg_flag,
		    FLAG_BITS);
		return(0);
	}
	if (addr->reg_cmdrl != 0xAAAA) {
		printf("dsv%d: self-test failed, CMDRL=0x%x, CMDRH=0x%x\n",
		    unit, addr->reg_cmdrl, addr->reg_cmdrh);
		return(0);
	}

	/*
	 * Now initialize the command memory structures and our state info
	 * about them.
	 */
	addr->reg_cmar = INITBLK_OFF_LSTHEADS;
	addr->reg_cmdrl = 0;
	addr->reg_cmdrh = CMDBLK_SIZE;
	addr->reg_cmar = INITBLK_OFF_VECTOR;
	addr->reg_cmdr = dds->dds_vector;
	addr->reg_cmar = CMDBLK_SIZE + CMDBLK_OFF_LINKS;
	addr->reg_cmdrl = 0;
	addr->reg_cmdrh = 0;
	dds->dds_lastcmd = 0;
	dds->dds_lastrsp = 1;
	for (i = 2; i < NCMDBLKS - 1; i++)
		dds->dds_cbinfo[i] = i + 1;
	dds->dds_cbinfo[NCMDBLKS - 1] = 0;
	dds->dds_freelisthead = 2;

	/* Now RUN the device! */
	s = spl6();
	addr->reg_flag = FLAG_INTE | FLAG_RUN;
	if ((addr->reg_flag & (FLAG_INTE | FLAG_RSET | FLAG_RUN |
	    FLAG_RSPAVAIL)) != (FLAG_INTE | FLAG_RUN)) {
		splx(s);
		printf("dsv%d: RUN failed, FLAG=%b\n", unit, addr->reg_flag,
		    FLAG_BITS);
		return(0);
	}
	dds->dds_flags |= DDSF_STARTED;
	splx(s);

	/*
	 * Now issue the Return Device Parameters command.
	 */
	bzero(&cmd, sizeof(struct dsv_cmdblk));
	cmd.cmd_cmd = CMD_DEVPARAM;
	s = spl6();
	dsvcommand(unit, &cmd);
	splx(s);
	return(1);
}

/*
 * Issue a command to the device.
 * Must be called at the device's spl.
 */
dsvcommand(unit, cmd)
	int unit;
	struct dsv_cmdblk *cmd;
{
	register struct dsv_softc *dds = &dsv_softc[unit];
	register struct dsvdevice *addr =
				(struct dsvdevice *) dsvinfo[unit]->ui_addr;
	int blk;

	/* First acquire a free command block. */
	blk = dds->dds_freelisthead;
	if (!blk)
		panic("dsv no free command block");
	dds->dds_freelisthead = dds->dds_cbinfo[blk];

	/* Now fill it in the command memory. */
	addr->reg_cmar = (blk << CMDBLK_SHIFT) + CMDBLK_OFF_LINKS;
	addr->reg_cmdrl = 0;
	addr->reg_cmdrh = 0;
	addr->reg_cmar = (blk << CMDBLK_SHIFT) + CMDBLK_OFF_FUNC;
	addr->reg_cmdr = cmd->cmd_func;
	addr->reg_cmar = (blk << CMDBLK_SHIFT) + CMDBLK_OFF_BUFLEN;
	addr->reg_cmdr = cmd->cmd_buflen;
	addr->reg_cmar = (blk << CMDBLK_SHIFT) + CMDBLK_OFF_BUFADDR;
	addr->reg_cmdr = cmd->cmd_bufaddr;
	addr->reg_cmar = (blk << CMDBLK_SHIFT) + CMDBLK_OFF_P1;
	addr->reg_cmdr = cmd->cmd_p1;
	addr->reg_cmar = (blk << CMDBLK_SHIFT) + CMDBLK_OFF_P2;
	addr->reg_cmdr = cmd->cmd_p2;

	/* Now put it on the command list. */
	if (dds->dds_lastcmd) {
		addr->reg_cmar = (dds->dds_lastcmd << CMDBLK_SHIFT) +
		    CMDBLK_OFF_LINKS;
		addr->reg_cmdrl = blk << CMDBLK_SHIFT;
		addr->reg_flag = FLAG_INTE | FLAG_CMDAVAIL;
	} else {
		addr->reg_cmar = INITBLK_OFF_LSTHEADS;
		addr->reg_cmdrl = blk << CMDBLK_SHIFT;
		addr->reg_flag = FLAG_INTE | FLAG_CMDLISTVAL | FLAG_CMDAVAIL;
	}
	dds->dds_lastcmd = blk;
	return(blk);
}

dsvintr(unit)
	int unit;
{
	struct uba_device *ui = dsvinfo[unit];
	register struct dsvdevice *addr = (struct dsvdevice *)ui->ui_addr;
	register struct dsv_softc *dds = &dsv_softc[unit];

	splx(dds->dds_ipl);

	/* Ignore interrupts when we shouldn't be getting any. */
	if (!(dds->dds_flags & DDSF_STARTED))
		return;

	/* If the device quit running, complain about it. */
	if (!(addr->reg_flag & FLAG_RUN)) {
		int s;

		printf("dsv%d: quit running, FLAG=%b\n", unit, addr->reg_flag,
		    FLAG_BITS);
		dds->dds_flags &= ~(DDSF_STARTED | DDSF_INITDONE);
		dsvc_softc[unit << 1].ds_flags |= DSF_WEDGED;
		dsvc_softc[(unit << 1) + 1].ds_flags |= DSF_WEDGED;
		s = splimp();
		if_qflush(&dsvc_softc[unit << 1].ds_if.if_snd);
		if_qflush(&dsvc_softc[(unit << 1) + 1].ds_if.if_snd);
		splx(s);
		return;
	}

	/* The real fun: handling responses. */
	if (addr->reg_flag & FLAG_RSPAVAIL) {
		addr->reg_flag = FLAG_INTE | FLAG_RSPAVAIL;
		/* Process the response list until it's empty. */
		for (;;) {
			struct dsv_cmdblk cmd;

			addr->reg_cmar = (dds->dds_lastrsp << CMDBLK_SHIFT) +
			    CMDBLK_OFF_LINKS;
			if (!addr->reg_cmdrh)
				break;
			dds->dds_cbinfo[dds->dds_lastrsp] =
			    dds->dds_freelisthead;
			dds->dds_freelisthead = dds->dds_lastrsp;
			dds->dds_lastrsp = addr->reg_cmdrh >> CMDBLK_SHIFT;
			addr->reg_cmar = (dds->dds_lastrsp << CMDBLK_SHIFT) +
			    CMDBLK_OFF_FUNC;
			cmd.cmd_func = addr->reg_cmdr;
			addr->reg_cmar = (dds->dds_lastrsp << CMDBLK_SHIFT) +
			    CMDBLK_OFF_BUFLEN;
			cmd.cmd_buflen = addr->reg_cmdr;
			addr->reg_cmar = (dds->dds_lastrsp << CMDBLK_SHIFT) +
			    CMDBLK_OFF_BUFADDR;
			cmd.cmd_bufaddr = addr->reg_cmdr;
			addr->reg_cmar = (dds->dds_lastrsp << CMDBLK_SHIFT) +
			    CMDBLK_OFF_P1;
			cmd.cmd_p1 = addr->reg_cmdr;
			addr->reg_cmar = (dds->dds_lastrsp << CMDBLK_SHIFT) +
			    CMDBLK_OFF_P2;
			cmd.cmd_p2 = addr->reg_cmdr;

			/* Take care of command list processing issues. */
			if (cmd.cmd_cmdsts & CMDSTS_ENDCMDLIST) {
				u_short cmdlink;

				addr->reg_cmar = (dds->dds_lastrsp <<
				    CMDBLK_SHIFT) + CMDBLK_OFF_LINKS;
				cmdlink = addr->reg_cmdrl;
				if (cmdlink) {
					addr->reg_cmar = INITBLK_OFF_LSTHEADS;
					addr->reg_cmdrl = cmdlink;
					addr->reg_flag = FLAG_INTE |
					    FLAG_CMDLISTVAL | FLAG_CMDAVAIL;
				} else
					dds->dds_lastcmd = 0;
			}

			/*
			 * Now process the response based on what command it is
			 * for.
			 */
			switch (cmd.cmd_cmd) {
			case CMD_DEVPARAM:
				dds->dds_hwrev = cmd.cmd_p1b3;
				dds->dds_fwrev = cmd.cmd_p1b1;
				bcopy(&cmd.cmd_buflen, dds->dds_macaddr, 6);
				dds->dds_flags |= DDSF_INITDONE;
				break;
			case CMD_CHANPARAM:
			case CMD_INITCHAN:
			case CMD_CHGCHANPARAM:
			case CMD_RSETCHAN:
			case CMD_XMIT:
			case CMD_RECV:
			case CMD_UPDRPTMODEMSTS:
			case CMD_RPTSTSCHG:
				dsvccmddone(unit, (unit << 1) + cmd.cmd_chan,
				    &cmd, dds->dds_lastrsp);
				break;
			}
		}
	}
}

/*
 * Channel/interface management routines.
 */

/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 * As this is called per interface, we will be called twice per device. We will
 * reset on the first call and reinitialize on the second.
 */
dsvcreset(unit, uban)
	int unit, uban;
{
	int devunit = unit >> 1;
	register struct uba_device *ui;

	if (devunit >= NDSV || (ui = dsvinfo[devunit]) == 0 ||
	    ui->ui_alive == 0 || ui->ui_ubanum != uban)
		return;
	if (!(unit & 1)) {
		dsv_softc[devunit].dds_flags = 0;
		dsvc_softc[devunit << 1].ds_if.if_flags &= ~IFF_RUNNING;
		dsvc_softc[devunit << 1].ds_flags = 0;
		dsvc_softc[devunit << 1].ds_state = DSS_SHUTDOWN;
		dsvc_softc[(devunit << 1) + 1].ds_if.if_flags &= ~IFF_RUNNING;
		dsvc_softc[(devunit << 1) + 1].ds_flags = 0;
		dsvc_softc[(devunit << 1) + 1].ds_state = DSS_SHUTDOWN;
	} else {
		printf(" dsv%d", devunit);
		dsvinit(devunit);
		dsvcinit(devunit << 1);
		dsvcinit((devunit << 1) + 1);
	}
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 * Must be called at splimp.
 */
dsvcinit(unit)
	int unit;
{
	int devunit = unit >> 1;
	register struct dsvc_softc *ds = &dsvc_softc[unit];
	register struct dsv_softc *dds = &dsv_softc[devunit];
	register struct uba_device *ui = dsvinfo[devunit];
	struct ifnet *ifp = &ds->ds_if;
	struct ifaddr *ifa;
	register i;

	/*
	 * Check to see that an address has been set
	 * (both local and destination for an address family).
	 */
	for (ifa = ifp->if_addrlist; ifa; ifa = ifa->ifa_next)
		if (ifa->ifa_addr.sa_family && ifa->ifa_dstaddr.sa_family)
			break;
	if (ifa == (struct ifaddr *) 0)
		return;

	/* Make sure the device isn't wedged. */
	if (!(dds->dds_flags & DDSF_STARTED) || (ds->ds_flags & DSF_WEDGED)) {
		printf("dsvc%d: hardware not in operating condition\n", unit);
		ds->ds_if.if_flags &= ~IFF_UP;
		return;
	}

	if ((ifp->if_flags & IFF_RUNNING) == 0) {
		if (if_ubaminit(&ds->ds_deuba, ui->ui_ubanum,
		    sizeof (struct hdlc_header), (int)btoc(ETHERMTU),
		    ds->ds_ifr, NRCV, ds->ds_ifw, NXMT) == 0) { 
			printf("dsvc%d: can't initialize\n", unit);
			ds->ds_if.if_flags &= ~IFF_UP;
			return;
		}
		/* Init our state info for the receive and transmit buffers. */
		for (i = 0; i < NRCV; i++)
			ds->ds_rbufstat[i] = 0;
		for (i = 0; i < NXMT; i++)
			ds->ds_xbuffreelist[i] = i + 1;
		ds->ds_xbuffreelisthead = 0;
		ifp->if_flags |= IFF_RUNNING;
	}

	dsvcchkstate(unit);
}

/*
 * Check the channel/interface state and adjust it as necessary.
 * Must be called at the device's spl.
 */
dsvcchkstate(unit)
	int unit;
{
	int devunit = unit >> 1;
	register struct dsvc_softc *ds = &dsvc_softc[unit];
	register struct dsv_softc *dds = &dsv_softc[devunit];
	register struct uba_device *ui = dsvinfo[devunit];
	struct ifnet *ifp = &ds->ds_if;
	struct dsv_cmdblk cmd;

	/*
	 * We can do anything only when the device is running, we are not
	 * wedged or in transition, and the uba resources are secured.
	 */
	if (!(dds->dds_flags & DDSF_STARTED) || (ds->ds_flags & (DSF_WEDGED |
	    DSF_INTRANS)) || !(ifp->if_flags & IFF_RUNNING))
		return;

	if (ifp->if_flags & IFF_UP) {
		if (ds->ds_state == DSS_SHUTDOWN) {
			u_short userflags;

			bzero(&cmd, sizeof(struct dsv_cmdblk));
			cmd.cmd_cmd = CMD_INITCHAN;
			cmd.cmd_chan = unit & 1;
			cmd.cmd_p1 = CHANPAR1_IDLESYNCFLAG |
			    (BITSPERCHAR_8 << CHANPAR1_XMITBPC_SHIFT) |
			    (BITSPERCHAR_8 << CHANPAR1_RECVBPC_SHIFT) |
			    (ERRCHK_CRCCCITT1 << CHANPAR1_ERRCHK_SHIFT) |
			    (PROTO_BASICHDLC << CHANPAR1_PROTO_SHIFT);
			cmd.cmd_p2 = CHANPAR2_PRIMSTAT | CHANPAR2_RECVENAB;
			userflags = (ui->ui_flags >> ((unit & 1) ? 16 : 0)) &
			    0xFFFF;
			if (userflags & USERFLAGS_INTLOOP)
				cmd.cmd_p2 |= CHANPAR2_INTLOOP;
			if (userflags & USERFLAGS_INTCLKENAB)
				cmd.cmd_p2 |= CHANPAR2_INTCLKENAB;
			if (userflags & USERFLAGS_NRZI)
				cmd.cmd_p2 |= CHANPAR2_NRZI;
			if (userflags & USERFLAGS_USEINTCLK)
				cmd.cmd_p2 |= CHANPAR2_USEINTCLK;
			cmd.cmd_p2 |= (userflags & USERFLAGS_INTCLKRATE) <<
			    (CHANPAR2_INTCLKRATE_SHIFT -
			    USERFLAGS_INTCLKRATE_SHIFT);
			cmd.cmd_p2 |= (userflags & USERFLAGS_DRIVER) <<
			    (CHANPAR2_DRIVER_SHIFT - USERFLAGS_DRIVER_SHIFT);
			ds->ds_flags |= DSF_INTRANS;
			dsvcommand(devunit, &cmd);
		} else if (ds->ds_state == DSS_PARAMSET) {
			bzero(&cmd, sizeof(struct dsv_cmdblk));
			cmd.cmd_cmd = CMD_UPDRPTMODEMSTS;
			cmd.cmd_chan = unit & 1;
			cmd.cmd_p1b0 = MODEMCTL_VALID | MODEMCTL_RTS |
			    MODEMCTL_DTR;
			ds->ds_flags |= DSF_INTRANS;
			dsvcommand(devunit, &cmd);
		}
	} else {
		if (ds->ds_state == DSS_RUNNING) {
			bzero(&cmd, sizeof(struct dsv_cmdblk));
			cmd.cmd_cmd = CMD_UPDRPTMODEMSTS;
			cmd.cmd_chan = unit & 1;
			cmd.cmd_p1b0 = MODEMCTL_VALID;
			ds->ds_flags |= DSF_INTRANS;
			dsvcommand(devunit, &cmd);
		} else if (ds->ds_state == DSS_PARAMSET) {
			bzero(&cmd, sizeof(struct dsv_cmdblk));
			cmd.cmd_cmd = CMD_RSETCHAN;
			cmd.cmd_chan = unit & 1;
			cmd.cmd_p1 = RSETCHAN_SHUTDOWN;
			ds->ds_flags |= DSF_INTRANS;
			dsvcommand(devunit, &cmd);
		}
	}
}

/*
 * Setup output on interface.
 * Get another datagram to send off of the interface queue,
 * and map it to the interface before starting the output.
 * Must be called at splimp.
 */
dsvcstart(unit)
	int unit;
{
	int devunit = unit >> 1;
	register struct dsvc_softc *ds = &dsvc_softc[unit];
	register struct dsv_softc *dds = &dsv_softc[devunit];
	struct mbuf *m;

	/* Don't do anything if the channel isn't RUNNING. */
	if (ds->ds_state != DSS_RUNNING)
		return;

	while (ds->ds_xbuffreelisthead < NXMT) {
		u_char xbuf, blk;
		int len;
		struct dsv_cmdblk cmd;

		IF_DEQUEUE(&ds->ds_if.if_snd, m);
		if (m == 0)
			break;
		xbuf = ds->ds_xbuffreelisthead;
		ds->ds_xbuffreelisthead = ds->ds_xbuffreelist[xbuf];
		len = if_ubaput(&ds->ds_deuba, &ds->ds_ifw[xbuf], m);
		bzero(&cmd, sizeof(struct dsv_cmdblk));
		cmd.cmd_cmd = CMD_XMIT;
		cmd.cmd_chan = unit & 1;
		cmd.cmd_bufaddr = UBAI_ADDR(ds->ds_ifw[xbuf].ifw_info);
		cmd.cmd_bufsize = len;
		blk = dsvcommand(devunit, &cmd);
		dds->dds_cbinfo[blk] = xbuf;
	}
}

/*
 * Channel/interface command done handling.
 * Called at the device's spl.
 */
dsvccmddone(devunit, unit, cmd, blk)
	int devunit, unit, blk;
	struct dsv_cmdblk *cmd;
{
	register struct dsvc_softc *ds = &dsvc_softc[unit];
	register struct dsv_softc *dds = &dsv_softc[devunit];
	register bufnum;
	register i;
	struct ifxmt *ifxp;
	int s;

	/* If we aren't IFF_RUNNING, we should never receive control. */
	if (!(ds->ds_if.if_flags & IFF_RUNNING))
		return;

	switch (cmd->cmd_cmd) {
	/* state transitions */
	case CMD_RSETCHAN:
	case CMD_INITCHAN:
	case CMD_UPDRPTMODEMSTS:
		if (cmd->cmd_complsts != COMPLSTS_NORMAL) {
			printf("dsvc%d: state transition failed, cmd=0x%x complsts=0x%x\n", unit, cmd->cmd_cmd, cmd->cmd_complsts);
			ds->ds_flags |= DSF_WEDGED;
		}
		if (ds->ds_flags & DSF_WEDGED)
			return;
		switch (cmd->cmd_cmd) {
		case CMD_RSETCHAN:
			ds->ds_state = DSS_SHUTDOWN;
			break;
		case CMD_INITCHAN:
			ds->ds_state = DSS_PARAMSET;
			break;
		case CMD_UPDRPTMODEMSTS:
			if (cmd->cmd_p1b0 & MODEMCTL_DTR)
				ds->ds_state = DSS_RUNNING;
			else
				ds->ds_state = DSS_PARAMSET;
			break;
		}
		ds->ds_flags &= ~DSF_INTRANS;
		dsvcchkstate(unit);
		if (!(ds->ds_flags & DSF_INTRANS) &&
		    ds->ds_state == DSS_RUNNING)
			for (i = 0; i < NRCV; i++)
				if (!ds->ds_rbufstat[i])
					dsvchangrecv(unit, i);
		break;

	/* got something */
	case CMD_RECV:
		bufnum = dds->dds_cbinfo[blk];
		if (cmd->cmd_complsts == COMPLSTS_NORMAL) {
			u_short len = cmd->cmd_bufused;

			ds->ds_if.if_ipackets++;
			if (len >= sizeof(struct hdlc_header))
				dsvcread(ds, &ds->ds_ifr[bufnum],
					len - sizeof(struct hdlc_header));
			else {
				if (dsvdebug)
					printf("dsvc%d: runt packet (%u bytes)\n", unit, len);
				ds->ds_if.if_ierrors++;
			}
		} else if (cmd->cmd_complsts != COMPLSTS_ABORTED) {
			if (dsvdebug)
				printf("dsvc%d: receive error, complsts=0x%x\n",
					unit, cmd->cmd_complsts);
			ds->ds_if.if_ierrors++;
		}
		ds->ds_rbufstat[bufnum] = 0;
		if (!(ds->ds_flags & (DSF_INTRANS | DSF_WEDGED)) &&
		    ds->ds_state == DSS_RUNNING)
			dsvchangrecv(unit, bufnum);
		break;

	/* xmit done */
	case CMD_XMIT:
		bufnum = dds->dds_cbinfo[blk];
		ds->ds_if.if_opackets++;
		if (cmd->cmd_complsts != COMPLSTS_NORMAL) {
			if (dsvdebug)
				printf("dsvc%d: transmit error, complsts=0x%x\n", cmd->cmd_complsts);
			ds->ds_if.if_oerrors++;
		}
		ifxp = &ds->ds_ifw[bufnum];
		if (ifxp->ifw_xtofree) {
			m_freem(ifxp->ifw_xtofree);
			ifxp->ifw_xtofree = 0;
		}
		ds->ds_xbuffreelist[bufnum] = ds->ds_xbuffreelisthead;
		ds->ds_xbuffreelisthead = bufnum;
		if (!(ds->ds_flags & DSF_WEDGED)) {
			s = splimp();
			dsvcstart(unit);
			splx(s);
		}
		break;
	}
}

/*
 * Hang receive buffer rbuf.
 * Called at the device's spl.
 */
dsvchangrecv(unit, rbuf)
	int unit, rbuf;
{
	int devunit = unit >> 1;
	register struct dsvc_softc *ds = &dsvc_softc[unit];
	register struct dsv_softc *dds = &dsv_softc[devunit];
	struct dsv_cmdblk cmd;
	int blk;

	bzero(&cmd, sizeof(struct dsv_cmdblk));
	cmd.cmd_cmd = CMD_RECV;
	cmd.cmd_chan = unit & 1;
	cmd.cmd_bufaddr = UBAI_ADDR(ds->ds_ifr[rbuf].ifrw_info);
	cmd.cmd_bufsize = sizeof(struct hdlc_header) + ETHERMTU;
	blk = dsvcommand(devunit, &cmd);
	dds->dds_cbinfo[blk] = rbuf;
	ds->ds_rbufstat[rbuf] = blk;
}

/*
 * Pass a packet to the higher levels.
 * We deal with the trailer protocol here.
 * Called at the device's spl.
 */
dsvcread(ds, ifrw, len)
	register struct dsvc_softc *ds;
	struct ifrw *ifrw;
	int len;
{
	struct hdlc_header *hh;
    	struct mbuf *m;
	int off, resid;
	int s;
	register struct ifqueue *inq;

	/*
	 * Deal with trailer protocol: if type is trailer type
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
	hh = (struct hdlc_header *)ifrw->ifrw_addr;
	if (hh->hdlc_address != CISCOHDLC_ADDR_UNICAST &&
	    hh->hdlc_address != CISCOHDLC_ADDR_MULTICAST)
		return;
	hh->hdlc_type = ntohs((u_short)hh->hdlc_type);
#define	dsvcdataaddr(hh, off, type)	((type)(((caddr_t)((hh)+1)+(off))))
	if (hh->hdlc_type >= ETHERTYPE_TRAIL &&
	    hh->hdlc_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (hh->hdlc_type - ETHERTYPE_TRAIL) * 512;
		if (off >= ETHERMTU)
			return;		/* sanity */
		hh->hdlc_type = ntohs(*dsvcdataaddr(hh, off, u_short *));
		resid = ntohs(*(dsvcdataaddr(hh, off+2, u_short *)));
		if (off + resid > len)
			return;		/* sanity */
		len = off + resid;
	} else
		off = 0;
	if (len == 0)
		return;

	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; if_ubaget will then force this header
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
	m = if_ubaget(&ds->ds_deuba, ifrw, len, off, &ds->ds_if);
	if (m == 0)
		return;
	if (off) {
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
		*(mtod(m, struct ifnet **)) = ifp;
	}
	switch (hh->hdlc_type) {

#ifdef INET
	case ETHERTYPE_IP:
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
#endif

	default:
		m_freem(m);
		return;
	}

	s = splimp();
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		splx(s);
		m_freem(m);
		return;
	}
	IF_ENQUEUE(inq, m);
	splx(s);
}

/*
 * Packet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
dsvcoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
	int type, s, error;
	register struct dsvc_softc *ds = &dsvc_softc[ifp->if_unit];
	register struct mbuf *m = m0;
	register struct hdlc_header *hh;
	u_char address = CISCOHDLC_ADDR_UNICAST, control = CISCOHDLC_CONTROL;
	register int off;
	int usetrailers = !(ifp->if_flags & IFF_NOTRAILERS);

	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING) ||
	    (ds->ds_flags & DSF_WEDGED)) {
		error = ENETDOWN;
		goto bad;
	}
	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
		if (usetrailers && off > 0 && (off & 0x1ff) == 0 &&
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
			type = ETHERTYPE_TRAIL + (off>>9);
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
			*mtod(m, u_short *) = htons((u_short)ETHERTYPE_IP);
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
			goto gottrailertype;
		}
		type = ETHERTYPE_IP;
		off = 0;
		goto gottype;
#endif

	case AF_UNSPEC:
		hh = (struct hdlc_header *)dst->sa_data;
		address = hh->hdlc_address;
		control = hh->hdlc_control;
		type = hh->hdlc_type;
		goto gottype;

	default:
		printf("dsvc%d: can't handle af%d\n", ifp->if_unit,
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
	    MMINOFF + sizeof (struct hdlc_header) > m->m_off) {
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof (struct hdlc_header);
	} else {
		m->m_off -= sizeof (struct hdlc_header);
		m->m_len += sizeof (struct hdlc_header);
	}
	hh = mtod(m, struct hdlc_header *);
	hh->hdlc_address = address;
	hh->hdlc_control = control;
	hh->hdlc_type = htons((u_short)type);

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		splx(s);
		m_freem(m);
		return (ENOBUFS);
	}
	IF_ENQUEUE(&ifp->if_snd, m);
	dsvcstart(ifp->if_unit);
	splx(s);
	return (0);

bad:
	m_freem(m0);
	return (error);
}

/*
 * Process an ioctl request.
 */
dsvcioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	register struct dsvc_softc *ds = &dsvc_softc[ifp->if_unit];
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
		ifp->if_flags |= IFF_UP;
	case SIOCSIFDSTADDR:
	case SIOCSIFFLAGS:
		dsvcinit(ifp->if_unit);
		break;

	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
}
#endif
