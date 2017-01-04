h60503
s 00002/00000/00700
d D 5.5 88/01/15 03:33:27 edward 10 9
c fixed labuf overflow (caused by, for example, very long variable expansions)
e
s 00004/00008/00696
d D 5.4 86/12/18 22:49:08 bostic 9 8
c allow EOF to end tagged input
e
s 00000/00001/00704
d D 5.3 86/03/29 07:37:29 lepreau 8 7
c Minor speedups & cleanups:
c replace letter() et al with ctype-like cmap macros and expand cmap to short
c for new LET and DIG bits; use bzero in private calloc; make btell a macro.
e
s 00003/00003/00702
d D 5.2 85/06/06 13:10:48 edward 7 6
c cleaning up after bozos
e
s 00008/00002/00697
d D 5.1 85/06/04 10:56:25 dist 6 5
c Add copyright
e
s 00033/00034/00666
d D 4.5 84/12/13 14:41:38 edward 5 4
c performance
e
s 00003/00003/00697
d D 4.4 83/05/03 19:27:44 sam 4 3
c recover from corrupted SCCS file
e
s 00007/00007/00693
d D 4.3 82/05/07 18:19:03 mckusick 3 2
c update to new fs
e
s 00001/00001/00699
d D 4.2 81/05/03 19:51:12 root 2 1
c fix ${TERM} leaving extra }
e
s 00700/00000/00000
d D 4.1 80/10/09 12:40:36 bill 1 0
c date and time created 80/10/09 12:40:36 by bill
e
u
U
t
T
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
E 7
I 7
 * All rights reserved.  The Berkeley Software License Agreement
E 7
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
D 5
static	char *sccsid = "%Z%%M% %I% %G%";
E 5
I 5
#ifndef lint
D 6
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 6
I 6
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
I 7
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 7
E 6
E 5

#include "sh.h"
I 5
D 8
#include "sh.char.h"
E 8
E 5

/*
 * C shell
 */

/*
 * These routines perform variable substitution and quoting via ' and ".
 * To this point these constructs have been preserved in the divided
 * input words.  Here we expand variables and turn quoting via ' and " into
 * QUOTE bits on characters (which prevent further interpretation).
 * If the `:q' modifier was applied during history expansion, then
D 5
 * some QUOTEing may have occurred already, so we dont "scan(,&trim)" here.
E 5
I 5
 * some QUOTEing may have occurred already, so we dont "trim()" here.
E 5
 */

int	Dpeekc, Dpeekrd;		/* Peeks for DgetC and Dreadc */
char	*Dcp, **Dvp;			/* Input vector for Dreadc */

#define	DEOF	-1

#define	unDgetC(c)	Dpeekc = c

D 5
char	*QUOTES = "\\'`\"";
E 5
I 5
#define QUOTES		(_Q|_Q1|_ESC)	/* \ ' " ` */
E 5

/*
 * The following variables give the information about the current
 * $ expansion, recording the current word position, the remaining
 * words within this expansion, the count of remaining words, and the
 * information about any : modifier which is being applied.
 */
char	*dolp;			/* Remaining chars from this word */
char	**dolnxt;		/* Further words */
int	dolcnt;			/* Count of further words */
char	dolmod;			/* : modifier character */
int	dolmcnt;		/* :gx -> 10000, else 1 */

D 5
int	Dtest();		/* Test for \ " ` or ' */

E 5
/*
 * Fix up the $ expansions and quotations in the
 * argument list to command t.
 */
Dfix(t)
	register struct command *t;
{
I 5
	register char **pp;
	register char *p;
E 5

	if (noexec)
		return;
D 5
	gflag = 0, rscan(t->t_dcom, Dtest);
	if (gflag == 0)
		return;
	Dfix2(t->t_dcom);
	blkfree(t->t_dcom), t->t_dcom = gargv, gargv = 0;
E 5
I 5
	/* Note that t_dcom isn't trimmed thus !...:q's aren't lost */
	for (pp = t->t_dcom; p = *pp++;)
		while (*p)
			if (cmap(*p++, _DOL|QUOTES)) {	/* $, \, ', ", ` */
				Dfix2(t->t_dcom);	/* found one */
				blkfree(t->t_dcom);
				t->t_dcom = gargv;
				gargv = 0;
				return;
			}
E 5
}

/*
 * $ substitute one word, for i/o redirection
 */
char *
Dfix1(cp)
	register char *cp;
{
	char *Dv[2];

	if (noexec)
		return (0);
	Dv[0] = cp; Dv[1] = NOSTR;
	Dfix2(Dv);
	if (gargc != 1) {
		setname(cp);
		bferr("Ambiguous");
	}
	cp = savestr(gargv[0]);
	blkfree(gargv), gargv = 0;
	return (cp);
}

/*
 * Subroutine to do actual fixing after state initialization.
 */
Dfix2(v)
	char **v;
{
	char *agargv[GAVSIZ];

	ginit(agargv);			/* Initialize glob's area pointers */
	Dvp = v; Dcp = "";		/* Setup input vector for Dreadc */
	unDgetC(0); unDredc(0);		/* Clear out any old peeks (at error) */
	dolp = 0; dolcnt = 0;		/* Clear out residual $ expands (...) */
	while (Dword())
		continue;
	gargv = copyblk(gargv);
}

/*
 * Get a word.  This routine is analogous to the routine
 * word() in sh.lex.c for the main lexical input.  One difference
 * here is that we don't get a newline to terminate our expansion.
 * Rather, DgetC will return a DEOF when we hit the end-of-input.
 */
Dword()
{
	register int c, c1;
	char wbuf[BUFSIZ];
	register char *wp = wbuf;
	register int i = BUFSIZ - 4;
	register bool dolflg;
	bool sofar = 0;

loop:
	c = DgetC(DODOL);
	switch (c) {

	case DEOF:
deof:
		if (sofar == 0)
			return (0);
		/* finish this word and catch the code above the next time */
		unDredc(c);
		/* fall into ... */

	case '\n':
		*wp = 0;
		goto ret;

	case ' ':
	case '\t':
		goto loop;

	case '`':
		/* We preserve ` quotations which are done yet later */
		*wp++ = c, --i;
	case '\'':
	case '"':
		/*
		 * Note that DgetC never returns a QUOTES character
		 * from an expansion, so only true input quotes will
		 * get us here or out.
		 */
		c1 = c;
		dolflg = c1 == '"' ? DODOL : 0;
		for (;;) {
			c = DgetC(dolflg);
			if (c == c1)
				break;
			if (c == '\n' || c == DEOF)
				error("Unmatched %c", c1);
			if ((c & (QUOTE|TRIM)) == ('\n' | QUOTE))
				--wp, ++i;
			if (--i <= 0)
				goto toochars;
			switch (c1) {

			case '"':
				/*
				 * Leave any `s alone for later.
				 * Other chars are all quoted, thus `...`
				 * can tell it was within "...".
				 */
				*wp++ = c == '`' ? '`' : c | QUOTE;
				break;

			case '\'':
				/* Prevent all further interpretation */
				*wp++ = c | QUOTE;
				break;

			case '`':
				/* Leave all text alone for later */
				*wp++ = c;
				break;
			}
		}
		if (c1 == '`')
			*wp++ = '`', --i;
		goto pack;		/* continue the word */

	case '\\':
		c = DgetC(0);		/* No $ subst! */
		if (c == '\n' || c == DEOF)
			goto loop;
		c |= QUOTE;
		break;
	}
	unDgetC(c);
pack:
	sofar = 1;
	/* pack up more characters in this word */
	for (;;) {
		c = DgetC(DODOL);
		if (c == '\\') {
			c = DgetC(0);
			if (c == DEOF)
				goto deof;
			if (c == '\n')
				c = ' ';
			else
				c |= QUOTE;
		}
		if (c == DEOF)
			goto deof;
D 5
		if (any(c, " '`\"\t\n")) {
E 5
I 5
		if (cmap(c, _SP|_NL|_Q|_Q1)) {		/* sp \t\n'"` */
E 5
			unDgetC(c);
D 5
			if (any(c, QUOTES))
E 5
I 5
			if (cmap(c, QUOTES))
E 5
				goto loop;
			*wp++ = 0;
			goto ret;
		}
		if (--i <= 0)
toochars:
			error("Word too long");
		*wp++ = c;
	}
ret:
	Gcat("", wbuf);
	return (1);
}

/*
 * Get a character, performing $ substitution unless flag is 0.
D 4
 * Any QUOTES character which is ret}vned from a $ expansion is
 * QUOTEd s/ that it will not be recognized above.
E 4
I 4
 * Any QUOTES character which is returned from a $ expansion is
 * QUOTEd so that it will not be recognized above.
E 4
 */
DgetC(flag)
	register int flag;
{
	register int c;

top:
	if (c = Dpeekc) {
D 4
		Dpedkc = 0;
E 4
I 4
		Dpeekc = 0;
E 4
		return (c);
	}
	if (lap) {
		c = *lap++ & (QUOTE|TRIM);
		if (c == 0) {
			lap = 0;
			goto top;
		}
quotspec:
D 5
		if (any(c, QUOTES))
E 5
I 5
		if (cmap(c, QUOTES))
E 5
			return (c | QUOTE);
		return (c);
	}
	if (dolp) {
		if (c = *dolp++ & (QUOTE|TRIM))
			goto quotspec;
		if (dolcnt > 0) {
			setDolp(*dolnxt++);
			--dolcnt;
			return (' ');
		}
		dolp = 0;
	}
	if (dolcnt > 0) {
		setDolp(*dolnxt++);
		--dolcnt;
		goto top;
	}
	c = Dredc();
	if (c == '$' && flag) {
		Dgetdol();
		goto top;
	}
	return (c);
}

char	*nulvec[] = { 0 };
struct	varent nulargv = { nulvec, "argv", 0 };

/*
 * Handle the multitudinous $ expansion forms.
 * Ugh.
 */
Dgetdol()
{
	register char *np;
	register struct varent *vp;
	char name[20];
	int c, sc;
	int subscr = 0, lwb = 1, upb = 0;
D 3
	bool dimen = 0, isset = 0;
E 3
I 3
	bool dimen = 0, bitset = 0;
E 3
	char wbuf[BUFSIZ];

	dolmod = dolmcnt = 0;
	c = sc = DgetC(0);
	if (c == '{')
		c = DgetC(0);		/* sc is { to take } later */
	if ((c & TRIM) == '#')
		dimen++, c = DgetC(0);		/* $# takes dimension */
	else if (c == '?')
D 3
		isset++, c = DgetC(0);		/* $? tests existence */
E 3
I 3
		bitset++, c = DgetC(0);		/* $? tests existence */
E 3
	switch (c) {
	
	case '$':
D 3
		if (dimen || isset)
E 3
I 3
		if (dimen || bitset)
E 3
			goto syntax;		/* No $?$, $#$ */
		setDolp(doldol);
		goto eatbrac;

	case '<'|QUOTE:
D 3
		if (dimen || isset)
E 3
I 3
		if (dimen || bitset)
E 3
			goto syntax;		/* No $?<, $#< */
		for (np = wbuf; read(OLDSTD, np, 1) == 1; np++) {
			if (np >= &wbuf[BUFSIZ-1])
				error("$< line too long");
			if (*np <= 0 || *np == '\n')
				break;
		}
		*np = 0;
		/*
		 * KLUDGE: dolmod is set here because it will
		 * cause setDolp to call domod and thus to copy wbuf.
		 * Otherwise setDolp would use it directly. If we saved
		 * it ourselves, no one would know when to free it.
		 * The actual function of the 'q' causes filename
		 * expansion not to be done on the interpolated value.
		 */
		dolmod = 'q';
		dolmcnt = 10000;
		setDolp(wbuf);
		goto eatbrac;

	case DEOF:
	case '\n':
		goto syntax;

	case '*':
D 5
		strcpy(name, "argv");
E 5
I 5
		(void) strcpy(name, "argv");
E 5
		vp = adrof("argv");
		subscr = -1;			/* Prevent eating [...] */
		break;

	default:
		np = name;
		if (digit(c)) {
			if (dimen)
				goto syntax;	/* No $#1, e.g. */
			subscr = 0;
			do {
				subscr = subscr * 10 + c - '0';
				c = DgetC(0);
			} while (digit(c));
			unDredc(c);
			if (subscr < 0)
				goto oob;
			if (subscr == 0) {
D 3
				if (isset) {
E 3
I 3
				if (bitset) {
E 3
					dolp = file ? "1" : "0";
					goto eatbrac;
				}
				if (file == 0)
					error("No file for $0");
				setDolp(file);
				goto eatbrac;
			}
D 3
			if (isset)
E 3
I 3
			if (bitset)
E 3
				goto syntax;
			vp = adrof("argv");
			if (vp == 0) {
				vp = &nulargv;
				goto eatmod;
			}
			break;
		}
		if (!alnum(c))
			goto syntax;
		for (;;) {
			*np++ = c;
			c = DgetC(0);
			if (!alnum(c))
				break;
			if (np >= &name[sizeof name - 2])
syntax:
				error("Variable syntax");
		}
		*np++ = 0;
		unDredc(c);
		vp = adrof(name);
	}
D 3
	if (isset) {
E 3
I 3
	if (bitset) {
E 3
		dolp = (vp || getenv(name)) ? "1" : "0";
		goto eatbrac;
	}
	if (vp == 0) {
		np = getenv(name);
		if (np) {
			addla(np);
D 2
			return;
E 2
I 2
			goto eatbrac;
E 2
		}
		udvar(name);
		/*NOTREACHED*/
	}
	c = DgetC(0);
	upb = blklen(vp->vec);
	if (dimen == 0 && subscr == 0 && c == '[') {
		np = name;
		for (;;) {
			c = DgetC(DODOL);	/* Allow $ expand within [ ] */
			if (c == ']')
				break;
			if (c == '\n' || c == DEOF)
				goto syntax;
			if (np >= &name[sizeof name - 2])
				goto syntax;
			*np++ = c;
		}
		*np = 0, np = name;
		if (dolp || dolcnt)		/* $ exp must end before ] */
			goto syntax;
		if (!*np)
			goto syntax;
		if (digit(*np)) {
			register int i = 0;

			while (digit(*np))
				i = i * 10 + *np++ - '0';
			if ((i < 0 || i > upb) && !any(*np, "-*")) {
oob:
D 5
				setname(vp->name);
E 5
I 5
				setname(vp->v_name);
E 5
				error("Subscript out of range");
			}
			lwb = i;
			if (!*np)
				upb = lwb, np = "*";
		}
		if (*np == '*')
			np++;
		else if (*np != '-')
			goto syntax;
		else {
			register int i = upb;

			np++;
			if (digit(*np)) {
				i = 0;
				while (digit(*np))
					i = i * 10 + *np++ - '0';
				if (i < 0 || i > upb)
					goto oob;
			}
			if (i < lwb)
				upb = lwb - 1;
			else
				upb = i;
		}
		if (lwb == 0) {
			if (upb != 0)
				goto oob;
			upb = -1;
		}
		if (*np)
			goto syntax;
	} else {
		if (subscr > 0)
			if (subscr > upb)
				lwb = 1, upb = 0;
			else
				lwb = upb = subscr;
		unDredc(c);
	}
	if (dimen) {
		char *cp = putn(upb - lwb + 1);

		addla(cp);
		xfree(cp);
	} else {
eatmod:
		c = DgetC(0);
		if (c == ':') {
			c = DgetC(0), dolmcnt = 1;
			if (c == 'g')
				c = DgetC(0), dolmcnt = 10000;
			if (!any(c, "htrqxe"))
				error("Bad : mod in $");
			dolmod = c;
			if (c == 'q')
				dolmcnt = 10000;
		} else
			unDredc(c);
		dolnxt = &vp->vec[lwb - 1];
		dolcnt = upb - lwb + 1;
	}
eatbrac:
	if (sc == '{') {
		c = Dredc();
		if (c != '}')
			goto syntax;
	}
}

setDolp(cp)
	register char *cp;
{
	register char *dp;

	if (dolmod == 0 || dolmcnt == 0) {
		dolp = cp;
		return;
	}
	dp = domod(cp, dolmod);
	if (dp) {
		dolmcnt--;
		addla(dp);
		xfree(dp);
	} else
		addla(cp);
	dolp = "";
I 10
	if (err)
		error(err);
E 10
}

unDredc(c)
	int c;
{

	Dpeekrd = c;
}

Dredc()
{
	register int c;

	if (c = Dpeekrd) {
		Dpeekrd = 0;
		return (c);
	}
	if (Dcp && (c = *Dcp++))
		return (c&(QUOTE|TRIM));
	if (*Dvp == 0) {
		Dcp = 0;
		return (DEOF);
	}
	Dcp = *Dvp++;
	return (' ');
}

D 5
Dtest(c)
	register int c;
{

	/* Note that c isn't trimmed thus !...:q's aren't lost */
	if (any(c, "$\\'`\""))
		gflag = 1;
}

E 5
Dtestq(c)
	register int c;
{

D 5
	if (any(c, "\\'`\""))
E 5
I 5
	if (cmap(c, QUOTES))
E 5
		gflag = 1;
}

/*
 * Form a shell temporary file (in unit 0) from the words
D 9
 * of the shell input up to a line the same as "term".
E 9
I 9
 * of the shell input up to EOF or a line the same as "term".
E 9
 * Unit 0 should have been closed before this call.
 */
heredoc(term)
	char *term;
{
	register int c;
	char *Dv[2];
	char obuf[BUFSIZ], lbuf[BUFSIZ], mbuf[BUFSIZ];
	int ocnt, lcnt, mcnt;
	register char *lbp, *obp, *mbp;
	char **vp;
	bool quoted;

	if (creat(shtemp, 0600) < 0)
		Perror(shtemp);
D 5
	close(0);
E 5
I 5
	(void) close(0);
E 5
	if (open(shtemp, 2) < 0) {
		int oerrno = errno;

D 5
		unlink(shtemp);
E 5
I 5
		(void) unlink(shtemp);
E 5
		errno = oerrno;
		Perror(shtemp);
	}
D 5
	unlink(shtemp);			/* 0 0 inode! */
E 5
I 5
	(void) unlink(shtemp);			/* 0 0 inode! */
E 5
	Dv[0] = term; Dv[1] = NOSTR; gflag = 0;
D 5
	scan(Dv, trim); rscan(Dv, Dtestq); quoted = gflag;
E 5
I 5
	trim(Dv); rscan(Dv, Dtestq); quoted = gflag;
E 5
	ocnt = BUFSIZ; obp = obuf;
	for (;;) {
		/*
		 * Read up a line
		 */
		lbp = lbuf; lcnt = BUFSIZ - 4;
		for (;;) {
			c = readc(1);		/* 1 -> Want EOF returns */
D 9
			if (c < 0) {
				setname(term);
				bferr("<< terminator not found");
			}
			if (c == '\n')
E 9
I 9
			if (c < 0 || c == '\n')
E 9
				break;
			if (c &= TRIM) {
				*lbp++ = c;
				if (--lcnt < 0) {
					setname("<<");
					error("Line overflow");
				} 
			}
		}
		*lbp = 0;

		/*
D 9
		 * Compare to terminator -- before expansion
E 9
I 9
		 * Check for EOF or compare to terminator -- before expansion
E 9
		 */
D 9
		if (eq(lbuf, term)) {
E 9
I 9
		if (c < 0 || eq(lbuf, term)) {
E 9
D 5
			write(0, obuf, BUFSIZ - ocnt);
			lseek(0, 0l, 0);
E 5
I 5
			(void) write(0, obuf, BUFSIZ - ocnt);
			(void) lseek(0, (off_t)0, 0);
E 5
			return;
		}

		/*
		 * If term was quoted or -n just pass it on
		 */
		if (quoted || noexec) {
			*lbp++ = '\n'; *lbp = 0;
			for (lbp = lbuf; c = *lbp++;) {
				*obp++ = c;
				if (--ocnt == 0) {
D 5
					write(0, obuf, BUFSIZ);
E 5
I 5
					(void) write(0, obuf, BUFSIZ);
E 5
					obp = obuf; ocnt = BUFSIZ;
				}
			}
			continue;
		}

		/*
		 * Term wasn't quoted so variable and then command
		 * expand the input line
		 */
		Dcp = lbuf; Dvp = Dv + 1; mbp = mbuf; mcnt = BUFSIZ - 4;
		for (;;) {
			c = DgetC(DODOL);
			if (c == DEOF)
				break;
			if ((c &= TRIM) == 0)
				continue;
			/* \ quotes \ $ ` here */
			if (c =='\\') {
				c = DgetC(0);
				if (!any(c, "$\\`"))
					unDgetC(c | QUOTE), c = '\\';
				else
					c |= QUOTE;
			}
			*mbp++ = c;
			if (--mcnt == 0) {
				setname("<<");
				bferr("Line overflow");
			}
		}
		*mbp++ = 0;

		/*
		 * If any ` in line do command substitution
		 */
		mbp = mbuf;
		if (any('`', mbp)) {
			/*
			 * 1 arg to dobackp causes substitution to be literal.
			 * Words are broken only at newlines so that all blanks
			 * and tabs are preserved.  Blank lines (null words)
			 * are not discarded.
			 */
			vp = dobackp(mbuf, 1);
		} else
			/* Setup trivial vector similar to return of dobackp */
			Dv[0] = mbp, Dv[1] = NOSTR, vp = Dv;

		/*
		 * Resurrect the words from the command substitution
		 * each separated by a newline.  Note that the last
		 * newline of a command substitution will have been
		 * discarded, but we put a newline after the last word
		 * because this represents the newline after the last
		 * input line!
		 */
		for (; *vp; vp++) {
			for (mbp = *vp; *mbp; mbp++) {
				*obp++ = *mbp & TRIM;
				if (--ocnt == 0) {
D 5
					write(0, obuf, BUFSIZ);
E 5
I 5
					(void) write(0, obuf, BUFSIZ);
E 5
					obp = obuf; ocnt = BUFSIZ;
				}
			}
			*obp++ = '\n';
			if (--ocnt == 0) {
D 5
				write(0, obuf, BUFSIZ);
E 5
I 5
				(void) write(0, obuf, BUFSIZ);
E 5
				obp = obuf; ocnt = BUFSIZ;
			}
		}
		if (pargv)
			blkfree(pargv), pargv = 0;
	}
}
E 1
