h52726
s 00001/00001/00690
d D 7.1 86/06/05 01:13:53 mckusick 19 18
c 4.3BSD release version
e
s 00004/00004/00687
d D 6.7 86/02/23 23:17:34 karels 18 17
c lint
e
s 00208/00195/00483
d D 6.6 85/11/13 21:03:50 sam 17 16
c cleanup; remove hidden refrence to vars inside macros; delete 
c short int, unsigned short int stuff; collaps some structures; etc....
e
s 00117/00064/00561
d D 6.5 85/11/12 20:01:22 sam 16 15
c new version from lfl which fixes refresh problems
e
s 00001/00001/00624
d D 6.4 85/06/16 18:27:21 sam 15 14
c add bill's name 
e
s 00007/00001/00618
d D 6.3 85/06/08 14:18:37 mckusick 14 13
c Add copyright
e
s 00012/00012/00607
d D 6.2 84/08/29 20:08:59 bloom 13 12
c Change to includes.  No more ../h
e
s 00000/00000/00619
d D 6.1 83/08/13 12:39:43 sam 12 11
c 4.2 distribution
e
s 00034/00009/00585
d D 4.10 83/08/13 12:37:20 sam 11 9
c update from reeves; tested with 4.2
e
s 00000/00000/00594
d R 6.1 83/07/29 07:28:15 sam 10 9
c 4.2 distribution
e
s 00002/00001/00592
d D 4.9 82/12/17 12:02:55 sam 9 8
c sun merge
e
s 00001/00001/00592
d D 4.8 82/12/05 21:48:39 sam 8 7
c reorganized tty structuer
e
s 00084/00099/00509
d D 4.7 82/10/17 11:49:49 root 7 6
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00004/00003/00604
d D 4.6 82/10/10 17:28:05 root 6 5
c header files for vax are in their place
e
s 00000/00000/00607
d D 4.5 82/08/22 21:18:56 root 5 4
c fully uio()'d
e
s 00005/00002/00602
d D 4.4 82/08/13 00:16:12 root 4 3
c changes for char dev uio'ing
e
s 00027/00015/00577
d D 4.3 82/08/01 19:25:40 sam 3 2
c new ioctl's
e
s 00001/00000/00591
d D 4.2 82/07/15 20:02:15 kre 2 1
c probe routines return size of unibus dev regs to reserve space
e
s 00591/00000/00000
d D 4.1 82/06/26 16:09:03 sam 1 0
c date and time created 82/06/26 16:09:03 by sam
e
u
U
t
T
I 1
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
D 19
 * Copyright (c) 1982 Regents of the University of California.
E 19
I 19
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 14

/*
D 15
 * Evans and Sutherland Picture System 2 driver
E 15
I 15
 * Evans and Sutherland Picture System 2 driver -- Bill Reeves.
E 15
 */

/*
 *	Still to be done:
 *		WAIT_HIT
 */

#include "ps.h"
#if NPS > 0

#define EXTERNAL_SYNC

I 9
#include "../machine/pte.h"

E 9
D 13
#include "../h/param.h"
#include "../h/systm.h"
D 8
#include "../h/tty.h"
E 8
I 8
#include "../h/ioctl.h"
E 8
D 9
#include "../h/pte.h"
E 9
#include "../h/map.h"
#include "../h/buf.h"
D 6
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 6
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
D 6
#include "../h/psreg.h"
E 6
I 4
#include "../h/uio.h"
E 13
I 13
#include "param.h"
#include "systm.h"
#include "ioctl.h"
#include "map.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "uio.h"
E 13
I 6

D 13
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/psreg.h"
E 13
I 13
#include "ubareg.h"
#include "ubavar.h"
#include "psreg.h"
E 13
E 6
E 4

D 16
int	psprobe(), psattach(), psintr();
E 16
I 16
int	psprobe(), psattach(), psextsync();
int	psclockintr(), pssystemintr(), psdeviceintr(), psdmaintr();
E 16
struct	uba_device *psdinfo[NPS];
u_short	psstd[] = { 0 };
struct	uba_driver psdriver = 
    { psprobe, 0, psattach, 0, psstd, "ps", psdinfo };

#define	PSUNIT(dev)	(minor(dev))

D 17
#define MAXAUTOREFRESH			(4)
#define MAXAUTOMAP			(4)
#define MAXDBSIZE			(0177777/2)
E 17
I 17
#define MAXAUTOREFRESH	4
#define MAXAUTOMAP	4
#define MAXDBSIZE	(0177777/2)
E 17

D 17
#define PSPRI				(PZERO+1)
E 17
I 17
#define PSPRI		(PZERO+1)
E 17

D 16
#define PSWAIT() {register short int i, j; i=20000; while((i-- != 0)\
E 16
I 16
D 17
#define PSWAIT() {register short i, j; i=20000; while((i-- != 0)\
E 16
	&& (((j=psaddr->ps_iostat)&DIOREADY)==0));}
E 17
I 17
#define PSWAIT(psaddr) { \
	register short i = 20000, j; \
	while (i-- != 0 && ((j = psaddr->ps_iostat) & DIOREADY) == 0) \
		;\
}
E 17

I 17
struct psrefresh {
	enum {
		SINGLE_STEP_RF,
		AUTO_RF,
		TIME_RF
	} state;
	enum {
		RUNNING_RF,
		SYNCING_RF,
		WAITING_MAP,
		STOPPED_RF
	} mode;
	u_short	sraddrs[MAXAUTOREFRESH];
	short	nsraddrs;
	short	srcntr;
	char	waiting;
	char	stop;
	int	icnt;
	int	timecnt;
};

struct psdbuffer {
	enum {
		ON_DB,
		OFF_DB
	} state;
	u_short	dbaddrs[2];
	u_short	dbsize;
	short	rbuffer;
};

struct psmap {
	enum {
		SINGLE_STEP_MAP,
		AUTO_MAP
	} state;
	enum {
		RUNNING_MAP,
		WAITING_RF,
		WAITING_START,
		STOPPED_MAP
	} mode;
	u_short	maddrs[MAXAUTOMAP];
	short	nmaddrs;
	short	mcntr;
	short	outputstart;
	char	waiting;
	char	stop;
	int	icnt;
};

/*
 * PS2 software state.
 */
E 17
struct ps {
D 17
	char		ps_open;
	short int 	ps_uid;
	struct {
D 11
		enum { SINGLE_STEP_RF, AUTO_RF } state;
		enum { RUNNING_RF, SYNCING_RF, WAITING_MAP } mode;
E 11
I 11
		enum { SINGLE_STEP_RF, AUTO_RF, TIME_RF } state;
		enum { RUNNING_RF, SYNCING_RF, WAITING_MAP, STOPPED_RF } mode;
E 11
		unsigned short int sraddrs[MAXAUTOREFRESH];
		short int nsraddrs;
		short int srcntr;
		char waiting;
		char stop;
		int icnt;
I 11
		int timecnt;
E 11
	} ps_refresh;
	struct {
		enum { ON_DB, OFF_DB } state;
		unsigned short int dbaddrs[2];
		unsigned short int dbsize;
		short int rbuffer;
	} ps_dbuffer;
	struct {
		enum { SINGLE_STEP_MAP, AUTO_MAP } state;
D 16
		enum { RUNNING_MAP, WAITING_RF, WAITING_START } mode;
E 16
I 16
		enum { RUNNING_MAP, WAITING_RF, WAITING_START, STOPPED_MAP } mode;
E 16
		unsigned short int maddrs[MAXAUTOMAP];
		short int nmaddrs;
		short int mcntr;
		short int outputstart;
		char waiting;
		char stop;
		int icnt;
	} ps_map;
	struct {
		short int ticked;
		short int missed;
		int icnt;
	} ps_clock;
	struct {
		int icnt;
	} ps_hit;
	int ps_strayintr;
	int last_request;
	int strayrequest;
I 11
	int ps_icnt;
I 16
	int last_request2;
	int last_funnyrequest;
	int funny_cnt;
E 17
I 17
	char	ps_open;		/* device is open */
	uid_t 	ps_uid;			/* uid of device owner */
	struct	psrefresh ps_refresh;	/* refresh state */
	struct	psdbuffer ps_dbuffer;	/* double buffering state */
	struct	psmap ps_map;		/* segment map state */
	int	ps_clockticks;		/* clock ints between refresh */
	int	ps_clockmiss;		/* clock ints w/o refresh */
	int	ps_clockcnt;		/* count of clock interrupts */
	int	ps_hitcnt;		/* count of hit interrupts */
	int	ps_strayintr;		/* count of stray interrupts */
	int	ps_icnt;		/* count of system interrupts */
/* BEGIN GROT */
	int	ps_lastrequest;
	int	ps_lastrequest2;
	int	ps_lastfunnyrequest;
	int	ps_funnycnt;
/* END GROT */
E 17
E 16
E 11
} ps[NPS];

psprobe(reg)
	caddr_t reg;
{
	register int br, cvec;
D 17
	register struct psdevice *psaddr = (struct psdevice *) reg;
E 17
I 17
	register struct psdevice *psaddr = (struct psdevice *)reg;
E 17

I 16
#ifdef lint
	br = 0; cvec = br; br = cvec;
	psclockintr((dev_t)0); pssystemintr((dev_t)0);
	psdeviceintr((dev_t)0); psdmaintr((dev_t)0);
	psextsync(0, 0);
#endif
E 16
	psaddr->ps_iostat = PSRESET;
	DELAY(200);
	psaddr->ps_addr = RTCIE;
D 17
	PSWAIT();
	psaddr->ps_data = 01;
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_data = 01;
E 17
	psaddr->ps_iostat = PSIE;
	psaddr->ps_addr = RTCSR;
D 17
	PSWAIT();
	psaddr->ps_data = (SYNC|RUN);
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_data = SYNC|RUN;
E 17
	DELAY(200000);
	psaddr->ps_addr = RTCREQ;
D 17
	PSWAIT();
	psaddr->ps_data = 01;
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_data = 01;
E 17
	psaddr->ps_iostat = 0;
	psaddr->ps_iostat = PSRESET;
I 2
	return (sizeof (struct psdevice));
E 2
}

/*ARGSUSED*/
psattach(ui)
D 16
	register struct uba_device *ui;
E 16
I 16
	struct uba_device *ui;
E 16
{
I 7

E 7
}

D 7

E 7
psopen(dev)
	dev_t dev;
{
	register struct ps *psp;
	register struct uba_device *ui;
	register int unit = PSUNIT(dev);

D 7
	if(unit >= NPS || (psp = &ps[minor(dev)])->ps_open ||
			(ui = psdinfo[unit]) == 0 || ui->ui_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 7
I 7
	if (unit >= NPS || (psp = &ps[minor(dev)])->ps_open ||
	    (ui = psdinfo[unit]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
E 7
	psp->ps_open = 1;
	psp->ps_uid = u.u_uid;
	psp->ps_strayintr = 0;
	psp->ps_refresh.state = SINGLE_STEP_RF;
I 16
	psp->ps_refresh.mode = STOPPED_RF;
E 16
	psp->ps_refresh.waiting = 0;
	psp->ps_refresh.stop = 0;
	psp->ps_dbuffer.state = OFF_DB;
	psp->ps_map.state = SINGLE_STEP_MAP;
I 16
	psp->ps_map.mode = STOPPED_MAP;
E 16
	psp->ps_map.waiting = 0;
	psp->ps_map.stop = 0;
D 17
	psp->ps_clock.ticked = 0;
I 16
	psp->ps_clock.missed = 0;
E 16
	psp->ps_refresh.icnt = psp->ps_map.icnt = psp->ps_clock.icnt = 0;
I 16
	psp->ps_hit.icnt = 0;
E 17
I 17
	psp->ps_clockticks = 0;
	psp->ps_clockmiss = 0;
	psp->ps_refresh.icnt = psp->ps_map.icnt = psp->ps_clockcnt = 0;
	psp->ps_hitcnt = 0;
E 17
E 16
I 11
	psp->ps_icnt = 0;
E 11
	maptouser(ui->ui_addr);
I 7
	return (0);
E 7
}

psclose(dev)
	dev_t dev;
{
	register struct psdevice *psaddr = 
D 17
			(struct psdevice *) psdinfo[PSUNIT(dev)]->ui_addr;
E 17
I 17
	    (struct psdevice *)psdinfo[PSUNIT(dev)]->ui_addr;
E 17

	ps[PSUNIT(dev)].ps_open = 0;
D 17
	psaddr->ps_iostat = 0;		/* clear IENABLE */
	PSWAIT();
	psaddr->ps_addr = RFSR;		/* set in auto refresh mode */
	PSWAIT();
	psaddr->ps_data = AUTOREF;
E 17
I 17
	psaddr->ps_iostat = 0;			 /* clear IENABLE */
	PSWAIT(psaddr); psaddr->ps_addr = RFSR;	 /* set in auto refresh mode */
	PSWAIT(psaddr); psaddr->ps_data = AUTOREF;
E 17
D 16
	unmaptouser(psaddr);
E 16
I 16
	unmaptouser((caddr_t)psaddr);
E 16
}

/*ARGSUSED*/
D 4
psread(dev)
E 4
I 4
psread(dev, uio)
E 4
	dev_t dev;
I 4
	struct uio *uio;
E 4
{
}

/*ARGSUSED*/
D 4
pswrite(dev)
E 4
I 4
pswrite(dev, uio)
E 4
	dev_t dev;
I 4
	struct uio *uio;
E 4
{
}

/*ARGSUSED*/
D 3
psioctl(dev, cmd, addr, flag)
	register caddr_t addr;
E 3
I 3
psioctl(dev, cmd, data, flag)
	register caddr_t data;
E 3
{
	register struct uba_device *ui = psdinfo[PSUNIT(dev)];
	register struct ps *psp = &ps[PSUNIT(dev)];
D 3
	int *waddr = (int *) addr;
E 3
I 3
	int *waddr = *(int **)data;
E 3
	int n, arg, i;

	switch (cmd) {
D 3
	case PSGETADDR:
		(void) suword(addr, ui->ui_addr);
E 3
I 3

	case PSIOGETADDR:
		*(caddr_t *)data = ui->ui_addr;
E 3
		break;
D 3
	case PSAUTOREFRESH:
E 3
I 3

	case PSIOAUTOREFRESH:
E 3
D 16
		n = fuword(waddr++);
E 16
I 16
		n = fuword((caddr_t)waddr++);
E 16
D 7
		if(n == -1)
			u.u_error = EFAULT;
		else if(n < 0 || n > MAXAUTOREFRESH)
			u.u_error = EINVAL;
		else {
			for(i = 0; i < n; i++)
				if((arg = fuword(waddr++)) == -1) {
					u.u_error = EFAULT;
					break;
				}
				else
					psp->ps_refresh.sraddrs[i] = arg;
			if(!u.u_error) {
				psp->ps_refresh.state = AUTO_RF;
				psp->ps_refresh.nsraddrs = n;
				psp->ps_refresh.srcntr = 0;
				psp->ps_refresh.mode = WAITING_MAP;
			}
E 7
I 7
		if (n == -1)
			return (EFAULT);
		if (n < 0 || n > MAXAUTOREFRESH)
			return (EINVAL);
		for (i = 0; i < n; i++) {
D 16
			if ((arg = fuword(waddr++)) == -1)
E 16
I 16
			if ((arg = fuword((caddr_t)waddr++)) == -1)
E 16
				return (EFAULT);
			psp->ps_refresh.sraddrs[i] = arg;
E 7
		}
I 7
		psp->ps_refresh.state = AUTO_RF;
		psp->ps_refresh.nsraddrs = n;
		psp->ps_refresh.srcntr = 0;
		psp->ps_refresh.mode = WAITING_MAP;
E 7
		break;
D 3
	case PSAUTOMAP:
E 3
I 3

	case PSIOAUTOMAP:
E 3
D 16
		n = fuword(waddr++);
E 16
I 16
		n = fuword((caddr_t)waddr++);
E 16
D 7
		if(n == -1)
			u.u_error = EFAULT;
		else if(n < 0 || n > MAXAUTOMAP)
			u.u_error = EINVAL;
		else {
			for(i = 0; i < n; i++)
				if((arg = fuword(waddr++)) == -1) {
					u.u_error = EFAULT;
					break;
				}
				else
					psp->ps_map.maddrs[i] = arg;
			if(!u.u_error)
				if((arg = fuword(waddr++)) == -1)
					u.u_error = EFAULT;
				else
					psp->ps_map.outputstart = arg;
			if(!u.u_error) {
				psp->ps_map.state = AUTO_MAP;
				psp->ps_map.nmaddrs = n;
				psp->ps_map.mcntr = 0;
				psp->ps_map.mode = WAITING_START;
			}
E 7
I 7
		if (n == -1)
			return (EFAULT);
		if (n < 0 || n > MAXAUTOMAP)
			return (EINVAL);
		for (i = 0; i < n; i++) {
D 16
			if ((arg = fuword(waddr++)) == -1)
E 16
I 16
			if ((arg = fuword((caddr_t)waddr++)) == -1)
E 16
				return (EFAULT);
			psp->ps_map.maddrs[i] = arg;
E 7
		}
I 7
D 16
		if ((arg = fuword(waddr++)) == -1)
E 16
I 16
		if ((arg = fuword((caddr_t)waddr++)) == -1)
E 16
			return (EFAULT);
		psp->ps_map.outputstart = arg;
		psp->ps_map.state = AUTO_MAP;
		psp->ps_map.nmaddrs = n;
		psp->ps_map.mcntr = 0;
		psp->ps_map.mode = WAITING_START;
E 7
		break;
D 3
	case PSSINGLEREFRESH:
E 3
I 3

	case PSIOSINGLEREFRESH:
E 3
		psp->ps_refresh.state = SINGLE_STEP_RF;
		break;
D 3
	case PSSINGLEMAP:
E 3
I 3

	case PSIOSINGLEMAP:
E 3
		psp->ps_map.state = SINGLE_STEP_MAP;
		break;
D 3
	case PSDOUBLEBUFFER:
E 3
I 3

	case PSIODOUBLEBUFFER:
E 3
D 7
		if((arg = fuword(waddr++)) == -1)
			u.u_error = EFAULT;
		else {
			psp->ps_dbuffer.dbaddrs[0] = arg;
			if((arg = fuword(waddr++)) == -1)
				u.u_error = EFAULT;
			else if(arg <= 0 || arg > MAXDBSIZE)
				u.u_error = EINVAL;
			else {
				psp->ps_dbuffer.dbsize = arg;
				psp->ps_dbuffer.dbaddrs[1] =
						psp->ps_dbuffer.dbaddrs[0]+arg;
				psp->ps_dbuffer.state = ON_DB;
				psp->ps_dbuffer.rbuffer = 0;
			}
E 7
I 7
D 16
		if ((arg = fuword(waddr++)) == -1)
E 16
I 16
		if ((arg = fuword((caddr_t)waddr++)) == -1)
E 16
			return (EFAULT);
		psp->ps_dbuffer.dbaddrs[0] = arg;
D 16
		if ((arg = fuword(waddr++)) == -1)
E 16
I 16
		if ((arg = fuword((caddr_t)waddr++)) == -1)
E 16
			return (EFAULT);
		if (arg <= 0 || arg > MAXDBSIZE)
			return (EINVAL);
		psp->ps_dbuffer.dbsize = arg;
D 17
		psp->ps_dbuffer.dbaddrs[1] =
		    psp->ps_dbuffer.dbaddrs[0]+arg;
E 17
I 17
		psp->ps_dbuffer.dbaddrs[1] = psp->ps_dbuffer.dbaddrs[0]+arg;
E 17
		psp->ps_dbuffer.state = ON_DB;
		psp->ps_dbuffer.rbuffer = 0;
E 7
D 11
		}
E 11
		break;
D 3
	case PSSINGLEBUFFER:
E 3
I 3

	case PSIOSINGLEBUFFER:
E 3
		psp->ps_dbuffer.state = OFF_DB;
		break;
D 3
	case PSWAITREFRESH:
E 3
I 3

I 11
	case PSIOTIMEREFRESH:
		if (psp->ps_refresh.state != SINGLE_STEP_RF)
D 17
			return(EINVAL);
E 17
I 17
			return (EINVAL);
E 17
D 16
		if ((arg = fuword(waddr++)) == -1)
E 16
I 16
		if ((arg = fuword((caddr_t)waddr++)) == -1)
E 16
D 17
			return(EFAULT);
E 17
I 17
			return (EFAULT);
E 17
		psp->ps_refresh.state = TIME_RF;
		psp->ps_refresh.timecnt = arg;
		break;

E 11
	case PSIOWAITREFRESH:
E 3
D 7
		if(psp->ps_refresh.mode != RUNNING_RF)	/* not running */
			return;				/* dont wait */
E 7
I 7
		if (psp->ps_refresh.mode != RUNNING_RF)	/* not running */
D 17
			return (0);				/* dont wait */
E 17
I 17
			return (0);			/* dont wait */
E 17
		/* fall into ... */
E 7
D 3
	case PSSTOPREFRESH:
E 3
I 3

D 11
	case PSSIOTOPREFRESH:
E 3
D 7
		if(cmd == PSSTOPREFRESH)
E 7
I 7
		if (cmd == PSSTOPREFRESH)
E 11
I 11
	case PSIOSTOPREFRESH:
		if (cmd == PSIOSTOPREFRESH) {
D 17
			if (psp->ps_refresh.mode == STOPPED_RF
					&& psp->ps_refresh.state != TIME_RF)
E 17
I 17
			if (psp->ps_refresh.mode == STOPPED_RF &&
			    psp->ps_refresh.state != TIME_RF)
E 17
				return (0);
E 11
E 7
			psp->ps_refresh.stop = 1;
I 11
		}
E 11
D 17
		spl5();
E 17
I 17
		(void) spl5();
E 17
		psp->ps_refresh.waiting = 1;
D 7
		while(psp->ps_refresh.waiting)
E 7
I 7
		while (psp->ps_refresh.waiting)
E 7
			sleep(&psp->ps_refresh.waiting, PSPRI);
D 17
		spl0();
E 17
I 17
		(void) spl0();
E 17
I 11
		if (cmd == PSIOSTOPREFRESH)
			psp->ps_refresh.mode = STOPPED_RF;
		if (psp->ps_refresh.state == TIME_RF)
			psp->ps_refresh.state = SINGLE_STEP_RF;
E 11
		break;
D 3
	case PSWAITMAP:
E 3
I 3

	case PSIOWAITMAP:
E 3
D 7
		if(psp->ps_map.mode != RUNNING_MAP)	/* not running */
			return;				/* dont wait */
E 7
I 7
		if (psp->ps_map.mode != RUNNING_MAP)	/* not running */
D 17
			return (0);				/* dont wait */
E 17
I 17
			return (0);			/* dont wait */
E 17
		/* fall into ... */
E 7
D 3
	case PSSTOPMAP:
E 3
I 3

	case PSIOSTOPMAP:
E 3
D 7
		if(cmd == PSSTOPMAP)
E 7
I 7
D 11
		if (cmd == PSSTOPMAP)
E 11
I 11
		if (cmd == PSIOSTOPMAP)
E 11
E 7
			psp->ps_map.stop = 1;
D 17
		spl5();
E 17
I 17
		(void) spl5();
E 17
		psp->ps_map.waiting = 1;
D 7
		while(psp->ps_map.waiting)
E 7
I 7
		while (psp->ps_map.waiting)
E 7
			sleep(&psp->ps_map.waiting, PSPRI);
D 17
		spl0();
E 17
I 17
		(void) spl0();
E 17
		break;
I 3

E 3
	default:
D 7
		u.u_error = ENOTTY;	/* Not a legal ioctl cmd. */
E 7
I 7
		return (ENOTTY);
E 7
		break;
	}
I 7
	return (0);
E 7
}

D 16
#define SAVEPSADDR() {register short int i, x;x=spl6();i=psaddr->ps_addr;\
		while(((i=psaddr->ps_iostat)&DIOREADY)==0);\
		savepsaddr=psaddr->ps_data;splx(x);}
#define RESTORPSADDR() {register int x,i;x=spl6();\
		while(((i=psaddr->ps_iostat)&DIOREADY)==0);\
		psaddr->ps_addr=savepsaddr;splx(x);}
E 16
I 16
D 17
#define SAVEPSADDR() {register short i,xx1;xx1=spl6();i=psaddr->ps_addr;\
		while(((psaddr->ps_iostat)&DIOREADY)==0);\
		savepsaddr=psaddr->ps_data;splx(xx1);}
#define RESTORPSADDR() {register short xx2;xx2=spl6();\
		while(((psaddr->ps_iostat)&DIOREADY)==0);\
		psaddr->ps_addr=savepsaddr;splx(xx2);}
E 17
I 17
#define SAVEPSADDR(psaddr, savepsaddr) { \
	register short i, xx1; \
D 18
	xx1 = spl6(); \
E 18
I 18
	xx1 = splclock(); \
E 18
	i = psaddr->ps_addr; \
	while ((psaddr->ps_iostat & DIOREADY) == 0) \
		; \
	savepsaddr = psaddr->ps_data; \
	splx(xx1); \
}
#define RESTORPSADDR(psaddr, savepsaddr) { \
	register short xx2; \
D 18
	xx2 = spl6(); \
E 18
I 18
	xx2 = splclock(); \
E 18
	while ((psaddr->ps_iostat & DIOREADY) == 0) \
		;\
	psaddr->ps_addr = savepsaddr; \
	splx(xx2); \
}
E 17
E 16

psclockintr(dev)
	dev_t dev;
{
	register struct psdevice *psaddr =
D 17
			(struct psdevice *) psdinfo[PSUNIT(dev)]->ui_addr;
E 17
I 17
	    (struct psdevice *)psdinfo[PSUNIT(dev)]->ui_addr;
E 17
	register struct ps *psp = &ps[PSUNIT(dev)];
	int savepsaddr;

D 7
	if(!psp->ps_open)
E 7
I 7
	if (!psp->ps_open)
E 7
		return;
D 17
	psp->ps_clock.icnt++;
	SAVEPSADDR();
E 17
I 17
	psp->ps_clockcnt++;
	SAVEPSADDR(psaddr, savepsaddr);
E 17
#ifndef EXTERNAL_SYNC
D 7
	if(psp->ps_refresh.state == AUTO_RF) {
		if(psp->ps_refresh.mode == SYNCING_RF) {
E 7
I 7
	if (psp->ps_refresh.state == AUTO_RF) {
D 11
		if (psp->ps_refresh.mode == SYNCING_RF) {
E 11
I 11
D 17
		if (psp->ps_refresh.mode == SYNCING_RF
					&& psp->ps_refresh.state != TIME_RF) {
E 17
I 17
		if (psp->ps_refresh.mode == SYNCING_RF &&
		    psp->ps_refresh.state != TIME_RF) {
E 17
E 11
E 7
D 16
			psrfnext(psp, psaddr);
E 16
I 16
			(void) psrfnext(psp, psaddr);
E 16
		} else {
D 17
			psp->ps_clock.ticked++;
			psp->ps_clock.missed++;
E 17
I 17
			psp->ps_clockticks++;
			psp->ps_clockmiss++;
E 17
		}
	}
#endif
D 17
	PSWAIT();
	psaddr->ps_addr = RTCREQ;
	PSWAIT();
	psaddr->ps_data = 01;		/* clear the request bits */
	RESTORPSADDR();
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_addr = RTCREQ;
	PSWAIT(psaddr); psaddr->ps_data = 01;	/* clear the request bits */
	RESTORPSADDR(psaddr, savepsaddr);
E 17
}

/*ARGSUSED*/
pssystemintr(dev)
	dev_t dev;
{
	register struct psdevice *psaddr =
D 17
			(struct psdevice *) psdinfo[PSUNIT(dev)]->ui_addr;
E 17
I 17
	    (struct psdevice *)psdinfo[PSUNIT(dev)]->ui_addr;
E 17
	register struct ps *psp = &ps[PSUNIT(dev)];
D 16
	short int request;
E 16
I 16
D 17
	short int request, tmp;
E 17
I 17
	short request, tmp;
E 17
E 16
	register int savepsaddr, x;

D 7
	if(!psp->ps_open)
E 7
I 7
	if (!psp->ps_open)
E 7
		return;
I 11
	psp->ps_icnt++;
E 11
D 17
	SAVEPSADDR();
	PSWAIT();
	psaddr->ps_addr = SYSREQ;
	PSWAIT();
D 11
	request = psaddr->ps_data;
E 11
I 11
D 16
	request = psaddr->ps_data&0377;
E 16
I 16
	request = psaddr->ps_data;
E 17
I 17
	SAVEPSADDR(psaddr, savepsaddr);
	PSWAIT(psaddr); psaddr->ps_addr = SYSREQ;
	PSWAIT(psaddr); request = psaddr->ps_data;
E 17
	request = request&0377;
D 17
	psp->last_request2 = psp->last_request;
E 16
E 11
	psp->last_request = request;
I 16
	if(request&(~(HALT_REQ|RFSTOP_REQ|HIT_REQ))) {
		psp->last_funnyrequest = request;
		psp->funny_cnt++;
E 17
I 17
	psp->ps_lastrequest2 = psp->ps_lastrequest;
	psp->ps_lastrequest = request;
	if (request &~ (HALT_REQ|RFSTOP_REQ|HIT_REQ)) {
		psp->ps_lastfunnyrequest = request;
		psp->ps_funnycnt++;
E 17
	}
E 16
D 17
	PSWAIT();
	psaddr->ps_addr = SYSREQ;
I 16
	tmp = request&(~(HALT_REQ|MOSTOP_REQ));   /* acknowledge */
E 16
	PSWAIT();
D 16
	psaddr->ps_data = request&(~(HALT_REQ|MOSTOP_REQ));   /* acknowledge */
E 16
I 16
	psaddr->ps_data = tmp;
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_addr = SYSREQ;
	tmp = request&(~(HALT_REQ|MOSTOP_REQ));	/* acknowledge */
	PSWAIT(psaddr); psaddr->ps_data = tmp;
E 17
E 16

D 7
	if(request & (MOSTOP_REQ|HALT_REQ)) {	/* Map stopped */
E 7
I 7
	if (request & (MOSTOP_REQ|HALT_REQ)) {	/* Map stopped */
E 7
		psp->ps_map.icnt++;
D 16
		psmapstop(psaddr);		/* kill it dead */
E 16
I 16
D 17
		psmapstop(psaddr, psp, request);	/* kill it dead */
E 17
I 17
		psmapstop(psaddr, psp, request);/* kill it dead */
E 17
E 16
D 7
		if(psp->ps_map.waiting) {
E 7
I 7
		if (psp->ps_map.waiting) {
E 7
			psp->ps_map.waiting = 0;
			wakeup(&psp->ps_map.waiting);
D 7
			if(psp->ps_map.stop) {
E 7
I 7
			if (psp->ps_map.stop) {
E 7
				psp->ps_map.stop = 0;
				goto tryrf;
			}
		}
D 7
		if(psp->ps_map.state == AUTO_MAP)
			if(!psmapnext(psp, psaddr)) {
E 7
I 7
D 16
		if (psp->ps_map.state == AUTO_MAP)
			if (!psmapnext(psp, psaddr)) {
E 7
				psp->ps_map.mcntr = 0;
				/* prepare for next round */
				pssetmapbounds(psp, psaddr);
D 7
				if(psp->ps_refresh.mode == WAITING_MAP) {
					if(psp->ps_dbuffer.state == ON_DB)
E 7
I 7
				if (psp->ps_refresh.mode == WAITING_MAP) {
E 16
I 16
D 17
		if((psp->ps_map.state==AUTO_MAP) && (!psmapnext(psp, psaddr))){
E 17
I 17
		if (psp->ps_map.state == AUTO_MAP && !psmapnext(psp, psaddr)) {
E 17
			psp->ps_map.mcntr = 0;
			/* prepare for next round */
			pssetmapbounds(psp, psaddr);
			if (psp->ps_refresh.state == AUTO_RF) {
D 17
				if(psp->ps_refresh.mode == WAITING_MAP){
E 17
I 17
				if (psp->ps_refresh.mode == WAITING_MAP){
E 17
E 16
					if (psp->ps_dbuffer.state == ON_DB)
E 7
						/* fill other db */
						psdbswitch(psp, psaddr);
					else
						psp->ps_map.mode = WAITING_RF;
D 16
					psrfnext(psp, psaddr);	/* start rf */
E 16
I 16
#ifdef EXTERNAL_SYNC
D 18
					x = spl6();
E 18
I 18
					x = splclock();
E 18
#endif
					(void) psrfnext(psp, psaddr);
#ifdef EXTERNAL_SYNC
					splx(x);
#endif
E 16
				} else
					psp->ps_map.mode = WAITING_RF;
I 16
			} else {	/* no auto refresh */
				if (psp->ps_dbuffer.state == ON_DB)
					/* fill other db */
					psdbswitch(psp, psaddr);
				else
					(void) psmapnext(psp, psaddr);
E 16
			}
I 16
		}
E 16
	}
tryrf:
D 7
	if(request & RFSTOP_REQ) {		/* Refresh stopped */
E 7
I 7
	if (request & RFSTOP_REQ) {		/* Refresh stopped */
E 7
		psp->ps_refresh.icnt++;
I 11
		if (psp->ps_refresh.state == TIME_RF)
D 17
			if(--psp->ps_refresh.timecnt > 0)
E 17
I 17
			if (--psp->ps_refresh.timecnt > 0)
E 17
				goto tryhit;
E 11
		psrfstop(psaddr, psp);
D 7
		if(psp->ps_refresh.waiting) {
E 7
I 7
		if (psp->ps_refresh.waiting) {
E 7
			psp->ps_refresh.waiting = 0;
			wakeup(&psp->ps_refresh.waiting);
D 7
			if(psp->ps_refresh.stop) {
E 7
I 7
			if (psp->ps_refresh.stop) {
E 7
				psp->ps_refresh.stop = 0;
				goto tryhit;
			}
		}
D 7
		if(psp->ps_refresh.state == AUTO_RF)
			if(!psrfnext(psp, psaddr)) {	/* at end of refresh cycle */
				if(psp->ps_map.state == AUTO_MAP && 
E 7
I 7
		if (psp->ps_refresh.state == AUTO_RF)
			if (!psrfnext(psp, psaddr)) {	/* at end of refresh cycle */
				if (psp->ps_map.state == AUTO_MAP && 
E 7
D 17
						psp->ps_map.mode==WAITING_RF) {
E 17
I 17
				    psp->ps_map.mode == WAITING_RF) {
E 17
D 7
					if(psp->ps_dbuffer.state == ON_DB)
E 7
I 7
					if (psp->ps_dbuffer.state == ON_DB)
E 7
						psdbswitch(psp, psaddr);
					else
D 16
						psmapnext(psp, psaddr);
E 16
I 16
						(void) psmapnext(psp, psaddr);
E 16
				}
				psp->ps_refresh.srcntr = 0;
#ifdef EXTERNAL_SYNC
D 18
				x = spl6();
E 18
I 18
				x = splclock();
E 18
#endif
D 7
				if(!psp->ps_clock.ticked ||
E 7
I 7
D 16
				if (!psp->ps_clock.ticked ||
E 7
						!psrfnext(psp, psaddr)) {
					psp->ps_refresh.mode = SYNCING_RF;
				}
				psp->ps_clock.ticked = 0;
E 16
				psp->ps_refresh.mode = SYNCING_RF;
I 16
D 17
				if (psp->ps_clock.ticked)
E 17
I 17
				if (psp->ps_clockticks)
E 17
					(void) psrfnext(psp, psaddr);
D 17
				psp->ps_clock.ticked = 0;
E 17
I 17
				psp->ps_clockticks = 0;
E 17
E 16
#ifdef EXTERNAL_SYNC
				splx(x);
#endif
			}
	}
tryhit:
D 7
	if(request & HIT_REQ) {		/* Hit request */
E 7
I 7
D 17
	if (request & HIT_REQ) {		/* Hit request */
E 7
		psp->ps_hit.icnt++;
	}
E 17
I 17
	if (request & HIT_REQ)			/* Hit request */
		psp->ps_hitcnt++;
E 17
D 7
	if(request == 0)
E 7
I 7
	if (request == 0)
E 7
		psp->ps_strayintr++;
D 17
	RESTORPSADDR();
E 17
I 17
	RESTORPSADDR(psaddr, savepsaddr);
E 17
}

psrfnext(psp, psaddr)
	register struct ps *psp;
	register struct psdevice *psaddr;
{
I 16
D 17
	unsigned short int start, last;
E 17
I 17
	u_short start, last;
E 17
E 16

D 7
	if(psp->ps_refresh.srcntr < psp->ps_refresh.nsraddrs)
E 7
I 7
D 17
	if (psp->ps_refresh.srcntr < psp->ps_refresh.nsraddrs)
E 17
I 17
	if (psp->ps_refresh.srcntr < psp->ps_refresh.nsraddrs) {
E 17
E 7
		psrfstart(psp->ps_refresh.sraddrs[psp->ps_refresh.srcntr++],
D 16
						psp, psaddr);
E 16
I 16
D 17
						0, psp, psaddr);
E 16
D 7
	else if(psp->ps_refresh.srcntr == psp->ps_refresh.nsraddrs
E 7
I 7
	else if (psp->ps_refresh.srcntr == psp->ps_refresh.nsraddrs
E 7
				&& psp->ps_dbuffer.state == ON_DB) {
E 17
I 17
		    0, psp, psaddr);
		return (1);
	}
	if (psp->ps_refresh.srcntr == psp->ps_refresh.nsraddrs &&
	    psp->ps_dbuffer.state == ON_DB) {
E 17
D 16
		psrfstart(psp->ps_dbuffer.dbaddrs[psp->ps_dbuffer.rbuffer],
						psp, psaddr);
E 16
I 16
		start = psp->ps_dbuffer.dbaddrs[psp->ps_dbuffer.rbuffer];
		last = start+psp->ps_dbuffer.dbsize;
		psrfstart(start, last, psp, psaddr);
E 16
		psp->ps_refresh.srcntr++;	/* flag for after dbuffer */
D 17
	} else
		return(0);
	return(1);
E 17
I 17
		return (1);
	}
	return (0);
E 17
}

D 16
psrfstart(dfaddr, psp, psaddr)
	short int dfaddr;
E 16
I 16
psrfstart(dfaddr, last, psp, psaddr)
D 17
	unsigned short int dfaddr, last;
E 17
I 17
	u_short dfaddr, last;
E 17
E 16
	register struct ps *psp;
	register struct psdevice *psaddr;
{
D 16
	int dummy;
E 16
I 16
D 17
	short int dummy;
E 17
I 17
	short dummy;
E 17
E 16

D 17
	PSWAIT();
	psaddr->ps_addr = RFASA;
	PSWAIT();
	psaddr->ps_data = dfaddr;
	PSWAIT();
D 16
	dummy = psaddr->ps_data;	/* just access to get to status reg */
E 16
I 16
	if(last != 0)
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_addr = RFASA;
	PSWAIT(psaddr); psaddr->ps_data = dfaddr;
	PSWAIT(psaddr);
	if (last != 0)
E 17
		psaddr->ps_data = last;
	else
		dummy = psaddr->ps_data;/* just access to get to status reg */
E 16
D 17
	PSWAIT();
	psaddr->ps_data = RFSTART;	/* may want to | this value in */
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_data = RFSTART;	/* may want | here */
E 17
	psp->ps_refresh.mode = RUNNING_RF;
}

I 16
/*ARGSUSED*/
E 16
psrfstop(psaddr, psp)
	register struct psdevice *psaddr;
	register struct ps *psp;
{

D 17
	PSWAIT();
	psaddr->ps_addr = RFSR;
	PSWAIT();
	psaddr->ps_data = 0;
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_addr = RFSR;
	PSWAIT(psaddr); psaddr->ps_data = 0;
E 17
}

psdbswitch(psp, psaddr)
	register struct ps *psp;
	register struct psdevice *psaddr;
{

	psp->ps_dbuffer.rbuffer = !psp->ps_dbuffer.rbuffer;
	pssetmapbounds(psp, psaddr);
D 16
	psmapnext(psp, psaddr);
E 16
I 16
	(void) psmapnext(psp, psaddr);
E 16
}

psmapnext(psp, psaddr)
	register struct ps *psp;
	register struct psdevice *psaddr;
{

D 7
	if(psp->ps_map.mcntr < psp->ps_map.nmaddrs)
E 7
I 7
D 17
	if (psp->ps_map.mcntr < psp->ps_map.nmaddrs)
E 7
		psmapstart(psp->ps_map.maddrs[psp->ps_map.mcntr++], psp, psaddr);
	else
		return(0);
	return(1);
E 17
I 17
	if (psp->ps_map.mcntr < psp->ps_map.nmaddrs) {
		psmapstart(psp->ps_map.maddrs[psp->ps_map.mcntr++],
		    psp, psaddr);
		return (1);
	}
	return (0);
E 17
}

pssetmapbounds(psp, psaddr)
	register struct ps *psp;
	register struct psdevice *psaddr;
{
D 16
	unsigned short int start;
E 16
I 16
D 17
	unsigned short int start, last;
E 17
I 17
	u_short start, last;
E 17
E 16

D 17
	PSWAIT();
	psaddr->ps_addr = MAOL;
	PSWAIT();
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_addr = MAOL;
	PSWAIT(psaddr);
E 17
D 7
	if(psp->ps_dbuffer.state == ON_DB) {
E 7
I 7
	if (psp->ps_dbuffer.state == ON_DB) {
E 7
D 16
		psaddr->ps_data = (start = psp->ps_dbuffer.dbaddrs[!psp->ps_dbuffer.rbuffer])
				+psp->ps_dbuffer.dbsize-2;   /* 2 for a refresh halt command */
E 16
I 16
		start = psp->ps_dbuffer.dbaddrs[!psp->ps_dbuffer.rbuffer];
		last = start+psp->ps_dbuffer.dbsize-2;   /* 2 for halt cmd */
		psaddr->ps_data = last;
E 16
D 17
		PSWAIT();
		psaddr->ps_data = start;
E 17
I 17
		PSWAIT(psaddr); psaddr->ps_data = start;
E 17
	} else {
		start = psaddr->ps_data;	/* dummy: don't update limit */
D 17
		PSWAIT();
		psaddr->ps_data = psp->ps_map.outputstart;
E 17
I 17
		PSWAIT(psaddr); psaddr->ps_data = psp->ps_map.outputstart;
E 17
	}
}

psmapstart(dfaddr, psp, psaddr)
D 16
	int dfaddr;
E 16
I 16
D 17
	unsigned short int dfaddr;
E 17
I 17
	u_short dfaddr;
E 17
E 16
	register struct ps *psp;
	register struct psdevice *psaddr;
{
D 16
	int data;
E 16

D 17
	PSWAIT();
	psaddr->ps_addr = MAIA;
	PSWAIT();
	psaddr->ps_data = dfaddr;
	PSWAIT();
	psaddr->ps_data = MAO|MAI;	/* may want more here */
E 17
I 17
	PSWAIT(psaddr); psaddr->ps_addr = MAIA;
	PSWAIT(psaddr); psaddr->ps_data = dfaddr;
	PSWAIT(psaddr); psaddr->ps_data = MAO|MAI;	/* may want more here */
E 17
	psp->ps_map.mode = RUNNING_MAP;
}

D 16
psmapstop(psaddr)
E 16
I 16
int pskillcnt = 1;

psmapstop(psaddr, psp, request)
E 16
	register struct psdevice *psaddr;
I 16
	register struct ps *psp;
D 17
	short int request;
E 17
I 17
	short request;
E 17
E 16
{
I 16
	register int i;
E 16

D 16
	PSWAIT();
	psaddr->ps_addr = MASR;
	PSWAIT();
	psaddr->ps_data = 0;	/* zero MAI bit */
	PSWAIT();
	psaddr->ps_addr = MAIA;
	PSWAIT();
	psaddr->ps_data = 0;	/* zero input address register */
	PSWAIT();
	psaddr->ps_addr = SYSREQ;
	PSWAIT();
	psaddr->ps_data = HALT_REQ|MOSTOP_REQ;	/* overkill?? */
E 16
I 16
D 17
	request = request&(HALT_REQ|MOSTOP_REQ); 	/* overkill?? */
	for(i = 0; i < pskillcnt; i++) {
		PSWAIT();
		psaddr->ps_addr = MASR;
		PSWAIT();
		psaddr->ps_data = IOUT;		/* zero MAI & MAO bits */
		PSWAIT();
		psaddr->ps_addr = MAIA;
		PSWAIT();
		psaddr->ps_data = 0;		/* 0 input address register */
		PSWAIT();
		psaddr->ps_addr = MAOA;
		PSWAIT();
		psaddr->ps_data = 0;		/* 0 output address register */
		PSWAIT();
		psaddr->ps_addr = SYSREQ;
		PSWAIT();
		psaddr->ps_data = request;
E 17
I 17
	request &= HALT_REQ|MOSTOP_REQ; 	/* overkill?? */
	for (i = 0; i < pskillcnt; i++) {
		PSWAIT(psaddr); psaddr->ps_addr = MASR;
		PSWAIT(psaddr); psaddr->ps_data = IOUT;	/* zero MAI & MAO */
		PSWAIT(psaddr); psaddr->ps_addr = MAIA;
		PSWAIT(psaddr); psaddr->ps_data = 0;	/* 0 input addr reg */
		PSWAIT(psaddr); psaddr->ps_addr = MAOA;
		PSWAIT(psaddr); psaddr->ps_data = 0;	/* 0 output addr reg */
		PSWAIT(psaddr); psaddr->ps_addr = SYSREQ;
		PSWAIT(psaddr); psaddr->ps_data = request;
E 17
	}
	psp->ps_map.mode = STOPPED_MAP;
E 16
}

/*ARGSUSED*/
psdeviceintr(dev)
	dev_t dev;
{

	printf("ps device intr\n");
}

/*ARGSUSED*/
psdmaintr(dev)
	dev_t dev;
{

	printf("ps dma intr\n");
}

I 16
/*ARGSUSED*/
E 16
psreset(uban)
	int uban;
{
I 17

E 17
}

I 16
/*ARGSUSED*/
E 16
D 17
psextsync(PC, PS) {
E 17
I 17
psextsync(PC, PS)
{
E 17
	register int n;
	register struct psdevice *psaddr;
	register struct ps *psp;
	register int savepsaddr;

#ifdef EXTERNAL_SYNC
D 7
	for(psp = ps, n = 0; n < NPS; psp++, n++) {
		if(!psp->ps_open)
E 7
I 7
	for (psp = ps, n = 0; n < NPS; psp++, n++) {
		if (!psp->ps_open)
E 7
			continue;
D 7
		if(psp->ps_refresh.mode == SYNCING_RF) {
E 7
I 7
D 11
		if (psp->ps_refresh.mode == SYNCING_RF) {
E 11
I 11
D 17
		if(psp->ps_refresh.mode == SYNCING_RF
					&& psp->ps_refresh.state != TIME_RF) {
E 11
E 7
			psaddr = (struct psdevice *) psdinfo[n]->ui_addr;
			SAVEPSADDR();
E 17
I 17
		if (psp->ps_refresh.mode == SYNCING_RF &&
		    psp->ps_refresh.state != TIME_RF) {
			psaddr = (struct psdevice *)psdinfo[n]->ui_addr;
			SAVEPSADDR(psaddr, savepsaddr);
E 17
D 16
			psrfnext(psp, psaddr);
E 16
I 16
			(void) psrfnext(psp, psaddr);
E 16
D 17
			RESTORPSADDR();
E 17
I 17
			RESTORPSADDR(psaddr, savepsaddr);
E 17
		} else {
D 17
			psp->ps_clock.ticked++;
			psp->ps_clock.missed++;
E 17
I 17
			psp->ps_clockticks++;
			psp->ps_clockmiss++;
E 17
		}
	}
#endif
}
#endif
E 1
