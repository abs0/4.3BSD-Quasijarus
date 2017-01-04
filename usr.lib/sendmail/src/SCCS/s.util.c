h43644
s 00000/00001/00864
d D 5.9 86/12/17 16:05:39 eric 71 70
c delete unneeded #include <ctype.h>
e
s 00001/00001/00864
d D 5.8 85/12/17 23:54:13 eric 70 69
m 
c lint
e
s 00001/00005/00864
d D 5.7 85/09/30 21:34:27 eric 69 68
m 
c clean up some aspects of error message display
e
s 00005/00001/00864
d D 5.6 85/09/19 00:45:26 eric 68 67
m 
c SMI changes (somewhat)
e
s 00002/00001/00863
d D 5.5 85/06/08 10:30:11 eric 67 66
m 
c lint for 4.3 release
e
s 00012/00012/00852
d D 5.4 85/06/08 00:30:55 eric 66 65
m 
c lint
e
s 00000/00002/00864
d D 5.3 85/06/07 22:22:08 miriam 65 64
m 
c Resolve duplicate SccsId
e
s 00000/00000/00866
d D 5.2 85/06/07 15:21:54 dist 64 63
m 
c Add copyright
e
s 00014/00000/00852
d D 5.1 85/06/07 15:18:20 dist 63 62
m 
c Add copyright
e
s 00001/00004/00851
d D 4.11 85/04/28 10:42:36 eric 62 61
m 
c remove #ifdef DEBUG so we can compile without #define DEBUG
e
s 00000/00019/00855
d D 4.10 85/04/09 14:14:54 ralph 61 60
m 
c syslog() is in lint librrary now.
e
s 00036/00019/00838
d D 4.9 84/11/13 12:29:36 eric 60 59
m 
c optimize fgetfolded and sameword
e
s 00002/00002/00855
d D 4.8 84/08/11 17:49:03 eric 59 58
m 
c Assorted changes from Guy Harris <rlgvax!guy>: mostly lint & USG
e
s 00001/00022/00856
d D 4.7 84/08/11 16:51:51 eric 58 57
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00006/00001/00872
d D 4.6 84/08/11 14:53:19 eric 57 56
m 
c strip 0200 bits on input to prevent loops
e
s 00006/00001/00867
d D 4.5 84/03/11 13:37:47 eric 56 55
m 
c fixes from Greg Satz <satz@sri-tsc.ARPA>, mostly for PDP's
e
s 00000/00020/00868
d D 4.4 83/12/27 22:52:29 eric 55 54
m 
c don't close files immediately before exec of mailer so that we can log;
c use FIOCLEX instead.  Suggested by Tom Ferrin, UCSF CGL.
e
s 00009/00003/00879
d D 4.3 83/11/13 18:08:07 eric 54 53
m 
c Fixes two nasty problems, both pointed out by Bill Nowicki at Stanford:
c I/O errors on input in collect would cause infinite loops, and a protocol
c error (or other error that would call smtpquit abnormally) would cause
c core dumps
e
s 00018/00007/00864
d D 4.2 83/08/31 17:42:23 eric 53 52
m 
c fix problem with timeouts caused by change in EINTR semantics in 4.2bsd;
c add a two minute timeout on the greeting message in user smtp to detect
c hung connections
e
s 00000/00000/00871
d D 4.1 83/07/25 19:45:24 eric 52 51
m 
c 4.2 release version
e
s 00002/00000/00869
d D 3.44 83/04/17 17:15:30 eric 51 50
m 221
c fix bogus errno problems
e
s 00009/00001/00860
d D 3.43 83/02/24 18:53:57 eric 50 49
m 192
c Truncate output text to seven bits
e
s 00056/00004/00805
d D 3.42 83/02/02 12:53:22 eric 49 48
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00004/00004/00805
d D 3.41 83/01/16 13:14:17 eric 48 47
m 152
c Change mailer spec to have labelled fields for future expansion.
c **** This delta invalidates previous configuration files ****
e
s 00002/00031/00807
d D 3.40 83/01/09 15:42:29 eric 47 46
m 
c fix CRLF problem when sending SMTP commands; make newstr() and crlf()
c into macros
e
s 00014/00013/00824
d D 3.39 83/01/06 10:46:54 eric 46 45
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00009/00003/00828
d D 3.38 83/01/01 21:25:45 eric 45 44
m 123
c Put CRLF on all lines in user SMTP.  Pass this info down to
c innumerable routines.
e
s 00002/00001/00829
d D 3.37 82/12/30 17:30:37 eric 44 43
m 114
c don't bother timing out on *.cf and qf* file reads -- they are
c really very vanilla
e
s 00002/00000/00828
d D 3.36 82/12/09 11:14:25 eric 43 42
m 081
c log read timeouts as a syserr
e
s 00052/00093/00776
d D 3.35 82/11/28 00:22:29 eric 42 41
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00023/00000/00846
d D 3.34 82/11/03 10:29:24 eric 41 40
m 058
c Put temporary file mode on the F option
e
s 00027/00000/00819
d D 3.33 82/11/03 09:49:24 eric 40 39
m 049
c Arrange to strip quote bits in message header; move SPACESUB into
c conf.c; change SpaceSub to unquoted dot
e
s 00024/00000/00795
d D 3.32 82/09/26 14:46:01 eric 39 38
c completely instantiate queue files for all mail, even if not needed;
c fix a bug that would probably come up once every ten years in creating
c the queue id.  should merge argv flag processing with option processing.
e
s 00007/00002/00788
d D 3.31 82/09/05 18:03:35 eric 38 37
c tune debugging
e
s 00007/00001/00783
d D 3.30 82/09/05 11:45:22 eric 37 36
c add line numbering for some input files; improve debugging output
e
s 00012/00008/00772
d D 3.29 82/08/27 16:03:28 eric 36 35
c simplify timeout code; allow multiple simultaneous queue runs so that
c large messages don't freeze things up; fix EINTR problem in sfgets;
c clean up canonname to be really correct; lots of misc. cleanup
e
s 00021/00000/00759
d D 3.28 82/08/25 11:21:31 eric 35 34
c clean up time manipulation to always be current; assign job
c id's earlier to make sure there is always one with a message.
e
s 00001/00001/00758
d D 3.27 82/08/24 10:27:21 eric 34 33
c clean up event handling so that events that do longjmp's don't turn
c off all future events.
e
s 00091/00000/00668
d D 3.26 82/08/23 11:59:43 eric 33 32
c clean up queueing; log time in queue.
c **** This delta invalidates mqueue files ****
e
s 00001/00001/00667
d D 3.25 82/08/22 19:03:13 eric 32 31
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00042/00000/00626
d D 3.24 82/08/17 20:43:29 eric 31 30
c handle folded lines in queue file properly
e
s 00033/00026/00593
d D 3.23 82/08/15 11:51:38 eric 30 29
c know about continuation lines in queue files: necessary for headers
e
s 00041/00000/00578
d D 3.22 82/08/08 17:02:39 eric 29 28
c more general event mechanism
e
s 00029/00000/00549
d D 3.21 82/08/08 01:03:06 eric 28 27
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00000/00023/00549
d D 3.20 82/07/05 12:21:57 eric 27 26
c split off clock stuff from util.c so that vacation will compile
e
s 00023/00000/00549
d D 3.19 82/07/05 12:02:47 eric 26 25
c put timeouts on net reads
e
s 00001/00002/00548
d D 3.18 82/06/26 13:10:36 eric 25 24
c lint
e
s 00055/00000/00495
d D 3.17 82/06/07 23:55:47 eric 24 23
c call the routine putline to output lines to mailers.  this lets us
c implement line length limits, etc. for full SMTP compatibility.
e
s 00004/00004/00491
d D 3.16 82/05/31 18:49:42 eric 23 22
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00030/00001/00465
d D 3.15 82/05/20 17:45:57 eric 22 21
c add dfopen as a "determined fopen" -- it retries if it gets recoverable
c errors.  we use it for returning mail (to dead.letter) and creating the
c temp file.  the whole idea is to avoid dropping things on the floor on
c heavily loaded systems.  this is untested, since it seems impossible to
c fill up the inode or file tables on this VAX (but it works if the open
c succeeds).
e
s 00001/00001/00465
d D 3.14 82/03/20 18:12:53 eric 21 20
c take % as an acceptable name terminator in GECOS field
c ("in-care-of") -- for TEF%UCSFCGL
e
s 00001/00001/00465
d D 3.13 81/12/06 12:39:03 eric 20 18
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00008/00011/00455
d D 3.12.1.1 81/11/21 15:47:50 eric 19 18
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00001/00001/00465
d D 3.12 81/11/07 21:57:40 eric 18 17
c fix a bug in fixcrlf that made SMTP die
e
s 00034/00000/00432
d D 3.11 81/10/20 11:36:19 eric 17 16
c clean up the SMTP stuff some more
e
s 00031/00000/00401
d D 3.10 81/10/17 16:57:55 eric 16 15
c initial prep to put in Daemon mode
e
s 00002/00000/00399
d D 3.9 81/09/24 10:30:37 eric 15 13
c changes to work under a V6 system -- mostly compilation flags
e
s 00001/00000/00399
d D 3.8.1.1 81/09/23 18:23:11 eric 14 13
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00040/00000/00359
d D 3.8 81/09/12 17:34:01 eric 13 12
c match on full name for local users
e
s 00029/00002/00330
d D 3.7 81/08/10 16:56:46 eric 12 11
c totally rework aliasing scheme -- sucks when no DBM now,
c but works better for the usual case; fix some quoting problems
c (and how many did I add?); remove .mailer feature since .forward
c will simulate this happily
e
s 00022/00006/00310
d D 3.6 81/08/09 15:03:12 eric 11 10
c lint it
e
s 00029/00000/00287
d D 3.5 81/08/08 11:17:20 eric 10 9
c add "sameword" to do case-indistinct matching of names
e
s 00155/00000/00132
d D 3.4 81/03/09 13:22:41 eric 9 8
c first step at rewriting rules, etc.
e
s 00002/00001/00130
d D 3.3 81/03/07 15:33:41 eric 8 7
c lint fixes
e
s 00000/00030/00131
d D 3.2 81/03/07 14:27:15 eric 7 6
c ----- delivermail ==> postbox -----
e
s 00062/00003/00099
d D 3.1 81/03/04 09:34:38 eric 6 5
c install fancy header stuff
e
s 00000/00000/00102
d D 2.1 80/11/05 11:00:30 eric 5 4
c release 2
e
s 00001/00001/00101
d D 1.4 80/10/21 22:39:47 eric 4 3
c EX_UNAVAIL => EX_UNAVAILABLE
e
s 00000/00028/00102
d D 1.3 80/08/02 13:50:10 eric 3 2
c cleaned up comments
e
s 00002/00000/00128
d D 1.2 80/07/25 22:04:31 eric 2 1
c add ID keywords
e
s 00128/00000/00000
d D 1.1 80/06/23 08:24:52 eric 1 0
e
u
U
f b 
f i 
t
T
I 63
/*
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/

#ifndef lint
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint

E 63
I 9
# include <stdio.h>
I 19
# include <pwd.h>
E 19
I 16
# include <sys/types.h>
# include <sys/stat.h>
E 16
E 9
I 1
# include <sysexits.h>
D 22
# include "useful.h"
E 22
I 22
# include <errno.h>
E 22
I 6
D 71
# include <ctype.h>
E 71
I 22
# include "sendmail.h"
E 22
I 14
# include "conf.h"
E 14
E 6

I 2
D 20
static char	SccsId[] = "%W%	%G%";
E 20
I 20
D 65
SCCSID(%W%	%Y%	%G%);
E 20

E 65
E 2
/*
D 3
**  UTIL.C -- General Purpose Routines
**
**	Defines:
**		stripquotes
**		xalloc
**		any
*/
/*
E 3
**  STRIPQUOTES -- Strip quotes & quote bits from a string.
**
**	Runs through a string and strips off unquoted quote
**	characters and quote bits.  This is done in place.
**
**	Parameters:
**		s -- the string to strip.
I 12
**		qf -- if set, remove actual `` " '' characters
**			as well as the quote bits.
E 12
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
**
D 3
**	Requires:
**		none.
**
E 3
**	Called By:
**		deliver
D 3
**
**	History:
**		3/5/80 -- written.
E 3
*/

D 12
stripquotes(s)
E 12
I 12
stripquotes(s, qf)
E 12
	char *s;
I 12
	bool qf;
E 12
{
	register char *p;
	register char *q;
	register char c;

I 12
	if (s == NULL)
		return;

E 12
	for (p = q = s; (c = *p++) != '\0'; )
	{
D 12
		if (c != '"')
E 12
I 12
		if (c != '"' || !qf)
E 12
			*q++ = c & 0177;
	}
	*q = '\0';
}
/*
I 40
**  QSTRLEN -- give me the string length assuming 0200 bits add a char
**
**	Parameters:
**		s -- the string to measure.
**
**	Reurns:
**		The length of s, including space for backslash escapes.
**
**	Side Effects:
**		none.
*/

qstrlen(s)
	register char *s;
{
	register int l = 0;
	register char c;

	while ((c = *s++) != '\0')
	{
		if (bitset(0200, c))
			l++;
		l++;
	}
	return (l);
}
/*
E 40
I 6
**  CAPITALIZE -- return a copy of a string, properly capitalized.
**
**	Parameters:
**		s -- the string to capitalize.
**
**	Returns:
**		a pointer to a properly capitalized string.
**
**	Side Effects:
**		none.
*/

char *
capitalize(s)
	register char *s;
{
	static char buf[50];
	register char *p;

	p = buf;

	for (;;)
	{
		while (!isalpha(*s) && *s != '\0')
			*p++ = *s++;
		if (*s == '\0')
			break;
		*p++ = toupper(*s++);
		while (isalpha(*s))
			*p++ = *s++;
	}

	*p = '\0';
	return (buf);
}
/*
E 6
**  XALLOC -- Allocate memory and bitch wildly on failure.
**
**	THIS IS A CLUDGE.  This should be made to give a proper
**	error -- but after all, what can we do?
**
**	Parameters:
**		sz -- size of area to allocate.
**
**	Returns:
**		pointer to data region.
**
**	Side Effects:
**		Memory is allocated.
D 6
**
D 3
**	Requires:
**		malloc
**		syserr
**		exit
**
E 3
**	Called By:
**		lots of people.
E 6
D 3
**
**	History:
**		12/31/79 -- written.
E 3
*/

char *
xalloc(sz)
D 23
	register unsigned int sz;
E 23
I 23
	register int sz;
E 23
{
	register char *p;
I 67
	extern char *malloc();
E 67
D 11
	extern char *malloc();
E 11

D 67
	p = malloc(sz);
E 67
I 67
	p = malloc((unsigned) sz);
E 67
	if (p == NULL)
	{
		syserr("Out of memory!!");
D 4
		exit(EX_UNAVAIL);
E 4
I 4
D 49
		exit(EX_UNAVAILABLE);
E 49
I 49
		abort();
		/* exit(EX_UNAVAILABLE); */
E 49
E 4
	}
I 6
	return (p);
}
/*
D 47
**  NEWSTR -- make copy of string.
**
**	Space is allocated for it using xalloc.
**
**	Parameters:
**		string to copy.
**
**	Returns:
**		pointer to new string.
**
**	Side Effects:
**		none.
*/

char *
newstr(s)
	register char *s;
{
	register char *p;
I 8
D 11
	extern char *strcpy();
E 11
E 8

D 8
	p = xalloc(strlen(s) + 1);
E 8
I 8
D 23
	p = xalloc((unsigned) (strlen(s) + 1));
E 8
	strcpy(p, s);
E 23
I 23
	p = xalloc(strlen(s) + 1);
	(void) strcpy(p, s);
E 23
E 6
	return (p);
I 9
}
/*
E 47
**  COPYPLIST -- copy list of pointers.
**
**	This routine is the equivalent of newstr for lists of
**	pointers.
**
**	Parameters:
**		list -- list of pointers to copy.
**			Must be NULL terminated.
**		copycont -- if TRUE, copy the contents of the vector
**			(which must be a string) also.
**
**	Returns:
**		a copy of 'list'.
**
**	Side Effects:
**		none.
*/

char **
copyplist(list, copycont)
	char **list;
	bool copycont;
{
	register char **vp;
	register char **newvp;
D 11
	extern char *xalloc();
E 11

	for (vp = list; *vp != NULL; vp++)
		continue;

	vp++;

D 11
	newvp = (char **) xalloc((vp - list) * sizeof *vp);
	bmove(list, newvp, (vp - list) * sizeof *vp);
E 11
I 11
D 23
	newvp = (char **) xalloc((unsigned) (vp - list) * sizeof *vp);
E 23
I 23
D 59
	newvp = (char **) xalloc((vp - list) * sizeof *vp);
E 23
D 58
	bmove((char *) list, (char *) newvp, (vp - list) * sizeof *vp);
E 58
I 58
	bcopy((char *) list, (char *) newvp, (vp - list) * sizeof *vp);
E 59
I 59
	newvp = (char **) xalloc((int) (vp - list) * sizeof *vp);
	bcopy((char *) list, (char *) newvp, (int) (vp - list) * sizeof *vp);
E 59
E 58
E 11

	if (copycont)
	{
		for (vp = newvp; *vp != NULL; vp++)
			*vp = newstr(*vp);
	}

	return (newvp);
}
/*
**  PRINTAV -- print argument vector.
**
**	Parameters:
**		av -- argument vector.
**
**	Returns:
**		none.
**
**	Side Effects:
**		prints av.
*/

D 62
# ifdef DEBUG
E 62
printav(av)
	register char **av;
{
	while (*av != NULL)
	{
D 38
		printf("\t%08x=", *av);
E 38
I 38
		if (tTd(0, 44))
			printf("\n\t%08x=", *av);
		else
D 66
			putchar(' ');
E 66
I 66
			(void) putchar(' ');
E 66
E 38
		xputs(*av++);
D 38
		putchar('\n');
E 38
	}
I 38
D 66
	putchar('\n');
E 66
I 66
	(void) putchar('\n');
E 66
E 38
}
D 62
# endif DEBUG
E 62
/*
**  LOWER -- turn letter into lower case.
**
**	Parameters:
**		c -- character to turn into lower case.
**
**	Returns:
**		c, in lower case.
**
**	Side Effects:
**		none.
*/

char
lower(c)
	register char c;
{
	if (isascii(c) && isupper(c))
		c = c - 'A' + 'a';
	return (c);
}
/*
**  XPUTS -- put string doing control escapes.
**
**	Parameters:
**		s -- string to put.
**
**	Returns:
**		none.
**
**	Side Effects:
**		output to stdout
*/

D 62
# ifdef DEBUG
E 62
xputs(s)
	register char *s;
{
	register char c;

I 37
	if (s == NULL)
	{
		printf("<null>");
		return;
	}
I 38
D 66
	putchar('"');
E 66
I 66
	(void) putchar('"');
E 66
E 38
E 37
	while ((c = *s++) != '\0')
	{
		if (!isascii(c))
		{
D 66
			putchar('\\');
E 66
I 66
			(void) putchar('\\');
E 66
			c &= 0177;
		}
D 48
		if (iscntrl(c))
E 48
I 48
		if (c < 040 || c >= 0177)
E 48
		{
D 66
			putchar('^');
E 66
I 66
			(void) putchar('^');
E 66
D 48
			c |= 0100;
E 48
I 48
			c ^= 0100;
E 48
		}
D 66
		putchar(c);
E 66
I 66
		(void) putchar(c);
E 66
	}
I 38
D 66
	putchar('"');
E 66
I 66
	(void) putchar('"');
E 66
E 38
D 11
	fflush(stdout);
E 11
I 11
	(void) fflush(stdout);
E 11
}
D 62
# endif DEBUG
E 62
/*
**  MAKELOWER -- Translate a line into lower case
**
**	Parameters:
**		p -- the string to translate.  If NULL, return is
**			immediate.
**
**	Returns:
**		none.
**
**	Side Effects:
**		String pointed to by p is translated to lower case.
**
**	Called By:
**		parse
*/

makelower(p)
	register char *p;
{
	register char c;

	if (p == NULL)
		return;
	for (; (c = *p) != '\0'; p++)
		if (isascii(c) && isupper(c))
			*p = c - 'A' + 'a';
E 9
}
I 10
/*
**  SAMEWORD -- return TRUE if the words are the same
**
**	Ignores case.
**
**	Parameters:
**		a, b -- the words to compare.
**
**	Returns:
**		TRUE if a & b match exactly (modulo case)
**		FALSE otherwise.
**
**	Side Effects:
**		none.
*/

bool
sameword(a, b)
	register char *a, *b;
{
D 60
	while (lower(*a) == lower(*b))
E 60
I 60
	char ca, cb;

	do
E 60
	{
D 60
		if (*a == '\0')
			return (TRUE);
		a++;
		b++;
	}
	return (FALSE);
E 60
I 60
		ca = *a++;
		cb = *b++;
		if (isascii(ca) && isupper(ca))
			ca = ca - 'A' + 'a';
		if (isascii(cb) && isupper(cb))
			cb = cb - 'A' + 'a';
	} while (ca != '\0' && ca == cb);
	return (ca == cb);
E 60
I 12
D 58
}
/*
**  CLEAR -- clear a block of memory
**
**	Parameters:
**		p -- location to clear.
**		l -- number of bytes to clear.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

clear(p, l)
	register char *p;
	register int l;
{
	while (l-- > 0)
		*p++ = 0;
E 58
E 12
}
I 11
/*
I 13
D 19
**  BUILDFNAME -- build full name from gecos style entry.
E 19
I 19
**  FULLNAME -- extract full name from a passwd file entry.
E 19
**
D 19
**	This routine interprets the strange entry that would appear
**	in the GECOS field of the password file.
**
E 19
**	Parameters:
D 19
**		p -- name to build.
**		login -- the login name of this user (for &).
**		buf -- place to put the result.
E 19
I 19
**		pw -- password entry to start from.
**		buf -- buffer to store result in.
E 19
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

D 19
buildfname(p, login, buf)
	register char *p;
	char *login;
E 19
I 19
fullname(pw, buf)
	register struct passwd *pw;
E 19
	char *buf;
{
	register char *bp = buf;
I 19
	register char *p = pw->pw_gecos;
E 19

I 15
	if (*p == '*')
		p++;
E 15
D 21
	while (*p != '\0' && *p != ',' && *p != ';')
E 21
I 21
	while (*p != '\0' && *p != ',' && *p != ';' && *p != '%')
E 21
	{
		if (*p == '&')
		{
D 19
			(void) strcpy(bp, login);
E 19
I 19
			(void) strcpy(bp, pw->pw_name);
E 19
			*bp = toupper(*bp);
			while (*bp != '\0')
				bp++;
			p++;
		}
		else
			*bp++ = *p++;
	}
	*bp = '\0';
I 16
}
/*
**  SAFEFILE -- return true if a file exists and is safe for a user.
**
**	Parameters:
**		fn -- filename to check.
**		uid -- uid to compare against.
**		mode -- mode bits that must match.
**
**	Returns:
**		TRUE if fn exists, is owned by uid, and matches mode.
**		FALSE otherwise.
**
**	Side Effects:
**		none.
*/

bool
safefile(fn, uid, mode)
	char *fn;
	int uid;
	int mode;
{
	struct stat stbuf;

	if (stat(fn, &stbuf) >= 0 && stbuf.st_uid == uid &&
	    (stbuf.st_mode & mode) == mode)
		return (TRUE);
I 51
	errno = 0;
E 51
	return (FALSE);
E 16
}
/*
I 17
**  FIXCRLF -- fix <CR><LF> in line.
**
**	Looks for the <CR><LF> combination and turns it into the
**	UNIX canonical <NL> character.  It only takes one line,
**	i.e., it is assumed that the first <NL> found is the end
**	of the line.
**
**	Parameters:
**		line -- the line to fix.
**		stripnl -- if true, strip the newline also.
**
**	Returns:
**		none.
**
**	Side Effects:
**		line is changed in place.
*/

fixcrlf(line, stripnl)
	char *line;
	bool stripnl;
{
	register char *p;

	p = index(line, '\n');
	if (p == NULL)
		return;
D 18
	if (*p == '\r')
E 18
I 18
	if (p[-1] == '\r')
E 18
		p--;
	if (!stripnl)
		*p++ = '\n';
	*p = '\0';
}
/*
E 17
E 13
D 61
**  SYSLOG -- fake entry to fool lint
*/

# ifdef LOG
# ifdef lint

/*VARARGS2*/
syslog(pri, fmt, args)
	int pri;
	char *fmt;
{
	pri = *fmt;
	args = pri;
	pri = args;
}

# endif lint
# endif LOG
I 22
/*
E 61
**  DFOPEN -- determined file open
**
**	This routine has the semantics of fopen, except that it will
**	keep trying a few times to make this happen.  The idea is that
**	on very loaded systems, we may run out of resources (inodes,
**	whatever), so this tries to get around it.
*/

FILE *
dfopen(filename, mode)
	char *filename;
	char *mode;
{
	register int tries;
	register FILE *fp;
D 42
	extern int errno;
E 42

	for (tries = 0; tries < 10; tries++)
	{
D 70
		sleep(10 * tries);
E 70
I 70
		sleep((unsigned) (10 * tries));
E 70
		errno = 0;
		fp = fopen(filename, mode);
D 42
		if (fp != NULL || errno != ENFILE)
E 42
I 42
		if (fp != NULL)
E 42
			break;
I 42
		if (errno != ENFILE && errno != EINTR)
			break;
E 42
	}
I 51
	errno = 0;
E 51
	return (fp);
}
I 24
/*
**  PUTLINE -- put a line like fputs obeying SMTP conventions
**
I 30
**	This routine always guarantees outputing a newline (or CRLF,
**	as appropriate) at the end of the string.
**
E 30
**	Parameters:
**		l -- line to put.
**		fp -- file to put it onto.
I 45
D 46
**		crlf -- if set, output Carriage Return/Line Feed on lines
**			instead of newline.
E 45
**		fullsmtp -- if set, obey strictest SMTP conventions.
E 46
I 46
**		m -- the mailer used to control output.
E 46
**
**	Returns:
**		none
**
**	Side Effects:
**		output of l to fp.
*/

D 30
# define SMTPLINELIM	120	/* maximum line length */
E 30
I 30
# define SMTPLINELIM	990	/* maximum line length */
E 30

D 45
putline(l, fp, fullsmtp)
E 45
I 45
D 46
putline(l, fp, crlf, fullsmtp)
E 46
I 46
putline(l, fp, m)
E 46
E 45
D 30
	char *l;
E 30
I 30
	register char *l;
E 30
	FILE *fp;
I 45
D 46
	bool crlf;
E 45
	bool fullsmtp;
E 46
I 46
	MAILER *m;
E 46
{
	register char *p;
I 30
	char svchar;
I 46
D 47
	char *crlfstring = "\r\n";
E 47
E 46
E 30
D 25
	char s1, s2;
E 25

I 50
	/* strip out 0200 bits -- these can look like TELNET protocol */
	if (bitnset(M_LIMITS, m->m_flags))
	{
		p = l;
		while ((*p++ &= ~0200) != 0)
			continue;
	}

E 50
I 46
D 47
	if (!bitset(M_CRLF, m->m_flags))
		crlfstring++;

E 47
E 46
D 30
	if (!fullsmtp)
E 30
I 30
	do
E 30
	{
D 30
		fputs(l, fp);
		return;
	}
E 30
I 30
		/* find the end of the line */
		p = index(l, '\n');
		if (p == NULL)
			p = &l[strlen(l)];
E 30

D 30
	/* find the end of the line */
D 25
	p = index('\n', l);
E 25
I 25
	p = index(l, '\n');
E 25
	if (p == NULL)
		p = &l[strlen(l)];
E 30
I 30
		/* check for line overflow */
D 46
		while (fullsmtp && (p - l) > SMTPLINELIM)
E 46
I 46
D 49
		while (bitset(M_LIMITS, m->m_flags) && (p - l) > SMTPLINELIM)
E 49
I 49
D 50
		while (bitnset(M_LIMITS, m->m_flags) && (p - l) > SMTPLINELIM)
E 50
I 50
		while ((p - l) > SMTPLINELIM && bitnset(M_LIMITS, m->m_flags))
E 50
E 49
E 46
		{
			register char *q = &l[SMTPLINELIM - 1];
E 30

D 30
	/* check for line overflow */
	while (p - l > SMTPLINELIM)
	{
		register char *q = &l[SMTPLINELIM - 1];
		char svchar = *q;
E 30
I 30
			svchar = *q;
			*q = '\0';
I 46
D 49
			if (l[0] == '.' && bitset(M_XDOT, m->m_flags))
E 49
I 49
			if (l[0] == '.' && bitnset(M_XDOT, m->m_flags))
E 49
D 66
				fputc('.', fp);
E 66
I 66
				(void) putc('.', fp);
E 66
E 46
			fputs(l, fp);
D 45
			fputs("!\r\n", fp);
E 45
I 45
D 66
			fputc('!', fp);
E 66
I 66
			(void) putc('!', fp);
E 66
D 46
			if (crlf)
				fputc('\r', fp);
			fputc('\n', fp);
E 46
I 46
D 47
			fputs(crlfstring, fp);
E 47
I 47
D 48
			fputs(crlf(m), fp);
E 48
I 48
			fputs(m->m_eol, fp);
E 48
E 47
E 46
E 45
			*q = svchar;
			l = q;
		}
E 30

D 30
		*q = '\0';
E 30
I 30
		/* output last part */
		svchar = *p;
		*p = '\0';
I 46
D 49
		if (l[0] == '.' && bitset(M_XDOT, m->m_flags))
E 49
I 49
		if (l[0] == '.' && bitnset(M_XDOT, m->m_flags))
E 49
D 66
			fputc('.', fp);
E 66
I 66
			(void) putc('.', fp);
E 66
E 46
E 30
		fputs(l, fp);
D 30
		fputs("!\r\n", fp);
		*q = svchar;
		l = q;
	}

	/* output last part */
	*p = '\0';
	fputs(l, fp);
	fputs("\r\n", fp);
	*p = '\n';
E 30
I 30
D 45
		if (fullsmtp)
E 45
I 45
D 46
		if (crlf)
E 45
			fputc('\r', fp);
		fputc('\n', fp);
E 46
I 46
D 47
		fputs(crlfstring, fp);
E 47
I 47
D 48
		fputs(crlf(m), fp);
E 48
I 48
		fputs(m->m_eol, fp);
E 48
E 47
E 46
		*p = svchar;
		l = p;
		if (*l == '\n')
			l++;
	} while (l[0] != '\0');
E 30
}
I 28
/*
**  XUNLINK -- unlink a file, doing logging as appropriate.
**
**	Parameters:
**		f -- name of file to unlink.
**
**	Returns:
**		none.
**
**	Side Effects:
**		f is unlinked.
*/

xunlink(f)
	char *f;
{
	register int i;

# ifdef LOG
	if (LogLevel > 20)
D 32
		syslog(LOG_DEBUG, "%s: unlink %s\n", MsgId, f);
E 32
I 32
		syslog(LOG_DEBUG, "%s: unlink %s\n", CurEnv->e_id, f);
E 32
# endif LOG

	i = unlink(f);
# ifdef LOG
	if (i < 0 && LogLevel > 21)
D 36
		syslog(LOG_DEBUG, "%s: unlink-fail %e");
E 36
I 36
		syslog(LOG_DEBUG, "%s: unlink-fail %d", f, errno);
E 36
# endif LOG
}
I 29
/*
D 53
**  SFGETS -- "safe" fgets -- times out.
E 53
I 53
**  SFGETS -- "safe" fgets -- times out and ignores random interrupts.
E 53
**
**	Parameters:
**		buf -- place to put the input line.
**		siz -- size of buf.
**		fp -- file to read from.
**
**	Returns:
D 54
**		NULL on error (including timeout).
E 54
I 54
**		NULL on error (including timeout).  This will also leave
**			buf containing a null string.
E 54
**		buf otherwise.
**
**	Side Effects:
**		none.
*/

D 36
jmp_buf	TimeoFrame;
E 36
I 36
D 53
static bool	TimeoutFlag;
E 53
I 53
static jmp_buf	CtxReadTimeout;
E 53
E 36

I 56
#ifndef ETIMEDOUT
#define ETIMEDOUT	EINTR
#endif

E 56
char *
sfgets(buf, siz, fp)
	char *buf;
	int siz;
	FILE *fp;
{
D 36
	register EVENT *ev;
E 36
I 36
	register EVENT *ev = NULL;
E 36
	register char *p;
	extern readtimeout();

I 53
	/* set the timeout */
E 53
D 34
	ev = setevent(ReadTimeout, readtimeout, 0);
E 34
D 36
	if (setjmp(TimeoFrame) != 0)
		return (NULL);
I 34
	ev = setevent(ReadTimeout, readtimeout, 0);
E 34
	p = fgets(buf, siz, fp);
E 36
I 36
	if (ReadTimeout != 0)
I 53
	{
		if (setjmp(CtxReadTimeout) != 0)
		{
I 56
			errno = ETIMEDOUT;
E 56
D 68
			syserr("sfgets: timeout on read (mailer may be hung)");
E 68
I 68
D 69
			if (RealHostName == NULL)
				syserr("timeout on read");
			else
				syserr("net timeout reading from %s", RealHostName);
			errno = ETIMEDOUT;
E 69
I 69
			syserr("net timeout");
E 69
E 68
I 62
			buf[0] = '\0';
E 62
			return (NULL);
		}
E 53
D 56
		ev = setevent(ReadTimeout, readtimeout, 0);
E 56
I 56
		ev = setevent((time_t) ReadTimeout, readtimeout, 0);
E 56
D 53
	TimeoutFlag = FALSE;
E 53
I 53
	}

	/* try to read */
E 53
D 54
	do
E 54
I 54
	p = NULL;
	while (p == NULL && !feof(fp) && !ferror(fp))
E 54
	{
		errno = 0;
		p = fgets(buf, siz, fp);
D 53
	} while (!(p != NULL || TimeoutFlag || errno != EINTR));
E 53
I 53
D 54
	} while (p == NULL && errno == EINTR);
E 54
I 54
		if (errno == EINTR)
			clearerr(fp);
	}
E 54

	/* clear the event if it has not sprung */
E 53
E 36
	clrevent(ev);
I 53

	/* clean up the books and exit */
E 53
I 37
	LineNumber++;
I 54
	if (p == NULL)
I 57
	{
E 57
		buf[0] = '\0';
E 54
I 43
D 53
	if (TimeoutFlag)
		syserr("sfgets: timeout on read (mailer may be hung)");
E 53
E 43
E 37
D 57
	return (p);
E 57
I 57
		return (NULL);
	}
	for (p = buf; *p != '\0'; p++)
		*p &= ~0200;
	return (buf);
E 57
}

static
readtimeout()
{
D 36
	longjmp(TimeoFrame, 1);
E 36
I 36
D 53
	TimeoutFlag = TRUE;
E 53
I 53
	longjmp(CtxReadTimeout, 1);
E 53
E 36
}
I 31
/*
**  FGETFOLDED -- like fgets, but know about folded lines.
**
**	Parameters:
**		buf -- place to put result.
**		n -- bytes available.
**		f -- file to read from.
**
**	Returns:
**		buf on success, NULL on error or EOF.
**
**	Side Effects:
**		buf gets lines from f, with continuation lines (lines
**		with leading white space) appended.  CRLF's are mapped
**		into single newlines.  Any trailing NL is stripped.
*/

char *
fgetfolded(buf, n, f)
	char *buf;
	register int n;
	FILE *f;
{
	register char *p = buf;
	register int i;

	n--;
D 37
	while (fgets(p, n, f) != NULL)
E 37
I 37
D 44
	while (sfgets(p, n, f) != NULL)
E 44
I 44
D 60
	while (fgets(p, n, f) != NULL)
E 60
I 60
	while ((i = getc(f)) != EOF)
E 60
E 44
E 37
	{
I 44
D 60
		LineNumber++;
E 44
		fixcrlf(p, TRUE);
		i = fgetc(f);
		if (i != EOF)
			ungetc(i, f);
		if (i != ' ' && i != '\t')
			return (buf);
		i = strlen(p);
		p += i;
		*p++ = '\n';
		n -= i + 1;
E 60
I 60
		if (i == '\r')
		{
			i = getc(f);
			if (i != '\n')
			{
				if (i != EOF)
D 66
					ungetc(i, f);
E 66
I 66
					(void) ungetc(i, f);
E 66
				i = '\r';
			}
		}
		if (--n > 0)
			*p++ = i;
		if (i == '\n')
		{
			LineNumber++;
			i = getc(f);
			if (i != EOF)
D 66
				ungetc(i, f);
E 66
I 66
				(void) ungetc(i, f);
E 66
			if (i != ' ' && i != '\t')
			{
				*--p = '\0';
				return (buf);
			}
		}
E 60
	}
	return (NULL);
}
I 33
/*
D 42
**  PINTVL -- produce printable version of a time interval
**
**	Parameters:
**		intvl -- the interval to be converted
**		brief -- if TRUE, print this in an extremely compact form
**			(basically used for logging).
**
**	Returns:
**		A pointer to a string version of intvl suitable for
**			printing or framing.
**
**	Side Effects:
**		none.
**
**	Warning:
**		The string returned is in a static buffer.
*/

# define PLURAL(n)	((n) == 1 ? "" : "s")

char *
pintvl(intvl, brief)
	time_t intvl;
	bool brief;
{
	static char buf[MAXNAME];
	register char *p;
	int wk, dy, hr, mi, se;

	if (intvl == 0 && !brief)
		return ("zero seconds");

	/* decode the interval into weeks, days, hours, minutes, seconds */
	se = intvl % 60;
	intvl /= 60;
	mi = intvl % 60;
	intvl /= 60;
	hr = intvl % 24;
	intvl /= 24;
	if (brief)
		dy = intvl;
	else
	{
		dy = intvl % 7;
		intvl /= 7;
		wk = intvl;
	}

	/* now turn it into a sexy form */
	p = buf;
	if (brief)
	{
		if (dy > 0)
		{
			(void) sprintf(p, "%d+", dy);
			p += strlen(p);
		}
		(void) sprintf(p, "%02d:%02d:%02d", hr, mi, se);
		return (buf);
	}

	/* use the verbose form */
	if (wk > 0)
	{
		(void) sprintf(p, ", %d week%s", wk, PLURAL(wk));
		p += strlen(p);
	}
	if (dy > 0)
	{
		(void) sprintf(p, ", %d day%s", dy, PLURAL(dy));
		p += strlen(p);
	}
	if (hr > 0)
	{
		(void) sprintf(p, ", %d hour%s", hr, PLURAL(hr));
		p += strlen(p);
	}
	if (mi > 0)
	{
		(void) sprintf(p, ", %d minute%s", mi, PLURAL(mi));
		p += strlen(p);
	}
	if (se > 0)
	{
		(void) sprintf(p, ", %d second%s", se, PLURAL(se));
		p += strlen(p);
	}

	return (buf + 2);
}
I 35
/*
E 42
**  CURTIME -- return current time.
**
**	Parameters:
**		none.
**
**	Returns:
**		the current time.
**
**	Side Effects:
**		none.
*/

time_t
curtime()
{
	auto time_t t;

	(void) time(&t);
	return (t);
}
I 39
/*
**  ATOBOOL -- convert a string representation to boolean.
**
**	Defaults to "TRUE"
**
**	Parameters:
**		s -- string to convert.  Takes "tTyY" as true,
**			others as false.
**
**	Returns:
**		A boolean representation of the string.
**
**	Side Effects:
**		none.
*/

bool
atobool(s)
	register char *s;
{
	if (*s == '\0' || index("tTyY", *s) != NULL)
		return (TRUE);
	return (FALSE);
}
I 41
/*
**  ATOOCT -- convert a string representation to octal.
**
**	Parameters:
**		s -- string to convert.
**
**	Returns:
**		An integer representing the string interpreted as an
**		octal number.
**
**	Side Effects:
**		none.
*/

atooct(s)
	register char *s;
{
	register int i = 0;

	while (*s >= '0' && *s <= '7')
		i = (i << 3) | (*s++ - '0');
	return (i);
I 42
}
/*
**  WAITFOR -- wait for a particular process id.
**
**	Parameters:
**		pid -- process id to wait for.
**
**	Returns:
**		status of pid.
**		-1 if pid never shows up.
**
**	Side Effects:
**		none.
*/

waitfor(pid)
	int pid;
{
	auto int st;
	int i;

	do
	{
		errno = 0;
		i = wait(&st);
	} while ((i >= 0 || errno == EINTR) && i != pid);
	if (i < 0)
		st = -1;
	return (st);
}
/*
D 55
**  CLOSEALL -- close all extraneous file descriptors
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Closes all file descriptors except zero, one, and two.
*/

closeall()
{
	int i;

	for (i = 3; i < 50; i++)
		(void) close(i);
I 49
}
/*
E 55
**  BITINTERSECT -- tell if two bitmaps intersect
**
**	Parameters:
**		a, b -- the bitmaps in question
**
**	Returns:
**		TRUE if they have a non-null intersection
**		FALSE otherwise
**
**	Side Effects:
**		none.
*/

bool
bitintersect(a, b)
	BITMAP a;
	BITMAP b;
{
	int i;

	for (i = BITMAPBYTES / sizeof (int); --i >= 0; )
		if ((a[i] & b[i]) != 0)
			return (TRUE);
	return (FALSE);
}
/*
**  BITZEROP -- tell if a bitmap is all zero
**
**	Parameters:
**		map -- the bit map to check
**
**	Returns:
**		TRUE if map is all zero.
**		FALSE if there are any bits set in map.
**
**	Side Effects:
**		none.
*/

bool
bitzerop(map)
	BITMAP map;
{
	int i;

	for (i = BITMAPBYTES / sizeof (int); --i >= 0; )
		if (map[i] != 0)
			return (FALSE);
	return (TRUE);
E 49
E 42
}
E 41
E 39
E 35
E 33
E 31
E 29
E 28
I 26
D 27
/*
**  TICK -- take a clock tick
**
**	Someday this will have to do more complex event scheduling.
**
**	Parameters:
**		none.
**
**	Returns:
**		non-local through TickFrame.
**
**	Side Effects:
**		none.
*/

tick()
{
# ifdef DEBUG
	if (Debug > 0)
		printf("tick\n");
# endif DEBUG
	longjmp(TickFrame, 1);
}
E 27
E 26
E 24
E 22
E 11
E 10
D 7
/*
**  ANY -- Return TRUE if the character exists in the string.
**
**	Parameters:
**		c -- the character.
**		s -- the string
**			(sounds like an avant garde script)
**
**	Returns:
**		TRUE -- if c could be found in s.
**		FALSE -- otherwise.
**
**	Side Effects:
**		none.
**
D 3
**	Requires:
**		none.
**
E 3
**	Called By:
**		prescan
D 3
**
**	History:
**		3/5/80 -- written.
E 3
*/

any(c, s)
	register char c;
	register char *s;
{
	register char c2;

	while ((c2 = *s++) != '\0')
		if (c2 == c)
			return (TRUE);
	return (FALSE);
}
E 7
E 1
