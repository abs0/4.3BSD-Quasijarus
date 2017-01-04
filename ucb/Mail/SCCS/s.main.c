h05077
s 00014/00008/00343
d D 5.5 88/02/18 17:04:07 bostic 24 23
c written by Kurt Shoens; added Berkeley specific header
e
s 00046/00021/00305
d D 5.4 87/05/18 12:28:14 edward 23 22
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00003/00325
d D 5.3 85/09/15 16:58:12 serge 22 21
c always print headers of first few messages when editing different file
e
s 00002/00002/00326
d D 5.2 85/06/21 17:12:19 mckusick 21 20
c botched copyright
e
s 00014/00002/00314
d D 5.1 85/06/06 10:37:28 dist 20 19
c Add copyright
e
s 00008/00001/00308
d D 2.15 85/05/27 15:02:19 serge 19 18
c Added -I flag, which causes Mail to assume that input is a tty
e
s 00001/00002/00308
d D 2.14 84/08/08 17:05:47 ralph 18 17
c fix stdio flushing, don't mess with stdio buffers
e
s 00000/00002/00310
d D 2.13 84/07/19 15:42:49 ralph 17 16
c use flock for mailbox locking
e
s 00003/00003/00309
d D 2.12 83/08/11 22:17:48 sam 16 15
c standardize sccs keyword lines
e
s 00000/00001/00312
d D 2.11 83/06/12 11:16:43 sam 15 14
c new signals
e
s 00008/00001/00305
d D 2.10 83/01/22 15:22:37 leres 14 13
c Added (restored?) missing required argument in call to announce() so that
c initial greeting is printed (unless "quiet" is set.) Added verbose
c command/option.
e
s 00003/00000/00303
d D 2.9 82/09/02 12:34:28 mckusick 13 12
c added call to inithost() if GETHOST is defined
e
s 00006/00001/00297
d D 2.8 82/07/28 15:35:54 kurt 12 11
c changed to print own error message if setfile fails 
c 
e
s 00002/00001/00296
d D 2.7 82/06/24 23:53:28 kurt 11 10
c made handling of "mailname" global variable simpler -- now it 
c is an array of chars rather than a pointer that used to get set to a small 
c calloc'd space that would get clobbered if you changed to a longer name. 
c 
e
s 00006/00001/00291
d D 2.6 82/02/26 08:01:49 kurt 10 9
c changed the -T flag to close(creat()) the file at the beginning 
c in case you user x's from Mail so readnews won't be upset. 
c 
e
s 00040/00011/00252
d D 2.5 82/02/13 14:49:35 kurt 9 8
c changed to load user's .mailrc before figuring out file 
c from -f so we can interpret +name.  Header printing now invoked by 
c main() with special escape to be able to ^C it. 
c 
e
s 00007/00000/00256
d D 2.4 81/12/10 12:54:37 kurt 8 7
c changed to set global "baud" to the output rate code from gtty 
c 
e
s 00005/00000/00251
d D 2.3 81/09/22 08:44:36 kurt 7 6
c changed start up code to exit if there are 0 messages and 
c we are not in edit mode 
c 
e
s 00013/00000/00238
d D 2.2 81/07/20 17:06:58 kurt 6 5
c changed to notice a flag of the form -T filename so that netnews can
c discover which articles were read or deleted
e
s 00000/00000/00238
d D 2.1 81/07/01 11:09:49 kurt 5 4
c Release to Heidi Stettner
e
s 00005/00001/00233
d D 1.4 81/04/01 12:57:48 kurt 4 3
c changed to ignore tty signals when about to quit
e
s 00007/00000/00227
d D 1.3 81/02/06 09:40:38 kas 3 2
c added -N flag to suppress header printing
e
s 00002/00047/00225
d D 1.2 80/10/09 13:39:52 kas 2 1
c changed to call setfile/lex.c to set up initial input file.
e
s 00272/00000/00000
d D 1.1 80/10/08 09:50:49 kas 1 0
c date and time created 80/10/08 09:50:49 by kas
e
u
U
f b 
t
T
I 20
/*
 * Copyright (c) 1980 Regents of the University of California.
D 24
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 24
I 24
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 24
 */

E 20
I 1
D 16
#
E 16
I 16
D 24
#ifndef lint
D 19
static char sccsid[] = "%W% (Berkeley) %G%";
E 19
I 19
D 20
static char *sccsid = "%W% (Berkeley) %G%";
E 19
#endif
E 20
I 20
D 21
char copyright[] =
E 21
I 21
char *copyright =
E 24
I 24
#ifdef notdef
char copyright[] =
E 24
E 21
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 24
#endif not lint
E 24
I 24
#endif /* notdef */
E 24

D 24
#ifndef lint
D 21
static char sccsid[] = "%W% (Berkeley) %G%";
E 21
I 21
static char *sccsid = "%W% (Berkeley) %G%";
E 21
#endif not lint
E 24
I 24
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 24
E 20
E 16

#include "rcv.h"
#include <sys/stat.h>

/*
 * Mail -- a mail program
 *
 * Startup -- interface with user.
 */
D 16

static char *SccsId = "%W% %G%";
E 16

I 9
jmp_buf	hdrjmp;

E 9
/*
 * Find out who the user is, copy his mail file (if exists) into
 * /tmp/Rxxxxx and set up the message pointers.  Then, print out the
 * message headers and read user commands.
 *
 * Command line syntax:
 *	Mail [ -i ] [ -r address ] [ -h number ] [ -f [ name ] ]
 * or:
 *	Mail [ -i ] [ -r address ] [ -h number ] people ...
 */

main(argc, argv)
	char **argv;
{
	register char *ef;
	register int i, argp;
D 9
	int mustsend, uflag;
E 9
I 9
D 10
	int mustsend, uflag, hdrstop(), (*prevint)();
E 10
I 10
D 23
	int mustsend, uflag, hdrstop(), (*prevint)(), f;
E 10
E 9
	FILE *ibuf, *ftat;
E 23
I 23
	int mustsend, hdrstop(), (*prevint)(), f;
E 23
D 2
	extern char tempMesg[], _sobuf[];
E 2
I 2
D 17
	extern char _sobuf[];
E 17
I 8
	struct sgttyb tbuf;
E 8
E 2

D 23
#ifdef signal
	Siginit();
#endif

E 23
	/*
D 23
	 * Set up a reasonable environment.  We clobber the last
	 * element of argument list for compatibility with version 6,
	 * figure out whether we are being run interactively, set up
E 23
I 23
	 * Set up a reasonable environment.
	 * Figure out whether we are being run interactively, set up
E 23
	 * all the temporary files, buffer standard output, and so forth.
	 */

D 23
	uflag = 0;
	argv[argc] = (char *) -1;
E 23
I 13
#ifdef	GETHOST
	inithost();
#endif	GETHOST
E 13
	mypid = getpid();
	intty = isatty(0);
	outtty = isatty(1);
I 8
	if (outtty) {
		gtty(1, &tbuf);
		baud = tbuf.sg_ospeed;
D 23
	}
	else
E 23
I 23
	} else
E 23
		baud = B9600;
E 8
	image = -1;
D 17
	setbuf(stdout, _sobuf);
E 17

	/*
	 * Now, determine how we are being used.
	 * We successively pick off instances of -r, -h, -f, and -i.
	 * If called as "rmail" we note this fact for letter sending.
	 * If there is anything left, it is the base of the list
	 * of users to mail to.  Argp will be set to point to the
	 * first of these users.
	 */

	ef = NOSTR;
	argp = -1;
	mustsend = 0;
	if (argc > 0 && **argv == 'r')
		rmail++;
	for (i = 1; i < argc; i++) {

		/*
		 * If current argument is not a flag, then the
		 * rest of the arguments must be recipients.
		 */

		if (*argv[i] != '-') {
			argp = i;
			break;
		}
		switch (argv[i][1]) {
		case 'r':
			/*
			 * Next argument is address to be sent along
			 * to the mailer.
			 */
			if (i >= argc - 1) {
				fprintf(stderr, "Address required after -r\n");
				exit(1);
			}
			mustsend++;
			rflag = argv[i+1];
			i++;
			break;

I 6
		case 'T':
			/*
			 * Next argument is temp file to write which
			 * articles have been read/deleted for netnews.
			 */
			if (i >= argc - 1) {
				fprintf(stderr, "Name required after -T\n");
				exit(1);
			}
			Tflag = argv[i+1];
I 10
			if ((f = creat(Tflag, 0600)) < 0) {
				perror(Tflag);
				exit(1);
			}
			close(f);
E 10
			i++;
			break;

E 6
		case 'u':
			/*
			 * Next argument is person to pretend to be.
			 */
D 23
			uflag++;
E 23
			if (i >= argc - 1) {
D 9
				fprintf(stderr, "You obviously dont know what you're doing\n");
E 9
I 9
				fprintf(stderr, "Missing user name for -u\n");
E 9
				exit(1);
			}
			strcpy(myname, argv[i+1]);
			i++;
			break;

		case 'i':
			/*
			 * User wants to ignore interrupts.
			 * Set the variable "ignore"
			 */
			assign("ignore", "");
			break;

		case 'd':
			debug++;
			break;

		case 'h':
			/*
			 * Specified sequence number for network.
			 * This is the number of "hops" made so
			 * far (count of times message has been
			 * forwarded) to help avoid infinite mail loops.
			 */
			if (i >= argc - 1) {
				fprintf(stderr, "Number required for -h\n");
				exit(1);
			}
			mustsend++;
			hflag = atoi(argv[i+1]);
			if (hflag == 0) {
				fprintf(stderr, "-h needs non-zero number\n");
				exit(1);
			}
			i++;
			break;

		case 's':
			/*
			 * Give a subject field for sending from
			 * non terminal
			 */
			if (i >= argc - 1) {
				fprintf(stderr, "Subject req'd for -s\n");
				exit(1);
			}
			mustsend++;
			sflag = argv[i+1];
			i++;
			break;

		case 'f':
			/*
			 * User is specifying file to "edit" with Mail,
			 * as opposed to reading system mailbox.
			 * If no argument is given after -f, we read his
			 * mbox file in his home directory.
			 */
			if (i >= argc - 1)
				ef = mbox;
			else
				ef = argv[i + 1];
			i++;
			break;

		case 'n':
			/*
			 * User doesn't want to source /usr/lib/Mail.rc
			 */
			nosrc++;
			break;

I 3
		case 'N':
			/*
			 * Avoid initial header printing.
			 */
			noheader++;
			break;

I 14
		case 'v':
			/*
			 * Send mailer verbose flag
			 */
			assign("verbose", "");
I 19
			break;

		case 'I':
			/*
			 * We're interactive
			 */
			intty = 1;
E 19
			break;

E 14
E 3
		default:
			fprintf(stderr, "Unknown flag: %s\n", argv[i]);
			exit(1);
		}
	}

	/*
	 * Check for inconsistent arguments.
	 */

D 9
	if (rflag != NOSTR && strcmp(rflag, "daemon") == 0) {
		ftat = fopen("/crp/kas/gotcha", "a");
		if (ftat != NULL) {
			fprintf(ftat, "user daemon, real uid %d\n", getuid());
			fclose(ftat);
		}
	}
E 9
	if (ef != NOSTR && argp != -1) {
		fprintf(stderr, "Cannot give -f and people to send to.\n");
		exit(1);
	}
	if (mustsend && argp == -1) {
		fprintf(stderr, "The flags you gave make no sense since you're not sending mail.\n");
		exit(1);
	}
	tinit();
I 23
	setscreensize();
E 23
I 9
	input = stdin;
	rcvmode = argp == -1;
	if (!nosrc)
		load(MASTER);
	load(mailrc);
E 9
	if (argp != -1) {
D 9
		commands();
E 9
		mail(&argv[argp]);

		/*
		 * why wait?
		 */

		exit(senderr);
	}

	/*
	 * Ok, we are reading mail.
	 * Decide whether we are editing a mailbox or reading
	 * the system mailbox, and open up the right stuff.
	 */

D 9
	rcvmode++;
E 9
	if (ef != NOSTR) {
I 9
		char *ename;

E 9
		edit++;
I 9
		ename = expand(ef);
		if (ename != ef) {
D 23
			ef = (char *) calloc(1, strlen(ename) + 1);
E 23
I 23
			ef = malloc((unsigned) strlen(ename) + 1);
E 23
			strcpy(ef, ename);
		}
E 9
D 11
		editfile = mailname = ef;
E 11
I 11
		editfile = ef;
		strcpy(mailname, ef);
E 11
D 2
		if ((ibuf = fopen(mailname, "r")) == NULL) {
			perror(mailname);
			exit(1);
		}
		if ((i = open(mailname, 1)) < 0)
			printf("Warning: \"%s\" not writable.\n", mailname);
		else
			close(i);
E 2
	}
D 2
	else {
		if ((ibuf = fopen(mailname, "r")) == NULL) {
			if (uflag)
				printf("No mail for %s\n", myname);
			else
				printf("No mail.\n");
			exit(0);
		}
	}

	/*
	 * Copy the messages into /tmp
	 * and set pointers.
	 */

	mailsize = fsize(ibuf);
	if ((otf = fopen(tempMesg, "w")) == NULL) {
		perror(tempMesg);
E 2
I 2
D 12
	if (setfile(mailname, edit) < 0)
E 12
I 12
	if (setfile(mailname, edit) < 0) {
		if (edit)
			perror(mailname);
		else
			fprintf(stderr, "No mail for %s\n", myname);
E 12
E 2
		exit(1);
I 12
	}
E 12
I 9
D 22
	if (!edit && !noheader && value("noheader") == NOSTR) {
E 22
I 22
	if (!noheader && value("noheader") == NOSTR) {
E 22
		if (setjmp(hdrjmp) == 0) {
D 23
			if ((prevint = sigset(SIGINT, SIG_IGN)) != SIG_IGN)
				sigset(SIGINT, hdrstop);
E 23
I 23
			if ((prevint = signal(SIGINT, SIG_IGN)) != SIG_IGN)
				signal(SIGINT, hdrstop);
E 23
D 14
			announce();
E 14
I 14
			announce(!0);
E 14
			fflush(stdout);
D 23
			sigset(SIGINT, prevint);
E 23
I 23
			signal(SIGINT, prevint);
E 23
		}
	}
D 22
	if (edit)
		newfileinfo();
E 22
E 9
I 7
	if (!edit && msgCount == 0) {
		printf("No mail\n");
		fflush(stdout);
		exit(0);
	}
E 7
D 2
	}
	if ((itf = fopen(tempMesg, "r")) == NULL) {
		perror(tempMesg);
		exit(1);
	}
	remove(tempMesg);
	setptr(ibuf);
	fclose(ibuf);

	/*
	 * print headings and accept user commands.
	 */

	if (msgCount == 0) {
		if (uflag)
			printf("No mail for %s\n", myname);
		else
			printf("No messages.\n");
		exit(1);
	}
E 2
	commands();
D 4
	if (!edit)
E 4
I 4
	if (!edit) {
D 23
		sigset(SIGHUP, SIG_IGN);
		sigset(SIGINT, SIG_IGN);
		sigset(SIGQUIT, SIG_IGN);
E 23
I 23
		signal(SIGHUP, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
E 23
E 4
		quit();
I 4
	}
E 4
	exit(0);
I 9
}

/*
 * Interrupt printing of the headers.
 */
hdrstop()
{

D 18
	clrbuf(stdout);
	printf("\nInterrupt\n");
E 18
	fflush(stdout);
I 18
	fprintf(stderr, "\nInterrupt\n");
E 18
D 15
	sigrelse(SIGINT);
E 15
	longjmp(hdrjmp, 1);
I 23
}

/*
 * Compute what the screen size should be.
 * We use the following algorithm for the height:
 *	If baud rate < 1200, use  9
 *	If baud rate = 1200, use 14
 *	If baud rate > 1200, use 24 or ws_row
 * Width is either 80 or ws_col;
 */
setscreensize()
{
#ifdef	TIOCGWINSZ
	struct winsize ws;

	if (ioctl(fileno(stdout), TIOCGWINSZ, (char *) &ws) < 0)
		ws.ws_col = ws.ws_row = 0;
#endif
	if (baud < B1200)
		screenheight = 9;
	else if (baud == B1200)
		screenheight = 14;
#ifdef	TIOCGWINSZ
	else if (ws.ws_row != 0)
		screenheight = ws.ws_row;
#endif
	else
		screenheight = 24;
#ifdef TIOCGWINSZ
	if (ws.ws_col != 0)
		screenwidth = ws.ws_col;
	else
#endif
		screenwidth = 80;
E 23
E 9
}
E 1
