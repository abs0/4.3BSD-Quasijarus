h44404
s 00010/00005/00055
d D 5.6 88/06/29 21:43:09 bostic 6 5
c install approved copyright notice
e
s 00011/00005/00049
d D 5.5 88/02/01 16:16:31 bostic 5 4
c add Berkeley specific header
e
s 00003/00003/00051
d D 5.4 87/07/21 11:35:58 bostic 4 3
c compress log file messages to single line
e
s 00001/00001/00053
d D 5.3 87/04/11 15:39:48 bostic 3 2
c added keywords
e
s 00014/00021/00040
d D 5.2 87/04/11 15:38:40 bostic 2 1
c version #2; -f flag, remove home_dir, redist per folder
e
s 00061/00000/00000
d D 5.1 86/11/25 13:33:09 bostic 1 0
c date and time created 86/11/25 13:33:09 by bostic
e
u
U
t
T
I 1
/*
D 5
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * Copyright (c) 1986, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %E%";
E 2
I 2
D 3
static char sccsid[] = "@(#)error.c	5.1 (Berkeley) 86/11/25";
E 3
I 3
D 5
static char sccsid[] = "%W% (Berkeley) %E%";
E 3
E 2
#endif not lint
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5

I 2
#include <bug.h>
E 2
#include <syslog.h>
#include <stdio.h>
D 2
#include <bug.h>
E 2

D 2
extern char	*distf,				/* redist temp file */
		tmpname[];			/* temporary file used */

short	made_dist;				/* if dist file made */

E 2
static short	err_redir;			/* stderr redirected */

/*
 * seterr --
 *	redirect stderr for error processing
 */
seterr()
{
D 2
	if (!freopen(ERROR_FILE,"a",stderr))
		error("unable to open error file %s.\n",ERROR_FILE);
E 2
I 2
	if (!freopen(ERROR_FILE, "a", stderr))
D 4
		error("can't open error file %s.\n", ERROR_FILE);
E 4
I 4
		error("can't open error file %s.", ERROR_FILE);
E 4
E 2
	err_redir = YES;
}

/*
 * error --
 *	write errors to log file and die
 */
D 2
error(fmt,arg)
register char	*fmt,
		*arg;
E 2
I 2
error(fmt, arg)
	register char	*fmt,
			*arg;
E 2
{
	static char	logmsg[MAXLINELEN];	/* syslog message */
	char	*strcpy(), *strcat();

	if (err_redir) {
		/* don't combine these, "fmt" may not require "arg" */
D 2
		fputc('\t',stderr);
		fprintf(stderr,fmt,arg);
		fprintf(stderr,"\n\ttemporary file is %s.\n",tmpname);
E 2
I 2
D 4
		fputc('\t', stderr);
E 4
I 4
		fprintf(stderr, "\t%s\n\t", tmpname);
E 4
		fprintf(stderr, fmt, arg);
D 4
		fprintf(stderr, "\n\ttemporary file is %s.\n", tmpname);
E 4
I 4
		fputc('\n', stderr);
E 4
E 2
	}
	else {
D 2
		strcat(strcpy(logmsg,"bugfiler: "),fmt);
		syslog(LOG_ERR,logmsg,arg);
E 2
I 2
		sprintf(logmsg, "bugfiler: %s", fmt);
		syslog(LOG_ERR, logmsg, arg);
E 2
	}
D 2
	if (made_dist)		/* unlink redist file if necessary */
		unlink(distf);
E 2
#ifdef METOO
	exit(ERR);
D 2
#else !METOO
E 2
I 2
#else
E 2
	exit(OK);
D 2
#endif METOO
E 2
I 2
#endif
E 2
}
E 1
