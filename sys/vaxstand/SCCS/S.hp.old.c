h14022
s 00000/00000/00091
d D 7.1 86/06/05 01:42:28 mckusick 24 23
c 4.3BSD release version
e
s 00017/00045/00074
d D 6.2 85/11/08 19:15:41 karels 23 22
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00000/00000/00119
d D 6.1 83/07/29 07:47:02 sam 22 21
c 4.2 distribution
e
s 00001/00001/00118
d D 4.15 83/03/02 12:43:53 sam 21 20
c typo
e
s 00022/00008/00097
d D 4.14 83/03/01 20:08:50 sam 20 19
c unreadable
e
s 00004/00097/00101
d D 4.13 83/02/18 05:23:42 sam 19 18
c pull out common type mapping code for hp's
e
s 00073/00043/00125
d D 4.12 83/02/17 11:50:42 sam 18 17
c handle drive mapping chores
e
s 00010/00000/00158
d D 4.11 82/12/30 15:32:35 sam 17 16
c add ioctl's and errno
e
s 00001/00001/00157
d D 4.10 82/12/17 17:00:15 sam 16 15
c pte.h is now in ../machine/
e
s 00004/00002/00154
d D 4.9 82/11/13 23:14:35 sam 15 14
c move includes for 4.1c directory layout
e
s 00058/00004/00098
d D 4.8 82/08/01 19:36:16 sam 14 13
c add kludges for si, capricorn, etc. -- who would think to boot 
c off an ml11????
e
s 00001/00000/00101
d D 4.7 82/07/15 21:31:06 root 13 12
c new boot scheme
e
s 00004/00004/00097
d D 4.6 81/05/10 20:31:09 root 12 11
c minor bugs
e
s 00011/00007/00090
d D 4.5 81/05/10 20:27:55 root 11 10
c add rp05 and rp07 and fill in rm80 sizes
e
s 00007/00005/00090
d D 4.4 81/03/22 20:50:19 wnj 10 9
c MASKREG and errors
e
s 00062/00125/00033
d D 4.3 81/03/15 20:46:02 wnj 9 8
c 
e
s 00007/00000/00151
d D 4.2 80/12/17 12:10:45 wnj 8 7
c fix for 750 (add rk, dont compile hp, ht)
e
s 00000/00000/00151
d D 4.1 80/11/09 16:29:17 bill 7 6
c stamp for 4bsd
e
s 00001/00001/00150
d D 1.6 80/11/03 15:26:58 bill 6 5
c fix to RM5 per ghg
e
s 00001/00001/00150
d D 1.5 80/10/20 09:46:42 bill 5 4
c bug fix in drive type
e
s 00024/00011/00127
d D 1.4 80/10/16 11:37:50 bill 4 3
c ro05
e
s 00007/00008/00131
d D 1.3 80/07/29 15:08:52 bill 3 2
c work w/o mba's
e
s 00004/00000/00135
d D 1.2 80/07/28 10:03:30 bill 2 1
c mbaact, etc
e
s 00135/00000/00000
d D 1.1 80/06/28 10:42:50 bill 1 0
c date and time created 80/06/28 10:42:50 by bill
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%G%	*/
E 9
I 9
/*	%M%	%I%	%E%	*/
E 9

/*
D 4
 * RP04/RP06/RM03 disk driver
E 4
I 4
D 9
 * RP06/RM03/RM05 disk driver
E 9
I 9
 * RP??/RM?? disk driver
E 9
E 4
 */
I 16
#include "../machine/pte.h"
E 16

I 8
D 9
#if VAX==780
E 9
E 8
#include "../h/param.h"
#include "../h/inode.h"
I 9
D 15
#include "../h/hpreg.h"
E 15
E 9
D 3
#include "../h/mba.h"
#include "../h/mtpr.h"
E 3
D 16
#include "../h/pte.h"
E 16
I 3
D 9
#include "../h/mba.h"
E 9
I 9
D 15
#include "../h/mbareg.h"
E 15
I 13
#include "../h/fs.h"
I 15

#include "../vaxmba/hpreg.h"
#include "../vaxmba/mbareg.h"

E 15
E 13
E 9
E 3
#include "saio.h"
I 9
#include "savax.h"
E 9

I 23
#define	SECTSIZ	512
E 23
I 10
#define	MASKREG(reg)	((reg)&0xffff)

E 10
D 9
struct	device
{
	int	hpcs1;		/* control and Status register 1 */
	int	hpds;		/* Drive Status */
	int	hper1;		/* Error register 1 */
	int	hpmr;		/* Maintenance */ 
	int	hpas;		/* Attention Summary */
	int	hpda;		/* Desired address register */
	int	hpdt;		/* Drive type */
	int	hpla;		/* Look ahead */
	int	hpsn;		/* serial number */
	int	hpof;		/* Offset register */
	int	hpdc;		/* Desired Cylinder address register */
	int	hpcc;		/* Current Cylinder */
	int	hper2;		/* Error register 2 */
	int	hper3;		/* Error register 3 */
	int	hpec1;		/* Burst error bit position */
	int	hpec2;		/* Burst error bit pattern */
};
E 9
I 9
D 19
char	hp_type[MAXNMBA*8] = { 0 };
E 9

D 3
#define	HPADDR	((struct device *)(PHYSMBA0 + MBA_ERB))
I 2
#define	HPMBA	0
E 3
I 3
D 9
#define	HPMBA		PHYSMBA0
#define	HPMBANUM	0
E 9
I 9
/* THIS SHOULD BE READ IN OFF THE PACK, PER DRIVE */
D 11
short	 hp_off[8] =	{ 0, 38, 0, -1, -1, -1, 118, -1 };
short	 rm_off[8] =	{ 0, 100, 0, -1, -1, -1, 310, -1 };
short	 rm5_off[8] =	{ 0, 27, 0, 562, 589, 681, 562, 82 };
short	 rm80_off[8] =	{ 0, 0, 0, 0, 0, 0, 0, 0 };
E 11
I 11
short	hp6_off[8] =	{ 0, 38, 0, -1, -1, -1, 118, -1 };
short	rm3_off[8] =	{ 0, 100, 0, -1, -1, -1, 310, -1 };
short	rm5_off[8] =	{ 0, 27, 0, 562, 589, 681, 562, 82 };
short	rm80_off[8] =	{ 0, 37, 0, -1, -1, -1, 115, 305 };
short	hp7_off[8] = 	{ 0, 10, 0, 330, 340, 500, 330, 50 };
I 14
short	ml_off[8] =	{ 0, -1, -1, -1, -1, -1, -1, -1 };
short	si9775_off[8] =	{ 0, 13, 0, -1, -1, -1, 40, 441 };
short	si9730_off[8] = { 0, 50, 0, -1, -1, -1, -1, 155 };
short	hpam_off[8] =	{ 0, 32, 0, 668, 723, 778, 668, 98 };
I 18
short	hpfj_off[8] =	{ 0, 19, 0, -1, -1, -1, 398, 59 };
E 18
E 14
E 11
/* END SHOULD BE READ IN */
E 9
E 3

E 19
E 2
D 9
#define	NHP	8
#define	RP	022
#define	RM	024
I 4
#define	RM5	027
E 4
#define	NSECT	22
#define	NTRAC	19
#define	NRMSECT	32
#define	NRMTRAC	5
#define	SDIST	2
#define	RDIST	6

D 5
char	hp_type[NHP];	/* drive type */
E 5
I 5
char	hp_type[NHP] = { 0 };	/* drive type */
E 5

#define	GO	01
#define	PRESET	020
#define	RTC	016
#define	OFFSET	014
#define	SEARCH	030
#define	RECAL	06
#define	DCLR	010
#define	WCOM	060
#define	RCOM	070

#define	IE	0100
#define	PIP	020000
#define	DRY	0200
#define	ERR	040000
#define	TRE	040000
#define	DCK	0100000
#define	WLE	04000
#define	ECH	0100
#define	VV	0100
#define	DPR	0400
#define	MOL	010000
#define	FMT22	010000

struct size {
	daddr_t	cyloff;
} hp_sizes[8] = {
D 4
	0, 38, 98, -1, -1, -1, 118, -1
E 4
I 4
	0, 38, 0, -1, -1, -1, 118, -1
E 4
}, rm_sizes[8] = {
D 4
	0, 100, -1, -1, -1, -1, 310, -1
E 4
I 4
	0, 100, 0, -1, -1, -1, 310, -1
}, rm5_sizes[9] = {
	0, 27, 0, 562, 589, 681, 562, 82
E 9
I 9
D 18
short	hptypes[] =
D 11
	{ MBDT_RM03, MBDT_RM05, MBDT_RP06, MBDT_RM80, 0 };
E 11
I 11
D 14
    { MBDT_RM03, MBDT_RM05, MBDT_RP06, MBDT_RM80, MBDT_RP05, MBDT_RP07, 0 };
E 14
I 14
    { MBDT_RM03, MBDT_RM05, MBDT_RP06, MBDT_RM80, MBDT_RP05, MBDT_RP07,
      MBDT_ML11A, MBDT_ML11B, -1/*9755*/, -1/*9730*/, -1/*Cap*/, MBDT_RM02, 0 };
E 18
I 18
D 23
short	hptypes[] = {
D 20
	MBDT_RM03,	MBDT_RM05,	MBDT_RP06,	MBDT_RM80,
	MBDT_RP05,	MBDT_RP07,	MBDT_ML11A,	MBDT_ML11B,
	-1 /*9755*/,	-1 /*9730*/,	-1 /*Cap*/,	-1 /* Eagle */,
	-1 /* Eagle */,	MBDT_RM02,	0
E 20
I 20
	MBDT_RM03,
	MBDT_RM05,
	MBDT_RP06,
	MBDT_RM80,
	MBDT_RP05,
	MBDT_RP07,
	MBDT_ML11A,
	MBDT_ML11B,
	-1,		/* 9755 */
	-1,		/* 9730 */
	-1,		/* Capricorn */
	-1,		/* Eagle */
	MBDT_RM02,	/* actually something else */
	-1,		/* 9300 */
	0
E 20
};
E 23
I 23
extern	short hptypes[];
E 23
E 18
E 14

I 20
D 23
#define RP06 (hptypes[hp_type[unit]] <= MBDT_RP06)
#define ML11 (hptypes[hp_type[unit]] == MBDT_ML11A)
#define RM80 (hptypes[hp_type[unit]] == MBDT_RM80)

E 20
E 11
D 19
struct hpst {
	short	nsect;
	short	ntrak;
	short	nspc;
	short	ncyl;
	short	*off;
} hpst[] = {
D 10
	32,	5,	32*5,	823,	rm_off,	/* RM03 */
E 10
I 10
D 11
	32,	5,	32*5,	823,	rm_off,		/* RM03 */
E 11
I 11
	32,	5,	32*5,	823,	rm3_off,	/* RM03 */
E 11
E 10
	32,	19,	32*19,	823,	rm5_off,	/* RM05 */
D 10
	22,	19,	22*19,	815,	hp_off,	/* RP06 */
E 10
I 10
D 11
	22,	19,	22*19,	815,	hp_off,		/* RP06 */
E 11
I 11
	22,	19,	22*19,	815,	hp6_off,	/* RP06 */
E 11
E 10
D 12
	31,	14, 	31*14,	559,	rm80_off	/* RM80 */
E 12
I 12
	31,	14, 	31*14,	559,	rm80_off,	/* RM80 */
E 12
I 11
	22,	19,	22*19,	411,	hp6_off,	/* RP06 */
	50,	32,	50*32,	630,	hp7_off,	/* RP07 */
I 14
	1,	1,	1,	1,	ml_off,		/* ML11A */
	1,	1,	1,	1,	ml_off,		/* ML11B */
	32,	40,	32*40,	843,	si9775_off,	/* 9775 */
	32,	10,	32*10,	823,	si9730_off,	/* 9730 */
	32,	16,	32*16,	1024,	hpam_off,	/* AMPEX capricorn */
I 18
	43,	20,	43*20,	842,	hpfj_off,	/* Eagle */
	48,	20,	48*20,	842,	hpfj_off,	/* modif. eagle */
E 18
	1,	1,	1,	1,	0,		/* rm02 - not used */
E 14
E 11
E 9
E 4
};
E 19
I 19
char	hp_type[MAXNMBA*8] = { 0 };
E 23
I 23
char	hp_type[MAXNMBA*8];
E 23
extern	struct st hpst[];
E 19

hpopen(io)
D 9
register struct iob *io;
E 9
I 9
	register struct iob *io;
E 9
{
	register unit = io->i_unit;
D 9
	struct device *hpaddr;
E 9
I 9
	struct hpdevice *hpaddr = (struct hpdevice *)mbadrv(unit);
D 19
	register struct hpst *st;
E 19
I 19
	register struct st *st;
I 23
	register i, type = hpaddr->hpdt & MBDT_TYPE;
E 23
E 19
E 9

I 2
D 3
	if ((mbaact&(1<<HPMBA)) == 0)
		mbainit(HPMBA);
E 2
	hpaddr = (struct device *)((int *)HPADDR + 32*unit);
E 3
I 3
D 9
	if ((mbaact&(1<<HPMBANUM)) == 0)
		mbainit(HPMBANUM);
	hpaddr = mbadev(HPMBA,unit);
E 3
	if (hp_type[unit] == 0)
		hp_type[unit] = hpaddr->hpdt;
	if (hp_sizes[io->i_boff].cyloff == -1 ||
	    io->i_boff < 0 || io->i_boff > 7)
		_stop("hp bad minor");
D 4
	if (hp_type[unit] == RM)
E 4
I 4
	switch (hp_type[unit]) {
	case RM:
E 4
		io->i_boff = rm_sizes[io->i_boff].cyloff * NRMSECT * NRMTRAC;
D 4
	else
E 4
I 4
		break;
	case RM5:
D 6
		io->i_boff = rm5_sizes[io->i_boff].cyloff * NSECT * NRMTRAC;
E 6
I 6
		io->i_boff = rm5_sizes[io->i_boff].cyloff * NRMSECT * NTRAC;
E 6
		break;
	case RP:
E 4
		io->i_boff = hp_sizes[io->i_boff].cyloff * NSECT * NTRAC;
I 4
		break;
	default:
E 9
I 9
	mbainit(UNITTOMBA(io->i_unit));
D 23
	if (hp_type[unit] == 0) {
D 18
		register type = hpaddr->hpdt & MBDT_TYPE;
E 18
D 20
		register int i;
I 18
		register type = hpaddr->hpdt & MBDT_TYPE;
E 20
I 20
		register i, type = hpaddr->hpdt & MBDT_TYPE;
E 20
E 18

		for (i = 0; hptypes[i]; i++)
			if (hptypes[i] == type)
				goto found;
E 9
		_stop("unknown drive type");
E 23
I 23
	for (i = 0; hptypes[i]; i++)
		if (hptypes[i] == type)
			goto found;
	_stop("unknown drive type");
E 23
I 9
found:
I 14
D 18
		switch (i) {
		case 0: case 1:	{	/* rm03 or rm05 */
			register hpsn = hpaddr->hpsn;

			if ((hpsn & SIMB_LU) != unit)
				break;
			switch ((hpsn & SIMB_MB) &~ (SIMB_S6|SIRM03|SIRM05)) {
			case SI9775D:
				i = 8;	/* si9775 */
				break;
			case SI9730D:
				i = 9;	/* si9730 */
				break;
			case SI9766:
				i = 1;	/* rm05 */
				hpaddr->hpcs1 = HP_RECAL|HP_GO;
				DELAY(100000);
				break;
			case SI9762:
				i = 0;	/* rm03 */
				break;
			}
			break;
		}

		case 11:		/* rm02 */
			hpaddr->hpcs1 = HP_NOP;
			hpaddr->hphr = HPHR_MAXTRAK;
			if ((hpaddr->hphr&0xffff) == 15)
				i = 10;		/* ampex capricorn */
			else
				i = 0;		/* rm03 */
			break;
		
		case 6: case 7:		/* ml11a ml11b */
			i = 6;			/* ml11a */
			break;
		}
E 14
		hp_type[unit] = i;
E 18
I 18
D 23
		hpaddr->hpcs1 = HP_DCLR|HP_GO;		/* init drive */
		hpaddr->hpcs1 = HP_PRESET|HP_GO;
		if (type != MBDT_ML11A && type != MBDT_ML11B)
			hpaddr->hpof = HPOF_FMT22;
		hp_type[unit] = hpmaptype(hpaddr, i, unit);
E 18
E 9
	}
E 23
I 23
	hpaddr->hpcs1 = HP_DCLR|HP_GO;		/* init drive */
	hpaddr->hpcs1 = HP_PRESET|HP_GO;
	hpaddr->hpof = HPOF_FMT22;
	hp_type[unit] = hpmaptype(hpaddr, i, unit);
E 23
I 9
D 12
	if (hp_off[io->i_boff]== -1 ||
	    io->i_boff < 0 || io->i_boff > 7)
		_stop("hp bad minor");
E 12
	st = &hpst[hp_type[unit]];
I 12
	if (io->i_boff < 0 || io->i_boff > 7 ||
	    st->off[io->i_boff]== -1)
		_stop("hp bad minor");
E 12
	io->i_boff = st->off[io->i_boff] * st->nspc;
I 18
}

D 19
hpmaptype(hpaddr, type, unit)
	register struct hpdevice *hpaddr;
	unsigned type;
	int unit;
{
	int ntracks, hpsn;

	/*
	 * Handle SI model byte stuff when
	 * we think it's an RM03 or RM05.
	 */
	if (type == 0 || type == 1) {
		hpsn = hpaddr->hpsn;
		if ((hpsn & SIMB_LU) != unit)
			return (type);
		switch ((hpsn & SIMB_MB) &~ (SIMB_S6|SIRM03|SIRM05)) {
		case SI9775D:
			return (8);
		case SI9730D:
			return (9);
		case SI9766:
			hpaddr->hpcs1 = HP_RECAL|HP_GO;
			DELAY(100000);
			return (1);

		case SI9762:
			return (0);
		}
		return (type);
	}
	/*
	 * RM03: EMULEX controller.  Map to correct
	 * drive type by checking the holding
	 * register for the disk geometry.
	 */
	if (type == 13) {
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXTRAK;
		ntracks = MASKREG(hpaddr->hphr) + 1;
		if (ntracks == 16)
			return (10);	/* AMPEX capricorn */
		hpaddr->hphr = HPHR_MAXSECT;
		ntracks = MASKREG(hpaddr->hphr) + 1;
		if (ntracks == 48)
			return (12);	/* 48 sector Eagle */
		if (ntracks == 43)
			return (11);	/* 43 sector Eagle */
		printf("RM02 with %d sectors/track?\n", ntracks);
		return (type);
	}
	/*
	 * ML11's all map to the same type.
	 */
	if (type == 6 || type == 7)
		return (6);
	return (type);
E 18
E 9
E 4
}

E 19
hpstrategy(io, func)
D 9
register struct iob *io;
E 9
I 9
	register struct iob *io;
E 9
{
D 9
	int unit, nspc, ns, cn, tn, sn;
	daddr_t bn;
	struct device *hpaddr;
E 9
I 9
	int unit = io->i_unit;
	daddr_t bn = io->i_bn;
	struct hpdevice *hpaddr = (struct hpdevice *)mbadrv(unit);
D 19
	struct hpst *st = &hpst[hp_type[unit]];
E 19
I 19
	struct st *st = &hpst[hp_type[unit]];
E 19
	int cn, tn, sn;
E 9

D 9
	unit = io->i_unit;
	bn = io->i_bn;
D 3
	hpaddr = (struct device *)((int *)HPADDR + 32*unit);
E 3
I 3
	hpaddr = mbadev(HPMBA, unit);
E 3
	if (hp_type[unit] == 0)
		hp_type[unit] = hpaddr->hpdt;
	if((hpaddr->hpds & VV) == 0) {
		hpaddr->hpcs1 = PRESET|GO;
		hpaddr->hpof = FMT22;
E 9
I 9
	if ((hpaddr->hpds & HPDS_VV) == 0) {
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
		hpaddr->hpcs1 = HP_PRESET|HP_GO;
D 14
		hpaddr->hpof = HPOF_FMT22;
E 14
I 14
D 20
		if (hp_type[unit] != 6)		/* any but ml11 */
E 20
I 20
D 23
		if (!ML11)
E 20
			hpaddr->hpof = HPOF_FMT22;
E 23
I 23
		hpaddr->hpof = HPOF_FMT22;
E 23
E 14
E 9
	}
D 4
	if (hp_type[unit] == RM) {
		nspc = NRMSECT*NRMTRAC;
		ns = NRMSECT;
	} else {
		nspc = NSECT*NTRAC;
		ns = NSECT;
E 4
I 4
D 9
	switch (hp_type[unit]) {
	case RM:
		nspc = NRMSECT*NRMTRAC; ns = NRMSECT; break;
	case RM5:
		nspc = NRMSECT*NTRAC; ns = NRMSECT; break;
	case RP:
		nspc = NSECT*NTRAC; ns = NSECT; break;
E 4
	}
	cn = bn/nspc;
	sn = bn%nspc;
	tn = sn/ns;
	sn = sn%ns;
E 9
I 9
	cn = bn/st->nspc;
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn = sn%st->nsect;
E 9
D 14
	hpaddr->hpdc = cn;
	hpaddr->hpda = (tn << 8) + sn;
E 14
I 14
D 20
	if (hp_type[unit] == 6)		/* ml11 */
E 20
I 20
D 21
	if (!ML11)
E 21
I 21
D 23
	if (ML11)
E 21
E 20
		hpaddr->hpda = bn;
	else {
		hpaddr->hpdc = cn;
		hpaddr->hpda = (tn << 8) + sn;
	}
E 23
I 23
	hpaddr->hpdc = cn;
	hpaddr->hpda = (tn << 8) + sn;
E 23
E 14
D 9
	mbastart(io, (int *)hpaddr, func);
	while((hpaddr->hpds & DRY) == 0)
E 9
I 9
	mbastart(io, func);
	while ((hpaddr->hpds & HPDS_DRY) == 0)
E 9
		;
D 9
	if(hpaddr->hpds&ERR) {
		printf("disk error: cyl=%d track=%d sect=%d ds=%X, er1=%X\n",
E 9
I 9
	if (hpaddr->hpds&HPDS_ERR) {
D 10
		printf("hp error: cyl=%d track=%d sect=%d ds=%o er1=%o\n",
E 9
		    cn, tn, sn,
		    hpaddr->hpds, hpaddr->hper1);
E 10
I 10
D 23
		printf("hp error: (cyl,trk,sec)=(%d,%d,%d) ds=%b er1=%b\n",
		    cn, tn, sn, MASKREG(hpaddr->hpds), HPDS_BITS,
E 23
I 23
		printf("hp error: sn [%d-%d) ds=%b er1=%b\n",
		    bn, bn + io->i_cc/SECTSIZ, MASKREG(hpaddr->hpds), HPDS_BITS,
E 23
		    MASKREG(hpaddr->hper1), HPER1_BITS);
E 10
		return (-1);
	}
D 9
	return(io->i_cc);
E 9
I 9
	return (io->i_cc);
E 9
}
I 17

/*ARGSUSED*/
hpioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
}
E 17
I 8
D 9
#else
hpdummy()
{
	;
}
#endif
E 9
E 8
E 1
