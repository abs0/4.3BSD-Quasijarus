/*
 * Generic job filter for PostScript printers - sends ready PostScript
 * to the interpreter over the serial link.  Designed for classic serial
 * PostScript printers like Apple LaserWriter and DEC LN03R.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 *
 * Operation:
 *
 * The job to be printed is on descriptor 0.  Descriptor 1 is the
 * serial line to the PostScript printer opened for read/write and set
 * to raw mode.  The job is copied to the printer, filtered of undesirable
 * characters (trojans) and terminated with EOT.  During the entire
 * process descriptor 1 is continuously monitored for feedback from the
 * printer.  XON and XOFF are detected and the data stream to the printer
 * is manually throttled.  All other job messages are collected, converted
 * to UNIX newline convention and sent to descriptor 2, the filter errors
 * file.  EOT from the printer indicates it's done with this job, and we
 * wait for it to make sure that our job was fully accepted.  Exit status
 * is normally 0, but changed to 3 if any job messages were collected.
 * By lpd convention this indicates that the job was printed, but may have
 * had errors.
 *
 * If a docopts.ps file is present (banneropts.ps if invoked with -b),
 * it is prepended to the job.
 *
 * Descriptor 1 is set to non-blocking I/O mode.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <stdio.h>

extern int errno;
extern int optind;
extern char *optarg;

int infd, banner, eof, eotpend, xon = 1;
#define	INBUFLEN	4096
char inbuf[INBUFLEN];
int inbufcnt, inbufpos;
#define	OUTBUFLEN	256
char outbuf[OUTBUFLEN];
int outbufcnt;
#define	MSGBUFLEN	256
char msgbuf[MSGBUFLEN];
int msgbufcnt, msggotcr;
int exitstatus;

int one = 1;
struct timeval zerotime;

main(argc, argv)
	char **argv;
{
	register int c, cc, i;
	fd_set readfds, writefds;
	int nfds;
	char feedbackbuf[256];

	while ((c = getopt(argc, argv, "P:O:bw:l:x:y:n:h:")) > 0)
		switch (c) {
		case 'b':
			banner = 1;
			continue;
		case '?':
			exit(2);
		}
	infd = open(banner ? "banneropts.ps" : "docopts.ps", O_RDONLY);
	if (infd < 0)
		infd = 0;	/* no prefix, go directly to the job */
	nfds = MAX(1, infd) + 1;
	ioctl(1, FIONBIO, &one);

	for (;;) {
		FD_ZERO(&readfds);
		FD_SET(1, &readfds);
		if (!eof && !inbufcnt)
			FD_SET(infd, &readfds);
		FD_ZERO(&writefds);
		if (outbufcnt && xon)
			FD_SET(1, &writefds);
		c = select(nfds, &readfds, &writefds, NULL,
			(inbufcnt || eotpend) && outbufcnt < OUTBUFLEN ?
			&zerotime : NULL);
		if (c < 0) {
			if (errno == EINTR)
				continue;
			perror("lppsjf: select");
			exit(3);
		}
		if (FD_ISSET(1, &readfds)) {
			cc = read(1, feedbackbuf, 256);
			if (cc <= 0) {
				perror("lppsjf: channel read error");
				exit(3);
			}
			for (i = 0; i < cc; i++) {
				c = feedbackbuf[i];
				switch (c) {
				case 0x04:		/* EOT */
					/* All done */
					exit(exitstatus);
				case '\n':
					if (msggotcr) {
						msggotcr = 0;
						continue;
					}
					process_feedback_msg();
					msgbufcnt = 0;
					continue;
				case '\r':
					process_feedback_msg();
					msgbufcnt = 0;
					msggotcr = 1;
					continue;
				case 0x11:		/* XON */
					xon = 1;
					ioctl(1, TIOCSTART);
					continue;
				case 0x13:		/* XOFF */
					xon = 0;
					ioctl(1, TIOCSTOP);
					continue;
				default:
					msggotcr = 0;
					if (msgbufcnt < MSGBUFLEN - 1)
						msgbuf[msgbufcnt++] = c;
					continue;
				}
			}
		}
		if (FD_SET(infd, &readfds)) {
			cc = read(infd, inbuf, INBUFLEN);
			if (cc < 0)
				cc = 0;
			inbufcnt = cc;
			inbufpos = 0;
			if (cc == 0) {
				if (infd) {
					/* done with the prefix, do the job */
					close(infd);
					infd = 0;
				} else
					eof = eotpend = 1;
			}
		}
		while (inbufpos < inbufcnt && outbufcnt < OUTBUFLEN) {
			c = inbuf[inbufpos++];
			/*
			 * Check for trojans. Our rules basically correspond
			 * to PostScript LRM definition of Clean8Bit, with the
			 * following 2 differences:
			 *
			 * - 0x7F (DEL) is not allowed in Clean8Bit, but we
			 *   don't block it since I can see no harm and it
			 *   would take extra work to block it.
			 *
			 * - 0x1B (ESC) is allowed by PostScript LRM for both
			 *   Clean7Bit and Clean8Bit. We have to block it,
			 *   however, since it opens too many holes. HP
			 *   printers (i.e., the world majority) do not allow
			 *   PCL/PJL to be completely blocked. Even if set to
			 *   PS personality, a luser could send some PJL
			 *   command and it would act on it, catapulting us out
			 *   of PostScript into whatever else, i.e., we could
			 *   be screwed. We must block it.
			 *
			 * It seems like PostScript LRM allows ESC quite
			 * deliberately, even though it's clearly not for
			 * PostScript but for legacy languages. I guess they
			 * did it to legitimize printers with emulations. But
			 * I still argue that it is not for PostScript and that
			 * our pure PS system has the right to disallow it.
			 */
			if (c >= 0x1C || c == '\n' || c == '\r' || c == '\t')
				outbuf[outbufcnt++] = c;
		}
		if (eotpend && outbufcnt < OUTBUFLEN) {
			outbuf[outbufcnt++] = 0x04;
			eotpend = 0;
		}


}
