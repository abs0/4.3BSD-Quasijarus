h51076
s 00000/00000/00023
d D 5.61.1.6 07/09/20 02:56:07 msokolov 490 489
c change to oversize handling strategy:
c trim at limit and silently discard the rest instead of error in mid-message
e
s 00000/00000/00023
d D 5.61.1.5 06/05/20 19:25:43 msokolov 489 488
c alias options for uid/gid and restricted access
e
s 00000/00000/00023
d D 5.61.1.4 06/03/31 17:33:10 msokolov 488 487
c generate 4-digit years (RFC 1123)
e
s 00000/00000/00023
d D 5.61.1.3 04/11/21 08:43:03 msokolov 487 486
c added options to globally limit message size in collect phase and to
c disallow Internet relaying
e
s 00000/00000/00023
d D 5.61.1.2 02/05/29 22:17:11 msokolov 486 485
c minor Y2K fix
c fix handling of null from addresses
c Log source IP addresses of everything coming from Internet (daemon mode).
c This feature will help catch Sendmail abusers while not suspending any
c Sendmail civil liberties.
e
s 00000/00000/00023
d D 5.61.1.1 99/10/01 18:43:01 msokolov 485 484
c started Quasijarus Sendmail
e
s 00000/00000/00023
d D 5.61 88/09/20 22:15:19 eric 484 483
c add I option to insist on Internet domain server; add NAMED_BIND
c compile option to compile in named routines.
e
s 00011/00009/00012
d D 5.60 88/06/30 15:00:04 bostic 483 482
c install approved copyright notice
e
s 00016/00010/00005
d D 5.59 88/03/13 19:53:40 bostic 482 481
c add Berkeley specific header
e
s 00000/00000/00015
d D 5.58 87/02/03 20:44:04 eric 481 479
c pass sending hostname correctly back via the $s macro (broken sometime
c earlier); hack around some name server changes
e
s 00000/00000/00015
d D 5.57.1.1 86/12/17 16:08:34 eric 480 479
c hack around compiler bug that gets confused on isascii
e
s 00000/00000/00015
d D 5.57 86/10/23 10:11:10 eric 479 478
c Fix security bug allowing writing to arbitrary files; from Bart Miller
c at U. Wisconsin.
e
s 00000/00000/00015
d D 5.56 86/10/14 18:06:05 eric 478 477
c don't let "locked job" messages remove transcript & lock
e
s 00000/00000/00015
d D 5.55 86/10/14 17:21:15 eric 477 476
c make sure that 0, 1, and 2 are open to avoid confusing syslog;
c from Steve Schoch <schoch@orion.arpa>
e
s 00000/00000/00015
d D 5.54 86/07/21 12:21:11 bloom 476 475
c add MX support
e
s 00000/00000/00015
d D 5.53 86/06/30 16:20:56 bloom 475 474
c try multiple addresses in SMTP connect
e
s 00000/00000/00015
d D 5.52 86/05/06 18:04:16 bloom 474 473
c Fix problem with not closing sockets upon errors when opening connections
e
s 00000/00000/00015
d D 5.51 86/05/02 16:28:28 bloom 473 472
c statistics structure moved to its own header file so it may be used by 
c aux/mailstats
e
s 00000/00000/00015
d D 5.50 86/04/17 20:18:12 eric 472 471
c don't ignore aliasing during queue runs in conjunction with -bd
e
s 00000/00000/00015
d D 5.49 86/04/02 16:02:31 eric 471 470
c don't run around clearing EF_FATALERRS -- this often applies to another
c address.  Drop uid/gid check in sameaddr -- it causes more problems
c than it fixes.
e
s 00000/00000/00015
d D 5.48 86/03/08 14:12:07 eric 470 469
c improve debugging in queue routines; don't output error addresses that
c are duplicates or otherwise marked as "don't send"
e
s 00000/00000/00015
d D 5.47 86/03/08 09:28:15 eric 469 468
c do dbminit in a reasonable place
e
s 00000/00000/00015
d D 5.46 86/03/02 14:07:11 eric 468 467
c always ignore SIGCHLD in openmailer; get SccsId correct in alias.c
e
s 00000/00000/00015
d D 5.45 86/01/30 11:02:58 eric 467 466
c fix .forward files that include yourself; this was a bug in sameaddr
c that may have caused some other problems
e
s 00000/00000/00015
d D 5.44 86/01/11 00:18:27 eric 466 465
c only check the RHS of aliases during newalias if the "n" option is set;
c this option should probably be set if you are not running the nameserver
e
s 00000/00000/00015
d D 5.43 86/01/10 16:34:08 eric 465 464
c adjust WkTimeFact so that -q1h will lower relative priorities of
c jobs over long periods, rather than leave them toward the top of the queue
e
s 00000/00000/00015
d D 5.42 86/01/10 15:49:40 eric 464 463
c allow multiple words per line in file classes; require a SCANF compilation
c flag to use sscanf in F specs in order to reduce image size
e
s 00000/00000/00015
d D 5.41 86/01/09 15:19:09 eric 463 462
c apparently European timezones were wrong; thanks to Piet Beertema
c <mcvax!piet@seismo.CSS.GOV> for this one
e
s 00000/00000/00015
d D 5.40 86/01/09 14:38:45 eric 462 461
c allow underscores in login names
e
s 00000/00000/00015
d D 5.39 86/01/05 18:49:01 eric 461 460
c rewrite reply-to and resent-reply-to; save errorqueueu in qf file;
c some performance hacking; some alias handling cleanup; delete leading
c spaces from SMTP lines
e
s 00000/00000/00015
d D 5.38 85/12/17 23:54:45 eric 460 459
c lint
e
s 00000/00000/00015
d D 5.37 85/12/17 21:35:28 eric 459 458
c patch to clearenvelope to avoid dereferencing garbage pointers
e
s 00000/00000/00015
d D 5.36 85/12/09 10:29:07 miriam 458 457
c Modify maphostname to do a gethostbyaddr if first character in name 
c is a bracket.
e
s 00000/00000/00015
d D 5.35 85/12/07 08:17:56 eric 457 456
c several small bugs: don't die if no environment, don't look in
c ESM_DEADLETTER state in savemail; lowercase before getpwnam to
c allow upper case regular names in alias file
e
s 00000/00000/00015
d D 5.34 85/11/22 11:38:09 miriam 456 455
c Distinguish between temporary failure types.  Now will print the 
c message "Host Name Lookup Failure" when h_errno contains TRY_AGAIN error value.
e
s 00000/00000/00015
d D 5.33 85/11/22 08:27:48 eric 455 454
c give error if alias file cannot be opened; log a message when aliases
c are rebuilt; consider addresses with different q_uid's different so
c that two recipients forwarding to the same program will work
e
s 00000/00000/00015
d D 5.32 85/11/21 18:49:02 eric 454 453
c don't duplicate original envelope into error envelope
e
s 00000/00000/00015
d D 5.31 85/10/24 10:38:28 eric 453 452
c don't create a queue name in syserr; permit trailing blanks and quoted
c commas in aliases.
e
s 00000/00000/00015
d D 5.30 85/10/19 09:55:01 eric 452 451
c strip spaces from ends of alias addresses so that blanks at end of line works
e
s 00000/00000/00015
d D 5.29 85/10/13 15:03:36 eric 451 450
c fix botch with reapchild getting queue runs before intended wait
e
s 00000/00000/00015
d D 5.28 85/09/30 21:34:39 eric 450 449
c clean up some aspects of error message display
e
s 00000/00000/00015
d D 5.27 85/09/30 21:06:04 eric 449 448
c fixes in setproctitle to avoid problems with titles longer than
c argv + env
e
s 00000/00000/00015
d D 5.26 85/09/25 11:02:19 eric 448 447
c DO use Ruleset 4 when defining $f -- it's very necessary (fix for <>
c will have to be done in configuration); pretty up mailq -v slightly
e
s 00000/00000/00015
d D 5.25 85/09/24 15:49:04 eric 447 446
c clean up queue output somewhat (push null jobs to end); set
c SO_REUSEADDR and SO_KEEPALIVE on daemon sockets in the hopes of making
c dead connections disappear faster
e
s 00000/00000/00015
d D 5.24 85/09/24 15:09:56 eric 446 445
c don't step on user environment
e
s 00000/00000/00015
d D 5.23 85/09/23 21:19:05 eric 445 444
c deliver directly in SMTP if VERB command has been issued; don't
c externalize name using ruleset 4 when defining $f macro: this turns "<>"
c into "", which confuses local mail
e
s 00000/00000/00015
d D 5.22 85/09/21 16:35:33 eric 444 443
c yet more cleanup to the process title code
e
s 00000/00000/00015
d D 5.21 85/09/21 16:24:06 eric 443 442
c don't include ctime as part of priority, since the value affects the results of
c shouldqueue; we go back to adding ctime into the workcmpf in queue.c
e
s 00000/00000/00015
d D 5.20 85/09/21 15:52:02 eric 442 441
c change sign on WkTimeFact so that is closer to what most people want
e
s 00000/00000/00015
d D 5.19 85/09/21 15:01:31 eric 441 440
c fix silly botch in SMTP command decoding
e
s 00000/00000/00015
d D 5.18 85/09/21 14:45:53 eric 440 439
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00000/00000/00015
d D 5.17 85/09/21 10:31:27 eric 439 438
c add -v mode to mailq to print priorities as well (this should be extended
c in the future); fix some problems in the savemail state machine.
e
s 00000/00000/00015
d D 5.16 85/09/20 09:43:20 eric 438 437
c print cute labels on programs communicating with SMTP
e
s 00000/00000/00015
d D 5.15 85/09/19 23:16:24 eric 437 436
c label child processes more effectively
e
s 00000/00000/00015
d D 5.14 85/09/19 22:01:02 eric 436 435
c use rename instead of link/unlink
e
s 00000/00000/00015
d D 5.13 85/09/19 17:43:16 eric 435 434
c fix botch in clearenvelope
e
s 00000/00000/00015
d D 5.12 85/09/19 15:57:48 eric 434 433
c updates to make it possible to run the queue in one process; this
c permits a database of host status to be built
e
s 00000/00000/00015
d D 5.11 85/09/19 13:41:13 eric 433 432
c lint
e
s 00000/00000/00015
d D 5.10 85/09/19 01:25:45 eric 432 431
c incorporate SMI changes -- still experimental
e
s 00000/00000/00015
d D 5.9 85/09/17 21:46:27 eric 431 430
c use SIGCHLD to catch processes as suggested by Serge Granik
e
s 00000/00000/00015
d D 5.8 85/09/17 19:24:39 eric 430 429
c facilities in syslog
e
s 00000/00000/00015
d D 5.7 85/09/03 20:08:54 eric 429 428
c increase MAXNAME and MAXLINE, as requested by Rick Adams, via
c George Goble, via Kirk Smith, via Miriam Amos (why????)
e
s 00000/00000/00015
d D 5.6 85/09/03 19:50:17 eric 428 427
c Wander WIZ from weariful DEBUG to wonderful WIZ woption
e
s 00000/00000/00015
d D 5.5 85/06/17 18:53:09 eric 427 426
c From Bill Nowicki: fixes to the statistics
e
s 00000/00000/00015
d D 5.4 85/06/16 16:04:51 eric 426 425
c arrange for a useful error message if the mailer fork fails
e
s 00000/00000/00015
d D 5.3 85/06/15 18:52:11 eric 425 424
c fix overzealous removal of df file
e
s 00000/00000/00015
d D 5.2 85/06/08 10:30:59 eric 424 423
c lint for 4.3 release
e
s 00013/00003/00002
d D 5.1 85/06/07 15:19:18 dist 423 422
c Add copyright
e
s 00000/00000/00005
d D 4.56 85/06/02 10:54:52 eric 422 421
c plug another security hole with command line arguments
e
s 00000/00000/00005
d D 4.55 85/06/01 15:26:40 eric 421 420
c More changes from Bill Nowicki -- file closing and improved logging.
e
s 00000/00000/00005
d D 4.54 85/05/24 11:00:43 eric 420 419
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00000/00000/00005
d D 4.53 85/05/15 20:26:44 eric 419 418
c reenable signals in an event that may be called to run the queue; this
c allows hung connections to time out properly during a queue run.  This
c fix provided by Bill Nowicki.
e
s 00000/00000/00005
d D 4.52 85/05/06 20:06:04 eric 418 417
c check syscall return values in a few questions; thanks go to Ian Darwin's
c rudely public ragging on this one.
e
s 00000/00000/00005
d D 4.51 85/04/29 22:48:37 eric 417 416
c lock alias file while rebuilding if flock system call available
e
s 00000/00000/00005
d D 4.50 85/04/28 10:46:11 eric 416 415
c stop collecting message on ferror(InChannel); changes to compile even
c if DEBUG isn't defined; avoid sending nonstandard 050 messages unless
c requested; recover from trashed DBM files; use recipient rewriting set
c on user part after ruleset 0 completes
e
s 00000/00000/00005
d D 4.49 85/04/25 20:06:08 miriam 415 414
c Remove lib/libsys.a references - not used anymore.
e
s 00000/00000/00005
d D 4.48 85/04/20 15:14:15 eric 414 413
c don't assume that all apparently local senders have passwd entries
e
s 00000/00000/00005
d D 4.47 85/04/04 17:48:45 miriam 413 412
c Change serverity of LOG_ERR to LOG_MAIL so syslog will place in 
c appropriate log file.
e
s 00000/00000/00005
d D 4.46 85/02/15 09:28:10 eric 412 411
c fix some bugs with -C flag; one with queuing from Teus
e
s 00000/00000/00005
d D 4.45 85/02/14 22:43:42 eric 411 410
c "and" file mode bits with 0777
e
s 00000/00000/00005
d D 4.44 84/12/06 10:35:01 eric 410 409
c back out attempt to use flock in the queue -- we don't in gerneral have
c an open file descriptor available.
e
s 00000/00000/00005
d D 4.43 84/12/05 23:16:18 eric 409 408
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00000/00000/00005
d D 4.42 84/11/13 12:46:05 eric 408 407
c assorted optimizations (no functional changes)
e
s 00000/00000/00005
d D 4.41 84/09/18 19:53:05 eric 407 406
c fix multiline aliases
e
s 00000/00000/00005
d D 4.40 84/09/08 17:44:21 eric 406 405
c fix hostname mapping to be repeatable (as required by some .cf files).
e
s 00000/00000/00005
d D 4.39 84/08/11 23:19:30 eric 405 404
c Add $[ and $] as RHS operators to look up the contents and pass them
c to maphostname; maphostname currently looks them up in /etc/hosts and
c converts them to canonical form, but could be turned into a general
c name server.....   huzzah!!
e
s 00000/00000/00005
d D 4.38 84/08/11 17:56:24 eric 404 403
c changes from Tom Ferrin <ucsfcgl!tef>: don't drop messages on the floor
c if no local mailer available; give real "errno" message in syserr.
e
s 00000/00000/00005
d D 4.37 84/08/11 17:50:27 eric 403 402
c Assorted changes from Guy Harris <rlgvax!guy>: mostly lint & USG
e
s 00000/00000/00005
d D 4.36 84/08/11 16:57:17 eric 402 401
c don't add ".ARPA" (or whatever net name) to names that already have
c a dot in them; pull NetName out of initialized data space so that
c it can be changed in frozen configuration files
e
s 00000/00000/00005
d D 4.35 84/08/11 16:54:59 eric 401 400
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00000/00000/00005
d D 4.34 84/08/11 14:38:46 eric 400 399
c fixes from Liudvikas Bukys <bukys@rochester.ARPA>:
c allow -M flag to be used more than once;
c handle hosts where "gethostname" does not return the canonical name.
e
s 00000/00000/00005
d D 4.33 84/08/11 13:23:32 eric 399 398
c add E mailer flag to > escape From lines (for files)
e
s 00000/00000/00005
d D 4.32 84/08/05 11:01:18 eric 398 397
c add B option to set blank substitution character
e
s 00000/00000/00005
d D 4.31 84/08/05 10:14:14 eric 397 396
c alway reset uid and gid immediately if alternate config file
e
s 00000/00000/00005
d D 4.30 84/05/13 15:45:35 eric 396 395
c remove .mailcf hack -- it's been abused.
e
s 00000/00000/00005
d D 4.29 84/05/13 14:03:01 eric 395 394
c change "returnto" to "returnq" for PDP-11 compilers
e
s 00000/00000/00005
d D 4.28 84/03/17 16:26:58 eric 394 393
c always fold case on host names; fold case on the LHS of aliases
e
s 00000/00000/00005
d D 4.27 84/03/11 21:21:31 eric 393 392
c fix argument to gethostname left over from some old interface....
e
s 00000/00000/00005
d D 4.26 84/03/11 19:58:20 eric 392 391
c disable UPPER->lower case mapping in RHS's of aliases so that upper
c case letters can be used in file names and as args to programs.
e
s 00000/00000/00005
d D 4.25 84/03/11 16:49:25 eric 391 390
c changes from Bill Nowicki <nowicki@diablo.ARPA> to avoid sending
c errors if a connection is aborted;
c changes from Greg Katz <katz@sri-tsc> to help with PDP-11 versions;
c allow home network name to be changed;
c change macro expansion character from $ to \001 so that $'s can be
c used in headers (.cf unchanged).
e
s 00000/00000/00005
d D 4.24 83/12/27 22:52:50 eric 390 389
c don't close files immediately before exec of mailer so that we can log;
c use FIOCLEX instead.  Suggested by Tom Ferrin, UCSF CGL.
e
s 00000/00000/00005
d D 4.23 83/12/27 21:21:47 eric 389 388
c fix bug with un-DBM'ed alias files that adds a newline on the end of
c the last entry in the alias; found by John Gilmore, SMI
e
s 00000/00000/00005
d D 4.22 83/11/26 18:52:55 eric 388 387
c fix SERIOUS bug allowing anyone to be "wiz" without a password
c if the configuration was frozen
e
s 00000/00000/00005
d D 4.21 83/11/13 18:08:19 eric 387 386
c Fixes two nasty problems, both pointed out by Bill Nowicki at Stanford:
c I/O errors on input in collect would cause infinite loops, and a protocol
c error (or other error that would call smtpquit abnormally) would cause
c core dumps
e
s 00000/00000/00005
d D 4.20 83/11/10 09:05:46 eric 386 385
c Be able to override the hostname in the configuration file when frozen
e
s 00000/00000/00005
d D 4.19 83/10/29 16:46:12 eric 385 384
c declare getpwnam in recipient.c for earlier systems
e
s 00000/00000/00005
d D 4.18 83/10/29 12:01:44 eric 384 383
c add newline to "deferred" message in usersmtp.c
e
s 00000/00000/00005
d D 4.17 83/10/23 17:16:56 eric 383 382
c handle dollar signs in headers properly
e
s 00000/00000/00005
d D 4.16 83/10/16 16:08:08 eric 382 381
c Postpone opening the alias DBM file until after the fork in srvrsmtp so
c that the alias database is as current as possible; thanks to dagobah!efo
c (Eben Ostby) for this one.
e
s 00000/00000/00005
d D 4.15 83/10/16 15:26:12 eric 381 380
c reset errno in parseaddr so that syserr gives a permanent error code and
c no extraneous information about non-errors
e
s 00000/00000/00005
d D 4.14 83/10/02 15:31:56 eric 380 379
c Use old environment after the thaw; credit rhc for this.
e
s 00000/00000/00005
d D 4.13 83/10/01 16:57:57 eric 379 378
c clean up error handling in general; make sure that something gets logged
c in the transcript if the connection cannot be established; clean up Teus
c Hagen's mod to arpadate.c to match the sendmail coding style.
e
s 00000/00000/00005
d D 4.12 83/09/07 09:45:41 eric 378 377
c Increase timeout for greeting message to five minutes; remember to close
c the connection properly if we get a failure during connection establishment.
e
s 00000/00000/00005
d D 4.11 83/09/05 15:02:48 eric 377 376
c Fix security hole caused by being able to freeze the configuration
c without owning the .fc file.
e
s 00000/00000/00005
d D 4.10 83/09/05 14:33:54 eric 376 375
c Cut down the amount of bulk that is sent in SMTP error messages, by
c trying to log only real errors in the transcript.  -v mode is unchanged.
e
s 00000/00000/00005
d D 4.9 83/08/31 17:42:50 eric 375 374
c fix problem with timeouts caused by change in EINTR semantics in 4.2bsd;
c add a two minute timeout on the greeting message in user smtp to detect
c hung connections
e
s 00000/00000/00005
d D 4.8 83/08/28 15:38:15 eric 374 373
c set FIOCLEX on /dev/kmem file when getting load average
e
s 00000/00000/00005
d D 4.7 83/08/28 14:45:35 eric 373 372
c Refuse to talk to yourself (i.e., reject HELO packets with your own name).
c Add two thresholds -- option 'x' is the load average at which messages are
c queued rather than delivered (default 12); option 'X' is the load average
c at which incoming TCP connections are refused (default 25).
e
s 00000/00000/00005
d D 4.6 83/08/21 15:40:13 eric 372 371
c Drop "Sender:" hack, since it doesn't work properly when relaying messages.
e
s 00000/00000/00005
d D 4.5 83/08/21 15:15:09 eric 371 370
c Insert a Sender: line if a From: line is specified and is different than
c what we would insert; don't send back a separate error message if we have
c diagnosed an error in a RCPT command; fix a *0 problem in some debug code.
e
s 00000/00000/00005
d D 4.4 83/08/06 10:37:57 eric 370 369
c Clear errno before trying connect in an attempt to track down EPERM
c problems.
e
s 00000/00000/00005
d D 4.3 83/07/31 10:46:22 eric 369 368
c Add EX_NOPERM to sysexits.h for kre
e
s 00000/00000/00005
d D 4.2 83/07/27 22:56:44 eric 368 367
c Don't uppercase hostname in myhostname so that it can be used as a
c UUCP name.
e
s 00000/00000/00005
d D 4.1 83/07/25 19:46:27 eric 367 366
c 4.2 release version
e
s 00000/00000/00005
d D 3.347 83/07/13 10:38:17 eric 366 365
c Delete "load limiting" for SMTP connections (a bad ethernet board can
c hang up all incoming mail); use sfgets in collect (same reason); check
c for I/O error in collect (from Bill Nowicki); switch date format to
c RFC822 style.
e
s 00000/00000/00005
d D 3.346 83/06/14 11:05:18 eric 365 364
c log the message-id only if non-null
e
s 00000/00000/00005
d D 3.345 83/06/11 20:59:30 eric 364 363
c %d => %ld in mailq for PDP-11's
e
s 00000/00000/00005
d D 3.344 83/06/11 19:28:58 eric 363 362
m 045
m 240
c don't rearrange input header lines; force Received: lines to be at the
c beginning by always adding new header fields at the end of the header.
e
s 00000/00000/00005
d D 3.343 83/05/21 11:01:51 eric 362 361
c Miscellaneous changes for PDP-11's.
c Always send to a login name before a full name.
e
s 00000/00000/00005
d D 3.342 83/05/20 11:50:16 eric 361 360
m 238
m 239
c Don't stack processes when VRFY fails.
c Give an error message on multiple RCPT commands with a bad address.
e
s 00000/00000/00005
d D 3.341 83/05/18 11:57:09 eric 360 359
c Change WKTIMEFACT to be negative to force failing jobs to the end of the
c queue rather than to the beginning, giving better overall performance --
c as noted by Jay Lepreau.  Also, clean up the format of the mailq output.
e
s 00000/00000/00005
d D 3.340 83/05/07 11:28:37 eric 359 358
m 237
c Pass the size of the buffer to myhostname.
e
s 00000/00000/00005
d D 3.339 83/05/04 11:29:53 eric 358 357
m 235
c fix botch in 3.338 -- arguments reversed
e
s 00000/00000/00005
d D 3.338 83/05/04 11:16:29 eric 357 356
m 235
c Don't send domain-based UUCP addresses to UGLYUUCP hosts
e
s 00000/00000/00005
d D 3.337 83/05/01 14:27:55 eric 356 355
m 234
c avoid core dumps on messages with very long header fields
e
s 00000/00000/00005
d D 3.336 83/04/30 15:14:51 eric 355 354
c lint
e
s 00000/00000/00005
d D 3.335 83/04/23 12:54:57 eric 354 353
m 230
c Don't put Resent-*: lines in queue file to prevent outputing them
c inappropriately in the sent message.
e
s 00000/00000/00005
d D 3.334 83/04/19 19:20:44 eric 353 352
m 228
c Fix bug causing convtime to loop forever on "w" (week) specification.
e
s 00000/00000/00005
d D 3.333 83/04/17 17:19:04 eric 352 351
m 199
m 218
m 221
m 224
c put true current time on SMTP greeting message; drop >From hack (this belongs
c in the mailer if needed); fix bogus errno problems (clear errno in many
c places); fix *(0) problems
e
s 00000/00000/00005
d D 3.332 83/03/26 14:26:43 eric 351 350
m 213
m 214
m 215
c increase buffer size in smtpmessage to avoid overflows; rewrite again with
c ruleset three after appending from domain so that we can add the bracket
c punctuation; changes from MRH for USG UNIX 5.0
e
s 00000/00000/00005
d D 3.331 83/03/19 14:25:33 eric 350 349
m 211
c Don't have mail from su'ed people come from "daemon"
e
s 00000/00000/00005
d D 3.330 83/03/19 13:14:27 eric 349 348
m 147
c Fix botch of putting incorrect full names on some addresses (usually
c UNIX-to-UNIX Copy)
e
s 00000/00000/00005
d D 3.329 83/03/12 18:05:51 eric 348 347
m 196
c take ECONNRESET (Connection reset by peer) as a temporary error during
c connection initiation.
e
s 00000/00000/00005
d D 3.328 83/03/12 17:41:55 eric 347 346
m 208
c Check for I/O error on close of temp file -- i.e., last buffer flush
e
s 00000/00000/00005
d D 3.327 83/03/12 15:40:05 eric 346 345
m 207
c Don't artifically add a "from: $q" when running the queue -- this seems
c to cause the from line in the qf file to be ignored.
e
s 00000/00000/00005
d D 3.326 83/03/10 00:48:02 eric 345 344
m 206
c Delete colon on front of aliases
e
s 00000/00000/00005
d D 3.325 83/03/08 19:22:48 eric 344 343
m 205
c Pass the delimiter character to parseaddr so that we can correctly
c decide between comma and space
e
s 00000/00000/00005
d D 3.324 83/03/07 09:55:13 eric 343 342
m 203
c Don't pass EX_TEMPFAIL code out (since we have already taken responsibility
c for delivering the message anyway).
e
s 00000/00000/00005
d D 3.323 83/03/07 09:25:01 eric 342 341
m 202
c Handle OLDSTYLE addresses properly with the -t flag; notice that tabs also
c delimit addresses (as well as spaces)
e
s 00000/00000/00005
d D 3.322 83/03/06 16:30:29 eric 341 340
m 201
c Handle messages with "Resent-xxx:" header lines properly (basically mark
c the message as being resent); ignore incoming From: lines if their text
c exactly matches our machine-readable address exactly -- this causes the
c full name to be added when called from (e.g.) MH.  Both of these mode are
c to improve interaction with MH.
e
s 00000/00000/00005
d D 3.321 83/03/05 17:39:11 eric 340 339
m 200
c Ignore delimiters (e.g., commas) inside quotes
e
s 00000/00000/00005
d D 3.320 83/02/26 15:32:31 eric 339 338
m 193
c Don't log message-id mapping and from person in a queue run
e
s 00000/00000/00005
d D 3.319 83/02/26 15:06:05 eric 338 337
m 162
c map host name for $w macro to upper case -- this is more conventional
e
s 00000/00000/00005
d D 3.318 83/02/26 11:51:43 eric 337 336
m 193
c log queueid <=> message-id correspondence
e
s 00000/00000/00005
d D 3.317 83/02/25 21:20:20 eric 336 335
m 181
c More attempts at insuring that everything goes through ruleset 4
e
s 00000/00000/00005
d D 3.316 83/02/24 20:03:04 eric 335 334
m 181
c arrange to cleanup addresses using ruleset 4 before storing in ADDR struct
e
s 00000/00000/00005
d D 3.315 83/02/24 18:55:32 eric 334 333
m 162
m 192
c Fix bug in $w and $=w setup; truncate output to seven bits if the "limits"
c flag is set to insure that nothing can be sent that looks like TELNET
c protocol
e
s 00000/00000/00005
d D 3.314 83/02/20 12:29:15 eric 333 332
m 190
c Avoid loops in the auto-closedown code
e
s 00000/00000/00005
d D 3.313 83/02/19 14:42:12 eric 332 331
m 188
c Avoid core dumps on very long addresses in headers.
e
s 00000/00000/00005
d D 3.312 83/02/18 13:11:57 eric 331 330
m 183
c Improve host verification -- put something in even if no HELO command given
e
s 00000/00000/00005
d D 3.311 83/02/18 12:44:13 eric 330 329
m 183
m 185
m 187
c Add HELO hostname verification; give an error if a message terminates with
c EOF rather than dot in SMTP mode; put in a catch for "Not owner" error on
c connect -- see if we can find anything funny.
e
s 00000/00000/00005
d D 3.310 83/02/13 16:23:03 eric 329 328
m 182
c fix clrbitmap to really clear the entire bitmap
e
s 00000/00000/00005
d D 3.309 83/02/10 10:00:49 eric 328 327
m 176
c avoid core dump on return receipt processing; clean up return receipt
c message.
e
s 00000/00000/00005
d D 3.308 83/02/08 10:50:24 eric 327 326
m 167
m 172
m 173
m 174
c clean up problems when QUEUE compile flag not defined; clean up hostname
c code to run on non-4.1c systems; fix use of -oeq (quiet on errors) flag.
e
s 00001/00001/00004
d D 3.307 83/02/03 10:46:02 eric 326 325
m 160
c Change version stamp to have no date (so that it looks nice as $v/$V)
e
s 00000/00000/00005
d D 3.306 83/02/03 10:29:15 eric 325 324
m 160
c $e macro is now SMTP entry message (so that configuration version can
c be included).
e
s 00000/00000/00005
d D 3.305 83/02/03 07:54:10 eric 324 323
m 168
c Make mailer size limits a per-mailer parameter (M field in the mailer
c descriptor)
e
s 00000/00000/00005
d D 3.304 83/02/02 12:53:10 eric 323 322
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00000/00000/00005
d D 3.303 83/02/01 20:47:34 eric 322 321
m 166
c don't call printqueue() if queueing is turned off
e
s 00000/00000/00005
d D 3.302 83/01/18 20:38:09 eric 321 320
c pause() after reply error if 18.100 set -- so that Sam can try to track
c down the state of the connection in the CMU-CS-A problem.
e
s 00000/00000/00005
d D 3.301 83/01/17 21:41:42 eric 320 319
m 158
c Set the $w macro to the hostname if at all possible to allow generic
c configuration tables.
e
s 00000/00000/00005
d D 3.300 83/01/17 12:31:10 eric 319 318
m 155
c fix bug that caused "\r\n" string in TCP mailer definition to turn
c into something else -- causing all TCP connections to hang.
e
s 00000/00000/00005
d D 3.299 83/01/17 09:32:18 eric 318 317
m 154
c define a newline in "nullmailer" so that queue files get written with
c newlines between the "H" lines.
e
s 00000/00000/00005
d D 3.298 83/01/16 22:08:47 eric 317 316
c put in socket debugging on a debug flag to help Sam find the CMU-CS-A
c problem -- this probably won't work with early 4.1c systems.
e
s 00000/00000/00005
d D 3.297 83/01/16 17:24:29 eric 316 315
m 153
c make the maximum number of simultaneous SMTP connections an option
e
s 00000/00000/00005
d D 3.296 83/01/16 13:14:04 eric 315 314
m 152
c Change mailer spec to have labelled fields for future expansion.
c **** This delta invalidates previous configuration files ****
e
s 00000/00000/00005
d D 3.295 83/01/15 17:40:49 eric 314 313
m 149
c be sure everything gets appropriately externalized; canonname goes away,
c since everything is now done by remotename
e
s 00000/00000/00005
d D 3.294 83/01/12 08:56:51 eric 313 312
m 144
c fix date format to be truly RFC822
e
s 00000/00000/00005
d D 3.293 83/01/09 15:43:11 eric 312 311
m 139
c fix CRLF problem when sending SMTP commands; make newstr() and crlf()
c into macros
e
s 00000/00000/00005
d D 3.292 83/01/08 19:54:37 eric 311 310
m 143
c release daemon resources when running the queue
e
s 00000/00000/00005
d D 3.291 83/01/08 13:49:08 eric 310 309
m 142
c be sure to open a new transcript on every queue run; when returning
c an SMTP transcript, only send the last half (i.e., that part which
c describes the sending half).
e
s 00000/00000/00005
d D 3.290 83/01/06 18:21:54 eric 309 308
m 141
c allow user-setable error codes in "error" mailer
e
s 00000/00000/00005
d D 3.289 83/01/06 18:09:01 eric 308 307
m 140
c fix a botch in argument processing such that it used the last flag as
c a recipient if there were no other recipients (e.g., with "-t")
e
s 00000/00000/00005
d D 3.288 83/01/06 12:05:54 eric 307 306
m 132
c fix (one more time!) long line wrapping.....
e
s 00000/00000/00005
d D 3.287 83/01/06 10:46:17 eric 306 305
m 139
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00000/00000/00005
d D 3.286 83/01/05 20:30:10 eric 305 304
m 132
c fix folded line output
e
s 00000/00000/00005
d D 3.285 83/01/05 17:57:11 eric 304 303
m 138
c curiouser and curiouser.....  a read error on the reply from a QUIT will
c cause another QUIT command, and thus an fclose(NULL).  Some sites seem
c to be sending a 421 Shutting down and then closing without waiting for
c the QUIT, so this happens....
e
s 00000/00000/00005
d D 3.284 83/01/05 10:19:04 eric 303 302
m 138
c improve error recovery for bizarre SMTP cases; unfortunately CMU has
c decided to start working again, so the strangest parts are untested.
e
s 00000/00000/00005
d D 3.283 83/01/04 19:53:55 eric 302 301
m 137
c externalize $g macro using ruleset 4 also
e
s 00000/00000/00005
d D 3.282 83/01/04 18:52:08 eric 301 300
m 136
c Don't try to drop our controlling TTY except when we are starting up a
c daemon; this can cause UUCP jobs to hang waiting for carrier on a dialin
c line (completely contrary to the intent).  Many thanks to Keith Sklower
c for pointing this one out.  However, that damned parameter to disconnect()
c has reappeared!
e
s 00000/00000/00005
d D 3.281 83/01/04 17:45:25 eric 300 299
m 135
c Ignore SIGPIPE early (in main rather than in deliver) so that rude hosts
c that close the connection early don't cause us to die -- in particular,
c CMU-CS-A (nee CMU-10A) was doing this after the DATA command; the problem
c went away quite mysteriously, so I have no idea why it happened
e
s 00000/00000/00005
d D 3.280 83/01/04 13:10:35 eric 299 298
m 129
m 134
c take EHOSTDOWN as a temporary failure; change the format of "deferred"
c message to be consistent with other messages.
e
s 00000/00000/00005
d D 3.279 83/01/04 10:58:55 eric 298 297
m 133
c fix botch that causes sendmail to core dump when there are large
c numbers of requests
e
s 00000/00000/00005
d D 3.278 83/01/04 10:04:41 eric 297 296
m 132
c Detect an internal error that seems to be occuring
e
s 00000/00000/00005
d D 3.277 83/01/03 18:01:33 eric 296 295
m 129
c give more useful error messages (including the errno that caused
c a temporary failure); reflect these messages out to mailq
e
s 00000/00000/00005
d D 3.276 83/01/03 14:02:28 eric 295 294
m 137
c have canonname pass the address through ruleset four also
e
s 00000/00000/00005
d D 3.275 83/01/03 13:44:39 eric 294 293
m 131
c take ENETUNREACH (Network unreachable) as a transient error -- this
c probably isn't usually right, but it seem safer in the long run....
e
s 00000/00000/00005
d D 3.274 83/01/03 13:19:37 eric 293 292
m 129
c print "request" instead of "requests" if there is only one request
e
s 00000/00000/00005
d D 3.273 83/01/03 13:03:01 eric 292 291
m 130
c fix bug in commaize so that it won't core dump on every message (sigh);
c process timeouts like normal errors so that they will get delivered to
c the correct address (i.e., the Errors-To: address).
e
s 00000/00000/00005
d D 3.272 83/01/03 11:28:04 eric 291 290
m 129
c fix botch in reading the queue that caused it to throw away the last
c entry it read -- this was particulary obvious with only one entry in
c the queue.
e
s 00000/00000/00005
d D 3.271 83/01/02 15:33:36 eric 290 289
m 124
c Take errno 65, "Host is unreachable", to be a recoverable error
e
s 00000/00000/00005
d D 3.270 83/01/02 14:27:32 eric 289 288
m 129
c clean up output of mailq mode
e
s 00000/00000/00005
d D 3.269 83/01/01 21:25:35 eric 288 287
m 123
c Put CRLF on all lines in user SMTP.  Pass this info down to
c innumerable routines.
e
s 00000/00000/00005
d D 3.268 83/01/01 18:14:56 eric 287 286
m 122
c Use a more resilient algorithm to handle the special case of an SMTP
c connection that is going down spontaneously (with a 421 reply code)
e
s 00000/00000/00005
d D 3.267 83/01/01 16:02:43 eric 286 285
m 128
c tag syserr's specially in the log so they can be grep'ed out easily
e
s 00000/00000/00005
d D 3.266 82/12/30 17:30:57 eric 285 284
m 114
c don't bother timing out on *.cf and qf* file reads -- they are
c really very vanilla
e
s 00000/00000/00005
d D 3.265 82/12/30 16:57:13 eric 284 283
m 113
c close files 3 through 20 before startup to insure sufficient resources
e
s 00000/00000/00005
d D 3.264 82/12/29 17:39:27 eric 283 282
m 112
c don't htons(sp->s_port) in makeconnection
e
s 00000/00000/00005
d D 3.263 82/12/24 08:14:55 eric 282 281
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00000/00000/00005
d D 3.262 82/12/14 19:23:23 eric 281 280
m 106
c fix freeze mode to do something more interesting that refreezing (over
c and over and over and .......)
e
s 00000/00000/00005
d D 3.261 82/12/14 16:57:16 eric 280 279
m 105
c Add "print mail queue" mode (-bp flag or call as "mailq")
e
s 00000/00000/00005
d D 3.260 82/12/13 18:25:22 eric 279 278
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00000/00000/00005
d D 3.259 82/12/13 17:47:27 eric 278 277
m 085
c NEW-IPC: convert to 4.1c
e
s 00000/00000/00005
d D 3.258 82/12/09 19:18:32 eric 277 276
m 036
m 053
m 064
c Fix a bug triggered when we add the sender's "@domain" to an address
c in the message body that is missing a domain -- we forgot to null
c terminate the list.
e
s 00000/00000/00005
d D 3.257 82/12/09 11:19:09 eric 276 275
m 081
m 095
m 103
c log read timeouts as syserrs; be able to match the inverse of a class
c using the $~x syntax; don't add a full name during network forward operations
e
s 00000/00000/00005
d D 3.256 82/12/05 13:46:29 eric 275 274
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00000/00000/00005
d D 3.255 82/11/28 16:00:50 eric 274 273
c implement SMTP auto-shutdown on 421 codes; clean up some error processing
c items, particularly in SMTP; don't reinstantiate error message bodies after
c queueing; other minor changes.  This is all cleanup from 3.253.
e
s 00000/00000/00005
d D 3.254 82/11/28 10:22:20 eric 273 272
c fix a number of problems left over from yesterday's delta.  The big
c triumph is being able to delete the parameter from disconnect().
e
s 00000/00000/00005
d D 3.253 82/11/28 00:22:21 eric 272 271
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00000/00000/00005
d D 3.252 82/11/24 18:44:28 eric 271 270
c lint it
e
s 00000/00000/00005
d D 3.251 82/11/24 17:15:30 eric 270 269
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00000/00000/00005
d D 3.250 82/11/21 17:19:05 eric 269 268
m 026
c preliminary hacks for multiple SMTP transactions per connection: make
c assignment of multiple queue id's more efficient, make prefixes two
c characters (e.g., qfAA99999), pass the file name to freeze and thaw,
c add a mailer flag saying we are talking to one of our own kind.
e
s 00000/00000/00005
d D 3.249 82/11/20 12:43:29 eric 268 267
m 083
c Accept user@[net.host.logical.imp] syntax
e
s 00000/00000/00005
d D 3.248 82/11/18 21:33:38 eric 267 266
m 080
c Correctly run "sendmail -q" (had a reversed condition on QueueIntvl)
e
s 00000/00000/00005
d D 3.247 82/11/18 17:54:23 eric 266 265
m 079
c Fix bug causing loops in sendto if there are scanner errors in addresses
e
s 00000/00000/00005
d D 3.246 82/11/18 08:56:27 eric 265 264
m 060
m 073
c disconnect input, output, signals, etc. when running in background
e
s 00000/00000/00005
d D 3.245 82/11/17 09:36:47 eric 264 263
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00000/00000/00005
d D 3.244 82/11/14 15:34:59 eric 263 262
m 075
c Explicitly inherit e_oldstyle from BlankEnvelope to MainEnvelope
e
s 00000/00000/00005
d D 3.243 82/11/14 15:14:00 eric 262 261
m 074
c fix quote processing on program mailers
e
s 00000/00000/00005
d D 3.242 82/11/14 12:26:17 eric 261 260
m 072
c Don't give an error message on unknown options
e
s 00000/00000/00005
d D 3.241 82/11/13 18:07:59 eric 260 259
m 021
m 066
m 069
m 069
m 070
m 071
c Clean up argument structure (-I=>-bi, -Z=>-bz).  Add -bp stub to someday
c print queue.  Move compile conf into conf.h (still some stuff in the
c Makefile).  Assume -bp if called as "mailq" and -bi if called as
c "newaliases".  Drop old directory hack -- send out compat code instead.
c Don't rebuild the alias file automatically unless the D option is set.
c Clean up compilation flags.
e
s 00000/00000/00005
d D 3.240 82/11/07 16:14:44 eric 259 258
m 041
c make all mailer output go to the transcript if running server smtp; this
c has the effect of making some significant changes in the output structure
c to handle such things as -em and -as together
e
s 00000/00000/00005
d D 3.239 82/11/07 15:31:50 eric 258 257
m 063
c don't flag errors in setting dangerous options when -C is used
e
s 00000/00000/00005
d D 3.238 82/11/05 13:12:52 eric 257 256
m 062
c arrange to freeze the configuration file for quick startup -- this
c technique requires reprocessing the argv so that flag settings don't
c get lost, and is really rather of a hack.
e
s 00000/00000/00005
d D 3.237 82/11/04 15:22:16 eric 256 255
m 019
c don't unlink qf & df files on ^C
e
s 00000/00000/00005
d D 3.236 82/11/04 13:27:28 eric 255 254
m 037
c put header conditionals into the .cf file
e
s 00000/00000/00005
d D 3.235 82/11/03 11:18:06 eric 254 253
m 059
c don't strip quotes off of addresses during prescan
e
s 00000/00000/00005
d D 3.234 82/11/03 10:34:13 eric 253 252
m 058
c Put the temporary file mode on the F option
e
s 00000/00000/00005
d D 3.233 82/11/03 09:49:15 eric 252 251
m 049
c Arrange to strip quote bits in message header; move SPACESUB into
c conf.c; change SpaceSub to unquoted dot
e
s 00000/00000/00005
d D 3.232 82/11/03 09:00:33 eric 251 250
m 056
c Arrange for queue.c to aapt to systems w/o new directory code
e
s 00000/00000/00005
d D 3.231 82/10/31 13:47:06 eric 250 249
m 032
m 051
c Call ruleset 4 after doing per-mailer translation to convert from
c internal to external form.
e
s 00000/00000/00005
d D 3.230 82/10/28 17:41:15 eric 249 248
m 039
m 027
c Put the "@:@" trick on the "a" option.  Also, move TrustedUsers into
c sendmail.h (it should have gone here in the first place!)
e
s 00000/00000/00005
d D 3.229 82/10/27 20:43:35 eric 248 247
m 044
c strip out bcc: and resent-bcc: always
e
s 00000/00000/00005
d D 3.228 82/10/25 08:30:12 eric 247 246
m 040
c Don't send closing protocol to SMTP if you haven't opened the
c connection; this happens if checkcompat fails on the only recipient.
e
s 00000/00000/00005
d D 3.227 82/10/22 09:02:44 eric 246 245
m 023
c part of a heuristic hill climbing algorithm to minimize the number of
c IPC bugs that come crawling over me.
e
s 00000/00000/00005
d D 3.226 82/10/16 15:24:52 eric 245 244
m 027
c Put list of login names able to use -f in the .cf file.
e
s 00000/00000/00005
d D 3.225 82/10/16 14:43:47 eric 244 243
m 007
c Arrange for a wizards password (the W option).  The SMTP KILL command
c may only be issued if this option is set.  This delta adds the "WIZ"
c command, and changes _KILL => KILL, _DEBUG => DEBUG, _VERBOSE => VERB,
c and _SHOWQ => SHOWQ.
e
s 00000/00000/00005
d D 3.224 82/10/16 13:43:28 eric 243 242
m 024
c Fix debug statement in sendall
e
s 00000/00000/00005
d D 3.223 82/10/16 13:22:22 eric 242 241
m 010
c Arrange for MD_FORK to work well with -v so that we can use it as the
c default.  This was really a separate bug, but I have just lumped it in
c here -- the problem came up with stty tostop.
e
s 00000/00000/00005
d D 3.222 82/10/13 21:55:07 eric 241 240
m 023
c Don't interrupt the process doing accepts (have a separate process
c running the queue) to avoid a large pile of 4.1[abc] bugs.  When
c something more stable comes out, I will change this.
e
s 00000/00000/00005
d D 3.221 82/10/13 18:43:28 eric 240 239
m 022
c Don't interpret <, >, (, or ) while in QST (quote state) during prescan
e
s 00000/00000/00005
d D 3.220 82/10/11 09:51:43 eric 239 238
m 016
c have auto-queueups print a polite message in the log (rather than an
c obnoxious "Temporary Failure").  Adds a new routine "logdelivery".
e
s 00000/00000/00005
d D 3.219 82/10/09 21:02:27 eric 238 237
m 005
c force a queuename in returntosender to insure that everyone has a
c queue name.
e
s 00000/00000/00005
d D 3.218 82/10/09 20:27:42 eric 237 236
m 003
c Lock out interrupts during alias rebuild; add an alias "@:@" after
c rebuild that we can check for to insure that the alias file is up to
c date.  Times out after five minutes (is this reasonable on ucbvax?)
c and forces a rebuild.  It shouldn't matter in the long run if two
c people rebuild, so I think this is the right thing to do.
e
s 00000/00000/00005
d D 3.217 82/10/09 19:06:31 eric 236 235
m 002
c Handle Reverse-Path in some reasonable way.  You must put the 'X'
c flag (M_FULLSMTP) in the local mailer's flags to get this line.
e
s 00000/00000/00005
d D 3.216 82/10/09 18:11:21 eric 235 234
m 013
c print a status indication when a message is autoqueued, either from
c a -bq flag or a NoConnect
e
s 00000/00000/00005
d D 3.215 82/10/09 17:22:35 eric 234 233
m 008
c Force -v override of deferred connect
e
s 00000/00000/00005
d D 3.214 82/10/09 17:10:37 eric 233 232
m 004
c Only put the "from" person on the error queue if an error actually
c occured -- prevents many "duplicate supressed" messages, etc.
e
s 00000/00000/00005
d D 3.213 82/10/09 09:05:35 eric 232 231
m 001
c implement an experimental forward-path algorithm by stripping off a
c leading "@..." component and dropping it on the end.
e
s 00000/00000/00005
d D 3.212 82/10/07 08:52:47 eric 231 230
c try to come up with a workaround on some of the IPC problems relating to
c interrupted accepts -- all this can go when everyone at Berkeley runs
c unflakey IPC.  Also, never use ruleset three alone -- involves changing
c canonname again.  Probably shouldn't do an auto-call of ruleset three now.
e
s 00000/00000/00005
d D 3.211 82/10/07 01:40:19 eric 230 229
c bother.... it takes time to close a socket
e
s 00000/00000/00005
d D 3.210 82/10/07 00:09:14 eric 229 228
c allow passing through multiple rewriting sets in test mode;
c <ndir.h> => <dir.h> for maximum portability
e
s 00000/00000/00005
d D 3.209 82/10/06 11:45:40 eric 228 227
c add test mode (MD_TEST, -bt)
e
s 00000/00000/00005
d D 3.208 82/09/30 22:29:46 eric 227 226
c workaround in daemon accept code for 4.1a kernel bug: if an accept
c gets an EINTR and then a valid accept before the interrupt returns,
c the connection will be lost forever (at least, as I understand it).
e
s 00000/00000/00005
d D 3.207 82/09/26 17:04:24 eric 226 225
c Put more configuration into setoption; merge some of the argv processing
c with this; move configuration information out of conf.c into the .cf
c file.  Since a lot of stuff will default to zero, a new .cf file is
c required.
e
s 00000/00000/00005
d D 3.206 82/09/26 14:45:52 eric 225 224
c completely instantiate queue files for all mail, even if not needed;
c fix a bug that would probably come up once every ten years in creating
c the queue id.  should merge argv flag processing with option processing.
e
s 00000/00000/00005
d D 3.205 82/09/24 19:39:25 eric 224 223
c change option implementation; define a bunch of interesting options.
e
s 00000/00000/00005
d D 3.204 82/09/24 09:38:36 eric 223 222
c arrange to be able to define options; put precedences in .cf file;
c send errors to an Errors-To: field; fix a serious bug causing mail
c to not be delivered to anyone if there were any errors.
e
s 00000/00000/00005
d D 3.203 82/09/22 10:50:47 eric 222 221
c don't put commas in non-address fields; have -bq clean up its temp files
e
s 00000/00000/00005
d D 3.202 82/09/21 10:15:00 eric 221 220
c get rid of double error returns; improve verbose mode output to be
c standard format (even though verbose mode isn't standard); output
c queue files with commas in headers to insure that the oldstyle stuff
c doesn't get confused.
e
s 00000/00000/00005
d D 3.201 82/09/18 20:37:46 eric 220 219
c fix botch where it believes that a list is !oldstyle just because
c it has an alias expansion in it.
e
s 00000/00000/00005
d D 3.200 82/09/16 20:25:01 eric 219 218
c drop ":...;" stuff -- it screws it up aliases; pass parameters to
c subroutines (this also adds $@ and $: features to subr calls); check
c overflow of "tobuf" on smtp deliveries, which caused core dumps on
c large mailing lists
e
s 00000/00000/00005
d D 3.199 82/09/12 22:17:30 eric 218 217
c accept ": ... ;" syntax for groups if !oldstyle
e
s 00000/00000/00005
d D 3.198 82/09/12 16:44:03 eric 217 216
c change inheritance for macros in envelopes; be able to canonicalize
c non-domained names by appending domain from sender; call ruleset 3
c explicitly before doing other rulesets; some general cleanup.
e
s 00000/00000/00005
d D 3.197 82/09/11 17:18:16 eric 216 215
c don't assign $s to be the sending host (this mucks up Received:
c lines) -- instead just use HELO messages; chdir into queue directory
c and make all pathnames relative; be more conservative in creating
c queue id's -- in the event you get file table overflows, etc.
e
s 00000/00000/00005
d D 3.196 82/09/08 23:55:46 eric 215 214
c fix stupid bug in wait code to dispose of "Interrupted system call" message
e
s 00000/00000/00005
d D 3.195 82/09/08 22:13:20 eric 214 213
c fix a nasty botch in 3.194 that killed SMTP in daemon mode.   sigh......
e
s 00000/00000/00005
d D 3.194 82/09/08 21:20:05 eric 213 212
c try to avoid "Interrupted system call" on wait in deliver and on
c writes; fix returned message to have proper sender; handle extra
c mailer output more cleverly.
e
s 00000/00000/00005
d D 3.193 82/09/06 19:55:17 eric 212 211
c more hacking on oldstyle -- always assume sender fields are in new
c style so that locally generated fields are edited correctly.
e
s 00000/00000/00005
d D 3.192 82/09/06 18:47:26 eric 211 210
c fix botch in "at"s in headers
e
s 00000/00000/00005
d D 3.191 82/09/06 18:24:40 eric 210 209
c fix botch in computing e_oldstyle
e
s 00000/00000/00005
d D 3.190 82/09/06 17:58:40 eric 209 208
c fix bug in scanner state machine that never let you out of quote state.
e
s 00000/00000/00005
d D 3.189 82/09/06 17:14:03 eric 208 207
c increase log level needed to print "entered" message.
e
s 00000/00000/00005
d D 3.188 82/09/06 17:00:23 eric 207 206
c user SMTP fixes to talk to ISI
e
s 00000/00000/00005
d D 3.187 82/09/06 16:24:51 eric 206 205
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00000/00000/00005
d D 3.186 82/09/05 18:08:58 eric 205 204
c change $g processing from a macro substitution per mailer to two sets
c of rewriting rules per mailer -- one each for sender and recipient
c fields; convert to NBS standard on Return-Receipt-To: and Precedence:
c fields; clean up From: processing code and generalize it to all
c sender fields; tune debugging code; clean up canonname.
c **** This delta invalidates previous configuration files ****
e
s 00000/00000/00005
d D 3.185 82/09/05 11:48:27 eric 204 203
c add $* to match zero or more and $> to make a "subroutine" call; stick
c in initial hooks for per-mailer rewriting; improve diagnostics in readcf,
c including number lines; increase the number of rewriting sets.
e
s 00000/00000/00005
d D 3.184 82/09/01 10:24:00 eric 203 202
c log entering uid & pid; allow CANONUSER ($:) to abort a rewriting set.
e
s 00000/00000/00005
d D 3.183 82/08/31 17:46:56 eric 202 201
c increase MAXMAILERS to 25
e
s 00000/00000/00005
d D 3.182 82/08/31 10:05:56 eric 201 200
c clean up reply code processing some more; in particular, give more
c detail in many messages.  process connection failures correctly.
e
s 00000/00000/00005
d D 3.181 82/08/29 23:31:35 eric 200 199
c handle comments and quotes in headers; still doesn't deal with
c backslashes however -- prescan should be cleaned up to deal with
c this case.  it turns out there are many bugs in prescan; it should
c be extensively rewritten.
e
s 00000/00000/00005
d D 3.180 82/08/29 17:32:49 eric 199 198
c fix serious botch in SMTP reply code delta; change a bunch of
c "Internal error" codes to a new "Remote protocol error" -- so that
c I don't get blamed for things that other systems do.
e
s 00000/00000/00005
d D 3.179 82/08/29 16:52:31 eric 198 197
c do a better job at interpreting SMTP reply codes
e
s 00000/00000/00005
d D 3.178 82/08/29 15:52:20 eric 197 196
c give 554 message on syserr (instead of 451) if errno == 0; as it
c was some permanent errors appeared transient
e
s 00000/00000/00005
d D 3.177 82/08/27 18:01:25 eric 196 195
c hack crackaddr to strip blanks off the end of a cracked address; this
c happens because "u at h" becomes "$g  " (with two spaces at the end).
c this doesn't solve the general case (e.g., "u at h (me)" comes out as
c "$g   (me)", with three spaces), but does handle the ugliest case.
c besides, the "at" syntax is supposed to go away.
e
s 00000/00000/00005
d D 3.176 82/08/27 16:01:58 eric 195 194
c simplify timeout code; allow multiple simultaneous queue runs so that
c large messages don't freeze things up; fix EINTR problem in sfgets;
c clean up canonname to be really correct; lots of misc. cleanup
e
s 00000/00000/00005
d D 3.175 82/08/27 11:11:40 eric 194 193
c release e_id after fork in daemon code; ignore events scheduled by
c another process
e
s 00000/00000/00005
d D 3.174 82/08/25 23:18:24 eric 193 192
c assign a new queue id to all jobs coming in via TCP
e
s 00000/00000/00005
d D 3.173 82/08/25 21:22:10 eric 192 191
c sigh....  more fun and games in the daemon code to try to guess right.
e
s 00000/00000/00005
d D 3.172 82/08/25 19:44:33 eric 191 190
c recreate a socket after every failed accept()
e
s 00000/00000/00005
d D 3.171 82/08/25 16:19:23 eric 190 189
c apply ruleset 4 to rewrite addresses in the body of the message; fix
c a clock.c bug that caused it to lose events; more time cleanup.
e
s 00000/00000/00005
d D 3.170 82/08/25 11:21:21 eric 189 188
c clean up time manipulation to always be current; assign job
c id's earlier to make sure there is always one with a message.
e
s 00000/00000/00005
d D 3.169 82/08/25 10:46:27 eric 188 187
c log locked files in queuer; don't mistakenly start up two runqueue's
e
s 00000/00000/00005
d D 3.168 82/08/24 19:55:39 eric 187 186
c put queueup log messages on a higher logging level
e
s 00000/00000/00005
d D 3.167 82/08/24 19:41:32 eric 186 185
c log more info (on log level 11); try to detect wild accept loops;
c some minor cleanup and debugging checks; fix NoConnect option to;
c only apply to expensive mailers (regardless of sendqueue order)
e
s 00000/00000/00005
d D 3.166 82/08/24 10:27:46 eric 185 184
c clean up event handling so that events that do longjmp's don't turn
c off all future events; diagnose reentry of main().
e
s 00000/00000/00005
d D 3.165 82/08/23 11:59:50 eric 184 183
c clean up queueing; log time in queue.
c **** This delta invalidates mqueue files ****
e
s 00000/00000/00005
d D 3.164 82/08/23 09:23:54 eric 183 182
c allow continuation lines in .cf file (particularly in headers)
e
s 00000/00000/00005
d D 3.163 82/08/22 23:07:11 eric 182 181
c change $i to $j; $i is now queue id; put "Received:" format in .cf
c file; minor cleanup
e
s 00000/00000/00005
d D 3.162 82/08/22 19:03:19 eric 181 180
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00000/00000/00005
d D 3.161 82/08/21 17:54:37 eric 180 179
c move <> and forward path processing to .cf file; increase MAXATOMS
c since some "comment" information may now be part of the address.
c **** this installation requires a new sendmail.cf file ****
e
s 00000/00000/00005
d D 3.160 82/08/20 20:35:15 eric 179 178
c time stamp the SMTP greeting message; increase the buffer size in
c syslog to prevent core dumps.
e
s 00000/00000/00005
d D 3.159 82/08/17 20:45:43 eric 178 177
c change Mail-From: to Received: for new SMTP spec (RFC821); handle
c folded lines in queue files correctly.
e
s 00000/00000/00005
d D 3.158 82/08/17 16:19:10 eric 177 176
c rework header processing: do special purpose header munging in a
c separate routine so that the queue run can do it also; parse From lines
c in a fancy way, extracting the address part and turning it into a $g
c macro; avoid reading and processing core files that end up in the queue
c directory; check the queue directory name for legality; fix the verify
c (-bv) option.
e
s 00000/00000/00005
d D 3.157 82/08/15 17:35:39 eric 176 175
c mark From: lines with the H_FROM bit; make VRFY work by adding the
c QuickAbort flag; handle headers more cleverly in queue files -- this
c seems to work, but I am frankly nervous.  Note: this version
c represents a flag day!-- old queues will not process properly.
e
s 00000/00000/00005
d D 3.156 82/08/15 11:58:25 eric 175 174
c output class rather than priority in log; accept zero intervals in
c event scheduling; allow continuation lines in queue files (particularly
c for headers); don't diagnose inappropriate errors when accepting a
c connection; fix bug when reprocessing addresses that put garbage in
c the header; some misc. debugging info (-d14 => commaize)
e
s 00000/00000/00005
d D 3.155 82/08/08 21:15:44 eric 174 173
c make "sleep" work correctly even in the face of other events; clean
c up the queue processing: child queue runs now go away when done.  more
c debugging logging is needed to verify that this works right though.
e
s 00000/00000/00005
d D 3.154 82/08/08 17:05:19 eric 173 172
c move remotename() from deliver.c to parse.c; change default log level
c to 9; put error versus success delivery on different log levels;
c diagnose overlength lines in headers; more general event mechanism;
c initial implementation of canonname; don't diagnose link errors in
c queue, since another daemon could have grabbed it legitimately;
c fix a problem in VRFY on bad addresses
e
s 00000/00000/00005
d D 3.153 82/08/08 01:00:25 eric 172 171
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00000/00000/00005
d D 3.152 82/08/07 11:13:15 eric 171 170
c Fix address rewriting so that multiple spaces and tabs work properly
e
s 00000/00000/00005
d D 3.151 82/07/31 16:57:49 eric 170 169
c don't give error on ETIMEDOUT on accept call; print errno properly
c in syserr()
e
s 00000/00000/00005
d D 3.150 82/07/31 12:56:56 eric 169 168
c By default, just queue up the mail for most mailers and deliver
c from the queue.  This avoids the wild process problem in netnews
c (or so we hope).
e
s 00000/00000/00005
d D 3.149 82/07/27 23:09:04 eric 168 167
c clean up semantics of daemon mode to facilitate use of other IPC;
c move some code to main.c because it is not part of creating a
c connection; if you can't create a socket assume there is another
c sendmail running and exit; improve the verbose information in an
c SMTP connection to make it more obvious which messages went which
c way; don't attempt delivery if you get an error reading the queue file.
e
s 00000/00000/00005
d D 3.148 82/07/25 13:11:20 eric 167 166
c clean up error handling
e
s 00000/00000/00005
d D 3.147 82/07/22 01:23:15 eric 166 165
c new version of syslog that uses 4.2 IPC
e
s 00000/00000/00005
d D 3.146 82/07/20 19:39:15 eric 165 164
c be smarter about when to rerun the queue when you are in repeated
c queue mode.
e
s 00000/00000/00005
d D 3.145 82/07/14 11:19:27 eric 164 163
c disconnect sendmail from the controlling tty in daemon mode.
e
s 00000/00000/00005
d D 3.144 82/07/14 11:00:33 eric 163 162
c arrange for MotherPid to be correct in daemon mode
e
s 00000/00000/00005
d D 3.143 82/07/14 10:46:00 eric 162 161
c fork automatically in daemon mode (but only if no debugging)
e
s 00000/00000/00005
d D 3.142 82/07/14 09:25:11 eric 161 160
c don't accidently unlink a null pointer in finis(); change the way
c it decides whether to remove the temp file (you don't want to if you
c are queueing it up); fix a bug in Apparently-To: that caused it to
c output both pre- and post-expanded names (only output pre-expanded)
e
s 00000/00000/00005
d D 3.141 82/07/05 20:56:24 eric 160 159
c flush fatal error flag before returning error messages to avoid error
c message loop; improve debugging: flush transcript before doing things
c that might take a long time, add some info to debug messages; extend
c configuration on timeouts so that text of error message is in conf.c
e
s 00000/00000/00005
d D 3.140 82/07/05 18:49:49 eric 159 158
c add "Apparently-To:" field if no recipients are in the header.
e
s 00000/00000/00005
d D 3.139 82/07/05 13:21:21 eric 158 157
c count Mail-From: lines to get a hop count, giving error as
c appropriate after collection; don't attempt delivery of message if
c errors occur before or during collection; fix a bug in -as mode
c (non-daemon SMTP).
e
s 00000/00000/00005
d D 3.138 82/07/05 12:37:23 eric 157 156
c check for errors before opening a daemon connection
e
s 00000/00000/00005
d D 3.137 82/07/05 12:22:02 eric 156 155
c split off clock stuff from util.c so that vacation will compile
e
s 00000/00000/00005
d D 3.136 82/07/05 12:02:53 eric 155 154
c put timeouts on net reads
e
s 00000/00000/00005
d D 3.135 82/07/02 20:52:46 eric 154 153
c arrange to not lose temporary queue control files (tf files)
c if you interrupt a queue run process.
e
s 00000/00000/00005
d D 3.134 82/07/02 10:00:16 eric 153 152
c be paranoid about resetting the "FatalErrors" flag -- always reset
c after forking for daemon or queue mode.  This will prevent false error
c return delivery.
e
s 00000/00000/00005
d D 3.133 82/07/02 09:43:39 eric 152 151
c take special care in outputing error messages to the transcript;
c a little bit of paranoia never hurt a mail system.
e
s 00000/00000/00005
d D 3.132 82/06/30 22:39:22 eric 151 150
c open a separate transcript in the child of a daemon.
e
s 00000/00000/00005
d D 3.131 82/06/26 14:53:40 eric 150 149
c clean up error messages on SMTP temporary failures resulting from
c failure to connect properly.
e
s 00000/00000/00005
d D 3.130 82/06/26 13:53:35 eric 149 148
c more debug information; fix dependencies in makefile
e
s 00000/00000/00005
d D 3.129 82/06/26 13:10:41 eric 148 147
c lint
e
s 00000/00000/00005
d D 3.128 82/06/26 12:33:39 eric 147 146
c take environment variable "NAME" to determine what your full name
c is; this is overridden by -F.
e
s 00000/00000/00005
d D 3.127 82/06/26 11:56:51 eric 146 145
c add _kill command to SMTP.  this is probably dangerous in the
c outside world.
e
s 00000/00000/00005
d D 3.126 82/06/25 19:38:24 eric 145 144
c add debugging information to server smtp code: _debug to set
c Debug, _verbose to set verbose, and _showq to show the send queue
c (already existant, just a name change)
e
s 00000/00000/00005
d D 3.125 82/06/23 12:12:19 eric 144 143
c check prescan return values in remotename
e
s 00000/00000/00005
d D 3.124 82/06/19 21:14:18 eric 143 142
c remember to put a newline at the end of the UGLYUUCP line
e
s 00000/00000/00005
d D 3.123 82/06/19 21:09:10 eric 142 141
c get rid of comment lines when storing rewriting rules
e
s 00000/00000/00005
d D 3.122 82/06/19 20:47:23 eric 141 140
c improve SMTP error reporting
e
s 00000/00000/00005
d D 3.121 82/06/18 11:58:31 eric 140 139
c believe host name on SMTP "HELO" line
e
s 00000/00000/00005
d D 3.120 82/06/17 10:44:38 eric 139 138
c fix botch in -Q flag (sets AliasFile rather than QueueDir)
e
s 00000/00000/00005
d D 3.119 82/06/16 14:51:16 eric 138 137
c allow connection refused as a temporary error; make sure there is
c always someone to return the mail to on error
e
s 00000/00000/00005
d D 3.118 82/06/16 14:29:20 eric 137 136
c fix botch in outputing "recipient" type lines (e.g., To:)
e
s 00000/00000/00005
d D 3.117 82/06/07 23:53:26 eric 136 135
c allow multiple connections; call putline to output FULL_SMTP
c lines (to limit line lengths, etc.); involves adding an asm.sed script
c to the makefile
e
s 00000/00000/00005
d D 3.116 82/06/07 07:54:55 eric 135 134
c make transcripts verbose always; misc. message cleanup, etc.
e
s 00000/00000/00005
d D 3.115 82/06/07 07:06:13 eric 134 133
c strip out xlate stuff -- this belongs at a different level
e
s 00000/00000/00005
d D 3.114 82/06/06 23:13:08 eric 133 132
c avoid loops by not sending to owner-owner-* -- just send to
c owner-owner instead
e
s 00000/00000/00005
d D 3.113 82/06/06 23:05:17 eric 132 131
c implement alias owner feature.  this actually works for any user.
c basically, if the alias owner-xxx exists, errors sending to xxx will be
c sent to that alias rather than to the sender.
e
s 00000/00000/00005
d D 3.112 82/05/31 19:03:47 eric 131 130
c make temp files the correct modes in all cases
e
s 00000/00000/00005
d D 3.111 82/05/31 18:49:50 eric 130 129
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00000/00000/00005
d D 3.110 82/05/31 17:10:51 eric 129 128
c eliminate -V, -D, -p flags in favor of a single flag "-bx"
c (be in mode x).
e
s 00000/00000/00005
d D 3.109 82/05/31 15:35:57 eric 128 127
c don't output SMTP/FTP error codes in transcript file
e
s 00000/00000/00005
d D 3.108 82/05/31 15:32:18 eric 127 126
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00000/00000/00005
d D 3.107 82/05/30 10:25:35 eric 126 125
c add M_FULLSMTP (``X'' flag in .cf file) for eventual implementation
c of full SMTP.  This version must support such garbage as line limits,
c address length limits, return-path, etc.
e
s 00000/00000/00005
d D 3.106 82/05/29 20:00:30 eric 125 124
c allow the user with name "daemon" to send mail as anyone s/he wants.
e
s 00000/00000/00005
d D 3.105 82/05/22 02:05:48 eric 124 123
c add "junk mail" -- error responses are never returned.
e
s 00000/00000/00005
d D 3.104 82/05/22 01:38:07 eric 123 122
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00000/00000/00005
d D 3.103 82/05/20 17:46:07 eric 122 121
c add dfopen as a "determined fopen" -- it retries if it gets recoverable
c errors.  we use it for returning mail (to dead.letter) and creating the
c temp file.  the whole idea is to avoid dropping things on the floor on
c heavily loaded systems.  this is untested, since it seems impossible to
c fill up the inode or file tables on this VAX (but it works if the open
c succeeds).
e
s 00000/00000/00005
d D 3.102 82/05/15 12:29:36 eric 121 120
c add the 'R' flag to mailers, saying to rewrite the recipient addresses
c to be relative to the recipient.  This makes reply code easy, but
c confuses user mail programs that are expecting to have to rewrite
c recipient addresses.  In general, the receiving host must be "smart"
c for this to work.
e
s 00000/00000/00005
d D 3.101 82/05/06 20:21:14 eric 120 119
c allow socket number on [IPC] connections -- eventually this
c could be used to handle other low-level protocols.
e
s 00000/00000/00005
d D 3.100 82/03/27 20:15:12 eric 119 118
c delete neat remotename feature, because it doesn't work right in
c UUCPland -- and breaks stupid hosts.  'Twill be fixed, I promise.  Time
c must be spent figuring out how to define the civilized versus the
c uncivilized world.
e
s 00000/00000/00005
d D 3.99 82/03/27 19:57:44 eric 118 117
c compensate for bug in getlogin: can return the empty string ("")
c for certain error conditions rather than the NULL pointer.
e
s 00000/00000/00005
d D 3.98 82/03/22 22:37:54 eric 117 116
c continue the impossible task of tracking Bill Joy
e
s 00000/00000/00005
d D 3.97 82/03/22 22:10:44 eric 116 115
c more cleanup for new 4.2 system configuration and some more fixes
c for vanilla V7
e
s 00000/00000/00005
d D 3.96 82/03/20 18:13:01 eric 115 114
c take % as an acceptable name terminator in GECOS field
c ("in-care-of") -- for TEF%UCSFCGL
e
s 00000/00000/00005
d D 3.95 82/03/20 16:12:27 eric 114 113
c 16 bit changes -- should have no effect on VAX binaries to
c speak of.
e
s 00000/00000/00005
d D 3.94 82/03/06 16:11:49 eric 113 112
c get queue scanning working correctly in conjunction with daemon mode
e
s 00000/00000/00005
d D 3.93 82/03/06 15:35:49 eric 112 111
c have daemon mode assume SMTP mode
e
s 00000/00000/00005
d D 3.92 82/03/06 15:08:24 eric 111 110
c give correct error message in SMTP if some of the addresses are not ok
e
s 00000/00000/00005
d D 3.91 82/03/06 14:52:22 eric 110 109
c arrange to be able to accept a connection from any host.
e
s 00000/00000/00005
d D 3.90 82/03/06 14:15:55 eric 109 108
c collapse special character processing into macro processing for
c simplicity of code.
e
s 00000/00000/00005
d D 3.89 82/03/06 12:09:18 eric 108 107
c clean up error handling in IPC case; fix a minor bug in headers in
c queueing code; make SMTP mail multi user per connect.
e
s 00000/00000/00005
d D 3.88 82/03/05 10:45:48 eric 107 106
c remove silly $U dependency in UGLYUUCP code
e
s 00000/00000/00005
d D 3.87 82/03/05 10:13:06 eric 106 105
c include direct connect on outgoing mail if the pathname is "[IPC]" --
c this gives minimal number of processes for ethernet mail.
e
s 00000/00000/00005
d D 3.86 82/02/27 12:29:31 eric 105 104
c more work on after $g translate rewriting
e
s 00000/00000/00005
d D 3.85 82/02/27 11:37:42 eric 104 103
c implement "return receipt requested".
e
s 00000/00000/00005
d D 3.84 82/02/27 09:51:36 eric 103 102
c improve rewriting of "after $g translate" to correspond to the
c real world.....
e
s 00000/00000/00005
d D 3.83 82/02/26 21:56:10 eric 102 101
c implement daemon mode
e
s 00000/00000/00005
d D 3.82 82/02/26 19:02:33 eric 101 100
c default to OldStyle headers -- this turns out to be needed so that it
c will work right when running as a server.
e
s 00000/00000/00005
d D 3.81 82/02/22 19:59:16 eric 100 99
c some hacks to make the ethernet community happier -- .cf changes only
e
s 00000/00000/00005
d D 3.80 82/02/22 19:32:12 eric 99 98
c be much more clever about splitting up addresses when doing header
c rewriting.  become NewStyle automatically based on heuristics; this
c makes some other addresses work, although there are conceivably
c sites that this could break.  Perhaps we should default to OldStyle?
c I don't think this would break anything.
e
s 00000/00000/00005
d D 3.79 82/02/20 16:56:02 eric 98 97
c output names in a nice comma-separated fashion in messages -- this
c opens up other possibilities
e
s 00000/00000/00005
d D 3.78 82/02/20 12:59:46 eric 97 96
c expand macros in rewriting rules early to allow multi-word macros to
c be processed correctly.
e
s 00000/00000/00005
d D 3.77 82/02/20 12:12:09 eric 96 95
c add the -c flag, to cause sendmail to just queue messages that are for
c mailers that are expensive; a later instantiation can come around and
c send them in a batch.  Also, pass macro definitions through the
c queueing code so that macros can be expanded later rather than sooner;
c this is important for destination dependent macros such as $g.
e
s 00000/00000/00005
d D 3.76 82/02/04 20:31:21 eric 95 94
c add host aliasing; add -p flag.  this version doesn't yet know about
c replacing the text of the host alias into the message however.  syntax
c is grotty: "/hostmatch:%s@newhost" or whatever.
e
s 00000/00000/00005
d D 3.75 82/01/23 14:21:06 eric 94 93
c add M_UGLYUUCP flag; only catch names with leading slash as filenames;
c let the user redefine their full name; don't pass -r or -f to uux.
e
s 00000/00000/00005
d D 3.74 82/01/10 21:57:33 eric 93 92
c cleanup from cbosgd (Mark Horton) testing; some internals, mostly
c configuration.  This tries to make the configuration file (cf.m4) be
c much more general, but I fear it is doomed to failure -- it may be
c better to just tell people to roll their own.
e
s 00000/00000/00005
d D 3.73 82/01/05 09:59:19 eric 92 91
c fix botch in UGLYUUCP code -- gave "remote from <dest>" instead of
c "remote from <source>"
e
s 00000/00000/00005
d D 3.72 82/01/01 18:39:43 eric 91 90
c know about all known Berknet host names so that we can handle the "."
c notation happily in the full name representation.
e
s 00000/00000/00005
d D 3.71 82/01/01 18:27:15 eric 90 89
c send to dead.letter using sendto/recipient/deliver mechanism rather
c than mailfile; this fixes a bug with the "from" name and seems like
c a better abstraction.
e
s 00002/00000/00003
d D 3.70 81/12/06 12:39:10 eric 89 88
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00000/00000/00003
d D 3.69 81/12/05 14:14:06 eric 88 87
c insert SMTP "Mail-From:" line.
e
s 00000/00000/00003
d D 3.68 81/12/05 11:53:41 eric 87 86
c put the SMTP and queueing code on compilation flags so that sendmail
c will fit on non-ID PDP-11's (ugh); put the ugly UUCP hack on a
c compilation flag also to emphasize that it sucks eggs; makefile
c cleanup.
e
s 00000/00000/00003
d D 3.67 81/11/27 21:37:05 eric 86 85
c this is a stupid hack to put "remote from <host>" lines on the From
c lines going to UUCP mail.  someday i hope to rip out this stupidity.
c it is triggered by any mailer named "uucp" -- it ought to be a special
c flag, but i refuse to legitimize antique hacky mistakes.
e
s 00000/00000/00003
d D 3.66 81/11/22 19:17:45 eric 85 84
c Edit queue control files when running queue (assuming there are still
c recipients left).  Also, modify the MsgPriority to be the absolute
c number (not the Priority: value); this allows us to include aging into
c the priority algorithm.
e
s 00000/00000/00003
d D 3.65 81/11/21 18:42:47 eric 84 83
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00000/00000/00003
d D 3.64 81/11/21 16:38:29 eric 83 82
c convert to SMTP draft 3 -- finishing touches.  Punt on the VRFY/
c EXPN commands for now; they aren't required anyhow.  Move the fullname
c into the address structure so it can be inherited.
e
s 00000/00000/00003
d D 3.63 81/11/11 20:24:07 eric 82 81
c integrate user SMTP into sendmail itself.  If there is no $u arg
c in the mailer argument list, SMTP is run.  This can be used directly
c over the Ethernet or to any clever mailer.  We still need to edit
c spooled control files to remove recipients that have been successfully
c sent during queue processing.
e
s 00000/00000/00003
d D 3.62 81/11/08 13:00:21 eric 81 80
c know about SMTP over TCP.  The current SMTP user is not clever
c enough to deal with multiple users at one host.  To fix this we will
c have to speak some smart protocol between sendmail and the mailer --
c maybe SMTP??
e
s 00000/00000/00003
d D 3.61 81/11/07 15:41:39 eric 80 79
c clean up to compile & work on ARPAVAX; move stat file to
c /usr/lib/sendmail.st; fix bug in syserr with error codes
e
s 00000/00000/00003
d D 3.60 81/10/31 22:12:47 eric 79 78
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00000/00000/00003
d D 3.59 81/10/27 12:24:51 eric 78 77
c experimental version combining queueing with daemon operation.
c I'm sure this doesn't work -- if only because the wait()s are funny.
e
s 00000/00000/00003
d D 3.58 81/10/27 10:50:52 eric 77 76
c More queueing cleanup: implement timeouts (still one-stage),
c properly implement priorities (didn't work before), and miscellaneous
c cleanup.
e
s 00000/00000/00003
d D 3.57 81/10/26 14:22:34 eric 76 75
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00000/00000/00003
d D 3.56 81/10/23 19:38:09 eric 75 74
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00000/00000/00003
d D 3.55 81/10/22 10:25:29 eric 74 73
c move stats file to /usr/lib; put location of sendmail.hf in conf.c
e
s 00000/00000/00003
d D 3.54 81/10/22 09:43:48 eric 73 72
c take fullname from /etc/passwd if Smtp mode and sender name
c is indeed local.  Also accepts names more often; this is probably
c a disaster for sender verification.
e
s 00000/00000/00003
d D 3.53 81/10/22 09:14:30 eric 72 71
c implement HELP and MRSQ -- MRSQ is a partial implementation
c of old MTP -- in particular, To: fields in MAIL commands are not yet
c implemented.  The "message" routine now takes first args of the form
c "999-" to specify continuation.
e
s 00000/00000/00003
d D 3.52 81/10/20 11:36:24 eric 71 70
c clean up the SMTP stuff some more
e
s 00000/00000/00003
d D 3.51 81/10/19 22:27:17 eric 70 69
c implement SMTP mode -- doesn't support source routing or the
c HELP command, and doesn't give the correct code on VRFY or forwarding.
c Maybe someday....
e
s 00000/00000/00003
d D 3.50 81/10/17 16:58:04 eric 69 68
c initial prep to put in Daemon mode
e
s 00000/00000/00003
d D 3.49 81/10/12 10:04:19 eric 68 67
c throw in some "errno = 0;"'s to make syserr's more accurate;
c take any -f flag if debug mode and uid==euid.
e
s 00000/00000/00003
d D 3.48 81/10/08 22:55:37 eric 67 66
c ignore interrupts and hangups while calling mailer.
e
s 00000/00000/00003
d D 3.47 81/10/08 09:13:30 eric 66 65
c fix botch in backup code during rewriting
e
s 00000/00000/00003
d D 3.46 81/10/06 19:12:57 eric 65 64
c change rewriting rules to use $N on RHS to match LHS, and include
c $=X (class match) in the matching; this will allow us to match the
c proposed "user.host@domain" syntax as well as the old syntax, by
c putting the known domains into a class to disambiguate.
e
s 00000/00000/00003
d D 3.45 81/10/02 11:05:21 eric 64 63
c arrange to give the correct "from" person on error messages.
e
s 00000/00000/00003
d D 3.44 81/10/02 10:07:38 eric 63 62
c use ruleset 2 to rewrite names after the $g translate (to fix some
c forwarding problems; do a read check in putmessage (just in case
c the temp file disappeared); some general cleanup.
e
s 00000/00000/00003
d D 3.43 81/09/30 10:00:20 eric 62 61
c fix the <> syntax, convert "at" to "@" in from addresses also,
c plus some minorness to get the multi-machine case going nicely.
e
s 00000/00000/00003
d D 3.42 81/09/29 18:22:25 eric 61 60
c change processing of From: person; basically, this mod deletes the
c Original-From: line if redundant with the generated From: line, uses
c the Original-From: line for the From: line if possible, and a host of
c other such trivialities.
e
s 00000/00000/00003
d D 3.41 81/09/29 14:59:00 eric 60 59
c fix hash function computation for symbol table on 16-bit machines
e
s 00000/00000/00003
d D 3.40 81/09/28 19:17:29 eric 59 58
c enable aliases to self-reference themselves correctly.
e
s 00000/00000/00003
d D 3.39 81/09/24 10:30:44 eric 58 56
c changes to work under a V6 system -- mostly compilation flags
e
s 00000/00000/00003
d D 3.38.1.1 81/09/23 18:23:19 eric 57 56
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00000/00000/00003
d D 3.38 81/09/23 09:52:23 eric 56 55
c fix bug in file modes when mailing to files that didn't exist before;
c add an 'F' line to the .cf file that will read class entries from
c another file, given a scanf string to do the parsing.
e
s 00000/00000/00003
d D 3.37 81/09/22 13:24:25 eric 55 54
c fix problem with using macros in rules; change configuration to send
c different flags when destined for arpanet vs. berknet hosts, etc.
e
s 00000/00000/00003
d D 3.36 81/09/22 11:33:29 eric 54 53
c finally make suppression of sender in mailing lists work -- this version
c also works correctly on simple aliases.
e
s 00000/00000/00003
d D 3.35 81/09/21 18:49:53 eric 53 52
c fix suppression of from address in mailing lists.
e
s 00000/00000/00003
d D 3.34 81/09/20 10:46:32 eric 52 51
c don't let a mailer ever execute as root (that should solve the
c security problems!) -- essentially just map root into someone else.
c Adds yet another configuration variable (should this be in the .cf file?
e
s 00000/00000/00003
d D 3.33 81/09/16 20:04:26 eric 51 50
c take underscore as well as space to separate parts of a person's
c full name.  Dot notation should be made to work someday also.
e
s 00000/00000/00003
d D 3.32 81/09/16 17:16:19 eric 50 49
c have .forward ownership stick harder than :include: ownership:
c this prevents cretins from using writable root files for nastiness.
c all this is pointless if /usr/lib/aliases is writable though....
e
s 00000/00000/00003
d D 3.31 81/09/16 16:39:44 eric 49 48
c be REALLY clever and inherit uid/gid from owner of :include:
c files also...   solves problem of alias to non-secure file
e
s 00000/00000/00003
d D 3.30 81/09/16 16:24:19 eric 48 47
c last delta was too paranoid -- this increases the number of
c cases that work (but is still safe -- I hope)
e
s 00000/00000/00003
d D 3.29 81/09/16 16:08:08 eric 47 46
c run as the user forwarding mail after a .forward operation;
c fix a bug in .forwarding that caused recursive expansion;
c restrict mail to programs, files, and with :include: for security
c reasons.
e
s 00000/00000/00003
d D 3.28 81/09/14 12:41:28 eric 46 45
c check MAXATOM overflow; increase MAXATOM value
e
s 00000/00000/00003
d D 3.27 81/09/14 12:19:23 eric 45 44
c fix but in mailers that only take one address at a time
e
s 00000/00000/00003
d D 3.26 81/09/12 17:34:05 eric 44 43
c match on full name for local users
e
s 00000/00000/00003
d D 3.25 81/09/12 15:48:57 eric 43 42
c change From: processing to reduce the number of Original-From:
c lines; change allocation of global variables.
e
s 00000/00000/00003
d D 3.24 81/09/07 14:12:48 eric 42 41
c fix up umask; allow setuid on files to take recipient owner;
c factor some configuration info into conf.c
e
s 00000/00000/00003
d D 3.23 81/09/07 12:33:38 eric 41 40
c add auto-rebuild on alias database; fix some aliasing bugs;
c add statistics to rebuild; slight code restructuring; change
c version handling one last (?) time
e
s 00000/00000/00003
d D 3.22 81/09/07 10:23:04 eric 40 39
c add NOTUNIX compile flag to turn off UNIX "From " line processing
e
s 00000/00000/00003
d D 3.21 81/09/06 19:50:23 eric 39 38
c cleanup, commenting, linting, etc.
e
s 00000/00000/00003
d D 3.20 81/09/06 14:23:20 eric 38 37
c improve "version:" entry in makefile; fix -em (mail back errors) option
e
s 00000/00000/00003
d D 3.19 81/09/06 10:29:49 eric 37 36
c fix $u argument processing bug (happened in uucp); .cf file cleanup
e
s 00000/00000/00003
d D 3.18 81/08/31 21:22:39 eric 36 35
c collect mail statistics; minor configuration changes
e
s 00000/00000/00003
d D 3.17 81/08/31 12:11:57 eric 35 34
c allow "error" as a net name to print error messages
e
s 00000/00000/00003
d D 3.16 81/08/29 19:16:24 eric 34 33
c drop unnecessary H_FORCE bits in conf.c; delete H_DELETE
c (since H_ACHECK can be used with a zero mask field)
e
s 00000/00000/00003
d D 3.15 81/08/27 11:42:58 eric 33 32
c on -t, use argument list as a supress list
e
s 00000/00000/00003
d D 3.14 81/08/25 16:06:37 eric 32 31
c change handling of <LWSP> characters; remove special
c "at" processing (put it in .cf file)
e
s 00000/00000/00003
d D 3.13 81/08/24 14:05:39 eric 31 30
c Add "-t" option to read To:, Cc:, and Bcc: lines to get recipients
e
s 00000/00000/00003
d D 3.12 81/08/23 12:08:53 eric 30 29
c plug assorted security holes
e
s 00000/00000/00003
d D 3.11 81/08/22 17:52:06 eric 29 28
c Arrange to pull full name out of From line if found; includes
c Original-From: hacking (oh so ugly).  There's got to be a better way
c to do this...
e
s 00000/00000/00003
d D 3.10 81/08/22 14:45:27 eric 28 27
c fix UNIX From line parsing problem; add $b macro to get
c correct dates; fix mail-to-file problem; define basic macros
c before cracking arguments so that -D is more useful
e
s 00000/00000/00003
d D 3.9 81/08/21 18:51:33 eric 27 26
c return transcript even if no message was collected
e
s 00000/00000/00003
d D 3.8 81/08/21 18:23:53 eric 26 25
c drop M_FINAL, add $y=ttyname, rename some constants
e
s 00000/00000/00003
d D 3.7 81/08/20 15:19:50 eric 25 24
c internal cleanup & minor improvements
e
s 00000/00000/00003
d D 3.6 81/08/18 11:40:37 eric 24 23
c allow :include: specs
e
s 00000/00000/00003
d D 3.5 81/08/17 11:02:12 eric 23 22
c implement hashing in symbol table and add more headers, from
c BB&N Report No. ICST/CBOS - 80/2, "Specification of a Draft Message
c Format Standard (Draft Report)", prepared for NBS.
e
s 00000/00000/00003
d D 3.4 81/08/09 19:08:25 eric 22 21
c put mailer definitions into configuration file
e
s 00003/00001/00000
d D 3.3 81/03/28 11:52:37 eric 21 20
c change format of Version to be suitable for internal use
e
s 00001/00001/00000
d D 3.2 81/03/20 09:45:43 eric 20 19
c change name (again); from postbox to sendmail
e
s 00001/00001/00000
d D 3.1 81/03/07 14:27:18 eric 19 18
c ----- delivermail ==> postbox -----
e
s 00000/00000/00001
d D 2.8 81/02/28 11:54:11 eric 18 17
c install VAX mpx file logging
e
s 00000/00000/00001
d D 2.7 81/02/05 08:01:25 eric 17 16
c always issued a delivermail error message regardless of M_QUIET
e
s 00000/00000/00001
d D 2.6 81/01/10 14:28:41 eric 16 15
c include ArpaLocal; flush output on errors; allow
c "user" "at" "host" as separate parameters; etc.
e
s 00000/00000/00001
d D 2.5 81/01/08 23:57:31 eric 15 14
c fixed botch in at => @ translation
e
s 00000/00000/00001
d D 2.4 81/01/08 19:37:22 eric 14 13
c fixed several bugs in parser; translate <lwsp> into quoted .
e
s 00000/00000/00001
d D 2.3 80/12/06 17:33:32 eric 13 12
c fix ^D botch in maketemp; allow "eric:eric,i.eric"
e
s 00000/00000/00001
d D 2.2 80/11/20 19:57:57 eric 12 11
c make dates be taken as date sent rather than date delivered
e
s 00000/00000/00001
d D 2.1 80/11/05 11:00:06 eric 11 10
c release 2
e
s 00000/00000/00001
d D 1.10 80/10/28 23:52:38 eric 10 9
c fixed ANOTHER bug in aliasing (this is getting dull....)
e
s 00000/00000/00001
d D 1.9 80/10/27 19:28:30 eric 9 8
c fix alias bug; count message sizes; map stderr->stdout; misc.
e
s 00000/00000/00001
d D 1.8 80/10/21 12:58:43 eric 8 7
c install dbm stuff + fix quoting bugs
e
s 00000/00000/00001
d D 1.7 80/10/18 16:48:51 eric 7 6
c cleanup for dbm stuff: Error => Errors; move local host
c detection into parse; misc cleanup
e
s 00000/00000/00001
d D 1.6 80/10/15 10:24:24 eric 6 5
c deal with disk overflows
e
s 00000/00000/00001
d D 1.5 80/10/11 20:10:44 eric 5 4
c fixed problem with sizeof MsgId == 0
e
s 00000/00000/00001
d D 1.4 80/10/11 18:55:35 eric 4 3
c cleanup to simplify distribution
e
s 00000/00000/00001
d D 1.3 80/10/11 13:49:55 eric 3 2
c accept multi-line fields in headers
e
s 00000/00000/00001
d D 1.2 80/10/11 13:37:53 eric 2 1
c test
e
s 00001/00000/00000
d D 1.1 80/10/11 13:34:43 eric 1 0
e
u
U
f b 
f i 
f t SendMail
t
T
I 89
D 423
# ifndef lint
E 89
I 1
D 19
char	Version[] = "%Z%Delivermail version %I% of %G%";
E 19
I 19
D 20
char	Version[] = "%Z%PostBox version %I% of %G%";
E 20
I 20
D 21
char	Version[] = "%Z%SendMail version %I% of %G%";
E 21
I 21
static char	SccsId[] = "%Z%%Y% version %I% of %G%";
I 89
# endif lint
E 423
I 423
/*
I 483
 * Copyright (c) 1983 Eric P. Allman
E 483
D 482
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 482
I 482
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 483
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 483
I 483
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
E 483
 */
E 482

#ifndef lint
D 482
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 482
I 482
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 482
E 423
E 89

D 326
char	Version[] = "%I% [%G%]";
E 326
I 326
char	Version[] = "%I%";
E 326
E 21
E 20
E 19
E 1
