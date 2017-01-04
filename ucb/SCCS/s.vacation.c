h26240
s 00010/00005/00343
d D 5.10 88/06/29 21:51:13 bostic 23 22
c install approved copyright notice
e
s 00015/00016/00333
d D 5.9 88/03/24 14:54:15 bostic 22 21
c remove sysexits.h
e
s 00001/00001/00348
d D 5.8 88/01/05 12:56:49 bostic 21 20
c reverse test for Cc: comparison
e
s 00192/00221/00157
d D 5.7 87/12/26 15:27:46 bostic 20 19
c remove vacation.ignore stuff; first cut at checking To: and Cc: lines 
c for mention of user's login or aliases; remove messages to stderr.
e
s 00003/00003/00375
d D 5.6 87/08/03 20:36:25 bostic 19 18
c strcasencmp to strncasecmp
e
s 00094/00052/00284
d D 5.5 87/07/03 15:00:50 bostic 18 17
c added logging, fixed couple of minor bugs, allow default user 
c when initializing database, put sysexits back in.
e
s 00239/00398/00097
d D 5.4 87/07/02 19:55:01 bostic 17 15
c getopt(3), automagically init the database, read list of 
c addresses to be completely ignored, remove _doprnt calls, handle 
c local and uucp junk mail better, use strcasecmp() calls
e
s 00067/00020/00337
d D 4.1.1.1 85/07/01 18:04:03 eric 16 10
c changes from Geoff Collyer "to work on machines with stricter alignment
c requirements than the VAX and prevent uucp mail loops."
e
s 00007/00001/00488
d D 5.3 85/07/01 17:41:39 eric 15 14
c fix alignment problems on 68K & pyramid boxes caused by -ldbm
e
s 00005/00003/00484
d D 5.2 85/06/16 17:55:53 eric 14 13
c expand list of pseudo-users who will not get responses
e
s 00015/00002/00472
d D 5.1 85/06/16 17:05:30 eric 13 12
c raise to 5.1; add copyright notice
e
s 00117/00004/00357
d D 4.3 85/06/16 17:02:35 eric 12 11
c don't send mail to *-request@* or to Precedence: junk/bulk
e
s 00018/00014/00343
d D 4.2 85/04/29 19:48:54 eric 11 10
c compile outside of sendmail/aux directory
e
s 00000/00000/00357
d D 4.1 83/07/25 20:11:46 eric 10 9
c 4.2 release version
e
s 00001/00001/00356
d D 3.9 83/01/23 22:07:20 eric 9 8
c don't pass -n to sendmail
e
s 00033/00005/00324
d D 3.8 83/01/23 19:28:55 eric 8 7
c get vacation to compile again -- I'm off to UNICOM!
e
s 00007/00007/00322
d D 3.7 82/05/31 18:50:46 eric 7 6
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00052/00018/00277
d D 3.6 82/03/20 16:44:47 eric 6 5
c try to clean up for setuid operation
e
s 00001/00001/00294
d D 3.5 81/12/06 12:40:38 eric 5 4
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00000/00044/00295
d D 3.4 81/10/26 09:33:31 eric 4 3
c split convtime into its own file so sendmail can use it
e
s 00055/00003/00284
d D 3.3 81/10/15 20:54:07 eric 3 2
c add -t flag to specify intermessage timeout
e
s 00002/00001/00285
d D 3.2 81/10/15 09:51:04 eric 2 1
c deal with recursive calls properly.
e
s 00286/00000/00000
d D 3.1 81/10/15 09:32:32 eric 1 0
c date and time created 81/10/15 09:32:32 by eric
e
u
U
f b 
f i 
t
T
I 13
/*
I 20
 * Copyright (c) 1983, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 23
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 23
I 23
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
E 23
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1983, 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

/*
E 20
**  Vacation
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
D 20
**
D 17
**  Copyright (c) 1983 Regents of the University of California.
E 17
I 17
**  Copyright (c) 1983, 1987 Regents of the University of California.
E 17
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
E 20
*/

D 20
#ifndef lint
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint

E 20
E 13
I 11
D 17
# include <sys/types.h>
E 11
I 1
# include <pwd.h>
# include <stdio.h>
# include <sysexits.h>
I 3
# include <ctype.h>
E 17
I 17
#include <sys/param.h>
#include <sys/file.h>
#include <pwd.h>
#include <stdio.h>
#include <ctype.h>
I 18
D 22
#include <sysexits.h>
E 22
#include <syslog.h>
E 18
E 17
E 3
D 11
# include "useful.h"
# include "userdbm.h"
E 11

D 5
static char	SccsId[] =	"%W%	%G%";
E 5
I 5
D 11
SCCSID(%W%	%Y%	%G%);
E 11
I 11
D 13
static char	SccsId[] =	"%W%	%Y%	%G%";
E 11
E 5

E 13
/*
**  VACATION -- return a message to the sender when on vacation.
**
D 17
**	This program could be invoked as a message receiver
**	when someone is on vacation.  It returns a message
**	specified by the user to whoever sent the mail, taking
**	care not to return a message too often to prevent
**	"I am on vacation" loops.
**
I 6
D 11
**	For best operation, this program should run setuid to
**	root or uucp or someone else that sendmail will believe
**	a -f flag from.  Otherwise, the user must be careful
**	to include a header on his .vacation.msg file.
**
E 11
E 6
**	Positional Parameters:
D 6
**		the user to send to.
E 6
I 6
**		the user to collect the vacation message from.
E 6
**
**	Flag Parameters:
**		-I	initialize the database.
I 13
**		-d	turn on debugging.
E 13
I 6
D 11
**		-tT	set the timeout to T.  messages arriving more
**			often than T will be ignored to avoid loops.
E 11
E 6
**
**	Side Effects:
**		A message is sent back to the sender.
**
**	Author:
**		Eric Allman
**		UCB/INGRES
E 17
I 17
**	This program could be invoked as a message receiver when someone is
**	on vacation.  It returns a message specified by the user to whoever
**	sent the mail, taking care not to return a message too often to
**	prevent "I am on vacation" loops.
E 17
*/

I 11
D 17
typedef int	bool;
E 17
I 17
D 20
#define	NO	0			/* no/false */
#define	YES	1			/* yes/true */
#define	EOS	'\0'			/* end of string */
E 20
#define	MAXLINE	500			/* max line from mail header */
#define	PERIOD	(60L*60L*24L*7L)	/* week between notifications */
I 20
#define	VMSG	".vacation.msg"		/* vacation message */
E 20
#define	VACAT	".vacation"		/* dbm's database prefix */
#define	VDIR	".vacation.dir"		/* dbm's DB prefix, part 1 */
D 20
#define	VIGN	".vacation.ignore"	/* addresses never replied to */
I 18
#define	VLOG	".vacation.log"		/* log action and errors */
E 18
#define	VMSG	".vacation.msg"		/* vacation message */
E 20
#define	VPAG	".vacation.pag"		/* dbm's DB prefix, part 2 */
E 17

D 17
# define TRUE		1
# define FALSE		0

E 11
# define MAXLINE	256	/* max size of a line */
D 16
# define MAXNAME	128	/* max size of one name */
E 16

I 3
# define ONEWEEK	(60L*60L*24L*7L)

D 8
long	Timeout = ONEWEEK;	/* timeout between notices per user */
E 8
I 8
time_t	Timeout = ONEWEEK;	/* timeout between notices per user */
E 8

E 3
D 16
struct dbrec
{
	long	sentdate;
E 16
I 16
struct dbrec {
	time_t	sentdate;
E 16
};

I 11
typedef struct
{
E 17
I 17
D 20
typedef struct {
E 17
	char	*dptr;
	int	dsize;
} DATUM;
E 20
I 20
typedef struct alias {
	struct alias *next;
	char	*name;
} ALIAS;
ALIAS	*names;
E 20

D 17
extern DATUM fetch();
E 17
I 17
D 20
typedef struct {
	time_t	sentdate;
} DBREC;
E 20
I 20
static char from[MAXLINE];		/* sender's address */
E 20
E 17

I 17
D 18
static int	debug = NO;		/* debugging flag */
E 18
I 18
D 20
static int	debug;			/* debugging flag */
E 18
E 17
I 12

E 20
D 17

bool	Debug = FALSE;

E 17
E 12
E 11
main(argc, argv)
D 17
	char **argv;
E 17
I 17
D 20
	int	argc;
	char	**argv;
E 20
I 20
	int argc;
	char **argv;
E 20
E 17
{
D 17
	char *from;
	register char *p;
	struct passwd *pw;
D 6
	register char *homedir;
E 6
I 6
	char *homedir;
	char *myname;
I 16
	char *shortfrom;
E 16
E 6
	char buf[MAXLINE];
	extern struct passwd *getpwnam();
	extern char *newstr();
	extern char *getfrom();
	extern bool knows();
I 12
	extern bool junkmail();
E 12
I 3
D 8
	extern long convtime();
E 8
I 8
	extern time_t convtime();
E 17
I 17
D 20
	extern int	optind;
	struct passwd	*pw;
	int	ch, iflag = NO;
	char	*from,
		*getfrom();
I 18
	uid_t	getuid();
E 20
I 20
	extern int optind;
	extern char *optarg;
	struct passwd *pw;
	ALIAS *cur;
	int ch, iflag;
	char *malloc();
	uid_t getuid();
E 20
E 18
E 17
E 8
E 3

D 17
	/* process arguments */
	while (--argc > 0 && (p = *++argv) != NULL && *p == '-')
	{
		switch (*++p)
		{
		  case 'I':	/* initialize */
D 6
			homedir = getenv("HOME");
			if (homedir == NULL)
				syserr("No home!");
			strcpy(buf, homedir);
			strcat(buf, "/.vacation.dir");
			if (close(creat(buf, 0644)) < 0)
				syserr("Cannot create %s", buf);
			strcpy(buf, homedir);
			strcat(buf, "/.vacation.pag");
			if (close(creat(buf, 0644)) < 0)
				syserr("Cannot create %s", buf);
E 6
I 6
			initialize();
E 6
			exit(EX_OK);

I 12
		  case 'd':	/* debug */
			Debug = TRUE;
E 17
I 17
D 20
	while ((ch = getopt(argc, argv, "Idi")) != EOF)
E 20
I 20
	iflag = 0;
	while ((ch = getopt(argc, argv, "a:Ii")) != EOF)
E 20
		switch((char)ch) {
I 20
		case 'a':			/* alias */
			if (!(cur = (ALIAS *)malloc((u_int)sizeof(ALIAS))))
				break;
			cur->name = optarg;
			cur->next = names;
			names = cur;
			break;
E 20
D 18
		case 'd':			/* debug */
			debug = YES;
E 17
			break;
D 17

E 12
I 3
D 11
		  case 't':	/* set timeout */
			Timeout = convtime(++p);
			break;

E 11
E 3
		  default:
			usrerr("Unknown flag -%s", p);
			exit(EX_USAGE);
E 17
I 17
		case 'i': case 'I':		/* re-init the database */
E 18
I 18
		case 'i':			/* init the database */
		case 'I':			/* backward compatible */
E 18
D 20
			iflag = YES;
E 20
I 20
			iflag = 1;
E 20
			break;
I 18
D 20
		case 'd':			/* debugging */
			debug = YES;
			break;
E 20
E 18
		case '?':
		default:
D 20
			usage();
E 20
I 20
			goto usage;
E 20
E 17
		}
D 17
	}
E 17
I 17
D 20
	argv += optind;
E 20
	argc -= optind;
I 20
	argv += optind;
E 20
E 17

D 17
	/* verify recipient argument */
E 17
D 18
	if (argc != 1)
D 17
	{
		usrerr("Usage: vacation username (or) vacation -I");
		exit(EX_USAGE);
E 17
I 17
		usage();

E 18
D 20
	/* find and move to user's home directory */
E 20
D 18
	if (!(pw = getpwnam(*argv))) {
		fprintf(stderr, "vacation: unknown user %s.\n", *argv);
		exit(1);
E 18
I 18
	if (argc != 1) {
D 20
		if (!iflag)
			usage();
		if (!(pw = getpwuid(getuid())) || chdir(pw->pw_dir)) {
			fprintf(stderr, "vacation: no such user uid %u.\n", getuid());
E 20
I 20
		if (!iflag) {
usage:			syslog(LOG_ERR, "uid %u: usage: vacation [-i] [-a alias] login\n", getuid());
D 22
			exit(EX_USAGE);
E 22
I 22
			exit(1);
E 22
		}
		if (!(pw = getpwuid(getuid()))) {
E 20
			syslog(LOG_ERR, "vacation: no such user uid %u.\n", getuid());
D 22
			exit(EX_USAGE);
E 22
I 22
			exit(1);
E 22
		}
D 20
		*argv = pw->pw_name;
E 20
E 18
E 17
	}
I 17
D 18
	if (chdir(pw->pw_dir)) {
		perror("vacation: chdir");
		exit(1);
E 18
I 18
D 20
	else if (!(pw = getpwnam(*argv)) || chdir(pw->pw_dir)) {
		fprintf(stderr, "vacation: no such user %s.\n", *argv);
E 20
I 20
	else if (!(pw = getpwnam(*argv))) {
E 20
		syslog(LOG_ERR, "vacation: no such user %s.\n", *argv);
D 22
		exit(EX_USAGE);
E 22
I 22
		exit(1);
E 22
E 18
	}
I 20
	if (chdir(pw->pw_dir)) {
		syslog(LOG_ERR, "vacation: no such directory %s.\n", pw->pw_dir);
D 22
		exit(EX_USAGE);
E 22
I 22
		exit(1);
E 22
	}
E 20
E 17

I 6
D 17
	myname = p;

E 6
	/* find user's home directory */
D 6
	pw = getpwnam(p);
E 6
I 6
	pw = getpwnam(myname);
E 6
	if (pw == NULL)
	{
D 6
		usrerr("Unknown user %s", p);
E 6
I 6
		usrerr("Unknown user %s", myname);
E 6
		exit(EX_NOUSER);
E 17
I 17
D 20
	/* iflag cleans out the database */
E 20
	if (iflag) {
		initialize();
D 18
		exit(0);
E 18
I 18
D 22
		exit(EX_OK);
E 22
I 22
		exit(0);
E 22
E 18
E 17
	}
D 17
	homedir = newstr(pw->pw_dir);
D 7
	strcpy(buf, homedir);
	strcat(buf, "/.vacation");
E 7
I 7
	(void) strcpy(buf, homedir);
	(void) strcat(buf, "/.vacation");
E 7
	dbminit(buf);
E 17

I 18
D 20
	if (debug) {
		time_t	now,
			time();
		char	*ctime();
E 20
I 20
	if (!(cur = (ALIAS *)malloc((u_int)sizeof(ALIAS))))
D 22
		exit(EX_SOFTWARE);
E 22
I 22
		exit(1);
E 22
	cur->name = pw->pw_name;
	cur->next = names;
	names = cur;
E 20

D 20
		if (!freopen(VLOG, "a", stderr)) {
			fprintf(stderr, "vacation: can't append ~%s/%s\n", *argv, VLOG);
			syslog(LOG_ERR, "vacation: can't append ~%s/%s\n", *argv, VLOG);
			exit(EX_CANTCREAT);
		}
		(void)time(&now);
		fprintf(stderr, "===== %s", ctime(&now));
	}
E 20
I 20
	readheaders();
E 20

E 18
D 17
	/* read message from standard input (just from line) */
E 17
I 17
D 20
	/*
	 * if database missing, we create it and do a dbminit;
	 * otherwise, just do the dbminit.
	 */
E 20
	if (access(VDIR, F_OK))
		initialize();
	else
		dbminit(VACAT);

D 20
	/* find out who sent us mail */
E 17
D 16
	from = getfrom();
E 16
I 16
	from = getfrom(&shortfrom);
#ifdef VDEBUG
	printf("from='%s'\nshortfrom='%s'\n", from, shortfrom);
	exit(0);
#endif
E 16

D 12
	/* check if this person is already informed */
D 16
	if (!knows(from))
E 16
I 16
	if (!knows(shortfrom))
E 16
E 12
I 12
D 17
	/* check if junk mail or this person is already informed */
	if (!junkmail(from) && !knows(from))
E 12
	{
		/* mark this person as knowing */
D 8
		setknows(from, buf);
E 8
I 8
D 16
		setknows(from);
E 17
I 17
	/* ignore if junk mail */
	if (junkmail(from))
D 18
		exit(0);
E 18
I 18
		exit(EX_OK);
E 18
E 17
E 16
I 16
		setknows(shortfrom);
E 16
E 8

D 17
		/* send the message back */
D 7
		strcat(buf, ".msg");
E 7
I 7
D 8
		(void) strcat(buf, ".msg");
E 8
I 8
		(void) strcpy(buf, homedir);
		(void) strcat(buf, "/.vacation.msg");
E 8
E 7
D 6
		sendmessage(buf, from);
E 6
I 6
D 12
		sendmessage(buf, from, myname);
E 6
D 16
		/* never returns */
E 16
I 16
		/* NOTREACHED */
E 16
E 12
I 12
		if (Debug)
			printf("Sending %s to %s\n", buf, from);
		else
		{
			sendmessage(buf, from, myname);
			/*NOTREACHED*/
		}
E 17
I 17
	/*
	 * ignore if recently replied to this address,
	 * else note the time and send a reply
	 */
	if (!knows(from)) {
		setknows(from, NO);
		sendmessage(from, *argv);
E 20
I 20
	if (!recent()) {
		setreply();
		sendmessage(pw->pw_name);
E 20
E 17
E 12
	}
I 2
D 17
	exit (EX_OK);
E 17
I 17
D 18
	exit(0);
E 18
I 18
D 22
	exit(EX_OK);
E 22
I 22
	exit(0);
E 22
E 18
E 17
E 2
}
D 17
/*
**  GETFROM -- read message from standard input and return sender
**
**	Parameters:
**		none.
**
**	Returns:
**		pointer to the sender address.
**
**	Side Effects:
**		Reads first line from standard input.
*/
E 17

D 17
char *
E 17
I 17
/*
D 20
 * getfrom --
 *	read mail "From" line and return sender's address
E 20
I 20
 * readheaders --
 *	read mail headers
E 20
 */
D 20
static char *
E 17
D 16
getfrom()
E 20
I 20
static
readheaders()
E 20
E 16
I 16
getfrom(shortp)
char **shortp;
E 16
{
D 17
	static char line[MAXLINE];
D 16
	register char *p;
E 16
I 16
	register char *p, *start, *at, *bang;
	char saveat;
E 16
I 11
	extern char *index();
E 17
I 17
D 20
	register char	*p;
	char	buf[MAXLINE],
		*malloc(), *strcpy();
E 20
I 20
	register ALIAS *cur;
	register char *p;
	int tome, cont;
	char buf[MAXLINE], *strcpy(), *index();
E 20
E 17
E 11

D 20
	/* read the from line */
D 17
	if (fgets(line, sizeof line, stdin) == NULL ||
	    strncmp(line, "From ", 5) != NULL)
	{
		usrerr("No initial From line");
		exit(EX_USAGE);
E 17
I 17
	if (!gets(buf) || strncmp(buf, "From ", 5)) {
		fputs("vacation: no initial From line.\n", stderr);
E 20
I 20
	cont = tome = 0;
	while (fgets(buf, sizeof(buf), stdin) && *buf != '\n')
		switch(*buf) {
		case 'F':		/* "From " */
			cont = 0;
			if (!strncmp(buf, "From ", 5)) {
				for (p = buf + 5; *p && *p != ' '; ++p);
				*p = '\0';
				(void)strcpy(from, buf + 5);
				if (junkmail())
D 22
					exit(EX_OK);
E 22
I 22
					exit(0);
E 22
			}
			break;
		case 'P':		/* "Precedence:" */
			cont = 0;
			if (strncasecmp(buf, "Precedence", 10) || buf[10] != ':' && buf[10] != ' ' && buf[10] != '\t')
				break;
			if (!(p = index(buf, ':')))
				break;
			while (*++p && isspace(*p));
			if (!*p)
				break;
			if (!strncasecmp(p, "junk", 4) || !strncasecmp(p, "bulk", 4))
D 22
				exit(EX_OK);
E 22
I 22
				exit(0);
E 22
			break;
		case 'C':		/* "Cc:" */
D 21
			if (!strncmp(buf, "Cc:", 3))
E 21
I 21
			if (strncmp(buf, "Cc:", 3))
E 21
				break;
			cont = 1;
			goto findme;
		case 'T':		/* "To:" */
			if (strncmp(buf, "To:", 3))
				break;
			cont = 1;
			goto findme;
		default:
			if (!isspace(*buf) || !cont || tome) {
				cont = 0;
				break;
			}
findme:			for (cur = names; !tome && cur; cur = cur->next)
				tome += nsearch(cur->name, buf);
		}
	if (!tome)
D 22
		exit(EX_OK);
E 22
I 22
		exit(0);
E 22
	if (!*from) {
		syslog(LOG_ERR, "vacation: no initial \"From\" line.\n");
E 20
D 18
		exit(1);
E 18
I 18
D 22
		exit(EX_DATAERR);
E 22
I 22
		exit(1);
E 22
E 18
E 17
	}
I 20
}
E 20

D 20
	/* find the end of the sender address and terminate it */
D 16
D 17
	p = index(&line[5], ' ');
E 16
I 16
	start = &line[5];
	p = index(start, ' ');
E 16
	if (p == NULL)
	{
		usrerr("Funny From line '%s'", line);
		exit(EX_USAGE);
E 17
I 17
	for (p = &buf[5]; *p && *p != ' '; ++p);
	if (!*p) {
D 18
		fprintf(stderr, "vacation: address terminated From line '%s'", buf);
		exit(1);
E 18
I 18
		fprintf(stderr, "vacation: address terminated From line '%s'\n", buf);
		exit(EX_DATAERR);
E 18
E 17
	}
D 17
	*p = '\0';

E 17
I 17
	*p = EOS;
	if (!(p = malloc((u_int)(strlen(&buf[5]) + 1)))) {
		fputs("vacation: out of space.\n", stderr);
D 18
		exit(1);
E 18
I 18
		exit(EX_OSERR);
E 18
	}
E 17
I 16
	/*
	 * Strip all but the rightmost UUCP host
	 * to prevent loops due to forwarding.
	 * Start searching leftward from the leftmost '@'.
	 *	a!b!c!d yields a short name of c!d
	 *	a!b!c!d@e yields a short name of c!d@e
	 *	e@a!b!c yields the same short name
	 */
#ifdef VDEBUG
printf("start='%s'\n", start);
#endif
	*shortp = start;			/* assume whole addr */
	if ((at = index(start, '@')) == NULL)	/* leftmost '@' */
		at = p;				/* if none, use end of addr */
	saveat = *at;
	*at = '\0';
	if ((bang = rindex(start, '!')) != NULL) {	/* rightmost '!' */
		char *bang2;

		*bang = '\0';
		if ((bang2 = rindex(start, '!')) != NULL) /* 2nd rightmost '!' */
			*shortp = bang2 + 1;		/* move past ! */
		*bang = '!';
	}
	*at = saveat;
#ifdef VDEBUG
printf("place='%s'\n", *shortp);
#endif

E 16
	/* return the sender address */
D 16
D 17
	return (&line[5]);
E 17
I 17
	return(strcpy(p, &buf[5]));
E 20
I 20
/*
 * nsearch --
 *	do a nice, slow, search of a string for a substring.
 */
static
nsearch(name, str)
	register char *name, *str;
{
	register int len;

	for (len = strlen(name); *str; ++str)
		if (*str == *name && !strncasecmp(name, str, len))
			return(1);
	return(0);
E 20
E 17
E 16
I 16
	return start;
E 16
}
D 17
/*
I 12
**  JUNKMAIL -- read the header and tell us if this is junk/bulk mail.
**
**	Parameters:
**		from -- the Return-Path of the sender.  We assume that
**			anything from "*-REQUEST@*" is bulk mail.
**
**	Returns:
**		TRUE -- if this is junk or bulk mail (that is, if the
**			sender shouldn't receive a response).
**		FALSE -- if the sender deserves a response.
**
**	Side Effects:
**		May read the header from standard input.  When this
**		returns the position on stdin is undefined.
*/
E 17

D 17
bool
E 17
I 17
/*
 * junkmail --
 *	read the header and return if automagic/junk/bulk mail
 */
static
E 17
D 20
junkmail(from)
D 17
	char *from;
E 17
I 17
	char	*from;
E 20
I 20
junkmail()
E 20
E 17
{
D 17
	register char *p;
	char buf[MAXLINE+1];
	extern char *index();
	extern char *rindex();
	extern bool sameword();
E 17
I 17
	static struct ignore {
		char	*name;
		int	len;
	} ignore[] = {
D 18
		"-REQUEST", 8, 		"Postmaster", 10,
E 18
I 18
D 20
		"-REQUEST", 8,		"Postmaster", 10,
E 18
		"uucp", 4,		"MAILER-DAEMON", 13,
		"MAILER", 6,		NULL, NULL,
E 20
I 20
		"-REQUEST", 8,	"Postmaster", 10,
		"uucp", 4,	"MAILER-DAEMON", 13,
		"MAILER", 6,	NULL, NULL,
E 20
	};
D 20
	register struct ignore	*I;
	register int	len;
	register char	*p;
	char	buf[MAXLINE],
D 18
		*index();
E 18
I 18
		*index(), *rindex();
E 20
I 20
	register struct ignore *cur;
	register int len;
	register char *p;
	char *index(), *rindex();
E 20
E 18
E 17

D 14
	/* test for sender == "*-REQUEST@*" */
E 14
I 14
D 17
	/* test for inhuman sender */
E 14
	p = rindex(from, '@');
D 14
	if (p != NULL && p > &from[8])
E 14
I 14
	if (p != NULL)
E 14
	{
		*p = '\0';
D 14
		if (sameword(&p[-8], "-REQUEST"))
E 14
I 14
		if (sameword(&p[-8],  "-REQUEST") ||
		    sameword(&p[-10], "Postmaster") ||
		    sameword(&p[-13], "MAILER-DAEMON"))
E 14
		{
			*p = '@';
			return (TRUE);
		}
		*p = '@';
	}
E 17
I 17
	/*
D 20
	 * This is mildly amusing, and I'm not positive it's right; what
	 * we're trying to do is find the "real" name of the sender.  I'm
	 * assuming that addresses will be some variant of:
E 20
I 20
	 * This is mildly amusing, and I'm not positive it's right; trying
	 * to find the "real" name of the sender, assuming that addresses
	 * will be some variant of:
E 20
	 *
D 18
	 * From ADDRESS
	 * From ADDRESS@seismo.css.gov
	 * From ADDRESS%site.BITNET@seismo.css.gov
	 * From site1!site2!ADDRESS@seismo.css.gov
E 18
I 18
D 20
	 * From SENDER
	 * From SENDER@seismo.css.gov
	 * From SENDER%site.BITNET@seismo.css.gov
	 * From site1!site2!SENDER@seismo.css.gov
E 18
	 *
	 * Therefore, the following search order:
E 20
I 20
	 * From site!site!SENDER%site.domain%site.domain@site.domain
E 20
	 */
	if (!(p = index(from, '%')))
D 18
		if (!(p = index(from, '@')))
			if (!(p = index(from, '!')))
				for (p = from; *p; ++p);
	len = p - from + 1;
E 18
I 18
		if (!(p = index(from, '@'))) {
			if (p = rindex(from, '!'))
				++p;
D 20
			for (p = from; *p; ++p);
E 20
I 20
			else
				p = from;
			for (; *p; ++p);
E 20
		}
	len = p - from;
E 18
D 20
	for (I = ignore; I->name; ++I)
D 18
		if (len >= I->len && !strcasencmp(I->name, p - I->len, I->len))
E 18
I 18
D 19
		if (len >= I->len && !strcasencmp(I->name, p - I->len, I->len)) {
E 19
I 19
		if (len >= I->len && !strncasecmp(I->name, p - I->len, I->len)) {
E 19
			if (debug)
				fprintf(stderr, "not sending to %s {%s}\n", from, I->name);
E 18
			return(YES);
I 18
		}
E 20
I 20
	for (cur = ignore; cur->name; ++cur)
		if (len >= cur->len && !strncasecmp(cur->name, p - cur->len, cur->len))
			return(1);
	return(0);
}
E 20
E 18
E 17

D 20
	/* read the header looking for a "Precedence:" line */
D 17
	while (fgets(buf, MAXLINE, stdin) != NULL && buf[0] != '\n')
	{
		/* should ignore case, but this is reasonably safe */
		if (strncmp(buf, "Precedence", 10) != 0 ||
		    !(buf[10] == ':' || buf[10] == ' ' || buf[10] == '\t'))
		{
E 17
I 17
	while (gets(buf) && *buf) {
D 19
		if (strcasencmp(buf, "Precedence", 10) ||
E 19
I 19
		if (strncasecmp(buf, "Precedence", 10) ||
E 19
		   buf[10] != ':' && buf[10] != ' ' && buf[10] != '\t')
E 17
			continue;
E 20
I 20
typedef struct {
	char	*dptr;
	int	dsize;
} DATUM;
E 20
D 17
		}
E 17

D 20
		/* find the value of this field */
D 17
		p = index(buf, ':');
		if (p == NULL)
E 17
I 17
		if (!(p = index(buf, ':')))
E 17
			continue;
D 17
		while (*++p != '\0' && isspace(*p))
E 17
I 17
		while (*++p && isspace(*p));
		if (!*p)
E 17
			continue;
E 20
I 20
typedef struct {
	time_t	sentdate;
} DBREC;
E 20
D 17
		if (*p == '\0')
			continue;
E 17

D 20
		/* see if it is "junk" or "bulk" */
D 17
		p[4] = '\0';
		if (sameword(p, "junk") || sameword(p, "bulk"))
			return (TRUE);
E 17
I 17
D 19
		if (!strcasencmp(p, "junk", 4) || !strcasecmp(p, "bulk", 4)) {
E 19
I 19
		if (!strncasecmp(p, "junk", 4) || !strncasecmp(p, "bulk", 4)) {
E 19
D 18
			puts("found junk or bulk");
E 18
I 18
			if (debug)
				fprintf(stderr, "not sending to %s {junk/bulk}\n", from);
E 18
			return(YES);
		}
E 17
	}
D 17
	return (FALSE);
E 17
I 17
	return(NO);
E 17
}
D 17
/*
E 12
**  KNOWS -- predicate telling if user has already been informed.
**
**	Parameters:
**		user -- the user who sent this message.
**
**	Returns:
**		TRUE if 'user' has already been informed that the
**			recipient is on vacation.
**		FALSE otherwise.
**
**	Side Effects:
**		none.
*/
E 17

E 20
D 3
# define ONEWEEK	(60L*60L*24L*7L)

E 3
D 17
bool
E 17
I 17
/*
D 20
 * knows --
E 20
I 20
 * recent --
E 20
 *	find out if user has gotten a vacation message recently.
 */
static
E 17
D 20
knows(user)
D 16
D 17
	char *user;
E 17
I 17
	char	*user;
E 20
I 20
recent()
E 20
E 17
E 16
I 16
char *user;
E 16
{
D 17
	DATUM k, d;
D 16
	long now;
E 16
I 16
	struct dbrec ldbrec;
E 16
I 15
	auto long then;
E 17
I 17
D 20
	DATUM	k, d,
		fetch();
	time_t	now, then,
		time();
E 20
I 20
	DATUM k, d, fetch();
	time_t now, then, time();
E 20
E 17
E 15

D 16
D 17
	time(&now);
E 17
E 16
D 20
	k.dptr = user;
	k.dsize = strlen(user) + 1;
E 20
I 20
	k.dptr = from;
	k.dsize = strlen(from) + 1;
E 20
	d = fetch(k);
D 3
	if (d.dptr == NULL || ((struct dbrec *) d.dptr)->sentdate + ONEWEEK < now)
E 3
I 3
D 15
D 16
	if (d.dptr == NULL || ((struct dbrec *) d.dptr)->sentdate + Timeout < now)
E 15
I 15
D 17
	if (d.dptr == NULL)
		return (FALSE);
	
	/* be careful on 68k's and others with alignment restrictions */
	bcopy((char *) &((struct dbrec *) d.dptr)->sentdate, (char *) &then, sizeof then);
	if (then + Timeout < now)
E 15
E 3
		return (FALSE);
	return (TRUE);
E 17
I 17
	if (d.dptr) {
D 20
		/*
		 * be careful on 68k's and others with alignment
		 * restrictions
		 */
E 20
I 20
		/* be careful on machines with alignment restrictions */
E 20
		bcopy((char *)&((DBREC *)d.dptr)->sentdate, (char *)&then, sizeof(then));
		(void)time(&now);
D 18
		if (!then || then + PERIOD > now)
E 18
I 18
D 20
		if (!then || then + PERIOD > now) {
			if (debug)
				fprintf(stderr, "not sending to %s {%s}\n",user, then ? "not timed out" : "ignored address");
E 18
			return(YES);
I 18
		}
E 20
I 20
		if (!then || then + PERIOD > now)
			return(1);
E 20
E 18
	}
D 20
	return(NO);
E 20
I 20
	return(0);
E 20
E 17
E 16
I 16
	if (d.dptr == NULL)
		return FALSE;
	bcopy(d.dptr, (char *)&ldbrec, sizeof ldbrec);	/* realign data */
	return ldbrec.sentdate + Timeout >= time((time_t *)0);
E 16
}
I 16

#ifndef VMUNIX
bcopy(from, to, size)
register char *to, *from;
register unsigned size;
{
	while (size-- > 0)
		*to++ = *from++;
}
#endif
E 16
D 17
/*
**  SETKNOWS -- set that this user knows about the vacation.
**
**	Parameters:
**		user -- the user who should be marked.
**
**	Returns:
**		none.
**
**	Side Effects:
**		The dbm file is updated as appropriate.
*/
E 17

D 17
setknows(user)
	char *user;
E 17
I 17
/*
D 20
 * setknows --
E 20
I 20
 * setreply --
E 20
 *	store that this user knows about the vacation.
 */
static
D 20
setknows(user, forever)
	char	*user;
	int	forever;
E 20
I 20
setreply()
E 20
E 17
{
D 8
	register int i;
E 8
D 17
	DATUM k, d;
	struct dbrec xrec;
E 17
I 17
D 20
	DBREC	xrec;
	DATUM	k, d;
	time_t	time();
E 20
I 20
	DBREC xrec;
	DATUM k, d;
	time_t time();
E 20
E 17

D 20
	k.dptr = user;
	k.dsize = strlen(user) + 1;
D 17
	time(&xrec.sentdate);
	d.dptr = (char *) &xrec;
	d.dsize = sizeof xrec;
E 17
I 17
	if (forever)
		/* zero is the flag value meaning *never* reply */
		xrec.sentdate = 0;
	else
		(void)time(&xrec.sentdate);
E 20
I 20
	k.dptr = from;
	k.dsize = strlen(from) + 1;
	(void)time(&xrec.sentdate);
E 20
	d.dptr = (char *)&xrec;
	d.dsize = sizeof(xrec);
E 17
	store(k, d);
}
D 17
/*
**  SENDMESSAGE -- send a message to a particular user.
**
**	Parameters:
**		msgf -- filename containing the message.
**		user -- user who should receive it.
**
**	Returns:
**		none.
**
**	Side Effects:
**		sends mail to 'user' using /usr/lib/sendmail.
*/
E 17

D 6
sendmessage(msgf, user)
E 6
I 6
D 17
sendmessage(msgf, user, myname)
E 6
	char *msgf;
	char *user;
I 6
	char *myname;
E 17
I 17
/*
 * sendmessage --
D 18
 *	exec sendmail to send the vacation file to the user "user".
E 18
I 18
D 20
 *	exec sendmail to send the vacation file to "user".
E 20
I 20
 *	exec sendmail to send the vacation file to sender
E 20
E 18
 */
static
D 20
sendmessage(user, myname)
	char	*user, *myname;
E 20
I 20
sendmessage(myname)
	char *myname;
E 20
E 17
E 6
{
D 17
	FILE *f;

	/* find the message to send */
	f = freopen(msgf, "r", stdin);
	if (f == NULL)
	{
		f = freopen("/usr/lib/vacation.def", "r", stdin);
		if (f == NULL)
			syserr("No message to send");
E 17
I 17
D 18
	if (debug)
		printf("sending {%s} to {%s}\n", VMSG, user);
	else {
		if (!freopen(VMSG, "r", stdin)) {
			fputs("vacation: no message to send.\n", stderr);
			exit(1);
		}
		execl("/usr/lib/sendmail", "sendmail", "-f", myname, user, NULL);
		fputs("vacation: cannot exec /usr/lib/sendmail\n", stderr);
		exit(1);
E 18
I 18
D 20
	if (debug) {
		fprintf(stderr, "sending {%s} to {%s}\n", VMSG, user);
		return;
E 18
E 17
	}
E 20
I 18
	if (!freopen(VMSG, "r", stdin)) {
D 20
		fprintf(stderr, "vacation: no ~%s/%s file.\n", myname, VMSG);
E 20
		syslog(LOG_ERR, "vacation: no ~%s/%s file.\n", myname, VMSG);
D 22
		exit(EX_NOINPUT);
E 22
I 22
		exit(1);
E 22
	}
D 20
	execl("/usr/lib/sendmail", "sendmail", "-f", myname, user, NULL);
	fprintf(stderr, "vacation: can't exec /usr/lib/sendmail.\n");
E 20
I 20
	execl("/usr/lib/sendmail", "sendmail", "-f", myname, from, NULL);
E 20
	syslog(LOG_ERR, "vacation: can't exec /usr/lib/sendmail.\n");
D 22
	exit(EX_OSERR);
E 22
I 22
	exit(1);
E 22
E 18
D 17

D 2
	execl("/usr/lib/sendmail", "sendmail", user, NULL);
E 2
I 2
D 6
	execl("/usr/lib/sendmail", "sendmail", "-n", user, NULL);
E 6
I 6
D 9
	execl("/usr/lib/sendmail", "sendmail", "-f", myname, "-n", user, NULL);
E 9
I 9
	execl("/usr/lib/sendmail", "sendmail", "-f", myname, user, NULL);
E 9
E 6
E 2
	syserr("Cannot exec /usr/lib/sendmail");
E 17
I 6
}
D 17
/*
**  INITIALIZE -- initialize the database before leaving for vacation
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Initializes the files .vacation.{pag,dir} in the
**		caller's home directory.
*/
E 17

I 17
/*
 * initialize --
D 20
 *	initialize the database
E 20
I 20
 *	initialize the dbm database
E 20
 */
static
E 17
initialize()
{
I 18
D 20
	extern int	errno;
	extern char	*sys_errlist[];
E 18
D 17
	char *homedir;
	char buf[MAXLINE];
I 11
	extern char *getenv();
E 17
I 17
	FILE	*fp;
	int	fd;
E 20
I 20
	extern int errno;
	extern char *sys_errlist[];
	int fd;
E 20
E 17
E 11

D 17
	setgid(getgid());
	setuid(getuid());
	homedir = getenv("HOME");
	if (homedir == NULL)
		syserr("No home!");
D 7
	strcpy(buf, homedir);
	strcat(buf, "/.vacation.dir");
E 7
I 7
	(void) strcpy(buf, homedir);
	(void) strcat(buf, "/.vacation.dir");
E 7
	if (close(creat(buf, 0644)) < 0)
		syserr("Cannot create %s", buf);
D 7
	strcpy(buf, homedir);
	strcat(buf, "/.vacation.pag");
E 7
I 7
	(void) strcpy(buf, homedir);
	(void) strcat(buf, "/.vacation.pag");
E 7
	if (close(creat(buf, 0644)) < 0)
		syserr("Cannot create %s", buf);
E 6
}
/*
**  USRERR -- print user error
**
**	Parameters:
**		f -- format.
**		p -- first parameter.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/
E 17
I 17
	if ((fd = open(VDIR, O_WRONLY|O_CREAT|O_TRUNC, 0644)) < 0) {
D 18
		perror("vacation: .vacation.dir");
		exit(1);
E 18
I 18
D 20
		fprintf(stderr, "vacation: %s: %s\n", VDIR, sys_errlist[errno]);
E 20
		syslog(LOG_ERR, "vacation: %s: %s\n", VDIR, sys_errlist[errno]);
D 22
		exit(EX_OSERR);
E 22
I 22
		exit(1);
E 22
E 18
	}
	(void)close(fd);
	if ((fd = open(VPAG, O_WRONLY|O_CREAT|O_TRUNC, 0644)) < 0) {
D 18
		perror("vacation: .vacation.page");
		exit(1);
E 18
I 18
D 20
		fprintf(stderr, "vacation: %s: %s\n", VPAG, sys_errlist[errno]);
E 20
		syslog(LOG_ERR, "vacation: %s: %s\n", VPAG, sys_errlist[errno]);
D 22
		exit(EX_OSERR);
E 22
I 22
		exit(1);
E 22
E 18
	}
	(void)close(fd);
	dbminit(VACAT);
D 20
	if (fp = fopen(VIGN, "r")) {
D 18
		char	buf[MAXLINE];
E 18
I 18
		char	buf[MAXLINE],
			*index();
E 18
E 17

I 16
/* VARARGS 1 */
E 16
D 17
usrerr(f, p)
	char *f;
	char *p;
{
	fprintf(stderr, "vacation: ");
	_doprnt(f, &p, stderr);
	fprintf(stderr, "\n");
}
/*
**  SYSERR -- print system error
**
**	Parameters:
**		f -- format.
**		p -- first parameter.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

I 16
/* VARARGS 1 */
E 16
syserr(f, p)
	char *f;
	char *p;
{
	fprintf(stderr, "vacation: ");
	_doprnt(f, &p, stderr);
	fprintf(stderr, "\n");
	exit(EX_USAGE);
I 8
}
/*
**  NEWSTR -- copy a string
**
**	Parameters:
**		s -- the string to copy.
**
**	Returns:
**		A copy of the string.
**
**	Side Effects:
**		none.
*/

char *
newstr(s)
	char *s;
{
	char *p;
I 11
	extern char *malloc();
E 11

D 16
	p = malloc(strlen(s) + 1);
E 16
I 16
	p = malloc((unsigned)strlen(s) + 1);
E 16
	if (p == NULL)
	{
		syserr("newstr: cannot alloc memory");
		exit(EX_OSERR);
E 17
I 17
		while (fgets(buf, sizeof(buf), fp)) {
			*(index(buf, '\n')) = EOS;
			setknows(buf, YES);
		}
		(void)fclose(fp);
E 17
	}
D 17
	strcpy(p, s);
D 16
	return (p);
E 17
E 16
I 16
	return p;
E 16
I 12
}
D 17
/*
**  SAMEWORD -- return TRUE if the words are the same
**
**	Ignores case.
**
**	Parameters:
**		a, b -- the words to compare.
**
**	Returns:
**		TRUE if a & b match exactly (modulo case)
**		FALSE otherwise.
**
**	Side Effects:
**		none.
*/
E 17

D 17
bool
sameword(a, b)
	register char *a, *b;
E 17
I 17
/*
 * usage --
 *	print out a usage message and die
 */
static
usage()
E 17
{
D 17
	char ca, cb;

	do
	{
		ca = *a++;
		cb = *b++;
		if (isascii(ca) && isupper(ca))
			ca = ca - 'A' + 'a';
		if (isascii(cb) && isupper(cb))
			cb = cb - 'A' + 'a';
	} while (ca != '\0' && ca == cb);
	return (ca == cb);
E 17
I 17
D 18
	fputs("vacation [-i] username\n", stderr);
	exit(1);
E 18
I 18
	uid_t	getuid();

	fputs("usage: vacation [-i] login\n", stderr);
	syslog(LOG_ERR, "uid %u: usage: vacation [-i] login\n", getuid());
	exit(EX_USAGE);
E 20
E 18
E 17
E 12
E 8
I 3
}
D 4
/*
**  CONVTIME -- convert time
**
**	Parameters:
**		p -- pointer to ascii time.
**
**	Returns:
**		time in seconds.
**
**	Side Effects:
**		none.
*/

long
convtime(p)
	char *p;
{
	register long t;

	t = 0;
	while (isdigit(*p))
		t = t * 10 + (*p++ - '0');
	switch (*p)
	{
	  case 'w':		/* weeks */
		t *= 7;

	  case 'd':		/* days */
	  case '\0':
	  default:
		t *= 24;

	  case 'h':		/* hours */
		t *= 60;

	  case 'm':		/* minutes */
		t *= 60;

	  case 's':		/* seconds */
		break;
	}

	return (t);
E 3
}
E 4
E 1
