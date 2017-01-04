h50024
s 00011/00005/00583
d D 5.5 88/02/18 17:03:29 bostic 22 21
c written by Kurt Shoens; added Berkeley specific header
e
s 00013/00010/00575
d D 5.4 87/05/18 12:28:53 edward 21 20
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00006/00002/00579
d D 5.3 85/09/10 20:29:53 serge 20 19
c made the write command delete the entire header, instead of only the first line
e
s 00001/00001/00580
d D 5.2 85/06/21 17:07:00 mckusick 19 18
c botched copyright
e
s 00008/00002/00573
d D 5.1 85/06/06 10:22:25 dist 18 17
c Add copyright
e
s 00062/00001/00513
d D 2.13 85/04/18 18:20:34 serge 17 16
c modified to work with new stdio; added retain command; fixed several bugs
e
s 00002/00002/00512
d D 2.12 84/08/08 17:06:11 ralph 16 15
c fix stdio flushing, don't mess with stdio buffers
e
s 00003/00003/00511
d D 2.11 83/08/11 22:13:30 sam 15 14
c standardize sccs keyword lines
e
s 00006/00004/00508
d D 2.10 82/10/21 05:38:38 carl 14 13
c Changes to support long mail sizes (long m_size).
c Call to msize(x) replaced by the inline expansion x->m_size.
e
s 00001/00001/00511
d D 2.9 82/07/29 09:28:55 kurt 13 12
c changed alloca to salloc since no alloca on pdp-11's, generally 
c 
e
s 00030/00007/00482
d D 2.8 82/07/29 09:13:08 kurt 12 11
c changed to disallow duplicate insertion of fields into the ignore list; 
c changed igshow() to sort the ignored fields before printing them. 
c 
e
s 00046/00001/00443
d D 2.7 82/07/28 23:07:24 kurt 11 10
c added routine igfield() to add new header fields to the ignore list; 
c added routine igshow() to print out the list of ignored header fields. 
c 
e
s 00003/00003/00441
d D 2.6 82/07/28 15:31:32 kurt 10 9
c changed clobber1 to clob1 to satisfy pdp-11 c compiler name length 
c restriction. 
c 
e
s 00001/00000/00443
d D 2.5 82/07/26 17:06:01 kurt 9 8
c added call on sigchild() after a fork to fix up retrofit signals 
c 
e
s 00028/00005/00415
d D 2.4 82/02/13 14:43:28 kurt 8 7
c put most of the code to do the save command in save1(), which 
c can be called with an extra argument to control marking messages with MSAVED. 
c Added copycmd() which uses save1() to avoid MSAVED'ing messages. 
c 
e
s 00009/00003/00411
d D 2.3 81/10/13 20:50:37 kurt 7 6
c changed "dp" command to say "At EOF" when executed on last message 
c 
e
s 00030/00000/00384
d D 2.2 81/09/09 11:18:48 kurt 6 5
c added command clobber which recurses, clobbering the stack
c with 0xFF.  Thus, when you suspect that someone is relying on the stack
c area being zero, you can catch it
e
s 00000/00000/00384
d D 2.1 81/07/01 11:08:04 kurt 5 4
c Release to Heidi Stettner
e
s 00002/00002/00382
d D 1.4 81/03/20 15:23:23 kas 4 3
c changed delete to touch message and clear preserve and mbox bits
e
s 00001/00003/00383
d D 1.3 80/10/17 00:21:40 kas 3 2
c on the first next command, next() no longer sets dot to 1
c but rather leaves it alone!
e
s 00010/00004/00376
d D 1.2 80/10/16 17:24:49 kas 2 1
c fixed bug in next command -- given a list of messages, it would
c never ``find'' the first one, but always take the following one
e
s 00380/00000/00000
d D 1.1 80/10/08 09:49:20 kas 1 0
c date and time created 80/10/08 09:49:20 by kas
e
u
U
f b 
t
T
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
D 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
 */

E 18
I 1
D 15
#
E 15
I 15
D 22
#ifndef lint
D 17
static char sccsid[] = "%W% (Berkeley) %G%";
E 17
I 17
D 18
static char *sccsid = "%W% (Berkeley) %G%";
E 17
#endif
E 18
I 18
D 19
static char sccsid[] = "%W% (Berkeley) %G%";
E 19
I 19
static char *sccsid = "%W% (Berkeley) %G%";
E 19
#endif not lint
E 22
I 22
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 22
E 18
E 15

#include "rcv.h"
#include <sys/stat.h>
I 21
#include <sys/wait.h>
E 21

/*
 * Mail -- a mail program
 *
 * More user commands.
 */
D 15

static char *SccsId = "%W% %G%";
E 15

/*
 * If any arguments were given, go to the next applicable argument
 * following dot, otherwise, go to the next applicable message.
 * If given as first command with no arguments, print first message.
 */

next(msgvec)
	int *msgvec;
{
	register struct message *mp;
	register int *ip, *ip2;
	int list[2], mdot;

	if (*msgvec != NULL) {

		/*
		 * If some messages were supplied, find the 
		 * first applicable one following dot using
		 * wrap around.
		 */

		mdot = dot - &message[0] + 1;
I 2

		/*
		 * Find the first message in the supplied
		 * message list which follows dot.
		 */

E 2
		for (ip = msgvec; *ip != NULL; ip++)
			if (*ip > mdot)
				break;
		if (*ip == NULL)
			ip = msgvec;
		ip2 = ip;
		do {
D 2
			if (*ip2 != NULL)
				ip2++;
			if (*ip2 == NULL)
				ip2 = msgvec;
E 2
			mp = &message[*ip2 - 1];
			if ((mp->m_flag & MDELETED) == 0) {
				dot = mp;
				goto hitit;
			}
I 2
			if (*ip2 != NULL)
				ip2++;
			if (*ip2 == NULL)
				ip2 = msgvec;
E 2
		} while (ip2 != ip);
		printf("No messages applicable\n");
		return(1);
	}

	/*
	 * If this is the first command, select message 1.
	 * Note that this must exist for us to get here at all.
	 */

D 3
	if (!sawcom) {
		dot = &message[0];
E 3
I 3
	if (!sawcom)
E 3
		goto hitit;
D 3
	}
E 3

	/*
	 * Just find the next good message after dot, no
	 * wraparound.
	 */

	for (mp = dot+1; mp < &message[msgCount]; mp++)
		if ((mp->m_flag & (MDELETED|MSAVED)) == 0)
			break;
	if (mp >= &message[msgCount]) {
		printf("At EOF\n");
		return(0);
	}
	dot = mp;
hitit:
	/*
	 * Print dot.
	 */

	list[0] = dot - &message[0] + 1;
	list[1] = NULL;
	return(type(list));
}

/*
D 8
 * Save the indicated messages at the end of the passed file name.
E 8
I 8
 * Save a message in a file.  Mark the message as saved
 * so we can discard when the user quits.
E 8
 */
D 8

E 8
save(str)
	char str[];
{
I 8

	return(save1(str, 1));
}

/*
 * Copy a message to a file without affected its saved-ness
 */
copycmd(str)
	char str[];
{

	return(save1(str, 0));
}

/*
 * Save/copy the indicated messages at the end of the passed file name.
 * If mark is true, mark the message "saved."
 */
save1(str, mark)
	char str[];
{
E 8
	register int *ip, mesg;
	register struct message *mp;
D 8
	char *file, *disp;
E 8
I 8
	char *file, *disp, *cmd;
E 8
D 14
	int f, *msgvec, lc, cc, t;
E 14
I 14
	int f, *msgvec, lc, t;
	long cc;
E 14
	FILE *obuf;
	struct stat statb;

I 8
	cmd = mark ? "save" : "copy";
E 8
	msgvec = (int *) salloc((msgCount + 2) * sizeof *msgvec);
	if ((file = snarf(str, &f)) == NOSTR)
		return(1);
	if (!f) {
		*msgvec = first(0, MMNORM);
		if (*msgvec == NULL) {
D 8
			printf("No messages to save.\n");
E 8
I 8
			printf("No messages to %s.\n", cmd);
E 8
			return(1);
		}
		msgvec[1] = NULL;
	}
	if (f && getmsglist(str, msgvec, 0) < 0)
		return(1);
	if ((file = expand(file)) == NOSTR)
		return(1);
	printf("\"%s\" ", file);
D 16
	flush();
E 16
I 16
	fflush(stdout);
E 16
	if (stat(file, &statb) >= 0)
		disp = "[Appended]";
	else
		disp = "[New file]";
	if ((obuf = fopen(file, "a")) == NULL) {
		perror(NOSTR);
		return(1);
	}
D 14
	cc = lc = 0;
E 14
I 14
	cc = 0L;
	lc = 0;
E 14
	for (ip = msgvec; *ip && ip-msgvec < msgCount; ip++) {
		mesg = *ip;
		touch(mesg);
		mp = &message[mesg-1];
D 11
		if ((t = send(mp, obuf)) < 0) {
E 11
I 11
		if ((t = send(mp, obuf, 0)) < 0) {
E 11
			perror(file);
			fclose(obuf);
			return(1);
		}
		lc += t;
D 14
		cc += msize(mp);
E 14
I 14
		cc += mp->m_size;
E 14
D 8
		mp->m_flag |= MSAVED;
E 8
I 8
		if (mark)
			mp->m_flag |= MSAVED;
E 8
	}
	fflush(obuf);
	if (ferror(obuf))
		perror(file);
	fclose(obuf);
D 14
	printf("%s %d/%d\n", disp, lc, cc);
E 14
I 14
	printf("%s %d/%ld\n", disp, lc, cc);
E 14
	return(0);
}

/*
 * Write the indicated messages at the end of the passed
 * file name, minus header and trailing blank line.
 */

swrite(str)
	char str[];
{
	register int *ip, mesg;
	register struct message *mp;
	register char *file, *disp;
	char linebuf[BUFSIZ];
	int f, *msgvec, lc, cc, t;
	FILE *obuf, *mesf;
	struct stat statb;

	msgvec = (int *) salloc((msgCount + 2) * sizeof *msgvec);
	if ((file = snarf(str, &f)) == NOSTR)
		return(1);
	if ((file = expand(file)) == NOSTR)
		return(1);
	if (!f) {
		*msgvec = first(0, MMNORM);
		if (*msgvec == NULL) {
			printf("No messages to write.\n");
			return(1);
		}
		msgvec[1] = NULL;
	}
	if (f && getmsglist(str, msgvec, 0) < 0)
		return(1);
	printf("\"%s\" ", file);
D 16
	flush();
E 16
I 16
	fflush(stdout);
E 16
	if (stat(file, &statb) >= 0)
		disp = "[Appended]";
	else
		disp = "[New file]";
	if ((obuf = fopen(file, "a")) == NULL) {
		perror(NOSTR);
		return(1);
	}
	cc = lc = 0;
	for (ip = msgvec; *ip && ip-msgvec < msgCount; ip++) {
		mesg = *ip;
		touch(mesg);
		mp = &message[mesg-1];
		mesf = setinput(mp);
D 20
		t = mp->m_lines - 2;
		readline(mesf, linebuf);
E 20
I 20
		t = mp->m_lines - 1;
		while (t-- > 0) {
			readline(mesf, linebuf);
			if (blankline(linebuf))
				break;
		}
E 20
		while (t-- > 0) {
			fgets(linebuf, BUFSIZ, mesf);
			fputs(linebuf, obuf);
			cc += strlen(linebuf);
		}
		lc += mp->m_lines - 2;
		mp->m_flag |= MSAVED;
	}
	fflush(obuf);
	if (ferror(obuf))
		perror(file);
	fclose(obuf);
	printf("%s %d/%d\n", disp, lc, cc);
	return(0);
}

/*
 * Snarf the file from the end of the command line and
 * return a pointer to it.  If there is no file attached,
 * just return NOSTR.  Put a null in front of the file
 * name so that the message list processing won't see it,
 * unless the file name is the only thing on the line, in
 * which case, return 0 in the reference flag variable.
 */

char *
snarf(linebuf, flag)
	char linebuf[];
	int *flag;
{
	register char *cp;

	*flag = 1;
	cp = strlen(linebuf) + linebuf - 1;

	/*
	 * Strip away trailing blanks.
	 */

D 21
	while (*cp == ' ' && cp > linebuf)
E 21
I 21
	while (cp > linebuf && isspace(*cp))
E 21
		cp--;
	*++cp = 0;

	/*
	 * Now search for the beginning of the file name.
	 */

D 21
	while (cp > linebuf && !any(*cp, "\t "))
E 21
I 21
	while (cp > linebuf && !isspace(*cp))
E 21
		cp--;
	if (*cp == '\0') {
		printf("No file specified.\n");
		return(NOSTR);
	}
D 21
	if (any(*cp, " \t"))
E 21
I 21
	if (isspace(*cp))
E 21
		*cp++ = 0;
	else
		*flag = 0;
	return(cp);
}

/*
 * Delete messages.
 */

delete(msgvec)
	int msgvec[];
{
	return(delm(msgvec));
}

/*
 * Delete messages, then type the new dot.
 */

deltype(msgvec)
	int msgvec[];
{
	int list[2];
I 7
	int lastdot;
E 7

I 7
	lastdot = dot - &message[0] + 1;
E 7
	if (delm(msgvec) >= 0) {
		list[0] = dot - &message[0];
		list[0]++;
D 7
		touch(list[0]);
		list[1] = NULL;
		return(type(list));
E 7
I 7
		if (list[0] > lastdot) {
			touch(list[0]);
			list[1] = NULL;
			return(type(list));
		}
		printf("At EOF\n");
		return(0);
E 7
	}
	else {
		printf("No more messages\n");
		return(0);
	}
}

/*
 * Delete the indicated messages.
 * Set dot to some nice place afterwards.
 * Internal interface.
 */

delm(msgvec)
	int *msgvec;
{
	register struct message *mp;
	register *ip, mesg;
	int last;

	last = NULL;
	for (ip = msgvec; *ip != NULL; ip++) {
		mesg = *ip;
		touch(mesg);
		mp = &message[mesg-1];
D 4
		mp->m_flag |= MDELETED;
		mp->m_flag &= ~(MPRESERVE|MSAVED);
E 4
I 4
		mp->m_flag |= MDELETED|MTOUCH;
		mp->m_flag &= ~(MPRESERVE|MSAVED|MBOX);
E 4
		last = mesg;
	}
	if (last != NULL) {
		dot = &message[last-1];
		last = first(0, MDELETED);
		if (last != NULL) {
			dot = &message[last-1];
			return(0);
		}
		else {
			dot = &message[0];
			return(-1);
		}
	}

	/*
	 * Following can't happen -- it keeps lint happy
	 */

	return(-1);
}

/*
 * Undelete the indicated messages.
 */

undelete(msgvec)
	int *msgvec;
{
	register struct message *mp;
	register *ip, mesg;

	for (ip = msgvec; ip-msgvec < msgCount; ip++) {
		mesg = *ip;
		if (mesg == 0)
			return;
		touch(mesg);
		mp = &message[mesg-1];
		dot = mp;
		mp->m_flag &= ~MDELETED;
	}
}

/*
 * Interactively dump core on "core"
 */

core()
{
	register int pid;
D 21
	int status;
E 21
I 21
	union wait status;
E 21

	if ((pid = vfork()) == -1) {
		perror("fork");
		return(1);
	}
	if (pid == 0) {
I 9
D 21
		sigchild();
E 21
E 9
		abort();
		_exit(1);
	}
	printf("Okie dokie");
	fflush(stdout);
	while (wait(&status) != pid)
		;
D 21
	if (status & 0200)
E 21
I 21
	if (status.w_coredump)
E 21
		printf(" -- Core dumped\n");
	else
		printf("\n");
I 21
	return 0;
E 21
}
I 6

/*
 * Clobber as many bytes of stack as the user requests.
 */
clobber(argv)
	char **argv;
{
	register int times;

	if (argv[0] == 0)
		times = 1;
	else
		times = (atoi(argv[0]) + 511) / 512;
D 10
	clobber1(times);
E 10
I 10
	clob1(times);
E 10
}

/*
 * Clobber the stack.
 */
D 10
clobber1(n)
E 10
I 10
clob1(n)
E 10
{
	char buf[512];
	register char *cp;

	if (n <= 0)
		return;
	for (cp = buf; cp < &buf[512]; *cp++ = 0xFF)
		;
D 10
	clobber1(n - 1);
E 10
I 10
	clob1(n - 1);
I 17
}

/*
 * Add the given header fields to the retained list.
 * If no arguments, print the current list of retained fields.
 */
retfield(list)
	char *list[];
{
	char field[BUFSIZ];
	register int h;
	register struct ignore *igp;
	char **ap;

	if (argcount(list) == 0)
		return(retshow());
	for (ap = list; *ap != 0; ap++) {
		istrcpy(field, *ap);

		if (member(field, retain))
			continue;

		h = hash(field);
		igp = (struct ignore *) calloc(1, sizeof (struct ignore));
D 21
		igp->i_field = calloc(strlen(field) + 1, sizeof (char));
E 21
I 21
		igp->i_field = calloc((unsigned) strlen(field) + 1,
			sizeof (char));
E 21
		strcpy(igp->i_field, field);
		igp->i_link = retain[h];
		retain[h] = igp;
		nretained++;
	}
	return(0);
}

/*
 * Print out all currently retained fields.
 */
retshow()
{
	register int h, count;
	struct ignore *igp;
	char **ap, **ring;
	int igcomp();

	count = 0;
	for (h = 0; h < HSHSIZE; h++)
		for (igp = retain[h]; igp != 0; igp = igp->i_link)
			count++;
	if (count == 0) {
		printf("No fields currently being retained.\n");
		return(0);
	}
	ring = (char **) salloc((count + 1) * sizeof (char *));
	ap = ring;
	for (h = 0; h < HSHSIZE; h++)
		for (igp = retain[h]; igp != 0; igp = igp->i_link)
			*ap++ = igp->i_field;
	*ap = 0;
D 21
	qsort(ring, count, sizeof (char *), igcomp);
E 21
I 21
	qsort((char *) ring, count, sizeof (char *), igcomp);
E 21
	for (ap = ring; *ap != 0; ap++)
		printf("%s\n", *ap);
	return(0);
E 17
I 11
}

/*
 * Add the given header fields to the ignored list.
 * If no arguments, print the current list of ignored fields.
 */
igfield(list)
	char *list[];
{
	char field[BUFSIZ];
	register int h;
	register struct ignore *igp;
	char **ap;

	if (argcount(list) == 0)
		return(igshow());
	for (ap = list; *ap != 0; ap++) {
I 12
		if (isign(*ap))
			continue;
E 12
		istrcpy(field, *ap);
		h = hash(field);
		igp = (struct ignore *) calloc(1, sizeof (struct ignore));
D 21
		igp->i_field = calloc(strlen(field) + 1, sizeof (char));
E 21
I 21
		igp->i_field = calloc((unsigned) strlen(field) + 1,
			sizeof (char));
E 21
		strcpy(igp->i_field, field);
		igp->i_link = ignore[h];
		ignore[h] = igp;
	}
	return(0);
}

/*
 * Print out all currently ignored fields.
 */
igshow()
{
D 12
	register int h, did;
E 12
I 12
	register int h, count;
E 12
	struct ignore *igp;
I 12
	char **ap, **ring;
	int igcomp();
E 12

D 12
	did = 0;
E 12
I 12
	count = 0;
E 12
	for (h = 0; h < HSHSIZE; h++)
D 12
		for (igp = ignore[h]; igp != 0; igp = igp->i_link) {
			printf("%s\n", igp->i_field);
			did++;
		}
	if (!did)
E 12
I 12
		for (igp = ignore[h]; igp != 0; igp = igp->i_link)
			count++;
	if (count == 0) {
E 12
		printf("No fields currently being ignored.\n");
I 12
		return(0);
	}
D 13
	ring = (char **) alloca((count + 1) * sizeof (char *));
E 13
I 13
	ring = (char **) salloc((count + 1) * sizeof (char *));
E 13
	ap = ring;
	for (h = 0; h < HSHSIZE; h++)
		for (igp = ignore[h]; igp != 0; igp = igp->i_link)
			*ap++ = igp->i_field;
	*ap = 0;
D 21
	qsort(ring, count, sizeof (char *), igcomp);
E 21
I 21
	qsort((char *) ring, count, sizeof (char *), igcomp);
E 21
	for (ap = ring; *ap != 0; ap++)
		printf("%s\n", *ap);
E 12
	return(0);
I 12
}

/*
 * Compare two names for sorting ignored field list.
 */
igcomp(l, r)
	char **l, **r;
{

	return(strcmp(*l, *r));
E 12
E 11
E 10
}
E 6
E 1
