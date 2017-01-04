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
 * This filter supports accounting.  If accounting is requested, we read the
 * printer's page count before and after the job and log the difference.  We
 * read the page count by transmitting "statusdict begin pagecount = end\n\4"
 * and collecting the response (EOT-terminated).  Thus both page count readings
 * are separated from the job itself.
 *
 * Implementation:
 *
 * We fork and use two processes.  The child copies the job from stdin to the
 * printer while the parent monitors the feedback from the printer.
 */

#ifndef lint
static char sccsid[] = "@(#)lppsjf.c	5.5 (Berkeley) 8/23/04";
#endif

#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <stdio.h>
#include <strings.h>
#include <syslog.h>

extern int errno;
extern int optind;
extern char *optarg;

int banner;
int child;
#define	MSGBUFLEN	256
char msgbuf[MSGBUFLEN];
int msgbufcnt;
int exitstatus;
char eot = 0x04;
char *user, *host, *acctfile;
int initpagecount;

int sigchld(), sigquit();

main(argc, argv)
	char **argv;
{
	register int c;

	openlog("lppsjf", LOG_PID, LOG_LPR);
	while ((c = getopt(argc, argv, "P:O:bci:w:l:x:y:n:h:")) > 0)
		switch (c) {
		case 'b':
			banner = 1;
			continue;
		case 'n':
			user = optarg;
			continue;
		case 'h':
			host = optarg;
			continue;
		case '?':
			exit(2);
		}
	acctfile = argv[optind];
	if (user && acctfile)
		initpagecount = read_pagecount();
	signal(SIGCHLD, sigchld);
	sigblock(sigmask(SIGQUIT));
	c = fork();
	if (c < 0) {
		perror("fork");
		exit(2);
	}
	if (c == 0)
		sendjob();
	else {
		sigsetmask(0);
		child = c;
		monitor();
	}
}

/* executes in the child */
sendjob()
{
	register FILE *hf;
	register int c;

	signal(SIGQUIT, sigquit);
	sigsetmask(0);
	hf = fopen(banner ? "banneropts.ps" : "docopts.ps", "r");
	if (hf) {
		while ((c = getc(hf)) >= 0) {
			putchar(c);
			if (ferror(stdout))
				_exit(errno);
		}
		fclose(hf);
	}
	while ((c = getchar()) >= 0) {
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
			putchar(c);
		if (ferror(stdout))
			_exit(errno);
	}
	sigblock(sigmask(SIGQUIT));
	putchar(0x04);
	if (ferror(stdout))
		_exit(errno);
	fflush(stdout);
	if (ferror(stdout))
		_exit(errno);
	_exit(0);
}

/* executes in the parent */
monitor()
{
	register int c;
	register int gotcr = 0;

	dup2(1, 0);
	while ((c = getchar()) >= 0) {
		switch (c) {
		case 0x04:		/* EOT */
			if (msgbufcnt)
				process_feedback_msg();
			/* All done, see if we need to charge the user */
			if (user && acctfile && initpagecount)
				bill_user();
			exit(exitstatus);
		case '\t':
			gotcr = 0;
			goto msgchar;
		case '\n':
			if (gotcr) {
				gotcr = 0;
				continue;
			}
			process_feedback_msg();
			msgbufcnt = 0;
			continue;
		case '\r':
			process_feedback_msg();
			msgbufcnt = 0;
			gotcr = 1;
			continue;
		case 0x11:		/* XON */
			ioctl(1, TIOCSTART);
			continue;
		case 0x13:		/* XOFF */
			ioctl(1, TIOCSTOP);
			continue;
		default:
			gotcr = 0;
			/* Filter out garbage */
			if (c < 0x20 || c >= 0x7F && c <= 0x9F)
				continue;
		msgchar:
			if (msgbufcnt < MSGBUFLEN - 1)
				msgbuf[msgbufcnt++] = c;
			continue;
		}
	}
	perror("lppsjf: channel read error");
	exit(3);
}

/* executes in the parent */
process_feedback_msg()
{
	msgbuf[msgbufcnt] = '\0';
	/* Any pre-logging processing goes here */
	if (!strncmp(msgbuf, "%%[ status: ", 12))
		return;
	/* Log it in job messages and set exit status to 3 */
	fprintf(stderr, "%s\n", msgbuf);
	exitstatus = 3;
	/* Any post-logging processing goes here */
	if (!strcmp(msgbuf,
	    "%%[ Flushing: rest of job (to end-of-file) will be ignored ]%%")) {
		/* No point in sending the rest of the job, cut it off */
		kill(child, SIGQUIT);
	}
}

/* executes in the parent */
sigchld()
{
	union wait status;

	wait(&status);
	if (WIFEXITED(status) && status.w_retcode) {
		errno = status.w_retcode;
		perror("lppsjf: channel write error");
		exit(3);
	}
}

/* executes in the child */
sigquit()
{
	register int i;

	i = write(1, &eot, 1);
	if (i < 0)
		_exit(errno);
	else
		_exit(0);
}

read_pagecount()
{
	static char query[35] = "statusdict begin pagecount = end\n\4";
	char buf[16], *end;
	register char *cp;
	register int cc;

	write(1, query, 34);
	for (cp = buf, end = cp + 16; cp < end; ) {
		cc = read(1, cp, end - cp);
		if (cc <= 0)
			goto fail;
		while (cc) {
			if (*cp++ == 0x04) {
				cc = atoi(buf);
				syslog(LOG_DEBUG, "read page count %d", cc);
				if (!cc)
					goto fail;
				return(cc);
			}
			cc--;
		}
	}
fail:	syslog(LOG_ERR, "page count read failure");
	return(0);
}

bill_user()
{
	int finalpagecount, npages;
	register FILE *af;

	finalpagecount = read_pagecount();
	if (!finalpagecount)			/* read failed */
		return;
	npages = finalpagecount - initpagecount;
	if (npages == 0)			/* no pages printed */
		return;
	if (npages < 0) {			/* odometer going backward?! */
		syslog(LOG_ERR, "page count went backward from %d to %d",
			initpagecount, finalpagecount);
		return;
	}
	af = fopen(acctfile, "a");
	if (!af) {
		syslog(LOG_ERR, "cannot append to accounting file %s: %m",
			acctfile);
		return;
	}
	fprintf(af, "%7.2f\t", (double) npages);
	if (host)
		fprintf(af, "%s:", host);
	fprintf(af, "%s\n", user);
	fclose(af);
}
