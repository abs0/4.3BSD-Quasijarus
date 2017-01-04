h34513
s 00063/00007/00979
d D 5.17 88/05/04 13:51:23 rick 17 16
c add missing logcls(); use setproctitle a la sendmail
e
s 00060/00037/00926
d D 5.16 88/04/05 12:02:51 rick 16 15
c use syslog for errors, misc bugsfixes, use getopt
e
s 00091/00023/00872
d D 5.15 88/02/24 19:46:37 rick 15 14
c better loggin. collect stats for connect accounting
e
s 00003/00002/00892
d D 5.14 86/04/14 08:33:30 bloom 14 13
c check if debugging allowed earlier to stop reading of L.sys
e
s 00003/00000/00891
d D 5.13 86/02/12 17:13:39 bloom 13 12
c avoid problems with previously blocked signals
e
s 00004/00008/00887
d D 5.12 86/01/24 13:18:05 bloom 12 11
c still more fixes and changes from rick@seismo
e
s 00204/00141/00691
d D 5.11 86/01/06 15:00:57 bloom 11 10
c more fixes from rick adams
e
s 00002/00001/00830
d D 5.10 85/11/22 05:48:00 tef 10 9
c Must set linebaudrate variable when in slave mode too.
e
s 00033/00029/00798
d D 5.9 85/10/09 15:32:44 bloom 9 8
c still more fixes from rick@seismo
e
s 00009/00008/00818
d D 5.8 85/06/24 10:18:27 bloom 8 7
c still more fixes from rick adams
e
s 00094/00082/00732
d D 5.7 85/06/19 17:57:40 bloom 7 6
c fixes from rick adams
e
s 00036/00009/00778
d D 5.6 85/04/10 15:18:09 ralph 6 5
c more changes from rick adams.
e
s 00365/00159/00422
d D 5.5 85/01/22 12:29:00 ralph 5 4
c bug fixes & changes from Rick Adams
e
s 00006/00000/00575
d D 5.4 84/08/30 16:13:42 ralph 4 3
c added network device NET
e
s 00004/00000/00571
d D 5.3 83/10/03 11:14:25 tef 3 2
c update intrEXIT for new signal mechanism
e
s 00002/00000/00569
d D 5.2 83/07/19 11:02:48 gray 2 1
c added 2 systats so uusnap does not misslead people
e
s 00569/00000/00000
d D 5.1 83/07/02 17:56:26 sam 1 0
c date and time created 83/07/02 17:56:26 by sam
e
u
U
t
T
I 1
#ifndef lint
D 16
static char sccsid[] = "%W% (Berkeley) %G%";
E 16
I 16
static char sccsid[] = "%W%	(Berkeley) %G%";
E 16
#endif

D 7
#include "uucp.h"
E 7
#include <signal.h>
I 7
#include "uucp.h"
E 7
#include <setjmp.h>
D 6
#include <sys/types.h>
E 6
D 5
#ifdef	SYSIII
E 5
I 5
#ifdef	USG
E 5
#include <termio.h>
I 15
#include <fcntl.h>
E 15
#endif
D 5
#ifndef	SYSIII
E 5
I 5
#ifndef	USG
E 5
#include <sgtty.h>
#endif
I 5
#ifdef BSDTCP
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#endif BSDTCP
#include <sys/stat.h>
I 15
#ifdef BSD4_2
#include <sys/time.h>
#include <fcntl.h>
#else
#include <time.h>
#endif
E 15
#include "uust.h"
#include "uusub.h"
E 5

I 7
#if defined(VMS) && defined(BSDTCP)
#define NOGETPEER
#endif

D 16
#ifdef BSD2_9
#define NOGETPEER
#endif

E 16
E 7
D 5

#ifdef UNET
#include <UNET/unetio.h>
#include <UNET/tcp.h>
static struct uiocstate ust;
#endif

E 5
jmp_buf Sjbuf;
D 5
	/*  call fail text  */
E 5
I 5
jmp_buf Pipebuf;

/*  call fail text  */
E 5
char *Stattext[] = {
	"",
	"BAD SYSTEM",
D 5
	"WRONG TIME",
E 5
I 5
	"WRONG TIME TO CALL",
E 5
	"SYSTEM LOCKED",
	"NO DEVICE",
D 11
	"DIAL FAILED",
E 11
I 11
	"CALL FAILED",
E 11
	"LOGIN FAILED",
	"BAD SEQUENCE"
D 5
	};
E 5
I 5
};
E 5

D 5
int Role = 0;
	/*  call fail codes  */
int Stattype[] = {0, 0, 0, 0,
	SS_NODEVICE, SS_FAIL, SS_FAIL, SS_BADSEQ
	};
E 5
I 5
/*  call fail codes  */
int Stattype[] = {
	0,
	0,
	SS_WRONGTIME,
	0,
	SS_NODEVICE,
	SS_FAIL,
	SS_FAIL,
	SS_BADSEQ
};
E 5

I 11
				/* Arguments to setdebug():		     */
#define DBG_TEMP  0		/*   Create a temporary audit file	     */
#define DBG_PERM  1		/*   Create a permanent audit file	     */
#define DBG_CLEAN 2		/*   Cleanup, discard temp file		     */
E 11

D 7
int Errorrate = 0;
E 7
D 5
#ifdef	SYSIII
E 5
I 5
int ReverseRole = 0;
D 11
int StdErrIsTty = 0;
E 11
int Role = SLAVE;
I 15
int InitialRole = SLAVE;
long StartTime;
E 15
int onesys = 0;
I 6
int turntime = 30 * 60;	/* 30 minutes expressed in seconds */
I 11
char *ttyn = NULL;
E 11
E 6
extern int LocalOnly;
I 11
extern int errno;
E 11
D 6
extern char MaxGrade;
E 6
I 6
extern char MaxGrade, DefMaxGrade;
extern char Myfullname[];
E 6

I 15
long Bytes_Sent, Bytes_Received;

E 15
#ifdef	USG
E 5
struct termio Savettyb;
#endif
D 5
#ifndef	SYSIII
E 5
I 5
#ifndef	USG
E 5
struct sgttyb Savettyb;
#endif

I 17
#define SETPROCTITLE
#ifdef SETPROCTITLE
char	**Argv = NULL;		/* pointer to argument vector */
char	*LastArgv = NULL;	/* end of argv */
#endif SETPROCTITLE

E 17
D 11
/*******
 *	cico - this program is used  to place a call to a
E 11
I 11
/*
 *	this program is used  to place a call to a
E 11
 *	remote machine, login, and copy files between the two machines.
 */
D 11

E 11
D 17
main(argc, argv)
E 17
I 17
main(argc, argv, envp)
E 17
I 11
int argc;
E 11
D 16
register char *argv[];
E 16
I 16
char **argv;
I 17
char **envp;
E 17
E 16
{
	register int ret;
	int seq;
D 5
	int onesys = 0;
E 5
	char wkpre[NAMESIZE], file[NAMESIZE];
D 5
	char msg[BUFSIZ], *q;
E 5
I 5
D 11
	char msg[MAXFULLNAME], *q, **alias;
E 11
I 11
	char msg[MAXFULLNAME], *q;
E 11
E 5
	register char *p;
D 11
	extern onintr(), timeout(), setdebug();
E 11
I 11
	extern onintr(), timeout(), dbg_signal();
E 11
D 5
	extern intrEXIT();
E 5
	extern char *pskip();
I 16
	extern char *optarg;
	extern int optind;
E 16
D 8
	char rflags[30];
E 8
I 8
	char rflags[MAXFULLNAME];
E 8
D 11
	char *ttyn;
E 11
D 5
	int orig_uid = getuid();
E 5
I 5
D 7
#if defined(VMS) && defined(BSDTCP)
E 7
I 7
#ifdef NOGETPEER
E 7
	u_long Hostnumber = 0;
D 7
#endif VMS && BSDTCP
E 7
I 7
#endif NOGETPEER
E 7
E 5

	strcpy(Progname, "uucico");
D 7
	uucpname(Myname);
E 7

I 13
#ifdef BSD4_2
D 16
	sigsetmask(0);	/* in case we inherit blocked signals */
E 16
I 16
	sigsetmask(0L);	/* in case we inherit blocked signals */
E 16
#endif BSD4_2
E 13
D 5
	/* Try to run as uucp -- rti!trt */
	setgid(getegid());
	setuid(geteuid());

	signal(SIGILL, intrEXIT);
	signal(SIGTRAP, intrEXIT);
	signal(SIGIOT, intrEXIT);
	signal(SIGEMT, intrEXIT);
	signal(SIGFPE, intrEXIT);
	signal(SIGBUS, intrEXIT);
	signal(SIGSEGV, intrEXIT);
	signal(SIGSYS, intrEXIT);
E 5
	signal(SIGINT, onintr);
	signal(SIGHUP, onintr);
	signal(SIGQUIT, onintr);
	signal(SIGTERM, onintr);
	signal(SIGPIPE, onintr);	/* 4.1a tcp-ip stupidity */
D 11
	signal(SIGFPE, setdebug);
E 11
I 11
	signal(SIGFPE, dbg_signal);
E 11
	ret = guinfo(getuid(), User, msg);
	strcpy(Loginuser, User);
I 7
	uucpname(Myname);
E 7
D 5
	ASSERT(ret == 0, "BAD UID ", "", ret);
E 5
I 5
D 16
	ASSERT(ret == 0, "BAD UID", CNULL, ret);
E 16
I 16
	if (ret == FAIL) {
		syslog(LOG_ERR, "can't get uid");
		cleanup(FAIL);
	}
E 16
E 5

I 5
D 11
#ifdef BSD4_2
	setlinebuf(stderr);
#endif
E 11
I 11
	setbuf (stderr, CNULL);

	rflags[0] = '\0';
E 11
E 5
D 9
	rflags[0] = '\0';
E 9
	umask(WFMASK);
	strcpy(Rmtname, Myname);
	Ifn = Ofn = -1;
D 16
	while(argc>1 && argv[1][0] == '-'){
		switch(argv[1][1]){
E 16
I 16
	while ((ret = getopt(argc, argv, "RLd:g:p:r:s:x:t:")) != EOF)
		switch(ret){
E 16
		case 'd':
D 16
			Spool = &argv[1][2];
E 16
I 16
			Spool = optarg;
E 16
			break;
I 4
D 5
#ifdef TCPNET
		case 'v':
			Unet = 1;
			break;
#endif TCPNET

E 4
#ifdef PROTODEBUG
		case 'E':
			Errorrate = atoi(&argv[1][2]);
			if (Errorrate <= 0)
				Errorrate = 100;
			break;
E 5
		case 'g':
D 5
			Pkdrvon = 1;
E 5
I 5
D 6
			MaxGrade = argv[1][2];
E 6
I 6
		case 'p':
D 16
			MaxGrade = DefMaxGrade = argv[1][2];
E 16
I 16
			MaxGrade = DefMaxGrade = *optarg;
E 16
E 6
E 5
			break;
D 5
		case 'G':
			Pkdrvon = 1;
			strcat(rflags, " -g ");
			break;
#endif
E 5
		case 'r':
D 16
			Role = atoi(&argv[1][2]);
E 16
I 16
			Role = atoi(optarg);
E 16
			break;
I 5
		case 'R':
			ReverseRole++;
			Role = MASTER;
			break;
E 5
		case 's':
D 7
			sprintf(Rmtname, "%.7s", &argv[1][2]);
E 7
I 7
D 16
			strncpy(Rmtname, &argv[1][2], MAXBASENAME);
E 16
I 16
			strncpy(Rmtname, optarg, MAXBASENAME);
E 16
			Rmtname[MAXBASENAME] = '\0';
E 7
			if (Rmtname[0] != '\0')
				onesys = 1;
			break;
		case 'x':
D 5
			chkdebug(orig_uid);
E 5
I 5
D 11
			chkdebug();
E 11
E 5
D 16
			Debug = atoi(&argv[1][2]);
E 16
I 16
			Debug = atoi(optarg);
E 16
			if (Debug <= 0)
				Debug = 1;
D 9
			strcat(rflags, argv[1]);
E 9
D 11
			logent("ENABLED", "DEBUG");
E 11
I 11
D 16
			strcat(rflags, argv[1]);
E 16
I 16
			strcat(rflags, argv[optind-1]);
E 16
E 11
			break;
I 6
		case 't':
D 16
			turntime = atoi(&argv[1][2])*60;/* minutes to seconds */
E 16
I 16
			turntime = atoi(optarg)*60;/* minutes to seconds */
E 16
			break;
E 6
I 5
		case 'L':	/* local calls only */
			LocalOnly++;
			break;
D 7
#if defined(VMS) && defined(BSDTCP)
E 7
I 7
#ifdef NOGETPEER
E 7
		case 'h':
			Hostnumber = inet_addr(&argv[1][2]);
			break;
D 7
#endif VMS && BSDTCP
E 7
I 7
#endif NOGETPEER
I 16
		case '?':
E 16
E 7
E 5
		default:
D 5
			printf("unknown flag %s\n", argv[1]);
E 5
I 5
D 16
			printf("unknown flag %s (ignored)\n", argv[1]);
E 16
I 16
			fprintf(stderr, "unknown flag %s (ignored)\n",
				argv[optind-1]);
E 16
E 5
			break;
		}
D 16
		--argc;  argv++;
	}
E 16

D 5
	subchdir(Spool);
	strcpy(Wrkdir, Spool);
E 5
I 5
D 16
	while (argc > 1) {
D 11
		printf("unknown argument %s (ignored)\n", argv[1]);
E 11
I 11
		fprintf(stderr, "unknown argument %s (ignored)\n", argv[1]);
E 11
		--argc; argv++;
	}
E 16
I 16
	while (optind < argc)
		fprintf(stderr, "unknown argument %s (ignored)\n",
			argv[optind++]);
E 16
E 5

I 14
	if (Debug && Role == MASTER)
		chkdebug();

I 17
#ifdef SETPROCTITLE
	/*
	 *  Save start and extent of argv for setproctitle.
	 */

	Argv = argv;
	LastArgv = argv[argc - 1] + strlen(argv[argc - 1]);
#endif SETPROCTITLE

E 17
E 14
D 5
#ifdef	UNET
/*
 * Determine if we are on UNET
 */
	ret = ioctl(0, UIOCSTATE, &ust);
	if (ret == 0) {
		Unet = 1;
		DEBUG(4, "UNET connection -- ioctl-s disabled\n", "");
E 5
I 5
D 9
	/* Try to run as uucp -- rti!trt */
E 9
I 9
	/* Try to run as uucp */
E 9
	setgid(getegid());
	setuid(geteuid());
#ifdef	TIOCNOTTY
	/*
	 * detach uucico from controlling terminal
	 * to defend against rlogind sending us a SIGKILL (!!!)
	 */
	if (Role == MASTER && (ret = open("/dev/tty", 2)) >= 0) {
		ioctl(ret, TIOCNOTTY, STBNULL);
		close(ret);
E 5
	}
D 5
#endif
E 5
I 5
#endif TIOCNOTTY
#ifdef BSD4_2
D 10
	if (getpgrp(0) == 0) { /*We have no controlling terminal */
E 10
I 10
	if (getpgrp(0) == 0) { /* We have no controlling terminal */
E 10
		setpgrp(0, getpid());
	}
I 16
#ifdef USE_SYSLOG
#ifdef BSD4_3
	openlog("uucico", LOG_PID, LOG_UUCP);
#else /* !BSD4_3 */
	openlog("uucico", LOG_PID);
#endif /* !BSD4_3 */
#endif /* USE_SYSLOG */
E 16
#endif BSD4_2

D 16
	ret = subchdir(Spool);
	ASSERT(ret >= 0, "CHDIR FAILED", Spool, ret);
E 16
I 16
#ifdef BSD4_3
	unsetenv("TZ");		/* We don't want him resetting our time zone */
#endif /* !BSD4_3 */

	if (subchdir(Spool) < 0) {
		syslog(LOG_ERR, "chdir(%s) failed: %m", Spool);
		cleanup(FAIL);
	}

E 16
	strcpy(Wrkdir, Spool);

I 11
	if (Debug) {
D 14
		if (Role == MASTER)
			chkdebug();
E 14
		setdebug ((Role == SLAVE) ? DBG_TEMP : DBG_PERM);
		if (Debug > 0)
			logent ("Local Enabled", "DEBUG");
	}

	/*
	 * First time through: If we're the slave, do initial checking.
	 */
E 11
E 5
	if (Role == SLAVE) {
I 5
		/* check for /etc/nologin */
D 9
		ultouch();	/* sets nologinflag as a side effect */
		if (nologinflag) {
E 9
I 9
		if (access(NOLOGIN, 0) == 0) {
E 9
			logent(NOLOGIN, "UUCICO SHUTDOWN");
D 7
			if (Debug)
E 7
I 7
			if (Debug > 4)
E 7
				logent("DEBUGGING", "continuing anyway");
			else
				cleanup(1);
		}
I 11
		Ifn = 0;
		Ofn = 1;
E 11
#ifdef	TCPIP
		/*
		 * Determine if we are on TCPIP
		 */
D 11
		if (isatty(0) ==  0) {
E 11
I 11
D 15
		if (isatty(Ifn) < 0) {
E 15
I 15
		if (isatty(Ifn) == 0) {
E 15
E 11
			IsTcpIp = 1;
			DEBUG(4, "TCPIP connection -- ioctl-s disabled\n", CNULL);
D 7
		}
E 7
I 7
		} else
			IsTcpIp = 0;
E 7
#endif TCPIP
E 5
		/* initial handshake */
		onesys = 1;
D 5
		if (!Unet) {
#ifdef	SYSIII
E 5
I 5
		if (!IsTcpIp) {
#ifdef	USG
E 5
D 11
			ret = ioctl(0, TCGETA, &Savettyb);
E 11
I 11
			ret = ioctl(Ifn, TCGETA, &Savettyb);
E 11
			Savettyb.c_cflag = (Savettyb.c_cflag & ~CS8) | CS7;
			Savettyb.c_oflag |= OPOST;
			Savettyb.c_lflag |= (ISIG|ICANON|ECHO);
D 5
#endif
#ifndef	SYSIII
E 5
I 5
#else !USG
E 5
D 11
			ret = ioctl(0, TIOCGETP, &Savettyb);
E 11
I 11
			ret = ioctl(Ifn, TIOCGETP, &Savettyb);
E 11
			Savettyb.sg_flags |= ECHO;
			Savettyb.sg_flags &= ~RAW;
D 5
#endif
E 5
I 5
#endif !USG
I 11
			ttyn = ttyname(Ifn);
E 11
E 5
		}
D 11
		Ifn = 0;
		Ofn = 1;
E 11
		fixmode(Ifn);
I 10
D 12
		getbaud(Ifn);
E 12
E 10
D 5
		fclose(stderr);
		fopen(RMTDEBUG, "w");
		omsg('S', "here", Ofn);
E 5
I 5
D 11
		sprintf(file,"%s/%d", RMTDEBUG, getpid());
#ifdef VMS
		/* hold the version number down */
		unlink(file);
D 7
#endif
E 7
I 7
#endif VMS
E 7
		freopen(file, "w", stderr);
#ifdef BSD4_2
		setlinebuf(stderr);
#else  !BSD4_2
		setbuf(stderr, NULL);
#endif !BSD4_2
E 11
I 11

		/*
		 * Initial Message -- tell them we're here, and who we are.
		 */
E 11
D 6
		sprintf(msg, "here=%s", Myname);
E 6
I 6
		sprintf(msg, "here=%s", Myfullname);
E 6
		omsg('S', msg, Ofn);
E 5
		signal(SIGALRM, timeout);
D 15
		alarm(MAXMSGTIME);
E 15
I 15
		alarm(IsTcpIp?MAXMSGTIME*4:MAXMSGTIME);
E 15
		if (setjmp(Sjbuf)) {
			/* timed out */
D 5
			if (!Unet) {
#ifdef	SYSIII
E 5
I 5
			if (!IsTcpIp) {
#ifdef	USG
E 5
D 11
				ret = ioctl(0, TCSETA, &Savettyb);
E 11
I 11
				ret = ioctl(Ifn, TCSETA, &Savettyb);

E 11
D 7
#endif
D 5
#ifndef	SYSIII
E 5
I 5
#ifndef	USG
E 7
I 7
#else	!USG
E 7
E 5
D 11
				ret = ioctl(0, TIOCSETP, &Savettyb);
E 11
I 11
				ret = ioctl(Ifn, TIOCSETP, &Savettyb);
E 11
D 7
#endif
E 7
I 7
#endif !USG
E 7
			}
D 5
			exit(0);
E 5
I 5
			cleanup(0);
E 5
		}
		for (;;) {
			ret = imsg(msg, Ifn);
D 11
			if (ret != 0) {
E 11
I 11
			if (ret != SUCCESS) {
E 11
				alarm(0);
D 5
				if (!Unet) {
#ifdef	SYSIII
E 5
I 5
				if (!IsTcpIp) {
#ifdef	USG
E 5
D 11
					ret = ioctl(0, TCSETA, &Savettyb);
E 11
I 11
					ret = ioctl(Ifn, TCSETA, &Savettyb);
E 11
D 7
#endif
D 5
#ifndef	SYSIII
E 5
I 5
#ifndef	USG
E 7
I 7
#else	!USG
E 7
E 5
D 11
					ret = ioctl(0, TIOCSETP, &Savettyb);
E 11
I 11
					ret = ioctl(Ifn, TIOCSETP, &Savettyb);
E 11
D 7
#endif
E 7
I 7
#endif !USG
E 7
				}
D 5
				exit(0);
E 5
I 5
				cleanup(0);
E 5
			}
			if (msg[0] == 'S')
				break;
		}
		alarm(0);
		q = &msg[1];
		p = pskip(q);
D 7
		sprintf(Rmtname, "%.7s", q);
E 7
I 7
		strncpy(Rmtname, q, MAXBASENAME);
		Rmtname[MAXBASENAME] = '\0';
E 7
I 5
D 11
		sprintf(wkpre,"%s/%s", RMTDEBUG, Rmtname);
		unlink(wkpre);
		if (link(file, wkpre) == 0)
			unlink(file);
E 11
I 11

		/*
		 * Now that we know who they are, give the audit file the right
		 * name.
		 */
		setdebug (DBG_PERM);
E 11
E 5
		DEBUG(4, "sys-%s\n", Rmtname);
I 7
D 8
#ifdef	NOSTRANGERS
		/* If we don't know them, we won't talk to them... */
E 8
I 8
		/* The versys will also do an alias on the incoming name */
E 8
		if (versys(&Rmtname)) {
I 8
D 15
			/* If we don't know them, we won't talk to them... */
E 15
#ifdef	NOSTRANGERS
E 8
D 15
			logent(Rmtname, "UNKNOWN HOST");
E 15
I 15
			/* If we don't know them, we won't talk to them... */
D 16
			assert("Unknown host:", Rmtname, 0);
E 16
I 16
			syslog(LOG_WARNING, "Unknown host: %s", Rmtname);
E 16
E 15
			omsg('R', "You are unknown to me", Ofn);
			cleanup(0);
D 8
		}
E 8
#endif	NOSTRANGERS
I 8
		}
E 8
E 7
I 5
#ifdef BSDTCP
		/* we must make sure they are really who they say they
		 * are. We compare the hostnumber with the number in the hosts
		 * table for the site they claim to be.
		 */
		if (IsTcpIp) {
			struct hostent *hp;
			char *cpnt, *inet_ntoa();
D 9
			int fromlen;
E 9
I 9
D 11
			int len;
E 11
I 11
			int fromlen;
E 11
E 9
			struct sockaddr_in from;
I 9
			extern char PhoneNumber[];
E 9

D 7
#ifndef	VMS
E 7
I 7
#ifdef	NOGETPEER
			from.sin_addr.s_addr = Hostnumber;
			from.sin_family = AF_INET;
#else	!NOGETPEER
E 7
D 9
			fromlen = sizeof(from);
			if (getpeername(0, &from, &fromlen) < 0) {
E 9
I 9
D 11
			len = sizeof(from);
			if (getpeername(0, &from, &len) < 0) {
E 11
I 11
			fromlen = sizeof(from);
			if (getpeername(Ifn, &from, &fromlen) < 0) {
E 11
E 9
				logent(Rmtname, "NOT A TCP CONNECTION");
				omsg('R', "NOT TCP", Ofn);
				cleanup(0);
			}
D 7
#else	VMS
			from.sin_addr.s_addr = Hostnumber;
			from.sin_family = AF_INET;
#endif	VMS
E 7
I 7
#endif	!NOGETPEER
E 7
			hp = gethostbyaddr(&from.sin_addr,
				sizeof (struct in_addr), from.sin_family);
D 11
			if (hp == 0) {
E 11
I 11
			if (hp == NULL) {
E 11
				/* security break or just old host table? */
				logent(Rmtname, "UNKNOWN IP-HOST Name =");
				cpnt = inet_ntoa(from.sin_addr),
				logent(cpnt, "UNKNOWN IP-HOST Number =");
				sprintf(wkpre, "%s/%s isn't in my host table",
					Rmtname, cpnt);
				omsg('R' ,wkpre ,Ofn);
				cleanup(0);
			}
D 11
			if (Debug>99)
E 11
I 11
			if (Debug > 99)
E 11
				logent(Rmtname,"Request from IP-Host name =");
D 9
			/* The following is to determine if the name given us by
			 * the Remote uucico matches any of the names(aliases)
E 9
I 9
			/*
			 * The following is to determine if the name given us by
			 * the Remote uucico matches any of the names
E 9
			 * given its network number (remote machine) in our
			 * host table.
I 9
			 * We could check the aliases, but that won't work in
			 * all cases (like if you are running the domain
			 * server, where you don't get any aliases). The only
			 * reliable way I can think of that works in ALL cases
			 * is too look up the site in L.sys and see if the
			 * sitename matches what we would call him if we
			 * originated the call.
E 9
			 */
D 7
			if (strncmp(q, hp->h_name, 7) == 0) {
E 7
I 7
D 8
			if (strncmp(q, hp->h_name, MAXBASENAME) == 0) {
E 8
I 8
D 9
			if (strncmp(q, hp->h_name, SYSNSIZE) == 0) {
E 9
I 9
			/* PhoneNumber contains the official network name of the 			   host we are checking. (set in versys.c) */
			if (sncncmp(PhoneNumber, hp->h_name, SYSNSIZE) == 0) {
E 9
E 8
E 7
				if (Debug > 99)
					logent(q,"Found in host Tables");
D 9
			} else { /* Scan The host aliases */
				for(alias=hp->h_aliases; *alias!=0 &&
D 7
				    strncmp(q, *alias, 7) != 0; ++alias)
E 7
I 7
D 8
				    strncmp(q, *alias, MAXBASENAME) != 0; ++alias)
E 8
I 8
				    strncmp(q, *alias, SYSNSIZE) != 0; ++alias)
E 8
E 7
					;
D 7
				if (strncmp(q, *alias, 7) != 0) {
E 7
I 7
D 8
				if (strncmp(q, *alias, MAXBASENAME) != 0) {
E 8
I 8
				if (strncmp(q, *alias, SYSNSIZE) != 0) {
E 8
E 7
					logent(q, "FORGED HOSTNAME");
					logent(inet_ntoa(from.sin_addr), "ORIGINATED AT");
D 7
					omsg('R',"You're not who you claim to be");
E 7
I 7
					omsg('R',"You're not who you claim to be", Ofn);
E 7
					cleanup(0);
				}
#ifdef DEBUG
				if (Debug> 99)
					logent(q,"Found in host Tables");
D 7
#endif
E 7
I 7
#endif DEBUG
E 9
I 9
			} else {
				logent(hp->h_name, "FORGED HOSTNAME");
				logent(inet_ntoa(from.sin_addr), "ORIGINATED AT");
				logent(PhoneNumber, "SHOULD BE");
				sprintf(wkpre, "You're not who you claim to be: %s !=  %s", hp->h_name, PhoneNumber);
				omsg('R', wkpre, Ofn);
				cleanup(0);
E 9
E 7
			}
		}
#endif	BSDTCP

D 7
#ifdef	NOSTRANGERS
		/* If we don't know them, we won't talk to them... */
D 6
		if (versys(Rmtname)) {
E 6
I 6
		if (versys(&Rmtname)) {
E 6
			logent(Rmtname, "UNKNOWN HOST");
			omsg('R', "You are unknown to me", Ofn);
			cleanup(0);
		}
#endif	NOSTRANGERS
E 7
E 5
D 9
		if (mlock(Rmtname)) {
E 9
I 9
D 11
		if (mlock(Rmtname) == FAIL) {
E 11
I 11
		if (mlock(Rmtname)) {
E 11
E 9
			omsg('R', "LCK", Ofn);
			cleanup(0);
		}
		else if (callback(Loginuser)) {
			signal(SIGINT, SIG_IGN);
			signal(SIGHUP, SIG_IGN);
			omsg('R', "CB", Ofn);
			logent("CALLBACK", "REQUIRED");
			/*  set up for call back  */
D 5
			systat(Rmtname, SS_CALLBACK, "CALL BACK");
E 5
I 5
			systat(Rmtname, SS_CALLBACK, "CALLING BACK");
E 5
			gename(CMDPRE, Rmtname, 'C', file);
			close(creat(subfile(file), 0666));
			xuucico(Rmtname);
			cleanup(0);
		}
		seq = 0;
		while (*p == '-') {
			q = pskip(p);
			switch(*(++p)) {
D 5
			case 'g':
				Pkdrvon = 1;
				break;
E 5
			case 'x':
D 11
				Debug = atoi(++p);
				if (Debug <= 0)
					Debug = 1;
E 11
I 11
				if (Debug == 0) {
					Debug = atoi(++p);
					if (Debug <= 0)
						Debug = 1;
					setdebug(DBG_PERM);
					if (Debug > 0)
						logent("Remote Enabled", "DEBUG");
				} else {
					DEBUG(1, "Remote debug request ignored\n",
					   CNULL);
				}
E 11
				break;
			case 'Q':
				seq = atoi(++p);
				break;
I 6
			case 'p':
				MaxGrade = DefMaxGrade = *++p;
				DEBUG(4, "MaxGrade set to %c\n", MaxGrade);
				break;
I 7
			case 'v':
				if (strncmp(p, "grade", 5) == 0) {
					p += 6;
					MaxGrade = DefMaxGrade = *p++;
					DEBUG(4, "MaxGrade set to %c\n", MaxGrade);
				}
				break;
E 7
E 6
			default:
				break;
			}
			p = q;
		}
I 17
		setproctitle("%s: startup", Rmtname);
E 17
		if (callok(Rmtname) == SS_BADSEQ) {
			logent("BADSEQ", "PREVIOUS");
			omsg('R', "BADSEQ", Ofn);
			cleanup(0);
		}
I 5
#ifdef GNXSEQ
E 5
		if ((ret = gnxseq(Rmtname)) == seq) {
			omsg('R', "OK", Ofn);
			cmtseq();
D 5
		}
E 5
I 5
		} else {
#else !GNXSEQ
		if (seq == 0)
			omsg('R', "OK", Ofn);
E 5
		else {
I 5
#endif !GNXSEQ
E 5
			systat(Rmtname, Stattype[7], Stattext[7]);
D 5
			logent("BAD SEQ", "HANDSHAKE FAILED");
E 5
I 5
D 7
			logent("BAD SEQ", "HANDSHAKE FAIL");
E 7
I 7
			logent("BAD SEQ", "FAILED HANDSHAKE");
E 7
#ifdef GNXSEQ
E 5
			ulkseq();
I 5
#endif GNXSEQ
E 5
			omsg('R', "BADSEQ", Ofn);
			cleanup(0);
		}
D 11
		ttyn = ttyname(Ifn);
E 11
		if (ttyn != NULL)
			chmod(ttyn, 0600);
I 5
D 11
	} else { /* Role == MASTER */
		struct stat stbuf;
		if (isatty(fileno(stderr)) || (fstat(fileno(stderr),&stbuf) == 0
		    && stbuf.st_mode&S_IFREG) )
			StdErrIsTty =  1;
		setdebug(0);
E 11
E 5
	}
I 5

E 5
loop:
I 5
	if(setjmp(Pipebuf)) {	/* come here on SIGPIPE	*/
		clsacu();
I 17
		logcls();
E 17
		close(Ofn);
		close(Ifn);
		Ifn = Ofn = -1;
		rmlock(CNULL);
		sleep(3);
	}
E 5
	if (!onesys) {
I 15
		do_connect_accounting();
I 16
#ifdef DIALINOUT
		/* reenable logins on dialout */
		reenable();
#endif DIALINOUT
E 16
		StartTime = 0;
I 17
		setproctitle("looking for work");
E 17
E 15
I 5
D 11
		struct stat sbuf;

		if (!StdErrIsTty) {
			sprintf(file, "%s/%s", RMTDEBUG, Rmtname);
			if (stat(file, &sbuf) == 0 && sbuf.st_size == 0)
				unlink(file);
		}
E 11
E 5
		ret = gnsys(Rmtname, Spool, CMDPRE);
I 17
		setproctitle("%s: startup", Rmtname);
E 17
I 5
D 11
		setdebug(0);
E 11
I 11
		setdebug(DBG_PERM);
E 11
E 5
		if (ret == FAIL)
			cleanup(100);
D 7
		if (ret == 0)
E 7
I 7
D 15
		if (ret == SUCCESS)
E 15
I 15
		else if (ret == SUCCESS)
E 15
E 7
			cleanup(0);
I 17
		logcls();
E 17
D 5
	}
	else if (Role == MASTER && callok(Rmtname) != 0) {
E 5
I 5
	} else if (Role == MASTER && callok(Rmtname) != 0) {
E 5
		logent("SYSTEM STATUS", "CAN NOT CALL");
		cleanup(0);
	}

D 7
	sprintf(wkpre, "%c.%.7s", CMDPRE, Rmtname);
E 7
I 7
	sprintf(wkpre, "%c.%.*s", CMDPRE, SYSNSIZE, Rmtname);
I 15
	StartTime = 0;
	Bytes_Sent = Bytes_Received = 0L;
E 15
E 7

I 5
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
E 5
	if (Role == MASTER) {
I 15
		extern char LineType[];
E 15
I 5
		/* check for /etc/nologin */
D 9
		ultouch();	/* sets nologinflag as a side effect */
		if (nologinflag) {
E 9
I 9
		if (access(NOLOGIN, 0) == 0) {
E 9
			logent(NOLOGIN, "UUCICO SHUTDOWN");
D 7
			if (Debug)
E 7
I 7
			if (Debug > 4)
E 7
				logent("DEBUGGING", "continuing anyway");
			else
				cleanup(1);
		}
E 5
		/*  master part */
D 5
		signal(SIGINT, SIG_IGN);
E 5
		signal(SIGHUP, SIG_IGN);
I 6
D 7
		MaxGrade = DefMaxGrade;
E 6
D 5
		signal(SIGQUIT, SIG_IGN);
E 5
		if (!iswrk(file, "chk", Spool, wkpre) && !onesys) {
			logent(Rmtname, "NO WORK");
			goto next;
		}
E 7
		if (Ifn != -1 && Role == MASTER) {
			write(Ofn, EOTMSG, strlen(EOTMSG));
			clsacu();
			close(Ofn);
			close(Ifn);
			Ifn = Ofn = -1;
			rmlock(CNULL);
			sleep(3);
		}
D 15
		sprintf(msg, "call to %s ", Rmtname);
E 15
D 9
		if (mlock(Rmtname) != 0) {
E 9
I 9
		if (mlock(Rmtname) != SUCCESS) {
E 9
D 15
			logent(msg, "LOCKED");
E 15
I 15
			DEBUG(1, "LOCKED: call to %s\n", Rmtname); 
E 15
I 5
			US_SST(us_s_lock);
E 5
			goto next;
		}
I 17
		setproctitle("%s: starting call", Rmtname);
E 17
		Ofn = Ifn = conn(Rmtname);
I 15
D 17
		sprintf(msg, "call to %s via %s", Rmtname, LineType);
E 17
I 17
		sprintf(msg, "(call to %s via %s)", Rmtname, LineType);
E 17
E 15
		if (Ofn < 0) {
D 5
			logent(msg, "FAILED");
			systat(Rmtname, Stattype[-Ofn],
				Stattext[-Ofn]);
E 5
I 5
			if (Ofn != CF_TIME)
				logent(msg, _FAILED);
			/* avoid excessive 'wrong time' info */
D 7
			if (Stattype[-Ofn] != SS_WRONGTIME || argv[0][0] != 'U'){
E 7
I 7
			if (Stattype[-Ofn] != SS_WRONGTIME){
E 7
				systat(Rmtname, Stattype[-Ofn], Stattext[-Ofn]);
				US_SST(-Ofn);
				UB_SST(-Ofn);
			}
E 5
			goto next;
D 5
		}
		else {
E 5
I 5
		} else {
E 5
			logent(msg, "SUCCEEDED");
I 5
			US_SST(us_s_cok);
			UB_SST(ub_ok);
E 5
		}
I 15
		InitialRole = MASTER;
E 15
D 5
	
E 5
I 5
#ifdef	TCPIP
		/*
		 * Determine if we are on TCPIP
		 */
D 11
		if (isatty(Ifn) ==  0) {
E 11
I 11
		if (isatty(Ifn) == 0) {
E 11
			IsTcpIp = 1;
			DEBUG(4, "TCPIP connection -- ioctl-s disabled\n", CNULL);
D 7
		}
E 7
I 7
		} else
			IsTcpIp = 0;
E 7
#endif

E 5
		if (setjmp(Sjbuf))
			goto next;
		signal(SIGALRM, timeout);
D 15
		alarm(2 * MAXMSGTIME);
E 15
I 15
		alarm(IsTcpIp?MAXMSGTIME*4:MAXMSGTIME*2);
E 15
		for (;;) {
			ret = imsg(msg, Ifn);
D 15
			if (ret != 0) {
E 15
I 15
			if (ret != SUCCESS) {
E 15
				alarm(0);
I 15
				DEBUG(4,"\nimsg failed: errno %d\n", errno);
E 15
D 5
				logent("imsg 1", "FAILED");
				goto next;
E 5
I 5
				logent("imsg 1", _FAILED);
				goto Failure;
E 5
			}
			if (msg[0] == 'S')
				break;
		}
D 15
		alarm(MAXMSGTIME);
E 15
I 15
		alarm(IsTcpIp?MAXMSGTIME*4:MAXMSGTIME);
E 15
I 5
#ifdef GNXSEQ
E 5
		seq = gnxseq(Rmtname);
I 5
#else !GNXSEQ
		seq = 0;
#endif !GNXSEQ
I 9
D 11
		if (Debug)
			sprintf(rflags, "-x%d", Debug);
		else
			rflags[0] = '\0';

E 11
E 9
I 6
		if (MaxGrade != '\177') {
D 8
			char buf[10];
E 8
I 8
D 12
			char buf[MAXFULLNAME];
E 8
D 7
			sprintf(buf, " -p%c", MaxGrade);
E 7
I 7
			sprintf(buf, " -p%c -vgrade=%c", MaxGrade, MaxGrade);
E 7
			strcat(rflags, buf);
		}

E 6
E 5
D 7
		sprintf(msg, "%.7s -Q%d %s", Myname, seq, rflags);
E 7
I 7
		sprintf(msg, "%s -Q%d %s", Myname, seq, rflags);
		if (MaxGrade != '\177')
E 12
			DEBUG(2, "Max Grade this transfer is %c\n", MaxGrade);
I 12
			sprintf(msg, "%s -Q%d -p%c -vgrade=%c %s",
				Myname, seq, MaxGrade, MaxGrade, rflags);
		} else
			sprintf(msg, "%s -Q%d %s", Myname, seq, rflags);
E 12
E 7
		omsg('S', msg, Ofn);
		for (;;) {
			ret = imsg(msg, Ifn);
			DEBUG(4, "msg-%s\n", msg);
D 5
			if (ret != 0) {
E 5
I 5
			if (ret != SUCCESS) {
E 5
				alarm(0);
I 5
#ifdef GNXSEQ
E 5
				ulkseq();
D 5
				logent("imsg 2", "FAILED");
				goto next;
E 5
I 5
#endif GNXSEQ
				logent("imsg 2", _FAILED);
				goto Failure;
E 5
			}
			if (msg[0] == 'R')
				break;
		}
		alarm(0);
		if (msg[1] == 'B') {
			/* bad sequence */
D 5
			logent("BAD SEQ", "HANDSHAKE FAILED");
			systat(Rmtname, Stattype[7], Stattext[7]);
E 5
I 5
D 7
			logent("BAD SEQ", "HANDSHAKE FAIL");
E 7
I 7
			logent("BAD SEQ", "FAILED HANDSHAKE");
E 7
			US_SST(us_s_hand);
			systat(Rmtname, SS_BADSEQ, Stattext[SS_BADSEQ]);
#ifdef GNXSEQ
E 5
			ulkseq();
I 5
#endif GNXSEQ
E 5
			goto next;
		}
		if (strcmp(&msg[1], "OK") != SAME)  {
D 5
			logent(&msg[1], "HANDSHAKE FAILED");
E 5
I 5
D 7
			logent(&msg[1], "HANDSHAKE FAIL");
E 7
I 7
			logent(&msg[1], "FAILED HANDSHAKE");
E 7
			US_SST(us_s_hand);
#ifdef GNXSEQ
E 5
			ulkseq();
I 5
#endif GNXSEQ
			systat(Rmtname, SS_INPROGRESS,
				strcmp(&msg[1], "CB") == SAME?
D 7
				"AWAITING CALLBACK": "HANDSHAKE FAIL");
E 7
I 7
				"AWAITING CALLBACK": "FAILED HANDSHAKE");
E 7
E 5
			goto next;
		}
I 5
#ifdef GNXSEQ
E 5
		cmtseq();
I 5
#endif GNXSEQ
E 5
	}
D 5
	DEBUG(1, " Rmtname %s, ", Rmtname);
E 5
I 5
	DEBUG(1, "Rmtname %s, ", Rmtname);
E 5
	DEBUG(1, "Role %s,  ", Role ? "MASTER" : "SLAVE");
	DEBUG(1, "Ifn - %d, ", Ifn);
	DEBUG(1, "Loginuser - %s\n", Loginuser);
I 17
	setproctitle("%s: %s", Rmtname, Role ? "MASTER" : "SLAVE");
E 17

I 11
	ttyn = ttyname(Ifn);

E 11
D 15
	alarm(MAXMSGTIME);
E 15
I 15
	alarm(IsTcpIp?MAXMSGTIME*4:MAXMSGTIME);
E 15
D 6
	if (setjmp(Sjbuf))
E 6
I 6
	if (ret=setjmp(Sjbuf))
E 6
		goto Failure;
	ret = startup(Role);
	alarm(0);
	if (ret != SUCCESS) {
I 5
D 17
		logent("startup", _FAILED);
E 17
I 17
		logent("(startup)", _FAILED);
E 17
E 5
Failure:
D 5
		logent("startup", "FAILED");
		systat(Rmtname, SS_FAIL, "STARTUP");
E 5
I 5
		US_SST(us_s_start);
D 6
		systat(Rmtname, SS_FAIL, "STARTUP FAILED");
E 6
I 6
		systat(Rmtname, SS_FAIL, ret > 0 ? "CONVERSATION FAILED" :
			"STARTUP FAILED");
E 6
E 5
		goto next;
D 5
	}
	else {
E 5
I 5
	} else {
E 5
D 11
		logent("startup", "OK");
E 11
I 11
D 15
		if (ttyn != NULL) {
			char startupmsg[BUFSIZ];
			extern int linebaudrate;
			sprintf(startupmsg, "startup %s %d baud", &ttyn[5], 
				linebaudrate);
			logent(startupmsg, "OK");
		} else
			logent("startup", "OK");
E 15
I 15
		char smsg[BUFSIZ], gmsg[10], pmsg[20], bpsmsg[20];
		extern char UsingProtocol;
		extern int linebaudrate;
		if (ttyn != NULL) 
			sprintf(bpsmsg, " %s %d bps", &ttyn[5], linebaudrate);
		else
			bpsmsg[0] = '\0';
		if (UsingProtocol != 'g')
			sprintf(pmsg, " %c protocol", UsingProtocol);
		else
			pmsg[0] = '\0';
		if (MaxGrade != '\177')
			sprintf(gmsg, " grade %c", MaxGrade);
		else
			gmsg[0] = '\0';
D 17
		sprintf(smsg, "startup%s%s%s", bpsmsg, pmsg, gmsg);
E 17
I 17
		sprintf(smsg, "(startup%s%s%s)", bpsmsg, pmsg, gmsg);
E 17
		logent(smsg, "OK");
E 15
E 11
I 5
		US_SST(us_s_gress);
I 15
		StartTime = Now.time;
E 15
E 5
		systat(Rmtname, SS_INPROGRESS, "TALKING");
		ret = cntrl(Role, wkpre);
		DEBUG(1, "cntrl - %d\n", ret);
		signal(SIGINT, SIG_IGN);
		signal(SIGHUP, SIG_IGN);
		signal(SIGALRM, timeout);
I 15
D 17
		sprintf(smsg, "conversation complete %ld sent %ld received",
E 17
I 17
		sprintf(smsg, "(conversation complete %ld sent %ld received)",
E 17
			Bytes_Sent, Bytes_Received);
E 15
D 5
		if (ret == 0) {
E 5
I 5
		if (ret == SUCCESS) {
E 5
D 15
			logent("conversation complete", "OK");
E 15
I 15
			logent(smsg, "OK");
E 15
I 5
			US_SST(us_s_ok);
E 5
			rmstat(Rmtname);

I 5
		} else {
D 15
			logent("conversation complete", _FAILED);
E 15
I 15
			logent(smsg, _FAILED);
E 15
			US_SST(us_s_cf);
			systat(Rmtname, SS_FAIL, "CONVERSATION FAILED");
E 5
		}
D 5
		else {
			logent("conversation complete", "FAILED");
			systat(Rmtname, SS_FAIL, "CONVERSATION");
		}
E 5
D 15
		alarm(MAXMSGTIME);
E 15
I 15
		alarm(IsTcpIp?MAXMSGTIME*4:MAXMSGTIME);
E 15
D 5
		omsg('O', "OOOOO", Ofn);
E 5
		DEBUG(4, "send OO %d,", ret);
		if (!setjmp(Sjbuf)) {
			for (;;) {
				omsg('O', "OOOOO", Ofn);
				ret = imsg(msg, Ifn);
				if (ret != 0)
					break;
				if (msg[0] == 'O')
					break;
			}
		}
		alarm(0);
D 5
		clsacu();	/* rti!trt: is this needed? */
E 5
I 5
		clsacu();
		rmlock(CNULL);
I 15
	
E 15
E 5
	}
next:
	if (!onesys) {
		goto loop;
	}
	cleanup(0);
}

D 5
#ifndef	SYSIII
E 5
I 5
#ifndef	USG
E 5
struct sgttyb Hupvec;
#endif

D 11
/***
 *	cleanup(code)	cleanup and exit with "code" status
 *	int code;
E 11
I 11
/*
 *	cleanup and exit with "code" status
E 11
 */
D 11

E 11
cleanup(code)
register int code;
{
D 7
	register int ret;
E 7
D 11
	register char *ttyn;
I 5
	char bfr[BUFSIZ];
	struct stat sbuf;
E 5

E 11
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	rmlock(CNULL);
I 11
	sleep(5);			/* Wait for any pending output	  */
E 11
	clsacu();
	logcls();
	if (Role == SLAVE) {
D 5
		if (!Unet) {
#ifdef	SYSIII
E 5
I 5
		if (!IsTcpIp) {
#ifdef USG
E 5
			Savettyb.c_cflag |= HUPCL;
D 7
			ret = ioctl(0, TCSETA, &Savettyb);
E 7
I 7
			(void) ioctl(0, TCSETA, &Savettyb);
E 7
D 5
#endif
#ifndef	SYSIII
			/* rti!trt:  use more robust hang up sequence */
E 5
I 5
#else !USG
E 5
D 7
			ret = ioctl(0, TIOCHPCL, STBNULL);
E 7
I 7
			(void) ioctl(0, TIOCHPCL, STBNULL);
E 7
I 6
#ifdef TIOCSDTR
D 7
			ret = ioctl(0, TIOCCDTR, STBNULL);
E 7
I 7
			(void) ioctl(0, TIOCCDTR, STBNULL);
E 7
			sleep(2);
D 7
			ret = ioctl(0, TIOCSDTR, STBNULL);
E 7
I 7
			(void) ioctl(0, TIOCSDTR, STBNULL);
E 7
#else !TIOCSDTR
E 6
D 7
			ret = ioctl(0, TIOCGETP, &Hupvec);
E 7
I 7
			(void) ioctl(0, TIOCGETP, &Hupvec);
E 7
I 6
D 11
#endif !TIOCSDTR
E 11
E 6
			Hupvec.sg_ispeed = B0;
			Hupvec.sg_ospeed = B0;
D 7
			ret = ioctl(0, TIOCSETP, &Hupvec);
E 7
I 7
			(void) ioctl(0, TIOCSETP, &Hupvec);
I 11
#endif !TIOCSDTR
E 11
E 7
			sleep(2);
D 7
			ret = ioctl(0, TIOCSETP, &Savettyb);
E 7
I 7
			(void) ioctl(0, TIOCSETP, &Savettyb);
E 7
D 5
#endif
E 5
I 5
			/* make *sure* exclusive access is off */
D 7
			ret = ioctl(0, TIOCNXCL, STBNULL);
E 7
I 7
			(void) ioctl(0, TIOCNXCL, STBNULL);
E 7
#endif !USG
E 5
D 7
			DEBUG(4, "ret ioctl - %d\n", ret);
E 7
		}
D 11
		ttyn = ttyname(Ifn);
E 11
		if (ttyn != NULL)
			chmod(ttyn, 0600);
	}
	if (Ofn != -1) {
		if (Role == MASTER)
			write(Ofn, EOTMSG, strlen(EOTMSG));
		close(Ifn);
		close(Ofn);
	}
I 6
#ifdef DIALINOUT
	/* reenable logins on dialout */
	reenable();
#endif DIALINOUT
E 6
D 5
	DEBUG(1, "exit code %d\n", code);
E 5
	if (code == 0)
		xuuxqt();
I 5
	else
		DEBUG(1, "exit code %d\n", code);
D 11
	sprintf(bfr, "%s/%s", RMTDEBUG, Rmtname);
	if (stat(bfr, &sbuf) == 0 && sbuf.st_size == 0)
		unlink(bfr);
	sprintf(bfr, "%s/%d", RMTDEBUG, getpid());
	unlink(bfr);
E 11
I 11
	setdebug (DBG_CLEAN);
I 15
	do_connect_accounting();
E 15
E 11
E 5
	exit(code);
}

I 15
do_connect_accounting()
{
I 16
#ifdef DO_CONNECT_ACCOUNTING
E 16
	register FILE *fp;
	struct tm *localtime();
	register struct tm *tm;
	int flags;

	if (StartTime == 0)
		return;

D 16
#ifdef DO_CONNECT_ACCOUNTING
	fp = fopen("/usr/spool/uucp/CONNECT", "a");
	ASSERT(fp != NULL, "Can't open CONNECT file", Rmtname, errno);
E 16
I 16
	fp = fopen(DO_CONNECT_ACCOUNTING, "a");
	if (fp == NULL) {
		syslog(LOG_ALERT, "fopen(%s) failed: %m",DO_CONNECT_ACCOUNTING);
		cleanup(FAIL);
	}
E 16

	tm = localtime(&StartTime);
#ifdef F_SETFL
	flags = fcntl(fileno(fp), F_GETFL, 0);
	fcntl(fileno(fp), F_SETFL, flags|O_APPEND);
#endif
#ifdef USG
	fprintf(fp,"%s %d %d%.2d%.2d %.2d%.2d %d %ld %s %ld %ld\n",
#else /* V7 */
	fprintf(fp,"%s %d %d%02d%02d %02d%02d %d %ld %s %ld %ld\n",
#endif /* V7 */
		Rmtname, InitialRole, tm->tm_year, tm->tm_mon + 1,
		tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_wday,
		(Now.time - StartTime + 59) / 60, 
		ttyn == NULL ? "ttyp0" : &ttyn[5],
			Bytes_Sent, Bytes_Received);
	fclose(fp);
#endif /* DO_CONNECT_ACCOUNTING */
}

E 15
D 11
/***
 *	onintr(inter)	interrupt - remove locks and exit
E 11
I 11
/*
 *	on interrupt - remove locks and exit
E 11
 */

onintr(inter)
register int inter;
{
D 15
	char str[30];
E 15
I 15
	char str[BUFSIZ];
E 15
	signal(inter, SIG_IGN);
D 17
	sprintf(str, "SIGNAL %d", inter);
E 17
I 17
	sprintf(str, "(SIGNAL %d)", inter);
E 17
	logent(str, "CAUGHT");
I 2
D 5
	systat(Rmtname, SS_FAIL, str);
E 5
I 5
	US_SST(us_s_intr);
D 6
	if (*Rmtname && strcmp(Rmtname, Myname))
E 6
I 6
D 7
	if (*Rmtname && strncmp(Rmtname, Myname, 7))
E 7
I 7
	if (*Rmtname && strncmp(Rmtname, Myname, MAXBASENAME))
E 7
E 6
		systat(Rmtname, SS_FAIL, str);
I 15
D 17
	sprintf(str, "conversation complete %ld sent %ld received",
E 17
I 17
	sprintf(str, "(conversation complete %ld sent %ld received)",
E 17
		Bytes_Sent, Bytes_Received);
	logent(str, _FAILED);
E 15
	if (inter == SIGPIPE && !onesys)
		longjmp(Pipebuf, 1);
E 5
E 2
	cleanup(inter);
}

D 5
/* changed to single version of intrEXIT.  Is this okay? rti!trt */
intrEXIT(signo)
int signo;
{
I 3
#ifdef	SIGIO
	/* if using 4.2 signal mechanism, must unblock all signal handlers */
	sigsetmask(0);
#endif
E 3
	signal(signo, SIG_DFL);
	setgid(getgid());
	setuid(getuid());
	abort();
}
E 5
/*
 * Catch a special signal
 * (SIGFPE, ugh), and toggle debugging between 0 and 30.
 * Handy for looking in on long running uucicos.
 */
D 5
setdebug()
E 5
I 5
D 11
setdebug(code)
int code;
E 11
I 11
dbg_signal()
E 11
E 5
{
D 5
	if (Debug < 30)
		Debug = 30;
	else
		Debug = 0;
E 5
I 5
D 11
	char buf[BUFSIZ];

D 7
	if (!StdErrIsTty) {
E 7
I 7
	if (code) {
		if (Debug == 0)
			Debug = 30;
		else
			Debug = 0;
	}
	if (Debug && !StdErrIsTty) {
E 7
		sprintf(buf,"%s/%s", RMTDEBUG, Rmtname);
		unlink(buf);
		freopen(buf, "w", stderr);
#ifdef BSD4_2
		setlinebuf(stderr);
#else  !BSD4_2
		setbuf(stderr, NULL);
#endif !BSD4_2
	}
E 11
I 11
	Debug = (Debug == 0) ? 30 : 0;
	setdebug(DBG_PERM);
	if (Debug > 0)
		logent("Signal Enabled", "DEBUG");
E 11
D 7
	if (code) {
		if (Debug == 0)
			Debug = 30;
		else
			Debug = 0;
	}
E 7
E 5
}


D 11
/***
 *	fixmode(tty)	fix kill/echo/raw on line
E 11
I 11
/*
 * Check debugging requests, and open RMTDEBUG audit file if necessary. If an
 * audit file is needed, the parm argument indicates how to create the file:
E 11
 *
D 11
 *	return codes:  none
E 11
I 11
 *	DBG_TEMP  - Open a temporary file, with filename = RMTDEBUG/pid.
 *	DBG_PERM  - Open a permanent audit file, filename = RMTDEBUG/Rmtname.
 *		    If a temp file already exists, it is mv'ed to be permanent.
 *	DBG_CLEAN - Cleanup; unlink temp files.
 *
 * Restrictions - this code can only cope with one open debug file at a time.
 * Each call creates a new file; if an old one of the same name exists it will
 * be overwritten.
E 11
 */
D 11

fixmode(tty)
register int tty;
E 11
I 11
setdebug(parm)
int parm;
E 11
{
D 5
#ifdef	SYSIII
E 5
I 5
D 11
#ifdef	USG
E 5
	struct termio ttbuf;
#endif
D 5
#ifndef	SYSIII
E 5
I 5
#ifndef	USG
E 5
	struct sgttyb ttbuf;
#endif
E 11
I 11
	char buf[BUFSIZ];		/* Buffer for building filenames     */
	static char *temp = NULL;	/* Ptr to temporary file name	     */
	static int auditopen = 0;	/* Set to 1 when we open a file	     */
	struct stat stbuf;		/* File status buffer		     */
E 11
D 7
	register int ret;
E 7

D 5
	if (Unet)
E 5
I 5
D 11
	if (IsTcpIp)
E 11
I 11
	/*
	 * If movement or cleanup of a temp file is indicated, we do it no
	 * matter what.
	 */
	if (temp != CNULL && parm == DBG_PERM) {
		sprintf(buf, "%s/%s", RMTDEBUG, Rmtname);
		unlink(buf);
		if (link(temp, buf) != 0) {
			Debug = 0;
D 16
			assert("RMTDEBUG LINK FAIL", temp, errno);
			cleanup(1);
E 16
I 16
			syslog(LOG_ERR, "RMTDEBUG link(%s,%s) failed: %m",
				temp, buf);
			cleanup(FAIL);
E 16
		}
		parm = DBG_CLEAN;
	}
	if (parm == DBG_CLEAN) {
		if (temp != CNULL) {
			unlink(temp);
			free(temp);
			temp = CNULL;
		}
E 11
E 5
		return;
D 5
#ifdef	SYSIII
	ioctl(tty, TCGETA, &ttbuf);
E 5
I 5
D 11
#ifdef	USG
D 7
	ret = ioctl(tty, TCGETA, &ttbuf);
E 7
I 7
	ioctl(tty, TCGETA, &ttbuf);
E 7
E 5
	ttbuf.c_iflag = ttbuf.c_oflag = ttbuf.c_lflag = (ushort)0;
	ttbuf.c_cflag &= (CBAUD);
	ttbuf.c_cflag |= (CS8|CREAD);
	ttbuf.c_cc[VMIN] = 6;
	ttbuf.c_cc[VTIME] = 1;
D 7
	ret = ioctl(tty, TCSETA, &ttbuf);
E 7
I 7
	ioctl(tty, TCSETA, &ttbuf);
E 7
#endif
D 5
#ifndef	SYSIII
E 5
I 5
#ifndef	USG
E 5
	ioctl(tty, TIOCGETP, &ttbuf);
	ttbuf.sg_flags = (ANYP | RAW);
D 7
	ret = ioctl(tty, TIOCSETP, &ttbuf);
E 7
I 7
	ioctl(tty, TIOCSETP, &ttbuf);
E 7
#endif
D 5
	ASSERT(ret >= 0, "STTY FAILED", "", ret);
#ifndef	SYSIII
	ioctl(tty, TIOCEXCL, STBNULL);
E 5
I 5
D 7
/*	ASSERT(ret >= 0, "STTY FAILED", CNULL, ret); */
E 7
#ifndef	USG
D 7
	ret = ioctl(tty, TIOCEXCL, STBNULL);
E 7
I 7
	ioctl(tty, TIOCEXCL, STBNULL);
E 7
E 5
#endif
}
E 11
I 11
	}
E 11

I 11
	if (Debug == 0)
		return;		/* Gotta be in debug to come here.   */
E 11

I 11
	/*
	 * If we haven't opened a file already, we can just return if it's
	 * alright to use the stderr we came in with. We can if:
	 *
	 *	Role == MASTER, and Stderr is a regular file, a TTY or a pipe.
	 *
	 * Caution: Detecting when stderr is a pipe is tricky, because the 4.2
	 * man page for fstat(2) disagrees with reality, and System V leaves it
	 * undefined, which means different implementations act differently.
	 */
	if (!auditopen && Role == MASTER) {
		if (isatty(fileno(stderr)))
			return;
		else if (fstat(fileno(stderr), &stbuf) == 0) {
#ifdef USG
			/* Is Regular File or Fifo   */
			if ((stbuf.st_mode & 0060000) == 0)
				return;
#else !USG
#ifdef BSD4_2
					/* Is Regular File */
			if ((stbuf.st_mode & S_IFMT) == S_IFREG ||
			    stbuf.st_mode == 0)		/* Is a pipe */
				return;
#else !BSD4_2
					 /* Is Regular File or Pipe  */
			if ((stbuf.st_mode & S_IFMT) == S_IFREG)
				return;
#endif BSD4_2
#endif USG
		}
	}

	/*
	 * We need RMTDEBUG directory to do auditing. If the file doesn't exist,
	 * then we forget about debugging; if it exists but has improper owner-
	 * ship or modes, we gripe about it in ERRLOG. 
	 */
	if (stat(RMTDEBUG, &stbuf) != SUCCESS) {
		Debug = 0;
		return;
	}
	if ((geteuid() != stbuf.st_uid) ||	  	/* We must own it    */
	    ((stbuf.st_mode & 0170700) != 040700)) {	/* Directory, rwx    */
		Debug = 0;
D 16
		assert("INVALID RMTDEBUG DIRECTORY:", RMTDEBUG, stbuf.st_mode);
E 16
I 16
		syslog(LOG_ERR, "%s: invalid directory mode: %o", RMTDEBUG,
			stbuf.st_mode);
E 16
		return;
	}

	if (parm == DBG_TEMP) {
		sprintf(buf, "%s/%d", RMTDEBUG, getpid());
		temp = malloc(strlen (buf) + 1);
		if (temp == CNULL) {
			Debug = 0;
D 16
			assert("RMTDEBUG MALLOC ERROR:", temp, errno);
			cleanup(1);
E 16
I 16
			syslog(LOG_ERR, "RMTDEBUG malloc failed: %m");
			cleanup(FAIL);
E 16
		}
		strcpy(temp, buf);
	} else
		sprintf(buf, "%s/%s", RMTDEBUG, Rmtname);

	unlink(buf);
	if (freopen(buf, "w", stderr) != stderr) {
		Debug = 0;
D 16
		assert("FAILED RMTDEBUG FILE OPEN:", buf, errno);
		cleanup(1);
E 16
I 16
		syslog(LOG_ERR, "RMTDEBUG freopen(%s) failed: %m", buf);
		cleanup(FAIL);
E 16
	}
	setbuf(stderr, CNULL);
	auditopen = 1;
}

E 11
D 7
/***
E 7
I 7
/*
E 7
D 11
 *	timeout()	catch SIGALRM routine
E 11
I 11
 *	catch SIGALRM routine
E 11
 */
D 11

E 11
timeout()
{
D 7
	logent(Rmtname, "TIMEOUT");
I 2
D 5
	systat(Rmtname, SS_FAIL, "TIMEOUT");
E 5
I 5
D 6
	if (*Rmtname && strcmp(Rmtname, Myname)) {
E 6
I 6
	if (*Rmtname && strncmp(Rmtname, Myname, 7)) {
E 6
		US_SST(us_s_tmot);
		systat(Rmtname, SS_FAIL, "TIMEOUT");
E 7
I 7
	extern int HaveSentHup;
	if (!HaveSentHup) {
		logent(Rmtname, "TIMEOUT");
		if (*Rmtname && strncmp(Rmtname, Myname, MAXBASENAME)) {
			US_SST(us_s_tmot);
			systat(Rmtname, SS_FAIL, "TIMEOUT");
		}
E 7
	}
E 5
E 2
	longjmp(Sjbuf, 1);
}

static char *
pskip(p)
register char *p;
{
D 5
	while( *p && *p != ' ' )
E 5
I 5
	while(*p && *p != ' ')
E 5
		++p;
D 5
	if( *p ) *p++ = 0;
	return(p);
E 5
I 5
D 7
	if(*p)
E 7
I 7
	while(*p && *p == ' ')
E 7
		*p++ = 0;
	return p;
I 17
}

/*
 * clobber argv so ps will show what we're doing.
 * stolen from sendmail
 */
/*VARARGS1*/
setproctitle(fmt, a, b, c)
char *fmt;
{
#ifdef SETPROCTITLE
	register char *p;
	register int i;
	extern char **Argv;
	extern char *LastArgv;
	char buf[BUFSIZ];

	(void) sprintf(buf, fmt, a, b, c);

	/* make ps print "(sendmail)" */
	p = Argv[0];
	*p++ = '-';

	i = strlen(buf);
	if (i > LastArgv - p - 2) {
		i = LastArgv - p - 2;
		buf[i] = '\0';
	}
	(void) strcpy(p, buf);
	p += i;
	while (p < LastArgv)
		*p++ = ' ';
#endif SETPROCTITLE
E 17
E 5
}
E 1
