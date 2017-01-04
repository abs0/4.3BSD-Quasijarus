h57559
s 00017/00000/00587
d D 5.17 06/05/19 21:47:21 msokolov 166 165
c implemented alias attributes
e
s 00001/00000/00586
d D 5.16 04/11/21 08:41:36 msokolov 165 164
c implement ability to globally limit message size in collect phase (l option)
e
s 00002/00000/00584
d D 5.15 04/04/23 15:28:51 msokolov 164 163
c add R option to disable relaying service for Internet senders
e
s 00001/00000/00583
d D 5.14 02/05/29 21:58:00 msokolov 163 162
c preserve the numeric IP address of origin in the traces left by a message
c (it would now normally appear as a (comment) in CurHostName and $s)
e
s 00001/00000/00582
d D 5.13 88/09/20 22:15:28 eric 162 161
c add I option to insist on Internet domain server; add NAMED_BIND
c compile option to compile in named routines.
e
s 00011/00010/00571
d D 5.12 88/06/30 14:59:42 bostic 161 160
c install approved copyright notice
e
s 00017/00012/00564
d D 5.11 88/03/13 19:53:08 bostic 160 157
c add Berkeley specific header
e
s 00001/00001/00582
d D 5.10.1.2 86/12/17 16:19:30 eric 159 158
c fix stupid botch -- reversed condition
e
s 00007/00000/00576
d D 5.10.1.1 86/12/17 16:08:30 eric 158 157
c hack around compiler bug that gets confused on isascii
e
s 00002/00002/00574
d D 5.10 86/10/14 17:25:03 eric 157 156
c make global variables begin with cap letters -- Please!!
e
s 00002/00000/00574
d D 5.9 86/07/21 10:21:19 bloom 156 155
c add support for MX use of the name server
e
s 00001/00000/00573
d D 5.8 86/01/10 21:02:18 eric 155 154
c add CheckAliases
e
s 00005/00000/00568
d D 5.7 85/11/22 11:26:33 miriam 154 153
m 
c Include MAX_ERRNO as an offset for the Name Server error message codes
c so as to not overlap with the System error message codes.
e
s 00002/00001/00566
d D 5.6 85/09/30 21:34:30 eric 153 152
m 
c clean up some aspects of error message display
e
s 00001/00000/00566
d D 5.5 85/09/24 15:09:52 eric 152 151
m 
c don't step on user environment
e
s 00018/00017/00548
d D 5.4 85/09/21 13:25:09 eric 151 150
m 
c make WK...FACT's configurable
e
s 00000/00000/00565
d D 5.3 85/09/19 01:25:30 eric 150 148
i 149
m 
c incorporate SMI changes -- still experimental
e
s 00059/00007/00505
d D 5.1.1.1 85/09/19 00:55:41 eric 149 147
m 
c SMI changes (somewhat)
e
s 00001/00000/00512
d D 5.2 85/09/04 09:39:12 eric 148 147
m 
c add H_VALID header flag for Sender: fields
e
s 00012/00000/00500
d D 5.1 85/06/07 16:11:49 dist 147 146
m 
c Add copyright
e
s 00001/00001/00499
d D 4.13 85/04/04 17:45:11 miriam 146 145
m 
c Correct location of syslog.h
e
s 00000/00000/00500
d D 4.12 84/12/06 10:04:42 eric 145 144
x 144
m 
c delete e_qfp -- there just isn't any point
e
s 00001/00000/00500
d D 4.11 84/12/05 21:58:03 eric 144 143
m 
c add e_qfp
e
s 00001/00000/00499
d D 4.10 84/12/05 20:55:58 eric 143 142
m 
c add M_SECURE_PORT
e
s 00001/00001/00498
d D 4.9 84/12/05 19:57:37 eric 142 141
m 
c SafeAlias is now an int
e
s 00011/00011/00488
d D 4.8 84/08/11 22:28:10 eric 141 140
m 
c fix conflict in internal character codes
e
s 00003/00000/00496
d D 4.7 84/08/11 20:00:46 eric 140 139
m 
c add PSBUFSIZE for size of prescan buffer
e
s 00004/00000/00492
d D 4.6 84/08/11 18:57:39 eric 139 138
m 
c add HOSTBEGIN and HOSTEND for hostname lookup
e
s 00011/00010/00481
d D 4.5 84/08/11 12:38:23 eric 138 136
m 
c add M_ESCFROM flag
e
s 00002/00000/00491
d D 4.4.1.1 84/06/17 16:17:43 eric 137 136
m 
c abortive attempt to install a name server.... sigh.
e
s 00002/00000/00489
d D 4.4 84/03/11 16:54:33 eric 136 135
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00001/00001/00488
d D 4.3 84/03/11 13:37:58 eric 135 134
m 
c fixes from Greg Satz <satz@sri-tsc.ARPA>, mostly for PDP's
e
s 00003/00000/00486
d D 4.2 83/08/28 14:06:32 eric 134 133
m 
c Add SM_DEFAULT so that we can arrange for sendall to default the mode.
e
s 00000/00000/00486
d D 4.1 83/07/25 19:45:31 eric 133 132
m 
c 4.2 release version
e
s 00007/00001/00479
d D 3.118 83/05/18 11:53:27 eric 132 131
m 
c change WKTIMEFACT to be negative so that jobs that are failing are pushed
c to the end rather than to the beginning of the queue, thus improving overall
c performance.  Thanks to Jay Lepreau for this observation.
e
s 00005/00002/00475
d D 3.117 83/03/07 09:56:59 eric 131 130
m 203
c Don't pass EX_TEMPFAIL code out (since we have already taken responsibility
c for delivering the message anyway).
e
s 00002/00001/00475
d D 3.116 83/03/06 16:30:41 eric 130 129
m 201
c Handle messages with "Resent-xxx:" header lines properly (basically mark
c the message as being resent); ignore incoming From: lines if their text
c exactly matches our machine-readable address exactly -- this causes the
c full name to be added when called from (e.g.) MH.  Both of these mode are
c to improve interaction with MH.
e
s 00001/00000/00475
d D 3.115 83/03/06 11:25:18 eric 129 128
m 201
c Add H_RESENT flag to header flags to indicate fields that are associated
c with a resent message.
e
s 00001/00001/00474
d D 3.114 83/02/13 16:22:39 eric 128 127
m 182
c fix clrbitmap to really clear the entire bitmap
e
s 00000/00007/00475
d D 3.113 83/02/03 10:54:47 eric 127 126
m 
c clean up mailer flags -- M_ARPAFMT is garbage now
e
s 00054/00024/00428
d D 3.112 83/02/02 12:49:52 eric 126 125
m 165
m 168
c implement classes and mailer flags as a bit map; put in initial hook
c for per-mailer size limits
e
s 00001/00004/00451
d D 3.111 83/01/16 13:13:25 eric 125 124
m 152
c Change mailer spec to have labelled fields for future expansion.
c **** This delta invalidates previous configuration files ****
e
s 00015/00003/00440
d D 3.110 83/01/09 15:03:00 eric 124 121
m 
c turn newstr() and crlf() into macros
e
s 00015/00003/00440
d R 3.110 83/01/09 14:55:59 eric 123 121
m 
c turn crlf() and newstr() into macros
e
s 00015/00002/00441
d R 3.110 83/01/09 14:52:20 eric 122 121
m 
c make newstr and crlf macros
e
s 00001/00000/00442
d D 3.109 83/01/09 14:43:44 eric 121 120
m 
c add declaration of "crlf"
e
s 00003/00001/00439
d D 3.108 83/01/06 10:45:14 eric 120 119
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00001/00000/00439
d D 3.107 83/01/05 21:30:05 eric 119 118
m 
c add M_CRLF
e
s 00001/00000/00438
d D 3.106 83/01/03 14:50:41 eric 118 117
m 
c add e_message field for eventual error message improvement
e
s 00001/00001/00437
d D 3.105 82/12/24 08:14:27 eric 117 116
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00001/00000/00437
d D 3.104 82/12/09 11:17:17 eric 116 115
m 095
c be able to match the inverse of a class using the $~x syntax
e
s 00002/00002/00435
d D 3.103 82/12/05 13:45:55 eric 115 114
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00015/00042/00422
d D 3.102 82/11/28 00:21:06 eric 114 113
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00011/00007/00453
d D 3.101 82/11/24 17:15:02 eric 113 112
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00001/00000/00459
d D 3.100 82/11/21 17:18:50 eric 112 111
m 026
c preliminary hacks for multiple SMTP transactions per connection: make
c assignment of multiple queue id's more efficient, make prefixes two
c characters (e.g., qfAA99999), pass the file name to freeze and thaw,
c add a mailer flag saying we are talking to one of our own kind.
e
s 00025/00010/00434
d D 3.99 82/11/17 09:35:48 eric 111 110
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00005/00015/00439
d D 3.98 82/11/13 17:55:08 eric 110 109
m 069,
m 070
c clean up argument structure; move configuration into conf.h
e
s 00001/00001/00453
d D 3.97 82/11/05 13:12:40 eric 109 108
m 062
c arrange to freeze the configuration file for quick startup -- this
c technique requires reprocessing the argv so that flag settings don't
c get lost, and is really rather of a hack.
e
s 00000/00001/00454
d D 3.96 82/11/04 13:26:57 eric 108 107
m 037
c put header conditionals into the .cf file
e
s 00001/00000/00454
d D 3.95 82/11/03 10:04:01 eric 107 106
m 059
c Add FileMode
e
s 00001/00001/00453
d D 3.94 82/11/03 09:48:38 eric 106 105
m 049
c Arrange to strip quote bits in message header; move SPACESUB into
c conf.c; change SpaceSub to unquoted dot
e
s 00003/00000/00451
d D 3.93 82/10/28 17:40:32 eric 105 104
m 039,
m 027
c Put the "@:@" trick on the "a" option.  Also, move TrustedUsers into
c sendmail.h (it should have gone here in the first place!)
e
s 00001/00000/00450
d D 3.92 82/10/06 10:46:52 eric 104 103
c add MD_TEST mode
e
s 00012/00011/00438
d D 3.91 82/09/26 17:04:10 eric 103 102
c Put more configuration into setoption; merge some of the argv processing
c with this; move configuration information out of conf.c into the .cf
c file.  Since a lot of stuff will default to zero, a new .cf file is
c required.
e
s 00001/00000/00448
d D 3.90 82/09/26 14:45:39 eric 102 101
c completely instantiate queue files for all mail, even if not needed;
c fix a bug that would probably come up once every ten years in creating
c the queue id.  should merge argv flag processing with option processing.
e
s 00000/00011/00448
d D 3.89 82/09/24 19:39:10 eric 101 100
c change option implementation; define a bunch of interesting options.
e
s 00020/00007/00439
d D 3.88 82/09/24 09:38:00 eric 100 99
c arrange to be able to define options; put precedences in .cf file;
c send errors to an Errors-To: field; fix a serious bug causing mail
c to not be delivered to anyone if there were any errors.
e
s 00002/00001/00444
d D 3.87 82/09/12 16:43:21 eric 99 98
c change inheritance for macros in envelopes; be able to canonicalize
c non-domained names by appending domain from sender; call ruleset 3
c explicitly before doing other rulesets; some general cleanup.
e
s 00004/00006/00441
d D 3.86 82/09/05 18:02:41 eric 98 97
c change from m_from (macro from rewrite) to using a pair of rewriting
c rules; convert Return-Receipt-To: and Precedence: to NBS standard;
c correctly process all sender fields
e
s 00024/00008/00423
d D 3.85 82/09/05 11:47:48 eric 97 96
c add $* to match zero or more and $> to make a "subroutine" call; stick
c in initial hooks for per-mailer rewriting; improve diagnostics in readcf,
c including number lines; increase the number of rewriting sets.
e
s 00001/00001/00430
d D 3.84 82/08/31 17:46:16 eric 96 95
c increase MAXMAILERS to 25
e
s 00004/00000/00427
d D 3.83 82/08/27 11:11:22 eric 95 94
c release e_id after fork in daemon code; ignore events scheduled by
c another process
e
s 00001/00001/00426
d D 3.82 82/08/25 11:21:05 eric 94 93
c clean up time manipulation to always be current; assign job
c id's earlier to make sure there is always one with a message.
e
s 00013/00011/00414
d D 3.81 82/08/23 11:59:25 eric 93 92
c clean up queueing; log time in queue.
c **** This delta invalidates mqueue files ****
e
s 00003/00002/00422
d D 3.80 82/08/22 19:02:51 eric 92 91
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00003/00005/00421
d D 3.79 82/08/21 17:52:44 eric 91 90
c increase MAXATOMS from 30 to 100 -- since <> is now in .cf file
e
s 00003/00001/00423
d D 3.78 82/08/15 17:32:08 eric 90 89
c mark From: lines with a bit; make EXPN work properly
e
s 00019/00000/00405
d D 3.77 82/08/08 17:02:29 eric 89 88
c more general event mechanism
e
s 00016/00001/00389
d D 3.76 82/08/08 01:02:23 eric 88 87
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00003/00000/00387
d D 3.75 82/07/05 12:02:34 eric 87 86
c put timeouts on net reads
e
s 00001/00000/00386
d D 3.74 82/07/02 20:52:35 eric 86 85
c arrange to not lose temporary queue control files (tf files)
c if you interrupt a queue run process.
e
s 00001/00000/00385
d D 3.73 82/06/26 11:56:42 eric 85 84
c add _kill command to SMTP.  this is probably dangerous in the
c outside world.
e
s 00001/00000/00384
d D 3.72 82/06/06 23:04:56 eric 84 82
c implement alias owner feature.  this actually works for any user.
c basically, if the alias owner-xxx exists, errors sending to xxx will be
c sent to that alias rather than to the sender.
e
s 00001/00000/00384
d D 3.71.1.1 82/06/06 20:12:53 eric 83 82
c first cut at putting mailing list maintainers in -- there is a
c much better way though.
e
s 00015/00002/00369
d D 3.71 82/05/31 17:10:38 eric 82 81
c eliminate -V, -D, -p flags in favor of a single flag "-bx"
c (be in mode x).
e
s 00000/00001/00371
d D 3.70 82/05/31 15:31:41 eric 81 80
i 79
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00001/00000/00368
d D 3.69 82/05/30 10:25:14 eric 80 78
c add M_FULLSMTP (``X'' flag in .cf file) for eventual implementation
c of full SMTP.  This version must support such garbage as line limits,
c address length limits, return-path, etc.
e
s 00017/00014/00354
d D 3.68.1.1 82/05/29 18:19:45 eric 79 78
c try to install envelopes.  is this really worth it???
e
s 00010/00004/00358
d D 3.68 82/05/22 02:05:20 eric 78 77
c add "junk mail" -- error responses are never returned.
e
s 00034/00049/00328
d D 3.67 82/05/22 01:37:20 eric 77 76
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00001/00000/00376
d D 3.66 82/05/20 17:45:43 eric 76 75
c add dfopen as a "determined fopen" -- it retries if it gets recoverable
c errors.  we use it for returning mail (to dead.letter) and creating the
c temp file.  the whole idea is to avoid dropping things on the floor on
c heavily loaded systems.  this is untested, since it seems impossible to
c fill up the inode or file tables on this VAX (but it works if the open
c succeeds).
e
s 00017/00016/00359
d D 3.65 82/05/15 12:16:03 eric 75 74
c add M_RELRCPT flag to indicate that messages sent to this mailer should
c have their recipient addresses rewritten to be relative to the receiver.
e
s 00004/00000/00371
d D 3.64 82/03/06 12:45:35 eric 74 73
c add more internal character types (for conditionals) -- for internal
c cleanup
e
s 00003/00002/00368
d D 3.63 82/03/06 12:09:07 eric 73 72
c clean up error handling in IPC case; fix a minor bug in headers in
c queueing code; make SMTP mail multi user per connect.
e
s 00002/00000/00368
d D 3.62 82/02/27 11:37:21 eric 72 71
c implement "return receipt requested".
e
s 00001/00001/00367
d D 3.61 82/02/26 21:55:59 eric 71 70
c implement daemon mode
e
s 00001/00000/00367
d D 3.60 82/02/20 19:16:08 eric 70 69
c make rewriting of addresses in headers really work.  This adds the $q
c macro.  The rewriting of the From: address is still ad hoc and should
c be integrated into this format.
c Note:  old .cf files will not work with this version.
e
s 00002/00000/00365
d D 3.59 82/02/20 12:09:44 eric 69 68
c implement -c flag: don't try to deliver expensive mail immediately
e
s 00004/00000/00361
d D 3.58 82/02/04 20:29:52 eric 68 67
c add host aliasing; add -p flag.  this version doesn't yet know about
c replacing the text of the host alias into the message however.  syntax
c is grotty: "/hostmatch:%s@newhost" or whatever.
e
s 00016/00014/00345
d D 3.57 82/01/23 14:19:36 eric 67 66
c add M_UGLYUUCP flag for ugly from line
e
s 00003/00004/00356
d D 3.56 81/12/06 12:38:19 eric 66 65
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00014/00005/00346
d D 3.55 81/11/22 19:17:13 eric 65 64
c Edit queue control files when running queue (assuming there are still
c recipients left).  Also, modify the MsgPriority to be the absolute
c number (not the Priority: value); this allows us to include aging into
c the priority algorithm.
e
s 00001/00008/00350
d D 3.54 81/11/21 18:41:49 eric 64 63
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00001/00000/00357
d D 3.53 81/11/21 16:37:35 eric 63 61
c convert to SMTP draft 3 -- finishing touches.  Punt on the VRFY/
c EXPN commands for now; they aren't required anyhow.  Move the fullname
c into the address structure so it can be inherited.
e
s 00017/00002/00355
d D 3.52.1.1 81/11/21 15:46:37 eric 62 61
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00003/00008/00354
d D 3.52 81/10/31 22:12:23 eric 61 60
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00007/00005/00355
d D 3.51 81/10/27 10:50:34 eric 60 59
c More queueing cleanup: implement timeouts (still one-stage),
c properly implement priorities (didn't work before), and miscellaneous
c cleanup.
e
s 00049/00004/00311
d D 3.50 81/10/26 14:22:10 eric 59 58
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00004/00007/00311
d D 3.49 81/10/23 19:37:29 eric 58 57
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00013/00008/00305
d D 3.48 81/10/19 22:27:04 eric 57 56
c implement SMTP mode -- doesn't support source routing or the
c HELP command, and doesn't give the correct code on VRFY or forwarding.
c Maybe someday....
e
s 00004/00002/00309
d D 3.47 81/10/17 16:57:44 eric 56 55
c initial prep to put in Daemon mode
e
s 00001/00000/00310
d D 3.46 81/10/06 18:56:45 eric 55 54
c add MATCHREPL for replacement on RHS of rewriting rule
e
s 00001/00000/00309
d D 3.45 81/09/24 10:30:25 eric 54 52
c changes to work under a V6 system -- mostly compilation flags
e
s 00001/00000/00309
d D 3.44.1.1 81/09/23 18:23:01 eric 53 52
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00001/00000/00308
d D 3.44 81/09/22 11:33:10 eric 52 51
c finally make suppression of sender in mailing lists work -- this version
c also works correctly on simple aliases.
e
s 00001/00000/00307
d D 3.43 81/09/16 16:39:35 eric 51 50
c be REALLY clever and inherit uid/gid from owner of :include:
c files also...   solves problem of alias to non-secure file
e
s 00002/00000/00305
d D 3.42 81/09/16 16:07:52 eric 50 49
c run as the user forwarding mail after a .forward operation;
c fix a bug in .forwarding that caused recursive expansion;
c restrict mail to programs, files, and with :include: for security
c reasons.
e
s 00001/00001/00304
d D 3.41 81/09/14 12:41:04 eric 49 48
c check MAXATOM overflow; increase MAXATOM value
e
s 00008/00007/00297
d D 3.40 81/09/12 17:33:39 eric 48 47
c match on full name for local users
e
s 00036/00028/00268
d D 3.39 81/09/12 15:48:48 eric 47 46
c change From: processing to reduce the number of Original-From:
c lines; change allocation of global variables.
e
s 00001/00000/00295
d D 3.38 81/09/07 14:12:41 eric 46 45
c fix up umask; allow setuid on files to take recipient owner;
c factor some configuration info into conf.c
e
s 00001/00001/00294
d D 3.37 81/09/06 19:48:27 eric 45 44
c cleanup, commenting, linting, etc.
e
s 00001/00000/00294
d D 3.36 81/09/01 11:43:26 eric 44 43
c add "suppress return-to-sender" function
e
s 00024/00004/00270
d D 3.35 81/08/31 21:21:38 eric 43 42
c collect mail statistics; change minor configuration
e
s 00000/00001/00274
d D 3.34 81/08/29 19:08:15 eric 42 41
c delete H_DELETE -- can be simulated with H_ACHECK
e
s 00001/00000/00274
d D 3.33 81/08/27 11:32:10 eric 41 40
c on -t, use argument list as a supress list
e
s 00002/00000/00272
d D 3.32 81/08/24 14:05:27 eric 40 39
c Add "-t" option to read To:, Cc:, and Bcc: lines to get recipients
e
s 00001/00000/00271
d D 3.31 81/08/22 19:36:32 eric 39 38
c only use a .forward file if owned by the receiver
e
s 00000/00001/00271
d D 3.30 81/08/22 14:34:01 eric 38 37
c fix UNIX From problem
e
s 00003/00004/00269
d D 3.29 81/08/21 18:11:04 eric 37 36
c drop M_FINAL, rename some other defined constants
e
s 00003/00000/00270
d D 3.28 81/08/20 15:13:53 eric 36 35
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00003/00004/00267
d D 3.27 81/08/20 12:27:02 eric 35 34
c correct some comments
e
s 00002/00000/00269
d D 3.26 81/08/18 17:12:49 eric 34 33
c factor out ARPANET FTP reply codes into conf.c
e
s 00007/00001/00262
d D 3.25 81/08/18 16:47:11 eric 33 32
c convert to really do arpanet reply codes right (maybe)
e
s 00008/00006/00255
d D 3.24 81/08/17 09:37:41 eric 32 31
c add header fields from new BB&N proposal ICST/CBOS - 80-2,
c "Specification of a Draft Message Format Standard" for NBS.
e
s 00025/00005/00236
d D 3.23 81/08/10 16:56:21 eric 31 30
c totally rework aliasing scheme -- sucks when no DBM now,
c but works better for the usual case; fix some quoting problems
c (and how many did I add?); remove .mailer feature since .forward
c will simulate this happily
e
s 00002/00000/00239
d D 3.22 81/08/09 19:08:14 eric 30 29
c put mailer definitions into configuration file
e
s 00001/00001/00238
d D 3.21 81/08/09 16:39:52 eric 29 28
c arrange for newaliases to work
e
s 00009/00000/00230
d D 3.20 81/08/09 15:02:37 eric 28 27
c lint it
e
s 00007/00001/00223
d D 3.19 81/08/09 12:34:25 eric 27 26
c add private incoming mailers; add q_home field to ADDRESS struct;
c some general cleanup
e
s 00001/00001/00223
d D 3.18 81/08/09 10:13:44 eric 26 25
c change to debugging levels
e
s 00001/00001/00223
d D 3.17 81/08/08 17:47:27 eric 25 24
c add another set of rewrite rules to process From: address;
c this will allow generalized from address processing in an
c internet
e
s 00002/00000/00222
d D 3.16 81/08/08 16:08:29 eric 24 23
c efficiency hacks with QBADADDR and QGOODADDR; don't call
c mailer if nothing to send
e
s 00001/00000/00221
d D 3.15 81/08/08 14:00:48 eric 23 22
c preliminary groundbreaking for verbose mode
e
s 00003/00002/00218
d D 3.14 81/08/08 11:17:42 eric 22 21
c add word classes
e
s 00022/00000/00198
d D 3.13 81/08/08 10:22:52 eric 21 20
c add definitions for symbol table
e
s 00003/00001/00195
d D 3.12 81/03/28 13:36:51 eric 20 19
c pass Full-Name field internally to do forwards correctly
e
s 00003/00004/00193
d D 3.11 81/03/28 12:02:41 eric 19 18
c put much more info in cf file (e.g., headers)
e
s 00001/00001/00196
d D 3.10 81/03/27 00:26:07 eric 18 17
c drop MSGID M_MSGID from M_ARPAFMT
e
s 00001/00001/00196
d D 3.9 81/03/20 09:45:26 eric 17 16
c change name (again); from postbox to sendmail
e
s 00001/00001/00196
d D 3.8 81/03/12 10:57:17 eric 16 15
c merge letters to the same host into one message
e
s 00032/00033/00165
d D 3.7 81/03/11 10:46:25 eric 15 14
c general cleanup, esp. macro processor
e
s 00025/00023/00173
d D 3.6 81/03/09 13:23:11 eric 14 13
c first step at rewriting rules, etc.
e
s 00002/00001/00194
d D 3.5 81/03/07 17:45:54 eric 13 12
c drop stupid concatenation stuff; add hi_pptr
e
s 00004/00004/00191
d D 3.4 81/03/07 16:59:51 eric 12 11
c change q_mailer to be index, not pointer
e
s 00001/00000/00194
d D 3.3 81/03/07 14:58:28 eric 11 10
c save real mailer
e
s 00005/00006/00189
d D 3.2 81/03/07 14:27:42 eric 10 9
c ----- delivermail ==> postbox -----
e
s 00063/00009/00132
d D 3.1 81/03/04 09:34:18 eric 9 8
c install fancy header stuff
e
s 00001/00000/00140
d D 2.2 80/11/21 12:57:22 eric 8 7
c have right user & time come out for msgs
e
s 00000/00000/00140
d D 2.1 80/11/05 11:00:57 eric 7 6
c release 2
e
s 00002/00001/00138
d D 1.6 80/10/18 16:49:14 eric 6 5
c cleanup for dbm stuff: Error => Errors; move local host
c detection into parse; misc cleanup
e
s 00018/00048/00121
d D 1.5 80/10/11 18:11:54 eric 5 4
c cleanup to simplify configuration & fix minor bugs
e
s 00001/00000/00168
d D 1.4 80/10/11 12:57:52 eric 4 3
c allow multi-line fields in headers
e
s 00002/00003/00166
d D 1.3 80/07/25 22:03:30 eric 3 2
c add ID keywords
e
s 00001/00001/00168
d D 1.2 80/07/25 21:40:26 eric 2 1
c changed "-ee" flag to work with BerkNet better
e
s 00169/00000/00000
d D 1.1 80/06/23 08:23:58 eric 1 0
e
u
U
f b 
f i 
t
T
I 1
/*
I 161
 * Copyright (c) 1983 Eric P. Allman
E 161
I 147
D 160
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
**
**	%W% (Berkeley) %G%
*/
E 160
I 160
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 161
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 161
I 161
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
E 161
 *
 *	%W% (Berkeley) %G%
D 161
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
 *
E 161
 */
E 160

/*
E 147
D 3
**  DELIVERMAIL.H -- Global definitions for delivermail.
E 3
I 3
D 10
**  DLVRMAIL.H -- Global definitions for delivermail.
E 10
I 10
D 17
**  POSTBOX.H -- Global definitions for postbox.
E 17
I 17
**  SENDMAIL.H -- Global definitions for sendmail.
E 17
E 10
E 3
D 56
**
D 14
**	Most of these are actually allocated in globals.c
**
E 14
D 3
**	History:
**		12/26/79 -- written.
E 3
I 3
**	%W%	%G%
E 56
E 3
*/
D 160


E 160

I 47
# ifdef _DEFINE
# define EXTERN
I 56
D 66
static char SmailSccsId[] =	"%W%	%G%";
E 66
I 66
# ifndef lint
static char SmailSccsId[] =	"%W%	%Y%	%G%";
# endif lint
E 66
E 56
# else  _DEFINE
# define EXTERN extern
# endif _DEFINE
E 47

I 59
D 66
# ifndef major
# include <sys/types.h>
# endif major
E 66
E 59
I 36
# include <stdio.h>
# include <ctype.h>
I 87
# include <setjmp.h>
I 110
# include "conf.h"
E 110
E 87
I 53
# include "conf.h"
E 53
E 36
I 5
# include "useful.h"

I 88
# ifdef LOG
D 146
# include <syslog.h>
E 146
I 146
# include <sys/syslog.h>
E 146
# endif LOG
I 126

I 149
# ifdef DAEMON
# ifdef VMUNIX
# include <sys/socket.h>
# include <netinet/in.h>
# endif VMUNIX
# endif DAEMON
E 149

I 149

E 149
I 140
# define PSBUFSIZE	(MAXNAME + MAXATOM)	/* size of prescan buffer */


E 140
/*
**  Data structure for bit maps.
**
**	Each bit in this map can be referenced by an ascii character.
**	This is 128 possible bits, or 12 8-bit bytes.
*/

#define BITMAPBYTES	16	/* number of bytes in a bit map */
#define BYTEBITS	8	/* number of bits in a byte */

/* internal macros */
#define _BITWORD(bit)	(bit / (BYTEBITS * sizeof (int)))
#define _BITBIT(bit)	(1 << (bit % (BYTEBITS * sizeof (int))))

typedef int	BITMAP[BITMAPBYTES / sizeof (int)];

/* test bit number N */
#define bitnset(bit, map)	((map)[_BITWORD(bit)] & _BITBIT(bit))

/* set bit number N */
#define setbitn(bit, map)	(map)[_BITWORD(bit)] |= _BITBIT(bit)

/* clear bit number N */
#define clrbitn(bit, map)	(map)[_BITWORD(bit)] &= ~_BITBIT(bit)

/* clear an entire bit map */
D 128
#define clrbitmap(map)		bzero((char *) map, BITMAPBYTES / sizeof (int))
E 128
I 128
#define clrbitmap(map)		bzero((char *) map, BITMAPBYTES)
E 128
E 126
D 91

E 88
E 5
/*
E 91
I 91
/*
E 91
D 43
**  Manifest constants.
E 43
I 43
D 110
**  Configuration constants.
**	There shouldn't be much need to change these....
E 43
*/

D 48
# define MAXLINE	256	/* maximum line length */
# define MAXNAME	128	/* maximum length of a name */
I 4
# define MAXFIELD	2500	/* maximum total length of a header field */
E 4
D 16
# define MAXPV		15	/* maximum # of parms to mailers */
E 16
I 16
# define MAXPV		40	/* maximum # of parms to mailers */
E 16
# define MAXHOP		30	/* maximum value of HopCount */
I 14
# define MAXATOM	15	/* max atoms per address */
I 30
# define MAXMAILERS	10	/* maximum mailers known to system */
E 48
I 48
# define MAXLINE	256		/* max line length */
# define MAXNAME	128		/* max length of a name */
# define MAXFIELD	2500		/* max total length of a hdr field */
# define MAXPV		40		/* max # of parms to mailers */
# define MAXHOP		30		/* max value of HopCount */
D 49
# define MAXATOM	15		/* max atoms per address */
E 49
I 49
D 91
# define MAXATOM	30		/* max atoms per address */
E 91
I 91
# define MAXATOM	100		/* max atoms per address */
E 91
E 49
D 96
# define MAXMAILERS	10		/* maximum mailers known to system */
E 96
I 96
# define MAXMAILERS	25		/* maximum mailers known to system */
I 97
# define MAXRWSETS	30		/* max # of sets of rewriting rules */
I 100
# define MAXPRIORITIES	25		/* max values for Precedence: field */
I 105
# define MAXTRUST	30		/* maximum number of trusted users */
E 105
E 100
E 97
E 96
D 106
# define SPACESUB	('.'|0200)	/* substitution for <lwsp> */
E 106
E 48
E 30
E 14
I 6
D 43
# define ALIASFILE	"/usr/lib/aliases"	/* location of alias file */
I 30
# define CONFFILE	"/usr/lib/sendmail.cf"	/* configuration file */
E 43
E 30
E 6
D 91

I 33
D 61
/* values for ArpaMode -- these are ordered!! */
# define ARPA_NONE	0	/* not in arpanet mode */
# define ARPA_OLD	1	/* in old arpanet mode */
# define ARPA_MAIL	2	/* in regular arpanet mail */
# define ARPA_FILE	3	/* reading over data connection */
I 57
# define ARPA_SMTP	4	/* running SMTP protocol */
E 57
E 33

E 61
I 34
extern char	Arpa_Info[];	/* the message number for Arpanet info */
E 91
D 77

E 34



I 15

I 33

E 33
E 15
/*
E 77
I 77
/*
E 110
E 77
I 15
**  Address structure.
**	Addresses are stored internally in this structure.
I 62
**
**	Each address is on two chains and in one tree.
**		The q_next chain is used to link together addresses
**		  for one mailer (and is rooted in a mailer).
**		The q_chain chain is used to maintain a list of
**		  addresses originating from one call to sendto, and
**		  is used primarily for printing messages.
**		The q_alias, q_sibling, and q_child tree maintains
**		  a complete tree of the aliases.  q_alias points to
**		  the parent -- obviously, there can be several, and
**		  so this points to "one" of them.  Ditto for q_sibling.
E 62
*/

struct address
{
	char		*q_paddr;	/* the printname for the address */
	char		*q_user;	/* user name */
	char		*q_host;	/* host name */
D 58
	short		q_mailer;	/* mailer to use */
E 58
I 58
	struct mailer	*q_mailer;	/* mailer to use */
E 58
D 99
	short		q_rmailer;	/* real mailer (before mapping) */
E 99
D 32
	short		q_flags;	/* status flags, see below */
E 32
I 32
	u_short		q_flags;	/* status flags, see below */
I 39
	short		q_uid;		/* user-id of receiver (if known) */
I 50
	short		q_gid;		/* group-id of receiver (if known) */
E 50
E 39
E 32
I 27
	char		*q_home;	/* home dir (local mailer only) */
I 63
	char		*q_fullname;	/* full name if known */
E 63
E 27
D 62
	struct address	*q_next;	/* chain */
I 50
	struct address	*q_alias;	/* address this results from */
I 65
	struct address	*q_tchain;	/* temporary use chain */
E 65
E 62
I 62
	char		*q_fullname;	/* full name of this person */
E 62
I 59
	time_t		q_timeout;	/* timeout for this address */
I 62
	struct address	*q_next;	/* chain */
	struct address	*q_alias;	/* parent in alias tree */
	struct address	*q_sibling;	/* sibling in alias tree */
	struct address	*q_child;	/* child in alias tree */
E 62
E 59
E 50
};

typedef struct address ADDRESS;

# define QDONTSEND	000001	/* don't send to this address */
I 24
# define QBADADDR	000002	/* this address is verified bad */
I 51
# define QGOODUID	000004	/* the q_uid q_gid fields are good */
I 52
# define QPRIMARY	000010	/* set from argv */
I 59
# define QQUEUEUP	000020	/* queue for later transmission */
I 62
# define QPSEUDO	000040	/* only on the list for verification */
E 62
E 59
E 52
E 51
D 27
# define QGOODADDR	000004	/* this address is verified good */
E 27
E 24
D 77





/*
E 77
I 77
/*
E 77
E 15
**  Mailer definition structure.
**	Every mailer known to the system is declared in this
**	structure.  It defines the pathname of the mailer, some
**	flags associated with it, and the argument vector to
D 5
**	pass to it.
E 5
I 5
**	pass to it.  The flags are defined in conf.c
E 5
**
I 9
D 64
**	The host map is a list of lists of strings.  Within each
**	list, any host is mapped to the last host in the list.
**	This allows multiple names, as well as doing clever
**	mail grouping in point-to-point networks.  Note: this
**	is only used internally, so the apparent host is still
**	kept around.
**
E 64
E 9
D 5
**	The flags are as follows:
**		M_FOPT -- if set, the mailer has a picky "-f"
**			option.  In this mode, the mailer will only
**			accept the "-f" option if the sender is
**			actually "root", "network", and possibly
**			(but not necessarily) if the -f argument
**			matches the real sender.  The effect is
**			that if the "-f" option is given to
**			delivermail then it will be passed through
**			(as arguments 1 & 2) to the mailer.
**		M_ROPT -- identical to M_FOPT, except uses -r instead.
**			UGH!
**		M_QUIET -- if set, don't print a message if the mailer
**			returns bad status.
**		M_RESTR -- if set, this mailer is restricted to use
**			by "daemon"; otherwise, we do a
**			setuid(getuid()) before calling the mailer.
**		M_HDR -- if set, the mailer wants us to insert a
**			UNIX "From" line before outputting.
**		M_NOHOST -- if set, this mailer doesn't care about
**			the host part (e.g., the local mailer).
**		M_STRIPQ -- if set, strip quote (`"') characters
**			out of parameters as you transliterate them
**			into the argument vector.  For example, the
**			local mailer is called directly, so these
**			should be stripped, but the program-mailer
**			(i.e., csh) should leave them in.
**
E 5
D 35
**	The argument vector is expanded before actual use.  Every-
**	thing is passed through except for things starting with "$".
D 5
**	"$x" defines some interpolation, as defined by x:
**		$f	The "from" person.
**		$h	The host being sent to.
**		$u	The user being sent to.
**		$c	The current hop count.
E 5
I 5
**	"$x" defines some interpolation, as described in conf.c
E 5
**	"$x" where x is unknown expands to "x", so use "$$" to get "$".
E 35
I 35
**	The argument vector is expanded before actual use.  All
**	words except the first are passed through the macro
**	processor.
E 35
*/

struct mailer
{
D 15
	char	*m_mailer;	/* pathname of the mailer to use */
E 15
I 14
	char	*m_name;	/* symbolic name of this mailer */
I 15
	char	*m_mailer;	/* pathname of the mailer to use */
E 15
E 14
D 32
	short	m_flags;	/* status flags, see below */
E 32
I 32
D 126
	u_long	m_flags;	/* status flags, see below */
E 126
I 126
	BITMAP	m_flags;	/* status flags, see below */
E 126
E 32
D 114
	short	m_badstat;	/* the status code to use on unknown error */
E 114
I 54
	short	m_mno;		/* mailer number internally */
E 54
D 14
	char	**m_local;	/* list of local names for this host */
E 14
I 9
D 98
	char	*m_from;	/* pattern for From: header */
E 98
D 14
	char	***m_hmap;	/* host map */
E 14
E 9
D 12
	char	*m_argv[MAXPV];	/* template argument vector */
E 12
I 12
	char	**m_argv;	/* template argument vector */
I 97
D 98
	short	m_rwset;	/* apply this rewriting set to addresses */
E 98
I 98
	short	m_s_rwset;	/* rewriting set for sender addresses */
	short	m_r_rwset;	/* rewriting set for recipient addresses */
I 125
	char	*m_eol;		/* end of line string */
I 126
	long	m_maxsize;	/* size limit on message to this mailer */
E 126
E 125
E 98
E 97
I 15
D 64
	ADDRESS	*m_sendq;	/* list of addresses to send to */
E 64
E 15
E 12
};

I 31
typedef struct mailer	MAILER;

E 31
D 9
# define M_FOPT		0001	/* mailer takes picky -f flag */
# define M_ROPT		0002	/* mailer takes picky -r flag */
# define M_QUIET	0004	/* don't print error on bad status */
# define M_RESTR	0010	/* must be daemon to execute */
# define M_HDR		0020	/* insert From line */
# define M_NOHOST	0040	/* ignore host in comparisons */
# define M_STRIPQ	0100	/* strip quote characters from user/host */
I 8
# define M_FHDR		0200	/* force good From line */
E 9
I 9
D 67
# define M_FOPT		000001	/* mailer takes picky -f flag */
# define M_ROPT		000002	/* mailer takes picky -r flag */
# define M_QUIET	000004	/* don't print error on bad status */
# define M_RESTR	000010	/* must be daemon to execute */
D 15
# define M_HDR		000020	/* insert From line */
E 15
I 15
# define M_NHDR		000020	/* don't insert From line */
E 15
D 37
# define M_NOHOST	000040	/* ignore host in comparisons */
E 37
I 37
# define M_LOCAL	000040	/* delivery is to this host */
E 37
# define M_STRIPQ	000100	/* strip quote characters from user/host */
D 15
# define M_FHDR		000200	/* force good From line */
E 15
I 15
# define M_MUSER	000200	/* mailer can handle multiple users at once */
E 15
# define M_NEEDFROM	000400	/* need arpa-style From: line */
# define M_NEEDDATE	001000	/* need arpa-style Date: line */
# define M_MSGID	002000	/* need Message-Id: field */
I 32
D 37
# define M_FINAL	004000	/* mailing will effect final delivery */
E 37
E 32
D 15
# define M_COMMAS	004000	/* need comma-seperated address lists */
E 15
I 14
# define M_USR_UPPER	010000	/* preserve user case distinction */
# define M_HST_UPPER	020000	/* preserve host case distinction */
I 20
# define M_FULLNAME	040000	/* want Full-Name field */
E 67
I 67
/* bits for m_flags */
I 138
# define M_CANONICAL	'C'	/* make addresses canonical "u@dom" */
# define M_EXPENSIVE	'e'	/* it costs to use this mailer.... */
# define M_ESCFROM	'E'	/* escape From lines to >From */
E 138
D 75
# define M_FOPT		000000001	/* mailer takes picky -f flag */
# define M_ROPT		000000002	/* mailer takes picky -r flag */
# define M_QUIET	000000004	/* don't print error on bad status */
# define M_RESTR	000000010	/* must be daemon to execute */
# define M_NHDR		000000020	/* don't insert From line */
# define M_LOCAL	000000040	/* delivery is to this host */
# define M_STRIPQ	000000100	/* strip quote chars from user/host */
# define M_MUSER	000000200	/* can handle multiple users at once */
# define M_NEEDFROM	000000400	/* need arpa-style From: line */
# define M_NEEDDATE	000001000	/* need arpa-style Date: line */
# define M_MSGID	000002000	/* need Message-Id: field */
# define M_USR_UPPER	000010000	/* preserve user case distinction */
# define M_HST_UPPER	000020000	/* preserve host case distinction */
# define M_FULLNAME	000040000	/* want Full-Name field */
# define M_UGLYUUCP	000100000	/* this wants an ugly UUCP from line */
I 69
# define M_EXPENSIVE	000200000	/* it costs to use this mailer.... */
E 75
I 75
D 126
# define M_FOPT		000000001L	/* mailer takes picky -f flag */
# define M_ROPT		000000002L	/* mailer takes picky -r flag */
D 114
# define M_QUIET	000000004L	/* don't print error on bad status */
E 114
I 114
# define M_RPATH	000000004L	/* wants a Return-Path: line */
E 114
# define M_RESTR	000000010L	/* must be daemon to execute */
# define M_NHDR		000000020L	/* don't insert From line */
# define M_LOCAL	000000040L	/* delivery is to this host */
# define M_STRIPQ	000000100L	/* strip quote chars from user/host */
# define M_MUSER	000000200L	/* can handle multiple users at once */
# define M_NEEDFROM	000000400L	/* need arpa-style From: line */
# define M_NEEDDATE	000001000L	/* need arpa-style Date: line */
# define M_MSGID	000002000L	/* need Message-Id: field */
I 99
# define M_CANONICAL	000004000L	/* make addresses canonical "u@dom" */
E 99
D 98
# define M_RELRCPT	000004000L	/* make recipient addresses relative */
E 98
# define M_USR_UPPER	000010000L	/* preserve user case distinction */
# define M_HST_UPPER	000020000L	/* preserve host case distinction */
# define M_FULLNAME	000040000L	/* want Full-Name field */
# define M_UGLYUUCP	000100000L	/* this wants an ugly UUCP from line */
# define M_EXPENSIVE	000200000L	/* it costs to use this mailer.... */
I 80
D 120
# define M_FULLSMTP	000400000L	/* must run full SMTP, inc. limits */
E 120
I 120
# define M_LIMITS	000400000L	/* must enforce SMTP line limits */
E 120
I 112
# define M_INTERNAL	001000000L	/* SMTP to another sendmail site */
I 119
D 125
# define M_CRLF		002000000L	/* use CRLF instead of NL as EOLine */
E 125
I 120
# define M_FROMPATH	004000000L	/* use reverse-path in MAIL FROM: */
# define M_XDOT		010000000L	/* use hidden-dot algorithm */
E 126
I 126
# define M_FOPT		'f'	/* mailer takes picky -f flag */
D 138
# define M_ROPT		'r'	/* mailer takes picky -r flag */
D 127
# define M_RPATH	'P'	/* wants a Return-Path: line */
E 127
# define M_RESTR	'S'	/* must be daemon to execute */
# define M_NHDR		'n'	/* don't insert From line */
E 138
I 138
# define M_HST_UPPER	'h'	/* preserve host case distinction */
# define M_INTERNAL	'I'	/* SMTP to another sendmail site */
E 138
# define M_LOCAL	'l'	/* delivery is to this host */
D 138
# define M_STRIPQ	's'	/* strip quote chars from user/host */
E 138
I 138
# define M_LIMITS	'L'	/* must enforce SMTP line limits */
E 138
# define M_MUSER	'm'	/* can handle multiple users at once */
D 127
# define M_NEEDFROM	'F'	/* need arpa-style From: line */
# define M_NEEDDATE	'D'	/* need arpa-style Date: line */
# define M_MSGID	'M'	/* need Message-Id: field */
E 127
D 138
# define M_CANONICAL	'C'	/* make addresses canonical "u@dom" */
E 138
I 138
# define M_NHDR		'n'	/* don't insert From line */
# define M_FROMPATH	'p'	/* use reverse-path in MAIL FROM: */
# define M_ROPT		'r'	/* mailer takes picky -r flag */
I 143
# define M_SECURE_PORT	'R'	/* try to send on a reserved TCP port */
E 143
# define M_STRIPQ	's'	/* strip quote chars from user/host */
# define M_RESTR	'S'	/* must be daemon to execute */
E 138
# define M_USR_UPPER	'u'	/* preserve user case distinction */
D 138
# define M_HST_UPPER	'h'	/* preserve host case distinction */
E 138
D 127
# define M_FULLNAME	'x'	/* want Full-Name field */
E 127
# define M_UGLYUUCP	'U'	/* this wants an ugly UUCP from line */
D 138
# define M_EXPENSIVE	'e'	/* it costs to use this mailer.... */
# define M_LIMITS	'L'	/* must enforce SMTP line limits */
# define M_INTERNAL	'I'	/* SMTP to another sendmail site */
# define M_FROMPATH	'p'	/* use reverse-path in MAIL FROM: */
E 138
# define M_XDOT		'X'	/* use hidden-dot algorithm */
E 126
E 120
E 119
E 112
E 80
E 75
E 69
E 67
E 20
E 14
E 9
E 8
D 127

I 9
D 15
# define M_ARPAFMT	(M_NEEDDATE|M_NEEDFROM|M_MSGID|M_COMMAS)
E 15
I 15
D 18
# define M_ARPAFMT	(M_NEEDDATE|M_NEEDFROM|M_MSGID)
E 18
I 18
D 20
# define M_ARPAFMT	(M_NEEDDATE|M_NEEDFROM)
E 20
I 20
D 45
# define M_ARPAFMT	(M_NEEDDATE|M_NEEDFROM|M_NEEDDATE)
E 45
I 45
# define M_ARPAFMT	(M_NEEDDATE|M_NEEDFROM|M_MSGID)
E 127
E 45
E 20
E 18
E 15

E 9
D 12
extern struct mailer Mailer[];
E 12
I 12
D 31
extern struct mailer *Mailer[];
E 31
I 31
D 47
extern MAILER *Mailer[];
E 47
I 47
D 58
EXTERN MAILER *Mailer[MAXMAILERS+1];
E 58
I 58
EXTERN MAILER	*Mailer[MAXMAILERS+1];
E 58
E 47
E 31
I 27

D 58
/* special mailer numbers */
D 37
# define M_LOCAL	0	/* local mailer */
# define M_PROG		1	/* program mailer */
E 37
I 37
# define MN_LOCAL	0	/* local mailer */
# define MN_PROG	1	/* program mailer */
E 37
D 31
# define M_PRIVATE	2	/* user's private mailer */
/* mailers from 3 on are arbitrary */
E 31
I 31
/* mailers from 2 on are arbitrary */
E 31
E 27
E 12

E 58
I 58
EXTERN MAILER	*LocalMailer;		/* ptr to local mailer */
EXTERN MAILER	*ProgMailer;		/* ptr to program mailer */
E 58
D 77

D 15
/*
**  Address structure.
**	Addresses are stored internally in this structure.
*/
E 15

D 15
struct address
{
	char		*q_paddr;	/* the printname for the address */
	char		*q_user;	/* user name */
	char		*q_host;	/* host name */
D 12
	struct mailer	*q_mailer;	/* mailer to use */
I 11
	int		q_rmailer;	/* real mailer (before mapping) */
E 12
I 12
	short		q_mailer;	/* mailer to use */
	short		q_rmailer;	/* real mailer (before mapping) */
E 12
E 11
	struct address	*q_next;	/* chain */
	struct address	*q_prev;	/* back pointer */
};

D 10
typedef struct address addrq;
E 10
I 10
typedef struct address ADDRESS;
E 10

/* some other primitives */
# define nxtinq(q)	((q)->q_next)
# define clearq(q)	(q)->q_next = (q)->q_prev = NULL

D 10
extern addrq SendQ;		/* queue of people to send to */
extern addrq AliasQ;		/* queue of people that are aliases */
E 10
I 10
extern ADDRESS SendQ;		/* queue of people to send to */
extern ADDRESS AliasQ;		/* queue of people that are aliases */
E 10


D 14
/*
**  Parse structure.
**	This table drives the parser which determines the network
**	to send the mail to.
*/
E 14

D 14
struct parsetab
{
	char	p_char;		/* trigger character */
	char	p_mailer;	/* the index of the mailer to call */
	short	p_flags;	/* see below */
	char	*p_arg;		/* extra info needed for some flags */
};
E 14

D 14
# define P_MAP		0001	/* map p_char -> p_arg[0] */
# define P_HLAST	0002	/* host is last, & right associative */
# define P_ONE		0004	/* can only be one p_char in addr */
# define P_MOVE		0010	/* send untouched to host p_arg */
# define P_USR_UPPER	0020	/* don't map UPPER->lower in user names */
# define P_HST_UPPER	0040	/* don't map UPPER->lower in host names */
E 14

E 15
D 14

E 14
I 9
/*
E 77
I 77
/*
E 77
**  Header structure.
**	This structure is used internally to store header items.
*/
E 9

I 9
struct header
{
	char		*h_field;	/* the name of the field */
	char		*h_value;	/* the value of that field */
	struct header	*h_link;	/* the next header */
D 32
	short		h_flags;	/* status bits, see below */
I 19
	short		h_mflags;	/* m_flags bits needed */
E 32
I 32
	u_short		h_flags;	/* status bits, see below */
D 126
	u_long		h_mflags;	/* m_flags bits needed */
E 126
I 126
	BITMAP		h_mflags;	/* m_flags bits needed */
E 126
E 32
E 19
};
E 9

I 9
typedef struct header	HDR;

D 47
extern HDR	*Header;	/* head of header list */
E 47
I 47
D 77
EXTERN HDR	*Header;	/* head of header list */
E 47

E 77
E 9
/*
I 9
**  Header information structure.
**	Defined in conf.c, this struct declares the header fields
**	that have some magic meaning.
*/

struct hdrinfo
{
	char	*hi_field;	/* the name of the field */
D 32
	short	hi_flags;	/* status bits, see below */
I 13
D 19
	char	**hi_pptr;	/* &ptr to point to this value */
E 19
I 19
	short	hi_mflags;	/* m_flags needed for this field */
E 32
I 32
	u_short	hi_flags;	/* status bits, see below */
D 108
	u_short	hi_mflags;	/* m_flags needed for this field */
E 108
E 32
E 19
E 13
};

extern struct hdrinfo	HdrInfo[];

/* bits for h_flags and hi_flags */
D 13
# define H_CONCAT	00001	/* comma-concat multiple fields */
E 13
I 13
# define H_EOH		00001	/* this field terminates header */
I 70
# define H_RCPT		00002	/* contains recipient addresses */
E 70
E 13
D 42
# define H_DELETE	00002	/* don't send this field */
E 42
# define H_DEFAULT	00004	/* if another value is found, drop this */
I 129
D 130
# define H_RESENT	00010	/* this address is a "resent-..." address */
E 130
I 130
# define H_RESENT	00010	/* this address is a "Resent-..." address */
E 130
E 129
D 114
# define H_USED		00010	/* indicates that this has been output */
E 114
I 19
# define H_CHECK	00020	/* check h_mflags against m_flags */
I 20
# define H_ACHECK	00040	/* ditto, but always (not just default) */
I 32
# define H_FORCE	00100	/* force this field, even if default */
I 40
D 98
# define H_ADDR		00200	/* this field contains addresses */
E 98
I 98
# define H_TRACE	00200	/* this field contains trace information */
E 98
I 90
# define H_FROM		00400	/* this is a from-type field */
I 148
# define H_VALID	01000	/* this field has a validated value */
E 148
E 90
I 77
/*
**  Envelope structure.
**	This structure defines the message itself.  There is usually
**	only one of these -- for the message that we originally read
**	and which is our primary interest -- but other envelopes can
**	be generated during processing.  For example, error messages
**	will have their own envelope.
*/
E 77
E 40
E 32
E 20
E 19
I 14

I 77
struct envelope
{
D 79
	HDR	*e_header;	/* head of header list */
	long	e_msgpriority;	/* adjusted priority of this message */
	bool	e_queueup;	/* queue this message for future xmission */
	bool	e_oldstyle;	/* spaces (not commas) delimit addresses */
	bool	e_retreceipt;	/* give a return receipt if delivery occurs */
	bool	e_sendreceipt;	/* actually send a receipt back */
	char	*e_origfrom;	/* the From: line read from the message */
	char	*e_to;		/* the target person */
	ADDRESS	e_from;		/* the person it is from */
	ADDRESS	*e_sendqueue;	/* list of message recipients */
	long	e_msgsize;	/* size of the message in bytes */
	int	(*e_putfunc)();	/* function used to put the message */
I 78
	short	e_class;	/* message class (priority, junk, etc.) */
E 79
I 79
	HDR		*e_header;	/* head of header list */
	long		e_msgpriority;	/* adjusted priority of this message */
I 93
	time_t		e_ctime;	/* time message appeared in the queue */
E 93
D 113
	bool		e_queueup;	/* queue this message */
I 93
	bool		e_dontqueue;	/* override queueing */
E 93
	bool		e_oldstyle;	/* use spaces (not commas) in hdrs */
D 98
	bool		e_retreceipt;	/* give a return receipt */
E 98
	bool		e_sendreceipt;	/* actually send a receipt back */
E 113
D 98
	char		*e_origfrom;	/* the From: line first read */
E 98
	char		*e_to;		/* the target person */
I 98
	char		*e_receiptto;	/* return receipt address */
E 98
	ADDRESS		e_from;		/* the person it is from */
I 99
	char		**e_fromdomain;	/* the domain part of the sender */
E 99
I 83
	ADDRESS		*e_returnto;	/* place to return the message to */
E 83
	ADDRESS		*e_sendqueue;	/* list of message recipients */
I 84
	ADDRESS		*e_errorqueue;	/* the queue for error responses */
E 84
	long		e_msgsize;	/* size of the message in bytes */
I 149
	int		e_nrcpts;	/* number of recipients */
E 149
	short		e_class;	/* msg class (priority, junk, etc.) */
I 113
	short		e_flags;	/* flags, see below */
I 114
	short		e_hopcount;	/* number of times processed */
E 114
E 113
	int		(*e_puthdr)();	/* function to put header of message */
	int		(*e_putbody)();	/* function to put body of message */
	struct envelope	*e_parent;	/* the message this one encloses */
I 113
	struct envelope *e_sibling;	/* the next envelope of interest */
E 113
	char		*e_df;		/* location of temp file */
I 115
	FILE		*e_dfp;		/* temporary file */
E 115
I 92
D 113
	char		*e_qf;		/* queue control file */
E 113
	char		*e_id;		/* code for this entry in queue */
I 115
	FILE		*e_xfp;		/* transcript file */
I 144
	FILE		*e_qfp;		/* queue control file */
E 144
I 118
	char		*e_message;	/* error message */
E 118
E 115
E 92
	char		*e_macro[128];	/* macro definitions */
E 79
E 78
};
E 77

I 77
typedef struct envelope	ENVELOPE;
E 77
I 59

I 113
/* values for e_flags */
#define EF_OLDSTYLE	000001		/* use spaces (not commas) in hdrs */
#define EF_INQUEUE	000002		/* this message is fully queued */
#define EF_TIMEOUT	000004		/* this message is too old */
#define EF_CLRQUEUE	000010		/* disk copy is no longer needed */
#define EF_SENDRECEIPT	000020		/* send a return receipt */
#define EF_FATALERRS	000040		/* fatal errors occured */
#define EF_KEEPQUEUE	000100		/* keep queue files always */
I 114
#define EF_RESPONSE	000200		/* this is an error or return receipt */
I 130
#define EF_RESENT	000400		/* this message is being forwarded */
E 130
E 114

E 113
E 59
D 77
/*
E 77
I 77
EXTERN ENVELOPE	*CurEnv;	/* envelope currently being processed */
/*
E 77
I 59
D 114
**  Work queue.
*/

struct work
{
	char		*w_name;	/* name of control file */
D 65
	short		w_pri;		/* priority of message, see below */
	long		w_size;		/* length of data file */
E 65
I 65
	long		w_pri;		/* priority of message, see below */
E 65
	struct work	*w_next;	/* next in queue */
};

typedef struct work	WORK;

EXTERN WORK	*WorkQ;			/* queue of things to be done */


/*
E 114
D 151
**  Message priorities.
I 60
**	Priorities > 0 should be preemptive.
E 151
I 151
**  Message priority classes.
E 151
I 65
**
D 77
**	MsgPriority is the number of bytes in the message adjusted
E 77
I 77
D 151
**	CurEnv->e_msgpriority is the number of bytes in the message adjusted
E 77
**	by the message priority and the amount of time the message
**	has been sitting around.  Each priority point is worth
**	WKPRIFACT bytes of message, and each time we reprocess a
D 149
**	message the size gets reduced by WKTIMEFACT.
E 149
I 149
**	message the size gets reduced by WKTIMEFACT.  Recipients are
**	worth WKRECIPFACT.
E 151
I 151
**	The message class is read directly from the Priority: header
**	field in the message.
E 151
E 149
I 78
**
I 132
D 151
**	WKTIMEFACT is negative since jobs that fail once have a high
**	probability of failing again.  Making it negative tends to force
**	them to the back rather than the front of the queue, where they
**	only clog things.  Thanks go to Jay Lepreau at Utah for pointing
**	out the error in my thinking.
E 151
I 151
**	CurEnv->e_msgpriority is the number of bytes in the message plus
**	the creation time (so that jobs ``tend'' to be ordered correctly),
**	adjusted by the message class, the number of recipients, and the
**	amount of time the message has been sitting around.  This number
**	is used to order the queue.  Higher values mean LOWER priority.
E 151
**
I 151
**	Each priority class point is worth WkClassFact priority points;
**	each recipient is worth WkRecipFact priority points.  Each time
**	we reprocess a message the priority is adjusted by WkTimeFact.
**	WkTimeFact should normally decrease the priority so that jobs
**	that have historically failed will be run later; thanks go to
**	Jay Lepreau at Utah for pointing out the error in my thinking.
**
E 151
E 132
**	The "class" is this number, unadjusted by the age or size of
**	this message.  Classes with negative representations will have
**	error messages thrown away if they are not local.
E 78
E 65
E 60
*/

D 60
# define PRI_NORMAL	20
# define PRI_SECONDCL	10
# define PRI_THIRDCL	7
# define PRI_QUICK	24
# define PRI_PRIORITY	40
E 60
I 60
D 78
# define PRI_ALERT	20
# define PRI_QUICK	10
D 65
# define PRI_FIRSTCL	0
# define PRI_NORMAL	-4
E 65
I 65
# define PRI_FIRSTCL	3
E 78
I 78
D 100
# define PRI_ALERT	50
# define PRI_QUICK	30
# define PRI_FIRSTCL	10
E 78
# define PRI_NORMAL	0
E 65
# define PRI_SECONDCL	-10
D 78
# define PRI_THIRDCL	-20
E 78
I 78
# define PRI_THIRDCL	-40
# define PRI_JUNK	-100
E 100
I 100
struct priority
{
	char	*pri_name;	/* external name of priority */
	int	pri_val;	/* internal value for same */
};
E 100
E 78
E 60

I 100
EXTERN struct priority	Priorities[MAXPRIORITIES];
EXTERN int		NumPriorities;	/* pointer into Priorities */
D 151

E 100
D 65
EXTERN int	MsgPriority;		/* priority of this message */
E 65
I 65
# define WKPRIFACT	1800		/* bytes each pri point is worth */
D 132
# define WKTIMEFACT	400		/* bytes each time unit is worth */
E 132
I 132
# define WKTIMEFACT	(-600)		/* bytes each reprocessing is worth */
I 149
# define WKRECIPFACT	1000		/* bytes each recipient is worth */
E 151
E 149
E 132
D 77

EXTERN long	MsgPriority;		/* adjusted priority of this message */
E 65



/*
E 77
I 77
/*
E 77
E 59
**  Rewrite rules.
*/

struct rewrite
{
	char	**r_lhs;	/* pattern match */
	char	**r_rhs;	/* substitution value */
	struct rewrite	*r_next;/* next in chain */
};

D 25
struct rewrite	*RewriteRules;
E 25
I 25
D 29
struct rewrite	*RewriteRules[];
E 29
I 29
D 97
extern struct rewrite	*RewriteRules[];
E 97
I 97
EXTERN struct rewrite	*RewriteRules[MAXRWSETS];
E 97
E 29
E 25

D 22
# define MATCHANY	'\020'	/* match exactly one token */
# define MATCHONE	'\021'	/* match one or more tokens */
E 22
I 22
D 97
# define MATCHANY	'\020'	/* match one or more tokens */
# define MATCHONE	'\021'	/* match exactly one token */
# define MATCHCLASS	'\022'	/* match one token in a class */
I 55
# define MATCHREPL	'\023'	/* replacement on RHS for above */
E 97
I 97
/*
**  Special characters in rewriting rules.
**	These are used internally only.
**	The COND* rules are actually used in macros rather than in
**		rewriting rules, but are given here because they
**		cannot conflict.
*/
E 97
E 55
E 22

I 97
/* left hand side items */
# define MATCHZANY	'\020'	/* match zero or more tokens */
# define MATCHANY	'\021'	/* match one or more tokens */
# define MATCHONE	'\022'	/* match exactly one token */
# define MATCHCLASS	'\023'	/* match one token in a class */
I 116
D 141
# define MATCHNCLASS	'\034'	/* match anything not in class */
E 116
# define MATCHREPL	'\024'	/* replacement on RHS for above */
E 141
I 141
# define MATCHNCLASS	'\024'	/* match anything not in class */
# define MATCHREPL	'\025'	/* replacement on RHS for above */
E 141
I 137
# define MATCHLOOKUP	'\035'	/* look up and replace a sequence */
# define MATCHELOOKUP	'\036'	/* end of the sequence */
E 137

/* right hand side items */
E 97
D 141
# define CANONNET	'\025'	/* canonical net, next token */
# define CANONHOST	'\026'	/* canonical host, next token */
# define CANONUSER	'\027'	/* canonical user, next N tokens */
I 97
# define CALLSUBR	'\030'	/* call another rewriting set */
E 141
I 141
# define CANONNET	'\026'	/* canonical net, next token */
# define CANONHOST	'\027'	/* canonical host, next token */
# define CANONUSER	'\030'	/* canonical user, next N tokens */
# define CALLSUBR	'\031'	/* call another rewriting set */
E 141
E 97
E 14

I 74
D 97
# define CONDIF		'\030'	/* conditional if-then */
# define CONDELSE	'\031'	/* conditional else */
# define CONDFI		'\032'	/* conditional fi */
E 97
I 97
/* conditionals in macros */
D 141
# define CONDIF		'\031'	/* conditional if-then */
# define CONDELSE	'\032'	/* conditional else */
# define CONDFI		'\033'	/* conditional fi */
E 141
I 141
# define CONDIF		'\032'	/* conditional if-then */
# define CONDELSE	'\033'	/* conditional else */
# define CONDFI		'\034'	/* conditional fi */
E 141
I 136

I 139
/* bracket characters for host name lookup */
D 141
# define HOSTBEGIN	'\034'	/* hostname lookup begin */
# define HOSTEND	'\035'	/* hostname lookup end */
E 141
I 141
# define HOSTBEGIN	'\035'	/* hostname lookup begin */
# define HOSTEND	'\036'	/* hostname lookup end */
E 141

E 139
/* \001 is also reserved as the macro expansion character */
E 136
E 97
D 77

E 74


I 21
/*
E 77
I 77
/*
I 149
**  Information about hosts that we have looked up recently.
**
**	This stuff is 4.2/3bsd specific.
*/

# ifdef DAEMON
# ifdef VMUNIX

# define HOSTINFO	struct hostinfo

HOSTINFO
{
	char		*ho_name;	/* name of this host */
	struct in_addr	ho_inaddr;	/* internet address */
	short		ho_flags;	/* flag bits, see below */
	short		ho_errno;	/* error number on last connection */
	short		ho_exitstat;	/* exit status from last connection */
};


/* flag bits */
#define HOF_VALID	00001		/* this entry is valid */

# endif VMUNIX
# endif DAEMON
/*
E 149
E 77
**  Symbol table definitions
*/

struct symtab
{
	char		*s_name;	/* name to be entered */
D 31
	char		s_type;		/* general type (unused) */
	long		s_class;	/* bit-map of word classes */
E 31
I 31
	char		s_type;		/* general type (see below) */
E 31
	struct symtab	*s_next;	/* pointer to next in chain */
I 31
	union
	{
D 126
		long	sv_class;	/* bit-map of word classes */
E 126
I 126
D 149
		BITMAP	sv_class;	/* bit-map of word classes */
E 126
		ADDRESS	*sv_addr;	/* pointer to address header */
		MAILER	*sv_mailer;	/* pointer to mailer */
		char	*sv_alias;	/* alias */
E 149
I 149
		BITMAP		sv_class;	/* bit-map of word classes */
		ADDRESS		*sv_addr;	/* pointer to address header */
		MAILER		*sv_mailer;	/* pointer to mailer */
		char		*sv_alias;	/* alias */
# ifdef HOSTINFO
		HOSTINFO	sv_host;	/* host information */
# endif HOSTINFO
E 149
	}	s_value;
E 31
};

typedef struct symtab	STAB;

I 31
/* symbol types */
# define ST_UNDEF	0	/* undefined type */
# define ST_CLASS	1	/* class map */
# define ST_ADDRESS	2	/* an address in parsed format */
# define ST_MAILER	3	/* a mailer header */
# define ST_ALIAS	4	/* an alias */
I 149
# define ST_HOST	5	/* host information */
E 149

# define s_class	s_value.sv_class
D 71
# define s_addr		s_value.sv_addr
E 71
I 71
# define s_address	s_value.sv_addr
E 71
# define s_mailer	s_value.sv_mailer
# define s_alias	s_value.sv_alias
I 149
# define s_host		s_value.sv_host
E 149

E 31
extern STAB	*stab();

/* opcodes to stab */
# define ST_FIND	0	/* find entry */
# define ST_ENTER	1	/* enter if not there */
D 77



E 21

/*
E 77
I 77
/*
I 89
**  STRUCT EVENT -- event queue.
**
**	Maintained in sorted order.
I 95
**
**	We store the pid of the process that set this event to insure
**	that when we fork we will not take events intended for the parent.
E 95
*/

struct event
{
	time_t		ev_time;	/* time of the function call */
	int		(*ev_func)();	/* function to call */
	int		ev_arg;		/* argument to ev_func */
I 95
	int		ev_pid;		/* pid that set this event */
E 95
	struct event	*ev_link;	/* link to next item */
};

typedef struct event	EVENT;

EXTERN EVENT	*EventQueue;		/* head of event queue */
/*
E 89
E 77
I 43
D 114
**  Statistics structure.
*/

struct statistics
{
	time_t	stat_itime;		/* file initialization time */
	short	stat_size;		/* size of this structure */
	long	stat_nf[MAXMAILERS];	/* # msgs from each mailer */
	long	stat_bf[MAXMAILERS];	/* kbytes from each mailer */
	long	stat_nt[MAXMAILERS];	/* # msgs to each mailer */
	long	stat_bt[MAXMAILERS];	/* kbytes to each mailer */
};

D 47
extern struct statistics	Stat;
E 47
I 47
EXTERN struct statistics	Stat;
E 47
extern long			kbytes();	/* for _bf, _bt */
D 77




/*
E 77
I 77
/*
I 82
D 111
**  Operation modes
**	The default operation mode can be safely changed (except
**	that the default cannot be MD_DAEMON).
E 111
I 111
**  Operation and send modes
E 114
I 114
**  Operation, send, and error modes
E 114
**
**	The operation mode describes the basic operation of sendmail.
**	This can be set from the command line, and is "send mail" by
**	default.
**
**	The send mode tells how to send mail.  It can be set in the
**	configuration file.  It's setting determines how quickly the
**	mail will be delivered versus the load on your system.  If the
**	-v (verbose) flag is given, it will be forced to SM_DELIVER
**	mode.
**
D 114
**	The default send mode can be safely changed.
E 114
I 114
**	The error mode tells how to return errors.
E 114
E 111
*/

D 111
EXTERN char	Mode;		/* operation mode, see below */
E 111
I 111
EXTERN char	OpMode;		/* operation mode, see below */
E 111

D 111
#define MD_DELIVER	'a'		/* collect and deliver */
#define MD_FORK		'f'		/* verify & fork before delivery */
#define MD_QUEUE	'q'		/* collect & queue, don't deliver */
E 111
I 111
#define MD_DELIVER	'm'		/* be a mail sender */
#define MD_ARPAFTP	'a'		/* old-style arpanet protocols */
#define MD_SMTP		's'		/* run SMTP on standard input */
E 111
#define MD_DAEMON	'd'		/* run as a daemon */
#define MD_VERIFY	'v'		/* verify: don't collect or deliver */
I 104
#define MD_TEST		't'		/* test mode: resolve addrs only */
I 110
#define MD_INITALIAS	'i'		/* initialize alias database */
#define MD_PRINT	'p'		/* print the queue */
#define MD_FREEZE	'z'		/* freeze the configuration file */
E 110
E 104

I 166
/*
**  The hack below is to remember the original OpMode on startup.
**  MD_DAEMON is later changed to MD_SMTP, and we sometimes want to
**  know whether we started out as a daemon.
*/
EXTERN char	OrigOpMode;
E 166
D 111
#define MD_DEFAULT	MD_DELIVER	/* default operation mode */
E 111
I 111

I 166

E 166
EXTERN char	SendMode;	/* send mode, see below */

#define SM_DELIVER	'i'		/* interactive delivery */
#define SM_QUICKD	'j'		/* deliver w/o queueing */
#define SM_FORK		'b'		/* deliver in background */
#define SM_QUEUE	'q'		/* queue, don't deliver */
#define SM_VERIFY	'v'		/* verify only (used internally) */
I 114

I 134
/* used only as a parameter to sendall */
#define SM_DEFAULT	'\0'		/* unspecified, use SendMode */

E 134

EXTERN char	ErrorMode;	/* error mode, see below */

#define EM_PRINT	'p'		/* print errors */
#define EM_MAIL		'm'		/* mail back errors */
#define EM_WRITE	'w'		/* write back errors */
#define EM_BERKNET	'e'		/* special berknet processing */
#define EM_QUIET	'q'		/* don't print messages (stat only) */
I 154

/* offset used to issure that the error messages for name server error
 * codes are unique.
 */
#define	MAX_ERRNO	100
I 166

/* alias attributes */
struct aliasattrs {
	short	aa_flags;
	short	aa_uid;
	short	aa_gid;
};
#define	AA_HASUID	0x0001		/* alias has associated uid/gid */
#define	AA_RESTRICTED	0x0002		/* not accessible to mere mortals */
#define	AA_NOEXPN	0x0004		/* don't allow EXPN */
E 166
E 154
E 114
E 111
I 100
/*
D 101
**  Options
**
**	These are assorted options that can be set from the configuration
**	file.
*/

EXTERN char	*Option[128];	/* miscellaneous option values */

/* option values */
# define	OPT_QUEUEALL	'q'	/* force all messages to queue */
E 100
/*
E 101
E 82
E 77
E 43
E 9
**  Global variables.
*/

D 5
extern char	ArpaFmt;	/* if set, message is in arpanet fmt */
extern char	FromFlag;	/* if set, "From" person is explicit */
extern char	Debug;		/* if set, debugging info */
extern char	MailBack;	/* mail back response on error */
D 2
extern char	EchoBack;	/* echo the message on error */
E 2
I 2
extern char	BerkNet;	/* called from BerkNet */
E 2
extern char	WriteBack;	/* write back response on error */
extern char	NoAlias;	/* if set, don't do any aliasing */
extern char	ForceMail;	/* if set, mail even if already got a copy */
extern char	MeToo;		/* send to the sender also */
extern char	Error;		/* set if errors */
E 5
I 5
D 33
extern bool	ArpaFmt;	/* if set, message is in arpanet fmt */
E 33
I 33
D 43
extern int	ArpaMode;	/* ARPANET handling mode */
E 43
E 33
D 47
extern bool	FromFlag;	/* if set, "From" person is explicit */
D 26
extern bool	Debug;		/* if set, debugging info */
E 26
extern bool	MailBack;	/* mail back response on error */
extern bool	BerkNet;	/* called from BerkNet */
extern bool	WriteBack;	/* write back response on error */
extern bool	NoAlias;	/* if set, don't do any aliasing */
extern bool	ForceMail;	/* if set, mail even if already got a copy */
extern bool	MeToo;		/* send to the sender also */
D 6
extern bool	Error;		/* set if errors */
E 6
D 19
extern bool	UseMsgId;	/* put msg-id's in all msgs [conf.c] */
E 19
extern bool	IgnrDot;	/* don't let dot end messages */
extern bool	SaveFrom;	/* save leading "From" lines */
I 23
extern bool	Verbose;	/* set if blow-by-blow desired */
I 40
extern bool	GrabTo;		/* if set, get recipients from msg */
I 41
extern bool	DontSend;	/* mark recipients as QDONTSEND */
I 44
extern bool	NoReturn;	/* don't return letter to sender */
I 46
extern int	OldUmask;	/* umask when sendmail starts up */
E 46
E 44
E 41
E 40
I 26
extern int	Debug;		/* debugging level */
E 26
E 23
I 6
extern int	Errors;		/* set if errors */
E 6
E 5
extern int	ExitStat;	/* exit status code */
I 43
extern int	ArpaMode;	/* ARPANET handling mode */
extern long	MsgSize;	/* size of the message in bytes */
E 47
I 47
EXTERN bool	FromFlag;	/* if set, "From" person is explicit */
D 114
EXTERN bool	MailBack;	/* mail back response on error */
EXTERN bool	BerkNet;	/* called from BerkNet */
EXTERN bool	WriteBack;	/* write back response on error */
E 114
EXTERN bool	NoAlias;	/* if set, don't do any aliasing */
EXTERN bool	ForceMail;	/* if set, mail even if already got a copy */
EXTERN bool	MeToo;		/* send to the sender also */
EXTERN bool	IgnrDot;	/* don't let dot end messages */
EXTERN bool	SaveFrom;	/* save leading "From" lines */
EXTERN bool	Verbose;	/* set if blow-by-blow desired */
EXTERN bool	GrabTo;		/* if set, get recipients from msg */
D 114
EXTERN bool	DontSend;	/* mark recipients as QDONTSEND */
E 114
EXTERN bool	NoReturn;	/* don't return letter to sender */
I 56
D 82
EXTERN bool	Daemon;		/* running as a daemon */
E 82
I 57
D 111
EXTERN bool	Smtp;		/* using SMTP over connection */
E 111
EXTERN bool	SuprErrs;	/* set if we are suppressing errors */
D 59
EXTERN bool	HasXscrpt;	/* set if we have a transcript */
E 59
I 59
D 77
EXTERN bool	QueueUp;	/* queue this message for future xmission */
E 77
D 73
EXTERN bool	QueueRun;	/* currently running something from the queue */
E 73
I 73
EXTERN bool	QueueRun;	/* currently running message from the queue */
E 73
I 61
EXTERN bool	HoldErrs;	/* only output errors to transcript */
D 111
EXTERN bool	ArpaMode;	/* set if running arpanet protocol */
E 111
I 68
D 82
EXTERN bool	ForkOff;	/* fork after initial verification */
E 82
D 77
EXTERN bool	OldStyle;	/* spaces (not commas) delimit addresses */
E 77
I 69
EXTERN bool	NoConnect;	/* don't connect to non-local mailers */
I 72
D 77
EXTERN bool	RetReceipt;	/* give a return receipt if delivery occurs */
EXTERN bool	SendReceipt;	/* actually send a receipt back */
E 77
I 73
D 113
EXTERN bool	FatalErrors;	/* set if fatal errors during processing */
E 113
I 102
D 103
extern bool	SuperSafe;	/* be extra careful, despite cost [conf.c] */
E 102
E 73
E 72
E 69
E 68
E 61
D 93
extern time_t	TimeOut;	/* time until timeout */
E 93
I 93
extern time_t	TimeOut;	/* time until timeout [conf.c] */
E 103
I 103
EXTERN bool	SuperSafe;	/* be extra careful, even if expensive */
I 149
EXTERN bool	ForkQueueRuns;	/* fork for each job when running the queue */
E 149
I 105
D 142
EXTERN bool	SafeAlias;	/* alias file must have "@:@" to be complete */
E 142
I 110
EXTERN bool	AutoRebuild;	/* auto-rebuild the alias database as needed */
I 155
EXTERN bool	CheckAliases;	/* parse addresses during newaliases */
I 162
EXTERN bool	UseNameServer;	/* use internet domain name server */
E 162
E 155
I 142
EXTERN int	SafeAlias;	/* minutes to wait until @:@ in alias file */
E 142
E 110
E 105
EXTERN time_t	TimeOut;	/* time until timeout */
E 103
E 93
E 59
EXTERN FILE	*InChannel;	/* input connection */
EXTERN FILE	*OutChannel;	/* output connection */
D 115
EXTERN FILE	*TempFile;	/* mail temp file */
I 61
EXTERN FILE	*Xscript;	/* mail transcript file */
E 115
E 61
E 57
EXTERN int	RealUid;	/* when Daemon, real uid of caller */
EXTERN int	RealGid;	/* when Daemon, real gid of caller */
I 68
D 93
extern int	DefUid;		/* default uid to run as */
extern int	DefGid;		/* default gid to run as */
E 93
I 93
D 103
extern int	DefUid;		/* default uid to run as [conf.c] */
extern int	DefGid;		/* default gid to run as [conf.c] */
E 103
I 103
EXTERN int	DefUid;		/* default uid to run as */
EXTERN int	DefGid;		/* default gid to run as */
E 103
E 93
E 68
E 56
EXTERN int	OldUmask;	/* umask when sendmail starts up */
D 88
EXTERN int	Debug;		/* debugging level */
E 88
D 73
EXTERN int	Errors;		/* set if errors */
E 73
I 73
EXTERN int	Errors;		/* set if errors (local to single pass) */
E 73
EXTERN int	ExitStat;	/* exit status code */
D 61
EXTERN int	ArpaMode;	/* ARPANET handling mode */
E 61
D 57
EXTERN long	MsgSize;	/* size of the message in bytes */
E 57
I 57
D 114
EXTERN int	HopCount;	/* hop count */
E 114
EXTERN int	AliasLevel;	/* depth of aliasing */
I 85
EXTERN int	MotherPid;	/* proc id of parent process */
I 97
EXTERN int	LineNumber;	/* line number in current input */
I 103
D 135
EXTERN int	ReadTimeout;	/* timeout on reads */
E 135
I 135
EXTERN time_t	ReadTimeout;	/* timeout on reads */
E 135
EXTERN int	LogLevel;	/* level of logging to perform */
I 107
EXTERN int	FileMode;	/* mode on files */
I 149
EXTERN int	QueueLA;	/* load average starting forced queueing */
EXTERN int	RefuseLA;	/* load average refusing connections are */
EXTERN int	QueueFactor;	/* slope of queue function */
E 149
E 107
E 103
E 97
E 85
I 59
EXTERN time_t	QueueIntvl;	/* intervals between running the queue */
E 59
D 77
EXTERN char	*OrigFrom;	/* the From: line read from the message */
EXTERN char	*To;		/* the target person */
E 77
D 153
EXTERN char	*HostName;	/* name of this host for SMTP messages */
E 153
E 57
E 47
E 43
D 59
extern char	InFileName[];	/* input file name */
extern char	Transcript[];	/* the transcript file name */
E 59
I 59
D 81
EXTERN char	*InFileName;	/* input file name */
E 81
D 113
EXTERN char	*Transcript;	/* the transcript file name */
E 113
I 103
EXTERN char	*AliasFile;	/* location of alias file */
EXTERN char	*HelpFile;	/* location of SMTP help file */
EXTERN char	*StatFile;	/* location of statistics summary */
EXTERN char	*QueueDir;	/* location of queue directory */
I 114
EXTERN char	*FileName;	/* name to print on error messages */
E 114
I 105
D 149
EXTERN char	*TrustedUsers[MAXTRUST+1];	/* list of trusted users */
E 149
I 149
EXTERN char	*SmtpPhase;	/* current phase in SMTP processing */
I 153
EXTERN char	*MyHostName;	/* name of this host for SMTP messages */
E 153
EXTERN char	*RealHostName;	/* name of host we are talking to */
I 163
EXTERN char	*RealHostAddr;	/* address of that host as "[a.b.c.d]" */
E 163
I 153
EXTERN char	*CurHostName;	/* current host we are dealing with */
I 164
EXTERN bool	FromInet;	/* coming from Internet */
EXTERN bool	NoInetRelay;	/* do not relay mail coming from Inet */
E 164
E 153
E 149
E 105
EXTERN jmp_buf	TopFrame;	/* branch-to-top-of-loop-on-error frame */
EXTERN bool	QuickAbort;	/*  .... but only if we want a quick abort */
E 103
D 93
extern char	*XcriptFile;	/* template for Transcript */
extern char	*AliasFile;	/* location of alias file */
extern char	*ConfFile;	/* location of configuration file */
extern char	*StatFile;	/* location of statistics summary */
extern char	*QueueDir;	/* location of queue directory */
I 86
D 92
EXTERN char	*ControlFile;	/* when queued, name of control file temp */
I 88
EXTERN char	*MsgId;		/* Message-Id: for this message */
E 92
I 91
extern char	Arpa_Info[];	/* the message number for Arpanet info */
E 93
I 93
D 109
extern char	*XcriptFile;	/* template for Transcript [conf.c] */
E 109
D 103
extern char	*AliasFile;	/* location of alias file [conf.c] */
E 103
extern char	*ConfFile;	/* location of configuration file [conf.c] */
I 109
extern char	*FreezeFile;	/* location of frozen memory image [conf.c] */
E 109
D 103
extern char	*StatFile;	/* location of statistics summary [conf.c] */
extern char	*QueueDir;	/* location of queue directory [conf.c] */
E 103
extern char	Arpa_Info[];	/* the reply code for Arpanet info [conf.c] */
I 106
D 149
extern char	SpaceSub;	/* substitution for <lwsp> [conf.c] */
E 149
I 149
extern ADDRESS	NullAddress;	/* a null (template) address [main.c] */
EXTERN char	SpaceSub;	/* substitution for <lwsp> */
I 151
EXTERN int	WkClassFact;	/* multiplier for message class -> priority */
EXTERN int	WkRecipFact;	/* multiplier for # of recipients -> priority */
EXTERN int	WkTimeFact;	/* priority offset each time this job is run */
E 151
EXTERN int	CheckPointLimit;	/* deliveries before checkpointing */
I 156
D 157
EXTERN short	nmx;			/* number of MX RRs */
E 157
I 157
EXTERN int	Nmx;			/* number of MX RRs */
E 157
E 156
EXTERN char	*PostMasterCopy;	/* address to get errs cc's */
I 156
D 157
EXTERN char	*mxhosts[MAXMXHOSTS+1];	/* for MX RRs */
E 157
I 157
EXTERN char	*MxHosts[MAXMXHOSTS+1];	/* for MX RRs */
E 157
E 156
EXTERN char	*TrustedUsers[MAXTRUST+1];	/* list of trusted users */
I 152
EXTERN char	*UserEnviron[MAXUSERENVIRON+1];	/* saved user environment */
I 165
EXTERN long	MaxMessageSize;	/* configurable hard limit on message size */
E 165
E 152
E 149
E 106
E 93
E 91
E 88
E 86
E 59
I 36
D 47
extern FILE	*TempFile;	/* mail temp file */
E 36
I 5
D 9
extern char	MsgId[];	/* the message id for this message */
E 9
I 9
D 19
extern char	*MsgId;		/* the message id for this message */
extern char	*Date;		/* origination date (UNIX format) */
E 19
E 9
E 5
D 10
extern addrq	From;		/* the person it is from */
E 10
I 10
extern ADDRESS	From;		/* the person it is from */
E 10
extern char	*To;		/* the target person */
extern int	HopCount;	/* hop count */
I 15
extern long	CurTime;	/* time of this message */
D 38
extern char	FromLine[];	/* a UNIX-style From line for this message */
E 38
I 31
extern int	AliasLevel;	/* depth of aliasing */
E 47
I 47
D 57
EXTERN FILE	*TempFile;	/* mail temp file */
E 57
D 77
EXTERN ADDRESS	From;		/* the person it is from */
I 64
EXTERN ADDRESS	*SendQueue;	/* list of message recipients */
E 64
D 57
EXTERN char	*To;		/* the target person */
EXTERN int	HopCount;	/* hop count */
E 57
I 57
EXTERN long	MsgSize;	/* size of the message in bytes */
E 77
E 57
D 59
EXTERN long	CurTime;	/* time of this message */
E 59
I 59
D 94
EXTERN time_t	CurTime;	/* time of this message */
E 94
I 87
D 90
EXTERN jmp_buf	TickFrame;	/* frame for clock ticks to jump to */
E 90
I 90
D 103
EXTERN jmp_buf	TopFrame;	/* branch-to-top-of-loop-on-error frame */
EXTERN bool	QuickAbort;	/*  .... but only if we want a quick abort */
E 90
D 93
extern int	ReadTimeout;	/* timeout on reads before clock ticks */
I 88
extern int	LogLevel;	/* level of logging to perform */
E 93
I 93
extern int	ReadTimeout;	/* timeout on reads [conf.c] */
extern int	LogLevel;	/* level of logging to perform [conf.c] */
E 103
E 93
/*
**  Trace information
*/
E 88
E 87
E 59
D 57
EXTERN int	AliasLevel;	/* depth of aliasing */
EXTERN char	*OrigFrom;	/* the From: line read from the message */
EXTERN bool	SuprErrs;	/* set if we are suppressing errors */
EXTERN bool	HasXscrpt;	/* set if we have a transcript */
E 57
E 47
E 31
E 15

I 88
/* trace vector and macros for debugging flags */
EXTERN u_char	tTdvect[100];
# define tTd(flag, level)	(tTdvect[flag] >= level)
# define tTdlevel(flag)		(tTdvect[flag])
/*
**  Miscellaneous information.
*/
E 88

# include	<sysexits.h>

I 124

/*
**  Some in-line functions
*/

/* set exit status */
E 124
D 10
# define flagset(bits, word)	((bits) & (word))
E 10
D 131
# define setstat(s)		{ if (ExitStat == EX_OK) ExitStat = s; }
E 131
I 131
#define setstat(s)	{ \
				if (ExitStat == EX_OK || ExitStat == EX_TEMPFAIL) \
					ExitStat = s; \
			}
E 131
I 28
D 125

I 124
/* line terminator appropriate for a given mailer */
# define crlf(m)		(bitset(M_CRLF, (m)->m_flags) ? "\r\n" : "\n")
E 125
E 124

D 124
/* useful functions */
E 124
I 124
/* make a copy of a string */
D 131
# define newstr(s)		strcpy(xalloc(strlen(s) + 1), s)
E 131
I 131
#define newstr(s)	strcpy(xalloc(strlen(s) + 1), s)
I 149

#define STRUCTCOPY(s, d)	d = s
E 149
E 131
E 124

D 124
extern char	*newstr();
E 124
I 124

/*
**  Declarations of useful functions
*/

E 124
D 117
extern ADDRESS	*parse();
E 117
I 117
extern ADDRESS	*parseaddr();
E 117
extern char	*xalloc();
D 79
extern char	*expand();
E 79
extern bool	sameaddr();
I 76
extern FILE	*dfopen();
I 89
extern EVENT	*setevent();
extern char	*sfgets();
I 92
extern char	*queuename();
I 94
extern time_t	curtime();
I 158

/*
**  HACK to fix bug in C compiler on CCI
*/

#undef isascii
D 159
#define isascii(x)	(((x) & ~0177) != 0)
E 159
I 159
#define isascii(x)	(((x) & ~0177) == 0)
E 159
E 158
I 121
D 124
extern char	*crlf();
E 124
E 121
E 94
E 92
E 89
E 76
E 28
D 5

# include "useful.h"

# define BADMAIL	YES	/* mail doesn't know about new returncodes */
E 5
E 1
