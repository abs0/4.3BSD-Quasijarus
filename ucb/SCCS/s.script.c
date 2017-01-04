h45178
s 00010/00005/00261
d D 5.6 88/06/29 21:51:08 bostic 14 13
c install approved copyright notice
e
s 00040/00030/00226
d D 5.5 88/06/03 17:22:46 bostic 13 12
c add Berkeley specific header; use getopt; minor lint
e
s 00008/00006/00248
d D 5.4 85/11/13 03:02:40 serge 12 10
c output the "script done on ..." line
e
s 00009/00006/00248
d R 5.4 85/09/26 15:41:38 serge 11 10
c output the "script done on ..." line
e
s 00019/00020/00235
d D 5.3 85/08/28 10:49:48 bloom 10 9
c lint cleanup
e
s 00016/00009/00239
d D 5.2 85/08/28 10:40:48 bloom 9 8
c fix hangs (from serge@arpa)
e
s 00014/00002/00234
d D 5.1 85/05/31 09:33:15 dist 8 7
c Add copyright
e
s 00003/00000/00233
d D 4.7 85/02/21 11:20:34 bloom 7 6
c propogate window size
e
s 00027/00015/00206
d D 4.6 84/12/23 18:02:20 sam 6 5
c check slave usable before taking master (from brl); also cleanup 
c pty search logic some and use definitions in <sys/file.h>
e
s 00003/00003/00218
d D 4.5 83/07/02 00:55:36 sam 5 4
c include fixes
e
s 00001/00000/00220
d D 4.4 83/06/10 23:34:34 sam 4 3
c new signals, no libjobs
e
s 00156/00265/00064
d D 4.3 82/03/26 21:21:36 wnj 3 2
c -a replaces -S; appending an option not the default
e
s 00000/00000/00329
d D 4.2 82/03/26 21:21:12 wnj 2 1
c fixes from the midnight skulker
e
s 00329/00000/00000
d D 4.1 80/10/01 17:28:22 bill 1 0
c date and time created 80/10/01 17:28:22 by bill
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
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
E 13
 */

E 8
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
 /*
  * script - makes copy of terminal conversation. usage:
  *
  * script [ -n ] [ -s ] [ -q ] [ -a ] [ -S shell ] [ file ]
  * conversation saved in file. default is DFNAME
  */

#define DFNAME "typescript"

#ifdef HOUXP
#define STDSHELL "/bin/sh"
#define NEWSHELL "/p4/3723mrh/bin/csh"
char *shell = NEWSHELL;
E 3
I 3
#ifndef lint
D 5
static char *sccsid = "%W% %E%";
E 5
I 5
D 8
static char *sccsid = "%W% (Berkeley) %E%";
E 5
E 3
#endif
E 8
I 8
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13
E 8
I 4

E 4
D 3

#ifdef HOUXT
#define STDSHELL "/bin/sh"
#define NEWSHELL "/t1/bruce/ucb/bin/csh"
char *shell = NEWSHELL;
#endif

#ifdef CORY
#define STDSHELL "/bin/sh"
#define NEWSHELL "/bin/csh"
char *shell = NEWSHELL;
#endif

#ifdef CC
#define STDSHELL "/bin/sh"
#define NEWSHELL "/bin/csh"
char *shell = NEWSHELL;
#endif

#ifndef STDSHELL
# define V7ENV
#endif

#ifdef V7ENV
#include <signal.h>
/* used for version 7 with environments - gets your environment shell */
#define STDSHELL "/bin/sh"
#define NEWSHELL "/bin/csh"
char *shell;	/* initialized in the code */
# include <sys/types.h>
# include <sys/stat.h>
# define MODE st_mode
# define STAT stat
char *getenv();

#else

E 3
/*
D 3
 * The following is the structure of the block returned by
 * the stat and fstat system calls.
E 3
I 3
 * script
E 3
 */
I 3
D 13
#include <stdio.h>
#include <signal.h>
E 13
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
D 13
#include <sgtty.h>
E 13
D 5
#include <time.h>
E 5
I 5
#include <sys/time.h>
I 6
#include <sys/file.h>
I 13
#include <stdio.h>
#include <signal.h>
E 13
E 6
E 5
E 3

D 3
struct inode {
	char	i_minor;	/* +0: minor device of i-node */
	char	i_major;	/* +1: major device */
	int	i_number;	/* +2 */
	int	i_flags;	/* +4: see below */
	char	i_nlinks;	/* +6: number of links to file */
	char	i_uid;		/* +7: user ID of owner */
	char	i_gid;		/* +8: group ID of owner */
	char	i_size0;	/* +9: high byte of 24-bit size */
	int	i_size1;	/* +10: low word of 24-bit size */
	int	i_addr[8];	/* +12: block numbers or device number */
	int	i_actime[2];	/* +28: time of last access */
	int	i_modtime[2];	/* +32: time of last modification */
};
E 3
I 3
D 13
char	*getenv();
char	*ctime();
E 13
char	*shell;
FILE	*fscript;
int	master;
int	slave;
int	child;
I 9
int	subchild;
E 9
D 13
char	*fname = "typescript";
int	finish();
E 13
I 13
char	*fname;
E 13
E 3

D 3
#define	IALLOC	0100000
#define	IFMT	060000
#define		IFDIR	040000
#define		IFCHR	020000
#define		IFBLK	060000
#define MODE i_flags
#define STAT inode
#endif
E 3
I 3
struct	sgttyb b;
struct	tchars tc;
struct	ltchars lc;
I 7
struct	winsize win;
E 7
int	lb;
int	l;
char	*line = "/dev/ptyXX";
int	aflg;
E 3

D 3
char	*tty;		/* name of users tty so can turn off writes */
char	*ttyname();	/* std subroutine */
int	mode = 0622;	/* old permission bits for users tty */
int	outpipe[2];	/* pipe from shell to output */
int	fd;		/* file descriptor of typescript file */
int	inpipe[2];	/* pipe from input to shell */
long	tvec;		/* current time */
char	buffer[256];	/* for block I/O's */
int	n;		/* number of chars read */
int	status;		/* dummy for wait sys call */
char	*fname;		/* name of typescript file */
int	forkval, ttn;	/* temps for error checking */
int	qflg;		/* true if -q (quiet) flag */
int	aflg;		/* true if -q (append) flag */
struct STAT sbuf;
int	flsh();
E 3
I 3
main(argc, argv)
	int argc;
	char *argv[];
{
I 13
	extern char *optarg;
	extern int optind;
	int ch;
	int finish();
	char *getenv();
E 13
D 9
	int f;
E 9
E 3

D 3
main(argc,argv) int argc; char **argv; {

	if ((tty = ttyname(2)) < 0) {
		printf("Nested script not allowed.\n");
		fail();
	}

#ifdef V7ENV
E 3
D 13
	shell = getenv("SHELL");
D 3
#endif
E 3
I 3
	if (shell == 0)
		shell = "/bin/sh";
	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		switch (argv[0][1]) {
E 3

E 13
I 13
	while ((ch = getopt(argc, argv, "a")) != EOF)
		switch((char)ch) {
E 13
D 3
	while ( argc > 1 && argv[1][0] == '-') {
		switch(argv[1][1]) {
			case 'n':
				shell = NEWSHELL;
				break;
			case 's':
				shell = STDSHELL;
				break;
			case 'S':
				shell = argv[2];
				argc--; argv++;
				break;
			case 'q':
				qflg++;
				break;
			case 'a':
				aflg++;
				break;
			default:
				printf("Bad flag %s - ignored\n",argv[1]);
		}
		argc--; argv++;
	}
E 3
I 3
		case 'a':
			aflg++;
			break;
E 3
D 13

E 13
I 13
		case '?':
E 13
D 3
	if (argc > 1) {
		fname = argv[1];
		if (!aflg && stat(fname,&sbuf) >= 0) {
			printf("File %s already exists.\n",fname);
			done();
E 3
I 3
		default:
D 13
			fprintf(stderr,
			    "usage: script [ -a ] [ typescript ]\n");
E 13
I 13
			fprintf(stderr, "usage: script [-a] [file]\n");
E 13
			exit(1);
E 3
		}
D 3
	} else	fname = DFNAME;
	if (!aflg) {
		fd = creat(fname,0);	/* so can't cat/lpr typescript from inside */
	} else {
		/* try to append to existing file first */
		fd = open(fname,1);
		if (fd >= 0) lseek(fd,0l,2);
		    else     fd = creat(fname,0);
E 3
I 3
D 13
		argc--, argv++;
E 3
	}
E 13
I 13
	argc -= optind;
	argv += optind;

E 13
D 3
	if (fd<0) {
		printf("Can't create %s\n",fname);
		if (unlink(fname)==0) {
			printf("because of previous typescript bomb - try again\n");
		}
E 3
I 3
	if (argc > 0)
		fname = argv[0];
I 13
	else
		fname = "typescript";
E 13
	if ((fscript = fopen(fname, aflg ? "a" : "w")) == NULL) {
		perror(fname);
E 3
		fail();
	}
I 13

	shell = getenv("SHELL");
	if (shell == NULL)
		shell = "/bin/sh";

E 13
D 3

	chmod(fname,0);	/* in case it already exists */
E 3
I 3
	getmaster();
	printf("Script started, file is %s\n", fname);
E 3
	fixtty();
D 3
	if (!qflg) {
		printf("Script started, file is %s\n",fname);
		check(write(fd,"Script started on ",18));
		time(&tvec);
		check(write(fd,ctime(&tvec),25));
	}
	pipe(inpipe);
	pipe(outpipe);
E 3

D 3
	forkval = fork();
	if (forkval < 0)
		goto ffail;
	if (forkval == 0) {
		forkval = fork();
		if (forkval < 0)
			goto ffail;
		if (forkval == 0)
E 3
I 3
	(void) signal(SIGCHLD, finish);
	child = fork();
	if (child < 0) {
		perror("fork");
		fail();
	}
	if (child == 0) {
D 9
		f = fork();
		if (f < 0) {
E 9
I 9
		subchild = child = fork();
		if (child < 0) {
E 9
			perror("fork");
			fail();
		}
D 9
		if (f)
E 9
I 9
		if (child)
E 9
E 3
			dooutput();
D 3
		forkval = fork();
		if (forkval < 0)
			goto ffail;
		if (forkval == 0)
			doinput();
		doshell();
E 3
I 3
		else
			doshell();
E 3
	}
D 3
	close(inpipe[0]); close(inpipe[1]);
	close(outpipe[0]); close(outpipe[1]);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, done);
	wait(&status);
	done();
	/*NOTREACHED*/

ffail:
	printf("Fork failed. Try again.\n");
	fail();
E 3
I 3
	doinput();
E 3
}

D 3
/* input process - copy tty to pipe and file */
E 3
doinput()
{
I 13
	register int cc;
E 13
I 3
	char ibuf[BUFSIZ];
D 13
	int cc;
E 13
E 3

D 3
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
E 3
I 3
	(void) fclose(fscript);
	while ((cc = read(0, ibuf, BUFSIZ)) > 0)
		(void) write(master, ibuf, cc);
	done();
}
E 3

D 3
	close(inpipe[0]);
	close(outpipe[0]);
	close(outpipe[1]);
E 3
I 3
D 5
#include <wait.h>
E 5
I 5
#include <sys/wait.h>
E 5
E 3

D 3
	/* main input loop - copy until end of file (ctrl D) */
	while ((n=read(0,buffer,256)) > 0) {
		check(write(fd,buffer,n));
		write(inpipe[1],buffer,n);
	}
E 3
I 3
finish()
{
	union wait status;
I 9
	register int pid;
	register int die = 0;
E 9
E 3

D 3
	/* end of script - close files and exit */
	close(inpipe[1]);
	close(fd);
E 3
I 3
D 9
	if (wait3(&status, WNOHANG, 0) != child)
		return;
E 3
	done();
E 9
I 9
	while ((pid = wait3(&status, WNOHANG, 0)) > 0)
		if (pid == child)
			die = 1;

	if (die)
		done();
E 9
}

D 3
/* do output process - copy to tty & file */
E 3
dooutput()
{
I 3
D 13
	time_t tvec;
	char obuf[BUFSIZ];
	int cc;
E 13
I 13
	register int cc;
	time_t tvec, time();
	char obuf[BUFSIZ], *ctime();
E 13
E 3

D 3
	signal(SIGINT, flsh);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	close(0);
	close(inpipe[0]);
	close(inpipe[1]);
	close(outpipe[1]);

	/* main output proc loop */
	while (n=read(outpipe[0],buffer,256)) {
		if (n > 0) { /* -1 means trap to flsh just happened */
			write(1,buffer,n);
			check(write(fd,buffer,n));
		}
E 3
I 3
	(void) close(0);
D 13
	tvec = time((time_t *)0);
E 13
I 13
	tvec = time((time_t *)NULL);
E 13
	fprintf(fscript, "Script started on %s", ctime(&tvec));
	for (;;) {
		cc = read(master, obuf, sizeof (obuf));
		if (cc <= 0)
			break;
		(void) write(1, obuf, cc);
		(void) fwrite(obuf, 1, cc, fscript);
E 3
	}
D 3

	/* output sees eof - close files and exit */
	if (!qflg) {
		printf("Script done, file is %s\n",fname);
		check(write(fd,"\nscript done on ",16));
		time(&tvec);
		check(write(fd,ctime(&tvec),25));
	}
	close(fd);
E 3
I 3
D 12
	tvec = time((time_t *)0);
	fprintf(fscript,"\nscript done on %s", ctime(&tvec));
	(void) fclose(fscript);
	(void) close(master);
E 3
	exit(0);
E 12
I 12
	done();
E 12
}

D 3
/* exec shell, after diverting std input & output */
E 3
doshell()
{
I 3
	int t;
E 3

D 3
	close(0);
	dup(inpipe[0]);
	close(1);
	dup(outpipe[1]);
	close(2);
	dup(outpipe[1]);

	/* close useless files */
	close(inpipe[0]);
	close(inpipe[1]);
	close(outpipe[0]);
	close(outpipe[1]);
E 3
I 3
D 6
	t = open("/dev/tty", 2);
E 6
I 6
	t = open("/dev/tty", O_RDWR);
E 6
	if (t >= 0) {
D 10
		ioctl(t, TIOCNOTTY, (char *)0);
E 10
I 10
		(void) ioctl(t, TIOCNOTTY, (char *)0);
E 10
		(void) close(t);
	}
	getslave();
	(void) close(master);
	(void) fclose(fscript);
D 10
	dup2(slave, 0);
	dup2(slave, 1);
	dup2(slave, 2);
E 10
I 10
	(void) dup2(slave, 0);
	(void) dup2(slave, 1);
	(void) dup2(slave, 2);
E 10
	(void) close(slave);
E 3
	execl(shell, "sh", "-i", 0);
D 3
	execl(STDSHELL, "sh", "-i", 0);
	execl(NEWSHELL, "sh", "-i", 0);
	printf("Can't execute shell\n");
E 3
I 3
	perror(shell);
E 3
	fail();
}

fixtty()
{
I 3
	struct sgttyb sbuf;
E 3

D 3
	fstat(2, &sbuf);
	mode = sbuf.MODE&0777;
	chmod(tty, 0600);
E 3
I 3
	sbuf = b;
	sbuf.sg_flags |= RAW;
	sbuf.sg_flags &= ~ECHO;
D 10
	ioctl(0, TIOCSETP, (char *)&sbuf);
E 10
I 10
	(void) ioctl(0, TIOCSETP, (char *)&sbuf);
E 10
E 3
}

D 3
/* come here on rubout to flush output - this doesn't work */
flsh()
{

	signal(SIGINT, flsh);
	/* lseek(outpipe[0],0l,2);	/* seeks on pipes don't work !"$"$!! */
}

E 3
fail()
{

D 3
	unlink(fname);
	kill(0, 15);	/* shut off other script processes */
E 3
I 3
	(void) kill(0, SIGTERM);
E 3
	done();
}

done()
{
I 12
D 13
	time_t tvec;
E 13
I 13
	time_t tvec, time();
	char *ctime();
E 13
E 12

D 3
	chmod(tty, mode);
	chmod(fname, 0664);
	exit();
E 3
I 3
D 9
	ioctl(0, TIOCSETP, (char *)&b);
	printf("Script done, file is %s\n", fname);
E 9
I 9
D 12
	if (!subchild) {
E 12
I 12
	if (subchild) {
D 13
		tvec = time((time_t *)0);
E 13
I 13
		tvec = time((time_t *)NULL);
E 13
		fprintf(fscript,"\nscript done on %s", ctime(&tvec));
		(void) fclose(fscript);
		(void) close(master);
	} else {
E 12
D 10
		ioctl(0, TIOCSETP, (char *)&b);
E 10
I 10
		(void) ioctl(0, TIOCSETP, (char *)&b);
E 10
		printf("Script done, file is %s\n", fname);
	}
E 9
	exit(0);
E 3
}

D 3
#ifndef V7ENV
#ifndef CC
char *ttyname(i) int i; {
	char *string;
	string = "/dev/ttyx";
	string[8] = ttyn(fd);
	if (string[8] == 'x') return((char *) (-1));
		else return(string);
E 3
I 3
getmaster()
{
D 6
	char c;
E 6
I 6
	char *pty, *bank, *cp;
E 6
	struct stat stb;
D 10
	int i;
E 10

D 6
	for (c = 'p'; c <= 's'; c++) {
		line[strlen("/dev/pty")] = c;
		line[strlen("/dev/ptyp")] = '0';
E 6
I 6
	pty = &line[strlen("/dev/ptyp")];
	for (bank = "pqrs"; *bank; bank++) {
		line[strlen("/dev/pty")] = *bank;
		*pty = '0';
E 6
		if (stat(line, &stb) < 0)
			break;
D 6
		for (i = 0; i < 16; i++) {
			line[strlen("/dev/ptyp")] = "0123456789abcdef"[i];
			master = open(line, 2);
E 6
I 6
		for (cp = "0123456789abcdef"; *cp; cp++) {
			*pty = *cp;
			master = open(line, O_RDWR);
E 6
			if (master >= 0) {
D 6
				ioctl(0, TIOCGETP, (char *)&b);
				ioctl(0, TIOCGETC, (char *)&tc);
				ioctl(0, TIOCGETD, (char *)&l);
				ioctl(0, TIOCGLTC, (char *)&lc);
				ioctl(0, TIOCLGET, (char *)&lb);
				return;
E 6
I 6
				char *tp = &line[strlen("/dev/")];
				int ok;

				/* verify slave side is usable */
				*tp = 't';
				ok = access(line, R_OK|W_OK) == 0;
				*tp = 'p';
				if (ok) {
D 10
					ioctl(0, TIOCGETP, (char *)&b);
					ioctl(0, TIOCGETC, (char *)&tc);
					ioctl(0, TIOCGETD, (char *)&l);
					ioctl(0, TIOCGLTC, (char *)&lc);
					ioctl(0, TIOCLGET, (char *)&lb);
I 7
					ioctl(0, TIOCGWINSZ, (char *)&win);
E 10
I 10
				    (void) ioctl(0, TIOCGETP, (char *)&b);
				    (void) ioctl(0, TIOCGETC, (char *)&tc);
				    (void) ioctl(0, TIOCGETD, (char *)&l);
				    (void) ioctl(0, TIOCGLTC, (char *)&lc);
				    (void) ioctl(0, TIOCLGET, (char *)&lb);
				    (void) ioctl(0, TIOCGWINSZ, (char *)&win);
E 10
E 7
					return;
				}
D 10
				close(master);
E 10
I 10
				(void) close(master);
E 10
E 6
			}
		}
	}
	fprintf(stderr, "Out of pty's\n");
	fail();
E 3
}
D 3
#endif
#endif
E 3

D 3
check(n)
int n;
E 3
I 3
getslave()
E 3
{
D 3
	/* checks the result of a write call, if neg
	   assume ran out of disk space & die */
	if (n < 0) {
		write(1,"Disk quota exceeded - script quits\n",35);
		kill(0,15);
		done();
E 3
I 3

	line[strlen("/dev/")] = 't';
D 6
	slave = open(line, 2);
E 6
I 6
	slave = open(line, O_RDWR);
E 6
	if (slave < 0) {
		perror(line);
		fail();
E 3
	}
I 3
D 10
	ioctl(slave, TIOCSETP, (char *)&b);
	ioctl(slave, TIOCSETC, (char *)&tc);
	ioctl(slave, TIOCSLTC, (char *)&lc);
	ioctl(slave, TIOCLSET, (char *)&lb);
	ioctl(slave, TIOCSETD, (char *)&l);
I 7
	ioctl(slave, TIOCSWINSZ, (char *)&win);
E 10
I 10
	(void) ioctl(slave, TIOCSETP, (char *)&b);
	(void) ioctl(slave, TIOCSETC, (char *)&tc);
	(void) ioctl(slave, TIOCSLTC, (char *)&lc);
	(void) ioctl(slave, TIOCLSET, (char *)&lb);
	(void) ioctl(slave, TIOCSETD, (char *)&l);
	(void) ioctl(slave, TIOCSWINSZ, (char *)&win);
E 10
E 7
E 3
}
E 1
