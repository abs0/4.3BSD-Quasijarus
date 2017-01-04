h48885
s 00016/00016/00089
d D 1.15 87/07/15 11:09:19 phil 16 15
c m4 includes now in ../m4
e
s 00003/00005/00102
d D 1.14 87/05/08 15:49:22 phil 15 14
c Changed foreign_networks into fake_domains, misc cleanup 
c after being hosed by a stray rdist ...
e
s 00001/00007/00106
d D 1.13 87/05/05 13:19:41 phil 14 13
c Now includes uucp.ucbarpa.m4
e
s 00001/00001/00112
d D 1.12 87/02/11 18:10:41 phil 13 12
c Fix S0 to support third level domains.
e
s 00001/00001/00112
d D 1.11 86/10/30 08:21:58 rwh 12 11
c Add kim and ucbkim to local name for arpa.
e
s 00006/00000/00107
d D 1.10 86/10/27 14:39:28 rwh 11 9
c Merge KIM's uucp over to ARPA.
e
s 00002/00002/00105
d R 1.10 86/09/30 11:31:48 rosen 10 9
c added Jim's hacks for third-level subdomains
e
s 00000/00012/00107
d D 1.9 86/08/11 11:02:18 bloom 9 8
c use MX records instead of explicitly listing routing
e
s 00002/00002/00117
d D 1.8 86/02/26 07:45:40 bloom 8 7
c Oz domain no longer used or allowed, start stamping out CC domain
e
s 00010/00006/00109
d D 1.7 86/01/03 12:40:45 bloom 7 6
c add mailer for local versus remote tcp
e
s 00001/00001/00114
d D 1.6 85/12/13 16:28:45 miriam 6 5
c Include "LOCAL" in the class of internet hostname.
e
s 00001/00001/00114
d D 1.5 85/11/20 12:06:34 miriam 5 4
c Change decwrl.arpa to decwrl.dec.com
e
s 00002/00001/00113
d D 1.4 85/11/15 14:41:21 miriam 4 3
c Correction for CC hosts.
e
s 00001/00029/00113
d D 1.3 85/11/13 16:22:33 miriam 3 2
c Use general rule0 with change in makefile to remove the unwanted 
c ruleset.
e
s 00001/00000/00141
d D 1.2 85/10/29 11:45:10 miriam 2 1
c Include the nic registered class.
e
s 00141/00000/00000
d D 1.1 85/08/13 16:42:51 miriam 1 0
c date and time created 85/08/13 16:42:51 by miriam
e
u
U
t
T
I 1
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
############################################################
############################################################
#####
#####		SENDMAIL CONFIGURATION FILE
#####
#####
############################################################
############################################################



##################
#   local info   #
##################

# internet hostname
D 6
Cwucbarpa arpa arpavax ucbarpavax r UCB-ARPA
E 6
I 6
D 12
Cwucbarpa arpa arpavax ucbarpavax r UCB-ARPA LOCAL
E 12
I 12
Cwucbarpa arpa arpavax ucbarpavax kim ucbkim r UCB-ARPA LOCAL
E 12
E 6

# uucp hostnames
DUucbarpa
CUucbarpa

# local UUCP connections
D 14
CWmetron
I 11
CWfranz
CWfateman
CWfisi
CWendotsew
CWfimus
CWinterlan
E 14
I 14
D 16
include(uucp.ucbarpa.m4)dnl
E 16
I 16
include(../m4/uucp.ucbarpa.m4)dnl
E 16
E 14
E 11

# we have full sendmail support here
Oa

#############################
###   Setup Information   ###
#############################

D 16
include(nsmacros.m4)
include(nsclasses.m4)
D 9
include(cchosts.m4)
E 9
I 2
include(nicregistered.m4)
E 2
D 9
include(berkhosts.m4)
E 9
include(version.m4)
include(boilerplate.m4)
E 16
I 16
include(../m4/nsmacros.m4)
include(../m4/nsclasses.m4)
include(../m4/nicregistered.m4)
include(../m4/version.m4)
include(../m4/boilerplate.m4)
E 16

###########################
###   Rewriting Rules   ###
###########################

D 16
include(prewriterule.m4)
include(postwriterule.m4)
include(rule3.m4)
E 16
I 16
include(../m4/prewriterule.m4)
include(../m4/postwriterule.m4)
include(../m4/rule3.m4)
E 16

###################
###   Mailers   ###
###################

D 16
include(localm.m4)
include(nstcpm.m4)
I 7
include(nstcpldm.m4)
E 7
include(mmdfm.m4)
include(euucpm.m4)
E 16
I 16
include(../m4/localm.m4)
include(../m4/nstcpm.m4)
include(../m4/nstcpldm.m4)
include(../m4/mmdfm.m4)
include(../m4/euucpm.m4)
E 16

#####################
###   Rule Zero   ###
#####################

D 3
S0
E 3
I 3
D 16
include(rule0.m4)
E 16
I 16
include(../m4/rule0.m4)
E 16
E 3

D 3
# first make canonical
R$*<$*>$*		$1$2$3				defocus
R$+			$:$>3$1				make canonical

# handle special cases.....
R@			$#local$:$n			handle <> form
R$*<@[$+]>$*		$#tcp$@[$2]$:$1@[$2]$3		numeric internet spec

# hack for Australian addresses (avoid conflict with local host "oz")
R$*<@$+.OZ>$*		$1<@$2.OZ.AU>$3

# arrange for local names to be fully qualified
R$*<$+.ARPA.LOCAL>$*	$1<$2.ARPA>$3			because ARPA is a host

# now delete the local info
R$*<$*$=w.$=T>$*	$1<$2>$5			thishost.LOCAL
# remove next line as it screws up arpa connections
# R$*<$*$=w>$*		$1<$2>$4			thishost
R$*<$*.>$*		$1<$2>$3			drop trailing dot
R<@>:$*			$@$>0$1				retry after route strip
R$*<@>			$@$>0$1				strip null trash & retry

# forward around hosts with communication problems
R$*<@$=F.LOCAL>$*	$#tcp$@$F$:$1<@$2.LOCAL>$3	reroute message

##################################
#  End of ruleset zero preamble  #
##################################
E 3
################################################
###  Machine dependent part of ruleset zero  ###
################################################

# resolve names we can handle locally
R<@$=W.UUCP>:$+		$#uucp$@$1$:$2			@host.UUCP:...
R$+<@$=W.UUCP>		$#uucp$@$2$:$1			user@host.UUCP

# pass test addresses off to MMDF
R$+@UDel-Test		$#mmdf$@UDel-Test$:$1		user.host@udel-relay

D 9
# resolve names destined for the computer center
D 4
R$*<@$+.CC>$*		$#tcp$@$C$:$1<@$2.CC>$3	user@host.CC
E 4
I 4
D 7
R$*<@$=C.berkeley.edu>$*	#tcp$@$C$:$1<@$2>$3
R$*<@$+.CC>$*		$#tcp$@$C$:$1<@$2>$3	user@host.CC
E 7
I 7
R$*<@$=C.berkeley.edu>$*	$#tcpld$@$C$:$1<@$2>$3
I 8
R$*<@$=C>$*		$#tcpld$@$C$:$1<@$2>$3
E 8
R$*<@$+.CC>$*		$#tcpld$@$C$:$1<@$2>$3	user@host.CC
E 7
E 4

# resolve names destined for berknet sites
D 7
R<@$=Z>:$+		$#tcp$@$B$:$2@$1		@berkhost: ...
R$+<@$=Z>		$#tcp$@$B$:$1@$2		user@berknethost
E 7
I 7
R<@$=Z>:$+		$#tcpld$@$B$:$2@$1		@berkhost: ...
R$+<@$=Z>		$#tcpld$@$B$:$1@$2		user@berknethost
E 7

E 9
D 15
# resolve explicit known foreign networks
D 8
R$*<@$+.Oz>$*		$#tcp$@seismo.css.gov$:$1<@$2.Oz>$3	down-under
R$*<@$+.Oz.au>$*	$#tcp$@seismo.css.gov$:$1<@$2.Oz>$3	down-under
E 8
I 8
D 9
R$*<@$+.Oz.au>$*	$#tcp$@seismo.css.gov$:$1<@$2.OZ.AU>$3	down-under
E 9
E 8
D 7
R$*<@$+.BITNET>$*	$#tcp$@$C$:$1<@$2.BITNET>$3	user@host.BITNET
E 7
I 7
R$*<@$+.BITNET>$*	$#tcpld$@$C$:$1<@$2.BITNET>$3	user@host.BITNET
E 7
R$*<@$+.CSNET>$*	$#tcp$@CSNET-RELAY.ARPA$:$1<@$2.CSNET>$3	user@host.CSNET
D 5
R$*<@$+.DEC>$*		$#tcp$@decwrl.ARPA$:$1<@$2.DEC>$3	user@host.DEC
E 5
I 5
R$*<@$+.DEC>$*		$#tcp$@decwrl.dec.com$:$1<@$2.DEC>$3	user@host.DEC
E 5
R$*<@$+.MailNET>$*	$#tcp$@MIT-Multics.ARPA$:$1<@$2.MailNET>$3	user@host.MailNET
E 15
I 15
# handle fake top level domains
D 16
include(fake_domains.m4)
E 16
I 16
include(../m4/fake_domains.m4)
E 16

E 15
D 7
R$*<@$*.UUCP>$*		$#tcp$@$F$:$1<@$2.UUCP>		uucp mail
E 7
I 7
R$*<@$*.UUCP>$*		$#tcpld$@$F$:$1<@$2.UUCP>		uucp mail

# local domain sites
D 13
R$*<@$*.berkeley.edu>$*	$#tcpld$@$2$:$1<@$2.$A>$3	user@host.berkeley.edu
E 13
I 13
R$*<@$*.$D>$*		$#tcpld$@$2.$D$:$1<@$2.$D>$3	user@host.berkeley.edu
E 13
E 7

# other non-local names 
R$*<@$+>$*		$#tcp$@$2$:$1<@$2>$3		user@some.where

# remaining names must be local
R$+			$#local$:$1			everything else

########################################
###  Host dependent address cleanup  ###
########################################

S8
R$*$=U!$+@$+		$3@$4				drop uucp forward

E 1
