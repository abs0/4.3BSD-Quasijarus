h50889
s 00013/00016/00705
d D 5.10 03/01/01 15:17:12 msokolov 27 26
c fix login time printing (Y2K and axe the stupid American 12 hour abomination)
c also it's better IMO to say 0 users than 0 user if that's the case
e
s 00001/00000/00720
d D 5.9 88/01/03 01:01:46 bostic 26 25
c fix findidle declaration for ANSI C
e
s 00016/00013/00704
d D 5.8 87/10/26 11:42:29 bostic 25 24
c uptime only needs few nlist entries; bug report 4.3BSD/ucb/129
e
s 00020/00005/00697
d D 5.7 87/10/10 21:29:26 marc 24 23
c reject STOPPED procs, don't reject by uid, and only accept
c procs where the controlling terminal has a pgrp equal to the pgrp of the proc
e
s 00000/00001/00702
d D 5.6 87/08/30 09:10:30 bostic 23 22
c misdeclaration of fread(); bug report 4.3BSD/ucb/108
e
s 00001/00001/00702
d D 5.5 87/05/28 23:09:24 sam 22 21
c set ttywidth properly from terminal state
e
s 00035/00006/00668
d D 5.4 86/12/22 09:23:54 karels 21 19
c don't make me use who too
e
s 00035/00006/00668
d R 5.4 86/12/21 16:28:36 karels 20 19
c don't make me use who too
e
s 00041/00029/00633
d D 5.3 86/02/23 23:38:54 karels 19 18
c don't make me do the arithmetic (he's been idle HOW long?)
e
s 00010/00002/00652
d D 5.2 85/11/15 09:52:15 lepreau 18 17
c ignore zombies; document obscure debug printout
e
s 00015/00002/00639
d D 5.1 85/05/31 09:38:31 dist 17 16
c Add copyright
e
s 00001/00001/00640
d D 4.15 85/05/11 17:10:13 sam 16 14
c print "user" when only 1 user on the machine
e
s 00001/00001/00640
d R 4.15 85/05/11 15:59:20 sam 15 14
c users only when nusers > 1
e
s 00005/00001/00636
d D 4.14 85/01/23 08:40:06 ralph 14 13
c better heuristic for calculating JCPU
e
s 00000/00002/00637
d D 4.13 84/09/17 10:46:38 ralph 13 12
c don't call setbuf.
e
s 00002/00002/00637
d D 4.12 83/05/27 12:14:22 sam 12 11
c fix it one more time....
e
s 00015/00004/00624
d D 4.11 83/05/22 17:31:41 sam 11 10
c changes for new swap area organization
e
s 00015/00008/00613
d D 4.10 83/03/10 19:05:54 sam 10 9
c from shannon
e
s 00001/00001/00620
d D 4.9 82/12/24 12:55:06 sam 9 8
c header files moved around a bit
e
s 00003/00003/00618
d D 4.8 82/11/19 00:47:00 sam 8 7
c times are now stored in seconds in kernel structures
e
s 00012/00010/00609
d D 4.7 82/11/15 11:32:58 sam 7 6
c conversion to 4.1c
e
s 00002/00001/00617
d D 4.6 82/07/14 17:36:58 kre 6 5
c fix rounding bugs in reporting system uptime
e
s 00000/00002/00618
d D 4.5 82/02/26 14:05:18 root 5 4
c get rid of SDETACH
e
s 00007/00007/00613
d D 4.4 81/06/05 15:52:00 root 4 3
c fix bug where hardly ever finds arg list
e
s 00014/00018/00606
d D 4.3 81/02/28 22:55:38 wnj 3 2
c changed for new system style
e
s 00001/00001/00623
d D 4.2 80/12/03 12:31:45 mark 2 1
c fixed bug in -w/-u option: changed 1 to i.
e
s 00624/00000/00000
d D 4.1 80/10/01 17:29:24 bill 1 0
c date and time created 80/10/01 17:29:24 by bill
e
u
U
t
T
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 17
I 11
#ifndef lint
E 11
I 1
D 17
static char *sccsid = "%W% (Berkeley) %G%";
I 11
#endif
E 17
I 17
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 17
E 11
/*
 * w - print system status (who and what)
 *
 * This program is similar to the systat command on Tenex/Tops 10/20
 * It needs read permission on /dev/mem, /dev/kmem, and /dev/drum.
 */
#include <sys/param.h>
#include <nlist.h>
#include <stdio.h>
#include <ctype.h>
#include <utmp.h>
D 7
#include <time.h>
E 7
#include <sys/stat.h>
#include <sys/dir.h>
#include <sys/user.h>
#include <sys/proc.h>
I 21
#include <sys/ioctl.h>
E 21
D 9
#include <sys/pte.h>
E 9
I 9
#include <machine/pte.h>
E 9
#include <sys/vm.h>
I 24
#include <sys/tty.h>
E 24

#define NMAX sizeof(utmp.ut_name)
#define LMAX sizeof(utmp.ut_line)
I 21
#define HMAX sizeof(utmp.ut_host)
E 21

#define ARGWIDTH	33	/* # chars left on 80 col crt for args */

D 3
struct smproc {
E 3
I 3
struct pr {
E 3
	short	w_pid;			/* proc.p_pid */
	char	w_flag;			/* proc.p_flag */
	short	w_size;			/* proc.p_size */
	long	w_seekaddr;		/* where to find args */
	long	w_lastpg;		/* disk address of stack */
	int	w_igintr;		/* INTR+3*QUIT, 0=die, 1=ign, 2=catch */
	time_t	w_time;			/* CPU time used by this process */
	time_t	w_ctime;		/* CPU time used by children */
	dev_t	w_tty;			/* tty device of process */
I 14
	int	w_uid;			/* uid of process */
E 14
	char	w_comm[15];		/* user.u_comm, null terminated */
	char	w_args[ARGWIDTH+1];	/* args if interesting process */
D 3
} pr[NPROC];
E 3
I 3
} *pr;
int	nproc;
E 3

struct	nlist nl[] = {
I 25
	{ "_avenrun" },
#define	X_AVENRUN	0
	{ "_boottime" },
#define	X_BOOTTIME	1
E 25
	{ "_proc" },
D 25
#define	X_PROC		0
E 25
I 25
#define	X_PROC		2
E 25
	{ "_swapdev" },
D 25
#define	X_SWAPDEV	1
E 25
I 25
#define	X_SWAPDEV	3
E 25
	{ "_Usrptmap" },
D 25
#define	X_USRPTMA	2
E 25
I 25
#define	X_USRPTMA	4
E 25
	{ "_usrpt" },
D 25
#define	X_USRPT		3
E 25
I 25
#define	X_USRPT		5
E 25
	{ "_nswap" },
D 25
#define	X_NSWAP		4
	{ "_avenrun" },
#define	X_AVENRUN	5
D 7
	{ "_bootime" },
#define	X_BOOTIME	6
E 7
I 7
	{ "_boottime" },
#define	X_BOOTTIME	6
E 25
I 25
#define	X_NSWAP		6
E 25
E 7
I 3
	{ "_nproc" },
#define	X_NPROC		7
I 11
	{ "_dmmin" },
#define	X_DMMIN		8
	{ "_dmmax" },
#define	X_DMMAX		9
E 11
E 3
D 10
	{ 0 },
E 10
I 10
	{ "" },
E 10
};

FILE	*ps;
FILE	*ut;
FILE	*bootfd;
int	kmem;
int	mem;
int	swap;			/* /dev/kmem, mem, and swap */
int	nswap;
I 11
int	dmmin, dmmax;
E 11
dev_t	tty;
I 14
int	uid;
E 14
char	doing[520];		/* process attached to terminal */
time_t	proctime;		/* cpu time of process in doing */
double	avenrun[3];
I 3
struct	proc *aproc;
I 24
struct  tty ttyent;
E 24
E 3

D 8
#define	DIV60(t)	((t+30)/60)    /* x/60 rounded */ 
E 8
I 8
D 11
#define	DIV60(t)	((t + 30) / 60)    /* x/60 rounded */ 
E 11
I 11
#define	DIV60(t)	((t+30)/60)    /* x/60 rounded */ 
E 11
E 8
D 14
#define	TTYEQ		(tty == pr[i].w_tty)
E 14
I 14
D 24
#define	TTYEQ		(tty == pr[i].w_tty && uid == pr[i].w_uid)
E 24
I 24
#define	TTYEQ		(tty == pr[i].w_tty)
E 24
E 14
#define IGINT		(1+3*1)		/* ignoring both SIGINT & SIGQUIT */

char	*getargs();
D 23
char	*fread();
E 23
char	*ctime();
char	*rindex();
FILE	*popen();
struct	tm *localtime();
I 19
time_t	findidle();
E 19

int	debug;			/* true if -d flag: debugging output */
I 21
int	ttywidth = 80;		/* width of tty */
E 21
int	header = 1;		/* true if -h flag: don't print heading */
int	lflag = 1;		/* true if -l flag: long style output */
I 21
int	prfrom = 1;		/* true if not -f flag: print host from */
E 21
int	login;			/* true if invoked as login shell */
D 19
int	idle;			/* number of minutes user is idle */
E 19
I 19
time_t	idle;			/* number of minutes user is idle */
E 19
int	nusers;			/* number of users logged in now */
char *	sel_user;		/* login of particular user selected */
char firstchar;			/* first char of name of prog invoked as */
time_t	jobtime;		/* total cpu time visible */
time_t	now;			/* the current time of day */
D 19
struct	tm *nowt;		/* current time as time struct */
E 19
D 7
time_t	bootime, uptime;	/* time of last reboot & elapsed time since */
E 7
I 7
struct	timeval boottime;
time_t	uptime;			/* time of last reboot & elapsed time since */
E 7
int	np;			/* number of processes currently active */
struct	utmp utmp;
struct	proc mproc;
D 10
struct	user up;
char	fill[512];
E 10
I 10
union {
	struct user U_up;
	char	pad[NBPG][UPAGES];
} Up;
#define	up	Up.U_up
E 10

main(argc, argv)
	char **argv;
{
	int days, hrs, mins;
	register int i, j;
	char *cp;
	register int curpid, empty;
I 21
	struct winsize win;
I 27
	struct tm *tm;
E 27
E 21
D 13
	char obuf[BUFSIZ];
E 13

D 13
	setbuf(stdout, obuf);
E 13
	login = (argv[0][0] == '-');
	cp = rindex(argv[0], '/');
	firstchar = login ? argv[0][1] : (cp==0) ? argv[0][0] : cp[1];
	cp = argv[0];	/* for Usage */

	while (argc > 1) {
		if (argv[1][0] == '-') {
			for (i=1; argv[1][i]; i++) {
				switch(argv[1][i]) {

				case 'd':
					debug++;
					break;

I 21
				case 'f':
					prfrom = !prfrom;
					break;

E 21
				case 'h':
					header = 0;
					break;

				case 'l':
					lflag++;
					break;

				case 's':
					lflag = 0;
					break;

				case 'u':
				case 'w':
D 2
					firstchar = argv[1][1];
E 2
I 2
					firstchar = argv[1][i];
E 2
					break;

				default:
					printf("Bad flag %s\n", argv[1]);
					exit(1);
				}
			}
		} else {
			if (!isalnum(argv[1][0]) || argc > 2) {
D 21
				printf("Usage: %s [ -hlsuw ] [ user ]\n", cp);
E 21
I 21
				printf("Usage: %s [ -hlsfuw ] [ user ]\n", cp);
E 21
				exit(1);
			} else
				sel_user = argv[1];
		}
		argc--; argv++;
	}

I 21
D 22
	if (ioctl(1, TIOCGWINSZ, &win) == -1 || win.ws_col > 70)
E 22
I 22
D 25
	if (ioctl(1, TIOCGWINSZ, &win) != -1 && win.ws_col > 70)
E 22
		ttywidth = win.ws_col;
E 25
E 21
	if ((kmem = open("/dev/kmem", 0)) < 0) {
		fprintf(stderr, "No kmem\n");
		exit(1);
	}
	nlist("/vmunix", nl);
	if (nl[0].n_type==0) {
		fprintf(stderr, "No namelist\n");
		exit(1);
	}

D 24
	if (firstchar != 'u')
		readpr();
E 24
I 24
D 25
	if (firstchar != 'u')	/* if this program is not "uptime(1)" */
		readpr();	/* then read in procs */
E 25
I 25
	if (firstchar == 'u')	/* uptime(1) */
		nl[X_BOOTTIME+1].n_name = "";
	else {			/* then read in procs, get window size */
		readpr();
		if (ioctl(1, TIOCGWINSZ, &win) != -1 && win.ws_col > 70)
			ttywidth = win.ws_col;
	}
E 25
E 24

	ut = fopen("/etc/utmp","r");
I 19
	time(&now);
E 19
	if (header) {
		/* Print time of day */
D 19
		time(&now);
		nowt = localtime(&now);
		prtat(nowt);
E 19
I 19
D 27
		prtat(&now);
E 27
I 27
		tm = localtime(&now);
		printf(" %2d:%02d", tm->tm_hour, tm->tm_min);
E 27
E 19

		/*
		 * Print how long system has been up.
D 7
		 * (Found by looking for "bootime" in kernel)
E 7
I 7
		 * (Found by looking for "boottime" in kernel)
E 7
		 */
D 7
		lseek(kmem, (long)nl[X_BOOTIME].n_value, 0);
		read(kmem, &bootime, sizeof (bootime));
E 7
I 7
		lseek(kmem, (long)nl[X_BOOTTIME].n_value, 0);
		read(kmem, &boottime, sizeof (boottime));
E 7

D 7
		uptime = now - bootime;
E 7
I 7
		uptime = now - boottime.tv_sec;
E 7
I 6
		uptime += 30;
E 6
		days = uptime / (60*60*24);
		uptime %= (60*60*24);
		hrs = uptime / (60*60);
		uptime %= (60*60);
D 6
		mins = DIV60(uptime);
E 6
I 6
		mins = uptime / 60;
E 6

		printf("  up");
		if (days > 0)
			printf(" %d day%s,", days, days>1?"s":"");
		if (hrs > 0 && mins > 0) {
			printf(" %2d:%02d,", hrs, mins);
		} else {
			if (hrs > 0)
				printf(" %d hr%s,", hrs, hrs>1?"s":"");
			if (mins > 0)
				printf(" %d min%s,", mins, mins>1?"s":"");
		}

		/* Print number of users logged in to system */
		while (fread(&utmp, sizeof(utmp), 1, ut)) {
			if (utmp.ut_name[0] != '\0')
				nusers++;
		}
		rewind(ut);
D 16
		printf("  %d users", nusers);
E 16
I 16
D 27
		printf("  %d user%s", nusers, nusers>1?"s":"");
E 27
I 27
		printf("  %d user%s", nusers, nusers!=1?"s":"");
E 27
E 16

		/*
		 * Print 1, 5, and 15 minute load averages.
		 * (Found by looking in kernel for avenrun).
		 */
		printf(",  load average:");
		lseek(kmem, (long)nl[X_AVENRUN].n_value, 0);
		read(kmem, avenrun, sizeof(avenrun));
		for (i = 0; i < (sizeof(avenrun)/sizeof(avenrun[0])); i++) {
			if (i > 0)
				printf(",");
			printf(" %.2f", avenrun[i]);
		}
		printf("\n");
D 24
		if (firstchar == 'u')
E 24
I 24
		if (firstchar == 'u')	/* if this was uptime(1), finished */
E 24
			exit(0);

		/* Headers for rest of output */
D 21
		if (lflag)
E 21
I 21
		if (lflag && prfrom)
			printf("User     tty from           login@  idle   JCPU   PCPU  what\n");
		else if (lflag)
E 21
			printf("User     tty       login@  idle   JCPU   PCPU  what\n");
I 21
		else if (prfrom)
			printf("User    tty from            idle  what\n");
E 21
		else
			printf("User    tty  idle  what\n");
		fflush(stdout);
	}


	for (;;) {	/* for each entry in utmp */
		if (fread(&utmp, sizeof(utmp), 1, ut) == NULL) {
			fclose(ut);
			exit(0);
		}
		if (utmp.ut_name[0] == '\0')
			continue;	/* that tty is free */
		if (sel_user && strcmpn(utmp.ut_name, sel_user, NMAX) != 0)
			continue;	/* we wanted only somebody else */

		gettty();
		jobtime = 0;
		proctime = 0;
		strcpy(doing, "-");	/* default act: normally never prints */
		empty = 1;
		curpid = -1;
		idle = findidle();
		for (i=0; i<np; i++) {	/* for each process on this tty */
			if (!(TTYEQ))
				continue;
			jobtime += pr[i].w_time + pr[i].w_ctime;
			proctime += pr[i].w_time;
D 18
			if (debug) {
E 18
I 18
			/* 
			 * Meaning of debug fields following proc name is:
			 * & by itself: ignoring both SIGINT and QUIT.
			 *		(==> this proc is not a candidate.)
			 * & <i> <q>:   i is SIGINT status, q is quit.
			 *		0 == DFL, 1 == IGN, 2 == caught.
			 * *:		proc pgrp == tty pgrp.
			 */
			 if (debug) {
E 18
				printf("\t\t%d\t%s", pr[i].w_pid, pr[i].w_args);
				if ((j=pr[i].w_igintr) > 0)
					if (j==IGINT)
						printf(" &");
					else
						printf(" & %d %d", j%3, j/3);
				printf("\n");
			}
			if (empty && pr[i].w_igintr!=IGINT) {
				empty = 0;
				curpid = -1;
			}
			if(pr[i].w_pid>curpid && (pr[i].w_igintr!=IGINT || empty)){
				curpid = pr[i].w_pid;
				strcpy(doing, lflag ? pr[i].w_args : pr[i].w_comm);
#ifdef notdef
				if (doing[0]==0 || doing[0]=='-' && doing[1]<=' ' || doing[0] == '?') {
					strcat(doing, " (");
					strcat(doing, pr[i].w_comm);
					strcat(doing, ")");
				}
#endif
			}
		}
		putline();
	}
}

/* figure out the major/minor device # pair for this tty */
gettty()
{
	char ttybuf[20];
	struct stat statbuf;

	ttybuf[0] = 0;
	strcpy(ttybuf, "/dev/");
	strcat(ttybuf, utmp.ut_line);
	stat(ttybuf, &statbuf);
	tty = statbuf.st_rdev;
I 14
	uid = statbuf.st_uid;
E 14
}

/*
 * putline: print out the accumulated line of info about one user.
 */
putline()
{
	register int tm;
I 21
	int width = ttywidth - 1;
E 21

	/* print login name of the user */
	printf("%-*.*s ", NMAX, NMAX, utmp.ut_name);
I 21
	width -= NMAX + 1;
E 21

	/* print tty user is on */
D 21
	if (lflag)
E 21
I 21
	if (lflag && !prfrom) {
E 21
		/* long form: all (up to) LMAX chars */
		printf("%-*.*s", LMAX, LMAX, utmp.ut_line);
D 21
	else {
E 21
I 21
		width -= LMAX;
	 } else {
E 21
		/* short form: 2 chars, skipping 'tty' if there */
		if (utmp.ut_line[0]=='t' && utmp.ut_line[1]=='t' && utmp.ut_line[2]=='y')
			printf("%-2.2s", &utmp.ut_line[3]);
		else
			printf("%-2.2s", utmp.ut_line);
I 21
		width -= 2;
E 21
	}

D 21
	if (lflag)
E 21
I 21
	if (prfrom) {
		printf(" %-14.14s", utmp.ut_host);
		width -= 15;
	}

	if (lflag) {
E 21
		/* print when the user logged in */
D 19
		prtat(localtime(&utmp.ut_time));
E 19
I 19
		prtat(&utmp.ut_time);
I 21
		width -= 8;
	}
E 21
E 19

	/* print idle time */
D 19
	prttime(idle," ");
E 19
I 19
	if (idle >= 36 * 60)
		printf("%2ddays ", (idle + 12 * 60) / (24 * 60));
	else
		prttime(idle," ");
I 21
	width -= 7;
E 21
E 19

	if (lflag) {
		/* print CPU time for all processes & children */
D 8
		prttime(DIV60(jobtime)," ");
E 8
I 8
D 10
		prttime(jobtime," ");
E 10
I 10
D 12
		prttime(DIV60(jobtime)," ");
E 12
I 12
		prttime(jobtime," ");
I 21
		width -= 7;
E 21
E 12
E 10
E 8
		/* print cpu time for interesting process */
D 8
		prttime(DIV60(proctime)," ");
E 8
I 8
D 10
		prttime(proctime," ");
E 10
I 10
D 12
		prttime(DIV60(proctime)," ");
E 12
I 12
		prttime(proctime," ");
I 21
		width -= 7;
E 21
E 12
E 10
E 8
	}

	/* what user is doing, either command tail or args */
D 21
	printf(" %-.32s\n",doing);
E 21
I 21
	printf(" %-.*s\n", width-1, doing);
E 21
	fflush(stdout);
}

/* find & return number of minutes current tty has been idle */
I 26
time_t
E 26
findidle()
{
	struct stat stbuf;
	long lastaction, diff;
	char ttyname[20];

	strcpy(ttyname, "/dev/");
	strcatn(ttyname, utmp.ut_line, LMAX);
	stat(ttyname, &stbuf);
	time(&now);
	lastaction = stbuf.st_atime;
	diff = now - lastaction;
	diff = DIV60(diff);
	if (diff < 0) diff = 0;
	return(diff);
}

I 19
#define	HR	(60 * 60)
#define	DAY	(24 * HR)
#define	MON	(30 * DAY)

E 19
/*
D 19
 * prttime prints a time in hours and minutes.
E 19
I 19
 * prttime prints a time in hours and minutes or minutes and seconds.
E 19
 * The character string tail is printed at the end, obvious
 * strings to pass are "", " ", or "am".
 */
prttime(tim, tail)
	time_t tim;
	char *tail;
{
D 19
	register int didhrs = 0;
E 19

	if (tim >= 60) {
		printf("%3d:", tim/60);
D 19
		didhrs++;
	} else {
		printf("    ");
	}
	tim %= 60;
	if (tim > 0 || didhrs) {
		printf(didhrs&&tim<10 ? "%02d" : "%2d", tim);
	} else {
		printf("  ");
	}
E 19
I 19
		tim %= 60;
		printf("%02d", tim);
	} else if (tim > 0)
		printf("    %2d", tim);
	else
		printf("      ");
E 19
	printf("%s", tail);
}

I 19
D 27
char *weekday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
E 27
I 27
char *weekday[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };
E 27
char *month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

E 19
D 27
/* prtat prints a 12 hour time given a pointer to a time of day */
E 27
I 27
/* prtat prints a 24 hour time given a pointer to a time of day */
E 27
D 19
prtat(p)
	struct tm *p;
E 19
I 19
prtat(time)
D 27
	long *time;
E 27
I 27
	register long *time;
E 27
E 19
{
D 19
	register int t, pm;
E 19
I 19
D 27
	struct tm *p;
	register int hr, pm;
E 27
I 27
	register struct tm *p;
E 27
E 19

D 19
	t = p -> tm_hour;
	pm = (t > 11);
	if (t > 11)
		t -= 12;
	if (t == 0)
		t = 12;
	prttime(t*60 + p->tm_min, pm ? "pm" : "am");
E 19
I 19
	p = localtime(time);
D 27
	hr = p->tm_hour;
	pm = (hr > 11);
	if (hr > 11)
		hr -= 12;
	if (hr == 0)
		hr = 12;
E 27
	if (now - *time <= 18 * HR)
D 27
		prttime(hr * 60 + p->tm_min, pm ? "pm" : "am");
E 27
I 27
		printf("   %2d:%02d", p->tm_hour, p->tm_min);
E 27
	else if (now - *time <= 7 * DAY)
D 27
		printf(" %s%2d%s", weekday[p->tm_wday], hr, pm ? "pm" : "am");
E 27
I 27
		printf(" %s%2d:%02d", weekday[p->tm_wday], p->tm_hour,
			p->tm_min);
E 27
	else
D 27
		printf(" %2d%s%2d", p->tm_mday, month[p->tm_mon], p->tm_year);
E 27
I 27
		printf(" %2d%s%02d", p->tm_mday, month[p->tm_mon],
			p->tm_year % 100);
E 27
E 19
}

/*
 * readpr finds and reads in the array pr, containing the interesting
 * parts of the proc and user tables for each live process.
I 24
 * We only accept procs whos controlling tty has a pgrp equal to the
 * pgrp of the proc.  This accurately defines the notion of the current
 * process(s), but because of time skew, we always read in the tty struct
 * after reading the proc, even though the same tty struct may have been
 * read earlier on.
E 24
 */
readpr()
{
	int pn, mf, addr, c;
	int szpt, pfnum, i;
	struct pte *Usrptma, *usrpt, *pte, apte;
	struct dblock db;

	Usrptma = (struct pte *) nl[X_USRPTMA].n_value;
	usrpt = (struct pte *) nl[X_USRPT].n_value;
	if((mem = open("/dev/mem", 0)) < 0) {
		fprintf(stderr, "No mem\n");
		exit(1);
	}
	if ((swap = open("/dev/drum", 0)) < 0) {
		fprintf(stderr, "No drum\n");
		exit(1);
	}
	/*
	 * read mem to find swap dev.
	 */
	lseek(kmem, (long)nl[X_SWAPDEV].n_value, 0);
	read(kmem, &nl[X_SWAPDEV].n_value, sizeof(nl[X_SWAPDEV].n_value));
	/*
D 11
	 * Find base of swap
E 11
I 11
	 * Find base of and parameters of swap
E 11
	 */
	lseek(kmem, (long)nl[X_NSWAP].n_value, 0);
	read(kmem, &nswap, sizeof(nswap));
I 11
	lseek(kmem, (long)nl[X_DMMIN].n_value, 0);
	read(kmem, &dmmin, sizeof(dmmin));
	lseek(kmem, (long)nl[X_DMMAX].n_value, 0);
	read(kmem, &dmmax, sizeof(dmmax));
E 11
	/*
	 * Locate proc table
	 */
I 3
	lseek(kmem, (long)nl[X_NPROC].n_value, 0);
	read(kmem, &nproc, sizeof(nproc));
	pr = (struct pr *)calloc(nproc, sizeof (struct pr));
E 3
	np = 0;
D 3
	for (pn=0; pn<NPROC; pn++) {
		lseek(kmem, (long)(nl[X_PROC].n_value + pn*(sizeof mproc)), 0);
E 3
I 3
	lseek(kmem, (long)nl[X_PROC].n_value, 0);
	read(kmem, &aproc, sizeof(aproc));
	for (pn=0; pn<nproc; pn++) {
		lseek(kmem, (int)(aproc + pn), 0);
E 3
		read(kmem, &mproc, sizeof mproc);
		/* decide if it's an interesting process */
D 18
		if (mproc.p_stat==0 || mproc.p_pgrp==0)
E 18
I 18
D 24
		if (mproc.p_stat==0 || mproc.p_stat==SZOMB || mproc.p_pgrp==0)
E 24
I 24
		if (mproc.p_stat==0 || mproc.p_stat==SZOMB 
		    || mproc.p_stat==SSTOP || mproc.p_pgrp==0)
E 24
E 18
			continue;
D 5
		if (mproc.p_flag&SDETACH)
			continue;
E 5
D 3
		
#ifdef notdef
		/*
		 * The following speeds up w on systems with lots of ttys
		 * by ignoring inits and gettys, but loses on root login shells.
		 * On Ernie it reduced user and system time by .3 seconds,
		 * an insignificant amount.  It is commented out since it
		 * will lose when root logs in.
		 */
		if (mproc.p_uid == 0 & mproc.p_ppid == 1)
			continue;
#endif

E 3
		/* find & read in the user structure */
		if ((mproc.p_flag & SLOAD) == 0) {
			/* not in memory - get from swap device */
D 10
			addr = mproc.p_swaddr<<9;
E 10
I 10
			addr = dtob(mproc.p_swaddr);
E 10
			lseek(swap, (long)addr, 0);
			if (read(swap, &up, sizeof(up)) != sizeof(up)) {
				continue;
			}
		} else {
			int p0br, cc;
#define INTPPG (NBPG / sizeof (int))
			struct pte pagetbl[NBPG / sizeof (struct pte)];
			/* loaded, get each page from memory separately */
			szpt = mproc.p_szpt;
			p0br = (int)mproc.p_p0br;
			pte = &Usrptma[btokmx(mproc.p_p0br) + szpt-1];
			lseek(kmem, (long)pte, 0);
			if (read(kmem, &apte, sizeof(apte)) != sizeof(apte))
				continue;
			lseek(mem, ctob(apte.pg_pfnum), 0);
			if (read(mem,pagetbl,sizeof(pagetbl)) != sizeof(pagetbl))   
cont:
				continue;
			for(cc=0; cc<UPAGES; cc++) {	/* get u area */
				int upage = pagetbl[NPTEPG-UPAGES+cc].pg_pfnum;
				lseek(mem,ctob(upage),0);
				if (read(mem,((int *)&up)+INTPPG*cc,NBPG) != NBPG)
					goto cont;
			}
			szpt = up.u_pcb.pcb_szpt;
			pr[np].w_seekaddr = ctob(apte.pg_pfnum);
		}
D 4
		vstodb(0, 1, &up.u_smap, &db, 1);
E 4
I 4
		vstodb(0, CLSIZE, &up.u_smap, &db, 1);
E 4
D 10
		pr[np].w_lastpg = ctob(db.db_base);
E 10
I 10
		pr[np].w_lastpg = dtob(db.db_base);
E 10
		if (up.u_ttyp == NULL)
I 24
			continue;

		/* only include a process whose tty has a pgrp which matchs its own */
		lseek(kmem, (long)up.u_ttyp, 0);
		if (read(kmem, &ttyent, sizeof(ttyent)) != sizeof(ttyent))
			continue;
		if (ttyent.t_pgrp != mproc.p_pgrp)
E 24
			continue;

		/* save the interesting parts */
		pr[np].w_pid = mproc.p_pid;
		pr[np].w_flag = mproc.p_flag;
		pr[np].w_size = mproc.p_dsize + mproc.p_ssize;
D 10
		pr[np].w_igintr = (((int)up.u_signal[2]==1) + 2*((int)up.u_signal[2]>1) + 3*((int)up.u_signal[3]==1)) + 6*((int)up.u_signal[3]>1);
E 10
I 10
		pr[np].w_igintr = (((int)up.u_signal[2]==1) +
		    2*((int)up.u_signal[2]>1) + 3*((int)up.u_signal[3]==1)) +
		    6*((int)up.u_signal[3]>1);
E 10
D 7
		pr[np].w_time = up.u_vm.vm_utime + up.u_vm.vm_stime;
		pr[np].w_ctime = up.u_cvm.vm_utime + up.u_cvm.vm_stime;
E 7
I 7
		pr[np].w_time =
		    up.u_ru.ru_utime.tv_sec + up.u_ru.ru_stime.tv_sec;
		pr[np].w_ctime =
		    up.u_cru.ru_utime.tv_sec + up.u_cru.ru_stime.tv_sec;
E 7
		pr[np].w_tty = up.u_ttyd;
I 14
		pr[np].w_uid = mproc.p_uid;
E 14
		up.u_comm[14] = 0;	/* Bug: This bombs next field. */
		strcpy(pr[np].w_comm, up.u_comm);
		/*
		 * Get args if there's a chance we'll print it.
		 * Cant just save pointer: getargs returns static place.
		 * Cant use strcpyn: that crock blank pads.
		 */
		pr[np].w_args[0] = 0;
		strcatn(pr[np].w_args,getargs(&pr[np]),ARGWIDTH);
		if (pr[np].w_args[0]==0 || pr[np].w_args[0]=='-' && pr[np].w_args[1]<=' ' || pr[np].w_args[0] == '?') {
			strcat(pr[np].w_args, " (");
			strcat(pr[np].w_args, pr[np].w_comm);
			strcat(pr[np].w_args, ")");
		}
		np++;
	}
}

/*
 * getargs: given a pointer to a proc structure, this looks at the swap area
 * and tries to reconstruct the arguments. This is straight out of ps.
 */
char *
getargs(p)
D 3
	struct smproc *p;
E 3
I 3
	struct pr *p;
E 3
{
	int c, addr, nbad;
D 4
	static int abuf[512/sizeof(int)];
E 4
I 4
	static int abuf[CLSIZE*NBPG/sizeof(int)];
E 4
	struct pte pagetbl[NPTEPG];
	register int *ip;
	register char *cp, *cp1;

	if ((p->w_flag & SLOAD) == 0) {
		lseek(swap, p->w_lastpg, 0);
		if (read(swap, abuf, sizeof(abuf)) != sizeof(abuf))
			return(p->w_comm);
	} else {
		c = p->w_seekaddr;
		lseek(mem,c,0);
		if (read(mem,pagetbl,NBPG) != NBPG)
			return(p->w_comm);
D 4
		if (pagetbl[NPTEPG-1-UPAGES].pg_fod==0 && pagetbl[NPTEPG-1-UPAGES].pg_pfnum) {
			lseek(mem,ctob(pagetbl[NPTEPG-1-UPAGES].pg_pfnum),0);
E 4
I 4
		if (pagetbl[NPTEPG-CLSIZE-UPAGES].pg_fod==0 && pagetbl[NPTEPG-CLSIZE-UPAGES].pg_pfnum) {
			lseek(mem,ctob(pagetbl[NPTEPG-CLSIZE-UPAGES].pg_pfnum),0);
E 4
			if (read(mem,abuf,sizeof(abuf)) != sizeof(abuf))
				return(p->w_comm);
		} else {
			lseek(swap, p->w_lastpg, 0);
			if (read(swap, abuf, sizeof(abuf)) != sizeof(abuf))
				return(p->w_comm);
		}
	}
D 4
	abuf[127] = 0;
	for (ip = &abuf[126]; ip > abuf;) {
E 4
I 4
	abuf[sizeof(abuf)/sizeof(abuf[0])-1] = 0;
	for (ip = &abuf[sizeof(abuf)/sizeof(abuf[0])-2]; ip > abuf;) {
E 4
		/* Look from top for -1 or 0 as terminator flag. */
		if (*--ip == -1 || *ip == 0) {
			cp = (char *)(ip+1);
			if (*cp==0)
				cp++;
			nbad = 0;	/* up to 5 funny chars as ?'s */
D 4
			for (cp1 = cp; cp1 < (char *)&abuf[128]; cp1++) {
E 4
I 4
			for (cp1 = cp; cp1 < (char *)&abuf[sizeof(abuf)/sizeof(abuf[0])]; cp1++) {
E 4
				c = *cp1&0177;
				if (c==0)  /* nulls between args => spaces */
					*cp1 = ' ';
				else if (c < ' ' || c > 0176) {
					if (++nbad >= 5) {
						*cp1++ = ' ';
						break;
					}
					*cp1 = '?';
				} else if (c=='=') {	/* Oops - found an
							 * environment var, back
							 * over & erase it. */
					*cp1 = 0;
					while (cp1>cp && *--cp1!=' ')
						*cp1 = 0;
					break;
				}
			}
			while (*--cp1==' ')	/* strip trailing spaces */
				*cp1 = 0;
			return(cp);
		}
	}
	return (p->w_comm);
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
D 11
	register int blk = DMMIN;
E 11
I 11
	register int blk = dmmin;
E 11
	register swblk_t *ip = dmp->dm_map;

I 10
	vsbase = ctod(vsbase);
	vssize = ctod(vssize);
E 10
	if (vsbase < 0 || vsbase + vssize > dmp->dm_size)
		panic("vstodb");
	while (vsbase >= blk) {
		vsbase -= blk;
D 11
		if (blk < DMMAX)
E 11
I 11
		if (blk < dmmax)
E 11
			blk *= 2;
		ip++;
	}
	if (*ip <= 0 || *ip + blk > nswap)
		panic("vstodb *ip");
	dbp->db_size = min(vssize, blk - vsbase);
	dbp->db_base = *ip + (rev ? blk - (vsbase + dbp->db_size) : vsbase);
}

panic(cp)
	char *cp;
{

	/* printf("%s\n", cp); */
}

min(a, b)
{

	return (a < b ? a : b);
}
E 1
