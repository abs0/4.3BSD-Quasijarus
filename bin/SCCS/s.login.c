h39083
s 00000/00001/00582
d D 5.21 03/03/22 19:30:38 msokolov 64 63
c don't reset local tty modes, we need to keep PASS8 from getty
e
s 00009/00001/00574
d D 5.20 87/10/01 14:00:41 bostic 63 61
c '-' may not start login name; bug report 4.3BSD/bin/85
e
s 00007/00001/00574
d R 5.20 87/10/01 13:38:36 bostic 62 61
c '-' may not start login name; bug report 4.3BSD/bin/85
e
s 00047/00019/00528
d D 5.19 87/06/27 17:14:17 karels 61 60
c add -f for datakit and others
e
s 00001/00001/00546
d D 5.18 87/06/16 14:03:11 bostic 60 59
c timeout to 5 minutes
e
s 00009/00057/00538
d D 5.17 87/03/11 12:00:22 bostic 59 58
c setenv moved to C library
e
s 00008/00000/00587
d D 5.16 86/11/10 21:48:46 karels 58 57
c shorten hostname if local
e
s 00005/00005/00582
d D 5.15 86/04/12 15:50:48 karels 57 55
c write => tty
e
s 00004/00004/00583
d R 5.15 86/04/12 15:48:36 karels 56 55
c write => tty
e
s 00007/00006/00580
d D 5.14 86/03/13 21:16:02 mckusick 55 54
c if lookup of group "write" fails, use user's /etc/passwd entry as before
e
s 00020/00002/00566
d D 5.13 86/03/13 19:23:05 mckusick 54 53
c setgid to group "write" so that terminals need not be world writable
e
s 00002/00000/00566
d D 5.12 86/03/05 18:07:38 karels 53 52
c if resetting special chars, let's do them all
e
s 00000/00034/00566
d D 5.11 86/01/09 14:54:45 mckusick 52 51
c delete trash for distribution
e
s 00001/00001/00599
d D 5.10 85/11/08 16:49:57 bloom 51 50
c check for null string as well as null pointer
e
s 00022/00005/00578
d D 5.9 85/10/18 15:12:41 mckusick 50 49
c give "from host" information for network login failures
e
s 00003/00002/00580
d D 5.8 85/10/10 17:54:10 bloom 49 47
c ask for login name second time around on rlogin
e
s 00001/00001/00581
d R 5.8 85/09/24 12:03:19 bloom 48 47
c ask for login name after first time around on remote login
e
s 00008/00006/00574
d D 5.7 85/09/19 18:41:52 karels 47 46
c don't clobber term, path if -p (but always set user, home and shell)
e
s 00002/00004/00578
d D 5.6 85/09/17 22:52:29 mckusick 46 45
c overloading of rflag causes trouble for window sizes
e
s 00004/00004/00578
d D 5.5 85/09/17 19:14:25 eric 45 44
c facilities in syslog
e
s 00036/00024/00546
d D 5.4 85/09/17 19:02:27 mckusick 44 43
c do not set window size from rlogin as rlogind promises to handle it;
c missed one file descriptor (from serge);
c passing through window size with speed is isolated as TRASH
e
s 00026/00067/00544
d D 5.3 85/09/12 16:17:40 bloom 43 42
c allow -p and a network arg, use ruserok instead of builtin, break rflag into
c two pieces
e
s 00001/00001/00610
d D 5.2 85/05/24 15:53:48 mckusick 42 41
c ignore ``quotas not compiled in'' error message from quota
e
s 00014/00002/00597
d D 5.1 85/04/30 14:57:06 dist 41 40
c Add copyright
e
s 00001/00001/00598
d D 4.37 85/04/02 08:18:45 karels 40 39
c off by one
e
s 00131/00036/00468
d D 4.36 85/04/01 21:25:00 sam 39 38
c allow getty to propagate environment; setup window sizes both locally 
c and for remote logins; hack -h flag to allow telnetd to set window sizes 
c instead of login; miscellaneous cleanups; NOTE change to rlogin protocol 
c encourages passing window size from remote machine
e
s 00006/00008/00498
d D 4.35 85/01/08 20:23:07 serge 38 36
c specify if mail in the mbox is new
e
s 00001/00000/00506
d R 4.35 84/12/17 13:30:04 ralph 37 36
c set umask here until switchover (get it from init).
e
s 00046/00089/00460
d D 4.34 84/05/07 11:42:51 root 36 35
c uses new getttyent(3) routines.
e
s 00004/00002/00545
d D 4.33 83/09/02 14:07:23 edward 35 32
c in getloginname, use lusername to getpw so it can be null terminated.
e
s 00007/00005/00542
d R 4.33 83/09/02 13:42:37 edward 34 32
c use lusername[] as buffer in getloginname()
c so we can null terminate it for getpwnam.
e
s 00002/00043/00504
d R 4.33 83/07/06 00:32:39 sam 33 32
c no more ttytype
e
s 00004/00003/00543
d D 4.32 83/06/30 14:36:40 sam 32 31
c fix logerr
e
s 00007/00004/00539
d D 4.31 83/06/30 12:58:39 sam 31 30
c pwd was undefined when user was unknown for remote login
e
s 00010/00008/00533
d D 4.30 83/06/13 02:43:44 sam 30 29
c way back yonder...
e
s 00001/00001/00540
d D 4.29 83/06/10 23:13:51 sam 29 28
c needs NMOUNT for quotas
e
s 00000/00001/00541
d D 4.28 83/05/28 16:29:15 sam 28 27
c no more need for #define ne QUOTA
e
s 00002/00003/00540
d D 4.27 83/05/24 16:03:06 sam 27 26
c no more hostname stuff
e
s 00008/00000/00535
d D 4.26 83/05/23 01:02:37 sam 26 25
c logging on define LOGERR now
e
s 00223/00156/00312
d D 4.25 83/05/23 00:04:36 sam 25 24
c major changes; make mainline login loop understandable; factor 
c out remote login protocol into separate routines; replace nice calls with 
c setpriority calls; add -h option so telnetd and friends can supply host name 
c for stuffing into the utmp file
e
s 00021/00001/00447
d D 4.24 83/05/22 19:23:42 sam 24 23
c stuff for quotas
e
s 00004/00009/00444
d D 4.23 83/05/19 02:21:53 leres 23 22
c /etc/securetty is checked, even when root logins across the net.
e
s 00001/00004/00452
d D 4.22 83/04/18 23:31:31 leres 22 21
c Removed "No such user" message to prevent probing from remote machines.
e
s 00036/00016/00420
d D 4.21 83/03/31 14:01:50 leres 21 20
c Tightened security in login. The .rhosts file must now be owned
c by either the user or root and may not be a symbolic link.
e
s 00011/00024/00425
d D 4.20 82/12/21 15:44:33 sam 20 19
c use new ioctl's; fix tty mode typo; handle > 8 remote login names
e
s 00001/00001/00448
d D 4.19 82/11/14 16:32:41 sam 19 18
c convert to 4.1c sys calls and directory layout
e
s 00001/00000/00448
d D 4.18 82/06/27 10:27:10 root 18 17
c chmod the tty to repair previous biff/mesg
e
s 00004/00001/00444
d D 4.17 82/05/19 22:09:26 mckusick 17 16
c fix group initialization for eight character login names
e
s 00006/00006/00439
d D 4.16 82/04/03 19:32:42 wnj 16 15
c root only from /.rhosts
e
s 00039/00056/00406
d D 4.15 82/03/27 22:16:33 wnj 15 14
c many changes relating to remote login; but fix with updating lastlog
e
s 00094/00053/00368
d D 4.14 82/03/15 04:04:39 root 14 13
c machine independent
e
s 00003/00003/00418
d D 4.13 82/02/28 23:45:47 wnj 13 12
c groups stuff
e
s 00071/00015/00350
d D 4.12 82/02/28 21:26:31 wnj 12 11
c add login -r
e
s 00001/00000/00364
d D 4.11 81/07/05 21:48:25 root 11 10
c ignore SIGTSTP before exec() so /bin/sh's wont die on ^Z under ttynew
e
s 00181/00094/00183
d D 4.10 81/02/28 22:58:37 wnj 10 9
c new shutdown style
e
s 00007/00001/00270
d D 4.9 81/01/11 15:35:18 wnj 9 8
c umask defaults to 2 for csr group members
e
s 00003/00003/00268
d D 4.8 81/01/10 17:09:59 root 8 7
c I changed the directory you log into if your own directory is not there to
c the root directory -- presotto
e
s 00004/00000/00267
d D 4.7 80/12/10 20:01:30 bill 7 6
c If login directory not available, log in with pwd->pw_dir=="/tmp"
e
s 00003/00000/00264
d D 4.6 80/11/11 10:10:08 bill 6 5
c #ifdef ERNIE around root login restrictions
e
s 00002/00002/00262
d D 4.5 80/10/22 10:23:17 mark 5 4
c fixed non-vax bug where lseek was being passed an int for lastlog.
e
s 00009/00001/00255
d D 4.4 80/10/19 10:45:53 bill 4 3
c restore lost code
e
s 00001/00002/00255
d D 4.3 80/10/19 02:05:01 bill 3 2
c remove local chars
e
s 00021/00010/00236
d D 4.2 80/10/10 00:50:08 bill 2 1
c reset all chars; line discipline=NTTY for csh users
e
s 00246/00000/00000
d D 4.1 80/10/01 17:27:21 bill 1 0
c date and time created 80/10/01 17:27:21 by bill
e
u
U
f b 
t
T
I 41
/*
D 61
 * Copyright (c) 1980 Regents of the University of California.
E 61
I 61
 * Copyright (c) 1980,1987 Regents of the University of California.
E 61
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 41
I 24
#ifndef lint
E 24
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 10
static	char *sccsid = "%W% (Berkeley) %G%";
E 10
I 10
D 12
static	char *sccsid = "%W% (Berkeley) %E%";
E 12
I 12
D 14
static	char *sccsid = "%W% (Berkeley) %I%";
E 14
I 14
D 25
static	char *sccsid = "%W% %E%";
E 25
I 25
D 41
static	char *sccsid = "%W% (Berkeley) %E%";
E 25
I 24
#endif
E 41
I 41
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 41

E 24
E 14
E 12
E 10
E 2
/*
 * login [ name ]
I 12
D 25
 * login -r
E 25
I 25
D 61
 * login -r hostname (for rlogind)
 * login -h hostname (for telnetd, etc.)
E 61
I 61
 * login -r hostname	(for rlogind)
 * login -h hostname	(for telnetd, etc.)
 * login -f name	(for pre-authenticated login: datakit, xterm, etc.)
E 61
E 25
I 14
D 15
 * login -r [ rhost ]
E 15
E 14
E 12
 */

D 29
#include <sys/types.h>
E 29
I 29
#include <sys/param.h>
E 29
I 25
D 28
#define	QUOTA
E 28
#include <sys/quota.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
I 36
#include <sys/file.h>
E 36

E 25
#include <sgtty.h>
#include <utmp.h>
#include <signal.h>
#include <pwd.h>
#include <stdio.h>
D 25
#include <sys/stat.h>
E 25
#include <lastlog.h>
I 24
D 25
#define	QUOTA
#include <sys/quota.h>
E 25
#include <errno.h>
I 36
#include <ttyent.h>
#include <syslog.h>
I 54
#include <grp.h>
E 54
E 36
E 24
I 6
D 14
#include <whoami.h>
E 6
D 10
#define SCPYN(a, b)	strncpy(a, b, sizeof(a))
E 10
I 10
#ifdef	UNAME
#include <sys/utsname.h>
#endif
E 14
E 10

I 54
D 55
#define WRITENAME       "write"         /* name of group to own ttys */
#define WRITEGID        write_gid()     /* gid that owns all ttys */
E 55
I 55
D 57
#define WRITENAME	"write"		/* name of group to own ttys */
#define WRITEGID(gid)	write_gid(gid)	/* gid that owns all ttys */
E 57
I 57
#define TTYGRPNAME	"tty"		/* name of group to own ttys */
#define TTYGID(gid)	tty_gid(gid)	/* gid that owns all ttys */
E 57
E 55

E 54
I 36
#define	SCMPN(a, b)	strncmp(a, b, sizeof(a))
E 36
I 10
#define	SCPYN(a, b)	strncpy(a, b, sizeof(a))

E 10
D 14
#define NMAX sizeof(utmp.ut_name)
#define LMAX sizeof(utmp.ut_line)
E 14
I 14
#define NMAX	sizeof(utmp.ut_name)
I 50
#define HMAX	sizeof(utmp.ut_host)
E 50
D 25
#define LMAX	sizeof(utmp.ut_line)
E 25
E 14

D 10
char	user[20];
E 10
I 10
#define	FALSE	0
#define	TRUE	-1

char	nolog[] =	"/etc/nologin";
char	qlog[]  =	".hushlogin";
D 36
char	securetty[] =	"/etc/securetty";
E 36
E 10
char	maildir[30] =	"/usr/spool/mail/";
char	lastlog[] =	"/usr/adm/lastlog";
D 20
struct	passwd nouser = {"", "nope"};
E 20
I 20
struct	passwd nouser = {"", "nope", -1, -1, -1, "", "", "", "" };
E 20
struct	sgttyb ttyb;
struct	utmp utmp;
char	minusnam[16] = "-";
I 39
D 59
char	*envinit[] = { 0 };		/* now set by setenv calls */
E 59
I 59
char	*envinit[1];			/* now set by setenv calls */
E 59
E 39
I 25
/*
 * This bounds the time given to login.  We initialize it here
 * so it can be patched on machines where it's too small.
 */
D 60
int	timeout = 60;
E 60
I 60
int	timeout = 300;
E 60
E 25
I 12

E 12
D 39
char	homedir[64] = "HOME=";
char	shell[64] = "SHELL=";
char	term[64] = "TERM=";
D 10
char	*envinit[] = {homedir, shell, "PATH=:/usr/ucb:/bin:/usr/bin", term, user,0};
E 10
I 10
char	user[20] = "USER=";
E 39
I 39
char	term[64];
E 39
D 12
char	*envinit[] = {homedir, shell, "PATH=:/usr/ucb:/bin:/usr/bin", term, user, 0};
E 10
struct	passwd *pwd;
E 12
I 12
D 25
char	*speeds[] =
    { "0", "50", "75", "110", "134", "150", "200", "300",
      "600", "1200", "1800", "2400", "4800", "9600", "19200", "38400" };
#define	NSPEEDS	(sizeof (speeds) / sizeof (speeds[0]))
E 25
E 12

I 12
D 39
char	*envinit[] =
D 25
    {homedir, shell, "PATH=:/usr/ucb:/bin:/usr/bin", term, user, 0};
E 25
I 25
    { homedir, shell, "PATH=:/usr/ucb:/bin:/usr/bin", term, user, 0 };
E 25

E 39
struct	passwd *pwd;
E 12
D 36
struct	passwd *getpwnam();
E 36
D 12
char	*strcat();
E 12
I 12
D 39
char	*strcat(), *rindex(), *index();
E 39
I 39
D 59
char	*strcat(), *rindex(), *index(), *malloc(), *realloc();
E 59
I 59
char	*strcat(), *rindex(), *index();
E 59
E 39
E 12
D 36
int	setpwent();
E 36
I 25
int	timedout();
E 25
char	*ttyname();
char	*crypt();
char	*getpass();
D 23
char	*rindex();
E 23
char	*stypeof();
D 59
extern	char **environ;
E 59
I 24
extern	int errno;
E 24

I 2
D 20
#define	CTRL(c)	('c'&037)
#define	CERASE	'#'
#define	CEOT	CTRL(d)
#define	CKILL	'@'
#define	CQUIT	034		/* FS, cntl shift L */
#define	CINTR	0177		/* DEL */
#define	CSTOP	CTRL(s)
#define	CSTART	CTRL(q)
#define	CBRK	0377
struct	tchars tc = {
	CINTR, CQUIT, CSTART, CSTOP, CEOT, CBRK
E 20
I 20
D 30
struct	ttychars tc = {
	CERASE,	CKILL,	CINTR,	CQUIT,	CSTART,
	CSTOP,	CEOF,	CBRK,	CSUSP,	CDSUSP,
	CRPRNT,	CFLUSH,	CWERASE,CLNEXT
E 30
I 30
struct	tchars tc = {
	CINTR, CQUIT, CSTART, CSTOP, CEOT, CBRK
E 30
E 20
};
I 30
struct	ltchars ltc = {
	CSUSP, CDSUSP, CRPRNT, CFLUSH, CWERASE, CLNEXT
};
E 30
I 10
D 14
#ifdef	TIOCLSET
E 14
E 10
D 20
struct	ltchars ltc = {
D 3
	CTRL(z), CTRL(y), CTRL(r), CTRL(o), CTRL(w), CTRL(v), CTRL(h), CTRL(u),
	CTRL(c)
E 3
I 3
	CTRL(z), CTRL(y), CTRL(r), CTRL(o), CTRL(w), CTRL(v)
E 3
};
E 20
I 10
D 14
#endif
E 14
E 10

I 39
struct winsize win = { 0, 0, 0, 0 };

E 39
I 12
int	rflag;
I 43
int	usererr = -1;
E 43
D 14
char	rusername[NMAX+1];
E 14
I 14
char	rusername[NMAX+1], lusername[NMAX+1];
E 14
char	rpassword[NMAX+1];
I 17
char	name[NMAX+1];
I 58
char	me[MAXHOSTNAMELEN];
E 58
E 17
I 14
char	*rhost;
E 14

E 12
E 2
main(argc, argv)
D 25
char **argv;
E 25
I 25
	char *argv[];
E 25
{
I 59
	extern	char **environ;
E 59
	register char *namep;
D 25
	int t, f, c;
I 10
	int invalid;
	int quietlog;
	int i;
E 25
I 25
D 36
	int t, f, c, i;
E 36
I 36
D 39
	int t, f, c;
E 39
I 39
D 61
	int pflag = 0, hflag = 0, t, f, c;
E 61
I 61
	int pflag = 0, hflag = 0, fflag = 0, t, f, c;
E 61
E 39
E 36
	int invalid, quietlog;
E 25
	FILE *nlfd;
E 10
D 36
	char *ttyn;
E 36
I 36
	char *ttyn, *tty;
E 36
D 10
	int ldisc = 0;
E 10
I 10
D 12
	int	ldisc = 0;
E 12
I 12
D 13
	int ldisc = 0;
	int zero = 0;
E 13
I 13
D 14
	int	ldisc = 0;
E 13
E 12
#ifdef	UNAME
	struct utsname uts;
#endif
E 14
I 14
D 39
	int ldisc = 0, zero = 0;
E 39
I 39
	int ldisc = 0, zero = 0, i;
D 59
	char **envnew;
E 59
I 58
	char *p, *domain, *index();
E 58
E 39
D 25
	FILE *hostf; int first = 1;
E 25
E 14
E 10

D 25
	alarm(60);
E 25
I 25
	signal(SIGALRM, timedout);
	alarm(timeout);
E 25
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
D 25
	nice(-100);
	nice(20);
	nice(0);
E 25
I 25
	setpriority(PRIO_PROCESS, 0, 0);
E 25
I 24
	quota(Q_SETUID, 0, 0, 0);
E 24
I 12
D 15
	if (argc > 0 && !strcmp(argv[1], "-r")) {
E 15
I 15
D 25
	if (argc > 1 && !strcmp(argv[1], "-r")) {
E 15
		rflag++;
D 14
		getstr(rusername, sizeof (rusername), "Username");
		getstr(rpassword, sizeof (rpassword), "Password");
E 14
I 14
D 15
		if (argc > 1)
			rhost = argv[2];
E 15
I 15
		rhost = argv[2];
E 15
		argc = 1;
D 15
		if (rhost) {
			getstr(rusername, sizeof (rusername), "remuser");
			getstr(lusername, sizeof (lusername), "locuser");
		} else {
			getstr(lusername, sizeof (lusername), "Username");
			getstr(rpassword, sizeof (rpassword), "Password");
		}
E 15
I 15
		getstr(rusername, sizeof (rusername), "remuser");
		getstr(lusername, sizeof (lusername), "locuser");
E 15
E 14
		getstr(term+5, sizeof(term)-5, "Terminal type");
I 14
D 15
		if (rhost == 0)
			goto normal;
		if (getuid()) {
			rflag = 0;
			goto normal;
		}
E 15
I 15
		if (getuid())
			goto abnormal;
E 15
		setpwent();
		pwd = getpwnam(lusername);
I 15
		endpwent();
E 15
D 22
		if (pwd == NULL) {
D 15
			fprintf(stderr, "Login incorrect.\n");
			exit(1);
E 15
I 15
			if (strcmp(rusername, lusername))
				printf("%s: No such user\r\n", lusername);
E 22
I 22
		if (pwd == NULL)
E 22
			goto abnormal;
E 15
D 22
		}
E 22
D 15
		endpwent();
E 15
D 16
		hostf = fopen("/etc/hosts.equiv", "r");
E 16
I 16
		hostf = pwd->pw_uid ? fopen("/etc/hosts.equiv", "r") : 0;
E 16
	again:
		if (hostf) {
D 21
		  char ahost[32];
		  while (fgets(ahost, sizeof (ahost), hostf)) {
			char *user;
			if (index(ahost, '\n'))
				*index(ahost, '\n') = 0;
			user = index(ahost, ' ');
			if (user)
				*user++ = 0;
			if (!strcmp(rhost, ahost) &&
D 15
			    !strcmp(rusername, user ? user : lusername))
E 15
I 15
			    !strcmp(rusername, user ? user : lusername)) {
				fclose(hostf);
E 15
				goto normal;
E 21
I 21
			char ahost[32];

		        while (fgets(ahost, sizeof (ahost), hostf)) {
				char *user;

D 23
				if (index(ahost, '\n'))
					*index(ahost, '\n') = 0;
				user = index(ahost, ' ');
				if (user)
					*user++ = 0;
E 23
I 23
				if ((user = index(ahost, '\n')) != 0)
					*user++ = '\0';
				if ((user = index(ahost, ' ')) != 0)
					*user++ = '\0';
E 23
				if (!strcmp(rhost, ahost) &&
				    !strcmp(rusername, user ?
				    user : lusername)) {
					fclose(hostf);
					goto normal;
				}
E 21
I 15
			}
E 15
D 21
		  }
		  fclose(hostf);
E 21
I 21
			fclose(hostf);
E 25
I 25
	/*
I 39
	 * -p is used by getty to tell login not to destroy the environment
E 39
	 * -r is used by rlogind to cause the autologin protocol;
I 61
 	 * -f is used to skip a second login authentication 
E 61
	 * -h is used by other servers to pass the name of the
	 * remote host to login so that it may be placed in utmp and wtmp
	 */
I 58
	(void) gethostname(me, sizeof(me));
	domain = index(me, '.');
E 58
D 43
	if (argc > 1) {
E 43
I 43
	while (argc > 1) {
E 43
		if (strcmp(argv[1], "-r") == 0) {
D 43
			rflag = doremotelogin(argv[2]);
E 43
I 43
D 61
			if (rflag || hflag) {
				printf("Only one of -r and -h allowed\n");
E 61
I 61
			if (rflag || hflag || fflag) {
				printf("Other options not allowed with -r\n");
E 61
				exit(1);
			}
I 63
			if (argv[2] == 0)
				exit(1);
E 63
			rflag = 1;
			usererr = doremotelogin(argv[2]);
I 58
			if ((p = index(argv[2], '.')) && strcmp(p, domain) == 0)
				*p = 0;
E 58
E 43
			SCPYN(utmp.ut_host, argv[2]);
D 43
			argc = 0;
E 43
I 43
			argc -= 2;
			argv += 2;
			continue;
E 43
E 25
E 21
		}
D 25
		if (first == 1) {
I 21
			char *rhosts = ".rhosts";
			struct stat sbuf;

E 21
			first = 0;
			if (chdir(pwd->pw_dir) < 0)
				goto again;
D 21
			hostf = fopen(".rhosts", "r");
			goto again;
E 21
I 21
			if (lstat(rhosts, &sbuf) < 0)
				goto again;
			if ((sbuf.st_mode & S_IFMT) == S_IFLNK) {
				printf("login: .rhosts is a soft link.\r\n");
D 23
			        fclose(hostf);
E 23
				goto abnormal;
			}
			hostf = fopen(rhosts, "r");
			fstat(fileno(hostf), &sbuf);
			if ((int) sbuf.st_uid != pwd->pw_uid &&
			    (int) sbuf.st_uid != 0) {
				printf("login: Bad .rhosts ownership.\r\n");
			        fclose(hostf);
				goto abnormal;
			}
		goto again;
E 25
I 25
D 61
		if (strcmp(argv[1], "-h") == 0 && getuid() == 0) {
I 43
			if (rflag || hflag) {
				printf("Only one of -r and -h allowed\n");
E 61
I 61
		if (strcmp(argv[1], "-h") == 0) {
			if (getuid() == 0) {
				if (rflag || hflag) {
				    printf("Only one of -r and -h allowed\n");
				    exit(1);
				}
				hflag = 1;
				if ((p = index(argv[2], '.')) &&
				    strcmp(p, domain) == 0)
					*p = 0;
				SCPYN(utmp.ut_host, argv[2]);
			}
			argc -= 2;
			argv += 2;
			continue;
		}
		if (strcmp(argv[1], "-f") == 0 && argc > 2) {
			if (rflag) {
				printf("Only one of -r and -f allowed\n");
E 61
				exit(1);
			}
E 43
I 39
D 61
			hflag = 1;
I 58
			if ((p = index(argv[2], '.')) && strcmp(p, domain) == 0)
				*p = 0;
E 58
E 39
			SCPYN(utmp.ut_host, argv[2]);
E 61
I 61
			fflag = 1;
			SCPYN(utmp.ut_name, argv[2]);
E 61
D 43
			argc = 0;
E 43
I 43
			argc -= 2;
			argv += 2;
			continue;
E 43
E 25
E 21
		}
I 39
		if (strcmp(argv[1], "-p") == 0) {
			argc--;
			argv++;
			pflag = 1;
I 43
			continue;
E 43
		}
I 43
		break;
E 43
E 39
I 15
D 25
abnormal:
E 15
		rhost = 0;
		rflag = -1;
E 25
E 14
	}
E 12
I 10
D 14
#ifdef	TIOCLSET
E 10
I 2
D 4
	ioctl(0, TIOCSETD, &ldisc);
E 4
E 2
D 12
	ioctl(0, TIOCLSET, 0);
E 12
I 12
D 13
	ioctl(0, TIOCLSET, &zero);
E 13
I 13
	ioctl(0, TIOCLSET, 0);
E 13
E 12
I 10
#endif
E 14
I 14
D 25
normal:
E 25
D 20
	ioctl(0, TIOCLSET, &zero);
E 20
I 20
D 30
	ioctl(0, TIOCLSET, &zero);	/* XXX */
E 30
I 30
D 64
	ioctl(0, TIOCLSET, &zero);
E 64
E 30
E 20
E 14
E 10
I 4
	ioctl(0, TIOCNXCL, 0);
I 15
	ioctl(0, FIONBIO, &zero);
	ioctl(0, FIOASYNC, &zero);
E 15
E 4
D 2
	ioctl(0, TIOCNXCL, 0);
E 2
D 20
	gtty(0, &ttyb);
E 20
I 20
D 30
	ioctl(0, TIOCGETP, &ttyb);	/* XXX */
E 30
I 30
	ioctl(0, TIOCGETP, &ttyb);
E 30
E 20
I 12
D 25
	if (rflag) {
		char *cp = index(term, '/');
		if (cp) {
			int i;
			*cp++ = 0;
			for (i = 0; i < NSPEEDS; i++)
				if (!strcmp(speeds[i], cp)) {
					ttyb.sg_ispeed = ttyb.sg_ospeed = i;
					break;
				}
		}
		ttyb.sg_flags = ECHO|CRMOD|ANYP|XTABS;
	}
E 25
I 25
	/*
	 * If talking to an rlogin process,
	 * propagate the terminal type and
	 * baud rate across the network.
	 */
	if (rflag)
		doremoteterm(term, &ttyb);
I 53
	ttyb.sg_erase = CERASE;
	ttyb.sg_kill = CKILL;
E 53
E 25
I 14
D 15
	if (rflag == -1)
		rflag = 0;
E 15
E 14
E 12
D 10
	ttyb.sg_erase = '#';
	ttyb.sg_kill = '@';
E 10
I 10
D 20
	ttyb.sg_erase = CERASE;
	ttyb.sg_kill = CKILL;
E 10
	stty(0, &ttyb);
I 2
	ioctl(0, TIOCSETC, &tc);
I 10
D 14
#ifdef	TIOCLSET
E 14
E 10
	ioctl(0, TIOCSLTC, &ltc);
E 20
I 20
D 30
	ioctl(0, TIOCSETP, &ttyb);	/* XXX */
	ioctl(0, TIOCCSET, &tc);
E 30
I 30
	ioctl(0, TIOCSLTC, &ltc);
	ioctl(0, TIOCSETC, &tc);
	ioctl(0, TIOCSETP, &ttyb);
E 30
E 20
I 10
D 14
#endif
E 14
E 10
E 2
D 25
	for (t=3; t<20; t++)
E 25
I 25
D 44
	for (t = getdtablesize(); t > 3; t--)
E 44
I 44
	for (t = getdtablesize(); t > 2; t--)
E 44
E 25
		close(t);
	ttyn = ttyname(0);
D 10
	if (ttyn==0)
E 10
I 10
D 36
	if (ttyn==(char *)0)
E 36
I 36
D 51
	if (ttyn == (char *)0)
E 51
I 51
	if (ttyn == (char *)0 || *ttyn == '\0')
E 51
E 36
E 10
		ttyn = "/dev/tty??";
I 36
	tty = rindex(ttyn, '/');
	if (tty == NULL)
		tty = ttyn;
	else
		tty++;
D 39
	openlog("login", 0, 0);
E 39
I 39
D 45
	openlog("login", LOG_ODELAY, 0);
E 45
I 45
	openlog("login", LOG_ODELAY, LOG_AUTH);
E 45
E 39
	t = 0;
I 49
	invalid = FALSE;
E 49
E 36
D 12

E 12
D 10
    loop:
I 4
	ldisc = 0;
	ioctl(0, TIOCSETD, &ldisc);
E 4
D 2
	ldisc = 0;
	ioctl(0, TIOCSETD, &ldisc);
E 2
	SCPYN(utmp.ut_name, "");
	if (argc>1) {
		SCPYN(utmp.ut_name, argv[1]);
		argc = 0;
	}
	while (utmp.ut_name[0] == '\0') {
		namep = utmp.ut_name;
		printf("login: ");
		while ((c = getchar()) != '\n') {
			if(c == ' ')
				c = '_';
			if (c == EOF)
				exit(0);
			if (namep < utmp.ut_name+NMAX)
				*namep++ = c;
		}
	}
	setpwent();
	if ((pwd = getpwnam(utmp.ut_name)) == NULL)
		pwd = &nouser;
	endpwent();
I 4
	if (!strcmp(pwd->pw_shell, "/bin/csh")) {
		ldisc = NTTYDISC;
E 10
I 10
	do {
		ldisc = 0;
E 10
		ioctl(0, TIOCSETD, &ldisc);
D 10
	}
E 4
D 2
	if (!strcmp(pwd->pw_shell, "/bin/csh")) {
		ldisc = NTTYDISC;
		ioctl(0, TIOCSETD, &ldisc);
	}
E 2
	if (*pwd->pw_passwd != '\0') {
I 4
		nice(-4);
E 4
D 2
		nice(-4);
E 2
		namep = crypt(getpass("Password:"),pwd->pw_passwd);
I 4
		nice(4);
E 4
D 2
		nice(4);
E 2
		if (strcmp(namep, pwd->pw_passwd)) {
bad:
E 10
I 10
D 49
		invalid = FALSE;
E 49
D 61
		SCPYN(utmp.ut_name, "");
E 61
I 61
		if (fflag == 0)
			SCPYN(utmp.ut_name, "");
E 61
D 25
		if (argc>1) {
E 25
I 25
		/*
		 * Name specified, take it.
		 */
		if (argc > 1) {
E 25
			SCPYN(utmp.ut_name, argv[1]);
			argc = 0;
		}
I 25
		/*
		 * If remote login take given name,
		 * otherwise prompt user for something.
		 */
E 25
I 12
D 15
		if (rflag)
E 15
I 15
D 46
		if (rflag) {
E 46
I 46
D 49
		if (rflag)
E 49
I 49
		if (rflag && !invalid)
E 49
E 46
E 15
D 14
			strcpy(utmp.ut_name, rusername);
E 14
I 14
D 20
			strcpy(utmp.ut_name, lusername);
E 20
I 20
			SCPYN(utmp.ut_name, lusername);
I 25
D 43
			/* autologin failed, prompt for passwd */
E 25
E 20
E 14
D 15
		else
E 15
I 15
			if (rflag == -1)
E 43
I 43
D 46
			if (usererr == -1)
E 43
				rflag = 0;
D 25
		} else
E 15
E 12
D 14
		while (utmp.ut_name[0] == '\0') {
			namep = utmp.ut_name;
D 12
#ifdef	UNAME
			if (uname(&uts) != -1)
				printf("%s login: ", uts.nodename);
			else
#endif
				printf("login: ");
E 12
I 12
			printf("%s login: ", sysname);
E 12
			while ((c = getchar()) != '\n') {
				if (c == ' ')
					c = '_';
				if (c == EOF)
					exit(0);
				if (namep < utmp.ut_name+NMAX)
					*namep++ = c;
E 14
I 14
			while (utmp.ut_name[0] == '\0') {
				namep = utmp.ut_name;
				{ char hostname[32];
				  gethostname(hostname, sizeof (hostname));
				  printf("%s login: ", hostname); }
				while ((c = getchar()) != '\n') {
					if (c == ' ')
						c = '_';
					if (c == EOF)
						exit(0);
					if (namep < utmp.ut_name+NMAX)
						*namep++ = c;
				}
E 14
			}
I 14
		if (rhost == 0) {
			setpwent();
			if ((pwd = getpwnam(utmp.ut_name)) == NULL)
				pwd = &nouser;
			endpwent();
E 25
I 25
D 31
		} else {
E 31
I 31
		} else
E 46
I 46
D 63
		else
E 63
I 63
		else {
E 63
E 46
E 31
			getloginname(&utmp);
I 63
			if (utmp.ut_name[0] == '-') {
				puts("login names may not start with '-'.");
				invalid = TRUE;
				continue;
			}
		}
E 63
I 49
		invalid = FALSE;
E 49
E 25
E 14
D 31
		}
E 31
D 14
		setpwent();
		if ((pwd = getpwnam(utmp.ut_name)) == NULL)
			pwd = &nouser;
		endpwent();
E 14
		if (!strcmp(pwd->pw_shell, "/bin/csh")) {
			ldisc = NTTYDISC;
			ioctl(0, TIOCSETD, &ldisc);
		}
I 61
		if (fflag) {
			int uid = getuid();

			if (uid != 0 && uid != pwd->pw_uid)
				fflag = 0;
			/*
			 * Disallow automatic login for root.
			 */
			if (pwd->pw_uid == 0)
				fflag = 0;
		}
E 61
D 14
		if (*pwd->pw_passwd != '\0') {
I 12
			char *pp;
E 12
			nice(-4);
D 12
			namep = crypt(getpass("Password:"),pwd->pw_passwd);
E 12
I 12
			if (rflag == 0)
				pp = getpass("Password:");
			else
				pp = rpassword;
			namep = crypt(pp,pwd->pw_passwd);
E 12
			nice(4);
			if (strcmp(namep, pwd->pw_passwd))
				invalid = TRUE;
E 14
I 14
D 25
		if (rhost == 0) {
			if (*pwd->pw_passwd != '\0') {
				char *pp;
				nice(-4);
				if (rflag == 0)
					pp = getpass("Password:");
				else
					pp = rpassword;
				namep = crypt(pp,pwd->pw_passwd);
				nice(4);
				if (strcmp(namep, pwd->pw_passwd))
					invalid = TRUE;
			}
E 25
I 25
		/*
		 * If no remote login authentication and
		 * a password exists for this user, prompt
		 * for one and verify it.
		 */
D 43
		if (!rflag && *pwd->pw_passwd != '\0') {
E 43
I 43
D 61
		if (usererr == -1 && *pwd->pw_passwd != '\0') {
E 61
I 61
		if (usererr == -1 && fflag == 0 && *pwd->pw_passwd != '\0') {
E 61
E 43
			char *pp;

			setpriority(PRIO_PROCESS, 0, -4);
			pp = getpass("Password:");
			namep = crypt(pp, pwd->pw_passwd);
			setpriority(PRIO_PROCESS, 0, 0);
			if (strcmp(namep, pwd->pw_passwd))
				invalid = TRUE;
E 25
E 14
		}
I 25
		/*
		 * If user not super-user, check for logins disabled.
		 */
E 25
		if (pwd->pw_uid != 0 && (nlfd = fopen(nolog, "r")) > 0) {
D 25
			/* logins are disabled except for root */
E 25
			while ((c = getc(nlfd)) != EOF)
				putchar(c);
			fflush(stdout);
			sleep(5);
			exit(0);
		}
I 25
		/*
		 * If valid so far and root is logging in,
		 * see if root logins on this terminal are permitted.
		 */
E 25
D 36
		if (!invalid && pwd->pw_uid == 0 &&
		    !rootterm(ttyn+sizeof("/dev/")-1)) {
D 15
			FILE *console = fopen("/dev/console", "w");
			if (console != NULL) {
				fprintf(console, "\r\nROOT LOGIN REFUSED %s\r\n"
				    , ttyn+sizeof("/dev/")-1
				);
				fclose(console);
			}
E 15
I 15
			logerr("ROOT LOGIN REFUSED %s",
			    ttyn+sizeof("/dev/")-1);
E 36
I 36
		if (!invalid && pwd->pw_uid == 0 && !rootterm(tty)) {
D 39
			syslog(LOG_INFO, "ROOT LOGIN REFUSED %s", tty);
E 39
I 39
D 45
			syslog(LOG_SECURITY, "ROOT LOGIN REFUSED %s", tty);
E 45
I 45
D 50
			syslog(LOG_CRIT, "ROOT LOGIN REFUSED %s", tty);
E 50
I 50
			if (utmp.ut_host[0])
				syslog(LOG_CRIT,
				    "ROOT LOGIN REFUSED ON %s FROM %.*s",
				    tty, HMAX, utmp.ut_host);
			else
				syslog(LOG_CRIT,
				    "ROOT LOGIN REFUSED ON %s", tty);
E 50
E 45
E 39
E 36
E 15
			invalid = TRUE;
		}
		if (invalid) {
E 10
			printf("Login incorrect\n");
D 10
			if (ttyn[LMAX] == 'd') {
E 10
I 10
D 15
			if (ttyn[sizeof("/dev/tty")-1] == 'd') {
E 10
				FILE *console = fopen("/dev/console", "w");
				if (console != NULL) {
D 10
					fprintf(console, "\r\nBADDIALUP %s %s\r\n", ttyn+5, utmp.ut_name);
E 10
I 10
					fprintf(console, "\r\nBADDIALUP %s %s\r\n"
					    , ttyn+sizeof("/dev/")-1
					    , utmp.ut_name);
E 10
					fclose(console);
				}
			}
E 15
I 15
D 36
			if (ttyn[sizeof("/dev/tty")-1] == 'd')
D 32
				logerr("BADDIALUP %s %s\n",
E 32
I 32
				logerr("BADDIALUP %s %s",
E 32
				    ttyn+sizeof("/dev/")-1, utmp.ut_name);
E 36
I 36
			if (++t >= 5) {
D 39
				syslog(LOG_INFO,
E 39
I 39
D 45
				syslog(LOG_SECURITY,
E 45
I 45
D 50
				syslog(LOG_CRIT,
E 45
E 39
				    "REPEATED LOGIN FAILURES %s, %s",
					tty, utmp.ut_name);
E 50
I 50
				if (utmp.ut_host[0])
D 61
					syslog(LOG_CRIT,
					    "REPEATED LOGIN FAILURES ON %s FROM %.*s, %.*s",
E 61
I 61
					syslog(LOG_ERR,
			    "REPEATED LOGIN FAILURES ON %s FROM %.*s, %.*s",
E 61
					    tty, HMAX, utmp.ut_host,
					    NMAX, utmp.ut_name);
				else
D 61
					syslog(LOG_CRIT,
					    "REPEATED LOGIN FAILURES ON %s, %.*s",
E 61
I 61
					syslog(LOG_ERR,
				    "REPEATED LOGIN FAILURES ON %s, %.*s",
E 61
						tty, NMAX, utmp.ut_name);
E 50
				ioctl(0, TIOCHPCL, (struct sgttyb *) 0);
D 39
				close(0);
				close(1);
				close(2);
E 39
I 39
				close(0), close(1), close(2);
E 39
				sleep(10);
				exit(1);
			}
E 36
E 15
D 10
			goto loop;
E 10
		}
D 10
	}
	sprintf(user, "USER=%.*s", NMAX, pwd->pw_name);
I 6
#ifdef ERNIE
E 6
	if (pwd->pw_uid == 0 && ttyn[5] != 'c')
		goto bad;
I 6
#endif
E 6
	if (ttyn[LMAX] == 'd') {
		FILE *console = fopen("/dev/console", "w");
		if (console != NULL) {
			fprintf(console, "\r\nDIALUP %s %s\r\n", ttyn+5, pwd->pw_name);
			fclose(console);
E 10
I 10
		if (*pwd->pw_shell == '\0')
			pwd->pw_shell = "/bin/sh";
D 36
		i = strlen(pwd->pw_shell);
E 36
		if (chdir(pwd->pw_dir) < 0 && !invalid ) {
			if (chdir("/") < 0) {
				printf("No directory!\n");
				invalid = TRUE;
			} else {
D 25
				printf("No directory!  Logging in with home=/\n");
E 25
I 25
				printf("No directory! %s\n",
				   "Logging in with home=/");
E 25
				pwd->pw_dir = "/";
			}
E 10
		}
I 25
		/*
		 * Remote login invalid must have been because
		 * of a restriction of some sort, no extra chances.
		 */
E 25
I 12
D 43
		if (rflag && invalid)
E 43
I 43
		if (!usererr && invalid)
E 43
			exit(1);
E 12
D 10
	}
	if((f = open(lastlog, 2)) >= 0) {
		struct lastlog ll;
E 10
I 10
	} while (invalid);
I 25
/* committed to login turn off timeout */
	alarm(0);
E 25
E 10

I 12
D 24

E 24
I 24
D 42
	if (quota(Q_SETUID, pwd->pw_uid, 0, 0) < 0) {
E 42
I 42
	if (quota(Q_SETUID, pwd->pw_uid, 0, 0) < 0 && errno != EINVAL) {
E 42
		if (errno == EUSERS)
			printf("%s.\n%s.\n",
			   "Too many users logged on already",
			   "Try again later");
		else if (errno == EPROCLIM)
			printf("You have too many processes running.\n");
		else
D 38
			perror("setuid");
E 38
I 38
			perror("quota (Q_SETUID)");
E 38
		sleep(5);
		exit(0);
	}
E 24
E 12
D 5
		lseek(f, pwd->pw_uid * sizeof (struct lastlog), 0);
E 5
I 5
D 10
		lseek(f, (long) pwd->pw_uid * sizeof (struct lastlog), 0);
E 5
		if (read(f, (char *) &ll, sizeof ll) == sizeof ll && ll.ll_time != 0) {
			register char *ep = (char *) ctime(&ll.ll_time);
			printf("Last login: ");
			ep[24 - 5] = 0;
			printf("%s on %.*s\n", ep, LMAX, ll.ll_line);
		}
D 5
		lseek(f, pwd->pw_uid * sizeof (struct lastlog), 0);
E 5
I 5
		lseek(f, (long) pwd->pw_uid * sizeof (struct lastlog), 0);
E 5
		time(&ll.ll_time);
		strcpyn(ll.ll_line, ttyn+5, LMAX);
		write(f, (char *) &ll, sizeof ll);
		close(f);
	}
	if(chdir(pwd->pw_dir) < 0) {
I 7
D 8
	    printf("Logging with home=/tmp\n");
	    pwd->pw_dir = "/tmp";
	    if(chdir("/tmp") < 0) {
E 8
I 8
	    printf("Logging with home=/\n");
	    pwd->pw_dir = "/";
	    if(chdir("/") < 0) {
E 8
E 7
		printf("No directory\n");
		goto loop;
I 7
	    }
E 7
	}
E 10
	time(&utmp.ut_time);
	t = ttyslot();
D 25
	if (t>0 && (f = open("/etc/utmp", 1)) >= 0) {
E 25
I 25
D 36
	if (t > 0 && (f = open("/etc/utmp", 1)) >= 0) {
E 36
I 36
	if (t > 0 && (f = open("/etc/utmp", O_WRONLY)) >= 0) {
E 36
E 25
		lseek(f, (long)(t*sizeof(utmp)), 0);
D 36
		SCPYN(utmp.ut_line, rindex(ttyn, '/')+1);
E 36
I 36
		SCPYN(utmp.ut_line, tty);
E 36
		write(f, (char *)&utmp, sizeof(utmp));
		close(f);
	}
D 25
	if (t>0 && (f = open("/usr/adm/wtmp", 1)) >= 0) {
E 25
I 25
D 36
	if (t > 0 && (f = open("/usr/adm/wtmp", 1)) >= 0) {
E 25
		lseek(f, 0L, 2);
E 36
I 36
	if ((f = open("/usr/adm/wtmp", O_WRONLY|O_APPEND)) >= 0) {
E 36
		write(f, (char *)&utmp, sizeof(utmp));
		close(f);
	}
I 10
D 15
	quietlog = FALSE;
E 15
I 15
D 25
	quietlog = 0;
E 15
	if (access(qlog, 0) == 0)
D 15
		quietlog = TRUE;
	if ( !quietlog && (f = open(lastlog, 2)) >= 0 ) {
E 15
I 15
		quietlog = 1;
E 25
I 25
D 36
	quietlog = access(qlog, 0) == 0;
E 25
	if ((f = open(lastlog, 2)) >= 0) {
E 36
I 36
	quietlog = access(qlog, F_OK) == 0;
	if ((f = open(lastlog, O_RDWR)) >= 0) {
E 36
E 15
		struct lastlog ll;

		lseek(f, (long)pwd->pw_uid * sizeof (struct lastlog), 0);
		if (read(f, (char *) &ll, sizeof ll) == sizeof ll &&
D 25
		    ll.ll_time != 0) {
I 15
			if (quietlog == 0)
E 15
			printf("Last login: %.*s on %.*s\n"
			    , 24-5
			    , (char *) ctime(&ll.ll_time)
			    , sizeof(ll.ll_line)
			    , ll.ll_line
			);
E 25
I 25
		    ll.ll_time != 0 && !quietlog) {
			printf("Last login: %.*s ",
			    24-5, (char *)ctime(&ll.ll_time));
			if (*ll.ll_host != '\0')
				printf("from %.*s\n",
				    sizeof (ll.ll_host), ll.ll_host);
			else
				printf("on %.*s\n",
				    sizeof (ll.ll_line), ll.ll_line);
E 25
		}
		lseek(f, (long)pwd->pw_uid * sizeof (struct lastlog), 0);
		time(&ll.ll_time);
D 36
		SCPYN(ll.ll_line, rindex(ttyn, '/')+1);
E 36
I 36
		SCPYN(ll.ll_line, tty);
E 36
I 25
		SCPYN(ll.ll_host, utmp.ut_host);
E 25
		write(f, (char *) &ll, sizeof ll);
		close(f);
	}
E 10
D 54
	chown(ttyn, pwd->pw_uid, pwd->pw_gid);
E 54
I 54
D 55
	chown(ttyn, pwd->pw_uid, WRITEGID);
E 55
I 55
D 57
	chown(ttyn, pwd->pw_uid, WRITEGID(pwd->pw_gid));
E 57
I 57
	chown(ttyn, pwd->pw_uid, TTYGID(pwd->pw_gid));
E 57
E 55
E 54
I 39
D 44
	if (!hflag)					/* XXX */
E 44
I 44
	if (!hflag && !rflag)					/* XXX */
E 44
		ioctl(0, TIOCSWINSZ, &win);
E 39
I 18
D 20
	chmod(ttyn, 622);
E 20
I 20
D 54
	chmod(ttyn, 0622);
E 54
I 54
	chmod(ttyn, 0620);
E 54
E 20
E 18
	setgid(pwd->pw_gid);
I 13
D 17
	inigrp(utmp.ut_name, pwd->pw_gid);
E 17
I 17
	strncpy(name, utmp.ut_name, NMAX);
	name[NMAX] = '\0';
D 19
	inigrp(name, pwd->pw_gid);
E 19
I 19
	initgroups(name, pwd->pw_gid);
I 24
	quota(Q_DOWARN, pwd->pw_uid, (dev_t)-1, 0);
E 24
E 19
E 17
E 13
	setuid(pwd->pw_uid);
I 59

E 59
D 10
	if (*pwd->pw_shell == '\0')
		pwd->pw_shell = "/bin/sh";
E 10
D 39
	environ = envinit;
	strncat(homedir, pwd->pw_dir, sizeof(homedir)-6);
	strncat(shell, pwd->pw_shell, sizeof(shell)-7);
D 12
	strncat(term, stypeof(ttyn), sizeof(term)-6);
E 12
I 12
D 15
	if (rflag == 0)
E 15
I 15
D 38
	if (term[strlen("TERM=")] == 0)
E 38
I 38
	if (term[sizeof("TERM=")-1] == 0)
E 38
E 15
D 36
		strncat(term, stypeof(ttyn), sizeof(term)-6);
E 36
I 36
		strncat(term, stypeof(tty), sizeof(term)-6);
E 36
E 12
I 10
	strncat(user, pwd->pw_name, sizeof(user)-6);
E 39
I 39
	/* destroy environment unless user has asked to preserve it */
	if (!pflag)
		environ = envinit;
D 59

	/* set up environment, this time without destruction */
	/* copy the environment before setenving */
	i = 0;
	while (environ[i] != NULL)
		i++;
	envnew = (char **) malloc(sizeof (char *) * (i + 1));
	for (; i >= 0; i--)
		envnew[i] = environ[i];
	environ = envnew;

D 47
	setenv("HOME=", pwd->pw_dir);
	setenv("SHELL=", pwd->pw_shell);
E 47
I 47
	setenv("HOME=", pwd->pw_dir, 1);
	setenv("SHELL=", pwd->pw_shell, 1);
E 59
I 59
	setenv("HOME", pwd->pw_dir, 1);
	setenv("SHELL", pwd->pw_shell, 1);
E 59
E 47
	if (term[0] == '\0')
		strncpy(term, stypeof(tty), sizeof(term));
D 47
	setenv("TERM=", term);
	setenv("USER=", pwd->pw_name);
	setenv("PATH=", ":/usr/ucb:/bin:/usr/bin");
E 47
I 47
D 59
	setenv("TERM=", term, 0);
	setenv("USER=", pwd->pw_name, 1);
	setenv("PATH=", ":/usr/ucb:/bin:/usr/bin", 0);
E 59
I 59
	setenv("TERM", term, 0);
	setenv("USER", pwd->pw_name, 1);
	setenv("PATH", ":/usr/ucb:/bin:/usr/bin", 0);
E 59
E 47

E 39
E 10
	if ((namep = rindex(pwd->pw_shell, '/')) == NULL)
		namep = pwd->pw_shell;
	else
		namep++;
	strcat(minusnam, namep);
D 25
	alarm(0);
E 25
D 9
	umask(022);
E 9
I 9
D 14
#ifdef ARPAVAX
D 10
	if (pwd->pw_gid == 31)
E 10
I 10
	if (pwd->pw_gid == 27)			/* UGLY ! */
E 10
		umask(2);
	else
D 10
#else
		umask(022);
E 10
#endif
E 9
D 10
	showmotd();
	strcat(maildir, pwd->pw_name);
	if(access(maildir,4)==0) {
		struct stat statb;
		stat(maildir, &statb);
		if (statb.st_size)
			printf("You have mail.\n");
E 10
I 10
		umask(022);
E 14
I 14
D 36
	umask(022);
E 14
D 15
	if (ttyn[sizeof("/dev/tty")-1] == 'd') {
		FILE *console = fopen("/dev/console", "w");
		if (console != NULL) {
			fprintf(console, "\r\nDIALUP %s %s\r\n"
			    , ttyn+sizeof("/dev/")-1
			    , pwd->pw_name
			);
			fclose(console);
		}
E 10
	}
I 10
	if ( !quietlog ) {
E 15
I 15
	if (ttyn[sizeof("/dev/tty")-1] == 'd')
D 32
		logerr("DIALUP %s %s\n", ttyn+sizeof("/dev/")-1, pwd->pw_name);
E 32
I 32
		logerr("DIALUP %s %s",
		    ttyn+sizeof("/dev/")-1, pwd->pw_name);
E 36
I 36
	if (tty[sizeof("tty")-1] == 'd')
D 39
		syslog(LOG_INFO, "DIALUP %s %s", tty, pwd->pw_name);
E 39
I 39
		syslog(LOG_INFO, "DIALUP %s, %s", tty, pwd->pw_name);
	if (pwd->pw_uid == 0)
D 45
		syslog(LOG_SECURITY, "ROOT LOGIN %s", tty);
E 45
I 45
D 50
		syslog(LOG_NOTICE, "ROOT LOGIN %s", tty);
E 50
I 50
		if (utmp.ut_host[0])
			syslog(LOG_NOTICE, "ROOT LOGIN %s FROM %.*s",
			    tty, HMAX, utmp.ut_host);
		else
			syslog(LOG_NOTICE, "ROOT LOGIN %s", tty);
E 50
E 45
E 39
E 36
E 32
	if (!quietlog) {
I 38
		struct stat st;
I 39

E 39
E 38
E 15
		showmotd();
		strcat(maildir, pwd->pw_name);
D 36
		if (access(maildir,4)==0) {
E 36
I 36
D 38
		if (access(maildir, R_OK) == 0) {
E 36
			struct stat statb;
			stat(maildir, &statb);
			if (statb.st_size)
				printf("You have mail.\n");
		}
E 38
I 38
		if (stat(maildir, &st) == 0 && st.st_size != 0)
			printf("You have %smail.\n",
D 39
				(st.st_mtime > st.st_atime) ? "new" : "");
E 39
I 39
				(st.st_mtime > st.st_atime) ? "new " : "");
E 39
E 38
	}
D 25
	
E 25
I 25
	signal(SIGALRM, SIG_DFL);
E 25
E 10
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
I 11
	signal(SIGTSTP, SIG_IGN);
E 11
	execlp(pwd->pw_shell, minusnam, 0);
I 10
	perror(pwd->pw_shell);
E 10
	printf("No shell\n");
	exit(0);
}

I 25
getloginname(up)
	register struct utmp *up;
{
	register char *namep;
D 27
	char hostname[32], c;
E 27
I 27
	char c;
E 27

D 27
	gethostname(hostname, sizeof (hostname));
E 27
	while (up->ut_name[0] == '\0') {
D 35
		namep = utmp.ut_name;
E 35
I 35
		namep = up->ut_name;
E 35
D 27
		printf("%s login: ", hostname);
E 27
I 27
		printf("login: ");
E 27
		while ((c = getchar()) != '\n') {
			if (c == ' ')
				c = '_';
			if (c == EOF)
				exit(0);
			if (namep < up->ut_name+NMAX)
				*namep++ = c;
		}
	}
I 35
	strncpy(lusername, up->ut_name, NMAX);
	lusername[NMAX] = 0;
E 35
D 36
	setpwent();
E 36
D 35
	if ((pwd = getpwnam(utmp.ut_name)) == NULL)
E 35
I 35
	if ((pwd = getpwnam(lusername)) == NULL)
E 35
		pwd = &nouser;
D 36
	endpwent();
E 36
}

timedout()
{

	printf("Login timed out after %d seconds\n", timeout);
	exit(0);
}

E 25
int	stopmotd;
catch()
{
I 16

E 16
	signal(SIGINT, SIG_IGN);
	stopmotd++;
}

I 10
D 16
/*
 * return true if OK for root to login on this terminal
 */
E 16
rootterm(tty)
D 16
	char	*tty;
E 16
I 16
	char *tty;
E 16
{
D 36
	register FILE *fd;
D 16
	char	buf[100];
E 16
I 16
	char buf[100];
E 36
I 36
	register struct ttyent *t;
E 36
E 16

I 16
D 23
	if (rflag)
		return(1);
E 23
E 16
D 36
	if ((fd = fopen(securetty, "r")) == NULL)
		return(1);
	while (fgets(buf, sizeof buf, fd) != NULL) {
		buf[strlen(buf)-1] = '\0';
		if (strcmp(tty, buf) == 0) {
			fclose(fd);
			return(1);
		}
E 36
I 36
	if ((t = getttynam(tty)) != NULL) {
		if (t->ty_status & TTY_SECURE)
			return (1);
E 36
	}
D 36
	fclose(fd);
	return(0);
E 36
I 36
	return (0);
E 36
}

E 10
showmotd()
{
	FILE *mf;
	register c;

	signal(SIGINT, catch);
D 10
	if((mf = fopen("/etc/motd","r")) != NULL) {
		while((c = getc(mf)) != EOF && stopmotd == 0)
E 10
I 10
D 36
	if ((mf = fopen("/etc/motd","r")) != NULL) {
E 36
I 36
	if ((mf = fopen("/etc/motd", "r")) != NULL) {
E 36
		while ((c = getc(mf)) != EOF && stopmotd == 0)
E 10
			putchar(c);
		fclose(mf);
	}
	signal(SIGINT, SIG_IGN);
}

I 10
#undef	UNKNOWN
E 10
#define UNKNOWN "su"

char *
stypeof(ttyid)
D 25
char	*ttyid;
E 25
I 25
	char *ttyid;
E 25
{
D 25
	static char	typebuf[16];
	char		buf[50];
	register FILE	*f;
	register char	*p, *t, *q;
E 25
I 25
D 36
	static char typebuf[16];
	char buf[50];
	register FILE *f;
	register char *p, *t, *q;
E 36
I 36
	register struct ttyent *t;
E 36
E 25

D 36
	if (ttyid == NULL)
E 36
I 36
	if (ttyid == NULL || (t = getttynam(ttyid)) == NULL)
E 36
		return (UNKNOWN);
D 36
	f = fopen("/etc/ttytype", "r");
	if (f == NULL)
		return (UNKNOWN);
	/* split off end of name */
	for (p = q = ttyid; *p != 0; p++)
		if (*p == '/')
			q = p + 1;

	/* scan the file */
D 25
	while (fgets(buf, sizeof buf, f) != NULL)
	{
D 10
		for (t=buf; *t!=' '; t++)
E 10
I 10
		for (t=buf; *t!=' ' && *t != '\t'; t++)
E 25
I 25
	while (fgets(buf, sizeof buf, f) != NULL) {
		for (t = buf; *t != ' ' && *t != '\t'; t++)
E 25
E 10
			;
		*t++ = 0;
I 10
		while (*t == ' ' || *t == '\t')
			t++;
E 10
D 25
		for (p=t; *p>' '; p++)
E 25
I 25
		for (p = t; *p > ' '; p++)
E 25
			;
		*p = 0;
D 25
		if (strcmp(q,t)==0) {
E 25
I 25
		if (strcmp(q,t) == 0) {
E 25
			strcpy(typebuf, buf);
			fclose(f);
			return (typebuf);
		}
	}
	fclose (f);
	return (UNKNOWN);
E 36
I 36
	return (t->ty_type);
E 36
I 12
}

I 25
doremotelogin(host)
	char *host;
{
D 43
	FILE *hostf;
	int first = 1;

E 43
	getstr(rusername, sizeof (rusername), "remuser");
	getstr(lusername, sizeof (lusername), "locuser");
D 39
	getstr(term+5, sizeof(term)-5, "Terminal type");
E 39
I 39
	getstr(term, sizeof(term), "Terminal type");
E 39
D 31
	if (getuid())
E 31
I 31
	if (getuid()) {
		pwd = &nouser;
E 31
D 43
		goto bad;
E 43
I 43
		return(-1);
E 43
I 31
	}
E 31
D 36
	setpwent();
E 36
	pwd = getpwnam(lusername);
D 36
	endpwent();
E 36
D 31
	if (pwd == NULL)
E 31
I 31
	if (pwd == NULL) {
		pwd = &nouser;
E 31
D 43
		goto bad;
E 43
I 43
		return(-1);
E 43
I 31
	}
E 31
D 43
	hostf = pwd->pw_uid ? fopen("/etc/hosts.equiv", "r") : 0;
again:
	if (hostf) {
		char ahost[32];

		while (fgets(ahost, sizeof (ahost), hostf)) {
I 39
			register char *p;
E 39
			char *user;

D 39
			if ((user = index(ahost, '\n')) != 0)
				*user++ = '\0';
			if ((user = index(ahost, ' ')) != 0)
				*user++ = '\0';
E 39
I 39
			p = ahost;
			while (*p != '\n' && *p != ' ' && *p != '\t' && *p != '\0')
				p++;
			if (*p == ' ' || *p == '\t') {
				*p++ = '\0';
				while (*p == ' ' || *p == '\t')
					p++;
				user = p;
				while (*p != '\n' && *p != ' ' && *p != '\t' && *p != '\0')
					p++;
			} else
				user = p;
			*p = '\0';
E 39
			if (!strcmp(host, ahost) &&
D 39
			    !strcmp(rusername, user ? user : lusername)) {
E 39
I 39
			    !strcmp(rusername, *user ? user : lusername)) {
E 39
				fclose(hostf);
				return (1);
			}
		}
		fclose(hostf);
	}
	if (first == 1) {
		char *rhosts = ".rhosts";
		struct stat sbuf;

		first = 0;
		if (chdir(pwd->pw_dir) < 0)
			goto again;
		if (lstat(rhosts, &sbuf) < 0)
			goto again;
		if ((sbuf.st_mode & S_IFMT) == S_IFLNK) {
			printf("login: .rhosts is a soft link.\r\n");
			goto bad;
		}
		hostf = fopen(rhosts, "r");
		fstat(fileno(hostf), &sbuf);
		if (sbuf.st_uid && sbuf.st_uid != pwd->pw_uid) {
			printf("login: Bad .rhosts ownership.\r\n");
			fclose(hostf);
			goto bad;
		}
		goto again;
	}
bad:
	return (-1);
E 43
I 43
	return(ruserok(host, (pwd->pw_uid == 0), rusername, lusername));
E 43
}

E 25
getstr(buf, cnt, err)
	char *buf;
	int cnt;
	char *err;
{
	char c;

	do {
		if (read(0, &c, 1) != 1)
			exit(1);
		if (--cnt < 0) {
			printf("%s too long\r\n", err);
			exit(1);
		}
		*buf++ = c;
	} while (c != 0);
I 25
}

char	*speeds[] =
    { "0", "50", "75", "110", "134", "150", "200", "300",
      "600", "1200", "1800", "2400", "4800", "9600", "19200", "38400" };
#define	NSPEEDS	(sizeof (speeds) / sizeof (speeds[0]))

doremoteterm(term, tp)
	char *term;
	struct sgttyb *tp;
{
D 39
	char *cp = index(term, '/');
	register int i;
E 39
I 39
	register char *cp = index(term, '/'), **cpp;
	char *speed;
D 44
	struct winsize ws;
E 44
E 39

	if (cp) {
D 39
		*cp++ = 0;
		for (i = 0; i < NSPEEDS; i++)
			if (!strcmp(speeds[i], cp)) {
				tp->sg_ispeed = tp->sg_ospeed = i;
E 39
I 39
		*cp++ = '\0';
		speed = cp;
		cp = index(speed, '/');
		if (cp)
			*cp++ = '\0';
		for (cpp = speeds; cpp < &speeds[NSPEEDS]; cpp++)
			if (strcmp(*cpp, speed) == 0) {
				tp->sg_ispeed = tp->sg_ospeed = cpp-speeds;
E 39
				break;
			}
I 39
D 44
		ws.ws_row = ws.ws_col = -1;
		ws.ws_xpixel = ws.ws_ypixel = -1;
		if (cp) {
D 40
			ws.ws_row = atoi(++cp);
E 40
I 40
			ws.ws_row = atoi(cp);
E 40
			cp = index(cp, ',');
			if (cp == 0)
				goto done;
			ws.ws_col = atoi(++cp);
			cp = index(cp, ',');
			if (cp == 0)
				goto done;
			ws.ws_xpixel = atoi(++cp);
			cp = index(cp, ',');
			if (cp == 0)
				goto done;
			ws.ws_ypixel = atoi(++cp);
		}
done:
		if (ws.ws_row != -1 && ws.ws_col != -1 &&
		    ws.ws_xpixel != -1 && ws.ws_ypixel != -1)
			win = ws;
E 44
I 44
D 52
		compatsiz(cp);
E 52
E 44
E 39
	}
	tp->sg_flags = ECHO|CRMOD|ANYP|XTABS;
I 39
D 59
}
I 44
D 52

/* BEGIN TRASH
 *
 * This is here only long enough to get us by to the revised rlogin
 */
compatsiz(cp)
	char *cp;
{
	struct winsize ws;

	ws.ws_row = ws.ws_col = -1;
	ws.ws_xpixel = ws.ws_ypixel = -1;
	if (cp) {
		ws.ws_row = atoi(cp);
		cp = index(cp, ',');
		if (cp == 0)
			goto done;
		ws.ws_col = atoi(++cp);
		cp = index(cp, ',');
		if (cp == 0)
			goto done;
		ws.ws_xpixel = atoi(++cp);
		cp = index(cp, ',');
		if (cp == 0)
			goto done;
		ws.ws_ypixel = atoi(++cp);
	}
done:
	if (ws.ws_row != -1 && ws.ws_col != -1 &&
	    ws.ws_xpixel != -1 && ws.ws_ypixel != -1)
		ioctl(0, TIOCSWINSZ, &ws);
}
/* END TRASH */
E 52
E 44

/*
 * Set the value of var to be arg in the Unix 4.2 BSD environment env.
 * Var should end with '='.
 * (bindings are of the form "var=value")
 * This procedure assumes the memory for the first level of environ
 * was allocated using malloc.
 */
D 47
setenv(var, value)
E 47
I 47
setenv(var, value, clobber)
E 47
	char *var, *value;
{
	extern char **environ;
	int index = 0;
	int varlen = strlen(var);
	int vallen = strlen(value);

	for (index = 0; environ[index] != NULL; index++) {
		if (strncmp(environ[index], var, varlen) == 0) {
			/* found it */
I 47
			if (!clobber)
				return;
E 47
			environ[index] = malloc(varlen + vallen + 1);
			strcpy(environ[index], var);
			strcat(environ[index], value);
			return;
		}
	}
	environ = (char **) realloc(environ, sizeof (char *) * (index + 2));
	if (environ == NULL) {
		fprintf(stderr, "login: malloc out of memory\n");
		exit(1);
	}
	environ[index] = malloc(varlen + vallen + 1);
	strcpy(environ[index], var);
	strcat(environ[index], value);
	environ[++index] = NULL;
E 59
I 54
}

D 55
write_gid()
E 55
I 55
D 57
write_gid(default_gid)
E 57
I 57
tty_gid(default_gid)
E 57
	int default_gid;
E 55
{
	struct group *getgrnam(), *gr;
D 55
	int gid = 0;
E 55
I 55
	int gid = default_gid;
E 55

D 57
	gr = getgrnam(WRITENAME);
E 57
I 57
	gr = getgrnam(TTYGRPNAME);
E 57
	if (gr != (struct group *) 0)
		gid = gr->gr_gid;

	endgrent();

D 55
	return gid;
E 55
I 55
	return (gid);
E 55
E 54
E 39
E 25
I 15
D 36
}

logerr(fmt, a1, a2, a3)
	char *fmt, *a1, *a2, *a3;
{
I 26
#ifdef LOGERR
	FILE *cons = fopen("/dev/console", "w");
E 26

I 26
	if (cons != NULL) {
		fprintf(cons, fmt, a1, a2, a3);
D 32
		fputc('\r', cons);
E 32
I 32
		fprintf(cons, "\n\r");
E 32
		fclose(cons);
	}
#endif
E 36
E 26
E 15
E 12
}
E 1
