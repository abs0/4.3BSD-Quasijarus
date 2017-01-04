h32264
s 00011/00008/00067
d D 5.5 88/06/29 22:00:45 bostic 11 10
c install approved copyright notice
e
s 00051/00042/00024
d D 5.4 88/04/21 17:17:16 bostic 10 9
c bring up to date
e
s 00002/00002/00064
d D 5.3 86/05/02 16:17:42 bloom 9 8
c  Fix problems with mailstats compiling and add to Makefile
e
s 00001/00001/00065
d D 5.2 86/05/02 11:29:23 bloom 8 7
c fix typo using sprintf instead of fprintf
e
s 00019/00000/00047
d D 5.1 85/06/07 15:58:09 dist 7 6
c Add copyright
e
s 00000/00000/00047
d D 4.1 83/07/25 20:11:21 eric 6 5
c 4.2 release version
e
s 00002/00002/00045
d D 3.5 82/03/20 16:21:01 eric 5 4
c fixes for PDP-11's
e
s 00002/00002/00045
d D 3.4 81/12/06 12:40:31 eric 4 3
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00001/00001/00046
d D 3.3 81/11/07 15:41:45 eric 3 2
c clean up to compile & work on ARPAVAX; move stat file to
c /usr/lib/sendmail.st; fix bug in syserr with error codes
e
s 00002/00000/00045
d D 3.2 81/09/12 18:00:30 eric 2 1
c print creation date
e
s 00045/00000/00000
d D 3.1 81/09/12 17:56:34 eric 1 0
c date and time created 81/09/12 17:56:34 by eric
e
u
U
t
T
I 7
/*
I 11
 * Copyright (c) 1983 Eric P. Allman
E 11
D 10
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
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
 *
D 11
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 11
 */
E 10

#ifndef lint
char copyright[] =
D 10
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 10
I 10
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
E 10
 All rights reserved.\n";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10

#ifndef lint
D 10
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10
E 7
I 1
D 9
# include "sendmail.h"
E 9

D 4
static char	SccsId[] =	"%W%	%G%";
E 4
I 4
D 9
SCCSID(%W%	%Y%	%G%);
E 9
I 9
D 10
# include "../src/sendmail.h"
# include "../src/mailstats.h"
E 10
I 10
#include <sys/file.h>
#include <sendmail.h>
#include <mailstats.h>
E 10
E 9
E 4

D 10
/*
**  MAILSTATS -- print mail statistics.
**
**	Flags:
**		-Ffile		Name of statistics file.
**
**	Exit Status:
**		zero.
*/

E 10
main(argc, argv)
D 10
	char  **argv;
E 10
I 10
	int argc;
	char **argv;
E 10
{
D 10
	register int fd;
E 10
I 10
	extern char *optarg;
	extern int optind;
E 10
	struct statistics stat;
D 3
	char *sfile = "/usr/eric/mailstats";
E 3
I 3
D 10
	char *sfile = "/usr/lib/sendmail.st";
E 10
E 3
	register int i;
I 2
D 10
	extern char *ctime();
E 10
I 10
	int ch, fd;
	char *sfile, *ctime();
E 10
E 2

D 10
	fd = open(sfile, 0);
	if (fd < 0)
	{
E 10
I 10
	sfile = "/usr/lib/sendmail.st";
	while ((ch = getopt(argc, argv, "f:")) != EOF)
		switch((char)ch) {
		case 'f':
			sfile = optarg;
			break;
		case '?':
		default:
			fputs("usage: mailstats [-f file]\n", stderr);
			exit(EX_USAGE);
		}
	argc -= optind;
	argv += optind;

	if ((fd = open(sfile, O_RDONLY)) < 0) {
		fputs("mailstats: ", stderr);
E 10
		perror(sfile);
		exit(EX_NOINPUT);
	}
D 10
	if (read(fd, &stat, sizeof stat) != sizeof stat ||
	    stat.stat_size != sizeof stat)
	{
D 4
		sprintf(stderr, "File size change\n");
E 4
I 4
D 8
		(void) sprintf(stderr, "File size change\n");
E 8
I 8
		(void) fprintf(stderr, "File size change\n");
E 10
I 10
	if (read(fd, &stat, sizeof(stat)) != sizeof(stat) ||
	    stat.stat_size != sizeof(stat)) {
		fputs("mailstats: file size changed.\n", stderr);
E 10
E 8
E 4
		exit(EX_OSERR);
	}

I 2
	printf("Statistics from %s", ctime(&stat.stat_itime));
E 2
	printf(" M msgsfr bytes_from  msgsto   bytes_to\n");
	for (i = 0; i < MAXMAILERS; i++)
D 10
	{
		if (stat.stat_nf[i] == 0 && stat.stat_nt[i] == 0)
			continue;
		printf("%2d ", i);
D 5
		printf("%6d %10dK ", stat.stat_nf[i], stat.stat_bf[i]);
		printf("%6d %10dK\n", stat.stat_nt[i], stat.stat_bt[i]);
E 5
I 5
		printf("%6ld %10ldK ", stat.stat_nf[i], stat.stat_bf[i]);
		printf("%6ld %10ldK\n", stat.stat_nt[i], stat.stat_bt[i]);
E 5
	}
E 10
I 10
		if (stat.stat_nf[i] || stat.stat_nt[i])
			printf("%2d %6ld %10ldK %6ld %10ldK\n", i,
			    stat.stat_nf[i], stat.stat_bf[i],
			    stat.stat_nt[i], stat.stat_bt[i]);
	exit(0);
E 10
}
E 1
