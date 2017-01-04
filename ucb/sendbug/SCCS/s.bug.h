h47608
s 00010/00005/00069
d D 5.7 88/06/29 21:43:05 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00065
d D 5.6 88/02/01 16:16:27 bostic 7 6
c add Berkeley specific header
e
s 00004/00003/00064
d D 5.5 87/09/01 19:28:30 karels 6 5
c try to preserve To, etc (or translate from Apparently-To)
c to make redisted messages look right
e
s 00006/00004/00061
d D 5.4 87/07/21 10:13:58 bostic 5 3
c added TMP_DIR; create errors directory if necessary
e
s 00001/00000/00065
d R 5.4 87/07/20 12:48:26 bostic 4 3
c added TMP_DIR; create errors directory if necessary
e
s 00000/00004/00065
d D 5.3 87/04/22 17:30:39 bostic 3 2
c remove unused defs
e
s 00008/00020/00061
d D 5.2 87/04/11 15:41:33 bostic 2 1
c version #2; -f flag, remove home_dir, redist per folder
e
s 00081/00000/00000
d D 5.1 86/11/25 12:41:14 bostic 1 0
c date and time created 86/11/25 12:41:14 by bostic
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
E 7
 *
D 6
 *	@(#)bug.h	1.1 (Berkeley) 11/25/86
E 6
I 6
 *	%W% (Berkeley) %G%
E 6
 */

D 6
#define BUGS_HOME	"owner-bugs@ucbvax.BERKELEY.EDU"
E 6
I 6
#define BUGS_HOME	"owner-bugs@ucbvax.Berkeley.EDU"
E 6
#define BUGS_ID		"bugs"
D 6
#define MAIL_CMD	"/usr/lib/sendmail -i -t -F \"Bugs Bunny\" -f owner-bugs@ucbvax.BERKELEY.EDU"
E 6
I 6
#define MAIL_CMD	"/usr/lib/sendmail -i -t -F \"Bugs Bunny\" -f owner-bugs"
E 6

/*
 * the METOO definition has the bugfiler exit with an error (-1) status
D 5
 * if there's a problem.  Sendmail then mails off a copy of the problem
 * mail to "owner-bugs".  This is great if you would have otherwise lost
 * the bug report.  It's not so great if you get a whole bunch of mail
 * that you really don't want.
E 5
I 5
 * if there's a problem.  This causes sendmail to send off a copy of the
 * report (as failed mail) to the "owner" of the mail alias that executed
 * the bugfiler.  This is great if you would have otherwise lost the bug
 * report.  It's not so great if you get a whole bunch of mail that you
 * really don't want.
E 5
 */
#define METOO

D 2
#include <sys/file.h>
#define GET_LOCK { \
	if (flock(lfd,LOCK_EX)) { \
		perror(LOCK_FILE); \
		exit(ERR); \
	} \
}

#define REL_LOCK { \
	if (flock(lfd,LOCK_UN)) { \
		perror(LOCK_FILE); \
		exit(ERR); \
	} \
}

E 2
/* files */
D 2
#define ACK_FILE	".ack"			/* acknowledge file */
#define DEF_DIR		"mail"			/* top-level directory */
#define DIST_FILE	".redist"		/* redistribution file */
E 2
I 2
#define ACK_FILE	"bug:ack"		/* acknowledge file */
#define DIST_FILE	"bug:redist"		/* redistribution file */
E 2
#define ERROR_FILE	"log"			/* error file */
#define LOCK_FILE	"bug:lock"		/* lock file name */
#define SUMMARY_FILE	"summary"		/* summary file */
#define TMP_BUG		"errors/BUG_XXXXXX"	/* tmp bug report */
I 5
#define TMP_DIR		"errors"		/* tmp directory */
E 5
D 2
#define TMP_FILE	"/tmp/BUG_XXXXXX"	/* tmp file name */
E 2

D 3
/* permissions */
#define DIR_MODE	0750		/* directory creation mode */
#define FILE_MODE	0644		/* file creation mode */

E 3
#define CHN		(char *)NULL	/* null arg string */
#define COMMENT		'#'		/* comment in redist file */
#define EOS		(char)NULL	/* end of string */
#define ERR		-1		/* error return */
#define MAXLINELEN	200		/* max line length in message */
#define NO		0		/* no/false */
#define OK		0		/* okay return */
#define YES		1		/* yes/true */

typedef struct {
	short	found,			/* line number if found */
		redist;			/* if part of redist headers */
	int	(*valid)();		/* validation routine */
	short	len;			/* length of tag */
	char	*tag,			/* leading tag */
		*line;			/* actual line */
} HEADER;
I 2
extern HEADER	mailhead[];
E 2

#define DATE_TAG	0		/* "Date:" offset */
#define FROM_TAG	1		/* "From " offset */
#define CFROM_TAG	2		/* "From:" offset */
#define INDX_TAG	3		/* "Index:" offset */
#define MSG_TAG		4		/* "Message-Id:" offset */
#define RPLY_TAG	5		/* "Reply-To:" offset */
#define RET_TAG		6		/* "Return-Path:" offset */
#define SUBJ_TAG	7		/* "Subject:" offset */
#define TO_TAG		8		/* "To:" offset */
I 6
#define APPAR_TO_TAG	9		/* "Apparently-To:" offset */
E 6

/* so sizeof doesn't return 0 */
#include <sys/param.h>
D 2
extern char	bfr[MAXBSIZE];		/* general I/O buffer */
E 2
I 2
#include <sys/dir.h>
extern char	bfr[MAXBSIZE],			/* general I/O buffer */
		dir[MAXNAMLEN],			/* subject and folder */
		folder[MAXNAMLEN],
		tmpname[sizeof(TMP_BUG) + 5];	/* temp bug file */
E 2
E 1
