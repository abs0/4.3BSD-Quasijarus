h11418
s 00001/00003/02090
d D 7.9 04/12/09 23:59:35 msokolov 17 16
c stop emitting old Ultrix SCCS ID in the binary
e
s 00010/00011/02083
d D 7.8 89/10/28 11:05:26 mckusick 16 15
c cannot use qbgetpri to discover interrupt priority (from Macklem)
e
s 00001/00000/02093
d D 7.7 89/01/16 11:28:42 mckusick 15 14
c fix for Exabyte tmscp tape on uVAX (4.3BSD/sys/230)
e
s 00017/00020/02076
d D 7.6 88/10/22 15:14:06 karels 14 13
c use ubaalloc macros; use qbgetpri for Q-bus device probe routines
e
s 00002/00002/02094
d D 7.5 88/08/27 07:20:47 tef 13 12
c Add support for microvax 3000.
e
s 00004/00000/02092
d D 7.4 88/05/27 16:10:14 karels 12 11
c fix intr. priority on microvax
e
s 00000/00034/02092
d D 7.3 88/05/06 17:17:32 bostic 11 10
c changes for raw{read,write} stuff
e
s 00002/00002/02124
d D 7.2 87/04/17 14:09:53 karels 10 9
c fix race in open; log excessive soft errs
e
s 00000/00000/02126
d D 7.1 86/06/05 01:17:52 mckusick 9 8
c 4.3BSD release version
e
s 00017/00015/02109
d D 5.7 86/04/28 01:33:58 kjd 8 7
c Add DEC copyright
e
s 00001/00000/02123
d D 5.6 86/03/13 11:26:32 karels 7 6
c more (obscure) lint
e
s 00000/00001/02123
d D 5.5 86/03/04 19:21:06 karels 6 5
c What do we care about quotas?!? (Especially if we don't know what they are!)
e
s 00007/00020/02117
d D 5.4 86/02/23 23:18:14 karels 5 4
c lint
e
s 00000/00001/02137
d D 5.3 86/02/21 12:09:41 karels 4 3
c missed one
e
s 00018/00024/02120
d D 5.2 86/02/20 19:53:33 karels 3 2
c lint
e
s 00384/00359/01760
d D 5.1 86/02/11 17:09:03 karels 2 1
c convert to 4.3
e
s 02119/00000/00000
d D 1.1 86/02/10 15:07:41 karels 1 0
c from DEC
e
u
U
t
T
I 1
D 2
 
E 2
I 2
/*	%W% (Berkeley) %G% */

E 2
D 17
#ifndef lint
static	char	*sccsid = "@(#)tmscp.c	1.24	(ULTRIX)	1/21/86";
#endif lint
E 17
I 17
/* from @(#)tmscp.c	1.24	(ULTRIX)	1/21/86	*/
E 17
D 2
 
E 2

I 2

E 2
/************************************************************************
 *									*
D 8
 *			Copyright (c) 1985 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
E 8
I 8
 *        Licensed from Digital Equipment Corporation 			*
 *                       Copyright (c) 					*
 *               Digital Equipment Corporation				*
 *                   Maynard, Massachusetts 				*
 *                         1985, 1986 					*
 *                    All rights reserved. 				*
E 8
 *									*
D 8
 *	Permission to use, copy, modify, and distribute this software	*
 *	and its documentation is hereby granted to licensees of the	*
 *	Regents of the University of California pursuant to their	*
 *	license agreement for the "Fourth Berkeley Software		*
 *	Distribution".							*
E 8
I 8
 *        The Information in this software is subject to change 	*
 *   without notice and should not be construed as a commitment 	*
 *   by  Digital  Equipment  Corporation.   Digital   makes  no 	*
 *   representations about the suitability of this software for 	*
 *   any purpose.  It is supplied "As Is" without expressed  or 	*
 *   implied  warranty. 						*
E 8
 *									*
D 8
 *	The information in this software is subject to change without	*
 *	notice and should not be construed as a commitment by Digital	*
 *	Equipment Corporation.  Digital makes no representations	*
 *	about suitability of this software for any purpose. It is	*
 *	supplied "as is" without express or implied warranty.		*
 *									*
 *	This software is not subject to any license of the American	*
 *	Telephone and Telegraph Company.				*
E 8
I 8
 *        If the Regents of the University of California or its 	*
 *   licensees modify the software in a manner creating  		*
 *   diriviative copyright rights, appropriate copyright  		*
 *   legends may be placed on  the drivative work in addition  		*
 *   to that set forth above. 						*
E 8
 *									*
 ************************************************************************
 * 
 * tmscp.c - TMSCP (TK50/TU81) tape device driver
 * 
 * Modification History:
 *
 * 06-Jan-86 - afd
 *	Changed the probe routine to use DELAY (not TODR).  This now
 *	works for MicroVAXen as well.  This eliminates the busy-wait
 *	for MicroVAXen so a dead TK50 controller will not hang autoconf.
 *
 * 06-Dec-85 - afd
 *	Fixed a bug in density selection.  The "set unit characteristics"
 *	command to select density, was clearing the "unit flags" field
 *	where the CACHE bit was for TU81-E.  Now the unit's "format" and
 *	"unitflgs" are saved in tms_info struct.  And are used on STUNT
 *	commands.
 *
 * 19-Oct-85 - afd
 *	Added support to the open routine to allow drives to be opened
 *	for low density (800 or 1600 bpi) use.  When the slave routine
 *	initiates a "get-unit-char" cmd, the format menu for the unit
 *	is saved in the tms_info structure. The format menu is used in the
 *	start routine to select the proper low density.
 *
 * 02-Oct-85 - afd
 *	When a tmscp-type controller is initializing, it is possible for
 *	the sa reg to become 0 between states.  Thus the init code in
 *	the interrupt routine had to be modified to reflect this.
 *
 * 21-Sep-85 - afd
 *	The TK50 declares a serious exception when a tape mark is encountered.
 *	This causes problems to dd (& other UN*X utilities).  So a flag
 *	is set in the rsp() routine when a tape mark is encountered.  If
 *	this flag is set, the start() routine appends the Clear Serious
 *	Exception modifier to the next command.
 *
 * 03-Sep-85 -- jaw
 *	messed up previous edit..
 *
 * 29-Aug-85 - jaw
 *	fixed bugs in 8200 and 750 buffered datapath handling.
 *
 * 06-Aug-85 - afd
 *   1. When repositioning records or files, the count of items skipped
 *	does NOT HAVE to be returned by controllers (& the TU81 doesn't).
 *	So tmscprsp() had to be modified to stop reporting
 *	residual count errors on reposition commands.
 *
 *   2. Fixed bug in the open routine which allowed multiple opens.
 *
 * 18-Jul-85 - afd
 *   1. Need to return status when mt status (or corresponding ioctl) is done.
 *	Save resid, flags, endcode & status in tmscprsp() routine (except on
 *	clear serious exception no-op).  Return these fields when status
 *	ioctl is done (in tmscpcommand()).  How they are returned:
 *		mt_resid = resid
 *		mt_dsreg = flags|endcode
 *		mt_erreg = status
 *
 *   2. Added latent support for enabling/disabling caching.  This is
 *	handled along with all other ioctl commands.
 *
 *   3. Need to issue a no-op on unrecognized ioctl in tmscpstart(), since
 *	we have already commited to issuing a command at that point.
 *
 *   4. In tmscprsp() routine if encode is 0200 (invalid command issued);
 *	We need to: Unlink the buffer from the I/O wait queue,
 *	and signal iodone, so the higher level command can exit!
 *	Just as if it were a valid command.
 *
 * 11-jul-85 -- jaw
 *	fix bua/bda map registers.
 *
 * 19-Jun-85 -- jaw
 *	VAX8200 name change.
 *
 * 06-Jun-85 - jaw
 *	fixes for 8200.
 *
 * 9-Apr-85 - afd
 *	Added timeout code to the probe routine, so if the controller
 *	fails to init in 10 seconds we return failed status.
 *
 * 13-Mar-85 -jaw
 *	Changes for support of the VAX8200 were merged in.
 *
 * 27-Feb-85 -tresvik
 *	Changes for support of the VAX8600 were merged in.
 *
 */
D 2
 
E 2
I 2

E 2
#include "tms.h"
D 2
#define	TMSCPDEVNUM	(15)		/* entry in bdevsw */
#if NTMSCP > 0 || defined(BINARY)
 
#include "../data/tmscp_data.c"
 
E 2
I 2
#if NTMSCP > 0

D 10
#include "../vax/pte.h"

E 10
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "file.h"
#include "map.h"
#include "vm.h"
#include "ioctl.h"
#include "syslog.h"
#include "mtio.h"
#include "cmap.h"
#include "uio.h"
I 7
#include "tty.h"
E 7

I 10
#include "../vax/pte.h"
E 10
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "ubareg.h"
#include "ubavar.h"

#define TENSEC	(1000)
#define	TMS_PRI	LOG_INFO

#define NRSPL2  3               /* log2 number of response packets */
#define NCMDL2  3               /* log2 number of command packets */
#define NRSP    (1<<NRSPL2)
#define NCMD    (1<<NCMDL2)

#include "tmscpreg.h"
#include "../vax/tmscp.h"

/* Software state per controller */

struct tmscp_softc {
	short   sc_state;       /* state of controller */
	short   sc_mapped;      /* Unibus map allocated for tmscp struct? */
	int     sc_ubainfo;     /* Unibus mapping info */
	struct	tmscp *sc_tmscp;   /* Unibus address of tmscp struct */
	int     sc_ivec;        /* interrupt vector address */
	short   sc_credits;     /* transfer credits */
	short   sc_lastcmd;     /* pointer into command ring */
	short   sc_lastrsp;     /* pointer into response ring */
I 14
	short   sc_ipl;		/* interrupt priority (Q-bus) */
E 14
} tmscp_softc[NTMSCP];

struct tmscp {
	struct tmscpca	tmscp_ca;         /* communications area */
	struct mscp	tmscp_rsp[NRSP];  /* response packets */
	struct mscp	tmscp_cmd[NCMD];  /* command packets */
} tmscp[NTMSCP];

/*
 * Per drive-unit info
 */
struct tms_info {
	daddr_t		tms_dsize;	/* Max user size from online pkt */
	unsigned	tms_type;	/* Drive type int field  */
	int		tms_resid;	/* residual from last xfer */
	u_char		tms_endcode;	/* last command endcode */
	u_char		tms_flags;	/* last command end flags */
	unsigned	tms_status;	/* Command status from last command */
	char		tms_openf;	/* lock against multiple opens */
	char		tms_lastiow;	/* last op was a write */
	char		tms_serex;	/* set when serious exception occurs */
	char		tms_clserex;	/* set when serex being cleared by no-op */
	short		tms_fmtmenu;	/* the unit's format (density) menu */
	short		tms_unitflgs;	/* unit flag parameters */
	short		tms_format;	/* the unit's current format (density) */
	struct tty	*tms_ttyp;	/* record user's tty for errors */
} tms_info[NTMS];
struct uba_ctlr *tmscpminfo[NTMSCP];
struct uba_device *tmsdinfo[NTMS];
/* 
 * ifdef other tmscp devices here if they allow more than 1 unit/controller
 */
struct uba_device *tmscpip[NTMSCP][1];
D 11
struct buf rtmsbuf[NTMS];		/* raw i/o buffer */
E 11
struct buf ctmscpbuf[NTMSCP];		/* internal cmd buffer (for ioctls) */
struct buf tmsutab[NTMS];		/* Drive queue */
struct buf tmscpwtab[NTMSCP];		/* I/O wait queue, per controller */
int    tmscpmicro[NTMSCP];		/* to store microcode level */
short  utoctlr[NTMS];			/* Slave unit to controller mapping */
					/* filled in by the slave routine */

E 2
/* Bits in minor device */
#define	TMSUNIT(dev)	(minor(dev)&03)
#define	T_NOREWIND	04
#define	T_HIDENSITY	010
D 2
 
E 2
I 2

E 2
/* Slave unit to controller mapping */
#define TMSCPCTLR(dev)	(utoctlr[TMSUNIT(dev)])
D 2
 
E 2
I 2

E 2
/*
 * Internal (ioctl) command codes (these must also be declared in the
 * tmscpioctl routine).  These correspond to ioctls in mtio.h
 */
#define TMS_WRITM	0		/* write tape mark */
#define TMS_FSF		1		/* forward space file */
#define TMS_BSF		2		/* backward space file */
#define TMS_FSR		3		/* forward space record */
#define TMS_BSR		4		/* backward space record */
#define TMS_REW		5		/* rewind tape */
#define TMS_OFFL	6		/* rewind tape & mark unit offline */
#define TMS_SENSE	7		/* noop - do a get unit status */
#define TMS_CACHE	8		/* enable cache */
#define TMS_NOCACHE	9		/* disable cache */
/* These go last: after all real mt cmds, just bump the numbers up */
#define TMS_CSE		10		/* clear serious exception */
#define TMS_LOWDENSITY	11		/* set unit to low density */
#define TMS_HIDENSITY	12		/* set unit to high density */
D 2
 
E 2
I 2

E 2
/*
 * Controller states
 */
#define S_IDLE  0               /* hasn't been initialized */
#define S_STEP1 1               /* doing step 1 init */
#define S_STEP2 2               /* doing step 2 init */
#define S_STEP3 3               /* doing step 3 init */
#define S_SCHAR 4               /* doing "set controller characteristics" */
#define S_RUN   5               /* running */
D 2
 
E 2
I 2

E 2
int     tmscperror = 0;		/* causes hex dump of packets */
int	tmscp_cp_wait = 0;	/* Something to wait on for command */
				/* packets and or credits. */
int	wakeup();
extern	int	hz;		/* Should find the right include */
D 2
 
E 2
I 2

E 2
#ifdef	DEBUG
#define printd if (tmscpdebug) printf
int tmscpdebug = 1;
#define	printd10 if(tmscpdebug >= 10) printf
#endif 
D 2
 
E 2
I 2

E 2
int     tmscpprobe(), tmscpslave(), tmscpattach(), tmscpintr();
struct  mscp *tmscpgetcp();
D 2
 
E 2
I 2

E 2
#define DRVNAME "tms"
#define CTRLNAME "tmscp"
D 2
 
E 2
I 2

E 2
u_short tmscpstd[] = { 0174500, 0 };
struct  uba_driver tmscpdriver =
{ tmscpprobe, tmscpslave, tmscpattach, 0, tmscpstd, DRVNAME, tmsdinfo, CTRLNAME
, tmscpminfo, 0};
D 2
 
E 2
I 2

E 2
#define b_qsize         b_resid         /* queue size per drive, in tmsutab */
#define b_ubinfo        b_resid         /* Unibus mapping info, per buffer */
D 2
 
 
E 2
I 2


E 2
/*************************************************************************/
D 2
 
E 2
I 2

E 2
#define DELAYTEN 1000
D 2
 
E 2
I 2

I 16
/*
 * Unfortunately qbgetpri can't be used because the TK50 doesn't flip the
 * TMSCP_STEP2 flag in the tmscpsa register until after the pending interrupt
 * has been acknowledged by the cpu. If you are at spl6(), the TMSCP_STEP2
 * flag never gets set and you return (0).
 */
E 16
E 2
tmscpprobe(reg, ctlr)
	caddr_t reg;		/* address of the IP register */
D 2
	int ctlr;		/* index of controller in the tmscp_softc array
 */
E 2
I 2
	int ctlr;		/* index of controller in the tmscp_softc array */
E 2
{
	register int br, cvec;	/* MUST be 1st (r11 & r10): IPL and intr vec */
	register struct tmscp_softc *sc = &tmscp_softc[ctlr];
				/* ptr to software controller structure */
D 2
	struct tmscpdevice *tmscpaddr; /* ptr to tmscpdevice struct (IP & SA) *
/
	struct uba_ctlr *um;	/* UNUSED ptr to uba_ctlr (controller) struct *
/
E 2
I 2
	struct tmscpdevice *tmscpaddr; /* ptr to tmscpdevice struct (IP & SA) */
D 3
	struct uba_ctlr *um;	/* UNUSED ptr to uba_ctlr (controller) struct */
E 3
E 2
D 14
	int count;		/* for probe delay time out */
E 14
I 14
D 16
	int count, s;		/* for probe delay time out */
E 16
I 16
	int count;		/* for probe delay time out */
E 16
E 14
D 2
 
E 2
I 2

E 2
#	ifdef lint
	br = 0; cvec = br; br = cvec; reg = reg;
	tmscpreset(0); tmscpintr(0);
#	endif
D 2
 
E 2
I 2

E 2
	tmscpaddr = (struct tmscpdevice *) reg;
	/* 
	 * Set host-settable interrupt vector.
D 2
	 * Assign 0 to the ip register to start the tmscp-device initialization
.
E 2
I 2
	 * Assign 0 to the ip register to start the tmscp-device initialization.
E 2
	 * The device is not really initialized at this point, this is just to
	 * find out if the device exists.
	 */
I 14
D 16
#ifdef QBA
	s = spl6();
#endif
E 16
E 14
	sc->sc_ivec = (uba_hd[numuba].uh_lastiv -= 4);
	tmscpaddr->tmscpip = 0;
D 2
 
E 2
I 2

E 2
	count=0;
	while(count < DELAYTEN)
		{	/* wait for at most 10 secs */
		if((tmscpaddr->tmscpsa & TMSCP_STEP1) != 0)
			break;
		DELAY(10000);
		count=count+1;
		}
D 14
	if (count == DELAYTEN)
E 14
I 14
D 16
	if (count == DELAYTEN) {
		splx(s);
E 16
I 16
	if (count == DELAYTEN)
E 16
E 14
		return(0);		
I 14
D 16
	}
E 16
E 14
D 2
 
	tmscpaddr->tmscpsa = TMSCP_ERR|(NCMDL2<<11)|(NRSPL2<<8)|TMSCP_IE|(sc->s
c_ivec/4);
 
E 2
I 2

	tmscpaddr->tmscpsa = TMSCP_ERR|(NCMDL2<<11)|(NRSPL2<<8)|TMSCP_IE|(sc->sc_ivec/4);

E 2
	count=0;
	while(count < DELAYTEN)
		{
D 2
		if((tmscpaddr->tmscpsa & TMSCP_STEP2) != 0)	
E 2
I 2
		if((tmscpaddr->tmscpsa & TMSCP_STEP2) != 0)
E 2
			break;
		DELAY(10000);
		count = count+1;
		}
D 14
	if (count == DELAYTEN)
E 14
I 14
D 16
	if (count == DELAYTEN) {
		splx(s);
E 16
I 16
	if (count == DELAYTEN)
E 16
E 14
		return(0);
I 14
D 16
	}
E 16
E 14
D 2
 
E 2
I 2

I 12
D 13
#ifdef VAX630
	if (cpu == VAX_630)
E 13
I 13
#ifdef QBA
D 14
	if (cpu == VAX_630 || cpu == VAX_650)
E 13
		br = 0x15;	/* screwy interrupt structure */
E 14
I 14
D 16
	sc->sc_ipl = br = qbgetpri();
E 16
I 16
	sc->sc_ipl = br = 0x15;
E 16
E 14
#endif
E 12
E 2
	return(sizeof (struct tmscpdevice));
}
D 2
 
E 2
I 2

E 2
/*
 * Try to find a slave (a drive) on the controller.
 * If the controller is not in the run state, call init to initialize it.
 */
tmscpslave (ui, reg)
	struct uba_device *ui;	/* ptr to the uba device structure */
	caddr_t reg;		/* addr of the device controller */
{
	register struct uba_ctlr *um = tmscpminfo[ui->ui_ctlr];
	register struct tmscp_softc *sc = &tmscp_softc[ui->ui_ctlr];
I 2
	register struct tms_info *tms = &tms_info[ui->ui_unit];
E 2
	struct   tmscpdevice *tmscpaddr;	/* ptr to IP & SA */
	struct   mscp *mp;
	int	 i;			/* Something to write into to start */
					/* the tmscp polling */
D 2
 
E 2
I 2

E 2
#	ifdef lint
D 3
	ui = ui; reg = reg; i = i;
E 3
I 3
	reg = reg;
E 3
#	endif
	tmscpaddr = (struct tmscpdevice *)um->um_addr;
	/* 
	 * If its not in the run state, start the initialization process
	 * (tmscpintr will complete it);  if the initialization doesn't start;
	 * then return.
	 */
	if(sc->sc_state != S_RUN)
		{
#		ifdef DEBUG
		printd("tmscpslave: ctlr not running: calling init \n");
#		endif	
		if(!tmscpinit(ui->ui_ctlr))
	    		return(0);
		}
	/*
	 * Wait for the controller to come into the run state or go idle.
	 * If it goes idle return.
	 */
#	ifdef DEBUG
	i=1;
#	endif	
	while(sc->sc_state != S_RUN && sc->sc_state != S_IDLE)
#		ifdef DEBUG
		if (tmscpaddr->tmscpsa & TMSCP_ERR && i)
	    		{
D 2
	    		printd("tmscp-device: fatal error (%o)\n", tmscpaddr->t
mscpsa&0xffff);
E 2
I 2
	    		printd("tmscp-device: fatal error (%o)\n", tmscpaddr->tmscpsa&0xffff);
E 2
	    		i=0;
	   		 }
#		endif	
		;	/* wait */
	if(sc->sc_state == S_IDLE)
		{	/* The tmscp device failed to initialize */
		printf("tmscp controller failed to init\n");
		return(0);
		}
	/* The controller is up so see if the drive is there */
	if(0 == (mp = tmscpgetcp(um)))
		{
		printf("tmscp can't get command packet\n");
		return(0);
		}
	/* Need to determine the drive type for generic driver */
D 2
	mp->mscp_opcode = M_OP_GTUNT;	/* This should give us the device type 
*/
E 2
I 2
	mp->mscp_opcode = M_OP_GTUNT;	/* This should give us the device type */
E 2
	mp->mscp_unit = ui->ui_slave;
	mp->mscp_cmdref = (long) ui->ui_slave;
D 2
	tms_info[ui->ui_unit].tms_status = 0;	/* set to zero */
E 2
I 2
	tms->tms_status = 0;	/* set to zero */
E 2
	tmscpip[ui->ui_ctlr][ui->ui_slave] = ui;
D 2
	*((long *) mp->mscp_dscptr ) |= TMSCP_OWN | TMSCP_INT;/* maybe we shoul
d poll*/
E 2
I 2
	*((long *) mp->mscp_dscptr ) |= TMSCP_OWN | TMSCP_INT;/* maybe we should poll*/
E 2
	i = tmscpaddr->tmscpip;
I 3
#ifdef lint
	i = i;
#endif
E 3
D 2
	while(!tms_info[ui->ui_unit].tms_status)
E 2
I 2
	while(!tms->tms_status)
E 2
		;				/* Wait for some status */
#	ifdef DEBUG
D 2
	printd("tmscpslave: status = %o\n",tms_info[ui->ui_unit].tms_status & M
_ST_MASK);
#	endif	
E 2
I 2
	printd("tmscpslave: status = %o\n",tms->tms_status & M_ST_MASK);
#	endif
E 2
	tmscpip[ui->ui_ctlr][ui->ui_slave] = 0;
D 2
	if(!tms_info[ui->ui_unit].tms_type)	/* packet from a GTUNT */
E 2
I 2
	if(!tms->tms_type)			/* packet from a GTUNT */
E 2
		return(0);			/* Failed No such drive */
	else
		return(1);			/* Got it and it is there */
}
D 2
 
 
E 2
I 2


E 2
/* 
 * Set ui flags to zero to show device is not online & set tmscpip.
 * Unit to Controller mapping is set up here.
 * Open routine will issue the online command, later.
 */
tmscpattach (ui)
	register struct uba_device *ui;		/* ptr to unibus dev struct */
{
D 2
	register struct uba_ctlr *um = ui->ui_mi; /* ptr to controller struct *
/
	struct tmscpdevice *tmscpaddr = (struct tmscpdevice *) um->um_addr; /* 
IP & SA */
E 2
I 2
D 4
	register struct uba_ctlr *um = ui->ui_mi; /* ptr to controller struct */
E 4
D 3
	struct tmscpdevice *tmscpaddr = (struct tmscpdevice *) um->um_addr; /* IP & SA */
E 2
	struct mscp *mp;
	int i;		/* Assign to here to start the tmscp-dev polling */
E 3
D 2
 
E 2
I 2

E 2
D 3
#	ifdef lint
	i = i;
#	endif lint
E 3
	ui->ui_flags = 0;
	tmscpip[ui->ui_ctlr][ui->ui_slave] = ui;
#	ifdef DEBUG
	/* 
	 * Check to see if the drive is available.
	 * If not then just print debug.
	 */
	if(tms_info[ui->ui_unit].tms_status != M_ST_AVLBL)
		printd("tmscpattach: unavailable \n");
#	endif	
	utoctlr[ui->ui_unit] = ui->ui_ctlr;
}
D 2
 
 
E 2
I 2


E 2
/*
 * TMSCP interrupt routine.
 */
tmscpintr (d)
	int d;		/* index to the controller */
{
	register struct uba_ctlr *um = tmscpminfo[d];
D 2
	register struct tmscpdevice *tmscpaddr = (struct tmscpdevice *)um->um_a
ddr;
E 2
I 2
	register struct tmscpdevice *tmscpaddr = (struct tmscpdevice *)um->um_addr;
E 2
	struct buf *bp;
	register int i;
	register struct tmscp_softc *sc = &tmscp_softc[d];
	register struct tmscp *tm = &tmscp[d];
	struct tmscp *ttm;
	struct mscp *mp;
D 2
 
E 2
I 2

E 2
#	ifdef DEBUG
D 2
	printd10("tmscpintr: state %d, tmscpsa %o\n", sc->sc_state, tmscpaddr->
tmscpsa);
E 2
I 2
	printd10("tmscpintr: state %d, tmscpsa %o\n", sc->sc_state, tmscpaddr->tmscpsa);
E 2
#	endif	
D 2
 
E 2
I 2

I 14
#ifdef QBA
	splx(sc->sc_ipl);
#endif
E 14
E 2
	/*
	 * How the interrupt is handled depends on the state of the controller.
	 */
	switch (sc->sc_state) {
D 2
 
E 2
I 2

E 2
	case S_IDLE:
		printf("tmscp%d: random interrupt ignored\n", d);
		return;
D 2
 
E 2
I 2

E 2
	/* Controller was in step 1 last, see if its gone to step 2 */
	case S_STEP1:
#		define STEP1MASK 0174377
#		define STEP1GOOD (TMSCP_STEP2|TMSCP_IE|(NCMDL2<<3)|NRSPL2)
		for (i = 0; i < 150; i++)
			{
			if ((tmscpaddr->tmscpsa&STEP1MASK) != STEP1GOOD)
				{ /* still in step 1 (wait 1/100 sec) */
				DELAY(10000);
#				ifdef DEBUG
				printd("still in step 1, delaying\n");
#				endif DEBUG
				}
			else
				break;
			}
		if (i > 149)
			{
			sc->sc_state = S_IDLE;
D 2
			printf("failed to initialize, in step1: sa 0x%x", tmscp
addr->tmscpsa);
E 2
I 2
			printf("failed to initialize, in step1: sa 0x%x", tmscpaddr->tmscpsa);
E 2
			wakeup((caddr_t)um);
			return;
			}
		tmscpaddr->tmscpsa = ((int)&sc->sc_tmscp->tmscp_ca.ca_ringbase)
			| ((cpu == VAX_780 || cpu == VAX_8600) ? TMSCP_PI : 0);
		sc->sc_state = S_STEP2;
		return;
D 2
 
E 2
I 2

E 2
	/* Controller was in step 2 last, see if its gone to step 3 */
	case S_STEP2:
#		define STEP2MASK 0174377
#		define STEP2GOOD (TMSCP_STEP3|TMSCP_IE|(sc->sc_ivec/4))
		for (i = 0; i < 150; i++)
			{
			if ((tmscpaddr->tmscpsa&STEP2MASK) != STEP2GOOD)
				{ /* still in step 2 (wait 1/100 sec) */
				DELAY(10000);
#				ifdef DEBUG
				printd("still in step 2, delaying\n");
#				endif DEBUG
				}
			else
				break;
			}
		if (i > 149)
			{
			sc->sc_state = S_IDLE;
D 2
			printf("failed to initialize, in step2: sa 0x%x", tmscp
addr->tmscpsa);
E 2
I 2
			printf("failed to initialize, in step2: sa 0x%x", tmscpaddr->tmscpsa);
E 2
			wakeup((caddr_t)um);
			return;
			}
D 2
		tmscpaddr->tmscpsa = ((int)&sc->sc_tmscp->tmscp_ca.ca_ringbase)
>>16;
E 2
I 2
		tmscpaddr->tmscpsa = ((int)&sc->sc_tmscp->tmscp_ca.ca_ringbase)>>16;
E 2
		sc->sc_state = S_STEP3;
		return;
D 2
 
E 2
I 2

E 2
	/* Controller was in step 3 last, see if its gone to step 4 */
	case S_STEP3:
#		define STEP3MASK 0174000
#		define STEP3GOOD TMSCP_STEP4
		for (i = 0; i < 150; i++)
			{
			if ((tmscpaddr->tmscpsa&STEP3MASK) != STEP3GOOD)
				{ /* still in step 3 (wait 1/100 sec) */
				DELAY(10000);
#				ifdef DEBUG
				printd("still in step 3, delaying\n");
#				endif DEBUG
				}
			else
				break;
			}
		if (i > 149)
			{
			sc->sc_state = S_IDLE;
D 2
			printf("failed to initialize, in step3: sa 0x%x", tmscp
addr->tmscpsa);
E 2
I 2
			printf("failed to initialize, in step3: sa 0x%x", tmscpaddr->tmscpsa);
E 2
			wakeup((caddr_t)um);
			return;
			}
		/*
		 * Get microcode version and model number of controller;
		 * Signal initialization complete (_GO) (to the controller);
		 *    ask for Last Fail response if tmscperror is set;
		 * Set state to "set controller characteristics".
		 */
		tmscpmicro[d] = tmscpaddr->tmscpsa;
		tmscpaddr->tmscpsa = TMSCP_GO | (tmscperror? TMSCP_LF : 0);
		sc->sc_state = S_SCHAR;
#		ifdef DEBUG
		printd("tmscpintr: completed state %d \n", sc->sc_state);
		printd("tmscp%d Version %d model %d\n",d,tmscpmicro[d]&0xF,
			(tmscpmicro[d]>>4) & 0xF);
#		endif
D 2
 
E 2
I 2

E 2
	    /*
	     * Initialize the data structures (response and command queues).
	     */
	    ttm = sc->sc_tmscp;
	    for (i = 0; i < NRSP; i++)
		    {
		    tm->tmscp_ca.ca_rspdsc[i] = TMSCP_OWN | TMSCP_INT | 
D 2
					   (long)&ttm->tmscp_rsp[i].mscp_cmdref
;
E 2
I 2
			   (long)&ttm->tmscp_rsp[i].mscp_cmdref;
E 2
		    tm->tmscp_rsp[i].mscp_dscptr = &tm->tmscp_ca.ca_rspdsc[i];
		    tm->tmscp_rsp[i].mscp_header.tmscp_msglen = mscp_msglen;
		    }
	    for (i = 0; i < NCMD; i++)
		    {
		    tm->tmscp_ca.ca_cmddsc[i] = TMSCP_INT | 
					(long)&ttm->tmscp_cmd[i].mscp_cmdref;
		    tm->tmscp_cmd[i].mscp_dscptr = &tm->tmscp_ca.ca_cmddsc[i];
		    tm->tmscp_cmd[i].mscp_header.tmscp_msglen = mscp_msglen;
		    tm->tmscp_cmd[i].mscp_header.tmscp_vcid = 1;
		    }
	    bp = &tmscpwtab[d];
	    bp->av_forw = bp->av_back = bp;
	    sc->sc_lastcmd = 1;
	    sc->sc_lastrsp = 0;
	    mp = &tmscp[um->um_ctlr].tmscp_cmd[0];
	    mp->mscp_unit = mp->mscp_modifier = 0;
	    mp->mscp_flags = 0;
	    mp->mscp_version = 0;
	    mp->mscp_cntflgs = M_CF_ATTN|M_CF_MISC|M_CF_THIS;
	    /*
	     * A host time out value of 0 means that the controller will not
	     * time out.  This is ok for the TK50.
	     */
	    mp->mscp_hsttmo = 0;
	    mp->mscp_time.val[0] = 0;
	    mp->mscp_time.val[1] = 0;
	    mp->mscp_cntdep = 0;
	    mp->mscp_opcode = M_OP_STCON;
	    *((long *)mp->mscp_dscptr) |= TMSCP_OWN|TMSCP_INT;
	    i = tmscpaddr->tmscpip;      /* initiate polling */
	    return;
D 2
 
E 2
I 2

E 2
	case S_SCHAR:
	case S_RUN:
		break;
D 2
 
E 2
I 2

E 2
	default:
D 2
	    printf("tmscp%d: interrupt in unknown state %d ignored\n",d,sc->sc_
state);
E 2
I 2
	    printf("tmscp%d: interrupt in unknown state %d ignored\n",d,sc->sc_state);
E 2
	    return;
	}	/* end switch */
D 2
 
E 2
I 2

E 2
	/*
	 * The controller state is S_SCHAR or S_RUN
	 */
D 2
 
E 2
I 2

E 2
	/*
	 * If the error bit is set in the SA register then print an error
	 * message and reinitialize the controller.
	 */
	if (tmscpaddr->tmscpsa&TMSCP_ERR)
		{
D 2
		printf("tmscp%d: fatal error (%o)\n", d, tmscpaddr->tmscpsa&0xf
fff);
E 2
I 2
		printf("tmscp%d: fatal error (%o)\n", d, tmscpaddr->tmscpsa&0xffff);
E 2
		tmscpaddr->tmscpip = 0;
		wakeup((caddr_t)um);
		}
	/*
	 * Check for a buffer purge request. (Won't happen w/ TK50 on Q22 bus)
	 */
	if (tm->tmscp_ca.ca_bdp)
		{
D 5
		/*
		 * THIS IS A KLUDGE.
		 * Maybe we should change the entire
		 * UBA interface structure.
		 */
		int s = spl6();
		i = um->um_ubinfo;
#		ifdef DEBUG
		printd("tmscp: purge bdp %d\n", tm->tmscp_ca.ca_bdp);
#		endif		
		um->um_ubinfo = tm->tmscp_ca.ca_bdp<<28;
		ubapurge(um);
		um->um_ubinfo = i;
		(void) splx(s);
E 5
I 5
		UBAPURGE(um->um_hd->uh_uba, tm->tmscp_ca.ca_bdp);
E 5
		tm->tmscp_ca.ca_bdp = 0;
		tmscpaddr->tmscpsa = 0;      /* signal purge complete */
		}
D 2
 
E 2
I 2

E 2
	/*
	 * Check for response ring transition.
	 */
	if (tm->tmscp_ca.ca_rspint)
		{
		tm->tmscp_ca.ca_rspint = 0;
		for (i = sc->sc_lastrsp;; i++)
			{
			i %= NRSP;
			if (tm->tmscp_ca.ca_rspdsc[i]&TMSCP_OWN)
			    break;
			tmscprsp(um, tm, sc, i);
			tm->tmscp_ca.ca_rspdsc[i] |= TMSCP_OWN;
			}
		sc->sc_lastrsp = i;
		}
D 2
 
E 2
I 2

E 2
	/*
	 * Check for command ring transition.
	 */
	if (tm->tmscp_ca.ca_cmdint)
		{
#		ifdef DEBUG
		printd("tmscpintr: command ring transition\n");
#		endif		
		tm->tmscp_ca.ca_cmdint = 0;
		}
    	if(tmscp_cp_wait)
D 5
		wakeup(&tmscp_cp_wait);
E 5
I 5
		wakeup((caddr_t)&tmscp_cp_wait);
E 5
    	(void) tmscpstart(um);
}
D 2
 
 
E 2
I 2


E 2
/*
 * Open a tmscp device and set the unit online.  If the controller is not 
 * in the run state, call init to initialize the tmscp controller first.
 */
D 2
 
E 2
I 2

I 3
/* ARGSUSED */
E 3
E 2
tmscpopen(dev, flag)
	dev_t dev;
	int flag;
{
	register int unit;
	register struct uba_device *ui;
	register struct tmscp_softc *sc;
I 2
	register struct tms_info *tms;
E 2
	register struct mscp *mp;
	register struct uba_ctlr *um;
	struct tmscpdevice *tmscpaddr;
	int s,i;
D 6
	extern quota;
E 6
	
D 3
#	ifdef lint
	flag = flag; i = i;
#	endif
E 3
	unit = TMSUNIT(dev);
#	ifdef DEBUG
	printd("tmscpopen unit %d\n",unit);
	if(tmscpdebug)DELAY(10000);
#	endif
D 2
	if (unit >= nNTMS || (ui = tmsdinfo[unit]) == 0 || ui->ui_alive == 0
		|| tms_info[ui->ui_unit].tms_openf)
E 2
I 2
	if (unit >= NTMS || (ui = tmsdinfo[unit]) == 0 || ui->ui_alive == 0)
E 2
		return (ENXIO);
I 2
	tms = &tms_info[ui->ui_unit];
	if (tms->tms_openf)
		return (EBUSY);
E 2
	sc = &tmscp_softc[ui->ui_ctlr];
I 2
	tms->tms_openf = 1;
	tms->tms_ttyp = u.u_ttyp;
E 2
	s = spl5();
	if (sc->sc_state != S_RUN)
		{
		if (sc->sc_state == S_IDLE)
			if(!tmscpinit(ui->ui_ctlr))
				{
				printf("tmscp controller failed to init\n");
				(void) splx(s);
I 10
				tms->tms_openf = 0;
E 10
				return(ENXIO);
				}
		/* 
		 * Wait for initialization to complete
		 */
		timeout(wakeup,(caddr_t)ui->ui_mi,11*hz);	/* to be sure*/
		sleep((caddr_t)ui->ui_mi, 0);
		if (sc->sc_state != S_RUN)
			{
			(void) splx(s);
I 2
			tms->tms_openf = 0;
E 2
			return (EIO);
			}
		}
	/*
	 * Check to see if the device is really there.
	 * this code was taken from Fred Canters 11 driver
	 */
	um = ui->ui_mi;
	tmscpaddr = (struct tmscpdevice *) um->um_addr;
	(void) splx(s);
	if(ui->ui_flags == 0)
		{
		s = spl5();
		while(0 ==(mp = tmscpgetcp(um)))
			{
			tmscp_cp_wait++;
D 5
			sleep(&tmscp_cp_wait,PSWP+1);
E 5
I 5
			sleep((caddr_t)&tmscp_cp_wait,PSWP+1);
E 5
			tmscp_cp_wait--;
			}
		(void) splx(s);
		mp->mscp_opcode = M_OP_ONLIN;
		mp->mscp_unit = ui->ui_slave;
D 2
		mp->mscp_cmdref = (long) & tms_info[ui->ui_unit].tms_type;
E 2
I 2
		mp->mscp_cmdref = (long) & tms->tms_type;
E 2
					    /* need to sleep on something */
#		ifdef DEBUG
		printd("tmscpopen: bring unit %d online\n",ui->ui_unit);
#		endif	
		*((long *) mp->mscp_dscptr ) |= TMSCP_OWN | TMSCP_INT;
		i = tmscpaddr->tmscpip;
I 3
#ifdef lint
		i = i;
#endif
E 3
		/* 
		 * To make sure we wake up, timeout in 240 seconds.
		 * Wakeup in tmscprsp routine.
		 * 240 seconds (4 minutes) is necessary since a rewind
		 * can take a few minutes.
		 */
		timeout(wakeup,(caddr_t) mp->mscp_cmdref,240 * hz);
		sleep((caddr_t) mp->mscp_cmdref,PSWP+1);
		}
D 2
	if(ui->ui_flags == 0)
E 2
I 2
	if(ui->ui_flags == 0) {
		tms->tms_openf = 0;
E 2
		return(ENXIO);  /* Didn't go online */
D 2
	tms_info[ui->ui_unit].tms_openf = 1;
	tms_info[ui->ui_unit].tms_lastiow = 0;
E 2
I 2
	}
	tms->tms_lastiow = 0;
E 2
	/*
	 * If the high density device is not specified, set unit to low
	 * density.  This is done as an "internal" ioctl command so
	 * that the command setup and response handling
	 * is done thru "regular" command routines.
	 */
	if ((minor(dev) & T_HIDENSITY) == 0)
		tmscpcommand(dev, TMS_LOWDENSITY, 1);
	else
		tmscpcommand(dev, TMS_HIDENSITY, 1);
	return (0);
}
D 2
 
 
E 2
I 2


E 2
/*
 * Close tape device.
 *
 * If tape was open for writing or last operation was
 * a write, then write two EOF's and backspace over the last one.
 * Unless this is a non-rewinding special file, rewind the tape.
 *
 * NOTE:
 *	We want to be sure that any serious exception is cleared on the
 *	close. A Clear Serious Exception (CSE) modifier is always done on
 *	the rewind command.  For the non-rewind case we check to see if the
 *	"serex" field is set in the softc struct; if it is then issue a noop
 *	command with the CSE modifier.
 * Make the tape available to others, by clearing openf flag.
 */
tmscpclose(dev, flag)
	register dev_t dev;
	register flag;
{
D 3
	register struct tmscp_softc *sc = &tmscp_softc[TMSCPCTLR(dev)];
E 3
I 2
	register struct tms_info *tms;
E 2
	register struct uba_device *ui;
D 2
 
E 2
I 2

E 2
	ui = tmsdinfo[TMSUNIT(dev)];
#	ifdef DEBUG
	printd("tmscpclose: ctlr =  %d\n",TMSCPCTLR(dev));
	printd("tmscpclose: unit = %d\n",TMSUNIT(dev));
	if(tmscpdebug)DELAY(10000);
#	endif
D 2
	if (flag == FWRITE || (flag&FWRITE) && tms_info[ui->ui_unit].tms_lastio
w)
E 2
I 2
	tms = &tms_info[ui->ui_unit];
	if (flag == FWRITE || (flag&FWRITE) && tms->tms_lastiow)
E 2
		{
		/*	   device, command, count */
		tmscpcommand (dev, TMS_WRITM, 1);
		tmscpcommand (dev, TMS_WRITM, 1);
		tmscpcommand (dev, TMS_BSR, 1);
		}
	if ((minor(dev)&T_NOREWIND) == 0)
		/*
		 * Don't hang waiting for rewind complete.
		 */
		tmscpcommand(dev, TMS_REW, 0);
	else
D 2
		if (tms_info[ui->ui_unit].tms_serex)
E 2
I 2
		if (tms->tms_serex)
E 2
			{
#			ifdef DEBUG
			printd("tmscpclose: clearing serex\n");
			if(tmscpdebug)DELAY(10000);
#			endif
			tmscpcommand(dev, TMS_CSE, 1);
			}
D 2
	tms_info[ui->ui_unit].tms_openf = 0;
E 2
I 2
	tms->tms_openf = 0;
E 2
}
D 2
 
 
E 2
I 2


E 2
/*
 * Execute a command on the tape drive a specified number of times.
 * This routine sets up a buffer and calls the strategy routine which
 * links the buffer onto the drive's buffer queue.
 * The start routine will take care of creating a tmscp command packet
 * with the command.  The start routine is called by the strategy or the
 * interrupt routine.
 */
D 2
 
E 2
I 2

E 2
tmscpcommand (dev, com, count)
	register dev_t dev;
	int com, count;
{
	register struct uba_device *ui;
	register struct buf *bp;
	register int s;
	int unit = TMSUNIT(dev);
D 2
 
	if (unit >= nNTMS)
E 2
I 2

D 3
	if (unit >= NTMS)
E 2
		return (ENXIO);
E 3
	ui = tmsdinfo[unit];
	bp = &ctmscpbuf[ui->ui_ctlr];
D 2
 
E 2
I 2

E 2
	s = spl5();
	while (bp->b_flags&B_BUSY)
		{
		/*
		 * This special check is because B_BUSY never
		 * gets cleared in the non-waiting rewind case.
		 */
		if (bp->b_bcount == 0 && (bp->b_flags&B_DONE))
			break;
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
		}
	bp->b_flags = B_BUSY|B_READ;
	splx(s);
	/*
	 * Load the buffer.  The b_count field gets used to hold the command
	 * count.  the b_resid field gets used to hold the command mneumonic.
	 * These 2 fields are "known" to be "safe" to use for this purpose.
	 * (Most other drivers also use these fields in this way.)
	 */
	bp->b_dev = dev;
	bp->b_bcount = count;
	bp->b_resid = com;
	bp->b_blkno = 0;
	tmscpstrategy(bp);
	/*
	 * In case of rewind from close, don't wait.
	 * This is the only case where count can be 0.
	 */
	if (count == 0)
		return;
	iowait(bp);
	if (bp->b_flags&B_WANTED)
		wakeup((caddr_t)bp);
	bp->b_flags &= B_ERROR;
}
D 2
 
E 2
I 2

E 2
/*
 * Find an unused command packet
 */
struct mscp *
tmscpgetcp(um)
	struct uba_ctlr *um;
{
	register struct mscp *mp;
	register struct tmscpca *cp;
	register struct tmscp_softc *sc;
	register int i;
	int	s;
D 2
 
E 2
I 2

E 2
	s = spl5();
	cp = &tmscp[um->um_ctlr].tmscp_ca;
	sc = &tmscp_softc[um->um_ctlr];
	/*
	 * If no credits, can't issue any commands
	 * until some outstanding commands complete.
	 */
	i = sc->sc_lastcmd;
#  	ifdef DEBUG
	printd10("tmscpgetcp: %d credits remain\n", sc->sc_credits);
#	endif
	if(((cp->ca_cmddsc[i]&(TMSCP_OWN|TMSCP_INT))==TMSCP_INT) &&
	  (sc->sc_credits >= 2))
		{
		sc->sc_credits--;       /* This commits to issuing a command */
		cp->ca_cmddsc[i] &= ~TMSCP_INT;
		mp = &tmscp[um->um_ctlr].tmscp_cmd[i];
		mp->mscp_unit = mp->mscp_modifier = 0;
		mp->mscp_opcode = mp->mscp_flags = 0;
		mp->mscp_bytecnt = mp->mscp_buffer = 0;
		sc->sc_lastcmd = (i + 1) % NCMD;
		(void) splx(s);
		return(mp);
		}
	(void) splx(s);
	return(NULL);
}
D 2
 
 
E 2
I 2


E 2
/*
 * Initialize a TMSCP device.  Set up UBA mapping registers,
 * initialize data structures, and start hardware
 * initialization sequence.
 */
tmscpinit (d)
	int d;			/* index to the controller */
{
	register struct tmscp_softc *sc;
D 2
	register struct tmscp *t;  /* communications area; cmd & resp packets *
/
E 2
I 2
	register struct tmscp *t;  /* communications area; cmd & resp packets */
E 2
	struct tmscpdevice *tmscpaddr;
	struct uba_ctlr *um;
D 2
 
E 2
I 2

E 2
	sc = &tmscp_softc[d];
	um = tmscpminfo[d];
	um->um_tab.b_active++;
	t = &tmscp[d];
	tmscpaddr = (struct tmscpdevice *)um->um_addr;
	if (sc->sc_mapped == 0)
		{
		/*
		 * Map the communications area and command
		 * and response packets into Unibus address
		 * space.
		 */
D 2
		sc->sc_ubainfo = uballoc(um->um_ubanum, (caddr_t)t, sizeof (str
uct tmscp), 0);
E 2
I 2
		sc->sc_ubainfo = uballoc(um->um_ubanum, (caddr_t)t, sizeof (struct tmscp), 0);
E 2
D 14
#		ifdef MVAX
		if (cpu == MVAX_I)
D 2
			sc->sc_tmscp = (struct tmscp *)(sc->sc_ubainfo & 0x3fff
ff);
E 2
I 2
			sc->sc_tmscp = (struct tmscp *)(sc->sc_ubainfo & 0x3fffff);
E 2
		else
#		endif MVAX
D 2
			sc->sc_tmscp = (struct tmscp *)(sc->sc_ubainfo & 0x3fff
f);
E 2
I 2
			sc->sc_tmscp = (struct tmscp *)(sc->sc_ubainfo & 0x3ffff);
E 14
I 14
		sc->sc_tmscp = (struct tmscp *)(UBAI_ADDR(sc->sc_ubainfo));
E 14
E 2
		sc->sc_mapped = 1;
		}
D 2
 
E 2
I 2

E 2
	/*
	 * Start the hardware initialization sequence.
	 */
	tmscpaddr->tmscpip = 0;              /* start initialization */
D 2
 
E 2
I 2

E 2
	while((tmscpaddr->tmscpsa & TMSCP_STEP1) == 0)
		{
#		ifdef DEBUG
		printd("tmscpinit: tmscpsa = 0%o\n",tmscpaddr->tmscpsa);
		DELAY(100000);
#		endif
		if(tmscpaddr->tmscpsa & TMSCP_ERR)
			return(0);	/* CHECK */
		}
D 2
	tmscpaddr->tmscpsa=TMSCP_ERR|(NCMDL2<<11)|(NRSPL2<<8)|TMSCP_IE|(sc->sc_
ivec/4);
E 2
I 2
	tmscpaddr->tmscpsa=TMSCP_ERR|(NCMDL2<<11)|(NRSPL2<<8)|TMSCP_IE|(sc->sc_ivec/4);
E 2
	/*
	 * Initialization continues in the interrupt routine.
	 */
	sc->sc_state = S_STEP1;
	sc->sc_credits = 0;
	return(1);
}
D 2
 
 
E 2
I 2


E 2
/*
 * Start I/O operation
 * This code is convoluted.  The majority of it was copied from the uda driver.
 */
D 2
 
E 2
I 2

E 2
tmscpstart(um)
	register struct uba_ctlr *um;
{
	register struct buf *bp, *dp;
	register struct mscp *mp;
	register struct tmscp_softc *sc;
I 2
	register struct tms_info *tms;
E 2
	register struct uba_device *ui;
	struct   tmscpdevice *tmscpaddr;
	struct   tmscp *tm = &tmscp[um->um_ctlr];
	int i,tempi;
	char ioctl;		/* flag: set true if its an IOCTL command */
D 2
 
E 2
I 2

E 2
	sc = &tmscp_softc[um->um_ctlr];
	
    for(;;)
	{
	if ((dp = um->um_tab.b_actf) == NULL)
		{
		/*
		 * Release unneeded UBA resources and return
		 * (drive was inactive)
		 */
		um->um_tab.b_active = 0;
		break;
		}
	if ((bp = dp->b_actf) == NULL)
		{
		/*
		 * No more requests for this drive, remove
		 * from controller queue and look at next drive.
		 * We know we're at the head of the controller queue.
		 */
		dp->b_active = 0;
		um->um_tab.b_actf = dp->b_forw;
		continue;		/* Need to check for loop */
		}
	um->um_tab.b_active++;
	tmscpaddr = (struct tmscpdevice *)um->um_addr;
I 2
	ui = tmsdinfo[(TMSUNIT(bp->b_dev))];
	tms = &tms_info[ui->ui_unit];
E 2
	if ((tmscpaddr->tmscpsa&TMSCP_ERR) || sc->sc_state != S_RUN)
		{
D 2
		harderr(bp, "tms");
		mprintf("tmscp%d: sa 0%o, state %d\n",um->um_ctlr,
E 2
I 2
		tprintf(tms->tms_ttyp,
		    "tms%d: hard error bn%d\n",
		    minor(bp->b_dev)&03, bp->b_blkno);
		log(TMS_PRI, "tmscp%d: sa 0%o, state %d\n",um->um_ctlr,
E 2
				tmscpaddr->tmscpsa&0xffff, sc->sc_state);
D 5
		tmscpinit(um->um_ctlr);
E 5
I 5
		(void)tmscpinit(um->um_ctlr);
E 5
		/* SHOULD REQUEUE OUTSTANDING REQUESTS, LIKE TMSCPRESET */
		break;
		}
D 2
	ui = tmsdinfo[(TMSUNIT(bp->b_dev))];
E 2
	/*
	 * Default is that last command was NOT a write command;
	 * if a write command is done it will be detected in tmscprsp.
	 */
D 2
	tms_info[ui->ui_unit].tms_lastiow = 0;
E 2
I 2
	tms->tms_lastiow = 0;
E 2
	if (ui->ui_flags == 0)
		{        /* not online */
		if ((mp = tmscpgetcp(um)) == NULL)
			break;
		mp->mscp_opcode = M_OP_ONLIN;
		mp->mscp_unit = ui->ui_slave;
		dp->b_active = 2;
		um->um_tab.b_actf = dp->b_forw; /* remove from controller q */
		*((long *)mp->mscp_dscptr) |= TMSCP_OWN|TMSCP_INT;
		if (tmscpaddr->tmscpsa&TMSCP_ERR)
			printf("tmscp%d fatal error (0%o)\n",um->um_ctlr,
					tmscpaddr->tmscpsa&0xffff);
		i = tmscpaddr->tmscpip;
		continue;
		}
	switch (cpu) {
D 2
 
E 2
I 2

E 2
	case VAX_8600:
	case VAX_780:
		i = UBA_NEEDBDP|UBA_CANTWAIT;
		break;
D 2
	case VAX_8200:
E 2
	case VAX_750:
		i = um->um_ubinfo|UBA_HAVEBDP|UBA_CANTWAIT;
		break;
	case VAX_730:
I 15
	case VAX_630:
E 15
		i = UBA_CANTWAIT;
		break;
D 2
	case MVAX_I:
	case MVAX_II:
		i = UBA_CANTWAIT|UBA_MAPANYWAY;
		break;
E 2
	}   /* end switch (cpu) */
	/*
D 2
	 * If command is an ioctl command then set the ioctl flag for later use
.
E 2
I 2
	 * If command is an ioctl command then set the ioctl flag for later use.
E 2
	 * If not (i.e. it is a read or write) then attempt
	 * to set up a buffer pointer.
	 */
	ioctl = 0;
	if (bp == &ctmscpbuf[um->um_ctlr])
		ioctl = 1;
	else
		if ((i = ubasetup(um->um_ubanum, bp, i)) == 0)
			{
			if(dp->b_qsize != 0)
				break; /* When a command completes and */
D 2
				     /* frees a bdp tmscpstart will be called *
/
E 2
I 2
				     /* frees a bdp tmscpstart will be called */
E 2
			if ((mp = tmscpgetcp(um)) == NULL)
				break;
#			ifdef DEBUG
D 2
			printd("tmscpstart: GTUNT %d ubasetup = %d\n",ui->ui_un
it, i);
E 2
I 2
			printd("tmscpstart: GTUNT %d ubasetup = %d\n",ui->ui_unit, i);
E 2
			if(tmscpdebug)DELAY(10000);
#			endif
			mp->mscp_opcode = M_OP_GTUNT;
			mp->mscp_unit = ui->ui_slave;
			*((long *)mp->mscp_dscptr) |= TMSCP_OWN|TMSCP_INT;
			if (tmscpaddr->tmscpsa&TMSCP_ERR)
D 2
				printf("tmscp%d: fatal error (0%o)\n",um->um_ct
lr,
E 2
I 2
				printf("tmscp%d: fatal error (0%o)\n",um->um_ctlr,
E 2
					    tmscpaddr->tmscpsa&0xffff);
			i = tmscpaddr->tmscpip;	/* initiate polling */
			break;
			}
D 2
#	if defined(VAX750) || defined(VAX8200)
	if ((cpu == VAX_750) || (cpu == VAX_8200))
E 2
I 2
#	if defined(VAX750)
	if (cpu == VAX_750)
E 2
		tempi = i & 0xfffffff;			/* mask off bdp */
	else
#	endif
		tempi = i;
	if ((mp = tmscpgetcp(um)) == NULL)
		{
		if (!ioctl)		/* only need to release if NOT ioctl */
			ubarelse(um->um_ubanum,&tempi);
		break;
		}
	mp->mscp_cmdref = (long)bp;		/* pointer to get back */
	mp->mscp_unit = ui->ui_slave;
	/*
	 * If its an ioctl-type command then set up the appropriate
	 * tmscp command;  by doing a switch on the "b_resid" field where
	 * the command mneumonic is stored.
	 */
	if (ioctl)
		{
#		ifdef DEBUG
		printd("tmscpstart: doing ioctl cmd %d\n", bp->b_resid);
#		endif
		/*
		 * The reccnt and tmkcnt fields are set to zero by the getcp
		 * routine (as bytecnt and buffer fields).  Thus reccnt and
		 * tmkcnt are only modified here if they need to be set to
		 * a non-zero value.
		 */
D 3
		switch (bp->b_resid) {
E 3
I 3
		switch ((int)bp->b_resid) {
E 3
D 2
 
E 2
I 2

E 2
		case TMS_WRITM:
			mp->mscp_opcode = M_OP_WRITM;
			break;
		case TMS_FSF:
			mp->mscp_opcode = M_OP_REPOS;
			mp->mscp_tmkcnt = bp->b_bcount;
			break;
		case TMS_BSF:
			mp->mscp_opcode = M_OP_REPOS;
			mp->mscp_modifier = M_MD_REVRS;
			mp->mscp_tmkcnt = bp->b_bcount;
			break;
		case TMS_FSR:
			mp->mscp_opcode = M_OP_REPOS;
			mp->mscp_modifier = M_MD_OBJCT;
			mp->mscp_reccnt = bp->b_bcount;
			break;
		case TMS_BSR:
			mp->mscp_opcode = M_OP_REPOS;
			mp->mscp_modifier = M_MD_REVRS | M_MD_OBJCT;
			mp->mscp_reccnt = bp->b_bcount;
			break;
		/*
		 * Clear serious exception is done for Rewind & Available cmds
		 */
		case TMS_REW:
			mp->mscp_opcode = M_OP_REPOS;
			mp->mscp_modifier = M_MD_REWND | M_MD_CLSEX;
			if (bp->b_bcount == 0)
				mp->mscp_modifier |= M_MD_IMMED;
D 2
			tms_info[ui->ui_unit].tms_serex = 0;
E 2
I 2
			tms->tms_serex = 0;
E 2
			break;
		case TMS_OFFL:
			mp->mscp_opcode = M_OP_AVAIL;
			mp->mscp_modifier = M_MD_UNLOD | M_MD_CLSEX;
D 2
			tms_info[ui->ui_unit].tms_serex = 0;
E 2
I 2
			tms->tms_serex = 0;
E 2
			break;
		case TMS_SENSE:
			mp->mscp_opcode = M_OP_GTUNT;
			break;
		case TMS_CACHE:
			mp->mscp_opcode = M_OP_STUNT;
D 2
			tms_info[ui->ui_unit].tms_unitflgs |= M_UF_WBKNV;
			mp->mscp_unitflgs = tms_info[ui->ui_unit].tms_unitflgs;
			mp->mscp_format = tms_info[ui->ui_unit].tms_format;
E 2
I 2
			tms->tms_unitflgs |= M_UF_WBKNV;
			mp->mscp_unitflgs = tms->tms_unitflgs;
			mp->mscp_format = tms->tms_format;
E 2
			/* default device dependant parameters */
			mp->mscp_mediaid = 0;
			break;
		case TMS_NOCACHE:
			mp->mscp_opcode = M_OP_STUNT;
D 2
			tms_info[ui->ui_unit].tms_unitflgs &= ~(M_UF_WBKNV);
			mp->mscp_unitflgs = tms_info[ui->ui_unit].tms_unitflgs;
			mp->mscp_format = tms_info[ui->ui_unit].tms_format;
E 2
I 2
			tms->tms_unitflgs &= ~(M_UF_WBKNV);
			mp->mscp_unitflgs = tms->tms_unitflgs;
			mp->mscp_format = tms->tms_format;
E 2
			/* default device dependant parameters */
			mp->mscp_mediaid = 0;
			break;
		case TMS_CSE:
			/*
			 * This is a no-op command. It performs a 
			 * clear serious exception only.  (Done on a
			 * non-rewinding close after a serious exception.)
			 */
			mp->mscp_opcode = M_OP_REPOS;
			mp->mscp_modifier = M_MD_CLSEX;
D 2
			tms_info[ui->ui_unit].tms_serex = 0;
			tms_info[ui->ui_unit].tms_clserex = 1;
E 2
I 2
			tms->tms_serex = 0;
			tms->tms_clserex = 1;
E 2
			break;
		case TMS_LOWDENSITY:
			/*
			 * Set the unit to low density
			 */
			mp->mscp_opcode = M_OP_STUNT;
D 2
			mp->mscp_unitflgs = tms_info[ui->ui_unit].tms_unitflgs;
			mp->mscp_mediaid = 0;	/* default device dependant par
ameters */
			if ((tms_info[ui->ui_unit].tms_fmtmenu & M_TF_800) != 0
)
E 2
I 2
			mp->mscp_unitflgs = tms->tms_unitflgs;
			mp->mscp_mediaid = 0;	/* default device dependant parameters */
			if ((tms->tms_fmtmenu & M_TF_800) != 0)
E 2
				mp->mscp_format = M_TF_800;
			else
D 2
				mp->mscp_format = M_TF_PE & tms_info[ui->ui_uni
t].tms_fmtmenu;
			tms_info[ui->ui_unit].tms_format = mp->mscp_format;
E 2
I 2
				mp->mscp_format = M_TF_PE & tms->tms_fmtmenu;
			tms->tms_format = mp->mscp_format;
E 2
			break;
		case TMS_HIDENSITY:
			/*
			 * Set the unit to high density (format == 0)
			 */
			mp->mscp_opcode = M_OP_STUNT;
D 2
			mp->mscp_unitflgs = tms_info[ui->ui_unit].tms_unitflgs;
			mp->mscp_mediaid = 0;	/* default device dependant par
ameters */
E 2
I 2
			mp->mscp_unitflgs = tms->tms_unitflgs;
			mp->mscp_mediaid = 0;	/* default device dependant parameters */
E 2
			mp->mscp_format = 0;
D 2
			tms_info[ui->ui_unit].tms_format = 0;
E 2
I 2
			tms->tms_format = 0;
E 2
			break;
		default:
			printf("Bad ioctl on tms unit %d\n", ui->ui_unit);
			/* Need a no-op. Reposition no amount */
			mp->mscp_opcode = M_OP_REPOS;
			break;
		}   /* end switch (bp->b_resid) */
		}
	else    /* Its a read/write command (not an ioctl) */
		{
		mp->mscp_opcode = bp->b_flags&B_READ ? M_OP_READ : M_OP_WRITE;
		mp->mscp_bytecnt = bp->b_bcount;
D 14
#       	if MVAX
		if (cpu == MVAX_I)
			{
			mp->mscp_buffer = (i & 0x3ffff) | TMSCP_MAP;
D 2
			mp->mscp_mapbase = (long)&(uba_hd[um->um_ubanum].uh_phy
suba->uba_map[0]);
E 2
I 2
			mp->mscp_mapbase = (long)&(uba_hd[um->um_ubanum].uh_physuba->uba_map[0]);
E 2
			}
		else
#		endif MVAX
			mp->mscp_buffer = (i & 0x3ffff) | (((i>>28)&0xf)<<24);
E 14
I 14
		mp->mscp_buffer = UBAI_ADDR(i) | (UBAI_BDP(i) << 24);
E 14
D 2
 
E 2
I 2

E 2
		bp->b_ubinfo = tempi;			/* save mapping info */
		}
D 2
	if (tms_info[ui->ui_unit].tms_serex == 2)	/* if tape mark read */
E 2
I 2
	if (tms->tms_serex == 2)			/* if tape mark read */
E 2
		{
D 2
		mp->mscp_modifier |= M_MD_CLSEX;	/*  clear serious exc *
/
		tms_info[ui->ui_unit].tms_serex = 0;
E 2
I 2
		mp->mscp_modifier |= M_MD_CLSEX;	/*  clear serious exc */
		tms->tms_serex = 0;
E 2
		}
	*((long *)mp->mscp_dscptr) |= TMSCP_OWN|TMSCP_INT;
#	ifdef DEBUG
D 2
	printd("tmscpstart: opcode 0%o mod %o unit %d cnt %d\n",mp->mscp_opcode
,mp->mscp_modifier,mp->mscp_unit,mp->mscp_bytecnt);
E 2
I 2
	printd("tmscpstart: opcode 0%o mod %o unit %d cnt %d\n",mp->mscp_opcode,mp->mscp_modifier,mp->mscp_unit,mp->mscp_bytecnt);
E 2
	if(tmscpdebug)DELAY(100000);
#	endif
	i = tmscpaddr->tmscpip;              /* initiate polling */
	dp->b_qsize++;
	/*
	 * Move drive to the end of the controller queue
	 */
	if (dp->b_forw != NULL)
		{
		um->um_tab.b_actf = dp->b_forw;
		um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_forw = NULL;
		}
	/*
	 * Move buffer to I/O wait queue
	 */
	dp->b_actf = bp->av_forw;
	dp = &tmscpwtab[um->um_ctlr];
	bp->av_forw = dp;
	bp->av_back = dp->av_back;
	dp->av_back->av_forw = bp;
	dp->av_back = bp;
	if (tmscpaddr->tmscpsa&TMSCP_ERR)
		{
D 2
		printf("tmscp%d: fatal error (0%o)\n", um->um_ctlr, tmscpaddr->
tmscpsa&0xffff);
E 2
I 2
		printf("tmscp%d: fatal error (0%o)\n", um->um_ctlr, tmscpaddr->tmscpsa&0xffff);
E 2
D 5
		tmscpinit(um->um_ctlr);
E 5
I 5
		(void)tmscpinit(um->um_ctlr);
E 5
		break;
		}
    }   /* end for */
    /*
     * Check for response ring transitions lost in the
     * Race condition
     */
    for (i = sc->sc_lastrsp;; i++)
	    {
	    i %= NRSP;
	    if (tm->tmscp_ca.ca_rspdsc[i]&TMSCP_OWN)
		    break;
	    tmscprsp(um, tm, sc, i);
	    tm->tmscp_ca.ca_rspdsc[i] |= TMSCP_OWN;
	    }
    sc->sc_lastrsp = i;
}
D 2
 
 
E 2
I 2


E 2
/*
 * Process a response packet
 */
tmscprsp(um, tm, sc, i)
	register struct uba_ctlr *um;
	register struct tmscp *tm;
	register struct tmscp_softc *sc;
	int i;
{
	register struct mscp *mp;
I 2
	register struct tms_info *tms;
E 2
	struct uba_device *ui;
D 3
	struct buf *dp, *bp, nullbp;
E 3
I 3
	struct buf *dp, *bp;
E 3
	int st;
D 2
 
E 2
I 2

E 2
	mp = &tm->tmscp_rsp[i];
	mp->mscp_header.tmscp_msglen = mscp_msglen;
D 2
	sc->sc_credits += mp->mscp_header.tmscp_credits & 0xf;  /* low 4 bits *
/
E 2
I 2
	sc->sc_credits += mp->mscp_header.tmscp_credits & 0xf;  /* low 4 bits */
E 2
	if ((mp->mscp_header.tmscp_credits & 0xf0) > 0x10)	/* Check */
		return;
#	ifdef DEBUG
D 2
	printd("tmscprsp, opcode 0%o status 0%o\n",mp->mscp_opcode,mp->mscp_sta
tus&M_ST_MASK);
E 2
I 2
	printd("tmscprsp, opcode 0%o status 0%o\n",mp->mscp_opcode,mp->mscp_status&M_ST_MASK);
E 2
#	endif	
	/*
	 * If it's an error log message (datagram),
	 * pass it on for more extensive processing.
	 */
	if ((mp->mscp_header.tmscp_credits & 0xf0) == 0x10)
		{	/* check */
		tmserror(um, (struct mslg *)mp);
		return;
		}
	st = mp->mscp_status&M_ST_MASK;
	/*
	 * The controller interrupts as drive 0.
	 * This means that you must check for controller interrupts
	 * before you check to see if there is a drive 0.
	 */
	if((M_OP_STCON|M_OP_END) == mp->mscp_opcode)
		{
		if (st == M_ST_SUCC)
			{
#		  	ifdef DEBUG
D 2
			printd("ctlr has %d credits\n", mp->mscp_header.tmscp_c
redits & 0xf);
E 2
I 2
			printd("ctlr has %d credits\n", mp->mscp_header.tmscp_credits & 0xf);
E 2
			printd("ctlr timeout = %d\n", mp->mscp_cnttmo);
#			endif
			sc->sc_state = S_RUN;
			}
		else
			sc->sc_state = S_IDLE;
		um->um_tab.b_active = 0;
		wakeup((caddr_t)um);
		return;
		}
D 2
	if (mp->mscp_unit >= nNTMS)
E 2
I 2
	if (mp->mscp_unit >= NTMS)
E 2
		return;
	if ((ui = tmscpip[um->um_ctlr][mp->mscp_unit]) == 0)
		return;
I 2
	tms = &tms_info[ui->ui_unit];
E 2
	/*
	 * Save endcode, endflags, and status for mtioctl get unit status.
	 * NOTE: Don't do this on Clear serious exception (reposition no-op);
	 *    which is done on close since this would
	 *    overwrite the real status we want.
	 */
D 2
	if (tms_info[ui->ui_unit].tms_clserex != 1)
E 2
I 2
	if (tms->tms_clserex != 1)
E 2
		{
D 2
		tms_info[ui->ui_unit].tms_endcode = mp->mscp_opcode;
		tms_info[ui->ui_unit].tms_flags = mp->mscp_flags;
		tms_info[ui->ui_unit].tms_status = st;
E 2
I 2
		tms->tms_endcode = mp->mscp_opcode;
		tms->tms_flags = mp->mscp_flags;
		tms->tms_status = st;
E 2
		}
D 2
	else tms_info[ui->ui_unit].tms_clserex = 0;
 
E 2
I 2
	else tms->tms_clserex = 0;

E 2
	switch (mp->mscp_opcode) {
	case M_OP_ONLIN|M_OP_END:
D 2
		tms_info[ui->ui_unit].tms_type = mp->mscp_mediaid;
E 2
I 2
		tms->tms_type = mp->mscp_mediaid;
E 2
		dp = &tmsutab[ui->ui_unit];
		if (st == M_ST_SUCC)
			{
			/*
			 * Link the drive onto the controller queue
			 */
			dp->b_forw = NULL;
			if (um->um_tab.b_actf == NULL)
				um->um_tab.b_actf = dp;
			else
				um->um_tab.b_actl->b_forw = dp;
			um->um_tab.b_actl = dp;
			ui->ui_flags = 1;       /* mark it online */
D 2
			tms_info[ui->ui_unit].tms_dsize=(daddr_t)mp->mscp_maxwr
t;
E 2
I 2
			tms->tms_dsize=(daddr_t)mp->mscp_maxwrt;
E 2
#			ifdef DEBUG
			printd("tmscprsp: unit %d online\n", mp->mscp_unit);
#			endif			
			/* 
			 * This define decodes the Media type identifier
			 */
D 2
#	        	define F_to_C(x,i)     ( ((x)->mscp_mediaid) >> (i*5+7)
 & 0x1f ? ( ( (((x)->mscp_mediaid) >>( i*5 + 7)) & 0x1f) + 'A' - 1): ' ')
E 2
I 2
#	        	define F_to_C(x,i)     ( ((x)->mscp_mediaid) >> (i*5+7) & 0x1f ? ( ( (((x)->mscp_mediaid) >>( i*5 + 7)) & 0x1f) + 'A' - 1): ' ')
E 2
#			ifdef DEBUG
			printd("tmscprsp: unit %d online %x %c%c %c%c%c%d\n"
				,mp->mscp_unit, mp->mscp_mediaid ,F_to_C(mp,4)
				,F_to_C(mp,3), F_to_C(mp,2)
D 2
				,F_to_C(mp,1), F_to_C(mp,0), mp->mscp_mediaid &
 0x7f);
E 2
I 2
				,F_to_C(mp,1), F_to_C(mp,0), mp->mscp_mediaid & 0x7f);
E 2
#			endif				
			dp->b_active = 1;
			}	/* end if st == M_ST_SUCC */
		else 
			{
D 3
			if(dp->b_actf)
E 3
I 3
			if (bp = dp->b_actf)
E 3
D 2
				harderr(dp->b_actf,"tms");
E 2
I 2
				tprintf(tms->tms_ttyp,
				    "tms%d: hard error bn%d: OFFLINE\n",
				    minor(bp->b_dev)&03, bp->b_blkno);
E 2
			else
D 2
				{
				nullbp.b_blkno = 0;
				nullbp.b_dev = makedev(TMSCPDEVNUM,ui->ui_unit)
;
				harderr(&nullbp, "tms" );
				}
			printf("OFFLINE\n");
E 2
I 2
				tprintf(tms->tms_ttyp,
				    "tms%d: hard error: OFFLINE\n",
D 3
				    minor(bp->b_dev)&03);
E 3
I 3
				    ui->ui_unit);
E 3
E 2
			while (bp = dp->b_actf)
				{
				dp->b_actf = bp->av_forw;
				bp->b_flags |= B_ERROR;
				iodone(bp);
				}
			}
		if(mp->mscp_cmdref!=NULL)
			/* Seems to get lost sometimes in uda */
D 5
			wakeup((caddr_t *) mp->mscp_cmdref);
E 5
I 5
			wakeup((caddr_t)mp->mscp_cmdref);
E 5
		break;
	/*
	 * The AVAILABLE ATTENTION message occurs when the
	 * unit becomes available after loading,
	 * marking the unit offline (ui_flags = 0) will force an
	 * online command prior to using the unit.
	 */
	case M_OP_AVATN:
		ui->ui_flags = 0;
D 2
		tms_info[ui->ui_unit].tms_type = mp->mscp_mediaid;
E 2
I 2
		tms->tms_type = mp->mscp_mediaid;
E 2
		break;
	case M_OP_END:
		/*
		 * An endcode without an opcode (0200) is an invalid command.
		 * The mscp specification states that this would be a protocol
		 * type error, such as illegal opcodes. The mscp spec. also
		 * states that parameter error type of invalid commands should
D 2
		 * return the normal end message for the command. This does not
 appear
		 * to be the case. An invalid logical block number returned an 
endcode
E 2
I 2
		 * return the normal end message for the command. This does not appear
		 * to be the case. An invalid logical block number returned an endcode
E 2
		 * of 0200 instead of the 0241 (read) that was expected.
		 */
			
		printf("tmscp%d: invalid cmd, endcode = %o, status=%o\n",
			um->um_ctlr, mp->mscp_opcode, st);
		bp = (struct buf *)mp->mscp_cmdref;
		/*
		 * Unlink buffer from I/O wait queue.
		 * And signal iodone, so the higher level command can exit!
		 *
		 */
		bp->av_back->av_forw = bp->av_forw;
		bp->av_forw->av_back = bp->av_back;
		dp = &tmsutab[ui->ui_unit];
		dp->b_qsize--;
		iodone(bp);
		break;
	case M_OP_WRITE|M_OP_END:
		/* mark the last io op as a write */
D 2
		tms_info[ui->ui_unit].tms_lastiow = 1;
E 2
I 2
		tms->tms_lastiow = 1;
E 2
	case M_OP_READ|M_OP_END:
	case M_OP_WRITM|M_OP_END:
	case M_OP_REPOS|M_OP_END:
	case M_OP_STUNT|M_OP_END:
	/*
	 * The AVAILABLE message occurs when the mt ioctl "rewoffl" is
	 * issued.  For the ioctl, "rewoffl", a tmscp AVAILABLE command is
	 * done with the UNLOAD modifier.  This performs a rewind, followed
	 * by marking the unit offline.  So mark the unit offline
	 * software wise as well (ui_flags = 0 and 
D 2
	 * tms_info[ui->ui_unit].tms_openf = 0).
E 2
I 2
	 * tms->tms_openf = 0).
E 2
	 */
	case M_OP_AVAIL|M_OP_END:
#		ifdef DEBUG
		printd("tmscprsp: position = %d\n", mp->mscp_lbn);
#		endif
		bp = (struct buf *)mp->mscp_cmdref;
		/*
D 2
		 * Only need to release buffer if the command was read or write
.
E 2
I 2
		 * Only need to release buffer if the command was read or write.
E 2
		 * No ubasetup was done in "tmscpstart" if it was an ioctl cmd.
		 */
		if (mp->mscp_opcode == (M_OP_READ|M_OP_END) || 
		    mp->mscp_opcode == (M_OP_WRITE|M_OP_END))
			ubarelse(um->um_ubanum, (int *)&bp->b_ubinfo);
		/*
		 * Unlink buffer from I/O wait queue.
		 */
		bp->av_back->av_forw = bp->av_forw;
		bp->av_forw->av_back = bp->av_back;
D 2
#		if defined(VAX750) || defined(VAX8200)
		if ((cpu == VAX_750) || (cpu == VAX_8200)) { 
		    if ((tmscpwtab[um->um_ctlr].av_forw == &tmscpwtab[um->um_ct
lr]) &&
E 2
I 2
#		if defined(VAX750)
		if (cpu == VAX_750) { 
		    if ((tmscpwtab[um->um_ctlr].av_forw == &tmscpwtab[um->um_ctlr]) &&
E 2
					(um->um_ubinfo != 0)) {
			ubarelse(um->um_ubanum, &um->um_ubinfo);
		    }
		    else {
			if (mp->mscp_opcode == (M_OP_READ|M_OP_END) ||
		    	    mp->mscp_opcode == (M_OP_WRITE|M_OP_END))
D 2
				UBAPURGE(uba_hd[um->um_ubanum].uh_uba,(um->um_u
binfo >>28) & 0x0f);
E 2
I 2
				UBAPURGE(uba_hd[um->um_ubanum].uh_uba,(um->um_ubinfo >>28) & 0x0f);
E 2
		    }
		}
#		endif
		dp = &tmsutab[ui->ui_unit];
		dp->b_qsize--;
		if (st == M_ST_OFFLN || st == M_ST_AVLBL)
			{
			ui->ui_flags = 0;       /* mark unit offline */
D 2
			tms_info[ui->ui_unit].tms_openf = 0;
			tms_info[ui->ui_unit].tms_type = mp->mscp_mediaid;
E 2
I 2
			tms->tms_openf = 0;
			tms->tms_type = mp->mscp_mediaid;
E 2
			/*
			 * Link the buffer onto the front of the drive queue
			 */
			if ((bp->av_forw = dp->b_actf) == 0)
				dp->b_actl = bp;
			dp->b_actf = bp;
			/*
			 * Link the drive onto the controller queue
			 */
			if (dp->b_active == 0)
				{
				dp->b_forw = NULL;
				if (um->um_tab.b_actf == NULL)
					um->um_tab.b_actf = dp;
				else
					um->um_tab.b_actl->b_forw = dp;
				um->um_tab.b_actl = dp;
				dp->b_active = 1;
				}
D 2
#			if defined(VAX750) || defined(VAX8200)
			if (((cpu == VAX_750) || (cpu == VAX_8200)) && um->um_u
binfo == 0)
				um->um_ubinfo = uballoc(um->um_ubanum, (caddr_t
)0, 0, UBA_NEEDBDP);
E 2
I 2
#			if defined(VAX750)
			if (cpu == VAX_750 && um->um_ubinfo == 0)
				um->um_ubinfo = uballoc(um->um_ubanum, (caddr_t)0, 0, UBA_NEEDBDP);
E 2
#			endif
			return;
			}
		if (st != M_ST_SUCC)
			{
			if (mp->mscp_flags & M_EF_SEREX)
D 2
				tms_info[ui->ui_unit].tms_serex = 1;
E 2
I 2
				tms->tms_serex = 1;
E 2
			if (st != M_ST_TAPEM)
				{
D 2
				harderr(bp, "tms");
				errinfo(st);		/* produces more info *
/
E 2
I 2
				tprintf(tms->tms_ttyp,
				    "tms%d: hard error bn%d\n",
				    minor(bp->b_dev)&03, bp->b_blkno);
				errinfo(st);		/* produces more info */
E 2
#				ifdef DEBUG
D 2
				printd("tmscprsp: error; status sub-code = 0%o,
 flags = 0%o\n",
					(mp->mscp_status & 177740)>>5, mp->mscp
_flags);
E 2
I 2
				printd("tmscprsp: error; status sub-code = 0%o, flags = 0%o\n",
					(mp->mscp_status & 177740)>>5, mp->mscp_flags);
E 2
#				endif
				bp->b_flags |= B_ERROR;
				}
			else
				/* Hit a tape mark - Set serex flag to
				 * a special value so we can clear the
				 * serious exception on the next command.
				 */
D 2
				tms_info[ui->ui_unit].tms_serex = 2;
E 2
I 2
				tms->tms_serex = 2;
E 2
			}
		/*
		 * The tmscp spec states that controllers do not have to
		 * report the number of records or files skipped.  So on
		 * reposition commands we go strictly by cmd status.
		 */
		if (mp->mscp_opcode != (M_OP_REPOS|M_OP_END))
			bp->b_resid = bp->b_bcount - mp->mscp_bytecnt;
		else
			bp->b_resid = 0;
D 2
		tms_info[ui->ui_unit].tms_resid = bp->b_resid;
E 2
I 2
		tms->tms_resid = bp->b_resid;
E 2
		iodone(bp);
		break;
D 2
 
E 2
I 2

E 2
	case M_OP_GTUNT|M_OP_END:
#		ifdef DEBUG
		printd("tmscprsp: GTUNT end packet status = 0%o\n",st);
D 2
		printd("tmscprsp: unit %d mediaid %x %c%c %c%c%c%d %x %x t=%d\n
"
E 2
I 2
		printd("tmscprsp: unit %d mediaid %x %c%c %c%c%c%d %x %x t=%d\n"
E 2
		    ,mp->mscp_unit, mp->mscp_mediaid
		    ,F_to_C(mp,4),F_to_C(mp,3),F_to_C(mp,2)
		    ,F_to_C(mp,1),F_to_C(mp,0)
		    ,mp->mscp_mediaid & 0x7f
		    ,mp->mscp_unitid.val[0]
		    ,mp->mscp_unitid.val[1]
		    ,mp->mscp_format);
#		endif		
D 2
		tms_info[ui->ui_unit].tms_type = mp->mscp_mediaid;
		tms_info[ui->ui_unit].tms_fmtmenu = mp->mscp_fmtmenu;
		tms_info[ui->ui_unit].tms_unitflgs = mp->mscp_unitflgs;
E 2
I 2
		tms->tms_type = mp->mscp_mediaid;
		tms->tms_fmtmenu = mp->mscp_fmtmenu;
		tms->tms_unitflgs = mp->mscp_unitflgs;
E 2
		break;
D 2
 
E 2
I 2

E 2
	default:
		printf("tmscp unknown packet\n");
		tmserror(um, (struct mslg *)mp);
	}	/* end switch mp->mscp_opcode */
}
D 2
 
 
E 2
I 2


E 2
/* 
 * Give a meaningful error when the mscp_status field returns an error code.
 */
D 2
 
E 2
I 2

E 2
errinfo(st)
	int st;			/* the status code */
{
	switch(st) {
	case M_ST_ICMD:
		printf("invalid command\n");
		break;
	case M_ST_ABRTD:
		printf("command aborted\n");
		break;
	case M_ST_OFFLN:
		printf("unit offline\n");
		break;
	case M_ST_WRTPR:
		printf("unit write protected\n");
		break;
	case M_ST_COMP:
		printf("compare error\n");
		break;
	case M_ST_DATA:
		printf("data error\n");
		break;
	case M_ST_HSTBF:
		printf("host buffer access error\n");
		break;
	case M_ST_CNTLR:
		printf("controller error\n");
		break;
	case M_ST_DRIVE:
		printf("drive error\n");
		break;
	case M_ST_FMTER:
		printf("formatter error\n");
		break;
	case M_ST_BOT:
		printf("BOT encountered\n");
		break;
	case M_ST_TAPEM:
		printf("tape mark encountered\n");
		break;
	case M_ST_RDTRN:
		printf("record data truncated\n");
		break;
	case M_ST_PLOST:
		printf("position lost\n");
		break;
	case M_ST_SEX:
		printf("serious exception\n");
		break;
	case M_ST_LED:
		printf("LEOT detected\n");
		break;
	}
}
D 2
 
 
E 2
I 2


E 2
/*
 * Manage buffers and perform block mode read and write operations.
 */
D 2
 
E 2
I 2

E 2
tmscpstrategy (bp)
	register struct buf *bp;
{
	register struct uba_device *ui;
	register struct uba_ctlr *um;
	register struct buf *dp;
	register int unit = TMSUNIT(bp->b_dev);
	int s;
D 2
 
	if (unit >= nNTMS)
E 2
I 2

	if (unit >= NTMS)
E 2
		{
#		ifdef DEBUG
		printd ("tmscpstrategy: bad unit # %d\n",unit);
#		endif
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
		}
	ui = tmsdinfo[unit];
	um = ui->ui_mi;
	if (ui == 0 || ui->ui_alive == 0)
		{
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
		}
	s = spl5();
	/*
	 * Link the buffer onto the drive queue
	 */
	dp = &tmsutab[ui->ui_unit];
	if (dp->b_actf == 0)
		dp->b_actf = bp;
	else
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	bp->av_forw = 0;
	/*
	 * Link the drive onto the controller queue
	 */
	if (dp->b_active == 0)
		{
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_active = 1;
		}
	/*
	 * If the controller is not active, start it.
	 */
	if (um->um_tab.b_active == 0)
		{
D 2
#		if defined(VAX750) || defined(VAX8200)
		if (((cpu == VAX_750) || (cpu == VAX_8200))
				 && tmscpwtab[um->um_ctlr].av_forw == &tmscpwta
b[um->um_ctlr])
E 2
I 2
#		if defined(VAX750)
		if (cpu == VAX_750
				 && tmscpwtab[um->um_ctlr].av_forw == &tmscpwtab[um->um_ctlr])
E 2
			{
			if (um->um_ubinfo != 0)
D 2
				mprintf("tmscpstrategy: ubinfo 0x%x\n",um->um_u
binfo);
E 2
I 2
				log(TMS_PRI, "tmscpstrategy: ubinfo 0x%x\n",
				    um->um_ubinfo);
E 2
			else
D 2
				um->um_ubinfo = uballoc(um->um_ubanum, (caddr_t
)0, 0, UBA_NEEDBDP);
E 2
I 2
				um->um_ubinfo = uballoc(um->um_ubanum, (caddr_t)0, 0, UBA_NEEDBDP);
E 2
			}
#		endif
#		ifdef DEBUG
D 2
		printd10("tmscpstrategy: Controller not active, starting it\n")
;
E 2
I 2
		printd10("tmscpstrategy: Controller not active, starting it\n");
E 2
#		endif
		(void) tmscpstart(um);
		}
	splx(s);
	return;
}
D 2
 
E 2
I 2

E 2
#define DBSIZE 32
D 2
 
E 2
I 2

E 2
#define ca_Rspdsc       ca_rspdsc[0]
#define ca_Cmddsc       ca_rspdsc[1]
#define tmscp_Rsp       tmscp_rsp[0]
#define tmscp_Cmd       tmscp_cmd[0]
D 2
 
E 2
I 2

E 2
struct  tmscp     tmscpd[NTMSCP];
D 2
 
E 2
I 2

E 2
tmscpdump(dev)
	dev_t dev;
{
	struct tmscpdevice *tmscpaddr;
	struct tmscp *tmscp_ubaddr;
	char *start;
	int num, blk, unit;
	register struct uba_regs *uba;
	register struct uba_device *ui;
	register struct tmscp *tmscpp;
	register struct pte *io;
	register int i;
D 2
 
E 2
I 2

E 2
	unit = minor(dev) & 03;
D 2
	if (unit >= nNTMS)
E 2
I 2
	if (unit >= NTMS)
E 2
		return (ENXIO);
#	define phys(cast, addr) ((cast)((int)addr & 0x7fffffff))
	ui = phys(struct uba_device *, tmsdinfo[unit]);
	if (ui->ui_alive == 0)
		return (ENXIO);
	uba = phys(struct uba_hd *, ui->ui_hd)->uh_physuba;
D 2
	if (ui->ui_hd->uba_type)
		buainit(uba);
	else
		ubainit(uba);
E 2
I 2
	ubainit(uba);
E 2
	tmscpaddr = (struct tmscpdevice *)ui->ui_physaddr;
	DELAY(2000000);
	tmscpp = phys(struct tmscp *, &tmscpd[ui->ui_ctlr]);
D 2
 
E 2
I 2

E 2
	num = btoc(sizeof(struct tmscp)) + 1;
	io = &uba->uba_map[NUBMREG-num];
	for(i = 0; i<num; i++)
		*(int *)io++ = UBAMR_MRV|(btop(tmscpp)+i);
D 2
#	ifdef MVAX
	if( cpu == MVAX_I )
		tmscp_ubaddr = tmscpp;
	else
#	endif MVAX
		tmscp_ubaddr = (struct tmscp *)(((int)tmscpp & PGOFSET)|((NUBMR
EG-num)<<9));
 
E 2
I 2
	tmscp_ubaddr = (struct tmscp *)(((int)tmscpp & PGOFSET)|((NUBMREG-num)<<9));

E 2
	tmscpaddr->tmscpip = 0;
	while ((tmscpaddr->tmscpsa & TMSCP_STEP1) == 0)
		if(tmscpaddr->tmscpsa & TMSCP_ERR) return(EFAULT);
	tmscpaddr->tmscpsa = TMSCP_ERR;
	while ((tmscpaddr->tmscpsa & TMSCP_STEP2) == 0)
		if(tmscpaddr->tmscpsa & TMSCP_ERR) return(EFAULT);
	tmscpaddr->tmscpsa = (short)&tmscp_ubaddr->tmscp_ca.ca_ringbase;
	while ((tmscpaddr->tmscpsa & TMSCP_STEP3) == 0)
		if(tmscpaddr->tmscpsa & TMSCP_ERR) return(EFAULT);
D 2
	tmscpaddr->tmscpsa = (short)(((int)&tmscp_ubaddr->tmscp_ca.ca_ringbase)
 >> 16);
E 2
I 2
	tmscpaddr->tmscpsa = (short)(((int)&tmscp_ubaddr->tmscp_ca.ca_ringbase) >> 16);
E 2
	while ((tmscpaddr->tmscpsa & TMSCP_STEP4) == 0)
		if(tmscpaddr->tmscpsa & TMSCP_ERR) return(EFAULT);
	tmscpaddr->tmscpsa = TMSCP_GO;
D 2
	tmscpp->tmscp_ca.ca_Rspdsc = (long)&tmscp_ubaddr->tmscp_Rsp.mscp_cmdref
;
	tmscpp->tmscp_ca.ca_Cmddsc = (long)&tmscp_ubaddr->tmscp_Cmd.mscp_cmdref
;
E 2
I 2
	tmscpp->tmscp_ca.ca_Rspdsc = (long)&tmscp_ubaddr->tmscp_Rsp.mscp_cmdref;
	tmscpp->tmscp_ca.ca_Cmddsc = (long)&tmscp_ubaddr->tmscp_Cmd.mscp_cmdref;
E 2
	tmscpp->tmscp_Cmd.mscp_header.tmscp_vcid = 1;	/* for tape */
	tmscpp->tmscp_Cmd.mscp_cntflgs = 0;
	tmscpp->tmscp_Cmd.mscp_version = 0;
	if (tmscpcmd(M_OP_STCON, tmscpp, tmscpaddr) == 0) {
		return(EFAULT);
	}
	tmscpp->tmscp_Cmd.mscp_unit = ui->ui_slave;
	if (tmscpcmd(M_OP_ONLIN, tmscpp, tmscpaddr) == 0) {
		return(EFAULT);
	}
D 2
 
E 2
I 2

E 2
	num = maxfree;
	start = 0;
	while (num > 0)
		{
		blk = num > DBSIZE ? DBSIZE : num;
		io = uba->uba_map;
		for (i = 0; i < blk; i++)
			*(int *)io++ = (btop(start)+i) | UBAMR_MRV;
		*(int *)io = 0;
		tmscpp->tmscp_Cmd.mscp_lbn = btop(start);
		tmscpp->tmscp_Cmd.mscp_unit = ui->ui_slave;
		tmscpp->tmscp_Cmd.mscp_bytecnt = blk*NBPG;
#		ifdef	MVAX
		if( cpu == MVAX_I )
			tmscpp->tmscp_Cmd.mscp_buffer = (long) start;
		else
#		endif 	MVAX
			tmscpp->tmscp_Cmd.mscp_buffer = 0;
		if (tmscpcmd(M_OP_WRITE, tmscpp, tmscpaddr) == 0)
			return(EIO);
		start += blk*NBPG;
		num -= blk;
		}
	return (0);
}
D 2
 
 
E 2
I 2


E 2
/*
 * Perform a standalone tmscp command.  This routine is only used by tmscpdump.
 */
D 2
 
E 2
I 2

E 2
tmscpcmd(op, tmscpp, tmscpaddr)
	int op;
	register struct tmscp *tmscpp;
	struct tmscpdevice *tmscpaddr;
{
	int i;
D 2
 
E 2
I 2

E 2
D 3
#	ifdef lint
	i = i;
#	endif
E 3
D 2
 
E 2
I 2

E 2
	tmscpp->tmscp_Cmd.mscp_opcode = op;
	tmscpp->tmscp_Rsp.mscp_header.tmscp_msglen = mscp_msglen;
	tmscpp->tmscp_Cmd.mscp_header.tmscp_msglen = mscp_msglen;
	tmscpp->tmscp_ca.ca_Rspdsc |= TMSCP_OWN|TMSCP_INT;
	tmscpp->tmscp_ca.ca_Cmddsc |= TMSCP_OWN|TMSCP_INT;
	if (tmscpaddr->tmscpsa&TMSCP_ERR)
		printf("tmscp fatal error (0%o)\n", tmscpaddr->tmscpsa&0xffff);
	i = tmscpaddr->tmscpip;
I 3
#ifdef lint
	i = i;
#endif
E 3
	for (;;)
		{
		if (tmscpp->tmscp_ca.ca_cmdint)
			tmscpp->tmscp_ca.ca_cmdint = 0;
		if (tmscpp->tmscp_ca.ca_rspint)
			break;
		}
	tmscpp->tmscp_ca.ca_rspint = 0;
	if (tmscpp->tmscp_Rsp.mscp_opcode != (op|M_OP_END) ||
	    (tmscpp->tmscp_Rsp.mscp_status&M_ST_MASK) != M_ST_SUCC)
		{
		printf("error: com %d opc 0x%x stat 0x%x\ndump ", op,
D 2
			tmscpp->tmscp_Rsp.mscp_opcode, tmscpp->tmscp_Rsp.mscp_s
tatus);
E 2
I 2
			tmscpp->tmscp_Rsp.mscp_opcode, tmscpp->tmscp_Rsp.mscp_status);
E 2
		return(0);
		}
	return(1);
}
D 2
 
 
E 2
I 2
D 11


E 2
/*
 * Perform raw read
 */
D 2
 
E 2
I 2

E 2
tmscpread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register int unit = TMSUNIT(dev);
D 2
 
	if (unit >= nNTMS)
E 2
I 2

	if (unit >= NTMS)
E 2
		return (ENXIO);
D 2
	return (physio(tmscpstrategy, &rtmsbuf[unit], dev, B_READ, minphys, uio
));
E 2
I 2
	return (physio(tmscpstrategy, &rtmsbuf[unit], dev, B_READ, minphys, uio));
E 2
}
D 2
 
 
E 2
I 2


E 2
/*
 * Perform raw write
 */
D 2
 
E 2
I 2

E 2
tmscpwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register int unit = TMSUNIT(dev);
D 2
 
	if (unit >= nNTMS)
E 2
I 2

	if (unit >= NTMS)
E 2
		return (ENXIO);
D 2
	return (physio(tmscpstrategy, &rtmsbuf[unit], dev, B_WRITE, minphys, ui
o));
E 2
I 2
	return (physio(tmscpstrategy, &rtmsbuf[unit], dev, B_WRITE, minphys, uio));
E 2
}
D 2
 
 
E 2
I 2

E 11

E 2
/*
 * Catch ioctl commands, and call the "command" routine to do them.
 */
D 2
 
E 2
I 2

I 3
/* ARGSUSED */
E 3
E 2
tmscpioctl(dev, cmd, data, flag)
	dev_t dev;
	int cmd;
	caddr_t data;
	int flag;
{
D 3
	register struct tmscp_softc *sc = &tmscp_softc[TMSCPCTLR(dev)];
E 3
	register struct buf *bp = &ctmscpbuf[TMSCPCTLR(dev)];
	register callcount;	/* number of times to call cmd routine */
	register struct uba_device *ui;
I 2
	register struct tms_info *tms;
E 2
	int fcount;		/* number of files (or records) to space */
D 3
	struct mtop *mtop;	/* mag tape cmd op to perform */
	struct mtget *mtget;	/* mag tape struct to get info in */
E 3
I 3
	register struct mtop *mtop;	/* mag tape cmd op to perform */
	register struct mtget *mtget;	/* mag tape struct to get info in */
E 3
D 2
 
E 2
I 2

E 2
	/* we depend of the values and order of the TMS ioctl codes here */
	static tmsops[] =
	 {TMS_WRITM,TMS_FSF,TMS_BSF,TMS_FSR,TMS_BSR,TMS_REW,TMS_OFFL,TMS_SENSE,
	  TMS_CACHE,TMS_NOCACHE};
D 2
 
E 2
I 2

E 2
	switch (cmd) {
	case MTIOCTOP:	/* tape operation */
		mtop = (struct mtop *)data;
		switch (mtop->mt_op) {
D 2
 
E 2
I 2

E 2
		case MTWEOF:
			callcount = mtop->mt_count;
			fcount = 1;
			break;
		case MTFSF: case MTBSF:
		case MTFSR: case MTBSR:
			callcount = 1;
			fcount = mtop->mt_count;
			break;
		case MTREW: case MTOFFL: case MTNOP:
		case MTCACHE: case MTNOCACHE:
			callcount = 1;
			fcount = 1;		/* wait for this rewind */
			break;
		default:
			return (ENXIO);
		}	/* end switch mtop->mt_op */
D 2
 
E 2
I 2

E 2
		if (callcount <= 0 || fcount <= 0)
			return (EINVAL);
		while (--callcount >= 0)
			{
			tmscpcommand(dev, tmsops[mtop->mt_op], fcount);
			if ((mtop->mt_op == MTFSR || mtop->mt_op == MTBSR) &&
			    bp->b_resid)
				return (EIO);
			if (bp->b_flags & B_ERROR)	/* like hitting BOT */
				break;
			}
		return (geterror(bp));
D 2
 
E 2
I 2

E 2
	case MTIOCGET:
		/*
		 * Return status info associated with the particular UNIT.
		 */
		ui = tmsdinfo[TMSUNIT(dev)];
I 2
		tms = &tms_info[ui->ui_unit];
E 2
		mtget = (struct mtget *)data;
		mtget->mt_type = MT_ISTMSCP;
D 2
		mtget->mt_dsreg = tms_info[ui->ui_unit].tms_flags << 8;
		mtget->mt_dsreg |= tms_info[ui->ui_unit].tms_endcode;
		mtget->mt_erreg = tms_info[ui->ui_unit].tms_status;
		mtget->mt_resid = tms_info[ui->ui_unit].tms_resid;
E 2
I 2
		mtget->mt_dsreg = tms->tms_flags << 8;
		mtget->mt_dsreg |= tms->tms_endcode;
		mtget->mt_erreg = tms->tms_status;
		mtget->mt_resid = tms->tms_resid;
E 2
		break;
D 2
 
E 2
I 2

E 2
	default:
		return (ENXIO);
	}
	return (0);
}
D 2
 
 
E 2
I 2


E 2
/*
 * Reset (for raw mode use only).
 */
D 2
 
E 2
I 2

E 2
tmscpreset (uban)
	int uban;
{
	register struct uba_ctlr *um;
	register struct uba_device *ui;
	register struct buf *bp, *dp;
	register int unit;
	struct buf *nbp;
	int d;
D 2
 
E 2
I 2

E 2
	for (d = 0; d < NTMSCP; d++)
		{
		if ((um = tmscpminfo[d]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
			continue;
		printf(" tmscp%d", d);
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
		tmscp_softc[d].sc_state = S_IDLE;
		tmscp_softc[d].sc_mapped = 0;
D 2
		for (unit = 0; unit < nNTMS; unit++)
E 2
I 2
		for (unit = 0; unit < NTMS; unit++)
E 2
			{
			if ((ui = tmsdinfo[unit]) == 0)
				continue;
			if (ui->ui_alive == 0 || ui->ui_mi != um)
				continue;
			tmsutab[unit].b_active = 0;
			tmsutab[unit].b_qsize = 0;
			}
		for (bp = tmscpwtab[d].av_forw; bp != &tmscpwtab[d]; bp = nbp)
			{
			nbp = bp->av_forw;
			bp->b_ubinfo = 0;
			/*
			 * Link the buffer onto the drive queue
			 */
			dp = &tmsutab[TMSUNIT(bp->b_dev)];
			if (dp->b_actf == 0)
				dp->b_actf = bp;
			else
				dp->b_actl->av_forw = bp;
			dp->b_actl = bp;
			bp->av_forw = 0;
			/*
			 * Link the drive onto the controller queue
			 */
			if (dp->b_active == 0)
				{
				dp->b_forw = NULL;
				if (um->um_tab.b_actf == NULL)
					um->um_tab.b_actf = dp;
				else
					um->um_tab.b_actl->b_forw = dp;
				um->um_tab.b_actl = dp;
				dp->b_active = 1;
				}
			}
D 5
		tmscpinit(d);
E 5
I 5
		(void)tmscpinit(d);
E 5
		}
}
D 2
 
 
E 2
I 2


E 2
/*
 * Process an error log message
 *
 * Only minimal decoding is done, only "useful"
 * information is printed.  Eventually should
 * send message to an error logger.
 */
D 2
 
E 2
I 2

E 2
tmserror(um, mp)
	register struct uba_ctlr *um;
	register struct mslg *mp;
{
	register i;
D 2
 
E 2
I 2

E 2
#	ifdef DEBUG
	printd("tmserror:\n");
#	endif
	if(!(mp->mslg_flags & (M_LF_SUCC | M_LF_CONT)))
D 2
		mprintf("tmscp%d: %s error, ", um->um_ctlr,
E 2
I 2
		log(TMS_PRI, "tmscp%d: %s error, ", um->um_ctlr,
E 2
		mp->mslg_flags & ( M_LF_SUCC | M_LF_CONT ) ? "soft" : "hard");
D 2
 
E 2
I 2

E 2
	switch (mp->mslg_format) {
D 2
 
E 2
I 2

E 2
	case M_FM_CNTERR:
D 2
		mprintf("controller error, event 0%o\n", mp->mslg_event);
E 2
I 2
		log(TMS_PRI, "controller error, event 0%o\n", mp->mslg_event);
E 2
		break;
	case M_FM_BUSADDR:
D 2
		mprintf("host memory access error, event 0%o, addr 0%o\n",
E 2
I 2
		log(TMS_PRI, "host memory access error, event 0%o, addr 0%o\n",
E 2
			mp->mslg_event, mp->mslg_busaddr);
		break;
	case M_FM_TAPETRN:
D 2
		mprintf("tape transfer error, unit %d, grp 0x%x, event 0%o\n",
E 2
I 2
		log(TMS_PRI, "tape transfer error, unit %d, grp 0x%x, event 0%o\n",
E 2
			mp->mslg_unit, mp->mslg_group, mp->mslg_event);
		break;
	case M_FM_STIERR:
D 2
		mprintf("STI error, unit %d, event 0%o\n",
E 2
I 2
		log(TMS_PRI, "STI error, unit %d, event 0%o\n",
E 2
			mp->mslg_unit, mp->mslg_event);
I 2
#ifdef notdef
		/* too painful to do with log() */
E 2
		for(i = 0; i < 62;i++)
			mprintf("\t0x%x",mp->mslg_stiunsucc[i] & 0xff);
		mprintf("\n");
I 2
#endif
E 2
		break;
	case M_FM_STIDEL:
D 2
		mprintf("STI Drive Error Log, unit %d, event 0%o\n",
E 2
I 2
		log(TMS_PRI, "STI Drive Error Log, unit %d, event 0%o\n",
E 2
			mp->mslg_unit, mp->mslg_event);
		break;
	case M_FM_STIFEL:
D 2
		mprintf("STI Formatter Error Log, unit %d, event 0%o\n",
E 2
I 2
		log(TMS_PRI, "STI Formatter Error Log, unit %d, event 0%o\n",
E 2
			mp->mslg_unit, mp->mslg_event);
		break;
	default:
D 2
		mprintf("unknown error, unit %d, format 0%o, event 0%o\n",
E 2
I 2
		log(TMS_PRI, "unknown error, unit %d, format 0%o, event 0%o\n",
E 2
			mp->mslg_unit, mp->mslg_format, mp->mslg_event);
	}
D 2
 
E 2
I 2

E 2
	if (tmscperror)
		{
		register long *p = (long *)mp;
D 2
 
E 2
I 2

E 2
		for (i = 0; i < mp->mslg_header.tmscp_msglen; i += sizeof(*p))
			printf("%x ", *p++);
		printf("\n");
		}
}
#endif
D 2

E 2
E 1
