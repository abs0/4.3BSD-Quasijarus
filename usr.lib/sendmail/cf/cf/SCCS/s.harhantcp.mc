h52756
s 00006/00000/00010
d D 1.3 04/11/21 08:55:24 msokolov 3 2
c set new R and l policy options
e
s 00006/00118/00004
d D 1.2 02/05/29 18:42:18 msokolov 2 1
c The dogs and executioners of ORBS lie under the rubble of the Bastille,
c and for us the sun is shining in the beauty of its rays: harhantcp.mc is now
c like ucbtcp.mc again!
e
s 00122/00000/00000
d D 1.1 00/05/26 23:38:23 msokolov 1 0
c date and time created 00/05/26 23:38:23 by msokolov
e
u
U
t
T
I 1
divert(10)dnl
D 2
define(DOMAIN, `DDHarhan.ORG')
divert(0)dnl
E 2
#
D 2
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 2
I 2
# Generic configuration file for Harhan machines.
E 2
#
D 2
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
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 2
I 2
# %W% (Berkeley) %G%
E 2
#
D 2
#	%W% (Berkeley) %G%
#
sinclude(buildinfo)dnl
#
############################################################
############################################################
#####
#####		SENDMAIL CONFIGURATION FILE
#####
#####	For all IFCTF/Harhan hosts with ARPA TCP/SMTP
#####	connections only.
#####
#####
############################################################
############################################################


##################
#   local info   #
##################

`#' file containing our internet aliases
Fw/usr/lib/sendmail.cw

ifdef(`UUCP_NAME',
`#' uucp hostnames
UUCP_NAME
UUCP_ALIASES

`#' local UUCP connections
`include(UUCP_HOSTS_FILE)')

#############################
###   Setup Information   ###
#############################

include(../m4/nsmacros.m4)
include(../m4/nsclasses.m4)
include(../m4/version.m4)
include(../m4/boilerplate.m4)

###########################
###   Rewriting Rules   ###
###########################

include(../m4/prewriterule.m4)
include(../m4/postwriterule.m4)
include(../m4/rule3.m4)

###################
###   Mailers   ###
###################

include(../m4/localm.m4)
ifdef(`UUCP_ONLY',,
`include(../m4/smtpm.m4)')
ifdef(`UUCP_NAME',
`include(../m4/uucpm.m4)'
`include(../m4/rule5.m4)')
ifdef(`SMTPUUCP',
`include(../m4/smtpuucpm.m4)')

#####################
###   Rule Zero   ###
#####################

include(../m4/rule0.m4)

###############################################
###   Machine dependent part of Rule Zero   ###
###############################################

ifdef(`SMTPUUCP',
`# resolve SMTP UUCP connections'
`include(SMTPUUCP)')

ifdef(`UUCP_NAME',
`# resolve local UUCP connections'
`R<@$=V.UUCP>:$+		$#uucp$@$1$:$2				@host.UUCP:...'
`R$+<@$=V.UUCP>		$#uucp$@$2$:$1				user@host.UUCP'
)

ifdef(`UUCP_ONLY',,
`#' resolve fake top level domains by forwarding to other hosts
`include(../m4/fake_domains.m4)'

`ifdef(`UUCP_RELAY',
`#' forward non-local UUCP traffic to our UUCP relay
R$*<@$*.UUCP>$*		$`#'smtp$@$R$:$1<@$2.UUCP>	uucp mail)'

`#' block mail transactions with hosts identified as enemies of the people by
`#' the IFCTF Soviet of People's Commissars
R$*<@$*orbs.org>$*		$`#'error$:IFCTF does not allow mail transactions with ORBS hosts
R$*<@$*manawatu.co.nz>$*	$`#'error$:IFCTF does not allow mail transactions with ORBS hosts
R$*<@$*manawatu.net.nz>$*	$`#'error$:IFCTF does not allow mail transactions with ORBS hosts
R$*<@$*vuurwerk.nl>$*		$`#'error$:IFCTF does not allow mail transactions with ORBS hosts

`#' resolve SMTP traffic
R$*<@$+>$*		$`#'smtp$@$2$:$1<@$2>$3		user@host.domain)

# remaining names must be local
R$+			$#local$:$1			everything else
E 2
I 2
define(DOMAIN, `DDHarhan.ORG')
define(EXTERNAL_VERSION, ``#'	`%W%' (Berkeley) `%G%'')
divert(0)dnl
include(proto.mc)dnl
I 3

#########################
# Harhan policy options #
#########################
OR
Ol262144
E 3
E 2
E 1
