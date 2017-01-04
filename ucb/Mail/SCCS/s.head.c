h18429
s 00011/00005/00232
d D 5.4 88/02/18 17:03:58 bostic 10 9
c written by Kurt Shoens; added Berkeley specific header
e
s 00084/00161/00153
d D 5.3 87/05/18 12:29:00 edward 9 8
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00313
d D 5.2 85/06/21 17:10:43 mckusick 8 7
c botched copyright
e
s 00007/00001/00307
d D 5.1 85/06/06 10:34:22 dist 7 6
c Add copyright
e
s 00008/00001/00300
d D 2.4 83/08/28 15:43:08 leres 6 5
c Added Jim Bloom's hack; now can reply to addresses like "jim bloom"@arpa.
e
s 00003/00003/00298
d D 2.3 83/08/11 22:16:17 sam 5 4
c standardize sccs keyword lines
e
s 00002/00046/00299
d D 2.2 83/03/03 12:24:41 leres 4 3
c Changed uses of isname() to strncmp(), removed isname()
e
s 00000/00000/00345
d D 2.1 81/07/01 11:09:02 kurt 3 2
c Release to Heidi Stettner
e
s 00022/00000/00323
d D 1.2 80/10/17 00:29:50 kas 2 1
c added procedure icisname which is really strncmp ignoring
c case differences
e
s 00323/00000/00000
d D 1.1 80/10/08 09:50:09 kas 1 0
c date and time created 80/10/08 09:50:09 by kas
e
u
U
f b 
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

E 7
I 1
D 5
#
E 5
I 5
D 10
#ifndef lint
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
static char *sccsid = "%W% (Berkeley) %G%";
E 8
D 7
#endif
E 7
I 7
#endif not lint
E 10
I 10
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 10
E 7
E 5

#include "rcv.h"

/*
 * Mail -- a mail program
 *
 * Routines for processing and detecting headlines.
 */
D 5

static char *SccsId = "%W% %G%";
E 5

/*
 * See if the passed line buffer is a mail header.
 * Return true if yes.  Note the extreme pains to
 * accomodate all funny formats.
 */
D 9

E 9
ishead(linebuf)
	char linebuf[];
{
	register char *cp;
	struct headline hl;
	char parbuf[BUFSIZ];

	cp = linebuf;
D 4
	if (!isname("From ", cp, 5))
E 4
I 4
D 9
	if (strncmp("From ", cp, 5) != 0)
E 4
		return(0);
	parse(cp, &hl, parbuf);
E 9
I 9
	if (*cp++ != 'F' || *cp++ != 'r' || *cp++ != 'o' || *cp++ != 'm' ||
	    *cp++ != ' ')
		return (0);
	parse(linebuf, &hl, parbuf);
E 9
	if (hl.l_from == NOSTR || hl.l_date == NOSTR) {
		fail(linebuf, "No from or date field");
D 9
		return(0);
E 9
I 9
		return (0);
E 9
	}
	if (!isdate(hl.l_date)) {
		fail(linebuf, "Date field not legal date");
D 9
		return(0);
E 9
I 9
		return (0);
E 9
	}
D 9
	
E 9
	/*
	 * I guess we got it!
	 */
D 9

	return(1);
E 9
I 9
	return (1);
E 9
}

I 9
/*ARGSUSED*/
E 9
fail(linebuf, reason)
	char linebuf[], reason[];
{

D 9
	if (1 /*value("debug") == NOSTR*/)
E 9
I 9
	/*
	if (value("debug") == NOSTR)
E 9
		return;
	fprintf(stderr, "\"%s\"\nnot a header because %s\n", linebuf, reason);
I 9
	*/
E 9
}

/*
 * Split a headline into its useful components.
 * Copy the line into dynamic string space, then set
 * pointers into the copied line in the passed headline
 * structure.  Actually, it scans.
 */
D 9

E 9
parse(line, hl, pbuf)
	char line[], pbuf[];
D 9
	struct headline *hl;
E 9
I 9
	register struct headline *hl;
E 9
{
D 9
	register char *cp, *dp;
E 9
I 9
	register char *cp;
E 9
	char *sp;
	char word[LINESIZE];

	hl->l_from = NOSTR;
	hl->l_tty = NOSTR;
	hl->l_date = NOSTR;
	cp = line;
	sp = pbuf;
D 9

E 9
	/*
D 9
	 * Skip the first "word" of the line, which should be "From"
	 * anyway.
E 9
I 9
	 * Skip over "From" first.
E 9
	 */
D 9

E 9
	cp = nextword(cp, word);
D 9
	dp = nextword(cp, word);
	if (!equal(word, ""))
E 9
I 9
	cp = nextword(cp, word);
	if (*word)
E 9
		hl->l_from = copyin(word, &sp);
D 4
	if (isname(dp, "tty", 3)) {
E 4
I 4
D 9
	if (strncmp(dp, "tty", 3) == 0) {
E 4
		cp = nextword(dp, word);
E 9
I 9
	if (cp != NOSTR && cp[0] == 't' && cp[1] == 't' && cp[2] == 'y') {
		cp = nextword(cp, word);
E 9
		hl->l_tty = copyin(word, &sp);
D 9
		if (cp != NOSTR)
			hl->l_date = copyin(cp, &sp);
E 9
	}
D 9
	else
		if (dp != NOSTR)
			hl->l_date = copyin(dp, &sp);
E 9
I 9
	if (cp != NOSTR)
		hl->l_date = copyin(cp, &sp);
E 9
}

/*
 * Copy the string on the left into the string on the right
 * and bump the right (reference) string pointer by the length.
 * Thus, dynamically allocate space in the right string, copying
 * the left string into it.
 */
D 9

E 9
char *
copyin(src, space)
D 9
	char src[];
E 9
I 9
	register char *src;
E 9
	char **space;
{
D 9
	register char *cp, *top;
	register int s;
E 9
I 9
	register char *cp;
	char *top;
E 9

D 9
	s = strlen(src);
	cp = *space;
	top = cp;
	strcpy(cp, src);
	cp += s + 1;
E 9
I 9
	top = cp = *space;
	while (*cp++ = *src++)
		;
E 9
	*space = cp;
D 9
	return(top);
E 9
I 9
	return (top);
E 9
D 4
}

/*
 * See if the two passed strings agree in the first n characters.
 * Return true if they do, gnu.
 */

isname(as1, as2, acount)
	char *as1, *as2;
{
	register char *s1, *s2;
	register count;

	s1 = as1;
	s2 = as2;
	count = acount;
	if (count > 0)
		do
			if (*s1++ != *s2++)
				return(0);
		while (--count);
	return(1);
}

/*
I 2
 * See if the two passed strings agree in the first n characters.
 * Return true if they do, ignoring case.
 */

icisname(as1, as2, acount)
	char *as1, *as2;
{
	register char *s1, *s2;
	register count;

	s1 = as1;
	s2 = as2;
	count = acount;
	if (count > 0)
		do
			if (raise(*s1++) != raise(*s2++))
				return(0);
		while (--count);
	return(1);
E 4
}

/*
E 2
 * Test to see if the passed string is a ctime(3) generated
 * date string as documented in the manual.  The template
 * below is used as the criterion of correctness.
 * Also, we check for a possible trailing time zone using
 * the auxtype template.
 */

#define	L	1		/* A lower case char */
#define	S	2		/* A space */
#define	D	3		/* A digit */
#define	O	4		/* An optional digit or space */
#define	C	5		/* A colon */
#define	N	6		/* A new line */
#define U	7		/* An upper case char */

D 9
char ctypes[] = {U,L,L,S,U,L,L,S,O,D,S,D,D,C,D,D,C,D,D,S,D,D,D,D,0};
char tmztypes[] = {U,L,L,S,U,L,L,S,O,D,S,D,D,C,D,D,C,D,D,S,U,U,U,S,D,D,D,D,0};
E 9
I 9
char ctypes[] = { U,L,L,S,U,L,L,S,O,D,S,D,D,C,D,D,C,D,D,S,D,D,D,D,0 };
char tmztypes[] = { U,L,L,S,U,L,L,S,O,D,S,D,D,C,D,D,C,D,D,S,U,U,U,S,D,D,D,D,0 };
E 9

isdate(date)
	char date[];
{
D 9
	register char *cp;
E 9

D 9
	cp = date;
	if (cmatch(cp, ctypes))
		return(1);
	return(cmatch(cp, tmztypes));
E 9
I 9
	if (cmatch(date, ctypes))
		return (1);
	return (cmatch(date, tmztypes));
E 9
}

/*
D 9
 * Match the given string against the given template.
E 9
I 9
 * Match the given string (cp) against the given template (tp).
E 9
 * Return 1 if they match, 0 if they don't
 */

D 9
cmatch(str, temp)
	char str[], temp[];
{
E 9
I 9
cmatch(cp, tp)
E 9
	register char *cp, *tp;
D 9
	register int c;
E 9
I 9
{
E 9

D 9
	cp = str;
	tp = temp;
	while (*cp != '\0' && *tp != 0) {
		c = *cp++;
E 9
I 9
	while (*cp && *tp)
E 9
		switch (*tp++) {
		case L:
D 9
			if (c < 'a' || c > 'z')
				return(0);
E 9
I 9
			if (!islower(*cp++))
				return 0;
E 9
			break;
D 9

E 9
		case U:
D 9
			if (c < 'A' || c > 'Z')
				return(0);
E 9
I 9
			if (!isupper(*cp++))
				return 0;
E 9
			break;
D 9

E 9
		case S:
D 9
			if (c != ' ')
				return(0);
E 9
I 9
			if (*cp++ != ' ')
				return 0;
E 9
			break;
D 9

E 9
		case D:
D 9
			if (!isdigit(c))
				return(0);
E 9
I 9
			if (!isdigit(*cp++))
				return 0;
E 9
			break;
D 9

E 9
		case O:
D 9
			if (c != ' ' && !isdigit(c))
				return(0);
E 9
I 9
			if (*cp != ' ' && !isdigit(*cp))
				return 0;
			cp++;
E 9
			break;
D 9

E 9
		case C:
D 9
			if (c != ':')
				return(0);
E 9
I 9
			if (*cp++ != ':')
				return 0;
E 9
			break;
D 9

E 9
		case N:
D 9
			if (c != '\n')
				return(0);
E 9
I 9
			if (*cp++ != '\n')
				return 0;
E 9
			break;
		}
D 9
	}
	if (*cp != '\0' || *tp != 0)
		return(0);
	return(1);
E 9
I 9
	if (*cp || *tp)
		return 0;
	return (1);
E 9
}

/*
 * Collect a liberal (space, tab delimited) word into the word buffer
 * passed.  Also, return a pointer to the next word following that,
 * or NOSTR if none follow.
 */
D 9

E 9
char *
nextword(wp, wbuf)
D 9
	char wp[], wbuf[];
E 9
I 9
	register char *wp, *wbuf;
E 9
{
D 9
	register char *cp, *cp2;
E 9
I 9
	register c;
E 9

D 9
	if ((cp = wp) == NOSTR) {
		copy("", wbuf);
		return(NOSTR);
E 9
I 9
	if (wp == NOSTR) {
		*wbuf = 0;
		return (NOSTR);
E 9
	}
D 9
	cp2 = wbuf;
	while (!any(*cp, " \t") && *cp != '\0')
D 6
		*cp2++ = *cp++;
E 6
I 6
		if (*cp == '"') {
 			*cp2++ = *cp++;
 			while (*cp != '\0' && *cp != '"')
 				*cp2++ = *cp++;
 			if (*cp == '"')
 				*cp2++ = *cp++;
 		} else
 			*cp2++ = *cp++;
E 6
	*cp2 = '\0';
	while (any(*cp, " \t"))
		cp++;
	if (*cp == '\0')
		return(NOSTR);
	return(cp);
E 9
I 9
	while ((c = *wp++) && c != ' ' && c != '\t') {
		*wbuf++ = c;
		if (c == '"') {
 			while ((c = *wp++) && c != '"')
 				*wbuf++ = c;
 			if (c == '"')
 				*wbuf++ = c;
			else
				wp--;
 		}
	}
	*wbuf = '\0';
	for (; c == ' ' || c == '\t'; c = *wp++)
		;
	if (c == 0)
		return (NOSTR);
	return (wp - 1);
E 9
}

/*
D 9
 * Test to see if the character is an ascii alphabetic.
E 9
I 9
 * Is c contained in s?
E 9
 */
D 9

isalpha(c)
{
	register int ch;

	ch = raise(c);
	return(ch >= 'A' && ch <= 'Z');
}

/*
 * Test to see if the character is an ascii digit.
 */

isdigit(c)
{
	return(c >= '0' && c <= '9');
}

/*
 * Copy str1 to str2, return pointer to null in str2.
 */

char *
copy(str1, str2)
	char *str1, *str2;
{
	register char *s1, *s2;

	s1 = str1;
	s2 = str2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = 0;
	return(s2);
}

/*
 * Is ch any of the characters in str?
 */

any(ch, str)
	char *str;
{
	register char *f;
E 9
I 9
any(c, s)
E 9
	register c;
D 9

	f = str;
	c = ch;
	while (*f)
		if (c == *f++)
			return(1);
	return(0);
}

/*
 * Convert lower case letters to upper case.
 */

raise(c)
	register int c;
E 9
I 9
	register char *s;
E 9
{
D 9
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return(c);
E 9
I 9

	while (*s)
		if (*s++ == c)
			return 1;
	return 0;
E 9
}
E 1
