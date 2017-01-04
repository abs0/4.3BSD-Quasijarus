h58686
s 00011/00005/00206
d D 5.5 88/02/18 17:03:48 bostic 13 12
c written by Kurt Shoens; added Berkeley specific header
e
s 00022/00022/00189
d D 5.4 87/05/18 12:51:54 edward 12 11
c lint
e
s 00019/00030/00192
d D 5.3 87/05/18 12:28:56 edward 11 10
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00221
d D 5.2 85/06/21 17:09:42 mckusick 10 9
c botched copyright
e
s 00007/00001/00215
d D 5.1 85/06/06 10:29:35 dist 9 8
c Add copyright
e
s 00003/00003/00213
d D 2.5 83/08/11 22:15:13 sam 8 7
c standardize sccs keyword lines
e
s 00002/00002/00214
d D 2.4 82/10/21 05:36:37 carl 7 6
c Changes to support long mail sizes (long m_size).
e
s 00001/00001/00215
d D 2.3 82/07/28 23:13:26 kurt 6 5
c changed arguments to send to include the new doignore argument 
c 
e
s 00001/00000/00215
d D 2.2 82/07/26 17:08:33 kurt 5 4
c added call on sigchild() after fork to fix retrofit signals 
c 
e
s 00000/00000/00215
d D 2.1 81/07/01 11:08:33 kurt 4 3
c Release to Heidi Stettner
e
s 00006/00006/00209
d D 1.3 81/04/01 12:46:34 kurt 3 2
c changed calls on signal to sigset/sigsys
e
s 00018/00000/00197
d D 1.2 80/10/16 17:27:09 kas 2 1
c now makes the temporary editing file mode 0400 if in readonly
c mode so that you can't easily change it.  also, will not read back in the
c new version in read only mode.
e
s 00197/00000/00000
d D 1.1 80/10/08 09:49:39 kas 1 0
c date and time created 80/10/08 09:49:39 by kas
e
u
U
f b 
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
 */

E 9
I 1
D 8
#
E 8
I 8
D 13
#ifndef lint
D 10
static char sccsid[] = "%W% (Berkeley) %G%";
E 10
I 10
static char *sccsid = "%W% (Berkeley) %G%";
E 10
D 9
#endif
E 9
I 9
#endif not lint
E 13
I 13
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 13
E 9
E 8

#include "rcv.h"
#include <stdio.h>
#include <sys/stat.h>
I 11
#include <sys/wait.h>
E 11

/*
 * Mail -- a mail program
 *
 * Perform message editing functions.
 */
D 8

static char *SccsId = "%W% %G%";
E 8

/*
 * Edit a message list.
 */

editor(msgvec)
	int *msgvec;
{
	char *edname;

	if ((edname = value("EDITOR")) == NOSTR)
		edname = EDITOR;
	return(edit1(msgvec, edname));
}

/*
 * Invoke the visual editor on a message list.
 */

visual(msgvec)
	int *msgvec;
{
	char *edname;

	if ((edname = value("VISUAL")) == NOSTR)
		edname = VISUAL;
	return(edit1(msgvec, edname));
}

/*
 * Edit a message by writing the message into a funnily-named file
 * (which should not exist) and forking an editor on it.
 * We get the editor from the stuff above.
 */

edit1(msgvec, ed)
	int *msgvec;
	char *ed;
{
D 11
	register char *cp, *cp2;
E 11
	register int c;
D 11
	int *ip, pid, mesg, lines;
D 7
	unsigned int ms;
E 7
I 7
	long ms;
E 11
I 11
	int *ip, pid, mesg;
E 11
E 7
	int (*sigint)(), (*sigquit)();
	FILE *ibuf, *obuf;
D 12
	char edname[15], nbuf[10];
E 12
I 12
	char edname[15];
E 12
D 11
	struct message *mp;
E 11
I 11
	register struct message *mp;
E 11
	extern char tempEdit[];
	off_t fsize(), size;
	struct stat statb;
	long modtime;
I 11
	union wait status;
E 11

	/*
	 * Set signals; locate editor.
	 */

D 3
	sigint = signal(SIGINT, SIG_IGN);
	sigquit = signal(SIGQUIT, SIG_IGN);
E 3
I 3
D 11
	sigint = sigset(SIGINT, SIG_IGN);
	sigquit = sigset(SIGQUIT, SIG_IGN);
E 11
I 11
	sigint = signal(SIGINT, SIG_IGN);
	sigquit = signal(SIGQUIT, SIG_IGN);
E 11
E 3

	/*
	 * Deal with each message to be edited . . .
	 */

	for (ip = msgvec; *ip && ip-msgvec < msgCount; ip++) {
		mesg = *ip;
		mp = &message[mesg-1];
		mp->m_flag |= MODIFY;
I 11
		touch(mesg);
		dot = mp;
E 11

		/*
		 * Make up a name for the edit file of the
		 * form "Message%d" and make sure it doesn't
		 * already exist.
		 */
D 11

		cp = &nbuf[10];
		*--cp = 0;
		while (mesg) {
			*--cp = mesg % 10 + '0';
			mesg /= 10;
		}
		cp2 = copy("Message", edname);
		while (*cp2++ = *cp++)
			;
E 11
I 11
D 12
		sprintf(edname, "Message%d", mesg);
E 12
I 12
		(void) sprintf(edname, "Message%d", mesg);
E 12
E 11
		if (!access(edname, 2)) {
			printf("%s: file exists\n", edname);
			goto out;
		}

		/*
		 * Copy the message into the edit file.
		 */
D 11

E 11
D 12
		close(creat(edname, 0600));
E 12
I 12
		(void) close(creat(edname, 0600));
E 12
		if ((obuf = fopen(edname, "w")) == NULL) {
			perror(edname);
			goto out;
		}
D 6
		if (send(mp, obuf) < 0) {
E 6
I 6
		if (send(mp, obuf, 0) < 0) {
E 6
			perror(edname);
D 12
			fclose(obuf);
			remove(edname);
E 12
I 12
			(void) fclose(obuf);
			(void) remove(edname);
E 12
			goto out;
		}
D 12
		fflush(obuf);
E 12
I 12
		(void) fflush(obuf);
E 12
		if (ferror(obuf)) {
D 12
			remove(edname);
			fclose(obuf);
E 12
I 12
			(void) remove(edname);
			(void) fclose(obuf);
E 12
			goto out;
		}
D 12
		fclose(obuf);
E 12
I 12
		(void) fclose(obuf);
E 12

		/*
I 2
		 * If we are in read only mode, make the
		 * temporary message file readonly as well.
		 */

		if (readonly)
D 12
			chmod(edname, 0400);
E 12
I 12
			(void) chmod(edname, 0400);
E 12

		/*
E 2
		 * Fork/execl the editor on the edit file.
		 */

		if (stat(edname, &statb) < 0)
			modtime = 0;
		modtime = statb.st_mtime;
		pid = vfork();
		if (pid == -1) {
			perror("fork");
D 12
			remove(edname);
E 12
I 12
			(void) remove(edname);
E 12
			goto out;
		}
		if (pid == 0) {
I 5
D 11
			sigchild();
E 11
E 5
			if (sigint != SIG_IGN)
D 3
				signal(SIGINT, SIG_DFL);
E 3
I 3
D 11
				sigsys(SIGINT, SIG_DFL);
E 11
I 11
D 12
				signal(SIGINT, SIG_DFL);
E 12
I 12
				(void) signal(SIGINT, SIG_DFL);
E 12
E 11
E 3
			if (sigquit != SIG_IGN)
D 3
				signal(SIGQUIT, SIG_DFL);
E 3
I 3
D 11
				sigsys(SIGQUIT, SIG_DFL);
E 11
I 11
D 12
				signal(SIGQUIT, SIG_DFL);
E 12
I 12
				(void) signal(SIGQUIT, SIG_DFL);
E 12
E 11
E 3
			execl(ed, ed, edname, 0);
			perror(ed);
			_exit(1);
		}
D 11
		while (wait(&mesg) != pid)
E 11
I 11
		while (wait(&status) != pid)
E 11
			;
I 2

		/*
		 * If in read only mode, just remove the editor
		 * temporary and return.
		 */

		if (readonly) {
D 12
			remove(edname);
E 12
I 12
			(void) remove(edname);
E 12
			continue;
		}
E 2

		/*
		 * Now copy the message to the end of the
		 * temp file.
		 */

		if (stat(edname, &statb) < 0) {
			perror(edname);
			goto out;
		}
		if (modtime == statb.st_mtime) {
D 12
			remove(edname);
E 12
I 12
			(void) remove(edname);
E 12
			goto out;
		}
		if ((ibuf = fopen(edname, "r")) == NULL) {
			perror(edname);
D 12
			remove(edname);
E 12
I 12
			(void) remove(edname);
E 12
			goto out;
		}
D 12
		remove(edname);
		fseek(otf, (long) 0, 2);
E 12
I 12
		(void) remove(edname);
		(void) fseek(otf, (long) 0, 2);
E 12
D 11
		size = fsize(otf);
E 11
I 11
		size = ftell(otf);
E 11
		mp->m_block = blockof(size);
		mp->m_offset = offsetof(size);
D 7
		ms = 0;
E 7
I 7
D 11
		ms = 0L;
E 7
		lines = 0;
E 11
I 11
		mp->m_size = fsize(ibuf);
		mp->m_lines = 0;
E 11
		while ((c = getc(ibuf)) != EOF) {
			if (c == '\n')
D 11
				lines++;
E 11
I 11
				mp->m_lines++;
E 11
D 12
			putc(c, otf);
E 12
I 12
			(void) putc(c, otf);
E 12
			if (ferror(otf))
				break;
D 11
			ms++;
E 11
		}
D 11
		mp->m_size = ms;
		mp->m_lines = lines;
E 11
		if (ferror(otf))
			perror("/tmp");
D 12
		fclose(ibuf);
E 12
I 12
		(void) fclose(ibuf);
E 12
	}

	/*
	 * Restore signals and return.
	 */

out:
D 3
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
E 3
I 3
D 11
	sigset(SIGINT, sigint);
	sigset(SIGQUIT, sigquit);
E 11
I 11
D 12
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
E 12
I 12
	(void) signal(SIGINT, sigint);
	(void) signal(SIGQUIT, sigquit);
E 12
	return 0;
E 11
E 3
}
E 1
