divert(10)dnl
#
# Prototype configuration file for systems on TCP/IP (SMTP) based networks
# without any connection to UUCP, BITNET, or CSNET
#
# @(#)baretcpproto.mc	1.1 (Berkeley) 3/27/00
#
define(DOMAIN, `DDYOUR_DOMAIN_GOES_HERE')
define(EXTERNAL_VERSION, ``#'	`@(#)baretcpproto.mc	1.1' (Berkeley) `3/27/00'')
divert(0)dnl
include(proto.mc)dnl
