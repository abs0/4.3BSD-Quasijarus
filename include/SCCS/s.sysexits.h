h26808
s 00010/00005/00092
d D 4.5 88/07/06 09:57:56 bostic 9 8
m 
c install approved copyright notice
e
s 00001/00000/00096
d D 4.4 88/03/24 14:58:23 bostic 8 7
m 
c add EX_CONFIG for configuration error
e
s 00014/00000/00082
d D 4.3 87/12/15 15:49:02 bostic 7 6
m 
c add Berkeley header
e
s 00007/00000/00075
d D 4.2 83/07/31 10:42:39 eric 6 5
m 
c Add EX_NOPERM for kre
e
s 00000/00000/00075
d D 4.1 83/07/25 19:10:43 eric 5 4
m 
c 4.2 release version
e
s 00005/00002/00070
d D 3.1 82/08/29 17:33:08 eric 4 3
c fix serious botch in SMTP reply code delta; change a bunch of
c "Internal error" codes to a new "Remote protocol error" -- so that
c I don't get blamed for things that other systems do.
e
s 00002/00000/00070
d D 1.3 81/10/15 20:36:32 eric 3 2
c really add id keywords.
e
s 00008/00000/00062
d D 1.2 81/10/15 20:35:35 eric 2 1
c add EX_TEMPFAIL (and id keywords)
e
s 00062/00000/00000
d D 1.1 81/10/15 20:29:54 eric 1 0
c date and time created 81/10/15 20:29:54 by eric
e
u
U
f b 
f i 
f v 
t
T
I 1
/*
I 7
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
 *
 *	%W% (Berkeley) %G%
 */

/*
E 7
**  SYSEXITS.H -- Exit status codes for system programs.
**
**	This include file attempts to categorize possible error
**	exit statuses for system programs, notably delivermail
**	and the Berkeley network.
**
**	Error numbers begin at EX__BASE to reduce the possibility of
**	clashing with other exit statuses that random programs may
**	already return.  The meaning of the codes is approximately
**	as follows:
**
**	EX_USAGE -- The command was used incorrectly, e.g., with
**		the wrong number of arguments, a bad flag, a bad
**		syntax in a parameter, or whatever.
**	EX_DATAERR -- The input data was incorrect in some way.
**		This should only be used for user's data & not
**		system files.
**	EX_NOINPUT -- An input file (not a system file) did not
**		exist or was not readable.  This could also include
**		errors like "No message" to a mailer (if it cared
**		to catch it).
**	EX_NOUSER -- The user specified did not exist.  This might
**		be used for mail addresses or remote logins.
**	EX_NOHOST -- The host specified did not exist.  This is used
**		in mail addresses or network requests.
**	EX_UNAVAILABLE -- A service is unavailable.  This can occur
**		if a support program or file does not exist.  This
**		can also be used as a catchall message when something
**		you wanted to do doesn't work, but you don't know
**		why.
**	EX_SOFTWARE -- An internal software error has been detected.
**		This should be limited to non-operating system related
**		errors as possible.
**	EX_OSERR -- An operating system error has been detected.
**		This is intended to be used for such things as "cannot
**		fork", "cannot create pipe", or the like.  It includes
**		things like getuid returning a user that does not
**		exist in the passwd file.
**	EX_OSFILE -- Some system file (e.g., /etc/passwd, /etc/utmp,
**		etc.) does not exist, cannot be opened, or has some
**		sort of error (e.g., syntax error).
**	EX_CANTCREAT -- A (user specified) output file cannot be
**		created.
**	EX_IOERR -- An error occurred while doing I/O on some file.
I 2
**	EX_TEMPFAIL -- temporary failure, indicating something that
**		is not really an error.  In sendmail, this means
**		that a mailer (e.g.) could not create a connection,
**		and the request should be reattempted later.
I 4
**	EX_PROTOCOL -- the remote system returned something that
**		was "not possible" during a protocol exchange.
I 6
**	EX_NOPERM -- You did not have sufficient permission to
**		perform the operation.  This is not intended for
**		file system problems, which should use NOINPUT or
**		CANTCREAT, but rather for higher level permissions.
**		For example, kre uses this to restrict who students
**		can send mail to.
E 6
E 4
**
D 4
**	Maintained by IngVAX:eric (eric@berkeley, ucbvax!eric) --
E 4
I 4
**	Maintained by Eric Allman (eric@berkeley, ucbvax!eric) --
E 4
**		please mail changes to me.
I 3
**
D 4
**			%W%	%G%
E 4
I 4
**			%W%	%Y%	%G%
E 4
E 3
E 2
*/

# define EX_OK		0	/* successful termination */

# define EX__BASE	64	/* base value for error messages */

# define EX_USAGE	64	/* command line usage error */
# define EX_DATAERR	65	/* data format error */
# define EX_NOINPUT	66	/* cannot open input */
# define EX_NOUSER	67	/* addressee unknown */
# define EX_NOHOST	68	/* host name unknown */
# define EX_UNAVAILABLE	69	/* service unavailable */
# define EX_SOFTWARE	70	/* internal software error */
# define EX_OSERR	71	/* system error (e.g., can't fork) */
# define EX_OSFILE	72	/* critical OS file missing */
# define EX_CANTCREAT	73	/* can't create (user) output file */
# define EX_IOERR	74	/* input/output error */
I 2
# define EX_TEMPFAIL	75	/* temp failure; user is invited to retry */
I 4
# define EX_PROTOCOL	76	/* remote error in protocol */
I 6
# define EX_NOPERM	77	/* permission denied */
I 8
# define EX_CONFIG	78	/* configuration error */
E 8
E 6
E 4
E 2
E 1
