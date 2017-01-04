h63283
s 00004/00000/00953
d D 5.16 04/11/21 08:41:39 msokolov 92 91
c implement ability to globally limit message size in collect phase (l option)
e
s 00004/00000/00949
d D 5.15 04/04/23 15:28:54 msokolov 91 90
c add R option to disable relaying service for Internet senders
e
s 00004/00000/00945
d D 5.14 88/09/20 22:15:24 eric 90 89
c add I option to insist on Internet domain server; add NAMED_BIND
c compile option to compile in named routines.
e
s 00011/00009/00934
d D 5.13 88/06/30 14:59:29 bostic 89 88
c install approved copyright notice
e
s 00001/00009/00942
d D 5.12 88/04/01 16:50:58 bostic 88 87
c remove V6 #ifdefs
e
s 00016/00010/00935
d D 5.11 88/03/13 19:52:50 bostic 87 86
c add Berkeley specific header
e
s 00004/00000/00941
d D 5.10 86/01/11 00:18:01 eric 86 85
c only check the RHS of aliases during newalias if the "n" option is set;
c this option should probably be set if you are not running the nameserver
e
s 00033/00003/00908
d D 5.9 86/01/10 15:49:22 eric 85 84
c allow multiple words per line in file classes; require a SCANF compilation
c flag to use sscanf in F specs in order to reduce image size
e
s 00009/00003/00902
d D 5.8 86/01/05 19:57:07 eric 84 83
m 
c cleanup for various compilation flags and reasonable organization
e
s 00001/00001/00904
d D 5.7 85/12/07 08:17:13 eric 83 82
m 
c several small bugs: don't die if no environment, don't look in
c ESM_DEADLETTER state in savemail; lowercase before getpwnam to
c allow upper case regular names in alias file
e
s 00013/00001/00892
d D 5.6 85/09/21 14:44:36 eric 82 81
m 
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00004/00000/00889
d D 5.5 85/09/19 12:18:01 eric 81 80
m 
c 'z' option now sets ForkQueueRuns
e
s 00000/00000/00889
d D 5.4 85/09/19 01:26:00 eric 80 78
i 79
m 
c incorporate SMI changes -- still experimental
e
s 00014/00004/00875
d D 5.3.1.1 85/09/19 00:56:23 eric 79 78
m 
c SMI changes (somewhat)
e
s 00003/00003/00876
d D 5.3 85/06/08 00:49:12 eric 78 77
m 
c lint
e
s 00000/00002/00879
d D 5.2 85/06/07 22:15:56 miriam 77 76
m 
c Resolve duplicate SccsId
e
s 00014/00000/00867
d D 5.1 85/06/07 15:09:07 dist 76 75
m 
c Add copyright
e
s 00015/00017/00852
d D 4.13 85/06/02 10:54:29 eric 75 74
x 74
m 
c plug another security hole with command line arguments
e
s 00006/00031/00838
d D 4.12 85/05/24 11:03:02 eric 74 73
m 
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00011/00005/00858
d D 4.11 85/02/15 09:27:53 eric 73 72
m 
c fix some bugs with -C flag; one with queuing from Teus
e
s 00001/00001/00862
d D 4.10 85/02/14 22:43:17 eric 72 71
m 
c "and" file mode bits with 0777
e
s 00019/00011/00844
d D 4.9 84/12/05 23:16:04 eric 71 70
m 
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00003/00002/00852
d D 4.8 84/08/11 23:21:13 eric 70 69
m 
c Add $[ and $] as RHS operators to look up the contents and pass them
c to maphostname; maphostname currently looks them up in /etc/hosts and
c converts them to canonical form, but could be turned into a general
c name server.....   huzzah!!
e
s 00001/00001/00853
d D 4.7 84/08/11 16:57:26 eric 69 68
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00003/00002/00851
d D 4.6 84/08/11 14:37:25 eric 68 67
m 
c allow multiple -M flags -- fix from Liudvikas Bukys
e
s 00006/00000/00847
d D 4.5 84/08/05 11:01:06 eric 67 65
m 
c add B option to set blank substitution character
e
s 00000/00000/00847
d R 4.4.1.1 84/06/17 16:18:47 eric 66 65
m 
c abortive attempt to install a name server.... sigh.
e
s 00018/00000/00829
d D 4.4 84/03/11 16:56:28 eric 65 64
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00007/00000/00822
d D 4.3 84/03/11 16:12:36 eric 64 63
m 
c make network name configurable
e
s 00010/00000/00812
d D 4.2 83/08/28 14:45:50 eric 63 62
m 
c Refuse to talk to yourself (i.e., reject HELO packets with your own name).
c Add two thresholds -- option 'x' is the load average at which messages are
c queued rather than delivered (default 12); option 'X' is the load average
c at which incoming TCP connections are refused (default 25).
e
s 00000/00000/00812
d D 4.1 83/07/25 19:47:11 eric 62 61
m 
c 4.2 release version
e
s 00000/00009/00812
d D 3.59 83/07/13 10:38:29 eric 61 60
m 
c Delete "load limiting" for SMTP connections (a bad ethernet board can
c hang up all incoming mail); use sfgets in collect (same reason); check
c for I/O error in collect (from Bill Nowicki); switch date format to
c RFC822 style.
e
s 00001/00000/00820
d D 3.58 83/05/21 11:01:14 eric 60 59
m 
c Miscellaneous changes for PDP-11's.
c Always send to a login name before a full name.
e
s 00000/00001/00820
d D 3.57 83/04/30 15:15:27 eric 59 58
m 
c lint
e
s 00006/00004/00815
d D 3.56 83/02/08 10:49:54 eric 58 57
m 167
m 172
m 173
m 174
c clean up problems when QUEUE compile flag not defined; clean up hostname
c code to run on non-4.1c systems; fix use of -oeq (quiet on errors) flag.
e
s 00002/00001/00817
d D 3.55 83/02/03 10:29:38 eric 57 56
m 160
c $e macro is now SMTP entry message (so that configuration version can
c be included).
e
s 00005/00000/00813
d D 3.54 83/02/03 07:54:21 eric 56 55
m 168
c Make mailer size limits a per-mailer parameter (M field in the mailer
c descriptor)
e
s 00034/00126/00779
d D 3.53 83/02/02 12:53:58 eric 55 54
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00001/00001/00904
d D 3.52 83/01/17 12:32:10 eric 54 53
m 155
c fix bug that caused "\r\n" string in TCP mailer definition to turn
c into something else -- causing all TCP connections to hang.
e
s 00009/00000/00896
d D 3.51 83/01/16 17:27:43 eric 53 52
m 153
c make the maximum number of simultaneous SMTP connections an option
e
s 00189/00073/00707
d D 3.50 83/01/16 13:14:31 eric 52 51
m 152
c Change mailer spec to have labelled fields for future expansion.
c **** This delta invalidates previous configuration files ****
e
s 00017/00014/00763
d D 3.49 83/01/06 10:48:15 eric 51 50
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00057/00092/00720
d D 3.48 82/11/28 00:23:43 eric 50 49
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00002/00001/00810
d D 3.47 82/11/24 18:45:00 eric 49 48
m 
c lint it
e
s 00011/00004/00800
d D 3.46 82/11/24 17:16:40 eric 48 47
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00001/00000/00803
d D 3.45 82/11/21 17:19:34 eric 47 46
m 026
c preliminary hacks for multiple SMTP transactions per connection: make
c assignment of multiple queue id's more efficient, make prefixes two
c characters (e.g., qfAA99999), pass the file name to freeze and thaw,
c add a mailer flag saying we are talking to one of our own kind.
e
s 00013/00028/00790
d D 3.44 82/11/17 09:37:27 eric 46 45
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00005/00003/00813
d D 3.43 82/11/14 12:26:07 eric 45 44
m 072
c Don't give an error message on unknown options
e
s 00008/00001/00808
d D 3.42 82/11/13 17:56:17 eric 44 43
m 066,
m 069
c require an option to do auto-rebuild of alias database; allow new
c operation modes to replace old ad hoc flags
e
s 00006/00009/00803
d D 3.41 82/11/07 15:32:04 eric 43 42
m 063
c don't flag errors in setting dangerous options when -C is used
e
s 00006/00000/00806
d D 3.40 82/11/03 10:29:45 eric 42 41
m 058
c Put temporary file mode on the F option
e
s 00005/00005/00801
d D 3.39 82/10/28 17:41:39 eric 41 40
m 039,
m 027
c Put the "@:@" trick on the "a" option.  Also, move TrustedUsers into
c sendmail.h (it should have gone here in the first place!)
e
s 00054/00005/00752
d D 3.38 82/10/16 15:25:05 eric 40 39
m 027
c Put list of login names able to use -f in the .cf file.
e
s 00010/00001/00747
d D 3.37 82/10/16 14:44:04 eric 39 38
m 007
c Arrange for a wizards password (the W option).  The SMTP KILL command
c may only be issued if this option is set.  This delta adds the "WIZ"
c command, and changes _KILL => KILL, _DEBUG => DEBUG, _VERBOSE => VERB,
c and _SHOWQ => SHOWQ.
e
s 00001/00000/00747
d D 3.36 82/10/06 11:46:07 eric 38 37
c add test mode (MD_TEST, -bt)
e
s 00131/00007/00616
d D 3.35 82/09/26 17:04:39 eric 37 36
c Put more configuration into setoption; merge some of the argv processing
c with this; move configuration information out of conf.c into the .cf
c file.  Since a lot of stuff will default to zero, a new .cf file is
c required.
e
s 00019/00011/00604
d D 3.34 82/09/26 14:46:21 eric 36 35
c completely instantiate queue files for all mail, even if not needed;
c fix a bug that would probably come up once every ten years in creating
c the queue id.  should merge argv flag processing with option processing.
e
s 00104/00004/00511
d D 3.33 82/09/24 19:39:33 eric 35 34
c change option implementation; define a bunch of interesting options.
e
s 00030/00003/00485
d D 3.32 82/09/24 09:38:47 eric 34 33
c arrange to be able to define options; put precedences in .cf file;
c send errors to an Errors-To: field; fix a serious bug causing mail
c to not be delivered to anyone if there were any errors.
e
s 00001/00000/00487
d D 3.31 82/09/12 16:44:10 eric 33 32
c change inheritance for macros in envelopes; be able to canonicalize
c non-domained names by appending domain from sender; call ruleset 3
c explicitly before doing other rulesets; some general cleanup.
e
s 00021/00024/00466
d D 3.30 82/09/05 18:05:59 eric 32 31
c change $g rewriting to two rewriting rulesets per mailer; tune debugging
e
s 00015/00007/00475
d D 3.29 82/09/05 11:46:04 eric 31 30
c put line numbers on error messages; increase max number of rewriting
c sets; improve diagnostics in several places
e
s 00001/00008/00481
d D 3.28 82/08/23 09:24:05 eric 30 29
c allow continuation lines in .cf file (particularly in headers)
e
s 00006/00001/00483
d D 3.27 82/06/19 21:09:24 eric 29 28
c get rid of comment lines when storing rewriting rules
e
s 00001/00001/00483
d D 3.26 82/05/31 18:50:31 eric 28 27
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00000/00000/00484
d D 3.25 82/05/31 15:32:45 eric 27 26
i 25
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00001/00000/00483
d D 3.24 82/05/30 10:25:28 eric 26 24
c add M_FULLSMTP (``X'' flag in .cf file) for eventual implementation
c of full SMTP.  This version must support such garbage as line limits,
c address length limits, return-path, etc.
e
s 00002/00002/00481
d D 3.23.1.1 82/05/29 18:20:53 eric 25 24
c try to install envelopes.  is this really worth it???
e
s 00001/00000/00482
d D 3.23 82/05/15 12:29:41 eric 24 23
c add the 'R' flag to mailers, saying to rewrite the recipient addresses
c to be relative to the recipient.  This makes reply code easy, but
c confuses user mail programs that are expecting to have to rewrite
c recipient addresses.  In general, the receiving host must be "smart"
c for this to work.
e
s 00003/00003/00479
d D 3.22 82/03/20 16:12:52 eric 23 22
c 16 bit changes -- should have no effect on VAX binaries to
c speak of.
e
s 00029/00020/00453
d D 3.21 82/02/20 13:00:21 eric 22 21
c expand macros in rewriting rules early to allow multi-word macros to
c be processed correctly.
e
s 00001/00000/00472
d D 3.20 82/02/20 12:10:24 eric 21 20
c implement -c flag: don't try to deliver expensive mail immediately
e
s 00001/00000/00471
d D 3.19 82/01/23 14:19:28 eric 20 19
c add M_UGLYUUCP flag for ugly from line
e
s 00001/00001/00470
d D 3.18 81/12/06 12:39:52 eric 19 18
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00000/00001/00471
d D 3.17 81/11/21 18:43:35 eric 18 17
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00039/00006/00433
d D 3.16 81/10/26 14:22:59 eric 17 16
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00004/00000/00435
d D 3.15 81/09/24 10:31:06 eric 16 15
c changes to work under a V6 system -- mostly compilation flags
e
s 00085/00001/00350
d D 3.14 81/09/23 09:52:26 eric 15 14
c fix bug in file modes when mailing to files that didn't exist before;
c add an 'F' line to the .cf file that will read class entries from
c another file, given a scanf string to do the parsing.
e
s 00006/00002/00345
d D 3.13 81/09/06 19:49:15 eric 14 13
c cleanup, commenting, linting, etc.
e
s 00012/00003/00335
d D 3.12 81/08/23 12:09:10 eric 13 12
c plug assorted security holes
e
s 00001/00002/00337
d D 3.11 81/08/21 18:18:49 eric 12 11
c drop M_FINAL, change some other defined constant names
e
s 00000/00002/00339
d D 3.10 81/08/20 15:14:44 eric 11 10
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00001/00000/00340
d D 3.9 81/08/17 09:37:54 eric 10 9
c add header fields from new BB&N proposal ICST/CBOS - 80-2,
c "Specification of a Draft Message Format Standard" for NBS.
e
s 00001/00001/00339
d D 3.8 81/08/10 16:57:31 eric 9 8
c totally rework aliasing scheme -- sucks when no DBM now,
c but works better for the usual case; fix some quoting problems
c (and how many did I add?); remove .mailer feature since .forward
c will simulate this happily
e
s 00154/00004/00186
d D 3.7 81/08/09 19:08:47 eric 8 7
c put mailer definitions into configuration file
e
s 00005/00103/00185
d D 3.6 81/08/09 15:03:41 eric 7 6
c lint it
e
s 00032/00015/00256
d D 3.5 81/08/08 17:48:05 eric 6 5
c add another set of rewrite rules to process From: address;
c this will allow generalized from address processing in an
c internet
e
s 00034/00000/00237
d D 3.4 81/08/08 11:18:07 eric 5 4
c add word classes
e
s 00001/00001/00236
d D 3.3 81/03/28 14:18:24 eric 4 3
c don't throw away some headers
e
s 00004/00000/00233
d D 3.2 81/03/28 12:03:01 eric 3 2
c put much more info in cf file (e.g., headers)
e
s 00001/00001/00232
d D 3.1 81/03/20 09:45:32 eric 2 1
c change name (again); from postbox to sendmail
e
s 00233/00000/00000
d D 1.1 81/03/20 09:39:01 eric 1 0
c date and time created 81/03/20 09:39:01 by eric
e
u
U
f b 
f i 
t
T
I 76
/*
I 89
 * Copyright (c) 1983 Eric P. Allman
E 89
D 87
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 87
I 87
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 89
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 89
I 89
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
E 89
 */
E 87

#ifndef lint
D 87
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 87
I 87
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 87

E 76
I 1
D 11
# include <stdio.h>
E 11
D 2
# include "postbox.h"
E 2
I 2
# include "sendmail.h"
E 2
D 11
# include <ctype.h>
E 11

D 19
static char SccsId[] = "%W%	%G%";
E 19
I 19
D 77
SCCSID(%W%	%Y%	%G%);
E 19

E 77
/*
**  READCF -- read control file.
**
**	This routine reads the control file and builds the internal
**	form.
**
I 15
**	The file is formatted as a sequence of lines, each taken
**	atomically.  The first character of each line describes how
**	the line is to be interpreted.  The lines are:
**		Dxval		Define macro x to have value val.
**		Cxword		Put word into class x.
**		Fxfile [fmt]	Read file for lines to put into
**				class x.  Use scanf string 'fmt'
**				or "%s" if not present.  Fmt should
**				only produce one string-valued result.
**		Hname: value	Define header with field-name 'name'
**				and value as specified; this will be
**				macro expanded immediately before
**				use.
**		Sn		Use rewriting set n.
**		Rlhs rhs	Rewrite addresses that match lhs to
**				be rhs.
D 34
**		Mn p f r a	Define mailer.  n - internal name,
**				p - pathname, f - flags, r - rewriting
**				rule for sender, a - argument vector.
E 34
I 34
D 79
**		Mn p f s r a	Define mailer.  n - internal name,
**				p - pathname, f - flags, s - rewriting
**				ruleset for sender, s - rewriting ruleset
**				for recipients, a - argument vector.
E 79
I 79
**		Mn arg=val...	Define mailer.  n is the internal name.
**				Args specify mailer parameters.
E 79
**		Oxvalue		Set option x to value.
**		Pname=value	Set precedence name to value.
E 34
**
E 15
**	Parameters:
**		cfname -- control file name.
I 13
D 74
D 75
**		safe -- set if this is a system configuration file.
**			Non-system configuration files can not do
**			certain things (e.g., leave the SUID bit on
**			when executing mailers).
E 75
E 74
E 13
**
**	Returns:
**		none.
**
**	Side Effects:
**		Builds several internal tables.
*/

I 40
D 41
# define MAXTRUST	10		/* maximum number of trusted users */

char	*TrustedUsers[MAXTRUST+1];	/* list of trusted users */

E 41
E 40
D 6
struct rewrite	*RewriteRules;
E 6
I 6
D 31
struct rewrite	*RewriteRules[10];
E 6


E 31
D 13
readcf(cfname)
E 13
I 13
D 74
D 75
readcf(cfname, safe)
E 75
I 75
readcf(cfname)
E 75
E 74
I 74
readcf(cfname)
E 74
E 13
	char *cfname;
I 13
D 74
D 75
	bool safe;
E 75
E 74
E 13
{
	FILE *cf;
I 40
D 55
	int class;
E 55
	int ruleset = 0;
	char *q;
	char **pv;
I 49
	struct rewrite *rwp = NULL;
E 49
E 40
	char buf[MAXLINE];
	register char *p;
D 49
	struct rewrite *rwp = NULL;
E 49
D 7
	extern char *xalloc();
E 7
	extern char **prescan();
	extern char **copyplist();
D 7
	extern char *rindex();
	extern char *newstr();
E 7
I 5
D 40
	int class;
I 6
	int ruleset = 0;
E 40
I 22
	char exbuf[MAXLINE];
I 70
	char pvpbuf[PSBUFSIZE];
E 70
I 49
	extern char *fgetfolded();
I 57
	extern char *munchstring();
E 57
E 49
I 29
D 40
	char *q;
E 40
E 29
E 22
E 6
E 5

	cf = fopen(cfname, "r");
	if (cf == NULL)
	{
		syserr("cannot open %s", cfname);
		exit(EX_OSFILE);
	}

I 50
	FileName = cfname;
E 50
I 31
	LineNumber = 0;
E 31
D 30
	while (fgets(buf, sizeof buf, cf) != NULL)
E 30
I 30
	while (fgetfolded(buf, sizeof buf, cf) != NULL)
E 30
	{
I 65
		/* map $ into \001 (ASCII SOH) for macro expansion */
		for (p = buf; *p != '\0'; p++)
		{
			if (*p != '$')
				continue;

			if (p[1] == '$')
			{
				/* actual dollar sign.... */
D 78
				strcpy(p, p + 1);
E 78
I 78
				(void) strcpy(p, p + 1);
E 78
				continue;
			}

			/* convert to macro expansion character */
			*p = '\001';
		}

		/* interpret this line */
E 65
D 30
		p = rindex(buf, '\n');
		if (p != NULL)
			*p = '\0';

E 30
		switch (buf[0])
		{
D 30
		  case '\n':
E 30
		  case '\0':
D 30
		  case ' ':
		  case '\t':
E 30
		  case '#':		/* comment */
			break;

		  case 'R':		/* rewriting rule */
			for (p = &buf[1]; *p != '\0' && *p != '\t'; p++)
				continue;

			if (*p == '\0')
I 22
			{
E 22
D 31
				syserr("invalid rewrite line \"%s\"", buf);
E 31
I 31
D 50
				syserr("line %d: invalid rewrite line \"%s\"",
					LineNumber, buf);
E 50
I 50
				syserr("invalid rewrite line \"%s\"", buf);
E 50
E 31
I 22
				break;
			}

			/* allocate space for the rule header */
			if (rwp == NULL)
			{
				RewriteRules[ruleset] = rwp =
					(struct rewrite *) xalloc(sizeof *rwp);
			}
E 22
			else
			{
D 22
				if (rwp == NULL)
D 6
					RewriteRules = rwp = (struct rewrite *) xalloc(sizeof *rwp);
E 6
I 6
				{
					RewriteRules[ruleset] = rwp =
						(struct rewrite *) xalloc(sizeof *rwp);
				}
E 6
				else
				{
					rwp->r_next = (struct rewrite *) xalloc(sizeof *rwp);
					rwp = rwp->r_next;
				}
				rwp->r_next = NULL;

				rwp->r_lhs = prescan(&buf[1], '\t');
				if (rwp->r_lhs != NULL)
					rwp->r_lhs = copyplist(rwp->r_lhs, TRUE);
				while (*p == '\t')
					p++;
				rwp->r_rhs = prescan(p, '\t');
				if (rwp->r_rhs != NULL)
					rwp->r_rhs = copyplist(rwp->r_rhs, TRUE);
E 22
I 22
				rwp->r_next = (struct rewrite *) xalloc(sizeof *rwp);
				rwp = rwp->r_next;
E 22
			}
I 22
			rwp->r_next = NULL;

			/* expand and save the LHS */
			*p = '\0';
D 25
			(void) expand(&buf[1], exbuf, &exbuf[sizeof exbuf]);
E 25
I 25
			expand(&buf[1], exbuf, &exbuf[sizeof exbuf], CurEnv);
E 25
D 70
			rwp->r_lhs = prescan(exbuf, '\t');
E 70
I 70
			rwp->r_lhs = prescan(exbuf, '\t', pvpbuf);
E 70
			if (rwp->r_lhs != NULL)
				rwp->r_lhs = copyplist(rwp->r_lhs, TRUE);

			/* expand and save the RHS */
			while (*++p == '\t')
				continue;
D 25
			(void) expand(p, exbuf, &exbuf[sizeof exbuf]);
E 25
I 25
D 29
			expand(p, exbuf, &exbuf[sizeof exbuf], CurEnv);
E 29
I 29
			q = p;
			while (*p != '\0' && *p != '\t')
				p++;
			*p = '\0';
			expand(q, exbuf, &exbuf[sizeof exbuf], CurEnv);
E 29
E 25
D 70
			rwp->r_rhs = prescan(exbuf, '\t');
E 70
I 70
			rwp->r_rhs = prescan(exbuf, '\t', pvpbuf);
E 70
			if (rwp->r_rhs != NULL)
				rwp->r_rhs = copyplist(rwp->r_rhs, TRUE);
E 22
			break;

I 6
		  case 'S':		/* select rewriting set */
			ruleset = atoi(&buf[1]);
I 31
			if (ruleset >= MAXRWSETS || ruleset < 0)
			{
D 50
				syserr("readcf: line %d: bad ruleset %d (%d max)",
					LineNumber, ruleset, MAXRWSETS);
E 50
I 50
				syserr("bad ruleset %d (%d max)", ruleset, MAXRWSETS);
E 50
				ruleset = 0;
			}
E 31
			rwp = NULL;
			break;

E 6
		  case 'D':		/* macro definition */
D 50
			define(buf[1], newstr(&buf[2]));
E 50
I 50
D 57
			define(buf[1], newstr(&buf[2]), CurEnv);
E 57
I 57
			define(buf[1], newstr(munchstring(&buf[2])), CurEnv);
E 57
E 50
			break;

I 3
		  case 'H':		/* required header line */
D 4
			chompheader(&buf[1], H_DEFAULT);
E 4
I 4
D 7
			chompheader(&buf[1], TRUE);
E 7
I 7
			(void) chompheader(&buf[1], TRUE);
E 7
E 4
			break;

I 5
		  case 'C':		/* word class */
I 15
		  case 'F':		/* word class from file */
E 15
D 55
			class = buf[1];
			if (!isalpha(class))
D 50
				goto badline;
E 50
I 50
			{
				syserr("illegal class name %c", class);
				break;
			}
E 50
			if (isupper(class))
				class -= 'A';
			else
				class -= 'a';
I 15
			
E 55
			/* read list of words from argument or file */
			if (buf[0] == 'F')
			{
				/* read from file */
				for (p = &buf[2]; *p != '\0' && !isspace(*p); p++)
					continue;
				if (*p == '\0')
					p = "%s";
				else
				{
					*p = '\0';
					while (isspace(*++p))
						continue;
				}
D 55
				fileclass(class, &buf[2], p);
E 55
I 55
				fileclass(buf[1], &buf[2], p);
E 55
				break;
			}
E 15

D 15
			/* scan the list of words and set class 'i' for all */
E 15
I 15
			/* scan the list of words and set class for all */
E 15
			for (p = &buf[2]; *p != '\0'; )
			{
				register char *wd;
				char delim;
D 59
				register STAB *s;
E 59

				while (*p != '\0' && isspace(*p))
					p++;
				wd = p;
				while (*p != '\0' && !isspace(*p))
					p++;
				delim = *p;
				*p = '\0';
				if (wd[0] != '\0')
D 55
				{
D 9
					s = stab(wd, ST_ENTER);
E 9
I 9
					s = stab(wd, ST_CLASS, ST_ENTER);
E 9
D 23
					s->s_class |= 1 << class;
E 23
I 23
					s->s_class |= 1L << class;
E 23
				}
E 55
I 55
					setclass(buf[1], wd);
E 55
				*p = delim;
			}
			break;

I 8
		  case 'M':		/* define mailer */
D 13
			makemailer(&buf[1]);
E 13
I 13
D 74
D 75
			makemailer(&buf[1], safe);
E 75
I 75
			makemailer(&buf[1]);
E 75
E 74
I 74
			makemailer(&buf[1]);
E 74
I 34
			break;

		  case 'O':		/* set option */
D 35
			if (buf[2] == '\0')
				Option[buf[1]] = "";
			else
				Option[buf[1]] = newstr(&buf[2]);
E 35
I 35
D 37
			setoption(buf[1], &buf[2]);
E 37
I 37
D 74
D 75
			setoption(buf[1], &buf[2], safe, FALSE);
E 75
I 75
			setoption(buf[1], &buf[2], TRUE, FALSE);
E 75
E 74
I 74
			setoption(buf[1], &buf[2], FALSE);
E 74
E 37
E 35
			break;

		  case 'P':		/* set precedence */
			if (NumPriorities >= MAXPRIORITIES)
			{
D 40
				syserr("readcf: line %d: too many P lines, %d max",
					LineNumber, MAXPRIORITIES);
E 40
I 40
				toomany('P', MAXPRIORITIES);
E 40
				break;
			}
D 50
			for (p = &buf[1]; *p != '\0' && *p != '='; p++)
E 50
I 50
			for (p = &buf[1]; *p != '\0' && *p != '=' && *p != '\t'; p++)
E 50
				continue;
			if (*p == '\0')
				goto badline;
			*p = '\0';
			Priorities[NumPriorities].pri_name = newstr(&buf[1]);
			Priorities[NumPriorities].pri_val = atoi(++p);
			NumPriorities++;
E 34
E 13
			break;

I 40
		  case 'T':		/* trusted user(s) */
			p = &buf[1];
			while (*p != '\0')
			{
				while (isspace(*p))
					p++;
				q = p;
				while (*p != '\0' && !isspace(*p))
					p++;
				if (*p != '\0')
					*p++ = '\0';
				if (*q == '\0')
					continue;
				for (pv = TrustedUsers; *pv != NULL; pv++)
					continue;
				if (pv >= &TrustedUsers[MAXTRUST])
				{
					toomany('T', MAXTRUST);
					break;
				}
				*pv = newstr(q);
			}
			break;

E 40
E 8
E 5
E 3
		  default:
I 5
		  badline:
E 5
D 31
			syserr("unknown control line \"%s\"", buf);
E 31
I 31
D 50
			syserr("readcf: line %d: unknown control line \"%s\"",
				LineNumber, buf);
E 50
I 50
			syserr("unknown control line \"%s\"", buf);
E 50
E 31
		}
	}
I 50
	FileName = NULL;
E 50
I 40
}
/*
**  TOOMANY -- signal too many of some option
**
**	Parameters:
**		id -- the id of the error line
**		maxcnt -- the maximum possible values
**
**	Returns:
**		none.
**
**	Side Effects:
**		gives a syserr.
*/

toomany(id, maxcnt)
	char id;
	int maxcnt;
{
D 50
	syserr("readcf: line %d: too many %c lines, %d max",
	       LineNumber, id, maxcnt);
E 50
I 50
	syserr("too many %c lines, %d max", id, maxcnt);
E 50
E 40
I 15
}
/*
**  FILECLASS -- read members of a class from a file
**
**	Parameters:
**		class -- class to define.
**		filename -- name of file to read.
**		fmt -- scanf string to use for match.
**
**	Returns:
**		none
**
**	Side Effects:
**
**		puts all lines in filename that match a scanf into
**			the named class.
*/

fileclass(class, filename, fmt)
	int class;
	char *filename;
	char *fmt;
{
D 85
	register FILE *f;
E 85
I 85
	FILE *f;
E 85
	char buf[MAXLINE];

	f = fopen(filename, "r");
	if (f == NULL)
	{
		syserr("cannot open %s", filename);
		return;
	}

	while (fgets(buf, sizeof buf, f) != NULL)
	{
		register STAB *s;
I 85
		register char *p;
# ifdef SCANF
E 85
		char wordbuf[MAXNAME+1];

		if (sscanf(buf, fmt, wordbuf) != 1)
			continue;
D 85
		s = stab(wordbuf, ST_CLASS, ST_ENTER);
D 23
		s->s_class |= 1 << class;
E 23
I 23
D 55
		s->s_class |= 1L << class;
E 55
I 55
		setbitn(class, s->s_class);
E 85
I 85
		p = wordbuf;
# else SCANF
		p = buf;
# endif SCANF

		/*
		**  Break up the match into words.
		*/

		while (*p != '\0')
		{
			register char *q;

			/* strip leading spaces */
			while (isspace(*p))
				p++;
			if (*p == '\0')
				break;

			/* find the end of the word */
			q = p;
			while (*p != '\0' && !isspace(*p))
				p++;
			if (*p != '\0')
				*p++ = '\0';

			/* enter the word in the symbol table */
			s = stab(q, ST_CLASS, ST_ENTER);
			setbitn(class, s->s_class);
		}
E 85
E 55
E 23
	}

D 17
	fclose(f);
E 17
I 17
	(void) fclose(f);
E 17
E 15
I 8
}
/*
**  MAKEMAILER -- define a new mailer.
**
**	Parameters:
D 52
**		line -- description of mailer.  This is in tokens
**			separated by white space.  The fields are:
**			* the name of the mailer, as refered to
**			  in the rewriting rules.
**			* the pathname of the program to fork to
**			  execute it.
**			* the options needed by this program.
**			* the macro string needed to translate
**			  a local "from" name to one that can be
**			  returned to this machine.
**			* the argument vector (a series of parameters).
E 52
I 52
**		line -- description of mailer.  This is in labeled
**			fields.  The fields are:
**			   P -- the path to the mailer
**			   F -- the flags associated with the mailer
**			   A -- the argv for this mailer
**			   S -- the sender rewriting set
**			   R -- the recipient rewriting set
**			   E -- the eol string
**			The first word is the canonical name of the mailer.
E 52
I 13
D 74
D 75
**		safe -- set if this is a safe configuration file.
E 75
E 74
E 13
**
**	Returns:
**		none.
**
**	Side Effects:
**		enters the mailer into the mailer table.
*/
E 8

D 7
/*
	printrules();
*/
}
/*
**  RWCRACK -- crack rewrite line.
**
**	Parameters:
**		l -- line to crack.
**
**	Returns:
**		local copy of cracked line.
**
**	Side Effects:
**		none.
*/

char **
rwcrack(l)
	register char *l;
{
	char *av[MAXATOM];
	int ac = 0;
	register char **avp;
	char buf[MAXNAME];
	register char *b;
	bool wasdelim = FALSE;
	char *delims = ":@!^.";
	extern char *index();
	bool tchange;
	extern char *newstr(), *xalloc();

	for (avp = av; *l != '\0' && *l != '\n'; avp++)
	{
		b = buf;
		tchange = FALSE;
		while (!tchange)
		{
			if (*l != '$')
			{
				if (wasdelim || index(delims, *l) != NULL)
					tchange = TRUE;
				wasdelim = (index(delims, *l) != NULL);
				if (wasdelim)
					tchange = TRUE;
				*b++ = *l++;
				continue;
			}

			tchange = TRUE;
			switch (*++l)
			{
			  case '$':		/* literal $ */
				*b++ = *l;
				break;

			  case '+':		/* match anything */
				*b++ = MATCHANY;
				*b++ = *++l;
				break;

			  case '-':		/* match one token */
				*b++ = MATCHONE;
				*b++ = *++l;
				break;

			  case '#':		/* canonical net name */
				*b++ = CANONNET;
				break;

			  case '@':		/* canonical host name */
				*b++ = CANONHOST;
				break;

			  case ':':		/* canonical user name */
				*b++ = CANONUSER;
				break;

			  default:
				*b++ = '$';
				l--;
				break;
			}
			l++;
		}

		/* save the argument we have collected */
		*b = '\0';
		*avp = newstr(buf);
		ac++;
	}

	/* allocate new space for vector */
	ac++;
	*avp = NULL;
	avp = (char **) xalloc(ac * sizeof *av);
	bmove(av, avp, ac * sizeof *av);

	return (avp);
E 7
I 7
D 8
# ifdef DEBUG
	if (Debug > 6)
		printrules();
# endif DEBUG
E 8
I 8
D 52
# define SETWORD \
		{ \
			while (*p != '\0' && isspace(*p)) \
				p++; \
			q = p; \
			while (*p != '\0' && !isspace(*p)) \
				p++; \
			if (*p != '\0') \
				*p++ = '\0'; \
		}

E 52
D 13
makemailer(line)
E 13
I 13
D 74
D 75
makemailer(line, safe)
E 75
I 75
makemailer(line)
E 75
E 74
I 74
makemailer(line)
E 74
E 13
	char *line;
I 13
D 74
D 75
	bool safe;
E 75
E 74
E 13
{
	register char *p;
D 52
	register char *q;
E 52
I 32
	register struct mailer *m;
	register STAB *s;
	int i;
E 32
D 52
	char *mname;
	char *mpath;
D 17
	int mopts;
E 17
I 17
	u_long mopts;
D 32
	extern u_long mfencode();
E 17
	char *mfrom;
	register struct mailer *m;
E 32
I 32
	short mrset, msset;
E 32
	char *margv[MAXPV + 1];
E 52
I 52
	char fcode;
E 52
D 32
	register int i;
E 32
I 32
D 55
	extern u_long mfencode();
E 55
E 32
	extern int NextMailer;
I 52
	extern char **makeargv();
	extern char *munchstring();
	extern char *DelimChar;
I 56
	extern long atol();
E 56
E 52
I 16
D 32
	STAB *s;
E 32
E 16

I 52
	/* allocate a mailer and set up defaults */
	m = (struct mailer *) xalloc(sizeof *m);
	bzero((char *) m, sizeof *m);
	m->m_mno = NextMailer;
	m->m_eol = "\n";

	/* collect the mailer name */
	for (p = line; *p != '\0' && *p != ',' && !isspace(*p); p++)
		continue;
	if (*p != '\0')
		*p++ = '\0';
	m->m_name = newstr(line);

	/* now scan through and assign info from the fields */
	while (*p != '\0')
	{
		while (*p != '\0' && (*p == ',' || isspace(*p)))
			p++;

		/* p now points to field code */
		fcode = *p;
		while (*p != '\0' && *p != '=' && *p != ',')
			p++;
		if (*p++ != '=')
		{
			syserr("`=' expected");
			return;
		}
		while (isspace(*p))
			p++;

		/* p now points to the field body */
		p = munchstring(p);

		/* install the field into the mailer struct */
		switch (fcode)
		{
		  case 'P':		/* pathname */
			m->m_mailer = newstr(p);
			break;

		  case 'F':		/* flags */
D 55
			m->m_flags = mfencode(p);
E 55
I 55
			for (; *p != '\0'; p++)
				setbitn(*p, m->m_flags);
E 55
D 74
D 75
			if (!safe)
D 55
				m->m_flags &= ~M_RESTR;
E 55
I 55
				clrbitn(M_RESTR, m->m_flags);
E 75
E 74
E 55
			break;

		  case 'S':		/* sender rewriting ruleset */
		  case 'R':		/* recipient rewriting ruleset */
			i = atoi(p);
			if (i < 0 || i >= MAXRWSETS)
			{
				syserr("invalid rewrite set, %d max", MAXRWSETS);
				return;
			}
			if (fcode == 'S')
				m->m_s_rwset = i;
			else
				m->m_r_rwset = i;
			break;

		  case 'E':		/* end of line string */
			m->m_eol = newstr(p);
			break;

		  case 'A':		/* argument vector */
			m->m_argv = makeargv(p);
I 56
			break;

		  case 'M':		/* maximum message size */
			m->m_maxsize = atol(p);
E 56
			break;
		}

		p = DelimChar;
	}

	/* now store the mailer away */
E 52
	if (NextMailer >= MAXMAILERS)
	{
D 31
		syserr("Too many mailers defined");
E 31
I 31
D 50
		syserr("readcf: line %d: too many mailers defined (%d max)",
			LineNumber, MAXMAILERS);
E 50
I 50
		syserr("too many mailers defined (%d max)", MAXMAILERS);
E 50
E 31
		return;
	}
I 52
	Mailer[NextMailer++] = m;
	s = stab(m->m_name, ST_MAILER, ST_ENTER);
	s->s_mailer = m;
}
/*
**  MUNCHSTRING -- translate a string into internal form.
**
**	Parameters:
**		p -- the string to munch.
**
**	Returns:
**		the munched string.
**
**	Side Effects:
**		Sets "DelimChar" to point to the string that caused us
**		to stop.
*/
E 52

D 52
	/* collect initial information */
	p = line;
	SETWORD;
	mname = q;
	SETWORD;
	mpath = q;
	SETWORD;
D 17
	mopts = crackopts(q);
E 17
I 17
	mopts = mfencode(q);
E 17
I 13
	if (!safe)
		mopts &= ~M_RESTR;
E 13
	SETWORD;
D 32
	mfrom = q;
E 32
I 32
	msset = atoi(q);
	SETWORD;
	mrset = atoi(q);
E 52
I 52
char *
munchstring(p)
	register char *p;
{
	register char *q;
	bool backslash = FALSE;
	bool quotemode = FALSE;
	static char buf[MAXLINE];
	extern char *DelimChar;
E 52
E 32

D 52
	if (*p == '\0')
E 52
I 52
	for (q = buf; *p != '\0'; p++)
E 52
	{
D 31
		syserr("invalid M line in configuration file");
E 31
I 31
D 50
		syserr("readcf: line %d: invalid M line in configuration file",
			LineNumber);
E 50
I 50
D 52
		syserr("invalid M line in configuration file");
E 50
E 31
		return;
E 52
I 52
		if (backslash)
		{
			/* everything is roughly literal */
I 54
			backslash = FALSE;
E 54
			switch (*p)
			{
			  case 'r':		/* carriage return */
				*q++ = '\r';
				continue;

			  case 'n':		/* newline */
				*q++ = '\n';
				continue;

			  case 'f':		/* form feed */
				*q++ = '\f';
				continue;

			  case 'b':		/* backspace */
				*q++ = '\b';
				continue;
			}
			*q++ = *p;
D 54
			backslash = FALSE;
E 54
		}
		else
		{
			if (*p == '\\')
				backslash = TRUE;
			else if (*p == '"')
				quotemode = !quotemode;
			else if (quotemode || *p != ',')
				*q++ = *p;
			else
				break;
		}
E 52
	}
I 32
D 52
	if (msset >= MAXRWSETS || mrset >= MAXRWSETS)
	{
		syserr("readcf: line %d: invalid rewrite set, %d max",
			LineNumber, MAXRWSETS);
		return;
	}
E 52
E 32

D 52
	/* allocate a mailer */
	m = (struct mailer *) xalloc(sizeof *m);
	m->m_name = newstr(mname);
	m->m_mailer = newstr(mpath);
	m->m_flags = mopts;
D 32
	m->m_from = newstr(mfrom);
E 32
I 32
	m->m_r_rwset = mrset;
	m->m_s_rwset = msset;
E 32
D 50
	m->m_badstat = EX_UNAVAILABLE;
E 50
D 18
	m->m_sendq = NULL;
E 18
I 16
	m->m_mno = NextMailer;
E 16
	Mailer[NextMailer++] = m;
E 52
I 52
	DelimChar = p;
	*q++ = '\0';
	return (buf);
}
/*
**  MAKEARGV -- break up a string into words
**
**	Parameters:
**		p -- the string to break up.
**
**	Returns:
**		a char **argv (dynamically allocated)
**
**	Side Effects:
**		munges p.
*/
E 52

D 52
	/* collect the argument vector */
	for (i = 0; i < MAXPV - 1 && *p != '\0'; i++)
E 52
I 52
char **
makeargv(p)
	register char *p;
{
	char *q;
	int i;
	char **avp;
	char *argv[MAXPV + 1];

	/* take apart the words */
	i = 0;
	while (*p != '\0' && i < MAXPV)
E 52
	{
D 52
		SETWORD;
		margv[i] = newstr(q);
E 52
I 52
		q = p;
		while (*p != '\0' && !isspace(*p))
			p++;
		while (isspace(*p))
			*p++ = '\0';
		argv[i++] = newstr(q);
E 52
	}
D 52
	margv[i++] = NULL;
E 52
I 52
	argv[i++] = NULL;
E 52

D 52
	/* save the argv */
D 14
	m->m_argv = (char **) xalloc(sizeof margv[0] * i);
E 14
I 14
D 28
	m->m_argv = (char **) xalloc((unsigned) (sizeof margv[0] * i));
E 28
I 28
	m->m_argv = (char **) xalloc(sizeof margv[0] * i);
E 28
E 14
	bmove((char *) margv, (char *) m->m_argv, sizeof margv[0] * i);
I 16
	s = stab(m->m_name, ST_MAILER, ST_ENTER);
	s->s_mailer = m;
E 52
I 52
	/* now make a copy of the argv */
	avp = (char **) xalloc(sizeof *avp * i);
D 69
	bmove((char *) argv, (char *) avp, sizeof *avp * i);
E 69
I 69
	bcopy((char *) argv, (char *) avp, sizeof *avp * i);
E 69

	return (avp);
E 52
E 16
E 8
E 7
}
/*
**  PRINTRULES -- print rewrite rules (for debugging)
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		prints rewrite rules.
*/

I 14
# ifdef DEBUG

E 14
printrules()
{
	register struct rewrite *rwp;
I 6
	register int ruleset;
E 6

D 6
	for (rwp = RewriteRules; rwp != NULL; rwp = rwp->r_next)
E 6
I 6
	for (ruleset = 0; ruleset < 10; ruleset++)
E 6
	{
D 6
		register char **av;
E 6
I 6
		if (RewriteRules[ruleset] == NULL)
			continue;
D 32
		printf("\n----Rule Set %d:\n", ruleset);
E 32
I 32
		printf("\n----Rule Set %d:", ruleset);
E 32
E 6

D 6
		printf("\n");
		for (av = rwp->r_lhs; *av != NULL; av++)
E 6
I 6
		for (rwp = RewriteRules[ruleset]; rwp != NULL; rwp = rwp->r_next)
E 6
		{
D 6
			xputs(*av);
			putchar('_');
E 6
I 6
D 32
			register char **av;

			printf("\n");
			for (av = rwp->r_lhs; *av != NULL; av++)
			{
				xputs(*av);
				putchar('_');
			}
			printf("\n\t");
			for (av = rwp->r_rhs; *av != NULL; av++)
			{
				xputs(*av);
				putchar('_');
			}
			printf("\n");
E 32
I 32
			printf("\nLHS:");
			printav(rwp->r_lhs);
			printf("RHS:");
			printav(rwp->r_rhs);
E 32
E 6
		}
D 6
		printf("\n\t");
		for (av = rwp->r_rhs; *av != NULL; av++)
		{
			xputs(*av);
			putchar('_');
		}
		printf("\n");
E 6
	}
I 8
}
I 14

# endif DEBUG
E 14
/*
D 17
**  CRACKOPTS -- crack mailer options
E 17
I 17
D 55
**  MFENCODE -- crack mailer options
E 17
**
**	These options modify the functioning of the mailer
**	from the configuration table.
**
**	Parameters:
**		p -- pointer to vector of options.
**
**	Returns:
**		option list in binary.
**
**	Side Effects:
**		none.
*/

struct optlist
{
	char	opt_name;	/* external name of option */
D 23
	int	opt_value;	/* internal name of option */
E 23
I 23
	u_long	opt_value;	/* internal name of option */
E 23
};
struct optlist	OptList[] =
{
I 51
	'A',	M_ARPAFMT,
	'C',	M_CANONICAL,
	'D',	M_NEEDDATE,
	'e',	M_EXPENSIVE,
	'F',	M_NEEDFROM,
E 51
	'f',	M_FOPT,
D 51
	'r',	M_ROPT,
E 51
I 51
	'h',	M_HST_UPPER,
	'I',	M_INTERNAL,
	'L',	M_LIMITS,
	'l',	M_LOCAL,
	'M',	M_MSGID,
	'm',	M_MUSER,
	'n',	M_NHDR,
E 51
D 50
	'q',	M_QUIET,
E 50
I 50
	'P',	M_RPATH,
I 51
	'p',	M_FROMPATH,
D 52
	'R',	M_CRLF,
E 52
	'r',	M_ROPT,
E 51
E 50
	'S',	M_RESTR,
D 51
	'n',	M_NHDR,
D 12
	'l',	M_NOHOST,
E 12
I 12
	'l',	M_LOCAL,
E 51
E 12
	's',	M_STRIPQ,
D 51
	'm',	M_MUSER,
	'F',	M_NEEDFROM,
	'D',	M_NEEDDATE,
	'M',	M_MSGID,
E 51
I 51
	'U',	M_UGLYUUCP,
E 51
	'u',	M_USR_UPPER,
D 51
	'h',	M_HST_UPPER,
E 51
	'x',	M_FULLNAME,
D 51
	'A',	M_ARPAFMT,
I 20
	'U',	M_UGLYUUCP,
I 21
	'e',	M_EXPENSIVE,
I 24
D 32
	'R',	M_RELRCPT,
E 32
I 26
	'X',	M_FULLSMTP,
I 33
	'C',	M_CANONICAL,
I 47
	'I',	M_INTERNAL,
E 51
I 51
	'X',	M_XDOT,
E 51
E 47
E 33
E 26
E 24
E 21
E 20
I 10
D 12
	'L',	M_FINAL,
E 12
E 10
D 14
	0,	0
E 14
I 14
	'\0',	0
E 14
};

D 17
crackopts(p)
E 17
I 17
u_long
mfencode(p)
E 17
	register char *p;
{
	register struct optlist *o;
D 17
	register int opts = 0;
E 17
I 17
	register u_long opts = 0;
E 17

	while (*p != '\0')
	{
		for (o = OptList; o->opt_name != '\0' && o->opt_name != *p; o++)
			continue;
D 52
		if (o->opt_name == '\0')
			syserr("bad mailer option %c", *p);
E 52
		opts |= o->opt_value;
		p++;
	}
	return (opts);
I 17
}
/*
**  MFDECODE -- decode mailer flags into external form.
**
**	Parameters:
**		flags -- value of flags to decode.
**		f -- file to write them onto.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

mfdecode(flags, f)
	u_long flags;
	FILE *f;
{
	register struct optlist *o;

	putc('?', f);
	for (o = OptList; o->opt_name != '\0'; o++)
	{
		if ((o->opt_value & flags) == o->opt_value)
		{
			flags &= ~o->opt_value;
			putc(o->opt_name, f);
		}
	}
	putc('?', f);
I 35
}
/*
E 55
**  SETOPTION -- set global processing option
**
**	Parameters:
**		opt -- option name.
**		val -- option value (as a text string).
I 37
D 74
D 75
**		safe -- if set, this came from a system configuration file.
E 75
I 75
**		safe -- set if this came from a configuration file.
**			Some options (if set from the command line) will
**			reset the user id to avoid security problems.
E 75
E 74
**		sticky -- if set, don't let other setoptions override
**			this value.
E 37
**
**	Returns:
**		none.
**
**	Side Effects:
**		Sets options as implied by the arguments.
*/

D 37
setoption(opt, val)
E 37
I 37
D 39
static int	StickyOpt[128 / sizeof (int)];
E 39
I 39
D 55
static int	StickyOpt[128 / sizeof (int)];	/* set if option is stuck */
extern char	*WizWord;			/* the stored wizard password */
E 55
I 55
static BITMAP	StickyOpt;		/* set if option is stuck */
D 84
extern char	*WizWord;		/* the stored wizard password */
E 84
I 64
extern char	*NetName;		/* name of home (local) network */
I 84
# ifdef SMTP
# ifdef WIZ
extern char	*WizWord;		/* the stored wizard password */
# endif WIZ
# endif SMTP
E 84
E 64
E 55
I 53
D 61
#ifdef DAEMON
D 55
extern int	MaxConnections;			/* max simult. SMTP conns */
E 55
I 55
extern int	MaxConnections;		/* max simult. SMTP conns */
E 55
#endif DAEMON
E 61
E 53
E 39

D 74
setoption(opt, val, safe, sticky)
E 74
I 74
setoption(opt, val, sticky)
E 74
E 37
	char opt;
	char *val;
I 37
D 74
	bool safe;
E 74
	bool sticky;
E 37
{
D 50
	time_t tval;
	int ival;
I 36
	bool bval;
E 50
E 36
D 37
	extern char *HelpFile;			/* defined in conf.c */
E 37
I 37
D 55
	int smask;
	int sindex;
E 55
E 37
I 36
	extern bool atobool();
I 60
	extern time_t convtime();
I 63
	extern int QueueLA;
	extern int RefuseLA;
I 71
	extern bool trusteduser();
	extern char *username();
E 71
E 63
E 60
E 36

# ifdef DEBUG
	if (tTd(37, 1))
D 48
		printf("setoption %c=%s\n", opt, val);
E 48
I 48
		printf("setoption %c=%s", opt, val);
E 48
# endif DEBUG

	/*
D 37
	**  First encode this option as appropriate.
E 37
I 37
	**  See if this option is preset for us.
E 37
	*/

I 37
D 55
	sindex = opt;
	smask = 1 << (sindex % sizeof (int));
	sindex /= sizeof (int);
	if (bitset(smask, StickyOpt[sindex]))
E 55
I 55
	if (bitnset(opt, StickyOpt))
E 55
	{
# ifdef DEBUG
D 48
		if (tTd(37, 2))
			printf("(ignored)\n");
E 48
I 48
		if (tTd(37, 1))
			printf(" (ignored)\n");
E 48
# endif DEBUG
		return;
	}
I 48
D 73
#ifdef DEBUG
	else if (tTd(37, 1))
		printf("\n");
#endif DEBUG
E 73
E 48
D 68
	if (sticky)
D 55
		StickyOpt[sindex] |= smask;
E 55
I 55
		setbitn(opt, StickyOpt);
E 68
E 55

D 71
	if (getruid() == 0)
E 71
I 71
D 74
	/*
	**  Check to see if this option can be specified by this user.
	*/

D 73
	if (!safe && (getruid() == 0 || trusteduser(username())))
E 73
I 73
D 75
	if (!safe && (getruid() == 0 || OpMode == MD_TEST))
E 75
I 75
D 83
	if (!safe && getruid())
E 83
I 83
	if (!safe && getruid() == 0)
E 83
E 75
E 73
E 71
		safe = TRUE;
I 71
	if (!safe && index("deiLmorsv", opt) == NULL)
I 73
	{
# ifdef DEBUG
		if (tTd(37, 1))
D 75
			printf(" (unsafe)\n");
E 75
I 75
			printf(" (unsafe)");
E 75
# endif DEBUG
E 73
D 75
		return;
E 75
I 75
		if (getruid() != geteuid())
		{
			printf("(Resetting uid)\n");
D 78
			setgid(getgid());
			setuid(getuid());
E 78
I 78
			(void) setgid(getgid());
			(void) setuid(getuid());
E 78
		}
E 75
I 73
	}
E 74
#ifdef DEBUG
D 74
	else if (tTd(37, 1))
E 74
I 74
	if (tTd(37, 1))
E 74
		printf("\n");
#endif DEBUG
E 73
E 71

D 50
	/*
	**  Encode this option as appropriate.
	*/

E 37
	if (index("rT", opt) != NULL)
		tval = convtime(val);
	else if (index("gLu", opt) != NULL)
		ival = atoi(val);
I 42
	else if (index("F", opt) != NULL)
		ival = atooct(val);
E 42
I 36
D 37
	else if (index("s", opt) != NULL)
E 37
I 37
D 41
	else if (index("cfimosv", opt) != NULL)
E 41
I 41
D 44
	else if (index("acfimosv", opt) != NULL)
E 44
I 44
	else if (index("acDfimosv", opt) != NULL)
E 44
E 41
E 37
		bval = atobool(val);
I 37
	else if (index("be", opt) != NULL)
		/* do nothing */ ;
E 37
E 36
	else if (val[0] == '\0')
		val = "";
	else
		val = newstr(val);

	/*
	**  Now do the actual assignment.
	*/

E 50
	switch (opt)
	{
	  case 'A':		/* set default alias file */
D 50
		AliasFile = val;
I 37
		if (AliasFile[0] == '\0')
E 50
I 50
		if (val[0] == '\0')
E 50
			AliasFile = "aliases";
I 50
		else
			AliasFile = newstr(val);
E 50
I 41
		break;

I 71
	  case 'a':		/* look N minutes for "@:@" in alias file */
		if (val[0] == '\0')
			SafeAlias = 5;
		else
			SafeAlias = atoi(val);
		break;

E 71
I 67
	  case 'B':		/* substitution for blank character */
		SpaceSub = val[0];
		if (SpaceSub == '\0')
			SpaceSub = ' ';
		break;

E 67
D 71
	  case 'a':		/* look for "@:@" in alias file */
D 50
		SafeAlias = bval;
E 50
I 50
		SafeAlias = atobool(val);
E 50
E 41
E 37
		break;

E 71
I 37
D 46
	  case 'b':		/* operations mode */
		Mode = *val;
		switch (Mode)
E 46
I 46
	  case 'c':		/* don't connect to "expensive" mailers */
D 50
		NoConnect = bval;
E 50
I 50
		NoConnect = atobool(val);
E 50
		break;

I 79
	  case 'C':		/* checkpoint after N connections */
		CheckPointLimit = atoi(val);
		break;

E 79
	  case 'd':		/* delivery mode */
		switch (*val)
E 46
		{
D 46
		  case MD_DAEMON:	/* run as a daemon */
#ifdef DAEMON
			ArpaMode = Smtp = TRUE;
#else DAEMON
			syserr("Daemon mode not implemented");
#endif DAEMON
E 46
I 46
		  case '\0':
			SendMode = SM_DELIVER;
E 46
			break;

I 58
		  case SM_QUEUE:	/* queue only */
#ifndef QUEUE
			syserr("need QUEUE to set -odqueue");
#endif QUEUE
			/* fall through..... */

E 58
D 46
		  case '\0':	/* default: do full delivery */
			Mode = MD_DEFAULT;
			/* fall through....... */

		  case MD_DELIVER:	/* do everything (default) */
		  case MD_FORK:		/* fork after verification */
		  case MD_QUEUE:	/* queue only */
		  case MD_VERIFY:	/* verify only */
I 38
		  case MD_TEST:		/* test addresses */
I 44
		  case MD_PRINT:	/* print queue contents */
		  case MD_INITALIAS:	/* initialize alias database */
		  case MD_FREEZE:	/* freeze config file */
E 46
I 46
		  case SM_DELIVER:	/* do everything */
		  case SM_FORK:		/* fork after verification */
D 58
		  case SM_QUEUE:	/* queue only */
E 58
			SendMode = *val;
E 46
E 44
E 38
			break;

		  default:
D 46
			syserr("Unknown operation mode -b%c", Mode);
E 46
I 46
			syserr("Unknown delivery mode %c", *val);
E 46
			exit(EX_USAGE);
		}
		break;

D 46
	  case 'c':		/* don't connect to "expensive" mailers */
		NoConnect = bval;
I 44
		break;

E 46
	  case 'D':		/* rebuild alias database as needed */
D 50
		AutoRebuild = bval;
E 50
I 50
		AutoRebuild = atobool(val);
E 50
E 44
		break;

	  case 'e':		/* set error processing mode */
		switch (*val)
		{
D 50
		  case 'p':	/* print errors normally */
			break;	/* (default) */

		  case 'q':	/* be silent about it */
E 50
I 50
		  case EM_QUIET:	/* be silent about it */
E 50
D 58
			(void) freopen("/dev/null", "w", stdout);
D 50
			break;
E 50
I 50
			/* fall through... */
E 50

E 58
D 50
		  case 'm':	/* mail back */
			MailBack = TRUE;
E 50
I 50
		  case EM_MAIL:		/* mail back */
		  case EM_BERKNET:	/* do berknet error processing */
		  case EM_WRITE:	/* write back (or mail) */
E 50
			HoldErrs = TRUE;
D 50
			break;
E 50
I 50
			/* fall through... */
E 50

D 50
		  case 'e':	/* do berknet error processing */
			BerkNet = TRUE;
			HoldErrs = TRUE;
E 50
I 50
		  case EM_PRINT:	/* print errors normally (default) */
			ErrorMode = *val;
E 50
			break;
D 50

		  case 'w':	/* write back (or mail) */
			WriteBack = TRUE;
			HoldErrs = TRUE;
			break;
E 50
		}
I 42
		break;

	  case 'F':		/* file mode */
D 50
		FileMode = ival;
E 50
I 50
D 72
		FileMode = atooct(val);
E 72
I 72
		FileMode = atooct(val) & 0777;
E 72
E 50
E 42
		break;

	  case 'f':		/* save Unix-style From lines on front */
D 50
		SaveFrom = bval;
E 50
I 50
		SaveFrom = atobool(val);
E 50
		break;

E 37
D 36
# ifdef V6
	  case 'd':		/* dst timezone name */
		DstTimeZone = val;
		break;
# endif V6

E 36
	  case 'g':		/* default gid */
I 37
D 43
		if (!safe)
			goto syntax;
E 37
		DefGid = ival;
E 43
I 43
D 71
		if (safe)
D 50
			DefGid = ival;
E 50
I 50
			DefGid = atoi(val);
E 71
I 71
		DefGid = atoi(val);
E 71
E 50
E 43
		break;

	  case 'H':		/* help file */
D 50
		HelpFile = val;
I 37
		if (HelpFile[0] == '\0')
E 50
I 50
		if (val[0] == '\0')
E 50
			HelpFile = "sendmail.hf";
I 50
		else
			HelpFile = newstr(val);
E 50
E 37
		break;

I 90
	  case 'I':		/* use internet domain name server */
		UseNameServer = atobool(val);
		break;

E 90
I 37
	  case 'i':		/* ignore dot lines in message */
D 50
		IgnrDot = bval;
E 50
I 50
		IgnrDot = atobool(val);
E 50
		break;

E 37
	  case 'L':		/* log level */
D 50
		LogLevel = ival;
E 50
I 50
		LogLevel = atoi(val);
E 50
		break;

I 92
	  case 'l':		/* collect message size limit */
		MaxMessageSize = atol(val);
		break;

E 92
I 37
	  case 'M':		/* define macro */
D 50
		define(val[0], &val[1]);
E 50
I 50
		define(val[0], newstr(&val[1]), CurEnv);
I 68
		sticky = FALSE;
E 68
E 50
		break;

	  case 'm':		/* send to me too */
D 50
		MeToo = bval;
E 50
I 50
		MeToo = atobool(val);
E 50
		break;
I 64

I 86
	  case 'n':		/* validate RHS in newaliases */
		CheckAliases = atobool(val);
		break;

E 86
# ifdef DAEMON
	  case 'N':		/* home (local?) network name */
		NetName = newstr(val);
		break;
# endif DAEMON
E 64
I 53
D 61

#ifdef DAEMON
	  case 'N':		/* maximum simultaneous SMTP connections */
		MaxConnections = atoi(val);
		break;
#endif DAEMON
E 61
E 53

	  case 'o':		/* assume old style headers */
D 48
		CurEnv->e_oldstyle = bval;
E 48
I 48
D 50
		if (bval)
E 50
I 50
		if (atobool(val))
E 50
			CurEnv->e_flags |= EF_OLDSTYLE;
		else
			CurEnv->e_flags &= ~EF_OLDSTYLE;
I 79
		break;

	  case 'P':		/* postmaster copy address for returned mail */
		PostMasterCopy = newstr(val);
		break;

	  case 'q':		/* slope of queue only function */
		QueueFactor = atoi(val);
E 79
E 48
		break;

E 37
	  case 'Q':		/* queue directory */
D 50
		QueueDir = val;
I 37
		if (QueueDir[0] == '\0')
E 50
I 50
		if (val[0] == '\0')
E 50
			QueueDir = "mqueue";
I 50
		else
			QueueDir = newstr(val);
E 50
E 37
		break;

I 91
	  case 'R':		/* do not relay mail coming from Inet */
		NoInetRelay = atobool(val);
		break;

E 91
	  case 'r':		/* read timeout */
D 50
		ReadTimeout = tval;
E 50
I 50
		ReadTimeout = convtime(val);
E 50
		break;

	  case 'S':		/* status file */
D 50
		StatFile = val;
I 37
		if (StatFile[0] == '\0')
E 50
I 50
		if (val[0] == '\0')
E 50
			StatFile = "sendmail.st";
I 50
		else
			StatFile = newstr(val);
E 50
E 37
		break;

D 36
# ifdef V6
	  case 's':		/* standard time time zone */
		StdTimeZone = val;
E 36
I 36
	  case 's':		/* be super safe, even if expensive */
D 50
		SuperSafe = bval;
E 50
I 50
		SuperSafe = atobool(val);
E 50
E 36
		break;
D 36
# endif V6
E 36

	  case 'T':		/* queue timeout */
D 50
		TimeOut = tval;
E 50
I 50
		TimeOut = convtime(val);
E 50
D 88
		break;
E 88
I 88
		/*FALLTHROUGH*/
E 88

I 36
	  case 't':		/* time zone name */
D 88
# ifdef V6
D 50
		StdTimezone = val;
		DstTimezone = index(val, ',');
E 50
I 50
		StdTimezone = newstr(val);
		DstTimezone = index(StdTimeZone, ',');
E 50
		if (DstTimezone == NULL)
D 50
			goto syntax;
		*DstTimezone++ = '\0';
E 50
I 50
			syserr("bad time zone spec");
		else
			*DstTimezone++ = '\0';
E 50
# endif V6
E 88
		break;

E 36
	  case 'u':		/* set default uid */
I 37
D 43
		if (!safe)
			goto syntax;
E 37
		DefUid = ival;
E 43
I 43
D 71
		if (safe)
D 50
			DefUid = ival;
E 50
I 50
			DefUid = atoi(val);
E 71
I 71
		DefUid = atoi(val);
E 71
E 50
E 43
		break;

D 37
	  case 'X':		/* transcript file template */
		XcriptFile = val;
E 37
I 37
	  case 'v':		/* run in verbose mode */
D 50
		Verbose = bval;
E 50
I 50
		Verbose = atobool(val);
E 50
D 46
		if (Verbose)
			NoConnect = FALSE;
E 46
E 37
		break;
I 39

D 84
# ifdef DEBUG
E 84
I 84
# ifdef SMTP
# ifdef WIZ
E 84
	  case 'W':		/* set the wizards password */
D 43
		if (!safe)
			goto syntax;
		WizWord = val;
E 43
I 43
D 71
		if (safe)
D 50
			WizWord = val;
E 50
I 50
			WizWord = newstr(val);
E 71
I 71
		WizWord = newstr(val);
E 71
E 50
E 43
		break;
D 84
# endif DEBUG
E 84
I 84
# endif WIZ
# endif SMTP
E 84
I 63

	  case 'x':		/* load avg at which to auto-queue msgs */
		QueueLA = atoi(val);
		break;

	  case 'X':		/* load avg at which to auto-reject connections */
		RefuseLA = atoi(val);
		break;
E 63
E 39

I 81
D 82
	  case 'z':		/* fork jobs during queue runs */
E 82
I 82
	  case 'y':		/* work recipient factor */
		WkRecipFact = atoi(val);
		break;

	  case 'Y':		/* fork jobs during queue runs */
E 82
		ForkQueueRuns = atobool(val);
I 82
		break;

	  case 'z':		/* work message class factor */
		WkClassFact = atoi(val);
		break;

	  case 'Z':		/* work time factor */
		WkTimeFact = atoi(val);
E 82
		break;

E 81
	  default:
D 36
		syserr("setoption: line %d: illegal option %c", LineNumber, opt);
E 36
I 36
D 45
	  syntax:
		syserr("setoption: line %d: syntax error on \"%c%s\"",
		       LineNumber, opt, val);
E 45
E 36
		break;
	}
I 68
	if (sticky)
		setbitn(opt, StickyOpt);
E 68
I 45
	return;
I 55
}
/*
**  SETCLASS -- set a word into a class
**
**	Parameters:
**		class -- the class to put the word in.
**		word -- the word to enter
**
**	Returns:
**		none.
**
**	Side Effects:
**		puts the word into the symbol table.
*/

setclass(class, word)
	int class;
	char *word;
{
	register STAB *s;

	s = stab(word, ST_CLASS, ST_ENTER);
	setbitn(class, s->s_class);
E 55
D 50

  syntax:
	syserr("setoption: line %d: syntax error on \"%c%s\"",
	       LineNumber, opt, val);
E 50
E 45
E 35
E 17
E 8
}
E 1
