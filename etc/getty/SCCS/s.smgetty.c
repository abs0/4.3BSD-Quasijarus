h59670
s 00031/00017/00153
d D 5.3 04/12/08 04:08:44 msokolov 3 2
c go by RS-232 RI signal instead of RING in-band message
e
s 00028/00012/00142
d D 5.2 04/12/08 01:51:46 msokolov 2 1
c mostly works correctly
e
s 00154/00000/00000
d D 5.1 04/12/07 20:00:55 msokolov 1 0
c date and time created 04/12/07 20:00:55 by msokolov
e
u
U
t
T
I 1
/*
 * smart modem getty
 *
 * This program is a front-end to getty for smart modems that speak AT commands.
 * Traditionally these modems have been configured for automatic answer with
 * modem messages suppressed, i.e., effectively reduced to dumb modems, when
 * connected to UNIX.  This program supports the alternative approach of
 * keeping the modem in its native smart configuration (AT commands enabled,
 * verbose responses enabled, no auto answer), answering calls with ATA upon
D 3
 * seeing RING, and waiting for the CONNECT response.  getty nnn-baud is execed
 * upon successful connection.
E 3
I 3
 * ring detection, and waiting for the CONNECT response.  getty nnn-baud is
 * execed upon successful connection.
E 3
 *
 * This program assumes and requires a smart modem that supports a wide range
 * of speeds and corresponding modulation schemes from 300 bps to 9600 bps or
 * higher (up to 33.6 kbps), and is configured for autobaud mode.  AT commands
 * are chatted at 9600 baud.  Raw mode is used for chatting AT commands and the
 * ATA command is sent with the high bit clear, putting the smart modem in
D 3
 * 8-N-1 mode.  See the man page for explanation.
E 3
I 3
 * 8-N-1 mode.  See the man page for explanation.  Ringing is detected through
 * the RS-232 RI line, not in-band RING messages.
E 3
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <syslog.h>

char ttyn[16] = "/dev/";
struct	sgttyb tmode = {
	B9600, B9600, CERASE, CKILL, RAW|ANYP
};
I 2
int lmode = LNOHANG;
E 2
char baudrate[16];
I 2
char readbuf[256];
int rbcnt, rbpos;
I 3
int zero;
E 3
E 2

main(argc, argv)
	char **argv;
{
	int repcnt = 0;
I 3
	int mstat;
	fd_set xfds;
E 3
	char mline[64];
	register int speed;

	if (argc < 2)
		exit(1);
	strcpy(ttyn + 5, argv[1]);
	openlog("smgetty", LOG_ODELAY, LOG_AUTH);
	/* Duplicate getty logic for opening the tty */
	chown(ttyn, 0, 0);
	chmod(ttyn, 0600);
	/*
	 * Delay the open so DTR stays down long enough to be detected.
	 */
	sleep(2);
I 2
	signal(SIGHUP, SIG_IGN);
E 2
	while (open(ttyn, O_RDWR | O_NDELAY) != 0) {
		if (repcnt % 10 == 0) {
			syslog(LOG_ERR, "%s: %m", ttyn);
			closelog();
		}
		repcnt++;
		sleep(60);
	}
D 2
	signal(SIGHUP, SIG_IGN);
E 2
	vhangup();
	(void) open(ttyn, O_RDWR | O_NDELAY);
	close(0);
	dup(1);
	dup(0);
D 3
	/* prepare for chatting AT */
E 3
I 3
	/* essential tty setup */
E 3
	ioctl(0, TIOCSETP, &tmode);
D 2
loop:	ioctl(0, TIOCSOFTCAR, 0);
E 2
I 2
	ioctl(0, TIOCLSET, &lmode);
	ioctl(0, TIOCHPCL, 0);
D 3
loop:	ioctl(0, TIOCSDTR, 0);
E 2
	/* main loop: answer calls */
E 3
I 3
	/* wait for ring */
waitr:	ioctl(0, TIOCSDTR, 0);
E 3
	for (;;) {
I 3
		ioctl(0, TIOCMGET, &mstat);
		if (mstat & TIOCM_RI)
			break;
		FD_ZERO(&xfds);
		FD_SET(0, &xfds);
		select(1, NULL, NULL, &xfds, NULL);
	}
	/* It's ringing. Answer it! */
	ioctl(0, TIOCFLUSH, &zero);
	rbcnt = 0;
	ioctl(1, TIOCSOFTCAR, 0);
	write(1, "ATA\r", 4);
	/* collect the response */
	alarm(90);
	for (;;) {
E 3
		getmline(mline, sizeof(mline));
D 3
		if (strcmp(mline, "RING"))
			continue;
I 2
		ioctl(1, TIOCSOFTCAR, 0);
E 2
		write(1, "ATA\r", 4);
		getmline(mline, sizeof(mline));
		if (!strcmp(mline, "ATA"))
			getmline(mline, sizeof(mline));
E 3
		if (!strncmp(mline, "CONNECT", 7))
			break;
D 3
		if (!strcmp(mline, "NO CARRIER"))
E 3
I 3
		if (strcmp(mline, "NO CARRIER"))
E 3
			continue;
D 3
		syslog(LOG_ERR, "%s: unexpected modem response: %s", ttyn+5,
			mline);
E 3
I 3
		alarm(0);
		goto waitr;
E 3
	}
I 3
	alarm(0);
	/* connected! */
E 3
	syslog(LOG_INFO, "%s: %s", ttyn+5, mline);
	if (mline[7] == ' ' && isdigit(mline[8]))
		speed = atoi(mline+8);
	else
		speed = 300;
	/* valid modem speeds that are also legal RS-232 baud rates */
	if (speed == 300 || speed == 600 || speed == 1200 || speed == 2400 ||
	    speed == 4800 || speed == 9600)
		;
	/* valid modem speeds that are NOT legal RS-232 baud rates */
	else if (speed > 4800 && speed < 9600)		/* V.32 7200 bps */
		speed = 9600;
	else if (speed > 9600 && speed <= 19200)	/* 14.4 kbps */
		speed = 19200;
	else if (speed > 19200 && speed <= 38400)	/* 28.8-33.6 kbps */
		speed = 38400;
	else {
		syslog(LOG_ERR, "%s: invalid connection speed: %d", ttyn+5,
			speed);
		/* hang up and take the next call */
		ioctl(0, TIOCCDTR, 0);
		sleep(2);
D 2
		ioctl(0, TIOCSDTR, 0);
E 2
D 3
		goto loop;
E 3
I 3
		goto waitr;
E 3
	}
	sprintf(baudrate, "%d-baud", speed);
	signal(SIGHUP, SIG_DFL);
	closelog();
D 2
	execl("/etc/getty", "getty", baudrate, ttyn+5, NULL);
E 2
I 2
	execl("/etc/getty", "getty", baudrate, "-", NULL);
E 2
}

/*
 * Get a modem response line.
 * Uses the fact that all modem response lines are immediately preceded by a \n
 * and terminated by a \r.
 */
getmline(buf, size)
	char *buf;
{
	register int c, s;
	register char *cp;

D 2
loop1:	while ((c = getchar()) != '\n')
		if (c == EOF) {
			syslog(LOG_ERR, "%s: read: %m", ttyn);
			exit(1);
		}
E 2
I 2
loop1:	while ((c = getch()) != '\n')
		;
E 2
	while (c == '\n')
D 2
		c = getchar();
E 2
I 2
		c = getch();
E 2
	if (!isupper(c))
		goto loop1;
	for (cp = buf, s = 0; ; ) {
		if (s < size - 1) {
			*cp++ = c;
			s++;
		}
D 2
		c = getchar();
		if (c == '\r' || c == '\n' || c == EOF)
E 2
I 2
		c = getch();
		if (c == '\r' || c == '\n')
E 2
			break;
	}
	*cp = '\0';
I 2
}

/* replacement for getchar() that does what we want */
getch()
{
	if (rbpos >= rbcnt) {
		do {
			ioctl(0, TIOCSOFTCAR, 0);
			rbcnt = read(0, readbuf, sizeof(readbuf));
		}
		while (rbcnt <= 0);
		rbpos = 0;
	}
	return(readbuf[rbpos++] & 0177);
E 2
}
E 1
