h37048
s 00006/00006/01718
d D 5.15 88/04/13 22:33:32 karels 55 54
c try again (better format for times >99:59)
e
s 00011/00010/01713
d D 5.14 88/03/10 19:16:05 karels 54 52
c sigh, I give up making this fit on a line (need to squish flags)
e
s 00004/00004/01719
d R 5.14 88/03/10 17:31:10 karels 53 52
c "pagedaemon" is too long now
e
s 00003/00002/01720
d D 5.13 88/03/10 17:23:50 karels 52 50
c oops, don't keep state from previous process
e
s 00001/00000/01722
d R 5.13 88/03/10 17:17:45 karels 51 50
c oops, don't keep the last proc's state
e
s 00035/00030/01687
d D 5.12 88/03/10 17:02:41 karels 50 49
c leave spaces between fields, enough space for large processes
e
s 00002/00002/01715
d D 5.11 87/10/22 09:54:49 bostic 49 48
c ANSI C; sprintf now returns an int.
e
s 00003/00003/01714
d D 5.10 87/03/28 17:49:05 karels 48 47
c make -k work on tahoe
e
s 00001/00001/01716
d D 5.9 86/05/08 12:48:28 karels 47 46
c rename nch => namecache (hopefully never used!)
e
s 00005/00005/01712
d D 5.8 86/04/26 07:29:23 lepreau 46 45
c give LIM field 1 more space
e
s 00000/00000/01717
d D 5.7 86/04/20 12:46:51 mckusick 45 43
i 44
c merge of 5.4.1.1
e
s 00039/00004/01678
d D 5.4.1.1 86/04/20 12:44:39 mckusick 44 41
c move verification to front of database to prevent looping 
c (from Peter Ford via lepreau@utah-cs.arpa)
e
s 00001/00001/01681
d D 5.6 86/02/07 10:40:42 bloom 43 42
c use stdout instead of stdin for sizing window
e
s 00002/00002/01680
d D 5.5 86/01/10 03:50:27 lepreau 42 41
c make specifying just proc 0 work
e
s 00031/00086/01651
d D 5.4 85/09/07 19:48:26 bloom 41 39
c use ls style uid/name hash (from serge@arpa), delete purdue RCS log
e
s 00031/00086/01651
d R 5.4 85/09/07 18:53:59 bloom 40 39
c use ls style name hashing, remove purdue rcs logs
e
s 00408/00032/01329
d D 5.3 85/08/28 18:04:31 mckusick 39 38
c symbolic wchan's (from Charles LaBrec; crl@newton.purdue.edu)
e
s 00055/00018/01306
d D 5.2 85/07/31 19:28:21 mckusick 38 37
c dynamic allocation of tty slots; save tty hash structure (from ks@purdue)
e
s 00014/00002/01310
d D 5.1 85/06/06 10:53:43 dist 37 36
c Add copyright
e
s 00013/00012/01299
d D 4.32 85/06/05 14:32:13 karels 36 35
c sundry fixes
e
s 00010/00004/01301
d D 4.31 85/02/25 09:23:33 karels 35 34
c minor cleanups: get disk names right, avoid pty masters
e
s 00013/00002/01292
d D 4.30 85/02/23 14:48:06 bloom 34 31
c get screen width ioctl added and hold passwd file open
e
s 00013/00002/01292
d R 4.30 85/02/20 08:55:01 bloom 33 31
c get screen width ioctl added and hold passwd file open
e
s 00001/00000/01294
d R 4.30 85/01/03 11:30:55 bloom 32 31
c tty.h requires ioctl.h
e
s 00003/00003/01291
d D 4.29 84/11/15 16:26:27 sam 31 30
c check in for bloom; update device lookup routine to skip current 
c block devices (had been checking only for oldies)
e
s 00002/00002/01292
d D 4.28 84/07/25 15:54:16 bloom 30 29
c add another digit to wchan, too many processes wait on higher addresses
e
s 00192/00086/01102
d D 4.27 84/03/21 14:56:45 ralph 29 28
c add -U flag to save static info & reduce startup time.
e
s 00001/00001/01187
d D 4.26 83/09/25 13:00:21 sam 28 27
c sbrk returns -1, not 0, on failure; from lepreau@utah-cs
e
s 00001/00001/01187
d D 4.25 83/09/22 11:45:37 ralph 27 26
c memory sizes are now computed correctly
e
s 00010/00003/01178
d D 4.24 83/05/22 17:29:45 sam 26 25
c size of proc structure changed for quotas
e
s 00068/00026/01113
d D 4.23 83/05/06 21:00:19 leres 25 24
c Fix from dlw@Jade, use a hash table so that uid's bigger than 2048 work.
e
s 00006/00000/01133
d D 4.22 83/04/13 15:54:15 leres 24 23
c Modified so that "ps t" means processes at my tty.
e
s 00054/00175/01079
d D 4.21 83/02/09 14:00:22 sam 23 22
c stuff from sun and delete ss trash
e
s 00001/00001/01253
d D 4.20 82/12/24 12:40:06 sam 22 21
c pte.h moved
e
s 00005/00009/01249
d D 4.19 82/11/14 16:33:35 sam 21 20
c convert to 4.1c sys calls and directory layout
e
s 00034/00025/01224
d D 4.18 82/06/26 01:07:10 wnj 20 19
c -k works now
e
s 00072/00081/01177
d D 4.17 82/05/07 17:46:29 mckusick 19 18
c update to new fs
e
s 00020/00009/01238
d D 4.16 82/03/01 00:11:36 wnj 18 17
c merge in -k fixes with rand stuff
e
s 00001/00001/01246
d D 4.15 81/09/08 08:30:02 mark 17 16
c fixed SCCS id to use %G%, not %E%
e
s 00152/00019/01095
d D 4.14 81/09/03 12:23:19 mark 16 15
c ss command from Rand merged in (again!)
e
s 00001/00001/01113
d D 4.13 81/07/08 16:32:54 root 15 14
c restore sccs line
e
s 00006/00003/01108
d D 4.12 81/07/08 16:32:04 root 14 11
c fix bug which caused some ttys to appear to be ``mt''
e
s 00004/00001/01243
d R 4.13 81/07/02 15:31:01 bugs 13 12
c fix to ps on tty12 printing tty as ``mt''
e
s 00152/00019/01092
d R 4.12 81/05/22 00:08:14 mark 12 11
c added in Rand ss stuff
e
s 00002/00000/01109
d D 4.11 81/05/12 23:03:56 toy 11 10
c Recognize net process (3)
e
s 00002/00002/01107
d D 4.10 81/04/26 23:38:41 wnj 10 9
c lim prints as XX; print S for sequential
e
s 00014/00005/01095
d D 4.9 81/04/21 02:06:01 root 9 8
c limit memsize stuff
e
s 00037/00015/01063
d D 4.8 81/02/28 22:55:52 wnj 8 7
c changed for new system style
e
s 00008/00001/01070
d D 4.7 80/10/21 01:23:27 bill 7 6
c pad for hardware botch end-run
e
s 00001/00001/01070
d D 4.6 80/10/20 14:04:38 bill 6 5
c fixed bug where used text even though 0
e
s 00006/00001/01065
d D 4.5 80/10/19 01:59:53 bill 5 4
c S option
e
s 00085/00044/00981
d D 4.4 80/10/12 23:30:04 bill 4 3
c %cpu %mem stuff 
e
s 00037/00014/00988
d D 4.3 80/10/11 18:32:38 bill 3 2
c ps au fixes
e
s 00095/00058/00907
d D 4.2 80/10/11 14:44:22 bill 2 1
c misc bug fixes
e
s 00965/00000/00000
d D 4.1 80/10/01 17:27:49 bill 1 0
c date and time created 80/10/01 17:27:49 by bill
e
u
U
f b 
t
T
I 37
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 37
I 19
#ifndef lint
E 19
I 3
D 14
static	char *sccsid = "%W% (Berkeley) %G%";
E 14
I 14
D 15
static	char *sccsid = "@(#)ps.c	4.10+ (Berkeley) 7/2/81";
E 15
I 15
D 17
static	char *sccsid = "%W% (Berkeley) %E%";
E 17
I 17
D 37
static	char *sccsid = "%W% (Berkeley) %G%";
I 19
#endif
E 37
I 37
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 37

E 19
E 17
E 15
E 14
E 3
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
D 41
/*
D 19
 * ps; VAX 4BSD version
E 19
I 19
 * ps
I 39
 *
 * $Log:	ps.c,v $
 * Revision 5.2.1.4  85/08/25  22:25:43  crl
 * 'n' flag now also causes usernames to be printed as uid's.
 * 
 * Revision 5.2.1.3  85/08/10  01:33:18  crl
 * Implemented the wait channel stop list in addchan() and the index table
 * 	in getchan()
 * 
 * Revision 5.2.1.2  85/08/05  23:40:34  crl
 * Cut down # of calls to realloc by allocating in bigger chunks in
 * 	addchan().
 * If terminal width > WTSIZ, use a wider field for wchan.
 * 
E 39
E 19
 */
E 41
D 23

E 23
#include <stdio.h>
#include <ctype.h>
D 39
#include <nlist.h>
E 39
I 39
#include <a.out.h>
E 39
#include <pwd.h>
#include <sys/param.h>
I 34
#include <sys/ioctl.h>
E 34
#include <sys/tty.h>
D 19
#include <sys/dir.h>
E 19
I 19
D 26
#include <dir.h>
E 26
I 26
#include <sys/dir.h>
E 26
E 19
#include <sys/user.h>
#include <sys/proc.h>
D 22
#include <sys/pte.h>
E 22
I 22
#include <machine/pte.h>
E 22
#include <sys/vm.h>
#include <sys/text.h>
#include <sys/stat.h>
I 23
#include <sys/mbuf.h>
E 23
I 3
#include <math.h>
I 29
#include <errno.h>
E 29
I 9
D 23
#include <sys/vlimit.h>
E 23
E 9
E 3

D 39
struct nlist nl[] = {
	{ "_proc" },
E 39
I 39
char *nl_names[] = {
	"_proc",
E 39
#define	X_PROC		0
D 39
	{ "_Usrptmap" },
E 39
I 39
	"_Usrptmap",
E 39
D 29
#define	X_USRPTMA	1
E 29
I 29
#define	X_USRPTMAP	1
E 29
D 39
	{ "_usrpt" },
E 39
I 39
	"_usrpt",
E 39
#define	X_USRPT		2
D 39
	{ "_text" },
E 39
I 39
	"_text",
E 39
#define	X_TEXT		3
D 39
	{ "_nswap" },
E 39
I 39
	"_nswap",
E 39
#define	X_NSWAP		4
I 2
D 39
	{ "_maxslp" },
E 39
I 39
	"_maxslp",
E 39
#define	X_MAXSLP	5
I 3
D 39
	{ "_ccpu" },
E 39
I 39
	"_ccpu",
E 39
#define	X_CCPU		6
I 4
D 39
	{ "_ecmx" },
E 39
I 39
	"_ecmx",
E 39
#define	X_ECMX		7
I 8
D 39
	{ "_nproc" },
E 39
I 39
	"_nproc",
E 39
#define	X_NPROC		8
D 39
	{ "_ntext" },
E 39
I 39
	"_ntext",
E 39
#define	X_NTEXT		9
I 26
D 39
	{ "_dmmin" },
E 39
I 39
	"_dmmin",
E 39
#define	X_DMMIN		10
D 39
	{ "_dmmax" },
E 39
I 39
	"_dmmax",
E 39
#define	X_DMMAX		11
I 29
D 39
	{ "_Sysmap" },
E 39
I 39
	"_Sysmap",
E 39
#define	X_SYSMAP	12
D 39
	{ "_Syssize" },
E 39
I 39
	"_Syssize",
E 39
#define	X_SYSSIZE	13
E 29
E 26
D 21
	{ "_hz" },
#define	X_HZ		10
E 21
E 8
E 4
E 3
E 2
D 23
	{ 0 },
E 23
I 23
D 39
	{ "" },
E 39
I 39
	"_inode",
#define X_INODE		14
	"_file",
#define X_FILE		15
	"_cfree",
#define X_CFREE		16
	"_callout",
#define X_CALLOUT	17
	"_swapmap",
#define X_SWAPMAP	18
	"_argmap",
#define X_ARGMAP	19
	"_kernelmap",
#define X_KERNELMAP	20
	"_mbmap",
#define X_MBMAP		21
D 47
	"_nch",
E 47
I 47
	"_namecache",
E 47
#define X_NCH		22
	"_quota",
#define X_QUOTA		23
	"_dquot",
#define X_DQUOT		24
	"_swbuf",
#define X_SWBUF		25
	"_buf",
#define X_BUF		26
	"_cmap",
#define X_CMAP		27
	"_buffers",
#define X_BUFFERS	28
	""
E 39
E 23
};

I 39
struct nlist *nl;			/* all because we can't init unions */
int nllen;				/* # of nlist entries */

E 39
struct	savcom {
	union {
		struct	lsav *lp;
		float	u_pctcpu;
		struct	vsav *vp;
		int	s_ssiz;
I 16
D 19
		struct	sssav *ssp;	/* RAND 2/81 */
E 19
I 19
D 23
		struct	sssav *ssp;
E 19
E 16
	} sun;
E 23
I 23
	} s_un;
E 23
	struct	asav *ap;
D 8
} savcom[NPROC];
E 8
I 8
} *savcom;
E 8

struct	asav {
	char	*a_cmdp;
	int	a_flag;
D 2
	short	a_stat, a_uid, a_pid, a_nice;
E 2
I 2
	short	a_stat, a_uid, a_pid, a_nice, a_pri, a_slptime, a_time;
E 2
D 4
	size_t	a_size, a_rss;
E 4
I 4
	size_t	a_size, a_rss, a_tsiz, a_txtrss;
	short	a_xccount;
E 4
D 19
	char	a_tty[DIRSIZ+1];
E 19
I 19
	char	a_tty[MAXNAMLEN+1];
E 19
	dev_t	a_ttyd;
D 2
	time_t	a_time;
E 2
I 2
	time_t	a_cpu;
I 9
	size_t	a_maxrss;
E 9
E 2
};

char	*lhdr;
I 39
int	wcwidth;		/* width of the wchan field for sprintf*/
E 39
D 2
/*	    F S UID   PID  PPID CP PRI NICE ADDR  SZ  RSS WCHAN TTY TIME */
E 2
I 2
D 3
/*	     F UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN S  TT  TIME */
E 3
I 3
D 4
/*	     F UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN ST TT  TIME */
E 4
E 3
E 2
struct	lsav {
	short	l_ppid;
D 2
	char	l_cpu, l_pri;
E 2
I 2
D 54
	char	l_cpu;
E 54
I 54
	u_char	l_cpu;
E 54
E 2
	int	l_addr;
	caddr_t	l_wchan;
};

I 16
D 19
char	*sshdr;				/* RAND 2/81 */
struct	sssav {				/* RAND 2/81 */
	short 	ss_ppid;		/* RAND 2/81 */
	short	ss_brother;		/* RAND 2/81 */
	short	ss_sons;		/* RAND 2/81 */
};					/* RAND 2/81 */
E 19
I 19
D 23
char	*sshdr;
struct	sssav {
	short 	ss_ppid;
	short	ss_brother;
	short	ss_sons;
};
E 19

E 23
E 16
char	*uhdr;
D 2
/*	 USER       PID %CPU NICE  SZ  RSS TTY TIME */
E 2
I 2
D 3
/*	USER       PID %CPU NICE  SZ  RSS TT F  TIME */
E 3
I 3
D 4
/*	USER       PID %CPU NI   SZ  RSS TT ST TIME */
E 3
E 2

E 4
char	*shdr;
D 2
/*	 SSIZ   PID TTY TIME */
E 2
I 2
D 3
/*	SSIZ   PID TT S  TIME */
E 3
I 3
D 4
/*	SSIZ   PID TT ST TIME */
E 4
E 3
E 2

char	*vhdr;
D 2
/*	F     PID TTY  TIME TIM SL  MINFLT  MAJFLT SIZE  RSS  SRS TSIZ TRS PF*/
E 2
I 2
D 3
/*	F     PID TT  TIME RES SL  MINFLT  MAJFLT SIZE  RSS  SRS TSIZ TRS PF*/
E 3
I 3
D 4
/*	   PID TT ST    TIME RES SL MINFLT MAJFLT SIZE  RSS  SRS TSIZ TRS %CP*/
E 4
E 3
E 2
struct	vsav {
D 2
	short	v_slptime, v_pri;
E 2
D 4
	u_int	v_minflt, v_majflt;
	size_t	v_swrss, v_tsiz, v_txtrss, v_txtswrss;
	short	v_xccount;
D 3
	short	v_aveflt;
E 3
I 3
	short	v_pctcpu;
E 4
I 4
	u_int	v_majflt;
	size_t	v_swrss, v_txtswrss;
	float	v_pctcpu;
E 4
E 3
};

D 29
struct	proc proc[8];		/* 8 = a few, for less syscalls */
E 29
I 29
#define	NPROC	16

struct	proc proc[NPROC];		/* a few, for less syscalls */
E 29
struct	proc *mproc;
struct	text *text;

I 7
D 19
int	paduser1;		/* avoid hardware mem clobbering botch */
E 19
E 7
union {
	struct	user user;
	char	upages[UPAGES][NBPG];
} user;
#define u	user.user
I 7
D 19
int	paduser2;		/* avoid hardware mem clobbering botch */
E 19
E 7

D 29
#define clear(x) 	((int)x & 0x7fffffff)
E 29
I 29
#ifndef	PSFILE
char	*psdb	= "/etc/psdatabase";
#else
char	*psdb	= PSFILE;
#endif
E 29

D 42
int	chkpid;
E 42
I 42
int	chkpid = -1;
E 42
D 16
int	aflg, cflg, eflg, gflg, kflg, lflg, sflg, uflg, vflg, xflg;
E 16
I 16
D 19
int	aflg, cflg, eflg, gflg, kflg, lflg, sflg, ssflg,  /* RAND 2/81 */
E 19
I 19
D 23
int	aflg, cflg, eflg, gflg, kflg, lflg, sflg, ssflg,
E 19
	nonssflg, uflg, vflg, xflg;
E 23
I 23
D 39
int	aflg, cflg, eflg, gflg, kflg, lflg, sflg,
E 39
I 39
int	aflg, cflg, eflg, gflg, kflg, lflg, nflg, sflg,
E 39
D 29
	uflg, vflg, xflg;
E 29
I 29
	uflg, vflg, xflg, Uflg;
I 39
int	nchans;				/* total # of wait channels */
E 39
E 29
E 23
E 16
char	*tptr;
D 2
char	*gettty(), *getcmd(), *getname(), *savestr(), *alloc();
E 2
I 2
D 29
char	*gettty(), *getcmd(), *getname(), *savestr(), *alloc(), *state();
E 29
I 29
char	*gettty(), *getcmd(), *getname(), *savestr(), *state();
E 29
I 16
D 19
char	*rindex();		/* RAND 2/81 */
E 19
I 19
char	*rindex(), *calloc(), *sbrk(), *strcpy(), *strcat(), *strncat();
I 24
D 29
char	*index(), *ttyname(), mytty[16];
E 29
I 29
D 36
char	*strncpy(), *index(), *ttyname(), mytty[16];
E 36
I 36
char	*strncpy(), *index(), *ttyname(), mytty[MAXPATHLEN+1];
I 38
D 39
char	*malloc();
E 39
I 39
char	*malloc(), *getchan();
E 39
E 38
E 36
E 29
E 24
long	lseek();
I 29
off_t	vtophys();
E 29
E 19
E 16
I 3
D 4
double	pcpu();
E 4
I 4
double	pcpu(), pmem();
I 39
int	wchancomp();
E 39
E 4
E 3
E 2
int	pscomp();
D 2
int	nswap;
E 2
I 2
int	nswap, maxslp;
I 8
struct	text *atext;
E 8
I 3
double	ccpu;
I 4
int	ecmx;
E 4
E 3
E 2
D 29
struct	pte *Usrptma, *usrpt;
E 29
I 29
struct	pte *Usrptmap, *usrpt;
E 29
I 8
D 23
int	nproc, ntext, hz;
E 23
I 23
int	nproc, ntext;
I 26
int	dmmin, dmmax;
I 29
struct	pte *Sysmap;
int	Syssize;
E 29
E 26
E 23
E 8

I 29
D 38
#ifndef	MAXTTYS
#define	MAXTTYS		256
#endif

E 38
int	nttys;

E 29
struct	ttys {
D 19
	char	name[DIRSIZ+1];
E 19
I 19
D 29
	char	name[MAXNAMLEN+1];
E 29
E 19
	dev_t	ttyd;
D 29
	struct	ttys *next;
E 29
D 38
	struct	ttys *cand;
E 38
I 38
	int cand;
E 38
D 29
} *allttys, *cand[16];
E 29
I 29
	char	name[MAXNAMLEN+1];
D 38
} allttys[MAXTTYS], *cand[16];
E 38
I 38
} *allttys;
int cand[16] = {-1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1};
struct lttys {
	struct ttys ttys;
	struct lttys *next;
} *lallttys;
E 38
E 29

I 39
/*
 * struct for the symbolic wait channel info
 *
 * WNAMESIZ is the max # of chars saved of the symbolic wchan gleaned
 * from the namelist.  Normally, only WSNAMESIZ are printed in the long
 * format, unless the terminal width is greater than WTSIZ wide.
 */
#define WNAMESIZ	12
#define WSNAMESIZ	6
#define WTSIZ		95
E 39
I 38

I 39
struct wchan {
	char	wc_name[WNAMESIZ+1];	/* symbolic name */
	caddr_t wc_caddr;		/* addr in kmem */
} *wchanhd;				/* an array sorted by wc_caddr */

#define NWCINDEX	10		/* the size of the index array */

caddr_t wchan_index[NWCINDEX];		/* used to speed searches */
/*
 * names listed here are not kept as wait channels -- this is used to 
 * remove names that confuse ps, like symbols that define the end of an
 * array that happen to be equal to the next symbol.
 */
char *wchan_stop_list[] = {
	"umbabeg",
	"umbaend",
	"calimit",
	NULL
};

E 39
E 38
D 8
struct	savcom savcom[NPROC];
E 8
int	npr;

int	cmdstart;
int	twidth;
I 34
D 35
struct winsize win;
E 35
I 35
struct	winsize win;
E 35
E 34
char	*kmemf, *memf, *swapf, *nlistf;
D 20
int	kmem, mem, swap;
E 20
I 20
int	kmem, mem, swap = -1;
E 20
I 4
D 5
int	rawcpu;
E 5
I 5
int	rawcpu, sumcpu;
E 5
E 4

int	pcbpf;
int	argaddr;
D 35
extern	char _sobuf[];
E 35

I 23
D 27
#define	pgtok(a)	((a)*CLBYTES/1024)
E 27
I 27
#define	pgtok(a)	((a)/(1024/NBPG))
E 27

E 23
main(argc, argv)
	char **argv;
{
	register int i, j;
	register char *ap;
	int uid;
	off_t procp;
I 34
	int width;
E 34

D 20
	if (chdir("/dev") < 0) {
		perror("/dev");
		exit(1);
	}
E 20
D 34
	twidth = 80;
E 34
I 34
D 43
	if (ioctl(0, TIOCGWINSZ, &win) == -1)
E 43
I 43
	if (ioctl(1, TIOCGWINSZ, &win) == -1)
E 43
		twidth = 80;
	else
		twidth = (win.ws_col == 0 ? 80 : win.ws_col);
E 34
I 16
D 20

E 20
D 19
	if (ap = rindex(argv[0], '/'))		/* RAND 2/81 */
E 19
I 19
D 23
	if (ap = rindex(argv[0], '/'))
E 19
		ap++;
	else
		ap = argv[0];
	if (*ap == 's')				/* If name starts with 's' */
		ssflg++;

E 23
E 16
D 19
	setbuf(stdout, _sobuf);
E 19
	argc--, argv++;
	if (argc > 0) {
		ap = argv[0];
		while (*ap) switch (*ap++) {

I 4
		case 'C':
D 16
			rawcpu++;
E 16
I 16
D 23
			rawcpu++; nonssflg++;
E 23
I 23
			rawcpu++;
E 23
E 16
			break;
I 5
		case 'S':
			sumcpu++;
			break;
I 29

		case 'U':
			Uflg++;
			break;

E 29
E 5
E 4
		case 'a':
			aflg++;
			break;
		case 'c':
D 16
			cflg = !cflg;
E 16
I 16
D 23
			cflg = !cflg; nonssflg++;
E 23
I 23
			cflg = !cflg;
E 23
E 16
			break;
		case 'e':
D 16
			eflg++;
E 16
I 16
D 23
			eflg++; nonssflg++;
E 23
I 23
			eflg++;
E 23
E 16
			break;
		case 'g':
D 16
			gflg++;
E 16
I 16
D 23
			gflg++; nonssflg++;
E 23
I 23
			gflg++;
E 23
E 16
			break;
		case 'k':
D 16
			kflg++;
E 16
I 16
D 23
			kflg++; nonssflg++;
E 23
I 23
			kflg++;
E 23
E 16
			break;
		case 'l':
D 16
			lflg++;
E 16
I 16
D 23
			lflg++; nonssflg++;
E 23
I 23
			lflg++;
E 23
E 16
			break;
I 39
		case 'n':
			nflg++;
			break;
E 39
		case 's':
D 16
			sflg++;
E 16
I 16
D 23
			sflg++; nonssflg++;
E 23
I 23
			sflg++;
E 23
E 16
			break;
		case 't':
			if (*ap)
				tptr = ap;
I 24
D 36
			else if ((tptr = ttyname(2)) != 0) {
				strcpy(mytty, tptr);
				if ((tptr = index(mytty,'y')) != 0)
					tptr++;
E 36
I 36
			else if ((tptr = ttyname(0)) != 0) {
				tptr = strcpy(mytty, tptr);
				if (strncmp(tptr, "/dev/", 5) == 0)
					tptr += 5;
E 36
			}
I 36
			if (strncmp(tptr, "tty", 3) == 0)
				tptr += 3;
E 36
E 24
D 16
			aflg++;
E 16
I 16
D 23
			aflg++; nonssflg++;
E 23
I 23
			aflg++;
E 23
E 16
			gflg++;
D 23
			if (*tptr == '?')
E 23
I 23
			if (tptr && *tptr == '?')
E 23
				xflg++;
			while (*ap)
				ap++;
			break;
D 16
		case 'u':
			uflg++;
E 16
I 16
		case 'u': 
D 23
			uflg++; nonssflg++;
E 23
I 23
			uflg++;
E 23
E 16
			break;
		case 'v':
			cflg = 1;
D 16
			vflg++;
E 16
I 16
D 23
			vflg++; nonssflg++;
E 23
I 23
			vflg++;
E 23
E 16
			break;
		case 'w':
D 34
			if (twidth == 80)
E 34
I 34
			if (twidth < 132)
E 34
				twidth = 132;
			else
				twidth = BUFSIZ;
			break;
		case 'x':
			xflg++;
			break;
I 16
D 23
		case 'y':		/* Rand 2/81 */
			ssflg++;
			break;
E 23
E 16
		default:
			if (!isdigit(ap[-1]))
				break;
			chkpid = atoi(--ap);
			*ap = 0;
D 16
			aflg++;
E 16
I 16
D 23
			aflg++;	nonssflg++;
E 23
I 23
			aflg++;
E 23
E 16
			xflg++;
			break;
		}
	}
I 16
D 19
	if (ssflg) {			/* RAND 2/81 */
E 19
I 19
D 23
	if (ssflg) {
E 19
		if (nonssflg) {
			fprintf (stderr, "Usage: ss [axwS]\n");
			exit(1);
		}
		uflg++;
		gflg++;
	}
E 23
D 20

E 20
E 16
	openfiles(argc, argv);
	getkvars(argc, argv);
I 20
D 29
	if (chdir("/dev") < 0) {
		perror("/dev");
		exit(1);
	}
E 20
	getdev();
E 29
	uid = getuid();
	printhdr();
D 8
	procp = nl[X_PROC].n_value;
	for (i=0; i<NPROC; i += 8) {
E 8
I 8
	procp = getw(nl[X_PROC].n_value);
	nproc = getw(nl[X_NPROC].n_value);
D 21
	hz = getw(nl[X_HZ].n_value);
E 21
D 29
	savcom = (struct savcom *)calloc(nproc, sizeof (*savcom));
	for (i=0; i<nproc; i += 8) {
E 29
I 29
	savcom = (struct savcom *)calloc((unsigned) nproc, sizeof (*savcom));
	for (i=0; i<nproc; i += NPROC) {
E 29
E 8
D 18
		lseek(kmem, (char *)procp, 0);
E 18
I 18
D 19
		klseek(kmem, (char *)procp, 0);
E 19
I 19
		klseek(kmem, (long)procp, 0);
E 19
E 18
D 8
		j = NPROC - i;
E 8
I 8
		j = nproc - i;
E 8
D 29
		if (j > 8)
			j = 8;
E 29
I 29
		if (j > NPROC)
			j = NPROC;
E 29
		j *= sizeof (struct proc);
D 20
		if (read(kmem, (char *)proc, j) != j)
E 20
I 20
		if (read(kmem, (char *)proc, j) != j) {
E 20
			cantread("proc table", kmemf);
I 20
			exit(1);
		}
E 20
		procp += j;
		for (j = j / sizeof (struct proc) - 1; j >= 0; j--) {
			mproc = &proc[j];
			if (mproc->p_stat == 0 ||
			    mproc->p_pgrp == 0 && xflg == 0)
D 2
			continue;
E 2
I 2
				continue;
E 2
			if (tptr == 0 && gflg == 0 && xflg == 0 &&
D 18
			    mproc->p_ppid == 1 && (mproc->p_flag&SDETACH) == 0)
E 18
I 18
			    mproc->p_ppid == 1)
E 18
				continue;
D 29
			if (uid != mproc->p_uid && aflg==0 ||
			    chkpid != 0 && chkpid != mproc->p_pid)
E 29
I 29
			if (uid != mproc->p_uid && aflg==0)
E 29
				continue;
I 29
D 42
			if (chkpid != 0 && chkpid != mproc->p_pid)
E 42
I 42
			if (chkpid != -1 && chkpid != mproc->p_pid)
E 42
				continue;
E 29
			if (vflg && gflg == 0 && xflg == 0) {
				if (mproc->p_stat == SZOMB ||
				    mproc->p_flag&SWEXIT)
					continue;
				if (mproc->p_slptime > MAXSLP &&
				    (mproc->p_stat == SSLEEP ||
				     mproc->p_stat == SSTOP))
				continue;
			}
			save();
		}
	}
I 34
	width = twidth - cmdstart - 2;
	if (width < 0)
		width = 0;
E 34
D 29
	qsort(savcom, npr, sizeof(savcom[0]), pscomp);
E 29
I 29
	qsort((char *) savcom, npr, sizeof(savcom[0]), pscomp);
E 29
I 16
D 19
	if (ssflg) {			/* RAND 2/81 */
E 19
I 19
D 23
	if (ssflg) {
E 19
		walk(npr);
		exit (npr == 0);
	}
E 23
E 16
	for (i=0; i<npr; i++) {
		register struct savcom *sp = &savcom[i];
		if (lflg)
			lpr(sp);
		else if (vflg)
			vpr(sp);
		else if (uflg)
			upr(sp);
		else
			spr(sp);
D 36
		if (sp->ap->a_flag & SWEXIT)
			printf(" <exiting>");
		else if (sp->ap->a_stat == SZOMB)
E 36
I 36
		if (sp->ap->a_stat == SZOMB)
E 36
D 54
			printf(" <defunct>");
E 54
I 54
			printf(" %.*s", twidth - cmdstart - 2, "<defunct>");
E 54
I 36
		else if (sp->ap->a_flag & SWEXIT)
D 54
			printf(" <exiting>");
E 54
I 54
			printf(" %.*s", twidth - cmdstart - 2, "<exiting>");
E 54
E 36
		else if (sp->ap->a_pid == 0)
D 54
			printf(" swapper");
E 54
I 54
			printf(" %.*s", twidth - cmdstart - 2, "swapper");
E 54
		else if (sp->ap->a_pid == 2)
D 54
			printf(" pagedaemon");
E 54
I 54
			printf(" %.*s", twidth - cmdstart - 2, "pagedaemon");
E 54
I 11
D 36
		else if (sp->ap->a_pid == 3 && sp->ap->a_flag & SSYS)
D 14
			printf(" net input");
E 14
I 14
			printf(" ip input");
E 36
E 14
E 11
		else
			printf(" %.*s", twidth - cmdstart - 2, sp->ap->a_cmdp);
		printf("\n");
	}
	exit(npr == 0);
}

I 8
getw(loc)
D 19
	off_t loc;
E 19
I 19
	unsigned long loc;
E 19
{
D 29
	long word;
E 29
I 29
	int word;
E 29

D 18
	lseek(kmem, loc, 0);
E 18
I 18
D 19
	klseek(kmem, loc, 0);
E 18
	if (read(kmem, &word, sizeof (word)) != sizeof (word))
E 19
I 19
	klseek(kmem, (long)loc, 0);
	if (read(kmem, (char *)&word, sizeof (word)) != sizeof (word))
E 19
		printf("error reading kmem at %x\n", loc);
	return (word);
}

I 18
klseek(fd, loc, off)
D 19
	int fd, loc, off;
E 19
I 19
	int fd;
	long loc;
	int off;
E 19
{
D 29

	if (kflg)
		loc &= 0x7fffffff;
E 29
I 29
	if (kflg) {
		if ((loc = vtophys(loc)) == -1)
			return;
	}
E 29
D 19
	lseek(fd, loc, off);
E 19
I 19
	(void) lseek(fd, (long)loc, off);
E 19
}

I 44
/*
 * Version allows change of db format w/o temporarily bombing ps's
 */
char thisversion[4] = "V2";		/* length must remain 4 */

E 44
I 29
writepsdb(unixname)
	char *unixname;
{
D 39
	int nllen;
E 39
	register FILE *fp;
I 38
	struct lttys *lt;
I 44
	struct stat stb;
E 44
E 38

I 36
	setgid(getgid());
E 36
	setuid(getuid());
	if ((fp = fopen(psdb, "w")) == NULL) {
		perror(psdb);
		exit(1);
	} else
		fchmod(fileno(fp), 0644);
I 44

D 46
	fwrite(thisversion, sizeof (thisversion), 1, fp);
E 46
I 46
	fwrite(thisversion, sizeof thisversion, 1, fp);
E 46
	fwrite(unixname, strlen(unixname) + 1, 1, fp);
	if (stat(unixname, &stb) < 0)
		stb.st_mtime = 0;
D 46
	fwrite((char *) &stb.st_mtime, sizeof (stb.st_mtime), 1, fp);
E 46
I 46
	fwrite((char *) &stb.st_mtime, sizeof stb.st_mtime, 1, fp);
E 46

E 44
D 39
	nllen = sizeof nl / sizeof (struct nlist);
E 39
	fwrite((char *) &nllen, sizeof nllen, 1, fp);
	fwrite((char *) nl, sizeof (struct nlist), nllen, fp);
I 38
	fwrite((char *) cand, sizeof (cand), 1, fp);
E 38
	fwrite((char *) &nttys, sizeof nttys, 1, fp);
D 38
	fwrite((char *) allttys, sizeof (struct ttys), nttys, fp);
E 38
I 38
	for (lt = lallttys ; lt ; lt = lt->next)
		fwrite((char *)&lt->ttys, sizeof (struct ttys), 1, fp);
I 39
	fwrite((char *) &nchans, sizeof nchans, 1, fp);
	fwrite((char *) wchanhd, sizeof (struct wchan), nchans, fp);
	fwrite((char *) wchan_index, sizeof (caddr_t), NWCINDEX, fp);
E 39
E 38
D 44
	fwrite(unixname, strlen(unixname) + 1, 1, fp);
E 44
	fclose(fp);
}

readpsdb(unixname)
	char *unixname;
{
D 39
	int nllen;
E 39
	register i;
	register FILE *fp;
	char unamebuf[BUFSIZ];
	char *p	= unamebuf;
I 44
	char dbversion[sizeof thisversion];
	struct stat stb;
	time_t dbmtime;
E 44
	extern int errno;

	if ((fp = fopen(psdb, "r")) == NULL) {
		if (errno == ENOENT)
			return (0);
		perror(psdb);
		exit(1);
	}

I 44
	/*
	 * Does the db file match this unix?
	 */
	fread(dbversion, sizeof dbversion, 1, fp);
	if (bcmp(thisversion, dbversion, sizeof thisversion))
		goto bad;
	while ((*p = getc(fp)) != '\0')
		p++;
	if (strcmp(unixname, unamebuf))
		goto bad;
	fread((char *) &dbmtime, sizeof dbmtime, 1, fp);
	if (stat(unixname, &stb) < 0)
		stb.st_mtime = 0;
	if (stb.st_mtime != dbmtime)
		goto bad;

E 44
	fread((char *) &nllen, sizeof nllen, 1, fp);
I 39
	nl = (struct nlist *) malloc (nllen * sizeof (struct nlist));
E 39
	fread((char *) nl, sizeof (struct nlist), nllen, fp);
I 38
	fread((char *) cand, sizeof (cand), 1, fp);
E 38
	fread((char *) &nttys, sizeof nttys, 1, fp);
I 38
	allttys = (struct ttys *)malloc(sizeof(struct ttys)*nttys);
	if (allttys == NULL) {
		fprintf(stderr, "ps: Can't malloc space for tty table\n");
		exit(1);
	}
E 38
	fread((char *) allttys, sizeof (struct ttys), nttys, fp);
I 39
	fread((char *) &nchans, sizeof nchans, 1, fp);
	wchanhd = (struct wchan *) malloc(nchans * sizeof (struct wchan));
	if (wchanhd == NULL) {
		fprintf(stderr, "ps: Can't malloc space for wait channels\n");
		nflg++;
		fseek(fp, (long) nchans * sizeof (struct wchan), 1);
	} else
		fread((char *) wchanhd, sizeof (struct wchan), nchans, fp);
	fread((char *) wchan_index, sizeof (caddr_t), NWCINDEX, fp);
E 39
D 44
	while ((*p = getc(fp)) != '\0')
		p++;
	return (strcmp(unixname, unamebuf) == 0);
E 44
I 44
	fclose(fp);
	return(1);

bad:
	fclose(fp);
	return(0);
E 44
}

E 29
E 18
E 8
openfiles(argc, argv)
	char **argv;
{

D 20
	kmemf = "kmem";
E 20
I 20
	kmemf = "/dev/kmem";
E 20
	if (kflg)
D 20
		kmemf = argc > 1 ? argv[1] : "/vmcore";
E 20
I 20
		kmemf = argc > 2 ? argv[2] : "/vmcore";
E 20
	kmem = open(kmemf, 0);
	if (kmem < 0) {
		perror(kmemf);
		exit(1);
	}
	if (kflg)  {
		mem = kmem;
		memf = kmemf;
	} else {
D 20
		memf = "mem";
E 20
I 20
		memf = "/dev/mem";
E 20
		mem = open(memf, 0);
		if (mem < 0) {
			perror(memf);
			exit(1);
		}
	}
D 20
	swapf = argc>2 ? argv[2]: "drum";
	swap = open(swapf, 0);
	if (swap < 0) {
		perror(swapf);
		exit(1);
E 20
I 20
	if (kflg == 0 || argc > 3) {
		swapf = argc>3 ? argv[3]: "/dev/drum";
		swap = open(swapf, 0);
		if (swap < 0) {
			perror(swapf);
			exit(1);
		}
E 20
	}
}

getkvars(argc, argv)
	char **argv;
{
I 39
	int faildb = 0;			/* true if psdatabase init failed */
I 44
	int i;
E 44
E 39
D 29
	register struct nlist *nlp;
E 29

D 20
	nlistf = argc > 3 ? argv[3] : "/vmunix";
E 20
I 20
	nlistf = argc > 1 ? argv[1] : "/vmunix";
E 20
D 29
	nlist(nlistf, nl);
E 29
I 29
	if (Uflg) {
I 39
		init_nlist();
E 39
		nlist(nlistf, nl);
I 39
		getvchans();
E 39
		getdev();
		writepsdb(nlistf);
		exit (0);
	} else if (!readpsdb(nlistf)) {
I 39
		init_nlist();
E 39
		if (!kflg)
D 39
			nl[X_SYSMAP].n_name = "";
E 39
I 39
			nl[X_SYSMAP].n_un.n_name = "";
		faildb = 1;
E 39
		nlist(nlistf, nl);
I 31
D 36
		nttys =  0;
E 36
I 36
		nttys = 0;
E 36
E 31
		getdev();
	}

E 29
	if (nl[0].n_type == 0) {
		fprintf(stderr, "%s: No namelist\n", nlistf);
		exit(1);
	}
D 29
	if (kflg)
		for (nlp = nl; nlp < &nl[sizeof (nl)/sizeof (nl[0])]; nlp++)
			nlp->n_value = clear(nlp->n_value);
I 20
	usrpt = (struct pte *)nl[X_USRPT].n_value;	/* don't clear!! */
E 20
	Usrptma = (struct pte *)nl[X_USRPTMA].n_value;
E 29
I 29
	if (kflg) {
		/* We must do the sys map first because klseek uses it */
		long	addr;

		Syssize = nl[X_SYSSIZE].n_value;
		Sysmap = (struct pte *)
			calloc((unsigned) Syssize, sizeof (struct pte));
		if (Sysmap == NULL) {
			fprintf(stderr, "Out of space for Sysmap\n");
			exit(1);
		}
		addr = (long) nl[X_SYSMAP].n_value;
D 48
		addr &= ~0x80000000;
E 48
I 48
		addr &= ~KERNBASE;
E 48
		(void) lseek(kmem, addr, 0);
		read(kmem, (char *) Sysmap, Syssize * sizeof (struct pte));
	}
I 39
	if (faildb)
		getvchans();
E 39
	usrpt = (struct pte *)nl[X_USRPT].n_value;
	Usrptmap = (struct pte *)nl[X_USRPTMAP].n_value;
E 29
D 20
	usrpt = (struct pte *)nl[X_USRPT].n_value;
E 20
D 18
	lseek(kmem, (long)nl[X_NSWAP].n_value, 0);
E 18
I 18
	klseek(kmem, (long)nl[X_NSWAP].n_value, 0);
E 18
D 19
	if (read(kmem, &nswap, sizeof (nswap)) != sizeof (nswap)) {
E 19
I 19
	if (read(kmem, (char *)&nswap, sizeof (nswap)) != sizeof (nswap)) {
E 19
		cantread("nswap", kmemf);
		exit(1);
	}
I 2
D 18
	lseek(kmem, (long)nl[X_MAXSLP].n_value, 0);
E 18
I 18
	klseek(kmem, (long)nl[X_MAXSLP].n_value, 0);
E 18
D 19
	if (read(kmem, &maxslp, sizeof (maxslp)) != sizeof (maxslp)) {
E 19
I 19
	if (read(kmem, (char *)&maxslp, sizeof (maxslp)) != sizeof (maxslp)) {
E 19
		cantread("maxslp", kmemf);
		exit(1);
	}
I 3
D 18
	lseek(kmem, (long)nl[X_CCPU].n_value, 0);
E 18
I 18
	klseek(kmem, (long)nl[X_CCPU].n_value, 0);
E 18
D 19
	if (read(kmem, &ccpu, sizeof (ccpu)) != sizeof (ccpu)) {
E 19
I 19
	if (read(kmem, (char *)&ccpu, sizeof (ccpu)) != sizeof (ccpu)) {
E 19
		cantread("ccpu", kmemf);
		exit(1);
	}
E 3
E 2
D 4
	if (vflg) {
E 4
I 4
D 18
	lseek(kmem, (long)nl[X_ECMX].n_value, 0);
E 18
I 18
	klseek(kmem, (long)nl[X_ECMX].n_value, 0);
E 18
D 19
	if (read(kmem, &ecmx, sizeof (ecmx)) != sizeof (ecmx)) {
E 19
I 19
	if (read(kmem, (char *)&ecmx, sizeof (ecmx)) != sizeof (ecmx)) {
E 19
		cantread("ecmx", kmemf);
		exit(1);
	}
	if (uflg || vflg) {
E 4
D 8
		text = (struct text *)alloc(NTEXT * sizeof (struct text));
E 8
I 8
		ntext = getw(nl[X_NTEXT].n_value);
D 29
		text = (struct text *)alloc(ntext * sizeof (struct text));
E 29
I 29
		text = (struct text *)
			calloc((unsigned) ntext, sizeof (struct text));
E 29
E 8
		if (text == 0) {
			fprintf(stderr, "no room for text table\n");
			exit(1);
		}
D 8
		lseek(kmem, (long)nl[X_TEXT].n_value, 0);
		if (read(kmem, (char *)text, NTEXT * sizeof (struct text))
		    != NTEXT * sizeof (struct text)) {
E 8
I 8
		atext = (struct text *)getw(nl[X_TEXT].n_value);
D 18
		lseek(kmem, (int)atext, 0);
E 18
I 18
D 19
		klseek(kmem, (int)atext, 0);
E 19
I 19
		klseek(kmem, (long)atext, 0);
E 19
E 18
		if (read(kmem, (char *)text, ntext * sizeof (struct text))
		    != ntext * sizeof (struct text)) {
E 8
			cantread("text table", kmemf);
			exit(1);
		}
	}
I 26
	dmmin = getw(nl[X_DMMIN].n_value);
	dmmax = getw(nl[X_DMMAX].n_value);
E 26
}

I 39
/*
 * get the valloc'ed kernel variables for symbolic wait channels
 */
getvchans()
{
	int i, tmp;

	if (nflg)
		return;

#define addv(i) 	addchan(&nl[i].n_un.n_name[1], getw(nl[i].n_value))
	addv(X_INODE);
	addv(X_FILE);
	addv(X_PROC);
	addv(X_TEXT);
	addv(X_CFREE);
	addv(X_CALLOUT);
	addv(X_SWAPMAP);
	addv(X_ARGMAP);
	addv(X_KERNELMAP);
	addv(X_MBMAP);
	addv(X_NCH);
	if (nl[X_QUOTA].n_value != 0) {	/* these are #ifdef QUOTA */
		addv(X_QUOTA);
		addv(X_DQUOT);
	}
	addv(X_SWBUF);
	addv(X_BUF);
	addv(X_CMAP);
	addv(X_BUFFERS);
	qsort(wchanhd, nchans, sizeof (struct wchan), wchancomp);
	for (i = 0; i < NWCINDEX; i++) {
		tmp = i * nchans;
		wchan_index[i] = wchanhd[tmp / NWCINDEX].wc_caddr;
	}
#undef addv
}
E 39
printhdr()
{
	char *hdr;

	if (sflg+lflg+vflg+uflg > 1) {
		fprintf(stderr, "ps: specify only one of s,l,v and u\n");
		exit(1);
	}
D 16
	hdr = lflg ? lhdr : (vflg ? vhdr : (uflg ? uhdr : shdr));
E 16
I 16
D 19
	hdr = ssflg ? sshdr : 		/* RAND 2/81 */
E 19
I 19
D 23
	hdr = ssflg ? sshdr :
E 19
		(lflg ? lhdr : 
E 23
I 23
D 39
	hdr = lflg ? lhdr : 
E 23
			(vflg ? vhdr : 
D 23
				(uflg ? uhdr : shdr))); 
E 23
I 23
				(uflg ? uhdr : shdr));
E 39
I 39
	if (lflg) {
		if (nflg)
			wcwidth = 6;
		else if (twidth > WTSIZ)
			wcwidth = -WNAMESIZ;
		else
			wcwidth = -WSNAMESIZ;
		if ((hdr = malloc(strlen(lhdr) + WNAMESIZ)) == NULL) {
			fprintf(stderr, "ps: out of memory\n");
			exit(1);
		}
D 49
		sprintf(hdr, lhdr, wcwidth, "WCHAN");
E 49
I 49
		(void)sprintf(hdr, lhdr, wcwidth, "WCHAN");
E 49
	} else if (vflg)
		hdr = vhdr;
	else if (uflg) {
		/* add enough on so that it can hold the sprintf below */
		if ((hdr = malloc(strlen(uhdr) + 10)) == NULL) {
			fprintf(stderr, "ps: out of memory\n");
			exit(1);
		}
D 49
		sprintf(hdr, uhdr, nflg ? " UID" : "USER    ");
E 49
I 49
		(void)sprintf(hdr, uhdr, nflg ? " UID" : "USER    ");
E 49
	} else
		hdr = shdr;
E 39
E 23
E 16
	if (lflg+vflg+uflg+sflg == 0)
D 2
		hdr += strlen(" SSIZ");
E 2
I 2
		hdr += strlen("SSIZ ");
E 2
	cmdstart = strlen(hdr);
	printf("%s COMMAND\n", hdr);
D 19
	fflush(stdout);
E 19
I 19
	(void) fflush(stdout);
E 19
}

cantread(what, fromwhat)
	char *what, *fromwhat;
{

D 20
	fprintf(stderr, "ps: error reading %s from %s", what, fromwhat);
E 20
I 20
	fprintf(stderr, "ps: error reading %s from %s\n", what, fromwhat);
E 20
}

D 19
struct	direct dbuf;
E 19
I 19
struct	direct *dbuf;
E 19
int	dialbase;

getdev()
{
D 19
	register FILE *df;
	register struct ttys *dp;
E 19
I 19
	register DIR *df;
I 38
	struct ttys *t;
	struct lttys *lt;
E 38
E 19

I 29
	if (chdir("/dev") < 0) {
		perror("/dev");
		exit(1);
	}
E 29
	dialbase = -1;
D 19
	if ((df = fopen(".", "r")) == NULL) {
E 19
I 19
	if ((df = opendir(".")) == NULL) {
E 19
		fprintf(stderr, "Can't open . in /dev\n");
		exit(1);
	}
D 19
	while (fread((char *)&dbuf, sizeof(dbuf), 1, df) == 1) {
		if (dbuf.d_ino == 0)
			continue;
		maybetty(dp);
	}
	fclose(df);
E 19
I 19
	while ((dbuf = readdir(df)) != NULL) 
		maybetty();
	closedir(df);
I 38
	allttys = (struct ttys *)malloc(sizeof(struct ttys)*nttys);
	if (allttys == NULL) {
		fprintf(stderr, "ps: Can't malloc space for tty table\n");
		exit(1);
	}
	for (lt = lallttys, t = allttys; lt ; lt = lt->next, t++)
		*t = lt->ttys;
E 38
E 19
}

/*
 * Attempt to avoid stats by guessing minor device
 * numbers from tty names.  Console is known,
 * know that r(hp|up|mt) are unlikely as are different mem's,
 * floppy, null, tty, etc.
 */
maybetty()
{
D 19
	register char *cp = dbuf.d_name;
E 19
I 19
	register char *cp = dbuf->d_name;
E 19
D 38
	register struct ttys *dp;
E 38
I 38
	static struct lttys *dp;
	struct lttys *olddp;
E 38
	int x;
	struct stat stb;

	switch (cp[0]) {

	case 'c':
		if (!strcmp(cp, "console")) {
			x = 0;
			goto donecand;
		}
		/* cu[la]? are possible!?! don't rule them out */
		break;

	case 'd':
		if (!strcmp(cp, "drum"))
D 19
			return (0);
E 19
I 19
			return;
E 19
		break;

	case 'f':
		if (!strcmp(cp, "floppy"))
D 19
			return (0);
E 19
I 19
			return;
E 19
		break;

	case 'k':
		cp++;
		if (*cp == 'U')
			cp++;
		goto trymem;

	case 'r':
		cp++;
D 31
		if (*cp == 'r' || *cp == 'u' || *cp == 'h')
			cp++;
E 31
#define is(a,b) cp[0] == 'a' && cp[1] == 'b'
D 31
		if (is(r,p) || is(u,p) || is(r,k) || is(r,m) || is(m,t)) {
E 31
I 31
D 35
		if (is(h,p) || is(r,a) || is(u,p) || is(r,k) 
		    || is(r,m) || is(m,t)) {
E 35
I 35
		if (is(h,p) || is(r,a) || is(u,p) || is(h,k) 
		    || is(r,b) || is(m,t)) {
E 35
E 31
			cp += 2;
			if (isdigit(*cp) && cp[2] == 0)
D 19
				return (0);
E 19
I 19
				return;
E 19
		}
		break;

	case 'm':
trymem:
		if (cp[0] == 'm' && cp[1] == 'e' && cp[2] == 'm' && cp[3] == 0)
D 19
			return (0);
E 19
I 19
			return;
E 19
I 14
		if (cp[0] == 'm' && cp[1] == 't')
D 19
			return (0);
E 19
I 19
			return;
E 19
E 14
		break;

	case 'n':
		if (!strcmp(cp, "null"))
I 35
			return;
		if (!strncmp(cp, "nrmt", 4))
			return;
		break;

	case 'p':
		if (cp[1] && cp[1] == 't' && cp[2] == 'y')
E 35
D 19
			return (0);
E 19
I 19
			return;
E 19
		break;

	case 'v':
		if ((cp[1] == 'a' || cp[1] == 'p') && isdigit(cp[2]) &&
		    cp[3] == 0)
D 19
			return (0);
E 19
I 19
			return;
E 19
		break;
	}
D 19
mightbe:
	cp = dbuf.d_name;
	while (cp < &dbuf.d_name[DIRSIZ] && *cp)
		cp++;
	--cp;
E 19
I 19
	cp = dbuf->d_name + dbuf->d_namlen - 1;
E 19
	x = 0;
	if (cp[-1] == 'd') {
		if (dialbase == -1) {
			if (stat("ttyd0", &stb) == 0)
				dialbase = stb.st_rdev & 017;
			else
				dialbase = -2;
		}
		if (dialbase == -2)
			x = 0;
		else
			x = 11;
	}
D 19
	if (cp > dbuf.d_name && isdigit(cp[-1]) && isdigit(*cp))
E 19
I 19
	if (cp > dbuf->d_name && isdigit(cp[-1]) && isdigit(*cp))
E 19
		x += 10 * (cp[-1] - ' ') + cp[0] - '0';
	else if (*cp >= 'a' && *cp <= 'f')
		x += 10 + *cp - 'a';
	else if (isdigit(*cp))
		x += *cp - '0';
	else
		x = -1;
donecand:
D 29
	dp = (struct ttys *)alloc(sizeof (struct ttys));
E 29
I 29
D 38
	if (nttys >= MAXTTYS) {
		fprintf(stderr, "ps: tty table overflow\n");
E 38
I 38
	olddp = dp;
	dp = (struct lttys *)malloc(sizeof(struct lttys));
	if (dp == NULL) {
		fprintf(stderr, "ps: Can't malloc space for tty table\n");
E 38
		exit(1);
	}
D 38
	dp = &allttys[nttys++];
E 29
D 19
	strncpy(dp->name, dbuf.d_name, DIRSIZ);
E 19
I 19
	(void) strcpy(dp->name, dbuf->d_name);
E 38
I 38
	if (lallttys == NULL)
		lallttys = dp;
	nttys++;
	if (olddp)
		olddp->next = dp;
	dp->next = NULL;
	(void) strcpy(dp->ttys.name, dbuf->d_name);
E 38
E 19
D 29
	dp->next = allttys;
	dp->ttyd = -1;
	allttys = dp;
E 29
I 29
	if (Uflg) {
D 38
		if (stat(dp->name, &stb) == 0 &&
E 38
I 38
		if (stat(dp->ttys.name, &stb) == 0 &&
E 38
		   (stb.st_mode&S_IFMT)==S_IFCHR)
D 38
			dp->ttyd = x = stb.st_rdev;
E 38
I 38
			dp->ttys.ttyd = x = stb.st_rdev;
E 38
		else {
			nttys--;
I 38
			if (lallttys == dp)
				lallttys = NULL;
			free(dp);
			dp = olddp;
			if (dp)
				dp->next = NULL;
E 38
			return;
		}
	} else
D 38
		dp->ttyd = -1;
E 38
I 38
		dp->ttys.ttyd = -1;
E 38
E 29
	if (x == -1)
		return;
	x &= 017;
D 38
	dp->cand = cand[x];
	cand[x] = dp;
E 38
I 38
	dp->ttys.cand = cand[x];
	cand[x] = nttys-1;
E 38
}

char *
gettty()
{
	register char *p;
	register struct ttys *dp;
	struct stat stb;
	int x;

	if (u.u_ttyp == 0)
D 55
		return("?");
E 55
I 55
		return(" ?");
E 55
	x = u.u_ttyd & 017;
D 38
	for (dp = cand[x]; dp; dp = dp->cand) {
E 38
I 38
	for (dp = &allttys[cand[x]]; dp != &allttys[-1];
	     dp = &allttys[dp->cand]) {
E 38
		if (dp->ttyd == -1) {
D 2
			if (stat(dp->name, &stb) == 0)
E 2
I 2
			if (stat(dp->name, &stb) == 0 &&
			   (stb.st_mode&S_IFMT)==S_IFCHR)
E 2
				dp->ttyd = stb.st_rdev;
			else
				dp->ttyd = -2;
		}
		if (dp->ttyd == u.u_ttyd)
			goto found;
	}
	/* ick */
D 29
	for (dp = allttys; dp; dp = dp->next) {
E 29
I 29
	for (dp = allttys; dp < &allttys[nttys]; dp++) {
E 29
		if (dp->ttyd == -1) {
D 14
			if (stat(dp->name, &stb) == 0)
E 14
I 14
			if (stat(dp->name, &stb) == 0 &&
			   (stb.st_mode&S_IFMT)==S_IFCHR)
E 14
				dp->ttyd = stb.st_rdev;
			else
				dp->ttyd = -2;
		}
		if (dp->ttyd == u.u_ttyd)
			goto found;
	}
	return ("?");
found:
	p = dp->name;
	if (p[0]=='t' && p[1]=='t' && p[2]=='y')
		p += 3;
	return (p);
}

save()
{
	register struct savcom *sp;
	register struct asav *ap;
	register char *cp;
I 4
	register struct text *xp;
E 4
	char *ttyp, *cmdp;

	if (mproc->p_stat != SZOMB && getu() == 0)
		return;
	ttyp = gettty();
D 16
	if (xflg == 0 && ttyp[0] == '?' || tptr && strcmpn(tptr, ttyp, 2))
E 16
I 16
	if (xflg == 0 && ttyp[0] == '?' || tptr && strncmp(tptr, ttyp, 2))
E 16
		return;
	sp = &savcom[npr];
	cmdp = getcmd();
	if (cmdp == 0)
		return;
D 29
	sp->ap = ap = (struct asav *)alloc(sizeof (struct asav));
E 29
I 29
	sp->ap = ap = (struct asav *)calloc(1, sizeof (struct asav));
E 29
	sp->ap->a_cmdp = cmdp;
#define e(a,b) ap->a = mproc->b
	e(a_flag, p_flag); e(a_stat, p_stat); e(a_nice, p_nice);
D 2
	e(a_uid, p_uid); e(a_pid, p_pid); e(a_rss, p_rssize);
E 2
I 2
D 4
	e(a_uid, p_uid); e(a_pid, p_pid); e(a_rss, p_rssize); e(a_pri, p_pri);
E 4
I 4
	e(a_uid, p_uid); e(a_pid, p_pid); e(a_pri, p_pri);
E 4
	e(a_slptime, p_slptime); e(a_time, p_time);
E 2
D 4
#undef e
E 4
	ap->a_tty[0] = ttyp[0];
	ap->a_tty[1] = ttyp[1] ? ttyp[1] : ' ';
	if (ap->a_stat == SZOMB) {
D 23
		register struct xproc *xp = (struct xproc *)mproc;

E 23
D 2
		ap->a_time = xp->xp_vm.vm_utime + xp->xp_vm.vm_stime;
E 2
I 2
D 21
		ap->a_cpu = xp->xp_vm.vm_utime + xp->xp_vm.vm_stime;
E 21
I 21
		ap->a_cpu = 0;
E 21
E 2
	} else {
		ap->a_size = mproc->p_dsize + mproc->p_ssize;
I 4
		e(a_rss, p_rssize); 
E 4
		ap->a_ttyd = u.u_ttyd;
D 2
		ap->a_time = u.u_vm.vm_utime + u.u_vm.vm_stime;
E 2
I 2
D 21
		ap->a_cpu = u.u_vm.vm_utime + u.u_vm.vm_stime;
E 21
I 21
		ap->a_cpu = u.u_ru.ru_utime.tv_sec + u.u_ru.ru_stime.tv_sec;
E 21
I 5
		if (sumcpu)
D 21
			ap->a_cpu += u.u_cvm.vm_utime + u.u_cvm.vm_stime;
E 21
I 21
			ap->a_cpu += u.u_cru.ru_utime.tv_sec + u.u_cru.ru_stime.tv_sec;
E 21
E 5
I 4
D 6
		if (mproc->p_textp) {
E 6
I 6
		if (mproc->p_textp && text) {
E 6
D 8
			xp = &text[mproc->p_textp -
				    (struct text *)nl[X_TEXT].n_value];
E 8
I 8
			xp = &text[mproc->p_textp - atext];
E 8
			ap->a_tsiz = xp->x_size;
			ap->a_txtrss = xp->x_rssize;
			ap->a_xccount = xp->x_ccount;
		}
E 4
E 2
	}
I 4
#undef e
E 4
D 2
	ap->a_time /= HZ;
E 2
I 2
D 8
	ap->a_cpu /= HZ;
E 8
I 8
D 21
	ap->a_cpu /= hz;
E 21
I 9
	ap->a_maxrss = mproc->p_maxrss;
E 9
E 8
E 2
	if (lflg) {
		register struct lsav *lp;

D 23
		sp->sun.lp = lp = (struct lsav *)alloc(sizeof (struct lsav));
E 23
I 23
D 29
		sp->s_un.lp = lp = (struct lsav *)alloc(sizeof (struct lsav));
E 29
I 29
		sp->s_un.lp = lp = (struct lsav *)
			calloc(1, sizeof (struct lsav));
E 29
E 23
#define e(a,b) lp->a = mproc->b
D 2
		e(l_ppid, p_ppid); e(l_cpu, p_cpu); e(l_pri, p_pri);
E 2
I 2
		e(l_ppid, p_ppid); e(l_cpu, p_cpu);
E 2
		if (ap->a_stat != SZOMB)
			e(l_wchan, p_wchan);
#undef e
		lp->l_addr = pcbpf;
	} else if (vflg) {
		register struct vsav *vp;
D 4
		register struct text *xp;
E 4

D 23
		sp->sun.vp = vp = (struct vsav *)alloc(sizeof (struct vsav));
E 23
I 23
D 29
		sp->s_un.vp = vp = (struct vsav *)alloc(sizeof (struct vsav));
E 29
I 29
		sp->s_un.vp = vp = (struct vsav *)
			calloc(1, sizeof (struct vsav));
E 29
E 23
#define e(a,b) vp->a = mproc->b
D 2
		e(v_slptime, p_slptime); e(v_pri, p_pri);
E 2
		if (ap->a_stat != SZOMB) {
D 3
			e(v_swrss, p_swrss); e(v_aveflt, p_aveflt);
E 3
I 3
			e(v_swrss, p_swrss);
E 3
D 4
			vp->v_minflt = u.u_vm.vm_minflt;
E 4
D 21
			vp->v_majflt = u.u_vm.vm_majflt;
E 21
I 21
			vp->v_majflt = u.u_ru.ru_majflt;
E 21
D 4
			if (mproc->p_textp) {
				xp = &text[mproc->p_textp -
				    (struct text *)nl[X_TEXT].n_value];
				vp->v_tsiz = xp->x_size;
				vp->v_txtrss = xp->x_rssize;
E 4
I 4
			if (mproc->p_textp)
E 4
				vp->v_txtswrss = xp->x_swrss;
D 4
				vp->v_xccount = xp->x_ccount;
			}
E 4
		}
I 3
		vp->v_pctcpu = pcpu();
E 3
#undef e
D 16
	} else if (uflg)
D 3
		sp->sun.u_pctcpu = 0.0;
E 3
I 3
		sp->sun.u_pctcpu = pcpu();
E 3
	else if (sflg) {
E 16
I 16
D 23
	} else if (uflg) {
D 19
		if (!ssflg) 		/* RAND 2/18 */
E 19
I 19
		if (!ssflg)
E 19
			sp->sun.u_pctcpu = pcpu();
		else {
			register struct sssav *ssp;

			sp->sun.ssp =ssp= (struct sssav *)alloc(sizeof (struct sssav));
			ssp->ss_ppid = mproc->p_ppid;
		}
	} else if (sflg) {
E 23
I 23
	} else if (uflg)
		sp->s_un.u_pctcpu = pcpu();
	else if (sflg) {
E 23
E 16
		if (ap->a_stat != SZOMB) {
			for (cp = (char *)u.u_stack;
D 8
			    cp < &user.upages[UPAGES][NBPG]; )
E 8
I 8
			    cp < &user.upages[UPAGES][0]; )
E 8
				if (*cp++)
					break;
D 8
			sp->sun.s_ssiz = (&user.upages[UPAGES][NBPG] - cp);
E 8
I 8
D 23
			sp->sun.s_ssiz = (&user.upages[UPAGES][0] - cp);
E 23
I 23
			sp->s_un.s_ssiz = (&user.upages[UPAGES][0] - cp);
E 23
E 8
		}
	}
I 16

E 16
	npr++;
}

I 3
double
I 4
pmem(ap)
	register struct asav *ap;
{
	double fracmem;
	int szptudot;

	if ((ap->a_flag&SLOAD) == 0)
		fracmem = 0.0;
	else {
		szptudot = UPAGES + clrnd(ctopt(ap->a_size+ap->a_tsiz));
		fracmem = ((float)ap->a_rss+szptudot)/CLSIZE/ecmx;
		if (ap->a_xccount)
			fracmem += ((float)ap->a_txtrss)/CLSIZE/
			    ap->a_xccount/ecmx;
	}
	return (100.0 * fracmem);
}

double
E 4
pcpu()
{
I 4
	time_t time;
E 4

D 4
	if (mproc->p_time == 0 || (mproc->p_flag&SLOAD) == 0)
E 4
I 4
	time = mproc->p_time;
	if (time == 0 || (mproc->p_flag&SLOAD) == 0)
E 4
		return (0.0);
D 4
	return (100.0 * mproc->p_pctcpu / (1.0 - exp(mproc->p_time * log(ccpu))));
E 4
I 4
	if (rawcpu)
		return (100.0 * mproc->p_pctcpu);
	return (100.0 * mproc->p_pctcpu / (1.0 - exp(time * log(ccpu))));
E 4
}

E 3
getu()
{
D 7
	struct pte *pteaddr, apte, arguutl[UPAGES+CLSIZE];
E 7
I 7
	struct pte *pteaddr, apte;
D 19
	int pad1;	/* avoid hardware botch */
E 19
	struct pte arguutl[UPAGES+CLSIZE];
D 19
	int pad2;	/* avoid hardware botch */
E 19
E 7
	register int i;
	int ncl, size;

	size = sflg ? ctob(UPAGES) : sizeof (struct user);
	if ((mproc->p_flag & SLOAD) == 0) {
I 20
		if (swap < 0)
			return (0);
E 20
D 19
		lseek(swap, ctob(mproc->p_swaddr), 0);
E 19
I 19
D 23
		(void) lseek(swap, (long)ctob(mproc->p_swaddr), 0);
E 23
I 23
		(void) lseek(swap, (long)dtob(mproc->p_swaddr), 0);
E 23
E 19
		if (read(swap, (char *)&user.user, size) != size) {
			fprintf(stderr, "ps: cant read u for pid %d from %s\n",
			    mproc->p_pid, swapf);
			return (0);
		}
		pcbpf = 0;
		argaddr = 0;
		return (1);
	}
I 18
D 29
	if (kflg)
		mproc->p_p0br = (struct pte *)clear(mproc->p_p0br);
E 18
	pteaddr = &Usrptma[btokmx(mproc->p_p0br) + mproc->p_szpt - 1];
E 29
I 29
	pteaddr = &Usrptmap[btokmx(mproc->p_p0br) + mproc->p_szpt - 1];
E 29
D 18
	lseek(kmem, kflg ? clear(pteaddr) : (int)pteaddr, 0);
E 18
I 18
D 19
	klseek(kmem, pteaddr, 0);
E 19
I 19
	klseek(kmem, (long)pteaddr, 0);
E 19
E 18
	if (read(kmem, (char *)&apte, sizeof(apte)) != sizeof(apte)) {
		printf("ps: cant read indir pte to get u for pid %d from %s\n",
D 29
		    mproc->p_pid, swapf);
E 29
I 29
		    mproc->p_pid, kmemf);
E 29
		return (0);
	}
D 19
	lseek(mem,
	    ctob(apte.pg_pfnum+1) - (UPAGES+CLSIZE) * sizeof (struct pte), 0);
E 19
I 19
D 20
	(void) lseek(mem,
E 20
I 20
D 29
	klseek(mem,
E 29
I 29
	lseek(mem,
E 29
E 20
	    (long)ctob(apte.pg_pfnum+1) - (UPAGES+CLSIZE) * sizeof (struct pte),
		0);
E 19
	if (read(mem, (char *)arguutl, sizeof(arguutl)) != sizeof(arguutl)) {
		printf("ps: cant read page table for u of pid %d from %s\n",
D 20
		    mproc->p_pid, swapf);
E 20
I 20
D 29
		    mproc->p_pid, kmemf);
E 29
I 29
		    mproc->p_pid, memf);
E 29
E 20
		return (0);
	}
	if (arguutl[0].pg_fod == 0 && arguutl[0].pg_pfnum)
		argaddr = ctob(arguutl[0].pg_pfnum);
	else
		argaddr = 0;
	pcbpf = arguutl[CLSIZE].pg_pfnum;
	ncl = (size + NBPG*CLSIZE - 1) / (NBPG*CLSIZE);
	while (--ncl >= 0) {
		i = ncl * CLSIZE;
D 19
		lseek(mem, ctob(arguutl[CLSIZE+i].pg_pfnum), 0);
E 19
I 19
D 20
		(void) lseek(mem, (long)ctob(arguutl[CLSIZE+i].pg_pfnum), 0);
E 20
I 20
D 29
		klseek(mem, (long)ctob(arguutl[CLSIZE+i].pg_pfnum), 0);
E 29
I 29
		lseek(mem, (long)ctob(arguutl[CLSIZE+i].pg_pfnum), 0);
E 29
E 20
E 19
		if (read(mem, user.upages[i], CLSIZE*NBPG) != CLSIZE*NBPG) {
			printf("ps: cant read page %d of u of pid %d from %s\n",
			    arguutl[CLSIZE+i].pg_pfnum, mproc->p_pid, memf);
			return(0);
		}
	}
	return (1);
}

char *
getcmd()
{
D 23
	char cmdbuf[BUFSIZ];
E 23
I 23
	char cmdbuf[CLSIZE*NBPG];
E 23
I 7
D 19
	int pad1;		/* avoid hardware botch */
E 19
E 7
	union {
		char	argc[CLSIZE*NBPG];
		int	argi[CLSIZE*NBPG/sizeof (int)];
	} argspac;
I 7
D 19
	int pad2;		/* avoid hardware botch */
E 19
E 7
	register char *cp;
	register int *ip;
	char c;
	int nbad;
	struct dblock db;
I 20
	char *file;
E 20

	if (mproc->p_stat == SZOMB || mproc->p_flag&(SSYS|SWEXIT))
		return ("");
	if (cflg) {
D 19
		strncpy(cmdbuf, u.u_comm, sizeof (u.u_comm));
E 19
I 19
		(void) strncpy(cmdbuf, u.u_comm, sizeof (u.u_comm));
E 19
		return (savestr(cmdbuf));
	}
	if ((mproc->p_flag & SLOAD) == 0 || argaddr == 0) {
I 20
		if (swap < 0)
			goto retucomm;
E 20
		vstodb(0, CLSIZE, &u.u_smap, &db, 1);
D 19
		lseek(swap, ctob(db.db_base), 0);
E 19
I 19
D 23
		(void) lseek(swap, (long)ctob(db.db_base), 0);
E 23
I 23
		(void) lseek(swap, (long)dtob(db.db_base), 0);
E 23
E 19
		if (read(swap, (char *)&argspac, sizeof(argspac))
		    != sizeof(argspac))
			goto bad;
I 20
		file = swapf;
E 20
	} else {
D 19
		lseek(mem, argaddr, 0);
E 19
I 19
D 20
		(void) lseek(mem, (long)argaddr, 0);
E 20
I 20
D 29
		klseek(mem, (long)argaddr, 0);
E 29
I 29
		lseek(mem, (long)argaddr, 0);
E 29
E 20
E 19
		if (read(mem, (char *)&argspac, sizeof (argspac))
		    != sizeof (argspac))
			goto bad;
I 20
		file = memf;
E 20
	}
	ip = &argspac.argi[CLSIZE*NBPG/sizeof (int)];
	ip -= 2;		/* last arg word and .long 0 */
	while (*--ip)
		if (ip == argspac.argi)
			goto retucomm;
	*(char *)ip = ' ';
	ip++;
	nbad = 0;
	for (cp = (char *)ip; cp < &argspac.argc[CLSIZE*NBPG]; cp++) {
		c = *cp & 0177;
		if (c == 0)
			*cp = ' ';
		else if (c < ' ' || c > 0176) {
			if (++nbad >= 5*(eflg+1)) {
				*cp++ = ' ';
				break;
			}
			*cp = '?';
		} else if (eflg == 0 && c == '=') {
			while (*--cp != ' ')
				if (cp <= (char *)ip)
					break;
			break;
		}
	}
	*cp = 0;
	while (*--cp == ' ')
		*cp = 0;
	cp = (char *)ip;
D 19
	strncpy(cmdbuf, cp, &argspac.argc[CLSIZE*NBPG] - cp);
E 19
I 19
	(void) strncpy(cmdbuf, cp, &argspac.argc[CLSIZE*NBPG] - cp);
E 19
	if (cp[0] == '-' || cp[0] == '?' || cp[0] <= ' ') {
D 19
		strcat(cmdbuf, " (");
		strncat(cmdbuf, u.u_comm, sizeof(u.u_comm));
		strcat(cmdbuf, ")");
E 19
I 19
		(void) strcat(cmdbuf, " (");
		(void) strncat(cmdbuf, u.u_comm, sizeof(u.u_comm));
		(void) strcat(cmdbuf, ")");
E 19
	}
I 2
D 29
/*
E 2
	if (xflg == 0 && gflg == 0 && tptr == 0 && cp[0] == '-')
		return (0);
I 2
*/
E 29
E 2
	return (savestr(cmdbuf));

bad:
D 20
	fprintf(stderr, "ps: error locating command name for pid %d\n",
	    mproc->p_pid);
E 20
I 20
	fprintf(stderr, "ps: error locating command name for pid %d from %s\n",
	    mproc->p_pid, file);
E 20
retucomm:
D 19
	strcpy(cmdbuf, " (");
	strncat(cmdbuf, u.u_comm, sizeof (u.u_comm));
	strcat(cmdbuf, ")");
E 19
I 19
	(void) strcpy(cmdbuf, " (");
	(void) strncat(cmdbuf, u.u_comm, sizeof (u.u_comm));
	(void) strcat(cmdbuf, ")");
E 19
	return (savestr(cmdbuf));
}

char	*lhdr =
D 2
"     F S UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN TTY TIME";
E 2
I 2
D 3
"     F UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN S  TT  TIME";
E 3
I 3
D 4
"     F UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN ST TT  TIME";
E 4
I 4
D 23
"     F UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN STAT TT  TIME";
E 23
I 23
D 30
"      F UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN STAT TT  TIME";
E 30
I 30
D 36
"      F UID   PID  PPID CP PRI NI ADDR  SZ  RSS WCHAN  STAT TT  TIME";
E 36
I 36
D 39
"      F UID   PID  PPID CP PRI NI ADDR  SZ  RSS  WCHAN STAT TT  TIME";
E 39
I 39
D 50
"      F UID   PID  PPID CP PRI NI ADDR  SZ  RSS %*s STAT TT  TIME";
E 50
I 50
D 52
"      F UID   PID  PPID CP PRI NI ADDR    SZ  RSS %*sSTAT TT  TIME";
E 52
I 52
D 54
"      F  UID   PID  PPID CP PRI NI ADDR    SZ  RSS %*sSTAT TT  TIME";
E 54
I 54
"     F  UID   PID  PPID CP PRI NI ADDR    SZ  RSS %*sSTAT TT  TIME";
E 54
E 52
E 50
E 39
E 36
E 30
E 23
E 4
E 3
E 2
lpr(sp)
	struct savcom *sp;
{
	register struct asav *ap = sp->ap;
D 23
	register struct lsav *lp = sp->sun.lp;
E 23
I 23
	register struct lsav *lp = sp->s_un.lp;
E 23

D 2
	printf("%6x %c%4d%6u%6u%3d%4d%2d%6x%4d%5d",
	    ap->a_flag, "0SWRIZT"[ap->a_stat], ap->a_uid,
	    ap->a_pid, lp->l_ppid, lp->l_cpu&0377, lp->l_pri-PZERO,
	    ap->a_nice-NZERO, lp->l_addr, ap->a_size, ap->a_rss);
E 2
I 2
D 23
	printf("%6x%4d%6u%6u%3d%4d%3d%5x%4d%5d",
E 23
I 23
D 50
	printf("%7x%4d%6u%6u%3d%4d%3d%5x%4d%5d",
E 50
I 50
D 52
	printf("%7x %3d %5u %5u %2d %3d %2d %4x %5d %4d",
E 52
I 52
D 54
	printf("%7x %4d %5u %5u %2d %3d %2d %4x %5d %4d",
E 52
E 50
E 23
	    ap->a_flag, ap->a_uid,
	    ap->a_pid, lp->l_ppid, lp->l_cpu&0377, ap->a_pri-PZERO,
D 23
	    ap->a_nice-NZERO, lp->l_addr, ap->a_size/2, ap->a_rss/2);
E 23
I 23
	    ap->a_nice-NZERO, lp->l_addr, pgtok(ap->a_size), pgtok(ap->a_rss));
E 54
I 54
	printf("%6x %4d %5u %5u %2d %3d %2d %4x %5d %4d",
	    (ap->a_flag &~ SPTECHG),				/* XXX */
	    ap->a_uid, ap->a_pid, lp->l_ppid,
	    lp->l_cpu > 99 ? 99 : lp->l_cpu, ap->a_pri-PZERO,
	    ap->a_nice, lp->l_addr, pgtok(ap->a_size), pgtok(ap->a_rss));
E 54
E 23
E 2
D 30
	printf(lp->l_wchan ? " %5x" : "      ", (int)lp->l_wchan&0xfffff);
E 30
I 30
D 39
	printf(lp->l_wchan ? " %6x" : "       ", (int)lp->l_wchan&0xffffff);
E 39
I 39
	if (lp->l_wchan == 0)
		printf(" %*s", wcwidth, "");
	else if (nflg)
D 50
		printf(" %*x", wcwidth, (int)lp->l_wchan&0xffffff);
E 50
I 50
		printf(" %*x", wcwidth, (int)lp->l_wchan&~KERNBASE);
E 50
	else
		printf(" %*.*s", wcwidth, abs(wcwidth), getchan(lp->l_wchan));
E 39
E 30
I 2
D 4
	printf(" %2.2s ", state(ap));
E 4
I 4
D 50
	printf(" %4.4s ", state(ap));
E 50
I 50
D 55
	printf(" %-3.3s ", state(ap));
E 55
I 55
	printf(" %-2.3s ", state(ap));
E 55
E 50
E 4
E 2
	ptty(ap->a_tty);
	ptime(ap);
}

ptty(tp)
	char *tp;
{

D 2
	printf(" %-2.2s", tp);
E 2
I 2
	printf("%-2.2s", tp);
E 2
}

ptime(ap)
	struct asav *ap;
{

D 2
	printf("%3ld:%02ld", ap->a_time / HZ, ap->a_time % HZ);
E 2
I 2
D 8
	printf("%3ld:%02ld", ap->a_cpu / HZ, ap->a_cpu % HZ);
E 8
I 8
D 21
	printf("%3ld:%02ld", ap->a_cpu / hz, ap->a_cpu % hz);
E 21
I 21
D 50
	printf("%3ld:%02ld", ap->a_cpu / 60, ap->a_cpu % 60);
E 50
I 50
D 55
	printf(" %2ld:%02ld", ap->a_cpu / 60, ap->a_cpu % 60);
E 55
I 55
	printf(" %3ld:%02ld", ap->a_cpu / 60, ap->a_cpu % 60);
E 55
E 50
E 21
E 8
E 2
}

char	*uhdr =
D 2
"USER       PID %CPU NICE  SZ  RSS TTY TIME";
E 2
I 2
D 3
"USER       PID %CPU NICE  SZ  RSS TT F   TIME";
E 3
I 3
D 4
"USER       PID %CPU NI   SZ  RSS TT ST  TIME";
E 4
I 4
D 39
"USER       PID %CPU %MEM   SZ  RSS TT STAT  TIME";
E 39
I 39
D 50
"%s   PID %%CPU %%MEM   SZ  RSS TT STAT  TIME";
E 50
I 50
"%s   PID %%CPU %%MEM    SZ   RSS TT STAT TIME";
E 50
E 39
E 4
E 3
E 2
upr(sp)
	struct savcom *sp;
{
	register struct asav *ap = sp->ap;
I 4
	int vmsize, rmsize;
E 4

D 3
	printf("%-8.8s %5u%5.1f%5d%4d%5d",
E 3
I 3
D 4
	printf("%-8.8s %5u%5.1f%3d%5d%5d",
E 3
	    getname(ap->a_uid), ap->a_pid, sp->sun.u_pctcpu, ap->a_nice-NZERO,
D 2
	    ap->a_size, ap->a_rss);
E 2
I 2
	    ap->a_size/2, ap->a_rss/2);
E 4
I 4
D 23
	vmsize = (ap->a_size + ap->a_tsiz)/2;
	rmsize = ap->a_rss/2;
E 23
I 23
	vmsize = pgtok((ap->a_size + ap->a_tsiz));
	rmsize = pgtok(ap->a_rss);
E 23
	if (ap->a_xccount)
D 23
		rmsize += ap->a_txtrss/ap->a_xccount/2;
E 23
I 23
		rmsize += pgtok(ap->a_txtrss/ap->a_xccount);
E 23
D 39
	printf("%-8.8s %5d%5.1f%5.1f%5d%5d",
D 23
	    getname(ap->a_uid), ap->a_pid, sp->sun.u_pctcpu, pmem(ap),
E 23
I 23
	    getname(ap->a_uid), ap->a_pid, sp->s_un.u_pctcpu, pmem(ap),
E 23
	    vmsize, rmsize);
E 39
I 39
	if (nflg)
		printf("%4d ", ap->a_uid);
	else
		printf("%-8.8s ", getname(ap->a_uid));
D 50
	printf("%5d%5.1f%5.1f%5d%5d",
E 50
I 50
	printf("%5d %4.1f %4.1f %5d %5d",
E 50
	    ap->a_pid, sp->s_un.u_pctcpu, pmem(ap), vmsize, rmsize);
E 39
E 4
	putchar(' ');
E 2
	ptty(ap->a_tty);
I 2
D 4
	printf(" %2.2s", state(ap));
E 4
I 4
D 50
	printf(" %4.4s", state(ap));
E 50
I 50
D 55
	printf(" %-3.3s", state(ap));
E 55
I 55
	printf(" %-2.3s", state(ap));
E 55
E 50
E 4
E 2
	ptime(ap);
}

char *vhdr =
D 2
"F     PID TTY  TIME RES SL  MINFLT  MAJFLT SIZE  RSS  SRS TSIZ TRS PF";
E 2
I 2
D 3
"   PID TT S     TIME RES SL MINFLT MAJFLT SIZE  RSS  SRS TSIZ TRS PF";
E 3
I 3
D 4
"   PID TT ST    TIME RES SL MINFLT MAJFLT SIZE  RSS  SRS TSIZ TRS %CP";
E 4
I 4
D 9
"  PID TT STAT  TIME SL RE PAGEIN SIZE  RSS  SRS TSIZ TRS %CPU %MEM";
E 9
I 9
D 23
"  PID TT STAT  TIME SL RE PAGEIN SIZE  RSS  LIM TSIZ TRS %CPU %MEM";
E 23
I 23
D 46
" SIZE  PID TT STAT  TIME SL RE PAGEIN SIZE  RSS  LIM TSIZ TRS %CPU %MEM"+5;
E 46
I 46
D 50
" SIZE  PID TT STAT  TIME SL RE PAGEIN SIZE  RSS   LIM TSIZ TRS %CPU %MEM"+5;
E 50
I 50
" SIZE  PID TT STAT TIME SL RE PAGEIN  SIZE   RSS   LIM TSIZ TRS %CPU %MEM"+5;
E 50
E 46
E 23
E 9
E 4
E 3
E 2
vpr(sp)
	struct savcom *sp;
{
D 23
	register struct vsav *vp = sp->sun.vp;
E 23
I 23
	register struct vsav *vp = sp->s_un.vp;
E 23
	register struct asav *ap = sp->ap;
D 2
	char stat, nice, anom;
E 2

I 2
D 4
	printf("%6u ", ap->a_pid);
E 4
I 4
	printf("%5u ", ap->a_pid);
E 4
	ptty(ap->a_tty);
D 4
	printf(" %4s", state(ap));
E 4
I 4
D 50
	printf(" %4.4s", state(ap));
E 50
I 50
D 55
	printf(" %-3.3s", state(ap));
E 55
I 55
	printf(" %-2.3s", state(ap));
E 55
E 50
E 4
	ptime(ap);
D 3
	printf("%4d%3d%7d%7d%5d%5d%5d%5d%4d%3d",
E 3
I 3
D 4
	printf("%4d%3d%7d%7d%5d%5d%5d%5d%4d%4d",
E 3
	   ap->a_time, ap->a_slptime, vp->v_minflt, vp->v_majflt,
E 4
I 4
D 9
	printf("%3d%3d%7d%5d%5d%5d%5d%4d%5.1f%5.1f",
	   ap->a_slptime, ap->a_time > 99 ? 99 : ap->a_time, vp->v_majflt,
E 4
	   ap->a_size/2, ap->a_rss/2, vp->v_swrss/2,
E 9
I 9
D 50
	printf("%3d%3d%7d%5d%5d",
E 50
I 50
	printf(" %2d %2d %6d %5d %5d",
E 50
	   ap->a_slptime > 99 ? 99 : ap-> a_slptime,
	   ap->a_time > 99 ? 99 : ap->a_time, vp->v_majflt,
D 23
	   ap->a_size/2, ap->a_rss/2);
	if (ap->a_maxrss == (INFINITY/NBPG))
E 23
I 23
	   pgtok(ap->a_size), pgtok(ap->a_rss));
	if (ap->a_maxrss == (RLIM_INFINITY/NBPG))
E 23
D 10
		printf("   oo");
E 10
I 10
D 46
		printf("   xx");
E 46
I 46
		printf("    xx");
E 46
E 10
	else
D 23
		printf("%5d", ap->a_maxrss/2);
E 23
I 23
D 46
		printf("%5d", pgtok(ap->a_maxrss));
E 46
I 46
D 50
		printf("%6d", pgtok(ap->a_maxrss));
E 46
E 23
	printf("%5d%4d%5.1f%5.1f",
E 50
I 50
		printf(" %5d", pgtok(ap->a_maxrss));
	printf(" %4d %3d %4.1f %4.1f",
E 50
E 9
D 3
	   vp->v_tsiz/2, vp->v_txtrss/2, vp->v_aveflt);
E 3
I 3
D 4
	   vp->v_tsiz/2, vp->v_txtrss/2, vp->v_pctcpu);
E 4
I 4
D 23
	   ap->a_tsiz/2, ap->a_txtrss/2, vp->v_pctcpu, pmem(ap));
E 23
I 23
	   pgtok(ap->a_tsiz), pgtok(ap->a_txtrss), vp->v_pctcpu, pmem(ap));
E 23
E 4
E 3
}

char	*shdr =
D 3
"SSIZ   PID TT S   TIME";
E 3
I 3
D 4
"SSIZ   PID TT ST  TIME";
E 4
I 4
"SSIZ   PID TT STAT  TIME";
E 4
E 3
spr(sp)
	struct savcom *sp;
{
	register struct asav *ap = sp->ap;

	if (sflg)
D 23
		printf("%4d ", sp->sun.s_ssiz);
E 23
I 23
		printf("%4d ", sp->s_un.s_ssiz);
E 23
	printf("%5u", ap->a_pid);
	putchar(' ');
	ptty(ap->a_tty);
D 4
	printf(" %2.2s", state(ap));
E 4
I 4
D 50
	printf(" %4.4s", state(ap));
E 50
I 50
D 55
	printf(" %-3.3s", state(ap));
E 55
I 55
	printf(" %-2.3s", state(ap));
E 55
E 50
E 4
	ptime(ap);
}

char *
state(ap)
	register struct asav *ap;
{
D 50
	char stat, load, nice, anom;
E 50
	static char res[5];
I 50
	char *cp = res;
E 50

E 2
	switch (ap->a_stat) {

D 2
	case SSLEEP:
E 2
	case SSTOP:
D 2
		if ((ap->a_flag & SLOAD) == 0)
			stat = 'W';
		else if (vp->v_pri >= PZERO)
			stat = 'S';
E 2
I 2
D 50
		stat = 'T';
E 50
I 50
		*cp = 'T';
E 50
		break;

	case SSLEEP:
		if (ap->a_pri >= PZERO)
			if (ap->a_slptime >= MAXSLP)
D 50
				stat = 'I';
E 50
I 50
				*cp = 'I';
E 50
			else
D 50
				stat = 'S';
E 50
I 50
				*cp = 'S';
E 50
E 2
		else if (ap->a_flag & SPAGE)
D 50
			stat = 'P';
E 50
I 50
			*cp = 'P';
E 50
		else
D 50
			stat = 'D';
E 50
I 50
			*cp = 'D';
E 50
		break;

I 2
	case SWAIT:
E 2
	case SRUN:
	case SIDL:
D 2
		stat = ap->a_flag & SLOAD ? 'R' : 'W';
E 2
I 2
D 50
		stat = 'R';
E 50
I 50
		*cp = 'R';
E 50
E 2
		break;
I 2

	case SZOMB:
D 50
		stat = 'Z';
E 50
I 50
		*cp = 'Z';
E 50
		break;

	default:
D 50
		stat = '?';
E 50
I 50
		*cp = '?';
E 50
E 2
	}
I 2
D 9
	load = ap->a_flag & SLOAD ? ' ' : 'W';
E 9
I 9
D 50
	load = ap->a_flag & SLOAD ? (ap->a_rss>ap->a_maxrss ? '>' : ' ') : 'W';
E 50
I 50
	cp++;
	if (ap->a_flag & SLOAD) {
		if (ap->a_rss > ap->a_maxrss)
			*cp++ = '>';
	} else
		*cp++ = 'W';
E 50
E 9
E 2
D 4
	nice = ap->a_nice > NZERO ? 'N' : ' ';
E 4
I 4
	if (ap->a_nice < NZERO)
D 50
		nice = '<';
E 50
I 50
		*cp++ = '<';
E 50
	else if (ap->a_nice > NZERO)
D 50
		nice = 'N';
	else
		nice = ' ';
E 4
D 10
	anom = ap->a_flag & (SANOM|SUANOM) ? 'A' : ' ';
E 10
I 10
	anom = (ap->a_flag&SUANOM) ? 'A' : ((ap->a_flag&SSEQL) ? 'S' : ' ');
E 10
D 2
	printf("%c%c%c%6u ", stat, nice, anom, ap->a_pid);
	ptty(ap->a_tty);
	ptime(ap);
	printf("%4d%3d%8d%8d%5d%5d%5d%5d%4d%3d",
	   ap->a_time, vp->v_slptime, vp->v_minflt, vp->v_majflt,
	   ap->a_size, ap->a_rss / 2, vp->v_swrss / 2,
	   vp->v_tsiz / 2, vp->v_txtrss / 2, vp->v_aveflt);
}

char	*shdr =
" SSIZ   PID TTY TIME";
spr(sp)
	struct savcom *sp;
{
	register struct asav *ap = sp->ap;

	if (sflg)
		printf("%5d", sp->sun.s_ssiz);
	printf(" %5u", ap->a_pid);
	ptty(ap->a_tty);
	ptime(ap);
E 2
I 2
	res[0] = stat; res[1] = load; res[2] = nice; res[3] = anom;
E 50
I 50
		*cp++ = 'N';
	if (ap->a_flag & SUANOM)
		*cp++ = 'A';
	else if (ap->a_flag & SSEQL)
		*cp++ = 'S';
I 52
	*cp = '\0';
E 52
E 50
	return (res);
E 2
}

/*
 * Given a base/size pair in virtual swap area,
 * return a physical base/size pair which is the
 * (largest) initial, physically contiguous block.
 */
vstodb(vsbase, vssize, dmp, dbp, rev)
	register int vsbase;
	int vssize;
	struct dmap *dmp;
	register struct dblock *dbp;
{
D 26
	register int blk = DMMIN;
E 26
I 26
	register int blk = dmmin;
E 26
	register swblk_t *ip = dmp->dm_map;

I 23
	vsbase = ctod(vsbase);
	vssize = ctod(vssize);
E 23
	if (vsbase < 0 || vsbase + vssize > dmp->dm_size)
		panic("vstodb");
	while (vsbase >= blk) {
		vsbase -= blk;
D 26
		if (blk < DMMAX)
E 26
I 26
		if (blk < dmmax)
E 26
			blk *= 2;
		ip++;
	}
	if (*ip <= 0 || *ip + blk > nswap)
		panic("vstodb *ip");
	dbp->db_size = min(vssize, blk - vsbase);
	dbp->db_base = *ip + (rev ? blk - (vsbase + dbp->db_size) : vsbase);
}

/*ARGSUSED*/
panic(cp)
	char *cp;
{

#ifdef DEBUG
	printf("%s\n", cp);
#endif
}

min(a, b)
{

	return (a < b ? a : b);
}

pscomp(s1, s2)
	struct savcom *s1, *s2;
{
	register int i;

I 3
D 16
	if (uflg)
E 16
I 16
D 23
	if (uflg && !ssflg)
E 16
		return (s2->sun.u_pctcpu > s1->sun.u_pctcpu ? 1 : -1);
E 23
I 23
	if (uflg)
		return (s2->s_un.u_pctcpu > s1->s_un.u_pctcpu ? 1 : -1);
E 23
E 3
	if (vflg)
		return (vsize(s2) - vsize(s1));
	i = s1->ap->a_ttyd - s2->ap->a_ttyd;
	if (i == 0)
		i = s1->ap->a_pid - s2->ap->a_pid;
	return (i);
}

vsize(sp)
	struct savcom *sp;
{
	register struct asav *ap = sp->ap;
D 23
	register struct vsav *vp = sp->sun.vp;
E 23
I 23
	register struct vsav *vp = sp->s_un.vp;
E 23
	
	if (ap->a_flag & SLOAD)
		return (ap->a_rss +
D 4
		    vp->v_txtrss / (vp->v_xccount ? vp->v_xccount : 1));
	return (vp->v_swrss + (vp->v_xccount ? 0 : vp->v_txtswrss));
E 4
I 4
		    ap->a_txtrss / (ap->a_xccount ? ap->a_xccount : 1));
	return (vp->v_swrss + (ap->a_xccount ? 0 : vp->v_txtswrss));
E 4
}

D 25
#define	NMAX	8
#define	NUID	2048
E 25
I 25
D 41
#define	NMAX	8	/* sizeof loginname (should be sizeof (utmp.ut_name)) */
#define NUID	2048	/* must not be a multiple of 5 */
E 41
I 41
#include <utmp.h>
E 41
E 25

D 25
char	names[NUID][NMAX+1];
E 25
I 25
D 41
struct nametable {
	char	nt_name[NMAX+1];
	int	nt_uid;
} nametable[NUID];
E 41
I 41
struct	utmp utmp;
#define	NMAX	(sizeof (utmp.ut_name))
#define SCPYN(a, b)	strncpy(a, b, NMAX)
E 41
E 25

D 25
/*
 * Stolen from ls...
 */
E 25
I 25
D 41
struct nametable *
findslot(uid)
D 29
unsigned short	uid;
E 29
I 29
int	uid;
E 29
{
	register struct nametable	*n, *start;
E 41
I 41
#define NUID	64
E 41

D 41
	/*
	 * find the uid or an empty slot.
	 * return NULL if neither found.
	 */
E 41
I 41
struct ncache {
	int	uid;
	char	name[NMAX+1];
} nc[NUID];
E 41

D 41
	n = start = nametable + (uid % (NUID - 20));
	while (n->nt_name[0] && n->nt_uid != uid) {
		if ((n += 5) >= &nametable[NUID])
			n -= NUID;
		if (n == start)
			return((struct nametable *)NULL);
	}
	return(n);
}

E 41
I 41
/*
 * This function assumes that the password file is hashed
 * (or some such) to allow fast access based on a uid key.
 */
E 41
E 25
char *
getname(uid)
{
D 25
	register struct passwd *pw;
	static init;
	struct passwd *getpwent();
E 25
I 25
D 41
	register struct passwd		*pw;
	static				init = 0;
	struct passwd			*getpwent();
	register struct nametable	*n;
I 34
	extern int			_pw_stayopen;
E 41
I 41
	register struct passwd *pw;
	struct passwd *getpwent();
	register int cp;
	extern int _pw_stayopen;
E 41
E 34
E 25

D 4
	if (names[uid][0])
E 4
I 4
D 25
	if (uid >= 0 && uid < NUID && names[uid][0])
E 4
		return (&names[uid][0]);
	if (init == 2)
		return (0);
	if (init == 0)
		setpwent(), init = 1;
	while (pw = getpwent()) {
		if (pw->pw_uid >= NUID)
			continue;
		if (names[pw->pw_uid][0])
			continue;
D 19
		strncpy(names[pw->pw_uid], pw->pw_name, NMAX);
E 19
I 19
		(void) strncpy(names[pw->pw_uid], pw->pw_name, NMAX);
E 19
		if (pw->pw_uid == uid)
			return (&names[uid][0]);
E 25
I 25
D 41
	/*
	 * find uid in hashed table; add it if not found.
	 * return pointer to name.
	 */
E 41
I 41
	_pw_stayopen = 1;
E 41

D 41
	if ((n = findslot(uid)) == NULL)
		return((char *)NULL);

	if (n->nt_name[0])	/* occupied? */
		return(n->nt_name);

	switch (init) {
		case 0:
			setpwent();
I 34
			_pw_stayopen = 1;
E 34
			init = 1;
			/* intentional fall-thru */
		case 1:
			while (pw = getpwent()) {
				if (pw->pw_uid < 0)
					continue;
				if ((n = findslot(pw->pw_uid)) == NULL) {
					endpwent();
					init = 2;
					return((char *)NULL);
				}
				if (n->nt_name[0])
					continue;	/* duplicate, not uid */
				strncpy(n->nt_name, pw->pw_name, NMAX);
				n->nt_uid = pw->pw_uid;
				if (pw->pw_uid == uid)
					return (n->nt_name);
			}
			endpwent();
			init = 2;
			/* intentional fall-thru */
		case 2:
			return ((char *)NULL);
E 25
	}
I 29
	/* NOTREACHED */
E 41
I 41
#if	(((NUID) & ((NUID) - 1)) != 0)
	cp = uid % (NUID);
#else
	cp = uid & ((NUID) - 1);
#endif
	if (uid >= 0 && nc[cp].uid == uid && nc[cp].name[0])
		return (nc[cp].name);
	pw = getpwuid(uid);
	if (!pw)
		return (0);
	nc[cp].uid = uid;
	SCPYN(nc[cp].name, pw->pw_name);
	return (nc[cp].name);
E 41
E 29
D 25
	init = 2;
	endpwent();
	return (0);
E 25
}

D 29
char	*freebase;
int	nleft;

E 29
char *
D 29
alloc(size)
	int size;
{
	register char *cp;
	register int i;

I 23
#ifdef sun
	size = (size+1)&~1;
#endif
E 23
	if (size > nleft) {
D 19
		freebase = (char *)sbrk(i = size > 2048 ? size : 2048);
E 19
I 19
		freebase = (char *)sbrk((int)(i = size > 2048 ? size : 2048));
E 19
D 28
		if (freebase == 0) {
E 28
I 28
		if (freebase == (char *)-1) {
E 28
			fprintf(stderr, "ps: ran out of memory\n");
			exit(1);
		}
		nleft = i - size;
	} else
		nleft -= size;
	cp = freebase;
	for (i = size; --i >= 0; )
		*cp++ = 0;
	freebase = cp;
	return (cp - size);
}

char *
E 29
savestr(cp)
	char *cp;
{
D 29
	register int len;
E 29
I 29
	register unsigned len;
E 29
	register char *dp;

	len = strlen(cp);
D 29
	dp = (char *)alloc(len+1);
E 29
I 29
	dp = (char *)calloc(len+1, sizeof (char));
E 29
D 19
	strcpy(dp, cp);
E 19
I 19
	(void) strcpy(dp, cp);
E 19
	return (dp);
I 29
}

/*
 * This routine was stolen from adb to simulate memory management
 * on the VAX.
 */
off_t
vtophys(loc)
long	loc;
{
	register	p;
	off_t	newloc;

D 48
	newloc = loc & ~0xc0000000;
E 48
I 48
	newloc = loc & ~KERNBASE;
E 48
	p = btop(newloc);
D 48
	if ((loc & 0xc0000000) == 0) {
E 48
I 48
	if ((loc & KERNBASE) == 0) {
E 48
		fprintf(stderr, "Vtophys: translating non-kernel address\n");
		return((off_t) -1);
	}
	if (p >= Syssize) {
		fprintf(stderr, "Vtophys: page out of bound (%d>=%d)\n",
			p, Syssize);
		return((off_t) -1);
	}
	if (Sysmap[p].pg_v == 0
	&& (Sysmap[p].pg_fod || Sysmap[p].pg_pfnum == 0)) {
		fprintf(stderr, "Vtophys: page not valid\n");
		return((off_t) -1);
	}
	loc = (long) (ptob(Sysmap[p].pg_pfnum) + (loc & PGOFSET));
	return(loc);
I 39
}

/*
 * since we can't init unions, the cleanest way to use a.out.h instead
 * of nlist.h (required since nlist() uses some defines) is to do a
 * runtime copy into the nl array -- sigh
 */
init_nlist()
{
	register struct nlist *np;
	register char **namep;

	nllen = sizeof nl_names / sizeof (char *);
	np = nl = (struct nlist *) malloc(nllen * sizeof (struct nlist));
	if (np == NULL) {
		fprintf(stderr, "ps: out of memory allocating namelist\n");
		exit(1);
	}
	namep = &nl_names[0];
	while (nllen > 0) {
		np->n_un.n_name = *namep;
		if (**namep == '\0')
			break;
		namep++;
		np++;
	}
}

/*
 * nlist - retreive attributes from name list (string table version)
 * 	modified to add wait channels - Charles R. LaBrec 8/85
 */
nlist(name, list)
	char *name;
	struct nlist *list;
{
	register struct nlist *p, *q;
	register char *s1, *s2;
	register n, m;
	int maxlen, nreq;
	FILE *f;
	FILE *sf;
	off_t sa;		/* symbol address */
	off_t ss;		/* start of strings */
	int type;
	struct exec buf;
	struct nlist space[BUFSIZ/sizeof (struct nlist)];
	char nambuf[BUFSIZ];

	maxlen = 0;
	for (q = list, nreq = 0; q->n_un.n_name && q->n_un.n_name[0]; q++, nreq++) {
		q->n_type = 0;
		q->n_value = 0;
		q->n_desc = 0;
		q->n_other = 0;
		n = strlen(q->n_un.n_name);
		if (n > maxlen)
			maxlen = n;
	}
	f = fopen(name, "r");
	if (f == NULL)
		return (-1);
	fread((char *)&buf, sizeof buf, 1, f);
	if (N_BADMAG(buf)) {
		fclose(f);
		return (-1);
	}
	sf = fopen(name, "r");
	if (sf == NULL) {
		/* ??? */
		fclose(f);
		return(-1);
	}
	sa = N_SYMOFF(buf);
	ss = sa + buf.a_syms;
	n = buf.a_syms;
	fseek(f, sa, 0);
	while (n) {
		m = sizeof (space);
		if (n < m)
			m = n;
		if (fread((char *)space, m, 1, f) != 1)
			break;
		n -= m;
		for (q = space; (m -= sizeof(struct nlist)) >= 0; q++) {
			if (q->n_un.n_strx == 0 || q->n_type & N_STAB)
				continue;
			/*
			 * since we know what type of symbols we will get,
			 * we can make a quick check here -- crl
			 */
			type = q->n_type & (N_TYPE | N_EXT);
			if ((q->n_type & N_TYPE) != N_ABS
			    && type != (N_EXT | N_DATA)
			    && type != (N_EXT | N_BSS))
				continue;
			fseek(sf, ss+q->n_un.n_strx, 0);
			fread(nambuf, maxlen+1, 1, sf);
			/* if using wchans, add it to the list of channels */
			if (!nflg)
				addchan(&nambuf[1], (caddr_t) q->n_value);
			for (p = list; p->n_un.n_name && p->n_un.n_name[0]; p++) {
				s1 = p->n_un.n_name;
				s2 = nambuf;
				if (strcmp(p->n_un.n_name, nambuf) == 0) {
					p->n_value = q->n_value;
					p->n_type = q->n_type;
					p->n_desc = q->n_desc;
					p->n_other = q->n_other;
					--nreq;
					break;
				}
			}
		}
	}
alldone:
	fclose(f);
	fclose(sf);
	return (nreq);
}

/*
 * add the given channel to the channel list
 */
addchan(name, caddr)
char *name;
caddr_t caddr;
{
	static int left = 0;
	register struct wchan *wp;
	register char **p;

	for (p = wchan_stop_list; *p; p++) {
		if (**p != *name)	/* quick check first */
			continue;
		if (strncmp(name, *p, WNAMESIZ) == 0)
			return;		/* if found, don't add */
	}
	if (left == 0) {
		if (wchanhd) {
			left = 100;
			wchanhd = (struct wchan *) realloc(wchanhd,
				(nchans + left) * sizeof (struct wchan));
		} else {
			left = 600;
			wchanhd = (struct wchan *) malloc(left
				* sizeof (struct wchan));
		}
		if (wchanhd == NULL) {
			fprintf(stderr, "ps: out of memory allocating wait channels\n");
			nflg++;
			return;
		}
	}
	left--;
	wp = &wchanhd[nchans++];
	strncpy(wp->wc_name, name, WNAMESIZ);
	wp->wc_name[WNAMESIZ] = '\0';
	wp->wc_caddr = caddr;
}

/*
 * returns the symbolic wait channel corresponding to chan
 */
char *
getchan(chan)
register caddr_t chan;
{
	register i, iend;
	register char *prevsym;
	register struct wchan *wp;

	prevsym = "???";		/* nothing, to begin with */
	if (chan) {
		for (i = 0; i < NWCINDEX; i++)
			if ((unsigned) chan < (unsigned) wchan_index[i])
				break;
		iend = i--;
		if (i < 0)		/* can't be found */
			return prevsym;
		iend *= nchans;
		iend /= NWCINDEX;
		i *= nchans;
		i /= NWCINDEX;
		wp = &wchanhd[i];
		for ( ; i < iend; i++, wp++) {
			if ((unsigned) wp->wc_caddr > (unsigned) chan)
				break;
			prevsym = wp->wc_name;
		}
	}
	return prevsym;
}

/*
 * used in sorting the wait channel array
 */
int
wchancomp (w1, w2)
struct wchan *w1, *w2;
{
	register unsigned c1, c2;

	c1 = (unsigned) w1->wc_caddr;
	c2 = (unsigned) w2->wc_caddr;
	if (c1 > c2)
		return 1;
	else if (c1 == c2)
		return 0;
	else
		return -1;
E 39
E 29
I 16
D 23
}

walk(np)
	int np;
{
	register int i, j, k, l, m;
#undef afl
#undef sfl
#define afl(i,f) savcom[i].ap -> f
#define sfl(i,f) savcom[i].sun.ssp -> f

	for(i = 0; i < np; i = j) {
		for(j = i; afl(j,a_ttyd) == afl(i,a_ttyd); j++) {
			sfl(j,ss_brother) = -1;
			sfl(j,ss_sons) = -1;
		}
		for(k = i+1; k < j; k++) {
			if(sfl(k,ss_ppid) == sfl(i,ss_ppid)) {
				for(l=i; sfl(l,ss_brother) != -1; 
					l=sfl(l,ss_brother)) ;
				sfl(l,ss_brother) = k;
				goto next;
			}
			for(l = i; l < j; l++) {
				if(l == k) continue;
				if(sfl(k,ss_ppid) == afl(l,a_pid)) {
					if(sfl(l,ss_sons) == -1)
					    sfl(l,ss_sons) = k;
					else {
					    for(m = sfl(l,ss_sons);
						sfl(m,ss_brother) != -1;
						m = sfl(m,ss_brother)) ;
					    sfl(m,ss_brother) = k;
					}
					goto next;
				}
			}
			for(l = i; l < j; l++) {
				if(l == k) continue;
				if(sfl(k,ss_ppid) == sfl(l,ss_ppid)) {
					for(m = k; sfl(m,ss_brother) != -1;
					    m = sfl(m,ss_brother)) ;
					sfl(m,ss_brother) = l;
				}
			}
		next: ;
		}
		walk1(i, 0);
	}
}

walk1(pno, depth)
	int pno, depth;
{
	if(pno == -1)
		return;
/***    printf("%5d, %d\n",outargs[pno].o_pid, depth);  ***/
	walkpr(&savcom[pno], depth);
	walk1(sfl(pno,ss_sons), depth+1);
	walk1(sfl(pno,ss_brother), depth);
}

char *sshdr =
"TTY User     SZ RSS  CPU  S      PID  ";

walkpr(a, depth)
	register struct savcom *a;
	int depth;
{
D 19
	long tm;
E 19

	if(!depth) {
		printf("%-2.2s", a->ap->a_tty);
		printf(" %-8.8s", getname(a->ap->a_uid));
	} else
		printf("   %-8s", &".......*"[8-(depth<=8?depth:8)]);
	printf("%4d%4d", a->ap->a_size/2, a->ap->a_rss/2);
	ptime(a->ap);
	/* Once there was a "CCPU" field here.  Subsumed by -S now. */
	printf(" %4.4s", state(a->ap));
	printf("%6u ", a->ap->a_pid);
	if (a->ap->a_pid == 0)
		printf(" swapper");
	else if (a->ap->a_pid == 2)
		printf(" pagedaemon");
	else
		printf(" %.*s", twidth - cmdstart - 2, a->ap->a_cmdp);
	putchar('\n');
E 23
E 16
}
E 1
