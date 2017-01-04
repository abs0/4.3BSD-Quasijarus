h22564
s 00001/00000/00437
d D 5.18 99/08/28 21:15:40 msokolov 22 21
c What in the hell happened to #include <stdio.h>?!
e
s 00010/00005/00428
d D 5.17 88/06/29 19:42:47 bostic 21 20
c install approved copyright notice
e
s 00035/00034/00398
d D 5.16 88/06/17 11:38:25 bostic 20 19
c "man new foo" was broken; clean up logic in general, it was needlessly\convoluted
e
s 00006/00006/00426
d D 5.15 88/04/22 16:51:26 marc 19 18
c wasen't using users PAGER if it was "more"
e
s 00069/00043/00363
d D 5.14 88/04/22 16:37:42 bostic 18 17
c add -a flag, print all man pages; add getopt, required getopt to handle
c single dash; add routine jump, to handle old -k and -f flags;
e
s 00086/00064/00320
d D 5.13 88/03/28 11:30:46 bostic 17 15
c change to display multiple man pages; minor kernel normal form changes
e
s 00081/00063/00321
d R 5.13 88/03/28 11:24:58 bostic 16 15
c change to display multiple man pages; minor kernel normal form changes
e
s 00169/00179/00224
d D 5.12 88/01/14 16:54:05 bostic 15 14
c fix to find all section 1's before finding section 2's, etc. 
c fair amount of rewriting, I never did like its kludginess anyway
e
s 00006/00002/00397
d D 5.11 88/01/08 14:28:53 bostic 14 13
c don't truncate manpath in case usage is "man foo bar baz"
e
s 00011/00005/00388
d D 5.10 87/12/16 15:39:15 bostic 13 12
c add Berkeley headers
e
s 00001/00000/00392
d D 5.9 87/11/14 11:57:40 bostic 12 11
c put in standard illegal option message
e
s 00019/00011/00373
d D 5.8 87/10/29 11:43:43 bostic 11 8
c add the UNDOCUMENTED -w flag; it's useful when you're moving 
c man pages hither and yon.  It's NOT worth making "real".
e
s 00020/00012/00372
d R 5.8 87/10/26 16:10:45 bostic 10 8
c add the UNDOCUMENTED -w flag; it's useful when you're moving 
c man pages hither and yon.  It's NOT worth making "real".
e
s 00016/00012/00372
d R 5.8 87/10/26 16:06:18 bostic 9 8
c add the UNDOCUMENTED -w flag; it's useful when you're moving 
c man pages hither and yon.  It's NOT worth making "real".
e
s 00054/00030/00330
d D 5.7 87/07/26 18:48:18 bostic 8 6
c break "new" out into multiple directories, minor fixes
e
s 00056/00024/00336
d R 5.7 87/07/26 18:43:53 bostic 7 6
c break "cat.new" into multiple directories, minor fixes
e
s 00003/00003/00357
d D 5.6 87/07/20 08:06:25 bostic 6 5
c make -M and MANPATH work again; bug report 4.3BSD/ucb/104
e
s 00029/00003/00331
d D 5.5 87/07/05 19:49:48 bostic 5 4
c if PAGER is more, add the -s flag
e
s 00071/00017/00263
d D 5.4 87/07/03 17:06:06 bostic 4 3
c make new/old really work; section 1 is really 1, 6, 8, old, new
e
s 00002/00002/00278
d D 5.3 87/07/02 15:33:15 bostic 3 2
c fix old/new argv stuff
e
s 00096/00065/00184
d D 5.2 87/06/30 19:17:32 bostic 2 1
c make it really work
e
s 00249/00000/00000
d D 5.1 87/06/29 20:53:50 bostic 1 0
c date and time created 87/06/29 20:53:50 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 13
 */

#ifndef lint
char copyright[] =
D 11
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 11
I 11
D 13
"@(#) Copyright (c) 1987 Regents of the University of California.\n\
E 13
I 13
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 13
E 11
 All rights reserved.\n";
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13

#include <sys/param.h>
#include <sys/file.h>
I 22
#include <stdio.h>
E 22
#include <ctype.h>

D 2
#define	DEF_PAGER	"more -s"	/* paging filter */
#define	DEF_PATH	"/usr/man"	/* default path */
#define	NO		0		/* no/false */
#define	YES		1		/* yes/true */
E 2
I 2
D 5
#define	DEF_PAGER	"more -s"
E 5
I 5
#define	DEF_PAGER	"/usr/ucb/more -s"
E 5
D 8
#define	DEF_PATH	"/usr/man:/usr/local/man"
E 8
I 8
#define	DEF_PATH	"/usr/man:/usr/new/man:/usr/local/man"
D 15

E 15
E 8
#define	LOCAL_PATH	"/usr/local/man"
D 15
#define	LOCAL_NAME	"local"
I 8

E 15
#define	NEW_PATH	"/usr/new/man"
D 15
#define	NEW_NAME	"new"
E 15

E 8
D 17
#define	NO		0
#define	YES		1
E 17
I 17
#define	NO	0
#define	YES	1
E 17
E 2

D 2
/*
 * See code for more info on this kludge; suffice it to say that the
 * local, new and old defines *have* to map into the dirlist array
 * correctly.  Notice also that cat1 is in array slot 1, etc. etc.
 * Continue to notice that it's also ordered for searching, i.e.
 * slots 1 - N are in the order you wish to search the directories.
 */
E 2
D 15
#define	NO_SECTION	0
D 2
#define	LOCAL_SECTION	9
#define	NEW_SECTION	10
#define	OLD_SECTION	11
#define	isname(x)	(x==LOCAL_SECTION || x==NEW_SECTION || x==OLD_SECTION)
static char	*machine,		/* machine type */
		*manpath,		/* search path */
		*pager,			/* pager */
		*dirlist[] = {		/* sub-directory list */
	"notused", 	"cat1",		"cat2",		"cat3",
	"cat4",		"cat5",		"cat6",		"cat7",
	"cat8",		"local",	"new",		"old",
	NULL,
E 2
I 2
#define	S_THREEF	9
D 8
#define	S_NEW		10
#define	S_OLD		11
E 8
I 8
#define	S_OLD		10
E 8

D 4
/* this array maps a character (ex: '4') to an offset in dirlist */
E 4
I 4
/* this array maps a character (ex: '4') to an offset in stanlist */
E 4
#define	secno(x)	(seclist[(int)(x - '0')])
static int	seclist[] = { -1, 1, 4, 5, 6, 7, 3, 8, 2, -1, -1 };

/* sub directory list, ordered for searching */
E 15
D 4
typedef struct something_meaningful {
E 4
I 4
D 17
typedef struct {
E 4
D 15
	char	*name,
		*msg;
E 15
I 15
	char	*name, *msg;
E 15
} DIR;

E 17
D 4
DIR	dirlist[] = {		/* sub-directory list */
E 4
I 4
D 15
DIR	stanlist[] = {		/* standard sub-directory list */
E 4
	"notused", "",		"cat1", "1st",		"cat8", "8th",
	"cat6", "6th",		"cat2", "2nd",		"cat3", "3rd",
	"cat4", "4th",		"cat5", "5th", 		"cat7", "7th",
D 4
	"cat3f", "3rd (F)",	"new", "new",		"old", "old",
E 4
I 4
D 8
	"cat3f", "3rd (F)",	"cat.new", "new",	"cat.old", "old",
E 4
	NULL, NULL,
E 8
I 8
	"cat3f", "3rd (F)",	"cat.old", "old",	NULL, NULL,
E 8
I 4
},	sec1list[] = {		/* section one list */
	"notused", "",		"cat1", "1st",		"cat8", "8th",
D 8
	"cat6", "6th",		"cat.new", "new",	"cat.old", "old",
	NULL, NULL,
E 8
I 8
	"cat6", "6th",		"cat.old", "old",	NULL, NULL,
E 8
E 4
E 2
};

I 4
static DIR	*dirlist;		/* list of directories to search */
E 15
E 4
D 2
static int	nomore;			/* don't use more */
E 2
I 2
D 11
static int	nomore;			/* copy file to stdout */
E 11
I 11
D 18
static int	nomore,			/* copy file to stdout */
		where;			/* just tell me where */
E 18
E 11
D 17
static char	*defpath,		/* default search path */
E 17
I 17
static char	*command,		/* command buffer */
		*defpath,		/* default search path */
E 17
		*locpath,		/* local search path */
		*machine,		/* machine type */
		*manpath,		/* current search path */
I 8
		*newpath,		/* new search path */
E 8
D 18
		*pager;			/* requested pager */
E 18
I 18
		*pager,			/* requested pager */
		how;			/* how to display */
E 18
E 2

I 18
#define	ALL	0x1			/* show all man pages */
#define	CAT	0x2			/* copy file to stdout */
#define	WHERE	0x4			/* just tell me where */

E 18
main(argc, argv)
D 15
	int	argc;
D 2
	char	**argv;
E 2
I 2
	register char	**argv;
E 15
I 15
	int argc;
	register char **argv;
E 15
E 2
{
D 15
	int	section;
	char	**arg_start, **arg,
D 5
		*getenv();
E 5
I 5
		*getenv(), *malloc();
E 15
I 15
D 18
	char **arg_start, **arg, *getenv(), *malloc(), *strcpy();
E 18
I 18
	extern char *optarg;
	extern int optind;
	int ch;
	char *getenv(), *malloc();
E 18
E 15
E 5

D 18
	arg_start = argv;
	for (--argc, ++argv; argc && (*argv)[0] == '-'; --argc, ++argv)
		switch((*argv)[1]) {
		case 0:			/* just write to stdout */
			nomore = YES;
E 18
I 18
	while ((ch = getopt(argc, argv, "-M:P:afkw")) != EOF)
		switch((char)ch) {
		case '-':
			how |= CAT;
E 18
			break;
		case 'M':
		case 'P':		/* backward compatibility */
D 18
			if ((*argv)[2])
D 6
				manpath = *argv + 2;
E 6
I 6
				defpath = *argv + 2;
E 6
			else {
				if (argc < 2) {
					fprintf(stderr, "%s: missing path\n", *argv);
					exit(1);
				}
				--argc;
D 6
				manpath = *++argv;
E 6
I 6
				defpath = *++argv;
E 6
			}
E 18
I 18
			defpath = optarg;
E 18
			break;
I 18
		case 'a':
			how |= ALL;
			break;
E 18
		/*
D 17
		 * "man -f" and "man -k" are undocumented ways of calling
		 * whatis(1) and apropos(1).  Just strip out the flag
		 * argument and jump.
E 17
I 17
		 * "man -f" and "man -k" are backward contemptible,
		 * undocumented ways of calling whatis(1) and apropos(1).
D 18
		 * Just strip out the flag argument and jump.
E 18
E 17
		 */
		case 'f':
D 18
			for (arg = argv; arg[0] = arg[1]; ++arg);
			*arg_start = "whatis";
			execvp(*arg_start, arg_start);
			fputs("whatis: Command not found.\n", stderr);
			exit(1);
E 18
I 18
			jump(argv, "-f", "whatis");
			/*NOTREACHED*/
E 18
		case 'k':
D 18
			for (arg = argv; *arg = arg[1]; ++arg);
			*arg_start = "apropos";
			execvp(*arg_start, arg_start);
			fputs("apropos: Command not found.\n", stderr);
			exit(1);
E 18
I 18
			jump(argv, "-k", "apropos");
			/*NOTREACHED*/
E 18
I 15
		/*
		 * Deliberately undocumented; really only useful when
		 * you're moving man pages around.  Not worth adding.
		 */
E 15
I 11
		case 'w':
D 15
			/*
			 * Deliberately undocumented; really only useful when
			 * you're moving man pages around.  Not worth adding.
			 */
E 15
D 18
			where = YES;
E 18
I 18
			how |= WHERE | ALL;
E 18
			break;
E 11
		case '?':
		default:
I 12
D 18
			fprintf(stderr, "man: illegal option -- %c\n", (*argv)[1]);
E 12
D 15
			usage();
E 15
I 15
			goto usage;
E 18
I 18
			usage();
E 18
E 15
		}
I 18
	argv += optind;
E 18
D 15
	if (!argc)
		usage();
E 15

I 15
D 18
	if (!argc) {
usage:		fputs("usage: man [-] [-M path] [section] title ...\n", stderr);
		exit(1);
	}
E 18
I 18
	if (!*argv)
		usage();
E 18

E 15
D 18
	if (!nomore)
E 18
I 18
	if (!(how & CAT))
E 18
		if (!isatty(1))
D 18
			nomore = YES;
E 18
I 18
			how |= CAT;
E 18
D 5
		else if (!(pager = getenv("PAGER")))
E 5
I 5
		else if (pager = getenv("PAGER")) {
D 15
			register char	*C;
E 15
I 15
			register char *p;
E 15

			/*
			 * if the user uses "more", we make it "more -s"
			 * watch out for PAGER = "mypager /usr/ucb/more"
			 */
D 15
			for (C = pager; *C && !isspace(*C); ++C);
			for (; C > pager && *C != '/'; --C);
			if (C != pager)
				++C;
E 15
I 15
			for (p = pager; *p && !isspace(*p); ++p);
			for (; p > pager && *p != '/'; --p);
			if (p != pager)
				++p;
E 15
			/* make sure it's "more", not "morex" */
D 15
			if (!strncmp(C, "more", 4) && (!C[4] || isspace(C[4]))) {
				C += 4;
E 15
I 15
D 19
			if (!strncmp(p, "more", 4) && (!p[4] || isspace(p[4]))) {
				p += 4;
E 19
I 19
			if (!strncmp(p, "more", 4) && (!p[4] || isspace(p[4]))){
				char *opager = pager;
E 19
E 15
				/*
D 15
				 * sizeof is 1 more than # of chars, so,
E 15
D 19
				 * allocate for the rest of the PAGER
				 * environment variable, a space, and the EOS.
E 19
I 19
				 * allocate space to add the "-s"
E 19
				 */
D 15
				if (!(pager = malloc((u_int)(strlen(C) + sizeof(DEF_PAGER) + 1)))) {
E 15
I 15
D 19
				if (!(pager = malloc((u_int)(strlen(p) + sizeof(DEF_PAGER) + 1)))) {
E 19
I 19
				if (!(pager = malloc((u_int)(strlen(opager) 
				    + sizeof("-s") + 1)))) {
E 19
E 15
					fputs("man: out of space.\n", stderr);
					exit(1);
				}
D 15
				(void)sprintf(pager, "%s %s", DEF_PAGER, C);
E 15
I 15
D 19
				(void)sprintf(pager, "%s %s", DEF_PAGER, p);
E 19
I 19
				(void)sprintf(pager, "%s %s", opager, "-s");
E 19
E 15
			}
		}
		else
E 5
			pager = DEF_PAGER;
	if (!(machine = getenv("MACHINE")))
		machine = MACHINE;
D 2
	if (!manpath && !(manpath = getenv("MANPATH")))
		manpath = DEF_PATH;
	for (; *manpath && *manpath == ':'; ++manpath);
E 2
I 2
	if (!defpath && !(defpath = getenv("MANPATH")))
		defpath = DEF_PATH;
	locpath = LOCAL_PATH;
I 8
	newpath = NEW_PATH;
E 8
D 15
	for (; *defpath && *defpath == ':'; ++defpath);
E 15
I 15
	man(argv);
I 17
D 20
	/* use system(3) in case someone's pager is "foo arg1 arg2" */
E 20
I 20
	/* use system(3) in case someone's pager is "pager arg1 arg2" */
E 20
	if (command)
		(void)system(command);
E 17
	exit(0);
}
E 15
E 2

I 17
typedef struct {
	char	*name, *msg;
} DIR;
E 17
I 4
D 15
	/* Gentlemen... start your kludges! */
E 15
I 15
static DIR	list1[] = {		/* section one list */
	"cat1", "1st",		"cat8", "8th",		"cat6", "6th",
	"cat.old", "old",	NULL, NULL,
},		list2[] = {		/* rest of the list */
	"cat2", "2nd",		"cat3", "3rd",		"cat4", "4th",
	"cat5", "5th", 		"cat7", "7th",		"cat3f", "3rd (F)",
	NULL, NULL,
},		list3[2];		/* single section */

static
man(argv)
	char **argv;
{
	register char *p;
	DIR *section, *getsect();
	int res;

E 15
E 4
	for (; *argv; ++argv) {
D 15
		section = NO_SECTION;
E 15
I 2
D 6
		manpath = DEF_PATH;
E 6
I 6
		manpath = defpath;
I 15
		section = NULL;
E 15
E 6
I 4
D 8
		dirlist = stanlist;
E 8
E 4
E 2
		switch(**argv) {
D 2
		/*
		 * hardwired section numbers, fix here if they do; note,
		 * only works for single digits.
		 */
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8':
E 2
I 2
D 4
		/* hardwired section numbers, fix here if they change */
		case '1': case '2': case '4': case '5': case '6':
E 4
I 4
D 15
		/*
D 8
		 * Section 1 requests are really for section 1, 6, 8, new and
		 * old.  Since new and old aren't broken up into a directory
		 * of cat[1-8], we just pretend that they are a subdirectory
		 * of /usr/man.  Should be fixed -- make new and old full
		 * structures just like local is, get rid of "sec1list" and
		 * dirlist.
E 8
I 8
		 * Section 1 requests are really for section 1, 6, 8, in the
		 * standard, local and new directories and section old. Since
		 * old isn't broken up into a directory of cat[1-8], we just
		 * treat it like a subdirectory of the others.
E 8
		 */
D 8
		case '1':
			if (!(*argv)[1]) {
				dirlist = sec1list;
				goto numtest;
			}
			break;

		case '2': case '4': case '5': case '6':
E 8
I 8
		case '1': case '2': case '4': case '5': case '6':
E 8
E 4
		case '7': case '8':
E 2
			if (!(*argv)[1]) {
D 2
				section = (*argv)[0] - '0';
E 2
I 2
				section = secno((*argv)[0]);
				goto numtest;
E 15
I 15
		case 'l':				/* local */
I 20
			/* support the "{l,local,n,new}###"  syntax */
E 20
			for (p = *argv; isalpha(*p); ++p);
			if (!strncmp(*argv, "l", p - *argv) ||
			    !strncmp(*argv, "local", p - *argv)) {
I 20
				++argv;
E 20
				manpath = locpath;
D 20
				if (section = getsect(p))
					goto argtest;
E 20
I 20
				section = getsect(p);
E 20
E 15
			}
			break;
I 4
D 15

		/* sect. 3 requests are for either section 3, or section 3F. */
E 4
		case '3':
			if (!(*argv)[1]) {			/* "3" */
				section = secno((*argv)[0]);
numtest:			if (!*++argv) {
D 4
					fprintf(stderr, "man: what do you want from the %s section of the manual?\n", dirlist[section].msg);
E 4
I 4
					fprintf(stderr, "man: what do you want from the %s section of the manual?\n", stanlist[section].msg);
E 4
					exit(1);
				}
			}					/* "3[fF]" */
D 8
			if (((*argv)[1] == 'f'  || (*argv)[1] == 'F') && !(*argv)[2]) {
E 8
I 8
			else if (((*argv)[1] == 'f'  || (*argv)[1] == 'F') && !(*argv)[2]) {
E 8
				section = S_THREEF;
E 2
				if (!*++argv) {
D 2
					fprintf(stderr, "man: what do you want from section %d?\n", section);
E 2
I 2
D 4
					fprintf(stderr, "man: what do you want from the %s section of the manual?\n", dirlist[S_THREEF].msg);
E 4
I 4
					fprintf(stderr, "man: what do you want from the %s section of the manual?\n", stanlist[S_THREEF].msg);
E 4
E 2
					exit(1);
				}
E 15
I 15
		case 'n':				/* new */
			for (p = *argv; isalpha(*p); ++p);
			if (!strncmp(*argv, "n", p - *argv) ||
			    !strncmp(*argv, "new", p - *argv)) {
I 20
				++argv;
E 20
				manpath = newpath;
D 20
				if (section = getsect(p))
					goto argtest;
E 20
I 20
				section = getsect(p);
E 20
E 15
			}
			break;
I 4
		/*
D 8
		 * Requests for the local section can have subsection numbers
		 * appended to them, i.e. "local3" is really local/cat3.
E 8
I 8
D 15
		 * Requests for the new or local sections can have subsection
		 * numbers appended to them, i.e. "local3" is really
		 * local/cat3.
E 15
I 15
		 * old isn't really a separate section of the manual,
		 * and its entries are all in a single directory.
E 15
E 8
		 */
E 4
D 2
		/*
		 * backward compatibility: manl == local, mann == new,
		 * mano == old;
		 */
		case 'l':
			if (!*argv[1] || !strcmp(*argv, dirlist[LOCAL_SECTION])) {
				section = LOCAL_SECTION;
				goto argtest;
E 2
I 2
D 15
		case 'l':					/* local */
			if (!(*argv)[1])			/* "l" */
				section = NO_SECTION;		/* "l2" */
			else if (isdigit((*argv)[1]) && !(*argv)[2])
				section = secno((*argv)[1]);
			else {
				int	lex;
				lex = strcmp(LOCAL_NAME, *argv);
				if (!lex)			/* "local" */
					section = NO_SECTION;	/* "local2" */
				else if (lex < 0 && isdigit((*argv)[sizeof(LOCAL_NAME) - 1]) && !(*argv)[sizeof(LOCAL_NAME)])
					section = secno((*argv)[sizeof(LOCAL_NAME) - 1]);
				else
					break;
E 15
I 15
		case 'o':				/* old */
			for (p = *argv; isalpha(*p); ++p);
			if (!strncmp(*argv, "o", p - *argv) ||
			    !strncmp(*argv, "old", p - *argv)) {
I 20
				++argv;
E 20
				list3[0] = list1[3];
				section = list3;
D 20
				goto argtest;
E 20
E 15
E 2
			}
I 2
D 15
			if (!*++argv) {
				fputs("man: what do you want from the local section of the manual?\n", stderr);
				exit(1);
			}
			manpath = locpath;
E 15
E 2
			break;
D 2
		case 'n':
			if (!*argv[1] || !strcmp(*argv, dirlist[NEW_SECTION])) {
				section = NEW_SECTION;
				goto argtest;
E 2
I 2
D 15
		case 'n':					/* new */
D 3
			if (!*argv[1] || !strcmp(*argv, dirlist[S_NEW].name)) {
E 3
I 3
D 4
			if (!(*argv)[1] || !strcmp(*argv, dirlist[S_NEW].name)) {
E 4
I 4
D 8
			if (!(*argv)[1] || !strcmp(*argv, stanlist[S_NEW].msg)) {
E 4
E 3
				section = S_NEW;
				goto strtest;
E 8
I 8
			if (!(*argv)[1])			/* "n" */
				section = NO_SECTION;		/* "n2" */
			else if (isdigit((*argv)[1]) && !(*argv)[2])
				section = secno((*argv)[1]);
			else {
				int	lex;
				lex = strcmp(NEW_NAME, *argv);
				if (!lex)			/* "new" */
					section = NO_SECTION;	/* "new2" */
				else if (lex < 0 && isdigit((*argv)[sizeof(NEW_NAME) - 1]) && !(*argv)[sizeof(NEW_NAME)])
					section = secno((*argv)[sizeof(NEW_NAME) - 1]);
				else
					break;
E 8
E 2
			}
I 8
			if (!*++argv) {
				fputs("man: what do you want from the new section of the manual?\n", stderr);
E 15
I 15
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8':
D 20
			if (!(section = getsect(*argv)))
				break;
argtest:		if (!*++argv) {
				fprintf(stderr, "man: what do you want from the %s section of the manual?\n", section->msg);
E 15
				exit(1);
E 20
I 20
			if (section = getsect(*argv))
				++argv;
		}

		if (*argv) {
			if (section)
				res = manual(section, *argv);
			else {
				res = manual(list1, *argv);
				if (!res || (how & ALL))
					res += manual(list2, *argv);
E 20
			}
I 20
			if (res || how&WHERE)
				continue;
E 20
D 15
			manpath = newpath;
E 8
			break;
D 2
		case 'o':
			if (!*argv[1] || !strcmp(*argv, dirlist[OLD_SECTION])) {
				section = OLD_SECTION;
argtest:			if (!*++argv) {
					fprintf(stderr, "man: what do you want from the %s section?\n", dirlist[section]);
E 2
I 2
		case 'o':					/* old */
D 3
			if (!*argv[1] || !strcmp(*argv, dirlist[S_OLD].name)) {
E 3
I 3
D 4
			if (!(*argv)[1] || !strcmp(*argv, dirlist[S_OLD].name)) {
E 4
I 4
			if (!(*argv)[1] || !strcmp(*argv, stanlist[S_OLD].msg)) {
E 4
E 3
				section = S_OLD;
D 8
strtest:			if (!*++argv) {
E 8
I 8
				if (!*++argv) {
E 8
D 4
					fprintf(stderr, "man: what do you want from the %s section of the manual?\n", dirlist[section].msg);
E 4
I 4
					fprintf(stderr, "man: what do you want from the %s section of the manual?\n", stanlist[section].msg);
E 4
E 2
					exit(1);
				}
			}
			break;
E 15
		}
I 8
D 15
		if (section == 1) {
			dirlist = sec1list;
			section = NO_SECTION;
		}
		else
			dirlist = stanlist;
E 8
I 4
		/*
		 * This is really silly, but I wanted to put out rational
		 * errors, not just "I couldn't find it."  This if statement
		 * knows an awful lot about what gets assigned to what in
		 * the switch statement we just passed through.  Sorry.
		 */
E 4
D 11
		if (!manual(section, *argv))
E 11
I 11
		if (!manual(section, *argv) && !where)
E 15
I 15

I 20
		fputs("man: ", stderr);
		if (*argv)
			fprintf(stderr, "no entry for %s in the ", *argv);
		else
			fputs("what do you want from the ", stderr);
E 20
D 17
		res = section ? manual(section, *argv) :
		    manual(list1, *argv) || manual(list2, *argv);
		if (!res && !where)
E 17
I 17
		if (section)
D 20
			res = manual(section, *argv);
		else {
			res = manual(list1, *argv);
D 18
			res += manual(list2, *argv);
E 18
I 18
			if (!res || (how & ALL))
				res += manual(list2, *argv);
E 18
		}
D 18
		if (!res && !where) {
E 18
I 18
		if (!res && !(how & WHERE)) {
E 18
E 17
E 15
E 11
D 2
			if (section == NO_SECTION)
				fprintf(stderr, "No manual entry for %s.\n", *argv);
			else if (isname(section))
				fprintf(stderr, "No entry for %s in the %s section of the manual.\n", *argv, dirlist[section]);
E 2
I 2
			if (manpath == locpath)
D 4
				fprintf(stderr, "No entry for %s in the %s section of the local manual.\n", *argv, dirlist[section].msg);
E 4
I 4
D 8
				fprintf(stderr, "No entry for %s in the %s section of the local manual.\n", *argv, stanlist[section].msg);
E 8
I 8
D 15
				if (section == NO_SECTION)
					fprintf(stderr, "No entry for %s in the local manual.\n", *argv);
E 15
I 15
				if (section)
					fprintf(stderr, "No entry for %s in the %s section of the local manual.\n", *argv, section->msg);
E 15
				else
D 15
					fprintf(stderr, "No entry for %s in the %s section of the local manual.\n", *argv, stanlist[section].msg);
E 15
I 15
					fprintf(stderr, "No entry for %s in the local manual.\n", *argv);
E 15
			else if (manpath == newpath)
D 15
				if (section == NO_SECTION)
					fprintf(stderr, "No entry for %s in the new manual.\n", *argv);
E 15
I 15
				if (section)
					fprintf(stderr, "No entry for %s in the %s section of the new manual.\n", *argv, section->msg);
E 15
				else
D 15
					fprintf(stderr, "No entry for %s in the %s section of the new manual.\n", *argv, stanlist[section].msg);
E 8
			else if (dirlist == sec1list)
				fprintf(stderr, "No entry for %s in the 1st section of the manual.\n", *argv);
E 4
			else if (section == NO_SECTION)
				fprintf(stderr, "No entry for %s in the manual.\n", *argv);
E 15
I 15
					fprintf(stderr, "No entry for %s in the new manual.\n", *argv);
			else if (section)
				fprintf(stderr, "No entry for %s in the %s section of the manual.\n", *argv, section->msg);
E 15
E 2
			else
D 2
				fprintf(stderr, "No entry for %s in section %d of the manual.\n", *argv, section);
E 2
I 2
D 4
				fprintf(stderr, "No entry for %s in the %s section of the manual.\n", *argv, dirlist[section].msg);
E 4
I 4
D 15
				fprintf(stderr, "No entry for %s in the %s section of the manual.\n", *argv, stanlist[section].msg);
E 15
I 15
				fprintf(stderr, "No entry for %s in the manual.\n", *argv);
I 17
			exit(1);
		}
E 20
I 20
			fprintf(stderr, "%s section of the ", section->msg);
		if (manpath == locpath)
			fputs("local ", stderr);
		else if (manpath == newpath)
			fputs("new ", stderr);
		if (*argv)
			fputs("manual.\n", stderr);
		else
			fputs("manual?\n", stderr);
		exit(1);
E 20
E 17
E 15
E 4
E 2
	}
D 15
	exit(0);
E 15
}

I 4
/*
 * manual --
D 17
 *	given a section number and a file name go through the directory
 *	list and find a file that matches.
E 17
I 17
 *	given a directory list and a file name find a file that
 *	matches; check ${directory}/${dir}/{file name} and
 *	${directory}/${dir}/${machine}/${file name}.
E 17
 */
E 4
static
manual(section, name)
D 15
	int	section;
	char	*name;
E 15
I 15
	DIR *section;
	char *name;
E 15
{
D 2
	register char	*beg, *end, **dir;
E 2
I 2
D 15
	register DIR	*dir;
	register char	*beg, *end;
E 2
	char	*index();
E 15
I 15
	register char *beg, *end;
	register DIR *dp;
D 17
	char *index();
E 17
I 17
	register int res;
	char fname[MAXPATHLEN + 1], *index();
E 17
E 15

D 17
	for (beg = manpath;; beg = end + 1) {
E 17
I 17
	for (beg = manpath, res = 0;; beg = end + 1) {
E 17
		if (end = index(beg, ':'))
			*end = '\0';
D 4
		if (section == NO_SECTION) {
D 2
			/* notice the +1... */
			for (dir = dirlist + 1; *dir; ++dir)
				if (find(beg, *dir, name))
E 2
I 2
			for (dir = dirlist + 1; dir->name; ++dir)
E 4
I 4
D 15
		if (section == NO_SECTION)
			for (dir = dirlist; (++dir)->name;) {
E 4
				if (find(beg, dir->name, name))
E 2
D 14
					return(YES);
E 14
I 14
					goto found;
E 15
I 15
D 17
		for (dp = section; dp->name; ++dp)
			if (find(beg, dp->name, name)) {
				if (end)
					*end = ':';
				return(YES);
E 17
I 17
		for (dp = section; dp->name; ++dp) {
			(void)sprintf(fname, "%s/%s/%s.0", beg, dp->name, name);
			if (access(fname, R_OK)) {
				(void)sprintf(fname, "%s/%s/%s/%s.0", beg,
				    dp->name, machine, name);
				if (access(fname, R_OK))
					continue;
E 17
E 15
E 14
D 4
		}
D 2
		else if (find(beg, dirlist[section], name))
E 2
I 2
		else if (find(beg, dirlist[section].name, name))
E 4
I 4
			}
I 17
D 18
			if (where)
E 18
I 18
			if (how & WHERE)
E 18
				printf("man: found in %s.\n", fname);
D 18
			else if (nomore)
E 18
I 18
			else if (how & CAT)
E 18
				cat(fname);
			else
				add(fname);
I 18
			if (!(how & ALL))
				return(1);
E 18
			res = 1;
		}
E 17
D 14
		else if (find(beg, stanlist[section].name, name))
E 14
I 14
D 15
		else if (find(beg, stanlist[section].name, name)) {
found:			if (end)
				*end = ':';
E 14
E 4
E 2
			return(YES);
I 14
		}
E 15
E 14
		if (!end)
D 17
			return(NO);
E 17
I 17
			return(res);
E 17
I 14
		*end = ':';
E 14
	}
	/*NOTREACHED*/
}

I 4
/*
D 17
 * find --
 *	given a directory path, a sub-directory and a file name,
 *	see if a file exists in ${directory}/${dir}/{file name}
 *	or in ${directory}/${dir}/${machine}/${file name}.
E 17
I 17
 * cat --
 *	cat out the file
E 17
 */
E 4
static
D 17
find(beg, dir, name)
D 15
	char	*beg, *dir, *name;
E 15
I 15
	char *beg, *dir, *name;
E 17
I 17
cat(fname)
	char *fname;
E 17
E 15
{
D 15
	char	fname[MAXPATHLEN + 1];
E 15
I 15
D 17
	char fname[MAXPATHLEN + 1];
E 17
I 17
	register int fd, n;
	char buf[BUFSIZ];
E 17
E 15

D 2
	(void)sprintf(fname, "%s/%s/%s", beg, dir, name);
E 2
I 2
D 17
	(void)sprintf(fname, "%s/%s/%s.0", beg, dir, name);
E 2
D 11
	if (!access(fname, R_OK)) {
		show(fname);
		return(YES);
E 11
I 11
	if (access(fname, R_OK)) {
		(void)sprintf(fname, "%s/%s/%s/%s.0", beg, dir, machine, name);
		if (access(fname, R_OK))
			return(NO);
E 17
I 17
	if (!(fd = open(fname, O_RDONLY, 0))) {
		perror("man: open");
		exit(1);
E 17
E 11
	}
D 2
	(void)sprintf(fname, "%s/%s/%s/%s", beg, dir, machine, name);
E 2
I 2
D 11
	(void)sprintf(fname, "%s/%s/%s/%s.0", beg, dir, machine, name);
E 2
	if (!access(fname, R_OK)) {
E 11
I 11
D 17
	if (where)
		printf("man: found in %s.\n", fname);
	else
E 11
		show(fname);
D 11
		return(YES);
	}
	return(NO);
E 11
I 11
	return(!where);
E 17
I 17
	while ((n = read(fd, buf, sizeof(buf))) > 0)
		if (write(1, buf, n) != n) {
			perror("man: write");
			exit(1);
		}
	if (n == -1) {
		perror("man: read");
		exit(1);
	}
	(void)close(fd);
E 17
E 11
}

I 4
/*
D 17
 * show --
 *	display the file
E 17
I 17
 * add --
 *	add a file name to the list for future paging
E 17
 */
E 4
static
D 17
show(fname)
E 17
I 17
add(fname)
E 17
D 15
	char	*fname;
E 15
I 15
	char *fname;
E 15
{
D 15
	register int	fd, n;
	char	buf[BUFSIZ];
E 15
I 15
D 17
	register int fd, n;
	char buf[BUFSIZ];
E 17
I 17
	static u_int buflen;
	static int len;
	static char *cp;
	int flen;
	char *malloc(), *realloc(), *strcpy();
E 17
E 15

D 17
	if (nomore) {
		if (!(fd = open(fname, O_RDONLY, 0))) {
			perror("man: open");
E 17
I 17
	if (!command) {
		if (!(command = malloc(buflen = 1024))) {
			fputs("man: out of space.\n", stderr);
E 17
			exit(1);
		}
D 17
		while ((n = read(fd, buf, sizeof(buf))) > 0)
			if (write(1, buf, n) != n) {
				perror("man: write");
				exit(1);
			}
		if (n == -1) {
			perror("man: read");
E 17
I 17
		len = strlen(strcpy(command, pager));
		cp = command + len;
	}
	flen = strlen(fname);
	if (len + flen + 2 > buflen) {		/* +2 == space, EOS */
		if (!(command = realloc(command, buflen += 1024))) {
			fputs("man: out of space.\n", stderr);
E 17
			exit(1);
		}
D 17
		(void)close(fd);
E 17
I 17
		cp = command + len;
E 17
	}
D 17
	else {
		/*
D 15
		 * use system(2) in case someone's pager is
E 15
I 15
		 * use system(3) in case someone's pager is
E 15
		 * "command arg1 arg2"
		 */
		(void)sprintf(buf, "%s %s", pager, fname);
		(void)system(buf);
	}
E 17
I 17
	*cp++ = ' ';
	len += flen + 1;			/* +1 = space */
	(void)strcpy(cp, fname);
	cp += flen;
E 17
}

I 4
/*
D 15
 * usage --
 *	print out a usage message and die
E 15
I 15
 * getsect --
 *	return a point to the section structure for a particular suffix
E 15
 */
E 4
D 15
static
usage()
E 15
I 15
static DIR *
getsect(s)
	char *s;
E 15
{
D 15
	fputs("usage: man [-] [-M path] [section] title ...\n", stderr);
	exit(1);
E 15
I 15
	switch(*s++) {
	case '1':
		if (!*s)
			return(list1);
		break;
	case '2':
		if (!*s) {
			list3[0] = list2[0];
			return(list3);
		}
		break;
	/* sect. 3 requests are for either section 3, or section 3[fF]. */
	case '3':
		if (!*s) {
			list3[0] = list2[1];
			return(list3);
		}
		else if ((*s == 'f'  || *s == 'F') && !*++s) {
			list3[0] = list2[5];
			return(list3);
		}
		break;
	case '4':
		if (!*s) {
			list3[0] = list2[2];
			return(list3);
		}
		break;
	case '5':
		if (!*s) {
			list3[0] = list2[3];
			return(list3);
		}
		break;
	case '6':
		if (!*s) {
			list3[0] = list1[2];
			return(list3);
		}
		break;
	case '7':
		if (!*s) {
			list3[0] = list2[4];
			return(list3);
		}
		break;
	case '8':
		if (!*s) {
			list3[0] = list1[1];
			return(list3);
		}
	}
	return((DIR *)NULL);
I 18
}

/*
 * jump --
 *	strip out flag argument and jump
 */
static
jump(argv, flag, name)
	char **argv, *name;
	register char *flag;
{
	register char **arg;

	argv[0] = name;
	for (arg = argv + 1; *arg; ++arg)
		if (!strcmp(*arg, flag))
			break;
	for (; *arg; ++arg)
		arg[0] = arg[1];
	execvp(name, argv);
	fprintf(stderr, "%s: Command not found.\n", name);
	exit(1);
}

/*
 * usage --
 *	print usage and die
 */
static
usage()
{
	fputs("usage: man [-] [-a] [-M path] [section] title ...\n", stderr);
	exit(1);
E 18
E 15
}
E 1
