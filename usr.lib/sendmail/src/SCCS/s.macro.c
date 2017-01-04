h44858
s 00011/00009/00238
d D 5.5 88/06/30 14:59:05 bostic 34 33
c install approved copyright notice
e
s 00016/00010/00231
d D 5.4 88/03/13 19:52:13 bostic 33 32
c add Berkeley specific header
e
s 00003/00003/00238
d D 5.3 85/09/19 00:44:59 eric 32 31
m 
c SMI changes (somewhat)
e
s 00000/00002/00241
d D 5.2 85/06/07 22:11:31 miriam 31 30
m 
c Resolve duplicate SccsId
e
s 00014/00000/00229
d D 5.1 85/06/07 15:07:07 dist 30 29
m 
c Add copyright
e
s 00018/00015/00211
d D 4.3 84/11/13 11:44:32 eric 29 28
m 
c optimize macro expansion
e
s 00001/00008/00225
d D 4.2 84/03/11 16:52:04 eric 28 27
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00000/00000/00233
d D 4.1 83/07/25 19:43:28 eric 27 26
m 
c 4.2 release version
e
s 00001/00000/00232
d D 3.20 83/02/03 10:29:55 eric 26 25
m 160
c $e macro is now SMTP entry message (so that configuration version can
c be included).
e
s 00001/00000/00231
d D 3.19 83/01/17 21:42:02 eric 25 24
m 158
c Set the $w macro to the hostname if at all possible to allow generic
c configuration tables.
e
s 00021/00024/00210
d D 3.18 82/11/28 00:23:59 eric 24 23
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00015/00004/00219
d D 3.17 82/09/12 16:44:17 eric 23 22
c change inheritance for macros in envelopes; be able to canonicalize
c non-domained names by appending domain from sender; call ruleset 3
c explicitly before doing other rulesets; some general cleanup.
e
s 00004/00002/00219
d D 3.16 82/09/05 18:03:45 eric 22 21
c tune debugging
e
s 00002/00001/00219
d D 3.15 82/08/22 23:07:28 eric 21 20
c change $i to $j; $i is now queue id; put "Received:" format in .cf
c file; minor cleanup
e
s 00003/00003/00217
d D 3.14 82/08/08 01:03:43 eric 20 19
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00000/00000/00220
d D 3.13 82/05/31 18:50:39 eric 19 18
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00000/00000/00220
d D 3.12 82/05/31 15:32:52 eric 18 16
i 17
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00021/00009/00199
d D 3.11.1.1 82/05/29 18:21:03 eric 17 16
c try to install envelopes.  is this really worth it???
e
s 00061/00035/00147
d D 3.11 82/03/06 14:16:50 eric 16 15
c collapse special character processing into macro processing for
c simplicity of code.
e
s 00002/00000/00180
d D 3.10 82/02/20 19:16:24 eric 15 14
c make rewriting of addresses in headers really work.  This adds the $q
c macro.  The rewriting of the From: address is still ad hoc and should
c be integrated into this format.
c Note:  old .cf files will not work with this version.
e
s 00001/00001/00179
d D 3.9 82/02/20 13:00:31 eric 14 13
c expand macros in rewriting rules early to allow multi-word macros to
c be processed correctly.
e
s 00001/00001/00179
d D 3.8 81/12/06 12:40:01 eric 13 12
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00002/00000/00178
d D 3.7 81/12/05 14:14:45 eric 12 11
c insert SMTP "Mail-From:" line.
e
s 00001/00000/00177
d D 3.6 81/10/20 11:36:48 eric 11 10
c clean up the SMTP stuff some more
e
s 00019/00000/00158
d D 3.5 81/10/02 11:05:25 eric 10 8
c arrange to give the correct "from" person on error messages.
e
s 00001/00000/00158
d D 3.4.1.1 81/09/23 18:23:34 eric 9 8
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00010/00004/00148
d D 3.4 81/09/06 19:49:20 eric 8 7
c cleanup, commenting, linting, etc.
e
s 00006/00002/00146
d D 3.3 81/08/22 14:31:39 eric 7 6
c bring comments up to date
e
s 00001/00001/00147
d D 3.2 81/08/20 12:27:35 eric 6 5
c take $$ to get $
e
s 00031/00000/00117
d D 3.1 81/08/09 16:53:58 eric 5 4
c documentation
e
s 00000/00000/00117
d D 1.4 81/08/09 15:03:46 eric 4 3
c lint it
e
s 00004/00004/00113
d D 1.3 81/08/09 10:13:50 eric 3 2
c change to debugging levels
e
s 00030/00001/00087
d D 1.2 81/03/28 12:03:05 eric 2 1
c put much more info in cf file (e.g., headers)
e
s 00088/00000/00000
d D 1.1 81/03/27 13:41:02 eric 1 0
c date and time created 81/03/27 13:41:02 by eric
e
u
U
f b 
f i 
t
T
I 30
/*
I 34
 * Copyright (c) 1983 Eric P. Allman
E 34
D 33
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 33
I 33
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 34
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 34
I 34
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 34
 */
E 33

#ifndef lint
D 33
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 33
I 33
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 33

E 30
I 1
D 16
# include "useful.h"
E 16
I 16
# include "sendmail.h"
E 16
I 9
# include "conf.h"
E 9

D 13
static char SccsId[] = "%W%	%G%";
E 13
I 13
D 31
SCCSID(%W%	%Y%	%G%);
E 13

E 31
D 17
char	*Macro[128];
D 3
extern bool	Debug;
E 3
I 3
D 16
extern int	Debug;
E 16
E 3

E 17
/*
**  EXPAND -- macro expand a string using $x escapes.
**
**	Parameters:
**		s -- the string to expand.
**		buf -- the place to put the expansion.
**		buflim -- the buffer limit, i.e., the address
**			of the last usable position in buf.
I 17
**		e -- envelope in which to work.
E 17
**
**	Returns:
D 8
**		buf.
E 8
I 8
D 24
**		End of interpolated output.
E 24
I 24
**		none.
E 24
E 8
**
**	Side Effects:
**		none.
I 24
D 28
**
**	Bugs:
**		The handling of $$ (to get one dollar) is rather bizarre,
**			especially if there should be another macro
**			expansion in the same string.
E 28
E 24
*/

I 17
expand(s, buf, buflim, e)
	register char *s;
	register char *buf;
	char *buflim;
	register ENVELOPE *e;
{
I 29
	register char *xp;
E 29
D 24
	extern char *expand2();

	(void) expand2(s, buf, buflim, e);
}


E 17
char *
D 17
expand(s, buf, buflim)
E 17
I 17
expand2(s, buf, buflim, e)
E 17
	register char *s;
	register char *buf;
	char *buflim;
I 17
	register ENVELOPE *e;
E 17
{
E 24
D 8
	register char *q;
E 8
D 16
	register char *bp;
E 16
I 16
	register char *q;
D 24
	char xbuf[BUFSIZ];
	register char *xp = xbuf;
E 24
E 16
I 2
D 8
	bool skipping;
E 8
I 8
	bool skipping;		/* set if conditionally skipping output */
I 16
D 29
	bool gotone = FALSE;	/* set if any expansion done */
E 29
I 29
	bool recurse = FALSE;	/* set if recursion required */
	int i;
E 29
I 24
	char xbuf[BUFSIZ];
D 29
	register char *xp = xbuf;
E 29
E 24
I 23
	extern char *macvalue();
E 23
E 16
E 8
E 2

# ifdef DEBUG
D 3
	if (Debug)
E 3
I 3
D 20
	if (Debug > 3)
E 20
I 20
D 32
	if (tTd(35, 4))
E 32
I 32
	if (tTd(35, 24))
E 32
E 20
E 3
D 16
		printf("expand(%s)\n", s);
E 16
I 16
	{
		printf("expand(");
		xputs(s);
		printf(")\n");
	}
E 16
# endif DEBUG

I 2
	skipping = FALSE;
I 22
	if (s == NULL)
		s = "";
E 22
E 2
D 16
	for (bp = buf; *s != '\0'; s++)
E 16
I 16
D 29
	for (; *s != '\0'; s++)
E 29
I 29
	for (xp = xbuf; *s != '\0'; s++)
E 29
E 16
	{
D 8
		/* q will be the interpolated quantity */
E 8
I 8
D 16
		register char *q;
E 16
I 16
		char c;
E 16

		/*
D 16
		**  Check for non-ordinary (special?) character --
		**  always escaped with dollar sign.
E 16
I 16
		**  Check for non-ordinary (special?) character.
E 16
		**	'q' will be the interpolated quantity.
		*/

E 8
		q = NULL;
D 16
		if (*s == '$')
E 16
I 16
		c = *s;
		switch (c)
E 16
D 2
			q = Macro[*++s & 0177];
E 2
I 2
		{
D 16
			char c;
E 2

E 16
I 16
		  case CONDIF:		/* see if var set */
E 16
I 2
			c = *++s;
D 16
			switch (c)
			{
			  case '?':	/* see if var set */
				c = *++s;
				skipping = Macro[c] == NULL;
				break;
E 16
I 16
D 17
			skipping = Macro[c] == NULL;
E 17
I 17
D 23
			skipping = e->e_macro[c] == NULL;
E 23
I 23
			skipping = macvalue(c, e) == NULL;
E 23
E 17
			continue;
E 16

D 14
			  case ':':	/* else */
E 14
I 14
D 16
			  case '|':	/* else */
E 14
				skipping = !skipping;
				break;
E 16
I 16
		  case CONDELSE:	/* change state of skipping */
			skipping = !skipping;
			continue;
E 16

D 16
			  case '.':	/* end if */
				skipping = FALSE;
				break;
E 16
I 16
		  case CONDFI:		/* stop skipping */
			skipping = FALSE;
			continue;
E 16

D 16
			  default:
				q = Macro[c & 0177];
				break;
			}
E 16
I 16
D 28
		  case '$':		/* macro interpolation */
E 28
I 28
		  case '\001':		/* macro interpolation */
E 28
			c = *++s;
I 24
D 28
			if (c == '$')
				break;
E 28
E 24
D 17
			q = Macro[c & 0177];
E 17
I 17
D 23
			q = e->e_macro[c & 0177];
E 23
I 23
			q = macvalue(c & 0177, e);
E 23
E 17
E 16
D 6
			if (q == NULL)
E 6
I 6
D 24
			if (q == NULL && c != '$')
E 24
I 24
			if (q == NULL)
E 24
E 6
				continue;
I 16
D 29
			gotone = TRUE;
E 29
			break;
E 16
		}

E 2
		/*
		**  Interpolate q or output one character
		*/

I 2
D 29
		if (skipping)
E 29
I 29
		if (skipping || xp >= &xbuf[sizeof xbuf])
E 29
			continue;
E 2
D 16
		if (q != NULL)
			bp = expand(q, bp, buflim);
		else if (bp < buflim - 1)
			*bp++ = *s;
E 16
I 16
D 29
		while (xp < &xbuf[sizeof xbuf])
E 29
I 29
		if (q == NULL)
			*xp++ = c;
		else
E 29
		{
D 29
			if (q == NULL)
E 29
I 29
			/* copy to end of q or max space remaining in buf */
			while ((c = *q++) != '\0' && xp < &xbuf[sizeof xbuf - 1])
E 29
			{
I 29
				if (iscntrl(c) && !isspace(c))
					recurse = TRUE;
E 29
				*xp++ = c;
D 29
				break;
E 29
			}
D 24
			if (*q == NULL)
E 24
I 24
D 29
			if (*q == '\0')
E 24
				break;
			*xp++ = *q++;
E 29
		}
E 16
	}
D 16
	*bp = '\0';
E 16
I 16
	*xp = '\0';
E 16

# ifdef DEBUG
D 3
	if (Debug)
E 3
I 3
D 20
	if (Debug > 3)
E 20
I 20
D 32
	if (tTd(35, 4))
E 32
I 32
	if (tTd(35, 24))
E 32
E 20
E 3
D 16
		printf("expand ==> '%s'\n", buf);
E 16
I 16
	{
D 22
		printf("expand ==> '");
E 22
I 22
		printf("expand ==> ");
E 22
		xputs(xbuf);
D 22
		printf("'\n");
E 22
I 22
		printf("\n");
E 22
	}
E 16
# endif DEBUG

D 16
	return (bp);
E 16
I 16
	/* recurse as appropriate */
D 29
	if (gotone)
E 29
I 29
	if (recurse)
E 29
D 17
		return (expand(xbuf, buf, buflim));
E 17
I 17
D 24
		return (expand2(xbuf, buf, buflim, e));
E 24
I 24
	{
		expand(xbuf, buf, buflim, e);
		return;
	}
E 24
E 17

	/* copy results out */
D 29
	for (q = buf, xp = xbuf; xp != '\0' && q < buflim-1; )
		*q++ = *xp++;
	*q = '\0';
E 29
I 29
	i = buflim - buf - 1;
	if (i > xp - xbuf)
		i = xp - xbuf;
	bcopy(xbuf, buf, i);
	buf[i] = '\0';
E 29
D 24

	return (q);
E 24
E 16
}
/*
**  DEFINE -- define a macro.
**
**	this would be better done using a #define macro.
**
**	Parameters:
**		n -- the macro name.
**		v -- the macro value.
I 24
**		e -- the envelope to store the definition in.
E 24
**
**	Returns:
**		none.
**
**	Side Effects:
D 17
**		Macro[n] is defined.
E 17
I 17
D 24
**		CurEnv->e_macro[n] is defined.
E 24
I 24
**		e->e_macro[n] is defined.
E 24
E 17
I 5
**
**	Notes:
**		There is one macro for each ASCII character,
**		although they are not all used.  The currently
**		defined macros are:
**
D 7
**		$a   date in arpa format
E 7
I 7
**		$a   date in ARPANET format (preferring the Date: line
**		     of the message)
**		$b   the current date (as opposed to the date as found
**		     the message) in ARPANET format
E 7
**		$c   hop count
D 7
**		$d   date in ctime format
E 7
I 7
**		$d   (current) date in UNIX (ctime) format
I 26
**		$e   the SMTP entry message+
E 26
E 7
**		$f   raw from address
**		$g   translated from address
**		$h   to host
I 11
D 21
**		$i   official SMTP hostname, used in messages+
E 21
I 21
**		$i   queue id
**		$j   official SMTP hostname, used in messages+
E 21
E 11
**		$l   UNIX-style from line+
**		$n   name of sendmail ("MAILER-DAEMON" on local
**		     net typically)+
**		$o   delimiters ("operators") for address tokens+
**		$p   my process id in decimal
I 15
**		$q   the string that becomes an address -- this is
**		     normally used to combine $g & $x.
E 15
I 12
**		$r   protocol used to talk to sender
**		$s   sender's host name
E 12
**		$t   the current time in seconds since 1/1/1970
**		$u   to user
**		$v   version number of sendmail
I 25
**		$w   our host name (if it can be determined)
E 25
**		$x   signature (full name) of from person
I 7
**		$y   the tty id of our terminal
E 7
**		$z   home directory of to person
**
**		Macros marked with + must be defined in the
**		configuration file and are used internally, but
**		are not set.
**
**		There are also some macros that can be used
**		arbitrarily to make the configuration file
**		cleaner.  In general all upper-case letters
**		are available.
E 5
*/

D 24
define(n, v)
E 24
I 24
define(n, v, e)
E 24
	char n;
	char *v;
I 24
	register ENVELOPE *e;
E 24
{
# ifdef DEBUG
D 3
	if (Debug)
E 3
I 3
D 20
	if (Debug > 3)
E 20
I 20
D 32
	if (tTd(35, 3))
E 32
I 32
	if (tTd(35, 9))
E 32
E 20
E 3
D 16
		printf("define(%c as %s)\n", n, v);
E 16
I 16
	{
		printf("define(%c as ", n);
		xputs(v);
		printf(")\n");
	}
E 16
# endif DEBUG
D 17
	Macro[n & 0177] = v;
E 17
I 17
D 24
	CurEnv->e_macro[n & 0177] = v;
E 24
I 24
	e->e_macro[n & 0177] = v;
E 24
E 17
}
I 10
/*
**  MACVALUE -- return uninterpreted value of a macro.
**
**	Parameters:
**		n -- the name of the macro.
**
**	Returns:
**		The value of n.
**
**	Side Effects:
**		none.
*/

char *
D 23
macvalue(n)
E 23
I 23
macvalue(n, e)
E 23
	char n;
I 23
	register ENVELOPE *e;
E 23
{
D 17
	return (Macro[n & 0177]);
E 17
I 17
D 23
	return (CurEnv->e_macro[n & 0177]);
E 23
I 23
	n &= 0177;
	while (e != NULL)
	{
		register char *p = e->e_macro[n];

		if (p != NULL)
			return (p);
		e = e->e_parent;
	}
	return (NULL);
E 23
E 17
}
E 10
E 1
