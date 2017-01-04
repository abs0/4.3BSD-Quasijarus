h30717
s 00013/00011/01448
d D 5.24 11/04/16 00:35:58 msokolov 62 61
c added support for multiple guest accounts
e
s 00001/00001/01458
d D 5.23 05/01/12 09:06:43 msokolov 61 60
c need to open syslog with LOG_NDELAY so chroot doesn't screw us
e
s 00006/00001/01453
d D 5.22 05/01/12 07:56:21 msokolov 60 59
c log EPS sessions
e
s 00116/00036/01338
d D 5.21 05/01/12 07:31:11 msokolov 59 58
c EPS implemented
e
s 00072/00031/01302
d D 5.20 05/01/11 06:00:14 msokolov 58 57
c use compiled-in ls instead of /bin/ls
c in preparation for EPS with chroot
e
s 00001/00001/01332
d D 5.19 03/11/06 20:24:13 msokolov 57 56
c fix auto gzcompat
e
s 00006/00001/01327
d D 5.18 03/06/10 21:10:59 msokolov 56 55
c make auto gzcompat feature conditional on -DGZCOMPAT for portability
e
s 00120/00062/01208
d D 5.17 03/06/10 21:05:18 msokolov 55 54
c restore LIST/NLST <glob pattern> support, but make it sensible this time
e
s 00212/00070/01058
d D 5.16 01/01/07 17:28:38 msokolov 54 53
c Added /etc/anonftp.allow support.
c While at it, removed support for changing users, which never worked right,
c and cleaned up / fixed / brought up to spec the handling of LIST/NLST and
c STOR/APPE/STOU. (STOU still not per RFC 959, sigh.)
e
s 00027/00000/01101
d D 5.15 00/12/21 22:46:30 msokolov 53 52
c add automatic gzcompat of compressed files on downloads
e
s 00006/00006/01095
d D 5.14 00/06/27 10:10:55 msokolov 52 51
c make reply() and lreply() take up to 6 parameters.
c 5 was too few for the PASV response!
e
s 00002/00001/01099
d D 5.13 99/07/13 22:47:46 msokolov 51 50
c "version" means when the code was written, not when it was compiled!
c make the version string based on ftpd.c SCCS ID and get rid of vers.c kludge
e
s 00010/00005/01090
d D 5.12 88/06/18 13:46:50 bostic 50 49
c install approved copyright notice
e
s 00011/00005/01084
d D 5.11 88/03/14 17:27:50 bostic 49 48
c add Berkeley specific header
e
s 00006/00008/01083
d D 5.10 87/09/04 17:56:29 mckusick 48 47
c fix bogus use of varags (4.3BSD/etc/90)
e
s 00001/00000/01090
d D 5.9 87/04/23 11:39:21 csvsj 47 46
c freoprn stderr to /dev/null to prevent ls() 'file not found' messages
e
s 00002/00001/01088
d D 5.8 86/11/18 20:44:27 bostic 46 45
c FTPD refuses to let /bin/sh users log in; bug report 4.3BSD/etc/19
e
s 00016/00003/01073
d D 5.7 86/05/28 15:24:17 mckusick 45 44
c also require user to have a standard shell
e
s 00022/00043/01054
d D 5.6 86/05/06 21:23:16 minshall 44 43
c Use SO_OOBINLINE for TCP urgent data. 
c Don't send 150 response unless data connection successful for data transfers. 
c Correctly filter \r\r\n during ascii receives. (all from Steve Jacobson)
e
s 00021/00037/01076
d D 5.5 86/04/16 17:37:20 mckusick 43 41
c standardize the reply codes (from mcvax!dpk@seismo.CSS.GOV)
e
s 00001/00001/01112
d R 5.5 86/04/03 13:38:28 mckusick 42 41
c command code 200 does not exist, should be code 250 (from torek)
e
s 00077/00079/01036
d D 5.4 86/03/07 12:01:22 minshall 41 40
c Clean up for lint; add syslog.
e
s 00017/00032/01098
d D 5.3 86/02/18 13:54:40 sam 40 39
c cleanup oob code; recv takes char *, SIOCATMARK takes int; geez!!!!
e
s 00282/00032/00848
d D 5.2 86/02/03 14:32:16 minshall 39 38
c Steve Jacobson's changes (from <csvsj@ucbopal>).
e
s 00014/00002/00866
d D 5.1 85/06/06 11:09:28 dist 38 37
c Add copyright
e
s 00010/00005/00858
d D 4.35 85/06/04 21:46:37 sam 37 36
c force glob failure to result in original string being used (from 
c bug report -- sorry whoever you are)
e
s 00001/00001/00862
d D 4.34 85/02/24 11:57:04 bloom 36 35
c fix printf format
e
s 00011/00011/00852
d D 4.33 84/12/23 16:43:04 sam 35 34
c always exit in dologout; from brl
e
s 00002/00002/00861
d D 4.32 84/09/04 21:43:01 sam 34 33
c convert setsockopt call to new interface
e
s 00014/00011/00849
d D 4.31 84/07/25 02:41:08 lepreau 33 32
c fix wtmp logging: no anonymous logout record; null hostname.
c disallow null passwords yet again.
e
s 00037/00082/00823
d D 4.30 84/04/11 14:55:28 karels 32 31
c convert for inetd
e
s 00015/00006/00890
d D 4.29 84/02/10 15:27:09 ralph 31 30
c log anonymous logins in wtmp properly.
e
s 00001/00001/00895
d D 4.28 83/09/22 22:23:15 sam 30 29
c disallow null passwords (geez I fixed this long ago, where'd it go?)
e
s 00001/00001/00895
d D 4.27 83/08/23 11:34:56 karels 29 28
c if !logged_in, going to loop indefinitely
e
s 00002/00001/00894
d D 4.26 83/08/09 20:11:51 sam 28 27
c if data is buffered when a SIGPIPE arrives, can loop on signals
e
s 00003/00001/00892
d D 4.25 83/07/24 13:19:08 sam 27 26
c don't reply when connection breaks, noone to send to
e
s 00001/00001/00892
d D 4.24 83/07/01 23:57:27 sam 26 25
c include fix
e
s 00070/00038/00823
d D 4.23 83/06/22 14:33:20 sam 25 24
c do wtmp logging and cleanup some stuff
e
s 00021/00015/00840
d D 4.22 83/06/19 23:06:40 root 24 23
c fix glob one more time (can't fix all since glob done in ftpcmd.y)
e
s 00007/00011/00848
d D 4.21 83/06/15 15:19:58 sam 23 22
c fix for multi-homing problem; glob done wrong
e
s 00015/00004/00844
d D 4.20 83/06/12 02:45:04 sam 22 21
c new signals == no libjobs
e
s 00019/00004/00829
d D 4.19 83/03/29 11:25:05 sam 21 20
c from jsq@utexas-11 (mls, mdir and random cleanups after me)
e
s 00039/00044/00794
d D 4.18 83/03/23 10:27:12 sam 20 19
c merge of changes from jsq@utexas-11
e
s 00001/00001/00837
d D 4.17 83/02/28 23:44:26 sam 19 18
c formatting
e
s 00023/00020/00815
d D 4.16 83/02/21 19:38:28 sam 18 17
c fixes from texas
e
s 00122/00000/00713
d D 4.15 83/02/02 16:25:13 sam 17 16
c 2 holes: disallow |'s in ls and dir; 2nd, provide forbidden user list
e
s 00003/00006/00710
d D 4.14 83/01/24 02:11:07 sam 16 15
c pretty dumb stuff -- better to use fileno directly
e
s 00014/00023/00702
d D 4.13 83/01/23 13:34:13 sam 15 14
c hack for address binding + rearrange replys for sanity
e
s 00001/00001/00724
d D 4.12 83/01/22 16:12:48 sam 14 13
c SIGCHLD reset on each occurance
e
s 00001/00007/00724
d D 4.11 83/01/21 22:05:51 sam 13 12
c follow spec dummy
e
s 00001/00000/00730
d D 4.10 83/01/19 12:41:44 sam 12 11
c forgot errno.h, who wrote this code anyway?
e
s 00011/00012/00719
d D 4.9 83/01/19 12:32:15 sam 11 10
c rearrange stuff so printfs look right
e
s 00019/00004/00712
d D 4.8 83/01/18 20:24:54 sam 10 8
c put back debugging and reap children so no zombies
e
s 00016/00003/00713
d R 4.8 83/01/18 20:22:52 sam 9 8
c put back debugging and reap child so no zombies
e
s 00001/00001/00715
d D 4.7 83/01/16 13:16:29 sam 8 7
c oops
e
s 00013/00002/00703
d D 4.6 83/01/16 12:32:48 sam 7 5
c use default port on data transfers when no PORT is specified
e
s 00012/00001/00704
d R 4.6 83/01/16 12:29:28 sam 6 5
c insure default address used even if some transfers supply PORT
e
s 00009/00003/00696
d D 4.5 83/01/16 11:53:17 sam 5 4
c disallow remote command execution, lest someone become root 
c through it by executing a setuid program while using the server
e
s 00002/00002/00697
d D 4.4 83/01/15 21:29:52 sam 4 3
c screwed up reseting effective uid after acquiring socket
e
s 00001/00001/00698
d D 4.3 83/01/15 17:02:40 sam 3 2
c leave stderr open only when debugging
e
s 00069/00026/00630
d D 4.2 83/01/15 17:00:29 sam 2 1
c handle globbing problems; make sure new files are owned 
c by the user; fix problem with rename; lots more (check delta)
e
s 00656/00000/00000
d D 4.1 83/01/13 23:57:01 sam 1 0
c date and time created 83/01/13 23:57:01 by sam
e
u
U
f b 
t
T
I 38
/*
D 39
 * Copyright (c) 1983 Regents of the University of California.
E 39
I 39
 * Copyright (c) 1985 Regents of the University of California.
E 39
D 49
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 49
I 49
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 50
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 50
I 50
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
E 50
E 49
 */

E 38
I 1
#ifndef lint
D 11
static char sccsid[] = "%W% (Berkeley) %E%";
E 11
I 11
D 32
static char sccsid[] = "%W% (Berkeley) %G%";
E 32
I 32
D 38
static	char sccsid[] = "%W% (Berkeley) %G%";
E 32
E 11
#endif
E 38
I 38
char copyright[] =
D 39
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 39
I 39
D 49
"@(#) Copyright (c) 1985 Regents of the University of California.\n\
E 49
I 49
"%Z% Copyright (c) 1985 Regents of the University of California.\n\
E 49
E 39
 All rights reserved.\n";
D 49
#endif not lint
E 49
I 49
#endif /* not lint */
E 49

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 49
#endif not lint
E 49
I 49
#endif /* not lint */
E 49
E 38

/*
 * FTP server.
 */
D 2
#include <sys/types.h>
E 2
I 2
#include <sys/param.h>
E 2
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
I 25
#include <sys/file.h>
I 26
#include <sys/wait.h>
E 26
E 25

#include <netinet/in.h>

I 22
#include <arpa/ftp.h>
I 24
#include <arpa/inet.h>
I 39
#include <arpa/telnet.h>
E 39
E 24

E 22
#include <stdio.h>
#include <signal.h>
D 26
#include <wait.h>
E 26
#include <pwd.h>
#include <setjmp.h>
#include <netdb.h>
I 12
#include <errno.h>
I 39
#include <strings.h>
I 41
#include <syslog.h>
E 41
E 39
E 12

D 22
#include "ftp.h"

E 22
I 17
/*
 * File containing login names
 * NOT to be used on this machine.
 * Commonly used to disallow uucp.
 */
#define	FTPUSERS	"/etc/ftpusers"
I 54
/*
 * File containing pathnames that guest users can access. If not found, guest
 * users can do anything that file permissions allow.
 */
#define	ANONFTPALLOW	"/etc/anonftp.allow"
/*
 * We keep a buffer with pointers to pathnames read from the above file.
 * Allocate it 32 entries at a time (first malloc, then realloc).
 */
#define	GUESTDIRSINCR	32
E 54

I 55
/* Longest arglist we are willing to generate from globbing */
#define	GAVSIZ		(NCARGS/6)

E 55
I 51
char	version[] = "Version %I% %Q% %U%";

E 51
E 17
extern	int errno;
extern	char *sys_errlist[];
extern	char *crypt();
D 51
extern	char version[];
E 51
D 55
extern	char *home;		/* pointer to home directory for glob */
E 55
D 39
extern	FILE *popen(), *fopen();
E 39
I 39
extern	FILE *popen(), *fopen(), *freopen();
E 39
D 41
extern	int pclose(), fclose();
E 41
I 41
extern	int  pclose(), fclose();
I 53
extern	char *alloca();
E 53
E 41
I 39
extern	char *getline();
extern	char cbuf[];
I 59
extern	int _pw_stayopen;
extern	int epsquota;
E 59
E 39

struct	sockaddr_in ctrl_addr;
struct	sockaddr_in data_source;
struct	sockaddr_in data_dest;
struct	sockaddr_in his_addr;

D 41
struct	hostent *hp;

E 41
int	data;
D 39
jmp_buf	errcatch;
E 39
I 39
jmp_buf	errcatch, urgcatch;
E 39
int	logged_in;
struct	passwd *pw;
int	debug;
I 20
D 41
int	timeout;
E 41
I 41
int	timeout = 900;    /* timeout after 15 minutes of inactivity */
E 41
E 20
D 21
int	logging = 1;
E 21
I 21
int	logging;
E 21
D 62
int	guest;
E 62
I 31
int	wtmp;
E 31
int	type;
int	form;
int	stru;			/* avoid C keyword */
int	mode;
I 7
int	usedefault = 1;		/* for data transfers */
I 39
int	pdata;			/* for passive mode */
D 54
int	unique;
E 54
int	transflag;
char	tmpline[7];
E 39
E 7
char	hostname[32];
D 25
char	*remotehost;
E 25
I 25
char	remotehost[32];
I 54
char	**guestdirs;
int	nguestdirs;
I 59
int	authmode;
I 60
char	epsaccount[10];
E 60
int	chrooted;
E 59
E 54
E 25
I 7
D 32
struct	servent *sp;
E 32
E 7

I 59
#define	AUTHMODE_INIT	0
#define	AUTHMODE_USER	1
#define	AUTHMODE_GUEST	2
#define	AUTHMODE_EPS	3
#define	AUTHMODE_BAD	4

E 59
I 20
/*
 * Timeout intervals for retrying connections
 * to hosts that don't accept PORT cmds.  This
 * is a kludge, but given the problems with TCP...
 */
#define	SWAITMAX	90	/* wait at most 90 seconds */
#define	SWAITINT	5	/* interval between retries */

int	swaitmax = SWAITMAX;
int	swaitint = SWAITINT;

E 20
int	lostconn();
I 10
D 41
int	reapchild();
E 41
I 39
int	myoob();
E 39
E 10
FILE	*getdatasock(), *dataconn();
I 55
FILE	*mypopen();
int	mypclose();
E 55
D 25
char	*ntoa();
E 25

main(argc, argv)
	int argc;
	char *argv[];
{
D 32
	int ctrl, s, options = 0;
E 32
I 32
D 41
	int options = 0, addrlen;
E 41
I 41
D 44
	int addrlen;
E 44
I 44
	int addrlen, on = 1;
E 44
E 41
I 39
	long pgid;
E 39
E 32
D 7
	struct servent *sp;
E 7
D 10
	union wait status;
E 10
	char *cp;

D 32
	sp = getservbyname("ftp", "tcp");
	if (sp == 0) {
D 18
		fprintf(stderr, "ftpd: fpt/tcp: unknown service\n");
E 18
I 18
		fprintf(stderr, "ftpd: ftp/tcp: unknown service\n");
E 32
I 32
	addrlen = sizeof (his_addr);
	if (getpeername(0, &his_addr, &addrlen) < 0) {
D 41
		fprintf(stderr, "%s: ", argv[0]);
		perror("getpeername");
E 41
I 41
		syslog(LOG_ERR, "getpeername (%s): %m",argv[0]);
E 41
E 32
E 18
		exit(1);
	}
D 32
	ctrl_addr.sin_port = sp->s_port;
	data_source.sin_port = htons(ntohs(sp->s_port) - 1);
	signal(SIGPIPE, lostconn);
E 32
I 32
	addrlen = sizeof (ctrl_addr);
D 41
	if (getsockname(0, &ctrl_addr, &addrlen) < 0) {
		fprintf(stderr, "%s: ", argv[0]);
		perror("getsockname");
E 41
I 41
	if (getsockname(0, (char *) &ctrl_addr, &addrlen) < 0) {
		syslog(LOG_ERR, "getsockname (%s): %m",argv[0]);
E 41
		exit(1);
	}
	data_source.sin_port = htons(ntohs(ctrl_addr.sin_port) - 1);
E 32
	debug = 0;
I 41
D 61
	openlog("ftpd", LOG_PID, LOG_DAEMON);
E 61
I 61
	openlog("ftpd", LOG_PID|LOG_NDELAY, LOG_DAEMON);
E 61
E 41
	argc--, argv++;
	while (argc > 0 && *argv[0] == '-') {
		for (cp = &argv[0][1]; *cp; cp++) switch (*cp) {

I 20
		case 'v':
			debug = 1;
			break;

E 20
		case 'd':
			debug = 1;
D 41
			options |= SO_DEBUG;
E 41
			break;

I 21
		case 'l':
			logging = 1;
I 39
D 41
			(void) freopen("/tmp/ftplog", "a", stderr);
E 41
E 39
			break;

E 21
I 20
		case 't':
			timeout = atoi(++cp);
			goto nextopt;
			break;

E 20
		default:
D 20
			fprintf(stderr, "Unknown flag -%c ignored.\n", cp);
E 20
I 20
D 32
			fprintf(stderr, "Unknown flag -%c ignored.\n", *cp);
E 32
I 32
			fprintf(stderr, "ftpd: Unknown flag -%c ignored.\n",
			     *cp);
E 32
E 20
			break;
		}
I 20
nextopt:
E 20
		argc--, argv++;
	}
I 47
	(void) freopen("/dev/null", "w", stderr);
E 47
D 32
#ifndef DEBUG
	if (fork())
		exit(0);
	for (s = 0; s < 10; s++)
I 20
		if (!logging || (s != 2))
			(void) close(s);
E 20
D 3
		if (s != 2)		/* don't screw stderr */
E 3
I 3
D 5
		if (s != 2 && debug)		/* don't screw stderr */
E 3
			(void) close(s);
E 5
I 5
D 21
		(void) close(s);
E 21
E 5
D 18
	(void) open("/dev/null", 0);
E 18
I 18
D 25
	(void) open("/", 0);
E 25
I 25
	(void) open("/", O_RDONLY);
E 25
E 18
	(void) dup2(0, 1);
I 18
D 20
	(void) dup2(0, 2);
E 20
I 20
	if (!logging)
		(void) dup2(0, 2);
E 20
E 18
D 25
	{ int tt = open("/dev/tty", 2);
E 25
I 25
	{ int tt = open("/dev/tty", O_RDWR);
E 25
	  if (tt > 0) {
		ioctl(tt, TIOCNOTTY, 0);
		close(tt);
	  }
	}
#endif
D 2
	while ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
E 2
I 2
D 25
	while ((s = socket(AF_INET, SOCK_STREAM, 0, 0)) < 0) {
E 25
I 25
	while ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
E 25
E 2
		perror("ftpd: socket");
		sleep(5);
	}
I 10
	if (options & SO_DEBUG)
		if (setsockopt(s, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
			perror("ftpd: setsockopt (SO_DEBUG)");
D 25
#ifdef notdef
E 25
	if (setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0)
		perror("ftpd: setsockopt (SO_KEEPALIVE)");
D 25
#endif
E 25
E 10
	while (bind(s, &ctrl_addr, sizeof (ctrl_addr), 0) < 0) {
		perror("ftpd: bind");
		sleep(5);
	}
I 10
D 14
	signal(SIGCHLD, reapchild);
E 14
I 14
D 22
	sigset(SIGCHLD, reapchild);
E 22
I 22
	signal(SIGCHLD, reapchild);
E 22
E 14
E 10
I 2
	listen(s, 10);
E 2
	for (;;) {
		int hisaddrlen = sizeof (his_addr);

		ctrl = accept(s, &his_addr, &hisaddrlen, 0);
		if (ctrl < 0) {
I 10
			if (errno == EINTR)
				continue;
E 10
			perror("ftpd: accept");
D 10
			sleep(5);
E 10
			continue;
		}
D 7
		data_dest = his_addr;
E 7
		if (fork() == 0) {
I 18
			signal (SIGCHLD, SIG_IGN);
E 18
D 25
			if (logging)
				dolog(&his_addr);
E 25
I 25
			dolog(&his_addr);
E 25
			close(s);
			dup2(ctrl, 0), close(ctrl), dup2(0, 1);
			/* do telnet option negotiation here */
I 2
			/*
			 * Set up default state
			 */
E 2
			logged_in = 0;
			data = -1;
I 2
			type = TYPE_A;
			form = FORM_N;
			stru = STRU_F;
			mode = MODE_S;
I 23
			(void) getsockname(0, &ctrl_addr, sizeof (ctrl_addr));
E 23
E 2
			gethostname(hostname, sizeof (hostname));
			reply(220, "%s FTP server (%s) ready.",
				hostname, version);
I 22
D 23
			/*
			 * Anchor data source address to that
			 * of the control port so hosts with
			 * multiple address won't have data
			 * connections bound to an address different
			 * than the control port.
			 */
			if (getsockname(0, &ctrl_addr, sizeof (ctrl_addr)) >= 0)
				data_source.sin_addr = ctrl_addr.sin_addr;
E 23
E 22
			for (;;) {
				setjmp(errcatch);
				yyparse();
			}
		}
		close(ctrl);
E 32
I 32
D 41
	signal(SIGPIPE, lostconn);
	signal(SIGCHLD, SIG_IGN);
E 41
I 41
	(void) signal(SIGPIPE, lostconn);
	(void) signal(SIGCHLD, SIG_IGN);
E 41
I 39
	if (signal(SIGURG, myoob) < 0) {
D 41
		perror("signal");
E 41
I 41
		syslog(LOG_ERR, "signal: %m");
E 41
	}
I 44
	/* handle urgent data inline */
#ifdef SO_OOBINLINE
	if (setsockopt(0, SOL_SOCKET, SO_OOBINLINE, (char *)&on, sizeof(on)) < 0) {
		syslog(LOG_ERR, "setsockopt: %m");
	}
#endif SO_OOBINLINE
E 44
	pgid = getpid();
D 41
	if (ioctl(fileno(stdin), SIOCSPGRP, (char *) &pgid) < 0) {
		perror("ioctl");
E 41
I 41
D 44
	if (ioctl(fileno(stdin), (int) SIOCSPGRP, (char *) &pgid) < 0) {
E 44
I 44
	if (ioctl(fileno(stdin), SIOCSPGRP, (char *) &pgid) < 0) {
E 44
		syslog(LOG_ERR, "ioctl: %m");
E 41
	}
E 39
I 33
	dolog(&his_addr);
E 33
	/* do telnet option negotiation here */
	/*
	 * Set up default state
	 */
	logged_in = 0;
	data = -1;
	type = TYPE_A;
	form = FORM_N;
	stru = STRU_F;
	mode = MODE_S;
I 39
	tmpline[0] = '\0';
E 39
D 41
	gethostname(hostname, sizeof (hostname));
E 41
I 41
	(void) gethostname(hostname, sizeof (hostname));
E 41
	reply(220, "%s FTP server (%s) ready.",
		hostname, version);
I 59
	_pw_stayopen = 1;
I 62
	init_special_guests();
E 62
E 59
	for (;;) {
D 41
		setjmp(errcatch);
		yyparse();
E 41
I 41
		(void) setjmp(errcatch);
		(void) yyparse();
E 41
E 32
D 10
		while (wait3(status, WNOHANG, 0) > 0)
			continue;
E 10
	}
I 10
}
D 41

E 41
I 41
D 43
/*
E 41
reapchild()
{
	union wait status;
E 43

D 43
	while (wait3(&status, WNOHANG, 0) > 0)
		;
E 10
}
I 41
*/
E 41

E 43
lostconn()
{

D 27
	fatal("Connection closed.");
E 27
I 27
	if (debug)
D 41
		fprintf(stderr, "Lost connection.\n");
E 41
I 41
		syslog(LOG_DEBUG, "lost connection");
E 41
	dologout(-1);
E 27
}

I 59
user(name)
	register char *name;
{
	/*
	 * RFC 959 allows us to change users, but doesn't
	 * require us to.  We used to support this, but it never
	 * worked right and now we have to block it altogether.
	 * 503 reply code is not in the table for USER, but RFC 1123
	 * relaxed rules let us use it.
	 */
	if (logged_in) {
		reply(503, "Changing USER is not supported.");
	} else if (strcmp(name, "ftp") == 0 || strcmp(name, "anonymous") == 0) {
		if ((pw = getpwnam("ftp")) != NULL) {
			authmode = AUTHMODE_GUEST;
D 62
			guest = 1;
E 62
			reply(331, "Guest login ok, send ident as password.");
		}
		else {
			reply(530, "No anonymous FTP service.");
		}
	} else if (pw = getpwnam(name)) {
D 62
		if (checkuser(name)) {
E 62
I 62
		if (is_special_guest(name)) {
			authmode = AUTHMODE_GUEST;
			reply(331,
				"Special guest login ok, send dummy password.");
		} else if (checkuser(name)) {
E 62
			authmode = AUTHMODE_USER;
D 62
askpass:		guest = 0;
			reply(331, "Password required for %s.", name);
E 62
I 62
askpass:		reply(331, "Password required for %s.", name);
E 62
		} else
			reply(530, "User %s access denied.", name);
	} else if (isepsname(name) && !eps_readaccount(name)) {
		authmode = AUTHMODE_EPS;
I 60
		strcpy(epsaccount, name);
E 60
		goto askpass;
	} else {
		/*
		 * Don't tell them whether the username or the password is
		 * invalid.
		 */
		authmode = AUTHMODE_BAD;
		goto askpass;
	}
}

E 59
pass(passwd)
	char *passwd;
{
D 2
	char *xpasswd;
E 2
I 2
	char *xpasswd, *savestr();
	static struct passwd save;
E 2

D 59
	if (logged_in || pw == NULL) {
		reply(503, "Login with USER first.");
E 59
I 59
	if (logged_in) {
		reply(503, "You are already logged in.");
E 59
		return;
	}
D 59
	if (!guest) {		/* "ftp" is only account allowed no password */
E 59
I 59
	switch (authmode) {
	case AUTHMODE_INIT:
		reply(503, "Login with USER first.");
		return;
	case AUTHMODE_USER:
		chrooted = 0;
		goto checkpass;
	case AUTHMODE_EPS:
		chrooted = 1;
	checkpass:
E 59
		xpasswd = crypt(passwd, pw->pw_passwd);
D 30
		if (strcmp(xpasswd, pw->pw_passwd) != 0) {
E 30
I 30
D 32
		if (*pw->pw_passwd == '\0' || strcmp(xpasswd, pw->pw_passwd)) {
E 32
I 32
D 33
		if (strcmp(xpasswd, pw->pw_passwd) != 0) {
E 33
I 33
		/* The strcmp does not catch null passwords! */
D 59
		if (*pw->pw_passwd == '\0' || strcmp(xpasswd, pw->pw_passwd)) {
E 33
E 32
E 30
			reply(530, "Login incorrect.");
			pw = NULL;
			return;
		}
E 59
I 59
		if (*pw->pw_passwd == '\0' || strcmp(xpasswd, pw->pw_passwd))
			goto badlogin;
		break;
	case AUTHMODE_GUEST:
		/* anonymous - anything goes for the password */
		if (strcmp(pw->pw_dir, "/"))
			chrooted = 1;
		else
			chrooted = 0;
		break;
	case AUTHMODE_BAD:
	badlogin:
		reply(530, "Login incorrect.");
		authmode = AUTHMODE_INIT;
		return;
E 59
	}
D 2
	home = pw->pw_dir;		/* home dir for globbing */
	setreuid(-1, pw->pw_uid);
	setregid(-1, pw->pw_gid);
E 2
I 2
	setegid(pw->pw_gid);
E 2
	initgroups(pw->pw_name, pw->pw_gid);
	if (chdir(pw->pw_dir)) {
D 36
		reply(550, "User %s: can't change directory to $s.",
E 36
I 36
D 43
		reply(550, "User %s: can't change directory to %s.",
E 43
I 43
		reply(530, "User %s: can't change directory to %s.",
E 43
E 36
			pw->pw_name, pw->pw_dir);
D 2
		pw = NULL;
		return;
E 2
I 2
		goto bad;
E 2
	}
I 31

D 33
	if (guest)			/* grab wtmp before chroot */
		wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
E 33
I 33
	/* grab wtmp before chroot */
D 59
	wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
E 33
D 32

E 32
E 31
D 2
	if (guest && chroot(pw->pw_dir) < 0){
E 2
I 2
	if (guest && chroot(pw->pw_dir) < 0) {
E 2
		reply(550, "Can't set guest privileges.");
E 59
I 59
	if (authmode != AUTHMODE_EPS)
		wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
	if (chrooted && chroot(pw->pw_dir) < 0) {
		reply(530, "Can't set guest privileges.");
E 59
I 33
		if (wtmp >= 0) {
			(void) close(wtmp);
			wtmp = -1;
		}
E 33
D 2
		pw = NULL;
		return;
E 2
I 2
		goto bad;
E 2
	}
D 59
	if (!guest)
E 59
I 59
	switch (authmode) {
	case AUTHMODE_USER:
E 59
		reply(230, "User %s logged in.", pw->pw_name);
D 54
	else
E 54
I 54
D 59
	else {
E 59
I 59
		break;
	case AUTHMODE_GUEST:
E 59
		init_guest_dirs();
E 54
		reply(230, "Guest login ok, access restrictions apply.");
I 59
		break;
	case AUTHMODE_EPS:
D 60
		reply(230, "Logged into Electronic Parcel Service.");
E 60
I 60
		reply(230, "Logged into EPS account %s.", epsaccount);
E 60
		break;
E 59
I 54
	}
E 54
	logged_in = 1;
I 25
D 59
	dologin(pw);
E 59
I 59
	if (authmode != AUTHMODE_EPS)
		dologin(pw);
I 60
	else
		syslog(LOG_INFO, "EPS session: account %s, connection from %s",
			epsaccount, remotehost);
E 60
E 59
E 25
I 2
	seteuid(pw->pw_uid);
	/*
	 * Save everything so globbing doesn't
	 * clobber the fields.
	 */
	save = *pw;
	save.pw_name = savestr(pw->pw_name);
	save.pw_passwd = savestr(pw->pw_passwd);
	save.pw_comment = savestr(pw->pw_comment);
D 41
	save.pw_gecos = savestr(pw->pw_gecos, &save.pw_gecos);
E 41
I 41
	save.pw_gecos = savestr(pw->pw_gecos);
E 41
	save.pw_dir = savestr(pw->pw_dir);
	save.pw_shell = savestr(pw->pw_shell);
	pw = &save;
D 55
	home = pw->pw_dir;		/* home dir for globbing */
E 55
	return;
bad:
	seteuid(0);
D 59
	pw = NULL;
E 59
I 59
	authmode = AUTHMODE_INIT;
E 59
E 2
}

I 2
char *
savestr(s)
	char *s;
{
	char *malloc();
D 41
	char *new = malloc(strlen(s) + 1);
E 41
I 41
	char *new = malloc((unsigned) strlen(s) + 1);
E 41
D 59
	
E 59
I 59

E 59
	if (new != NULL)
D 41
		strcpy(new, s);
E 41
I 41
		(void) strcpy(new, s);
E 41
D 19
	return(new);
E 19
I 19
	return (new);
E 19
}

I 55
/*
 * Here is how we implement the list commands.
 *
 * First if a pathname is specified and it contains slash(es), we first chdir
 * to the last slash (rindex). No globbing is allowed before the last slash,
 * and we do the anonymous FTP protection at this point.
 *
 * After this we have four possibilities as far as the list spec goes: nothing,
 * a filename, a directory name, or a globbing pattern. If nothing, we ls the
 * current directory. If a subdirectory name, we ls that subdirectory. If a
 * single filename, we ls that (arguably not very useful). The last two cases
 * are distinguished by ls, not by us. The specified thing must exist (tested
 * by lstat) or we 550. Finally, if we have a globbing pattern (contains '*',
 * '?', '[', or '{'), we glob it. If we got nothing, we 550. Otherwise, we give
 * the list to ls with -d.
 */
D 58
list(spec, longlist)
E 58
I 58
list(spec)
E 58
	register char *spec;
{
D 58
	char savedir[MAXPATHLEN], *dir = ".";
E 58
I 58
	int p[2];
	char *dir = ".";
E 58
	int haveglob = 0;
	char *argv[GAVSIZ], **globvec;
	register int argc;
	register int i;
	register char *cp;
	register char **av;
	struct stat st;
I 58
	char flg;
E 58

D 58
	savedir[0] = '\0';
E 58
I 58
	if (pipe(p) < 0) {
D 59
		reply(450, "System error: pipe: %s.", sys_errlist[errno]);
E 59
I 59
		reply(451, "System error: pipe: %s.", sys_errlist[errno]);
E 59
		return;
	}
	i = fork();
	if (i < 0) {
D 59
		reply(450, "System error: fork: %s.", sys_errlist[errno]);
E 59
I 59
		reply(451, "System error: fork: %s.", sys_errlist[errno]);
E 59
		close(p[0]);
		close(p[1]);
		return;
	}
	if (i > 0) {
		close(p[1]);
		i = p[0];
		read(i, &flg, 1);
		if (flg) {
			close(i);
			goto out;
		}
		retrcore(fdopen(i, "r"), "file list", (off_t) -1);
out:		(void) wait();
		return;
	}
	close(p[0]);

E 58
	if (spec) {
D 62
		if (guest && guestdirs && guest_check_pathname(spec)) {
E 62
I 62
		if (guestdirs && guest_check_pathname(spec)) {
E 62
			reply(550, "%s: %s.", spec, sys_errlist[EACCES]);
D 58
			return;
E 58
I 58
			goto childfail;
E 58
		}
		cp = rindex(spec, '/');
		if (cp) {
D 58
			getwd(savedir);
E 58
			if (cp == spec)
				dir = "/";
			else {
				*cp = '\0';
				dir = spec;
			}
			if (chdir(dir) < 0) {
				reply(550, "%s: %s.", dir, sys_errlist[errno]);
D 58
				return;
E 58
I 58
				goto childfail;
E 58
			}
			spec = cp + 1;
		}
		haveglob = isaglob(spec);
	}

	argv[0] = "ls";
	argc = 1;
D 58
	if (longlist && !haveglob)
		argv[argc++] = "-lg";
	else if (longlist && haveglob)
		argv[argc++] = "-lgd";
	else if (!longlist && haveglob)
		argv[argc++] = "-d";
E 58
	if (spec == NULL || *spec == '\0')
		goto doit;
D 58
	argv[argc++] = "--";
E 58
	if (!haveglob) {
		if (lstat(spec, &st) < 0) {
			reply(550, "%s: %s.", spec, sys_errlist[errno]);
D 58
			if (savedir[0])
				chdir(savedir);
			return;
E 58
I 58
			goto childfail;
E 58
		}
		argv[argc++] = spec;
		goto doit;
	}
	globvec = argv + argc;
	i = glob(spec, globvec, GAVSIZ - argc - 1);
	if (i < 0) {
		reply(550, "%s: %s.", dir, sys_errlist[errno]);
D 58
		if (savedir[0])
			chdir(savedir);
		return;
E 58
I 58
		goto childfail;
E 58
	}
	if (i == 0) {
		reply(550, "%s: No match.", spec);
D 58
		if (savedir[0])
			chdir(savedir);
		return;
E 58
I 58
		goto childfail;
E 58
	}
	argc += i;

D 58
doit:	argv[argc] = NULL;
	retrieve("/bin/ls", argv);
	if (savedir[0])
		chdir(savedir);
	if (haveglob)
		for (av = globvec; *av; av++)
			free(*av);
E 58
I 58
doit:	flg = 0;
	argv[argc] = NULL;
	dup2(p[1], 1);
	dup2(p[1], 2);
	close(p[1]);
	write(1, &flg, 1);
	exit(ls(haveglob, argc, argv));

childfail:
	flg = 1;
	write(p[1], &flg, 1);
	exit(1);
E 58
}

E 55
E 2
retrieve(cmd, name)
	char *cmd, *name;
{
	FILE *fin, *dout;
	struct stat st;
D 39
	int (*closefunc)();
E 39
I 39
	int (*closefunc)(), tmp;
I 55
D 56
	char **argv = (char **) name, *gzcompat_argv[3];
E 56
I 56
	char **argv = (char **) name;
#ifdef GZCOMPAT
	char *gzcompat_argv[3];
#endif
E 56
E 55
E 39

I 53
retry:
E 53
	if (cmd == 0) {
I 5
#ifdef notdef
		/* no remote command execution -- it's a security hole */
E 5
D 20
		if (*name == '!')
E 20
I 20
		if (*name == '|')
E 20
			fin = popen(name + 1, "r"), closefunc = pclose;
		else
I 5
#endif
E 5
D 54
			fin = fopen(name, "r"), closefunc = fclose;
E 54
I 54
		{
D 62
			if (guest && guestdirs && guest_check_pathname(name))
E 62
I 62
			if (guestdirs && guest_check_pathname(name))
E 62
				fin = NULL, errno = EACCES;
			else
				fin = fopen(name, "r"), closefunc = fclose;
		}
E 54
	} else {
D 55
		char line[BUFSIZ];

D 11
		sprintf(line, cmd, name);
E 11
I 11
D 41
		sprintf(line, cmd, name), name = line;
E 41
I 41
		(void) sprintf(line, cmd, name), name = line;
E 41
E 11
		fin = popen(line, "r"), closefunc = pclose;
E 55
I 55
		fin = mypopen(cmd, argv, "r"), closefunc = mypclose;
		name = cmd;
E 55
	}
	if (fin == NULL) {
I 56
#ifdef GZCOMPAT
E 56
I 53
D 59
		if (cmd == NULL && errno == ENOENT) {
E 59
I 59
		if (cmd == NULL && errno == ENOENT && !chrooted) {
E 59
			int namelen;
			char *newname;

			namelen = strlen(name);
			if (namelen > 2 && name[namelen-2] == '.'
			  && name[namelen-1] == 'Z') {
				newname = alloca(namelen + 2);
				strncpy(newname, name, namelen - 2);
				strcat(newname, ".gz");
			} else if (namelen > 3 && name[namelen-3] == '.'
			  && name[namelen-2] == 'g' && name[namelen-1] == 'z') {
				newname = alloca(namelen);
				strncpy(newname, name, namelen - 3);
				strcat(newname, ".Z");
			} else
				goto bailout;
			if (stat(newname, &st) < 0
			    || (st.st_mode&S_IFMT) != S_IFREG)
				goto bailout;
D 57
			cmd = "/usr/ucb/gzcompat %s";
E 57
I 57
			cmd = "/usr/ucb/gzcompat";
E 57
D 55
			name = newname;
E 55
I 55
			argv = gzcompat_argv;
			argv[0] = "gzcompat";
			argv[1] = newname;
			argv[2] = NULL;
E 55
			goto retry;
bailout:		errno = ENOENT;
		}
I 56
#endif
E 56
E 53
D 23
		reply(550, "%s: %s.", name, sys_errlist[errno]);
E 23
I 23
		if (errno != 0)
			reply(550, "%s: %s.", name, sys_errlist[errno]);
E 23
		return;
	}
D 58
	st.st_size = 0;
E 58
I 58
	st.st_size = -1;
E 58
	if (cmd == 0 &&
	    (stat(name, &st) < 0 || (st.st_mode&S_IFMT) != S_IFREG)) {
		reply(550, "%s: not a plain file.", name);
		goto done;
	}
	dout = dataconn(name, st.st_size, "w");
	if (dout == NULL)
		goto done;
D 2
	if (!send_data(fin, dout) || ferror(dout))
E 2
I 2
D 39
	if (send_data(fin, dout) || ferror(dout))
E 39
I 39
	if ((tmp = send_data(fin, dout)) > 0 || ferror(dout) > 0) {
E 39
E 2
		reply(550, "%s: %s.", name, sys_errlist[errno]);
D 39
	else
E 39
I 39
	}
	else if (tmp == 0) {
E 39
		reply(226, "Transfer complete.");
D 2
	if (mode == MODE_S)
		/* indicate EOF by closing connection */
		fclose(dout), data = -1;
E 2
I 2
D 39
	fclose(dout), data = -1;
E 39
I 39
	}
D 41
	fclose(dout);
E 41
I 41
	(void) fclose(dout);
E 41
	data = -1;
	pdata = -1;
E 39
E 2
done:
	(*closefunc)(fin);
}

I 58
retrcore(fin, name, size)
	FILE *fin;
	char *name;
	off_t size;
{
	FILE *dout;
	int tmp;

	dout = dataconn(name, size, "w");
	if (dout == NULL)
		goto done;
	if ((tmp = send_data(fin, dout)) > 0 || ferror(dout) > 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
	}
	else if (tmp == 0) {
		reply(226, "Transfer complete.");
	}
	(void) fclose(dout);
	data = -1;
	pdata = -1;
done:
	(void) fclose(fin);
}

E 58
store(name, mode)
	char *name, *mode;
{
	FILE *fout, *din;
D 2
	int (*closefunc)();
E 2
I 2
D 39
	int (*closefunc)(), dochown = 0;
E 39
I 39
D 54
	int (*closefunc)(), dochown = 0, tmp;
	char *gunique(), *local;
E 54
I 54
	int (*closefunc)(), dochown = 0, tmp, localcnt = 0;
	char *local, localname[MAXPATHLEN], *localtail;
E 54
E 39
E 2

I 59
	if (authmode == AUTHMODE_EPS && !epsquota) {
		reply(550, "This EPS account is read-only.");
		return;
	}
E 59
I 5
#ifdef notdef
	/* no remote command execution -- it's a security hole */
E 5
D 20
	if (name[0] == '!')
E 20
I 20
	if (name[0] == '|')
E 20
		fout = popen(&name[1], "w"), closefunc = pclose;
D 2
	else
E 2
I 2
D 5
	else {
E 5
I 5
	else
#endif
	{
E 5
D 54
		struct stat st;

E 54
I 54
D 62
		if (guest && guestdirs != NULL && guest_check_pathname(name)) {
E 62
I 62
		if (guestdirs != NULL && guest_check_pathname(name)) {
E 62
			reply(553, "%s: %s.", name, sys_errlist[EACCES]);
			return;
		}
E 54
D 39
		if (stat(name, &st) < 0)
E 39
I 39
		local = name;
D 54
		if (stat(name, &st) < 0) {
E 54
I 54
openretry:
		tmp = open(local, O_CREAT | O_EXCL | O_WRONLY, 0666);
		if (tmp >= 0) {
E 54
E 39
			dochown++;
I 54
			goto openok;
E 54
E 2
D 39
		fout = fopen(name, mode), closefunc = fclose;
E 39
I 39
		}
D 54
		else if (unique) {
			if ((local = gunique(name)) == NULL) {
E 54
I 54
		if (errno != EEXIST) {
			reply(553, "%s: %s.", local, sys_errlist[errno]);
			return;
		}
		switch (*mode) {
		case 'w':
			tmp = open(local, O_TRUNC | O_WRONLY);
			break;
		case 'a':
			tmp = open(local, O_WRONLY);
			break;
		case 'u':
			if (!localcnt) {
				if (strlen(name) > MAXPATHLEN - 4) {
					reply(553, "%s: %s.", name,
					      sys_errlist[ENAMETOOLONG]);
					return;
				}
				strcpy(localname, name);
				local = localname;
				localtail = index(local, '\0');
			}
			if (++localcnt == 100) {
				reply(452,
				      "Unique file name cannot be created.");
E 54
				return;
			}
D 54
			dochown++;
E 54
I 54
			sprintf(localtail, ".%d", localcnt);
			goto openretry;
E 54
		}
D 54
		fout = fopen(local, mode), closefunc = fclose;
E 54
I 54
		if (tmp < 0) {
			reply(553, "%s: %s.", local, sys_errlist[errno]);
			return;
		}
openok:
		fout = fdopen(tmp, *mode == 'u' ? "w" : mode);
		closefunc = fclose;
E 54
E 39
I 2
	}
E 2
	if (fout == NULL) {
D 39
		reply(550, "%s: %s.", name, sys_errlist[errno]);
E 39
I 39
D 43
		reply(550, "%s: %s.", local, sys_errlist[errno]);
E 43
I 43
		reply(553, "%s: %s.", local, sys_errlist[errno]);
E 43
E 39
		return;
	}
D 20
	din = dataconn(name, -1, "r");
E 20
I 20
D 39
	din = dataconn(name, (off_t)-1, "r");
E 39
I 39
	din = dataconn(local, (off_t)-1, "r");
E 39
E 20
	if (din == NULL)
		goto done;
D 2
	if (!receive_data(din, fout) || ferror(fout))
E 2
I 2
D 39
	if (receive_data(din, fout) || ferror(fout))
E 2
		reply(550, "%s: %s.", name, sys_errlist[errno]);
	else
E 39
I 39
	if ((tmp = receive_data(din, fout)) > 0 || ferror(fout) > 0) {
D 43
		reply(550, "%s: %s.", local, sys_errlist[errno]);
E 43
I 43
		reply(552, "%s: %s.", local, sys_errlist[errno]);
E 43
	}
D 54
	else if (tmp == 0 && !unique) {
E 54
I 54
	else if (tmp == 0 && *mode != 'u') {
E 54
E 39
		reply(226, "Transfer complete.");
D 39
	fclose(din), data = -1;
E 39
I 39
	}
D 54
	else if (tmp == 0 && unique) {
E 54
I 54
	else if (tmp == 0 && *mode == 'u') {
E 54
		reply(226, "Transfer complete (unique file name:%s).", local);
	}
D 41
	fclose(din);
E 41
I 41
	(void) fclose(din);
E 41
	data = -1;
	pdata = -1;
E 39
done:
I 2
	if (dochown)
D 39
		(void) chown(name, pw->pw_uid, -1);
E 39
I 39
		(void) chown(local, pw->pw_uid, -1);
E 39
E 2
	(*closefunc)(fout);
}

FILE *
getdatasock(mode)
	char *mode;
{
D 15
	int retrytime, s;
E 15
I 15
D 22
	int s;
E 22
I 22
D 25
	int s, linger;
E 25
I 25
D 34
	int s;
E 34
I 34
	int s, on = 1;
E 34
E 25
E 22
E 15

	if (data >= 0)
		return (fdopen(data, mode));
D 15
	retrytime = 1;
	while ((s = socket(AF_INET, SOCK_STREAM, 0, 0)) < 0) {
		if (retrytime < 5) {
			sleep(retrytime);
			retrytime <<= 1;
			continue;
		}
E 15
I 15
D 25
	s = socket(AF_INET, SOCK_STREAM, 0, 0);
E 25
I 25
	s = socket(AF_INET, SOCK_STREAM, 0);
E 25
	if (s < 0)
E 15
		return (NULL);
D 15
	}
	retrytime = 1;
E 15
	seteuid(0);
D 15
	while (bind(s, &data_source, sizeof (data_source), 0) < 0) {
		if (retrytime < 5) {
			sleep(retrytime);
			retrytime <<= 1;
			continue;
		}
D 4
		seteuid(0);
E 4
I 4
		seteuid(pw->pw_uid);
E 4
		close(s);
		return (NULL);
	}
E 15
I 15
D 34
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, 0, 0) < 0)
E 34
I 34
D 41
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof (on)) < 0)
E 41
I 41
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof (on)) < 0)
E 41
E 34
		goto bad;
I 23
	/* anchor socket to avoid multi-homing problems */
	data_source.sin_family = AF_INET;
	data_source.sin_addr = ctrl_addr.sin_addr;
E 23
D 41
	if (bind(s, &data_source, sizeof (data_source), 0) < 0)
E 41
I 41
	if (bind(s, &data_source, sizeof (data_source)) < 0)
E 41
		goto bad;
I 22
D 25
	linger = 60;			/* value ignored by system */
	(void) setsockopt(s, SOL_SOCKET, SO_LINGER, &linger, sizeof (linger));
E 25
E 22
E 15
D 4
	seteuid(0);
E 4
I 4
	seteuid(pw->pw_uid);
E 4
	return (fdopen(s, mode));
I 15
bad:
	seteuid(pw->pw_uid);
D 41
	close(s);
E 41
I 41
	(void) close(s);
E 41
	return (NULL);
E 15
}

FILE *
dataconn(name, size, mode)
	char *name;
D 20
	int size;
E 20
I 20
	off_t size;
E 20
	char *mode;
{
	char sizebuf[32];
	FILE *file;
I 20
	int retry = 0;
E 20

	if (size >= 0)
D 20
		sprintf(sizebuf, " (%d bytes)", size);
E 20
I 20
D 41
		sprintf (sizebuf, " (%ld bytes)", size);
E 41
I 41
		(void) sprintf (sizebuf, " (%ld bytes)", size);
E 41
E 20
	else
		(void) strcpy(sizebuf, "");
I 39
	if (pdata > 0) {
		struct sockaddr_in from;
		int s, fromlen = sizeof(from);

D 41
		s = accept(pdata, &from, &fromlen, 0);
E 41
I 41
		s = accept(pdata, &from, &fromlen);
E 41
		if (s < 0) {
			reply(425, "Can't open data connection.");
			(void) close(pdata);
			pdata = -1;
			return(NULL);
		}
		(void) close(pdata);
		pdata = s;
D 54
		reply(150, "Openning data connection for %s (%s,%d)%s.",
E 54
I 54
		reply(150, "Opening data connection for %s (%s,%d)%s.",
E 54
D 41
		     name, inet_ntoa(from.sin_addr.s_addr),
E 41
I 41
		     name, inet_ntoa(from.sin_addr),
E 41
		     ntohs(from.sin_port), sizebuf);
		return(fdopen(pdata, mode));
	}
E 39
	if (data >= 0) {
		reply(125, "Using existing data connection for %s%s.",
		    name, sizebuf);
I 7
		usedefault = 1;
E 7
		return (fdopen(data, mode));
	}
I 11
D 13
	/*
	 * If no PORT command was specified,
	 * use the default address.
	 */
	if (usedefault) {
E 13
I 13
	if (usedefault)
E 13
		data_dest = his_addr;
D 13
		data_dest.sin_port = htons(ntohs(sp->s_port) - 1);
	}
E 13
	usedefault = 1;
E 11
D 15
	reply(150, "Opening data connection for %s (%s,%d)%s.",
	    name, ntoa(data_dest.sin_addr.s_addr),
	    ntohs(data_dest.sin_port), sizebuf);
E 15
	file = getdatasock(mode);
	if (file == NULL) {
		reply(425, "Can't create data socket (%s,%d): %s.",
D 25
		    ntoa(data_source.sin_addr),
E 25
I 25
		    inet_ntoa(data_source.sin_addr),
E 25
		    ntohs(data_source.sin_port),
		    sys_errlist[errno]);
I 7
D 11
		usedefault = 1;
E 11
E 7
		return (NULL);
	}
I 15
D 44
	reply(150, "Opening data connection for %s (%s,%d)%s.",
D 25
	    name, ntoa(data_dest.sin_addr.s_addr),
E 25
I 25
D 41
	    name, inet_ntoa(data_dest.sin_addr.s_addr),
E 41
I 41
	    name, inet_ntoa(data_dest.sin_addr),
E 41
E 25
	    ntohs(data_dest.sin_port), sizebuf);
E 44
E 15
	data = fileno(file);
I 7
D 11
	/*
	 * If no PORT command was specified,
	 * use the default address.
	 */
	if (usedefault) {
		data_dest = his_addr;
		data_dest.sin_port = htons(ntohs(sp->s_port) - 1);
	}
D 8
	usedefault = 0;
E 8
I 8
	usedefault = 1;
E 11
E 8
E 7
D 20
	if (connect(data, &data_dest, sizeof (data_dest), 0) < 0) {
E 20
I 20
D 39
	while (connect(data, &data_dest, sizeof (data_dest), 0) < 0) {
E 39
I 39
	while (connect(data, &data_dest, sizeof (data_dest)) < 0) {
E 39
		if (errno == EADDRINUSE && retry < swaitmax) {
D 41
			sleep(swaitint);
E 41
I 41
			sleep((unsigned) swaitint);
E 41
			retry += swaitint;
			continue;
		}
E 20
		reply(425, "Can't build data connection: %s.",
		    sys_errlist[errno]);
		(void) fclose(file);
		data = -1;
		return (NULL);
	}
I 44
	reply(150, "Opening data connection for %s (%s,%d)%s.",
	    name, inet_ntoa(data_dest.sin_addr),
	    ntohs(data_dest.sin_port), sizebuf);
E 44
	return (file);
}

/*
 * Tranfer the contents of "instr" to
 * "outstr" peer using the appropriate
 * encapulation of the date subject
 * to Mode, Structure, and Type.
 *
 * NB: Form isn't handled.
 */
send_data(instr, outstr)
	FILE *instr, *outstr;
{
	register int c;
	int netfd, filefd, cnt;
	char buf[BUFSIZ];

I 39
	transflag++;
	if (setjmp(urgcatch)) {
		transflag = 0;
		return(-1);
	}
E 39
	switch (type) {

	case TYPE_A:
		while ((c = getc(instr)) != EOF) {
D 18
			if (c == '\n')
E 18
I 18
			if (c == '\n') {
D 39
				if (ferror (outstr))
E 39
I 39
				if (ferror (outstr)) {
					transflag = 0;
E 39
					return (1);
I 39
				}
E 39
E 18
D 44
				putc('\r', outstr);
E 44
I 44
				(void) putc('\r', outstr);
E 44
D 18
			if (putc(c, outstr) == EOF)
				return (1);
E 18
I 18
			}
D 44
			putc(c, outstr);
E 44
I 44
			(void) putc(c, outstr);
E 44
D 39
			if (c == '\r')
				putc ('\0', outstr);
E 39
I 39
		/*	if (c == '\r')			*/
		/*		putc ('\0', outstr);	*/
E 39
E 18
		}
I 18
D 39
		if (ferror (instr) || ferror (outstr))
E 39
I 39
		transflag = 0;
		if (ferror (instr) || ferror (outstr)) {
E 39
			return (1);
I 39
		}
E 39
E 18
		return (0);
		
	case TYPE_I:
	case TYPE_L:
		netfd = fileno(outstr);
		filefd = fileno(instr);

D 2
		while ((cnt = read(filefd, buf, sizeof buf)) > 0)
E 2
I 2
D 39
		while ((cnt = read(filefd, buf, sizeof (buf))) > 0)
E 2
			if (write(netfd, buf, cnt) < 0)
E 39
I 39
		while ((cnt = read(filefd, buf, sizeof (buf))) > 0) {
			if (write(netfd, buf, cnt) < 0) {
				transflag = 0;
E 39
				return (1);
I 39
			}
		}
		transflag = 0;
E 39
		return (cnt < 0);
	}
D 43
	reply(504,"Unimplemented TYPE %d in send_data", type);
E 43
I 43
	reply(550, "Unimplemented TYPE %d in send_data", type);
E 43
I 39
	transflag = 0;
E 39
D 43
	return (1);
E 43
I 43
	return (-1);
E 43
}

/*
 * Transfer data from peer to
 * "outstr" using the appropriate
 * encapulation of the data subject
 * to Mode, Structure, and Type.
 *
 * N.B.: Form isn't handled.
 */
receive_data(instr, outstr)
	FILE *instr, *outstr;
{
	register int c;
D 16
	int cr, escape, eof;
	int netfd, filefd, cnt;
E 16
I 16
D 18
	int cr, escape, eof, cnt;
E 18
I 18
	int cnt;
E 18
E 16
	char buf[BUFSIZ];


I 39
	transflag++;
	if (setjmp(urgcatch)) {
		transflag = 0;
		return(-1);
	}
E 39
	switch (type) {

	case TYPE_I:
	case TYPE_L:
D 16
		netfd = fileno(instr);
		netfd = fileno(outstr);
		while ((cnt = read(netfd, buf, sizeof buf)) > 0)
			if (write(filefd, buf, cnt) < 0)
E 16
I 16
D 39
		while ((cnt = read(fileno(instr), buf, sizeof buf)) > 0)
			if (write(fileno(outstr), buf, cnt) < 0)
E 39
I 39
		while ((cnt = read(fileno(instr), buf, sizeof buf)) > 0) {
			if (write(fileno(outstr), buf, cnt) < 0) {
				transflag = 0;
E 39
E 16
				return (1);
I 39
			}
		}
		transflag = 0;
E 39
		return (cnt < 0);

	case TYPE_E:
D 43
		reply(504, "TYPE E not implemented.");
E 43
I 43
		reply(553, "TYPE E not implemented.");
E 43
I 39
		transflag = 0;
E 39
D 43
		return (1);
E 43
I 43
		return (-1);
E 43

	case TYPE_A:
D 18
		cr = 0;
E 18
		while ((c = getc(instr)) != EOF) {
D 18
			if (cr) {
				if (c != '\r' && c != '\n')
					putc('\r', outstr);
				putc(c, outstr);
				cr = c == '\r';
				continue;
			}
E 18
D 44
			if (c == '\r') {
E 44
I 44
			while (c == '\r') {
E 44
D 18
				cr = 1;
				continue;
E 18
I 18
D 39
				if (ferror (outstr))
E 39
I 39
				if (ferror (outstr)) {
					transflag = 0;
E 39
					return (1);
I 39
				}
E 39
				if ((c = getc(instr)) != '\n')
D 44
					putc ('\r', outstr);
E 44
I 44
					(void) putc ('\r', outstr);
E 44
D 39
				if (c == '\0')
					continue;
E 39
I 39
			/*	if (c == '\0')			*/
			/*		continue;		*/
E 39
E 18
			}
D 18
			putc(c, outstr);
E 18
I 18
D 44
			putc (c, outstr);
E 44
I 44
			(void) putc (c, outstr);
E 44
E 18
		}
I 39
		transflag = 0;
E 39
D 18
		if (cr)
			putc('\r', outstr);
E 18
I 18
		if (ferror (instr) || ferror (outstr))
			return (1);
E 18
		return (0);
	}
I 39
	transflag = 0;
E 39
	fatal("Unknown type in receive_data.");
	/*NOTREACHED*/
}

fatal(s)
	char *s;
{
	reply(451, "Error in server: %s\n", s);
	reply(221, "Closing connection due to server error.");
D 25
	exit(0);
E 25
I 25
	dologout(0);
E 25
}

I 41
D 48
/*VARARGS2*/
E 41
reply(n, s, args)
E 48
I 48
D 52
reply(n, s, p0, p1, p2, p3, p4)
E 52
I 52
reply(n, s, p0, p1, p2, p3, p4, p5)
E 52
E 48
	int n;
	char *s;
{

	printf("%d ", n);
D 48
	_doprnt(s, &args, stdout);
E 48
I 48
D 52
	printf(s, p0, p1, p2, p3, p4);
E 52
I 52
	printf(s, p0, p1, p2, p3, p4, p5);
E 52
E 48
	printf("\r\n");
D 41
	fflush(stdout);
E 41
I 41
	(void) fflush(stdout);
E 41
	if (debug) {
D 41
		fprintf(stderr, "<--- %d ", n);
		_doprnt(s, &args, stderr);
		fprintf(stderr, "\n");
		fflush(stderr);
E 41
I 41
		syslog(LOG_DEBUG, "<--- %d ", n);
D 48
		syslog(LOG_DEBUG, s, &args);
E 48
I 48
D 52
		syslog(LOG_DEBUG, s, p0, p1, p2, p3, p4);
E 52
I 52
		syslog(LOG_DEBUG, s, p0, p1, p2, p3, p4, p5);
E 52
E 48
E 41
	}
}

I 41
D 48
/*VARARGS2*/
E 41
lreply(n, s, args)
E 48
I 48
D 52
lreply(n, s, p0, p1, p2, p3, p4)
E 52
I 52
lreply(n, s, p0, p1, p2, p3, p4, p5)
E 52
E 48
	int n;
	char *s;
{
	printf("%d-", n);
D 48
	_doprnt(s, &args, stdout);
E 48
I 48
D 52
	printf(s, p0, p1, p2, p3, p4);
E 52
I 52
	printf(s, p0, p1, p2, p3, p4, p5);
E 52
E 48
	printf("\r\n");
D 41
	fflush(stdout);
E 41
I 41
	(void) fflush(stdout);
E 41
	if (debug) {
D 41
		fprintf(stderr, "<--- %d-", n);
		_doprnt(s, &args, stderr);
		fprintf(stderr, "\n");
E 41
I 41
		syslog(LOG_DEBUG, "<--- %d- ", n);
D 48
		syslog(LOG_DEBUG, s, &args);
E 48
I 48
D 52
		syslog(LOG_DEBUG, s, p0, p1, p2, p3, p4);
E 52
I 52
		syslog(LOG_DEBUG, s, p0, p1, p2, p3, p4, p5);
E 52
E 48
E 41
	}
}

I 41
D 43
/*  NOT CALLED ANYWHERE
E 41
replystr(s)
	char *s;
{
	printf("%s\r\n", s);
D 41
	fflush(stdout);
E 41
I 41
	(void) fflush(stdout);
E 41
	if (debug)
		fprintf(stderr, "<--- %s\n", s);
}
I 41
*/
E 41

E 43
ack(s)
	char *s;
{
D 39
	reply(200, "%s command okay.", s);
E 39
I 39
D 43
	reply(200, "%s command successful.", s);
E 43
I 43
	reply(250, "%s command successful.", s);
E 43
E 39
}

nack(s)
	char *s;
{
	reply(502, "%s command not implemented.", s);
}

D 41
yyerror()
E 41
I 41
yyerror(s)
	char *s;
E 41
{
D 39
	reply(500, "Command not understood.");
E 39
I 39
	char *cp;

	cp = index(cbuf,'\n');
	*cp = '\0';
	reply(500, "'%s': command not understood.",cbuf);
E 39
}

delete(name)
	char *name;
{
	struct stat st;

I 59
	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550, "Guest users are not allowed to delete files.");
		return;
	}
E 59
I 54
D 62
	if (guest && guestdirs != NULL && guest_check_pathname(name)) {
E 62
I 62
	if (guestdirs != NULL && guest_check_pathname(name)) {
E 62
		reply(550, "%s: %s.", name, sys_errlist[EACCES]);
		return;
	}
E 54
	if (stat(name, &st) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
	if ((st.st_mode&S_IFMT) == S_IFDIR) {
		if (rmdir(name) < 0) {
			reply(550, "%s: %s.", name, sys_errlist[errno]);
			return;
		}
		goto done;
	}
	if (unlink(name) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
done:
	ack("DELE");
}

cwd(path)
	char *path;
{
D 54

E 54
I 54
D 62
	if (guest && guestdirs != NULL && guest_check_pathname(path)) {
E 62
I 62
	if (guestdirs != NULL && guest_check_pathname(path)) {
E 62
		reply(550, "%s: %s.", path, sys_errlist[EACCES]);
		return;
	}
E 54
	if (chdir(path) < 0) {
		reply(550, "%s: %s.", path, sys_errlist[errno]);
		return;
	}
	ack("CWD");
}

D 2
do_mkdir(name)
E 2
I 2
makedir(name)
E 2
	char *name;
{
I 2
D 54
	struct stat st;
	int dochown = stat(name, &st) < 0;
E 2
	
E 54
I 54
D 59
	if (guest && guestdirs != NULL && guest_check_pathname(name)) {
		reply(550, "%s: %s.", name, sys_errlist[EACCES]);
E 59
I 59
	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550,
			"Guest users are not allowed to create directories.");
E 59
		return;
	}
E 54
	if (mkdir(name, 0777) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
I 2
D 54
	if (dochown)
		(void) chown(name, pw->pw_uid, -1);
E 54
I 54
	(void) chown(name, pw->pw_uid, -1);
E 54
E 2
D 43
	ack("MKDIR");
E 43
I 43
	reply(257, "MKD command successful.");
E 43
}

D 2
do_rmdir(name)
E 2
I 2
removedir(name)
E 2
	char *name;
{
D 54

E 54
I 54
D 59
	if (guest && guestdirs != NULL && guest_check_pathname(name)) {
		reply(550, "%s: %s.", name, sys_errlist[EACCES]);
E 59
I 59
	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550,
			"Guest users are not allowed to delete directories.");
E 59
		return;
	}
E 54
	if (rmdir(name) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return;
	}
D 43
	ack("RMDIR");
E 43
I 43
	ack("RMD");
E 43
}

D 2
do_pwd()
E 2
I 2
pwd()
E 2
{
D 2
	char path[1024];
E 2
I 2
D 54
	char path[MAXPATHLEN + 1];
E 54
I 54
	char path[MAXPATHLEN];
E 54
E 2
D 20
	char *p;
E 20

	if (getwd(path) == NULL) {
D 43
		reply(451, "%s.", path);
E 43
I 43
		reply(550, "%s.", path);
E 43
		return;
	}
D 43
	reply(251, "\"%s\" is current directory.", path);
E 43
I 43
	reply(257, "\"%s\" is current directory.", path);
E 43
}

char *
renamefrom(name)
	char *name;
{
	struct stat st;

I 54
D 59
	if (guest && guestdirs != NULL && guest_check_pathname(name)) {
		reply(550, "%s: %s.", name, sys_errlist[EACCES]);
		return ((char *)0);
E 59
I 59
	if (authmode == AUTHMODE_GUEST || authmode == AUTHMODE_EPS) {
		reply(550, "Guest users are not allowed to rename files.");
		return;
E 59
	}
E 54
	if (stat(name, &st) < 0) {
		reply(550, "%s: %s.", name, sys_errlist[errno]);
		return ((char *)0);
	}
D 2
	ack("RNFR");
E 2
I 2
	reply(350, "File exists, ready for destination name");
E 2
	return (name);
}

renamecmd(from, to)
	char *from, *to;
{
D 54

E 54
I 54
D 59
	if (guest && guestdirs != NULL && guest_check_pathname(to)) {
		reply(550, "%s: %s.", to, sys_errlist[EACCES]);
		return;
	}
E 59
E 54
	if (rename(from, to) < 0) {
		reply(550, "rename: %s.", sys_errlist[errno]);
		return;
	}
	ack("RNTO");
D 20
}

int guest;
/*
 * Test pathname for guest-user safety.
 */
inappropriate_request(name)
	char *name;
{
	int bogus = 0, depth = 0, length = strlen(name);
	char *p, *s;

	if (!guest)
		return (0);
	if (name[0] == '/' || name[0] == '|')
		bogus = 1;
	for (p = name; p < name+length;) {
		s = p;				/* start of token */
		while ( *p && *p!= '/')
			p++;
		*p = 0;
		if (strcmp(s, "..") == 0)
			depth -= 1;		/* backing up */
		else if (strcmp(s, ".") == 0)
			depth += 0;		/* no change */
		else
			depth += 1;		/* descending */
		if (depth < 0) {
			bogus = 1;
			break;
		}
	}
	if (bogus)
		reply(553, "%s: pathname disallowed guest users", name);
	return (bogus);
E 20
}

D 25
/*
 * Convert network-format internet address
 * to base 256 d.d.d.d representation.
 */
char *
ntoa(in)
	struct in_addr in;
{
	static char b[18];
	register char *p;

D 18
	in.s_addr = ntohl(in.s_addr);
E 18
	p = (char *)&in;
#define	UC(b)	(((int)b)&0xff)
	sprintf(b, "%d.%d.%d.%d", UC(p[0]), UC(p[1]), UC(p[2]), UC(p[3]));
	return (b);
}

E 25
dolog(sin)
	struct sockaddr_in *sin;
{
	struct hostent *hp = gethostbyaddr(&sin->sin_addr,
		sizeof (struct in_addr), AF_INET);
D 25
	char *remotehost;
E 25
	time_t t;
I 41
	extern char *ctime();
E 41

D 25
	if (hp)
		remotehost = hp->h_name;
	else
D 23
		remotehost = "UNKNOWNHOST";
E 23
I 23
		remotehost = inet_ntoa(sin->sin_addr);
E 25
I 25
	if (hp) {
D 41
		strncpy(remotehost, hp->h_name, sizeof (remotehost));
E 41
I 41
		(void) strncpy(remotehost, hp->h_name, sizeof (remotehost));
E 41
		endhostent();
	} else
D 41
		strncpy(remotehost, inet_ntoa(sin->sin_addr),
E 41
I 41
		(void) strncpy(remotehost, inet_ntoa(sin->sin_addr),
E 41
		    sizeof (remotehost));
	if (!logging)
		return;
E 25
E 23
D 41
	t = time(0);
D 2
	fprintf(stderr,"FTP %d: connection from %s at %s",
		getpid(), remotehost, ctime(&t));
E 2
I 2
D 21
	fprintf(stderr,"FTP: connection from %s at %s", remotehost, ctime(&t));
E 21
I 21
	fprintf(stderr,"FTPD: connection from %s at %s", remotehost, ctime(&t));
E 21
E 2
	fflush(stderr);
E 41
I 41
	t = time((time_t *) 0);
	syslog(LOG_INFO,"FTPD: connection from %s at %s", remotehost, ctime(&t));
E 41
I 25
}

#include <utmp.h>

D 41
#define	SCPYN(a, b)	strncpy(a, b, sizeof (a))
E 41
I 41
#define	SCPYN(a, b)	(void) strncpy(a, b, sizeof (a))
E 41
struct	utmp utmp;

/*
 * Record login in wtmp file.
 */
dologin(pw)
	struct passwd *pw;
{
D 31
	int wtmp;
E 31
	char line[32];

D 31
	wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
E 31
I 31
D 33
	if (guest && (wtmp >= 0))
		lseek(wtmp, 0, L_XTND);
	else
		wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
E 33
E 31
	if (wtmp >= 0) {
		/* hack, but must be unique and no tty line */
D 41
		sprintf(line, "ftp%d", getpid());
E 41
I 41
		(void) sprintf(line, "ftp%d", getpid());
E 41
		SCPYN(utmp.ut_line, line);
		SCPYN(utmp.ut_name, pw->pw_name);
		SCPYN(utmp.ut_host, remotehost);
D 41
		utmp.ut_time = time(0);
E 41
I 41
		utmp.ut_time = (long) time((time_t *) 0);
E 41
		(void) write(wtmp, (char *)&utmp, sizeof (utmp));
D 31
		(void) close(wtmp);
E 31
I 31
D 32
		if (!guest)
			(void) close(wtmp);
E 32
I 32
D 33
		(void) close(wtmp);
E 33
I 33
D 62
		if (!guest) {		/* anon must hang on */
E 62
I 62
		if (!chrooted) {		/* anon must hang on */
E 62
			(void) close(wtmp);
			wtmp = -1;
		}
E 33
E 32
E 31
	}
}

/*
 * Record logout in wtmp file
 * and exit with supplied status.
 */
dologout(status)
	int status;
{
I 32
D 59

E 32
D 31
	int wtmp;

E 31
D 35
	if (!logged_in)
D 29
		return;
E 29
I 29
D 32
		_exit(status);
E 32
I 32
		return;
E 32
E 29
	seteuid(0);
D 31
	wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
E 31
I 31
D 33
	if (guest && (wtmp >= 0))
		lseek(wtmp, 0, L_XTND);
	else
E 33
I 33
	if (wtmp < 0)
E 33
		wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
E 31
	if (wtmp >= 0) {
		SCPYN(utmp.ut_name, "");
		SCPYN(utmp.ut_host, "");
		utmp.ut_time = time(0);
		(void) write(wtmp, (char *)&utmp, sizeof (utmp));
		(void) close(wtmp);
E 35
I 35
	if (logged_in) {
E 59
I 59
	if (logged_in && authmode != AUTHMODE_EPS) {
E 59
I 54
		if (guestdirs)
			free_guest_dirs();
E 54
		(void) seteuid(0);
		if (wtmp < 0)
			wtmp = open("/usr/adm/wtmp", O_WRONLY|O_APPEND);
		if (wtmp >= 0) {
			SCPYN(utmp.ut_name, "");
			SCPYN(utmp.ut_host, "");
D 41
			utmp.ut_time = time(0);
E 41
I 41
			utmp.ut_time = (long) time((time_t *) 0);
E 41
			(void) write(wtmp, (char *)&utmp, sizeof (utmp));
			(void) close(wtmp);
		}
E 35
	}
D 28
	exit(status);
E 28
I 28
	/* beware of flushing buffers after a SIGPIPE */
	_exit(status);
E 28
E 25
I 17
}

/*
 * Special version of popen which avoids
 * call to shell.  This insures noone may 
 * create a pipe to a hidden program as a side
 * effect of a list or dir command.
I 55
 *
 * This version is also more efficient and
 * convenient for us as it takes ready argv,
 * which is what globbing gives us.
E 55
 */
#define	tst(a,b)	(*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1
D 58
static	int popen_pid[5];
E 58
I 58
static	int popen_pid[20];
E 58

D 55
static char *
nextarg(cpp)
	char *cpp;
{
	register char *cp = cpp;

	if (cp == 0)
		return (cp);
	while (*cp && *cp != ' ' && *cp != '\t')
		cp++;
	if (*cp == ' ' || *cp == '\t') {
		*cp++ = '\0';
		while (*cp == ' ' || *cp == '\t')
			cp++;
	}
	if (cp == cpp)
		return ((char *)0);
	return (cp);
}

E 55
FILE *
D 55
popen(cmd, mode)
	char *cmd, *mode;
E 55
I 55
mypopen(cmd, argv, mode)
	char *cmd, **argv, *mode;
E 55
{
D 24
	int p[2], ac;
E 24
I 24
D 55
	int p[2], ac, gac;
E 55
I 55
	int p[2];
E 55
E 24
	register myside, hisside, pid;
D 21
	char *av[10];
E 21
I 21
D 24
	char *av[512];
	char **pop, **popargs = NULL;
	extern char **glob();
E 24
I 24
D 55
	char *av[20], *gav[512];
E 55
E 24
E 21
	register char *cp;

	if (pipe(p) < 0)
		return (NULL);
D 55
	cp = cmd, ac = 0;
I 24
	/* break up string into pieces */
E 24
	do {
		av[ac++] = cp;
		cp = nextarg(cp);
D 24
	} while (cp && *cp);
E 24
I 24
	} while (cp && *cp && ac < 20);
E 24
	av[ac] = (char *)0;
I 21
D 24
	if (ac > 1) {
		popargs = glob(&av[1]);
		if (popargs == NULL)
			return (NULL);
		for (ac = 1, pop = popargs; *pop;) 
			av[ac++] = *pop++;
E 24
I 24
	gav[0] = av[0];
	/* glob each piece */
	for (gac = ac = 1; av[ac] != NULL; ac++) {
		char **pop;
D 37
		extern char **glob();
E 37
I 37
		extern char **glob(), **copyblk();
E 37

		pop = glob(av[ac]);
D 37
		if (pop) {
			av[ac] = (char *)pop;		/* save to free later */
			while (*pop && gac < 512)
				gav[gac++] = *pop++;
E 37
I 37
		if (pop == (char **)NULL) {	/* globbing failed */
			char *vv[2];

			vv[0] = av[ac];
			vv[1] = 0;
			pop = copyblk(vv);
E 37
		}
I 37
		av[ac] = (char *)pop;		/* save to free later */
		while (*pop && gac < 512)
			gav[gac++] = *pop++;
E 37
E 24
	}
D 24
	av[ac] = (char *)0;
E 24
I 24
	gav[gac] = (char *)0;
E 55
E 24
E 21
	myside = tst(p[WTR], p[RDR]);
	hisside = tst(p[RDR], p[WTR]);
D 55
	if ((pid = fork()) == 0) {
E 55
I 55
	if ((pid = vfork()) == 0) {
E 55
		/* myside and hisside reverse roles in child */
D 41
		close(myside);
		dup2(hisside, tst(0, 1));
		close(hisside);
E 41
I 41
		(void) close(myside);
		(void) dup2(hisside, tst(0, 1));
		(void) close(hisside);
E 41
D 24
		execv(av[0], av);
E 24
I 24
D 55
		execv(gav[0], gav);
E 55
I 55
		execv(cmd, argv);
E 55
E 24
		_exit(1);
	}
I 21
D 24
	if (popargs != NULL)
		blkfree(popargs);
E 24
I 24
D 55
	for (ac = 1; av[ac] != NULL; ac++)
		blkfree((char **)av[ac]);
E 55
E 24
E 21
	if (pid == -1)
		return (NULL);
	popen_pid[myside] = pid;
D 41
	close(hisside);
E 41
I 41
	(void) close(hisside);
E 41
	return (fdopen(myside, mode));
}

D 55
pclose(ptr)
E 55
I 55
mypclose(ptr)
E 55
	FILE *ptr;
{
	register f, r, (*hstat)(), (*istat)(), (*qstat)();
	int status;

	f = fileno(ptr);
D 41
	fclose(ptr);
E 41
I 41
	(void) fclose(ptr);
E 41
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	hstat = signal(SIGHUP, SIG_IGN);
	while ((r = wait(&status)) != popen_pid[f] && r != -1)
		;
	if (r == -1)
		status = -1;
D 41
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	signal(SIGHUP, hstat);
E 41
I 41
	(void) signal(SIGINT, istat);
	(void) signal(SIGQUIT, qstat);
	(void) signal(SIGHUP, hstat);
E 41
	return (status);
}

/*
 * Check user requesting login priviledges.
I 45
 * Disallow anyone who does not have a standard
 * shell returned by getusershell() (/etc/shells).
E 45
 * Disallow anyone mentioned in the file FTPUSERS
 * to allow people such as uucp to be avoided.
 */
checkuser(name)
	register char *name;
{
D 45
	char line[BUFSIZ], *index();
E 45
I 45
	register char *cp;
D 54
	char line[BUFSIZ], *index(), *getusershell();
E 54
I 54
	char line[BUFSIZ], *getusershell();
E 54
E 45
	FILE *fd;
I 45
D 59
	struct passwd *pw;
E 59
E 45
	int found = 0;

I 45
D 59
	pw = getpwnam(name);
	if (pw == NULL)
		return (0);
E 59
I 46
	if (pw ->pw_shell == NULL || pw->pw_shell[0] == NULL)
		pw->pw_shell = "/bin/sh";
E 46
	while ((cp = getusershell()) != NULL)
		if (strcmp(cp, pw->pw_shell) == 0)
			break;
D 46
	endpwent();
E 46
	endusershell();
	if (cp == NULL)
		return (0);
E 45
	fd = fopen(FTPUSERS, "r");
	if (fd == NULL)
		return (1);
	while (fgets(line, sizeof (line), fd) != NULL) {
D 45
		register char *cp = index(line, '\n');

E 45
I 45
		cp = index(line, '\n');
E 45
		if (cp)
			*cp = '\0';
		if (strcmp(line, name) == 0) {
			found++;
			break;
		}
	}
D 41
	fclose(fd);
E 41
I 41
	(void) fclose(fd);
E 41
	return (!found);
I 39
}

myoob()
{
D 40
	char mark, *cp;
	int aflag = 0, count = 0, iacflag = 0, c;
E 40
I 40
D 41
	int aflag = 0, count = 0, iacflag = 0, atmark;
E 41
I 41
D 44
	int aflag = 0, atmark;
E 41
	char c, *cp;
E 44
I 44
	char *cp;
E 44
E 40

I 44
	/* only process if transfer occurring */
E 44
	if (!transflag) {
D 44
		for (;;) {
D 40
			if (ioctl(fileno(stdin), SIOCATMARK, &mark) < 0) {
E 40
I 40
D 41
			if (ioctl(fileno(stdin), SIOCATMARK, &atmark) < 0) {
E 40
				perror("ioctl");
E 41
I 41
			if (ioctl(fileno(stdin), (int) SIOCATMARK, (char *) &atmark) < 0) {
				syslog(LOG_ERR, "ioctl: %m");
E 41
				break;
			}
D 40
			if (mark) {
E 40
I 40
			if (atmark)
E 40
				break;
D 40
			}
			read(fileno(stdin), &mark, 1);
			c = 0377 & mark;
E 40
I 40
D 41
			read(fileno(stdin), &c, 1);
E 41
I 41
			(void) read(fileno(stdin), &c, 1);
E 41
E 40
		}
D 40
		recv(fileno(stdin), &mark, 1, MSG_OOB);
		c = 0377 & mark;
		read(fileno(stdin), &mark, 1);
E 40
I 40
D 41
		recv(fileno(stdin), &c, 1, MSG_OOB);
		read(fileno(stdin), &c, 1);
E 41
I 41
		(void) recv(fileno(stdin), &c, 1, MSG_OOB);
		(void) read(fileno(stdin), &c, 1);
E 44
E 41
E 40
		return;
	}
D 44
	for (;;) {
D 40
		if (ioctl(fileno(stdin), SIOCATMARK, &mark) < 0) {
E 40
I 40
D 41
		if (ioctl(fileno(stdin), SIOCATMARK, &atmark) < 0) {
E 40
			perror("ioctl");
E 41
I 41
		if (ioctl(fileno(stdin), (int) SIOCATMARK, (char *) &atmark) < 0) {
			syslog(LOG_ERR, "ioctl: %m");
E 41
			break;
		}
D 40
		if (mark) {
E 40
I 40
		if (atmark)
E 40
			break;
D 40
		}
		read(fileno(stdin), &mark, 1);
		c = 0377 & mark;
		if (c == IAC) {
E 40
I 40
D 41
		read(fileno(stdin), &c, 1);
E 41
I 41
		(void) read(fileno(stdin), &c, 1);
E 41
		if (c == IAC || c == IP)
E 40
			aflag++;
D 40
		}
		else if (c == IP) {
			aflag++;
		}
E 40
	}
D 40
	recv(fileno(stdin), &mark, 1, MSG_OOB);
	c = 0377 & mark;
	if (c == IAC) {
E 40
I 40
D 41
	recv(fileno(stdin), &c, 1, MSG_OOB);
E 41
I 41
	(void) recv(fileno(stdin), &c, 1, MSG_OOB);
E 41
	if (c == IAC)
E 40
		aflag++;
D 40
	}
	read(fileno(stdin), &mark, 1);
	c = 0377 & mark;
	if (c == DM) {
E 40
I 40
D 41
	read(fileno(stdin), &c, 1);
E 41
I 41
	(void) read(fileno(stdin), &c, 1);
E 41
	if (c == DM)
E 40
		aflag++;
D 40
	}
	if (aflag != 4) {
E 40
I 40
	if (aflag != 4)
E 40
		return;
E 44
D 40
	}
E 40
	cp = tmpline;
D 44
	(void) getline(cp, 7, stdin);
E 44
I 44
	if (getline(cp, 7, stdin) == NULL) {
D 54
		reply(221, "You could at least say goodby.");
E 54
I 54
		reply(221, "You could at least say goodbye.");
E 54
		dologout(0);
	}
E 44
	upper(cp);
D 40
	if (strcmp(cp, "ABOR\r\n")) {
E 40
I 40
	if (strcmp(cp, "ABOR\r\n"))
E 40
		return;
D 40
	}
E 40
	tmpline[0] = '\0';
	reply(426,"Transfer aborted. Data connection closed.");
	reply(226,"Abort successful");
	longjmp(urgcatch, 1);
}

I 43
/*
 * Note: The 530 reply codes could be 4xx codes, except nothing is
 * given in the state tables except 421 which implies an exit.  (RFC959)
 */
E 43
passive()
{
	int len;
	struct sockaddr_in tmp;
	register char *p, *a;

	pdata = socket(AF_INET, SOCK_STREAM, 0);
	if (pdata < 0) {
D 43
		reply(451, "Can't open passive connection");
E 43
I 43
		reply(530, "Can't open passive connection");
E 43
		return;
	}
	tmp = ctrl_addr;
	tmp.sin_port = 0;
	seteuid(0);
D 41
	if (bind(pdata, (char *) &tmp, sizeof(tmp), 0) < 0) {
E 41
I 41
	if (bind(pdata, (struct sockaddr *) &tmp, sizeof(tmp)) < 0) {
E 41
		seteuid(pw->pw_uid);
		(void) close(pdata);
		pdata = -1;
D 43
		reply(451, "Can't open passive connection");
E 43
I 43
		reply(530, "Can't open passive connection");
E 43
		return;
	}
	seteuid(pw->pw_uid);
	len = sizeof(tmp);
	if (getsockname(pdata, (char *) &tmp, &len) < 0) {
		(void) close(pdata);
		pdata = -1;
D 43
		reply(451, "Can't open passive connection");
E 43
I 43
		reply(530, "Can't open passive connection");
E 43
		return;
	}
	if (listen(pdata, 1) < 0) {
		(void) close(pdata);
		pdata = -1;
D 43
		reply(451, "Can't open passive connection");
E 43
I 43
		reply(530, "Can't open passive connection");
E 43
		return;
	}
	a = (char *) &tmp.sin_addr;
	p = (char *) &tmp.sin_port;

#define UC(b) (((int) b) & 0xff)

	reply(227, "Entering Passive Mode (%d,%d,%d,%d,%d,%d)", UC(a[0]),
		UC(a[1]), UC(a[2]), UC(a[3]), UC(p[0]), UC(p[1]));
}

D 54
char *
gunique(local)
	char *local;
E 54
I 54
/*
 * The following functions implement the logic for restricting the set of
 * directories that anonymous users can access to less than all world-readable
 * directories without chrooting. This is accomplished by listing the allowed
 * directories in /etc/anonftp.allow as absolute pathnames. Their parent
 * directories are also necessarily accessible, as are their subdirectories,
 * unless the listed pathname ends with a slash. All files in an accessible
 * directory are also accessible. However, directories that are not children of
 * an explicitly listed allowed directory, but are children of a parent
 * directory of one, are NOT accessible.
 */

init_guest_dirs()
E 54
{
D 54
	static char new[MAXPATHLEN];
	char *cp = rindex(local, '/');
	int d, count=0;
	char ext = '1';
E 54
I 54
	FILE *fd;
	int nalloc;
	char line[MAXPATHLEN + 1];
E 54

D 54
	if (cp) {
		*cp = '\0';
E 54
I 54
	fd = fopen(ANONFTPALLOW, "r");
	if (fd == NULL)
		return;
	guestdirs = (char **) malloc(sizeof(char *) * GUESTDIRSINCR);
	if (guestdirs == NULL)
		return;
	bzero((char *) guestdirs, sizeof(char *) * GUESTDIRSINCR);
	nguestdirs = 0;
	nalloc = GUESTDIRSINCR;
	while (fgets(line, sizeof(line), fd) != NULL) {
		char *copy, *cp;

		cp = index(line, '\n');
		if (cp)
			*cp = '\0';
		else
			break;
		if (line[0] != '/')
			continue;
		if (nguestdirs == nalloc) {
			guestdirs = (char **) realloc((char *) guestdirs,
					sizeof(char *) *
					(nalloc + GUESTDIRSINCR));
			if (guestdirs == NULL)
				break;
			bzero((char *) guestdirs + sizeof(char *) * nalloc,
			      sizeof(char *) * GUESTDIRSINCR);
			nalloc += GUESTDIRSINCR;
		}
		copy = malloc(strlen(line) + 1);
		if (copy == NULL)
			break;
		strcpy(copy, line);
		guestdirs[nguestdirs++] = copy;
E 54
	}
D 54
	d = access(cp ? local : ".", 2);
	if (cp) {
		*cp = '/';
E 54
I 54
	(void) fclose(fd);
}

free_guest_dirs()
{
	int i;

	for (i = 0; i < nguestdirs; i++)
		free(guestdirs[i]);
	free((char *) guestdirs);
	guestdirs = NULL;
}

guest_check_curdir()
{
	char curdir[MAXPATHLEN];
	int i;

	getwd(curdir);
	if (!strcmp(curdir, "/"))
		return(0);
	for (i = 0; i < nguestdirs; i++) {
		char *cp1 = curdir, *cp2 = guestdirs[i];

		while (*cp1 == *cp2 && *cp1 != '\0')
			cp1++, cp2++;
		if (*cp1 == '\0' && *cp2 == '\0')
			return(0);
		if (*cp1 == '\0' && *cp2 == '/')
			return(0);
		if (*cp1 == '/' && *cp2 == '\0')
			return(0);
E 54
	}
D 54
	if (d < 0) {
D 41
		perror(local);
E 41
I 41
		syslog(LOG_ERR, "%s: %m", local);
E 41
		return((char *) 0);
	}
	(void) strcpy(new, local);
	cp = new + strlen(new);
	*cp++ = '.';
	while (!d) {
		if (++count == 100) {
D 43
			reply(451, "Unique file name not cannot be created.");
E 43
I 43
			reply(452, "Unique file name not cannot be created.");
E 43
			return((char *) 0);
		}
		*cp++ = ext;
		*cp = '\0';
		if (ext == '9') {
			ext = '0';
		}
		else {
			ext++;
		}
		if ((d = access(new, 0)) < 0) {
E 54
I 54
	return(1);
}

guest_check_pathname(pathname)
	char *pathname;
{
	char origdir[MAXPATHLEN];
	char *comp, *slash;
	int status;

	getwd(origdir);
	if (pathname[0] == '/')
		chdir("/");
	for (comp = pathname; ; comp = slash) {
		while (*comp == '/')
			comp++;
		if (*comp == '\0')
E 54
			break;
I 54
		slash = index(comp, '/');
		if (slash != NULL)
			*slash = '\0';
		status = chdir(comp);
		if (slash != NULL)
			*slash = '/';
		if (status)
			break;
		if (guest_check_curdir()) {
			chdir(origdir);
			return(1);
E 54
		}
D 54
		if (ext != '0') {
			cp--;
		}
		else if (*(cp - 2) == '.') {
			*(cp - 1) = '1';
		}
		else {
			*(cp - 2) = *(cp - 2) + 1;
			cp--;
		}
E 54
I 54
		if (slash == NULL)
			break;
E 54
	}
D 54
	return(new);
E 54
I 54
	chdir(origdir);
	return(0);
E 54
E 39
E 17
}
E 1
