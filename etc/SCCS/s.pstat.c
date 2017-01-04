h08413
s 00006/00000/01133
d D 5.18 88/02/27 11:11:19 bostic 51 50
c add mpcc tty driver; from Keith Muller
e
s 00033/00052/01100
d D 5.17 88/01/01 17:12:18 bostic 50 49
c use getopt; fix usage statement; -a should imply -p; minor cleanups
e
s 00001/00000/01151
d D 5.16 87/12/26 13:04:56 bostic 49 48
c declare rmalloc, ANSI C fix
e
s 00020/00020/01131
d D 5.15 87/08/30 08:58:06 mckusick 48 47
c getw => getword to avoid stdio definition; bug report 4.3BSD/etc/84
e
s 00004/00000/01147
d D 5.14 87/08/27 07:23:59 bostic 47 46
c make pstat recgonize SLIP; bug report 4.3BSD/etc/82
e
s 00032/00001/01115
d D 5.13 87/08/06 15:35:44 marc 46 45
c under -t, check for qdss tty structs
e
s 00006/00006/01110
d D 5.12 87/04/06 14:58:07 bostic 45 44
c printf format/arg mismatch
e
s 00001/00001/01115
d D 5.11 87/04/06 11:39:05 bostic 44 43
c printf format/argument mismatch
e
s 00004/00008/01112
d D 5.10 87/03/28 17:34:51 karels 43 42
c make -k work on tahoe
e
s 00059/00040/01061
d D 5.9 86/10/13 15:09:00 sam 42 41
c tahoe support
e
s 00002/00001/01099
d D 5.8 86/05/05 17:53:21 mckusick 41 40
c do not count swap devices that have not been enabled (from Guy Harris)
e
s 00093/00022/01007
d D 5.7 86/01/31 08:16:31 karels 40 39
c sanity checks on array sizes, check return of malloc;
c core dumping if /vmunix is wrong is not very elegant
e
s 00001/00005/01028
d D 5.6 85/11/10 13:25:13 karels 39 38
c no more ntab discipline
e
s 00006/00000/01027
d D 5.5 85/10/28 12:36:24 bloom 38 37
c add support for dmz
e
s 00001/00001/01026
d D 5.4 85/10/28 10:15:43 bloom 37 36
c change define for SYSMAP to be correct
e
s 00036/00079/00991
d D 5.3 85/09/04 21:03:15 mckusick 36 35
c dhu support (from mcvax!jim Jim McKie)
e
s 00032/00004/01038
d D 5.2 85/07/26 15:41:33 mckusick 35 34
c fixes for reading kernel dumps (from pur-ee!ghg)
e
s 00015/00002/01027
d D 5.1 85/06/04 16:43:34 dist 34 33
c Add copyright
e
s 00048/00031/00981
d D 4.30 85/06/03 09:39:59 karels 33 32
c hacks on -u: use /dev/mem, fix up format; still lose because 1K
c isn't enough of the u.
e
s 00062/00024/00950
d D 4.29 85/04/16 09:17:59 karels 32 31
c missing ctod(); handle >128 terminals
e
s 00002/00002/00972
d D 4.28 85/04/03 17:04:38 kupfer 31 30
c Fix calculation of swap allocation for text segments.
e
s 00028/00012/00946
d D 4.27 85/02/04 17:29:51 edward 30 29
c print more (but not all) state info in -t
e
s 00007/00011/00951
d D 4.26 84/07/25 15:32:35 bloom 29 28
c Fix user structure to agree with namei change
e
s 00020/00002/00942
d D 4.25 84/02/06 15:34:01 ralph 28 27
c check for dmf's too (-t option).
e
s 00065/00050/00879
d D 4.24 83/10/15 18:45:56 sam 27 26
c swap stats cleanup: print values in kilobytes, calculate true 
c size of swap space instead of believing nswap variable in kernel, rearrange 
c allocations to come before read of swap map in case segment expansion forces 
c change in swap map state (unlikely); also put xdsize routine in-line and 
c take vusize routine verbatim from kernel code
e
s 00001/00000/00928
d D 4.23 83/10/06 10:54:38 sam 26 25
c correct swap map overflow problem; from kre
e
s 00003/00002/00925
d D 4.22 83/06/18 17:07:48 sam 25 24
c no string present to print in case of error
e
s 00004/00001/00923
d D 4.21 83/06/14 01:31:27 sam 24 23
c file table definition changed
e
s 00008/00011/00916
d D 4.20 83/05/28 14:49:43 sam 23 22
c fix up file table printout
e
s 00219/00037/00708
d D 4.19 83/05/18 02:45:42 sam 22 21
c changes mostly for new swapping algorithms (from shannon@sun.UUCP)
e
s 00026/00004/00719
d D 4.18 83/04/15 14:29:14 edward 21 20
c Now knows about dmf.  And formatting changed slightly.
e
s 00001/00001/00722
d D 4.17 82/12/24 12:47:37 sam 20 19
c pte.h moved
e
s 00014/00018/00709
d D 4.16 82/12/13 21:58:29 sam 19 18
c update for new data structures
e
s 00042/00019/00685
d D 4.15 82/10/19 16:37:23 sam 18 16
c add usage messages and update for 4.1b
e
s 00042/00019/00685
d R 4.15 82/10/19 16:35:08 sam 17 16
c add usages and fix up tables printouts for 4.1b
e
s 00001/00001/00703
d D 4.14 82/06/27 11:35:35 root 16 15
c fix to -f per cak@purdue
e
s 00000/00001/00704
d D 4.13 82/05/10 17:35:23 sam 15 14
c no more u_dbuf
e
s 00001/00001/00704
d D 4.12 82/05/10 17:32:57 sam 14 13
c i_rdev redefined
e
s 00012/00018/00693
d D 4.11 82/03/31 12:04:38 root 13 12
c pty stuff
e
s 00031/00115/00680
d D 4.10 82/02/28 21:27:24 wnj 12 9
c new flag names for tty and no mpx and sockets
e
s 00034/00006/00839
d R 4.11 81/06/11 15:45:08 wnj 11 10
c print pty's
e
s 00050/00000/00795
d R 4.10 81/05/08 15:04:09 root 10 9
c add stuff for new pipe code
e
s 00010/00000/00785
d D 4.9 81/05/07 14:21:41 root 9 8
c fix pstat -tk
e
s 00002/00000/00783
d D 4.8 81/04/15 03:06:53 root 8 7
c fix bug in 'k' option
e
s 00002/00005/00781
d D 4.7 81/04/14 20:08:59 root 7 6
c fixed bugs with 'k' flag
e
s 00007/00006/00779
d D 4.6 81/03/10 07:02:00 wnj 6 5
c miscellaneous minor fixups
e
s 00093/00053/00692
d D 4.5 81/02/28 23:05:43 wnj 5 4
c new kernel proc structure scheme
e
s 00120/00001/00625
d D 4.4 81/02/10 14:47:36 hickman 4 3
c Added mpx debug stuff (-mg flags) (kebh)
e
s 00002/00002/00624
d D 4.3 80/11/15 14:26:48 bill 3 2
c fixes per mja
e
s 00004/00005/00622
d D 4.2 80/10/15 23:52:44 bill 2 1
c un-barfup pstat
e
s 00627/00000/00000
d D 4.1 80/10/01 17:27:52 bill 1 0
c date and time created 80/10/01 17:27:52 by bill
e
u
U
t
T
I 34
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 34
I 18
#ifndef lint
E 18
I 1
D 12
static char *sccsid = "%W% (Berkeley) %G%";
E 12
I 12
D 22
static char *sccsid = "%Z% (Berkeley) %E%";
E 22
I 22
D 34
static char *sccsid = "%W% (Berkeley) %G%";
E 22
I 18
#endif
E 34
I 34
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 50
#endif not lint
E 50
I 50
#endif /* not lint */
E 50

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 50
#endif not lint
E 50
I 50
#endif /* not lint */
E 50

E 34
E 18
E 12
/*
 * Print system stuff
 */

D 43
#define mask(x) (x&0377)
I 42
#ifdef vax
E 42
#define	clear(x) ((int)x&0x7fffffff)
I 42
#endif
#ifdef tahoe
#define	clear(x) ((int)x&~0xc0000000)
#endif
E 42

E 43
#include <sys/param.h>
#include <sys/dir.h>
I 18
#define	KERNEL
E 18
#include <sys/file.h>
I 18
#undef	KERNEL
E 18
#include <sys/user.h>
#include <sys/proc.h>
#include <sys/text.h>
#include <sys/inode.h>
#include <sys/map.h>
I 19
#include <sys/ioctl.h>
E 19
#include <sys/tty.h>
#include <sys/conf.h>
#include <sys/vm.h>
#include <nlist.h>
D 20
#include <sys/pte.h>
E 20
I 20
#include <machine/pte.h>
I 40
#include <stdio.h>
E 40
E 20
I 4
D 18
#define	KERNEL
D 12
#include <sys/mx.h>
E 12
#undef	KERNEL
E 18
I 18
D 23
#include <sys/descrip.h>
E 23
E 18
E 4

I 43
#define mask(x)		(x&0377)
#define	clear(x)	((int)x &~ KERNBASE)

E 43
char	*fcore	= "/dev/kmem";
I 33
char	*fmem	= "/dev/mem";
E 33
char	*fnlist	= "/vmunix";
D 33
int	fc;
E 33
I 33
int	fc, fm;
E 33

struct nlist nl[] = {
#define	SINODE	0
	{ "_inode" },
#define	STEXT	1
	{ "_text" },
#define	SPROC	2
	{ "_proc" },
D 42
#define	SDZ	3
	{ "_dz_tty" },
#define	SNDZ	4
	{ "_dz_cnt" },
#define	SKL	5
E 42
I 42
#define	SCONS	3
E 42
	{ "_cons" },
D 42
#define	SFIL	6
E 42
I 42
#define	SFIL	4
E 42
	{ "_file" },
D 42
#define	USRPTMA	7
E 42
I 42
#define	USRPTMA	5
E 42
	{ "_Usrptmap" },
D 42
#define	USRPT	8
E 42
I 42
#define	USRPT	6
E 42
	{ "_usrpt" },
D 27
#define	SNSWAP	9
	{ "_nswap" },
#define	SWAPMAP	10
E 27
I 27
D 42
#define	SWAPMAP	9
E 42
I 42
#define	SWAPMAP	7
E 42
E 27
	{ "_swapmap" },
D 27
#define	SDH	11
E 27
I 27
D 42
#define	SDH	10
E 27
	{ "_dh11" },
D 27
#define	SNDH	12
E 27
I 27
#define	SNDH	11
E 27
	{ "_ndh11" },
I 4
D 13
#define	SGROUP	13
	{ "_groups" },
#define	SCHANS	14
	{ "_chans" },
#define	SSCHANS	15
	{ "_schans" },
I 5
#define	SNPROC	16
E 13
I 13
D 27
#define	SNPROC	13
E 27
I 27
#define	SNPROC	12
E 42
I 42
#define	SNPROC	8
E 42
E 27
E 13
	{ "_nproc" },
D 13
#define	SNTEXT	17
E 13
I 13
D 27
#define	SNTEXT	14
E 27
I 27
D 42
#define	SNTEXT	13
E 42
I 42
#define	SNTEXT	9
E 42
E 27
E 13
	{ "_ntext" },
D 13
#define	SNFILE	18
E 13
I 13
D 27
#define	SNFILE	15
E 27
I 27
D 42
#define	SNFILE	14
E 42
I 42
#define	SNFILE	10
E 42
E 27
E 13
	{ "_nfile" },
D 13
#define	SNINODE	19
E 13
I 13
D 27
#define	SNINODE	16
E 27
I 27
D 42
#define	SNINODE	15
E 42
I 42
#define	SNINODE	11
E 42
E 27
E 13
	{ "_ninode" },
D 13
#define	SNSWAPMAP 20
E 13
I 13
D 27
#define	SNSWAPMAP 17
E 27
I 27
D 42
#define	SNSWAPMAP 16
E 42
I 42
#define	SNSWAPMAP 12
E 42
E 27
E 13
	{ "_nswapmap" },
I 12
D 13
#define	SPTY	21
E 13
I 13
D 27
#define	SPTY	18
E 27
I 27
D 42
#define	SPTY	17
E 42
I 42
#define	SPTY	13
E 42
E 27
E 13
	{ "_pt_tty" },
I 21
D 22
#define SDMF	19
	{ "_dmf_tty" },
#define SNDMF	20
	{ "_ndmf" },
E 22
I 22
D 27
#define	SDMMIN	19
E 27
I 27
D 42
#define	SDMMIN	18
E 42
I 42
#define	SDMMIN	14
E 42
E 27
	{ "_dmmin" },
D 27
#define	SDMMAX	20
E 27
I 27
D 42
#define	SDMMAX	19
E 42
I 42
#define	SDMMAX	15
E 42
E 27
	{ "_dmmax" },
D 27
#define	SNSWDEV	21
E 27
I 27
D 42
#define	SNSWDEV	20
E 42
I 42
#define	SNSWDEV	16
E 42
E 27
	{ "_nswdev" },
E 22
E 21
E 12
E 5
E 4
D 27
	0,
E 27
I 27
D 42
#define	SSWDEVT	21
E 42
I 42
#define	SSWDEVT	17
E 42
	{ "_swdevt" },
I 28
D 42
#define	SDMF	22
E 42
I 42
#define	SYSMAP	18
	{ "_Sysmap" },
#define	SNPTY	19
	{ "_npty" },
#ifdef vax
#define	SDZ	(SNPTY+1)
	{ "_dz_tty" },
#define	SNDZ	(SNPTY+2)
	{ "_dz_cnt" },
#define	SDMF	(SNPTY+3)
E 42
	{ "_dmf_tty" },
D 42
#define	SNDMF	23
E 42
I 42
#define	SNDMF	(SNPTY+4)
E 42
	{ "_ndmf" },
I 32
D 42
#define	SNPTY	24
	{ "_npty" },
I 36
#define	SDHU	25
E 42
I 42
#define	SDH	(SNPTY+5)
	{ "_dh11" },
#define	SNDH	(SNPTY+6)
	{ "_ndh11" },
#define	SDHU	(SNPTY+7)
E 42
	{ "_dhu_tty" },
D 42
#define	SNDHU	26
E 42
I 42
#define	SNDHU	(SNPTY+8)
E 42
	{ "_ndhu" },
E 36
I 35
D 37
#define	SYSMAP	25
E 37
I 37
D 42
#define	SYSMAP	27
E 37
	{ "_Sysmap" },
I 38
#define	SDMZ	28
E 42
I 42
#define	SDMZ	(SNPTY+9)
E 42
	{ "_dmz_tty" },
D 42
#define	SNDMZ	29
E 42
I 42
#define	SNDMZ	(SNPTY+10)
E 42
	{ "_ndmz" },
I 46
#define	SQD	(SNPTY+11)
	{ "_qd_tty" },
#define	SNQD	(SNPTY+12)
	{ "_nNQD" },
E 46
I 42
#endif
#ifdef tahoe
#define	SVX	(SNPTY+1)
	{ "_vx_tty" },
#define	SNVX	(SNPTY+2)
	{ "_nvx" },
I 51
#define	SMP	(SNPTY+3)
	{ "_mp_tty" },
#define	SNMP	(SNPTY+4)
	{ "_nmp" },
E 51
#endif
E 42
E 38
E 35
E 32
E 28
	{ "" }
E 27
};

int	inof;
int	txtf;
int	prcf;
int	ttyf;
int	usrf;
I 4
D 18
int	mpxf;
int	groupf;
E 18
E 4
long	ubase;
int	filf;
int	swpf;
int	totflg;
char	partab[1];
struct	cdevsw	cdevsw[1];
struct	bdevsw	bdevsw[1];
int	allflg;
int	kflg;
struct	pte *Usrptma;
struct	pte *usrpt;
I 40
D 48
u_long	getw();
E 48
I 48
u_long	getword();
E 48
off_t	mkphys();
E 40

main(argc, argv)
D 50
char **argv;
E 50
I 50
	int argc;
	char **argv;
E 50
{
D 50
	register char *argp;
I 18
	int allflags;
E 50
I 50
	extern char *optarg;
	extern int optind;
	int ch;
E 50
E 18

D 50
	argc--, argv++;
	while (argc > 0 && **argv == '-') {
		argp = *argv++;
		argp++;
		argc--;
		while (*argp++)
		switch (argp[-1]) {

E 50
I 50
	while ((ch = getopt(argc, argv, "Tafikptu:sx")) != EOF)
		switch((char)ch) {
E 50
		case 'T':
			totflg++;
			break;
D 50

E 50
		case 'a':
			allflg++;
I 50
			/*FALLTHROUGH*/
		case 'p':
			prcf++;
E 50
			break;
D 50

E 50
I 50
		case 'f':
			filf++;
			break;
E 50
		case 'i':
			inof++;
			break;
D 50

		case 'k':
E 50
I 50
		case 'k':			/* undocumented */
E 50
			kflg++;
D 33
			fcore = "/vmcore";
E 33
I 33
			fcore = fmem = "/vmcore";
E 33
			break;
D 50

		case 'x':
			txtf++;
			break;

		case 'p':
			prcf++;
			break;

E 50
		case 't':
			ttyf++;
			break;
D 50

E 50
		case 'u':
D 50
			if (argc == 0)
				break;
			argc--;
E 50
			usrf++;
D 50
			sscanf( *argv++, "%x", &ubase);
E 50
I 50
			sscanf(optarg, "%x", &ubase);
E 50
			break;
D 50

		case 'f':
			filf++;
			break;
E 50
		case 's':
			swpf++;
			break;
I 50
		case 'x':
			txtf++;
			break;
		case '?':
E 50
I 4
D 18
		case 'm':
			mpxf++;
			break;
		case 'g':
			groupf++;
			break;
E 18
I 18
		default:
D 50
			usage();
E 50
I 50
			printf("usage: pstat -[Tafiptsx] [-u [ubase]] [system] [core]\n");
E 50
			exit(1);
E 18
E 4
		}
D 50
	}
E 50
I 50
	argc -= optind;
	argv += optind;

E 50
D 18
	if (argc>0)
		fcore = argv[0];
E 18
I 18
D 40
	if (argc>1)
E 40
I 40
	if (argc>1) {
E 40
D 33
		fcore = argv[1];
E 33
I 33
		fcore = fmem = argv[1];
I 40
		kflg++;
	}
E 40
E 33
E 18
D 50
	if ((fc = open(fcore, 0)) < 0) {
		printf("Can't find %s\n", fcore);
E 50
I 50
	if ((fc = open(fcore, O_RDONLY, 0)) < 0) {
		perror(fcore);
E 50
		exit(1);
	}
I 33
D 50
	if ((fm = open(fmem, 0)) < 0) {
		printf("Can't find %s\n", fmem);
E 50
I 50
	if ((fm = open(fmem, O_RDONLY, 0)) < 0) {
		perror(fmem);
E 50
		exit(1);
	}
E 33
D 18
	if (argc>1)
		fnlist = argv[1];
E 18
I 18
	if (argc>0)
		fnlist = argv[0];
E 18
	nlist(fnlist, nl);
D 7
	if (kflg) {
		register struct nlist *nlp;
		for (nlp=nl; nlp < &nl[sizeof (nl)/sizeof(nl[0])]; nlp++)
			nlp->n_value = clear(nlp->n_value);
	}
E 7
D 50
	usrpt = (struct pte *)nl[USRPT].n_value;
	Usrptma = (struct pte *)nl[USRPTMA].n_value;
E 50
	if (nl[0].n_type == 0) {
D 50
		printf("no namelist\n");
E 50
I 50
		printf("pstat: no namelist.\n");
E 50
		exit(1);
	}
I 18
D 50
	allflags = filf | totflg | inof | prcf | txtf | ttyf | usrf | swpf;
	if (allflags == 0) {
E 50
I 50
	usrpt = (struct pte *)nl[USRPT].n_value;
	Usrptma = (struct pte *)nl[USRPTMA].n_value;
	if (!(filf | totflg | inof | prcf | txtf | ttyf | usrf | swpf)) {
E 50
		printf("pstat: one or more of -[aixptfsu] is required\n");
		exit(1);
	}
E 18
	if (filf||totflg)
D 5
		dofil();
E 5
I 5
		dofile();
E 5
	if (inof||totflg)
		doinode();
	if (prcf||totflg)
		doproc();
	if (txtf||totflg)
		dotext();
	if (ttyf)
		dotty();
	if (usrf)
		dousr();
	if (swpf||totflg)
		doswap();
I 4
D 5
	if (mpxf||totflg)
E 5
I 5
D 12
	if (mpxf)
E 5
		dompx();
D 5
	if (groupf||totflg)
E 5
I 5
	if (groupf)
E 5
		dogroup();
E 12
E 4
D 50
}

I 18
usage()
{

	printf("usage: pstat -[aixptfs] [-u [ubase]] [system] [core]\n");
E 50
}

E 18
doinode()
{
	register struct inode *ip;
D 5
	struct inode xinode[NINODE];
	register int nin, loc;
E 5
I 5
	struct inode *xinode, *ainode;
	register int nin;
	int ninode;
E 5

	nin = 0;
D 5
	lseek(fc, (long)nl[SINODE].n_value, 0);
	read(fc, xinode, sizeof(xinode));
	for (ip = xinode; ip < &xinode[NINODE]; ip++)
E 5
I 5
D 48
	ninode = getw(nl[SNINODE].n_value);
E 48
I 48
	ninode = getword(nl[SNINODE].n_value);
E 48
	xinode = (struct inode *)calloc(ninode, sizeof (struct inode));
D 35
	lseek(fc, (int)(ainode = (struct inode *)getw(nl[SINODE].n_value)), 0);
E 35
I 35
D 48
	ainode = (struct inode *)getw(nl[SINODE].n_value);
E 48
I 48
	ainode = (struct inode *)getword(nl[SINODE].n_value);
E 48
D 40
	lseek(fc, mkphys((int)ainode), 0);
E 40
I 40
	if (ninode < 0 || ninode > 10000) {
		fprintf(stderr, "number of inodes is preposterous (%d)\n",
			ninode);
		return;
	}
	if (xinode == NULL) {
		fprintf(stderr, "can't allocate memory for inode table\n");
		return;
	}
	lseek(fc, mkphys((off_t)ainode), 0);
E 40
E 35
	read(fc, xinode, ninode * sizeof(struct inode));
	for (ip = xinode; ip < &xinode[ninode]; ip++)
E 5
		if (ip->i_count)
			nin++;
	if (totflg) {
D 5
		printf("%3d/%3d inodes\n", nin, NINODE);
E 5
I 5
		printf("%3d/%3d inodes\n", nin, ninode);
E 5
		return;
	}
D 5
	printf("%d/%d active xinodes\n", nin, NINODE);
E 5
I 5
	printf("%d/%d active inodes\n", nin, ninode);
E 5
D 18
	printf("   LOC    FLAGS  CNT DEVICE   INO  MODE  NLK UID   SIZE/DEV\n");
E 18
I 18
printf("   LOC      FLAGS    CNT DEVICE  RDC WRC  INO  MODE  NLK UID   SIZE/DEV\n");
E 18
D 5
	loc = nl[SINODE].n_value;
	for (ip = xinode; ip < &xinode[NINODE]; ip++, loc += sizeof(xinode[0])) {
E 5
I 5
	for (ip = xinode; ip < &xinode[ninode]; ip++) {
E 5
		if (ip->i_count == 0)
			continue;
D 5
		printf("%8.1x ", loc);
E 5
I 5
		printf("%8.1x ", ainode + (ip - xinode));
E 5
D 19
		putf(ip->i_flag&ILOCK, 'L');
E 19
I 19
		putf(ip->i_flag&ILOCKED, 'L');
E 19
		putf(ip->i_flag&IUPD, 'U');
		putf(ip->i_flag&IACC, 'A');
		putf(ip->i_flag&IMOUNT, 'M');
		putf(ip->i_flag&IWANT, 'W');
		putf(ip->i_flag&ITEXT, 'T');
I 18
		putf(ip->i_flag&ICHG, 'C');
		putf(ip->i_flag&ISHLOCK, 'S');
		putf(ip->i_flag&IEXLOCK, 'E');
		putf(ip->i_flag&ILWAIT, 'Z');
E 18
		printf("%4d", ip->i_count&0377);
		printf("%4d,%3d", major(ip->i_dev), minor(ip->i_dev));
I 18
D 19
		printf("%4d", ip->i_rdlockc&0377);
		printf("%4d", ip->i_wrlockc&0377);
E 19
I 19
		printf("%4d", ip->i_shlockc&0377);
		printf("%4d", ip->i_exlockc&0377);
E 19
E 18
		printf("%6d", ip->i_number);
		printf("%6x", ip->i_mode & 0xffff);
		printf("%4d", ip->i_nlink);
		printf("%4d", ip->i_uid);
		if ((ip->i_mode&IFMT)==IFBLK || (ip->i_mode&IFMT)==IFCHR)
D 14
			printf("%6d,%3d", major(ip->i_un.i_rdev), minor(ip->i_un.i_rdev));
E 14
I 14
			printf("%6d,%3d", major(ip->i_rdev), minor(ip->i_rdev));
E 14
		else
			printf("%10ld", ip->i_size);
		printf("\n");
	}
I 5
	free(xinode);
E 5
}

I 40
u_long
E 40
I 5
D 48
getw(loc)
E 48
I 48
getword(loc)
E 48
	off_t loc;
{
D 40
	int word;
E 40
I 40
	u_long word;
E 40

I 7
	if (kflg)
D 42
		loc &= 0x7fffffff;
E 42
I 42
		loc = clear(loc);
E 42
E 7
	lseek(fc, loc, 0);
	read(fc, &word, sizeof (word));
I 8
D 40
	if (kflg)
		word &= 0x7fffffff;
E 40
E 8
	return (word);
}

E 5
putf(v, n)
{
	if (v)
		printf("%c", n);
	else
D 4
		printf(" ");
E 4
I 4
D 5
		printf("_");
E 5
I 5
		printf(" ");
E 5
E 4
}

dotext()
{
	register struct text *xp;
D 5
	struct text xtext[NTEXT];
	register loc;
E 5
I 5
	int ntext;
	struct text *xtext, *atext;
E 5
D 40
	int ntx;
E 40
I 40
	int ntx, ntxca;
E 40

D 40
	ntx = 0;
E 40
I 40
	ntx = ntxca = 0;
E 40
D 5
	lseek(fc, (long)nl[STEXT].n_value, 0);
	read(fc, xtext, sizeof(xtext));
	for (xp = xtext; xp < &xtext[NTEXT]; xp++)
E 5
I 5
D 48
	ntext = getw(nl[SNTEXT].n_value);
E 48
I 48
	ntext = getword(nl[SNTEXT].n_value);
E 48
	xtext = (struct text *)calloc(ntext, sizeof (struct text));
D 35
	lseek(fc, (int)(atext = (struct text *)getw(nl[STEXT].n_value)), 0);
E 35
I 35
D 48
	atext = (struct text *)getw(nl[STEXT].n_value);
E 48
I 48
	atext = (struct text *)getword(nl[STEXT].n_value);
E 48
D 40
	lseek(fc, mkphys((int)atext), 0);
E 40
I 40
	if (ntext < 0 || ntext > 10000) {
		fprintf(stderr, "number of texts is preposterous (%d)\n",
			ntext);
		return;
	}
	if (xtext == NULL) {
		fprintf(stderr, "can't allocate memory for text table\n");
		return;
	}
	lseek(fc, mkphys((off_t)atext), 0);
E 40
E 35
	read(fc, xtext, ntext * sizeof (struct text));
D 40
	for (xp = xtext; xp < &xtext[ntext]; xp++)
E 5
		if (xp->x_iptr!=NULL)
E 40
I 40
	for (xp = xtext; xp < &xtext[ntext]; xp++) {
		if (xp->x_iptr != NULL)
			ntxca++;
		if (xp->x_count != 0)
E 40
			ntx++;
I 40
	}
E 40
	if (totflg) {
D 5
		printf("%3d/%3d texts\n", ntx, NTEXT);
E 5
I 5
D 40
		printf("%3d/%3d texts\n", ntx, ntext);
E 40
I 40
		printf("%3d/%3d texts active, %3d used\n", ntx, ntext, ntxca);
E 40
E 5
		return;
	}
I 5
D 40
	printf("%d/%d active texts\n", ntx, ntext);
E 5
D 2
	printf("   LOC   FLAGS  PTDADDR DADDR  CADDR  RSS   SIZE   IPTR    CNT CCNT\n");
E 2
I 2
	printf("   LOC   FLAGS DADDR      CADDR  RSS SIZE      IPTR  CNT CCNT\n");
E 40
I 40
	printf("%d/%d active texts, %d used\n", ntx, ntext, ntxca);
	printf("\
   LOC   FLAGS DADDR     CADDR  RSS SIZE     IPTR   CNT CCNT      FORW     BACK\n");
E 40
E 2
D 5
	loc = nl[STEXT].n_value;
	for (xp = xtext; xp < &xtext[NTEXT]; xp++, loc+=sizeof(xtext[0])) {
E 5
I 5
	for (xp = xtext; xp < &xtext[ntext]; xp++) {
E 5
		if (xp->x_iptr == NULL)
			continue;
D 5
		printf("%8.1x", loc);
E 5
I 5
		printf("%8.1x", atext + (xp - xtext));
E 5
		printf(" ");
		putf(xp->x_flag&XPAGI, 'P');
		putf(xp->x_flag&XTRC, 'T');
		putf(xp->x_flag&XWRIT, 'W');
		putf(xp->x_flag&XLOAD, 'L');
		putf(xp->x_flag&XLOCK, 'K');
		putf(xp->x_flag&XWANT, 'w');
D 2
		printf("%8x", xp->x_ptdaddr);
E 2
		printf("%5x", xp->x_daddr[0]);
D 40
		printf("%11x", xp->x_caddr);
E 40
I 40
		printf("%10x", xp->x_caddr);
E 40
		printf("%5d", xp->x_rssize);
		printf("%5d", xp->x_size);
		printf("%10.1x", xp->x_iptr);
		printf("%5d", xp->x_count&0377);
D 2
		printf("%4d", xp->x_ccount);
E 2
I 2
		printf("%5d", xp->x_ccount);
I 40
		printf("%10x", xp->x_forw);
		printf("%9x", xp->x_back);
E 40
E 2
		printf("\n");
	}
I 5
	free(xtext);
E 5
}

doproc()
{
D 5
	struct proc xproc[NPROC];
E 5
I 5
	struct proc *xproc, *aproc;
	int nproc;
E 5
	register struct proc *pp;
	register loc, np;
	struct pte apte;

D 5
	lseek(fc, (long)nl[SPROC].n_value, 0);
	read(fc, xproc, sizeof(xproc));
E 5
I 5
D 48
	nproc = getw(nl[SNPROC].n_value);
E 48
I 48
	nproc = getword(nl[SNPROC].n_value);
E 48
	xproc = (struct proc *)calloc(nproc, sizeof (struct proc));
D 35
	lseek(fc, (int)(aproc = (struct proc *)getw(nl[SPROC].n_value)), 0);
E 35
I 35
D 48
	aproc = (struct proc *)getw(nl[SPROC].n_value);
E 48
I 48
	aproc = (struct proc *)getword(nl[SPROC].n_value);
E 48
D 40
	lseek(fc, mkphys((int)aproc), 0);
E 40
I 40
	if (nproc < 0 || nproc > 10000) {
		fprintf(stderr, "number of procs is preposterous (%d)\n",
			nproc);
		return;
	}
	if (xproc == NULL) {
		fprintf(stderr, "can't allocate memory for proc table\n");
		return;
	}
	lseek(fc, mkphys((off_t)aproc), 0);
E 40
E 35
	read(fc, xproc, nproc * sizeof (struct proc));
E 5
	np = 0;
D 5
	for (pp=xproc; pp < &xproc[NPROC]; pp++)
E 5
I 5
	for (pp=xproc; pp < &xproc[nproc]; pp++)
E 5
		if (pp->p_stat)
			np++;
	if (totflg) {
D 5
		printf("%3d/%3d processes\n", np, NPROC);
E 5
I 5
		printf("%3d/%3d processes\n", np, nproc);
E 5
		return;
	}
D 5
	printf("%d/%d processes\n", np, NPROC);
E 5
I 5
	printf("%d/%d processes\n", np, nproc);
E 5
D 2
	printf("   LOC    S    F POIP PRI SIG  UID  SLP TIM  CPU  NI    PGRP   PID   PPID    ADDR   RSS  SRSS SIZE   WCHAN    LINK   TEXTP CLKT\n");
E 2
I 2
D 33
	printf("   LOC    S    F POIP PRI      SIG  UID SLP TIM  CPU  NI   PGRP    PID   PPID    ADDR   RSS SRSS SIZE    WCHAN    LINK   TEXTP CLKT\n");
E 33
I 33
	printf("   LOC    S    F POIP PRI      SIG  UID SLP TIM  CPU  NI   PGRP    PID   PPID    ADDR   RSS SRSS SIZE    WCHAN    LINK   TEXTP\n");
E 33
E 2
D 5
	for (loc=nl[SPROC].n_value,pp=xproc; pp<&xproc[NPROC]; pp++,loc+=sizeof(xproc[0])) {
E 5
I 5
	for (pp=xproc; pp<&xproc[nproc]; pp++) {
E 5
		if (pp->p_stat==0 && allflg==0)
			continue;
D 5
		printf("%8x", loc);
E 5
I 5
		printf("%8x", aproc + (pp - xproc));
E 5
		printf(" %2d", pp->p_stat);
		printf(" %4x", pp->p_flag & 0xffff);
		printf(" %4d", pp->p_poip);
		printf(" %3d", pp->p_pri);
D 2
		printf(" %4x", pp->p_sig);
E 2
I 2
		printf(" %8x", pp->p_sig);
E 2
		printf(" %4d", pp->p_uid);
		printf(" %3d", pp->p_slptime);
		printf(" %3d", pp->p_time);
		printf(" %4d", pp->p_cpu&0377);
		printf(" %3d", pp->p_nice);
		printf(" %6d", pp->p_pgrp);
		printf(" %6d", pp->p_pid);
		printf(" %6d", pp->p_ppid);
		if (kflg)
			pp->p_addr = (struct pte *)clear((int)pp->p_addr);
D 33
		lseek(fc, (long)(Usrptma+btokmx(pp->p_addr)), 0);
		read(fc, &apte, sizeof(apte));
		printf(" %8x", ctob(apte.pg_pfnum+1) - sizeof(struct pte) * UPAGES);
E 33
I 33
		if (pp->p_flag & SLOAD) {
			lseek(fc, (long)pp->p_addr, 0);
			read(fc, &apte, sizeof(apte));
			printf(" %8x", apte.pg_pfnum);
		} else
			printf(" %8x", pp->p_swaddr);
E 33
		printf(" %4x", pp->p_rssize);
		printf(" %4x", pp->p_swrss);
		printf(" %5x", pp->p_dsize+pp->p_ssize);
		printf(" %7x", clear(pp->p_wchan));
		printf(" %7x", clear(pp->p_link));
		printf(" %7x", clear(pp->p_textp));
D 19
		printf("    %u", pp->p_clktim);
E 19
		printf("\n");
	}
I 40
	free(xproc);
E 40
}

I 36
static char mesg[] =
" # RAW CAN OUT     MODE     ADDR DEL COL     STATE  PGRP DISC\n";
static int ttyspace = 128;
static struct tty *tty;

E 36
dotty()
{
D 13
	struct tty dz_tty[64];
E 13
I 13
D 32
	struct tty dz_tty[128];
E 13
	int ndz;
E 32
I 32
D 36
	struct tty *tty;
	int ntty, ttyspace = 128;
E 32
	register struct tty *tp;
I 32
	extern char *malloc(), *realloc();
E 32
D 30
	register char *mesg;
E 30
I 30
	static char mesg[] =
	" # RAW CAN OUT     MODE     ADDR DEL COL     STATE  PGRP DISC\n";
E 36
I 36
	extern char *malloc();
E 36
E 30

I 32
	if ((tty = (struct tty *)malloc(ttyspace * sizeof(*tty))) == 0) {
		printf("pstat: out of memory\n");
		return;
	}
E 32
I 21
D 22
	mesg = " # RAW CAN OUT     MODE     ADDR DEL COL STATE     PGRP DISC\n";
E 22
E 21
	printf("1 cons\n");
I 9
	if (kflg)
D 42
		nl[SKL].n_value = clear(nl[SKL].n_value);
E 9
	lseek(fc, (long)nl[SKL].n_value, 0);
E 42
I 42
		nl[SCONS].n_value = clear(nl[SCONS].n_value);
	lseek(fc, (long)nl[SCONS].n_value, 0);
E 42
D 32
	read(fc, dz_tty, sizeof(dz_tty[0]));
E 32
I 32
	read(fc, tty, sizeof(*tty));
E 32
I 22
D 30
	mesg = " # RAW CAN OUT   MODE    ADDR   DEL COL  STATE   PGRP DISC\n";
E 30
E 22
D 21
	mesg = " # RAW CAN OUT   MODE    ADDR   DEL COL  STATE   PGRP DISC\n";
E 21
	printf(mesg);
D 32
	ttyprt(&dz_tty[0], 0);
E 32
I 32
	ttyprt(&tty[0], 0);
I 42
#ifdef vax
I 46
	if (nl[SNQD].n_type != 0) 
		doqdss();
E 46
E 42
E 32
D 3
	if (nl[SNDZ].n_type == -1)
E 3
I 3
D 36
	if (nl[SNDZ].n_type == 0)
E 3
		goto dh;
I 9
	if (kflg) {
		nl[SNDZ].n_value = clear(nl[SNDZ].n_value);
		nl[SDZ].n_value = clear(nl[SDZ].n_value);
	}
E 9
	lseek(fc, (long)nl[SNDZ].n_value, 0);
D 32
	read(fc, &ndz, sizeof(ndz));
	printf("%d dz lines\n", ndz);
E 32
I 32
	read(fc, &ntty, sizeof(ntty));
	printf("%d dz lines\n", ntty);
	if (ntty > ttyspace) {
		ttyspace = ntty;
		if ((tty = (struct tty *)realloc(tty, ttyspace * sizeof(*tty))) == 0) {
			printf("pstat: out of memory\n");
			return;
		}
	}
E 32
	lseek(fc, (long)nl[SDZ].n_value, 0);
D 13
	read(fc, dz_tty, sizeof(dz_tty));
E 13
I 13
D 32
	read(fc, dz_tty, ndz * sizeof (struct tty));
E 32
I 32
	read(fc, tty, ntty * sizeof (struct tty));
E 32
I 30
	printf(mesg);
E 30
I 21
D 22
	printf(mesg);
E 22
E 21
E 13
D 32
	for (tp = dz_tty; tp < &dz_tty[ndz]; tp++)
		ttyprt(tp, tp - dz_tty);
E 32
I 32
	for (tp = tty; tp < &tty[ntty]; tp++)
		ttyprt(tp, tp - tty);
E 32
dh:
D 3
	if (nl[SNDH].n_type == -1)
E 3
I 3
	if (nl[SNDH].n_type == 0)
E 3
D 12
		return;
E 12
I 12
D 21
		goto pty;
E 21
I 21
D 22
		goto dmf;
E 22
I 22
D 28
		goto pty;
E 28
I 28
		goto dmf;
E 28
E 22
E 21
E 12
I 9
	if (kflg) {
		nl[SNDH].n_value = clear(nl[SNDH].n_value);
		nl[SDH].n_value = clear(nl[SDH].n_value);
	}
E 9
	lseek(fc, (long)nl[SNDH].n_value, 0);
D 32
	read(fc, &ndz, sizeof(ndz));
	printf("%d dh lines\n", ndz);
E 32
I 32
	read(fc, &ntty, sizeof(ntty));
	printf("%d dh lines\n", ntty);
	if (ntty > ttyspace) {
		ttyspace = ntty;
		if ((tty = (struct tty *)realloc(tty, ttyspace * sizeof(*tty))) == 0) {
			printf("pstat: out of memory\n");
			return;
		}
	}
E 32
	lseek(fc, (long)nl[SDH].n_value, 0);
D 13
	read(fc, dz_tty, sizeof(dz_tty));
E 13
I 13
D 32
	read(fc, dz_tty, ndz * sizeof(struct tty));
E 32
I 32
	read(fc, tty, ntty * sizeof(struct tty));
E 32
I 30
	printf(mesg);
E 30
I 21
D 22
	printf(mesg);
E 22
E 21
E 13
D 32
	for (tp = dz_tty; tp < &dz_tty[ndz]; tp++)
		ttyprt(tp, tp - dz_tty);
E 32
I 32
	for (tp = tty; tp < &tty[ntty]; tp++)
		ttyprt(tp, tp - tty);
E 32
I 28
dmf:
	if (nl[SNDMF].n_type == 0)
		goto pty;
	if (kflg) {
		nl[SNDMF].n_value = clear(nl[SNDMF].n_value);
		nl[SDMF].n_value = clear(nl[SDMF].n_value);
	}
	lseek(fc, (long)nl[SNDMF].n_value, 0);
D 32
	read(fc, &ndz, sizeof(ndz));
	printf("%d dmf lines\n", ndz);
E 32
I 32
	read(fc, &ntty, sizeof(ntty));
	printf("%d dmf lines\n", ntty);
	if (ntty > ttyspace) {
		ttyspace = ntty;
		if ((tty = (struct tty *)realloc(tty, ttyspace * sizeof(*tty))) == 0) {
			printf("pstat: out of memory\n");
			return;
		}
	}
E 32
	lseek(fc, (long)nl[SDMF].n_value, 0);
D 32
	read(fc, dz_tty, ndz * sizeof(struct tty));
E 32
I 32
	read(fc, tty, ntty * sizeof(struct tty));
E 32
I 30
	printf(mesg);
E 30
D 32
	for (tp = dz_tty; tp < &dz_tty[ndz]; tp++)
		ttyprt(tp, tp - dz_tty);
E 32
I 32
	for (tp = tty; tp < &tty[ntty]; tp++)
		ttyprt(tp, tp - tty);
E 32
E 28
I 21
D 22
dmf:
	if (nl[SNDMF].n_type == 0)
		goto pty;
	if (kflg) {
		nl[SNDMF].n_value = clear(nl[SNDMF].n_value);
		nl[SDMF].n_value = clear(nl[SDMF].n_value);
	}
	lseek(fc, (long)nl[SNDMF].n_value, 0);
	read(fc, &ndz, sizeof(ndz));
	printf("%d dmf lines\n", ndz);
	lseek(fc, (long)nl[SDMF].n_value, 0);
	read(fc, dz_tty, ndz * sizeof(struct tty));
	printf(mesg);
	for (tp = dz_tty; tp < &dz_tty[ndz]; tp++)
		ttyprt(tp, tp - dz_tty);
E 22
E 21
I 12
pty:
	if (nl[SPTY].n_type == 0)
E 36
I 36
	if (nl[SNDZ].n_type != 0)
		dottytype("dz", SDZ, SNDZ);
	if (nl[SNDH].n_type != 0)
		dottytype("dh", SDH, SNDH);
	if (nl[SNDMF].n_type != 0)
		dottytype("dmf", SDMF, SNDMF);
	if (nl[SNDHU].n_type != 0)
		dottytype("dhu", SDHU, SNDHU);
I 38
	if (nl[SNDMZ].n_type != 0)
		dottytype("dmz", SDMZ, SNDMZ);
I 42
#endif
#ifdef tahoe
	if (nl[SNVX].n_type != 0)
		dottytype("vx", SVX, SNVX);
I 51
	if (nl[SNMP].n_type != 0)
		dottytype("mp", SMP, SNMP);
E 51
#endif
E 42
E 38
	if (nl[SNPTY].n_type != 0)
		dottytype("pty", SPTY, SNPTY);
}

I 46
/* 
 * Special case the qdss because there are 4 tty structs per qdss 
 * and only the first of each is used as a tty.  
 */
#ifdef vax
doqdss()
{
	int nqd;
	register struct tty *tp;

	if (kflg) {
		nl[SNQD].n_value = clear(nl[SNQD].n_value);
		nl[SQD].n_value = clear(nl[SQD].n_value);
	}
	lseek(fc, (long)nl[SNQD].n_value, 0);
	read(fc, &nqd, sizeof(nqd));
	printf("%d qd\n", nqd);
	lseek(fc, (long)nl[SQD].n_value, 0);
	read(fc, tty, nqd * sizeof(struct tty) * 4);
	printf(mesg);
	for (tp = tty; tp < &tty[nqd * 4]; tp += 4)
		ttyprt(tp, tp - tty);
}
#endif

E 46
dottytype(name, type, number)
char *name;
{
	int ntty;
	register struct tty *tp;
	extern char *realloc();

D 46
	if (tty == (struct tty *)0)
E 46
I 46
	if (tty == (struct tty *)0) 
E 46
E 36
D 28
		goto pty;
E 28
I 28
		return;
E 28
	if (kflg) {
D 36
		nl[SPTY].n_value = clear(nl[SPTY].n_value);
I 32
		nl[SNPTY].n_value = clear(nl[SNPTY].n_value);
E 36
I 36
		nl[number].n_value = clear(nl[number].n_value);
		nl[type].n_value = clear(nl[type].n_value);
E 36
E 32
	}
D 13
	printf("16 pty lines\n");
E 13
I 13
D 32
	printf("32 pty lines\n");
E 32
I 32
D 36
	lseek(fc, (long)nl[SNPTY].n_value, 0);
E 36
I 36
	lseek(fc, (long)nl[number].n_value, 0);
E 36
	read(fc, &ntty, sizeof(ntty));
D 36
	printf("%d pty lines\n", ntty);
E 36
I 36
	printf("%d %s lines\n", ntty, name);
E 36
	if (ntty > ttyspace) {
		ttyspace = ntty;
		if ((tty = (struct tty *)realloc(tty, ttyspace * sizeof(*tty))) == 0) {
			printf("pstat: out of memory\n");
			return;
		}
	}
E 32
E 13
D 36
	lseek(fc, (long)nl[SPTY].n_value, 0);
D 13
	read(fc, dz_tty, sizeof(dz_tty));
	for (tp = dz_tty; tp < &dz_tty[16]; tp++)
E 13
I 13
D 32
	read(fc, dz_tty, 32*sizeof(struct tty));
E 32
I 32
	read(fc, tty, ntty*sizeof(struct tty));
E 36
I 36
	lseek(fc, (long)nl[type].n_value, 0);
	read(fc, tty, ntty * sizeof(struct tty));
E 36
E 32
I 30
	printf(mesg);
E 30
I 21
D 22
	printf(mesg);
E 22
E 21
D 32
	for (tp = dz_tty; tp < &dz_tty[32]; tp++)
E 13
		ttyprt(tp, tp - dz_tty);
E 32
I 32
	for (tp = tty; tp < &tty[ntty]; tp++)
		ttyprt(tp, tp - tty);
E 32
E 12
}

ttyprt(atp, line)
struct tty *atp;
{
	register struct tty *tp;

	printf("%2d", line);
	tp = atp;
	switch (tp->t_line) {

I 12
D 42
/*
E 42
I 42
#ifdef notdef
E 42
E 12
	case NETLDISC:
		if (tp->t_rec)
			printf("%4d%4d", 0, tp->t_inbuf);
		else
			printf("%4d%4d", tp->t_inbuf, 0);
		break;
I 12
D 42
*/
E 42
I 42
#endif
E 42
E 12

	default:
D 30
		printf("%4d", tp->t_rawq.c_cc);
		printf("%4d", tp->t_canq.c_cc);
E 30
I 30
		printf("%4d%4d", tp->t_rawq.c_cc, tp->t_canq.c_cc);
E 30
	}
D 30
	printf("%4d", tp->t_outq.c_cc);
D 19
	printf("%8.1o", tp->t_flags);
E 19
I 19
D 21
	printf("%8.1x", tp->t_flags);
E 21
I 21
D 22
	printf(" %8.1x", tp->t_flags);
E 22
I 22
	printf("%8.1x", tp->t_flags);
E 22
E 21
E 19
	printf(" %8.1x", tp->t_addr);
D 21
	printf("%3d", tp->t_delct);
E 21
I 21
D 22
	printf(" %3d", tp->t_delct);
E 22
I 22
	printf("%3d", tp->t_delct);
E 22
E 21
	printf("%4d ", tp->t_col);
E 30
I 30
	printf("%4d %8x %8x%4d%4d", tp->t_outq.c_cc, tp->t_flags,
		tp->t_addr, tp->t_delct, tp->t_col);
E 30
D 12
	putf(tp->t_state&TIMEOUT, 'T');
	putf(tp->t_state&WOPEN, 'W');
	putf(tp->t_state&ISOPEN, 'O');
	putf(tp->t_state&CARR_ON, 'C');
	putf(tp->t_state&BUSY, 'B');
	putf(tp->t_state&ASLEEP, 'A');
	putf(tp->t_state&XCLUDE, 'X');
E 12
I 12
	putf(tp->t_state&TS_TIMEOUT, 'T');
	putf(tp->t_state&TS_WOPEN, 'W');
	putf(tp->t_state&TS_ISOPEN, 'O');
I 30
	putf(tp->t_state&TS_FLUSH, 'F');
E 30
	putf(tp->t_state&TS_CARR_ON, 'C');
	putf(tp->t_state&TS_BUSY, 'B');
	putf(tp->t_state&TS_ASLEEP, 'A');
	putf(tp->t_state&TS_XCLUDE, 'X');
I 30
	putf(tp->t_state&TS_TTSTOP, 'S');
E 30
E 12
D 19
/*
E 19
D 12
	putf(tp->t_state&HUPCLS, 'H');
E 12
I 12
	putf(tp->t_state&TS_HUPCLS, 'H');
E 12
D 19
 */
E 19
	printf("%6d", tp->t_pgrp);
	switch (tp->t_line) {

I 30
	case OTTYDISC:
		printf("\n");
		break;

E 30
	case NTTYDISC:
D 30
		printf(" ntty");
E 30
I 30
		printf(" ntty\n");
E 30
		break;

	case NETLDISC:
D 30
		printf(" net");
E 30
I 30
D 39
		printf(" net\n");
E 39
I 39
		printf(" berknet\n");
E 39
E 30
		break;
I 30

	case TABLDISC:
		printf(" tab\n");
D 39
		break;

	case NTABLDISC:
		printf(" ntab\n");
E 39
		break;

I 47
	case SLIPDISC:
		printf(" slip\n");
		break;

E 47
	default:
		printf(" %d\n", tp->t_line);
E 30
	}
D 30
	printf("\n");
E 30
}

dousr()
{
	struct user U;
	register i, j, *ip;
I 29
	register struct nameidata *nd = &U.u_nd;
E 29

D 33
	/* This wins only if PAGSIZ > sizeof (struct user) */
	lseek(fc, ubase * NBPG, 0);
	read(fc, &U, sizeof(U));
E 33
I 33
	/* This wins only if CLBYTES >= sizeof (struct user) */
	lseek(fm, ubase * NBPG, 0);
	read(fm, &U, sizeof(U));
E 33
	printf("pcb");
	ip = (int *)&U.u_pcb;
	while (ip < &U.u_arg[0]) {
		if ((ip - (int *)&U.u_pcb) % 4 == 0)
			printf("\t");
		printf("%x ", *ip++);
		if ((ip - (int *)&U.u_pcb) % 4 == 0)
			printf("\n");
	}
	if ((ip - (int *)&U.u_pcb) % 4 != 0)
		printf("\n");
D 33
	printf("arg\t");
	for (i=0; i<5; i++)
		printf(" %.1x", U.u_arg[i]);
	printf("\n");
	for (i=0; i<sizeof(label_t)/sizeof(int); i++) {
E 33
I 33
	printf("arg");
	for (i=0; i<sizeof(U.u_arg)/sizeof(U.u_arg[0]); i++) {
E 33
		if (i%5==0)
			printf("\t");
D 19
		printf("%9.1x", U.u_ssav[i]);
E 19
I 19
D 33
		printf("%9.1x", U.u_ssave.val[i]);
E 33
I 33
		printf(" %.1x", U.u_arg[i]);
E 33
E 19
		if (i%5==4)
			printf("\n");
	}
	if (i%5)
		printf("\n");
D 29
	printf("segflg\t%d\nerror %d\n", U.u_segflg, U.u_error);
E 29
I 29
	printf("segflg\t%d\nerror %d\n", nd->ni_segflg, U.u_error);
E 29
	printf("uids\t%d,%d,%d,%d\n", U.u_uid,U.u_gid,U.u_ruid,U.u_rgid);
	printf("procp\t%.1x\n", U.u_procp);
	printf("ap\t%.1x\n", U.u_ap);
	printf("r_val?\t%.1x %.1x\n", U.u_r.r_val1, U.u_r.r_val2);
D 29
	printf("base, count, offset %.1x %.1x %ld\n", U.u_base,
		U.u_count, U.u_offset);
E 29
I 29
	printf("base, count, offset %.1x %.1x %ld\n", nd->ni_base,
		nd->ni_count, nd->ni_offset);
E 29
	printf("cdir rdir %.1x %.1x\n", U.u_cdir, U.u_rdir);
D 15
	printf("dbuf %.14s\n", U.u_dbuf);
E 15
D 29
	printf("dirp %.1x\n", U.u_dirp);
	printf("dent %d %.14s\n", U.u_dent.d_ino, U.u_dent.d_name);
	printf("pdir %.1o\n", U.u_pdir);
E 29
I 29
	printf("dirp %.1x\n", nd->ni_dirp);
	printf("dent %d %.14s\n", nd->ni_dent.d_ino, nd->ni_dent.d_name);
	printf("pdir %.1o\n", nd->ni_pdir);
E 29
D 33
	printf("file\t");
	for (i=0; i<10; i++)
E 33
I 33
	printf("file");
	for (i=0; i<NOFILE; i++) {
		if (i % 8 == 0)
			printf("\t");
E 33
		printf("%9.1x", U.u_ofile[i]);
D 33
	printf("\n\t");
	for (i=10; i<NOFILE; i++)
		printf("%9.1x", U.u_ofile[i]);
	printf("\n");
	printf("pofile\t");
	for (i=0; i<10; i++)
E 33
I 33
		if (i % 8 == 7)
			printf("\n");
	}
	if (i % 8)
		printf("\n");
	printf("pofile");
	for (i=0; i<NOFILE; i++) {
		if (i % 8 == 0)
			printf("\t");
E 33
		printf("%9.1x", U.u_pofile[i]);
D 33
	printf("\n\t");
	for (i=10; i<NOFILE; i++)
		printf("%9.1x", U.u_pofile[i]);
	printf("\n");
E 33
I 33
		if (i % 8 == 7)
			printf("\n");
	}
	if (i % 8)
		printf("\n");
E 33
D 19
	printf("ssav");
E 19
I 19
	printf("ssave");
E 19
	for (i=0; i<sizeof(label_t)/sizeof(int); i++) {
		if (i%5==0)
			printf("\t");
D 19
		printf("%9.1x", U.u_ssav[i]);
E 19
I 19
		printf("%9.1x", U.u_ssave.val[i]);
E 19
		if (i%5==4)
			printf("\n");
	}
	if (i%5)
		printf("\n");
D 33
	printf("sigs\t");
	for (i=0; i<NSIG; i++)
E 33
I 33
	printf("sigs");
	for (i=0; i<NSIG; i++) {
		if (i % 8 == 0)
			printf("\t");
E 33
		printf("%.1x ", U.u_signal[i]);
D 33
	printf("\n");
E 33
I 33
		if (i % 8 == 7)
			printf("\n");
	}
	if (i % 8)
		printf("\n");
E 33
D 6
	printf("cfcode\t%.1x\n", U.u_cfcode);
E 6
I 6
	printf("code\t%.1x\n", U.u_code);
E 6
	printf("ar0\t%.1x\n", U.u_ar0);
D 45
	printf("prof\t%X %X %X %X\n", U.u_prof.pr_base, U.u_prof.pr_size,
E 45
I 45
	printf("prof\t%x %x %x %x\n", U.u_prof.pr_base, U.u_prof.pr_size,
E 45
	    U.u_prof.pr_off, U.u_prof.pr_scale);
	printf("\neosys\t%d\n", U.u_eosys);
D 19
	printf("sep\t%d\n", U.u_sep);
E 19
	printf("ttyp\t%.1x\n", U.u_ttyp);
	printf("ttyd\t%d,%d\n", major(U.u_ttyd), minor(U.u_ttyd));
D 29
	printf("exdata\t");
	ip = (int *)&U.u_exdata;
	for (i = 0; i < 8; i++)
		printf("%.1D ", *ip++);
	printf("\n");
E 29
	printf("comm %.14s\n", U.u_comm);
D 45
	printf("start\t%D\n", U.u_start);
	printf("acflag\t%D\n", U.u_acflag);
D 19
	printf("fpflag\t%D\n", U.u_fpflag);
E 19
	printf("cmask\t%D\n", U.u_cmask);
E 45
I 45
	printf("start\t%ld\n", U.u_start.tv_sec);
	printf("acflag\t%ld\n", U.u_acflag);
	printf("cmask\t%ld\n", U.u_cmask);
E 45
	printf("sizes\t%.1x %.1x %.1x\n", U.u_tsize, U.u_dsize, U.u_ssize);
D 19
	printf("vm\t");
	ip = (int *)&U.u_vm;
	for (i = 0; i < sizeof(U.u_vm)/sizeof(int); i++)
E 19
I 19
	printf("ru\t");
	ip = (int *)&U.u_ru;
	for (i = 0; i < sizeof(U.u_ru)/sizeof(int); i++)
E 19
D 45
		printf("%D ", ip[i]);
E 45
I 45
		printf("%ld ", ip[i]);
E 45
	printf("\n");
D 19
	ip = (int *)&U.u_cvm;
	printf("cvm\t");
	for (i = 0; i < sizeof(U.u_vm)/sizeof(int); i++)
E 19
I 19
	ip = (int *)&U.u_cru;
	printf("cru\t");
	for (i = 0; i < sizeof(U.u_cru)/sizeof(int); i++)
E 19
D 45
		printf("%D ", ip[i]);
E 45
I 45
		printf("%ld ", ip[i]);
E 45
	printf("\n");
D 42
/*
E 42
I 42
#ifdef notdef
E 42
	i =  U.u_stack - &U;
	while (U[++i] == 0);
	i &= ~07;
	while (i < 512) {
		printf("%x ", 0140000+2*i);
		for (j=0; j<8; j++)
			printf("%9x", U[i++]);
		printf("\n");
	}
D 42
*/
E 42
I 42
#endif
E 42
}

oatoi(s)
char *s;
{
	register v;

	v = 0;
	while (*s)
		v = (v<<3) + *s++ - '0';
	return(v);
}

D 5
dofil()
E 5
I 5
dofile()
E 5
{
D 5
	struct file xfile[NFILE];
E 5
I 5
	int nfile;
	struct file *xfile, *afile;
E 5
	register struct file *fp;
	register nf;
	int loc;
I 18
D 23
	static char *dtypes[] = {
		"???", "kernel", "fsys", "file", "dir", "bdev",
		"cdev", "proc", "socket", "domain", "tty"
	};
E 23
I 23
	static char *dtypes[] = { "???", "inode", "socket" };
E 23
E 18

	nf = 0;
D 5
	lseek(fc, (long)nl[SFIL].n_value, 0);
	read(fc, xfile, sizeof(xfile));
	for (fp=xfile; fp < &xfile[NFILE]; fp++)
E 5
I 5
D 48
	nfile = getw(nl[SNFILE].n_value);
E 48
I 48
	nfile = getword(nl[SNFILE].n_value);
E 48
	xfile = (struct file *)calloc(nfile, sizeof (struct file));
D 35
	lseek(fc, (int)(afile = (struct file *)getw(nl[SFIL].n_value)), 0);
E 35
I 35
D 48
	afile = (struct file *)getw(nl[SFIL].n_value);
E 48
I 48
	afile = (struct file *)getword(nl[SFIL].n_value);
E 48
D 40
	lseek(fc, (mkphys((int)afile)), 0);
E 40
I 40
	if (nfile < 0 || nfile > 10000) {
		fprintf(stderr, "number of files is preposterous (%d)\n",
			nfile);
		return;
	}
	if (xfile == NULL) {
		fprintf(stderr, "can't allocate memory for file table\n");
		return;
	}
	lseek(fc, mkphys((off_t)afile), 0);
E 40
E 35
	read(fc, xfile, nfile * sizeof (struct file));
	for (fp=xfile; fp < &xfile[nfile]; fp++)
E 5
		if (fp->f_count)
			nf++;
	if (totflg) {
D 5
		printf("%3d/%3d files\n", nf, NFILE);
E 5
I 5
		printf("%3d/%3d files\n", nf, nfile);
E 5
		return;
	}
D 5
	printf("%d/%d open files\n", nf, NFILE);
E 5
I 5
	printf("%d/%d open files\n", nf, nfile);
E 5
D 12
	printf("   LOC   FLG  CNT   INO    OFFS\n");
E 12
I 12
D 18
	printf("   LOC   FLG  CNT   INO    OFFS|SOCK\n");
E 18
I 18
D 23
	printf("   LOC   TYPE    FLG  CNT   INO    OFFS|SOCK\n");
E 23
I 23
D 24
	printf("   LOC   TYPE    FLG  CNT  MSG    DATA    OFFSET\n");
E 24
I 24
	printf("   LOC   TYPE    FLG     CNT  MSG    DATA    OFFSET\n");
E 24
E 23
E 18
E 12
D 5
	for (fp=xfile,loc=nl[SFIL].n_value; fp < &xfile[NFILE]; fp++,loc+=sizeof(xfile[0])) {
E 5
I 5
D 16
	for (fp=xfile,loc=nl[SFIL].n_value; fp < &xfile[nfile]; fp++,loc+=sizeof(xfile[0])) {
E 16
I 16
	for (fp=xfile,loc=(int)afile; fp < &xfile[nfile]; fp++,loc+=sizeof(xfile[0])) {
E 16
E 5
		if (fp->f_count==0)
			continue;
		printf("%8x ", loc);
I 18
D 23
		if (fp->f_type <= DTYPE_TERMINAL)
E 23
I 23
		if (fp->f_type <= DTYPE_SOCKET)
E 23
			printf("%-8.8s", dtypes[fp->f_type]);
		else
D 44
			printf("8d", fp->f_type);
E 44
I 44
			printf("%8d", fp->f_type);
E 44
E 18
		putf(fp->f_flag&FREAD, 'R');
		putf(fp->f_flag&FWRITE, 'W');
D 12
		putf(fp->f_flag&FPIPE, 'P');
E 12
I 12
D 18
		putf(fp->f_flag&FSOCKET, 'S');
E 18
I 18
		putf(fp->f_flag&FAPPEND, 'A');
I 24
		putf(fp->f_flag&FSHLOCK, 'S');
		putf(fp->f_flag&FEXLOCK, 'X');
		putf(fp->f_flag&FASYNC, 'I');
E 24
E 18
E 12
D 23
		printf("%4d", mask(fp->f_count));
		printf("%9.1x", fp->f_inode);
D 12
		printf("  %ld\n", fp->f_un.f_offset);
E 12
I 12
D 18
		if (fp->f_flag&FSOCKET)
E 18
I 18
		if (fp->f_type == DTYPE_SOCKET)
E 18
			printf("  %x\n", fp->f_socket);
E 23
I 23
		printf("  %3d", mask(fp->f_count));
		printf("  %3d", mask(fp->f_msgcount));
		printf("  %8.1x", fp->f_data);
		if (fp->f_offset < 0)
			printf("  %x\n", fp->f_offset);
E 23
		else
			printf("  %ld\n", fp->f_offset);
E 12
	}
I 40
	free(xfile);
E 40
}

I 22
int dmmin, dmmax, nswdev;

E 22
doswap()
{
D 5
	struct proc proc[NPROC];
	struct text xtext[NTEXT];
	struct map swapmap[SMAPSIZ];
E 5
I 5
	struct proc *proc;
	int nproc;
	struct text *xtext;
	int ntext;
	struct map *swapmap;
	int nswapmap;
I 27
	struct swdevt *swdevt, *sw;
E 27
E 5
	register struct proc *pp;
D 22
	int nswap, used, tused, free;
E 22
I 22
	int nswap, used, tused, free, waste;
	int db, sb;
E 22
D 6
	register struct map *mp;
E 6
I 6
	register struct mapent *me;
E 6
	register struct text *xp;
I 22
	int i, j;
I 49
	long rmalloc();
E 49
E 22

D 5
	lseek(fc, (long)nl[SPROC].n_value, 0);
	read(fc, proc, sizeof(proc));
	lseek(fc, (long)nl[SWAPMAP].n_value, 0);
	read(fc, swapmap, sizeof(swapmap));
	lseek(fc, (long)nl[SNSWAP].n_value, 0);
	read(fc, &nswap, sizeof(nswap));
E 5
I 5
D 48
	nproc = getw(nl[SNPROC].n_value);
D 40
	proc = (struct proc *)calloc(nproc, sizeof (struct proc));
E 40
D 27
	lseek(fc, getw(nl[SPROC].n_value), 0);
	read(fc, proc, nproc * sizeof (struct proc));
E 27
I 27
	ntext = getw(nl[SNTEXT].n_value);
E 48
I 48
	nproc = getword(nl[SNPROC].n_value);
	ntext = getword(nl[SNTEXT].n_value);
E 48
I 40
	if (nproc < 0 || nproc > 10000 || ntext < 0 || ntext > 10000) {
		fprintf(stderr, "number of procs/texts is preposterous (%d, %d)\n",
			nproc, ntext);
		return;
	}
	proc = (struct proc *)calloc(nproc, sizeof (struct proc));
	if (proc == NULL) {
		fprintf(stderr, "can't allocate memory for proc table\n");
		exit(1);
	}
E 40
	xtext = (struct text *)calloc(ntext, sizeof (struct text));
I 40
	if (xtext == NULL) {
		fprintf(stderr, "can't allocate memory for text table\n");
		exit(1);
	}
E 40
E 27
D 48
	nswapmap = getw(nl[SNSWAPMAP].n_value);
E 48
I 48
	nswapmap = getword(nl[SNSWAPMAP].n_value);
E 48
	swapmap = (struct map *)calloc(nswapmap, sizeof (struct map));
I 40
	if (swapmap == NULL) {
		fprintf(stderr, "can't allocate memory for swapmap\n");
		exit(1);
	}
E 40
I 27
D 48
	nswdev = getw(nl[SNSWDEV].n_value);
E 48
I 48
	nswdev = getword(nl[SNSWDEV].n_value);
E 48
	swdevt = (struct swdevt *)calloc(nswdev, sizeof (struct swdevt));
D 40
	lseek(fc, nl[SSWDEVT].n_value, L_SET);
E 40
I 40
	if (swdevt == NULL) {
		fprintf(stderr, "can't allocate memory for swdevt table\n");
		exit(1);
	}
	lseek(fc, mkphys((off_t)nl[SSWDEVT].n_value), L_SET);
E 40
	read(fc, swdevt, nswdev * sizeof (struct swdevt));
D 40
	lseek(fc, getw(nl[SPROC].n_value), 0);
E 40
I 40
D 48
	lseek(fc, mkphys((off_t)getw(nl[SPROC].n_value)), 0);
E 48
I 48
	lseek(fc, mkphys((off_t)getword(nl[SPROC].n_value)), 0);
E 48
E 40
	read(fc, proc, nproc * sizeof (struct proc));
D 40
	lseek(fc, getw(nl[STEXT].n_value), 0);
E 40
I 40
D 48
	lseek(fc, mkphys((off_t)getw(nl[STEXT].n_value)), 0);
E 48
I 48
	lseek(fc, mkphys((off_t)getword(nl[STEXT].n_value)), 0);
E 48
E 40
	read(fc, xtext, ntext * sizeof (struct text));
E 27
D 40
	lseek(fc, getw(nl[SWAPMAP].n_value), 0);
E 40
I 40
D 48
	lseek(fc, mkphys((off_t)getw(nl[SWAPMAP].n_value)), 0);
E 48
I 48
	lseek(fc, mkphys((off_t)getword(nl[SWAPMAP].n_value)), 0);
E 48
E 40
	read(fc, swapmap, nswapmap * sizeof (struct map));
I 25
	swapmap->m_name = "swap";
I 26
	swapmap->m_limit = (struct mapent *)&swapmap[nswapmap];
E 26
E 25
D 27
	nswap = getw(nl[SNSWAP].n_value);
E 27
I 22
D 48
	dmmin = getw(nl[SDMMIN].n_value);
	dmmax = getw(nl[SDMMAX].n_value);
E 48
I 48
	dmmin = getword(nl[SDMMIN].n_value);
	dmmax = getword(nl[SDMMAX].n_value);
E 48
D 27
	nswdev = getw(nl[SNSWDEV].n_value);
E 27
I 27
	nswap = 0;
	for (sw = swdevt; sw < &swdevt[nswdev]; sw++)
D 41
		nswap += sw->sw_nblks,
E 41
I 41
		if (sw->sw_freed)
			nswap += sw->sw_nblks;
E 41
E 27
E 22
E 5
	free = 0;
D 5
	for (mp = swapmap; mp < &swapmap[SMAPSIZ]; mp++)
E 5
I 5
D 6
	for (mp = swapmap; mp < &swapmap[nswapmap]; mp++)
E 5
		free += mp->m_size;
E 6
I 6
	for (me = (struct mapent *)(swapmap+1);
	    me < (struct mapent *)&swapmap[nswapmap]; me++)
		free += me->m_size;
E 6
D 5
	lseek(fc, (long)nl[STEXT].n_value, 0);
	read(fc, xtext, sizeof(xtext));
E 5
I 5
D 27
	ntext = getw(nl[SNTEXT].n_value);
	xtext = (struct text *)calloc(ntext, sizeof (struct text));
	lseek(fc, getw(nl[STEXT].n_value), 0);
	read(fc, xtext, ntext * sizeof (struct text));
E 27
E 5
	tused = 0;
D 5
	for (xp = xtext; xp < &xtext[NTEXT]; xp++)
E 5
I 5
	for (xp = xtext; xp < &xtext[ntext]; xp++)
E 5
D 27
		if (xp->x_iptr!=NULL)
			tused += xdsize(xp);
E 27
I 27
		if (xp->x_iptr!=NULL) {
D 31
			tused += ctod(xp->x_size);
E 31
I 31
			tused += ctod(clrnd(xp->x_size));
E 31
			if (xp->x_flag & XPAGI)
D 31
				tused += ctod(ctopt(xp->x_size));
E 31
I 31
				tused += ctod(clrnd(ctopt(xp->x_size)));
E 31
		}
E 27
	used = tused;
I 22
	waste = 0;
E 22
D 5
	for (pp = proc; pp < &proc[NPROC]; pp++) {
E 5
I 5
	for (pp = proc; pp < &proc[nproc]; pp++) {
E 5
		if (pp->p_stat == 0 || pp->p_stat == SZOMB)
			continue;
		if (pp->p_flag & SSYS)
			continue;
D 22
		used += up(pp->p_dsize) + up(pp->p_ssize);
E 22
I 22
D 27
		db = ctod(pp->p_dsize);
		sb = ctod(pp->p_ssize);
		waste -= db + sb;
		db = up(db);
		sb = up(sb);
		used += db + sb;
		waste += db + sb;
E 27
I 27
		db = ctod(pp->p_dsize), sb = up(db);
		used += sb;
		waste += sb - db;
		db = ctod(pp->p_ssize), sb = up(db);
		used += sb;
		waste += sb - db;
E 27
E 22
		if ((pp->p_flag&SLOAD) == 0)
D 32
			used += vusize(pp);
E 32
I 32
			used += ctod(vusize(pp));
E 32
	}
D 6
	/* a DMMAX block goes to argmap */
E 6
I 6
D 27
	/* a DMMAX/2 block goes to argmap */
E 27
E 6
	if (totflg) {
D 22
		printf("%3d/%3d 00k swap\n", used/2/100, (used+free)/2/100);
E 22
I 22
D 27
		printf("%3d/%3d 00k swap\n", used/100, (used+free)/100);
E 27
I 27
#define	btok(x)	((x) / (1024 / DEV_BSIZE))
		printf("%3d/%3d 00k swap\n",
		    btok(used/100), btok((used+free)/100));
E 27
E 22
		return;
	}
D 22
	printf("%d used (%d text), %d free, %d missing\n",
D 6
	    used/2, tused/2, free/2, (nswap - DMMAX - (used + free))/2);
E 6
I 6
	    used/2, tused/2, free/2, (nswap - DMMAX/2 - (used + free))/2);
E 22
I 22
D 27
	printf("%d used (%d text), %d free, %d wasted, %d missing\n",
	    used, tused, free, waste, (nswap - dmmax/2 - (used + free)));
E 27
I 27
	printf("%dk used (%dk text), %dk free, %dk wasted, %dk missing\n",
	    btok(used), btok(tused), btok(free), btok(waste),
/* a dmmax/2 block goes to argmap */
	    btok(nswap - dmmax/2 - (used + free)));
E 27
	printf("avail: ");
	for (i = dmmax; i >= dmmin; i /= 2) {
		j = 0;
		while (rmalloc(swapmap, i) != 0)
			j++;
D 27
		if (j) printf("%d*%d ", j, i);
E 27
I 27
		if (j) printf("%d*%dk ", j, btok(i));
E 27
	}
D 27
	printf("\n");
E 27
I 27
	free = 0;
	for (me = (struct mapent *)(swapmap+1);
	    me < (struct mapent *)&swapmap[nswapmap]; me++)
		free += me->m_size;
	printf("%d*1k\n", btok(free));
E 27
E 22
E 6
}

up(size)
	register int size;
{
	register int i, block;

	i = 0;
D 22
	block = DMMIN;
E 22
I 22
	block = dmmin;
E 22
	while (i < size) {
		i += block;
D 22
		if (block < DMMAX)
E 22
I 22
		if (block < dmmax)
E 22
			block *= 2;
	}
	return (i);
}

I 27
/*
 * Compute number of pages to be allocated to the u. area
 * and data and stack area page tables, which are stored on the
 * disk immediately after the u. area.
 */
E 27
vusize(p)
D 25
struct proc *p;
E 25
I 25
D 27
	struct proc *p;
E 27
I 27
	register struct proc *p;
E 27
E 25
{
	register int tsz = p->p_tsize / NPTEPG;

D 22
	return (clrnd(UPAGES + clrnd(ctopt(p->p_tsize+p->p_dsize+p->p_ssize+UPAGES)) - tsz));
E 22
I 22
D 27
	return (ctod(clrnd(UPAGES +
	    clrnd(ctopt(p->p_tsize+p->p_dsize+p->p_ssize+UPAGES)) - tsz)));
E 22
}

xdsize(xp)
D 25
struct text *xp;
E 25
I 25
	struct text *xp;
E 25
{

	if (xp->x_flag & XPAGI)
D 22
		return (clrnd(xp->x_size + ctopt(xp->x_size)));
	return (xp->x_size);
E 22
I 22
		return (ctod(clrnd(xp->x_size + ctopt(xp->x_size))));
	return (ctod(xp->x_size));
E 27
I 27
	/*
	 * We do not need page table space on the disk for page
	 * table pages wholly containing text. 
	 */
	return (clrnd(UPAGES +
	    clrnd(ctopt(p->p_tsize+p->p_dsize+p->p_ssize+UPAGES)) - tsz));
E 27
}

/*
 * Allocate 'size' units from the given
 * map. Return the base of the allocated space.
 * In a map, the addresses are increasing and the
 * list is terminated by a 0 size.
 *
 * Algorithm is first-fit.
 *
 * This routine knows about the interleaving of the swapmap
 * and handles that.
 */
long
rmalloc(mp, size)
	register struct map *mp;
	long size;
{
	register struct mapent *ep = (struct mapent *)(mp+1);
	register int addr;
	register struct mapent *bp;
	swblk_t first, rest;

	if (size <= 0 || size > dmmax)
		return (0);
	/*
	 * Search for a piece of the resource map which has enough
	 * free space to accomodate the request.
	 */
	for (bp = ep; bp->m_size; bp++) {
		if (bp->m_size >= size) {
			/*
			 * If allocating from swapmap,
			 * then have to respect interleaving
			 * boundaries.
			 */
			if (nswdev > 1 &&
			    (first = dmmax - bp->m_addr%dmmax) < bp->m_size) {
				if (bp->m_size - first < size)
					continue;
				addr = bp->m_addr + first;
				rest = bp->m_size - first - size;
				bp->m_size = first;
				if (rest)
					rmfree(mp, rest, addr+size);
				return (addr);
			}
			/*
			 * Allocate from the map.
			 * If there is no space left of the piece
			 * we allocated from, move the rest of
			 * the pieces to the left.
			 */
			addr = bp->m_addr;
			bp->m_addr += size;
			if ((bp->m_size -= size) == 0) {
				do {
					bp++;
					(bp-1)->m_addr = bp->m_addr;
				} while ((bp-1)->m_size = bp->m_size);
			}
			if (addr % CLSIZE)
				return (0);
			return (addr);
		}
	}
	return (0);
}

/*
 * Free the previously allocated space at addr
 * of size units into the specified map.
 * Sort addr into map and combine on
 * one or both ends if possible.
 */
rmfree(mp, size, addr)
	struct map *mp;
	long size, addr;
{
	struct mapent *firstbp;
	register struct mapent *bp;
	register int t;

	/*
	 * Both address and size must be
	 * positive, or the protocol has broken down.
	 */
	if (addr <= 0 || size <= 0)
		goto badrmfree;
	/*
	 * Locate the piece of the map which starts after the
	 * returned space (or the end of the map).
	 */
	firstbp = bp = (struct mapent *)(mp + 1);
	for (; bp->m_addr <= addr && bp->m_size != 0; bp++)
		continue;
	/*
	 * If the piece on the left abuts us,
	 * then we should combine with it.
	 */
	if (bp > firstbp && (bp-1)->m_addr+(bp-1)->m_size >= addr) {
		/*
		 * Check no overlap (internal error).
		 */
		if ((bp-1)->m_addr+(bp-1)->m_size > addr)
			goto badrmfree;
		/*
		 * Add into piece on the left by increasing its size.
		 */
		(bp-1)->m_size += size;
		/*
		 * If the combined piece abuts the piece on
		 * the right now, compress it in also,
		 * by shifting the remaining pieces of the map over.
		 */
		if (bp->m_addr && addr+size >= bp->m_addr) {
			if (addr+size > bp->m_addr)
				goto badrmfree;
			(bp-1)->m_size += bp->m_size;
			while (bp->m_size) {
				bp++;
				(bp-1)->m_addr = bp->m_addr;
				(bp-1)->m_size = bp->m_size;
			}
		}
		goto done;
	}
	/*
	 * Don't abut on the left, check for abutting on
	 * the right.
	 */
	if (addr+size >= bp->m_addr && bp->m_size) {
		if (addr+size > bp->m_addr)
			goto badrmfree;
		bp->m_addr -= size;
		bp->m_size += size;
		goto done;
	}
	/*
	 * Don't abut at all.  Make a new entry
	 * and check for map overflow.
	 */
	do {
		t = bp->m_addr;
		bp->m_addr = addr;
		addr = t;
		t = bp->m_size;
		bp->m_size = size;
		bp++;
	} while (size = t);
	/*
	 * Segment at bp is to be the delimiter;
	 * If there is not room for it 
	 * then the table is too full
	 * and we must discard something.
	 */
	if (bp+1 > mp->m_limit) {
		/*
		 * Back bp up to last available segment.
		 * which contains a segment already and must
		 * be made into the delimiter.
		 * Discard second to last entry,
		 * since it is presumably smaller than the last
		 * and move the last entry back one.
		 */
		bp--;
		printf("%s: rmap ovflo, lost [%d,%d)\n", mp->m_name,
		    (bp-1)->m_addr, (bp-1)->m_addr+(bp-1)->m_size);
		bp[-1] = bp[0];
		bp[0].m_size = bp[0].m_addr = 0;
	}
done:
	return;
badrmfree:
	printf("bad rmfree\n");
I 35
}
/*
 * "addr"  is a kern virt addr and does not correspond
 * To a phys addr after zipping out the high bit..
 * since it was valloc'd in the kernel.
 *
 * We return the phys addr by simulating kernel vm (/dev/kmem)
 * when we are reading a crash dump.
 */
I 40
off_t
E 40
mkphys(addr)
I 40
	off_t addr;
E 40
{
D 40
	register o;
E 40
I 40
	register off_t o;
E 40

	if (!kflg)
		return(addr);
I 43
	addr = clear(addr);
E 43
	o = addr & PGOFSET;
	addr >>= PGSHIFT;
	addr &= PG_PFNUM;
	addr *=  NBPW;
D 48
	addr = getw(nl[SYSMAP].n_value + addr);
E 48
I 48
	addr = getword(nl[SYSMAP].n_value + addr);
E 48
	addr = ((addr & PG_PFNUM) << PGSHIFT) | o;
	return(addr);
E 35
E 22
I 4
}
D 18

E 18
D 12
dompx()
{
	register int i;
	struct chan chans[NCHANS];
	struct schan schans[NPORTS];

	lseek(fc, (long)nl[SCHANS].n_value, 0);
	read(fc, chans, sizeof chans);
	lseek(fc, (long)nl[SSCHANS].n_value, 0);
	read(fc, schans, sizeof schans);

	printf("CHAN  FLAGS            INDEX     LINE  GROUP     FILE      TTYP      CTLX      PGRP    OTTYP     OLINE  DATQ      CTLY\n");
	for (i = 0; i < NCHANS; i++) {
		printf("%3d   ", i);
		putf(chans[i].c_flags&INUSE, 'I');
		putf(chans[i].c_flags&SIOCTL, 'S');
		putf(chans[i].c_flags&XGRP, 'X');
		putf(chans[i].c_flags&YGRP, 'Y');
		putf(chans[i].c_flags&WCLOSE, 'W');
		putf(chans[i].c_flags&ISGRP, 'i');
		putf(chans[i].c_flags&BLOCK, 'B');
		putf(chans[i].c_flags&EOTMARK, 'E');
		putf(chans[i].c_flags&SIGBLK, 's');
		putf(chans[i].c_flags&BLKMSG, 'b');
		putf(chans[i].c_flags&ENAMSG, 'e');
		putf(chans[i].c_flags&WFLUSH, 'w');
		putf(chans[i].c_flags&NMBUF, 'N');
		putf(chans[i].c_flags&PORT, 'P');
		putf(chans[i].c_flags&ALT, 'A');
		putf(chans[i].c_flags&FBLOCK, 'F');
		printf("%8x  ", chans[i].c_index);
		printf("%3d   ", chans[i].c_line);
		printf("%8x  ", chans[i].c_group);
		printf("%8x  ", chans[i].c_fy);
		printf("%8x  ", chans[i].c_ttyp);
		printf("%8x  ", chans[i].c_ctlx);
		printf("%6d  ", chans[i].c_pgrp);
		printf("%8x  ", chans[i].c_ottyp);
		printf("%3d   ", chans[i].c_oline);
		printf("%8x  ", chans[i].cx.datq);
		printf("%8x\n", chans[i].c_ctly);
	}

	printf("\nCHAN  FLAGS            INDEX     LINE  GROUP     FILE      TTYP      CTLX      PGRP\n");
	for (i = 0; i < NPORTS; i++) {
		printf("%3d  ", i);
		putf(schans[i].c_flags&INUSE, 'I');
		putf(schans[i].c_flags&SIOCTL, 'S');
		putf(schans[i].c_flags&XGRP, 'X');
		putf(schans[i].c_flags&YGRP, 'Y');
		putf(schans[i].c_flags&WCLOSE, 'W');
		putf(schans[i].c_flags&ISGRP, 'i');
		putf(schans[i].c_flags&BLOCK, 'B');
		putf(schans[i].c_flags&EOTMARK, 'E');
		putf(schans[i].c_flags&SIGBLK, 's');
		putf(schans[i].c_flags&BLKMSG, 'b');
		putf(schans[i].c_flags&ENAMSG, 'e');
		putf(schans[i].c_flags&WFLUSH, 'w');
		putf(schans[i].c_flags&NMBUF, 'N');
		putf(schans[i].c_flags&PORT, 'P');
		putf(schans[i].c_flags&ALT, 'A');
		putf(schans[i].c_flags&FBLOCK, 'F');
		printf("%8x  ", schans[i].c_index);
		printf("%3d   ", schans[i].c_line);
		printf("%8x  ", schans[i].c_group);
		printf("%8x  ", schans[i].c_fy);
		printf("%8x  ", schans[i].c_ttyp);
		printf("%8x  ", schans[i].c_ctlx);
		printf("%6d\n", schans[i].c_pgrp);
	}
}

dogroup()
{
	register int i, j;
	struct group *groups[NGROUPS];
	struct group g;

	lseek(fc, (long)nl[SGROUP].n_value, 0);
	read(fc, groups, sizeof groups);
	printf("GROUP STATE      INDEX     ROT  *GROUP    *INODE    *FILE     ROTM  DATQ\n");
	for (i = 0; i < NGROUPS; i++) {
		if (groups[i] == 0)
			continue;
		lseek(fc, (long) groups[i], 0);
		read(fc, &g, sizeof g);
		printf("%3d   ", i);
		printf("%8x  ", g.g_state);
		printf("%8x  ", g.g_index);
		printf("%3d  ", g.g_rot);
		printf("%8x  ", g.g_group);
		printf("%8x  ", g.g_inode);
		printf("%8x  ", g.g_file);
		printf("%3d   ", g.g_rotmask);
		printf("%3d\n", g.g_datq);
	}
E 4
}
E 12
E 1
