h26003
s 00011/00005/00689
d D 5.6 88/02/18 17:04:03 bostic 15 14
c written by Kurt Shoens; added Berkeley specific header
e
s 00001/00001/00693
d D 5.5 87/05/18 12:28:06 edward 14 13
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00008/00001/00686
d D 5.4 85/11/02 20:29:38 serge 13 12
c check for overflow in getrawlist()
e
s 00031/00016/00656
d D 5.3 85/09/23 17:50:41 serge 12 10
c made "-" and "+" skip over deleted messages (from guy@sun)
c "type user" works now (does a substring match instead of literal comparison)
e
s 00030/00015/00657
d R 5.3 85/09/15 16:51:24 serge 11 10
c made "-" and "+" skip over deleted messages (from guy@sun)
c "type user" works now (does a substring match instead of literal comparison)
e
s 00001/00001/00671
d D 5.2 85/06/21 17:11:42 mckusick 10 9
c botched copyright
e
s 00007/00001/00665
d D 5.1 85/06/06 10:36:26 dist 9 8
c Add copyright
e
s 00003/00003/00663
d D 2.3 83/08/11 22:17:05 sam 8 7
c standardize sccs keyword lines
e
s 00002/00001/00664
d D 2.2 83/01/22 14:43:47 leres 7 6
c Fixed bug in marking a range; modified markall() to only mark messages
c that aren't deleted and match the passed flag.
e
s 00000/00000/00665
d D 2.1 81/07/01 11:09:29 kurt 6 5
c Release to Heidi Stettner
e
s 00001/00001/00664
d D 1.5 81/02/06 09:38:24 kas 5 4
c nameof now takes 2 args
e
s 00095/00003/00570
d D 1.4 81/01/23 17:06:33 kas 4 3
c added :{r,o,u,n,d} modifiers for read, old, unread, new, and deleted
c to message list syntax
e
s 00005/00002/00568
d D 1.3 80/10/10 13:45:12 kas 3 2
c Fixed imagined bug in subject pattern match about
c restarting the character search shifted over by 1 character.
e
s 00051/00003/00519
d D 1.2 80/10/09 13:37:40 kas 2 1
c added /pattern to search for pattern in subjects
e
s 00522/00000/00000
d D 1.1 80/10/08 09:50:32 kas 1 0
c date and time created 80/10/08 09:50:32 by kas
e
u
U
f b 
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
 */

E 9
I 1
D 8
#
E 8
I 8
D 15
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
E 15
I 15
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 15
E 9
E 8

#include "rcv.h"
#include <ctype.h>

/*
 * Mail -- a mail program
 *
 * Message list handling.
 */
D 8

static char *SccsId = "%W% %G%";
E 8

/*
 * Convert the user string of message numbers and
 * store the numbers into vector.
 *
 * Returns the count of messages picked up or -1 on error.
 */

getmsglist(buf, vector, flags)
	char *buf;
	int *vector;
{
	register int *ip;
	register struct message *mp;

	if (markall(buf, flags) < 0)
		return(-1);
	ip = vector;
	for (mp = &message[0]; mp < &message[msgCount]; mp++)
		if (mp->m_flag & MMARK)
			*ip++ = mp - &message[0] + 1;
	*ip = NULL;
	return(ip - vector);
}

/*
 * Mark all messages that the user wanted from the command
 * line in the message structure.  Return 0 on success, -1
 * on error.
 */

I 4
/*
 * Bit values for colon modifiers.
 */

#define	CMNEW		01		/* New messages */
#define	CMOLD		02		/* Old messages */
#define	CMUNREAD	04		/* Unread messages */
#define	CMDELETED	010		/* Deleted messages */
#define	CMREAD		020		/* Read messages */

/*
 * The following table describes the letters which can follow
 * the colon and gives the corresponding modifier bit.
 */

struct coltab {
	char	co_char;		/* What to find past : */
	int	co_bit;			/* Associated modifier bit */
	int	co_mask;		/* m_status bits to mask */
	int	co_equal;		/* ... must equal this */
} coltab[] = {
	'n',		CMNEW,		MNEW,		MNEW,
	'o',		CMOLD,		MNEW,		0,
	'u',		CMUNREAD,	MREAD,		0,
	'd',		CMDELETED,	MDELETED,	MDELETED,
	'r',		CMREAD,		MREAD,		MREAD,
	0,		0,		0,		0
};

static	int	lastcolmod;

E 4
markall(buf, f)
	char buf[];
{
	register char **np;
	register int i;
I 4
	register struct message *mp;
E 4
	char *namelist[NMLSIZE], *bufp;
D 4
	int tok, beg, mc, star, other, valdot;
E 4
I 4
	int tok, beg, mc, star, other, valdot, colmod, colresult;
E 4

	valdot = dot - &message[0] + 1;
I 4
	colmod = 0;
E 4
	for (i = 1; i <= msgCount; i++)
		unmark(i);
	bufp = buf;
	mc = 0;
	np = &namelist[0];
	scaninit();
	tok = scan(&bufp);
	star = 0;
	other = 0;
	beg = 0;
	while (tok != TEOL) {
		switch (tok) {
		case TNUMBER:
number:
			if (star) {
				printf("No numbers mixed with *\n");
				return(-1);
			}
			mc++;
			other++;
			if (beg != 0) {
				if (check(lexnumber, f))
					return(-1);
				for (i = beg; i <= lexnumber; i++)
D 7
					mark(i);
E 7
I 7
					if ((message[i - 1].m_flag & MDELETED) == f)
						mark(i);
E 7
				beg = 0;
				break;
			}
			beg = lexnumber;
			if (check(beg, f))
				return(-1);
			tok = scan(&bufp);
			regret(tok);
			if (tok != TDASH) {
				mark(beg);
				beg = 0;
			}
			break;

		case TPLUS:
			if (beg != 0) {
				printf("Non-numeric second argument\n");
				return(-1);
			}
D 12
			if (valdot < msgCount)
				mark(valdot+1);
			else {
				printf("Referencing beyond EOF\n");
				return(-1);
			}
E 12
I 12
			i = valdot;
			do {
				i++;
				if (i > msgCount) {
					printf("Referencing beyond EOF\n");
					return(-1);
				}
			} while ((message[i - 1].m_flag & MDELETED) != f);
			mark(i);
E 12
			break;

		case TDASH:
			if (beg == 0) {
D 12
				if (valdot > 1)
					mark(valdot-1);
				else {
					printf("Referencing before 1\n");
					return(-1);
				}
E 12
I 12
				i = valdot;
				do {
					i--;
					if (i <= 0) {
						printf("Referencing before 1\n");
						return(-1);
					}
				} while ((message[i - 1].m_flag & MDELETED) != f);
				mark(i);
E 12
			}
			break;

		case TSTRING:
			if (beg != 0) {
				printf("Non-numeric second argument\n");
				return(-1);
			}
			other++;
D 4
			*np++ = savestr(lexstring);
E 4
I 4
			if (lexstring[0] == ':') {
				colresult = evalcol(lexstring[1]);
				if (colresult == 0) {
					printf("Unknown colon modifier \"%s\"\n",
					    lexstring);
					return(-1);
				}
				colmod |= colresult;
			}
			else
				*np++ = savestr(lexstring);
E 4
			break;

		case TDOLLAR:
		case TUP:
		case TDOT:
			lexnumber = metamess(lexstring[0], f);
			if (lexnumber == -1)
				return(-1);
			goto number;

		case TSTAR:
			if (other) {
				printf("Can't mix \"*\" with anything\n");
				return(-1);
			}
			star++;
			break;
		}
		tok = scan(&bufp);
	}
I 4
	lastcolmod = colmod;
E 4
	*np = NOSTR;
	mc = 0;
	if (star) {
		for (i = 0; i < msgCount; i++)
			if ((message[i].m_flag & MDELETED) == f) {
				mark(i+1);
				mc++;
			}
		if (mc == 0) {
			printf("No applicable messages.\n");
			return(-1);
		}
		return(0);
	}

	/*
	 * If no numbers were given, mark all of the messages,
	 * so that we can unmark any whose sender was not selected
	 * if any user names were given.
	 */

D 4
	if (np > namelist && mc == 0)
E 4
I 4
	if ((np > namelist || colmod != 0) && mc == 0)
E 4
		for (i = 1; i <= msgCount; i++)
D 12
			if ((message[i-1].m_flag & (MSAVED|MDELETED)) == f)
E 12
I 12
			if ((message[i-1].m_flag & MDELETED) == f)
E 12
				mark(i);

	/*
	 * If any names were given, go through and eliminate any
	 * messages whose senders were not requested.
	 */

	if (np > namelist) {
		for (i = 1; i <= msgCount; i++) {
			for (mc = 0, np = &namelist[0]; *np != NOSTR; np++)
D 2
				if (sender(*np, i)) {
					mc++;
					break;
E 2
I 2
				if (**np == '/') {
					if (matchsubj(*np, i)) {
						mc++;
						break;
					}
E 2
				}
I 2
				else {
					if (sender(*np, i)) {
						mc++;
						break;
					}
				}
E 2
			if (mc == 0)
				unmark(i);
		}

		/*
		 * Make sure we got some decent messages.
		 */

		mc = 0;
		for (i = 1; i <= msgCount; i++)
			if (message[i-1].m_flag & MMARK) {
				mc++;
				break;
			}
		if (mc == 0) {
			printf("No applicable messages from {%s",
				namelist[0]);
			for (np = &namelist[1]; *np != NOSTR; np++)
				printf(", %s", *np);
			printf("}\n");
			return(-1);
		}
	}
I 4

	/*
	 * If any colon modifiers were given, go through and
	 * unmark any messages which do not satisfy the modifiers.
	 */

	if (colmod != 0) {
		for (i = 1; i <= msgCount; i++) {
			register struct coltab *colp;

			mp = &message[i - 1];
			for (colp = &coltab[0]; colp->co_char; colp++)
				if (colp->co_bit & colmod)
					if ((mp->m_flag & colp->co_mask)
					    != colp->co_equal)
						unmark(i);
			
		}
		for (mp = &message[0]; mp < &message[msgCount]; mp++)
			if (mp->m_flag & MMARK)
				break;
		if (mp >= &message[msgCount]) {
			register struct coltab *colp;

			printf("No messages satisfy");
			for (colp = &coltab[0]; colp->co_char; colp++)
				if (colp->co_bit & colmod)
					printf(" :%c", colp->co_char);
			printf("\n");
			return(-1);
		}
	}
	return(0);
}

/*
 * Turn the character after a colon modifier into a bit
 * value.
 */
evalcol(col)
{
	register struct coltab *colp;

	if (col == 0)
		return(lastcolmod);
	for (colp = &coltab[0]; colp->co_char; colp++)
		if (colp->co_char == col)
			return(colp->co_bit);
E 4
	return(0);
}

/*
 * Check the passed message number for legality and proper flags.
 */

check(mesg, f)
{
	register struct message *mp;

	if (mesg < 1 || mesg > msgCount) {
		printf("%d: Invalid message number\n", mesg);
		return(-1);
	}
	mp = &message[mesg-1];
	if ((mp->m_flag & MDELETED) != f) {
		printf("%d: Inappropriate message\n", mesg);
		return(-1);
	}
	return(0);
}

/*
 * Scan out the list of string arguments, shell style
 * for a RAWLIST.
 */

D 13
getrawlist(line, argv)
E 13
I 13
getrawlist(line, argv, argc)
E 13
	char line[];
	char **argv;
I 13
	int  argc;
E 13
{
	register char **ap, *cp, *cp2;
	char linebuf[BUFSIZ], quotec;
I 13
	register char **last;
E 13

	ap = argv;
	cp = line;
I 13
	last = argv + argc - 1;
E 13
	while (*cp != '\0') {
		while (any(*cp, " \t"))
			cp++;
		cp2 = linebuf;
		quotec = 0;
		if (any(*cp, "'\""))
			quotec = *cp++;
		if (quotec == 0)
			while (*cp != '\0' && !any(*cp, " \t"))
				*cp2++ = *cp++;
		else {
			while (*cp != '\0' && *cp != quotec)
				*cp2++ = *cp++;
			if (*cp != '\0')
				cp++;
		}
		*cp2 = '\0';
		if (cp2 == linebuf)
			break;
I 13
		if (ap >= last) {
			printf("Too many elements in the list; excess discarded\n");
			break;
		}
E 13
		*ap++ = savestr(linebuf);
	}
	*ap = NOSTR;
	return(ap-argv);
}

/*
 * scan out a single lexical item and return its token number,
 * updating the string pointer passed **p.  Also, store the value
 * of the number or string scanned in lexnumber or lexstring as
 * appropriate.  In any event, store the scanned `thing' in lexstring.
 */

struct lex {
	char	l_char;
	char	l_token;
} singles[] = {
	'$',	TDOLLAR,
	'.',	TDOT,
	'^',	TUP,
	'*',	TSTAR,
	'-',	TDASH,
	'+',	TPLUS,
	'(',	TOPEN,
	')',	TCLOSE,
	0,	0
};

scan(sp)
	char **sp;
{
	register char *cp, *cp2;
	register int c;
	register struct lex *lp;
	int quotec;

	if (regretp >= 0) {
D 14
		copy(stringstack[regretp], lexstring);
E 14
I 14
		strcpy(lexstring, stringstack[regretp]);
E 14
		lexnumber = numberstack[regretp];
		return(regretstack[regretp--]);
	}
	cp = *sp;
	cp2 = lexstring;
	c = *cp++;

	/*
	 * strip away leading white space.
	 */

	while (any(c, " \t"))
		c = *cp++;

	/*
	 * If no characters remain, we are at end of line,
	 * so report that.
	 */

	if (c == '\0') {
		*sp = --cp;
		return(TEOL);
	}

	/*
	 * If the leading character is a digit, scan
	 * the number and convert it on the fly.
	 * Return TNUMBER when done.
	 */

	if (isdigit(c)) {
		lexnumber = 0;
		while (isdigit(c)) {
			lexnumber = lexnumber*10 + c - '0';
			*cp2++ = c;
			c = *cp++;
		}
		*cp2 = '\0';
		*sp = --cp;
		return(TNUMBER);
	}

	/*
	 * Check for single character tokens; return such
	 * if found.
	 */

	for (lp = &singles[0]; lp->l_char != 0; lp++)
		if (c == lp->l_char) {
			lexstring[0] = c;
			lexstring[1] = '\0';
			*sp = cp;
			return(lp->l_token);
		}

	/*
	 * We've got a string!  Copy all the characters
	 * of the string into lexstring, until we see
	 * a null, space, or tab.
	 * If the lead character is a " or ', save it
	 * and scan until you get another.
	 */

	quotec = 0;
	if (any(c, "'\"")) {
		quotec = c;
		c = *cp++;
	}
	while (c != '\0') {
		if (c == quotec)
			break;
		if (quotec == 0 && any(c, " \t"))
			break;
		if (cp2 - lexstring < STRINGLEN-1)
			*cp2++ = c;
		c = *cp++;
	}
	if (quotec && c == 0)
		fprintf(stderr, "Missing %c\n", quotec);
	*sp = --cp;
	*cp2 = '\0';
	return(TSTRING);
}

/*
 * Unscan the named token by pushing it onto the regret stack.
 */

regret(token)
{
	if (++regretp >= REGDEP)
		panic("Too many regrets");
	regretstack[regretp] = token;
	lexstring[STRINGLEN-1] = '\0';
	stringstack[regretp] = savestr(lexstring);
	numberstack[regretp] = lexnumber;
}

/*
 * Reset all the scanner global variables.
 */

scaninit()
{
	regretp = -1;
}

/*
 * Find the first message whose flags & m == f  and return
 * its message number.
 */

first(f, m)
{
	register int mesg;
	register struct message *mp;

	mesg = dot - &message[0] + 1;
	f &= MDELETED;
	m &= MDELETED;
	for (mp = dot; mp < &message[msgCount]; mp++) {
		if ((mp->m_flag & m) == f)
			return(mesg);
		mesg++;
	}
	mesg = dot - &message[0];
	for (mp = dot-1; mp >= &message[0]; mp--) {
		if ((mp->m_flag & m) == f)
			return(mesg);
		mesg--;
	}
	return(NULL);
}

/*
 * See if the passed name sent the passed message number.  Return true
 * if so.
 */

sender(str, mesg)
	char *str;
{
	register struct message *mp;
D 12
	register char *cp;
E 12
I 12
	register char *cp, *cp2, *backup;
E 12

	mp = &message[mesg-1];
D 5
	cp = nameof(mp);
E 5
I 5
D 12
	cp = nameof(mp, 0);
E 5
	return(icequal(cp, str));
E 12
I 12
	backup = cp2 = nameof(mp, 0);
	cp = str;
	while (*cp2) {
		if (*cp == 0)
			return(1);
		if (raise(*cp++) != raise(*cp2++)) {
			cp2 = ++backup;
			cp = str;
		}
	}
	return(*cp == 0);
E 12
I 2
}

/*
 * See if the given string matches inside the subject field of the
 * given message.  For the purpose of the scan, we ignore case differences.
 * If it does, return true.  The string search argument is assumed to
 * have the form "/search-string."  If it is of the form "/," we use the
 * previous search string.
 */

char lastscan[128];

matchsubj(str, mesg)
	char *str;
{
	register struct message *mp;
D 3
	register char *cp, *cp2;
E 3
I 3
	register char *cp, *cp2, *backup;
E 3

	str++;
	if (strlen(str) == 0)
		str = lastscan;
	else
		strcpy(lastscan, str);
	mp = &message[mesg-1];
	
	/*
	 * Now look, ignoring case, for the word in the string.
	 */

	cp = str;
	cp2 = hfield("subject", mp);
	if (cp2 == NOSTR)
		return(0);
I 3
	backup = cp2;
E 3
	while (*cp2) {
		if (*cp == 0)
			return(1);
D 3
		if (raise(*cp++) != raise(*cp2++))
E 3
I 3
		if (raise(*cp++) != raise(*cp2++)) {
			cp2 = ++backup;
E 3
			cp = str;
I 3
		}
E 3
	}
	return(*cp == 0);
E 2
}

/*
 * Mark the named message by setting its mark bit.
 */

mark(mesg)
{
	register int i;

	i = mesg;
	if (i < 1 || i > msgCount)
		panic("Bad message number to mark");
	message[i-1].m_flag |= MMARK;
}

/*
 * Unmark the named message.
 */

unmark(mesg)
{
	register int i;

	i = mesg;
	if (i < 1 || i > msgCount)
		panic("Bad message number to unmark");
	message[i-1].m_flag &= ~MMARK;
}

/*
 * Return the message number corresponding to the passed meta character.
 */

metamess(meta, f)
{
	register int c, m;
	register struct message *mp;

	c = meta;
	switch (c) {
	case '^':
		/*
		 * First 'good' message left.
		 */
		for (mp = &message[0]; mp < &message[msgCount]; mp++)
			if ((mp->m_flag & MDELETED) == f)
				return(mp - &message[0] + 1);
		printf("No applicable messages\n");
		return(-1);

	case '$':
		/*
		 * Last 'good message left.
		 */
		for (mp = &message[msgCount-1]; mp >= &message[0]; mp--)
			if ((mp->m_flag & MDELETED) == f)
				return(mp - &message[0] + 1);
		printf("No applicable messages\n");
		return(-1);

	case '.':
		/* 
		 * Current message.
		 */
		m = dot - &message[0] + 1;
		if ((dot->m_flag & MDELETED) != f) {
			printf("%d: Inappropriate message\n", m);
			return(-1);
		}
		return(m);

	default:
		printf("Unknown metachar (%c)\n", c);
		return(-1);
	}
}
E 1
