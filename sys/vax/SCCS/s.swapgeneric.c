h57591
s 00010/00000/00168
d D 7.10 04/03/06 22:46:53 msokolov 25 24
c kdb is now a pnexus device
e
s 00006/00006/00162
d D 7.9 90/12/01 14:27:50 karels 24 23
c check/print unit other than 0
e
s 00003/00002/00165
d D 7.8 89/02/07 20:35:41 tef 23 22
c 3rd try for mike and tom to get this right; this time it's been tested
e
s 00001/00001/00166
d D 7.7 88/12/12 13:03:02 karels 22 21
c one increment per loop
e
s 00002/00002/00165
d D 7.6 88/08/31 10:22:27 tef 21 20
c tish, tish.  mike never tested his previous changes.
e
s 00001/00002/00166
d D 7.5 88/06/07 10:07:50 karels 20 19
c don't reset unit after computing
e
s 00011/00005/00157
d D 7.4 88/05/07 14:20:19 karels 19 18
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00012/00012/00150
d D 7.3 88/02/08 13:41:12 karels 18 17
c accept unit numbers > 7
e
s 00001/00014/00161
d D 7.2 87/02/21 11:19:12 karels 17 16
c kdb (for sam; untested); misc.
e
s 00001/00001/00174
d D 7.1 86/06/06 19:19:35 karels 16 15
c 4.3BSD release version
e
s 00004/00001/00171
d D 6.5 86/06/06 19:18:44 karels 15 13
c need to set swap even if setroot works on generic
e
s 00001/00001/00171
d R 7.1 86/06/05 00:48:05 mckusick 14 13
c 4.3BSD release version
e
s 00005/00001/00167
d D 6.4 85/09/16 17:51:23 karels 13 12
c initialize devs (esp. dumpdev) to NODEV to avoid accidents on hp0a;
c might as well let DEL erase here too
e
s 00007/00001/00161
d D 6.3 85/06/08 13:46:01 mckusick 12 11
c Add copyright
e
s 00009/00009/00153
d D 6.2 84/08/28 18:10:39 bloom 11 10
c Change to includes.  No more ../h
e
s 00000/00000/00162
d D 6.1 83/08/05 17:58:28 sam 10 9
c 4.2 distribution
e
s 00002/00001/00160
d D 4.8 83/08/05 17:57:37 sam 9 7
c make rl really rl instead of just the rl02 on the idc
e
s 00000/00000/00161
d R 6.1 83/07/29 07:21:15 sam 8 7
c 4.2 distribution
e
s 00008/00016/00153
d D 4.7 83/05/18 05:58:49 sam 7 6
c purge swap config stuff now that swapconf does this
e
s 00025/00019/00144
d D 4.6 83/05/18 02:10:02 sam 6 5
c support multiple variable sized swap areas (some from shannon)
e
s 00002/00001/00161
d D 4.5 82/12/17 11:56:47 sam 5 4
c sun merge
e
s 00009/00007/00153
d D 4.4 82/10/17 23:08:32 root 4 3
c fix includes
e
s 00010/00004/00150
d D 4.3 82/10/17 20:23:29 root 3 2
c * for new bootstrap procedure; no argdev
e
s 00005/00002/00149
d D 4.2 82/05/27 16:35:29 sam 2 1
c add idc
e
s 00151/00000/00000
d D 4.1 82/05/27 16:30:56 sam 1 0
c date and time created 82/05/27 16:30:56 by sam
e
u
U
t
T
I 1
D 2
/*	swapgeneric.c	4.12	81/12/03	*/
E 2
I 2
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
D 4
/*	swapgeneric.c	4.2	82/05/27	*/
E 4
I 4
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 16
 * Copyright (c) 1982 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12
E 4
E 3
E 2

#include "mba.h"

I 5
D 11
#include "../machine/pte.h"
E 11
I 11
#include "pte.h"
E 11

E 5
D 11
#include "../h/param.h"
#include "../h/conf.h"
D 5
#include "../h/pte.h"
E 5
#include "../h/buf.h"
D 4
#include "../h/mbareg.h"
#include "../h/mbavar.h"
E 4
#include "../h/vm.h"
D 4
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 4
#include "../h/systm.h"
#include "../h/reboot.h"
E 11
I 11
#include "param.h"
#include "conf.h"
#include "buf.h"
#include "vm.h"
#include "systm.h"
#include "reboot.h"
E 11
D 4
#include "../h/cons.h"
#include "../h/mtpr.h"
E 4
I 4

D 11
#include "../vax/cons.h"
#include "../vax/mtpr.h"
E 11
I 11
#include "cons.h"
#include "mtpr.h"
E 11
#include "../vaxmba/mbareg.h"
#include "../vaxmba/mbavar.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"

E 4
/*
 * Generic configuration;  all in one
 */
D 3
dev_t	rootdev, pipedev, argdev, dumpdev;
E 3
I 3
D 13
dev_t	rootdev, argdev, dumpdev;
E 13
I 13
D 15
dev_t	rootdev;
E 15
I 15
dev_t	rootdev = NODEV;
E 15
dev_t	argdev = NODEV;
dev_t	dumpdev = NODEV;
E 13
E 3
int	nswap;
D 6
struct	swdevt swdevt[] =
{
	-1,	1,
	0,	0,
E 6
I 6
struct	swdevt swdevt[] = {
	{ -1,	1,	0 },
	{ 0,	0,	0 },
E 6
};
long	dumplo;
I 7
int	dmmin, dmmax, dmtext;
E 7

I 6
D 7
int	dmmin = 32;
int	dmmax;
int	dmtext;

E 7
E 6
extern	struct mba_driver hpdriver;
extern	struct uba_driver scdriver;
extern	struct uba_driver hkdriver;
I 2
extern	struct uba_driver idcdriver;
I 9
extern	struct uba_driver hldriver;
E 9
E 2
extern	struct uba_driver udadriver;
I 19
extern	struct uba_driver kdbdriver;
E 19

struct	genericconf {
	caddr_t	gc_driver;
	char	*gc_name;
	dev_t	gc_root;
D 7
	long	gc_nswap;
D 6
	long	gc_dumplo;
E 6
I 6
	long	gc_dumpsize;
E 7
E 6
} genericconf[] = {
D 6
   (caddr_t)&hpdriver,	"hp", makedev(0, 0), 33440, 33440 - 10*2048,
   (caddr_t)&scdriver,	"up", makedev(2, 0), 33440, 33440 - 10*2048,
   (caddr_t)&udadriver,	"ra", makedev(9, 0), 33440, 33440 - 10*2048,
I 2
   (caddr_t)&idcdriver, "rb", makedev(11, 0),33440, 33440 - 10*2048,
   (caddr_t)&idcdriver, "rl", makedev(11, 0), 4480, 0,
E 2
   (caddr_t)&hkdriver,	"hk", makedev(3, 0), 10032, 10032 - 2*(2048+1024),
   0,
E 6
I 6
D 7
	{ (caddr_t)&hpdriver,	"hp",	makedev(0, 0),	33440,	10*2048 },
	{ (caddr_t)&scdriver,	"up",	makedev(2, 0),	33440,	10*2048 },
	{ (caddr_t)&udadriver,	"ra",	makedev(9, 0),	33440,	10*2048 },
	{ (caddr_t)&idcdriver,	"rb",	makedev(11, 0),	33440,	10*2048 },
	{ (caddr_t)&idcdriver,	"rl",	makedev(11, 0),	4480,	0 },
	{ (caddr_t)&hkdriver,	"hk",	makedev(3, 0),	10032,	2*(2048+1024) },
E 7
I 7
	{ (caddr_t)&hpdriver,	"hp",	makedev(0, 0),	},
	{ (caddr_t)&scdriver,	"up",	makedev(2, 0),	},
	{ (caddr_t)&udadriver,	"ra",	makedev(9, 0),	},
	{ (caddr_t)&idcdriver,	"rb",	makedev(11, 0),	},
D 9
	{ (caddr_t)&idcdriver,	"rl",	makedev(11, 0),	},
E 9
I 9
	{ (caddr_t)&hldriver,	"rl",	makedev(14, 0),	},
E 9
	{ (caddr_t)&hkdriver,	"hk",	makedev(3, 0),	},
I 13
	{ (caddr_t)&hkdriver,	"rk",	makedev(3, 0),	},
I 19
	{ (caddr_t)&kdbdriver,	"kra",	makedev(16, 0), },
E 19
E 13
E 7
	{ 0 },
E 6
};

setconf()
{
I 19
#if NMBA > 0
E 19
	register struct mba_device *mi;
I 19
#endif
E 19
	register struct uba_device *ui;
	register struct genericconf *gc;
I 18
D 19
	register char *cp;
E 19
I 19
	register char *cp, *gp;
E 19
E 18
D 3
	int unit;
E 3
I 3
	int unit, swaponroot = 0;
E 3

I 15
	if (rootdev != NODEV)
		goto doswap;
I 20
	unit = 0;
E 20
E 15
	if (boothowto & RB_ASKNAME) {
		char name[128];
retry:
		printf("root device? ");
		gets(name);
		for (gc = genericconf; gc->gc_driver; gc++)
D 19
			if (gc->gc_name[0] == name[0] &&
			    gc->gc_name[1] == name[1])
E 19
I 19
D 23
		    for (cp = name, gp = gc->gc_name; *cp == *gp; cp++, gp++)
D 21
			if (*gp == 0)
E 21
I 21
D 22
			if (*++gp == 0)
E 22
I 22
			if (*gp == 0)
E 23
I 23
		    for (cp = name, gp = gc->gc_name; *cp == *gp; cp++)
			if (*++gp == 0)
E 23
E 22
E 21
E 19
				goto gotit;
D 18
		goto bad;
gotit:
I 3
		if (name[3] == '*') {
			name[3] = name[4];
			swaponroot++;
		}
E 3
		if (name[2] >= '0' && name[2] <= '7' && name[3] == 0) {
			unit = name[2] - '0';
			goto found;
		}
		printf("bad/missing unit number\n");
bad:
E 18
D 2
		printf("use hp%%d, up%%d, ra%%d or hk%%d\n");
E 2
I 2
D 19
		printf("use hp%%d, up%%d, ra%%d, rb%%d, rl%%d or hk%%d\n");
E 19
I 19
		printf(
		  "use hp%%d, up%%d, ra%%d, rb%%d, rl%%d, hk%%d or kra%%d\n");
E 19
E 2
		goto retry;
I 18
gotit:
D 19
		cp = name + 2;
E 19
D 21
		if (*cp < '0' || *cp > '9') {
E 21
I 21
		if (*++cp < '0' || *cp > '9') {
E 21
			printf("bad/missing unit number\n");
			goto retry;
		}
D 20
		unit = 0;
E 20
		while (*cp >= '0' && *cp <= '9')
			unit = 10 * unit + *cp++ - '0';
		if (*cp == '*')
			swaponroot++;
I 23
		goto found;
E 23
E 18
	}
D 20
	unit = 0;
E 20
	for (gc = genericconf; gc->gc_driver; gc++) {
I 19
#if NMBA > 0
E 19
		for (mi = mbdinit; mi->mi_driver; mi++) {
			if (mi->mi_alive == 0)
				continue;
D 24
			if (mi->mi_unit == 0 && mi->mi_driver ==
E 24
I 24
			if (mi->mi_unit == unit && mi->mi_driver ==
E 24
			    (struct mba_driver *)gc->gc_driver) {
D 6
				printf("root on %s0\n", mi->mi_driver->md_dname);
E 6
I 6
D 24
				printf("root on %s0\n",
				    mi->mi_driver->md_dname);
E 24
I 24
				printf("root on %s%d\n",
				    mi->mi_driver->md_dname, unit);
E 24
E 6
				goto found;
			}
		}
I 19
#endif
E 19
		for (ui = ubdinit; ui->ui_driver; ui++) {
			if (ui->ui_alive == 0)
				continue;
D 24
			if (ui->ui_unit == 0 && ui->ui_driver ==
E 24
I 24
			if (ui->ui_unit == unit && ui->ui_driver ==
E 24
			    (struct uba_driver *)gc->gc_driver) {
D 24
				printf("root on %s0\n",
				    ui->ui_driver->ud_dname);
E 24
I 24
				printf("root on %s%d\n",
				    ui->ui_driver->ud_dname, unit);
E 24
				goto found;
			}
		}
I 25
		for (ui = pnexdinit; ui->ui_driver; ui++) {
			if (ui->ui_alive == 0)
				continue;
			if (ui->ui_unit == unit && ui->ui_driver ==
			    (struct uba_driver *)gc->gc_driver) {
				printf("root on %s%d\n",
				    ui->ui_driver->ud_dname, unit);
				goto found;
			}
		}
E 25
	}
	printf("no suitable root\n");
	asm("halt");
found:
	gc->gc_root = makedev(major(gc->gc_root), unit*8);
D 3
	rootdev = pipedev = gc->gc_root;
E 3
I 3
	rootdev = gc->gc_root;
I 15
doswap:
E 15
E 3
	swdevt[0].sw_dev = argdev = dumpdev =
	    makedev(major(rootdev), minor(rootdev)+1);
D 6
	nswap = gc->gc_nswap;
	dumplo = gc->gc_dumplo;
E 6
I 6
D 7
	swdevt[0].sw_nblks = gc->gc_nswap;
	dumplo = gc->gc_nswap - gc->gc_dumpsize;
	if (dumplo < 0)
		dumplo = 0;
E 7
I 7
	/* swap size and dumplo set during autoconfigure */
E 7
E 6
I 3
	if (swaponroot)
		rootdev = dumpdev;
E 3
}

D 17
getchar()
{
	register c;

D 6
	while((mfpr(RXCS)&RXCS_DONE) == 0)
E 6
I 6
	while ((mfpr(RXCS)&RXCS_DONE) == 0)
E 6
		;
	c = mfpr(RXDB)&0177;
D 6
	if (c=='\r')
E 6
I 6
	if (c == '\r')
E 6
		c = '\n';
	cnputc(c);
D 6
	return(c);
E 6
I 6
	return (c);
E 6
}

E 17
gets(cp)
	char *cp;
{
	register char *lp;
	register c;

	lp = cp;
	for (;;) {
D 17
		c = getchar() & 0177;
E 17
I 17
		cnputc(c = cngetc());
E 17
D 6
		switch(c) {
E 6
I 6
		switch (c) {
E 6
		case '\n':
		case '\r':
			*lp++ = '\0';
			return;
		case '\b':
		case '#':
I 13
		case '\177':
E 13
			lp--;
			if (lp < cp)
				lp = cp;
			continue;
		case '@':
		case 'u'&037:
			lp = cp;
			cnputc('\n');
			continue;
		default:
			*lp++ = c;
		}
	}
}
E 1
