h06689
s 00011/00005/00489
d D 5.6 88/02/18 17:03:50 bostic 37 36
c written by Kurt Shoens; added Berkeley specific header
e
s 00094/00133/00400
d D 5.5 87/05/18 12:28:58 edward 36 35
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00000/00532
d D 5.4 86/11/26 16:01:37 bostic 35 34
c included strings.h
e
s 00017/00072/00515
d D 5.3 85/09/05 02:48:12 donn 34 33
c Efficiency changes -- replace inline loops on getc() with calls
c to fgets(); took out useless string copy in check for header status line.
e
s 00001/00001/00586
d D 5.2 85/06/21 17:09:48 mckusick 33 32
c botched copyright
e
s 00007/00001/00580
d D 5.1 85/06/06 10:30:34 dist 32 31
c Add copyright
e
s 00003/00003/00578
d D 2.18 85/01/09 10:18:24 ralph 31 30
c use sigmask() macro
e
s 00002/00025/00579
d D 2.17 84/08/08 17:06:24 ralph 30 29
c fix stdio flushing, don't mess with stdio buffers
e
s 00003/00003/00601
d D 2.16 83/08/11 22:15:26 sam 29 28
c standardize sccs keyword lines
e
s 00002/00001/00602
d D 2.15 83/06/17 21:29:52 root 28 27
c merge monet
e
s 00003/00004/00600
d D 2.14 83/06/12 11:17:11 sam 27 26
c new signals
e
s 00007/00010/00597
d D 2.13 83/02/25 17:37:15 leres 26 25
c Modified holdsigs() to use sighold() rather than sigset()
c (which fixes many signal related bugs.) Also added a hold
c depth counter since sighold()s don't stack.
e
s 00006/00005/00601
d D 2.12 82/10/21 05:36:43 carl 25 24
c Changes to support long mail sizes (long m_size).
e
s 00007/00001/00599
d D 2.11 82/10/21 04:40:05 carl 24 23
c Changed ``sighold(i)'' to ``sigset(i, SIG_HOLD)'' in holdsigs().
c This gets around a bug in the job library.  Sighold() does not note that one
c is using the new signal mechanisms, so a later sigrelse() will not do what
c one expects.
e
s 00001/00001/00599
d D 2.10 82/07/28 23:14:47 kurt 23 22
c changed arguments to send() to include doignore argument 
c 
e
s 00001/00012/00599
d D 2.9 82/07/26 17:09:17 kurt 22 21
c fixed holdsigs() and relsesigs() to rely on retrofit library; 
c added call on sigchild() after fork to fix retrofit signals. 
c 
e
s 00000/00000/00611
d D 2.8 82/03/15 09:44:09 kurt 21 19
i 20
c Included Eric's branch changes to remove vax and vmunix 
c dependencies. 
c 
e
s 00012/00000/00578
d D 2.3.1.1 82/03/15 09:33:33 kurt 20 15
c Eric Allman's fixes to remove VAX and VMUNIX dependencies
e
s 00019/00005/00580
d D 2.7 82/02/17 22:53:46 kurt 19 18
c added routine getfold() to find user's folder directory and changed 
c expand() to use this 
c 
e
s 00004/00001/00581
d D 2.6 82/02/13 21:23:12 kurt 18 17
c changed expand() to interpret a relative pathname for maildir as 
c relative to user's home directory 
c 
e
s 00004/00000/00578
d D 2.5 82/02/11 11:22:14 kurt 17 16
c Changed expand() to interpret names that begin with + relative 
c to the directory specified by the variable "maildir" 
c 
e
s 00001/00001/00577
d D 2.4 81/12/07 15:50:35 kurt 16 15
c changed edstop() so that if you give -T flag, it won't 
c bother to write out the updated file you were reading. 
c 
e
s 00001/00001/00577
d D 2.3 81/08/12 17:20:24 kurt 15 14
c changed erroneous check in setptr to respect LINESIZE rather than BUFSIZ
e
s 00012/00004/00566
d D 2.2 81/07/20 17:06:19 kurt 14 13
c added code to do accounting for -T flag for netnews:
c now records in the file of your choice the article-id's which were read
c or deleted
e
s 00000/00000/00570
d D 2.1 81/07/01 11:08:43 kurt 13 12
c Release to Heidi Stettner
e
s 00001/00000/00569
d D 1.12 81/04/28 11:38:54 kurt 12 11
c fixed handling case where stuff gets sent to an edit file while you're
c reading it -- missing fseek
e
s 00015/00017/00554
d D 1.11 81/04/20 13:35:58 kurt 11 10
c now uses signal holding facility to avoid losing signals when they must be
c ignored
e
s 00036/00005/00535
d D 1.10 81/04/01 12:48:37 kurt 10 9
c invented routines sigsave/sigret to save and restore signals;
c changed calls on signal to sigset
e
s 00037/00004/00503
d D 1.9 81/03/13 15:56:24 kas 9 8
c changed edstop to preserve new stuff added to the end of the mailbox while we
c were reading it
e
s 00007/00002/00500
d D 1.8 81/01/12 11:50:15 kas 8 7
c mail -f now correctly updates status fields
e
s 00020/00003/00482
d D 1.7 81/01/05 17:33:34 kas 7 6
c In-line expanded calls on readline/putline in setptr() for speed
e
s 00034/00002/00451
d D 1.6 80/11/21 09:10:46 kas 6 5
c Made fast version of readline for setptr; use fputs not putline
c there also for speed
e
s 00001/00000/00452
d D 1.5 80/10/17 00:27:46 kas 5 4
c fixed setting of variable inhead in setptr so that status:
c fields are actually seen
e
s 00025/00003/00427
d D 1.4 80/10/16 18:44:01 kas 4 3
c on initial read of file, now looks for Status: header field,
c used to determine which messages are new and which unread.
e
s 00000/00002/00430
d D 1.3 80/10/16 16:16:48 kas 3 2
c got rid of code which sets MPRESERVE on every message if
c value("hold") != NOSTR.
e
s 00004/00000/00428
d D 1.2 80/10/09 13:31:07 kas 2 1
c Freed storage of old message structure to avoid storage leak
c when switching files.  Also, edstop does nothing in read only mode.
e
s 00428/00000/00000
d D 1.1 80/10/08 09:49:45 kas 1 0
c date and time created 80/10/08 09:49:45 by kas
e
u
U
f b 
t
T
I 32
/*
 * Copyright (c) 1980 Regents of the University of California.
D 37
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 37
I 37
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 37
 */

E 32
I 1
D 29
#
E 29
I 29
D 37
#ifndef lint
D 33
static char sccsid[] = "%W% (Berkeley) %G%";
E 33
I 33
static char *sccsid = "%W% (Berkeley) %G%";
E 33
D 32
#endif
E 32
I 32
#endif not lint
E 37
I 37
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 37
E 32
E 29

#include "rcv.h"
#include <sys/stat.h>
I 36
#include <sys/file.h>
#include <sys/wait.h>
E 36
#include <errno.h>
I 35
D 36
#include <strings.h>
E 36
E 35

/*
 * Mail -- a mail program
 *
 * File I/O.
 */
D 29

static char *SccsId = "%W% %G%";
E 29

/*
 * Set up the input pointers while copying the mail file into
 * /tmp.
 */
D 36

E 36
setptr(ibuf)
D 36
	FILE *ibuf;
E 36
I 36
	register FILE *ibuf;
E 36
{
D 7
	register int count, s, l;
E 7
I 7
D 36
	register int c;
E 36
I 36
	register c;
E 36
E 7
I 4
	register char *cp, *cp2;
I 7
D 25
	register int count, s, l;
E 25
I 25
D 36
	register int count, l;
	long s;
E 25
E 7
E 4
	off_t offset;
E 36
I 36
	register count;
E 36
	char linebuf[LINESIZE];
D 4
	int maybe, mestmp, flag;
E 4
I 4
D 36
	char wbuf[LINESIZE];
	int maybe, mestmp, flag, inhead;
E 36
I 36
	int maybe, inhead;
	FILE *mestmp;
	off_t offset;
E 36
E 4
	struct message this;
	extern char tempSet[];

D 36
	if ((mestmp = opentemp(tempSet)) < 0)
E 36
I 36
	if ((c = opentemp(tempSet)) < 0)
E 36
		exit(1);
I 36
	if ((mestmp = fdopen(c, "r+")) == NULL)
		panic("Can't open temporary");
E 36
	msgCount = 0;
D 36
	offset = 0;
D 25
	s = 0;
E 25
I 25
	s = 0L;
E 25
	l = 0;
E 36
	maybe = 1;
D 4
	flag = MUSED;
E 4
I 4
D 36
	flag = MUSED|MNEW;
E 36
I 36
	inhead = 0;
	offset = 0;
	this.m_flag = MUSED|MNEW;
	this.m_size = 0;
	this.m_lines = 0;
	this.m_block = 0;
	this.m_offset = 0;
E 36
E 4
D 3
	if (value("hold") != NOSTR)
		flag = MPRESERVE|MUSED;
E 3
	for (;;) {
D 6
		if ((count = readline(ibuf, linebuf)) == 0) {
E 6
I 6
D 7
		if ((count = freadline(ibuf, linebuf)) == 0) {
E 7
I 7
D 34
		cp = linebuf;
		c = getc(ibuf);
		while (c != EOF && c != '\n') {
D 15
			if (cp - linebuf >= BUFSIZ - 1) {
E 15
I 15
			if (cp - linebuf >= LINESIZE - 1) {
E 15
				ungetc(c, ibuf);
				*cp = 0;
				break;
			}
			*cp++ = c;
			c = getc(ibuf);
		}
		*cp = 0;
		if (cp == linebuf && c == EOF) {
E 34
I 34
		if (fgets(linebuf, LINESIZE, ibuf) == NULL) {
E 34
E 7
E 6
D 36
			this.m_flag = flag;
I 4
			flag = MUSED|MNEW;
E 4
			this.m_offset = offsetof(offset);
			this.m_block = blockof(offset);
			this.m_size = s;
			this.m_lines = l;
E 36
			if (append(&this, mestmp)) {
				perror(tempSet);
				exit(1);
			}
			fclose(ibuf);
			makemessage(mestmp);
D 36
			close(mestmp);
E 36
			return;
		}
D 6
		if (putline(otf, linebuf) < 0) {
E 6
I 6
D 7
		if (fputs(linebuf, otf) == NULL || putc('\n', otf) == EOF) {
E 7
I 7
D 34
		count = cp - linebuf + 1;
		for (cp = linebuf; *cp;)
			putc(*cp++, otf);
		putc('\n', otf);
E 34
I 34
		count = strlen(linebuf);
D 36
		fputs(linebuf, otf);
		cp = linebuf + (count - 1);
		if (*cp == '\n')
			*cp = 0;
E 36
I 36
		fwrite(linebuf, sizeof *linebuf, count, otf);
E 36
E 34
		if (ferror(otf)) {
E 7
E 6
			perror("/tmp");
			exit(1);
		}
I 36
		linebuf[count - 1] = 0;
E 36
D 4
		if (maybe && ishead(linebuf)) {
E 4
I 4
		if (maybe && linebuf[0] == 'F' && ishead(linebuf)) {
E 4
			msgCount++;
D 36
			this.m_flag = flag;
I 4
			flag = MUSED|MNEW;
I 5
			inhead = 1;
E 5
E 4
			this.m_block = blockof(offset);
			this.m_offset = offsetof(offset);
			this.m_size = s;
			this.m_lines = l;
D 25
			s = 0;
E 25
I 25
			s = 0L;
E 25
			l = 0;
E 36
			if (append(&this, mestmp)) {
				perror(tempSet);
				exit(1);
			}
D 36
		}
I 4
		if (linebuf[0] == 0)
E 36
I 36
			this.m_flag = MUSED|MNEW;
			this.m_size = 0;
			this.m_lines = 0;
			this.m_block = blockof(offset);
			this.m_offset = offsetof(offset);
			inhead = 1;
		} else if (linebuf[0] == 0) {
E 36
			inhead = 0;
D 34
		if (inhead && index(linebuf, ':')) {
			cp = linebuf;
			cp2 = wbuf;
			while (isalpha(*cp))
				*cp2++ = *cp++;
			*cp2 = 0;
			if (icequal(wbuf, "status")) {
				cp = index(linebuf, ':');
E 34
I 34
D 36
		if (inhead && (cp = index(linebuf, ':'))) {
			*cp = 0;
			if (icequal(linebuf, "status")) {
				++cp;
E 34
				if (index(cp, 'R'))
					flag |= MREAD;
				if (index(cp, 'O'))
					flag &= ~MNEW;
				inhead = 0;
E 36
I 36
		} else if (inhead) {
			for (cp = linebuf, cp2 = "status";; cp++) {
				if ((c = *cp2++) == 0) {
					while (isspace(*cp++))
						;
					if (cp[-1] != ':')
						break;
					while (c = *cp++)
						if (c == 'R')
							this.m_flag |= MREAD;
						else if (c == 'O')
							this.m_flag &= ~MNEW;
					inhead = 0;
					break;
				}
				if (*cp != c && *cp != toupper(c))
					break;
E 36
			}
		}
E 4
		offset += count;
D 25
		s += count;
E 25
I 25
D 36
		s += (long) count;
E 25
		l++;
		maybe = 0;
		if (linebuf[0] == 0)
			maybe = 1;
E 36
I 36
		this.m_size += count;
		this.m_lines++;
		maybe = linebuf[0] == 0;
E 36
	}
}

/*
 * Drop the passed line onto the passed output buffer.
 * If a write error occurs, return -1, else the count of
 * characters written, including the newline.
 */
D 36

E 36
putline(obuf, linebuf)
	FILE *obuf;
	char *linebuf;
{
	register int c;

	c = strlen(linebuf);
D 36
	fputs(linebuf, obuf);
E 36
I 36
	fwrite(linebuf, sizeof *linebuf, c, obuf);
E 36
	putc('\n', obuf);
	if (ferror(obuf))
D 36
		return(-1);
	return(c+1);
E 36
I 36
		return (-1);
	return (c + 1);
E 36
I 6
}

/*
D 34
 * Quickly read a line from the specified input into the line
 * buffer; return characters read.
 */

freadline(ibuf, linebuf)
	register FILE *ibuf;
	register char *linebuf;
{
	register int c;
	register char *cp;

	c = getc(ibuf);
	cp = linebuf;
	while (c != '\n' && c != EOF) {
		if (c == 0) {
			c = getc(ibuf);
			continue;
		}
		if (cp - linebuf >= BUFSIZ-1) {
			*cp = 0;
			return(cp - linebuf + 1);
		}
		*cp++ = c;
		c = getc(ibuf);
	}
	if (c == EOF && cp == linebuf)
		return(0);
	*cp = 0;
	return(cp - linebuf + 1);
E 6
}

/*
E 34
 * Read up a line from the specified input into the line
 * buffer.  Return the number of characters read.  Do not
 * include the newline at the end.
 */
D 36

E 36
readline(ibuf, linebuf)
	FILE *ibuf;
	char *linebuf;
{
D 34
	register char *cp;
	register int c;
E 34
I 34
	register int n;
E 34

D 34
	do {
		clearerr(ibuf);
		c = getc(ibuf);
		for (cp = linebuf; c != '\n' && c != EOF; c = getc(ibuf)) {
			if (c == 0)
				continue;
			if (cp - linebuf < LINESIZE-2)
				*cp++ = c;
		}
	} while (ferror(ibuf) && ibuf == stdin);
	*cp = 0;
	if (c == EOF && cp == linebuf)
E 34
I 34
	clearerr(ibuf);
	if (fgets(linebuf, LINESIZE, ibuf) == NULL)
E 34
D 36
		return(0);
E 36
I 36
		return -1;
E 36
D 34
	return(cp - linebuf + 1);
E 34
I 34
	n = strlen(linebuf);
D 36
	if (n >= 1 && linebuf[n-1] == '\n')
		linebuf[n-1] = '\0';
	return(n);
E 36
I 36
	if (n > 0 && linebuf[n - 1] == '\n')
		linebuf[--n] = '\0';
	return n;
E 36
E 34
}

/*
 * Return a file buffer all ready to read up the
 * passed message pointer.
 */
D 36

E 36
FILE *
setinput(mp)
	register struct message *mp;
{
D 36
	off_t off;
E 36

	fflush(otf);
D 36
	off = mp->m_block;
	off <<= 9;
	off += mp->m_offset;
	if (fseek(itf, off, 0) < 0) {
E 36
I 36
	if (fseek(itf, positionof(mp->m_block, mp->m_offset), 0) < 0) {
E 36
		perror("fseek");
		panic("temporary file seek");
	}
D 36
	return(itf);
E 36
I 36
	return (itf);
E 36
}

/*
 * Take the data out of the passed ghost file and toss it into
 * a dynamically allocated message structure.
 */
D 36

E 36
makemessage(f)
I 36
	FILE *f;
E 36
{
D 36
	register struct message *m;
	register char *mp;
	register count;
E 36
I 36
	register size = (msgCount + 1) * sizeof (struct message);
	off_t lseek();
E 36

D 36
	mp = calloc((unsigned) (msgCount + 1), sizeof *m);
	if (mp == NOSTR) {
		printf("Insufficient memory for %d messages\n", msgCount);
		exit(1);
	}
I 2
	if (message != (struct message *) 0)
		cfree((char *) message);
E 2
	message = (struct message *) mp;
E 36
I 36
	if (message != 0)
		free((char *) message);
	if ((message = (struct message *) malloc((unsigned) size)) == 0)
		panic("Insufficient memory for %d messages", msgCount);
E 36
	dot = message;
D 36
	lseek(f, 0L, 0);
	while (count = read(f, mp, BUFSIZ))
		mp += count;
	for (m = &message[0]; m < &message[msgCount]; m++) {
		m->m_size = (m+1)->m_size;
		m->m_lines = (m+1)->m_lines;
I 4
		m->m_flag = (m+1)->m_flag;
E 4
	}
D 25
	message[msgCount].m_size = 0;
E 25
I 25
	message[msgCount].m_size = 0L;
E 36
I 36
	size -= sizeof (struct message);
	fflush(f);
	lseek(fileno(f), (long) sizeof *message, 0);
	if (read(fileno(f), (char *) message, size) != size)
		panic("Message temporary file corrupted");
	message[msgCount].m_size = 0;
E 36
E 25
	message[msgCount].m_lines = 0;
I 36
	fclose(f);
E 36
}

/*
 * Append the passed message descriptor onto the temp file.
 * If the write fails, return 1, else 0
 */
D 36

E 36
append(mp, f)
	struct message *mp;
I 36
	FILE *f;
E 36
{
D 36
	if (write(f, (char *) mp, sizeof *mp) != sizeof *mp)
		return(1);
	return(0);
E 36
I 36
	return fwrite((char *) mp, sizeof *mp, 1, f) != 1;
E 36
}

/*
 * Delete a file, but only if the file is a plain file.
 */
D 36

E 36
remove(name)
	char name[];
{
	struct stat statb;
	extern int errno;

	if (stat(name, &statb) < 0)
		return(-1);
	if ((statb.st_mode & S_IFMT) != S_IFREG) {
		errno = EISDIR;
		return(-1);
	}
D 36
	return(unlink(name));
E 36
I 36
	return unlink(name);
E 36
}

/*
 * Terminate an editing session by attempting to write out the user's
D 9
 * file from the temporary.
E 9
I 9
 * file from the temporary.  Save any new stuff appended to the file.
E 9
 */
D 9

E 9
edstop()
{
	register int gotcha, c;
	register struct message *mp;
D 9
	FILE *obuf;
E 9
I 9
D 14
	FILE *obuf, *ibuf;
E 14
I 14
	FILE *obuf, *ibuf, *readstat;
E 14
	struct stat statb;
D 14
	char tempname[30];
E 14
I 14
	char tempname[30], *id;
E 14
I 10
D 36
	int (*sigs[3])();
E 36
I 36
	char *mktemp();
E 36
E 10
E 9

I 2
	if (readonly)
		return;
I 10
D 11
	sigsave(sigs, SIG_IGN);
E 11
I 11
	holdsigs();
I 14
	if (Tflag != NOSTR) {
		if ((readstat = fopen(Tflag, "w")) == NULL)
			Tflag = NOSTR;
	}
E 14
E 11
E 10
E 2
D 8
	for (mp = &message[0], gotcha = 0; mp < &message[msgCount]; mp++)
		if (mp->m_flag & (MODIFY|MDELETED)) {
E 8
I 8
	for (mp = &message[0], gotcha = 0; mp < &message[msgCount]; mp++) {
		if (mp->m_flag & MNEW) {
			mp->m_flag &= ~MNEW;
			mp->m_flag |= MSTATUS;
		}
D 14
		if (mp->m_flag & (MODIFY|MDELETED|MSTATUS)) {
E 14
I 14
		if (mp->m_flag & (MODIFY|MDELETED|MSTATUS))
E 14
E 8
			gotcha++;
D 14
			break;
E 14
I 14
		if (Tflag != NOSTR && (mp->m_flag & (MREAD|MDELETED)) != 0) {
			if ((id = hfield("article-id", mp)) != NOSTR)
				fprintf(readstat, "%s\n", id);
E 14
		}
I 8
	}
I 14
	if (Tflag != NOSTR)
		fclose(readstat);
E 14
E 8
D 16
	if (!gotcha)
E 16
I 16
	if (!gotcha || Tflag != NOSTR)
E 16
D 10
		return;
E 10
I 10
		goto done;
E 10
I 9
	ibuf = NULL;
	if (stat(editfile, &statb) >= 0 && statb.st_size > mailsize) {
		strcpy(tempname, "/tmp/mboxXXXXXX");
		mktemp(tempname);
		if ((obuf = fopen(tempname, "w")) == NULL) {
			perror(tempname);
I 10
D 11
			sigret(sigs);
E 11
I 11
			relsesigs();
E 11
E 10
			reset(0);
		}
		if ((ibuf = fopen(editfile, "r")) == NULL) {
			perror(editfile);
			fclose(obuf);
			remove(tempname);
I 10
D 11
			sigret(sigs);
E 11
I 11
			relsesigs();
E 11
E 10
			reset(0);
		}
I 12
		fseek(ibuf, mailsize, 0);
E 12
		while ((c = getc(ibuf)) != EOF)
			putc(c, obuf);
		fclose(ibuf);
		fclose(obuf);
		if ((ibuf = fopen(tempname, "r")) == NULL) {
			perror(tempname);
			remove(tempname);
I 10
D 11
			sigret(sigs);
E 11
I 11
			relsesigs();
E 11
E 10
			reset(0);
		}
		remove(tempname);
	}
E 9
	printf("\"%s\" ", editfile);
D 30
	flush();
E 30
I 30
	fflush(stdout);
E 30
D 28
	if ((obuf = fopen(editfile, "w")) == NULL) {
E 28
I 28
	if ((obuf = fopen(editfile, "r+")) == NULL) {
E 28
		perror(editfile);
I 10
D 11
		sigret(sigs);
E 11
I 11
		relsesigs();
E 11
E 10
		reset(0);
	}
I 28
	trunc(obuf);
E 28
	c = 0;
	for (mp = &message[0]; mp < &message[msgCount]; mp++) {
		if ((mp->m_flag & MDELETED) != 0)
			continue;
		c++;
D 23
		if (send(mp, obuf) < 0) {
E 23
I 23
		if (send(mp, obuf, 0) < 0) {
E 23
			perror(editfile);
I 10
D 11
			sigret(sigs);
E 11
I 11
			relsesigs();
E 11
E 10
			reset(0);
		}
	}
I 9
	gotcha = (c == 0 && ibuf == NULL);
	if (ibuf != NULL) {
		while ((c = getc(ibuf)) != EOF)
			putc(c, obuf);
		fclose(ibuf);
	}
E 9
	fflush(obuf);
	if (ferror(obuf)) {
		perror(editfile);
I 10
D 11
		sigret(sigs);
E 11
I 11
		relsesigs();
E 11
E 10
		reset(0);
	}
D 9
	if (c == 0) {
E 9
I 9
	fclose(obuf);
	if (gotcha) {
E 9
		remove(editfile);
		printf("removed\n");
	}
	else
		printf("complete\n");
D 30
	flush();
E 30
I 30
	fflush(stdout);
E 30
I 10

done:
D 11
	sigret(sigs);
E 11
I 11
	relsesigs();
E 11
E 10
}

I 26
static int sigdepth = 0;		/* depth of holdsigs() */
I 27
D 31
static int sigmask = 0;
E 31
I 31
static int omask = 0;
E 31
E 27
E 26
I 20
D 22
# ifndef VMUNIX
static int	SaveSigs[32];
# endif VMUNIX

E 22
E 20
/*
I 10
D 11
 * Save signals SIGHUP - SIGQUIT in sigs, set them all to action.
E 11
I 11
D 36
 * Hold signals SIGHUP - SIGQUIT.
E 36
I 36
 * Hold signals SIGHUP, SIGINT, and SIGQUIT.
E 36
E 11
 */
D 11
sigsave(sigs, action)
	int (*sigs[])();
E 11
I 11
holdsigs()
E 11
{
D 36
	register int i;
E 36

D 26
	for (i = SIGHUP; i <= SIGQUIT; i++)
I 20
D 22
# ifdef VMUNIX
E 22
E 20
D 11
		sigs[i - SIGHUP] = sigset(i, action);
E 11
I 11
D 24
		sighold(i);
E 24
I 24
		/*
		 * This cannot be changed to ``sighold(i)'' because
		 * of a bug in the jobs library.  Sighold does not
		 * record that one is using the new signal mechanisms
		 * so an eventual sigrelse() will fail.
		 */
		sigset(i, SIG_HOLD);
E 26
I 26
	if (sigdepth++ == 0)
D 27
		for (i = SIGHUP; i <= SIGQUIT; i++)
			sighold(i);
E 27
I 27
D 31
		sigmask = sigblock(mask(SIGHUP)|mask(SIGINT)|mask(SIGQUIT));
E 31
I 31
		omask = sigblock(sigmask(SIGHUP)|sigmask(SIGINT)|sigmask(SIGQUIT));
E 31
E 27
E 26
E 24
I 20
D 22
# else
		SaveSigs[i] = signal(i, SIG_IGN);
# endif
E 22
E 20
E 11
}

/*
D 11
 * Restore SIGHUP - SIGQUIT from sigs.
E 11
I 11
D 36
 * Release signals SIGHUP - SIGQUIT
E 36
I 36
 * Release signals SIGHUP, SIGINT, and SIGQUIT.
E 36
E 11
 */
D 11
sigret(sigs)
	int (*sigs[])();
E 11
I 11
relsesigs()
E 11
{
D 36
	register int i;
E 36
D 11
	
E 11
I 11

E 11
D 26
	for (i = SIGHUP; i <= SIGQUIT; i++)
I 20
D 22
# ifdef VMUNIX
E 22
E 20
D 11
		sigset(i, sigs[i - SIGHUP]);
E 11
I 11
		sigrelse(i);
E 26
I 26
	if (--sigdepth == 0)
D 27
	    for (i = SIGHUP; i <= SIGQUIT; i++)
		    sigrelse(i);
E 27
I 27
D 31
		sigsetmask(sigmask);
E 31
I 31
		sigsetmask(omask);
E 31
E 27
E 26
I 20
D 22
# else
		signal(i, SaveSigs[i]);
# endif
E 22
E 20
E 11
}

/*
E 10
D 30
 * Empty the output buffer.
 */

clrbuf(buf)
	register FILE *buf;
{

	buf = stdout;
	buf->_ptr = buf->_base;
	buf->_cnt = BUFSIZ;
}

/*
E 30
D 36
 * Open a temp file by creating, closing, unlinking, and
 * reopening.  Return the open file descriptor.
E 36
I 36
 * Open a temp file by creating and unlinking.
 * Return the open file descriptor.
E 36
 */
D 36

E 36
opentemp(file)
	char file[];
{
D 36
	register int f;
E 36
I 36
	int f;
E 36

D 36
	if ((f = creat(file, 0600)) < 0) {
E 36
I 36
	if ((f = open(file, O_CREAT|O_EXCL|O_RDWR, 0600)) < 0)
E 36
		perror(file);
D 36
		return(-1);
	}
	close(f);
	if ((f = open(file, 2)) < 0) {
		perror(file);
		remove(file);
		return(-1);
	}
E 36
	remove(file);
D 36
	return(f);
E 36
I 36
	return (f);
E 36
D 30
}

/*
 * Flush the standard output.
 */

flush()
{
	fflush(stdout);
	fflush(stderr);
E 30
}

/*
 * Determine the size of the file possessed by
 * the passed buffer.
 */
D 36

E 36
off_t
fsize(iob)
	FILE *iob;
{
D 36
	register int f;
E 36
	struct stat sbuf;

D 36
	f = fileno(iob);
	if (fstat(f, &sbuf) < 0)
		return(0);
	return(sbuf.st_size);
E 36
I 36
	if (fstat(fileno(iob), &sbuf) < 0)
		return 0;
	return sbuf.st_size;
E 36
}

/*
 * Take a file name, possibly with shell meta characters
 * in it and expand it by using "sh -c echo filename"
 * Return the file name as a dynamic string.
 */
D 36

E 36
char *
expand(name)
	char name[];
{
	char xname[BUFSIZ];
	char cmdbuf[BUFSIZ];
D 36
	register int pid, l, rc;
E 36
I 36
	register int pid, l;
E 36
	register char *cp, *Shell;
D 36
	int s, pivec[2], (*sigint)();
E 36
I 36
	int pivec[2];
E 36
	struct stat sbuf;
I 36
	union wait s;
E 36

I 17
D 19
	if (name[0] == '+' && (cp = value("maildir")) != 0) {
D 18
		sprintf(xname, "%s/%s", cp, name + 1);
E 18
I 18
		if (*cp == '/')
			sprintf(xname, "%s/%s", cp, name + 1);
		else
			sprintf(xname, "%s/%s/%s", homedir, cp, name + 1);
E 19
I 19
	if (name[0] == '+' && getfold(cmdbuf) >= 0) {
		sprintf(xname, "%s/%s", cmdbuf, name + 1);
E 19
E 18
		return(expand(savestr(xname)));
	}
E 17
	if (!anyof(name, "~{[*?$`'\"\\"))
		return(name);
D 10
	/* sigint = signal(SIGINT, SIG_IGN); */
E 10
	if (pipe(pivec) < 0) {
		perror("pipe");
D 10
		/* signal(SIGINT, sigint) */
E 10
		return(name);
	}
	sprintf(cmdbuf, "echo %s", name);
	if ((pid = vfork()) == 0) {
I 22
D 36
		sigchild();
E 36
E 22
		Shell = value("SHELL");
		if (Shell == NOSTR)
			Shell = SHELL;
		close(pivec[0]);
		close(1);
		dup(pivec[1]);
		close(pivec[1]);
		close(2);
		execl(Shell, Shell, "-c", cmdbuf, 0);
		_exit(1);
	}
	if (pid == -1) {
		perror("fork");
		close(pivec[0]);
		close(pivec[1]);
		return(NOSTR);
	}
	close(pivec[1]);
	l = read(pivec[0], xname, BUFSIZ);
	close(pivec[0]);
	while (wait(&s) != pid);
		;
D 36
	s &= 0377;
	if (s != 0 && s != SIGPIPE) {
E 36
I 36
	if (s.w_status != 0 && s.w_termsig != SIGPIPE) {
E 36
		fprintf(stderr, "\"Echo\" failed\n");
		goto err;
	}
	if (l < 0) {
		perror("read");
		goto err;
	}
	if (l == 0) {
		fprintf(stderr, "\"%s\": No match\n", name);
		goto err;
	}
	if (l == BUFSIZ) {
		fprintf(stderr, "Buffer overflow expanding \"%s\"\n", name);
		goto err;
	}
	xname[l] = 0;
	for (cp = &xname[l-1]; *cp == '\n' && cp > xname; cp--)
		;
	*++cp = '\0';
	if (any(' ', xname) && stat(xname, &sbuf) < 0) {
		fprintf(stderr, "\"%s\": Ambiguous\n", name);
		goto err;
	}
D 10
	/* signal(SIGINT, sigint) */
E 10
	return(savestr(xname));

err:
D 10
	/* signal(SIGINT, sigint); */
E 10
	return(NOSTR);
I 19
}

/*
 * Determine the current folder directory name.
 */
getfold(name)
	char *name;
{
	char *folder;

	if ((folder = value("folder")) == NOSTR)
D 36
		return(-1);
E 36
I 36
		return (-1);
E 36
	if (*folder == '/')
		strcpy(name, folder);
	else
		sprintf(name, "%s/%s", homedir, folder);
D 36
	return(0);
E 36
I 36
	return (0);
E 36
E 19
}

/*
 * A nicer version of Fdopen, which allows us to fclose
 * without losing the open file.
 */
D 36

E 36
FILE *
Fdopen(fildes, mode)
	char *mode;
{
D 36
	register int f;
	FILE *fdopen();
E 36
I 36
	int f;
E 36

D 36
	f = dup(fildes);
	if (f < 0) {
E 36
I 36
	if ((f = dup(fildes)) < 0) {
E 36
		perror("dup");
D 36
		return(NULL);
E 36
I 36
		return (NULL);
E 36
	}
D 36
	return(fdopen(f, mode));
E 36
I 36
	return fdopen(f, mode);
E 36
}
E 1
