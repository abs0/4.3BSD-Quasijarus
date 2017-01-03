h20499
s 00000/00006/00023
d D 1.7 88/04/08 11:50:08 phil 7 6
c Domain and arpanet gateway classes no longer needed.
e
s 00001/00001/00028
d D 1.6 88/03/31 23:45:07 phil 6 5
c Remove DEC and MAILNET fake domains.
e
s 00005/00014/00024
d D 1.5 87/07/05 20:03:30 phil 5 4
c Removed K, P, T classes; removed some aliases.
e
s 00001/00001/00037
d D 1.4 86/07/21 16:22:41 bloom 4 3
c don't use EDU as a known local domain
e
s 00005/00002/00033
d D 1.3 86/02/26 07:48:54 bloom 3 2
c bye, bye OZ domain, start stamping out CC, add list of internal domains
e
s 00002/00002/00033
d D 1.2 86/01/23 10:53:59 rwh 2 1
c Add IL NET ORG UK US to class K and P.
e
s 00035/00000/00000
d D 1.1 85/08/08 15:31:18 miriam 1 0
c date and time created 85/08/08 15:31:18 by miriam
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
###############
#   Classes   #
###############

D 7
# our arpanet gateway
D 5
CABerkeley UCB ucbc70 c70 UCB-C70 u UCB-VAX ucbvax
E 5
I 5
CABerkeley
E 5

# local domain names
D 5
CDBERKELEY UCB ucbc70 c70 ucb-c70 u UCB-VAX ucbvax
E 5
I 5
CDBerkeley
E 5

E 7
# major relay host
D 5
CRucbvax vax k
E 5
I 5
CRucbvax vax
E 5

D 5
# all supported top-level domains
D 2
CKLOCAL ARPA UUCP BITNET CSNET EDU MIL COM GOV AU OZ
E 2
I 2
D 3
CKLOCAL ARPA UUCP BITNET CSNET EDU MIL COM GOV AU OZ IL NET ORG UK US
E 3
I 3
CKLOCAL ARPA UUCP BITNET CSNET EDU MIL COM GOV AU IL NET ORG UK US
E 3
E 2

# local domains
D 3
CTLOCAL ARPA UUCP BITNET CC CSNET EDU
E 3
I 3
D 4
CTLOCAL ARPA UUCP BITNET CSNET EDU
E 4
I 4
CTLOCAL ARPA UUCP BITNET CSNET
E 4
E 3

# legal Internet top-level domains
D 2
CPARPA EDU MIL GOV COM
E 2
I 2
CPARPA EDU MIL GOV COM IL NET ORG UK US
I 3

# Internal domains that we use in rewriting (not known by NIC)
CILOCAL UUCP BITNET CSNET DEC MailNET CC
E 5
I 5
# Internal ("fake") domains that we use in rewriting
D 6
CIUUCP BITNET CSNET DEC MailNET
E 6
I 6
CIUUCP BITNET CSNET
E 6
E 5
E 3
E 2

E 1
