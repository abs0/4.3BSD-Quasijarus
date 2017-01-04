h11723
s 00002/00002/00087
d D 7.4 88/05/27 15:50:19 karels 12 11
c unbreak compat code, allow formatter to open unformatted disk
e
s 00034/00012/00055
d D 7.3 88/03/04 13:54:14 bostic 11 10
c set up a minimal disklabel from st structure
e
s 00005/00005/00062
d D 7.2 88/01/28 20:53:35 karels 10 9
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00066
d D 7.1 86/06/05 01:47:45 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00060
d D 6.3 85/06/08 13:14:01 mckusick 8 7
c Add copyright
e
s 00006/00004/00055
d D 6.2 85/05/17 09:44:40 bloom 7 6
c add support for eagle on emulex sc31
e
s 00000/00000/00059
d D 6.1 83/07/29 07:48:11 sam 6 5
c 4.2 distribution
e
s 00002/00000/00057
d D 4.5 83/07/20 23:06:28 sam 5 4
c add dm980 for robertt
e
s 00001/00001/00056
d D 4.4 83/03/10 11:47:03 sam 4 3
c oops, thanks to bob gross
e
s 00003/00005/00054
d D 4.3 83/02/21 18:18:46 sam 3 2
c reflect standard disk partition table sizes
e
s 00000/00000/00059
d D 4.2 83/02/18 05:25:50 sam 2 1
c pull out common type mapping code for up's
e
s 00059/00000/00000
d D 4.1 83/02/18 00:50:12 sam 1 0
c date and time created 83/02/18 00:50:12 by sam
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8

/*
 * UNIBUS peripheral standalone
 * driver: drive type mapping routine.
 */
D 11

E 11
I 11
#ifdef COMPAT_42
E 11
D 10
#include "../h/param.h" 
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/dkbad.h"
#include "../h/vmmac.h"
E 10
I 10
#include "param.h" 
#include "inode.h"
#include "fs.h"
#include "dkbad.h"
I 11
#include "disklabel.h"
E 11
#include "vmmac.h"
E 10

#include "../vax/pte.h"
#include "../vaxuba/upreg.h"
#include "../vaxuba/ubareg.h"

#include "saio.h"
#include "savax.h"

D 3
short	up9300_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
short	up9766_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
short	fj_off[] = { 0, 50, 0, -1, -1, -1, -1, 155 };
/* this is called upam instead of am because hp.c has a similar array */
E 3
I 3
D 7
short	up9300_off[] = { 0, 27, 0, -1, -1, -1, 562, 82 };
short	fj_off[] = { 0, 50, 0, -1, -1, -1, 155, -1 };
E 3
short	upam_off[] = { 0, 32, 0, 668, 723, 778, 668, 98 };
I 5
short	up980_off[] = { 0, 100, 0, -1, -1 , -1, 309, -1};
E 7
I 7
D 11
static short	up9300_off[] = { 0, 27, 0, -1, -1, -1, 562, 82 };
static short	fj_off[] = { 0, 50, 0, -1, -1, -1, 155, -1 };
static short	upam_off[] = { 0, 32, 0, 668, 723, 778, 668, 98 };
static short	up980_off[] = { 0, 100, 0, -1, -1 , -1, 309, -1};
static short	eagle_off[8] =	{ 0, 17, 0, 391, 408, 728, 391, 87 };
E 11
I 11
static short	up9300_off[] = { 0,  27,  0,  -1,  -1,  -1, 562, 82 };
static short	fj_off[]     = { 0,  50,  0,  -1,  -1,  -1, 155, -1 };
static short	upam_off[]   = { 0,  32,  0, 668, 723, 778, 668, 98 };
static short	up980_off[]  = { 0, 100,  0,  -1,  -1,  -1, 309, -1 };
static short	eagle_off[]  = { 0,  17,  0, 391, 408, 728, 391, 87 };
E 11
E 7
E 5

struct st upst[] = {
	32,	19,	32*19,	815,	up9300_off,	/* 9300 */
D 3
	32,	19,	32*19,	823,	up9766_off,	/* 9766 */
E 3
I 3
	32,	19,	32*19,	823,	up9300_off,	/* 9766 */
E 3
	32,	10,	32*10,	823,	fj_off,		/* Fuji 160 */
	32,	16,	32*16,	1024,	upam_off,	/* Capricorn */
I 5
	32,	5,	32*5,	823,	up980_off,	/* DM980 */
I 7
	48,	20,	48*20,	842,	eagle_off,	/* Fuji Eagle */
E 7
E 5
	0,	0,	0,	0,	0,
};

D 11
upmaptype(unit, upaddr)
E 11
I 11
upmaptype(unit, upaddr, lp)
E 11
	int unit;
	register struct updevice *upaddr;
I 11
	register struct disklabel *lp;
E 11
{
	register struct st *st;
I 11
	register int i;
E 11
	int type = -1;

	upaddr->upcs1 = 0;
	upaddr->upcs2 = unit % 8;
	upaddr->uphr = UPHR_MAXTRAK;
D 11
	for (st = upst; st->ntrak != 0; st++)
E 11
I 11
	for (st = upst;; ++st) {
		if (!st->ntrak)
D 12
			return(1);
E 12
I 12
			return(0);
E 12
E 11
		if (upaddr->uphr == st->ntrak - 1) {
D 4
			type = st - st;
E 4
I 4
			type = st - upst;
E 4
			break;
		}
D 11
	if (st->ntrak == 0)
		printf("up%d: uphr=%x\n", unit, upaddr->uphr);
E 11
I 11
	}
E 11
	if (type == 0) {
		upaddr->uphr = UPHR_MAXCYL;
		if (upaddr->uphr == 822)	/* CDC 9766 */
D 11
			type++;
E 11
I 11
			++type;
E 11
	}
	upaddr->upcs2 = UPCS2_CLR;
D 11
	return (type);
E 11
I 11
	st = &upst[type];

	/* set up a minimal disk label */
	lp->d_nsectors = st->nsect;
	lp->d_ntracks = st->ntrak;
	lp->d_secpercyl = st->nspc;
	lp->d_ncylinders = st->ncyl;
	lp->d_secperunit = st->nspc * st->ncyl;
	lp->d_npartitions = 8;
	for (i = 0; i < 8; i++)
		if (st->off[i] == -1)
			lp->d_partitions[i].p_size = 0;
		else {
			lp->d_partitions[i].p_offset = st->off[i] *
			    lp->d_secpercyl;
			lp->d_partitions[i].p_size = lp->d_secperunit;
		}
D 12
	return(0);
E 12
I 12
	return(1);
E 12
E 11
}
I 11
#endif /* COMPAT_42 */
E 11
E 1
