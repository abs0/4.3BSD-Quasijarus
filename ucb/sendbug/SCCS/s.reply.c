h06937
s 00010/00005/00078
d D 5.6 88/06/29 21:43:14 bostic 6 5
c install approved copyright notice
e
s 00011/00005/00072
d D 5.5 88/02/01 16:16:36 bostic 5 4
c add Berkeley specific header
e
s 00003/00002/00074
d D 5.4 87/11/23 10:44:43 bostic 4 3
c move acknowledgement file into folder directory
e
s 00001/00001/00075
d D 5.3 87/07/20 12:38:26 bostic 3 2
c added Precedence header for vacation program
e
s 00015/00018/00061
d D 5.2 87/04/11 15:38:46 bostic 2 1
c version #2; -f flag, remove home_dir, redist per folder
e
s 00079/00000/00000
d D 5.1 86/11/25 12:37:18 bostic 1 0
c date and time created 86/11/25 12:37:18 by bostic
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
D 4
#endif not lint
E 4
I 4
#endif /* !lint */
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5
E 4

#include <bug.h>
#include <sys/file.h>
#include <stdio.h>

D 2
extern HEADER	mailhead[];			/* mail headers */

E 2
/*
 * reply --
D 2
 *	tell the user we got their bug report
E 2
I 2
 *	tell the user we got their silly little bug report
E 2
 */
reply()
{
	register char	*C,			/* traveling pointer */
			*to;			/* who we're replying to */
	register int	afd,			/* ack file descriptor */
			rval;			/* return value */
	FILE	*pf,				/* pipe pointer */
		*popen();
D 2
	char	*mktemp(), *strcpy(), *index();
E 2
I 2
	char	*index();
E 2

	if (mailhead[RPLY_TAG].found) {
		for (C = mailhead[RPLY_TAG].line + mailhead[RPLY_TAG].len;*C != '\n' && (*C == ' ' || *C == '\t');++C);
		if (*C)
			goto gotone;
	}
	if (mailhead[FROM_TAG].found) {
		for (C = mailhead[FROM_TAG].line + mailhead[FROM_TAG].len;*C != '\n' && (*C == ' ' || *C == '\t');++C);
		if (*C)
			goto gotone;
	}
	if (mailhead[CFROM_TAG].found) {
		for (C = mailhead[CFROM_TAG].line + mailhead[CFROM_TAG].len;*C != '\n' && (*C == ' ' || *C == '\t');++C);
		if (*C)
			goto gotone;
	}
	return;

	/* if it's a foo <XXX>, get the XXX, else get foo (first string) */
D 2
gotone:	if (to = index(C,'<'))
E 2
I 2
gotone:	if (to = index(C, '<'))
E 2
		for (C = ++to;*C != '\n' && *C != ' ' && *C != '\t' && *C != '>';++C);
	else {
		to = C;
		for (to = C++;*C != '\n' && *C != ' ' && *C != '\t';++C);
	}
	*C = EOS;

D 2
	if (!(pf = popen(MAIL_CMD,"w")))
		error("sendmail pipe failed.",CHN);
E 2
I 2
	if (!(pf = popen(MAIL_CMD, "w")))
		error("sendmail pipe failed.", CHN);
E 2

D 2
	fprintf(pf,"Reply-To: %s\nFrom: %s (Bugs Bunny)\nTo: %s\n",BUGS_HOME,BUGS_HOME,to);
E 2
I 2
	fprintf(pf, "Reply-To: %s\nFrom: %s (Bugs Bunny)\nTo: %s\n", BUGS_HOME, BUGS_HOME, to);
E 2
	if (mailhead[SUBJ_TAG].found)
D 2
		fprintf(pf,"Subject: Re:%s",mailhead[SUBJ_TAG].line + mailhead[SUBJ_TAG].len);
E 2
I 2
		fprintf(pf, "Subject: Re:%s", mailhead[SUBJ_TAG].line + mailhead[SUBJ_TAG].len);
E 2
	else
D 2
		fputs("Subject: Bug report acknowledgement.\n",pf);
E 2
I 2
		fputs("Subject: Bug report acknowledgement.\n", pf);
E 2
	if (mailhead[DATE_TAG].found)
D 2
		fprintf(pf,"In-Acknowledgement-Of: Your message of %s",mailhead[DATE_TAG].line + mailhead[DATE_TAG].len);
E 2
I 2
		fprintf(pf, "In-Acknowledgement-Of: Your message of %s", mailhead[DATE_TAG].line + mailhead[DATE_TAG].len);
E 2
	if (mailhead[MSG_TAG].found)
D 2
		fprintf(pf,"\t\t%s",mailhead[MSG_TAG].line);
	putc('\n',pf);
E 2
I 2
		fprintf(pf, "\t\t%s", mailhead[MSG_TAG].line);
D 3
	putc('\n', pf);
E 3
I 3
	fputs("Precedence: bulk\n\n", pf);	/* vacation(1) uses this... */
E 3
E 2
	fflush(pf);

D 2
	if ((afd = open(ACK_FILE,O_RDONLY,0)) >= 0) {
		while ((rval = read(afd,bfr,sizeof(bfr))) != ERR && rval)
			write(fileno(pf),bfr,rval);
		close(afd);
E 2
I 2
D 4
	if ((afd = open(ACK_FILE, O_RDONLY, 0)) >= 0) {
E 4
I 4
	(void)sprintf(bfr, "%s/%s", dir, ACK_FILE);
	if ((afd = open(bfr, O_RDONLY, 0)) >= 0) {
E 4
		while ((rval = read(afd, bfr, sizeof(bfr))) != ERR && rval)
			(void)write(fileno(pf), bfr, rval);
		(void)close(afd);
E 2
	}
D 2

E 2
	pclose(pf);
}
E 1
