h13227
s 00005/00002/00620
d D 7.4 88/05/27 15:49:27 karels 15 14
c update controller selection, etc.
e
s 00087/00071/00535
d D 7.3 88/03/04 14:12:17 bostic 14 13
c enable cache, add disklabels, from Chris Torek
e
s 00013/00019/00593
d D 7.2 88/02/24 11:05:21 karels 13 12
c update
e
s 00002/00002/00610
d D 7.1 86/06/05 01:41:39 mckusick 12 11
c 4.3BSD release version
e
s 00068/00047/00544
d D 6.7 85/11/08 19:15:13 karels 11 10
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00099/00035/00492
d D 6.6 85/10/15 13:19:54 karels 10 9
c allow format track by track; numerous fixes for skip sector
c (still not sure it's right)
e
s 00014/00001/00513
d D 6.5 85/06/08 13:37:35 mckusick 9 8
c Add copyright
e
s 00051/00038/00463
d D 6.4 84/11/27 11:24:06 karels 8 7
c allow variable # of passes, continue or quit after specified number
e
s 00173/00071/00328
d D 6.3 83/09/23 10:07:04 karels 7 6
c ghg's severe burnin format
e
s 00009/00008/00390
d D 6.2 83/09/18 22:00:19 karels 6 5
c fixes from ghg
e
s 00000/00000/00398
d D 6.1 83/07/29 07:46:51 sam 5 4
c 4.2 distribution
e
s 00001/00001/00397
d D 4.4 83/05/03 12:33:01 helge 4 3
c display cylinder numbers instead of sector numbers
e
s 00000/00001/00398
d D 4.3 83/03/02 16:04:55 sam 3 2
c shorten message so it fits on the screen
e
s 00060/00042/00339
d D 4.2 83/03/02 12:47:46 sam 2 1
c parameterize patterns more
e
s 00381/00000/00000
d D 4.1 83/03/01 23:29:30 sam 1 0
c date and time created 83/03/01 23:29:30 by sam
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
D 12
 * Copyright (c) 1980 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 9

I 9
#ifndef lint
char copyright[] =
D 12
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 12
I 12
"%Z% Copyright (c) 1980, 1986 Regents of the University of California.\n\
E 12
 All rights reserved.\n";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14
E 9
I 7

I 10
D 14

E 14
E 10
E 7
/* 
 * Standalone program to do media checking
 * and record bad block information on any 
D 6
 * disk with the appropriate driver.
E 6
I 6
 * disk with the appropriate driver and RM03-style headers.
I 10
 * TODO:
 *	add new bad sectors to bad-sector table when formatting by track
 *		(rearranging replacements ala bad144 -a)
 *	multi-pass format for disks with skip-sector capability
E 10
E 6
 */
D 13
#include "../h/param.h"
#include "../h/fs.h"
#include "../h/inode.h"
#include "../h/dkbad.h"
#include "../h/vmmac.h"
E 13
I 13
#include "param.h"
#include "fs.h"
#include "inode.h"
#include "dkbad.h"
#include "vmmac.h"
I 14
#include "disklabel.h"
E 14
E 13

I 14
#include "../vax/cpu.h"
#include "../vax/mtpr.h"

E 14
#include "saio.h"
#include "savax.h"

#define MAXBADDESC	126		/* size of bad block table */
#define CHUNK		48		/* max # of sectors/io operation */
#define SECTSIZ		512		/* standard sector size */
#define HDRSIZ		4		/* number of bytes in sector header */

#define SSERR		0
#define BSERR		1

D 11
#define SSDEV		((ioctl(iob[fd-3], SAIOSSDEV, (char *)0) == 0))
E 11
I 11
#define SSDEV(fd)	(ioctl((fd), SAIOSSDEV, (char *)0) == 0)
#define MAXECCBITS	3
E 11

struct sector {
	u_short	header1;
	u_short header2;
	char	buf[SECTSIZ];
};

struct	dkbad dkbad;		/* bad sector table */
I 11
struct	dkbad oldbad;		/* old bad sector table */
E 11
struct	dkbad sstab;		/* skip sector table */

#define	NERRORS		6
D 2
char	*errornames[NERRORS] = {
E 2
I 2
static char *
errornames[NERRORS] = {
E 2
D 6
#define	FE_WCE		0
	"Write check",
#define	FE_BSE		1
E 6
I 6
#define	FE_BSE		0
E 6
	"Bad sector",
I 6
#define	FE_WCE		1
	"Write check",
E 6
#define	FE_ECC		2
D 11
	"ECC",
E 11
I 11
	"Hard ECC",
E 11
#define	FE_HARD		3
	"Other hard",
#define	FE_TOTAL	4
D 11
	"Total",
E 11
I 11
	"Marked bad",
E 11
#define	FE_SSE		5
D 11
	"Skip sector",
E 11
I 11
	"Skipped",
E 11
};

int	errors[NERRORS];	/* histogram of errors */
I 2
int	pattern;
I 11
int	maxeccbits;
E 11
E 2

I 7
/*
 * Purdue/EE severe burnin patterns.
 */
unsigned short ppat[] = {
D 8
0031463,0070707,0133333,0155555,0161616,0143434,
E 8
I 8
0xf00f, 0xec6d, 0031463,0070707,0133333,0155555,0161616,0143434,
E 8
0107070,0016161,0034343,0044444,0022222,0111111,0125252, 052525,
0125252,0125252,0125252,0125252,0125252,0125252,0125252,0125252,
#ifndef	SHORTPASS
0125252,0125252,0125252,0125252,0125252,0125252,0125252,0125252,
 052525, 052525, 052525, 052525, 052525, 052525, 052525, 052525,
#endif
 052525, 052525, 052525, 052525, 052525, 052525, 052525, 052525
 };

#define	NPT	(sizeof (ppat) / sizeof (short))
D 8
int	npat;		/* subscript to ppat[] */
E 8
I 8
int	maxpass, npat;	/* subscript to ppat[] */
E 8
int	severe;		/* nz if running "severe" burnin */
I 11
int	ssdev;			/* device supports skip sectors */
E 11
I 10
int	startcyl, endcyl, starttrack, endtrack;
E 10
D 11
int	nbads;		/* subscript for bads */
long	bads[MAXBADDESC]; /* Bad blocks accumulated */
E 11
I 11
int	nbads;			/* subscript for bads */
daddr_t	bads[2*MAXBADDESC]; 	/* Bad blocks accumulated */
E 11

E 7
char	*malloc();
I 7
int	qcompar();
E 7
char	*prompt();
I 10
daddr_t	badsn();
E 10
extern	int end;

main()
{
D 14
	register int sector, sn;
D 2
	int pattern, lastsector, tracksize;
E 2
I 2
D 7
	int lastsector, tracksize;
E 7
I 7
	int lastsector, tracksize, rtracksize;
E 7
E 2
	int unit, fd, resid, i, trk, cyl, debug;
	struct st st;
E 14
I 14
	register struct sector *hdr;
	register int sector, sn, i;
	struct disklabel dl;
E 14
	struct sector *bp, *cbp;
I 7
D 14
	char *rbp, *rcbp;
D 8
	int pass, maxpass;
E 8
I 8
	int pass;
E 8
E 7
	char *cp;
E 14
I 14
	int lastsector, tracksize, rtracksize;
	int unit, fd, resid, trk, cyl, debug, pass;
	char *cp, *rbp, *rcbp;
E 14

	printf("Disk format/check utility\n\n");

I 14
	/* enable the cache, as every little bit helps */
	switch (cpu) {
	case VAX_8600:
		mtpr(CSWP, 3);
		break;
	case VAX_8200:
	case VAX_750:
		mtpr(CADR, 0);
		break;
	case VAX_780:
		mtpr(SBIMT, 0x200000);
		break;
	}

E 14
again:
D 7
	cp = prompt("Enable debugging (1=bse, 2=ecc, 3=bse+ecc)? ");
E 7
I 7
	nbads = 0;
	cp = prompt("Enable debugging (0=none, 1=bse, 2=ecc, 3=bse+ecc)? ");
E 7
	debug = atoi(cp);
	if (debug < 0)
		debug = 0;
	for (i = 0; i < NERRORS; i++)
		errors[i] = 0;
	fd = getdevice();
D 14
	ioctl(fd, SAIODEVDATA, &st);
E 14
I 14
	ioctl(fd, SAIODEVDATA, &dl);
E 14
	printf("Device data: #cylinders=%d, #tracks=%d, #sectors=%d\n",
D 14
	  st.ncyl, st.ntrak, st.nsect);
E 14
I 14
	    dl.d_ncylinders, dl.d_ntracks, dl.d_nsectors);
E 14
I 11
	ssdev = SSDEV(fd);
	if (ssdev) {
		ioctl(fd, SAIOSSI, (char *)0);	/* set skip sector inhibit */
D 14
		st.nsect++;
		st.nspc += st.ntrak;
E 14
I 14
		dl.d_nsectors++;
		dl.d_secpercyl += dl.d_ntracks;
E 14
		printf("(not counting skip-sector replacement)\n");
	}
E 11
I 10
D 14
	getrange(&st);
E 14
I 14
	getrange(&dl);
E 14
E 10
D 2
	printf("Available test patterns are:\n");
	printf("\t0 - (f00f) RH750 worst case\n");
	printf("\t1 - (ec6d) media worst case\n");
	printf("\t2 - (a5a5) alternate 1's & 0's\n");
	cp = prompt("Pattern (0, 1, 2, other to restart)? ");
	pattern = atoi(cp);
	if (pattern < 0 || pattern > 2)
E 2
I 2
	if (getpattern())
E 2
		goto again;
	printf("Start formatting...make sure the drive is online\n");
I 7
D 11
	if (severe)
		ioctl(fd, SAIOSEVRE, (char *) 0);
E 11
E 7
	ioctl(fd, SAIONOBAD, (char *)0);
D 11
	ioctl(fd, SAIOECCLIM, (char *)0);
E 11
I 11
	ioctl(fd, SAIORETRIES, (char *)0);
	ioctl(fd, SAIOECCLIM, (char *)maxeccbits);
E 11
	ioctl(fd, SAIODEBUG, (char *)debug);
D 11
	if (SSDEV) {
I 7
		if (severe) {
			printf("Severe burnin doesn't work with RM80 yet\n");
			exit(1);
		}
E 7
		ioctl(fd, SAIOSSI, (char *)0);	/* set skip sector inhibit */
		st.nsect++;
		st.nspc += st.ntrak;
	}
E 11
D 14
	tracksize = sizeof (struct sector) * st.nsect;
I 7
	rtracksize = SECTSIZ * st.nsect;
E 14
I 14
	tracksize = sizeof (struct sector) * dl.d_nsectors;
	rtracksize = SECTSIZ * dl.d_nsectors;
E 14
E 7
	bp = (struct sector *)malloc(tracksize);
D 2
	bufinit(bp, tracksize, pattern);
E 2
I 2
D 7
	bufinit(bp, tracksize);
E 2
	/*
	 * Begin check, for each track,
	 *
	 * 1) Write header and test pattern.
	 * 2) Write check header and data.
	 */
	lastsector = st.nspc * st.ncyl;
	for (sector = 0; sector < lastsector; sector += st.nsect) {
		cyl = sector / st.nspc;
		trk = (sector % st.nspc) / st.nsect;
		for (i = 0; i < st.nsect; i++) {
			bp[i].header1 =
				(u_short) cyl | HDR1_FMT22 | HDR1_OKSCT;
			bp[i].header2 = ((u_short)trk << 8) + i;
		}
		if (sector && (sector % (st.nspc * 10)) == 0)
D 4
			printf("sector %d\n", sector);
E 4
I 4
			printf("cylinder %d\n", cyl);
E 7
I 7
	rbp = malloc(rtracksize);
D 8
	if (severe) {
		npat = 0;
		maxpass = NPT;
	} else
		maxpass = 1;
	for (pass = 0; pass < maxpass; pass++) {
E 8
I 8
	pass = 0;
	npat = 0;
more:
	for (; pass < maxpass; pass++) {
E 8
		if (severe)
			printf("Begin pass %d\n", pass);
		bufinit(bp, tracksize);
		if (severe)
			npat++;
E 7
E 4
		/*
D 7
		 * Try and write the headers and data patterns into
		 * each sector in the track.  Continue until such
		 * we're done, or until there's less than a sector's
		 * worth of data to transfer.
E 7
I 7
		 * Begin check, for each track,
E 7
		 *
D 7
		 * The lseek call is necessary because of
		 * the odd sector size (516 bytes)
E 7
I 7
		 * 1) Write header and test pattern.
		 * 2) Read data.  Hardware checks header and data ECC.
D 8
		 *    Read data (esp on Eagles) is much faster when write check.
E 8
I 8
		 *    Read data (esp on Eagles) is much faster than write check.
E 8
E 7
		 */
D 7
		for (resid = tracksize, cbp = bp, sn = sector;;) {
			int cc;
E 7
I 7
D 10
		lastsector = st.nspc * st.ncyl;
		for (sector = 0; sector < lastsector; sector += st.nsect) {
E 10
I 10
D 14
		sector = ((startcyl * st.ntrak) + starttrack) * st.nsect;
		lastsector = ((endcyl * st.ntrak) + endtrack) * st.nsect
			+ st.nsect;
		for ( ; sector < lastsector; sector += st.nsect) {
E 10
			cyl = sector / st.nspc;
			trk = (sector % st.nspc) / st.nsect;
			for (i = 0; i < st.nsect; i++) {
				bp[i].header1 =
					(u_short) cyl | HDR1_FMT22 | HDR1_OKSCT;
				bp[i].header2 = ((u_short)trk << 8) + i;
E 14
I 14
		sector = ((startcyl * dl.d_ntracks) + starttrack) *
			dl.d_nsectors;
		lastsector = ((endcyl * dl.d_ntracks) + endtrack) *
			dl.d_nsectors + dl.d_nsectors;
		for ( ; sector < lastsector; sector += dl.d_nsectors) {
			cyl = sector / dl.d_secpercyl;
			trk = ((sector % dl.d_secpercyl) / dl.d_nsectors) << 8;
			for (i = 0, hdr = bp; i < dl.d_nsectors; i++, hdr++) {
				hdr->header1 = cyl | HDR1_FMT22 | HDR1_OKSCT;
				hdr->header2 = trk + i;
E 14
			}
D 14
			if (sector && (sector % (st.nspc * 100)) == 0)
E 14
I 14
			if (sector && (sector % (dl.d_secpercyl * 50)) == 0)
E 14
				printf("cylinder %d\n", cyl);
			/*
			 * Try and write the headers and data patterns into
			 * each sector in the track.  Continue until such
			 * we're done, or until there's less than a sector's
			 * worth of data to transfer.
			 *
			 * The lseek call is necessary because of
			 * the odd sector size (516 bytes)
			 */
			for (resid = tracksize, cbp = bp, sn = sector;;) {
D 14
				int cc;
E 14
I 14
				register int cc;
E 14
E 7

D 7
			lseek(fd, sn * SECTSIZ, 0);
			ioctl(fd, SAIOHDR, (char *)0);
			cc = write(fd, cbp, resid);
			if (cc == resid)
				break;
E 7
I 7
D 13
				lseek(fd, sn * SECTSIZ, 0);
E 13
I 13
				lseek(fd, sn * SECTSIZ, L_SET);
E 13
				ioctl(fd, SAIOHDR, (char *)0);
				cc = write(fd, cbp, resid);
				if (cc == resid)
					break;
				/*
				 * Don't record errors during write,
				 * all errors will be found during
D 11
				 * writecheck performed below.
E 11
I 11
				 * check performed below.
E 11
				 */
				sn = iob[fd - 3].i_errblk;
				cbp += sn - sector;
				resid -= (sn - sector) * sizeof (struct sector);
				if (resid < sizeof (struct sector)) 
					break;
			}
E 7
			/*
D 7
			 * Don't record errors during write,
			 * all errors will be found during
			 * writecheck performed below.
E 7
I 7
			 * Read test patterns.
			 * Retry remainder of track on error until
			 * we're done, or until there's less than a
			 * sector to verify.
E 7
			 */
D 7
			sn = iob[fd - 3].i_errblk;
			cbp += sn - sector;
			resid -= (sn - sector) * sizeof (struct sector);
			if (resid < sizeof (struct sector)) 
				break;
		}
		/*
		 * Write check headers and test patterns.
		 * Retry remainder of track on error until
		 * we're done, or until there's less than a
		 * sector to verify.
		 */
		for (resid = tracksize, cbp = bp, sn = sector;;) {
			int cc;
E 7
I 7
			for (resid = rtracksize, rcbp = rbp, sn = sector;;) {
D 11
				int cc;
E 11
I 11
D 14
				int cc, rsn;
E 14
I 14
				register int cc, rsn;
E 14
E 11
E 7

D 7
			lseek(fd, sn * SECTSIZ, 0);
			ioctl(fd, SAIOHCHECK, (char *)0);
			cc = read(fd, cbp, resid);
			if (cc == resid)
				break;
			sn = iob[fd-3].i_errblk;
			printf("sector %d, write check error\n", sn);
			recorderror(fd, sn, &st);
			/* advance past bad sector */
			sn++;
			cbp += sn - sector;
			resid -= (sn - sector) * sizeof (struct sector);
			if (resid < sizeof (struct sector)) 
				break;
E 7
I 7
D 13
				lseek(fd, sn * SECTSIZ, 0);
E 13
I 13
				lseek(fd, sn * SECTSIZ, L_SET);
E 13
				cc = read(fd, rcbp, resid);
				if (cc == resid)
					break;
				sn = iob[fd-3].i_errblk;
D 11
				printf("sector %d, read error\n", sn);
E 11
I 11
				if (ssdev) {
D 14
					rsn = sn - (sn / st.nsect);
E 14
I 14
					rsn = sn - (sn / dl.d_nsectors);
E 14
					printf("data ");
				} else
					rsn = sn;
				printf("sector %d, read error\n\n", rsn);
E 11
D 14
				if (recorderror(fd, sn, &st) < 0 && pass > 0)
E 14
I 14
				if (recorderror(fd, sn, &dl) < 0 && pass > 0)
E 14
					goto out;
				/* advance past bad sector */
				sn++;
D 11
				rcbp += sn - sector;
				resid -= ((sn - sector) * SECTSIZ);
E 11
I 11
				resid = rtracksize - ((sn - sector) * SECTSIZ);
				rcbp = rbp + ((sn - sector) * SECTSIZ);
E 11
				if (resid < SECTSIZ) 
					break;
			}
E 7
		}
	}
	/*
	 * Checking finished.
	 */
I 7
out:
I 8
D 11
	if (errors[FE_TOTAL] || errors[FE_SSE]) {
		printf("Errors:\n");
		for (i = 0; i < NERRORS; i++)
			printf("%s: %d\n", errornames[i], errors[i]);
D 10
		printf("Total of %d hard errors found\n",
E 10
I 10
		printf("Total of %d hard errors revectored\n",
E 10
			errors[FE_TOTAL] + errors[FE_SSE]);
	}
E 11
	if (severe && maxpass < NPT) {
		cp = prompt("More passes? (0 or number) ");
		maxpass = atoi(cp);
		if (maxpass > 0) {
			maxpass += pass;
			goto more;
		}
	}
E 8
	if (severe && nbads) {
		/*
		 * Sort bads and insert in bad block table.
		 */
D 11
		qsort(bads, nbads, sizeof (long), qcompar);
E 11
I 11
		qsort(bads, nbads, sizeof (daddr_t), qcompar);
E 11
		severe = 0;
D 8
		for (i = 0; i < nbads; i++) {
			errno = EECC;	/* for now */
E 8
I 8
		errno = 0;
		for (i = 0; i < nbads; i++)
E 8
D 14
			recorderror(fd, bads[i], &st);
E 14
I 14
			recorderror(fd, bads[i], &dl);
E 14
D 8
		}
E 8
		severe++;
	}
E 7
	if (errors[FE_TOTAL] || errors[FE_SSE]) {
D 8
		printf("Errors:\n");
		for (i = 0; i < NERRORS; i++)
			printf("%s: %d\n", errornames[i], errors[i]);
		printf("Total of %d hard errors found\n",
			errors[FE_TOTAL] + errors[FE_SSE]);
E 8
		/* change the headers of all the bad sectors */
D 14
		writebb(fd, errors[FE_SSE], &sstab, &st, SSERR);
		writebb(fd, errors[FE_TOTAL], &dkbad, &st, BSERR);
E 14
I 14
		writebb(fd, errors[FE_SSE], &sstab, &dl, SSERR);
		writebb(fd, errors[FE_TOTAL], &dkbad, &dl, BSERR);
E 14
	}
I 11
	if (errors[FE_TOTAL] || errors[FE_SSE]) {
		printf("Errors:\n");
		for (i = 0; i < NERRORS; i++)
			printf("%s: %d\n", errornames[i], errors[i]);
		printf("Total of %d hard errors revectored\n",
			errors[FE_TOTAL] + errors[FE_SSE]);
	}
E 11
D 10
	while (errors[FE_TOTAL] < MAXBADDESC) {
		int i = errors[FE_TOTAL]++;
E 10
I 10
D 14
	if (endcyl == st.ncyl - 1 &&
	    (startcyl < st.ncyl - 1 || starttrack == 0)) {
E 14
I 14
	if (endcyl == dl.d_ncylinders - 1 &&
	    (startcyl < dl.d_ncylinders - 1 || starttrack == 0)) {
E 14
		while (errors[FE_TOTAL] < MAXBADDESC) {
			int i = errors[FE_TOTAL]++;
E 10

D 10
		dkbad.bt_bad[i].bt_cyl = -1;
		dkbad.bt_bad[i].bt_trksec = -1;
E 10
I 10
			dkbad.bt_bad[i].bt_cyl = -1;
			dkbad.bt_bad[i].bt_trksec = -1;
		}
		printf("\nWriting bad sector table at sector #%d\n",
D 14
			st.ncyl * st.nspc - st.nsect);
E 14
I 14
			dl.d_ncylinders * dl.d_secpercyl - dl.d_nsectors);
E 14
		/* place on disk */
D 14
		for (i = 0; i < 10 && i < st.nsect; i += 2) {
D 13
			lseek(fd, SECTSIZ * (st.ncyl * st.nspc - st.nsect + i), 0);
E 13
I 13
			lseek(fd, SECTSIZ * (st.ncyl * st.nspc - st.nsect + i), L_SET);
E 14
I 14
		for (i = 0; i < 10 && i < dl.d_nsectors; i += 2) {
			lseek(fd, SECTSIZ * (dl.d_ncylinders *
				dl.d_secpercyl - dl.d_nsectors + i), 0);
E 14
E 13
			write(fd, &dkbad, sizeof (dkbad));
		}
	} else if (errors[FE_TOTAL]) {
		struct bt_bad *bt;

		printf("New bad sectors (not added to table):\n");
		bt = dkbad.bt_bad;
		for (i = 0; i < errors[FE_TOTAL]; i++) {
D 11
			printf("sn %d (cn=%d, tn=%d, sn=%d)\n", badsn(bt, st),
E 11
I 11
D 14
			printf("bn %d (cn=%d, tn=%d, sn=%d)\n", badsn(bt, &st),
E 14
I 14
			printf("bn %d (cn=%d, tn=%d, sn=%d)\n", badsn(bt, &dl),
E 14
E 11
			    bt->bt_cyl, bt->bt_trksec>>8, bt->bt_trksec&0xff);
			bt++;
		}
E 10
	}
D 10
	printf("\nWriting bad sector table at sector #%d\n",
		st.ncyl * st.nspc - st.nsect);
	/* place on disk */
	for (i = 0; i < 10; i += 2) {
		lseek(fd, SECTSIZ * (st.ncyl * st.nspc - st.nsect + i), 0);
		write(fd, &dkbad, sizeof (dkbad));
	}
E 10
	printf("Done\n");
	ioctl(fd,SAIONOSSI,(char *)0);
	close(fd);
I 7
D 8
/*
	if (severe) {
		asm("halt");
		exit(0);
	}
*/
E 8
E 7
#ifndef JUSTEXIT
	goto again;
#endif
}

I 7
qcompar(l1, l2)
D 11
register long *l1, *l2;
E 11
I 11
register daddr_t *l1, *l2;
E 11
{
	if (*l1 < *l2)
		return(-1);
	if (*l1 == *l2)
		return(0);
	return(1);
}

I 10
daddr_t
D 14
badsn(bt, st)
E 14
I 14
badsn(bt, lp)
E 14
	register struct bt_bad *bt;
D 14
	register struct st *st;
E 14
I 14
	register struct disklabel *lp;
E 14
{
I 14
	register int ssoff = ssdev ? 1 : 0;
E 14
D 11
	return ((bt->bt_cyl*st->ntrak + (bt->bt_trksec>>8)) * st->nsect
E 11
I 11

D 14
	if (ssdev)
	    return ((bt->bt_cyl * st->ntrak + (bt->bt_trksec>>8)) *
		(st->nsect - 1) + (bt->bt_trksec&0xff)) - 1;
	else
	    return ((bt->bt_cyl*st->ntrak + (bt->bt_trksec>>8)) * st->nsect
E 11
		+ (bt->bt_trksec&0xff));
E 14
I 14
	return ((bt->bt_cyl * lp->d_ntracks + (bt->bt_trksec >> 8)) *
		(lp->d_nsectors - ssoff) + (bt->bt_trksec & 0xff) - ssoff);
E 14
}

E 10
E 7
D 2
static struct pat {
	long	pt[2];
} pat[3] = {
	{ 0xf00ff00f, 0xf00ff00f }, 	/* worst case for RH750 */
	{ 0xec6dec6d, 0xec6dec6d },	/* worst case for media */
	{ 0xa5a5a5a5, 0xa5a5a5a5 }
};

struct xsect {
	u_short	hd1;
	u_short	hd2;
	struct	pat buf[64];
};

E 2
/*
D 2
 * Initialize the buffer with the requested pattern. 
 */
bufinit(bufptr, size, pattern)
	register struct xsect bufptr[];
	int size, pattern;
{
	register struct pat *pptr;

	int i, j;

	size /= sizeof (struct sector);
	pptr = &pat[pattern];
	for (i = 0; i < size; i++)
		for (j = 0; j < 64; j++)
			bufptr[i].buf[j] = *pptr;
}

/*
E 2
D 10
 * Write out the bad blocks.
E 10
I 10
 * Mark the bad/skipped sectors.
D 11
 * Bad sectors on skip-sector devices are assumed to be skipped also.
E 11
I 11
 * Bad sectors on skip-sector devices are assumed to be skipped also,
 * and must be done after the (earlier) first skipped sector.
E 11
E 10
 */
D 14
writebb(fd, nsects, dbad, st, sw)
E 14
I 14
writebb(fd, nsects, dbad, lp, sw)
E 14
	int nsects, fd;
	struct dkbad *dbad;
D 14
	register struct st *st;
E 14
I 14
	register struct disklabel *lp;
E 14
{
	struct sector bb_buf; /* buffer for one sector plus 4 byte header */
	register int i;
	int bn, j;
	struct bt_bad *btp;

	for (i = 0; i < nsects; i++) {
		btp = &dbad->bt_bad[i];
		if (sw == BSERR) {
			bb_buf.header1 = HDR1_FMT22|btp->bt_cyl;
D 11
			if (SSDEV)
E 11
I 11
			if (ssdev)
E 11
				bb_buf.header1 |= HDR1_SSF;
		} else
			bb_buf.header1 =
			       btp->bt_cyl | HDR1_FMT22 | HDR1_SSF | HDR1_OKSCT;
		bb_buf.header2 = btp->bt_trksec;
D 14
		bn = st->nspc * btp->bt_cyl +
		     st->nsect * (btp->bt_trksec >> 8) +
E 14
I 14
		bn = lp->d_secpercyl * btp->bt_cyl +
		     lp->d_nsectors * (btp->bt_trksec >> 8) +
E 14
D 6
		     (btp->bt_trksec & 0x1f);
E 6
I 6
		     (btp->bt_trksec & 0xff);
E 6
D 13
		lseek(fd, bn * SECTSIZ, 0);
E 13
I 13
		lseek(fd, bn * SECTSIZ, L_SET);
E 13
		ioctl(fd, SAIOHDR, (char *)0);
		write(fd, &bb_buf, sizeof (bb_buf));
D 11
		if (!SSDEV)
			continue;
E 11
		/*
		 * If skip sector, mark all remaining
		 * sectors on the track.
		 */
D 6
		for (j = (btp->bt_trksec & 0x1f) + 1; j < st->nsect; j++) {
E 6
I 6
D 10
		for (j = (btp->bt_trksec & 0xff) + 1; j < st->nsect; j++) {
E 6
			bb_buf.header1 = j | HDR1_FMT22 | HDR1_SSF;
E 10
I 10
D 11
		for (j = (btp->bt_trksec & 0xff) + 1, bn++;
		    j <= st->nsect; j++, bn++) {
			bb_buf.header2 = j | (btp->bt_trksec & 0xff00);
			lseek(fd, bn * SECTSIZ, 0);
E 10
			ioctl(fd, SAIOHDR, (char *)0);
			write(fd, &bb_buf, sizeof (bb_buf));
E 11
I 11
		if (sw == SSERR) {
			for (j = (btp->bt_trksec & 0xff) + 1, bn++;
D 14
			    j < st->nsect; j++, bn++) {
E 14
I 14
			    j < lp->d_nsectors; j++, bn++) {
E 14
				bb_buf.header2 = j | (btp->bt_trksec & 0xff00);
D 13
				lseek(fd, bn * SECTSIZ, 0);
E 13
I 13
				lseek(fd, bn * SECTSIZ, L_SET);
E 13
				ioctl(fd, SAIOHDR, (char *)0);
				write(fd, &bb_buf, sizeof (bb_buf));
			}
E 11
		}
	}
}

/*
 * Record an error, and if there's room, put
 * it in the appropriate bad sector table.
I 7
 *
 * If severe burnin store block in a list after making sure
 * we have not already found it on a prev pass.
E 7
 */
D 14
recorderror(fd, bn, st)
E 14
I 14
recorderror(fd, bn, lp)
E 14
	int fd, bn;
D 14
	register struct st *st;
E 14
I 14
	register struct disklabel *lp;
E 14
{
D 10
	int cn, tn, sn, strk;
E 10
I 10
	int cn, tn, sn;
E 10
I 7
D 14
	register i;
E 14
I 14
	register int i;
E 14
E 7

I 7
D 14
	
E 14
	if (severe) {
		for (i = 0; i < nbads; i++)
			if (bads[i] == bn)
				return(0);	/* bn already flagged */
D 11
		if (nbads >= MAXBADDESC) {
E 11
I 11
		if (nbads >= (ssdev ? 2 * MAXBADDESC : MAXBADDESC)) {
E 11
D 10
			printf("Bad sector table full, burnin terminating\n");
E 10
I 10
			printf("Bad sector table full, format terminating\n");
E 10
			return(-1);
		}
		bads[nbads++] = bn;
I 8
		if (errno < EBSE || errno > EHER)
			return(0);
		errno -= EBSE;
		errors[errno]++;
E 8
		return(0);
	}
E 7
D 8
	if (errors[FE_TOTAL] >= MAXBADDESC) {
		printf("Too many bad sectors\n");
D 7
		return;
E 7
I 7
		return(-1);
E 8
I 8
	if (errno >= EBSE && errno <= EHER) {
D 10
		if (errors[FE_TOTAL] >= MAXBADDESC) {
			printf("Too many bad sectors\n");
			return(-1);
		}
		if (errors[FE_SSE] >= MAXBADDESC) {
			printf("Too many skip sector errors\n");
			return(-1);
		}
E 10
		errno -= EBSE;
		errors[errno]++;
E 8
E 7
	}
D 8
	if (errors[FE_SSE] >= MAXBADDESC) {
		printf("Too many skip sector errors\n");
D 7
		return;
E 7
I 7
		return(-1);
E 7
	}
D 6
	if (errno <= ECMD || errno > EHER)
E 6
I 6
	if (errno < EBSE || errno > EHER)
E 6
D 7
		return;
E 7
I 7
		return(0);
E 7
I 6
	errno -= EBSE;
E 6
	errors[errno]++;
E 8
D 14
	cn = bn / st->nspc;
	sn = bn % st->nspc;
	tn = sn / st->nsect;
	sn %= st->nsect;
E 14
I 14
	cn = bn / lp->d_secpercyl;
	sn = bn % lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn %= lp->d_nsectors;
E 14
D 11
	if (SSDEV) {		/* if drive has skip sector capability */
E 11
I 11
	if (ssdev) {		/* if drive has skip sector capability */
E 11
D 10
		int ss = errors[FE_SSE]++;
E 10
I 10
		int ss = errors[FE_SSE];
E 10

D 10
		if (ss)
			strk = sstab.bt_bad[ss - 1].bt_trksec >> 8;
		else
			strk = -1;
		if (tn != strk) {	  /* only one skip sector/track */
E 10
I 10
		if (errors[FE_SSE] >= MAXBADDESC) {
			/* this is bogus, we don't maintain skip sector table */
			printf("Too many skip sector errors\n");
			return(-1);
		}
		  /* only one skip sector/track */
		if (ss == 0 ||
		    tn != (sstab.bt_bad[ss - 1].bt_trksec >> 8) ||
		    cn != sstab.bt_bad[ss - 1].bt_cyl) {
I 11
			/*
			 * Don't bother with skipping the extra sector
			 * at the end of the track.
			 */
D 14
			if (sn == st->nsect - 1)
E 14
I 14
			if (sn == lp->d_nsectors - 1)
E 14
				return(0);
E 11
E 10
			sstab.bt_bad[ss].bt_cyl = cn;
			sstab.bt_bad[ss].bt_trksec = (tn<<8) + sn;
D 10
			return;
E 10
I 10
			errors[FE_SSE]++;
			return(0);
E 10
		}
D 10
		cn = -cn;
E 10
	}
I 10
	if (errors[FE_TOTAL] >= MAXBADDESC) {
		printf("Too many bad sectors\n");
		return(-1);
	}
E 10
	/* record the bad sector address and continue */
D 6
	dkbad.bt_bad[errors[FE_TOTAL]++].bt_cyl = cn;
E 6
I 6
	dkbad.bt_bad[errors[FE_TOTAL]].bt_cyl = cn;
E 6
	dkbad.bt_bad[errors[FE_TOTAL]++].bt_trksec = (tn << 8) + sn;
I 7
	return(0);
E 7
}

/*
 * Allocate memory on a page-aligned address.
 * Round allocated chunk to a page multiple to
 * ease next request.
 */
char *
malloc(size)
	int size;
{
	char *result;
	static caddr_t last = 0;

	if (last == 0)
		last = (caddr_t)(((int)&end + 511) & ~0x1ff);
	size = (size + 511) & ~0x1ff;
	result = (char *)last;
	last += size;
	return (result);
}

/*
 * Prompt and verify a device name from the user.
 */
getdevice()
{
	register char *cp;
D 13
	register struct devsw *dp;
E 13
	int fd;

top:
D 13
	cp = prompt("Device to format? ");
	if ((fd = open(cp, 2)) < 0) {
		printf("Known devices are: ");
		for (dp = devsw; dp->dv_name; dp++)
			printf("%s ",dp->dv_name);
		printf("\n");
		goto top;
	}
E 13
I 13
	do {
I 15
		printf(
		"Enter device name as \"type(adaptor,controller,drive,0)\"\n");
E 15
		cp = prompt("Device to format? ");
	} while ((fd = open(cp, 2)) < 0);
E 13
D 7
	printf("Formatting drive %d on %c%c%d ",
		iob[fd - 3].i_unit % 8, cp[0], cp[1], iob[fd - 3].i_unit / 8);
E 7
I 7
D 15
	printf("Formatting drive %c%c%d on adaptor %d: ",
		cp[0], cp[1], iob[fd - 3].i_unit % 8, iob[fd - 3].i_unit / 8);
E 15
I 15
	printf("Formatting %c%c drive %d on controller %d, adaptor %d: ",
		cp[0], cp[1], iob[fd - 3].i_unit,
		iob[fd - 3].i_ctlr, iob[fd - 3].i_adapt);
E 15
E 7
D 3
	printf("will destroy everything on the disk, ");
E 3
	cp = prompt("verify (yes/no)? ");
	while (*cp != 'y' && *cp != 'n')
		cp = prompt("Huh, yes or no? ");
	if (*cp == 'y')
		return (fd);
	goto top;
I 10
}

/*
 * Find range of tracks to format.
 */
D 14
getrange(st)
	struct st *st;
E 14
I 14
getrange(lp)
	register struct disklabel *lp;
E 14
{
D 14
	startcyl = getnum("Starting cylinder", 0, st->ncyl - 1, 0);
D 11
	endcyl = getnum("Ending cylinder", 0, st->ncyl - 1, st->ncyl - 1);
E 11
	starttrack = getnum("Starting track", 0, st->ntrak - 1, 0);
I 11
	endcyl = getnum("Ending cylinder", 0, st->ncyl - 1, st->ncyl - 1);
E 11
	endtrack = getnum("Ending track", 0, st->ntrak - 1, st->ntrak - 1);
E 14
I 14
	startcyl = getnum("Starting cylinder", 0, lp->d_ncylinders - 1, 0);
	starttrack = getnum("Starting track", 0, lp->d_ntracks - 1, 0);
	endcyl = getnum("Ending cylinder", 0, lp->d_ncylinders - 1,
		lp->d_ncylinders - 1);
	endtrack = getnum("Ending track", 0, lp->d_ntracks - 1,
		lp->d_ntracks - 1);
E 14
}

getnum(s, low, high, dflt)
I 14
	int s, low, high, dflt;
E 14
{
	char buf[132];
D 14
	unsigned val;
E 14
I 14
	u_int val;
E 14

D 14
	while (1) {
E 14
I 14
	for(;;) {
E 14
		printf("%s (%d): ", s, dflt);
		gets(buf);
		if (buf[0] == 0)
			return (dflt);
		val = atoi(buf);
		if (val >= low && val <= high)
			return ((int)val);
		printf("Value must be in range [%d,%d]\n", low, high);
	}
E 10
I 2
}

static struct pattern {
	long	pa_value;
	char	*pa_name;
} pat[] = {
	{ 0xf00ff00f, 	"RH750 worst case" },
	{ 0xec6dec6d,	"media worst case" },
	{ 0xa5a5a5a5,	"alternate 1's and 0's" },
I 7
D 8
	{ 0xFFFFFFFF,	"Severe burnin (takes several hours)" },
E 8
I 8
	{ 0xFFFFFFFF,	"Severe burnin (up to 48 passes)" },
E 8
E 7
	{ 0, 0 },
};

getpattern()
{
	register struct pattern *p;
	int npatterns;
	char *cp;

	printf("Available test patterns are:\n");
	for (p = pat; p->pa_value; p++)
		printf("\t%d - (%x) %s\n", (p - pat) + 1,
		  p->pa_value & 0xffff, p->pa_name);
	npatterns = p - pat;
	cp = prompt("Pattern (one of the above, other to restart)? ");
	pattern = atoi(cp) - 1;
I 8
	if (pattern < 0 || pattern >= npatterns)
		return(1);
E 8
I 7
	severe = 0;
D 8
	if (pat[pattern].pa_value == -1)
E 8
I 8
	maxpass = 1;
	if (pat[pattern].pa_value == -1) {
E 8
		severe = 1;
E 7
D 8
	return (pattern < 0 || pattern >= npatterns);
E 8
I 8
		cp = prompt("How many passes (up to 48)? ");
		maxpass = atoi(cp);
		if (maxpass > NPT)
			maxpass = NPT;
	}
I 11
	maxeccbits = getnum(
		"Maximum number of bit errors to allow for soft ECC",
		0, 11, MAXECCBITS);
E 11
	return (0);
E 8
}

struct xsect {
	u_short	hd1;
	u_short	hd2;
	long	buf[128];
};

/*
 * Initialize the buffer with the requested pattern. 
 */
bufinit(bp, size)
	register struct xsect *bp;
	int size;
{
	register struct pattern *pptr;
	register long *pp, *last;
	register struct xsect *lastbuf;
I 7
	int patt;
E 7

	size /= sizeof (struct sector);
	lastbuf = bp + size;
D 7
	pptr = &pat[pattern];
E 7
I 7
	if (severe) {
		patt = ppat[npat] | ((long)ppat[npat] << 16);
		printf("Write pattern 0x%x\n", patt&0xffff);
	} else {
		pptr = &pat[pattern];
		patt = pptr->pa_value;
	}
E 7
	while (bp < lastbuf) {
		last = &bp->buf[128];
		for (pp = bp->buf; pp < last; pp++)
D 7
			*pp = pptr->pa_value;
E 7
I 7
			*pp = patt;
E 7
		bp++;
	}
E 2
}

char *
prompt(msg)
	char *msg;
{
	static char buf[132];

	printf("%s", msg);
	gets(buf);
	return (buf);
}
E 1
