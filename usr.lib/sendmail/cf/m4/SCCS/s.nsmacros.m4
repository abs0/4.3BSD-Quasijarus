h04703
s 00000/00007/00046
d D 1.11 00/03/27 09:33:18 msokolov 12 11
c INTERNET_RELAY, ARPAKLUDGE, and nicregistered.m4 go away, tcp & tcpld => smtp
e
s 00000/00000/00053
d D 1.10 00/03/27 08:51:41 msokolov 11 10
c bump it up to 1.10
e
s 00000/00000/00053
d D 1.9 00/03/27 08:51:27 msokolov 10 9
c bump it up to 1.10
e
s 00035/00015/00018
d D 1.8 00/03/27 08:51:09 msokolov 9 8
c deltas 1.8-1.10 have apparently been lost, reconstructing from g-file 1.10
e
s 00001/00001/00032
d D 1.7 88/04/08 11:50:29 phil 8 7
c Fully qualify major relay name.
e
s 00006/00002/00027
d D 1.6 87/07/05 20:56:19 phil 7 6
c Added ifdefs for INTERNET_RELAY and UUCP_RELAY.
e
s 00000/00006/00029
d D 1.5 87/07/05 20:07:57 phil 6 5
c Removed berknet, bitnet relay macros.
e
s 00003/00003/00032
d D 1.4 87/02/11 15:44:41 phil 5 3
c Change case on BERKELEY.EDU.
e
s 00002/00002/00033
d R 1.4 86/09/30 11:37:23 rosen 4 3
c added Jim's hacks for subdomains
e
s 00001/00001/00034
d D 1.3 86/03/12 09:55:56 bloom 3 2
c fix up berknet; are is through jade, onyx is through ucbvax
e
s 00001/00001/00034
d D 1.2 85/08/16 18:43:24 miriam 2 1
c Make local domain name to be .berkeley.edu
e
s 00035/00000/00000
d D 1.1 85/08/08 15:31:19 miriam 1 0
c date and time created 85/08/08 15:31:19 by miriam
e
u
U
t
T
I 1
divert(10)
#
D 9
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 9
I 9
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 9
#
D 9
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
E 9
I 9
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
E 9
#
#	%W% (Berkeley) %G%
#
divert(0)
######################
#   General Macros   #
######################

D 9
# our arpanet gateway
E 9
I 9
# local domain name
ifdef(`DOMAIN',
DOMAIN,
`#' YOUR DOMAIN NAME GOES HERE!
DDYOUR_DOMAIN_NAME)

E 9
D 5
DABERKELEY.EDU
E 5
I 5
D 7
DABerkeley.EDU
E 7
I 7
D 12
ifdef(`INTERNET_RELAY',
D 9
INTERNET_RELAY,
DAucbvax.Berkeley.EDU)
E 9
I 9
`#' Internet relay host -- machines in our domain that are not
`#' registered with the NIC will be "hidden" behind this relay machine
`#' with the % kludge`,' although SMTP delivery will still be performed
`#' by the sending machine.  Someday this will go away.
INTERNET_RELAY)
E 9
E 7
E 5

E 12
D 9
# local domain names
D 2
DDBERKELEY
E 2
I 2
D 5
DDBERKELEY.EDU
E 5
I 5
DDBerkeley.EDU
E 5
E 2

# major relay host
E 9
D 5
DRUCBVAX
E 5
I 5
D 7
DRucbvax
E 7
I 7
ifdef(`UUCP_RELAY',
D 9
UUCP_RELAY,
D 8
DRucbvax)
E 8
I 8
DRucbvax.Berkeley.EDU)
E 9
I 9
`#' UUCP relay host
UUCP_RELAY)

ifdef(`CSNET_RELAY',
`#' csnet relay host
CSNET_RELAY)

ifdef(`BITNET_RELAY',
`#' bitnet relay host
BITNET_RELAY)
E 9
E 8
E 7
E 5

D 6
# bitnet relay
DCjade

# berknet relay
D 3
DBjade
E 3
I 3
DB$R
E 3

E 6
# my official hostname
Dj$w

E 1
