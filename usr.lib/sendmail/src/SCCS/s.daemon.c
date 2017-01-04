h11996
s 00042/00000/00614
d D 5.30 04/04/23 15:28:56 msokolov 100 99
c add R option to disable relaying service for Internet senders
e
s 00006/00005/00608
d D 5.29 02/05/29 21:57:58 msokolov 99 98
c preserve the numeric IP address of origin in the traces left by a message
c (it would now normally appear as a (comment) in CurHostName and $s)
e
s 00012/00002/00601
d D 5.28 02/01/08 09:10:49 msokolov 98 97
c add logging of incoming connections by origin
e
s 00011/00002/00592
d D 5.27 88/09/20 22:15:33 eric 97 96
c add I option to insist on Internet domain server; add NAMED_BIND
c compile option to compile in named routines.
e
s 00011/00009/00583
d D 5.26 88/06/30 14:58:36 bostic 96 95
c install approved copyright notice
e
s 00036/00056/00556
d D 5.25 88/04/01 15:43:17 bostic 95 94
c redo maphostname
e
s 00023/00020/00589
d D 5.24 88/03/24 09:04:27 bostic 94 93
c add Berkeley specific header
e
s 00002/00000/00607
d D 5.23 87/12/21 12:22:14 bostic 93 92
c fix #ifdef DAEMON, there was an extra #else
e
s 00001/00000/00606
d D 5.22 87/07/27 17:09:11 bostic 92 91
c checked in for eric; new message
e
s 00006/00001/00600
d D 5.21 86/07/21 10:31:48 bloom 91 90
c fix possible buffer overflow problem, use specific routine for 
c canonicalizing host names not gethostbyname
e
s 00015/00004/00586
d D 5.20 86/06/30 16:20:43 bloom 90 89
c try multiple addresses in SMTP connect
e
s 00005/00001/00585
d D 5.19 86/05/06 18:04:41 bloom 89 88
c Fix problem with not closing sockets upon errors when opening connections
e
s 00000/00004/00586
d D 5.18 86/04/02 16:00:22 eric 88 87
c don't run around clearing EF_FATALERRS -- this often applies to another
c address.  Drop uid/gid check in sameaddr -- it causes more problems
c than it fixes.
e
s 00003/00023/00587
d D 5.17 86/01/05 19:56:47 eric 87 86
m 
c cleanup for various compilation flags and reasonable organization
e
s 00006/00004/00604
d D 5.16 85/12/26 14:46:11 eric 86 85
m 
c cleanup (comments only)
e
s 00010/00010/00598
d D 5.15 85/12/17 23:53:12 eric 85 84
m 
c lint
e
s 00027/00002/00581
d D 5.14 85/12/09 10:26:26 miriam 84 83
m 
c Modify maphostname to do a gethostbyaddr if first character in name 
c is a bracket.
e
s 00016/00005/00567
d D 5.13 85/11/13 11:11:50 miriam 83 82
m 
c Take into account the possible error return values from gethostbyname().
e
s 00004/00003/00568
d D 5.12 85/09/24 15:49:01 eric 82 81
m 
c clean up queue output somewhat (push null jobs to end); set
c SO_REUSEADDR and SO_KEEPALIVE on daemon sockets in the hopes of making
c dead connections disappear faster
e
s 00002/00002/00569
d D 5.11 85/09/19 13:35:46 eric 81 80
m 
c lint
e
s 00002/00000/00569
d D 5.10 85/09/19 10:34:43 eric 80 79
m 
c don't catch extraneous children
e
s 00000/00001/00569
d D 5.9 85/09/19 01:25:26 eric 79 77
i 78
m 
c incorporate SMI changes -- still experimental
e
s 00001/00004/00551
d D 5.4.1.1 85/09/19 00:55:37 eric 78 73
m 
c SMI changes (somewhat)
e
s 00024/00018/00548
d D 5.8 85/09/17 21:42:42 eric 77 76
m 
c use SIGCHLD to catch processes as suggested by Serge Granik
e
s 00001/00001/00565
d D 5.7 85/09/17 19:24:15 eric 76 75
m 
c facilities in syslog
e
s 00008/00002/00558
d D 5.6 85/08/07 16:43:57 miriam 75 74
m 
c Update format of setsockopt to use 4.3 syntax.
e
s 00005/00000/00555
d D 5.5 85/07/26 11:00:53 miriam 74 73
m 
c Check errno after gethostbyname to see if name server unable to return 
c a get a valid answer because authoritative name server is down.
e
s 00028/00014/00527
d D 5.4 85/06/08 10:29:45 eric 73 72
m 
c lint for 4.3 release
e
s 00005/00005/00536
d D 5.3 85/06/08 00:28:54 eric 72 71
m 
c lint
e
s 00002/00005/00539
d D 5.2 85/06/07 22:03:26 miriam 71 70
m 
c Resolve duplicate SccsId
e
s 00014/00000/00530
d D 5.1 85/06/07 14:39:11 dist 70 69
m 
c Add copyright
e
s 00001/00001/00529
d D 4.12 85/05/24 10:59:46 eric 69 68
m 
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00061/00000/00469
d D 4.11 84/08/11 23:19:14 eric 68 67
m 
c Add $[ and $] as RHS operators to look up the contents and pass them
c to maphostname; maphostname currently looks them up in /etc/hosts and
c converts them to canonical form, but could be turned into a general
c name server.....   huzzah!!
e
s 00001/00001/00468
d D 4.10 84/08/11 17:18:49 eric 67 66
m 
c fix stupid syntax error
e
s 00010/00002/00459
d D 4.9 84/08/11 16:56:45 eric 66 65
m 
c don't add ".ARPA" (or whatever net name) to names that already have
c a dot in them; pull NetName out of initialized data space so that
c it can be changed in frozen configuration files
e
s 00012/00003/00449
d D 4.8 84/08/11 16:51:39 eric 65 64
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00003/00000/00449
d D 4.7 84/08/11 14:34:25 eric 64 63
m 
c handle hosts where gethostname does not return the canonical address
e
s 00001/00002/00448
d D 4.6 84/03/11 21:21:07 eric 63 62
m 
c fix argument to gethostname left over from some old interface....
e
s 00004/00002/00446
d D 4.5 84/03/11 16:13:46 eric 62 61
m 
c make network name configurable
e
s 00006/00002/00442
d D 4.4 83/08/28 14:44:55 eric 61 60
m 
c Refuse to talk to yourself (i.e., reject HELO packets with your own name).
c Add two thresholds -- option 'x' is the load average at which messages are
c queued rather than delivered (default 12); option 'X' is the load average
c at which incoming TCP connections are refused (default 25).
e
s 00002/00001/00442
d D 4.3 83/08/06 10:37:46 eric 60 59
m 
c Clear errno before trying connect in an attempt to track down EPERM
c problems.
e
s 00000/00004/00443
d D 4.2 83/07/27 22:56:32 eric 59 58
m 
c Don't uppercase hostname in myhostname so that it can be used as a
c UUCP name.
e
s 00000/00000/00447
d D 4.1 83/07/25 19:45:15 eric 58 57
m 
c 4.2 release version
e
s 00003/00006/00444
d D 3.55 83/07/13 10:38:04 eric 57 56
m 
c Delete "load limiting" for SMTP connections (a bad ethernet board can
c hang up all incoming mail); use sfgets in collect (same reason); check
c for I/O error in collect (from Bill Nowicki); switch date format to
c RFC822 style.
e
s 00001/00001/00449
d D 3.54 83/07/01 23:01:21 wnj 56 55
m 
c wait.h -> sys/wait.h
e
s 00009/00004/00441
d D 3.53 83/05/07 11:28:25 eric 55 54
m 237
c Pass the size of the buffer to myhostname.
e
s 00001/00000/00444
d D 3.52 83/03/12 18:05:40 eric 54 53
m 196
c take ECONNRESET (Connection reset by peer) as a temporary error during
c connection initiation.
e
s 00006/00000/00438
d D 3.51 83/02/26 15:05:52 eric 53 52
m 162
c map host name for $w macro to upper case -- this is more conventional
e
s 00002/00001/00436
d D 3.50 83/02/24 18:54:21 eric 52 51
m 162
c Fix bug in $w and $=w setup
e
s 00036/00020/00401
d D 3.49 83/02/18 12:43:05 eric 51 50
m 183
m 187
c Add HELO hostname verification; put in hack to print lots of info if we
c get an EPERM (Not owner) on a connect.
e
s 00050/00000/00371
d D 3.48 83/02/08 10:51:20 eric 50 49
m 167
m 172
m 173
m 174
c clean up problems when QUEUE compile flag not defined; clean up hostname
c code to run on non-4.1c systems; fix use of -oeq (quiet on errors) flag.
e
s 00001/00001/00370
d D 3.47 83/01/17 12:31:57 eric 49 48
m 155
c fix bug that caused "\r\n" string in TCP mailer definition to turn
c into something else -- causing all TCP connections to hang.
e
s 00011/00000/00360
d D 3.46 83/01/16 22:08:35 eric 48 47
m 
c put in socket debugging on a debug flag to help Sam find the CMU-CS-A
c problem -- this probably won't work with early 4.1c systems.
e
s 00002/00003/00358
d D 3.45 83/01/16 17:26:43 eric 47 46
m 153
c make the maximum number of simultaneous SMTP connections an option
e
s 00035/00010/00326
d D 3.44 83/01/08 19:54:08 eric 46 45
m 
c release daemon resources when running the queue
e
s 00001/00001/00335
d D 3.43 83/01/06 10:40:58 eric 45 44
m 
c lint
e
s 00001/00000/00335
d D 3.42 83/01/04 13:09:27 eric 44 43
m 
c take EHOSTDOWN as a temporary failure
e
s 00002/00001/00333
d D 3.41 83/01/03 13:44:25 eric 43 42
m 
c take ENETUNREACH (Network unreachable) as a transient error -- this
c probably isn't usually right, but it seem safer in the long run....
e
s 00001/00000/00333
d D 3.40 83/01/02 15:33:48 eric 42 41
m 124
c Take errno 65, "Host is unreachable", to be a recoverable error
e
s 00004/00003/00329
d D 3.39 82/12/29 17:39:48 eric 41 40
m 112
c don't htons(sp->s_port) in makeconnection
e
s 00004/00002/00328
d D 3.38 82/12/24 08:15:05 eric 40 39
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00001/00001/00329
d D 3.37 82/12/16 10:14:25 sam 39 38
m 
c port numbers now returned byte swapped
e
s 00105/00109/00225
d D 3.36 82/12/13 17:28:58 eric 38 37
x 36
m 085
c NEW-IPC: convert to 4.1c
e
s 00001/00001/00358
d D 3.35 82/12/05 13:47:09 eric 37 36
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00026/00001/00333
d D 3.34 82/11/21 15:35:38 eric 36 35
m 085
c First part of 4.1c conversion
e
s 00024/00001/00310
d D 3.33 82/11/20 12:43:46 eric 35 34
m 083
c Accept user@[net.host.logical.imp] syntax
e
s 00010/00004/00301
d D 3.32 82/10/22 09:02:59 eric 34 33
x 30
m 023
c part of a heuristic hill climbing algorithm to minimize the number of
c IPC bugs that come crawling over me.
e
s 00004/00001/00300
d D 3.31 82/10/13 21:55:16 eric 33 32
m 023
c Don't interrupt the process doing accepts (have a separate process
c running the queue) to avoid a large pile of 4.1[abc] bugs.  When
c something more stable comes out, I will change this.
e
s 00010/00001/00291
d D 3.30 82/10/07 08:50:14 eric 32 31
c try again to work around the kernel problems in IPC connects when
c interrupted.
e
s 00001/00003/00291
d D 3.29 82/10/07 01:40:12 eric 31 30
c bother.... it takes time to close a socket
e
s 00010/00008/00284
d D 3.28 82/09/30 22:29:55 eric 30 29
c workaround in daemon accept code for 4.1a kernel bug: if an accept
c gets an EINTR and then a valid accept before the interrupt returns,
c the connection will be lost forever (at least, as I understand it).
e
s 00008/00007/00284
d D 3.27 82/08/25 21:22:18 eric 29 28
c sigh....  more fun and games in the daemon code to try to guess right.
e
s 00002/00026/00289
d D 3.26 82/08/25 19:44:41 eric 28 27
c recreate a socket after every failed accept()
e
s 00005/00007/00310
d D 3.25 82/08/25 11:21:54 eric 27 26
c clean up time manipulation to always be current; assign job
c id's earlier to make sure there is always one with a message.
e
s 00025/00000/00292
d D 3.24 82/08/24 19:41:39 eric 26 25
c log more info (on log level 11); try to detect wild accept loops;
c some minor cleanup and debugging checks; fix NoConnect option to;
c only apply to expensive mailers (regardless of sendqueue order)
e
s 00006/00005/00286
d D 3.23 82/08/15 11:53:12 eric 25 24
c allow ETIMEDOUT or EINTR as in accept call
e
s 00009/00009/00282
d D 3.22 82/08/08 01:03:29 eric 24 23
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00002/00000/00289
d D 3.21 82/07/31 16:57:29 eric 23 22
c don't give error on ETIMEDOUT on accept() call.
e
s 00040/00016/00249
d D 3.20 82/07/27 23:01:30 eric 22 21
c clean up semantics of daemon mode to facilitate use of other IPC;
c if you can't create a socket assume there is another sendmail running
c and exit; move some code to main.c because it is not part of creating
c a connection.
e
s 00001/00000/00264
d D 3.19 82/07/05 20:55:10 eric 21 20
c improve debugging: flush transcript before doing things that might
c take a long time; add some info to debugging output
e
s 00002/00000/00262
d D 3.18 82/07/02 10:00:24 eric 20 19
c be paranoid about resetting the "FatalErrors" flag -- always reset
c after forking for daemon or queue mode.  This will prevent false error
c return delivery.
e
s 00001/00000/00261
d D 3.17 82/06/30 22:39:06 eric 19 18
c open a separate transcript in the child of a daemon.
e
s 00002/00003/00259
d D 3.16 82/06/26 13:10:55 eric 18 17
c lint
e
s 00001/00000/00261
d D 3.15 82/06/16 14:50:47 eric 17 16
c allow ECONNREFUSED (connection refused) as a temp error
e
s 00031/00003/00230
d D 3.14 82/06/07 23:52:01 eric 16 15
c allow multiple connections
e
s 00003/00003/00230
d D 3.13 82/05/31 18:50:56 eric 15 14
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00006/00000/00227
d D 3.12 82/05/22 01:26:44 eric 14 12
c add some other temporary failure conditions to ipc connection
e
s 00007/00000/00227
d R 3.12 82/05/22 00:06:28 eric 13 12
c extend the list of "temporary failure" returns from the list of
c IPC temporary failures.
e
s 00007/00001/00220
d D 3.11 82/05/06 20:21:23 eric 12 11
c allow socket number on [IPC] connections -- eventually this
c could be used to handle other low-level protocols.
e
s 00000/00001/00221
d D 3.10 82/03/22 22:38:01 eric 11 10
c continue the impossible task of tracking Bill Joy
e
s 00002/00003/00220
d D 3.9 82/03/06 14:52:15 eric 10 9
c arrange to be able to accept a connection from any host.
e
s 00074/00000/00149
d D 3.8 82/03/05 10:12:59 eric 9 8
c include direct connect on outgoing mail if the pathname is "[IPC]" --
c this gives minimal number of processes for ethernet mail.
e
s 00001/00001/00148
d D 3.7 82/02/26 22:03:20 eric 8 7
c switch to the correct port (IPPORT_SMTP).
e
s 00088/00005/00061
d D 3.6 82/02/26 21:56:32 eric 7 6
c implement daemon mode
e
s 00001/00001/00065
d D 3.5 81/12/06 12:40:50 eric 6 5
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00001/00001/00065
d D 3.4 81/11/08 17:27:09 eric 5 4
c LINT
e
s 00037/00019/00029
d D 3.3 81/10/27 11:49:13 eric 4 2
c sketch out eventual implementation of daemon.
e
s 00191/00008/00040
d D 3.2.1.1 81/10/27 08:37:20 eric 3 2
c try to cram in the MPX stuff -- is this really worth it?  NO!
e
s 00002/00002/00046
d D 3.2 81/10/26 14:23:34 eric 2 1
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00048/00000/00000
d D 3.1 81/10/17 16:56:40 eric 1 0
c date and time created 81/10/17 16:56:40 by eric
e
u
U
f b 
f i 
t
T
I 70
/*
I 96
 * Copyright (c) 1983 Eric P. Allman
E 96
D 94
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 94
I 94
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 96
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 96
I 96
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
E 96
 */
E 94

D 71
#ifndef lint
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 71
D 94

E 94
E 70
I 9
D 95
# include <errno.h>
E 9
I 1
# include "sendmail.h"
E 95
I 95
#include <errno.h>
#include <sendmail.h>
E 95
I 3
# include <sys/mx.h>
E 3

D 6
static char	SccsId[] =	"%W%	%G%";
E 6
I 6
D 7
SCCSID(%W%	%Y%	%G%);
E 7
I 7
D 73
#ifndef DAEMON
E 73
I 73
D 94
# ifndef DAEMON
# ifndef lint
E 73
D 71
SCCSID(%W%	%Y%	%G%	(w/o daemon mode));
E 71
I 71
static char	SccsId[] = "%W% (Berkeley) %G%	(w/o daemon mode)";
E 71
D 73
#else
E 73
I 73
# endif not lint
# else
E 94
I 94
#ifndef lint
#ifdef DAEMON
static char sccsid[] = "%W% (Berkeley) %G% (with daemon mode)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without daemon mode)";
#endif
#endif /* not lint */
E 94
E 73
E 7
E 6

I 94
#ifdef DAEMON

E 94
I 7
D 38
# include <sys/socket.h>
D 11
# include <wellknown.h>
E 11
# include <net/in.h>
I 16
# include <wait.h>
E 38
I 38
D 73
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
D 56
#include <wait.h>
E 56
I 56
#include <sys/wait.h>
E 73
I 73
D 78
# include <sys/socket.h>
# include <netinet/in.h>
E 78
# include <netdb.h>
I 77
# include <sys/signal.h>
E 77
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
I 100
# include <sys/ioctl.h>
# include <net/if.h>
E 100
E 73
E 56
E 38
E 16

I 73
D 94
# ifndef lint
E 73
D 71
SCCSID(%W%	%Y%	%G%	(with daemon mode));
E 71
I 71
static char	SccsId[] = "%W% (Berkeley) %G% (with daemon mode)";
I 73
# endif not lint
I 93
# endif
E 93
E 73
E 71

I 93
# ifdef DAEMON
E 94
E 93
E 7
/*
**  DAEMON.C -- routines to use when running as a daemon.
I 22
**
**	This entire file is highly dependent on the 4.2 BSD
**	interprocess communication primitives.  No attempt has
**	been made to make this file portable to Version 7,
**	Version 6, MPX files, etc.  If you should try such a
**	thing yourself, I recommend chucking the entire file
**	and starting from scratch.  Basic semantics are:
**
**	getrequests()
**		Opens a port and initiates a connection.
**		Returns in a child.  Must set InChannel and
**		OutChannel appropriately.
I 46
**	clrdaemon()
**		Close any open files associated with getting
**		the connection; this is used when running the queue,
**		etc., to avoid having extra file descriptors during
**		the queue run and to avoid confusing the network
**		code (if it cares).
E 46
**	makeconnection(host, port, outfile, infile)
**		Make a connection to the named host on the given
**		port.  Set *outfile and *infile to the files
**		appropriate for communication.  Returns zero on
**		success, else an exit status describing the
**		error.
D 87
**
**	The semantics of both of these should be clean.
E 87
I 87
**	maphostname(hbuf, hbufsize)
**		Convert the entry in hbuf into a canonical form.  It
**		may not be larger than hbufsize.
E 87
E 22
*/
I 3

static FILE	*MailPort;	/* port that mail comes in on */
E 3
D 2

static int	DaemonPipe;
E 2
/*
**  GETREQUESTS -- open mail IPC port and get requests.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Waits until some interesting activity occurs.  When
**		it does, a child is created to process it, and the
**		parent waits for completion.  Return from this
D 40
**		routine is always in the child.
E 40
I 40
**		routine is always in the child.  The file pointers
**		"InChannel" and "OutChannel" should be set to point
**		to the communication channel.
E 40
*/

I 16
D 47
# define MAXCONNS	4	/* maximum simultaneous sendmails */

E 47
I 38
D 46
struct sockaddr_in SendmailAddress;
E 46
I 46
struct sockaddr_in	SendmailAddress;/* internet address of sendmail */
D 62
int	DaemonSocket = -1;		/* fd describing socket */
E 62
I 47
D 57
int	MaxConnections = 4;		/* maximum simultaneous sendmails */
E 57
E 47
E 46

I 62
int	DaemonSocket	= -1;		/* fd describing socket */
D 66
char	*NetName	= "ARPA";	/* name of home (local?) network */
E 66
I 66
char	*NetName;			/* name of home (local?) network */
E 66

I 100
#define	ADDRLISTSZ	32
static	struct ifreq	myaddrlist[ADDRLISTSZ];
static	struct ifconf	ifconf;

E 100
E 62
E 38
E 16
getrequests()
{
I 38
D 46
	int s;
E 46
	int t;
E 38
I 16
D 77
	union wait status;
E 77
D 57
	int numconnections = 0;
E 57
I 38
D 40
	struct sockaddr otherend;
E 40
	register struct servent *sp;
I 82
	int on = 1;
E 82
I 77
	extern reapchild();
E 77
E 38

I 38
	/*
	**  Set up the address for the mailer.
	*/

	sp = getservbyname("smtp", "tcp");
	if (sp == NULL)
	{
		syserr("server \"smtp\" unknown");
D 45
		return (-1);
E 45
I 45
		goto severe;
E 45
	}
	SendmailAddress.sin_family = AF_INET;
	SendmailAddress.sin_addr.s_addr = INADDR_ANY;
D 39
	SendmailAddress.sin_port = htons(sp->s_port);
E 39
I 39
	SendmailAddress.sin_port = sp->s_port;
E 39

	/*
	**  Try to actually open the connection.
	*/

# ifdef DEBUG
	if (tTd(15, 1))
		printf("getrequests: port 0x%x\n", SendmailAddress.sin_port);
# endif DEBUG

	/* get a socket for the SMTP connection */
D 46
	s = socket(AF_INET, SOCK_STREAM, 0, 0);
	if (s < 0)
E 46
I 46
D 73
	DaemonSocket = socket(AF_INET, SOCK_STREAM, 0, 0);
E 73
I 73
	DaemonSocket = socket(AF_INET, SOCK_STREAM, 0);
E 73
	if (DaemonSocket < 0)
E 46
	{
		/* probably another daemon already */
		syserr("getrequests: can't create socket");
	  severe:
# ifdef LOG
		if (LogLevel > 0)
D 76
D 78
			syslog(LOG_SALERT, "cannot get connection");
E 78
I 78
			syslog(LOG_ALERT, "cannot get connection");
E 78
E 76
I 76
D 79
			syslog(LOG_ALERT, "cannot get connection");
E 79
E 76
# endif LOG
		finis();
	}
I 48

I 100
	/* get the list of this host's addresses */
	ifconf.ifc_len = sizeof(myaddrlist);
	ifconf.ifc_req = myaddrlist;
	(void) ioctl(DaemonSocket, SIOCGIFCONF, &ifconf);

E 100
#ifdef DEBUG
	/* turn on network debugging? */
	if (tTd(15, 15))
D 75
		(void) setsockopt(DaemonSocket, SOL_SOCKET, SO_DEBUG, 0, 0);
E 75
I 75
D 82
	{
		int on = 1;
E 82
		(void) setsockopt(DaemonSocket, SOL_SOCKET, SO_DEBUG, (char *)&on, sizeof on);
D 82
	}
E 82
E 75
#endif DEBUG
I 82

	(void) setsockopt(DaemonSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof on);
	(void) setsockopt(DaemonSocket, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof on);
E 82

E 48
D 46
	if (bind(s, &SendmailAddress, sizeof SendmailAddress, 0) < 0)
E 46
I 46
D 73
	if (bind(DaemonSocket, &SendmailAddress, sizeof SendmailAddress, 0) < 0)
E 73
I 73
	if (bind(DaemonSocket, &SendmailAddress, sizeof SendmailAddress) < 0)
E 73
E 46
	{
		syserr("getrequests: cannot bind");
D 46
		close(s);
E 46
I 46
		(void) close(DaemonSocket);
E 46
		goto severe;
	}
D 46
	listen(s, 10);
E 46
I 46
D 73
	listen(DaemonSocket, 10);
E 73
I 73
	if (listen(DaemonSocket, 10) < 0)
	{
		syserr("getrequests: cannot listen");
		(void) close(DaemonSocket);
		goto severe;
	}
E 73
E 46

I 77
D 81
	signal(SIGCHLD, reapchild);
E 81
I 81
	(void) signal(SIGCHLD, reapchild);
E 81

E 77
# ifdef DEBUG
	if (tTd(15, 1))
D 46
		printf("getrequests: %d\n", s);
E 46
I 46
		printf("getrequests: %d\n", DaemonSocket);
E 46
# endif DEBUG

E 38
E 16
D 3
D 7
	syserr("Daemon mode not yet implemented");
I 2
D 4
	getrecipients();
E 4
E 2
	exit(EX_USAGE);
E 3
I 3
	char *portname = "/dev/mailbox";

E 3
I 2
D 4
	/* initsys(); */
I 3

	/*
	**  Create "/dev/mailbox"
	*/

	if (Debug)
		portname = "mailbox";
	unlink(portname);
	MailPort = mpx(portname, 0222);
	if (MailPort < 0)
	{
		syserr("cannot create %s", portname);
		exit(EX_OSFILE);
	}
	chmod(portname, 0222);

	/*
	**  Wait for connection.
	*/

	for (;;)
	{
		i = read(MailPort, line, sizeof line);
		if (i < 0)
		{
			if (errno == EINTR)
				continue;
			syserr("mpx read");
			errct++;
			if (errct > 1000)
			{
				syserr("mpx read: too many errors");
				finis();
			}
			sleep(5);
			continue;
		}
		mpxcrack(line, i);
	}
E 3
E 2
}
/*
D 3
**  GETRECIPIENTS -- do a sendto to all recipients.
E 3
I 3
**  MPXCRACK -- parse & handle an input line.
E 3
**
**	Parameters:
I 3
**		rec -- the input record.
**		bc -- the byte count for rec.
**
**	Returns:
**		nothing
**
**	Side Effects:
**		rec is processed.
*/

# define skip(rec, n)	((struct rh *) (((char *) rec) + n))

mpxcrack(rec, bc)
	register struct rh *rec;
	int bc;
{
	struct rh *endrec;

	endrec = skip(rec, bc);

	while (rec < endrec)
	{
		if (rec->count == 0)
		{
			/* control record from mpx file */
			mpxcontrol(rec);
		}
		else
		{
			/* data record -- process message */
			syserr("data record!!");
		}
		rec->count += rec->ccount;
		if (rec->count & 01)
			rec->count++;
		rec = skip(rec, rec->count + sizeof *rec);
	}
}
/*
**  MPXCONTROL -- handle mpx control messages.
**
**	Parameters:
**		rec -- control message.
**
**	Returns:
E 3
**		none.
**
I 3
**	Side Effects:
**		as necessary for that control message.
*/

short NoIoctl[] = { M_IOANS };

mpxcontrol(rec)
	register struct rh *rec;
{
	register int cmd;
	register short val;
	register short *ap;
# ifdef MPXDEBUG
	char dbbuf[100];
# endif MPXDEBUG

# ifdef DEBUG
	if (Debug > 7)
		printf("%d byte control message\n", rec->ccount);
# endif DEBUG

	ap = (short *) (((char *) rec) + sizeof *rec);
	cmd = *ap++ & 0377;
	val = *ap++;
# ifdef MPXDEBUG
	logmsg(LOG_DEBUG, "mpxctl ch=%x cmd=%d val=%d", rec->index, cmd, val);
# endif MPXDEBUG

	switch (cmd)
	{
	  case M_WATCH:		/* attempted connect; value is uid */
# ifdef DEBUG
		if (Debug > 7)
			printf("WATCH, uid=%d\n", val);
# endif DEBUG
		attach(rec->index, MailPort);
		InChannel = extract(rec->index, MailPort);
		RealUid = val;
		detach(rec->index, MailPort);
		i = fork();
		if (i < 0)
		{
			syserr("daemon: cannot fork");
		}
		else if (i > 0)
		{
			/* parent -- wait for child */
			auto int st;

			(void) wait(&st);
		}
		else
		{
			/* child */
			smtp();
			syserr("smtp returns");
			exit(EX_SOFTWARE);
		}
		break;

	  case M_CLOSE:		/* close channel; value is unused */
# ifdef DEBUG
		if (Debug > 7)
			printf("CLOSE, val=%d\n", val);
# endif DEBUG
		detach(rec->index, MailPort);
		break;

	  case M_IOCTL:
# ifdef DEBUG
		if (Debug > 7)
			printf("IOCTL, val=%d\n", val);
# endif DEBUG
		wmpxctl(rec->index, NoIoctl, sizeof NoIoctl);
		break;

	  default:
		syserr("unknown mpx cmd %d, val=%d\n", cmd, val);
		break;
	}
}
/*
**  WMPXCTL -- write mpx control message
**
**	Parameters:
**		index -- index to write to.
**		buf -- place to write.
**		len -- length to write.
**
E 3
**	Returns:
**		none.
**
**	Side Effects:
D 3
**		The set of recipients for this request are
**		collected and designated as recipients.
E 3
I 3
**		writes to MailPort.
E 3
*/
E 4

E 7
D 3
D 4
getrecipients()
E 3
I 3
wmpxctl(index, buf, cnt)
	int index;
	char *buf;
	int cnt;
E 3
{
D 3
	return;
E 4
I 4
	for (;;)
	{
I 61
		register int pid;
E 61
I 51
		auto int lotherend;
		struct sockaddr_in otherend;
I 61
		extern int RefuseLA;
I 98
		extern char *inet_ntoa();
E 98
E 61

E 51
I 38
D 61
		/* wait for a connection */
E 38
		register int pid;
E 61
I 61
		/* see if we are rejecting connections */
		while (getla() > RefuseLA)
			sleep(5);
E 61
D 18
		auto int st;
E 18
I 7
D 38
		register int port;
E 38
E 7

I 61
		/* wait for a connection */
E 61
D 38
		/*
		**  Wait for a connection.
		*/
E 38
I 38
		do
		{
D 51
			auto int lotherend;
			struct sockaddr otherend;
E 38

E 51
D 7
		/* MailPort = getconnection(); */
E 7
I 7
D 38
		while ((port = getconnection()) < 0)
E 38
I 38
			errno = 0;
			lotherend = sizeof otherend;
D 46
			t = accept(s, &otherend, &lotherend, 0);
E 46
I 46
D 73
			t = accept(DaemonSocket, &otherend, &lotherend, 0);
E 73
I 73
			t = accept(DaemonSocket, &otherend, &lotherend);
E 73
E 46
		} while (t < 0 && errno == EINTR);
		if (t < 0)
E 38
		{
D 33
			syserr("getrequests: getconnection failed");
E 33
I 33
D 38
# ifdef LOG
			if (LogLevel > 0)
				syslog(LOG_SALERT, "cannot get connection");
# endif LOG
E 33
D 22
			sleep(30);
E 22
I 22
			finis();
E 38
I 38
			syserr("getrequests: accept");
			sleep(5);
			continue;
E 38
E 22
		}
E 7

I 7
		/*
I 98
		**  Log the connection.
		*/

# ifdef LOG
		if (LogLevel > 1)
			syslog(LOG_INFO, "connection from %s:%u",
				inet_ntoa(otherend.sin_addr),
				otherend.sin_port);
# endif LOG

		/*
E 98
		**  Create a subprocess to process the mail.
		*/

# ifdef DEBUG
D 24
		if (Debug > 1)
E 24
I 24
		if (tTd(15, 2))
E 24
D 38
			printf("getrequests: forking (port = %d)\n", port);
E 38
I 38
			printf("getrequests: forking (fd = %d)\n", t);
E 38
# endif DEBUG

E 7
		pid = fork();
		if (pid < 0)
		{
			syserr("daemon: cannot fork");
			sleep(10);
I 7
D 15
			close(port);
E 15
I 15
D 38
			(void) close(port);
E 38
I 38
			(void) close(t);
E 38
E 15
E 7
			continue;
		}

		if (pid == 0)
		{
I 51
			extern struct hostent *gethostbyaddr();
			register struct hostent *hp;
D 78
			extern char *RealHostName;	/* srvrsmtp.c */
E 78
			char buf[MAXNAME];

E 51
			/*
			**  CHILD -- return to caller.
I 51
			**	Collect verified idea of sending host.
E 51
			**	Verify calling user id if possible here.
I 20
D 22
			**	Make sure we reset state from parent.
E 22
E 20
			*/

I 80
D 81
			signal(SIGCHLD, SIG_DFL);
E 81
I 81
			(void) signal(SIGCHLD, SIG_DFL);
E 81

E 80
I 51
			/* determine host name */
I 99
			(void) sprintf(buf, "[%s]",
				inet_ntoa(otherend.sin_addr));
			RealHostAddr = newstr(buf);
E 99
D 85
			hp = gethostbyaddr(&otherend.sin_addr, sizeof otherend.sin_addr, AF_INET);
E 85
I 85
			hp = gethostbyaddr((char *) &otherend.sin_addr, sizeof otherend.sin_addr, AF_INET);
E 85
			if (hp != NULL)
D 62
				(void) sprintf(buf, "%s.ARPA", hp->h_name);
E 62
I 62
D 66
				(void) sprintf(buf, "%s.%s", hp->h_name, NetName);
E 66
I 66
			{
D 72
				strcpy(buf, hp->h_name);
E 72
I 72
				(void) strcpy(buf, hp->h_name);
E 72
				if (NetName != NULL && NetName[0] != '\0' &&
D 67
				    index(hp->h_name), '.') == NULL)
E 67
I 67
				    index(hp->h_name, '.') == NULL)
E 67
				{
D 72
					strcat(buf, ".");
					strcat(buf, NetName);
E 72
I 72
					(void) strcat(buf, ".");
					(void) strcat(buf, NetName);
E 72
				}
I 99
				RealHostName = newstr(buf);
E 99
			}
E 66
E 62
			else
D 65
				/* this should produce a dotted quad */
				(void) sprintf(buf, "%lx", otherend.sin_addr.s_addr);
E 65
I 65
			{
D 98
				extern char *inet_ntoa();

E 98
D 99
				/* produce a dotted quad */
				(void) sprintf(buf, "[%s]",
					inet_ntoa(otherend.sin_addr));
E 99
I 99
				/* use the dotted quad */
				RealHostName = RealHostAddr;
E 99
			}

			/* should we check for illegal connection here? XXX */
I 100
			/* We do set FromInet here. */
			FromInet = !ismyaddr(&otherend.sin_addr);
E 100
D 99

E 65
			RealHostName = newstr(buf);
E 99

E 51
I 20
D 22
			FatalErrors = FALSE;
E 22
E 20
I 7
D 38
			InChannel = fdopen(port, "r");
			OutChannel = fdopen(port, "w");
E 38
I 38
D 46
			close(s);
E 46
I 46
			(void) close(DaemonSocket);
E 46
			InChannel = fdopen(t, "r");
D 69
			OutChannel = fdopen(t, "w");
E 69
I 69
			OutChannel = fdopen(dup(t), "w");
E 69
E 38
I 19
D 22
			openxscrpt();
E 19
E 7
			initsys();
E 22
I 7
# ifdef DEBUG
D 24
			if (Debug > 1)
E 24
I 24
			if (tTd(15, 2))
E 24
				printf("getreq: returning\n");
# endif DEBUG
I 26
# ifdef LOG
			if (LogLevel > 11)
				syslog(LOG_DEBUG, "connected, pid=%d", getpid());
# endif LOG
E 26
E 7
			return;
		}

D 77
		/*
		**  PARENT -- wait for child to terminate.
		**	Perhaps we should allow concurrent processing?
		*/

I 7
# ifdef DEBUG
D 24
		if (Debug > 1)
E 24
I 24
		if (tTd(15, 2))
E 24
		{
			sleep(2);
			printf("getreq: parent waiting\n");
		}
# endif DEBUG

E 77
E 7
D 5
		wait(&st);
E 5
I 5
D 16
		(void) wait(&st);
E 16
I 16
		/* close the port so that others will hang (for a while) */
E 16
I 7
D 15
		close(port);
E 15
I 15
D 38
		(void) close(port);
E 38
I 38
		(void) close(t);
E 38
I 16
D 77

D 57
		/* pick up old zombies; implement load limiting */
		numconnections++;
D 47
		while (wait3(&status, numconnections < MAXCONNS ? WNOHANG : 0, 0) > 0)
E 47
I 47
		while (wait3(&status, numconnections < MaxConnections ? WNOHANG : 0, 0) > 0)
E 47
			numconnections--;
E 57
I 57
		/* pick up old zombies */
D 73
		while (wait3(&status, WNOHANG, 0) > 0)
E 73
I 73
		while (wait3(&status, WNOHANG, (struct rusage *) 0) > 0)
E 73
			continue;
E 77
E 57
E 16
E 15
E 7
E 5
	}
I 40
	/*NOTREACHED*/
I 100
}
/*
**  ISMYADDR -- assistant routine for getrequests to test if an IP address is
**		one of ours.
**
**	Parameters:
**		ipaddr -- IP address (struct in_addr) to check.
**
**	Returns:
**		A Boolean indication of whether ipaddr is one of ours.
**
**	Side Effects:
**		none.
*/

static
ismyaddr(ipaddr)
	register struct in_addr *ipaddr;
{
	register struct ifreq *ifr, *ifrend;

	for (ifr = myaddrlist,
	     ifrend = (struct ifreq *)((caddr_t)ifr + ifconf.ifc_len);
	     ifr < ifrend; ifr++)
		if (ifr->ifr_addr.sa_family == AF_INET &&
		    !bcmp(&((struct sockaddr_in *)&ifr->ifr_addr)->sin_addr,
			  ipaddr, sizeof(struct in_addr)))
			return (TRUE);
	return (FALSE);
E 100
I 77
}
/*
D 87
**  REAPCHILD -- pick up the body of my child, lest it become a zombie
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Picks up zombies.
*/

reapchild()
{
	union wait status;

	while (wait3(&status, WNOHANG, (struct rusage *) NULL) > 0)
		continue;
E 77
I 46
}
/*
E 87
**  CLRDAEMON -- reset the daemon connection
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		releases any resources used by the passive daemon.
*/

clrdaemon()
{
	if (DaemonSocket >= 0)
		(void) close(DaemonSocket);
	DaemonSocket = -1;
E 46
E 40
E 4
E 3
I 3
	struct wh wbuf;

	wbuf.index = index;
	wbuf.count = 0;
	wbuf.ccount = cnt;
	wbuf.data = buf;
	write(MailPort, &wbuf, sizeof wbuf);
E 3
}
I 7
/*
D 38
**  GETCONNECTION -- make a connection with the outside world
**
I 34
**	This routine is horribly contorted to try to get around a bunch
**	of 4.1a IPC bugs.  There appears to be nothing we can do to make
**	it "right" -- the code to interrupt accepts just doesn't work
**	right.  However, this is an attempt to minimize the probablity
**	of problems.
**
E 34
**	Parameters:
**		none.
**
**	Returns:
**		The port for mail traffic.
**
**	Side Effects:
**		Waits for a connection.
*/

I 16
#define IPPORT_PLAYPORT	3055		/* random number */

E 16
D 8
struct sockaddr_in SendmailAddress = { AF_INET, IPPORT_SENDMAIL };
E 8
I 8
struct sockaddr_in SendmailAddress = { AF_INET, IPPORT_SMTP };
E 8

getconnection()
{
D 36
	register int s;
E 36
I 36
	int s;
#ifdef NVMUNIX
	int t;
#endif NVMUNIX
E 36
D 10
	char *host = "localhost";
E 10
	struct sockaddr otherend;

	/*
	**  Set up the address for the mailer.
	*/

D 10
	SendmailAddress.sin_addr.s_addr = rhost(&host);
E 10
I 10
	SendmailAddress.sin_addr.s_addr = 0;
I 12
	SendmailAddress.sin_port = IPPORT_SMTP;
I 16
# ifdef DEBUG
D 24
	if (Debug > 0)
E 24
I 24
	if (tTd(15, 15))
E 24
		SendmailAddress.sin_port = IPPORT_PLAYPORT;
# endif DEBUG
	SendmailAddress.sin_port = htons(SendmailAddress.sin_port);
E 16
E 12
E 10

	/*
	**  Try to actually open the connection.
	*/

# ifdef DEBUG
D 24
	if (Debug)
E 24
I 24
	if (tTd(15, 1))
E 24
D 10
		printf("getconnection (%s)\n", host);
E 10
I 10
		printf("getconnection\n");
E 10
# endif DEBUG

D 22
	s = socket(SOCK_STREAM, 0, &SendmailAddress, SO_ACCEPTCONN);
I 16
	if (s < 0)
E 22
I 22
D 29
	for (;;)
E 29
I 29
D 30
D 34
	for (;; sleep(10))
E 34
I 34
	for (;; sleep(15))
E 34
E 30
I 30
	for (;;)
E 30
E 29
E 22
	{
I 32
		int i;

E 32
I 26
D 27
		int acptcnt;
E 27
I 27
D 28
		int acptcnt;			/* for debugging */
		time_t lasttick;		/* for debugging */
E 27

E 28
E 26
D 22
		sleep(10);
		return (s);
	}
E 22
I 22
		/* get a socket for the SMTP connection */
I 36
#ifdef NVMUNIX
		s = socket(AF_INET, SOCK_STREAM, 0, 0);
		bind(s, &SendmailAddress, sizeof SendmailAddress, 0);
		listen(s, 10);
#else NVMUNIX
E 36
D 32
		s = socket(SOCK_STREAM, 0, &SendmailAddress, SO_ACCEPTCONN);
E 32
I 32
		/* do loop is to avoid 4.1b kernel bug (?) */
D 34
		i = 50;
E 34
I 34
		i = 60;
E 34
		do
		{
			s = socket(SOCK_STREAM, 0, &SendmailAddress, SO_ACCEPTCONN);
			if (s < 0)
D 34
				sleep(5);
E 34
I 34
				sleep(10);
E 34
		} while (--i > 0 && s < 0);
I 36
#endif NVMUNIX
E 36
E 32
		if (s < 0)
		{
			/* probably another daemon already */
			syserr("getconnection: can't create socket");
D 29
			break;
E 29
I 29
			return (-1);
E 29
		}
E 22
E 16

# ifdef DEBUG
D 22
	if (Debug)
		printf("getconnection: %d\n", s);
E 22
I 22
D 24
		if (Debug)
E 24
I 24
		if (tTd(15, 1))
E 24
			printf("getconnection: %d\n", s);
E 22
# endif DEBUG
D 16
	accept(s, &otherend);
E 16
I 16
D 22
	if (accept(s, &otherend) < 0)
	{
		syserr("accept");
E 22
I 22

		/* wait for a connection */
I 26
D 27
		(void) time(&CurTime);
E 27
I 27
D 28
		lasttick = curtime();
E 27
		acptcnt = 0;
E 26
D 25
		if (accept(s, &otherend) >= 0)
E 25
I 25
		do
		{
I 26
D 27
			long now;

E 27
E 26
			errno = 0;
			(void) accept(s, &otherend);
I 26
D 27
			(void) time(&now);
			if (now == CurTime)
E 27
I 27
			if (lasttick == curtime())
E 27
			{
				if(++acptcnt > 2)
				{
					syserr("wild accept");
					/* abort(); */
					break;
				}
			}
			else
			{
D 27
				CurTime = now;
E 27
I 27
				lasttick = curtime();
E 27
				acptcnt = 0;
			}
E 26
		} while (errno == ETIMEDOUT || errno == EINTR);
		if (errno == 0)
E 28
I 28
D 29
		if (accept(s, &otherend) >= 0)
E 28
E 25
			break;
E 29
I 29
D 30
		do
		{
			errno = 0;
I 36
#ifdef NVMUNIX
			lotherend = sizeof otherend;
			t = accept(s, &otherend, &lotherend, 0);
			if (t >= 0)
				return (t);
#else NVMUNIX
E 36
			if (accept(s, &otherend) >= 0)
				return (s);
I 36
#endif NVMUNIX
E 36
		} while (errno == EINTR);
E 29
D 25

		/* probably innocuous -- retry */
I 23
		if (errno == ETIMEDOUT)
			continue;
E 25
E 23
		syserr("getconnection: accept");
E 30
I 30
		/* contorted code is due to a 4.1a kernel bug */
		errno = 0;
		if (accept(s, &otherend) >= 0)
			return (s);
E 30
E 22
D 18
		close(s);
E 18
I 18
D 34
		(void) close(s);
E 34
I 30
		if (errno != EINTR)
D 31
		{
E 31
			syserr("getconnection: accept");
D 31
			sleep(5);
		}
E 31
I 31
		sleep(5);
I 34
		(void) close(s);
E 34
E 31
E 30
E 18
D 22
		return (-1);
E 22
I 22
D 28
		sleep(20);
E 28
I 28
D 29
		sleep(10);
E 29
E 28
E 22
	}
E 16
D 29

	return (s);
E 29
I 9
}
/*
E 38
**  MAKECONNECTION -- make a connection to an SMTP socket on another machine.
**
**	Parameters:
**		host -- the name of the host.
I 12
**		port -- the port number to connect to.
E 12
**		outfile -- a pointer to a place to put the outfile
**			descriptor.
**		infile -- ditto for infile.
**
**	Returns:
**		An exit code telling whether the connection could be
**			made and if not why not.
**
**	Side Effects:
**		none.
*/

I 83
D 97
int	h_errno;	/*this will go away when code implemented*/

E 97
E 83
D 12
makeconnection(host, outfile, infile)
E 12
I 12
makeconnection(host, port, outfile, infile)
E 12
	char *host;
I 12
D 18
	int port;
E 18
I 18
	u_short port;
E 18
E 12
	FILE **outfile;
	FILE **infile;
{
D 90
	register int s;
E 90
I 90
	register int i, s;
	register struct hostent *hp = (struct hostent *)NULL;
	extern char *inet_ntoa();
E 90
I 89
	int sav_errno;
I 97
#ifdef NAMED_BIND
	extern int h_errno;
#endif
E 97
E 89

	/*
	**  Set up the address for the mailer.
I 35
	**	Accept "[a.b.c.d]" syntax for host name.
E 35
	*/

I 97
#ifdef NAMED_BIND
E 97
I 83
	h_errno = 0;
I 97
#endif
E 97
	errno = 0;

E 83
D 35
	if ((SendmailAddress.sin_addr.s_addr = rhost(&host)) == -1)
E 35
I 35
	if (host[0] == '[')
	{
D 51
		long hid = 0;
		int i, j;
		register char *p = host;
E 51
I 51
		long hid;
		register char *p = index(host, ']');
E 51

D 51
		for (i = 3; i >= 0 && *p != ']' && *p != '\0'; i--)
E 51
I 51
		if (p != NULL)
E 51
		{
D 51
			j = 0;
			while (isdigit(*++p))
				j = j * 10 + (*p - '0');
			if (*p != (i == 0 ? ']' : '.') || j > 255 || j < 0)
				break;
			hid |= j << ((3 - i) * 8);
E 51
I 51
			*p = '\0';
			hid = inet_addr(&host[1]);
			*p = ']';
E 51
		}
D 51
		if (i >= 0 || *p != ']' || *++p != '\0')
E 51
I 51
		if (p == NULL || hid == -1)
E 51
		{
			usrerr("Invalid numeric domain spec \"%s\"", host);
			return (EX_NOHOST);
		}
		SendmailAddress.sin_addr.s_addr = hid;
	}
D 38
	else if ((SendmailAddress.sin_addr.s_addr = rhost(&host)) == -1)
E 35
		return (EX_NOHOST);
E 38
I 38
	else
	{
D 90
		register struct hostent *hp = gethostbyname(host);

E 90
I 90
		hp = gethostbyname(host);
E 90
I 74
D 83
		if (errno == ETIMEDOUT)
		{
			CurEnv->e_flags &= ~EF_FATALERRS;
			return (EX_TEMPFAIL);
		}
E 83
E 74
D 51
		if (hp == 0)
E 51
I 51
		if (hp == NULL)
I 83
		{
I 97
#ifdef NAMED_BIND
E 97
			if (errno == ETIMEDOUT || h_errno == TRY_AGAIN)
D 88
			{
				CurEnv->e_flags &= ~EF_FATALERRS;
E 88
				return (EX_TEMPFAIL);
I 97

			/* if name server is specified, assume temp fail */
			if (errno == ECONNREFUSED && UseNameServer)
				return (EX_TEMPFAIL);
#endif
E 97
D 88
			}
E 88
D 86
#ifdef notdef
			if (h_errno == NO_ADDRESS)
				;		/*look for mail forwarder records*/
#endif notdef
E 86
I 86

			/*
			**  XXX Should look for mail forwarder record here
			**  XXX if (h_errno == NO_ADDRESS).
			*/

E 86
E 83
E 51
			return (EX_NOHOST);
I 83
		}
E 83
D 65
		bmove(hp->h_addr, (char *) &SendmailAddress.sin_addr, hp->h_length);
E 65
I 65
		bcopy(hp->h_addr, (char *) &SendmailAddress.sin_addr, hp->h_length);
I 90
		i = 1;
E 90
E 65
	}

	/*
	**  Determine the port number.
	*/

E 38
I 12
D 41
	if (port == 0)
E 41
I 41
	if (port != 0)
		SendmailAddress.sin_port = htons(port);
	else
E 41
D 38
		port = IPPORT_SMTP;
E 38
I 38
	{
		register struct servent *sp = getservbyname("smtp", "tcp");

		if (sp == NULL)
		{
			syserr("makeconnection: server \"smtp\" unknown");
			return (EX_OSFILE);
		}
D 41
		port = sp->s_port;
E 41
I 41
		SendmailAddress.sin_port = sp->s_port;
E 41
	}
E 38
D 16
	SendmailAddress.sin_port = port;
E 16
I 16
D 41
	SendmailAddress.sin_port = htons(port);
E 41
E 16
E 12

	/*
	**  Try to actually open the connection.
	*/

I 90
again:
E 90
# ifdef DEBUG
D 24
	if (Debug)
E 24
I 24
	if (tTd(16, 1))
E 24
D 90
		printf("makeconnection (%s)\n", host);
E 90
I 90
		printf("makeconnection (%s [%s])\n", host,
		    inet_ntoa(SendmailAddress.sin_addr.s_addr));
E 90
# endif DEBUG

I 36
#ifdef NVMUNIX
	s = socket(AF_INET, SOCK_STREAM, 0, 0);
#else NVMUNIX
E 36
D 15
	s = socket(SOCK_STREAM, 0, 0, 0);
E 15
I 15
D 38
	s = socket(SOCK_STREAM, 0, (struct sockaddr_in *) 0, 0);
E 38
I 38
D 73
	s = socket(AF_INET, SOCK_STREAM, 0, 0);
E 73
I 73
	s = socket(AF_INET, SOCK_STREAM, 0);
E 73
E 38
I 36
#endif NVMUNIX
E 36
E 15
	if (s < 0)
	{
		syserr("makeconnection: no socket");
I 89
		sav_errno = errno;
E 89
		goto failure;
	}

# ifdef DEBUG
D 24
	if (Debug)
E 24
I 24
	if (tTd(16, 1))
E 24
		printf("makeconnection: %d\n", s);
I 48

	/* turn on network debugging? */
	if (tTd(16, 14))
D 75
		(void) setsockopt(s, SOL_SOCKET, SO_DEBUG, 0, 0);
E 75
I 75
	{
		int on = 1;
		(void) setsockopt(DaemonSocket, SOL_SOCKET, SO_DEBUG, (char *)&on, sizeof on);
	}
E 75
E 48
# endif DEBUG
I 21
D 24
	fflush(Xscript);				/* for debugging */
E 24
I 24
D 37
	(void) fflush(Xscript);				/* for debugging */
E 37
I 37
	(void) fflush(CurEnv->e_xfp);			/* for debugging */
I 60
	errno = 0;					/* for debugging */
E 60
E 37
I 36
#ifdef NVMUNIX
	bind(s, &SendmailAddress, sizeof SendmailAddress, 0);
	if (connect(s, &SendmailAddress, sizeof SendmailAddress, 0) < 0)
#else NVMUNIX
E 36
E 24
E 21
D 38
	if (connect(s, &SendmailAddress) < 0)
E 38
I 38
	SendmailAddress.sin_family = AF_INET;
D 49
	bind(s, &SendmailAddress, sizeof SendmailAddress, 0);
E 49
I 49
D 51
	/* bind(s, &SendmailAddress, sizeof SendmailAddress, 0); */
E 51
E 49
D 73
	if (connect(s, &SendmailAddress, sizeof SendmailAddress, 0) < 0)
E 73
I 73
	if (connect(s, &SendmailAddress, sizeof SendmailAddress) < 0)
E 73
E 38
I 36
#endif NVMUNIX
E 36
	{
I 89
		sav_errno = errno;
		(void) close(s);
I 90
		if (hp && hp->h_addr_list[i])
		{
			bcopy(hp->h_addr_list[i++],
			    (char *)&SendmailAddress.sin_addr, hp->h_length);
			goto again;
		}

E 90
E 89
		/* failure, decide if temporary or not */
	failure:
D 89
		switch (errno)
E 89
I 89
		switch (sav_errno)
E 89
		{
		  case EISCONN:
		  case ETIMEDOUT:
I 14
		  case EINPROGRESS:
		  case EALREADY:
		  case EADDRINUSE:
I 44
		  case EHOSTDOWN:
E 44
		  case ENETDOWN:
		  case ENETRESET:
		  case ENOBUFS:
I 17
		  case ECONNREFUSED:
I 54
		  case ECONNRESET:
E 54
I 42
		  case EHOSTUNREACH:
I 43
		  case ENETUNREACH:
E 43
E 42
E 17
E 14
			/* there are others, I'm sure..... */
I 65
D 88
			CurEnv->e_flags &= ~EF_FATALERRS;
E 88
E 65
			return (EX_TEMPFAIL);

I 51
		  case EPERM:
			/* why is this happening? */
			syserr("makeconnection: funny failure, addr=%lx, port=%x",
				SendmailAddress.sin_addr.s_addr, SendmailAddress.sin_port);
D 60
			/* explicit fall-through */
E 60
I 60
			return (EX_TEMPFAIL);
E 60

E 51
		  default:
I 92
			message(Arpa_Info, "%s", errstring(sav_errno));
E 92
			return (EX_UNAVAILABLE);
		}
	}

	/* connection ok, put it into canonical form */
	*outfile = fdopen(s, "w");
	*infile = fdopen(s, "r");

D 43
	return (0);
E 43
I 43
	return (EX_OK);
E 43
E 9
}
I 50
/*
**  MYHOSTNAME -- return the name of this host.
**
**	Parameters:
**		hostbuf -- a place to return the name of this host.
I 55
**		size -- the size of hostbuf.
E 55
**
**	Returns:
**		A list of aliases for this host.
**
**	Side Effects:
**		none.
*/

char **
D 55
myhostname(hostbuf)
E 55
I 55
myhostname(hostbuf, size)
E 55
	char hostbuf[];
I 55
	int size;
E 55
{
	extern struct hostent *gethostbyname();
D 51
	struct hostent *hent;
E 51
I 51
	struct hostent *hp;
I 52
D 55
	auto int i = 30;
E 55
I 55
D 63
	auto int i = size;
E 63
E 55
I 53
D 59
	register char *p;
E 59
E 53
E 52
E 51

D 52
	gethostname(hostbuf, sizeof hostbuf);
E 52
I 52
D 63
	gethostname(hostbuf, &i);
E 63
I 63
D 73
	gethostname(hostbuf, size);
E 73
I 73
	if (gethostname(hostbuf, size) < 0)
	{
		(void) strcpy(hostbuf, "localhost");
	}
E 73
E 63
E 52
D 51
	hent = gethostbyname(hostbuf);
	if (hent != NULL)
		return (hent->h_aliases);
E 51
I 51
	hp = gethostbyname(hostbuf);
I 53
D 59
	for (p = hostbuf; *p != '\0'; p++)
		if (islower(*p))
			*p -= 'a' - 'A';
E 59
E 53
	if (hp != NULL)
I 64
	{
D 72
		strcpy(hostbuf, hp->h_name);
E 72
I 72
		(void) strcpy(hostbuf, hp->h_name);
E 72
E 64
		return (hp->h_aliases);
I 64
	}
E 64
E 51
	else
		return (NULL);
}
I 68
D 95
/*
**  MAPHOSTNAME -- turn a hostname into canonical form
**
**	Parameters:
**		hbuf -- a buffer containing a hostname.
**		hbsize -- the size of hbuf.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Looks up the host specified in hbuf.  If it is not
**		the canonical name for that host, replace it with
**		the canonical name.  If the name is unknown, or it
**		is already the canonical name, leave it unchanged.
*/
E 95
E 68

I 95
/*
 *  MAPHOSTNAME -- turn a hostname into canonical form
 *
 *	Parameters:
 *		hbuf -- a buffer containing a hostname.
 *		hbsize -- the size of hbuf.
 *
 *	Returns:
 *		none.
 *
 *	Side Effects:
 *		Looks up the host specified in hbuf.  If it is not
 *		the canonical name for that host, replace it with
 *		the canonical name.  If the name is unknown, or it
 *		is already the canonical name, leave it unchanged.
 */
E 95
I 68
maphostname(hbuf, hbsize)
	char *hbuf;
	int hbsize;
{
	register struct hostent *hp;
D 95
	extern struct hostent *gethostbyname();
E 95
I 95
	u_long in_addr;
	char ptr[256];
	struct hostent *gethostbyaddr();
E 95

D 84
	makelower(hbuf);
	hp = gethostbyname(hbuf);
E 84
I 84
	/*
D 85
	 * If first character is a bracket, then it is an address
	 * lookup.  Address is copied into a temporary buffer to
	 * strip the brackets and to preserve hbuf if address is
	 * unknown.
	 */
E 85
I 85
D 95
	**  If first character is a bracket, then it is an address
	**  lookup.  Address is copied into a temporary buffer to
	**  strip the brackets and to preserve hbuf if address is
	**  unknown.
	*/
E 85

	if (*hbuf == '[')
	{
		extern struct hostent *gethostbyaddr();
		u_long in_addr;
		char ptr[256];
		char *bptr;

D 85
		strcpy(ptr,hbuf);
E 85
I 85
		(void) strcpy(ptr, hbuf);
E 85
		bptr = index(ptr,']');
		*bptr = '\0';
		in_addr = inet_addr(&ptr[1]);
D 85
		hp = gethostbyaddr(&in_addr, sizeof(struct in_addr), AF_INET);
		if(hp == NULL)
			return(NULL);
E 85
I 85
		hp = gethostbyaddr((char *) &in_addr, sizeof(struct in_addr), AF_INET);
		if (hp == NULL)
			return;
E 85
	}
	else
	{
		makelower(hbuf);
I 91
#ifdef MXDOMAIN
E 95
I 95
	 * If first character is a bracket, then it is an address
	 * lookup.  Address is copied into a temporary buffer to
	 * strip the brackets and to preserve hbuf if address is
	 * unknown.
	 */
	if (*hbuf != '[') {
E 95
		getcanonname(hbuf, hbsize);
		return;
D 95
#else MXDOMAIN
E 91
		hp = gethostbyname(hbuf);
I 91
#endif
E 95
E 91
	}
E 84
D 95
	if (hp != NULL)
	{
		int i = strlen(hp->h_name);

		if (i >= hbsize)
D 91
			hp->h_name[--i] = '\0';
E 91
I 91
			hp->h_name[hbsize - 1] = '\0';
E 91
D 72
		strcpy(hbuf, hp->h_name);
E 72
I 72
		(void) strcpy(hbuf, hp->h_name);
E 72
	}
E 95
I 95
	*index(strcpy(ptr, hbuf), ']') = '\0';
	in_addr = inet_addr(&ptr[1]);
	hp = gethostbyaddr((char *)&in_addr, sizeof(struct in_addr), AF_INET);
	if (hp == NULL)
		return;
	if (strlen(hp->h_name) >= hbsize)
		hp->h_name[hbsize - 1] = '\0';
	(void)strcpy(hbuf, hp->h_name);
E 95
}
D 95

E 95
I 95

E 95
E 68
# else DAEMON
I 68
/* code for systems without sophisticated networking */
E 68

/*
**  MYHOSTNAME -- stub version for case of no daemon code.
I 53
**
**	Can't convert to upper case here because might be a UUCP name.
I 55
**
**	Mark, you can change this to be anything you want......
E 55
E 53
*/

char **
D 55
myhostname(hostbuf)
E 55
I 55
myhostname(hostbuf, size)
E 55
	char hostbuf[];
I 55
	int size;
E 55
{
	register FILE *f;

	hostbuf[0] = '\0';
	f = fopen("/usr/include/whoami", "r");
	if (f != NULL)
	{
D 55
		(void) fgets(hostbuf, sizeof hostbuf, f);
E 55
I 55
		(void) fgets(hostbuf, size, f);
E 55
		fixcrlf(hostbuf, TRUE);
		(void) fclose(f);
	}
	return (NULL);
}
I 68
/*
**  MAPHOSTNAME -- turn a hostname into canonical form
**
**	Parameters:
**		hbuf -- a buffer containing a hostname.
**		hbsize -- the size of hbuf.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Looks up the host specified in hbuf.  If it is not
**		the canonical name for that host, replace it with
**		the canonical name.  If the name is unknown, or it
**		is already the canonical name, leave it unchanged.
*/

/*ARGSUSED*/
maphostname(hbuf, hbsize)
	char *hbuf;
	int hbsize;
{
	return;
}
D 87

E 87
E 68
E 50

#endif DAEMON
E 7
E 1
