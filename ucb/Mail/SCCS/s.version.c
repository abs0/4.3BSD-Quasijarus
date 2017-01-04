h26475
s 00000/00000/00022
d D 5.4 03/04/15 19:08:31 msokolov 23 22
c Nice support for KOI-7 (Russian) mail in a KOI-8 leaning UNIX environment
e
s 00011/00005/00011
d D 5.3 88/02/18 17:04:35 bostic 22 21
c written by Kurt Shoens; added Berkeley specific header
e
s 00001/00001/00015
d D 5.2 85/06/21 17:14:54 mckusick 21 20
c botched copyright
e
s 00010/00000/00006
d D 5.1 85/06/06 10:46:13 dist 20 19
c Add copyright
e
s 00000/00000/00006
d D 2.18 83/05/19 20:21:38 leres 19 18
c New version number to cover bug fixes up to 4.2 freeze
e
s 00000/00000/00006
d D 2.17 82/12/26 21:16:26 eric 18 17
c change delivermail to sendmail throughout
e
s 00000/00000/00006
d D 2.16 82/11/17 23:21:13 bush 17 16
c Updating version number for send fix release
e
s 00000/00000/00006
d D 2.15 82/07/29 09:29:56 kurt 16 15
c Added "ignore" command to suppress printing of selected header fields 
c 
e
s 00000/00000/00006
d D 2.14 82/07/28 16:08:44 kurt 15 14
c Version that works on pdp-11's 
c 
e
s 00000/00000/00006
d D 2.13 82/06/25 00:00:24 kurt 14 13
c This version of Mail eliminates a nasty bug which 
c caused core images if you used the -f flag with a name that 
c expand changed and then later used the "file" command to switch 
c to a file with a longer name since this would overrun the calloc'd space. 
c 
e
s 00000/00000/00006
d D 2.12 82/03/24 10:00:41 kurt 13 11
c conditional compilation from Eric Allman to retrofit signals 
c for PDP-11's without sigset. 
c 
e
s 00000/00000/00006
d R 2.12 82/03/24 09:59:53 kurt 12 11
c conditional compilation from Mark Horton to retrofit signals 
c for PDP-11 without sigset. 
c 
e
s 00000/00000/00006
d D 2.11 82/02/26 08:06:19 kurt 11 10
c +name as a recipient gets sent to a folder; 
c if -T is given, we now create the file immediately. 
c 
e
s 00000/00000/00006
d D 2.10 82/02/17 23:03:23 kurt 10 9
c changed the "maildir" option to "folder" 
c sped up folders command 
c made "folder" command print a folder as +folder rather than full path 
c 
e
s 00000/00000/00006
d D 2.9 82/02/14 19:50:30 kurt 9 8
c added command "folders" to list all your folders 
c 
e
s 00000/00000/00006
d D 2.8 82/02/14 19:26:47 kurt 8 7
c added command "folder" as a synonym for "file"; 
c added machine Kim to config table 
c 
e
s 00000/00000/00006
d D 2.7 82/02/13 21:25:52 kurt 7 6
c fixed so that the + filename convention can be used with -f; 
c made interpretation of maildir relative to home directory if not a 
c full pathname. 
c 
e
s 00000/00000/00006
d D 2.6 82/02/11 11:23:47 kurt 6 5
c Changed so that all file names used anywhere may begin with 
c a +, in which case they are interpreted relative to the user variable 
c maildir. 
c 
e
s 00002/00000/00004
d D 2.5 81/12/14 14:05:55 kurt 5 4
c Put in a nice identification string that will appear at 
c the beginning of an sccs what of Mail. 
c 
e
s 00000/00000/00004
d D 2.4 81/12/10 19:57:30 kurt 4 3
c Added code to adjust the number of headers printed on 
c start up according to speed of terminal; added option "screen" to 
c override this. 
c  
c Changed to print senders of uucp messages by only their home machine and name. 
c 
e
s 00000/00000/00004
d D 2.3 81/10/20 17:21:07 kurt 3 2
c This version of Mail is noticeable by changed prompt string. 
c 
e
s 00001/00001/00003
d D 2.2 81/09/09 13:52:40 kurt 2 1
c changed version string to be more generally useful
e
s 00004/00000/00000
d D 2.1 81/09/09 12:45:00 kurt 1 0
c date and time created 81/09/09 12:45:00 by kurt
e
u
U
f i 
t
T
I 1
/*
I 20
 * Copyright (c) 1980 Regents of the University of California.
D 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
 */

D 22
#ifndef lint
D 21
static char sccsid[] = "%W% (Berkeley) %G%";
E 21
I 21
static char *sccsid = "%W% (Berkeley) %G%";
E 21
#endif not lint
E 22
I 22
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 22

/*
E 20
 * Just keep track of the date/sid of this version of Mail.
I 5
 * Load this file first to get a "total" Mail version.
E 5
 */
I 5
static	char	*SccsID = "%Z%UCB Mail Version %I% (%G%)";
E 5
D 2
char	*version = "Version %R%.%L% %G%";
E 2
I 2
char	*version = "%R%.%L% %G%";
E 2
E 1
