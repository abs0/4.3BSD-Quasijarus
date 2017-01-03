h52586
s 00005/00005/00041
d D 1.2 87/07/05 14:10:24 phil 2 1
c Changed A to D.
e
s 00046/00000/00000
d D 1.1 85/08/12 10:43:38 miriam 1 0
c date and time created 85/08/12 10:43:38 by miriam
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
#####		UUCP Smart Mailer specification
#####		(handles multiple recipients)
#####
############################################################
############################################################



Msuucp,	P=/usr/bin/uux, F=mDFMhuU, S=13, R=23, M=100000,
	A=uux - -r $h!rmail ($u)

ifdef(`m4UUCP',`divert(10)',)

S13
R$+			$:$>5$1				convert to old style
R$=w!$+			$2				strip local name
D 2
R$*<@$=Z>$*		$1<@$2.$A>$3			resolve abbreviations
R$*<@$->$*		$1<@$2.$A>$3			resolve abbreviations
E 2
I 2
R$*<@$=Z>$*		$1<@$2.$D>$3			resolve abbreviations
R$*<@$->$*		$1<@$2.$D>$3			resolve abbreviations
E 2
R$+<@$+>		$2!$1				uucpize (no @'s in addr)
R$+			$:$U!$1				stick on our host name
R$=w!$=R:$+		$:$1!$3				ucbvax!ucbvax:xxx

S23
R$+			$:$>5$1				convert to old style
D 2
R$*<@$=Z>$*		$1<@$2.$A>$3			resolve abbreviations
R$*<@$=w>$*		$1<@$2.$A>$3			resolve abbreviations
R$*<@$->$*		$1<@$2.$A>$3			resolve abbreviations
E 2
I 2
R$*<@$=Z>$*		$1<@$2.$D>$3			resolve abbreviations
R$*<@$=w>$*		$1<@$2.$D>$3			resolve abbreviations
R$*<@$->$*		$1<@$2.$D>$3			resolve abbreviations
E 2
R$+<@$*$=w.EDU>		$2$3.EDU!$1			uucp!u@local -> local!uucp!u

ifdef(`m4UUCP',`divert(0)',)
E 1
