h34643
s 00000/00001/00028
d D 1.4 87/11/04 16:15:36 phil 4 3
c Nuked a line that was never being matched, and that was 
c wrong anyway.
e
s 00001/00007/00028
d D 1.3 87/07/05 20:06:05 phil 3 2
c Removed LOCAL cruft, removed C class for bitnet.
e
s 00001/00000/00034
d D 1.2 85/10/25 12:36:11 miriam 2 1
c Strip @LOCAL
e
s 00034/00000/00000
d D 1.1 85/08/08 18:51:33 miriam 1 0
c date and time created 85/08/08 18:51:33 by miriam
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
#####		Provide Backward Compatibility
#####
############################################################
############################################################

#####################################################
#  General code to convert back to old style names  #
#####################################################
S5

D 3
#R$+<@$-.LOCAL>		$2:$1				u@h.LOCAL => h:u
I 2
R$+<@LOCAL>		$1				strip LOCAL
E 2
R$+<@$+.LOCAL>		$1<@$2>
R$+<@$=Z>		$@$2:$1				u@bhost => h:u
R$+<@$=C>		$@$2:$1				u@cchost => h:u
R$+<@$-.Bitnet>		$C!$2:$1			u@h.Bitnet => cfo-relay!h:u
R$+<@$-.CC>		$C!$2:$1			u@h.CC => cfo-relay!h:u
E 3
I 3
R$+<@$w>		$1				strip host
E 3
R$+<@$-.UUCP>		$2!$1				u@host.UUCP => host!u
D 4
R$+@$+.ARPA		$1@$2				u@host.ARPA => u@host
E 4
E 1
