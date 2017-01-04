h40314
s 00001/00000/00660
d D 5.8 03/12/31 13:32:42 msokolov 31 30
c koi7line:	oops, must account for the terminating NUL too!
e
s 00024/00033/00636
d D 5.7 03/04/15 18:30:27 msokolov 30 29
c Make the KOI-8 to KOI-7 conversion more conservative.
c Make it an identity transformation whenever there are no 8-bit chars on input,
c even if there are SO/SI. This way one can always send any valid 7-bit RFC 822
c message without interference.
e
s 00101/00007/00568
d D 5.6 03/04/15 17:55:19 msokolov 29 28
c support KOI-8 message bodies on input (to be sent in KOI-7)
e
s 00011/00005/00564
d D 5.5 88/02/18 17:04:21 bostic 28 27
c written by Kurt Shoens; added Berkeley specific header
e
s 00038/00038/00531
d D 5.4 87/05/18 12:51:56 edward 27 26
c lint
e
s 00130/00151/00439
d D 5.3 87/05/18 12:28:39 edward 26 25
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00589
d D 5.2 85/06/21 17:13:57 mckusick 25 24
c botched copyright
e
s 00007/00001/00583
d D 5.1 85/06/06 10:42:43 dist 24 23
c Add copyright
e
s 00001/00001/00583
d D 2.14 84/08/08 17:06:02 ralph 23 22
c fix stdio flushing, don't mess with stdio buffers
e
s 00003/00003/00581
d D 2.13 83/08/11 22:19:37 sam 22 21
c standardize sccs keyword lines
e
s 00001/00001/00583
d D 2.12 83/07/02 00:23:57 sam 21 20
c include fix
e
s 00003/00004/00581
d D 2.11 83/05/19 02:32:26 leres 20 18
c Ok to send a message with no subject and no body
e
s 00002/00004/00581
d R 2.11 83/03/17 19:32:30 leres 19 18
c Allow no body, no subject messages, why not?
e
s 00001/00001/00584
d D 2.10 83/02/09 15:25:00 sam 18 17
c from sun
e
s 00043/00022/00542
d D 2.9 83/01/22 15:11:50 leres 17 14
c Modified to only append to the POSTAGE file if it already exists. Modified
c fmt() to *really* limit lines to 72 characters. Added support for verbose
c command/option.
e
s 00043/00022/00542
d R 2.9 83/01/22 15:10:13 leres 16 14
c Modified to only append to the POSTAGE file if it already exists. Modified
c fmt() to *really* limit lines to 72 characters. Added support for verbose
e
s 00043/00022/00542
d R 2.9 83/01/22 15:04:54 leres 15 14
c Modified to append to the POSTAGE file only if it already exists.
c Modified fmt() to *really* limit lines to 72 characters and modified
e
s 00003/00003/00561
d D 2.8 82/12/26 21:16:29 eric 14 13
c change delivermail to sendmail throughout
e
s 00006/00003/00558
d D 2.7 82/11/17 23:11:50 bush 13 12
c Send fixed to supress continuation lines in ignored fields.
e
s 00004/00004/00557
d D 2.6 82/10/21 05:36:54 carl 12 11
c Changes to support long mail sizes (long m_size).
e
s 00005/00000/00556
d D 2.5 82/10/21 04:42:36 carl 11 10
c Wait3 becomes wait2 if pdp11 is defined, stays wait3 if vax is defined.
e
s 00011/00013/00545
d D 2.4 82/07/29 09:13:39 kurt 10 9
c Made recognition of Status: header field slightly more reliable. 
c 
e
s 00060/00011/00498
d D 2.3 82/07/28 23:20:42 kurt 9 8
c changed send() to take doignore argument and ignore header fields 
c that the user doesn't want to see; 
c changed statusput() to see if "status" should be ignored. 
c 
e
s 00002/00001/00507
d D 2.2 82/07/26 17:13:00 kurt 8 7
c added call on sigchild() after fork() to fix retrofit signals; 
c parameterized location of postage meter file 
c 
e
s 00000/00000/00508
d D 2.1 81/07/01 11:10:23 kurt 7 6
c Release to Heidi Stettner
e
s 00004/00002/00504
d D 1.6 81/05/18 15:53:11 kurt 6 5
c added option sendmail which lets you specify what program to use to
c actually send the mail
e
s 00004/00004/00502
d D 1.5 81/04/01 13:03:11 kurt 5 4
c changed calls on signal to sigset
e
s 00032/00002/00474
d D 1.4 81/03/13 12:44:54 kas 4 3
c fixed bug of putting Status:  line in wrong place for non
c Arpanetish messages
e
s 00001/00002/00475
d D 1.3 81/01/05 17:36:49 kas 3 2
c removed incriminating error message
e
s 00051/00006/00426
d D 1.2 80/10/17 00:36:21 kas 2 1
c send() now updates the status: field in the message image
c that it writes out.  Added routine statusput to print the Status: field
c in the appropriate format
e
s 00432/00000/00000
d D 1.1 80/10/08 09:51:16 kas 1 0
c date and time created 80/10/08 09:51:16 by kas
e
u
U
f b 
t
T
I 24
/*
 * Copyright (c) 1980 Regents of the University of California.
D 28
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 28
I 28
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 28
 */

E 24
I 1
D 22
#
E 22
I 22
D 28
#ifndef lint
D 25
static char sccsid[] = "%W% (Berkeley) %G%";
E 25
I 25
static char *sccsid = "%W% (Berkeley) %G%";
E 25
D 24
#endif
E 24
I 24
#endif not lint
E 28
I 28
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 28
E 24
E 22

#include "rcv.h"
D 26
#ifdef VMUNIX
E 26
D 21
#include <wait.h>
E 21
I 21
#include <sys/wait.h>
E 21
D 26
#endif
I 4
#include <ctype.h>
E 26
I 17
#include <sys/stat.h>
E 17
E 4

/*
 * Mail -- a mail program
 *
 * Mail to others.
 */
D 22

static char *SccsId = "%W% %G%";
E 22

/*
 * Send message described by the passed pointer to the
 * passed output buffer.  Return -1 on error, but normally
D 2
 * the number of lines written.
E 2
I 2
 * the number of lines written.  Adjust the status: field
D 9
 * if need be.
E 9
I 9
 * if need be.  If doign is set, suppress ignored header fields.
E 9
E 2
 */
D 10

E 10
D 9
send(mailp, obuf)
E 9
I 9
D 26
send(mailp, obuf, doign)
E 9
	struct message *mailp;
E 26
I 26
send(mp, obuf, doign)
	register struct message *mp;
E 26
	FILE *obuf;
{
D 26
	register struct message *mp;
	register int t;
D 12
	unsigned int c;
E 12
I 12
	long c;
E 12
	FILE *ibuf;
D 2
	int lc;
E 2
I 2
D 9
	char line[LINESIZE];
D 4
	int lc, ishead;
E 4
I 4
	int lc, ishead, infld, fline;
E 9
I 9
	char line[LINESIZE], field[BUFSIZ];
	int lc, ishead, infld, fline, dostat;
	char *cp, *cp2;
E 26
I 26
	long count;
	register FILE *ibuf;
	char line[LINESIZE];
	int lc, ishead, infld, ignoring, dostat;
	register char *cp, *cp2;
	register int c;
	int length;
E 26
E 9
E 4
E 2

D 26
	mp = mailp;
E 26
	ibuf = setinput(mp);
D 12
	c = msize(mp);
E 12
I 12
D 26
	c = mp->m_size;
E 26
I 26
	count = mp->m_size;
E 26
E 12
I 2
D 9
	ishead = (mailp->m_flag & MSTATUS) != 0;
E 9
I 9
	ishead = 1;
D 26
	dostat = 1;
E 26
I 26
	dostat = !doign || !isign("status");
E 26
E 9
I 4
	infld = 0;
D 26
	fline = 1;
E 26
E 4
E 2
	lc = 0;
D 2
	while (c-- > 0) {
		putc(t = getc(ibuf), obuf);
		if (t == '\n')
			lc++;
E 2
I 2
D 12
	while (c > 0) {
E 12
I 12
D 26
	while (c > 0L) {
E 12
		fgets(line, LINESIZE, ibuf);
D 12
		c -= strlen(line);
E 12
I 12
		c -= (long) strlen(line);
E 12
		lc++;
		if (ishead) {
E 26
I 26
	/*
	 * Process headers first
	 */
	while (count > 0 && ishead) {
		if (fgets(line, LINESIZE, ibuf) == NULL)
			break;
		count -= length = strlen(line);
		if (lc == 0) {
E 26
I 9
			/* 
			 * First line is the From line, so no headers
			 * there to worry about
			 */
E 9
I 4
D 26
			if (fline) {
				fline = 0;
				goto writeit;
			}
E 26
I 26
			ignoring = 0;
		} else if (line[0] == '\n') {
E 26
I 9
			/*
			 * If line is blank, we've reached end of
			 * headers, so force out status: field
			 * and note that we are no longer in header
			 * fields
			 */
E 9
E 4
D 26
			if (line[0] == '\n') {
D 9
				statusput(mailp, obuf);
E 9
I 9
				if (dostat) {
					statusput(mailp, obuf, doign);
					dostat = 0;
				}
E 9
				ishead = 0;
				goto writeit;
E 26
I 26
			if (dostat) {
				statusput(mp, obuf);
				dostat = 0;
E 26
			}
I 26
			ishead = 0;
			ignoring = 0;
		} else if (infld && (line[0] == ' ' || line[0] == '\t')) {
E 26
I 9
			/*
D 13
			 * If this line is a continuation
			 * of a previous header field, just echo it.
E 13
I 13
			 * If this line is a continuation (via space or tab)
			 * of a previous header field, just echo it
			 * (unless the field should be ignored).
I 26
			 * In other words, nothing to do.
E 26
E 13
			 */
E 9
D 4
			if (index(line, ':') == 0)
E 4
I 4
D 13
			if (isspace(line[0]) && infld)
E 13
I 13
D 26
			if (infld && (isspace(line[0]) || line[0] == '\t')) {
				if (doign && isign(field)) continue;
E 13
E 4
				goto writeit;
I 13
			}
E 13
I 4
			infld = 0;
E 26
I 26
		} else {
E 26
I 9
			/*
D 26
			 * If we are no longer looking at real
			 * header lines, force out status:
			 * This happens in uucp style mail where
			 * there are no headers at all.
E 26
I 26
			 * Pick up the header field if we have one.
E 26
			 */
E 9
D 26
			if (!headerp(line)) {
E 26
I 26
			for (cp = line; (c = *cp++) && c != ':' && !isspace(c);)
				;
			cp2 = --cp;
			while (isspace(*cp++))
				;
			if (cp[-1] != ':') {
				/*
				 * Not a header line, force out status:
				 * This happens in uucp style mail where
				 * there are no headers at all.
				 */
E 26
D 9
				statusput(mailp, obuf);
E 9
I 9
				if (dostat) {
D 26
					statusput(mailp, obuf, doign);
E 26
I 26
					statusput(mp, obuf);
E 26
					dostat = 0;
				}
E 9
D 26
				putc('\n', obuf);
E 26
I 26
D 27
				putc('\n', obuf);	/* add blank line */
E 27
I 27
				(void) putc('\n', obuf); /* add blank line */
E 27
				lc++;
E 26
				ishead = 0;
D 26
				goto writeit;
			}
			infld++;
I 9
			/*
D 10
			 * We are looking at a header line.
			 * See if it is the status: field,
			 * and if it is, print the real status: field
			 */
E 9
E 4
			if (icisname(line, "status", 6)) {
D 9
				statusput(mailp, obuf);
				ishead = 0;
E 9
I 9
				if (dostat) {
					statusput(mailp, obuf, doign);
					dostat = 0;
				}
E 9
				continue;
			}
I 9
			/*
E 10
			 * Pick up the header field.
			 * If it is an ignored field and
			 * we care about such things, skip it.
			 */
			cp = line;
			cp2 = field;
			while (*cp && *cp != ':' && !isspace(*cp))
				*cp2++ = *cp++;
			*cp2 = 0;
			if (doign && isign(field))
				continue;
I 10
			/*
			 * If the field is "status," go compute and print the
			 * real Status: field
			 */
			if (icequal(field, "status")) {
				if (dostat) {
					statusput(mailp, obuf, doign);
					dostat = 0;
E 26
I 26
				ignoring = 0;
			} else {
				/*
				 * If it is an ignored field and
				 * we care about such things, skip it.
				 */
				*cp2 = 0;	/* temporarily null terminate */
				if (doign && isign(line))
					ignoring = 1;
				else if ((line[0] == 's' || line[0] == 'S') &&
					 icequal(line, "status")) {
					/*
					 * If the field is "status," go compute
					 * and print the real Status: field
					 */
					if (dostat) {
						statusput(mp, obuf);
						dostat = 0;
					}
					ignoring = 1;
				} else {
					ignoring = 0;
					*cp2 = c;	/* restore */
E 26
				}
D 26
				continue;
E 26
I 26
				infld = 1;
E 26
			}
E 10
E 9
		}
D 26
writeit:
		fputs(line, obuf);
E 2
		if (ferror(obuf))
			return(-1);
E 26
I 26
		if (!ignoring) {
D 27
			fwrite(line, sizeof *line, length, obuf);
E 27
I 27
			(void) fwrite(line, sizeof *line, length, obuf);
E 27
			if (ferror(obuf))
				return -1;
			lc++;
		}
E 26
	}
I 2
D 26
	if (ferror(obuf))
		return(-1);
	if (ishead && (mailp->m_flag & MSTATUS))
E 26
I 26
	/*
	 * Copy out message body
	 */
	while (count > 0) {
		cp = line;
		c = count < LINESIZE ? count : LINESIZE;
		if ((c = fread(cp, sizeof *cp, c, ibuf)) <= 0)
			break;
		if (fwrite(cp, sizeof *cp, c, obuf) != c)
			return -1;
		count -= c;
		while (--c >= 0)
			if (*cp++ == '\n')
				lc++;
	}
	if (ishead && (mp->m_flag & MSTATUS))
E 26
		printf("failed to fix up status field\n");
E 2
D 26
	return(lc);
E 26
I 26
	return (lc);
E 26
I 4
}

/*
D 26
 * Test if the passed line is a header line, RFC 733 style.
 */
headerp(line)
	register char *line;
{
	register char *cp = line;

	while (*cp && !isspace(*cp) && *cp != ':')
		cp++;
	while (*cp && isspace(*cp))
		cp++;
	return(*cp == ':');
E 4
}
I 2

/*
E 26
 * Output a reasonable looking status field.
I 9
 * But if "status" is ignored and doign, forget it.
E 9
 */
D 9

statusput(mp, obuf)
E 9
I 9
D 26
statusput(mp, obuf, doign)
E 26
I 26
statusput(mp, obuf)
E 26
E 9
	register struct message *mp;
D 26
	register FILE *obuf;
E 26
I 26
	FILE *obuf;
E 26
{
	char statout[3];
I 26
	register char *cp = statout;
E 26

I 9
D 26
	if (doign && isign("status"))
		return;
E 9
	if ((mp->m_flag & (MNEW|MREAD)) == MNEW)
		return;
E 26
	if (mp->m_flag & MREAD)
D 26
		strcpy(statout, "R");
	else
		strcpy(statout, "");
E 26
I 26
		*cp++ = 'R';
E 26
	if ((mp->m_flag & MNEW) == 0)
D 26
		strcat(statout, "O");
	fprintf(obuf, "Status: %s\n", statout);
E 26
I 26
		*cp++ = 'O';
	*cp = 0;
	if (statout[0])
		fprintf(obuf, "Status: %s\n", statout);
E 26
}

E 2
D 26

E 26
/*
 * Interface between the argument list and the mail1 routine
 * which does all the dirty work.
 */

mail(people)
	char **people;
{
	register char *cp2;
	register int s;
	char *buf, **ap;
	struct header head;

D 26
	for (s = 0, ap = people; *ap != (char *) -1; ap++)
E 26
I 26
	for (s = 0, ap = people; *ap != 0; ap++)
E 26
		s += strlen(*ap) + 1;
	buf = salloc(s+1);
	cp2 = buf;
D 26
	for (ap = people; *ap != (char *) -1; ap++) {
E 26
I 26
	for (ap = people; *ap != 0; ap++) {
E 26
		cp2 = copy(*ap, cp2);
		*cp2++ = ' ';
	}
	if (cp2 != buf)
		cp2--;
	*cp2 = '\0';
	head.h_to = buf;
	head.h_subject = NOSTR;
	head.h_cc = NOSTR;
	head.h_bcc = NOSTR;
	head.h_seq = 0;
D 27
	mail1(&head);
E 27
I 27
	(void) mail1(&head);
E 27
	return(0);
}


/*
 * Send mail to a bunch of user names.  The interface is through
 * the mail routine below.
 */

sendmail(str)
	char *str;
{
D 26
	register char **ap;
	char *bufp;
	register int t;
E 26
	struct header head;

	if (blankline(str))
		head.h_to = NOSTR;
	else
		head.h_to = str;
	head.h_subject = NOSTR;
	head.h_cc = NOSTR;
	head.h_bcc = NOSTR;
	head.h_seq = 0;
D 27
	mail1(&head);
E 27
I 27
	(void) mail1(&head);
E 27
	return(0);
}

/*
 * Mail a message on standard input to the people indicated
 * in the passed header.  (Internal interface).
 */

mail1(hp)
	struct header *hp;
{
	register char *cp;
D 26
	int pid, i, s, p, gotcha;
E 26
I 26
	int pid, i, p, gotcha;
	union wait s;
E 26
D 6
	char **namelist;
E 6
I 6
	char **namelist, *deliver;
E 6
	struct name *to, *np;
I 17
	struct stat sbuf;
E 17
	FILE *mtf, *postage;
	int remote = rflag != NOSTR || rmail;
	char **t;

	/*
	 * Collect user's mail from standard input.
	 * Get the result as mtf.
	 */

	pid = -1;
	if ((mtf = collect(hp)) == NULL)
		return(-1);
	hp->h_seq = 1;
	if (hp->h_subject == NOSTR)
		hp->h_subject = sflag;
D 20
	if (fsize(mtf) == 0 && hp->h_subject == NOSTR) {
		printf("No message !?!\n");
		goto out;
	}
E 20
	if (intty && value("askcc") != NOSTR)
		grabh(hp, GCC);
	else if (intty) {
		printf("EOT\n");
D 23
		flush();
E 23
I 23
D 27
		fflush(stdout);
E 27
I 27
		(void) fflush(stdout);
E 27
E 23
	}

	/*
	 * Now, take the user names from the combined
	 * to and cc lists and do all the alias
	 * processing.
	 */

	senderr = 0;
	to = usermap(cat(extract(hp->h_bcc, GBCC),
	    cat(extract(hp->h_to, GTO), extract(hp->h_cc, GCC))));
	if (to == NIL) {
		printf("No recipients specified\n");
		goto topdog;
	}

	/*
	 * Look through the recipient list for names with /'s
	 * in them which we write to as files directly.
	 */

	to = outof(to, mtf, hp);
	rewind(mtf);
	to = verify(to);
	if (senderr && !remote) {
topdog:

		if (fsize(mtf) != 0) {
D 27
			remove(deadletter);
			exwrite(deadletter, mtf, 1);
E 27
I 27
			(void) remove(deadletter);
			(void) exwrite(deadletter, mtf, 1);
E 27
			rewind(mtf);
		}
	}
	for (gotcha = 0, np = to; np != NIL; np = np->n_flink)
		if ((np->n_type & GDEL) == 0) {
			gotcha++;
			break;
		}
	if (!gotcha)
		goto out;
	to = elide(to);
	mechk(to);
	if (count(to) > 1)
		hp->h_seq++;
	if (hp->h_seq > 0 && !remote) {
		fixhead(hp, to);
		if (fsize(mtf) == 0)
I 20
		    if (hp->h_subject == NOSTR)
			printf("No message, no subject; hope that's ok\n");
		    else
E 20
			printf("Null message body; hope that's ok\n");
		if ((mtf = infix(hp, mtf)) == NULL) {
			fprintf(stderr, ". . . message lost, sorry.\n");
			return(-1);
		}
	}
	namelist = unpack(to);
	if (debug) {
		printf("Recipients of message:\n");
		for (t = namelist; *t != NOSTR; t++)
			printf(" \"%s\"", *t);
		printf("\n");
D 27
		fflush(stdout);
E 27
I 27
		(void) fflush(stdout);
E 27
D 26
		return;
E 26
I 26
		return 0;
E 26
	}
	if ((cp = value("record")) != NOSTR)
D 26
		savemail(expand(cp), hp, mtf);
E 26
I 26
D 27
		savemail(expand(cp), mtf);
E 27
I 27
		(void) savemail(expand(cp), mtf);
E 27
E 26

	/*
	 * Wait, to absorb a potential zombie, then
	 * fork, set up the temporary mail file as standard
	 * input for "mail" and exec with the user list we generated
	 * far above. Return the process id to caller in case he
	 * wants to await the completion of mail.
	 */

D 26
#ifdef VMUNIX
I 11
#ifdef	pdp11
	while (wait2(&s, WNOHANG) > 0)
#endif
D 18
#ifdef	vax
E 18
I 18
#if defined(vax) || defined(sun)
E 18
E 11
	while (wait3(&s, WNOHANG, 0) > 0)
I 11
#endif
E 26
I 26
	while (wait3(&s, WNOHANG, (struct timeval *) 0) > 0)
E 26
E 11
		;
D 26
#else
	wait(&s);
#endif
E 26
	rewind(mtf);
	pid = fork();
	if (pid == -1) {
		perror("fork");
D 27
		remove(deadletter);
		exwrite(deadletter, mtf, 1);
E 27
I 27
		(void) remove(deadletter);
		(void) exwrite(deadletter, mtf, 1);
E 27
		goto out;
	}
	if (pid == 0) {
I 8
D 26
		sigchild();
E 26
E 8
#ifdef SIGTSTP
		if (remote == 0) {
D 5
			signal(SIGTSTP, SIG_IGN);
			signal(SIGTTIN, SIG_IGN);
			signal(SIGTTOU, SIG_IGN);
E 5
I 5
D 26
			sigset(SIGTSTP, SIG_IGN);
			sigset(SIGTTIN, SIG_IGN);
			sigset(SIGTTOU, SIG_IGN);
E 26
I 26
D 27
			signal(SIGTSTP, SIG_IGN);
			signal(SIGTTIN, SIG_IGN);
			signal(SIGTTOU, SIG_IGN);
E 27
I 27
			(void) signal(SIGTSTP, SIG_IGN);
			(void) signal(SIGTTIN, SIG_IGN);
			(void) signal(SIGTTOU, SIG_IGN);
E 27
E 26
E 5
		}
#endif
D 26
		for (i = SIGHUP; i <= SIGQUIT; i++)
D 5
			signal(i, SIG_IGN);
E 5
I 5
			sigset(i, SIG_IGN);
E 26
I 26
D 27
		signal(SIGHUP, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
E 27
I 27
		(void) signal(SIGHUP, SIG_IGN);
		(void) signal(SIGINT, SIG_IGN);
		(void) signal(SIGQUIT, SIG_IGN);
E 27
E 26
E 5
D 8
		if ((postage = fopen("/crp/kurt/postage", "a")) != NULL) {
E 8
I 8
D 17
		if ((postage = fopen(POSTAGE, "a")) != NULL) {
E 8
			fprintf(postage, "%s %d %d\n", myname,
			    count(to), fsize(mtf));
			fclose(postage);
		}
E 17
I 17
		if (!stat(POSTAGE, &sbuf))
			if ((postage = fopen(POSTAGE, "a")) != NULL) {
D 27
				fprintf(postage, "%s %d %d\n", myname,
E 27
I 27
				fprintf(postage, "%s %d %ld\n", myname,
E 27
				    count(to), fsize(mtf));
D 27
				fclose(postage);
E 27
I 27
				(void) fclose(postage);
E 27
			}
E 17
D 26
		s = fileno(mtf);
		for (i = 3; i < 15; i++)
			if (i != s)
				close(i);
E 26
D 27
		close(0);
D 26
		dup(s);
		close(s);
#ifdef CC
		submit(getpid());
#endif CC
E 26
I 26
		dup(fileno(mtf));
E 27
I 27
		(void) close(0);
		(void) dup(fileno(mtf));
E 27
		for (i = getdtablesize(); --i > 2;)
D 27
			close(i);
E 27
I 27
			(void) close(i);
E 27
E 26
D 14
#ifdef DELIVERMAIL
E 14
I 14
#ifdef SENDMAIL
E 14
D 6
		execv(DELIVERMAIL, namelist);
E 6
I 6
		if ((deliver = value("sendmail")) == NOSTR)
D 14
			deliver = DELIVERMAIL;
E 14
I 14
			deliver = SENDMAIL;
E 14
		execv(deliver, namelist);
E 6
D 14
#endif DELIVERMAIL
E 14
I 14
#endif SENDMAIL
E 14
		execv(MAIL, namelist);
		perror(MAIL);
		exit(1);
	}

out:
D 17
	if (remote) {
E 17
I 17
	if (remote || (value("verbose") != NOSTR)) {
E 17
		while ((p = wait(&s)) != pid && p != -1)
			;
D 26
		if (s != 0)
E 26
I 26
		if (s.w_status != 0)
E 26
			senderr++;
		pid = 0;
	}
D 27
	fclose(mtf);
E 27
I 27
	(void) fclose(mtf);
E 27
	return(pid);
}

/*
 * Fix the header by glopping all of the expanded names from
 * the distribution list into the appropriate fields.
 * If there are any ARPA net recipients in the message,
 * we must insert commas, alas.
 */

fixhead(hp, tolist)
	struct header *hp;
	struct name *tolist;
{
D 26
	register struct name *nlist;
E 26
	register int f;
	register struct name *np;

	for (f = 0, np = tolist; np != NIL; np = np->n_flink)
		if (any('@', np->n_name)) {
			f |= GCOMMA;
			break;
		}

	if (debug && f & GCOMMA)
		fprintf(stderr, "Should be inserting commas in recip lists\n");
	hp->h_to = detract(tolist, GTO|f);
	hp->h_cc = detract(tolist, GCC|f);
}

/*
D 29
 * Prepend a header in front of the collected stuff
 * and return the new file.
E 29
I 29
 * Prepend a header in front of the collected stuff and return the new file.
 *
D 30
 * Also if the collected message body is in KOI-8 we convert it to KOI-7 here.
 * As usual the conversion of KOI-8 to KOI-7 is complicated by the possibility
 * of the input already being in KOI-7. To produce the cleanest possible output
 * we first canonicalize the input into KOI-8 and then insert SO/SI where
 * necessary. (This is the same approach I used in cat.)
E 30
I 30
 * Also if the collected message body has any 8-bit characters in it (illegal
 * in RFC 822), convert it to KOI-7. We use a slick algorithm (see the code) to
 * ensure that this is an identity transformation when there are no 8-bit chars
 * in the input and to handle the case of input already being in KOI-7 (or a
 * mixture of KOI-7 and KOI-8).
E 30
 *
D 30
 * (A calming note to our American friends: if the input is pure ASCII without
 *  8-bit chars or SO/SI codes this is the identity transformation.)
 *
E 30
 * We also have to do the same to the Subject: line (RFC 822 allows control
 * chars there, so we are OK with SO/SI). The extra trick here is that the line
 * must end in LAT mode, otherwise when the whole message is simply dumped on a
 * terminal without RFC 822 parsing the subsequent header lines will print
D 30
 * wrong.
E 30
I 30
 * wrong. Again we do nothing if there are no 8-bit chars in the input, but we
 * use a different algorithm because the Subject: line resides entirely in
 * core.
E 30
E 29
 */

FILE *
infix(hp, fi)
	struct header *hp;
D 29
	FILE *fi;
E 29
I 29
	register FILE *fi;
E 29
{
	extern char tempMail[];
	register FILE *nfo, *nfi;
D 29
	register int c;
E 29
I 29
D 30
	register int c, inso, outso;
E 30
I 30
	register int c, state;
E 30
E 29

I 3
	rewind(fi);
E 3
	if ((nfo = fopen(tempMail, "w")) == NULL) {
		perror(tempMail);
		return(fi);
	}
	if ((nfi = fopen(tempMail, "r")) == NULL) {
		perror(tempMail);
D 27
		fclose(nfo);
E 27
I 27
		(void) fclose(nfo);
E 27
		return(fi);
	}
D 27
	remove(tempMail);
	puthead(hp, nfo, GTO|GSUBJECT|GCC|GNL);
E 27
I 27
	(void) remove(tempMail);
I 29
	(void) koi7subj(hp);
E 29
	(void) puthead(hp, nfo, GTO|GSUBJECT|GCC|GNL);
E 27
D 3
	rewind(fi);
E 3
D 29
	c = getc(fi);
	while (c != EOF) {
E 29
I 29
D 30
	inso = outso = 0;
E 30
I 30
	state = 0;
E 30
	while ((c = getc(fi)) != EOF) {
D 30
		if (c == '\016') {
			inso = 1;
			continue;
		}
		if (c == '\017') {
			inso = 0;
			continue;
		}
		if (c >= 0100 && c <= 0177 && inso)
			c |= 0200;
		if (c >= 0100 && c <= 0177 && outso) {
E 30
I 30
		if (c == '\016')
			state = 1;
		else if (c == '\017')
			state = 0;
		else if (c >= 0300) {
			if (state == 0)
				(void) putc('\016', nfo);
			state = 2;
		} else if (c >= 0100 && c <= 0177 && state == 2) {
E 30
			(void) putc('\017', nfo);
D 30
			outso = 0;
E 30
I 30
			state = 0;
E 30
		}
D 30
		if (c >= 0300 && !outso) {
			(void) putc('\016', nfo);
			outso = 1;
		}
E 30
		c &= 0177;
E 29
D 27
		putc(c, nfo);
E 27
I 27
		(void) putc(c, nfo);
E 27
D 29
		c = getc(fi);
E 29
	}
	if (ferror(fi)) {
		perror("read");
D 3
		fprintf(stderr, "Please notify Kurt Shoens\n");
E 3
		return(fi);
	}
D 27
	fflush(nfo);
E 27
I 27
	(void) fflush(nfo);
E 27
	if (ferror(nfo)) {
		perror(tempMail);
D 27
		fclose(nfo);
		fclose(nfi);
E 27
I 27
		(void) fclose(nfo);
		(void) fclose(nfi);
E 27
		return(fi);
	}
D 27
	fclose(nfo);
	fclose(fi);
E 27
I 27
	(void) fclose(nfo);
	(void) fclose(fi);
E 27
	rewind(nfi);
	return(nfi);
I 29
}

koi7subj(hp)
	struct header *hp;
{
	register int newlen;
	register char *newsubj;

	if (hp->h_subject == NOSTR)
		return;
	newlen = koi7line(hp->h_subject, NOSTR);
	if (!newlen)
		return;
	newsubj = salloc(newlen);
	(void) koi7line(hp->h_subject, newsubj);
	hp->h_subject = newsubj;
}

koi7line(src, dst)
	char *src, *dst;
{
	register u_char *cp, *dp;
	register int c, inso, outso, cnt;
D 30
	int change;
E 30
I 30
	int found8;
E 30

D 30
	inso = outso = change = 0;
E 30
I 30
	inso = outso = found8 = 0;
E 30
	for (cp = (u_char*)src, dp = (u_char*)dst, cnt = 0; c = *cp++; ) {
		if (c == '\016') {
			inso = 1;
D 30
			change = 1;
E 30
			continue;
		}
		if (c == '\017') {
			inso = 0;
D 30
			change = 1;
E 30
			continue;
		}
		if (c >= 0100 && c <= 0177 && inso)
			c |= 0200;
		if (c >= 0100 && c <= 0177 && outso) {
			if (dp) *dp++ = '\017';
			cnt++;
			outso = 0;
		}
		if (c >= 0300 && !outso) {
			if (dp) *dp++ = '\016';
			cnt++;
			outso = 1;
D 30
			change = 1;
E 30
I 30
			found8 = 1;
E 30
		}
		if (dp) *dp++ = toascii(c);
		cnt++;
	}
	if (outso) {
		if (dp) *dp++ = '\017';
		cnt++;
	}
	if (dp) *dp = '\0';
I 31
	cnt++;
E 31
D 30
	if (!change)
E 30
I 30
	if (!found8)
E 30
		cnt = 0;
	return(cnt);
E 29
}

/*
 * Dump the to, subject, cc header on the
 * passed file buffer.
 */

puthead(hp, fo, w)
	struct header *hp;
	FILE *fo;
{
	register int gotcha;

	gotcha = 0;
	if (hp->h_to != NOSTR && w & GTO)
D 17
		fprintf(fo, "To: "), fmt(hp->h_to, fo), gotcha++;
E 17
I 17
		fmt("To: ", hp->h_to, fo), gotcha++;
E 17
	if (hp->h_subject != NOSTR && w & GSUBJECT)
		fprintf(fo, "Subject: %s\n", hp->h_subject), gotcha++;
	if (hp->h_cc != NOSTR && w & GCC)
D 17
		fprintf(fo, "Cc: "), fmt(hp->h_cc, fo), gotcha++;
E 17
I 17
		fmt("Cc: ", hp->h_cc, fo), gotcha++;
E 17
	if (hp->h_bcc != NOSTR && w & GBCC)
D 17
		fprintf(fo, "Bcc: "), fmt(hp->h_bcc, fo), gotcha++;
E 17
I 17
		fmt("Bcc: ", hp->h_bcc, fo), gotcha++;
E 17
	if (gotcha && w & GNL)
D 27
		putc('\n', fo);
E 27
I 27
		(void) putc('\n', fo);
E 27
	return(0);
}

/*
 * Format the given text to not exceed 72 characters.
 */

D 17
fmt(str, fo)
	register char *str;
E 17
I 17
fmt(str, txt, fo)
	register char *str, *txt;
E 17
	register FILE *fo;
{
	register int col;
D 17
	register char *cp;
E 17
I 17
	register char *bg, *bl, *pt, ch;
E 17

D 17
	cp = str;
	col = 0;
	while (*cp) {
		if (*cp == ' ' && col > 65) {
			fprintf(fo, "\n    ");
E 17
I 17
	col = strlen(str);
	if (col)
		fprintf(fo, "%s", str);
	pt = bg = txt;
	bl = 0;
	while (*bg) {
		pt++;
D 26
		if (++col >72) {
E 26
I 26
		if (++col > 72) {
E 26
			if (!bl) {
				bl = bg;
				while (*bl && !isspace(*bl))
					bl++;
			}
			if (!*bl)
				goto finish;
			ch = *bl;
			*bl = '\0';
			fprintf(fo, "%s\n    ", bg);
E 17
			col = 4;
D 17
			cp++;
			continue;
E 17
I 17
			*bl = ch;
			pt = bg = ++bl;
			bl = 0;
E 17
		}
D 17
		putc(*cp++, fo);
		col++;
E 17
I 17
		if (!*pt) {
finish:
			fprintf(fo, "%s\n", bg);
			return;
		}
		if (isspace(*pt))
			bl = pt;
E 17
	}
D 17
	putc('\n', fo);
E 17
}

/*
 * Save the outgoing mail on the passed file.
 */

D 26
savemail(name, hp, fi)
E 26
I 26
/*ARGSUSED*/
savemail(name, fi)
E 26
	char name[];
D 26
	struct header *hp;
	FILE *fi;
E 26
I 26
	register FILE *fi;
E 26
{
	register FILE *fo;
D 26
	register int c;
	long now;
E 26
I 26
	char buf[BUFSIZ];
	register i;
	time_t now, time();
E 26
	char *n;
I 26
	char *ctime();
E 26

	if ((fo = fopen(name, "a")) == NULL) {
		perror(name);
D 26
		return(-1);
E 26
I 26
		return (-1);
E 26
	}
D 27
	time(&now);
E 27
I 27
	(void) time(&now);
E 27
D 26
	n = rflag;
	if (n == NOSTR)
E 26
I 26
	if ((n = rflag) == NOSTR)
E 26
		n = myname;
	fprintf(fo, "From %s %s", n, ctime(&now));
	rewind(fi);
D 26
	for (c = getc(fi); c != EOF; c = getc(fi))
		putc(c, fo);
	fprintf(fo, "\n");
E 26
I 26
	while ((i = fread(buf, 1, sizeof buf, fi)) > 0)
D 27
		fwrite(buf, 1, i, fo);
	putc('\n', fo);
E 26
	fflush(fo);
E 27
I 27
		(void) fwrite(buf, 1, i, fo);
	(void) putc('\n', fo);
	(void) fflush(fo);
E 27
	if (ferror(fo))
		perror(name);
D 27
	fclose(fo);
E 27
I 27
	(void) fclose(fo);
E 27
D 26
	return(0);
E 26
I 26
	return (0);
E 26
}
E 1
