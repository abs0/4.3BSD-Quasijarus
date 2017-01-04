h10109
s 00001/00000/00120
d D 1.5 04/12/25 05:16:19 msokolov 5 4
c add msmlm to trusted users
e
s 00002/00000/00118
d D 1.4 00/03/27 09:48:32 msokolov 4 3
c me too!
e
s 00000/00000/00118
d D 1.3 00/03/27 08:44:19 msokolov 3 2
c bump it up to 1.3
e
s 00014/00011/00104
d D 1.2 00/03/27 08:44:02 msokolov 2 1
c deltas 1.2-1.3 have apparently been lost, reconstructing from g-file 1.3
e
s 00115/00000/00000
d D 1.1 85/08/08 15:31:15 miriam 1 0
c date and time created 85/08/08 15:31:15 by miriam
e
u
U
t
T
I 1
divert(10)
#
D 2
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 2
I 2
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 2
#
D 2
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
E 2
I 2
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
E 2
#
#	%W% (Berkeley) %G%
#
divert(0)
######################
#   Special macros   #
######################

# my name
DnMAILER-DAEMON
# UNIX header format
DlFrom $g  $d
# delimiter (operator) characters
Do.:%@!^=/[]
# format of a total name
Dq$g$?x ($x)$.
# SMTP login message
De$j Sendmail $v/$Z ready at $b

D 2
# forwarding host -- redefine this if you can't talk to the relay directly #
DF$R

E 2
###############
#   Options   #
###############

# location of alias file
OA/usr/lib/aliases
# wait up to ten minutes for alias file rebuild
Oa10
# substitution for space (blank) characters
OB.
# (don't) connect to "expensive" mailers
#Oc
# default delivery mode (deliver in background)
Odbackground
# temporary file mode
OF0600
# default GID
Og1
# location of help file
OH/usr/lib/sendmail.hf
# log level
OL9
# default network name
ONARPA
# default messages to old style
Oo
# queue directory
OQ/usr/spool/mqueue
# read timeout -- violates protocols
Or2h
# status file
OS/usr/lib/sendmail.st
# queue up everything before starting transmission
Os
# default timeout interval
OT3d
# time zone names (V6 only)
OtPST,PDT
# default UID
Ou1
# wizard's password
OW*
# load average at which we just queue messages
Ox8
# load average at which we refuse connections
OX12
I 4
# me too!
Om
E 4

###########################
#   Message precedences   #
###########################

Pfirst-class=0
Pspecial-delivery=100
Pbulk=-60
Pjunk=-100

#####################
#   Trusted users   #
#####################

Troot
Tdaemon
Tuucp
I 5
Tmsmlm
E 5
D 2
Teric
Tnetwork
E 2

#########################
#   Format of headers   #
#########################

H?P?Return-Path: <$g>
HReceived: $?sfrom $s $.by $j ($v/$Z)
	id $i; $b
H?D?Resent-Date: $a
H?D?Date: $a
H?F?Resent-From: $q
H?F?From: $q
H?x?Full-Name: $x
HSubject:
# HPosted-Date: $a
# H?l?Received-Date: $b
H?M?Resent-Message-Id: <$t.$i@$j>
H?M?Message-Id: <$t.$i@$j>

E 1
