/*
 * smart modem getty
 *
 * This program is a front-end to getty for smart modems that speak AT commands.
 * Traditionally these modems have been configured for automatic answer with
 * modem messages suppressed, i.e., effectively reduced to dumb modems, when
 * connected to UNIX.  This program supports the alternative approach of
 * keeping the modem in its native smart configuration (AT commands enabled,
 * verbose responses enabled, no auto answer), answering calls with ATA upon
 * ring detection, and waiting for the CONNECT response.  getty nnn-baud is
 * execed upon successful connection.
 *
 * This program assumes and requires a smart modem that supports a wide range
 * of speeds and corresponding modulation schemes from 300 bps to 9600 bps or
 * higher (up to 33.6 kbps), and is configured for autobaud mode.  AT commands
 * are chatted at 9600 baud.  Raw mode is used for chatting AT commands and the
 * ATA command is sent with the high bit clear, putting the smart modem in
 * 8-N-1 mode.  See the man page for explanation.  Ringing is detected through
 * the RS-232 RI line, not in-band RING messages.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "@(#)smgetty.c	5.3 (Berkeley) 04/12/08";
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
int lmode = LNOHANG;
char baudrate[16];
char readbuf[256];
int rbcnt, rbpos;
int zero;

main(argc, argv)
	char **argv;
{
	int repcnt = 0;
	int mstat;
	fd_set xfds;
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
	signal(SIGHUP, SIG_IGN);
	while (open(ttyn, O_RDWR | O_NDELAY) != 0) {
		if (repcnt % 10 == 0) {
			syslog(LOG_ERR, "%s: %m", ttyn);
			closelog();
		}
		repcnt++;
		sleep(60);
	}
	vhangup();
	(void) open(ttyn, O_RDWR | O_NDELAY);
	close(0);
	dup(1);
	dup(0);
	/* essential tty setup */
	ioctl(0, TIOCSETP, &tmode);
	ioctl(0, TIOCLSET, &lmode);
	ioctl(0, TIOCHPCL, 0);
	/* wait for ring */
waitr:	ioctl(0, TIOCSDTR, 0);
	for (;;) {
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
		getmline(mline, sizeof(mline));
		if (!strncmp(mline, "CONNECT", 7))
			break;
		if (strcmp(mline, "NO CARRIER"))
			continue;
		alarm(0);
		goto waitr;
	}
	alarm(0);
	/* connected! */
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
		goto waitr;
	}
	sprintf(baudrate, "%d-baud", speed);
	signal(SIGHUP, SIG_DFL);
	closelog();
	execl("/etc/getty", "getty", baudrate, "-", NULL);
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

loop1:	while ((c = getch()) != '\n')
		;
	while (c == '\n')
		c = getch();
	if (!isupper(c))
		goto loop1;
	for (cp = buf, s = 0; ; ) {
		if (s < size - 1) {
			*cp++ = c;
			s++;
		}
		c = getch();
		if (c == '\r' || c == '\n')
			break;
	}
	*cp = '\0';
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
}
