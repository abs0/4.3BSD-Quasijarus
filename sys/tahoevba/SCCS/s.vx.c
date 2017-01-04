h03258
s 00016/00002/01321
d D 7.2 88/07/09 16:34:51 karels 14 13
c add CCI credit, update copyright
e
s 00009/00003/01314
d D 7.1 88/05/21 18:33:25 karels 13 12
c bring up to revision 7 for tahoe release
e
s 00002/00002/01315
d D 1.11 87/09/06 20:56:54 karels 12 11
c call line discipline start routine!
e
s 00128/00114/01189
d D 1.10 87/01/11 21:23:42 karels 11 10
c more or less 4.3
e
s 00058/00150/01245
d D 1.9 86/11/03 12:29:07 karels 10 9
c more conversion to 4.3-ism's
e
s 00013/00013/01382
d D 1.8 86/01/23 01:09:09 sam 9 8
c put back tabs
e
s 00119/00109/01276
d D 1.7 86/01/21 17:49:40 sam 8 6
c cleanups and typos
e
s 00113/00108/01277
d R 1.7 86/01/21 17:44:58 sam 7 6
c random cleanups and typo corrections
e
s 01012/00449/00373
d D 1.6 86/01/13 12:01:22 sam 6 5
c merge vc?.c files and rename  lots of stuff to ease identification;
c merge all the separate data structures into vx_softc; rename vxblok vxdevice;
c and lots more...
e
s 00017/00017/00805
d D 1.5 86/01/12 21:46:17 sam 5 4
c fix some includes and make scope points globally controlled
e
s 00004/00004/00818
d D 1.4 86/01/12 17:39:57 sam 4 3
c bsc -> tahoebsc; sna -> tahoesna
e
s 00041/00024/00781
d D 1.3 86/01/12 15:53:20 sam 3 2
c start of autoconfig
e
s 00046/00039/00759
d D 1.2 86/01/05 18:37:45 sam 2 1
c 1st working version (mostly)
e
s 00798/00000/00000
d D 1.1 85/07/21 20:36:11 sam 1 0
c date and time created 85/07/21 20:36:11 by sam
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
/*
 * Copyright (c) 1988 Regents of the University of California.
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
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
E 14
 *
 *	%W% (Berkeley) %G%
 */
E 13

#include "vx.h"
#if NVX > 0
/*
D 3
 *	VIOC-X driver
E 3
I 3
 * VIOC-X driver
E 3
 */
I 5
#ifdef VXPERF
D 8
#define	DOSCOPE
E 8
I 8
D 9
#define DOSCOPE
E 9
I 9
#define	DOSCOPE
E 9
E 8
#endif

E 5
I 2
D 13
#include "../tahoe/pte.h"
E 2

E 13
D 5
#include "../h/param.h"
#include "../h/ioctl.h"
#include "../h/tty.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/map.h"
D 2
#include "../machine/pte.h"
E 2
#include "../h/buf.h"
D 2
#include "../vba/vbavar.h"
E 2
#include "../h/conf.h"
#include "../h/file.h"
#include "../h/uio.h"
D 2
#include "../vba/vioc.h"
E 2
I 2
#include "../h/proc.h"
#include "../h/vm.h"
E 5
I 5
#include "param.h"
#include "ioctl.h"
#include "tty.h"
#include "dir.h"
#include "user.h"
#include "map.h"
#include "buf.h"
#include "conf.h"
#include "file.h"
#include "uio.h"
#include "proc.h"
#include "vm.h"
I 6
#include "kernel.h"
I 10
#include "syslog.h"
I 13

#include "../tahoe/pte.h"
E 13
E 10
E 6
E 5

#include "../tahoevba/vbavar.h"
D 6
#include "../tahoevba/vioc.h"
E 6
I 6
#include "../tahoevba/vxreg.h"
E 6
E 2
D 5
#ifdef VXPERF
E 5
D 2
#include "../vba/scope.h"
E 2
I 2
#include "../tahoevba/scope.h"
E 2
D 5
#endif VXPERF
E 5
D 10
#include "vbsc.h"
#if NVBSC > 0
D 4
#include "../bsc/bscio.h"
#include "../bsc/bsc.h"
E 4
I 4
#include "../tahoebsc/bscio.h"
#include "../tahoebsc/bsc.h"
E 4
D 6
char bscport[NVXPORTS];
#endif

E 6
#ifdef BSC_DEBUG
D 4
#include "../bsc/bscdebug.h"
E 4
I 4
#include "../tahoebsc/bscdebug.h"
E 4
#endif
E 10

D 6
#ifdef	VX_DEBUG
long vxintr4 = 0;
long vxdebug = 0;
D 4
#include "../vba/vxdebug.h"
E 4
I 4
#include "../tahoevba/vxdebug.h"
E 6
I 6
D 10
char	bscport[NVX*16];
E 6
E 4
#endif

E 10
D 6
#define RSPquals	1
E 6
I 6
#ifdef VX_DEBUG
long	vxintr4 = 0;
D 9
#define VXERR4	1
#define VXNOBUF	2
E 9
I 9
#define	VXERR4	1
#define	VXNOBUF	2
E 9
long	vxdebug = 0;
D 9
#define VXVCM	1
#define VXVCC	2
#define VXVCX	4
E 9
I 9
#define	VXVCM	1
#define	VXVCC	2
#define	VXVCX	4
E 9
D 11
#include "../tahoesna/snadebug.h"
E 11
#endif
E 6

D 3
struct	vcx	vcx[NVIOCX] ;
struct	tty	vx_tty[NVXPORTS];
extern struct vcmds v_cmds[];
extern long reinit;
E 3
I 3
D 6
struct	vcx vcx[NVIOCX] ;
struct	tty vx_tty[NVXPORTS];
extern	struct vcmds v_cmds[];
extern	long reinit;
E 6
I 6
/*
 * Interrupt type bits passed to vinthandl().
 */
D 9
#define CMDquals 0		/* command completed interrupt */
#define RSPquals 1		/* command response interrupt */
#define UNSquals 2		/* unsolicited interrupt */
E 9
I 9
#define	CMDquals 0		/* command completed interrupt */
#define	RSPquals 1		/* command response interrupt */
#define	UNSquals 2		/* unsolicited interrupt */
E 9
E 6
E 3

I 11
#define	VXUNIT(n)	((n) >> 4)
#define	VXPORT(n)	((n) & 0xf)

E 11
D 6
int	vxstart() ;
int	ttrstrt() ;
D 2
caddr_t vtoph();
E 2
D 3
struct	vxcmd	*vobtain() ;
struct	vxcmd	*nextcmd() ;
E 3
I 3
struct	vxcmd *vobtain() ;
struct	vxcmd *nextcmd() ;
E 6
I 6
struct	tty vx_tty[NVX*16];
I 10
#ifndef lint
int	nvx = NVX*16;
#endif
E 10
int	vxstart(), ttrstrt();
struct	vxcmd *vobtain(), *nextcmd();
E 6
E 3

/*
 * Driver information for auto-configuration stuff.
D 6
 * (not tested and probably should be changed)
E 6
 */
int	vxprobe(), vxattach(), vxrint();
D 6
struct	vba_device *vxinfo[NVIOCX];
E 6
I 6
struct	vba_device *vxinfo[NVX];
E 6
long	vxstd[] = { 0 };
struct	vba_driver vxdriver =
D 2
	{ vxprobe, 0, vxattach, 0, vxstd, "vioc ", vxinfo };
E 2
I 2
D 3
	{ vxprobe, 0, vxattach, 0, vxstd, "vx", vxinfo };
E 3
I 3
    { vxprobe, 0, vxattach, 0, vxstd, "vx", vxinfo };
E 3
E 2

D 3
char vxtype[NVIOCX];	/* 0: viox-x/vioc-b; 1: vioc-bop */
char vxbbno = -1;
char vxbopno[NVIOCX];	/* BOP board no. if indicated by vxtype[] */
extern vbrall();
E 3
I 3
D 6
char	vxtype[NVIOCX];	/* 0: viox-x/vioc-b; 1: vioc-bop */
char	vxbbno = -1;
char	vxbopno[NVIOCX];	/* BOP board no. if indicated by vxtype[] */
int	vxivec[NVIOCX];		/* interrupt vector base */
extern	vbrall();
E 6
I 6
struct	vx_softc {
	u_char	vs_type;	/* 0: viox-x/vioc-b, 1: vioc-bop */
	u_char	vs_bop;		/* bop board # for vioc-bop's */
	u_char	vs_loport;	/* low port nbr */
	u_char	vs_hiport;	/* high port nbr */
	u_short	vs_nbr;		/* viocx number */
	u_short	vs_maxcmd;	/* max number of concurrent cmds */
	u_short	vs_silosiz;	/* silo size */
	short	vs_vers;	/* vioc/pvioc version */
D 8
#define	VXV_OLD	0		/* PVIOCX | VIOCX */
#define	VXV_NEW	1		/* NPVIOCX | NVIOCX */
E 8
I 8
D 9
#define VXV_OLD	0		/* PVIOCX | VIOCX */
#define VXV_NEW	1		/* NPVIOCX | NVIOCX */
E 9
I 9
#define	VXV_OLD	0		/* PVIOCX | VIOCX */
#define	VXV_NEW	1		/* NPVIOCX | NVIOCX */
E 9
E 8
	short	vs_xmtcnt;	/* xmit commands pending */
	short	vs_brkreq;	/* send break requests pending */
D 11
	short	vs_active;	/* active port bit array or flag */
E 11
	short 	vs_state;	/* controller state */
D 8
#define	VXS_READY	0	/* ready for commands */
E 8
I 8
D 9
#define VXS_READY	0	/* ready for commands */
E 8
#define VXS_RESET	1	/* in process of reseting */
E 9
I 9
#define	VXS_READY	0	/* ready for commands */
#define	VXS_RESET	1	/* in process of reseting */
I 11
	u_short	vs_softCAR;	/* soft carrier */
E 11
E 9
	caddr_t vs_mricmd;	/* most recent issued cmd */
	u_int	vs_ivec;	/* interrupt vector base */
	struct	vxcmd *vs_avail;/* next available command buffer */
	struct	vxcmd *vs_build;
	struct	vxcmd vs_lst[NVCXBUFS];
	struct	vcmds vs_cmds;
} vx_softc[NVX];
E 6
E 3

D 3

vxprobe(reg)
E 3
I 3
vxprobe(reg, vi)
E 3
	caddr_t reg;
I 3
	struct vba_device *vi;
E 3
{
D 3
	register int br, cvec;
E 3
I 3
	register int br, cvec;			/* must be r12, r11 */
E 3
D 6
	register struct vblok *vp = (struct vblok *)reg;
E 6
I 6
	register struct vxdevice *vp = (struct vxdevice *)reg;
	register struct vx_softc *vs;
E 6

#ifdef lint
	br = 0; cvec = br; br = cvec;
I 2
	vackint(0); vunsol(0); vcmdrsp(0); vxfreset(0);
E 2
#endif
D 3

E 3
D 2
	if(badaddr(vp, 1))
		return(0);
	vp->v_fault = 0 ;
	vp->v_vioc = V_BSY ;
	vp->v_hdwre = V_RESET ;		/* reset interrupt */

E 2
I 2
	if (badaddr((caddr_t)vp, 1))
		return (0);
	vp->v_fault = 0;
	vp->v_vioc = V_BSY;
	vp->v_hdwre = V_RESET;		/* reset interrupt */
E 2
	DELAY(4000000);
D 2
	return ( vp->v_fault == VREADY);
E 2
I 2
D 6
	if (vp->v_fault != VREADY)
E 6
I 6
	if (vp->v_fault != VXF_READY)
E 6
		return (0);
I 6
	vs = &vx_softc[vi->ui_unit];
E 6
I 3
#ifdef notdef
	/*
	 * Align vioc interrupt vector base to 4 vector
	 * boundary and fitting in 8 bits (is this necessary,
	 * wish we had documentation).
	 */
	if ((vi->ui_hd->vh_lastiv -= 3) > 0xff)
		vi->ui_hd->vh_lastiv = 0xff;
D 6
	vxivec[vi->ui_unit] = vi->ui_hd->vh_lastiv =
	    vi->ui_hd->vh_lastiv &~ 0x3;
E 6
I 6
	vs->vs_ivec = vi->ui_hd->vh_lastiv = vi->ui_hd->vh_lastiv &~ 0x3;
E 6
#else
D 6
	vxivec[vi->ui_unit] = 0x40+vi->ui_unit*4;
E 6
I 6
	vs->vs_ivec = 0x40+vi->ui_unit*4;
E 6
#endif
D 6
	br = 0x18, cvec = vxivec[vi->ui_unit];	/* XXX */
E 3
	return (sizeof (*vp));
E 6
I 6
	br = 0x18, cvec = vs->vs_ivec;	/* XXX */
	return (sizeof (struct vxdevice));
E 6
E 2
}

D 3
vxattach(ui)
	register struct vba_device *ui;
E 3
I 3
vxattach(vi)
	register struct vba_device *vi;
E 3
{
I 2

I 11
	vx_softc[vi->ui_unit].vs_softCAR = vi->ui_flags;
E 11
E 2
D 3
	VIOCBAS[ui->ui_unit] = ui->ui_addr;
D 2
	vxinit(ui->ui_unit,1);
E 2
I 2
	vxinit(ui->ui_unit,(long)1);
E 3
I 3
D 6
	VIOCBAS[vi->ui_unit] = vi->ui_addr;
E 6
D 10
	vxinit(vi->ui_unit, (long)1);
E 10
I 10
	vxinit(vi->ui_unit, 1);
E 10
E 3
E 2
}

/*
 * Open a VX line.
 */
I 2
/*ARGSUSED*/
E 2
vxopen(dev, flag)
I 6
	dev_t dev;
	int flag;
E 6
{
	register struct tty *tp;	/* pointer to tty struct for port */
D 6
	register struct vcx *xp;	/* pointer to VIOC-X info/cmd buffer */
	register d;			/* minor device number */
	register long jj;
E 6
I 6
	register struct vx_softc *vs;
	register struct vba_device *vi;
	int unit, vx, s, error;
E 6

D 6

	d = minor(dev);			/* get minor device number */
	if (d >= NVXPORTS)		/* validate minor device number */
		return ENXIO;		/* set errno to indicate bad port # */
	tp = &vx_tty[d];		/* index the tty structure for port */

	xp = &vcx[d>>4];			/* index VIOC-X info/cmd area */
	d &= 017;

	/* If we did not find a board with the correct port number on
	   it, or the entry for the VIOC-X had no ports on it, inform the
	   caller that the port does not exist. */
	if(!( xp->v_loport <= d && d <= xp->v_hiport )	/* home? */
	 || (xp->v_hiport - xp->v_loport)==0)
		return ENXIO;	/* bad minor device number */
	tp->t_addr = (caddr_t)xp;	/* store address of VIOC-X info */
	tp->t_oproc = vxstart;		/* store address of startup routine */
	tp->t_dev = dev;		/* store major/minor device numbers */
	d = spl8();
	tp->t_state |= TS_WOPEN;	/* mark device as waiting for open */
	if ((tp->t_state&TS_ISOPEN) == 0)	/* is device already open? */
	{				/*  no, open it */
		ttychars(tp);		/* set default control chars */
		if (tp->t_ispeed == 0)	/* if no default speeds set them */
		{
			tp->t_ispeed = SSPEED;	/* default input baud */
			tp->t_ospeed = SSPEED;	/* default output baud */
			tp->t_flags |= (ODDP|EVENP|ECHO); /* default modes */
E 6
I 6
	unit = minor(dev);
D 11
	vx = unit >> 4;
	if (unit >= NVX*16 || (vi = vxinfo[vx])== 0 || vi->ui_alive == 0)
E 11
I 11
	vx = VXUNIT(unit);
	if (vx >= NVX || (vi = vxinfo[vx])== 0 || vi->ui_alive == 0)
E 11
		return (ENXIO);
I 11
	vs = &vx_softc[vx];
E 11
	tp = &vx_tty[unit];
I 11
	unit = VXPORT(unit);
E 11
	if (tp->t_state&TS_XCLUDE && u.u_uid != 0)
		return (EBUSY);
D 11
	vs = &vx_softc[vx];
#ifdef notdef
	if (unit < vs->vs_loport || vs->vs_hiport < unit)	/* ??? */
E 11
I 11
	if (unit < vs->vs_loport || unit > vs->vs_hiport)
E 11
		return (ENXIO);
D 11
#endif
E 11
	tp->t_addr = (caddr_t)vs;
	tp->t_oproc = vxstart;
	tp->t_dev = dev;
	s = spl8();
	tp->t_state |= TS_WOPEN;
	if ((tp->t_state&TS_ISOPEN) == 0) {
		ttychars(tp);
		if (tp->t_ispeed == 0) {
			tp->t_ispeed = SSPEED;
			tp->t_ospeed = SSPEED;
			tp->t_flags |= ODDP|EVENP|ECHO;
E 6
		}
D 6
		vxparam(dev);		/* set parameters for this port */
E 6
I 6
		vxparam(dev);
E 6
	}
D 6
	splx(d);
	/* ? if already open for exclusive use open fails unless caller is 
	     root. */
	if (tp->t_state&TS_XCLUDE && u.u_uid!=0)
		return EBUSY;	/* device is busy, sorry */

	/* wait for data carrier detect to go high */
	d = spl8();
	if( !vcmodem(dev,VMOD_ON) )
		while( (tp->t_state&TS_CARR_ON) == 0 )
D 2
			sleep(&tp->t_canq,TTIPRI);
E 2
I 2
			sleep((caddr_t)&tp->t_canq,TTIPRI);
E 2
	jj= (*linesw[tp->t_line].l_open)(dev,tp); /*let tty.c finish the open */
	splx(d);	/* 1/2/85 : assures open complete */
	return (jj);
E 6
I 6
D 11
	if (!vcmodem(dev, VMOD_ON))
		while ((tp->t_state&TS_CARR_ON) == 0)
D 10
			sleep((caddr_t)&tp->t_canq, TTIPRI);
E 10
I 10
			sleep((caddr_t)&tp->t_rawq, TTIPRI);
E 11
I 11
	vcmodem(dev, VMOD_ON);
	while ((tp->t_state&TS_CARR_ON) == 0)
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
E 11
E 10
	error = (*linesw[tp->t_line].l_open)(dev,tp);
	splx(s);
	return (error);
E 6
}

/*
 * Close a VX line.
 */
I 2
/*ARGSUSED*/
E 2
vxclose(dev, flag)
D 6
dev_t dev;
int  flag;
E 6
I 6
	dev_t dev;
	int flag;
E 6
{
	register struct tty *tp;
D 6
	register d;
E 6
I 6
	int unit, s;
E 6

D 6
	d = minor(dev) & 0377;
	tp = &vx_tty[d];
	d = spl8();
E 6
I 6
	unit = minor(dev);
	tp = &vx_tty[unit];
	s = spl8();
E 6
	(*linesw[tp->t_line].l_close)(tp);
D 6
	if ((tp->t_state&TS_ISOPEN) && (tp->t_state&TS_HUPCLS))
		if( !vcmodem(dev,VMOD_OFF) )
E 6
I 6
D 10
	if ((tp->t_state & (TS_ISOPEN|TS_HUPCLS)) == (TS_ISOPEN|TS_HUPCLS))
E 10
I 10
D 11
	if (tp->t_state & TS_HUPCLS || (tp->t_state & TS_ISOPEN) == 0) {
E 10
		if (!vcmodem(dev, VMOD_OFF))
E 6
			tp->t_state &= ~TS_CARR_ON;
I 10
	}
E 11
I 11
	if (tp->t_state & TS_HUPCLS || (tp->t_state & TS_ISOPEN) == 0)
		vcmodem(dev, VMOD_OFF);
E 11
E 10
	/* wait for the last response */
D 6
	while(tp->t_state & TS_FLUSH)
		sleep( (caddr_t)&tp->t_state, TTOPRI ) ;
	ttyclose(tp);	/* let tty.c finish the close */
	splx(d);
E 6
I 6
	while (tp->t_state&TS_FLUSH)
		sleep((caddr_t)&tp->t_state, TTOPRI);
	ttyclose(tp);
	splx(s);
E 6
}

/*
 * Read from a VX line.
 */
vxread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
D 6
	register struct tty *tp = &vx_tty[minor(dev) & 0377];
	return (*linesw[tp->t_line].l_read)(tp, uio);
E 6
I 6
	struct tty *tp = &vx_tty[minor(dev)];

	return ((*linesw[tp->t_line].l_read)(tp, uio));
E 6
}

/*
 * write on a VX line
 */
vxwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
D 6
	register struct tty *tp = &vx_tty[minor(dev) & 0377];
	return (*linesw[tp->t_line].l_write)(tp, uio);
E 6
I 6
	register struct tty *tp = &vx_tty[minor(dev)];

	return ((*linesw[tp->t_line].l_write)(tp, uio));
E 6
}

/*
 * VIOCX unsolicited interrupt.
 */
D 6
vxrint(n)
register n;				/* mux number */
E 6
I 6
vxrint(vx)
	register vx;
E 6
{
D 6
	register struct tty *tp;
	register struct vcx *xp;
	register short *sp;
	register struct vblok *kp;
	register int i, c;
	short *savsilo;
	struct silo {
		char	data;
		char	port;
	};
E 6
I 6
	register struct tty *tp, *tp0;
	register struct vxdevice *addr;
	register struct vx_softc *vs;
	struct vba_device *vi;
	register int nc, c;
	register struct silo {
		char	data, port;
	} *sp;
	short *osp;
	int overrun = 0;
E 6

D 6
	kp = VBAS(n);
	xp = &vcx[n];
	switch(kp->v_uqual&037) {
E 6
I 6
	vi = vxinfo[vx];
	if (vi == 0 || vi->ui_alive == 0)
		return;
	addr = (struct vxdevice *)vi->ui_addr;
	switch (addr->v_uqual&037) {
E 6
	case 0:
		break;
	case 2:
D 6
		printf(" ERR NBR %x\n",kp->v_ustat);
		vpanic("vc: VC PROC ERR");
		vxstreset(n);
		return(0);
E 6
I 6
D 11
		printf("vx%d: vc proc err, ustat %x\n", addr->v_ustat);
E 11
I 11
		printf("vx%d: vc proc err, ustat %x\n", vx, addr->v_ustat);
E 11
		vxstreset(vx);
D 11
		return (0);
E 11
I 11
		return;
E 11
E 6
	case 3:
D 6
		vcmintr(n);
		return(1);
E 6
I 6
		vcmintr(vx);
D 11
		return (1);
E 11
I 11
		return;
E 11
E 6
	case 4:
D 6
		return(1);
E 6
I 6
D 11
		return (1);
E 11
I 11
		return;
E 11
E 6
	default:
D 6
		printf(" ERR NBR %x\n",kp->v_uqual);
		vpanic("vc: VC UQUAL ERR");
		vxstreset(n);
		return(0);
E 6
I 6
D 11
		printf("vx%d: vc uqual err, uqual %x\n", addr->v_uqual);
E 11
I 11
		printf("vx%d: vc uqual err, uqual %x\n", vx, addr->v_uqual);
E 11
		vxstreset(vx);
D 11
		return (0);
E 11
I 11
		return;
E 11
E 6
	}
D 6
	if(xp->v_vers == V_NEW) {
		register short *aa ;
		aa = (short *)kp->v_usdata;
		sp = (short *)(*aa  + (char *)kp) ;
	} else {
		c = kp->v_usdata[0] << 6;
		sp = (short *)((char *)kp + SILOBAS + c);
E 6
I 6
	vs = &vx_softc[vx];
	if (vs->vs_vers == VXV_NEW)
		sp = (struct silo *)((caddr_t)addr + *(short *)addr->v_usdata);
	else
		sp = (struct silo *)((caddr_t)addr+VX_SILO+(addr->v_usdata[0]<<6));
	nc = *(osp = (short *)sp);
	if (nc == 0)
D 11
		return (1);
E 11
I 11
		return;
E 11
	if (vs->vs_vers == VXV_NEW && nc > vs->vs_silosiz) {
		printf("vx%d: %d exceeds silo size\n", nc);
		nc = vs->vs_silosiz;
E 6
	}
D 2
nextsilo:
E 2
D 6
	i = *(savsilo = sp);
	if (i == 0) return(1);
	if(xp->v_vers == V_NEW)
		if( i > xp->v_silosiz ) {
			printf("vx: %d exceeds silo size\n",i) ;
			i = xp->v_silosiz;
		}
	for(sp++;i > 0;i--,sp++) {
		c = ((struct silo *)sp)->port & 017;
		tp = &vx_tty[c+n*16];
		if(xp->v_loport > c || c > xp->v_hiport)
			continue;	/* port out of bounds */
		if( (tp->t_state & TS_ISOPEN) == 0) {
E 6
I 6
	tp0 = &vx_tty[vx*16];
	sp = (struct silo *)(((short *)sp)+1);
	for (; nc > 0; nc--, sp = (struct silo *)(((short *)sp)+1)) {
		c = sp->port & 017;
		if (vs->vs_loport > c || c > vs->vs_hiport)
			continue;
		tp = tp0 + c;
		if( (tp->t_state&TS_ISOPEN) == 0) {
E 6
			wakeup((caddr_t)&tp->t_rawq);
			continue;
		}
D 6
		c = ((struct silo *)sp)->data;
		switch(((struct silo *)sp)->port&(PERROR|FERROR)) {
		case PERROR:
		case PERROR|FERROR:
			if( (tp->t_flags&(EVENP|ODDP)) == EVENP
			|| (tp->t_flags & (EVENP|ODDP)) == ODDP )
E 6
I 6
		c = sp->data;
		if ((sp->port&VX_RO) == VX_RO && !overrun) {
D 10
			printf("vx%d: receiver overrun\n", vi->ui_unit);
E 10
I 10
			log(LOG_ERR, "vx%d: receiver overrun\n", vi->ui_unit);
E 10
			overrun = 1;
			continue;
		}
		if (sp->port&VX_PE)
			if ((tp->t_flags&(EVENP|ODDP)) == EVENP ||
			    (tp->t_flags&(EVENP|ODDP)) == ODDP)
E 6
				continue;
I 11
		if ((tp->t_flags & (RAW | PASS8)) == 0)
			c &= 0177;
E 11
D 6
			if(!(((struct silo *)sp)->port&FERROR))
				break;
		case FERROR:
			if(tp->t_flags & RAW) c = 0;
			else c = tp->t_intrc;
E 6
I 6
		if (sp->port&VX_FE) {
			/*
			 * At framing error (break) generate
			 * a null (in raw mode, for getty), or a
			 * interrupt (in cooked/cbreak mode).
			 */
			if (tp->t_flags&RAW)
				c = 0;
			else
				c = tp->t_intrc;
E 6
		}
		(*linesw[tp->t_line].l_rint)(c, tp);
	}
D 6
	*savsilo = 0;
	return(1);
E 6
I 6
	*osp = 0;
D 11
	return (1);
E 11
E 6
}

/*
D 6
 * stty/gtty for VX
E 6
I 6
 * Ioctl for VX.
E 6
 */
vxioctl(dev, cmd, data, flag)
D 6
int	dev;			/* major, minor device numbers */
int	cmd;			/* command */
caddr_t	data;
int	flag;
E 6
I 6
	dev_t dev;
	caddr_t	data;
E 6
{
D 6
	register struct tty	*tp;
	register error;
E 6
I 6
	register struct tty *tp;
	int error;
E 6

D 6
	tp = &vx_tty[minor(dev) & 0377];
E 6
I 6
	tp = &vx_tty[minor(dev)];
E 6
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
	if (error == 0)
D 6
		return error;
	if((error = ttioctl(tp, cmd, data, flag)) >= 0)
	{
		if (cmd==TIOCSETP||cmd==TIOCSETN)
E 6
I 6
		return (error);
	error = ttioctl(tp, cmd, data, flag);
	if (error >= 0) {
D 10
		if (cmd == TIOCSETP || cmd == TIOCSETN)
E 10
I 10
		if (cmd == TIOCSETP || cmd == TIOCSETN || cmd == TIOCLBIS ||
		    cmd == TIOCLBIC || cmd == TIOCLSET)
E 10
E 6
			vxparam(dev);
D 6
		return error;
	} else
		return ENOTTY;
E 6
I 6
		return (error);
	}
	return (ENOTTY);
E 6
}

D 6

E 6
vxparam(dev)
D 6
dev_t	dev;
E 6
I 6
	dev_t dev;
E 6
{
I 6

E 6
	vxcparam(dev, 1);
}

/*
 * Set parameters from open or stty into the VX hardware
 * registers.
 */
vxcparam(dev, wait)
D 6
dev_t	dev;			/* major, minor device numbers */
int wait;			/* nonzero if we should wait for finish */
E 6
I 6
	dev_t dev;
	int wait;
E 6
{
D 6
	register struct tty	*tp;
	register struct vcx	*xp;
	register struct vxcmd	*cp;
	register s;
E 6
I 6
	register struct tty *tp;
	register struct vx_softc *vs;
	register struct vxcmd *cp;
D 8
	int s;
E 8
I 8
	int s, unit = minor(dev);
E 8
E 6

D 6
	tp = &vx_tty[minor(dev)];	/* pointer to tty structure for port */
	xp = (struct vcx *)tp->t_addr;	/* pointer to VIOCX info/cmd buffer */
	cp = vobtain(xp);
E 6
I 6
D 8
	tp = &vx_tty[minor(dev)];
E 8
I 8
	tp = &vx_tty[unit];
I 11
	if ((tp->t_ispeed)==0) {
		tp->t_state |= TS_HUPCLS;
		vcmodem(dev, VMOD_OFF);
		return;
	}
E 11
E 8
	vs = (struct vx_softc *)tp->t_addr;
	cp = vobtain(vs);
E 6
	s = spl8();
D 6
	cp->cmd = LPARAX;		/* set command to "load parameters" */
E 6
I 6
D 8
	cp->cmd = VXC_LPARAX;		/* set command to "load parameters" */
E 6
	cp->par[1] = minor(dev)&017;	/* port number */
D 6

	cp->par[2] = (tp->t_flags&RAW)? 0 : tp->t_startc;	/* XON char */
	cp->par[3] = (tp->t_flags&RAW)? 0 : tp->t_stopc;	/* XOFF char */

	if(tp->t_flags&(RAW|LITOUT) ||
	  (tp->t_flags&(EVENP|ODDP)) == (EVENP|ODDP)) {
E 6
I 6
	cp->par[2] = (tp->t_flags&RAW) ? 0 : tp->t_startc;	/* XON char */
	cp->par[3] = (tp->t_flags&RAW) ? 0 : tp->t_stopc;	/* XOFF char */
E 8
I 8
	/*
	 * Construct ``load parameters'' command block
	 * to setup baud rates, xon-xoff chars, parity,
	 * and stop bits for the specified port.
	 */
	cp->cmd = VXC_LPARAX;
D 11
	cp->par[1] = unit & 017;	/* port number */
E 11
I 11
	cp->par[1] = VXPORT(unit);
E 11
	cp->par[2] = (tp->t_flags&RAW) ? 0 : tp->t_startc;
	cp->par[3] = (tp->t_flags&RAW) ? 0 : tp->t_stopc;
I 11
#ifdef notnow
E 11
E 8
D 10
	if (tp->t_flags&(RAW|LITOUT) ||
	    (tp->t_flags&(EVENP|ODDP)) == (EVENP|ODDP)) {
E 10
I 10
	if (tp->t_flags & (RAW|LITOUT|PASS8)) {
E 10
E 6
D 11
		cp->par[4] = 0xc0;	/* 8 bits of data */
		cp->par[7] = 0;		/* no parity */
E 11
I 11
#endif
		cp->par[4] = BITS8;		/* 8 bits of data */
		cp->par[7] = VNOPARITY;		/* no parity */
#ifdef notnow
E 11
	} else {
D 11
		cp->par[4] = 0x40;	/* 7 bits of data */
E 11
I 11
		cp->par[4] = BITS7;		/* 7 bits of data */
E 11
D 6
		if((tp->t_flags&(EVENP|ODDP)) == ODDP)
E 6
I 6
		if ((tp->t_flags&(EVENP|ODDP)) == ODDP)
E 6
D 11
			cp->par[7] = 1;		/* odd parity */
E 11
I 11
			cp->par[7] = VODDP;	/* odd parity */
E 11
D 8
		else if((tp->t_flags&(EVENP|ODDP)) == EVENP)
E 8
I 8
D 10
		else if ((tp->t_flags&(EVENP|ODDP)) == EVENP)
E 8
			cp->par[7] = 3;		/* even parity */
E 10
		else
D 10
			cp->par[7] = 0;		/* no parity */
E 10
I 10
D 11
			cp->par[7] = 3;		/* even parity */
E 11
I 11
			cp->par[7] = VEVENP;	/* even parity */
E 11
E 10
	}
D 8
	cp->par[5] = 0x4;			/* 1 stop bit */
E 8
I 8
D 11
	cp->par[5] = 0x4;			/* 1 stop bit - XXX */
E 8
	cp->par[6] = tp->t_ospeed;
D 6

D 2
	if (vcmd(xp->v_nbr, &cp->cmd) && wait)
		sleep(cp,TTIPRI);
E 2
I 2
	if (vcmd(xp->v_nbr, (caddr_t)&cp->cmd) && wait)
E 6
I 6
	if (vcmd(vs->vs_nbr, (caddr_t)&cp->cmd) && wait)
E 11
I 11
#endif
	if (tp->t_ospeed == B110)
		cp->par[5] = VSTOP2;		/* 2 stop bits */
	else
		cp->par[5] = VSTOP1;		/* 1 stop bit */
	if (tp->t_ospeed == EXTA || tp->t_ospeed == EXTB)
		cp->par[6] = V19200;
	else
		cp->par[6] = tp->t_ospeed;
	if (vcmd((int)vs->vs_nbr, (caddr_t)&cp->cmd) && wait)
E 11
E 6
		sleep((caddr_t)cp,TTIPRI);
E 2
	splx(s);
}

/*
 * VIOCX command response interrupt.
 * For transmission, restart output to any active port.
 * For all other commands, just clean up.
 */
D 6
vxxint(n,cp)
register int n;			/* VIOC number */
register struct vxcmd	*cp;	/* command structure */
E 6
I 6
vxxint(vx, cp)
	register int vx;
	register struct vxcmd *cp;
E 6
{
D 6
	register struct	vxmit	*vp, *pvp;
	register struct	tty	*tp;
	register struct	vcx	*xp;
	register struct tty	*hp;
E 6
I 6
D 8
	register struct	vxmit *vp, *pvp;
	register struct	tty *tp, *tp0;
	register struct	vx_softc *vs;
E 8
I 8
D 11
	register struct vxmit *vp, *pvp;
E 11
I 11
	register struct vxmit *vp;
E 11
	register struct tty *tp, *tp0;
	register struct vx_softc *vs;
E 8
D 11
	register struct tty *hp;
E 11
E 6

D 6
	xp = &vcx[n];
	cp = (struct vxcmd *)( (long *)cp - 1);
E 6
I 6
	vs = &vx_softc[vx];
	cp = (struct vxcmd *)((long *)cp-1);
E 6
D 10
#if NVBSC > 0
D 6
	switch(cp->cmd) {
	case MDMCTL1: case HUNTMD1: case LPARAX1:
		vrelease(xp, cp);
		wakeup(cp);
E 6
I 6
	if (cp->cmd == VXC_MDMCTL1 || cp->cmd == VXC_HUNTMD1 ||
	    cp->cmd == VXC_LPARAX1) {
		vrelease(vs, cp);
		wakeup((caddr_t)cp);
E 6
		return;
	}
#endif
E 10
I 10

E 10
D 6
	switch(cp->cmd&0xff00) {
	case LIDENT:	/* initialization complete */
		if (xp->v_state & V_RESETTING) {
			vxfnreset(n,cp);
			vinthandl(n,((V_BSY | RSPquals) << 8) | V_INTR);
E 6
I 6
	switch (cp->cmd&0xff00) {

	case VXC_LIDENT:	/* initialization complete */
		if (vs->vs_state == VXS_RESET) {
			vxfnreset(vx, cp);
			vinthandl(vx, ((V_BSY|RSPquals) << 8)|V_INTR);
E 6
		}
		cp->cmd++;
		return;
D 6
	case XMITDTA: case XMITIMM:
E 6
I 6

	case VXC_XMITDTA:
	case VXC_XMITIMM:
E 6
		break;
D 6
	case LPARAX:
E 6
I 6

	case VXC_LPARAX:
E 6
D 2
		wakeup(cp);
E 2
I 2
		wakeup((caddr_t)cp);
E 2
D 6
	default:	/* MDMCTL or FDTATOX */
		vrelease(xp, cp);
		if (xp->v_state & V_RESETTING) {
			vinthandl(n,((V_BSY | RSPquals) << 8) | V_INTR);
		}
E 6
I 6
		/* fall thru... */
	default:	/* VXC_MDMCTL or VXC_FDTATOX */
		vrelease(vs, cp);
		if (vs->vs_state == VXS_RESET)
			vinthandl(vx, ((V_BSY|RSPquals) << 8)|V_INTR);
E 6
		return;
	}
D 6
	for(vp = (struct vxmit *)(cp->par + (cp->cmd & 07)*sizvxmit);
	    vp >= (struct vxmit *)cp->par;
	    vp = (struct vxmit *) ((char *)vp - sizvxmit) )
	{
		tp = &vx_tty[(vp->line & 017)+n*16];
/* cjk buffer bug */
E 6
I 6
	tp0 = &vx_tty[vx*16];
	vp = (struct vxmit *)(cp->par + (cp->cmd & 07)*sizeof (struct vxmit));
	for (; vp >= (struct vxmit *)cp->par; vp--) {
		tp = tp0 + (vp->line & 017);
E 6
D 10
#if NVBSC > 0
D 6
					/* bsc change */
E 6
		if (tp->t_line == LDISP) {
			vrelease(xp, cp);
D 6
			bsctxd((vp->line & 017));
			return ;
E 6
I 6
			bsctxd(vp->line & 017);
			return;
E 6
		}
D 6
					/* End of bsc change */
E 6
#endif
E 10
D 6
/* cjk */
E 6
D 11
		pvp = vp;
E 11
		tp->t_state &= ~TS_BUSY;
D 6
		if(tp->t_state & TS_FLUSH) {
E 6
I 6
		if (tp->t_state & TS_FLUSH) {
E 6
			tp->t_state &= ~TS_FLUSH;
D 6
			wakeup( (caddr_t)&tp->t_state ) ;
		}
		else
E 6
I 6
			wakeup((caddr_t)&tp->t_state);
		} else
E 6
		 	ndflush(&tp->t_outq, vp->bcount+1);
	}
D 6
	xp->v_xmtcnt--;
	vrelease(xp,cp);
	if(xp->v_vers == V_NEW) {
E 6
I 6
D 11
	vs->vs_xmtcnt--;
E 11
	vrelease(vs, cp);
D 11
	if (vs->vs_vers == VXV_NEW) {
E 6
		vp = pvp;
D 6
		xp->v_actport[(vp->line & 017) - xp->v_loport] |= 1 ;
		if(vxstart(tp) && (cp = nextcmd(xp)) != NULL)
		{
			xp->v_xmtcnt++;
D 2
			vcmd(n, &cp->cmd);
E 2
I 2
			vcmd(n, (caddr_t)&cp->cmd);
E 2
			return ;
E 6
I 6
		vs->vs_active |= 1 << ((vp->line & 017) - vs->vs_loport);
		if (vxstart(tp) && (cp = nextcmd(vs)) != NULL) {
			vs->vs_xmtcnt++;
			vcmd(vx, (caddr_t)&cp->cmd);
			return;
E 6
		}
D 6
		xp->v_actport[(vp->line & 017) - xp->v_loport] = 0 ;
		return ;
	}
	xp->v_actflg = 1;
	hp = &vx_tty[xp->v_hiport+n*16];
	for(tp = &vx_tty[xp->v_loport+n*16];tp <= hp;tp++)
		if(vxstart(tp) && (cp = nextcmd(xp)) != NULL)
		{
			xp->v_xmtcnt++;
D 2
			vcmd(n, &cp->cmd);
E 2
I 2
			vcmd(n, (caddr_t)&cp->cmd);
E 6
I 6
		vs->vs_active &= ~(1 << ((vp->line & 017) - vs->vs_loport));
	} else {
D 8
		vs->vs_active = 1;
E 8
I 8
		vs->vs_active = -1;
E 11
I 11
	if (vs->vs_vers == VXV_NEW)
D 12
		vxstart(tp);
E 12
I 12
		(*linesw[tp->t_line].l_start)(tp);
E 12
	else {
E 11
E 8
		tp0 = &vx_tty[vx*16 + vs->vs_hiport];
		for(tp = &vx_tty[vx*16 + vs->vs_loport]; tp <= tp0; tp++)
D 11
			if (vxstart(tp) && (cp = nextcmd(vs)) != NULL) {
				vs->vs_xmtcnt++;
				vcmd(vx, (caddr_t)&cp->cmd);
			}
E 11
I 11
D 12
			vxstart(tp);
E 12
I 12
			(*linesw[tp->t_line].l_start)(tp);
E 12
E 11
		if ((cp = nextcmd(vs)) != NULL) {	/* command to send? */
			vs->vs_xmtcnt++;
D 11
			vcmd(vx, (caddr_t)&cp->cmd);
E 11
I 11
			(void) vcmd(vx, (caddr_t)&cp->cmd);
E 11
E 6
E 2
		}
D 6
	if( (cp = nextcmd(xp)) != NULL )		/* command to send ? */
	{
		xp->v_xmtcnt++;
D 2
		vcmd(n,&cp->cmd);
E 2
I 2
		vcmd(n, (caddr_t)&cp->cmd);
E 6
I 6
D 11
		vs->vs_active = 0;
E 11
E 6
E 2
	}
I 11
	vs->vs_xmtcnt--;
E 11
D 6
	xp->v_actflg = 0;
E 6
}

/*
 * Force out partial XMIT command after timeout
 */
D 6
vxforce(xp)
register struct vcx	*xp;
E 6
I 6
vxforce(vs)
	register struct vx_softc *vs;
E 6
{
D 6
	register struct vxcmd	*cp;
	register int s;
E 6
I 6
	register struct vxcmd *cp;
	int s;
E 6

	s = spl8();
D 6
	if((cp = nextcmd(xp)) != NULL) {
		xp->v_xmtcnt++;
D 2
		vcmd(xp->v_nbr, &cp->cmd);
E 2
I 2
		vcmd(xp->v_nbr, (caddr_t)&cp->cmd);
E 6
I 6
	if ((cp = nextcmd(vs)) != NULL) {
		vs->vs_xmtcnt++;
D 11
		vcmd(vs->vs_nbr, (caddr_t)&cp->cmd);
E 11
I 11
		(void) vcmd((int)vs->vs_nbr, (caddr_t)&cp->cmd);
E 11
E 6
E 2
	}
	splx(s);
}

/*
 * Start (restart) transmission on the given VX line.
 */
vxstart(tp)
D 6
register struct tty *tp;
E 6
I 6
	register struct tty *tp;
E 6
{
D 2
	register short nch;
E 2
I 2
	register short n;
E 2
D 6
	register struct	vcx	*xp;
E 6
I 6
D 8
	register struct	vx_softc *vs;
E 6
	register char *outb;
E 8
I 8
	register struct vx_softc *vs;
E 8
D 10
	register full = 0;
E 10
I 10
D 11
	register full;
E 11
E 10
D 8
	int k, s, port;
E 8
I 8
	int s, port;
E 8

	s = spl8();
	port = minor(tp->t_dev) & 017;
D 6
	xp = (struct vcx *)tp->t_addr;
	if (!(tp->t_state&(TS_TIMEOUT|TS_BUSY|TS_TTSTOP))) {
		if (tp->t_outq.c_cc<=TTLOWAT(tp)) {
E 6
I 6
	vs = (struct vx_softc *)tp->t_addr;
	if ((tp->t_state&(TS_TIMEOUT|TS_BUSY|TS_TTSTOP)) == 0) {
		if (tp->t_outq.c_cc <= TTLOWAT(tp)) {
E 6
			if (tp->t_state&TS_ASLEEP) {
				tp->t_state &= ~TS_ASLEEP;
				wakeup((caddr_t)&tp->t_outq);
			}
			if (tp->t_wsel) {
				selwakeup(tp->t_wsel, tp->t_state & TS_WCOLL);
				tp->t_wsel = 0;
				tp->t_state &= ~TS_WCOLL;
			}
		}
D 6
		if(tp->t_outq.c_cc == 0) {
E 6
I 6
		if (tp->t_outq.c_cc == 0) {
E 6
			splx(s);
D 6
			return(0);
E 6
I 6
D 11
			return (0);
E 11
I 11
			return;
E 11
E 6
		}
D 5
#ifdef VXPERF
	scope_out(3);
#endif VXPERF
E 5
I 5
		scope_out(3);
E 5
D 6
		if(!(tp->t_flags&(RAW|LITOUT)))  
E 6
I 6
D 10
		if ((tp->t_flags&(RAW|LITOUT)) == 0)  
E 10
I 10
		if (tp->t_flags & (RAW|LITOUT))
D 11
			full = 0;
		else
E 10
E 6
			full = 0200;
D 2
		if((nch = ndqb(&tp->t_outq, full)) == 0)   {
E 2
I 2
D 6
		if((n = ndqb(&tp->t_outq, full)) == 0)   {
E 2
			if(full) {
E 6
I 6
		if ((n = ndqb(&tp->t_outq, full)) == 0) {
			if (full) {
E 11
I 11
			n = ndqb(&tp->t_outq, 0);
		else {
			n = ndqb(&tp->t_outq, 0200);
			if (n == 0) {
E 11
E 6
D 2
				nch = getc(&tp->t_outq);
				timeout(ttrstrt, (caddr_t)tp, (nch&0177) +6);
E 2
I 2
				n = getc(&tp->t_outq);
D 6
				timeout(ttrstrt, (caddr_t)tp, (n&0177) +6);
E 6
I 6
				timeout(ttrstrt, (caddr_t)tp, (n&0177)+6);
E 6
E 2
				tp->t_state |= TS_TIMEOUT;
D 11
				full = 0;
E 11
I 11
				n = 0;
E 11
			}
D 11
		} else {
D 8
			outb = (char *)tp->t_outq.c_cf;
E 8
I 8
			char *cp = (char *)tp->t_outq.c_cf;

E 11
I 11
		}
		if (n) {
E 11
E 8
			tp->t_state |= TS_BUSY;
D 6
			if(xp->v_vers == V_NEW)
				k = xp->v_actport[port - xp->v_loport] ;
E 6
I 6
D 8
			if (vs->vs_vers == VXV_NEW)
				k = vs->vs_active & (1 << (port-vs->vs_loport));
E 6
			else
D 6
				k = xp->v_actflg ;

D 2
			full = vsetq(xp, port, outb, nch);
E 2
I 2
			full = vsetq(xp, port, outb, n);
E 2

			if( (k&1) == 0 ) {	/* not called from vxxint */
				if(full || xp->v_xmtcnt == 0) {
					outb = (char *)(&nextcmd(xp)->cmd);
					xp->v_xmtcnt++;
					vcmd(xp->v_nbr, outb );
E 6
I 6
				k = vs->vs_active;
			full = vsetq(vs, port, outb, n);
			if ((k&1) == 0) {	/* not called from vxxint */
E 8
I 8
D 11
			full = vsetq(vs, port, cp, n);
			/*
			 * If the port is not currently active, try to
			 * send the data.  We send it immediately if the
			 * command buffer is full, or if we've nothing
			 * currently outstanding.  If we don't send it,
			 * set a timeout to force the data to be sent soon.
			 */
			if ((vs->vs_active & (1 << (port-vs->vs_loport))) == 0)
E 8
				if (full || vs->vs_xmtcnt == 0) {
D 8
					outb = (char *)(&nextcmd(vs)->cmd);
E 8
I 8
					cp = (char *)&nextcmd(vs)->cmd;
E 8
					vs->vs_xmtcnt++;
D 8
					vcmd(vs->vs_nbr, outb);
E 8
I 8
					vcmd(vs->vs_nbr, cp);
E 8
E 6
				} else
D 2
					timeout(vxforce,xp,3);
E 2
I 2
D 6
					timeout(vxforce,(caddr_t)xp,3);
E 6
I 6
					timeout(vxforce, (caddr_t)vs, 3);
E 11
I 11
			vsetq(vs, port, (char *)tp->t_outq.c_cf, n);
E 11
E 6
E 2
D 8
			}
E 8
		}
	}
	splx(s);
D 6
	return(full);	/* indicate if max commands or not */
E 6
I 6
D 11
	return (full);	/* indicate if max commands or not */
E 11
E 6
}

/*
 * Stop output on a line.
 */
vxstop(tp)
D 6
register struct tty *tp;
E 6
I 6
	register struct tty *tp;
E 6
{
D 6
	register  s;
E 6
I 6
	int s;
E 6

	s = spl8();
D 6
	if (tp->t_state & TS_BUSY) {
		if ((tp->t_state&TS_TTSTOP)==0) {
E 6
I 6
	if (tp->t_state&TS_BUSY)
		if ((tp->t_state&TS_TTSTOP) == 0)
E 6
			tp->t_state |= TS_FLUSH;
D 6
		}
	}
E 6
	splx(s);
}

I 6
static	int vxbbno = -1;
E 6
/*
 * VIOCX Initialization.  Makes free lists of command buffers.
 * Resets all viocx's.  Issues a LIDENT command to each
D 8
 * viocx which establishes interrupt vectors and logical
 * port numbers
E 8
I 8
 * viocx to establish interrupt vectors and logical port numbers.
E 8
 */
D 6
vxinit(i,wait) 
register int	i;
long wait;
E 6
I 6
vxinit(vx, wait) 
	register int vx;
	int wait;
E 6
{
D 6
	register struct	vcx	*xp;	/* ptr to VIOC-X info/cmd buffer */
	register struct	vblok	*kp;	/* pointer to VIOC-X control block */
	register struct	vxcmd	*cp;	/* pointer to a command buffer */
	register char	*resp;		/* pointer to response buffer */
	register int	j;
E 6
I 6
D 8
	register struct	vx_softc *vs;
	register struct	vxdevice *addr;
	register struct	vxcmd *cp;
E 8
I 8
	register struct vx_softc *vs;
	register struct vxdevice *addr;
	register struct vxcmd *cp;
E 8
	register char *resp;
	register int j;
E 6
D 2
	register struct	vcmds	*cpp;
E 2
D 11
	char type;
E 11
I 11
	char type, *typestring;
E 11
I 2
D 6
#if NVBSC > 0
E 2
	register struct	bsc	*bp;	/* bsc change */
	extern	 struct	bsc	bsc[];
I 2
#endif
E 6
E 2

I 6
	vs = &vx_softc[vx];
D 8
	vs->vs_type = 0;		/* viox-x by default */
	addr = (struct vxdevice *)(((struct vba_device *)vxinfo[vx])->ui_addr);
E 8
I 8
	vs->vs_type = 0;		/* vioc-x by default */
	addr = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
E 8
	type = addr->v_ident;
	vs->vs_vers = (type&VXT_NEW) ? VXV_NEW : VXV_OLD;
	if (vs->vs_vers == VXV_NEW)
		vs->vs_silosiz = addr->v_maxsilo;
	switch (type) {
E 6

D 6
	kp = VBAS(i);		/* get base adr of cntl blok for VIOC */
E 6
I 6
	case VXT_VIOCX:
	case VXT_VIOCX|VXT_NEW:
D 11
		/* set dcd for printer ports */
D 8
		for (j = 0;j < 16;j++)
E 8
I 8
		for (j = 0; j < 16;j++)
E 8
			if (addr->v_portyp[j] == 4)
E 11
I 11
		typestring = "VIOC-X";
		/* set soft carrier for printer ports */
		for (j = 0; j < 16; j++)
			if (addr->v_portyp[j] == VXT_PARALLEL) {
				vs->vs_softCAR |= 1 << j;
E 11
				addr->v_dcd |= 1 << j;
I 11
			}
E 11
		break;
E 6

D 6
	xp = &vcx[i];		/* index info/command buffers */
D 2
	cpp = &v_cmds[i];
E 2
	type = kp->v_ident;
	vxtype[i] =  0;		/* Type is Viox-x */
	switch(type) {
	case VIOCX:
		{
		xp->v_vers = V_OLD ;
		/* set DCD for printer ports */
		for(j = 0;j < 16;j++)
			if (kp->v_portyp[j] == 4 )
				kp->v_dcd |= 1 << j ;
		}
		break ;
	case NWVIOCX:
		{
		xp->v_vers = V_NEW ;
		xp->v_silosiz = kp->v_maxsilo ;
		/* set DCD for printer ports */
		for(j = 0;j < 16;j++)
			if (kp->v_portyp[j] == 4 )
				kp->v_dcd |= 1 << j ;
		}
		break ;
	case PVIOCX:
		xp->v_vers = V_OLD ;
		break ;
	case NPVIOCX:
		xp->v_vers = V_NEW ;
		xp->v_silosiz = kp->v_maxsilo ;
		break ;
E 6
I 6
	case VXT_PVIOCX:
	case VXT_PVIOCX|VXT_NEW:
I 11
		typestring = "VIOC-X (old connector panel)";
E 11
		break;
E 6
D 10
#if NVBSC > 0
D 6
	case VIOCB:	/* old f/w, Bisync board */
		printf("%X: %x%x OLD VIOC-B, ",
					(long)kp, (int)kp->v_ident,
					(int)kp->v_fault);
		xp->v_vers = V_OLD ;
		/* save device specific info */
		for(bp = &bsc[0]; bp <= &bsc[NBSC]; bp++)
			bp->b_devregs = (caddr_t)xp ;
		printf("%d BSC Ports initialized.\n",NBSC);
		break ;
E 6
I 6
	case VX_VIOCB:			/* old f/w bisync */
	case VX_VIOCB|VXT_NEW: {	/* new f/w bisync */
D 8
		register struct	bsc *bp;
E 8
I 8
		register struct bsc *bp;
E 8
		extern struct bsc bsc[];
E 6

D 6
	case NWVIOCB:	/* new f/w, Bisync board */
		printf("%X: %x%x 16K VIOC-B, ",
					(long)kp, (int)kp->v_ident,
					(int)kp->v_fault);
		xp->v_vers = V_NEW ;
		xp->v_silosiz = kp->v_maxsilo ;
		/* save device specific info */
		for(bp = &bsc[0]; bp <= &bsc[NBSC]; bp++)
			bp->b_devregs = (caddr_t)xp ;
		printf("%d BSC Ports initialized.\n",NBSC);
		if(CBSIZE > kp->v_maxxmt)
			printf("vxinit: Warning CBSIZE > maxxmt\n") ;
		break ;
E 6
I 6
		printf("%X: %x%x %s VIOC-B, ", (long)addr, (int)addr->v_ident,
		    (int)addr->v_fault, vs->vs_vers == VXV_OLD ? "old" : "16k");
		for (bp = &bsc[0]; bp <= &bsc[NBSC]; bp++)
			bp->b_devregs = (caddr_t)vs;
		printf("%d BSC Ports initialized.\n", NBSC);
		break;
		if (vs->vs_vers == VXV_NEW && CBSIZE > addr->v_maxxmt)
			printf("vxinit: Warning CBSIZE > maxxmt\n");
		break;
E 6
#endif
E 10
D 6
	case VBOPID:		/* VIOC-BOP */
		vxbbno++;
		vxtype[i] = 1;
		vxbopno[i] = vxbbno;
		printf("VIOC-BOP no. %d at %lx\n",vxbopno[i],VIOCBAS[i]);
	default:
		return ;	/* Not a viocx type */
	}
	xp->v_nbr = -1;		/* no number for it yet */
	xp->v_maxcmd = xp->v_vers == V_NEW ? 24 : 4;
E 6
I 6
	case VXT_VIOCBOP:		/* VIOC-BOP */
		vs->vs_type = 1;
		vs->vs_bop = ++vxbbno;
		printf("VIOC-BOP no. %d at %x\n", vs->vs_bop, addr);
E 6

D 6
	for(j=0; j<NVCXBUFS; j++)	/* init all cmd buffers */
	{
		cp = &xp->vx_lst[j];	/* index a buffer */
		cp->c_fwd = &xp->vx_lst[j+1];	/* point to next buf */
E 6
I 6
D 8
	default:		/* unknown viocx type */
E 8
I 8
	default:
E 8
		printf("vx%d: unknown type %x\n", vx, type);
I 11
		vxinfo[vx]->ui_alive = 0;
E 11
		return;
E 6
	}
D 6
	xp->vx_avail = &xp->vx_lst[0];	/* set idx to 1st free buf */
E 6
I 6
	vs->vs_nbr = -1;
D 8
	vs->vs_maxcmd = vs->vs_vers == VXV_NEW ? 24 : 4;
	/* init all cmd buffers */
E 8
I 8
	vs->vs_maxcmd = (vs->vs_vers == VXV_NEW) ? 24 : 4;
	/*
	 * Initialize all cmd buffers by linking them
	 * into a free list.
	 */
E 8
	for (j = 0; j < NVCXBUFS; j++) {
D 8
		cp = &vs->vs_lst[j];	/* index a buffer */
		cp->c_fwd = &vs->vs_lst[j+1];	/* point to next buf */
E 8
I 8
		cp = &vs->vs_lst[j];
		cp->c_fwd = &vs->vs_lst[j+1];
E 8
	}
	vs->vs_avail = &vs->vs_lst[0];	/* set idx to 1st free buf */
E 6
	cp->c_fwd = (struct vxcmd *)0;	/* mark last buf in free list */

D 6
	cp = vobtain(xp);	/* grap the control block */
	cp->cmd = LIDENT;	/* set command type */
D 3
	cp->par[0] = i * 4 + VCVECT; 	/* ack vector */
	cp->par[1] = cp->par[0] + 1;	/* cmd resp vector */
	cp->par[3] = cp->par[0] + 2;	/* unsol intr vector */
E 3
I 3
	cp->par[0] = vxivec[i]; 	/* ack vector */
E 6
I 6
D 8
	cp = vobtain(vs);		/* grab the control block */
	cp->cmd = VXC_LIDENT;		/* set command type */
E 8
I 8
	/*
	 * Establish the interrupt vectors and define the port numbers.
	 */
	cp = vobtain(vs);
	cp->cmd = VXC_LIDENT;
E 8
	cp->par[0] = vs->vs_ivec; 	/* ack vector */
E 6
	cp->par[1] = cp->par[0]+1;	/* cmd resp vector */
	cp->par[3] = cp->par[0]+2;	/* unsol intr vector */
E 3
D 6
	cp->par[4] = 15;	/* max ports, no longer used */
	cp->par[5] = 0;		/* set 1st port number */
D 2
	vcmd(i, &cp->cmd);	/* initialize the VIOC-X */
E 2
I 2
	vcmd(i, (caddr_t)&cp->cmd);	/* initialize the VIOC-X */
E 2

	if (!wait) return;
D 3
	while(cp->cmd == LIDENT);    /* wait for command completion */
E 3
I 3
	for (j = 0; cp->cmd == LIDENT && j < 4000000; j++)
E 6
I 6
	cp->par[4] = 15;		/* max ports, no longer used */
	cp->par[5] = 0;			/* set 1st port number */
D 8
	vcmd(vx, (caddr_t)&cp->cmd);	/* initialize the VIOC-X */
E 8
I 8
D 11
	vcmd(vx, (caddr_t)&cp->cmd);
E 11
I 11
	(void) vcmd(vx, (caddr_t)&cp->cmd);
E 11
E 8
	if (!wait)
		return;
	for (j = 0; cp->cmd == VXC_LIDENT && j < 4000000; j++)
E 6
		;
	if (j >= 4000000)
D 6
		printf("vx%d: didn't respond to LIDENT\n", i); 
E 6
I 6
		printf("vx%d: didn't respond to LIDENT\n", vx); 
E 6
E 3

 	/* calculate address of response buffer */
D 6
 	resp = (char *)kp;
 	resp += kp->v_rspoff & 0x3FFF;
 
	if(resp[0] != 0 && (resp[0]&0177) != 3)	/* did init work? */
	{
		vrelease(xp,cp);	/* init failed */
		return;			/* try next VIOC-X */
E 6
I 6
 	resp = (char *)addr + (addr->v_rspoff&0x3fff);
D 8
	if (resp[0] != 0 && (resp[0]&0177) != 3) {	/* did init work? */
		vrelease(vs, cp);
E 8
I 8
	if (resp[0] != 0 && (resp[0]&0177) != 3) {
		vrelease(vs, cp);	/* init failed */
E 8
		return;
E 6
	}
D 6

	xp->v_loport = cp->par[5];	/* save low port number */
	xp->v_hiport = cp->par[7];/* VIOC knows high port numbr */
	vrelease(xp,cp);	/* done with this control block */
	xp->v_nbr = i;		/* assign VIOC-X board number */
E 6
I 6
	vs->vs_loport = cp->par[5];
	vs->vs_hiport = cp->par[7];
I 11
	printf("vx%d: %s%s, ports %d-%d\n", vx,
	    (vs->vs_vers == VXV_NEW) ? "" : "old ", typestring,
	    vs->vs_loport, vs->vs_hiport);
E 11
	vrelease(vs, cp);
D 8
	vs->vs_nbr = vx;		/* assign VIOC-X board number */
E 8
I 8
	vs->vs_nbr = vx;		/* assign board number */
E 8
E 6
}

/*
 * Obtain a command buffer
 */
D 6
struct	vxcmd *
vobtain(xp)
register struct	vcx	*xp;
E 6
I 6
struct vxcmd *
vobtain(vs)
D 8
	register struct	vx_softc *vs;
E 8
I 8
	register struct vx_softc *vs;
E 8
E 6
{
I 6
D 8
	register struct	vxcmd *p;
E 8
I 8
	register struct vxcmd *p;
E 8
	int s;
E 6

D 6
	register struct	vxcmd	*p;
	register s;

E 6
	s = spl8();
D 6
	p = xp->vx_avail;
	if(p == (struct vxcmd *)0) {
E 6
I 6
	p = vs->vs_avail;
	if (p == (struct vxcmd *)0) {
E 6
#ifdef VX_DEBUG
D 6
		if (vxintr4 & VXNOBUF) vxintr4 &= ~VXNOBUF;
E 6
I 6
		if (vxintr4&VXNOBUF)
			vxintr4 &= ~VXNOBUF;
E 6
#endif
D 6
		vpanic("vx: no buffs");
		vxstreset(xp - vcx);
E 6
I 6
		printf("vx%d: no buffers\n", vs - vx_softc);
		vxstreset(vs - vx_softc);
E 6
		splx(s);
D 6
		return(vobtain(xp));
E 6
I 6
		return (vobtain(vs));
E 6
	}
D 6
	xp->vx_avail = (xp->vx_avail)->c_fwd;
E 6
I 6
D 11
	vs->vs_avail = vs->vs_avail->c_fwd;
E 11
I 11
	vs->vs_avail = p->c_fwd;
E 11
E 6
	splx(s);
D 6
	return( (struct vxcmd *)p);
E 6
I 6
	return ((struct vxcmd *)p);
E 6
}

/*
 * Release a command buffer
 */
D 6
vrelease(xp,cp)
register struct	vcx	*xp;
register struct	vxcmd	*cp;
E 6
I 6
vrelease(vs, cp)
D 8
	register struct	vx_softc *vs;
	register struct	vxcmd *cp;
E 8
I 8
	register struct vx_softc *vs;
	register struct vxcmd *cp;
E 8
E 6
{
I 6
	int s;
E 6

D 6
	register s;

E 6
#ifdef VX_DEBUG
D 6
	if (vxintr4 & VXNOBUF) return;
E 6
I 6
	if (vxintr4&VXNOBUF)
		return;
E 6
#endif
	s = spl8();
D 6
	cp->c_fwd = xp->vx_avail;
	xp->vx_avail = cp;
E 6
I 6
	cp->c_fwd = vs->vs_avail;
	vs->vs_avail = cp;
E 6
	splx(s);
}

D 8
/*
 * vxcmd - 
 *
 */
E 8
D 6
struct vxcmd 	*
nextcmd(xp)
register struct	vcx	*xp;
E 6
I 6
struct vxcmd *
nextcmd(vs)
D 8
	register struct	vx_softc *vs;
E 8
I 8
	register struct vx_softc *vs;
E 8
E 6
{
D 6
	register struct	vxcmd	*cp;
	register int	s;
E 6
I 6
D 8
	register struct	vxcmd *cp;
E 8
I 8
	register struct vxcmd *cp;
E 8
	int s;
E 6

	s = spl8();
D 6
	cp = xp->vx_build;
	xp->vx_build = (struct vxcmd *)0;
E 6
I 6
	cp = vs->vs_build;
	vs->vs_build = (struct vxcmd *)0;
E 6
	splx(s);
D 6
	return(cp);
E 6
I 6
	return (cp);
E 6
}

/*
D 8
 * assemble transmits into a multiple command.
 * up to 8 transmits to 8 lines can be assembled together
E 8
I 8
 * Assemble transmits into a multiple command;
D 11
 * up to 8 transmits to 8 lines can be assembled together.
E 11
I 11
 * up to 8 transmits to 8 lines can be assembled together
 * (on PVIOCX only).
E 11
E 8
 */
D 2
vsetq(xp ,d ,addr, cnt)
E 2
I 2
D 6
vsetq(xp ,d ,addr, n)
E 2
register struct	vcx	*xp;
caddr_t	addr;
E 6
I 6
D 8
vsetq(vs ,d ,addr, n)
	register struct	vx_softc *vs;
E 8
I 8
vsetq(vs, line, addr, n)
	register struct vx_softc *vs;
E 8
	caddr_t	addr;
E 6
{
D 6

	register struct	vxcmd	*cp;
	register struct	vxmit	*mp;
	register char	*p;
E 6
I 6
D 8
	register struct	vxcmd *cp;
	register struct	vxmit *mp;
	register char *p;
E 6
	register i;
E 8
I 8
	register struct vxcmd *cp;
	register struct vxmit *mp;
E 8

I 8
	/*
	 * Grab a new command buffer or append
	 * to the current one being built.
	 */
E 8
D 6
	cp = xp->vx_build;
	if(cp == (struct vxcmd *)0) {
		cp = vobtain(xp);
		xp->vx_build = cp;
		cp->cmd = XMITDTA;
E 6
I 6
	cp = vs->vs_build;
	if (cp == (struct vxcmd *)0) {
		cp = vobtain(vs);
		vs->vs_build = cp;
		cp->cmd = VXC_XMITDTA;
E 6
	} else {
D 6
		if((cp->cmd & 07) == 07) {
			vpanic("vx: vsetq overflow");
			vxstreset(xp->v_nbr);
			return(0);
E 6
I 6
D 11
		if ((cp->cmd & 07) == 07) {
E 11
I 11
		if ((cp->cmd & 07) == 07 || vs->vs_vers == VXV_NEW) {
E 11
			printf("vx%d: setq overflow\n", vs-vx_softc);
D 11
			vxstreset(vs->vs_nbr);
			return (0);
E 11
I 11
			vxstreset((int)vs->vs_nbr);
			return;
E 11
E 6
		}
		cp->cmd++;
	}
I 8
	/*
	 * Select the next vxmit buffer and copy the
	 * characters into the buffer (if there's room
	 * and the device supports ``immediate mode'',
	 * or store an indirect pointer to the data.
	 */
E 8
D 6

	mp = (struct vxmit *)(cp->par + (cp->cmd & 07)*sizvxmit);
E 6
I 6
	mp = (struct vxmit *)(cp->par + (cp->cmd & 07)*sizeof (struct vxmit));
E 6
D 2
	mp->bcount = cnt-1;
E 2
I 2
	mp->bcount = n-1;
E 2
D 6

E 6
D 8
	mp->line = d;
D 2
	if((xp->v_vers == V_NEW) && (cnt <= 6)) {
E 2
I 2
D 6
	if((xp->v_vers == V_NEW) && (n <= 6)) {
E 2
		cp->cmd = XMITIMM ;
E 6
I 6
	if (vs->vs_vers == VXV_NEW && n <= 6) {
E 8
I 8
	mp->line = line;
	if (vs->vs_vers == VXV_NEW && n <= sizeof (mp->ostream)) {
E 8
		cp->cmd = VXC_XMITIMM;
E 6
D 8
		p = addr;
D 2
		/* bcopy(addr, &(char *)mp->ostream, cnt) ; */
E 2
I 2
		/* bcopy(addr, &(char *)mp->ostream, n) ; */
E 8
I 8
D 11
		bcopy(addr, mp->ostream, n);
E 11
I 11
		bcopy(addr, mp->ostream, (unsigned)n);
E 11
E 8
E 2
	} else {
I 8
		/* get system address of clist block */
E 8
D 2
		addr = vtoph(0, (caddr_t)addr) ; /* should be a sys address */
E 2
I 2
		addr = (caddr_t)vtoph((struct proc *)0, (unsigned)addr);
D 8
				/* should be a sys address */
E 2
		p = (char *)&addr;
D 2
		cnt = sizeof addr;
E 2
I 2
		n = sizeof addr;
E 2
		/* mp->ostream = addr ; */
E 8
I 8
D 11
		bcopy(&addr, mp->ostream, sizeof (addr));
E 11
I 11
		bcopy((caddr_t)&addr, mp->ostream, sizeof (addr));
E 11
E 8
	}
D 2
	for(i=0; i<cnt; i++)
E 2
I 2
D 6
	for(i=0; i<n; i++)
E 6
I 6
D 8
	for (i = 0; i < n; i++)
E 6
E 2
		mp->ostream[i] = *p++;
D 6
	if(xp->v_vers == V_NEW)
		return(1) ;
	else
		return((cp->cmd&07) == 7) ;	/* Indicate if full */
E 6
I 6
	if (vs->vs_vers == VXV_NEW)
E 8
D 11
	return (vs->vs_vers == VXV_NEW ? 1 : (cp->cmd&07) == 7);
E 11
I 11
	/*
	 * We send the data immediately if a VIOCX,
	 * the command buffer is full, or if we've nothing
	 * currently outstanding.  If we don't send it,
	 * set a timeout to force the data to be sent soon.
	 */
	if (vs->vs_vers == VXV_NEW || (cp->cmd & 07) == 7 ||
	    vs->vs_xmtcnt == 0) {
		vs->vs_xmtcnt++;
		(void) vcmd((int)vs->vs_nbr, (char *)&cp->cmd);
		vs->vs_build = 0;
	} else
		timeout(vxforce, (caddr_t)vs, 3);
E 11
}

/*
 * Write a command out to the VIOC
 */
vcmd(vx, cmdad)
	register int vx;
	register caddr_t cmdad;
{
D 8
	register struct	vcmds *cp;
E 8
I 8
	register struct vcmds *cp;
E 8
	register struct vx_softc *vs;
	int s;

	s = spl8();
	vs = &vx_softc[vx];
I 8
	/*
	 * When the vioc is resetting, don't process
	 * anything other than VXC_LIDENT commands.
	 */
E 8
	if (vs->vs_state == VXS_RESET && cmdad != NULL) {
D 8
		/*
		 * When the vioc is resetting, don't process
		 * anything other than LIDENT commands.
		 */
		register struct vxcmd *cmdp = (struct vxcmd *)
			((char *)cmdad - sizeof (cmdp->c_fwd));
E 8
I 8
		struct vxcmd *vcp = (struct vxcmd *)(cmdad-sizeof (vcp->c_fwd));
E 8

D 8
		if (cmdp->cmd != VXC_LIDENT) {
			vrelease(vs, cmdp);
E 8
I 8
		if (vcp->cmd != VXC_LIDENT) {
			vrelease(vs, vcp);
E 8
			return (0);
		}
	}
	cp = &vs->vs_cmds;
	if (cmdad != (caddr_t)0) {
		cp->cmdbuf[cp->v_fill] = cmdad;
		if (++cp->v_fill >= VC_CMDBUFL)
			cp->v_fill = 0;
		if (cp->v_fill == cp->v_empty) {
			printf("vx%d: cmd q overflow\n", vx);
			vxstreset(vx);
			splx(s);
			return (0);
		}
		cp->v_cmdsem++;
	}
	if (cp->v_cmdsem && cp->v_curcnt < vs->vs_maxcmd) {
		cp->v_cmdsem--;
		cp->v_curcnt++;
		vinthandl(vx, ((V_BSY|CMDquals) << 8)|V_INTR);
	}
	splx(s);
	return (1);
}

/*
 * VIOC acknowledge interrupt.  The VIOC has received the new
 * command.  If no errors, the new command becomes one of 16 (max)
 * current commands being executed.
 */
vackint(vx)
	register vx;
{
D 8
	register struct	vxdevice *vp;
	register struct	vcmds *cp;
E 8
I 8
	register struct vxdevice *vp;
	register struct vcmds *cp;
E 8
	struct vx_softc *vs;
	int s;

	scope_out(5);
	vs = &vx_softc[vx];
D 10
	if (vs->vs_type) {	/* Its a BOP */
#ifdef SNA_DEBUG
		extern vbrall();

		if (snadebug & SVIOC)
			printf("vx%d: vack interrupt from BOP\n", vx);
		vbrall(vx); 	/* Int. from BOP, port 0 */
#endif
E 10
I 10
	if (vs->vs_type)	/* Its a BOP */
E 10
		return;
D 10
	}
E 10
	s = spl8();
	vp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	cp = &vs->vs_cmds;
D 8
	if (vp->v_vcid & V_ERR) {
E 8
I 8
	if (vp->v_vcid&V_ERR) {
E 8
		register char *resp;
		register i;
I 8

E 8
D 11
		printf("vx%d INTR ERR type %x v_dcd %x\n", vx,
E 11
I 11
		printf("vx%d: ackint error type %x v_dcd %x\n", vx,
E 11
		    vp->v_vcid & 07, vp->v_dcd & 0xff);
D 8
		/* resp = (char *)vp + (vp->v_rspoff & 0x7FFF); */
E 8
		resp = (char *)vs->vs_mricmd;
		for (i = 0; i < 16; i++)
			printf("%x ", resp[i]&0xff);
		printf("\n");
		splx(s);
		vxstreset(vx);
		return;
	}
	if ((vp->v_hdwre&017) == CMDquals) {
#ifdef VX_DEBUG
		if (vxintr4 & VXERR4) {	/* causes VIOC INTR ERR 4 */
D 8
			register struct vxcmd *cp1;
			register struct vxcmd *cp0 = (struct vxcmd *)
				((long)cp->cmdbuf[cp->v_empty] - 4);
E 8
I 8
			struct vxcmd *cp1, *cp0;
E 8

I 8
			cp0 = (struct vxcmd *)
			    ((caddr_t)cp->cmdbuf[cp->v_empty]-sizeof (cp0->c_fwd));
E 8
			if (cp0->cmd == VXC_XMITDTA || cp0->cmd == VXC_XMITIMM) {
				cp1 = vobtain(vs);
				*cp1 = *cp0;
				vxintr4 &= ~VXERR4;
				(void) vcmd(vx, &cp1->cmd);
			}
		}
#endif
		cp->v_curcmd[vp->v_vcid & VCMDLEN-1] = cp->cmdbuf[cp->v_empty];
		if (++cp->v_empty >= VC_CMDBUFL)
			cp->v_empty = 0;
	}
	if (++cp->v_itrempt >= VC_IQLEN)
		cp->v_itrempt = 0;
	vintempt(vx);
	splx(s);
	(void) vcmd(vx, (caddr_t)0);	/* queue next cmd, if any */
}

/*
 * Command Response interrupt.  The Vioc has completed
 * a command.  The command may now be returned to
 * the appropriate device driver.
 */
vcmdrsp(vx)
	register vx;
{
D 8
	register struct	vxdevice *vp;
	register struct	vcmds *cp;
E 8
I 8
	register struct vxdevice *vp;
	register struct vcmds *cp;
E 8
	register caddr_t cmd;
	register struct vx_softc *vs;
	register char *resp;
	register k;
	register int s;

	scope_out(6);
	vs = &vx_softc[vx];
	if (vs->vs_type) {	/* Its a BOP */
		printf("vx%d: vcmdrsp interrupt\n", vx);
		return;
	}
	s = spl8();
	vp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	cp = &vs->vs_cmds;
	resp = (char *)vp + (vp->v_rspoff&0x7fff);
	if (((k = resp[1])&V_UNBSY) == 0) {
		printf("vx%d: cmdresp debug\n", vx);
		splx(s);
		vxstreset(vx);
		return;
	}
	k &= VCMDLEN-1;
	cmd = cp->v_curcmd[k];
	cp->v_curcmd[k] = (caddr_t)0;
	cp->v_curcnt--;
	k = *((short *)&resp[4]);	/* cmd operation code */
	if ((k&0xff00) == VXC_LIDENT)	/* want hiport number */
		for (k = 0; k < VRESPLEN; k++)
			cmd[k] = resp[k+4];
	resp[1] = 0;
	vxxint(vx, (struct vxcmd *)cmd);
	if (vs->vs_state == VXS_READY)
		vinthandl(vx, ((V_BSY|RSPquals) << 8)|V_INTR);
	splx(s);
}

/*
 * Unsolicited interrupt.
 */
vunsol(vx)
	register vx;
{
D 8
	register struct	vxdevice *vp;
E 8
I 8
	register struct vxdevice *vp;
E 8
	struct vx_softc *vs;
	int s;

	scope_out(1);
	vs = &vx_softc[vx];
	if (vs->vs_type) {	/* Its a BOP */
		printf("vx%d: vunsol from BOP\n", vx);
		return;
	}
	s = spl8();
	vp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	if (vp->v_uqual&V_UNBSY) {
		vxrint(vx);
		vinthandl(vx, ((V_BSY|UNSquals) << 8)|V_INTR);
#ifdef notdef
	} else {
		printf("vx%d: unsolicited interrupt error\n", vx);
		splx(s);
		vxstreset(vx);
#endif
	}
	splx(s);
}

/*
D 8
 * Enqueue an interrupt
E 8
I 8
 * Enqueue an interrupt.
E 8
 */
vinthandl(vx, item)
	register int vx;
	register item;
{
	register struct vcmds *cp;
	int empty;

	cp = &vx_softc[vx].vs_cmds;
D 8
	empty = cp->v_itrfill == cp->v_itrempt;
E 8
I 8
	empty = (cp->v_itrfill == cp->v_itrempt);
E 8
	cp->v_itrqueu[cp->v_itrfill] = item;
	if (++cp->v_itrfill >= VC_IQLEN)
		cp->v_itrfill = 0;
	if (cp->v_itrfill == cp->v_itrempt) {
		printf("vx%d: interrupt q overflow\n", vx);
		vxstreset(vx);
	} else if (empty)
		vintempt(vx);
}

vintempt(vx)
	register int vx;
{
	register struct vcmds *cp;
	register struct vxdevice *vp;
	register short item;
	register short *intr;

	vp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	if (vp->v_vioc&V_BSY)
		return;
	cp = &vx_softc[vx].vs_cmds;
	if (cp->v_itrempt == cp->v_itrfill)
		return;
	item = cp->v_itrqueu[cp->v_itrempt];
	intr = (short *)&vp->v_vioc;
	switch ((item >> 8)&03) {

	case CMDquals: {		/* command */
		int phys;

		if (cp->v_empty == cp->v_fill || vp->v_vcbsy&V_BSY)
			break;
		vx_softc[vx].vs_mricmd = (caddr_t)cp->cmdbuf[cp->v_empty];
		phys = vtoph((struct proc *)0, 
		    (unsigned)cp->cmdbuf[cp->v_empty]);
		vp->v_vcp[0] = ((short *)&phys)[0];
		vp->v_vcp[1] = ((short *)&phys)[1];
		vp->v_vcbsy = V_BSY;
		*intr = item;
		scope_out(4);
		break;
	}

	case RSPquals:		/* command response */
		*intr = item;
		scope_out(7);
		break;

	case UNSquals:		/* unsolicited interrupt */
		vp->v_uqual = 0;
		*intr = item;
		scope_out(2);
		break;
	}
}

/*
 * Start a reset on a vioc after error (hopefully)
 */
vxstreset(vx)
	register vx;
{
	register struct vx_softc *vs;
D 8
	register struct	vxdevice *vp;
E 8
I 8
	register struct vxdevice *vp;
E 8
	register struct vxcmd *cp;
	register int j;
	extern int vxinreset();
	int s;

	s = spl8() ;
	vs = &vx_softc[vx];
	if (vs->vs_state == VXS_RESET) {	/* avoid recursion */
		splx(s);
		return;
	}
	vp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	/*
	 * Zero out the vioc structures, mark the vioc as being
	 * reset, reinitialize the free command list, reset the vioc
	 * and start a timer to check on the progress of the reset.
	 */
	bzero((caddr_t)vs, (unsigned)sizeof (*vs));

	/*
	 * Setting VXS_RESET prevents others from issuing
	 * commands while allowing currently queued commands to
	 * be passed to the VIOC.
	 */
	vs->vs_state = VXS_RESET;
	/* init all cmd buffers */
	for (j = 0; j < NVCXBUFS; j++) {
D 8
		cp = &vs->vs_lst[j];	/* index a buffer */
		cp->c_fwd = &vs->vs_lst[j+1];	/* point to next buf */
E 8
I 8
		cp = &vs->vs_lst[j];
		cp->c_fwd = &vs->vs_lst[j+1];
E 8
	}
D 8
	vs->vs_avail = &vs->vs_lst[0];	/* set idx to 1st free buf */
	cp->c_fwd = (struct vxcmd *)0;	/* mark last buf in free list */
E 8
I 8
	vs->vs_avail = &vs->vs_lst[0];
	cp->c_fwd = (struct vxcmd *)0;
E 8
	printf("vx%d: reset...", vx);
	vp->v_fault = 0;
	vp->v_vioc = V_BSY;
D 8
	vp->v_hdwre = V_RESET;		/* reset interrupt */
E 8
I 8
	vp->v_hdwre = V_RESET;		/* generate reset interrupt */
E 8
	timeout(vxinreset, (caddr_t)vx, hz*5);
	splx(s);
}

/* continue processing a reset on a vioc after an error (hopefully) */
vxinreset(vx)
	int vx;
{
D 8
	register struct	vxdevice *vp;
E 8
I 8
	register struct vxdevice *vp;
E 8
	int s = spl8();

	vp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	/*
	 * See if the vioc has reset.
	 */
	if (vp->v_fault != VXF_READY) {
		printf("failed\n");
		splx(s);
		return;
	}
	/*
	 * Send a LIDENT to the vioc and mess with carrier flags
	 * on parallel printer ports.
	 */
D 10
	vxinit(vx, (long)0);
E 10
I 10
	vxinit(vx, 0);
E 10
	splx(s);
}

/*
I 8
 * Finish the reset on the vioc after an error (hopefully).
 *
E 8
 * Restore modem control, parameters and restart output.
 * Since the vioc can handle no more then 24 commands at a time
 * and we could generate as many as 48 commands, we must do this in
 * phases, issuing no more then 16 commands at a time.
 */
D 8
/* finish the reset on the vioc after an error (hopefully) */
E 8
vxfnreset(vx, cp)
	register int vx;
	register struct vxcmd *cp;
{
	register struct vx_softc *vs;
D 8
	register struct	vxdevice *vp ;
E 8
I 8
	register struct vxdevice *vp ;
E 8
	register struct tty *tp, *tp0;
	register int i;
#ifdef notdef
	register int on;
#endif
	extern int vxrestart();
	int s = spl8();

	vs = &vx_softc[vx];
	vs->vs_loport = cp->par[5];
	vs->vs_hiport = cp->par[7];
	vrelease(vs, cp);
	vs->vs_nbr = vx;			/* assign VIOC-X board number */
	vs->vs_state = VXS_READY;

	vp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	vp->v_vcid = 0;

	/*
	 * Restore modem information and control.
	 */
	tp0 = &vx_tty[vx*16];
	for (i = vs->vs_loport; i <= vs->vs_hiport; i++) {
		tp = tp0 + i;
		if (tp->t_state&(TS_ISOPEN|TS_WOPEN)) {
			tp->t_state &= ~TS_CARR_ON;
			vcmodem(tp->t_dev, VMOD_ON);
			if (tp->t_state&TS_CARR_ON)
D 10
				wakeup((caddr_t)&tp->t_canq);
			else if (tp->t_state & TS_ISOPEN) {
				ttyflush(tp, FREAD|FWRITE);
				if (tp->t_state&TS_FLUSH)
					wakeup((caddr_t)&tp->t_state);
				if ((tp->t_flags&NOHANG) == 0) {
					gsignal(tp->t_pgrp, SIGHUP);
					gsignal(tp->t_pgrp, SIGCONT);
				}
			}
E 10
I 10
				(void)(*linesw[tp->t_line].l_modem)(tp, 1);
			else if (tp->t_state & TS_ISOPEN)
				(void)(*linesw[tp->t_line].l_modem)(tp, 0);
E 10
		}
I 10
#ifdef notdef
E 10
		/*
		 * If carrier has changed while we were resetting,
		 * take appropriate action.
		 */
D 10
#ifdef notdef
E 10
		on = vp->v_dcd & 1<<i;
D 10
		if (on && (tp->t_state&TS_CARR_ON) == 0) {
			tp->t_state |= TS_CARR_ON;
			wakeup((caddr_t)&tp->t_canq);
		} else if (!on && tp->t_state&TS_CARR_ON) {
			tp->t_state &= ~TS_CARR_ON;
			if (tp->t_state & TS_ISOPEN) {
				ttyflush(tp, FREAD|FWRITE);
				if (tp->t_state&TS_FLUSH)
					wakeup((caddr_t)&tp->t_state);
				if ((tp->t_flags&NOHANG) == 0) {
					gsignal(tp->t_pgrp, SIGHUP);
					gsignal(tp->t_pgrp, SIGCONT);
				}
			}
		}
E 10
I 10
		if (on && (tp->t_state&TS_CARR_ON) == 0)
			(void)(*linesw[tp->t_line].l_modem)(tp, 1);
		else if (!on && tp->t_state&TS_CARR_ON)
			(void)(*linesw[tp->t_line].l_modem)(tp, 0);
E 10
#endif
	}
	vs->vs_state = VXS_RESET;
	timeout(vxrestart, (caddr_t)vx, hz);
	splx(s);
}

/*
 * Restore a particular aspect of the VIOC.
 */
vxrestart(vx)
	int vx;
{
	register struct tty *tp, *tp0;
	register struct vx_softc *vs;
D 11
	register int i, cnt;
E 11
I 11
	register int i, count;
E 11
	int s = spl8();

D 11
	cnt = vx >> 8;
E 11
I 11
	count = vx >> 8;
E 11
	vx &= 0xff;
	vs = &vx_softc[vx];
	vs->vs_state = VXS_READY;
	tp0 = &vx_tty[vx*16];
	for (i = vs->vs_loport; i <= vs->vs_hiport; i++) {
		tp = tp0 + i;
D 11
		if (cnt != 0) {
E 11
I 11
		if (count != 0) {
E 11
			tp->t_state &= ~(TS_BUSY|TS_TIMEOUT);
			if (tp->t_state&(TS_ISOPEN|TS_WOPEN))
				vxstart(tp);	/* restart pending output */
		} else {
			if (tp->t_state&(TS_WOPEN|TS_ISOPEN))
				vxcparam(tp->t_dev, 0);
		}
	}
D 11
	if (cnt == 0) {
E 11
I 11
	if (count == 0) {
E 11
		vs->vs_state = VXS_RESET;
		timeout(vxrestart, (caddr_t)(vx + 1*256), hz);
	} else
		printf("done\n");
	splx(s);
}

vxreset(dev)
	dev_t dev;
{

D 11
	vxstreset(minor(dev) >> 4);	/* completes asynchronously */
E 11
I 11
	vxstreset((int)VXUNIT(minor(dev)));	/* completes asynchronously */
E 11
}

I 11
#ifdef notdef
E 11
vxfreset(vx)
	register int vx;
{
	struct vba_device *vi;

	if ((unsigned)vx > NVX || (vi = vxinfo[vx]) == 0 || vi->ui_addr == 0)
		return (ENODEV);
	vx_softc[vx].vs_state = VXS_READY;
	vxstreset(vx);
	return (0);		/* completes asynchronously */
}
I 11
#endif
E 11

vcmodem(dev, flag)
	dev_t dev;
{
	struct tty *tp;
	register struct vxcmd *cp;
	register struct vx_softc *vs;
	register struct vxdevice *kp;
	register port;
	int unit;

	unit = minor(dev);
	tp = &vx_tty[unit];
	vs = (struct vx_softc *)tp->t_addr;
I 11
	if (vs->vs_state != VXS_READY)
		return;
E 11
	cp = vobtain(vs);
	kp = (struct vxdevice *)((struct vba_device *)vxinfo[vs->vs_nbr])->ui_addr;

	port = unit & 017;
	/*
	 * Issue MODEM command
	 */
	cp->cmd = VXC_MDMCTL;
D 11
	cp->par[0] = (flag == VMOD_ON) ? V_ENAB : V_DISAB;
E 11
I 11
	if (flag == VMOD_ON) {
		if (vs->vs_softCAR & (1 << port))
			cp->par[0] = V_MANUAL | V_DTR_ON | V_RTS;
		else
			cp->par[0] = V_AUTO | V_DTR_ON | V_RTS;
	} else
		cp->par[0] = V_DTR_OFF;
E 11
	cp->par[1] = port;
D 11
	vcmd(vs->vs_nbr, (caddr_t)&cp->cmd);
	port -= vs->vs_loport;
	if ((kp->v_dcd >> port) & 1) {
		if (flag == VMOD_ON)
			tp->t_state |= TS_CARR_ON;
		return (1);
	}
	return (0);
E 11
I 11
	(void) vcmd((int)vs->vs_nbr, (caddr_t)&cp->cmd);
	if (vs->vs_softCAR & (1 << port))
		kp->v_dcd |= (1 << port);
	if ((kp->v_dcd | vs->vs_softCAR) & (1 << port) && flag == VMOD_ON)
		tp->t_state |= TS_CARR_ON;
E 11
}

/*
 * VCMINTR called when an unsolicited interrup occurs signaling
 * some change of modem control state.
 */
vcmintr(vx)
	register vx;
{
	register struct vxdevice *kp;
	register struct tty *tp;
	register port;
I 11
	register struct vx_softc *vs;
E 11

	kp = (struct vxdevice *)((struct vba_device *)vxinfo[vx])->ui_addr;
	port = kp->v_usdata[0] & 017;
	tp = &vx_tty[vx*16+port];
I 11
	vs = &vx_softc[vx];
E 11
D 10
#if NVBSC > 0
	/*
	 * Check for change in DSR for BISYNC port.
	 */
	if (bscport[vx*16+port]&BISYNC) {
		if (kp->v_ustat&DSR_CHG) {
D 8
			register struct	vx_softc *xp;
E 8
I 8
			register struct vx_softc *xp;
E 8
			register struct bsc *bp;
			extern struct bsc bsc[];
E 10

D 10
			vs = (struct vx_softc *)tp->t_addr;
			bp = &bsc[minor(tp->t_dev)] ;
			bp->b_hlflgs &= ~BSC_DSR ;
			if (kp->v_ustat & DSR_ON)
				bp->b_hlflgs |= BSC_DSR ;
			printf("BSC DSR Chg: %x\n", kp->v_ustat&DSR_CHG);/*XXX*/
		}
		return;
	}
#endif
	if ((kp->v_ustat&DCD_ON) && ((tp->t_state&TS_CARR_ON) == 0)) {
		tp->t_state |= TS_CARR_ON;
		wakeup((caddr_t)&tp->t_canq);
		return;
	}
	if ((kp->v_ustat&DCD_OFF) && (tp->t_state&TS_CARR_ON)) {
		tp->t_state &= ~TS_CARR_ON;
		if (tp->t_state&TS_ISOPEN) {
			register struct vx_softc *vs;
			register struct vcmds *cp;
			register struct vxcmd *cmdp;
E 10
I 10
	if (kp->v_ustat & DCD_ON)
		(void)(*linesw[tp->t_line].l_modem)(tp, 1);
	else if ((kp->v_ustat & DCD_OFF) &&
I 11
	    ((vs->vs_softCAR & (1 << port))) == 0 &&
E 11
	    (*linesw[tp->t_line].l_modem)(tp, 0) == 0) {
D 11
		register struct vx_softc *vs;
E 11
		register struct vcmds *cp;
		register struct vxcmd *cmdp;
E 10

D 10
			ttyflush(tp, FREAD|FWRITE);
			/* clear all pending trnansmits */
			vs = &vx_softc[vx];
			if (tp->t_state&(TS_BUSY|TS_FLUSH) &&
			    vs->vs_vers == VXV_NEW) {
				int i, cmdfound = 0;
E 10
I 10
D 11
		/* clear all pending trnansmits */
		vs = &vx_softc[vx];
E 11
I 11
		/* clear all pending transmits */
E 11
		if (tp->t_state&(TS_BUSY|TS_FLUSH) &&
		    vs->vs_vers == VXV_NEW) {
			int i, cmdfound = 0;
E 10

D 10
				cp = &vs->vs_cmds;
				for (i = cp->v_empty; i != cp->v_fill; ) {
					cmdp = (struct vxcmd *)((long *)cp->cmdbuf[i]-1);
					if ((cmdp->cmd == VXC_XMITDTA ||
					    cmdp->cmd == VXC_XMITIMM) &&
					    ((struct vxmit *)cmdp->par)->line == port) {
						cmdfound++;
						cmdp->cmd = VXC_FDTATOX;
						cmdp->par[1] = port;
					}
					if (++i >= VC_CMDBUFL)
						i = 0;
				}
				if (cmdfound)
					tp->t_state &= ~(TS_BUSY|TS_FLUSH);
				/* cmd is already in vioc, have to flush it */
				else {
					cmdp = vobtain(vs);
E 10
I 10
			cp = &vs->vs_cmds;
			for (i = cp->v_empty; i != cp->v_fill; ) {
				cmdp = (struct vxcmd *)((long *)cp->cmdbuf[i]-1);
				if ((cmdp->cmd == VXC_XMITDTA ||
				    cmdp->cmd == VXC_XMITIMM) &&
				    ((struct vxmit *)cmdp->par)->line == port) {
					cmdfound++;
E 10
					cmdp->cmd = VXC_FDTATOX;
					cmdp->par[1] = port;
D 10
					vcmd(vx, (caddr_t)&cmdp->cmd);
E 10
				}
I 10
				if (++i >= VC_CMDBUFL)
					i = 0;
E 10
			}
D 10
			if ((tp->t_flags&NOHANG) == 0) {
				gsignal(tp->t_pgrp, SIGHUP);
				gsignal(tp->t_pgrp, SIGCONT);
E 10
I 10
			if (cmdfound)
				tp->t_state &= ~(TS_BUSY|TS_FLUSH);
			/* cmd is already in vioc, have to flush it */
			else {
				cmdp = vobtain(vs);
				cmdp->cmd = VXC_FDTATOX;
				cmdp->par[1] = port;
D 11
				vcmd(vx, (caddr_t)&cmdp->cmd);
E 11
I 11
				(void) vcmd(vx, (caddr_t)&cmdp->cmd);
E 11
E 10
			}
		}
D 10
		return;
	}
	if ((kp->v_ustat&BRK_CHR) && (tp->t_state&TS_ISOPEN)) {
E 10
I 10
	} else if ((kp->v_ustat&BRK_CHR) && (tp->t_state&TS_ISOPEN)) {
E 10
D 11
		(*linesw[tp->t_line].l_rint)(tp->t_intrc & 0377, tp);
E 11
I 11
		(*linesw[tp->t_line].l_rint)((tp->t_flags & RAW) ?
		    0 : tp->t_intrc, tp);
E 11
		return;
	}
E 6
}
#endif
E 1
