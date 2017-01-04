h14930
s 00001/00000/00034
d D 1.2 86/03/06 16:43:22 bloom 2 1
c stop sending mail out as user%berkhost
e
s 00034/00000/00000
d D 1.1 85/11/08 16:46:23 miriam 1 0
c date and time created 85/11/08 16:46:23 by miriam
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
#####		Berknet Mailer specification
#####
############################################################
############################################################

Mberk,	P=/usr/net/bin/sendberkmail, F=fsDFMC, S=12, R=22, M=100000,
	A=sendberkmail -m $h -h $c -t $u

S12
R$+			$:$>5$1				convert to old style
R$-:$+			$@$1:$2				old berknet as is
R$+<@$+>		$@$1<@$2>			don't modify arpanet
R$-!$+			$@$1!$2				don't modify uucp
R<@$+>			$@<@$1>				don't modify <routeaddr>
R$+			$@$B:$1				make others relative

S22
R$+			$:$>5$1				convert to old style
I 2
R$*%$-			$:$>9$1%$2			convert % to @
E 2
E 1
