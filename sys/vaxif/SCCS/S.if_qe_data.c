h46144
s 00172/00000/00000
d D 1.1 86/05/09 17:36:37 karels 1 0
c from DEC
e
u
U
t
T
I 1
 
/*
 * static	char	*sccsid = "@(#)if_qe_data.c	1.9	(ULTRIX)	3/13/86"
 */
 
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
 
/************************************************************************
 *			Modification History				*
 *									*
 *	Jeff Chase - 03/12/86						*
 *		Changed number of receive buffers from 8 to 25.		*
 *		The number 25 is arbitrary, but the number should be	*
 *		at least 20.						*
 *									*
 *	Larry Cohen  -	09/16/85					*
 * 		Add 43bsd alpha tape changes for subnet routing		*
 *									*
 ************************************************************************/
 
#include "qe.h"
/*
 * Digital Q-BUS to NI Adapter
 */
#include "../machine/pte.h"
 
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/vmmac.h"
#include "../h/ioctl.h"
#include "../h/errno.h"
#include "../h/time.h"
#include "../h/kernel.h"
 
#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/if_ether.h"
#include "../netpup/pup.h"
 
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "../vaxif/if_qereg.h"
#include "../vaxif/if_uba.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
 
 
#define NRCV	25	 		/* Receive descriptors		*/
#define NXMT	5	 		/* Transmit descriptors		*/
#define NTOT	(NXMT + NRCV)
#define NMULTI	12			/* Number of multicast addresses*/
 
/*
 * This constant should really be 60 because the qna adds 4 bytes of crc.
 * However when set to 60 our packets are ignored by deuna's , 3coms are
 * okay ??????????????????????????????????????????
 */
#define MINDATA 64
 
/*
 * The qeuba structures generalizes the ifuba structure
 * to an arbitrary number of receive and transmit buffers.
 */
struct	ifxmt {
	struct	ifrw x_ifrw;			/* mapping information */
	struct	pte x_map[IF_MAXNUBAMR];	/* output base pages */
	short	x_xswapd;			/* mask of clusters swapped */
	struct	mbuf *x_xtofree;		/* pages being dma'ed out */
};
 
struct	qeuba {
	short	ifu_uban;		/* uba number */
	short	ifu_hlen;		/* local net heaqer length */
	struct	uba_regs *ifu_uba;	/* uba regs, in vm */
	struct	ifrw ifu_r[NRCV];	/* receive information */
	struct	ifxmt ifu_w[NXMT];	/* transmit information */
	short	ifu_flags;		/* used during uballoc's */
};
struct qe_multi {
	u_char	qm_char[6];
};
#define MULTISIZE sizeof(struct qe_multi)
 
/*
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * is_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 */
#define	is_if	is_ac.ac_if		/* network-visible interface 	*/
#define	is_addr	is_ac.ac_enaddr		/* hardware Ethernet address 	*/
 
struct	qe_softc {
	struct	arpcom is_ac;		/* Ethernet common part 	*/
	struct	qeuba qeuba;		/* Q-bus resources 		*/
	int	setupaddr;		/* mapping info for setup pkts  */
	struct	qe_ring *rringaddr;	/* mapping info for rings	*/
	struct	qe_ring *tringaddr;	/*       ""			*/
	struct	qe_ring rring[NRCV+1];	/* Receive ring descriptors 	*/
	struct	qe_ring tring[NXMT+1];	/* Transmit ring descriptors 	*/
	u_char	setup_pkt[16][8];	/* Setup packet			*/
	struct	qe_multi multi[NMULTI];	/* Multicast address list	*/
	struct	estat ctrblk;		/* Counter block		*/
	u_char	muse[NMULTI];		/* Multicast address usage count*/
	long	ztime;			/* Time counters last zeroed	*/
	int	rindex;			/* Receive index		*/
	int	tindex;			/* Transmit index		*/
	int	otindex;		/* Old transmit index		*/
	int	qe_intvec;		/* Interrupt vector 		*/
	struct	qedevice *addr;		/* device addr			*/
	int 	setupqueued;		/* setup packet queued		*/
	int	nxmit;			/* Transmits in progress	*/
	char	*buffers;		/* Buffers for packets		*/
	int	timeout;		/* watchdog			*/
};
 
#ifdef BINARY
 
extern	struct	qe_softc qe_softc[];
extern	struct	uba_device *qeinfo[];
extern	int	nNQE;
extern  int	nNRCV;
extern	int	nNXMT;
extern	int	nNTOT;
 
#else BINARY
 
struct	qe_softc  qe_softc[NQE];
struct	uba_device *qeinfo[NQE];
int	nNQE = NQE;
int	nNXMT = NXMT;
int 	nNRCV = NRCV;
int	nNTOT = NTOT;
 
#endif
E 1
