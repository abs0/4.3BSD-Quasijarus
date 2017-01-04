h14320
s 00001/00005/00052
d D 1.13 00/03/27 09:47:17 msokolov 13 12
c remove unnecessary extra canonicalization hop and fix the special error address
e
s 00001/00001/00056
d D 1.12 00/03/27 09:29:33 msokolov 12 11
c INTERNET_RELAY, ARPAKLUDGE, and nicregistered.m4 go away, tcp & tcpld => smtp
e
s 00000/00000/00057
d D 1.11 00/03/27 09:02:49 msokolov 11 10
c bump it up to 1.11
e
s 00015/00010/00042
d D 1.10 00/03/27 09:02:32 msokolov 10 9
c deltas 1.10-1.11 have apparently been lost, reconstructing from g-file 1.11
e
s 00001/00001/00051
d D 1.9 87/09/01 10:02:51 phil 9 8
c Change @ to be returned with invalid address.
e
s 00002/00005/00050
d D 1.8 87/07/15 14:10:40 phil 8 7
c 
e
s 00005/00007/00050
d D 1.7 87/07/05 20:04:08 phil 7 6
c Removed LOCAL cruft.
e
s 00003/00005/00054
d D 1.6 86/02/26 07:49:57 bloom 6 5
c get rid of OZ domain, pass a bit less off to the nameserver
e
s 00003/00000/00056
d D 1.5 86/02/24 13:35:46 bloom 5 4
c canonicalize using the nameserver early
e
s 00003/00001/00053
d D 1.4 85/12/09 10:43:52 miriam 4 3
c Resolve number internet address to the name and check to see if sending 
c to ourself.
e
s 00001/00001/00053
d D 1.3 85/10/25 12:05:00 miriam 3 2
c Correct user@local to match on 1 token.
e
s 00001/00000/00053
d D 1.2 85/10/24 16:39:01 miriam 2 1
c For handling "LOCAL" machine.
e
s 00053/00000/00000
d D 1.1 85/08/08 15:31:24 miriam 1 0
c date and time created 85/08/08 15:31:24 by miriam
e
u
U
t
T
I 1
divert(10)
#
D 10
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 10
I 10
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 10
#
D 10
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
E 10
I 10
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
E 10
#
#	%W% (Berkeley) %G%
#
divert(0)
############################################################
############################################################
#####
#####		RULESET ZERO PREAMBLE
#####
#####	The beginning of ruleset zero is constant through all
#####	configurations.
#####
############################################################
############################################################

S0

D 13
# first make canonical
R$*<$*>$*		$1$2$3				defocus
R$+			$:$>3$1				make canonical

E 13
D 7
# handle special cases.....
E 7
I 7
# handle special cases
E 7
I 4
D 10
R$*<@[$+]>$*		$:$1<@$[[$2]$]>$3		lookup numeric internet addr
E 10
I 10
R$*<@[$+]>$*		$:$1<@$[[$2]$]>$3		numeric internet addr
E 10
D 12
R$*<@[$+]>$*		$#tcp$@[$2]$:$1@[$2]$3		numeric internet spec
E 12
I 12
R$*<@[$+]>$*		$#smtp$@[$2]$:$1@[$2]$3		numeric internet spec
E 12
R$+			$:$>6$1
E 4
I 2
D 3
R$*<@LOCAL>		$#local$:$1
E 3
I 3
D 7
R$-<@LOCAL>		$#local$:$1
E 7
I 7
R$-<@$w>		$#local$:$1
E 7
E 3
E 2
D 9
R@			$#local$:$n			handle <> form
E 9
I 9
D 13
R@			$#error$:Invalid address	handle <> form
E 13
I 13
R@			$#local$:$n			handle <> form
E 13
E 9
D 4
R$*<@[$+]>$*		$#tcp$@[$2]$:$1@[$2]$3		numeric internet spec
E 4

I 5
D 6
# canonicalize using the nameserver
R$*<@$+>$*		$:$1<@$[$2$]>$3

E 5
# hack for Australian addresses (avoid conflict with local host "oz")
R$*<@$+.OZ>$*		$1<@$2.OZ.AU>$3
E 6
I 6
# canonicalize using the nameserver if not internal domain
R$*<@$*.$~I>$*		$:$1<@$[$2.$3$]>$4
R$*<@$->$*		$:$1<@$[$2$]>$3
I 7
R$*<@$->$*		$:$1<@$2.$D>$3			if nameserver fails
E 7
E 6

D 7
# arrange for local names to be fully qualified
R$*<$+.ARPA.LOCAL>$*	$1<$2.ARPA>$3			because ARPA is a host

E 7
# now delete the local info
D 7
R$*<$*$=w.$=T>$*	$1<$2>$5			thishost.LOCAL
E 7
I 7
D 8
R$*<$*$w>$*		$1<$2>$3
E 7
R$*<$*$=w>$*		$1<$2>$4			thishost
R$*<$*.>$*		$1<$2>$3			drop trailing dot
R<@>:$*			$@$>0$1				retry after route strip
R$*<@>			$@$>0$1				strip null trash & retry
E 8
I 8
R<@$w>:$*		$@$>0$1				@here:... -> ...
R$*<@$w>		$@$>0$1				...@here -> ...
E 8
D 10

# forward around hosts with communication problems
D 7
R$*<@$=F.LOCAL>$*	$#tcp$@$F$:$1<@$2.LOCAL>$3	reroute message
E 7
I 7
R$*<@$=F>$*		$#tcp$@$F$:$1<@$2>$3		reroute message
E 10
E 7

##################################
#  End of ruleset zero preamble  #
##################################
E 1
