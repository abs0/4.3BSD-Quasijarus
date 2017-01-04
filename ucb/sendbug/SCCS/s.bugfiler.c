h06272
s 00010/00006/00134
d D 5.14 88/06/29 21:43:06 bostic 34 33
c install approved copyright notice
e
s 00014/00007/00126
d D 5.13 88/02/01 16:16:28 bostic 33 32
c add Berkeley specific header
e
s 00001/00000/00132
d D 5.12 87/09/29 10:31:43 bostic 32 31
c usage message to tty, just in case
e
s 00006/00003/00126
d D 5.11 87/07/21 11:35:48 bostic 31 30
c compress log file messages to single line
e
s 00004/00000/00125
d D 5.10 87/07/20 12:50:32 bostic 30 29
c create errors directory if DNE
e
s 00001/00001/00124
d D 5.9 87/04/23 16:43:54 bostic 29 26
c set permissions to 664
e
s 00001/00001/00124
d R 5.10 87/04/22 17:40:03 bostic 28 27
c I just can't think in octal...
e
s 00001/00001/00124
d R 5.9 87/04/22 17:30:15 bostic 27 26
c create files 644
e
s 00008/00008/00117
d D 5.8 87/04/11 15:48:06 bostic 26 25
c change -f flag to -v
e
s 00053/00057/00072
d D 5.7 87/04/11 15:38:38 bostic 25 24
c version #2; -f flag, remove home_dir, redist per folder
e
s 00078/00825/00051
d D 5.6 86/11/25 12:26:06 bostic 24 23
c remove MH dependencies; total rewrite
e
s 00010/00004/00866
d D 5.5 86/05/20 18:43:12 karels 23 22
c redist error stuff too, make folder if not there, add folder info
c to redistributed header
e
s 00005/00003/00865
d D 5.4 86/03/26 18:28:47 bloom 22 21
c  move the home back to ucbvax, clean up unixtomh handling
e
s 00000/00000/00868
d D 5.3 85/11/04 18:02:51 bloom 21 17
i 20
c merge from arpa development
e
s 00008/00009/00844
d D 4.15.2.1 85/11/04 17:55:59 bloom 20 18
c move unixtomh, redist instead of forward, prevent loops caused by mailing
c to myself
e
s 00011/00028/00841
d R 5.3 85/11/04 17:46:50 bloom 19 17
c move unixtomh, redist instead of forward, prevent loops caused by mailing myself
e
s 00000/00000/00853
d D 4.15.1.1 85/11/04 17:39:54 bloom 18 15
c branch-place-holder
e
s 00006/00002/00863
d D 5.2 85/08/09 18:09:37 kre 17 16
c allow cmd line -D args to override built in defaults for
c name & host address of bugs user - and alter defaults to new
c addressing format anyway.
e
s 00013/00001/00852
d D 5.1 85/06/06 08:58:59 dist 16 15
c Add copyright
e
s 00002/00001/00851
d D 4.15 84/05/17 11:56:34 ralph 15 14
c fix folder/128 file overwrite problem
e
s 00002/00002/00850
d D 4.14 84/03/12 11:40:45 ralph 14 13
c strip off '.' in addition to '/'
e
s 00026/00001/00826
d D 4.13 83/12/19 13:57:56 ralph 13 12
c don't send mail back to mailer daemon.
e
s 00002/00001/00825
d D 4.12 83/12/08 10:16:51 ralph 12 11
c fixes usage message and does setuid to bugperson.
e
s 00004/00008/00822
d D 4.11 83/09/14 14:46:51 ralph 11 10
c fixed subject in body only and Reply-To fields.
e
s 00001/00001/00829
d D 4.10 83/09/12 08:31:29 ralph 10 9
c made Repeat-By optional so more reports accepted.
e
s 00002/00008/00828
d D 4.9 83/08/27 12:36:38 sam 9 8
c sys/ stripping doesn't work, just leave go
e
s 00001/00000/00835
d D 4.8 83/08/23 13:55:39 karels 8 7
c fill in from line, sendmail gets confused
e
s 00000/00005/00835
d D 4.7 83/08/23 00:38:20 sam 7 6
c forgot to delete debugging stuff; also forgot to mention 
c that we now use sendmail because the deliver program's been expunged
e
s 00231/00022/00609
d D 4.6 83/08/23 00:37:08 sam 6 5
c add redistribution lists; fix bug where sys folder wasn't recognized
e
s 00002/00002/00629
d D 4.5 83/08/22 20:25:38 sam 5 4
c user contributed software resides in /usr/new, make pathnames correspond
e
s 00004/00001/00627
d D 4.4 83/08/11 22:41:06 sam 4 3
c standardize sccs keyword lines
e
s 00001/00001/00627
d D 4.3 83/08/05 09:57:51 karels 3 2
c needed %% in address (fprintf..4bsd-bugs%%ucbarpa)
e
s 00301/00133/00327
d D 4.2 83/05/23 15:59:14 ralph 2 1
c handles continuation lines & checks index line differently.
e
s 00460/00000/00000
d D 4.1 83/05/11 13:56:26 ralph 1 0
c date and time created 83/05/11 13:56:26 by ralph
e
u
U
f b 
t
T
I 16
/*
D 24
 * Copyright (c) 1983 Regents of the University of California.
E 24
I 24
D 33
 * Copyright (c) 1983, 1986 Regents of the University of California.
E 24
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 33
I 33
 * Copyright (c) 1983, 1986, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 34
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 34
I 34
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
E 34
E 33
 */

E 16
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
#ifndef lint
I 16
char copyright[] =
D 24
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 24
I 24
D 33
"%Z% Copyright (c) 1983, 1986 Regents of the University of California.\n\
E 33
I 33
"%Z% Copyright (c) 1983, 1986, 1987 Regents of the University of California.\n\
E 33
E 24
 All rights reserved.\n";
D 33
#endif not lint
E 33
I 33
#endif /* not lint */
E 33

#ifndef lint
E 16
D 17
static char sccsid[] = "%W% (Berkeley) %G%";
E 17
I 17
D 33
static char sccsid[] = "%W% (Berkeley) %E%";
E 17
D 16
#endif
E 16
I 16
#endif not lint
E 33
I 33
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
D 34

E 34
E 33
E 16

E 4
/*
D 24
 * Bug report processing program.
D 6
 * It is designed to be invoked by alias(5) and to be compatible with mh.
E 6
I 6
 * It is designed to be invoked by alias(5)
 * and to be compatible with mh.
E 24
I 24
 * Bug report processing program, designed to be invoked
 * through aliases(5).
E 24
E 6
 */
D 24

E 24
I 24
#include <bug.h>
#include <sys/time.h>
E 24
D 25
#include <stdio.h>
E 25
I 25
#include <sys/file.h>
E 25
D 24
#include <ctype.h>
#include <signal.h>
E 24
I 6
#include <pwd.h>
I 25
#include <stdio.h>
E 25

E 6
D 24
#include <sys/types.h>
#include <sys/stat.h>
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 24
I 24
D 25
extern char	*optarg;		/* getopt arguments */
extern int	optind;
E 24
E 2

I 17
D 24
#ifndef BUGS_NAME
E 17
D 5
char	deliver[] = "/usr/local/lib/mh/deliver";
char	unixtomh[] = "/usr/local/lib/mh/unixtomh";
E 5
I 5
D 6
char	deliver[] = "/usr/new/lib/mh/deliver";
E 6
I 6
#define	BUGS_NAME	"4bsd-bugs"
D 17
#define	BUGS_HOME	"%ucbarpa@BERKELEY"
E 17
I 17
#endif
#ifndef BUGS_HOME
D 22
#define	BUGS_HOME	"@ucbarpa.BERKELEY.EDU"
E 22
I 22
#define	BUGS_HOME	"@ucbvax.BERKELEY.EDU"
E 22
#endif
E 17
#define	MAILCMD		"/usr/lib/sendmail -i -t"
E 24
I 24
int	lfd;				/* lock file descriptor */
short	do_redist = YES;		/* redistribut BR */
E 25
char	bfr[MAXBSIZE],			/* general I/O buffer */
	tmpname[sizeof(TMP_BUG) + 5];	/* temp bug file */
E 24

E 6
D 20
char	unixtomh[] = "/usr/new/lib/mh/unixtomh";
E 20
I 20
D 22
char	unixtomh[] = "/ra/bugs/bin/unixtomh";
E 22
I 22
D 24
#ifndef UNIXTOMH
#define UNIXTOMH	"/usr/lib/unixtomh"
#endif
E 22
E 20
E 5
D 6
char	*maildir = "/ra/bugs/mail";
E 6
I 6
D 7
#ifdef notdef
E 7
char	*bugperson = "bugs";
char	*maildir = "mail";
D 7
#else
char	*bugperson = "sam";
char	*maildir = "Mail";
#endif
E 7
E 6
char	ackfile[] = ".ack";
char	errfile[] = ".format";
char	sumfile[] = "summary";
char	logfile[] = "errors/log";
I 6
char	redistfile[] = ".redist";
E 6
char	tmpname[] = "BfXXXXXX";
char	draft[] = "RpXXXXXX";
I 6
char	disttmp[] = "RcXXXXXX";
E 6

D 2
char	line[BUFSIZ];
E 2
I 2
char	buf[8192];
E 2
char	folder[MAXNAMLEN];
int	num;
D 23
int	msg_prot = 0664;
E 23
I 23
int	msg_prot = 0640;
int	folder_prot = 0750;
E 23

int	debug;

char	*index();
char	*rindex();
char	*fixaddr();
I 6
char	*any();
E 6

main(argc, argv)
	char *argv[];
E 24
I 24
D 25
main(argc,argv)
int	argc;
char	**argv;
E 25
I 25
main(argc, argv)
	int	argc;
	char	**argv;
E 25
E 24
{
I 25
	extern char	*optarg;	/* getopt arguments */
E 25
D 24
	register char *cp;
I 2
	register int n;
	int pfd[2];
E 24
I 24
	register struct passwd	*pwd;	/* bugs password entry */
	register int	ch;		/* getopts char */
D 25
	register short	do_ack = YES;	/* acknowledge bug report */
E 25
I 25
	int	do_ack,			/* acknowledge bug report */
		do_redist;		/* redistribut BR */
D 26
	char	*argfolder,		/* folder name provided */
E 26
I 26
	char	*argversion,		/* folder name provided */
E 26
		*strcpy();
E 25
	struct passwd	*getpwnam();
E 24
E 2

D 12
	if (argc > 3) {
E 12
I 12
D 24
	if (argc > 4) {
E 12
	usage:
D 2
		fprintf(stderr, "Usage: bugfiler [-d] [maildir]\n");
E 2
I 2
		fprintf(stderr, "Usage: bugfiler [-d] [-mmsg_mode] [maildir]\n");
E 2
		exit(1);
	}
	while (--argc > 0) {
		cp = *++argv;
D 2
		if (*cp == '-') while (*++cp)
			switch (*cp) {
E 2
I 2
		if (*cp == '-')
			switch (cp[1]) {
E 2
			case 'd':
				debug++;
E 24
I 24
D 25
	while ((ch = getopt(argc,argv,"ar")) != EOF)
E 25
I 25
	do_ack = do_redist = YES;
D 26
	argfolder = NULL;
	while ((ch = getopt(argc, argv, "af:r")) != EOF)
E 26
I 26
	argversion = NULL;
	while ((ch = getopt(argc, argv, "av:r")) != EOF)
E 26
E 25
		switch((char)ch) {
D 25
			case 'a':
				do_ack = NO;
E 24
				break;
I 2
D 24

			case 'm':	/* set message protection */
				n = 0;
				for (cp += 2; *cp >= '0' && *cp <= '7'; )
					n = (n << 3) + (*cp++ - '0');
				msg_prot = n & 0777;
E 24
I 24
			case 'r':
				do_redist = NO;
E 24
				break;
D 24

E 24
I 24
			case '?':
E 24
E 2
			default:
D 24
				goto usage;
			}
		else
			maildir = cp;
	}
I 2
	if (!debug)
		freopen(logfile, "a", stderr);

I 6
	if (bugperson) {
		struct passwd *pwd = getpwnam(bugperson);

		if (pwd == NULL) {
			fprintf(stderr, "%s: bugs person is unknown\n",
			    bugperson);
			exit(1);
E 24
I 24
				error("usage: bugfiler [-ar] [maildir]",CHN);
E 25
I 25
		case 'a':
			do_ack = NO;
			break;
D 26
		case 'f':
			argfolder = optarg;
E 26
I 26
		case 'v':
			argversion = optarg;
E 26
			break;
		case 'r':
			do_redist = NO;
			break;
		case '?':
		default:
I 32
			fputs("usage: bugfiler [-ar] [-v version]\n", stderr);
E 32
D 26
			error("usage: bugfiler [-ar] [-f folder]", CHN);
E 26
I 26
			error("usage: bugfiler [-ar] [-v version]", CHN);
E 26
E 25
E 24
		}
D 24
		if (chdir(pwd->pw_dir) < 0) {
			fprintf(stderr, "can't chdir to %s\n", pwd->pw_dir);
			exit(1);
		}
I 12
		setuid(pwd->pw_uid);
E 12
	}
E 6
E 2
	if (chdir(maildir) < 0) {
		fprintf(stderr, "can't chdir to %s\n", maildir);
		exit(1);
	}
D 2
	if (freopen(logfile, "a", stderr) == NULL)
		freopen("/dev/null", "w", stderr);
	exit(process());
E 2
I 2
	umask(0);
E 24

D 24
#ifdef UNIXCOMP
	/*
	 * Convert UNIX style mail to mh style by filtering stdin through
	 * unixtomh.
	 */
	if (pipe(pfd) >= 0) {
		while ((n = fork()) == -1)
			sleep(5);
		if (n == 0) {
			close(pfd[0]);
			dup2(pfd[1], 1);
			close(pfd[1]);
D 22
			execl(unixtomh, "unixtomh", 0);
E 22
I 22
			execl(UNIXTOMH, "unixtomh", 0);
E 22
			_exit(127);
		}
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
	}
#endif
	while (process())
		;
	exit(0);
E 2
}
E 24
I 24
	if (!(pwd = getpwnam(BUGS_ID)))
D 25
		error("bugs person %s is unknown",BUGS_ID);
E 25
I 25
		error("can't find bugs login.", BUGS_ID);
E 25
E 24

I 2
D 24
/* states */
E 24
I 24
D 25
	argv += optind;
	if (*argv) {		/* change to argument directory */
		if (chdir(*argv))
			error("can't move to %s.",*argv);
	}			/* change to bugs home directory */
	else if (chdir(pwd->pw_dir))
		error("can't move to %s.",pwd->pw_dir);
E 25
I 25
	if (chdir(pwd->pw_dir))		/* change to bugs home directory */
		error("can't chdir to %s.", pwd->pw_dir);
E 25
E 24

D 24
#define EOM	0	/* End of message seen */
#define FLD	1	/* Looking for header lines */
#define BODY	2	/* Looking for message body lines */
E 24
I 24
D 25
	if (setreuid(0,pwd->pw_uid))
		error("can't set id to %s.",BUGS_ID);
E 25
I 25
	if (setreuid(0, pwd->pw_uid))
		error("can't set id to %s.", BUGS_ID);
E 25
E 24

E 2
D 24
/* defines used for tag attributes */
E 24
I 24
D 25
	umask(2);		/* everything is 664 */
	seterr();
	logit();
	make_copy();
E 25
I 25
D 29
	(void)umask(2);			/* everything is 664 */
E 29
I 29
	(void)umask(02);		/* everything is 664 */
E 29
	seterr();			/* redirect to log file */
	logit();			/* log report arrival */
	make_copy();			/* save copy in case */
	gethead(do_redist);
E 25
E 24

D 24
#define H_REQ 01
D 2
#define H_OPT 02
#define H_SAV 04
E 2
I 2
#define H_SAV 02
#define H_HDR 04
#define H_FND 010
E 24
I 24
D 25
	if (access(LOCK_FILE,R_OK) || (lfd = open(LOCK_FILE,O_RDONLY,0)) < 0)
		error("can't read lock file %s.",LOCK_FILE);
E 25
I 25
D 26
	if (argfolder)			/* specific folder requested */
		(void)strcpy(dir, argfolder);
E 26
I 26
	if (argversion)			/* specific folder requested */
		(void)strcpy(dir, argversion);
E 26
E 25
E 24
E 2

I 13
D 24
#define FROM &headers[0]
E 13
#define FROM_I headers[0].h_info
#define SUBJECT_I headers[1].h_info
#define INDEX &headers[2]
#define INDEX_I headers[2].h_info
#define DATE_I headers[3].h_info
#define MSGID_I headers[4].h_info
#define REPLYTO_I headers[5].h_info
D 11
#define RETURNPATH_I headers[6].h_info
#define TO_I headers[7].h_info
#define CC_I headers[8].h_info
#define FIX headers[11]
E 11
I 11
#define TO_I headers[6].h_info
#define CC_I headers[7].h_info
#define FIX headers[10]
E 24
I 24
D 25
	gethead();
E 25
	process();
E 24
E 11

D 24
struct header {
	char	*h_tag;
	int	h_flags;
	char	*h_info;
} headers[] = {
D 2
	"From",		H_REQ|H_SAV, 0,
	"Subject",	H_REQ|H_SAV, 0,
E 2
I 2
	"From",		H_REQ|H_SAV|H_HDR, 0,
D 11
	"Subject",	H_REQ|H_SAV|H_HDR, 0,
E 11
I 11
	"Subject",	H_REQ|H_SAV, 0,
E 11
E 2
	"Index",	H_REQ|H_SAV, 0,
D 2
	"Date",		H_OPT|H_SAV, 0,
	"Message-Id",	H_OPT|H_SAV, 0,
	"Reply-To",	H_OPT|H_SAV, 0,
	"Return-Path",	H_OPT|H_SAV, 0,
	"To",		H_OPT|H_SAV, 0,
	"Cc",		H_OPT|H_SAV, 0,
E 2
I 2
	"Date",		H_SAV|H_HDR, 0,
	"Message-Id",	H_SAV|H_HDR, 0,
	"Reply-To",	H_SAV|H_HDR, 0,
D 11
	"Return-Path",	H_SAV|H_HDR, 0,
E 11
	"To",		H_SAV|H_HDR, 0,
	"Cc",		H_SAV|H_HDR, 0,
E 2
	"Description",	H_REQ,       0,
D 10
	"Repeat-By",	H_REQ,	     0,
E 10
I 10
	"Repeat-By",	0,	     0,
E 10
D 2
	"Fix",		H_OPT,	     0,
E 2
I 2
	"Fix",		0,	     0,
E 2
	0,	0,	0,
};
E 24
I 24
D 25
	if (setuid(0,0))
		error("can't set id to root.",CHN);
E 24

E 25
I 25
	if (setuid(0, 0))
		error("can't set id to root.", CHN);
E 25
I 2
D 24
struct header *findheader();
E 24
I 24
	if (do_ack)
		reply();
	if (do_redist)
		redist();
E 24
D 25

E 2
D 24
process()
{
	register struct header *hp;
	register char *cp;
I 2
	register int c;
E 2
	char *info;
D 2
	int tmp, pfd[2];
	FILE *fs;
E 2
I 2
D 13
	int state, tmp;
E 13
I 13
	int state, tmp, no_reply = 0;
E 13
	FILE *tfp, *fs;
E 2

	/*
	 * Insure all headers are in a consistent
	 * state.  Anything left there is free'd.
	 */
	for (hp = headers; hp->h_tag; hp++) {
I 2
		hp->h_flags &= ~H_FND;
E 2
		if (hp->h_info) {
D 2
			if (hp->h_info != (char *) 1)
				free(hp->h_info);
E 2
I 2
			free(hp->h_info);
E 2
			hp->h_info = 0;
		}
	}
D 2
#ifdef UNIXCOMP
E 2
	/*
D 2
	 * Convert UNIX style mail to mh style by filtering stdin through
	 * unixtomh.
	 */
	if (pipe(pfd) >= 0) {
		register int n;

		while ((n = fork()) == -1)
			sleep(5);
		if (n == 0) {
			close(pfd[0]);
			dup2(pfd[1], 1);
			close(pfd[1]);
			execl(unixtomh, "unixtomh", 0);
			_exit(127);
		}
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
	}
#endif
	/*
E 2
	 * Read the report and make a copy.  Must conform to RFC822 and
	 * be of the form... <tag>: <info>
I 2
	 * Note that the input is expected to be in mh mail format
	 * (i.e., messages are separated by lines of ^A's).
E 2
	 */
I 2
	while ((c = getchar()) == '\001' && peekc(stdin) == '\001')
		while (getchar() != '\n')
			;
	if (c == EOF)
		return(0);	/* all done */

E 2
	mktemp(tmpname);
D 2
	if ((tmp = creat(tmpname, msg_prot)) < 0)
		return(1);
	while ((cp = fgets(line, sizeof(line), stdin)) != NULL) {
		if (line[0] == '\01')
			continue;
		write(tmp, cp, strlen(cp));
		cp = index(cp, ':');
		if (cp == 0)
			continue;
		*cp++ = '\0';
		for (hp = headers; hp->h_tag; hp++)
			if (streq(hp->h_tag, line))
				break;
		if (hp->h_tag == 0)
			continue;
		if (!(hp->h_flags & H_SAV)) {
			hp->h_info = (char *) 1;
			continue;
E 2
I 2
	if ((tmp = creat(tmpname, msg_prot)) < 0) {
D 23
		fprintf(stderr, "cannont create %s\n", tmpname);
E 23
I 23
		fprintf(stderr, "cannot create %s\n", tmpname);
E 23
		exit(1);
	}
	if ((tfp = fdopen(tmp, "w")) == NULL) {
		fprintf(stderr, "cannot fdopen temp file\n");
		exit(1);
	}

	for (state = FLD; state != EOF && state != EOM; c = getchar()) {
		switch (state) {
		case FLD:
			if (c == '\n' || c == '-')
				goto body;
			for (cp = buf; c != ':'; c = getchar()) {
				if (cp < buf+sizeof(buf)-1 && c != '\n' && c != EOF) {
					*cp++ = c;
					continue;
				}
				*cp = '\0';
				fputs(buf, tfp);
				state = EOF;
				while (c != EOF) {
					if (c == '\n')
						if ((tmp = peekc(stdin)) == EOF)
							break;
						else if (tmp == '\001') {
							state = EOM;
							break;
						}
					putc(c, tfp);
					c = getchar();
				}
				fclose(tfp);
				goto badfmt;
			}
			*cp = '\0';
			fprintf(tfp, "%s:", buf);
			hp = findheader(buf, state);

			for (cp = buf; ; ) {
				if (cp >= buf+sizeof(buf)-1) {
					fprintf(stderr, "field truncated\n");
					while ((c = getchar()) != EOF && c != '\n')
						putc(c, tfp);
				}
				if ((c = getchar()) == EOF) {
					state = EOF;
					break;
				}
				putc(c, tfp);
				*cp++ = c;
				if (c == '\n')
					if ((c = peekc(stdin)) != ' ' && c != '\t') {
						if (c == EOF)
							state = EOF;
						else if (c == '\001')
							state = EOM;
						break;
					}
			}
			*cp = '\0';
			cp = buf;
			break;

		body:
			state = BODY;
		case BODY:
			for (cp = buf; ; c = getchar()) {
				if (c == EOF) {
					state = EOF;
					break;
				}
				if (c == '\001' && peekc(stdin) == '\001') {
					state = EOM;
					break;
				}
				putc(c, tfp);
				*cp++ = c;
				if (cp >= buf+sizeof(buf)-1 || c == '\n')
					break;
			}
			*cp = '\0';
			if ((cp = index(buf, ':')) == NULL)
				continue;
			*cp++ = '\0';
			hp = findheader(buf, state);
E 2
		}
I 2

		/*
		 * Don't save the info if the header wasn't found, we don't
		 * care about the info, or the header is repeated.
		 */
		if (hp == NULL || !(hp->h_flags & H_SAV) || hp->h_info)
			continue;
E 2
		while (isspace(*cp))
			cp++;
		if (*cp) {
			info = cp;
			while (*cp++);
			cp--;
			while (isspace(cp[-1]))
				*--cp = '\0';
			hp->h_info = (char *) malloc(strlen(info) + 1);
D 2
			if (hp->h_info == NULL)
E 2
I 2
			if (hp->h_info == NULL) {
				fprintf(stderr, "ran out of memory\n");
E 2
				continue;
I 2
			}
E 2
			strcpy(hp->h_info, info);
I 13
			if (hp == FROM && chkfrom(hp) < 0)
				no_reply = 1;
E 13
			if (hp == INDEX)
				chkindex(hp);
		}
	}
D 2
	close(tmp);
E 2
I 2
	fclose(tfp);
I 13
	if (no_reply) {
		unlink(tmpname);
		exit(0);
	}
E 13
E 2
	/*
	 * Verify all the required pieces of information
	 * are present.
	 */
D 2
	for (hp = headers; hp->h_tag; hp++)
		if ((hp->h_flags & H_REQ) && !hp->h_info)
			break;
	if (hp->h_tag) {
E 2
I 2
	for (hp = headers; hp->h_tag; hp++) {
E 2
		/*
		 * Mail the bug report back to the sender with a note
		 * explaining they must conform to the specification.
		 */
D 2
		if (debug)
			fprintf(stderr, "Missing %s\n", hp->h_tag);
		reply(FROM_I, errfile, tmpname);
		file(tmpname, "errors");
		return(0);
E 2
I 2
		if ((hp->h_flags & H_REQ) && !(hp->h_flags & H_FND)) {
			if (debug)
				printf("Missing %s\n", hp->h_tag);
		badfmt:
			reply(FROM_I, errfile, tmpname);
			file(tmpname, "errors");
I 23
			redistribute("errors", num);
E 23
			return(state == EOM);
		}
E 2
	}
D 2
	else {	/* Acknowledge receipt */
		reply(FROM_I, ackfile, (char *)0);
		file(tmpname, folder);
	}
E 2
	/*
I 2
	 * Acknowledge receipt.
	 */
	reply(FROM_I, ackfile, (char *)0);
	file(tmpname, folder);
	/*
E 2
	 * Append information about the new bug report
	 * to the summary file.
	 */
D 2
	if ((fs = fopen(sumfile, "a")) == NULL) {
E 2
I 2
	if ((fs = fopen(sumfile, "a")) == NULL)
E 2
		fprintf(stderr, "Can't open %s\n", sumfile);
D 2
		return(1);
E 2
I 2
	else {
		fprintf(fs, "%14.14s/%-3d  ", folder, num);
		fprintf(fs, "%-51.51s Recv\n", INDEX_I);
		fprintf(fs, "\t\t    %-51.51s\n", SUBJECT_I);
E 2
	}
D 2
	fprintf(fs, "%14.14s/%-3d  %s\n\t\t    %s\n", folder, num, INDEX_I, SUBJECT_I);
E 2
	fclose(fs);
I 6
	/*
	 * Check redistribution list and, if members,
	 * mail a copy of the bug report to these people.
	 */
	redistribute(folder, num);
E 6
D 2
	return(0);
E 2
I 2
	return(state == EOM);
E 24
I 24
	unlink(tmpname);
E 25
I 25
	(void)unlink(tmpname);
E 25
	exit(OK);
E 24
E 2
}

/*
I 2
D 24
 * Lookup the string in the list of headers and return a pointer
 * to the entry or NULL.
E 24
I 24
 * make_copy --
D 25
 *	make a copy of the bug report
E 25
I 25
 *	make a copy of bug report in error folder
E 25
E 24
 */
D 24

struct header *
findheader(name, state)
	char *name;
	int state;
E 24
I 24
static
make_copy()
E 24
{
D 24
	register struct header *hp;
E 24
I 24
	register int	cnt,			/* read return value */
			tfd;			/* temp file descriptor */
D 25
	char	*mktemp(), *strcpy();
E 25
I 25
	char	*strcpy();
E 25
E 24

I 30
	if (access(TMP_DIR, F_OK)) {
		(void)mkdir(TMP_DIR);
		(void)chmod(TMP_DIR, 0775);
	}
E 30
D 24
	if (debug)
		printf("findheader(%s, %d)\n", name, state);

	for (hp = headers; hp->h_tag; hp++) {
		if (!streq(hp->h_tag, buf))
			continue;
		if ((hp->h_flags & H_HDR) && state != FLD)
			continue;
		hp->h_flags |= H_FND;
		return(hp);
	}
	return(NULL);
I 13
}

/*
 * Check the FROM line to eliminate loops.
 */

chkfrom(hp)
	struct header *hp;
{
	register char *cp1, *cp2;
	register char c;

	if (debug)
D 20
		printf("chkindex(%s)\n", hp->h_info);
E 20
I 20
		printf("chkfrom(%s)\n", hp->h_info);
E 20

I 20
	if (substr(hp->h_info, BUGS_NAME))
		return(-1);
E 20
	if (substr(hp->h_info, "MAILER-DAEMON"))
		return(-1);
	return(0);
E 13
}

/*
E 2
 * Check the format of the Index information.
 * A side effect is to set the name of the folder if all is well.
 */

chkindex(hp)
	struct header *hp;
{
D 2
	register char *cp1, *cp2, *cp3, *cp4;
E 2
I 2
	register char *cp1, *cp2;
E 2
	register char c;
	struct stat stbuf;

	if (debug)
D 2
		fprintf(stderr, "chkindex(%s)\n", hp->h_info);
E 2
I 2
		printf("chkindex(%s)\n", hp->h_info);
E 2
	/*
I 2
D 9
	 * Strip of leading "/", "usr/", "src/" or "sys/".
E 9
I 9
D 14
	 * Strip of leading "/", "usr/", or "src/".
E 14
I 14
	 * Strip of leading "/", ".", "usr/", or "src/".
E 14
E 9
	 */
	cp1 = hp->h_info;
D 14
	while (*cp1 == '/')
E 14
I 14
	while (*cp1 == '/' || *cp1 == '.')
E 14
		cp1++;
D 9
	while (substr(cp1, "usr/") || substr(cp1, "src/") || substr(cp1, "sys/"))
E 9
I 9
	while (substr(cp1, "usr/") || substr(cp1, "src/"))
E 9
		cp1 += 4;
I 6
D 9
	/* 
	 * Don't toss "sys/" if nothing else is given for
	 * a folder name, this is a valid folder as well.
	 */
	if (index(cp1, '/') == NULL && substr(cp1 - 4, "sys/"))
		cp1 -= 4;
E 9
E 6
	/*
E 2
	 * Read the folder name and remove it from the index line.
	 */
D 2
	for (cp1 = hp->h_info, cp2 = NULL, cp3 = folder, cp4 == NULL; ;) {
		c = *cp1++;
		if (c == '\0' || isspace(c) || cp3 >= folder+sizeof(folder)-1) {
			if (cp4 == NULL)
				*cp3 = '\0';
			else
				*cp4 = '\0';
			if (cp2 == NULL) {
				cp2 = cp1 - 1;
				while (isspace(*cp2))
					cp2++;
			}
			for (cp3 = hp->h_info; *cp3++ = *cp2++; );
E 2
I 2
	for (cp2 = folder; ;) {
		switch (c = *cp1++) {
		case '/':
			if (cp2 == folder)
				continue;
E 2
			break;
D 2
		} else {
			if (c == '/') {
				cp2 = cp1;
				cp4 = cp3;
			}
			*cp3++ = c;
E 2
I 2
		case '\0':
			cp1--;
			break;
		case ' ':
		case '\t':
			while (isspace(*cp1))
				cp1++;
			break;
		default:
			if (cp2 < folder+sizeof(folder)-1)
				*cp2++ = c;
			continue;
E 2
		}
I 2
		*cp2 = '\0';
		for (cp2 = hp->h_info; *cp2++ = *cp1++; )
			;
		break;
E 2
	}
I 2
	if (debug)
		printf("folder = %s\n", folder);
E 2
	/*
D 2
	 * Check to see if a Fix is included.
	if ((cp1 = rindex(hp->h_info, ' ')) == NULL) {
		if ((cp1 = rindex(hp->h_info, '\t')) != NULL)
			cp1++;
	} else
		cp1++;
	if (cp1 != NULL && streq(cp1, FIX.h_tag))
		FIX.h_flags = H_REQ;
	else
		FIX.h_flags = 0;
	 */
	/*
E 2
	 * Check to make sure we have a valid folder name
	 */
	if (stat(folder, &stbuf) == 0 && (stbuf.st_mode & S_IFMT) == S_IFDIR)
		return;
	/*
	 * The Index line is not in the correct format so clear
D 2
	 * the h_info line to mail back the correct format.
E 2
I 2
	 * the H_FND flag to mail back the correct format.
E 2
	 */
D 2
	hp->h_info = 0;
E 2
I 2
	hp->h_flags &= ~H_FND;
E 2
}

/*
 * Move or copy the file msg to the folder (directory).
D 6
 * A side effect is to set num to the number of the file in folder.
E 6
I 6
 * As a side effect, num is set to the number under which
 * the message is filed in folder.
E 6
 */

file(fname, folder)
	char *fname, *folder;
{
D 15
	register char *cp, n;
E 15
I 15
	register char *cp;
	register int n;
E 15
	char msgname[MAXNAMLEN*2+2];
	struct stat stbuf;
	DIR *dirp;
	struct direct *d;

	if (debug)
D 2
		fprintf(stderr, "file(%s, %s)\n", fname, folder);
E 2
I 2
		printf("file(%s, %s)\n", fname, folder);
E 2
	/*
	 * Get the next number to use by finding the last message number
	 * in folder and adding one.
	 */
	if ((dirp = opendir(folder)) == NULL) {
D 23
		fprintf(stderr, "Cannot open %s/%s\n", maildir, folder);
		return;
E 23
I 23
		(void) mkdir(folder, folder_prot);
		if ((dirp = opendir(folder)) == NULL) {
			fprintf(stderr, "Cannot open %s/%s\n", maildir, folder);
E 24
I 24
D 25
	/* use O_EXCL, since may not be able to get a lock file */
	for (cnt = 0;cnt < 20;++cnt)
		if ((tfd = open(mktemp(strcpy(tmpname,TMP_BUG)),O_WRONLY | O_CREAT | O_EXCL,0664)) >= 0) {
			while ((cnt = read(fileno(stdin),bfr,sizeof(bfr))) != ERR && cnt)
				write(tfd,bfr,cnt);
			close(tfd);
E 24
			return;
		}
E 23
D 24
	}
	num = 0;
	while ((d = readdir(dirp)) != NULL) {
		cp = d->d_name;
		n = 0;
		while (isdigit(*cp))
			n = n * 10 + (*cp++ - '0');
		if (*cp == '\0' && n > num)
			num = n;
	}
	closedir(dirp);
	num++;
	/*
	 * Create the destination file "folder/num" and copy fname to it.
	 */
	sprintf(msgname, "%s/%d", folder, num);
	if (link(fname, msgname) < 0) {
		int fin, fout;

D 2
		if ((fin = open(fname, 0)) < 0)
E 2
I 2
		if ((fin = open(fname, 0)) < 0) {
			fprintf(stderr, "cannot open %s\n", fname);
E 2
			return;
D 2
		if ((fout = open(msgname, 1)) < 0)
E 2
I 2
		}
		if ((fout = creat(msgname, msg_prot)) < 0) {
			fprintf(stderr, "cannot create %s\n", msgname);
E 2
			return;
D 2
		while ((n = read(fin, line, sizeof(line))) > 0)
			write(fout, line, n);
E 2
I 2
		}
		while ((n = read(fin, buf, sizeof(buf))) > 0)
			write(fout, buf, n);
E 2
		close(fin);
		close(fout);
	}
	unlink(fname);
E 24
I 24
	error("unable to make copy using %s.\n",tmpname);
E 25
I 25
	(void)strcpy(tmpname, TMP_BUG);
	if (tfd = mkstemp(tmpname)) {
		while ((cnt = read(fileno(stdin), bfr, sizeof(bfr))) != ERR && cnt)
			write(tfd, bfr, cnt);
		(void)close(tfd);
		return;
	}
D 31
	error("can't make copy using %s.\n", tmpname);
E 31
I 31
	error("can't make copy using %s.", tmpname);
E 31
E 25
E 24
}

/*
I 6
D 24
 * Redistribute a bug report to those people indicated
 * in the redistribution list file.  Perhaps should also
 * annotate bug report with this information for future
 * reference?
E 24
I 24
 * logit --
 *	log this run of the bugfiler
E 24
 */
D 24
redistribute(folder, num)
	char *folder;
	int num;
E 24
I 24
static
logit()
E 24
{
D 24
	FILE *fredist, *fbug, *ftemp;
	char line[BUFSIZ], bug[2 * MAXNAMLEN + 1];
	register char *cp;
	int redistcnt, continuation, first;
E 24
I 24
	struct timeval	tp;
D 25
	struct timezone	tzp;
E 25
D 31
	char	*ctime();
E 31
I 31
	char	*C1, *C2,
		*ctime();
E 31
E 24

D 24
	fredist = fopen(redistfile, "r");
	if (fredist == NULL) {
		if (debug)
			printf("redistribute(%s, %d), no distribution list\n",
			    folder, num);
		return;
	}
	continuation = 0;
	first = 1;
	redistcnt = 0;
	while (fgets(line, sizeof (line) - 1, fredist) != NULL) {
		if (debug)
			printf("%s: %s", redistfile, line);
		if (continuation && index(line, '\\'))
			continue;
		continuation = 0;
		cp = any(line, " \t");
		if (cp == NULL)
			continue;
		*cp++ = '\0';
		if (strcmp(folder, line) == 0)
			goto found;
		if (index(cp, '\\'))
			continuation = 1;
	}
	if (debug)
		printf("no redistribution list found\n");
	fclose(fredist);
	return;
found:
	mktemp(disttmp);
	ftemp = fopen(disttmp, "w+r");
	if (ftemp == NULL) {
		if (debug)
			printf("%s: couldn't create\n", disttmp);
		return;
	}
again:
	if (debug)
		printf("redistribution list %s", cp);
	while (cp) {
		char *user, terminator;

		while (*cp && (*cp == ' ' || *cp == '\t' || *cp == ','))
			cp++;
		user = cp, cp = any(cp, ", \t\n\\");
		if (cp) {
			terminator = *cp;
			*cp++ = '\0';
			if (terminator == '\n')
				cp = 0;
			if (terminator == '\\')
				continuation++;
		}
		if (*user == '\0')
			continue;
		if (debug)
			printf("copy to %s\n", user);
		if (first) {
D 20
			fprintf(ftemp, "To: %s", user);
E 20
I 20
			fprintf(ftemp, "Resent-To: %s", user);
E 20
			first = 0;
		} else
			fprintf(ftemp, ", %s", user);
		redistcnt++;
	}
	if (!first)
		putc('\n', ftemp);
	if (continuation) {
		first = 1;
		continuation = 0;
		cp = line;
		if (fgets(line, sizeof (line) - 1, fredist))
			goto again;
	}
	fclose(fredist);
	if (redistcnt == 0)
		goto cleanup;
D 20
	fprintf(ftemp, "Subject: ");
	if (SUBJECT_I)
		fprintf(ftemp, "%s\n", SUBJECT_I);
	else
E 20
I 20
	if (! SUBJECT_I) {
		fprintf(ftemp, "Subject: ");
E 20
		fprintf(ftemp, "Untitled bug report\n");
D 20
	fprintf(ftemp, "\nRedistributed-by: %s%s\n", BUGS_NAME, BUGS_HOME);
E 20
I 20
	}
I 23
	fprintf(ftemp, "Folder: %s/%d\n", folder, num);
E 23
E 20
	/*
	 * Create copy of bug report.  Perhaps we should
	 * truncate large messages and just give people
	 * a pointer to the original?
	 */
	sprintf(bug, "%s/%d", folder, num);
	fbug = fopen(bug, "r");
	if (fbug == NULL) {
		if (debug)
			printf("%s: disappeared?\n", bug);
		goto cleanup;
	}
	first = 1;
	while (fgets(line, sizeof (line) - 1, fbug)) {
		/* first blank line indicates start of mesg */
		if (first && line[0] == '\n') {
			first = 0;
D 20
			continue;
E 20
		}
		fputs(line, ftemp);
	}
	fclose(fbug);
	if (first) {
		if (debug)
			printf("empty bug report?\n");
		goto cleanup;
	}
	if (dodeliver(ftemp))
		unlink(disttmp);
	fclose(ftemp);
	return;
cleanup:
	fclose(ftemp);
	unlink(disttmp);
}

dodeliver(fd)
	FILE *fd;
{
	char buf[BUFSIZ], cmd[BUFSIZ];
	FILE *pf, *popen();

	strcpy(cmd, MAILCMD);
	if (debug) {
		strcat(cmd, " -v");
		printf("dodeliver \"%s\"\n", cmd);
	}
	pf = popen(cmd, "w");
	if (pf == NULL) {
		if (debug)
			printf("dodeliver, \"%s\" failed\n", cmd);
		return (0);
	}
	rewind(fd);
	while (fgets(buf, sizeof (buf) - 1, fd)) {
		if (debug)
			printf("%s", buf);
		(void) fputs(buf, pf);
	}
	if (debug)
		printf("EOF\n");
	(void) pclose(pf);
	return (1);
}

/*
E 6
 * Mail file1 and file2 back to the sender.
 */

reply(to, file1, file2)
	char	*to, *file1, *file2;
{
D 6
	int (*istat)(), (*qstat)();
	int pid, w, status, pfd[2], in;
E 6
I 6
	int pfd[2], in, w;
E 6
	FILE *fout;

	if (debug)
D 2
		fprintf(stderr, "reply(%s, %s, %s)\n", to, file1, file2);
E 2
I 2
		printf("reply(%s, %s, %s)\n", to, file1, file2);

E 2
	/*
	 * Create a temporary file to put the message in.
	 */
	mktemp(draft);
D 6
	if ((fout = fopen(draft, "w")) == NULL) {
E 6
I 6
	if ((fout = fopen(draft, "w+r")) == NULL) {
E 6
		fprintf(stderr, "Can't create %s\n", draft);
		return;
	}
	/*
	 * Output the proper header information.
	 */
D 2
	fprintf(fout, "Reply-To: 4bsd-bugs@BERKELEY\n");
E 2
I 2
D 3
	fprintf(fout, "Reply-To: 4bsd-bugs%ucbarpa@BERKELEY\n");
E 3
I 3
D 6
	fprintf(fout, "Reply-To: 4bsd-bugs%%ucbarpa@BERKELEY\n");
E 6
I 6
	fprintf(fout, "Reply-To: %s%s\n", BUGS_NAME, BUGS_HOME);
I 8
	fprintf(fout, "From: %s%s (Bugs Bunny)\n", BUGS_NAME, BUGS_HOME);
E 8
E 6
E 3
E 2
D 11
	if (RETURNPATH_I != NULL)
		to = RETURNPATH_I;
E 11
	if (REPLYTO_I != NULL)
		to = REPLYTO_I;
	if ((to = fixaddr(to)) == 0) {
		fprintf(stderr, "No one to reply to\n");
		return;
	}
	fprintf(fout, "To: %s\n", to);
	if (SUBJECT_I) {
		fprintf(fout, "Subject: ");
		if ((SUBJECT_I[0] != 'R' && SUBJECT_I[0] != 'r') ||
		    (SUBJECT_I[1] != 'E' && SUBJECT_I[1] != 'e') ||
		    SUBJECT_I[2] != ':')
			fprintf(fout, "Re: ");
		fprintf(fout, "%s\n", SUBJECT_I);
	}
	if (DATE_I) {
		fprintf(fout, "In-Acknowledgement-Of: Your message of ");
		fprintf(fout, "%s.\n", DATE_I);
		if (MSGID_I)
			fprintf(fout, "             %s\n", MSGID_I);
	}
D 6
	fprintf(fout, "----------\n");
E 6
I 6
	fprintf(fout, "\n");
E 6
	if ((in = open(file1, 0)) >= 0) {
D 2
		while ((w = read(in, line, sizeof(line))) > 0)
			fwrite(line, 1, w, fout);
E 2
I 2
		while ((w = read(in, buf, sizeof(buf))) > 0)
			fwrite(buf, 1, w, fout);
E 2
		close(in);
	}
	if (file2 && (in = open(file2, 0)) >= 0) {
D 2
		while ((w = read(in, line, sizeof(line))) > 0)
			fwrite(line, 1, w, fout);
E 2
I 2
		while ((w = read(in, buf, sizeof(buf))) > 0)
			fwrite(buf, 1, w, fout);
E 2
		close(in);
	}
D 6
	fclose(fout);
	while ((pid = fork()) == -1)
		sleep(5);
	if (pid == 0) {
		execl(deliver, "deliver", draft, 0);
		_exit(127);
	}
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	while ((w = wait(&status)) != -1 && w != pid);
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	if (w != -1 && status == 0)
E 6
I 6
	if (dodeliver(fout))
E 6
		unlink(draft);
I 6
	fclose(fout);
E 6
}

/*
 * fix names like "xxx (something)" to "xxx" and
 * "xxx <something>" to "something".
 */

char *
fixaddr(text)
	char *text;
{
	register char *cp, *lp, c;
	char *tp;

	if (!text)
		return(0);
	for (lp = cp = text; ; ) {
		switch (c = *cp++) {
		case '(':
			while (*cp && *cp++ != ')');
			continue;
		case '<':
			lp = text;
		case '>':
			continue;
		case '\0':
			while (lp != text && (*lp == ' ' || *lp == '\t'))
				lp--;
			*lp = c;
			return(text);
		}
		*lp++ = c;
	}
}

/*
 * Compare two strings and convert any upper case letters to lower case.
 */

D 2
streq(c1, c2)
	register char *c1, *c2;
E 2
I 2
streq(s1, s2)
	register char *s1, *s2;
E 2
{
	register int c;

D 2
	while (c = *c1++)
		if ((c | 040) != (*c2++ | 040))
E 2
I 2
	while (c = *s1++)
		if ((c | 040) != (*s2++ | 040))
E 2
			return(0);
D 2
	return(*c2 == '\0');
E 2
I 2
	return(*s2 == '\0');
}

/*
 * Return true if string s2 matches the first part of s1.
 */

substr(s1, s2)
	register char *s1, *s2;
{
	register int c;

	while (c = *s2++)
		if (c != *s1++)
			return(0);
	return(1);
I 6
}

char *
any(cp, set)
	register char *cp;
	char *set;
{
	register char *sp;

	if (cp == 0 || set == 0)
		return (0);
	while (*cp) {
		for (sp = set; *sp; sp++)
			if (*cp == *sp)
				return (cp);
		cp++;
	}
	return ((char *)0);
E 6
}

peekc(fp)
FILE *fp;
{
	register c;

	c = getc(fp);
	ungetc(c, fp);
	return(c);
E 24
I 24
D 25
	if (gettimeofday(&tp,&tzp))
		error("unable to get time of day.",CHN);
	fprintf(stderr,"\n>>> BUGFILER <<<\n\t%s",ctime(&tp.tv_sec));
E 25
I 25
	if (gettimeofday(&tp, (struct timezone *)NULL))
		error("can't get time of day.", CHN);
D 31
	fprintf(stderr, "\n>>> BUGFILER <<<\n\t%s", ctime(&tp.tv_sec));
E 31
I 31
	for (C1 = C2 = ctime(&tp.tv_sec); *C1 && *C1 != '\n'; ++C1);
	*C1 = EOS;
	fputs(C2, stderr);
E 31
E 25
E 24
E 2
}
E 1
