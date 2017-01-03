h52833
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
divert(0)
######################
#   General Macros   #
######################

# our arpanet gateway
D 5
DABERKELEY.EDU
E 5
I 5
D 7
DABerkeley.EDU
E 7
I 7
ifdef(`INTERNET_RELAY',
INTERNET_RELAY,
DAucbvax.Berkeley.EDU)
E 7
E 5

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
D 5
DRUCBVAX
E 5
I 5
D 7
DRucbvax
E 7
I 7
ifdef(`UUCP_RELAY',
UUCP_RELAY,
D 8
DRucbvax)
E 8
I 8
DRucbvax.Berkeley.EDU)
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
