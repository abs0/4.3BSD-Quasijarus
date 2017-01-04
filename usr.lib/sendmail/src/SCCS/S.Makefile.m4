h01818
s 00004/00004/00133
d D 5.11 86/07/21 13:41:00 bloom 100 98
c add new file for MX support, fix install
e
s 00004/00004/00133
d R 5.11 86/07/21 10:26:23 bloom 99 98
c add new file for MX support and fix install of group
e
s 00001/00000/00136
d D 5.10 86/05/02 16:28:11 bloom 98 97
c statistics structure moved to its own header file so it may be used by 
c aux/mailstats
e
s 00000/00000/00136
d D 5.9 85/10/24 14:23:26 miriam 97 96
x 96
m 
c Don't want to use /sys/vax/inline/inline because of the kernel versus 
c user longjmp (ie kernel has only 1 arg while user has 2 args).
e
s 00004/00001/00135
d D 5.8 85/10/13 15:01:53 eric 96 95
m 
c use system inline expander
e
s 00005/00003/00131
d D 5.7 85/10/10 09:30:23 miriam 95 94
m 
c Put in -o root for install and ifdef SCCS specific stuff.
e
s 00001/00001/00133
d D 5.6 85/09/03 19:55:29 eric 94 93
m 
c "what" is no longer in /usr/local
e
s 00001/00000/00133
d D 5.5 85/08/15 12:01:34 miriam 93 92
m 
c Install sendmail in kmem group so load averaging check will work.
e
s 00002/00002/00131
d D 5.4 85/07/25 11:30:23 miriam 92 91
m 
c Use the bcopy in the library to prevent building a corrupt alias database.
e
s 00001/00000/00132
d D 5.3 85/06/16 16:20:39 eric 91 90
m 
c truncate sendmail.fc file after make install
e
s 00001/00001/00131
d D 5.2 85/06/16 16:18:24 eric 90 88
m 
c install -m 4755
e
s 00001/00001/00131
d R 5.2 85/06/16 16:05:44 eric 89 88
m 
c setuid install
e
s 00011/00002/00121
d D 5.1 85/06/07 16:17:47 dist 88 87
m 
c Add copyright
e
s 00001/00001/00122
d D 4.4 85/06/01 11:22:01 eric 87 86
m 
c handle existence or lack of SCCS directory automatically
e
s 00001/00001/00122
d D 4.3 85/04/25 20:01:40 miriam 86 85
m 
c Remove lib/libsys.a reference.
e
s 00002/00002/00121
d D 4.2 84/08/11 16:19:15 eric 85 84
m 
c bmove.c => bcopy.c
e
s 00000/00000/00123
d D 4.1 83/07/25 19:42:59 eric 84 83
m 
c 4.2 release version
e
s 00002/00002/00121
d D 3.67 82/12/24 08:14:17 eric 83 82
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00002/00002/00121
d D 3.66 82/12/13 18:24:39 eric 82 81
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00002/00002/00121
d D 3.65 82/12/05 13:45:45 eric 81 80
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00001/00001/00122
d D 3.64 82/11/28 00:20:38 eric 80 79
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00006/00007/00117
d D 3.63 82/11/21 15:35:28 eric 79 78
m 085
c First part of 4.1c conversion
e
s 00001/00001/00123
d D 3.62 82/11/13 18:45:08 eric 78 77
m 070
c put OS info back into the Makefile; sendmail discretionary info goes into
c conf.h.
e
s 00002/00001/00122
d D 3.61 82/11/13 18:16:37 eric 77 76
m 070
c remember to require conf.h
e
s 00001/00027/00122
d D 3.60 82/11/13 17:57:47 eric 76 75
m 070
c clean up configuration structure (partial)
e
s 00002/00002/00147
d D 3.59 82/10/13 18:40:20 eric 75 74
m 017
c revise directory structure (useful.h => include)
e
s 00015/00045/00134
d D 3.58 82/10/13 08:07:10 eric 74 73
m 017
c revise directory structure
e
s 00004/00053/00175
d D 3.57 82/08/23 21:52:08 eric 73 72
c put all non-sendmail stuff into the AUX directory; reduce what
c "make print" prints to get it through the line printer.
e
s 00001/00001/00227
d D 3.56 82/08/23 20:02:01 eric 72 71
c print TraceFlags also
e
s 00001/00001/00227
d D 3.55 82/08/23 19:57:17 eric 71 70
c know about config subdirectory in print entry
e
s 00002/00002/00226
d D 3.54 82/08/08 00:53:14 eric 70 69
c add trace.c
e
s 00001/00001/00227
d D 3.53 82/07/14 09:30:48 eric 69 68
c print *.m4
e
s 00002/00002/00226
d D 3.52 82/07/05 12:22:08 eric 68 67
c split off clock stuff from util.c so that vacation will compile
e
s 00003/00003/00225
d D 3.51 82/06/26 13:53:42 eric 67 66
c more debug information; fix dependencies in makefile
e
s 00003/00009/00225
d D 3.50 82/06/17 10:42:39 eric 66 65
c move junk into AUX directory
e
s 00018/00004/00216
d D 3.49 82/06/07 23:54:26 eric 65 64
c add an asm.sed script and mconnect
e
s 00003/00001/00217
d D 3.48 82/03/22 22:04:09 eric 64 63
c add -DVMUNIX
e
s 00002/00001/00216
d D 3.47 82/02/26 21:56:45 eric 63 62
c implement daemon mode
e
s 00005/00010/00212
d D 3.46 82/01/10 22:10:38 eric 62 61
c add sl (sccsid list) entry
e
s 00001/00001/00221
d D 3.45 82/01/10 22:00:55 eric 61 60
c oops....  need a dependency on macros.m4 and whoami.m4
e
s 00039/00022/00183
d D 3.44 82/01/10 21:58:11 eric 60 59
c cleanup from cbosgd (Mark Horton) testing; some internals, mostly
c configuration.  This tries to make the configuration file (cf.m4) be
c much more general, but I fear it is doomed to failure -- it may be
c better to just tell people to roll their own.
e
s 00001/00001/00204
d D 3.43 81/12/06 12:38:12 eric 59 58
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00007/00003/00198
d D 3.42 81/12/05 12:09:49 eric 58 57
c finish configuring Kim.
e
s 00028/00023/00173
d D 3.41 81/12/05 11:53:28 eric 57 56
c put the SMTP and queueing code on compilation flags so that sendmail
c will fit on non-ID PDP-11's (ugh); put the ugly UUCP hack on a
c compilation flag also to emphasize that it sucks eggs; makefile
c cleanup.
e
s 00007/00008/00189
d D 3.40 81/11/11 20:23:51 eric 56 54
c integrate user SMTP into sendmail itself.  If there is no $u arg
c in the mailer argument list, SMTP is run.  This can be used directly
c over the Ethernet or to any clever mailer.  We still need to edit
c spooled control files to remove recipients that have been successfully
c sent during queue processing.
e
s 00001/00001/00196
d R 3.40 81/11/08 13:15:15 eric 55 54
c ignore exit status on the what command -- why is wnj so
c careless as to blow this sort of thing?
e
s 00005/00005/00192
d D 3.39 81/11/08 12:37:03 eric 54 53
c move m4 macros and configuration into other files; someday
c makefile should be makefile.m4 (but how can we make it easily? --
c perhaps a makemake shell script?)
e
s 00002/00001/00195
d D 3.38 81/11/07 21:59:11 eric 53 52
c know about rexec library for remote TCP exec
e
s 00005/00002/00191
d D 3.37 81/11/07 16:54:32 eric 52 51
c change sendmail.cf to m4 format (in cf.m4); makefile
c automatically makes sendmail.cf from cf.m4, using /usr/include/whoami
c to adjust the configuration
e
s 00004/00003/00189
d D 3.36 81/11/07 15:41:23 eric 51 50
c clean up to compile & work on ARPAVAX; move stat file to
c /usr/lib/sendmail.st; fix bug in syserr with error codes
e
s 00023/00016/00169
d D 3.35 81/10/31 22:25:31 eric 50 49
c include usersmtp
e
s 00002/00002/00183
d D 3.34 81/10/31 10:08:12 eric 49 48
c smtp.c ==> srvrsmtp.c
e
s 00006/00001/00179
d D 3.33 81/10/27 14:00:47 eric 48 47
c add "fullversion" entry to make sure Version.c is up to date.
c Don't want to do this in the Version.c: entry because then it will
c remake it on every debugging compilation.
e
s 00007/00006/00173
d D 3.32 81/10/26 14:22:03 eric 47 46
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00005/00004/00174
d D 3.31 81/10/22 09:26:44 eric 46 45
c include sendmail.hf
e
s 00002/00002/00176
d D 3.30 81/10/19 22:26:56 eric 45 44
c implement SMTP mode -- doesn't support source routing or the
c HELP command, and doesn't give the correct code on VRFY or forwarding.
c Maybe someday....
e
s 00002/00002/00176
d D 3.29 81/10/17 16:57:38 eric 44 43
c initial prep to put in Daemon mode
e
s 00008/00002/00170
d D 3.28 81/10/15 09:50:16 eric 43 40
c add stuff for "vacation" program
e
s 00001/00001/00160
d D 3.27.1.2 81/09/23 18:26:37 eric 42 41
c add conf.h to sources
e
s 00002/00013/00159
d D 3.27.1.1 81/09/23 18:22:54 eric 41 40
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00001/00001/00171
d D 3.27 81/09/20 11:01:21 eric 40 39
c print out version number on a make
e
s 00003/00003/00169
d D 3.26 81/09/12 15:47:27 eric 39 38
c change version processing to not use SCCS for every make
c (distribution considerations....)
e
s 00002/00002/00170
d D 3.25 81/09/07 15:10:23 eric 38 37
c include version number of makefile & sendmail.cf in Version.c
e
s 00023/00023/00149
d D 3.24 81/09/07 12:33:31 eric 37 36
c add auto-rebuild on alias database; fix some aliasing bugs;
c add statistics to rebuild; slight code restructuring; change
c version handling one last (?) time
e
s 00005/00004/00167
d D 3.23 81/09/06 19:48:21 eric 36 35
c cleanup, commenting, linting, etc.
e
s 00001/00000/00170
d D 3.22 81/09/06 15:53:15 eric 35 34
c even more cleanup to makefile for version entry
e
s 00015/00008/00155
d D 3.21 81/09/06 15:50:04 eric 34 33
c cleanup of version stuff
e
s 00018/00004/00145
d D 3.20 81/09/06 14:22:21 eric 33 32
c improve version: entry
e
s 00008/00002/00141
d D 3.19 81/09/06 11:52:47 eric 32 31
c add rmail
e
s 00021/00019/00122
d D 3.18 81/09/05 16:11:48 eric 31 30
c add mailstats; delete newaliases; note move from /etc to /usr/lib;
c general makefile cleanup
e
s 00003/00002/00138
d D 3.17 81/08/31 21:21:27 eric 30 29
c collect mail statistics; change minor configuration
e
s 00006/00000/00134
d D 3.16 81/08/24 18:07:56 eric 29 28
c add spell and nroff entries (for sendmail.doc)
e
s 00002/00002/00132
d D 3.15 81/08/22 15:13:44 eric 28 27
c add TODO to make print
e
s 00002/00002/00132
d D 3.14 81/08/20 14:36:04 eric 27 26
c split deliver.c and sendto.c
e
s 00002/00002/00132
d D 3.13 81/08/18 10:01:15 eric 26 25
c print makefile and sendmail.cf on make print
e
s 00008/00006/00126
d D 3.12 81/08/17 09:34:30 eric 25 24
c clean up xref and printing of source
e
s 00004/00003/00128
d D 3.11 81/08/09 16:39:47 eric 24 23
c arrange for newaliases to work
e
s 00007/00006/00124
d D 3.10 81/08/09 15:02:32 eric 23 22
c lint it
e
s 00002/00002/00128
d D 3.9 81/08/08 11:16:00 eric 22 21
c know about stab.c
e
s 00002/00002/00128
d D 3.8 81/04/20 14:53:21 eric 21 20
c drop -p and -g
e
s 00001/00000/00129
d D 3.7 81/03/28 14:19:09 eric 20 19
c know about readcf.c
e
s 00013/00013/00116
d D 3.6 81/03/20 09:45:46 eric 19 18
c change name (again); from postbox to sendmail
e
s 00001/00001/00128
d D 3.5 81/03/12 10:57:04 eric 18 17
c merge letters to the same host into one message
e
s 00006/00006/00123
d D 3.4 81/03/11 10:45:43 eric 17 16
c general cleanup, esp. macro processor
e
s 00001/00001/00128
d D 3.3 81/03/09 13:21:53 eric 16 15
c first step at rewriting rules, etc.
e
s 00015/00015/00114
d D 3.2 81/03/07 14:26:28 eric 15 14
c ----- delivermail ==> postbox -----
e
s 00001/00001/00128
d D 3.1 81/03/04 09:34:24 eric 14 13
c install fancy header stuff
e
s 00003/00002/00126
d D 2.3 81/02/28 11:50:36 eric 13 12
c install VAX mpx file logging
e
s 00007/00006/00121
d D 2.2 80/12/06 17:36:01 eric 12 11
c fix for local standards compatibility
e
s 00000/00000/00127
d D 2.1 80/11/05 11:00:39 eric 11 10
c release 2
e
s 00008/00008/00119
d D 1.10 80/10/28 23:51:09 eric 10 9
c aliasdbm => newaliases; showdbm => praliases
e
s 00001/00001/00126
d D 1.9 80/10/21 22:39:54 eric 9 8
c EX_UNAVAIL => EX_UNAVAILABLE
e
s 00027/00004/00100
d D 1.8 80/10/18 16:48:58 eric 8 7
c cleanup for dbm stuff: Error => Errors; move local host
c detection into parse; misc cleanup
e
s 00001/00001/00103
d D 1.7 80/10/17 14:10:52 mark 7 6
c added aliasdbm/showdbm to SRCS
e
s 00004/00004/00100
d D 1.6 80/10/17 14:08:23 mark 6 5
c renamed aldbm => aliasdbm, and alget => showdbm
e
s 00010/00007/00094
d D 1.5 80/10/17 13:42:11 mark 5 4
c uses dbm package for alias file to make it faster
e
s 00001/00002/00100
d D 1.4 80/10/11 19:07:12 eric 4 3
c remove CPUTYPE dependency
e
s 00003/00002/00099
d D 1.3 80/10/11 18:11:48 eric 3 2
c cleanup to simplify configuration & fix minor bugs
e
s 00024/00017/00077
d D 1.2 80/10/11 14:00:13 eric 2 1
c change the technique of handling versions (use SCCS instead!)
e
s 00094/00000/00000
d D 1.1 80/10/11 13:21:51 eric 1 0
e
u
U
f b 
t
T
I 1
#
I 88
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
#
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
#
E 88
D 5
#  INGRES 11/70 Version
E 5
I 5
D 58
#  VAX Version
E 58
I 58
D 60
#  SENDMAIL makefile.
E 60
I 60
#  SENDMAIL Makefile.
E 60
E 58
E 5
#
D 58
#	%W%	%G%
E 58
I 58
D 60
#	VAX Version
E 58
#
I 58
#	Version:
#		%W%	%Y%	%G%
#
E 60
E 58
I 8
D 41
D 57
#	Compilation Flags (in CFLAGS):
E 57
I 57
D 76
#	Compilation Flags (in CCONFIG):
E 57
#		-DDEBUG -- compile in debug stuff.  This is not enabled
#			unless the debug flag is given, so the only
#			advantage in not including this is that the
#			binaries will be smaller.
#		-DLOG -- include log information.  This is probably
#			only useful on systems that include the logger.
#		-DVFORK -- use 'vfork' instead of 'fork'.
#		-DDBM -- use the dbm package instead of scanning the
#			ALIASFILE sequentially.  LIBS must include
#			-ldbm for this to work.
I 57
#		-DSMTP -- compile in the SMTP code.
#		-DQUEUE -- compile in the queueing code.  If SMTP is
#			being used over a "real" network, then QUEUE
#			is really required for proper operation.
#		-DUGLYUUCP -- add "remote from ..." on From lines for
#			UUCP mailers.  To trigger this the mailer must
#			must end in "/uux" and the name of the mailer
#			must be "uucp".
#		-DNOTUNIX -- don't put in UNIX dependencies (i.e.,
#			on the From line) for sites running non-UNIX
#			mail systems.
I 63
#		-DDAEMON -- compile in the daemon code.
I 64
#		-DVMUNIX -- put in VMUNIX dependencies.  Mostly for
#			location of header files, etc.
E 64
E 63
E 57
#
E 76
I 60
D 88
#	Version:
#		%W%	%Y%	%G%
E 88
#
I 79
include(../md/config.m4)dnl
E 79
E 60
E 41
E 8
I 2

E 2
D 4
CPUTYPE=11
E 4
D 5
LIBS=	-lX -lS
E 5
I 5
D 12
LIBS=	/usr/new/lib/libdbm.a
E 5
I 2
TARG=	/etc
E 12
I 12
D 13
LIBS=	-ldbm
E 13
I 13
D 51
LIBS=	-ldbm -lsys
E 51
I 51
D 60
LIBS=	-ldbm
E 60
I 60
D 74
include(macros.m4)dnl
include(whoami.m4)dnl
E 74
I 74
D 79
include(config.m4)dnl
E 74

D 65
LIBS=	ifdef(`m4_DBMLIB', -ldbm)
E 65
I 65
D 74
LIBS=	ifdef(`m4_DBMLIB', -ldbm) ifdef(`m4_VAX', -ljobs)
E 65
E 60
I 53
REXEC=	rexec.a
E 74
I 74
LIBS=	ifdef(`m4_DBMLIB', -ldbm) ifdef(`m4_VAX', -ljobs) ../lib/libsys.a
E 79
I 79
D 86
LIBS=	../lib/libsys.a m4LIBS
E 86
I 86
LIBS=	m4LIBS
E 86
E 79
E 74
E 53
E 51
E 13
D 31
TARG=	$(DESTDIR)/etc
E 31
I 31
D 34
TARG=	$(DESTDIR)/usr/lib
E 34
I 34
DESTDIR=
E 34
E 31
E 12
E 2

I 2
D 3
OBJS1=	conf.o deliver.o main.o parse.o err.o alias.o savemail.o addr.o
E 3
I 3
D 15
OBJS1=	conf.o main.o maketemp.o parse.o alias.o deliver.o \
E 15
I 15
D 83
OBJS1=	conf.o main.o collect.o parse.o alias.o deliver.o \
E 83
I 83
OBJS1=	conf.o main.o collect.o parseaddr.o alias.o deliver.o \
E 83
E 15
D 16
	savemail.o addr.o err.o
E 16
I 16
D 17
	savemail.o addr.o err.o readcf.o
E 16
E 3
D 4
OBJS2=	matchhdr.o sysexits.o util.o bmove.${CPUTYPE}.o
E 4
I 4
D 14
OBJS2=	matchhdr.o sysexits.o util.o bmove.o
E 14
I 14
OBJS2=	sysexits.o util.o bmove.o arpadate.o
E 17
I 17
D 22
	savemail.o err.o readcf.o
E 22
I 22
D 24
	savemail.o err.o readcf.o stab.o
E 24
I 24
D 27
	savemail.o err.o readcf.o stab.o headers.o
E 27
I 27
D 30
	savemail.o err.o readcf.o stab.o headers.o sendto.o
E 30
I 30
D 82
	savemail.o err.o readcf.o stab.o headers.o sendto.o \
E 82
I 82
	savemail.o err.o readcf.o stab.o headers.o recipient.o \
E 82
D 44
	stats.o
E 44
I 44
D 45
	stats.o daemon.o
E 45
I 45
D 47
	stats.o daemon.o smtp.o
E 45
E 44
E 30
E 27
E 24
E 22
OBJS2=	sysexits.o util.o bmove.o arpadate.o macro.o
E 47
I 47
D 49
	stats.o daemon.o smtp.o queue.o
E 49
I 49
D 56
	stats.o daemon.o srvrsmtp.o queue.o
E 56
I 56
D 67
	stats.o daemon.o usersmtp.o srvrsmtp.o queue.o
E 56
E 49
D 51
OBJS2=	sysexits.o util.o bmove.o arpadate.o macro.o convtime.o
E 51
I 51
OBJS2=	sysexits.o util.o bmove.o arpadate.o macro.o convtime.o \
	syslog.o
E 67
I 67
	stats.o daemon.o usersmtp.o srvrsmtp.o queue.o \
D 68
	macro.o util.o
E 68
I 68
D 70
	macro.o util.o clock.o
E 70
I 70
D 81
	macro.o util.o clock.o trace.o
E 81
I 81
D 100
	macro.o util.o clock.o trace.o envelope.o
E 100
I 100
	macro.o util.o clock.o trace.o envelope.o domain.o
E 100
E 81
E 70
E 68
D 74
OBJS2=	sysexits.o bmove.o arpadate.o convtime.o syslog.o
E 74
I 74
D 85
OBJS2=	sysexits.o bmove.o arpadate.o convtime.o
E 85
I 85
D 92
OBJS2=	sysexits.o bcopy.o arpadate.o convtime.o
E 92
I 92
OBJS2=	sysexits.o arpadate.o convtime.o
E 92
E 85
E 74
E 67
E 51
E 47
I 33
OBJS=	$(OBJS1) $(OBJS2)
E 33
E 17
E 14
E 4
D 15
SRCS=	useful.h dlvrmail.h \
E 15
I 15
D 19
SRCS=	useful.h postbox.h \
E 19
I 19
D 23
SRCS=	useful.h sendmail.h \
E 23
I 23
D 42
D 75
SRCS1=	useful.h sendmail.h \
E 75
I 75
D 77
SRCS1=	sendmail.h \
E 77
I 77
SRCS1=	conf.h sendmail.h \
E 77
E 75
E 42
I 42
SRCS1=	useful.h sendmail.h conf.h \
E 42
E 23
E 19
E 15
D 17
	conf.c deliver.c main.c parse.c err.c alias.c savemail.c addr.c \
E 17
I 17
D 83
	conf.c deliver.c main.c parse.c err.c alias.c savemail.c \
E 83
I 83
	conf.c deliver.c main.c parseaddr.c err.c alias.c savemail.c \
E 83
E 17
D 23
	matchhdr.c sysexits.c util.c bmove.c bmove.11.s bmove.vax.s \
D 3
	arpa.c arpadate.c version.c
E 3
I 3
D 7
	arpa.c arpadate.c version.c maketemp.c
E 7
I 7
D 8
	arpa.c arpadate.c version.c maketemp.c aliasdbm.c showdbm.c
E 8
I 8
D 15
	arpa.c arpadate.c version.c maketemp.c \
E 15
I 15
D 17
	arpa.c arpadate.c version.c collect.c \
E 17
I 17
	arpa.c arpadate.c version.c collect.c macro.c \
I 20
D 22
	readcf.c \
E 22
I 22
	readcf.c stab.c\
E 22
E 20
E 17
E 15
D 10
	aliasdbm.c showdbm.c
ALL=	delivermail aliasdbm showdbm arpa
E 10
I 10
	newaliases.c praliases.c
E 23
I 23
D 56
	sysexits.c util.c bmove.c \
D 24
	arpadate.c version.c collect.c macro.c \
E 24
I 24
D 34
	arpadate.c version.c collect.c macro.c headers.c \
E 34
I 34
D 37
	arpadate.c version.t collect.c macro.c headers.c \
E 37
I 37
	arpadate.c version.c collect.c macro.c headers.c \
E 37
E 34
E 24
D 27
	readcf.c stab.c
E 27
I 27
D 30
	readcf.c stab.c sendto.c
E 30
I 30
D 44
	readcf.c stab.c sendto.c stats.c
E 44
I 44
D 45
	readcf.c stab.c sendto.c stats.c daemon.c
E 45
I 45
D 47
	readcf.c stab.c sendto.c stats.c daemon.c smtp.c
E 47
I 47
D 49
	readcf.c stab.c sendto.c stats.c daemon.c smtp.c queue.c
E 49
I 49
	readcf.c stab.c sendto.c stats.c daemon.c srvrsmtp.c queue.c
E 56
I 56
D 85
	sysexits.c util.c bmove.c arpadate.c version.c collect.c \
E 85
I 85
D 92
	sysexits.c util.c bcopy.c arpadate.c version.c collect.c \
E 92
I 92
	sysexits.c util.c arpadate.c version.c collect.c \
E 92
E 85
D 82
	macro.c headers.c readcf.c stab.c sendto.c stats.c daemon.c \
E 82
I 82
	macro.c headers.c readcf.c stab.c recipient.c stats.c daemon.c \
E 82
D 68
	usersmtp.c srvrsmtp.c queue.c
E 68
I 68
D 70
	usersmtp.c srvrsmtp.c queue.c clock.c
E 70
I 70
D 81
	usersmtp.c srvrsmtp.c queue.c clock.c trace.c
E 81
I 81
D 100
	usersmtp.c srvrsmtp.c queue.c clock.c trace.c envelope.c
E 100
I 100
	usersmtp.c srvrsmtp.c queue.c clock.c trace.c envelope.c domain.c
E 100
E 81
E 70
E 68
E 56
E 49
E 47
E 45
E 44
E 30
E 27
D 26
SRCS2=	arpa.c matchhdr.c newaliases.c praliases.c
E 26
I 26
D 28
SRCS2=	arpa.c matchhdr.c newaliases.c praliases.c sendmail.cf
E 28
I 28
D 31
SRCS2=	arpa.c matchhdr.c newaliases.c praliases.c sendmail.cf TODO
E 31
I 31
D 32
SRCS2=	arpa.c matchhdr.c mailstats.c praliases.c sendmail.cf TODO
E 32
I 32
D 66
SRCS2=	arpa.c matchhdr.c mailstats.c praliases.c rmail.c \
E 66
I 66
D 73
SRCS2=	matchhdr.c mailstats.c praliases.c rmail.c \
E 66
D 43
	sendmail.cf TODO
E 43
I 43
D 46
	sendmail.cf TODO vacation.c
E 46
I 46
D 47
	sendmail.cf TODO vacation.c sendmail.hf
E 47
I 47
D 50
	sendmail.cf TODO vacation.c sendmail.hf convtime.c
E 50
I 50
D 52
	sendmail.cf TODO vacation.c sendmail.hf convtime.c \
E 52
I 52
D 54
	cf.m4 TODO vacation.c sendmail.hf convtime.c \
E 52
	usersmtp.c
E 54
I 54
D 56
	usersmtp.c TODO vacation.c sendmail.hf convtime.c \
E 56
I 56
D 60
	TODO vacation.c sendmail.hf convtime.c \
E 56
	macros.m4 whoami.m4 cf.m4
E 60
I 60
	TODO vacation.c sendmail.hf convtime.c uname.c \
D 65
	macros.m4 whoami.m4 cf.m4 makefile.m4
E 65
I 65
	macros.m4 whoami.m4 cf.m4 makefile.m4 asm.sed mconnect.c
E 73
I 73
D 74
SRCS2=	TODO sendmail.hf convtime.c \
	macros.m4 whoami.m4 cf.m4 makefile.m4 asm.sed
E 74
I 74
SRCS2=	TODO convtime.c
E 74
E 73
E 65
E 60
E 54
E 50
E 47
E 46
E 43
E 32
E 31
E 28
E 26
D 34
SRCS=	$(SRCS1) $(SRCS2)
E 23
D 12
ALL=	delivermail newaliases praliases arpa
E 12
I 12
D 15
ALL=	delivermail newaliases arpa
E 15
I 15
D 19
ALL=	postbox newaliases arpa
E 19
I 19
D 31
ALL=	sendmail newaliases arpa
E 31
I 31
D 32
ALL=	sendmail arpa mailstats
E 32
I 32
ALL=	sendmail arpa mailstats rmail
E 34
I 34
D 37
SRCS=	$(SRCS1) $(SRCS2) version.c
E 37
I 37
SRCS=	Version.c $(SRCS1) $(SRCS2)
E 37
D 43
ALL=	sendmail arpa mailstats rmail sendmail.cf
E 43
I 43
D 46
ALL=	sendmail arpa mailstats rmail sendmail.cf vacation
E 46
I 46
D 54
ALL=	sendmail arpa mailstats rmail sendmail.cf vacation sendmail.hf
E 54
I 54
D 56
ALL=	sendmail arpa mailstats rmail sendmail.cf vacation sendmail.hf usersmtp
E 56
I 56
D 60
ALL=	sendmail arpa mailstats rmail sendmail.cf vacation sendmail.hf
E 60
I 60
D 66
ALL=	sendmail arpa mailstats rmail sendmail.cf vacation sendmail.hf uname
E 66
I 66
D 73
ALL=	sendmail mailstats rmail sendmail.cf vacation sendmail.hf uname
E 73
I 73
D 74
ALL=	sendmail sendmail.hf
E 74
I 74
ALL=	sendmail
E 74
E 73
E 66
E 60
E 56
E 54
E 46
E 43
E 34
E 32
E 31
E 19
E 15
E 12
E 10
E 8
E 7
E 3

E 2
CHOWN=	-echo chown
CHMOD=	chmod
D 5
CFLAGS=	-O -DDEBUG -DLOG
LDFLAGS=-n
E 5
I 5
D 9
CFLAGS=	-O -I. -DDBM -DVFORK -DDEBUG
E 9
I 9
D 13
CFLAGS=	-O -DDBM -DVFORK -DDEBUG
E 13
I 13
D 57
OPT=	-O
D 17
CFLAGS=	$(OPT) -DDBM -DVFORK -DDEBUG -DLOG
E 13
E 9
LDFLAGS=
E 17
I 17
D 21
CFLAGS=	$(OPT) -DDBM -DVFORK -DDEBUG -DLOG -g -p
D 18
LDFLAGS=-p
E 18
I 18
LDFLAGS=-p -g
E 21
I 21
D 36
CFLAGS=	$(OPT) -DDBM -DVFORK -DDEBUG -DLOG $(PFLAG) $(GFLAG)
E 36
I 36
D 41
COPTS=	-DDBM -DVFORK -DDEBUG -DLOG
E 41
I 41
COPTS=	
E 41
D 51
CFLAGS=	$(OPT) $(COPTS) $(PFLAG) $(GFLAG)
E 51
I 51
CFLAGS=	$(OPT) $(COPTS) $(PFLAG) $(GFLAG) -I.
E 51
E 36
LDFLAGS=$(PFLAG) $(GFLAG)
E 57
I 57
O=	-O
COPTS=
D 60
CCONFIG=-I. -DDBM -DVFORK -DDEBUG -DLOG -DSMTP -DQUEUE -DUGLYUUCP
E 60
I 60
D 63
CCONFIG=-I. ifdef(`m4_DBMLIB', -DDBM) ifdef(`m4_VFORK', -DVFORK) -DDEBUG -DLOG -DSMTP -DQUEUE -DUGLYUUCP
E 63
I 63
D 64
CCONFIG=-I. ifdef(`m4_DBMLIB', -DDBM) ifdef(`m4_VFORK', -DVFORK) -DDEBUG -DLOG -DSMTP -DQUEUE -DUGLYUUCP ifdef(`m4_VAX', -DDAEMON)
E 64
I 64
D 74
CCONFIG=-I. ifdef(`m4_DBMLIB', -DDBM) ifdef(`m4_VFORK', -DVFORK) -DDEBUG -DLOG -DSMTP -DQUEUE -DUGLYUUCP ifdef(`m4_VAX', -DDAEMON -DVMUNIX)
E 74
I 74
D 76
CCONFIG=-I../`include' ifdef(`m4_DBMLIB', -DDBM) -DDEBUG -DLOG -DSMTP -DQUEUE -DUGLYUUCP ifdef(`m4_VAX', -DDAEMON -DVMUNIX -DVFORK)
E 76
I 76
D 78
CCONFIG=-I../`include'
E 78
I 78
D 79
CCONFIG=-I../`include' ifdef(`m4_VAX', -DVMUNIX) ifdef(`m4_NVMUNIX', -DNVMUNIX) ifdef(`m4_V6', -DV6)
E 79
I 79
CCONFIG=-I../`include' m4CONFIG
E 79
E 78
E 76
E 74
E 64
E 63
E 60
CFLAGS=	$O $(COPTS) $(CCONFIG)
I 74
ASMSED=	../`include'/asm.sed
E 74
E 57
E 21
E 18
E 17
E 5
AR=	-ar
ARFLAGS=rvu
LINT=	lint
D 57
LINTFLAGS=-bxa
E 57
D 25
XREF=	csh /usr/bin/xref
E 25
I 25
XREF=	ctags -x
E 25
D 2
MAKEVERSION=csh -f makeversion
VER=	0.0
E 2
I 2
CP=	cp
I 62
MV=	mv
E 62
I 34
D 95
INSTALL=install -c -s
E 95
I 95
INSTALL=install -c -s -o root
E 95
I 58
M4=	m4
I 60
TOUCH=	touch
ABORT=	false
E 60
E 58
E 34
E 2

GET=	sccs get
I 2
DELTA=	sccs delta
I 33
D 94
WHAT=	sccs what
E 94
I 94
WHAT=	what
E 94
PRT=	sccs prt
E 33
E 2
REL=

D 2
OBJS1=	conf.o deliver.o main.o parse.o err.o alias.o savemail.o addr.o
OBJS2=	matchhdr.o sysexits.o util.o bmove.${CPUTYPE}.o
SRCS=	useful.h dlvrmail.h \
	conf.c deliver.c main.c parse.c err.c alias.c savemail.c addr.c \
	matchhdr.c sysexits.c util.c bmove.c bmove.11.s bmove.vax.s \
	arpa.c arpadate.c

E 2
ROOT=	root
I 100
GROUP=	kmem
E 100
OBJMODE=755

I 96
INLINE=	/sys/vax/inline/inline
#INLINE=	sed -f $(ASMSED)

E 96
D 2
delivermail: $(OBJS1) $(OBJS2)
	$(MAKEVERSION) Delivermail $(VER) $(CC)
E 2
I 2
D 15
delivermail: $(OBJS1) $(OBJS2) version.o
E 2
	$(CC) $(LDFLAGS) -o delivermail version.o $(OBJS1) $(OBJS2) $(LIBS)
	$(CHMOD) $(OBJMODE) delivermail
	size delivermail; ls -l delivermail
E 15
I 15
D 19
postbox: $(OBJS1) $(OBJS2) version.o
	$(CC) $(LDFLAGS) -o postbox version.o $(OBJS1) $(OBJS2) $(LIBS)
	$(CHMOD) $(OBJMODE) postbox
	size postbox; ls -l postbox
E 19
I 19
D 37
sendmail: $(OBJS1) $(OBJS2) version.o
	$(CC) $(LDFLAGS) -o sendmail version.o $(OBJS1) $(OBJS2) $(LIBS)
E 37
I 37
D 39
sendmail: Version.o $(OBJS1) $(OBJS2)
E 39
I 39
D 65
sendmail: $(OBJS1) $(OBJS2) Version.o
E 65
I 65
.c.o:
	cc -S ${CFLAGS} $*.c
D 74
	sed -f asm.sed $*.s | as -o $*.o
E 74
I 74
D 96
	sed -f $(ASMSED) $*.s | as -o $*.o
E 96
I 96
	$(INLINE) $*.s | as -o $*.o
E 96
E 74
	rm -f $*.s

D 74
sendmail: asm.sed $(OBJS1) $(OBJS2) Version.o
E 74
I 74
sendmail: $(OBJS1) $(OBJS2) Version.o
E 74
E 65
E 39
D 57
	$(CC) $(LDFLAGS) -o sendmail Version.o $(OBJS1) $(OBJS2) $(LIBS)
E 57
I 57
	$(CC) $(COPTS) -o sendmail Version.o $(OBJS1) $(OBJS2) $(LIBS)
E 57
E 37
	$(CHMOD) $(OBJMODE) sendmail
D 40
	size sendmail; ls -l sendmail
E 40
I 40
D 60
	size sendmail; ls -l sendmail; what < Version.o
E 60
I 60
D 79
	size sendmail; ls -l sendmail; ifdef(`m4_SCCS', `$(WHAT) < Version.o')
E 79
I 79
	size sendmail; ls -l sendmail; ifdef(`m4SCCS', `$(WHAT) < Version.o')
E 79
E 60
E 40
E 19
E 15

I 52
D 54
sendmail.cf: cf.m4
	m4 cf.m4 > sendmail.cf
E 54
I 54
D 74
sendmail.cf: macros.m4 whoami.m4 cf.m4
D 58
	m4 $(M4CONF) macros.m4 whoami.m4 cf.m4 > sendmail.cf
E 58
I 58
	$(M4) $(M4CONF) cf.m4 > sendmail.cf
E 58
E 54

E 74
E 52
I 2
D 12
install: $(OBJS1) $(OBJS2) install1 delivermail
E 12
I 12
install: all
E 12
D 15
	$(CP) delivermail $(TARG)/delivermail
E 15
I 15
D 19
	$(CP) postbox $(TARG)/postbox
E 19
I 19
D 34
	$(CP) sendmail $(TARG)/sendmail
E 19
E 15
I 12
D 31
	install -s newaliases $(DESTDIR)/usr/ucb
E 31
I 31
	install -s arpa $(DESTDIR)/usr/lib/mailers
E 34
I 34
D 74
	$(CP) sendmail.cf $(DESTDIR)/usr/lib/sendmail.cf
I 46
	$(CP) sendmail.hf $(DESTDIR)/usr/lib/sendmail.hf
E 74
E 46
D 90
	$(INSTALL) sendmail $(DESTDIR)/usr/lib
E 90
I 90
D 100
	$(INSTALL) -m 4755 sendmail $(DESTDIR)/usr/lib
I 93
	chgrp kmem $(DESTDIR)/usr/lib/sendmail
E 100
I 100
	$(INSTALL) -m 6755 -g $(GROUP) sendmail $(DESTDIR)/usr/lib
E 100
E 93
I 91
	$(CP) /dev/null $(DESTDIR)/usr/lib/sendmail.fc
E 91
E 90
D 66
	$(INSTALL) arpa $(DESTDIR)/usr/lib/mailers
E 66
D 73
	$(INSTALL) rmail $(DESTDIR)/bin
E 73
I 50
D 56
	$(INSTALL) usersmtp $(DESTDIR)/usr/lib/mailers
E 56
E 50
E 34
E 31
E 12

D 12
install1:
E 12
I 12
D 34
version:
E 34
I 34
D 37
version: newversion version.c
E 37
I 37
D 39
version: newversion Version.c
E 39
I 39
D 46
version: newversion makefile sendmail.cf $(OBJS) Version.c
E 46
I 46
D 74
version: newversion makefile sendmail.cf sendmail.hf $(OBJS) Version.c
E 74
I 74
version: newversion $(OBJS) Version.c
E 74
E 46
E 39
E 37

newversion:
E 34
E 12
D 33
	@rm -f SCCS/p.version.c version.c
	@$(GET) $(REL) -e -s SCCS/s.version.c
	@$(DELTA) -s SCCS/s.version.c
	@$(GET) -t SCCS/s.version.c
E 33
I 33
D 37
	@rm -f SCCS/p.version.t version.t
	@$(GET) $(REL) -e SCCS/s.version.t
	@$(DELTA) -s SCCS/s.version.t
	@$(GET) -t -s SCCS/s.version.t
E 37
I 37
	@rm -f SCCS/p.version.c version.c
	@$(GET) $(REL) -e SCCS/s.version.c
	@$(DELTA) -s SCCS/s.version.c
	@$(GET) -t -s SCCS/s.version.c
E 37
I 34

I 48
D 74
fullversion: makefile sendmail.cf sendmail.hf $(OBJS) dumpVersion Version.o
E 74
I 74
fullversion: $(OBJS) dumpVersion Version.o
E 74

dumpVersion:
	rm -f Version.c

I 60
D 79
ifdef(`m4_SCCS',
E 79
I 79
ifdef(`m4SCCS',
E 79
E 60
E 48
D 37
version.c: version.t
I 35
	@echo generating version.c from version.t
E 35
E 34
	@cp version.t version.c
	@chmod 644 version.c
	@echo '' >> version.c
	@echo '# ifdef COMMENT' >> version.c
	@$(PRT) SCCS/s.version.t >> version.c
	@echo '' >> version.c
	@echo 'code versions:' >> version.c
	@echo '' >> version.c
	@$(WHAT) $(OBJS) >> version.c
	@echo '' >> version.c
	@echo '# endif COMMENT' >> version.c
E 37
I 37
D 38
Version.c: version.c
E 38
I 38
D 39
Version.c: version.c makefile sendmail.cf $(OBJS)
E 39
I 39
Version.c: version.c
E 39
E 38
	@echo generating Version.c from version.c
	@cp version.c Version.c
	@chmod 644 Version.c
D 60
	@echo '' >> Version.c
	@echo '# ifdef COMMENT' >> Version.c
E 60
I 60
	@echo "" >> Version.c
	@echo "`# ifdef' COMMENT" >> Version.c
E 60
	@$(PRT) SCCS/s.version.c >> Version.c
D 60
	@echo '' >> Version.c
	@echo 'code versions:' >> Version.c
	@echo '' >> Version.c
E 60
I 60
	@echo "" >> Version.c
	@echo "code versions:" >> Version.c
	@echo "" >> Version.c
E 60
D 38
	@$(WHAT) $(OBJS) >> Version.c
E 38
I 38
D 46
	@$(WHAT) makefile sendmail.cf $(OBJS) >> Version.c
E 46
I 46
D 74
	@$(WHAT) makefile sendmail.cf sendmail.hf $(OBJS) >> Version.c
E 74
I 74
	@$(WHAT) $(OBJS) >> Version.c
E 74
E 46
E 38
D 60
	@echo '' >> Version.c
	@echo '# endif COMMENT' >> Version.c
E 60
I 60
	@echo "" >> Version.c
	@echo "`#' endif COMMENT" >> Version.c
)dnl
E 60
E 37
E 33

E 2
D 5
main.o: main.c
	$(CC) $(CFLAGS) -DDEBUGFILE=\"/mnt/eric/DEBUG.DLVRML\" -c $<

E 5
D 15
$(OBJS1): dlvrmail.h
E 15
I 15
D 19
$(OBJS1): postbox.h
E 19
I 19
$(OBJS1): sendmail.h
I 77
$(OBJS): conf.h
I 98
stats.o: mailstats.h
E 98
E 77
E 19
E 15

D 15
dlvrmail.h util.o: useful.h
E 15
I 15
D 19
postbox.h util.o: useful.h
E 19
I 19
D 75
sendmail.h util.o: useful.h
E 75
I 75
sendmail.h util.o: ../`include'/useful.h
E 75
I 41
arpa.o arpadate.o macro.o rmail.o util.o: conf.h
E 41
E 19
E 15

I 8
D 60
all: $(ALL)
E 60
I 60
D 65
all: makefile $(ALL)
E 65
I 65
D 74
all: makefile asm.sed $(ALL)
E 74
I 74
all: $(ALL)
E 74
E 65
E 60

E 8
#
I 60
D 74
#  Makefile bootstrap
#

D 61
makefile: makefile.m4
E 61
I 61
makefile: makefile.m4 macros.m4 whoami.m4
I 62
	$(MV) makefile makefile.bak
E 62
E 61
	$(M4) $(M4CONF) makefile.m4 > makefile
	@echo "WARNING: makefile has been regenerated, rerun make"
	$(ABORT)

#
E 74
E 60
D 31
#  Auxiliary stuff
E 31
I 31
D 73
#  Auxiliary programs
E 31
#

I 31
mailstats: mailstats.o
D 57
	$(CC) $(LDFLAGS) mailstats.o -o mailstats
E 57
I 57
	$(CC) $(COPTS) mailstats.o -o mailstats
E 57

I 60
uname: uname.o
	$(CC) $(COPTS) uname.o -o uname

E 60
D 36
praliases: praliases.c
	$(CC) $(CFLAGS) praliases.c -o praliases $(LIBS)
E 36
I 36
praliases: praliases.o
D 57
	$(CC) $(LDFLAGS) praliases.o -o praliases -ldbm
E 57
I 57
	$(CC) $(COPTS) praliases.o -o praliases -ldbm
E 57
E 36

praliases.o: sendmail.h

#
E 73
#  Auxiliary support entries
#

E 31
clean:
D 12
	rm -f core delivermail arpa uucp a.out xref version.c
E 12
I 12
D 15
	rm -f core delivermail arpa uucp a.out xref
E 15
I 15
D 19
	rm -f core postbox arpa uucp a.out xref
E 19
I 19
D 25
	rm -f core sendmail arpa uucp a.out xref
E 25
I 25
D 50
	rm -f core sendmail arpa uucp a.out XREF
E 50
I 50
D 52
	rm -f core sendmail arpa rmail usersmtp uucp a.out XREF
E 52
I 52
D 66
	rm -f core sendmail arpa rmail usersmtp uucp a.out XREF sendmail.cf vacation
E 66
I 66
D 74
	rm -f core sendmail rmail usersmtp uucp a.out XREF sendmail.cf vacation
E 74
I 74
	rm -f core sendmail rmail usersmtp uucp a.out XREF sendmail.cf
E 74
E 66
E 52
E 50
E 25
E 19
E 15
E 12
	rm -f *.o

sources: $(SRCS)

D 34
$(SRCS):
E 34
I 34
D 95
$(SRCS1) $(SRCS2):
E 34
D 60
	$(GET) $(REL) SCCS/s.$@
E 60
I 60
D 79
	ifdef(`m4_SCCS', `$(GET) $(REL) SCCS/s.$@', `$(TOUCH) $@')
E 79
I 79
D 87
	ifdef(`m4SCCS', `$(GET) $(REL) SCCS/s.$@', `$(TOUCH) $@')
E 87
I 87
	if test -d SCCS; then $(GET) $(REL) SCCS/s.$@; else $(TOUCH) $@; fi
E 95
I 95
ifdef(`m4SCCS',
`$(SRCS1) $(SRCS2):
	if test -d SCCS; then $(GET) $(REL) SCCS/s.$@; else $(TOUCH) $@; fi'
)dnl
E 95
E 87
E 79
E 60

D 73
archive:
D 15
	${AR} ${ARFLAGS} delivermail.a READ_ME TO_BE_DONE makefile makefl.* *.h *.c *.s makeversion *.[123456789u]
E 15
I 15
D 19
	${AR} ${ARFLAGS} postbox.a READ_ME TO_BE_DONE makefile makefl.* *.h *.c *.s makeversion *.[123456789u]
E 19
I 19
D 37
	${AR} ${ARFLAGS} sendmail.a READ_ME TO_BE_DONE makefile makefl.* *.h *.c *.s makeversion *.[123456789u]
E 37
I 37
	${AR} ${ARFLAGS} sendmail.a READ_ME TODO makefile makefl.* *.h *.c *.s *.[123456789u]
E 37
E 19
E 15

E 73
D 25
print: xref
E 25
I 25
D 48
print: $(SRCS) XREF
E 48
I 48
D 57
print: $(SRCS) all XREF
E 57
I 57
print: $(SRCS)
E 57
E 48
E 25
D 15
	@ls -l | pr -h "delivermail directory"
E 15
I 15
D 19
	@ls -l | pr -h "postbox directory"
E 19
I 19
	@ls -l | pr -h "sendmail directory"
E 19
E 15
D 25
	@pr -h "cross reference listing" xref
E 25
I 25
D 57
	@pr -h "cross reference listing" XREF
E 57
I 57
	@$(XREF) *.c | pr -h "cross reference listing"
E 57
E 25
	@size *.o | pr -h "object code sizes"
D 26
	@pr *.h *.[cs]
E 26
I 26
D 28
	@pr makefile sendmail.cf *.h *.[cs]
E 28
I 28
D 69
	@pr makefile TODO sendmail.cf *.h *.[cs]
E 69
I 69
D 71
	@pr makefile TODO sendmail.cf *.m4 *.h *.[cs]
E 71
I 71
D 72
	@pr makefile TODO config/*.m4 config/cf/* sendmail.cf *.m4 *.h *.[cs]
E 72
I 72
D 73
	@pr makefile TODO TraceFlags config/*.m4 config/cf/* sendmail.cf *.m4 *.h *.[cs]
E 73
I 73
D 74
	@pr makefile TODO TraceFlags config/*.m4 config/cf/arpa *.m4 *.h *.[cs]
E 74
I 74
D 80
	@pr Makefile TODO TraceFlags ../cf/*.m4 *.m4 *.h *.[cs]
E 80
I 80
	@pr Makefile *.m4 *.h *.[cs]
E 80
E 74
E 73
E 72
E 71
E 69
E 28
E 26

lint:
D 23
	$(LINT) $(LINTFLAGS) $(SRCS)
E 23
I 23
D 36
	$(LINT) $(LINTFLAGS) $(CFLAGS) $(SRCS1)
E 36
I 36
D 57
	$(LINT) $(LINTFLAGS) $(COPTS) $(SRCS1) | egrep -v 'SccsId|\?\?\?'
E 57
I 57
D 59
	$(LINT) $(CCONFIG) $(SRCS1) | egrep -v 'SccsId|\?\?\?'
E 59
I 59
	$(LINT) $(CCONFIG) $(SRCS1)
E 59
E 57
E 36
E 23
D 74

I 62
sl: sl.sed
	@$(PRT) -y SCCS | sed -f sl.sed | sort
D 73

E 62
D 25
xref: *.c
	${XREF} *.c > xref
E 25
I 25
D 57
xref: $(SRCS) XREF

XREF: *.c
	${XREF} *.c > XREF
E 25
I 5

E 57
D 6
aldbm:	aldbm.c
	$(CC) $(CFLAGS) aldbm.c -o aldbm $(LIBS)
E 6
I 6
D 8
aliasdbm:	aliasdbm.c
	$(CC) $(CFLAGS) aliasdbm.c -o aliasdbm $(LIBS)
E 8
I 8
#
D 31
#  Data base maintenance routines
#
D 10
AOBJS=	aliasdbm.o parse.o conf.o util.o
E 10
I 10
D 24
AOBJS=	newaliases.o parse.o conf.o util.o
E 24
I 24
AOBJS=	newaliases.o parse.o conf.o util.o macro.o readcf.o stab.o \
	headers.o bmove.o
E 24
E 10
E 8
E 6

D 6
alget:	alget.c
	$(CC) $(CFLAGS) alget.c -o alget $(LIBS)
E 6
I 6
D 8
showdbm:	showdbm.c
E 8
I 8
D 10
aliasdbm: $(AOBJS)
	$(CC) $(LDFLAGS) $(AOBJS) -o aliasdbm $(LIBS)
E 10
I 10
newaliases: $(AOBJS)
	$(CC) $(LDFLAGS) $(AOBJS) -o newaliases $(LIBS)
E 10

D 10
showdbm: showdbm.c
E 8
	$(CC) $(CFLAGS) showdbm.c -o showdbm $(LIBS)
E 10
I 10
praliases: praliases.c
	$(CC) $(CFLAGS) praliases.c -o praliases $(LIBS)
E 10
I 8

D 10
aliasdbm.o showdbm.o: dlvrmail.h
E 10
I 10
D 15
newaliases.o praliases.o: dlvrmail.h
E 15
I 15
D 19
newaliases.o praliases.o: postbox.h
E 19
I 19
newaliases.o praliases.o: sendmail.h
E 19
E 15
E 10
E 8
E 6
E 5

#
E 31
#  Auxiliary mailers
#
D 66

arpa: arpa.o matchhdr.o arpadate.o
D 2
	$(MAKEVERSION) Arpa-mailer 1.0 ${CC}
	$(CC) $(LDFLAGS) -o arpa version.o arpa.o matchhdr.o arpadate.o $(LIBS)
E 2
I 2
D 50
	$(CC) $(LDFLAGS) -o arpa arpa.o matchhdr.o arpadate.o $(LIBS)
E 2
	${CHMOD} ${OBJMODE} arpa
	size arpa; ls -l arpa
E 50
I 50
D 57
	$(CC) $(LDFLAGS) -o $@ $@.o matchhdr.o arpadate.o $(LIBS)
E 57
I 57
	$(CC) $(COPTS) -o $@ $@.o matchhdr.o arpadate.o $(LIBS)
E 57
D 62
	${CHMOD} ${OBJMODE} $@
	size $@; ls -l $@
E 50

uucp: uucp.o
D 2
	$(MAKEVERSION) Uucp-mailer 1.0 ${CC}
	${CC} ${LDFLAGS} -o uucp version.o uucp.o ${LIBS}
E 2
I 2
D 50
	${CC} ${LDFLAGS} -o uucp uucp.o ${LIBS}
E 2
	${CHMOD} ${OBJMODE} uucp
	size uucp; ls -l uucp
E 50
I 50
D 57
	${CC} ${LDFLAGS} -o $@ $@.o ${LIBS}
E 57
I 57
	${CC} ${COPTS} -o $@ $@.o ${LIBS}
E 57
	${CHMOD} ${OBJMODE} $@
	size $@; ls -l $@
E 50
I 32

I 50
D 56
usersmtp: usersmtp.o
E 56
I 56
smtpmailer: smtpmailer.o
E 56
D 53
	${CC} ${LDFLAGS} -o $@ $@.o ${LIBS}
E 53
I 53
D 57
	${CC} ${LDFLAGS} -o $@ $@.o $(REXEC) ${LIBS}
E 57
I 57
	${CC} ${COPTS} -o $@ $@.o $(REXEC) ${LIBS}
E 62
E 57
E 53
	${CHMOD} ${OBJMODE} $@
	size $@; ls -l $@
E 66

E 50
rmail: rmail.o
D 50
	${CC} ${LDFLAGS} -o rmail rmail.o ${LIBS}
	${CHMOD} ${OBJMODE} rmail
	size rmail; ls -l rmail
E 50
I 50
D 57
	${CC} ${LDFLAGS} -o $@ $@.o ${LIBS}
E 57
I 57
	${CC} ${COPTS} -o $@ $@.o ${LIBS}
E 57
	${CHMOD} ${OBJMODE} $@
	size $@; ls -l $@
E 50
E 32

D 60
mail:	mail.o getname.o
E 60
I 60
mail: mail.o getname.o
E 60
D 2
	$(MAKEVERSION) Local-mailer 1.0 ${CC}
	$(CC) $(LDFLAGS) -o mail version.o mail.o getname.o
E 2
I 2
D 50
	$(CC) $(LDFLAGS) -o mail mail.o getname.o
E 2
	size mail; ls -l mail
E 50
I 50
D 57
	$(CC) $(LDFLAGS) -o $@ $@.o getname.o
E 57
I 57
	$(CC) $(COPTS) -o $@ $@.o getname.o
E 57
	size $@; ls -l $@
E 50
I 43

I 65
#
#  Some auxiliary routines
#

E 65
D 47
vacation: vacation.o util.o bmove.o
	$(CC) $(LDFLAGS) -o vacation vacation.o util.o bmove.o $(LIBS)
E 47
I 47
VOBJS=	vacation.o convtime.o util.o bmove.o
vacation: $(VOBJS)
D 50
	$(CC) $(LDFLAGS) -o vacation $(VOBJS) $(LIBS)
E 47
	$(CHMOD) $(OBJMODE) vacation
	size vacation; ls -l vacation
E 50
I 50
D 57
	$(CC) $(LDFLAGS) -o $@ $(VOBJS) $(LIBS)
E 57
I 57
	$(CC) $(COPTS) -o $@ $(VOBJS) $(LIBS)
E 57
	$(CHMOD) $(OBJMODE) $@
	size $@; ls -l $@
E 50
vacation.o: useful.h
I 65

mconnect: mconnect.o
	$(CC) $(COPTS) -o $@ mconnect.o
	$(CHMOD) $(OBJMODE) $@
	size $@; ls -l $@
E 73
E 65
E 43
I 31

#
#  Documentation
#
E 31
I 29

nroff: sendmail.doc
	nroff -me $(TERM) sendmail.doc

spell: sendmail.doc spell.good
	spell sendmail.doc | sort | comm -23 - spell.good > spell.out
E 74
E 29
E 1
