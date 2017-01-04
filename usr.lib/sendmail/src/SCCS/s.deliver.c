h17342
s 00001/00001/01482
d D 5.25 06/05/19 21:47:27 msokolov 212 211
c implemented alias attributes
e
s 00002/00001/01481
d D 5.24 00/04/03 09:51:30 msokolov 211 210
c Check the sender address for a null string and change it to "<>" if it is,
c as we can't handle null strings very well.
e
s 00021/00005/01461
d D 5.23 88/09/20 22:15:11 eric 210 209
c add I option to insist on Internet domain server; add NAMED_BIND
c compile option to compile in named routines.
e
s 00011/00009/01455
d D 5.22 88/06/30 14:58:40 bostic 209 208
c install approved copyright notice
e
s 00001/00010/01463
d D 5.21 88/05/05 12:40:12 bostic 208 207
c remove ifdef's on FIOCLEX; never got turned on since sys/ioctl.h
c wasn't included
e
s 00046/00030/01427
d D 5.20 88/04/19 13:45:58 bostic 207 206
c unless interactive, don't pound name server; restructure getmxrr logic
c fix "Connecting to" messages
e
s 00005/00005/01452
d D 5.19 88/04/01 16:36:34 bostic 206 205
c if get MX record, note what site we're *really* connecting too
e
s 00022/00044/01435
d D 5.18 88/04/01 15:36:45 bostic 205 204
c map certain errors in getmxrr; minor speedup/cleanup
e
s 00000/00006/01479
d D 5.17 88/03/24 09:00:08 bostic 204 203
c MXDOMAIN is always in place
e
s 00016/00010/01469
d D 5.16 88/03/13 19:51:48 bostic 203 202
c add Berkeley specific header
e
s 00001/00001/01478
d D 5.15 87/12/12 17:29:28 bostic 202 201
c add h_errno as an extern
e
s 00007/00001/01472
d D 5.14 87/07/27 17:08:10 bostic 201 200
c bug report 4.3BSD/usr.lib/50; fix user@[a.b.c.d]
e
s 00001/00001/01472
d D 5.13 86/10/23 10:10:58 eric 200 199
c Fix security bug allowing writing to arbitrary files; from Bart Miller
c at U. Wisconsin.
e
s 00011/00011/01462
d D 5.12 86/10/14 17:25:09 eric 199 198
c make global variables begin with cap letters -- Please!!
e
s 00000/00000/01473
d D 5.11 86/07/21 11:21:19 bloom 198 195
i 197 196
c MX branch merge
e
s 00023/00030/01450
d D 5.10.1.2 86/07/21 11:06:34 bloom 197 196
c clean up code a bit, move MX query, getmxrr is smarter
e
s 00055/00021/01425
d D 5.10.1.1 86/07/01 15:17:03 bloom 196 195
c add Name Server MX support from satz@su-sierra.arpa, fix macro usage
e
s 00006/00000/01440
d D 5.10 86/03/02 14:05:41 eric 195 194
c always ignore SIGCHLD in openmailer; get SccsId correct in alias.c
e
s 00001/00001/01439
d D 5.9 85/12/17 23:53:29 eric 194 193
m 
c lint
e
s 00016/00005/01424
d D 5.8 85/11/22 11:31:05 miriam 193 192
m 
c Call errstring() to print out Name Server error code TRY_AGAIN message -
c "Host Name Lookup Failure".
e
s 00006/00000/01423
d D 5.7 85/09/30 21:34:19 eric 192 191
m 
c clean up some aspects of error message display
e
s 00001/00001/01422
d D 5.6 85/09/24 15:09:43 eric 191 190
m 
c don't step on user environment
e
s 00029/00007/01394
d D 5.5 85/09/19 00:45:16 eric 190 189
m 
c SMI changes (somewhat)
e
s 00003/00002/01398
d D 5.4 85/06/16 16:03:41 eric 189 188
m 
c arrange for a useful error message if the mailer fork fails
e
s 00004/00004/01396
d D 5.3 85/06/08 00:15:07 eric 188 187
m 
c lint
e
s 00000/00002/01400
d D 5.2 85/06/07 22:05:38 miriam 187 186
m 
c Resolve duplicate SccsId
e
s 00014/00000/01388
d D 5.1 85/06/07 14:40:15 dist 186 185
m 
c Add copyright
e
s 00017/00001/01371
d D 4.10 85/05/24 10:58:08 eric 185 184
m 
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00004/00001/01368
d D 4.9 84/08/11 17:55:46 eric 184 183
m 
c changes from Tom Ferrin <ucsfcgl!tef>: don't drop messages on the floor
c if no local mailer available; give real "errno" message in syserr.
e
s 00002/00002/01367
d D 4.8 84/08/11 16:51:02 eric 183 182
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00005/00000/01364
d D 4.7 84/08/11 13:22:27 eric 182 181
m 
c E flag will > escape From lines (for files)
e
s 00010/00011/01354
d D 4.6 84/03/11 16:53:44 eric 181 180
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00013/00020/01352
d D 4.5 83/12/27 22:51:03 eric 180 179
m 
c don't close files immediately before exec of mailer so that we can log;
c use FIOCLEX instead.  Suggested by Tom Ferrin, UCSF CGL.
e
s 00001/00001/01371
d D 4.4 83/11/13 18:07:10 eric 179 178
m 
c Fixes two nasty problems, both pointed out by Bill Nowicki at Stanford:
c I/O errors on input in collect would cause infinite loops, and a protocol
c error (or other error that would call smtpquit abnormally) would cause
c core dumps
e
s 00003/00012/01369
d D 4.3 83/10/01 16:57:09 eric 178 177
m 
c clean up error handling in general; make sure that something gets logged
c in the transcript if the connection cannot be established; clean up Teus
c Hagen's mod to arpadate.c to match the sendmail coding style.
e
s 00013/00001/01368
d D 4.2 83/08/28 14:44:04 eric 177 176
m 
c Refuse to talk to yourself (i.e., reject HELO packets with your own name).
c Add two thresholds -- option 'x' is the load average at which messages are
c queued rather than delivered (default 12); option 'X' is the load average
c at which incoming TCP connections are refused (default 25).
e
s 00000/00000/01369
d D 4.1 83/07/25 19:44:34 eric 176 175
m 
c 4.2 release version
e
s 00003/00001/01366
d D 3.154 83/05/20 11:46:44 eric 175 174
m 238
m 239
c Don't stack processes when VRFY fails.
c Give an error message on multiple RCPT commands with a bad address.
e
s 00001/00001/01366
d D 3.153 83/05/04 11:29:05 eric 174 173
m 235
c fix botch in 3.338 -- arguments reversed
e
s 00010/00010/01357
d D 3.152 83/05/04 11:15:42 eric 173 172
m 235
c Don't send domain-based UUCP addresses to UGLYUUCP hosts
e
s 00005/00001/01362
d D 3.151 83/04/30 15:13:14 eric 172 171
m 
c lint
e
s 00003/00000/01360
d D 3.150 83/04/17 17:14:45 eric 171 170
m 221
c fix bogus errno problems
e
s 00011/00000/01349
d D 3.149 83/02/20 12:28:40 eric 170 169
m 190
c Avoid loops in the auto-closedown code
e
s 00007/00000/01342
d D 3.148 83/02/03 07:53:34 eric 169 168
m 168
c Make mailer size limits a per-mailer parameter (M field in the mailer
c descriptor)
e
s 00010/00010/01332
d D 3.147 83/02/02 12:51:59 eric 168 167
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00009/00014/01333
d D 3.146 83/01/15 17:39:59 eric 167 166
m 149
c be sure everything gets appropriately externalized; canonname goes away,
c since everything is now done by remotename
e
s 00023/00033/01324
d D 3.145 83/01/06 10:44:19 eric 166 165
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00001/00000/01356
d D 3.144 83/01/04 19:53:04 eric 165 164
m 
c externalize $g macro using ruleset 4 also
e
s 00001/00001/01355
d D 3.143 83/01/04 18:51:46 eric 164 163
m 
c Don't try to drop our controlling TTY except when we are starting up a
c daemon; this can cause UUCP jobs to hang waiting for carrier on a dialin
c line (completely contrary to the intent).  Many thanks to Keith Sklower
c for pointing this one out.  However, that damned parameter to disconnect()
c has reappeared!
e
s 00000/00004/01356
d D 3.142 83/01/04 17:44:48 eric 163 162
m 
c Ignore SIGPIPE early (in main rather than in deliver) so that rude hosts
c that close the connection early don't cause us to die -- in particular,
c CMU-CS-A (nee CMU-10A) was doing this after the DATA command; the problem
c went away quite mysteriously, so I have no idea why it happened
e
s 00013/00006/01347
d D 3.141 83/01/04 13:10:04 eric 162 161
m 
c change format of deferred message to be consistent with other messages
e
s 00037/00010/01316
d D 3.140 83/01/03 18:00:50 eric 161 160
m 
c give more useful error messages (including the errno that caused
c a temporary failure); reflect these messages out to mailq
e
s 00041/00010/01285
d D 3.139 83/01/03 13:01:18 eric 160 159
m 
c process timeouts like normal errors, so that they will get delivered to
c the correct address (i.e., the Errors-To: address)
e
s 00016/00013/01279
d D 3.138 83/01/01 21:24:54 eric 159 158
m 123
c Put CRLF on all lines in user SMTP.  Pass this info down to
c innumerable routines.
e
s 00002/00002/01290
d D 3.137 82/12/13 18:23:45 eric 158 157
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00028/00012/01264
d D 3.136 82/12/05 13:44:25 eric 157 156
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00045/00030/01231
d D 3.135 82/11/28 16:00:05 eric 156 155
m 
c implement SMTP auto-shutdown on 421 codes; clean up some error processing
c items, particularly in SMTP; don't reinstantiate error message bodies after
c queueing; other minor changes.  This is all cleanup from 3.253.
e
s 00001/00001/01260
d D 3.134 82/11/28 10:21:48 eric 155 154
m 
c fix a number of problems left over from yesterday's delta.  The big
c triumph is being able to delete the parameter from disconnect().
e
s 00154/00456/01107
d D 3.133 82/11/28 00:18:36 eric 154 153
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00000/00058/01563
d D 3.132 82/11/24 18:43:20 eric 153 152
m 
c lint it
e
s 00020/00047/01601
d D 3.131 82/11/24 17:14:10 eric 152 151
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00017/00010/01631
d D 3.130 82/11/18 08:55:49 eric 151 150
m 060,
m 073
c disconnect input, output, signals, etc. when running in background
e
s 00071/00009/01570
d D 3.129 82/11/17 09:34:19 eric 150 149
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00004/00000/01575
d D 3.128 82/11/14 15:13:17 eric 149 148
m 074
c fix quote processing on program mailers
e
s 00006/00006/01569
d D 3.127 82/11/13 17:58:25 eric 148 147
m 021
c #ifdef VFORK => #ifdef VMUNIX
e
s 00002/00002/01573
d D 3.126 82/11/07 16:13:47 eric 147 146
m 041
c make all mailer output go to the transcript if running server smtp; this
c has the effect of making some significant changes in the output structure
c to handle such things as -em and -as together
e
s 00009/00003/01566
d D 3.125 82/11/03 09:48:09 eric 146 145
m 049
c Arrange to strip quote bits in message header; move SPACESUB into
c conf.c; change SpaceSub to unquoted dot
e
s 00001/00001/01568
d D 3.124 82/10/25 08:22:55 eric 145 144
m 040
c Don't send closing protocol to SMTP if you haven't opened the
c connection; this happens if checkcompat fails on the only recipient.
e
s 00001/00001/01568
d D 3.123 82/10/16 13:43:00 eric 144 143
m 024
c Fix debug statement in sendall
e
s 00030/00010/01539
d D 3.122 82/10/11 09:50:59 eric 143 142
m 016
c have auto-queueups print a polite message in the log (rather than an
c obnoxious "Temporary Failure").  Adds a new routine "logdelivery".
e
s 00002/00000/01547
d D 3.121 82/10/09 19:06:05 eric 142 141
m 002
c Handle Reverse-Path in some reasonable way.  You must put the 'X'
c flag (M_FULLSMTP) in the local mailer's flags to get this line.
e
s 00009/00004/01538
d D 3.120 82/10/09 18:10:46 eric 141 140
m 013
c print a status indication when a message is autoqueued, either from
c a -bq flag or a NoConnect
e
s 00002/00001/01540
d D 3.119 82/10/09 17:21:58 eric 140 139
m 008
c Force -v override of deferred connect
e
s 00001/00001/01540
d D 3.118 82/10/09 17:10:12 eric 139 138
m 004
c Only put the "from" person on the error queue if an error actually
c occured -- prevents many "duplicate supressed" messages, etc.
e
s 00002/00000/01539
d D 3.117 82/09/26 14:45:15 eric 138 137
c completely instantiate queue files for all mail, even if not needed;
c fix a bug that would probably come up once every ten years in creating
c the queue id.  should merge argv flag processing with option processing.
e
s 00024/00004/01515
d D 3.116 82/09/24 09:37:35 eric 137 136
c arrange to be able to define options; put precedences in .cf file;
c send errors to an Errors-To: field; fix a serious bug causing mail
c to not be delivered to anyone if there were any errors.
e
s 00008/00003/01511
d D 3.115 82/09/21 10:08:39 eric 136 135
c output headers with commas into the queue
e
s 00005/00001/01509
d D 3.114 82/09/16 20:23:49 eric 135 134
c drop ":...;" stuff -- it screws it up aliases; pass parameters to
c subroutines (this also adds $@ and $: features to subr calls); check
c overflow of "tobuf" on smtp deliveries, which caused core dumps on
c large mailing lists
e
s 00002/00003/01508
d D 3.113 82/09/12 16:42:42 eric 134 133
c change inheritance for macros in envelopes; be able to canonicalize
c non-domained names by appending domain from sender; call ruleset 3
c explicitly before doing other rulesets; some general cleanup.
e
s 00001/00003/01510
d D 3.112 82/09/08 23:55:12 eric 133 132
c fix stupid bug in wait code to dispose of "Interrupted system call" message
e
s 00007/00002/01506
d D 3.111 82/09/08 21:18:40 eric 132 131
c try to avoid "Interrupted system call" on wait in deliver and on
c writes; fix returned message to have proper sender; handle extra
c mailer output more cleverly.
e
s 00005/00001/01503
d D 3.110 82/09/06 19:54:45 eric 131 130
c more hacking on oldstyle -- always assume sender fields are in new
c style so that locally generated fields are edited correctly.
e
s 00001/00001/01503
d D 3.109 82/09/06 18:46:57 eric 130 129
c fix botch in "at"s in headers
e
s 00009/00023/01495
d D 3.108 82/09/06 16:23:52 eric 129 128
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00030/00067/01488
d D 3.107 82/09/05 18:02:57 eric 128 127
c change from m_from (macro from rewrite) to using a pair of rewriting
c rules; convert Return-Receipt-To: and Precedence: to NBS standard;
c correctly process all sender fields
e
s 00022/00029/01533
d D 3.106 82/08/31 10:05:16 eric 127 126
c clean up reply code processing some more; in particular, give more
c detail in many messages.  process connection failures correctly.
e
s 00011/00001/01551
d D 3.105 82/08/29 23:31:10 eric 126 125
c handle comments and quotes in headers; still doesn't deal with
c backslashes however -- prescan should be cleaned up to deal with
c this case.  it turns out there are many bugs in prescan; it should
c be extensively rewritten.
e
s 00003/00001/01549
d D 3.104 82/08/29 16:52:04 eric 125 124
c do a better job at interpreting SMTP reply codes
e
s 00001/00001/01549
d D 3.103 82/08/25 11:20:31 eric 124 123
c clean up time manipulation to always be current; assign job
c id's earlier to make sure there is always one with a message.
e
s 00004/00006/01546
d D 3.102 82/08/24 19:40:59 eric 123 122
c log more info (on log level 11); try to detect wild accept loops;
c some minor cleanup and debugging checks; fix NoConnect option to;
c only apply to expensive mailers (regardless of sendqueue order)
e
s 00009/00002/01543
d D 3.101 82/08/23 11:58:54 eric 122 121
c clean up queueing; log time in queue.
c **** This delta invalidates mqueue files ****
e
s 00011/00004/01534
d D 3.100 82/08/22 19:02:10 eric 121 120
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00005/00000/01533
d D 3.99 82/08/17 16:06:55 eric 120 119
c fix verify mode (only worked in verbose mode)
e
s 00140/00108/01393
d D 3.98 82/08/15 11:55:04 eric 119 118
c split off "commaize()" routine; fix bug that caused garbage in headers
e
s 00001/00092/01500
d D 3.97 82/08/08 16:54:40 eric 118 117
c move remotename() to parse.c; log errors at a higher level than successes
e
s 00012/00019/01580
d D 3.96 82/08/08 01:01:12 eric 117 116
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00034/00006/01565
d D 3.95 82/08/07 11:12:38 eric 116 115
c Fix address rewriting so that multiple spaces and tabs work properly
e
s 00002/00001/01569
d D 3.94 82/07/05 20:54:39 eric 115 114
c improve debugging: flush transcript before doing things that might
c take a long time; add some info to debugging output
e
s 00003/00001/01567
d D 3.93 82/07/02 09:43:06 eric 114 113
c take special care in outputing error messages to the transcript;
c a little bit of paranoia never hurt a mail system.
e
s 00002/00009/01566
d D 3.92 82/06/26 14:53:12 eric 113 112
c clean up error messages on SMTP temporary failures resulting from
c failure to connect properly.
e
s 00006/00005/01569
d D 3.91 82/06/26 13:09:59 eric 112 111
c lint
e
s 00004/00000/01570
d D 3.90 82/06/23 12:10:50 eric 111 110
c check prescan return values in remotename
e
s 00001/00001/01569
d D 3.89 82/06/19 21:13:54 eric 110 109
c remember to put a newline at the end of the UGLYUUCP line
e
s 00003/00003/01567
d D 3.88 82/06/19 20:46:58 eric 109 108
c improve SMTP error reporting
e
s 00001/00001/01569
d D 3.87 82/06/16 14:29:26 eric 108 107
c fix botch in outputing "recipient" type lines (e.g., To:)
e
s 00029/00010/01541
d D 3.86 82/06/07 23:55:12 eric 107 106
c call the routine putline to output lines to mailers.  this lets us
c implement line length limits, etc. for full SMTP compatibility.
e
s 00029/00022/01522
d D 3.85 82/06/07 07:53:57 eric 106 105
c make transcripts verbose always; misc. message cleanup, etc.
e
s 00006/00022/01538
d D 3.84 82/06/07 07:05:52 eric 105 104
c strip out xlate stuff -- this belongs at a different level
e
s 00004/00001/01556
d D 3.83 82/06/06 23:13:16 eric 104 103
c avoid loops by not sending to owner-owner-* -- just send to
c owner-owner instead
e
s 00093/00012/01464
d D 3.82 82/06/06 23:04:17 eric 103 102
c implement alias owner feature.  this actually works for any user.
c basically, if the alias owner-xxx exists, errors sending to xxx will be
c sent to that alias rather than to the sender.
e
s 00015/00008/01461
d D 3.81 82/05/31 18:48:07 eric 102 101
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00002/00000/01467
d D 3.80 82/05/31 15:30:52 eric 101 99
i 100
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00118/00120/01349
d D 3.79.1.1 82/05/29 18:18:54 eric 100 99
c try to install envelopes.  is this really worth it???
e
s 00022/00022/01447
d D 3.79 82/05/22 01:36:18 eric 99 98
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00002/00002/01467
d D 3.78 82/05/20 17:44:59 eric 98 97
c add dfopen as a "determined fopen" -- it retries if it gets recoverable
c errors.  we use it for returning mail (to dead.letter) and creating the
c temp file.  the whole idea is to avoid dropping things on the floor on
c heavily loaded systems.  this is untested, since it seems impossible to
c fill up the inode or file tables on this VAX (but it works if the open
c succeeds).
e
s 00016/00007/01453
d D 3.77 82/05/15 12:29:09 eric 97 96
c add the 'R' flag to mailers, saying to rewrite the recipient addresses
c to be relative to the recipient.  This makes reply code easy, but
c confuses user mail programs that are expecting to have to rewrite
c recipient addresses.  In general, the receiving host must be "smart"
c for this to work.
e
s 00005/00001/01455
d D 3.76 82/05/06 20:20:42 eric 96 95
c allow socket number on [IPC] connections -- eventually this
c could be used to handle other low-level protocols.
e
s 00005/00000/01451
d D 3.75 82/03/27 20:14:43 eric 95 94
c delete neat remotename feature, because it doesn't work right in
c UUCPland -- and breaks stupid hosts.  'Twill be fixed, I promise.  Time
c must be spent figuring out how to define the civilized versus the
c uncivilized world.
e
s 00002/00005/01449
d D 3.74 82/03/20 16:11:51 eric 94 93
c 16 bit changes -- should have no effect on VAX binaries to
c speak of.
e
s 00037/00033/01417
d D 3.73 82/03/06 15:07:55 eric 93 92
c give correct error message in SMTP if some of the addresses are not ok
e
s 00007/00004/01443
d D 3.72 82/03/06 12:08:24 eric 92 91
c clean up error handling in IPC case; fix a minor bug in headers in
c queueing code; make SMTP mail multi user per connect.
e
s 00014/00005/01433
d D 3.71 82/03/05 10:44:50 eric 91 90
c remove silly $U dependency in UGLYUUCP code
e
s 00052/00001/01386
d D 3.70 82/03/05 10:12:04 eric 90 89
c include direct connect on outgoing mail if the pathname is "[IPC]" --
c this gives minimal number of processes for ethernet mail.
e
s 00063/00032/01324
d D 3.69 82/02/27 11:36:47 eric 89 88
c implement "return receipt requested".
e
s 00047/00003/01309
d D 3.68 82/02/22 19:31:06 eric 88 87
c be much mroe clever about splitting up addresses when doing header
c rewriting.
e
s 00016/00005/01296
d D 3.67 82/02/20 19:15:31 eric 87 86
c make rewriting of addresses in headers really work.  This adds the $q
c macro.  The rewriting of the From: address is still ad hoc and should
c be integrated into this format.
c Note:  old .cf files will not work with this version.
e
s 00132/00003/01169
d D 3.66 82/02/20 16:56:31 eric 86 85
c output names in a nice comma-separated fashion in messages -- this
c opens up other possibilities
e
s 00025/00003/01147
d D 3.65 82/02/20 12:09:03 eric 85 84
c implement -c flag: don't try to deliver expensive mail immediately
e
s 00000/00002/01150
d D 3.64 82/02/15 09:39:19 eric 84 83
c pass lint
e
s 00000/00003/01152
d D 3.63 82/02/04 20:29:21 eric 83 82
c add host aliasing; add -p flag.  this version doesn't yet know about
c replacing the text of the host alias into the message however.  syntax
c is grotty: "/hostmatch:%s@newhost" or whatever.
e
s 00002/00003/01153
d D 3.62 82/01/23 14:18:39 eric 82 81
c add M_UGLYUUCP flag; only catch filenames if the "/" is leading.
e
s 00005/00003/01151
d D 3.61 82/01/05 09:58:58 eric 81 80
c fix botch in UGLYUUCP code -- gave "remote from <dest>" instead of
c "remote from <source>"
e
s 00001/00001/01153
d D 3.60 81/12/06 12:37:31 eric 80 79
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00039/00009/01115
d D 3.59 81/12/05 11:52:58 eric 79 78
c put the SMTP and queueing code on compilation flags so that sendmail
c will fit on non-ID PDP-11's (ugh); put the ugly UUCP hack on a
c compilation flag also to emphasize that it sucks eggs; makefile
c cleanup.
e
s 00004/00001/01120
d D 3.58 81/11/27 21:47:43 eric 78 77
c make the trigger be stricter (path must end "/uux") so that mail
c forwarded to another machine will work right.  this delta should also
c be removed when the other goes.
e
s 00011/00001/01110
d D 3.57 81/11/27 21:36:44 eric 77 76
c this is a stupid hack to put "remote from <host>" lines on the From
c lines going to UUCP mail.  someday i hope to rip out this stupidity.
c it is triggered by any mailer named "uucp" -- it ought to be a special
c flag, but i refuse to legitimize antique hacky mistakes.
e
s 00027/00009/01084
d D 3.56 81/11/22 19:16:12 eric 76 75
c Edit queue control files when running queue (assuming there are still
c recipients left).  Also, modify the MsgPriority to be the absolute
c number (not the Priority: value); this allows us to include aging into
c the priority algorithm.
e
s 00013/00017/01080
d D 3.55 81/11/21 18:45:11 eric 75 73
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00003/00003/01094
d D 3.54.1.1 81/11/21 15:45:19 eric 74 73
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00001/00001/01096
d D 3.54 81/11/21 09:57:38 eric 73 72
c convert to SMTP draft 3
e
s 00196/00048/00901
d D 3.53 81/11/11 20:23:24 eric 72 71
c integrate user SMTP into sendmail itself.  If there is no $u arg
c in the mailer argument list, SMTP is run.  This can be used directly
c over the Ethernet or to any clever mailer.  We still need to edit
c spooled control files to remove recipients that have been successfully
c sent during queue processing.
e
s 00022/00010/00927
d D 3.52 81/10/31 22:11:41 eric 71 70
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00022/00000/00915
d D 3.51 81/10/27 12:24:27 eric 70 69
c experimental version combining queueing with daemon operation.
c I'm sure this doesn't work -- if only because the wait()s are funny.
e
s 00030/00008/00885
d D 3.50 81/10/26 14:21:25 eric 69 68
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00007/00007/00886
d D 3.49 81/10/23 19:37:01 eric 68 67
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00041/00000/00852
d D 3.48 81/10/19 22:26:26 eric 67 66
c implement SMTP mode -- doesn't support source routing or the
c HELP command, and doesn't give the correct code on VRFY or forwarding.
c Maybe someday....
e
s 00003/00001/00849
d D 3.47 81/10/12 10:04:01 eric 66 65
c throw in some "errno = 0;"'s to make syserr's more accurate;
c take any -f flag if debug mode and uid==euid.
e
s 00002/00002/00848
d D 3.46 81/10/08 22:55:19 eric 65 64
c ignore interrupts and hangups while calling mailer.
e
s 00032/00008/00818
d D 3.45 81/10/02 10:07:10 eric 64 63
c use ruleset 2 to rewrite names after the $g translate (to fix some
c forwarding problems; do a read check in putmessage (just in case
c the temp file disappeared); some general cleanup.
e
s 00064/00011/00762
d D 3.44 81/09/29 18:22:33 eric 63 62
c change processing of From: person; basically, this mod deletes the
c Original-From: line if redundant with the generated From: line, uses
c the Original-From: line for the From: line if possible, and a host of
c other such trivialities.
e
s 00001/00001/00772
d D 3.43 81/09/23 09:52:11 eric 62 61
c fix bug in file modes when mailing to files that didn't exist before;
c add an 'F' line to the .cf file that will read class entries from
c another file, given a scanf string to do the parsing.
e
s 00025/00008/00748
d D 3.42 81/09/20 10:56:23 eric 61 60
c be more careful in resetting uid
e
s 00007/00000/00749
d D 3.41 81/09/20 10:46:18 eric 60 59
c don't let a mailer ever execute as root (that should solve the
c security problems!) -- essentially just map root into someone else.
c Adds yet another configuration variable (should this be in the .cf file?
e
s 00002/00000/00747
d D 3.40 81/09/16 16:24:08 eric 59 58
c last delta was too paranoid -- this increases the number of
c cases that work (but is still safe -- I hope)
e
s 00024/00008/00723
d D 3.39 81/09/16 16:07:32 eric 58 57
c run as the user forwarding mail after a .forward operation;
c fix a bug in .forwarding that caused recursive expansion;
c restrict mail to programs, files, and with :include: for security
c reasons.
e
s 00001/00003/00730
d D 3.38 81/09/14 12:18:45 eric 57 56
c fix bug in mailers that only take one address at a time
e
s 00036/00007/00697
d D 3.37 81/09/12 15:48:28 eric 56 55
c change From: processing to reduce the number of Original-From:
c lines; change allocation of global variables.
e
s 00019/00002/00685
d D 3.36 81/09/07 14:12:21 eric 55 54
c fix up umask; allow setuid on files to take recipient owner;
c factor some configuration info into conf.c
e
s 00034/00016/00653
d D 3.35 81/09/06 19:47:51 eric 54 53
c cleanup, commenting, linting, etc.
e
s 00003/00002/00666
d D 3.34 81/09/06 12:13:19 eric 53 52
c return mail on error (ignore QDONTSEND)
e
s 00001/00001/00667
d D 3.33 81/09/06 10:27:01 eric 52 51
c fix botch in $u argument processing
e
s 00004/00001/00664
d D 3.32 81/08/31 21:21:12 eric 51 50
c collect mail statistics; change minor configuration
e
s 00000/00002/00665
d D 3.31 81/08/29 19:12:56 eric 50 49
c delete H_DELETE -- can be simulated with H_ACHECK
e
s 00011/00001/00656
d D 3.30 81/08/23 12:08:40 eric 49 48
c plug assorted security holes
e
s 00085/00024/00572
d D 3.29 81/08/22 20:33:17 eric 48 47
c drop into subprocess when delivering to a file so we can setuid(getuid())
e
s 00015/00001/00581
d D 3.28 81/08/22 17:51:48 eric 47 46
c Arrange to pull full name out of From line if found; includes
c Original-From: hacking (oh so ugly).  There's got to be a better way
c to do this...
e
s 00004/00001/00578
d D 3.27 81/08/22 14:33:50 eric 46 45
c fix UNIX From problem
e
s 00002/00002/00577
d D 3.26 81/08/21 18:17:54 eric 45 44
c drop M_FINAL, change some other defined constant names
e
s 00002/00005/00577
d D 3.25 81/08/20 15:13:18 eric 44 43
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00000/00242/00582
d D 3.24 81/08/20 14:33:30 eric 43 42
c split deliver.c and sendto.c
e
s 00004/00004/00820
d D 3.23 81/08/18 17:12:29 eric 42 41
c factor out ARPANET FTP reply codes into conf.c
e
s 00042/00028/00782
d D 3.22 81/08/18 16:46:37 eric 41 40
c convert to really do arpanet reply codes right (maybe)
e
s 00057/00003/00753
d D 3.21 81/08/18 11:38:34 eric 40 39
c allow :include: specs
e
s 00004/00023/00752
d D 3.20 81/08/12 13:09:55 eric 39 38
c ignore broken pipe signals, since some "mailers" may not want
c to read their input.
e
s 00004/00002/00771
d D 3.19 81/08/10 18:14:38 eric 38 37
c fix botch with $z macro that confused forwarding
e
s 00048/00045/00725
d D 3.18 81/08/10 16:55:55 eric 37 36
c totally rework aliasing scheme -- sucks when no DBM now,
c but works better for the usual case; fix some quoting problems
c (and how many did I add?); remove .mailer feature since .forward
c will simulate this happily
e
s 00028/00038/00742
d D 3.17 81/08/09 15:02:01 eric 36 35
c lint it
e
s 00041/00012/00739
d D 3.16 81/08/09 12:34:10 eric 35 34
c add private incoming mailers; add q_home field to ADDRESS struct;
c some general cleanup
e
s 00009/00005/00742
d D 3.15 81/08/08 16:08:15 eric 34 33
c efficiency hacks with QBADADDR and QGOODADDR; don't call
c mailer if nothing to send
e
s 00007/00001/00740
d D 3.14 81/08/08 15:04:46 eric 33 32
c implement blow-by-blow verbose mode
e
s 00002/00003/00739
d D 3.13 81/08/08 13:50:00 eric 32 31
c fix botch with returned messages
e
s 00010/00002/00732
d D 3.12 81/08/04 11:27:39 eric 31 30
c retry forks on failure
e
s 00001/00001/00733
d D 3.11 81/04/27 21:52:14 eric 30 29
c fix botch in |prog form
e
s 00005/00002/00729
d D 3.10 81/03/28 13:36:26 eric 29 28
c pass Full-Name field internally to do forwards correctly
e
s 00011/00047/00720
d D 3.9 81/03/28 12:02:23 eric 28 27
c put much more info in cf file (e.g., headers)
e
s 00002/00002/00765
d D 3.8 81/03/20 09:44:43 eric 27 26
c change name (again); from postbox to sendmail
e
s 00210/00201/00557
d D 3.7 81/03/12 10:56:47 eric 26 25
c merge letters to the same host into one message
e
s 00055/00157/00703
d D 3.6 81/03/11 10:45:16 eric 25 24
c general cleanup, esp. macro processor
e
s 00038/00059/00822
d D 3.5 81/03/09 13:21:16 eric 24 23
c first step at rewriting rules, etc.
e
s 00007/00007/00874
d D 3.4 81/03/07 16:59:02 eric 23 22
c change q_mailer to be index, not pointer
e
s 00005/00007/00876
d D 3.3 81/03/07 16:26:32 eric 22 20
c lint fixes
e
s 00004/00007/00876
d R 3.3 81/03/07 15:31:46 eric 21 20
c lint fixes
e
s 00027/00020/00856
d D 3.2 81/03/07 14:25:43 eric 20 19
c ----- delivermail ==> postbox -----
e
s 00200/00107/00676
d D 3.1 81/03/04 09:33:58 eric 19 18
c install fancy header stuff
e
s 00022/00016/00761
d D 2.6 81/02/28 11:50:18 eric 18 17
c install VAX mpx file logging
e
s 00003/00001/00774
d D 2.5 81/02/05 08:01:28 eric 17 16
c always issued a delivermail error message regardless of M_QUIET
e
s 00001/00001/00774
d D 2.4 81/01/08 18:18:30 eric 16 15
c convert to new log scheme
e
s 00017/00004/00758
d D 2.3 80/11/21 12:57:39 eric 15 14
c have right user & time come out for msgs
e
s 00002/00001/00760
d D 2.2 80/11/20 19:58:07 eric 14 12
c make dates be taken as date sent rather than date delivered
e
s 00012/00003/00758
d D 2.1.1.1 80/11/20 09:54:20 eric 13 12
c experimental save date technique
e
s 00000/00000/00761
d D 2.1 80/11/05 11:02:01 eric 12 11
c release 2
e
s 00009/00004/00752
d D 1.11 80/10/27 19:27:23 eric 11 10
c count & record message size
e
s 00004/00000/00752
d D 1.10 80/10/27 19:09:17 eric 10 9
c fix botch in SIGPIPE catching; map diagnostic to std out in mailers
e
s 00002/00002/00750
d D 1.9 80/10/26 16:50:14 eric 9 8
c exit => _exit in child
e
s 00002/00002/00750
d D 1.8 80/10/21 22:39:20 eric 8 7
c EX_UNAVAIL => EX_UNAVAILABLE
e
s 00003/00026/00749
d D 1.7 80/10/18 16:50:03 eric 7 6
c cleanup for dbm stuff: Error => Errors; move local host
c detection into parse; misc cleanup
e
s 00017/00000/00758
d D 1.6 80/10/17 13:41:57 mark 6 5
c uses dbm package for alias file to make it faster
e
s 00008/00008/00750
d D 1.5 80/10/11 18:11:31 eric 5 4
c cleanup to simplify configuration & fix minor bugs
e
s 00001/00105/00757
d D 1.4 80/08/02 13:48:34 eric 4 3
c cleaned up comments
e
s 00002/00000/00860
d D 1.3 80/07/25 22:03:11 eric 3 2
c add ID keywords
e
s 00000/00002/00860
d D 1.2 80/06/24 23:33:56 eric 2 1
c attempted fixes to quote problem(s)
e
s 00862/00000/00000
d D 1.1 80/06/23 08:23:47 eric 1 0
e
u
U
f b 
f i 
t
T
I 186
/*
I 209
 * Copyright (c) 1983 Eric P. Allman
E 209
D 203
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 203
I 203
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 209
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 209
I 209
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
E 209
 */
E 203

#ifndef lint
D 203
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 203
I 203
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 203

E 186
I 1
D 44
# include <stdio.h>
# include <pwd.h>
E 44
D 205
# include <signal.h>
I 19
D 44
# include <ctype.h>
E 44
I 39
# include <errno.h>
I 55
D 69
# include <sys/types.h>
# include <sys/stat.h>
E 69
E 55
E 39
E 19
D 20
# include "dlvrmail.h"
E 20
I 20
D 27
# include "postbox.h"
E 27
I 27
# include "sendmail.h"
I 69
# include <sys/stat.h>
I 193
# include <netdb.h>
E 205
I 205
#include <sendmail.h>
#include <sys/signal.h>
#include <sys/stat.h>
I 208
#include <sys/ioctl.h>
E 208
#include <netdb.h>
#include <errno.h>
I 210
#ifdef NAMED_BIND
E 210
I 207
#include <arpa/nameser.h>
#include <resolv.h>
I 210
#endif
E 210
E 207
E 205
E 193
E 69
E 27
E 20
D 117
# ifdef LOG
D 18
# include <log.h>
E 18
I 18
# include <syslog.h>
E 18
# endif LOG
E 117

I 3
D 80
static char SccsId[] = "%W%	%G%";
E 80
I 80
D 187
SCCSID(%W%	%Y%	%G%);
E 80

E 187
E 3
/*
D 54
**  DELIVER -- Deliver a message to a particular address.
E 54
I 54
**  DELIVER -- Deliver a message to a list of addresses.
E 54
**
I 54
**	This routine delivers to everyone on the same host as the
**	user on the head of the list.  It is clever about mailers
**	that don't handle multiple users.  It is NOT guaranteed
**	that it will deliver to all these addresses however -- so
**	deliver should be called once for each address on the
**	list.
**
E 54
D 26
**	Algorithm:
**		Compute receiving network (i.e., mailer), host, & user.
**		If local, see if this is really a program name.
**		Build argument for the mailer.
**		Create pipe through edit fcn if appropriate.
**		Fork.
**			Child: call mailer
**		Parent: call editfcn if specified.
**		Wait for mailer to finish.
**		Interpret exit status.
**
E 26
**	Parameters:
I 154
**		e -- the envelope to deliver.
E 154
D 54
**		to -- the address to deliver the message to.
E 54
I 54
D 69
**		to -- head of the address list to deliver to.
E 69
I 69
**		firstto -- head of the address list to deliver to.
E 69
E 54
D 100
**		editfcn -- if non-NULL, we want to call this function
**			to output the letter (instead of just out-
**			putting it raw).
E 100
**
**	Returns:
**		zero -- successfully delivered.
**		else -- some failure, see ExitStat for more info.
**
**	Side Effects:
**		The standard input is passed off to someone.
D 26
**
**	WARNING:
**		The standard input is shared amongst all children,
**		including the file pointer.  It is critical that the
**		parent waits for the child to finish before forking
**		another child.
E 26
D 25
**
D 4
**	Requires:
**		buildargv
**		giveresponse
**		fork (sys)
**		rewind (sys)
**		execv (sys)
**		exit (sys)
**		wait (sys)
**		syserr
**		getpwnam (sys)
**		endpwent (sys)
**		initlog
**		flagset
**		usrerr
**		pipe (sys)
**		close (sys)
**		dup (sys)
**		setuid (sys)
**		getuid (sys)
**		signal (sys)
**		fdopen (sys[v7] or conf.c[v6])
**		fclose (sys)
**		printf (sys)
**		stripquotes
**		mailfile
**		index (sys)
**
E 4
**	Called By:
**		main
**		savemail
**
**	Files:
D 4
**		standard input -- must be openned to the message to
E 4
I 4
**		standard input -- must be opened to the message to
E 4
**			deliver.
E 25
D 4
**
**	History:
**		3/5/80 -- modified rather extensively to change the
**			internal form of addresses.
**		12/26/79 -- written.
E 4
*/

D 69
deliver(to, editfcn)
D 20
	addrq *to;
E 20
I 20
	ADDRESS *to;
E 69
I 69
D 100
deliver(firstto, editfcn)
E 100
I 100
D 154
deliver(firstto)
E 154
I 154
deliver(e, firstto)
	register ENVELOPE *e;
E 154
E 100
	ADDRESS *firstto;
E 69
E 20
D 100
	int (*editfcn)();
E 100
{
D 26
	register struct mailer *m;
E 26
D 64
	char *host;
	char *user;
E 64
I 64
	char *host;			/* host being sent to */
	char *user;			/* user being sent to */
E 64
D 37
	extern struct passwd *getpwnam();
E 37
	char **pvp;
D 26
	extern char **buildargv();
	auto int st;
	register int i;
E 26
I 26
	register char **mvp;
E 26
	register char *p;
D 26
	int pid;
	int pvect[2];
	extern FILE *fdopen();
E 26
I 26
D 64
	register struct mailer *m;
E 64
I 64
D 154
	register struct mailer *m;	/* mailer for this recipient */
E 154
I 154
D 167
	register MAILER *m;	/* mailer for this recipient */
E 154
E 64
D 127
	register int i;
E 127
E 26
D 36
	extern int errno;
E 36
D 26
	FILE *mfile;
E 26
D 19
	extern putheader();
E 19
I 19
D 100
	extern putmessage();
E 100
E 19
D 26
	extern pipesig();
E 26
I 14
D 19
	extern bool GotHdr;
E 19
I 15
D 36
	extern char *index();
E 36
I 20
	extern bool checkcompat();
I 26
	char *pv[MAXPV+1];
D 36
	extern char *newstr();
E 36
D 64
	char tobuf[MAXLINE];
E 64
I 64
D 135
	char tobuf[MAXLINE];		/* text line of to people */
E 135
I 135
	char tobuf[MAXLINE-50];		/* text line of to people */
E 135
E 64
	char buf[MAXNAME];
E 167
I 167
	register MAILER *m;		/* mailer for this recipient */
E 167
I 58
	ADDRESS *ctladdr;
D 167
	extern ADDRESS *getctladdr();
I 64
	char tfrombuf[MAXNAME];		/* translated from person */
	extern char **prescan();
E 167
I 69
	register ADDRESS *to = firstto;
I 72
	bool clever = FALSE;		/* running user smtp to this mailer */
D 117
	bool tempfail = FALSE;
E 117
I 76
	ADDRESS *tochain = NULL;	/* chain of users in this mailer call */
I 106
D 154
	bool notopen = TRUE;		/* set if connection not quite open */
E 154
I 127
D 205
	register int rcode;		/* response code */
E 205
I 205
	int rcode;		/* response code */
E 205
I 167
	char *pv[MAXPV+1];
	char tobuf[MAXLINE-50];		/* text line of to people */
	char buf[MAXNAME];
	char tfrombuf[MAXNAME];		/* translated from person */
	extern bool checkcompat();
	extern ADDRESS *getctladdr();
	extern char *remotename();
E 167
E 127
E 106
E 76
E 72
E 69
E 64
E 58
D 36
	extern char *expand();
E 36
D 57
	bool firstone;
E 57
E 26
E 20
E 15
E 14

I 66
	errno = 0;
E 66
D 26
	/*
	**  Compute receiving mailer, host, and to addreses.
	**	Do some initialization first.  To is the to address
	**	for error messages.
I 25
	**	Also, define the standard per-address macros.
E 25
	*/
E 26
I 26
D 53
	if (bitset(QDONTSEND, to->q_flags))
E 53
I 53
D 74
D 106
	if (!ForceMail && bitset(QDONTSEND, to->q_flags))
E 106
I 106
	if (bitset(QDONTSEND, to->q_flags))
E 106
E 74
I 74
	if (!ForceMail && bitset(QDONTSEND|QPSEUDO, to->q_flags))
E 74
E 53
		return (0);
E 26

I 210
#ifdef NAMED_BIND
E 210
I 207
	/* unless interactive, try twice, over a minute */
	if (OpMode == MD_DAEMON || OpMode == MD_SMTP) {
		_res.retrans = 30;
		_res.retry = 2;
	}
I 210
#endif NAMED_BIND
E 210

E 207
I 100
	m = to->q_mailer;
	host = to->q_host;

E 100
D 26
	To = to->q_paddr;
D 23
	m = to->q_mailer;
E 23
I 23
	m = Mailer[to->q_mailer];
E 23
	user = to->q_user;
	host = to->q_host;
D 7
	Error = 0;
E 7
I 7
	Errors = 0;
E 7
	errno = 0;
I 25
	define('u', user);		/* to user */
	define('h', host);		/* to host */
	define('g', m->m_from);		/* translated from address */
E 26
E 25
# ifdef DEBUG
D 117
	if (Debug)
E 117
I 117
	if (tTd(10, 1))
E 117
D 26
		printf("deliver(%s [%d, `%s', `%s'])\n", To, m, host, user);
E 26
I 26
		printf("\n--deliver, mailer=%d, host=`%s', first user=`%s'\n",
D 68
			to->q_mailer, to->q_host, to->q_user);
E 68
I 68
D 100
			to->q_mailer->m_mno, to->q_host, to->q_user);
E 100
I 100
			m->m_mno, host, to->q_user);
E 100
E 68
E 26
# endif DEBUG
I 100
D 106
	if (Verbose)
		message(Arpa_Info, "Connecting to %s.%s...", host, m->m_name);
E 106
E 100

I 85
D 100
	m = to->q_mailer;
	host = to->q_host;

E 100
E 85
	/*
I 85
	**  If this mailer is expensive, and if we don't want to make
	**  connections now, just mark these addresses and return.
	**	This is useful if we want to batch connections to
	**	reduce load.  This will cause the messages to be
	**	queued up, and a daemon will come along to send the
	**	messages later.
	**		This should be on a per-mailer basis.
	*/

D 140
	if (NoConnect && !QueueRun && bitset(M_EXPENSIVE, m->m_flags))
E 140
I 140
D 168
	if (NoConnect && !QueueRun && bitset(M_EXPENSIVE, m->m_flags) &&
E 168
I 168
	if (NoConnect && !QueueRun && bitnset(M_EXPENSIVE, m->m_flags) &&
E 168
	    !Verbose)
E 140
	{
D 99
		QueueUp = TRUE;
E 99
I 99
D 103
		CurEnv->e_queueup = TRUE;
E 103
E 99
		for (; to != NULL; to = to->q_next)
D 123
			if (!bitset(QDONTSEND, to->q_flags))
E 123
I 123
D 141
			if (!bitset(QDONTSEND, to->q_flags) &&
			    to->q_mailer == firstto->q_mailer)
E 123
				to->q_flags |= QQUEUEUP|QDONTSEND;
E 141
I 141
		{
			if (bitset(QDONTSEND, to->q_flags) || to->q_mailer != m)
				continue;
			to->q_flags |= QQUEUEUP|QDONTSEND;
D 154
			CurEnv->e_to = to->q_paddr;
E 154
I 154
			e->e_to = to->q_paddr;
E 154
D 143
			giveresponse(EX_TEMPFAIL, TRUE, m);
E 143
I 143
			message(Arpa_Info, "queued");
			if (LogLevel > 4)
				logdelivery("queued");
E 143
		}
D 154
		CurEnv->e_to = NULL;
E 154
I 154
		e->e_to = NULL;
E 154
E 141
		return (0);
	}

	/*
E 85
I 20
D 26
	**  Check to see that these people are allowed to talk to each other.
E 26
I 26
	**  Do initial argv setup.
	**	Insert the mailer name.  Notice that $x expansion is
	**	NOT done on the mailer name.  Then, if the mailer has
	**	a picky -f flag, we insert it as appropriate.  This
	**	code does not check for 'pv' overflow; this places a
	**	manifest lower limit of 4 for MAXPV.
I 85
D 128
	**		We rewrite the from address here, being careful
	**		to also rewrite it again using ruleset 2 to
	**		eliminate redundancies.
E 128
I 128
	**		The from address rewrite is expected to make
	**		the address relative to the other end.
E 128
E 85
E 26
	*/
D 85

D 26
	if (!checkcompat(to))
		return(giveresponse(EX_UNAVAILABLE, TRUE, m));
E 26
I 26
D 68
	m = Mailer[to->q_mailer];
E 68
I 68
	m = to->q_mailer;
E 68
	host = to->q_host;
E 85
D 64
	define('g', m->m_from);		/* translated from address */
E 64
I 64

	/* rewrite from address, using rewriting rules */
D 100
	(void) expand(m->m_from, buf, &buf[sizeof buf - 1]);
E 100
I 100
D 128
	expand(m->m_from, buf, &buf[sizeof buf - 1], CurEnv);
E 128
I 128
D 154
	expand("$f", buf, &buf[sizeof buf - 1], CurEnv);
E 154
I 154
D 181
	expand("$f", buf, &buf[sizeof buf - 1], e);
E 181
I 181
	expand("\001f", buf, &buf[sizeof buf - 1], e);
E 181
E 154
E 128
E 100
D 167
	mvp = prescan(buf, '\0');
I 154
	rewrite(mvp, 3);
	rewrite(mvp, 1);
E 154
D 128
	if (mvp == NULL)
	{
		syserr("bad mailer from translate \"%s\"", buf);
		return (EX_SOFTWARE);
	}
	rewrite(mvp, 2);
E 128
I 128
	rewrite(mvp, m->m_s_rwset);
I 165
	rewrite(mvp, 4);
E 165
E 128
	cataddr(mvp, tfrombuf, sizeof tfrombuf);
E 167
I 167
D 211
	(void) strcpy(tfrombuf, remotename(buf, m, TRUE, TRUE));
E 211
I 211
	(void) strcpy(tfrombuf, remotename(buf[0] != '\0' ? buf : "<>", m,
		TRUE, TRUE));
E 211
E 167

D 154
	define('g', tfrombuf);		/* translated sender address */
E 64
	define('h', host);		/* to host */
E 154
I 154
	define('g', tfrombuf, e);		/* translated sender address */
	define('h', host, e);			/* to host */
E 154
	Errors = 0;
D 66
	errno = 0;
E 66
	pvp = pv;
	*pvp++ = m->m_argv[0];
E 26

D 26
	/*
E 20
	**  Remove quote bits from user/host.
	*/
E 26
I 26
	/* insert -f or -r flag as appropriate */
D 168
	if (bitset(M_FOPT|M_ROPT, m->m_flags) && FromFlag)
E 168
I 168
	if (FromFlag && (bitnset(M_FOPT, m->m_flags) || bitnset(M_ROPT, m->m_flags)))
E 168
	{
D 168
		if (bitset(M_FOPT, m->m_flags))
E 168
I 168
		if (bitnset(M_FOPT, m->m_flags))
E 168
			*pvp++ = "-f";
		else
			*pvp++ = "-r";
D 36
		expand("$g", buf, &buf[sizeof buf - 1]);
E 36
I 36
D 100
		(void) expand("$g", buf, &buf[sizeof buf - 1]);
E 100
I 100
D 154
		expand("$g", buf, &buf[sizeof buf - 1], CurEnv);
E 154
I 154
D 181
		expand("$g", buf, &buf[sizeof buf - 1], e);
E 181
I 181
		expand("\001g", buf, &buf[sizeof buf - 1], e);
E 181
E 154
E 100
E 36
		*pvp++ = newstr(buf);
	}
E 26

D 26
	for (p = user; (*p++ &= 0177) != '\0'; )
		continue;
	if (host != NULL)
		for (p = host; (*p++ &= 0177) != '\0'; )
			continue;
	
E 26
	/*
D 26
	**  Strip quote bits from names if the mailer wants it.
E 26
I 26
	**  Append the other fixed parts of the argv.  These run
	**  up to the first entry containing "$u".  There can only
	**  be one of these, and there are only a few more slots
	**  in the pv after it.
E 26
	*/

D 20
	if (flagset(M_STRIPQ, m->m_flags))
E 20
I 20
D 26
	if (bitset(M_STRIPQ, m->m_flags))
E 26
I 26
	for (mvp = m->m_argv; (p = *++mvp) != NULL; )
E 26
E 20
	{
D 26
		stripquotes(user);
		stripquotes(host);
E 26
I 26
D 181
		while ((p = index(p, '$')) != NULL)
E 181
I 181
		while ((p = index(p, '\001')) != NULL)
E 181
			if (*++p == 'u')
				break;
		if (p != NULL)
			break;

		/* this entry is safe -- go ahead and process it */
D 36
		expand(*mvp, buf, &buf[sizeof buf - 1]);
E 36
I 36
D 100
		(void) expand(*mvp, buf, &buf[sizeof buf - 1]);
E 100
I 100
D 154
		expand(*mvp, buf, &buf[sizeof buf - 1], CurEnv);
E 154
I 154
		expand(*mvp, buf, &buf[sizeof buf - 1], e);
E 154
E 100
E 36
		*pvp++ = newstr(buf);
		if (pvp >= &pv[MAXPV - 3])
		{
			syserr("Too many parameters to %s before $u", pv[0]);
			return (-1);
		}
E 26
	}
I 72

I 90
	/*
	**  If we have no substitution for the user name in the argument
	**  list, we know that we must supply the names otherwise -- and
	**  SMTP is the answer!!
	*/

E 90
E 72
I 26
	if (*mvp == NULL)
D 72
		syserr("No $u in mailer argv for %s", pv[0]);
E 72
I 72
	{
		/* running SMTP */
I 79
# ifdef SMTP
E 79
		clever = TRUE;
		*pvp = NULL;
I 90
D 106

		/* send the initial SMTP protocol */
E 90
D 92
		i = smtpinit(m, pv, (ADDRESS *) NULL);
		giveresponse(i, TRUE, m);
E 92
I 92
D 102
		smtpinit(m, pv, (ADDRESS *) NULL);
E 102
I 102
		i = smtpinit(m, pv, (ADDRESS *) NULL);
E 102
E 92
I 79
# ifdef QUEUE
E 79
		if (i == EX_TEMPFAIL)
D 103
		{
D 99
			QueueUp = TRUE;
E 99
I 99
			CurEnv->e_queueup = TRUE;
E 103
E 99
			tempfail = TRUE;
D 103
		}
E 103
I 79
# endif QUEUE
E 106
# else SMTP
I 90
		/* oops!  we don't implement SMTP */
E 90
		syserr("SMTP style mailer");
		return (EX_SOFTWARE);
# endif SMTP
E 79
	}
E 72
E 26

	/*
D 26
	**  See if this user name is "special".
	**	If the user is a program, diddle with the mailer spec.
	**	If the user name has a slash in it, assume that this
	**		is a file -- send it off without further ado.
	**		Note that this means that editfcn's will not
	**		be applied to the message.
E 26
I 26
	**  At this point *mvp points to the argument with $u.  We
	**  run through our address list and append all the addresses
	**  we can.  If we run out of space, do not fret!  We can
	**  always send another copy later.
E 26
	*/

D 23
	if (m == &Mailer[0])
E 23
I 23
D 26
	if (m == Mailer[0])
E 26
I 26
	tobuf[0] = '\0';
D 57
	firstone = TRUE;
E 57
D 99
	To = tobuf;
E 99
I 99
D 154
	CurEnv->e_to = tobuf;
E 154
I 154
	e->e_to = tobuf;
E 154
E 99
I 58
	ctladdr = NULL;
E 58
	for (; to != NULL; to = to->q_next)
E 26
E 23
	{
D 26
		if (*user == '|')
E 26
I 26
		/* avoid sending multiple recipients to dumb mailers */
D 57
		if (!firstone && !bitset(M_MUSER, m->m_flags))
E 57
I 57
D 168
		if (tobuf[0] != '\0' && !bitset(M_MUSER, m->m_flags))
E 168
I 168
		if (tobuf[0] != '\0' && !bitnset(M_MUSER, m->m_flags))
E 168
E 57
			break;

		/* if already sent or not for this host, don't send */
D 53
		if (bitset(QDONTSEND, to->q_flags) || strcmp(to->q_host, host) != 0)
E 53
I 53
D 74
D 106
		if ((!ForceMail && bitset(QDONTSEND, to->q_flags)) ||
E 74
I 74
		if ((!ForceMail && bitset(QDONTSEND|QPSEUDO, to->q_flags)) ||
E 74
D 75
		    strcmp(to->q_host, host) != 0)
E 75
I 75
		    strcmp(to->q_host, host) != 0 || to->q_mailer != firstto->q_mailer)
E 106
I 106
		if (bitset(QDONTSEND, to->q_flags) ||
		    strcmp(to->q_host, host) != 0 ||
		    to->q_mailer != firstto->q_mailer)
E 106
E 75
E 53
			continue;
I 135

		/* avoid overflowing tobuf */
D 154
		if (sizeof tobuf - (strlen(to->q_paddr) + strlen(tobuf) + 1) < 0)
E 154
I 154
		if (sizeof tobuf - (strlen(to->q_paddr) + strlen(tobuf) + 2) < 0)
E 154
			break;
E 135
I 58

I 76
# ifdef DEBUG
D 117
		if (Debug)
E 117
I 117
		if (tTd(10, 1))
E 117
		{
			printf("\nsend to ");
			printaddr(to, FALSE);
		}
# endif DEBUG

D 93
		/* link together the chain of recipients */
		if (!bitset(QDONTSEND, to->q_flags))
		{
			to->q_tchain = tochain;
			tochain = to;
		}

E 93
E 76
		/* compute effective uid/gid when sending */
D 68
		if (to->q_mailer == MN_PROG)
E 68
I 68
		if (to->q_mailer == ProgMailer)
E 68
			ctladdr = getctladdr(to);

E 58
		user = to->q_user;
D 99
		To = to->q_paddr;
E 99
I 99
D 154
		CurEnv->e_to = to->q_paddr;
E 154
I 154
		e->e_to = to->q_paddr;
E 154
E 99
		to->q_flags |= QDONTSEND;
I 72
D 113
		if (tempfail)
I 76
		{
E 76
			to->q_flags |= QQUEUEUP;
E 72
D 54
		firstone = FALSE;

E 54
D 76
# ifdef DEBUG
		if (Debug)
			printf("   send to `%s'\n", user);
# endif DEBUG
E 76
I 76
			continue;
		}
E 113
E 76

		/*
		**  Check to see that these people are allowed to
		**  talk to each other.
		*/

I 169
		if (m->m_maxsize != 0 && e->e_msgsize > m->m_maxsize)
		{
D 200
			usrerr("Message is too large; %ld bytes max", m->m_maxsize);
E 200
			NoReturn = TRUE;
I 200
			usrerr("Message is too large; %ld bytes max", m->m_maxsize);
E 200
			giveresponse(EX_UNAVAILABLE, m, e);
			continue;
		}
E 169
		if (!checkcompat(to))
E 26
		{
D 26
			user++;
D 23
			m = &Mailer[1];
E 23
I 23
			m = Mailer[1];
E 26
I 26
D 154
			giveresponse(EX_UNAVAILABLE, TRUE, m);
E 154
I 154
D 161
			giveresponse(EX_UNAVAILABLE, m);
E 161
I 161
			giveresponse(EX_UNAVAILABLE, m, e);
E 161
E 154
			continue;
E 26
E 23
		}
D 26
		else
E 26
I 26

		/*
D 37
		**  Remove quote bits from user/host.
E 37
I 37
		**  Strip quote bits from names if the mailer is dumb
		**	about them.
E 37
		*/

D 37
		for (p = user; (*p++ &= 0177) != '\0'; )
			continue;
		if (host != NULL)
			for (p = host; (*p++ &= 0177) != '\0'; )
				continue;
		
		/*
		**  Strip quote bits from names if the mailer wants it.
		*/

E 37
D 168
		if (bitset(M_STRIPQ, m->m_flags))
E 168
I 168
		if (bitnset(M_STRIPQ, m->m_flags))
E 168
E 26
		{
I 26
D 37
			stripquotes(user);
			stripquotes(host);
E 37
I 37
			stripquotes(user, TRUE);
			stripquotes(host, TRUE);
E 37
		}
I 37
		else
		{
			stripquotes(user, FALSE);
			stripquotes(host, FALSE);
		}
E 37

I 149
		/* hack attack -- delivermail compatibility */
		if (m == ProgMailer && *user == '|')
			user++;

E 149
		/*
I 106
D 154
		**  Do initial connection setup if needed.
		*/

		if (notopen)
		{
			message(Arpa_Info, "Connecting to %s.%s...", host, m->m_name);
# ifdef SMTP
			if (clever)
			{
				/* send the initial SMTP protocol */
D 127
				i = smtpinit(m, pv, (ADDRESS *) NULL);
E 127
I 127
				rcode = smtpinit(m, pv, (ADDRESS *) NULL);
E 127
D 117
# ifdef QUEUE
				if (i == EX_TEMPFAIL)
					tempfail = TRUE;
# endif QUEUE
E 117
			}
# ifdef SMTP
			notopen = FALSE;
		}

		/*
E 106
I 93
		**  Pass it to the other host if we are running SMTP.
		*/

		if (clever)
		{
# ifdef SMTP
D 127
			i = smtprcpt(to);
			if (i != EX_OK)
E 127
I 127
			if (rcode == EX_OK)
				rcode = smtprcpt(to);
			if (rcode != EX_OK)
E 127
			{
D 127
# ifdef QUEUE
				if (i == EX_TEMPFAIL)
E 127
I 127
				if (rcode == EX_TEMPFAIL)
E 127
D 103
				{
D 99
					QueueUp = TRUE;
E 99
I 99
					CurEnv->e_queueup = TRUE;
E 103
E 99
					to->q_flags |= QQUEUEUP;
D 103
				}
E 103
				else
D 127
# endif QUEUE
E 127
D 113
				{
E 113
					to->q_flags |= QBADADDR;
D 113
					giveresponse(i, TRUE, m);
				}
E 113
I 113
D 127
				giveresponse(i, TRUE, m);
E 127
I 127
				giveresponse(rcode, TRUE, m);
E 127
E 113
			}
# else SMTP
			syserr("trying to be clever");
# endif SMTP
		}

		/*
E 154
E 93
I 41
		**  If an error message has already been given, don't
		**	bother to send to this address.
		**
		**	>>>>>>>>>> This clause assumes that the local mailer
		**	>> NOTE >> cannot do any further aliasing; that
		**	>>>>>>>>>> function is subsumed by sendmail.
		*/

D 113
		if (bitset(QBADADDR, to->q_flags))
E 113
I 113
		if (bitset(QBADADDR|QQUEUEUP, to->q_flags))
E 113
			continue;

I 51
		/* save statistics.... */
D 68
		Stat.stat_nt[to->q_mailer]++;
		Stat.stat_bt[to->q_mailer] += kbytes(MsgSize);
E 68
I 68
D 154
		Stat.stat_nt[to->q_mailer->m_mno]++;
D 99
		Stat.stat_bt[to->q_mailer->m_mno] += kbytes(MsgSize);
E 99
I 99
		Stat.stat_bt[to->q_mailer->m_mno] += kbytes(CurEnv->e_msgsize);
E 154
I 154
		markstats(e, to);
E 154
E 99
E 68

E 51
		/*
E 41
		**  See if this user name is "special".
		**	If the user name has a slash in it, assume that this
D 100
		**	is a file -- send it off without further ado.
		**	Note that this means that editfcn's will not
		**	be applied to the message.  Also note that
		**	this type of addresses is not processed along
D 99
		**	with the others, so we fudge on the To person.
E 99
I 99
		**	with the others, so we fudge on the CurEnv->e_to person.
E 100
I 100
		**	is a file -- send it off without further ado.  Note
		**	that this type of addresses is not processed along
		**	with the others, so we fudge on the To person.
E 100
E 99
		*/

D 35
		if (m == Mailer[0])
E 35
I 35
D 45
		if (m == Mailer[M_LOCAL])
E 45
I 45
D 68
		if (m == Mailer[MN_LOCAL])
E 68
I 68
		if (m == LocalMailer)
E 68
E 45
E 35
		{
E 26
D 82
			if (index(user, '/') != NULL)
E 82
I 82
			if (user[0] == '/')
E 82
			{
D 58
				i = mailfile(user);
E 58
I 58
D 127
				i = mailfile(user, getctladdr(to));
E 58
				giveresponse(i, TRUE, m);
E 127
I 127
				rcode = mailfile(user, getctladdr(to));
D 154
				giveresponse(rcode, TRUE, m);
E 154
I 154
D 161
				giveresponse(rcode, m);
E 161
I 161
				giveresponse(rcode, m, e);
E 161
E 154
E 127
D 26
				return (i);
E 26
I 26
				continue;
E 26
			}
		}
I 26

I 54
		/*
		**  Address is verified -- add this user to mailer
		**  argv, and add it to the print list of recipients.
		*/

I 93
		/* link together the chain of recipients */
D 94
		if (!bitset(QDONTSEND, to->q_flags))
		{
			to->q_tchain = tochain;
			tochain = to;
		}
E 94
I 94
		to->q_tchain = tochain;
		tochain = to;
E 94

E 93
E 54
D 41
		/*
		**  See if the user exists.
		**	Strictly, this is only needed to print a pretty
		**	error message.
		**
		**	>>>>>>>>>> This clause assumes that the local mailer
		**	>> NOTE >> cannot do any further aliasing; that
D 27
		**	>>>>>>>>>> function is subsumed by postbox.
E 27
I 27
		**	>>>>>>>>>> function is subsumed by sendmail.
E 27
		*/

D 34
		if (m == Mailer[0])
E 34
I 34
D 35
		if (m == Mailer[0] && !bitset(QGOODADDR, to->q_flags))
E 35
I 35
		if (bitset(QBADADDR, to->q_flags))
E 35
E 34
		{
D 34
			if (getpwnam(user) == NULL)
E 34
I 34
D 35
			if (bitset(QBADADDR, to->q_flags) || getpwnam(user) == NULL)
E 34
			{
				giveresponse(EX_NOUSER, TRUE, m);
				continue;
			}
E 35
I 35
			giveresponse(EX_NOUSER, TRUE, m);
			continue;
E 35
		}

E 41
		/* create list of users for error messages */
D 156
		if (tobuf[0] != '\0')
D 36
			strcat(tobuf, ",");
		strcat(tobuf, to->q_paddr);
E 36
I 36
			(void) strcat(tobuf, ",");
E 156
I 156
		(void) strcat(tobuf, ",");
E 156
		(void) strcat(tobuf, to->q_paddr);
E 36
D 154
		define('u', user);		/* to user */
I 35
		define('z', to->q_home);	/* user's home */
E 154
I 154
		define('u', user, e);		/* to user */
		define('z', to->q_home, e);	/* user's home */
E 154
E 35

D 72
		/* expand out this user */
D 36
		expand(user, buf, &buf[sizeof buf - 1]);
E 36
I 36
D 52
		(void) expand(user, buf, &buf[sizeof buf - 1]);
E 52
I 52
		(void) expand(*mvp, buf, &buf[sizeof buf - 1]);
E 52
E 36
		*pvp++ = newstr(buf);
		if (pvp >= &pv[MAXPV - 2])
E 72
I 72
		/*
D 93
		**  Expand out this user into argument list or
		**  send it to our SMTP server.
E 93
I 93
		**  Expand out this user into argument list.
E 93
		*/

D 93
		if (clever)
E 72
		{
I 79
# ifdef SMTP
E 79
D 72
			/* allow some space for trailing parms */
			break;
E 72
I 72
D 73
			i = smtpmrcp(to);
E 73
I 73
			i = smtprcpt(to);
E 73
D 79
			if (i == EX_TEMPFAIL)
E 79
I 79
			if (i != EX_OK)
E 79
			{
D 79
				QueueUp = TRUE;
				to->q_flags |= QQUEUEUP;
E 79
I 79
# ifdef QUEUE
				if (i == EX_TEMPFAIL)
				{
					QueueUp = TRUE;
					to->q_flags |= QQUEUEUP;
				}
				else
# endif QUEUE
				{
					to->q_flags |= QBADADDR;
					giveresponse(i, TRUE, m);
				}
E 79
			}
D 79
			else if (i != EX_OK)
			{
				to->q_flags |= QBADADDR;
				giveresponse(i, TRUE, m);
			}
E 79
I 79
# else SMTP
			syserr("trying to be clever");
# endif SMTP
E 79
E 72
		}
I 72
		else
E 93
I 93
		if (!clever)
E 93
		{
D 100
			(void) expand(*mvp, buf, &buf[sizeof buf - 1]);
E 100
I 100
D 154
			expand(*mvp, buf, &buf[sizeof buf - 1], CurEnv);
E 154
I 154
			expand(*mvp, buf, &buf[sizeof buf - 1], e);
E 154
E 100
			*pvp++ = newstr(buf);
			if (pvp >= &pv[MAXPV - 2])
			{
				/* allow some space for trailing parms */
				break;
			}
		}
E 72
E 26
	}

I 34
	/* see if any addresses still exist */
	if (tobuf[0] == '\0')
I 72
	{
I 79
D 154
# ifdef SMTP
E 79
D 145
		if (clever)
E 145
I 145
		if (clever && !notopen)
E 145
D 109
			smtpquit(pv[0]);
E 109
I 109
			smtpquit(pv[0], FALSE);
E 109
I 79
# endif SMTP
I 101
D 102
		define('g', NULL);
E 102
I 102
		define('g', (char *) NULL);
E 154
I 154
		define('g', (char *) NULL, e);
E 154
E 102
E 101
E 79
E 72
		return (0);
I 72
	}
E 72

E 34
I 26
	/* print out messages as full list */
D 99
	To = tobuf;
E 99
I 99
D 154
	CurEnv->e_to = tobuf;
E 154
I 154
D 156
	e->e_to = tobuf;
E 156
I 156
	e->e_to = tobuf + 1;
E 156
E 154
E 99

E 26
D 5
# ifdef BADMAIL
E 5
	/*
D 5
	**  If the mailer doesn't return the proper
	**  exit statuses, check here to see if the
	**  user exists so that we can give a pretty
	**  error message.
E 5
I 5
D 26
	**  See if the user exists.
	**	Strictly, this is only needed to print a pretty
	**	error message.
	**
	**	>>>>>>>>>> This clause assumes that the local mailer
	**	>> NOTE >> cannot do any further aliasing; that
D 20
	**	>>>>>>>>>> function is subsumed by delivermail.
E 20
I 20
	**	>>>>>>>>>> function is subsumed by postbox.
E 26
I 26
	**  Fill out any parameters after the $u parameter.
E 26
E 20
E 5
	*/

D 23
	if (m == &Mailer[0])
E 23
I 23
D 26
	if (m == Mailer[0])
E 26
I 26
D 72
	while (*++mvp != NULL)
E 72
I 72
	while (!clever && *++mvp != NULL)
E 72
E 26
E 23
	{
D 26
		if (getpwnam(user) == NULL)
		{
			giveresponse(EX_NOUSER, TRUE, m);
			return (EX_NOUSER);
		}
E 26
I 26
D 36
		expand(*mvp, buf, &buf[sizeof buf - 1]);
E 36
I 36
D 100
		(void) expand(*mvp, buf, &buf[sizeof buf - 1]);
E 100
I 100
D 154
		expand(*mvp, buf, &buf[sizeof buf - 1], CurEnv);
E 154
I 154
		expand(*mvp, buf, &buf[sizeof buf - 1], e);
E 154
E 100
E 36
		*pvp++ = newstr(buf);
		if (pvp >= &pv[MAXPV])
			syserr("deliver: pv overflow after $u for %s", pv[0]);
E 26
	}
I 26
	*pvp++ = NULL;
E 26
D 5
# endif BADMAIL
E 5

	/*
D 19
	**  If the mailer wants a From line, insert a new editfcn.
	*/

D 14
	if (flagset(M_HDR, m->m_flags) && editfcn == NULL)
E 14
I 14
D 15
	if (flagset(M_HDR, m->m_flags) && editfcn == NULL && !GotHdr)
E 15
I 15
	if (flagset(M_HDR, m->m_flags) && editfcn == NULL && (!GotHdr || flagset(M_FHDR, m->m_flags)))
E 15
E 14
		editfcn = putheader;

	/*
E 19
	**  Call the mailer.
D 19
	**	The argument vector gets built, pipes through 'editfcn'
E 19
I 19
	**	The argument vector gets built, pipes
E 19
	**	are created as necessary, and we fork & exec as
D 19
	**	appropriate.  In the parent, we call 'editfcn'.
E 19
I 19
	**	appropriate.
I 72
	**	If we are running SMTP, we just need to clean up.
E 72
I 35
D 54
	**
	**	Notice the tacky hack to handle private mailers.
E 54
E 35
E 19
	*/

I 154
D 206
	message(Arpa_Info, "Connecting to %s.%s...", host, m->m_name);

E 206
E 154
D 19
	pvp = buildargv(m->m_argv, m->m_flags, host, user, From.q_paddr);
E 19
I 19
D 26
	pvp = buildargv(m, host, user, From.q_paddr);
E 19
	if (pvp == NULL)
E 26
I 26
D 100
	if (editfcn == NULL)
		editfcn = putmessage;
E 100
I 35
D 37
	if (m == Mailer[M_PRIVATE])
	{
D 36
		expand("$z/.mailer", buf, &buf[sizeof buf - 1]);
E 36
I 36
		(void) expand("$z/.mailer", buf, &buf[sizeof buf - 1]);
E 36
		m->m_mailer = buf;
	}
E 37
E 35
D 58
	i = sendoff(m, pv, editfcn);
E 58
I 58
	if (ctladdr == NULL)
D 99
		ctladdr = &From;
E 99
I 99
D 154
		ctladdr = &CurEnv->e_from;
E 154
I 154
		ctladdr = &e->e_from;
I 210
#ifdef NAMED_BIND
E 210
I 207
	_res.options &= ~(RES_DEFNAMES | RES_DNSRCH);		/* XXX */
I 210
#endif
E 210
E 207
E 154
E 99
I 79
D 205
# ifdef SMTP
E 79
D 72
	i = sendoff(m, pv, editfcn, ctladdr);
E 72
I 72
	if (clever)
	{
I 197
D 204
# ifdef MXDOMAIN
E 204
		expand("\001w", buf, &buf[sizeof buf - 1], e);
D 199
		if ((nmx = getmxrr(host, mxhosts, MAXMXHOSTS, buf)) < 0)
E 199
I 199
D 201
		if ((Nmx = getmxrr(host, MxHosts, MAXMXHOSTS, buf)) < 0)
E 201
I 201
		if (host[0] == '[')
		{
E 205
I 205
#ifdef SMTP
D 210
	if (clever) {
E 210
I 210
	if (clever)
	{
E 210
		expand("\001w", buf, &buf[sizeof(buf) - 1], e);
		rcode = EX_OK;
D 210
		if (host[0] == '[') {
E 210
I 210
#ifdef NAMED_BIND
		if (host[0] != '[')
		{
			Nmx = getmxrr(host, MxHosts, buf, &rcode);
		}
		else
#endif
		{
E 210
E 205
			Nmx = 1;
			MxHosts[0] = host;
D 205
			rcode = EX_OK;
E 205
D 207
		}
D 205
		else if ((Nmx = getmxrr(host, MxHosts, MAXMXHOSTS, buf)) < 0)
E 201
E 199
		{
			/*
			 * Map errors into standard values
			 */
D 199
			if (nmx == -1)
E 199
I 199
			if (Nmx == -1)
E 199
				rcode = EX_TEMPFAIL;
D 199
			else if (nmx == -3)
E 199
I 199
			else if (Nmx == -3)
E 199
				rcode = EX_NOHOST;
			else
				rcode = EX_UNAVAILABLE;
		}
		else
			rcode = EX_OK;
D 204
#else MXDOMAIN
D 199
		nmx = 1;
		mxhosts[0] = q->q_host;
E 199
I 199
		Nmx = 1;
		MxHosts[0] = q->q_host;
E 199
		rcode = EX_OK;
#endif
E 204
E 197
D 100
		i = smtpfinish(m, editfcn);
E 100
I 100
D 127
		i = smtpfinish(m, CurEnv);
E 100
D 109
		smtpquit(pv[0]);
E 109
I 109
D 125
		smtpquit(pv[0], TRUE);
E 125
I 125
		if (i != EX_OK)
			giveresponse(i, TRUE, m);
		smtpquit(pv[0], i == EX_OK);
E 127
I 127
D 154
		rcode = smtpfinish(m, CurEnv);
E 154
I 154
		/* send the initial SMTP protocol */
D 166
		rcode = smtpinit(m, pv, (ADDRESS *) NULL);
E 166
I 166
D 197
		rcode = smtpinit(m, pv);
E 197
I 197
		if (rcode == EX_OK)
			rcode = smtpinit(m, pv);
E 205
I 205
		else if ((Nmx = getmxrr(host, MxHosts, buf, &rcode)) >= 0 &&
		    (rcode = smtpinit(m, pv)) == EX_OK) {
E 205
E 197
E 166
D 206

E 206
I 206
			message(Arpa_Info, "Connecting to %s.%s...", MxHosts[0],
			    m->m_name);
E 206
D 156
		/* send the recipient list */
		for (to = tochain; to != NULL; to = to->q_tchain)
E 156
I 156
D 205
		if (rcode == EX_OK)
E 156
		{
E 205
D 156
			int i;
E 156
I 156
			/* send the recipient list */
			tobuf[0] = '\0';
D 205
			for (to = tochain; to != NULL; to = to->q_tchain)
			{
				int i;
E 205
I 205
			for (to = tochain; to; to = to->q_tchain) {
				register int i;
				register char *t = tobuf;
E 207
I 207
D 210
		} else
			Nmx = getmxrr(host, MxHosts, buf, &rcode);
		if (Nmx >= 0) {
E 210
I 210
		}
		if (Nmx >= 0)
		{
E 210
			message(Arpa_Info, "Connecting to %s (%s)...",
			    MxHosts[0], m->m_name);
			if ((rcode = smtpinit(m, pv)) == EX_OK) {
				/* send the recipient list */
				tobuf[0] = '\0';
				for (to = tochain; to; to = to->q_tchain) {
					register int i;
					register char *t = tobuf;
E 207
E 205
E 156

D 156
			if (rcode == EX_OK)
E 156
I 156
D 207
				e->e_to = to->q_paddr;
E 156
D 166
				i = smtprcpt(to);
E 166
I 166
				i = smtprcpt(to, m);
E 166
I 156
D 205
				if (i != EX_OK)
				{
E 205
I 205
				if (i != EX_OK) {
E 205
D 160
					if (i == EX_TEMPFAIL)
						to->q_flags |= QQUEUEUP;
					else
						to->q_flags |= QBADADDR;
E 160
I 160
					markfailure(e, to, i);
E 160
D 161
					giveresponse(i, m);
E 161
I 161
					giveresponse(i, m, e);
E 207
I 207
					e->e_to = to->q_paddr;
					if ((i = smtprcpt(to, m)) != EX_OK) {
						markfailure(e, to, i);
						giveresponse(i, m, e);
					}
					else {
						*t++ = ',';
						for (p = to->q_paddr; *p; *t++ = *p++);
					}
E 207
E 161
				}
I 207

				/* now send the data */
				if (tobuf[0] == '\0')
					e->e_to = NULL;
E 207
D 205
				else
				{
D 188
					strcat(tobuf, ",");
					strcat(tobuf, to->q_paddr);
E 188
I 188
					(void) strcat(tobuf, ",");
					(void) strcat(tobuf, to->q_paddr);
E 205
I 205
				else {
D 207
					*t++ = ',';
					for (p = to->q_paddr; *p; *t++ = *p++);
E 207
I 207
					e->e_to = tobuf + 1;
					rcode = smtpdata(m, e);
E 207
E 205
E 188
				}
D 207
			}
E 207

D 207
			/* now send the data */
			if (tobuf[0] == '\0')
				e->e_to = NULL;
E 156
D 205
			else
D 156
				i = rcode;
			if (i != EX_OK)
E 156
			{
E 205
I 205
			else {
E 205
D 156
				if (i == EX_TEMPFAIL)
					to->q_flags |= QQUEUEUP;
				else
					to->q_flags |= QBADADDR;
				giveresponse(rcode, m);
E 156
I 156
				e->e_to = tobuf + 1;
D 166
				rcode = smtpfinish(m, e);
E 166
I 166
				rcode = smtpdata(m, e);
E 207
I 207
				/* now close the connection */
				smtpquit(m);
E 207
E 166
E 156
			}
D 156
		}
E 156
D 207

D 156
		/* now send the closing protocol */
		if (rcode == EX_OK)
			rcode = smtpfinish(m, e);
E 154
		if (rcode != EX_OK)
D 154
			giveresponse(rcode, TRUE, m);
E 154
I 154
			giveresponse(rcode, m);
E 154
		smtpquit(pv[0], rcode == EX_OK);
E 156
I 156
			/* now close the connection */
D 166
			smtpquit(pv[0]);
E 166
I 166
D 179
			smtpquit(pv[0], m);
E 179
I 179
			smtpquit(m);
E 207
E 179
E 166
		}
E 156
E 127
E 125
E 109
	}
	else
I 79
D 205
# endif SMTP
E 205
I 205
#endif /* SMTP */
I 206
	{
D 207
		message(Arpa_Info, "Connecting to %s.%s...", host, m->m_name);
E 207
I 207
		message(Arpa_Info, "Connecting to %s (%s)...", host, m->m_name);
E 207
E 206
E 205
E 79
D 100
		i = sendoff(m, pv, editfcn, ctladdr);
E 100
I 100
D 127
		i = sendoff(m, pv, ctladdr);
E 127
I 127
D 154
		rcode = sendoff(m, pv, ctladdr);
E 154
I 154
D 159
		rcode = sendoff(e, m, pv, ctladdr);
E 159
I 159
D 166
		rcode = sendoff(e, m, pv, ctladdr, FALSE);
E 166
I 166
		rcode = sendoff(e, m, pv, ctladdr);
I 206
	}
I 210
#ifdef NAMED_BIND
E 210
I 207
	_res.options |= RES_DEFNAMES | RES_DNSRCH;	/* XXX */
I 210
#endif
E 210
E 207
E 206
E 166
E 159
E 154
E 127
E 100
E 72
E 58

I 69
	/*
D 156
	**  If we got a temporary failure, arrange to queue the
	**  addressees.
E 156
I 156
	**  Do final status disposal.
	**	We check for something in tobuf for the SMTP case.
	**	If we got a temporary failure, arrange to queue the
	**		addressees.
E 156
	*/

I 79
D 127
# ifdef QUEUE
E 79
	if (i == EX_TEMPFAIL)
E 127
I 127
D 156
	if (rcode == EX_TEMPFAIL)
E 156
I 156
	if (tobuf[0] != '\0')
D 161
		giveresponse(rcode, m);
E 161
I 161
		giveresponse(rcode, m, e);
E 161
	if (rcode != EX_OK)
E 156
E 127
D 206
	{
E 206
D 99
		QueueUp = TRUE;
E 99
I 99
D 103
		CurEnv->e_queueup = TRUE;
E 103
E 99
D 76
		for (to = firstto; to != NULL; to = to->q_next)
		{
			if (bitset(QBADADDR, to->q_flags))
				continue;
E 76
I 76
		for (to = tochain; to != NULL; to = to->q_tchain)
E 76
D 156
			to->q_flags |= QQUEUEUP;
E 156
I 156
D 160
		{
			if (rcode == EX_TEMPFAIL)
				to->q_flags |= QQUEUEUP;
			else
				to->q_flags |= QBADADDR;
		}
E 160
I 160
			markfailure(e, to, rcode);
E 160
E 156
D 76
		}
E 76
D 206
	}
E 206
I 79
D 127
# endif QUEUE
E 127
E 79

E 69
I 66
	errno = 0;
I 101
D 102
	define('g', NULL);
E 102
I 102
D 154
	define('g', (char *) NULL);
E 154
I 154
	define('g', (char *) NULL, e);
E 154
E 102
E 101
E 66
D 127
	return (i);
E 127
I 127
	return (rcode);
I 160
}
/*
**  MARKFAILURE -- mark a failure on a specific address.
**
**	Parameters:
**		e -- the envelope we are sending.
**		q -- the address to mark.
**		rcode -- the code signifying the particular failure.
**
**	Returns:
**		none.
**
**	Side Effects:
**		marks the address (and possibly the envelope) with the
**			failure so that an error will be returned or
**			the message will be queued, as appropriate.
*/

markfailure(e, q, rcode)
	register ENVELOPE *e;
	register ADDRESS *q;
	int rcode;
{
	if (rcode == EX_OK)
		return;
	else if (rcode != EX_TEMPFAIL)
		q->q_flags |= QBADADDR;
	else if (curtime() > e->e_ctime + TimeOut)
	{
		extern char *pintvl();
I 161
		char buf[MAXLINE];
E 161

		if (!bitset(EF_TIMEOUT, e->e_flags))
D 161
			message(Arpa_Info, "Cannot send message for %s",
E 161
I 161
		{
			(void) sprintf(buf, "Cannot send message for %s",
E 161
				pintvl(TimeOut, FALSE));
I 161
			if (e->e_message != NULL)
				free(e->e_message);
			e->e_message = newstr(buf);
			message(Arpa_Info, buf);
		}
E 161
		q->q_flags |= QBADADDR;
		e->e_flags |= EF_TIMEOUT;
	}
	else
		q->q_flags |= QQUEUEUP;
E 160
E 127
}
/*
I 48
**  DOFORK -- do a fork, retrying a couple of times on failure.
**
**	This MUST be a macro, since after a vfork we are running
**	two processes on the same stack!!!
**
**	Parameters:
**		none.
**
**	Returns:
**		From a macro???  You've got to be kidding!
**
**	Side Effects:
**		Modifies the ==> LOCAL <== variable 'pid', leaving:
**			pid of child in parent, zero in child.
**			-1 on unrecoverable error.
**
**	Notes:
**		I'm awfully sorry this looks so awful.  That's
**		vfork for you.....
*/

# define NFORKTRIES	5
D 148
# ifdef VFORK
E 148
I 148
# ifdef VMUNIX
E 148
# define XFORK	vfork
D 148
# else VFORK
E 148
I 148
# else VMUNIX
E 148
# define XFORK	fork
D 148
# endif VFORK
E 148
I 148
# endif VMUNIX
E 148

# define DOFORK(fORKfN) \
{\
	register int i;\
\
D 189
	for (i = NFORKTRIES; i-- > 0; )\
E 189
I 189
	for (i = NFORKTRIES; --i >= 0; )\
E 189
	{\
		pid = fORKfN();\
		if (pid >= 0)\
			break;\
D 102
		sleep((unsigned) NFORKTRIES - i);\
E 102
I 102
D 189
		sleep(NFORKTRIES - i);\
E 189
I 189
		if (i > 0)\
D 194
			sleep(NFORKTRIES - i);\
E 194
I 194
			sleep((unsigned) NFORKTRIES - i);\
E 194
E 189
E 102
	}\
}
/*
I 70
**  DOFORK -- simple fork interface to DOFORK.
**
**	Parameters:
**		none.
**
**	Returns:
**		pid of child in parent.
**		zero in child.
**		-1 on error.
**
**	Side Effects:
**		returns twice, once in parent and once in child.
*/

dofork()
{
	register int pid;

	DOFORK(fork);
	return (pid);
}
/*
E 70
E 48
**  SENDOFF -- send off call to mailer & collect response.
**
**	Parameters:
I 154
**		e -- the envelope to mail.
E 154
**		m -- mailer descriptor.
**		pvp -- parameter vector to send to it.
D 100
**		editfcn -- function to pipe it through.
E 100
I 58
**		ctladdr -- an address pointer controlling the
**			user/groupid etc. of the mailer.
I 159
D 166
**		crlf -- set if we want CRLF on the end of lines.
E 166
E 159
E 58
**
**	Returns:
**		exit status of mailer.
**
**	Side Effects:
**		none.
*/
D 207

E 207
I 207
static
E 207
I 31
D 48
#define NFORKTRIES	5

E 48
E 31
D 58
sendoff(m, pvp, editfcn)
E 58
I 58
D 100
sendoff(m, pvp, editfcn, ctladdr)
E 100
I 100
D 154
sendoff(m, pvp, ctladdr)
E 100
E 58
	struct mailer *m;
E 154
I 154
D 159
sendoff(e, m, pvp, ctladdr)
E 159
I 159
D 166
sendoff(e, m, pvp, ctladdr, crlf)
E 166
I 166
sendoff(e, m, pvp, ctladdr)
E 166
E 159
	register ENVELOPE *e;
	MAILER *m;
E 154
	char **pvp;
D 100
	int (*editfcn)();
E 100
I 58
	ADDRESS *ctladdr;
I 159
D 166
	bool crlf;
E 166
E 159
E 58
{
D 72
	auto int st;
E 72
I 72
	auto FILE *mfile;
	auto FILE *rfile;
E 72
	register int i;
I 72
D 100
	extern putmessage();
E 100
E 72
	int pid;
I 72

	/*
	**  Create connection to mailer.
	*/

	pid = openmailer(m, pvp, ctladdr, FALSE, &mfile, &rfile);
	if (pid < 0)
		return (-1);

	/*
	**  Format and send message.
I 154
D 163
	**	We ignore broken pipes so that the mailer need not read
	**	its input if it is not convenient to do so (e.g., on
	**	some error).
E 163
E 154
	*/

D 163
	(void) signal(SIGPIPE, SIG_IGN);
E 163
D 100
	if (editfcn == NULL)
		editfcn = putmessage;
	
	(*editfcn)(mfile, m, FALSE);
E 100
I 100
D 159
	putfromline(mfile, m);
D 154
	(*CurEnv->e_puthdr)(mfile, m, CurEnv);
E 154
I 154
	(*e->e_puthdr)(mfile, m, e);
E 159
I 159
D 166
	putfromline(mfile, m, crlf);
	(*e->e_puthdr)(mfile, m, e, crlf);
E 159
E 154
	fprintf(mfile, "\n");
D 154
	(*CurEnv->e_putbody)(mfile, m, FALSE);
E 154
I 154
D 157
	(*e->e_putbody)(mfile, m, FALSE);
E 157
I 157
D 159
	(*e->e_putbody)(mfile, m, FALSE, e);
E 159
I 159
	(*e->e_putbody)(mfile, m, FALSE, e, crlf);
E 166
I 166
	putfromline(mfile, m);
	(*e->e_puthdr)(mfile, m, e);
	putline("\n", mfile, m);
	(*e->e_putbody)(mfile, m, e);
E 166
E 159
E 157
E 154
E 100
	(void) fclose(mfile);

	i = endmailer(pid, pvp[0]);
D 154
	giveresponse(i, TRUE, m);
E 154
I 154
D 156
	giveresponse(i, m);
E 156
E 154
I 89

	/* arrange a return receipt if requested */
D 99
	if (RetReceipt && bitset(M_LOCAL, m->m_flags) && i == EX_OK)
E 99
I 99
D 128
	if (CurEnv->e_retreceipt && bitset(M_LOCAL, m->m_flags) && i == EX_OK)
E 128
I 128
D 154
	if (CurEnv->e_receiptto != NULL && bitset(M_LOCAL, m->m_flags))
E 154
I 154
D 168
	if (e->e_receiptto != NULL && bitset(M_LOCAL, m->m_flags))
E 168
I 168
	if (e->e_receiptto != NULL && bitnset(M_LOCAL, m->m_flags))
E 168
E 154
E 128
E 99
	{
D 99
		SendReceipt = TRUE;
		fprintf(Xscript, "%s... successfully delivered\n", To);
E 99
I 99
D 152
		CurEnv->e_sendreceipt = TRUE;
D 128
		fprintf(Xscript, "%s... successfully delivered\n", CurEnv->e_to);
E 128
I 128
		if (ExitStat == EX_OK)
E 152
I 152
D 154
		CurEnv->e_flags |= EF_SENDRECEIPT;
E 154
I 154
		e->e_flags |= EF_SENDRECEIPT;
E 154
D 156
		if (ExitStat == EX_OK && Xscript != NULL)
E 152
			fprintf(Xscript, "%s... successfully delivered\n",
D 154
				CurEnv->e_to);
E 154
I 154
				e->e_to);
E 156
E 154
E 128
E 99
		/* do we want to send back more info? */
	}

E 89
	return (i);
}
/*
**  ENDMAILER -- Wait for mailer to terminate.
**
**	We should never get fatal errors (e.g., segmentation
**	violation), so we report those specially.  For other
**	errors, we choose a status message (into statmsg),
**	and if it represents an error, we print it.
**
**	Parameters:
**		pid -- pid of mailer.
**		name -- name of mailer (for error messages).
**
**	Returns:
**		exit code of mailer.
**
**	Side Effects:
**		none.
*/

endmailer(pid, name)
	int pid;
	char *name;
{
D 154
	register int i;
	auto int st;
E 154
I 154
	int st;
E 154

I 90
	/* in the IPC case there is nothing to wait for */
	if (pid == 0)
		return (EX_OK);

	/* wait for the mailer process to die and collect status */
E 90
D 132
	while ((i = wait(&st)) > 0 && i != pid)
		continue;
E 132
I 132
D 154
	do
E 154
I 154
	st = waitfor(pid);
	if (st == -1)
E 154
	{
D 154
		errno = 0;
		i = wait(&st);
D 133
		if (i < 0 && errno == EINTR)
			continue;
	} while (i >= 0 && i != pid);
E 133
I 133
	} while ((i >= 0 && i != pid) || errno == EINTR);
E 133
E 132
	if (i < 0)
	{
		syserr("wait");
		return (-1);
E 154
I 154
		syserr("endmailer %s: wait", name);
		return (EX_SOFTWARE);
E 154
	}
I 90

	/* see if it died a horrid death */
E 90
	if ((st & 0377) != 0)
	{
D 154
		syserr("%s: stat %o", name, st);
E 154
I 154
D 190
		syserr("endmailer %s: stat %o", name, st);
E 154
		ExitStat = EX_UNAVAILABLE;
D 154
		return (-1);
E 154
I 154
		return (EX_UNAVAILABLE);
E 190
I 190
		syserr("mailer %s died with signal %o", name, st);
		ExitStat = EX_TEMPFAIL;
		return (EX_TEMPFAIL);
E 190
E 154
	}
I 90

	/* normal death -- return status */
E 90
D 154
	i = (st >> 8) & 0377;
	return (i);
E 154
I 154
	st = (st >> 8) & 0377;
	return (st);
E 154
}
/*
**  OPENMAILER -- open connection to mailer.
**
**	Parameters:
**		m -- mailer descriptor.
**		pvp -- parameter vector to pass to mailer.
**		ctladdr -- controlling address for user.
**		clever -- create a full duplex connection.
**		pmfile -- pointer to mfile (to mailer) connection.
**		prfile -- pointer to rfile (from mailer) connection.
**
**	Returns:
D 90
**		pid of mailer.
E 90
I 90
**		pid of mailer ( > 0 ).
E 90
**		-1 on error.
I 90
**		zero on an IPC connection.
E 90
**
**	Side Effects:
**		creates a mailer in a subprocess.
*/

openmailer(m, pvp, ctladdr, clever, pmfile, prfile)
D 154
	struct mailer *m;
E 154
I 154
	MAILER *m;
E 154
	char **pvp;
	ADDRESS *ctladdr;
	bool clever;
	FILE **pmfile;
	FILE **prfile;
{
	int pid;
E 72
D 71
	int pvect[2];
E 71
I 71
	int mpvect[2];
I 72
	int rpvect[2];
E 72
E 71
	FILE *mfile;
D 72
	extern putmessage();
E 72
I 72
	FILE *rfile;
E 72
D 39
	extern pipesig();
E 39
	extern FILE *fdopen();
I 196
D 197
	char buf[MAXNAME];
E 197
E 196

# ifdef DEBUG
D 117
	if (Debug)
E 117
I 117
	if (tTd(11, 1))
E 117
E 26
	{
D 26
		usrerr("name too long");
		return (-1);
E 26
I 26
D 72
		printf("Sendoff:\n");
E 72
I 72
D 134
		printf("openmailer:\n");
E 134
I 134
		printf("openmailer:");
E 134
E 72
		printav(pvp);
E 26
	}
I 26
# endif DEBUG
I 66
	errno = 0;
E 66

I 192
	CurHostName = m->m_mailer;

E 192
I 90
D 154
# ifdef DAEMON
E 154
	/*
	**  Deal with the special case of mail handled through an IPC
	**  connection.
	**	In this case we don't actually fork.  We must be
	**	running SMTP for this to work.  We will return a
	**	zero pid to indicate that we are running IPC.
I 170
	**  We also handle a debug version that just talks to stdin/out.
E 170
	*/
I 170

#ifdef DEBUG
	/* check for Local Person Communication -- not for mortals!!! */
	if (strcmp(m->m_mailer, "[LPC]") == 0)
	{
		*pmfile = stdout;
		*prfile = stdin;
		return (0);
	}
#endif DEBUG
E 170

	if (strcmp(m->m_mailer, "[IPC]") == 0)
	{
I 190
#ifdef HOSTINFO
		register STAB *st;
		extern STAB *stab();
#endif HOSTINFO
E 190
I 154
#ifdef DAEMON
E 154
D 196
		register int i;
E 196
I 196
		register int i, j;
E 196
I 112
		register u_short port;
E 112

I 192
		CurHostName = pvp[1];
E 192
		if (!clever)
			syserr("non-clever IPC");
D 96
		i = makeconnection(pvp[1], pmfile, prfile);
E 96
I 96
		if (pvp[2] != NULL)
D 112
			i = atoi(pvp[2]);
E 112
I 112
			port = atoi(pvp[2]);
E 112
		else
D 112
			i = 0;
		i = makeconnection(pvp[1], i, pmfile, prfile);
E 112
I 112
			port = 0;
I 196
D 199
		for (j = 0; j < nmx; j++)
E 199
I 199
		for (j = 0; j < Nmx; j++)
E 199
		{
D 199
			CurHostName = mxhosts[j];
E 199
I 199
			CurHostName = MxHosts[j];
E 199
D 197
			expand("\001j", buf, &buf[sizeof buf - 1], CurEnv);
			if (sameword(CurHostName, buf))
				break;
E 197
E 196
I 190
#ifdef HOSTINFO
		/* see if we have already determined that this host is fried */
D 196
		st = stab(pvp[1], ST_HOST, ST_FIND);
		if (st == NULL || st->s_host.ho_exitstat == EX_OK)
			i = makeconnection(pvp[1], port, pmfile, prfile);
		else
I 192
		{
E 192
			i = st->s_host.ho_exitstat;
I 192
			errno = st->s_host.ho_errno;
		}
E 196
I 196
D 199
			st = stab(mxhosts[j], ST_HOST, ST_FIND);
E 199
I 199
			st = stab(MxHosts[j], ST_HOST, ST_FIND);
E 199
D 207
			if (st == NULL || st->s_host.ho_exitstat == EX_OK)
E 207
I 207
			if (st == NULL || st->s_host.ho_exitstat == EX_OK) {
				if (j > 1)
					message(Arpa_Info,
					    "Connecting to %s (%s)...",
					    MxHosts[j], m->m_name);
E 207
D 199
				i = makeconnection(mxhosts[j], port, pmfile, prfile);
E 199
I 199
				i = makeconnection(MxHosts[j], port, pmfile, prfile);
I 207
			}
E 207
E 199
			else
			{
				i = st->s_host.ho_exitstat;
				errno = st->s_host.ho_errno;
			}
E 196
E 192
#else HOSTINFO
E 190
D 196
		i = makeconnection(pvp[1], port, pmfile, prfile);
E 196
I 196
D 199
			i = makeconnection(mxhosts[j], port, pmfile, prfile);
E 199
I 199
			i = makeconnection(MxHosts[j], port, pmfile, prfile);
E 199
E 196
I 190
#endif HOSTINFO
E 190
E 112
E 96
D 196
		if (i != EX_OK)
I 92
		{
E 196
I 196
			if (i != EX_OK)
			{
E 196
I 190
#ifdef HOSTINFO
D 196
			/* enter status of this host */
			if (st == NULL)
				st = stab(pvp[1], ST_HOST, ST_ENTER);
			st->s_host.ho_exitstat = i;
			st->s_host.ho_errno = errno;
E 196
I 196
				/* enter status of this host */
				if (st == NULL)
D 199
					st = stab(mxhosts[j], ST_HOST, ST_ENTER);
E 199
I 199
					st = stab(MxHosts[j], ST_HOST, ST_ENTER);
E 199
				st->s_host.ho_exitstat = i;
				st->s_host.ho_errno = errno;
E 196
#endif HOSTINFO
E 190
D 196
			ExitStat = i;
E 92
			return (-1);
E 196
I 196
				ExitStat = i;
				continue;
			}
			else
				return (0);
E 196
I 92
		}
E 92
D 196
		else
			return (0);
E 196
I 196
		return (-1);
E 196
I 154
#else DAEMON
		syserr("openmailer: no IPC");
		return (-1);
#endif DAEMON
E 154
	}
D 154
# endif DAEMON
E 154

E 90
E 26
D 32
	rewind(stdin);

E 32
D 19
	/* create a pipe if we will need one */
	if (editfcn != NULL && pipe(pvect) < 0)
E 19
I 19
	/* create a pipe to shove the mail through */
D 71
	if (pipe(pvect) < 0)
E 71
I 71
	if (pipe(mpvect) < 0)
E 71
E 19
	{
D 72
		syserr("pipe");
E 72
I 72
D 154
		syserr("pipe (to mailer)");
E 154
I 154
		syserr("openmailer: pipe (to mailer)");
E 154
E 72
		return (-1);
	}
I 72

I 79
D 154
# ifdef SMTP
E 154
I 154
#ifdef SMTP
E 154
E 79
	/* if this mailer speaks smtp, create a return pipe */
	if (clever && pipe(rpvect) < 0)
	{
D 154
		syserr("pipe (from mailer)");
E 154
I 154
		syserr("openmailer: pipe (from mailer)");
E 154
		(void) close(mpvect[0]);
		(void) close(mpvect[1]);
		return (-1);
	}
I 79
D 154
# endif SMTP
E 154
I 154
#endif SMTP
E 154
E 79

I 90
	/*
	**  Actually fork the mailer process.
	**	DOFORK is clever about retrying.
I 195
	**
	**	Dispose of SIGCHLD signal catchers that may be laying
	**	around so that endmail will get it.
E 195
	*/

I 115
D 117
	fflush(Xscript);				/* for debugging */
E 117
I 117
D 152
	(void) fflush(Xscript);				/* for debugging */
E 152
I 152
D 157
	if (Xscript != NULL)
		(void) fflush(Xscript);			/* for debugging */
E 157
I 157
	if (CurEnv->e_xfp != NULL)
		(void) fflush(CurEnv->e_xfp);		/* for debugging */
E 157
I 154
	(void) fflush(stdout);
I 195
# ifdef SIGCHLD
	(void) signal(SIGCHLD, SIG_DFL);
# endif SIGCHLD
E 195
E 154
E 152
E 117
E 115
E 90
E 72
I 31
D 48
	for (i = NFORKTRIES; i-- > 0; )
	{
E 31
I 6
# ifdef VFORK
D 31
	pid = vfork();
E 31
I 31
		pid = vfork();
E 31
# else
E 6
D 31
	pid = fork();
E 31
I 31
		pid = fork();
E 31
I 6
# endif
I 31
		if (pid >= 0)
			break;
D 36
		sleep(NFORKTRIES - i);
E 36
I 36
		sleep((unsigned) NFORKTRIES - i);
E 36
	}
E 48
I 48
	DOFORK(XFORK);
I 55
	/* pid is set by DOFORK */
E 55
E 48
E 31
E 6
	if (pid < 0)
	{
I 90
		/* failure */
E 90
D 154
		syserr("Cannot fork");
E 154
I 154
		syserr("openmailer: cannot fork");
E 154
D 19
		if (editfcn != NULL)
		{
			close(pvect[0]);
			close(pvect[1]);
		}
E 19
I 19
D 36
		close(pvect[0]);
		close(pvect[1]);
E 36
I 36
D 71
		(void) close(pvect[0]);
		(void) close(pvect[1]);
E 71
I 71
		(void) close(mpvect[0]);
		(void) close(mpvect[1]);
I 154
#ifdef SMTP
E 154
I 72
		if (clever)
		{
			(void) close(rpvect[0]);
			(void) close(rpvect[1]);
		}
I 154
#endif SMTP
E 154
E 72
E 71
E 36
E 19
		return (-1);
	}
	else if (pid == 0)
	{
I 180
		int i;
I 190
		extern int DtableSize;
E 190

E 180
		/* child -- set up input & exec mailer */
I 10
		/* make diagnostic output be standard output */
I 49
D 65
		(void) signal(SIGINT, SIG_DFL);
		(void) signal(SIGHUP, SIG_DFL);
E 65
I 65
		(void) signal(SIGINT, SIG_IGN);
		(void) signal(SIGHUP, SIG_IGN);
E 65
		(void) signal(SIGTERM, SIG_DFL);
I 71

		/* arrange to filter standard & diag output of command */
D 72
		if (OutChannel != stdout)
E 72
I 72
		if (clever)
E 72
		{
I 72
			(void) close(rpvect[0]);
E 72
			(void) close(1);
I 72
			(void) dup(rpvect[1]);
			(void) close(rpvect[1]);
		}
D 147
		else if (OutChannel != stdout)
E 147
I 147
D 150
		else if (Smtp || HoldErrs)
E 150
I 150
		else if (OpMode == MD_SMTP || HoldErrs)
E 150
E 147
		{
I 154
			/* put mailer output in transcript */
E 154
			(void) close(1);
E 72
D 147
			(void) dup(fileno(OutChannel));
E 147
I 147
D 157
			(void) dup(fileno(Xscript));
E 157
I 157
			(void) dup(fileno(CurEnv->e_xfp));
E 157
E 147
		}
E 71
E 49
D 36
		close(2);
		dup(1);
E 10
		signal(SIGINT, SIG_IGN);
D 19
		if (editfcn != NULL)
E 19
I 19
		close(0);
E 36
I 36
		(void) close(2);
		(void) dup(1);
I 71

		/* arrange to get standard input */
		(void) close(mpvect[1]);
E 71
D 49
		(void) signal(SIGINT, SIG_IGN);
E 49
		(void) close(0);
E 36
D 71
		if (dup(pvect[0]) < 0)
E 71
I 71
		if (dup(mpvect[0]) < 0)
E 71
E 19
		{
D 19
			close(0);
			if (dup(pvect[0]) < 0)
			{
				syserr("Cannot dup to zero!");
D 9
				exit(EX_OSERR);
E 9
I 9
				_exit(EX_OSERR);
E 9
			}
			close(pvect[0]);
			close(pvect[1]);
E 19
I 19
			syserr("Cannot dup to zero!");
			_exit(EX_OSERR);
E 19
		}
I 19
D 36
		close(pvect[0]);
		close(pvect[1]);
E 36
I 36
D 71
		(void) close(pvect[0]);
		(void) close(pvect[1]);
E 71
I 71
		(void) close(mpvect[0]);
E 71
E 36
E 19
D 20
		if (!flagset(M_RESTR, m->m_flags))
E 20
I 20
D 168
		if (!bitset(M_RESTR, m->m_flags))
E 168
I 168
		if (!bitnset(M_RESTR, m->m_flags))
E 168
I 49
		{
I 60
D 61
			extern int DefUid, DefGid;
E 61
I 61
D 183
			if (ctladdr->q_uid == 0)
E 183
I 183
			if (ctladdr == NULL || ctladdr->q_uid == 0)
E 183
			{
D 83
				extern int DefUid, DefGid;
E 61

E 83
E 60
E 49
E 20
D 36
			setuid(getuid());
E 36
I 36
D 58
			(void) setuid(getuid());
I 49
			(void) setgid(getgid());
E 58
I 58
D 61
			(void) setuid(ctladdr->q_uid);
			(void) setgid(ctladdr->q_gid);
I 60
			if (getruid() == 0)
E 61
I 61
				(void) setgid(DefGid);
				(void) setuid(DefUid);
			}
			else
E 61
			{
D 61
				setuid(DefUid);
				setgid(DefGid);
E 61
I 61
				(void) setgid(ctladdr->q_gid);
				(void) setuid(ctladdr->q_uid);
E 61
			}
E 60
E 58
		}
E 49
E 36
D 18
# ifdef LOG
D 16
		initlog(NULL, 0, LOG_CLOSE);
E 16
I 16
		closelog();
E 16
# endif LOG
E 18
I 6
D 148
# ifndef VFORK
E 148
I 148
D 154
# ifndef VMUNIX
E 154
I 154

E 154
E 148
D 180
		/*
D 18
		 * We have to be careful with vfork - we can't mung up the
		 * memory but we don't want the mailer to inherit any extra
		 * open files.  Chances are the mailer won't
		 * care about an extra file, but then again you never know.
		 * Actually, we would like to close(fileno(pwf)), but it's
		 * declared static so we can't.  But if we fclose(pwf), which
		 * is what endpwent does, it closes it in the parent too and
		 * the next getpwnam will be slower.  If you have a weird mailer
		 * that chokes on the extra file you should do the endpwent().
		 */
E 18
I 18
		**  We have to be careful with vfork - we can't mung up the
		**  memory but we don't want the mailer to inherit any extra
		**  open files.  Chances are the mailer won't
		**  care about an extra file, but then again you never know.
		**  Actually, we would like to close(fileno(pwf)), but it's
		**  declared static so we can't.  But if we fclose(pwf), which
		**  is what endpwent does, it closes it in the parent too and
		**  the next getpwnam will be slower.  If you have a weird
		**  mailer that chokes on the extra file you should do the
D 148
		**  endpwent().
E 148
I 148
		**  endpwent().			-MRH
E 148
		**
		**  Similar comments apply to log.  However, openlog is
		**  clever enough to set the FIOCLEX mode on the file,
		**  so it will be closed automatically on the exec.
		*/
E 180
I 180
		/* arrange for all the files to be closed */
D 190
		for (i = 3; i < 50; i++)
E 190
I 190
		for (i = 3; i < DtableSize; i++)
E 190
D 208
#ifdef FIOCLEX
E 208
			(void) ioctl(i, FIOCLEX, 0);
D 208
#else FIOCLEX
			(void) close(i);
#endif FIOCLEX
E 208
E 180

E 18
E 6
D 154
		endpwent();
I 6
D 18
# endif
E 18
I 18
# ifdef LOG
		closelog();
# endif LOG
D 148
# endif VFORK
E 148
I 148
# endif VMUNIX
E 154
I 154
D 180
		closeall();
E 154
E 148
I 90

E 180
		/* try to execute the mailer */
E 90
E 18
E 6
D 191
		execv(m->m_mailer, pvp);
E 191
I 191
		execve(m->m_mailer, pvp, UserEnviron);
E 191
I 90
D 208

E 90
D 180
		/* syserr fails because log is closed */
		/* syserr("Cannot exec %s", m->m_mailer); */
E 180
I 180
#ifdef FIOCLEX
E 208
		syserr("Cannot exec %s", m->m_mailer);
D 208
#else FIOCLEX
E 180
I 17
D 48
		printf("Cannot exec %s\n", m->m_mailer);
E 48
I 48
		printf("Cannot exec '%s' errno=%d\n", m->m_mailer, errno);
E 48
D 36
		fflush(stdout);
E 36
I 36
		(void) fflush(stdout);
I 180
#endif FIOCLEX
E 208
E 180
E 36
E 17
D 8
		exit(EX_UNAVAIL);
E 8
I 8
D 9
		exit(EX_UNAVAILABLE);
E 9
I 9
D 184
		_exit(EX_UNAVAILABLE);
E 184
I 184
D 190
		if (m == LocalMailer)
E 190
I 190
		if (m == LocalMailer || errno == EIO || errno == EAGAIN ||
		    errno == ENOMEM || errno == EPROCLIM)
E 190
			_exit(EX_TEMPFAIL);
		else
			_exit(EX_UNAVAILABLE);
E 184
E 9
E 8
	}

D 19
	/* arrange to write out header message if error */
	if (editfcn != NULL)
	{
		close(pvect[0]);
		signal(SIGPIPE, pipesig);
		mfile = fdopen(pvect[1], "w");
		(*editfcn)(mfile);
		fclose(mfile);
	}
E 19
I 19
D 71
	/* write out message to mailer */
D 36
	close(pvect[0]);
	signal(SIGPIPE, pipesig);
E 36
I 36
	(void) close(pvect[0]);
E 71
I 71
	/*
D 72
	**  Format and write message to mailer.
E 72
I 72
	**  Set up return value.
E 72
	*/

	(void) close(mpvect[0]);
E 71
D 39
	(void) signal(SIGPIPE, pipesig);
E 39
I 39
D 72
	(void) signal(SIGPIPE, SIG_IGN);
E 72
E 39
E 36
D 71
	mfile = fdopen(pvect[1], "w");
E 71
I 71
	mfile = fdopen(mpvect[1], "w");
E 71
D 72
	if (editfcn == NULL)
		editfcn = putmessage;
	(*editfcn)(mfile, m);
D 36
	fclose(mfile);
E 36
I 36
	(void) fclose(mfile);
E 36
E 19

	/*
	**  Wait for child to die and report status.
	**	We should never get fatal errors (e.g., segmentation
	**	violation), so we report those specially.  For other
	**	errors, we choose a status message (into statmsg),
	**	and if it represents an error, we print it.
	*/

	while ((i = wait(&st)) > 0 && i != pid)
		continue;
	if (i < 0)
E 72
I 72
	if (clever)
E 72
	{
D 72
		syserr("wait");
		return (-1);
E 72
I 72
		(void) close(rpvect[1]);
		rfile = fdopen(rpvect[0], "r");
E 72
	}
D 72
	if ((st & 0377) != 0)
	{
		syserr("%s: stat %o", pvp[0], st);
D 8
		ExitStat = EX_UNAVAIL;
E 8
I 8
		ExitStat = EX_UNAVAILABLE;
E 8
		return (-1);
	}
	i = (st >> 8) & 0377;
D 17
	giveresponse(i, FALSE, m);
E 17
I 17
	giveresponse(i, TRUE, m);
E 17
	return (i);
E 72
I 72

	*pmfile = mfile;
	*prfile = rfile;

	return (pid);
E 72
}
/*
**  GIVERESPONSE -- Interpret an error response from a mailer
**
**	Parameters:
**		stat -- the status code from the mailer (high byte
**			only; core dumps must have been taken care of
**			already).
D 154
**		force -- if set, force an error message output, even
**			if the mailer seems to like to print its own
**			messages.
E 154
**		m -- the mailer descriptor for this mailer.
**
**	Returns:
D 20
**		none.
E 20
I 20
D 36
**		stat.
E 36
I 36
**		none.
E 36
E 20
**
**	Side Effects:
D 7
**		Error may be set.
E 7
I 7
**		Errors may be incremented.
E 7
**		ExitStat may be set.
D 54
**
D 4
**	Requires:
**		usrerr
**		syserr
**		flagset
**		logmsg (sys)
**
E 4
**	Called By:
**		deliver
E 54
D 4
**
**	History:
**		2/18/80 -- broken from deliver.
E 4
*/

D 154
giveresponse(stat, force, m)
E 154
I 154
D 172
/*ARGSUSED*/
E 172
D 161
giveresponse(stat, m)
E 161
I 161
giveresponse(stat, m, e)
E 161
E 154
	int stat;
D 109
	int force;
E 109
I 109
D 154
	bool force;
E 109
	register struct mailer *m;
E 154
I 154
	register MAILER *m;
I 161
	ENVELOPE *e;
E 161
E 154
{
	register char *statmsg;
	extern char *SysExMsg[];
	register int i;
D 202
	extern int N_SysEx;
E 202
I 202
	extern int N_SysEx, h_errno;
E 202
I 11
D 51
	extern long MsgSize;
E 51
D 161
	char buf[30];
E 161
I 161
	char buf[MAXLINE];
I 172

#ifdef lint
	if (m == NULL)
		return;
#endif lint
E 172
E 161
I 22
D 36
	extern char *sprintf();
E 36
E 22
E 11

I 54
	/*
	**  Compute status message from code.
	*/

E 54
	i = stat - EX__BASE;
D 154
	if (i < 0 || i > N_SysEx)
		statmsg = NULL;
E 154
I 154
	if (stat == 0)
		statmsg = "250 Sent";
	else if (i < 0 || i > N_SysEx)
	{
		(void) sprintf(buf, "554 unknown mailer error %d", stat);
		stat = EX_UNAVAILABLE;
		statmsg = buf;
	}
I 161
	else if (stat == EX_TEMPFAIL)
	{
D 178
		extern char *sys_errlist[];
		extern int sys_nerr;

E 178
D 162
		(void) sprintf(buf, "%.3s ", SysExMsg[i]);
		if (errno > 0 && errno < sys_nerr)
E 162
I 162
		(void) strcpy(buf, SysExMsg[i]);
D 193
		if (errno != 0)
E 193
I 193
		if (h_errno == TRY_AGAIN)
E 193
E 162
		{
D 162
			(void) strcat(buf, sys_errlist[errno]);
			(void) strcat(buf, " [deferred]");
E 162
I 162
D 178
			(void) strcat(buf, ": ");
			if (errno > 0 && errno < sys_nerr)
				(void) strcat(buf, sys_errlist[errno]);
			else
			{
				char xbuf[30];
E 178
I 178
			extern char *errstring();
E 178

I 185
D 193
			statmsg = errstring(errno);
E 193
I 193
			statmsg = errstring(h_errno+MAX_ERRNO);
E 193
		}
		else
		{
I 193
			if (errno != 0)
			{
				extern char *errstring();

				statmsg = errstring(errno);
			}
			else
			{
E 193
#ifdef SMTP
D 193
			extern char SmtpError[];
E 193
I 193
				extern char SmtpError[];
E 193

D 193
			statmsg = SmtpError;
E 193
I 193
				statmsg = SmtpError;
E 193
#else SMTP
D 193
			statmsg = NULL;
E 193
I 193
				statmsg = NULL;
E 193
#endif SMTP
I 193
			}
E 193
		}
		if (statmsg != NULL && statmsg[0] != '\0')
		{
E 185
D 178
				(void) sprintf(xbuf, "Error %d", errno);
				(void) strcat(buf, xbuf);
			}
E 178
I 178
			(void) strcat(buf, ": ");
D 185
			(void) strcat(buf, errstring(errno));
E 185
I 185
			(void) strcat(buf, statmsg);
E 185
E 178
E 162
		}
D 162
		else
			(void) strcat(buf, "deferred");
E 162
		statmsg = buf;
	}
E 161
E 154
	else
I 185
	{
E 185
		statmsg = SysExMsg[i];
I 185
	}
E 185
I 154

	/*
	**  Print the message as appropriate
	*/

E 154
D 161
	if (stat == 0)
E 161
I 161
	if (stat == EX_OK || stat == EX_TEMPFAIL)
E 161
I 33
D 154
	{
E 33
D 41
		statmsg = "ok";
E 41
I 41
D 45
		if (bitset(M_FINAL, m->m_flags))
E 45
I 45
D 123
		if (bitset(M_LOCAL, m->m_flags))
E 45
			statmsg = "delivered";
		else
			statmsg = "queued";
E 123
I 123
D 127
		statmsg = "sent";
E 123
E 41
I 33
D 106
		if (Verbose)
D 41
			message("050", "ok");
E 41
I 41
D 42
			message("050", statmsg);
E 42
I 42
			message(Arpa_Info, statmsg);
E 106
I 106
		message(Arpa_Info, statmsg);
E 127
I 127
		statmsg = "250 sent";
E 154
		message(Arpa_Info, &statmsg[4]);
E 127
E 106
E 42
E 41
D 154
	}
E 154
I 79
D 127
# ifdef QUEUE
E 127
E 79
I 69
D 161
	else if (stat == EX_TEMPFAIL)
D 154
	{
E 154
D 106
		if (Verbose)
			message(Arpa_Info, "transmission deferred");
E 106
I 106
D 123
		message(Arpa_Info, "transmission deferred");
E 123
I 123
D 141
		message(Arpa_Info, "deferred");
E 141
I 141
D 143
		message(Arpa_Info, "queued");
E 143
I 143
		message(Arpa_Info, "deferred");
E 161
E 143
E 141
E 123
E 106
D 154
	}
E 154
I 79
D 127
# endif QUEUE
E 127
E 79
E 69
E 33
	else
	{
D 7
		Error++;
E 7
I 7
		Errors++;
I 154
		usrerr(statmsg);
E 154
I 92
D 152
		FatalErrors = TRUE;
E 152
I 152
D 156
		CurEnv->e_flags |= EF_FATALERRS;
E 156
E 152
E 92
E 7
D 154
		if (statmsg == NULL && m->m_badstat != 0)
		{
			stat = m->m_badstat;
			i = stat - EX__BASE;
# ifdef DEBUG
			if (i < 0 || i >= N_SysEx)
				syserr("Bad m_badstat %d", stat);
			else
# endif DEBUG
D 114
			statmsg = SysExMsg[i];
E 114
I 114
				statmsg = SysExMsg[i];
E 114
		}
		if (statmsg == NULL)
			usrerr("unknown mailer response %d", stat);
D 20
		else if (force || !flagset(M_QUIET, m->m_flags))
E 20
I 20
D 33
		else if (force || !bitset(M_QUIET, m->m_flags))
E 33
I 33
		else if (force || !bitset(M_QUIET, m->m_flags) || Verbose)
E 33
E 20
D 127
			usrerr("%s", statmsg);
E 127
I 127
			usrerr(statmsg);
E 127
I 114
D 152
		else
E 152
I 152
		else if (Xscript != NULL)
E 152
D 127
			fprintf(Xscript, "%s\n", statmsg);
E 127
I 127
			fprintf(Xscript, "%s\n", &statmsg[4]);
E 154
E 127
E 114
	}

	/*
	**  Final cleanup.
	**	Log a record of the transaction.  Compute the new
	**	ExitStat -- if we already had an error, stick with
	**	that.
	*/

D 11
# ifdef LOG
E 11
D 154
	if (statmsg == NULL)
D 11
		logmsg(LOG_INFO, "%s->%s: error %d", From.q_paddr, To, stat);
	else
		logmsg(LOG_INFO, "%s->%s: %s", From.q_paddr, To, statmsg);
E 11
I 11
	{
D 36
		sprintf(buf, "error %d", stat);
E 36
I 36
D 127
		(void) sprintf(buf, "error %d", stat);
E 127
I 127
		(void) sprintf(buf, "554 error %d", stat);
E 127
E 36
		statmsg = buf;
	}

D 143
# ifdef LOG
E 143
I 143
	/* log it in the system log */
E 154
E 143
D 18
	logmsg(LOG_INFO, "%s->%s: %ld: %s", From.q_paddr, To, MsgSize, statmsg);
E 18
I 18
D 99
	syslog(LOG_INFO, "%s->%s: %ld: %s", From.q_paddr, To, MsgSize, statmsg);
E 99
I 99
D 117
	syslog(LOG_INFO, "%s->%s: %ld: %s", CurEnv->e_from.q_paddr, CurEnv->e_to, CurEnv->e_msgsize, statmsg);
E 117
I 117
D 118
	if (LogLevel > 1)
E 118
I 118
	if (LogLevel > ((stat == 0 || stat == EX_TEMPFAIL) ? 3 : 2))
E 118
D 121
		syslog(LOG_INFO, "%s: to=%s, stat=%s", MsgId, CurEnv->e_to, statmsg);
E 121
I 121
D 122
		syslog(LOG_INFO, "%s: to=%s, stat=%s", CurEnv->e_id,
				  CurEnv->e_to, statmsg);
E 122
I 122
D 143
	{
		extern char *pintvl();
E 143
I 143
		logdelivery(&statmsg[4]);
E 143

D 143
		syslog(LOG_INFO, "%s: to=%s, delay=%s, stat=%s", CurEnv->e_id,
D 124
		       CurEnv->e_to, pintvl(CurTime - CurEnv->e_ctime, TRUE),
E 124
I 124
		       CurEnv->e_to, pintvl(curtime() - CurEnv->e_ctime, TRUE),
E 124
D 127
		       statmsg);
E 127
I 127
		       &statmsg[4]);
E 127
	}
E 122
E 121
E 117
E 99
E 18
E 11
# endif LOG
E 143
I 143
D 154
	/* set the exit status appropriately */
E 154
E 143
I 79
D 127
# ifdef QUEUE
E 127
E 79
D 5
	if (ExitStat == EX_OK)
		ExitStat = stat;
E 5
I 5
D 69
	setstat(stat);
E 69
I 69
	if (stat != EX_TEMPFAIL)
I 79
D 127
# endif QUEUE
E 127
E 79
		setstat(stat);
I 161
	if (stat != EX_OK)
	{
		if (e->e_message != NULL)
			free(e->e_message);
		e->e_message = newstr(&statmsg[4]);
	}
I 162
	errno = 0;
I 193
	h_errno = 0;
E 193
E 162
E 161
I 143
}
/*
**  LOGDELIVERY -- log the delivery in the system log
**
**	Parameters:
**		stat -- the message to print for the status
**
**	Returns:
**		none
**
**	Side Effects:
**		none
*/

logdelivery(stat)
	char *stat;
{
	extern char *pintvl();

# ifdef LOG
	syslog(LOG_INFO, "%s: to=%s, delay=%s, stat=%s", CurEnv->e_id,
	       CurEnv->e_to, pintvl(curtime() - CurEnv->e_ctime, TRUE), stat);
# endif LOG
E 143
E 69
E 5
D 36
	return (stat);
E 36
}
/*
D 19
**  PUTHEADER -- insert the From header into some mail
E 19
I 19
D 100
**  PUTMESSAGE -- output a message to the final mailer.
E 100
I 100
**  PUTFROMLINE -- output a UNIX-style from line (or whatever)
E 100
E 19
**
D 19
**	For mailers such as 'msgs' that want the header inserted
**	into the mail, this edit filter inserts the From line and
D 13
**	then passes the rest of the message through.
E 19
I 19
D 100
**	This routine takes care of recreating the header from the
**	in-core copy, etc.
E 100
I 100
**	This can be made an arbitrary message separator by changing $l
E 100
E 19
E 13
I 13
**	then passes the rest of the message through.  If we have
**	managed to extract a date already, use that; otherwise,
**	use the current date/time.
E 13
**
I 100
D 181
**	One of the ugliest hacks seen by human eyes is
**	contained herein: UUCP wants those stupid
D 154
**	"remote from <host>" lines.  Why oh why does a
E 154
I 154
**	"emote from <host>" lines.  Why oh why does a
E 154
**	well-meaning programmer such as myself have to
**	deal with this kind of antique garbage????
E 181
I 181
**	One of the ugliest hacks seen by human eyes is contained herein:
**	UUCP wants those stupid "remote from <host>" lines.  Why oh why
**	does a well-meaning programmer such as myself have to deal with
**	this kind of antique garbage????
E 181
**
E 100
**	Parameters:
D 19
**		fp -- the file pointer for the output.
E 19
I 19
D 100
**		fp -- file to output onto.
**		m -- a mailer descriptor.
I 72
**		xdot -- if set, hide lines beginning with dot.
E 100
I 100
**		fp -- the file to output to.
**		m -- the mailer describing this entry.
I 159
D 166
**		crlf -- set if we want a CRLF at the end of the line.
E 166
E 159
E 100
E 72
E 19
**
**	Returns:
D 19
**		none
E 19
I 19
D 100
**		none.
E 100
I 100
**		none
E 100
E 19
**
**	Side Effects:
D 19
**		Puts a "From" line in UNIX format, and then
**			outputs the rest of the message.
**
D 4
**	Requires:
**		fprintf (sys)
**		fgets (sys)
**		fputs (sys)
**		time (sys)
**		ctime (sys)
**		ferror (sys)
**		syserr
**		setstat
**
E 4
**	Called By:
**		deliver
E 19
I 19
D 100
**		The message is written onto fp.
E 100
I 100
**		outputs some text to fp.
E 100
E 19
D 4
**
**	History:
**		1/8/80 -- written.
E 4
*/

D 19
putheader(fp)
	register FILE *fp;
E 19
I 19
D 72
putmessage(fp, m)
E 72
I 72
D 100
putmessage(fp, m, xdot)
E 72
	FILE *fp;
	struct mailer *m;
I 72
	bool xdot;
E 100
I 100
D 159
putfromline(fp, m)
E 159
I 159
D 166
putfromline(fp, m, crlf)
E 166
I 166
putfromline(fp, m)
E 166
E 159
	register FILE *fp;
	register MAILER *m;
E 100
E 72
E 19
{
I 173
D 181
	char *template = "$l\n";
E 181
I 181
	char *template = "\001l\n";
E 181
E 173
D 19
	char buf[MAXLINE + 1];
	long tim;
	extern char *ctime();
E 19
I 19
D 100
	char buf[BUFSIZ];
E 100
I 100
	char buf[MAXLINE];
E 100
D 72
	register int i;
E 72
D 54
	HDR *h;
E 19
I 15
	register char *p;
E 54
I 54
D 89
	register HDR *h;
E 54
D 19
	extern char *index();
E 19
I 19
	extern char *arpadate();
D 28
	extern char *hvalue();
E 28
	bool anyheader = FALSE;
D 25
	extern char *translate();
E 25
I 25
D 36
	extern char *expand();
E 36
E 25
I 22
	extern char *capitalize();
I 56
	extern char *hvalue();
	extern bool samefrom();
I 63
	char *of_line;
E 89
E 63
E 56
E 22
E 19
E 15
I 13
	extern char SentDate[];
E 13

I 25
D 54
	/* output "From" line unless supressed */
E 54
I 54
D 100
	/*
	**  Output "From" line unless supressed
I 77
	**
	**  >>>>>>>>>>	One of the ugliest hacks seen by human eyes is
	**  >>>>>>>>>>	contained herein: UUCP wants those stupid
D 81
	**  >> NOTE >>	"remote from <host>" lines.  Why oh why does a
	**  >>>>>>>>>>	well-meaning programmer such as myself have to
E 81
I 81
D 91
	**  >>>>>>>>>>	"remote from <host>" lines.  Why oh why does a
	**  >> NOTE >>	well-meaning programmer such as myself have to
E 91
I 91
	**  >> NOTE >>	"remote from <host>" lines.  Why oh why does a
	**  >>>>>>>>>>	well-meaning programmer such as myself have to
E 91
E 81
	**  >>>>>>>>>>	deal with this kind of antique garbage????
I 81
D 91
	**  >>>>>>>>>>  This even depends on the local UUCP host name
	**  >>>>>>>>>>  being in the $U macro!!!!
E 91
E 81
E 77
	*/
E 100
I 100
D 168
	if (bitset(M_NHDR, m->m_flags))
E 168
I 168
	if (bitnset(M_NHDR, m->m_flags))
E 168
		return;
E 100

E 54
D 100
	if (!bitset(M_NHDR, m->m_flags))
D 46
		fprintf(fp, "%s\n", FromLine);
E 46
I 46
	{
E 100
D 77
		(void) expand("$l", buf, &buf[sizeof buf - 1]);
E 77
I 77
D 78
		if (strcmp(m->m_name, "uucp") == 0)
E 78
I 78
D 79
		register char *p = rindex(m->m_mailer, '/');
E 79
I 79
# ifdef UGLYUUCP
D 84
		char *p = rindex(m->m_mailer, '/');
E 79

E 84
D 82
		if (p != NULL && strcmp(p, "/uux") == 0 &&
		    strcmp(m->m_name, "uucp") == 0)
E 82
I 82
D 100
		if (bitset(M_UGLYUUCP, m->m_flags))
E 82
E 78
D 81
			(void) expand("From $f  $d remote from $h", buf,
E 81
I 81
D 91
			(void) expand("From $f  $d remote from $U", buf,
E 91
I 91
		{
			extern char *macvalue();
			char *sys = macvalue('g');
			char *bang = index(sys, '!');
E 100
I 100
D 168
	if (bitset(M_UGLYUUCP, m->m_flags))
E 168
I 168
	if (bitnset(M_UGLYUUCP, m->m_flags))
E 168
	{
D 173
		extern char *macvalue();
D 134
		char *sys = macvalue('g');
E 134
I 134
		char *sys = macvalue('g', CurEnv);
E 134
		char *bang = index(sys, '!');
E 173
I 173
		char *bang;
		char xbuf[MAXLINE];
E 173
E 100

I 173
D 181
		expand("$g", buf, &buf[sizeof buf - 1], CurEnv);
E 181
I 181
		expand("\001g", buf, &buf[sizeof buf - 1], CurEnv);
E 181
		bang = index(buf, '!');
E 173
D 100
			if (bang == NULL)
				syserr("No ! in UUCP! (%s)", sys);
			else
				*bang = '\0';
			(void) expand("From $f  $d remote from $g", buf,
E 91
E 81
					&buf[sizeof buf - 1]);
I 91
			*bang = '!';
		}
E 100
I 100
		if (bang == NULL)
D 173
			syserr("No ! in UUCP! (%s)", sys);
E 173
I 173
			syserr("No ! in UUCP! (%s)", buf);
E 173
E 100
E 91
		else
I 154
		{
E 154
I 79
D 100
# endif UGLYUUCP
E 79
			(void) expand("$l", buf, &buf[sizeof buf - 1]);
E 77
		fprintf(fp, "%s\n", buf);
E 100
I 100
D 173
			*bang = '\0';
D 110
		expand("From $f  $d remote from $g", buf,
E 110
I 110
D 154
		expand("From $f  $d remote from $g\n", buf,
E 110
				&buf[sizeof buf - 1], CurEnv);
		*bang = '!';
E 154
I 154
			expand("From $f  $d remote from $g\n", buf,
					&buf[sizeof buf - 1], CurEnv);
			*bang = '!';
E 173
I 173
			*bang++ = '\0';
D 174
			(void) sprintf(xbuf, "From %s  $d remote from %s\n", buf, bang);
E 174
I 174
D 181
			(void) sprintf(xbuf, "From %s  $d remote from %s\n", bang, buf);
E 181
I 181
			(void) sprintf(xbuf, "From %s  \001d remote from %s\n", bang, buf);
E 181
E 174
			template = xbuf;
E 173
		}
E 154
E 100
	}
E 46
D 100

E 25
D 13
D 15
	time(&tim);
	fprintf(fp, "From %s %s", From.q_paddr, ctime(&tim));
E 13
I 13
	fprintf(fp, "From %s ", From.q_paddr);
	if (SentDate[0] == '\0')
	{
		time(&tim);
		fprintf(fp, "%s", ctime(&tim));
	}
	else
		fprintf(fp, "%s", SentDate);
E 13
	while (fgets(buf, sizeof buf, stdin) != NULL && !ferror(fp))
E 15
I 15
D 19
	/* output the header part */
	fgets(buf, sizeof buf, stdin);
	if (strncmp(buf, "From ", 5) != 0 || (p = index(&buf[5], ' ')) == NULL)
E 19
I 19
D 28
	/* clear all "used" bits */
E 28
I 28
D 54
	/* output all header lines */
E 54
I 54
	/*
	**  Output all header lines
	*/

I 89
	putheader(fp, m);

	/*
	**  Output the body of the message
	*/

	if (TempFile != NULL)
	{
		rewind(TempFile);
		while (!ferror(fp) && fgets(buf, sizeof buf, TempFile) != NULL)
			fprintf(fp, "%s%s", xdot && buf[0] == '.' ? "." : "", buf);

		if (ferror(TempFile))
		{
			syserr("putmessage: read error");
D 92
			setstat(EX_IOERR);
E 92
I 92
			ExitStat = EX_IOERR;
E 92
		}
	}

	(void) fflush(fp);
	if (ferror(fp) && errno != EPIPE)
	{
		syserr("putmessage: write error");
D 92
		setstat(EX_IOERR);
E 92
I 92
		ExitStat = EX_IOERR;
E 92
	}
	errno = 0;
E 100
I 100
D 173
	else
E 173
# endif UGLYUUCP
D 173
		expand("$l\n", buf, &buf[sizeof buf - 1], CurEnv);
E 173
I 173
	expand(template, buf, &buf[sizeof buf - 1], CurEnv);
E 173
D 107
	fputs(buf, fp);
E 107
I 107
D 159
	putline(buf, fp, bitset(M_FULLSMTP, m->m_flags));
E 159
I 159
D 166
	putline(buf, fp, crlf, bitset(M_FULLSMTP, m->m_flags));
E 166
I 166
	putline(buf, fp, m);
E 166
E 159
E 107
E 100
}
/*
D 100
**  PUTHEADER -- put the header part of a message
E 100
I 100
D 154
**  PUTHEADER -- put the header part of a message from the in-core copy
E 100
**
**	Parameters:
**		fp -- file to put it on.
**		m -- mailer to use.
I 100
**		e -- envelope to use.
E 100
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

D 100
putheader(fp, m)
E 100
I 100
putheader(fp, m, e)
E 100
	register FILE *fp;
	register struct mailer *m;
I 100
	register ENVELOPE *e;
E 100
{
	char buf[BUFSIZ];
	register HDR *h;
	extern char *arpadate();
D 100
	bool anyheader = FALSE;
E 100
	extern char *capitalize();
D 134
	extern char *hvalue();
E 134
D 153
	extern bool samefrom();
E 153
D 128
	char *of_line;
E 128
I 107
	char obuf[MAXLINE];
D 153
	register char *obp;
E 153
	bool fullsmtp = bitset(M_FULLSMTP, m->m_flags);
E 107

I 142
	if (bitset(M_LOCAL, m->m_flags) && fullsmtp)
		fprintf(fp, "Return-Path: <%s>\n", e->e_from);
E 142
E 89
I 63
D 128
	of_line = hvalue("original-from");
E 128
E 63
E 54
E 28
D 99
	for (h = Header; h != NULL; h = h->h_link)
E 99
I 99
D 100
	for (h = CurEnv->e_header; h != NULL; h = h->h_link)
E 100
I 100
	for (h = e->e_header; h != NULL; h = h->h_link)
E 100
E 99
D 28
		h->h_flags &= ~H_USED;

	/* output date if needed by mailer */
	p = hvalue("date");
D 20
	if (flagset(M_NEEDDATE, m->m_flags) && p == NULL)
E 20
I 20
	if (bitset(M_NEEDDATE, m->m_flags) && p == NULL)
E 20
		p = arpadate(Date);
	if (p != NULL)
E 28
E 19
	{
I 54
		register char *p;
I 56
D 99
		char *origfrom = OrigFrom;
E 99
I 99
D 100
		char *origfrom = CurEnv->e_origfrom;
E 100
I 100
D 128
		char *origfrom = e->e_origfrom;
E 100
E 99
I 63
		bool nooutput;
E 128
E 63
E 56

I 63
D 128
		nooutput = FALSE;
E 128
E 63
E 54
D 19
		time(&tim);
		fprintf(fp, "From %s %s", From.q_paddr, ctime(&tim));
		fputs(buf, fp);
E 19
I 19
D 28
		fprintf(fp, "Date: %s\n", p);
		anyheader = TRUE;
E 19
	}
D 19
	else
		fprintf(fp, "From %s %s", From.q_paddr, &p[1]);
E 19

D 19
	/* output the body */
	while (!ferror(fp) && fgets(buf, sizeof buf, stdin) != NULL)
E 15
		fputs(buf, fp);
E 19
I 19
	/* output from line if needed by mailer */
	p = hvalue("from");
D 20
	if (flagset(M_NEEDFROM, m->m_flags) && p == NULL)
E 20
I 20
	if (bitset(M_NEEDFROM, m->m_flags) && p == NULL)
E 20
	{
D 22
		char frombuf[MAXLINE];
E 22
		extern char *FullName;

D 22
		p = translate("$f", From.q_mailer, From.q_paddr, NULL, NULL);
E 22
I 22
D 23
		p = translate("$f", From.q_mailer, From.q_paddr, (char *) NULL, (char *) NULL);
E 23
I 23
D 24
		p = translate("$f", Mailer[From.q_mailer], From.q_paddr, (char *) NULL, (char *) NULL);
E 24
I 24
D 25
		p = translate("$g", Mailer[From.q_mailer], From.q_paddr, (char *) NULL, (char *) NULL);
E 25
I 25
		expand("$g", buf, &buf[sizeof buf - 1]);
E 25
E 24
E 23
E 22
		if (FullName != NULL)
D 25
			fprintf(fp, "From: %s <%s>\n", FullName, p);
E 25
I 25
			fprintf(fp, "From: %s <%s>\n", FullName, buf);
E 25
		else
D 25
			fprintf(fp, "From: %s\n", p);
		free(p);
E 25
I 25
			fprintf(fp, "From: %s\n", buf);
E 25
		anyheader = TRUE;
	}
	else if (p != NULL)
	{
		fprintf(fp, "From: %s\n", p);
		anyheader = TRUE;
	}

	/* output message-id field if needed */
	p = hvalue("message-id");
D 20
	if (flagset(M_MSGID, m->m_flags) && p == NULL)
E 20
I 20
	if (bitset(M_MSGID, m->m_flags) && p == NULL)
E 20
		p = MsgId;
	if (p != NULL)
	{
		fprintf(fp, "Message-Id: %s\n", p);
		anyheader = TRUE;
	}

	/* output any other header lines */
	for (h = Header; h != NULL; h = h->h_link)
	{
D 20
		if (flagset(H_USED, h->h_flags))
E 20
I 20
		if (bitset(H_USED, h->h_flags))
E 28
I 28
D 29
		if (bitset(H_CHECK, h->h_flags) && bitset(H_DEFAULT, h->h_flags) &&
		    !bitset(h->h_mflags, m->m_flags))
E 29
I 29
D 50
		if (bitset(H_DELETE, h->h_flags))
E 29
E 28
E 20
			continue;
E 50
I 29
		if (bitset(H_CHECK|H_ACHECK, h->h_flags) && !bitset(h->h_mflags, m->m_flags))
D 47
			continue;
E 47
I 47
D 86
		{
			p = ")><(";		/* can't happen (I hope) */
E 86
D 63
			goto checkfrom;
E 63
I 63
D 128
			nooutput = TRUE;
E 128
I 128
			continue;
E 128
E 63
D 86
		}
E 86
I 63

D 128
		/* use From: line from message if generated is the same */
E 128
I 119
		p = h->h_value;
E 119
E 63
E 47
E 29
D 28
		fprintf(fp, "%s: %s\n", capitalize(h->h_field), h->h_value);
E 28
I 28
D 56
		if (bitset(H_DEFAULT, h->h_flags))
E 56
I 56
D 128
		if (strcmp(h->h_field, "from") == 0 && origfrom != NULL &&
D 63
		    strcmp(m->m_from, "$f") == 0)
E 63
I 63
		    strcmp(m->m_from, "$f") == 0 && of_line == NULL)
E 128
I 128
		if (bitset(H_DEFAULT, h->h_flags))
E 128
E 63
E 56
		{
I 56
D 128
			p = origfrom;
			origfrom = NULL;
		}
		else if (bitset(H_DEFAULT, h->h_flags))
		{
E 128
I 116
			/* macro expand value if generated internally */
E 116
E 56
D 36
			expand(h->h_value, buf, &buf[sizeof buf]);
E 36
I 36
D 100
			(void) expand(h->h_value, buf, &buf[sizeof buf]);
E 100
I 100
D 128
			expand(h->h_value, buf, &buf[sizeof buf], e);
E 128
I 128
			expand(p, buf, &buf[sizeof buf], e);
E 128
E 100
E 36
			p = buf;
		}
I 86
D 128
		else if (bitset(H_ADDR, h->h_flags))
		{
D 119
			register int opos;
			bool firstone = TRUE;

			/*
			**  Output the address list translated by the
			**  mailer and with commas.
			*/

			p = h->h_value;
E 119
			if (p == NULL || *p == '\0' || nooutput)
				continue;
D 107
			fprintf(fp, "%s: ", capitalize(h->h_field));
E 107
I 107
D 119
			obp = obuf;
D 112
			sprintf(obp, "%s: ", capitalize(h->h_field));
E 112
I 112
			(void) sprintf(obp, "%s: ", capitalize(h->h_field));
E 112
E 107
			opos = strlen(h->h_field) + 2;
I 107
			obp += opos;
I 116

			/*
			**  Run through the list of values.
			*/

E 116
E 107
			while (*p != '\0')
			{
D 116
				register char *name = p;
E 116
I 116
				register char *name;
E 116
				extern char *remotename();
				char savechar;

D 116
				/* find the end of the name */
E 116
I 116
				/*
				**  Find the end of the name.  New style names
				**  end with a comma, old style names end with
				**  a space character.  However, spaces do not
				**  necessarily delimit an old-style name -- at
				**  signs mean keep going.
				*/

				/* clean up the leading trash in source */
				while (*p != '\0' && (isspace(*p) || *p == ','))
					p++;
				name = p;

				/* find end of name */
E 116
D 88
				while (*p != '\0' && *p != ',' &&
				       (OldStyle ? (!isspace(*p)) : TRUE))
					p++;
E 88
I 88
				while (*p != '\0' && *p != ',')
				{
					extern bool isatword();
					char *oldp;

D 99
					if (!OldStyle || !isspace(*p))
E 99
I 99
D 100
					if (!CurEnv->e_oldstyle || !isspace(*p))
E 100
I 100
					if (!e->e_oldstyle || !isspace(*p))
E 100
E 99
					{
						p++;
						continue;
					}
I 116

					/* look to see if we have an at sign */
E 116
					oldp = p;
					while (*p != '\0' && isspace(*p))
						p++;
I 116

E 116
					if (*p != '@' && !isatword(p))
					{
						p = oldp;
						break;
					}
					p += *p == '@' ? 1 : 2;
					while (*p != '\0' && isspace(*p))
						p++;
				}
I 116
				/* at the end of one complete name */

				/* strip off trailing white space */
				while (p >= name && (isspace(*p) || *p == ','))
					p--;
				if (++p == name)
					continue;
E 116
E 88
				savechar = *p;
				*p = '\0';

				/* translate the name to be relative */
D 87
				name = remotename(name);
E 87
I 87
D 97
				name = remotename(name, m);
E 97
I 97
				name = remotename(name, m, FALSE);
E 97
E 87
				if (*name == '\0')
I 116
				{
					*p = savechar;
E 116
					continue;
I 116
				}
E 116

				/* output the name with nice formatting */
				opos += strlen(name);
				if (!firstone)
					opos += 2;
				if (opos > 78 && !firstone)
				{
D 107
					fprintf(fp, ",\n        ");
E 107
I 107
					(void) sprintf(obp, ",\n");
					putline(obuf, fp, fullsmtp);
					obp = obuf;
					(void) sprintf(obp, "        ");
					obp += strlen(obp);
E 107
D 87
					opos = 8;
E 87
I 87
					opos = 8 + strlen(name);
E 87
				}
				else if (!firstone)
D 107
					fprintf(fp, ", ");
				fprintf(fp, "%s", name);
E 107
I 107
				{
					(void) sprintf(obp, ", ");
					obp += 2;
				}
				(void) sprintf(obp, "%s", name);
				obp += strlen(obp);
E 107
				firstone = FALSE;
D 116

				/* clean up the source string */
E 116
				*p = savechar;
D 116
				while (*p != '\0' && (isspace(*p) || *p == ','))
					p++;
E 116
			}
D 107
			fprintf(fp, "\n");
E 107
I 107
D 112
			strcpy(obp, "\n");
E 112
I 112
			(void) strcpy(obp, "\n");
E 112
D 108
			putline(obp, fp, fullsmtp);
E 108
I 108
			putline(obuf, fp, fullsmtp);
E 119
I 119
			commaize(p, capitalize(h->h_field), fp, e->e_oldstyle, m);
E 119
E 108
E 107
			nooutput = TRUE;
		}
E 128
E 86
D 119
		else
			p = h->h_value;
E 119
I 29
D 63
		if (*p == '\0')
E 63
I 63
		if (p == NULL || *p == '\0')
E 63
			continue;
E 29
D 63
		fprintf(fp, "%s: %s\n", capitalize(h->h_field), p);
E 28
		h->h_flags |= H_USED;
		anyheader = TRUE;
E 63
I 47

D 128
		/* hack, hack -- output Original-From field if different */
D 63
	checkfrom:
D 56
		if (strcmp(h->h_field, "from") == 0)
E 56
I 56
		if (strcmp(h->h_field, "from") == 0 && origfrom != NULL &&
		    !samefrom(p, origfrom) && hvalue("original-from") == NULL)
E 63
I 63
		if (strcmp(h->h_field, "from") == 0 && origfrom != NULL)
E 128
I 128
		if (bitset(H_FROM|H_RCPT, h->h_flags))
E 128
E 63
E 56
		{
D 56
			extern char *hvalue();
			char *ofrom = hvalue("original-from");

			if (ofrom != NULL && strcmp(p, ofrom) != 0)
				fprintf(fp, "Original-From: %s\n", ofrom);
E 56
I 56
D 63
			fprintf(fp, "Original-From: %s\n", origfrom);
E 63
I 63
D 128
			/* output new Original-From line if needed */
			if (of_line == NULL && !samefrom(p, origfrom))
D 100
			{
E 100
D 107
				fprintf(fp, "Original-From: %s\n", origfrom);
E 107
I 107
			{
				(void) sprintf(obuf, "Original-From: %s\n", origfrom);
				putline(obuf, fp, fullsmtp);
			}
E 107
D 100
				anyheader = TRUE;
			}
E 100
			if (of_line != NULL && !nooutput && samefrom(p, of_line))
			{
				/* delete Original-From: line if redundant */
				p = of_line;
				of_line = NULL;
			}
E 128
I 128
			/* address field */
D 131
			commaize(h, p, fp, e->e_oldstyle, m);
E 131
I 131
D 152
			bool oldstyle = e->e_oldstyle;
E 152
I 152
			bool oldstyle = bitset(EF_OLDSTYLE, e->e_flags);
E 152

			if (bitset(H_FROM, h->h_flags))
				oldstyle = FALSE;
			commaize(h, p, fp, oldstyle, m);
E 131
E 128
		}
D 128
		else if (strcmp(h->h_field, "original-from") == 0 && of_line == NULL)
			nooutput = TRUE;

		/* finally, output the header line */
		if (!nooutput)
E 128
I 128
		else
E 128
		{
I 128
			/* vanilla header line */
E 128
D 107
			fprintf(fp, "%s: %s\n", capitalize(h->h_field), p);
E 107
I 107
			(void) sprintf(obuf, "%s: %s\n", capitalize(h->h_field), p);
			putline(obuf, fp, fullsmtp);
E 107
D 128
			h->h_flags |= H_USED;
E 128
E 63
D 100
			anyheader = TRUE;
E 100
E 56
		}
I 128
		h->h_flags |= H_USED;
E 128
E 47
	}
I 119
}
/*
**  COMMAIZE -- output a header field, making a comma-translated list.
**
**	Parameters:
D 128
**		p -- the field to output.
**		tag -- the tag to associate with it.
E 128
I 128
**		h -- the header field to output.
**		p -- the value to put in it.
E 128
**		fp -- file to put it to.
**		oldstyle -- TRUE if this is an old style header.
D 136
**		m -- a pointer to the mailer descriptor.
E 136
I 136
**		m -- a pointer to the mailer descriptor.  If NULL,
**			don't transform the name at all.
E 136
**
**	Returns:
**		none.
**
**	Side Effects:
**		outputs "p" to file "fp".
*/

D 128
commaize(p, tag, fp, oldstyle, m)
E 128
I 128
commaize(h, p, fp, oldstyle, m)
	register HDR *h;
E 128
	register char *p;
D 128
	char *tag;
E 128
	FILE *fp;
	bool oldstyle;
D 128
	MAILER *m;
E 128
I 128
	register MAILER *m;
E 128
{
D 128
	register int opos;
	bool firstone = TRUE;
	char obuf[MAXLINE];
E 128
	register char *obp;
I 128
	int opos;
E 128
D 136
	bool fullsmtp = bitset(M_FULLSMTP, m->m_flags);
E 136
I 136
	bool fullsmtp = FALSE;
E 136
I 128
	bool firstone = TRUE;
	char obuf[MAXLINE];
E 128

	/*
	**  Output the address list translated by the
	**  mailer and with commas.
	*/

# ifdef DEBUG
	if (tTd(14, 2))
D 128
		printf("commaize(%s: %s)\n", tag, p);
E 128
I 128
		printf("commaize(%s: %s)\n", h->h_field, p);
E 128
# endif DEBUG

I 136
	if (m != NULL && bitset(M_FULLSMTP, m->m_flags))
		fullsmtp = TRUE;

E 136
	obp = obuf;
D 128
	(void) sprintf(obp, "%s: ", tag);
	opos = strlen(tag) + 2;
E 128
I 128
	(void) sprintf(obp, "%s: ", capitalize(h->h_field));
	opos = strlen(h->h_field) + 2;
E 128
	obp += opos;

	/*
	**  Run through the list of values.
	*/

	while (*p != '\0')
	{
		register char *name;
D 128
		extern char *remotename();
E 128
		char savechar;
I 126
D 129
		int commentlevel;
		bool inquote;
E 129
I 128
		extern char *remotename();
I 129
		extern char *DelimChar;		/* defined in prescan */
E 129
E 128
E 126

		/*
		**  Find the end of the name.  New style names
		**  end with a comma, old style names end with
		**  a space character.  However, spaces do not
		**  necessarily delimit an old-style name -- at
		**  signs mean keep going.
		*/

D 129
		/* clean up the leading trash in source */
		while (*p != '\0' && (isspace(*p) || *p == ','))
E 129
I 129
		/* find end of name */
		while (isspace(*p) || *p == ',')
E 129
			p++;
		name = p;
D 129

		/* find end of name */
D 126
		while (*p != '\0' && *p != ',')
E 126
I 126
		commentlevel = 0;
		inquote = FALSE;
		while (*p != '\0' && (*p != ',' || commentlevel > 0 || inquote))
E 129
I 129
		for (;;)
E 129
E 126
		{
D 129
			extern bool isatword();
E 129
			char *oldp;
I 129
			extern bool isatword();
E 129

I 126
D 129
			if (*p == '(')
				commentlevel++;
			else if (*p == ')' && commentlevel > 0)
				commentlevel--;
			else if (*p == '"')
				inquote = !inquote;
E 126
			if (!oldstyle || !isspace(*p))
			{
				p++;
				continue;
			}
E 129
I 129
D 130
			(void) prescan(name, oldstyle ? ' ' : ',');
E 130
I 130
			(void) prescan(p, oldstyle ? ' ' : ',');
E 130
			p = DelimChar;
E 129

			/* look to see if we have an at sign */
			oldp = p;
			while (*p != '\0' && isspace(*p))
				p++;

			if (*p != '@' && !isatword(p))
			{
				p = oldp;
				break;
			}
			p += *p == '@' ? 1 : 2;
			while (*p != '\0' && isspace(*p))
				p++;
		}
		/* at the end of one complete name */

		/* strip off trailing white space */
		while (p >= name && (isspace(*p) || *p == ',' || *p == '\0'))
			p--;
		if (++p == name)
			continue;
		savechar = *p;
		*p = '\0';

		/* translate the name to be relative */
D 128
		name = remotename(name, m, FALSE);
E 128
I 128
D 136
		name = remotename(name, m, bitset(H_FROM, h->h_flags));
E 136
I 136
		if (m != NULL)
			name = remotename(name, m, bitset(H_FROM, h->h_flags));
E 136
E 128
		if (*name == '\0')
		{
			*p = savechar;
			continue;
		}

		/* output the name with nice formatting */
D 146
		opos += strlen(name);
E 146
I 146
		opos += qstrlen(name);
E 146
		if (!firstone)
			opos += 2;
		if (opos > 78 && !firstone)
		{
			(void) sprintf(obp, ",\n");
			putline(obuf, fp, fullsmtp);
			obp = obuf;
			(void) sprintf(obp, "        ");
			obp += strlen(obp);
			opos = 8 + strlen(name);
		}
		else if (!firstone)
		{
			(void) sprintf(obp, ", ");
			obp += 2;
		}
D 146
		(void) sprintf(obp, "%s", name);
		obp += strlen(obp);
E 146
I 146

		/* strip off quote bits as we output */
		while (*name != '\0')
		{
			if (bitset(0200, *name))
				*obp++ = '\\';
			*obp++ = *name++ & ~0200;
		}
E 146
		firstone = FALSE;
		*p = savechar;
	}
	(void) strcpy(obp, "\n");
	putline(obuf, fp, fullsmtp);
E 119
D 54

E 54
D 100
	if (anyheader)
		fprintf(fp, "\n");
E 100
D 89

D 54
	/* output the body of the message */
E 54
I 54
	/*
	**  Output the body of the message
	*/

E 54
D 32
	while (!ferror(fp) && (i = read(0, buf, BUFSIZ)) > 0)
E 32
I 32
D 44
	rewind(stdin);
	while (!ferror(fp) && (i = fread(buf, 1, BUFSIZ, stdin)) > 0)
E 44
I 44
D 64
	rewind(TempFile);
	while (!ferror(fp) && (i = fread(buf, 1, BUFSIZ, TempFile)) > 0)
E 44
E 32
D 36
		fwrite(buf, 1, i, fp);
E 36
I 36
		(void) fwrite(buf, 1, i, fp);
E 64
I 64
	if (TempFile != NULL)
	{
		rewind(TempFile);
D 72
		while (!ferror(fp) && (i = fread(buf, 1, BUFSIZ, TempFile)) > 0)
			(void) fwrite(buf, 1, i, fp);
E 72
I 72
		while (!ferror(fp) && fgets(buf, sizeof buf, TempFile) != NULL)
			fprintf(fp, "%s%s", xdot && buf[0] == '.' ? "." : "", buf);
E 72
E 64
E 36

I 64
		if (ferror(TempFile))
		{
			syserr("putmessage: read error");
			setstat(EX_IOERR);
		}
	}

D 69
	fflush(fp);
E 69
I 69
	(void) fflush(fp);
E 69
E 64
E 19
D 39
	if (ferror(fp))
E 39
I 39
	if (ferror(fp) && errno != EPIPE)
E 39
	{
D 19
		syserr("putheader: write error");
E 19
I 19
		syserr("putmessage: write error");
E 19
		setstat(EX_IOERR);
	}
D 39
}
/*
**  PIPESIG -- Handle broken pipe signals
**
**	This just logs an error.
**
**	Parameters:
**		none
**
**	Returns:
**		none
**
**	Side Effects:
**		logs an error message.
D 4
**
**	Requires:
**		syserr
**
**	History:
**		1/17/80 -- written.
E 4
*/

pipesig()
{
	syserr("Broken pipe");
I 10
D 36
	signal(SIGPIPE, SIG_IGN);
E 36
I 36
	(void) signal(SIGPIPE, SIG_IGN);
E 39
I 39
	errno = 0;
E 89
I 88
}
/*
E 154
I 100
**  PUTBODY -- put the body of a message.
**
**	Parameters:
**		fp -- file to output onto.
D 166
**		m -- a mailer descriptor.
**		xdot -- if set, use SMTP hidden dot algorithm.
E 166
I 166
**		m -- a mailer descriptor to control output format.
E 166
I 157
**		e -- the envelope to put out.
E 157
**
**	Returns:
**		none.
**
**	Side Effects:
**		The message is written onto fp.
*/

D 157
putbody(fp, m, xdot)
E 157
I 157
D 159
putbody(fp, m, xdot, e)
E 159
I 159
D 166
putbody(fp, m, xdot, e, crlf)
E 166
I 166
putbody(fp, m, e)
E 166
E 159
E 157
	FILE *fp;
D 154
	struct mailer *m;
E 154
I 154
	MAILER *m;
E 154
D 166
	bool xdot;
E 166
I 157
	register ENVELOPE *e;
E 157
{
D 166
	char buf[MAXLINE + 1];
I 107
	bool fullsmtp = bitset(M_FULLSMTP, m->m_flags);
E 166
I 166
	char buf[MAXLINE];
E 166
E 107

	/*
	**  Output the body of the message
	*/

I 102
D 154
#ifdef lint
	/* m will be needed later for complete smtp emulation */
	if (m == NULL)
		return;
#endif lint

E 154
E 102
D 157
	if (TempFile != NULL)
E 157
I 157
	if (e->e_dfp == NULL)
E 157
	{
D 157
		rewind(TempFile);
E 157
I 157
		if (e->e_df != NULL)
		{
			e->e_dfp = fopen(e->e_df, "r");
			if (e->e_dfp == NULL)
				syserr("Cannot open %s", e->e_df);
		}
		else
D 159
			putline("<<< No Message Collected >>>", fp, fullsmtp);
E 159
I 159
D 166
			putline("<<< No Message Collected >>>", fp, crlf, fullsmtp);
E 166
I 166
			putline("<<< No Message Collected >>>", fp, m);
E 166
E 159
	}
	if (e->e_dfp != NULL)
	{
		rewind(e->e_dfp);
E 157
D 166
		buf[0] = '.';
D 157
		while (!ferror(fp) && fgets(&buf[1], sizeof buf - 1, TempFile) != NULL)
E 157
I 157
		while (!ferror(fp) &&
		       fgets(&buf[1], sizeof buf - 1, e->e_dfp) != NULL)
		{
E 157
D 107
			fputs((xdot && buf[1] == '.') ? buf : &buf[1], fp);
E 107
I 107
D 159
			putline((xdot && buf[1] == '.') ? buf : &buf[1], fp, fullsmtp);
E 159
I 159
			putline((xdot && buf[1] == '.') ? buf : &buf[1], fp, crlf, fullsmtp);
E 159
I 157
		}
E 166
I 166
		while (!ferror(fp) && fgets(buf, sizeof buf, e->e_dfp) != NULL)
I 182
		{
			if (buf[0] == 'F' && bitnset(M_ESCFROM, m->m_flags) &&
			    strncmp(buf, "From", 4) == 0)
D 188
				putc('>', fp);
E 188
I 188
				(void) putc('>', fp);
E 188
E 182
			putline(buf, fp, m);
I 182
		}
E 182
E 166
E 157
E 107

D 157
		if (ferror(TempFile))
E 157
I 157
		if (ferror(e->e_dfp))
E 157
		{
			syserr("putbody: read error");
			ExitStat = EX_IOERR;
		}
	}

	(void) fflush(fp);
	if (ferror(fp) && errno != EPIPE)
	{
		syserr("putbody: write error");
		ExitStat = EX_IOERR;
	}
	errno = 0;
}
/*
E 100
D 154
**  ISATWORD -- tell if the word we are pointing to is "at".
**
**	Parameters:
**		p -- word to check.
**
**	Returns:
**		TRUE -- if p is the word at.
**		FALSE -- otherwise.
**
**	Side Effects:
**		none.
*/

bool
isatword(p)
	register char *p;
{
	extern char lower();

	if (lower(p[0]) == 'a' && lower(p[1]) == 't' &&
	    p[2] != '\0' && isspace(p[2]))
		return (TRUE);
	return (FALSE);
E 88
I 86
D 118
}
/*
**  REMOTENAME -- return the name relative to the current mailer
**
**	Parameters:
**		name -- the name to translate.
I 97
**		force -- if set, forces rewriting even if the mailer
**			does not request it.  Used for rewriting
**			sender addresses.
E 97
**
**	Returns:
**		the text string representing this address relative to
**			the receiving mailer.
**
**	Side Effects:
**		none.
**
**	Warnings:
**		The text string returned is tucked away locally;
**			copy it if you intend to save it.
*/

char *
D 87
remotename(name)
E 87
I 87
D 97
remotename(name, m)
E 97
I 97
remotename(name, m, force)
E 97
E 87
	char *name;
I 87
	struct mailer *m;
I 97
	bool force;
E 97
E 87
{
I 95
D 97
# ifdef NOTDEF
E 97
E 95
	static char buf[MAXNAME];
	char lbuf[MAXNAME];
	extern char *macvalue();
	char *oldf = macvalue('f');
I 87
	char *oldx = macvalue('x');
	char *oldg = macvalue('g');
E 87
	extern char **prescan();
	register char **pvp;
I 87
	extern char *getxpart();
I 102
	extern ADDRESS *buildaddr();
E 102
E 87

	/*
I 97
	**  See if this mailer wants the name to be rewritten.  There are
	**  many problems here, owing to the standards for doing replies.
	**  In general, these names should only be rewritten if we are
	**  sending to another host that runs sendmail.
	*/

	if (!bitset(M_RELRCPT, m->m_flags) && !force)
D 102
		return;
E 102
I 102
		return (name);
E 102

	/*
E 97
	**  Do general rewriting of name.
	**	This will also take care of doing global name translation.
	*/

I 87
	define('x', getxpart(name));
E 87
	pvp = prescan(name, '\0');
I 111
	if (pvp == NULL)
		return (name);
E 111
D 105
	for (;;)
E 105
I 105
	rewrite(pvp, 1);
	rewrite(pvp, 3);
	if (**pvp == CANONNET)
E 105
	{
D 105
		rewrite(pvp, 1);
		rewrite(pvp, 3);
		if (**pvp == CANONNET)
		{
			auto ADDRESS a;
			register char *p;
			extern char *hostalias();

			/* oops... resolved to something */
			if (buildaddr(pvp, &a) == NULL)
				return (name);
			p = hostalias(&a);
			if (p == NULL)
				return (name);
			pvp = prescan(p, '\0');
		}
		else
		{
			cataddr(pvp, lbuf, sizeof lbuf);
			break;
		}
E 105
I 105
		/* oops... resolved to something */
		return (name);
E 105
	}
I 105
	cataddr(pvp, lbuf, sizeof lbuf);
E 105

	/* make the name relative to the receiving mailer */
	define('f', lbuf);
D 87
	(void) expand(From.q_mailer->m_from, buf, &buf[sizeof buf - 1]);
E 87
I 87
D 100
	(void) expand(m->m_from, buf, &buf[sizeof buf - 1]);
E 100
I 100
	expand(m->m_from, buf, &buf[sizeof buf - 1], CurEnv);
E 100
E 87

	/* rewrite to get rid of garbage we added in the expand above */
	pvp = prescan(buf, '\0');
I 111
	if (pvp == NULL)
		return (name);
E 111
	rewrite(pvp, 2);
D 87
	cataddr(pvp, buf, sizeof buf);
E 87
I 87
	cataddr(pvp, lbuf, sizeof lbuf);
E 87

I 87
	/* now add any comment info we had before back */
	define('g', lbuf);
D 100
	(void) expand("$q", buf, &buf[sizeof buf - 1]);
E 100
I 100
	expand("$q", buf, &buf[sizeof buf - 1], CurEnv);
E 100

E 87
	define('f', oldf);
I 87
	define('g', oldg);
	define('x', oldx);
E 87

# ifdef DEBUG
D 117
	if (Debug > 0)
E 117
I 117
	if (tTd(12, 1))
E 117
		printf("remotename(%s) => `%s'\n", name, buf);
# endif DEBUG
	return (buf);
E 118
I 95
D 97
# else NOTDEF
	/* oh bother, this breaks UUCP......   */
	return (name);
# endif NOTDEF
E 97
E 95
E 86
I 56
}
/*
E 154
D 153
**  SAMEFROM -- tell if two text addresses represent the same from address.
**
**	Parameters:
**		ifrom -- internally generated form of from address.
**		efrom -- external form of from address.
**
**	Returns:
**		TRUE -- if they convey the same info.
**		FALSE -- if any information has been lost.
**
**	Side Effects:
**		none.
*/

bool
samefrom(ifrom, efrom)
	char *ifrom;
	char *efrom;
{
D 63
	return (strcmp(ifrom, efrom) == 0);
E 63
I 63
	register char *p;
	char buf[MAXNAME + 4];

# ifdef DEBUG
D 117
	if (Debug > 7)
E 117
I 117
	if (tTd(3, 8))
E 117
		printf("samefrom(%s,%s)-->", ifrom, efrom);
# endif DEBUG
	if (strcmp(ifrom, efrom) == 0)
		goto success;
	p = index(ifrom, '@');
	if (p == NULL)
		goto failure;
	*p = '\0';
D 102
	strcpy(buf, ifrom);
	strcat(buf, " at ");
E 102
I 102
	(void) strcpy(buf, ifrom);
	(void) strcat(buf, " at ");
E 102
	*p++ = '@';
D 102
	strcat(buf, p);
E 102
I 102
	(void) strcat(buf, p);
E 102
	if (strcmp(buf, efrom) == 0)
		goto success;

  failure:
# ifdef DEBUG
D 117
	if (Debug > 7)
E 117
I 117
	if (tTd(3, 8))
E 117
		printf("FALSE\n");
# endif DEBUG
	return (FALSE);

  success:
# ifdef DEBUG
D 117
	if (Debug > 7)
E 117
I 117
	if (tTd(3, 8))
E 117
		printf("TRUE\n");
# endif DEBUG
	return (TRUE);
E 63
E 56
E 39
E 36
E 10
}
/*
E 153
D 43
**  SENDTO -- Designate a send list.
**
**	The parameter is a comma-separated list of people to send to.
**	This routine arranges to send to all of them.
**
**	Parameters:
**		list -- the send list.
**		copyf -- the copy flag; passed to parse.
**
**	Returns:
**		none
**
**	Side Effects:
**		none.
D 26
**
D 4
**	Requires:
**		parse
**		recipient
**
E 4
**	Called By:
**		main
**		alias
E 26
D 4
**
**	History:
**		1/11/80 -- written.
E 4
*/

I 37
# define MAXRCRSN	10

E 37
sendto(list, copyf)
	char *list;
	int copyf;
{
	register char *p;
	register char *q;
	register char c;
D 20
	addrq *a;
	extern addrq *parse();
E 20
I 20
	ADDRESS *a;
D 36
	extern ADDRESS *parse();
E 36
E 20
	bool more;

	/* more keeps track of what the previous delimiter was */
	more = TRUE;
	for (p = list; more; )
	{
		/* find the end of this address */
I 40
		while (*p == ' ' || *p == '\t')
			p++;
E 40
		q = p;
		while ((c = *p++) != '\0' && c != ',' && c != '\n')
			continue;
		more = c != '\0';
		*--p = '\0';
		if (more)
			p++;

		/* parse the address */
D 20
		if ((a = parse(q, (addrq *) NULL, copyf)) == NULL)
E 20
I 20
		if ((a = parse(q, (ADDRESS *) NULL, copyf)) == NULL)
E 20
			continue;

		/* arrange to send to this person */
D 25
		recipient(a, &SendQ);
E 25
I 25
		recipient(a);
E 25
	}
	To = NULL;
}
/*
**  RECIPIENT -- Designate a message recipient
**
**	Saves the named person for future mailing.
**
D 25
**	Designates a person as a recipient.  This routine
**	does the initial parsing, and checks to see if
**	this person has already received the mail.
**	It also supresses local network names and turns them into
**	local names.
**
E 25
**	Parameters:
**		a -- the (preparsed) address header for the recipient.
D 25
**		targetq -- the queue to add the name to.
E 25
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
D 26
**
D 4
**	Requires:
**		sameaddr
**		parse
**		forward
**		printf (sys)
**		strcmp (sys)
**		nxtinq
**		putonq
**
E 4
**	Called By:
**		sendto
**		main
E 26
D 4
**
**	History:
**		3/5/80 -- modified to know about new internal form
**			for addresses.
**		12/31/79 -- written.
E 4
*/

D 25
recipient(a, targetq)
E 25
I 25
recipient(a)
E 25
D 20
	register addrq *a;
	addrq *targetq;
E 20
I 20
	register ADDRESS *a;
D 25
	ADDRESS *targetq;
E 25
E 20
{
D 20
	register addrq *q;
E 20
I 20
	register ADDRESS *q;
E 20
	register struct mailer *m;
D 22
	register char **pvp;
E 22
D 20
	extern char *xalloc();
E 20
D 37
	extern bool forward();
E 37
I 37
	char buf[MAXNAME];
E 37
D 36
	extern int errno;
	extern bool sameaddr();
E 36

	To = a->q_paddr;
D 23
	m = a->q_mailer;
E 23
I 23
	m = Mailer[a->q_mailer];
E 23
	errno = 0;
# ifdef DEBUG
	if (Debug)
		printf("recipient(%s)\n", To);
# endif DEBUG
D 7

	/*
	**  Don't go to the net if already on the target host.
	**	This is important on the berkeley network, since
	**	it get confused if we ask to send to ourselves.
	**	For nets like the ARPANET, we probably will have
	**	the local list set to NULL to simplify testing.
	**	The canonical representation of the name is also set
	**	to be just the local name so the duplicate letter
	**	suppression algorithm will work.
	*/

	if ((pvp = m->m_local) != NULL)
	{
		while (*pvp != NULL)
		{
			if (strcmp(*pvp++, a->q_host) == 0)
			{
				a->q_mailer = m = &Mailer[0];
				break;
			}
		}
	}
E 7

I 37
	/* break aliasing loops */
	if (AliasLevel > MAXRCRSN)
	{
		usrerr("aliasing/forwarding loop broken");
		return;
	}

E 37
	/*
I 25
	**  Do sickly crude mapping for program mailing, etc.
	*/

D 35
	if (a->q_mailer == 0 && a->q_user[0] == '|')
E 35
I 35
	if (a->q_mailer == M_LOCAL)
E 35
	{
D 35
		a->q_mailer = 1;
D 30
		m++;
E 30
I 30
		m = Mailer[1];
E 30
		a->q_user++;
E 35
I 35
		if (a->q_user[0] == '|')
		{
			a->q_mailer = M_PROG;
			m = Mailer[M_PROG];
			a->q_user++;
		}
D 37
		else
		{
			register struct passwd *pw;

			pw = getpwnam(a->q_user);
			if (pw == NULL)
				a->q_flags |= QBADADDR;
			else
			{
				char xbuf[60];

				a->q_home = newstr(pw->pw_dir);
				define('z', a->q_home);
D 36
				expand("$z/.mailer", xbuf, &xbuf[sizeof xbuf - 1]);
E 36
I 36
				(void) expand("$z/.mailer", xbuf, &xbuf[sizeof xbuf - 1]);
E 36
				if (access(xbuf, 1) == 0)
				{
					a->q_mailer = M_PRIVATE;
					m = Mailer[M_PROG];
				}
			}
		}
E 37
E 35
	}

	/*
E 25
	**  Look up this person in the recipient list.  If they
	**  are there already, return, otherwise continue.
I 25
	**  If the list is empty, just add it.
E 25
	*/

D 25
	if (!ForceMail)
E 25
I 25
	if (m->m_sendq == NULL)
E 25
	{
D 25
		for (q = &SendQ; (q = nxtinq(q)) != NULL; )
			if (sameaddr(q, a, FALSE))
E 25
I 25
		m->m_sendq = a;
	}
	else
	{
		ADDRESS *pq;

		for (q = m->m_sendq; q != NULL; pq = q, q = q->q_next)
		{
			if (!ForceMail && sameaddr(q, a, FALSE))
E 25
			{
# ifdef DEBUG
				if (Debug)
D 25
					printf("(%s in SendQ)\n", a->q_paddr);
E 25
I 25
					printf("(%s in sendq)\n", a->q_paddr);
E 25
# endif DEBUG
I 33
D 34
				if (Verbose)
E 34
I 34
				if (Verbose && !bitset(QDONTSEND, a->q_flags))
E 34
D 42
					message("050", "duplicate supressed");
E 42
I 42
					message(Arpa_Info, "duplicate supressed");
E 42
E 33
				return;
			}
D 25
		for (q = &AliasQ; (q = nxtinq(q)) != NULL; )
			if (sameaddr(q, a, FALSE))
			{
# ifdef DEBUG
				if (Debug)
					printf("(%s in AliasQ)\n", a->q_paddr);
# endif DEBUG
				return;
			}
E 25
I 25
		}

		/* add address on list */
		q = pq;
D 26
		q->q_next = NULL;
E 26
I 26
		q->q_next = a;
E 26
E 25
	}
I 25
	a->q_next = NULL;
E 25

	/*
D 37
	**  See if the user wants hir mail forwarded.
	**	`Forward' must do the forwarding recursively.
E 37
I 37
D 40
	**  Alias the name.
E 40
I 40
	**  Alias the name and handle :include: specs.
E 40
E 37
	*/

D 23
	if (m == &Mailer[0] && !NoAlias && targetq == &SendQ && forward(a))
E 23
I 23
D 25
	if (m == Mailer[0] && !NoAlias && targetq == &SendQ && forward(a))
E 23
		return;
E 25
I 25
D 35
	if (m == Mailer[0] && !NoAlias && forward(a))
E 35
I 35
D 37
	if (m == Mailer[M_LOCAL] && !NoAlias && forward(a))
E 35
D 34
		setbit(QDONTSEND, a->q_flags);
E 34
I 34
		a->q_flags |= QDONTSEND;
E 37
I 37
	if (a->q_mailer == M_LOCAL)
D 40
		alias(a);
E 40
I 40
	{
		if (strncmp(a->q_user, ":include:", 9) == 0)
		{
			a->q_flags |= QDONTSEND;
			include(&a->q_user[9]);
		}
		else
			alias(a);
	}
E 40

	/*
	**  If the user is local and still being sent, verify that
	**  the address is good.  If it is, try to forward.
	**  If the address is already good, we have a forwarding
	**  loop.  This can be broken by just sending directly to
	**  the user (which is probably correct anyway).
	*/

D 41
	if (!bitset(QDONTSEND, a->q_flags) && a->q_mailer == M_LOCAL &&
	    a->q_home == NULL)
E 41
I 41
	if (!bitset(QDONTSEND, a->q_flags) && a->q_mailer == M_LOCAL)
E 41
	{
D 41
		register struct passwd *pw;
		extern struct passwd *getpwnam();
E 41
		char buf[MAXNAME];

		strcpy(buf, a->q_user);
		stripquotes(buf, TRUE);
D 41
		pw = getpwnam(buf);
		if (pw == NULL)
			a->q_flags |= QBADADDR;
E 41
I 41

		/* see if this is to a file */
		if (index(buf, '/') != NULL)
		{
			if (access(buf, 2) < 0)
			{
				a->q_flags |= QBADADDR;
				giveresponse(EX_CANTCREAT, TRUE, m);
			}
		}
E 41
		else
I 38
		{
E 38
D 41
			a->q_home = newstr(pw->pw_dir);
D 38
		if (strcmp(buf, a->q_user) == 0)
			forward(a);
E 38
I 38
			if (strcmp(buf, a->q_user) == 0)
				forward(a);
E 41
I 41
			register struct passwd *pw;
			extern struct passwd *getpwnam();
			pw = getpwnam(buf);
			if (pw == NULL)
			{
				a->q_flags |= QBADADDR;
				giveresponse(EX_NOUSER, TRUE, m);
			}
			else
			{
				a->q_home = newstr(pw->pw_dir);
				if (strcmp(buf, a->q_user) == 0)
					forward(a);
			}
E 41
		}
E 38
	}
I 40
}
/*
**  INCLUDE -- handle :include: specification.
**
**	Parameters:
**		fname -- filename to include.
**
**	Returns:
**		none.
**
**	Side Effects:
**		reads the :include: file and sends to everyone
**		listed in that file.
*/
E 40
E 37
E 34
E 25

D 25
	/*
	**  Put the user onto the target queue.
	*/

	if (targetq != NULL)
	{
		putonq(a, targetq);
	}

E 25
D 40
	return;
E 40
I 40
include(fname)
	char *fname;
{
	char buf[MAXLINE];
	register FILE *fp;

	if (Verbose)
D 42
		message("050", "Including file %s", fname);
E 42
I 42
		message(Arpa_Info, "Including file %s", fname);
E 42
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		usrerr("Cannot open %s", fname);
		return;
	}

	/* read the file -- each line is a comma-separated list. */
	while (fgets(buf, sizeof buf, fp) != NULL)
	{
		register char *p = index(buf, '\n');

		if (p != NULL)
			*p = '\0';
		if (buf[0] == '\0')
			continue;
		To = fname;
		if (Verbose)
D 42
			message("050", " >> %s", buf);
E 42
I 42
			message(Arpa_Info, " >> %s", buf);
E 42
		sendto(buf, 1);
	}

	fclose(fp);
E 40
D 26
}
/*
**  BUILDARGV -- Build an argument vector for a mail server.
**
**	Using a template defined in config.c, an argv is built.
**	The format of the template is already a vector.  The
**	items of this vector are copied, unless a dollar sign
**	is encountered.  In this case, the next character
**	specifies something else to copy in.  These can be
I 25
**	any macros.  System defined macros are:
E 25
**		$f	The from address.
**		$h	The host.
**		$u	The user.
**		$c	The hop count.
I 25
**	among others.
E 25
**	The vector is built in a local buffer.  A pointer to
**	the static argv is returned.
**
**	Parameters:
D 19
**		tmplt -- a template for an argument vector.
**		flags -- the flags for this server.
E 19
I 19
**		m -- a pointer to the mailer descriptor.
E 19
**		host -- the host name to send to.
**		user -- the user name to send to.
**		from -- the person this mail is from.
**
**	Returns:
**		A pointer to an argv.
**
**	Side Effects:
**		none
**
**	WARNING:
**		Since the argv is staticly allocated, any subsequent
**		calls will clobber the old argv.
**
D 4
**	Requires:
**		printf (sys)
**		sprintf (sys)
**		flagset
**		syserr
**
E 4
**	Called By:
**		deliver
D 4
**
**	History:
**		12/26/79 -- written.
E 4
*/

char **
D 19
buildargv(tmplt, flags, host, user, from)
	char **tmplt;
	int flags;
E 19
I 19
buildargv(m, host, user, from)
	struct mailer *m;
E 19
	char *host;
	char *user;
	char *from;
{
	register char *p;
D 22
	register char *q;
E 22
	static char *pv[MAXPV+1];
	char **pvp;
	char **mvp;
	static char buf[512];
D 22
	register char *bp;
E 22
D 19
	char pbuf[30];
E 19
I 19
D 25
	extern char *translate();
E 25
I 25
	extern char *expand();
	extern char *newstr();
E 25
E 19

	/*
	**  Do initial argv setup.
	**	Insert the mailer name.  Notice that $x expansion is
	**	NOT done on the mailer name.  Then, if the mailer has
	**	a picky -f flag, we insert it as appropriate.  This
	**	code does not check for 'pv' overflow; this places a
	**	manifest lower limit of 4 for MAXPV.
	*/

	pvp = pv;
D 22
	bp = buf;

E 22
D 19
	*pvp++ = tmplt[0];
E 19
I 19
	*pvp++ = m->m_argv[0];
E 19

	/* insert -f or -r flag as appropriate */
D 19
	if (flagset(M_FOPT|M_ROPT, flags) && FromFlag)
E 19
I 19
D 20
	if (flagset(M_FOPT|M_ROPT, m->m_flags) && FromFlag)
E 20
I 20
	if (bitset(M_FOPT|M_ROPT, m->m_flags) && FromFlag)
E 20
E 19
	{
D 19
		if (flagset(M_FOPT, flags))
E 19
I 19
D 20
		if (flagset(M_FOPT, m->m_flags))
E 20
I 20
		if (bitset(M_FOPT, m->m_flags))
E 20
E 19
			*pvp++ = "-f";
		else
			*pvp++ = "-r";
D 19
		*pvp++ = From.q_paddr;
E 19
I 19
D 25
		*pvp++ = translate(from, m, from, user, host);
E 25
I 25
		expand(from, buf, &buf[sizeof buf - 1]);
		*pvp++ = newstr(buf);
E 25
E 19
	}

	/*
	**  Build the rest of argv.
	**	For each prototype parameter, the prototype is
D 25
	**	scanned character at a time.  If a dollar-sign is
	**	found, 'q' is set to the appropriate expansion,
	**	otherwise it is null.  Then either the string
	**	pointed to by q, or the original character, is
	**	interpolated into the buffer.  Buffer overflow is
E 25
I 25
	**	scanned character at a time.  Buffer overflow is
E 25
	**	checked.
	*/

D 19
	for (mvp = tmplt; (p = *++mvp) != NULL; )
E 19
I 19
	for (mvp = m->m_argv; (p = *++mvp) != NULL; )
E 19
	{
		if (pvp >= &pv[MAXPV])
		{
			syserr("Too many parameters to %s", pv[0]);
			return (NULL);
		}
D 19
		*pvp++ = bp;
		for (; *p != '\0'; p++)
E 19
I 19
D 25
		*pvp++ = translate(p, m, from, user, host);
E 25
I 25
		expand(p, buf, &buf[sizeof buf - 1]);
		*pvp++ = newstr(buf);
E 25
	}
	*pvp = NULL;

# ifdef DEBUG
	if (Debug)
	{
		printf("Interpolated argv is:\n");
		for (mvp = pv; *mvp != NULL; mvp++)
			printf("\t%s\n", *mvp);
	}
# endif DEBUG

	return (pv);
E 26
}
/*
E 43
D 25
**  TRANSLATE -- translate a string using $x escapes.
**
**	Parameters:
**		s -- string to translate.
**		m -- pointer to mailer descriptor.
**
**	Returns:
**		pointer to translated string.
**
**	Side Effects:
**		none.
*/

char *
translate(s, m, from, user, host)
	register char *s;
	struct mailer *m;
	char *from;
	char *user;
	char *host;
{
D 24
	register char *q;
E 24
	char buf[MAXNAME];
D 24
	register char *bp;
	char *stack = NULL;
E 24
	char pbuf[10];
	extern char *newstr();
	extern char *Macro[];
I 22
	extern char *sprintf();
I 24
	extern char *trans2();
E 24
E 22

D 24
	bp = buf;
restart:
E 24
I 24
	/* predefine system macros */
	Macro['f'] = From.q_paddr;
	Macro['g'] = m->m_from;
	Macro['u'] = user;
	Macro['h'] = host;
	sprintf(pbuf, "%d", HopCount);
	Macro['c'] = pbuf;
E 24

I 24
	trans2(s, buf, &buf[sizeof buf - 1]);

E 24
# ifdef DEBUG
	if (Debug)
I 24
		printf("translate ==> '%s'\n", buf);
# endif DEBUG

	return (newstr(buf));
}

/*
**  TRANS2 -- internal routine to translate.
*/

char *
trans2(s, bp, buflim)
	register char *s;
	register char *bp;
	char *buflim;
{
	register char *q;
	extern char *Macro[];

# ifdef DEBUG
	if (Debug)
E 24
		printf("translate(%s)\n", s);
# endif DEBUG
I 24

E 24
	for (; *s != '\0'; s++)
	{
		/* q will be the interpolated quantity */
		q = NULL;
		if (*s == '$')
E 19
D 24
		{
D 19
			/* q will be the interpolated quantity */
			q = NULL;
			if (*p == '$')
E 19
I 19
			if (isupper(*++s))
				q = Macro[*s - 'A'];
			else
E 19
			{
D 19
				switch (*++p)
E 19
I 19
				switch (*s)
E 19
				{
				  case 'f':	/* from person */
I 19
					if (stack == NULL && m != NULL)
					{
						stack = s;
						s = m->m_from;
						goto restart;
					}
E 19
					q = from;
					break;
E 24
I 24
			q = Macro[*++s];
E 24

D 24
				  case 'u':	/* user */
					q = user;
					break;

				  case 'h':	/* host */
					q = host;
					break;

				  case 'c':	/* hop count */
					sprintf(pbuf, "%d", HopCount);
					q = pbuf;
					break;
				}
			}
I 19
		}
E 19

E 24
D 19
			/*
			**  Interpolate q or output one character
			**	Strip quote bits as we proceed.....
			*/
E 19
I 19
		/*
		**  Interpolate q or output one character
		**	Strip quote bits as we proceed.....
		*/
E 19

D 19
			if (q != NULL)
			{
				while (bp < &buf[sizeof buf - 1] && (*bp++ = *q++) != '\0')
					continue;
				bp--;
D 2
				if (q[-2] == '"')
					bp--;
E 2
			}
			else if (bp < &buf[sizeof buf - 1])
				*bp++ = *p;
E 19
I 19
		if (q != NULL)
D 24
		{
			while (bp < &buf[sizeof buf - 1] && (*bp++ = *q++) != '\0')
				continue;
			bp--;
E 19
		}
D 19
		*bp++ = '\0';
		if (bp >= &buf[sizeof buf - 1])
			return (NULL);
E 19
I 19
		else if (bp < &buf[sizeof buf - 1])
E 24
I 24
			bp = trans2(q, bp, buflim);
		else if (bp < buflim - 1)
E 24
			*bp++ = *s;
E 19
	}
D 19
	*pvp = NULL;

# ifdef DEBUG
	if (Debug)
E 19
I 19
D 24
	if (stack != NULL)
E 19
	{
D 19
		printf("Interpolated argv is:\n");
		for (mvp = pv; *mvp != NULL; mvp++)
			printf("\t%s\n", *mvp);
E 19
I 19
		s = stack;
		s++;
		stack = NULL;
		goto restart;
E 19
	}
I 19
	*bp++ = '\0';
	if (bp >= &buf[sizeof buf - 1])
		return (NULL);
# ifdef DEBUG
	if (Debug)
		printf("translate ==> '%s'\n", buf);
E 19
# endif DEBUG
D 19

	return (pv);
E 19
I 19
	return (newstr(buf));
E 24
I 24
	*bp = '\0';
	return (bp);
E 24
E 19
}
/*
E 25
**  MAILFILE -- Send a message to a file.
**
I 55
**	If the file has the setuid/setgid bits set, but NO execute
**	bits, sendmail will try to become the owner of that file
**	rather than the real user.  Obviously, this only works if
**	sendmail runs as root.
**
I 154
**	This could be done as a subordinate mailer, except that it
**	is used implicitly to save messages in ~/dead.letter.  We
**	view this as being sufficiently important as to include it
**	here.  For example, if the system is dying, we shouldn't have
**	to create another process plus some pipes to save the message.
**
E 154
E 55
**	Parameters:
**		filename -- the name of the file to send to.
I 58
**		ctladdr -- the controlling address header -- includes
**			the userid/groupid to be when sending.
E 58
**
**	Returns:
**		The exit code associated with the operation.
**
**	Side Effects:
**		none.
D 48
**
D 4
**	Requires:
**		fgets (sys)
**		fputs (sys)
**		fprintf (sys)
**		fopen (sys)
**		fclose (sys)
**		ferror (sys)
**		time (sys)
**		ctime (sys)
**		rewind (sys)
**
E 4
**	Called By:
**		deliver
E 48
D 4
**
**	History:
**		3/5/80 -- written.
E 4
*/

D 58
mailfile(filename)
E 58
I 58
mailfile(filename, ctladdr)
E 58
	char *filename;
I 58
	ADDRESS *ctladdr;
E 58
{
D 25
	char buf[MAXLINE];
E 25
	register FILE *f;
I 48
	register int pid;
D 54
	register int i;
E 54
E 48
D 25
	auto long tim;
	extern char *ctime();
I 22
	extern long time();
E 25
E 22

D 48
	f = fopen(filename, "a");
	if (f == NULL)
		return (EX_CANTCREAT);
E 48
I 48
	/*
	**  Fork so we can change permissions here.
	**	Note that we MUST use fork, not vfork, because of
	**	the complications of calling subroutines, etc.
	*/
E 48
D 34
	
E 34
I 34

E 34
D 25
	/* output the timestamp */
	time(&tim);
	fprintf(f, "From %s %s", From.q_paddr, ctime(&tim));
	rewind(stdin);
	while (fgets(buf, sizeof buf, stdin) != NULL)
	{
		fputs(buf, f);
		if (ferror(f))
		{
			fclose(f);
			return (EX_IOERR);
		}
	}
E 25
I 25
D 48
	putmessage(f, Mailer[1]);
E 25
	fputs("\n", f);
D 36
	fclose(f);
E 36
I 36
	(void) fclose(f);
E 36
	return (EX_OK);
E 48
I 48
	DOFORK(fork);

	if (pid < 0)
		return (EX_OSERR);
	else if (pid == 0)
	{
		/* child -- actually write to file */
D 55
		(void) setuid(getuid());
		(void) setgid(getgid());
E 55
I 55
		struct stat stb;
I 61
D 83
		extern int DefUid, DefGid;
E 83
E 61

E 55
I 49
		(void) signal(SIGINT, SIG_DFL);
		(void) signal(SIGHUP, SIG_DFL);
		(void) signal(SIGTERM, SIG_DFL);
I 55
D 188
		umask(OldUmask);
E 188
I 188
		(void) umask(OldUmask);
E 188
		if (stat(filename, &stb) < 0)
I 171
		{
			errno = 0;
E 171
D 62
			stb.st_mode = 0;
E 62
I 62
			stb.st_mode = 0666;
I 171
		}
E 171
E 62
		if (bitset(0111, stb.st_mode))
			exit(EX_CANTCREAT);
I 59
		if (ctladdr == NULL)
D 99
			ctladdr = &From;
E 99
I 99
			ctladdr = &CurEnv->e_from;
E 99
E 59
		if (!bitset(S_ISGID, stb.st_mode) || setgid(stb.st_gid) < 0)
D 58
			(void) setgid(getgid());
E 58
I 58
D 61
			(void) setgid(ctladdr->q_gid);
E 61
I 61
		{
			if (ctladdr->q_uid == 0)
				(void) setgid(DefGid);
			else
				(void) setgid(ctladdr->q_gid);
		}
E 61
E 58
		if (!bitset(S_ISUID, stb.st_mode) || setuid(stb.st_uid) < 0)
D 58
			(void) setuid(getuid());
E 58
I 58
D 61
			(void) setuid(ctladdr->q_uid);
E 61
I 61
		{
			if (ctladdr->q_uid == 0)
				(void) setuid(DefUid);
			else
				(void) setuid(ctladdr->q_uid);
		}
E 61
E 58
E 55
E 49
D 98
		f = fopen(filename, "a");
E 98
I 98
		f = dfopen(filename, "a");
E 98
		if (f == NULL)
			exit(EX_CANTCREAT);

D 72
		putmessage(f, Mailer[1]);
E 72
I 72
D 100
		putmessage(f, Mailer[1], FALSE);
E 100
I 100
D 154
		putfromline(f, Mailer[1]);
		(*CurEnv->e_puthdr)(f, Mailer[1], CurEnv);
E 154
I 154
D 159
		putfromline(f, ProgMailer);
		(*CurEnv->e_puthdr)(f, ProgMailer, CurEnv);
E 159
I 159
D 166
		putfromline(f, ProgMailer, FALSE);
		(*CurEnv->e_puthdr)(f, ProgMailer, CurEnv, FALSE);
E 159
E 154
D 107
		fprintf(f, "\n");
E 107
I 107
		fputs("\n", f);
E 107
D 154
		(*CurEnv->e_putbody)(f, Mailer[1], FALSE);
E 154
I 154
D 157
		(*CurEnv->e_putbody)(f, ProgMailer, FALSE);
E 157
I 157
D 159
		(*CurEnv->e_putbody)(f, ProgMailer, FALSE, CurEnv);
E 159
I 159
		(*CurEnv->e_putbody)(f, ProgMailer, FALSE, CurEnv, FALSE);
E 159
E 157
E 154
E 100
E 72
		fputs("\n", f);
E 166
I 166
		putfromline(f, ProgMailer);
		(*CurEnv->e_puthdr)(f, ProgMailer, CurEnv);
		putline("\n", f, ProgMailer);
		(*CurEnv->e_putbody)(f, ProgMailer, CurEnv);
		putline("\n", f, ProgMailer);
E 166
		(void) fclose(f);
		(void) fflush(stdout);
I 61

D 98
		/* reset ISUID & ISGID bits */
E 98
I 98
		/* reset ISUID & ISGID bits for paranoid systems */
E 98
D 69
		(void) chmod(filename, stb.st_mode);
E 69
I 69
		(void) chmod(filename, (int) stb.st_mode);
E 69
E 61
		exit(EX_OK);
I 54
		/*NOTREACHED*/
E 54
	}
	else
	{
		/* parent -- wait for exit status */
D 154
		register int i;
		auto int stat;
E 154
I 154
		int st;
E 154

D 154
		while ((i = wait(&stat)) != pid)
		{
			if (i < 0)
			{
				stat = EX_OSERR << 8;
				break;
			}
		}
I 49
		if ((stat & 0377) != 0)
			stat = EX_UNAVAILABLE << 8;
E 49
		return ((stat >> 8) & 0377);
E 154
I 154
		st = waitfor(pid);
		if ((st & 0377) != 0)
			return (EX_UNAVAILABLE);
		else
			return ((st >> 8) & 0377);
E 154
	}
E 48
}
I 67
/*
**  SENDALL -- actually send all the messages.
**
**	Parameters:
I 103
**		e -- the envelope to send.
E 103
D 150
**		verifyonly -- if set, only give verification messages.
E 150
I 150
D 177
**		mode -- the delivery mode to use.
E 177
I 177
**		mode -- the delivery mode to use.  If SM_DEFAULT, use
**			the current SendMode.
E 177
E 150
**
**	Returns:
**		none.
**
**	Side Effects:
**		Scans the send lists and sends everything it finds.
I 103
**		Delivers any appropriate error messages.
I 150
**		If we are running in a non-interactive mode, takes the
**			appropriate action.
E 150
E 103
*/

D 103
sendall(verifyonly)
E 103
I 103
D 150
sendall(e, verifyonly)
E 150
I 150
sendall(e, mode)
E 150
	ENVELOPE *e;
E 103
D 150
	bool verifyonly;
E 150
I 150
	char mode;
E 150
{
D 75
	register int i;
E 75
I 75
	register ADDRESS *q;
I 120
	bool oldverbose;
I 150
	int pid;
I 196
D 197
	register char *p;
	char user[MAXNAME];
	char buf[MAXNAME];
E 197
E 196
I 177

	/* determine actual delivery mode */
	if (mode == SM_DEFAULT)
	{
D 190
		extern int QueueLA;
E 190
I 190
		extern bool shouldqueue();
E 190

D 190
		if (getla() > QueueLA)
E 190
I 190
		if (shouldqueue(e->e_msgpriority))
E 190
			mode = SM_QUEUE;
		else
			mode = SendMode;
	}
E 177
E 150
E 120
E 75
D 103
	typedef int (*fnptr)();
E 103

I 76
D 154
# ifdef DEBUG
E 154
I 154
#ifdef DEBUG
E 154
D 117
	if (Debug > 1)
E 117
I 117
D 137
	if (tTd(13, 2))
E 137
I 137
	if (tTd(13, 1))
E 137
E 117
	{
D 99
		printf("\nSendQueue:\n");
		printaddr(SendQueue, TRUE);
E 99
I 99
D 137
		printf("\nSend Queue:\n");
E 137
I 137
D 144
		printf("\nSENDALL: verify %d, sendqueue:\n");
E 144
I 144
D 150
		printf("\nSENDALL: verify %d, sendqueue:\n", verifyonly);
E 150
I 150
		printf("\nSENDALL: mode %c, sendqueue:\n", mode);
E 150
E 144
E 137
D 103
		printaddr(CurEnv->e_sendqueue, TRUE);
E 103
I 103
		printaddr(e->e_sendqueue, TRUE);
E 103
E 99
	}
D 154
# endif DEBUG
E 154
I 154
#endif DEBUG
E 154
E 76
D 75
	for (i = 0; Mailer[i] != NULL; i++)
	{
		ADDRESS *q;
E 75

D 75
		for (q = Mailer[i]->m_sendq; q != NULL; q = q->q_next)
E 75
I 75
D 99
	for (q = SendQueue; q != NULL; q = q->q_next)
E 99
I 99
D 103
	for (q = CurEnv->e_sendqueue; q != NULL; q = q->q_next)
E 103
I 103
	/*
D 150
	**  Run through the list and send everything.
E 150
I 150
	**  Do any preprocessing necessary for the mode we are running.
I 154
	**	Check to make sure the hop count is reasonable.
	**	Delete sends to the sender in mailing lists.
E 154
E 150
	*/

I 150
D 154
# ifdef QUEUE
	if (mode == SM_QUEUE)
E 154
I 154
	CurEnv = e;

	if (e->e_hopcount > MAXHOP)
E 154
	{
D 154
		register ADDRESS *q;
E 154
I 154
		syserr("sendall: too many hops (%d max)", MAXHOP);
		return;
	}
E 154

D 151
		for (q = CurEnv->e_sendqueue; q != NULL; q = q->q_next)
E 151
I 151
D 154
		for (q = e->e_sendqueue; q != NULL; q = q->q_next)
E 151
		{
			if (!bitset(QDONTSEND, q->q_flags))
			{
D 151
				CurEnv->e_to = q->q_paddr;
E 151
I 151
				e->e_to = q->q_paddr;
E 151
				message(Arpa_Info, "queued");
				if (LogLevel > 4)
					logdelivery("queued");
			}
D 151
			CurEnv->e_to = NULL;
E 151
I 151
			e->e_to = NULL;
E 151
		}
E 154
I 154
	if (!MeToo)
	{
I 175
		extern ADDRESS *recipient();

E 175
		e->e_from.q_flags |= QDONTSEND;
D 175
		recipient(&e->e_from, &e->e_sendqueue);
E 175
I 175
		(void) recipient(&e->e_from, &e->e_sendqueue);
E 175
E 154
	}
I 154

# ifdef QUEUE
E 154
D 152
	if (mode == SM_QUEUE || mode == SM_FORK ||
	    (mode != SM_VERIFY && SuperSafe))
E 152
I 152
	if ((mode == SM_QUEUE || mode == SM_FORK ||
	     (mode != SM_VERIFY && SuperSafe)) &&
	    !bitset(EF_INQUEUE, e->e_flags))
E 152
D 151
		queueup(CurEnv, TRUE);
E 151
I 151
D 154
		queueup(e, TRUE);
E 154
I 154
		queueup(e, TRUE, mode == SM_QUEUE);
E 154
E 151
#endif QUEUE

E 150
I 120
	oldverbose = Verbose;
D 150
	if (verifyonly)
E 150
I 150
	switch (mode)
	{
	  case SM_VERIFY:
E 150
		Verbose = TRUE;
I 150
		break;

	  case SM_QUEUE:
D 151
		CurEnv->e_df = CurEnv->e_qf = NULL;
		CurEnv->e_dontqueue = TRUE;
E 151
I 151
D 152
		e->e_df = e->e_qf = NULL;
		e->e_dontqueue = TRUE;
E 151
		finis();
E 152
I 152
		e->e_flags |= EF_INQUEUE|EF_KEEPQUEUE;
E 152
		return;

	  case SM_FORK:
I 151
D 152
		(void) fflush(Xscript);
E 152
I 152
D 157
		if (Xscript != NULL)
			(void) fflush(Xscript);
E 157
I 157
		if (e->e_xfp != NULL)
			(void) fflush(e->e_xfp);
E 157
E 152
E 151
		pid = fork();
		if (pid < 0)
		{
			mode = SM_DELIVER;
			break;
		}
		else if (pid > 0)
I 151
		{
			/* be sure we leave the temp files to our child */
D 152
			e->e_id = e->e_df = e->e_qf = NULL;
			e->e_dontqueue = TRUE;
			Transcript = NULL;
E 152
I 152
			e->e_id = e->e_df = NULL;
E 152
E 151
			return;
I 151
		}
E 151

		/* double fork to avoid zombies */
		if (fork() > 0)
			exit(EX_OK);

D 151
		/* now arrange to run the queue */
		HoldErrs = MailBack = TRUE;
		Verbose = FALSE;
E 151
I 151
		/* be sure we are immune from the terminal */
D 155
		disconnect(TRUE);
E 155
I 155
D 164
		disconnect();
E 164
I 164
		disconnect(FALSE);
E 164
E 155

E 151
		break;
	}

	/*
	**  Run through the list and send everything.
	*/

I 196
D 197
restart:
E 197
E 196
E 150
E 120
	for (q = e->e_sendqueue; q != NULL; q = q->q_next)
E 103
E 99
	{
D 150
		if (verifyonly)
E 150
I 150
		if (mode == SM_VERIFY)
E 150
E 75
		{
D 75
			if (verifyonly)
E 75
I 75
D 99
			To = q->q_paddr;
E 99
I 99
D 151
			CurEnv->e_to = q->q_paddr;
E 151
I 151
			e->e_to = q->q_paddr;
E 151
E 99
			if (!bitset(QDONTSEND|QBADADDR, q->q_flags))
E 75
D 106
			{
D 75
				To = q->q_paddr;
D 74
				if (!bitset(QDONTSEND|QBADADDR, q->q_flags))
E 74
I 74
				if (!bitset(QDONTSEND|QBADADDR|QPSEUDO, q->q_flags))
E 74
				{
D 68
					if (q->q_mailer == MN_LOCAL || q->q_mailer == MN_PROG)
E 68
I 68
					if (bitset(M_LOCAL, q->q_mailer->m_flags))
E 68
						message(Arpa_Info, "deliverable");
					else
						message(Arpa_Info, "queueable");
				}
E 75
I 75
				if (bitset(M_LOCAL, q->q_mailer->m_flags))
					message(Arpa_Info, "deliverable");
				else
					message(Arpa_Info, "queueable");
E 75
			}
E 106
I 106
				message(Arpa_Info, "deliverable");
E 106
D 75
			else
				(void) deliver(q, (fnptr) NULL);
E 75
		}
I 75
		else
I 196
D 197
		{
			if (strcmp(q->q_mailer->m_mailer, "[IPC]") == 0 &&
			    !bitset(QDONTSEND, q->q_flags))
			{
				if ((nmx = getmxrr(q->q_host, mxhosts, MAXMXHOSTS)) < 0)
				{
					mxhosts[0] = q->q_host;
					nmx = 1;
				}
				/* we get this mail */
				expand("\001j", buf, &buf[sizeof buf - 1], e);
				if (sameword(mxhosts[0], buf))
				{
					strcpy(user, q->q_user);
					if (p = index(user, '@'))
						*p = '\0';
					sendtolist(user, q, &e->e_sendqueue);
					goto restart;
				}
			}
E 197
E 196
D 100
			(void) deliver(q, (fnptr) NULL);
E 100
I 100
D 154
			(void) deliver(q);
E 154
I 154
			(void) deliver(e, q);
I 196
D 197
		}
E 197
E 196
E 154
I 103
	}
I 120
	Verbose = oldverbose;
E 120

	/*
	**  Now run through and check for errors.
	*/

D 150
	if (verifyonly)
E 150
I 150
	if (mode == SM_VERIFY)
E 150
		return;

	for (q = e->e_sendqueue; q != NULL; q = q->q_next)
	{
		register ADDRESS *qq;

I 137
# ifdef DEBUG
		if (tTd(13, 3))
		{
			printf("Checking ");
			printaddr(q, FALSE);
		}
# endif DEBUG

E 137
D 152
		if (bitset(QQUEUEUP, q->q_flags))
			e->e_queueup = TRUE;
E 152
I 152
		/* only send errors if the message failed */
		if (!bitset(QBADADDR, q->q_flags))
			continue;
E 152
D 137
		if (!bitset(QBADADDR, q->q_flags))
			continue;
E 137

		/* we have an address that failed -- find the parent */
		for (qq = q; qq != NULL; qq = qq->q_alias)
		{
			char obuf[MAXNAME + 6];
			extern char *aliaslookup();

			/* we can only have owners for local addresses */
D 168
			if (!bitset(M_LOCAL, qq->q_mailer->m_flags))
E 168
I 168
			if (!bitnset(M_LOCAL, qq->q_mailer->m_flags))
E 168
				continue;

			/* see if the owner list exists */
			(void) strcpy(obuf, "owner-");
D 104
			(void) strcat(obuf, qq->q_user);
E 104
I 104
			if (strncmp(qq->q_user, "owner-", 6) == 0)
				(void) strcat(obuf, "owner");
			else
				(void) strcat(obuf, qq->q_user);
E 104
D 212
			if (aliaslookup(obuf) == NULL)
E 212
I 212
			if (aliaslookup(obuf, NULL) == NULL)
E 212
				continue;
I 137

# ifdef DEBUG
			if (tTd(13, 4))
				printf("Errors to %s\n", obuf);
# endif DEBUG

D 152
			/* add in an errors-to field */
				/*   ugh... must happen before delivery.....
			addheader("errors-to", newstr(obuf), e);
				.... i guess this should go in sendto */

			/* only send errors if the message failed */
			if (!bitset(QBADADDR, q->q_flags))
				break;
E 137

E 152
			/* owner list exists -- add it to the error queue */
D 154
			qq->q_flags &= ~QPRIMARY;
D 129
			sendto(obuf, 1, qq, &e->e_errorqueue);
E 129
I 129
			sendto(obuf, qq, &e->e_errorqueue);
E 129
			MailBack = TRUE;
E 154
I 154
D 158
			sendto(obuf, (ADDRESS *) NULL, &e->e_errorqueue);
E 158
I 158
			sendtolist(obuf, (ADDRESS *) NULL, &e->e_errorqueue);
E 158
D 183
			ErrorMode == EM_MAIL;
E 183
I 183
			ErrorMode = EM_MAIL;
E 183
E 154
			break;
		}

		/* if we did not find an owner, send to the sender */
D 139
		if (qq == NULL)
E 139
I 139
		if (qq == NULL && bitset(QBADADDR, q->q_flags))
E 139
D 129
			sendto(e->e_from.q_paddr, 1, qq, &e->e_errorqueue);
E 129
I 129
D 158
			sendto(e->e_from.q_paddr, qq, &e->e_errorqueue);
E 158
I 158
			sendtolist(e->e_from.q_paddr, qq, &e->e_errorqueue);
E 158
E 129
	}
I 150

	if (mode == SM_FORK)
		finis();
E 150
D 154
}
/*
**  CHECKERRORS -- check a queue of addresses and process errors.
**
**	Parameters:
**		e -- the envelope to check.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Arranges to queue all tempfailed messages in q
**			or deliver error responses.
*/

checkerrors(e)
	register ENVELOPE *e;
{
I 121
D 153
	register ADDRESS *q;

E 153
E 121
# ifdef DEBUG
D 117
	if (Debug > 0)
E 117
I 117
	if (tTd(4, 1))
E 117
	{
D 115
		printf("\ncheckerrors: errorqueue:\n");
E 115
I 115
D 152
		printf("\ncheckerrors: FatalErrors %d, errorqueue:\n");
E 152
I 152
		printf("\ncheckerrors: e_flags %o, errorqueue:\n", e->e_flags);
E 152
E 115
		printaddr(e->e_errorqueue, TRUE);
	}
# endif DEBUG

	/* mail back the transcript on errors */
D 152
	if (FatalErrors)
		savemail();

	/* queue up anything laying around */
I 122
	if (e->e_dontqueue)
		return;
E 122
D 121
	if (e->e_queueup)
E 121
I 121
	for (q = e->e_sendqueue; q != NULL; q = q->q_next)
E 121
	{
I 121
		if (bitset(QQUEUEUP, q->q_flags))
		{
E 121
# ifdef QUEUE
D 121
		queueup(e, FALSE);
E 121
I 121
			queueup(e, FALSE);
I 138
			e->e_df = e->e_qf = NULL;
			e->e_dontqueue = TRUE;
E 138
E 121
# else QUEUE
D 121
		syserr("finis: trying to queue %s", e->e_df);
E 121
I 121
			syserr("checkerrors: trying to queue %s", e->e_df);
E 121
# endif QUEUE
I 121
			break;
		}
E 121
E 103
E 100
E 75
	}
E 152
I 152
	if (bitset(EF_FATALERRS, e->e_flags))
		savemail(e);
E 154
E 152
}
E 67
E 1
