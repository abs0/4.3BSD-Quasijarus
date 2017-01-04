h58561
s 00011/00005/00332
d D 5.4 88/02/18 17:04:17 bostic 19 18
c written by Kurt Shoens; added Berkeley specific header
e
s 00003/00001/00334
d D 5.3 86/03/06 13:07:48 mckusick 18 16
c fix security/privacy problem (from ks@ef.purdue.edu (Kirk Smith))
e
s 00001/00000/00335
d R 5.3 86/03/03 14:48:32 mckusick 17 16
c fix security/privacy problem (from ks@ef.purdue.edu (Kirk Smith))
e
s 00001/00001/00334
d D 5.2 85/06/21 17:13:45 mckusick 16 15
c botched copyright
e
s 00008/00002/00327
d D 5.1 85/06/06 10:41:47 dist 15 14
c Add copyright
e
s 00003/00002/00326
d D 2.9 85/05/27 15:04:01 serge 14 13
c Fixed indirect through NULL bug
e
s 00029/00027/00299
d D 2.8 84/07/19 15:43:05 ralph 13 12
c use flock for mailbox locking
e
s 00003/00003/00323
d D 2.7 83/08/11 22:19:13 sam 12 11
c standardize sccs keyword lines
e
s 00003/00000/00323
d D 2.6 83/05/28 22:35:48 leres 11 10
c Modified to truncate read/write files before closing.
e
s 00003/00003/00320
d D 2.5 83/05/24 16:30:16 leres 10 9
c Changed various fopens to open read/write to avoid trashing files
c when the file system gets full, etc.
e
s 00002/00003/00321
d D 2.4 82/07/28 23:18:13 kurt 9 8
c added extra doignore argument to send() calls 
c 
e
s 00005/00002/00319
d D 2.3 81/09/09 10:00:57 kurt 8 7
c changed quit processing to NOT delete MSAVED messages if you
c have set "keepsave"
e
s 00013/00001/00308
d D 2.2 81/07/20 17:07:51 kurt 7 6
c added code to handle accounting for the -T flag:
c writes into the chosen file name the article id's of messages read or
c deleted
e
s 00000/00000/00309
d D 2.1 81/07/01 11:10:16 kurt 6 5
c Release to Heidi Stettner
e
s 00009/00010/00300
d D 1.5 81/03/20 15:28:50 kas 5 4
c simplified interpretation of where to send each message with added mbox bit
e
s 00014/00002/00296
d D 1.4 80/10/17 00:34:18 kas 4 3
c now quit clears the MNEW bit on all messages and writes back
c all the messages into the mail file if any of the message status fields
c have changed
e
s 00004/00001/00294
d D 1.3 80/10/10 13:47:03 kas 3 2
c Implemented transparent version of autoholding messages
c which doesn't set MPRESERVE until we are just about to quit.
e
s 00007/00000/00288
d D 1.2 80/10/09 13:41:18 kas 2 1
c quit() does nothing if in read only mode
e
s 00288/00000/00000
d D 1.1 80/10/08 09:51:11 kas 1 0
c date and time created 80/10/08 09:51:11 by kas
e
u
U
f b 
t
T
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
 */

E 15
I 1
D 12
#
E 12
I 12
D 19
#ifndef lint
D 14
static char sccsid[] = "%W% (Berkeley) %G%";
E 14
I 14
D 15
static char *sccsid = "%W% (Berkeley) %G%";
E 14
#endif
E 15
I 15
D 16
static char sccsid[] = "%W% (Berkeley) %G%";
E 16
I 16
static char *sccsid = "%W% (Berkeley) %G%";
E 16
#endif not lint
E 19
I 19
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 19
E 15
E 12

#include "rcv.h"
#include <sys/stat.h>
I 13
#include <sys/file.h>
E 13

/*
 * Rcv -- receive mail rationally.
 *
 * Termination processing.
 */
D 12

static char *SccsId = "%W% %G%";
E 12

/*
 * Save all of the undetermined messages at the top of "mbox"
 * Save all untouched messages back in the system mailbox.
 * Remove the system mailbox, if none saved there.
 */

quit()
{
D 3
	int mcount, p, modify;
E 3
I 3
D 4
	int mcount, p, modify, autohold;
E 4
I 4
D 5
	int mcount, p, modify, autohold, anystat;
E 5
I 5
D 8
	int mcount, p, modify, autohold, anystat, holdbit;
E 8
I 8
	int mcount, p, modify, autohold, anystat, holdbit, nohold;
E 8
E 5
E 4
E 3
D 7
	FILE *ibuf, *obuf, *fbuf, *rbuf;
E 7
I 7
D 13
	FILE *ibuf, *obuf, *fbuf, *rbuf, *readstat;
E 13
I 13
	FILE *ibuf, *obuf, *fbuf, *rbuf, *readstat, *abuf;
E 13
E 7
	register struct message *mp;
	register int c;
	extern char tempQuit[], tempResid[];
	struct stat minfo;
I 7
	char *id;
E 7

	/*
I 2
	 * If we are read only, we can't do anything,
	 * so just return quickly.
	 */

	if (readonly)
		return;
	/*
E 2
	 * See if there any messages to save in mbox.  If no, we
	 * can save copying mbox to /tmp and back.
	 *
	 * Check also to see if any files need to be preserved.
	 * Delete all untouched messages to keep them out of mbox.
	 * If all the messages are to be preserved, just exit with
	 * a message.
	 *
	 * If the luser has sent mail to himself, refuse to do
	 * anything with the mailbox, unless mail locking works.
	 */

D 13
	lock(mailname);
E 13
I 13
	fbuf = fopen(mailname, "r");
	if (fbuf == NULL)
		goto newmail;
	flock(fileno(fbuf), LOCK_EX);
E 13
#ifndef CANLOCK
	if (selfsent) {
		printf("You have new mail.\n");
D 13
		unlock();
E 13
I 13
		fclose(fbuf);
E 13
		return;
	}
#endif
	rbuf = NULL;
D 13
	if (stat(mailname, &minfo) >= 0 && minfo.st_size > mailsize) {
E 13
I 13
	if (fstat(fileno(fbuf), &minfo) >= 0 && minfo.st_size > mailsize) {
E 13
		printf("New mail has arrived.\n");
		rbuf = fopen(tempResid, "w");
D 13
		fbuf = fopen(mailname, "r");
E 13
		if (rbuf == NULL || fbuf == NULL)
			goto newmail;
#ifdef APPEND
		fseek(fbuf, mailsize, 0);
		while ((c = getc(fbuf)) != EOF)
			putc(c, rbuf);
#else
		p = minfo.st_size - mailsize;
		while (p-- > 0) {
			c = getc(fbuf);
			if (c == EOF)
				goto newmail;
			putc(c, rbuf);
		}
#endif
D 13
		fclose(fbuf);
E 13
		fclose(rbuf);
		if ((rbuf = fopen(tempResid, "r")) == NULL)
			goto newmail;
		remove(tempResid);
	}
I 4

	/*
	 * Adjust the message flags in each message.
	 */

	anystat = 0;
I 5
	autohold = value("hold") != NOSTR;
	holdbit = autohold ? MPRESERVE : MBOX;
I 8
	nohold = MBOX|MSAVED|MDELETED|MPRESERVE;
	if (value("keepsave") != NOSTR)
		nohold &= ~MSAVED;
E 8
E 5
E 4
	for (mp = &message[0]; mp < &message[msgCount]; mp++) {
I 4
		if (mp->m_flag & MNEW) {
			mp->m_flag &= ~MNEW;
			mp->m_flag |= MSTATUS;
		}
		if (mp->m_flag & MSTATUS)
			anystat++;
E 4
D 5
		if (mp->m_flag & MDELETED)
			mp->m_flag = MDELETED|MTOUCH;
E 5
		if ((mp->m_flag & MTOUCH) == 0)
D 5
			mp->m_flag |= MDELETED;
E 5
I 5
			mp->m_flag |= MPRESERVE;
D 8
		if ((mp->m_flag & (MBOX|MSAVED|MDELETED|MPRESERVE)) == 0)
E 8
I 8
		if ((mp->m_flag & nohold) == 0)
E 8
			mp->m_flag |= holdbit;
E 5
	}
I 3
D 5
	autohold = value("hold") != NOSTR;
E 5
E 3
	modify = 0;
I 7
	if (Tflag != NOSTR) {
		if ((readstat = fopen(Tflag, "w")) == NULL)
			Tflag = NOSTR;
	}
E 7
	for (c = 0, p = 0, mp = &message[0]; mp < &message[msgCount]; mp++) {
I 3
D 5
		if ((mp->m_flag & (MSAVED|MDELETED)) == 0 && autohold)
			mp->m_flag |= MPRESERVE;
E 3
		if ((mp->m_flag & (MSAVED|MDELETED|MPRESERVE)) == 0)
E 5
I 5
		if (mp->m_flag & MBOX)
E 5
			c++;
D 5
		if ((mp->m_flag & MPRESERVE) || (mp->m_flag & MTOUCH) == 0)
E 5
I 5
		if (mp->m_flag & MPRESERVE)
E 5
			p++;
		if (mp->m_flag & MODIFY)
			modify++;
I 7
		if (Tflag != NOSTR && (mp->m_flag & (MREAD|MDELETED)) != 0) {
			id = hfield("article-id", mp);
			if (id != NOSTR)
				fprintf(readstat, "%s\n", id);
		}
E 7
	}
I 7
	if (Tflag != NOSTR)
		fclose(readstat);
E 7
D 4
	if (p == msgCount && !modify) {
E 4
I 4
	if (p == msgCount && !modify && !anystat) {
E 4
		if (p == 1)
			printf("Held 1 message in %s\n", mailname);
		else
			printf("Held %2d messages in %s\n", p, mailname);
D 13
		unlock();
E 13
I 13
		fclose(fbuf);
E 13
		return;
	}
	if (c == 0) {
		if (p != 0) {
			writeback(rbuf);
D 13
			unlock();
E 13
I 13
			fclose(fbuf);
E 13
			return;
		}
		goto cream;
	}

	/*
	 * Create another temporary file and copy user's mbox file
	 * darin.  If there is no mbox, copy nothing.
	 * If he has specified "append" don't copy his mailbox,
	 * just copy saveable entries at the end.
	 */

	mcount = c;
	if (value("append") == NOSTR) {
		if ((obuf = fopen(tempQuit, "w")) == NULL) {
			perror(tempQuit);
D 13
			unlock();
E 13
I 13
			fclose(fbuf);
E 13
			return;
		}
		if ((ibuf = fopen(tempQuit, "r")) == NULL) {
			perror(tempQuit);
			remove(tempQuit);
			fclose(obuf);
D 13
			unlock();
E 13
I 13
			fclose(fbuf);
E 13
			return;
		}
		remove(tempQuit);
D 13
		if ((fbuf = fopen(mbox, "r")) != NULL) {
			while ((c = getc(fbuf)) != EOF)
E 13
I 13
		if ((abuf = fopen(mbox, "r")) != NULL) {
			while ((c = getc(abuf)) != EOF)
E 13
				putc(c, obuf);
D 13
			fclose(fbuf);
E 13
I 13
			fclose(abuf);
E 13
		}
		if (ferror(obuf)) {
			perror(tempQuit);
			fclose(ibuf);
			fclose(obuf);
D 13
			unlock();
E 13
I 13
			fclose(fbuf);
E 13
			return;
		}
		fclose(obuf);
		close(creat(mbox, 0600));
D 10
		if ((obuf = fopen(mbox, "w")) == NULL) {
E 10
I 10
		if ((obuf = fopen(mbox, "r+")) == NULL) {
E 10
			perror(mbox);
			fclose(ibuf);
D 13
			unlock();
E 13
I 13
			fclose(fbuf);
E 13
			return;
		}
	}
D 18
	if (value("append") != NOSTR)
E 18
I 18
	if (value("append") != NOSTR) {
E 18
		if ((obuf = fopen(mbox, "a")) == NULL) {
			perror(mbox);
D 13
			unlock();
E 13
I 13
			fclose(fbuf);
E 13
			return;
		}
I 18
		fchmod(fileno(obuf), 0600);
	}
E 18
	for (mp = &message[0]; mp < &message[msgCount]; mp++)
D 5
		if ((mp->m_flag & (MDELETED|MSAVED|MPRESERVE)) == 0)
E 5
I 5
		if (mp->m_flag & MBOX)
E 5
D 9
			if (send(mp, obuf) < 0) {
E 9
I 9
			if (send(mp, obuf, 0) < 0) {
E 9
				perror(mbox);
				fclose(ibuf);
				fclose(obuf);
D 13
				unlock();
E 13
I 13
				fclose(fbuf);
E 13
				return;
			}

	/*
	 * Copy the user's old mbox contents back
	 * to the end of the stuff we just saved.
	 * If we are appending, this is unnecessary.
	 */

	if (value("append") == NOSTR) {
		rewind(ibuf);
		c = getc(ibuf);
		while (c != EOF) {
			putc(c, obuf);
			if (ferror(obuf))
				break;
			c = getc(ibuf);
		}
		fclose(ibuf);
		fflush(obuf);
	}
I 11
	trunc(obuf);
E 11
	if (ferror(obuf)) {
		perror(mbox);
		fclose(obuf);
D 13
		unlock();
E 13
I 13
		fclose(fbuf);
E 13
		return;
	}
	fclose(obuf);
	if (mcount == 1)
		printf("Saved 1 message in mbox\n");
	else
		printf("Saved %d messages in mbox\n", mcount);

	/*
	 * Now we are ready to copy back preserved files to
	 * the system mailbox, if any were requested.
	 */

	if (p != 0) {
		writeback(rbuf);
D 13
		unlock();
E 13
I 13
		fclose(fbuf);
E 13
		return;
	}

	/*
	 * Finally, remove his /usr/mail file.
	 * If new mail has arrived, copy it back.
	 */

cream:
	if (rbuf != NULL) {
D 10
		fbuf = fopen(mailname, "w");
E 10
I 10
D 13
		fbuf = fopen(mailname, "r+");
E 10
		if (fbuf == NULL)
E 13
I 13
		abuf = fopen(mailname, "r+");
		if (abuf == NULL)
E 13
			goto newmail;
		while ((c = getc(rbuf)) != EOF)
D 13
			putc(c, fbuf);
E 13
I 13
			putc(c, abuf);
E 13
		fclose(rbuf);
I 11
D 13
		trunc(fbuf);
E 11
		fclose(fbuf);
E 13
I 13
		trunc(abuf);
		fclose(abuf);
E 13
		alter(mailname);
D 13
		unlock();
E 13
I 13
		fclose(fbuf);
E 13
		return;
	}
	demail();
D 13
	unlock();
E 13
I 13
	fclose(fbuf);
E 13
	return;

newmail:
	printf("Thou hast new mail.\n");
D 13
	unlock();
E 13
I 13
D 14
	fclose(fbuf);
E 14
I 14
	if (fbuf != NULL)
		fclose(fbuf);
E 14
E 13
}

/*
 * Preserve all the appropriate messages back in the system
 * mailbox, and print a nice message indicated how many were
 * saved.  On any error, just return -1.  Else return 0.
 * Incorporate the any new mail that we found.
 */
D 9

E 9
writeback(res)
	register FILE *res;
{
	register struct message *mp;
	register int p, c;
	FILE *obuf;

	p = 0;
D 10
	if ((obuf = fopen(mailname, "w")) == NULL) {
E 10
I 10
	if ((obuf = fopen(mailname, "r+")) == NULL) {
E 10
		perror(mailname);
		return(-1);
	}
#ifndef APPEND
	if (res != NULL)
		while ((c = getc(res)) != EOF)
			putc(c, obuf);
#endif
	for (mp = &message[0]; mp < &message[msgCount]; mp++)
		if ((mp->m_flag&MPRESERVE)||(mp->m_flag&MTOUCH)==0) {
			p++;
D 9
			if (send(mp, obuf) < 0) {
E 9
I 9
			if (send(mp, obuf, 0) < 0) {
E 9
				perror(mailname);
				fclose(obuf);
				return(-1);
			}
		}
#ifdef APPEND
	if (res != NULL)
		while ((c = getc(res)) != EOF)
			putc(c, obuf);
#endif
	fflush(obuf);
I 11
	trunc(obuf);
E 11
	if (ferror(obuf)) {
		perror(mailname);
		fclose(obuf);
		return(-1);
	}
	if (res != NULL)
		fclose(res);
	fclose(obuf);
	alter(mailname);
	if (p == 1)
		printf("Held 1 message in %s\n", mailname);
	else
		printf("Held %d messages in %s\n", p, mailname);
	return(0);
}
E 1
