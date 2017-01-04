h42152
s 00077/00003/00612
d D 5.9 88/02/27 15:04:30 mckusick 28 27
c add -m flag to print out memory usage statistics
e
s 00001/00001/00614
d D 5.8 86/12/09 13:43:04 bostic 27 26
c typo in the nlist sanity checking; bug report 4.3BSD/ucb/50
e
s 00004/00000/00611
d D 5.7 86/11/15 11:27:08 sam 26 25
c must include cpu.h for tahoe keystat structure
e
s 00026/00062/00585
d D 5.6 86/07/25 23:26:28 sam 25 24
c 4.3 update; send errors to stderr; cleanup code; widen memory field
e
s 00026/00001/00621
d D 5.5 86/01/24 02:25:39 sam 24 23
c add code and data cache key stats under -s
e
s 00076/00025/00546
d D 5.4 86/01/06 19:50:45 sam 23 22
c add tahoe
e
s 00031/00002/00540
d D 5.3 85/11/20 20:56:39 sam 22 21
c add text cache stats to -s report
e
s 00001/00001/00541
d D 5.2 85/08/26 10:20:17 mckusick 21 20
c spelling
e
s 00014/00002/00528
d D 5.1 85/05/31 09:36:39 dist 20 19
c Add copyright
e
s 00005/00010/00525
d D 4.18 85/04/25 21:25:23 sam 19 18
c when printing header after SIGCONT, reset count to next header
e
s 00149/00067/00386
d D 4.17 85/04/24 23:39:21 sam 18 17
c handle arbitrary number of disk drives; allow drive selection from command line
e
s 00000/00034/00453
d D 4.16 85/04/01 14:37:12 karels 17 16
c rm sun
e
s 00064/00017/00423
d D 4.15 84/10/17 13:50:05 mckusick 16 15
c add -i flag to summarize interrupts
e
s 00006/00003/00434
d D 4.14 84/06/09 13:14:22 sam 15 14
c update for changes to namei cache & and add other stats
e
s 00017/00003/00420
d D 4.13 84/01/04 16:24:57 mckusick 14 13
c add statistical line for namei in -s option
e
s 00023/00029/00400
d D 4.12 83/10/19 20:00:27 sam 13 12
c take into account alternate line clock -- both in defining hz 
c for disk i/o stats and in adjusting interrupt rate; also purge sun swap 
c stats flag -- they page now
e
s 00001/00001/00428
d D 4.11 83/09/25 12:42:58 sam 12 11
c 60 no, hz yes
e
s 00002/00001/00427
d D 4.10 83/05/30 18:41:30 sam 11 9
c show percent of fast reclaims
e
s 00002/00001/00427
d R 4.10 83/05/30 16:54:30 sam 10 9
c show fast reclaim percentage
e
s 00090/00022/00338
d D 4.9 83/02/09 15:22:21 sam 9 8
c from sun
e
s 00008/00008/00352
d D 4.8 82/11/15 11:32:44 sam 8 7
c conversion to 4.1c
e
s 00010/00011/00350
d D 4.7 81/04/28 00:46:52 root 7 6
c new format for output (pages all over), -s prints pgpg*, seqfree
e
s 00003/00006/00358
d D 4.6 81/04/08 18:44:56 root 6 5
c fix to work with no mba's
e
s 00005/00005/00359
d D 4.5 81/03/11 18:50:19 wnj 5 4
c print ``disk'' on top line, names (1 char and 1 number)
e
s 00002/00002/00362
d D 4.4 81/03/10 07:02:09 wnj 4 3
c miscellaneous minor fixups
e
s 00077/00038/00287
d D 4.3 81/03/09 20:51:50 toy 3 2
c Made it know about device names
e
s 00035/00051/00290
d D 4.2 80/10/16 01:08:05 bill 2 1
c new iostat information format
e
s 00341/00000/00000
d D 4.1 80/10/01 17:29:22 bill 1 0
c date and time created 80/10/01 17:29:22 by bill
e
u
U
t
T
I 20
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 20
I 9
#ifndef lint
E 9
I 1
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
D 20
static	char *sccsid = "%W% (Berkeley) %G%";
I 9
#endif
E 20
I 20
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 20

E 9
E 5
#include <stdio.h>
I 18
#include <ctype.h>
#include <nlist.h>

E 18
#include <sys/param.h>
I 18
#include <sys/file.h>
E 18
#include <sys/vm.h>
D 25
#include <sys/dk.h>
E 25
I 25
#include <sys/dkstat.h>
E 25
D 18
#include <nlist.h>
E 18
I 3
#include <sys/buf.h>
I 14
#include <sys/dir.h>
I 18
#include <sys/inode.h>
E 18
D 16
#include <sys/nami.h>
E 16
I 16
#include <sys/namei.h>
I 23
#include <sys/text.h>
I 28
#include <sys/malloc.h>
E 28
E 23
E 16
E 14
I 9
D 18
#ifdef vax
E 9
D 8
#include <sys/ubavar.h>
#include <sys/mbavar.h>
E 8
I 8
#include <vaxuba/ubavar.h>
#include <vaxmba/mbavar.h>
I 9
#endif
E 18
D 17
#ifdef sun
#include <sundev/mbvar.h>
#endif
E 17
E 9
E 8
E 3

struct nlist nl[] = {
D 2
#define	X_DKBUSY 0
	{ "_dk_busy" },
#define	X_DKTIME 1
	{ "_dk_time" },
#define	X_DKNUMB 2
	{ "_dk_numb" },
#define	X_RATE 3
E 2
I 2
#define	X_CPTIME	0
	{ "_cp_time" },
#define	X_RATE		1
E 2
	{ "_rate" },
D 2
#define X_TOTAL 4
E 2
I 2
#define X_TOTAL		2
E 2
	{ "_total" },
D 2
#define	X_DEFICIT 5
E 2
I 2
#define	X_DEFICIT	3
E 2
	{ "_deficit" },
D 2
#define	X_FORKSTAT 6
E 2
I 2
#define	X_FORKSTAT	4
E 2
	{ "_forkstat" },
D 2
#define X_SUM 7
E 2
I 2
#define X_SUM		5
E 2
	{ "_sum" },
D 2
#define	X_FIRSTFREE 8
E 2
I 2
#define	X_FIRSTFREE	6
E 2
	{ "_firstfree" },
D 2
#define	X_MAXFREE 9
E 2
I 2
#define	X_MAXFREE	7
E 2
	{ "_maxfree" },
D 2
#define	X_BOOTIME 10
E 2
I 2
D 8
#define	X_BOOTIME	8
E 2
	{ "_bootime" },
E 8
I 8
#define	X_BOOTTIME	8
	{ "_boottime" },
E 8
I 2
#define	X_DKXFER	9
	{ "_dk_xfer" },
E 2
D 3
#ifdef ERNIE
D 2
#define X_REC 10
E 2
I 2
#define X_REC		10
E 3
I 3
D 9
#define X_MBDINIT	10
	{ "_mbdinit" },
#define X_UBDINIT	11
	{ "_ubdinit" },
#define X_REC		12
E 9
I 9
#define X_REC		10
E 9
E 3
E 2
	{ "_rectime" },
D 2
#define X_PGIN 11
E 2
I 2
D 3
#define X_PGIN		11
E 3
I 3
D 9
#define X_PGIN		13
E 9
I 9
#define X_PGIN		11
E 9
E 3
E 2
	{ "_pgintime" },
D 3
#endif
E 3
I 3
D 9
#define X_HZ		14
E 9
I 9
#define X_HZ		12
E 9
	{ "_hz" },
I 13
D 18
#define	X_PHZ		13
E 18
I 18
#define X_PHZ		13
E 18
	{ "_phz" },
I 14
#define X_NCHSTATS	14
	{ "_nchstats" },
I 16
#define	X_INTRNAMES	15
	{ "_intrnames" },
#define	X_EINTRNAMES	16
	{ "_eintrnames" },
#define	X_INTRCNT	17
	{ "_intrcnt" },
#define	X_EINTRCNT	18
	{ "_eintrcnt" },
I 18
#define	X_DK_NDRIVE	19
	{ "_dk_ndrive" },
I 22
#define	X_XSTATS	20
	{ "_xstats" },
I 28
#define	X_KMEMSTAT	21
	{ "_kmemstats" },
#define	X_KMEMBUCKETS	22
	{ "_bucket" },
E 28
E 22
E 18
E 16
E 14
E 13
E 3
D 9
	{ 0 },
E 9
I 9
#ifdef vax
D 13
#define X_MBDINIT	13
E 13
I 13
D 14
#define X_MBDINIT	14
E 14
I 14
D 16
#define X_MBDINIT	15
E 16
I 16
D 18
#define X_MBDINIT	19
E 18
I 18
D 22
#define X_MBDINIT	20
E 22
I 22
D 23
#define X_MBDINIT	21
E 23
I 23
#define X_MBDINIT	(X_XSTATS+1)
E 23
E 22
E 18
E 16
E 14
E 13
	{ "_mbdinit" },
D 13
#define X_UBDINIT	14
E 13
I 13
D 14
#define X_UBDINIT	15
E 14
I 14
D 16
#define X_UBDINIT	16
E 16
I 16
D 18
#define X_UBDINIT	20
E 18
I 18
D 22
#define X_UBDINIT	21
E 22
I 22
D 23
#define X_UBDINIT	22
E 23
I 23
#define X_UBDINIT	(X_XSTATS+2)
E 23
E 22
E 18
E 16
E 14
E 13
	{ "_ubdinit" },
#endif
I 23
D 25
#ifdef sun
#define X_MBDINIT	(X_XSTATS+1)
	{ "_mbdinit" },
#endif
E 25
#ifdef tahoe
#define	X_VBDINIT	(X_XSTATS+1)
	{ "_vbdinit" },
I 24
#define	X_CKEYSTATS	(X_XSTATS+2)
	{ "_ckeystats" },
#define	X_DKEYSTATS	(X_XSTATS+3)
	{ "_dkeystats" },
E 24
#endif
E 23
D 16
#ifdef sun
D 13
#define X_MBDINIT	13
E 13
I 13
D 14
#define X_MBDINIT	14
E 14
I 14
#define X_MBDINIT	15
E 14
E 13
	{ "_mbdinit" },
#endif
E 16
	{ "" },
E 9
};

I 3
D 18
char dr_name[DK_NDRIVE][10];
char dr_unit[DK_NDRIVE];
E 18
I 18
char	**dr_name;
int	*dr_select;
int	dk_ndrive;
int	ndrives = 0;
#ifdef vax
char	*defdrives[] = { "hp0", "hp1", "hp2",  0 };
#else
char	*defdrives[] = { 0 };
#endif
E 18
E 3
double	stat1();
int	firstfree, maxfree;
I 3
int	hz;
I 13
int	phz;
int	HZ;
I 18

E 18
D 17
#ifdef sun
#define	INTS(x)	(x)
#endif
E 17
D 23
#ifdef vax
#define	INTS(x)	((x) - (hz + phz))
#endif

E 23
E 13
E 3
D 18
struct
{
E 18
I 18
struct {
E 18
	int	busy;
D 2
	long	etime[CPUSTATES][DK_NSTATES];
	long	numb[DK_NDRIVE];
E 2
I 2
	long	time[CPUSTATES];
D 18
	long	xfer[DK_NDRIVE];
E 18
I 18
	long	*xfer;
E 18
E 2
	struct	vmmeter Rate;
	struct	vmtotal	Total;
	struct	vmmeter Sum;
	struct	forkstat Forkstat;
D 3
#ifdef ERNIE
E 3
	unsigned rectime;
	unsigned pgintime;
D 3
#endif
E 3
} s, s1, z;
#define	rate		s.Rate
#define	total		s.Total
#define	sum		s.Sum
#define	forkstat	s.Forkstat

I 9
struct	vmmeter osum;
E 9
D 3
int	iflag = 1;
E 3
D 25
int	zero;
E 25
int	deficit;
double	etime;
int 	mf;
I 16
time_t	now, boottime;
int	printhdr();
I 19
int	lines = 1;
E 19
E 16
I 9
D 13
int	swflag;
E 13
E 9

I 25
#define	INTS(x)	((x) - (hz + phz))

E 25
main(argc, argv)
D 9
char **argv;
E 9
I 9
	int argc;
	char **argv;
E 9
{
D 16
	time_t now;
E 16
D 19
	int lines;
E 19
	extern char *ctime();
D 25
	register i,j;
E 25
I 25
	register i;
E 25
D 16
	int iter, nintv;
D 8
	time_t bootime;
E 8
I 8
	time_t boottime;
E 16
I 16
	int iter, nintv, iflag = 0;
E 16
E 8
D 25
	double f1, f2;
E 25
	long t;
I 18
D 25
	char *arg, **cp, name[6], buf[BUFSIZ];
E 25
I 25
	char *arg, **cp, buf[BUFSIZ];
E 25
E 18
D 16
	extern char _sobuf[];
E 16

I 9
D 13
#ifdef sun
	swflag = 1;
#endif
E 13
E 9
D 16
	setbuf(stdout, _sobuf);
E 16
	nlist("/vmunix", nl);
	if(nl[0].n_type == 0) {
D 25
		printf("no /vmunix namelist\n");
E 25
I 25
		fprintf(stderr, "no /vmunix namelist\n");
E 25
		exit(1);
	}
	mf = open("/dev/kmem", 0);
	if(mf < 0) {
D 25
		printf("cannot open /dev/kmem\n");
E 25
I 25
		fprintf(stderr, "cannot open /dev/kmem\n");
E 25
		exit(1);
	}
	iter = 0;
	argc--, argv++;
	while (argc>0 && argv[0][0]=='-') {
		char *cp = *argv++;
		argc--;
		while (*++cp) switch (*cp) {

I 9
D 13
		case 'S':
			swflag = 1 - swflag;
			break;


E 13
E 9
D 3
#ifdef ERNIE
E 3
		case 't':
			dotimes();
			exit(0);
I 9

E 9
D 3
#endif
E 3
		case 'z':
			close(mf);
			mf = open("/dev/kmem", 2);
D 18
			lseek(mf, (long)nl[X_SUM].n_value, 0);
E 18
I 18
			lseek(mf, (long)nl[X_SUM].n_value, L_SET);
E 18
			write(mf, &z.Sum, sizeof z.Sum);
			exit(0);

		case 'f':
			doforkst();
			exit(0);
		
I 28
		case 'm':
			domem();
			exit(0);

E 28
		case 's':
			dosum();
			exit(0);

I 16
		case 'i':
			iflag++;
			break;

E 16
D 3
		case 'i':
			iflag = 0;
			break;

E 3
		default:
D 16
			fprintf(stderr, "usage: vmstat [ -fs ] [ interval ] [ count]\n");
E 16
I 16
D 18
			fprintf(stderr, "usage: vmstat [ -fsi ] [ interval ] [ count]\n");
E 18
I 18
			fprintf(stderr,
D 28
			    "usage: vmstat [ -fsi ] [ interval ] [ count]\n");
E 28
I 28
			    "usage: vmstat [ -fsim ] [ interval ] [ count]\n");
E 28
E 18
E 16
			exit(1);
		}
	}
D 18
	if(argc > 1)
		iter = atoi(argv[1]);
	lseek(mf, (long)nl[X_FIRSTFREE].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_FIRSTFREE].n_value, L_SET);
E 18
	read(mf, &firstfree, sizeof firstfree);
D 18
	lseek(mf, (long)nl[X_MAXFREE].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_MAXFREE].n_value, L_SET);
E 18
	read(mf, &maxfree, sizeof maxfree);
D 8
	lseek(mf, (long)nl[X_BOOTIME].n_value, 0);
	read(mf, &bootime, sizeof bootime);
E 8
I 8
D 18
	lseek(mf, (long)nl[X_BOOTTIME].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_BOOTTIME].n_value, L_SET);
E 18
	read(mf, &boottime, sizeof boottime);
E 8
I 3
D 18
	lseek(mf, (long)nl[X_HZ].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_HZ].n_value, L_SET);
E 18
	read(mf, &hz, sizeof hz);
I 13
D 18
	lseek(mf, (long)nl[X_PHZ].n_value, 0);
	read(mf, &phz, sizeof phz);
E 18
I 18
	if (nl[X_PHZ].n_value != 0) {
		lseek(mf, (long)nl[X_PHZ].n_value, L_SET);
		read(mf, &phz, sizeof phz);
	}
E 18
	HZ = phz ? phz : hz;
E 13
D 7
	for (i = 0; i < DK_NDRIVE; i++)
	{
E 7
I 7
D 18
	for (i = 0; i < DK_NDRIVE; i++) {
E 7
D 5
		strcpy(dr_name[i], "DK");
E 5
I 5
		strcpy(dr_name[i], "xx");
E 5
		dr_unit[i] = i;
E 18
I 18
D 27
	if (nl[DK_NDRIVE].n_value == 0) {
E 27
I 27
	if (nl[X_DK_NDRIVE].n_value == 0) {
E 27
D 25
		printf("dk_ndrive undefined in system\n");
E 25
I 25
		fprintf(stderr, "dk_ndrive undefined in system\n");
E 25
		exit(1);
E 18
	}
I 18
	lseek(mf, nl[X_DK_NDRIVE].n_value, L_SET);
	read(mf, &dk_ndrive, sizeof (dk_ndrive));
	if (dk_ndrive <= 0) {
D 25
		printf("dk_ndrive %d\n", dk_ndrive);
E 25
I 25
		fprintf(stderr, "dk_ndrive %d\n", dk_ndrive);
E 25
		exit(1);
	}
	dr_select = (int *)calloc(dk_ndrive, sizeof (int));
	dr_name = (char **)calloc(dk_ndrive, sizeof (char *));
#define	allocate(e, t) \
    s./**/e = (t *)calloc(dk_ndrive, sizeof (t)); \
    s1./**/e = (t *)calloc(dk_ndrive, sizeof (t));
	allocate(xfer, long);
	for (arg = buf, i = 0; i < dk_ndrive; i++) {
		dr_name[i] = arg;
		sprintf(dr_name[i], "dk%d", i);
		arg += strlen(dr_name[i]) + 1;
	}
E 18
	read_names();
E 3
	time(&now);
D 8
	nintv = now - bootime;
E 8
I 8
	nintv = now - boottime;
E 8
	if (nintv <= 0 || nintv > 60*60*24*365*10) {
D 25
		printf("Time makes no sense... namelist must be wrong.\n");
E 25
I 25
		fprintf(stderr,
		    "Time makes no sense... namelist must be wrong.\n");
E 25
		exit(1);
	}
I 16
	if (iflag) {
		dointr(nintv);
		exit(0);
	}
I 18
	/*
	 * Choose drives to be displayed.  Priority
	 * goes to (in order) drives supplied as arguments,
	 * default drives.  If everything isn't filled
	 * in and there are drives not taken care of,
	 * display the first few that fit.
	 */
	ndrives = 0;
	while (argc > 0 && !isdigit(argv[0][0])) {
		for (i = 0; i < dk_ndrive; i++) {
			if (strcmp(dr_name[i], argv[0]))
				continue;
			dr_select[i] = 1;
			ndrives++;
		}
		argc--, argv++;
	}
	for (i = 0; i < dk_ndrive && ndrives < 4; i++) {
		if (dr_select[i])
			continue;
		for (cp = defdrives; *cp; cp++)
			if (strcmp(dr_name[i], *cp) == 0) {
				dr_select[i] = 1;
				ndrives++;
				break;
			}
	}
	for (i = 0; i < dk_ndrive && ndrives < 4; i++) {
		if (dr_select[i])
			continue;
		dr_select[i] = 1;
		ndrives++;
	}
	if (argc > 1)
		iter = atoi(argv[1]);
E 18
	signal(SIGCONT, printhdr);
E 16
D 19
reprint:
	lines = 20;
	/* s1 = z; */
D 3
	if (iflag==0)
E 3
D 16
printf("\
D 3
      Procs  Virtual Real         Page        Swap         Disk             Cpu\n\
RQ DW PW SW   AVM TX  FRE  RE AT PI PO FR  DE  SR I O  D0 D1 D2 D3  CS US SY ID\n\
");
	else
printf("\
 Procs     Memory            Page        Swap         Disk  Faults          Cpu\n\
 R B W   AVM  FRE  RE AT PI PO FR  DE  SR I O  D0 D1 D2 D3  IN  SY  CS US SY ID\n\
");
E 3
I 3
D 4
 Procs     Memory            Page        Swap  %s %s %s %s  Faults          Cpu\n\
 R B W   AVM  FRE  RE AT PI PO FR  DE  SR I O  %-2d %-2d %-2d %-2d  IN  SY  CS US SY ID\n\
E 4
I 4
D 5
 procs     memory            page        swap  %s %s %s %s  faults          cpu\n\
 r b w   avm  fre  re at pi po fr  de  sr i o  %-2d %-2d %-2d %-2d  in  sy  cs us sy id\n\
E 4
", dr_name[0], dr_name[1], dr_name[2], dr_name[3], dr_unit[0], dr_unit[1], dr_unit[2], dr_unit[3]);
E 5
I 5
D 7
 procs     memory            page        swap         disk  faults          cpu\n\
 r b w   avm  fre  re at pi po fr  de  sr i o  %c%d %c%d %c%d %c%d  in  sy  cs us sy id\n\
E 7
I 7
 procs     memory                       page      disk  faults          cpu\n\
D 9
 r b w   avm  fre  re at  pi  po  fr  de  sr %c%d %c%d %c%d %c%d  in  sy  cs us sy id\n\
E 7
", dr_name[0][0], dr_unit[0], dr_name[1][0], dr_unit[1], dr_name[2][0], dr_unit[2], dr_name[3][0], dr_unit[3]);
E 9
I 9
D 13
 r b w   avm  fre  %5s  pi  po  fr  de  sr %c%d %c%d %c%d %c%d  in  sy  cs us sy id\n\
", swflag ? "si so" : "re at",
E 13
I 13
 r b w   avm  fre  re at  pi  po  fr  de  sr %c%d %c%d %c%d %c%d  in  sy  cs us sy id\n",
E 13
 dr_name[0][0], dr_unit[0], dr_name[1][0], dr_unit[1], dr_name[2][0], dr_unit[2], dr_name[3][0], dr_unit[3]);
E 16
I 16
	printhdr();
E 19
E 16
E 9
E 5
E 3
loop:
I 19
	if (--lines == 0)
		printhdr();
E 19
D 2
	lseek(mf, (long)nl[X_DKBUSY].n_value, 0);
 	read(mf, &s.busy, sizeof s.busy);
 	lseek(mf, (long)nl[X_DKTIME].n_value, 0);
 	read(mf, s.etime, sizeof s.etime);
 	lseek(mf, (long)nl[X_DKNUMB].n_value, 0);
 	read(mf, s.numb, sizeof s.numb);
E 2
I 2
D 18
	lseek(mf, (long)nl[X_CPTIME].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_CPTIME].n_value, L_SET);
E 18
 	read(mf, s.time, sizeof s.time);
D 18
	lseek(mf, (long)nl[X_DKXFER].n_value, 0);
	read(mf, s.xfer, sizeof s.xfer);
E 2
	if (nintv != 1) {
		lseek(mf, (long)nl[X_SUM].n_value, 0);
		read(mf, &rate, sizeof rate);
	} else {
		lseek(mf, (long)nl[X_RATE].n_value, 0);
		read(mf, &rate, sizeof rate);
	}
	lseek(mf, (long)nl[X_TOTAL].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_DKXFER].n_value, L_SET);
	read(mf, s.xfer, dk_ndrive * sizeof (long));
	if (nintv != 1)
		lseek(mf, (long)nl[X_SUM].n_value, L_SET);
	else
		lseek(mf, (long)nl[X_RATE].n_value, L_SET);
	read(mf, &rate, sizeof rate);
	lseek(mf, (long)nl[X_TOTAL].n_value, L_SET);
E 18
	read(mf, &total, sizeof total);
I 9
	osum = sum;
D 18
	lseek(mf, (long)nl[X_SUM].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_SUM].n_value, L_SET);
E 18
	read(mf, &sum, sizeof sum);
E 9
D 18
	lseek(mf, (long)nl[X_DEFICIT].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_DEFICIT].n_value, L_SET);
E 18
	read(mf, &deficit, sizeof deficit);
I 2
	etime = 0;
E 2
D 18
	for (i=0; i < DK_NDRIVE; i++) {
E 18
I 18
	for (i=0; i < dk_ndrive; i++) {
E 18
D 2
		t = s.numb[i];
		s.numb[i] -= s1.numb[i];
		s1.numb[i] = t;
E 2
I 2
		t = s.xfer[i];
		s.xfer[i] -= s1.xfer[i];
		s1.xfer[i] = t;
E 2
	}
	for (i=0; i < CPUSTATES; i++) {
D 2
		for (j=0; j < DK_NSTATES; j++) {
			t = s.etime[i][j];
			s.etime[i][j] -= s1.etime[i][j];
			s1.etime[i][j] = t;
		}
E 2
I 2
		t = s.time[i];
		s.time[i] -= s1.time[i];
		s1.time[i] = t;
		etime += s.time[i];
E 2
	}
D 2
	t = 0;
	for (i=0; i < CPUSTATES; i++)
		for (j=0; j < DK_NSTATES; j++)
			t += s.etime[i][j];
	etime = t;
E 2
	if(etime == 0.)
		etime = 1.;
D 3
	if (iflag)
		printf("%2d%2d%2d", total.t_rq, total.t_dw+total.t_pw,
		    total.t_sw);
	else
		printf("%2d%3d%3d%3d%3d", total.t_rq, total.t_dw, total.t_pw,
		    total.t_sw);
	if (iflag)
		printf("%6d%5d", total.t_avm/2, total.t_free/2);
	else
		printf("%6d%3d%5d", total.t_avm/2,
		    pct(total.t_avmtxt, total.t_avm), total.t_free/2);
E 3
I 3
	printf("%2d%2d%2d", total.t_rq, total.t_dw+total.t_pw, total.t_sw);
D 9
	printf("%6d%5d", total.t_avm/2, total.t_free/2);
E 3
D 7
	printf("%4d%3d%3d",
E 7
I 7
	printf("%4d%3d%4d",
E 7
	    (rate.v_pgrec - (rate.v_xsfrec+rate.v_xifrec))/nintv,
D 7
	    (rate.v_xsfrec+rate.v_xifrec)/nintv, rate.v_pgin/nintv);
	printf("%3d%3d%4d%4.1f%2d%2d", rate.v_pgout/nintv,
	    rate.v_dfree/nintv, deficit/2,
	    (60.0 * rate.v_scan) / (LOOPSIZ*nintv),
	    rate.v_swpin/nintv, rate.v_swpout/nintv);
E 7
I 7
	    (rate.v_xsfrec+rate.v_xifrec)/nintv, rate.v_pgpgin/2/nintv);
	printf("%4d%4d%4d%4d", rate.v_pgpgout/2/nintv,
	    rate.v_dfree/2/nintv, deficit/2, rate.v_scan/nintv);
E 9
I 9
#define pgtok(a) ((a)*NBPG/1024)
D 25
	printf("%6d%5d", pgtok(total.t_avm), pgtok(total.t_free));
E 25
I 25
	printf("%6d%6d", pgtok(total.t_avm), pgtok(total.t_free));
E 25
D 13
	printf("%4d%3d",
	    swflag ?
	        sum.v_swpin-osum.v_swpin :
	        (rate.v_pgrec - (rate.v_xsfrec+rate.v_xifrec))/nintv,
	    swflag ?
		sum.v_swpout-osum.v_swpout :
	        (rate.v_xsfrec+rate.v_xifrec)/nintv);
E 13
I 13
	printf("%4d%3d", (rate.v_pgrec - (rate.v_xsfrec+rate.v_xifrec))/nintv,
	    (rate.v_xsfrec+rate.v_xifrec)/nintv);
E 13
	printf("%4d", pgtok(rate.v_pgpgin)/nintv);
	printf("%4d%4d%4d%4d", pgtok(rate.v_pgpgout)/nintv,
	    pgtok(rate.v_dfree)/nintv, pgtok(deficit), rate.v_scan/nintv);
E 9
E 7
D 12
	etime /= 60.;
E 12
I 12
D 13
	etime /= (float) hz;
E 13
I 13
D 18
	etime /= (float) HZ;
E 13
E 12
D 7
	printf(" ");
E 7
	for(i=0; i<4; i++)
		stats(i);
E 18
I 18
	etime /= (float)HZ;
	for (i = 0; i < dk_ndrive; i++)
		if (dr_select[i])
			stats(i);
I 23
D 25
#define	INTS(x)	((x) - (hz + phz))
E 25
E 23
E 18
I 9
D 13
#ifdef sun
	printf("%4d%4d", (rate.v_intr/nintv), rate.v_syscall/nintv);
#endif
#ifdef vax
E 9
D 3
	if (iflag)
		printf("%4d%4d", (rate.v_intr/nintv) - HZ,
		    rate.v_syscall/nintv);
E 3
I 3
	printf("%4d%4d", (rate.v_intr/nintv) - hz, rate.v_syscall/nintv);
I 9
#endif
E 9
E 3
	printf("%4d", rate.v_swtch/nintv);
E 13
I 13
	printf("%4d%4d%4d", INTS(rate.v_intr/nintv), rate.v_syscall/nintv,
	    rate.v_swtch/nintv);
E 13
	for(i=0; i<CPUSTATES; i++) {
		float f = stat1(i);
		if (i == 0) {		/* US+NI */
			i++;
			f += stat1(i);
		}
		printf("%3.0f", f);
	}
	printf("\n");
	fflush(stdout);
D 25
contin:
E 25
	nintv = 1;
D 19
	--iter;
	if(iter)
	if(argc > 0) {
E 19
I 19
	if (--iter &&argc > 0) {
E 19
		sleep(atoi(argv[0]));
D 19
		if (--lines <= 0)
			goto reprint;
E 19
		goto loop;
	}
}

I 16
printhdr()
{
D 18
printf("\
 procs     memory                       page      disk  faults          cpu\n\
 r b w   avm  fre  re at  pi  po  fr  de  sr %c%d %c%d %c%d %c%d  in  sy  cs us sy id\n",
 dr_name[0][0], dr_unit[0], dr_name[1][0], dr_unit[1], dr_name[2][0], dr_unit[2], dr_name[3][0], dr_unit[3]);
E 18
I 18
	register int i, j;

D 25
	printf(" procs    memory              page           ");
E 25
I 25
	printf(" procs     memory              page           ");
E 25
	i = (ndrives * 3 - 6) / 2;
	if (i < 0)
		i = 0;
	for (j = 0; j < i; j++)
		putchar(' ');
	printf("faults");
	i = ndrives * 3 - 6 - i;
	for (j = 0; j < i; j++)
		putchar(' ');
	printf("               cpu\n");
D 25
	printf(" r b w   avm  fre  re at  pi  po  fr  de  sr ");
E 25
I 25
	printf(" r b w   avm   fre  re at  pi  po  fr  de  sr ");
E 25
	for (i = 0; i < dk_ndrive; i++)
		if (dr_select[i])
			printf("%c%c ", dr_name[i][0], dr_name[i][2]);	
	printf(" in  sy  cs us sy id\n");
I 19
	lines = 19;
E 19
E 18
}

E 16
D 3
#ifdef ERNIE
E 3
dotimes()
{

D 18
	lseek(mf, (long)nl[X_REC].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_REC].n_value, L_SET);
E 18
	read(mf, &s.rectime, sizeof s.rectime);
D 18
	lseek(mf, (long)nl[X_PGIN].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_PGIN].n_value, L_SET);
E 18
	read(mf, &s.pgintime, sizeof s.pgintime);
D 18
	lseek(mf, (long)nl[X_SUM].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_SUM].n_value, L_SET);
E 18
	read(mf, &sum, sizeof sum);
	printf("%d reclaims, %d total time (usec)\n", sum.v_pgrec, s.rectime);
	printf("average: %d usec / reclaim\n", s.rectime/sum.v_pgrec);
	printf("\n");
	printf("%d page ins, %d total time (msec)\n",sum.v_pgin, s.pgintime/10);
	printf("average: %8.1f msec / page in\n", s.pgintime/(sum.v_pgin*10.0));
}
D 3
#endif
E 3

I 26
#if defined(tahoe)
#include <tahoe/cpu.h>
#endif

E 26
I 22
D 23
/* SHOULD BE AVAILABLE IN <sys/text.h> */
/*
 * Statistics
 */
struct xstats {
	u_long	alloc;			/* calls to xalloc */
	u_long	alloc_inuse;		/*	found in use/sticky */
	u_long	alloc_cachehit;		/*	found in cache */
	u_long	alloc_cacheflush;	/*	flushed cached text */
	u_long	alloc_unused;		/*	flushed unused cached text */
	u_long	free;			/* calls to xfree */
	u_long	free_inuse;		/*	still in use/sticky */
	u_long	free_cache;		/*	placed in cache */
	u_long	free_cacheswap;		/*	swapped out to place in cache */
};
/* END SHOULD BE AVAILABLE... */

E 23
E 22
dosum()
{
I 14
D 18
	struct nchstats statbuf;
E 18
I 18
	struct nchstats nchstats;
I 22
D 24
	struct xstats  xstats;
E 24
I 24
	struct xstats xstats;
E 24
E 22
E 18
	long nchtotal;
I 24
#if defined(tahoe)
	struct keystats keystats;
#endif
E 24
E 14

D 18
	lseek(mf, (long)nl[X_SUM].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_SUM].n_value, L_SET);
E 18
	read(mf, &sum, sizeof sum);
	printf("%9d swap ins\n", sum.v_swpin);
	printf("%9d swap outs\n", sum.v_swpout);
	printf("%9d pages swapped in\n", sum.v_pswpin / CLSIZE);
	printf("%9d pages swapped out\n", sum.v_pswpout / CLSIZE);
	printf("%9d total address trans. faults taken\n", sum.v_faults);
	printf("%9d page ins\n", sum.v_pgin);
	printf("%9d page outs\n", sum.v_pgout);
I 7
	printf("%9d pages paged in\n", sum.v_pgpgin);
	printf("%9d pages paged out\n", sum.v_pgpgout);
	printf("%9d sequential process pages freed\n", sum.v_seqfree);
I 23
D 25
#define	nz(x)	((x) ? (x) : 1)
E 25
E 23
E 7
D 11
	printf("%9d total reclaims\n", sum.v_pgrec);
E 11
I 11
	printf("%9d total reclaims (%d%% fast)\n", sum.v_pgrec,
D 23
	    (sum.v_fastpgrec * 100) / (sum.v_pgrec == 0 ? 1 : sum.v_pgrec));
E 23
I 23
D 25
	    (sum.v_fastpgrec * 100) / nz(sum.v_pgrec));
E 25
I 25
	    pct(sum.v_fastpgrec, sum.v_pgrec));
E 25
E 23
E 11
	printf("%9d reclaims from free list\n", sum.v_pgfrec);
	printf("%9d intransit blocking page faults\n", sum.v_intrans);
	printf("%9d zero fill pages created\n", sum.v_nzfod / CLSIZE);
	printf("%9d zero fill page faults\n", sum.v_zfod / CLSIZE);
	printf("%9d executable fill pages created\n", sum.v_nexfod / CLSIZE);
	printf("%9d executable fill page faults\n", sum.v_exfod / CLSIZE);
	printf("%9d swap text pages found in free list\n", sum.v_xsfrec);
	printf("%9d inode text pages found in free list\n", sum.v_xifrec);
	printf("%9d file fill pages created\n", sum.v_nvrfod / CLSIZE);
	printf("%9d file fill page faults\n", sum.v_vrfod / CLSIZE);
	printf("%9d pages examined by the clock daemon\n", sum.v_scan);
	printf("%9d revolutions of the clock hand\n", sum.v_rev);
	printf("%9d pages freed by the clock daemon\n", sum.v_dfree / CLSIZE);
	printf("%9d cpu context switches\n", sum.v_swtch);
	printf("%9d device interrupts\n", sum.v_intr);
I 16
	printf("%9d software interrupts\n", sum.v_soft);
I 18
#ifdef vax
E 18
E 16
D 21
	printf("%9d pseduo-dma dz interrupts\n", sum.v_pdma);
E 21
I 21
	printf("%9d pseudo-dma dz interrupts\n", sum.v_pdma);
E 21
I 18
#endif
E 18
	printf("%9d traps\n", sum.v_trap);
	printf("%9d system calls\n", sum.v_syscall);
I 14
	lseek(mf, (long)nl[X_NCHSTATS].n_value, 0);
D 18
	read(mf, &statbuf, sizeof statbuf);
	nchtotal = statbuf.ncs_goodhits + statbuf.ncs_badhits +
D 15
		statbuf.ncs_miss + statbuf.ncs_long;
E 15
I 15
	    statbuf.ncs_falsehits + statbuf.ncs_miss + statbuf.ncs_long;
E 18
I 18
	read(mf, &nchstats, sizeof nchstats);
	nchtotal = nchstats.ncs_goodhits + nchstats.ncs_badhits +
	    nchstats.ncs_falsehits + nchstats.ncs_miss + nchstats.ncs_long;
E 18
E 15
	printf("%9d total name lookups", nchtotal);
I 15
D 23
#define	nz(x)	((x) ? (x) : 1)
E 23
E 15
	printf(" (cache hits %d%% system %d%% per-process)\n",
D 15
		statbuf.ncs_goodhits * 100 / nchtotal,
		statbuf.ncs_pass2 * 100 / nchtotal);
E 15
I 15
D 18
	    statbuf.ncs_goodhits * 100 / nz(nchtotal),
	    statbuf.ncs_pass2 * 100 / nz(nchtotal));
E 18
I 18
D 25
	    nchstats.ncs_goodhits * 100 / nz(nchtotal),
	    nchstats.ncs_pass2 * 100 / nz(nchtotal));
E 25
I 25
	    pct(nchstats.ncs_goodhits, nchtotal),
	    pct(nchstats.ncs_pass2, nchtotal));
E 25
E 18
	printf("%9s badhits %d, falsehits %d, toolong %d\n", "",
D 18
	    statbuf.ncs_badhits, statbuf.ncs_falsehits, statbuf.ncs_long);
E 18
I 18
	    nchstats.ncs_badhits, nchstats.ncs_falsehits, nchstats.ncs_long);
I 22
	lseek(mf, (long)nl[X_XSTATS].n_value, 0);
	read(mf, &xstats, sizeof xstats);
	printf("%9d total calls to xalloc (cache hits %d%%)\n",
D 25
	    xstats.alloc, xstats.alloc_cachehit * 100 / nz(xstats.alloc));
E 25
I 25
	    xstats.alloc, pct(xstats.alloc_cachehit, xstats.alloc));
E 25
	printf("%9s sticky %d flushed %d unused %d\n", "",
	    xstats.alloc_inuse, xstats.alloc_cacheflush, xstats.alloc_unused);
	printf("%9d total calls to xfree", xstats.free);
	printf(" (sticky %d cached %d swapped %d)\n",
	    xstats.free_inuse, xstats.free_cache, xstats.free_cacheswap);
I 24
#if defined(tahoe)
	lseek(mf, (long)nl[X_CKEYSTATS].n_value, 0);
	read(mf, &keystats, sizeof keystats);
	printf("%9d %s (free %d%% norefs %d%% taken %d%% shared %d%%)\n",
	    keystats.ks_allocs, "code cache keys allocated",
D 25
	    keystats.ks_free * 100 / nz(keystats.ks_allocs),
	    keystats.ks_norefs * 100 / nz(keystats.ks_allocs),
	    keystats.ks_taken * 100 / nz(keystats.ks_allocs),
	    keystats.ks_shared * 100 / nz(keystats.ks_allocs));
E 25
I 25
D 28
	    pct(keystats.ks_free, keystats.ks_allocs),
E 28
I 28
	    pct(keystats.ks_allocfree, keystats.ks_allocs),
E 28
	    pct(keystats.ks_norefs, keystats.ks_allocs),
	    pct(keystats.ks_taken, keystats.ks_allocs),
	    pct(keystats.ks_shared, keystats.ks_allocs));
E 25
	lseek(mf, (long)nl[X_DKEYSTATS].n_value, 0);
	read(mf, &keystats, sizeof keystats);
	printf("%9d %s (free %d%% norefs %d%% taken %d%% shared %d%%)\n",
	    keystats.ks_allocs, "data cache keys allocated",
D 25
	    keystats.ks_free * 100 / nz(keystats.ks_allocs),
	    keystats.ks_norefs * 100 / nz(keystats.ks_allocs),
	    keystats.ks_taken * 100 / nz(keystats.ks_allocs),
	    keystats.ks_shared * 100 / nz(keystats.ks_allocs));
E 25
I 25
D 28
	    pct(keystats.ks_free, keystats.ks_allocs),
E 28
I 28
	    pct(keystats.ks_allocfree, keystats.ks_allocs),
E 28
	    pct(keystats.ks_norefs, keystats.ks_allocs),
	    pct(keystats.ks_taken, keystats.ks_allocs),
	    pct(keystats.ks_shared, keystats.ks_allocs));
E 25
#endif
E 24
E 22
E 18
E 15
E 14
}

D 9

E 9
doforkst()
{

D 18
	lseek(mf, (long)nl[X_FORKSTAT].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_FORKSTAT].n_value, L_SET);
E 18
	read(mf, &forkstat, sizeof forkstat);
	printf("%d forks, %d pages, average=%.2f\n",
		forkstat.cntfork, forkstat.sizfork,
		(float) forkstat.sizfork / forkstat.cntfork);
	printf("%d vforks, %d pages, average=%.2f\n",
		forkstat.cntvfork, forkstat.sizvfork,
		(float)forkstat.sizvfork / forkstat.cntvfork);
}

stats(dn)
{

D 18
	if (dn >= DK_NDRIVE) {
E 18
I 18
	if (dn >= dk_ndrive) {
E 18
		printf("  0");
		return;
	}
D 2
	printf("%3.0f", s.numb[dn]/etime);
E 2
I 2
	printf("%3.0f", s.xfer[dn]/etime);
E 2
}

double
stat1(row)
{
D 2
	register i, j;
	long t;
	double f1, f2;
E 2
I 2
	double t;
	register i;
E 2

	t = 0;
	for(i=0; i<CPUSTATES; i++)
D 2
		for(j=0; j<DK_NSTATES; j++)
			t += s.etime[i][j];
	f1 = t;
	if(f1 == 0.)
		f1 = 1.;
	t = 0;
	for(j=0; j<DK_NSTATES; j++)
		t += s.etime[row][j];
	f2 = t;
	return(f2*100./f1);
E 2
I 2
		t += s.time[i];
	if(t == 0.)
		t = 1.;
	return(s.time[row]*100./t);
E 2
}

pct(top, bot)
{

	if (bot == 0)
		return (0);
	return ((top * 100) / bot);
I 16
}

dointr(nintv)
{
	int nintr, inttotal;
	long *intrcnt;
	char *intrname, *malloc();

	nintr = (nl[X_EINTRCNT].n_value - nl[X_INTRCNT].n_value) / sizeof(long);
	intrcnt = (long *) malloc(nl[X_EINTRCNT].n_value -
		nl[X_INTRCNT].n_value);
	intrname = malloc(nl[X_EINTRNAMES].n_value - nl[X_INTRNAMES].n_value);
	if (intrcnt == NULL || intrname == NULL) {
		fprintf(stderr, "vmstat: out of memory\n");
		exit(9);
	}
D 18
	lseek(mf, (long)nl[X_INTRCNT].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_INTRCNT].n_value, L_SET);
E 18
	read(mf, intrcnt, nintr * sizeof (long));
D 18
	lseek(mf, (long)nl[X_INTRNAMES].n_value, 0);
E 18
I 18
	lseek(mf, (long)nl[X_INTRNAMES].n_value, L_SET);
E 18
	read(mf, intrname, nl[X_EINTRNAMES].n_value - nl[X_INTRNAMES].n_value);
	printf("interrupt      total      rate\n");
	inttotal = 0;
	while (nintr--) {
		if (*intrcnt)
			printf("%-12s %8ld %8ld\n", intrname,
			    *intrcnt, *intrcnt / nintv);
		intrname += strlen(intrname) + 1;
		inttotal += *intrcnt++;
	}
	printf("Total        %8ld %8ld\n", inttotal, inttotal / nintv);
I 28
}

/*
 * These names must be kept in sync with
 * the types defined in <sys/malloc.h>.
 */
char *kmemnames[] = {
	"free",		/* M_FREE */
	"mbuf",		/* M_MBUF */
	"devbuf",	/* M_DEVBUF */
	"socket",	/* M_SOCKET */
	"pcb",		/* M_PCB */
	"routetbl",	/* M_RTABLE */
	"hosttbl",	/* M_HTABLE */
	"fragtbl",	/* M_FTABLE */
	"zombie",	/* M_ZOMBIE */
	"ifaddr",	/* M_IFADDR */
	"soopts",	/* M_SOOPTS */
	"soname",	/* M_SONAME */
	"namei",	/* M_NAMEI */
	"gprof",	/* M_GPROF */
	"ioctlops",	/* M_IOCTLOPS */
	"superblk",	/* M_SUPERBLK */
	"cred",		/* M_CRED */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"temp",		/* M_TEMP */
};

domem()
{
	struct kmemstats kmemstats[M_LAST];
	struct kmembuckets buckets[MINBUCKET + 16];
	register struct kmembuckets *kp;
	register struct kmemstats *ks;
	int i;

	lseek(mf, (long)nl[X_KMEMBUCKETS].n_value, L_SET);
	read(mf, buckets, sizeof buckets);
	printf("Memory statistics by bucket size\n");
	printf("    Size   In Use   Free   Requests  HighWater  Couldfree\n");
	for (i = MINBUCKET, kp = &buckets[i]; i < MINBUCKET + 16; i++, kp++) {
		if (kp->kb_calls == 0)
			continue;
		printf("%8d%9d%7d%11d%8d%11d\n", 1 << i, 
			kp->kb_total - kp->kb_totalfree,
			kp->kb_totalfree, kp->kb_calls,
			kp->kb_highwat, kp->kb_couldfree);
		
	}
	lseek(mf, (long)nl[X_KMEMSTAT].n_value, L_SET);
	read(mf, kmemstats, sizeof kmemstats);
	printf("Memory statistics by type\n");
	printf("     Type   In Use  MemUse   HighUse  Limit  Requests %s\n",
		"TypeLimit KernLimit");
	for (i = 0, ks = &kmemstats[0]; i < M_LAST; i++, ks++) {
		if (ks->ks_calls == 0)
			continue;
		printf("%10s%7d%8dK%9dK%6dK%9d%7d%10d\n",
			kmemnames[i] ? kmemnames[i] : "undefined",
			ks->ks_inuse, (ks->ks_memuse + 1023) / 1024,
			(ks->ks_maxused + 1023) / 1024,
			(ks->ks_limit + 1023) / 1024, ks->ks_calls,
			ks->ks_limblocks, ks->ks_mapblocks);
	}
E 28
E 16
I 3
}

I 9
D 18
#define steal(where, var) lseek(mf, where, 0); read(mf, &var, sizeof var);
E 18
I 18
#define steal(where, var) \
	lseek(mf, where, L_SET); read(mf, &var, sizeof var);
E 18
E 9
/*
 * Read the drive names out of kmem.
D 9
 * ARGH ARGH ARGH ARGH !!!!!!!!!!!!
E 9
 */
D 9

#define steal(where, var) lseek(mf, where, 0); read(mf, &var, sizeof var);
E 9
I 9
#ifdef vax
I 18
#include <vaxuba/ubavar.h>
#include <vaxmba/mbavar.h>

E 18
E 9
read_names()
{
	struct mba_device mdev;
	register struct mba_device *mp;
	struct mba_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;
	struct uba_device udev, *up;
	struct uba_driver udrv;

	mp = (struct mba_device *) nl[X_MBDINIT].n_value;
	up = (struct uba_device *) nl[X_UBDINIT].n_value;
D 6
	if (mp == 0 || up == 0)
	{
E 6
I 6
	if (up == 0) {
E 6
D 9
		fprintf(stderr, "iostat: Disk init info not in namelist\n");
E 9
I 9
		fprintf(stderr, "vmstat: Disk init info not in namelist\n");
E 9
		exit(1);
	}
D 6
	while(1)
	{
E 6
I 6
	if (mp) for (;;) {
E 6
		steal(mp++, mdev);
		if (mdev.mi_driver == 0)
			break;
		if (mdev.mi_dk < 0 || mdev.mi_alive == 0)
			continue;
		steal(mdev.mi_driver, mdrv);
		steal(mdrv.md_dname, two_char);
D 18
		sprintf(dr_name[mdev.mi_dk], "%c%c", cp[0], cp[1]);
		dr_unit[mdev.mi_dk] = mdev.mi_unit;
E 18
I 18
		sprintf(dr_name[mdev.mi_dk], "%c%c%d",
		    cp[0], cp[1], mdev.mi_unit);
E 18
	}
D 6
	while(1)
	{
E 6
I 6
	for (;;) {
E 6
		steal(up++, udev);
		if (udev.ui_driver == 0)
			break;
		if (udev.ui_dk < 0 || udev.ui_alive == 0)
			continue;
		steal(udev.ui_driver, udrv);
		steal(udrv.ud_dname, two_char);
D 18
		sprintf(dr_name[udev.ui_dk], "%c%c", cp[0], cp[1]);
		dr_unit[udev.ui_dk] = udev.ui_unit;
E 18
I 18
		sprintf(dr_name[udev.ui_dk], "%c%c%d",
		    cp[0], cp[1], udev.ui_unit);
I 23
D 25
	}
}
#endif

#ifdef sun
#include <sundev/mbvar.h>

read_names()
{
	struct mb_device mdev;
	register struct mb_device *mp;
	struct mb_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;

	mp = (struct mb_device *) nl[X_MBDINIT].n_value;
	if (mp == 0) {
		fprintf(stderr, "vmstat: Disk init info not in namelist\n");
		exit(1);
	}
	for (;;) {
		steal(mp++, mdev);
		if (mdev.md_driver == 0)
			break;
		if (mdev.md_dk < 0 || mdev.md_alive == 0)
			continue;
		steal(mdev.md_driver, mdrv);
		steal(mdrv.mdr_dname, two_char);
		sprintf(dr_name[mdev.md_dk], "%c%c%d",
		     cp[0], cp[1], mdev.md_unit);
E 25
	}
}
#endif

#ifdef tahoe
#include <tahoevba/vbavar.h>

/*
 * Read the drive names out of kmem.
 */
read_names()
{
	struct vba_device udev, *up;
	struct vba_driver udrv;
	short two_char;
	char *cp = (char *)&two_char;

	up = (struct vba_device *) nl[X_VBDINIT].n_value;
	if (up == 0) {
		fprintf(stderr, "vmstat: Disk init info not in namelist\n");
		exit(1);
	}
	for (;;) {
		steal(up++, udev);
		if (udev.ui_driver == 0)
			break;
		if (udev.ui_dk < 0 || udev.ui_alive == 0)
			continue;
		steal(udev.ui_driver, udrv);
		steal(udrv.ud_dname, two_char);
		sprintf(dr_name[udev.ui_dk], "%c%c%d",
		     cp[0], cp[1], udev.ui_unit);
E 23
E 18
D 17
	}
E 3
}
I 9
#endif

#ifdef sun
read_names()
{
	struct mb_device mdev;
	register struct mb_device *mp;
	struct mb_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;

	mp = (struct mb_device *) nl[X_MBDINIT].n_value;
	if (mp == 0) {
		fprintf(stderr, "iostat: Disk init info not in namelist\n");
		exit(1);
	}
	for (;;) {
		steal(mp++, mdev);
		if (mdev.md_driver == 0)
			break;
		if (mdev.md_dk < 0 || mdev.md_alive == 0)
			continue;
		steal(mdev.md_driver, mdrv);
		steal(mdrv.mdr_dname, two_char);
		sprintf(dr_name[mdev.md_dk], "%c%c%d", cp[0], cp[1]);
		dr_unit[mdev.md_dk] = mdev.md_unit;
E 17
	}
}
#endif
E 9
E 1
