h28875
s 00011/00005/00677
d D 5.7 88/02/18 17:03:23 bostic 26 25
c written by Kurt Shoens; added Berkeley specific header
e
s 00133/00240/00549
d D 5.6 87/05/18 12:28:31 edward 25 24
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00035/00788
d D 5.5 86/11/26 16:01:26 bostic 24 23
c removed index() and rindex(), included strings.h
e
s 00051/00007/00772
d D 5.4 86/01/13 20:34:32 mckusick 23 22
c reply to RFC822 instead of RFC733 headers (from sun!gorodish!guy)
e
s 00000/00033/00779
d D 5.3 85/09/15 17:13:55 serge 22 21
c deleted isatty and strncmp, as they are in the C library (from guy@sun)
e
s 00001/00001/00811
d D 5.2 85/06/21 17:06:10 mckusick 21 20
c botched copyright
e
s 00008/00002/00804
d D 5.1 85/06/06 10:21:03 dist 20 19
c Add copyright
e
s 00042/00015/00764
d D 2.12 85/04/18 18:20:10 serge 19 18
c modified to work with new stdio; added retain command; fixed several bugs
e
s 00003/00003/00776
d D 2.11 83/08/11 22:12:55 sam 18 17
c standardize sccs keyword lines
e
s 00000/00002/00779
d D 2.10 83/06/28 17:52:42 leres 17 16
c Removed sendmail conditional compile from nameof() since we should
c always look for a "from" header for the sender.
e
s 00011/00003/00770
d D 2.9 83/05/29 16:59:07 leres 16 15
c Fix to skin() from John Quarterman of utexas-11, does a better job of
c handling imbeded blanks and comments.
e
s 00001/00001/00772
d D 2.8 82/12/26 21:16:02 eric 15 14
c change delivermail to sendmail throughout
e
s 00000/00026/00773
d D 2.7 82/10/21 05:44:49 carl 14 13
c Definitions of msize() and sigchild() deleted.
e
s 00033/00000/00766
d D 2.6 82/07/28 23:02:15 kurt 13 12
c added routine istrcpy() to copy strings lower-cased; 
c added routine isign() to see if a header field is being ignored. 
c 
e
s 00011/00000/00755
d D 2.5 82/07/26 17:04:49 kurt 12 11
c added routine sigchild() to cope with sigretro when 
c we're not using it. 
c 
e
s 00005/00001/00750
d D 2.4 82/02/13 21:22:09 kurt 11 10
c changed source file stacking/unstacking to save/restore the value 
c of loading. 
c 
e
s 00026/00003/00725
d D 2.3 81/12/10 19:33:50 kurt 10 9
c changed nameof() to only return the last part of a uucp 
c name, eg: lastmachine!user when the name is to be used for display 
c purposes (reptype == 0) 
c 
e
s 00001/00006/00727
d D 2.2 81/09/14 19:43:26 kurt 9 8
c fixed bug in alter which made it fail to work if no utime sys call --
c thanks to Mark Horton for this fix
e
s 00000/00000/00733
d D 2.1 81/07/01 11:07:46 kurt 8 7
c Release to Heidi Stettner
e
s 00005/00002/00728
d D 1.7 81/07/01 10:59:58 kurt 7 6
c changed "source" routine to expand() the name first.
e
s 00083/00011/00647
d D 1.6 81/03/11 15:52:31 kas 6 5
c changed recognition of names in sender:, reply-to:, from:, etc.
c Now does appropriate stuff with <> and () in arpanet style host phrases
e
s 00008/00002/00650
d D 1.5 81/01/26 10:28:24 kas 5 4
c Changed nameof to return from: or sender: field if not
c replying; other stuff if appropriate
e
s 00001/00001/00651
d D 1.4 81/01/12 17:30:44 kas 4 3
c when there is a reply-to, nameof now returns a savestr'd version,
c rather than a stack local
e
s 00011/00003/00641
d D 1.3 80/10/18 16:57:57 kas 3 2
c changed file stacking to save and restore cond flag;
c also sets it to CANY at beginning of source
e
s 00008/00002/00636
d D 1.2 80/10/17 00:16:30 kas 2 1
c Changed touch() to set MREAD, and if MREAD wasn't set before,
c to set MSTATUS.
e
s 00638/00000/00000
d D 1.1 80/10/08 09:47:15 kas 1 0
c date and time created 80/10/08 09:47:15 by kas
e
u
U
f b 
t
T
I 20
/*
 * Copyright (c) 1980 Regents of the University of California.
D 26
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 26
I 26
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 26
 */

E 20
I 1
D 18
#
E 18
I 18
D 26
#ifndef lint
D 19
static char sccsid[] = "%W% (Berkeley) %G%";
E 19
I 19
D 20
static char *sccsid = "%W% (Berkeley) %G%";
E 19
#endif
E 20
I 20
D 21
static char sccsid[] = "%W% (Berkeley) %G%";
E 21
I 21
static char *sccsid = "%W% (Berkeley) %G%";
E 21
#endif not lint
E 26
I 26
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 26
E 20
E 18

#include "rcv.h"
#include <sys/stat.h>
D 10
#include <sgtty.h>
E 10
D 25
#include <ctype.h>
I 24
#include <strings.h>
E 25
E 24

/*
 * Mail -- a mail program
 *
 * Auxiliary functions.
 */
D 18

static char *SccsId = "%W% %G%";
E 18

/*
 * Return a pointer to a dynamic copy of the argument.
 */

char *
savestr(str)
	char *str;
{
	register char *cp, *cp2, *top;

	for (cp = str; *cp; cp++)
		;
	top = salloc(cp-str + 1);
	if (top == NOSTR)
		return(NOSTR);
	for (cp = str, cp2 = top; *cp; cp++)
		*cp2++ = *cp;
	*cp2 = 0;
	return(top);
}

/*
D 25
 * Copy the name from the passed header line into the passed
 * name buffer.  Null pad the name buffer.
 */

copyname(linebuf, nbuf)
	char *linebuf, *nbuf;
{
	register char *cp, *cp2;

	for (cp = linebuf + 5, cp2 = nbuf; *cp != ' ' && cp2-nbuf < 8; cp++)
		*cp2++ = *cp;
	while (cp2-nbuf < 8)
		*cp2++ = 0;
}

/*
E 25
 * Announce a fatal error and die.
 */

D 25
panic(str)
	char *str;
E 25
I 25
/*VARARGS1*/
panic(fmt, a, b)
	char *fmt;
E 25
{
D 25
	prs("panic: ");
	prs(str);
	prs("\n");
E 25
I 25
	fprintf(stderr, "panic: ");
	fprintf(stderr, fmt, a, b);
	putc('\n', stderr);
E 25
	exit(1);
}

/*
D 25
 * Catch stdio errors and report them more nicely.
 */

_error(str)
	char *str;
{
	prs("Stdio Error: ");
	prs(str);
	prs("\n");
	abort();
}

/*
 * Print a string on diagnostic output.
 */

prs(str)
	char *str;
{
	register char *s;

	for (s = str; *s; s++)
		;
	write(2, str, s-str);
}

/*
E 25
 * Touch the named message by setting its MTOUCH flag.
 * Touched messages have the effect of not being sent
 * back to the system mailbox on exit.
 */

touch(mesg)
{
D 2
	if (mesg >= 1 && mesg <= msgCount)
		message[mesg-1].m_flag |= MTOUCH;
E 2
I 2
	register struct message *mp;

	if (mesg < 1 || mesg > msgCount)
		return;
	mp = &message[mesg-1];
	mp->m_flag |= MTOUCH;
	if ((mp->m_flag & MREAD) == 0)
		mp->m_flag |= MREAD|MSTATUS;
E 2
}

/*
 * Test to see if the passed file name is a directory.
 * Return true if it is.
 */

isdir(name)
	char name[];
{
	struct stat sbuf;

	if (stat(name, &sbuf) < 0)
		return(0);
	return((sbuf.st_mode & S_IFMT) == S_IFDIR);
}

/*
D 14
 * Compute the size in characters of the passed message
 */

unsigned int
msize(messp)
	struct message *messp;
{
	register struct message *mp;

	mp = messp;
	return(mp->m_size);
}

/*
E 14
 * Count the number of arguments in the given string raw list.
 */

argcount(argv)
	char **argv;
{
	register char **ap;

D 25
	for (ap = argv; *ap != NOSTR; ap++)
E 25
I 25
	for (ap = argv; *ap++ != NOSTR;)
E 25
		;	
D 25
	return(ap-argv);
E 25
I 25
	return ap - argv - 1;
E 25
}

/*
D 25
 * Given a file address, determine the
 * block number it represents.
 */

blockof(off)
	off_t off;
{
	off_t a;

	a = off >> 9;
	a &= 077777;
	return((int) a);
}

/*
 * Take a file address, and determine
 * its offset in the current block.
 */

offsetof(off)
	off_t off;
{
	off_t a;

	a = off & 0777;
	return((int) a);
}

/*
E 25
D 22
 * Determine if the passed file is actually a tty, via a call to
 * gtty.  This is not totally reliable, but . . .
 */

isatty(f)
{
	struct sgttyb buf;

	if (gtty(f, &buf) < 0)
		return(0);
	return(1);
}

/*
E 22
 * Return the desired header line from the passed message
 * pointer (or NOSTR if the desired header field is not available).
 */

char *
hfield(field, mp)
	char field[];
	struct message *mp;
{
	register FILE *ibuf;
	char linebuf[LINESIZE];
	register int lc;
I 25
	register char *hfield;
	char *colon;
E 25

	ibuf = setinput(mp);
D 25
	if ((lc = mp->m_lines) <= 0)
		return(NOSTR);
E 25
I 25
	if ((lc = mp->m_lines - 1) < 0)
		return NOSTR;
E 25
	if (readline(ibuf, linebuf) < 0)
D 25
		return(NOSTR);
	lc--;
	do {
		lc = gethfield(ibuf, linebuf, lc);
		if (lc == -1)
			return(NOSTR);
		if (ishfield(linebuf, field))
			return(savestr(hcontents(linebuf)));
	} while (lc > 0);
	return(NOSTR);
E 25
I 25
		return NOSTR;
	while (lc > 0) {
		if ((lc = gethfield(ibuf, linebuf, lc, &colon)) < 0)
			return NOSTR;
		if (hfield = ishfield(linebuf, colon, field))
			return savestr(hfield);
	}
	return NOSTR;
E 25
}

/*
 * Return the next header field found in the given message.
D 25
 * Return > 0 if something found, <= 0 elsewise.
E 25
I 25
 * Return >= 0 if something found, < 0 elsewise.
 * "colon" is set to point to the colon in the header.
E 25
 * Must deal with \ continuations & other such fraud.
 */

D 25
gethfield(f, linebuf, rem)
E 25
I 25
gethfield(f, linebuf, rem, colon)
E 25
	register FILE *f;
	char linebuf[];
	register int rem;
I 25
	char **colon;
E 25
{
	char line2[LINESIZE];
D 25
	long loc;
E 25
	register char *cp, *cp2;
	register int c;

D 25

E 25
	for (;;) {
D 25
		if (rem <= 0)
			return(-1);
		if (readline(f, linebuf) < 0)
			return(-1);
		rem--;
		if (strlen(linebuf) == 0)
			return(-1);
		if (isspace(linebuf[0]))
E 25
I 25
		if (--rem < 0)
			return -1;
		if ((c = readline(f, linebuf)) <= 0)
			return -1;
		for (cp = linebuf; isprint(*cp) && *cp != ' ' && *cp != ':';
		     cp++)
			;
		if (*cp != ':' || cp == linebuf)
E 25
			continue;
D 25
		if (linebuf[0] == '>')
			continue;
		cp = index(linebuf, ':');
		if (cp == NOSTR)
			continue;
		for (cp2 = linebuf; cp2 < cp; cp2++)
			if (isdigit(*cp2))
				continue;
		
E 25
		/*
		 * I guess we got a headline.
		 * Handle wraparounding
		 */
D 25
		
E 25
I 25
		*colon = cp;
		cp = linebuf + c;
E 25
		for (;;) {
I 25
			while (--cp >= linebuf && (*cp == ' ' || *cp == '\t'))
				;
			cp++;
E 25
			if (rem <= 0)
				break;
D 25
#ifdef CANTELL
			loc = ftell(f);
			if (readline(f, line2) < 0)
E 25
I 25
			ungetc(c = getc(f), f);
			if (c != ' ' && c != '\t')
E 25
				break;
D 25
			rem--;
			if (!isspace(line2[0])) {
				fseek(f, loc, 0);
				rem++;
E 25
I 25
			if ((c = readline(f, line2)) < 0)
E 25
				break;
D 25
			}
#else
			c = getc(f);
			ungetc(c, f);
			if (!isspace(c) || c == '\n')
				break;
			if (readline(f, line2) < 0)
				break;
E 25
			rem--;
D 25
#endif
			cp2 = line2;
			for (cp2 = line2; *cp2 != 0 && isspace(*cp2); cp2++)
E 25
I 25
			for (cp2 = line2; *cp2 == ' ' || *cp2 == '\t'; cp2++)
E 25
				;
D 25
			if (strlen(linebuf) + strlen(cp2) >= LINESIZE-2)
E 25
I 25
			c -= cp2 - line2;
			if (cp + c >= linebuf + LINESIZE - 2)
E 25
				break;
D 25
			cp = &linebuf[strlen(linebuf)];
			while (cp > linebuf &&
			    (isspace(cp[-1]) || cp[-1] == '\\'))
				cp--;
E 25
			*cp++ = ' ';
D 25
			for (cp2 = line2; *cp2 != 0 && isspace(*cp2); cp2++)
				;
			strcpy(cp, cp2);
E 25
I 25
			bcopy(cp2, cp, c);
			cp += c;
E 25
		}
D 25
		if ((c = strlen(linebuf)) > 0) {
			cp = &linebuf[c-1];
			while (cp > linebuf && isspace(*cp))
				cp--;
			*++cp = 0;
		}
		return(rem);
E 25
I 25
		*cp = 0;
		return rem;
E 25
	}
	/* NOTREACHED */
}

/*
 * Check whether the passed line is a header line of
D 25
 * the desired breed.
E 25
I 25
 * the desired breed.  Return the field body, or 0.
E 25
 */

D 25
ishfield(linebuf, field)
E 25
I 25
char*
ishfield(linebuf, colon, field)
E 25
	char linebuf[], field[];
I 25
	char *colon;
E 25
{
D 25
	register char *cp;
	register int c;
E 25
I 25
	register char *cp = colon;
E 25

D 25
	if ((cp = index(linebuf, ':')) == NOSTR)
		return(0);
	if (cp == linebuf)
		return(0);
	cp--;
	while (cp > linebuf && isspace(*cp))
		cp--;
	c = *++cp;
E 25
	*cp = 0;
D 25
	if (icequal(linebuf ,field)) {
		*cp = c;
		return(1);
E 25
I 25
	if (!icequal(linebuf, field)) {
		*cp = ':';
		return 0;
E 25
	}
D 25
	*cp = c;
	return(0);
E 25
I 25
	*cp = ':';
	for (cp++; *cp == ' ' || *cp == '\t'; cp++)
		;
	return cp;
E 25
}

/*
D 25
 * Extract the non label information from the given header field
 * and return it.
 */

char *
hcontents(hfield)
	char hfield[];
{
	register char *cp;

	if ((cp = index(hfield, ':')) == NOSTR)
		return(NOSTR);
	cp++;
	while (*cp && isspace(*cp))
		cp++;
	return(cp);
}

/*
E 25
 * Compare two strings, ignoring case.
 */

icequal(s1, s2)
	register char *s1, *s2;
{
I 25
	register c1, c2;
E 25

D 25
	while (raise(*s1++) == raise(*s2))
		if (*s2++ == 0)
			return(1);
	return(0);
E 25
I 25
	for (;;) {
		if ((c1 = (unsigned char)*s1++) !=
		    (c2 = (unsigned char)*s2++)) {
			if (isupper(c1))
				c1 = tolower(c1);
			if (c1 != c2)
				return 0;
		}
		if (c1 == 0)
			return 1;
	}
	/*NOTREACHED*/
E 25
}

/*
I 13
 * Copy a string, lowercasing it as we go.
 */
istrcpy(dest, src)
D 25
	char *dest, *src;
E 25
I 25
	register char *dest, *src;
E 25
{
D 25
	register char *cp, *cp2;
E 25

D 25
	cp2 = dest;
	cp = src;
E 25
	do {
D 25
		*cp2++ = little(*cp);
	} while (*cp++ != 0);
E 25
I 25
		if (isupper(*src))
			*dest++ = tolower(*src);
		else
			*dest++ = *src;
	} while (*src++ != 0);
E 25
}

/*
E 13
 * The following code deals with input stacking to do source
 * commands.  All but the current file pointer are saved on
 * the stack.
 */

static	int	ssp = -1;		/* Top of file stack */
D 3
static	FILE	*sstack[_NFILE];	/* Saved input files */
E 3
I 3
struct sstack {
	FILE	*s_file;		/* File we were in. */
	int	s_cond;			/* Saved state of conditionals */
I 11
	int	s_loading;		/* Loading .mailrc, etc. */
E 11
D 19
} sstack[_NFILE];
E 19
I 19
} sstack[NOFILE];
E 19
E 3

/*
 * Pushdown current input file and switch to a new one.
 * Set the global flag "sourcing" so that others will realize
 * that they are no longer reading from a tty (in all probability).
 */

source(name)
	char name[];
{
	register FILE *fi;
I 7
	register char *cp;
E 7

D 7
	if ((fi = fopen(name, "r")) == NULL) {
		perror(name);
E 7
I 7
	if ((cp = expand(name)) == NOSTR)
		return(1);
	if ((fi = fopen(cp, "r")) == NULL) {
		perror(cp);
E 7
		return(1);
	}
D 19
	if (ssp >= _NFILE-2) {
E 19
I 19
	if (ssp >= NOFILE - 2) {
E 19
		printf("Too much \"sourcing\" going on.\n");
		fclose(fi);
		return(1);
	}
D 3
	sstack[++ssp] = input;
E 3
I 3
	sstack[++ssp].s_file = input;
	sstack[ssp].s_cond = cond;
I 11
	sstack[ssp].s_loading = loading;
	loading = 0;
E 11
	cond = CANY;
E 3
	input = fi;
	sourcing++;
	return(0);
}

/*
D 25
 * Source a file, but do nothing if the file cannot be opened.
 */

source1(name)
	char name[];
{
	register int f;

	if ((f = open(name, 0)) < 0)
		return(0);
	close(f);
	source(name);
}

/*
E 25
 * Pop the current input back to the previous level.
 * Update the "sourcing" flag as appropriate.
 */

unstack()
{
	if (ssp < 0) {
		printf("\"Source\" stack over-pop.\n");
		sourcing = 0;
		return(1);
	}
	fclose(input);
D 3
	input = sstack[ssp--];
E 3
I 3
	if (cond != CANY)
		printf("Unmatched \"if\"\n");
	cond = sstack[ssp].s_cond;
I 11
	loading = sstack[ssp].s_loading;
E 11
	input = sstack[ssp--].s_file;
E 3
	if (ssp < 0)
D 11
		sourcing = 0;
E 11
I 11
		sourcing = loading;
E 11
	return(0);
}

/*
 * Touch the indicated file.
 * This is nifty for the shell.
 * If we have the utime() system call, this is better served
 * by using that, since it will work for empty files.
 * On non-utime systems, we must sleep a second, then read.
 */

alter(name)
	char name[];
{
#ifdef UTIME
	struct stat statb;
	long time();
	time_t time_p[2];
#else
	register int pid, f;
	char w;
#endif UTIME

#ifdef UTIME
	if (stat(name, &statb) < 0)
		return;
	time_p[0] = time((long *) 0) + 1;
	time_p[1] = statb.st_mtime;
	utime(name, time_p);
#else
D 9
	if ((pid = fork()) != 0)
		return;
	clrbuf(stdout);
	clrbuf(stderr);
	clrbuf(stdin);
E 9
	sleep(1);
	if ((f = open(name, 0)) < 0)
D 9
		exit(1);
E 9
I 9
		return;
E 9
	read(f, &w, 1);
	exit(0);
#endif
}

/*
 * Examine the passed line buffer and
 * return true if it is all blanks and tabs.
 */

blankline(linebuf)
	char linebuf[];
{
	register char *cp;

	for (cp = linebuf; *cp; cp++)
D 19
		if (!any(*cp, " \t"))
E 19
I 19
		if (*cp != ' ' && *cp != '\t')
E 19
			return(0);
	return(1);
}

/*
I 6
 * Get sender's name from this message.  If the message has
 * a bunch of arpanet stuff in it, we may have to skin the name
 * before returning it.
 */
char *
nameof(mp, reptype)
	register struct message *mp;
{
I 10
	register char *cp, *cp2;
E 10

D 10
	return(skin(name1(mp, reptype)));
E 10
I 10
	cp = skin(name1(mp, reptype));
	if (reptype != 0 || charcount(cp, '!') < 2)
		return(cp);
	cp2 = rindex(cp, '!');
	cp2--;
	while (cp2 > cp && *cp2 != '!')
		cp2--;
	if (*cp2 == '!')
		return(cp2 + 1);
	return(cp);
E 10
}

/*
D 23
 * Skin an arpa net address according to the RFC 733 interpretation
E 23
I 23
 * Skin an arpa net address according to the RFC 822 interpretation
E 23
 * of "host-phrase."
 */
char *
skin(name)
	char *name;
{
	register int c;
	register char *cp, *cp2;
I 23
	char *bufend;
E 23
	int gotlt, lastsp;
	char nbuf[BUFSIZ];
I 19
	int nesting;
E 19

	if (name == NOSTR)
		return(NOSTR);
D 16
	if (index(name, '(') == NOSTR && index(name, '<') == NOSTR)
E 16
I 16
	if (index(name, '(') == NOSTR && index(name, '<') == NOSTR
D 25
	&& index(name, ' ') == NOSTR)
E 25
I 25
	    && index(name, ' ') == NOSTR)
E 25
E 16
		return(name);
	gotlt = 0;
	lastsp = 0;
D 16
	for (cp = name, cp2 = nbuf, c = *cp++; *cp; c = *cp++) {
E 16
I 16
D 23
	for (cp = name, cp2 = nbuf; c = *cp++; ) {
E 23
I 23
	bufend = nbuf;
	for (cp = name, cp2 = bufend; c = *cp++; ) {
E 23
E 16
		switch (c) {
		case '(':
I 23
			/*
			 * Start of a "comment".
			 * Ignore it.
			 */
E 23
D 19
			while (*cp != ')' && *cp != 0)
				cp++;
			if (*cp)
				cp++;
E 19
I 19
			nesting = 1;
D 23
			while (*cp != '\0') {
				switch (*cp++) {
E 23
I 23
			while ((c = *cp) != 0) {
				cp++;
				switch (c) {
				case '\\':
					if (*cp == 0)
						goto outcm;
					cp++;
					break;
E 23
				case '(':
					nesting++;
					break;

				case ')':
					--nesting;
					break;
				}

				if (nesting <= 0)
					break;
			}
I 23
		outcm:
E 23
E 19
I 16
			lastsp = 0;
E 16
			break;

I 23
		case '"':
			/*
			 * Start of a "quoted-string".
			 * Copy it in its entirety.
			 */
			while ((c = *cp) != 0) {
				cp++;
				switch (c) {
				case '\\':
					if ((c = *cp) == 0)
						goto outqs;
					cp++;
					break;
				case '"':
					goto outqs;
				}
				*cp2++ = c;
			}
		outqs:
			lastsp = 0;
			break;

E 23
		case ' ':
D 16
			lastsp = 1;
E 16
I 16
			if (cp[0] == 'a' && cp[1] == 't' && cp[2] == ' ')
				cp += 3, *cp2++ = '@';
			else
			if (cp[0] == '@' && cp[1] == ' ')
				cp += 2, *cp2++ = '@';
			else
				lastsp = 1;
E 16
			break;

		case '<':
D 23
			cp2 = nbuf;
E 23
I 23
			cp2 = bufend;
E 23
			gotlt++;
			lastsp = 0;
			break;

		case '>':
D 23
			if (gotlt)
				goto done;
E 23
I 23
			if (gotlt) {
				gotlt = 0;
				while (*cp != ',' && *cp != 0)
					cp++;
				if (*cp == 0 )
					goto done;
				*cp2++ = ',';
				*cp2++ = ' ';
				bufend = cp2;
				break;
			}
E 23

			/* Fall into . . . */

		default:
			if (lastsp) {
				lastsp = 0;
				*cp2++ = ' ';
			}
			*cp2++ = c;
			break;
		}
	}
done:
	*cp2 = 0;

	return(savestr(nbuf));
}

/*
E 6
 * Fetch the sender's name from the passed message.
I 5
D 6
 * If fetching this name for replying purposes, do not
 * return sender:
E 6
I 6
 * Reptype can be
 *	0 -- get sender's name for display purposes
 *	1 -- get sender's name for reply
 *	2 -- get sender's name for Reply
E 6
E 5
 */

char *
D 5
nameof(mp)
E 5
I 5
D 6
nameof(mp, reply)
E 6
I 6
name1(mp, reptype)
E 6
E 5
	register struct message *mp;
{
	char namebuf[LINESIZE];
	char linebuf[LINESIZE];
	register char *cp, *cp2;
	register FILE *ibuf;
	int first = 1;

D 5
	if ((cp = hfield("reply-to", mp)) != NOSTR) {
E 5
I 5
D 6
	if ((cp = hfield("from", mp)) != NOSTR) {
		strcpy(namebuf, cp);
		return(savestr(namebuf));
	}
	if (!reply && (cp = hfield("sender", mp)) != NOSTR) {
E 5
		strcpy(namebuf, cp);
D 4
		return(namebuf);
E 4
I 4
		return(savestr(namebuf));
E 4
	}
E 6
I 6
D 15
#ifndef DELIVERMAIL
E 15
I 15
D 17
#ifndef SENDMAIL
E 17
E 15
	if ((cp = hfield("from", mp)) != NOSTR)
D 25
		return(cp);
E 25
I 25
		return cp;
E 25
	if (reptype == 0 && (cp = hfield("sender", mp)) != NOSTR)
D 25
		return(cp);
E 25
I 25
		return cp;
E 25
D 17
#endif
E 17
E 6
	ibuf = setinput(mp);
D 25
	copy("", namebuf);
	if (readline(ibuf, linebuf) <= 0)
E 25
I 25
	namebuf[0] = 0;
	if (readline(ibuf, linebuf) < 0)
E 25
		return(savestr(namebuf));
newname:
D 25
	for (cp = linebuf; *cp != ' '; cp++)
E 25
I 25
	for (cp = linebuf; *cp && *cp != ' '; cp++)
E 25
		;
D 25
	while (any(*cp, " \t"))
		cp++;
	for (cp2 = &namebuf[strlen(namebuf)]; *cp && !any(*cp, " \t") &&
	    cp2-namebuf < LINESIZE-1; *cp2++ = *cp++)
E 25
I 25
	for (; *cp == ' ' || *cp == '\t'; cp++)
E 25
		;
I 25
	for (cp2 = &namebuf[strlen(namebuf)];
	     *cp && *cp != ' ' && *cp != '\t' && cp2 < namebuf + LINESIZE - 1;)
		*cp2++ = *cp++;
E 25
	*cp2 = '\0';
D 25
	if (readline(ibuf, linebuf) <= 0)
E 25
I 25
	if (readline(ibuf, linebuf) < 0)
E 25
		return(savestr(namebuf));
	if ((cp = index(linebuf, 'F')) == NULL)
		return(savestr(namebuf));
	if (strncmp(cp, "From", 4) != 0)
		return(savestr(namebuf));
	while ((cp = index(cp, 'r')) != NULL) {
		if (strncmp(cp, "remote", 6) == 0) {
			if ((cp = index(cp, 'f')) == NULL)
				break;
			if (strncmp(cp, "from", 4) != 0)
				break;
			if ((cp = index(cp, ' ')) == NULL)
				break;
			cp++;
			if (first) {
D 25
				copy(cp, namebuf);
E 25
I 25
				strcpy(namebuf, cp);
E 25
				first = 0;
			} else
				strcpy(rindex(namebuf, '!')+1, cp);
			strcat(namebuf, "!");
			goto newname;
		}
		cp++;
	}
	return(savestr(namebuf));
}

/*
I 10
 * Count the occurances of c in str
 */
charcount(str, c)
	char *str;
{
	register char *cp;
	register int i;

	for (i = 0, cp = str; *cp; cp++)
		if (*cp == c)
			i++;
	return(i);
}

/*
E 10
D 24
 * Find the rightmost pointer to an instance of the
 * character in the string and return it.
 */
D 10

E 10
char *
rindex(str, c)
	char str[];
	register int c;
{
	register char *cp, *cp2;

	for (cp = str, cp2 = NOSTR; *cp; cp++)
		if (c == *cp)
			cp2 = cp;
	return(cp2);
}

/*
E 24
D 25
 * See if the string is a number.
E 25
I 25
 * Are any of the characters in the two strings the same?
E 25
 */

D 25
numeric(str)
	char str[];
E 25
I 25
anyof(s1, s2)
	register char *s1, *s2;
E 25
{
D 25
	register char *cp = str;
E 25

D 25
	while (*cp)
		if (!isdigit(*cp++))
			return(0);
	return(1);
E 25
I 25
	while (*s1)
		if (index(s2, *s1++))
			return 1;
	return 0;
E 25
}

/*
D 25
 * Are any of the characters in the two strings the same?
E 25
I 25
 * Convert c to upper case
E 25
 */

D 25
anyof(s1, s2)
E 25
I 25
raise(c)
	register c;
{

	if (islower(c))
		return toupper(c);
	return c;
}

/*
 * Copy s1 to s2, return pointer to null in s2.
 */

char *
copy(s1, s2)
E 25
	register char *s1, *s2;
{
D 25
	register int c;
E 25

D 25
	while (c = *s1++)
		if (any(c, s2))
			return(1);
	return(0);
E 25
I 25
	while (*s2++ = *s1++)
		;
	return s2 - 1;
E 25
D 24
}

/*
 * Determine the leftmost index of the character
 * in the string.
 */

char *
index(str, ch)
	char *str;
{
	register char *cp;
	register int c;

	for (c = ch, cp = str; *cp; cp++)
		if (*cp == c)
			return(cp);
	return(NOSTR);
E 24
D 22
}

/*
 * String compare two strings of bounded length.
 */

strncmp(as1, as2, an)
	char *as1, *as2;
{
	register char *s1, *s2;
	register int n;

	s1 = as1;
	s2 = as2;
	n = an;
	while (--n >= 0 && *s1 == *s2++)
		if (*s1++ == '\0')
			return(0);
	return(n<0 ? 0 : *s1 - *--s2);
E 22
}
D 14

I 12
#ifndef SIGRETRO

/*
 * This routine is used by the sigretro package to
 * reset held signals to ignored signals.  If you're not
 * using sigretro, you don't need to do anything, but you DO
 * need this stub to keep everyone happy.
 */
sigchild() {}

#endif SIGRETRO
E 14
I 13

/*
I 25
 * Add a single character onto a string.
 */

stradd(str, c)
	register char *str;
{

	while (*str++)
		;
	str[-1] = c;
	*str = 0;
}

/*
E 25
 * See if the given header field is supposed to be ignored.
 */
isign(field)
	char *field;
{
	char realfld[BUFSIZ];
D 19
	register int h;
	register struct ignore *igp;
E 19

I 19
	/*
	 * Lower-case the string, so that "Status" and "status"
	 * will hash to the same place.
	 */
E 19
	istrcpy(realfld, field);
D 19
	h = hash(realfld);
	for (igp = ignore[h]; igp != 0; igp = igp->i_link)
		if (strcmp(igp->i_field, realfld) == 0)
			return(1);
	return(0);
E 19
I 19
D 25

E 25
	if (nretained > 0)
		return (!member(realfld, retain));
	else
		return (member(realfld, ignore));
}

member(realfield, table)
	register char *realfield;
D 25
	register struct ignore **table;
E 25
I 25
	struct ignore **table;
E 25
{
	register struct ignore *igp;

	for (igp = table[hash(realfield)]; igp != 0; igp = igp->i_link)
D 25
		if (equal(igp->i_field, realfield))
E 25
I 25
		if (*igp->i_field == *realfield &&
		    equal(igp->i_field, realfield))
E 25
			return (1);
D 25

E 25
	return (0);
E 19
}
E 13
E 12
E 1
