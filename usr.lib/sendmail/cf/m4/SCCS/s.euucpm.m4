h18541
s 00001/00001/00030
d D 1.2 85/11/02 12:30:33 miriam 2 1
c Don't pass recipient through ruleset 15.
e
s 00031/00000/00000
d D 1.1 85/08/12 10:48:00 miriam 1 0
c date and time created 85/08/12 10:48:00 by miriam
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
#####		Smart UUCP Mailer specification
#####
#####	The other end must speak domain-based  addresses for
#####	this to work.  Someday this should become the "suucp"
#####	mailer, and we should be able to select by host name.
#####
############################################################
############################################################

D 2
Muucp,	P=/usr/bin/uux, F=sDFMhu, S=15, R=15, M=100000,
E 2
I 2
Muucp,	P=/usr/bin/uux, F=sDFMhu, S=15, M=100000,
E 2
	A=uux - -r $h!rmail ($u)

S15
R$*<@$+>$*		$@$1<@$2>$3			accept usual domain name
R$+			$:$1<@$U.UUCP>			stick on our host name
E 1
