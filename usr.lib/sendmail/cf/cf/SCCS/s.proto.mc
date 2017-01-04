h54640
s 00003/00015/00106
d D 1.22 00/03/27 09:36:21 msokolov 23 22
c INTERNET_RELAY, ARPAKLUDGE, and nicregistered.m4 go away, tcp & tcpld => smtp
e
s 00000/00000/00121
d D 1.21 00/03/27 09:12:44 msokolov 22 21
c bump it up to 1.21
e
s 00000/00000/00121
d D 1.20 00/03/27 09:12:32 msokolov 21 20
c bump it up to 1.21
e
s 00000/00000/00121
d D 1.19 00/03/27 09:12:19 msokolov 20 19
c bump it up to 1.21
e
s 00000/00000/00121
d D 1.18 00/03/27 09:12:06 msokolov 19 18
c bump it up to 1.21
e
s 00036/00021/00085
d D 1.17 00/03/27 09:11:53 msokolov 18 17
c deltas 1.17-1.21 have apparently been lost, reconstructing from g-file 1.21
e
s 00004/00004/00102
d D 1.16 88/04/08 10:38:01 phil 17 16
c Only hide outgoing user@host.berkeley.edu if we're talking to 
c a host.arpa.  Thanks and a Tip of the Hat to Erik Fair for this.
e
s 00008/00001/00098
d D 1.15 88/03/31 22:13:28 phil 16 15
c Added smtpuucp support.
e
s 00002/00000/00097
d D 1.14 87/11/04 16:55:38 phil 15 14
c Added the build information.
e
s 00030/00014/00067
d D 1.13 87/07/15 10:50:40 phil 14 13
c Include uucp stuff.  ucbuucp.mc is now obsolete, and ucbtcp.cf
c can be made from this file by defining the appropriate M4 macros.
e
s 00005/00002/00076
d D 1.12 87/07/05 20:55:23 phil 13 12
c Added conditional ifdef for EXTERNAL_VERSION and INTERNET_ALIASES
e
s 00002/00002/00076
d D 1.11 87/05/08 15:49:29 phil 12 11
c Changed foreign_networks into fake_domains, misc cleanup 
c after being hosed by a stray rdist ...
e
s 00006/00007/00072
d D 1.10 87/04/25 22:55:47 phil 11 10
c Added foreign_networks include file.
e
s 00001/00001/00078
d D 1.9 87/02/11 15:45:13 phil 10 8
c Fix S0 to deal with third level domains.
e
s 00002/00002/00077
d R 1.9 86/09/30 11:40:00 rosen 9 8
c added Jim's subdomain hacks
e
s 00000/00012/00079
d D 1.8 86/07/21 14:43:44 bloom 8 7
c use MX records for CC and Berknet hosts
e
s 00002/00002/00089
d D 1.7 86/02/26 07:45:56 bloom 7 6
c Oz domain no longer used or allowed, start stamping out CC domain
e
s 00010/00006/00081
d D 1.6 86/01/03 12:40:49 bloom 6 5
c add mailer for local versus remote tcp
e
s 00001/00001/00086
d D 1.5 85/12/13 16:30:28 miriam 5 4
c Include "LOCAL" in the class of internet hostname.
e
s 00001/00001/00086
d D 1.4 85/11/20 12:06:08 miriam 4 3
c Change decwrl.arpa to decwrl.dec.com
e
s 00002/00001/00085
d D 1.3 85/11/15 14:44:12 miriam 3 2
c Correction for CC hosts.
e
s 00001/00000/00085
d D 1.2 85/10/29 11:47:08 miriam 2 1
c Include nic registered class.
e
s 00085/00000/00000
d D 1.1 85/08/09 16:05:33 miriam 1 0
c date and time created 85/08/09 16:05:33 by miriam
e
u
U
t
T
I 1
#
D 18
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 18
I 18
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 18
#
D 18
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
E 18
I 18
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
E 18
#
I 13
ifdef(`EXTERNAL_VERSION', EXTERNAL_VERSION, `#')
E 13
#	%W% (Berkeley) %G%
#
I 15
sinclude(buildinfo)dnl
#
E 15
############################################################
############################################################
#####
#####		SENDMAIL CONFIGURATION FILE
#####
############################################################
############################################################


D 18

E 18
##################
#   local info   #
##################

D 13
# internet hostname	REPLACE HOSTNAME WITH YOUR MACHINE NAME HERE
D 5
Cwucbmonet monet
E 5
I 5
Cwucbmonet monet LOCAL
E 13
I 13
D 18
ifdef(`INTERNET_ALIASES',
INTERNET_ALIASES,
D 14
`#' internet hostname	REPLACE HOSTNAME WITH YOUR MACHINE NAME HERE
E 14
I 14
`#' internet aliases	REPLACE HOSTNAME WITH YOUR MACHINE NAME HERE
E 14
Cwucbmonet monet)
E 18
I 18
`#' file containing our internet aliases
Fw/usr/lib/sendmail.cw
E 18
E 13
E 5

I 14
ifdef(`UUCP_NAME',
`#' uucp hostnames
UUCP_NAME
UUCP_ALIASES

`#' local UUCP connections
`include(UUCP_HOSTS_FILE)')

E 14
#############################
###   Setup Information   ###
#############################

D 14
include(nsmacros.m4)
include(nsclasses.m4)
D 8
include(cchosts.m4)
E 8
I 2
include(nicregistered.m4)
E 2
D 8
include(berkhosts.m4)
E 8
include(version.m4)
include(boilerplate.m4)
E 14
I 14
include(../m4/nsmacros.m4)
include(../m4/nsclasses.m4)
D 18
include(../m4/nicregistered.m4)
E 18
I 18
D 23
ifdef(`INTERNET_RELAY',
`include(../sitedep/nicregistered.m4)')
E 23
E 18
include(../m4/version.m4)
include(../m4/boilerplate.m4)
E 14

###########################
###   Rewriting Rules   ###
###########################

D 14
include(prewriterule.m4)
include(postwriterule.m4)
include(rule3.m4)
E 14
I 14
include(../m4/prewriterule.m4)
include(../m4/postwriterule.m4)
include(../m4/rule3.m4)
E 14

###################
###   Mailers   ###
###################

D 14
include(localm.m4)
include(nstcpm.m4)
I 6
include(nstcpldm.m4)
E 14
I 14
include(../m4/localm.m4)
I 18
ifdef(`UUCP_ONLY',,
D 23
`include(../m4/nstcpldm.m4)')
E 18
include(../m4/nstcpm.m4)
E 23
I 23
`include(../m4/smtpm.m4)')
E 23
D 18
include(../m4/nstcpldm.m4)
E 18
ifdef(`UUCP_NAME',
D 16
`include(../m4/uucpm.m4)')
E 16
I 16
`include(../m4/uucpm.m4)'
`include(../m4/rule5.m4)')
ifdef(`SMTPUUCP',
`include(../m4/smtpuucpm.m4)')
E 16
E 14
E 6

#####################
###   Rule Zero   ###
#####################

D 14
include(rule0.m4)
E 14
I 14
include(../m4/rule0.m4)
E 14

###############################################
###   Machine dependent part of Rule Zero   ###
###############################################
I 16

ifdef(`SMTPUUCP',
`# resolve SMTP UUCP connections'
`include(SMTPUUCP)')
E 16

I 14
ifdef(`UUCP_NAME',
`# resolve local UUCP connections'
`R<@$=V.UUCP>:$+		$#uucp$@$1$:$2				@host.UUCP:...'
`R$+<@$=V.UUCP>		$#uucp$@$2$:$1				user@host.UUCP'
)

E 14
D 8
# resolve names destined for the computer center
D 3
R$*<@$+.CC>$*		$#tcp$@$C$:$1<@$2.CC>$3	user@host.CC
E 3
I 3
D 6
R$*<@$=C.berkeley.edu>$*	$#tcp$@$C$:$1<@$2>$3
R$*<@$+.CC>$*		$#tcp$@$C$:$1<@$2>$3	user@host.CC
E 6
I 6
R$*<@$=C.berkeley.edu>$*	$#tcpld$@$C$:$1<@$2>$3
I 7
R$*<@$=C>$*		$#tcpld$@$C$:$1<@$2>$3
E 7
R$*<@$+.CC>$*		$#tcpld$@$C$:$1<@$2>$3	user@host.CC
E 6
E 3

# resolve names destined for berknet sites
D 6
R<@$=Z>:$+		$#tcp$@$B$:$2@$1		@berkhost: ...
R$+<@$=Z>		$#tcp$@$B$:$1@$2		user@berknethost
E 6
I 6
R<@$=Z>:$+		$#tcpld$@$B$:$2@$1		@berkhost: ...
R$+<@$=Z>		$#tcpld$@$B$:$1@$2		user@berknethost
E 6

E 8
D 11
# resolve explicit known foreign networks
D 7
R$*<@$+.Oz>$*		$#tcp$@seismo.css.gov$:$1<@$2.Oz>$3	down-under
R$*<@$+.Oz.au>$*	$#tcp$@seismo.css.gov$:$1<@$2.Oz>$3	down-under
E 7
I 7
D 8
R$*<@$+.Oz.au>$*	$#tcp$@seismo.css.gov$:$1<@$2.OZ.AU>$3	down-under
E 8
E 7
D 6
R$*<@$+.BITNET>$*	$#tcp$@$C$:$1<@$2.BITNET>$3	user@host.BITNET
E 6
I 6
R$*<@$+.BITNET>$*	$#tcpld$@$C$:$1<@$2.BITNET>$3	user@host.BITNET
E 6
R$*<@$+.CSNET>$*	$#tcp$@CSNET-RELAY.ARPA$:$1<@$2.CSNET>$3	user@host.CSNET
D 4
R$*<@$+.DEC>$*		$#tcp$@decwrl.ARPA$:$1<@$2.DEC>$3	user@host.DEC
E 4
I 4
R$*<@$+.DEC>$*		$#tcp$@decwrl.dec.com$:$1<@$2.DEC>$3	user@host.DEC
E 4
R$*<@$+.MailNET>$*	$#tcp$@MIT-Multics.ARPA$:$1<@$2.MailNET>$3	user@host.MailNET
D 6
R$*<@$*.UUCP>$*		$#tcp$@$F$:$1<@$2.UUCP>		uucp mail
E 6
I 6
R$*<@$*.UUCP>$*		$#tcpld$@$F$:$1<@$2.UUCP>		uucp mail
E 11
I 11
D 12
# resolve pseudo top-level domains by forwarding to other hosts
include(foreign_networks.m4)
E 12
I 12
D 18
# resolve fake top level domains by forwarding to other hosts
D 14
include(fake_domains.m4)
E 14
I 14
include(../m4/fake_domains.m4)
E 18
I 18
ifdef(`UUCP_ONLY',,
`#' resolve fake top level domains by forwarding to other hosts
`include(../m4/fake_domains.m4)'
E 18
E 14
E 12
E 11

I 11
D 18
# forward UUCP traffic to our UUCP gateway
R$*<@$*.UUCP>$*		$#tcpld$@$F$:$1<@$2.UUCP>	uucp mail
E 18
I 18
`ifdef(`UUCP_RELAY',
`#' forward non-local UUCP traffic to our UUCP relay
D 23
R$*<@$*.UUCP>$*		$`#'tcpld$@$R$:$1<@$2.UUCP>	uucp mail)'
E 23
I 23
R$*<@$*.UUCP>$*		$`#'smtp$@$R$:$1<@$2.UUCP>	uucp mail)'
E 23
E 18

E 11
D 17
# local domain sites
D 10
R$*<@$*.berkeley.edu>$*	$#tcpld$@$2$:$1<@$2.$A>$3	user@host.berkeley.edu
E 10
I 10
D 11
R$*<@$*.$D>$*		$#tcpld$@$2.$D$:$1<@$2.$D>$3	user@host.berkeley.edu
E 11
I 11
R$*<@$*.$D>$*		$#tcpld$@$2.$D$:$1<@$2.$D>$3	user@host.our.domain
E 17
I 17
D 18
# hide behind a gateway when talking to people who don't speak domains
R$*<@$*.arpa>$*		$#tcp$@$2.arpa$:$1<@$2.arpa>$3	user@host.arpa
E 18
I 18
D 23
`ifdef(`ARPAKLUDGE',
`#' hide behind our internet relay when talking to people in the arpa domain
R$*<@$*.arpa>$*		$`#'tcp$@$2.arpa$:$1<@$2.arpa>$3	user@host.arpa
E 18
E 17
E 11
E 10
E 6

D 17
# other non-local names 
R$*<@$+>$*		$#tcp$@$2$:$1<@$2>$3		user@some.where
E 17
I 17
D 18
# but don't hide if they do.
R$*<@$*>$*		$#tcpld$@$2$:$1<@$2>$3		user@host.domain
E 18
I 18
`#' but speak domains to them if they speak domains too
R$*<@$*>$*		$`#'tcpld$@$2$:$1<@$2>$3		user@host.domain,
E 23
`#' resolve SMTP traffic
D 23
`ifdef(`INTERNET_RELAY',
R$*<@$*.$D>$*		$`#'tcpld$@$2.$D$:$1<@$2.$D>$3	user@host.ourdomain
R$*<@$+>$*		$`#'tcp$@$2$:$1<@$2>$3		user@host.ourdomain,
R$*<@$+>$*		$`#'tcpld$@$2$:$1<@$2>$3	user@host.domain)')')
E 23
I 23
R$*<@$+>$*		$`#'smtp$@$2$:$1<@$2>$3		user@host.domain)
E 23
E 18
E 17

# remaining names must be local
R$+			$#local$:$1			everything else
E 1
