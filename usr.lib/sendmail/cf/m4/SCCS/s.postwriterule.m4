h17697
s 00001/00001/00037
d D 1.7 87/11/04 16:15:17 phil 7 6
c Removed a berkeley.edu dependency.
e
s 00000/00003/00038
d D 1.6 87/07/05 20:04:35 phil 6 5
c Removed LOCAL cruft.
e
s 00001/00001/00040
d D 1.5 86/07/21 14:31:26 bloom 5 4
c look for berkeley.edu and not ARPA
e
s 00003/00000/00038
d D 1.4 85/12/09 10:42:22 miriam 4 3
c Resolve numeric internet address to the name.
e
s 00001/00000/00037
d D 1.3 85/10/24 16:39:38 miriam 3 2
c For handling "LOCAL" machine.
e
s 00002/00002/00035
d D 1.2 85/08/08 18:20:28 miriam 2 1
c Use $w rather than $3 to get full expansion.
e
s 00037/00000/00000
d D 1.1 85/08/08 15:31:22 miriam 1 0
c date and time created 85/08/08 15:31:22 by miriam
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
#################################
#  Final Output Post-rewriting  #
#################################
S4

R@			$@				handle <> error addr

I 4
# resolve numeric addresses to name if possible
R$*<@[$+]>$*		$:$1<@$[[$2]$]>$3		lookup numeric internet addr

E 4
# externalize local domain info
I 3
D 6
R$*<@LOCAL>		$@$1@$w
E 3
R$*<$*LOCAL>$*		$1<$2$D>$3			change local info
R$*<$*LOCAL.ARPA>$*	$1<$2$D>$3			change local info
E 6
R$*<$+>$*		$1$2$3				defocus
R@$+:@$+:$+		@$1,@$2:$3			<route-addr> canonical

# UUCP must always be presented in old form (with domains, leave the ".uucp")
R$+@$-.UUCP		$2!$1				u@h.UUCP => h!u
R$+@$-.$-.UUCP		$2.$3.uucp!$1			u@h.UUCP => h!u
R$+@$-.$-.$-.UUCP	$2.$3.$4.uucp!$1		u@h.UUCP => h!u
R$+@$-.$-.$-.$-.UUCP	$2.$3.$4.$5.uucp!$1		u@h.UUCP => h!u
R$+@$-.$-.$-.$-.$-.UUCP	$2.$3.$4.$5.$6.uucp!$1		u@h.UUCP => h!u

# delete duplicate local names -- mostly for arpaproto.mc
D 2
R$+%$=w@$=w		$1@$3				u%UCB@UCB => u@UCB
R$+%$=w@$=w.ARPA	$1@$3.ARPA			u%UCB@UCB => u@UCB
E 2
I 2
R$+%$=w@$=w		$1@$w				u%UCB@UCB => u@UCB
D 5
R$+%$=w@$=w.ARPA	$1@$w				u%UCB@UCB => u@UCB
E 5
I 5
D 7
R$+%$=w@$=w.Berkeley.EDU	$1@$w			u%UCB@UCB => u@UCB
E 7
I 7
R$+%$=w@$=w.$D		$1@$w				u%UCB@UCB => u@UCB
E 7
E 5
E 2

E 1
