h65105
s 00001/00004/00091
d D 1.7 88/03/31 23:45:10 phil 8 7
c Remove DEC and MAILNET fake domains.
e
s 00000/00002/00095
d D 1.6 87/11/04 15:53:04 phil 7 6
c Removed .oz cruft (thanks to kre).
e
s 00033/00046/00064
d D 1.5 87/07/05 20:08:18 phil 6 4
c Removed LOCAL cruft, lots of old stuff.
e
s 00002/00002/00108
d R 1.5 86/09/30 11:38:31 rosen 5 4
c added Jim's subdomain hacks
e
s 00000/00016/00110
d D 1.4 86/07/21 14:39:24 bloom 4 3
c remove extraneous nameserver calls, CC and BERKNET handled by MX records
e
s 00006/00007/00120
d D 1.3 86/05/01 18:32:05 bloom 3 2
c use domain name instead of arpanet relay for domain name
e
s 00004/00008/00123
d D 1.2 86/02/26 07:54:26 bloom 2 1
c OZ domain is gone, CC is going away, cleanup
e
s 00131/00000/00000
d D 1.1 85/12/20 13:52:04 bloom 1 0
c date and time created 85/12/20 13:52:04 by bloom
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
#####		Local Domain TCP Mailer specification
#####
#####	Messages processed by this specification are assumed to remain
#####	the local domain -- hence, they must be canonical according to
#####	RFC822 etc.
#####
#####	This mailer is to be used with the Berkeley Name Server.
#####
############################################################
############################################################

Mtcpld,	P=[IPC], F=mDFMueXLC, S=17, R=27, A=IPC $h, E=\r\n

S17

# cleanup forwarding a bit
R$*<$*>$*		$1$2$3				defocus
R$*			$:$>3$1				canonicalize
D 6
R$*%$*<@LOCAL>		$:$>9$1%$2			user%localhost@localdomain
E 6
I 6
R$*%$*<@$w>		$:$>9$1%$2			user%localhost@localdomain
E 6

# pass <route-addr>'s through
R<@$+>$*		$@<@$[$1$]>$2			resolve <route-addr>

D 6
# map colons to dots everywhere.....
E 6
I 6
# map colons to dots everywhere
E 6
R$*:$*			$1.$2				map colons to dots

D 4
# handle the simple case....
R$+<@$-.ARPA>		$@$1<@$[$2.ARPA$]>		user@host.ARPA

# fully qualify computer center names so the rest works nicely
D 2
R$+<@$+.CC>		$1<@$2.LOCAL>		user@host.CC
E 2
I 2
D 3
R$+<@$=C>		$1<@$2.$A>		user@host.CC
E 3
I 3
R$+<@$=C>		$1<@$2.$D>		user@host.CC
E 3
E 2

E 4
D 6
# output local host in user@host.BERKELEY.EDU syntax
R$+<@LOCAL>		$:$1<@$w>				this host
R$+<@$->		$:$1<@$[$2$]>			check for local domain
D 2
#R$+<@$~N.berkeley.edu>	$@$1%$2<@$A>			for non-nic-reg local hosts
#R$+<@$~N.LOCAL>		$@$1%$2<@$A>			for non-nic-registered sites
E 2
D 3
R$+<@$+.LOCAL>		$@$1<@$2.$A>			nic-reg local hosts
R$+<@$=w>		$@$1<@$w.$A>			user@this_host.berkeley.edu
E 3
I 3
R$+<@$+.LOCAL>		$@$1<@$2.$D>			nic-reg local hosts
R$+<@$=w>		$@$1<@$w.$D>			user@this_host.berkeley.edu
E 6
I 6
# output local host as user@host.domain
R$-			$@$1<@$w>			user w/o host
R$+<@$w>		$@$1<@$w>			this host
R$+<@$=w>		$@$1<@$w>			or an alias
R$+<@$->		$:$1<@$[$2$]>			ask nameserver
R$+<@$w>		$@$1<@$w>			this host
R$+<@$->		$@$1<@$2.$D>			if nameserver fails
E 6
E 3

D 6
# output local hosts in user%host@BERKELEY.EDU syntax
E 6
I 6
# if not local, and not a "fake" domain, ask the nameserver
R$+<@$+.$~I>		$@$1<@$[$2.$3$]>		user@host.domain
R$+<@[$+]>		$@$1<@[$2]>			already ok
E 6

D 6
R$+<@$+.CSNET>		$@$1%$2.CSNET<@CSNET-RELAY.ARPA>	user@host.CSNET
E 6
I 6
# output fake domains as user%fake@relay

R$+<@$+.CSNET>		$@$1%$2.CSNET<@relay.cs.net>	user@host.CSNET
E 6
D 8
R$+<@$+.DEC>		$@$1%$2.DEC<@decwrl.dec.com>	user@host.DEC
E 8
I 6
R$+<@$+.BITNET>		$@$1%$2.BITNET<@jade.berkeley.edu>	 user@host.bitnet
D 8
R$+<@$+.MAILNET>	$@$1%$2.MAILNET<@mit-multics.arpa>	 user@host.mailnet
E 8
E 6
D 2
R$+<@$+.OZ>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ
R$+<@$+.OZ.AU>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ.AU
E 2
I 2
D 7
R$+<@$+.OZ.AU>		$@$1%$2.OZ.AU<@seismo.css.gov>	user@host.OZ.AU
E 7
E 2
R$+<@$+.UUCP>		$@$2!$1<@$w>			user@host.UUCP
D 6
R$+<@$+.$=P>		$@$1<@$[$2.$3$]>		user@host.{mil,edu,...}
R$+<@$+.$=K>		$@$1%$2.$3<@$w>			user@host.fake
E 6
D 4
R$+<@$*$=Z>		$@$1%$2$3<@$w>
E 4

D 6
# handle other external cases
R$+<@$->		$@$1<@$[$2$]>			no .ARPA on simple names
D 4
#R$+<@$+.$-.ARPA>	$@$1%$2<@$[$3.ARPA$]>		approximate something
E 4
R$+<@[$+]>		$@$1<@[$2]>			already ok
R$+<@$+>		$@$1<@$[$2$]>			set for named
E 6

D 6
# convert remaining addresses to old format and externalize appropriately
R$+			$:$>5$1				=> old format
R$-:$+			$@$1.$2<@$w>			convert berk hosts
#R$+<@$+>		$@$1%$2<@$w>			pessmize
R$+			$:$1<@$w>			tack on our hostname
D 3
R$+<@$=w>		$:$1<@$w.$A>			wher $w doesn't have .b.e
#R$+<@$~N.berkeley.edu>	$@$1%$2<@$A>			user%host@berkeley.edu
E 3
I 3
R$+<@$=w>		$:$1<@$w.$D>			wher $w doesn't have .b.e
E 3
R$+%$=R<@$=A>		$1<@$[$3$]>			strip unneeded relay

E 6
S27

D 6
# put in <> kludge
E 6
I 6
# cleanup
E 6
R$*<$*>$*		$1$2$3				defocus
R$*			$:$>3$1				now canonical form
D 6
R$*%$*<@LOCAL>		$:$>9$1%$2			user%localhost@localdomain
E 6
I 6
R$*%$*<@$w>		$:$>9$1%$2			user%localhost@localdomain
E 6

# pass <route-addr>'s through
R<@$+>$*		$@<@$[$1$]>$2			resolve <route-addr>

D 6
# map colons to dots everywhere.....
E 6
I 6
# map colons to dots everywhere
E 6
R$*:$*			$1.$2				map colons to dots

D 4
# handle the simple case....
R$+<@$-.ARPA>		$@$1<@$[$2.ARPA$]>		user@host.ARPA

# fully qualify computer center names so the rest works nicely
D 2
R$+<@$+.CC>		$1<@$2.LOCAL>		user@host.CC
E 2
I 2
D 3
R$+<@$=C>		$1<@$2.$A>		user@host.CC
E 3
I 3
R$+<@$=C>		$1<@$2.$D>		user@host.CC
E 3
E 2

E 4
D 6
# output local host in user@host.BERKELEY.EDU syntax
R$+<@$=w>		$@$1<@$w>			this host
R$+<@LOCAL>		$@$1<@$w>			this host
D 3
R$+<@$+.LOCAL>		$@$1<@$2.$A>			local hosts
E 3
I 3
R$+<@$+.LOCAL>		$@$1<@$2.$D>			local hosts
E 6
I 6
# output local host as user@host.domain
R$-			$@$1<@$w>			user w/o host
R$+<@$w>		$@$1<@$w>			this host
R$+<@$=w>		$@$1<@$w>			or an alias
R$+<@$->		$:$1<@$[$2$]>			ask nameserver
R$+<@$w>		$@$1<@$w>			this host
R$+<@$->		$@$1<@$2.$D>			if nameserver fails
E 6
E 3

D 6
# output local hosts in user%host@BERKELEY.EDU syntax
E 6
I 6
# if not local, and not a "fake" domain, ask the nameserver
R$+<@$+.$~I>		$@$1<@$[$2.$3$]>		user@host.domain
R$+<@[$+]>		$@$1<@[$2]>			already ok
E 6

D 6
R$+<@$+.CSNET>		$@$1%$2.CSNET<@CSNET-RELAY.ARPA>	user@host.CSNET
E 6
I 6
# output fake domains as user%fake@relay

R$+<@$+.CSNET>		$@$1%$2.CSNET<@relay.cs.net>	user@host.CSNET
E 6
D 8
R$+<@$+.DEC>		$@$1%$2.DEC<@decwrl.dec.com>	user@host.DEC
D 2
R$+<@$+.OZ>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ
R$+<@$+.OZ.AU>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ.AU
E 2
I 2
D 7
R$+<@$+.OZ.AU>		$@$1%$2.OZ.AU<@seismo.css.gov>	user@host.OZ.AU
E 7
E 2
R$+<@$+.UUCP>		$@$2!$1				user@host.UUCP
E 8
R$+<@$+.BITNET>		$@$1<@$2.BITNET>		user@host.BITNET
I 8
R$+<@$+.UUCP>		$@$2!$1				user@host.UUCP
E 8
D 6
R$+<@$+.$=P>		$@$1<@$[$2.$3$]>		user@host.{mil,edu,...}
R$+<@$+.$=K>		$@$1%$2.$3<@$w>			user@host.fake
D 4
R$+<@$=Z>		$@$1<@$2>			berkhosts
E 4

# handle other external cases
R$+<@$->		$@$1<@$[$2$]>			no .ARPA on simple names
D 4
#R$+<@$+.$-.ARPA>	$@$1%$2<@$[$3.ARPA$]>		approximate something
E 4
R$+<@[$+]>		$@$1<@[$2]>			already ok
R$+<@$+>		$@$1<@$[$2$]>			set for named

# convert remaining addresses to old format and externalize appropriately
R$+			$:$>5$1				=> old format
R$-:$+			$@$1.$2<@$w>			convert berk hosts
#R$+<@$+>		$@$1%$2<@$w>			pessmize
R$+			$:$1<@$w>			tack on our hostname
R$+%$=R<@$=A>		$1<@$[$3$]>			strip unneeded relay
E 6

E 1
