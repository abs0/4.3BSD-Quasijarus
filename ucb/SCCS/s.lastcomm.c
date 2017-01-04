h64609
s 00010/00005/00277
d D 5.6 88/06/29 21:50:49 bostic 20 19
c install approved copyright notice
e
s 00034/00056/00248
d D 5.5 88/04/20 14:17:03 bostic 19 18
c written by Len Edmondson, add Berkeley specific header; fix flagbits
c routine to squeeze flags together, output dash if no flags; replace getname
c routine with simpler one; bug report 4.2BSD/ucb/227
e
s 00033/00017/00271
d D 5.4 88/03/08 21:45:43 bostic 18 17
c add a -f option to select a file
e
s 00022/00015/00266
d D 5.3 87/05/15 07:50:43 bostic 17 16
c NULL pointers, negative UIDs; bug report 4.3BSD/ucb/95
e
s 00003/00002/00278
d D 5.2 86/05/04 16:22:16 lepreau 16 15
c don't print trailing garbage after full length ac_comm's.
e
s 00014/00002/00266
d D 5.1 85/05/31 09:18:20 dist 15 14
c Add copyright
e
s 00006/00005/00262
d D 4.14 85/02/04 09:41:46 ralph 14 13
c fixes from donn@utah-cs.
e
s 00003/00003/00264
d D 4.13 85/01/22 10:23:21 ralph 13 12
c minor speedups.
e
s 00002/00002/00265
d D 4.12 84/12/12 09:20:21 karels 12 11
c use AHZ
e
s 00002/00003/00265
d D 4.11 84/07/15 01:21:26 sam 11 10
c convert to revised accounting
e
s 00002/00002/00266
d D 4.10 83/12/02 10:02:35 ralph 10 9
c didn't show most recent commands.
e
s 00002/00001/00266
d D 4.9 83/09/08 09:41:59 ralph 9 8
c getdev() always called setupdevs() so memory filled up & slow.
e
s 00002/00002/00265
d D 4.8 83/08/19 16:17:19 sam 8 7
c incorrect max login name size
e
s 00001/00001/00266
d D 4.7 83/07/01 02:54:16 sam 7 6
c include fix
e
s 00127/00076/00140
d D 4.6 83/06/18 14:09:36 sam 6 5
c rewrite to handle large uids and make dev naming self contained
e
s 00098/00166/00118
d D 4.5 83/04/04 21:34:38 sam 5 4
c rewrite
e
s 00145/00022/00139
d D 4.4 82/07/17 19:03:19 kre 4 3
c report tty command was started from, & accounting flags;
c allow "lastcomm ttyXX" as well as "lastcomm user" and "lastcomm cmd".
e
s 00001/00001/00160
d D 4.3 80/12/14 18:11:00 mark 3 2
c fixed previous fix
e
s 00002/00001/00159
d D 4.2 80/12/14 18:00:13 mark 2 1
c fixed handling of multiple entries in passwd: now uses first instead of last
e
s 00160/00000/00000
d D 4.1 80/10/01 17:27:16 bill 1 0
c date and time created 80/10/01 17:27:16 by bill
e
u
U
t
T
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 19
 */

E 15
I 5
#ifndef lint
E 5
I 1
D 4
static char *sccsid = "%W% (Berkeley) %G%";
#
E 4
I 4
D 6
static char *sccsid = "%W% (Berkeley) %E%";
E 6
I 6
D 15
static char *sccsid = "%W% (Berkeley) %G%";
E 6
I 5
#endif
E 15
I 15
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19
E 15
E 5
E 4

/*
 * last command
 */
I 5
D 6
#include <stdio.h>
E 6
#include <sys/param.h>
#include <sys/acct.h>
D 6
#include <sys/dir.h>
#include <signal.h>
E 6
I 6
#include <sys/file.h>
D 19

#include <stdio.h>
E 6
#include <pwd.h>
E 19
D 7
#include <stat.h>
E 7
I 7
#include <sys/stat.h>
E 7
#include <utmp.h>
#include <struct.h>
#include <ctype.h>
I 19
#include <stdio.h>
E 19
E 5

D 5
# include <stdio.h>
D 4
# include <sys/types.h>
E 4
I 4
# include <sys/param.h>
E 4
# include <sys/acct.h>
I 4
# include <sys/dir.h>
E 4
# include <signal.h>
# include <pwd.h>
# include <stat.h>
I 4
# include <utmp.h>
# include <struct.h>
E 5
I 5
D 6
#define N_USER		4000		/* highest alloc user # */
#define N_DEVS		43		/* hash value for device names */
#define NDEVS		500		/* max number of file names in /dev */
E 6
I 6
struct	acct buf[DEV_BSIZE / sizeof (struct acct)];
E 6
E 5
E 4

D 4
# define N_USER		1000
E 4
I 4
D 5
# define N_USER		4000		/* highest alloc user # */
# define N_DEVS		43		/* hash value for device names */
# define NDEVS		500		/* max number of file names in /dev */
E 5
I 5
D 6
struct	acct acct_buff[BUFSIZ / sizeof (struct acct)];
char	user_list[N_USER][fldsiz(utmp, ut_name) + 1];
E 5
E 4

D 5
struct acct	acct_buff [BUFSIZ / sizeof (struct acct)];

D 4
char	yes   = 1,
	no    = 0,
E 4
I 4
char	user_list [N_USER][fldsiz(utmp, ut_name) + 1];
E 4

E 5
D 4
	user_list [1000][9];
E 4
I 4
struct	devhash {
	dev_t	dev_dev;
	char	dev_name [fldsiz(utmp, ut_line) + 1];
	struct	devhash * dev_nxt;
D 5
}
	* dev_hash [ N_DEVS ],
	* dev_chain ;
# define HASH(d)	(((int) d) % N_DEVS)
E 5
I 5
};
struct	devhash *dev_hash[N_DEVS];
struct	devhash *dev_chain ;
#define HASH(d)	(((int) d) % N_DEVS)
E 5
E 4

time_t	expand ();
E 6
I 6
time_t	expand();
E 6
I 4
D 5
char	* flagbits();
char	* tername();
E 5
I 5
char	*flagbits();
D 6
char	*ttyname();
E 6
I 6
char	*getname();
char	*getdev();
E 6
E 5
E 4

D 5
struct passwd
	*passwd,
	*getpwent ();

E 5
I 5
D 6
struct	passwd *passwd, *getpwent ();
E 5
struct stat stat_buff;

E 6
I 4
D 5
# define equal(a, b)		(strcmp(a, b) == 0)

E 4
main (argc, argv)
char **argv;
E 5
I 5
main(argc, argv)
I 18
	int argc;
E 18
	char *argv[];
E 5
{
D 5
	char	acct_desc,
		*p;
E 5
I 5
D 6
	char acct_desc, *p;
	long i, j, i_block, n_blocks, n_byte, n_entry, x;
E 6
I 6
D 18
	register int bn, cc;
E 18
I 18
	extern int optind;
	extern char *optarg;
E 18
E 6
	register struct acct *acp;
I 6
D 18
	int fd;
E 18
I 18
	register int bn, cc;
E 18
	struct stat sb;
I 18
	int ch, fd;
	char *acctfile, *strcpy(), *ctime();
E 18
I 17
	long lseek();
D 18
	char *strcpy(), *ctime();
E 18
E 17
E 6
E 5

D 5
	long	i,
		j,
		i_block,
		n_blocks,
		n_byte,
		n_entry;

	float	x;

/*
 * set up user names
 */
	while (passwd = getpwent ())
	{
D 2
		move (passwd->pw_name, user_list [passwd->pw_uid]);
E 2
I 2
D 3
		if (user_list[passwd->pw_uid][0])
E 3
I 3
		if (user_list[passwd->pw_uid][0]==0)
E 3
			move (passwd->pw_name, user_list [passwd->pw_uid]);
E 2
	}

I 4
 /*
  * find dev numbers corresponding to names in /dev
  */
E 5
I 5
D 6
	/*
	 * Set up user names
	 */
	while (passwd = getpwent())
		if (user_list[passwd->pw_uid][0] == 0)
			strcpy(user_list[passwd->pw_uid], passwd->pw_name);
	/*
	 * Find dev numbers corresponding to names in /dev
	 */
E 5
	setupdevs();
D 5

E 4
	acct_desc = open ("/usr/adm/acct", 0);
	if (acct_desc < 0)
	{
		perror ("/usr/adm/acct");
		return;
E 5
I 5
	acct_desc = open("/usr/adm/acct", 0);
	if (acct_desc < 0) {
E 6
I 6
D 18
	fd = open("/usr/adm/acct", O_RDONLY);
E 18
I 18
	acctfile = NULL;
	while ((ch = getopt(argc, argv, "f:")) != EOF)
		switch((char)ch) {
		case 'f':
			acctfile = optarg;
			break;
		case '?':
		default:
			fputs("lastcomm [ -f file ]\n", stderr);
			exit(1);
		}
	argv += optind;
	if (!acctfile)
		acctfile = "/usr/adm/acct";
	fd = open(acctfile, O_RDONLY);
E 18
	if (fd < 0) {
E 6
D 18
		perror("/usr/adm/acct");
E 18
I 18
		perror(acctfile);
E 18
		exit(1);
E 5
	}
D 5
	fstat (acct_desc, &stat_buff);
E 5
I 5
D 6
	fstat(acct_desc, &stat_buff);
E 5
	n_blocks = (stat_buff.st_size + BUFSIZ - 1) / BUFSIZ;
E 6
I 6
D 18
	fstat(fd, &sb);
E 18
I 18
	(void)fstat(fd, &sb);
E 18
D 10
	for (bn = btodb(sb.st_size) - 1; bn >= 0; bn--) {
		lseek(fd, bn * DEV_BSIZE, L_SET);
E 10
I 10
	for (bn = btodb(sb.st_size); bn >= 0; bn--) {
D 17
		lseek(fd, dbtob(bn), L_SET);
E 17
I 17
		(void)lseek(fd, (off_t)dbtob(bn), L_SET);
E 17
E 10
		cc = read(fd, buf, DEV_BSIZE);
		if (cc < 0) {
			perror("read");
			break;
		}
		acp = buf + (cc / sizeof (buf[0])) - 1;
		for (; acp >= buf; acp--) {
			register char *cp;
D 13
			time_t x =
			    expand(acp->ac_utime) + expand(acp->ac_stime);
E 13
I 13
			time_t x;
E 13
E 6

D 6
	/*
D 5
	 * read one block's worth
E 5
I 5
	 * Read one block's worth
E 5
	 */
D 5
	for (i_block = n_blocks - 1; i_block >= 0; i_block--)
	{
		lseek (acct_desc, i_block * BUFSIZ, 0);
		n_byte = read (acct_desc, acct_buff, BUFSIZ);
		n_entry = n_byte / sizeof acct_buff [0];
		for (i = n_entry - 1; i >= 0; i--)
		{
D 4
			if (!*user_list [acct_buff [i].ac_uid]) continue;
E 4
I 4
			if (!*user_list [acct_buff [i].ac_uid])
E 5
I 5
	for (i_block = n_blocks - 1; i_block >= 0; i_block--) {
		lseek(acct_desc, i_block * BUFSIZ, 0);
		n_byte = read(acct_desc, acct_buff, BUFSIZ);
		n_entry = n_byte / sizeof acct_buff[0];
		for (acp = acct_buff + n_entry - 1; acp >= acct_buff; acp--) {
			if (*user_list[acp->ac_uid] == '\0')
E 5
				continue;
E 4
D 5
			/*
			 * get the times
			 */
			x =	expand (acct_buff [i].ac_utime)
				+
				expand (acct_buff [i].ac_stime);
			/*
			 * null terminate the command name
			 */
			acct_buff [i].ac_comm [10] = 0;
			/*
			 * replace missing command names with question marks
			 */
			if (!*acct_buff [i].ac_comm)
			{
				move ("?", acct_buff [i].ac_comm);
			}
			/*
			 * replace control characters with question marks
			 */
			for (p = acct_buff [i].ac_comm; *p; p++)
			{
D 4
				if (*p < '!' || '~' < *p) *p = '?';
E 4
I 4
				if (*p < '!' || '~' < *p)
E 5
I 5
			x = expand(acp->ac_utime) + expand(acp->ac_stime);
E 6
D 14
			acp->ac_comm[10] = '\0';
			if (*acp->ac_comm == '\0')
E 14
I 14
			if (acp->ac_comm[0] == '\0')
E 14
D 18
				strcpy(acp->ac_comm, "?");
E 18
I 18
				(void)strcpy(acp->ac_comm, "?");
E 18
D 6
			for (p = acp->ac_comm; *p; p++)
				if (iscntrl(*p))
E 5
					*p = '?';
E 6
I 6
D 14
			for (cp = acp->ac_comm; *cp; cp++)
				if (iscntrl(*cp))
E 14
I 14
			for (cp = &acp->ac_comm[0];
			     cp < &acp->ac_comm[fldsiz(acct, ac_comm)] && *cp;
			     cp++)
				if (!isascii(*cp) || iscntrl(*cp))
E 14
					*cp = '?';
E 6
E 4
D 5
			}
			for (j = 1; j < argc; j++)
			{
				if
				(
					equal (acct_buff [i].ac_comm, argv [j])
					||
					equal
					(
D 4
					user_list [acct_buff [i].ac_uid],
E 4
I 4
						user_list[acct_buff[i].ac_uid],
E 4
						argv [j]
					)
I 4
					||
					equal
					(
						tername(acct_buff[i].ac_tty),
						argv[j]
					)
E 4
				)
				{
					break;
				}
			}
			if (argc == 1 || j != argc)
			{
				printf
				(
D 4
					"%-10s %-8s %6.2f     %.16s\n",
					acct_buff [i].ac_comm,
					user_list [acct_buff [i].ac_uid],
					x / 60.0,
					ctime (&acct_buff [i].ac_btime)
E 4
I 4
					"%-*s %s %-*s %-*s %6.2f     %.16s\n"
					, fldsiz(acct, ac_comm)
					, acct_buff [i].ac_comm
					, flagbits(acct_buff [i].ac_flag)
					, fldsiz(utmp, ut_name)
					, user_list [acct_buff [i].ac_uid]
					, fldsiz(utmp, ut_line)
					, tername(acct_buff [i].ac_tty)
					, x / 60.0
					, ctime (&acct_buff [i].ac_btime)
E 4
				);
			}
E 5
I 5
D 13
			if (!ok(argc, argv, acp) && argc != 1)
E 13
I 13
D 18
			if (argc > 1 && !ok(argc, argv, acp))
E 18
I 18
			if (*argv && !ok(argv, acp))
E 18
E 13
				continue;
I 13
			x = expand(acp->ac_utime) + expand(acp->ac_stime);
E 13
D 11
			printf("%-*s %s %-*s %-*s %4d sec%s %.16s\n",
E 11
I 11
D 12
			printf("%-*s %s %-*s %-*s %6.1f secs %.16s\n",
E 12
I 12
D 16
			printf("%-*s %s %-*s %-*s %6.2f secs %.16s\n",
E 12
E 11
				fldsiz(acct, ac_comm), acp->ac_comm,
E 16
I 16
			printf("%-*.*s %s %-*s %-*s %6.2f secs %.16s\n",
D 17
				fldsiz(acct, ac_comm), fldsiz(acct, ac_comm),
				acp->ac_comm,
E 16
				flagbits(acp->ac_flag),
D 6
				fldsiz(utmp, ut_name), user_list[acp->ac_uid],
				fldsiz(utmp, ut_line), ttyname(acp->ac_tty),
E 6
I 6
				fldsiz(utmp, ut_name), getname(acp->ac_uid),
E 17
I 17
				fldsiz(acct, ac_comm),
				fldsiz(acct, ac_comm),
				acp->ac_comm, flagbits(acp->ac_flag),
				fldsiz(utmp, ut_name),
				(cp = getname(acp->ac_uid)) ? cp : "",
E 17
				fldsiz(utmp, ut_line), getdev(acp->ac_tty),
E 6
D 11
				x, x > 1 || x == 0 ? "s" : " ",
				ctime(&acp->ac_btime));
E 11
I 11
D 12
				x / 64.0, ctime(&acp->ac_btime));
E 12
I 12
				x / (double)AHZ, ctime(&acp->ac_btime));
E 12
E 11
E 5
		}
	}
}

time_t
expand (t)
D 5
unsigned t;
E 5
I 5
	unsigned t;
E 5
{
	register time_t nt;

	nt = t & 017777;
	t >>= 13;
D 5
	while (t)
	{
E 5
I 5
	while (t) {
E 5
		t--;
		nt <<= 3;
	}
	return (nt);
}

D 5
move (a, b)
char *a, *b;
{
D 4
	while (*b++ = *a++);
E 4
I 4
	while (*b++ = *a++)
		;
E 4
}

E 5
D 4
equal (a, b)
char *a, *b;
E 4
I 4
char *
flagbits(f)
D 5
register int f;
E 5
I 5
	register int f;
E 5
E 4
{
D 4
	for (;; a++, b++)
	{
		if (*a != *b) return no;
		if (!*a)      return yes;
E 4
I 4
D 19
	register int i = 0;
E 19
	static char flags[20];
I 19
	char *p, *strcpy();
E 19

D 5
# define BIT(flag, ch)	flags[i++] = ( f & flag ) ? ch : ' '

	BIT( ASU,	'S');
	BIT( AFORK,	'F');
	BIT( ACOMPAT,	'C');
	BIT( ACORE,	'D');
	BIT( AXSIG,	'X');

E 5
I 5
D 19
#define BIT(flag, ch)	flags[i++] = (f & flag) ? ch : ' '
E 19
I 19
#define	BIT(flag, ch)	if (f & flag) *p++ = ch;
	p = strcpy(flags, "-    ");
E 19
	BIT(ASU, 'S');
	BIT(AFORK, 'F');
	BIT(ACOMPAT, 'C');
	BIT(ACORE, 'D');
	BIT(AXSIG, 'X');
E 5
D 19
	flags[i] = '\0';
E 19
D 5

	return(flags);
E 5
I 5
	return (flags);
E 5
}

I 6
D 18
ok(argc, argv, acp)
	register int argc;
E 18
I 18
ok(argv, acp)
E 18
	register char *argv[];
	register struct acct *acp;
{
D 18
	register int j;
E 18
I 17
	register char *cp;
E 17

D 18
	for (j = 1; j < argc; j++)
D 17
		if (strcmp(getname(acp->ac_uid), argv[j]) &&
		    strcmp(getdev(acp->ac_tty), argv[j]) &&
E 17
I 17
		if ((!(cp = getname(acp->ac_uid)) || strcmp(cp, argv[j])) &&
		    (!(cp = getdev(acp->ac_tty)) || strcmp(cp, argv[j])) &&
E 17
D 14
		    strcmp(acp->ac_comm, argv[j]))
E 14
I 14
		    strncmp(acp->ac_comm, argv[j], fldsiz(acct, ac_comm)))
E 14
			break;
	return (j == argc);
E 18
I 18
	do {
		if ((cp = getname(acp->ac_uid)) && !strcmp(cp, *argv) ||
		    (cp = getdev(acp->ac_tty)) && !strcmp(cp, *argv) ||
		    !strncmp(acp->ac_comm, *argv, fldsiz(acct, ac_comm)))
			return(1);
	} while (*++argv);
	return(0);
E 18
}

/* should be done with nameserver or database */

D 19
struct	utmp utmp;
E 19
I 19
#include <pwd.h>
E 19

D 19
#define NUID	2048
E 19
I 19
struct	utmp utmp;
E 19
#define	NMAX	(sizeof (utmp.ut_name))
I 19
#define SCPYN(a, b)	strncpy(a, b, NMAX)
E 19

D 19
char	names[NUID][NMAX+1];
char	outrangename[NMAX+1];
int	outrangeuid = -1;
E 19
I 19
#define NCACHE	64		/* power of 2 */
#define CAMASK	NCACHE - 1
E 19

char *
getname(uid)
I 17
	uid_t uid;
E 17
{
I 19
	extern int _pw_stayopen;
	static struct ncache {
		uid_t	uid;
		char	name[NMAX+1];
	} c_uid[NCACHE];
E 19
	register struct passwd *pw;
D 19
	static init;
	struct passwd *getpwent();
E 19
I 19
	register struct ncache *cp;
E 19

D 17
	if (uid >= 0 && uid < NUID && names[uid][0])
E 17
I 17
D 19
	if (uid < NUID && names[uid][0])
E 17
		return (&names[uid][0]);
D 17
	if (uid >= 0 && uid == outrangeuid)
E 17
I 17
	if (uid == outrangeuid)
E 17
		return (outrangename);
	if (init == 2) {
		if (uid < NUID)
			return (0);
		setpwent();
		while (pw = getpwent()) {
			if (pw->pw_uid != uid)
				continue;
			outrangeuid = pw->pw_uid;
D 8
			strncpy(outrangename, pw->pw_name, NUID);
E 8
I 8
			strncpy(outrangename, pw->pw_name, NMAX);
E 8
			endpwent();
			return (outrangename);
		}
		endpwent();
		return (0);
	}
	if (init == 0)
		setpwent(), init = 1;
	while (pw = getpwent()) {
		if (pw->pw_uid < 0 || pw->pw_uid >= NUID) {
			if (pw->pw_uid == uid) {
				outrangeuid = pw->pw_uid;
D 8
				strncpy(outrangename, pw->pw_name, NUID);
E 8
I 8
				strncpy(outrangename, pw->pw_name, NMAX);
E 8
				return (outrangename);
			}
			continue;
		}
		if (names[pw->pw_uid][0])
			continue;
		strncpy(names[pw->pw_uid], pw->pw_name, NMAX);
		if (pw->pw_uid == uid)
			return (&names[uid][0]);
	}
	init = 2;
	endpwent();
	return (0);
E 19
I 19
	_pw_stayopen = 1;
	cp = c_uid + (uid & CAMASK);
	if (cp->uid == uid && *cp->name)
		return(cp->name);
	if (!(pw = getpwuid(uid)))
		return((char *)0);
	cp->uid = uid;
	SCPYN(cp->name, pw->pw_name);
	return(cp->name);
E 19
}

#include <sys/dir.h>

#define N_DEVS		43		/* hash value for device names */
#define NDEVS		500		/* max number of file names in /dev */

struct	devhash {
	dev_t	dev_dev;
	char	dev_name [fldsiz(utmp, ut_line) + 1];
	struct	devhash * dev_nxt;
};
struct	devhash *dev_hash[N_DEVS];
struct	devhash *dev_chain;
#define HASH(d)	(((int) d) % N_DEVS)

E 6
setupdevs()
{
	register DIR * fd;
	register struct devhash * hashtab;
	register ndevs = NDEVS;
	struct direct * dp;
I 17
	char *malloc();
E 17

D 17
	if ((fd = opendir("/dev")) == NULL) {
		perror("/dev");
		return;
E 4
	}
E 17
I 17
	/*NOSTRICT*/
E 17
I 4
D 5

E 5
D 6
	if ((hashtab = (struct devhash *)malloc(NDEVS * sizeof(struct devhash)))
	    == (struct devhash *) 0) {
E 6
I 6
	hashtab = (struct devhash *)malloc(NDEVS * sizeof(struct devhash));
	if (hashtab == (struct devhash *)0) {
E 6
D 17
		fprintf(stderr, "No mem for dev table\n");
I 9
		closedir(fd);
E 17
I 17
		fputs("No mem for dev table\n", stderr);
E 17
E 9
		return;
	}
I 17
	if ((fd = opendir("/dev")) == NULL) {
		perror("/dev");
		return;
	}
E 17
D 5

E 5
	while (dp = readdir(fd)) {
		if (dp->d_ino == 0)
			continue;
D 6
#ifdef	MELB
E 6
		if (dp->d_name[0] != 't' && strcmp(dp->d_name, "console"))
			continue;
D 6
#endif
E 6
		strncpy(hashtab->dev_name, dp->d_name, fldsiz(utmp, ut_line));
		hashtab->dev_name[fldsiz(utmp, ut_line)] = 0;
		hashtab->dev_nxt = dev_chain;
		dev_chain = hashtab;
		hashtab++;
		if (--ndevs <= 0)
			break;
	}
	closedir(fd);
}

char *
D 5
tername(dev)
dev_t dev;
E 5
I 5
D 6
ttyname(dev)
E 6
I 6
getdev(dev)
E 6
	dev_t dev;
E 5
{
	register struct devhash *hp, *nhp;
	struct stat statb;
D 5
	char name [fldsiz(devhash, dev_name) + 6];
E 5
I 5
	char name[fldsiz(devhash, dev_name) + 6];
E 5
	static dev_t lastdev = (dev_t) -1;
	static char *lastname;
I 6
D 9
	int init = 0;
E 9
I 9
	static int init = 0;
I 17
	char *strcpy(), *strcat();
E 17
E 9
E 6

	if (dev == NODEV)
D 5
		return("__");

E 5
I 5
		return ("__");
E 5
	if (dev == lastdev)
D 5
		return(lastname);
	
E 5
I 5
		return (lastname);
I 6
	if (!init) {
		setupdevs();
		init++;
	}
E 6
E 5
	for (hp = dev_hash[HASH(dev)]; hp; hp = hp->dev_nxt)
		if (hp->dev_dev == dev) {
			lastdev = dev;
D 5
			return(lastname = hp->dev_name);
E 5
I 5
			return (lastname = hp->dev_name);
E 5
		}
D 5

E 5
	for (hp = dev_chain; hp; hp = nhp) {
		nhp = hp->dev_nxt;
		strcpy(name, "/dev/");
		strcat(name, hp->dev_name);
		if (stat(name, &statb) < 0)	/* name truncated usually */
			continue;
		if ((statb.st_mode & S_IFMT) != S_IFCHR)
			continue;
		hp->dev_dev = statb.st_rdev;
		hp->dev_nxt = dev_hash[HASH(hp->dev_dev)];
		dev_hash[HASH(hp->dev_dev)] = hp;
		if (hp->dev_dev == dev) {
			dev_chain = nhp;
			lastdev = dev;
D 5
			return(lastname = hp->dev_name);
E 5
I 5
			return (lastname = hp->dev_name);
E 5
		}
	}
D 5

E 5
	dev_chain = (struct devhash *) 0;
D 5
	return("??");
E 5
I 5
	return ("??");
D 6
}

ok(argc, argv, acp)
	register int argc;
	register char *argv[];
	register struct acct *acp;
{
	register int j;

	for (j = 1; j < argc; j++)
		if (strcmp(user_list[acp->ac_uid], argv[j]) &&
		    strcmp(ttyname(acp->ac_tty), argv[j]) &&
		    strcmp(acp->ac_comm, argv[j]))
			break;
	return (j == argc);
E 6
E 5
E 4
}
E 1
