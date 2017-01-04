h54363
s 00000/00001/00013
d D 1.3 00/03/27 10:14:26 msokolov 3 2
c ARPAKLUDGE is gone
e
s 00000/00000/00014
d D 1.2 00/03/27 10:11:45 msokolov 2 1
c bump it up to 1.2
e
s 00014/00000/00000
d D 1.1 00/03/27 10:11:24 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 1.2
e
u
U
t
T
I 1
divert(10)dnl
#
# Prototype configuration file for systems on TCP/IP (SMTP) based networks
#
# %W% (Berkeley) %G%
#
define(DOMAIN, `DDYOUR_DOMAIN_GOES_HERE')
define(UUCP_RELAY, DRYOUR_UUCP_RELAY_GOES_HERE)
define(BITNET_RELAY, `DBYOUR_BITNET_RELAY_GOES_HERE')
define(CSNET_RELAY, `DCYOUR_CSNET_RELAY_GOES_HERE')
D 3
define(ARPAKLUDGE, `1')
E 3
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%'')
divert(0)dnl
include(proto.mc)dnl
E 1
