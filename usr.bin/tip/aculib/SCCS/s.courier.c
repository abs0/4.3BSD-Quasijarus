h15617
s 00067/00036/00287
d D 5.2 87/02/17 19:15:54 karels 2 1
c really ought to be merged with hayes, but this will do for now...
e
s 00323/00000/00000
d D 5.1 86/04/03 16:50:58 donn 1 0
c date and time created 86/04/03 16:50:58 by donn
e
u
U
t
T
I 1
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#define write cour_write
/*
D 2
 * Routines for calling up on a Hayes Smartmodem
E 2
I 2
 * Routines for calling up on a Courier modem.
 * Derived from Hayes driver.
E 2
 */
#include "tip.h"
#include <stdio.h>

#define	MAXRETRY	5

static	int sigALRM();
static	int timeout = 0;
I 2
static	int connected = 0;
E 2
static	jmp_buf timeoutbuf, intbuf;
static	int (*osigint)();

cour_dialer(num, acu)
	register char *num;
	char *acu;
{
	register char *cp;
D 2
	register int connected = 0;
E 2
#ifdef ACULOG
	char line[80];
#endif
	if (boolean(value(VERBOSE)))
		printf("Using \"%s\"\n", acu);

	ioctl(FD, TIOCHPCL, 0);
	/*
	 * Get in synch.
	 */
	if (!coursync()) {
I 2
badsynch:
E 2
		printf("can't synchronize with courier\n");
#ifdef ACULOG
		logent(value(HOST), num, "courier", "can't synch up");
#endif
		return (0);
	}
I 2
	write(FD, "AT E0\r", 6);	/* turn off echoing */
	sleep(1);
#ifdef DEBUG
	if (boolean(value(VERBOSE)))
		verbose_read();
#endif
	ioctl(FD, TIOCFLUSH, 0);	/* flush any clutter */
	write(FD, "AT C1 E0 H0 Q0 X6 V1\r", 21);
	if (!cour_swallow("\r\nOK\r\n"))
		goto badsynch;
E 2
	fflush(stdout);
	write(FD, "AT D", 4);
	for (cp = num; *cp; cp++)
		if (*cp == '=')
			*cp = ',';
	write(FD, num, strlen(num));
	write(FD, "\r", 1);
	connected = cour_connect();
#ifdef ACULOG
	if (timeout) {
		sprintf(line, "%d second dial timeout",
			number(value(DIALTIMEOUT)));
		logent(value(HOST), num, "cour", line);
	}
#endif
	if (timeout)
		cour_disconnect();
	return (connected);
}

cour_disconnect()
D 2
  {
E 2
I 2
{
	 /* first hang up the modem*/
	ioctl(FD, TIOCCDTR, 0);
	sleep(1);
	ioctl(FD, TIOCSDTR, 0);
	coursync();				/* reset */
E 2
	close(FD);
}

cour_abort()
D 2
  {
	write(FD, "\rAT Z\r", 6);
	close(FD);
E 2
I 2
{
	write(FD, "\r", 1);	/* send anything to abort the call */
	cour_disconnect();
E 2
}

static int
sigALRM()
{
	printf("\07timeout waiting for reply\n");
	timeout = 1;
	longjmp(timeoutbuf, 1);
}

static int
cour_swallow(match)
  register char *match;
  {
	char c;
	int (*f)();

	f = signal(SIGALRM, sigALRM);
	timeout = 0;
	do {
		if (*match =='\0') {
			signal(SIGALRM, f);
D 2
			return 1;
E 2
I 2
			return (1);
E 2
		}
		if (setjmp(timeoutbuf)) {
			signal(SIGALRM, f);
			return (0);
		}
		alarm(number(value(DIALTIMEOUT)));
		read(FD, &c, 1);
		alarm(0);
		c &= 0177;
I 2
#ifdef DEBUG
E 2
		if (boolean(value(VERBOSE)))
			putchar(c);
I 2
#endif
E 2
	} while (c == *match++);
I 2
#ifdef DEBUG
E 2
	if (boolean(value(VERBOSE)))
		fflush(stdout);
I 2
#endif
E 2
	signal(SIGALRM, SIG_DFL);
	return (0);
}

struct baud_msg {
	char *msg;
	int baud;
} baud_msg[] = {
	"",		B300,
	" 1200",	B1200,
	" 2400",	B2400,
	0,		0,
};

static int
cour_connect()
{
	char c;
	int nc, nl, n;
	struct sgttyb sb;
	char dialer_buf[64];
	struct baud_msg *bm;
	int (*f)();

	if (cour_swallow("\r\n") == 0)
		return (0);
	f = signal(SIGALRM, sigALRM);
again:
	nc = 0; nl = sizeof(dialer_buf)-1;
	bzero(dialer_buf, sizeof(dialer_buf));
	timeout = 0;
	for (nc = 0, nl = sizeof(dialer_buf)-1 ; nl > 0 ; nc++, nl--) {
		if (setjmp(timeoutbuf))
			break;
		alarm(number(value(DIALTIMEOUT)));
		n = read(FD, &c, 1);
		alarm(0);
		if (n <= 0)
			break;
		c &= 0x7f;
		if (c == '\r') {
			if (cour_swallow("\n") == 0)
				break;
			if (!dialer_buf[0])
				goto again;
D 2
			if (strcmp(dialer_buf, "RINGING") == 0) {
E 2
I 2
			if (strcmp(dialer_buf, "RINGING") == 0 &&
			    boolean(value(VERBOSE))) {
#ifdef DEBUG
E 2
				printf("%s\r\n", dialer_buf);
I 2
#endif
E 2
				goto again;
			}
			if (strncmp(dialer_buf, "CONNECT",
				    sizeof("CONNECT")-1) != 0)
				break;
			for (bm = baud_msg ; bm ; bm++)
				if (strcmp(bm->msg,
				    dialer_buf+sizeof("CONNECT")-1) == 0) {
					if (ioctl(FD, TIOCGETP, &sb) < 0) {
						perror("TIOCGETP");
						goto error;
					}
					sb.sg_ispeed = sb.sg_ospeed = bm->baud;
					if (ioctl(FD, TIOCSETP, &sb) < 0) {
						perror("TIOCSETP");
						goto error;
					}
					signal(SIGALRM, f);
I 2
#ifdef DEBUG
E 2
					if (boolean(value(VERBOSE)))
						printf("%s\r\n", dialer_buf);
I 2
#endif
E 2
					return (1);
				}
			break;
		}
		dialer_buf[nc] = c;
#ifdef notdef
		if (boolean(value(VERBOSE)))
			putchar(c);
#endif
	}
error1:
	printf("%s\r\n", dialer_buf);
error:
	signal(SIGALRM, f);
	return (0);
}

/*
 * This convoluted piece of code attempts to get
D 2
 * the courier in sync.  If you don't have FIONREAD
 * there are gory ways to simulate this.
E 2
I 2
 * the courier in sync.
E 2
 */
static int
coursync()
{
	int already = 0;
I 2
	int len;
	char buf[40];
E 2

D 2
	/*
	 * Toggle DTR to force anyone off that might have left
	 * the modem connected, and insure a consistent state
	 * to start from.
	 *
	 * If you don't have the ioctl calls to diddle directly
	 * with DTR, you can always try setting the baud rate to 0.
	 */
	ioctl(FD, TIOCCDTR, 0);
	sleep(2);
	ioctl(FD, TIOCSDTR, 0);
E 2
	while (already++ < MAXRETRY) {
		ioctl(FD, TIOCFLUSH, 0);	/* flush any clutter */
		write(FD, "\rAT Z\r", 6);	/* reset modem */
D 2
		sleep(2);
		verbose_read();
		write(FD, "AT E0\r", 6);	/* turn off echoing */
		sleep(2);
		verbose_read();
		ioctl(FD, TIOCFLUSH, 0);	/* flush any clutter */
E 2
I 2
		bzero(buf, sizeof(buf));
E 2
		sleep(1);
D 2
		write(FD, "AT C1 E0 H0 Q0 X6 V1\r", 21);
		if (cour_swallow("\r\nOK\r\n")) {
			ioctl(FD, TIOCFLUSH, 0);
			return 1;
E 2
I 2
		ioctl(FD, FIONREAD, &len);
		if (len) {
			len = read(FD, buf, sizeof(buf));
#ifdef DEBUG
			buf[len] = '\0';
			printf("coursync: (\"%s\")\n\r", buf);
#endif
			if (index(buf, '0') || 
		   	   (index(buf, 'O') && index(buf, 'K')))
				return(1);
E 2
		}
D 2
		sleep(2);
E 2
I 2
		/*
		 * If not strapped for DTR control,
		 * try to get command mode.
		 */
		sleep(1);
E 2
		write(FD, "+++", 3);
D 2
		sleep(2);
E 2
I 2
		sleep(1);
		/*
		 * Toggle DTR to force anyone off that might have left
		 * the modem connected.
		 */
		ioctl(FD, TIOCCDTR, 0);
		sleep(1);
		ioctl(FD, TIOCSDTR, 0);
E 2
	}
	write(FD, "\rAT Z\r", 6);
D 2
	return 0;
E 2
I 2
	return (0);
E 2
}

#undef write

cour_write(fd, cp, n)
int fd;
char *cp;
int n;
{
	struct sgttyb sb;
I 2
#ifdef notdef
E 2
	if (boolean(value(VERBOSE)))
		write(1, cp, n);
I 2
#endif
E 2
	ioctl(fd, TIOCGETP, &sb);
	ioctl(fd, TIOCSETP, &sb);
	cour_nap();
	for ( ; n-- ; cp++) {
		write(fd, cp, 1);
		ioctl(fd, TIOCGETP, &sb);
		ioctl(fd, TIOCSETP, &sb);
		cour_nap();
	}
}

I 2
#ifdef DEBUG
E 2
verbose_read()
{
	int n = 0;
	char buf[BUFSIZ];
D 2
	if (!boolean(value(VERBOSE)))
		return;
E 2
I 2

E 2
	if (ioctl(FD, FIONREAD, &n) < 0)
		return;
	if (n <= 0)
		return;
	if (read(FD, buf, n) != n)
		return;
	write(1, buf, n);
}
I 2
#endif
E 2

/*
 * Code stolen from /usr/src/lib/libc/gen/sleep.c
 */
#include <sys/time.h>

#define mask(s) (1<<((s)-1))
#define setvec(vec, a) \
        vec.sv_handler = a; vec.sv_mask = vec.sv_onstack = 0

static napms = 50; /* Give the courier 50 milliseconds between characters */

static int ringring;

cour_nap()
{
	
        static int cour_napx();
	int omask;
        struct itimerval itv, oitv;
        register struct itimerval *itp = &itv;
        struct sigvec vec, ovec;

        timerclear(&itp->it_interval);
        timerclear(&itp->it_value);
        if (setitimer(ITIMER_REAL, itp, &oitv) < 0)
                return;
        setvec(ovec, SIG_DFL);
        omask = sigblock(mask(SIGALRM));
        itp->it_value.tv_sec = napms/1000;
	itp->it_value.tv_usec = ((napms%1000)*1000);
        setvec(vec, cour_napx);
        ringring = 0;
        (void) sigvec(SIGALRM, &vec, &ovec);
        (void) setitimer(ITIMER_REAL, itp, (struct itimerval *)0);
        while (!ringring)
                sigpause(omask &~ mask(SIGALRM));
        (void) sigvec(SIGALRM, &ovec, (struct sigvec *)0);
        (void) setitimer(ITIMER_REAL, &oitv, (struct itimerval *)0);
	(void) sigsetmask(omask);
}

static
cour_napx()
{
        ringring = 1;
}
E 1
