h21372
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

# first make canonical
R$*<$*>$*		$1$2$3				defocus
R$+			$:$>3$1				make canonical

D 7
# handle special cases.....
E 7
I 7
# handle special cases
E 7
I 4
R$*<@[$+]>$*		$:$1<@$[[$2]$]>$3		lookup numeric internet addr
R$*<@[$+]>$*		$#tcp$@[$2]$:$1@[$2]$3		numeric internet spec
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
R@			$#error$:Invalid address	handle <> form
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

# forward around hosts with communication problems
D 7
R$*<@$=F.LOCAL>$*	$#tcp$@$F$:$1<@$2.LOCAL>$3	reroute message
E 7
I 7
R$*<@$=F>$*		$#tcp$@$F$:$1<@$2>$3		reroute message
E 7

##################################
#  End of ruleset zero preamble  #
##################################
E 1
