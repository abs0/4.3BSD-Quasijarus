h32112
s 00010/00005/00128
d D 5.6 88/06/29 21:43:10 bostic 6 5
c install approved copyright notice
e
s 00011/00005/00122
d D 5.5 88/02/01 16:16:32 bostic 5 4
c add Berkeley specific header
e
s 00004/00003/00123
d D 5.4 87/09/01 19:28:32 karels 4 3
c try to preserve To, etc (or translate from Apparently-To)
c to make redisted messages look right
e
s 00028/00002/00098
d D 5.3 87/05/02 12:45:02 bostic 3 2
c added code to make summary file prettier
e
s 00029/00032/00071
d D 5.2 87/04/11 15:38:41 bostic 2 1
c version #2; -f flag, remove home_dir, redist per folder
e
s 00103/00000/00000
d D 5.1 86/11/25 13:36:02 bostic 1 0
c date and time created 86/11/25 13:36:02 by bostic
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
D 5
static char sccsid[] = "%W% (Berkeley) %E%";
#endif not lint
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5

#include <bug.h>
#include <sys/stat.h>
D 2
#include <sys/dir.h>
E 2
#include <stdio.h>

D 3
static int	chk1();
E 3
I 3
static int	chk1(), pbuf();
E 3

#define ENT(X)	sizeof(X) - 1, X
HEADER	mailhead[] = {				/* mail headers */
	{ NO, YES,  NULL, ENT("Date:"), },
	{ NO,  NO,  NULL, ENT("From "), },
	{ NO, YES,  NULL, ENT("From:"), },
	{ NO,  NO,  chk1, ENT("Index:"), },
	{ NO, YES,  NULL, ENT("Message-Id:"), },
D 4
	{ NO,  NO,  NULL, ENT("Reply-To:"), },
	{ NO,  NO,  NULL, ENT("Return-Path:"), },
E 4
I 4
	{ NO, YES,  NULL, ENT("Reply-To:"), },
	{ NO, YES,  NULL, ENT("Return-Path:"), },
E 4
D 3
	{ NO,  NO,  NULL, ENT("Subject:"), },
E 3
I 3
	{ NO,  NO,  pbuf, ENT("Subject:"), },
E 3
D 4
	{ NO,  NO,  NULL, ENT("To:"), },
E 4
I 4
	{ NO, YES,  NULL, ENT("To:"), },
	{ NO,  NO,  NULL, ENT("Apparently-To:"), },
E 4
	{ ERR, }
};

D 2
extern short	do_redist,		/* if redistributing report */
		made_dist;		/* if dist file needs removing */
extern char	tmpname[];		/* temp bug report file */

char	*distf = TMP_FILE,		/* redist temp file */
	dir[MAXNAMLEN],			/* subject and folder */
E 2
I 2
FILE	*dfp;				/* distf file pointer */
char	dir[MAXNAMLEN],			/* subject and folder */
E 2
	folder[MAXNAMLEN];

/*
 * gethead --
 *	read mail and bug headers from bug report, construct redist headers
 */
D 2
gethead()
E 2
I 2
gethead(redist)
	int	redist;
E 2
{
	register HEADER	*hp;		/* mail header pointer */
D 2
	register FILE	*dfp;		/* distf file pointer */
	char	*strcpy(), *malloc(), *mktemp();
E 2
I 2
	char	*strcpy(), *malloc();
E 2

D 2
	if (do_redist && (!mktemp(distf) || !(dfp = fopen(distf,"w"))))
		error("unable to create redistribution file %s.",distf);
	made_dist = YES;
	if (!freopen(tmpname,"r",stdin))
		error("unable to read temporary bug file %s.",tmpname);
E 2
I 2
	if (redist) {
		int	fd;
		char	*distf;
E 2

D 2
	while (fgets(bfr,sizeof(bfr),stdin)) {
		for (hp = mailhead;hp->found != ERR;++hp)
E 2
I 2
		distf = "/tmp/BUG_XXXXXX";
		if (!(fd = mkstemp(distf)) || !(dfp = fdopen(fd, "w+")))
			error("can't create redistribution file %s.", distf);
		/* disappear after last reference is closed */
		(void)unlink(distf);
	}
	if (!freopen(tmpname, "r", stdin))
		error("can't read temporary bug file %s.", tmpname);

	while (fgets(bfr, sizeof(bfr), stdin)) {
		for (hp = mailhead; hp->found != ERR; ++hp)
E 2
			if (!hp->found)
D 2
				if (!strncmp(hp->tag,bfr,hp->len)) {
E 2
I 2
				if (!strncmp(hp->tag, bfr, hp->len)) {
E 2
					if (hp->valid && !((*(hp->valid))(bfr)))
						break;
					if (!(hp->line = malloc((u_int)(strlen(bfr) + 1))))
D 2
						error("unable to allocate space for header search.",CHN);
					strcpy(hp->line,bfr);
E 2
I 2
						error("malloc failed.", CHN);
					(void)strcpy(hp->line, bfr);
E 2
					hp->found = YES;
					break;
				}
D 2
		if ((hp->found == ERR || hp->redist) && do_redist)
			fputs(bfr,dfp);
E 2
I 2
		if ((hp->found == ERR || hp->redist) && redist)
			fputs(bfr, dfp);
E 2
	}

	if (!mailhead[INDX_TAG].found)
D 2
		error("no readable \"Index:\" header in bug report.",CHN);
	if (do_redist)
		fclose(dfp);
E 2
I 2
		error("no readable \"Index:\" header in bug report.", CHN);
E 2
}

/*
 * chk1 --
 *	parse the "Index:" line into folder and directory
 */
static
chk1(line)
D 2
char	*line;
E 2
I 2
	char	*line;
E 2
{
	register char	*C;		/* tmp pointer */
	struct stat	sbuf;		/* existence check */
	char	*index();

D 2
	if (sscanf(line," Index: %s %s ",folder,dir) != 2)
E 2
I 2
	if (sscanf(line, " Index: %s %s ", folder, dir) != 2)
E 2
		return(NO);
D 2

	/* backward compatible, deal with "bin/from.c" */
	if (C = index(folder,'/')) {
E 2
I 2
	if (C = index(folder, '/')) {	/* deal with "bin/from.c" */
E 2
		if (C == folder)
			return(NO);
		*C = EOS;
	}
D 2

	if (stat(dir,&sbuf) || (sbuf.st_mode & S_IFMT) != S_IFDIR)
E 2
I 2
	if (stat(dir, &sbuf) || (sbuf.st_mode & S_IFMT) != S_IFDIR)
E 2
		return(NO);
I 3
	(void)pbuf(line);
	return(YES);
}

/*
 * pbuf --
 *	kludge so that summary file looks pretty
 */
static
pbuf(line)
	char	*line;
{
	register char	*rp,			/* tmp pointers */
			*wp;

	for (rp = line; *rp == ' ' || *rp == '\t'; ++rp);
	for (wp = line; *rp; ++wp) {
		if ((*wp = *rp++) != ' ' && *wp != '\t')
			continue;
		*wp = ' ';
		while (*rp == ' ' || *rp == '\t')
			++rp;
	}
	if (wp[-1] == ' ')			/* wp can't == line */
		--wp;
	*wp = EOS;
E 3
	return(YES);
}
E 1
