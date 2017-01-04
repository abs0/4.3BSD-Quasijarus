h20085
s 00000/00000/00127
d D 4.1 83/07/25 20:11:25 eric 15 14
c 4.2 release version
e
s 00008/00004/00119
d D 3.12 82/12/27 09:49:01 eric 14 13
c remove useful.h references so that it can be compiled from normal place
e
s 00010/00010/00113
d D 3.11 82/05/31 18:50:42 eric 13 12
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00001/00001/00122
d D 3.10 82/03/30 07:00:34 eric 12 11
c make it work with new format headers (no ... remote from... lines);
c this was supposed to work before (sigh)
e
s 00004/00001/00119
d D 3.9 82/03/22 21:12:06 eric 11 10
c strip off parentheses from recipient names -- to keep sendmail from
c treating them as comments.
e
s 00009/00005/00111
d D 3.8 82/03/16 08:40:03 eric 10 9
c hack to pass badly formatted mail through reasonably
e
s 00008/00002/00108
d D 3.7 82/03/07 09:33:18 eric 9 8
c check exit status more carefully
e
s 00003/00003/00107
d D 3.6 81/12/06 12:40:16 eric 8 7
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00022/00016/00088
d D 3.5 81/10/31 23:12:21 eric 7 6
c work with more sophisticated addresses as well as garbage ones
e
s 00002/00002/00102
d D 3.4 81/10/26 14:23:12 eric 6 4
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00001/00000/00104
d D 3.3.1.1 81/09/23 18:23:39 eric 5 4
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00001/00001/00103
d D 3.3 81/09/06 19:49:33 eric 4 3
c cleanup, commenting, linting, etc.
e
s 00001/00001/00103
d D 3.2 81/09/06 11:57:40 eric 3 2
c mail back errors (perhaps this is why mail gets lost.....)
e
s 00046/00036/00058
d D 3.1 81/09/06 11:53:07 eric 2 1
c handle multiple users; know about sendmail
e
s 00094/00000/00000
d D 1.1 81/09/06 11:31:30 eric 1 0
c date and time created 81/09/06 11:31:30 by eric
e
u
U
f b 
f i 
f t (Berkeley)
t
T
I 1
/*
D 7
 * rmail: front end for mail to stack up those stupid >From ... remote from ...
 * lines and make a correct return address.  This works with the -f option
D 2
 * to /etc/delivermail so it won't work on systems without delivermail.
E 2
I 2
 * to /usr/lib/sendmail so it won't work on systems without sendmail.
E 2
 * However, it ought to be easy to modify a standard /bin/mail to do the
 * same thing.
 *
 * NOTE: Rmail is SPECIFICALLY INTENDED for ERNIE COVAX because of its
 * physical position as a gateway between the uucp net and the arpanet.
 * By default, other sites will probably want /bin/rmail to be a link
 * to /bin/mail, as it was intended by BTL.  However, other than the
 * (somewhat annoying) loss of information about when the mail was
 * originally sent, rmail should work OK on other systems running uucp.
 * If you don't run uucp you don't even need any rmail.
 */
E 7
I 7
D 10
** rmail: front end for mail to stack up those stupid >From ... remote from ...
** lines and make a correct return address.  This works with the -f option
** to /usr/lib/sendmail so it won't work on systems without sendmail.
** However, it ought to be easy to modify a standard /bin/mail to do the
** same thing.
E 10
I 10
**  RMAIL -- UUCP mail server.
**
**	This program reads the >From ... remote from ... lines that
**	UUCP is so fond of and turns them into something reasonable.
**	It calls sendmail giving it a -f option built from these
**	lines.
E 10
*/
E 7

D 8
static char	SccsId[] =	"%W%	%G%";

E 8
D 2
#include <stdio.h>
FILE *popen();
char *index();
E 2
I 2
# include <stdio.h>
# include <sysexits.h>
D 14
# include "useful.h"
E 14
I 5
# include "conf.h"
E 5
E 2

I 8
D 14
SCCSID(%W%	%Y%	%G%);
E 14
I 14
static char	SccsId[] =	"%W%	%Y%	%G%";
E 14

E 8
D 2
#define MAILER	"/etc/delivermail"
E 2
I 2
D 14
extern FILE *popen();
extern char *index();
E 14
I 14
typedef char	bool;
#define TRUE	1
#define FALSE	0

extern FILE	*popen();
extern char	*index();
extern char	*rindex();
E 14
E 2

I 2
bool	Debug;

# define MAILER	"/usr/lib/sendmail"

E 2
main(argc, argv)
D 2
char **argv;
E 2
I 2
	char **argv;
E 2
{
D 2
	FILE *out;	/* output to delivermail */
E 2
I 2
	FILE *out;	/* output to sendmail */
E 2
	char lbuf[512];	/* one line of the message */
	char from[512];	/* accumulated path of sender */
	char ufrom[64];	/* user on remote system */
	char sys[64];	/* a system in path */
	char junk[512];	/* scratchpad */
D 2
	char cmd[512];
	char *to, *cp;
E 2
I 2
	char cmd[2000];
	register char *cp;
I 7
	register char *uf;	/* ptr into ufrom */
I 9
	int i;
E 9
E 7
E 2

D 2
	to = argv[1];
	if (argc != 2) {
		fprintf(stderr, "Usage: rmail user\n");
		exit(1);
E 2
I 2
# ifdef DEBUG
	if (argc > 1 && strcmp(argv[1], "-T") == 0)
	{
		Debug = TRUE;
		argc--;
		argv++;
E 2
	}
I 2
# endif DEBUG
E 2

D 2
	for (;;) {
E 2
I 2
	if (argc < 2)
	{
		fprintf(stderr, "Usage: rmail user ...\n");
		exit(EX_USAGE);
	}
I 10

D 13
	strcpy(from, "");
	strcpy(ufrom, "/dev/null");
E 13
I 13
	(void) strcpy(from, "");
	(void) strcpy(ufrom, "/dev/null");
E 13
E 10

	for (;;)
	{
E 2
D 4
		fgets(lbuf, sizeof lbuf, stdin);
E 4
I 4
		(void) fgets(lbuf, sizeof lbuf, stdin);
E 4
D 2
		if (strncmp(lbuf, "From ", 5) && strncmp(lbuf, ">From ", 6))
E 2
I 2
		if (strncmp(lbuf, "From ", 5) != 0 && strncmp(lbuf, ">From ", 6) != 0)
E 2
			break;
D 2
		/* sscanf(lbuf, "%s %s %s %s %s %s %s remote from %s", junk, ufrom, junk, junk, junk, junk, junk, sys); */
E 2
D 6
		sscanf(lbuf, "%s %s", junk, ufrom);
E 6
I 6
		(void) sscanf(lbuf, "%s %s", junk, ufrom);
E 6
		cp = lbuf;
I 7
		uf = ufrom;
E 7
D 2
		for (;;) {
E 2
I 2
		for (;;)
		{
E 2
			cp = index(cp+1, 'r');
			if (cp == NULL)
I 7
			{
				register char *p = rindex(uf, '!');

				if (p != NULL)
				{
					*p = '\0';
D 13
					strcpy(sys, uf);
E 13
I 13
					(void) strcpy(sys, uf);
E 13
					uf = p + 1;
					break;
				}
E 7
				cp = "remote from somewhere";
I 7
			}
E 7
#ifdef DEBUG
D 2
			printf("cp='%s'\n", cp);
E 2
I 2
			if (Debug)
				printf("cp='%s'\n", cp);
E 2
#endif
			if (strncmp(cp, "remote from ", 12)==0)
				break;
		}
D 6
		sscanf(cp, "remote from %s", sys);
E 6
I 6
D 7
		(void) sscanf(cp, "remote from %s", sys);
E 7
I 7
		if (cp != NULL)
			(void) sscanf(cp, "remote from %s", sys);
E 7
E 6
D 13
		strcat(from, sys);
		strcat(from, "!");
E 13
I 13
		(void) strcat(from, sys);
		(void) strcat(from, "!");
E 13
#ifdef DEBUG
D 2
		printf("ufrom='%s', sys='%s', from now '%s'\n", ufrom, sys, from);
E 2
I 2
		if (Debug)
D 7
			printf("ufrom='%s', sys='%s', from now '%s'\n", ufrom, sys, from);
E 7
I 7
			printf("ufrom='%s', sys='%s', from now '%s'\n", uf, sys, from);
E 7
E 2
#endif
	}
D 12
	strcat(from, ufrom);
E 12
I 12
D 13
	strcat(from, uf);
E 13
I 13
	(void) strcat(from, uf);
E 13
E 12

D 2
	sprintf(cmd, "%s -r%s %s", MAILER, from, to);
E 2
I 2
D 3
	sprintf(cmd, "%s -f%s", MAILER, from);
E 3
I 3
D 8
	sprintf(cmd, "%s -em -f%s", MAILER, from);
E 8
I 8
	(void) sprintf(cmd, "%s -em -f%s", MAILER, from);
E 8
E 3
	while (*++argv != NULL)
	{
D 13
		strcat(cmd, " '");
E 13
I 13
		(void) strcat(cmd, " '");
E 13
D 11
		strcat(cmd, *argv);
E 11
I 11
		if (**argv == '(')
D 13
			strncat(cmd, *argv + 1, strlen(*argv) - 2);
E 13
I 13
			(void) strncat(cmd, *argv + 1, strlen(*argv) - 2);
E 13
		else
D 13
			strcat(cmd, *argv);
E 11
		strcat(cmd, "'");
E 13
I 13
			(void) strcat(cmd, *argv);
		(void) strcat(cmd, "'");
E 13
	}
E 2
#ifdef DEBUG
D 2
	printf("cmd='%s'\n", cmd);
E 2
I 2
	if (Debug)
		printf("cmd='%s'\n", cmd);
E 2
#endif
	out = popen(cmd, "w");
	fputs(lbuf, out);
	while (fgets(lbuf, sizeof lbuf, stdin))
		fputs(lbuf, out);
D 9
	pclose(out);
E 9
I 9
	i = pclose(out);
	if ((i & 0377) != 0)
	{
		fprintf(stderr, "pclose: status 0%o\n", i);
		exit(EX_OSERR);
	}
E 9
D 2
}
E 2

D 2
/*
 * Return the ptr in sp at which the character c appears;
 * NULL if not found
 */

char *
index(sp, c)
register char *sp, c;
{
	do {
		if (*sp == c)
			return(sp);
	} while (*sp++);
	return(NULL);
E 2
I 2
D 9
	exit(EX_OK);
E 9
I 9
	exit((i >> 8) & 0377);
E 9
E 2
}
E 1
