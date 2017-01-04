h05105
s 00010/00005/00189
d D 5.6 88/06/29 21:50:53 bostic 11 10
c install approved copyright notice
e
s 00012/00006/00182
d D 5.5 87/12/26 21:42:16 bostic 10 9
c add Berkeley header
e
s 00008/00003/00180
d D 5.4 87/11/14 12:40:07 bostic 9 8
c standard usage statements
e
s 00067/00059/00116
d D 5.3 87/04/26 12:20:10 bostic 8 7
c allow root password; general cleanup; bug report 4.2BSD/ucb/55
e
s 00073/00100/00102
d D 5.2 87/03/18 15:21:48 bostic 7 6
c removed timezone, general cleanup
e
s 00014/00002/00188
d D 5.1 85/05/31 09:19:55 dist 6 5
c Add copyright
e
s 00014/00003/00176
d D 4.5 84/06/22 08:31:00 kre 5 4
c Handle EOF from user sanely (don't just loop till timeout)
e
s 00136/00012/00043
d D 4.4 84/03/26 13:41:05 ralph 4 3
c added timeout, allow root password to override.
e
s 00013/00017/00042
d D 4.3 83/06/10 23:34:07 sam 3 2
c new signals, no libjobs
e
s 00011/00004/00048
d D 4.2 82/02/11 11:30:09 root 2 1
c upgraded signal handling to 4.1bsd (mikey olson)
e
s 00052/00000/00000
d D 4.1 80/10/01 17:27:20 bill 1 0
c date and time created 80/10/01 17:27:20 by bill
e
u
U
t
T
I 6
/*
D 10
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * Copyright (c) 1980, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */

E 6
I 3
#ifndef lint
E 3
I 1
D 6
static char *sccsid = "%W% (Berkeley) %G%";
I 3
#endif
E 6
I 6
char copyright[] =
D 10
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 10
I 10
"%Z% Copyright (c) 1980, 1987 Regents of the University of California.\n\
E 10
 All rights reserved.\n";
D 9
#endif not lint
E 9
I 9
D 10
#endif /* !lint */
E 10
I 10
#endif /* not lint */
E 10
E 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
D 10
#endif /* !lint */
E 10
I 10
#endif /* not lint */
E 10
E 9
E 6

/*
D 4
 * Lock a terminal up until the knowledgeable Joe returns.
E 4
I 4
D 8
 * Lock a terminal up until the given key is entered,
 * or until the root password is entered,
 * or the given interval times out.
E 8
I 8
 * Lock a terminal up until the given key is entered, until the root
 * password is entered, or the given interval times out.
E 8
 *
 * Timeout interval is by default TIMEOUT, it can be changed with
 * an argument of the form -time where time is in minutes
E 4
 */
I 4

D 7
#include <pwd.h>
E 4
E 3
#include <stdio.h>
#include <sys/types.h>
E 7
I 7
#include <sys/param.h>
E 7
D 2
#include <stat.h>
E 2
I 2
#include <sys/stat.h>
I 4
#include <sys/time.h>
E 4
E 2
D 7
#include <signal.h>
E 7
I 7
#include <sys/signal.h>
#include <pwd.h>
E 7
#include <sgtty.h>
I 7
#include <stdio.h>
I 9
#include <ctype.h>
E 9
E 7

D 3
/*
 * Lock a terminal up until the knowledgeable Joe returns.
 */
E 3
D 4
char	masterp[] =	"hasta la vista\n";
struct	sgttyb tty, ntty;
char	s[BUFSIZ], s1[BUFSIZ];
E 4
I 4
D 7
#define TIMEOUT 15
E 7
I 7
D 8
#define	TIMEOUT 15
E 8
I 8
#define	TIMEOUT	15
#define	YES	1
#define	NO	0
E 8
E 7
E 4

I 4
D 7
struct	passwd *pwd;
char	*crypt();
char	*getpass();
char	*index();
char	*ttyname();
char	*timezone();
char	*asctime();
struct	tm *localtime();
E 7
I 7
int	quit(), bye(), hi();
E 7

D 7
int	quit();
int	bye();
int	hi();

struct timeval	timeout	= {0, 0};
struct timeval	zerotime = {0, 0};
E 7
I 7
struct timeval	timeout;
struct timeval	zerotime;
E 7
struct sgttyb	tty, ntty;
D 8
long	nexttime;		/* keep the timeout time */
E 8
I 8
long	nexttime;			/* keep the timeout time */
E 8

E 4
D 7
main(argc, argv)
I 4
	int argc;
E 4
	char **argv;
E 7
I 7
D 8
main(argc,argv)
E 8
I 8
/*ARGSUSED*/
main(argc, argv)
E 8
	int	argc;
	char	**argv;
E 7
{
D 7
	register int t;
D 4
	struct stat statb;
E 4
I 4
	char	*ttynam;
	char	*ap;
	int	sectimeout = TIMEOUT;
	char	s[BUFSIZ], s1[BUFSIZ];
	char	hostname[32];
	char	*tzn;
E 7
I 7
D 8
	struct passwd	*pwd;
E 8
I 8
	struct passwd	*root_pwd, *my_pwd;
E 8
E 7
	struct timeval	timval;
	struct itimerval	ntimer, otimer;
D 7
	struct timezone	timzone;
E 7
	struct tm	*timp;
D 7
	struct stat	statb;
E 7
I 7
D 8
	int	sectimeout = TIMEOUT;
E 8
I 8
	int	sectimeout = TIMEOUT,
		use_mine;
E 8
	char	*ttynam, *ap, *tzn,
D 8
		hostname[MAXHOSTNAMELEN],
		s[BUFSIZ], s1[BUFSIZ],
E 8
I 8
		hostname[MAXHOSTNAMELEN], s[BUFSIZ], s1[BUFSIZ],
E 8
		*crypt(), *index(), *ttyname();
E 7
E 4

D 2
	for (t = 1; t <= 16; t++)
		if (t != SIGHUP)
		signal(t, SIG_IGN);
E 2
I 2
D 3
	
	/*
	 *	Ignore signals generated from tty keyboard.  These signals
	 *	are for xBSD only.  This program should be compiled with
	 *	the jobs library (cc ... -ljobs).
	 */
	sigset( SIGINT, SIG_IGN ); 
	sigset( SIGQUIT, SIG_IGN ); 
	sigset( SIGTSTP, SIG_IGN ); 

E 3
I 3
D 4
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
E 3
E 2
	if (argc > 0)
		argv[0] = 0;
E 4
I 4
D 7
	/* process arguments */
E 7
I 7
D 8
	/* process argument */
E 7

D 7
	if (argc > 1){
		if (argv[1][0] != '-')
			goto usage;
		if (sscanf(&(argv[1][1]), "%d", &sectimeout) != 1)
			goto usage;
E 7
I 7
	if (argc > 1 && (argv[1][0] != '-' ||
	    (sectimeout = atoi(argv[1] + 1)) <= 0)) {
		puts("Usage: lock [-timeout]");
		exit (1);
E 8
I 8
	use_mine = NO;
	for (++argv; *argv; ++argv) {
		if (argv[0][0] != '-')
			usage();
		if (argv[0][1] == 'p')
			use_mine = YES;
I 9
		else if (!isdigit(argv[0][1])) {
			fprintf(stderr, "lock: illegal option -- %c\n", argv[0][1]);
			usage();
		}
E 9
		else if ((sectimeout = atoi(*argv + 1)) <= 0)
			usage();
E 8
E 7
	}
	timeout.tv_sec = sectimeout * 60;

	/* get information for header */
D 8

E 8
E 4
D 3
	if (gtty(0, &tty))
E 3
I 3
	if (ioctl(0, TIOCGETP, &tty))
E 3
		exit(1);
I 4
D 7
	pwd = getpwuid(0);
E 7
	gethostname(hostname, sizeof(hostname));
D 7
	if (!(ttynam = ttyname(0))){
		printf("lock: not a terminal?");
E 7
I 7
	if (!(ttynam = ttyname(0))) {
		puts("lock: not a terminal?");
E 7
D 8
		exit (1);
E 8
I 8
		exit(1);
E 8
	}
D 7
	gettimeofday(&timval, &timzone);
E 7
I 7
	if (gettimeofday(&timval, (struct timezone *)NULL)) {
		perror("gettimeofday");
D 8
		exit (1);
E 8
I 8
		exit(1);
E 8
	}
E 7
	nexttime = timval.tv_sec + (sectimeout * 60);
	timp = localtime(&timval.tv_sec);
	ap = asctime(timp);
D 7
	tzn = timezone(timzone.tz_minuteswest, timp->tm_isdst);
E 7
I 7
	tzn = timp->tm_zone;
E 7

D 8
	/* get key and check again */

E 8
D 7
	signal(SIGINT, quit);
	signal(SIGQUIT, quit);
E 7
I 7
	(void)signal(SIGINT, quit);
	(void)signal(SIGQUIT, quit);
E 7
E 4
	ntty = tty; ntty.sg_flags &= ~ECHO;
D 3
	stty(0, &ntty);
E 3
I 3
D 7
	ioctl(0, TIOCSETN, &ntty);
E 3
	printf("Key: ");
D 5
	fgets(s, sizeof s, stdin);
E 5
I 5
	if (fgets(s, sizeof s, stdin) == NULL) {
		putchar('\n');
E 7
I 7
	(void)ioctl(0, TIOCSETP, &ntty);

D 8
	fputs("Key: ",stdout);
	if (!gets(s,sizeof(s)))
E 7
		quit();
D 7
	}
E 5
	printf("\nAgain: ");
E 7
I 7
	fputs("\nAgain: ",stdout);

E 7
D 5
	fgets(s1, sizeof s1, stdin);
E 5
I 5
	/*
	 * Don't need EOF test here, if we get EOF, then s1 != s
	 * and the right things will happen.
	 */
D 7
	(void) fgets(s1, sizeof s1, stdin);
E 7
I 7
	(void)gets(s1,sizeof(s1));
E 7
E 5
	putchar('\n');
	if (strcmp(s1, s)) {
		putchar(07);
D 7
		stty(0, &tty);
E 7
I 7
		ioctl(0, TIOCSETP, &tty);
E 7
		exit(1);
E 8
I 8
	if (!use_mine) {
		/* get key and check again */
		fputs("Key: ", stdout);
		if (!gets(s, sizeof(s)))
			quit();
		fputs("\nAgain: ", stdout);
		/*
		 * Don't need EOF test here, if we get EOF, then s1 != s
		 * and the right things will happen.
		 */
		(void)gets(s1, sizeof(s1));
		putchar('\n');
		if (strcmp(s1, s)) {
			puts("\07lock: passwords didn't match.");
			ioctl(0, TIOCSETP, &tty);
			exit(1);
		}
		s[0] = NULL;
E 8
	}
D 7
	s[0] = 0;
E 7
I 7
D 8
	s[0] = NULL;
E 8
E 7
I 4

D 8
	/* Set signal handlers */

E 8
I 8
	/* set signal handlers */
E 8
D 7
	signal(SIGINT, hi);
	signal(SIGQUIT, hi);
	signal(SIGTSTP, hi);
	signal(SIGALRM, bye);
E 7
I 7
	(void)signal(SIGINT, hi);
	(void)signal(SIGQUIT, hi);
	(void)signal(SIGTSTP, hi);
	(void)signal(SIGALRM, bye);

E 7
	ntimer.it_interval = zerotime;
	ntimer.it_value = timeout;
	setitimer(ITIMER_REAL, &ntimer, &otimer);

D 8
	/* Header info */

E 8
I 8
	/* header info */
E 8
D 7
	printf ("lock: %s on %s. timeout in %d minutes\n",
		ttynam, hostname, sectimeout);
	printf("time now is %.20s", ap);
	if (tzn)
		printf("%s", tzn);
	printf("%s", ap+19);
E 7
I 7
	printf ("lock: %s on %s. timeout in %d minutes\ntime now is %.20s%s%s",
D 8
		ttynam,hostname,sectimeout,ap,tzn,ap+19);
E 8
I 8
		ttynam, hostname, sectimeout, ap, tzn, ap + 19);
E 8
E 7

	/* wait */
D 8

E 4
D 7
	for (;;) {
I 4
		printf("Key: ");
E 4
D 5
		fgets(s, sizeof s, stdin);
E 5
I 5
		if (fgets(s, sizeof s, stdin) == NULL) {
E 7
I 7
	for (pwd = getpwuid(0);;) {
		fputs("Key: ",stdout);
		if (!gets(s,sizeof(s))) {
E 8
I 8
	root_pwd = getpwuid(0);
	if (use_mine)
		my_pwd = getpwuid(getuid());
	for (;;) {
		fputs("Key: ", stdout);
		if (!gets(s, sizeof(s))) {
E 8
E 7
			clearerr(stdin);
			hi();
			continue;
		}
E 5
D 7
		if (strcmp(s1, s) == 0)
E 7
I 7
D 8
		if (!strcmp(s1,s) || !pwd || !*pwd->pw_passwd ||
			!strcmp(pwd->pw_passwd,crypt(s,pwd->pw_passwd)))
E 8
I 8
		if (use_mine) {
			if (!my_pwd || !*my_pwd->pw_passwd || !strcmp(my_pwd->pw_passwd, crypt(s, my_pwd->pw_passwd)))
				break;
		}
		else if (!strcmp(s1, s))
E 8
E 7
			break;
I 8
		if (!root_pwd || !*root_pwd->pw_passwd || !strcmp(root_pwd->pw_passwd, crypt(s, root_pwd->pw_passwd)))
			break;
E 8
D 4
		if (strcmp(s, masterp) == 0)
E 4
I 4
D 7
		if (pwd == (struct passwd *) 0 || pwd->pw_passwd[0] == '\0')
E 4
			break;
D 4
		putchar(07);
E 4
I 4
		ap = index(s, '\n');
		if (ap != NULL)
			*ap = '\0';
		if (strcmp(pwd->pw_passwd, crypt(s, pwd->pw_passwd)) == 0)
			break;
		printf("\07\n");
E 7
I 7
		puts("\07");
E 7
E 4
D 3
		if (gtty(0, &ntty))
E 3
I 3
		if (ioctl(0, TIOCGETP, &ntty))
E 3
			exit(1);
	}
D 3
	stty(0, &tty);
E 3
I 3
D 7
	ioctl(0, TIOCSETN, &tty);
E 7
I 4
	putchar('\n');
D 7
	exit (0);
usage:
	printf("Usage: lock [-timeout]\n");
	exit (1);
E 7
I 7
	quit();
E 7
}

D 8
/*
D 7
 *	get out of here
E 7
I 7
 *	tell the user we are waiting
E 7
 */

E 8
D 7
quit()
E 7
I 7
static
hi()
E 7
{
D 7
	ioctl(0, TIOCSETN, &tty);
	exit (0);
}
E 7
I 7
	struct timeval	timval;
E 7

D 7
bye()
{
	ioctl(0, TIOCSETN, &tty);
	printf("lock: timeout\n");
	exit (1);
E 7
I 7
	if (!gettimeofday(&timval, (struct timezone *)NULL))
D 8
	    printf("lock: type in the unlock key. timeout in %d minutes\n",
	    (nexttime - timval.tv_sec) / 60);
E 8
I 8
	    printf("lock: type in the unlock key. timeout in %ld:%ld minutes\n",
	    (nexttime - timval.tv_sec) / 60, (nexttime - timval.tv_sec) % 60);
E 8
E 7
}

D 8
/*
D 7
 *	tell the user we are waiting
E 7
I 7
 *	get out of here
E 7
 */
E 8
D 7

hi()
E 7
I 7
static
quit()
E 7
{
D 7
	long	curtime;
	struct timeval	timval;
	struct timezone	timzone;
E 7
I 7
	(void)ioctl(0, TIOCSETP, &tty);
D 8
	exit (0);
E 8
I 8
	exit(0);
E 8
}
E 7

D 7
	gettimeofday(&timval, &timzone);
	curtime = timval.tv_sec;
	printf("lock: type in the unlock key. timeout in %d minutes\n",
		(nexttime-curtime)/60);
E 7
I 7
static
bye()
{
	(void)ioctl(0, TIOCSETP, &tty);
	puts("lock: timeout");
D 8
	exit (1);
E 8
I 8
	exit(1);
}

static
usage()
{
D 9
	puts("Usage: lock [-p] [-timeout]");
E 9
I 9
	fputs("usage: lock [-p] [-timeout]\n", stderr);
E 9
	exit(1);
E 8
E 7
E 4
E 3
}
E 1
