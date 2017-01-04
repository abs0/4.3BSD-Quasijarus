h29299
s 00000/00000/00096
d D 7.1 86/06/05 01:47:35 mckusick 23 22
c 4.3BSD release version
e
s 00000/00000/00096
d D 6.1 83/07/29 07:48:08 sam 22 21
c 4.2 distribution
e
s 00007/00009/00089
d D 4.17 83/03/02 22:07:13 sam 21 20
c use correct drive #; return correct residual; make things 
c more understandable -- use register names instead of playing with pointers
e
s 00002/00002/00096
d D 4.16 83/03/01 23:25:48 sam 20 19
c have to make arrays in same segment as up.new.c or loader bitches
e
s 00003/00046/00095
d D 4.15 83/02/18 05:25:31 sam 19 18
c pull out common type mapping code for up's
e
s 00039/00008/00102
d D 4.14 83/02/17 13:09:58 sam 18 15
c handle type mapping better
e
s 00039/00008/00102
d R 4.14 83/02/17 13:07:07 sam 17 15
c handle type mapping better
e
s 00036/00007/00103
d R 4.14 83/02/17 11:51:01 sam 16 15
c handle drive mapping chores
e
s 00010/00000/00100
d D 4.13 82/12/30 15:32:48 sam 15 14
c add ioctl's and errno
e
s 00002/00001/00098
d D 4.12 82/12/17 17:01:50 sam 14 13
c pte.h is now in ../machine/
e
s 00004/00002/00095
d D 4.11 82/11/13 23:15:42 sam 13 12
c move includes for 4.1c directory layout
e
s 00001/00000/00096
d D 4.10 82/07/15 21:32:42 root 12 11
c new boot scheme
e
s 00001/00001/00095
d D 4.9 81/04/18 11:51:24 wnj 11 10
c s/10/9/
e
s 00030/00014/00066
d D 4.8 81/04/15 12:38:00 wnj 10 9
c put in fujitsu stuff
e
s 00007/00006/00073
d D 4.7 81/04/03 03:02:14 root 9 8
c cleanup and cosmetics
e
s 00025/00090/00054
d D 4.6 81/03/15 20:47:01 wnj 8 7
c 
e
s 00003/00003/00141
d D 4.5 81/01/15 19:39:17 wnj 7 6
c fix to wait for DVA
e
s 00004/00000/00140
d D 4.4 80/12/18 12:08:26 wnj 6 5
c use SC11 for 750
e
s 00003/00000/00137
d D 4.3 80/12/17 12:04:58 wnj 5 4
c startup delay for controller (sc21) to self-test itself
e
s 00000/00020/00137
d D 4.2 80/11/09 16:36:55 bill 4 3
c cleanup for reasonable (no-delay) controller
e
s 00000/00000/00157
d D 4.1 80/11/09 16:29:53 bill 3 2
c stamp for 4bsd
e
s 00061/00048/00096
d D 1.2 80/07/21 10:39:22 bill 2 1
c fixed up messy
e
s 00144/00000/00000
d D 1.1 80/06/28 10:43:21 bill 1 0
c date and time created 80/06/28 10:43:21 by bill
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
/*	%M%	%I%	%E%	*/
E 8

I 14
#include "../machine/pte.h"

E 14
I 6
D 8
#if VAX==750
#include "up.c.SC11"
#else
E 8
E 6
I 2
D 4
#define	OLDUCODE

E 4
E 2
#include "../h/param.h"
#include "../h/inode.h"
I 8
D 13
#include "../h/upreg.h"
E 13
E 8
D 14
#include "../h/pte.h"
E 14
D 8
#include "../h/uba.h"
E 8
I 8
D 13
#include "../h/ubareg.h"
E 13
I 12
#include "../h/fs.h"
I 13

#include "../vaxuba/upreg.h"
#include "../vaxuba/ubareg.h"

E 13
E 12
E 8
#include "saio.h"
I 8
#include "savax.h"
E 8

D 4
#define	EMULEX
#ifdef	EMULEX
E 4
D 8
#define DELAY(N)	{ register int d; d = N; while (--d > 0); }
D 4
#else
#define	DELAY(N)
#endif
E 4

struct upregs {
	short	upcs1;	/* Control and Status register 1 */
	short	upwc;	/* Word count register */
	short	upba;	/* UNIBUS address register */
	short	upda;	/* Desired address register */
	short	upcs2;	/* Control and Status register 2*/
	short	upds;	/* Drive Status */
	short	uper1;	/* Error register 1 */
	short	upas;	/* Attention Summary */
	short	upla;	/* Look ahead */
	short	updb;	/* Data buffer */
	short	upmr;	/* Maintenance register */
	short	updt;	/* Drive type */
	short	upsn;	/* Serial number */
	short	upof;	/* Offset register */
	short	upca;	/* Desired Cylinder address register*/
	short	upcc;	/* Current Cylinder */
	short	uper2;	/* Error register 2 */
	short	uper3;	/* Error register 3 */
	short	uppos;	/* Burst error bit position */
	short	uppat;	/* Burst error bit pattern */
	short	upbae;	/* 11/70 bus extension */
};

I 2
D 4
#ifdef	OLDUCODE
#define	SDELAY	500
#else
#define	SDELAY	25
#endif
int	sdelay = SDELAY;
int	idelay = 500;

E 4
E 2
#define	UPADDR ((struct upregs *)(PHYSUMEM + 0776700 - UNIBASE))
D 2
char	up_openf;
E 2

D 2
/* Drive Commands */
#define	GO	01
#define	PRESET	020
#define	RECAL	06
#define	RCLR	010
#define	OFFSET	014
#define	RCOM	070
#define	WCOM	060
E 2
I 2
/* Drive commands, placed in upcs1 */
#define	GO	01		/* Go bit, set in all commands */
#define	PRESET	020		/* Preset drive at init or after errors */
#define	OFFSET	014		/* Offset heads to try to recover error */
#define	RTC	016		/* Return to center-line after OFFSET */
#define	SEARCH	030		/* Search for cylinder+sector */
#define	SEEK	04		/* Seek to cylinder */
#define	RECAL	06		/* Recalibrate, needed after seek error */
#define	DCLR	010		/* Drive clear, after error */
#define	WCOM	060		/* Write */
#define	RCOM	070		/* Read */
E 2

D 2
#define	IENABLE	0100
#define	READY	0200		/* upds - drive ready */
#define	PIP	020000		/* upds - Positioning Operation in Progress */
#define	ERR	040000		/* upcs1 - composite error */
#define	DRY	0200		/* upcs1 - drive ready */
E 2
I 2
/* Other bits of upcs1 */
#define	IE	0100		/* Controller wide interrupt enable */
I 7
#define	DVA	04000		/* Drive available */
E 7
#define	TRE	040000		/* Transfer error */
#define	RDY	0200		/* Transfer terminated */
E 2

D 2
#define	DTE	010000  	/* uper1 - Drive Timing Error	*/
#define	OPI	020000  	/* uper1 - Operation Incomplete */
#define	DU	040000		/* uper1 - Drive Unsafe */
E 2
I 2
/* Drive status bits of upds */
#define	PIP	020000		/* Positioning in progress */
#define	ERR	040000		/* Error has occurred, DCLR necessary */
#define	VV	0100		/* Volume is valid, set by PRESET */
#define	DPR	0400		/* Drive has been preset */
#define	MOL	010000		/* Drive is online, heads loaded, etc */
#define	DRY	0200		/* Drive ready */
E 2

D 2
/* Error Correction Code errors */
#define	DCK	0100000		/* uper1 - Data Check error */
#define	ECH	0100    	/* uper1 - ECC hard error */
E 2
I 2
/* Bits of upcs2 */
#define	CLR	040		/* Controller clear */
/* Bits of uper1 */
#define	DCK	0100000		/* Ecc error occurred */
#define	ECH	0100		/* Ecc error was unrecoverable */
#define	WLE	04000		/* Attempt to write read-only drive */
E 2

D 2
#define	CLR	040		/* upcs2 - Controller Clear */
E 2
I 2
/* Bits of upof; the offset bits above are also in this register */
#define	FMT22	010000		/* 16 bits/word, must be always set */
E 2

E 8
I 8
u_short	ubastd[] = { 0776700 };
E 8
D 2
#define	FMT22	010000		/* upof - 16 bit /word format */

E 2
D 10
struct devsize {
	daddr_t	cyloff;
} up_sizes[] = {
	0, 27, 68, -1, -1, -1, -1, 82
E 10
I 10
D 20
char	up_gottype[MAXNUBA*8] = { 0 };
char	up_type[MAXNUBA*8] = { 0 };
E 20
I 20
char	up_gottype[MAXNUBA*8];
char	up_type[MAXNUBA*8];
E 20
D 18
short	up_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
E 18
I 18
D 19
short	up9300_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
short	up9766_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
E 18
short	fj_off[] = { 0, 50, 0, -1, -1, -1, -1, 155 };
I 18
short	upam_off[] = { 0, 32, 0, 668, 723, 778, 668, 98 };
E 19
I 19
extern	struct st upst[];
E 19

D 19
#define	NUPTYPES	4
E 18
struct upst {
	short nsect;
	short ntrak;
	short nspc;
	short ncyl;
	short *off;
D 18
} upst[] = {
	32,	19,	32*19,	823,	up_off,
	32,	10,	32*10,	823,	fj_off,
E 18
I 18
} upst[NUPTYPES] = {
	32,	19,	32*19,	815,	up9300_off,	/* 9300 */
	32,	19,	32*19,	823,	up9766_off,	/* 9766 */
	32,	10,	32*10,	823,	fj_off,		/* fuji 160 */
	32,	16,	32*16,	1024,	upam_off,	/* Capricorn */
E 18
E 10
};

E 19
upopen(io)
D 8
register struct iob *io;
E 8
I 8
	register struct iob *io;
E 8
{
I 8
	register struct updevice *upaddr =
	    (struct updevice *)ubamem(io->i_unit, ubastd[0]);
I 10
D 19
	register struct upst *st;
E 19
I 19
	register struct st *st;
E 19
E 10
E 8

D 10
	if (up_sizes[io->i_boff].cyloff == -1 ||
	    io->i_boff < 0 || io->i_boff > 7)
		_stop("up bad unit");
	io->i_boff = up_sizes[io->i_boff].cyloff * 32 * 19;
E 10
I 5
D 7
	printf("wait...");
	DELAY(15000000);
	printf("\n");
E 7
I 7
D 8
	while ((UPADDR->upcs1&DVA) == 0)
E 8
I 8
	while ((upaddr->upcs1 & UP_DVA) == 0)
E 8
		;
I 10
	if (up_gottype[io->i_unit] == 0) {
D 18
		upaddr->uphr = UPHR_MAXTRAK;
D 11
		if (upaddr->uphr == 10)
E 11
I 11
		if (upaddr->uphr == 9)
E 11
			up_type[io->i_unit] = 1;	/* fuji kludge */
		upaddr->upcs2 = UPCS2_CLR;
E 18
I 18
		up_type[io->i_unit] = upmaptype(io->i_unit, upaddr);
		if (up_type[io->i_unit] < 0)
			_stop("unknown drive type");
E 18
		up_gottype[io->i_unit] = 1;
	}
	st = &upst[up_type[io->i_unit]];
	if (io->i_boff < 0 || io->i_boff > 7 || st->off[io->i_boff] == -1)
		_stop("up bad unit");
	io->i_boff = st->off[io->i_boff] * st->nspc;
I 18
}

D 19
upmaptype(unit, upaddr)
	int unit;
	register struct updevice *upaddr;
{
	register struct upst *st;
	int type = -1;

	upaddr->upcs1 = 0;
	upaddr->upcs2 = unit % 8;
	upaddr->uphr = UPHR_MAXTRAK;
	for (st = upst; st < &upst[NUPTYPES]; st++)
		if (upaddr->uphr == st->ntrak - 1) {
			type = st - upst;
			break;
		}
	if (type < 0)
		printf("up%d: uphr=%x\n", unit, upaddr->uphr);
	if (type == 0) {
		upaddr->uphr = UPHR_MAXCYL;
		if (upaddr->uphr == 822)	/* CDC 9766 */
			type++;
	}
	upaddr->upcs2 = UPCS2_CLR;
	return (type);
E 18
E 10
E 7
E 5
}

E 19
upstrategy(io, func)
D 8
register struct iob *io;
E 8
I 8
	register struct iob *io;
E 8
{
	int unit, nspc, ns, cn, tn, sn;
	daddr_t bn;
	int info;
D 21
	register short *rp;
E 21
D 8
	int occ = io->i_cc;
I 2
	register struct upregs *upaddr = UPADDR;
E 8
I 8
	register struct updevice *upaddr =
	    (struct updevice *)ubamem(io->i_unit, ubastd[0]);
I 10
D 19
	register struct upst *st = &upst[up_type[io->i_unit]];
E 19
I 19
	register struct st *st = &upst[up_type[io->i_unit]];
E 19
E 10
E 8
E 2

	unit = io->i_unit;
	bn = io->i_bn;
D 10
	nspc = 32 * 19;
	ns = 32;
	cn = bn/nspc;
	sn = bn%nspc;
	tn = sn/ns;
	sn = sn%ns;
E 10
I 10
	cn = bn/st->nspc;
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn = sn%st->nsect;
E 10
D 2
	if (!up_openf) {
		up_openf++;
		UPADDR->upcs2 = CLR;
		DELAY(500);
		UPADDR->upcs1 = RCLR|GO;
		DELAY(500);
		UPADDR->upcs1 = PRESET|GO;
		DELAY(500);
		UPADDR->upof = FMT22;
		DELAY(500);
		while ((UPADDR->upcs1 & DRY) == 0)
			DELAY(500);
E 2
I 2
D 21
	upaddr->upcs2 = unit;
E 21
I 21
	upaddr->upcs2 = unit % 8;
E 21
D 4
	DELAY(sdelay);
E 4
D 8
	if ((upaddr->upds & VV) == 0) {
		upaddr->upcs1 = DCLR|GO;
D 4
		DELAY(idelay);
E 4
		upaddr->upcs1 = PRESET|GO;
D 4
		DELAY(idelay);
E 4
		upaddr->upof = FMT22;
E 8
I 8
D 9
	if ((upaddr->upds & UP_VV) == 0) {
E 9
I 9
	if ((upaddr->upds & UPDS_VV) == 0) {
E 9
		upaddr->upcs1 = UP_DCLR|UP_GO;
		upaddr->upcs1 = UP_PRESET|UP_GO;
D 9
		upaddr->upof = UP_FMT22;
E 9
I 9
		upaddr->upof = UPOF_FMT22;
E 9
E 8
E 2
	}
D 2
	UPADDR->upcs2 = unit;
	DELAY(500);
E 2
I 2
D 8
	if ((upaddr->upds & (DPR|MOL)) != (DPR|MOL))
		_stop("up !DPR || !MOL");
E 8
I 8
D 9
	if ((upaddr->upds & UP_DREADY) != UP_DREADY)
E 9
I 9
	if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY)
E 9
		_stop("up not ready");
E 8
E 2
	info = ubasetup(io, 1);
D 2
	rp = (short *) &UPADDR->upda;
	UPADDR->upca = cn;
E 2
I 2
D 21
	rp = (short *) &upaddr->upda;
E 21
D 8
	upaddr->upca = cn;
E 8
I 8
	upaddr->updc = cn;
E 8
E 2
D 21
	*rp = (tn << 8) + sn;
	*--rp = info;
	*--rp = -io->i_cc / sizeof (short);
E 21
I 21
	upaddr->upda = (tn << 8) + sn;
	upaddr->upba = info;
	upaddr->upwc = -io->i_cc / sizeof (short);
E 21
D 2
	if (func == READ) {
E 2
I 2
	if (func == READ)
E 2
D 8
		*--rp = GO|RCOM;
E 8
I 8
D 21
		*--rp = UP_RCOM|UP_GO;
E 21
I 21
		upaddr->upcs1 = UP_RCOM|UP_GO;
E 21
E 8
D 2
	} else {
E 2
I 2
	else
E 2
D 8
		*--rp = GO|WCOM;
E 8
I 8
D 21
		*--rp = UP_WCOM|UP_GO;
E 21
I 21
		upaddr->upcs1 = UP_WCOM|UP_GO;
E 21
E 8
D 2
	}
	DELAY(500);
E 2
I 2
D 4
	DELAY(sdelay);
E 4
E 2
	do {
D 2
		DELAY(200);
	} while ((UPADDR->upcs1 & DRY) == 0);
E 2
I 2
		DELAY(25);
D 8
	} while ((upaddr->upcs1 & RDY) == 0);
E 2
D 4
	DELAY(200);
E 4
D 2
	if (UPADDR->upcs1&ERR) {
E 2
I 2
	if (upaddr->upcs1&ERR) {
E 2
		printf("disk error: cyl=%d track=%d sect=%d cs1=%X, er1=%X\n",
E 8
I 8
	} while ((upaddr->upcs1 & UP_RDY) == 0);
D 9
	if (upaddr->upcs1 & UP_ERR) {
		printf("up error: cyl=%d track=%d sect=%d cs1=%o, er1=%o\n",
E 9
I 9
	if (upaddr->upds & UPDS_ERR) {
		printf("up error: (cyl,trk,sec)=(%d,%d,%d) cs2=%b er1=%b er2=%b\n",
E 9
E 8
		    cn, tn, sn,
D 2
		    UPADDR->upcs1, UPADDR->uper1);
E 2
I 2
D 9
		    upaddr->upcs1, upaddr->uper1);
E 9
I 9
		    upaddr->upcs2, UPCS2_BITS, upaddr->uper1, UPER1_BITS,
		    upaddr->uper2, UPER2_BITS);
E 9
E 2
		return (-1);
	}
D 8
	if (io->i_cc != occ)
D 2
	printf("returned %d\n", io->i_cc);
E 2
I 2
		printf("returned %d\n", io->i_cc);
E 2
	ubafree(info);
E 8
I 8
	ubafree(io, info);
E 8
D 21
	return (io->i_cc);
E 21
I 21
	return (io->i_cc + (upaddr->upwc * sizeof (short)));
E 21
}
I 15

/*ARGSUSED*/
upioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
}
E 15
I 6
D 8
#endif
E 8
E 6
E 1
