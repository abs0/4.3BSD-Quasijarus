h48506
s 00000/00000/00473
d D 5.11 04/12/08 04:15:12 msokolov 18 17
x 17
c I wrote all this code only to find out that the modem does not after all behave
c the way I thought. Back to smgetty.
e
s 00006/00000/00473
d D 5.10 04/12/07 23:43:22 msokolov 17 16
c smart modem support
e
s 00001/00001/00472
d D 5.9 04/12/07 22:07:50 msokolov 16 15
c tighten up security a little: make ttys mode 600 while in getty
e
s 00010/00005/00463
d D 5.8 03/03/22 18:44:22 msokolov 15 14
c Add PASS8 support (p8 boolean flag)
c This is necessary for 8-bit terminals as the default parity will screw them
e
s 00004/00000/00464
d D 5.7 87/10/01 12:10:42 bostic 14 13
c '-' may not start login name; bug report 4.3BSD/bin/85
e
s 00004/00000/00460
d D 5.6 87/09/16 17:42:54 bostic 13 12
c ioctl mode cleanup; login fail logging; bug report 4.3BSD/etc/34
e
s 00005/00003/00455
d D 5.5 86/01/23 16:29:06 bloom 12 11
c don't do a vhangup if running xterm (from Jim Gettys)
e
s 00004/00000/00454
d D 5.4 85/11/30 11:59:39 mckusick 11 10
c hold DTR down for at least two seconds (from muller@nprdc.arpa)
e
s 00001/00001/00453
d D 5.3 85/09/18 00:01:31 eric 10 9
c facilities in syslog
e
s 00001/00001/00453
d D 5.2 85/09/17 23:27:34 eric 9 8
c facilities in syslog
e
s 00014/00002/00440
d D 5.1 85/04/29 12:06:11 dist 8 7
c Add copyright
e
s 00076/00021/00366
d D 4.7 85/04/01 13:46:26 ralph 7 6
c set up environment partially; do tty open.
e
s 00011/00000/00376
d D 4.6 83/12/13 14:59:07 ralph 6 5
c added %t for tty name to :im= string.
e
s 00001/00000/00375
d D 4.5 83/08/01 16:06:15 sam 5 4
c must flush output before sleep
e
s 00004/00000/00371
d D 4.4 83/07/09 18:34:29 sam 4 3
c allow output to be flushed before first prompt to handle open lines
e
s 00009/00008/00362
d D 4.3 83/07/07 09:26:04 sam 3 2
c forgotten flush
e
s 00043/00004/00327
d D 4.2 83/07/07 03:34:08 kre 2 1
c several fixes (buffered output, parity override bug,
c int's can happen in cbreak, ..)
e
s 00331/00000/00000
d D 4.1 83/07/06 00:10:13 sam 1 0
c date and time created 83/07/06 00:10:13 by sam
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
#ifndef lint
D 8
static char sccsid[] = "%W% (Berkeley) %E%";
#endif
E 8
I 8
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8

/*
 * getty -- adapt to terminal speed on dialup, and call login
 *
 * Melbourne getty, June 83, kre.
 */

#include <sgtty.h>
#include <signal.h>
#include <ctype.h>
#include <setjmp.h>
I 7
#include <syslog.h>
#include <sys/file.h>
E 7
#include "gettytab.h"

I 7
extern	char **environ;

E 7
struct	sgttyb tmode = {
	0, 0, CERASE, CKILL, 0
};
struct	tchars tc = {
	CINTR, CQUIT, CSTART,
	CSTOP, CEOF, CBRK,
};
struct	ltchars ltc = {
	CSUSP, CDSUSP, CRPRNT,
	CFLUSH, CWERASE, CLNEXT
};

int	crmod;
int	upper;
int	lower;
int	digit;

char	hostname[32];
char	name[16];
I 7
char	dev[] = "/dev/";
char	ctty[] = "/dev/console";
char	ttyn[32];
E 7
char	*portselector();
I 7
char	*ttyname();
E 7

I 2
#define	OBUFSIZ		128
E 2
#define	TABBUFSIZ	512

char	defent[TABBUFSIZ];
char	defstrs[TABBUFSIZ];
char	tabent[TABBUFSIZ];
char	tabstrs[TABBUFSIZ];

char	*env[128];

char partab[] = {
	0001,0201,0201,0001,0201,0001,0001,0201,
	0202,0004,0003,0205,0005,0206,0201,0001,
	0201,0001,0001,0201,0001,0201,0201,0001,
	0001,0201,0201,0001,0201,0001,0001,0201,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0201
};

#define	ERASE	tmode.sg_erase
#define	KILL	tmode.sg_kill
#define	EOT	tc.t_eofc

jmp_buf timeout;

dingdong()
{

	alarm(0);
	signal(SIGALRM, SIG_DFL);
	longjmp(timeout, 1);
}

I 2
jmp_buf	intrupt;

interrupt()
{

	signal(SIGINT, interrupt);
	longjmp(intrupt, 1);
}

E 2
main(argc, argv)
	char *argv[];
{
	char *tname;
	long allflags;
I 7
	int repcnt = 0;
E 7

D 2
/*
E 2
	signal(SIGINT, SIG_IGN);
I 2
/*
E 2
	signal(SIGQUIT, SIG_DFL);
*/
I 7
D 9
	openlog("getty", LOG_ODELAY|LOG_CONS, 0);
E 9
I 9
	openlog("getty", LOG_ODELAY|LOG_CONS, LOG_AUTH);
E 9
E 7
	gethostname(hostname, sizeof(hostname));
	if (hostname[0] == '\0')
		strcpy(hostname, "Amnesiac");
I 7
	/*
	 * The following is a work around for vhangup interactions
	 * which cause great problems getting window systems started.
	 * If the tty line is "-", we do the old style getty presuming
	 * that the file descriptors are already set up for us. 
	 * J. Gettys - MIT Project Athena.
	 */
	if (argc <= 2 || strcmp(argv[2], "-") == 0)
D 12
		strcpy(ttyn, ttyname(0));
E 12
I 12
	    strcpy(ttyn, ttyname(0));
E 12
	else {
D 12
		strcpy(ttyn, dev);
		strncat(ttyn, argv[2], sizeof(ttyn)-sizeof(dev));
E 12
I 12
	    strcpy(ttyn, dev);
	    strncat(ttyn, argv[2], sizeof(ttyn)-sizeof(dev));
	    if (strcmp(argv[0], "+") != 0) {
E 12
		chown(ttyn, 0, 0);
D 16
		chmod(ttyn, 0622);
E 16
I 16
		chmod(ttyn, 0600);
E 16
I 11
		/*
		 * Delay the open so DTR stays down long enough to be detected.
		 */
		sleep(2);
E 11
		while (open(ttyn, O_RDWR) != 0) {
			if (repcnt % 10 == 0) {
D 10
				syslog(LOG_FAIL, "%s: %m", ttyn);
E 10
I 10
				syslog(LOG_ERR, "%s: %m", ttyn);
E 10
				closelog();
			}
			repcnt++;
			sleep(60);
		}
		signal(SIGHUP, SIG_IGN);
		vhangup();
		(void) open(ttyn, O_RDWR);
		close(0);
		dup(1);
		dup(0);
		signal(SIGHUP, SIG_DFL);
I 12
	    }
E 12
	}

E 7
	gettable("default", defent, defstrs);
	gendefaults();
	tname = "default";
	if (argc > 1)
		tname = argv[1];
	for (;;) {
		int ldisp = OTTYDISC;
I 13
		int off = 0;
E 13

		gettable(tname, tabent, tabstrs);
I 2
		if (OPset || EPset || APset)
			APset++, OPset++, EPset++;
E 2
		setdefaults();
I 15
		ioctl(0, TIOCSETD, &ldisp);
E 15
		ioctl(0, TIOCFLUSH, 0);		/* clear out the crap */
I 13
		ioctl(0, FIONBIO, &off);	/* turn off non-blocking mode */
		ioctl(0, FIOASYNC, &off);	/* ditto for asynchronous mode */
E 13
		if (IS)
			tmode.sg_ispeed = speed(IS);
		else if (SP)
			tmode.sg_ispeed = speed(SP);
		if (OS)
			tmode.sg_ospeed = speed(OS);
		else if (SP)
			tmode.sg_ospeed = speed(SP);
D 15
		tmode.sg_flags = setflags(0);
E 15
I 15
		allflags = setflags(0);
		tmode.sg_flags = allflags & 0xFFFF;
E 15
		ioctl(0, TIOCSETP, &tmode);
I 15
		allflags >>= 16;
		ioctl(0, TIOCLSET, &allflags);
E 15
		setchars();
		ioctl(0, TIOCSETC, &tc);
D 15
		ioctl(0, TIOCSETD, &ldisp);
E 15
		if (HC)
			ioctl(0, TIOCHPCL, 0);
I 7
		if (AB) {
			extern char *autobaud();

			tname = autobaud();
			continue;
		}
I 17
		if (SM) {
			extern char *smartmodem();

			tname = smartmodem();
			continue;
		}
E 17
E 7
		if (PS) {
			tname = portselector();
			continue;
		}
		if (CL && *CL)
			putpad(CL);
		edithost(HE);
		if (IM && *IM)
			putf(IM);
		if (setjmp(timeout)) {
			tmode.sg_ispeed = tmode.sg_ospeed = 0;
			ioctl(0, TIOCSETP, &tmode);
			exit(1);
		}
		if (TO) {
			signal(SIGALRM, dingdong);
			alarm(TO);
		}
		if (getname()) {
I 7
			register int i;

			oflush();
E 7
			alarm(0);
			signal(SIGALRM, SIG_DFL);
I 14
			if (name[0] == '-') {
				puts("login names may not start with '-'.");
				continue;
			}
E 14
D 3
			if (!(upper||lower||digit))
E 3
I 3
			if (!(upper || lower || digit))
E 3
				continue;
			allflags = setflags(2);
			tmode.sg_flags = allflags & 0xffff;
			allflags >>= 16;
			if (crmod || NL)
				tmode.sg_flags |= CRMOD;
			if (upper || UC)
				tmode.sg_flags |= LCASE;
			if (lower || LC)
				tmode.sg_flags &= ~LCASE;
			ioctl(0, TIOCSETP, &tmode);
			ioctl(0, TIOCSLTC, &ltc);
			ioctl(0, TIOCLSET, &allflags);
D 7
			putchr('\n');
I 3
			oflush();
E 3
			makeenv(env);
E 7
I 2
			signal(SIGINT, SIG_DFL);
E 2
D 7
			execle(LO, "login", name, (char *)0, env);
E 7
I 7
			for (i = 0; environ[i] != (char *)0; i++)
				env[i] = environ[i];
			makeenv(&env[i]);
			execle(LO, "login", "-p", name, (char *) 0, env);
I 13
			syslog(LOG_ERR, "%s: %m", LO);
E 13
E 7
			exit(1);
		}
		alarm(0);
		signal(SIGALRM, SIG_DFL);
I 2
		signal(SIGINT, SIG_IGN);
E 2
		if (NX && *NX)
			tname = NX;
	}
}

getname()
{
	register char *np;
	register c;
	char cs;

I 2
	/*
D 3
	 * interrupt may happen if we use CBREAK mode
E 3
I 3
	 * Interrupt may happen if we use CBREAK mode
E 3
	 */
	if (setjmp(intrupt)) {
		signal(SIGINT, SIG_IGN);
		return (0);
	}
	signal(SIGINT, interrupt);
E 2
	tmode.sg_flags = setflags(0);
	ioctl(0, TIOCSETP, &tmode);
	tmode.sg_flags = setflags(1);
	prompt();
I 4
	if (PF > 0) {
I 5
		oflush();
E 5
		sleep(PF);
		PF = 0;
	}
E 4
	ioctl(0, TIOCSETP, &tmode);
	crmod = 0;
	upper = 0;
	lower = 0;
	digit = 0;
	np = name;
	for (;;) {
I 2
		oflush();
E 2
		if (read(0, &cs, 1) <= 0)
			exit(0);
		if ((c = cs&0177) == 0)
			return (0);
D 3
		if (c==EOT)
E 3
I 3
		if (c == EOT)
E 3
			exit(1);
D 3
		if (c=='\r' || c=='\n' || np >= &name[16])
E 3
I 3
D 7
		if (c == '\r' || c == '\n' || np >= &name[16])
E 7
I 7
		if (c == '\r' || c == '\n' || np >= &name[sizeof name]) {
			putf("\r\n");
E 7
E 3
			break;
D 7

E 7
I 7
		}
E 7
D 3
		if (c>='a' && c <='z')
E 3
I 3
		if (c >= 'a' && c <= 'z')
E 3
			lower++;
D 3
		else if (c>='A' && c<='Z') {
E 3
I 3
D 7
		else if (c >= 'A' && c <= 'Z') {
E 7
I 7
		else if (c >= 'A' && c <= 'Z')
E 7
E 3
			upper++;
D 2
		} else if (c==ERASE) {
E 2
I 2
D 3
		} else if (c==ERASE || c=='#' || c=='\b') {
E 3
I 3
D 7
		} else if (c == ERASE || c == '#' || c == '\b') {
E 7
I 7
		else if (c == ERASE || c == '#' || c == '\b') {
E 7
E 3
E 2
			if (np > name) {
				np--;
				if (tmode.sg_ospeed >= B1200)
					puts("\b \b");
				else
					putchr(cs);
			}
			continue;
D 2
		} else if (c==KILL) {
E 2
I 2
D 3
		} else if (c==KILL || c=='@') {
E 3
I 3
		} else if (c == KILL || c == '@') {
E 3
E 2
			putchr(cs);
			putchr('\r');
			if (tmode.sg_ospeed < B1200)
				putchr('\n');
			/* this is the way they do it down under ... */
			else if (np > name)
				puts("                                     \r");
			prompt();
			np = name;
			continue;
D 7
		} else if (c == ' ')
			c = '_';
		else if (c >= '0' && c <= '9')
E 7
I 7
		} else if (c >= '0' && c <= '9')
E 7
			digit++;
D 7
		if (IG && (c < ' ' || c > 0176))
E 7
I 7
		if (IG && (c <= ' ' || c > 0176))
E 7
			continue;
		*np++ = c;
		putchr(cs);
	}
I 2
	signal(SIGINT, SIG_IGN);
E 2
	*np = 0;
	if (c == '\r')
		crmod++;
	if (upper && !lower && !LC || UC)
		for (np = name; *np; np++)
			if (isupper(*np))
				*np = tolower(*np);
	return (1);
}

static
short	tmspc10[] = {
	0, 2000, 1333, 909, 743, 666, 500, 333, 166, 83, 55, 41, 20, 10, 5, 15
};

putpad(s)
	register char *s;
{
	register pad = 0;
	register mspc10;

	if (isdigit(*s)) {
		while (isdigit(*s)) {
			pad *= 10;
			pad += *s++ - '0';
		}
		pad *= 10;
		if (*s == '.' && isdigit(s[1])) {
			pad += s[1] - '0';
			s += 2;
		}
	}

	puts(s);
	/*
	 * If no delay needed, or output speed is
	 * not comprehensible, then don't try to delay.
	 */
	if (pad == 0)
		return;
	if (tmode.sg_ospeed <= 0 ||
	    tmode.sg_ospeed >= (sizeof tmspc10 / sizeof tmspc10[0]))
		return;

	/*
	 * Round up by a half a character frame,
	 * and then do the delay.
	 * Too bad there are no user program accessible programmed delays.
	 * Transmitting pad characters slows many
	 * terminals down and also loads the system.
	 */
	mspc10 = tmspc10[tmode.sg_ospeed];
	pad += mspc10 / 2;
	for (pad /= mspc10; pad > 0; pad--)
		putchr(*PC);
}

puts(s)
	register char *s;
{

	while (*s)
		putchr(*s++);
}

I 2
char	outbuf[OBUFSIZ];
int	obufcnt = 0;

E 2
putchr(cc)
{
	char c;

	c = cc;
D 15
	c |= partab[c&0177] & 0200;
	if (OP)
		c ^= 0200;
E 15
I 15
	if (!P8) {
		c |= partab[c&0177] & 0200;
		if (OP)
			c ^= 0200;
	}
E 15
D 2
	write(1, &c, 1);
E 2
I 2
	if (!UB) {
		outbuf[obufcnt++] = c;
		if (obufcnt >= OBUFSIZ)
			oflush();
	} else
		write(1, &c, 1);
}

oflush()
{
	if (obufcnt)
		write(1, outbuf, obufcnt);
	obufcnt = 0;
E 2
}

prompt()
{

	putf(LM);
	if (CO)
		putchr('\n');
}

putf(cp)
	register char *cp;
{
I 6
D 7
	char *tp;
E 7
I 7
	char *ttyn, *slash;
	char datebuffer[60];
E 7
E 6
	extern char editedhost[];
I 6
D 7
	extern char *ttyname();
E 7
I 7
	extern char *ttyname(), *rindex();
E 7
E 6

	while (*cp) {
		if (*cp != '%') {
			putchr(*cp++);
			continue;
		}
		switch (*++cp) {

I 7
		case 't':
			ttyn = ttyname(0);
			slash = rindex(ttyn, '/');
			if (slash == (char *) 0)
				puts(ttyn);
			else
				puts(&slash[1]);
			break;

E 7
		case 'h':
			puts(editedhost);
I 6
			break;

D 7
		case 't':
			tp = ttyname(0);
			if (tp != (char *)0) {
				if (strncmp(tp, "/dev/", 5) == 0)
					tp += 5;
				puts(tp);
			}
E 7
I 7
		case 'd':
			get_date(datebuffer);
			puts(datebuffer);
E 7
E 6
			break;

		case '%':
			putchr('%');
			break;
		}
		cp++;
	}
}
E 1
