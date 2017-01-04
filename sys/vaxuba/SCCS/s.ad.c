h57373
s 00003/00002/00169
d D 7.2 87/05/12 10:22:51 mckusick 13 12
c fixes from Bill Vaughn (ur-cvsvax!bill@cs.rochester.edu)
e
s 00001/00001/00170
d D 7.1 86/06/05 01:05:05 mckusick 12 11
c 4.3BSD release version
e
s 00007/00001/00164
d D 6.3 85/06/08 14:13:06 mckusick 11 10
c Add copyright
e
s 00009/00009/00156
d D 6.2 84/08/29 20:07:58 bloom 10 9
c Change to includes.  No more ../h
e
s 00000/00000/00165
d D 6.1 83/07/29 07:26:52 sam 9 8
c 4.2 distribution
e
s 00002/00001/00163
d D 4.7 82/12/17 12:01:06 sam 8 7
c sun merge
e
s 00012/00010/00152
d D 4.6 82/10/17 11:47:57 root 7 6
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00004/00003/00158
d D 4.5 82/10/10 17:26:07 root 6 5
c header files for vax are in their place
e
s 00000/00000/00161
d D 4.4 82/08/22 21:16:34 root 5 4
c fully uio()'d
e
s 00007/00008/00154
d D 4.3 82/08/01 19:24:12 sam 4 3
c new ioctl's
e
s 00001/00000/00161
d D 4.2 82/07/15 20:01:58 kre 3 1
c probe routines return size of unibus dev regs to reserve space
e
s 00001/00001/00160
d R 4.2 82/06/26 16:10:40 sam 2 1
c sorry bill, but noone gets blamed for anything around here
e
s 00161/00000/00000
d D 4.1 82/06/26 16:08:49 sam 1 0
c date and time created 82/06/26 16:08:49 by sam
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11

#include "ad.h"
#if NAD > 0
/*
 * Data translation AD converter interface -- Bill Reeves
 */
I 8
#include "../machine/pte.h"

E 8
D 10
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/systm.h"
#include "../h/map.h"
E 10
I 10
#include "param.h"
I 13
#include "ioctl.h"
E 13
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "systm.h"
#include "map.h"
E 10
D 8
#include "../h/pte.h"
E 8
D 6
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/adreg.h"
E 6
I 6

D 10
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/adreg.h"
E 10
I 10
#include "ubareg.h"
#include "ubavar.h"
#include "adreg.h"
E 10
E 6

#define ADBUSY 01
#define ADWAITPRI (PZERO+1)

int adprobe(), adattach();
struct uba_device *addinfo[NAD];
u_short adstd[] = { 0770400, 0000000, 0 };
struct uba_driver addriver =
	{ adprobe, 0, adattach, 0, adstd, "ad", addinfo, 0, 0 };

struct ad {
	char	ad_open;
	short int ad_uid;
	short int ad_state;
	short int ad_softcsr;
	short int ad_softdata;
	short int ad_chan;
	int	ad_icnt;
	int	ad_loop;
} ad[NAD];

#define ADUNIT(dev) (minor(dev))

adprobe(reg)
	caddr_t reg;
{
D 7
	register int br, cvec;
E 7
I 7
	register int br, cvec;		/* value-result */
E 7
	register struct addevice *adaddr = (struct addevice *) reg;

	adaddr->ad_csr = AD_IENABLE | AD_START;
	DELAY(40000);
	adaddr->ad_csr = 0;
I 3
	return (sizeof (struct addevice));
E 3
}

I 7
/*ARGSUSED*/
E 7
adattach(ui)
	struct uba_device *ui;
{
I 7

E 7
}

adopen(dev)
	dev_t dev;
{
	register struct ad *adp;
	register struct uba_device *ui;

D 7
	if(ADUNIT(dev) >= NAD || (adp = &ad[ADUNIT(dev)])->ad_open ||
		(ui = addinfo[ADUNIT(dev)]) == 0 || ui->ui_alive == 0) {
			u.u_error = ENXIO;
			return;
	}
E 7
I 7
	if (ADUNIT(dev) >= NAD || (adp = &ad[ADUNIT(dev)])->ad_open ||
	    (ui = addinfo[ADUNIT(dev)]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
E 7
	adp->ad_open = 1;
	adp->ad_icnt = 0;
	adp->ad_state = 0;
	adp->ad_uid = u.u_uid;
I 7
	return (0);
E 7
}

adclose(dev)
	dev_t dev;
{

	ad[ADUNIT(dev)].ad_open = 0;
	ad[ADUNIT(dev)].ad_state = 0;
}

/*ARGSUSED*/
adioctl(dev, cmd, addr, flag)
	dev_t dev;
	register caddr_t addr;
{
	register struct addevice *adaddr =
D 7
			(struct addevice *) addinfo[ADUNIT(dev)]->ui_addr;
E 7
I 7
	    (struct addevice *) addinfo[ADUNIT(dev)]->ui_addr;
E 7
	register struct uba_device *ui = addinfo[ADUNIT(dev)];
	register struct ad *adp;
	register int i;
	short int chan;

	switch (cmd) {
D 4
	case AD_CHAN:
E 4
I 4

	case ADIOSCHAN:
E 4
		adp = &ad[ADUNIT(dev)];
D 4
		chan  = fuword(addr);
		if(chan == -1)
			u.u_error = EFAULT;
		else
			adp->ad_chan = chan<<8;
E 4
I 4
D 13
		adp->ad_chan = (*(int *)data)<<8;
E 13
I 13
		adp->ad_chan = (*(int *)addr)<<8;
E 13
E 4
		break;
D 4
	case AD_READ:
E 4
I 4

	case ADIOGETW:
E 4
		adp = &ad[ADUNIT(dev)];
		spl6();
		adaddr->ad_csr = adp->ad_chan;
		i = 1000;
D 7
		while(i-- > 0 && (adaddr->ad_csr&037400) != adp->ad_chan) {
E 7
I 7
		while (i-- > 0 && (adaddr->ad_csr&037400) != adp->ad_chan) {
E 7
			adp->ad_loop++;
			adaddr->ad_csr = adp->ad_chan;
		}
		adp->ad_state |= ADBUSY;
		adaddr->ad_csr |= AD_IENABLE|AD_START;
D 7
		while(adp->ad_state&ADBUSY)
E 7
I 7
		while (adp->ad_state&ADBUSY)
E 7
			sleep((caddr_t)adp, ADWAITPRI);
		spl0();
D 4
		(void) suword(addr, adp->ad_softdata);
E 4
I 4
D 13
		*(int *)data = adp->ad_softdata;
E 13
I 13
		*(int *)addr = adp->ad_softdata;
E 13
E 4
		break;
I 4

E 4
	default:
D 7
		u.u_error = ENOTTY;	/* Not a legal ioctl cmd. */
E 7
I 7
		return (ENOTTY);	/* Not a legal ioctl cmd. */
E 7
	}
I 7
	return (0);
E 7
}

/*ARGSUSED*/
adintr(dev)
	dev_t dev;
{
	register struct addevice *adaddr =
			(struct addevice *) addinfo[ADUNIT(dev)]->ui_addr;
	register struct ad *adp = &ad[ADUNIT(dev)];

	adp->ad_icnt++;
	adp->ad_softcsr = adaddr->ad_csr;
	adp->ad_softdata = adaddr->ad_data;
	if(adp->ad_state&ADBUSY) {
		adp->ad_state &= ~ADBUSY;
		wakeup((caddr_t)adp);
	}
}

adreset(uban)
	int uban;
{
	register int i;
	register struct uba_device *ui;
	register struct ad *adp = ad;
	register struct addevice *adaddr;

	for(i = 0; i < NAD; i++, adp++) {
		if((ui = addinfo[i]) == 0 || ui->ui_alive == 0 ||
				ui->ui_ubanum != uban || adp->ad_open == 0)
			continue;
		printf(" ad%d", i);
		if(adp->ad_state&ADBUSY == 0)
			continue;
		adaddr = (struct addevice *) ui->ui_addr;
		adaddr->ad_csr = 0;
		adaddr->ad_csr = adp->ad_chan|AD_IENABLE|AD_START;
	}
}
#endif
E 1
