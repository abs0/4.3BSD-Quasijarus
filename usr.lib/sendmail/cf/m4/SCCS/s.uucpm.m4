h62446
s 00006/00005/00037
d D 1.10 87/11/11 14:14:55 phil 10 9
c Clean up UUCP stuff.
e
s 00003/00005/00039
d D 1.9 87/02/23 12:44:19 phil 9 8
c Sender addresses now of the form ucbvax!cory.berkeley.edu!user
c instead of ucbvax!user@cory.berkeley.edu.
e
s 00001/00001/00043
d D 1.8 86/08/08 13:35:53 bloom 8 7
c support subdomains a bit better
e
s 00005/00005/00039
d D 1.7 86/05/01 18:32:29 bloom 7 6
c use domain name instead of arpanet relay for domain name
e
s 00001/00000/00043
d D 1.6 85/11/08 12:07:22 miriam 6 5
c Rewrite address of user%host@berkeley.edu for outgoing uucp mail as 
c ucbvax!user@host.berkeley.edu.
e
s 00001/00000/00042
d D 1.5 85/11/06 10:01:17 miriam 5 4
c Correct outgoing address from "hiden" sites to be
c ucbvax!user@host.berkeley.edu
e
s 00002/00000/00040
d D 1.4 85/10/29 17:09:28 miriam 4 3
c Strip local name.
e
s 00000/00001/00040
d D 1.3 85/08/09 16:54:04 miriam 3 2
c Remove line with @ so not to confuse sendmails at uucp sites.
e
s 00003/00004/00038
d D 1.2 85/08/09 15:50:52 miriam 2 1
c Corrections for name server setup.
e
s 00042/00000/00000
d D 1.1 85/08/08 18:53:39 miriam 1 0
c date and time created 85/08/08 18:53:39 by miriam
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
#####		UUCP Mailer specification
#####
############################################################
############################################################


Muucp,	P=/usr/bin/uux, F=DFMhuU, S=13, R=23, M=100000,
	A=uux - -r -z -a$f -gC $h!rmail ($u)

S13
R$+			$:$>5$1				convert to old style
D 10
R$=w!$+			$2				strip local name
E 10
I 10
R$*<@$=w>$*		$1<@$w>$2			resolve abbreviations
E 10
D 2
R$*<@$=S>$*		$1<@$2.$A>$3			resolve abbreviations
E 2
D 7
R$*<@$=Z>$*		$1<@$2.$A>$3			resolve abbreviations
D 2
R$*<@$->$*		$1<@$2.ARPA>$3			resolve abbreviations
E 2
I 2
R$*<@$->$*		$1<@$2.$A>$3			resolve abbreviations
E 7
I 7
D 9
R$*<@$=Z>$*		$1<@$2.$D>$3			resolve abbreviations
E 9
R$*<@$->$*		$1<@$2.$D>$3			resolve abbreviations
E 7
D 3
R$*<@$-.$=A.EDU>	$@$U!$1<@$2.$A>			leave @ if local domain
E 3
E 2
R$+<@$+>		$2!$1				uucpize (no @'s in addr)
I 10
R$w!$+			$1				strip local name
E 10
R$+			$:$U!$1				stick on our host name
D 9
R$=w!$=R:$+		$:$1!$3				ucbvax!ucbvax:xxx
I 5
D 8
R$=U!$-.berkeley.edu!$-	$:$1!$3@$2.berkeley.edu		ucbvax!user@host.berkeley.edu
E 8
I 8
R$=U!$*.berkeley.edu!$-	$:$1!$3@$2.berkeley.edu		ucbvax!user@host.berkeley.edu
E 8
I 6
R$=U!$-%$-		$:$1!$2@$3.berkeley.edu		ucbvax!user@host.berkeley.edu
E 9
I 9
R$=w!$=R:$+		$:$1!$3				us!us:user -> us!user
R$=U!$-%$-		$:$1!$2@$3.$D			ucbvax!user@host.domain
E 9
E 6
E 5

S23
R$+			$:$>5$1				convert to old style
D 2
R$*<@$=S>$*		$1<@$2.$A>$3			resolve abbreviations
E 2
D 7
R$*<@$=Z>$*		$1<@$2.$A>$3			resolve abbreviations
R$*<@$=w>$*		$1<@$2.$A>$3			resolve abbreviations
D 2
R$*<@$->$*		$1<@$2.ARPA>$3			resolve abbreviations
E 2
I 2
R$*<@$->$*		$1<@$2.$A>$3			resolve abbreviations
E 7
I 7
D 10
R$*<@$=Z>$*		$1<@$2.$D>$3			resolve abbreviations
R$*<@$=w>$*		$1<@$2.$D>$3			resolve abbreviations
E 10
I 10
R$*<@$=w>$*		$1<@$w>$2			resolve abbreviations
E 10
R$*<@$->$*		$1<@$2.$D>$3			resolve abbreviations
E 7
E 2
D 10
R$+<@$*$=w.EDU>		$2$3.EDU!$1			uucp!u@local -> local!uucp!u
I 4
R$=U!$+			$2				strip local name
E 10
I 10
R$+<@$w>		$U!$1				a!b@here -> here!a!b
R$=U!$+			$2				here!a!b -> a!b
# sanity ... should not happen.
E 10
D 9
R$=U.berkeley.edu!$+	$2				strip local name.domain
E 9
I 9
R$=U.$D!$+		$2				strip local name.domain
E 9
E 4
E 1
