h10725
s 00002/00002/00569
d D 5.6 87/10/22 19:55:31 bostic 24 23
c ANSI C; sprintf now returns an int.
e
s 00045/00014/00526
d D 5.5 87/02/09 12:08:33 karels 23 22
c formalize uid swapping and force everywhere
e
s 00002/00003/00538
d D 5.4 86/04/03 17:01:53 donn 22 21
c Be even less picky about 'phone numbers' -- anything that begins with
c a digit is a phone number.
e
s 00022/00010/00519
d D 5.3 86/01/13 19:27:59 karels 21 20
c use setreuid to retain setuid uid for cleanup of lock files
e
s 00015/00001/00514
d D 5.2 85/11/29 19:28:27 donn 20 19
c Arranged to copy a phone number argument to a safe place, then zero
c out the original version.  This narrows the window in which the phone number
c is visible to miscreants using 'ps' or 'w'.
e
s 00013/00001/00502
d D 5.1 85/04/30 12:33:59 dist 19 18
c Add copyright
e
s 00001/00001/00502
d D 4.18 84/10/06 17:40:01 helge 18 17
c fixed typo in comment
e
s 00007/00001/00496
d D 4.17 83/10/08 13:58:31 sam 17 16
c recognize and handle carrier loss
e
s 00004/00003/00493
d D 4.16 83/06/28 00:32:57 sam 16 15
c must setparity even in cumode
e
s 00056/00066/00440
d D 4.15 83/06/25 01:14:29 sam 15 14
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00076/00006/00430
d D 4.14 83/06/15 13:52:54 ralph 14 13
c changes for local info, parity, vadic auto dialers
e
s 00006/00000/00430
d D 4.13 83/05/17 11:49:58 root 13 12
c Now turns off local characters (suspend, etc)
e
s 00003/00000/00427
d D 4.12 82/07/29 15:21:53 shannon 12 11
c 68000 fixes
e
s 00050/00014/00377
d D 4.11 81/12/16 17:24:51 shannon 11 10
c new cu interface and phone numbers for tip
e
s 00017/00057/00374
d D 4.10 81/11/29 22:50:50 sam 10 9
c reformatting
e
s 00001/00001/00430
d D 4.9 81/11/20 10:44:58 sam 9 8
c cosmetics
e
s 00001/00000/00430
d D 4.8 81/08/26 17:24:44 sam 8 7
c missing unlock on hunt returning -1: normally seen timed out opens
e
s 00003/00002/00427
d D 4.7 81/08/16 15:17:37 sam 7 6
c make escape escape force escape
e
s 00002/00000/00427
d D 4.6 81/07/13 10:55:51 sam 6 5
c 2 #ifdef VMUNIX's that were missed
e
s 00046/00023/00381
d D 4.5 81/07/11 14:05:05 sam 5 4
c cleanup after "hw" attribute addition (instead of shannon mods)
e
s 00023/00007/00381
d D 4.4 81/06/16 16:43:40 sam 4 3
c lots of patches to satisfy the DN-11's wants
e
s 00012/00000/00376
d D 4.3 81/05/18 10:55:13 sam 3 2
c temporary kluge fix for setting script in .tiprc file
e
s 00001/00000/00375
d D 4.2 81/05/10 13:12:35 sam 2 1
c insure stdout is unbuffered
e
s 00375/00000/00000
d D 4.1 81/05/09 16:45:22 root 1 0
c date and time created 81/05/09 16:45:22 by root
e
u
U
t
T
I 19
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 19
I 1
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
#ifndef lint
I 19
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 19
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif
E 19
I 19
#endif not lint
E 19
E 15
I 10

E 10
/*
D 10
 * tip - Unix link to other systems
E 10
I 10
 * tip - UNIX link to other systems
E 10
 *  tip [-v] [-speed] system-name
D 10
 *
 * Uses remote file for system descriptions.
 * Current commands (escapes):
 *
 *	~!	fork a shell on the local machine
 *	~c	change working directory on local machine
 *	~^D	exit tip
 *	~<	fetch file from remote system
 *	~>	send file to remote system
 *	~t	take a file from a remote UNIX (uses cat & echo)
 *	~p	send a file to a remote UNIX (uses cat)
 *	~|	fetch file from remote system and pipe it to
 *		 a local process
 *	~%	fork and wait for a program which inherits file
 *		 descriptors 3 & 4 attached to the remote machine
 *		 (optional by CONNECT define)
 *	~s	set or show variable
 *	~?	give a help summary
 *
 * Samuel J. Leffler	1-18-81
 *
 * sjl			2-11-81
 * add auto-dial stuff for the BIZCOMP
 *
 * sjl			2-14-81
 * cleaned up auto-dialer stuff and added variables
 *
 * sjl			2-19-81
 * handle quit and interrupt during calls
 *
 * sjl			3-8-81
 * made to pass lint
 *
 * sjl			4-11-81
 * mods to handle both FIOCAPACITY and FIONREAD in biz.c
 *
 * sjl			4-17-81
 * added take and put, made piping stuff work
 * honor uucp locks
 * rewrite remote file stuff for DN-11 like acu's and just to clean
 *   it up
I 4
 *
 * sjl			6-16-81
 * real working setup for DN-11's
E 10
I 10
 * or
 *  cu phone-number [-s speed] [-l line] [-a acu]
E 10
E 4
 */
D 10

E 10
#include "tip.h"

I 14
D 15
static char *sccsid = "%W% %G%";

E 15
E 14
/*
 * Baud rate mapping table
 */
int bauds[] = {
	0, 50, 75, 110, 134, 150, 200, 300, 600,
	1200, 1800, 2400, 4800, 9600, 19200, -1
};

I 5
D 15
#ifdef VMUNIX
E 15
int	disc = OTTYDISC;		/* tip normally runs this way */
D 15
#endif

E 15
E 5
int	intprompt();
int	timeout();
D 10
static int cleanup();
E 10
I 10
int	cleanup();
I 11
char	*sname();
I 20
char	PNbuf[256];			/* This limits the size of a number */
E 20
D 24
extern char *sprintf();
E 24
E 11
E 10

main(argc, argv)
D 9
char *argv[];
E 9
I 9
	char *argv[];
E 9
{
	char *system = NOSTR;
	register int i;
D 5
#ifdef VMUNIX
	int disc;
#endif
E 5
D 11
	char *p;
E 11
I 11
	register char *p;
	char sbuf[12];
E 11

I 23
	gid = getgid();
	egid = getegid();
	uid = getuid();
	euid = geteuid();
E 23
I 10
D 11
	if (strcmp(argv[0], "tip")) {
E 11
I 11
	if (equal(sname(argv[0]), "cu")) {
E 11
D 21
		cumain(argc, argv);
E 21
		cumode = 1;
I 21
		cumain(argc, argv);
E 21
		goto cucommon;
	}

E 10
	if (argc > 4) {
		fprintf(stderr, "usage: tip [-v] [-speed] [system-name]\n");
		exit(1);
	}
	if (!isatty(0)) {
		fprintf(stderr, "tip: must be interactive\n");
		exit(1);
	}
D 11
	if (argc > 1 && argv[argc-1][0] != '-')
		system = argv[argc-1];		/* always last item */
E 11
I 11

	for (; argc > 1; argv++, argc--) {
		if (argv[1][0] != '-')
			system = argv[1];
		else switch (argv[1][1]) {

		case 'v':
			vflag++;
			break;

		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			BR = atoi(&argv[1][1]);
			break;

		default:
			fprintf(stderr, "tip: %s, unknown option\n", argv[1]);
			break;
		}
	}

I 12
	if (system == NOSTR)
		goto notnumber;
E 12
D 22
	for (p = system; *p; p++)
		if (isalpha(*p))
			goto notnumber;
E 22
I 22
	if (isalpha(*system))
		goto notnumber;
E 22
D 20
	PN = system;		/* system name is really a phone number */
E 20
I 20
	/*
	 * System name is really a phone number...
	 * Copy the number then stomp on the original (in case the number
	 *	is private, we don't want 'ps' or 'w' to find it).
	 */
	if (strlen(system) > sizeof PNbuf - 1) {
		fprintf(stderr, "tip: phone number too long (max = %d bytes)\n",
			sizeof PNbuf - 1);
		exit(1);
	}
	strncpy( PNbuf, system, sizeof PNbuf - 1 );
	for (p = system; *p; p++)
		*p = '\0';
	PN = PNbuf;
E 20
D 24
	system = sprintf(sbuf, "tip%d", BR);
E 24
I 24
	(void)sprintf(sbuf, "tip%d", BR);
	system = sbuf;
E 24

notnumber:
E 11
	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGHUP, cleanup);
	signal(SIGTERM, cleanup);
I 4

E 4
	if ((i = hunt(system)) == 0) {
		printf("all ports busy\n");
		exit(3);
	}
	if (i == -1) {
		printf("link down\n");
I 8
		delock(uucplock);
E 8
		exit(3);
	}
I 2
	setbuf(stdout, NULL);
E 2
	loginit();
D 21
	/*
	 * Now that we have the logfile and the ACU open
	 *  return to the real uid and gid.  These things will
	 *  be closed on exit.  Note that we can't run as root,
	 *  because locking mechanism on the tty and the accounting
	 *  will be bypassed.
	 */
D 14
	setuid(getuid());
E 14
	setgid(getgid());
I 14
	setuid(getuid());
E 21
E 14
D 11
	for (i = 1; i < argc-1; i++)
		if (equal(argv[i], "-v"))
			vflag++;
E 11
I 11

E 11
	/*
	 * Kludge, their's no easy way to get the initialization
	 *   in the right order, so force it here
	 */
	if ((PH = getenv("PHONES")) == NOSTR)
		PH = "/etc/phones";
	vinit();				/* init variables */
I 14
D 16
	setparity();				/* set the parity table */
E 16
I 16
	setparity("even");			/* set the parity table */
E 16
E 14
D 11
	for (i = 1; i < argc-1; i++)
		if (argv[i][0] == '-' && argv[i][1] != 'v') {
			if (isnum(argv[i][1]))
				number(value(BAUDRATE)) = atoi(&argv[i][1]);
			else
				printf("%s: unknown option\n", argv[i]);
		}
E 11
D 5
	if ((arg.sg_ispeed = speed(number(value(BAUDRATE)))) == NULL) {
E 5
I 5
	if ((i = speed(number(value(BAUDRATE)))) == NULL) {
E 5
		printf("tip: bad baud rate %d\n", number(value(BAUDRATE)));
		delock(uucplock);
		exit(3);
	}
I 4

I 5
	/*
I 21
	 * Now that we have the logfile and the ACU open
	 *  return to the real uid and gid.  These things will
	 *  be closed on exit.  Swap real and effective uid's
	 *  so we can get the original permissions back
	 *  for removing the uucp lock.
	 */
D 23
	gid = getgid();
	egid = getegid();
	uid = getuid();
	euid = geteuid();
	setregid(egid, gid);
	setreuid(euid, uid);
E 23
I 23
	user_uid();
E 23

	/*
E 21
	 * Hardwired connections require the
	 *  line speed set before they make any transmissions
	 *  (this is particularly true of things like a DF03-AC)
	 */
	if (HW)
		ttysetup(i);
E 5
	if (p = connect()) {
		printf("\07%s\n[EOT]\n", p);
I 21
D 23
		setreuid(uid, euid);
		setregid(gid, egid);
E 23
I 23
		daemon_uid();
E 23
E 21
		delock(uucplock);
		exit(1);
	}
E 4
D 5
	arg.sg_ospeed = arg.sg_ispeed;
E 5
I 5
	if (!HW)
		ttysetup(i);
D 10

E 10
I 10
cucommon:
E 10
E 5
	/*
D 5
	 * NOTE that remote side runs in TANDEM mode,
	 *  if the host doesn't honor X-ON/X-OFF with default
	 *  start/stop chars, the remote description must be
	 *  extended and tchars will have to be set up here.
	 * If the host doesn't honor TANDEM mode, then watch
	 *  out, as you'll get garbage.
E 5
I 5
D 10
	 * Set up local tty state
E 10
I 10
	 * From here down the code is shared with
	 * the "cu" version of tip.
E 10
E 5
	 */
I 21

E 21
D 5
	arg.sg_flags = RAW | TANDEM;
	ioctl(FD, TIOCSETP, &arg);

	ioctl(0, TIOCGETP, &defarg);	/* store initial status */
	ioctl(0, TIOCGETC, &defchars);
E 5
I 5
	ioctl(0, TIOCGETP, (char *)&defarg);
	ioctl(0, TIOCGETC, (char *)&defchars);
I 13
	ioctl(0, TIOCGLTC, (char *)&deflchars);
E 13
I 6
D 15
#ifdef VMUNIX
E 15
E 6
	ioctl(0, TIOCGETD, (char *)&odisc);
I 6
D 15
#endif
E 15
E 6
E 5
	arg = defarg;
	arg.sg_flags = ANYP | CBREAK;
	tchars = defchars;
	tchars.t_intrc = tchars.t_quitc = -1;
I 13
	ltchars = deflchars;
	ltchars.t_suspc = ltchars.t_dsuspc = ltchars.t_flushc
		= ltchars.t_lnextc = -1;
E 13
D 4

	if (p = connect()) {
		printf("\07%s\n[EOT]\n", p);
		delock(uucplock);
		exit(1);
	}
	write(1, "\07connected\n", 11);
E 4
	raw();
D 5
#ifdef VMUNIX
	ioctl(0, TIOCGETD, (char *)&odisc);
	disc = OTTYDISC;
	ioctl(0, TIOCSETD, (char *)&disc);
#endif
E 5
I 5

E 5
	pipe(fildes); pipe(repdes);
	signal(SIGALRM, timeout);
I 4

	/*
	 * Everything's set up now:
D 18
	 *	connection established (hardwired or diaulup)
E 18
I 18
	 *	connection established (hardwired or dialup)
E 18
	 *	line conditioned (baud rate, mode, etc.)
	 *	internal data structures (variables)
	 * so, fork one process for local side and one for remote.
	 */
D 10
	write(1, "\07connected\r\n", 12);
E 10
I 10
	printf(cumode ? "Connected\r\n" : "\07connected\r\n");
E 10
E 4
	if (pid = fork())
		tipin();
	else
		tipout();
	/*NOTREACHED*/
}

D 10
static
E 10
cleanup()
{
I 15

I 21
D 23
	if (uid != getuid()) {
		setreuid(uid, euid);
		setregid(gid, egid);
	}
E 23
I 23
	daemon_uid();
E 23
E 21
E 15
	delock(uucplock);
I 4
D 15
#ifdef VMUNIX
E 15
	if (odisc)
		ioctl(0, TIOCSETD, (char *)&odisc);
D 15
#endif
E 15
E 4
	exit(0);
}

/*
I 23
 * Muck with user ID's.  We are setuid to the owner of the lock
 * directory when we start.  user_uid() reverses real and effective
 * ID's after startup, to run with the user's permissions.
 * daemon_uid() switches back to the privileged uid for unlocking.
 * Finally, to avoid running a shell with the wrong real uid,
 * shell_uid() sets real and effective uid's to the user's real ID.
 */
static int uidswapped;

user_uid()
{
	if (uidswapped == 0) {
		setregid(egid, gid);
		setreuid(euid, uid);
		uidswapped = 1;
	}
}

daemon_uid()
{

	if (uidswapped) {
		setreuid(uid, euid);
		setregid(gid, egid);
		uidswapped = 0;
	}
}

shell_uid()
{

	setreuid(uid, uid);
	setregid(gid, gid);
}

/*
E 23
 * put the controlling keyboard into raw mode
 */
raw()
{
I 15

E 15
	ioctl(0, TIOCSETP, &arg);
	ioctl(0, TIOCSETC, &tchars);
I 13
	ioctl(0, TIOCSLTC, &ltchars);
E 13
I 5
D 15
#ifdef VMUNIX
E 15
	ioctl(0, TIOCSETD, (char *)&disc);
D 15
#endif
E 15
E 5
}


/*
 * return keyboard to normal mode
 */
unraw()
{
D 5
	ioctl(0, TIOCSETP, &defarg);
	ioctl(0, TIOCSETC, &defchars);
E 5
I 5
D 15
#ifdef VMUNIX
E 15
I 15

E 15
	ioctl(0, TIOCSETD, (char *)&odisc);
D 15
#endif
E 15
	ioctl(0, TIOCSETP, (char *)&defarg);
	ioctl(0, TIOCSETC, (char *)&defchars);
I 13
	ioctl(0, TIOCSLTC, (char *)&deflchars);
E 13
E 5
}

I 15
static	jmp_buf promptbuf;

E 15
/*
 * Print string ``s'', then read a string
 *  in from the terminal.  Handles signals & allows use of
 *  normal erase and kill characters.
 */
prompt(s, p)
	char *s;
	register char *p;
{
	register char *b = p;
I 15
	int (*oint)(), (*oquit)();
E 15

	stoprompt = 0;
D 15
	signal(SIGINT, intprompt);
	signal(SIGQUIT, SIG_IGN);
E 15
I 15
	oint = signal(SIGINT, intprompt);
	oint = signal(SIGQUIT, SIG_IGN);
E 15
	unraw();
	printf("%s", s);
D 15
	while ((*p = getchar()) != EOF && *p != '\n') {
		if (stoprompt)
			goto pbreak;
		p++;
	}
E 15
I 15
	if (setjmp(promptbuf) == 0)
		while ((*p = getchar()) != EOF && *p != '\n')
			p++;
E 15
	*p = '\0';
D 15
pbreak:
E 15
I 15

E 15
	raw();
D 15
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT,SIG_DFL);
	return(stoprompt || p == b);
E 15
I 15
	signal(SIGINT, oint);
	signal(SIGQUIT, oint);
	return (stoprompt || p == b);
E 15
}

/*
 * Interrupt service routine during prompting
 */
intprompt()
{
I 15

E 15
	signal(SIGINT, SIG_IGN);
	stoprompt = 1;
	printf("\r\n");
I 15
	longjmp(promptbuf, 1);
E 15
}

/*
 * ****TIPIN   TIPIN****
 */
tipin()
{
	char gch, bol = 1;

I 3
	/*
	 * Kinda klugey here...
	 *   check for scripting being turned on from the .tiprc file,
	 *   but be careful about just using setscript(), as we may
	 *   send a SIGEMT before tipout has a chance to set up catching
	 *   it; so wait a second, then setscript()
	 */
	if (boolean(value(SCRIPT))) {
		sleep(1);
		setscript();
	}

E 3
	while (1) {
		gch = getchar()&0177;
		if ((gch == character(value(ESCAPE))) && bol) {
			if (!(gch = escape()))
				continue;
D 10
		} else if (gch == character(value(RAISECHAR))) {
E 10
I 10
		} else if (!cumode && gch == character(value(RAISECHAR))) {
E 10
			boolean(value(RAISE)) = !boolean(value(RAISE));
D 10
			printf("%s", ctrl(character(value(RAISECHAR))));
E 10
			continue;
		} else if (gch == '\r') {
			bol = 1;
D 14
			write(FD, &gch, 1);
E 14
I 14
			pwrite(FD, &gch, 1);
			if (boolean(value(HALFDUPLEX)))
				printf("\r\n");
E 14
			continue;
D 10
		} else if (gch == character(value(FORCE))) {
			printf("%s", ctrl(character(value(FORCE))));
E 10
I 10
		} else if (!cumode && gch == character(value(FORCE)))
E 10
			gch = getchar()&0177;
D 10
		}
E 10
		bol = any(gch, value(EOL));
		if (boolean(value(RAISE)) && islower(gch))
D 14
			toupper(gch);
		write(FD, &gch, 1);
E 14
I 14
			gch = toupper(gch);
		pwrite(FD, &gch, 1);
		if (boolean(value(HALFDUPLEX)))
			printf("%c", gch);
E 14
	}
}

/*
 * Escape handler --
 *  called on recognition of ``escapec'' at the beginning of a line
 */
escape()
{
	register char gch;
	register esctable_t *p;
	char c = character(value(ESCAPE));
	extern esctable_t etable[];

	gch = (getchar()&0177);
	for (p = etable; p->e_char; p++)
		if (p->e_char == gch) {
D 23
			if ((p->e_flags&PRIV) && getuid())
E 23
I 23
			if ((p->e_flags&PRIV) && uid)
E 23
				continue;
			printf("%s", ctrl(c));
			(*p->e_func)(gch);
D 15
			return(0);
E 15
I 15
			return (0);
E 15
		}
D 7

	write(FD, &c, 1);
E 7
I 7
	/* ESCAPE ESCAPE forces ESCAPE */
	if (c != gch)
D 14
		write(FD, &c, 1);
E 14
I 14
		pwrite(FD, &c, 1);
E 14
E 7
D 15
	return(gch);
E 15
I 15
	return (gch);
E 15
}

speed(n)
I 15
	int n;
E 15
{
	register int *p;

	for (p = bauds; *p != -1;  p++)
		if (*p == n)
D 15
			return(p-bauds);
	return(NULL);
E 15
I 15
			return (p - bauds);
	return (NULL);
E 15
}

any(c, p)
	register char c, *p;
{
I 12
D 15
	if (p)
E 12
	while (*p)
E 15
I 15
	while (p && *p)
E 15
		if (*p++ == c)
D 15
			return(1);
	return(0);
E 15
I 15
			return (1);
	return (0);
E 15
}

size(s)
	register char	*s;
{
D 15
	register int	i = 0;
E 15
I 15
	register int i = 0;
E 15

D 15
	while (*s++) i++;
	return(i);
E 15
I 15
	while (s && *s++)
		i++;
	return (i);
E 15
}

char *
interp(s)
	register char *s;
{
	static char buf[256];
	register char *p = buf, c, *q;

	while (c = *s++) {
		for (q = "\nn\rr\tt\ff\033E\bb"; *q; q++)
			if (*q++ == c) {
				*p++ = '\\'; *p++ = *q;
				goto next;
			}
		if (c < 040) {
			*p++ = '^'; *p++ = c + 'A'-1;
		} else if (c == 0177) {
			*p++ = '^'; *p++ = '?';
		} else
			*p++ = c;
	next:
		;
	}
	*p = '\0';
D 15
	return(buf);
E 15
I 15
	return (buf);
E 15
}

char *
ctrl(c)
	char c;
{
	static char s[3];

	if (c < 040 || c == 0177) {
		s[0] = '^';
		s[1] = c == 0177 ? '?' : c+'A'-1;
		s[2] = '\0';
	} else {
		s[0] = c;
		s[1] = '\0';
	}
D 15
	return(s);
E 15
I 15
	return (s);
E 15
}

/*
 * Help command
 */
help(c)
	char c;
{
	register esctable_t *p;
	extern esctable_t etable[];

	printf("%c\r\n", c);
	for (p = etable; p->e_char; p++) {
D 23
		if ((p->e_flags&PRIV) && getuid())
E 23
I 23
		if ((p->e_flags&PRIV) && uid)
E 23
			continue;
		printf("%2s", ctrl(character(value(ESCAPE))));
		printf("%-2s %c   %s\r\n", ctrl(p->e_char),
			p->e_flags&EXP ? '*': ' ', p->e_help);
	}
I 5
}

/*
 * Set up the "remote" tty's state
 */
D 10
static
E 10
ttysetup(speed)
I 15
	int speed;
E 15
{
D 15
#ifdef VMUNIX
E 15
	unsigned bits = LDECCTQ;
D 15
#endif
E 15

	arg.sg_ispeed = arg.sg_ospeed = speed;
I 15
	arg.sg_flags = RAW;
E 15
D 14
	arg.sg_flags = TANDEM|RAW;
E 14
I 14
	if (boolean(value(TAND)))
D 15
		arg.sg_flags = TANDEM|RAW;
	else
		arg.sg_flags = RAW;
E 15
I 15
		arg.sg_flags |= TANDEM;
E 15
E 14
	ioctl(FD, TIOCSETP, (char *)&arg);
D 15
#ifdef VMUNIX
E 15
	ioctl(FD, TIOCLBIS, (char *)&bits);
D 15
#endif
E 15
I 11
}

/*
 * Return "simple" name from a file name,
 * strip leading directories.
 */
char *
sname(s)
	register char *s;
{
	register char *p = s;

	while (*s)
		if (*s++ == '/')
			p = s;
	return (p);
I 14
}

D 15
extern char chartab[];
E 15
static char partab[0200];

/*
D 15
 * do a write to the remote machine with the correct parity
 * we are doing 8 bit wide output, so we just generate a character
E 15
I 15
 * Do a write to the remote machine with the correct parity.
 * We are doing 8 bit wide output, so we just generate a character
E 15
 * with the right parity and output it.
 */
pwrite(fd, buf, n)
	int fd;
	char *buf;
	register int n;
{
	register int i;
D 15
	register char *bp = buf;
E 15
I 15
	register char *bp;
I 17
	extern int errno;
E 17
E 15

D 15
	for (i = 0, bp = buf; i < n; i++, bp++) {
E 15
I 15
	bp = buf;
	for (i = 0; i < n; i++) {
E 15
		*bp = partab[(*bp) & 0177];
I 15
		bp++;
E 15
	}
D 17
	write(fd, buf, n);
E 17
I 17
	if (write(fd, buf, n) < 0) {
		if (errno == EIO)
			abort("Lost carrier.");
		/* this is questionable */
		perror("write");
	}
E 17
}

/*
D 15
 * build a parity table with the right high-order bit
 * copy an even-parity table and doctor it
E 15
I 15
 * Build a parity table with appropriate high-order bit.
E 15
 */
D 16
setparity()
E 16
I 16
setparity(defparity)
	char *defparity;
E 16
{
D 15
	int i;
E 15
I 15
	register int i;
E 15
	char *parity;
I 15
	extern char evenpartab[];
E 15

	if (value(PARITY) == NOSTR)
D 16
		value(PARITY) = "even";
E 16
I 16
		value(PARITY) = defparity;
E 16
D 15

E 15
	parity = value(PARITY);
D 15

E 15
	for (i = 0; i < 0200; i++)
D 15
		partab[i] = chartab[i];

E 15
I 15
		partab[i] = evenpartab[i];
	if (equal(parity, "even"))
		return;
E 15
	if (equal(parity, "odd")) {
		for (i = 0; i < 0200; i++)
			partab[i] ^= 0200;	/* reverse bit 7 */
I 15
		return;
E 15
	}
D 15
	else if (equal(parity, "none") || equal(parity, "zero")) {
E 15
I 15
	if (equal(parity, "none") || equal(parity, "zero")) {
E 15
		for (i = 0; i < 0200; i++)
			partab[i] &= ~0200;	/* turn off bit 7 */
I 15
		return;
E 15
	}
D 15
	else if (equal(parity, "one")) {
E 15
I 15
	if (equal(parity, "one")) {
E 15
		for (i = 0; i < 0200; i++)
			partab[i] |= 0200;	/* turn on bit 7 */
I 15
		return;
E 15
	}
D 15
	else if (equal(parity, "even")) {
		/* table is already even parity */
	}
	else {
		fprintf(stderr, "parity value %s unknown\n", PA);
		fflush(stderr);
	}
E 15
I 15
	fprintf(stderr, "%s: unknown parity value\n", PA);
	fflush(stderr);
E 15
E 14
E 11
E 5
}
E 1
