h50023
s 00010/00005/00209
d D 6.8 88/06/29 21:50:55 bostic 8 7
c install approved copyright notice
e
s 00001/00000/00213
d D 6.7 88/06/06 09:34:28 bostic 7 6
c add LOG_UUCP
e
s 00010/00005/00203
d D 6.6 88/05/27 11:38:05 karels 6 5
c don't ignore long arguments
e
s 00080/00095/00128
d D 6.5 88/05/24 09:46:46 bostic 5 4
c add getopt, don't overflow with command line arguments, use strcasecmp
c instead of converting string, don't need most of these buffers
c add Berkeley header, written by Eric Allman
e
s 00000/00001/00223
d D 6.4 86/10/27 21:42:15 eric 4 3
c tut tut....  LOG_MARK doesn't belong here
e
s 00004/00000/00220
d D 6.3 86/10/27 19:24:00 eric 3 2
c add mark, syslog, lpr, news facilities
e
s 00001/00000/00219
d D 6.2 85/09/19 02:15:14 eric 2 1
c add "daemon" to list of known facility names
e
s 00219/00000/00000
d D 6.1 85/09/17 20:26:21 eric 1 0
c enter messages in system log -- new with 4.3 Beta release
e
u
U
f b 
f i 
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 5
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#include <stdio.h>
#include <syslog.h>
#include <ctype.h>

/*
**  LOGGER -- read and log utility
**
**	This routine reads from an input and arranges to write the
**	result on the system log, along with a useful tag.
*/

main(argc, argv)
	int argc;
	char **argv;
{
D 5
	char buf[200];
	char *tag;
	register char *p;
E 5
I 5
	extern char *optarg;
	extern int optind;
E 5
	int pri = LOG_NOTICE;
D 5
	int logflags = 0;
	extern char *getlogin();
E 5
I 5
	int ch, logflags = 0;
	char *tag, buf[200], *getlogin();
E 5

D 5
	/* initialize */
	tag = getlogin();

	/* crack arguments */
	while (--argc > 0)
	{
		p = *++argv;
		if (*p != '-')
			break;

		switch (*++p)
		{
		  case '\0':		/* dummy */
			/* this can be used to give null parameters */
			break;

		  case 't':		/* tag */
			if (argc > 1 && argv[1][0] != '-')
			{
				argc--;
				tag = *++argv;
E 5
I 5
	tag = NULL;
	while ((ch = getopt(argc, argv, "f:ip:t:")) != EOF)
		switch((char)ch) {
		case 'f':		/* file to log */
			if (freopen(optarg, "r", stdin) == NULL) {
				fprintf("logger: ");
				perror(optarg);
				exit(1);
E 5
			}
D 5
			else
				tag = NULL;
E 5
			break;
D 5

		  case 'p':		/* priority */
			if (argc > 1 && argv[1][0] != '-')
			{
				argc--;
				pri = pencode(*++argv);
			}
			break;

		  case 'i':		/* log process id also */
E 5
I 5
		case 'i':		/* log process id also */
E 5
			logflags |= LOG_PID;
			break;
D 5

		  case 'f':		/* file to log */
			if (argc > 1 && argv[1][0] != '-')
			{
				argc--;
				if (freopen(*++argv, "r", stdin) == NULL)
				{
					fprintf("logger: ");
					perror(*argv);
					exit(1);
				}
			}
E 5
I 5
		case 'p':		/* priority */
			pri = pencode(optarg);
E 5
			break;
D 5

		  default:
			fprintf(stderr, "logger: unknown flag -%s\n", p);
E 5
I 5
		case 't':		/* tag */
			tag = optarg;
E 5
			break;
I 5
		case '?':
		default:
			usage();
E 5
		}
D 5
	}
E 5
I 5
	argc -= optind;
	argv += optind;
E 5

	/* setup for logging */
D 5
	openlog(tag, logflags, 0);
E 5
I 5
	openlog(tag ? tag : getlogin(), logflags, 0);
E 5
	(void) fclose(stdout);

	/* log input line if appropriate */
D 5
	if (argc > 0)
	{
		char buf[120];
E 5
I 5
	if (argc > 0) {
		register char *p, *endp;
		int len;
E 5

D 5
		buf[0] = '\0';
		while (argc-- > 0)
		{
			strcat(buf, " ");
			strcat(buf, *argv++);
E 5
I 5
		for (p = buf, endp = buf + sizeof(buf) - 1;;) {
			len = strlen(*argv);
D 6
			if (p + len < endp) {
E 6
I 6
			if (p + len < endp && p > buf) {
				*--p = '\0';
				syslog(pri, buf);
				p = buf;
			}
			if (len > sizeof(buf) - 1) {
				syslog(pri, *argv++);
				if (!--argc)
					break;
			} else {
E 6
				bcopy(*argv++, p, len);
				p += len;
				if (!--argc)
					break;
				*p++ = ' ';
D 6
			}
			else {
E 6
				*--p = '\0';
D 6
				syslog(pri, buf);
				p = buf;
E 6
			}
E 5
		}
D 5
		syslog(pri, buf + 1);
E 5
I 5
		if (p != buf) {
			*p = '\0';
			syslog(pri, buf);
		}
E 5
		exit(0);
	}

	/* main loop */
D 5
	while (fgets(buf, sizeof buf, stdin) != NULL)
E 5
I 5
	while (fgets(buf, sizeof(buf), stdin) != NULL)
E 5
		syslog(pri, buf);

	exit(0);
}


struct code {
	char	*c_name;
	int	c_val;
};

struct code	PriNames[] = {
	"panic",	LOG_EMERG,
	"emerg",	LOG_EMERG,
	"alert",	LOG_ALERT,
	"crit",		LOG_CRIT,
	"err",		LOG_ERR,
	"error",	LOG_ERR,
	"warn",		LOG_WARNING,
	"warning",	LOG_WARNING,
	"notice",	LOG_NOTICE,
	"info",		LOG_INFO,
	"debug",	LOG_DEBUG,
	NULL,		-1
};

struct code	FacNames[] = {
	"kern",		LOG_KERN,
	"user",		LOG_USER,
	"mail",		LOG_MAIL,
I 2
	"daemon",	LOG_DAEMON,
E 2
	"auth",		LOG_AUTH,
	"security",	LOG_AUTH,
I 3
D 4
	"mark",		LOG_MARK,
E 4
	"syslog",	LOG_SYSLOG,
	"lpr",		LOG_LPR,
	"news",		LOG_NEWS,
I 7
	"uucp",		LOG_UUCP,
E 7
E 3
	"local0",	LOG_LOCAL0,
	"local1",	LOG_LOCAL1,
	"local2",	LOG_LOCAL2,
	"local3",	LOG_LOCAL3,
	"local4",	LOG_LOCAL4,
	"local5",	LOG_LOCAL5,
	"local6",	LOG_LOCAL6,
	"local7",	LOG_LOCAL7,
	NULL,		-1
};


/*
 *  Decode a symbolic name to a numeric value
 */

pencode(s)
	register char *s;
{
D 5
	register char *p;
	int lev;
	int fac;
	char buf[100];
E 5
I 5
	char *save;
	int fac, lev;
E 5

D 5
	for (p = buf; *s && *s != '.'; )
		*p++ = *s++;
	*p = '\0';
	if (*s++) {
		fac = decode(buf, FacNames);
E 5
I 5
	for (save = s; *s && *s != '.'; ++s);
	if (*s) {
		*s = '\0';
		fac = decode(save, FacNames);
E 5
		if (fac < 0)
D 5
			bailout("unknown facility name: ", buf);
		for (p = buf; *p++ = *s++; )
			continue;
	} else
E 5
I 5
			bailout("unknown facility name: ", save);
		*s++ = '.';
	}
	else {
E 5
		fac = 0;
D 5
	lev = decode(buf, PriNames);
E 5
I 5
		s = save;
	}
	lev = decode(s, PriNames);
E 5
	if (lev < 0)
D 5
		bailout("unknown priority name: ", buf);

E 5
I 5
		bailout("unknown priority name: ", save);
E 5
	return ((lev & LOG_PRIMASK) | (fac & LOG_FACMASK));
}


decode(name, codetab)
	char *name;
	struct code *codetab;
{
	register struct code *c;
D 5
	register char *p;
	char buf[40];
E 5

	if (isdigit(*name))
		return (atoi(name));

D 5
	(void) strcpy(buf, name);
	for (p = buf; *p; p++)
		if (isupper(*p))
			*p = tolower(*p);
E 5
	for (c = codetab; c->c_name; c++)
D 5
		if (!strcmp(buf, c->c_name))
E 5
I 5
		if (!strcasecmp(name, c->c_name))
E 5
			return (c->c_val);

	return (-1);
}

D 5
bailout(a, b)
	char *a, *b;
E 5
I 5
bailout(msg, arg)
	char *msg, *arg;
E 5
{
D 5
	fprintf(stderr, "logger: %s%s\n", a, b);
E 5
I 5
	fprintf(stderr, "logger: %s%s\n", msg, arg);
	exit(1);
}

usage()
{
	fputs("logger: [-i] [-f file] [-p pri] [-t tag] [ message ... ]\n",
	    stderr);
E 5
	exit(1);
}
E 1
