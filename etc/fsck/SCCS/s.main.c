h16948
s 00055/00005/00338
d D 5.8 88/05/03 19:30:38 mckusick 80 79
c in preen mode, summarize file systems that must be checked manually
e
s 00004/00000/00339
d D 5.7 88/05/01 23:36:56 mckusick 79 78
c add -c flag (convert dynamic cylinder group format back to static format)
e
s 00012/00010/00327
d D 5.6 87/02/26 17:44:49 karels 78 77
c update disk labels to ioctl's; check the file the user specified!;
c don't try to check "." if a named file doesn't exist;
c don't check spare constants in superblock against alternate;
c make the "TRASHED VALUES" message understandable
e
s 00005/00004/00332
d D 5.5 86/11/24 20:58:08 mckusick 77 76
c verify that we are checking the root file system (from conrad@cgl.ucsf.edu)
c bug report 4.3BSD/etc/20
e
s 00009/00000/00327
d D 5.4 86/03/05 17:12:40 mckusick 76 75
c free dup list and zero link count entries as they are used
c reinitialize dup list head and zero link count head to empty after each fs check
e
s 00004/00002/00323
d D 5.3 85/10/24 19:24:05 mckusick 75 73
c add fragmentation statistics
e
s 00004/00002/00323
d R 5.3 85/10/23 15:03:01 mckusick 74 73
c add fragmentation statistics
e
s 00008/00002/00317
d D 5.2 85/09/10 20:14:03 karels 73 72
c allow a single sigquit to force exit(2) after completing checks
c if preening
e
s 00014/00002/00305
d D 5.1 85/06/05 08:55:35 dist 72 71
c Add copyright
e
s 00007/00000/00300
d D 3.5 85/06/02 17:40:12 mckusick 71 70
c when debug is set, list remaining duplicate blocks
e
s 00001/00001/00299
d D 3.4 85/05/31 20:08:17 mckusick 70 69
c dynamically allocate the duplicate block table
e
s 00035/00017/00265
d D 3.3 85/02/08 19:15:12 mckusick 69 68
c merge passes 5 and 6 into a single pass
e
s 00194/00000/00088
d D 3.2 85/02/07 17:51:42 mckusick 68 67
c code reorganization and cleanup
e
s 00003/02200/00085
d D 3.1 84/03/31 20:58:59 mckusick 67 66
c break up into managable pieces
e
s 00007/00008/02278
d D 2.32 84/01/23 18:32:47 mckusick 66 65
c overwrite ".." if first entry, "." if second entry in directory
e
s 00004/00003/02282
d D 2.31 84/01/23 14:56:45 mckusick 65 64
c must apply beginning of directory check at each resync point (Tom Lyons)
e
s 00005/00000/02280
d D 2.30 83/09/19 18:06:19 mckusick 64 63
c arbitrarily cut off searching around orphaned directory loops
e
s 00019/00013/02261
d D 2.29 83/09/13 18:41:36 mckusick 63 62
c lint; ask about all possible directory fixes instead of just once per directory
e
s 00014/00008/02260
d D 2.28 83/09/12 15:03:17 mckusick 62 61
c give more complete information about pathnames while linking up files
e
s 00685/00446/01583
d D 2.27 83/09/11 20:03:31 mckusick 61 60
c cleanup to get rid of global variables; robust directory checking:
c first entry is '.' and has correct inumber,
c second entry is '..' and has parent inumber,
c no additional '.' or '..' entries,
c more information about errors and consistancy checks of entries
e
s 00003/00003/02026
d D 2.26 83/07/06 22:23:36 sam 60 59
c leave sockets alone (please?)
e
s 00012/00014/02017
d D 2.25 83/07/02 23:50:07 root 59 58
c must check block root device to insure consistency
e
s 00005/00002/02026
d D 2.24 83/05/25 23:03:50 sam 58 57
c quotas
e
s 00013/00002/02015
d D 2.23 83/05/22 13:00:09 mckusick 57 56
c accounting and fix-up for i_blocks (from kre)
e
s 00005/00000/02012
d D 2.22 83/03/08 18:19:36 mckusick 56 55
c check for excessively long pathnames
e
s 00016/00006/01996
d D 2.21 83/02/24 14:30:24 mckusick 55 54
c remove any socket inodes left lying around
c attach bad blocks marked by badsect
e
s 00005/00011/01997
d D 2.20 83/01/19 13:16:43 mckusick 54 53
c zero link count table increased 50 => 500; corrupted directories now pfatal.
e
s 00001/00001/02007
d D 2.19 83/01/09 00:51:04 mckusick 53 51
c blkcpy() becomes bcopy()
e
s 00001/00001/02007
d R 2.19 83/01/09 00:39:48 mckusick 52 51
c blkcpy becomes bcopy
e
s 00001/00001/02007
d D 2.18 82/12/03 19:43:43 mckusick 51 50
c use raw, not cooked device, for root file system
e
s 00001/00030/02007
d D 2.17 82/11/15 13:05:05 mckusick 50 47
i 49 48
c merge in branch 2.11.1
e
s 00052/00022/02077
d D 2.11.1.2 82/11/14 19:40:15 mckusick 49 48
c correctly reset cylinder count in last cylinder group 
c make duplicate/bad blocks in bit maps non-fatal with -p (since can reconstruct)
c more debug info; clear out unused portions of block maps
e
s 00000/00000/02099
d D 2.11.1.1 82/11/14 19:33:18 mckusick 48 42
c branch-place-holder
e
s 00258/00232/01733
d D 2.16 82/10/13 23:29:19 root 47 46
c speedups and cleanups
e
s 00008/00063/01957
d D 2.15 82/07/31 13:01:20 root 46 45
c more routines common with kernel
e
s 00023/00027/01997
d D 2.14 82/07/31 02:14:29 root 45 44
c remove some macros
e
s 00390/00458/01634
d D 2.13 82/07/31 02:07:24 root 44 43
c split up check()
e
s 00001/00008/02091
d D 2.12 82/07/30 15:18:26 mckusick 43 42
c when preening, dup blocks in bit maps are  ok.
e
s 00003/00002/02096
d D 2.11 82/07/25 17:22:45 mckusick 42 41
c add consistency check of last entry in a directory
e
s 00017/00007/02081
d D 2.10 82/07/03 19:57:57 kre 41 40
c minor fixes (handle errs on root with -p, and always
c use pfatal/pwarn instead of printf for 1st err & know about -p)
e
s 00008/00003/02080
d D 2.9 82/06/15 13:21:33 mckusick 40 39
c force reboot after fixing the root file system
e
s 00033/00011/02050
d D 2.8 82/06/09 23:27:12 mckusick 39 38
c be more paranoid about checking unallocated blocks in inodes
e
s 00012/00012/02049
d D 2.7 82/05/17 22:47:37 mckusick 38 37
c minor cosmetic changes to directory salvage code
e
s 00061/00032/02000
d D 2.6 82/05/17 22:39:07 mckusick 37 36
c merge in fixes 4.10 to 4.15 of old fsck; fix directory salvage code
e
s 00016/00008/02016
d D 2.5 82/05/07 01:19:01 mckusick 36 35
c fix bug in reading multiple block directories
e
s 00021/00001/02003
d D 2.4 82/04/15 15:30:59 mckusick 35 34
c check for insufficient memory
e
s 00055/00043/01949
d D 2.3 82/04/11 17:21:39 mckusick 34 33
c float the super block, reclaim redundant boot block space
e
s 00021/00010/01971
d D 2.2 82/04/08 14:47:04 mckusick 33 32
c add check of super block cylinder summary information
e
s 00119/00006/01862
d D 2.1 82/04/08 11:41:11 mckusick 32 31
c merge into new kernel
e
s 00001/00001/01867
d D 1.31 82/03/30 14:13:57 mckusick 31 30
c fix bug in directory salvage code
e
s 00003/00002/01865
d D 1.30 82/03/26 23:15:43 mckusick 30 29
c use bread instead of getblk for summary info
e
s 00008/00008/01859
d D 1.29 82/03/25 02:30:54 mckusick 29 28
c update to the current system
e
s 00001/00001/01866
d D 1.28 82/03/23 12:55:29 mckusick 28 27
c compress frag tables
e
s 00002/00005/01865
d D 1.27 82/03/23 01:02:59 mckusick 27 26
c add symbolic links
e
s 00044/00010/01826
d D 1.26 82/03/17 18:28:25 mckusick 26 25
c implement rudimentary reconstruction of directories
e
s 00010/00011/01826
d D 1.25 82/02/25 14:48:00 mckusic 25 24
c use speed-up macros in fs.h
e
s 00015/00011/01822
d D 1.24 82/02/23 19:04:06 mckusic 24 23
c always allocate inodes 0 and 1 when reconstructing cyl group 0
e
s 00005/00021/01828
d D 1.23 82/02/21 16:19:21 mckusic 23 22
c conversion to flexable length directory names
e
s 00076/00051/01773
d D 1.22 82/02/17 01:08:27 mckusic 22 21
c convert to use "library" directory access routines
e
s 00004/00002/01820
d D 1.21 82/01/15 13:46:40 mckusic 21 20
c fix bug in initializing cg_free in makecg()
e
s 00006/00002/01816
d D 1.20 82/01/13 18:34:04 mckusic 20 19
c zero out cg_free for unused portion of last cylinder group
e
s 00038/00028/01780
d D 1.19 82/01/12 22:18:17 mckusic 19 18
c change all macros taking "fs" to have it as their first argument
e
s 00016/00003/01792
d D 1.18 82/01/12 19:34:19 mckusic 18 17
c add cg_ctot to summarize cg_b
e
s 00029/00021/01766
d D 1.17 82/01/10 18:24:23 mckusic 17 16
c fix rotational layout code to work with disks with nsect % bsize != 0
e
s 00006/00005/01781
d D 1.16 82/01/06 23:33:29 mckusic 16 15
c incorporate fs.h -r1.10, and param.h -r1.8 reorganization
e
s 00004/00003/01782
d D 1.15 82/01/06 21:12:08 mckusic 15 14
c skip over inode 1 when checking
e
s 00119/00083/01666
d D 1.14 82/01/05 01:32:36 mckusic 14 13
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00009/00011/01740
d D 1.13 81/11/27 16:37:52 mckusic 13 12
c clean up makecg in preparation for moving it to icheck (-s)
e
s 00004/00003/01747
d D 1.12 81/11/13 16:55:06 mckusic 12 11
c must use struct ostat when statting old file system
e
s 00034/00032/01716
d D 1.11 81/11/07 19:59:31 mckusic 11 10
c edit to incorperate -r1.6 reorganization of fs.h
e
s 00012/00011/01736
d D 1.10 81/11/01 00:57:22 mckusic 10 9
c force directory updates on UNALLOCATED inodes which are removed
e
s 00010/00006/01737
d D 1.9 81/10/29 00:36:44 mckusic 9 8
c put in optimal rotational block allocation
e
s 00002/00000/01741
d D 1.8 81/10/25 17:30:28 mckusic 8 7
c move external decls for tables.o from fs.h to fsck.c
e
s 00001/00001/01740
d D 1.7 81/10/07 18:29:41 mckusic 7 6
c fix unsigned char problem to get FRAG == 8 to work
e
s 00121/00058/01620
d D 1.6 81/10/05 20:45:55 mckusic 6 5
c maintaining and using cg_frsum to do intelligent allocation of FRAGs
e
s 00024/00019/01654
d D 1.5 81/09/22 17:46:13 mckusic 5 4
c allow files and directories to have FRAGS as their final block
e
s 00001/00000/01672
d D 1.4 81/08/29 14:43:55 mckusic 4 3
c add cg_irotor initialization
e
s 00000/00004/01672
d D 1.3 81/08/28 22:47:16 mckusic 3 2
c move bit op macros to param.h
e
s 00001/00004/01675
d D 1.2 81/08/28 21:22:01 mckusic 2 1
c put in new inode structure
e
s 01679/00000/00000
d D 1.1 81/08/26 23:47:37 mckusick 1 0
c date and time created 81/08/26 23:47:37 by mckusick
e
u
U
f b 
t
T
I 72
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 72
I 1
D 36
static	char *sccsid = "%W% (Berkeley) %G%";
E 36
I 36
D 37
static	char *sccsid = "@(#)fsck.c	2.4 (Berkeley) 4/15/82";
E 37
I 37
D 50
static	char sccsid[] = "%W%	(Berkeley)	%G%";
E 50
I 50
D 58
char version[] = "%W%	(Berkeley)	%G%";
E 58
I 58
#ifndef lint
D 67
char version[] = "%W% (Berkeley) %G%";
E 67
I 67
D 72
static char version[] = "%W% (Berkeley) %G%";
E 67
#endif
E 72
I 72
char copyright[] =
D 73
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 73
I 73
"@(#) Copyright (c) 1980 Regents of the University of California.\n\
E 73
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 72
E 58
E 50
E 37
E 36
I 5

E 5
D 67
#include <stdio.h>
#include <ctype.h>
E 67
I 32
D 44
#ifndef SIMFS
E 44
#include <sys/param.h>
D 67
#include <sys/fs.h>
E 67
#include <sys/inode.h>
D 36
#include <ndir.h>
E 36
I 36
D 59
#include <dir.h>
E 59
I 59
D 61
#include <sys/dir.h>
E 61
E 59
E 36
D 44
#else
E 32
#include "../h/param.h"
#include "../h/fs.h"
D 22
#include "../h/dir.h"
E 22
I 22
D 25
#include "../h/ndir.h"
E 25
E 22
D 2
#include "../h/ino.h"
E 2
#include "../h/inode.h"
D 32
#include "../h/stat.h"
I 12
#include "../h/ostat.h"
I 25
#include <ndir.h>
E 32
I 32
#include "../h/ndir.h"
#endif
E 44
D 67
#include <sys/stat.h>
I 61
#include <sys/wait.h>
E 61
E 32
E 25
E 12
#include <fstab.h>
I 61
#define KERNEL
#include <sys/dir.h>
#undef KERNEL
E 67
I 67
#include <sys/fs.h>
I 68
#include <sys/stat.h>
#include <sys/wait.h>
#include <fstab.h>
#include <strings.h>
E 68
#include "fsck.h"
E 67
E 61

I 68
char	*rawname(), *unrawname(), *blockcheck();
D 73
int	catch();
E 73
I 73
int	catch(), catchquit(), voidquit();
int	returntosingle;
E 73
int	(*signal())();

main(argc, argv)
	int	argc;
	char	*argv[];
{
	struct fstab *fsp;
	int pid, passno, anygtr, sumstatus;
	char *name;
I 80
	struct worklist {
		int	pid;		/* pid of child doing the check */
		struct	worklist *next;	/* next in list */
		char	name[MAXMNTLEN];/* name of file system */
	} *listhead = 0, *freelist = 0, *badlist = 0;
	register struct worklist *wp, *pwp;
E 80

	sync();
	while (--argc > 0 && **++argv == '-') {
		switch (*++*argv) {

		case 'p':
			preen++;
			break;

		case 'b':
			if (argv[0][1] != '\0') {
				bflag = atoi(argv[0]+1);
			} else {
				bflag = atoi(*++argv);
				argc--;
			}
			printf("Alternate super block location: %d\n", bflag);
			break;

I 79
		case 'c':
			cvtflag++;
			break;

E 79
		case 'd':
			debug++;
			break;

		case 'n':	/* default no answer flag */
		case 'N':
			nflag++;
			yflag = 0;
			break;

		case 'y':	/* default yes answer flag */
		case 'Y':
			yflag++;
			nflag = 0;
			break;

		default:
			errexit("%c option?\n", **argv);
		}
	}
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		(void)signal(SIGINT, catch);
I 73
	if (preen)
		(void)signal(SIGQUIT, catchquit);
E 73
	if (argc) {
		while (argc-- > 0) {
			hotroot = 0;
D 77
			checkfilesys(*argv++);
E 77
I 77
D 78
			name = blockcheck(*argv++);
			checkfilesys(name);
E 78
I 78
			checkfilesys(*argv++);
E 78
E 77
		}
		exit(0);
	}
	sumstatus = 0;
	passno = 1;
	do {
		anygtr = 0;
		if (setfsent() == 0)
			errexit("Can't open checklist file: %s\n", FSTAB);
		while ((fsp = getfsent()) != 0) {
			if (strcmp(fsp->fs_type, FSTAB_RW) &&
			    strcmp(fsp->fs_type, FSTAB_RO) &&
			    strcmp(fsp->fs_type, FSTAB_RQ))
				continue;
			if (preen == 0 ||
			    passno == 1 && fsp->fs_passno == passno) {
				name = blockcheck(fsp->fs_spec);
				if (name != NULL)
					checkfilesys(name);
				else if (preen)
					exit(8);
			} else if (fsp->fs_passno > passno) {
				anygtr = 1;
			} else if (fsp->fs_passno == passno) {
I 80
				name = blockcheck(fsp->fs_spec);
				if (name == NULL) {
					pwarn("BAD DISK NAME %s\n",
						fsp->fs_spec);
					sumstatus |= 8;
					continue;
				}
E 80
				pid = fork();
				if (pid < 0) {
					perror("fork");
					exit(8);
				}
				if (pid == 0) {
I 73
					(void)signal(SIGQUIT, voidquit);
E 73
D 80
					name = blockcheck(fsp->fs_spec);
					if (name == NULL)
						exit(8);
E 80
					checkfilesys(name);
					exit(0);
I 80
				} else {
					if (freelist == 0) {
						wp = (struct worklist *) malloc
						    (sizeof(struct worklist));
					} else {
						wp = freelist;
						freelist = wp->next;
					}
					wp->next = listhead;
					listhead = wp;
					wp->pid = pid;
					sprintf(wp->name, "%s (%s)", name,
					    fsp->fs_file);
E 80
				}
			}
		}
		if (preen) {
			union wait status;
D 80
			while (wait(&status) != -1)
E 80
I 80
			while ((pid = wait(&status)) != -1) {
E 80
				sumstatus |= status.w_retcode;
I 80
				pwp = 0;
				for (wp = listhead; wp; pwp = wp, wp = wp->next)
					if (wp->pid == pid)
						break;
				if (wp == 0) {
					printf("Unknown pid %d\n", pid);
					continue;
				}
				if (pwp == 0)
					listhead = wp->next;
				else
					pwp->next = wp->next;
				if (status.w_retcode != 0) {
					wp->next = badlist;
					badlist = wp;
				} else {
					wp->next = freelist;
					freelist = wp;
				}
			}
E 80
		}
		passno++;
	} while (anygtr);
D 80
	if (sumstatus)
E 80
I 80
	if (sumstatus) {
		if (badlist == 0)
			exit(8);
		printf("THE FOLLOWING FILE SYSTEM%s HAD AN %s\n\t",
			badlist->next ? "S" : "", "UNEXPECTED INCONSISTENCY:");
		for (wp = badlist; wp; wp = wp->next)
			printf("%s%s", wp->name, wp->next ? ", " : "\n");
E 80
		exit(8);
I 80
	}
E 80
	(void)endfsent();
I 73
	if (returntosingle)
		exit(2);
E 73
	exit(0);
}

E 68
I 47
D 67
/* RECONSTRUCT ONLY BAD CG IN PASS 6 */

E 47
typedef	int	(*SIG_TYP)();

D 14
#define	NDIRECT	(BSIZE/sizeof(struct direct))
#define	SPERB	(BSIZE/sizeof(short))
E 14
I 14
D 22
#define	NDIRECT(fs)	((fs)->fs_bsize / sizeof(struct direct))
#define	MAXNDIRECT	(MAXBSIZE / sizeof(struct direct))
E 22
D 16
#define	MAXINOPB	(MAXBSIZE / sizeof(struct dinode))
#define	MAXNINDIR	(MAXBSIZE / sizeof(daddr_t))
E 16
I 16
#define	MAXNINDIR	(MAXBSIZE / sizeof (daddr_t))
#define	MAXINOPB	(MAXBSIZE / sizeof (struct dinode))
E 16
#define	SPERB		(MAXBSIZE / sizeof(short))
I 61
#define MINDIRSIZE	(sizeof (struct dirtemplate))
E 61
E 14

#define	MAXDUP	10		/* limit on dup blks (per inode) */
#define	MAXBAD	10		/* limit on bad blks (per inode) */

#define	USTATE	0		/* inode not allocated */
#define	FSTATE	01		/* inode is file */
#define	DSTATE	02		/* inode is directory */
#define	CLEAR	03		/* inode is to be cleared */

typedef struct dinode	DINODE;
typedef struct direct	DIRECT;

#define	ALLOC	((dp->di_mode & IFMT) != 0)
D 22
#define	DIR	((dp->di_mode & IFMT) == IFDIR)
E 22
I 22
#define	DIRCT	((dp->di_mode & IFMT) == IFDIR)
E 22
#define	REG	((dp->di_mode & IFMT) == IFREG)
#define	BLK	((dp->di_mode & IFMT) == IFBLK)
#define	CHR	((dp->di_mode & IFMT) == IFCHR)
I 37
#define	LNK	((dp->di_mode & IFMT) == IFLNK)
I 55
#define	SOCK	((dp->di_mode & IFMT) == IFSOCK)
#define	BADBLK	((dp->di_mode & IFMT) == IFMT)
E 55
E 37
D 27
#define	MPC	((dp->di_mode & IFMT) == IFMPC)
#define	MPB	((dp->di_mode & IFMT) == IFMPB)
#define	SPECIAL	(BLK || CHR || MPC || MPB)
E 27
I 27
#define	SPECIAL	(BLK || CHR)
E 27

D 6
daddr_t	startib;		/* blk num of first in raw area */
struct	dinode ibase[MAXIPG];
int	niblk;
E 6
I 6
D 61
ino_t	startinum;		/* blk num of first in raw area */
E 6

E 61
struct bufarea {
	struct bufarea	*b_next;		/* must be first */
	daddr_t	b_bno;
	int	b_size;
	union {
D 14
		char	b_buf[BSIZE];		/* buffer space */
E 14
I 14
		char	b_buf[MAXBSIZE];	/* buffer space */
E 14
		short	b_lnks[SPERB];		/* link counts */
D 14
		daddr_t	b_indir[NINDIR];	/* indirect block */
E 14
I 14
		daddr_t	b_indir[MAXNINDIR];	/* indirect block */
E 14
		struct	fs b_fs;		/* super block */
		struct	cg b_cg;		/* cylinder group */
D 14
		struct dinode b_dinode[INOPB];	/* inode block */
		DIRECT b_dir[NDIRECT];		/* directory */
E 14
I 14
		struct dinode b_dinode[MAXINOPB]; /* inode block */
D 22
		DIRECT b_dir[MAXNDIRECT];	/* directory */
E 22
E 14
	} b_un;
	char	b_dirty;
};

typedef struct bufarea BUFAREA;

BUFAREA	inoblk;			/* inode blocks */
BUFAREA	fileblk;		/* other blks in filesys */
BUFAREA	sblk;			/* file system superblock */
D 61
BUFAREA	cgblk;
E 61
I 61
BUFAREA	cgblk;			/* cylinder group blocks */
E 61

#define	initbarea(x)	(x)->b_dirty = 0;(x)->b_bno = (daddr_t)-1
#define	dirty(x)	(x)->b_dirty = 1
#define	inodirty()	inoblk.b_dirty = 1
#define	sbdirty()	sblk.b_dirty = 1
#define	cgdirty()	cgblk.b_dirty = 1

#define	dirblk		fileblk.b_un
#define	sblock		sblk.b_un.b_fs
#define	cgrp		cgblk.b_un.b_cg

struct filecntl {
	int	rfdes;
	int	wfdes;
	int	mod;
} dfile;			/* file descriptors for filesys */

I 61
struct inodesc {
	char id_type;		/* type of descriptor, DATA or ADDR */
	int (*id_func)();	/* function to be applied to blocks of inode */
	ino_t id_number;	/* inode number described */
	ino_t id_parent;	/* for DATA nodes, their parent */
	daddr_t id_blkno;	/* current block number being examined */
	int id_numfrags;	/* number of frags contained in block */
	long id_filesize;	/* for DATA nodes, the size of the directory */
	int id_loc;		/* for DATA nodes, current location in dir */
	int id_entryno;		/* for DATA nodes, current entry number */
	DIRECT *id_dirp;	/* for data nodes, ptr to current entry */
	enum {DONTKNOW, NOFIX, FIX} id_fix; /* policy on fixing errors */
};
/* file types */
#define	DATA	1
#define	ADDR	2


E 61
#define	DUPTBLSIZE	100	/* num of dup blocks to remember */
daddr_t	duplist[DUPTBLSIZE];	/* dup block table */
daddr_t	*enddup;		/* next entry in dup table */
daddr_t	*muldup;		/* multiple dups part of table */

D 37
#define	MAXLNCNT	20	/* num zero link cnts to remember */
E 37
I 37
D 54
#define	MAXLNCNT	50	/* num zero link cnts to remember */
E 54
I 54
#define	MAXLNCNT	500	/* num zero link cnts to remember */
E 54
E 37
ino_t	badlncnt[MAXLNCNT];	/* table of inos with zero link cnts */
ino_t	*badlnp;		/* next entry in table */

char	rawflg;
char	nflag;			/* assume a no response */
char	yflag;			/* assume a yes response */
int	bflag;			/* location of alternate super block */
I 19
int	debug;			/* output debugging info */
E 19
char	preen;			/* just fix normal inconsistencies */
char	rplyflag;		/* any questions asked? */
char	hotroot;		/* checking root device */
char	fixcg;			/* corrupted free list bit maps */

D 29
char	*blkmap;		/* ptr to primary blk allocation map */
E 29
I 29
char	*blockmap;		/* ptr to primary blk allocation map */
E 29
char	*freemap;		/* ptr to secondary blk allocation map */
char	*statemap;		/* ptr to inode state table */
short	*lncntp;		/* ptr to link count table */

D 61
char	*pathp;			/* pointer to pathname position */
char	*thisname;		/* ptr to current pathname component */
E 61
char	*srchname;		/* name being searched for in dir */
D 22
char	pathname[200];
E 22
I 22
D 61
char	pathname[BUFSIZ];
E 61
I 61
char	pathname[BUFSIZ];	/* current pathname */
char	*pathp;			/* pointer to pathname position */
E 61
I 56
char	*endpathname = &pathname[BUFSIZ - 2];
E 56
E 22

char	*lfname = "lost+found";

D 61
ino_t	inum;			/* inode we are currently working on */
I 36
ino_t	dnum;			/* directory inode currently being worked on */
E 61
E 36
ino_t	imax;			/* number of inodes */
D 61
ino_t	parentdir;		/* i number of parent directory */
E 61
ino_t	lastino;		/* hiwater mark of inodes */
ino_t	lfdir;			/* lost & found directory */
D 61
ino_t	orphan;			/* orphaned inode */
E 61

D 61
off_t	filsize;		/* num blks seen in file */
E 61
off_t	maxblk;			/* largest logical blk in file */
D 29
off_t	bmapsz;			/* num chars in blkmap */
E 29
I 29
off_t	bmapsz;			/* num chars in blockmap */
E 29

daddr_t	n_ffree;		/* number of small free blocks */
daddr_t	n_bfree;		/* number of large free blocks */
daddr_t	n_blks;			/* number of blocks used */
daddr_t	n_files;		/* number of files seen */
daddr_t	n_index;
daddr_t	n_bad;
daddr_t	fmax;			/* number of blocks in the volume */

daddr_t	badblk;
daddr_t	dupblk;

int	inosumbad;
int	offsumbad;
I 6
int	frsumbad;
I 33
int	sbsumbad;
E 33
E 6

D 13
#define	howmany(x, y)	(((x)+((y)-1))/(y))
#define	roundup(x, y)	((((x)+((y)-1))/(y))*(y))
E 13
#define	zapino(x)	(*(x) = zino)
struct	dinode zino;

D 3
#define	setbit(a, i)	((a)[(i)/NBBY] |= 1<<((i)%NBBY))
#define	clrbit(a, i)	((a)[(i)/NBBY] &= ~(1<<((i)%NBBY)))
#define	isset(a, i)	((a)[(i)/NBBY] & (1<<((i)%NBBY)))

E 3
D 45
#define	setlncnt(x)	(lncntp[inum] = x)
#define	getlncnt()	(lncntp[inum])
#define	declncnt()	(--lncntp[inum])

E 45
D 29
#define	setbmap(x)	setbit(blkmap, x)
#define	getbmap(x)	isset(blkmap, x)
#define	clrbmap(x)	clrbit(blkmap, x)
E 29
I 29
#define	setbmap(x)	setbit(blockmap, x)
#define	getbmap(x)	isset(blockmap, x)
#define	clrbmap(x)	clrbit(blockmap, x)
E 29

#define	setfmap(x)	setbit(freemap, x)
#define	getfmap(x)	isset(freemap, x)
#define	clrfmap(x)	clrbit(freemap, x)

D 45
#define	setstate(x)	(statemap[inum] = x)
#define	getstate()	statemap[inum]

E 45
D 61
#define	DATA	1
#define	ADDR	0

#define	ALTERD	010
E 61
I 61
#define	ALTERED	010
E 61
#define	KEEPON	04
#define	SKIP	02
#define	STOP	01

int	(*signal())();
long	lseek();
time_t	time();
DINODE	*ginode();
I 61
DIRECT	*fsck_readdir();
E 61
BUFAREA	*getblk();
D 61
int	dirscan();
int	findino();
E 61
int	catch();
D 61
int	mkentry();
int	chgdd();
D 44
int	pass1(), pass1b(), pass2(), pass4(), pass5();
E 44
I 44
int	pass1check(), pass1bcheck(), pass2check(), pass4check(), pass5check();
E 44
int	(*pfunc)();
char	*rawname(), *rindex(), *unrawname();
E 61
I 61
int	findino(), mkentry(), chgdd();
int	pass1check(), pass1bcheck(), pass2check(), pass4check();
char	*rawname(), *unrawname();
char	*calloc(), *strcpy(), *strcat(), *rindex();
E 61
I 8
extern int inside[], around[];
D 14
extern unsigned char fragtbl[];
E 14
I 14
extern unsigned char *fragtbl[];
E 14
E 8

char	*devname;

main(argc, argv)
D 10
int	argc;
char	*argv[];
E 10
I 10
	int	argc;
	char	*argv[];
E 10
{
	struct fstab *fsp;
	int pid, passno, anygtr, sumstatus;

	sync();
	while (--argc > 0 && **++argv == '-') {
		switch (*++*argv) {

		case 'p':
			preen++;
			break;

		case 'b':
D 61
			bflag = atoi(argv[0]+1);
E 61
I 61
			if (argv[0][1] != '\0') {
				bflag = atoi(argv[0]+1);
			} else {
				bflag = atoi(*++argv);
				argc--;
			}
E 61
			printf("Alternate super block location: %d\n", bflag);
			break;

I 19
		case 'd':
			debug++;
			break;

E 19
		case 'n':	/* default no answer flag */
		case 'N':
			nflag++;
			yflag = 0;
			break;

		case 'y':	/* default yes answer flag */
		case 'Y':
			yflag++;
			nflag = 0;
			break;

		default:
			errexit("%c option?\n", **argv);
		}
	}
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
D 61
		signal(SIGINT, catch);
E 61
I 61
		(void)signal(SIGINT, catch);
E 61
	if (argc) {
		while (argc-- > 0) {
			hotroot = 0;
D 44
			check(*argv++);
E 44
I 44
			checkfilesys(*argv++);
E 44
		}
		exit(0);
	}
	sumstatus = 0;
	passno = 1;
	do {
		anygtr = 0;
		if (setfsent() == 0)
			errexit("Can't open checklist file: %s\n", FSTAB);
		while ((fsp = getfsent()) != 0) {
			if (strcmp(fsp->fs_type, FSTAB_RW) &&
D 58
			    strcmp(fsp->fs_type, FSTAB_RO))
E 58
I 58
			    strcmp(fsp->fs_type, FSTAB_RO) &&
			    strcmp(fsp->fs_type, FSTAB_RQ))
E 58
				continue;
			if (preen == 0 ||
			    passno == 1 && fsp->fs_passno == passno) {
				if (blockcheck(fsp->fs_spec) == 0 && preen)
					exit(8);
			} else if (fsp->fs_passno > passno)
				anygtr = 1;
			else if (fsp->fs_passno == passno) {
				pid = fork();
				if (pid < 0) {
					perror("fork");
					exit(8);
				}
				if (pid == 0)
					if (blockcheck(fsp->fs_spec)==0)
						exit(8);
					else
						exit(0);
			}
		}
		if (preen) {
D 61
			int status;
E 61
I 61
			union wait status;
E 61
			while (wait(&status) != -1)
D 61
				sumstatus |= status;
E 61
I 61
				sumstatus |= status.w_retcode;
E 61
		}
		passno++;
	} while (anygtr);
	if (sumstatus)
		exit(8);
D 61
	endfsent();
E 61
I 61
	(void)endfsent();
E 61
	exit(0);
}

blockcheck(name)
	char *name;
{
D 12
	struct stat stslash, stblock, stchar;
E 12
I 12
D 32
	struct ostat stslash, stblock, stchar;
E 32
I 32
	struct stat stslash, stblock, stchar;
E 32
E 12
	char *raw;
	int looped = 0;

	hotroot = 0;
	if (stat("/", &stslash) < 0){
		error("Can't stat root\n");
		return (0);
	}
retry:
	if (stat(name, &stblock) < 0){
		error("Can't stat %s\n", name);
		return (0);
	}
	if (stblock.st_mode & S_IFBLK) {
		raw = rawname(name);
		if (stat(raw, &stchar) < 0){
			error("Can't stat %s\n", raw);
			return (0);
		}
		if (stchar.st_mode & S_IFCHR) {
			if (stslash.st_dev == stblock.st_rdev) {
				hotroot++;
D 51
				raw = unrawname(name);
E 51
I 51
D 59
				raw = rawname(name);
E 59
I 59
				raw = unrawname(name);
E 59
E 51
			}
D 44
			check(raw);
E 44
I 44
			checkfilesys(raw);
E 44
			return (1);
		} else {
			error("%s is not a character device\n", raw);
			return (0);
		}
	} else if (stblock.st_mode & S_IFCHR) {
		if (looped) {
			error("Can't make sense out of name %s\n", name);
			return (0);
		}
		name = unrawname(name);
		looped++;
		goto retry;
	}
	error("Can't make sense out of name %s\n", name);
	return (0);
}

E 67
D 44
char *
unrawname(cp)
	char *cp;
E 44
I 44
checkfilesys(filesys)
	char *filesys;
E 44
{
I 69
	daddr_t n_ffree, n_bfree;
I 71
	struct dups *dp;
I 76
	struct zlncnt *zlnp;
E 76
E 71
E 69
D 44
	char *dp = rindex(cp, '/');
D 12
	struct stat stb;
E 12
I 12
D 32
	struct ostat stb;
E 32
I 32
	struct stat stb;
E 32
E 12

	if (dp == 0)
		return (cp);
	if (stat(cp, &stb) < 0)
		return (cp);
	if ((stb.st_mode&S_IFMT) != S_IFCHR)
		return (cp);
	if (*(dp+1) != 'r')
		return (cp);
	strcpy(dp+1, dp+2);
	return (cp);
}

char *
rawname(cp)
	char *cp;
{
	static char rawbuf[32];
	char *dp = rindex(cp, '/');

	if (dp == 0)
		return (0);
	*dp = 0;
	strcpy(rawbuf, cp);
	*dp = '/';
	strcat(rawbuf, "/r");
	strcat(rawbuf, dp+1);
	return (rawbuf);
}

check(dev)
	char *dev;
{
E 44
D 61
	register DINODE *dp;
	register ino_t *blp;
	register int i, n;
	ino_t savino;
D 39
	int b, c;
E 39
I 39
	int b, c, j, partial, ndb;
E 39
	daddr_t d, s;
E 61

D 44
	devname = dev;
	if (setup(dev) == 0) {
E 44
I 44
	devname = filesys;
	if (setup(filesys) == 0) {
E 44
		if (preen)
D 44
			pfatal("CAN'T CHECK DEVICE.");
E 44
I 44
			pfatal("CAN'T CHECK FILE SYSTEM.");
E 44
		return;
	}
D 44
/* 1 */
E 44
I 44
D 69
/* 1: scan inodes tallying blocks used */
E 69
I 69
	/*
	 * 1: scan inodes tallying blocks used
	 */
E 69
E 44
D 37
	if (preen==0) {
E 37
I 37
	if (preen == 0) {
		printf("** Last Mounted on %s\n", sblock.fs_fsmnt);
E 37
		if (hotroot)
			printf("** Root file system\n");
		printf("** Phase 1 - Check Blocks and Sizes\n");
	}
D 44
	pfunc = pass1;
E 44
I 44
	pass1();

D 47
/* 1b: locate first references to duplicates, if any  */
E 47
I 47
D 69
/* 1b: locate first references to duplicates, if any */
E 69
I 69
	/*
	 * 1b: locate first references to duplicates, if any
	 */
E 69
E 47
D 70
	if (enddup != &duplist[0]) {
E 70
I 70
	if (duplist) {
E 70
		if (preen)
			pfatal("INTERNAL ERROR: dups with -p");
		printf("** Phase 1b - Rescan For More DUPS\n");
		pass1b();
	}

D 61
/* 2: traverse directories to check reference counts */
E 61
I 61
D 69
/* 2: traverse directories from root to mark all connected directories */
E 69
I 69
	/*
	 * 2: traverse directories from root to mark all connected directories
	 */
E 69
E 61
	if (preen == 0)
		printf("** Phase 2 - Check Pathnames\n");
	pass2();

D 61
/* 3 */
E 61
I 61
D 69
/* 3: scan inodes looking for disconnected directories */
E 69
I 69
	/*
	 * 3: scan inodes looking for disconnected directories
	 */
E 69
E 61
	if (preen == 0)
		printf("** Phase 3 - Check Connectivity\n");
	pass3();

D 61
/* 4 */
E 61
I 61
D 69
/* 4: scan inodes looking for disconnected files; check reference counts */
E 69
I 69
	/*
	 * 4: scan inodes looking for disconnected files; check reference counts
	 */
E 69
E 61
	if (preen == 0)
		printf("** Phase 4 - Check Reference Counts\n");
	pass4();

D 61
/* 5 */
E 61
I 61
D 69
/* 5: check resource counts in cylinder groups */
E 69
I 69
	/*
	 * 5: check and repair resource counts in cylinder groups
	 */
E 69
E 61
	if (preen == 0)
		printf("** Phase 5 - Check Cyl groups\n");
	pass5();

D 69
	if (fixcg) {
		if (preen == 0)
			printf("** Phase 6 - Salvage Cylinder Groups\n");
		makecg();
		n_ffree = sblock.fs_cstotal.cs_nffree;
		n_bfree = sblock.fs_cstotal.cs_nbfree;
E 69
I 69
	/*
	 * print out summary statistics
	 */
	n_ffree = sblock.fs_cstotal.cs_nffree;
	n_bfree = sblock.fs_cstotal.cs_nbfree;
D 75
	pwarn("%d files, %d used, %d free (%d frags, %d blocks)\n", n_files,
	    n_blks, n_ffree + sblock.fs_frag * n_bfree, n_ffree, n_bfree);
E 75
I 75
	pwarn("%d files, %d used, %d free ",
	    n_files, n_blks, n_ffree + sblock.fs_frag * n_bfree);
	printf("(%d frags, %d blocks, %.1f%% fragmentation)\n",
	    n_ffree, n_bfree, (float)(n_ffree * 100) / sblock.fs_dsize);
E 75
	if (debug && (n_files -= imax - ROOTINO - sblock.fs_cstotal.cs_nifree))
		printf("%d files missing\n", n_files);
	if (debug) {
		n_blks += sblock.fs_ncg *
			(cgdmin(&sblock, 0) - cgsblock(&sblock, 0));
		n_blks += cgsblock(&sblock, 0) - cgbase(&sblock, 0);
		n_blks += howmany(sblock.fs_cssize, sblock.fs_fsize);
		if (n_blks -= fmax - (n_ffree + sblock.fs_frag * n_bfree))
			printf("%d blocks missing\n", n_blks);
I 71
		if (duplist != NULL) {
			printf("The following duplicate blocks remain:");
			for (dp = duplist; dp; dp = dp->next)
				printf(" %d,", dp->dup);
			printf("\n");
		}
I 76
		if (zlnhead != NULL) {
			printf("The following zero link count inodes remain:");
			for (zlnp = zlnhead; zlnp; zlnp = zlnp->next)
				printf(" %d,", zlnp->zlncnt);
			printf("\n");
		}
E 76
E 71
E 69
	}
I 76
	zlnhead = (struct zlncnt *)0;
	duplist = (struct dups *)0;
E 76
D 69

	pwarn("%d files, %d used, %d free (%d frags, %d blocks)\n",
	    n_files, n_blks - howmany(sblock.fs_cssize, sblock.fs_fsize),
	    n_ffree + sblock.fs_frag * n_bfree, n_ffree, n_bfree);
E 69
	if (dfile.mod) {
D 61
		time(&sblock.fs_time);
E 61
I 61
		(void)time(&sblock.fs_time);
E 61
		sbdirty();
	}
	ckfini();
	free(blockmap);
D 69
	free(freemap);
E 69
	free(statemap);
D 61
	free(lncntp);
E 61
I 61
	free((char *)lncntp);
E 61
D 47
	if (dfile.mod)
E 47
I 47
D 59
	if (dfile.mod) {
E 47
		if (preen) {
I 47
			if (hotroot)
				exit(4);
		} else {
E 47
			printf("\n***** FILE SYSTEM WAS MODIFIED *****\n");
			if (hotroot) {
D 47
				sync();
E 47
I 47
				printf("\n***** BOOT UNIX (NO SYNC!) *****\n");
E 47
				exit(4);
			}
D 47
		} else if (hotroot) {
			printf("\n***** BOOT UNIX (NO SYNC!) *****\n");
			exit(4);
E 47
		}
E 59
I 59
	if (!dfile.mod)
		return;
	if (!preen) {
		printf("\n***** FILE SYSTEM WAS MODIFIED *****\n");
		if (hotroot)
			printf("\n***** REBOOT UNIX *****\n");
E 59
D 47
	sync();
E 47
I 47
	}
D 59
	sync();			/* ??? */
E 59
I 59
	if (hotroot) {
		sync();
		exit(4);
	}
I 68
}

char *
blockcheck(name)
	char *name;
{
	struct stat stslash, stblock, stchar;
	char *raw;
	int looped = 0;

	hotroot = 0;
	if (stat("/", &stslash) < 0){
I 78
		perror("/");
E 78
		printf("Can't stat root\n");
		return (0);
	}
retry:
	if (stat(name, &stblock) < 0){
I 78
		perror(name);
E 78
		printf("Can't stat %s\n", name);
		return (0);
	}
D 77
	if (stblock.st_mode & S_IFBLK) {
E 77
I 77
	if ((stblock.st_mode & S_IFMT) == S_IFBLK) {
I 78
		if (stslash.st_dev == stblock.st_rdev) {
			hotroot++;
			return (name);
		}
E 78
E 77
		raw = rawname(name);
		if (stat(raw, &stchar) < 0){
I 78
			perror(raw);
E 78
			printf("Can't stat %s\n", raw);
D 78
			return (0);
E 78
I 78
			return (name);
E 78
		}
D 77
		if (stchar.st_mode & S_IFCHR) {
E 77
I 77
D 78
		if ((stchar.st_mode & S_IFMT) == S_IFCHR) {
E 77
			if (stslash.st_dev == stblock.st_rdev) {
				hotroot++;
				raw = unrawname(name);
			}
E 78
I 78
		if ((stchar.st_mode & S_IFMT) == S_IFCHR)
E 78
			return (raw);
D 78
		} else {
E 78
I 78
		else {
E 78
			printf("%s is not a character device\n", raw);
D 78
			return (0);
E 78
I 78
			return (name);
E 78
		}
D 77
	} else if (stblock.st_mode & S_IFCHR) {
E 77
I 77
	} else if ((stblock.st_mode & S_IFMT) == S_IFCHR) {
E 77
		if (looped) {
			printf("Can't make sense out of name %s\n", name);
			return (0);
		}
		name = unrawname(name);
		looped++;
		goto retry;
	}
	printf("Can't make sense out of name %s\n", name);
	return (0);
}

char *
unrawname(cp)
	char *cp;
{
	char *dp = rindex(cp, '/');
	struct stat stb;

	if (dp == 0)
		return (cp);
	if (stat(cp, &stb) < 0)
		return (cp);
	if ((stb.st_mode&S_IFMT) != S_IFCHR)
		return (cp);
	if (*(dp+1) != 'r')
		return (cp);
	(void)strcpy(dp+1, dp+2);
	return (cp);
}

char *
rawname(cp)
	char *cp;
{
	static char rawbuf[32];
	char *dp = rindex(cp, '/');

	if (dp == 0)
		return (0);
	*dp = 0;
	(void)strcpy(rawbuf, cp);
	*dp = '/';
	(void)strcat(rawbuf, "/r");
	(void)strcat(rawbuf, dp+1);
	return (rawbuf);
E 68
E 59
E 47
}
D 67

I 47
setup(dev)
	char *dev;
{
	dev_t rootdev;
	struct stat statb;
D 61
	int super = bflag ? bflag : SBLOCK;
	int i, j, size;
	int c, d, cgd;
E 61
I 61
	daddr_t super = bflag ? bflag : SBLOCK;
	int i, j, c, d, cgd;
	long size;
	BUFAREA asblk;
#	define altsblock asblk.b_un.b_fs
E 61

D 61
	bflag = 0;
E 61
	if (stat("/", &statb) < 0)
		errexit("Can't stat root\n");
	rootdev = statb.st_dev;
	if (stat(dev, &statb) < 0) {
		error("Can't stat %s\n", dev);
		return (0);
	}
	rawflg = 0;
	if ((statb.st_mode & S_IFMT) == S_IFBLK)
		;
	else if ((statb.st_mode & S_IFMT) == S_IFCHR)
		rawflg++;
	else {
		if (reply("file is not a block or character device; OK") == 0)
			return (0);
	}
	if (rootdev == statb.st_rdev)
		hotroot++;
	if ((dfile.rfdes = open(dev, 0)) < 0) {
		error("Can't open %s\n", dev);
		return (0);
	}
	if (preen == 0)
		printf("** %s", dev);
	if (nflag || (dfile.wfdes = open(dev, 1)) < 0) {
		dfile.wfdes = -1;
		if (preen)
			pfatal("NO WRITE ACCESS");
		printf(" (NO WRITE)");
	}
	if (preen == 0)
		printf("\n");
	fixcg = 0; inosumbad = 0; offsumbad = 0; frsumbad = 0; sbsumbad = 0;
	dfile.mod = 0;
	n_files = n_blks = n_ffree = n_bfree = 0;
	muldup = enddup = &duplist[0];
	badlnp = &badlncnt[0];
	lfdir = 0;
	rplyflag = 0;
	initbarea(&sblk);
	initbarea(&fileblk);
	initbarea(&inoblk);
	initbarea(&cgblk);
I 61
	initbarea(&asblk);
E 61
	/*
	 * Read in the super block and its summary info.
	 */
D 61
	if (bread(&dfile, &sblock, super, SBSIZE) == 0)
E 61
I 61
	if (bread(&dfile, (char *)&sblock, super, (long)SBSIZE) == 0)
E 61
		return (0);
	sblk.b_bno = super;
	sblk.b_size = SBSIZE;
	/*
	 * run a few consistency checks of the super block
	 */
	if (sblock.fs_magic != FS_MAGIC)
		{ badsb("MAGIC NUMBER WRONG"); return (0); }
	if (sblock.fs_ncg < 1)
		{ badsb("NCG OUT OF RANGE"); return (0); }
	if (sblock.fs_cpg < 1 || sblock.fs_cpg > MAXCPG)
		{ badsb("CPG OUT OF RANGE"); return (0); }
D 61
	if (sblock.fs_nsect < 1)
		{ badsb("NSECT < 1"); return (0); }
	if (sblock.fs_ntrak < 1)
		{ badsb("NTRAK < 1"); return (0); }
	if (sblock.fs_spc != sblock.fs_nsect * sblock.fs_ntrak)
		{ badsb("SPC DOES NOT JIVE w/NTRAK*NSECT"); return (0); }
	if (sblock.fs_ipg % INOPB(&sblock))
		{ badsb("INODES NOT MULTIPLE OF A BLOCK"); return (0); }
	if (cgdmin(&sblock, 0) >= sblock.fs_cpg * sblock.fs_spc / NSPF(&sblock))
		{ badsb("IMPLIES MORE INODE THAN DATA BLOCKS"); return (0); }
E 61
	if (sblock.fs_ncg * sblock.fs_cpg < sblock.fs_ncyl ||
	    (sblock.fs_ncg - 1) * sblock.fs_cpg >= sblock.fs_ncyl)
		{ badsb("NCYL DOES NOT JIVE WITH NCG*CPG"); return (0); }
D 61
	if (sblock.fs_fpg != sblock.fs_cpg * sblock.fs_spc / NSPF(&sblock))
		{ badsb("FPG DOES NOT JIVE WITH CPG & SPC"); return (0); }
	if (sblock.fs_size * NSPF(&sblock) <=
	    (sblock.fs_ncyl - 1) * sblock.fs_spc)
		{ badsb("SIZE PREPOSTEROUSLY SMALL"); return (0); }
	if (sblock.fs_size * NSPF(&sblock) > sblock.fs_ncyl * sblock.fs_spc)
E 61
I 61
	if (sblock.fs_sbsize > SBSIZE)
E 61
		{ badsb("SIZE PREPOSTEROUSLY LARGE"); return (0); }
D 61
	/* rest we COULD repair... */
	if (sblock.fs_cgsize != fragroundup(&sblock,
	    sizeof(struct cg) + howmany(sblock.fs_fpg, NBBY)))
		{ badsb("CGSIZE INCORRECT"); return (0); }
	if (sblock.fs_cssize !=
	    fragroundup(&sblock, sblock.fs_ncg * sizeof(struct csum)))
		{ badsb("CSSIZE INCORRECT"); return (0); }
E 61
I 61
	/*
	 * Set all possible fields that could differ, then do check
	 * of whole super block against an alternate super block.
	 * When an alternate super-block is specified this check is skipped.
	 */
	if (bflag)
		goto sbok;
	if (getblk(&asblk, cgsblock(&sblock, sblock.fs_ncg - 1),
	    sblock.fs_sbsize) == 0)
		return (0);
	altsblock.fs_link = sblock.fs_link;
	altsblock.fs_rlink = sblock.fs_rlink;
	altsblock.fs_time = sblock.fs_time;
	altsblock.fs_cstotal = sblock.fs_cstotal;
	altsblock.fs_cgrotor = sblock.fs_cgrotor;
	altsblock.fs_fmod = sblock.fs_fmod;
	altsblock.fs_clean = sblock.fs_clean;
	altsblock.fs_ronly = sblock.fs_ronly;
	altsblock.fs_flags = sblock.fs_flags;
	altsblock.fs_maxcontig = sblock.fs_maxcontig;
	altsblock.fs_minfree = sblock.fs_minfree;
	altsblock.fs_rotdelay = sblock.fs_rotdelay;
	altsblock.fs_maxbpg = sblock.fs_maxbpg;
	bcopy((char *)sblock.fs_csp, (char *)altsblock.fs_csp,
		sizeof sblock.fs_csp);
	bcopy((char *)sblock.fs_fsmnt, (char *)altsblock.fs_fsmnt,
		sizeof sblock.fs_fsmnt);
	if (bcmp((char *)&sblock, (char *)&altsblock, (int)sblock.fs_sbsize))
		{ badsb("TRASHED VALUES IN SUPER BLOCK"); return (0); }
sbok:
E 61
	fmax = sblock.fs_size;
	imax = sblock.fs_ncg * sblock.fs_ipg;
	n_bad = cgsblock(&sblock, 0); /* boot block plus dedicated sblock */
	/*
	 * read in the summary info.
	 */
	for (i = 0, j = 0; i < sblock.fs_cssize; i += sblock.fs_bsize, j++) {
		size = sblock.fs_cssize - i < sblock.fs_bsize ?
		    sblock.fs_cssize - i : sblock.fs_bsize;
D 61
		sblock.fs_csp[j] = (struct csum *)calloc(1, size);
		bread(&dfile, (char *)sblock.fs_csp[j],
E 61
I 61
		sblock.fs_csp[j] = (struct csum *)calloc(1, (unsigned)size);
		if (bread(&dfile, (char *)sblock.fs_csp[j],
E 61
		    fsbtodb(&sblock, sblock.fs_csaddr + j * sblock.fs_frag),
D 61
		    size);
E 61
I 61
		    size) == 0)
			return (0);
E 61
	}
	/*
	 * allocate and initialize the necessary maps
	 */
	bmapsz = roundup(howmany(fmax, NBBY), sizeof(short));
D 61
	blockmap = (char *)calloc(bmapsz, sizeof (char));
E 61
I 61
	blockmap = calloc((unsigned)bmapsz, sizeof (char));
E 61
	if (blockmap == NULL) {
		printf("cannot alloc %d bytes for blockmap\n", bmapsz);
D 61
		exit(1);
E 61
I 61
		goto badsb;
E 61
	}
D 61
	freemap = (char *)calloc(bmapsz, sizeof (char));
E 61
I 61
	freemap = calloc((unsigned)bmapsz, sizeof (char));
E 61
	if (freemap == NULL) {
		printf("cannot alloc %d bytes for freemap\n", bmapsz);
D 61
		exit(1);
E 61
I 61
		goto badsb;
E 61
	}
D 61
	statemap = (char *)calloc(imax+1, sizeof(char));
E 61
I 61
	statemap = calloc((unsigned)(imax + 1), sizeof(char));
E 61
	if (statemap == NULL) {
		printf("cannot alloc %d bytes for statemap\n", imax + 1);
D 61
		exit(1);
E 61
I 61
		goto badsb;
E 61
	}
D 61
	lncntp = (short *)calloc(imax+1, sizeof(short));
E 61
I 61
	lncntp = (short *)calloc((unsigned)(imax + 1), sizeof(short));
E 61
	if (lncntp == NULL) {
		printf("cannot alloc %d bytes for lncntp\n", 
		    (imax + 1) * sizeof(short));
D 61
		exit(1);
E 61
I 61
		goto badsb;
E 61
	}
	for (c = 0; c < sblock.fs_ncg; c++) {
		cgd = cgdmin(&sblock, c);
		if (c == 0) {
			d = cgbase(&sblock, c);
			cgd += howmany(sblock.fs_cssize, sblock.fs_fsize);
		} else
			d = cgsblock(&sblock, c);
		for (; d < cgd; d++)
			setbmap(d);
	}

D 61
	startinum = imax + 1;
E 61
	return (1);

badsb:
	ckfini();
	return (0);
I 61
#	undef altsblock
E 61
}

E 47
pass1()
{
	register int c, i, n, j;
	register DINODE *dp;
D 61
	int savino, ndb, partial;
E 61
I 61
	int ndb, partial;
	struct inodesc idesc;
	ino_t inumber;
E 61

D 61
	pfunc = pass1check;
E 44
	inum = 0;
E 61
I 61
	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	idesc.id_func = pass1check;
	inumber = 0;
E 61
D 11
	n_blks += roundup(sblock.fs_ncg * sizeof (struct csum), BSIZE)
		/ BSIZE * FRAG;
E 11
I 11
D 14
	n_blks += howmany(sblock.fs_cssize, BSIZE) * FRAG;
E 14
I 14
D 34
	n_blks += howmany(sblock.fs_cssize, sblock.fs_bsize) * sblock.fs_frag;
E 34
I 34
	n_blks += howmany(sblock.fs_cssize, sblock.fs_fsize);
E 34
E 14
E 11
	for (c = 0; c < sblock.fs_ncg; c++) {
D 19
		if (getblk(&cgblk, cgtod(c, &sblock), sblock.fs_cgsize) == 0)
E 19
I 19
		if (getblk(&cgblk, cgtod(&sblock, c), sblock.fs_cgsize) == 0)
E 19
			continue;
I 34
D 47
		if (debug && cgrp.cg_magic != CG_MAGIC)
			printf("cg %d: bad magic number\n", c);
E 47
I 47
		if (cgrp.cg_magic != CG_MAGIC) {
D 61
			pfatal("cg %d: bad magic number\n", c);
			bzero((caddr_t)&cgrp, sblock.fs_cgsize);
E 61
I 61
			pfatal("CG %d: BAD MAGIC NUMBER\n", c);
			bzero((char *)&cgrp, (int)sblock.fs_cgsize);
E 61
		}
E 47
E 34
D 6
		dp = ginode();
		if (dp == NULL)
			continue;
E 6
		n = 0;
D 6
		for (i = 0; i < sblock.fs_ipg; i++, inum++, dp++) {
E 6
I 6
D 61
		for (i = 0; i < sblock.fs_ipg; i++, inum++) {
			dp = ginode();
E 61
I 61
		for (i = 0; i < sblock.fs_ipg; i++, inumber++) {
			dp = ginode(inumber);
E 61
			if (dp == NULL)
				continue;
I 24
			n++;
E 24
E 6
			if (ALLOC) {
				if (!isset(cgrp.cg_iused, i)) {
I 6
D 19
					/*
E 6
					printf("%d bad, not used\n", inum);
I 6
					*/
E 19
I 19
					if (debug)
						printf("%d bad, not used\n",
D 61
						    inum);
E 61
I 61
						    inumber);
E 61
E 19
E 6
					inosumbad++;
I 6
D 24
					n++;
E 24
E 6
				}
I 24
				n--;
E 24
D 61
				lastino = inum;
E 61
I 61
				lastino = inumber;
E 61
D 39
				if (ftypeok(dp) == 0) {
					pfatal("UNKNOWN FILE TYPE I=%u", inum);
					if (reply("CLEAR") == 1) {
						zapino(dp);
						inodirty();
						inosumbad++;
					}
					continue;
				}
E 39
I 39
D 55
				if (ftypeok(dp) == 0)
E 55
I 55
				if (!preen && BADBLK &&
				    reply("HOLD BAD BLOCK") == 1) {
					dp->di_size = sblock.fs_fsize;
					dp->di_mode = IFREG|0600;
					inodirty();
				} else if (ftypeok(dp) == 0)
E 55
					goto unknown;
D 49
				if (dp->di_size < 0)
E 49
I 49
				if (dp->di_size < 0) {
					if (debug)
						printf("bad size %d:",
							dp->di_size);
E 49
					goto unknown;
I 49
				}
E 49
				ndb = howmany(dp->di_size, sblock.fs_bsize);
				if (SPECIAL)
					ndb++;
				for (j = ndb; j < NDADDR; j++)
D 49
					if (dp->di_db[j] != 0)
E 49
I 49
					if (dp->di_db[j] != 0) {
						if (debug)
D 55
							printf("bad direct addr:");
E 55
I 55
							printf("bad direct addr: %d\n",
								dp->di_db[j]);
E 55
E 49
						goto unknown;
I 49
					}
E 49
				for (j = 0, ndb -= NDADDR; ndb > 0; j++)
					ndb /= NINDIR(&sblock);
				for (; j < NIADDR; j++)
D 49
					if (dp->di_ib[j] != 0)
E 49
I 49
					if (dp->di_ib[j] != 0) {
						if (debug)
D 55
							printf("bad indirect addr:");
E 55
I 55
							printf("bad indirect addr: %d\n",
								dp->di_ib[j]);
E 55
E 49
						goto unknown;
I 49
					}
E 49
E 39
				n_files++;
D 45
				if (setlncnt(dp->di_nlink) <= 0) {
E 45
I 45
D 61
				lncntp[inum] = dp->di_nlink;
E 61
I 61
				lncntp[inumber] = dp->di_nlink;
E 61
				if (dp->di_nlink <= 0) {
E 45
					if (badlnp < &badlncnt[MAXLNCNT])
D 61
						*badlnp++ = inum;
E 61
I 61
						*badlnp++ = inumber;
E 61
					else {
						pfatal("LINK COUNT TABLE OVERFLOW");
						if (reply("CONTINUE") == 0)
							errexit("");
					}
				}
D 22
				setstate(DIR ? DSTATE : FSTATE);
E 22
I 22
D 45
				setstate(DIRCT ? DSTATE : FSTATE);
E 45
I 45
D 61
				statemap[inum] = DIRCT ? DSTATE : FSTATE;
E 45
E 22
				badblk = dupblk = 0; filsize = 0; maxblk = 0;
				ckinode(dp, ADDR);
I 57
				filsize *= btodb(sblock.fs_fsize);
				if (dp->di_blocks != filsize) {
E 61
I 61
				statemap[inumber] = DIRCT ? DSTATE : FSTATE;
				badblk = dupblk = 0; maxblk = 0;
				idesc.id_number = inumber;
				idesc.id_filesize = 0;
				(void)ckinode(dp, &idesc);
				idesc.id_filesize *= btodb(sblock.fs_fsize);
				if (dp->di_blocks != idesc.id_filesize) {
E 61
					pwarn("INCORRECT BLOCK COUNT I=%u (%ld should be %ld)",
D 61
					    inum, dp->di_blocks, filsize);
E 61
I 61
					    inumber, dp->di_blocks,
					    idesc.id_filesize);
E 61
					if (preen)
						printf(" (CORRECTED)\n");
					else if (reply("CORRECT") == 0)
						continue;
D 61
					dp->di_blocks = filsize;
E 61
I 61
					dp->di_blocks = idesc.id_filesize;
E 61
					inodirty();
				}
E 57
I 39
				continue;
		unknown:
D 55
				pfatal("UNKNOWN FILE TYPE I=%u", inum);
				if (reply("CLEAR") == 1) {
E 55
I 55
D 60
				if (!SOCK)
					pfatal("UNKNOWN FILE TYPE I=%u", inum);
				if ((preen && SOCK) || reply("CLEAR") == 1) {
E 60
I 60
D 61
				pfatal("UNKNOWN FILE TYPE I=%u", inum);
E 61
I 61
				pfatal("UNKNOWN FILE TYPE I=%u", inumber);
E 61
				if (reply("CLEAR") == 1) {
E 60
E 55
					zapino(dp);
					inodirty();
					inosumbad++;
				}
E 39
D 22
				if (DIR && dp->di_size % sizeof(DIRECT)) {
					pwarn("DIRECTORY MISALIGNED I=%u\n",
					    inum);
					if (preen == 0)
						printf("\n");
				}
E 22
			} else {
D 24
				n++;
E 24
				if (isset(cgrp.cg_iused, i)) {
I 6
D 19
					/*
E 6
					printf("%d bad, marked used\n", inum);
I 6
					*/
E 19
I 19
					if (debug)
						printf("%d bad, marked used\n",
D 61
						    inum);
E 61
I 61
						    inumber);
E 61
E 19
E 6
					inosumbad++;
I 6
					n--;
E 6
				}
D 39
				if (dp->di_mode != 0) {
E 39
I 39
				partial = 0;
				for (j = 0; j < NDADDR; j++)
					if (dp->di_db[j] != 0)
						partial++;
				for (j = 0; j < NIADDR; j++)
					if (dp->di_ib[j] != 0)
						partial++;
				if (partial || dp->di_mode != 0 ||
				    dp->di_size != 0) {
E 39
D 61
					pfatal("PARTIALLY ALLOCATED INODE I=%u", inum);
E 61
I 61
					pfatal("PARTIALLY ALLOCATED INODE I=%u",
						inumber);
E 61
					if (reply("CLEAR") == 1) {
						zapino(dp);
						inodirty();
						inosumbad++;
					}
				}
			}
		}
D 11
		if (n != cgrp.cg_nifree) {
			printf("cg[%d].cg_nifree is %d not %d\n",
			    c, cgrp.cg_nifree, n);
E 11
I 11
		if (n != cgrp.cg_cs.cs_nifree) {
D 19
			printf("cg[%d].cg_cs.cs_nifree is %d not %d\n",
			    c, cgrp.cg_cs.cs_nifree, n);
E 19
I 19
			if (debug)
D 24
				printf("cg[%d].cg_cs.cs_nifree is %d not %d\n",
E 24
I 24
				printf("cg[%d].cg_cs.cs_nifree is %d; calc %d\n",
E 24
				    c, cgrp.cg_cs.cs_nifree, n);
E 19
E 11
			inosumbad++;
		}
I 33
		if (cgrp.cg_cs.cs_nbfree != sblock.fs_cs(&sblock, c).cs_nbfree
		  || cgrp.cg_cs.cs_nffree != sblock.fs_cs(&sblock, c).cs_nffree
		  || cgrp.cg_cs.cs_nifree != sblock.fs_cs(&sblock, c).cs_nifree
		  || cgrp.cg_cs.cs_ndir != sblock.fs_cs(&sblock, c).cs_ndir)
			sbsumbad++;
E 33
	}
D 44
/* 1b */
	if (enddup != &duplist[0]) {
		if (preen)
			pfatal("INTERNAL ERROR: dups with -p");
		printf("** Phase 1b - Rescan For More DUPS\n");
		pfunc = pass1b;
		inum = 0;
		for (c = 0; c < sblock.fs_ncg; c++) {
D 6
			dp = ginode();
			if (dp == NULL)
				continue;
			for (i = 0; i < sblock.fs_ipg; i++, inum++, dp++)
E 6
I 6
			for (i = 0; i < sblock.fs_ipg; i++, inum++) {
				dp = ginode();
				if (dp == NULL)
					continue;
E 6
				if (getstate() != USTATE &&
				    (ckinode(dp, ADDR) & STOP))
					goto out1b;
E 44
I 44
}

D 61
pass1check(blk, size)
	daddr_t blk;
	int size;
E 61
I 61
pass1check(idesc)
	register struct inodesc *idesc;
E 61
{
	register daddr_t *dlp;
	int res = KEEPON;
I 47
D 61
	int anyout;
E 61
I 61
	int anyout, nfrags;
	daddr_t blkno = idesc->id_blkno;
E 61
E 47

I 47
D 61
	anyout = outrange(blk, size);
E 47
	for (; size > 0; blk++, size--) {
D 47
		if (outrange(blk)) {
E 47
I 47
		if (anyout && outrange(blk, 1)) {
E 47
			blkerr("BAD", blk);
E 61
I 61
	anyout = outrange(blkno, idesc->id_numfrags);
	for (nfrags = idesc->id_numfrags; nfrags > 0; blkno++, nfrags--) {
		if (anyout && outrange(blkno, 1)) {
			blkerr(idesc->id_number, "BAD", blkno);
E 61
			if (++badblk >= MAXBAD) {
D 61
				pwarn("EXCESSIVE BAD BLKS I=%u", inum);
E 61
I 61
				pwarn("EXCESSIVE BAD BLKS I=%u",
					idesc->id_number);
E 61
				if (preen)
					printf(" (SKIPPING)\n");
				else if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
E 44
I 6
			}
I 44
			res = SKIP;
D 61
		} else if (getbmap(blk)) {
			blkerr("DUP", blk);
E 61
I 61
		} else if (getbmap(blkno)) {
			blkerr(idesc->id_number, "DUP", blkno);
E 61
			if (++dupblk >= MAXDUP) {
D 61
				pwarn("EXCESSIVE DUP BLKS I=%u", inum);
E 61
I 61
				pwarn("EXCESSIVE DUP BLKS I=%u",
					idesc->id_number);
E 61
				if (preen)
					printf(" (SKIPPING)\n");
				else if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
			if (enddup >= &duplist[DUPTBLSIZE]) {
				pfatal("DUP TABLE OVERFLOW.");
				if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
			for (dlp = duplist; dlp < muldup; dlp++)
D 61
				if (*dlp == blk) {
					*enddup++ = blk;
E 61
I 61
				if (*dlp == blkno) {
					*enddup++ = blkno;
E 61
					break;
				}
			if (dlp >= muldup) {
				*enddup++ = *muldup;
D 61
				*muldup++ = blk;
E 61
I 61
				*muldup++ = blkno;
E 61
			}
		} else {
			n_blks++;
D 61
			setbmap(blk);
E 61
I 61
			setbmap(blkno);
E 61
E 44
E 6
		}
I 44
D 61
		filsize++;
E 61
I 61
		idesc->id_filesize++;
E 61
E 44
	}
I 44
	return (res);
}

pass1b()
{
	register int c, i;
	register DINODE *dp;
I 61
	struct inodesc idesc;
	ino_t inumber;
E 61

D 61
	pfunc = pass1bcheck;
	inum = 0;
E 61
I 61
	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	idesc.id_func = pass1bcheck;
	inumber = 0;
E 61
	for (c = 0; c < sblock.fs_ncg; c++) {
D 61
		for (i = 0; i < sblock.fs_ipg; i++, inum++) {
			dp = ginode();
E 61
I 61
		for (i = 0; i < sblock.fs_ipg; i++, inumber++) {
			dp = ginode(inumber);
E 61
			if (dp == NULL)
				continue;
D 45
			if (getstate() != USTATE &&
E 45
I 45
D 61
			if (statemap[inum] != USTATE &&
E 45
			    (ckinode(dp, ADDR) & STOP))
E 61
I 61
			idesc.id_number = inumber;
			if (statemap[inumber] != USTATE &&
			    (ckinode(dp, &idesc) & STOP))
E 61
				goto out1b;
		}
	}
E 44
out1b:
D 6
	if (inoblk.b_dirty) {
		bwrite(&dfile, (char *)ibase, startib, niblk*BSIZE);
		inoblk.b_dirty = 0;
	}
E 6
I 6
	flush(&dfile, &inoblk);
E 6
D 44
/* 2 */
	if (preen == 0)
		printf("** Phase 2 - Check Pathnames\n");
E 44
I 44
}

D 61
pass1bcheck(blk, size)
	daddr_t blk;
	int size;
E 61
I 61
pass1bcheck(idesc)
	register struct inodesc *idesc;
E 61
{
	register daddr_t *dlp;
D 61
	int res = KEEPON;
E 61
I 61
	int nfrags, res = KEEPON;
	daddr_t blkno = idesc->id_blkno;
E 61

D 61
	for (; size > 0; blk++, size--) {
D 47
		if (outrange(blk))
E 47
I 47
		if (outrange(blk, 1))
E 61
I 61
	for (nfrags = idesc->id_numfrags; nfrags > 0; blkno++, nfrags--) {
		if (outrange(blkno, 1))
E 61
E 47
			res = SKIP;
		for (dlp = duplist; dlp < muldup; dlp++)
D 61
			if (*dlp == blk) {
				blkerr("DUP", blk);
E 61
I 61
			if (*dlp == blkno) {
				blkerr(idesc->id_number, "DUP", blkno);
E 61
				*dlp = *--muldup;
D 61
				*muldup = blk;
E 61
I 61
				*muldup = blkno;
E 61
				if (muldup == duplist)
					return (STOP);
			}
	}
	return (res);
}

pass2()
{
	register DINODE *dp;
I 61
	struct inodesc rootdesc;
E 61

E 44
D 61
	inum = ROOTINO;
	thisname = pathp = pathname;
D 44
	pfunc = pass2;
E 44
I 44
	pfunc = pass2check;
E 44
D 45
	switch (getstate()) {
E 45
I 45
	switch (statemap[inum]) {
E 61
I 61
	bzero((char *)&rootdesc, sizeof(struct inodesc));
	rootdesc.id_type = ADDR;
	rootdesc.id_func = pass2check;
	rootdesc.id_number = ROOTINO;
	pathp = pathname;
	switch (statemap[ROOTINO]) {
E 61
E 45

	case USTATE:
		errexit("ROOT INODE UNALLOCATED. TERMINATING.\n");

	case FSTATE:
		pfatal("ROOT INODE NOT DIRECTORY");
D 61
		if (reply("FIX") == 0 || (dp = ginode()) == NULL)
E 61
I 61
		if (reply("FIX") == 0 || (dp = ginode(ROOTINO)) == NULL)
E 61
			errexit("");
		dp->di_mode &= ~IFMT;
		dp->di_mode |= IFDIR;
		inodirty();
		inosumbad++;
D 45
		setstate(DSTATE);
E 45
I 45
D 61
		statemap[inum] = DSTATE;
E 61
I 61
		statemap[ROOTINO] = DSTATE;
E 61
E 45
		/* fall into ... */

	case DSTATE:
D 61
		descend();
E 61
I 61
		descend(&rootdesc, ROOTINO);
E 61
		break;

	case CLEAR:
		pfatal("DUPS/BAD IN ROOT INODE");
		printf("\n");
		if (reply("CONTINUE") == 0)
			errexit("");
D 45
		setstate(DSTATE);
E 45
I 45
D 61
		statemap[inum] = DSTATE;
E 45
		descend();
E 61
I 61
		statemap[ROOTINO] = DSTATE;
		descend(&rootdesc, ROOTINO);
E 61
	}
D 44
/* 3 */
	if (preen == 0)
		printf("** Phase 3 - Check Connectivity\n");
E 44
I 44
}

D 61
pass2check(dirp)
	register DIRECT *dirp;
E 61
I 61
pass2check(idesc)
	struct inodesc *idesc;
E 61
{
D 61
	register char *p;
	register n;
E 61
I 61
	register DIRECT *dirp = idesc->id_dirp;
	char *curpathloc;
	int n, entrysize, ret = 0;
E 61
	DINODE *dp;
I 61
	DIRECT proto;
E 61

D 61
	if ((inum = dirp->d_ino) == 0)
		return (KEEPON);
	thisname = pathp;
E 61
I 61
	/* 
	 * check for "."
	 */
	if (idesc->id_entryno != 0)
		goto chk1;
D 66
	if (dirp->d_ino != 0 && dirp->d_namlen == 1 && dirp->d_name[0] == '.') {
E 66
I 66
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, ".") == 0) {
E 66
		if (dirp->d_ino != idesc->id_number) {
			direrr(idesc->id_number, "BAD INODE NUMBER FOR '.'");
			dirp->d_ino = idesc->id_number;
D 63
			ret |= dofix(idesc);
E 63
I 63
			if (reply("FIX") == 1)
				ret |= ALTERED;
E 63
		}
		goto chk1;
	}
	direrr(idesc->id_number, "MISSING '.'");
	proto.d_ino = idesc->id_number;
	proto.d_namlen = 1;
	(void)strcpy(proto.d_name, ".");
	entrysize = DIRSIZ(&proto);
D 66
	if (dirp->d_ino != 0) {
E 66
I 66
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, "..") != 0) {
E 66
		pfatal("CANNOT FIX, FIRST ENTRY IN DIRECTORY CONTAINS %s\n",
			dirp->d_name);
	} else if (dirp->d_reclen < entrysize) {
		pfatal("CANNOT FIX, INSUFFICIENT SPACE TO ADD '.'\n");
	} else if (dirp->d_reclen < 2 * entrysize) {
		proto.d_reclen = dirp->d_reclen;
		bcopy((char *)&proto, (char *)dirp, entrysize);
D 63
		ret |= dofix(idesc);
E 63
I 63
		if (reply("FIX") == 1)
			ret |= ALTERED;
E 63
	} else {
		n = dirp->d_reclen - entrysize;
		proto.d_reclen = entrysize;
		bcopy((char *)&proto, (char *)dirp, entrysize);
		idesc->id_entryno++;
		lncntp[dirp->d_ino]--;
		dirp = (DIRECT *)((char *)(dirp) + entrysize);
		bzero((char *)dirp, n);
		dirp->d_reclen = n;
D 63
		ret |= dofix(idesc);
E 63
I 63
		if (reply("FIX") == 1)
			ret |= ALTERED;
E 63
	}
chk1:
	if (idesc->id_entryno > 1)
		goto chk2;
	proto.d_ino = idesc->id_parent;
	proto.d_namlen = 2;
	(void)strcpy(proto.d_name, "..");
	entrysize = DIRSIZ(&proto);
	if (idesc->id_entryno == 0) {
		n = DIRSIZ(dirp);
		if (dirp->d_reclen < n + entrysize)
			goto chk2;
		proto.d_reclen = dirp->d_reclen - n;
		dirp->d_reclen = n;
		idesc->id_entryno++;
		lncntp[dirp->d_ino]--;
		dirp = (DIRECT *)((char *)(dirp) + n);
		bzero((char *)dirp, n);
		dirp->d_reclen = n;
	}
D 66
	if (dirp->d_ino != 0 && dirp->d_namlen == 2 &&
	    strcmp(dirp->d_name, "..") == 0) {
E 66
I 66
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, "..") == 0) {
E 66
		if (dirp->d_ino != idesc->id_parent) {
			direrr(idesc->id_number, "BAD INODE NUMBER FOR '..'");
			dirp->d_ino = idesc->id_parent;
D 63
			ret |= dofix(idesc);
E 63
I 63
			if (reply("FIX") == 1)
				ret |= ALTERED;
E 63
		}
		goto chk2;
	}
	direrr(idesc->id_number, "MISSING '..'");
D 66
	if (dirp->d_ino != 0) {
E 66
I 66
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, ".") != 0) {
E 66
		pfatal("CANNOT FIX, SECOND ENTRY IN DIRECTORY CONTAINS %s\n",
			dirp->d_name);
	} else if (dirp->d_reclen < entrysize) {
		pfatal("CANNOT FIX, INSUFFICIENT SPACE TO ADD '..'\n");
	} else {
		proto.d_reclen = dirp->d_reclen;
		bcopy((char *)&proto, (char *)dirp, entrysize);
D 63
		ret |= dofix(idesc);
E 63
I 63
		if (reply("FIX") == 1)
			ret |= ALTERED;
E 63
	}
chk2:
	if (dirp->d_ino == 0)
		return (ret|KEEPON);
D 66
	if (idesc->id_entryno >= 2 &&
	    dirp->d_namlen <= 2 &&
	    dirp->d_name[0] == '.') {
E 66
I 66
	if (dirp->d_namlen <= 2 &&
	    dirp->d_name[0] == '.' &&
	    idesc->id_entryno >= 2) {
E 66
		if (dirp->d_namlen == 1) {
			direrr(idesc->id_number, "EXTRA '.' ENTRY");
			dirp->d_ino = 0;
D 63
			return (KEEPON | dofix(idesc));
E 63
I 63
			if (reply("FIX") == 1)
				ret |= ALTERED;
			return (KEEPON | ret);
E 63
		}
		if (dirp->d_name[1] == '.') {
			direrr(idesc->id_number, "EXTRA '..' ENTRY");
			dirp->d_ino = 0;
D 63
			return (KEEPON | dofix(idesc));
E 63
I 63
			if (reply("FIX") == 1)
				ret |= ALTERED;
			return (KEEPON | ret);
E 63
		}
	}
	curpathloc = pathp;
	*pathp++ = '/';
E 61
I 56
	if (pathp + dirp->d_namlen >= endpathname) {
		*pathp = '\0';
		errexit("NAME TOO LONG %s%s\n", pathname, dirp->d_name);
	}
E 56
D 61
	for (p = dirp->d_name; p < &dirp->d_name[MAXNAMLEN]; )
		if ((*pathp++ = *p++) == 0) {
			--pathp;
			break;
		}
	*pathp = 0;
E 61
I 61
	bcopy(dirp->d_name, pathp, dirp->d_namlen + 1);
	pathp += dirp->d_namlen;
	idesc->id_entryno++;
E 61
	n = 0;
D 61
	if (inum > imax || inum <= 0)
		n = direrr("I OUT OF RANGE");
	else {
E 61
I 61
	if (dirp->d_ino > imax || dirp->d_ino <= 0) {
		direrr(dirp->d_ino, "I OUT OF RANGE");
		n = reply("REMOVE");
	} else {
E 61
again:
D 45
		switch (getstate()) {
E 45
I 45
D 61
		switch (statemap[inum]) {
E 61
I 61
		switch (statemap[dirp->d_ino]) {
E 61
E 45
		case USTATE:
D 61
			n = direrr("UNALLOCATED");
E 61
I 61
			direrr(dirp->d_ino, "UNALLOCATED");
			n = reply("REMOVE");
E 61
			break;

		case CLEAR:
D 61
			if ((n = direrr("DUP/BAD")) == 1)
E 61
I 61
			direrr(dirp->d_ino, "DUP/BAD");
			if ((n = reply("REMOVE")) == 1)
E 61
				break;
D 61
			if ((dp = ginode()) == NULL)
E 61
I 61
			if ((dp = ginode(dirp->d_ino)) == NULL)
E 61
				break;
D 45
			setstate(DIRCT ? DSTATE : FSTATE);
E 45
I 45
D 61
			statemap[inum] = DIRCT ? DSTATE : FSTATE;
E 61
I 61
			statemap[dirp->d_ino] = DIRCT ? DSTATE : FSTATE;
E 61
E 45
			goto again;

		case FSTATE:
D 45
			declncnt();
E 45
I 45
D 61
			lncntp[inum]--;
E 61
I 61
			lncntp[dirp->d_ino]--;
E 61
E 45
			break;

		case DSTATE:
D 45
			declncnt();
E 45
I 45
D 61
			lncntp[inum]--;
E 45
			descend();
E 61
I 61
			descend(idesc, dirp->d_ino);
			if (statemap[dirp->d_ino] != CLEAR) {
				lncntp[dirp->d_ino]--;
			} else {
				dirp->d_ino = 0;
				ret |= ALTERED;
			}
E 61
			break;
		}
	}
D 61
	pathp = thisname;
E 61
I 61
	pathp = curpathloc;
	*pathp = '\0';
E 61
	if (n == 0)
D 61
		return (KEEPON);
E 61
I 61
		return (ret|KEEPON);
E 61
	dirp->d_ino = 0;
D 61
	return (KEEPON|ALTERD);
E 61
I 61
	return (ret|KEEPON|ALTERED);
E 61
}

pass3()
{
D 61
	ino_t savino;
E 61
	register DINODE *dp;
I 61
	struct inodesc idesc;
	ino_t inumber, orphan;
I 64
	int loopcnt;
E 64
D 63
	int len;
E 63
E 61

E 44
D 61
	for (inum = ROOTINO; inum <= lastino; inum++) {
D 45
		if (getstate() == DSTATE) {
E 45
I 45
		if (statemap[inum] == DSTATE) {
E 45
			pfunc = findino;
E 61
I 61
	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = DATA;
	for (inumber = ROOTINO; inumber <= lastino; inumber++) {
		if (statemap[inumber] == DSTATE) {
I 62
			pathp = pathname;
			*pathp++ = '?';
			*pathp = '\0';
E 62
			idesc.id_func = findino;
E 61
			srchname = "..";
D 61
			savino = inum;
E 61
I 61
			idesc.id_parent = inumber;
I 64
			loopcnt = 0;
E 64
E 61
			do {
D 61
				orphan = inum;
				if ((dp = ginode()) == NULL)
E 61
I 61
				orphan = idesc.id_parent;
				if ((dp = ginode(orphan)) == NULL)
E 61
					break;
D 61
				filsize = dp->di_size;
				parentdir = 0;
				ckinode(dp, DATA);
				if ((inum = parentdir) == 0)
E 61
I 61
				idesc.id_parent = 0;
				idesc.id_filesize = dp->di_size;
				idesc.id_number = orphan;
				(void)ckinode(dp, &idesc);
				if (idesc.id_parent == 0)
E 61
					break;
I 64
				if (loopcnt >= sblock.fs_cstotal.cs_ndir)
					break;
				loopcnt++;
E 64
D 45
			} while (getstate() == DSTATE);
E 45
I 45
D 61
			} while (statemap[inum] == DSTATE);
E 45
			inum = orphan;
			if (linkup() == 1) {
				thisname = pathp = pathname;
				*pathp++ = '?';
D 44
				pfunc = pass2;
E 44
I 44
				pfunc = pass2check;
E 44
				descend();
E 61
I 61
			} while (statemap[idesc.id_parent] == DSTATE);
			if (linkup(orphan, idesc.id_parent) == 1) {
D 62
				pathp = pathname;
				*pathp++ = '/';
				len = strlen(lfname);
				bcopy(lfname, pathp, len + 1);
				pathp += len;
				*pathp++ = '/';
				pathp += lftempname(pathp, orphan);
E 62
				idesc.id_func = pass2check;
				idesc.id_number = lfdir;
				descend(&idesc, orphan);
E 61
			}
D 61
			inum = savino;
E 61
		}
	}
D 44
/* 4 */
	if (preen == 0)
		printf("** Phase 4 - Check Reference Counts\n");
	pfunc = pass4;
E 44
I 44
}

pass4()
{
D 61
	register int n;
	register ino_t *blp;
E 61
I 61
	register ino_t inumber, *blp;
	int n;
	struct inodesc idesc;
E 61

D 61
	pfunc = pass4check;
E 44
	for (inum = ROOTINO; inum <= lastino; inum++) {
D 45
		switch (getstate()) {
E 45
I 45
		switch (statemap[inum]) {
E 61
I 61
	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	idesc.id_func = pass4check;
	for (inumber = ROOTINO; inumber <= lastino; inumber++) {
		idesc.id_number = inumber;
		switch (statemap[inumber]) {
E 61
E 45

		case FSTATE:
D 45
			if (n = getlncnt())
E 45
I 45
D 61
			n = lncntp[inum];
E 61
I 61
			n = lncntp[inumber];
E 61
			if (n)
E 45
D 61
				adjust((short)n);
E 61
I 61
				adjust(&idesc, (short)n);
E 61
			else {
				for (blp = badlncnt;blp < badlnp; blp++)
D 61
					if (*blp == inum) {
						clri("UNREF", 1);
E 61
I 61
					if (*blp == inumber) {
						clri(&idesc, "UNREF", 1);
E 61
						break;
					}
			}
			break;

		case DSTATE:
D 61
			clri("UNREF", 1);
E 61
I 61
			clri(&idesc, "UNREF", 1);
E 61
			break;

		case CLEAR:
D 61
			clri("BAD/DUP", 1);
E 61
I 61
			clri(&idesc, "BAD/DUP", 1);
E 61
			break;
		}
	}
D 11
	if (imax - n_files != sblock.fs_nifree) {
E 11
I 11
D 15
	if (imax - n_files != sblock.fs_cstotal.cs_nifree) {
E 15
I 15
	if (imax - ROOTINO - n_files != sblock.fs_cstotal.cs_nifree) {
E 15
E 11
		pwarn("FREE INODE COUNT WRONG IN SUPERBLK");
		if (preen)
			printf(" (FIXED)\n");
		if (preen || reply("FIX") == 1) {
D 11
			sblock.fs_nifree = imax - n_files;
E 11
I 11
D 24
			sblock.fs_cstotal.cs_nifree = imax - n_files;
E 24
I 24
			sblock.fs_cstotal.cs_nifree = imax - ROOTINO - n_files;
E 24
E 11
			sbdirty();
		}
	}
	flush(&dfile, &fileblk);
I 44
}
E 44

D 44
/* 5 */
	if (preen == 0)
		printf("** Phase 5 - Check Cyl groups\n");
D 29
	copy(blkmap, freemap, (unsigned)bmapsz);
E 29
I 29
	copy(blockmap, freemap, (unsigned)bmapsz);
E 44
I 44
D 61
pass4check(blk, size)
	daddr_t blk;
E 61
I 61
pass4check(idesc)
	register struct inodesc *idesc;
E 61
{
	register daddr_t *dlp;
D 61
	int res = KEEPON;
E 61
I 61
	int nfrags, res = KEEPON;
	daddr_t blkno = idesc->id_blkno;
E 61

D 61
	for (; size > 0; blk++, size--) {
D 47
		if (outrange(blk))
E 47
I 47
		if (outrange(blk, 1))
E 61
I 61
	for (nfrags = idesc->id_numfrags; nfrags > 0; blkno++, nfrags--) {
		if (outrange(blkno, 1))
E 61
E 47
			res = SKIP;
D 61
		else if (getbmap(blk)) {
E 61
I 61
		else if (getbmap(blkno)) {
E 61
			for (dlp = duplist; dlp < enddup; dlp++)
D 61
				if (*dlp == blk) {
E 61
I 61
				if (*dlp == blkno) {
E 61
					*dlp = *--enddup;
					return (KEEPON);
				}
D 61
			clrbmap(blk);
E 61
I 61
			clrbmap(blkno);
E 61
			n_blks--;
		}
	}
	return (res);
}

pass5()
{
	register int c, n, i, b, d;
I 47
	short bo[MAXCPG][NRPOS];
	long botot[MAXCPG];
	long frsum[MAXFRAG];
	int blk;
	daddr_t cbase;
	int blockbits = (1<<sblock.fs_frag)-1;
E 47

D 53
	blkcpy((unsigned)bmapsz, blockmap, freemap);
E 53
I 53
	bcopy(blockmap, freemap, (unsigned)bmapsz);
E 53
E 44
E 29
	dupblk = 0;
D 19
	n_index = sblock.fs_ncg * (cgdmin(0, &sblock) - cgtod(0, &sblock));
E 19
I 19
	n_index = sblock.fs_ncg * (cgdmin(&sblock, 0) - cgtod(&sblock, 0));
E 19
D 6
	n_index += SBLOCK;	/* super-block and boot block */
	n_bad = -SBLOCK;	/* ... which appear (inaccurately) bad */
E 6
	for (c = 0; c < sblock.fs_ncg; c++) {
D 19
		daddr_t cbase = cgbase(c,&sblock);
E 19
I 19
D 47
		daddr_t cbase = cgbase(&sblock, c);
E 19
		short bo[MAXCPG][NRPOS];
I 18
		long botot[MAXCPG];
E 18
I 6
D 11
		short frsum[FRAG];
E 11
I 11
D 14
		long frsum[FRAG];
E 14
I 14
		long frsum[MAXFRAG];
E 14
E 11
		int blk;

E 6
D 18
		for (n = 0; n < sblock.fs_cpg; n++)
E 18
I 18
		for (n = 0; n < sblock.fs_cpg; n++) {
			botot[n] = 0;
E 18
			for (i = 0; i < NRPOS; i++)
				bo[n][i] = 0;
I 18
		}
E 18
I 6
D 14
		for (i = 0; i < FRAG; i++) {
E 14
I 14
D 44
		for (i = 0; i < sblock.fs_frag; i++) {
E 44
I 44
		for (i = 0; i < sblock.fs_frag; i++)
E 44
E 14
			frsum[i] = 0;
E 47
I 47
		cbase = cgbase(&sblock, c);
D 61
		bzero(botot, sizeof (botot));
		bzero(bo, sizeof (bo));
		bzero(frsum, sizeof (frsum));
E 61
I 61
		bzero((char *)botot, sizeof (botot));
		bzero((char *)bo, sizeof (bo));
		bzero((char *)frsum, sizeof (frsum));
E 61
E 47
D 44
		}
E 44
		/*
D 34
		 * need to account for the spare boot and super blocks
E 34
I 34
		 * need to account for the super blocks
E 34
		 * which appear (inaccurately) bad
		 */
E 6
D 19
		n_bad += cgtod(c, &sblock) - cbase;
		if (getblk(&cgblk, cgtod(c, &sblock), sblock.fs_cgsize) == 0)
E 19
I 19
D 34
		n_bad += cgtod(&sblock, c) - cbase;
E 34
I 34
		n_bad += cgtod(&sblock, c) - cgsblock(&sblock, c);
E 34
		if (getblk(&cgblk, cgtod(&sblock, c), sblock.fs_cgsize) == 0)
E 19
			continue;
I 34
D 47
		if (debug && cgrp.cg_magic != CG_MAGIC)
			printf("cg %d: bad magic number\n", c);
E 47
I 47
		if (cgrp.cg_magic != CG_MAGIC) {
D 61
			pfatal("cg %d: bad magic number\n", c);
			bzero((caddr_t)&cgrp, sblock.fs_cgsize);
E 61
I 61
			pfatal("CG %d: BAD MAGIC NUMBER\n", c);
			bzero((char *)&cgrp, (int)sblock.fs_cgsize);
E 61
		}
E 47
E 34
D 14
		for (b = 0; b < sblock.fs_fpg; b += FRAG) {
			if (isblock(cgrp.cg_free, b/FRAG)) {
				if (pass5(cbase+b, FRAG) == STOP)
E 14
I 14
		for (b = 0; b < sblock.fs_fpg; b += sblock.fs_frag) {
D 47
			if (isblock(&sblock, cgrp.cg_free, b/sblock.fs_frag)) {
E 47
I 47
			blk = blkmap(&sblock, cgrp.cg_free, b);
			if (blk == 0)
				continue;
			if (blk == blockbits) {
E 47
D 44
				if (pass5(cbase+b, sblock.fs_frag) == STOP)
E 44
I 44
				if (pass5check(cbase+b, sblock.fs_frag) == STOP)
E 44
E 14
					goto out5;
				/* this is clumsy ... */
D 14
				n_ffree -= FRAG;
E 14
I 14
				n_ffree -= sblock.fs_frag;
E 14
				n_bfree++;
I 18
				botot[cbtocylno(&sblock, b)]++;
E 18
D 14
				s = b * NSPF;
E 14
I 14
D 17
				s = b * NSPF(&sblock);
E 14
				bo[s/sblock.fs_spc]
				    [s%sblock.fs_nsect*NRPOS/sblock.fs_nsect]++;
E 17
I 17
				bo[cbtocylno(&sblock, b)]
				    [cbtorpos(&sblock, b)]++;
E 17
D 6
			} else
E 6
I 6
D 47
			} else {
E 6
D 14
				for (d = 0; d < FRAG; d++)
E 14
I 14
				for (d = 0; d < sblock.fs_frag; d++)
E 14
					if (isset(cgrp.cg_free, b+d))
D 44
						if (pass5(cbase+b+d,1) == STOP)
E 44
I 44
						if (pass5check(cbase+b+d,1) == STOP)
E 44
							goto out5;
I 6
				blk = ((cgrp.cg_free[b / NBBY] >> (b % NBBY)) &
D 14
				       (0xff >> (NBBY - FRAG)));
E 14
I 14
				       (0xff >> (NBBY - sblock.fs_frag)));
E 14
				if (blk != 0)
D 14
					fragacct(blk, frsum, 1);
E 14
I 14
					fragacct(&sblock, blk, frsum, 1);
E 47
I 47
				continue;
E 47
E 14
			}
I 47
			for (d = 0; d < sblock.fs_frag; d++)
				if ((blk & (1<<d)) &&
D 61
				    pass5check(cbase+b+d,1) == STOP)
E 61
I 61
				    pass5check(cbase + b + d, (long)1) == STOP)
E 61
					goto out5;
			fragacct(&sblock, blk, frsum, 1);
E 47
E 6
		}
I 6
D 14
		for (i = 0; i < FRAG; i++) {
E 14
I 14
D 47
		for (i = 0; i < sblock.fs_frag; i++) {
E 14
			if (cgrp.cg_frsum[i] != frsum[i]) {
D 19
				printf("cg[%d].cg_frsum[%d] have %d calc %d\n",
					c, i, cgrp.cg_frsum[i], frsum[i]);
E 19
I 19
				if (debug)
					printf("cg[%d].cg_frsum[%d] have %d calc %d\n",
					    c, i, cgrp.cg_frsum[i], frsum[i]);
E 19
				frsumbad++;
			}
E 47
I 47
D 61
		if (bcmp(cgrp.cg_frsum, frsum, sizeof (frsum))) {
E 61
I 61
		if (bcmp((char *)cgrp.cg_frsum, (char *)frsum, sizeof(frsum))) {
E 61
			if (debug)
			for (i = 0; i < sblock.fs_frag; i++)
				if (cgrp.cg_frsum[i] != frsum[i])
				printf("cg[%d].cg_frsum[%d] have %d calc %d\n",
				    c, i, cgrp.cg_frsum[i], frsum[i]);
			frsumbad++;
E 47
		}
E 6
D 18
		for (n = 0; n < sblock.fs_cpg; n++)
E 18
I 18
D 47
		for (n = 0; n < sblock.fs_cpg; n++) {
			if (botot[n] != cgrp.cg_btot[n]) {
D 19
				printf("cg[%d].cg_btot[%d] have %d calc %d\n",
				    c, n, cgrp.cg_btot[n], botot[n]);
E 19
I 19
				if (debug)
					printf("cg[%d].cg_btot[%d] have %d calc %d\n",
					    c, n, cgrp.cg_btot[n], botot[n]);
E 19
				offsumbad++;
			}
E 47
I 47
D 61
		if (bcmp(cgrp.cg_btot, botot, sizeof (botot))) {
E 61
I 61
		if (bcmp((char *)cgrp.cg_btot, (char *)botot, sizeof (botot))) {
E 61
			if (debug)
			for (n = 0; n < sblock.fs_cpg; n++)
				if (botot[n] != cgrp.cg_btot[n])
				printf("cg[%d].cg_btot[%d] have %d calc %d\n",
				    c, n, cgrp.cg_btot[n], botot[n]);
			offsumbad++;
		}
D 61
		if (bcmp(cgrp.cg_b, bo, sizeof (bo))) {
E 61
I 61
		if (bcmp((char *)cgrp.cg_b, (char *)bo, sizeof (bo))) {
E 61
			if (debug)
E 47
E 18
			for (i = 0; i < NRPOS; i++)
D 47
				if (bo[n][i] != cgrp.cg_b[n][i]) {
D 5
					printf("[%d][%d] have %d calc %d\n",
					    n, i, cgrp.cg_b[n][i], bo[n][i]);
E 5
I 5
D 19
					printf("cg[%d].cg_b[%d][%d] have %d calc %d\n",
					    c, n, i, cgrp.cg_b[n][i], bo[n][i]);
E 19
I 19
					if (debug)
						printf("cg[%d].cg_b[%d][%d] have %d calc %d\n",
						    c, n, i, cgrp.cg_b[n][i],
						    bo[n][i]);
E 19
E 5
					offsumbad++;
				}
E 47
I 47
				if (bo[n][i] != cgrp.cg_b[n][i])
				printf("cg[%d].cg_b[%d][%d] have %d calc %d\n",
				    c, n, i, cgrp.cg_b[n][i], bo[n][i]);
			offsumbad++;
E 47
I 18
		}
E 18
	}
out5:
	if (dupblk)
		pwarn("%d DUP BLKS IN BIT MAPS\n", dupblk);
	if (fixcg == 0) {
D 14
		if ((b = n_blks+n_ffree+FRAG*n_bfree+n_index+n_bad) != fmax) {
E 14
I 14
		if ((b = n_blks+n_ffree+sblock.fs_frag*n_bfree+n_index+n_bad) != fmax) {
E 14
			pwarn("%ld BLK(S) MISSING\n", fmax - b);
			fixcg = 1;
D 6
		} else if (inosumbad+offsumbad) {
			pwarn("SUMMARY INFORMATION %s%sBAD\n",
E 6
I 6
D 33
		} else if (inosumbad + offsumbad + frsumbad) {
			pwarn("SUMMARY INFORMATION %s%s%sBAD\n",
E 33
I 33
		} else if (inosumbad + offsumbad + frsumbad + sbsumbad) {
			pwarn("SUMMARY INFORMATION %s%s%s%sBAD\n",
E 33
E 6
			    inosumbad ? "(INODE FREE) " : "",
D 6
			    offsumbad ? "(BLOCK OFFSETS) " : "");
E 6
I 6
			    offsumbad ? "(BLOCK OFFSETS) " : "",
D 33
			    frsumbad ? "(FRAG SUMMARIES) " : "");
E 33
I 33
			    frsumbad ? "(FRAG SUMMARIES) " : "",
			    sbsumbad ? "(SUPER BLOCK SUMMARIES) " : "");
E 33
E 6
			fixcg = 1;
D 11
		} else if (n_ffree != sblock.fs_nffree ||
		    n_bfree != sblock.fs_nbfree) {
E 11
I 11
		} else if (n_ffree != sblock.fs_cstotal.cs_nffree ||
		    n_bfree != sblock.fs_cstotal.cs_nbfree) {
E 11
			pwarn("FREE BLK COUNT(S) WRONG IN SUPERBLK");
			if (preen)
				printf(" (FIXED)\n");
			if (preen || reply("FIX") == 1) {
D 11
				sblock.fs_nffree = n_ffree;
				sblock.fs_nbfree = n_bfree;
E 11
I 11
				sblock.fs_cstotal.cs_nffree = n_ffree;
				sblock.fs_cstotal.cs_nbfree = n_bfree;
E 11
				sbdirty();
			}
		}
	}
	if (fixcg) {
		pwarn("BAD CYLINDER GROUPS");
		if (preen)
			printf(" (SALVAGED)\n");
		else if (reply("SALVAGE") == 0)
			fixcg = 0;
	}
D 44

	if (fixcg) {
		if (preen == 0)
			printf("** Phase 6 - Salvage Cylinder Groups\n");
D 5
		sblock.fs_cs = (struct csum *)
		    calloc(sblock.fs_ncg, roundup(sizeof (struct csum), BSIZE));
E 5
I 5
D 9
		sblock.fs_cs = (struct csum *)calloc(1,
		    roundup(cssize(&sblock), BSIZE));
E 9
I 9
D 13
		for (i = 0; i < howmany(cssize(&sblock), BSIZE); i++) {
			sblock.fs_csp[i] = (struct csum *)calloc(1, BSIZE);
			getblk((char *)sblock.fs_csp[i],
			       csaddr(&sblock) + (i * FRAG), BSIZE);
		}
E 13
E 9
E 5
		makecg();
D 9
		for (i = 0; i < cssize(&sblock); i += BSIZE)
			bwrite(&dfile, ((char *)sblock.fs_cs) + i,
				csaddr(&sblock) + i / BSIZE, BSIZE);
E 9
I 9
D 13
		for (i = 0; i < howmany(cssize(&sblock), BSIZE); i++) {
			bwrite(&dfile, (char *)sblock.fs_csp[i],
			       csaddr(&sblock) + (i * FRAG), BSIZE);
		}
E 13
E 9
D 11
		n_ffree = sblock.fs_nffree;
		n_bfree = sblock.fs_nbfree;
E 11
I 11
		n_ffree = sblock.fs_cstotal.cs_nffree;
		n_bfree = sblock.fs_cstotal.cs_nbfree;
E 11
	}

	pwarn("%d files, %d used, %d free (%d frags, %d blocks)\n",
D 11
	    n_files, n_blks, n_ffree + FRAG * n_bfree, n_ffree, n_bfree);
E 11
I 11
D 14
	    n_files, n_blks - howmany(sblock.fs_cssize, BSIZE) * FRAG,
	    n_ffree + FRAG * n_bfree, n_ffree, n_bfree);
E 14
I 14
D 34
	    n_files, n_blks - howmany(sblock.fs_cssize, sblock.fs_bsize) * sblock.fs_frag,
E 34
I 34
	    n_files, n_blks - howmany(sblock.fs_cssize, sblock.fs_fsize),
E 34
	    n_ffree + sblock.fs_frag * n_bfree, n_ffree, n_bfree);
E 14
E 11
	if (dfile.mod) {
		time(&sblock.fs_time);
		sbdirty();
	}
	ckfini();
D 40
	sync();
D 37
	if (dfile.mod && hotroot) {
		printf("\n***** BOOT UNIX (NO SYNC!) *****\n");
		exit(4);
	}
E 37
	if (dfile.mod && preen == 0)
		printf("\n***** FILE SYSTEM WAS MODIFIED *****\n");
E 40
D 29
	free(blkmap);
E 29
I 29
	free(blockmap);
E 29
	free(freemap);
	free(statemap);
	free(lncntp);
I 40
	if (dfile.mod)
D 41
		if (preen)
E 41
I 41
		if (preen) {
E 41
			printf("\n***** FILE SYSTEM WAS MODIFIED *****\n");
D 41
		else if (hotroot) {
E 41
I 41
			if (hotroot) {
				sync();
				exit(4);
			}
		} else if (hotroot) {
E 41
			printf("\n***** BOOT UNIX (NO SYNC!) *****\n");
			exit(4);
		}
	sync();
E 44
E 40
}

D 44
/* VARARGS1 */
error(s1, s2, s3, s4)
D 10
char *s1;
E 10
I 10
	char *s1;
E 44
I 44
pass5check(blk, size)
	daddr_t blk;
D 61
	int size;
E 61
I 61
	long size;
E 61
E 44
E 10
{
I 44
D 47
	int res = KEEPON;
E 47
E 44

D 44
	printf(s1, s2, s3, s4);
}

/* VARARGS1 */
errexit(s1, s2, s3, s4)
D 10
char *s1;
E 10
I 10
	char *s1;
E 10
{
	error(s1, s2, s3, s4);
	exit(8);
}

/*
 * An inconsistency occured which shouldn't during normal operations.
 * Die if preening, otw just printf.
 */
/* VARARGS1 */
pfatal(s, a1, a2, a3)
	char *s;
{

	if (preen) {
		printf("%s: ", devname);
		printf(s, a1, a2, a3);
		printf("\n");
		preendie();
E 44
I 44
D 47
	for (; size > 0; blk++, size--) {
		if (outrange(blk)) {
E 47
I 47
D 61
	if (outrange(blk, size)) {
E 61
I 61
	if (outrange(blk, (int)size)) {
E 61
		fixcg = 1;
		if (preen)
			pfatal("BAD BLOCKS IN BIT MAPS.");
		if (++badblk >= MAXBAD) {
			printf("EXCESSIVE BAD BLKS IN BIT MAPS.");
			if (reply("CONTINUE") == 0)
				errexit("");
			return (STOP);
		}
	}
	for (; size > 0; blk++, size--)
		if (getfmap(blk)) {
E 47
			fixcg = 1;
D 47
			if (preen)
				pfatal("BAD BLOCKS IN BIT MAPS.");
			if (++badblk >= MAXBAD) {
				printf("EXCESSIVE BAD BLKS IN BIT MAPS.");
				if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
		} else if (getfmap(blk)) {
			fixcg = 1;
E 47
			++dupblk;
		} else {
			n_ffree++;
			setfmap(blk);
		}
E 44
D 47
	}
D 44
	printf(s, a1, a2, a3);
E 44
I 44
	return (res);
E 47
I 47
	return (KEEPON);
E 47
E 44
}

D 44
preendie()
{

	printf("%s: UNEXPECTED INCONSISTENCY; RUN fsck MANUALLY.\n", devname);
	exit(8);
}

/*
 * Pwarn is like printf when not preening,
 * or a warning (preceded by filename) when preening.
 */
/* VARARGS1 */
D 37
pwarn(s, a1, a2, a3, a4, a5)
E 37
I 37
pwarn(s, a1, a2, a3, a4, a5, a6)
E 37
	char *s;
{

	if (preen)
		printf("%s: ", devname);
D 37
	printf(s, a1, a2, a3, a4, a5);
E 37
I 37
	printf(s, a1, a2, a3, a4, a5, a6);
E 37
}

E 44
D 61
ckinode(dp, flg)
E 61
I 61
ckinode(dp, idesc)
E 61
	DINODE *dp;
D 61
	register flg;
E 61
I 61
	register struct inodesc *idesc;
E 61
{
	register daddr_t *ap;
D 61
	register ret;
D 25
	int (*func)(), n, ndb, size;
E 25
I 25
	int (*func)(), n, ndb, size, offset;
I 36
	ino_t number = inum;
E 61
I 61
	int ret, n, ndb, offset;
E 61
	DINODE dino;
E 36
E 25
D 2
	daddr_t	iaddrs[NDADDR+NIADDR];
E 2

	if (SPECIAL)
		return (KEEPON);
I 36
	dino = *dp;
E 36
D 2
	l3tol(iaddrs, dp->di_addr, NDADDR+NIADDR);
E 2
D 61
	func = (flg == ADDR) ? pfunc : dirscan;
E 61
I 61
	idesc->id_fix = DONTKNOW;
	idesc->id_entryno = 0;
E 61
D 14
	ndb = howmany(dp->di_size, BSIZE);
E 14
I 14
D 36
	ndb = howmany(dp->di_size, sblock.fs_bsize);
E 14
D 2
	for (ap = iaddrs; ap < &iaddrs[NDADDR]; ap++) {
E 2
I 2
D 5
	for (ap = dp->di_db; ap < &dp->di_db[NDADDR]; ap++) {
E 5
I 5
	for (ap = &dp->di_db[0]; ap < &dp->di_db[NDADDR]; ap++) {
E 5
E 2
D 14
		if (--ndb == 0 && (dp->di_size&BMASK))
			size = howmany(dp->di_size&BMASK, FSIZE);
E 14
I 14
D 25
		if (--ndb == 0 && (dp->di_size % sblock.fs_bsize))
			size = howmany(dp->di_size % sblock.fs_bsize, sblock.fs_fsize);
E 25
I 25
		if (--ndb == 0 && (offset = blkoff(&sblock, dp->di_size)) != 0)
E 36
I 36
	ndb = howmany(dino.di_size, sblock.fs_bsize);
	for (ap = &dino.di_db[0]; ap < &dino.di_db[NDADDR]; ap++) {
		if (--ndb == 0 && (offset = blkoff(&sblock, dino.di_size)) != 0)
E 36
D 61
			size = numfrags(&sblock, fragroundup(&sblock, offset));
E 61
I 61
			idesc->id_numfrags =
				numfrags(&sblock, fragroundup(&sblock, offset));
E 61
E 25
E 14
		else
D 14
			size = FRAG;
E 14
I 14
D 61
			size = sblock.fs_frag;
I 36
		dnum = number;
E 36
E 14
		if (*ap && (ret = (*func)(*ap, size)) & STOP)
E 61
I 61
			idesc->id_numfrags = sblock.fs_frag;
		if (*ap == 0)
			continue;
		idesc->id_blkno = *ap;
		if (idesc->id_type == ADDR)
			ret = (*idesc->id_func)(idesc);
		else
			ret = dirscan(idesc);
		if (ret & STOP)
E 61
			return (ret);
	}
I 61
	idesc->id_numfrags = sblock.fs_frag;
E 61
D 5
	for (n = 1; n <= 2; n++) {
		if (*ap && (ret = iblock(*ap, n, flg, dp->di_size)) & STOP)
E 5
I 5
D 36
	for (ap = &dp->di_ib[0], n = 1; n <= 2; ap++, n++) {
D 14
		if (*ap && (ret = iblock(*ap, n, flg, dp->di_size - BSIZE * NDADDR)) & STOP)
E 14
I 14
		if (*ap && (ret = iblock(*ap, n, flg, dp->di_size - sblock.fs_bsize * NDADDR)) & STOP)
E 36
I 36
	for (ap = &dino.di_ib[0], n = 1; n <= 2; ap++, n++) {
D 61
		dnum = number;
E 61
D 44
		if (*ap && (ret = iblock(*ap, n, flg, dino.di_size - sblock.fs_bsize * NDADDR)) & STOP)
E 36
E 14
E 5
			return (ret);
E 44
I 44
		if (*ap) {
D 61
			ret = iblock(*ap, n, flg,
			    dino.di_size - sblock.fs_bsize * NDADDR);
E 61
I 61
			idesc->id_blkno = *ap;
			ret = iblock(idesc, n,
				dino.di_size - sblock.fs_bsize * NDADDR);
E 61
			if (ret & STOP)
				return (ret);
		}
E 44
D 5
		ap++;
E 5
	}
	return (KEEPON);
}

D 61
iblock(blk, ilevel, flg, isize)
	daddr_t blk;
E 61
I 61
iblock(idesc, ilevel, isize)
	struct inodesc *idesc;
E 61
	register ilevel;
D 61
	int isize;
E 61
I 61
	long isize;
E 61
{
	register daddr_t *ap;
	register daddr_t *aplim;
D 5
	register n;
E 5
I 5
D 61
	register int i, n;
E 5
	int (*func)(), nif;
E 61
I 61
	int i, n, (*func)(), nif;
E 61
	BUFAREA ib;

D 5
	nif = howmany(isize - NDADDR*BSIZE, NINDIR / FRAG * BSIZE);
	if (nif > FRAG || ilevel > 1)
		nif = FRAG;
E 5
D 61
	if (flg == ADDR) {
		func = pfunc;
D 5
		if (((n = (*func)(blk, nif)) & KEEPON) == 0)
E 5
I 5
D 14
		if (((n = (*func)(blk, FRAG)) & KEEPON) == 0)
E 14
I 14
		if (((n = (*func)(blk, sblock.fs_frag)) & KEEPON) == 0)
E 61
I 61
	if (idesc->id_type == ADDR) {
		func = idesc->id_func;
		if (((n = (*func)(idesc)) & KEEPON) == 0)
E 61
E 14
E 5
			return (n);
	} else
		func = dirscan;
D 47
	if (outrange(blk))		/* protect thyself */
E 47
I 47
D 61
	if (outrange(blk, sblock.fs_frag))		/* protect thyself */
E 61
I 61
	if (outrange(idesc->id_blkno, idesc->id_numfrags)) /* protect thyself */
E 61
E 47
		return (SKIP);
	initbarea(&ib);
D 5
	if (getblk(&ib, blk, nif * FSIZE) == NULL)
E 5
I 5
D 14
	if (getblk(&ib, blk, BSIZE) == NULL)
E 14
I 14
D 61
	if (getblk(&ib, blk, sblock.fs_bsize) == NULL)
E 61
I 61
	if (getblk(&ib, idesc->id_blkno, sblock.fs_bsize) == NULL)
E 61
E 14
E 5
		return (SKIP);
	ilevel--;
D 5
	aplim = & ib.b_un.b_indir[NINDIR*nif/FRAG];
	for (ap = ib.b_un.b_indir; ap < aplim; ap++)
E 5
I 5
	if (ilevel == 0) {
D 14
		nif = isize / BSIZE + 1;
E 14
I 14
D 25
		nif = isize / sblock.fs_bsize + 1;
E 25
I 25
		nif = lblkno(&sblock, isize) + 1;
E 25
E 14
	} else /* ilevel == 1 */ {
D 14
		nif = isize / (BSIZE * NINDIR) + 1;
E 14
I 14
		nif = isize / (sblock.fs_bsize * NINDIR(&sblock)) + 1;
E 14
	}
D 14
	if (nif > NINDIR)
		nif = NINDIR;
E 14
I 14
	if (nif > NINDIR(&sblock))
		nif = NINDIR(&sblock);
E 14
D 44
	aplim = & ib.b_un.b_indir[nif];
E 44
I 44
	aplim = &ib.b_un.b_indir[nif];
E 44
	for (ap = ib.b_un.b_indir, i = 1; ap < aplim; ap++, i++)
E 5
		if (*ap) {
I 61
			idesc->id_blkno = *ap;
E 61
			if (ilevel > 0)
D 5
				n = iblock(*ap, ilevel, flg, BSIZE);
E 5
I 5
D 14
				n = iblock(*ap, ilevel, flg, isize - i * NINDIR * BSIZE);
E 14
I 14
D 44
				n = iblock(*ap, ilevel, flg, isize - i * NINDIR(&sblock) * sblock.fs_bsize);
E 44
I 44
D 61
				n = iblock(*ap, ilevel, flg,
E 61
I 61
				n = iblock(idesc, ilevel,
E 61
				    isize - i*NINDIR(&sblock)*sblock.fs_bsize);
E 44
E 14
E 5
			else
D 5
				n = (*func)(*ap, BSIZE);
E 5
I 5
D 14
				n = (*func)(*ap, FRAG);
E 14
I 14
D 61
				n = (*func)(*ap, sblock.fs_frag);
E 61
I 61
				n = (*func)(idesc);
E 61
E 14
E 5
			if (n & STOP)
				return (n);
		}
	return (KEEPON);
}

D 44
pass1(blk, size)
	daddr_t blk;
	int size;
{
	register daddr_t *dlp;
	int res = KEEPON;

	for (; size > 0; blk++, size--) {
		if (outrange(blk)) {
			blkerr("BAD", blk);
			if (++badblk >= MAXBAD) {
D 41
				printf("EXCESSIVE BAD BLKS I=%u", inum);
				if (reply("CONTINUE") == 0)
E 41
I 41
				pwarn("EXCESSIVE BAD BLKS I=%u", inum);
				if (preen)
					printf(" (SKIPPING)\n");
				else if (reply("CONTINUE") == 0)
E 41
					errexit("");
				return (STOP);
			}
			res = SKIP;
		} else if (getbmap(blk)) {
			blkerr("DUP", blk);
			if (++dupblk >= MAXDUP) {
D 41
				printf("EXCESSIVE DUP BLKS I=%u", inum);
				if (reply("CONTINUE") == 0)
E 41
I 41
				pwarn("EXCESSIVE DUP BLKS I=%u", inum);
				if (preen)
					printf(" (SKIPPING)\n");
				else if (reply("CONTINUE") == 0)
E 41
					errexit("");
				return (STOP);
			}
			if (enddup >= &duplist[DUPTBLSIZE]) {
D 41
				printf("DUP TABLE OVERFLOW.");
E 41
I 41
				pfatal("DUP TABLE OVERFLOW.");
E 41
				if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
			for (dlp = duplist; dlp < muldup; dlp++)
				if (*dlp == blk) {
					*enddup++ = blk;
					break;
				}
			if (dlp >= muldup) {
				*enddup++ = *muldup;
				*muldup++ = blk;
			}
		} else {
			n_blks++;
			setbmap(blk);
		}
		filsize++;
	}
	return (res);
}

pass1b(blk, size)
	daddr_t blk;
	int size;
{
	register daddr_t *dlp;
	int res = KEEPON;

	for (; size > 0; blk++, size--) {
		if (outrange(blk))
			res = SKIP;
		for (dlp = duplist; dlp < muldup; dlp++)
			if (*dlp == blk) {
				blkerr("DUP", blk);
				*dlp = *--muldup;
				*muldup = blk;
				if (muldup == duplist)
					return (STOP);
			}
	}
	return (res);
}

pass2(dirp)
	register DIRECT *dirp;
{
	register char *p;
	register n;
	DINODE *dp;

	if ((inum = dirp->d_ino) == 0)
		return (KEEPON);
	thisname = pathp;
D 22
	for (p = dirp->d_name; p < &dirp->d_name[DIRSIZ]; )
E 22
I 22
	for (p = dirp->d_name; p < &dirp->d_name[MAXNAMLEN]; )
E 22
		if ((*pathp++ = *p++) == 0) {
			--pathp;
			break;
		}
	*pathp = 0;
	n = 0;
D 10
	if (inum > imax || inum < ROOTINO)
E 10
I 10
	if (inum > imax || inum <= 0)
E 10
		n = direrr("I OUT OF RANGE");
	else {
again:
		switch (getstate()) {
		case USTATE:
			n = direrr("UNALLOCATED");
			break;

		case CLEAR:
			if ((n = direrr("DUP/BAD")) == 1)
				break;
			if ((dp = ginode()) == NULL)
				break;
D 22
			setstate(DIR ? DSTATE : FSTATE);
E 22
I 22
			setstate(DIRCT ? DSTATE : FSTATE);
E 22
			goto again;

		case FSTATE:
			declncnt();
			break;

		case DSTATE:
			declncnt();
			descend();
			break;
		}
	}
	pathp = thisname;
	if (n == 0)
		return (KEEPON);
	dirp->d_ino = 0;
	return (KEEPON|ALTERD);
}

pass4(blk, size)
D 10
daddr_t blk;
E 10
I 10
	daddr_t blk;
E 10
{
	register daddr_t *dlp;
	int res = KEEPON;

	for (; size > 0; blk++, size--) {
		if (outrange(blk))
			res = SKIP;
		else if (getbmap(blk)) {
			for (dlp = duplist; dlp < enddup; dlp++)
				if (*dlp == blk) {
					*dlp = *--enddup;
					return (KEEPON);
				}
			clrbmap(blk);
			n_blks--;
		}
	}
	return (res);
}

pass5(blk, size)
	daddr_t blk;
	int size;
{
	int res = KEEPON;

	for (; size > 0; blk++, size--) {
		if (outrange(blk)) {
			fixcg = 1;
D 49
			if (preen)
				pfatal("BAD BLOCKS IN BIT MAPS.");
			if (++badblk >= MAXBAD) {
				printf("EXCESSIVE BAD BLKS IN BIT MAPS.");
				if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
E 49
I 49
D 50
			++badblk;
E 49
		} else if (getfmap(blk)) {
			fixcg = 1;
I 41
D 43
D 49
			if (preen)
				pfatal("DUP BLKS IN BIT MAPS.");
E 41
			if (++dupblk >= DUPTBLSIZE) {
				printf("EXCESSIVE DUP BLKS IN BIT MAPS.");
				if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
E 49
I 49
			++dupblk;
E 50
E 49
E 43
I 43
			++dupblk;
E 43
		} else {
			n_ffree++;
			setfmap(blk);
		}
	}
	return (res);
}

E 44
D 47
outrange(blk)
E 47
I 47
outrange(blk, cnt)
E 47
	daddr_t blk;
I 47
	int cnt;
E 47
{
	register int c;

D 19
	c = dtog(blk, &sblock);
D 5
	if (blk >= fmax || blk < cgdmin(c, &sblock))
E 5
I 5
	if (blk >= fmax || blk < cgdmin(c, &sblock)) {
E 19
I 19
D 47
	c = dtog(&sblock, blk);
D 34
	if (blk >= fmax || blk < cgdmin(&sblock, c)) {
E 34
I 34
	if ((unsigned)blk >= fmax) {
E 47
I 47
	if ((unsigned)(blk+cnt) > fmax)
E 47
E 34
E 19
E 5
		return (1);
I 47
	c = dtog(&sblock, blk);
	if (blk < cgdmin(&sblock, c)) {
		if ((blk+cnt) > cgsblock(&sblock, c)) {
			if (debug) {
				printf("blk %d < cgdmin %d;",
				    blk, cgdmin(&sblock, c));
				printf(" blk+cnt %d > cgsbase %d\n",
				    blk+cnt, cgsblock(&sblock, c));
			}
			return (1);
		}
	} else {
		if ((blk+cnt) > cgbase(&sblock, c+1)) {
			if (debug)  {
				printf("blk %d >= cgdmin %d;",
				    blk, cgdmin(&sblock, c));
				printf(" blk+cnt %d > sblock.fs_fpg %d\n",
				    blk+cnt, sblock.fs_fpg);
			}
			return (1);
		}
E 47
I 5
	}
E 5
	return (0);
}

D 61
blkerr(s, blk)
	daddr_t blk;
E 61
I 61
blkerr(ino, s, blk)
	ino_t ino;
E 61
	char *s;
I 61
	daddr_t blk;
E 61
{
I 45

E 45
D 61
	pfatal("%ld %s I=%u", blk, s, inum);
E 61
I 61
	pfatal("%ld %s I=%u", blk, s, ino);
E 61
	printf("\n");
D 45
	setstate(CLEAR);	/* mark for possible clearing */
E 45
I 45
D 61
	statemap[inum] = CLEAR;
E 61
I 61
	statemap[ino] = CLEAR;
E 61
E 45
}

D 61
descend()
E 61
I 61
descend(parentino, inumber)
	struct inodesc *parentino;
	ino_t inumber;
E 61
{
	register DINODE *dp;
D 61
	register char *savname;
	off_t savsize;
E 61
I 61
	struct inodesc curino;
E 61

D 45
	setstate(FSTATE);
E 45
I 45
D 61
	statemap[inum] = FSTATE;
E 45
	if ((dp = ginode()) == NULL)
E 61
I 61
	bzero((char *)&curino, sizeof(struct inodesc));
	statemap[inumber] = FSTATE;
	if ((dp = ginode(inumber)) == NULL)
E 61
		return;
D 61
	savname = thisname;
	*pathp++ = '/';
	savsize = filsize;
	filsize = dp->di_size;
	ckinode(dp, DATA);
	thisname = savname;
	*--pathp = 0;
	filsize = savsize;
E 61
I 61
	if (dp->di_size == 0) {
		direrr(inumber, "ZERO LENGTH DIRECTORY");
		if (reply("REMOVE") == 1)
			statemap[inumber] = CLEAR;
		return;
	}
	if (dp->di_size < MINDIRSIZE) {
		direrr(inumber, "DIRECTORY TOO SHORT");
		dp->di_size = MINDIRSIZE;
		if (reply("FIX") == 1)
			inodirty();
	}
	curino.id_type = DATA;
	curino.id_func = parentino->id_func;
	curino.id_parent = parentino->id_number;
	curino.id_number = inumber;
	curino.id_filesize = dp->di_size;
	(void)ckinode(dp, &curino);
E 61
}

I 22
D 61
struct dirstuff {
	int loc;
	int blkno;
	int blksiz;
I 36
	ino_t number;
I 37
D 38
	int fix;
E 38
I 38
	enum {DONTKNOW, NOFIX, FIX} fix;
E 38
E 37
E 36
};

E 22
dirscan(blk, nf)
D 10
daddr_t blk;
int nf;
E 10
I 10
	daddr_t blk;
	int nf;
E 61
I 61
dirscan(idesc)
	register struct inodesc *idesc;
E 61
E 10
{
D 22
	register DIRECT *dirp;
	register DIRECT *edirp;
	register char *p1, *p2;
	register n;
E 22
I 22
	register DIRECT *dp;
E 22
D 26
	DIRECT direntry;
E 26
I 22
D 61
	struct dirstuff dirp;
D 26
	int blksiz, n;
E 26
I 26
	int blksiz, dsize, n;
E 61
I 61
	int dsize, n;
	long blksiz;
E 61
	char dbuf[DIRBLKSIZ];
E 26
E 22

D 47
	if (outrange(blk)) {
E 47
I 47
D 61
	if (outrange(blk, 1)) {
E 47
D 14
		filsize -= BSIZE;
E 14
I 14
		filsize -= sblock.fs_bsize;
E 61
I 61
	if (idesc->id_type != DATA)
		errexit("wrong type to dirscan %d\n", idesc->id_type);
	blksiz = idesc->id_numfrags * sblock.fs_fsize;
	if (outrange(idesc->id_blkno, idesc->id_numfrags)) {
		idesc->id_filesize -= blksiz;
E 61
E 14
		return (SKIP);
	}
D 14
	edirp = &dirblk.b_dir[NDIRECT*nf/FRAG];
E 14
I 14
D 22
	edirp = &dirblk.b_dir[NDIRECT(&sblock)*nf/sblock.fs_frag];
E 14
	for (dirp = dirblk.b_dir; dirp < edirp &&
		filsize > 0; dirp++, filsize -= sizeof(DIRECT)) {
D 14
		if (getblk(&fileblk, blk, nf * FSIZE) == NULL) {
			filsize -= (&dirblk.b_dir[NDIRECT]-dirp)*sizeof(DIRECT);
E 14
I 14
		if (getblk(&fileblk, blk, nf * sblock.fs_fsize) == NULL) {
			filsize -= (&dirblk.b_dir[NDIRECT(&sblock)]-dirp)*sizeof(DIRECT);
E 14
			return (SKIP);
		}
		p1 = &dirp->d_name[DIRSIZ];
		p2 = &direntry.d_name[DIRSIZ];
		while (p1 > (char *)dirp)
			*--p2 = *--p1;
E 22
I 22
D 61
	blksiz = nf * sblock.fs_fsize;
	dirp.loc = 0;
	dirp.blkno = blk;
	dirp.blksiz = blksiz;
I 36
D 37
	dirp.number = dnum;
E 37
I 37
	if (dirp.number != dnum) {
		dirp.number = dnum;
D 38
		dirp.fix = 0;
E 38
I 38
		dirp.fix = DONTKNOW;
E 38
	}
E 37
E 36
	for (dp = readdir(&dirp); dp != NULL; dp = readdir(&dirp)) {
E 61
I 61
	idesc->id_loc = 0;
	for (dp = fsck_readdir(idesc); dp != NULL; dp = fsck_readdir(idesc)) {
E 61
D 23
		printf("got %s ino %d\n", dp->d_name, dp->d_ino);
E 23
D 26
		copy(dp, &direntry, DIRSIZ(dp));
E 22
		if ((n = (*pfunc)(&direntry)) & ALTERD) {
E 26
I 26
		dsize = dp->d_reclen;
D 44
		copy(dp, dbuf, dsize);
E 44
I 44
D 61
		bcopy(dp, dbuf, dsize);
E 44
		if ((n = (*pfunc)(dbuf)) & ALTERD) {
E 26
D 14
			if (getblk(&fileblk, blk, nf * FSIZE) != NULL) {
E 14
I 14
D 22
			if (getblk(&fileblk, blk, nf * sblock.fs_fsize) != NULL) {
E 14
				p1 = &dirp->d_name[DIRSIZ];
				p2 = &direntry.d_name[DIRSIZ];
				while (p1 > (char *)dirp)
					*--p1 = *--p2;
E 22
I 22
			if (getblk(&fileblk, blk, blksiz) != NULL) {
D 26
				copy(&direntry, dp, DIRSIZ(&direntry));
E 26
I 26
D 44
				copy(dbuf, dp, dsize);
E 44
I 44
				bcopy(dbuf, dp, dsize);
E 61
I 61
		bcopy((char *)dp, dbuf, dsize);
		idesc->id_dirp = (DIRECT *)dbuf;
		if ((n = (*idesc->id_func)(idesc)) & ALTERED) {
			if (getblk(&fileblk, idesc->id_blkno, blksiz) != NULL) {
				bcopy(dbuf, (char *)dp, dsize);
E 61
E 44
E 26
E 22
I 10
				dirty(&fileblk);
E 10
				sbdirty();
			} else
D 61
				n &= ~ALTERD;
E 61
I 61
				n &= ~ALTERED;
E 61
		}
D 22
		if (n & STOP)
E 22
I 22
		if (n & STOP) 
E 22
			return (n);
	}
D 61
	return (filsize > 0 ? KEEPON : STOP);
E 61
I 61
	return (idesc->id_filesize > 0 ? KEEPON : STOP);
E 61
}

I 22
/*
D 23
 * read an old stlye directory entry and present it as a new one
 */
#define	ODIRSIZ	14

struct	olddirect {
	ino_t	d_ino;
	char	d_name[ODIRSIZ];
	char	d_spare[14];
};

/*
E 23
 * get next entry in a directory.
 */
DIRECT *
D 61
readdir(dirp)
	register struct dirstuff *dirp;
E 61
I 61
fsck_readdir(idesc)
	register struct inodesc *idesc;
E 61
{
D 23
	register struct olddirect *dp;
	static DIRECT dir;
E 23
I 23
D 26
	register DIRECT *dp;
E 26
I 26
	register DIRECT *dp, *ndp;
I 37
D 61
	long size;
E 61
I 61
	long size, blksiz;
E 61
E 37
E 26
E 23

D 61
	if (getblk(&fileblk, dirp->blkno, dirp->blksiz) == NULL) {
		filsize -= dirp->blksiz - dirp->loc;
E 61
I 61
	blksiz = idesc->id_numfrags * sblock.fs_fsize;
	if (getblk(&fileblk, idesc->id_blkno, blksiz) == NULL) {
		idesc->id_filesize -= blksiz - idesc->id_loc;
E 61
		return NULL;
	}
D 37
	for (;;) {
		if (filsize <= 0 || dirp->loc >= dirp->blksiz)
			return NULL;
E 37
I 37
D 61
	while (dirp->loc % DIRBLKSIZ == 0 && filsize > 0 &&
	    dirp->loc < dirp->blksiz) {
E 37
D 23
		dp = (struct olddirect *)(dirblk.b_buf + dirp->loc);
		dirp->loc += sizeof(struct olddirect);
		filsize -= sizeof(struct olddirect);
E 23
I 23
		dp = (DIRECT *)(dirblk.b_buf + dirp->loc);
D 37
		dirp->loc += dp->d_reclen;
		filsize -= dp->d_reclen;
E 23
D 26
		if (dp->d_ino == 0)
E 26
I 26
		ndp = (DIRECT *)(dirblk.b_buf + dirp->loc);
D 31
		if (dirp->loc < dirp->blksiz &&
E 31
I 31
		if (dirp->loc < dirp->blksiz && filsize > 0 &&
E 31
		    (ndp->d_ino > imax || ndp->d_namlen > MAXNAMLEN ||
		    ndp->d_reclen <= 0 || 
		    ndp->d_reclen > DIRBLKSIZ - (dirp->loc % DIRBLKSIZ))) {
E 37
I 37
	   	if (dp->d_ino < imax &&
		    dp->d_namlen <= MAXNAMLEN && dp->d_namlen >= 0 &&
		    dp->d_reclen > 0 && dp->d_reclen <= DIRBLKSIZ)
			break;
		dirp->loc += DIRBLKSIZ;
		filsize -= DIRBLKSIZ;
D 38
		if (dirp->fix == 0) {
E 38
I 38
		if (dirp->fix == DONTKNOW) {
E 38
E 37
D 36
			pwarn("DIRECTORY CORRUPTED");
E 36
I 36
D 54
			pwarn("DIRECTORY %D CORRUPTED", dirp->number);
E 54
I 54
			pfatal("DIRECTORY %D CORRUPTED", dirp->number);
E 54
E 36
D 37
			if (preen)
E 37
I 37
D 38
			dirp->fix = 1;
E 38
I 38
			dirp->fix = NOFIX;
E 38
D 54
			if (preen) {
E 37
				printf(" (SALVAGED)\n");
E 54
I 54
			if (reply("SALVAGE") != 0)
E 54
D 37
			else if (reply("SALVAGE") == 0) {
				dirp->loc +=
				    DIRBLKSIZ - (dirp->loc % DIRBLKSIZ);
				filsize -= DIRBLKSIZ - (dirp->loc % DIRBLKSIZ);
				return(dp);
			}
			dirp->loc -= dp->d_reclen;
			filsize += dp->d_reclen;
			dp->d_reclen = DIRBLKSIZ - (dirp->loc % DIRBLKSIZ);
			dirty(&fileblk);
E 37
I 37
D 38
				dirp->fix = 2;
E 38
I 38
				dirp->fix = FIX;
E 38
D 54
			} else if (reply("SALVAGE") != 0)
D 38
				dirp->fix = 2;
E 38
I 38
				dirp->fix = FIX;
E 54
E 38
		}
D 38
		if (dirp->fix < 2)
E 38
I 38
		if (dirp->fix != FIX)
E 38
E 37
E 26
			continue;
E 61
I 61
	if (idesc->id_loc % DIRBLKSIZ == 0 && idesc->id_filesize > 0 &&
	    idesc->id_loc < blksiz) {
		dp = (DIRECT *)(dirblk.b_buf + idesc->id_loc);
		if (dircheck(idesc, dp))
			goto dpok;
		idesc->id_loc += DIRBLKSIZ;
		idesc->id_filesize -= DIRBLKSIZ;
E 61
I 37
		dp->d_reclen = DIRBLKSIZ;
		dp->d_ino = 0;
		dp->d_namlen = 0;
D 61
		dirty(&fileblk);
E 61
I 61
		dp->d_name[0] = '\0';
D 63
		if (idesc->id_fix == DONTKNOW)
			direrr(idesc->id_number, "DIRECTORY CORRUPTED");
E 63
		if (dofix(idesc))
			dirty(&fileblk);
		return (dp);
E 61
	}
D 61
	if (filsize <= 0 || dirp->loc >= dirp->blksiz)
E 61
I 61
dpok:
	if (idesc->id_filesize <= 0 || idesc->id_loc >= blksiz)
E 61
		return NULL;
D 61
	dp = (DIRECT *)(dirblk.b_buf + dirp->loc);
	dirp->loc += dp->d_reclen;
	filsize -= dp->d_reclen;
	ndp = (DIRECT *)(dirblk.b_buf + dirp->loc);
D 42
	if (dirp->loc < dirp->blksiz && filsize > 0 &&
E 42
I 42
	if ((filsize <= 0 && dirp->loc % DIRBLKSIZ != 0) ||
	    (dirp->loc < dirp->blksiz && filsize > 0 &&
E 42
	    (ndp->d_ino >= imax ||
	    ndp->d_namlen > MAXNAMLEN || ndp->d_namlen < 0 ||
	    ndp->d_reclen <= 0 || 
D 42
	    ndp->d_reclen > DIRBLKSIZ - (dirp->loc % DIRBLKSIZ))) {
E 42
I 42
	    ndp->d_reclen > DIRBLKSIZ - (dirp->loc % DIRBLKSIZ)))) {
E 42
		size = DIRBLKSIZ - (dirp->loc % DIRBLKSIZ);
		dirp->loc += size;
		filsize -= size;
D 38
		if (dirp->fix == 0) {
E 38
I 38
		if (dirp->fix == DONTKNOW) {
E 38
D 54
			pwarn("DIRECTORY %D CORRUPTED", dirp->number);
E 54
I 54
			pfatal("DIRECTORY %D CORRUPTED", dirp->number);
E 54
D 38
			dirp->fix = 1;
E 38
I 38
			dirp->fix = NOFIX;
E 38
D 54
			if (preen) {
				printf(" (SALVAGED)\n");
D 38
				dirp->fix = 2;
E 38
I 38
				dirp->fix = FIX;
E 38
			} else if (reply("SALVAGE") != 0)
E 54
I 54
			if (reply("SALVAGE") != 0)
E 54
D 38
				dirp->fix = 2;
E 38
I 38
				dirp->fix = FIX;
E 38
E 37
I 26
		}
E 26
D 23
		dir.d_ino = dp->d_ino;
		strncpy(dir.d_name, dp->d_name, ODIRSIZ);
		dir.d_namlen = strlen(dir.d_name);
		return (&dir);
E 23
I 23
D 37
		return (dp);
E 37
I 37
D 38
		if (dirp->fix > 2) {
E 38
I 38
		if (dirp->fix == FIX) {
E 38
			dp->d_reclen += size;
E 61
I 61
	dp = (DIRECT *)(dirblk.b_buf + idesc->id_loc);
	idesc->id_loc += dp->d_reclen;
	idesc->id_filesize -= dp->d_reclen;
I 65
	if ((idesc->id_loc % DIRBLKSIZ) == 0)
		return (dp);
E 65
	ndp = (DIRECT *)(dirblk.b_buf + idesc->id_loc);
D 65
	if ((idesc->id_filesize <= 0 && idesc->id_loc % DIRBLKSIZ != 0) ||
	    (idesc->id_loc < blksiz && idesc->id_filesize > 0 &&
	     dircheck(idesc, ndp) == 0)) {
E 65
I 65
	if (idesc->id_loc < blksiz && idesc->id_filesize > 0 &&
	    dircheck(idesc, ndp) == 0) {
E 65
		size = DIRBLKSIZ - (idesc->id_loc % DIRBLKSIZ);
		dp->d_reclen += size;
		idesc->id_loc += size;
		idesc->id_filesize -= size;
D 63
		if (idesc->id_fix == DONTKNOW)
			direrr(idesc->id_number, "DIRECTORY CORRUPTED");
E 63
		if (dofix(idesc))
E 61
			dirty(&fileblk);
D 61
		}
E 61
E 37
E 23
	}
I 37
	return (dp);
E 37
}

E 22
D 61
direrr(s)
E 61
I 61
/*
 * Verify that a directory entry is valid.
 * This is a superset of the checks made in the kernel.
 */
dircheck(idesc, dp)
	struct inodesc *idesc;
	register DIRECT *dp;
{
	register int size;
	register char *cp;
	int spaceleft;

	size = DIRSIZ(dp);
	spaceleft = DIRBLKSIZ - (idesc->id_loc % DIRBLKSIZ);
	if (dp->d_ino < imax &&
	    dp->d_reclen != 0 &&
	    dp->d_reclen <= spaceleft &&
	    (dp->d_reclen & 0x3) == 0 &&
	    dp->d_reclen >= size &&
	    idesc->id_filesize >= size &&
	    dp->d_namlen <= MAXNAMLEN) {
		if (dp->d_ino == 0)
			return (1);
		for (cp = dp->d_name, size = 0; size < dp->d_namlen; size++)
			if (*cp == 0 || (*cp++ & 0200))
				return (0);
		if (*cp == 0)
			return (1);
	}
	return (0);
}

direrr(ino, s)
	ino_t ino;
E 61
D 10
char *s;
E 10
I 10
	char *s;
E 10
{
	register DINODE *dp;

	pwarn("%s ", s);
D 61
	pinode();
E 61
I 61
	pinode(ino);
E 61
	printf("\n");
D 61
	if ((dp = ginode()) != NULL && ftypeok(dp))
D 22
		pfatal("%s=%s", DIR?"DIR":"FILE", pathname);
E 22
I 22
		pfatal("%s=%s", DIRCT?"DIR":"FILE", pathname);
E 61
I 61
	if ((dp = ginode(ino)) != NULL && ftypeok(dp))
		pfatal("%s=%s\n", DIRCT?"DIR":"FILE", pathname);
E 61
E 22
	else
D 61
		pfatal("NAME=%s", pathname);
	return (reply("REMOVE"));
E 61
I 61
		pfatal("NAME=%s\n", pathname);
E 61
}

D 61
adjust(lcnt)
D 6
register short lcnt;
E 6
I 6
	register short lcnt;
E 61
I 61
adjust(idesc, lcnt)
	register struct inodesc *idesc;
	short lcnt;
E 61
E 6
{
	register DINODE *dp;

D 61
	if ((dp = ginode()) == NULL)
E 61
I 61
	if ((dp = ginode(idesc->id_number)) == NULL)
E 61
		return;
	if (dp->di_nlink == lcnt) {
D 61
		if (linkup() == 0)
			clri("UNREF", 0);
E 61
I 61
		if (linkup(idesc->id_number, (ino_t)0) == 0)
			clri(idesc, "UNREF", 0);
E 61
	}
	else {
		pwarn("LINK COUNT %s",
D 22
			(lfdir==inum)?lfname:(DIR?"DIR":"FILE"));
E 22
I 22
D 61
			(lfdir==inum)?lfname:(DIRCT?"DIR":"FILE"));
E 22
		pinode();
E 61
I 61
			(lfdir==idesc->id_number)?lfname:(DIRCT?"DIR":"FILE"));
		pinode(idesc->id_number);
E 61
		printf(" COUNT %d SHOULD BE %d",
			dp->di_nlink, dp->di_nlink-lcnt);
		if (preen) {
			if (lcnt < 0) {
				printf("\n");
				preendie();
			}
			printf(" (ADJUSTED)\n");
		}
		if (preen || reply("ADJUST") == 1) {
			dp->di_nlink -= lcnt;
			inodirty();
		}
	}
}

D 61
clri(s, flg)
E 61
I 61
clri(idesc, s, flg)
	register struct inodesc *idesc;
E 61
D 10
char *s;
E 10
I 10
	char *s;
I 61
	int flg;
E 61
E 10
{
	register DINODE *dp;

D 61
	if ((dp = ginode()) == NULL)
E 61
I 61
	if ((dp = ginode(idesc->id_number)) == NULL)
E 61
		return;
	if (flg == 1) {
D 22
		pwarn("%s %s", s, DIR?"DIR":"FILE");
E 22
I 22
		pwarn("%s %s", s, DIRCT?"DIR":"FILE");
E 22
D 61
		pinode();
E 61
I 61
		pinode(idesc->id_number);
E 61
	}
	if (preen || reply("CLEAR") == 1) {
		if (preen)
			printf(" (CLEARED)\n");
		n_files--;
D 44
		pfunc = pass4;
E 44
I 44
D 61
		pfunc = pass4check;
E 44
		ckinode(dp, ADDR);
E 61
I 61
		(void)ckinode(dp, idesc);
E 61
		zapino(dp);
I 6
D 45
		setstate(USTATE);
E 45
I 45
D 61
		statemap[inum] = USTATE;
E 61
I 61
		statemap[idesc->id_number] = USTATE;
E 61
E 45
E 6
		inodirty();
		inosumbad++;
	}
D 47
}

setup(dev)
D 10
char *dev;
E 10
I 10
	char *dev;
E 10
{
	dev_t rootdev;
D 12
	struct stat statb;
E 12
I 12
D 32
	struct ostat statb;
E 32
I 32
	struct stat statb;
E 32
E 12
	int super = bflag ? bflag : SBLOCK;
I 33
D 34
	int i;
E 34
I 34
	int i, j, size;
	int c, d, cgd;
E 34
E 33

	bflag = 0;
	if (stat("/", &statb) < 0)
		errexit("Can't stat root\n");
	rootdev = statb.st_dev;
	if (stat(dev, &statb) < 0) {
		error("Can't stat %s\n", dev);
		return (0);
	}
	rawflg = 0;
	if ((statb.st_mode & S_IFMT) == S_IFBLK)
		;
	else if ((statb.st_mode & S_IFMT) == S_IFCHR)
		rawflg++;
	else {
		if (reply("file is not a block or character device; OK") == 0)
			return (0);
	}
	if (rootdev == statb.st_rdev)
		hotroot++;
	if ((dfile.rfdes = open(dev, 0)) < 0) {
		error("Can't open %s\n", dev);
		return (0);
	}
	if (preen == 0)
		printf("** %s", dev);
	if (nflag || (dfile.wfdes = open(dev, 1)) < 0) {
		dfile.wfdes = -1;
		if (preen)
			pfatal("NO WRITE ACCESS");
		printf(" (NO WRITE)");
	}
	if (preen == 0)
		printf("\n");
D 6
	fixcg = 0; inosumbad = 0; offsumbad = 0;
E 6
I 6
D 33
	fixcg = 0; inosumbad = 0; offsumbad = 0; frsumbad = 0;
E 33
I 33
	fixcg = 0; inosumbad = 0; offsumbad = 0; frsumbad = 0; sbsumbad = 0;
E 33
E 6
	dfile.mod = 0;
	n_files = n_blks = n_ffree = n_bfree = 0;
	muldup = enddup = &duplist[0];
	badlnp = &badlncnt[0];
	lfdir = 0;
	rplyflag = 0;
	initbarea(&sblk);
	initbarea(&fileblk);
	initbarea(&inoblk);
	initbarea(&cgblk);
I 33
	/*
	 * Read in the super block and its summary info.
	 */
E 33
D 14
	if (getblk(&sblk, super, BSIZE) == NULL) {
		ckfini();
E 14
I 14
D 16
	if (bread(&dfile, &sblock, super, MAXBSIZE) == 0)
E 16
I 16
	if (bread(&dfile, &sblock, super, SBSIZE) == 0)
E 16
E 14
		return (0);
D 14
	}
E 14
D 6
	sblk.b_bno = SBLOCK;
E 6
I 6
	sblk.b_bno = super;
I 14
D 16
	sblk.b_size = MAXBSIZE;
E 16
I 16
	sblk.b_size = SBSIZE;
I 33
D 34
	for (i = 0; i < howmany(sblock.fs_cssize, sblock.fs_bsize); i++) {
		sblock.fs_csp[i] = (struct csum *)calloc(1, sblock.fs_bsize);
		bread(&dfile, (char *)sblock.fs_csp[i],
		    fsbtodb(&sblock, sblock.fs_csaddr + (i * sblock.fs_frag)),
		    sblock.fs_bsize);
	}
E 34
E 33
I 17
	/*
	 * run a few consistency checks of the super block
	 */
E 17
E 16
E 14
E 6
	if (sblock.fs_magic != FS_MAGIC)
		{ badsb("MAGIC NUMBER WRONG"); return (0); }
	if (sblock.fs_ncg < 1)
		{ badsb("NCG OUT OF RANGE"); return (0); }
	if (sblock.fs_cpg < 1 || sblock.fs_cpg > MAXCPG)
		{ badsb("CPG OUT OF RANGE"); return (0); }
	if (sblock.fs_nsect < 1)
		{ badsb("NSECT < 1"); return (0); }
	if (sblock.fs_ntrak < 1)
		{ badsb("NTRAK < 1"); return (0); }
D 14
	if (sblock.fs_ipg*sblock.fs_ncg > 65535 || sblock.fs_ipg%INOPB)
E 14
I 14
D 17
	if (sblock.fs_ipg*sblock.fs_ncg > 65535 || sblock.fs_ipg%INOPB(&sblock))
E 14
		{ badsb("TOO MANY INODES IMPLIED"); return (0); }
D 14
	if (sblock.fs_ipg/INOPF+IBLOCK >=
	    sblock.fs_cpg*sblock.fs_nsect*sblock.fs_ntrak/NSPF)
E 14
I 14
	if (sblock.fs_ipg/INOPF(&sblock)+IBLOCK(&sblock) >=
	    sblock.fs_cpg*sblock.fs_nsect*sblock.fs_ntrak/NSPF(&sblock))
E 17
I 17
	if (sblock.fs_spc != sblock.fs_nsect * sblock.fs_ntrak)
		{ badsb("SPC DOES NOT JIVE w/NTRAK*NSECT"); return (0); }
	if (sblock.fs_ipg % INOPB(&sblock))
		{ badsb("INODES NOT MULTIPLE OF A BLOCK"); return (0); }
D 19
	if (cgdmin(0, &sblock) >= sblock.fs_cpg * sblock.fs_spc / NSPF(&sblock))
E 19
I 19
	if (cgdmin(&sblock, 0) >= sblock.fs_cpg * sblock.fs_spc / NSPF(&sblock))
E 19
E 17
E 14
		{ badsb("IMPLIES MORE INODE THAN DATA BLOCKS"); return (0); }
D 17
/* THE FOLLOWING COULD BE CHECKED MORE CLOSELY... */
	if ((sblock.fs_ncg + 1) * sblock.fs_cpg < sblock.fs_ncyl ||
	    (sblock.fs_ncg - 1) * sblock.fs_cpg > sblock.fs_ncyl)
E 17
I 17
	if (sblock.fs_ncg * sblock.fs_cpg < sblock.fs_ncyl ||
	    (sblock.fs_ncg - 1) * sblock.fs_cpg >= sblock.fs_ncyl)
E 17
		{ badsb("NCYL DOES NOT JIVE WITH NCG*CPG"); return (0); }
D 14
	if (sblock.fs_fpg != sblock.fs_cpg * sblock.fs_spc / NSPF)
E 14
I 14
	if (sblock.fs_fpg != sblock.fs_cpg * sblock.fs_spc / NSPF(&sblock))
E 14
		{ badsb("FPG DOES NOT JIVE WITH CPG & SPC"); return (0); }
D 17
	if (sblock.fs_size <=
D 14
	    (sblock.fs_ncg-1)*sblock.fs_fpg+IBLOCK+sblock.fs_ipg/INOPF)
E 14
I 14
	    (sblock.fs_ncg-1)*sblock.fs_fpg+IBLOCK(&sblock)+sblock.fs_ipg/INOPF(&sblock))
E 17
I 17
	if (sblock.fs_size * NSPF(&sblock) <=
	    (sblock.fs_ncyl - 1) * sblock.fs_spc)
E 17
E 14
		{ badsb("SIZE PREPOSTEROUSLY SMALL"); return (0); }
D 14
	if (sblock.fs_size*NSPF >
E 14
I 14
D 17
	if (sblock.fs_size*NSPF(&sblock) >
E 14
	    (sblock.fs_ncg+2)*sblock.fs_cpg*sblock.fs_spc)
E 17
I 17
	if (sblock.fs_size * NSPF(&sblock) > sblock.fs_ncyl * sblock.fs_spc)
E 17
		{ badsb("SIZE PREPOSTEROUSLY LARGE"); return (0); }
	/* rest we COULD repair... */
D 34
	if (sblock.fs_sblkno != SBLOCK)
D 17
		{ badsb("BLKNO CORRUPTED"); return (0); }
	if (sblock.fs_spc != sblock.fs_nsect * sblock.fs_ntrak)
		{ badsb("SPC DOES NOT JIVE w/NTRAK*NSECT"); return (0); }
E 17
I 17
		{ badsb("SBLKNO CORRUPTED"); return (0); }
	if (sblock.fs_cblkno !=
	    roundup(howmany(BBSIZE + SBSIZE, sblock.fs_fsize), sblock.fs_frag))
		{ badsb("CBLKNO CORRUPTED"); return (0); }
	if (sblock.fs_iblkno != sblock.fs_cblkno + sblock.fs_frag)
		{ badsb("IBLKNO CORRUPTED"); return (0); }
	if (sblock.fs_dblkno != 
	    sblock.fs_iblkno + sblock.fs_ipg / INOPF(&sblock))
		{ badsb("DBLKNO CORRUPTED"); return (0); }
E 34
E 17
D 15
	if (sblock.fs_cgsize != cgsize(&sblock))
E 15
I 15
D 25
	if (sblock.fs_cgsize !=
D 16
	    sizeof(struct cg) + howmany(sblock.fs_fpg, NBBY))
E 16
I 16
	    roundup(sizeof(struct cg) + howmany(sblock.fs_fpg, NBBY),
	    sblock.fs_fsize))
E 25
I 25
	if (sblock.fs_cgsize != fragroundup(&sblock,
	    sizeof(struct cg) + howmany(sblock.fs_fpg, NBBY)))
E 25
E 16
E 15
		{ badsb("CGSIZE INCORRECT"); return (0); }
D 14
	if (sblock.fs_cssize != cssize(&sblock))
E 14
I 14
D 34
	if (sblock.fs_cssize != sblock.fs_ncg * sizeof(struct csum))
E 34
I 34
	if (sblock.fs_cssize !=
	    fragroundup(&sblock, sblock.fs_ncg * sizeof(struct csum)))
E 34
E 14
		{ badsb("CSSIZE INCORRECT"); return (0); }
	fmax = sblock.fs_size;
	imax = sblock.fs_ncg * sblock.fs_ipg;
I 34
	n_bad = cgsblock(&sblock, 0); /* boot block plus dedicated sblock */
E 34
D 17

E 17
I 17
	/*
D 34
	 * allocate the necessary maps
E 34
I 34
	 * read in the summary info.
E 34
	 */
I 34
	for (i = 0, j = 0; i < sblock.fs_cssize; i += sblock.fs_bsize, j++) {
		size = sblock.fs_cssize - i < sblock.fs_bsize ?
		    sblock.fs_cssize - i : sblock.fs_bsize;
		sblock.fs_csp[j] = (struct csum *)calloc(1, size);
		bread(&dfile, (char *)sblock.fs_csp[j],
		    fsbtodb(&sblock, sblock.fs_csaddr + j * sblock.fs_frag),
		    size);
	}
	/*
	 * allocate and initialize the necessary maps
	 */
E 34
E 17
	bmapsz = roundup(howmany(fmax, NBBY), sizeof(short));
D 29
	blkmap = (char *)calloc(bmapsz, sizeof (char));
E 29
I 29
	blockmap = (char *)calloc(bmapsz, sizeof (char));
I 35
	if (blockmap == NULL) {
		printf("cannot alloc %d bytes for blockmap\n", bmapsz);
		exit(1);
	}
E 35
E 29
	freemap = (char *)calloc(bmapsz, sizeof (char));
I 35
	if (freemap == NULL) {
		printf("cannot alloc %d bytes for freemap\n", bmapsz);
		exit(1);
	}
E 35
	statemap = (char *)calloc(imax+1, sizeof(char));
I 35
	if (statemap == NULL) {
		printf("cannot alloc %d bytes for statemap\n", imax + 1);
		exit(1);
	}
E 35
	lncntp = (short *)calloc(imax+1, sizeof(short));
I 35
	if (lncntp == NULL) {
		printf("cannot alloc %d bytes for lncntp\n", 
		    (imax + 1) * sizeof(short));
		exit(1);
	}
E 35
I 34
	for (c = 0; c < sblock.fs_ncg; c++) {
		cgd = cgdmin(&sblock, c);
		if (c == 0) {
			d = cgbase(&sblock, c);
			cgd += howmany(sblock.fs_cssize, sblock.fs_fsize);
		} else
			d = cgsblock(&sblock, c);
		for (; d < cgd; d++)
			setbmap(d);
	}
E 34

D 6
	niblk = sblock.fs_ipg / INOPB;
	startib = fmax;
E 6
I 6
	startinum = imax + 1;
E 6
	return (1);

badsb:
	ckfini();
	return (0);
E 47
}

badsb(s)
	char *s;
{

	if (preen)
		printf("%s: ", devname);
	printf("BAD SUPER BLOCK: %s\n", s);
	pwarn("USE -b OPTION TO FSCK TO SPECIFY LOCATION OF AN ALTERNATE\n");
	pfatal("SUPER-BLOCK TO SUPPLY NEEDED INFORMATION; SEE fsck(8).\n");
}

DINODE *
D 61
ginode()
E 61
I 61
ginode(inumber)
	ino_t inumber;
E 61
{
	daddr_t iblk;
I 61
	static ino_t startinum = 0;	/* blk num of first in raw area */
E 61

D 15
	if (inum > imax)
E 15
I 15
D 35
	if (inum < ROOTINO || inum > imax)
E 35
I 35
D 61
	if (inum < ROOTINO || inum > imax) {
		if (debug && (inum < 0 || inum > imax))
			printf("inum out of range (%d)\n", inum);
E 61
I 61

	if (inumber < ROOTINO || inumber > imax) {
		if (debug && inumber > imax)
			printf("inumber out of range (%d)\n", inumber);
E 61
E 35
E 15
		return (NULL);
I 35
	}
E 35
D 6
	iblk = itod(inum, &sblock);
	if (iblk < startib || iblk >= startib+niblk) {
		if (inoblk.b_dirty)
			bwrite(&dfile, (char *)ibase, startib, niblk*BSIZE);
		inoblk.b_dirty = 0;
		startib = cgimin(inum/sblock.fs_ipg, &sblock);
		if (bread(&dfile, (char *)ibase, iblk, niblk*BSIZE) == 0) {
			startib = fmax;
E 6
I 6
D 14
	if (inum < startinum || inum >= startinum + INOPB) {
E 14
I 14
D 61
	if (inum < startinum || inum >= startinum + INOPB(&sblock)) {
E 14
D 19
		iblk = itod(inum, &sblock);
E 19
I 19
		iblk = itod(&sblock, inum);
E 61
I 61
	if (startinum == 0 ||
	    inumber < startinum || inumber >= startinum + INOPB(&sblock)) {
		iblk = itod(&sblock, inumber);
E 61
E 19
D 14
		if (getblk(&inoblk, iblk, BSIZE) == NULL) {
E 14
I 14
		if (getblk(&inoblk, iblk, sblock.fs_bsize) == NULL) {
E 14
E 6
			return (NULL);
		}
D 6
		startib = iblk;
E 6
I 6
D 14
		startinum = (inum / INOPB) * INOPB;
E 14
I 14
D 61
		startinum = (inum / INOPB(&sblock)) * INOPB(&sblock);
E 61
I 61
		startinum = (inumber / INOPB(&sblock)) * INOPB(&sblock);
E 61
E 14
E 6
	}
D 6
	return (&ibase[(iblk - startib)*INOPB + itoo(inum)]);
E 6
I 6
D 14
	return (&inoblk.b_un.b_dinode[inum % INOPB]);
E 14
I 14
D 61
	return (&inoblk.b_un.b_dinode[inum % INOPB(&sblock)]);
E 61
I 61
	return (&inoblk.b_un.b_dinode[inumber % INOPB(&sblock)]);
E 61
E 14
E 6
}

ftypeok(dp)
	DINODE *dp;
{
	switch (dp->di_mode & IFMT) {

	case IFDIR:
	case IFREG:
	case IFBLK:
	case IFCHR:
D 27
	case IFMPC:
	case IFMPB:
E 27
I 27
	case IFLNK:
I 60
	case IFSOCK:
E 60
E 27
		return (1);

	default:
I 49
		if (debug)
			printf("bad file type 0%o\n", dp->di_mode);
E 49
		return (0);
	}
}

reply(s)
	char *s;
{
	char line[80];

	if (preen)
		pfatal("INTERNAL ERROR: GOT TO reply()");
	rplyflag = 1;
	printf("\n%s? ", s);
	if (nflag || dfile.wfdes < 0) {
		printf(" no\n\n");
		return (0);
	}
	if (yflag) {
		printf(" yes\n\n");
		return (1);
	}
	if (getline(stdin, line, sizeof(line)) == EOF)
		errexit("\n");
	printf("\n");
	if (line[0] == 'y' || line[0] == 'Y')
		return (1);
	else
		return (0);
}

getline(fp, loc, maxlen)
	FILE *fp;
	char *loc;
{
	register n;
	register char *p, *lastloc;

	p = loc;
	lastloc = &p[maxlen-1];
	while ((n = getc(fp)) != '\n') {
		if (n == EOF)
			return (EOF);
		if (!isspace(n) && p < lastloc)
			*p++ = n;
	}
	*p = 0;
	return (p - loc);
}

BUFAREA *
getblk(bp, blk, size)
D 61
	daddr_t blk;
E 61
	register BUFAREA *bp;
D 61
	int size;
E 61
I 61
	daddr_t blk;
	long size;
E 61
{
	register struct filecntl *fcp;
I 14
	daddr_t dblk;
E 14

	fcp = &dfile;
D 14
	if (bp->b_bno == blk)
E 14
I 14
	dblk = fsbtodb(&sblock, blk);
	if (bp->b_bno == dblk)
E 14
		return (bp);
	flush(fcp, bp);
D 14
	if (bread(fcp, bp->b_un.b_buf, blk, size) != 0) {
		bp->b_bno = blk;
E 14
I 14
	if (bread(fcp, bp->b_un.b_buf, dblk, size) != 0) {
		bp->b_bno = dblk;
E 14
		bp->b_size = size;
		return (bp);
	}
	bp->b_bno = (daddr_t)-1;
	return (NULL);
}

flush(fcp, bp)
	struct filecntl *fcp;
	register BUFAREA *bp;
{

	if (bp->b_dirty)
D 61
		bwrite(fcp, bp->b_un.b_buf, bp->b_bno, bp->b_size);
E 61
I 61
		(void)bwrite(fcp, bp->b_un.b_buf, bp->b_bno, (long)bp->b_size);
E 61
	bp->b_dirty = 0;
}

rwerr(s, blk)
	char *s;
	daddr_t blk;
{

	if (preen == 0)
		printf("\n");
	pfatal("CANNOT %s: BLK %ld", s, blk);
	if (reply("CONTINUE") == 0)
		errexit("Program terminated\n");
}

ckfini()
{

	flush(&dfile, &fileblk);
	flush(&dfile, &sblk);
I 6
	if (sblk.b_bno != SBLOCK) {
		sblk.b_bno = SBLOCK;
		sbdirty();
		flush(&dfile, &sblk);
	}
E 6
	flush(&dfile, &inoblk);
D 61
	close(dfile.rfdes);
	close(dfile.wfdes);
E 61
I 61
	(void)close(dfile.rfdes);
	(void)close(dfile.wfdes);
E 61
}

D 61
pinode()
E 61
I 61
pinode(ino)
	ino_t ino;
E 61
{
	register DINODE *dp;
	register char *p;
D 22
	char uidbuf[200];
E 22
I 22
	char uidbuf[BUFSIZ];
E 22
	char *ctime();

D 61
	printf(" I=%u ", inum);
	if ((dp = ginode()) == NULL)
E 61
I 61
	printf(" I=%u ", ino);
	if ((dp = ginode(ino)) == NULL)
E 61
		return;
	printf(" OWNER=");
	if (getpw((int)dp->di_uid, uidbuf) == 0) {
		for (p = uidbuf; *p != ':'; p++);
		*p = 0;
		printf("%s ", uidbuf);
	}
	else {
		printf("%d ", dp->di_uid);
	}
	printf("MODE=%o\n", dp->di_mode);
	if (preen)
		printf("%s: ", devname);
	printf("SIZE=%ld ", dp->di_size);
	p = ctime(&dp->di_mtime);
	printf("MTIME=%12.12s %4.4s ", p+4, p+20);
}

D 44
copy(fp, tp, size)
	register char *tp, *fp;
	unsigned size;
{

	while (size--)
		*tp++ = *fp++;
}

E 44
makecg()
{
D 6
	int c;
E 6
I 6
	int c, blk;
E 6
D 34
	daddr_t dbase, d, dmin, dmax;
E 34
I 34
	daddr_t dbase, d, dlower, dupper, dmax;
E 34
	long i, j, s;
I 61
	ino_t inumber;
E 61
I 20
D 24
	int x;
E 24
E 20
	register struct csum *cs;
I 6
	register DINODE *dp;
E 6

D 11
	sblock.fs_nbfree = 0;
	sblock.fs_nffree = 0;
E 11
I 11
	sblock.fs_cstotal.cs_nbfree = 0;
	sblock.fs_cstotal.cs_nffree = 0;
	sblock.fs_cstotal.cs_nifree = 0;
	sblock.fs_cstotal.cs_ndir = 0;
I 13
D 14
	for (i = 0; i < howmany(cssize(&sblock), BSIZE); i++) {
		sblock.fs_csp[i] = (struct csum *)calloc(1, BSIZE);
E 14
I 14
D 33
	for (i = 0; i < howmany(sblock.fs_cssize, sblock.fs_bsize); i++) {
		sblock.fs_csp[i] = (struct csum *)calloc(1, sblock.fs_bsize);
E 14
D 30
		getblk((char *)sblock.fs_csp[i],
D 14
		       csaddr(&sblock) + (i * FRAG), BSIZE);
E 14
I 14
		    sblock.fs_csaddr + (i * sblock.fs_frag), sblock.fs_bsize);
E 30
I 30
		bread(&dfile, (char *)sblock.fs_csp[i],
		    fsbtodb(&sblock, sblock.fs_csaddr + (i * sblock.fs_frag)),
		    sblock.fs_bsize);
E 30
E 14
	}
E 33
E 13
E 11
	for (c = 0; c < sblock.fs_ncg; c++) {
D 19
		dbase = cgbase(c, &sblock);
E 19
I 19
		dbase = cgbase(&sblock, c);
E 19
		dmax = dbase + sblock.fs_fpg;
D 21
		if (dmax > sblock.fs_size)
D 20
			dmax = sblock.fs_size;
I 6
D 19
		dmin = cgdmin(c, &sblock) - dbase;
E 19
I 19
		dmin = cgdmin(&sblock, c) - dbase;
E 20
I 20
			for ( ; dmax > sblock.fs_size ; dmax--)
E 21
I 21
		if (dmax > sblock.fs_size) {
D 24
			for ( ; dmax >= sblock.fs_size ; dmax--)
E 24
I 24
			for ( ; dmax >= sblock.fs_size; dmax--)
E 24
E 21
				clrbit(cgrp.cg_free, dmax - dbase);
I 21
			dmax++;
		}
E 21
D 34
		dmin = sblock.fs_dblkno;
E 34
I 34
		dlower = cgsblock(&sblock, c) - dbase;
		dupper = cgdmin(&sblock, c) - dbase;
E 34
E 20
E 19
E 6
D 9
		cs = &sblock.fs_cs[c];
E 9
I 9
D 14
		cs = &sblock.fs_cs(c);
E 14
I 14
		cs = &sblock.fs_cs(&sblock, c);
E 14
E 9
D 61
		cgrp.cg_time = time(0);
E 61
I 61
		(void)time(&cgrp.cg_time);
E 61
		cgrp.cg_magic = CG_MAGIC;
		cgrp.cg_cgx = c;
D 49
		cgrp.cg_ncyl = sblock.fs_cpg;
E 49
I 49
		if (c == sblock.fs_ncg - 1)
			cgrp.cg_ncyl = sblock.fs_ncyl % sblock.fs_cpg;
		else
			cgrp.cg_ncyl = sblock.fs_cpg;
E 49
		cgrp.cg_niblk = sblock.fs_ipg;
		cgrp.cg_ndblk = dmax - dbase;
D 11
		cgrp.cg_ndir = 0;
		cgrp.cg_nffree = 0;
		cgrp.cg_nbfree = 0;
		cgrp.cg_nifree = 0;
E 11
I 11
		cgrp.cg_cs.cs_ndir = 0;
		cgrp.cg_cs.cs_nffree = 0;
		cgrp.cg_cs.cs_nbfree = 0;
		cgrp.cg_cs.cs_nifree = 0;
E 11
D 6
		cgrp.cg_rotor = 0;
E 6
I 6
D 34
		cgrp.cg_rotor = dmin;
		cgrp.cg_frotor = dmin;
E 34
I 34
		cgrp.cg_rotor = 0;
		cgrp.cg_frotor = 0;
E 34
E 6
I 4
		cgrp.cg_irotor = 0;
I 6
D 14
		for (i = 0; i < FRAG; i++)
E 14
I 14
		for (i = 0; i < sblock.fs_frag; i++)
E 14
			cgrp.cg_frsum[i] = 0;
E 6
E 4
D 61
		inum = sblock.fs_ipg * c;
D 6
		for (i = 0; i < sblock.fs_ipg; inum++, i++)
		switch (getstate()) {

		case USTATE:
E 6
I 6
		for (i = 0; i < sblock.fs_ipg; inum++, i++) {
E 61
I 61
		inumber = sblock.fs_ipg * c;
		for (i = 0; i < sblock.fs_ipg; inumber++, i++) {
E 61
I 24
			cgrp.cg_cs.cs_nifree++;
			clrbit(cgrp.cg_iused, i);
E 24
D 61
			dp = ginode();
E 61
I 61
			dp = ginode(inumber);
E 61
			if (dp == NULL)
				continue;
			if (ALLOC) {
D 22
				if (DIR)
E 22
I 22
				if (DIRCT)
E 22
D 11
					cgrp.cg_ndir++;
E 11
I 11
					cgrp.cg_cs.cs_ndir++;
I 24
				cgrp.cg_cs.cs_nifree--;
E 24
E 11
				setbit(cgrp.cg_iused, i);
				continue;
			}
E 6
D 11
			cgrp.cg_nifree++;
E 11
I 11
D 24
			cgrp.cg_cs.cs_nifree++;
E 11
			clrbit(cgrp.cg_iused, i);
E 24
D 6
			continue;

		case DSTATE:
			cgrp.cg_ndir++;
			/* fall into ... */

		case FSTATE:
			setbit(cgrp.cg_iused, i);
			continue;

		default:
			errexit("internal error: inode state %d in makecg()\n",
			    getstate());
E 6
		}
		while (i < MAXIPG) {
			clrbit(cgrp.cg_iused, i);
			i++;
		}
I 24
		if (c == 0)
			for (i = 0; i < ROOTINO; i++) {
				setbit(cgrp.cg_iused, i);
				cgrp.cg_cs.cs_nifree--;
			}
E 24
D 18
		for (s = 0; s < MAXCPG; s++)
E 18
I 18
		for (s = 0; s < MAXCPG; s++) {
			cgrp.cg_btot[s] = 0;
E 18
			for (i = 0; i < NRPOS; i++)
				cgrp.cg_b[s][i] = 0;
I 18
		}
E 18
D 6
		dmin = cgdmin(c, &sblock) - dbase;
E 6
		if (c == 0) {
D 14
			dmin += howmany(cssize(&sblock), BSIZE) * FRAG;
E 14
I 14
D 24
			dmin += howmany(sblock.fs_cssize, sblock.fs_bsize) * sblock.fs_frag;
E 24
I 24
D 34
			dmin += howmany(sblock.fs_cssize, sblock.fs_bsize) *
			    sblock.fs_frag;
E 34
I 34
			dupper += howmany(sblock.fs_cssize, sblock.fs_fsize);
E 34
E 24
E 14
		}
D 34
		for (d = 0; d < dmin; d++)
E 34
I 34
		for (d = dlower; d < dupper; d++)
E 34
			clrbit(cgrp.cg_free, d);
D 14
		for (; (d + FRAG) <= dmax - dbase; d += FRAG) {
E 14
I 14
D 34
		for (; (d + sblock.fs_frag) <= dmax - dbase; d += sblock.fs_frag) {
E 34
I 34
		for (d = 0; (d + sblock.fs_frag) <= dmax - dbase;
		    d += sblock.fs_frag) {
E 34
E 14
			j = 0;
D 14
			for (i = 0; i < FRAG; i++) {
E 14
I 14
			for (i = 0; i < sblock.fs_frag; i++) {
E 14
D 34
				if (!getbmap(dbase+d+i)) {
					setbit(cgrp.cg_free, d+i);
E 34
I 34
				if (!getbmap(dbase + d + i)) {
					setbit(cgrp.cg_free, d + i);
E 34
					j++;
				} else
					clrbit(cgrp.cg_free, d+i);
			}
D 14
			if (j == FRAG) {
E 14
I 14
			if (j == sblock.fs_frag) {
E 14
D 11
				cgrp.cg_nbfree++;
E 11
I 11
				cgrp.cg_cs.cs_nbfree++;
I 18
				cgrp.cg_btot[cbtocylno(&sblock, d)]++;
E 18
E 11
D 14
				s = d * NSPF;
E 14
I 14
D 17
				s = d * NSPF(&sblock);
E 14
				cgrp.cg_b[s/sblock.fs_spc]
				  [s%sblock.fs_nsect*NRPOS/sblock.fs_nsect]++;
E 17
I 17
				cgrp.cg_b[cbtocylno(&sblock, d)]
				    [cbtorpos(&sblock, d)]++;
E 17
D 6
			} else
E 6
I 6
			} else if (j > 0) {
E 6
D 11
				cgrp.cg_nffree += j;
E 11
I 11
				cgrp.cg_cs.cs_nffree += j;
E 11
I 6
D 34
				blk = ((cgrp.cg_free[d / NBBY] >> (d % NBBY)) &
D 14
				       (0xff >> (NBBY - FRAG)));
				fragacct(blk, cgrp.cg_frsum, 1);
E 14
I 14
				       (0xff >> (NBBY - sblock.fs_frag)));
E 34
I 34
				blk = blkmap(&sblock, cgrp.cg_free, d);
E 34
				fragacct(&sblock, blk, cgrp.cg_frsum, 1);
E 14
			}
E 6
		}
I 20
D 24
		x = 0;
E 24
E 20
D 6
		for (; d < dmax - dbase; d++) {
E 6
I 6
		for (j = d; d < dmax - dbase; d++) {
E 6
D 34
			if (!getbmap(dbase+d)) {
E 34
I 34
			if (!getbmap(dbase + d)) {
E 34
				setbit(cgrp.cg_free, d);
D 11
				cgrp.cg_nffree++;
E 11
I 11
				cgrp.cg_cs.cs_nffree++;
I 20
D 24
				x++;
E 24
E 20
E 11
			} else
				clrbit(cgrp.cg_free, d);
		}
I 49
		for (; d % sblock.fs_frag != 0; d++)
			clrbit(cgrp.cg_free, d);
E 49
I 6
		if (j != d) {
D 34
			blk = ((cgrp.cg_free[j / NBBY] >> (j % NBBY)) &
D 14
			       (0xff >> (NBBY - FRAG)));
			fragacct(blk, cgrp.cg_frsum, 1);
E 14
I 14
			       (0xff >> (NBBY - sblock.fs_frag)));
E 34
I 34
			blk = blkmap(&sblock, cgrp.cg_free, j);
E 34
			fragacct(&sblock, blk, cgrp.cg_frsum, 1);
E 14
		}
E 6
D 14
		for (; d < MAXBPG; d++)
E 14
I 14
D 49
		for (; d < MAXBPG(&sblock); d++)
E 14
			clrbit(cgrp.cg_free, d);
E 49
I 49
		for (d /= sblock.fs_frag; d < MAXBPG(&sblock); d ++)
			clrblock(&sblock, cgrp.cg_free, d);
E 49
D 11
		sblock.fs_nffree += cgrp.cg_nffree;
		sblock.fs_nbfree += cgrp.cg_nbfree;
		cs->cs_ndir = cgrp.cg_ndir;
		cs->cs_nifree = cgrp.cg_nifree;
		cs->cs_nbfree = cgrp.cg_nbfree;
E 11
I 11
		sblock.fs_cstotal.cs_nffree += cgrp.cg_cs.cs_nffree;
		sblock.fs_cstotal.cs_nbfree += cgrp.cg_cs.cs_nbfree;
		sblock.fs_cstotal.cs_nifree += cgrp.cg_cs.cs_nifree;
		sblock.fs_cstotal.cs_ndir += cgrp.cg_cs.cs_ndir;
		*cs = cgrp.cg_cs;
E 11
D 14
		bwrite(&dfile, &cgrp, cgtod(c, &sblock), sblock.fs_cgsize);
E 14
I 14
D 19
		bwrite(&dfile, &cgrp, fsbtodb(&sblock, cgtod(c, &sblock)),
E 19
I 19
D 61
		bwrite(&dfile, &cgrp, fsbtodb(&sblock, cgtod(&sblock, c)),
E 19
D 25
			roundup(sblock.fs_cgsize, DEV_BSIZE));
E 25
I 25
		    sblock.fs_cgsize);
E 61
I 61
		(void)bwrite(&dfile, (char *)&cgrp,
			fsbtodb(&sblock, cgtod(&sblock, c)), sblock.fs_cgsize);
E 61
E 25
E 14
I 13
	}
D 14
	for (i = 0; i < howmany(cssize(&sblock), BSIZE); i++) {
E 14
I 14
D 34
	for (i = 0; i < howmany(sblock.fs_cssize, sblock.fs_bsize); i++) {
E 14
		bwrite(&dfile, (char *)sblock.fs_csp[i],
D 14
		       csaddr(&sblock) + (i * FRAG), BSIZE);
E 14
I 14
		    fsbtodb(&sblock, sblock.fs_csaddr + (i * sblock.fs_frag)),
		    sblock.fs_bsize);
E 34
I 34
	for (i = 0, j = 0; i < sblock.fs_cssize; i += sblock.fs_bsize, j++) {
D 61
		bwrite(&dfile, (char *)sblock.fs_csp[j],
E 61
I 61
		(void)bwrite(&dfile, (char *)sblock.fs_csp[j],
E 61
		    fsbtodb(&sblock, sblock.fs_csaddr + j * sblock.fs_frag),
		    sblock.fs_cssize - i < sblock.fs_bsize ?
		    sblock.fs_cssize - i : sblock.fs_bsize);
E 34
E 14
E 13
	}
	sblock.fs_ronly = 0;
	sblock.fs_fmod = 0;
	sbdirty();
I 6
}

D 46
/*
 * update the frsum fields to reflect addition or deletion 
 * of some frags
 */
D 14
fragacct(fragmap, fraglist, cnt)
E 14
I 14
fragacct(fs, fragmap, fraglist, cnt)
	struct fs *fs;
E 14
D 7
	char fragmap;
E 7
I 7
	int fragmap;
E 7
D 11
	short fraglist[];
E 11
I 11
	long fraglist[];
E 11
	int cnt;
{
	int inblk;
	register int field, subfield;
	register int siz, pos;

D 14
	inblk = (int)(fragtbl[fragmap] << 1);
E 14
I 14
	inblk = (int)(fragtbl[fs->fs_frag][fragmap] << 1);
E 14
	fragmap <<= 1;
D 14
	for (siz = 1; siz < FRAG; siz++) {
E 14
I 14
	for (siz = 1; siz < fs->fs_frag; siz++) {
E 14
D 28
		if (((1 << siz) & inblk) == 0)
E 28
I 28
		if ((inblk & (1 << (siz + (fs->fs_frag % NBBY)))) == 0)
E 28
			continue;
		field = around[siz];
		subfield = inside[siz];
D 14
		for (pos = siz; pos <= FRAG; pos++) {
E 14
I 14
		for (pos = siz; pos <= fs->fs_frag; pos++) {
E 14
			if ((fragmap & field) == subfield) {
				fraglist[siz] += cnt;
				pos += siz;
				field <<= siz;
				subfield <<= siz;
			}
			field <<= 1;
			subfield <<= 1;
		}
	}
E 6
}

E 46
D 61
findino(dirp)
	register DIRECT *dirp;
E 61
I 61
findino(idesc)
	struct inodesc *idesc;
E 61
{
I 61
	register DIRECT *dirp = idesc->id_dirp;

E 61
D 22
	register char *p1, *p2;

E 22
	if (dirp->d_ino == 0)
		return (KEEPON);
D 22
	for (p1 = dirp->d_name, p2 = srchname;*p2++ == *p1; p1++) {
		if (*p1 == 0 || p1 == &dirp->d_name[DIRSIZ-1]) {
			if (dirp->d_ino >= ROOTINO && dirp->d_ino <= imax)
				parentdir = dirp->d_ino;
			return (STOP);
		}
E 22
I 22
	if (!strcmp(dirp->d_name, srchname)) {
		if (dirp->d_ino >= ROOTINO && dirp->d_ino <= imax)
D 61
			parentdir = dirp->d_ino;
E 61
I 61
			idesc->id_parent = dirp->d_ino;
E 61
		return (STOP);
E 22
	}
	return (KEEPON);
}

D 61
mkentry(dirp)
	register DIRECT *dirp;
E 61
I 61
mkentry(idesc)
	struct inodesc *idesc;
E 61
{
D 61
	register ino_t in;
	register char *p;
E 61
I 61
	register DIRECT *dirp = idesc->id_dirp;
E 61
I 26
	DIRECT newent;
	int newlen, oldlen;
E 26

D 26
	if (dirp->d_ino)
E 26
I 26
	newent.d_namlen = 11;
	newlen = DIRSIZ(&newent);
	if (dirp->d_ino != 0)
		oldlen = DIRSIZ(dirp);
	else
		oldlen = 0;
	if (dirp->d_reclen - oldlen < newlen)
E 26
		return (KEEPON);
I 26
	newent.d_reclen = dirp->d_reclen - oldlen;
	dirp->d_reclen = oldlen;
	dirp = (struct direct *)(((char *)dirp) + oldlen);
E 26
D 61
	dirp->d_ino = orphan;
E 61
I 61
	dirp->d_ino = idesc->id_parent;	/* ino to be entered is in id_parent */
E 61
D 26
	in = orphan;
	p = &dirp->d_name[8];
E 26
I 26
	dirp->d_reclen = newent.d_reclen;
D 61
	p = &dirp->d_name[2];
	for (in = imax; in > 0; in /= 10)
		p++;
E 26
	*--p = 0;
I 26
	dirp->d_namlen = p - dirp->d_name;
	in = orphan;
E 26
	while (p > dirp->d_name) {
		*--p = (in % 10) + '0';
		in /= 10;
	}
	*p = '#';
	return (ALTERD|STOP);
E 61
I 61
	dirp->d_namlen = lftempname(dirp->d_name, idesc->id_parent);
	return (ALTERED|STOP);
E 61
}

D 61
chgdd(dirp)
	register DIRECT *dirp;
E 61
I 61
chgdd(idesc)
	struct inodesc *idesc;
E 61
{
I 61
	register DIRECT *dirp = idesc->id_dirp;

E 61
	if (dirp->d_name[0] == '.' && dirp->d_name[1] == '.' &&
	dirp->d_name[2] == 0) {
		dirp->d_ino = lfdir;
D 61
		return (ALTERD|STOP);
E 61
I 61
		return (ALTERED|STOP);
E 61
	}
	return (KEEPON);
}

D 61
linkup()
E 61
I 61
linkup(orphan, pdir)
	ino_t orphan;
	ino_t pdir;
E 61
{
	register DINODE *dp;
D 62
	register lostdir;
E 62
I 62
	int lostdir, len;
E 62
D 61
	register ino_t pdir;
E 61
I 61
	struct inodesc idesc;
E 61

D 61
	if ((dp = ginode()) == NULL)
E 61
I 61
	bzero((char *)&idesc, sizeof(struct inodesc));
	if ((dp = ginode(orphan)) == NULL)
E 61
		return (0);
D 22
	lostdir = DIR;
E 22
I 22
	lostdir = DIRCT;
E 22
D 61
	pdir = parentdir;
E 61
	pwarn("UNREF %s ", lostdir ? "DIR" : "FILE");
D 61
	pinode();
E 61
I 61
	pinode(orphan);
E 61
	if (preen && dp->di_size == 0)
		return (0);
	if (preen)
		printf(" (RECONNECTED)\n");
	else
		if (reply("RECONNECT") == 0)
			return (0);
I 62
	pathp = pathname;
	*pathp++ = '/';
	*pathp = '\0';
E 62
D 61
	orphan = inum;
E 61
	if (lfdir == 0) {
D 61
		inum = ROOTINO;
		if ((dp = ginode()) == NULL) {
			inum = orphan;
E 61
I 61
		if ((dp = ginode(ROOTINO)) == NULL)
E 61
			return (0);
D 61
		}
		pfunc = findino;
E 61
		srchname = lfname;
D 61
		filsize = dp->di_size;
		parentdir = 0;
		ckinode(dp, DATA);
		inum = orphan;
		if ((lfdir = parentdir) == 0) {
E 61
I 61
		idesc.id_type = DATA;
		idesc.id_func = findino;
		idesc.id_number = ROOTINO;
		idesc.id_filesize = dp->di_size;
		(void)ckinode(dp, &idesc);
		if ((lfdir = idesc.id_parent) == 0) {
E 61
			pfatal("SORRY. NO lost+found DIRECTORY");
			printf("\n\n");
			return (0);
		}
	}
D 61
	inum = lfdir;
D 22
	if ((dp = ginode()) == NULL || !DIR || getstate() != FSTATE) {
E 22
I 22
D 45
	if ((dp = ginode()) == NULL || !DIRCT || getstate() != FSTATE) {
E 45
I 45
	if ((dp = ginode()) == NULL || !DIRCT || statemap[inum] != FSTATE) {
E 45
E 22
		inum = orphan;
E 61
I 61
	if ((dp = ginode(lfdir)) == NULL ||
	     !DIRCT || statemap[lfdir] != FSTATE) {
E 61
		pfatal("SORRY. NO lost+found DIRECTORY");
		printf("\n\n");
		return (0);
	}
D 14
	if (dp->di_size & BMASK) {
		dp->di_size = roundup(dp->di_size, BSIZE);
E 14
I 14
D 25
	if (dp->di_size % sblock.fs_bsize) {
		dp->di_size = roundup(dp->di_size, sblock.fs_bsize);
E 25
I 25
	if (fragoff(&sblock, dp->di_size)) {
		dp->di_size = fragroundup(&sblock, dp->di_size);
E 25
E 14
		inodirty();
	}
I 62
	len = strlen(lfname);
	bcopy(lfname, pathp, len + 1);
	pathp += len;
E 62
D 61
	filsize = dp->di_size;
	inum = orphan;
	pfunc = mkentry;
	if ((ckinode(dp, DATA) & ALTERD) == 0) {
E 61
I 61
	idesc.id_type = DATA;
	idesc.id_func = mkentry;
	idesc.id_number = lfdir;
	idesc.id_filesize = dp->di_size;
	idesc.id_parent = orphan;	/* this is the inode to enter */
I 62
	idesc.id_fix = DONTKNOW;
E 62
	if ((ckinode(dp, &idesc) & ALTERED) == 0) {
E 61
		pfatal("SORRY. NO SPACE IN lost+found DIRECTORY");
		printf("\n\n");
		return (0);
	}
D 45
	declncnt();
E 45
I 45
D 61
	lncntp[inum]--;
E 61
I 61
	lncntp[orphan]--;
I 62
	*pathp++ = '/';
	pathp += lftempname(pathp, orphan);
E 62
E 61
E 45
	if (lostdir) {
D 61
		pfunc = chgdd;
		dp = ginode();
		filsize = dp->di_size;
		ckinode(dp, DATA);
		inum = lfdir;
		if ((dp = ginode()) != NULL) {
E 61
I 61
		dp = ginode(orphan);
		idesc.id_type = DATA;
		idesc.id_func = chgdd;
		idesc.id_number = orphan;
		idesc.id_filesize = dp->di_size;
I 62
		idesc.id_fix = DONTKNOW;
E 62
		(void)ckinode(dp, &idesc);
		if ((dp = ginode(lfdir)) != NULL) {
E 61
			dp->di_nlink++;
			inodirty();
D 45
			setlncnt(getlncnt()+1);
E 45
I 45
D 61
			lncntp[inum]++;
E 61
I 61
			lncntp[lfdir]++;
E 61
E 45
		}
D 61
		inum = orphan;
E 61
		pwarn("DIR I=%u CONNECTED. ", orphan);
		printf("PARENT WAS I=%u\n", pdir);
		if (preen == 0)
			printf("\n");
	}
	return (1);
}

I 61
/*
 * generate a temporary name for the lost+found directory.
 */
lftempname(bufp, ino)
	char *bufp;
	ino_t ino;
{
	register ino_t in;
	register char *cp;
	int namlen;

	cp = bufp + 2;
	for (in = imax; in > 0; in /= 10)
		cp++;
	*--cp = 0;
	namlen = cp - bufp;
	in = ino;
	while (cp > bufp) {
		*--cp = (in % 10) + '0';
		in /= 10;
	}
	*cp = '#';
	return (namlen);
}

E 61
bread(fcp, buf, blk, size)
D 61
	daddr_t blk;
E 61
	register struct filecntl *fcp;
D 61
	register size;
E 61
	char *buf;
I 61
	daddr_t blk;
	long size;
E 61
{
D 14
	if (lseek(fcp->rfdes, blk*FSIZE, 0) < 0)
E 14
I 14
D 57
	if (lseek(fcp->rfdes, blk * DEV_BSIZE, 0) < 0)
E 57
I 57
D 61
	if (lseek(fcp->rfdes, dbtob(blk), 0) < 0)
E 61
I 61
	if (lseek(fcp->rfdes, (long)dbtob(blk), 0) < 0)
E 61
E 57
E 14
		rwerr("SEEK", blk);
D 61
	else if (read(fcp->rfdes, buf, size) == size)
E 61
I 61
	else if (read(fcp->rfdes, buf, (int)size) == size)
E 61
		return (1);
	rwerr("READ", blk);
	return (0);
}

bwrite(fcp, buf, blk, size)
D 61
	daddr_t blk;
E 61
	register struct filecntl *fcp;
D 61
	register size;
E 61
	char *buf;
I 61
	daddr_t blk;
	long size;
E 61
{

	if (fcp->wfdes < 0)
		return (0);
D 14
	if (lseek(fcp->wfdes, blk*FSIZE, 0) < 0)
E 14
I 14
D 57
	if (lseek(fcp->wfdes, blk * DEV_BSIZE, 0) < 0)
E 57
I 57
D 61
	if (lseek(fcp->wfdes, dbtob(blk), 0) < 0)
E 61
I 61
	if (lseek(fcp->wfdes, (long)dbtob(blk), 0) < 0)
E 61
E 57
E 14
		rwerr("SEEK", blk);
D 61
	else if (write(fcp->wfdes, buf, size) == size) {
E 61
I 61
	else if (write(fcp->wfdes, buf, (int)size) == size) {
E 61
		fcp->mod = 1;
		return (1);
	}
	rwerr("WRITE", blk);
	return (0);
}

catch()
{

	ckfini();
	exit(12);
I 14
}

D 46
/*
 * block operations
 */

isblock(fs, cp, h)
	struct fs *fs;
	unsigned char *cp;
	int h;
{
	unsigned char mask;

	switch (fs->fs_frag) {
	case 8:
		return (cp[h] == 0xff);
	case 4:
		mask = 0x0f << ((h & 0x1) << 2);
		return ((cp[h >> 1] & mask) == mask);
	case 2:
		mask = 0x03 << ((h & 0x3) << 1);
		return ((cp[h >> 2] & mask) == mask);
	case 1:
		mask = 0x01 << (h & 0x7);
		return ((cp[h >> 3] & mask) == mask);
	default:
D 19
		fprintf(stderr, "isblock bad fs_frag %d\n", fs->fs_frag);
		return;
E 19
I 19
		error("isblock bad fs_frag %d\n", fs->fs_frag);
		return (0);
I 49
D 50
	}
}

/*
 * take a block out of the map
 */
clrblock(fs, cp, h)
	struct fs *fs;
	unsigned char *cp;
	int h;
{
	switch ((fs)->fs_frag) {
	case 8:
		cp[h] = 0;
		return;
	case 4:
		cp[h >> 1] &= ~(0x0f << ((h & 0x1) << 2));
		return;
	case 2:
		cp[h >> 2] &= ~(0x03 << ((h & 0x3) << 1));
		return;
	case 1:
		cp[h >> 3] &= ~(0x01 << (h & 0x7));
		return;
	default:
		error("clrblock bad fs_frag %d\n", fs->fs_frag);
		return;
E 50
E 49
E 19
	}
E 14
}
I 32

E 46
D 44
/*	tables.c	4.1	82/03/25	*/
E 44
I 44
char *
unrawname(cp)
	char *cp;
{
	char *dp = rindex(cp, '/');
	struct stat stb;
E 44

D 44
/* merged into kernel:	tables.c 2.1 3/25/82 */
E 44
I 44
	if (dp == 0)
		return (cp);
	if (stat(cp, &stb) < 0)
		return (cp);
	if ((stb.st_mode&S_IFMT) != S_IFCHR)
		return (cp);
	if (*(dp+1) != 'r')
		return (cp);
D 61
	strcpy(dp+1, dp+2);
E 61
I 61
	(void)strcpy(dp+1, dp+2);
E 61
	return (cp);
}
E 44

D 44
/* last monet version:	partab.c	4.2	81/03/08	*/
E 44
I 44
char *
rawname(cp)
	char *cp;
{
	static char rawbuf[32];
	char *dp = rindex(cp, '/');
E 44

D 44
/*
 * bit patterns for identifying fragments in the block map
 * used as ((map & around) == inside)
 */
int around[9] = {
	0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff, 0x1ff, 0x3ff
};
int inside[9] = {
	0x0, 0x2, 0x6, 0xe, 0x1e, 0x3e, 0x7e, 0xfe, 0x1fe
};
E 44
I 44
	if (dp == 0)
		return (0);
	*dp = 0;
D 61
	strcpy(rawbuf, cp);
E 61
I 61
	(void)strcpy(rawbuf, cp);
E 61
	*dp = '/';
D 61
	strcat(rawbuf, "/r");
	strcat(rawbuf, dp+1);
E 61
I 61
	(void)strcat(rawbuf, "/r");
	(void)strcat(rawbuf, dp+1);
E 61
	return (rawbuf);
}
E 44

I 61
/*
 * determine whether an inode should be fixed.
 */
dofix(idesc)
	register struct inodesc *idesc;
{
I 63

E 63
	switch (idesc->id_fix) {

	case DONTKNOW:
D 63
		if (reply("FIX") == 0) {
E 63
I 63
		direrr(idesc->id_number, "DIRECTORY CORRUPTED");
		if (reply("SALVAGE") == 0) {
E 63
			idesc->id_fix = NOFIX;
			return (0);
		}
		idesc->id_fix = FIX;
		return (ALTERED);

	case FIX:
		return (ALTERED);

	case NOFIX:
		return (0);

	default:
		errexit("UNKNOWN INODESC FIX MODE %d\n", idesc->id_fix);
	}
	/* NOTREACHED */
}

E 61
I 44
/* VARARGS1 */
error(s1, s2, s3, s4)
	char *s1;
{

	printf(s1, s2, s3, s4);
}

/* VARARGS1 */
errexit(s1, s2, s3, s4)
	char *s1;
{
	error(s1, s2, s3, s4);
	exit(8);
}

E 44
/*
D 44
 * given a block map bit pattern, the frag tables tell whether a
 * particular size fragment is available. 
 *
 * used as:
 * if ((1 << (size - 1)) & fragtbl[fs->fs_frag][map] {
 *	at least one fragment of the indicated size is available
 * }
 *
 * These tables are used by the scanc instruction on the VAX to
 * quickly find an appropriate fragment.
E 44
I 44
 * An inconsistency occured which shouldn't during normal operations.
D 55
 * Die if preening, otw just printf.
E 55
I 55
 * Die if preening, otherwise just printf.
E 55
E 44
 */
I 44
/* VARARGS1 */
pfatal(s, a1, a2, a3)
	char *s;
{
E 44

D 44
unsigned char fragtbl124[256] = {
	0x00, 0x16, 0x16, 0x2a, 0x16, 0x16, 0x26, 0x4e,
	0x16, 0x16, 0x16, 0x3e, 0x2a, 0x3e, 0x4e, 0x8a,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x2a, 0x3e, 0x3e, 0x2a, 0x3e, 0x3e, 0x2e, 0x6e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x2a, 0x3e, 0x6e, 0xaa,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x26, 0x36, 0x36, 0x2e, 0x36, 0x36, 0x26, 0x6e,
	0x36, 0x36, 0x36, 0x3e, 0x2e, 0x3e, 0x6e, 0xae,
	0x4e, 0x5e, 0x5e, 0x6e, 0x5e, 0x5e, 0x6e, 0x4e,
	0x5e, 0x5e, 0x5e, 0x7e, 0x6e, 0x7e, 0x4e, 0xce,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e, 0xbe,
	0x2a, 0x3e, 0x3e, 0x2a, 0x3e, 0x3e, 0x2e, 0x6e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x2a, 0x3e, 0x6e, 0xaa,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e, 0xbe,
	0x4e, 0x5e, 0x5e, 0x6e, 0x5e, 0x5e, 0x6e, 0x4e,
	0x5e, 0x5e, 0x5e, 0x7e, 0x6e, 0x7e, 0x4e, 0xce,
	0x8a, 0x9e, 0x9e, 0xaa, 0x9e, 0x9e, 0xae, 0xce,
	0x9e, 0x9e, 0x9e, 0xbe, 0xaa, 0xbe, 0xce, 0x8a,
};
E 44
I 44
	if (preen) {
		printf("%s: ", devname);
		printf(s, a1, a2, a3);
		printf("\n");
		preendie();
	}
	printf(s, a1, a2, a3);
}
E 44

D 44
unsigned char fragtbl8[256] = {
	0x00, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02, 0x04,
	0x01, 0x01, 0x01, 0x03, 0x02, 0x03, 0x04, 0x08,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x02, 0x03, 0x03, 0x02, 0x04, 0x05, 0x08, 0x10,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0x06,
	0x04, 0x05, 0x05, 0x06, 0x08, 0x09, 0x10, 0x20,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x09, 0x11,
	0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0x06,
	0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x06, 0x0a,
	0x04, 0x05, 0x05, 0x06, 0x05, 0x05, 0x06, 0x04,
	0x08, 0x09, 0x09, 0x0a, 0x10, 0x11, 0x20, 0x40,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x09, 0x11,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07,
	0x05, 0x05, 0x05, 0x07, 0x09, 0x09, 0x11, 0x21,
	0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0x06,
	0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x06, 0x0a,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07,
	0x02, 0x03, 0x03, 0x02, 0x06, 0x07, 0x0a, 0x12,
	0x04, 0x05, 0x05, 0x06, 0x05, 0x05, 0x06, 0x04,
	0x05, 0x05, 0x05, 0x07, 0x06, 0x07, 0x04, 0x0c,
	0x08, 0x09, 0x09, 0x0a, 0x09, 0x09, 0x0a, 0x0c,
	0x10, 0x11, 0x11, 0x12, 0x20, 0x21, 0x40, 0x80,
};
E 44
I 44
preendie()
{
E 44

I 44
	printf("%s: UNEXPECTED INCONSISTENCY; RUN fsck MANUALLY.\n", devname);
	exit(8);
}

E 44
/*
D 44
 * the actual fragtbl array
E 44
I 44
 * Pwarn is like printf when not preening,
 * or a warning (preceded by filename) when preening.
E 44
 */
D 44
unsigned char *fragtbl[MAXFRAG + 1] = {
	0, fragtbl124, fragtbl124, 0, fragtbl124, 0, 0, 0, fragtbl8,
};
E 44
I 44
/* VARARGS1 */
pwarn(s, a1, a2, a3, a4, a5, a6)
	char *s;
{

	if (preen)
		printf("%s: ", devname);
	printf(s, a1, a2, a3, a4, a5, a6);
I 46
}

I 61
#ifndef lint
/*
 * Stub for routines from kernel.
 */
E 61
panic(s)
	char *s;
{

D 61
	pfatal("internal inconsistency: %s\n");
E 61
I 61
	pfatal("INTERNAL INCONSISTENCY: %s\n", s);
E 61
	exit(12);
E 46
}
I 61
#endif
E 67
E 61
E 44
E 32
E 1
