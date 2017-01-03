h08908
s 00001/00001/00026
d D 1.2 85/08/12 11:41:59 miriam 2 1
c Remove .ARPA from S16 as $D externalizes the name already.
e
s 00027/00000/00000
d D 1.1 85/08/12 10:53:41 miriam 1 0
c date and time created 85/08/12 10:53:41 by miriam
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
#####		MMDF Phonenet Channel Mailer specification
#####
############################################################
############################################################

Mmmdf,	P=/usr/lib/mmdf/sendmmdf, F=sDFMu, S=16, R=16, A=sendmmdf $f $h $u

S16
D 2
R$+<@$-.LOCAL>		$@$1<@$2.$D.ARPA>		externalize local names
E 2
I 2
R$+<@$-.LOCAL>		$@$1<@$2.$D>			externalize local names
E 2
R$+<@$+>		$@$1<@$2>			already ok
R$+			$@$1<@Berk-Test>		tack on our hostname
E 1
