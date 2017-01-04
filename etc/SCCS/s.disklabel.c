h26445
s 00063/00018/01034
d D 5.13 88/06/04 17:14:58 karels 13 12
c allow re-editing if label can't be written back;
c clarify obscure errors
e
s 00181/00063/00871
d D 5.12 88/04/20 12:37:42 karels 12 11
c marc's changes for alternate bootstraps; keith's changes to enable/
c disable writing of label sector; many cleanups
e
s 00005/00006/00929
d D 5.11 87/10/22 10:13:06 bostic 11 10
c ANSI C; sprintf now returns an int.
e
s 00001/00000/00934
d D 5.10 87/09/10 09:22:01 tef 10 9
c flush stdout before calling stderr
e
s 00026/00033/00908
d D 5.9 87/06/19 12:57:16 karels 9 8
c minor cleanups
e
s 00016/00010/00925
d D 5.8 87/06/04 22:27:00 karels 8 7
c more fixes: write boot block if writing, not editing;
c get spaces right around words on multiple-word lines
e
s 00014/00013/00921
d D 5.7 87/06/04 15:54:02 karels 7 6
c handle flags, drivedata correctly
e
s 00069/00024/00865
d D 5.6 87/04/07 21:15:07 karels 6 5
c show, restore fsize, bsize and cpg
e
s 00000/00002/00889
d D 5.5 87/04/01 10:32:01 bostic 5 4
c update of arg processing; special problem diff
e
s 00570/00110/00321
d D 5.4 87/04/01 10:29:41 bostic 4 3
c fold sam's changes in, fix argument processing
e
s 00064/00051/00367
d D 5.3 87/03/27 17:36:53 karels 3 2
c add -r (read/write directly to disk), otherwise use ioctl's;
c isolate vax stuff a bit more; other cleanups
e
s 00022/00010/00396
d D 5.2 87/01/19 15:23:38 karels 2 1
c fix up byteswapping
e
s 00406/00000/00000
d D 5.1 87/01/19 15:23:17 karels 1 0
c date and time created 87/01/19 15:23:17 by karels
e
u
U
t
T
I 4
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
/* from static char sccsid[] = "@(#)disklabel.c	1.2 (Symmetric) 11/28/85"; */
#endif

#include <stdio.h>
#include <ctype.h>
#include <sys/param.h>
I 4
#include <sys/signal.h>
E 4
#include <sys/errno.h>
#include <sys/file.h>
I 3
D 4
#include <sys/fs.h>
E 4
E 3
#include <sys/ioctl.h>
I 4
#include <sys/fs.h>
#include <strings.h>
E 4
#define DKTYPENAMES
#include <sys/disklabel.h>

/*
 * Disklabel: read and write disklabels.
 * The label is usually placed on one of the first sectors of the disk.
 * Many machines (VAX 11/750) also place a bootstrap in the same area,
 * in which case the label is embedded in the bootstrap.
 * The bootstrap source must leave space at the proper offset
 * for the label on such machines.
 */

I 3
#ifdef vax
#define RAWPARTITION	'c'
#else
#define RAWPARTITION	'a'
#endif

#ifndef BBSIZE
E 3
#define	BBSIZE	8192			/* size of boot area, with label */
I 3
#endif
E 3

#ifdef vax
#define	BOOT				/* also have bootstrap in "boot area" */
#define	BOOTDIR	"/usr/mdec"		/* source of boot binaries */
I 3
#else
#ifdef lint
#define	BOOT
E 3
#endif
I 3
#endif
E 3

I 4
#define	DEFEDITOR	"/usr/ucb/vi"
#define	streq(a,b)	(strcmp(a,b) == 0)

E 4
D 9
char	*dkname;
E 9
D 4
char	*dkbasename;
E 4
I 4
#ifdef BOOT
E 4
char	*xxboot;
char	*bootxx;
I 4
#endif
I 9

char	*dkname;
E 9
E 4
char	*specname;
I 4
char	tmpfil[] = "/tmp/EdDk.aXXXXXX";
E 4
D 11
char	*sprintf();
E 11
D 4
char	*rindex();
E 4

extern	int errno;
char	namebuf[BBSIZE], *np = namebuf;
D 9
char	bootarea[BBSIZE];
E 9
struct	disklabel lab;
D 9
struct	disklabel *readlabel(), *getbootarea();
E 9
I 9
struct	disklabel *readlabel(), *makebootarea();
char	bootarea[BBSIZE];
I 12
char	boot0[MAXPATHLEN];
char	boot1[MAXPATHLEN];
E 12
E 9

D 4
int	op;			/* one of: */
#define	READ	1
#define	WRITE	2
#define	EDIT	3
#define	RESTORE	4
E 4
I 4
D 12
enum	{ READ, WRITE, EDIT, RESTORE } op = READ;
E 12
I 12
enum	{ UNSPEC, EDIT, NOWRITE, READ, RESTORE, WRITE, WRITEABLE } op = UNSPEC;
E 12
E 4

I 3
int	rflag;

I 12
#ifdef DEBUG
int	debug;
#endif

E 12
E 3
main(argc, argv)
	int argc;
	char *argv[];
{
I 4
D 12
	extern int	optind;
E 12
I 12
	extern int optind;
E 12
E 4
	register struct disklabel *lp;
D 4
	int f, t;
	char *name = 0, *asciifile, *type;
E 4
I 4
D 12
	FILE	*t;
	int	ch, f;
E 12
I 12
	FILE *t;
D 13
	int ch, f;
E 13
I 13
	int ch, f, error = 0;
E 13
E 12
	char *name = 0, *type;
E 4

D 4
	while (argc > 1 && argv[1][0] == '-') {
		if (strcmp(argv[1], "-e") == 0) {
			if (argc != 3)
				goto usage;
			op = EDIT;
		} else if (strcmp(argv[1], "-w") == 0) {
			if (argc != 4)
				goto usage;
			op = RESTORE;
D 3
		} else
E 3
I 3
		} else if (strcmp(argv[1], "-r") == 0)
			rflag++;
		else
E 3
			goto usage;
		argv++;
		argc--;
	}
	if (argc < 2 || argc > 6) {
usage:
		fprintf(stderr, "%s%s%s%s",
#ifdef BOOT
"usage: disklabel disk    				(to read label)\n",
"or disklabel disk type [ packid ] [ xxboot bootxx ]    (to write label)\n",
"or disklabel -e disk    				(to edit label)\n",
"or disklabel -w disk protofile [ xxboot bootxx ]	(to restore label)\n"
#else
"usage: disklabel disk    			(to read label)\n",
"or disklabel disk type [ packid ]		(to write label)\n",
"or disklabel -e disk    			(to edit label)\n",
"or disklabel -w disk protofile			(to restore label)\n"
#endif
			);
		exit(1);
	}
	if (op == 0)
		if (argc == 2)
			op = READ;
		else
			op = WRITE;
	dkname = argv[1];
E 4
I 4
D 12
	while ((ch = getopt(argc, argv, "Rerw")) != EOF)
		switch((char)ch) {
E 12
I 12
	while ((ch = getopt(argc, argv, "NRWerw")) != EOF)
		switch (ch) {
			case 'N':
				if (op != UNSPEC)
					usage();
				op = NOWRITE;
				break;
E 12
			case 'R':
I 12
				if (op != UNSPEC)
					usage();
E 12
				op = RESTORE;
				break;
I 12
			case 'W':
				if (op != UNSPEC)
					usage();
				op = WRITEABLE;
				break;
E 12
			case 'e':
I 12
				if (op != UNSPEC)
					usage();
E 12
				op = EDIT;
				break;
			case 'r':
				++rflag;
				break;
			case 'w':
I 12
				if (op != UNSPEC)
					usage();
E 12
				op = WRITE;
				break;
I 12
#ifdef DEBUG
			case 'd':
				debug++;
				break;
#endif
E 12
			case '?':
			default:
				usage();
		}
	argc -= optind;
	argv += optind;
I 12
	if (op == UNSPEC)
		op = READ;
E 12
	if (argc < 1)
		usage();

	dkname = argv[0];
E 4
	if (dkname[0] != '/') {
D 3
		sprintf(np, "/dev/r%sc", dkname);
E 3
I 3
D 11
		sprintf(np, "/dev/r%s%c", dkname, RAWPARTITION);
E 11
I 11
		(void)sprintf(np, "/dev/r%s%c", dkname, RAWPARTITION);
E 11
E 3
		specname = np;
		np += strlen(specname) + 1;
	} else
		specname = dkname;
	f = open(specname, op == READ ? O_RDONLY : O_RDWR);
	if (f < 0 && errno == ENOENT && dkname[0] != '/') {
D 11
		sprintf(specname, "/dev/r%s", dkname);
E 11
I 11
		(void)sprintf(specname, "/dev/r%s", dkname);
E 11
		np = namebuf + strlen(specname) + 1;
		f = open(specname, op == READ ? O_RDONLY : O_RDWR);
	}
	if (f < 0)
		Perror(specname);

D 4
	if (op == WRITE) {
		type = argv[2];
		if (argc == 4 || argc == 6) {
			name = argv[3];
			argv++;
			argc--;
		}
	}
	if (op == RESTORE) {
		asciifile = argv[2];
		argv++;
		argc--;
	}
#ifdef BOOT
	if (argc == 5) {
		xxboot = argv[3];
		bootxx = argv[4];
	}
#endif


	switch (op) {

	case READ:
		lp = readlabel(f, 0);
		display(stdout, lp);
		break;

E 4
I 4
	switch(op) {
E 4
	case EDIT:
I 4
		if (argc != 1)
			usage();
E 4
D 9
		lp = readlabel(f, bootarea);
E 9
I 9
D 12
		lp = readlabel(f, rflag);
E 12
I 12
		lp = readlabel(f);
E 12
E 9
D 4
		edit(f, lp);
		writelabel(f, bootarea, lp);
E 4
I 4
D 13
		if (edit(lp))
			writelabel(f, bootarea, lp);
E 13
I 13
		error = edit(lp, f);
E 13
E 4
		break;
I 12
	case NOWRITE: {
		int flag = 0;
		if (ioctl(f, DIOCWLABEL, (char *)&flag) < 0)
			Perror("ioctl DIOCWLABEL");
		break;
	}
E 12
D 4

	case WRITE:
		makelabel(type, name, &lab);
		lp = getbootarea(bootarea, &lab);
		*lp = lab;
		writelabel(f, bootarea, lp);
E 4
I 4
	case READ:
		if (argc != 1)
			usage();
D 9
		lp = readlabel(f, (char *)0);
E 9
I 9
D 12
		lp = readlabel(f, 0);
E 12
I 12
		lp = readlabel(f);
E 12
E 9
		display(stdout, lp);
D 13
		(void) checklabel(lp);
E 13
I 13
		error = checklabel(lp);
E 13
E 4
		break;
D 4

E 4
	case RESTORE:
I 4
#ifdef BOOT
D 12
		if (argc == 4) {
			xxboot = argv[2];
			bootxx = argv[3];
D 9
		}
		else
#else
E 9
I 9
		} else
E 12
I 12
		if (rflag) {
			if (argc == 4) {	/* [ priboot secboot ] */
				xxboot = argv[2];
				bootxx = argv[3];
				lab.d_secsize = DEV_BSIZE;	/* XXX */
				lab.d_bbsize = BBSIZE;		/* XXX */
			}
			else if (argc == 3) 	/* [ disktype ] */
				makelabel(argv[2], (char *)NULL, &lab);
			else {
				fprintf(stderr,
"Must specify either disktype or bootfiles with -r flag of RESTORE option\n");
				exit(1);
			}
		}
		else
E 12
#endif
E 9
		if (argc != 2)
			usage();
D 9
#endif
E 9
E 4
D 12
		lab.d_secsize = DEV_BSIZE;			/* XXX */
		lab.d_bbsize = BBSIZE;				/* XXX */
E 12
D 9
		lp = getbootarea(bootarea, &lab);
E 9
I 9
		lp = makebootarea(bootarea, &lab);
E 9
D 4
		t = open(asciifile, O_RDONLY);
		if (t < 0)
			Perror(asciifile);
		getasciilabel(t, lp);
		writelabel(f, bootarea, lp);
E 4
I 4
		if (!(t = fopen(argv[1],"r")))
			Perror(argv[1]);
I 8
D 12
#ifdef BOOT
		rflag = 1;		/* force bootstrap to be written */
#endif
E 12
E 8
		if (getasciilabel(t, lp))
D 13
			writelabel(f, bootarea, lp);
E 13
I 13
			error = writelabel(f, bootarea, lp);
E 13
E 4
		break;
I 4
	case WRITE:
		type = argv[1];
#ifdef BOOT
		if (argc > 5 || argc < 2)
			usage();
		if (argc > 3) {
			bootxx = argv[--argc];
			xxboot = argv[--argc];
		}
#else
D 5
#ifdef FIX_FOR_LATER
E 5
		if (argc > 3 || argc < 2)
D 5
#endif
E 5
			usage();
#endif
		if (argc > 2)
			name = argv[--argc];
		makelabel(type, name, &lab);
D 9
		lp = getbootarea(bootarea, &lab);
E 9
I 9
		lp = makebootarea(bootarea, &lab);
E 9
		*lp = lab;
I 8
D 12
#ifdef BOOT
		rflag = 1;		/* force bootstrap to be written */
#endif
E 12
E 8
		if (checklabel(lp) == 0)
D 13
			writelabel(f, bootarea, lp);
E 13
I 13
			error = writelabel(f, bootarea, lp);
E 13
		break;
I 12
	case WRITEABLE: {
		int flag = 1;
		if (ioctl(f, DIOCWLABEL, (char *)&flag) < 0)
			Perror("ioctl DIOCWLABEL");
		break;
E 12
E 4
	}
I 12
	}
E 12
D 13
	exit(0);
E 13
I 13
	exit(error);
E 13
}

I 12
/*
 * Construct a prototype disklabel from /etc/disktab.  As a side
 * effect, set the names of the primary and secondary boot files
 * if specified.
 */
E 12
makelabel(type, name, lp)
	char *type, *name;
	register struct disklabel *lp;
{
	register struct disklabel *dp;
I 12
	char *strcpy();
E 12
D 4
	register char *p;
E 4

	dp = getdiskbyname(type);
	if (dp == NULL) {
		fprintf(stderr, "%s: unknown disk type\n", type);
		exit(1);
	}
	*lp = *dp;
I 12
#ifdef BOOT
	/*
	 * Check if disktab specifies the bootstraps (b0 or b1).
	 */
	if (!xxboot && lp->d_boot0) {
		if (*lp->d_boot0 != '/')
			(void)sprintf(boot0, "%s/%s", BOOTDIR, lp->d_boot0);
		else
			(void)strcpy(boot0, lp->d_boot0);
		xxboot = boot0;
	}
	if (!bootxx && lp->d_boot1) {
		if (*lp->d_boot1 != '/')
			(void)sprintf(boot1, "%s/%s", BOOTDIR, lp->d_boot1);
		else
			(void)strcpy(boot1, lp->d_boot1);
		bootxx = boot1;
	}
	/*
	 * If bootstraps not specified anywhere, makebootarea()
	 * will choose ones based on the name of the disk special
	 * file. E.g. /dev/ra0 -> raboot, bootra
	 */
#endif /*BOOT*/
	/* d_packname is union d_boot[01], so zero */
	bzero(lp->d_packname, sizeof(lp->d_packname));
E 12
	if (name)
D 4
		strncpy(lp->d_name, name, sizeof(lp->d_name));
E 4
I 4
D 12
		(void)strncpy(lp->d_name, name, sizeof(lp->d_name));
E 12
I 12
		(void)strncpy(lp->d_packname, name, sizeof(lp->d_packname));
E 12
E 4
}

writelabel(f, boot, lp)
	int f;
	char *boot;
	register struct disklabel *lp;
{
D 4
	register i;
E 4
I 4
	register int i;
D 12
	long	lseek();
E 12
I 12
	int flag;
	off_t lseek();
E 12
E 4
I 2
D 3
	daddr_t bbsize;
#if vax
E 2
	daddr_t alt;
I 2
	int nsectors, secsize;
#endif
E 3
E 2

	lp->d_magic = DISKMAGIC;
	lp->d_magic2 = DISKMAGIC;
D 2
#if ENDIAN != BIG
	swablabel(lp);
E 2
I 2
D 3
	bbsize = lp->d_bbsize;
#if vax
	/* copy before swabbing */
	if (lp->d_type == DTYPE_SMD && lp->d_flags & D_BADSECT)
		alt = lp->d_ncylinders * lp->d_secpercyl - lp->d_nsectors;
	else
		alt = 0;
	nsectors = lp->d_nsectors;
	secsize = lp->d_secsize;
E 2
#endif
I 2
	swablabel(lp);
E 3
E 2
	lp->d_checksum = 0;
	lp->d_checksum = dkcksum(lp);
D 4
	lseek(f, (off_t)0, L_SET);
E 4
I 4
D 9
	(void)lseek(f, (off_t)0, L_SET);
E 9
E 4
D 2
	if (write(f, boot, lp->d_bbsize) < lp->d_bbsize)
E 2
I 2
D 3
	if (write(f, boot, bbsize) < bbsize)
E 2
		Perror("write");
E 3
I 3
	if (rflag) {
I 12
		/*
		 * First set the kernel disk label,
		 * then write a label to the raw disk.
		 * If the SDINFO ioctl fails because it is unimplemented,
		 * keep going; otherwise, the kernel consistency checks
		 * may prevent us from changing the current (in-core)
		 * label.
		 */
		if (ioctl(f, DIOCSDINFO, lp) < 0 &&
D 13
		    errno != ENODEV && errno != ENOTTY)
			Perror("ioctl DIOCSDINFO");
E 13
I 13
		    errno != ENODEV && errno != ENOTTY) {
			l_perror("ioctl DIOCSDINFO");
			return (1);
		}
E 13
E 12
I 9
		(void)lseek(f, (off_t)0, L_SET);
E 9
D 12
		if (write(f, boot, lp->d_bbsize) < lp->d_bbsize)
E 12
I 12
		/*
		 * write enable label sector before write (if necessary),
		 * disable after writing.
		 */
		flag = 1;
		if (ioctl(f, DIOCWLABEL, &flag) < 0)
			perror("ioctl DIOCWLABEL");
D 13
		if (write(f, boot, lp->d_bbsize) != lp->d_bbsize)
E 12
			Perror("write");
E 13
I 13
		if (write(f, boot, lp->d_bbsize) != lp->d_bbsize) {
			perror("write");
			return (1);
		}
E 13
D 12
		if (ioctl(f, DIOCSDINFO, lp) < 0)
			Perror("ioctl DIOCSDINFO");
E 12
I 12
		flag = 0;
		(void) ioctl(f, DIOCWLABEL, &flag);
E 12
D 13
	} else if (ioctl(f, DIOCWDINFO, lp) < 0)
		Perror("ioctl DIOCWDINFO");
E 13
I 13
	} else if (ioctl(f, DIOCWDINFO, lp) < 0) {
		l_perror("ioctl DIOCWDINFO");
		return (1);
	}
E 13
E 3
D 2
#ifdef notyet
	alt = lp->d_ncylinders * lp->d_secpercyl - lp->d_nsectors;
	for (i = 1; i < 11 && i < lp->d_nsectors; i += 2) {
		lseek(f, (off_t)(alt + i) * lp->d_secsize, L_SET);
		if (write(f, boot, lp->d_secsize) < lp->d_secsize) {
E 2
I 2
D 12
#if vax
E 12
I 12
#ifdef vax
E 12
D 3
	if (alt)
	for (i = 1; i < 11 && i < nsectors; i += 2) {
		lseek(f, (off_t)(alt + i) * secsize, L_SET);
		if (write(f, boot, secsize) < secsize) {
E 2
			int oerrno = errno;
			fprintf(stderr, "alternate label %d ", i/2);
			errno = oerrno;
			perror("write");
E 3
I 3
	if (lp->d_type == DTYPE_SMD && lp->d_flags & D_BADSECT) {
		daddr_t alt;

		alt = lp->d_ncylinders * lp->d_secpercyl - lp->d_nsectors;
		for (i = 1; i < 11 && i < lp->d_nsectors; i += 2) {
D 4
			lseek(f, (off_t)(alt + i) * lp->d_secsize, L_SET);
E 4
I 4
			(void)lseek(f, (off_t)((alt + i) * lp->d_secsize), L_SET);
E 4
			if (write(f, boot, lp->d_secsize) < lp->d_secsize) {
				int oerrno = errno;
				fprintf(stderr, "alternate label %d ", i/2);
				errno = oerrno;
				perror("write");
			}
E 3
		}
	}
I 2
#endif
I 13
	return (0);
E 13
D 3
#ifdef notyet
E 2
	if (ioctl(f, DIOCSDINFO, lp) < 0)
		Perror("ioctl DIOCSDINFO");
#endif
E 3
}

I 13
l_perror(s)
	char *s;
{
	int saverrno = errno;

	fprintf(stderr, "disklabel: %s: ", s);

	switch (saverrno) {

	case ESRCH:
		fprintf(stderr, "No disk label on disk;\n");
		fprintf(stderr,
		    "use \"disklabel -r\" to install initial label\n");
		break;

	case EINVAL:
		fprintf(stderr, "Label magic number or checksum is wrong!\n");
		fprintf(stderr, "(disklabel or kernel is out of date?)\n");
		break;

	case EBUSY:
		fprintf(stderr, "Open partition would move or shrink\n");
		break;

	case EXDEV:
		fprintf(stderr,
	"Labeled partition or 'a' partition must start at beginning of disk\n");
		break;

	default:
		errno = saverrno;
		perror((char *)NULL);
		break;
	}
}

E 13
/*
D 9
 * Read disklabel from disk.
 * If boot is given, need bootstrap too.
D 3
 * If boot not needed, could use ioctl to get label.
E 3
I 3
 * If boot not needed, use ioctl to get label
 * unless -r flag is given.
E 9
I 9
 * Fetch disklabel for disk.
D 12
 * If needboot is given, need bootstrap too.
E 12
 * Use ioctl to get label unless -r flag is given.
E 9
E 3
 */
struct disklabel *
D 9
readlabel(f, boot)
	int f;
	char *boot;
E 9
I 9
D 12
readlabel(f, needboot)
	int f, needboot;
E 12
I 12
readlabel(f)
	int f;
E 12
E 9
{
	register struct disklabel *lp;
D 3
	u_long magic = htonl(DISKMAGIC);
E 3
I 3
D 9
	register char *buf;
E 9
E 3

D 3
	if (boot == NULL)
		boot = bootarea;
	if (read(f, boot, BBSIZE) < BBSIZE)
		Perror(specname);
	for (lp = (struct disklabel *)(boot + LABELOFFSET);
	    lp <= (struct disklabel *)(boot + BBSIZE -
	    sizeof(struct disklabel));
	    lp = (struct disklabel *)((char *)lp + 128))
		if (lp->d_magic == magic && lp->d_magic2 == magic)
			break;
	if (lp > (struct disklabel *)(boot + BBSIZE -
	    sizeof(struct disklabel)) ||
	    lp->d_magic != magic || lp->d_magic2 != magic ||
	    dkcksum(lp) != 0) {
		fprintf(stderr,
E 3
I 3
D 9
	if (boot)
		buf = boot;
	else
		buf = bootarea;
	lp = (struct disklabel *)(buf + LABELOFFSET);
D 8
	if (rflag == 0 && boot == 0) {
E 8
I 8
	if (boot || rflag)
		if (read(f, buf, BBSIZE) < BBSIZE)
E 9
I 9
D 12
	if (needboot || rflag) {
		lp = (struct disklabel *)(bootarea + LABELOFFSET);
E 12
I 12
	if (rflag) {
E 12
		if (read(f, bootarea, BBSIZE) < BBSIZE)
E 9
			Perror(specname);
I 9
D 12
	} else
		lp = &lab;
E 9
	if (rflag == 0) {
E 8
		if (ioctl(f, DIOCGDINFO, lp) < 0)
			Perror("ioctl DIOCGDINFO");
	} else {
E 12
D 8
		if (read(f, buf, BBSIZE) < BBSIZE)
			Perror(specname);
E 8
D 9
		for (lp = (struct disklabel *)buf;
		    lp <= (struct disklabel *)(buf + BBSIZE - sizeof(*lp));
E 9
I 9
		for (lp = (struct disklabel *)bootarea;
		    lp <= (struct disklabel *)(bootarea + BBSIZE - sizeof(*lp));
E 9
		    lp = (struct disklabel *)((char *)lp + 16))
			if (lp->d_magic == DISKMAGIC &&
			    lp->d_magic2 == DISKMAGIC)
				break;
D 9
		if (lp > (struct disklabel *)(buf + BBSIZE - sizeof(*lp)) ||
E 9
I 9
		if (lp > (struct disklabel *)(bootarea+BBSIZE-sizeof(*lp)) ||
E 9
		    lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC ||
		    dkcksum(lp) != 0) {
			fprintf(stderr,
E 3
	"Bad pack magic number (label is damaged, or pack is unlabeled)\n");
D 3
		exit(1);
E 3
I 3
D 12
			exit(1);
E 12
I 12
			/* lp = (struct disklabel *)(bootarea + LABELOFFSET); */
			exit (1);
E 12
		}
I 12
	} else {
		lp = &lab;
		if (ioctl(f, DIOCGDINFO, lp) < 0)
			Perror("ioctl DIOCGDINFO");
E 12
E 3
	}
D 2
#if ENDIAN != BIG
E 2
D 3
	swablabel(lp);
E 3
D 2
#endif
E 2
	return (lp);
}

struct disklabel *
D 9
getbootarea(boot, dp)
E 9
I 9
makebootarea(boot, dp)
E 9
	char *boot;
	register struct disklabel *dp;
{
	struct disklabel *lp;
	register char *p;
	int b;
D 9

E 9
#ifdef BOOT
I 4
	char	*dkbasename;
I 12
#endif /*BOOT*/
E 12

E 4
D 12
	if (xxboot == NULL) {
E 12
I 12
	lp = (struct disklabel *)(boot + (LABELSECTOR * dp->d_secsize) +
	    LABELOFFSET);
#ifdef BOOT
	if (!rflag)
		return (lp);

	if (xxboot == NULL || bootxx == NULL) {
E 12
		dkbasename = np;
		if ((p = rindex(dkname, '/')) == NULL)
			p = dkname;
		else
			p++;
		while (*p && !isdigit(*p))
			*np++ = *p++;
		*np++ = '\0';

D 11
		sprintf(np, "%s/%sboot", BOOTDIR, dkbasename);
E 11
I 11
D 12
		(void)sprintf(np, "%s/%sboot", BOOTDIR, dkbasename);
E 11
		if (access(np, F_OK) < 0 && dkbasename[0] == 'r')
			dkbasename++;
		xxboot = np;
D 11
		sprintf(xxboot, "%s/%sboot", BOOTDIR, dkbasename);
E 11
I 11
		(void)sprintf(xxboot, "%s/%sboot", BOOTDIR, dkbasename);
E 11
		np += strlen(xxboot) + 1;

		bootxx = np;
D 11
		sprintf(bootxx, "%s/boot%s", BOOTDIR, dkbasename);
E 11
I 11
		(void)sprintf(bootxx, "%s/boot%s", BOOTDIR, dkbasename);
E 11
		np += strlen(bootxx) + 1;
E 12
I 12
		if (xxboot == NULL) {
			(void)sprintf(np, "%s/%sboot", BOOTDIR, dkbasename);
			if (access(np, F_OK) < 0 && dkbasename[0] == 'r')
				dkbasename++;
			xxboot = np;
			(void)sprintf(xxboot, "%s/%sboot", BOOTDIR, dkbasename);
			np += strlen(xxboot) + 1;
		}
		if (bootxx == NULL) {
			(void)sprintf(np, "%s/boot%s", BOOTDIR, dkbasename);
			if (access(np, F_OK) < 0 && dkbasename[0] == 'r')
				dkbasename++;
			bootxx = np;
			(void)sprintf(bootxx, "%s/boot%s", BOOTDIR, dkbasename);
			np += strlen(bootxx) + 1;
		}
E 12
	}
I 12
#ifdef DEBUG
	if (debug)
		fprintf(stderr, "bootstraps: xxboot = %s, bootxx = %s\n",
			xxboot, bootxx);
#endif
E 12

	b = open(xxboot, O_RDONLY);
	if (b < 0)
		Perror(xxboot);
D 4
	if (read(b, boot, dp->d_secsize) < 0)
E 4
I 4
	if (read(b, boot, (int)dp->d_secsize) < 0)
E 4
		Perror(xxboot);
	close(b);
	b = open(bootxx, O_RDONLY);
	if (b < 0)
		Perror(bootxx);
D 4
	if (read(b, &boot[dp->d_secsize], dp->d_bbsize-dp->d_secsize) < 0)
E 4
I 4
	if (read(b, &boot[dp->d_secsize], (int)(dp->d_bbsize-dp->d_secsize)) < 0)
E 4
		Perror(bootxx);
D 4
	close(b);
E 4
I 4
	(void)close(b);
E 4
D 12
#endif
E 12
I 12
#endif /*BOOT*/
E 12

D 12
	lp = (struct disklabel *)(boot + (LABELSECTOR * dp->d_secsize) +
	    LABELOFFSET);
E 12
	for (p = (char *)lp; p < (char *)lp + sizeof(struct disklabel); p++)
		if (*p) {
			fprintf(stderr,
			    "Bootstrap doesn't leave room for disk label\n");
			exit(2);
		}
	return (lp);
}

display(f, lp)
	FILE *f;
	register struct disklabel *lp;
{
D 4
	register i, j;
E 4
I 4
	register int i, j;
E 4
	register struct partition *pp;

	fprintf(f, "# %s:\n", specname);
	if ((unsigned) lp->d_type < DKMAXTYPES)
		fprintf(f, "type: %s\n", dktypenames[lp->d_type]);
	else
		fprintf(f, "type: %d\n", lp->d_type);
	fprintf(f, "disk: %.*s\n", sizeof(lp->d_typename), lp->d_typename);
D 12
	fprintf(f, "label: %.*s\n", sizeof(lp->d_name), lp->d_name);
E 12
I 12
	fprintf(f, "label: %.*s\n", sizeof(lp->d_packname), lp->d_packname);
E 12
D 8
	fprintf(f, "flags: ");
E 8
I 8
	fprintf(f, "flags:");
E 8
	if (lp->d_flags & D_REMOVABLE)
D 8
		fprintf(f, "removeable ");
E 8
I 8
		fprintf(f, " removeable");
E 8
	if (lp->d_flags & D_ECC)
D 8
		fprintf(f, "ecc ");
E 8
I 8
		fprintf(f, " ecc");
E 8
	if (lp->d_flags & D_BADSECT)
D 8
		fprintf(f, "badsect ");
E 8
I 8
		fprintf(f, " badsect");
E 8
	fprintf(f, "\n");
	fprintf(f, "bytes/sector: %d\n", lp->d_secsize);
	fprintf(f, "sectors/track: %d\n", lp->d_nsectors);
	fprintf(f, "tracks/cylinder: %d\n", lp->d_ntracks);
I 7
	fprintf(f, "sectors/cylinder: %d\n", lp->d_secpercyl);
E 7
	fprintf(f, "cylinders: %d\n", lp->d_ncylinders);
I 4
	fprintf(f, "rpm: %d\n", lp->d_rpm);
E 4
	fprintf(f, "interleave: %d\n", lp->d_interleave);
	fprintf(f, "trackskew: %d\n", lp->d_trackskew);
	fprintf(f, "cylinderskew: %d\n", lp->d_cylskew);
	fprintf(f, "headswitch: %d\t\t# milliseconds\n", lp->d_headswitch);
	fprintf(f, "track-to-track seek: %d\t# milliseconds\n", lp->d_trkseek);
	fprintf(f, "drivedata: ");
	for (i = NDDATA - 1; i >= 0; i--)
		if (lp->d_drivedata[i])
			break;
	if (i < 0)
		i = 0;
	for (j = 0; j <= i; j++)
		fprintf(f, "%d ", lp->d_drivedata[j]);
	fprintf(f, "\n\n%d partitions:\n", lp->d_npartitions);
D 6
	fprintf(f, "#\t       size    offset     fstype\n");
E 6
I 6
	fprintf(f,
	    "#        size   offset    fstype   [fsize bsize   cpg]\n");
E 6
	pp = lp->d_partitions;
	for (i = 0; i < lp->d_npartitions; i++, pp++) {
D 6
		fprintf(f, "\t%c: %8d %8d    ", 'a' + i,
		   pp->p_size, pp->p_offset);
E 6
		if (pp->p_size) {
I 6
			fprintf(f, "  %c: %8d %8d  ", 'a' + i,
			   pp->p_size, pp->p_offset);
E 6
			if ((unsigned) pp->p_fstype < FSMAXTYPES)
				fprintf(f, "%8.8s", fstypenames[pp->p_fstype]);
			else
				fprintf(f, "%8d", pp->p_fstype);
I 6
			switch (pp->p_fstype) {

			case FS_UNUSED:				/* XXX */
				fprintf(f, "    %5d %5d %5.5s ",
				    pp->p_fsize, pp->p_fsize * pp->p_frag, "");
				break;

			case FS_BSDFFS:
				fprintf(f, "    %5d %5d %5d ",
				    pp->p_fsize, pp->p_fsize * pp->p_frag,
				    pp->p_cpg);
				break;

			default:
				fprintf(f, "%20.20s", "");
				break;
			}
E 6
			fprintf(f, "\t# (Cyl. %4d",
			    pp->p_offset / lp->d_secpercyl);
			if (pp->p_offset % lp->d_secpercyl)
			    putc('*', f);
			else
			    putc(' ', f);
			fprintf(f, "- %d",
			    (pp->p_offset + 
			    pp->p_size + lp->d_secpercyl - 1) /
			    lp->d_secpercyl - 1);
			if (pp->p_size % lp->d_secpercyl)
			    putc('*', f);
D 6
			putc(')', f);
E 6
I 6
			fprintf(f, ")\n");
E 6
		}
D 6
		fprintf(f, "\n");
E 6
	}
I 10
	fflush(f);
E 10
}

D 4
edit(f)
	int f;
E 4
I 4
D 13
edit(lp)
E 13
I 13
edit(lp, f)
E 13
	struct disklabel *lp;
I 13
	int f;
E 13
E 4
{
D 4
	fprintf(stderr, "sorry, not yet\n");
	exit(1);
E 4
I 4
	register int c;
	struct disklabel label;
	FILE *fd;
	char *mktemp();

	(void) mktemp(tmpfil);
	fd = fopen(tmpfil, "w");
	if (fd == NULL) {
		fprintf(stderr, "%s: Can't create\n", tmpfil);
D 13
		return (0);
E 13
I 13
		return (1);
E 13
	}
	(void)fchmod(fd, 0600);
	display(fd, lp);
	fclose(fd);
	for (;;) {
		if (!editit())
			break;
		fd = fopen(tmpfil, "r");
		if (fd == NULL) {
D 12
			fprintf(stderr, "%s: Can't reopen for reading\n");
E 12
I 12
			fprintf(stderr, "%s: Can't reopen for reading\n",
				tmpfil);
E 12
			break;
		}
D 6
		label = *lp;
E 6
I 6
		bzero((char *)&label, sizeof(label));
E 6
		if (getasciilabel(fd, &label)) {
			*lp = label;
D 13
			(void) unlink(tmpfil);
			return (1);
E 13
I 13
			if (writelabel(f, bootarea, lp) == 0) {
				(void) unlink(tmpfil);
				return (0);
			}
E 13
		}
		printf("re-edit the label? [y]: "); fflush(stdout);
		c = getchar();
		if (c != EOF && c != (int)'\n')
			while (getchar() != (int)'\n')
				;
		if  (c == (int)'n')
			break;
	}
	(void) unlink(tmpfil);
D 13
	return (0);
E 13
I 13
	return (1);
E 13
E 4
}

I 4
editit()
{
	register int pid, xpid;
	int stat, omask;
	extern char *getenv();
E 4

I 4
	omask = sigblock(sigmask(SIGINT)|sigmask(SIGQUIT)|sigmask(SIGHUP));
	while ((pid = fork()) < 0) {
		extern int errno;

		if (errno == EPROCLIM) {
			fprintf(stderr, "You have too many processes\n");
			return(0);
		}
		if (errno != EAGAIN) {
			perror("fork");
			return(0);
		}
		sleep(1);
	}
	if (pid == 0) {
		register char *ed;

		sigsetmask(omask);
		setgid(getgid());
		setuid(getuid());
		if ((ed = getenv("EDITOR")) == (char *)0)
			ed = DEFEDITOR;
		execlp(ed, ed, tmpfil, 0);
		perror(ed);
		exit(1);
	}
	while ((xpid = wait(&stat)) >= 0)
		if (xpid == pid)
			break;
	sigsetmask(omask);
	return(!stat);
}

char *
skip(cp)
	register char *cp;
{

	while (*cp != '\0' && isspace(*cp))
		cp++;
	if (*cp == '\0' || *cp == '#')
		return ((char *)NULL);
	return (cp);
}

char *
word(cp)
	register char *cp;
{
	register char c;

D 8
	while (*cp != '\0' && !isspace(*cp))
		if (*cp++ == '#')
			break;
E 8
I 8
	while (*cp != '\0' && !isspace(*cp) && *cp != '#')
		cp++;
E 8
	if ((c = *cp) != '\0') {
		*cp++ = '\0';
		if (c != '#')
			return (skip(cp));
	}
	return ((char *)NULL);
}

E 4
/*
 * Read an ascii label in from fd f,
 * in the same format as that put out by display(),
 * and fill in lp.
 */
getasciilabel(f, lp)
D 4
	int f;
E 4
I 4
	FILE	*f;
E 4
	register struct disklabel *lp;
{
D 4
	fprintf(stderr, "sorry, not yet\n");
	exit(1);
E 4
I 4
	register char **cpp, *cp;
I 6
	register struct partition *pp;
E 6
	char *tp, *s, line[BUFSIZ];
	int v, lineno = 0, errors = 0;

	lp->d_bbsize = BBSIZE;				/* XXX */
	lp->d_sbsize = SBSIZE;				/* XXX */
	while (fgets(line, sizeof(line) - 1, f)) {
		lineno++;
		if (cp = index(line,'\n'))
			*cp = '\0';
		cp = skip(line);
		if (cp == NULL)
			continue;
		tp = index(cp, ':');
		if (tp == NULL) {
			fprintf(stderr, "line %d: syntax error\n", lineno);
			errors++;
			continue;
		}
		*tp++ = '\0', tp = skip(tp);
		if (streq(cp, "type")) {
			if (tp == NULL)
				tp = "unknown";
			cpp = dktypenames;
			for (; cpp < &dktypenames[DKMAXTYPES]; cpp++)
				if ((s = *cpp) && streq(s, tp)) {
					lp->d_type = cpp - dktypenames;
					goto next;
				}
			v = atoi(tp);
			if ((unsigned)v >= DKMAXTYPES)
				fprintf(stderr, "line %d:%s %d\n", lineno,
				    "Warning, unknown disk type", v);
			lp->d_type = v;
			continue;
		}
		if (streq(cp, "flags")) {
D 7
			v = 0;
			while ((cp = tp) && *cp != '\0') {
				if (tp = skip(cp)) {
					*tp++ = '\0';
					while (*tp && isspace(*tp))
						tp++;
				}
E 7
I 7
D 12
			for (v = 0; (cp = tp) && *cp != '\0'; tp = word(cp)) {
E 12
I 12
			for (v = 0; (cp = tp) && *cp != '\0';) {
				tp = word(cp);
E 12
E 7
				if (streq(cp, "removeable"))
					v |= D_REMOVABLE;
				else if (streq(cp, "ecc"))
					v |= D_ECC;
				else if (streq(cp, "badsect"))
					v |= D_BADSECT;
				else {
					fprintf(stderr,
					    "line %d: %s: bad flag\n",
					    lineno, cp);
					errors++;
				}
			}
			lp->d_flags = v;
			continue;
		}
		if (streq(cp, "drivedata")) {
			register int i;

D 7
			for (i = 0;(cp = tp) && *cp != '\0'  && i < NDDATA;) {
				if (tp = skip(cp)) {
					*tp++ = '\0';
					while (*tp != '\0' && isspace(*tp))
						tp++;
				}
E 7
I 7
			for (i = 0; (cp = tp) && *cp != '\0' && i < NDDATA;) {
E 7
				lp->d_drivedata[i++] = atoi(cp);
I 7
				tp = word(cp);
E 7
			}
			continue;
		}
		if (sscanf(cp, "%d partitions", &v) == 1) {
D 6
			if (v == 0 || (unsigned)v > MAXPARTITIONS)
E 6
I 6
			if (v == 0 || (unsigned)v > MAXPARTITIONS) {
E 6
				fprintf(stderr,
				    "line %d: bad # of partitions\n", lineno);
D 6
			else
E 6
I 6
				lp->d_npartitions = MAXPARTITIONS;
				errors++;
			} else
E 6
				lp->d_npartitions = v;
			continue;
		}
		if (tp == NULL)
			tp = "";
		if (streq(cp, "disk")) {
			strncpy(lp->d_typename, tp, sizeof (lp->d_typename));
			continue;
		}
		if (streq(cp, "label")) {
D 12
			strncpy(lp->d_name, tp, sizeof (lp->d_name));
E 12
I 12
			strncpy(lp->d_packname, tp, sizeof (lp->d_packname));
E 12
			continue;
		}
		if (streq(cp, "bytes/sector")) {
			v = atoi(tp);
			if (v <= 0 || (v % 512) != 0) {
				fprintf(stderr,
				    "line %d: %s: bad sector size\n",
				    lineno, tp);
				errors++;
			} else
				lp->d_secsize = v;
			continue;
		}
		if (streq(cp, "sectors/track")) {
			v = atoi(tp);
			if (v <= 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_nsectors = v;
I 7
			continue;
		}
		if (streq(cp, "sectors/cylinder")) {
			v = atoi(tp);
			if (v <= 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_secpercyl = v;
E 7
			continue;
		}
		if (streq(cp, "tracks/cylinder")) {
			v = atoi(tp);
			if (v <= 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_ntracks = v;
			continue;
		}
		if (streq(cp, "cylinders")) {
			v = atoi(tp);
			if (v <= 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_ncylinders = v;
			continue;
		}
		if (streq(cp, "rpm")) {
			v = atoi(tp);
			if (v <= 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_rpm = v;
			continue;
		}
		if (streq(cp, "interleave")) {
			v = atoi(tp);
			if (v <= 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_interleave = v;
			continue;
		}
		if (streq(cp, "trackskew")) {
			v = atoi(tp);
			if (v < 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_trackskew = v;
			continue;
		}
		if (streq(cp, "cylinderskew")) {
			v = atoi(tp);
			if (v < 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_cylskew = v;
			continue;
		}
		if (streq(cp, "headswitch")) {
			v = atoi(tp);
			if (v < 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_headswitch = v;
			continue;
		}
		if (streq(cp, "track-to-track seek")) {
			v = atoi(tp);
			if (v < 0) {
				fprintf(stderr, "line %d: %s: bad %s\n",
				    lineno, tp, cp);
				errors++;
			} else
				lp->d_trkseek = v;
			continue;
		}
		if ('a' <= *cp && *cp <= 'z' && cp[1] == '\0') {
D 6
			int part = *cp - 'a';
E 6
I 6
			unsigned part = *cp - 'a';
E 6

D 6
			if ((unsigned)part > MAXPARTITIONS) {
E 6
I 6
			if (part > lp->d_npartitions) {
E 6
				fprintf(stderr,
				    "line %d: bad partition name\n", lineno);
				errors++;
				continue;
			}
D 6
			cp = tp, tp = word(cp);
			if (tp == NULL)
				tp = cp;
			v = atoi(cp);
E 6
I 6
			pp = &lp->d_partitions[part];
#define NXTNUM(n) { \
	cp = tp, tp = word(cp); \
	if (tp == NULL) \
		tp = cp; \
	(n) = atoi(cp); \
     }

			NXTNUM(v);
E 6
			if (v < 0) {
				fprintf(stderr,
				    "line %d: %s: bad partition size\n",
				    lineno, cp);
				errors++;
			} else
D 6
				lp->d_partitions[part].p_size = v;
			cp = tp, tp = word(cp);
			if (tp == NULL)
				tp = cp;
			v = atoi(cp);
E 6
I 6
				pp->p_size = v;
			NXTNUM(v);
E 6
			if (v < 0) {
				fprintf(stderr,
				    "line %d: %s: bad partition offset\n",
				    lineno, cp);
				errors++;
			} else
D 6
				lp->d_partitions[part].p_offset = v;
E 6
I 6
				pp->p_offset = v;
E 6
			cp = tp, tp = word(cp);
			cpp = fstypenames;
			for (; cpp < &fstypenames[FSMAXTYPES]; cpp++)
				if ((s = *cpp) && streq(s, cp)) {
D 6
					lp->d_partitions[part].p_fstype =
					    cpp - fstypenames;
					goto next;
E 6
I 6
					pp->p_fstype = cpp - fstypenames;
					goto gottype;
E 6
				}
D 12
			v = atoi(cp);
			if ((unsigned)v >= FSMAXTYPES)
E 12
I 12
			if (isdigit(*cp))
				v = atoi(cp);
			else
				v = FSMAXTYPES;
			if ((unsigned)v >= FSMAXTYPES) {
E 12
				fprintf(stderr, "line %d: %s %s\n", lineno,
				    "Warning, unknown filesystem type", cp);
I 12
				v = FS_UNUSED;
			}
E 12
D 6
			lp->d_partitions[part].p_fstype = v;
E 6
I 6
			pp->p_fstype = v;
	gottype:

			switch (pp->p_fstype) {

			case FS_UNUSED:				/* XXX */
				NXTNUM(pp->p_fsize);
				if (pp->p_fsize == 0)
					break;
				NXTNUM(v);
				pp->p_frag = v / pp->p_fsize;
				break;

			case FS_BSDFFS:
				NXTNUM(pp->p_fsize);
				if (pp->p_fsize == 0)
					break;
				NXTNUM(v);
				pp->p_frag = v / pp->p_fsize;
				NXTNUM(pp->p_cpg);
				break;

			default:
				break;
			}
E 6
			continue;
		}
		fprintf(stderr, "line %d: %s: Unknown disklabel field\n",
		    lineno, cp);
		errors++;
	next:
		;
	}
	errors += checklabel(lp);
	return (errors == 0);
E 4
}

D 4
Perror(op)
	char *op;
E 4
I 4
/*
 * Check disklabel for errors and fill in
 * derived fields according to supplied values.
 */
checklabel(lp)
	register struct disklabel *lp;
E 4
{
I 4
	register struct partition *pp;
	int i, errors = 0;
	char part;
E 4

D 4
	fprintf(stderr, "disklabel: "); perror(op);
E 4
I 4
	if (lp->d_secsize == 0) {
		fprintf(stderr, "sector size %d\n", lp->d_secsize);
		return (1);
	}
	if (lp->d_nsectors == 0) {
		fprintf(stderr, "sectors/track %d\n", lp->d_nsectors);
		return (1);
	}
	if (lp->d_ntracks == 0) {
		fprintf(stderr, "tracks/cylinder %d\n", lp->d_ntracks);
		return (1);
	}
	if  (lp->d_ncylinders == 0) {
		fprintf(stderr, "cylinders/unit %d\n", lp->d_ncylinders);
		errors++;
	}
	if (lp->d_rpm == 0)
		Warning("revolutions/minute %d\n", lp->d_rpm);
	if (lp->d_secpercyl == 0)
		lp->d_secpercyl = lp->d_nsectors * lp->d_ntracks;
	if (lp->d_secperunit == 0)
		lp->d_secperunit = lp->d_secpercyl * lp->d_ncylinders;
	if (lp->d_bbsize == 0) {
		fprintf(stderr, "boot block size %d\n", lp->d_bbsize);
		errors++;
	} else if (lp->d_bbsize % lp->d_secsize)
		Warning("boot block size %% sector-size != 0\n");
	if (lp->d_sbsize == 0) {
		fprintf(stderr, "super block size %d\n", lp->d_sbsize);
		errors++;
	} else if (lp->d_sbsize % lp->d_secsize)
		Warning("super block size %% sector-size != 0\n");
	if (lp->d_npartitions > MAXPARTITIONS)
		Warning("number of partitions (%d) > MAXPARTITIONS (%d)\n",
		    lp->d_npartitions, MAXPARTITIONS);
	for (i = 0; i < lp->d_npartitions; i++) {
		part = 'a' + i;
		pp = &lp->d_partitions[i];
		if (pp->p_size == 0 && pp->p_offset != 0)
			Warning("partition %c: size 0, but offset %d\n",
			    part, pp->p_offset);
#ifdef notdef
		if (pp->p_size % lp->d_secpercyl)
			Warning("partition %c: size %% cylinder-size != 0\n",
			    part);
		if (pp->p_offset % lp->d_secpercyl)
			Warning("partition %c: offset %% cylinder-size != 0\n",
			    part);
#endif
		if (pp->p_offset > lp->d_secperunit) {
			fprintf(stderr,
			    "partition %c: offset past end of unit\n", part);
			errors++;
		}
		if (pp->p_offset + pp->p_size > lp->d_secperunit) {
			fprintf(stderr,
			    "partition %c: partition extends past end of unit\n",
			    part);
			errors++;
		}
	}
	for (; i < MAXPARTITIONS; i++) {
		part = 'a' + i;
		pp = &lp->d_partitions[i];
		if (pp->p_size || pp->p_offset)
			Warning("unused partition %c: size %d offset %d\n",
D 12
			    pp->p_size, pp->p_offset);
E 12
I 12
			    'a' + i, pp->p_size, pp->p_offset);
E 12
	}
	return (errors);
}

/*VARARGS1*/
Warning(fmt, a1, a2, a3, a4, a5)
	char *fmt;
{

	fprintf(stderr, "Warning, ");
	fprintf(stderr, fmt, a1, a2, a3, a4, a5);
	fprintf(stderr, "\n");
}

Perror(str)
	char *str;
{
	fputs("disklabel: ", stderr); perror(str);
E 4
	exit(4);
I 4
}

usage()
{
#ifdef BOOT
D 9
	fprintf(stderr, "%-64s%s\n%-64s%s\n%-64s%s\n%-64s%s\n",
E 9
I 9
D 12
	fprintf(stderr, "%-62s%s\n%-62s%s\n%-62s%s\n%-62s%s\n",
E 12
I 12
	fprintf(stderr, "%-62s%s\n%-62s%s\n%-62s%s\n%-62s%s\n%-62s%s\n",
E 12
E 9
"usage: disklabel [-r] disk", "(to read label)",
"or disklabel -w [-r] disk type [ packid ] [ xxboot bootxx ]", "(to write label)",
"or disklabel -e [-r] disk", "(to edit label)",
D 12
"or disklabel -R [-r] disk protofile [ xxboot bootxx ]", "(to restore label)");
E 12
I 12
"or disklabel -R [-r] disk protofile [ type | xxboot bootxx ]", "(to restore label)",
"or disklabel [-NW] disk", "(to write disable/enable label)");
E 12
#else
D 12
	fprintf(stderr, "%-43s%s\n%-43s%s\n%-43s%s\n%-43s%s\n",
E 12
I 12
	fprintf(stderr, "%-43s%s\n%-43s%s\n%-43s%s\n%-43s%s\n%-43s%s\n",
E 12
"usage: disklabel [-r] disk", "(to read label)",
"or disklabel -w [-r] disk type [ packid ]", "(to write label)",
"or disklabel -e [-r] disk", "(to edit label)",
D 12
"or disklabel -R [-r] disk protofile", "(to restore label)");
E 12
I 12
"or disklabel -R [-r] disk protofile", "(to restore label)",
"or disklabel [-NW] disk", "(to write disable/enable label)");
E 12
#endif
	exit(1);
E 4
}
E 1
