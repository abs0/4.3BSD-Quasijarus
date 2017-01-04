h65197
s 00011/00009/01193
d D 5.9 88/06/30 14:59:17 bostic 125 124
c install approved copyright notice
e
s 00016/00010/01186
d D 5.8 88/03/13 19:52:30 bostic 124 123
c add Berkeley specific header
e
s 00003/00005/01193
d D 5.7 88/03/13 18:21:42 bostic 123 122
c replace sameword with strcasecmp
e
s 00000/00005/01198
d D 5.6 86/04/02 16:00:55 eric 122 121
c don't run around clearing EF_FATALERRS -- this often applies to another
c address.  Drop uid/gid check in sameaddr -- it causes more problems
c than it fixes.
e
s 00002/00002/01201
d D 5.5 86/01/30 11:02:18 eric 121 120
c fix .forward files that include yourself; this was a bug in sameaddr
c that may have caused some other problems
e
s 00004/00000/01199
d D 5.4 85/11/22 08:26:44 eric 120 119
m 
c don't consider addresses with different q_uid's alike
e
s 00001/00001/01198
d D 5.3 85/10/24 10:36:36 eric 119 118
m 
c don't create a queue name in syserr; permit trailing blanks and quoted
c commas in aliases.
e
s 00000/00000/01199
d D 5.2 85/09/19 01:25:52 eric 118 116
i 117
m 
c incorporate SMI changes -- still experimental
e
s 00012/00007/01187
d D 5.1.1.1 85/09/19 00:56:11 eric 117 116
m 
c SMI changes (somewhat)
e
s 00000/00000/01194
d D 5.1 85/06/08 10:25:54 eric 116 115
m 
c bring to release 5 (like all the other files)
e
s 00003/00003/01191
d D 4.17 85/06/08 00:42:51 eric 115 114
m 
c lint
e
s 00016/00005/01178
d D 4.16 85/06/07 22:31:05 miriam 114 113
m 
c Resolve duplicate SccsId.  Remove unused variables.  Correct 
c return.
e
s 00008/00001/01175
d D 4.15 85/04/28 10:44:23 eric 113 112
m 
c use the recipient rewriting set for parsed addresses
e
s 00004/00000/01172
d D 4.14 84/12/05 23:15:41 eric 112 111
m 
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00001/00001/01171
d D 4.13 84/11/13 11:33:43 eric 111 110
m 
c bmove => bcopy
e
s 00001/00001/01171
d D 4.12 84/09/09 14:28:22 eric 110 109
m 
c fix absurd trivial botch in previous change
e
s 00007/00003/01165
d D 4.11 84/09/08 17:43:36 eric 109 108
m 
c fix hostname mapping to be repeatable (as required by some .cf files).
e
s 00006/00006/01162
d D 4.10 84/08/12 00:19:01 eric 108 107
m 
c clean up botch in $[ $] code
e
s 00103/00032/01065
d D 4.9 84/08/11 23:20:10 eric 107 106
m 
c Add $[ and $] as RHS operators to look up the contents and pass them
c to maphostname; maphostname currently looks them up in /etc/hosts and
c converts them to canonical form, but could be turned into a general
c name server.....   huzzah!!
e
s 00002/00002/01095
d D 4.8 84/08/11 17:52:58 eric 106 105
m 
c Assorted changes from Guy Harris <rlgvax!guy>: mostly lint & USG
e
s 00008/00003/01089
d D 4.7 84/08/11 16:55:38 eric 105 103
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00057/00014/01078
d D 4.6.1.1 84/06/17 16:18:24 eric 104 103
m 
c abortive attempt to install a name server.... sigh.
e
s 00008/00002/01084
d D 4.6 84/03/17 16:27:30 eric 103 102
m 
c always fold case on host names; fold case on the LHS of aliases
e
s 00023/00009/01063
d D 4.5 84/03/11 19:58:44 eric 102 101
m 
c disable UPPER->lower case mapping in RHS's of aliases so that upper
c case letters can be used in file names and as args to programs.
e
s 00003/00010/01069
d D 4.4 84/03/11 16:55:38 eric 101 100
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00014/00002/01065
d D 4.3 83/10/23 17:15:42 eric 100 99
m 
c handle dollar signs in headers properly
e
s 00004/00000/01063
d D 4.2 83/10/16 15:25:42 eric 99 98
m 
c reset errno in parseaddr so that syserr gives a permanent error code and
c no extraneous information about non-errors
e
s 00000/00000/01063
d D 4.1 83/07/25 19:46:46 eric 98 97
m 
c 4.2 release version
e
s 00001/00000/01062
d D 3.81 83/03/26 14:25:26 eric 97 96
m 215
c rewrite again with ruleset 3 after appending from domain so that we can
c add any punctuation, e.g., "<" "@" "domain" ">"
e
s 00005/00002/01057
d D 3.80 83/03/08 19:21:47 eric 96 95
m 205
c Pass the delimiter character to parseaddr so that we can correctly
c decide between comma and space
e
s 00003/00001/01056
d D 3.79 83/03/07 09:24:34 eric 95 94
m 202
c Handle OLDSTYLE addresses properly with the -t flag; notice that tabs also
c delimit addresses (as well as spaces)
e
s 00001/00001/01056
d D 3.78 83/03/05 17:37:54 eric 94 93
m 200
c Ignore delimiters (e.g., commas) inside quotes
e
s 00002/00001/01055
d D 3.77 83/02/24 20:02:44 eric 93 92
m 181
c arrange to cleanup addresses using ruleset 4 before storing in ADDR struct
e
s 00002/00002/01054
d D 3.76 83/02/19 14:41:40 eric 92 91
m 188
c Avoid core dumps on very long addresses in headers.
e
s 00005/00013/01051
d D 3.75 83/02/02 12:55:01 eric 91 90
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00008/00037/01056
d D 3.74 83/01/15 17:41:30 eric 90 89
m 149
c be sure everything gets appropriately externalized; canonname goes away,
c since everything is now done by remotename
e
s 00006/00001/01087
d D 3.73 83/01/06 18:21:30 eric 89 88
m 
c allow user-setable error codes in "error" mailer
e
s 00004/00000/01084
d D 3.72 83/01/06 10:49:48 eric 88 87
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00001/00000/01083
d D 3.71 83/01/03 14:02:03 eric 87 86
m 
c have canonname pass the address through ruleset four also
e
s 00004/00004/01079
d D 3.70 82/12/24 08:15:34 eric 86 85
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00004/00002/01079
d D 3.69 82/12/09 19:18:11 eric 85 84
m 036
m 053
m 064
c Fix a bug triggered when we add the sender's "@domain" to an address
c in the message body that is missing a domain -- we forgot to null
c terminate the list.
e
s 00013/00006/01068
d D 3.68 82/12/09 11:17:43 eric 84 83
m 095
c be able to match the inverse of a class using the $~x syntax
e
s 00086/00092/00988
d D 3.67 82/11/28 00:21:33 eric 83 82
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00001/00002/01079
d D 3.66 82/11/24 18:44:00 eric 82 81
m 
c lint it
e
s 00002/00002/01079
d D 3.65 82/11/17 09:36:07 eric 81 80
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00003/00003/01078
d D 3.64 82/11/03 11:17:32 eric 80 79
m 059
c don't strip quotes off of addresses during prescan
e
s 00001/00001/01080
d D 3.63 82/11/03 09:48:57 eric 79 78
m 049
c Arrange to strip quote bits in message header; move SPACESUB into
c conf.c; change SpaceSub to unquoted dot
e
s 00012/00003/01069
d D 3.62 82/10/31 13:46:39 eric 78 77
m 032,
m 051
c Call ruleset 4 after doing per-mailer translation to convert from
c internal to external form.
e
s 00004/00000/01068
d D 3.61 82/10/13 18:43:06 eric 77 76
m 022
c Don't interpret <, >, (, or ) while in QST (quote state) during prescan
e
s 00025/00002/01043
d D 3.60 82/10/09 09:05:11 eric 76 75
m 001
c implement an experimental forward-path algorithm by stripping off a
c leading "@..." component and dropping it on the end.
e
s 00004/00001/01041
d D 3.59 82/10/07 08:50:53 eric 75 74
c never use ruleset 3 alone -- perhaps the standard use of ruleset
c three should go now, since noone uses it alone.
e
s 00002/00006/01040
d D 3.58 82/10/06 11:44:40 eric 74 73
c add test mode (MD_TEST, -bt)
e
s 00016/00014/01030
d D 3.57 82/09/16 20:24:38 eric 73 72
x 72
c drop ":...;" stuff -- it screws it up aliases; pass parameters to
c subroutines (this also adds $@ and $: features to subr calls); check
c overflow of "tobuf" on smtp deliveries, which caused core dumps on
c large mailing lists
e
s 00011/00000/01044
d D 3.56 82/09/12 22:17:08 eric 72 71
c accept ": ... ;" syntax for groups if !oldstyle
e
s 00047/00016/00997
d D 3.55 82/09/12 16:43:39 eric 71 70
c change inheritance for macros in envelopes; be able to canonicalize
c non-domained names by appending domain from sender; call ruleset 3
c explicitly before doing other rulesets; some general cleanup.
e
s 00002/00002/01011
d D 3.54 82/09/06 17:58:21 eric 70 69
c fix bug in scanner state machine that never let you out of quote state.
e
s 00130/00113/00883
d D 3.53 82/09/06 16:24:18 eric 69 68
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00054/00078/00942
d D 3.52 82/09/05 18:08:38 eric 68 67
c change $g processing from a macro substitution per mailer to two sets
c of rewriting rules per mailer -- one each for sender and recipient
c fields; convert to NBS standard on Return-Receipt-To: and Precedence:
c fields; clean up From: processing code and generalize it to all
c sender fields; tune debugging code; clean up canonname.
c **** This delta invalidates previous configuration files ****
e
s 00072/00025/00948
d D 3.51 82/09/05 11:48:09 eric 67 66
c add $* to match zero or more and $> to make a "subroutine" call; stick
c in initial hooks for per-mailer rewriting; improve diagnostics in readcf,
c including number lines; increase the number of rewriting sets.
e
s 00003/00001/00970
d D 3.50 82/09/01 10:23:14 eric 66 65
c allow CANONUSER ($:) to abort a rewriting set
e
s 00005/00004/00966
d D 3.49 82/08/27 16:00:29 eric 65 64
c simplify timeout code; allow multiple simultaneous queue runs so that
c large messages don't freeze things up; fix EINTR problem in sfgets;
c clean up canonname to be really correct; lots of misc. cleanup
e
s 00043/00038/00927
d D 3.48 82/08/25 16:18:39 eric 64 63
c apply ruleset 4 to rewrite addresses in the body of the message; fix
c a clock.c bug that caused it to lose events; more time cleanup.
e
s 00001/00038/00964
d D 3.47 82/08/21 17:54:19 eric 63 62
c move <> and forward path processing to .cf file; increase MAXATOMS
c since some "comment" information may now be part of the address.
c **** this installation requires a new sendmail.cf file ****
e
s 00012/00001/00990
d D 3.46 82/08/15 11:54:00 eric 62 61
c add debugging info
e
s 00124/00000/00867
d D 3.45 82/08/08 16:58:18 eric 61 60
c move remotename() from deliver.c to parse.c; initial implementation
c of canonname()
e
s 00008/00008/00859
d D 3.44 82/08/08 01:02:37 eric 60 59
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00004/00004/00863
d D 3.43 82/05/31 18:49:12 eric 59 58
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00000/00000/00867
d D 3.42 82/05/31 15:31:55 eric 58 56
i 57
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00001/00001/00866
d D 3.41.1.1 82/05/29 18:20:02 eric 57 56
c try to install envelopes.  is this really worth it???
e
s 00001/00001/00866
d D 3.41 82/05/22 01:37:38 eric 56 55
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00001/00001/00866
d D 3.40 82/03/20 16:12:14 eric 55 54
c 16 bit changes -- should have no effect on VAX binaries to
c speak of.
e
s 00007/00064/00860
d D 3.39 82/03/06 14:14:58 eric 54 53
c collapse special character processing into macro processing for
c simplicity of code.
e
s 00005/00004/00919
d D 3.38 82/02/04 20:30:13 eric 53 52
c add host aliasing; add -p flag.  this version doesn't yet know about
c replacing the text of the host alias into the message however.  syntax
c is grotty: "/hostmatch:%s@newhost" or whatever.
e
s 00001/00001/00922
d D 3.37 81/12/06 12:38:35 eric 52 51
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00002/00002/00921
d D 3.36 81/11/22 19:17:33 eric 51 50
c Edit queue control files when running queue (assuming there are still
c recipients left).  Also, modify the MsgPriority to be the absolute
c number (not the Priority: value); this allows us to include aging into
c the priority algorithm.
e
s 00006/00002/00917
d D 3.35 81/11/21 18:42:12 eric 50 49
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00001/00002/00918
d D 3.34 81/11/21 16:37:57 eric 49 47
c convert to SMTP draft 3 -- finishing touches.  Punt on the VRFY/
c EXPN commands for now; they aren't required anyhow.  Move the fullname
c into the address structure so it can be inherited.
e
s 00018/00006/00914
d D 3.33.1.1 81/11/21 15:47:12 eric 48 47
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00003/00002/00917
d D 3.33 81/10/27 11:13:14 eric 47 46
c ignore case in mailer name comparison
e
s 00001/00002/00918
d D 3.32 81/10/26 14:22:22 eric 46 45
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00005/00005/00915
d D 3.31 81/10/23 19:37:41 eric 45 44
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00043/00023/00877
d D 3.30 81/10/08 09:16:51 eric 44 42
c fix botch in backup code during rewriting
e
s 00043/00022/00878
d R 3.30 81/10/08 09:13:17 eric 43 42
c fix botch in backup code during rewriting
e
s 00048/00141/00852
d D 3.29 81/10/06 19:12:41 eric 42 41
c change rewriting rules to use $N on RHS to match LHS, and include
c $=X (class match) in the matching; this will allow us to match the
c proposed "user.host@domain" syntax as well as the old syntax, by
c putting the known domains into a class to disambiguate.
e
s 00007/00007/00986
d D 3.28 81/09/30 10:00:04 eric 41 40
c fix the <> syntax, convert "at" to "@" in from addresses also,
c plus some minorness to get the multi-machine case going nicely.
e
s 00008/00004/00985
d D 3.27 81/09/28 19:17:12 eric 40 39
c enable aliases to self-reference themselves correctly.
e
s 00019/00009/00970
d D 3.26 81/09/22 13:24:08 eric 39 38
c fix problem with using macros in rules; change configuration to send
c different flags when destined for arpanet vs. berknet hosts, etc.
e
s 00017/00000/00962
d D 3.25 81/09/14 12:41:14 eric 38 37
c check MAXATOM overflow; increase MAXATOM value
e
s 00000/00001/00962
d D 3.24 81/09/12 17:33:48 eric 37 36
c match on full name for local users
e
s 00004/00004/00959
d D 3.23 81/09/06 19:48:36 eric 36 35
c cleanup, commenting, linting, etc.
e
s 00030/00001/00933
d D 3.22 81/08/31 12:11:35 eric 35 34
c allow "error" as a net name to print error messages
e
s 00000/00000/00934
d D 3.21 81/08/25 16:05:53 eric 34 33
i 32
c remove special "at" processing (put it in .cf file)
e
s 00051/00019/00894
d D 3.20 81/08/25 16:01:42 eric 33 31
c change processing of <LWSP> in addresses
e
s 00000/00011/00902
d D 3.19.1.1 81/08/25 13:42:16 eric 32 31
c remove special "at" processing (experimental)
e
s 00002/00002/00911
d D 3.19 81/08/21 18:18:19 eric 31 30
c drop M_FINAL, change some other defined constant names
e
s 00000/00002/00913
d D 3.18 81/08/20 15:14:02 eric 30 29
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00024/00015/00891
d D 3.17 81/08/10 16:56:30 eric 29 28
c totally rework aliasing scheme -- sucks when no DBM now,
c but works better for the usual case; fix some quoting problems
c (and how many did I add?); remove .mailer feature since .forward
c will simulate this happily
e
s 00007/00010/00899
d D 3.16 81/08/09 15:02:46 eric 28 27
c lint it
e
s 00001/00000/00908
d D 3.15 81/08/09 12:34:32 eric 27 26
c add private incoming mailers; add q_home field to ADDRESS struct;
c some general cleanup
e
s 00004/00003/00904
d D 3.14 81/08/08 17:47:33 eric 26 25
c add another set of rewrite rules to process From: address;
c this will allow generalized from address processing in an
c internet
e
s 00025/00006/00882
d D 3.13 81/08/08 11:17:49 eric 25 24
c add word classes
e
s 00003/00002/00885
d D 3.12 81/03/27 14:31:09 eric 24 23
c fix funny botch in $o exclusion
e
s 00010/00002/00877
d D 3.11 81/03/27 13:54:59 eric 23 22
c put word delimiters into cf file
e
s 00001/00001/00878
d D 3.10 81/03/20 09:45:16 eric 22 21
c change name (again); from postbox to sendmail
e
s 00032/00000/00847
d D 3.9 81/03/12 10:57:09 eric 21 20
c merge letters to the same host into one message
e
s 00065/00011/00782
d D 3.8 81/03/11 10:45:50 eric 20 19
c general cleanup, esp. macro processor
e
s 00002/00002/00791
d D 3.7 81/03/09 14:21:12 eric 19 18
c fix botch in string compares
e
s 00569/00295/00224
d D 3.6 81/03/09 13:22:02 eric 18 17
c first step at rewriting rules, etc.
e
s 00034/00001/00485
d D 3.5 81/03/08 13:05:00 eric 17 16
c do host equivalence
e
s 00002/00003/00484
d D 3.4 81/03/07 16:59:32 eric 16 15
c change q_mailer to be index, not pointer
e
s 00001/00000/00486
d D 3.3 81/03/07 15:32:33 eric 15 14
c lint fixes
e
s 00001/00000/00485
d D 3.2 81/03/07 14:58:19 eric 14 13
c save real mailer
e
s 00023/00034/00462
d D 3.1 81/03/07 14:26:50 eric 13 12
c ----- delivermail ==> postbox -----
e
s 00001/00001/00495
d D 2.5 81/01/08 23:57:36 eric 12 11
c fixed botch in at => @ translation
e
s 00001/00001/00495
d D 2.4 81/01/08 19:50:58 eric 11 10
c fix problem with "isspace" on non-ascii characters
e
s 00010/00002/00486
d D 2.3 81/01/08 19:36:42 eric 10 9
c disallowed multiple <> spec
e
s 00021/00005/00467
d D 2.2 81/01/08 19:27:29 eric 9 8
c turn <lwsp> (spaces) into quoted '.' instead of nothing (for CMU)
e
s 00000/00000/00472
d D 2.1 80/11/05 11:01:09 eric 8 7
c release 2
e
s 00002/00002/00470
d D 1.7 80/10/21 12:13:01 eric 7 6
c fix bug with bslashmode & don't strip quote bits in prescan
e
s 00001/00001/00471
d D 1.6 80/10/21 11:53:45 eric 6 5
c print result at all times
e
s 00038/00000/00434
d D 1.5 80/10/18 16:49:23 eric 5 4
c cleanup for dbm stuff: Error => Errors; move local host
c detection into parse; misc cleanup
e
s 00004/00003/00430
d D 1.4 80/10/11 12:57:13 eric 4 3
c cleaned up algorithm slightly
e
s 00000/00032/00433
d D 1.3 80/08/02 13:49:38 eric 3 2
c cleaned up comments
e
s 00002/00000/00463
d D 1.2 80/07/25 22:04:06 eric 2 1
c add ID keywords
e
s 00463/00000/00000
d D 1.1 80/06/23 08:24:29 eric 1 0
e
u
U
f b 
f i 
t
T
I 1
D 30
# include <stdio.h>
# include <ctype.h>
E 30
D 13
# include "dlvrmail.h"
E 13
I 13
D 22
# include "postbox.h"
E 22
I 22
D 114
# include "sendmail.h"
E 114
E 22
E 13
D 121

E 121
I 2
D 50
static char	SccsId[] = "%W%	%G%";
E 50
I 50
D 52
static char	SccsId[] =	"%W%	%G%";
E 52
I 52
D 114
SCCSID(%W%	%Y%	%G%);
E 114
I 114
/*
I 125
 * Copyright (c) 1983 Eric P. Allman
E 125
D 124
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 124
I 124
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 125
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 125
I 125
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
E 125
 */
E 124
E 114
E 52
E 50

I 114
#ifndef lint
D 124
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 124
I 124
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 124

# include "sendmail.h"

E 114
E 2
/*
D 86
**  PARSE -- Parse an address
E 86
I 86
**  PARSEADDR -- Parse an address
E 86
**
**	Parses an address and breaks it up into three parts: a
**	net to transmit the message on, the host to transmit it
**	to, and a user on that host.  These are loaded into an
D 13
**	addrq header with the values squirreled away if necessary.
E 13
I 13
**	ADDRESS header with the values squirreled away if necessary.
E 13
**	The "user" part may not be a real user; the process may
**	just reoccur on that machine.  For example, on a machine
**	with an arpanet connection, the address
**		csvax.bill@berkeley
**	will break up to a "user" of 'csvax.bill' and a host
**	of 'berkeley' -- to be transmitted over the arpanet.
**
**	Parameters:
**		addr -- the address to parse.
**		a -- a pointer to the address descriptor buffer.
**			If NULL, a header will be created.
**		copyf -- determines what shall be copied:
**			-1 -- don't copy anything.  The printname
**				(q_paddr) is just addr, and the
**				user & host are allocated internally
**				to parse.
**			0 -- copy out the parsed user & host, but
**				don't copy the printname.
**			+1 -- copy everything.
I 96
**		delim -- the character to terminate the address, passed
**			to prescan.
E 96
**
**	Returns:
**		A pointer to the address descriptor header (`a' if
**			`a' is non-NULL).
**		NULL on error.
**
**	Side Effects:
**		none
D 33
**
D 3
**	Defined Constants:
**		none
**
**	Requires:
**		usrerr
**		strcpy (sys)
**		isalpha (sys)
**		xalloc
**		prescan
**		flagset
**		makelower
**		printf (sys)
**		ParseTab -- the parse table.
**
E 3
**	Called By:
**		main
**		sendto
**		alias
**		savemail
E 33
D 3
**
**	History:
**		12/26/79 -- written.
E 3
*/

I 83
/* following delimiters are inherent to the internal algorithms */
E 83
I 9
D 12
# define DELIMCHARS	"()<>@!.,;:\\\""	/* word delimiters */
E 12
I 12
D 18
# define DELIMCHARS	"()<>@!.,;:\\\" \t\r\n"	/* word delimiters */
E 18
I 18
D 23
# define DELIMCHARS	"$()<>@!.,;:\\\" \t\r\n"	/* word delimiters */
E 23
I 23
D 101
# define DELIMCHARS	"$()<>,;\\\"\r\n"	/* word delimiters */
E 101
I 101
# define DELIMCHARS	"\001()<>,;\\\"\r\n"	/* word delimiters */
E 101
E 23
E 18
E 12
D 37
# define SPACESUB	('.'|0200)		/* substitution for <lwsp> */
E 37

E 9
D 13
addrq *
E 13
I 13
ADDRESS *
E 13
D 86
parse(addr, a, copyf)
E 86
I 86
D 96
parseaddr(addr, a, copyf)
E 96
I 96
parseaddr(addr, a, copyf, delim)
E 96
E 86
	char *addr;
D 13
	register addrq *a;
E 13
I 13
	register ADDRESS *a;
E 13
	int copyf;
I 96
	char delim;
E 96
{
D 18
	register char *p;
	register struct parsetab *t;
	extern struct parsetab ParseTab[];
	static char buf[MAXNAME];
	register char c;
	register char *q;
	bool got_one;
	extern char *prescan();
E 18
I 18
	register char **pvp;
	register struct mailer *m;
I 107
	char pvpbuf[PSBUFSIZE];
E 107
	extern char **prescan();
E 18
D 20
	extern char *xalloc();
E 20
I 13
D 28
	extern char *newstr();
E 13
I 5
D 18
	char **pvp;
I 17
	char ***hvp;
E 18
E 17
I 15
	extern char *strcpy();
E 28
I 18
	extern ADDRESS *buildaddr();
I 64
D 82
	static char nbuf[MAXNAME];
E 82
E 64
E 18
E 15
E 5

	/*
	**  Initialize and prescan address.
	*/

D 56
	To = addr;
E 56
I 56
	CurEnv->e_to = addr;
E 56
I 20
# ifdef DEBUG
D 60
	if (Debug)
E 60
I 60
	if (tTd(20, 1))
E 60
D 86
		printf("\n--parse(%s)\n", addr);
E 86
I 86
		printf("\n--parseaddr(%s)\n", addr);
E 86
# endif DEBUG

E 20
D 18
	if (prescan(addr, buf, &buf[sizeof buf], '\0') == NULL)
E 18
I 18
D 69
	pvp = prescan(addr, '\0');
E 69
I 69
D 95
	pvp = prescan(addr, ',');
E 95
I 95
D 96
	pvp = prescan(addr, bitset(EF_OLDSTYLE, CurEnv->e_flags) ? ' ' : ',');
E 96
I 96
D 107
	pvp = prescan(addr, delim);
E 107
I 107
	pvp = prescan(addr, delim, pvpbuf);
E 107
E 96
E 95
E 69
	if (pvp == NULL)
E 18
		return (NULL);

	/*
D 18
	**  Scan parse table.
	**	Look for the first entry designating a character
	**		that is contained in the address.
	**	Arrange for q to point to that character.
	**	Check to see that there is only one of the char
	**		if it must be unique.
	**	Find the last one if the host is on the RHS.
	**	Insist that the host name is atomic.
	**	If just doing a map, do the map and then start all
	**		over.
E 18
I 18
	**  Apply rewriting rules.
I 64
D 68
	**	Ruleset 4 rewrites the address into a form that will
	**		be reflected in the outgoing message.  It must
	**		not resolve.
E 68
	**	Ruleset 0 does basic parsing.  It must resolve.
E 64
E 18
	*/

I 71
	rewrite(pvp, 3);
E 71
I 64
D 68
	rewrite(pvp, 4);
E 68
E 64
D 18
 rescan:
	got_one = FALSE;
	for (t = ParseTab; t->p_char != '\0'; t++)
	{
		q = NULL;
		for (p = buf; (c = *p) != '\0'; p++)
		{
			/* find the end of this token */
			while (isalnum(c) || c == '-' || c == '_')
				c = *++p;
			if (c == '\0')
				break;
E 18
I 18
D 26
	rewrite(pvp);
E 26
I 26
	rewrite(pvp, 0);
E 26
E 18

D 18
			if (c == t->p_char)
			{
				got_one = TRUE;
E 18
I 18
	/*
	**  See if we resolved to a real mailer.
	*/
E 18

D 18
				/* do mapping as appropriate */
D 13
				if (flagset(P_MAP, t->p_flags))
E 13
I 13
				if (bitset(P_MAP, t->p_flags))
E 13
				{
					*p = t->p_arg[0];
D 13
					if (flagset(P_ONE, t->p_flags))
E 13
I 13
					if (bitset(P_ONE, t->p_flags))
E 13
						goto rescan;
					else
						continue;
				}

				/* arrange for q to point to it */
D 13
				if (q != NULL && flagset(P_ONE, t->p_flags))
E 13
I 13
				if (q != NULL && bitset(P_ONE, t->p_flags))
E 13
				{
					usrerr("multichar error");
					ExitStat = EX_USAGE;
					return (NULL);
				}
D 13
				if (q == NULL || flagset(P_HLAST, t->p_flags))
E 13
I 13
				if (q == NULL || bitset(P_HLAST, t->p_flags))
E 13
					q = p;
			}
			else
			{
				/* insist that host name is atomic */
D 13
				if (flagset(P_HLAST, t->p_flags))
E 13
I 13
				if (bitset(P_HLAST, t->p_flags))
E 13
					q = NULL;
				else
					break;
			}
		}

		if (q != NULL)
			break;
E 18
I 18
	if (pvp[0][0] != CANONNET)
	{
		setstat(EX_USAGE);
		usrerr("cannot resolve name");
		return (NULL);
E 18
	}

	/*
D 18
	**  If we matched nothing cleanly, but we did match something
	**  somewhere in the process of scanning, then we have a
	**  syntax error.  This can happen on things like a@b:c where
	**  @ has a right host and : has a left host.
	**
	**  We also set `q' to the null string, in case someone forgets
	**  to put the P_MOVE bit in the local mailer entry of the
	**  configuration table.
E 18
I 18
	**  Build canonical address from pvp.
E 18
	*/

D 18
	if (q == NULL)
	{
		q = "";
		if (got_one)
		{
			usrerr("syntax error");
			ExitStat = EX_USAGE;
			return (NULL);
		}
	}
E 18
I 18
	a = buildaddr(pvp, a);
I 35
	if (a == NULL)
		return (NULL);
E 35
D 45
	m = Mailer[a->q_mailer];
E 45
I 45
	m = a->q_mailer;
E 45
E 18

	/*
D 18
	**  Interpret entry.
	**	t points to the entry for the mailer we will use.
	**	q points to the significant character.
E 18
I 18
	**  Make local copies of the host & user and then
	**  transport them out.
E 18
	*/

D 18
	if (a == NULL)
D 13
		a = (addrq *) xalloc(sizeof *a);
E 13
I 13
		a = (ADDRESS *) xalloc(sizeof *a);
E 18
E 13
	if (copyf > 0)
I 69
	{
		extern char *DelimChar;
		char savec = *DelimChar;

		*DelimChar = '\0';
E 69
D 13
	{
		p = xalloc((unsigned) strlen(addr) + 1);
		strcpy(p, addr);
		a->q_paddr = p;
	}
E 13
I 13
		a->q_paddr = newstr(addr);
I 69
		*DelimChar = savec;
	}
E 69
E 13
	else
		a->q_paddr = addr;
I 117

	if (a->q_user == NULL)
		a->q_user = "";
	if (a->q_host == NULL)
		a->q_host = "";

E 117
I 14
D 16
	a->q_rmailer = t->p_mailer;
E 14
	a->q_mailer = &Mailer[t->p_mailer];
E 16
I 16
D 18
	a->q_mailer = a->q_rmailer = t->p_mailer;
E 18
E 16
D 64

E 64
D 13
	if (flagset(P_MOVE, t->p_flags))
E 13
I 13
D 18
	if (bitset(P_MOVE, t->p_flags))
E 18
I 18
	if (copyf >= 0)
E 18
E 13
	{
D 18
		/* send the message to another host & retry */
		a->q_host = t->p_arg;
		if (copyf >= 0)
D 13
		{
			p = xalloc((unsigned) strlen(buf) + 1);
			strcpy(p, buf);
			a->q_user = p;
		}
E 13
I 13
			a->q_user = newstr(buf);
E 18
I 18
D 117
		if (a->q_host != NULL)
			a->q_host = newstr(a->q_host);
E 18
E 13
		else
D 18
			a->q_user = buf;
E 18
I 18
			a->q_host = "";
E 117
I 117
		a->q_host = newstr(a->q_host);
E 117
		if (a->q_user != a->q_paddr)
			a->q_user = newstr(a->q_user);
E 18
	}
D 18
	else
	{
		/*
		**  Make local copies of the host & user and then
		**  transport them out.
		*/
E 18

D 18
		*q++ = '\0';
D 13
		if (flagset(P_HLAST, t->p_flags))
E 13
I 13
		if (bitset(P_HLAST, t->p_flags))
E 13
		{
			a->q_host = q;
			a->q_user = buf;
		}
		else
		{
			a->q_host = buf;
			a->q_user = q;
		}
I 5

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

D 16
		if ((pvp = a->q_mailer->m_local) != NULL)
E 16
I 16
		if ((pvp = Mailer[a->q_mailer]->m_local) != NULL)
E 16
		{
			while (*pvp != NULL)
			{
				auto char buf2[MAXNAME];

				strcpy(buf2, a->q_host);
D 13
				if (!flagset(P_HST_UPPER, t->p_flags))
E 13
I 13
				if (!bitset(P_HST_UPPER, t->p_flags))
E 13
					makelower(buf2);
				if (strcmp(*pvp++, buf2) == 0)
				{
					strcpy(buf2, a->q_user);
					p = a->q_paddr;
					if (parse(buf2, a, -1) == NULL)
					{
						To = addr;
						return (NULL);
					}
					To = a->q_paddr = p;
					break;
				}
			}
		}

I 17
		/*
		**  Do host equivalence.
		**	This allows us to map together messages that
		**	would otherwise have several copies going
		**	through the same net link.
		*/

		for (hvp = Mailer[a->q_mailer]->m_hmap; *hvp != NULL; hvp++)
		{
			register bool doremap;

			doremap = FALSE;
			for (pvp = *hvp; *pvp != NULL; pvp++)
			{
				p = *pvp;
				if (*p == '\0')
				{
					/* null string: match everything */
					doremap = TRUE;
				}
				else if (strcmp(p, a->q_host) == 0)
					doremap = TRUE;
			}

			if (doremap)
			{
				a->q_host = pvp[-1];
				a->q_user = a->q_paddr;
			}
		}

E 17
		/* make copies if specified */
E 5
		if (copyf >= 0)
		{
D 13
			p = xalloc((unsigned) strlen(a->q_host) + 1);
			strcpy(p, a->q_host);
			a->q_host = p;
			p = xalloc((unsigned) strlen(a->q_user) + 1);
			strcpy(p, a->q_user);
			a->q_user = p;
E 13
I 13
			a->q_host = newstr(a->q_host);
D 17
			a->q_user = newstr(a->q_user);
E 17
I 17
			if (a->q_user != a->q_paddr)
				a->q_user = newstr(a->q_user);
E 17
E 13
		}
	}

E 18
	/*
I 103
	**  Convert host name to lower case if requested.
	**	User name will be done later.
	*/

	if (!bitnset(M_HST_UPPER, m->m_flags))
		makelower(a->q_host);

	/*
E 103
D 102
	**  Do UPPER->lower case mapping unless inhibited.
	*/

D 13
	if (!flagset(P_HST_UPPER, t->p_flags))
E 13
I 13
D 18
	if (!bitset(P_HST_UPPER, t->p_flags))
E 18
I 18
D 91
	if (!bitset(M_HST_UPPER, m->m_flags))
E 91
I 91
	if (!bitnset(M_HST_UPPER, m->m_flags))
E 91
E 18
E 13
		makelower(a->q_host);
D 13
	if (!flagset(P_USR_UPPER, t->p_flags))
E 13
I 13
D 18
	if (!bitset(P_USR_UPPER, t->p_flags))
E 18
I 18
D 91
	if (!bitset(M_USR_UPPER, m->m_flags))
E 91
I 91
	if (!bitnset(M_USR_UPPER, m->m_flags))
E 91
E 18
E 13
		makelower(a->q_user);

	/*
E 102
	**  Compute return value.
	*/

# ifdef DEBUG
D 6
	if (Debug && copyf >= 0)
E 6
I 6
D 60
	if (Debug)
E 60
I 60
	if (tTd(20, 1))
E 60
E 6
D 40
		printf("parse(\"%s\"): host \"%s\" user \"%s\" mailer %d\n",
D 18
		    addr, a->q_host, a->q_user, t->p_mailer);
E 18
I 18
		    addr, a->q_host, a->q_user, a->q_mailer);
E 40
I 40
	{
D 86
		printf("parse-->");
E 86
I 86
		printf("parseaddr-->");
E 86
		printaddr(a, FALSE);
	}
E 40
E 18
# endif DEBUG

	return (a);
I 102
}
/*
**  LOWERADDR -- map UPPER->lower case on addresses as requested.
**
**	Parameters:
**		a -- address to be mapped.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

loweraddr(a)
	register ADDRESS *a;
{
	register MAILER *m = a->q_mailer;

D 103
	if (!bitnset(M_HST_UPPER, m->m_flags))
		makelower(a->q_host);
E 103
	if (!bitnset(M_USR_UPPER, m->m_flags))
		makelower(a->q_user);
E 102
}
/*
D 18
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
D 3
**	Requires:
**		isupper (sys)
**
E 3
**	Called By:
**		parse
D 3
**
**	History:
**		12/26/79 -- written.
E 3
*/

makelower(p)
	register char *p;
{
	register char c;

	if (p == NULL)
		return;
	for (; (c = *p) != '\0'; p++)
		if ((c & 0200) == 0 && isupper(c))
			*p = c - 'A' + 'a';
}
/*
E 18
**  PRESCAN -- Prescan name and make it canonical
**
D 83
**	Scans a name and turns it into canonical form.  This involves
**	deleting blanks, comments (in parentheses), and turning the
**	word "at" into an at-sign ("@").  The name is copied as this
**	is done; it is legal to copy a name onto itself, since this
**	process can only make things smaller.
E 83
I 83
**	Scans a name and turns it into a set of tokens.  This process
**	deletes blanks and comments (in parentheses).
E 83
**
**	This routine knows about quoted strings and angle brackets.
**
**	There are certain subtleties to this routine.  The one that
**	comes to mind now is that backslashes on the ends of names
**	are silently stripped off; this is intentional.  The problem
**	is that some versions of sndmsg (like at LBL) set the kill
**	character to something other than @ when reading addresses;
**	so people type "csvax.eric\@berkeley" -- which screws up the
**	berknet mailer.
**
**	Parameters:
**		addr -- the name to chomp.
D 18
**		buf -- the buffer to copy it into.
**		buflim -- the last usable address in the buffer
**			(which will old a null byte).  Normally
**			&buf[sizeof buf - 1].
E 18
**		delim -- the delimiter for the address, normally
**			'\0' or ','; \0 is accepted in any case.
I 100
**			If '\t' then we are reading the .cf file.
I 107
**		pvpbuf -- place to put the saved text -- note that
**			the pointers are static.
E 107
E 100
D 69
**			are moving in place; set buflim to high core.
E 69
**
**	Returns:
D 18
**		A pointer to the terminator of buf.
E 18
I 18
**		A pointer to a vector of tokens.
E 18
**		NULL on error.
**
**	Side Effects:
D 18
**		buf gets clobbered.
**
D 3
**	Requires:
**		isspace (sys)
**		any
**		usrerr
**
E 3
**	Called By:
**		parse
**		maketemp
E 18
I 18
D 119
**		none.
E 119
I 119
**		sets DelimChar to point to the character matching 'delim'.
E 119
E 18
D 3
**
**	History:
**		12/30/79 -- broken from parse; comment processing
**			added.
E 3
*/

D 18
char *
prescan(addr, buf, buflim, delim)
E 18
I 18
D 69
# define OPER		1
# define ATOM		2
# define EOTOK		3
# define QSTRING	4
# define SPACE		5
D 54
# define DOLLAR		6
E 54
I 54
# define ONEMORE	6
E 54
# define GETONE		7
I 39
# define MACRO		8
E 69
I 69
/* states and character types */
# define OPR		0	/* operator */
# define ATM		1	/* atom */
# define QST		2	/* in quoted string */
# define SPC		3	/* chewing up spaces */
# define ONE		4	/* pick up one character */
E 69
E 39

I 69
# define NSTATES	5	/* number of states */
# define TYPE		017	/* mask to select state type */

/* meta bits for table */
# define M		020	/* meta character; don't pass through */
# define B		040	/* cause a break */
# define MB		M|B	/* meta-break */

static short StateTab[NSTATES][NSTATES] =
{
D 70
   /*	oldst	newst>	OPR	ATM	QST	SPC	ONE	*/
E 70
I 70
   /*	oldst	chtype>	OPR	ATM	QST	SPC	ONE	*/
E 70
D 80
	/*OPR*/		OPR|B,	ATM|B,	QST|MB,	SPC|MB,	ONE|B,
	/*ATM*/		OPR|B,	ATM,	QST|MB,	SPC|MB,	ONE|B,
D 70
	/*QST*/		QST,	QST,	QST|MB,	QST,	QST,
E 70
I 70
	/*QST*/		QST,	QST,	OPR|MB,	QST,	QST,
E 80
I 80
	/*OPR*/		OPR|B,	ATM|B,	QST|B,	SPC|MB,	ONE|B,
	/*ATM*/		OPR|B,	ATM,	QST|B,	SPC|MB,	ONE|B,
	/*QST*/		QST,	QST,	OPR,	QST,	QST,
E 80
E 70
	/*SPC*/		OPR,	ATM,	QST,	SPC|M,	ONE,
	/*ONE*/		OPR,	OPR,	OPR,	OPR,	OPR,
};

# define NOCHAR		-1	/* signal nothing in lookahead token */

char	*DelimChar;		/* set to point to the delimiter */

E 69
char **
D 107
prescan(addr, delim)
E 107
I 107
prescan(addr, delim, pvpbuf)
E 107
E 18
	char *addr;
D 18
	char *buf;
	char *buflim;
E 18
	char delim;
I 107
	char pvpbuf[];
E 107
{
	register char *p;
I 18
D 69
	static char buf[MAXNAME+MAXATOM];
	static char *av[MAXATOM+1];
E 69
I 69
	register char *q;
D 82
	register char c;
E 82
I 82
	register int c;
E 82
E 69
	char **avp;
E 18
D 36
	bool space;
E 36
D 18
	bool quotemode;
E 18
	bool bslashmode;
I 9
D 18
	bool delimmode;
E 18
E 9
	int cmntcnt;
I 76
	int anglecnt;
E 76
D 63
	int brccnt;
E 63
D 69
	register char c;
E 69
I 18
	char *tok;
E 18
D 69
	register char *q;
D 13
	extern bool any();
E 13
I 13
D 28
	extern char *index();
E 28
I 18
	register int state;
	int nstate;
I 28
	extern char lower();
E 69
I 69
	int state;
	int newstate;
D 107
	static char buf[MAXNAME+MAXATOM];
E 107
	static char *av[MAXATOM+1];
I 99
	extern int errno;

	/* make sure error messages don't have garbage on them */
	errno = 0;
E 99
E 69
E 28
E 18
E 13

D 9
	space = TRUE;
E 9
I 9
D 36
	space = FALSE;
E 36
D 18
	delimmode = TRUE;
E 18
E 9
D 107
	q = buf;
E 107
I 107
	q = pvpbuf;
E 107
D 18
	bslashmode = quotemode = FALSE;
E 18
I 18
	bslashmode = FALSE;
E 18
D 63
	cmntcnt = brccnt = 0;
E 63
I 63
	cmntcnt = 0;
I 76
	anglecnt = 0;
E 76
E 63
D 7
	for (p = addr; (c = *p++ & 0177) != '\0'; )
E 7
I 7
D 18
	for (p = addr; (c = *p++) != '\0'; )
E 18
I 18
	avp = av;
D 69
	state = OPER;
	for (p = addr; *p != '\0' && *p != delim; )
E 69
I 69
	state = OPR;
	c = NOCHAR;
	p = addr;
# ifdef DEBUG
	if (tTd(22, 45))
E 69
E 18
E 7
	{
I 69
		printf("prescan: ");
		xputs(p);
D 115
		putchar('\n');
E 115
I 115
		(void) putchar('\n');
E 115
	}
# endif DEBUG

	do
	{
E 69
D 18
		/* chew up special characters */
		*q = '\0';
		if (bslashmode)
E 18
I 18
		/* read a token */
		tok = q;
D 69
		while ((c = *p++) != '\0' && c != delim)
E 69
I 69
		for (;;)
E 69
E 18
		{
I 69
			/* store away any old lookahead character */
			if (c != NOCHAR)
			{
D 100
				/* squirrel it away */
E 100
I 100
				/* see if there is room */
E 100
D 107
				if (q >= &buf[sizeof buf - 5])
E 107
I 107
				if (q >= &pvpbuf[PSBUFSIZE - 5])
E 107
				{
					usrerr("Address too long");
					DelimChar = p;
					return (NULL);
				}
I 100

				/* squirrel it away */
E 100
				*q++ = c;
			}

			/* read a new input character */
			c = *p++;
			if (c == '\0')
				break;
I 100
			c &= ~0200;

E 100
# ifdef DEBUG
			if (tTd(22, 101))
				printf("c=%c, s=%d; ", c, state);
# endif DEBUG

E 69
D 18
			c |= 0200;
D 7
			bslashmode == FALSE;
E 7
I 7
			bslashmode = FALSE;
E 18
I 18
			/* chew up special characters */
I 29
D 100
			c &= ~0200;
E 100
E 29
			*q = '\0';
			if (bslashmode)
			{
D 117
				c |= 0200;
E 117
I 117
				/* kludge \! for naive users */
				if (c != '!')
					c |= 0200;
E 117
				bslashmode = FALSE;
			}
			else if (c == '\\')
			{
				bslashmode = TRUE;
D 69
				continue;
E 69
I 69
				c = NOCHAR;
E 69
			}
I 77
			else if (state == QST)
			{
				/* do nothing, just avoid next clauses */
			}
E 77
I 29
D 69
			else if (c == '"')
E 69
I 69
			else if (c == '(')
E 69
			{
D 69
				if (state == QSTRING)
					state = OPER;
				else
					state = QSTRING;
				break;
E 69
I 69
				cmntcnt++;
				c = NOCHAR;
E 69
			}
E 29
D 69

D 39
			nstate = toktype(c);
E 39
I 39
D 54
			if (c == '$' && delim == '\t')
				nstate = DOLLAR;
			else
				nstate = toktype(c);
E 54
I 54
			nstate = toktype(c);
E 54
E 39
			switch (state)
E 69
I 69
			else if (c == ')')
E 69
			{
D 69
			  case QSTRING:		/* in quoted string */
D 29
				if (c == '"')
					state = OPER;
E 29
				break;

			  case ATOM:		/* regular atom */
D 33
				state = nstate;
				if (state != ATOM)
E 33
I 33
D 39
				/* state = nstate; */
E 39
				if (nstate != ATOM)
E 69
I 69
				if (cmntcnt <= 0)
E 69
E 33
				{
D 69
					state = EOTOK;
					p--;
E 69
I 69
					usrerr("Unbalanced ')'");
					DelimChar = p;
					return (NULL);
E 69
				}
D 69
				break;
E 69
I 69
				else
					cmntcnt--;
			}
			else if (cmntcnt > 0)
				c = NOCHAR;
I 76
			else if (c == '<')
				anglecnt++;
			else if (c == '>')
			{
				if (anglecnt <= 0)
				{
					usrerr("Unbalanced '>'");
					DelimChar = p;
					return (NULL);
				}
				anglecnt--;
			}
I 95
			else if (delim == ' ' && isspace(c))
				c = ' ';
E 95
E 76
I 72
			else if (c == ':' && !CurEnv->e_oldstyle)
			{
				/* consume characters until a semicolon */
				while (*p != '\0' && *p != ';')
					p++;
				if (*p == '\0')
					usrerr("Unbalanced ':...;' group spec");
				else
					p++;
				c = ' ';
			}
E 72
E 69

D 69
			  case GETONE:		/* grab one character */
				state = OPER;
				break;
E 69
I 69
			if (c == NOCHAR)
				continue;
E 69

D 69
			  case EOTOK:		/* after atom or q-string */
				state = nstate;
				if (state == SPACE)
					continue;
E 69
I 69
			/* see if this is end of input */
D 76
			if (c == delim)
E 76
I 76
D 94
			if (c == delim && anglecnt <= 0)
E 94
I 94
			if (c == delim && anglecnt <= 0 && state != QST)
E 94
E 76
E 69
				break;

D 69
			  case SPACE:		/* linear white space */
				state = nstate;
E 69
I 69
			newstate = StateTab[state][toktype(c)];
# ifdef DEBUG
			if (tTd(22, 101))
				printf("ns=%02o\n", newstate);
# endif DEBUG
			state = newstate & TYPE;
			if (bitset(M, newstate))
				c = NOCHAR;
			if (bitset(B, newstate))
E 69
D 36
				space = TRUE;
E 36
D 33
				continue;
E 33
I 33
				break;
E 33
D 69

			  case OPER:		/* operator */
				if (nstate == SPACE)
					continue;
				state = nstate;
				break;

D 54
			  case DOLLAR:		/* $- etc. */
				state = OPER;
I 42
				if (isascii(c) && isdigit(c))
				{
					/* replacement */
					c = MATCHREPL;
					state = GETONE;
					p--;
					break;
				}
E 42
				switch (c)
				{
				  case '$':		/* literal $ */
					break;

				  case '+':		/* match anything */
					c = MATCHANY;
D 42
					state = GETONE;
E 42
					break;

				  case '-':		/* match one token */
					c = MATCHONE;
D 42
					state = GETONE;
E 42
					break;

I 25
				  case '=':		/* match one token of class */
					c = MATCHCLASS;
					state = GETONE;
					break;

E 25
				  case '#':		/* canonical net name */
					c = CANONNET;
					break;

				  case '@':		/* canonical host name */
					c = CANONHOST;
					break;

				  case ':':		/* canonical user name */
					c = CANONUSER;
					break;

				  default:
D 39
					c = '$';
					state = OPER;
					p--;
E 39
I 39
					state = MACRO;
E 39
					break;
				}
E 54
I 54
			  case ONEMORE:		/* $- etc. */
				state = GETONE;
E 54
				break;

			  default:
				syserr("prescan: unknown state %d", state);
			}

D 33
			if (state == OPER)
				space = FALSE;
			else if (state == EOTOK)
E 33
I 33
			if (state == EOTOK || state == SPACE)
E 33
				break;
D 39
			if (c == '$' && delim == '\t')
			{
				state = DOLLAR;
E 39
I 39
D 54
			if (state == DOLLAR)
E 39
				continue;
E 54
D 39
			}
E 39

			/* squirrel it away */
			if (q >= &buf[sizeof buf - 5])
			{
				usrerr("Address too long");
				return (NULL);
I 39
			}
D 54
			if (state == MACRO)
			{
				char mbuf[3];

				mbuf[0] = '$';
				mbuf[1] = c;
				mbuf[2] = '\0';
				(void) expand(mbuf, q, &buf[sizeof buf - 5]);
				q += strlen(q);
				state = EOTOK;
				break;
E 39
			}
E 54
D 33
			if (space)
				*q++ = SPACESUB;
E 33
			*q++ = c;

			/* decide whether this represents end of token */
D 54
			if (state == OPER)
E 54
I 54
			if (state == OPER || state == GETONE)
E 54
				break;
E 69
E 18
E 7
		}
D 18
		else if (c == '"')
			quotemode = !quotemode;
		else if (c == '\\')
		{
			bslashmode++;
E 18
I 18
D 69
		if (c == '\0' || c == delim)
			p--;
E 69

		/* new token */
D 69
		if (tok == q)
E 18
			continue;
D 18
		}
		else if (quotemode)
			c |= 0200;
		else if (c == delim)
			break;
		else if (c == '(')
E 18
I 18
		*q++ = '\0';

		c = tok[0];
		if (c == '(')
E 69
I 69
		if (tok != q)
E 69
E 18
I 4
		{
E 4
D 69
			cmntcnt++;
I 4
			continue;
		}
E 4
		else if (c == ')')
		{
			if (cmntcnt <= 0)
E 69
I 69
			*q++ = '\0';
# ifdef DEBUG
			if (tTd(22, 36))
E 69
			{
D 69
				usrerr("Unbalanced ')'");
				return (NULL);
E 69
I 69
				printf("tok=");
				xputs(tok);
D 115
				putchar('\n');
E 115
I 115
				(void) putchar('\n');
E 115
E 69
			}
D 69
			else
E 69
I 69
# endif DEBUG
			if (avp >= &av[MAXATOM])
E 69
			{
D 69
				cmntcnt--;
				continue;
E 69
I 69
				syserr("prescan: too many tokens");
				DelimChar = p;
				return (NULL);
E 69
			}
I 69
			*avp++ = tok;
E 69
		}
I 9
D 18
		if (cmntcnt > 0)
E 18
I 18
D 69
		else if (cmntcnt > 0)
E 18
			continue;
D 18
		else if (isascii(c) && isspace(c) && (space || delimmode))
			continue;
E 9
D 4
		if (cmntcnt > 0)
			continue;
E 4
		else if (c == '<')
E 18
I 18

I 38
D 41
		if (avp >= &av[MAXATOM])
		{
			syserr("prescan: too many tokens");
			return (NULL);
		}
E 38
		*avp++ = tok;

E 41
D 63
		/* we prefer <> specs */
		if (c == '<')
E 18
		{
I 10
			if (brccnt < 0)
			{
				usrerr("multiple < spec");
				return (NULL);
			}
E 10
			brccnt++;
I 9
D 18
			delimmode = TRUE;
E 18
D 36
			space = FALSE;
E 36
E 9
			if (brccnt == 1)
			{
				/* we prefer using machine readable name */
				q = buf;
				*q = '\0';
I 18
				avp = av;
E 18
				continue;
			}
		}
		else if (c == '>')
		{
			if (brccnt <= 0)
			{
				usrerr("Unbalanced `>'");
				return (NULL);
			}
			else
				brccnt--;
			if (brccnt <= 0)
I 10
			{
				brccnt = -1;
E 10
				continue;
I 10
			}
E 10
		}
I 41

E 63
		if (avp >= &av[MAXATOM])
		{
			syserr("prescan: too many tokens");
			return (NULL);
		}
		*avp++ = tok;
E 41
D 32

		/*
		**  Turn "at" into "@",
D 4
		**	but only if "at" is a word in and to itself.
E 4
I 4
		**	but only if "at" is a word.
E 4
D 18
		**	By the way, I violate the ARPANET RFC-733
		**	standard here, by assuming that 'space' delimits
		**	atoms.  I assume that is just a mistake, since
		**	it violates the spirit of the semantics
		**	of the document.....
E 18
		*/

D 9
		if (space && (c == 'a' || c == 'A') &&
E 9
I 9
D 18
		if (delimmode && (c == 'a' || c == 'A') &&
E 9
		    (p[0] == 't' || p[0] == 'T') &&
D 9
		    (any(p[1], "()<>@,;:\\\"") || p[1] <= 040))
E 9
I 9
D 13
		    (any(p[1], DELIMCHARS) || p[1] <= 040))
E 13
I 13
		    (index(DELIMCHARS, p[1]) != NULL || p[1] <= 040))
E 18
I 18
		if (lower(tok[0]) == 'a' && lower(tok[1]) == 't' && tok[2] == '\0')
E 18
E 13
E 9
		{
D 18
			c = '@';
			p++;
E 18
I 18
			tok[0] = '@';
			tok[1] = '\0';
E 18
		}
E 32
I 18
	}
E 69
I 69
D 76
	} while (c != '\0' && c != delim);
E 76
I 76
	} while (c != '\0' && (c != delim || anglecnt > 0));
E 76
E 69
	*avp = NULL;
I 69
	DelimChar = --p;
E 69
	if (cmntcnt > 0)
		usrerr("Unbalanced '('");
I 76
	else if (anglecnt > 0)
		usrerr("Unbalanced '<'");
E 76
D 63
	else if (brccnt > 0)
		usrerr("Unbalanced '<'");
E 63
D 69
	else if (state == QSTRING)
E 69
I 69
	else if (state == QST)
E 69
		usrerr("Unbalanced '\"'");
	else if (av[0] != NULL)
		return (av);
	return (NULL);
}
/*
**  TOKTYPE -- return token type
**
**	Parameters:
**		c -- the character in question.
**
**	Returns:
**		Its type.
**
**	Side Effects:
**		none.
*/
E 18

I 9
D 13
		if (delimmode = any(c, DELIMCHARS))
E 13
I 13
D 18
		if (delimmode = (index(DELIMCHARS, c) != NULL))
E 13
			space = FALSE;
E 18
I 18
toktype(c)
	register char c;
{
I 23
	static char buf[50];
D 24
	static char firstime;
E 24
I 24
	static bool firstime = TRUE;
E 24

D 24
	if (firstime++ == 0)
E 24
I 24
	if (firstime)
E 24
	{
I 24
		firstime = FALSE;
E 24
D 28
		expand("$o", buf, &buf[sizeof buf - 1]);
E 28
I 28
D 57
		(void) expand("$o", buf, &buf[sizeof buf - 1]);
E 57
I 57
D 101
		expand("$o", buf, &buf[sizeof buf - 1], CurEnv);
E 101
I 101
		expand("\001o", buf, &buf[sizeof buf - 1], CurEnv);
E 101
E 57
E 28
D 59
		strcat(buf, DELIMCHARS);
E 59
I 59
		(void) strcat(buf, DELIMCHARS);
E 59
	}
I 54
D 84
	if (c == MATCHCLASS || c == MATCHREPL)
E 84
I 84
	if (c == MATCHCLASS || c == MATCHREPL || c == MATCHNCLASS)
E 84
D 69
		return (ONEMORE);
E 69
I 69
		return (ONE);
	if (c == '"')
		return (QST);
E 69
E 54
I 29
	if (!isascii(c))
D 69
		return (ATOM);
E 29
E 23
	if (isspace(c))
		return (SPACE);
E 69
I 69
		return (ATM);
	if (isspace(c) || c == ')')
		return (SPC);
E 69
D 23
	if (index(DELIMCHARS, c) != NULL || iscntrl(c))
E 23
I 23
	if (iscntrl(c) || index(buf, c) != NULL)
E 23
D 69
		return (OPER);
	return (ATOM);
E 69
I 69
		return (OPR);
	return (ATM);
E 69
}
/*
**  REWRITE -- apply rewrite rules to token vector.
**
I 44
**	This routine is an ordered production system.  Each rewrite
**	rule has a LHS (called the pattern) and a RHS (called the
**	rewrite); 'rwr' points the the current rewrite rule.
**
**	For each rewrite rule, 'avp' points the address vector we
**	are trying to match against, and 'pvp' points to the pattern.
D 67
**	If pvp points to a special match value (MATCHANY, MATCHONE,
**	MATCHCLASS) then the address in avp matched is saved away
**	in the match vector (pointed to by 'mvp').
E 67
I 67
**	If pvp points to a special match value (MATCHZANY, MATCHANY,
D 84
**	MATCHONE, MATCHCLASS) then the address in avp matched is
**	saved away in the match vector (pointed to by 'mvp').
E 84
I 84
**	MATCHONE, MATCHCLASS, MATCHNCLASS) then the address in avp
**	matched is saved away in the match vector (pointed to by 'mvp').
E 84
E 67
**
**	When a match between avp & pvp does not match, we try to
D 84
**	back out.  If we back up over a MATCHONE or a MATCHCLASS
E 84
I 84
**	back out.  If we back up over MATCHONE, MATCHCLASS, or MATCHNCLASS
E 84
**	we must also back out the match in mvp.  If we reach a
D 67
**	MATCHANY we just extend the match and start over again.
E 67
I 67
**	MATCHANY or MATCHZANY we just extend the match and start
**	over again.
E 67
**
**	When we finally match, we rewrite the address vector
**	and try over again.
**
E 44
**	Parameters:
**		pvp -- pointer to token vector.
**
**	Returns:
**		none.
**
**	Side Effects:
**		pvp is modified.
*/
E 18

E 9
D 10
		/* skip blanks */
D 9
		if (((c & 0200) != 0 || !isspace(c)) && cmntcnt <= 0)
E 9
I 9
		if (!isascii(c) || !isspace(c))
E 10
I 10
D 18
		/* if not a space, squirrel it away */
		if ((!isascii(c) || !isspace(c)) && brccnt >= 0)
E 18
I 18
struct match
{
D 42
	char	**firsttok;	/* first token matched */
	char	**lasttok;	/* last token matched */
	char	name;		/* name of parameter */
E 42
I 42
	char	**first;	/* first token matched */
	char	**last;		/* last token matched */
E 42
};

D 42
# define MAXMATCH	8	/* max params per rewrite */
E 42
I 42
# define MAXMATCH	9	/* max params per rewrite */
E 42


D 26
rewrite(pvp)
E 26
I 26
rewrite(pvp, ruleset)
E 26
	char **pvp;
I 26
	int ruleset;
E 26
{
	register char *ap;		/* address pointer */
	register char *rp;		/* rewrite pointer */
	register char **avp;		/* address vector pointer */
I 42
D 44
	char **avfp;			/* first word in current match */
E 44
E 42
	register char **rvp;		/* rewrite vector pointer */
D 42
	struct rewrite *rwr;
	struct match mlist[MAXMATCH];
E 42
I 42
D 67
	struct rewrite *rwr;		/* pointer to current rewrite rule */
E 67
I 67
	register struct match *mlp;	/* cur ptr into mlist */
	register struct rewrite *rwr;	/* pointer to current rewrite rule */
I 104
	int subr;			/* subroutine number if >= 0 */
	bool dolookup;			/* do host aliasing */
E 104
E 67
	struct match mlist[MAXMATCH];	/* stores match on LHS */
D 67
	struct match *mlp;		/* cur ptr into mlist */
E 67
E 42
	char *npvp[MAXATOM+1];		/* temporary space for rebuild */
I 25
D 123
	extern bool sameword();
E 123
E 25

D 20
# ifdef DEBUG
E 20
I 20
D 29
# ifdef DEBUGX
E 20
	if (Debug)
E 29
I 29
D 74
# ifdef DEBUG
D 33
	if (Debug > 10)
E 33
I 33
D 60
	if (Debug > 9)
E 60
I 60
D 68
	if (tTd(21, 9))
E 68
I 68
	if (tTd(21, 2))
E 74
I 74
D 81
	if (Mode == MD_TEST || tTd(21, 2))
E 81
I 81
	if (OpMode == MD_TEST || tTd(21, 2))
E 81
E 74
E 68
E 60
E 33
E 29
	{
D 67
		printf("rewrite: original pvp:\n");
E 67
I 67
D 68
		printf("rewrite: ruleset %d, original pvp:\n", ruleset);
E 68
I 68
D 78
		printf("rewrite: ruleset %d, original pvp:", ruleset);
E 78
I 78
		printf("rewrite: ruleset %2d   input:", ruleset);
E 78
E 68
E 67
		printav(pvp);
	}
I 76
	if (pvp == NULL)
		return;
E 76
D 20
# endif DEBUG
E 20
I 20
D 29
# endif DEBUGX
E 29
I 29
D 74
# endif DEBUG
E 74
E 29
E 20

	/*
	**  Run through the list of rewrite rules, applying
	**	any that match.
	*/

D 26
	for (rwr = RewriteRules; rwr != NULL; )
E 26
I 26
	for (rwr = RewriteRules[ruleset]; rwr != NULL; )
E 26
	{
D 20
# ifdef DEBUG
E 20
I 20
D 29
# ifdef DEBUGX
E 20
		if (Debug)
E 29
I 29
# ifdef DEBUG
D 60
		if (Debug > 10)
E 60
I 60
		if (tTd(21, 12))
E 60
E 29
E 18
E 10
E 9
		{
D 9
			if (q >= buflim)
E 9
I 9
D 18
			if (q >= buflim-1)
E 18
I 18
D 68
			printf("-----trying rule:\n");
E 68
I 68
			printf("-----trying rule:");
E 68
			printav(rwr->r_lhs);
		}
D 20
# endif DEBUG
E 20
I 20
D 29
# endif DEBUGX
E 29
I 29
# endif DEBUG
E 29
E 20

		/* try to match on this rule */
D 42
		clrmatch(mlist);
		for (rvp = rwr->r_lhs, avp = pvp; *avp != NULL; )
E 42
I 42
		mlp = mlist;
D 44
		for (rvp = rwr->r_lhs, avfp = avp = pvp; *avp != NULL; )
E 44
I 44
D 67
		for (rvp = rwr->r_lhs, avp = pvp; *avp != NULL; )
E 67
I 67
		rvp = rwr->r_lhs;
		avp = pvp;
		while ((ap = *avp) != NULL || *rvp != NULL)
E 67
E 44
E 42
		{
D 67
			ap = *avp;
E 67
			rp = *rvp;
D 67

E 67
I 67
# ifdef DEBUG
			if (tTd(21, 35))
			{
D 68
				printf("ap=\"");
E 68
I 68
				printf("ap=");
E 68
				xputs(ap);
D 68
				printf("\", rp=\"");
E 68
I 68
				printf(", rp=");
E 68
				xputs(rp);
D 68
				printf("\"\n");
E 68
I 68
				printf("\n");
E 68
			}
# endif DEBUG
E 67
			if (rp == NULL)
E 18
E 9
			{
D 18
				usrerr("Address too long");
				return (NULL);
E 18
I 18
				/* end-of-pattern before end-of-address */
D 67
				goto fail;
E 67
I 67
				goto backup;
E 67
E 18
			}
I 67
			if (ap == NULL && *rp != MATCHZANY)
			{
				/* end-of-input */
				break;
			}
E 67
I 9
D 18
			if (space)
				*q++ = SPACESUB;
E 9
			*q++ = c;
E 18
I 18

			switch (*rp)
			{
I 25
				register STAB *s;
D 91
				register int class;
E 91

E 25
D 44
			  case MATCHONE:
				/* match exactly one token */
D 42
				setmatch(mlist, rp[1], avp, avp);
E 42
I 42
				mlp->first = mlp->last = avp++;
				mlp++;
				avfp = avp;
E 42
				break;

			  case MATCHANY:
				/* match any number of tokens */
D 28
				setmatch(mlist, rp[1], NULL, avp);
E 28
I 28
D 42
				setmatch(mlist, rp[1], (char **) NULL, avp);
E 42
I 42
				mlp->first = avfp;
				mlp->last = avp++;
				mlp++;
E 42
E 28
				break;

E 44
I 25
			  case MATCHCLASS:
D 84
				/* match any token in a class */
E 84
I 84
			  case MATCHNCLASS:
				/* match any token in (not in) a class */
E 84
D 91
				class = rp[1];
				if (!isalpha(class))
D 67
					goto fail;
E 67
I 67
					goto backup;
E 67
				if (isupper(class))
					class -= 'A';
				else
					class -= 'a';
E 91
D 29
				s = stab(ap, ST_FIND);
E 29
I 29
				s = stab(ap, ST_CLASS, ST_FIND);
E 29
D 55
				if (s == NULL || (s->s_class & (1 << class)) == 0)
E 55
I 55
D 91
				if (s == NULL || (s->s_class & (1L << class)) == 0)
E 91
I 91
				if (s == NULL || !bitnset(rp[1], s->s_class))
E 91
I 84
				{
					if (*rp == MATCHCLASS)
						goto backup;
				}
				else if (*rp == MATCHNCLASS)
E 84
E 55
D 67
					goto fail;
E 67
I 67
					goto backup;
E 67
I 42

D 44
				/* mark match */
E 44
I 44
				/* explicit fall-through */

			  case MATCHONE:
			  case MATCHANY:
				/* match exactly one token */
E 44
D 67
				mlp->first = mlp->last = avp++;
E 67
I 67
				mlp->first = avp;
				mlp->last = avp++;
E 67
				mlp++;
D 44
				avfp = avp;
E 44
E 42
				break;

I 67
			  case MATCHZANY:
				/* match zero or more tokens */
				mlp->first = avp;
				mlp->last = avp - 1;
				mlp++;
				break;

E 67
E 25
			  default:
				/* must have exact match */
D 25
				/* can scribble rp & ap here safely */
D 19
				while (*rp != '\0' && *ap != '\0')
E 19
I 19
				while (*rp != '\0' || *ap != '\0')
E 19
				{
					if (*rp++ != lower(*ap++))
						goto fail;
				}
E 25
I 25
D 123
				if (!sameword(rp, ap))
E 123
I 123
				if (strcasecmp(rp, ap))
E 123
D 67
					goto fail;
E 67
I 67
					goto backup;
E 67
I 42
				avp++;
D 44
				avfp = avp;
E 44
E 42
E 25
				break;
			}

			/* successful match on this token */
D 42
			avp++;
E 42
			rvp++;
			continue;

D 67
		  fail:
E 67
I 67
		  backup:
E 67
			/* match failed -- back up */
			while (--rvp >= rwr->r_lhs)
			{
				rp = *rvp;
D 67
				if (*rp == MATCHANY)
E 67
I 67
				if (*rp == MATCHANY || *rp == MATCHZANY)
E 67
I 42
				{
D 44
					avfp = mlp->first;
E 44
I 44
					/* extend binding and continue */
D 67
					mlp[-1].last = avp++;
E 67
I 67
					avp = ++mlp[-1].last;
					avp++;
E 67
					rvp++;
E 44
E 42
					break;
D 42

				/* can't extend match: back up everything */
				avp--;

				if (*rp == MATCHONE)
E 42
I 42
				}
D 44
				else if (*rp == MATCHONE || *rp == MATCHCLASS)
E 44
I 44
				avp--;
D 84
				if (*rp == MATCHONE || *rp == MATCHCLASS)
E 84
I 84
				if (*rp == MATCHONE || *rp == MATCHCLASS ||
				    *rp == MATCHNCLASS)
E 84
E 44
E 42
				{
D 42
					/* undo binding */
D 28
					setmatch(mlist, rp[1], NULL, NULL);
E 28
I 28
					setmatch(mlist, rp[1], (char **) NULL, (char **) NULL);
E 42
I 42
					/* back out binding */
D 44
					avp--;
					avfp = avp;
E 44
					mlp--;
E 42
E 28
				}
			}

			if (rvp < rwr->r_lhs)
			{
				/* total failure to match */
				break;
			}
E 18
		}
D 11
		space = isspace(c);
E 11
I 11
D 18
		space = isascii(c) && isspace(c);
E 18
I 18

		/*
		**  See if we successfully matched
		*/

D 83
		if (rvp >= rwr->r_lhs && *rvp == NULL)
E 83
I 83
		if (rvp < rwr->r_lhs || *rvp != NULL)
E 83
		{
I 67
D 83
			rvp = rwr->r_rhs;
E 83
E 67
D 20
# ifdef DEBUG
E 20
I 20
D 29
# ifdef DEBUGX
E 20
			if (Debug)
E 29
I 29
# ifdef DEBUG
D 60
			if (Debug > 10)
E 60
I 60
D 83
			if (tTd(21, 12))
E 60
E 29
			{
D 68
				printf("-----rule matches:\n");
E 68
I 68
				printf("-----rule matches:");
E 68
D 67
				printav(rwr->r_rhs);
E 67
I 67
				printav(rvp);
E 67
			}
E 83
I 83
			if (tTd(21, 10))
				printf("----- rule fails\n");
E 83
D 20
# endif DEBUG
E 20
I 20
D 29
# endif DEBUGX
E 29
I 29
# endif DEBUG
I 83
			rwr = rwr->r_next;
			continue;
		}
E 83
E 29
E 20

I 83
		rvp = rwr->r_rhs;
# ifdef DEBUG
		if (tTd(21, 12))
		{
			printf("-----rule matches:");
			printav(rvp);
		}
# endif DEBUG

		rp = *rvp;
		if (*rp == CANONUSER)
		{
			rvp++;
			rwr = rwr->r_next;
		}
		else if (*rp == CANONHOST)
		{
			rvp++;
			rwr = NULL;
		}
		else if (*rp == CANONNET)
			rwr = NULL;

		/* substitute */
I 104
		dolookup = FALSE;
E 104
		for (avp = npvp; *rvp != NULL; rvp++)
		{
			register struct match *m;
			register char **pp;

E 83
I 67
D 73
			/* see if this is a "subroutine" call */
E 73
			rp = *rvp;
I 104

			/* check to see if we should do a lookup */
			if (*rp == MATCHLOOKUP)
				dolookup = TRUE;

			/* see if there is substitution here */
E 104
D 73
			if (*rp == CALLSUBR)
E 73
I 73
D 83
			if (*rp == CANONUSER)
E 83
I 83
D 107
			if (*rp != MATCHREPL)
E 107
I 107
			if (*rp == MATCHREPL)
E 107
E 83
E 73
			{
D 73
				rp = *++rvp;
# ifdef DEBUG
D 68
				if (tTd(21, 2))
E 68
I 68
				if (tTd(21, 3))
E 68
					printf("-----callsubr %s\n", rp);
# endif DEBUG
				rewrite(pvp, atoi(rp));
				rwr = rwr->r_next;
				continue;
			}
I 68
			else if (*rp == CANONUSER)
			{
E 73
D 83
				rvp++;
				rwr = rwr->r_next;
E 83
I 83
D 107
				if (avp >= &npvp[MAXATOM])
E 107
I 107
				/* substitute from LHS */
				m = &mlist[rp[1] - '1'];
				if (m >= mlp)
E 107
				{
I 104
				  toolong:
E 104
D 107
					syserr("rewrite: expansion too long");
E 107
I 107
					syserr("rewrite: ruleset %d: replacement out of bounds", ruleset);
E 107
					return;
				}
D 107
				*avp++ = rp;
				continue;
E 83
			}
D 83
			else if (*rp == CANONHOST)
			{
				rvp++;
				rwr = NULL;
			}
			else if (*rp == CANONNET)
				rwr = NULL;
E 83
E 68

E 67
D 83
			/* substitute */
D 68
			for (rvp = rwr->r_rhs, avp = npvp; *rvp != NULL; rvp++)
E 68
I 68
			for (avp = npvp; *rvp != NULL; rvp++)
E 83
I 83
			/* substitute from LHS */
			m = &mlist[rp[1] - '1'];
I 105
			if (m >= mlp)
			{
				syserr("rewrite: ruleset %d: replacement out of bounds", ruleset);
				return;
			}
E 107
E 105
# ifdef DEBUG
D 107
			if (tTd(21, 15))
E 83
E 68
			{
D 83
				rp = *rvp;
D 42
				if (*rp == MATCHANY)
E 42
I 42
				if (*rp == MATCHREPL)
E 83
I 83
				printf("$%c:", rp[1]);
E 107
I 107
				if (tTd(21, 15))
				{
					printf("$%c:", rp[1]);
					pp = m->first;
					while (pp <= m->last)
					{
						printf(" %x=\"", *pp);
						(void) fflush(stdout);
						printf("%s\"", *pp++);
					}
					printf("\n");
				}
# endif DEBUG
E 107
				pp = m->first;
				while (pp <= m->last)
E 83
E 42
				{
D 83
					register struct match *m;
					register char **pp;
D 42
					extern struct match *findmatch();
E 42

D 42
					m = findmatch(mlist, rp[1]);
					if (m != NULL)
E 42
I 42
					m = &mlist[rp[1] - '1'];
I 44
# ifdef DEBUG
D 60
					if (Debug > 13)
E 60
I 60
					if (tTd(21, 15))
E 60
					{
						printf("$%c:", rp[1]);
						pp = m->first;
D 67
						do
E 67
I 67
						while (pp <= m->last)
E 67
						{
							printf(" %x=\"", *pp);
D 46
							fflush(stdout);
E 46
I 46
							(void) fflush(stdout);
E 46
D 67
							printf("%s\"", *pp);
						} while (pp++ != m->last);
E 67
I 67
							printf("%s\"", *pp++);
						}
E 67
						printf("\n");
					}
# endif DEBUG
E 44
					pp = m->first;
D 67
					do
E 67
I 67
					while (pp <= m->last)
E 67
E 42
					{
D 42
						pp = m->firsttok;
						do
E 42
I 42
						if (avp >= &npvp[MAXATOM])
E 42
						{
I 38
D 42
							if (avp >= &npvp[MAXATOM])
							{
								syserr("rewrite: expansion too long");
								return;
							}
E 38
							*avp++ = *pp;
						} while (pp++ != m->lasttok);
					}
E 42
I 42
							syserr("rewrite: expansion too long");
							return;
						}
D 67
						*avp++ = *pp;
					} while (pp++ != m->last);
E 67
I 67
						*avp++ = *pp++;
					}
E 83
I 83
D 107
					printf(" %x=\"", *pp);
					(void) fflush(stdout);
					printf("%s\"", *pp++);
E 107
I 107
					if (avp >= &npvp[MAXATOM])
					{
						syserr("rewrite: expansion too long");
						return;
					}
					*avp++ = *pp++;
E 107
E 83
E 67
E 42
				}
D 83
				else
I 38
				{
					if (avp >= &npvp[MAXATOM])
					{
						syserr("rewrite: expansion too long");
						return;
					}
E 38
					*avp++ = rp;
I 38
				}
E 83
I 83
D 107
				printf("\n");
E 107
E 83
E 38
			}
D 83
			*avp++ = NULL;
D 28
			bmove(npvp, pvp, (avp - npvp) * sizeof *avp);
E 28
I 28
D 73
			bmove((char *) npvp, (char *) pvp, (avp - npvp) * sizeof *avp);
E 73
I 73
			if (**npvp == CALLSUBR)
			{
				bmove((char *) &npvp[2], (char *) pvp,
					(avp - npvp - 2) * sizeof *avp);
# ifdef DEBUG
				if (tTd(21, 3))
					printf("-----callsubr %s\n", npvp[1]);
E 83
D 107
# endif DEBUG
D 83
				rewrite(pvp, atoi(npvp[1]));
			}
			else
E 83
I 83
			pp = m->first;
			while (pp <= m->last)
E 107
I 107
			else
E 107
E 83
			{
I 107
				/* vanilla replacement */
E 107
D 83
				bmove((char *) npvp, (char *) pvp,
					(avp - npvp) * sizeof *avp);
E 83
I 83
				if (avp >= &npvp[MAXATOM])
D 104
				{
I 107
	toolong:
E 107
					syserr("rewrite: expansion too long");
					return;
				}
E 104
I 104
					goto toolong;
E 104
D 107
				*avp++ = *pp++;
E 107
I 107
				*avp++ = rp;
E 107
E 83
			}
I 83
		}
		*avp++ = NULL;
I 107

		/*
		**  Check for any hostname lookups.
		*/

		for (rvp = npvp; *rvp != NULL; rvp++)
		{
			char **hbrvp;
			char **xpvp;
			int trsize;
D 114
			int i;
E 114
I 112
			char *olddelimchar;
E 112
D 108
			char buf[MAXATOM + 1];
E 108
I 108
			char buf[MAXNAME + 1];
E 108
			char *pvpb1[MAXATOM + 1];
D 109
			static char pvpbuf[PSBUFSIZE];
E 109
I 109
			char pvpbuf[PSBUFSIZE];
I 112
			extern char *DelimChar;
E 112
E 109

			if (**rvp != HOSTBEGIN)
				continue;

			/*
			**  Got a hostname lookup.
			**
			**	This could be optimized fairly easily.
			*/

			hbrvp = rvp;

			/* extract the match part */
			while (*++rvp != NULL && **rvp != HOSTEND)
				continue;
			if (*rvp != NULL)
				*rvp++ = NULL;

			/* save the remainder of the input string */
			trsize = (int) (avp - rvp + 1) * sizeof *rvp;
			bcopy((char *) rvp, (char *) pvpb1, trsize);

			/* look it up */
			cataddr(++hbrvp, buf, sizeof buf);
			maphostname(buf, sizeof buf);

			/* scan the new host name */
I 112
			olddelimchar = DelimChar;
E 112
			xpvp = prescan(buf, '\0', pvpbuf);
I 112
			DelimChar = olddelimchar;
E 112
			if (xpvp == NULL)
			{
				syserr("rewrite: cannot prescan canonical hostname: %s", buf);
D 114
				return (NULL);
E 114
I 114
				return;
E 114
			}

			/* append it to the token list */
D 108
			rvp = --hbrvp;
			while ((*rvp++ = *xpvp++) != NULL)
				if (rvp >= &npvp[MAXATOM])
E 108
I 108
D 109
			avp = --hbrvp;
			while ((*avp++ = *xpvp++) != NULL)
E 109
I 109
			for (avp = --hbrvp; *xpvp != NULL; xpvp++)
			{
				*avp++ = newstr(*xpvp);
E 109
				if (avp >= &npvp[MAXATOM])
E 108
					goto toolong;
I 109
			}
E 109

			/* restore the old trailing information */
D 108
			for (xpvp = pvpb1, rvp--; (*rvp++ = *xpvp++) != NULL; )
				if (rvp >= &npvp[MAXATOM])
E 108
I 108
D 110
			for (xpvp = pvpb1, avp--; (*avp++ = *xpvp++) != NULL; )
E 110
I 110
			for (xpvp = pvpb1; (*avp++ = *xpvp++) != NULL; )
E 110
				if (avp >= &npvp[MAXATOM])
E 108
					goto toolong;
I 109

			break;
E 109
		}

		/*
		**  Check for subroutine calls.
		*/

E 107
D 104
D 117
		if (**npvp == CALLSUBR)
E 117
I 117
		if (*npvp != NULL && **npvp == CALLSUBR)
E 117
E 104
I 104

		/*
		**  Do hostname lookup if requested.
		*/

		if (dolookup)
E 104
		{
D 104
D 105
			bmove((char *) &npvp[2], (char *) pvp,
E 105
I 105
			bcopy((char *) &npvp[2], (char *) pvp,
E 105
D 106
				(avp - npvp - 2) * sizeof *avp);
E 106
I 106
				(int) (avp - npvp - 2) * sizeof *avp);
E 106
E 83
E 73
E 28
# ifdef DEBUG
D 33
			if (Debug)
E 33
I 33
D 60
			if (Debug > 3)
E 60
I 60
D 83
			if (tTd(21, 4))
E 60
E 33
			{
D 20
				printf("rewritten as:\n");
				printav(pvp);
E 20
I 20
D 68
				char **vp;

				printf("rewritten as `");
				for (vp = pvp; *vp != NULL; vp++)
I 33
				{
					if (vp != pvp)
						printf("_");
E 33
					xputs(*vp);
I 33
				}
E 33
				printf("'\n");
E 68
I 68
				printf("rewritten as:");
				printav(pvp);
E 68
E 20
			}
E 83
I 83
			if (tTd(21, 3))
				printf("-----callsubr %s\n", npvp[1]);
E 83
# endif DEBUG
I 83
			rewrite(pvp, atoi(npvp[1]));
E 104
I 104
			extern char **maphost();

			rvp = maphost(npvp);
E 104
E 83
D 66
			if (pvp[0][0] == CANONNET)
E 66
I 66
D 68
			if (**pvp == CANONNET || **pvp == CANONUSER)
E 66
				break;
E 68
		}
		else
I 104
			rvp = npvp;

		/*
		**  See if this is a subroutine call.
		*/

		if (**rvp == CALLSUBR)
E 104
		{
I 83
D 104
D 105
			bmove((char *) npvp, (char *) pvp,
E 105
I 105
D 107
			bcopy((char *) npvp, (char *) pvp,
E 107
I 107
D 111
			bmove((char *) npvp, (char *) pvp,
E 111
I 111
			bcopy((char *) npvp, (char *) pvp,
E 111
E 107
E 105
D 106
				(avp - npvp) * sizeof *avp);
E 106
I 106
				(int) (avp - npvp) * sizeof *avp);
E 106
E 104
I 104
			subr = atoi(*++rvp);
			rvp++;
E 104
		}
I 104
		else
			subr = -1;

		/*
		**  Copy result back to original string.
		*/

		for (avp = pvp; *rvp != NULL; rvp++)
			*avp++ = *rvp;
		*avp = NULL;

		/*
		**  If this specified a subroutine, call it.
		*/

		if (subr >= 0)
		{
# ifdef DEBUG
			if (tTd(21, 3))
				printf("-----callsubr %s\n", subr);
# endif DEBUG
			rewrite(pvp, subr);
		}

		/*
		**  Done with rewriting this pass.
		*/

E 104
E 83
D 20
# ifdef DEBUG
E 20
I 20
D 29
# ifdef DEBUGX
E 20
			if (Debug)
E 29
I 29
# ifdef DEBUG
D 60
			if (Debug > 10)
E 60
I 60
D 83
			if (tTd(21, 10))
E 60
E 29
				printf("----- rule fails\n");
D 20
# endif DEBUG
E 20
I 20
D 29
# endif DEBUGX
E 29
I 29
# endif DEBUG
E 29
E 20
			rwr = rwr->r_next;
E 83
I 83
		if (tTd(21, 4))
		{
			printf("rewritten as:");
			printav(pvp);
E 83
		}
I 83
# endif DEBUG
E 83
E 18
E 11
	}
I 68

D 74
# ifdef DEBUG
	if (tTd(21, 2))
E 74
I 74
D 81
	if (Mode == MD_TEST || tTd(21, 2))
E 81
I 81
	if (OpMode == MD_TEST || tTd(21, 2))
E 81
E 74
	{
D 78
		printf("rewrite: ruleset %d returns:", ruleset);
E 78
I 78
		printf("rewrite: ruleset %2d returns:", ruleset);
E 78
		printav(pvp);
	}
D 74
# endif DEBUG
E 74
E 68
D 18
	*q = '\0';
	if (c == '\0')
		p--;
	if (cmntcnt > 0)
		usrerr("Unbalanced '('");
	else if (quotemode)
		usrerr("Unbalanced '\"'");
	else if (brccnt > 0)
		usrerr("Unbalanced '<'");
	else if (buf[0] != '\0')
		return (p);
E 18
I 18
D 42
}
/*
**  SETMATCH -- set parameter value in match vector
**
**	Parameters:
**		mlist -- list of match values.
**		name -- the character name of this parameter.
**		first -- the first location of the replacement.
**		last -- the last location of the replacement.
**
**		If last == NULL, delete this entry.
**		If first == NULL, extend this entry (or add it if
**			it does not exist).
**
**	Returns:
**		nothing.
**
**	Side Effects:
**		munges with mlist.
*/

setmatch(mlist, name, first, last)
	struct match *mlist;
	char name;
	char **first;
	char **last;
{
	register struct match *m;
	struct match *nullm = NULL;

	for (m = mlist; m < &mlist[MAXMATCH]; m++)
	{
		if (m->name == name)
			break;
		if (m->name == '\0')
			nullm = m;
	}

	if (m >= &mlist[MAXMATCH])
		m = nullm;

	if (last == NULL)
	{
		m->name = '\0';
		return;
	}

	if (m->name == '\0')
	{
		if (first == NULL)
			m->firsttok = last;
		else
			m->firsttok = first;
	}
	m->name = name;
	m->lasttok = last;
}
/*
**  FINDMATCH -- find match in mlist
**
**	Parameters:
**		mlist -- list to search.
**		name -- name to find.
**
**	Returns:
**		pointer to match structure.
**		NULL if no match.
**
**	Side Effects:
**		none.
*/

struct match *
findmatch(mlist, name)
	struct match *mlist;
	char name;
{
	register struct match *m;

	for (m = mlist; m < &mlist[MAXMATCH]; m++)
	{
		if (m->name == name)
			return (m);
	}

E 18
	return (NULL);
I 18
}
/*
**  CLRMATCH -- clear match list
**
**	Parameters:
**		mlist -- list to clear.
**
**	Returns:
**		none.
**
**	Side Effects:
**		mlist is cleared.
*/

clrmatch(mlist)
	struct match *mlist;
{
	register struct match *m;

	for (m = mlist; m < &mlist[MAXMATCH]; m++)
		m->name = '\0';
E 42
}
/*
**  BUILDADDR -- build address from token vector.
**
**	Parameters:
**		tv -- token vector.
**		a -- pointer to address descriptor to fill.
**			If NULL, one will be allocated.
**
**	Returns:
D 35
**		'a'
E 35
I 35
**		NULL if there was an error.
**		'a' otherwise.
E 35
**
**	Side Effects:
**		fills in 'a'
*/

ADDRESS *
buildaddr(tv, a)
	register char **tv;
	register ADDRESS *a;
{
D 46
	register int i;
E 46
	static char buf[MAXNAME];
	struct mailer **mp;
	register struct mailer *m;
I 47
D 123
	extern bool sameword();
E 123
E 47
D 28
	extern char *xalloc();
E 28

	if (a == NULL)
		a = (ADDRESS *) xalloc(sizeof *a);
I 20
D 48
D 49
	a->q_flags = 0;
I 27
	a->q_home = NULL;
E 49
I 49
D 105
	clear((char *) a, sizeof *a);
E 105
I 105
	bzero((char *) a, sizeof *a);
E 105
E 49
E 48
I 48
	clear((char *) a, sizeof *a);
E 48
E 27
E 20

	/* figure out what net/mailer to use */
	if (**tv != CANONNET)
I 35
	{
E 35
		syserr("buildaddr: no net");
I 35
		return (NULL);
	}
E 35
	tv++;
I 35
D 47
	if (strcmp(*tv, "error") == 0)
E 47
I 47
D 123
	if (sameword(*tv, "error"))
E 123
I 123
	if (!strcasecmp(*tv, "error"))
E 123
E 47
	{
D 89
		if (**++tv != CANONUSER)
E 89
I 89
		if (**++tv == CANONHOST)
		{
			setstat(atoi(*++tv));
			tv++;
		}
		if (**tv != CANONUSER)
E 89
			syserr("buildaddr: error: no user");
		buf[0] = '\0';
		while (*++tv != NULL)
		{
			if (buf[0] != '\0')
D 59
				strcat(buf, " ");
			strcat(buf, *tv);
E 59
I 59
				(void) strcat(buf, " ");
			(void) strcat(buf, *tv);
E 59
		}
		usrerr(buf);
		return (NULL);
	}
E 35
D 19
	for (mp = Mailer, i = 0; (m = *mp) != NULL; m++, i++)
E 19
I 19
D 45
	for (mp = Mailer, i = 0; (m = *mp++) != NULL; i++)
E 45
I 45
	for (mp = Mailer; (m = *mp++) != NULL; )
E 45
E 19
	{
D 47
		if (strcmp(m->m_name, *tv) == 0)
E 47
I 47
D 123
		if (sameword(m->m_name, *tv))
E 123
I 123
		if (!strcasecmp(m->m_name, *tv))
E 123
E 47
			break;
	}
	if (m == NULL)
I 35
	{
E 35
D 117
		syserr("buildaddr: unknown net %s", *tv);
E 117
I 117
		syserr("buildaddr: unknown mailer %s", *tv);
E 117
I 35
		return (NULL);
	}
E 35
D 45
	a->q_mailer = i;
E 45
I 45
	a->q_mailer = m;
E 45

	/* figure out what host (if any) */
	tv++;
D 31
	if (!bitset(M_NOHOST, m->m_flags))
E 31
I 31
D 91
	if (!bitset(M_LOCAL, m->m_flags))
E 91
I 91
	if (!bitnset(M_LOCAL, m->m_flags))
E 91
E 31
	{
D 53
		if (**tv != CANONHOST)
E 53
I 53
		if (**tv++ != CANONHOST)
E 53
I 35
		{
E 35
			syserr("buildaddr: no host");
I 35
			return (NULL);
		}
E 35
D 53
		tv++;
		a->q_host = *tv;
		tv++;
E 53
I 53
		buf[0] = '\0';
		while (*tv != NULL && **tv != CANONUSER)
D 59
			strcat(buf, *tv++);
E 59
I 59
			(void) strcat(buf, *tv++);
E 59
		a->q_host = newstr(buf);
E 53
	}
	else
		a->q_host = NULL;

	/* figure out the user */
	if (**tv != CANONUSER)
I 35
	{
E 35
		syserr("buildaddr: no user");
I 35
		return (NULL);
	}
E 35
D 33
	buf[0] = '\0';
	while (**++tv != NULL)
D 28
		strcat(buf, *tv);
E 28
I 28
		(void) strcat(buf, *tv);
E 33
I 33
D 93
	cataddr(++tv, buf, sizeof buf);
E 93
I 93
D 113
	rewrite(++tv, 4);
E 113
I 113

	/* rewrite according recipient mailer rewriting rules */
	rewrite(++tv, 2);
	if (m->m_r_rwset > 0)
		rewrite(tv, m->m_r_rwset);
	rewrite(tv, 4);

	/* save the result for the command line/RCPT argument */
E 113
	cataddr(tv, buf, sizeof buf);
E 93
E 33
E 28
	a->q_user = buf;

	return (a);
I 33
}
/*
**  CATADDR -- concatenate pieces of addresses (putting in <LWSP> subs)
**
**	Parameters:
**		pvp -- parameter vector to rebuild.
**		buf -- buffer to build the string into.
**		sz -- size of buf.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Destroys buf.
*/

cataddr(pvp, buf, sz)
	char **pvp;
	char *buf;
	register int sz;
{
	bool oatomtok = FALSE;
	bool natomtok = FALSE;
	register int i;
	register char *p;

I 76
	if (pvp == NULL)
	{
D 115
		strcpy(buf, "");
E 115
I 115
		(void) strcpy(buf, "");
E 115
		return;
	}
E 76
	p = buf;
D 92
	sz--;
E 92
I 92
	sz -= 2;
E 92
I 66
D 68
	if (*pvp != NULL && **pvp == CANONUSER)
		pvp++;
E 68
E 66
	while (*pvp != NULL && (i = strlen(*pvp)) < sz)
	{
D 69
		natomtok = (toktype(**pvp) == ATOM);
E 69
I 69
		natomtok = (toktype(**pvp) == ATM);
E 69
		if (oatomtok && natomtok)
D 79
			*p++ = SPACESUB;
E 79
I 79
			*p++ = SpaceSub;
E 79
		(void) strcpy(p, *pvp);
		oatomtok = natomtok;
		p += i;
D 92
		sz -= i;
E 92
I 92
		sz -= i + 1;
E 92
		pvp++;
	}
	*p = '\0';
E 33
I 20
}
/*
**  SAMEADDR -- Determine if two addresses are the same
**
**	This is not just a straight comparison -- if the mailer doesn't
**	care about the host we just ignore it, etc.
**
**	Parameters:
**		a, b -- pointers to the internal forms to compare.
D 83
**		wildflg -- if TRUE, 'a' may have no user specified,
**			in which case it is to match anything.
E 83
**
**	Returns:
**		TRUE -- they represent the same mailbox.
**		FALSE -- they don't.
**
**	Side Effects:
**		none.
*/

bool
D 83
sameaddr(a, b, wildflg)
E 83
I 83
sameaddr(a, b)
E 83
	register ADDRESS *a;
	register ADDRESS *b;
D 83
	bool wildflg;
E 83
{
	/* if they don't have the same mailer, forget it */
	if (a->q_mailer != b->q_mailer)
		return (FALSE);

	/* if the user isn't the same, we can drop out */
D 83
	if ((!wildflg || a->q_user[0] != '\0') && strcmp(a->q_user, b->q_user) != 0)
E 83
I 83
	if (strcmp(a->q_user, b->q_user) != 0)
E 83
		return (FALSE);

I 120
D 122
	/* if receiving uid's don't match, these are "different" */
D 121
	if (a->q_uid != b->q_uid || a->q_gid != b->q_gid)
E 121
I 121
	if (bitset(QGOODUID, a->q_flags) && bitset(QGOODUID, b->q_flags) &&
	    (a->q_uid != b->q_uid || a->q_gid != b->q_gid))
E 121
		return (FALSE);

E 122
E 120
	/* if the mailer ignores hosts, we have succeeded! */
D 31
	if (bitset(M_NOHOST, Mailer[a->q_mailer]->m_flags))
E 31
I 31
D 45
	if (bitset(M_LOCAL, Mailer[a->q_mailer]->m_flags))
E 45
I 45
D 91
	if (bitset(M_LOCAL, a->q_mailer->m_flags))
E 91
I 91
	if (bitnset(M_LOCAL, a->q_mailer->m_flags))
E 91
E 45
E 31
		return (TRUE);

	/* otherwise compare hosts (but be careful for NULL ptrs) */
	if (a->q_host == NULL || b->q_host == NULL)
		return (FALSE);
	if (strcmp(a->q_host, b->q_host) != 0)
		return (FALSE);

	return (TRUE);
E 20
E 18
}
I 21
/*
**  PRINTADDR -- print address (for debugging)
**
**	Parameters:
**		a -- the address to print
**		follow -- follow the q_next chain.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

I 36
# ifdef DEBUG

E 36
printaddr(a, follow)
	register ADDRESS *a;
	bool follow;
{
I 50
	bool first = TRUE;

E 50
I 48
	static int indent;
	register int i;

E 48
	while (a != NULL)
	{
I 50
		first = FALSE;
E 50
I 48
		for (i = indent; i > 0; i--)
			printf("\t");
E 48
D 40
		printf("addr@%x: ", a);
E 40
I 40
		printf("%x=", a);
E 40
D 28
		fflush(stdout);
E 28
I 28
		(void) fflush(stdout);
E 28
		printf("%s: mailer %d (%s), host `%s', user `%s'\n", a->q_paddr,
D 45
		       a->q_mailer, Mailer[a->q_mailer]->m_name, a->q_host, a->q_user);
E 45
I 45
D 71
		       a->q_mailer->m_mno, a->q_mailer->m_name, a->q_host, a->q_user);
E 45
D 40
		printf("\tnext=%x flags=%o, rmailer %d\n", a->q_next,
E 40
I 40
D 48
D 51
		printf("\tnext=%x, flags=%o, rmailer %d\n", a->q_next,
E 40
		       a->q_flags, a->q_rmailer);
E 51
I 51
		printf("\tnext=%x, flags=%o, rmailer %d, alias %x\n", a->q_next,
		       a->q_flags, a->q_rmailer, a->q_alias);
E 51
I 50
		printf("\thome=\"%s\", fullname=\"%s\"\n", a->q_home, a->q_fullname);
E 71
I 71
		       a->q_mailer->m_mno, a->q_mailer->m_name, a->q_host,
		       a->q_user);
		printf("\tnext=%x, flags=%o, alias %x\n", a->q_next, a->q_flags,
		       a->q_alias);
		printf("\thome=\"%s\", fullname=\"%s\"\n", a->q_home,
		       a->q_fullname);
E 71
E 50

E 48
I 48
		for (i = indent; i > 0; i--)
			printf("\t");
		printf("\tnext=%x, flags=%o, rmailer %d, alias=%x, sibling=%x, child=%x\n",
		       a->q_next, a->q_flags, a->q_rmailer, a->q_alias,
		       a->q_sibling, a->q_child);
		
		/* follow the chain if appropriate */
E 48
		if (!follow)
			return;
D 48
		a = a->q_next;
E 48
I 48
		
		indent++;
		printaddr(a->q_child, TRUE);
		indent--;
		a = a->q_sibling;
E 48
	}
I 40
D 50
	if (!follow)
E 50
I 50
	if (first)
E 50
		printf("[NULL]\n");
E 40
}
I 36

# endif DEBUG
I 61
/*
**  REMOTENAME -- return the name relative to the current mailer
**
**	Parameters:
**		name -- the name to translate.
D 68
**		force -- if set, forces rewriting even if the mailer
**			does not request it.  Used for rewriting
**			sender addresses.
E 68
I 68
**		m -- the mailer that we want to do rewriting relative
**			to.
**		senderaddress -- if set, uses the sender rewriting rules
**			rather than the recipient rewriting rules.
I 90
**		canonical -- if set, strip out any comment information,
**			etc.
E 90
E 68
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
D 68
remotename(name, m, force)
E 68
I 68
D 90
remotename(name, m, senderaddress)
E 90
I 90
remotename(name, m, senderaddress, canonical)
E 90
E 68
	char *name;
	struct mailer *m;
D 68
	bool force;
E 68
I 68
	bool senderaddress;
I 90
	bool canonical;
E 90
E 68
{
D 68
	static char buf[MAXNAME];
	char lbuf[MAXNAME];
E 68
I 68
	register char **pvp;
	char *fancy;
I 100
D 114
	register char *p;
E 114
E 100
E 68
	extern char *macvalue();
D 68
	char *oldf = macvalue('f');
E 68
D 64
	char *oldx = macvalue('x');
E 64
D 71
	char *oldg = macvalue('g');
E 71
I 71
	char *oldg = macvalue('g', CurEnv);
E 71
I 68
	static char buf[MAXNAME];
	char lbuf[MAXNAME];
I 107
	char pvpbuf[PSBUFSIZE];
E 107
E 68
	extern char **prescan();
D 68
	register char **pvp;
D 64
	extern char *getxpart();
E 64
	extern ADDRESS *buildaddr();
E 68
I 64
	extern char *crackaddr();
D 68
	char *fancy;
E 68
E 64

I 62
# ifdef DEBUG
	if (tTd(12, 1))
		printf("remotename(%s)\n", name);
# endif DEBUG

I 88
	/* don't do anything if we are tagging it as special */
	if ((senderaddress ? m->m_s_rwset : m->m_r_rwset) < 0)
		return (name);

E 88
E 62
	/*
D 64
	**  See if this mailer wants the name to be rewritten.  There are
	**  many problems here, owing to the standards for doing replies.
	**  In general, these names should only be rewritten if we are
	**  sending to another host that runs sendmail.
E 64
I 64
D 71
	**  First put this address into canonical form.
	**	First turn it into a macro.
D 68
	**	Then run it through ruleset 4.
E 68
I 68
	**	Then run it through ruleset 1 or 2, depending on whether
	**		it is a sender or a recipient address.
E 68
I 67
	**	If the mailer defines a rewriting set, run it through
	**		there next.
E 71
I 71
	**  Do a heuristic crack of this name to extract any comment info.
	**	This will leave the name as a comment and a $g macro.
E 71
D 68
	**	The intent is that ruleset 4 puts the name into a
	**		canonical form; the mailer's ruleset then
	**		does any customization.
E 68
E 67
E 64
	*/

D 64
	if (!bitset(M_RELRCPT, m->m_flags) && !force)
I 62
	{
# ifdef DEBUG
		if (tTd(12, 1))
			printf("remotename [ditto]\n");
# endif DEBUG
E 64
I 64
D 71
	/* save away the extraneous pretty stuff */
E 71
D 90
	fancy = crackaddr(name);
E 90
I 90
	if (canonical)
D 101
		fancy = "$g";
E 101
I 101
		fancy = "\001g";
E 101
	else
		fancy = crackaddr(name);
E 90

D 71
	/* now run through ruleset four */
E 71
I 71
	/*
	**  Turn the name into canonical form.
	**	Normally this will be RFC 822 style, i.e., "user@domain".
	**	If this only resolves to "user", and the "C" flag is
	**	specified in the sending mailer, then the sender's
	**	domain will be appended.
	*/

E 71
D 107
	pvp = prescan(name, '\0');
E 107
I 107
	pvp = prescan(name, '\0', pvpbuf);
E 107
	if (pvp == NULL)
E 64
E 62
		return (name);
I 71
	rewrite(pvp, 3);
	if (CurEnv->e_fromdomain != NULL)
	{
		/* append from domain to this address */
		register char **pxp = pvp;

I 85
		/* see if there is an "@domain" in the current name */
E 85
		while (*pxp != NULL && strcmp(*pxp, "@") != 0)
			pxp++;
		if (*pxp == NULL)
		{
I 85
			/* no.... append the "@domain" from the sender */
E 85
			register char **qxq = CurEnv->e_fromdomain;

D 85
			while (*qxq != NULL)
				*pxp++ = *qxq++;
E 85
I 85
			while ((*pxp++ = *qxq++) != NULL)
				continue;
I 97
			rewrite(pvp, 3);
E 97
E 85
		}
	}

	/*
D 78
	**  Now do more specific rewriting.
E 78
I 78
	**  Do more specific rewriting.
E 78
	**	Rewrite using ruleset 1 or 2 depending on whether this is
	**		a sender address or not.
	**	Then run it through any receiving-mailer-specific rulesets.
	*/

E 71
I 62
D 64
	}
E 64
I 64
D 68
	rewrite(pvp, 4);
I 67
	if (m->m_rwset > 0)
		rewrite(pvp, m->m_rwset);
E 67
E 64
E 62

	/*
D 64
	**  Do general rewriting of name.
	**	This will also take care of doing global name translation.
E 64
I 64
	**  See if this mailer wants the name to be rewritten.  There are
	**  many problems here, owing to the standards for doing replies.
	**  In general, these names should only be rewritten if we are
	**  sending to another host that runs sendmail.
E 64
	*/

D 64
	define('x', getxpart(name));
	pvp = prescan(name, '\0');
	if (pvp == NULL)
		return (name);
	rewrite(pvp, 1);
	rewrite(pvp, 3);
	if (**pvp == CANONNET)
E 64
I 64
	if (bitset(M_RELRCPT, m->m_flags) && !force)
E 68
I 68
	if (senderaddress)
E 68
E 64
	{
D 64
		/* oops... resolved to something */
		return (name);
	}
	cataddr(pvp, lbuf, sizeof lbuf);
E 64
I 64
D 68
		/*
		**  Do general rewriting of name.
		**	This will also take care of doing global name
		**	translation.
		*/
E 64

E 68
D 64
	/* make the name relative to the receiving mailer */
	define('f', lbuf);
	expand(m->m_from, buf, &buf[sizeof buf - 1], CurEnv);
E 64
I 64
		rewrite(pvp, 1);
D 68
		rewrite(pvp, 3);
E 64

D 64
	/* rewrite to get rid of garbage we added in the expand above */
	pvp = prescan(buf, '\0');
	if (pvp == NULL)
		return (name);
	rewrite(pvp, 2);
	cataddr(pvp, lbuf, sizeof lbuf);
E 64
I 64
		/* make the name relative to the receiving mailer */
		cataddr(pvp, lbuf, sizeof lbuf);
		define('f', lbuf);
		expand(m->m_from, buf, &buf[sizeof buf - 1], CurEnv);
E 64

I 64
		/* rewrite to get rid of garbage we added in the expand above */
		pvp = prescan(buf, '\0');
		if (pvp == NULL)
			return (name);
E 68
I 68
		if (m->m_s_rwset > 0)
			rewrite(pvp, m->m_s_rwset);
	}
	else
	{
E 68
		rewrite(pvp, 2);
I 68
		if (m->m_r_rwset > 0)
			rewrite(pvp, m->m_r_rwset);
E 68
	}
I 78

	/*
	**  Do any final sanitation the address may require.
	**	This will normally be used to turn internal forms
	**	(e.g., user@host.LOCAL) into external form.  This
	**	may be used as a default to the above rules.
	*/

	rewrite(pvp, 4);
E 78

E 64
D 71
	/* now add any comment info we had before back */
E 71
I 71
	/*
	**  Now restore the comment information we had at the beginning.
I 100
D 101
	**	Make sure that any real '$' characters in the input are
	**	not accidently interpreted as macro expansions by quoting
	**	them before expansion.
E 101
E 100
	*/

E 71
I 64
	cataddr(pvp, lbuf, sizeof lbuf);
I 100
D 101
	for (p = lbuf; *p != '\0'; p++)
		if (*p == '$')
			*p |= 0200;
E 101
E 100
E 64
D 83
	define('g', lbuf);
E 83
I 83
	define('g', lbuf, CurEnv);
E 83
D 64
	expand("$q", buf, &buf[sizeof buf - 1], CurEnv);
E 64
I 64
	expand(fancy, buf, &buf[sizeof buf - 1], CurEnv);
E 64
D 68

	define('f', oldf);
E 68
D 83
	define('g', oldg);
E 83
I 83
	define('g', oldg, CurEnv);
I 100
D 101
	stripquotes(buf, FALSE);
E 101
E 100
E 83
D 64
	define('x', oldx);
E 64

# ifdef DEBUG
	if (tTd(12, 1))
D 62
		printf("remotename(%s) => `%s'\n", name, buf);
E 62
I 62
		printf("remotename => `%s'\n", buf);
E 62
# endif DEBUG
	return (buf);
D 90
}
/*
**  CANONNAME -- make name canonical
**
**	This is used for SMTP and misc. printing.  Given a print
D 71
**	address, it strips out comments, etc., and puts on exactly
**	one set of brackets.
E 71
I 71
**	address, it strips out comments, etc.
E 71
**
**	Parameters:
**		name -- the name to make canonical.
I 75
**		ruleset -- the canonicalizing ruleset.
E 75
**
**	Returns:
**		pointer to canonical name.
**
**	Side Effects:
**		none.
**
**	Warning:
**		result is saved in static buf; future calls will trash it.
*/

char *
D 75
canonname(name)
E 75
I 75
canonname(name, ruleset)
E 75
	char *name;
I 75
	int ruleset;
E 75
{
D 68
	static char nbuf[MAXNAME + 2];
E 68
I 68
	static char nbuf[MAXNAME];
E 68
I 65
	register char **pvp;
E 65

D 65
	if (name[0] == '<')
		return (name);
	strcpy(nbuf, "<");
	strcat(nbuf, name);
E 65
I 65
	pvp = prescan(name, '\0');
D 68
	rewrite(pvp, 4);
	cataddr(pvp, nbuf + 1, MAXNAME);
	nbuf[0] = '<';
E 65
	strcat(nbuf, ">");
E 68
I 68
	rewrite(pvp, 3);
I 75
	rewrite(pvp, ruleset);
I 87
	rewrite(pvp, 4);
E 87
E 75
	cataddr(pvp, nbuf, sizeof nbuf);
E 68
	return (nbuf);
E 90
}
E 61
E 36
E 21
E 1
