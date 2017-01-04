h57838
s 00015/00004/00631
d D 5.15 88/07/12 19:09:51 karels 24 23
c update copyright
e
s 00023/00014/00612
d D 5.14 88/07/09 19:00:47 karels 23 22
c resynch bad sector file, use new-style format ops
e
s 00023/00005/00603
d D 5.13 88/03/15 16:21:55 karels 22 21
c needed seek *inside* the loop for retries; add (undoc) -# flag
c to look at alternate badsector files
e
s 00001/00001/00607
d D 5.12 87/12/26 12:22:42 bostic 21 20
c cast constant to u_short; fix for ANSI C
e
s 00001/00001/00607
d D 5.11 87/10/22 11:27:47 bostic 20 19
c ANSI C; sprintf now returns an int.
e
s 00012/00019/00596
d D 5.10 87/10/05 14:23:30 karels 19 17
c check the right table
e
s 00005/00003/00612
d R 5.10 87/10/05 11:23:55 karels 18 17
c fix unsigned problem looking for end of table
e
s 00000/00016/00615
d D 5.9 87/06/30 13:58:43 bostic 17 16
c remove vax specific stuff
e
s 00017/00004/00614
d D 5.8 87/06/19 12:57:53 karels 16 15
c fix usage, don't allow dups with -a
e
s 00003/00003/00615
d D 5.7 87/06/18 11:38:38 karels 15 14
c if old sector can't be read, still clear the "good" bit
c bug report 4.3BSD/etc/70
e
s 00016/00000/00602
d D 5.6 87/06/02 14:21:21 bostic 14 13
c bad144 is vax specific
e
s 00088/00056/00514
d D 5.5 87/04/02 11:24:20 karels 13 12
c convert to pack labels (untested!)
e
s 00030/00022/00540
d D 5.4 86/03/20 20:49:21 lepreau 12 11
c fix length of sector i/o; fix unused struct names; -n forces -v; lint.
e
s 00102/00030/00460
d D 5.3 85/10/28 19:10:32 karels 11 10
c format the right sectors!; add -n to watch first; more careful
c about reading old header/sector in format; don't exit on error unless fatal
e
s 00024/00008/00466
d D 5.2 85/08/05 13:37:57 karels 10 9
c fix sort for sectors on same cyl; remove a few explicit 512's
e
s 00014/00002/00460
d D 5.1 85/06/06 10:59:57 dist 9 8
c Add copyright
e
s 00279/00065/00183
d D 4.8 84/03/22 15:32:35 karels 8 7
c add -a option to add new bad sectors, rearranging replacements
c as required
e
s 00000/00002/00248
d D 4.7 83/07/27 22:59:53 helge 7 6
c ooops, forgot a debug printf...
e
s 00008/00011/00242
d D 4.6 83/07/26 20:43:02 helge 6 5
c fixed some minor bugs, tested
e
s 00056/00037/00197
d D 4.5 83/06/12 02:20:25 sam 5 4
c generalize formatting; be very cautious when writing sectors
e
s 00095/00005/00139
d D 4.4 83/02/23 20:33:05 sam 4 3
c add stuff to mark sectors bad on-line (for rp06 right now)
e
s 00029/00043/00115
d D 4.3 83/02/20 16:23:15 sam 3 2
c uses disktab now
e
s 00001/00001/00157
d D 4.2 81/05/11 03:27:14 root 2 1
c bt-magic -> bt_mbz
e
s 00158/00000/00000
d D 4.1 81/05/10 19:22:34 root 1 0
c date and time created 81/05/10 19:22:34 by root
e
u
U
t
T
I 9
/*
D 13
 * Copyright (c) 1980 Regents of the University of California.
E 13
I 13
D 24
 * Copyright (c) 1980,1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 24
I 24
 * Copyright (c) 1980,1986,1988 Regents of the University of California.
 * All rights reserved.
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
E 24
 */

E 9
I 5
#ifndef lint
E 5
I 1
D 9
static	char *sccsid = "%W% (Berkeley) %E%";
I 5
#endif
E 9
I 9
char copyright[] =
D 24
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 24
I 24
"%Z% Copyright (c) 1980,1986,1988 Regents of the University of California.\n\
E 24
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 5

I 14
D 17
#ifdef vax

E 17
E 14
/*
 * bad144
 *
 * This program prints and/or initializes a bad block record for a pack,
 * in the format used by the DEC standard 144.
I 8
 * It can also add bad sector(s) to the record, moving the sector
 * replacements as necessary.
E 8
 *
D 8
 * BUGS:
 *	Only reads/writes the first of the bad block record (sector 0
 *	of the last track of the disk); in fact, there are copies
 *	of the information in the first 5 even numbered sectors of this
 *	track, but UNIX uses only the first, and we don't bother with the
 *	others.
 *
E 8
 * It is preferable to write the bad information with a standard formatter,
D 8
 * but this program will do in a pinch, e.g. if the bad information is
 * accidentally wiped out this is a much faster way of restoring it than
D 4
 * reformatting.  To add a new bad sector the formatter must be used in
 * general since UNIX doesn't have on-line formatters to write the BSE
 * error in the header.  The
E 4
I 4
 * reformatting. 
E 8
I 8
 * but this program will do.
E 8
 * 
D 5
 * For the RP06 the -f flag may be used to mark a sector as bad by
 * inverting the format bit in the header and writing the sector header.
 * One should be able to do this on all drives ... as soon as someone
 * puts the time into it.
E 5
I 5
 * RP06 sectors are marked as bad by inverting the format bit in the
D 8
 * header; on other drives the BSE bit is set.
E 8
I 8
 * header; on other drives the valid-sector bit is cleared.
E 8
E 5
E 4
 */
D 13
#include <sys/types.h>
E 13
I 13
#include <sys/param.h>
E 13
#include <sys/dkbad.h>
I 4
#include <sys/ioctl.h>
I 13
#include <sys/fs.h>
E 13
I 5
#include <sys/file.h>
E 5
D 13
#include <machine/dkio.h>
E 13
E 4
I 3

E 3
#include <stdio.h>
I 3
D 13
#include <disktab.h>
E 13
I 13
#include <sys/disklabel.h>
E 13
E 3

I 4
D 8
int	fflag;
E 4
D 3
struct diskinfo {
	char	*di_type;	/* type name of disk */
	int	di_size;	/* size of entire volume in sectors */
	int	di_nsect;	/* sectors per track */
	int	di_ntrak;	/* tracks per cylinder */
} diskinfo[] = {
	"rk06",		22*3*411,	22,	3,
	"rk07",		22*3*815,	22,	3,
	"rm03",		32*5*823,	32,	5,
	"rm05",		32*19*823,	32,	19,
	"rp06",		22*19*815,	22,	19,
	"rm80",		31*14*559,	31,	14,
	"rp05",		22*19*411,	22,	19,
	"rp07",		50*32*630,	50,	32,
	0,
};
E 3
struct	dkbad dkbad;
E 8
I 8
D 11
int	fflag, add, copy, verbose;
E 11
I 11
#define RETRIES	10		/* number of retries on reading old sectors */
I 16
#define	RAWPART	"c"		/* disk partition containing badsector tables */
E 16

int	fflag, add, copy, verbose, nflag;
E 11
int	compare();
I 16
int	dups;
I 22
int	badfile = -1;		/* copy of badsector table to use, -1 if any */
E 22
E 16
D 13
struct	dkbad dkbad, oldbad;
E 13
I 13
#define MAXSECSIZE	1024
D 19
#ifndef SCS
E 19
struct	dkbad curbad, oldbad;
#define	DKBAD_MAGIC	0
D 19
#else SCS
union {
	struct dkbad bd;
	char buf[MAXSECSIZE];
} currentbad, previousbad;
#define	curbad	currentbad.bd
#define oldbad	previousbad.bd
#endif SCS
E 19

char	label[BBSIZE];
E 13
daddr_t	size, getold(), badsn();
D 13
struct	disktab *dp;
E 13
I 13
struct	disklabel *dp;
E 13
char	name[BUFSIZ];
I 10
char	*malloc();
I 12
off_t	lseek();
E 12
E 10
E 8

main(argc, argv)
	int argc;
D 5
	char **argv;
E 5
I 5
	char *argv[];
E 5
{
D 3
	register struct diskinfo *di;
E 3
	register struct bt_bad *bt;
I 3
D 8
	register struct disktab *dp;
E 3
	char name[BUFSIZ];
D 3
	int i, f, bad, oldbad, errs;
E 3
I 3
	int size, i, f, bad, oldbad, errs;
E 8
I 8
	daddr_t	sn, bn[126];
	int i, f, nbad, new, bad, errs;
E 8
E 3

	argc--, argv++;
I 4
D 8
	if (argc > 0 && strcmp(*argv, "-f") == 0) {
E 8
I 8
	while (argc > 0 && **argv == '-') {
		(*argv)++;
		while (**argv) {
			switch (**argv) {
I 13
#if vax
E 13
			    case 'f':
				fflag++;
				break;
I 13
#endif
E 13
			    case 'a':
				add++;
				break;
			    case 'c':
				copy++;
				break;
			    case 'v':
				verbose++;
				break;
I 11
			    case 'n':
				nflag++;
I 12
				verbose++;
E 12
				break;
I 13
			    default:
I 22
				if (**argv >= '0' && **argv <= '4') {
					badfile = **argv - '0';
					break;
				}
E 22
				goto usage;
E 13
E 11
			}
			(*argv)++;
		}
E 8
		argc--, argv++;
D 8
		fflag++;
E 8
	}
E 4
D 13
	if (argc < 2) {
E 13
I 13
	if (argc < 1) {
usage:
E 13
D 3
		fprintf(stderr, "usage: bad type disk [ snum [ bn ... ] ]\n");
		fprintf(stderr, "e.g.: bad rk07 hk0\n");
E 3
I 3
D 4
		fprintf(stderr, "usage: bad144 type disk [ snum [ bn ... ] ]\n");
E 4
I 4
		fprintf(stderr,
D 13
		  "usage: bad144 [ -f ] type disk [ snum [ bn ... ] ]\n");
E 13
I 13
		  "usage: bad144 [ -f ] disk [ snum [ bn ... ] ]\n");
E 13
E 4
D 8
		fprintf(stderr, "e.g.: bad144 rk07 hk0\n");
E 8
I 8
		fprintf(stderr,
D 16
	      "to read or overwrite bad-sector table, e.g.: bad144 rk07 hk0\n");
E 16
I 16
	      "to read or overwrite bad-sector table, e.g.: bad144 hp0\n");
E 16
		fprintf(stderr,
D 13
		  "or bad144 -a [ -f ] [ -c ] type disk  bn ...\n");
E 13
I 13
		  "or bad144 -a [ -f ] [ -c ] disk  bn ...\n");
E 13
		fprintf(stderr, "where options are:\n");
		fprintf(stderr, "\t-a  add new bad sectors to the table\n");
		fprintf(stderr, "\t-f  reformat listed sectors as bad\n");
		fprintf(stderr, "\t-c  copy original sector to replacement\n");
E 8
E 3
		exit(1);
	}
D 3
	for (di = diskinfo; di->di_type; di++)
		if (!strcmp(di->di_type, argv[0]))
			goto found;
	fprintf(stderr, "%s: not a known disk type\n", argv[0]);
	fprintf(stderr, "known types:");
	for (di = diskinfo; di->di_type; di++)
		fprintf(stderr, " %s", di->di_type);
	fprintf(stderr, "\n");
	exit(1);
found:
E 3
I 3
D 13
	dp = getdiskbyname(argv[0]);
	if (dp == NULL) {
		fprintf(stderr, "%s: unknown disk type\n", argv[0]);
E 13
I 13
	if (argv[0][0] != '/')
D 16
		sprintf(name, "/dev/r%sc", argv[0]);
E 16
I 16
D 20
		sprintf(name, "/dev/r%s%s", argv[0], RAWPART);
E 20
I 20
		(void)sprintf(name, "/dev/r%s%s", argv[0], RAWPART);
E 20
E 16
	else
		strcpy(name, argv[0]);
	f = open(name, argc == 1? O_RDONLY : O_RDWR);
	if (f < 0)
		Perror(name);
	if (read(f, label, sizeof(label)) < 0) 
		Perror("read");
	for (dp = (struct disklabel *)(label + LABELOFFSET);
	    dp < (struct disklabel *)
		(label + sizeof(label) - sizeof(struct disklabel));
	    dp = (struct disklabel *)((char *)dp + 64))
		if (dp->d_magic == DISKMAGIC && dp->d_magic2 == DISKMAGIC)
			break;
	if (dp->d_magic != DISKMAGIC || dp->d_magic2 != DISKMAGIC) {
		fprintf(stderr, "Bad pack magic number (pack is unlabeled)\n");
E 13
		exit(1);
	}
E 3
D 8
	sprintf(name, "/dev/r%sc", argv[1]);
E 8
I 8
D 13
	if (argv[1][0] != '/')
D 12
		sprintf(name, "/dev/r%sc", argv[1]);
E 12
I 12
		(void)sprintf(name, "/dev/r%sc", argv[1]);
E 12
	else
D 12
		strcpy(name, argv[1]);
E 12
I 12
		(void)strcpy(name, argv[1]);
E 12
E 8
	argc -= 2;
	argv += 2;
E 13
I 13
	if (dp->d_secsize > MAXSECSIZE || dp->d_secsize <= 0) {
		fprintf(stderr, "Disk sector size too large/small (%d)\n",
			dp->d_secsize);
		exit(7);
	}
E 13
I 3
	size = dp->d_nsectors * dp->d_ntracks * dp->d_ncylinders; 
I 13
	argc--;
	argv++;
E 13
E 3
	if (argc == 0) {
D 5
		f = open(name, 0);
		if (f < 0) {
			perror(name);
			exit(1);
		}
D 3
		lseek(f, 512 * (di->di_size - di->di_nsect), 0);
E 3
I 3
		lseek(f, dp->d_secsize * (size - dp->d_nsectors), 0);
E 5
I 5
D 13
		f = open(name, O_RDONLY);
		if (f < 0)
			Perror(name);
D 8
		if (lseek(f, dp->d_secsize*(size-dp->d_nsectors), L_SET) < 0)
			Perror("lseek");
E 8
I 8
		sn = getold(f, &dkbad);
E 13
I 13
D 19
		sn = getold(f, &curbad);
E 19
I 19
		sn = getold(f, &oldbad);
E 19
E 13
E 8
E 5
E 3
D 6
		printf("bad block information at 0x%x in %s:\n",
		    tell(f), name);
E 6
I 6
		printf("bad block information at sector %d in %s:\n",
D 8
		    tell(f)/512, name);
E 6
		if (read(f, &dkbad, sizeof (struct dkbad)) !=
		    sizeof (struct dkbad)) {
D 5
			fprintf("%s: can't read bad block info (wrong type disk?)\n");
E 5
I 5
			fprintf("bad144: %s: can't read bad block info\n");
E 5
			exit(1);
		}
		printf("cartidge serial number: %d(10)\n", dkbad.bt_csn);
E 8
I 8
		    sn, name);
D 13
		printf("cartridge serial number: %d(10)\n", dkbad.bt_csn);
E 8
		switch (dkbad.bt_flag) {
E 13
I 13
D 19
		printf("cartridge serial number: %d(10)\n", curbad.bt_csn);
		switch (curbad.bt_flag) {
E 19
I 19
		printf("cartridge serial number: %d(10)\n", oldbad.bt_csn);
		switch (oldbad.bt_flag) {
E 19
E 13
I 3

E 3
D 21
		case -1:
E 21
I 21
		case (u_short)-1:
E 21
			printf("alignment cartridge\n");
			break;
I 3

E 3
D 13
		case 0:
E 13
I 13
		case DKBAD_MAGIC:
E 13
			break;
I 3

E 3
		default:
D 13
			printf("bt_flag=%x(16)?\n", dkbad.bt_flag);
E 13
I 13
D 19
			printf("bt_flag=%x(16)?\n", curbad.bt_flag);
E 19
I 19
			printf("bt_flag=%x(16)?\n", oldbad.bt_flag);
E 19
E 13
			break;
		}
D 8
		oldbad = 0;
E 8
D 13
		bt = dkbad.bt_bad;
E 13
I 13
D 19
		bt = curbad.bt_bad;
E 19
I 19
		bt = oldbad.bt_bad;
E 19
E 13
D 8
		for (i = 0; i < 128; i++) {
E 8
I 8
		for (i = 0; i < 126; i++) {
E 8
			bad = (bt->bt_cyl<<16) + bt->bt_trksec;
			if (bad < 0)
				break;
D 8
			printf("sn=%d, cn=%d, tn=%d, sn=%d\n",
D 3
			    (bt->bt_cyl*di->di_ntrak + (bt->bt_trksec>>8)) *
				di->di_nsect + (bt->bt_trksec&0xff),
E 3
I 3
			    (bt->bt_cyl*dp->d_ntracks + (bt->bt_trksec>>8)) *
				dp->d_nsectors + (bt->bt_trksec&0xff),
E 8
I 8
			printf("sn=%d, cn=%d, tn=%d, sn=%d\n", badsn(bt),
E 8
E 3
			    bt->bt_cyl, bt->bt_trksec>>8, bt->bt_trksec&0xff);
			bt++;
		}
I 11
D 19
		(void) checkold();
E 19
I 19
		(void) checkold(&oldbad);
E 19
E 11
D 5
		exit (0);
E 5
I 5
		exit(0);
E 5
	}
D 4
	f = open(name, 1);
E 4
I 4
D 8
	f = open(name, 1 + fflag);
E 8
I 8
D 13
	f = open(name, (fflag || add)? O_RDWR: O_WRONLY);
E 8
E 4
D 5
	if (f < 0) {
		perror(name);
		exit(1);
	}
E 5
I 5
	if (f < 0)
		Perror(name);
E 13
E 5
D 8
	dkbad.bt_csn = atoi(*argv++);
	argc--;
D 2
	dkbad.bt_magic = 0;
E 2
I 2
	dkbad.bt_mbz = 0;
E 2
D 3
	if (argc > 2 * di->di_nsect || argc > 126) {
		printf("bad: too many bad sectors specified\n");
		if (2 * di->di_nsect > 126)
E 3
I 3
D 6
	if (argc > 2 * dp->d_nsectors || argc > 126) {
E 6
I 6
	if (argc > 126) {
E 6
		printf("bad144: too many bad sectors specified\n");
D 6
		if (2 * dp->d_nsectors > 126)
E 3
			printf("limited to 126 by information format\n");
		else
			printf("limited to %d (only 2 tracks of sectors)\n",
D 3
			    2 * di->di_nsect);
E 3
I 3
			    2 * dp->d_nsectors);
E 6
I 6
		printf("limited to 126 by information format\n");
E 6
E 3
		exit(1);
E 8
I 8
	if (add) {
		/*
		 * Read in the old badsector table.
		 * Verify that it makes sense, and the bad sectors
		 * are in order.  Copy the old table to the new one.
		 */
		(void) getold(f, &oldbad);
D 19
		i = checkold();
E 19
I 19
		i = checkold(&oldbad);
E 19
		if (verbose)
D 13
			printf("Had %d bad sectors\n", i);
E 13
I 13
			printf("Had %d bad sectors, adding %d\n", i, argc);
E 13
		if (i + argc > 126) {
			printf("bad144: not enough room for %d more sectors\n",
				argc);
			printf("limited to 126 by information format\n");
			exit(1);
		}
D 13
		dkbad = oldbad;
E 13
I 13
		curbad = oldbad;
E 13
	} else {
D 13
		dkbad.bt_csn = atoi(*argv++);
E 13
I 13
		curbad.bt_csn = atoi(*argv++);
E 13
		argc--;
D 13
		dkbad.bt_mbz = 0;
E 13
I 13
		curbad.bt_mbz = 0;
		curbad.bt_flag = DKBAD_MAGIC;
E 13
		if (argc > 126) {
			printf("bad144: too many bad sectors specified\n");
			printf("limited to 126 by information format\n");
			exit(1);
		}
		i = 0;
E 8
	}
	errs = 0;
D 8
	i = 0;
E 8
I 8
	new = argc;
E 8
	while (argc > 0) {
D 8
		int sn = atoi(*argv++);
I 3

E 8
I 8
		daddr_t sn = atoi(*argv++);
E 8
E 3
		argc--;
D 3
		if (sn < 0 || sn >= di->di_size) {
E 3
I 3
		if (sn < 0 || sn >= size) {
E 3
D 13
			printf("%d: out of range [0,%d) for %s\n",
D 3
			    sn, di->di_size, di->di_type);
E 3
I 3
			    sn, size, dp->d_name);
E 13
I 13
			printf("%d: out of range [0,%d) for disk %s\n",
			    sn, size, dp->d_typename);
E 13
E 3
			errs++;
I 8
			continue;
E 8
		}
I 8
		bn[i] = sn;
E 8
D 3
		dkbad.bt_bad[i].bt_cyl = sn / (di->di_nsect*di->di_ntrak);
		sn %= (di->di_nsect*di->di_ntrak);
E 3
I 3
D 13
		dkbad.bt_bad[i].bt_cyl = sn / (dp->d_nsectors*dp->d_ntracks);
E 13
I 13
		curbad.bt_bad[i].bt_cyl = sn / (dp->d_nsectors*dp->d_ntracks);
E 13
		sn %= (dp->d_nsectors*dp->d_ntracks);
E 3
D 13
		dkbad.bt_bad[i].bt_trksec =
E 13
I 13
		curbad.bt_bad[i].bt_trksec =
E 13
D 3
		    ((sn/di->di_nsect) << 8) + (sn%di->di_nsect);
E 3
I 3
		    ((sn/dp->d_nsectors) << 8) + (sn%dp->d_nsectors);
E 3
		i++;
	}
I 8
	if (errs)
		exit(1);
	nbad = i;
E 8
	while (i < 126) {
D 13
		dkbad.bt_bad[i].bt_trksec = -1;
		dkbad.bt_bad[i].bt_cyl = -1;
E 13
I 13
		curbad.bt_bad[i].bt_trksec = -1;
		curbad.bt_bad[i].bt_cyl = -1;
E 13
		i++;
	}
D 8
	if (errs)
		exit(1);
D 3
	lseek(f, 512 * (di->di_size - di->di_nsect), 0);
E 3
I 3
D 5
	lseek(f, dp->d_secsize * (size - dp->d_nsectors), 0);
E 3
	if (write(f, (caddr_t)&dkbad, sizeof (dkbad)) != sizeof (dkbad)) {
		perror(name);
		exit(1);
	}
E 5
I 5
	if (lseek(f, dp->d_secsize * (size - dp->d_nsectors), L_SET) < 0)
		Perror("lseek");
	if (write(f, (caddr_t)&dkbad, sizeof (dkbad)) != sizeof (dkbad))
		Perror(name);
E 8
I 8
	if (add) {
		/*
		 * Sort the new bad sectors into the list.
		 * Then shuffle the replacement sectors so that
		 * the previous bad sectors get the same replacement data.
		 */
D 12
		qsort(dkbad.bt_bad, nbad, sizeof (struct bt_bad), compare);
E 12
I 12
D 13
		qsort((char *)dkbad.bt_bad, nbad, sizeof (struct bt_bad),
E 13
I 13
		qsort((char *)curbad.bt_bad, nbad, sizeof (struct bt_bad),
E 13
		    compare);
I 16
		if (dups) {
			fprintf(stderr,
"bad144: bad sectors have been duplicated; can't add existing sectors\n");
			exit(3);
		}
E 16
E 12
		shift(f, nbad, nbad-new);
	}
D 10
	for (i = 0; i < 10; i += 2) {
E 10
I 10
D 22
	for (i = 0; i < 10 && i < dp->d_nsectors; i += 2) {
E 22
I 22
	if (badfile == -1)
		i = 0;
	else
		i = badfile * 2;
	for (; i < 10 && i < dp->d_nsectors; i += 2) {
E 22
E 10
		if (lseek(f, dp->d_secsize * (size - dp->d_nsectors + i),
		    L_SET) < 0)
			Perror("lseek");
		if (verbose)
			printf("write badsect file at %d\n",
				size - dp->d_nsectors + i);
D 11
		if (write(f, (caddr_t)&dkbad, sizeof dkbad) != sizeof dkbad) {
E 11
I 11
D 13
		if (nflag == 0 &&
		    write(f, (caddr_t)&dkbad, sizeof dkbad) != sizeof dkbad) {
E 13
I 13
		if (nflag == 0 && write(f, (caddr_t)&curbad, sizeof(curbad)) !=
		    sizeof(curbad)) {
E 13
E 11
			char msg[80];
D 12
			sprintf(msg, "bad144: write bad sector file %d", i/2);
E 12
I 12
			(void)sprintf(msg, "bad144: write bad sector file %d",
			    i/2);
E 12
			perror(msg);
		}
I 22
		if (badfile != -1)
			break;
E 22
	}
E 8
E 5
I 4
D 13
	if (fflag)
E 13
I 13
#ifdef vax
	if (nflag == 0 && fflag)
E 13
D 6
		for (i = 0, bt = dkbad.bt_bad; i < 128; i++, bt++) {
E 6
I 6
D 8
		for (i = 0, bt = dkbad.bt_bad; i < 126; i++, bt++) {
E 6
			daddr_t bn;
E 8
I 8
D 11
		for (i = 0; i < new; i++)
E 11
I 11
		for (i = nbad - new; i < nbad; i++)
E 11
			format(f, bn[i]);
I 13
#endif
I 23
#ifdef DIOCSBAD
	if (nflag == 0 && ioctl(f, DIOCSBAD, (caddr_t)&curbad) < 0)
		fprintf(stderr,
	"Can't sync bad-sector file; reboot for changes to take effect\n");
#endif
E 23
E 13
	exit(0);
}
E 8

D 8
			bad = (bt->bt_cyl<<16) + bt->bt_trksec;
			if (bad < 0)
				break;
			bn = (bt->bt_cyl * dp->d_ntracks +
			    (bt->bt_trksec >> 8)) *
			    dp->d_nsectors + (bt->bt_trksec & 0xff);
			format(f, dp, bn);
E 8
I 8
daddr_t
getold(f, bad)
struct dkbad *bad;
{
	register int i;
	daddr_t sn;
	char msg[80];

D 10
	for (i = 0; i < 10; i += 2) {
E 10
I 10
D 22
	for (i = 0; i < 10 && i < dp->d_nsectors; i += 2) {
E 22
I 22
	if (badfile == -1)
		i = 0;
	else
		i = badfile * 2;
	for (; i < 10 && i < dp->d_nsectors; i += 2) {
E 22
E 10
		sn = size - dp->d_nsectors + i;
		if (lseek(f, sn * dp->d_secsize, L_SET) < 0)
			Perror("lseek");
D 12
		if (read(f, bad, sizeof (*bad)) == sizeof (*bad)) {
E 12
I 12
D 13
		if (read(f, (char *)bad, sizeof (*bad)) == sizeof (*bad)) {
E 13
I 13
		if (read(f, (char *) bad, dp->d_secsize) == dp->d_secsize) {
E 13
E 12
			if (i > 0)
				printf("Using bad-sector file %d\n", i/2);
			return(sn);
E 8
		}
E 4
D 8
	exit(0);
E 8
I 8
D 12
		sprintf(msg, "bad144: read bad sector file at sn %d", sn);
E 12
I 12
D 13
		(void)sprintf(msg, "bad144: read bad sector file at sn %d",
		    sn);
E 13
I 13
		(void)sprintf(msg, "bad144: read bad sector file at sn %d", sn);
E 13
E 12
		perror(msg);
I 22
		if (badfile != -1)
			break;
E 22
	}
D 13
	fprintf(stderr,
	    "bad144: %s: can't read bad block info\n", name);
E 13
I 13
	fprintf(stderr, "bad144: %s: can't read bad block info\n", name);
E 13
	exit(1);
I 12
	/*NOTREACHED*/
E 12
E 8
I 4
}

I 8
checkold()
{
	register int i;
	register struct bt_bad *bt;
	daddr_t sn, lsn;
I 11
	int errors = 0, warned = 0;
E 11

D 13
	if (oldbad.bt_flag != 0) {
E 13
I 13
	if (oldbad.bt_flag != DKBAD_MAGIC) {
E 13
		fprintf(stderr, "bad144: %s: bad flag in bad-sector table\n",
			name);
D 11
		exit(1);
E 11
I 11
		errors++;
E 11
	}
	if (oldbad.bt_mbz != 0) {
		fprintf(stderr, "bad144: %s: bad magic number\n", name);
D 11
		exit(1);
E 11
I 11
		errors++;
E 11
	}
D 16
	lsn = 0;
E 16
	bt = oldbad.bt_bad;
	for (i = 0; i < 126; i++, bt++) {
D 19
		if (bt->bt_cyl == -1 && bt->bt_trksec == -1)
E 19
I 19
		if (bt->bt_cyl == 0xffff && bt->bt_trksec == 0xffff)
E 19
			break;
		if ((bt->bt_cyl >= dp->d_ncylinders) ||
		    ((bt->bt_trksec >> 8) >= dp->d_ntracks) ||
		    ((bt->bt_trksec & 0xff) >= dp->d_nsectors)) {
D 11
			fprintf(stderr, "bad144: cyl/sect/trk out of range\n");
			exit(1);
E 11
I 11
			fprintf(stderr,
		     "bad144: cyl/trk/sect out of range in existing entry: ");
			fprintf(stderr, "sn=%d, cn=%d, tn=%d, sn=%d\n",
				badsn(bt), bt->bt_cyl, bt->bt_trksec>>8,
				bt->bt_trksec & 0xff);
			errors++;
E 11
		}
		sn = (bt->bt_cyl * dp->d_ntracks +
		    (bt->bt_trksec >> 8)) *
		    dp->d_nsectors + (bt->bt_trksec & 0xff);
D 11
		if (sn < lsn) {
E 11
I 11
D 16
		if (sn < lsn && !warned) {
E 16
I 16
		if (i > 0 && sn < lsn && !warned) {
E 16
E 11
D 19
		    fprintf(stderr, "bad144: bad sector file out of order\n");
E 19
I 19
		    fprintf(stderr,
			"bad144: bad sector file is out of order\n");
E 19
D 11
		    exit(1);
E 11
I 11
		    errors++;
		    warned++;
E 11
		}
I 16
		if (i > 0 && sn == lsn) {
		    fprintf(stderr,
D 19
			"bad144: bad sector file contains duplicates\n");
E 19
I 19
			"bad144: bad sector file contains duplicates (sn %d)\n",
			sn);
E 19
		    errors++;
		}
E 16
		lsn = sn;
	}
D 11
	return i;
E 11
I 11
	if (errors)
		exit(1);
	return (i);
E 11
}

/*
 * Move the bad sector replacements
 * to make room for the new bad sectors.
 * new is the new number of bad sectors, old is the previous count.
 */
shift(f, new, old)
{
	daddr_t repl;

	/*
	 * First replacement is last sector of second-to-last track.
	 */
	repl = size - dp->d_nsectors - 1;
	new--; old--;
	while (new >= 0 && new != old) {
		if (old < 0 ||
D 13
		    compare(&dkbad.bt_bad[new], &oldbad.bt_bad[old]) > 0) {
E 13
I 13
		    compare(&curbad.bt_bad[new], &oldbad.bt_bad[old]) > 0) {
E 13
			/*
			 * Insert new replacement here-- copy original
			 * sector if requested and possible,
			 * otherwise write a zero block.
			 */
			if (!copy ||
D 13
			    !blkcopy(f, badsn(&dkbad.bt_bad[new]), repl - new))
E 13
I 13
			    !blkcopy(f, badsn(&curbad.bt_bad[new]), repl - new))
E 13
				blkzero(f, repl - new);
		} else {
			if (blkcopy(f, repl - old, repl - new) == 0)
			    fprintf(stderr,
				"Can't copy replacement sector %d to %d\n",
				repl-old, repl-new);
			old--;
		}
		new--;
	}
}

I 10
char *buf;

E 10
/*
 *  Copy disk sector s1 to s2.
 */
blkcopy(f, s1, s2)
daddr_t s1, s2;
{
I 11
	register tries, n;
E 11
D 10
	char buf[512];
E 10

I 10
	if (buf == (char *)NULL) {
D 12
		buf = malloc(dp->d_secsize);
E 12
I 12
		buf = malloc((unsigned)dp->d_secsize);
E 12
		if (buf == (char *)NULL) {
			fprintf(stderr, "Out of memory\n");
			exit(20);
		}
	}
E 10
D 22
	if (lseek(f, dp->d_secsize * s1, L_SET) < 0)
		Perror("lseek");
D 11
	if (read(f, buf, sizeof (buf)) != sizeof (buf)) {
		if (verbose)
			fprintf(stderr, "bad144: can't read sector, %d\n", s1);
E 11
I 11
	for (tries = 0; tries < RETRIES; tries++)
E 22
I 22
	for (tries = 0; tries < RETRIES; tries++) {
		if (lseek(f, dp->d_secsize * s1, L_SET) < 0)
			Perror("lseek");
E 22
D 12
		if ((n = read(f, buf, sizeof (buf))) == sizeof (buf))
E 12
I 12
		if ((n = read(f, buf, dp->d_secsize)) == dp->d_secsize)
E 12
			break;
I 22
	}
E 22
D 12
	if (n != sizeof (buf)) {
E 12
I 12
	if (n != dp->d_secsize) {
E 12
		fprintf(stderr, "bad144: can't read sector, %d: ", s1);
		if (n < 0)
D 12
			perror(0);
E 12
I 12
			perror((char *)0);
E 12
E 11
		return(0);
	}
	if (lseek(f, dp->d_secsize * s2, L_SET) < 0)
		Perror("lseek");
	if (verbose)
		printf("copying %d to %d\n", s1, s2);
D 11
	if (write(f, buf, sizeof (buf)) != sizeof (buf)) {
E 11
I 11
D 12
	if (nflag == 0 && write(f, buf, sizeof (buf)) != sizeof (buf)) {
E 12
I 12
	if (nflag == 0 && write(f, buf, dp->d_secsize) != dp->d_secsize) {
E 12
E 11
		fprintf(stderr,
D 11
		    "bad144: can't write replacement sector, %d\n", s2);
E 11
I 11
		    "bad144: can't write replacement sector, %d: ", s2);
D 12
		perror(0);
E 12
I 12
		perror((char *)0);
E 12
E 11
		return(0);
	}
	return(1);
}

D 10
char zbuf[512];
E 10
I 10
char *zbuf;
E 10

blkzero(f, sn)
daddr_t sn;
{

I 10
	if (zbuf == (char *)NULL) {
D 12
		zbuf = malloc(dp->d_secsize);
E 12
I 12
		zbuf = malloc((unsigned)dp->d_secsize);
E 12
		if (zbuf == (char *)NULL) {
			fprintf(stderr, "Out of memory\n");
			exit(20);
		}
	}
E 10
	if (lseek(f, dp->d_secsize * sn, L_SET) < 0)
		Perror("lseek");
	if (verbose)
		printf("zeroing %d\n", sn);
D 11
	if (write(f, zbuf, sizeof (zbuf)) != sizeof (zbuf)) {
E 11
I 11
D 12
	if (nflag == 0 && write(f, zbuf, sizeof (zbuf)) != sizeof (zbuf)) {
E 12
I 12
	if (nflag == 0 && write(f, zbuf, dp->d_secsize) != dp->d_secsize) {
E 12
E 11
		fprintf(stderr,
D 11
		    "bad144: can't write replacement sector, %d\n", sn);
		exit(1);
E 11
I 11
		    "bad144: can't write replacement sector, %d: ", sn);
D 12
		perror(0);
E 12
I 12
		perror((char *)0);
E 12
E 11
	}
}

compare(b1, b2)
register struct bt_bad *b1, *b2;
{
	if (b1->bt_cyl > b2->bt_cyl)
		return(1);
	if (b1->bt_cyl < b2->bt_cyl)
		return(-1);
I 16
	if (b1->bt_trksec == b2->bt_trksec)
		dups++;
E 16
D 10
	return (b2->bt_trksec - b1->bt_trksec);
E 10
I 10
	return (b1->bt_trksec - b2->bt_trksec);
E 10
}

daddr_t
badsn(bt)
register struct bt_bad *bt;
{
	return ((bt->bt_cyl*dp->d_ntracks + (bt->bt_trksec>>8)) * dp->d_nsectors
		+ (bt->bt_trksec&0xff));
}

I 13
#ifdef vax
#include <machine/dkio.h>

E 13
E 8
struct rp06hdr {
	short	h_cyl;
	short	h_trksec;
	short	h_key1;
	short	h_key2;
	char	h_data[512];
#define	RP06_FMT	010000		/* 1 == 16 bit, 0 == 18 bit */
};
D 5
int	rp06fmt();
E 5

I 5
/*
 * Most massbus and unibus drives
 * have headers of this form
 */
struct hpuphdr {
	u_short	hpup_cyl;
D 11
	u_short hpup_trksec;
E 11
I 11
	u_char	hpup_sect;
	u_char	hpup_track;
E 11
	char	hpup_data[512];
#define	HPUP_OKSECT	0xc000		/* this normally means sector is good */
I 11
#define	HPUP_16BIT	0x1000		/* 1 == 16 bit format */
E 11
};
I 11
int rp06format(), hpupformat();
E 11

E 5
struct	formats {
	char	*f_name;		/* disk name */
	int	f_bufsize;		/* size of sector + header */
I 5
	int	f_bic;			/* value to bic in hpup_cyl */
E 5
	int	(*f_routine)();		/* routine for special handling */
} formats[] = {
D 5
	{ "rp06",	sizeof (struct rp06hdr),	rp06fmt },
	{ 0, 0, 0 }
E 5
I 5
D 11
	{ "rp06",	sizeof (struct rp06hdr),	RP06_FMT,	0 },
	{ "eagle",	sizeof (struct hpuphdr),	HPUP_OKSECT,	0 },
	{ "capricorn",	sizeof (struct hpuphdr),	HPUP_OKSECT,	0 },
I 8
	{ "rm03",	sizeof (struct hpuphdr),	HPUP_OKSECT,	0 },
	{ "rm05",	sizeof (struct hpuphdr),	HPUP_OKSECT,	0 },
	{ "9300",	sizeof (struct hpuphdr),	HPUP_OKSECT,	0 },
	{ "9766",	sizeof (struct hpuphdr),	HPUP_OKSECT,	0 },
E 11
I 11
	{ "rp06",	sizeof (struct rp06hdr), RP06_FMT,	rp06format },
	{ "eagle",	sizeof (struct hpuphdr), HPUP_OKSECT,	hpupformat },
	{ "capricorn",	sizeof (struct hpuphdr), HPUP_OKSECT,	hpupformat },
	{ "rm03",	sizeof (struct hpuphdr), HPUP_OKSECT,	hpupformat },
	{ "rm05",	sizeof (struct hpuphdr), HPUP_OKSECT,	hpupformat },
	{ "9300",	sizeof (struct hpuphdr), HPUP_OKSECT,	hpupformat },
	{ "9766",	sizeof (struct hpuphdr), HPUP_OKSECT,	hpupformat },
E 11
E 8
	{ 0, 0, 0, 0 }
E 5
};

I 12
/*ARGSUSED*/
E 12
I 11
hpupformat(fp, dp, blk, buf, count)
D 12
	struct format *fp;
E 12
I 12
	struct formats *fp;
E 12
D 13
	struct disktab *dp;
E 13
I 13
	struct disklabel *dp;
E 13
	daddr_t blk;
	char *buf;
	int count;
{
	struct hpuphdr *hdr = (struct hpuphdr *)buf;
	int sect;

	if (count < sizeof(struct hpuphdr)) {
		hdr->hpup_cyl = (HPUP_OKSECT | HPUP_16BIT) |
			(blk / (dp->d_nsectors * dp->d_ntracks));
		sect = blk % (dp->d_nsectors * dp->d_ntracks);
		hdr->hpup_track = (u_char)(sect / dp->d_nsectors);
		hdr->hpup_sect = (u_char)(sect % dp->d_nsectors);
	}
	return (0);
}

I 12
/*ARGSUSED*/
E 12
rp06format(fp, dp, blk, buf, count)
D 12
	struct format *fp;
	struct disklabel *dp;
E 12
I 12
	struct formats *fp;
D 13
	struct disktab *dp;
E 13
I 13
	struct disklabel *dp;
E 13
E 12
	daddr_t blk;
	char *buf;
	int count;
{

	if (count < sizeof(struct rp06hdr)) {
		fprintf(stderr, "Can't read header on blk %d, can't reformat\n",
			blk);
		return (-1);
	}
	return (0);
}

E 11
D 8
format(fd, dp, blk)
E 8
I 8
format(fd, blk)
E 8
	int fd;
D 8
	struct disktab *dp;
E 8
	daddr_t blk;
{
	register struct formats *fp;
D 10
	char *buf, *malloc();
E 10
I 10
D 11
	char *buf;
E 11
I 11
	static char *buf;
	static char bufsize;
I 23
	struct format_op fop;
E 23
	int n;
E 11
E 10

	for (fp = formats; fp->f_name; fp++)
D 13
		if (strcmp(dp->d_name, fp->f_name) == 0)
E 13
I 13
		if (strcmp(dp->d_typename, fp->f_name) == 0)
E 13
			break;
	if (fp->f_name == 0) {
		fprintf(stderr, "bad144: don't know how to format %s disks\n",
D 13
			dp->d_name);
E 13
I 13
			dp->d_typename);
E 13
		exit(2);
	}
D 11
	buf = malloc(fp->f_bufsize);
E 11
I 11
	if (buf && bufsize < fp->f_bufsize) {
		free(buf);
		buf = NULL;
	}
	if (buf == NULL)
D 12
		buf = malloc(fp->f_bufsize);
E 12
I 12
		buf = malloc((unsigned)fp->f_bufsize);
E 12
E 11
	if (buf == NULL) {
		fprintf(stderr, "bad144: can't allocate sector buffer\n");
		exit(3);
	}
I 11
	bufsize = fp->f_bufsize;
E 11
	/*
	 * Here we do the actual formatting.  All we really
	 * do is rewrite the sector header and flag the bad sector
	 * according to the format table description.  If a special
	 * purpose format routine is specified, we allow it to
	 * process the sector as well.
	 */
D 5
	lseek(fd, (long)blk * 512, 0);
	ioctl(fd, DKIOCHDR, 0);
	read(fd, buf, fp->f_bufsize);
E 5
I 5
D 10
	if (lseek(fd, (long)blk * 512, L_SET) < 0)
E 10
I 10
D 23
	if (lseek(fd, (long)blk * dp->d_secsize, L_SET) < 0)
E 10
		Perror("lseek");
E 23
I 8
	if (verbose)
		printf("format blk %d\n", blk);
E 8
D 12
	if (ioctl(fd, DKIOCHDR, 0) < 0)
E 12
I 12
D 23
	if (ioctl(fd, DKIOCHDR, (char *)0) < 0)
E 12
		Perror("ioctl");
D 6
	if (read(fd, buf, fp->f_bufsize) != fp->f_bufsize)
		Perror("read");
E 6
I 6
D 11
	read(fd, buf, fp->f_bufsize);
E 11
I 11
	if ((n = read(fd, buf, fp->f_bufsize)) < 0)
		bzero(buf, fp->f_bufsize);
I 15
	if (fp->f_routine)
		if ((*fp->f_routine)(fp, dp, blk, buf, n) != 0)
			return;
E 23
I 23
	bzero((char *)&fop, sizeof(fop));
	fop.df_buf = buf;
	fop.df_count = fp->f_bufsize;
	fop.df_startblk = blk;
	bzero(buf, fp->f_bufsize);
	if (ioctl(fd, DIOCRFORMAT, &fop) < 0)
		perror("bad144: read format");
	if (fp->f_routine &&
	    (*fp->f_routine)(fp, dp, blk, buf, fop.df_count) != 0)
		return;
E 23
E 15
E 11
E 6
	if (fp->f_bic) {
		struct hpuphdr *xp = (struct hpuphdr *)buf;

		xp->hpup_cyl &= ~fp->f_bic;
	}
E 5
D 15
	if (fp->f_routine)
D 11
		(*fp->f_routine)(fp, dp, blk, buf);
E 11
I 11
		if ((*fp->f_routine)(fp, dp, blk, buf, n) != 0)
			return;
E 15
E 11
I 6
D 7
	printf("formatting blk %d...", blk);
E 7
E 6
D 5
	lseek(fd, (long)blk * 512, 0);
	ioctl(fd, DKIOCHDR, 0);
	write(fd, buf, fp->f_bufsize);
E 5
I 5
D 10
	if (lseek(fd, (long)blk * 512, L_SET) < 0)
E 10
I 10
D 23
	if (lseek(fd, (long)blk * dp->d_secsize, L_SET) < 0)
E 10
		Perror("lseek");
E 23
I 11
	if (nflag)
		return;
E 11
D 12
	if (ioctl(fd, DKIOCHDR, 0) < 0)
E 12
I 12
D 23
	if (ioctl(fd, DKIOCHDR, (char *)0) < 0)
E 12
		Perror("ioctl");
D 8
	if (write(fd, buf, fp->f_bufsize) != fp->f_bufsize)
		Perror("write");
E 8
I 8
	if (write(fd, buf, fp->f_bufsize) != fp->f_bufsize) {
E 23
I 23
	bzero((char *)&fop, sizeof(fop));
	fop.df_buf = buf;
	fop.df_count = fp->f_bufsize;
	fop.df_startblk = blk;
	if (ioctl(fd, DIOCWFORMAT, &fop) < 0)
		Perror("write format");
	if (fop.df_count != fp->f_bufsize) {
E 23
		char msg[80];
D 12
		sprintf(msg, "bad144: write format %d", blk);
E 12
I 12
		(void)sprintf(msg, "bad144: write format %d", blk);
E 12
		perror(msg);
	}
E 8
I 6
D 7
	printf("Done..\n");
E 7
E 6
E 5
}
I 13
#endif
E 13

D 5
rp06fmt(fp, dp, bn, hp)
	struct format *fp;
	struct disktab *dp;
	daddr_t bn;
	struct rp06hdr *hp;
E 5
I 5
Perror(op)
	char *op;
E 5
{

D 5
	hp->h_cyl &= ~RP06_FMT;
E 5
I 5
	fprintf(stderr, "bad144: "); perror(op);
	exit(4);
E 5
E 4
}
I 14
D 17

#else /* !vax */

#include <stdio.h>

main(argc, argv)
	int	argc;
	char	**argv;
{
	fputs("bad144 is a vax specific program.\n", stderr);
	exit(1);
}

#endif /* vax */
E 17
E 14
E 1
