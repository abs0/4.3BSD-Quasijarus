h17656
s 00010/00005/00089
d D 5.8 88/06/29 21:43:13 bostic 9 8
c install approved copyright notice
e
s 00008/00002/00086
d D 5.7 88/04/01 13:30:02 karels 8 7
c don't let sendmail add apparently-to lines (always have a To: line)
e
s 00011/00005/00077
d D 5.6 88/02/01 16:16:35 bostic 7 6
c add Berkeley specific header
e
s 00046/00045/00036
d D 5.5 87/12/12 18:14:41 bostic 6 4
c handle "all" keyword, minor cleanups
e
s 00047/00045/00036
d R 5.5 87/11/23 10:56:21 bostic 5 4
c add "all:" label
e
s 00002/00001/00079
d D 5.4 87/09/01 19:28:33 karels 4 3
c try to preserve To, etc (or translate from Apparently-To)
c to make redisted messages look right
e
s 00000/00001/00080
d D 5.3 87/04/11 16:00:58 bostic 3 2
c cleaner unlink of redist file
e
s 00025/00031/00056
d D 5.2 87/04/11 15:38:44 bostic 2 1
c version #2; -f flag, remove home_dir, redist per folder
e
s 00087/00000/00000
d D 5.1 86/11/25 12:37:10 bostic 1 0
c date and time created 86/11/25 12:37:10 by bostic
e
u
U
t
T
I 1
/*
D 7
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * Copyright (c) 1986, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 7
 */

#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %E%";
D 6
#endif not lint
E 6
I 6
#endif /* !lint */
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 7
E 6

#include <sys/file.h>
#include <stdio.h>
I 6
#include <ctype.h>
E 6
#include <bug.h>

D 2
extern HEADER	mailhead[];			/* mail headers */
extern char	*distf,				/* redist temp file */
		pfile[],			/* permanent bug file */
		folder[];			/* system name */

E 2
/*
 * redist --
 *	Redistribute a bug report to those people indicated in the
 *	redistribution list file.
 */
redist()
{
D 2
	register char	*C1,		/* traveling chars */
E 2
I 2
	extern FILE	*dfp;		/* dist file fp */
	extern char	pfile[];	/* permanent bug file */
D 6
	register char	*C1,
E 2
			*C2;
D 2
	register int	first = YES;	/* if first blank line */
	FILE	*pf,			/* pipe pointer */
		*dfp,			/* dist file fp */
E 2
I 2
	register int	first;		/* if first blank line */
	FILE	*pf,
E 2
		*popen();
E 6
I 6
	register char	*C1, *C2;
	FILE	*pf, *popen();
	int	group;
E 6
D 2
	char	*index(), *mktemp();
E 2
I 2
	char	*index();
E 2

D 2
	if (!freopen(DIST_FILE,"r",stdin))
E 2
I 2
D 6
	sprintf(bfr, "%s/%s", dir, DIST_FILE);
E 6
I 6
	(void)sprintf(bfr, "%s/%s", dir, DIST_FILE);
E 6
	if (!freopen(bfr, "r", stdin))
E 2
		return;
D 2

E 2
D 6
	for (;;) {			/* get first part of entry */
		if (!gets(bfr))
			return;
D 2
		if (*bfr == COMMENT || *bfr == ' ' || *bfr == '\t' || !(C1 = index(bfr,':')))
E 2
I 2
		if (*bfr == COMMENT || *bfr == ' ' || *bfr == '\t' || !(C1 = index(bfr, ':')))
E 6
I 6
	for (pf = NULL, group = 0; gets(bfr);) {
		if (*bfr == COMMENT || isspace(*bfr) || !(C1 = index(bfr, ':')))
E 6
E 2
			continue;
		*C1 = EOS;
D 2
		if (!strcmp(bfr,folder))
E 2
I 2
D 6
		if (!strcmp(bfr, folder))
E 2
			break;
E 6
I 6
		if (!strcmp(bfr, folder) || !strcmp(bfr, "all")) {
			for (++C1; *C1 && (*C1 == ' ' || *C1 == '\t'); ++C1);
			if (!*C1)			/* if empty list */
				continue;
			if (!pf) {
				if (!(pf = popen(MAIL_CMD, "w")))
					error("sendmail pipe failed.", CHN);
				if (mailhead[SUBJ_TAG].found)
					fprintf(pf, "%s", mailhead[SUBJ_TAG].line);
				else
					fputs("Subject: Untitled Bug Report\n", pf);
D 8
				if (!mailhead[TO_TAG].line && mailhead[APPAR_TO_TAG].line)
					fprintf(pf, "To%s", index(mailhead[APPAR_TO_TAG].line, ':'));
E 8
I 8
				if (!mailhead[TO_TAG].line) {
					if (mailhead[APPAR_TO_TAG].line)
					    fprintf(pf, "To%s",
					      index(mailhead[APPAR_TO_TAG].line,
					      ':'));
					else
					    fprintf(pf, "To: %s\n",  BUGS_ID);
				}
E 8
				fputs("Resent-To: ", pf);
			}
			/*
			 * write out first entry, then succeeding entries
			 * backward compatible, handles back slashes at end
			 * of line
			 */
			if (group++)
				fputs(", ", pf);
			for (;;) {
				if (C2 = index(C1, '\\'))
					*C2 = EOS;
				fputs(C1, pf);
				if (!gets(bfr) || *bfr != ' ' && *bfr != '\t')
					break;
				for (C1 = bfr; *C1 && (*C1 == ' ' || *C1 == '\t'); ++C1);
			}
		}
E 6
	}
D 6
	for (++C1;*C1 && (*C1 == ' ' || *C1 == '\t');++C1);
	if (!*C1)			/* if empty */
E 6
I 6
	if (!pf)
E 6
		return;

D 2
	if (!(pf = popen(MAIL_CMD,"w")))
		error("sendmail pipe failed.",CHN);
E 2
I 2
D 6
	if (!(pf = popen(MAIL_CMD, "w")))
		error("sendmail pipe failed.", CHN);
E 2

D 2
	fprintf(pf,"Reply-To: %s\n",BUGS_HOME);
E 2
I 2
D 4
	fprintf(pf, "Reply-To: %s\n", BUGS_HOME);
E 4
E 2
	if (mailhead[SUBJ_TAG].found)
D 2
		fprintf(pf,"%s",mailhead[SUBJ_TAG].line);
E 2
I 2
		fprintf(pf, "%s", mailhead[SUBJ_TAG].line);
E 2
	else
D 2
		fputs("Subject: Untitled Bug Report\n",pf);
	fputs("Resent-To: ",pf);
E 2
I 2
		fputs("Subject: Untitled Bug Report\n", pf);
I 4
	if (mailhead[TO_TAG].line == 0 && mailhead[APPAR_TO_TAG].line != 0)
		fprintf(pf, "To%s", index(mailhead[APPAR_TO_TAG].line, ':'));
E 4
	fputs("Resent-To: ", pf);
E 2

	/*
	 * write out first entry, then succeeding entries
	 * backward compatible, handles back slashes at end of line
	 */
	for (;;) {
D 2
		if (C2 = index(C1,'\\'))
E 2
I 2
		if (C2 = index(C1, '\\'))
E 2
			*C2 = EOS;
D 2
		fputs(C1,pf);
E 2
I 2
		fputs(C1, pf);
E 2
		if (!gets(bfr) || (*bfr != ' ' && *bfr != '\t'))
			break;
		for (C1 = bfr;*C1 && (*C1 == ' ' || *C1 == '\t');++C1);
	}
E 6
D 2
	fputs("\n",pf);
E 2
I 2
	putc('\n', pf);
E 2

D 2
	if (!(dfp = fopen(distf,"r")))
		error("unable to read temporary file %s.",distf);
	while (fgets(bfr,sizeof(bfr),dfp))
E 2
I 2
	rewind(dfp);
D 6
	for (first = YES;fgets(bfr, sizeof(bfr), dfp);)
E 2
		if (*bfr == '\n' && first) {
			first = NO;
D 2
			fprintf(pf,"\n%sReference: %s\n",mailhead[INDX_TAG].line,pfile);
E 2
I 2
			fprintf(pf, "\n%sReference: %s\n", mailhead[INDX_TAG].line, pfile);
E 2
		}
		else
D 2
			fputs(bfr,pf);
	fclose(dfp);
	pclose(pf);
	unlink(distf);
E 2
I 2
			fputs(bfr, pf);
E 6
I 6
	/* add Reference header and copy bug report out */
	while (fgets(bfr, sizeof(bfr), dfp) && *bfr != '\n')
		fputs(bfr, pf);
	fprintf(pf, "\n%sReference: %s\n\n", mailhead[INDX_TAG].line, pfile);
	while (fgets(bfr, sizeof(bfr), dfp))
		fputs(bfr, pf);
E 6
	(void)pclose(pf);
D 3
	(void)fclose(dfp);
E 3
E 2
}
E 1
