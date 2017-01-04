h27144
s 00010/00005/01495
d D 5.19 88/06/29 20:34:17 bostic 36 35
c install approved copyright notice
e
s 00002/00002/01498
d D 5.18 88/03/23 10:14:41 csvsj 35 34
c correct disconnection processing when not in verbose mode
e
s 00009/00003/01491
d D 5.17 88/03/14 17:21:33 bostic 34 33
c add Berkeley specific headers
e
s 00002/00002/01492
d D 5.16 88/01/02 23:32:53 bostic 33 32
c fix external declarations; ANSI C compatibility
e
s 00001/00001/01493
d D 5.15 87/04/23 14:01:30 csvsj 32 31
c fix reset loop if control connection gone
e
s 00007/00004/01487
d D 5.14 86/05/22 16:07:16 karels 31 30
c don't dereference null pointer
e
s 00001/00001/01490
d D 5.13 86/05/06 21:20:51 minshall 30 29
c Correctly filter \r\r\n during ascii receives (from Steve Jacobson).
e
s 00084/00076/01407
d D 5.12 86/05/02 21:19:42 minshall 29 28
c Changes from Steve Jacobson: 
c 1.  do 4.3 select's correctly. 
c 2.  filter telnet options from command replies. 
c 3.  take into account 4.3 OOB behaviour (only send IAC in urgent 
c 	mode when sending a telnet synch).
e
s 00001/00001/01482
d D 5.11 86/04/02 15:24:54 karels 28 27
c socket options must be INT!
e
s 00007/00000/01476
d D 5.10 86/03/11 12:00:23 karels 27 25
c can't reconnect after some errors
e
s 00003/00001/01475
d R 5.10 86/03/11 11:32:28 karels 26 25
c can't retry if got too far
e
s 00109/00093/01367
d D 5.9 86/03/07 12:31:36 minshall 25 24
c Clean up for lint; change some stderr to stdout; bug fix
c (in ruserpass.c, routine rnetrc()).
e
s 00085/00166/01375
d D 5.8 86/03/04 09:43:23 lepreau 24 23
c just formatting (verified with cc -S).
e
s 00001/00001/01540
d D 5.7 86/02/04 10:53:56 minshall 23 22
c A fix from Steve Jacobson to his new version (from csvsj@ucbopal).
e
s 01068/00138/00473
d D 5.6 86/02/03 14:40:35 minshall 22 21
c Changes from Steve Jacobson (from <csvsj@ucbopal>).
e
s 00046/00033/00565
d D 5.5 86/01/13 19:32:40 mckusick 21 20
c numerous bug fixes from sun!gorodish!guy
e
s 00039/00040/00559
d D 5.4 86/01/13 17:59:43 karels 20 19
c try multiple addresses in turn if necessary;
c don't build hostent structures, just the parts we want
e
s 00011/00009/00588
d D 5.3 85/10/05 18:33:01 bloom 19 18
c check to see if we have a internet address before getting the hostname
e
s 00002/00000/00595
d D 5.2 85/10/05 18:20:08 bloom 18 17
c fix problem building own hostent
e
s 00007/00001/00588
d D 5.1 85/05/31 17:00:14 dist 17 16
c Add copyright
e
s 00002/00002/00587
d D 4.16 85/03/11 13:31:47 ralph 16 15
c minor fixes from ut-sally
e
s 00001/00001/00588
d D 4.15 85/02/13 14:36:43 ralph 15 14
c added a missing \n.
e
s 00003/00002/00586
d D 4.14 84/12/03 00:06:21 lepreau 14 13
c cnvt setsockopt to new interface
e
s 00004/00003/00584
d D 4.13 84/10/25 09:24:26 ralph 13 12
c fix access check on destination files in recvrequest().
e
s 00005/00006/00582
d D 4.12 84/05/03 15:38:07 leres 12 11
c Simplified math in ptransfer() to avoid destroying bits (and somethings
c coming up with negative transfer rates).
e
s 00000/00003/00588
d D 4.11 83/07/26 21:34:14 sam 11 10
c linger purge
e
s 00001/00001/00590
d D 4.10 83/07/02 00:29:46 sam 10 9
c include fixes
e
s 00009/00002/00582
d D 4.9 83/06/19 23:08:20 sam 9 8
c fix m* cmds and add linger control
e
s 00006/00001/00578
d D 4.8 83/05/11 22:02:40 sam 8 7
c split ftpd out to etc source; fix bug with sendport stuff
e
s 00068/00021/00511
d D 4.7 83/03/23 10:26:18 sam 7 6
c merge of changes from jsq@utexas-11
e
s 00008/00006/00524
d D 4.6 83/03/19 14:29:07 sam 6 5
c no more socketaddr, now use getsockname
e
s 00014/00012/00516
d D 4.5 83/02/28 22:06:34 sam 5 4
c more fixes from jsq@utexas-11
e
s 00003/00004/00525
d D 4.4 83/02/25 05:24:06 sam 4 3
c problem with a.b.c.d specification
e
s 00002/00002/00527
d D 4.3 83/02/22 17:11:10 sam 3 2
c missed two other things
e
s 00084/00025/00445
d D 4.2 83/02/21 19:38:06 sam 2 1
c fixes from texas
e
s 00470/00000/00000
d D 4.1 83/01/15 16:52:38 sam 1 0
c date and time created 83/01/15 16:52:38 by sam
e
u
U
f b 
t
T
I 17
/*
D 22
 * Copyright (c) 1980 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1985 Regents of the University of California.
E 22
D 34
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 34
I 34
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 34
 */

E 17
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif
E 17
I 17
D 34
#endif not lint
E 34
I 34
#endif /* not lint */
E 34
E 17

D 22
#include <sys/param.h>
E 22
I 22
#include "ftp_var.h"

E 22
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
I 10
#include <sys/time.h>
I 25
D 31
#include <sys/types.h>
E 31
I 31
#include <sys/param.h>
E 31
E 25
E 10

#include <netinet/in.h>
I 8
#include <arpa/ftp.h>
I 22
#include <arpa/telnet.h>
E 22
E 8

#include <stdio.h>
#include <signal.h>
D 10
#include <time.h>
E 10
#include <errno.h>
#include <netdb.h>
I 22
#include <fcntl.h>
#include <pwd.h>
E 22

D 8
#include "ftp.h"
E 8
D 22
#include "ftp_var.h"

E 22
struct	sockaddr_in hisctladdr;
struct	sockaddr_in data_addr;
int	data = -1;
I 22
D 29
int     telflag = 0;
E 29
int	abrtflag = 0;
int	ptflag = 0;
E 22
int	connected;
struct	sockaddr_in myctladdr;
I 25
uid_t	getuid();
E 25

FILE	*cin, *cout;
FILE	*dataconn();

D 20
struct hostent *
E 20
I 20
char *
E 20
hookup(host, port)
	char *host;
	int port;
{
D 20
	register struct hostent *hp;
E 20
I 20
	register struct hostent *hp = 0;
I 22
D 29
	int s,len,oldverbose;
E 29
I 29
	int s,len;
E 29
E 22
	static char hostnamebuf[80];
E 20
D 6
	int s;
E 6
I 6
D 22
	int s, len;
E 22
I 22
D 29
	char msg[2];
E 29
E 22
I 19
D 20
	long addr;
E 20
E 19
E 6

	bzero((char *)&hisctladdr, sizeof (hisctladdr));
D 19
	hp = gethostbyname(host);
D 4
	if (hp) {
		hisctladdr.sin_family = hp->h_addrtype;
		hostname = hp->h_name;
	} else {
E 4
I 4
	if (hp == NULL) {
E 19
I 19
D 20
	if ((addr = inet_addr(host)) == -1) {
E 20
I 20
	hisctladdr.sin_addr.s_addr = inet_addr(host);
	if (hisctladdr.sin_addr.s_addr != -1) {
		hisctladdr.sin_family = AF_INET;
		(void) strcpy(hostnamebuf, host);
D 22
	} else {
E 22
I 22
	}
	else {
E 22
E 20
		hp = gethostbyname(host);
D 20
	} else  {
E 19
E 4
		static struct hostent def;
		static struct in_addr defaddr;
D 19
		static char namebuf[128];
E 19
I 19
		static char namebuf[MAXHOSTNAMELEN];
E 19
I 18
		static char *addrbuf;
E 18
D 19
		int inet_addr();
E 19
I 19
		long inet_addr();
E 19

D 19
		defaddr.s_addr = inet_addr(host);
		if (defaddr.s_addr == -1) {
			fprintf(stderr, "%s: Unknown host.\n", host);
			return (0);
		}
E 19
I 19
		defaddr.s_addr = addr;
E 19
		strcpy(namebuf, host);
		def.h_name = namebuf;
		hostname = namebuf;
I 18
		def.h_addr_list = &addrbuf;
E 18
		def.h_addr = (char *)&defaddr;
		def.h_length = sizeof (struct in_addr);
		def.h_addrtype = AF_INET;
		def.h_aliases = 0;
		hp = &def;
E 20
I 20
		if (hp == NULL) {
			printf("%s: unknown host\n", host);
D 22
			return (0);
E 22
I 22
			code = -1;
			return((char *) 0);
E 22
		}
		hisctladdr.sin_family = hp->h_addrtype;
		bcopy(hp->h_addr_list[0],
		    (caddr_t)&hisctladdr.sin_addr, hp->h_length);
		(void) strcpy(hostnamebuf, hp->h_name);
E 20
I 19
	}
D 20
	if (hp == NULL) {
		fprintf(stderr, "%s: Unknown host.\n", host);
		return (0);
E 19
	}
I 4
	hostname = hp->h_name;
	hisctladdr.sin_family = hp->h_addrtype;
E 4
D 16
	s = socket(hp->h_addrtype, SOCK_STREAM, 0, 0);
E 16
I 16
	s = socket(hp->h_addrtype, SOCK_STREAM, 0);
E 20
I 20
	hostname = hostnamebuf;
	s = socket(hisctladdr.sin_family, SOCK_STREAM, 0);
E 20
E 16
	if (s < 0) {
		perror("ftp: socket");
I 22
		code = -1;
E 22
		return (0);
	}
D 20
	if (bind(s, (char *)&hisctladdr, sizeof (hisctladdr), 0) < 0) {
		perror("ftp: bind");
		goto bad;
	}
	bcopy(hp->h_addr, (char *)&hisctladdr.sin_addr, hp->h_length);
E 20
	hisctladdr.sin_port = port;
D 20
	if (connect(s, (char *)&hisctladdr, sizeof (hisctladdr), 0) < 0) {
E 20
I 20
D 25
	while (connect(s, (caddr_t)&hisctladdr, sizeof (hisctladdr)) < 0) {
E 25
I 25
	while (connect(s, &hisctladdr, sizeof (hisctladdr)) < 0) {
E 25
		if (hp && hp->h_addr_list[1]) {
			int oerrno = errno;

			fprintf(stderr, "ftp: connect to address %s: ",
				inet_ntoa(hisctladdr.sin_addr));
			errno = oerrno;
D 25
			perror(0);
E 25
I 25
			perror((char *) 0);
E 25
			hp->h_addr_list++;
			bcopy(hp->h_addr_list[0],
D 22
			    (caddr_t)&hisctladdr.sin_addr, hp->h_length);
E 22
I 22
			     (caddr_t)&hisctladdr.sin_addr, hp->h_length);
E 22
D 25
			fprintf(stderr, "Trying %s...\n",
E 25
I 25
			fprintf(stdout, "Trying %s...\n",
E 25
				inet_ntoa(hisctladdr.sin_addr));
I 27
			(void) close(s);
			s = socket(hisctladdr.sin_family, SOCK_STREAM, 0);
			if (s < 0) {
				perror("ftp: socket");
				code = -1;
				return (0);
			}
E 27
			continue;
		}
E 20
		perror("ftp: connect");
I 22
		code = -1;
E 22
		goto bad;
	}
D 6
	if (socketaddr(s, &myctladdr) < 0) {
		perror("ftp: socketaddr");
E 6
I 6
	len = sizeof (myctladdr);
	if (getsockname(s, (char *)&myctladdr, &len) < 0) {
		perror("ftp: getsockname");
I 22
		code = -1;
E 22
E 6
		goto bad;
	}
	cin = fdopen(s, "r");
	cout = fdopen(s, "w");
D 2
	if (cin == NULL | cout == NULL) {
E 2
I 2
	if (cin == NULL || cout == NULL) {
E 2
		fprintf(stderr, "ftp: fdopen failed.\n");
		if (cin)
D 25
			fclose(cin);
E 25
I 25
			(void) fclose(cin);
E 25
		if (cout)
D 25
			fclose(cout);
E 25
I 25
			(void) fclose(cout);
E 25
I 22
		code = -1;
E 22
		goto bad;
	}
	if (verbose)
D 20
		printf("Connected to %s.\n", hp->h_name);
E 20
I 20
D 22
		printf("Connected to %s.\n", hostname);
E 20
	(void) getreply(0); 		/* read startup message from server */
E 22
I 22
D 23
		printf("Connected to %s.\n", hp->h_name);
E 23
I 23
		printf("Connected to %s.\n", hostname);
E 23
D 29
	if (getreply(0) != 2) { 	/* read startup message from server */
E 29
I 29
	if (getreply(0) > 2) { 	/* read startup message from server */
E 29
		if (cin)
D 25
			fclose(cin);
E 25
I 25
			(void) fclose(cin);
E 25
		if (cout)
D 25
			fclose(cout);
E 25
I 25
			(void) fclose(cout);
E 25
		code = -1;
		goto bad;
	}
I 29
#ifdef SO_OOBINLINE
	{
	int on = 1;
E 29

D 29
/* test to see if server command parser understands TELNET SYNC command */
E 29
I 29
	if (setsockopt(s, SOL_SOCKET, SO_OOBINLINE, &on, sizeof(on))
		< 0 && debug) {
			perror("ftp: setsockopt");
		}
	}
#endif SO_OOBINLINE
E 29

D 29
	fprintf(cout,"%c%c",IAC,NOP);
	(void) fflush(cout);
	*msg = IAC;
	*(msg+1) = DM;
D 24
	if (send(s,msg,2,MSG_OOB) != 2) {
E 24
I 24
	if (send(s,msg,2,MSG_OOB) != 2)
E 24
		perror("sync");
D 24
	}
E 24
	oldverbose = verbose;
D 24
	if (!debug) {
E 24
I 24
	if (!debug)
E 24
		verbose = -1;
D 24
	}
	if (command("NOOP") == COMPLETE) {
E 24
I 24
	if (command("NOOP") == COMPLETE)
E 24
		telflag = 1;
D 24
	}
	else {
E 24
I 24
	else
E 24
		telflag = 0;
D 24
	}
E 24
	verbose = oldverbose;
E 29
E 22
D 20
	return (hp);
E 20
I 20
	return (hostname);
E 20
bad:
D 25
	close(s);
E 25
I 25
	(void) close(s);
E 25
D 20
	return ((struct hostent *)0);
E 20
I 20
	return ((char *)0);
E 20
}

D 20
login(hp)
	struct hostent *hp;
E 20
I 20
login(host)
	char *host;
E 20
{
D 22
	char acct[80];
	char *user, *pass;
	int n;
E 22
I 22
	char tmp[80];
D 25
	char *user, *pass, *acct, *getlogin(), *getpass();
E 25
I 25
	char *user, *pass, *acct, *getlogin(), *mygetpass();
E 25
	int n, aflag = 0;
E 22

D 22
	user = pass = 0;
D 20
	ruserpass(hp->h_name, &user, &pass);
E 20
I 20
	ruserpass(host, &user, &pass);
E 22
I 22
	user = pass = acct = 0;
	if (ruserpass(host, &user, &pass, &acct) < 0) {
		disconnect();
		code = -1;
		return(0);
	}
	if (user == NULL) {
		char *myname = getlogin();

		if (myname == NULL) {
			struct passwd *pp = getpwuid(getuid());

D 24
			if (pp != NULL) {
E 24
I 24
			if (pp != NULL)
E 24
				myname = pp->pw_name;
D 24
			}
E 24
		}
		printf("Name (%s:%s): ", host, myname);
		(void) fgets(tmp, sizeof(tmp) - 1, stdin);
		tmp[strlen(tmp) - 1] = '\0';
D 24
		if (*tmp == '\0') {
E 24
I 24
		if (*tmp == '\0')
E 24
			user = myname;
D 24
		}
		else {
E 24
I 24
		else
E 24
			user = tmp;
D 24
		}
E 24
	}
E 22
E 20
	n = command("USER %s", user);
D 22
	if (n == CONTINUE)
E 22
I 22
	if (n == CONTINUE) {
D 24
		if (pass == NULL) {
E 24
I 24
		if (pass == NULL)
E 24
D 25
			pass = getpass("Password:");
E 25
I 25
			pass = mygetpass("Password:");
E 25
D 24
		}
E 24
E 22
		n = command("PASS %s", pass);
I 22
	}
E 22
	if (n == CONTINUE) {
D 22
		printf("Account: "); (void) fflush(stdout);
		(void) fgets(acct, sizeof(acct) - 1, stdin);
		acct[strlen(acct) - 1] = '\0';
E 22
I 22
		aflag++;
D 25
		acct = getpass("Account:");
E 25
I 25
		acct = mygetpass("Account:");
E 25
E 22
		n = command("ACCT %s", acct);
	}
	if (n != COMPLETE) {
		fprintf(stderr, "Login failed.\n");
		return (0);
	}
I 22
D 24
	if (!aflag && acct != NULL) {
E 24
I 24
	if (!aflag && acct != NULL)
E 24
		(void) command("ACCT %s", acct);
D 24
	}
	if (proxy) {
E 24
I 24
	if (proxy)
E 24
		return(1);
D 24
	}
E 24
	for (n = 0; n < macnum; ++n) {
		if (!strcmp("init", macros[n].mac_name)) {
D 25
			strcpy(line, "$init");
E 25
I 25
			(void) strcpy(line, "$init");
E 25
			makeargv();
			domacro(margc, margv);
			break;
		}
	}
E 22
	return (1);
}

I 22
cmdabort()
{
	extern jmp_buf ptabort;

	printf("\n");
	(void) fflush(stdout);
	abrtflag++;
D 24
	if (ptflag) {
E 24
I 24
	if (ptflag)
E 24
		longjmp(ptabort,1);
D 24
	}
E 24
}

E 22
D 25
/*VARARGS 1*/
E 25
I 25
/*VARARGS1*/
E 25
command(fmt, args)
	char *fmt;
{
I 22
	int r, (*oldintr)(), cmdabort();
E 22

I 22
	abrtflag = 0;
E 22
	if (debug) {
		printf("---> ");
		_doprnt(fmt, &args, stdout);
		printf("\n");
		(void) fflush(stdout);
	}
I 2
	if (cout == NULL) {
		perror ("No control connection for command");
I 22
		code = -1;
E 22
		return (0);
	}
I 22
	oldintr = signal(SIGINT,cmdabort);
E 22
E 2
	_doprnt(fmt, &args, cout);
	fprintf(cout, "\r\n");
	(void) fflush(cout);
D 22
	return (getreply(!strcmp(fmt, "QUIT")));
E 22
I 22
	cpend = 1;
	r = getreply(!strcmp(fmt, "QUIT"));
D 24
	if (abrtflag && oldintr != SIG_IGN) {
E 24
I 24
	if (abrtflag && oldintr != SIG_IGN)
E 24
		(*oldintr)();
D 24
	}
E 24
	(void) signal(SIGINT, oldintr);
	return(r);
E 22
}

#include <ctype.h>

getreply(expecteof)
	int expecteof;
{
D 2
	register char c, n;
E 2
I 2
	register int c, n;
E 2
D 22
	register int code, dig;
	int originalcode = 0, continuation = 0;
E 22
I 22
	register int dig;
	int originalcode = 0, continuation = 0, (*oldintr)(), cmdabort();
	int pflag = 0;
	char *pt = pasv;
E 22

I 22
	oldintr = signal(SIGINT,cmdabort);
E 22
	for (;;) {
		dig = n = code = 0;
		while ((c = getc(cin)) != '\n') {
I 29
			if (c == IAC) {     /* handle telnet commands */
				switch (c = getc(cin)) {
				case WILL:
				case WONT:
					c = getc(cin);
					fprintf(cout, "%c%c%c",IAC,WONT,c);
					(void) fflush(cout);
					break;
				case DO:
				case DONT:
					c = getc(cin);
					fprintf(cout, "%c%c%c",IAC,DONT,c);
					(void) fflush(cout);
					break;
				default:
					break;
				}
				continue;
			}
E 29
			dig++;
			if (c == EOF) {
D 22
				if (expecteof)
E 22
I 22
				if (expecteof) {
					(void) signal(SIGINT,oldintr);
					code = 221;
E 22
					return (0);
I 22
				}
E 22
				lostpeer();
D 22
				exit(1);
E 22
I 22
				if (verbose) {
					printf("421 Service not available, remote server has closed connection\n");
					(void) fflush(stdout);
D 35
					code = 421;
					return(4);
E 35
				}
I 35
				code = 421;
				return(4);
E 35
E 22
			}
D 22
			if (verbose && c != '\r' ||
			    (n == '5' && dig > 4))
E 22
I 22
			if (c != '\r' && (verbose > 0 ||
			    (verbose > -1 && n == '5' && dig > 4))) {
D 24
				if ( proxflag && 
				   (dig == 1 || dig == 5 && verbose == 0)) {
E 24
I 24
				if (proxflag &&
				   (dig == 1 || dig == 5 && verbose == 0))
E 24
					printf("%s:",hostname);
D 24
				}
E 24
E 22
D 25
				putchar(c);
E 25
I 25
				(void) putchar(c);
E 25
I 22
			}
E 22
			if (dig < 4 && isdigit(c))
				code = code * 10 + (c - '0');
D 22
			if (dig == 4 && c == '-')
E 22
I 22
D 24
			if (!pflag && code == 227) {
E 24
I 24
			if (!pflag && code == 227)
E 24
				pflag = 1;
D 24
			}
			if (dig > 4 && pflag == 1 && isdigit(c)) {
E 24
I 24
			if (dig > 4 && pflag == 1 && isdigit(c))
E 24
				pflag = 2;
D 24
			}
E 24
			if (pflag == 2) {
D 24
				if (c != '\r' && c != ')') {
E 24
I 24
				if (c != '\r' && c != ')')
E 24
					*pt++ = c;
D 24
				}
E 24
				else {
					*pt = '\0';
					pflag = 3;
				}
			}
			if (dig == 4 && c == '-') {
D 24
				if (continuation) {
E 24
I 24
				if (continuation)
E 24
					code = 0;
D 24
				}
E 24
E 22
				continuation++;
I 22
			}
E 22
			if (n == 0)
				n = c;
		}
D 5
		if (verbose || n == '5')
E 5
I 5
D 22
		if (verbose || n == '5') {
E 22
I 22
		if (verbose > 0 || verbose > -1 && n == '5') {
E 22
E 5
D 25
			putchar(c);
E 25
I 25
			(void) putchar(c);
E 25
I 5
			(void) fflush (stdout);
		}
E 5
		if (continuation && code != originalcode) {
			if (originalcode == 0)
				originalcode = code;
			continue;
		}
I 22
D 24
		if (n != '1') {
E 24
I 24
		if (n != '1')
E 24
			cpend = 0;
D 24
		}
E 24
		(void) signal(SIGINT,oldintr);
D 24
		if (code == 421 || originalcode == 421) {
E 24
I 24
		if (code == 421 || originalcode == 421)
E 24
			lostpeer();
D 24
		}
		if (abrtflag && oldintr != cmdabort && oldintr != SIG_IGN) {
E 24
I 24
		if (abrtflag && oldintr != cmdabort && oldintr != SIG_IGN)
E 24
			(*oldintr)();
D 24
		}
E 24
E 22
D 2
		if (empty(cin))
E 2
I 2
D 21
		if (expecteof || empty(cin))
E 2
			return (n - '0');
E 21
I 21
		return (n - '0');
E 21
	}
}

I 22
empty(mask, sec)
D 25
	long mask;
E 25
I 25
D 29
	struct fd_set mask;
E 29
I 29
	struct fd_set *mask;
E 29
E 25
	int sec;
{
	struct timeval t;

	t.tv_sec = (long) sec;
	t.tv_usec = 0;
D 24
	if (select(20, &mask, 0, 0, &t) < 0) {
E 24
I 24
D 25
	if (select(20, &mask, 0, 0, &t) < 0)
E 25
I 25
D 29
	if (select(20, &mask, (struct fd_set *) 0, (struct fd_set *) 0, &t) < 0)
E 25
E 24
		return(-1);
D 24
	}
E 24
D 25
	return (mask);
E 25
I 25
	return (1);
E 29
I 29
	return(select(32, mask, (struct fd_set *) 0, (struct fd_set *) 0, &t));
E 29
E 25
}

E 22
D 21
empty(f)
	FILE *f;
{
D 7
	int mask;
E 7
I 7
	long mask;
E 7
	struct timeval t;

	if (f->_cnt > 0)
		return (0);
	mask = (1 << fileno(f));
	t.tv_sec = t.tv_usec = 0;
	(void) select(20, &mask, 0, 0, &t);
	return (mask == 0);
}

E 21
jmp_buf	sendabort;

abortsend()
{

I 22
	mflag = 0;
	abrtflag = 0;
	printf("\nsend aborted\n");
	(void) fflush(stdout);
E 22
	longjmp(sendabort, 1);
}

sendrequest(cmd, local, remote)
	char *cmd, *local, *remote;
{
D 22
	FILE *fin, *dout, *popen();
	int (*closefunc)(), pclose(), fclose(), (*oldintr)();
E 22
I 22
D 25
	FILE *fin, *dout = 0, *popen();
	int (*closefunc)(), pclose(), fclose(), (*oldintr)(), (*oldintp)();
E 25
I 25
	FILE *fin, *dout = 0, *mypopen();
	int (*closefunc)(), mypclose(), fclose(), (*oldintr)(), (*oldintp)();
E 25
	int abortsend();
E 22
D 2
	register int bytes = 0;
	register char c;
E 2
I 2
	char buf[BUFSIZ];
I 21
D 22
	int expectingreply = 0;
E 22
E 21
D 5
	register int bytes = 0, c;
E 5
I 5
D 7
	register int bytes = 0;
E 7
I 7
	long bytes = 0, hashbytes = sizeof (buf);
E 7
	register int c, d;
E 5
E 2
	struct stat st;
	struct timeval start, stop;
I 2
D 5
	extern int errno;
E 5
E 2

I 22
	if (proxy) {
		proxtrans(cmd, local, remote);
		return;
	}
E 22
	closefunc = NULL;
D 22
	if (setjmp(sendabort))
		goto bad;
E 22
I 22
	oldintr = NULL;
	oldintp = NULL;
	if (setjmp(sendabort)) {
		while (cpend) {
			(void) getreply(0);
		}
		if (data >= 0) {
			(void) close(data);
			data = -1;
		}
D 24
		if (oldintr) {
E 24
I 24
		if (oldintr)
E 24
			(void) signal(SIGINT,oldintr);
D 24
		}
		if (oldintp) {
E 24
I 24
		if (oldintp)
E 24
			(void) signal(SIGPIPE,oldintp);
D 24
		}
E 24
		code = -1;
		return;
	}
E 22
	oldintr = signal(SIGINT, abortsend);
	if (strcmp(local, "-") == 0)
		fin = stdin;
	else if (*local == '|') {
D 21
		fin = popen(local + 1, "r");
E 21
I 21
D 22
		/*
		 * Advance local so further uses just yield file name
		 * thus later references for error messages need not check
		 * for '|' special case.
	 	 */
		local += 1;
		fin = popen(local, "r");
E 22
I 22
		oldintp = signal(SIGPIPE,SIG_IGN);
D 25
		fin = popen(local + 1, "r");
E 25
I 25
		fin = mypopen(local + 1, "r");
E 25
E 22
E 21
		if (fin == NULL) {
D 21
			perror(local + 1);
E 21
I 21
D 22
			perror(local);
E 21
			goto bad;
E 22
I 22
			perror(local + 1);
			(void) signal(SIGINT, oldintr);
			(void) signal(SIGPIPE, oldintp);
			code = -1;
			return;
E 22
		}
D 25
		closefunc = pclose;
E 25
I 25
		closefunc = mypclose;
E 25
	} else {
		fin = fopen(local, "r");
		if (fin == NULL) {
			perror(local);
D 22
			goto bad;
E 22
I 22
			(void) signal(SIGINT, oldintr);
			code = -1;
			return;
E 22
		}
		closefunc = fclose;
		if (fstat(fileno(fin), &st) < 0 ||
		    (st.st_mode&S_IFMT) != S_IFREG) {
D 15
			fprintf(stderr, "%s: not a plain file.", local);
E 15
I 15
D 25
			fprintf(stderr, "%s: not a plain file.\n", local);
E 25
I 25
			fprintf(stdout, "%s: not a plain file.\n", local);
E 25
E 15
D 22
			goto bad;
E 22
I 22
			(void) signal(SIGINT, oldintr);
			code = -1;
			return;
E 22
		}
	}
D 22
	if (initconn())
		goto bad;
E 22
I 22
	if (initconn()) {
		(void) signal(SIGINT, oldintr);
D 24
		if (oldintp) {
E 24
I 24
		if (oldintp)
E 24
			(void) signal(SIGPIPE, oldintp);
D 24
		}
E 24
		code = -1;
		return;
	}
D 24
	if (setjmp(sendabort)) {
E 24
I 24
	if (setjmp(sendabort))
E 24
		goto abort;
D 24
	}
E 24
E 22
	if (remote) {
D 22
		if (command("%s %s", cmd, remote) != PRELIM)
			goto bad;
E 22
I 22
		if (command("%s %s", cmd, remote) != PRELIM) {
			(void) signal(SIGINT, oldintr);
D 24
			if (oldintp) {
E 24
I 24
			if (oldintp)
E 24
				(void) signal(SIGPIPE, oldintp);
D 24
			}
E 24
			return;
		}
E 22
	} else
D 22
		if (command("%s", cmd) != PRELIM)
			goto bad;
I 21
	expectingreply++;	/* got preliminary reply, expecting final reply */
E 22
I 22
		if (command("%s", cmd) != PRELIM) {
			(void) signal(SIGINT, oldintr);
D 24
			if (oldintp) {
E 24
I 24
			if (oldintp)
E 24
				(void) signal(SIGPIPE, oldintp);
D 24
			}
E 24
			return;
		}
E 22
E 21
	dout = dataconn("w");
D 22
	if (dout == NULL)
		goto bad;
E 22
I 22
D 24
	if (dout == NULL) {
E 24
I 24
	if (dout == NULL)
E 24
		goto abort;
D 24
	}
E 24
E 22
D 25
	gettimeofday(&start, (struct timezone *)0);
E 25
I 25
	(void) gettimeofday(&start, (struct timezone *)0);
E 25
D 2
	while ((c = getc(fin)) != EOF) {
		if (type == TYPE_A && c == '\n')
			putc('\r', dout);
		putc(c, dout);
		bytes++;
E 2
I 2
	switch (type) {

	case TYPE_I:
	case TYPE_L:
D 5
		errno = 0;
E 5
I 5
		errno = d = 0;
E 5
		while ((c = read(fileno (fin), buf, sizeof (buf))) > 0) {
D 5
			if (write(fileno (dout), buf, c) < 0)
E 5
I 5
			if ((d = write(fileno (dout), buf, c)) < 0)
E 5
				break;
			bytes += c;
I 7
			if (hash) {
D 25
				putchar('#');
				fflush(stdout);
E 25
I 25
				(void) putchar('#');
				(void) fflush(stdout);
E 25
			}
E 7
		}
I 7
D 9
		if (hash) {
E 9
I 9
		if (hash && bytes > 0) {
E 9
D 25
			putchar('\n');
			fflush(stdout);
E 25
I 25
			(void) putchar('\n');
			(void) fflush(stdout);
E 25
		}
E 7
		if (c < 0)
			perror(local);
D 3
		if (errno)
E 3
I 3
D 5
		else if (errno)
E 5
I 5
		if (d < 0)
E 5
E 3
			perror("netout");
		break;

	case TYPE_A:
		while ((c = getc(fin)) != EOF) {
			if (c == '\n') {
I 7
				while (hash && (bytes >= hashbytes)) {
D 25
					putchar('#');
					fflush(stdout);
E 25
I 25
					(void) putchar('#');
					(void) fflush(stdout);
E 25
					hashbytes += sizeof (buf);
				}
E 7
				if (ferror(dout))
					break;
D 25
				putc('\r', dout);
E 25
I 25
				(void) putc('\r', dout);
E 25
				bytes++;
			}
D 25
			putc(c, dout);
E 25
I 25
			(void) putc(c, dout);
E 25
			bytes++;
D 22
			if (c == '\r') {
				putc('\0', dout);
				bytes++;
			}
E 22
I 22
	/*		if (c == '\r') {			  	*/
D 25
	/*			putc('\0', dout);  /* this violates rfc */
E 25
I 25
	/*		(void)	putc('\0', dout);  /* this violates rfc */
E 25
	/*			bytes++;				*/
	/*		}                          			*/	
E 22
		}
I 7
		if (hash) {
I 9
			if (bytes < hashbytes)
D 25
				putchar('#');
E 9
			putchar('\n');
			fflush(stdout);
E 25
I 25
				(void) putchar('#');
			(void) putchar('\n');
			(void) fflush(stdout);
E 25
		}
E 7
		if (ferror(fin))
			perror(local);
D 3
		if (ferror(dout))
E 3
I 3
D 5
		else if (ferror(dout))
E 5
I 5
		if (ferror(dout))
E 5
E 3
			perror("netout");
		break;
E 2
	}
D 25
	gettimeofday(&stop, (struct timezone *)0);
E 25
I 25
	(void) gettimeofday(&stop, (struct timezone *)0);
E 25
	if (closefunc != NULL)
D 21
		(*closefunc)(fin);
E 21
I 21
D 22
		(*closefunc)(fin), closefunc = NULL;
E 22
I 22
		(*closefunc)(fin);
E 22
E 21
	(void) fclose(dout);
D 2
	if (ferror(fin)) {
		perror(local);
		goto done;
	}
E 2
D 21
	(void) getreply(0);
E 21
D 22
done:
I 21
	if (expectingreply) {
		(void) getreply(0);
		expectingreply = 0;
	}
E 21
	signal(SIGINT, oldintr);
E 22
I 22
	(void) getreply(0);
	(void) signal(SIGINT, oldintr);
E 22
	if (bytes > 0 && verbose)
D 22
		ptransfer("sent", bytes, &start, &stop);
E 22
I 22
		ptransfer("sent", bytes, &start, &stop, local, remote);
E 22
	return;
D 22
bad:
	if (data >= 0)
		(void) close(data), data = -1;
E 22
I 22
abort:
D 25
	gettimeofday(&stop, (struct timezone *)0);
E 25
I 25
	(void) gettimeofday(&stop, (struct timezone *)0);
E 25
	(void) signal(SIGINT, oldintr);
D 24
	if (oldintp) {
E 24
I 24
	if (oldintp)
E 24
		(void) signal(SIGPIPE, oldintp);
D 24
	}
E 24
	if (!cpend) {
		code = -1;
		return;
	}
	if (data >= 0) {
		(void) close(data);
		data = -1;
	}
D 24
	if (dout) {
E 24
I 24
	if (dout)
E 24
		(void) fclose(dout);
D 24
	}
E 24
	(void) getreply(0);
	code = -1;
E 22
	if (closefunc != NULL && fin != NULL)
D 21
		(*closefunc)(fin);
E 21
I 21
D 22
		(*closefunc)(fin), closefunc = NULL;
	bytes = 0;	/* so we don't print a message if the transfer was aborted */
E 21
	goto done;
E 22
I 22
		(*closefunc)(fin);
	if (bytes > 0 && verbose)
		ptransfer("sent", bytes, &start, &stop, local, remote);
E 22
}

jmp_buf	recvabort;

abortrecv()
{

I 22
	mflag = 0;
	abrtflag = 0;
	printf("\n");
	(void) fflush(stdout);
E 22
	longjmp(recvabort, 1);
}

D 7
recvrequest(cmd, local, remote)
	char *cmd, *local, *remote;
E 7
I 7
recvrequest(cmd, local, remote, mode)
	char *cmd, *local, *remote, *mode;
E 7
{
D 22
	FILE *fout, *din, *popen();
D 2
	int (*closefunc)(), pclose(), fclose(), (*oldintr)();
	register char c;
E 2
I 2
D 7
	char buf[BUFSIZ];
E 7
D 5
	int (*closefunc)(), pclose(), fclose(), (*oldintr)(), c;
E 5
I 5
	int (*closefunc)(), pclose(), fclose(), (*oldintr)();
E 5
E 2
D 7
	register int bytes = 0;
E 7
I 7
	char buf[BUFSIZ];
I 21
	int expectingreply = 0;
E 21
	long bytes = 0, hashbytes = sizeof (buf);
E 22
I 22
D 25
	FILE *fout, *din = 0, *popen();
	int (*closefunc)(), pclose(), fclose(), (*oldintr)(), (*oldintp)(); 
E 25
I 25
	FILE *fout, *din = 0, *mypopen();
	int (*closefunc)(), mypclose(), fclose(), (*oldintr)(), (*oldintp)(); 
E 25
D 29
	int abortrecv(), oldverbose, oldtype = 0, tcrflag;
	char buf[BUFSIZ], *gunique();
E 29
I 29
	int abortrecv(), oldverbose, oldtype = 0, tcrflag, nfnd;
	char buf[BUFSIZ], *gunique(), msg;
E 29
D 25
	long bytes = 0, hashbytes = sizeof (buf), mask;
E 25
I 25
	long bytes = 0, hashbytes = sizeof (buf);
	struct fd_set mask;
E 25
E 22
E 7
I 5
	register int c, d;
E 5
	struct timeval start, stop;
I 2
D 5
	extern int errno;
E 5
E 2

I 22
	if (proxy && strcmp(cmd,"RETR") == 0) {
		proxtrans(cmd, local, remote);
		return;
	}
E 22
	closefunc = NULL;
D 22
	if (setjmp(recvabort))
		goto bad;
E 22
I 22
	oldintr = NULL;
	oldintp = NULL;
	tcrflag = !crflag && !strcmp(cmd, "RETR");
	if (setjmp(recvabort)) {
		while (cpend) {
			(void) getreply(0);
		}
		if (data >= 0) {
			(void) close(data);
			data = -1;
		}
D 24
		if (oldintr) {
E 24
I 24
		if (oldintr)
E 24
			(void) signal(SIGINT, oldintr);
D 24
		}
E 24
		code = -1;
		return;
	}
E 22
	oldintr = signal(SIGINT, abortrecv);
D 22
	if (strcmp(local, "-") && *local != '|')
E 22
I 22
	if (strcmp(local, "-") && *local != '|') {
E 22
		if (access(local, 2) < 0) {
D 21
			char *dir = rindex(local, '/');
E 21
I 21
D 22
			if (errno == ENOENT) {
				char *dir = rindex(local, '/');
E 22
I 22
			char *dir = rindex(local, '/');
E 22
E 21

D 21
			if (dir != NULL)
				*dir = 0;
D 13
			if (access(dir ? dir : ".", 2) < 0) {
E 13
I 13
			d = access(dir ? local : ".", 2);
			if (dir != NULL)
				*dir = '/';
			if (d < 0) {
E 21
I 21
D 22
				if (dir != NULL)
					*dir = 0;
				d = access(dir ? local : ".", 2);
				if (dir != NULL)
					*dir = '/';
				if (d < 0) {
					perror(local);
					goto bad;
				}
			} else {
E 22
I 22
			if (errno != ENOENT && errno != EACCES) {
E 22
E 21
E 13
				perror(local);
D 22
				goto bad;
E 22
I 22
				(void) signal(SIGINT, oldintr);
				code = -1;
				return;
E 22
			}
I 22
			if (dir != NULL)
				*dir = 0;
			d = access(dir ? local : ".", 2);
			if (dir != NULL)
				*dir = '/';
			if (d < 0) {
				perror(local);
				(void) signal(SIGINT, oldintr);
				code = -1;
				return;
			}
			if (!runique && errno == EACCES &&
			    chmod(local,0600) < 0) {
				perror(local);
				(void) signal(SIGINT, oldintr);
				code = -1;
				return;
			}
			if (runique && errno == EACCES &&
			   (local = gunique(local)) == NULL) {
				(void) signal(SIGINT, oldintr);
				code = -1;
				return;
			}
E 22
D 13
			if (dir != NULL)
				*dir = '/';
E 13
		}
D 22
	if (initconn())
		goto bad;
E 22
I 22
		else if (runique && (local = gunique(local)) == NULL) {
			(void) signal(SIGINT, oldintr);
			code = -1;
			return;
		}
	}
	if (initconn()) {
		(void) signal(SIGINT, oldintr);
		code = -1;
		return;
	}
D 24
	if (setjmp(recvabort)) {
E 24
I 24
	if (setjmp(recvabort))
E 24
		goto abort;
D 24
	}
E 24
	if (strcmp(cmd, "RETR") && type != TYPE_A) {
		oldtype = type;
		oldverbose = verbose;
D 24
		if (!debug) {
E 24
I 24
		if (!debug)
E 24
			verbose = 0;
D 24
		}
E 24
		setascii();
		verbose = oldverbose;
	}
E 22
	if (remote) {
D 22
		if (command("%s %s", cmd, remote) != PRELIM)
			goto bad;
	} else
		if (command("%s", cmd) != PRELIM)
			goto bad;
I 21
	expectingreply++;	/* got preliminary reply, expecting final reply */
E 21
	if (strcmp(local, "-") == 0)
E 22
I 22
		if (command("%s %s", cmd, remote) != PRELIM) {
			(void) signal(SIGINT, oldintr);
			if (oldtype) {
D 24
				if (!debug) {
E 24
I 24
				if (!debug)
E 24
					verbose = 0;
D 24
				}
E 24
				switch (oldtype) {
					case TYPE_I:
						setbinary();
						break;
					case TYPE_E:
						setebcdic();
						break;
					case TYPE_L:
						settenex();
						break;
				}
				verbose = oldverbose;
			}
			return;
		}
	} else {
		if (command("%s", cmd) != PRELIM) {
			(void) signal(SIGINT, oldintr);
			if (oldtype) {
D 24
				if (!debug) {
E 24
I 24
				if (!debug)
E 24
					verbose = 0;
D 24
				}
E 24
				switch (oldtype) {
					case TYPE_I:
						setbinary();
						break;
					case TYPE_E:
						setebcdic();
						break;
					case TYPE_L:
						settenex();
						break;
				}
				verbose = oldverbose;
			}
			return;
		}
	}
	din = dataconn("r");
	if (din == NULL)
		goto abort;
D 24
	if (strcmp(local, "-") == 0) {
E 24
I 24
	if (strcmp(local, "-") == 0)
E 24
E 22
		fout = stdout;
I 22
D 24
	}
E 24
E 22
	else if (*local == '|') {
D 21
		fout = popen(local + 1, "w");
E 21
I 21
D 22
		/*
		 * Advance local over '|' so don't need to check for
		 * '|' special case any further.
		 */
		local += 1;
		fout = popen(local, "w");
E 22
I 22
		oldintp = signal(SIGPIPE, SIG_IGN);
D 25
		fout = popen(local + 1, "w");
E 25
I 25
		fout = mypopen(local + 1, "w");
E 25
		if (fout == NULL) {
			perror(local+1);
			goto abort;
		}
E 22
E 21
D 25
		closefunc = pclose;
E 25
I 25
		closefunc = mypclose;
E 25
D 22
	} else {
E 22
I 22
	}
	else {
E 22
D 7
		fout = fopen(local, "w");
E 7
I 7
		fout = fopen(local, mode);
I 22
		if (fout == NULL) {
			perror(local);
			goto abort;
		}
E 22
E 7
		closefunc = fclose;
	}
D 22
	if (fout == NULL) {
D 21
		perror(local + 1);
E 21
I 21
		perror(local);
E 21
		goto bad;
	}
	din = dataconn("r");
	if (din == NULL)
		goto bad;
E 22
D 25
	gettimeofday(&start, (struct timezone *)0);
E 25
I 25
	(void) gettimeofday(&start, (struct timezone *)0);
E 25
D 2
	while ((c = getc(din)) != EOF) {
		if (c != '\r' || type != TYPE_A)
			putc(c, fout);
		bytes++;
		if (ferror(fout)) {
E 2
I 2
	switch (type) {

	case TYPE_I:
	case TYPE_L:
D 5
		errno = 0;
E 5
I 5
		errno = d = 0;
E 5
		while ((c = read(fileno(din), buf, sizeof (buf))) > 0) {
D 5
			if (write(fileno(fout), buf, c) < 0)
E 5
I 5
			if ((d = write(fileno(fout), buf, c)) < 0)
E 5
				break;
			bytes += c;
I 7
			if (hash) {
D 25
				putchar('#');
				fflush(stdout);
E 25
I 25
				(void) putchar('#');
				(void) fflush(stdout);
E 25
			}
E 7
		}
I 7
D 9
		if (hash) {
E 9
I 9
		if (hash && bytes > 0) {
E 9
D 25
			putchar('\n');
			fflush(stdout);
E 25
I 25
			(void) putchar('\n');
			(void) fflush(stdout);
E 25
		}
E 7
		if (c < 0)
			perror("netin");
D 5
		if (errno)
E 5
I 5
		if (d < 0)
E 5
E 2
			perror(local);
D 2
			while (c = getc(din) != EOF)
E 2
I 2
		break;

	case TYPE_A:
		while ((c = getc(din)) != EOF) {
D 30
			if (c == '\r') {
E 30
I 30
			while (c == '\r') {
E 30
I 7
				while (hash && (bytes >= hashbytes)) {
D 25
					putchar('#');
					fflush(stdout);
E 25
I 25
					(void) putchar('#');
					(void) fflush(stdout);
E 25
					hashbytes += sizeof (buf);
				}
E 7
E 2
				bytes++;
D 2
			break;
E 2
I 2
D 22
				if ((c = getc(din)) != '\n') {
E 22
I 22
				if ((c = getc(din)) != '\n' || tcrflag) {
E 22
					if (ferror (fout))
						break;
D 25
					putc ('\r', fout);
E 25
I 25
					(void) putc ('\r', fout);
E 25
				}
D 22
				if (c == '\0') {
E 22
I 22
				/*if (c == '\0') {
E 22
					bytes++;
					continue;
D 22
				}
E 22
I 22
				}*/
E 22
			}
D 25
			putc (c, fout);
E 25
I 25
			(void) putc (c, fout);
E 25
			bytes++;
E 2
		}
I 7
		if (hash) {
I 9
			if (bytes < hashbytes)
D 25
				putchar('#');
E 9
			putchar('\n');
			fflush(stdout);
E 25
I 25
				(void) putchar('#');
			(void) putchar('\n');
			(void) fflush(stdout);
E 25
		}
E 7
I 2
		if (ferror (din))
			perror ("netin");
		if (ferror (fout))
			perror (local);
		break;
E 2
	}
D 22
	gettimeofday(&stop, (struct timezone *)0);
	(void) fclose(din);
	if (closefunc != NULL)
D 21
		(*closefunc)(fout);
	(void) getreply(0);
E 21
I 21
		(*closefunc)(fout), closefunc = NULL;
E 21
done:
I 21
	if (expectingreply) {
		(void) getreply(0);
		expectingreply = 0;
E 22
I 22
D 24
	if (closefunc != NULL) {
E 24
I 24
	if (closefunc != NULL)
E 24
		(*closefunc)(fout);
E 22
D 24
	}
E 24
E 21
D 25
	signal(SIGINT, oldintr);
E 25
I 25
	(void) signal(SIGINT, oldintr);
E 25
I 22
D 24
	if (oldintp) {
E 24
I 24
	if (oldintp)
E 24
		(void) signal(SIGPIPE, oldintp);
D 24
	}
E 24
D 25
	gettimeofday(&stop, (struct timezone *)0);
E 25
I 25
	(void) gettimeofday(&stop, (struct timezone *)0);
E 25
	(void) fclose(din);
	(void) getreply(0);
E 22
	if (bytes > 0 && verbose)
D 22
		ptransfer("received", bytes, &start, &stop);
E 22
I 22
		ptransfer("received", bytes, &start, &stop, local, remote);
	if (oldtype) {
D 24
		if (!debug) {
E 24
I 24
		if (!debug)
E 24
			verbose = 0;
D 24
		}
E 24
		switch (oldtype) {
			case TYPE_I:
				setbinary();
				break;
			case TYPE_E:
				setebcdic();
				break;
			case TYPE_L:
				settenex();
				break;
		}
		verbose = oldverbose;
	}
E 22
	return;
D 22
bad:
	if (data >= 0)
		(void) close(data), data = -1;
	if (closefunc != NULL && fout != NULL)
E 22
I 22
abort:

D 29
/* if server command parser understands TELNET commands, abort using */
/* recommended IP,SYNC sequence                                      */
E 29
I 29
/* abort using RFC959 recommended IP,SYNC sequence  */
E 29

D 25
	gettimeofday(&stop, (struct timezone *)0);
E 25
I 25
	(void) gettimeofday(&stop, (struct timezone *)0);
E 25
D 24
	if (oldintp) {
E 24
I 24
	if (oldintp)
E 24
		(void) signal(SIGPIPE, oldintr);
D 24
	}
E 24
	(void) signal(SIGINT,SIG_IGN);
	if (oldtype) {
D 24
		if (!debug) {
E 24
I 24
		if (!debug)
E 24
			verbose = 0;
D 24
		}
E 24
		switch (oldtype) {
			case TYPE_I:
				setbinary();
				break;
			case TYPE_E:
				setebcdic();
				break;
			case TYPE_L:
				settenex();
				break;
		}
		verbose = oldverbose;
	}
	if (!cpend) {
		code = -1;
		(void) signal(SIGINT,oldintr);
		return;
	}
D 29
	if (telflag) {
		char msg[2];
E 29

D 29
		fprintf(cout,"%c%c",IAC,IP);
		(void) fflush(cout); 
		*msg = IAC;
		*(msg+1) = DM;
D 24
		if (send(fileno(cout),msg,2,MSG_OOB) != 2) {
E 24
I 24
		if (send(fileno(cout),msg,2,MSG_OOB) != 2)
E 24
			perror("abort");
E 29
I 29
	fprintf(cout,"%c%c",IAC,IP);
	(void) fflush(cout); 
	msg = IAC;
/* send IAC in urgent mode instead of DM because UNIX places oob mark */
/* after urgent byte rather than before as now is protocol            */
	if (send(fileno(cout),&msg,1,MSG_OOB) != 1) {
		perror("abort");
E 29
D 24
		}
E 24
	}
D 29
	fprintf(cout,"ABOR\r\n");
E 29
I 29
	fprintf(cout,"%cABOR\r\n",DM);
E 29
	(void) fflush(cout);
D 25
	mask = (1 << fileno(cin)) | (din ? (1 << fileno(din)) : 0);
	if ((mask = empty(mask,10)) < 0) {
E 25
I 25
D 29
	FD_ZERO((char *) &mask);
E 29
I 29
	FD_ZERO(&mask);
E 29
	FD_SET(fileno(cin), &mask);
	if (din) { 
		FD_SET(fileno(din), &mask);
	}
D 29
	if (empty(mask,10) < 0) {
E 25
		perror("abort");
E 29
I 29
	if ((nfnd = empty(&mask,10)) <= 0) {
		if (nfnd < 0) {
			perror("abort");
		}
E 29
		code = -1;
		lostpeer();
	}
D 24
	if (din && mask & (1 << fileno(din))) {
		while ((c = read(fileno(din), buf, sizeof (buf))) > 0);
	}
E 24
I 24
D 25
	if (din && mask & (1 << fileno(din)))
E 25
I 25
	if (din && FD_ISSET(fileno(din), &mask)) {
E 25
		while ((c = read(fileno(din), buf, sizeof (buf))) > 0)
			;
I 25
	}
E 25
E 24
D 29
	if ((c = getreply(0)) == ERROR) { /* needed for nic style abort */
E 29
I 29
	if ((c = getreply(0)) == ERROR && code == 552) { /* needed for nic style abort */
E 29
		if (data >= 0) {
D 25
			close(data);
E 25
I 25
			(void) close(data);
E 25
			data = -1;
		}
		(void) getreply(0);
	}
	(void) getreply(0);
	code = -1;
	if (data >= 0) {
		(void) close(data);
		data = -1;
	}
D 24
	if (closefunc != NULL && fout != NULL) {
E 24
I 24
	if (closefunc != NULL && fout != NULL)
E 24
E 22
		(*closefunc)(fout);
I 21
D 22
	bytes = 0;	/* so we don't print a message if the transfer was aborted */
E 21
	goto done;
E 22
I 22
D 24
	}
	if (din) {
E 24
I 24
	if (din)
E 24
		(void) fclose(din);
D 24
	}
E 24
	if (bytes > 0 && verbose)
		ptransfer("received", bytes, &start, &stop, local, remote);
	(void) signal(SIGINT,oldintr);
E 22
}

/*
 * Need to start a listen on the data channel
 * before we send the command, otherwise the
 * server's connect may fail.
 */
I 7
D 33
static int sendport = -1;
E 33
I 33
int sendport = -1;
E 33

E 7
initconn()
{
	register char *p, *a;
D 6
	int result;
E 6
I 6
D 22
	int result, len;
E 22
I 22
	int result, len, tmpno = 0;
E 22
I 14
D 25
	int on = 1;
E 25
I 25
D 28
	char on = 1;
E 28
I 28
	int on = 1;
E 28
E 25
E 14
E 6

I 7
noport:
E 7
	data_addr = myctladdr;
D 7
	data_addr.sin_port = 0;		/* let system pick one */
E 7
I 7
	if (sendport)
		data_addr.sin_port = 0;	/* let system pick one */ 
	if (data != -1)
		(void) close (data);
E 7
D 16
	data = socket(AF_INET, SOCK_STREAM, 0, 0);
E 16
I 16
	data = socket(AF_INET, SOCK_STREAM, 0);
E 16
	if (data < 0) {
		perror("ftp: socket");
I 22
D 24
		if (tmpno) {
E 24
I 24
		if (tmpno)
E 24
			sendport = 1;
D 24
		}
E 24
E 22
		return (1);
	}
I 8
	if (!sendport)
D 14
		if (setsockopt(data, SOL_SOCKET, SO_REUSEADDR, 0, 0) < 0) {
E 14
I 14
D 29
		if (setsockopt(data, SOL_SOCKET, SO_REUSEADDR, &on, sizeof (on)) < 0) {
E 29
I 29
		if (setsockopt(data, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof (on)) < 0) {
E 29
E 14
D 21
			perror("ftp: setsockopt (resuse address)");
E 21
I 21
D 22
			perror("ftp: setsockopt (reuse address)");
E 22
I 22
D 33
			perror("ftp: setsockopt (resuse address)");
E 33
I 33
			perror("ftp: setsockopt (reuse address)");
E 33
E 22
E 21
			goto bad;
		}
E 8
D 25
	if (bind(data, (char *)&data_addr, sizeof (data_addr), 0) < 0) {
E 25
I 25
	if (bind(data, (struct sockaddr *)&data_addr, sizeof (data_addr)) < 0) {
E 25
		perror("ftp: bind");
		goto bad;
	}
D 2
#ifdef notdef
E 2
	if (options & SO_DEBUG &&
D 14
	    setsockopt(data, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 14
I 14
D 29
	    setsockopt(data, SOL_SOCKET, SO_DEBUG, &on, sizeof (on)) < 0)
E 29
I 29
	    setsockopt(data, SOL_SOCKET, SO_DEBUG, (char *)&on, sizeof (on)) < 0)
E 29
E 14
		perror("ftp: setsockopt (ignored)");
D 2
#endif
E 2
D 6
	if (socketaddr(data, &data_addr) < 0) {
		perror("ftp: socketaddr");
E 6
I 6
	len = sizeof (data_addr);
	if (getsockname(data, (char *)&data_addr, &len) < 0) {
		perror("ftp: getsockname");
E 6
		goto bad;
	}
D 24
	if (listen(data, 1) < 0) {
E 24
I 24
	if (listen(data, 1) < 0)
E 24
		perror("ftp: listen");
D 22
		goto bad;
E 22
I 22
D 24
		
E 22
	}
E 24
D 7
	a = (char *)&data_addr.sin_addr;
	p = (char *)&data_addr.sin_port;
E 7
I 7
	if (sendport) {
		a = (char *)&data_addr.sin_addr;
		p = (char *)&data_addr.sin_port;
E 7
#define	UC(b)	(((int)b)&0xff)
D 7
	result =
	    command("PORT %d,%d,%d,%d,%d,%d",
	      UC(a[0]), UC(a[1]), UC(a[2]), UC(a[3]),
	      UC(p[0]), UC(p[1]));
	return (result != COMPLETE);
E 7
I 7
		result =
		    command("PORT %d,%d,%d,%d,%d,%d",
		      UC(a[0]), UC(a[1]), UC(a[2]), UC(a[3]),
		      UC(p[0]), UC(p[1]));
		if (result == ERROR && sendport == -1) {
			sendport = 0;
I 22
			tmpno = 1;
E 22
			goto noport;
		}
		return (result != COMPLETE);
	}
I 22
D 24
	if (tmpno) {
E 24
I 24
	if (tmpno)
E 24
		sendport = 1;
D 24
	}
E 24
E 22
	return (0);
E 7
bad:
	(void) close(data), data = -1;
I 22
D 24
	if (tmpno) {
E 24
I 24
	if (tmpno)
E 24
		sendport = 1;
D 24
	}
E 24
E 22
	return (1);
}

FILE *
dataconn(mode)
	char *mode;
{
	struct sockaddr_in from;
	int s, fromlen = sizeof (from);

D 25
	s = accept(data, &from, &fromlen, 0);
E 25
I 25
	s = accept(data, (struct sockaddr *) &from, &fromlen);
E 25
	if (s < 0) {
		perror("ftp: accept");
		(void) close(data), data = -1;
		return (NULL);
	}
	(void) close(data);
	data = s;
I 9
D 11
	if (*mode == 'w' && linger)
		(void) setsockopt(s, SOL_SOCKET, SO_LINGER, &linger,
		    sizeof (linger));
E 11
E 9
	return (fdopen(data, mode));
}

D 22
ptransfer(direction, bytes, t0, t1)
	char *direction;
E 22
I 22
ptransfer(direction, bytes, t0, t1, local, remote)
	char *direction, *local, *remote;
E 22
D 7
	int bytes;
E 7
I 7
	long bytes;
E 7
	struct timeval *t0, *t1;
{
	struct timeval td;
D 7
	int ms, bs;
E 7
I 7
D 12
	long ms;
	float bs;
E 12
I 12
	float s, bs;
E 12
E 7

	tvsub(&td, t1, t0);
D 12
	ms = (td.tv_sec * 1000) + (td.tv_usec / 1000);
E 12
I 12
	s = td.tv_sec + (td.tv_usec / 1000000.);
E 12
#define	nz(x)	((x) == 0 ? 1 : (x))
D 7
	bs = ((bytes * NBBY * 1000) / nz(ms)) / NBBY;
	printf("%d bytes %s in %d.%02d seconds (%d.%01d Kbytes/s)\n",
		bytes, direction, td.tv_sec, td.tv_usec / 10000,
		bs / 1024, (((bs % 1024) * 10) + 1023) / 1024);
E 7
I 7
D 12
	bs = ((bytes * NBBY * 1000) / (float) nz(ms)) / NBBY;
	printf("%ld bytes %s in %d.%02d seconds (%.2g Kbytes/s)\n",
		bytes, direction, td.tv_sec, td.tv_usec / 10000, bs / 1024.);
E 12
I 12
	bs = bytes / nz(s);
I 22
D 24
	if (local && *local != '-') {
E 24
I 24
	if (local && *local != '-')
E 24
		printf("local: %s ", local);
D 24
	}
	if (remote) {
E 24
I 24
	if (remote)
E 24
		printf("remote: %s\n", remote);
D 24
	}
E 24
E 22
	printf("%ld bytes %s in %.2g seconds (%.2g Kbytes/s)\n",
		bytes, direction, s, bs / 1024.);
E 12
E 7
}

D 25
tvadd(tsum, t0)
E 25
I 25
/*tvadd(tsum, t0)
E 25
	struct timeval *tsum, *t0;
{

	tsum->tv_sec += t0->tv_sec;
	tsum->tv_usec += t0->tv_usec;
	if (tsum->tv_usec > 1000000)
		tsum->tv_sec++, tsum->tv_usec -= 1000000;
D 25
}
E 25
I 25
} */
E 25

tvsub(tdiff, t1, t0)
	struct timeval *tdiff, *t1, *t0;
{

	tdiff->tv_sec = t1->tv_sec - t0->tv_sec;
	tdiff->tv_usec = t1->tv_usec - t0->tv_usec;
	if (tdiff->tv_usec < 0)
		tdiff->tv_sec--, tdiff->tv_usec += 1000000;
I 22
}

psabort()
{
	extern int abrtflag;

	abrtflag++;
}

pswitch(flag)
	int flag;
{
	extern int proxy, abrtflag;
	int (*oldintr)();
	static struct comvars {
		int connect;
D 31
		char name[32];
E 31
I 31
		char name[MAXHOSTNAMELEN];
E 31
		struct sockaddr_in mctl;
		struct sockaddr_in hctl;
		FILE *in;
		FILE *out;
D 29
		int tflag;
E 29
		int tpe;
		int cpnd;
		int sunqe;
		int runqe;
		int mcse;
		int ntflg;
		char nti[17];
		char nto[17];
		int mapflg;
		char mi[MAXPATHLEN];
		char mo[MAXPATHLEN];
		} proxstruct, tmpstruct;
	struct comvars *ip, *op;

	abrtflag = 0;
	oldintr = signal(SIGINT, psabort);
	if (flag) {
D 24
		if (proxy) {
E 24
I 24
		if (proxy)
E 24
			return;
D 24
		}
E 24
		ip = &tmpstruct;
		op = &proxstruct;
		proxy++;
	}
	else {
D 24
		if (!proxy) {
E 24
I 24
		if (!proxy)
E 24
			return;
D 24
		}
E 24
		ip = &proxstruct;
		op = &tmpstruct;
		proxy = 0;
	}
	ip->connect = connected;
	connected = op->connect;
D 25
	strncpy(ip->name, hostname, 31);
E 25
I 25
D 31
	(void) strncpy(ip->name, hostname, 31);
E 25
	(ip->name)[strlen(ip->name)] = '\0';
E 31
I 31
	if (hostname) {
		(void) strncpy(ip->name, hostname, sizeof(ip->name) - 1);
		ip->name[strlen(ip->name)] = '\0';
	} else
		ip->name[0] = 0;
E 31
	hostname = op->name;
	ip->hctl = hisctladdr;
	hisctladdr = op->hctl;
	ip->mctl = myctladdr;
	myctladdr = op->mctl;
	ip->in = cin;
	cin = op->in;
	ip->out = cout;
	cout = op->out;
D 29
	ip->tflag = telflag;
	telflag = op->tflag;
E 29
	ip->tpe = type;
	type = op->tpe;
D 24
	if (!type) {
E 24
I 24
	if (!type)
E 24
		type = 1;
D 24
	}
E 24
	ip->cpnd = cpend;
	cpend = op->cpnd;
	ip->sunqe = sunique;
	sunique = op->sunqe;
	ip->runqe = runique;
	runique = op->runqe;
	ip->mcse = mcase;
	mcase = op->mcse;
	ip->ntflg = ntflag;
	ntflag = op->ntflg;
D 25
	strncpy(ip->nti, ntin, 16);
E 25
I 25
	(void) strncpy(ip->nti, ntin, 16);
E 25
	(ip->nti)[strlen(ip->nti)] = '\0';
D 25
	strcpy(ntin, op->nti);
	strncpy(ip->nto, ntout, 16);
E 25
I 25
	(void) strcpy(ntin, op->nti);
	(void) strncpy(ip->nto, ntout, 16);
E 25
	(ip->nto)[strlen(ip->nto)] = '\0';
D 25
	strcpy(ntout, op->nto);
E 25
I 25
	(void) strcpy(ntout, op->nto);
E 25
	ip->mapflg = mapflag;
	mapflag = op->mapflg;
D 25
	strncpy(ip->mi, mapin, MAXPATHLEN - 1);
E 25
I 25
	(void) strncpy(ip->mi, mapin, MAXPATHLEN - 1);
E 25
	(ip->mi)[strlen(ip->mi)] = '\0';
D 25
	strcpy(mapin, op->mi);
	strncpy(ip->mo, mapout, MAXPATHLEN - 1);
E 25
I 25
	(void) strcpy(mapin, op->mi);
	(void) strncpy(ip->mo, mapout, MAXPATHLEN - 1);
E 25
	(ip->mo)[strlen(ip->mo)] = '\0';
D 25
	strcpy(mapout, op->mo);
E 25
I 25
	(void) strcpy(mapout, op->mo);
E 25
	(void) signal(SIGINT, oldintr);
	if (abrtflag) {
		abrtflag = 0;
		(*oldintr)();
D 24
		}
E 24
I 24
	}
E 24
}

jmp_buf ptabort;
int ptabflg;

abortpt()
{
	printf("\n");
D 25
	fflush(stdout);
E 25
I 25
	(void) fflush(stdout);
E 25
	ptabflg++;
	mflag = 0;
	abrtflag = 0;
	longjmp(ptabort, 1);
}

proxtrans(cmd, local, remote)
	char *cmd, *local, *remote;
{
D 29
	int (*oldintr)(), abortpt(), tmptype, oldtype = 0, secndflag = 0;
E 29
I 29
	int (*oldintr)(), abortpt(), tmptype, oldtype = 0, secndflag = 0, nfnd;
E 29
	extern jmp_buf ptabort;
	char *cmd2;
D 25
	long mask;
E 25
I 25
	struct fd_set mask;
E 25

D 24
	if (strcmp(cmd, "RETR")) {
E 24
I 24
	if (strcmp(cmd, "RETR"))
E 24
		cmd2 = "RETR";
D 24
	}
	else {
E 24
I 24
	else
E 24
		cmd2 = runique ? "STOU" : "STOR";
D 24
	}
E 24
	if (command("PASV") != COMPLETE) {
		printf("proxy server does not support third part transfers.\n");
		return;
	}
	tmptype = type;
	pswitch(0);
	if (!connected) {
		printf("No primary connection\n");
		pswitch(1);
		code = -1;
		return;
	}
	if (type != tmptype) {
		oldtype = type;
		switch (tmptype) {
			case TYPE_A:
				setascii();
				break;
			case TYPE_I:
				setbinary();
				break;
			case TYPE_E:
				setebcdic();
				break;
			case TYPE_L:
				settenex();
				break;
		}
	}
	if (command("PORT %s", pasv) != COMPLETE) {
		switch (oldtype) {
			case 0:
				break;
			case TYPE_A:
				setascii();
				break;
			case TYPE_I:
				setbinary();
				break;
			case TYPE_E:
				setebcdic();
				break;
			case TYPE_L:
				settenex();
				break;
		}
		pswitch(1);
		return;
	}
D 24
	if (setjmp(ptabort)) {
E 24
I 24
	if (setjmp(ptabort))
E 24
		goto abort;
D 24
	}
E 24
	oldintr = signal(SIGINT, abortpt);
	if (command("%s %s", cmd, remote) != PRELIM) {
		(void) signal(SIGINT, oldintr);
		switch (oldtype) {
			case 0:
				break;
			case TYPE_A:
				setascii();
				break;
			case TYPE_I:
				setbinary();
				break;
			case TYPE_E:
				setebcdic();
				break;
			case TYPE_L:
				settenex();
				break;
		}
		pswitch(1);
		return;
	}
	sleep(2);
	pswitch(1);
	secndflag++;
D 24
	if (command("%s %s", cmd2, local) != PRELIM) {
E 24
I 24
	if (command("%s %s", cmd2, local) != PRELIM)
E 24
		goto abort;
D 24
	}
E 24
	ptflag++;
	(void) getreply(0);
	pswitch(0);
	(void) getreply(0);
	(void) signal(SIGINT, oldintr);
	switch (oldtype) {
		case 0:
			break;
		case TYPE_A:
			setascii();
			break;
		case TYPE_I:
			setbinary();
			break;
		case TYPE_E:
			setebcdic();
			break;
		case TYPE_L:
			settenex();
			break;
	}
	pswitch(1);
	ptflag = 0;
	printf("local: %s remote: %s\n", local, remote);
	return;
abort:
	(void) signal(SIGINT, SIG_IGN);
	ptflag = 0;
D 24
	if (strcmp(cmd, "RETR") && !proxy) {
E 24
I 24
	if (strcmp(cmd, "RETR") && !proxy)
E 24
		pswitch(1);
D 24
	}
	else if (!strcmp(cmd, "RETR") && proxy) {
E 24
I 24
	else if (!strcmp(cmd, "RETR") && proxy)
E 24
		pswitch(0);
D 24
	}
E 24
	if (!cpend && !secndflag) {  /* only here if cmd = "STOR" (proxy=1) */
		if (command("%s %s", cmd2, local) != PRELIM) {
			pswitch(0);
			switch (oldtype) {
				case 0:
					break;
				case TYPE_A:
					setascii();
					break;
				case TYPE_I:
					setbinary();
					break;
				case TYPE_E:
					setebcdic();
					break;
				case TYPE_L:
					settenex();
					break;
			}
D 29
			if (cpend && telflag) {
E 29
I 29
			if (cpend) {
E 29
				char msg[2];

				fprintf(cout,"%c%c",IAC,IP);
				(void) fflush(cout); 
				*msg = IAC;
				*(msg+1) = DM;
D 24
				if (send(fileno(cout),msg,2,MSG_OOB) != 2) {
E 24
I 24
				if (send(fileno(cout),msg,2,MSG_OOB) != 2)
E 24
					perror("abort");
D 24
				}
E 24
D 29
			}
			if (cpend) {
E 29
				fprintf(cout,"ABOR\r\n");
				(void) fflush(cout);
D 25
				mask = 1 << fileno(cin);
				if ((mask = empty(mask,10)) < 0) {
E 25
I 25
D 29
				FD_ZERO((char *) &mask);
E 29
I 29
				FD_ZERO(&mask);
E 29
				FD_SET(fileno(cin), &mask);
D 29
				if (empty(mask,10) < 0) {
E 25
					perror("abort");
E 29
I 29
				if ((nfnd = empty(&mask,10)) <= 0) {
					if (nfnd < 0) {
						perror("abort");
					}
E 29
D 24
					if (ptabflg) {
E 24
I 24
					if (ptabflg)
E 24
						code = -1;
D 24
					}
E 24
					lostpeer();
				}
				(void) getreply(0);
				(void) getreply(0);
			}
		}
		pswitch(1);
D 24
		if (ptabflg) {
E 24
I 24
		if (ptabflg)
E 24
			code = -1;
D 24
		}
E 24
		(void) signal(SIGINT, oldintr);
		return;
	}
D 29
	if (cpend && telflag) {
E 29
I 29
	if (cpend) {
E 29
		char msg[2];

		fprintf(cout,"%c%c",IAC,IP);
		(void) fflush(cout); 
		*msg = IAC;
		*(msg+1) = DM;
D 24
		if (send(fileno(cout),msg,2,MSG_OOB) != 2) {
E 24
I 24
		if (send(fileno(cout),msg,2,MSG_OOB) != 2)
E 24
			perror("abort");
D 24
		}
E 24
D 29
	}
	if (cpend) {
E 29
		fprintf(cout,"ABOR\r\n");
		(void) fflush(cout);
D 25
		mask = 1 << fileno(cin);
		if ((mask = empty(mask,10)) < 0) {
E 25
I 25
D 29
		FD_ZERO((char *) &mask);
E 29
I 29
		FD_ZERO(&mask);
E 29
		FD_SET(fileno(cin), &mask);
D 29
		if ((empty(mask,10)) < 0) {
E 25
			perror("abort");
E 29
I 29
		if ((nfnd = empty(&mask,10)) <= 0) {
			if (nfnd < 0) {
				perror("abort");
			}
E 29
D 24
			if (ptabflg) {
E 24
I 24
			if (ptabflg)
E 24
				code = -1;
D 24
			}
E 24
			lostpeer();
		}
		(void) getreply(0);
		(void) getreply(0);
	}
	pswitch(!proxy);
	if (!cpend && !secndflag) {  /* only if cmd = "RETR" (proxy=1) */
		if (command("%s %s", cmd2, local) != PRELIM) {
			pswitch(0);
			switch (oldtype) {
				case 0:
					break;
				case TYPE_A:
					setascii();
					break;
				case TYPE_I:
					setbinary();
					break;
				case TYPE_E:
					setebcdic();
					break;
				case TYPE_L:
					settenex();
					break;
			}
D 29
			if (cpend && telflag) {
E 29
I 29
			if (cpend) {
E 29
				char msg[2];

				fprintf(cout,"%c%c",IAC,IP);
				(void) fflush(cout); 
				*msg = IAC;
				*(msg+1) = DM;
D 24
				if (send(fileno(cout),msg,2,MSG_OOB) != 2) {
E 24
I 24
				if (send(fileno(cout),msg,2,MSG_OOB) != 2)
E 24
					perror("abort");
D 24
				}
E 24
D 29
			}
			if (cpend) {
E 29
				fprintf(cout,"ABOR\r\n");
				(void) fflush(cout);
D 25
				mask = 1 << fileno(cin);
				if ((mask = empty(mask,10)) < 0) {
E 25
I 25
D 29
				FD_ZERO((char *) &mask);
E 29
I 29
				FD_ZERO(&mask);
E 29
				FD_SET(fileno(cin), &mask);
D 29
				if (empty(mask,10) < 0) {
E 25
					perror("abort");
E 29
I 29
				if ((nfnd = empty(&mask,10)) <= 0) {
					if (nfnd < 0) {
						perror("abort");
					}
E 29
D 24
					if (ptabflg) {
E 24
I 24
					if (ptabflg)
E 24
						code = -1;
D 24
					}
E 24
					lostpeer();
				}
				(void) getreply(0);
				(void) getreply(0);
			}
			pswitch(1);
D 24
			if (ptabflg) {
E 24
I 24
			if (ptabflg)
E 24
				code = -1;
D 24
			}
E 24
			(void) signal(SIGINT, oldintr);
			return;
		}
	}
D 29
	if (cpend && telflag) {
E 29
I 29
	if (cpend) {
E 29
		char msg[2];

		fprintf(cout,"%c%c",IAC,IP);
		(void) fflush(cout); 
		*msg = IAC;
		*(msg+1) = DM;
D 24
		if (send(fileno(cout),msg,2,MSG_OOB) != 2) {
E 24
I 24
		if (send(fileno(cout),msg,2,MSG_OOB) != 2)
E 24
			perror("abort");
D 24
		}
E 24
D 29
	}
	if (cpend) {
E 29
		fprintf(cout,"ABOR\r\n");
		(void) fflush(cout);
D 25
		mask = 1 << fileno(cin);
		if ((mask = empty(mask,10)) < 0) {
E 25
I 25
D 29
		FD_ZERO((char *) &mask);
E 29
I 29
		FD_ZERO(&mask);
E 29
		FD_SET(fileno(cin), &mask);
D 29
		if (empty(mask,10) < 0) {
E 25
			perror("abort");
E 29
I 29
		if ((nfnd = empty(&mask,10)) <= 0) {
			if (nfnd < 0) {
				perror("abort");
			}
E 29
D 24
			if (ptabflg) {
E 24
I 24
			if (ptabflg)
E 24
				code = -1;
D 24
			}
E 24
			lostpeer();
		}
		(void) getreply(0);
		(void) getreply(0);
	}
	pswitch(!proxy);
	if (cpend) {
D 25
		mask = 1 << fileno(cin);
		if ((mask = empty(mask,10)) < 0) {
E 25
I 25
D 29
		FD_ZERO((char *) &mask);
E 29
I 29
		FD_ZERO(&mask);
E 29
		FD_SET(fileno(cin), &mask);
D 29
		if (empty(mask,10) < 0) {
E 25
			perror("abort");
E 29
I 29
		if ((nfnd = empty(&mask,10)) <= 0) {
			if (nfnd < 0) {
				perror("abort");
			}
E 29
D 24
			if (ptabflg) {
E 24
I 24
			if (ptabflg)
E 24
				code = -1;
D 24
			}
E 24
			lostpeer();
		}
		(void) getreply(0);
		(void) getreply(0);
	}
D 24
	if (proxy) {
E 24
I 24
	if (proxy)
E 24
		pswitch(0);
D 24
	}
E 24
	switch (oldtype) {
		case 0:
			break;
		case TYPE_A:
			setascii();
			break;
		case TYPE_I:
			setbinary();
			break;
		case TYPE_E:
			setebcdic();
			break;
		case TYPE_L:
			settenex();
			break;
	}
	pswitch(1);
D 24
	if (ptabflg) {
E 24
I 24
	if (ptabflg)
E 24
		code = -1;
D 24
	}
E 24
	(void) signal(SIGINT, oldintr);
}

reset()
{
D 25
	long mask;
E 25
I 25
	struct fd_set mask;
	int nfnd = 1;
E 25

D 25
	mask = 1 << fileno(cin);
	while (mask > 0) {
		if ((mask = empty(mask,0)) < 0) {
E 25
I 25
D 29
	FD_ZERO((char *) &mask);
E 29
I 29
	FD_ZERO(&mask);
E 29
D 32
	while (nfnd) {
E 32
I 32
	while (nfnd > 0) {
E 32
		FD_SET(fileno(cin), &mask);
D 29
		if ((nfnd = empty(mask,0)) < 0) {
E 29
I 29
		if ((nfnd = empty(&mask,0)) < 0) {
E 29
E 25
			perror("reset");
			code = -1;
			lostpeer();
		}
D 24
		if (mask > 0) {
E 24
I 24
D 25
		if (mask > 0)
E 25
I 25
D 29
		else {
E 29
I 29
		else if (nfnd) {
E 29
E 25
E 24
			(void) getreply(0);
I 25
		}
E 25
D 24
		}
E 24
	}
}

char *
gunique(local)
	char *local;
{
	static char new[MAXPATHLEN];
	char *cp = rindex(local, '/');
	int d, count=0;
	char ext = '1';

D 24
	if (cp) {
E 24
I 24
	if (cp)
E 24
		*cp = '\0';
D 24
	}
E 24
	d = access(cp ? local : ".", 2);
D 24
	if (cp) {
E 24
I 24
	if (cp)
E 24
		*cp = '/';
D 24
	}
E 24
	if (d < 0) {
		perror(local);
		return((char *) 0);
	}
	(void) strcpy(new, local);
	cp = new + strlen(new);
	*cp++ = '.';
	while (!d) {
		if (++count == 100) {
			printf("runique: can't find unique file name.\n");
			return((char *) 0);
		}
		*cp++ = ext;
		*cp = '\0';
D 24
		if (ext == '9') {
E 24
I 24
		if (ext == '9')
E 24
			ext = '0';
D 24
		}
		else {
E 24
I 24
		else
E 24
			ext++;
D 24
		}
		if ((d = access(new, 0)) < 0) {
E 24
I 24
		if ((d = access(new, 0)) < 0)
E 24
			break;
D 24
		}
		if (ext != '0') {
E 24
I 24
		if (ext != '0')
E 24
			cp--;
D 24
		}
		else if (*(cp - 2) == '.') {
E 24
I 24
		else if (*(cp - 2) == '.')
E 24
			*(cp - 1) = '1';
D 24
		}
E 24
		else {
			*(cp - 2) = *(cp - 2) + 1;
			cp--;
		}
	}
	return(new);
E 22
}
E 1
