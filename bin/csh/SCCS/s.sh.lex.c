h34229
s 00001/00001/01336
d D 5.6 88/05/19 15:38:54 bostic 15 14
c install C version of _doprnt
e
s 00002/00002/01335
d D 5.5 88/01/15 03:33:29 edward 14 13
c fixed labuf overflow (caused by, for example, very long variable expansions)
e
s 00002/00001/01335
d D 5.4 86/03/29 07:37:41 lepreau 13 12
c Minor speedups & cleanups:
c replace letter() et al with ctype-like cmap macros and expand cmap to short
c for new LET and DIG bits; use bzero in private calloc; make btell a macro.
e
s 00003/00003/01333
d D 5.3 85/06/06 13:11:27 edward 12 11
c cleaning up after bozos
e
s 00002/00001/01334
d D 5.2 85/06/06 12:53:50 edward 11 10
c prlex(): don't print trailing space
e
s 00008/00002/01327
d D 5.1 85/06/04 11:03:18 dist 10 9
c Add copyright
e
s 00001/00001/01328
d D 4.9 85/03/19 18:18:26 mckusick 9 8
c check for reference through null pointer
e
s 00012/00004/01317
d D 4.8 85/01/30 12:12:52 edward 8 7
c turn off NBIO when read gets EWOULDBLOCK
e
s 00168/00173/01153
d D 4.7 84/12/13 14:42:24 edward 7 6
c performance
e
s 00003/00004/01323
d D 4.6 84/11/21 11:26:27 ralph 6 5
c turn \newline into space as per documentation.
e
s 00001/00001/01326
d D 4.5 84/09/02 16:58:21 sam 5 4
c argh -- missing #
e
s 00022/00023/01305
d D 4.4 84/09/02 16:51:07 sam 4 3
c I can't stand it, if layer's gonna put this crap in the source code, 
c the least he can do is reformat it to conform to the rest of the code
e
s 00033/00001/01295
d D 4.3 83/11/02 14:53:42 layer 3 2
c mods for filename completion (ifdef'd in with FILEC)
e
s 00001/00001/01295
d D 4.2 83/02/09 14:17:44 sam 2 1
c cleanups from sun
e
s 01296/00000/00000
d D 4.1 80/10/09 12:41:16 bill 1 0
c date and time created 80/10/09 12:41:16 by bill
e
u
U
t
T
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
E 12
I 12
 * All rights reserved.  The Berkeley Software License Agreement
E 12
 * specifies the terms and conditions for redistribution.
 */

E 10
I 4
#ifndef lint
E 4
I 1
D 7
static	char *sccsid = "%Z%%M% %I% %G%";
E 7
I 7
D 10
static	char *sccsid = "%W% (Berkeley) %G%";
E 7
I 4
D 5
endif
E 5
I 5
#endif
E 10
I 10
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12
I 12
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 12
E 10
E 5
E 4

#include "sh.h"
I 7
D 13
#include "sh.char.h"
E 13
I 8
#include <sgtty.h>
E 8
E 7

/*
 * C shell
 */

/*
 * These lexical routines read input and form lists of words.
 * There is some involved processing here, because of the complications
 * of input buffering, and especially because of history substitution.
 */

char	*word();

/*
 * Peekc is a peek characer for getC, peekread for readc.
 * There is a subtlety here in many places... history routines
 * will read ahead and then insert stuff into the input stream.
 * If they push back a character then they must push it behind
 * the text substituted by the history substitution.  On the other
 * hand in several places we need 2 peek characters.  To make this
 * all work, the history routines read with getC, and make use both
 * of ungetC and unreadc.  The key observation is that the state
 * of getC at the call of a history reference is such that calls
 * to getC from the history routines will always yield calls of
 * readc, unless this peeking is involved.  That is to say that during
 * getexcl the variables lap, exclp, and exclnxt are all zero.
 *
 * Getdol invokes history substitution, hence the extra peek, peekd,
 * which it can ungetD to be before history substitutions.
 */
char	peekc, peekd;
char	peekread;

char	*exclp;			/* (Tail of) current word from ! subst */
struct	wordent *exclnxt;	/* The rest of the ! subst words */
int	exclc;			/* Count of remainig words in ! subst */
char	*alvecp;		/* "Globp" for alias resubstitution */

/*
 * Lex returns to its caller not only a wordlist (as a "var" parameter)
 * but also whether a history substitution occurred.  This is used in
 * the main (process) routine to determine whether to echo, and also
 * when called by the alias routine to determine whether to keep the
 * argument list.
 */
bool	hadhist;

I 7
char getCtmp;
#define getC(f)		((getCtmp = peekc) ? (peekc = 0, getCtmp) : getC1(f))
E 7
#define	ungetC(c)	peekc = c
#define	ungetD(c)	peekd = c

lex(hp)
	register struct wordent *hp;
{
	register struct wordent *wdp;
	int c;

	lineloc = btell();
	hp->next = hp->prev = hp;
	hp->word = "";
	alvecp = 0, hadhist = 0;
	do
		c = readc(0);
	while (c == ' ' || c == '\t');
	if (c == HISTSUB && intty)
		/* ^lef^rit	from tty is short !:s^lef^rit */
		getexcl(c);
	else
		unreadc(c);
	wdp = hp;
	/*
	 * The following loop is written so that the links needed
	 * by freelex will be ready and rarin to go even if it is
	 * interrupted.
	 */
	do {
D 7
		register struct wordent *new = (struct wordent *) calloc(1, sizeof *wdp);
E 7
I 7
		register struct wordent *new = (struct wordent *) xalloc(sizeof *wdp);
E 7

I 7
		new->word = 0;
E 7
		new->prev = wdp;
		new->next = hp;
		wdp->next = new;
		wdp = new;
		wdp->word = word();
	} while (wdp->word[0] != '\n');
	hp->prev = wdp;
	return (hadhist);
}

prlex(sp0)
	struct wordent *sp0;
{
	register struct wordent *sp = sp0->next;

	for (;;) {
		printf("%s", sp->word);
		sp = sp->next;
		if (sp == sp0)
			break;
D 11
		printf(" ");
E 11
I 11
		if (sp->word[0] != '\n')
D 15
			putchar(' ');
E 15
I 15
			cshputchar(' ');
E 15
E 11
	}
}

copylex(hp, fp)
	register struct wordent *hp;
D 7
	struct wordent *fp;
E 7
I 7
	register struct wordent *fp;
E 7
{
	register struct wordent *wdp;

	wdp = hp;
	fp = fp->next;
	do {
D 7
		register struct wordent *new = (struct wordent *) calloc(1, sizeof *wdp);
E 7
I 7
		register struct wordent *new = (struct wordent *) xalloc(sizeof *wdp);
E 7

		new->prev = wdp;
		new->next = hp;
		wdp->next = new;
		wdp = new;
		wdp->word = savestr(fp->word);
		fp = fp->next;
	} while (wdp->word[0] != '\n');
	hp->prev = wdp;
}

freelex(vp)
	register struct wordent *vp;
{
	register struct wordent *fp;

	while (vp->next != vp) {
		fp = vp->next;
		vp->next = fp->next;
D 7
		xfree(fp->word);
		xfree((char *)fp);
E 7
I 7
		XFREE(fp->word)
		XFREE((char *)fp)
E 7
	}
	vp->prev = vp;
}

D 7
char	*WORDMETA =	"# '`\"\t;&<>()|\n";

E 7
char *
word()
{
	register char c, c1;
	register char *wp;
	char wbuf[BUFSIZ];
	register bool dolflg;
	register int i;

	wp = wbuf;
	i = BUFSIZ - 4;
loop:
D 7
	c = getC(DOALL);
	switch (c) {
E 7
I 7
	while ((c = getC(DOALL)) == ' ' || c == '\t')
		;
	if (cmap(c, _META|_ESC))
		switch (c) {
		case '&':
		case '|':
		case '<':
		case '>':
			*wp++ = c;
			c1 = getC(DOALL);
			if (c1 == c)
				*wp++ = c1;
			else
				ungetC(c1);
			goto ret;
E 7

D 7
	case ' ':
	case '\t':
		goto loop;

	case '`':
	case '\'':
	case '"':
		*wp++ = c, --i, c1 = c;
		dolflg = c == '"' ? DOALL : DOEXCL;
		for (;;) {
			c = getC(dolflg);
			if (c == c1)
E 7
I 7
		case '#':
			if (intty)
E 7
				break;
D 7
			if (c == '\n') {
				seterrc("Unmatched ", c1);
				ungetC(c);
				goto ret;
			}
			if (c == '\\') {
E 7
I 7
			c = 0;
			do {
				c1 = c;
E 7
				c = getC(0);
D 7
				if (c == HIST)
					c |= QUOTE;
D 6
				else {
					if (c == '\n' && c1 != '`')
						c |= QUOTE;
E 6
I 6
				else if (c == '\n')
					c = ' ';
				else
E 6
					ungetC(c), c = '\\';
D 6
				}
E 6
			}
			if (--i <= 0)
				goto toochars;
			*wp++ = c;
		}
		*wp++ = c, --i;
		goto pack;
E 7
I 7
			} while (c != '\n');
			if (c1 == '\\')
				goto loop;
			/* fall into ... */
E 7

D 7
	case '&':
	case '|':
	case '<':
	case '>':
		*wp++ = c;
		c1 = getC(DOALL);
		if (c1 == c)
			*wp++ = c1;
		else
			ungetC(c1);
		goto ret;

	case '#':
		if (intty)
			break;
		if (wp != wbuf) {
			ungetC(c);
E 7
I 7
		case ';':
		case '(':
		case ')':
		case '\n':
			*wp++ = c;
E 7
			goto ret;
D 7
		}
		c = 0;
		do {
			c1 = c;
			c = getC(0);
		} while (c != '\n');
		if (c1 == '\\')
			goto loop;
		/* fall into ... */
E 7

D 7
	case ';':
	case '(':
	case ')':
	case '\n':
		*wp++ = c;
		goto ret;

casebksl:
	case '\\':
		c = getC(0);
		if (c == '\n') {
			if (onelflg == 1)
				onelflg = 2;
			goto loop;
		}
		if (c != HIST)
			*wp++ = '\\', --i;
		c |= QUOTE;
		break;
	}
	ungetC(c);
pack:
	for (;;) {
		c = getC(DOALL);
		if (c == '\\') {
E 7
I 7
		case '\\':
E 7
			c = getC(0);
			if (c == '\n') {
				if (onelflg == 1)
					onelflg = 2;
D 7
				goto ret;
E 7
I 7
				goto loop;
E 7
			}
			if (c != HIST)
				*wp++ = '\\', --i;
			c |= QUOTE;
		}
D 7
		if (any(c, WORDMETA + intty)) {
			ungetC(c);
			if (any(c, "\"'`"))
				goto loop;
			goto ret;
E 7
I 7
	c1 = 0;
	dolflg = DOALL;
	for (;;) {
		if (c1) {
			if (c == c1) {
				c1 = 0;
				dolflg = DOALL;
			} else if (c == '\\') {
				c = getC(0);
				if (c == HIST)
					c |= QUOTE;
				else {
					if (c == '\n')
						/*
						if (c1 == '`')
							c = ' ';
						else
						*/
							c |= QUOTE;
					ungetC(c);
					c = '\\';
				}
			} else if (c == '\n') {
				seterrc("Unmatched ", c1);
				ungetC(c);
				break;
			}
		} else if (cmap(c, _META|_Q|_Q1|_ESC)) {
			if (c == '\\') {
				c = getC(0);
				if (c == '\n') {
					if (onelflg == 1)
						onelflg = 2;
					break;
				}
				if (c != HIST)
					*wp++ = '\\', --i;
				c |= QUOTE;
			} else if (cmap(c, _Q|_Q1)) {		/* '"` */
				c1 = c;
				dolflg = c == '"' ? DOALL : DOEXCL;
			} else if (c != '#' || !intty) {
				ungetC(c);
				break;
			}
E 7
		}
D 7
		if (--i <= 0)
			goto toochars;
		*wp++ = c;
E 7
I 7
		if (--i > 0) {
			*wp++ = c;
			c = getC(dolflg);
		} else {
			seterr("Word too long");
			wp = &wbuf[1];
			break;
		}
E 7
	}
D 7
toochars:
	seterr("Word too long");
	wp = &wbuf[1];
E 7
ret:
	*wp = 0;
	return (savestr(wbuf));
}

D 7
getC(flag)
E 7
I 7
getC1(flag)
E 7
	register int flag;
{
	register char c;

top:
	if (c = peekc) {
		peekc = 0;
		return (c);
	}
	if (lap) {
D 7
		c = *lap++;
		if (c == 0) {
E 7
I 7
		if ((c = *lap++) == 0)
E 7
			lap = 0;
D 7
			goto top;
E 7
I 7
		else {
			if (cmap(c, _META|_Q|_Q1))
				c |= QUOTE;
			return (c);
E 7
		}
D 7
		if (any(c, WORDMETA + intty))
			c |= QUOTE;
		return (c);
E 7
	}
	if (c = peekd) {
		peekd = 0;
		return (c);
	}
	if (exclp) {
		if (c = *exclp++)
			return (c);
		if (exclnxt && --exclc >= 0) {
			exclnxt = exclnxt->next;
			setexclp(exclnxt->word);
			return (' ');
		}
		exclp = 0;
		exclnxt = 0;
	}
	if (exclnxt) {
		exclnxt = exclnxt->next;
		if (--exclc < 0)
			exclnxt = 0;
		else
			setexclp(exclnxt->word);
		goto top;
	}
	c = readc(0);
	if (c == '$' && (flag & DODOL)) {
		getdol();
		goto top;
	}
	if (c == HIST && (flag & DOEXCL)) {
		getexcl(0);
		goto top;
	}
	return (c);
}

getdol()
{
	register char *np;
	char name[40];
	register int c;
	int sc;
	bool special = 0;

	np = name, *np++ = '$';
	c = sc = getC(DOEXCL);
	if (any(c, "\t \n")) {
		ungetD(c);
		ungetC('$' | QUOTE);
		return;
	}
	if (c == '{')
		*np++ = c, c = getC(DOEXCL);
	if (c == '#' || c == '?')
		special++, *np++ = c, c = getC(DOEXCL);
	*np++ = c;
	switch (c) {
	
	case '<':
	case '$':
		if (special)
			goto vsyn;
		goto ret;

	case '\n':
		ungetD(c);
		np--;
		goto vsyn;

	case '*':
		if (special)
			goto vsyn;
		goto ret;

	default:
		if (digit(c)) {
/*
 * let $?0 pass for now
			if (special)
				goto vsyn;
*/
			while (digit(c = getC(DOEXCL))) {
				if (np < &name[sizeof name / 2])
					*np++ = c;
			}
		} else if (letter(c))
			while (letter(c = getC(DOEXCL))) {
				if (np < &name[sizeof name / 2])
					*np++ = c;
			}
		else
			goto vsyn;
	}
	if (c == '[') {
		*np++ = c;
		do {
			c = getC(DOEXCL);
			if (c == '\n') {
				ungetD(c);
				np--;
				goto vsyn;
			}
			if (np >= &name[sizeof name - 8])
				goto vsyn;
			*np++ = c;
		} while (c != ']');
		c = getC(DOEXCL);
	}
	if (c == ':') {
		*np++ = c, c = getC(DOEXCL);
		if (c == 'g')
			*np++ = c, c = getC(DOEXCL);
		*np++ = c;
		if (!any(c, "htrqxe"))
			goto vsyn;
	} else
		ungetD(c);
	if (sc == '{') {
		c = getC(DOEXCL);
		if (c != '}') {
			ungetC(c);
			goto vsyn;
		}
		*np++ = c;
	}
ret:
	*np = 0;
	addla(name);
	return;

vsyn:
	seterr("Variable syntax");
	goto ret;
}

addla(cp)
	char *cp;
{
	char buf[BUFSIZ];

D 14
	if (lap != 0 && strlen(cp) + strlen(lap) >= sizeof (labuf) - 4) {
		seterr("Expansion buf ovflo");
E 14
I 14
	if (strlen(cp) + (lap ? strlen(lap) : 0) >= sizeof (labuf) - 4) {
		seterr("Expansion buffer overflow");
E 14
		return;
	}
	if (lap)
D 7
		strcpy(buf, lap);
	strcpy(labuf, cp);
E 7
I 7
		(void) strcpy(buf, lap);
	(void) strcpy(labuf, cp);
E 7
	if (lap)
D 7
		strcat(labuf, buf);
E 7
I 7
		(void) strcat(labuf, buf);
E 7
	lap = labuf;
}

char	lhsb[32];
char	slhs[32];
char	rhsb[64];
int	quesarg;

getexcl(sc)
	char sc;
{
	register struct wordent *hp, *ip;
	int left, right, dol;
	register int c;

	if (sc == 0) {
		sc = getC(0);
		if (sc != '{') {
			ungetC(sc);
			sc = 0;
		}
	}
	quesarg = -1;
	lastev = eventno;
	hp = gethent(sc);
	if (hp == 0)
		return;
	hadhist = 1;
	dol = 0;
	if (hp == alhistp)
		for (ip = hp->next->next; ip != alhistt; ip = ip->next)
			dol++;
	else
		for (ip = hp->next->next; ip != hp->prev; ip = ip->next)
			dol++;
	left = 0, right = dol;
	if (sc == HISTSUB) {
		ungetC('s'), unreadc(HISTSUB), c = ':';
		goto subst;
	}
	c = getC(0);
	if (!any(c, ":^$*-%"))
		goto subst;
	left = right = -1;
	if (c == ':') {
		c = getC(0);
		unreadc(c);
		if (letter(c) || c == '&') {
			c = ':';
			left = 0, right = dol;
			goto subst;
		}
	} else
		ungetC(c);
	if (!getsel(&left, &right, dol))
		return;
	c = getC(0);
	if (c == '*')
		ungetC(c), c = '-';
	if (c == '-') {
		if (!getsel(&left, &right, dol))
			return;
		c = getC(0);
	}
subst:
	exclc = right - left + 1;
	while (--left >= 0)
		hp = hp->next;
	if (sc == HISTSUB || c == ':') {
		do {
			hp = getsub(hp);
			c = getC(0);
		} while (c == ':');
	}
	unreadc(c);
	if (sc == '{') {
		c = getC(0);
		if (c != '}')
			seterr("Bad ! form");
	}
	exclnxt = hp;
}

struct wordent *
getsub(en)
	struct wordent *en;
{
	register char *cp;
	int delim;
	register int c;
	int sc;
	bool global = 0;
	char orhsb[sizeof rhsb];

	exclnxt = 0;
	sc = c = getC(0);
	if (c == 'g')
		global++, c = getC(0);
	switch (c) {

	case 'p':
		justpr++;
		goto ret;

	case 'x':
	case 'q':
		global++;
		/* fall into ... */

	case 'h':
	case 'r':
	case 't':
	case 'e':
		break;

	case '&':
		if (slhs[0] == 0) {
			seterr("No prev sub");
			goto ret;
		}
D 7
		strcpy(lhsb, slhs);
E 7
I 7
		(void) strcpy(lhsb, slhs);
E 7
		break;

/*
	case '~':
		if (lhsb[0] == 0)
			goto badlhs;
		break;
*/

	case 's':
		delim = getC(0);
		if (letter(delim) || digit(delim) || any(delim, " \t\n")) {
			unreadc(delim);
bads:
			lhsb[0] = 0;
			seterr("Bad substitute");
			goto ret;
		}
		cp = lhsb;
		for (;;) {
			c = getC(0);
			if (c == '\n') {
				unreadc(c);
D 7
				goto bads;
E 7
I 7
				break;
E 7
			}
			if (c == delim)
				break;
			if (cp > &lhsb[sizeof lhsb - 2])
				goto bads;
			if (c == '\\') {
				c = getC(0);
				if (c != delim && c != '\\')
					*cp++ = '\\';
			}
			*cp++ = c;
		}
		if (cp != lhsb)
			*cp++ = 0;
		else if (lhsb[0] == 0) {
/*badlhs:*/
			seterr("No prev lhs");
			goto ret;
		}
		cp = rhsb;
D 7
		strcpy(orhsb, cp);
E 7
I 7
		(void) strcpy(orhsb, cp);
E 7
		for (;;) {
			c = getC(0);
			if (c == '\n') {
				unreadc(c);
				break;
			}
			if (c == delim)
				break;
/*
			if (c == '~') {
				if (&cp[strlen(orhsb)] > &rhsb[sizeof rhsb - 2])
					goto toorhs;
D 7
				strcpy(cp, orhsb);
E 7
I 7
				(void) strcpy(cp, orhsb);
E 7
				cp = strend(cp);
				continue;
			}
*/
			if (cp > &rhsb[sizeof rhsb - 2]) {
/*toorhs:*/
				seterr("Rhs too long");
				goto ret;
			}
			if (c == '\\') {
				c = getC(0);
				if (c != delim /* && c != '~' */)
					*cp++ = '\\';
			}
			*cp++ = c;
		}
		*cp++ = 0;
		break;

	default:
		if (c == '\n')
			unreadc(c);
		seterrc("Bad ! modifier: ", c);
		goto ret;
	}
D 7
	strcpy(slhs, lhsb);
E 7
I 7
	(void) strcpy(slhs, lhsb);
E 7
	if (exclc)
		en = dosub(sc, en, global);
ret:
	return (en);
}

struct wordent *
dosub(sc, en, global)
	int sc;
	struct wordent *en;
	bool global;
{
	struct wordent lex;
	bool didsub = 0;
	struct wordent *hp = &lex;
	register struct wordent *wdp;
	register int i = exclc;

	wdp = hp;
	while (--i >= 0) {
		register struct wordent *new = (struct wordent *) calloc(1, sizeof *wdp);

		new->prev = wdp;
		new->next = hp;
		wdp->next = new;
		wdp = new;
		en = en->next;
		wdp->word = global || didsub == 0 ?
		    subword(en->word, sc, &didsub) : savestr(en->word);
	}
	if (didsub == 0)
		seterr("Modifier failed");
	hp->prev = wdp;
	return (&enthist(-1000, &lex, 0)->Hlex);
}

char *
subword(cp, type, adid)
	char *cp;
	int type;
	bool *adid;
{
	char wbuf[BUFSIZ];
	register char *wp, *mp, *np;
	register int i;

	switch (type) {

	case 'r':
I 7
	case 'e':
E 7
	case 'h':
	case 't':
	case 'q':
	case 'x':
		wp = domod(cp, type);
		if (wp == 0)
			return (savestr(cp));
		*adid = 1;
		return (wp);

	default:
		wp = wbuf;
		i = BUFSIZ - 4;
		for (mp = cp; *mp; mp++)
			if (matchs(mp, lhsb)) {
				for (np = cp; np < mp;)
					*wp++ = *np++, --i;
				for (np = rhsb; *np; np++) switch (*np) {

				case '\\':
					if (np[1] == '&')
						np++;
					/* fall into ... */

				default:
					if (--i < 0)
						goto ovflo;
					*wp++ = *np;
					continue;

				case '&':
					i -= strlen(lhsb);
					if (i < 0)
						goto ovflo;
					*wp = 0;
D 7
					strcat(wp, lhsb);
E 7
I 7
					(void) strcat(wp, lhsb);
E 7
					wp = strend(wp);
					continue;
				}
				mp += strlen(lhsb);
				i -= strlen(mp);
				if (i < 0) {
ovflo:
					seterr("Subst buf ovflo");
					return ("");
				}
				*wp = 0;
D 7
				strcat(wp, mp);
E 7
I 7
				(void) strcat(wp, mp);
E 7
				*adid = 1;
				return (savestr(wbuf));
			}
		return (savestr(cp));
	}
}

char *
domod(cp, type)
	char *cp;
	int type;
{
	register char *wp, *xp;
	register int c;

	switch (type) {

	case 'x':
	case 'q':
		wp = savestr(cp);
		for (xp = wp; c = *xp; xp++)
			if ((c != ' ' && c != '\t') || type == 'q')
				*xp |= QUOTE;
		return (wp);

	case 'h':
	case 't':
D 7
		if (!any('/', cp))	/* what if :h :t are both the same? */
			return (0);
E 7
I 7
		if (!any('/', cp))
			return (type == 't' ? savestr(cp) : 0);
E 7
		wp = strend(cp);
		while (*--wp != '/')
			continue;
		if (type == 'h')
D 7
take:
E 7
			xp = savestr(cp), xp[wp - cp] = 0;
		else
			xp = savestr(wp + 1);
		return (xp);

	case 'e':
	case 'r':
		wp = strend(cp);
		for (wp--; wp >= cp && *wp != '/'; wp--)
			if (*wp == '.') {
				if (type == 'e')
					xp = savestr(wp + 1);
				else
					xp = savestr(cp), xp[wp - cp] = 0;
				return (xp);
			}
		return (savestr(type == 'e' ? "" : cp));
	}
	return (0);
}

matchs(str, pat)
	register char *str, *pat;
{

	while (*str && *pat && *str == *pat)
		str++, pat++;
	return (*pat == 0);
}

getsel(al, ar, dol)
	register int *al, *ar;
	int dol;
{
	register int c = getC(0);
	register int i;
	bool first = *al < 0;

	switch (c) {

	case '%':
		if (quesarg == -1)
			goto bad;
		if (*al < 0)
			*al = quesarg;
		*ar = quesarg;
		break;

	case '-':
		if (*al < 0) {
			*al = 0;
			*ar = dol - 1;
			unreadc(c);
		}
		return (1);

	case '^':
		if (*al < 0)
			*al = 1;
		*ar = 1;
		break;

	case '$':
		if (*al < 0)
			*al = dol;
		*ar = dol;
		break;

	case '*':
		if (*al < 0)
			*al = 1;
		*ar = dol;
		if (*ar < *al) {
			*ar = 0;
			*al = 1;
			return (1);
		}
		break;

	default:
		if (digit(c)) {
			i = 0;
			while (digit(c)) {
				i = i * 10 + c - '0';
				c = getC(0);
			}
			if (i < 0)
				i = dol + 1;
			if (*al < 0)
				*al = i;
			*ar = i;
		} else
			if (*al < 0)
				*al = 0, *ar = dol;
			else
				*ar = dol - 1;
		unreadc(c);
		break;
	}
	if (first) {
		c = getC(0);
		unreadc(c);
		if (any(c, "-$*"))
			return (1);
	}
	if (*al > *ar || *ar > dol) {
bad:
		seterr("Bad ! arg selector");
		return (0);
	}
	return (1);

}

struct wordent *
gethent(sc)
	int sc;
{
	register struct Hist *hp;
	register char *np;
	register int c;
	int event;
	bool back = 0;

	c = sc == HISTSUB ? HIST : getC(0);
	if (c == HIST) {
		if (alhistp)
			return (alhistp);
		event = eventno;
		goto skip;
	}
	switch (c) {

	case ':':
	case '^':
	case '$':
	case '*':
	case '%':
		ungetC(c);
		if (lastev == eventno && alhistp)
			return (alhistp);
		event = lastev;
		break;

	case '-':
		back = 1;
		c = getC(0);
		goto number;

	case '#':			/* !# is command being typed in (mrh) */
		return(&paraml);

	default:
		if (any(c, "(=~")) {
			unreadc(c);
			ungetC(HIST);
			return (0);
		}
		if (digit(c))
			goto number;
		np = lhsb;
		while (!any(c, ": \t\\\n}")) {
			if (np < &lhsb[sizeof lhsb - 2])
				*np++ = c;
			c = getC(0);
		}
		unreadc(c);
		if (np == lhsb) {
			ungetC(HIST);
			return (0);
		}
		*np++ = 0;
		hp = findev(lhsb, 0);
		if (hp)
			lastev = hp->Hnum;
		return (&hp->Hlex);

	case '?':
		np = lhsb;
		for (;;) {
			c = getC(0);
			if (c == '\n') {
				unreadc(c);
				break;
			}
			if (c == '?')
				break;
			if (np < &lhsb[sizeof lhsb - 2])
				*np++ = c;
		}
		if (np == lhsb) {
			if (lhsb[0] == 0) {
				seterr("No prev search");
				return (0);
			}
		} else
			*np++ = 0;
		hp = findev(lhsb, 1);
		if (hp)
			lastev = hp->Hnum;
		return (&hp->Hlex);

	number:
		event = 0;
		while (digit(c)) {
			event = event * 10 + c - '0';
			c = getC(0);
		}
		if (back)
			event = eventno + (alhistp == 0) - (event ? event : 0);
		unreadc(c);
		break;
	}
skip:
	for (hp = Histlist.Hnext; hp; hp = hp->Hnext)
		if (hp->Hnum == event) {
			hp->Href = eventno;
			lastev = hp->Hnum;
			return (&hp->Hlex);
		}
	np = putn(event);
	noev(np);
	return (0);
}

struct Hist *
findev(cp, anyarg)
	char *cp;
	bool anyarg;
{
	register struct Hist *hp;

D 7
	for (hp = Histlist.Hnext; hp; hp = hp->Hnext)
		if (matchev(hp, cp, anyarg))
			return (hp);
E 7
I 7
	for (hp = Histlist.Hnext; hp; hp = hp->Hnext) {
		char *dp;
		register char *p, *q;
		register struct wordent *lp = hp->Hlex.next;
		int argno = 0;

		if (lp->word[0] == '\n')
			continue;
		if (!anyarg) {
			p = cp;
			q = lp->word;
			do
				if (!*p)
					return (hp);
			while (*p++ == *q++);
			continue;
		}
		do {
			for (dp = lp->word; *dp; dp++) {
				p = cp;
				q = dp;
				do
					if (!*p) {
						quesarg = argno;
						return (hp);
					}
				while (*p++ == *q++);
			}
			lp = lp->next;
			argno++;
		} while (lp->word[0] != '\n');
	}
E 7
	noev(cp);
	return (0);
}

noev(cp)
	char *cp;
{

	seterr2(cp, ": Event not found");
}

D 7
matchev(hp, cp, anyarg)
	register struct Hist *hp;
	char *cp;
	bool anyarg;
{
	register char *dp;
	struct wordent *lp = &hp->Hlex;
	int argno = 0;

	for (;;) {
		lp = lp->next;
		if (lp->word[0] == '\n')
			return (0);
		for (dp = lp->word; *dp; dp++) {
			if (matchs(dp, cp)) {
				if (anyarg)
					quesarg = argno;
				return (1);
			}
			if (!anyarg)
				return (0);
		}
		argno++;
	}
}

E 7
setexclp(cp)
	register char *cp;
{

D 9
	if (cp[0] == '\n')
E 9
I 9
	if (cp && cp[0] == '\n')
E 9
		return;
	exclp = cp;
}

unreadc(c)
	char c;
{

	peekread = c;
}

readc(wanteof)
	bool wanteof;
{
	register int c;
	static sincereal;

	if (c = peekread) {
		peekread = 0;
		return (c);
	}
top:
	if (alvecp) {
		if (c = *alvecp++)
			return (c);
		if (*alvec) {
			alvecp = *alvec++;
			return (' ');
		}
	}
	if (alvec) {
		if (alvecp = *alvec) {
			alvec++;
			goto top;
		}
		/* Infinite source! */
		return ('\n');
	}
	if (evalp) {
		if (c = *evalp++)
			return (c);
		if (*evalvec) {
			evalp = *evalvec++;
			return (' ');
		}
		evalp = 0;
	}
	if (evalvec) {
		if (evalvec == (char **)1) {
			doneinp = 1;
			reset();
		}
		if (evalp = *evalvec) {
			evalvec++;
			goto top;
		}
		evalvec = (char **)1;
		return ('\n');
	}
	do {
		if (arginp == (char *) 1 || onelflg == 1) {
			if (wanteof)
				return (-1);
			exitstat();
		}
		if (arginp) {
			if ((c = *arginp++) == 0) {
				arginp = (char *) 1;
				return ('\n');
			}
			return (c);
		}
reread:
		c = bgetc();
		if (c < 0) {
D 8
#include <sgtty.h>
E 8
			struct sgttyb tty;

			if (wanteof)
				return (-1);
			/* was isatty but raw with ignoreeof yields problems */
D 7
			if (ioctl(SHIN, TIOCGETP, &tty)==0 && (tty.sg_flags & RAW) == 0) {
E 7
I 7
			if (ioctl(SHIN, TIOCGETP, (char *)&tty) == 0 &&
			    (tty.sg_flags & RAW) == 0) {
E 7
I 3
				/* was 'short' for FILEC */
E 3
D 2
				short ctpgrp;
E 2
I 2
				int ctpgrp;
E 2

				if (++sincereal > 25)
					goto oops;
				if (tpgrp != -1 &&
D 7
				    ioctl(FSHTTY, TIOCGPGRP, &ctpgrp) == 0 &&
E 7
I 7
				    ioctl(FSHTTY, TIOCGPGRP, (char *)&ctpgrp) == 0 &&
E 7
				    tpgrp != ctpgrp) {
D 7
					ioctl(FSHTTY, TIOCSPGRP, &tpgrp);
					killpg(ctpgrp, SIGHUP);
E 7
I 7
					(void) ioctl(FSHTTY, TIOCSPGRP,
						(char *)&tpgrp);
					(void) killpg(ctpgrp, SIGHUP);
E 7
printf("Reset tty pgrp from %d to %d\n", ctpgrp, tpgrp);
					goto reread;
				}
				if (adrof("ignoreeof")) {
					if (loginsh)
						printf("\nUse \"logout\" to logout.\n");
					else
						printf("\nUse \"exit\" to leave csh.\n");
					reset();
				}
				if (chkstop == 0)
					panystop(1);
			}
oops:
			doneinp = 1;
			reset();
		}
		sincereal = 0;
		if (c == '\n' && onelflg)
			onelflg--;
	} while (c == 0);
	return (c);
}

bgetc()
{
	register int buf, off, c;
I 3
#ifdef FILEC
	char ttyline[BUFSIZ];
	register int numleft = 0, roomleft;
D 4
#endif FILEC
E 4
I 4
#endif
E 4
E 3

#ifdef TELL
	if (cantell) {
		if (fseekp < fbobp || fseekp > feobp) {
			fbobp = feobp = fseekp;
D 7
			lseek(SHIN, fseekp, 0);
E 7
I 7
			(void) lseek(SHIN, fseekp, 0);
E 7
		}
		if (fseekp == feobp) {
			fbobp = feobp;
			do
				c = read(SHIN, fbuf[0], BUFSIZ);
			while (c < 0 && errno == EINTR);
			if (c <= 0)
				return (-1);
			feobp += c;
		}
		c = fbuf[0][fseekp - fbobp];
		fseekp++;
		return (c);
	}
#endif
again:
	buf = (int) fseekp / BUFSIZ;
	if (buf >= fblocks) {
D 7
		register char **nfbuf = (char **) calloc(fblocks+2, sizeof (char **));
E 7
I 7
		register char **nfbuf =
			(char **) calloc((unsigned) (fblocks + 2),
				sizeof (char **));
E 7

		if (fbuf) {
D 7
			blkcpy(nfbuf, fbuf);
E 7
I 7
			(void) blkcpy(nfbuf, fbuf);
E 7
			xfree((char *)fbuf);
		}
		fbuf = nfbuf;
		fbuf[fblocks] = calloc(BUFSIZ, sizeof (char));
		fblocks++;
		goto again;
	}
	if (fseekp >= feobp) {
		buf = (int) feobp / BUFSIZ;
		off = (int) feobp % BUFSIZ;
I 3
D 7
#ifdef FILEC
		roomleft = BUFSIZ - off;
D 4
#endif FILEC
E 4
I 4
#endif
E 4
E 3
		do
E 7
D 3
			c = read(SHIN, fbuf[buf] + off, BUFSIZ - off);
E 3
I 3
#ifndef FILEC
I 7
D 8
		do
E 8
I 8
		for (;;) {
E 8
E 7
D 4
		    c = read(SHIN, fbuf[buf] + off, BUFSIZ - off);
#else FILEC
		    if (intty)			/* then use tenex routine */
		    {
			c = numleft ? numleft : tenex(ttyline, BUFSIZ);
			if (c > roomleft)	/* No room in this buffer? */
			{
			    /* start with fresh buffer */
			    feobp = fseekp = fblocks * BUFSIZ;
			    numleft = c;
			    goto again;
			}
			if (c > 0)
			    copy (fbuf[buf] + off, ttyline, c);
			numleft = 0;
		    }
		    else
			c = read(SHIN, fbuf[buf] + off, roomleft);
#endif FILEC
E 4
I 4
			c = read(SHIN, fbuf[buf] + off, BUFSIZ - off);
#else
D 7
			if (intty) {
E 7
I 7
		roomleft = BUFSIZ - off;
D 8
		do
E 8
I 8
		for (;;) {
E 8
			if (filec && intty) {
E 7
				c = numleft ? numleft : tenex(ttyline, BUFSIZ);
				if (c > roomleft) {
					/* start with fresh buffer */
					feobp = fseekp = fblocks * BUFSIZ;
					numleft = c;
					goto again;
				}
				if (c > 0)
					copy(fbuf[buf] + off, ttyline, c);
				numleft = 0;
			} else
				c = read(SHIN, fbuf[buf] + off, roomleft);
#endif
E 4
E 3
D 8
		while (c < 0 && errno == EINTR);
E 8
I 8
			if (c >= 0)
				break;
			if (errno == EWOULDBLOCK) {
				int off = 0;

				(void) ioctl(SHIN, FIONBIO, (char *)&off);
			} else if (errno != EINTR)
				break;
		}
E 8
		if (c <= 0)
			return (-1);
		feobp += c;
I 3
#ifndef FILEC
E 3
		goto again;
I 3
D 4
#else FILEC
E 4
I 4
#else
E 4
D 7
		if (!intty)
		    goto again;
E 7
I 7
		if (filec && !intty)
			goto again;
E 7
D 4
#endif FILEC
E 4
I 4
#endif
E 4
E 3
	}
	c = fbuf[buf][(int) fseekp % BUFSIZ];
	fseekp++;
	return (c);
}

bfree()
{
	register int sb, i;

#ifdef TELL
	if (cantell)
		return;
#endif
	if (whyles)
		return;
	sb = (int) (fseekp - 1) / BUFSIZ;
	if (sb > 0) {
		for (i = 0; i < sb; i++)
			xfree(fbuf[i]);
D 7
		blkcpy(fbuf, &fbuf[sb]);
E 7
I 7
		(void) blkcpy(fbuf, &fbuf[sb]);
E 7
		fseekp -= BUFSIZ * sb;
		feobp -= BUFSIZ * sb;
		fblocks -= sb;
	}
}

bseek(l)
D 7
	long l;
E 7
I 7
	off_t l;
E 7
{
	register struct whyle *wp;

	fseekp = l;
#ifdef TELL
	if (!cantell) {
#endif
		if (!whyles)
			return;
		for (wp = whyles; wp->w_next; wp = wp->w_next)
			continue;
		if (wp->w_start > l)
			l = wp->w_start;
#ifdef TELL
	}
#endif
}

/* any similarity to bell telephone is purely accidental */
I 13
#ifndef btell
E 13
D 7
long
E 7
I 7
off_t
E 7
btell()
{

	return (fseekp);
}
I 13
#endif
E 13

btoeof()
{

D 7
	lseek(SHIN, 0l, 2);
E 7
I 7
	(void) lseek(SHIN, (off_t)0, 2);
E 7
	fseekp = feobp;
	wfree();
	bfree();
}

#ifdef TELL
settell()
{

	cantell = 0;
	if (arginp || onelflg || intty)
		return;
D 7
	if (lseek(SHIN, 0l, 1) < 0 || errno == ESPIPE)
E 7
I 7
	if (lseek(SHIN, (off_t)0, 1) < 0 || errno == ESPIPE)
E 7
		return;
	fbuf = (char **) calloc(2, sizeof (char **));
	fblocks = 1;
	fbuf[0] = calloc(BUFSIZ, sizeof (char));
D 7
	fseekp = fbobp = feobp = tell(SHIN);
E 7
I 7
	fseekp = fbobp = feobp = lseek(SHIN, (off_t)0, 1);
E 7
	cantell = 1;
}
#endif
E 1
