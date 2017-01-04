h24734
s 00001/00001/00857
d D 5.6 87/12/22 13:49:04 bostic 20 19
c make ANSI C compatible
e
s 00004/00002/00854
d D 5.5 87/02/09 12:08:28 karels 19 18
c formalize uid swapping and force everywhere
e
s 00003/00002/00853
d D 5.4 86/05/05 11:00:43 sam 18 17
c add ~^Y to stop local side only (a la rlogin)
e
s 00002/00000/00853
d D 5.3 86/01/13 19:27:46 karels 17 16
c use setreuid to retain setuid uid for cleanup of lock files
e
s 00048/00000/00805
d D 5.2 85/11/29 19:11:34 donn 16 15
c Added pipeout() command (~$) -- run a local command and send its
c output to the remote system.
e
s 00007/00001/00798
d D 5.1 85/04/30 12:40:47 dist 15 14
c Add copyright
e
s 00007/00006/00792
d D 4.14 84/09/12 11:57:16 ralph 14 13
c restore sigint correctly, print 0 seconds if time == 0.
e
s 00016/00007/00782
d D 4.13 83/10/08 13:57:57 sam 13 12
c recognize and handle carrier loss
e
s 00026/00077/00763
d D 4.12 83/06/25 01:13:20 sam 12 11
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00230/00034/00610
d D 4.11 83/06/15 13:51:46 ralph 11 10
c changes for local info, parity, vadic auto dialers
e
s 00001/00001/00643
d D 4.10 82/09/02 16:55:46 sam 10 9
c make TIOCSBRK less VAX dependent
e
s 00005/00005/00639
d D 4.9 82/07/29 14:43:52 shannon 9 8
c 68000 fixes
e
s 00001/00001/00643
d D 4.8 82/01/06 10:55:13 shannon 8 7
c fix bugs with beautify and scripting
e
s 00014/00002/00630
d D 4.7 81/11/29 22:49:17 sam 7 6
c reformatting
e
s 00000/00000/00632
d D 4.6 81/11/20 10:44:23 sam 6 5
c cosmetics
e
s 00000/00003/00632
d D 4.5 81/07/11 14:04:33 sam 5 4
c cleanup after "hw" attribute addition (instead of shannon mods)
e
s 00006/00000/00629
d D 4.4 81/06/09 12:29:32 sam 4 3
c fix problem with scripting
e
s 00035/00014/00594
d D 4.3 81/06/02 10:00:28 sam 3 2
c added echocheck mode for ftp (from decvax!shannon)
e
s 00025/00000/00583
d D 4.2 81/05/31 15:03:07 sam 2 1
c added break command from decvax!shannon
e
s 00583/00000/00000
d D 4.1 81/05/09 16:45:10 root 1 0
c date and time created 81/05/09 16:45:10 by root
e
u
U
t
T
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 15
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif
E 15
I 15
#endif not lint
E 15

E 12
#include "tip.h"
/*
 * tip
 *
 * miscellaneous commands
 */

I 11
D 12
static char *sccsid = "%W% %G%";

E 12
E 11
int	quant[] = { 60, 60, 24 };

char	null = '\0';
char	*sep[] = { "second", "minute", "hour" };
static char *argv[10];		/* argument vector for take and put */

int	timeout();		/* timeout function called on alarm */
int	stopsnd();		/* SIGINT handler during file transfers */
int	intprompt();		/* used in handling SIG_INT during prompt */
int	intcopy();		/* interrupt routine for file transfers */

/*
 * FTP - remote ==> local
 *  get a file from the remote host
 */
getfl(c)
	char c;
{
D 12
	char buf[256];
I 11
	char *copynamex;
	char *expand();
E 12
I 12
	char buf[256], *cp, *expand();
E 12
E 11
	
	putchar(c);
	/*
	 * get the UNIX receiving file's name
	 */
	if (prompt("Local file name? ", copyname))
		return;
D 11
	if ((sfd = creat(copyname, 0666)) < 0) {
E 11
I 11
D 12
	copynamex = expand(copyname);
	if ((sfd = creat(copynamex, 0666)) < 0) {
E 12
I 12
	cp = expand(copyname);
	if ((sfd = creat(cp, 0666)) < 0) {
E 12
E 11
		printf("\r\n%s: cannot creat\r\n", copyname);
		return;
	}
	
	/*
	 * collect parameters
	 */
	if (prompt("List command for remote system? ", buf)) {
		unlink(copyname);
		return;
	}
	transfer(buf, sfd, value(EOFREAD));
}

/*
 * Cu-like take command
 */
cu_take(cc)
	char cc;
{
	int fd, argc;
D 12
	char line[BUFSIZ];
I 11
	char *expand();
	char *copynamex;
E 12
I 12
	char line[BUFSIZ], *expand(), *cp;
E 12
E 11

	if (prompt("[take] ", copyname))
		return;
	if ((argc = args(copyname, argv)) < 1 || argc > 2) {
		printf("usage: <take> from [to]\r\n");
		return;
	}
	if (argc == 1)
		argv[1] = argv[0];
D 11
	if ((fd = creat(argv[1], 0666)) < 0) {
E 11
I 11
D 12
	copynamex = expand(argv[1]);
	if ((fd = creat(copynamex, 0666)) < 0) {
E 12
I 12
	cp = expand(argv[1]);
	if ((fd = creat(cp, 0666)) < 0) {
E 12
E 11
		printf("\r\n%s: cannot create\r\n", argv[1]);
		return;
	}
D 11
	sprintf(line, "cat '%s';echo \01", argv[0]);
E 11
I 11
	sprintf(line, "cat %s;echo \01", argv[0]);
E 11
	transfer(line, fd, "\01");
}

I 12
static	jmp_buf intbuf;
E 12
/*
 * Bulk transfer routine --
 *  used by getfl(), cu_take(), and pipefile()
 */
transfer(buf, fd, eofchars)
	char *buf, *eofchars;
{
	register int ct;
	char c, buffer[BUFSIZ];
	register char *p = buffer;
	register int cnt, eof;
	time_t start;
I 12
	int (*f)();
E 12

D 11
	write(FD, buf, size(buf));
E 11
I 11
	pwrite(FD, buf, size(buf));
E 11
	quit = 0;
D 12
	signal(SIGINT, intcopy);
E 12
	kill(pid, SIGIOT);
	read(repdes[0], (char *)&ccc, 1);  /* Wait until read process stops */
	
	/*
	 * finish command
	 */
D 11
	write(FD, "\r", 1);
E 11
I 11
	pwrite(FD, "\r", 1);
E 11
	do
		read(FD, &c, 1); 
	while ((c&0177) != '\n');
	ioctl(0, TIOCSETC, &defchars);
	
I 14
	(void) setjmp(intbuf);
E 14
I 12
	f = signal(SIGINT, intcopy);
E 12
	start = time(0);
I 12
D 14
	(void) setjmp(intbuf);
E 14
E 12
	for (ct = 0; !quit;) {
		eof = read(FD, &c, 1) <= 0;
		c &= 0177;
		if (quit)
			continue;
		if (eof || any(c, eofchars))
			break;
		if (c == 0)
			continue;	/* ignore nulls */
		if (c == '\r')
			continue;
		*p++ = c;

		if (c == '\n' && boolean(value(VERBOSE)))
			printf("\r%d", ++ct);
		if ((cnt = (p-buffer)) == number(value(FRAMESIZE))) {
			if (write(fd, buffer, cnt) != cnt) {
				printf("\r\nwrite error\r\n");
				quit = 1;
			}
			p = buffer;
		}
	}
	if (cnt = (p-buffer))
		if (write(fd, buffer, cnt) != cnt)
			printf("\r\nwrite error\r\n");

	if (boolean(value(VERBOSE)))
		prtime(" lines transferred in ", time(0)-start);
	ioctl(0, TIOCSETC, &tchars);
	write(fildes[1], (char *)&ccc, 1);
D 14
	signal(SIGINT, SIG_DFL);
E 14
I 14
	signal(SIGINT, f);
E 14
	close(fd);
}

/*
 * FTP - remote ==> local process
 *   send remote input to local process via pipe
 */
pipefile()
{
	int cpid, pdes[2];
	char buf[256];
	int status, p;
	extern int errno;

	if (prompt("Local command? ", buf))
		return;

	if (pipe(pdes)) {
		printf("can't establish pipe\r\n");
		return;
	}

	if ((cpid = fork()) < 0) {
		printf("can't fork!\r\n");
		return;
	} else if (cpid) {
		if (prompt("List command for remote system? ", buf)) {
			close(pdes[0]), close(pdes[1]);
			kill (cpid, SIGKILL);
		} else {
			close(pdes[0]);
			signal(SIGPIPE, intcopy);
			transfer(buf, pdes[1], value(EOFREAD));
			signal(SIGPIPE, SIG_DFL);
			while ((p = wait(&status)) > 0 && p != cpid)
				;
		}
	} else {
		register int f;

		dup2(pdes[0], 0);
		close(pdes[0]);
		for (f = 3; f < 20; f++)
			close(f);
		execute(buf);
		printf("can't execl!\r\n");
		exit(0);
	}
}

/*
 * Interrupt service routine for FTP
 */
stopsnd()
{
I 12

E 12
	stop = 1;
	signal(SIGINT, SIG_IGN);
}

/*
 * FTP - local ==> remote
 *  send local file to remote host
 *  terminate transmission with pseudo EOF sequence
 */
sendfile(cc)
	char cc;
{
	FILE *fd;
I 11
	char *fnamex;
	char *expand();
E 11

	putchar(cc);
	/*
	 * get file name
	 */
	if (prompt("Local file name? ", fname))
		return;

	/*
	 * look up file
	 */
D 11
	if ((fd = fopen(fname, "r")) == NULL) {
E 11
I 11
	fnamex = expand(fname);
	if ((fd = fopen(fnamex, "r")) == NULL) {
E 11
		printf("%s: cannot open\r\n", fname);
		return;
	}
	transmit(fd, value(EOFWRITE), NULL);
I 3
	if (!boolean(value(ECHOCHECK))) {
		struct sgttyb buf;

		ioctl(FD, TIOCGETP, &buf);	/* this does a */
		ioctl(FD, TIOCSETP, &buf);	/*   wflushtty */
	}
E 3
}

/*
 * Bulk transfer routine to remote host --
 *   used by sendfile() and cu_put()
 */
transmit(fd, eofchars, command)
	FILE *fd;
	char *eofchars, *command;
{
D 9
	char *pc, lastc;
E 9
I 9
D 11
	char *pc, lastc, rc;
E 11
I 11
	char *pc, lastc;
E 11
E 9
	int c, ccount, lcount;
	time_t start_t, stop_t;
I 14
	int (*f)();
E 14

	kill(pid, SIGIOT);	/* put TIPOUT into a wait state */
D 14
	signal(SIGINT, stopsnd);
E 14
	stop = 0;
I 14
	f = signal(SIGINT, stopsnd);
E 14
	ioctl(0, TIOCSETC, &defchars);
	read(repdes[0], (char *)&ccc, 1);
	if (command != NULL) {
		for (pc = command; *pc; pc++)
			send(*pc);
D 3
		read(FD, (char *)&c, 1);	/* trailing \n */
E 3
I 3
		if (boolean(value(ECHOCHECK)))
			read(FD, (char *)&c, 1);	/* trailing \n */
		else {
			struct sgttyb buf;

			ioctl(FD, TIOCGETP, &buf);	/* this does a */
			ioctl(FD, TIOCSETP, &buf);	/*   wflushtty */
			sleep(5); /* wait for remote stty to take effect */
		}
E 3
	}
	lcount = 0;
	lastc = '\0';
	start_t = time(0);
D 7
	while(1) {
E 7
I 7
	while (1) {
E 7
		ccount = 0;
		do {
			c = getc(fd);
			if (stop)
				goto out;
			if (c == EOF)
				goto out;
D 11
			if (c == 0177)
E 11
I 11
			if (c == 0177 && !boolean(value(RAWFTP)))
E 11
				continue;
			lastc = c;
			if (c < 040) {
D 11
				if (c == '\n')
					c = '\r';
E 11
I 11
				if (c == '\n') {
					if (!boolean(value(RAWFTP)))
						c = '\r';
				}
E 11
				else if (c == '\t') {
D 11
					if (boolean(value(TABEXPAND))) {
						send(' ');
D 7
						while((++ccount % 8) != 0)
E 7
I 7
						while ((++ccount % 8) != 0)
E 11
I 11
					if (!boolean(value(RAWFTP))) {
						if (boolean(value(TABEXPAND))) {
E 11
E 7
							send(' ');
D 11
						continue;
E 11
I 11
							while ((++ccount % 8) != 0)
								send(' ');
							continue;
						}
E 11
					}
D 9
				} else
E 9
I 9
D 11
				} else if (!any(c, value(EXCEPTIONS)))
E 9
					continue;
E 11
I 11
				} else
					if (!boolean(value(RAWFTP)))
						continue;
E 11
			}
			send(c);
D 11
		} while (c != '\r');
E 11
I 11
		} while (c != '\r' && !boolean(value(RAWFTP)));
E 11
		if (boolean(value(VERBOSE)))
			printf("\r%d", ++lcount);
D 3
		alarm(10);
		timedout = 0;
		do {	/* wait for prompt */
			read(FD, (char *)&c, 1);
			if (timedout || stop) {
				if (timedout)
					printf("\r\ntimed out at eol\r\n");
				alarm(0);
				goto out;
			}
		} while ((c&0177) != character(value(PROMPT)));
		alarm(0);
E 3
I 3
		if (boolean(value(ECHOCHECK))) {
D 11
			alarm(10);
E 11
I 11
D 14
			alarm(value(ETIMEOUT));
E 14
E 11
			timedout = 0;
I 14
			alarm(value(ETIMEOUT));
E 14
			do {	/* wait for prompt */
D 9
				read(FD, (char *)&c, 1);
E 9
I 9
D 11
				read(FD, (char *)&rc, 1);
E 11
I 11
				read(FD, (char *)&c, 1);
E 11
E 9
				if (timedout || stop) {
					if (timedout)
						printf("\r\ntimed out at eol\r\n");
					alarm(0);
					goto out;
				}
D 9
			} while ((c&0177) != character(value(PROMPT)));
E 9
I 9
D 11
			} while ((rc&0177) != character(value(PROMPT)));
E 11
I 11
			} while ((c&0177) != character(value(PROMPT)));
E 11
E 9
			alarm(0);
		}
E 3
	}
out:
D 11
	if (lastc != '\n')
E 11
I 11
	if (lastc != '\n' && !boolean(value(RAWFTP)))
E 11
		send('\r');
	for (pc = eofchars; *pc; pc++)
		send(*pc);
	stop_t = time(0);
	fclose(fd);
D 14
	signal(SIGINT, SIG_DFL);
E 14
I 14
	signal(SIGINT, f);
E 14
	if (boolean(value(VERBOSE)))
D 11
		prtime(" lines transferred in ", stop_t-start_t);
E 11
I 11
		if (boolean(value(RAWFTP)))
			prtime(" chars transferred in ", stop_t-start_t);
		else
			prtime(" lines transferred in ", stop_t-start_t);
E 11
	write(fildes[1], (char *)&ccc, 1);
	ioctl(0, TIOCSETC, &tchars);
}

/*
 * Cu-like put command
 */
cu_put(cc)
	char cc;
{
	FILE *fd;
	char line[BUFSIZ];
	int argc;
I 11
	char *expand();
	char *copynamex;
E 11

	if (prompt("[put] ", copyname))
		return;
	if ((argc = args(copyname, argv)) < 1 || argc > 2) {
		printf("usage: <put> from [to]\r\n");
		return;
	}
	if (argc == 1)
		argv[1] = argv[0];
D 11
	if ((fd = fopen(argv[0], "r")) == NULL) {
		printf("%s: cannot open\r\n", argv[0]);
E 11
I 11
	copynamex = expand(argv[0]);
	if ((fd = fopen(copynamex, "r")) == NULL) {
		printf("%s: cannot open\r\n", copynamex);
E 11
		return;
	}
D 3
	sprintf(line, "cat>'%s'\r", argv[1]);
E 3
I 3
	if (boolean(value(ECHOCHECK)))
D 11
		sprintf(line, "cat>'%s'\r", argv[1]);
E 11
I 11
		sprintf(line, "cat>%s\r", argv[1]);
E 11
	else
D 11
		sprintf(line, "stty -echo;cat>'%s';stty echo\r", argv[1]);
E 11
I 11
		sprintf(line, "stty -echo;cat>%s;stty echo\r", argv[1]);
E 11
E 3
	transmit(fd, "\04", line);
}

/*
 * FTP - send single character
 *  wait for echo & handle timeout
 */
send(c)
	char c;
{
D 9
	int cc;
E 9
I 9
	char cc;
E 9
	int retry = 0;

	cc = c;
D 11
	write(FD, (char *)&cc, 1);
I 3
	if (!boolean(value(ECHOCHECK)))
E 11
I 11
	pwrite(FD, &cc, 1);
#ifdef notdef
	if (number(value(CDELAY)) > 0 && c != '\r')
		nap(number(value(CDELAY)));
#endif
	if (!boolean(value(ECHOCHECK))) {
#ifdef notdef
		if (number(value(LDELAY)) > 0 && c == '\r')
			nap(number(value(LDELAY)));
#endif
E 11
		return;
I 11
	}
E 11
E 3
tryagain:
	timedout = 0;
D 11
	alarm(10);
	read(FD, (char *)&cc, 1);
E 11
I 11
	alarm(value(ETIMEOUT));
	read(FD, &cc, 1);
E 11
	alarm(0);
	if (timedout) {
		printf("\r\ntimeout error (%s)\r\n", ctrl(c));
		if (retry++ > 3)
			return;
D 11
		write(FD, &null, 1); /* poke it */
E 11
I 11
		pwrite(FD, &null, 1); /* poke it */
E 11
		goto tryagain;
	}
}

timeout()
{
	signal(SIGALRM, timeout);
	timedout = 1;
}

I 16
/*
 * Stolen from consh() -- puts a remote file on the output of a local command.
 *	Identical to consh() except for where stdout goes.
 */
pipeout(c)
{
	char buf[256];
	int cpid, status, p;
	time_t start;

	putchar(c);
	if (prompt("Local command? ", buf))
		return;
	kill(pid, SIGIOT);	/* put TIPOUT into a wait state */
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	ioctl(0, TIOCSETC, &defchars);
	read(repdes[0], (char *)&ccc, 1);
	/*
	 * Set up file descriptors in the child and
	 *  let it go...
	 */
	if ((cpid = fork()) < 0)
		printf("can't fork!\r\n");
	else if (cpid) {
		start = time(0);
		while ((p = wait(&status)) > 0 && p != cpid)
			;
	} else {
		register int i;

		dup2(FD, 1);
		for (i = 3; i < 20; i++)
			close(i);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execute(buf);
		printf("can't find `%s'\r\n", buf);
		exit(0);
	}
	if (boolean(value(VERBOSE)))
		prtime("away for ", time(0)-start);
	write(fildes[1], (char *)&ccc, 1);
	ioctl(0, TIOCSETC, &tchars);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

E 16
#ifdef CONNECT
/*
 * Fork a program with:
 *  0 <-> local tty in
 *  1 <-> local tty out
 *  2 <-> local tty out
 *  3 <-> remote tty in
 *  4 <-> remote tty out
 */
consh(c)
{
	char buf[256];
	int cpid, status, p;
	time_t start;

	putchar(c);
	if (prompt("Local command? ", buf))
		return;
	kill(pid, SIGIOT);	/* put TIPOUT into a wait state */
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	ioctl(0, TIOCSETC, &defchars);
	read(repdes[0], (char *)&ccc, 1);
	/*
	 * Set up file descriptors in the child and
	 *  let it go...
	 */
	if ((cpid = fork()) < 0)
		printf("can't fork!\r\n");
	else if (cpid) {
		start = time(0);
		while ((p = wait(&status)) > 0 && p != cpid)
			;
	} else {
		register int i;

		dup2(FD, 3);
		dup2(3, 4);
		for (i = 5; i < 20; i++)
			close(i);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execute(buf);
		printf("can't find `%s'\r\n", buf);
		exit(0);
	}
	if (boolean(value(VERBOSE)))
		prtime("away for ", time(0)-start);
	write(fildes[1], (char *)&ccc, 1);
	ioctl(0, TIOCSETC, &tchars);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
#endif

/*
I 11
D 12
 * Execute command under local shell
 */
lcmd()
{
	int shpid, status;
	extern char **environ;
	char *cp;
	char	cmdline[255];
	register char *cmdp = cmdline;

	if (prompt("!", cmdline))
		if (stoprompt)
			return;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	unraw();
	if (shpid = fork()) {
		while (shpid != wait(&status));
		raw();
		printf("\r\n!\r\n");
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		return;
	} else {
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		if ((cp = rindex(value(SHELL), '/')) == NULL)
			cp = value(SHELL);
		else
			cp++;
		execl(value(SHELL), cp, "-c", cmdline, 0);
		printf("\r\ncan't execl!\r\n");
		exit(1);
	}
}

/*
E 12
E 11
 * Escape to local shell
 */
shell()
{
	int shpid, status;
	extern char **environ;
	char *cp;

	printf("[sh]\r\n");
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	unraw();
	if (shpid = fork()) {
		while (shpid != wait(&status));
		raw();
		printf("\r\n!\r\n");
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		return;
	} else {
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		if ((cp = rindex(value(SHELL), '/')) == NULL)
			cp = value(SHELL);
		else
			cp++;
I 19
		shell_uid();
E 19
		execl(value(SHELL), cp, 0);
		printf("\r\ncan't execl!\r\n");
		exit(1);
	}
}

/*
 * TIPIN portion of scripting
 *   initiate the conversation with TIPOUT
 */
setscript()
{
	char c;
	/*
	 * enable TIPOUT side for dialogue
	 */
	kill(pid, SIGEMT);
	if (boolean(value(SCRIPT)))
		write(fildes[1], value(RECORD), size(value(RECORD)));
	write(fildes[1], "\n", 1);
	/*
	 * wait for TIPOUT to finish
	 */
	read(repdes[0], &c, 1);
	if (c == 'n')
		printf("can't create %s\r\n", value(RECORD));
}

/*
 * Change current working directory of
 *   local portion of tip
 */
chdirectory()
{
D 12
	char	dirname[80];
E 12
I 12
	char dirname[80];
E 12
	register char *cp = dirname;

D 12
	if (prompt("[cd] ", dirname))
E 12
I 12
	if (prompt("[cd] ", dirname)) {
E 12
		if (stoprompt)
			return;
D 12
		else
			cp = value(HOME);
E 12
I 12
		cp = value(HOME);
	}
E 12
	if (chdir(cp) < 0)
		printf("%s: bad directory\r\n", cp);
	printf("!\r\n");
}

D 13
finish()
E 13
I 13
abort(msg)
	char *msg;
E 13
{
I 11
D 13
	char *dismsg;
E 13

D 13
	if ((dismsg = value(DISCONNECT)) != NOSTR) {
		write(FD,dismsg,strlen(dismsg));
		sleep(5);
	}
E 13
E 11
	kill(pid, SIGTERM);
I 17
D 19
	setreuid(euid, euid);
	setregid(egid, egid);
E 19
E 17
D 13
	disconnect();
E 13
I 13
	disconnect(msg);
	if (msg != NOSTR)
		printf("\r\n%s", msg);
E 13
	printf("\r\n[EOT]\r\n");
I 19
	daemon_uid();
E 19
	delock(uucplock);
D 5
#ifdef VMUNIX
	ioctl(0, TIOCSETD, (char *)&odisc);
#endif
E 5
	unraw();
	exit(0);
I 13
}

finish()
{
	char *dismsg;

	if ((dismsg = value(DISCONNECT)) != NOSTR) {
		write(FD, dismsg, strlen(dismsg));
		sleep(5);
	}
	abort(NOSTR);
E 13
}

intcopy()
{
I 12

E 12
	raw();
	quit = 1;
I 12
	longjmp(intbuf, 1);
E 12
}

execute(s)
	char *s;
{
	register char *cp;

	if ((cp = rindex(value(SHELL), '/')) == NULL)
		cp = value(SHELL);
	else
		cp++;
I 19
	user_uid();
E 19
	execl(value(SHELL), cp, "-c", s, 0);
}

args(buf, a)
	char *buf, *a[];
{
	register char *p = buf, *start;
	register char **parg = a;
	register int n = 0;

	do {
		while (*p && (*p == ' ' || *p == '\t'))
			p++;
		start = p;
		if (*p)
			*parg = p;
		while (*p && (*p != ' ' && *p != '\t'))
			p++;
		if (p != start)
			parg++, n++;
		if (*p)
			*p++ = '\0';
	} while (*p);

	return(n);
}

prtime(s, a)
	char *s;
	time_t a;
{
	register i;
	int nums[3];

	for (i = 0; i < 3; i++) {
		nums[i] = (int)(a % quant[i]);
		a /= quant[i];
	}
	printf("%s", s);
	while (--i >= 0)
D 14
		if (nums[i])
E 14
I 14
		if (nums[i] || i == 0 && nums[1] == 0 && nums[2] == 0)
E 14
			printf("%d %s%c ", nums[i], sep[i],
				nums[i] == 1 ? '\0' : 's');
	printf("\r\n!\r\n");
}

variable()
{
	char	buf[256];

	if (prompt("[set] ", buf))
		return;
	vlex(buf);
	if (vtable[BEAUTIFY].v_access&CHANGED) {
		vtable[BEAUTIFY].v_access &= ~CHANGED;
D 8
		signal(pid, SIGSYS);
E 8
I 8
		kill(pid, SIGSYS);
E 8
	}
	if (vtable[SCRIPT].v_access&CHANGED) {
		vtable[SCRIPT].v_access &= ~CHANGED;
		setscript();
I 4
		/*
		 * So that "set record=blah script" doesn't
		 *  cause two transactions to occur.
		 */
		if (vtable[RECORD].v_access&CHANGED)
			vtable[RECORD].v_access &= ~CHANGED;
E 4
	}
	if (vtable[RECORD].v_access&CHANGED) {
		vtable[RECORD].v_access &= ~CHANGED;
		if (boolean(value(SCRIPT)))
			setscript();
	}
I 11
	if (vtable[TAND].v_access&CHANGED) {
		vtable[TAND].v_access &= ~CHANGED;
		if (boolean(value(TAND)))
			tandem("on");
		else
			tandem("off");
	}
 	if (vtable[LECHO].v_access&CHANGED) {
 		vtable[LECHO].v_access &= ~CHANGED;
 		HD = boolean(value(LECHO));
 	}
	if (vtable[PARITY].v_access&CHANGED) {
		vtable[PARITY].v_access &= ~CHANGED;
		setparity();
	}
E 11
}
I 2

/*
I 11
D 12
 * turn tandem mode on or off for remote tty
E 12
I 12
 * Turn tandem mode on or off for remote tty.
E 12
 */
D 12

E 12
tandem(option)
D 12
char *option;
E 12
I 12
	char *option;
E 12
{
	struct sgttyb rmtty;

	ioctl(FD, TIOCGETP, &rmtty);
	if (strcmp(option,"on") == 0) {
		rmtty.sg_flags |= TANDEM;
		arg.sg_flags |= TANDEM;
D 12
	}
	else {
E 12
I 12
	} else {
E 12
		rmtty.sg_flags &= ~TANDEM;
		arg.sg_flags &= ~TANDEM;
	}
	ioctl(FD, TIOCSETP, &rmtty);
	ioctl(0,  TIOCSETP, &arg);
}

/*
E 11
 * Send a break.
D 12
 * If we can't do it directly (as on VMUNIX), then simulate it.
E 12
 */
genbrk()
{
D 10
#ifdef VMUNIX
E 10
I 10
D 11
#ifdef TIOCSBRK
E 11
I 11
D 12
#ifdef VMUNIX
E 12
I 12

E 12
E 11
E 10
	ioctl(FD, TIOCSBRK, NULL);
	sleep(1);
	ioctl(FD, TIOCCBRK, NULL);
D 12
#else
	struct sgttyb ttbuf;
	int sospeed;

	ioctl(FD, TIOCGETP, &ttbuf);
	sospeed = ttbuf.sg_ospeed;
	ttbuf.sg_ospeed = B150;
	ioctl(FD, TIOCSETP, &ttbuf);
D 11
	write(FD, "\0\0\0\0\0\0\0\0\0\0", 10);
E 11
I 11
	pwrite(FD, "\0\0\0\0\0\0\0\0\0\0", 10);
E 11
	ttbuf.sg_ospeed = sospeed;
	ioctl(FD, TIOCSETP, &ttbuf);
D 11
	write(FD, "@", 1);
E 11
I 11
	pwrite(FD, "@", 1);
E 11
#endif
E 12
}
I 7

D 12
#ifdef SIGTSTP
E 12
/*
 * Suspend tip
 */
D 18
suspend()
E 18
I 18
suspend(c)
	char c;
E 18
{
I 12

E 12
	unraw();
D 18
	kill(0, SIGTSTP);
E 18
I 18
D 20
	kill(c == CTRL(y) ? getpid() : 0, SIGTSTP);
E 20
I 20
	kill(c == CTRL('y') ? getpid() : 0, SIGTSTP);
E 20
E 18
	raw();
}
D 12
#endif
E 12
I 11

/*
 *	expand a file name if it includes shell meta characters
 */

char *
expand(name)
	char name[];
{
	static char xname[BUFSIZ];
	char cmdbuf[BUFSIZ];
	register int pid, l, rc;
	register char *cp, *Shell;
	int s, pivec[2], (*sigint)();

	if (!anyof(name, "~{[*?$`'\"\\"))
		return(name);
	/* sigint = signal(SIGINT, SIG_IGN); */
	if (pipe(pivec) < 0) {
		perror("pipe");
		/* signal(SIGINT, sigint) */
		return(name);
	}
	sprintf(cmdbuf, "echo %s", name);
	if ((pid = vfork()) == 0) {
		Shell = value(SHELL);
		if (Shell == NOSTR)
			Shell = "/bin/sh";
		close(pivec[0]);
		close(1);
		dup(pivec[1]);
		close(pivec[1]);
		close(2);
I 19
		shell_uid();
E 19
		execl(Shell, Shell, "-c", cmdbuf, 0);
		_exit(1);
	}
	if (pid == -1) {
		perror("fork");
		close(pivec[0]);
		close(pivec[1]);
		return(NOSTR);
	}
	close(pivec[1]);
	l = read(pivec[0], xname, BUFSIZ);
	close(pivec[0]);
	while (wait(&s) != pid);
		;
	s &= 0377;
	if (s != 0 && s != SIGPIPE) {
		fprintf(stderr, "\"Echo\" failed\n");
		return(NOSTR);
	}
	if (l < 0) {
		perror("read");
		return(NOSTR);
	}
	if (l == 0) {
		fprintf(stderr, "\"%s\": No match\n", name);
		return(NOSTR);
	}
	if (l == BUFSIZ) {
		fprintf(stderr, "Buffer overflow expanding \"%s\"\n", name);
		return(NOSTR);
	}
	xname[l] = 0;
	for (cp = &xname[l-1]; *cp == '\n' && cp > xname; cp--)
		;
	*++cp = '\0';
	return(xname);
}

/*
 * Are any of the characters in the two strings the same?
 */

anyof(s1, s2)
	register char *s1, *s2;
{
	register int c;

	while (c = *s1++)
		if (any(c, s2))
			return(1);
	return(0);
}
E 11
E 7
E 2
E 1
