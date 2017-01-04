/*
 * lpd input filter for PostScript printers - converts plain text to
 * PostScript (by invoking txtps) and invokes lppsjf to send the PS job
 * to the printer.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 *
 * Input may be plain text or PostScript, sensed by checking the first two
 * bytes for '%!'.  The check relies on stdin being a file rather than a
 * pipe or socket.  If this filter is invoked with -c (i.e., lpr was
 * invoked with -l), the check is skipped and PS is forced.  This behaviour
 * was chosen since printing control characters is meaningless with txtps
 * and sending ready PS seems the most sensible interpretation of "send to
 * printer as is with control codes" in the PostScript environment.
 */

#ifndef lint
static char sccsid[] = "@(#)lppsif.c	5.2 (Berkeley) 8/21/04";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <stdio.h>
#include <strings.h>
#include <syslog.h>

extern int errno;
extern int optind;
extern char *optarg;

int literal, indent;
char *printer = "lp", *options, *width, *height, *prtitle;
char *user, *host, *acctfile;

main(argc, argv)
	char **argv;
{
	register int c;
	struct stat st;
	char idbytes[2];

	openlog("lppsif", LOG_PID, LOG_LPR);
	while ((c = getopt(argc, argv, "P:O:ci:w:l:x:y:n:h:p:")) > 0)
		switch (c) {
		case 'P':
			printer = optarg;
			continue;
		case 'O':
			options = optarg;
			continue;
		case 'c':
			literal = 1;
			continue;
		case 'i':
			indent = atoi(optarg);
			continue;
		case 'x':
			width = optarg;
			continue;
		case 'y':
			height = optarg;
			continue;
		case 'n':
			user = optarg;
			continue;
		case 'h':
			host = optarg;
			continue;
		case 'p':
			prtitle = optarg;
			continue;
		case '?':
			exit(2);
		}
	acctfile = argv[optind];
	if (!width || !height) {
		fputs("lppsif: must specify page size with -x and -y\n",
			stderr);
		exit(2);
	}
	if (prtitle && literal) {
		fputs("lppsif: -c and -p are mutually exclusive\n", stderr);
		exit(2);
	}
	if (prtitle)
		return(do_plaintext());
	if (literal)
		return(do_postscript());
	fstat(0, &st);
	if ((st.st_mode & S_IFMT) != S_IFREG)
		return(do_plaintext());
	lseek(0, 0L, L_SET);
	c = read(0, idbytes, 2);
	lseek(0, 0L, L_SET);
	if (c == 2 && idbytes[0] == '%' && idbytes[1] == '!')
		return(do_postscript());
	else
		return(do_plaintext());
}

do_plaintext()
{
	int p[2];
	register int i;
	int txtpid, jfpid;
	char *av[8], lm[8];
	register char **avp;
	union wait w;

	i = pipe(p);
	if (i < 0) {
		perror("pipe");
		exit(2);
	}
	/*
	 * Fork off two child processes for txtps and lppsjf, the parent waits
	 * to collect their exit status and report it back to lpd.
	 */
	i = vfork();
	if (i < 0) {
		perror("fork");
		exit(2);
	}
	if (i == 0) {		/* child: invoke txtps */
		dup2(p[1], 1);
		close(p[0]);
		close(p[1]);
		avp = av;
		*avp++ = "txtps";
		*avp++ = "-h";
		*avp++ = height;
		if (indent) {
			sprintf(lm, "%d", indent * 6);
			*avp++ = "-l";
			*avp++ = lm;
		}
		if (prtitle) {
			*avp++ = "-r";
			*avp++ = prtitle;
		}
		*avp = NULL;
		execv("/usr/ucb/txtps", av);
		perror("txtps");
		_exit(2);
	}
	txtpid = i;
	i = vfork();
	if (i < 0) {
		perror("fork");
		exit(2);
	}
	if (i == 0) {		/* child: invoke jppsjf */
		dup2(p[0], 0);
		close(p[0]);
		close(p[1]);
		do_postscript();
		/*NOTREACHED*/
	}
	jfpid = i;
	close(p[0]);
	close(p[1]);
	while ((i = wait(&w)) >= 0) {
		if (w.w_termsig)
			exit(2);
		if (!w.w_retcode)
			continue;
		if (i == txtpid)
			exit(2);
		if (i == jfpid)
			exit(w.w_retcode);
	}
	exit(0);
}

do_postscript()
{
	char *av[16];
	register char **avp;

	avp = av;
	*avp++ = "lppsjf";
	*avp++ = "-P";
	*avp++ = printer;
	if (options) {
		*avp++ = "-O";
		*avp++ = options;
	}
	*avp++ = "-x";
	*avp++ = width;
	*avp++ = "-y";
	*avp++ = height;
	if (user) {
		*avp++ = "-n";
		*avp++ = user;
	}
	if (host) {
		*avp++ = "-h";
		*avp++ = host;
	}
	if (acctfile)
		*avp++ = acctfile;
	*avp = NULL;
	execv("/usr/lib/lppsjf", av);
	perror("lppsjf");
	_exit(2);
}
