h47771
s 00003/00003/00544
d D 5.18 06/05/20 16:53:57 msokolov 116 115
c make the return value of username() last forever
e
s 00011/00009/00536
d D 5.17 88/06/30 14:58:27 bostic 115 114
c install approved copyright notice
e
s 00001/00165/00544
d D 5.16 88/04/01 16:50:40 bostic 114 113
c remove V6 #ifdefs
e
s 00016/00010/00693
d D 5.15 88/03/13 19:51:37 bostic 113 112
c add Berkeley specific header
e
s 00001/00001/00702
d D 5.14 86/01/10 16:33:45 eric 112 111
c adjust WkTimeFact so that -q1h will lower relative priorities of
c jobs over long periods, rather than leave them toward the top of the queue
e
s 00031/00000/00672
d D 5.13 86/01/05 19:56:34 eric 111 110
m 
c cleanup for various compilation flags and reasonable organization
e
s 00002/00000/00670
d D 5.12 86/01/05 18:47:52 eric 110 109
m 
c rewrite reply-to and resent-reply-to; save errorqueueu in qf file;
c some performance hacking; some alias handling cleanup; delete leading
c spaces from SMTP lines
e
s 00001/00000/00669
d D 5.11 85/12/17 23:52:53 eric 109 108
m 
c lint
e
s 00012/00005/00657
d D 5.10 85/09/30 21:06:00 eric 108 107
m 
c fixes in setproctitle to avoid problems with titles longer than
c argv + env
e
s 00000/00000/00662
d D 5.9 85/09/24 15:09:33 eric 107 106
m 
c don't step on user environment
e
s 00001/00001/00661
d D 5.8 85/09/21 15:51:58 eric 106 105
m 
c change sign on WkTimeFact so that is closer to what most people want
e
s 00006/00000/00656
d D 5.7 85/09/21 14:44:24 eric 105 104
m 
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00000/00000/00656
d D 5.6 85/09/19 01:25:15 eric 104 102
i 103
m 
c incorporate SMI changes -- still experimental
e
s 00102/00004/00553
d D 5.3.1.1 85/09/19 00:55:24 eric 103 100
m 
c SMI changes (somewhat)
e
s 00002/00002/00556
d D 5.5 85/08/13 18:20:25 miriam 102 101
m 
c Correct error check for lseek as kernel memory is a negative binary value.
e
s 00002/00001/00556
d D 5.4 85/07/31 10:47:53 miriam 101 100
m 
c Make sure getpwuid returns a valid entry before setting myname.
e
s 00003/00027/00554
d D 5.3 85/06/08 10:27:23 eric 100 99
m 
c lint for 4.3 release
e
s 00000/00004/00581
d D 5.2 85/06/07 22:01:37 miriam 99 98
m 
c Resolve duplicate SccsId
e
s 00014/00000/00571
d D 5.1 85/06/07 14:34:54 dist 98 97
m 
c Add copyright
e
s 00006/00002/00565
d D 4.9 85/05/06 20:05:00 eric 97 96
m 
c check syscall return values in a few questions; thanks go to Ian Darwin's
c rudely public ragging on this one.
e
s 00006/00006/00561
d D 4.8 85/05/01 21:23:37 miriam 96 95
m 
c slight rearrangement for efficency
e
s 00010/00000/00557
d D 4.7 85/05/01 16:44:09 miriam 95 94
m 
c Correct for the getlogin problem in username()
e
s 00046/00001/00511
d D 4.6 84/12/05 23:14:07 eric 94 93
m 
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00003/00003/00509
d D 4.5 84/08/11 14:56:30 eric 93 92
m 
c pull configurable vars out of initialized data for freeze files
e
s 00004/00000/00508
d D 4.4 83/08/28 15:37:15 eric 92 91
m 
c set FIOCLEX on /dev/kmem file when getting load average
e
s 00002/00002/00506
d D 4.3 83/08/28 14:59:54 eric 91 90
m 
c Change QueueLA and RefuseLA to 8 and 12 respectively
e
s 00055/00001/00453
d D 4.2 83/08/28 14:43:08 eric 90 89
m 
c Refuse to talk to yourself (i.e., reject HELO packets with your own name).
c Add two thresholds -- option 'x' is the load average at which messages are
c queued rather than delivered (default 12); option 'X' is the load average
c at which incoming TCP connections are refused (default 25).
e
s 00000/00000/00454
d D 4.1 83/07/25 19:43:58 eric 89 88
m 
c 4.2 release version
e
s 00004/00000/00450
d D 3.71 83/04/30 15:11:59 eric 88 87
m 
c lint
e
s 00010/00005/00440
d D 3.70 83/03/06 16:31:01 eric 87 86
m 201
c Handle messages with "Resent-xxx:" header lines properly (basically mark
c the message as being resent); ignore incoming From: lines if their text
c exactly matches our machine-readable address exactly -- this causes the
c full name to be added when called from (e.g.) MH.  Both of these mode are
c to improve interaction with MH.
e
s 00000/00045/00445
d D 3.69 83/02/08 10:50:56 eric 86 85
m 167
m 172
m 173
m 174
c clean up problems when QUEUE compile flag not defined; clean up hostname
c code to run on non-4.1c systems; fix use of -oeq (quiet on errors) flag.
e
s 00004/00010/00486
d D 3.68 83/02/03 07:53:21 eric 85 84
m 168
c Make mailer size limits a per-mailer parameter (M field in the mailer
c descriptor)
e
s 00021/00012/00475
d D 3.67 83/02/02 12:51:46 eric 84 83
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00036/00000/00451
d D 3.66 83/01/17 21:41:23 eric 83 82
m 158
c Set the $w macro to the hostname if at all possible to allow generic
c configuration tables.
e
s 00061/00002/00390
d D 3.65 82/11/28 00:18:23 eric 82 81
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00002/00002/00390
d D 3.64 82/11/17 09:34:03 eric 81 80
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00003/00003/00389
d D 3.63 82/11/05 13:12:28 eric 80 79
m 062
c arrange to freeze the configuration file for quick startup -- this
c technique requires reprocessing the argv so that flag settings don't
c get lost, and is really rather of a hack.
e
s 00019/00028/00373
d D 3.62 82/11/04 13:26:42 eric 79 78
m 037
c put header conditionals into the .cf file
e
s 00006/00000/00395
d D 3.61 82/11/03 09:47:56 eric 78 77
m 049
c Arrange to strip quote bits in message header; move SPACESUB into
c conf.c; change SpaceSub to unquoted dot
e
s 00002/00002/00393
d D 3.60 82/10/27 20:43:43 eric 77 76
m 044
c strip out bcc: and resent-bcc: always
e
s 00000/00035/00395
d D 3.59 82/09/26 17:03:58 eric 76 75
c Put more configuration into setoption; merge some of the argv processing
c with this; move configuration information out of conf.c into the .cf
c file.  Since a lot of stuff will default to zero, a new .cf file is
c required.
e
s 00001/00000/00429
d D 3.58 82/09/26 14:45:04 eric 75 74
c completely instantiate queue files for all mail, even if not needed;
c fix a bug that would probably come up once every ten years in creating
c the queue id.  should merge argv flag processing with option processing.
e
s 00001/00001/00428
d D 3.57 82/09/24 09:37:23 eric 74 73
c arrange to be able to define options; put precedences in .cf file;
c send errors to an Errors-To: field; fix a serious bug causing mail
c to not be delivered to anyone if there were any errors.
e
s 00026/00012/00403
d D 3.56 82/09/05 18:00:25 eric 73 72
c correctly process all sender fields; clean up sender processing code
e
s 00004/00003/00411
d D 3.55 82/08/29 15:52:00 eric 72 71
c give 554 message on syserr (instead of 451) if errno == 0; as it
c was some permanent errors appeared transient
e
s 00000/00001/00414
d D 3.54 82/08/23 11:58:32 eric 71 70
c clean up queueing; log time in queue.
c **** This delta invalidates mqueue files ****
e
s 00001/00001/00414
d D 3.53 82/08/17 20:44:31 eric 70 69
c Mail-From: ==> Received: for new SMTP spec (RFC821)
e
s 00001/00001/00414
d D 3.52 82/08/15 17:31:38 eric 69 68
c mark From: lines with a bit; this should be used later instead of a
c direct strcmp with "from"
e
s 00001/00001/00414
d D 3.51 82/08/08 16:53:36 eric 68 67
c change default log level to 9
e
s 00003/00002/00412
d D 3.50 82/08/08 00:38:36 eric 67 66
c don't delete bcc: lines; force message-id output; default logging level
e
s 00001/00000/00413
d D 3.49 82/07/05 20:52:48 eric 66 65
c improve configuration on timeout
e
s 00004/00003/00409
d D 3.48 82/07/05 12:02:24 eric 65 64
c put timeouts on net reads
e
s 00002/00002/00410
d D 3.47 82/05/31 17:10:15 eric 64 63
c eliminate -V, -D, -p flags in favor of a single flag "-bx"
c (be in mode x).
e
s 00002/00002/00410
d D 3.46 82/05/22 01:36:06 eric 63 62
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00000/00002/00412
d D 3.45 82/05/05 20:42:59 glickman 62 61
c Removed whoami.h.
e
s 00001/00001/00413
d D 3.44 82/03/22 22:12:21 eric 61 60
c 16 bit fixes
e
s 00005/00005/00409
d D 3.43 82/02/20 19:15:21 eric 60 59
c make rewriting of addresses in headers really work.  This adds the $q
c macro.  The rewriting of the From: address is still ad hoc and should
c be integrated into this format.
c Note:  old .cf files will not work with this version.
e
s 00001/00001/00413
d D 3.42 81/12/06 12:37:20 eric 59 58
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00001/00000/00413
d D 3.41 81/12/05 14:13:35 eric 58 57
c insert SMTP "Mail-From:" line.
e
s 00004/00000/00409
d D 3.40 81/12/05 11:52:48 eric 57 56
c put the SMTP and queueing code on compilation flags so that sendmail
c will fit on non-ID PDP-11's (ugh); put the ugly UUCP hack on a
c compilation flag also to emphasize that it sucks eggs; makefile
c cleanup.
e
s 00001/00001/00408
d D 3.39 81/11/07 15:41:02 eric 56 55
c clean up to compile & work on ARPAVAX; move stat file to
c /usr/lib/sendmail.st; fix bug in syserr with error codes
e
s 00002/00015/00407
d D 3.38 81/10/31 22:11:27 eric 55 54
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00005/00000/00417
d D 3.37 81/10/26 14:21:13 eric 54 53
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00002/00002/00415
d D 3.36 81/10/23 19:36:50 eric 53 52
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00002/00001/00415
d D 3.35 81/10/22 10:25:19 eric 52 51
c move stats file to /usr/lib; put location of sendmail.hf in conf.c
e
s 00008/00002/00408
d D 3.34 81/10/17 16:57:29 eric 51 50
c initial prep to put in Daemon mode
e
s 00001/00001/00409
d D 3.33 81/09/24 10:52:31 eric 50 49
c fix botch in ING70 code
e
s 00011/00000/00399
d D 3.32 81/09/24 10:30:15 eric 49 47
c changes to work under a V6 system -- mostly compilation flags
e
s 00001/00006/00393
d D 3.31.1.1 81/09/23 18:22:44 eric 48 47
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00008/00000/00391
d D 3.31 81/09/20 10:46:08 eric 47 46
c don't let a mailer ever execute as root (that should solve the
c security problems!) -- essentially just map root into someone else.
c Adds yet another configuration variable (should this be in the .cf file?
e
s 00001/00001/00390
d D 3.30 81/09/12 15:48:18 eric 46 45
c change From: processing to reduce the number of Original-From:
c lines; change allocation of global variables.
e
s 00076/00000/00315
d D 3.29 81/09/07 14:12:11 eric 45 44
c fix up umask; allow setuid on files to take recipient owner;
c factor some configuration info into conf.c
e
s 00015/00000/00300
d D 3.28 81/09/06 19:47:42 eric 44 43
c cleanup, commenting, linting, etc.
e
s 00009/00006/00291
d D 3.27 81/09/01 11:43:16 eric 43 42
c add "suppress return-to-sender" function
e
s 00012/00000/00285
d D 3.26 81/08/31 21:21:02 eric 42 41
c collect mail statistics; change minor configuration
e
s 00003/00003/00282
d D 3.25 81/08/29 19:15:28 eric 41 40
c drop unneccessary H_FORCE bits
e
s 00002/00002/00283
d D 3.24 81/08/29 19:13:08 eric 40 39
c delete H_DELETE -- can be simulated with H_ACHECK
e
s 00003/00003/00282
d D 3.23 81/08/24 14:05:15 eric 39 38
c Add "-t" option to read To:, Cc:, and Bcc: lines to get recipients
e
s 00001/00000/00284
d D 3.22 81/08/22 17:51:38 eric 38 37
c Arrange to pull full name out of From line if found; includes
c Original-From: hacking (oh so ugly).  There's got to be a better way
c to do this...
e
s 00002/00002/00282
d D 3.21 81/08/21 18:17:44 eric 37 36
c drop M_FINAL, change some other defined constant names
e
s 00011/00039/00273
d D 3.20 81/08/21 16:44:51 eric 36 35
c add the $y macro as the tty name.
e
s 00000/00001/00312
d D 3.19 81/08/20 15:13:07 eric 35 34
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00022/00000/00291
d D 3.18 81/08/18 17:12:20 eric 34 33
c factor out ARPANET FTP reply codes into conf.c
e
s 00023/00017/00268
d D 3.17 81/08/17 09:36:50 eric 33 32
c add header fields from new BB&N proposal ICST/CBOS - 80-2,
c "Specification of a Draft Message Format Standard" for NBS.
e
s 00010/00190/00275
d D 3.16 81/08/09 19:07:59 eric 32 31
c put mailer definitions into configuration file
e
s 00008/00003/00457
d D 3.15 81/08/09 15:01:51 eric 31 30
c lint it
e
s 00023/00008/00437
d D 3.14 81/08/09 12:34:02 eric 30 29
c add private incoming mailers; add q_home field to ADDRESS struct;
c some general cleanup
e
s 00002/00058/00443
d D 3.13 81/04/01 23:37:10 eric 29 28
c eliminate useless garbage
e
s 00003/00002/00498
d D 3.12 81/03/28 13:36:16 eric 28 27
c pass Full-Name field internally to do forwards correctly
e
s 00003/00003/00497
d D 3.11 81/03/28 12:02:13 eric 27 26
c put much more info in cf file (e.g., headers)
e
s 00003/00003/00497
d D 3.10 81/03/20 09:44:32 eric 26 25
c change name (again); from postbox to sendmail
e
s 00007/00008/00493
d D 3.9 81/03/12 10:56:37 eric 25 24
c merge letters to the same host into one message
e
s 00021/00034/00480
d D 3.8 81/03/11 10:45:05 eric 24 23
c general cleanup, esp. macro processor
e
s 00012/00106/00502
d D 3.7 81/03/09 13:20:50 eric 23 22
c first step at rewriting rules, etc.
e
s 00024/00050/00584
d D 3.6 81/03/07 18:18:47 eric 22 21
c split local configurations into seperate files
e
s 00014/00011/00620
d D 3.5 81/03/07 17:45:16 eric 21 20
c drop stupid concatenation stuff; add hi_pptr
e
s 00098/00039/00533
d D 3.4 81/03/07 16:58:37 eric 20 19
c change q_mailer to be index, not pointer
e
s 00000/00053/00572
d D 3.3 81/03/07 15:31:25 eric 19 18
c lint fixes
e
s 00035/00006/00590
d D 3.2 81/03/07 14:25:21 eric 18 17
c ----- delivermail ==> postbox -----
e
s 00065/00002/00531
d D 3.1 81/03/04 09:33:46 eric 17 16
c install fancy header stuff
e
s 00006/00000/00527
d D 2.6 81/02/15 10:03:56 eric 16 15
c add onyx machine
e
s 00009/00001/00518
d D 2.5 81/02/07 10:28:36 eric 15 14
c add ARPAVAX; default to NETV6MAIL at Berkeley
e
s 00013/00001/00506
d D 2.4 81/01/10 12:38:34 eric 14 13
c add an "ArpaLocal"
e
s 00007/00002/00500
d D 2.3 81/01/10 12:19:42 eric 13 12
c have name of mailer daemon be a configuration parameter
e
s 00006/00001/00496
d D 2.2 80/11/21 12:57:28 eric 12 11
c have right user & time come out for msgs
e
s 00000/00000/00497
d D 2.1 80/11/05 11:01:17 eric 11 10
c release 2
e
s 00002/00002/00495
d D 1.10 80/10/21 22:38:44 eric 10 9
c EX_UNAVAIL => EX_UNAVAILABLE
e
s 00034/00005/00463
d D 1.9 80/10/20 13:12:45 eric 9 8
c tried to clean up for non-berkeley site
e
s 00088/00031/00380
d D 1.8 80/10/11 18:11:18 eric 8 7
c cleanup to simplify configuration & fix minor bugs
e
s 00007/00007/00404
d D 1.7 80/10/03 16:45:32 eric 7 6
c MyLocNam => MyLocName for consistency with main.c
e
s 00001/00001/00410
d D 1.6 80/09/27 11:21:55 eric 6 5
c don't ignore host in comparing UUCP addresses
e
s 00016/00008/00395
d D 1.5 80/08/12 13:48:46 eric 5 4
c add UUCP local address & remove cruft
e
s 00000/00039/00403
d D 1.4 80/08/02 13:48:26 eric 4 3
c cleaned up comments
e
s 00002/00000/00440
d D 1.3 80/07/25 22:02:56 eric 3 2
c add ID keywords
e
s 00002/00002/00438
d D 1.2 80/06/24 23:33:44 eric 2 1
c attempted fixes to quote problem(s)
e
s 00440/00000/00000
d D 1.1 80/06/23 08:23:40 eric 1 0
e
u
U
f b 
f i 
t
T
I 98
/*
I 115
 * Copyright (c) 1983 Eric P. Allman
E 115
D 113
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 113
I 113
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 115
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 115
I 115
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
E 115
 */
E 113

#ifndef lint
D 113
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 113
I 113
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 113

E 98
I 1
D 35
# include <stdio.h>
E 35
# include <pwd.h>
I 92
# include <sys/ioctl.h>
I 103
# ifdef sun
# include <sys/param.h>
# endif sun
E 103
E 92
D 18
# include "dlvrmail.h"
E 18
I 18
D 26
# include "postbox.h"
E 26
I 26
# include "sendmail.h"
E 26
E 18
I 3

D 8
static char SccsId[] = "%W%	%G%";
E 3
# include <whoami.h>

E 8
/*
D 18
**  CONF.C -- Delivermail Configuration Tables.
E 18
I 18
D 26
**  CONF.C -- Postbox Configuration Tables.
E 26
I 26
**  CONF.C -- Sendmail Configuration Tables.
E 26
E 18
**
**	Defines the configuration of this installation.
**
D 8
**	The first table describes available mailers.  This is
**	just a list of argument vectors, with the following
**	codes embedded:
**		$u -- insert the user name.
**		$h -- insert the host name.
**		$f -- insert the from person name.
**		$c -- insert the hop count.
**	This stuff is interpreted in buildmail.  There are two
**	important conventions here: entry zero must be the
**	local mailer & entry one must be the shell.
E 8
I 8
**	Compilation Flags:
D 29
**		HASARPA -- set if this machine has a connection to
**			the Arpanet.
**		HASUUCP -- set if this machine has a connection to
**			the UUCP network.
E 29
D 32
**		NETV6MAIL -- set if you want to use "v6mail" that
**			comes with the Berkeley network.  Normally
**			/bin/mail will work fine, but around Berkeley
**			we use v6mail because it is a "fixed target".
I 15
**			Also, only v6mail has the "/dev/mail" stuff
**			in it (for biff(1)).
E 32
E 15
D 114
**		V6 -- running on a version 6 system.  This determines
**			whether to define certain routines between
**			the two systems.  If you are running a funny
**			system, e.g., V6 with long tty names, this
**			should be checked carefully.
E 114
I 90
**		VMUNIX -- running on a Berkeley UNIX system.
E 90
I 9
D 29
**		DUMBMAIL -- set if your /bin/mail doesn't have the
**			-d flag.
E 29
E 9
E 8
**
D 8
**	The second table gives a list of special characters.  This
**	table is scanned linearly by parse() until an entry is
**	found using one of the magic characters.  Other fields
**	give more information on how to handle it.
**
**	Defined Constants:
**		M_* -- indices into Mailer, used only in this module.
**
**	Defines:
**		Mailer -- the mailer descriptor table.
**		ParseTab -- the parse table.
**
**	Notes:
**		Ingres 11/70 version.
**
**	History:
**		3/5/80 -- Generalized to use <whoami.h>.
**		12/26/79 -- written for Ingres 11/70.
E 8
I 8
**	Configuration Variables:
D 9
**		ArpaHost -- the name of the host through which arpanet
**			mail will be sent.
E 9
I 9
D 23
**		ArpaHost -- the arpanet name of the host through
**			which arpanet mail will be sent.
E 9
**		MyLocName -- the name of the host on a local network.
**			This is used to disambiguate the contents of
**			ArpaHost among many hosts who may be sharing
**			a gateway.
I 14
**		DaemonName -- the name of this agent for use in
**			error messages, typically "~MAILER~DAEMON~"
**			at this host on the local net.
E 14
I 9
**		ArpaLocal -- a list of local names for this host on
**			the arpanet.  Only functional if HASARPA set.
**		UucpLocal -- ditto for the Arpanet.
**		BerkLocal -- ditto for the Berknet.
E 23
E 9
D 32
**		Mailer -- a table of mailers known to the system.
D 29
**			The fields are:
E 29
I 29
**			This should be fairly static.  The fields are:
E 29
**			- the pathname of the mailer.
**			- a list of flags describing the properties
**			  of this mailer:
**			   M_FOPT -- if set, the mailer has a picky "-f"
**				option.  In this mode, the mailer will
**				only accept the "-f" option if the
**				sender is actually "root", "network",
**				and possibly (but not necessarily) if
**				the -f argument matches the real sender.
**				The effect is that if the "-f" option
D 18
**				is given to delivermail then it will be
E 18
I 18
D 26
**				is given to postbox then it will be
E 26
I 26
**				is given to sendmail then it will be
E 26
E 18
**				passed through (as arguments 1 & 2) to
**				the mailer.
**			   M_ROPT -- identical to M_FOPT, except uses
**				-r instead.
**			   M_QUIET -- if set, don't print a message if
**				the mailer returns bad status.
**			   M_RESTR -- if set, this mailer is restricted
**				to use by "daemon"; otherwise, we do a
**				setuid(getuid()) before calling the
**				mailer.
D 24
**			   M_HDR -- if set, the mailer wants us to
**				insert a UNIX "From" line before
E 24
I 24
**			   M_NHDR -- if set, the mailer doesn't want us
**				to insert a UNIX "From" line before
E 24
**				outputing.
I 12
D 24
**			   M_FHDR -- if set, the header that we
**				generate will be used literally, so
**				we must force it to be correct.  The
**				effect is that we generate a header
**				even if one exists.
E 24
E 12
**			   M_NOHOST -- if set, this mailer doesn't care
**				about the host part (e.g., the local
**				mailer).
**			   M_STRIPQ -- if set, strip quote (`"')
**				characters out of parameters as you
**				transliterate them into the argument
**				vector.  For example, the local mailer
**				is called directly, so these should be
**				stripped, but the program-mailer (i.e.,
**				csh) should leave them in.
I 17
**			   M_NEEDDATE -- this mailer requires a Date:
**				field in the message.
**			   M_NEEDFROM -- this mailer requires a From:
**				field in the message.
**			   M_MSGID -- this mailer requires a Message-Id
**				field in the message.
D 24
**			   M_COMMAS -- this mailer wants comma-
**				seperated To: and Cc: fields.
**			   M_ARPAFMT == M_NEEDDATE|M_NEEDFROM|M_MSGID|
**				M_COMMAS.
E 24
I 24
**			   M_ARPAFMT == M_NEEDDATE|M_NEEDFROM|M_MSGID.
E 24
E 17
**			- an exit status to use as the code for the
**			  error message print if the mailer returns
**			  something we don't understand.
**			- A list of names that are to be considered
**			  "local" (and hence are stripped off) for
**			  this mailer.
**			- An argument vector to be passed to the
D 29
**			  mailer with the following substitutions:
**			   $f - the from person name.
**			   $u - the target user name.
**			   $h - the target user host.
**			   $c - the hop count.
E 29
I 29
**			  mailer; this is macro substituted.
E 29
**			>>>>>>>>>> Entry zero must be for the local
**			>> NOTE >> mailer and entry one must be for
**			>>>>>>>>>> the shell.
E 32
D 23
**		ParseTab -- a table driving the parsing process.  Each
**			entry contains:
**			- a character that will trigger this entry.
**			- an index into the Mailer table.
D 18
**			- a word of flags, described in dlvrmail.h.
E 18
I 18
**			- a word of flags, described in postbox.h.
E 18
**			- an argument.  If we have P_MAP, it is the
**			  character to turn the trigger character into.
**			  If we have P_MOVE, it is the site to send it
**			  to, using the mailer specified above.
I 9
**			This table will almost certainly have to be
**			changed on your site if you have anything more
**			than the UUCP net.
E 23
I 17
**		HdrInfo -- a table describing well-known header fields.
**			Each entry has the field name and some flags,
D 33
**			which can be:
D 21
**			H_CONCAT -- if there is more than one field
**				of this name, turn it into a comma-
**				seperated list.
**			H_DELETE -- delete this field.
E 21
I 21
**			- H_EOH -- this field is equivalent to a blank
**			  line; i.e., it signifies end of header.
**			- H_DELETE -- delete this field.
**			There is also a field pointing to a pointer
**			that should be set to point to this header.
E 33
I 33
**			which are described in sendmail.h.
I 44
D 76
**		StdTimezone -- name of local timezone in standard time
**			(V6 only).
**		DstTimezone -- name of local timezone in daylight savings
**			time (V6 only).
E 76
E 44
E 33
I 32
**
**	Notes:
**		I have tried to put almost all the reasonable
**		configuration information into the configuration
**		file read at runtime.  My intent is that anything
**		here is a function of the version of UNIX you
**		are running, or is really static -- for example
**		the headers are a superset of widely used
**		protocols.  If you find yourself playing with
**		this file too much, you may be making a mistake!
E 32
E 21
E 17
E 9
E 8
*/




I 8
D 59
static char SccsId[] = "%W%	%G%";
E 59
I 59
D 99
SCCSID(%W%	%Y%	%G%);
E 59
E 8
D 48

I 8

D 9
char	*ArpaHost = "Berkeley";	/* host name of gateway on Arpanet */
E 9
D 19
bool	UseMsgId = FALSE;	/* don't put message id's in anywhere */

E 19
D 62
# include <whoami.h>		/* definitions of machine id's at berkeley */
D 32

I 9
# ifdef BERKELEY
I 14
D 29

E 29
E 14
D 23
char	*ArpaHost = "Berkeley";	/* host name of gateway on Arpanet */
I 17
D 22
char	*UucpHost = "ucbvax";	/* host name of gateway on UUCP net */
E 22
# define BerkHost   MyLocName	/* host name of gateway on Berk net */
E 23
E 17
I 15
# define NETV6MAIL		/* use /usr/net/bin/v6mail for local delivery */
E 15
I 14
D 29

E 14
D 22
# else BERKELEY
I 14

E 14
char	*ArpaHost = "[unknown]";
char	*MyLocName = sysname;
# define HASUUCP		/* default to having UUCP net */
char	*UucpLocal[] = { sysname, NULL };
I 14

E 14
# endif BERKELEY

I 14

E 22
/* Specific Configurations for Berkeley Machines */

D 22
/* Berkeley people: mail changes to csvax:eric or they will be lost! */
E 22
I 22
/* Berkeley people: mail changes to ingvax:eric or they will be lost! */
E 22

E 14
E 9
E 8
# ifdef ING70
D 22
static char	*BerkLocal[] = { "i", "ingres", "ing70", NULL };
I 5
D 14
# define ArpaLocal	NULL
E 14
I 14
char		*ArpaLocal = { "berkeley", "ucb", NULL };
E 14
E 5
D 7
char		*MyLocNam = "Ing70";
E 7
I 7
char		*MyLocName = "Ing70";
I 13
char		*DaemonName = "Ing70:~MAILER~DAEMON~";
E 13
E 7
# define HASARPA
# define V6
E 22
I 22
# include "c.ing70.h"
E 22
# endif ING70

# ifdef INGVAX
D 9
/* untested */
E 9
D 22
static char	*BerkLocal[] = { "j", "ingvax", NULL };
D 7
char		*MyLocNam = "IngVax";
E 7
I 7
char		*MyLocName = "IngVax";
I 13
char		*DaemonName = "IngVax:~MAILER~DAEMON~";
E 22
I 22
# include "c.ingvax.h"
E 22
E 13
E 7
# endif INGVAX

# ifdef CSVAX
D 9
/* untested */
E 9
D 22
static char	*BerkLocal[] = { "v", "csvax", "vax", NULL };
D 5
char		*MyLocNam = "CSVax";
E 5
I 5
static char	*UucpLocal[] = { "ucbvax", "ernie", NULL };
D 7
char		*MyLocNam = "CSVAX";
E 7
I 7
char		*MyLocName = "CSVAX";
I 13
char		*DaemonName = "CSVAX:~MAILER~DAEMON~";
E 13
E 7
E 5
# define HASUUCP
E 22
I 22
# include "c.csvax.h"
E 22
D 15
# define NETV6MAIL
E 15
# endif CSVAX
I 15

# ifdef ARPAVAX
D 22
static char	*BerkLocal[] = { "r", "arpavax", NULL };
char		*MyLocName = "ARPAVAX";
char		*DaemonName = "ARPAVAX:~MAILER~DAEMON~";
E 22
I 22
# include "c.arpavax.h"
E 22
# endif ARPAVAX
E 15

# ifdef CORY
D 13
/* untested */
E 13
D 22
static char	*BerkLocal[] = { "y", "cory", NULL };
D 7
char		*MyLocNam = "Cory";
E 7
I 7
char		*MyLocName = "Cory";
I 13
char		*DaemonName = "Cory:~MAILER~DAEMON~";
E 22
I 22
# include "c.cory.h"
E 22
E 13
E 7
# endif CORY

I 16
# ifdef ONYX
D 22
static char	*BerkLocal[[] = { "x", "onyx", NULL };
char		*MyLocName = "Onyx";
char		*DaemonName = "Onyx:~MAILER~DAEMON~";
E 22
I 22
# include "c.onyx.h"
E 22
# endif ONYX

E 16
# ifdef IMAGE
D 22
/* untested */
static char	*BerkLocal[] = { "m", "image", NULL };
D 7
char		*MyLocNam = "Image";
E 7
I 7
char		*MyLocName = "Image";
I 13
char		*DaemonName = "Image:~MAILER~DAEMON~";
E 13
E 7
# define V6
E 22
I 22
# include "c.image.h"
E 22
# endif IMAGE

# ifdef ESVAX
D 13
/* untested */
E 13
D 22
static char	*BerkLocal[] = { "o", "esvax", NULL };
D 5
char		*MyLocNam = "ESVax";
E 5
I 5
D 7
char		*MyLocNam = "ESVAX";
E 7
I 7
char		*MyLocName = "ESVAX";
I 13
char		*DaemonName = "ESVAX:~MAILER~DAEMON~";
E 22
I 22
# include "c.esvax.h"
E 22
E 13
E 7
E 5
# endif ESVAX

# ifdef EECS40
D 22
/* untested */
static char	*BerkLocal[] = { "z", "eecs40", NULL };
D 7
char		*MyLocNam = "EECS40";
E 7
I 7
char		*MyLocName = "EECS40";
I 13
char		*DaemonName = "EECS40:~MAILER~DAEMON~";
E 13
E 7
# define V6
E 22
I 22
# include "c.eecs40.h"
E 22
# endif EECS40

I 22
# else BERKELEY
E 22
I 5

I 22
D 23
char	*ArpaHost = "[unknown]";
char	*MyLocName = sysname;
E 23
# define HASUUCP		/* default to having UUCP net */
D 23
char	*UucpLocal[] = { sysname, NULL };
# define BerkMerge	NULL	/* don't merge any berknet sites */
# define UucpMerge	NULL	/* don't merge any UUCP sites */
E 23

E 29
# endif BERKELEY



E 22
D 23
# ifndef HASARPA
# define ArpaLocal	NULL
# endif HASARPA

# ifndef HASUUCP
# define UucpLocal	NULL
# endif HASUUCP


E 23
E 5
D 20
struct mailer Mailer[] =
E 20
I 20
/* local mail -- must be #0 */
static char	*LocalArgv[] =
E 20
{
D 20
	/* local mail -- must be #0 */
	{
E 20
I 20
	"...local%mail",
	"-d",
	"$u",
	NULL
};

static struct mailer	LocalMailer =
{
E 20
# ifdef NETV6MAIL
D 20
		"/usr/net/bin/v6mail",
E 20
I 20
D 24
	"/usr/net/bin/v6mail",
E 24
I 24
	"local",	"/usr/net/bin/v6mail",
E 24
E 20
# else
D 20
		"/bin/mail",
E 20
I 20
D 24
	"/bin/mail",
E 24
I 24
	"local",	"/bin/mail",
E 24
E 20
# endif
D 17
		M_ROPT|M_NOHOST|M_STRIPQ,	EX_NOUSER,	NULL,
E 17
I 17
D 20
		M_ROPT|M_NOHOST|M_STRIPQ|M_ARPAFMT,	EX_NOUSER,	NULL,
		"$f",		NULL,
E 17
		{ "...local%mail", "-d", "$u", NULL }
	},
	/* pipes through programs -- must be #1 */
	{
		"/bin/csh",
D 10
		M_HDR|M_NOHOST,			EX_UNAVAIL,	NULL,
E 10
I 10
D 12
		M_HDR|M_NOHOST,			EX_UNAVAILABLE,	NULL,
E 12
I 12
		M_HDR|M_FHDR|M_NOHOST,		EX_UNAVAILABLE,	NULL,
I 17
		"$f",		NULL,
E 17
E 12
E 10
		{ "...prog%mail", "-fc", "$u", NULL }
	},
	/* local berkeley mail */
	{
		"/usr/net/bin/sendberkmail",
D 2
		M_FOPT|M_HDR,			EX_UNAVAIL,	BerkLocal,
E 2
I 2
D 10
		M_FOPT|M_HDR|M_STRIPQ,		EX_UNAVAIL,	BerkLocal,
E 10
I 10
		M_FOPT|M_HDR|M_STRIPQ,		EX_UNAVAILABLE,	BerkLocal,
I 17
		"$B:$f",	NULL,
E 17
E 10
E 2
		{ "...berk%mail", "-m", "$h", "-t", "$u", "-h", "$c", NULL }
	},
	/* arpanet mail */
	{
		"/usr/lib/mailers/arpa",
D 2
		0,				0,		NULL,
E 2
I 2
D 5
		M_STRIPQ,			0,		NULL,
E 5
I 5
D 17
		M_STRIPQ,			0,		ArpaLocal,
E 17
I 17
		M_STRIPQ|M_ARPAFMT,		0,		ArpaLocal,
		"$f@$A",	NULL,
E 17
E 5
E 2
		{ "...arpa%mail", "$f", "$h", "$u", NULL }
	},
	/* uucp mail (cheat & use Bell's v7 mail) */
	{
D 5
# ifdef UCKMAIL
		"/bin/badmail",
# else
E 5
		"/bin/mail",
D 5
# endif
		M_ROPT|M_NOHOST|M_STRIPQ,	EX_NOUSER,	NULL,
E 5
I 5
D 6
		M_ROPT|M_NOHOST|M_STRIPQ,	EX_NOUSER,	UucpLocal,
E 6
I 6
		M_ROPT|M_STRIPQ,		EX_NOUSER,	UucpLocal,
I 17
		"$U!$f",	NULL,
E 20
I 20
D 23
	M_ROPT|M_NOHOST|M_STRIPQ|M_ARPAFMT,	EX_NOUSER,	NULL,
	"$f",		NULL,			LocalArgv,
E 23
I 23
D 24
	"local",	M_ROPT|M_NOHOST|M_STRIPQ|M_ARPAFMT,	EX_NOUSER,
	"$f",		LocalArgv,
E 24
I 24
	M_ROPT|M_NOHOST|M_STRIPQ|M_ARPAFMT|M_MUSER|M_NHDR,
	EX_NOUSER,	"$f",		LocalArgv,	NULL,
E 24
E 23
};

D 24
/* pipes through programs -- must be #1 */
E 24
I 24
/* pipes through programs -- must be #1 -- also used for files */
E 24
static char	*ProgArgv[] =
{
	"...prog%mail",
	"-fc",
	"$u",
	NULL
};

static struct mailer	ProgMailer =
{
D 24
	"/bin/csh",
D 23
	M_HDR|M_FHDR|M_NOHOST,			EX_UNAVAILABLE,	NULL,
	"$f",		NULL,			ProgArgv,
E 23
I 23
	"prog",		M_HDR|M_FHDR|M_NOHOST,			EX_UNAVAILABLE,
	"$f",		ProgArgv,
E 24
I 24
	"prog",		"/bin/csh",
	M_NOHOST|M_ARPAFMT,
	EX_UNAVAILABLE, "$f",		ProgArgv,	NULL,
E 24
E 23
};

I 30
/* user-private mailers -- must be #2 */
static char	*PrivArgv[] =
{
	"...priv%mail",
	"$u",
	NULL
};

static struct mailer	PrivMailer =
{
	"priv",		NULL,
	M_ROPT|M_NOHOST|M_STRIPQ|M_ARPAFMT,
	EX_UNAVAILABLE,	"$f",		PrivArgv,	NULL,
};

E 30
/* local berkeley mail */
static char	*BerkArgv[] =
{
	"...berk%mail",
	"-m",
	"$h",
D 25
	"-t",
	"$u",
E 25
	"-h",
	"$c",
I 25
	"-t",
	"$u",
E 25
	NULL
};

static struct mailer	BerkMailer =
{
D 24
	"/usr/net/bin/sendberkmail",
D 23
	M_FOPT|M_HDR|M_STRIPQ,			EX_UNAVAILABLE,	BerkLocal,
D 22
	"$B:$f",	NULL,			BerkArgv,
E 22
I 22
	"$B:$f",	BerkMerge,		BerkArgv,
E 23
I 23
	"berk",		M_FOPT|M_HDR|M_STRIPQ,			EX_UNAVAILABLE,
	"$B:$f",	BerkArgv,
E 24
I 24
	"berk",		"/usr/net/bin/sendberkmail",
D 25
	M_FOPT|M_ARPAFMT|M_STRIPQ|M_MUSER,
E 25
I 25
D 28
	M_FOPT|M_ARPAFMT|M_STRIPQ,
E 28
I 28
	M_FOPT|M_NEEDDATE|M_FULLNAME|M_STRIPQ,
E 28
E 25
	EX_UNAVAILABLE,	"$B:$f",	BerkArgv,	NULL,
E 24
E 23
E 22
};

/* arpanet mail */
static char	*ArpaArgv[] =
{
	"...arpa%mail",
	"$f",
	"$h",
	"$u",
	NULL
};

static struct mailer	ArpaMailer =
{
D 24
	"/usr/lib/mailers/arpa",
D 23
	M_STRIPQ|M_ARPAFMT,			0,		ArpaLocal,
	"$f@$A",	NULL,			ArpaArgv,
E 23
I 23
	"arpa",		M_STRIPQ|M_ARPAFMT,			0,
	"$f@$A",	ArpaArgv,
E 24
I 24
	"arpa",		"/usr/lib/mailers/arpa",
	M_STRIPQ|M_ARPAFMT|M_USR_UPPER,
	0,		"$f@$A",	ArpaArgv,	NULL,
E 24
E 23
};

/* uucp mail (cheat & use Bell's v7 mail) */
static char	*UucpArgv[] =
{
	"...uucp%mail",
E 20
E 17
E 6
E 5
D 24
# ifdef DUMBMAIL
E 24
I 24
D 25
# ifndef DUMBMAIL
E 24
D 20
		{ "...uucp%mail", "$h!$u", NULL }
# else
		{ "...uucp%mail", "-d", "$h!$u", NULL }
E 20
I 20
	"-d",
E 20
# endif DUMBMAIL
D 20
	},
E 20
I 20
	"$h!$u",
E 25
I 25
	"-",
	"$h!rmail",
	"($u)",
E 25
	NULL
E 20
};

I 20
static struct mailer	UucpMailer =
{
D 24
	"/bin/mail",
D 23
	M_ROPT|M_STRIPQ,			EX_NOUSER,	UucpLocal,
D 22
	"$U!$f",	NULL,			UucpArgv,
E 22
I 22
	"$U!$f",	UucpMerge,		UucpArgv,
E 23
I 23
	"uucp",		M_ROPT|M_STRIPQ,			EX_NOUSER,
	"$U!$f",	UucpArgv,
E 24
I 24
D 25
	"uucp",		"/bin/mail",
E 25
I 25
	"uucp",		"/usr/bin/uux",
E 25
D 28
	M_ROPT|M_STRIPQ|M_ARPAFMT|M_MUSER,
E 28
I 28
	M_ROPT|M_STRIPQ|M_NEEDDATE|M_FULLNAME|M_MUSER,
E 28
	EX_NOUSER,	"$U!$f",	UucpArgv,	NULL,
E 24
E 23
E 22
};

struct mailer	*Mailer[] =
{
	&LocalMailer,		/* 0 -- must be 0 */
	&ProgMailer,		/* 1 -- must be 1 */
D 30
	&BerkMailer,		/* 2 */
	&ArpaMailer,		/* 3 */
	&UucpMailer,		/* 4 */
E 30
I 30
	&PrivMailer,		/* 2 -- must be 2 */
	&BerkMailer,		/* 3 */
	&ArpaMailer,		/* 4 */
	&UucpMailer,		/* 5 */
E 30
I 23
	NULL
E 23
};

D 23
# define NMAILERS	(sizeof Mailer / sizeof Mailer[0])
E 23
I 23
D 24
# define NMAILERS	((sizeof Mailer / sizeof Mailer[0]) - 1)
E 23

E 24
E 20
D 30
# define M_LOCAL	0
I 20
# define M_PROG		1
E 20
# define M_BERK		2
# define M_ARPA		3
# define M_UUCP		4
E 30
I 30
/* offsets for arbitrary mailers */
# define M_BERK		2	/* berknet */
# define M_ARPA		3	/* arpanet */
# define M_UUCP		4	/* UUCPnet */
E 30
I 20
D 24

/* list of messages for each mailer (sorted by host) */
ADDRESS		MailList[NMAILERS];
E 24
E 20



E 32
I 9
D 23
# ifdef BERKELEY
E 9
struct parsetab ParseTab[] =
{
	':',	M_BERK,		P_ONE,				NULL,
# ifdef HASARPA
	'@',	M_ARPA,		P_HLAST|P_USR_UPPER,		NULL,
# else
	'@',	M_BERK,		P_HLAST|P_USR_UPPER|P_MOVE,	"ing70",
# endif HASARPA
	'^',	-1,		P_MAP,				"!",
# ifdef HASUUCP
	'!',	M_UUCP,		0,				NULL,
# else
	'!',	M_BERK,		P_MOVE,				"csvax",
# endif HASUUCP
	'.',	-1,		P_MAP|P_ONE,			":",
	'\0',	M_LOCAL,	P_MOVE,				"",
};
I 9
# else BERKELEY
struct parsetab ParseTab[] =
{
# ifdef HASARPA
	'@',	M_ARPA,		P_HLAST|P_USR_UPPER,		NULL,
# endif HASARPA
# ifdef HASUUCP
	'^',	-1,		P_MAP,				"!",
	'!',	M_UUCP,		0,				NULL,
# endif HASUUCP
	'\0',	M_LOCAL,	P_MOVE,				"",
};
# endif BERKELEY
E 23
I 17

E 62

E 99
/*
E 48
I 48
/*
E 48
**  Header info table
I 21
**	Final (null) entry contains the flags used for any other field.
I 33
**
**	Not all of these are actually handled specially by sendmail
**	at this time.  They are included as placeholders, to let
**	you know that "someday" I intend to have sendmail do
**	something with them.
E 33
E 21
*/

struct hdrinfo	HdrInfo[] =
{
I 73
D 79
		/* date information */
	"posted-date",		0,			0,
E 73
D 21
	"date",		0,
	"from",		0,
	"to",		H_CONCAT,
	"cc",		H_CONCAT,
	"subject",	0,
	"message-id",	0,
	NULL,		0
E 21
I 21
D 27
	"date",		0,			NULL,
	"from",		0,			NULL,
E 27
I 27
D 33
	"date",		H_CHECK,		M_NEEDDATE,
	"from",		H_CHECK,		M_NEEDFROM,
I 28
	"full-name",	H_ACHECK,		M_FULLNAME,
E 28
E 27
	"to",		0,			NULL,
	"cc",		0,			NULL,
	"subject",	0,			NULL,
D 27
	"message-id",	0,			&MsgId,
E 27
I 27
	"message-id",	H_CHECK,		M_MSGID,
E 27
	"message",	H_EOH,			NULL,
	NULL,		0,			NULL,
E 33
I 33
	"date",			H_CHECK,		M_NEEDDATE,
D 60
	"from",			H_CHECK,		M_NEEDFROM,
E 60
I 60
D 69
	"from",			H_ADDR|H_CHECK,		M_NEEDFROM,
E 69
I 69
D 73
	"from",			H_ADDR|H_FROM|H_CHECK,	M_NEEDFROM,
E 73
I 73
	"resent-date",		0,			0,
	"received-date",	H_CHECK,		M_LOCAL,
E 79
		/* originator fields, most to least significant  */
D 79
	"resent-sender",	H_FROM,			0,
	"resent-from",		H_FROM,			0,
	"sender",		H_FROM,			0,
	"from",			H_FROM|H_CHECK,		M_NEEDFROM,
E 73
E 69
E 60
I 38
D 40
	"original-from",	H_DELETE,		0,		/* internal */
E 40
I 40
D 46
	"original-from",	H_ACHECK,		0,		/* internal */
E 46
I 46
D 74
	"original-from",	0,			0,
E 74
E 46
E 40
E 38
D 60
	"sender",		0,			0,
E 60
I 60
D 73
	"sender",		H_ADDR,			0,
E 73
E 60
	"full-name",		H_ACHECK,		M_FULLNAME,
D 39
	"to",			0,			0,
	"cc",			0,			0,
	"bcc",			0,			0,
E 39
I 39
D 41
	"to",			H_ADDR|H_FORCE,		0,
	"cc",			H_ADDR|H_FORCE,		0,
D 40
	"bcc",			H_ADDR|H_DELETE|H_FORCE,0,
E 40
I 40
	"bcc",			H_ADDR|H_ACHECK|H_FORCE,0,
E 41
I 41
D 60
	"to",			H_ADDR,			0,
	"cc",			H_ADDR,			0,
	"bcc",			H_ADDR|H_ACHECK,	0,
E 60
I 60
D 73
	"to",			H_ADDR|H_RCPT,		0,
	"cc",			H_ADDR|H_RCPT,		0,
D 67
	"bcc",			H_ADDR|H_ACHECK|H_RCPT,	0,
E 60
E 41
E 40
E 39
	"message-id",		H_CHECK,		M_MSGID,
E 67
I 67
	"bcc",			H_ADDR|H_RCPT,		0,
E 73
I 73
	"received-from",	H_CHECK,		M_LOCAL,
	"return-receipt-to",	H_FROM,			0,
I 74
	"errors-to",		H_FROM,			0,
E 79
I 79
D 87
	"resent-sender",	H_FROM,
	"resent-from",		H_FROM,
E 87
I 87
	"resent-sender",	H_FROM|H_RESENT,
	"resent-from",		H_FROM|H_RESENT,
I 110
	"resent-reply-to",	H_FROM|H_RESENT,
E 110
E 87
	"sender",		H_FROM,
	"from",			H_FROM,
I 110
	"reply-to",		H_FROM,
E 110
	"full-name",		H_ACHECK,
	"return-receipt-to",	H_FROM,
	"errors-to",		H_FROM,
E 79
E 74
		/* destination fields */
D 79
	"to",			H_RCPT,			0,
	"resent-to",		H_RCPT,			0,
	"cc",			H_RCPT,			0,
	"resent-cc",		H_RCPT,			0,
D 77
	"bcc",			H_RCPT,			0,
	"resent-bcc",		H_RCPT,			0,
E 77
I 77
	"bcc",			H_RCPT|H_ACHECK,	0,
	"resent-bcc",		H_RCPT|H_ACHECK,	0,
E 79
I 79
	"to",			H_RCPT,
D 87
	"resent-to",		H_RCPT,
E 87
I 87
	"resent-to",		H_RCPT|H_RESENT,
E 87
	"cc",			H_RCPT,
D 87
	"resent-cc",		H_RCPT,
E 87
I 87
	"resent-cc",		H_RCPT|H_RESENT,
E 87
	"bcc",			H_RCPT|H_ACHECK,
D 87
	"resent-bcc",		H_RCPT|H_ACHECK,
E 87
I 87
	"resent-bcc",		H_RCPT|H_ACHECK|H_RESENT,
E 87
E 79
E 77
		/* message identification and control */
I 87
	"message-id",		0,
	"resent-message-id",	H_RESENT,
E 87
E 73
D 79
	"message-id",		0,			0,
I 73
	"resent-message-id",	0,			0,
	"precedence",		0,			0,
E 73
E 67
	"message",		H_EOH,			0,
	"text",			H_EOH,			0,
E 79
I 79
	"message",		H_EOH,
	"text",			H_EOH,
I 87
		/* date fields */
	"date",			0,
	"resent-date",		H_RESENT,
E 87
E 79
D 73
	"posted-date",		0,			0,
	"return-receipt-to",	0,			0,
D 37
	"received-date",	H_CHECK,		M_FINAL,
	"received-from",	H_CHECK,		M_FINAL,
E 37
I 37
	"received-date",	H_CHECK,		M_LOCAL,
	"received-from",	H_CHECK,		M_LOCAL,
E 37
	"precedence",		0,			0,
I 58
D 70
	"mail-from",		H_FORCE,		0,
E 70
I 70
	"received",		H_FORCE,		0,
E 70
E 58
	"via",			H_FORCE,		0,
E 73
I 73
		/* trace fields */
D 79
	"received",		H_TRACE|H_FORCE,	0,
	"via",			H_TRACE|H_FORCE,	0,
	"mail-from",		H_TRACE|H_FORCE,	0,
E 79
I 79
	"received",		H_TRACE|H_FORCE,
	"via",			H_TRACE|H_FORCE,
	"mail-from",		H_TRACE|H_FORCE,
E 79

E 73
D 79
	NULL,			0,			0,
E 79
I 79
	NULL,			0,
E 79
E 33
E 21
};
I 34


/*
**  ARPANET error message numbers.
*/

D 55
# ifdef NEWFTP
/* these are almost all unchecked */
char	Arpa_Info[] =	"010";	/* arbitrary info: this is WRONG! */
char	Arpa_Enter[] =	"354";	/* start mail input */
char	Arpa_Mmsg[] =	"250";	/* mail successful (MAIL cmd) */
char	Arpa_Fmsg[] =	"250";	/* mail successful (MLFL cmd) */
char	Arpa_Syserr[] =	"450";	/* some (transient) system error */
char	Arpa_Usrerr[] =	"550";	/* some (fatal) user error */
# else NEWFTP
E 55
D 72
char	Arpa_Info[] =	"050";	/* arbitrary info */
D 55
char	Arpa_Enter[] =	"350";	/* start mail input */
char	Arpa_Mmsg[] =	"256";	/* mail successful (MAIL cmd) */
char	Arpa_Fmsg[] =	"250";	/* mail successful (MLFL cmd) */
char	Arpa_Syserr[] =	"455";	/* some (transient) system error */
char	Arpa_Usrerr[] =	"450";	/* some (fatal) user error */
# endif NEWFTP
E 55
I 55
char	Arpa_Syserr[] =	"451";	/* some (transient) system error */
char	Arpa_Usrerr[] =	"554";	/* some (fatal) user error */
E 72
I 72
char	Arpa_Info[] =		"050";	/* arbitrary info */
char	Arpa_TSyserr[] =	"451";	/* some (transient) system error */
char	Arpa_PSyserr[] =	"554";	/* some (permanent) system error */
char	Arpa_Usrerr[] =		"554";	/* some (fatal) user error */
E 72
E 55
I 42



D 80


E 80
/*
**  Location of system files/databases/etc.
*/

D 76
char	*AliasFile =	"/usr/lib/aliases";	/* alias file */
E 76
char	*ConfFile =	"/usr/lib/sendmail.cf";	/* runtime configuration */
D 52
char	*StatFile =	"/usr/eric/mailstats";	/* statistics summary */
E 52
I 52
D 56
char	*StatFile =	"/usr/lib/mailstats";	/* statistics summary */
E 56
I 56
D 76
char	*StatFile =	"/usr/lib/sendmail.st";	/* statistics summary */
E 56
char	*HelpFile =	"/usr/lib/sendmail.hf";	/* help file */
I 57
# ifdef QUEUE
E 57
I 54
char	*QueueDir =	"/usr/spool/mqueue";	/* queue of saved mail */
I 57
# else QUEUE
char	*QueueDir =	"/tmp";			/* location of temp files */
# endif QUEUE
E 76
E 57
D 80
char	*XcriptFile =	"/tmp/mailxXXXXXX";	/* template for transcript */
E 80
I 80
char	*FreezeFile =	"/usr/lib/sendmail.fc";	/* frozen version of above */


E 80
I 78

/*
D 103
**  Some other configuration....
E 103
I 103
**  Miscellaneous stuff.
E 103
*/

D 90
char	SpaceSub =	'.';
E 90
I 90
D 93
char	SpaceSub =	'.';	/* character to replace <lwsp> in addrs */
D 91
int	QueueLA =	12;	/* if load average > 12, just queue */
int	RefuseLA =	25;	/* if load average > 25, refuse connections */
E 91
I 91
int	QueueLA =	8;	/* load avg > QueueLA -> just queue */
int	RefuseLA =	12;	/* load avg > RefuseLA -> refuse connections */
E 93
I 93
D 103
char	SpaceSub;		/* character to replace <lwsp> in addrs */
int	QueueLA;		/* load avg > QueueLA -> just queue */
int	RefuseLA;		/* load avg > RefuseLA -> refuse connections */
E 103
I 103
int	DtableSize =	50;		/* max open files; reset in 4.2bsd */
/*
**  SETDEFAULTS -- set default values
**
**	Because of the way freezing is done, these must be initialized
**	using direct code.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Initializes a bunch of global variables to their
**		default values.
*/

setdefaults()
{
	QueueLA = 8;
	QueueFactor = 10000;
	RefuseLA = 12;
	SpaceSub = ' ';
I 105
	WkRecipFact = 1000;
	WkClassFact = 1800;
D 106
	WkTimeFact = -600;
E 106
I 106
D 112
	WkTimeFact = 600;
E 112
I 112
	WkTimeFact = 9000;
E 112
E 106
	FileMode = 0644;
	DefUid = 1;
	DefGid = 1;
E 105
}
E 103
E 93
E 91
E 90
E 78
E 54
E 52
I 44
D 76


I 47
/*
**  Other configuration.
*/

D 65
int	DefUid = 1;		/* the uid to execute mailers as */
int	DefGid = 1;		/* ditto for gid */
I 54
D 61
time_t	TimeOut = 3*24*60*60;	/* default timeout for queue files */
E 61
I 61
time_t	TimeOut = 3*24*60*60L;	/* default timeout for queue files */
E 65
I 65
int	DefUid =	1;		/* the uid to execute mailers as */
int	DefGid =	1;		/* ditto for gid */
time_t	TimeOut =	3*24*60*60L;	/* default timeout for queue files */
I 66
D 71
char	*TextTimeOut =	"three days";	/* text of above for error messages */
E 71
E 66
int	ReadTimeout =	10*60;		/* timeout on external reads */
I 67
D 68
int	LogLevel =	2;		/* default logging level */
E 68
I 68
int	LogLevel =	9;		/* default logging level */
I 75
bool	SuperSafe =	TRUE;		/* always create qf file */
E 75
E 68
E 67
E 65
E 61
E 54


E 47

/*
**  V6 system configuration.
*/

# ifdef V6
char	*StdTimezone =	"PST";		/* std time timezone */
char	*DstTimezone =	"PDT";		/* daylight time timezone */
# endif V6
E 76
E 44
E 42
E 34
D 23
/*
**  INITMACS -- initialize predefined macros.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Macros array gets initialized.
*/

char	*Macro[26];

# define MACRO(x)	Macro[x - 'A']

initmacs()
{
	MACRO('A') = ArpaHost;
	MACRO('B') = BerkHost;
	MACRO('U') = UucpHost;
D 19
}
E 17
E 9
/*
**  GETNAME -- Get the current users login name.
**
**	This is in config.c because it is somewhat machine dependent.
**	Examine it carefully for your installation.
**
**	Algorithm:
**		See if the person is logged in.  If so, return
**			the name s/he is logged in as.
**		Look up the user id in /etc/passwd.  If found,
**			return that name.
**		Return NULL.
**
**	Parameters:
**		none
**
**	Returns:
**		The login name of this user.
**		NULL if this person is noone.
**
**	Side Effects:
**		none
**
D 4
**	Requires:
**		getlogin (sys)
**		getpwuid (sys)
**		getuid (sys)
**
E 4
**	Called By:
**		main
D 4
**
**	History:
**		12/26/79 -- written.
E 4
*/

char *
getname()
{
	register char *p;
	register struct passwd *w;
	extern char *getlogin();
	extern struct passwd *getpwuid();
	static char namebuf[9];

	p = getlogin();
	if (p != NULL && p[0] != '\0')
		return (p);
# ifdef V6
	w = getpwuid(getuid() & 0377);
# else
	w = getpwuid(getuid());
# endif V6
	if (w != NULL)
	{
		strcpy(namebuf, w->pw_name);
		return (namebuf);
	}
	return (NULL);
E 19
}
E 23
D 114

# ifdef V6
/*
D 36
**  TTYPATH -- Get the path of the user's tty -- Version 6 version.
E 36
I 36
**  TTYNAME -- return name of terminal.
E 36
**
D 36
**	Returns the pathname of the user's tty.  Returns NULL if
**	the user is not logged in or if s/he has write permission
**	denied.
**
E 36
**	Parameters:
D 36
**		none
E 36
I 36
**		fd -- file descriptor to check.
E 36
**
**	Returns:
D 36
**		pathname of the user's tty.
**		NULL if not logged in or write permission denied.
E 36
I 36
**		pointer to full path of tty.
**		NULL if no tty.
E 36
**
**	Side Effects:
**		none.
D 36
**
**	WARNING:
**		Return value is in a local buffer.
**
D 4
**	Requires:
**		stat (sys)
**		ttyn (sys)
**		open (sys)
**		read (sys)
**		close (sys)
**		seek (sys)
**
E 4
**	Called By:
**		savemail
E 36
D 4
**
**	History:
**		1/12/80 -- written.
E 4
*/
E 114

D 33
# include <sys/types.h>
E 33
D 36
# include <sys/stat.h>

E 36
D 114
char *
D 36
ttypath()
E 36
I 36
ttyname(fd)
	int fd;
E 36
{
D 36
	struct stat stbuf;
	register int i;
E 36
I 36
	register char tn;
E 36
	static char pathn[] = "/dev/ttyx";
D 31
	extern int errno;
E 31

	/* compute the pathname of the controlling tty */
D 36
	if ((i = ttyn(2)) == 'x' && (i = ttyn(1)) == 'x' && (i = ttyn(0)) == 'x')
E 36
I 36
	if ((tn = ttyn(fd)) == NULL)
E 36
	{
		errno = 0;
		return (NULL);
	}
D 36
	pathn[8] = i;

	/* see if we have write permission */
D 18
	if (stat(pathn, &stbuf) < 0 || !flagset(02, stbuf.st_mode))
E 18
I 18
	if (stat(pathn, &stbuf) < 0 || !bitset(02, stbuf.st_mode))
E 18
	{
		errno = 0;
		return (NULL);
	}

	/* see if the user is logged in */
	if (getlogin() == NULL)
		return (NULL);

	/* looks good */
E 36
I 36
	pathn[8] = tn;
E 36
	return (pathn);
}
/*
**  FDOPEN -- Open a stdio file given an open file descriptor.
**
**	This is included here because it is standard in v7, but we
**	need it in v6.
**
**	Algorithm:
**		Open /dev/null to create a descriptor.
**		Close that descriptor.
**		Copy the existing fd into the descriptor.
**
**	Parameters:
**		fd -- the open file descriptor.
**		type -- "r", "w", or whatever.
**
**	Returns:
**		The file descriptor it creates.
**
**	Side Effects:
**		none
**
D 4
**	Requires:
**		fopen (sys)
**
E 4
**	Called By:
**		deliver
**
**	Notes:
**		The mode of fd must match "type".
*/

FILE *
fdopen(fd, type)
	int fd;
	char *type;
{
	register FILE *f;

	f = fopen("/dev/null", type);
D 31
	close(fileno(f));
E 31
I 31
	(void) close(fileno(f));
E 31
	fileno(f) = fd;
	return (f);
}
/*
**  INDEX -- Return pointer to character in string
**
**	For V7 compatibility.
**
**	Parameters:
**		s -- a string to scan.
**		c -- a character to look for.
**
**	Returns:
**		If c is in s, returns the address of the first
**			instance of c in s.
**		NULL if c is not in s.
**
**	Side Effects:
**		none.
D 4
**
**	Requires:
**		none.
**
**	History:
**		3/14/80 -- written.  Why isn't this in -lS?
E 4
*/

I 49
char *
E 49
index(s, c)
	register char *s;
	register char c;
{
	while (*s != '\0')
	{
		if (*s++ == c)
			return (--s);
	}
	return (NULL);
}
I 45
/*
**  UMASK -- fake the umask system call.
**
**	Since V6 always acts like the umask is zero, we will just
**	assume the same thing.
*/

/*ARGSUSED*/
umask(nmask)
{
	return (0);
}


E 114
/*
D 114
**  GETRUID -- get real user id.
*/

getruid()
{
	return (getuid() & 0377);
}


/*
**  GETRGID -- get real group id.
*/

getrgid()
{
	return (getgid() & 0377);
}


/*
**  GETEUID -- get effective user id.
*/

geteuid()
{
	return ((getuid() >> 8) & 0377);
}


/*
**  GETEGID -- get effective group id.
*/

getegid()
{
	return ((getgid() >> 8) & 0377);
}

# endif V6

# ifndef V6

/*
E 114
**  GETRUID -- get real user id (V7)
*/

getruid()
{
D 51
	return (getuid());
E 51
I 51
D 64
	if (Daemon)
E 64
I 64
D 81
	if (Mode == MD_DAEMON)
E 81
I 81
	if (OpMode == MD_DAEMON)
E 81
E 64
		return (RealUid);
	else
		return (getuid());
E 51
}


/*
**  GETRGID -- get real group id (V7).
*/

getrgid()
{
D 51
	return (getgid());
E 51
I 51
D 64
	if (Daemon)
E 64
I 64
D 81
	if (Mode == MD_DAEMON)
E 81
I 81
	if (OpMode == MD_DAEMON)
E 81
E 64
		return (RealGid);
	else
		return (getgid());
E 51
}

E 45
D 114
# endif V6
D 36

# ifndef V6
/*
**  TTYPATH -- Get the path of the user's tty -- Version 7 version.
E 36
I 36
/*
E 114
I 114
/*
E 114
I 82
**  USERNAME -- return the user id of the logged in user.
**
**	Parameters:
**		none.
**
**	Returns:
**		The login name of the logged in user.
**
**	Side Effects:
**		none.
**
**	Notes:
D 116
**		The return value is statically allocated.
E 116
I 116
**		The return value is permanently allocated and cached.
E 116
*/

char *
username()
{
I 94
	static char *myname = NULL;
E 94
	extern char *getlogin();
I 96
	register struct passwd *pw;
	extern struct passwd *getpwuid();
E 96

D 94
	return (getlogin());
E 94
I 94
	/* cache the result */
	if (myname == NULL)
	{
		myname = getlogin();
		if (myname == NULL || myname[0] == '\0')
		{
D 96
			register struct passwd *pw;
			extern struct passwd *getpwuid();
E 96

			pw = getpwuid(getruid());
			if (pw != NULL)
D 116
				myname = pw->pw_name;
E 116
I 116
				myname = newstr(pw->pw_name);
E 116
		}
I 95
D 96
		else {
			register struct passwd *pw;
			extern struct passwd *getpwuid();
E 96
I 96
		else
		{
E 96

			pw = getpwnam(myname);
D 96
			if(getuid() != pw->pw_uid) {
E 96
I 96
			if(getuid() != pw->pw_uid)
			{
E 96
				pw = getpwuid(getuid());
D 101
				myname = pw->pw_name;
E 101
I 101
				if (pw != NULL)
D 116
					myname = pw->pw_name;
E 116
I 116
					myname = newstr(pw->pw_name);
E 116
E 101
			}
		}
E 95
		if (myname == NULL || myname[0] == '\0')
		{
			syserr("Who are you?");
			myname = "postmaster";
		}
	}

	return (myname);
E 94
}
/*
E 82
**  TTYPATH -- Get the path of the user's tty
E 36
**
**	Returns the pathname of the user's tty.  Returns NULL if
**	the user is not logged in or if s/he has write permission
**	denied.
**
**	Parameters:
**		none
**
**	Returns:
**		pathname of the user's tty.
**		NULL if not logged in or write permission denied.
**
**	Side Effects:
**		none.
**
**	WARNING:
**		Return value is in a local buffer.
**
D 4
**	Requires:
**		stat (sys)
**		ttyn (sys)
**		open (sys)
**		read (sys)
**		close (sys)
**		seek (sys)
**
E 4
**	Called By:
**		savemail
D 4
**
**	History:
**		1/12/80 -- written.
E 4
*/

D 33
# include <sys/types.h>
E 33
# include <sys/stat.h>

char *
ttypath()
{
	struct stat stbuf;
	register char *pathn;
D 31
	extern int errno;
E 31
	extern char *ttyname();
I 31
	extern char *getlogin();
E 31

	/* compute the pathname of the controlling tty */
D 82
	if ((pathn = ttyname(2)) == NULL && (pathn = ttyname(1)) == NULL && (pathn = ttyname(0)) == NULL)
E 82
I 82
	if ((pathn = ttyname(2)) == NULL && (pathn = ttyname(1)) == NULL &&
	    (pathn = ttyname(0)) == NULL)
E 82
	{
		errno = 0;
		return (NULL);
	}

	/* see if we have write permission */
D 18
	if (stat(pathn, &stbuf) < 0 || !flagset(02, stbuf.st_mode))
E 18
I 18
	if (stat(pathn, &stbuf) < 0 || !bitset(02, stbuf.st_mode))
E 18
	{
		errno = 0;
		return (NULL);
	}

	/* see if the user is logged in */
	if (getlogin() == NULL)
		return (NULL);

	/* looks good */
	return (pathn);
}
D 36
# endif V6
E 36
I 18
/*
**  CHECKCOMPAT -- check for From and To person compatible.
**
**	This routine can be supplied on a per-installation basis
**	to determine whether a person is allowed to send a message.
**	This allows restriction of certain types of internet
**	forwarding or registration of users.
**
**	If the hosts are found to be incompatible, an error
**	message should be given using "usrerr" and FALSE should
**	be returned.
**
I 43
**	'NoReturn' can be set to suppress the return-to-sender
**	function; this should be done on huge messages.
**
E 43
**	Parameters:
**		to -- the person being sent to.
**
**	Returns:
**		TRUE -- ok to send.
**		FALSE -- not ok.
**
**	Side Effects:
**		none (unless you include the usrerr stuff)
*/

bool
checkcompat(to)
	register ADDRESS *to;
{
I 88
# ifdef lint
	if (to == NULL)
		to++;
# endif lint
E 88
I 54
D 85
# ifdef ING70
E 85
I 85
# ifdef EXAMPLE_CODE
	/* this code is intended as an example only */
E 85
E 54
I 49
	register STAB *s;
I 54
D 85
# endif ING70
E 85
E 54

E 49
I 31
D 43
# ifdef lint
	ADDRESS *x = to;

	to = x;
# endif lint

E 43
I 43
D 53
	if (to->q_mailer != MN_LOCAL && MsgSize > 100000)
E 53
I 53
D 63
	if (to->q_mailer != LocalMailer && MsgSize > 100000)
E 63
I 63
D 85
	if (to->q_mailer != LocalMailer && CurEnv->e_msgsize > 100000)
E 63
E 53
	{
		usrerr("Message exceeds 100000 bytes");
		NoReturn++;
		return (FALSE);
	}
I 49
# ifdef ING70
E 85
	s = stab("arpa", ST_MAILER, ST_FIND);
D 50
	if (s != NULL && From.q_mailer != MN_LOCAL && to->q_mailer == s->st_mailer->m_mno)
E 50
I 50
D 53
	if (s != NULL && From.q_mailer != MN_LOCAL && to->q_mailer == s->s_mailer->m_mno)
E 53
I 53
D 63
	if (s != NULL && From.q_mailer != LocalMailer && to->q_mailer == s->s_mailer)
E 63
I 63
D 82
	if (s != NULL && CurEnv->e_from.q_mailer != LocalMailer && to->q_mailer == s->s_mailer)
E 82
I 82
	if (s != NULL && CurEnv->e_from.q_mailer != LocalMailer &&
	    to->q_mailer == s->s_mailer)
E 82
E 63
E 53
E 50
	{
		usrerr("No ARPA mail through this machine: see your system administration");
I 85
		/* NoReturn = TRUE; to supress return copy */
E 85
		return (FALSE);
	}
D 85
# endif ING70
E 85
I 85
# endif EXAMPLE_CODE
E 85
E 49
E 43
E 31
	return (TRUE);
I 82
}
/*
**  HOLDSIGS -- arrange to hold all signals
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Arranges that signals are held.
*/

holdsigs()
{
}
/*
**  RLSESIGS -- arrange to release all signals
**
**	This undoes the effect of holdsigs.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Arranges that signals are released.
*/

rlsesigs()
{
E 82
}
I 90
/*
**  GETLA -- get the current load average
**
I 92
**	This code stolen from la.c.
**
E 92
**	Parameters:
**		none.
**
**	Returns:
**		The current load average as an integer.
**
**	Side Effects:
**		none.
*/

#ifdef VMUNIX

#include <nlist.h>

struct	nlist Nl[] =
{
	{ "_avenrun" },
#define	X_AVENRUN	0
	{ 0 },
};

getla()
{
	static int kmem = -1;
I 103
# ifdef sun
	long avenrun[3];
# else
E 103
	double avenrun[3];
I 103
# endif
I 109
	extern off_t lseek();
E 109
E 103

	if (kmem < 0)
	{
D 102
		kmem = open("/dev/kmem", 0);
E 102
I 102
		kmem = open("/dev/kmem", 0, 0);
E 102
		if (kmem < 0)
			return (-1);
I 92
D 100
		(void) ioctl(kmem, FIOCLEX, 0);
E 100
I 100
		(void) ioctl(kmem, (int) FIOCLEX, (char *) 0);
E 100
E 92
		nlist("/vmunix", Nl);
		if (Nl[0].n_type == 0)
			return (-1);
	}
D 97
	(void) lseek(kmem, (long) Nl[X_AVENRUN].n_value, 0);
	(void) read(kmem, avenrun, sizeof(avenrun));
E 97
I 97
D 100
	if (lseek(kmem, (long) Nl[X_AVENRUN].n_value, 0) < 0 ||
	    read(kmem, avenrun, sizeof(avenrun)) < sizeof(avenrun))
E 100
I 100
D 102
	if (lseek(kmem, (off_t) Nl[X_AVENRUN].n_value, 0) < 0 ||
E 102
I 102
	if (lseek(kmem, (off_t) Nl[X_AVENRUN].n_value, 0) == -1 ||
E 102
	    read(kmem, (char *) avenrun, sizeof(avenrun)) < sizeof(avenrun))
E 100
	{
		/* thank you Ian */
		return (-1);
	}
I 103
# ifdef sun
	return ((int) (avenrun[0] + FSCALE/2) >> FSHIFT);
# else
E 103
E 97
	return ((int) (avenrun[0] + 0.5));
I 103
# endif
E 103
}

#else VMUNIX

getla()
{
	return (0);
}

#endif VMUNIX
I 103
/*
**  SHOULDQUEUE -- should this message be queued or sent?
**
**	Compares the message cost to the load average to decide.
**
**	Parameters:
**		pri -- the priority of the message in question.
**
**	Returns:
**		TRUE -- if this message should be queued up for the
**			time being.
**		FALSE -- if the load is low enough to send this message.
**
**	Side Effects:
**		none.
*/

bool
shouldqueue(pri)
	long pri;
{
	int la;

	la = getla();
	if (la < QueueLA)
		return (FALSE);
	return (pri > (QueueFactor / (la - QueueLA + 1)));
}
/*
**  SETPROCTITLE -- set process title for ps
**
**	Parameters:
**		fmt -- a printf style format string.
**		a, b, c -- possible parameters to fmt.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Clobbers argv of our main procedure so ps(1) will
**		display the title.
*/

/*VARARGS1*/
setproctitle(fmt, a, b, c)
	char *fmt;
{
# ifdef SETPROCTITLE
	register char *p;
I 108
	register int i;
E 108
	extern char **Argv;
	extern char *LastArgv;
I 108
	char buf[MAXLINE];
E 108

D 108
	p = Argv[0];
E 108
I 108
	(void) sprintf(buf, fmt, a, b, c);
E 108

	/* make ps print "(sendmail)" */
I 108
	p = Argv[0];
E 108
	*p++ = '-';

D 108
	(void) sprintf(p, fmt, a, b, c);
	p += strlen(p);

	/* avoid confusing ps */
E 108
I 108
	i = strlen(buf);
	if (i > LastArgv - p - 2)
	{
		i = LastArgv - p - 2;
		buf[i] = '\0';
	}
	(void) strcpy(p, buf);
	p += i;
E 108
	while (p < LastArgv)
		*p++ = ' ';
# endif SETPROCTITLE
}
I 111
/*
**  REAPCHILD -- pick up the body of my child, lest it become a zombie
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Picks up extant zombies.
*/

# ifdef VMUNIX
# include <sys/wait.h>
# endif VMUNIX

reapchild()
{
# ifdef WNOHANG
	union wait status;

	while (wait3(&status, WNOHANG, (struct rusage *) NULL) > 0)
		continue;
# else WNOHANG
	auto int status;

	while (wait(&status) > 0)
		continue;
# endif WNOHANG
}
E 111
E 103
I 94
D 100
/*
**  DBMCLOSE -- close the DBM file
**
**	This depends on the implementation of the DBM library.  It
**	seems to work for all versions that I have come across.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Closes the current DBM file; dbminit must be
**		called again to continue using the DBM routines.
*/

dbmclose()
{
	extern int pagf, dirf;	/* defined in the DBM package */

	(void) close(pagf);
	(void) close(dirf);
}
E 100
E 94
E 90
I 83
D 86
/*
**  MYHOSTNAME -- return the name of this host.
**
**	Parameters:
D 84
**		none.
E 84
I 84
**		hostbuf -- a place to return the name of this host.
E 84
**
**	Returns:
D 84
**		The name of this host, as best as it can be determined.
E 84
I 84
**		A list of aliases for this host.
E 84
**
**	Side Effects:
**		none.
*/

D 84
char *
myhostname()
{
	static char hostbuf[40];
	register FILE *f;
E 84
I 84
#ifdef VMUNIX
#include <netdb.h>
#endif VMUNIX
E 84

D 84
	hostbuf[0] = '\0';
E 84
I 84
char **
myhostname(hostbuf)
	char hostbuf[];
{
E 84
#ifdef VMUNIX
I 84
	extern struct hostent *gethostbyname();
	struct hostent *hent;

E 84
	gethostname(hostbuf, sizeof hostbuf);
I 84
	hent = gethostbyname(hostbuf);
	if (hent != NULL)
		return (hent->h_aliases);
	else
		return (NULL);
E 84
# else VMUNIX
I 84
	register FILE *f;

	hostbuf[0] = '\0';
E 84
	f = fopen("/usr/include/whoami", "r");
	if (f != NULL)
	{
		(void) fgets(hostbuf, sizeof hostbuf, f);
		fixcrlf(hostbuf, TRUE);
		(void) fclose(f);
	}
I 84
	return (NULL);
E 84
#endif VMUNIX
D 84
	if (strncmp(hostbuf, "ucb", 3) == 0)
		return (&hostbuf[3]);
	else
		return (hostbuf);
E 84
}
E 86
E 83
E 18
E 1
