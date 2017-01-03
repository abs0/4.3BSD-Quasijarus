h23261
s 00001/00005/00071
d D 1.16 88/04/08 11:51:24 phil 16 15
c Don't use $=D anymore.  Berkeley.ARPA unsupported.  Don't 
c rewrite ucsfcgl!ho into cgl.ucsf.edu, since smtpuucp will handle that.
e
s 00000/00003/00076
d D 1.15 87/07/15 14:11:40 phil 15 14
c Move deletion of thishost info to rule 0.
e
s 00000/00001/00079
d D 1.14 87/07/15 10:49:16 phil 14 13
c As it turns out, that last delta wasn't necessary.
e
s 00001/00000/00079
d D 1.13 87/07/14 16:46:31 phil 13 12
c Added kludge to deal with nameserver not working for "arpa".
e
s 00010/00012/00069
d D 1.12 87/07/05 20:05:33 phil 12 11
c Removed LOCAL cruft, added check for user%this_host@this_host.
e
s 00001/00001/00080
d D 1.11 86/05/01 18:32:19 bloom 11 10
c use domain name instead of arpanet relay for domain name
e
s 00001/00001/00080
d D 1.10 86/03/11 14:20:54 bloom 10 9
c use new domain name when rewrite ucsfcgl
e
s 00001/00003/00080
d D 1.9 86/02/26 07:50:44 bloom 9 8
c CC domain is going away soon, don't use it internally
e
s 00001/00001/00082
d D 1.8 85/11/21 12:04:46 miriam 8 7
c Correction in S6 to prevent looping.
e
s 00001/00000/00082
d D 1.7 85/11/20 16:47:04 miriam 7 6
c Change rule 6 to convert user@local_host to user@local.
e
s 00001/00001/00081
d D 1.6 85/11/20 15:09:06 miriam 6 5
c Allow format any.domain!user 
e
s 00001/00000/00081
d D 1.5 85/11/12 12:03:19 miriam 5 4
c Recognize class C in the domain form.
e
s 00001/00001/00080
d D 1.4 85/11/11 17:35:05 miriam 4 3
c Check for x%y before x.y
e
s 00002/00002/00079
d D 1.3 85/10/24 16:40:00 miriam 3 2
c For handling "LOCAL" machine.
e
s 00008/00004/00073
d D 1.2 85/08/09 17:42:27 miriam 2 1
c Work on S6.
e
s 00077/00000/00000
d D 1.1 85/08/08 15:31:25 miriam 1 0
c date and time created 85/08/08 15:31:25 by miriam
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
###########################
#  Name Canonicalization  #
###########################
S3

# handle "from:<>" special case
R<>			$@@				turn into magic token

# basic textual canonicalization -- note RFC733 heuristic here
R$*<$*<$*<$+>$*>$*>$*	$4				3-level <> nesting
R$*<$*<$+>$*>$*		$3				2-level <> nesting
R$*<$+>$*		$2				basic RFC821/822 parsing
R$+ at $+		$1@$2				"at" -> "@" for RFC 822

# make sure <@a,@b,@c:user@d> syntax is easy to parse -- undone later
R@$+,$+			@$1:$2				change all "," to ":"

# localize and dispose of route-based addresses
R@$+:$+			$@$>6<@$1>:$2			handle <route-addr>

# more miscellaneous cleanup
R$+			$:$>8$1				host dependent cleanup
R$+:$*;@$+		$@$1:$2;@$3			list syntax
R$+:$*;			$@$1:$2;			list syntax
R$+@$+			$:$1<@$2>			focus on domain
R$+<$+@$+>		$1$2<@$3>			move gaze right
R$+<@$+>		$@$>6$1<@$2>			already canonical

# convert old-style addresses to a domain-based address
R$+^$+			$1!$2				convert ^ to !
R$-!$+			$@$>6$2<@$1.UUCP>		resolve uucp names
D 6
R$+.$=K!$+		$@$>6$3<@$1.$2>			domain uucps
E 6
I 6
R$+.$-!$+		$@$>6$3<@$1.$2>			domain uucps
E 6
R$+!$+			$@$>6$2<@$1.UUCP>		uucp subdomains
R$-:$+			$@$>6$2<@$1>			host:user
D 4
R$-.$+			$@$>6$2<@$1>			host.user
E 4
R$-=$+			$@$>6$2<@$1.BITNET>		resolve bitnet names
R$+%$+			$:$>9$1%$2			user%host
R$+<@$+>		$@$>6$1<@$2>			already canonical
I 4
R$-.$+			$@$>6$2<@$1>			host.user
E 4


#################################
#   special local conversions   #
#################################

S6
I 7
D 8
R$*<@$=w>$*		$1<@LOCAL>$3
E 8
I 8
D 12
R$*<@$=w>$*		$:$1<@LOCAL>$3
E 8
E 7
D 2
R$*<@$=D>		$@$1<@$2>			allow send to ucbvax
R$*<@$*$=D>$*		$1<@$2LOCAL>$4			convert local domain
R$*<@$*$=D.ARPA>$*	$1<@$2LOCAL>$4
R$*<@$*$=D.EDU>$*	$1<@$2LOCAL>$4
E 2
I 2
R$*<@$=w.$=D>$*		$1<@$2.LOCAL>$4			convert local domain
R$*<@$=w.ARPA>$*	$1<@$2.LOCAL>$3
R$*<@$=w.EDU>$*		$1<@$2.LOCAL>$3
R$*<@$=w.$=D.ARPA>$*	$1<@$2.LOCAL>$4
R$*<@$=w.$=D.EDU>$*	$1<@$2.LOCAL>$4
E 2
D 3
R$+<@LOCAL>		$@$>3$1
I 2
R$+<@$=w.LOCAL>		$@$>3$1
E 3
I 3
R$+<@LOCAL>		$@$1<@LOCAL>
R$+<@$=w.LOCAL>		$@$1<@LOCAL>
E 3
R<@$=w.LOCAL>:$+	$@$>3$2
R$+<@$*.LOCAL>$*	$1<@$2>$3
E 2
R$*<@$+.$=T.$=T>$*	$1<@$2.$3>$5			make UUCP top level
D 9
R$*<@$*$=C.$=T>$*	$1<@$2$3>$5			adjust CC hosts (ucbvax)
R$*<@$*$=C>$*		$1<@$2$3.CC>$4			adjust CC hosts (ucbvax)
I 5
R$*<@$=C.berkeley.edu>$*	$1<@$2.CC>$3		recognize cc hosts w/ domain
E 9
I 9
D 11
R$*<@$+.CC>$*		$1<@$2.$A>$3
E 11
I 11
R$*<@$+.CC>$*		$1<@$2.$D>$3
E 12
I 12
R$*<@$=w>$*		$:$1<@$w>$3			get into u@$w form
D 16
R$*<@$=w.$=D>$*		$:$1<@$w>$4
R$*<@$=w.ARPA>$*	$:$1<@$w>$3
E 16
I 16
R$*<@$=w.$D>$*		$:$1<@$w>$3
E 16
R$*<@$=w.EDU>$*		$:$1<@$w>$3
D 16
R$*<@$=w.$=D.ARPA>$*	$:$1<@$w>$4
R$*<@$=w.$=D.EDU>$*	$:$1<@$w>$4
E 16
R$*<@$=U.UUCP>$*	$:$1<@$w>$3
D 15
R$*%$*<@$w>$*		$@$>3$1%$2
R$+<@$w>		$@$1<@$w>
R<@$w>:$+		$@$>3$1				@us:... -> ...
E 15
E 12
E 11
E 9
E 5
D 10
R$*<@ucsfcgl.UUCP>$*	$1<@ucsf-cgl.ARPA>$2		ucsfcgl now on Internet
E 10
I 10
D 16
R$*<@ucsfcgl.UUCP>$*	$1<@cgl.ucsf.edu>$2		ucsfcgl now on Internet
E 16
I 13
D 14
R$*<@arpa>$*		$1<@ucbarpa>$2			compat for user@arpa
E 14
E 13
E 10

################################
#   Change rightmost % to @.   #
################################

S9
R$*%$*			$1@$2				First make them all @'s.
R$*@$*@$*		$1%$2@$3			Undo all but the last.
R$*@$*			$@$1<@$2>			Put back the brackets.

E 1
