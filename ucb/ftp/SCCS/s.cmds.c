h05808
s 00007/00000/01834
d D 5.9 03/06/12 20:11:19 msokolov 20 19
c ls/dir: heuristics to guess when a single arg meant local, not remote
e
s 00010/00005/01824
d D 5.8 88/06/29 20:34:10 bostic 19 18
c install approved copyright notice
e
s 00009/00003/01820
d D 5.7 88/03/14 17:21:25 bostic 18 17
c add Berkeley specific headers
e
s 00005/00000/01818
d D 5.6 87/10/06 09:58:38 csvsj 17 16
c Ask user to confirm 'ls' and 'dir' local file to prevent accidental
c overwrite; bug report (4.3BSD/ucb/124)
e
s 00086/00079/01732
d D 5.5 86/03/07 12:32:15 minshall 16 15
c Clean up for lint; change some stderr to stdout; bug fix
c (in ruserpass.c, routine rnetrc()).
e
s 00883/00074/00928
d D 5.4 86/02/03 14:41:14 minshall 15 14
c Changes from Steve Jacobson (from <csvsj@ucbopal>).
e
s 00027/00032/00975
d D 5.3 86/01/13 19:32:55 mckusick 14 13
c numerous bug fixes from sun!gorodish!guy
e
s 00001/00001/01006
d D 5.2 86/01/13 17:59:19 karels 13 12
c try multiple addresses in turn if necessary;
c don't build hostent structures, just the parts we want
e
s 00007/00001/01000
d D 5.1 85/05/31 16:58:20 dist 12 11
c Add copyright
e
s 00005/00002/00996
d D 4.11 85/03/11 13:31:03 ralph 11 10
c minor fixes from ut-sally
e
s 00001/00001/00997
d D 4.10 84/04/10 17:24:14 ralph 10 9
c fix test for mls/mdir.
e
s 00002/00022/00996
d D 4.9 83/07/26 21:33:54 sam 9 8
c linger purge
e
s 00001/00001/01017
d D 4.8 83/07/02 00:29:25 sam 8 7
c include fixes
e
s 00070/00028/00948
d D 4.7 83/06/19 23:07:50 sam 7 6
c fix m* cmds and add linger control
e
s 00002/00001/00974
d D 4.6 83/05/11 22:02:20 sam 6 5
c split ftpd out to etc source; fix bug with sendport stuff
e
s 00108/00042/00867
d D 4.5 83/03/29 11:24:42 sam 5 4
c from jsq@utexas-11 (mls, mdir and random cleanups after me)
e
s 00138/00132/00771
d D 4.4 83/03/23 10:25:36 sam 4 3
c merge of changes from jsq@utexas-11
e
s 00244/00030/00659
d D 4.3 83/03/01 03:15:20 sam 3 2
c globbing of local file names & mget and mput (ugly, needs more work)
e
s 00015/00008/00674
d D 4.2 83/02/21 19:37:49 sam 2 1
c fixes from texas
e
s 00682/00000/00000
d D 4.1 83/01/15 16:52:34 sam 1 0
c date and time created 83/01/15 16:52:34 by sam
e
u
U
f b 
t
T
I 12
/*
D 15
 * Copyright (c) 1983 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1985 Regents of the University of California.
E 15
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
E 18
 */

E 12
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif
E 12
I 12
D 18
#endif not lint
E 18
I 18
#endif /* not lint */
E 18
E 12

/*
 * FTP User Program -- Command Routines.
 */
D 3
#include <sys/types.h>
E 3
I 3
D 15
#include <sys/param.h>
E 15
I 15
#include "ftp_var.h"
E 15
I 8
D 11
#include <sys/stat.h>
E 11
E 8
E 3
#include <sys/socket.h>

I 6
#include <arpa/ftp.h>

E 6
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>
I 15
#include <ctype.h>
I 16
#include <sys/wait.h>
E 16
E 15
I 3
D 8
#include <stat.h>
E 8
E 3

D 6
#include "ftp.h"
E 6
D 15
#include "ftp_var.h"
E 15

D 3
int	autologin = 1;
E 3
I 3
extern	char *globerr;
extern	char **glob();
I 5
extern	char *home;
E 5
extern	short gflag;
I 5
extern	char *remglob();
extern	char *getenv();
extern	char *index();
extern	char *rindex();
I 15
char *mname;
jmp_buf jabort;
char *dotrans(), *domap();
E 15
E 5
E 3

/*
 * Connect to peer server and
 * auto-login, if possible.
 */
setpeer(argc, argv)
	int argc;
	char *argv[];
{
D 13
	struct hostent *host, *hookup();
E 13
I 13
	char *host, *hookup();
E 13
	int port;

	if (connected) {
D 15
		printf("Already connected to %s, use disconnect first.\n",
E 15
I 15
		printf("Already connected to %s, use close first.\n",
E 15
			hostname);
I 15
		code = -1;
E 15
		return;
	}
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(to) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc > 3) {
		printf("usage: %s host-name [port]\n", argv[0]);
I 15
		code = -1;
E 15
		return;
	}
	port = sp->s_port;
	if (argc > 2) {
D 2
		port = atoi(argv[1]);
E 2
I 2
		port = atoi(argv[2]);
E 2
		if (port <= 0) {
D 2
			printf("%s: bad port number.\n", argv[1]);
E 2
I 2
			printf("%s: bad port number-- %s\n", argv[1], argv[2]);
			printf ("usage: %s host-name [port]\n", argv[0]);
I 15
			code = -1;
E 15
E 2
			return;
		}
		port = htons(port);
	}
	host = hookup(argv[1], port);
	if (host) {
		connected = 1;
		if (autologin)
D 15
			login(host);
E 15
I 15
D 16
			login(argv[1]);
E 16
I 16
			(void) login(argv[1]);
E 16
E 15
	}
}

struct	types {
	char	*t_name;
	char	*t_mode;
	int	t_type;
I 2
	char	*t_arg;
E 2
} types[] = {
D 2
	{ "ascii",	"A",	TYPE_A },
	{ "binary",	"I",	TYPE_I },
	{ "image",	"I",	TYPE_I },
	{ "ebcdic",	"E",	TYPE_E },
	{ "tenex",	"L",	TYPE_L },
E 2
I 2
	{ "ascii",	"A",	TYPE_A,	0 },
	{ "binary",	"I",	TYPE_I,	0 },
	{ "image",	"I",	TYPE_I,	0 },
	{ "ebcdic",	"E",	TYPE_E,	0 },
	{ "tenex",	"L",	TYPE_L,	bytename },
E 2
	0
};

/*
 * Set transfer type.
 */
settype(argc, argv)
	char *argv[];
{
	register struct types *p;
I 2
	int comret;
E 2

	if (argc > 2) {
		char *sep;

		printf("usage: %s [", argv[0]);
		sep = " ";
		for (p = types; p->t_name; p++) {
			printf("%s%s", sep, p->t_name);
			if (*sep == ' ')
				sep = " | ";
		}
		printf(" ]\n");
I 15
		code = -1;
E 15
		return;
	}
	if (argc < 2) {
		printf("Using %s mode to transfer files.\n", typename);
I 15
		code = 0;
E 15
		return;
	}
	for (p = types; p->t_name; p++)
		if (strcmp(argv[1], p->t_name) == 0)
			break;
	if (p->t_name == 0) {
		printf("%s: unknown mode\n", argv[1]);
I 15
		code = -1;
E 15
		return;
	}
D 2
	if (command("TYPE %s", p->t_mode) == COMPLETE) {
E 2
I 2
	if ((p->t_arg != NULL) && (*(p->t_arg) != '\0'))
		comret = command ("TYPE %s %s", p->t_mode, p->t_arg);
	else
		comret = command("TYPE %s", p->t_mode);
	if (comret == COMPLETE) {
E 2
D 16
		strcpy(typename, p->t_name);
E 16
I 16
		(void) strcpy(typename, p->t_name);
E 16
		type = p->t_type;
	}
}

/*
 * Set binary transfer type.
 */
/*VARARGS*/
setbinary()
{

	call(settype, "type", "binary", 0);
}

/*
 * Set ascii transfer type.
 */
/*VARARGS*/
setascii()
{

	call(settype, "type", "ascii", 0);
}

/*
 * Set tenex transfer type.
 */
/*VARARGS*/
settenex()
{

	call(settype, "type", "tenex", 0);
}

/*
 * Set ebcdic transfer type.
 */
/*VARARGS*/
setebcdic()
{

	call(settype, "type", "ebcdic", 0);
}

/*
 * Set file transfer mode.
 */
I 16
/*ARGSUSED*/
E 16
setmode(argc, argv)
	char *argv[];
{

	printf("We only support %s mode, sorry.\n", modename);
I 15
	code = -1;
E 15
}

/*
 * Set file transfer format.
 */
I 16
/*ARGSUSED*/
E 16
setform(argc, argv)
	char *argv[];
{

	printf("We only support %s format, sorry.\n", formname);
I 15
	code = -1;
E 15
}

/*
 * Set file transfer structure.
 */
I 16
/*ARGSUSED*/
E 16
setstruct(argc, argv)
	char *argv[];
{

	printf("We only support %s structure, sorry.\n", structname);
I 15
	code = -1;
E 15
}

I 11
/*
 * Send a single file.
 */
E 11
D 5
/*
 * Send a single file.
 */
I 4
append(argc, argv)
	char *argv[];
{

	return (put1("APPE", argc, argv));
}

E 5
E 4
put(argc, argv)
D 5
	char *argv[];
{
D 3
	int fd;
	register int n, addr;
	register char *cp, *targ;
E 3

D 4
	if (!connected) {
		printf("Not connected.\n");
		return;
	}
E 4
I 4
	return (put1("STOR", argc, argv));
}

put1(cmd, argc, argv)
	char *cmd;
E 5
	int argc;
	char *argv[];
{
I 5
	char *cmd;
I 15
	int loc = 0;
E 15
I 14
	char *oldargv1;
E 14
E 5

E 4
D 15
	if (argc == 2)
		argc++, argv[2] = argv[1];
E 15
I 15
	if (argc == 2) {
		argc++;
		argv[2] = argv[1];
		loc++;
	}
E 15
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(local-file) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
usage:
D 15
		printf("%s local-file remote-file\n", argv[0]);
E 15
I 15
		printf("usage:%s local-file remote-file\n", argv[0]);
		code = -1;
E 15
		return;
	}
	if (argc < 3) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(remote-file) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 3) 
		goto usage;
I 14
	oldargv1 = argv[1];
E 14
I 3
D 15
	if (!globulize(&argv[1]))
E 15
I 15
	if (!globulize(&argv[1])) {
		code = -1;
E 15
		return;
I 15
	}
E 15
I 14
	/*
	 * If "globulize" modifies argv[1], and argv[2] is a copy of
	 * the old argv[1], make it a copy of the new argv[1].
	 */
D 15
	if (argv[1] != oldargv1 && argv[2] == oldargv1)
E 15
I 15
	if (argv[1] != oldargv1 && argv[2] == oldargv1) {
E 15
		argv[2] = argv[1];
E 14
I 5
D 15
	cmd = (argv[0][0] == 'a') ? "APPE" : "STOR";
E 15
I 15
	}
	cmd = (argv[0][0] == 'a') ? "APPE" : ((sunique) ? "STOU" : "STOR");
	if (loc && ntflag) {
		argv[2] = dotrans(argv[2]);
	}
	if (loc && mapflag) {
		argv[2] = domap(argv[2]);
	}
E 15
E 5
E 3
D 4
	sendrequest("STOR", argv[1], argv[2]);
E 4
I 4
	sendrequest(cmd, argv[1], argv[2]);
E 4
}

/*
D 3
 * Receive a single file.
E 3
I 3
D 5
 * Send one or more files.
E 5
I 5
 * Send multiple files.
E 5
E 3
 */
I 3
mput(argc, argv)
	char *argv[];
{
D 4
	char **cpp, *dst;
E 4
I 4
D 7
	char **cpp, **gargs = NULL;
E 7
I 7
	register int i;
I 15
	int ointer, (*oldintr)(), mabort();
	extern jmp_buf jabort;
	char *tp;
E 15
E 7
E 4
D 5
	int i;
E 5

D 4
	if (!connected) {
		printf("Not connected.\n");
		return;
E 4
I 4
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(local-files) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
E 4
	}
	if (argc < 2) {
D 4
		printf("%s local-file remote-file, or\n", argv[0]);
E 4
D 15
		printf("%s local-files\n", argv[0]);
E 15
I 15
		printf("usage:%s local-files\n", argv[0]);
		code = -1;
E 15
		return;
	}
I 15
	mname = argv[0];
	mflag = 1;
	oldintr = signal(SIGINT, mabort);
	(void) setjmp(jabort);
	if (proxy) {
		char *cp, *tp2, tmpbuf[MAXPATHLEN];

D 16
		while ((cp = remglob(argc, argv, 0)) != NULL) {
E 16
I 16
		while ((cp = remglob(argv,0)) != NULL) {
E 16
			if (*cp == 0) {
				mflag = 0;
				continue;
			}
			if (mflag && confirm(argv[0], cp)) {
				tp = cp;
				if (mcase) {
					while (*tp && !islower(*tp)) {
						tp++;
					}
					if (!*tp) {
						tp = cp;
						tp2 = tmpbuf;
						while ((*tp2 = *tp) != NULL) {
						     if (isupper(*tp2)) {
						        *tp2 = 'a' + *tp2 - 'A';
						     }
						     tp++;
						     tp2++;
						}
					}
					tp = tmpbuf;
				}
				if (ntflag) {
					tp = dotrans(tp);
				}
				if (mapflag) {
					tp = domap(tp);
				}
				sendrequest((sunique) ? "STOU" : "STOR", cp,tp);
				if (!mflag && fromatty) {
					ointer = interactive;
					interactive = 1;
					if (confirm("Continue with","mput")) {
						mflag++;
					}
					interactive = ointer;
				}
			}
		}
		(void) signal(SIGINT, oldintr);
		mflag = 0;
		return;
	}
E 15
D 4
	if (argc == 3)  {
		if (!globulize(&argv[1]))
E 4
I 4
D 7
	cpp = argv + 1;
	if (doglob) {
		gargs = glob(cpp);
E 7
I 7
	for (i = 1; i < argc; i++) {
		register char **cpp, **gargs;

		if (!doglob) {
D 15
			if (confirm(argv[0], argv[i]))
				sendrequest("STOR", argv[i], argv[i]);
E 15
I 15
			if (mflag && confirm(argv[0], argv[i])) {
				tp = (ntflag) ? dotrans(argv[i]) : argv[i];
				tp = (mapflag) ? domap(tp) : tp;
				sendrequest((sunique) ? "STOU" : "STOR",
				            argv[i], tp);
				if (!mflag && fromatty) {
					ointer = interactive;
					interactive = 1;
					if (confirm("Continue with","mput")) {
						mflag++;
					}
					interactive = ointer;
				}
			}
E 15
			continue;
		}
		gargs = glob(argv[i]);
E 7
		if (globerr != NULL) {
			printf("%s\n", globerr);
			if (gargs)
				blkfree(gargs);
E 4
D 7
			return;
E 7
I 7
			continue;
E 7
D 4
		sendrequest("STOR", argv[1], argv[2]);
		return;
	}
	/*
	 * Check for shell metacharacters which we might
	 * want to expand into a list of file names.
	 */
	for (i = 1; i < argc; i++) {
		if (!doglob) {
			if (!skip(argv[0], argv[i]))
				sendrequest("STOR", argv[i], argv[i]);
			continue;
E 4
		}
I 7
D 15
		for (cpp = gargs; cpp && *cpp != NULL; cpp++)
			if (confirm(argv[0], *cpp))
				sendrequest("STOR", *cpp, *cpp);
E 15
I 15
		for (cpp = gargs; cpp && *cpp != NULL; cpp++) {
			if (mflag && confirm(argv[0], *cpp)) {
				tp = (ntflag) ? dotrans(*cpp) : *cpp;
				tp = (mapflag) ? domap(tp) : tp;
				sendrequest((sunique) ? "STOU" : "STOR",
					   *cpp, tp);
				if (!mflag && fromatty) {
					ointer = interactive;
					interactive = 1;
					if (confirm("Continue with","mput")) {
						mflag++;
					}
					interactive = ointer;
				}
			}
		}
E 15
		if (gargs != NULL)
			blkfree(gargs);
E 7
D 4
		cpp = glob(argv[i]);
		if (globerr != NULL) {
			printf("%s: %s\n", argv[i], globerr);
			if (cpp)
				blkfree(cpp);
			continue;
		}
		if (cpp == NULL) {
			printf("%s: no match\n", argv[i]);
			continue;
		}
		while (*cpp != NULL) {
			if (!skip(argv[0], *cpp))
				sendrequest("STOR", *cpp, *cpp);
			free(*cpp), cpp++;
		}
E 4
	}
I 15
	(void) signal(SIGINT, oldintr);
	mflag = 0;
E 15
I 4
D 7
	if (gargs != NULL)
		cpp = gargs;
	for (; *cpp != NULL; cpp++)
		if (confirm(argv[0], *cpp))
			sendrequest("STOR", *cpp, *cpp);
	if (gargs != NULL)
		blkfree(gargs);
E 7
E 4
}

/*
 * Receive one file.
 */
E 3
get(argc, argv)
	char *argv[];
{
I 15
	int loc = 0;
E 15
D 3
	int fd;
	register int n, addr;
	register char *cp;
	char *src;
E 3

D 4
	if (!connected) {
		printf("Not connected.\n");
		return;
	}
E 4
D 15
	if (argc == 2)
		argc++, argv[2] = argv[1];
E 15
I 15
	if (argc == 2) {
		argc++;
		argv[2] = argv[1];
		loc++;
	}
E 15
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(remote-file) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
usage:
D 3
		printf("%s remote-file local-file\n", argv[0]);
E 3
I 3
D 15
		printf("%s remote-file [ local-file ]\n", argv[0]);
E 15
I 15
		printf("usage: %s remote-file [ local-file ]\n", argv[0]);
		code = -1;
E 15
E 3
		return;
	}
	if (argc < 3) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(local-file) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 3) 
		goto usage;
I 3
D 15
	if (!globulize(&argv[2]))
E 15
I 15
	if (!globulize(&argv[2])) {
		code = -1;
E 15
		return;
I 15
	}
	if (loc && mcase) {
		char *tp = argv[1], *tp2, tmpbuf[MAXPATHLEN];

		while (*tp && !islower(*tp)) {
			tp++;
		}
		if (!*tp) {
			tp = argv[2];
			tp2 = tmpbuf;
			while ((*tp2 = *tp) != NULL) {
				if (isupper(*tp2)) {
					*tp2 = 'a' + *tp2 - 'A';
				}
				tp++;
				tp2++;
			}
			argv[2] = tmpbuf;
		}
	}
	if (loc && ntflag) {
		argv[2] = dotrans(argv[2]);
	}
	if (loc && mapflag) {
		argv[2] = domap(argv[2]);
	}
E 15
E 3
D 4
	recvrequest("RETR", argv[2], argv[1]);
E 4
I 4
	recvrequest("RETR", argv[2], argv[1], "w");
E 4
}

I 15
mabort()
{
	int ointer;
	extern jmp_buf jabort;

	printf("\n");
	(void) fflush(stdout);
	if (mflag && fromatty) {
		ointer = interactive;
		interactive = 1;
		if (confirm("Continue with", mname)) {
			interactive = ointer;
			longjmp(jabort,0);
		}
		interactive = ointer;
	}
	mflag = 0;
	longjmp(jabort,0);
}

E 15
I 3
/*
 * Get multiple files.
 */
mget(argc, argv)
	char *argv[];
{
D 4
	char temp[16], *dst, dstpath[MAXPATHLEN], buf[MAXPATHLEN];
	FILE *ftemp;
	int madedir = 0, oldverbose;
	struct stat stb;
E 4
I 4
D 5
	register char *cp;
E 5
I 5
D 15
	char *cp;
E 15
I 15
	char *cp, *tp, *tp2, tmpbuf[MAXPATHLEN];
	int ointer, (*oldintr)(), mabort();
	extern jmp_buf jabort;
E 15
E 5
E 4

D 4
	if (!connected) {
		printf("Not connected.\n");
		return;
	}
	if (argc == 2)
		argc++, argv[2] = argv[1];
E 4
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
D 5
		printf("(remote-directory) ");
E 5
I 5
		printf("(remote-files) ");
E 5
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
D 4
usage:
		printf("%s remote-directory [ local-directory ], or\n",
			argv[0]);
		printf("%s remote-files local-directory\n", argv[0]);
E 4
I 4
D 15
		printf("%s remote-files\n", argv[0]);
E 15
I 15
		printf("usage:%s remote-files\n", argv[0]);
		code = -1;
E 15
E 4
		return;
	}
D 4
	if (argc < 3) {
		strcat(line, " ");
		printf("(local-directory) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
E 4
I 4
D 15
	while ((cp = remglob(argc, argv)) != NULL)
		if (confirm(argv[0], cp))
			recvrequest("RETR", cp, cp, "w");
E 15
I 15
	mname = argv[0];
	mflag = 1;
	oldintr = signal(SIGINT,mabort);
	(void) setjmp(jabort);
D 16
	while ((cp = remglob(argc, argv, proxy)) != NULL) {
E 16
I 16
	while ((cp = remglob(argv,proxy)) != NULL) {
E 16
		if (*cp == '\0') {
			mflag = 0;
			continue;
		}
		if (mflag && confirm(argv[0], cp)) {
			tp = cp;
			if (mcase) {
				while (*tp && !islower(*tp)) {
					tp++;
				}
				if (!*tp) {
					tp = cp;
					tp2 = tmpbuf;
					while ((*tp2 = *tp) != NULL) {
						if (isupper(*tp2)) {
							*tp2 = 'a' + *tp2 - 'A';
						}
						tp++;
						tp2++;
					}
				}
				tp = tmpbuf;
			}
			if (ntflag) {
				tp = dotrans(tp);
			}
			if (mapflag) {
				tp = domap(tp);
			}
			recvrequest("RETR", tp, cp, "w");
			if (!mflag && fromatty) {
				ointer = interactive;
				interactive = 1;
				if (confirm("Continue with","mget")) {
					mflag++;
				}
				interactive = ointer;
			}
		}
	}
	(void) signal(SIGINT,oldintr);
	mflag = 0;
E 15
}

char *
D 15
remglob(argc, argv)
E 15
I 15
D 16
remglob(argc, argv, doswitch)
	int argc, doswitch;
E 16
I 16
remglob(argv,doswitch)
E 16
E 15
	char *argv[];
I 16
	int doswitch;
E 16
{
D 5
	char temp[16], *cp;
E 5
I 5
	char temp[16];
E 5
	static char buf[MAXPATHLEN];
	static FILE *ftemp = NULL;
	static char **args;
D 7
	int oldverbose;
E 7
I 7
	int oldverbose, oldhash;
E 7
I 5
	char *cp, *mode;
E 5

I 15
	if (!mflag) {
		if (!doglob) {
			args = NULL;
		}
		else {
			if (ftemp) {
D 16
				fclose(ftemp);
E 16
I 16
				(void) fclose(ftemp);
E 16
				ftemp = NULL;
			}
		}
		return(NULL);
	}
E 15
	if (!doglob) {
D 5
		if (argc == NULL)
E 5
I 5
		if (args == NULL)
E 5
			args = argv;
		if ((cp = *++args) == NULL)
			args = NULL;
		return (cp);
E 4
	}
D 4
	if (argc < 3) 
		goto usage;
	dst = argv[argc - 1];
	if (!globulize(&dst))
		return;
	/*
	 * If destination doesn't exist,
	 * try and create it.
	 */
	if (stat(dst, &stb) < 0) {
		if (mkdir(dst, 0777) < 0) {
			perror(dst);
E 4
I 4
	if (ftemp == NULL) {
D 16
		strcpy(temp, "/tmp/ftpXXXXXX");
		mktemp(temp);
E 16
I 16
		(void) strcpy(temp, "/tmp/ftpXXXXXX");
		(void) mktemp(temp);
E 16
		oldverbose = verbose, verbose = 0;
I 7
		oldhash = hash, hash = 0;
I 15
		if (doswitch) {
			pswitch(!proxy);
		}
E 15
E 7
D 5
		recvrequest("NLST", temp, argv[1], "w");
E 5
I 5
		for (mode = "w"; *++argv != NULL; mode = "a")
			recvrequest ("NLST", temp, *argv, mode);
I 15
		if (doswitch) {
			pswitch(!proxy);
		}
E 15
E 5
D 7
		verbose = oldverbose;
E 7
I 7
		verbose = oldverbose; hash = oldhash;
E 7
		ftemp = fopen(temp, "r");
D 16
		unlink(temp);
E 16
I 16
		(void) unlink(temp);
E 16
		if (ftemp == NULL) {
			printf("can't find list of remote files, oops\n");
E 4
D 5
			return;
E 5
I 5
			return (NULL);
E 5
		}
D 4
		madedir++;
	} else {
		if ((stb.st_mode & S_IFMT) != S_IFDIR) {
			printf("%s: not a directory\n", dst);
			return;
		}
E 4
	}
D 4
	/*
	 * Multiple files, just get each one without an nlst.
	 */
	if (argc > 3) {
		int i;

		for (i = 1; i < argc - 1; i++)
			recvrequest("RETR",
			  sprintf(dstpath, "%s/%s", dst, argv[i]), argv[i]);
		return;
E 4
I 4
	if (fgets(buf, sizeof (buf), ftemp) == NULL) {
D 16
		fclose(ftemp), ftemp = NULL;
E 16
I 16
		(void) fclose(ftemp), ftemp = NULL;
E 16
		return (NULL);
E 4
	}
D 4
	/*
	 * Get a directory full of files.  Perform an
	 * nlst to find the file names, then retrieve
	 * each individually.  If prompting is on, ask
	 * before grabbing each file.
	 */
	strcpy(temp, "/tmp/ftpXXXXXX");
	mktemp(temp);
	oldverbose = verbose, verbose = 0;
	recvrequest("NLST", temp, argv[1]);
	verbose = oldverbose;
	ftemp = fopen(temp, "r");
	unlink(temp);
	if (ftemp == NULL) {
		printf("can't find list of remote files, oops\n");
		if (madedir)
			(void) rmdir(dst);
		return;
	}
	while (fgets(buf, sizeof (buf), ftemp) != NULL) {
		char *cp = index(buf, '\n');

		if (cp)
			*cp = '\0';
		if (skip(argv[0], buf))
			continue;
		recvrequest("RETR", sprintf(dstpath, "%s/%s", dst, buf), buf);
	}
	fclose(ftemp);
E 4
I 4
	if ((cp = index(buf, '\n')) != NULL)
		*cp = '\0';
	return (buf);
E 4
}

E 3
char *
onoff(bool)
	int bool;
{

	return (bool ? "on" : "off");
}

/*
 * Show status.
 */
I 16
/*ARGSUSED*/
E 16
status(argc, argv)
	char *argv[];
{
I 15
	int i;
E 15

	if (connected)
		printf("Connected to %s.\n", hostname);
	else
		printf("Not connected.\n");
I 15
	if (!proxy) {
		pswitch(1);
		if (connected) {
			printf("Connected for proxy commands to %s.\n", hostname);
		}
		else {
			printf("No proxy connection.\n");
		}
		pswitch(0);
	}
E 15
	printf("Mode: %s; Type: %s; Form: %s; Structure: %s\n",
		modename, typename, formname, structname);
D 3
	printf("Verbose: %s; Bell: %s; Prompting: %s\n", 
		onoff(verbose), onoff(bell), onoff(interactive));
E 3
I 3
	printf("Verbose: %s; Bell: %s; Prompting: %s; Globbing: %s\n", 
		onoff(verbose), onoff(bell), onoff(interactive),
		onoff(doglob));
I 15
	printf("Store unique: %s; Receive unique: %s\n", onoff(sunique),
		onoff(runique));
	printf("Case: %s; CR stripping: %s\n",onoff(mcase),onoff(crflag));
	if (ntflag) {
		printf("Ntrans: (in) %s (out) %s\n", ntin,ntout);
	}
	else {
		printf("Ntrans: off\n");
	}
	if (mapflag) {
		printf("Nmap: (in) %s (out) %s\n", mapin, mapout);
	}
	else {
		printf("Nmap: off\n");
	}
E 15
I 4
D 7
	printf("Hash mark printing: %s; Use of PORT cmds: %s\n",
		onoff(hash), onoff(sendport));
E 7
I 7
D 9
	printf("Hash mark printing: %s; Use of PORT cmds: %s; Linger: %s\n",
		onoff(hash), onoff(sendport), onoff(linger));
E 9
I 9
	printf("Hash mark printing: %s; Use of PORT cmds: %s\n",
		onoff(hash), onoff(sendport));
I 15
	if (macnum > 0) {
		printf("Macros:\n");
		for (i=0; i<macnum; i++) {
			printf("\t%s\n",macros[i].mac_name);
		}
	}
	code = 0;
E 15
E 9
E 7
E 4
E 3
}

/*
 * Set beep on cmd completed mode.
 */
/*VARARGS*/
setbell()
{

	bell = !bell;
	printf("Bell mode %s.\n", onoff(bell));
I 15
	code = bell;
E 15
}

/*
 * Turn on packet tracing.
 */
/*VARARGS*/
settrace()
{

	trace = !trace;
	printf("Packet tracing %s.\n", onoff(trace));
I 15
	code = trace;
E 15
}

/*
I 4
 * Toggle hash mark printing during transfers.
 */
/*VARARGS*/
sethash()
{

	hash = !hash;
	printf("Hash mark printing %s", onoff(hash));
I 15
	code = hash;
E 15
	if (hash)
		printf(" (%d bytes/hash mark)", BUFSIZ);
	printf(".\n");
}

/*
E 4
 * Turn on printing of server echo's.
 */
/*VARARGS*/
setverbose()
{

	verbose = !verbose;
	printf("Verbose mode %s.\n", onoff(verbose));
I 15
	code = verbose;
E 15
}

/*
I 4
 * Toggle PORT cmd use before each data connection.
 */
/*VARARGS*/
setport()
{

	sendport = !sendport;
	printf("Use of PORT cmds %s.\n", onoff(sendport));
I 15
	code = sendport;
E 15
}

/*
E 4
 * Turn on interactive prompting
 * during mget, mput, and mdelete.
 */
/*VARARGS*/
setprompt()
{

	interactive = !interactive;
	printf("Interactive mode %s.\n", onoff(interactive));
I 15
	code = interactive;
E 15
}

/*
I 3
 * Toggle metacharacter interpretation
 * on local file names.
 */
/*VARARGS*/
setglob()
{
	
	doglob = !doglob;
	printf("Globbing %s.\n", onoff(doglob));
I 15
	code = doglob;
E 15
}

/*
E 3
 * Set debugging mode on/off and/or
 * set level of debugging.
 */
I 5
/*VARARGS*/
E 5
D 3
/*VARARGS*/
E 3
setdebug(argc, argv)
	char *argv[];
{
	int val;

	if (argc > 1) {
		val = atoi(argv[1]);
		if (val < 0) {
			printf("%s: bad debugging value.\n", argv[1]);
I 15
			code = -1;
E 15
			return;
		}
	} else
		val = !debug;
	debug = val;
	if (debug)
		options |= SO_DEBUG;
	else
		options &= ~SO_DEBUG;
	printf("Debugging %s (debug=%d).\n", onoff(debug), debug);
I 15
	code = debug > 0;
E 15
D 9
}

/*
I 7
 * Set linger on data connections on/off.
 */
/*VARARGS*/
setlinger(argc, argv)
	char *argv[];
{

	if (argc == 1)
		linger = !linger;
	else
		linger = atoi(argv[1]);
	if (argc == 1 || linger == 0) {
		printf("Linger on data connection close %s.\n", onoff(linger));
		return;
	}
	printf("Will linger for %d seconds on close of data connections.\n",
	   linger);
E 9
}

/*
E 7
 * Set current working directory
 * on remote machine.
 */
cd(argc, argv)
	char *argv[];
{

D 5
	if (!connected) {
		printf("Not connected.\n");
		return;
	}
E 5
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(remote-directory) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
D 15
		printf("%s remote-directory\n", argv[0]);
E 15
I 15
		printf("usage:%s remote-directory\n", argv[0]);
		code = -1;
E 15
		return;
	}
	(void) command("CWD %s", argv[1]);
}

D 3
#include <pwd.h>

E 3
/*
 * Set current working directory
 * on local machine.
 */
lcd(argc, argv)
	char *argv[];
{
D 3
	static struct passwd *pw = NULL;
E 3
I 3
	char buf[MAXPATHLEN];
D 5
	extern char *home;
E 5
E 3

D 3
	if (argc < 2) {
		if (pw == NULL) {
			pw = getpwnam(getlogin());
			if (pw == NULL)
				pw = getpwuid(getuid());
		}
		if (pw == NULL) {
			printf("ftp: can't find home directory.\n");
			return;
		}
		argc++, argv[1] = pw->pw_dir;
	}
E 3
I 3
	if (argc < 2)
		argc++, argv[1] = home;
E 3
	if (argc != 2) {
D 15
		printf("%s local-directory\n", argv[0]);
E 15
I 15
		printf("usage:%s local-directory\n", argv[0]);
		code = -1;
E 15
		return;
	}
D 3
	if (chdir(argv[1]) < 0)
E 3
I 3
D 15
	if (!globulize(&argv[1]))
E 15
I 15
	if (!globulize(&argv[1])) {
		code = -1;
E 15
		return;
I 15
	}
E 15
	if (chdir(argv[1]) < 0) {
E 3
		perror(argv[1]);
I 15
		code = -1;
E 15
I 3
		return;
	}
	printf("Local directory now %s\n", getwd(buf));
I 15
	code = 0;
E 15
E 3
}

/*
 * Delete a single file.
 */
delete(argc, argv)
	char *argv[];
{

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(remote-file) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
D 15
		printf("%s remote-file\n", argv[0]);
E 15
I 15
		printf("usage:%s remote-file\n", argv[0]);
		code = -1;
E 15
		return;
	}
	(void) command("DELE %s", argv[1]);
}

/*
I 4
 * Delete multiple files.
 */
mdelete(argc, argv)
	char *argv[];
{
	char *cp;
I 15
	int ointer, (*oldintr)(), mabort();
	extern jmp_buf jabort;
E 15

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(remote-files) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
D 15
		printf("%s remote-files\n", argv[0]);
E 15
I 15
		printf("usage:%s remote-files\n", argv[0]);
		code = -1;
E 15
		return;
	}
D 15
	while ((cp = remglob(argc, argv)) != NULL)
		if (confirm(argv[0], cp))
E 15
I 15
	mname = argv[0];
	mflag = 1;
	oldintr = signal(SIGINT, mabort);
	(void) setjmp(jabort);
D 16
	while ((cp = remglob(argc, argv, 0)) != NULL) {
E 16
I 16
	while ((cp = remglob(argv,0)) != NULL) {
E 16
		if (*cp == '\0') {
			mflag = 0;
			continue;
		}
		if (mflag && confirm(argv[0], cp)) {
E 15
			(void) command("DELE %s", cp);
I 15
			if (!mflag && fromatty) {
				ointer = interactive;
				interactive = 1;
				if (confirm("Continue with", "mdelete")) {
					mflag++;
				}
				interactive = ointer;
			}
		}
	}
	(void) signal(SIGINT, oldintr);
	mflag = 0;
E 15
}
I 5

E 5
/*
E 4
 * Rename a remote file.
 */
renamefile(argc, argv)
	char *argv[];
{

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(from-name) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
usage:
		printf("%s from-name to-name\n", argv[0]);
I 15
		code = -1;
E 15
		return;
	}
	if (argc < 3) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(to-name) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 3) 
		goto usage;
	if (command("RNFR %s", argv[1]) == CONTINUE)
		(void) command("RNTO %s", argv[2]);
}

/*
 * Get a directory listing
 * of remote files.
 */
ls(argc, argv)
	char *argv[];
{
D 4
	char *cmd;
E 4
I 4
D 5
	char *cmd, *mode;
	int i;
E 5
I 5
	char *cmd;
E 5
E 4

I 20
	if (argc == 2 && (argv[1][0] == '|' || argv[1][0] == '>')) {
		argc++;
		argv[2] = argv[1];
		argv[1] = NULL;
		if (argv[2][0] == '>')
			argv[2]++;
	}
E 20
	if (argc < 2)
		argc++, argv[1] = NULL;
	if (argc < 3)
		argc++, argv[2] = "-";
I 5
	if (argc > 3) {
		printf("usage: %s remote-directory local-file\n", argv[0]);
I 15
		code = -1;
E 15
		return;
	}
E 5
D 4
	if (argc > 3) {
		printf("usage: %s remote-directory local-file\n", argv[0]);
		return;
	}
E 4
	cmd = argv[0][0] == 'l' ? "NLST" : "LIST";
I 3
D 15
	if (strcmp(argv[2], "-") && !globulize(&argv[2]))
E 15
I 15
	if (strcmp(argv[2], "-") && !globulize(&argv[2])) {
		code = -1;
E 15
		return;
I 15
	}
I 17
	if (strcmp(argv[2], "-") && *argv[2] != '|')
		if (!globulize(&argv[2]) || !confirm("output to local-file:", argv[2])) {
			code = -1;
			return;
	}
E 17
E 15
E 3
D 4
	recvrequest(cmd, argv[2], argv[1]);
E 4
I 4
D 5
	mode = argc > 3 ? "a" : "w";
	for (i = 1; i < argc - 1; i++)
		recvrequest(cmd, argv[argc - 1], argv[i], mode);
E 5
I 5
	recvrequest(cmd, argv[2], argv[1], "w");
E 5
E 4
}

/*
I 5
 * Get a directory listing
 * of multiple remote files.
 */
mls(argc, argv)
	char *argv[];
{
D 7
	char *cmd, *mode;
	int i, dest;
E 7
I 7
D 15
	char *cmd, *mode, *cp, *dest;
E 15
I 15
	char *cmd, mode[1], *dest;
	int ointer, i, (*oldintr)(), mabort();
	extern jmp_buf jabort;
E 15
E 7

D 7
	if (argc < 2)
		argc++, argv[1] = NULL;
	if (argc < 3)
		argc++, argv[2] = "-";
	dest = argc - 1;
	cmd = argv[0][1] == 'l' ? "NLST" : "LIST";
	if (strcmp(argv[dest], "-") != 0)
		if (globulize(&argv[dest]) && confirm("local-file", argv[dest]))
E 7
I 7
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(remote-files) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 3) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(local-file) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 3) {
D 15
		printf("%s remote-files local-file\n", argv[0]);
E 15
I 15
		printf("usage:%s remote-files local-file\n", argv[0]);
		code = -1;
E 15
		return;
	}
	dest = argv[argc - 1];
	argv[argc - 1] = NULL;
D 15
	if (strcmp(dest, "-"))
D 10
		if (globulize(&dest) && confirm("local-file", dest))
E 10
I 10
		if (!globulize(&dest) || !confirm("local-file", dest))
E 15
I 15
	if (strcmp(dest, "-") && *dest != '|')
		if (!globulize(&dest) || !confirm("output to local-file:", dest)) {
			code = -1;
E 15
E 10
E 7
			return;
I 15
	}
E 15
D 7
	for (i = 1, mode = "w"; i < dest; i++, mode = "a")
		recvrequest(cmd, argv[dest], argv[i], mode);
E 7
I 7
	cmd = argv[0][1] == 'l' ? "NLST" : "LIST";
D 15
	for (mode = "w"; cp = remglob(argc, argv); mode = "a")
		if (confirm(argv[0], cp))
			recvrequest(cmd, dest, cp, mode);
E 15
I 15
	mname = argv[0];
	mflag = 1;
	oldintr = signal(SIGINT, mabort);
	(void) setjmp(jabort);
	for (i = 1; mflag && i < argc-1; ++i) {
		*mode = (i == 1) ? 'w' : 'a';
		recvrequest(cmd, dest, argv[i], mode);
		if (!mflag && fromatty) {
			ointer = interactive;
			interactive = 1;
			if (confirm("Continue with", argv[0])) {
				mflag ++;
			}
			interactive = ointer;
		}
	}
	(void) signal(SIGINT, oldintr);
	mflag = 0;
E 15
E 7
}

/*
E 5
 * Do a shell escape
 */
I 16
/*ARGSUSED*/
E 16
shell(argc, argv)
	char *argv[];
{
I 5
D 15
	int pid, status, (*old1)(), (*old2)();
	char shellnam[40], *shell, *namep;
	char **cpp, **gargs;
E 15
I 15
D 16
	int i, pid, status, (*old1)(), (*old2)();
E 16
I 16
	int pid, (*old1)(), (*old2)();
E 16
	char shellnam[40], *shell, *namep; 
I 16
	union wait status;
E 16
E 15
E 5

D 5
	printf("Sorry, this function is unimplemented.\n");
E 5
I 5
	old1 = signal (SIGINT, SIG_IGN);
	old2 = signal (SIGQUIT, SIG_IGN);
	if ((pid = fork()) == 0) {
		for (pid = 3; pid < 20; pid++)
D 16
			close(pid);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
E 16
I 16
			(void) close(pid);
		(void) signal(SIGINT, SIG_DFL);
		(void) signal(SIGQUIT, SIG_DFL);
E 16
I 14
		shell = getenv("SHELL");
		if (shell == NULL)
			shell = "/bin/sh";
		namep = rindex(shell,'/');
		if (namep == NULL)
			namep = shell;
E 14
D 15
		if (argc <= 1) {
D 14
			shell = getenv("SHELL");
			if (shell == NULL)
				shell = "/bin/sh";
			namep = rindex(shell,'/');
			if (namep == NULL)
				namep = shell;
			strcpy(shellnam,"-");
			strcat(shellnam, ++namep);
			if (strcmp(namep, "sh") != 0)
				shellnam[0] = '+';
E 14
			if (debug) {
				printf ("%s\n", shell);
				fflush (stdout);
			}
D 14
			execl(shell, shellnam, 0);
			perror(shell);
			exit(1);
		}
		cpp = &argv[1];
		if (argc > 2) {
			if ((gargs = glob(cpp)) != NULL)
				cpp = gargs;
			if (globerr != NULL) {
				printf("%s\n", globerr);
				exit(1);
E 14
I 14
			execl(shell, shell, (char *)0);
		} else {
			char *args[4];	/* "sh" "-c" <command> NULL */

			args[0] = shell;
			args[1] = "-c";
			args[2] = argv[1];
			args[3] = NULL;
			if (debug) {
				printf("%s -c %s\n", shell, argv[1]);
				fflush(stdout);
E 14
			}
I 14
			execv(shell, args);
E 15
I 15
D 16
		strcpy(shellnam,"-");
		strcat(shellnam, ++namep);
E 16
I 16
		(void) strcpy(shellnam,"-");
		(void) strcat(shellnam, ++namep);
E 16
		if (strcmp(namep, "sh") != 0)
			shellnam[0] = '+';
		if (debug) {
			printf ("%s\n", shell);
D 16
			fflush (stdout);
E 16
I 16
			(void) fflush (stdout);
E 16
E 15
E 14
		}
I 15
		if (argc > 1) {
			execl(shell,shellnam,"-c",altarg,(char *)0);
		}
		else {
			execl(shell,shellnam,(char *)0);
		}
E 15
D 14
		if (debug) {
			register char **zip = cpp;

			printf("%s", *zip);
			while (*++zip != NULL)
				printf(" %s", *zip);
			printf("\n");
			fflush(stdout);
		}
		execvp(argv[1], cpp);
		perror(argv[1]);
E 14
I 14
		perror(shell);
I 15
		code = -1;
E 15
E 14
		exit(1);
D 15
	}
E 15
I 15
		}
E 15
	if (pid > 0)
		while (wait(&status) != pid)
			;
D 16
	signal(SIGINT, old1);
	signal(SIGQUIT, old2);
E 16
I 16
	(void) signal(SIGINT, old1);
	(void) signal(SIGQUIT, old2);
E 16
D 15
	if (pid == -1)
E 15
I 15
	if (pid == -1) {
E 15
		perror("Try again later");
I 15
		code = -1;
	}
	else {
		code = 0;
	}
E 15
	return (0);
E 5
}

/*
 * Send new user information (re-login)
 */
user(argc, argv)
	int argc;
	char **argv;
{
D 16
	char acct[80], *getpass();
E 16
I 16
	char acct[80], *mygetpass();
E 16
D 15
	int n;
E 15
I 15
	int n, aflag = 0;
E 15

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(username) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc > 4) {
		printf("usage: %s username [password] [account]\n", argv[0]);
I 15
		code = -1;
E 15
D 5
		return;
E 5
I 5
		return (0);
E 5
	}
	n = command("USER %s", argv[1]);
	if (n == CONTINUE) {
		if (argc < 3 )
D 16
			argv[2] = getpass("Password: "), argc++;
E 16
I 16
			argv[2] = mygetpass("Password: "), argc++;
E 16
		n = command("PASS %s", argv[2]);
	}
	if (n == CONTINUE) {
		if (argc < 4) {
			printf("Account: "); (void) fflush(stdout);
			(void) fgets(acct, sizeof(acct) - 1, stdin);
			acct[strlen(acct) - 1] = '\0';
			argv[3] = acct; argc++;
		}
D 15
		n = command("ACCT %s", acct);
E 15
I 15
		n = command("ACCT %s", argv[3]);
		aflag++;
E 15
	}
	if (n != COMPLETE) {
D 16
		fprintf(stderr, "Login failed.\n");
E 16
I 16
		fprintf(stdout, "Login failed.\n");
E 16
		return (0);
	}
I 15
	if (!aflag && argc == 4) {
		(void) command("ACCT %s", argv[3]);
	}
E 15
	return (1);
}

/*
 * Print working directory.
 */
/*VARARGS*/
pwd()
{
D 5
	if (!connected) {
		printf("Not connected.\n");
		return;
	}
E 5
I 5

E 5
D 15
	(void) command("XPWD");
E 15
I 15
	(void) command("PWD");
E 15
}

/*
 * Make a directory.
 */
makedir(argc, argv)
	char *argv[];
{

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(directory-name) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
D 15
		printf("%s directory-name\n", argv[0]);
E 15
I 15
		printf("usage: %s directory-name\n", argv[0]);
		code = -1;
E 15
		return;
	}
D 15
	(void) command("XMKD %s", argv[1]);
E 15
I 15
	(void) command("MKD %s", argv[1]);
E 15
}

/*
 * Remove a directory.
 */
removedir(argc, argv)
	char *argv[];
{

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(directory-name) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
D 15
		printf("%s directory-name\n", argv[0]);
E 15
I 15
		printf("usage: %s directory-name\n", argv[0]);
		code = -1;
E 15
		return;
	}
D 15
	(void) command("XRMD %s", argv[1]);
E 15
I 15
	(void) command("RMD %s", argv[1]);
E 15
}

/*
 * Send a line, verbatim, to the remote machine.
 */
quote(argc, argv)
	char *argv[];
{
	int i;
	char buf[BUFSIZ];

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(command line to send) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
		printf("usage: %s line-to-send\n", argv[0]);
I 15
		code = -1;
E 15
		return;
	}
D 16
	strcpy(buf, argv[1]);
E 16
I 16
	(void) strcpy(buf, argv[1]);
E 16
	for (i = 2; i < argc; i++) {
D 16
		strcat(buf, " ");
		strcat(buf, argv[i]);
E 16
I 16
		(void) strcat(buf, " ");
		(void) strcat(buf, argv[i]);
E 16
	}
D 15
	(void) command(buf);
E 15
I 15
	if (command(buf) == PRELIM) {
		while (getreply(0) == PRELIM);
	}
E 15
}

/*
 * Ask the other side for help.
 */
rmthelp(argc, argv)
	char *argv[];
{
	int oldverbose = verbose;

	verbose = 1;
	(void) command(argc == 1 ? "HELP" : "HELP %s", argv[1]);
	verbose = oldverbose;
}

/*
 * Terminate session and exit.
 */
/*VARARGS*/
quit()
{

D 11
	disconnect();
E 11
I 11
	if (connected)
		disconnect();
I 15
	pswitch(1);
	if (connected) {
		disconnect();
	}
E 15
E 11
	exit(0);
}

/*
 * Terminate session, but don't exit.
 */
disconnect()
{
	extern FILE *cout;
	extern int data;

	if (!connected)
		return;
	(void) command("QUIT");
D 15
	(void) fclose(cout);
E 15
I 15
	if (cout) {
		(void) fclose(cout);
	}
E 15
	cout = NULL;
	connected = 0;
	data = -1;
I 15
	if (!proxy) {
		macnum = 0;
	}
E 15
I 3
}

D 4
skip(cmd, file)
E 4
I 4
confirm(cmd, file)
E 4
	char *cmd, *file;
{
	char line[BUFSIZ];

	if (!interactive)
D 4
		return (0);
E 4
I 4
		return (1);
E 4
	printf("%s %s? ", cmd, file);
D 16
	fflush(stdout);
	gets(line);
E 16
I 16
	(void) fflush(stdout);
	(void) gets(line);
E 16
D 4
	return (*line == 'y');
E 4
I 4
	return (*line != 'n' && *line != 'N');
E 4
}

fatal(msg)
	char *msg;
{

D 16
	fprintf(stderr, "ftp: %s\n");
E 16
I 16
	fprintf(stderr, "ftp: %s\n", msg);
E 16
	exit(1);
}

/*
 * Glob a local file name specification with
 * the expectation of a single return value.
 * Can't control multiple values being expanded
 * from the expression, we return only the first.
 */
globulize(cpp)
	char **cpp;
{
	char **globbed;

	if (!doglob)
		return (1);
	globbed = glob(*cpp);
	if (globerr != NULL) {
		printf("%s: %s\n", *cpp, globerr);
		if (globbed)
			blkfree(globbed);
		return (0);
	}
	if (globbed) {
		*cpp = *globbed++;
		/* don't waste too much memory */
		if (*globbed)
			blkfree(globbed);
	}
	return (1);
I 15
}

account(argc,argv)

	int argc;
	char **argv;
{
D 16
	char acct[50], *getpass(), *ap;
E 16
I 16
	char acct[50], *mygetpass(), *ap;
E 16

	if (argc > 1) {
		++argv;
		--argc;
		(void) strncpy(acct,*argv,49);
		acct[50] = '\0';
		while (argc > 1) {
			--argc;
			++argv;
			(void) strncat(acct,*argv, 49-strlen(acct));
		}
		ap = acct;
	}
	else {
D 16
		ap = getpass("Account:");
E 16
I 16
		ap = mygetpass("Account:");
E 16
	}
	(void) command("ACCT %s", ap);
}

jmp_buf abortprox;

proxabort()
{
	extern int proxy;

	if (!proxy) {
		pswitch(1);
	}
	if (connected) {
		proxflag = 1;
	}
	else {
		proxflag = 0;
	}
	pswitch(0);
	longjmp(abortprox,1);
}

doproxy(argc,argv)
	int argc;
	char *argv[];
{
	int (*oldintr)(), proxabort();
	register struct cmd *c;
	struct cmd *getcmd();
	extern struct cmd cmdtab[];
	extern jmp_buf abortprox;

	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(command) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
		printf("usage:%s command\n", argv[0]);
		code = -1;
		return;
	}
	c = getcmd(argv[1]);
	if (c == (struct cmd *) -1) {
		printf("?Ambiguous command\n");
D 16
		fflush(stdout);
E 16
I 16
		(void) fflush(stdout);
E 16
		code = -1;
		return;
	}
	if (c == 0) {
		printf("?Invalid command\n");
D 16
		fflush(stdout);
E 16
I 16
		(void) fflush(stdout);
E 16
		code = -1;
		return;
	}
	if (!c->c_proxy) {
		printf("?Invalid proxy command\n");
D 16
		fflush(stdout);
E 16
I 16
		(void) fflush(stdout);
E 16
		code = -1;
		return;
	}
	if (setjmp(abortprox)) {
		code = -1;
		return;
	}
	oldintr = signal(SIGINT, proxabort);
	pswitch(1);
	if (c->c_conn && !connected) {
		printf("Not connected\n");
D 16
		fflush(stdout);
E 16
I 16
		(void) fflush(stdout);
E 16
		pswitch(0);
		(void) signal(SIGINT, oldintr);
		code = -1;
		return;
	}
	(*c->c_handler)(argc-1, argv+1);
	if (connected) {
		proxflag = 1;
	}
	else {
		proxflag = 0;
	}
	pswitch(0);
	(void) signal(SIGINT, oldintr);
}

setcase()
{
	mcase = !mcase;
	printf("Case mapping %s.\n", onoff(mcase));
	code = mcase;
}

setcr()
{
	crflag = !crflag;
	printf("Carriage Return stripping %s.\n", onoff(crflag));
	code = crflag;
}

setntrans(argc,argv)
	int argc;
	char *argv[];
{
	if (argc == 1) {
		ntflag = 0;
		printf("Ntrans off.\n");
		code = ntflag;
		return;
	}
	ntflag++;
	code = ntflag;
	(void) strncpy(ntin, argv[1], 16);
	ntin[16] = '\0';
	if (argc == 2) {
		ntout[0] = '\0';
		return;
	}
	(void) strncpy(ntout, argv[2], 16);
	ntout[16] = '\0';
}

char *
dotrans(name)
	char *name;
{
	static char new[MAXPATHLEN];
	char *cp1, *cp2 = new;
	register int i, ostop, found;

	for (ostop = 0; *(ntout + ostop) && ostop < 16; ostop++);
	for (cp1 = name; *cp1; cp1++) {
		found = 0;
		for (i = 0; *(ntin + i) && i < 16; i++) {
			if (*cp1 == *(ntin + i)) {
				found++;
				if (i < ostop) {
					*cp2++ = *(ntout + i);
				}
				break;
			}
		}
		if (!found) {
			*cp2++ = *cp1;
		}
	}
	*cp2 = '\0';
	return(new);
}

setnmap(argc, argv)
	int argc;
	char *argv[];
{
	char *cp;

	if (argc == 1) {
		mapflag = 0;
		printf("Nmap off.\n");
		code = mapflag;
		return;
	}
	if (argc < 3) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(mapout) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 3) {
		printf("Usage: %s [mapin mapout]\n",argv[0]);
		code = -1;
		return;
	}
	mapflag = 1;
	code = 1;
	cp = index(altarg, ' ');
	if (proxy) {
		while(*++cp == ' ');
		altarg = cp;
		cp = index(altarg, ' ');
	}
	*cp = '\0';
	(void) strncpy(mapin, altarg, MAXPATHLEN - 1);
	while (*++cp == ' ');
	(void) strncpy(mapout, cp, MAXPATHLEN - 1);
}

char *
domap(name)
	char *name;
{
	static char new[MAXPATHLEN];
	register char *cp1 = name, *cp2 = mapin;
	char *tp[9], *te[9];
	int i, toks[9], toknum, match = 1;

	for (i=0; i < 9; ++i) {
		toks[i] = 0;
	}
	while (match && *cp1 && *cp2) {
		switch (*cp2) {
			case '\\':
				if (*++cp2 != *cp1) {
					match = 0;
				}
				break;
			case '$':
				if (*(cp2+1) >= '1' && (*cp2+1) <= '9') {
					if (*cp1 != *(++cp2+1)) {
						toks[toknum = *cp2 - '1']++;
						tp[toknum] = cp1;
						while (*++cp1 && *(cp2+1)
							!= *cp1);
						te[toknum] = cp1;
					}
					cp2++;
					break;
				}
				/* intentional drop through */
			default:
				if (*cp2 != *cp1) {
					match = 0;
				}
				break;
		}
		if (*cp1) {
			cp1++;
		}
		if (*cp2) {
			cp2++;
		}
	}
	cp1 = new;
	*cp1 = '\0';
	cp2 = mapout;
	while (*cp2) {
		match = 0;
		switch (*cp2) {
			case '\\':
				if (*(cp2 + 1)) {
					*cp1++ = *++cp2;
				}
				break;
			case '[':
LOOP:
				if (*++cp2 == '$' && isdigit(*(cp2+1))) { 
					if (*++cp2 == '0') {
						char *cp3 = name;

						while (*cp3) {
							*cp1++ = *cp3++;
						}
						match = 1;
					}
					else if (toks[toknum = *cp2 - '1']) {
						char *cp3 = tp[toknum];

						while (cp3 != te[toknum]) {
							*cp1++ = *cp3++;
						}
						match = 1;
					}
				}
				else {
					while (*cp2 && *cp2 != ',' && 
					    *cp2 != ']') {
						if (*cp2 == '\\') {
							cp2++;
						}
						else if (*cp2 == '$' &&
   						        isdigit(*(cp2+1))) {
							if (*++cp2 == '0') {
							   char *cp3 = name;

							   while (*cp3) {
								*cp1++ = *cp3++;
							   }
							}
							else if (toks[toknum =
							    *cp2 - '1']) {
							   char *cp3=tp[toknum];

							   while (cp3 !=
								  te[toknum]) {
								*cp1++ = *cp3++;
							   }
							}
						}
						else if (*cp2) {
							*cp1++ = *cp2++;
						}
					}
					if (!*cp2) {
						printf("nmap: unbalanced brackets\n");
						return(name);
					}
					match = 1;
					cp2--;
				}
				if (match) {
					while (*++cp2 && *cp2 != ']') {
					      if (*cp2 == '\\' && *(cp2 + 1)) {
							cp2++;
					      }
					}
					if (!*cp2) {
						printf("nmap: unbalanced brackets\n");
						return(name);
					}
					break;
				}
				switch (*++cp2) {
					case ',':
						goto LOOP;
					case ']':
						break;
					default:
						cp2--;
						goto LOOP;
				}
				break;
			case '$':
				if (isdigit(*(cp2 + 1))) {
					if (*++cp2 == '0') {
						char *cp3 = name;

						while (*cp3) {
							*cp1++ = *cp3++;
						}
					}
					else if (toks[toknum = *cp2 - '1']) {
						char *cp3 = tp[toknum];

						while (cp3 != te[toknum]) {
							*cp1++ = *cp3++;
						}
					}
					break;
				}
				/* intentional drop through */
			default:
				*cp1++ = *cp2;
				break;
		}
		cp2++;
	}
	*cp1 = '\0';
	if (!*new) {
		return(name);
	}
	return(new);
}

setsunique()
{
	sunique = !sunique;
	printf("Store unique %s.\n", onoff(sunique));
	code = sunique;
}

setrunique()
{
	runique = !runique;
	printf("Receive unique %s.\n", onoff(runique));
	code = runique;
}

/* change directory to perent directory */
cdup()
{
	(void) command("CDUP");
}

macdef(argc, argv)
	int argc;
	char *argv[];
{
	char *tmp;
	int c;

	if (macnum == 16) {
		printf("Limit of 16 macros have already been defined\n");
		code = -1;
		return;
	}
	if (argc < 2) {
D 16
		strcat(line, " ");
E 16
I 16
		(void) strcat(line, " ");
E 16
		printf("(macro name) ");
D 16
		gets(&line[strlen(line)]);
E 16
I 16
		(void) gets(&line[strlen(line)]);
E 16
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc != 2) {
		printf("Usage: %s macro_name\n",argv[0]);
		code = -1;
		return;
	}
	if (interactive) {
		printf("Enter macro line by line, terminating it with a null line\n");
	}
D 16
	strncpy(macros[macnum].mac_name, argv[1], 8);
E 16
I 16
	(void) strncpy(macros[macnum].mac_name, argv[1], 8);
E 16
	if (macnum == 0) {
		macros[macnum].mac_start = macbuf;
	}
	else {
		macros[macnum].mac_start = macros[macnum - 1].mac_end + 1;
	}
	tmp = macros[macnum].mac_start;
	while (tmp != macbuf+4096) {
		if ((c = getchar()) == EOF) {
			printf("macdef:end of file encountered\n");
			code = -1;
			return;
		}
		if ((*tmp = c) == '\n') {
			if (tmp == macros[macnum].mac_start) {
				macros[macnum++].mac_end = tmp;
				code = 0;
				return;
			}
			if (*(tmp-1) == '\0') {
				macros[macnum++].mac_end = tmp - 1;
				code = 0;
				return;
			}
			*tmp = '\0';
		}
		tmp++;
	}
	while (1) {
		while ((c = getchar()) != '\n' && c != EOF);
		if (c == EOF || getchar() == '\n') {
			printf("Macro not defined - 4k buffer exceeded\n");
			code = -1;
			return;
		}
	}
E 15
E 3
}
E 1
