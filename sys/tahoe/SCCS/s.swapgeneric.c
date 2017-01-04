h45969
s 00001/00002/00139
d D 7.2 88/06/07 10:08:40 karels 11 10
c don't reset unit after computing
e
s 00000/00000/00141
d D 7.1 88/05/22 14:00:16 karels 10 9
c bring up to level 7 for tahoe release
e
s 00012/00006/00129
d D 1.7 88/05/22 13:59:50 karels 9 7
c one too many
e
s 00012/00007/00128
d R 7.1 88/05/21 18:36:24 karels 8 7
c bring up to revision 7 for tahoe release
e
s 00012/00012/00123
d D 1.6 88/02/08 13:41:22 karels 7 6
c accept unit numbers > 7 
e
s 00002/00029/00133
d D 1.5 86/11/25 16:44:47 sam 6 5
c getchar moved to cons.c for kdb; make rootdev initialized
e
s 00003/00001/00159
d D 1.4 86/11/16 19:26:33 sam 5 3
c missing label; add cpu.h for uncache
e
s 00002/00001/00159
d R 1.4 86/11/16 19:23:19 sam 4 3
c missing label
e
s 00018/00012/00142
d D 1.3 86/07/16 08:28:34 sam 3 2
c disk name changes; accept del as erase char
e
s 00019/00018/00135
d D 1.2 86/01/05 18:42:42 sam 2 1
c 1st working version
e
s 00153/00000/00000
d D 1.1 85/07/21 20:20:55 sam 1 0
c date and time created 85/07/21 20:20:55 by sam
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

D 9
#include "../machine/pte.h"

E 9
D 2
#include "../h/param.h"
#include "../h/conf.h"
#include "../h/buf.h"
#include "../h/vm.h"
#include "../h/systm.h"
#include "../h/reboot.h"
E 2
I 2
#include "param.h"
#include "conf.h"
#include "buf.h"
#include "vm.h"
#include "systm.h"
#include "reboot.h"
E 2

I 5
D 9
#include "../tahoe/cpu.h"
E 5
D 2
#include "../machine/cp.h"
#include "../machine/mtpr.h"
#include "../vba/vbavar.h"
E 2
I 2
#include "../tahoe/cp.h"
#include "../tahoe/mtpr.h"
E 9
I 9
#include "pte.h"
#include "cpu.h"
#include "cp.h"
#include "mtpr.h"

E 9
#include "../tahoevba/vbavar.h"
E 2

/*
 * Generic configuration;  all in one
 */
D 3
dev_t	rootdev, argdev, dumpdev;
E 3
I 3
D 6
dev_t	rootdev;
E 6
I 6
dev_t	rootdev = NODEV;
E 6
dev_t	argdev = NODEV;
dev_t	dumpdev = NODEV;
E 3
int	nswap;
struct	swdevt swdevt[] = {
	{ -1,	1,	0 },
	{ 0,	0,	0 },
};
long	dumplo;
int	dmmin, dmmax, dmtext;

extern	struct vba_driver vddriver;

struct	genericconf {
	caddr_t	gc_driver;
	char	*gc_name;
	dev_t	gc_root;
} genericconf[] = {
D 3
	{ (caddr_t)&vddriver,	"fsd",	makedev(1, 0),	},
	{ (caddr_t)&vddriver,	"smd",	makedev(1, 0),	},
	{ (caddr_t)&vddriver,	"xfd",	makedev(1, 0),	},
I 2
	{ (caddr_t)&vddriver,	"xsd",	makedev(1, 0),	},
E 3
I 3
	{ (caddr_t)&vddriver,	"dk",	makedev(1, 0),	},
E 3
E 2
	{ 0 },
};

setconf()
{
	register struct vba_device *ui;
	register struct genericconf *gc;
I 7
	register char *cp;
E 7
	int unit, swaponroot = 0;

I 3
	if (rootdev != NODEV)
D 5
		goto noswap;
E 5
I 5
		goto doswap;
I 11
	unit = 0;
E 11
E 5
E 3
	if (boothowto & RB_ASKNAME) {
		char name[128];
retry:
		printf("root device? ");
		gets(name);
		for (gc = genericconf; gc->gc_driver; gc++)
			if (gc->gc_name[0] == name[0] &&
D 3
			    gc->gc_name[1] == name[1] &&
			    gc->gc_name[2] == name[2])
E 3
I 3
			    gc->gc_name[1] == name[1])
E 3
				goto gotit;
D 7
		goto bad;
gotit:
D 3
		if (name[4] == '*') {
			name[4] = name[5];
E 3
I 3
		if (name[3] == '*') {
			name[3] = name[4];
E 3
			swaponroot++;
		}
D 3
		if (name[3] >= '0' && name[3] <= '7' && name[4] == 0) {
			unit = name[3] - '0';
E 3
I 3
		if (name[2] >= '0' && name[2] <= '7' && name[3] == 0) {
			unit = name[2] - '0';
E 3
			goto found;
		}
		printf("bad/missing unit number\n");
bad:
E 7
D 2
		printf("use fsd%%d, smd%%d, or xfd%%d\n");
E 2
I 2
D 3
		printf("use fsd%%d, smd%%d, xfd%%d, or xsd%%d\n");
E 3
I 3
		printf("use dk%%d\n");
E 3
E 2
		goto retry;
I 7
gotit:
		cp = name + 2;
		if (*cp < '0' || *cp > '9') {
			printf("bad/missing unit number\n");
			goto retry;
		}
D 11
		unit = 0;
E 11
		while (*cp >= '0' && *cp <= '9')
			unit = 10 * unit + *cp++ - '0';
		if (*cp == '*')
			swaponroot++;
E 7
	}
D 11
	unit = 0;
E 11
	for (gc = genericconf; gc->gc_driver; gc++) {
		for (ui = vbdinit; ui->ui_driver; ui++) {
			if (ui->ui_alive == 0)
				continue;
			if (ui->ui_unit == 0 && ui->ui_driver ==
			    (struct vba_driver *)gc->gc_driver) {
				printf("root on %s0\n",
				    ui->ui_driver->ud_dname);
				goto found;
			}
		}
	}
	printf("no suitable root\n");
	asm("halt");
found:
	gc->gc_root = makedev(major(gc->gc_root), unit*8);
	rootdev = gc->gc_root;
I 5
doswap:
E 5
	swdevt[0].sw_dev = argdev = dumpdev =
	    makedev(major(rootdev), minor(rootdev)+1);
	/* swap size and dumplo set during autoconfigure */
	if (swaponroot)
		rootdev = dumpdev;
}

D 6
getchar()
{
D 2
	char	c;
E 2
I 2
	char c;
E 2
	int timo;
D 2
	extern struct	cpdcb_i consin[];
	extern struct	cphdr *lasthdr;
E 2
I 2
	extern struct cpdcb_i consin[];
	extern struct cphdr *lasthdr;
E 2
#define cpin consin[CPCONS]

	timo = 10000;
	uncache((char *)&lasthdr->cp_unit);
D 2
	while ((lasthdr->cp_unit & CPTAKE)==0 && --timo )
		uncache((char *)&lasthdr->cp_unit);
E 2
I 2
	while ((lasthdr->cp_unit&CPTAKE) == 0 && --timo)
		uncache(&lasthdr->cp_unit);
E 2
	cpin.cp_hdr.cp_unit = CPCONS;	/* Resets done bit */
	cpin.cp_hdr.cp_comm = CPREAD;
	cpin.cp_hdr.cp_count = 1;
D 2
	mtpr(&cpin, CPMDCB);
E 2
I 2
	mtpr(CPMDCB, &cpin);
E 2
	while ((cpin.cp_hdr.cp_unit & CPDONE) == 0) 
D 2
		uncache (&cpin.cp_hdr.cp_unit);
	uncache (&cpin.cpi_buf[0]);
E 2
I 2
		uncache(&cpin.cp_hdr.cp_unit);
	uncache(&cpin.cpi_buf[0]);
E 2
	c = cpin.cpi_buf[0] & 0x7f;
	lasthdr = (struct cphdr *)&cpin;
	if (c == '\r')
		c = '\n';
	printf("%c", c);	/* takes care of interrupts & parity */
	return (c);
}

E 6
gets(cp)
	char *cp;
{
	register char *lp;
	register c;

	lp = cp;
	for (;;) {
D 6
		c = getchar() & 0177;
E 6
I 6
		printf("%c", c = cngetc()&0177);
E 6
		switch (c) {
		case '\n':
		case '\r':
			*lp++ = '\0';
			return;
		case '\b':
I 3
		case '\177':
			if (lp > cp) {
				printf(" \b");
				lp--;
			}
			continue;
E 3
		case '#':
			lp--;
			if (lp < cp)
				lp = cp;
			continue;
		case '@':
		case 'u'&037:
			lp = cp;
			printf("%c", '\n');
			continue;
		default:
			*lp++ = c;
		}
	}
}
E 1
