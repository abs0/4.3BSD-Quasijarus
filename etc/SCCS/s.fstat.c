h26784
s 00010/00005/00616
d D 5.13 88/06/18 14:34:28 bostic 14 13
c install approved copyright notice
e
s 00018/00018/00603
d D 5.12 88/03/13 18:40:16 bostic 13 12
c put it all in "kernel normal"
e
s 00001/00001/00620
d D 5.11 88/02/22 11:57:04 bostic 12 11
c don't increment argv twice
e
s 00048/00039/00573
d D 5.10 87/12/26 12:59:51 bostic 11 10
c Berkeley header, minor cleanups
e
s 00008/00004/00604
d D 5.9 87/11/24 14:38:25 marc 10 9
c If multiple files are specified, don't bomb as long as at least
c one of them is accessable.  I.e. fstat /foo/* shouldn't crap out just 
c because one of those files can't be opened.
e
s 00017/00006/00591
d D 5.8 87/11/24 01:24:16 marc 9 8
c Print name of file if known (if matched by a -f entry).
e
s 00005/00002/00592
d D 5.7 87/11/17 13:34:37 marc 8 7
c fix -p arg handling
e
s 00254/00309/00340
d D 5.6 87/11/06 19:55:23 bostic 7 6
c more rape and pillage; no more single character reads for 
c domain names, no more multiple str{cpy,cat}'s to put single characters 
c into buffers, lots of general cleanup
e
s 00246/00333/00403
d D 5.5 87/11/05 19:09:50 bostic 6 4
c complete and total rape
e
s 00247/00333/00403
d R 5.5 87/11/05 19:06:41 bostic 5 4
c complete and total rape
e
s 00010/00004/00726
d D 5.4 87/10/22 10:34:23 bostic 4 3
c ANSI C; sprintf now returns an int.
e
s 00053/00064/00677
d D 5.3 87/10/11 00:02:03 marc 3 2
c multiple file args, point arrows in the right direction 
c for connected unixdomain sockets (pipes).
e
s 00001/00001/00740
d D 5.2 87/09/02 15:58:57 marc 2 1
c upcase title line
e
s 00741/00000/00000
d D 5.1 87/09/02 15:25:56 bostic 1 0
c date and time created 87/09/02 15:25:56 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
E 11
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
D 6
#endif not lint
E 6
I 6
D 11
#endif /* !lint */
E 11
I 11
#endif /* not lint */
E 11
E 6

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
D 11
#endif /* !lint */
E 11
I 11
#endif /* not lint */
E 11
E 6

/*
 *  fstat 
 */
D 6
#include <stdio.h>
#include <ctype.h>
#include <nlist.h>
#include <pwd.h>
E 6
I 6
D 7
#include <machine/pte.h> 
E 7
I 7
#include <machine/pte.h>
E 7

E 6
#include <sys/param.h>
D 7
#include <sys/ioctl.h>
#include <sys/tty.h>
E 7
#include <sys/dir.h>
#include <sys/user.h>
#include <sys/proc.h>
D 6
#include <machine/pte.h> 
E 6
D 7
#include <sys/vm.h>
E 7
#include <sys/text.h>
#include <sys/stat.h>
D 6
#include <math.h>
E 6
D 7
#include <sys/vlimit.h>
E 7
#include <sys/inode.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <sys/domain.h>
#include <sys/protosw.h>
D 6
#include <net/route.h>
#include <netinet/in.h>
#include <netinet/in_pcb.h>
E 6
#include <sys/unpcb.h>
D 7
#define KERNEL
E 7
I 7
#include <sys/vmmac.h>
#define	KERNEL
E 7
#include <sys/file.h>
D 7
#undef KERNEL
E 7
I 7
#undef	KERNEL
E 7
I 6
#include <net/route.h>
#include <netinet/in.h>
#include <netinet/in_pcb.h>
#include <stdio.h>
I 8
#include <ctype.h>
E 8
D 7
#include <math.h>
E 7
#include <nlist.h>
#include <pwd.h>
E 6

D 6
#ifdef ULTRIX	
   		/* UFS -> GFS */
E 6
I 6
#ifdef	ULTRIX
		/* UFS -> GFS */
E 6
#    define	inode	gnode
#    define	x_iptr	x_gptr
#    define	i_dev	g_dev
#    define	i_number g_number
#    define	i_mode	g_mode
#    define	i_size	g_size
D 6
#endif ULTRIX
E 6
I 6
D 7
#endif	/* ULTRIX */
E 7
I 7
#endif
E 7
E 6

I 7
#define	N_KMEM	"/dev/kmem"
#define	N_MEM	"/dev/mem"
#define	N_SWAP	"/dev/drum"
#define	N_UNIX	"/vmunix"

E 7
D 6
char *emalloc();
char *getinetproto();
E 6
I 6
#define	TEXT	-2
#define	WD	-1
I 7

E 7
D 11
#define	vprintf	if (vflg) printf
E 6

E 11
D 6
#define vprintf	if (vflg) printf
#define WD	-1
#define TEXT	-2

int	pcbpf, nswap, kmem, mem, swap, uid, pid;
D 3
int	uflg, fflg, inum, Mdev, mdev, special, vflg, nproc, pflg;
E 3
I 3
int	uflg, fflg, vflg, nproc, pflg;
E 3
int sflg, kflg; /*4.2*/
int argaddr; /*4.2*/

E 6
I 3
D 7
struct devs {
E 7
I 7
typedef struct devs {
E 7
D 6
	struct devs *next;
	dev_t dev;
	int inum;
E 6
I 6
D 13
	struct devs	*next;
	dev_t	dev;
	int	inum;
I 9
	char	*name;
E 13
I 13
	struct devs *next;
	dev_t dev;
	int inum;
	char *name;
E 13
E 9
E 6
D 7
} devs;
E 7
I 7
} DEVS;
D 13
DEVS	*devs;
E 13
I 13
DEVS *devs;
E 13
E 7

E 3
D 6
#define clear(x) 	((int)x & 0x7fffffff)

struct pte *Sysmap = 0;

E 6
D 7
struct nlist nl[] = {
E 7
I 7
static struct nlist nl[] = {
E 7
	{ "_proc" },
#define	X_PROC		0
	{ "_Usrptmap" },
#define	X_USRPTMA	1
D 7
	{ "_usrpt" },
#define	X_USRPT		2
	{ "_nswap" },
#define	X_NSWAP		3
E 7
	{ "_nproc" },
D 7
#define	X_NPROC		4
E 7
I 7
#define	X_NPROC		2
	{ "_usrpt" },
#define	X_USRPT		3
E 7
D 6
	{ "_Sysmap" },
#define SSYSMAP		5
	{ "_Syssize" },
#define SSYSSIZE	6
E 6
	{ "" },
};

D 6
char 	*stypename[] = {
	"unused",	/* 0 */
	"stream", 	/* 1 */
	"dgram",	/* 2 */
	"raw",		/* 3 */
	"rdm",		/* 4 */
	"seqpak"	/* 5 */
};
#define STYPEMAX 5

char	*uname;


E 6
D 7
struct	proc proc[8], *mproc;		/* 8 = a few, for less syscalls */
struct	pte *Usrptma, *usrpt;
E 7
I 7
D 13
struct proc	*mproc;
struct pte	*Usrptma, *usrpt;
E 13
I 13
struct proc *mproc;
struct pte *Usrptma, *usrpt;
E 13

E 7
D 6

int	paduser1;		/* avoid hardware mem clobbering botch */
E 6
union {
D 13
	struct	user user;
	char	upages[UPAGES][NBPG];
E 13
I 13
	struct user user;
	char upages[UPAGES][NBPG];
E 13
} user;
D 6
int	paduser2;		/* avoid hardware mem clobbering botch */
#define u	user.user
E 6

D 6
char	*kmemf, *memf, *swapf, *nlistf;
E 6
I 6
D 7
static int	nproc, nswap, kmem, mem, swap, uid, pid;
static int	uflg, fflg, vflg, pflg;
static char	*kmemf = "kmem",
		*memf = "mem",
		*swapf = "drum",
		*nlistf = "/vmunix",
		*uname;
E 6

E 7
D 13
extern int	errno;
I 7
D 11
static off_t	procp;
D 10
static int	fflg, vflg;
E 10
I 10
static int	fflg, hadfflg, vflg;
E 11
I 11
static int	fflg, vflg;
E 11
E 10
static int	kmem, mem, nproc, swap;
static char	*uname;
E 13
I 13
extern int errno;
static int fflg, vflg;
static int kmem, mem, nproc, swap;
static char *uname;
E 13
E 7
D 6
char	stdoutBuf[BUFSIZ];
E 6

I 6
D 13
off_t	lseek();
E 13
I 13
off_t lseek();
E 13
D 7
long	lgetw();
char	*emalloc(), *getinetproto();
E 7

E 6
main(argc, argv)
D 6
char **argv;
E 6
I 6
D 13
	int	argc;
	char	**argv;
E 13
I 13
	int argc;
	char **argv;
E 13
E 6
{
I 6
D 7
	extern char	*optarg;
	extern int	optind;
E 6
	register int i, j;
	off_t procp;
D 6
	dev_t	dev;
E 6
I 6
	int	ch;
E 7
I 7
	extern char *optarg;
	extern int optind;
	register struct passwd *passwd;
	register int pflg, pid, uflg, uid;
	int ch, size;
	struct passwd *getpwnam(), *getpwuid();
	long lgetw();
	char *malloc();
E 7
E 6

D 6
	argv++;
D 3
	while (--argc > 0) {
E 3
I 3
	while (*argv) {
E 3
		if (strcmp(*argv, "-v") == 0) {
			vflg++;
			argv++;
			continue;
		} 
		if (strcmp(*argv, "-u") == 0) {
			if (uflg++)
E 6
I 6
D 7
	if (chdir("/dev") < 0) {
		perror("/dev");
		exit(1);
	}

E 7
I 7
	pflg = uflg = 0;
E 7
	while ((ch = getopt(argc, argv, "p:u:v")) != EOF)
		switch((char)ch) {
		case 'p':
D 7
			if (pflg++ || ((pid = atoi(optarg)) <= 0)) {
E 7
I 7
D 8
			if (pflg++) {
E 8
I 8
			if (pflg++)
E 8
E 7
E 6
				usage();
D 6
			if ((uid = getuname(*(++argv))) < 0) {
				fprintf(stderr, "%s: unknown user\n", *argv);
E 6
D 8
				exit(1);
E 8
I 8
			if (!isdigit(*optarg)) {
				fputs("fstat: -p option requires a process id.\n", stderr);
				usage();
E 8
			}
I 7
			pid = atoi(optarg);
E 7
D 3
			--argc;
E 3
D 6
			argv++;
			continue;
		} 
		if (strcmp(*argv, "-f") == 0) {
D 3
			if (fflg++)
				usage();
			if ((dev = getfname(*(++argv))) < 0) {
E 3
I 3
			fflg++;
			if (getfname(*(++argv)) < 0) {
E 3
				perror(*argv);
				exit(1);
			}
D 3
			--argc;
E 3
			argv++;
			continue;
		}

		if (strcmp(*argv, "-p") == 0) {
			if (pflg++ || ((pid = Atoi(*(++argv))) <= 0)) {
E 6
I 6
			break;
		case 'u':
			if (uflg++)
E 6
				usage();
D 6
				perror(*argv);
E 6
I 6
D 7
			if ((uid = getuname(optarg)) < 0) {
				fprintf(stderr, "%s: unknown user\n", optarg);
E 7
I 7
			if (!(passwd = getpwnam(optarg))) {
				fprintf(stderr, "%s: unknown uid\n", optarg);
E 7
E 6
				exit(1);
			}
I 7
			uid = passwd->pw_uid;
			uname = passwd->pw_name;
E 7
D 3
			--argc;
E 3
D 6
			argv++;
			continue;
E 6
I 6
			break;
D 11
		case 'v':
E 11
I 11
		case 'v':	/* undocumented: print read error messages */
E 11
			vflg++;
			break;
		case '?':
		default:
			usage();
E 6
		}
D 3

		/* admit missing -u, -f, -p */
		/* it's an expert system! */
		if ((pid = Atoi(*argv)) > 0) {
			if (pflg++)
				usage();
			continue;
E 3
I 3
D 6
		/* otherwise its a file argument */
		fflg++;
		if (getfname(*argv) < 0) {
			perror(*argv);
			exit(1);
E 3
		}
D 3
		if (fflg && uflg)
			usage();
		if (uflg) {
			/* it must be a file */
			fflg++;
			if ((dev = getfname(*argv)) < 0) {
				perror(*argv);
				exit(1);
			}
			argv++;
			continue;
		}
		if (fflg) {
			/* it must be a user */
			uflg++;
			if ((uid = getuname(*argv)) < 0) {
				fprintf(stderr,
					"%s: unknown user\n", *argv);
				exit(1);
			}
			argv++;
			continue;
		}
		/* !uflg && !fflg -- which is it? */
		if ((dev = getfname(*argv)) >= 0)
			fflg++;		/* could be a file */
		if ((uid = getuname(*argv)) >= 0)
			uflg++;		/* could be a user */
		if ((!uflg ^ !fflg) == 0)
			usage();	/* could be either/neither */
E 3
		argv++;
		continue;
	}
E 6

D 3
	if (fflg) {
		Mdev = major(dev);
		mdev = minor(dev);
	}

E 3
D 6
	if (chdir("/dev") < 0) {
		perror("/dev");
		exit(1);
E 6
I 6
D 11
	for (argv += optind; *argv; ++argv) {
D 10
		fflg = 1;
		getfname(*argv);
E 10
I 10
		hadfflg = 1;
		if (getfname(*argv))
			fflg = 1;
E 11
I 11
	if (*(argv += optind)) {
D 12
		for (argv += optind; *argv; ++argv) {
E 12
I 12
		for (; *argv; ++argv) {
E 12
			if (getfname(*argv))
				fflg = 1;
		}
		if (!fflg)	/* file(s) specified, but none accessable */
			exit(1);
E 11
E 10
E 6
	}
I 10
D 11
	if (hadfflg && !fflg)	/* file(s) specified, but none accessable */
		exit(1);
E 11
E 10

D 2
	printf("user\t cmd\t      pid    fd\tdevice\tinode\t  size\ttype\n");
E 2
I 2
D 9
	printf("USER\t CMD\t      PID    FD\tDEVICE\tINODE\t  SIZE\tTYPE\n");
E 9
I 9
D 11
	printf("USER\t CMD\t      PID    FD\tDEVICE\tINODE\t  SIZE TYPE");
	if (fflg)
		printf(" NAME\n");
	else
		printf("\n");

E 11
E 9
E 2
	openfiles();
D 7
	getkvars();
E 7
I 7

	if (nlist(N_UNIX, nl) == -1 || !nl[0].n_type) {
		fprintf(stderr, "%s: No namelist\n", N_UNIX);
		exit(1);
	}
	Usrptma = (struct pte *)nl[X_USRPTMA].n_value;
	usrpt = (struct pte *) nl[X_USRPT].n_value;
E 7
D 6
	procp = getw((off_t) nl[X_PROC].n_value);
	nproc = getw((off_t) nl[X_NPROC].n_value);
	for (i=0; i<nproc; i += 8) {
		lseek(kmem, (long) procp, 0);
		j = nproc - i;
		if (j > 8)
			j = 8;
		j *= sizeof (struct proc);
		if (read(kmem, (char *) proc, j) != j)
E 6
I 6
D 11
	procp = lgetw((off_t)nl[X_PROC].n_value);
E 11
	nproc = (int)lgetw((off_t)nl[X_NPROC].n_value);
D 7
	for (i = 0; i < nproc; i += 8) {
		(void)lseek(kmem, (off_t)procp, 0);
		j = MIN(nproc - i, 8);
		j *= sizeof(struct proc);
		if (read(kmem, (char *)proc, j) != j)
E 6
			cantread("proc table", kmemf);
		procp += j;
D 6
		for (j = j / sizeof (struct proc) - 1; j >= 0; j--) {
E 6
I 6
		for (j = j / sizeof(struct proc) - 1; j >= 0; j--) {
E 6
			mproc = &proc[j];
			if (mproc->p_stat == 0)
				continue;
			doproc();
		}
	}
	exit(0);
}
E 7

I 11
	(void)lseek(kmem, lgetw((off_t)nl[X_PROC].n_value), L_SET);
E 11
D 6
long
getw(loc)
E 6
I 6
D 7
static long
lgetw(loc)
E 6
	off_t loc;
{
	long word;

D 6
	lseek(kmem, (long) loc, 0);
	if (read(kmem, (char *) &word, sizeof (word)) != sizeof (word))
		vprintf("error reading kmem at %x\n", loc);
	return (word);
E 6
I 6
	(void)lseek(kmem, (off_t)loc, L_SET);
	if (read(kmem, (char *) &word, sizeof(word)) != sizeof(word))
		vprintf("error reading kmem at %lx\n", loc);
	return(word);
E 6
}

I 6
static
E 6
openfiles()
{
D 6

	kmemf = "kmem";
	kmem = open(kmemf, 0);
E 6
I 6
	kmem = open(kmemf, O_RDONLY, 0);
E 6
	if (kmem < 0) {
		perror(kmemf);
E 7
I 7
	size = nproc * sizeof(struct proc);
	if ((mproc = (struct proc *)malloc((u_int)size)) == NULL) {
		fprintf(stderr, "fstat: out of space.\n");
E 7
		exit(1);
	}
D 6
	memf = "mem";
	mem = open(memf, 0);
E 6
I 6
D 7
	mem = open(memf, O_RDONLY, 0);
E 6
	if (mem < 0) {
		perror(memf);
		exit(1);
	}
D 6
	swapf = "drum";
	swap = open(swapf, 0);
E 6
I 6
	swap = open(swapf, O_RDONLY, 0);
E 6
	if (swap < 0) {
		perror(swapf);
		exit(1);
	}
}
E 7
D 11

I 6
D 7
static
E 6
getkvars()
{
D 6
	nlistf = "/vmunix";
	nlist(nlistf, nl);
	if (nl[0].n_type == 0) {
E 6
I 6
	if (nlist(nlistf, nl) == -1 || !nl[0].n_type) {
E 6
		fprintf(stderr, "%s: No namelist\n", nlistf);
		exit(1);
E 7
I 7
	(void)lseek(kmem, (off_t)procp, L_SET);
E 11
	if (read(kmem, (char *)mproc, size) != size)
D 11
		cantread("proc table", N_KMEM);
E 11
I 11
		rerr1("proc table", N_KMEM);

	printf("USER\t CMD\t      PID    FD\tDEVICE\tINODE\t  SIZE TYPE%s\n",
	    fflg ? " NAME" : "");
E 11
	for (; nproc--; ++mproc) {
		if (mproc->p_stat == 0)
			continue;
		if (pflg && mproc->p_pid != pid)
			continue;
		if (uflg)  {
			if (mproc->p_uid != uid)
				continue;
		}
		else
			uname = (passwd = getpwuid(mproc->p_uid)) ?
			    passwd->pw_name : "unknown";
		if (mproc->p_stat != SZOMB && getu() == 0)
			continue;
		dotext();
		readf();
E 7
	}
D 6
	Usrptma = (struct pte *) nl[X_USRPTMA].n_value;
	usrpt = (struct pte *) nl[X_USRPT].n_value;
	lseek(kmem, (long) nl[X_NSWAP].n_value, 0);
	if (read(kmem, (char *) &nswap, sizeof (nswap)) != sizeof (nswap)) {
E 6
I 6
D 7
	Usrptma = (struct pte *)nl[X_USRPTMA].n_value;
	usrpt = (struct pte *)nl[X_USRPT].n_value;
	(void)lseek(kmem, (off_t)nl[X_NSWAP].n_value, L_SET);
	if (read(kmem, (char *)&nswap, sizeof(nswap)) != sizeof(nswap)) {
E 6
		cantread("nswap", kmemf);
		exit(1);
	}
E 7
I 7
	exit(0);
E 7
}

I 6
static
E 6
D 7
cantread(what, fromwhat)
	char *what, *fromwhat;
{
D 6

E 6
	vprintf("fstat: error reading %s from %s", what, fromwhat);
}

I 6
static
E 6
doproc()
{
	struct passwd	*getpwuid();


	if (uflg && mproc->p_uid != uid)
		return;
	if (pflg && mproc->p_pid != pid)
		return;
	if (mproc->p_stat != SZOMB && getu() == 0)
		return;
	uname = getpwuid(mproc->p_uid)->pw_name;
	dotext();
	getf();
}

I 6
static
E 7
E 6
getu()
{
	struct pte *pteaddr, apte;
	struct pte arguutl[UPAGES+CLSIZE];
	register int i;
D 7
	int ncl, size;
E 7
I 7
	int ncl;
E 7

D 6
	size = sizeof (struct user);
E 6
I 6
D 7
	size = sizeof(struct user);
E 7
E 6
	if ((mproc->p_flag & SLOAD) == 0) {
		if (swap < 0)
D 7
			return (0);
E 7
I 7
			return(0);
E 7
D 6
		(void) lseek(swap, (long)dtob(mproc->p_swaddr), 0);
E 6
I 6
		(void)lseek(swap, (off_t)dtob(mproc->p_swaddr), L_SET);
E 6
D 7
		if (read(swap, (char *)&user.user, size) != size) {
D 6
			fprintf(stderr, "ps: cant read u for pid %d from %s\n",
E 6
I 6
			fprintf(stderr, "fstat: cant read u for pid %d from %s\n",
E 6
			    mproc->p_pid, swapf);
E 7
I 7
		if (read(swap, (char *)&user.user, sizeof(struct user))
		    != sizeof(struct user)) {
			fprintf(stderr, "fstat: can't read u for pid %d from %s\n", mproc->p_pid, N_SWAP);
E 7
D 6
			return (0);
E 6
I 6
			return(0);
E 6
		}
D 6
		pcbpf = 0;
		argaddr = 0;
		return (1);
E 6
I 6
		return(1);
E 6
	}
	pteaddr = &Usrptma[btokmx(mproc->p_p0br) + mproc->p_szpt - 1];
D 6
	klseek(kmem, (long)pteaddr, 0);
E 6
I 6
	(void)lseek(kmem, (off_t)pteaddr, L_SET);
E 6
	if (read(kmem, (char *)&apte, sizeof(apte)) != sizeof(apte)) {
D 7
		printf("fstat: cant read indir pte to get u for pid %d from %s\n",
		    mproc->p_pid, swapf);
E 7
I 7
		printf("fstat: can't read indir pte to get u for pid %d from %s\n", mproc->p_pid, N_SWAP);
E 7
D 6
		return (0);
E 6
I 6
		return(0);
E 6
	}
D 6
	klseek(mem,
	    (long)ctob(apte.pg_pfnum+1) - (UPAGES+CLSIZE) * sizeof (struct pte),
		0);
E 6
I 6
	(void)lseek(mem, (off_t)ctob(apte.pg_pfnum+1) - (UPAGES+CLSIZE)
	    * sizeof(struct pte), L_SET);
E 6
	if (read(mem, (char *)arguutl, sizeof(arguutl)) != sizeof(arguutl)) {
D 7
		printf("fstat: cant read page table for u of pid %d from %s\n",
		    mproc->p_pid, kmemf);
E 7
I 7
		printf("fstat: can't read page table for u of pid %d from %s\n", mproc->p_pid, N_KMEM);
E 7
D 6
		return (0);
E 6
I 6
		return(0);
E 6
	}
D 6
	if (arguutl[0].pg_fod == 0 && arguutl[0].pg_pfnum)
		argaddr = ctob(arguutl[0].pg_pfnum);
	else
		argaddr = 0;
	pcbpf = arguutl[CLSIZE].pg_pfnum;
E 6
D 7
	ncl = (size + NBPG*CLSIZE - 1) / (NBPG*CLSIZE);
E 7
I 7
	ncl = (sizeof(struct user) + NBPG*CLSIZE - 1) / (NBPG*CLSIZE);
E 7
	while (--ncl >= 0) {
		i = ncl * CLSIZE;
D 6
		klseek(mem, (long)ctob(arguutl[CLSIZE+i].pg_pfnum), 0);
E 6
I 6
		(void)lseek(mem, (off_t)ctob(arguutl[CLSIZE+i].pg_pfnum), L_SET);
E 6
		if (read(mem, user.upages[i], CLSIZE*NBPG) != CLSIZE*NBPG) {
D 6
			printf("fstat: cant read page %d of u of pid %d from %s\n",
E 6
I 6
D 7
			printf("fstat: cant read page %u of u of pid %d from %s\n",
E 6
			    arguutl[CLSIZE+i].pg_pfnum, mproc->p_pid, memf);
E 7
I 7
			printf("fstat: can't read page %u of u of pid %d from %s\n", arguutl[CLSIZE+i].pg_pfnum, mproc->p_pid, N_MEM);
E 7
			return(0);
		}
	}
D 6
	return (1);
E 6
I 6
	return(1);
E 6
}

D 6
#define	NMAX	8
#define	NUID	2048

E 6
I 6
static
E 6
dotext()
{
D 13
	struct text	text;
E 13
I 13
	struct text text;
E 13

D 6
	lseek(kmem, (long) mproc->p_textp, 0);
E 6
I 6
	(void)lseek(kmem, (off_t)mproc->p_textp, L_SET);
E 6
	if (read(kmem, (char *) &text, sizeof(text)) != sizeof(text)) {
D 7
		cantread("text table", kmemf);
E 7
I 7
D 11
		cantread("text table", N_KMEM);
E 11
I 11
		rerr1("text table", N_KMEM);
E 11
E 7
		return;
	}
D 7
	if (text.x_flag == 0)
		return;
	itrans(DTYPE_INODE, text.x_iptr, TEXT);
E 7
I 7
	if (text.x_flag)
		itrans(DTYPE_INODE, text.x_iptr, TEXT);
E 7
}

D 6
char 	*itypename[] = {
E 6
I 6
D 7
char	*itypename[] = {
E 6
	"unk",
#define UNK 0	/* unknown */
	"chr",
#define CHR 1	
	"dir",
#define DIR 2
	"blk",
#define BLK 3
	"reg",
#define REG 4
	"lnk",
#define LNK 5
	"soc"
#define SOC 6
};

E 7
I 6
static
E 6
D 7
itype(mode)
I 6
	u_short mode;
E 6
{
	switch(mode&IFMT) {
	case IFCHR:
		return(CHR);
	case IFDIR:
		return(DIR);
	case IFBLK:
		return(BLK);
	case IFREG:
		return(REG);
	case IFLNK:
		return(LNK);
	case IFSOCK:
		return(SOC);
	default:
		return(0);
	}
}

I 6
static
E 7
E 6
itrans(ftype, g, fno)
D 6
struct inode	*g;  /* if ftype is inode */
E 6
I 6
	int ftype, fno;
D 13
	struct inode	*g;		/* if ftype is inode */
E 13
I 13
	struct inode *g;		/* if ftype is inode */
E 13
E 6
{
D 7
	struct inode	inode;
	dev_t	idev;
D 6
	int 	type;
	char 	*comm;
E 6
I 6
	int	type;
	char	*comm;
E 7
I 7
	struct inode inode;
	dev_t idev;
	char *comm, *itype();
I 9
	char *name = (char *)NULL;	/* set by devmatch() on a match */
E 9
E 7
E 6

D 6
	if (g == 0 && ! fflg) {
		goto skip;
E 6
I 6
	if (g || fflg) {
		(void)lseek(kmem, (off_t)g, L_SET);
		if (read(kmem, (char *)&inode, sizeof(inode)) != sizeof(inode)) {
D 11
			vprintf("error %d reading inode at %x from kmem\n", errno, (int)g);
E 11
I 11
			rerr2(errno, (int)g, "inode");
E 11
			return;
		}
		idev = inode.i_dev;
D 9
		if (fflg && !devmatch(idev, inode.i_number))
E 9
I 9
		if (fflg && !devmatch(idev, inode.i_number, &name))
E 9
			return;
E 6
	}
D 6
	lseek(kmem, (long) g, 0);
	if (read(kmem, (char *) &inode, sizeof(inode))
					!= sizeof(inode)) {
		vprintf("error %d reading inode at %x from kmem\n", errno, g);
		return;
	}
D 3
	if (special)
		idev = inode.i_dev;
	else
		idev = inode.i_dev;
	if (fflg && major(idev) != Mdev)
		return;	
	if (fflg && minor(idev) != mdev)
		return;	
	if (inum && inode.i_number != inum)
E 3
I 3
	idev = inode.i_dev;
	if (fflg && !devmatch(idev, inode.i_number))
E 3
		return;
skip:
E 6
	if (mproc->p_pid == 0)
		comm = "swapper";
	else if (mproc->p_pid == 2)
		comm = "pagedaemon";
	else
D 6
		comm = u.u_comm;
E 6
I 6
		comm = user.user.u_comm;
E 6
	printf("%-8.8s %-10.10s %5d  ", uname, comm, mproc->p_pid);
D 7
	if (fno == WD)
		printf("  wd");
	else if (fno == TEXT)
		printf("text");
	else
E 7
I 7

	switch(fno) {
	case WD:
		printf("  wd"); break;
	case TEXT:
		printf("text"); break;
	default:
E 7
		printf("%4d", fno);
I 7
	}
E 7

	if (g == 0) {
		printf("* (deallocated)\n");
		return;
	}

D 6
	if (ftype == DTYPE_INODE) {
		type = itype(inode.i_mode);  /* determine inode type */
		printf("\t%2d, %2d\t%5d\t%6d\t%3s\n", major(inode.i_dev), minor(inode.i_dev),
			inode.i_number, type == SOC?0:inode.i_size, itypename[type]);
	}
	else if (ftype == DTYPE_SOCKET) {
E 6
I 6
	switch(ftype) {
	case DTYPE_INODE:
D 7
		type = itype(inode.i_mode);	/* determine inode type */
E 7
D 9
		printf("\t%2d, %2d\t%5lu\t%6ld\t%3s\n", major(inode.i_dev),
E 9
I 9
		printf("\t%2d, %2d\t%5lu\t%6ld\t%3s %s\n", major(inode.i_dev),
E 9
		    minor(inode.i_dev), inode.i_number,
D 7
		    type == SOC ? 0 : inode.i_size, itypename[type]);
E 7
I 7
		    inode.i_mode == IFSOCK ? 0 : inode.i_size,
D 9
		    itype(inode.i_mode));
E 9
I 9
		    itype(inode.i_mode), name ? name : "");
E 9
E 7
		break;
	case DTYPE_SOCKET:
E 6
		socktrans((struct socket *)g);
D 6
	}
E 6
I 6
		break;
E 6
#ifdef DTYPE_PORT
D 6
	else if (ftype == DTYPE_PORT) {
E 6
I 6
	case DTYPE_PORT:
E 6
		printf("* (fifo / named pipe)\n");
D 6
	}
#endif DTYPE_PORT
	else {
E 6
I 6
		break;
#endif
	default:
E 6
		printf("* (unknown file type)\n");
	}
}
I 6

D 7
static
E 6
I 3
devmatch(idev, inum)
D 6
dev_t idev;
int inum;
E 6
I 6
	dev_t idev;
	ino_t inum;
E 7
I 7
static char *
itype(mode)
	u_short mode;
E 7
E 6
{
D 7
	struct devs *d = &devs;
D 6
	for (d = d->next; d; d = d->next) {
		if (d->dev == idev) {
			if (d->inum == 0)
				return(1);
			if (d->inum == inum)
				return(1);
		}
	}
E 6
I 6

	for (d = d->next; d; d = d->next)
		if (d->dev == idev && (!d->inum || d->inum == inum))
			return(1);
E 6
	return(0);
E 7
I 7
	switch(mode & IFMT) {
	case IFCHR:
		return("chr");
	case IFDIR:
		return("dir");
	case IFBLK:
		return("blk");
	case IFREG:
		return("reg");
	case IFLNK:
		return("lnk");
	case IFSOCK:
		return("soc");
	default:
		return("unk");
	}
	/*NOTREACHED*/
E 7
}
E 3

I 6
static
E 6
socktrans(sock)
D 6
struct socket *sock;
E 6
I 6
	struct socket *sock;
E 6
{
D 6
	struct socket 	so;
	struct protosw 	proto;
	struct domain 	dom;
	char	dname[32];	/* domain name, e.g. "inet" */
	char 	c;
	char 	*cp;
E 6
I 6
D 7
	static char	*stypename[] = {
E 7
I 7
	static char *stypename[] = {
E 7
		"unused",	/* 0 */
		"stream", 	/* 1 */
		"dgram",	/* 2 */
		"raw",		/* 3 */
		"rdm",		/* 4 */
		"seqpak"	/* 5 */
	};
#define	STYPEMAX 5
	struct socket	so;
	struct protosw	proto;
	struct domain	dom;
	struct inpcb	inpcb;
	struct unpcb	unpcb;
E 6
D 7
	int	i;
D 6
	char 	*stype;
	struct inpcb 	inpcb;
	struct unpcb 	unpcb;
E 6
I 6
	char	c, *cp, *stype, *strcpy(), *strcat();
	char	dname[32];	/* domain name, e.g. "inet" */
E 7
I 7
	int len;
	char dname[32], *strcpy();
E 7
E 6

	/* fill in socket */
D 6
	lseek(kmem, (long) sock, 0);
	if (read(kmem, (char *) &so, sizeof(struct socket)) 
	    != sizeof(struct socket)){
		vprintf("error %d reading socket at %x from kmem\n", errno, sock);
E 6
I 6
	(void)lseek(kmem, (off_t)sock, L_SET);
	if (read(kmem, (char *)&so, sizeof(struct socket))
	    != sizeof(struct socket)) {
D 11
		vprintf("error %d reading socket at %x from kmem\n", errno, (int)sock);
E 11
I 11
		rerr2(errno, (int)sock, "socket");
E 11
E 6
		return;
	}

	/* fill in protosw entry */
D 6
	lseek(kmem, (long) so.so_proto, 0);
	if (read(kmem, (char *) &proto, sizeof(struct protosw)) 
	    != sizeof(struct protosw)){
		vprintf("error %d reading protosw at %x from kmem\n", errno, so.so_proto);
E 6
I 6
	(void)lseek(kmem, (off_t)so.so_proto, L_SET);
	if (read(kmem, (char *)&proto, sizeof(struct protosw))
	    != sizeof(struct protosw)) {
D 11
		vprintf("error %d reading protosw at %x from kmem\n", errno, (int)so.so_proto);
E 11
I 11
		rerr2(errno, (int)so.so_proto, "protosw");
E 11
E 6
		return;
	}

	/* fill in domain */
D 6
	lseek(kmem, (long) proto.pr_domain, 0);
	if (read(kmem, (char *) &dom, sizeof(struct domain)) 
	    != sizeof(struct domain)){
		vprintf("error %d reading domain at %x from kmem\n", errno, proto.pr_domain);
E 6
I 6
	(void)lseek(kmem, (off_t)proto.pr_domain, L_SET);
	if (read(kmem, (char *)&dom, sizeof(struct domain))
	    != sizeof(struct domain)) {
D 11
		vprintf("error %d reading domain at %x from kmem\n", errno, (int)proto.pr_domain);
E 11
I 11
		rerr2(errno, (int)proto.pr_domain, "domain");
E 11
E 6
		return;
	}

D 7
	/* Grab domain name */
D 6
	lseek(kmem, (long) dom.dom_name, 0);
	for (cp=dname, i=0; i < 30; i++, cp++) { /* 30 leaves room for null byte */
E 6
I 6
	(void)lseek(kmem, (off_t)dom.dom_name, L_SET);
	/* 30 leaves room for null byte */
	for (cp = dname, i = 0; i < 30; i++, cp++) {
E 6
		if (read(kmem, (char *)&c, sizeof(char)) != sizeof(char)) {
D 6
		    vprintf("error %d reading char at %x from kmem\n", errno, dom.dom_name+i);
E 6
I 6
		    vprintf("error %d reading char at %x from kmem\n", errno, (int)(dom.dom_name+i));
E 6
		    break;
		}
		if (c == '\0')
			break;
		*cp = c;
	}
D 6
	*cp='\0';
E 6
I 6
	*cp = '\0';
E 6
	/* kludge "internet" --> "inet" for brevity */
E 7
I 7
	/*
	 * grab domain name
	 * kludge "internet" --> "inet" for brevity
	 */
E 7
D 6
	if (dom.dom_family == AF_INET)	
		strcpy(dname, "inet");
E 6
I 6
	if (dom.dom_family == AF_INET)
		(void)strcpy(dname, "inet");
E 6
D 7

D 4
	if (so.so_type < 1 || so.so_type > STYPEMAX)
		stype = (char *)sprintf(emalloc(10),"unk%d", so.so_type);
	else
E 4
I 4
	if (so.so_type < 1 || so.so_type > STYPEMAX) {
D 6
		
E 6
		stype = emalloc(10);
D 6
		(void)sprintf(stype,"unk%d", so.so_type);
	} else
E 6
I 6
		(void)sprintf(stype, "unk%d", so.so_type);
E 7
I 7
	else {
		(void)lseek(kmem, (off_t)dom.dom_name, L_SET);
		if ((len = read(kmem, dname, sizeof(dname) - 1)) < 0) {
D 11
			vprintf("error %d reading char at %x from kmem\n", errno, (int)dom.dom_name);
E 11
I 11
			rerr2(errno, (int)dom.dom_name, "char");
E 11
			dname[0] = '\0';
		}
		else
			dname[len] = '\0';
E 7
	}
I 7

	if ((u_short)so.so_type > STYPEMAX)
		printf("* (%s unk%d %x", dname, so.so_type, so.so_state);
E 7
	else
E 6
E 4
D 7
		stype = stypename[so.so_type];
E 7
I 7
		printf("* (%s %s %x", dname, stypename[so.so_type],
		    so.so_state);
E 7

D 7
	/* print sock type, sock state, and domain name */
	printf("* (%s %s %x", dname, stype, so.so_state);

E 7
	/* 
D 11
	 * protocol specific formating 
E 11
I 11
	 * protocol specific formatting
E 11
	 *
D 7
	 * Try to find interesting things to print.  For tcp, the
	 * interesting thing is the address of the tcpcb, for udp
	 * and others, just the inpcb (socket pcb).  For unix
	 * domain, its the address of the socket pcb and the address of
	 * the connected pcb (if connected).  Otherwise just print
	 * the protocol number and address of the socket itself. The
	 * idea is not to duplicate netstat, but to make available
	 * enough information for further analysis. 
E 7
I 7
	 * Try to find interesting things to print.  For tcp, the interesting
	 * thing is the address of the tcpcb, for udp and others, just the
	 * inpcb (socket pcb).  For unix domain, its the address of the socket
	 * pcb and the address of the connected pcb (if connected).  Otherwise
	 * just print the protocol number and address of the socket itself.
	 * The idea is not to duplicate netstat, but to make available enough
	 * information for further analysis.
E 7
	 */
D 7
	if (dom.dom_family == AF_INET) {
		/* print name of protocol number */
		printf(" %s", getinetproto(proto.pr_protocol));
E 7
I 7
	switch(dom.dom_family) {
	case AF_INET:
		getinetproto(proto.pr_protocol);
E 7
		if (proto.pr_protocol == IPPROTO_TCP ) {
			if (so.so_pcb) {
D 6
				lseek(kmem, (long) so.so_pcb, 0);
				if (read(kmem, (char *) &inpcb, sizeof(struct inpcb)) 
E 6
I 6
				(void)lseek(kmem, (off_t)so.so_pcb, L_SET);
				if (read(kmem, (char *)&inpcb, sizeof(struct inpcb))
E 6
				    != sizeof(struct inpcb)){
D 7
					vprintf("error %d reading inpcb at %x from kmem\n",
D 6
					     errno, so.so_pcb);
E 6
I 6
					     errno, (int)so.so_pcb);
E 7
I 7
D 11
					vprintf("error %d reading inpcb at %x from kmem\n", errno, (int)so.so_pcb);
E 11
I 11
					rerr2(errno, (int)so.so_pcb, "inpcb");
E 11
E 7
E 6
					return;
				}
D 6
				printf(" %x", inpcb.inp_ppcb);
E 6
I 6
				printf(" %x", (int)inpcb.inp_ppcb);
E 6
			}
D 6
		} else if (so.so_pcb) {
				printf(" %x", so.so_pcb);
E 6
		}
D 6
	} else if (dom.dom_family == AF_UNIX) {	
E 6
I 6
		else if (so.so_pcb)
			printf(" %x", (int)so.so_pcb);
D 7
	}
	else if (dom.dom_family == AF_UNIX) {
E 7
I 7
		break;
	case AF_UNIX:
E 7
E 6
		/* print address of pcb and connected pcb */
		if (so.so_pcb) {
D 6
			printf(" %x", so.so_pcb);
			lseek(kmem, (long) so.so_pcb, 0);
			if (read(kmem, (char *) &unpcb, sizeof(struct unpcb)) 
E 6
I 6
			printf(" %x", (int)so.so_pcb);
			(void)lseek(kmem, (off_t)so.so_pcb, L_SET);
			if (read(kmem, (char *)&unpcb, sizeof(struct unpcb))
E 6
			    != sizeof(struct unpcb)){
D 7
				vprintf("error %d reading unpcb at %x from kmem\n",
D 6
				     errno, so.so_pcb);
E 6
I 6
				     errno, (int)so.so_pcb);
E 7
I 7
D 11
				vprintf("error %d reading unpcb at %x from kmem\n", errno, (int)so.so_pcb);
E 11
I 11
				rerr2(errno, (int)so.so_pcb, "unpcb");
E 11
E 7
E 6
				return;
			}
D 3
			if (unpcb.unp_conn)
				printf(" -> %x", unpcb.unp_conn);
E 3
I 3
			if (unpcb.unp_conn) {
D 7
				char shoconn[4]; *shoconn = 0;
E 7
I 7
				char shoconn[4], *cp;
E 7
I 6

I 7
				cp = shoconn;
E 7
E 6
				if (!(so.so_state & SS_CANTRCVMORE))
D 6
					strcat(shoconn, "<");
				strcat(shoconn,"-");
E 6
I 6
D 7
					(void)strcat(shoconn, "<");
				(void)strcat(shoconn, "-");
E 7
I 7
					*cp++ = '<';
				*cp++ = '-';
E 7
E 6
				if (!(so.so_state & SS_CANTSENDMORE))
D 6
					strcat(shoconn, ">");
				printf(" %s %x", shoconn, unpcb.unp_conn);
E 6
I 6
D 7
					(void)strcat(shoconn, ">");
E 7
I 7
					*cp++ = '>';
				*cp = '\0';
E 7
				printf(" %s %x", shoconn, (int)unpcb.unp_conn);
E 6
			}
E 3
		}
D 6
	} else {
		/* print protocol number and socket address */
		printf(" %d %x", proto.pr_protocol, sock);
E 6
D 7
	}
I 6
	else		/* print protocol number and socket address */
E 7
I 7
		break;
	default:
		/* print protocol number and socket address */
E 7
		printf(" %d %x", proto.pr_protocol, (int)sock);
I 7
	}
E 7
E 6
	printf(")\n");
}

D 6
char *
E 6
I 6
D 7
static char *
E 7
I 7
/*
 * getinetproto --
 *	print name of protocol number
 */
static
E 7
E 6
getinetproto(number)
I 6
	int number;
E 6
{
I 4
D 6
	char	*cp;
E 6
I 6
	char *cp;
E 6

E 4
	switch(number) {
D 6
	case 0:	 return("ip");
	case 1:	 return("icmp");
	case 2:	 return("ggp");
	case 6:	 return("tcp");
	case 8:	 return("egp");
	case 12: return("pup");
	case 17: return("udp");
	case 22: return("idp");
E 6
I 6
D 7
	case 0:	  return("ip");
	case 1:	  return("icmp");
	case 2:	  return("ggp");
	case 6:	  return("tcp");
	case 8:	  return("egp");
	case 12:  return("pup");
	case 17:  return("udp");
	case 22:  return("idp");
E 6
	case 255: return("raw");
E 7
I 7
	case IPPROTO_IP:
		cp = "ip"; break;
	case IPPROTO_ICMP:
		cp ="icmp"; break;
	case IPPROTO_GGP:
		cp ="ggp"; break;
	case IPPROTO_TCP:
		cp ="tcp"; break;
	case IPPROTO_EGP:
		cp ="egp"; break;
	case IPPROTO_PUP:
		cp ="pup"; break;
	case IPPROTO_UDP:
		cp ="udp"; break;
	case IPPROTO_IDP:
		cp ="idp"; break;
	case IPPROTO_RAW:
		cp ="raw"; break;
E 7
D 4
	default: return((char *)sprintf(emalloc(16),"%d",number));
E 4
I 4
	default:
D 6
		(void)sprintf(emalloc(16),"%d",number);
E 6
I 6
D 7
		(void)sprintf(cp = emalloc(16), "%d", number);
E 6
		return(cp);
E 7
I 7
		printf(" %d", number);
		return;
E 7
E 4
	}
I 7
	printf(" %s", cp);
E 7
}
D 6
		
char *
E 6
I 6

D 7
static char *
E 6
emalloc(size)
I 6
	int size;
E 7
I 7
static
readf()
E 7
E 6
{
D 6
	char *cp;
	cp = (char *)malloc(size);
	if (cp < 0) {
		fprintf(stderr,"Out of space.\n");
E 6
I 6
D 7
	char *cp, *malloc();

	if (!(cp = (char *)malloc((u_int)size))) {
		fprintf(stderr, "fstat: out of space.\n");
E 6
		exit(1);
	}
	return(cp);
}

D 6
struct  file  *
E 6
I 6
static struct file *
E 6
getf()
{
D 6
	int	i;
	struct file	file;
E 6
I 6
	int i;
E 7
	struct file lfile;
I 7
	int i;
E 7
E 6

D 6
	itrans(DTYPE_INODE, u.u_cdir, WD);
E 6
I 6
	itrans(DTYPE_INODE, user.user.u_cdir, WD);
E 6
	for (i = 0; i < NOFILE; i++) {
D 6
		if (u.u_ofile[i] == 0)
E 6
I 6
		if (user.user.u_ofile[i] == 0)
E 6
			continue;
D 6
		lseek(kmem, (long) u.u_ofile[i], 0);
		if (read(kmem, (char *) &file, sizeof(file)) != sizeof(file)) {
E 6
I 6
		(void)lseek(kmem, (off_t)user.user.u_ofile[i], L_SET);
		if (read(kmem, (char *)&lfile, sizeof(lfile))
		    != sizeof(lfile)) {
E 6
D 7
			cantread("file", kmemf);
E 7
I 7
D 11
			cantread("file", N_KMEM);
E 11
I 11
			rerr1("file", N_KMEM);
E 11
E 7
			continue;
		}
D 6
		/*printf("flag: %x count: %x ",file.f_flag, file.f_count);
		/*fflush(stdout);
		 */
		itrans(file.f_type, file.f_data, i); 
E 6
I 6
		itrans(lfile.f_type, (struct inode *)lfile.f_data, i);
E 6
	}
}

I 6
static
E 6
D 7
usage()
E 7
I 7
D 9
devmatch(idev, inum)
E 9
I 9
devmatch(idev, inum, name)
E 9
	dev_t idev;
	ino_t inum;
I 9
	char  **name;
E 9
E 7
{
D 6
	fputs("usage: fstat [-u user] [-f filename] [-p pid]\n", stderr);
E 6
I 6
D 7
	fputs("usage: fstat [-v] [-u user] [-p pid] [filename ...]\n", stderr);
E 6
	exit(1);
}
E 7
I 7
	register DEVS *d;
E 7

D 6
getuname(uname)
char	*uname;
E 6
I 6
D 7
static
getuname(arg_uname)
	char *arg_uname;
E 6
{
D 6
	struct passwd	*passwd, *getpwnam();
	
	if ((passwd = getpwnam(uname)) == NULL)
		return(-1);
	return(passwd->pw_uid);
E 6
I 6
	struct passwd *passwd, *getpwnam();

	return((passwd = getpwnam(arg_uname)) ? passwd->pw_uid : -1);
E 7
I 7
	for (d = devs; d; d = d->next)
D 9
		if (d->dev == idev && (!d->inum || d->inum == inum))
E 9
I 9
		if (d->dev == idev && (d->inum == 0 || d->inum == inum)) {
			*name = d->name;
E 9
			return(1);
I 9
		}
E 9
	return(0);
E 7
E 6
}

I 6
static
E 6
getfname(filename)
D 6
char	*filename;
E 6
I 6
	char *filename;
E 6
{
D 7
	struct	stat statbuf;
I 3
	struct devs *d, *oldd;
	dev_t dev;
	int inum;
E 7
I 7
	struct stat statbuf;
	DEVS *cur;
	char *malloc();
E 7
E 3

D 6
	if (stat(filename, &statbuf) != 0)
		return(-1);
E 6
I 6
	if (stat(filename, &statbuf)) {
		perror(filename);
D 10
		exit(1);
E 10
I 10
		return(0);
E 10
	}
I 7
	if ((cur = (DEVS *)malloc(sizeof(DEVS))) == NULL) {
		fprintf(stderr, "fstat: out of space.\n");
		exit(1);
	}
	cur->next = devs;
	devs = cur;
E 7
E 6

D 7
	/*
D 6
	 *	if file is block special, look for open files on it
E 6
I 6
	 * if file is block special, look for open files on it
E 6
	 */
E 7
I 7
	/* if file is block special, look for open files on it */
E 7
	if ((statbuf.st_mode & S_IFMT) != S_IFBLK) {
D 7
		inum = statbuf.st_ino;
D 3
		return(statbuf.st_dev);
E 3
I 3
		dev = statbuf.st_dev;
E 7
I 7
		cur->inum = statbuf.st_ino;
		cur->dev = statbuf.st_dev;
E 7
E 3
D 6
	} else {
E 6
I 6
	}
	else {
E 6
D 3
		special++;
E 3
D 7
		inum = 0;
D 3
		return(statbuf.st_rdev);
E 3
I 3
		dev = statbuf.st_rdev;
E 7
I 7
		cur->inum = 0;
		cur->dev = statbuf.st_rdev;
E 7
E 3
	}
I 9
	cur->name = filename;
I 10
	return(1);
E 10
E 9
I 3
D 7
	for (d = oldd = &devs; d; oldd = d, d = d->next)
		;
	d = (struct devs *)emalloc(sizeof(struct devs));
	oldd->next = d;
D 6
	d->next = 0;
E 6
I 6
	d->next = NULL;
E 6
	d->dev = dev;
	d->inum = inum;
E 7
I 7
}

static
openfiles()
{
	if ((kmem = open(N_KMEM, O_RDONLY, 0)) < 0) {
		perror(N_KMEM);
		exit(1);
	}
	if ((mem = open(N_MEM, O_RDONLY, 0)) < 0) {
		perror(N_MEM);
		exit(1);
	}
	if ((swap = open(N_SWAP, O_RDONLY, 0)) < 0) {
		perror(N_SWAP);
		exit(1);
	}
}

static
D 11
cantread(what, fromwhat)
E 11
I 11
rerr1(what, fromwhat)
E 11
	char *what, *fromwhat;
{
D 11
	vprintf("fstat: error reading %s from %s", what, fromwhat);
E 11
I 11
	if (vflg)
		printf("fstat: error reading %s from %s", what, fromwhat);
E 11
}

I 11
static
rerr2(err, address, what)
	int err, address;
	char *what;
{
	if (vflg)
		printf("error %d reading %s at %x from kmem\n", errno, what, address);
}

E 11
static long
lgetw(loc)
	off_t loc;
{
	long word;

	(void)lseek(kmem, (off_t)loc, L_SET);
D 11
	if (read(kmem, (char *) &word, sizeof(word)) != sizeof(word))
		vprintf("error reading kmem at %lx\n", loc);
E 11
I 11
	if (read(kmem, (char *)&word, sizeof(word)) != sizeof(word))
		rerr2(errno, (int)loc, "word");
E 11
	return(word);
}

static
usage()
{
	fputs("usage: fstat [-v] [-u user] [-p pid] [filename ...]\n", stderr);
	exit(1);
E 7
E 3
D 6
}

Atoi(p)
register char *p;
{
	register int n = 0;

	while(*p >= '0' && *p <= '9')
		n = n*10 + *p++ - '0';
	return(*p ? -n : n);
}

klseek(fd, loc, off)
	int fd;
	long loc;
	int off;
{
	static int	sizeSysmap;

	if( kflg && Sysmap == 0)
		{/* initialize Sysmap */

		sizeSysmap = nl[SSYSSIZE].n_value * sizeof( struct pte);
		Sysmap = (struct pte *)calloc( sizeSysmap, 1);
		lseek( kmem, clear( nl[SSYSMAP].n_value), 0);
		if( read( kmem, Sysmap, sizeSysmap) != sizeSysmap)
			{
			printf( "Cant read system page table\n");
			exit(1);
			}
		}
	if( kflg && (loc&0x80000000))
		{/* do mapping for kernel virtual addresses */
		struct pte *ptep;

		loc &= 0x7fffffff;
		ptep = &Sysmap[btop(loc)];
		if( (char *)ptep - (char *)Sysmap > sizeSysmap)
			{
			printf( "no system pte for %s\n", loc);
			exit(1);
			}
		if( ptep->pg_v == 0)
			{
			printf( "system pte invalid for %x\n", loc);
			exit(1);
			}
		loc = (off_t)((loc&PGOFSET) + ptob(ptep->pg_pfnum));
		}
	(void) lseek(fd, (long)loc, off);
E 6
}
E 1
