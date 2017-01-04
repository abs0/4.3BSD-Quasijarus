h60186
s 00011/00009/01033
d D 5.24 88/06/30 14:59:23 bostic 107 106
c install approved copyright notice
e
s 00024/00018/01018
d D 5.23 88/03/13 19:52:42 bostic 106 105
c add Berkeley specific header
e
s 00003/00001/01033
d D 5.22 86/10/14 18:05:54 eric 105 104
c don't let "locked job" messages remove transcript & lock
e
s 00006/00000/01028
d D 5.21 86/04/17 20:17:24 eric 104 103
c don't ignore aliasing during queue runs in conjunction with -bd
e
s 00006/00001/01022
d D 5.20 86/03/08 14:11:35 eric 103 102
c improve debugging in queue routines; don't output error addresses that
c are duplicates or otherwise marked as "don't send"
e
s 00031/00015/00992
d D 5.19 86/01/05 18:48:12 eric 102 101
m 
c rewrite reply-to and resent-reply-to; save errorqueueu in qf file;
c some performance hacking; some alias handling cleanup; delete leading
c spaces from SMTP lines
e
s 00001/00001/01006
d D 5.18 85/12/17 21:35:02 eric 101 100
m 
c patch to clearenvelope to avoid dereferencing garbage pointers
e
s 00010/00000/00997
d D 5.17 85/10/13 15:03:15 eric 100 99
m 
c fix botch with reapchild getting queue runs before intended wait
e
s 00001/00001/00996
d D 5.16 85/09/25 11:02:12 eric 99 98
m 
c DO use Ruleset 4 when defining $f -- it's very necessary (fix for <>
c will have to be done in configuration); pretty up mailq -v slightly
e
s 00008/00004/00989
d D 5.15 85/09/24 15:48:56 eric 98 97
m 
c clean up queue output somewhat (push null jobs to end); set
c SO_REUSEADDR and SO_KEEPALIVE on daemon sockets in the hopes of making
c dead connections disappear faster
e
s 00008/00002/00985
d D 5.14 85/09/21 16:23:49 eric 97 96
m 
c don't include ctime as part of priority, since the value affects the results of
c shouldqueue; we go back to adding ctime into the workcmpf in queue.c
e
s 00001/00001/00986
d D 5.13 85/09/21 15:51:55 eric 96 95
m 
c change sign on WkTimeFact so that is closer to what most people want
e
s 00011/00022/00976
d D 5.12 85/09/21 14:44:16 eric 95 94
m 
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00015/00004/00983
d D 5.11 85/09/21 10:31:19 eric 94 93
m 
c add -v mode to mailq to print priorities as well (this should be extended
c in the future); fix some problems in the savemail state machine.
e
s 00003/00006/00984
d D 5.10 85/09/19 22:00:56 eric 93 92
m 
c use rename instead of link/unlink
e
s 00001/00001/00989
d D 5.9 85/09/19 20:48:17 eric 92 91
m 
c pretty up "Skipping ..." message
e
s 00001/00002/00989
d D 5.8 85/09/19 15:57:43 eric 91 90
m 
c updates to make it possible to run the queue in one process; this
c permits a database of host status to be built
e
s 00005/00002/00986
d D 5.7 85/09/19 13:35:29 eric 90 89
m 
c lint
e
s 00023/00000/00965
d D 5.6 85/09/19 12:18:20 eric 89 88
m 
c performance hacks
e
s 00090/00025/00875
d D 5.5 85/09/19 00:45:03 eric 88 87
m 
c SMI changes (somewhat)
e
s 00005/00001/00895
d D 5.4 85/06/08 10:26:47 eric 87 86
m 
c lint for 4.3 release
e
s 00009/00009/00887
d D 5.3 85/06/08 00:02:07 eric 86 85
m 
c lint
e
s 00002/00006/00894
d D 5.2 85/06/07 22:34:08 miriam 85 84
m 
c Resolve duplicate Sccsid.  Remove unused variable.
e
s 00014/00000/00886
d D 5.1 85/06/07 15:08:01 dist 84 83
m 
c Add copyright
e
s 00002/00002/00884
d D 4.5 85/02/15 09:26:30 eric 83 82
m 
c fix some bugs with -C flag; one with queuing from Teus
e
s 00021/00084/00865
d D 4.4 84/12/06 10:34:17 eric 82 81
m 
c back out attempt to use flock in the queue -- we don't in gerneral have
c an open file descriptor available.
e
s 00255/00042/00694
d D 4.3 84/12/05 23:13:28 eric 81 80
m 
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00001/00001/00735
d D 4.2 84/03/11 16:52:15 eric 80 79
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00000/00000/00736
d D 4.1 83/07/25 19:43:35 eric 79 78
m 
c 4.2 release version
e
s 00001/00001/00735
d D 3.76 83/07/02 18:33:43 sam 78 77
m 
c include fix
e
s 00001/00001/00735
d D 3.75 83/06/11 20:59:15 eric 77 76
m 
c %d => %ld in mailq for PDP-11's
e
s 00004/00008/00732
d D 3.74 83/05/18 11:55:43 eric 76 75
m 
c Minor formatting change so that the entire text of the message can
c be printed.
e
s 00011/00000/00729
d D 3.73 83/04/23 12:54:19 eric 75 74
m 230
c Don't put Resent-*: lines in queue file to prevent outputing them
c inappropriately in the sent message.
e
s 00000/00001/00729
d D 3.72 83/03/12 15:39:45 eric 74 73
m 207
c Don't artifically add a "from: $q" when running the queue -- this seems
c to cause the from line in the qf file to be ignored.
e
s 00013/00003/00717
d D 3.71 83/02/02 12:53:39 eric 73 72
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00001/00000/00719
d D 3.70 83/01/17 09:31:58 eric 72 71
m 154
c define a newline in "nullmailer" so that queue files get written with
c newlines between the "H" lines.
e
s 00008/00000/00711
d D 3.69 83/01/08 19:53:24 eric 71 70
m 
c release daemon resources when running the queue
e
s 00001/00000/00710
d D 3.68 83/01/08 13:48:30 eric 70 69
m 
c be sure to open a new transcript on every queue run; when returning
c an SMTP transcript, only send the last half (i.e., that part which
c describes the sending half).
e
s 00008/00002/00702
d D 3.67 83/01/06 10:47:20 eric 69 68
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00009/00010/00695
d D 3.66 83/01/04 10:58:42 eric 68 67
m 
c fix botch that causes sendmail to core dump when there are large
c numbers of requests
e
s 00021/00006/00684
d D 3.65 83/01/03 18:01:43 eric 67 66
m 
c give more useful error messages (including the errno that caused
c a temporary failure); reflect these messages out to mailq
e
s 00001/00001/00689
d D 3.64 83/01/03 13:19:20 eric 66 65
m 
c print "request" instead of "requests" if there is only one request
e
s 00000/00044/00690
d D 3.63 83/01/03 13:01:47 eric 65 64
m 
c process timeouts like normal errors, so that they will get delivered to
c the correct address (i.e., the Errors-To: address)
e
s 00008/00001/00726
d D 3.62 83/01/03 11:28:18 eric 64 63
m 
c fix botch in reading the queue that caused it to throw away the last
c entry it read -- this was particulary obvious with only one entry in
c the queue.
e
s 00039/00019/00688
d D 3.61 83/01/02 14:27:16 eric 63 62
m 
c clean up output of mailq mode
e
s 00002/00002/00705
d D 3.60 83/01/01 21:25:53 eric 62 61
m 123
c Put CRLF on all lines in user SMTP.  Pass this info down to
c innumerable routines.
e
s 00091/00008/00616
d D 3.59 82/12/14 16:57:44 eric 61 60
m 105
c Add "print mail queue" mode (-bp flag or call as "mailq")
e
s 00001/00001/00623
d D 3.58 82/12/13 18:25:43 eric 60 59
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00003/00006/00621
d D 3.57 82/12/05 13:46:39 eric 59 58
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00002/00000/00625
d D 3.56 82/11/28 16:00:58 eric 58 57
m 
c implement SMTP auto-shutdown on 421 codes; clean up some error processing
c items, particularly in SMTP; don't reinstantiate error message bodies after
c queueing; other minor changes.  This is all cleanup from 3.253.
e
s 00008/00010/00617
d D 3.55 82/11/28 10:22:31 eric 57 56
m 
c fix a number of problems left over from yesterday's delta.  The big
c triumph is being able to delete the parameter from disconnect().
e
s 00071/00055/00556
d D 3.54 82/11/28 00:22:39 eric 56 55
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00007/00009/00604
d D 3.53 82/11/24 18:44:38 eric 55 54
m 
c lint it
e
s 00015/00024/00598
d D 3.52 82/11/24 17:15:38 eric 54 53
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00001/00001/00621
d D 3.51 82/11/17 09:37:01 eric 53 52
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00000/00000/00622
d D 3.50 82/11/13 17:55:36 eric 52 51
x 51 49
m 068
c drop old dir hack
e
s 00007/00001/00630
d D 3.49 82/11/04 15:17:35 eric 51 50
m 056
c fix bug in back compat dir code
e
s 00002/00002/00629
d D 3.48 82/11/03 10:29:31 eric 50 49
m 058
c Put temporary file mode on the F option
e
s 00009/00000/00622
d D 3.47 82/11/03 09:00:42 eric 49 48
m 056
c Arrange for queue.c to aapt to systems w/o new directory code
e
s 00001/00001/00621
d D 3.46 82/10/07 00:08:11 eric 48 47
c <ndir.h> => <dir.h> for maximum portability
e
s 00000/00005/00622
d D 3.45 82/09/26 14:46:07 eric 47 46
c completely instantiate queue files for all mail, even if not needed;
c fix a bug that would probably come up once every ten years in creating
c the queue id.  should merge argv flag processing with option processing.
e
s 00007/00002/00620
d D 3.44 82/09/22 10:51:08 eric 46 45
c don't put commas in non-address fields; have -bq clean up its temp files
e
s 00002/00003/00620
d D 3.43 82/09/21 10:10:45 eric 45 44
c output headers with commas into the queue
e
s 00008/00018/00615
d D 3.42 82/09/11 17:18:24 eric 44 43
c don't assign $s to be the sending host (this mucks up Received:
c lines) -- instead just use HELO messages; chdir into queue directory
c and make all pathnames relative; be more conservative in creating
c queue id's -- in the event you get file table overflows, etc.
e
s 00001/00001/00632
d D 3.41 82/09/06 16:24:57 eric 43 42
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00027/00093/00606
d D 3.40 82/08/27 16:04:58 eric 42 41
c simplify timeout code; allow multiple simultaneous queue runs so that
c large messages don't freeze things up; fix EINTR problem in sfgets;
c clean up canonname to be really correct; lots of misc. cleanup
e
s 00002/00002/00697
d D 3.39 82/08/25 11:21:39 eric 41 40
c clean up time manipulation to always be current; assign job
c id's earlier to make sure there is always one with a message.
e
s 00011/00008/00688
d D 3.38 82/08/25 10:46:38 eric 40 39
c log locked files in queuer; don't mistakenly start up two runqueue's
e
s 00002/00002/00694
d D 3.37 82/08/24 19:56:05 eric 39 38
c put queueup log messages on a higher logging level
e
s 00009/00000/00687
d D 3.36 82/08/24 19:41:45 eric 38 37
c log more info (on log level 11); try to detect wild accept loops;
c some minor cleanup and debugging checks; fix NoConnect option to;
c only apply to expensive mailers (regardless of sendqueue order)
e
s 00010/00009/00677
d D 3.35 82/08/23 11:59:57 eric 37 36
c clean up queueing; log time in queue.
c **** This delta invalidates mqueue files ****
e
s 00037/00049/00649
d D 3.34 82/08/22 19:03:33 eric 36 35
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00002/00017/00696
d D 3.33 82/08/17 20:43:18 eric 35 34
c handle folded lines in queue file properly
e
s 00002/00001/00711
d D 3.32 82/08/17 16:15:49 eric 34 33
c don't process core files; process headers properly when running queue.
e
s 00021/00003/00691
d D 3.31 82/08/15 17:34:08 eric 33 32
c make headers work properly when a message is queued up; this involves
c expanding the header before it is written into the queue.  However, it
c also means that we don't have to store the macro definitions (?)
e
s 00017/00002/00677
d D 3.30 82/08/15 11:51:45 eric 32 31
c know about continuation lines in queue files: necessary for headers
e
s 00029/00031/00650
d D 3.29 82/08/08 21:16:07 eric 31 30
c make "sleep" work correctly even in the face of other events; clean
c up the queue processing: child queue runs now go away when done.  more
c debugging logging is needed to verify that this works right though.
e
s 00002/00003/00679
d D 3.28 82/08/08 17:01:50 eric 30 29
c don't give an error when the link fails -- another daemon could have
c grabbed it
e
s 00013/00007/00669
d D 3.27 82/08/08 01:03:57 eric 29 28
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00002/00001/00674
d D 3.26 82/07/27 23:05:04 eric 28 27
c don't attempt delivery if you get an error reading the queue file.
e
s 00032/00027/00643
d D 3.25 82/07/20 19:39:04 eric 27 26
c be smarter about when to rerun the queue when you are in repeated
c queue mode.
e
s 00003/00000/00667
d D 3.24 82/07/14 09:23:31 eric 26 25
c don't accidently unlink a null pointer in finis(); change the way
c it decides whether to do the unlink.
e
s 00005/00002/00662
d D 3.23 82/07/05 20:52:40 eric 25 24
c improve configuration on timeout
e
s 00003/00001/00661
d D 3.22 82/07/05 12:03:12 eric 24 23
c put timeouts on net reads
e
s 00006/00002/00656
d D 3.21 82/07/02 20:52:51 eric 23 22
c arrange to not lose temporary queue control files (tf files)
c if you interrupt a queue run process.
e
s 00001/00000/00657
d D 3.20 82/07/02 10:00:35 eric 22 21
c be paranoid about resetting the "FatalErrors" flag -- always reset
c after forking for daemon or queue mode.  This will prevent false error
c return delivery.
e
s 00004/00004/00653
d D 3.19 82/06/07 07:55:12 eric 21 20
c make transcripts verbose always; misc. message cleanup, etc.
e
s 00001/00001/00656
d D 3.18 82/06/06 23:05:51 eric 20 19
c implement alias owner feature.  this actually works for any user.
c basically, if the alias owner-xxx exists, errors sending to xxx will be
c sent to that alias rather than to the sender.
e
s 00002/00000/00655
d D 3.17 82/05/31 19:03:53 eric 19 18
c make temp files the correct modes in all cases
e
s 00013/00013/00642
d D 3.16 82/05/31 18:51:02 eric 18 17
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00005/00002/00650
d D 3.15 82/05/31 17:11:30 eric 17 16
c eliminate -V, -D, -p flags in favor of a single flag "-bx"
c (be in mode x).
e
s 00005/00003/00647
d D 3.14 82/05/31 15:33:06 eric 16 14
i 15
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00092/00028/00558
d D 3.13.1.1 82/05/29 18:21:25 eric 15 14
c try to install envelopes.  is this really worth it???
e
s 00012/00010/00574
d D 3.13 82/05/22 01:39:09 eric 14 13
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00008/00009/00576
d D 3.12 82/05/05 20:28:12 glickman 13 12
c Modified to use new directory access routines.
e
s 00001/00000/00584
d D 3.11 82/03/06 16:12:25 eric 12 11
c get queue scanning working correctly in conjunction with daemon mode
e
s 00003/00000/00581
d D 3.10 82/02/26 21:56:37 eric 11 10
c implement daemon mode
e
s 00016/00010/00565
d D 3.9 82/02/20 12:05:09 eric 10 9
c don't expand macros in queued requests until delivery time -- means
c passing the macro definitions through also.
e
s 00003/00005/00572
d D 3.8 81/12/06 12:40:54 eric 9 8
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00006/00000/00571
d D 3.7 81/12/05 11:54:23 eric 8 7
c put the SMTP and queueing code on compilation flags so that sendmail
c will fit on non-ID PDP-11's (ugh); put the ugly UUCP hack on a
c compilation flag also to emphasize that it sucks eggs; makefile
c cleanup.
e
s 00032/00047/00539
d D 3.6 81/11/22 19:18:15 eric 7 6
c Edit queue control files when running queue (assuming there are still
c recipients left).  Also, modify the MsgPriority to be the absolute
c number (not the Priority: value); this allows us to include aging into
c the priority algorithm.
e
s 00006/00010/00580
d D 3.5 81/11/21 18:44:24 eric 6 4
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00002/00001/00589
d D 3.4.1.1 81/11/21 15:50:58 eric 5 4
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00006/00006/00584
d D 3.4 81/11/08 17:27:14 eric 4 3
c LINT
e
s 00052/00009/00538
d D 3.3 81/10/27 12:25:14 eric 3 2
c experimental version combining queueing with daemon operation.
c I'm sure this doesn't work -- if only because the wait()s are funny.
e
s 00091/00023/00456
d D 3.2 81/10/27 10:51:23 eric 2 1
c More queueing cleanup: implement timeouts (still one-stage),
c properly implement priorities (didn't work before), and miscellaneous
c cleanup.
e
s 00479/00000/00000
d D 3.1 81/10/27 08:38:53 eric 1 0
c date and time created 81/10/27 08:38:53 by eric
e
u
U
f b 
f i 
t
T
I 84
/*
I 107
 * Copyright (c) 1983 Eric P. Allman
E 107
D 106
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 106
I 106
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 107
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 107
I 107
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
E 107
 */
E 106

D 85
#ifndef lint
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 85
D 106

E 106
E 84
I 1
# include "sendmail.h"
I 106

#ifndef lint
#ifdef QUEUE
static char sccsid[] = "%W% (Berkeley) %G% (with queueing)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without queueing)";
#endif
#endif /* not lint */

E 106
# include <sys/stat.h>
D 13
# include <sys/dir.h>
E 13
I 13
D 48
# include <ndir.h>
E 48
I 48
D 78
# include <dir.h>
E 78
I 78
# include <sys/dir.h>
E 78
E 48
E 13
I 2
# include <signal.h>
E 2
# include <errno.h>
I 81
D 82
# ifdef FLOCK
# include <sys/file.h>
# endif FLOCK
E 82
E 81

I 8
D 106
# ifndef QUEUE
I 87
# ifndef lint
E 87
D 9
static char	SccsId[] =	"%W%	%G%	(no queueing)";
E 9
I 9
D 85
SCCSID(%W%	%Y%	%G%	(no queueing));
E 85
I 85
static char	SccsId[] = "%W% (Berkeley) %G%	(no queueing)";
I 87
# endif not lint
E 87
E 85
E 9
# else QUEUE

I 87
# ifndef lint
E 87
E 8
D 9
static char	SccsId[] =	"%W%	%G%";
E 9
I 9
D 85
SCCSID(%W%	%Y%	%G%);
E 85
I 85
static char	SccsId[] = "%W% (Berkeley) %G%";
I 87
# endif not lint
E 106
I 106
# ifdef QUEUE
E 106
E 87
E 85
E 9

/*
I 56
**  Work queue.
*/

struct work
{
	char		*w_name;	/* name of control file */
	long		w_pri;		/* priority of message, see below */
I 97
	time_t		w_ctime;	/* creation time of message */
E 97
I 88
D 95
	long		w_ctime;	/* creation time of message */
E 95
E 88
	struct work	*w_next;	/* next in queue */
};

typedef struct work	WORK;

WORK	*WorkQ;			/* queue of things to be done */
/*
E 56
**  QUEUEUP -- queue a message up for future transmission.
**
D 56
**	The queued message should already be in the correct place.
**	This routine just outputs the control file as appropriate.
**
E 56
**	Parameters:
D 15
**		df -- location of the data file.  The name will
**			be transformed into a control file name.
E 15
I 15
**		e -- the envelope to queue up.
I 17
**		queueall -- if TRUE, queue all addresses, rather than
**			just those with the QQUEUEUP flag set.
I 56
**		announce -- if TRUE, tell when you are queueing up.
E 56
E 17
E 15
**
**	Returns:
**		none.
**
**	Side Effects:
D 56
**		The current request (only unsatisfied addresses)
**			are saved in a control file.
E 56
I 56
**		The current request are saved in a control file.
E 56
*/

D 15
queueup(df)
	char *df;
E 15
I 15
D 17
queueup(e)
E 17
I 17
D 56
queueup(e, queueall)
E 56
I 56
queueup(e, queueall, announce)
E 56
E 17
	register ENVELOPE *e;
I 17
	bool queueall;
I 56
	bool announce;
E 56
E 17
E 15
{
D 36
	char cf[MAXNAME];
E 36
I 36
	char *tf;
	char *qf;
E 36
D 15
	register FILE *f;
E 15
I 15
D 33
	char buf[MAXNAME];
E 33
I 33
	char buf[MAXLINE];
E 33
D 36
	register FILE *cfp;
E 36
I 36
	register FILE *tfp;
E 36
E 15
D 9
	register int i;
E 9
	register HDR *h;
D 9
	register char *p;
E 9
I 6
	register ADDRESS *q;
I 69
	MAILER nullmailer;
E 69
I 9
D 36
	extern char *mktemp();
E 36
I 10
D 55
	register int i;
E 55
E 10
E 9
E 6

D 7
	/* create control file name from data file name */
	strcpy(cf, df);
	p = rindex(cf, '/');
	if (p == NULL || *++p != 'd')
	{
		syserr("queueup: bad df name %s", df);
		return;
	}
	*p = 'c';
E 7
I 7
	/*
D 81
	**  Create control file.
E 81
I 81
D 82
	**  Create control file if necessary.
E 82
I 82
	**  Create control file.
E 82
E 81
	*/
E 7

D 7
	/* create control file */
E 7
I 7
D 18
	strcpy(cf, QueueDir);
D 15
	strcat(cf, "/cfXXXXXX");
E 15
I 15
	strcat(cf, "/tfXXXXXX");
E 18
I 18
D 36
	(void) strcpy(cf, QueueDir);
	(void) strcat(cf, "/tfXXXXXX");
E 18
E 15
	(void) mktemp(cf);
E 7
D 15
	f = fopen(cf, "w");
	if (f == NULL)
E 15
I 15
	cfp = fopen(cf, "w");
	if (cfp == NULL)
E 36
I 36
D 81
	tf = newstr(queuename(e, 't'));
	tfp = fopen(tf, "w");
E 81
I 81
D 82
	tfp = e->e_qfp;
E 82
I 82
	tf = newstr(queuename(e, 't'));
	tfp = fopen(tf, "w");
E 82
E 81
	if (tfp == NULL)
E 36
E 15
	{
D 36
		syserr("queueup: cannot create control file %s", cf);
E 36
I 36
D 81
		syserr("queueup: cannot create temp file %s", tf);
E 36
		return;
E 81
I 81
D 82
		tf = newstr(queuename(e, 't'));
		tfp = fopen(tf, "w");
		if (tfp == NULL)
		{
			syserr("queueup: cannot create temp file %s", tf);
			return;
		}
		(void) chmod(tf, FileMode);
E 82
I 82
		syserr("queueup: cannot create temp file %s", tf);
		return;
E 82
E 81
	}
I 19
D 36
	(void) chmod(cf, 0600);
E 36
I 36
D 50
	(void) chmod(tf, 0600);
E 50
I 50
D 81
	(void) chmod(tf, FileMode);
E 81
I 81
D 82
	else
		tf = NULL;
E 82
I 82
	(void) chmod(tf, FileMode);
E 82
E 81
E 50
E 36
E 19

# ifdef DEBUG
D 29
	if (Debug)
E 29
I 29
	if (tTd(40, 1))
E 29
D 15
		printf("queued in %s\n", cf);
E 15
I 15
D 36
		printf("queueing in %s\n", cf);
E 36
I 36
D 81
		printf("queueing in %s\n", tf);
E 81
I 81
		printf("queueing %s\n", e->e_id);
E 81
E 36
E 15
# endif DEBUG

	/*
I 15
	**  If there is no data file yet, create one.
	*/

	if (e->e_df == NULL)
	{
		register FILE *dfp;
I 58
		extern putbody();
E 58

D 18
		strcpy(buf, QueueDir);
		strcat(buf, "/dfXXXXXX");
E 18
I 18
D 36
		(void) strcpy(buf, QueueDir);
		(void) strcat(buf, "/dfXXXXXX");
E 18
		e->e_df = newstr(mktemp(buf));
E 36
I 36
		e->e_df = newstr(queuename(e, 'd'));
E 36
		dfp = fopen(e->e_df, "w");
		if (dfp == NULL)
		{
			syserr("queueup: cannot create %s", e->e_df);
D 18
			fclose(cfp);
E 18
I 18
D 36
			(void) fclose(cfp);
E 36
I 36
			(void) fclose(tfp);
E 36
E 18
			return;
		}
I 19
D 50
		(void) chmod(e->e_df, 0600);
E 50
I 50
		(void) chmod(e->e_df, FileMode);
E 50
E 19
D 56
		(*e->e_putbody)(dfp, Mailer[1], FALSE);
E 56
I 56
D 59
		(*e->e_putbody)(dfp, ProgMailer, FALSE);
E 59
I 59
D 62
		(*e->e_putbody)(dfp, ProgMailer, FALSE, e);
E 62
I 62
D 69
		(*e->e_putbody)(dfp, ProgMailer, FALSE, e, FALSE);
E 69
I 69
		(*e->e_putbody)(dfp, ProgMailer, e);
E 69
E 62
E 59
E 56
D 18
		fclose(dfp);
E 18
I 18
		(void) fclose(dfp);
I 58
		e->e_putbody = putbody;
E 58
E 18
	}

	/*
E 15
	**  Output future work requests.
I 56
D 102
	**	Priority should be first, since it is read by orderq.
E 102
I 102
	**	Priority and creation time should be first, since
	**	they are required by orderq.
E 102
E 56
	*/

I 56
	/* output message priority */
	fprintf(tfp, "P%ld\n", e->e_msgpriority);

I 61
	/* output creation time */
	fprintf(tfp, "T%ld\n", e->e_ctime);

E 61
E 56
	/* output name of data file */
D 15
	fprintf(f, "D%s\n", df);
E 15
I 15
D 36
	fprintf(cfp, "D%s\n", e->e_df);
E 36
I 36
	fprintf(tfp, "D%s\n", e->e_df);
E 36
E 15

I 67
	/* message from envelope, if it exists */
	if (e->e_message != NULL)
		fprintf(tfp, "M%s\n", e->e_message);

E 67
	/* output name of sender */
D 14
	fprintf(f, "S%s\n", From.q_paddr);
E 14
I 14
D 15
	fprintf(f, "S%s\n", CurEnv->e_from.q_paddr);
E 15
I 15
D 36
	fprintf(cfp, "S%s\n", e->e_from.q_paddr);
E 36
I 36
	fprintf(tfp, "S%s\n", e->e_from.q_paddr);
E 36
E 15
E 14

D 37
	/* output timeout */
D 15
	fprintf(f, "T%ld\n", TimeOut);
E 15
I 15
D 36
	fprintf(cfp, "T%ld\n", TimeOut);
E 36
I 36
	fprintf(tfp, "T%ld\n", TimeOut);
E 37
I 37
D 61
	/* output creation time */
	fprintf(tfp, "T%ld\n", e->e_ctime);
E 37
E 36
E 15

E 61
I 2
D 56
	/* output message priority */
D 7
	fprintf(f, "P%d\n", MsgPriority);
E 7
I 7
D 14
	fprintf(f, "P%ld\n", MsgPriority);
E 14
I 14
D 15
	fprintf(f, "P%ld\n", CurEnv->e_msgpriority);
E 15
I 15
D 36
	fprintf(cfp, "P%ld\n", e->e_msgpriority);
E 36
I 36
	fprintf(tfp, "P%ld\n", e->e_msgpriority);
E 36
E 15
E 14
E 7

E 56
I 15
D 57
	/* output message class */
D 36
	fprintf(cfp, "C%d\n", e->e_class);
E 36
I 36
	fprintf(tfp, "C%d\n", e->e_class);
E 36

E 57
E 15
I 10
D 54
	/* output macro definitions */
I 33
	/* I don't think this is needed any more.....
E 33
	for (i = 0; i < 128; i++)
	{
D 15
		extern char *Macro[128];
		register char *p = Macro[i];
E 15
I 15
		register char *p = e->e_macro[i];
E 15

		if (p != NULL && i != (int) 'b')
D 15
			fprintf(f, "M%c%s\n", i, p);
E 15
I 15
D 36
			fprintf(cfp, "M%c%s\n", i, p);
E 36
I 36
			fprintf(tfp, "M%c%s\n", i, p);
E 36
E 15
	}
I 33
	.....  */
E 33

E 54
E 10
E 2
	/* output list of recipient addresses */
D 6
	for (i = 0; Mailer[i] != NULL; i++)
E 6
I 6
D 14
	for (q = SendQueue; q != NULL; q = q->q_next)
E 14
I 14
D 15
	for (q = CurEnv->e_sendqueue; q != NULL; q = q->q_next)
E 15
I 15
	for (q = e->e_sendqueue; q != NULL; q = q->q_next)
E 15
E 14
E 6
	{
D 6
		register ADDRESS *q;

		for (q = Mailer[i]->m_sendq; q != NULL; q = q->q_next)
		{
			if (!bitset(QQUEUEUP, q->q_flags))
				continue;
			fprintf(f, "R%s\n", q->q_paddr);
		}
E 6
I 6
D 7
		if (!bitset(QQUEUEUP, q->q_flags))
			continue;
		fprintf(f, "R%s\n", q->q_paddr);
E 7
I 7
D 57
# ifdef DEBUG
D 29
		if (Debug > 0)
E 29
I 29
		if (tTd(40, 1))
E 29
		{
			printf("queueing ");
			printaddr(q, FALSE);
		}
# endif DEBUG
E 57
D 17
		if (bitset(QQUEUEUP, q->q_flags))
E 17
I 17
D 33
		if (queueall || bitset(QQUEUEUP, q->q_flags))
E 33
I 33
		if (queueall ? !bitset(QDONTSEND, q->q_flags) :
			       bitset(QQUEUEUP, q->q_flags))
I 46
		{
E 46
E 33
E 17
D 15
			fprintf(f, "R%s\n", q->q_paddr);
E 15
I 15
D 36
			fprintf(cfp, "R%s\n", q->q_paddr);
E 36
I 36
			fprintf(tfp, "R%s\n", q->q_paddr);
I 56
			if (announce)
			{
				e->e_to = q->q_paddr;
				message(Arpa_Info, "queued");
				if (LogLevel > 4)
					logdelivery("queued");
				e->e_to = NULL;
			}
I 57
#ifdef DEBUG
			if (tTd(40, 1))
			{
				printf("queueing ");
				printaddr(q, FALSE);
			}
#endif DEBUG
E 57
E 56
I 46
		}
E 46
E 36
E 15
E 7
E 6
	}

I 102
	/* output list of error recipients */
	for (q = e->e_errorqueue; q != NULL; q = q->q_next)
	{
D 103
		fprintf(tfp, "E%s\n", q->q_paddr);
E 103
I 103
		if (!bitset(QDONTSEND, q->q_flags))
			fprintf(tfp, "E%s\n", q->q_paddr);
E 103
	}

E 102
D 56
	/* output headers for this message */
I 33
	define('g', "$f");
E 56
I 56
	/*
	**  Output headers for this message.
	**	Expand macros completely here.  Queue run will deal with
	**	everything as absolute headers.
	**		All headers that must be relative to the recipient
	**		can be cracked later.
I 69
	**	We set up a "null mailer" -- i.e., a mailer that will have
	**	no effect on the addresses as they are output.
E 69
	*/

I 69
D 73
	bzero(&nullmailer, sizeof nullmailer);
E 73
I 73
	bzero((char *) &nullmailer, sizeof nullmailer);
E 73
	nullmailer.m_r_rwset = nullmailer.m_s_rwset = -1;
I 72
	nullmailer.m_eol = "\n";
E 72

E 69
D 80
	define('g', "$f", e);
E 80
I 80
	define('g', "\001f", e);
E 80
E 56
E 33
D 14
	for (h = Header; h != NULL; h = h->h_link)
E 14
I 14
D 15
	for (h = CurEnv->e_header; h != NULL; h = h->h_link)
E 15
I 15
	for (h = e->e_header; h != NULL; h = h->h_link)
E 15
E 14
	{
I 73
		extern bool bitzerop();

I 75
		/* don't output null headers */
E 75
E 73
		if (h->h_value == NULL || h->h_value[0] == '\0')
			continue;
I 75

		/* don't output resent headers on non-resent messages */
		if (bitset(H_RESENT, h->h_flags) && !bitset(EF_RESENT, e->e_flags))
			continue;

		/* output this header */
E 75
D 15
		fprintf(f, "H");
E 15
I 15
D 36
		fprintf(cfp, "H");
E 36
I 36
		fprintf(tfp, "H");
I 75

		/* if conditional, output the set of conditions */
E 75
E 36
E 15
D 73
		if (h->h_mflags != 0 && bitset(H_CHECK|H_ACHECK, h->h_flags))
D 15
			mfdecode(h->h_mflags, f);
D 10
		fprintf(f, "%s: ", h->h_field);
		if (bitset(H_DEFAULT, h->h_flags))
		{
			char buf[MAXLINE];

			(void) expand(h->h_value, buf, &buf[sizeof buf]);
			fprintf(f, "%s\n", buf);
		}
		else
			fprintf(f, "%s\n", h->h_value);
E 10
I 10
		fprintf(f, "%s: %s\n", h->h_field, h->h_value);
E 15
I 15
D 36
			mfdecode(h->h_mflags, cfp);
D 33
		fprintf(cfp, "%s: %s\n", h->h_field, h->h_value);
E 33
I 33
		fprintf(cfp, "%s: ", h->h_field);
E 36
I 36
			mfdecode(h->h_mflags, tfp);
E 73
I 73
		if (!bitzerop(h->h_mflags) && bitset(H_CHECK|H_ACHECK, h->h_flags))
		{
			int j;

D 86
			putc('?', tfp);
E 86
I 86
			(void) putc('?', tfp);
E 86
			for (j = '\0'; j <= '\177'; j++)
				if (bitnset(j, h->h_mflags))
D 86
					putc(j, tfp);
			putc('?', tfp);
E 86
I 86
					(void) putc(j, tfp);
			(void) putc('?', tfp);
E 86
		}
I 75

		/* output the header: expand macros, convert addresses */
E 75
E 73
D 45
		fprintf(tfp, "%s: ", h->h_field);
E 45
E 36
		if (bitset(H_DEFAULT, h->h_flags))
		{
			(void) expand(h->h_value, buf, &buf[sizeof buf], e);
D 36
			fprintf(cfp, "%s\n", buf);
E 36
I 36
D 45
			fprintf(tfp, "%s\n", buf);
E 45
I 45
			fprintf(tfp, "%s: %s\n", h->h_field, buf);
E 45
E 36
		}
D 46
		else
E 46
I 46
		else if (bitset(H_FROM|H_RCPT, h->h_flags))
E 46
D 36
			fprintf(cfp, "%s\n", h->h_value);
E 36
I 36
D 45
			fprintf(tfp, "%s\n", h->h_value);
E 45
I 45
D 54
			commaize(h, h->h_value, tfp, e->e_oldstyle, NULL);
E 54
I 54
D 55
			commaize(h, h->h_value, tfp,
				 bitset(EF_OLDSTYLE, e->e_flags), NULL);
E 55
I 55
		{
			commaize(h, h->h_value, tfp, bitset(EF_OLDSTYLE, e->e_flags),
D 62
				 (MAILER *) NULL);
E 62
I 62
D 69
				 (MAILER *) NULL, FALSE);
E 69
I 69
				 &nullmailer);
E 69
E 62
		}
E 55
E 54
I 46
		else
			fprintf(tfp, "%s: %s\n", h->h_field, h->h_value);
E 46
E 45
E 36
E 33
E 15
E 10
	}

	/*
	**  Clean up.
	*/

I 82
	(void) fclose(tfp);
E 82
D 15
	(void) fclose(f);
E 15
I 15
D 36
	(void) fclose(cfp);
	(void) strcpy(buf, QueueDir);
	(void) strcat(buf, "/cfXXXXXX");
	(void) mktemp(buf);
	if (link(cf, buf) < 0)
		syserr("cannot link(%s, %s), df=%s", cf, buf, e->e_df);
E 36
I 36
D 81
	(void) fclose(tfp);
E 81
	qf = queuename(e, 'q');
I 56
D 81
	holdsigs();
E 56
	(void) unlink(qf);
	if (link(tf, qf) < 0)
		syserr("cannot link(%s, %s), df=%s", tf, qf, e->e_df);
E 36
	else
D 18
		unlink(cf);
E 18
I 18
D 36
		(void) unlink(cf);
E 36
I 36
		(void) unlink(tf);
I 56
	rlsesigs();
E 81
I 81
	if (tf != NULL)
	{
D 82
# ifdef FLOCK
		(void) flock(fileno(tfp), LOCK_EX|LOCK_NB);
		if (rename(tf, qf) < 0)
			syserr("cannot rename(%s, %s), df=%s", tf, qf, e->e_df);
# else FLOCK
E 82
D 93
		holdsigs();
E 93
		(void) unlink(qf);
D 93
		if (link(tf, qf) < 0)
			syserr("cannot link(%s, %s), df=%s", tf, qf, e->e_df);
		else
			(void) unlink(tf);
		rlsesigs();
E 93
I 93
		if (rename(tf, qf) < 0)
			syserr("cannot unlink(%s, %s), df=%s", tf, qf, e->e_df);
		errno = 0;
E 93
D 82
# endif FLOCK
E 82
	}
D 82
	(void) fclose(tfp);
	e->e_qfp = NULL;
E 82
E 81
E 56
D 47
	e->e_qf = NULL;
E 47
E 36
I 26

I 29
# ifdef LOG
	/* save log info */
D 39
	if (LogLevel > 9)
D 36
		syslog(LOG_INFO, "%s queueup: cf=%s, df=%s\n", MsgId, buf, e->e_df);
E 36
I 36
		syslog(LOG_INFO, "%s queueup: qf=%s, df=%s\n", e->e_id, qf, e->e_df);
E 39
I 39
	if (LogLevel > 15)
		syslog(LOG_DEBUG, "%s: queueup, qf=%s, df=%s\n", e->e_id, qf, e->e_df);
E 39
E 36
# endif LOG
D 47

E 29
D 46
	/* disconnect this temp file from the job */
E 46
I 46
	/* disconnect this temp file from the job; don't requeue later */
E 46
	e->e_df = NULL;
I 46
	e->e_dontqueue = TRUE;
E 47
E 46
E 26
E 18
E 15
}
/*
**  RUNQUEUE -- run the jobs in the queue.
**
**	Gets the stuff out of the queue in some presumably logical
**	order and processes them.
**
**	Parameters:
D 88
**		none.
E 88
I 88
**		forkflag -- TRUE if the queue scanning should be done in
**			a child process.  We double-fork so it is not our
**			child and we don't have to clean up after it.
E 88
**
**	Returns:
**		none.
**
**	Side Effects:
**		runs things in the mail queue.
*/

I 2
D 3
bool	ReorderQueue;
E 3
I 3
D 42
bool	ReorderQueue;		/* if set, reorder the send queue */
int	QueuePid;		/* pid of child running queue */
E 3

E 42
E 2
D 3
runqueue()
E 3
I 3
runqueue(forkflag)
	bool forkflag;
E 3
{
I 89
	extern bool shouldqueue();

E 89
D 2
	/*
	**  Order the existing work requests.
	*/
E 2
I 2
D 42
	extern reordersig();
E 42
I 42
D 56
	register int i;
E 42
E 2

E 56
I 3
D 27
	if (QueueIntvl != 0)
	{
D 4
		signal(SIGALRM, reordersig);
		alarm(QueueIntvl);
E 4
I 4
		(void) signal(SIGALRM, reordersig);
D 18
		(void) alarm((unsigned) QueueIntvl);
E 18
I 18
		(void) alarm(QueueIntvl);
E 18
E 4
	}
E 27
I 27
	/*
I 89
	**  If no work will ever be selected, don't even bother reading
	**  the queue.
	*/

	if (shouldqueue(-100000000L))
	{
		if (Verbose)
			printf("Skipping queue run -- load average too high\n");

		if (forkflag)
			return;
		finis();
	}

	/*
E 89
	**  See if we want to go off and do other useful work.
	*/
E 27

	if (forkflag)
	{
D 42
		QueuePid = dofork();
		if (QueuePid > 0)
E 42
I 42
		int pid;

		pid = dofork();
		if (pid != 0)
E 42
		{
I 100
			extern reapchild();

E 100
D 42
			/* parent */
E 42
I 42
			/* parent -- pick up intermediate zombie */
I 100
#ifndef SIGCHLD
E 100
D 56
			do
			{
				auto int stat;

				i = wait(&stat);
			} while (i >= 0 && i != pid);
E 56
I 56
			(void) waitfor(pid);
I 100
#else SIGCHLD
			(void) signal(SIGCHLD, reapchild);
#endif SIGCHLD
E 100
E 56
E 42
I 31
			if (QueueIntvl != 0)
D 42
				setevent(QueueIntvl, reordersig, TRUE);
E 42
I 42
D 55
				setevent(QueueIntvl, runqueue, TRUE);
E 55
I 55
				(void) setevent(QueueIntvl, runqueue, TRUE);
E 55
E 42
E 31
			return;
		}
I 42
		/* child -- double fork */
I 100
#ifndef SIGCHLD
E 100
		if (fork() != 0)
			exit(EX_OK);
I 100
#else SIGCHLD
		(void) signal(SIGCHLD, SIG_DFL);
#endif SIGCHLD
E 100
E 42
D 31
		else
D 4
			alarm(0);
E 4
I 4
D 18
			(void) alarm((unsigned) 0);
E 18
I 18
			(void) alarm(0);
E 31
E 18
E 4
	}
I 88

	setproctitle("running queue");

E 88
I 38
# ifdef LOG
	if (LogLevel > 11)
D 42
		syslog(LOG_DEBUG, "runqueue, pid=%d", getpid());
E 42
I 42
		syslog(LOG_DEBUG, "runqueue %s, pid=%d", QueueDir, getpid());
E 42
# endif LOG
E 38

E 3
D 2
	orderq();
E 2
I 2
D 27
	for (;;)
E 27
I 27
	/*
I 71
	**  Release any resources used by the daemon code.
	*/

# ifdef DAEMON
	clrdaemon();
# endif DAEMON

	/*
I 104
	**  Make sure the alias database is open.
	*/

	initaliases(AliasFile, FALSE);

	/*
E 104
E 71
D 31
	**  Arrange to reorder the queue at polite intervals.
	*/

	if (QueueIntvl != 0)
E 27
	{
D 27
		/*
		**  Order the existing work requests.
		*/
E 27
I 27
		(void) signal(SIGALRM, reordersig);
		(void) alarm(QueueIntvl);
	}
E 27
E 2

D 2
	/*
	**  Process them once at a time.
	**	The queue could be reordered while we do this to take
	**	new requests into account.  If so, the existing job
	**	will be finished but the next thing taken off WorkQ
	**	may be something else.
	*/
E 2
I 2
D 27
		orderq();
E 27
I 27
	/*
E 31
	**  Start making passes through the queue.
	**	First, read and sort the entire queue.
	**	Then, process the work in that order.
	**		But if you take too long, start over.
D 42
	**	There is a race condition at the end -- we could get
	**		a reorder signal after finishing the queue.
	**		In this case we will hang for one more queue
	**		interval -- clearly a botch, but rare and
	**		relatively innocuous.
E 42
	*/
E 27
E 2

D 2
	while (WorkQ != NULL)
	{
		WORK *w = WorkQ;
E 2
I 2
D 27
		if (WorkQ == NULL)
		{
			/* no work?  well, maybe later */
			if (QueueIntvl == 0)
				break;
D 3
			sleep(QueueIntvl);
E 3
I 3
			pause();
E 3
			continue;
		}
E 2

E 27
I 27
D 42
	for (;;)
	{
		/* order the existing work requests */
		orderq();
E 42
I 42
	/* order the existing work requests */
D 63
	orderq();
E 63
I 63
D 90
	(void) orderq();
E 90
I 90
	(void) orderq(FALSE);
E 90
E 63
E 42
I 31

D 42
		/* arrange to reorder later */
E 31
E 27
D 2
		WorkQ = WorkQ->w_next;
		dowork(w);
		free(w->w_name);
		free((char *) w);
E 2
I 2
		ReorderQueue = FALSE;
I 31
		if (QueueIntvl != 0)
			setevent(QueueIntvl, reordersig, FALSE);
E 31
D 3
		if (QueueIntvl != 0)
		{
			signal(SIGALRM, reordersig);
			alarm(QueueIntvl);
		}
E 3

D 27
		/*
		**  Process them once at a time.
		**	The queue could be reordered while we do this to take
		**	new requests into account.  If so, the existing job
		**	will be finished but the next thing taken off WorkQ
		**	may be something else.
		*/

E 27
I 27
		/* process them once at a time */
E 27
		while (WorkQ != NULL)
		{
			WORK *w = WorkQ;

			WorkQ = WorkQ->w_next;
			dowork(w);
			free(w->w_name);
			free((char *) w);
			if (ReorderQueue)
				break;
		}

I 27
		/* if we are just doing one pass, then we are done */
E 27
		if (QueueIntvl == 0)
D 31
			break;
E 31
I 31
			finis();
E 31
I 27

		/* wait for work -- note (harmless) race condition here */
D 31
		if (!ReorderQueue)
E 31
I 31
		while (!ReorderQueue)
		{
			if (forkflag)
				finis();
E 31
			pause();
I 31
		}
E 31
E 27
E 2
	}
I 11
D 31

	/* no work to do -- just exit */
	finis();
E 31
E 11
}
/*
I 2
D 31
**  REORDERSIG -- catch the alarm signal and tell sendmail to reorder queue.
E 31
I 31
**  REORDERSIG -- catch the reorder signal and tell sendmail to reorder queue.
E 31
**
**	Parameters:
D 31
**		none.
E 31
I 31
**		parent -- if set, called from parent (i.e., not
**			really doing the work).
E 31
**
**	Returns:
**		none.
**
**	Side Effects:
**		sets the "reorder work queue" flag.
*/

D 31
reordersig()
E 31
I 31
reordersig(parent)
	bool parent;
E 31
{
D 3
	ReorderQueue = TRUE;
E 3
I 3
D 31
	if (QueuePid == 0)
E 31
I 31
	if (!parent)
E 42
I 42
	/* process them once at a time */
	while (WorkQ != NULL)
E 42
E 31
	{
D 42
		/* we are in a child doing queueing */
		ReorderQueue = TRUE;
E 42
I 42
		WORK *w = WorkQ;
E 42
I 40

D 42
		/* arrange to get this signal again */
		setevent(QueueIntvl, reordersig, FALSE);
E 42
I 42
		WorkQ = WorkQ->w_next;
		dowork(w);
		free(w->w_name);
		free((char *) w);
E 42
E 40
	}
D 42
	else
	{
D 31
		/* we are in a parent -- poke child or start new one */
E 31
I 31
		/*
		**  In parent.  If the child still exists, we want
		**  to do nothing.  If the child is gone, we will
		**  start up a new one.
		**  If the child exists, it is responsible for
		**  doing a queue reorder.
		**  This code really sucks.
		*/

E 31
		if (kill(QueuePid, SIGALRM) < 0)
		{
			/* no child -- get zombie & start new one */
			static int st;

D 4
			wait(&st);
E 4
I 4
			(void) wait(&st);
E 4
D 31
			QueuePid = dofork();
			if (QueuePid == 0)
			{
				/* new child; run queue */
D 4
				runqueue();
E 4
I 4
				runqueue(FALSE);
E 4
				finis();
			}
E 31
I 31
			runqueue(TRUE);
E 31
		}
I 40
		else
			setevent(QueueIntvl, reordersig, TRUE);
E 40
	}
E 42
I 42
D 105
	finis();
E 105
I 105

	/* exit without the usual cleanup */
	exit(ExitStat);
E 105
E 42
D 40

	/*
	**  Arrange to get this signal again.
	*/

I 12
D 31
	(void) signal(SIGALRM, reordersig);
E 12
D 4
	alarm(QueueIntvl);
E 4
I 4
D 18
	(void) alarm((unsigned) QueueIntvl);
E 18
I 18
	(void) alarm(QueueIntvl);
E 31
I 31
	setevent(QueueIntvl, reordersig, parent);
E 40
E 31
E 18
E 4
E 3
}
/*
E 2
**  ORDERQ -- order the work queue.
**
**	Parameters:
D 88
**		none.
E 88
I 88
**		doall -- if set, include everything in the queue (even
**			the jobs that cannot be run because the load
**			average is too high).  Otherwise, exclude those
**			jobs.
E 88
**
**	Returns:
D 68
**		none.
E 68
I 68
**		The number of request in the queue (not necessarily
**		the number of requests in WorkQ however).
E 68
**
**	Side Effects:
**		Sets WorkQ to the queue of available work, in order.
*/

D 102
# define WLSIZE		120	/* max size of worklist per sort */
E 102
I 102
# define NEED_P		001
# define NEED_T		002
E 102

I 49
# ifndef DIR
# define DIR		FILE
# define direct		dir
# define opendir(d)	fopen(d, "r")
D 51
# define readdir(f)	(fread(dbuf, sizeof dbuf, 1, f) > 0 ? &dbuf : 0)
E 51
I 51
# define readdir(f)	((fread(&dbuf, sizeof dbuf, 1, f) > 0) ? &dbuf : 0)
E 51
static struct dir	dbuf;
# define closedir(f)	fclose(f)
# endif DIR

E 49
D 88
orderq()
E 88
I 88
orderq(doall)
	bool doall;
E 88
{
D 13
	struct direct d;
E 13
I 13
	register struct direct *d;
E 13
	register WORK *w;
D 95
	register WORK **wp;		/* parent of w */
E 95
D 13
	register FILE *f;
E 13
I 13
	DIR *f;
E 13
	register int i;
D 9
	struct stat st;
E 9
D 68
	WORK wlist[WLSIZE];
E 68
I 68
D 102
	WORK wlist[WLSIZE+1];
E 102
I 102
	WORK wlist[QUEUESIZE+1];
E 102
E 68
D 63
	int wn = 0;
E 63
I 63
	int wn = -1;
E 63
	extern workcmpf();
D 44
	extern char *QueueDir;
E 44

	/* clear out old WorkQ */
	for (w = WorkQ; w != NULL; )
	{
		register WORK *nw = w->w_next;

		WorkQ = nw;
		free(w->w_name);
		free((char *) w);
		w = nw;
	}

	/* open the queue directory */
D 13
	f = fopen(QueueDir, "r");
E 13
I 13
D 44
	f = opendir(QueueDir);
E 44
I 44
	f = opendir(".");
E 44
E 13
	if (f == NULL)
	{
D 44
		syserr("orderq: cannot open %s", QueueDir);
E 44
I 44
		syserr("orderq: cannot open \"%s\" as \".\"", QueueDir);
E 44
D 63
		return;
E 63
I 63
		return (0);
E 63
	}

	/*
	**  Read the work directory.
	*/

D 13
	while (wn < WLSIZE && fread((char *) &d, sizeof d, 1, f) == 1)
E 13
I 13
D 63
	while (wn < WLSIZE && (d = readdir(f)) != NULL)
E 63
I 63
	while ((d = readdir(f)) != NULL)
E 63
E 13
	{
D 44
		char cbuf[MAXNAME];
E 44
D 56
		char lbuf[MAXNAME];
E 56
		FILE *cf;
I 56
		char lbuf[MAXNAME];
E 56
D 44
		register char *p;
E 44

		/* is this an interesting entry? */
I 51
		if (d->d_ino == 0)
			continue;
# ifdef DEBUG
		if (tTd(40, 10))
			printf("orderq: %12s\n", d->d_name);
# endif DEBUG
E 51
D 13
		if (d.d_ino == 0 || d.d_name[0] != 'c')
E 13
I 13
D 34
		if (d->d_name[0] != 'c')
E 34
I 34
D 36
		if (d->d_name[0] != 'c' || d->d_name[1] != 'f')
E 36
I 36
		if (d->d_name[0] != 'q' || d->d_name[1] != 'f')
E 36
E 34
E 13
			continue;

D 44
		/* yes -- find the control file location */
D 18
		strcpy(cbuf, QueueDir);
		strcat(cbuf, "/");
E 18
I 18
		(void) strcpy(cbuf, QueueDir);
		(void) strcat(cbuf, "/");
E 18
		p = &cbuf[strlen(cbuf)];
D 13
		strncpy(p, d.d_name, DIRSIZ);
		p[DIRSIZ] = '\0';
E 13
I 13
D 18
		strcpy(p, d->d_name);
E 18
I 18
		(void) strcpy(p, d->d_name);
E 18
E 13

		/* open control file */
		cf = fopen(cbuf, "r");
E 44
I 44
D 63
		/* yes -- open control file */
E 63
I 63
		/* yes -- open control file (if not too many files) */
D 102
		if (++wn >= WLSIZE)
E 102
I 102
		if (++wn >= QUEUESIZE)
E 102
			continue;
E 63
		cf = fopen(d->d_name, "r");
E 44
		if (cf == NULL)
		{
D 21
			syserr("orderq: cannot open %s", cbuf);
E 21
I 21
			/* this may be some random person sending hir msgs */
			/* syserr("orderq: cannot open %s", cbuf); */
I 64
#ifdef DEBUG
			if (tTd(41, 2))
				printf("orderq: cannot open %s (%d)\n",
					d->d_name, errno);
#endif DEBUG
E 64
			errno = 0;
I 64
			wn--;
E 64
E 21
			continue;
		}
I 7
D 44
		wlist[wn].w_name = newstr(cbuf);
E 44
I 44
D 102
		wlist[wn].w_name = newstr(d->d_name);
E 102
I 102
		w = &wlist[wn];
		w->w_name = newstr(d->d_name);
E 102
E 44
E 7

I 98
		/* make sure jobs in creation don't clog queue */
D 102
		wlist[wn].w_pri = 0x7fffffff;
		wlist[wn].w_ctime = 0;
E 102
I 102
		w->w_pri = 0x7fffffff;
		w->w_ctime = 0;
E 102

E 98
		/* extract useful information */
D 7
		wlist[wn].w_pri = PRI_NORMAL;
E 7
D 102
		while (fgets(lbuf, sizeof lbuf, cf) != NULL)
E 102
I 102
		i = NEED_P | NEED_T;
		while (i != 0 && fgets(lbuf, sizeof lbuf, cf) != NULL)
E 102
		{
I 90
			extern long atol();

E 90
D 56
			fixcrlf(lbuf, TRUE);

			switch (lbuf[0])
E 56
I 56
D 88
			if (lbuf[0] == 'P')
E 88
I 88
			switch (lbuf[0])
E 88
E 56
			{
D 7
			  case 'D':		/* data file name */
				if (stat(&lbuf[1], &st) < 0)
				{
					syserr("orderq: cannot stat %s", &lbuf[1]);
					(void) fclose(cf);
					(void) unlink(cbuf);
					wn--;
					continue;
				}
				wlist[wn].w_name = newstr(cbuf);
				wlist[wn].w_size = st.st_size;
				break;

E 7
D 56
			  case 'P':		/* message priority */
E 56
D 7
				wlist[wn].w_pri = atoi(&lbuf[1]);
E 7
I 7
D 88
				(void) sscanf(&lbuf[1], "%ld", &wlist[wn].w_pri);
E 88
I 88
			  case 'P':
D 102
				wlist[wn].w_pri = atol(&lbuf[1]);
E 102
I 102
				w->w_pri = atol(&lbuf[1]);
				i &= ~NEED_P;
E 102
E 88
E 7
				break;
I 97

			  case 'T':
D 102
				wlist[wn].w_ctime = atol(&lbuf[1]);
E 102
I 102
				w->w_ctime = atol(&lbuf[1]);
				i &= ~NEED_T;
E 102
				break;
E 97
I 88
D 95

			  case 'T':
				wlist[wn].w_ctime = atol(&lbuf[1]);
				break;
E 95
E 88
			}
		}
D 63
		wn++;
E 63
		(void) fclose(cf);
I 89

D 102
		if (!doall && shouldqueue(wlist[wn].w_pri))
E 102
I 102
		if (!doall && shouldqueue(w->w_pri))
E 102
		{
			/* don't even bother sorting this job in */
			wn--;
		}
E 89
	}
D 13
	(void) fclose(f);
E 13
I 13
	(void) closedir(f);
I 64
	wn++;
E 64
E 13

	/*
	**  Sort the work directory.
	*/

D 68
	qsort(wlist, wn, sizeof *wlist, workcmpf);
E 68
I 68
D 87
	qsort(wlist, min(wn, WLSIZE), sizeof *wlist, workcmpf);
E 87
I 87
D 102
	qsort((char *) wlist, min(wn, WLSIZE), sizeof *wlist, workcmpf);
E 102
I 102
	qsort((char *) wlist, min(wn, QUEUESIZE), sizeof *wlist, workcmpf);
E 102
E 87
E 68

	/*
	**  Convert the work list into canonical form.
I 56
	**	Should be turning it into a list of envelopes here perhaps.
E 56
	*/

D 95
	wp = &WorkQ;
E 95
I 95
	WorkQ = NULL;
E 95
D 68
	for (i = 0; i < wn; i++)
E 68
I 68
D 102
	for (i = min(wn, WLSIZE); --i >= 0; )
E 102
I 102
	for (i = min(wn, QUEUESIZE); --i >= 0; )
E 102
E 68
	{
		w = (WORK *) xalloc(sizeof *w);
		w->w_name = wlist[i].w_name;
D 7
		w->w_size = wlist[i].w_size;
E 7
		w->w_pri = wlist[i].w_pri;
I 97
		w->w_ctime = wlist[i].w_ctime;
E 97
I 88
D 95
		w->w_ctime = wlist[i].w_ctime;
E 88
		w->w_next = NULL;
		*wp = w;
		wp = &w->w_next;
E 95
I 95
		w->w_next = WorkQ;
		WorkQ = w;
E 95
	}

# ifdef DEBUG
D 29
	if (Debug)
E 29
I 29
	if (tTd(40, 1))
E 29
	{
		for (w = WorkQ; w != NULL; w = w->w_next)
D 2
			printf("%32s: sz=%ld\n", w->w_name, w->w_size);
E 2
I 2
D 7
			printf("%32s: pri=%-2d sz=%ld\n", w->w_name, w->w_pri,
			     w->w_size);
E 7
I 7
			printf("%32s: pri=%ld\n", w->w_name, w->w_pri);
E 7
E 2
	}
# endif DEBUG
I 63

D 64
	return (wn + 1);
E 64
I 64
	return (wn);
E 64
E 63
}
/*
D 29
**	WORKCMPF -- compare function for ordering work.
E 29
I 29
**  WORKCMPF -- compare function for ordering work.
E 29
**
**	Parameters:
**		a -- the first argument.
**		b -- the second argument.
**
**	Returns:
D 68
**		-1 if a < b
E 68
I 68
D 95
**		1 if a < b
E 68
**		0 if a == b
D 68
**		1 if a > b
E 68
I 68
**		-1 if a > b
E 95
I 95
**		-1 if a < b
**		 0 if a == b
**		+1 if a > b
E 95
E 68
**
**	Side Effects:
**		none.
*/

D 68
# define PRIFACT	1800		/* bytes each priority point is worth */

E 68
workcmpf(a, b)
D 7
	WORK *a;
	WORK *b;
E 7
I 7
	register WORK *a;
	register WORK *b;
E 7
{
D 7
	register long aval;
	register long bval;

	aval = a->w_size - PRIFACT * a->w_pri;
	bval = b->w_size - PRIFACT * b->w_pri;

	if (aval == bval)
E 7
I 7
D 88
	if (a->w_pri == b->w_pri)
E 88
I 88
D 95
	long pa = a->w_pri + a->w_ctime;
	long pb = b->w_pri + b->w_ctime;
E 95
I 95
D 97
	long pa = a->w_pri;
	long pb = b->w_pri;
E 97
I 97
	long pa = a->w_pri + a->w_ctime;
	long pb = b->w_pri + b->w_ctime;
E 97
E 95

	if (pa == pb)
E 88
E 7
		return (0);
D 7
	else if (aval > bval)
E 7
I 7
D 88
	else if (a->w_pri > b->w_pri)
E 88
I 88
	else if (pa > pb)
E 88
E 7
D 68
		return (1);
	else
E 68
D 95
		return (-1);
I 68
	else
E 95
		return (1);
I 95
	else
		return (-1);
E 95
E 68
}
/*
**  DOWORK -- do a work request.
**
**	Parameters:
**		w -- the work request to be satisfied.
**
**	Returns:
**		none.
**
**	Side Effects:
**		The work request is satisfied if possible.
*/

dowork(w)
	register WORK *w;
{
	register int i;
I 88
	extern bool shouldqueue();
E 88
D 56
	auto int xstat;
E 56

# ifdef DEBUG
D 29
	if (Debug)
E 29
I 29
	if (tTd(40, 1))
E 29
D 7
		printf("dowork: %s size %ld pri %d\n", w->w_name,
		    w->w_size, w->w_pri);
E 7
I 7
		printf("dowork: %s pri %ld\n", w->w_name, w->w_pri);
E 7
# endif DEBUG

	/*
D 88
	**  Fork for work.
E 88
I 88
	**  Ignore jobs that are too expensive for the moment.
E 88
	*/

D 88
	i = fork();
	if (i < 0)
E 88
I 88
	if (shouldqueue(w->w_pri))
E 88
	{
D 88
		syserr("dowork: cannot fork");
E 88
I 88
		if (Verbose)
D 92
			printf("\nSkipping %s\n", w->w_name);
E 92
I 92
			printf("\nSkipping %s\n", w->w_name + 2);
E 92
E 88
		return;
	}

I 88
	/*
	**  Fork for work.
	*/

	if (ForkQueueRuns)
	{
		i = fork();
		if (i < 0)
		{
			syserr("dowork: cannot fork");
			return;
		}
	}
	else
	{
		i = 0;
	}

E 88
	if (i == 0)
	{
I 81
D 82
		FILE *qfp;

E 82
E 81
I 15
D 55
		char buf[MAXNAME];

E 55
E 15
		/*
		**  CHILD
I 15
D 44
		**	Change the name of the control file to avoid
D 23
		**	duplicate deliveries.   Then run the file as
		**	though we had just read it.
E 23
I 23
		**		duplicate deliveries.   Then run the file
		**		as though we had just read it.
E 44
I 44
		**	Lock the control file to avoid duplicate deliveries.
		**		Then run the file as though we had just read it.
E 44
		**	We save an idea of the temporary name so we
		**		can recover on interrupt.
E 23
E 15
		*/

I 33
		/* set basic modes, etc. */
E 33
I 24
		(void) alarm(0);
I 70
D 91
		closexscript(CurEnv);
E 70
E 24
I 22
D 54
		FatalErrors = FALSE;
E 54
I 54
		CurEnv->e_flags &= ~EF_FATALERRS;
E 91
I 91
D 101
		clearenvelope(CurEnv);
E 101
I 101
		clearenvelope(CurEnv, FALSE);
E 101
E 91
E 54
E 22
		QueueRun = TRUE;
I 57
D 65
		SendMode = SM_DELIVER;
E 65
E 57
I 16
D 56
		MailBack = TRUE;
E 56
I 56
		ErrorMode = EM_MAIL;
E 56
I 36
D 54
		CurEnv->e_qf = w->w_name;
E 54
D 44
		CurEnv->e_id = &w->w_name[strlen(QueueDir) + 3];
E 44
I 44
		CurEnv->e_id = &w->w_name[2];
E 44
I 38
# ifdef LOG
		if (LogLevel > 11)
D 40
			syslog(LOG_DEBUG, "dowork, pid=%d, id=%s", getpid(),
			       CurEnv->e_id);
E 40
I 40
			syslog(LOG_DEBUG, "%s: dowork, pid=%d", CurEnv->e_id,
			       getpid());
E 40
# endif LOG
E 38
E 36
I 33

		/* don't use the headers from sendmail.cf... */
		CurEnv->e_header = NULL;
D 55
		chompheader("from: $q", TRUE);
E 55
I 55
D 74
		(void) chompheader("from: $q", TRUE);
E 74
E 55

D 81
		/* create the link to the control file during processing */
E 81
I 81
D 82
		FileName = queuename(CurEnv, 'q');
		qfp = fopen(FileName, "r");
		if (qfp == NULL)
			exit(EX_OK);

E 82
		/* lock the control file during processing */
D 82
# ifdef FLOCK
		if (flock(fileno(qfp), LOCK_EX|LOCK_NB) < 0)
# else FLOCK
E 82
E 81
E 33
E 16
I 15
D 36
		(void) strcpy(buf, QueueDir);
		(void) strcat(buf, "/tfXXXXXX");
		(void) mktemp(buf);
		if (link(w->w_name, buf) < 0)
E 36
I 36
		if (link(w->w_name, queuename(CurEnv, 'l')) < 0)
I 81
D 82
# endif FLOCK
E 82
E 81
E 36
		{
D 30
			syserr("dowork: link(%s, %s)", w->w_name, buf);

			/* it's ok to lie -- it will be run later */
E 30
I 30
D 36
			/* this can happen normally; another queuer sneaks in */
			/* syserr("dowork: link(%s, %s)", w->w_name, buf); */
E 36
I 36
			/* being processed by another queuer */
I 40
# ifdef LOG
			if (LogLevel > 4)
				syslog(LOG_DEBUG, "%s: locked", CurEnv->e_id);
# endif LOG
E 40
E 36
E 30
D 88
			exit(EX_OK);
E 88
I 88
			if (ForkQueueRuns)
				exit(EX_OK);
			else
				return;
E 88
		}
I 23
D 36
		ControlFile = newstr(buf);
E 23
		(void) unlink(w->w_name);
E 36

D 59
		/* create ourselves a transcript file */
E 15
I 2
		openxscrpt();
I 15

E 59
		/* do basic system initialization */
E 15
E 2
		initsys();
D 15
		readqf(w->w_name);
E 15
I 15

		/* read the queue control file */
D 36
		readqf(buf);
E 36
I 36
D 54
		readqf(CurEnv->e_qf);
E 54
I 54
D 56
		readqf(queuename(CurEnv, 'q'));
E 56
I 56
D 61
		readqf(CurEnv);
E 61
I 61
D 81
		readqf(CurEnv, TRUE);
E 81
I 81
D 82
		readqf(qfp, CurEnv, TRUE);
		(void) fclose(qfp);
E 82
I 82
		readqf(CurEnv, TRUE);
E 82
E 81
E 61
E 56
		CurEnv->e_flags |= EF_INQUEUE;
E 54
E 36
I 34
D 56
		eatheader();
E 56
I 56
		eatheader(CurEnv);
E 56
E 34

		/* do the delivery */
E 15
D 20
		sendall(FALSE);
E 20
I 20
D 28
		sendall(CurEnv, FALSE);
E 28
I 28
D 54
		if (!FatalErrors)
E 54
I 54
		if (!bitset(EF_FATALERRS, CurEnv->e_flags))
E 54
D 53
			sendall(CurEnv, FALSE);
E 53
I 53
			sendall(CurEnv, SM_DELIVER);
E 53
E 28
E 20
I 15

D 65
		/* if still not sent, perhaps we should time out.... */
E 15
I 2
# ifdef DEBUG
D 29
		if (Debug > 2)
E 29
I 29
		if (tTd(40, 3))
E 29
D 37
			printf("CurTime=%ld, TimeOut=%ld\n", CurTime, TimeOut);
E 37
I 37
D 41
			printf("CurTime=%ld, TimeOut=%ld\n", CurTime,
E 41
I 41
			printf("curtime=%ld, TimeOut=%ld\n", curtime(),
E 41
					     CurEnv->e_ctime + TimeOut);
E 37
# endif DEBUG
D 14
		if (QueueUp && CurTime > TimeOut)
E 14
I 14
D 37
		if (CurEnv->e_queueup && CurTime > TimeOut)
E 37
I 37
D 41
		if (CurEnv->e_queueup && CurTime > CurEnv->e_ctime + TimeOut)
E 41
I 41
D 54
		if (CurEnv->e_queueup && curtime() > CurEnv->e_ctime + TimeOut)
E 41
E 37
E 14
			timeout(w);
E 54
I 54
		if (curtime() > CurEnv->e_ctime + TimeOut)
			CurEnv->e_flags |= EF_TIMEOUT;
E 54
E 2
D 7
		if (!QueueUp)
			(void) unlink(w->w_name);
E 7
I 7
D 15
		(void) unlink(w->w_name);
E 15
I 15
D 36

		/* get rid of the temporary file -- a new cf will be made */
I 23
		ControlFile = NULL;
E 23
		(void) unlink(buf);
E 36

E 65
		/* finish up and exit */
E 15
E 7
D 2
		else if (CurTime > TimeOut)
			timeout(w);
E 2
D 88
		finis();
E 88
I 88
		if (ForkQueueRuns)
			finis();
		else
			dropenvelope(CurEnv);
E 88
	}
I 88
	else
	{
		/*
		**  Parent -- pick up results.
		*/
E 88

D 88
	/*
	**  Parent -- pick up results.
	*/

	errno = 0;
D 56
	while ((i = wait(&xstat)) > 0 && errno != EINTR)
	{
		if (errno == EINTR)
		{
			errno = 0;
		}
	}
E 56
I 56
	(void) waitfor(i);
E 88
I 88
		errno = 0;
		(void) waitfor(i);
	}
E 88
E 56
}
/*
**  READQF -- read queue file and set up environment.
**
**	Parameters:
I 81
D 82
**		qfp -- the file pointer for the qf file.
E 82
E 81
D 56
**		cf -- name of queue control file.
E 56
I 56
**		e -- the envelope of the job to run.
I 61
**		full -- if set, read in all information.  Otherwise just
**			read in info needed for a queue print.
E 61
E 56
**
**	Returns:
**		none.
**
**	Side Effects:
**		cf is read and created as the current job, as though
**		we had been invoked by argument.
*/

D 56
readqf(cf)
	char *cf;
E 56
I 56
D 61
readqf(e)
E 61
I 61
D 81
readqf(e, full)
E 81
I 81
D 82
readqf(qfp, e, full)
	register FILE *qfp;
E 82
I 82
readqf(e, full)
E 82
E 81
E 61
	register ENVELOPE *e;
I 61
	bool full;
E 61
E 56
{
I 82
	char *qf;
	register FILE *qfp;
E 82
D 81
	register FILE *f;
E 81
D 35
	char buf[MAXLINE];
E 35
I 35
	char buf[MAXFIELD];
E 35
I 32
D 55
	register char *p;
	register int i;
E 55
I 55
	extern char *fgetfolded();
I 90
	extern long atol();
E 90
I 56
D 81
	register char *p;
E 81
E 56
E 55
E 32
I 5
	extern ADDRESS *sendto();
E 5

	/*
D 81
	**  Open the file created by queueup.
	*/

D 56
	f = fopen(cf, "r");
E 56
I 56
	p = queuename(e, 'q');
	f = fopen(p, "r");
E 56
	if (f == NULL)
	{
D 56
		syserr("readqf: no cf file %s", cf);
E 56
I 56
		syserr("readqf: no control file %s", p);
E 56
		return;
	}
I 56
	FileName = p;
	LineNumber = 0;
E 56

	/*
E 81
	**  Read and process the file.
	*/

I 82
	qf = queuename(e, 'q');
	qfp = fopen(qf, "r");
	if (qfp == NULL)
	{
		syserr("readqf: no control file %s", qf);
		return;
	}
	FileName = qf;
E 82
I 81
	LineNumber = 0;
E 81
I 7
D 21
	if (Verbose)
D 14
		message(Arpa_Info, "Running %s (from %s)", cf, From.q_paddr);
E 14
I 14
		message(Arpa_Info, "Running %s", cf);
E 14

E 21
I 21
D 24
	message(Arpa_Info, "Running %s", cf);
E 24
I 24
D 61
	if (Verbose)
E 61
I 61
	if (Verbose && full)
E 61
D 56
		printf("\nRunning %s\n", cf);
E 56
I 56
		printf("\nRunning %s\n", e->e_id);
E 56
E 24
E 21
E 7
D 32
	while (fgets(buf, sizeof buf, f) != NULL)
E 32
I 32
D 35
	p = buf;
	while (fgets(p, sizeof buf - (p - buf), f) != NULL)
E 35
I 35
D 81
	while (fgetfolded(buf, sizeof buf, f) != NULL)
E 81
I 81
	while (fgetfolded(buf, sizeof buf, qfp) != NULL)
E 81
E 35
E 32
	{
I 103
# ifdef DEBUG
		if (tTd(40, 4))
			printf("+++++ %s\n", buf);
# endif DEBUG
E 103
D 32
		fixcrlf(buf, TRUE);
E 32
I 32
D 35
		/*
		**  Collect any continuation lines...
		*/

		i = fgetc(f);
		if (i != EOF)
			ungetc(i, f);
		if (i == ' ' || i == '\t')
		{
			p += strlen(p);
			continue;
		}
		fixcrlf(p, TRUE);
E 32

E 35
		switch (buf[0])
		{
		  case 'R':		/* specify recipient */
D 5
D 6
			sendto(&buf[1], 1, (ADDRESS *) NULL);
E 6
I 6
D 14
			sendto(&buf[1], 1, (ADDRESS *) NULL, &SendQueue);
E 14
I 14
D 43
			sendto(&buf[1], 1, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 43
I 43
D 56
			sendto(&buf[1], (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 56
I 56
D 60
			sendto(&buf[1], (ADDRESS *) NULL, &e->e_sendqueue);
E 60
I 60
			sendtolist(&buf[1], (ADDRESS *) NULL, &e->e_sendqueue);
E 60
E 56
E 43
E 14
E 6
E 5
I 5
			(void) sendto(&buf[1], 1, (ADDRESS *) NULL, 0);
E 5
			break;

I 102
		  case 'E':		/* specify error recipient */
			sendtolist(&buf[1], (ADDRESS *) NULL, &e->e_errorqueue);
			break;

E 102
		  case 'H':		/* header */
D 61
			(void) chompheader(&buf[1], FALSE);
E 61
I 61
			if (full)
				(void) chompheader(&buf[1], FALSE);
E 61
			break;

I 67
		  case 'M':		/* message */
			e->e_message = newstr(&buf[1]);
			break;

E 67
		  case 'S':		/* sender */
I 14
D 15
			if (Verbose)
				message(Arpa_Info, "Sender: %s", &buf[1]);
E 15
E 14
D 2
			setsender(&buf[1]);
E 2
I 2
			setsender(newstr(&buf[1]));
E 2
			break;

		  case 'D':		/* data file name */
I 61
			if (!full)
				break;
E 61
D 16
			InFileName = newstr(&buf[1]);
			TempFile = fopen(InFileName, "r");
E 16
I 16
D 56
			CurEnv->e_df = newstr(&buf[1]);
			TempFile = fopen(CurEnv->e_df, "r");
E 56
I 56
			e->e_df = newstr(&buf[1]);
D 59
			TempFile = fopen(e->e_df, "r");
E 56
E 16
			if (TempFile == NULL)
E 59
I 59
			e->e_dfp = fopen(e->e_df, "r");
			if (e->e_dfp == NULL)
E 59
D 16
				syserr("readqf: cannot open %s", InFileName);
E 16
I 16
D 56
				syserr("readqf: cannot open %s", CurEnv->e_df);
E 56
I 56
				syserr("readqf: cannot open %s", e->e_df);
E 56
E 16
			break;

D 37
		  case 'T':		/* timeout */
			(void) sscanf(&buf[1], "%ld", &TimeOut);
E 37
I 37
		  case 'T':		/* init time */
D 56
			(void) sscanf(&buf[1], "%ld", &CurEnv->e_ctime);
E 56
I 56
D 88
			(void) sscanf(&buf[1], "%ld", &e->e_ctime);
E 88
I 88
			e->e_ctime = atol(&buf[1]);
E 88
E 56
E 37
			break;

I 2
		  case 'P':		/* message priority */
D 7
			MsgPriority = atoi(&buf[1]);
E 7
I 7
D 14
			(void) sscanf(&buf[1], "%ld", &MsgPriority);
E 14
I 14
D 56
			(void) sscanf(&buf[1], "%ld", &CurEnv->e_msgpriority);
E 56
I 56
D 88
			(void) sscanf(&buf[1], "%ld", &e->e_msgpriority);
E 88
I 88
D 95
			e->e_msgpriority = atol(&buf[1]);
E 88
E 56
E 14

			/* make sure that big things get sent eventually */
D 14
			MsgPriority -= WKTIMEFACT;
E 14
I 14
D 56
			CurEnv->e_msgpriority -= WKTIMEFACT;
E 56
I 56
			e->e_msgpriority -= WKTIMEFACT;
E 95
I 95
D 96
			e->e_msgpriority = atol(&buf[1]) - WkTimeFact;
E 96
I 96
			e->e_msgpriority = atol(&buf[1]) + WkTimeFact;
E 96
E 95
E 56
E 14
I 10
			break;

I 88
		  case '\0':		/* blank line; ignore */
			break;

E 88
I 15
D 56
		  case 'C':		/* message class */
			(void) sscanf(&buf[1], "%hd", &CurEnv->e_class);
			break;

E 56
E 15
D 67
		  case 'M':		/* define macro */
D 56
			define(buf[1], newstr(&buf[2]));
E 56
I 56
D 61
			define(buf[1], newstr(&buf[2]), e);
E 61
I 61
			if (full)
				define(buf[1], newstr(&buf[2]), e);
E 61
E 56
E 10
E 7
			break;

E 67
E 2
		  default:
D 56
			syserr("readqf(%s): bad line \"%s\"", cf, buf);
E 56
I 56
D 88
			syserr("readqf(%s): bad line \"%s\"", e->e_id, buf);
E 88
I 88
			syserr("readqf(%s:%d): bad line \"%s\"", e->e_id,
				LineNumber, buf);
E 88
E 56
			break;
		}
	}
I 56

I 88
D 90
	fclose(qfp);
E 90
I 90
	(void) fclose(qfp);
E 90
E 88
	FileName = NULL;
I 88

	/*
	**  If we haven't read any lines, this queue file is empty.
	**  Arrange to remove it without referencing any null pointers.
	*/

	if (LineNumber == 0)
	{
		errno = 0;
		e->e_flags |= EF_CLRQUEUE | EF_FATALERRS | EF_RESPONSE;
	}
E 88
E 56
D 65
}
/*
**  TIMEOUT -- process timeout on queue file.
**
**	Parameters:
D 54
**		w -- pointer to work request that timed out.
E 54
I 54
**		e -- the envelope that timed out.
E 54
**
**	Returns:
**		none.
**
**	Side Effects:
**		Returns a message to the sender saying that this
**		message has timed out.
*/

D 54
timeout(w)
	register WORK *w;
E 54
I 54
timeout(e)
	register ENVELOPE *e;
E 54
{
I 25
	char buf[MAXLINE];
D 37
	extern char *TextTimeOut;
E 37
I 37
	extern char *pintvl();
E 37

E 25
D 2
	printf("timeout(%s)\n", w->w_name);
E 2
I 2
# ifdef DEBUG
D 29
	if (Debug > 0)
E 29
I 29
	if (tTd(40, 3))
E 29
D 54
		printf("timeout(%s)\n", w->w_name);
E 54
I 54
		printf("timeout(%s)\n", e->e_id);
E 54
# endif DEBUG
I 54
	e->e_to = NULL;
E 54
I 16
	message(Arpa_Info, "Message has timed out");
E 16

	/* return message to sender */
D 15
	(void) returntosender("Cannot send mail for three days");
E 15
I 15
D 25
	(void) returntosender("Cannot send mail for three days",
			      &CurEnv->e_from, TRUE);
E 25
I 25
D 37
	(void) sprintf(buf, "Cannot send mail for %s", TextTimeOut);
E 37
I 37
	(void) sprintf(buf, "Cannot send mail for %s", pintvl(TimeOut, FALSE));
E 37
D 54
	(void) returntosender(buf, &CurEnv->e_from, TRUE);
E 54
I 54
	(void) returntosender(buf, &e->e_from, TRUE);
E 54
E 25
E 15

	/* arrange to remove files from queue */
D 14
	QueueUp = FALSE;
E 14
I 14
D 37
	CurEnv->e_queueup = FALSE;
E 37
I 37
D 54
	CurEnv->e_dontqueue = TRUE;
E 54
I 54
	e->e_flags |= EF_CLRQUEUE;
E 65
I 61
}
/*
**  PRINTQUEUE -- print out a representation of the mail queue
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Prints a listing of the mail queue on the standard output.
*/

printqueue()
{
	register WORK *w;
	FILE *f;
I 63
	int nrequests;
E 63
	char buf[MAXLINE];

	/*
	**  Read and order the queue.
	*/

D 63
	orderq();
E 63
I 63
D 88
	nrequests = orderq();
E 88
I 88
	nrequests = orderq(TRUE);
E 88
E 63

	/*
	**  Print the work list that we have read.
	*/

	/* first see if there is anything */
D 63
	if (WorkQ == NULL)
E 63
I 63
	if (nrequests <= 0)
E 63
	{
D 63
		printf("\nMail queue is empty\n");
E 63
I 63
		printf("Mail queue is empty\n");
E 63
		return;
	}

D 63
	printf("\n\t\tMail Queue\n");
	printf("--QID-- --Size-- -----Q Time----- --Sender/Recipient--\n");
E 63
I 63
D 66
	printf("\t\tMail Queue (%d requests", nrequests);
E 66
I 66
	printf("\t\tMail Queue (%d request%s", nrequests, nrequests == 1 ? "" : "s");
E 66
D 102
	if (nrequests > WLSIZE)
		printf(", only %d printed", WLSIZE);
E 102
I 102
	if (nrequests > QUEUESIZE)
		printf(", only %d printed", QUEUESIZE);
E 102
D 94
	printf(")\n--QID-- --Size-- -----Q-Time----- ------------Sender/Recipient------------\n");
E 94
I 94
	if (Verbose)
D 99
		printf(")\n--QID-- --Size-- -Priority- -----Q-Time----- --------Sender/Recipient--------\n");
E 99
I 99
		printf(")\n--QID-- --Size-- -Priority- ---Q-Time--- -----------Sender/Recipient-----------\n");
E 99
	else
		printf(")\n--QID-- --Size-- -----Q-Time----- ------------Sender/Recipient------------\n");
E 94
E 63
	for (w = WorkQ; w != NULL; w = w->w_next)
	{
		struct stat st;
I 63
D 67
		char lf[20];
E 67
		auto time_t submittime = 0;
		long dfsize = -1;
I 81
D 85
		int fd;
E 85
D 82
# ifndef FLOCK
E 82
E 81
I 67
		char lf[20];
I 81
D 82
# endif FLOCK
E 82
E 81
		char message[MAXLINE];
I 88
		extern bool shouldqueue();
E 88
E 67
E 63

I 81
		f = fopen(w->w_name, "r");
		if (f == NULL)
		{
			errno = 0;
			continue;
		}
E 81
		printf("%7s", w->w_name + 2);
I 81
D 82
# ifdef FLOCK
		fd = fileno(f);

		if (flock(fd, LOCK_EX|LOCK_NB) < 0)
		{
			printf("*");
		}
		else
		{
			flock(fd, LOCK_UN);
			printf(" ");
		}
# else FLOCK
E 82
E 81
I 63
D 86
		strcpy(lf, w->w_name);
E 86
I 86
		(void) strcpy(lf, w->w_name);
E 86
		lf[0] = 'l';
		if (stat(lf, &st) >= 0)
			printf("*");
I 88
		else if (shouldqueue(w->w_pri))
			printf("X");
E 88
		else
			printf(" ");
I 81
D 82
# endif FLOCK
E 82
E 81
		errno = 0;
E 63
D 81
		f = fopen(w->w_name, "r");
		if (f == NULL)
		{
			printf(" (finished)\n");
I 63
			errno = 0;
E 63
			continue;
		}
E 81
I 81

E 81
I 67
		message[0] = '\0';
E 67
D 63
		(void) fstat(fileno(f), &st);
		printf(" %8ld", st.st_size);
E 63
		while (fgets(buf, sizeof buf, f) != NULL)
		{
D 63
			auto long ti;

E 63
			fixcrlf(buf, TRUE);
			switch (buf[0])
			{
I 67
			  case 'M':	/* error message */
D 86
				strcpy(message, &buf[1]);
E 86
I 86
				(void) strcpy(message, &buf[1]);
E 86
				break;

E 67
			  case 'S':	/* sender name */
I 67
D 76
				if (message[0] != '\0')
				{
					(void) strcat(buf, " (");
					(void) strcat(buf, message);
					(void) strcat(buf, ")");
				}
E 67
D 63
				printf(" %.20s", &buf[1]);
E 63
I 63
				printf("%8d %.16s %.40s", dfsize,
E 76
I 76
D 77
				printf("%8d %.16s %.45s", dfsize,
E 77
I 77
D 94
				printf("%8ld %.16s %.45s", dfsize,
E 77
E 76
					ctime(&submittime), &buf[1]);
E 94
I 94
				if (Verbose)
D 98
					printf("%8ld %10ld %.16s %.37s", dfsize,
					    w->w_pri, ctime(&submittime),
E 98
I 98
					printf("%8ld %10ld %.12s %.38s", dfsize,
					    w->w_pri, ctime(&submittime) + 4,
E 98
					    &buf[1]);
				else
					printf("%8ld %.16s %.45s", dfsize,
					    ctime(&submittime), &buf[1]);
E 94
I 76
				if (message[0] != '\0')
D 88
					printf("\n\t\t\t\t  (%.43s)", message);
E 88
I 88
D 98
					printf("\n\t\t (%.62s)", message);
E 98
I 98
					printf("\n\t\t (%.60s)", message);
E 98
E 88
E 76
E 63
				break;

			  case 'R':	/* recipient name */
D 63
				printf("\n\t\t\t\t  %.20s", &buf[1]);
E 63
I 63
D 76
				printf("\n\t\t\t\t  %.40s", &buf[1]);
E 76
I 76
D 94
				printf("\n\t\t\t\t  %.45s", &buf[1]);
E 94
I 94
				if (Verbose)
D 98
					printf("\n\t\t\t\t\t     %.37s", &buf[1]);
E 98
I 98
					printf("\n\t\t\t\t\t %.38s", &buf[1]);
E 98
				else
					printf("\n\t\t\t\t  %.45s", &buf[1]);
E 94
E 76
E 63
				break;

			  case 'T':	/* creation time */
D 63
				sscanf(&buf[1], "%ld", &ti);
				printf(" %.16s", ctime(&ti));
E 63
I 63
D 86
				sscanf(&buf[1], "%ld", &submittime);
E 86
I 86
D 88
				(void) sscanf(&buf[1], "%ld", &submittime);
E 88
I 88
				submittime = atol(&buf[1]);
E 88
E 86
E 63
				break;
I 63

			  case 'D':	/* data file name */
				if (stat(&buf[1], &st) >= 0)
					dfsize = st.st_size;
				break;
E 63
			}
		}
I 63
		if (submittime == (time_t) 0)
			printf(" (no control file)");
E 63
		printf("\n");
D 86
		fclose(f);
E 86
I 86
		(void) fclose(f);
E 86
	}
E 61
E 54
E 37
E 14
E 2
}
I 8

# endif QUEUE
I 81
/*
**  QUEUENAME -- build a file name in the queue directory for this envelope.
**
**	Assigns an id code if one does not already exist.
**	This code is very careful to avoid trashing existing files
**	under any circumstances.
**		We first create an nf file that is only used when
**		assigning an id.  This file is always empty, so that
**		we can never accidently truncate an lf file.
**
**	Parameters:
**		e -- envelope to build it in/from.
**		type -- the file type, used as the first character
**			of the file name.
**
**	Returns:
**		a pointer to the new file name (in a static buffer).
**
**	Side Effects:
**		Will create the lf and qf files if no id code is
**		already assigned.  This will cause the envelope
**		to be modified.
*/

char *
queuename(e, type)
	register ENVELOPE *e;
	char type;
{
	static char buf[MAXNAME];
	static int pid = -1;
	char c1 = 'A';
	char c2 = 'A';

	if (e->e_id == NULL)
	{
		char qf[20];
		char nf[20];
D 82
# ifndef FLOCK
E 82
		char lf[20];
D 82
# endif FLOCK
E 82

		/* find a unique id */
		if (pid != getpid())
		{
			/* new process -- start back at "AA" */
			pid = getpid();
			c1 = 'A';
			c2 = 'A' - 1;
		}
		(void) sprintf(qf, "qfAA%05d", pid);
D 82
# ifndef FLOCK
E 82
D 86
		strcpy(lf, qf);
E 86
I 86
		(void) strcpy(lf, qf);
E 86
		lf[0] = 'l';
D 82
# endif FLOCK
E 82
D 86
		strcpy(nf, qf);
E 86
I 86
		(void) strcpy(nf, qf);
E 86
		nf[0] = 'n';

		while (c1 < '~' || c2 < 'Z')
		{
			int i;

			if (c2 >= 'Z')
			{
				c1++;
				c2 = 'A' - 1;
			}
D 82
			nf[2] = qf[2] = c1;
			nf[3] = qf[3] = ++c2;
# ifndef FLOCK
			lf[2] = c1;
			lf[3] = c2;
# endif FLOCK
E 82
I 82
			lf[2] = nf[2] = qf[2] = c1;
			lf[3] = nf[3] = qf[3] = ++c2;
E 82
# ifdef DEBUG
			if (tTd(7, 20))
				printf("queuename: trying \"%s\"\n", nf);
# endif DEBUG

D 82
# ifdef FLOCK
			i = open(nf, O_WRONLY|O_CREAT|O_EXCL, FileMode);
			if (i >= 0)
			{
				(void) flock(i, LOCK_EX|LOCK_NB);
				if (link(nf, qf) < 0)
				{
					(void) close(i);
					(void) unlink(nf);
					continue;
				}
				e->e_qfp = fdopen(i, "w");
				(void) unlink(nf);
				break;
			}
# else FLOCK
E 82
# ifdef QUEUE
			if (access(lf, 0) >= 0 || access(qf, 0) >= 0)
				continue;
			errno = 0;
			i = creat(nf, FileMode);
			if (i < 0)
			{
				(void) unlink(nf);	/* kernel bug */
				continue;
			}
			(void) close(i);
			i = link(nf, lf);
			(void) unlink(nf);
			if (i < 0)
				continue;
			if (link(lf, qf) >= 0)
				break;
			(void) unlink(lf);
# else QUEUE
D 83
			if (close(creat(qf, FileMode)) < 0)
				continue;
E 83
I 83
			if (close(creat(qf, FileMode)) >= 0)
				break;
E 83
# endif QUEUE
D 82
# endif FLOCK
E 82
		}
		if (c1 >= '~' && c2 >= 'Z')
		{
			syserr("queuename: Cannot create \"%s\" in \"%s\"",
				qf, QueueDir);
			exit(EX_OSERR);
		}
		e->e_id = newstr(&qf[2]);
		define('i', e->e_id, e);
# ifdef DEBUG
		if (tTd(7, 1))
			printf("queuename: assigned id %s, env=%x\n", e->e_id, e);
# ifdef LOG
		if (LogLevel > 16)
			syslog(LOG_DEBUG, "%s: assigned id", e->e_id);
# endif LOG
# endif DEBUG
	}

	if (type == '\0')
		return (NULL);
	(void) sprintf(buf, "%cf%s", type, e->e_id);
# ifdef DEBUG
	if (tTd(7, 2))
		printf("queuename: %s\n", buf);
# endif DEBUG
	return (buf);
}
/*
**  UNLOCKQUEUE -- unlock the queue entry for a specified envelope
**
**	Parameters:
**		e -- the envelope to unlock.
**
**	Returns:
**		none
**
**	Side Effects:
**		unlocks the queue for `e'.
*/

unlockqueue(e)
	ENVELOPE *e;
{
	/* remove the transcript */
#ifdef DEBUG
# ifdef LOG
	if (LogLevel > 19)
		syslog(LOG_DEBUG, "%s: unlock", e->e_id);
# endif LOG
	if (!tTd(51, 4))
#endif DEBUG
		xunlink(queuename(e, 'x'));

# ifdef QUEUE
D 82
# ifndef FLOCK
E 82
	/* last but not least, remove the lock */
	xunlink(queuename(e, 'l'));
D 82
# endif FLOCK
E 82
# endif QUEUE
}
E 81
E 8
E 1
