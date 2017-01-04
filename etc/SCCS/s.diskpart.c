h24602
s 00010/00008/00448
d D 5.12 99/09/04 15:09:44 msokolov 16 15
c don't output the commented-out c line if it's meaningless (because the user
c specified -s) or redundant (because there is no bad sector forwarding)
e
s 00020/00022/00436
d D 5.11 99/09/04 15:00:24 msokolov 15 14
c name and type were still confused when prompting for parameters
c let the user specify more cylinders than needed to cover totsect if he knows
c the real geometry
c threshold was set incorrectly (and it's spelled with one 'h')
c the conditional to ask about bad sector forwarding for SMD only was busted
e
s 00037/00018/00421
d D 5.10 88/07/12 19:52:04 karels 14 12
c add -s size; fix type-name confusion
e
s 00033/00015/00424
d R 5.10 88/07/12 19:49:03 karels 13 12
c add -s size, for qd33; fix type-name confusion
e
s 00010/00005/00429
d D 5.9 88/06/18 14:34:10 bostic 12 11
c install approved copyright notice
e
s 00019/00010/00415
d D 5.8 88/02/19 09:49:27 bostic 11 10
c d_name is now d_typename, add Berkeley specific header
e
s 00013/00003/00412
d D 5.7 87/06/19 11:36:20 karels 10 9
c need to include whole disk in c partition for now for disklabel;
c 
e
s 00136/00058/00279
d D 5.6 87/04/02 11:24:52 karels 9 8
c convert to disklabels
e
s 00009/00007/00328
d D 5.5 86/05/30 15:15:26 karels 8 7
c reduce 'c' by badsecttable for disktab, humans; 8K/1K
e
s 00033/00006/00302
d D 5.4 85/10/02 00:00:22 mckusick 7 6
c add understanding of "sf" - bad sector forwarding and 
c "so" - sector offset addressing
e
s 00000/00016/00308
d D 5.3 85/06/06 11:05:34 dist 6 5
c Add copyright
e
s 00016/00000/00308
d D 5.2 85/06/06 11:03:16 dist 5 4
c Add copyright
e
s 00013/00001/00295
d D 5.1 85/05/06 11:29:08 dist 4 3
c Add copyright
e
s 00013/00005/00283
d D 4.3 83/05/03 20:52:35 sam 3 2
c fix calculation of bad sector table space
e
s 00009/00002/00279
d D 4.2 83/03/03 10:16:21 sam 2 1
c fix problem with -d flag and empty 'h' partitions
e
s 00281/00000/00000
d D 4.1 83/02/20 16:08:34 sam 1 0
c date and time created 83/02/20 16:08:34 by sam
e
u
U
t
T
I 4
/*
I 5
D 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

/*
E 6
E 5
D 14
 * Copyright (c) 1983 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 14
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 */

E 4
I 1
#ifndef lint
I 4
char copyright[] =
D 14
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 14
I 14
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 14
 All rights reserved.\n";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11

#ifndef lint
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11
E 4

/*
 * Program to calculate standard disk partition sizes.
 */
#include <sys/param.h>
I 9
#define DKTYPENAMES
#include <sys/disklabel.h>
E 9

#include <stdio.h>
D 9
#include <disktab.h>
E 9
I 9
#include <ctype.h>
E 9

I 10
#define	for_now			/* show all of `c' partition for disklabel */
E 10
#define	NPARTITIONS	8
#define	PART(x)		(x - 'a')

/*
 * Default partition sizes, where they exist.
 */
#define	NDEFAULTS	4
int	defpart[NDEFAULTS][NPARTITIONS] = {
   { 15884, 66880, 0, 15884, 307200, 0, 0, 291346 },	/* ~ 356+ Mbytes */
   { 15884, 33440, 0, 15884, 55936, 0, 0, 291346 },	/* ~ 206-355 Mbytes */
   { 15884, 33440, 0, 15884, 55936, 0, 0, 0 },		/* ~ 61-205 Mbytes */
   { 15884, 10032, 0, 15884, 0, 0, 0, 0 },		/* ~ 20-60 Mbytes */
};

/*
 * Each array defines a layout for a disk;
 * that is, the collection of partitions totally
 * covers the physical space on a disk.
 */
#define	NLAYOUTS	3
char	layouts[NLAYOUTS][NPARTITIONS] = {
   { 'a', 'b', 'h', 'g' },
   { 'a', 'b', 'h', 'd', 'e', 'f' },
   { 'c' },
};

/*
 * Default disk block and disk block fragment
 * sizes for each file system.  Those file systems
 * with zero block and frag sizes are special cases
 * (e.g. swap areas or for access to the entire device).
 */
D 9
struct	defparam {
	int	p_bsize;	/* block size */
	int	p_fsize;	/* frag size */
} defparam[NPARTITIONS] = {
	{ 8192, 1024 },		/* a */
D 8
	{ 0 },			/* b */
	{ 0 },			/* c */
	{ 8192, 1024 },		/* d */
	{ 4096, 512 },		/* e */
	{ 4096, 1024 },		/* f */
	{ 4096, 1024 },		/* g */
	{ 4096, 512 }		/* h */
E 8
I 8
	{ 8192, 1024 },		/* b */
	{ 8192, 1024 },		/* c */
	{ 4096, 512 },		/* d */
	{ 8192, 1024 },		/* e */
	{ 8192, 1024 },		/* f */
	{ 8192, 1024 },		/* g */
	{ 8192, 1024 }		/* h */
E 9
I 9
struct	partition defparam[NPARTITIONS] = {
	{ 0, 0, 1024, FS_UNUSED, 8, 0 },		/* a */
	{ 0, 0, 1024, FS_SWAP,   8, 0 },		/* b */
	{ 0, 0, 1024, FS_UNUSED, 8, 0 },		/* c */
	{ 0, 0,  512, FS_UNUSED, 8, 0 },		/* d */
	{ 0, 0, 1024, FS_UNUSED, 8, 0 },		/* e */
	{ 0, 0, 1024, FS_UNUSED, 8, 0 },		/* f */
	{ 0, 0, 1024, FS_UNUSED, 8, 0 },		/* g */
	{ 0, 0, 1024, FS_UNUSED, 8, 0 }			/* h */
E 9
E 8
};

/*
 * Each disk has some space reserved for a bad sector
D 3
 * forwarding table.  While DEC standard 144 uses only
 * the first 5 even numbered sectors in the last track
 * of the last cylinder, we reserve 3 tracks for expansion.
E 3
I 3
 * forwarding table.  DEC standard 144 uses the first
 * 5 even numbered sectors in the last track of the
 * last cylinder for replicated storage of the bad sector
 * table; another 126 sectors past this is needed as a
 * pool of replacement sectors.
E 3
 */
D 3
int	badsecttable = 3;	/* # tracks */
E 3
I 3
int	badsecttable = 126;	/* # sectors */
E 3

int	pflag;			/* print device driver partition tables */
int	dflag;			/* print disktab entry */

D 9
struct	disktab *promptfordisk();
E 9
I 9
struct	disklabel *promptfordisk();
E 9

main(argc, argv)
	int argc;
	char *argv[];
{
D 9
	struct disktab *dp;
	register int curcyl, spc, def, part, layout;
E 9
I 9
	struct disklabel *dp;
	register int curcyl, spc, def, part, layout, j;
E 9
D 15
	int threshhold, numcyls[NPARTITIONS], startcyl[NPARTITIONS];
E 15
I 15
	int threshold, numcyls[NPARTITIONS], startcyl[NPARTITIONS];
E 15
D 14
	char *lp;
E 14
I 14
	int totsize = 0;
	char *lp, *tyname;
E 14

	argc--, argv++;
	if (argc < 1) {
D 14
		fprintf(stderr, "usage: disktab [ -p ] [ -d ] disk-type\n");
E 14
I 14
		fprintf(stderr,
		    "usage: disktab [ -p ] [ -d ] [ -s size ] disk-type\n");
E 14
		exit(1);
	}
	if (argc > 0 && strcmp(*argv, "-p") == 0) {
		pflag++;
		argc--, argv++;
	}
	if (argc > 0 && strcmp(*argv, "-d") == 0) {
		dflag++;
		argc--, argv++;
	}
I 14
	if (argc > 1 && strcmp(*argv, "-s") == 0) {
		totsize = atoi(argv[1]);
		argc += 2, argv += 2;
	}
E 14
	dp = getdiskbyname(*argv);
	if (dp == NULL) {
		if (isatty(0))
			dp = promptfordisk(*argv);
		if (dp == NULL) {
			fprintf(stderr, "%s: unknown disk type\n", *argv);
			exit(2);
		}
I 9
D 15
	} else {
		if (dp->d_flags & D_REMOVABLE)
D 11
			strncpy(dp->d_name, "removable", sizeof(dp->d_name));
E 11
I 11
D 14
			strncpy(dp->d_typename, "removable",
			    sizeof(dp->d_typename));
E 14
I 14
			tyname = "removable";
E 14
E 11
		else if (dp->d_flags & D_RAMDISK)
D 11
			strncpy(dp->d_name, "simulated", sizeof(dp->d_name));
E 11
I 11
D 14
			strncpy(dp->d_typename, "simulated",
			    sizeof(dp->d_typename));
E 14
I 14
			tyname = "simulated";
E 14
E 11
		else
D 11
			strncpy(dp->d_name, "winchester", sizeof(dp->d_name));
E 11
I 11
D 14
			strncpy(dp->d_typename, "winchester",
			    sizeof(dp->d_typename));
E 14
I 14
			tyname = "winchester";
E 15
E 14
E 11
E 9
	}
I 15
	if (dp->d_flags & D_REMOVABLE)
		tyname = "removable";
	else if (dp->d_flags & D_RAMDISK)
		tyname = "simulated";
	else
		tyname = "winchester";
E 15
D 9
	spc = dp->d_nsectors * dp->d_ntracks;
E 9
I 9
	spc = dp->d_secpercyl;
E 9
D 3
	badsecttable *= dp->d_nsectors;
E 3
I 3
	/*
	 * Bad sector table contains one track for the replicated
	 * copies of the table and enough full tracks preceding
	 * the last track to hold the pool of free blocks to which
	 * bad sectors are mapped.
I 14
	 * If disk size was specified explicitly, use specified size.
E 14
	 */
D 9
	badsecttable = dp->d_nsectors + roundup(badsecttable, dp->d_nsectors);
E 3
	threshhold = howmany(spc, badsecttable);
I 7
	if (dp->d_badsectforw == 0) {
E 9
I 9
D 14
	if (dp->d_type == DTYPE_SMD && dp->d_flags & D_BADSECT) {
E 14
I 14
	if (dp->d_type == DTYPE_SMD && dp->d_flags & D_BADSECT &&
D 15
	    totsize == 0) {
E 15
I 15
	    totsize == 0)
E 15
E 14
		badsecttable = dp->d_nsectors +
		    roundup(badsecttable, dp->d_nsectors);
D 15
		threshhold = howmany(spc, badsecttable);
	} else {
E 15
I 15
	else
E 15
E 9
		badsecttable = 0;
D 15
		threshhold = 0;
	}
E 15
I 14
	/*
	 * If disk size was specified, recompute number of cylinders
	 * that may be used, and set badsecttable to any remaining
	 * fraction of the last cylinder.
	 */
	if (totsize != 0) {
D 15
		dp->d_ncylinders = howmany(totsize, spc);
E 15
I 15
		dp->d_ncylinders = MAX(dp->d_ncylinders, howmany(totsize, spc));
E 15
		badsecttable = spc * dp->d_ncylinders - totsize;
	}
I 15
	threshold = howmany(badsecttable, spc);
E 15
E 14
E 7

	/* 
	 * Figure out if disk is large enough for
	 * expanded swap area and 'd', 'e', and 'f'
	 * partitions.  Otherwise, use smaller defaults
	 * based on RK07.
	 */
	for (def = 0; def < NDEFAULTS; def++) {
		curcyl = 0;
		for (part = PART('a'); part < NPARTITIONS; part++)
			curcyl += howmany(defpart[def][part], spc);
D 15
		if (curcyl < dp->d_ncylinders - threshhold)
E 15
I 15
		if (curcyl < dp->d_ncylinders - threshold)
E 15
			break;
	}
	if (def >= NDEFAULTS) {
		fprintf(stderr, "%s: disk too small, calculate by hand\n",
			*argv);
		exit(3);
	}

	/*
	 * Calculate number of cylinders allocated to each disk
	 * partition.  We may waste a bit of space here, but it's
D 14
	 * in the interest of compatibility (for mixed disk systems).
E 14
I 14
	 * in the interest of (very backward) compatibility
	 * (for mixed disk systems).
E 14
	 */
	for (curcyl = 0, part = PART('a'); part < NPARTITIONS; part++) {
		numcyls[part] = 0;
		if (defpart[def][part] != 0) {
			numcyls[part] = howmany(defpart[def][part], spc);
			curcyl += numcyls[part];
		}
	}
	numcyls[PART('f')] = dp->d_ncylinders - curcyl;
	numcyls[PART('g')] =
		numcyls[PART('d')] + numcyls[PART('e')] + numcyls[PART('f')];
	numcyls[PART('c')] = dp->d_ncylinders;
	defpart[def][PART('f')] = numcyls[PART('f')] * spc - badsecttable;
	defpart[def][PART('g')] = numcyls[PART('g')] * spc - badsecttable;
	defpart[def][PART('c')] = numcyls[PART('c')] * spc;
I 10
#ifndef for_now
E 10
I 8
D 14
	if (!pflag)
		defpart[def][PART('c')] -= badsecttable;
E 14
I 14
	if (totsize || !pflag)
#else
	if (totsize)
E 14
I 10
#endif
I 14
		defpart[def][PART('c')] -= badsecttable;
E 14
E 10
E 8

	/*
	 * Calculate starting cylinder number for each partition.
	 * Note the 'h' partition is physically located before the
	 * 'g' or 'd' partition.  This is reflected in the layout
	 * arrays defined above.
	 */
	for (layout = 0; layout < NLAYOUTS; layout++) {
		curcyl = 0;
		for (lp = layouts[layout]; *lp != 0; lp++) {
			startcyl[PART(*lp)] = curcyl;
			curcyl += numcyls[PART(*lp)];
		}
	}

	if (pflag) {
D 9
		printf("}, %s_sizes[%d] = {\n", dp->d_name, NPARTITIONS);
E 9
I 9
		printf("}, %s_sizes[%d] = {\n", dp->d_typename, NPARTITIONS);
E 9
		for (part = PART('a'); part < NPARTITIONS; part++) {
			if (numcyls[part] == 0) {
				printf("\t0,\t0,\n");
				continue;
			}
D 7
			printf("\t%d,\t%d,\t\t/* %c=cyl %d thru %d */\n",
				defpart[def][part], startcyl[part],
				'A' + part, startcyl[part],
				startcyl[part] + numcyls[part] - 1);
E 7
I 7
D 9
			if (dp->d_sectoffset == 0) {
E 9
I 9
			if (dp->d_type != DTYPE_MSCP) {
E 9
			       printf("\t%d,\t%d,\t\t/* %c=cyl %d thru %d */\n",
					defpart[def][part], startcyl[part],
					'A' + part, startcyl[part],
					startcyl[part] + numcyls[part] - 1);
				continue;
			}
			printf("\t%d,\t%d,\t\t/* %c=sectors %d thru %d */\n",
				defpart[def][part], spc * startcyl[part],
				'A' + part, spc * startcyl[part],
				spc * startcyl[part] + defpart[def][part] - 1);
E 7
		}
		exit(0);
	}
	if (dflag) {
I 2
		int nparts;

E 2
		/*
		 * In case the disk is in the ``in-between'' range
		 * where the 'g' partition is smaller than the 'h'
		 * partition, reverse the frag sizes so the /usr partition
		 * is always set up with a frag size larger than the
		 * user's partition.
		 */
		if (defpart[def][PART('g')] < defpart[def][PART('h')]) {
			int temp;

			temp = defparam[PART('h')].p_fsize;
			defparam[PART('h')].p_fsize =
				defparam[PART('g')].p_fsize;
			defparam[PART('g')].p_fsize = temp;
		}
D 9
		printf("%s:\\\n", dp->d_name);
D 7
		printf("\t:ty=%s:ns#%d:nt#%d:nc#%d:\\\n", dp->d_type,
			dp->d_nsectors, dp->d_ntracks, dp->d_ncylinders);
E 7
I 7
		printf("\t:ty=%s:ns#%d:nt#%d:nc#%d:%s%s\\\n", dp->d_type,
			dp->d_nsectors, dp->d_ntracks, dp->d_ncylinders,
			dp->d_badsectforw ? "sf:" : "",
			dp->d_sectoffset ? "so:" : "");
E 9
I 9
		printf("%s:\\\n", dp->d_typename);
D 11
		printf("\t:ty=%s:ns#%d:nt#%d:nc#%d:", dp->d_name,
E 11
I 11
D 14
		printf("\t:ty=%s:ns#%d:nt#%d:nc#%d:", dp->d_typename,
E 14
I 14
		printf("\t:ty=%s:ns#%d:nt#%d:nc#%d:", tyname,
E 14
E 11
			dp->d_nsectors, dp->d_ntracks, dp->d_ncylinders);
		if (dp->d_secpercyl != dp->d_nsectors * dp->d_ntracks)
			printf("sc#%d:", dp->d_secpercyl);
		if (dp->d_type == DTYPE_SMD && dp->d_flags & D_BADSECT)
			printf("sf:");
D 10
		if (dp->d_type == DTYPE_MSCP)
			printf("so:");
E 10
		printf("\\\n\t:dt=%s:", dktypenames[dp->d_type]);
		for (part = NDDATA - 1; part >= 0; part--)
			if (dp->d_drivedata[part])
				break;
		for (j = 0; j <= part; j++)
			printf("d%d#%d:", j, dp->d_drivedata[j]);
		printf("\\\n");
E 9
E 7
I 2
		for (nparts = 0, part = PART('a'); part < NPARTITIONS; part++)
			if (defpart[def][part] != 0)
				nparts++;
E 2
		for (part = PART('a'); part < NPARTITIONS; part++) {
			if (defpart[def][part] == 0)
				continue;
			printf("\t:p%c#%d:", 'a' + part, defpart[def][part]);
D 2
			if (defparam[part].p_bsize != 0)
E 2
I 2
D 9
			if (defparam[part].p_bsize != 0) {
E 2
				printf("b%c#%d:f%c#%d:",
				  'a' + part, defparam[part].p_bsize,
				  'a' + part, defparam[part].p_fsize);
D 2
			printf("%s\n", part != NPARTITIONS - 1 ? "\\" : "");
E 2
I 2
			}
E 9
I 9
			printf("o%c#%d:b%c#%d:f%c#%d:",
			    'a' + part, spc * startcyl[part],
			    'a' + part,
			    defparam[part].p_frag * defparam[part].p_fsize,
			    'a' + part, defparam[part].p_fsize);
			if (defparam[part].p_fstype == FS_SWAP)
				printf("t%c=swap:", 'a' + part);
E 9
			nparts--;
			printf("%s\n", nparts > 0 ? "\\" : "");
E 2
		}
I 10
#ifdef for_now
D 16
		defpart[def][PART('c')] -= badsecttable;
		part = PART('c');
		printf("#\t:p%c#%d:", 'a' + part, defpart[def][part]);
		printf("o%c#%d:b%c#%d:f%c#%d:\n",
		    'a' + part, spc * startcyl[part],
		    'a' + part,
		    defparam[part].p_frag * defparam[part].p_fsize,
		    'a' + part, defparam[part].p_fsize);
E 16
I 16
		if (!totsize && badsecttable) {
			defpart[def][PART('c')] -= badsecttable;
			part = PART('c');
			printf("#\t:p%c#%d:", 'a' + part, defpart[def][part]);
			printf("o%c#%d:b%c#%d:f%c#%d:\n",
			    'a' + part, spc * startcyl[part],
			    'a' + part,
			    defparam[part].p_frag * defparam[part].p_fsize,
			    'a' + part, defparam[part].p_fsize);
		}
E 16
#endif
E 10
		exit(0);
	}
	printf("%s: #sectors/track=%d, #tracks/cylinder=%d #cylinders=%d\n",
D 9
		dp->d_name, dp->d_nsectors, dp->d_ntracks, dp->d_ncylinders);
E 9
I 9
		dp->d_typename, dp->d_nsectors, dp->d_ntracks,
		dp->d_ncylinders);
E 9
D 14
	printf("\n    Partition\t   Size\t   Range\n");
E 14
I 14
	printf("\n    Partition\t   Size\t Offset\t   Range\n");
E 14
	for (part = PART('a'); part < NPARTITIONS; part++) {
		printf("\t%c\t", 'a' + part);
		if (numcyls[part] == 0) {
			printf(" unused\n");
			continue;
		}
D 14
		printf("%7d\t%4d - %d\n", defpart[def][part], startcyl[part],
			startcyl[part] + numcyls[part] - 1);
E 14
I 14
		printf("%7d\t%7d\t%4d - %d%s\n",
			defpart[def][part], startcyl[part] * spc,
			startcyl[part], startcyl[part] + numcyls[part] - 1,
			defpart[def][part] % spc ? "*" : "");
E 14
	}
}

D 9
struct disktab disk;
E 9
I 9
struct disklabel disk;
E 9

struct	field {
	char	*f_name;
	char	*f_defaults;
D 9
	int	*f_location;
E 9
I 9
	u_long	*f_location;
E 9
} fields[] = {
	{ "sector size",		"512",	&disk.d_secsize },
	{ "#sectors/track",		0,	&disk.d_nsectors },
	{ "#tracks/cylinder",		0,	&disk.d_ntracks },
	{ "#cylinders",			0,	&disk.d_ncylinders },
D 10
	{ "revolutions/minute",		"3600",	&disk.d_rpm },
E 10
	{ 0, 0, 0 },
};

D 9
struct disktab *
E 9
I 9
struct disklabel *
E 9
promptfordisk(name)
	char *name;
{
D 9
	register struct disktab *dp = &disk;
E 9
I 9
	register struct disklabel *dp = &disk;
E 9
	register struct field *fp;
D 9
	static char type[BUFSIZ];
	char buf[BUFSIZ], *cp, *gets();
E 9
I 9
	register i;
	char buf[BUFSIZ], **tp, *cp, *gets();
E 9

D 9
	dp->d_name = name;
E 9
I 9
	strncpy(dp->d_typename, name, sizeof(dp->d_typename));
E 9
	fprintf(stderr,
		"%s: unknown disk type, want to supply parameters (y/n)? ",
		name);
	(void) gets(buf);
	if (*buf != 'y')
D 9
		return ((struct disktab *)0);
E 9
I 9
		return ((struct disklabel *)0);
	for (;;) {
		fprintf(stderr, "Disk/controller type (%s)? ", dktypenames[1]);
		(void) gets(buf);
		if (buf[0] == 0)
			dp->d_type = 1;
		else
			dp->d_type = gettype(buf, dktypenames);
		if (dp->d_type >= 0)
			break;
		fprintf(stderr, "%s: unrecognized controller type\n", buf);
		fprintf(stderr, "use one of:\n", buf);
		for (tp = dktypenames; *tp; tp++)
			if (index(*tp, ' ') == 0)
				fprintf(stderr, "\t%s\n", *tp);
	}
E 9
gettype:
I 9
	dp->d_flags = 0;
E 9
	fprintf(stderr, "type (winchester|removable|simulated)? ");
D 9
	(void) gets(type);
	if (strcmp(type, "winchester") && strcmp(type, "removable") &&
	    strcmp(type, "simulated")) {
		fprintf(stderr, "%s: bad disk type\n", type);
E 9
I 9
	(void) gets(buf);
	if (strcmp(buf, "removable") == 0)
		dp->d_flags = D_REMOVABLE;
	else if (strcmp(buf, "simulated") == 0)
		dp->d_flags = D_RAMDISK;
	else if (strcmp(buf, "winchester")) {
		fprintf(stderr, "%s: bad disk type\n", buf);
E 9
		goto gettype;
	}
D 9
	dp->d_type = type;
E 9
I 9
D 11
	strncpy(dp->d_name, buf, sizeof(dp->d_name));
E 11
I 11
D 15
	strncpy(dp->d_typename, buf, sizeof(dp->d_typename));
E 15
E 11
E 9
	fprintf(stderr, "(type <cr> to get default value, if only one)\n");
I 7
D 9
	fprintf(stderr, "Do %ss require sector or cylinder offsets (%s)? ",
		dp->d_name, "cylinder");
	(void) gets(buf);
	if (*buf == 's')
		dp->d_sectoffset = 1;
	else
		dp->d_sectoffset = 0;
	fprintf(stderr, "Do %ss support bad144 bad block forwarding (yes)? ",
E 9
I 9
D 15
	if (dp->d_type == DTYPE_SMD)
	   fprintf(stderr, "Do %ss support bad144 bad block forwarding (yes)? ",
E 9
D 11
		dp->d_name);
E 11
I 11
		dp->d_typename);
E 11
	(void) gets(buf);
	if (*buf != 'n')
D 9
		dp->d_badsectforw = 1;
	else
		dp->d_badsectforw = 0;
E 9
I 9
		dp->d_flags |= D_BADSECT;
E 15
I 15
	if (dp->d_type == DTYPE_SMD) {
		fprintf(stderr,
			"Do %ss support bad144 bad block forwarding (yes)? ",
			dp->d_typename);
		(void) gets(buf);
		if (*buf != 'n')
			dp->d_flags |= D_BADSECT;
	}
E 15
E 9
E 7
	for (fp = fields; fp->f_name != NULL; fp++) {
again:
		fprintf(stderr, "%s ", fp->f_name);
		if (fp->f_defaults != NULL)
			fprintf(stderr, "(%s)", fp->f_defaults);
		fprintf(stderr, "? ");
		cp = gets(buf);
		if (*cp == '\0') {
			if (fp->f_defaults == NULL) {
				fprintf(stderr, "no default value\n");
				goto again;
			}
			cp = fp->f_defaults;
		}
D 9
		*fp->f_location = atoi(cp);
E 9
I 9
		*fp->f_location = atol(cp);
E 9
		if (*fp->f_location == 0) {
			fprintf(stderr, "%s: bad value\n", cp);
			goto again;
		}
	}
I 9
	fprintf(stderr, "sectors/cylinder (%d)? ",
	    dp->d_nsectors * dp->d_ntracks);
	(void) gets(buf);
	if (buf[0] == 0)
		dp->d_secpercyl = dp->d_nsectors * dp->d_ntracks;
	else
		dp->d_secpercyl = atol(buf);
	fprintf(stderr, "Drive-type-specific parameters, <cr> to terminate:\n");
	for (i = 0; i < NDDATA; i++) {
		fprintf(stderr, "d%d? ", i);
		(void) gets(buf);
		if (buf[0] == 0)
			break;
		dp->d_drivedata[i] = atol(buf);
	}
E 9
	return (dp);
I 9
}

gettype(t, names)
	char *t;
	char **names;
{
	register char **nm;

	for (nm = names; *nm; nm++)
		if (ustrcmp(t, *nm) == 0)
			return (nm - names);
	if (isdigit(*t))
		return (atoi(t));
	return (-1);
}

ustrcmp(s1, s2)
	register char *s1, *s2;
{
#define	lower(c)	(islower(c) ? (c) : tolower(c))

	for (; *s1; s1++, s2++) {
		if (*s1 == *s2)
			continue;
		if (isalpha(*s1) && isalpha(*s2) &&
		    lower(*s1) == lower(*s2))
			continue;
		return (*s2 - *s1);
	}
	return (0);
E 9
}
E 1
