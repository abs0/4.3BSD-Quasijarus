h19596
s 00000/00000/00026
d D 1.36 00/03/27 10:04:57 msokolov 36 35
c The prophecy has come true. HOSTS.TXT is gone, everyone uses DNS, and there are
c no more NIC-registered hosts to worry about. The old tcp mailer goes away and
c tcpld becomes smtp. Also some minor nits.
e
s 00000/00000/00026
d D 1.35 00/03/27 09:58:10 msokolov 35 34
c bump it up to 1.35
e
s 00000/00000/00026
d D 1.34 00/03/27 09:58:09 msokolov 34 33
c bump it up to 1.35
e
s 00000/00000/00026
d D 1.33 00/03/27 09:58:07 msokolov 33 32
c bump it up to 1.35
e
s 00000/00000/00026
d D 1.32 00/03/27 09:58:06 msokolov 32 31
c bump it up to 1.35
e
s 00000/00000/00026
d D 1.31 00/03/27 09:58:05 msokolov 31 30
c bump it up to 1.35
e
s 00000/00000/00026
d D 1.30 00/03/27 09:58:03 msokolov 30 29
c bump it up to 1.35
e
s 00015/00006/00011
d D 1.29 00/03/27 09:57:23 msokolov 29 28
c deltas 1.29-1.35 have apparently been lost, reconstructing from g-file 1.35
e
s 00000/00000/00017
d D 1.28 88/04/08 11:30:29 phil 28 27
c Don't hide outgoing hosts unless we're talking to a host.arpa. 
c Fully-qualify host names in the cf file to avoid resolver braindeath. 
c Add some smtpuucp pairs to ucbvax.  Update cogsci's uucp list.
e
s 00000/00000/00017
d D 1.27 88/03/31 23:41:22 phil 27 26
c Add smtpuucp mailer; remove a fake domain or two.
e
s 00000/00000/00017
d D 1.26 87/05/08 15:39:52 phil 26 25
c Cleanup after being rdisted from okeeffe.
e
s 00000/00000/00017
d D 1.25 87/04/28 09:01:55 phil 25 24
c Changed UUCP hosts on ucbvax per rwh, cleaned up nstcpm a bit.
e
s 00000/00000/00017
d D 1.24 87/04/25 23:07:47 phil 24 23
c UUCP hosts are now in separate files per uucp host.
c uucphosts.m4 is now generated automatically by including these files.
c Created "foreign_networks" which is included in ruleset 0 and hands
c off pseudo top-level domains to specific gateway hosts.
e
s 00000/00000/00017
d D 1.23 87/02/23 12:46:05 phil 23 22
c  Fixed uucp sender address (ucbvax!cory.berkeley.edu!user)
e
s 00000/00000/00017
d D 1.22 87/02/15 00:53:57 phil 22 21
c Added violet to N class, removed dali and kim.
e
s 00000/00000/00017
d D 1.21 87/02/11 18:10:52 phil 21 20
c Fix S0 to support third level domains.
e
s 00000/00000/00017
d D 1.20 87/01/06 15:15:24 rwh 20 19
c Add hoptoad to list of uucp sites fpr cogsci.
e
s 00000/00000/00017
d D 1.19 86/12/08 11:11:31 rwh 19 18
c Remove arizona from list of uucp sites.
e
s 00000/00000/00017
d D 1.18 86/10/17 10:23:47 rwh 18 17
c Changes in uucp hosts.
e
s 00000/00000/00017
d D 1.17 86/09/22 13:57:26 rwh 17 16
c Update uucp hosts and add cogsci as alternate uucp machine.
e
s 00000/00000/00017
d D 1.16 86/08/11 11:37:47 bloom 16 15
c berknet mail is defunct on ucbvax
e
s 00000/00000/00017
d D 1.15 86/07/21 14:45:51 bloom 15 14
c use MX records for CC and Berknet hosts
e
s 00000/00000/00017
d D 1.14 86/05/01 18:50:04 bloom 14 13
c use domain name instead of arpanet relay for domain name
e
s 00000/00000/00017
d D 1.13 86/04/28 16:22:15 rwh 13 12
c Change names on uucphosts.
e
s 00000/00000/00017
d D 1.12 86/04/03 10:56:09 rwh 12 11
c Added "cad" to uucphosts as well as "ucbcad"
e
s 00000/00000/00017
d D 1.11 86/03/12 09:57:52 bloom 11 10
c fix up berknet; are is through jade, onyx is through ucbvax
e
s 00000/00000/00017
d D 1.10 86/03/11 11:17:21 rwh 10 9
c Removed dagobah from list of uucp sites.
e
s 00000/00000/00017
d D 1.9 86/01/27 16:14:42 rwh 9 8
c Add name change to uucphosts.m4 "dagobah -> pixar"
e
s 00000/00000/00017
d D 1.8 86/01/23 10:58:13 rwh 8 7
c Added IL NET ORG UK US to class K and P in nsclasses.m4
e
s 00000/00000/00017
d D 1.7 85/11/21 09:50:28 miriam 7 6
c If $w does not include domain, then tack it on.
e
s 00000/00000/00017
d D 1.6 85/11/20 16:47:43 miriam 6 5
c Change rule 6 to convert user@local_host to user@local.
e
s 00000/00000/00017
d D 1.5 85/11/20 15:10:10 miriam 5 4
c Allow format any.domain!user
e
s 00000/00000/00017
d D 1.4 85/11/20 12:07:15 miriam 4 3
c Change decwrl.arpa to decwrl.dec.com
e
s 00000/00000/00017
d D 1.3 85/11/14 13:47:42 miriam 3 2
c Bump the version number to reflect lots of changes - ie I have 
c forgotten to do this.
e
s 00001/00001/00016
d D 1.2 85/08/09 16:12:06 miriam 2 1
c Correct version number to reflect name serve config files.
e
s 00017/00000/00000
d D 1.1 85/08/08 15:31:26 miriam 1 0
c date and time created 85/08/08 15:31:26 by miriam
e
u
U
t
T
I 1
divert(10)
#
D 29
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 29
I 29
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 29
#
D 29
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
E 29
I 29
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 29
#
#	%W% (Berkeley) %G%
I 29
#
E 29
divert(0)
######################
#   Version Number   #
######################

D 2
DZ5.6
E 2
I 2
DZ%I%
E 2
E 1
