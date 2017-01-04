h54012
s 00002/00003/00084
d D 1.19 88/03/31 23:45:13 phil 21 20
c Remove DEC and MAILNET fake domains.
e
s 00002/00004/00085
d D 1.18 87/11/04 15:53:07 phil 20 19
c Removed .oz cruft (thanks to kre).
e
s 00019/00042/00070
d D 1.17 87/07/05 20:07:31 phil 19 18
c Removed LOCAL cruft, removed lots of stuff.
e
s 00011/00011/00101
d D 1.16 87/04/28 09:00:56 phil 18 16
c Misc cleanup to prepare for big rewrite.
e
s 00002/00002/00110
d R 1.16 86/09/30 11:39:17 rosen 17 16
c added Jim's subdomain hacks
e
s 00006/00003/00106
d D 1.15 86/08/08 13:35:46 bloom 16 15
c support subdomains a bit better
e
s 00000/00009/00109
d D 1.14 86/07/21 14:39:54 bloom 15 14
c CC and BERKNET handled by MX records now
e
s 00000/00007/00118
d D 1.13 86/07/09 16:47:33 bloom 14 13
c remove host.arpa specail case and cruft
e
s 00006/00006/00119
d D 1.12 86/05/01 18:42:32 bloom 13 12
c use domain name instead of arpanet relay for domain name
e
s 00004/00006/00121
d D 1.11 86/02/26 07:52:31 bloom 12 11
x 11
c OZ domain is gone, CC is going away, get rewriting of local host names right
e
s 00000/00000/00125
d D 1.10 85/12/19 11:27:38 miriam 11 10
x 10
c Remove local loops when using user%host@ucbvax.berkeley.edu
e
s 00002/00000/00125
d D 1.9 85/12/17 09:47:16 miriam 10 9
c Put in user%non-nic-host@berkeley.edu for the to:, cc:, and bcc: headers.
e
s 00002/00000/00123
d D 1.8 85/11/21 09:49:52 miriam 9 8
c If $w does not include domain, then tack it on.
e
s 00002/00002/00121
d D 1.7 85/11/20 12:04:51 miriam 8 7
c Change decwrl.arpa to decwrl.dec.com
e
s 00001/00001/00122
d D 1.6 85/10/30 13:38:43 miriam 7 6
c Match on single token when resolving local hosts (user<@host>).
e
s 00006/00003/00117
d D 1.5 85/10/29 11:18:00 miriam 6 5
c For non-nic-registered hosts format should be user%host@berkeley.edu
e
s 00001/00001/00119
d D 1.4 85/10/24 16:00:58 miriam 5 3
c Put in C flage to mailer definition for address completion.
e
s 00001/00001/00119
d R 1.4 85/10/21 17:07:18 miriam 4 3
c Put in C flag to complete addresses in the To: line.
e
s 00001/00000/00119
d D 1.3 85/08/17 10:23:07 miriam 3 2
c Don't rewrite user@host.bitnet recipients - let jade (the gateway)
c do it.
e
s 00001/00001/00118
d D 1.2 85/08/13 18:16:50 miriam 2 1
c Remove the C options.
e
s 00119/00000/00000
d D 1.1 85/08/08 15:31:20 miriam 1 0
c date and time created 85/08/08 15:31:20 by miriam
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
#####		Arpanet TCP Mailer specification
#####
#####	Messages processed by this specification are assumed to leave
#####	the local domain -- hence, they must be canonical according to
#####	RFC822 etc.
#####
#####	This mailer is to be used with the Berkeley Name Server.
#####
############################################################
############################################################

D 2
Mtcp,	P=[IPC], F=mDFMueCXL, S=14, R=24, A=IPC $h, E=\r\n
E 2
I 2
D 5
Mtcp,	P=[IPC], F=mDFMueXL, S=14, R=24, A=IPC $h, E=\r\n
E 5
I 5
Mtcp,	P=[IPC], F=mDFMueXLC, S=14, R=24, A=IPC $h, E=\r\n
E 5
E 2

S14

# pass <route-addr>'s through
R<@$+>$*		$@<@$[$1$]>$2			resolve <route-addr>

D 19
# map colons to dots everywhere.....
E 19
I 19
# map colons to dots everywhere
E 19
R$*:$*			$1.$2				map colons to dots

D 14
# handle the simple case....
R$+<@$-.ARPA>		$@$1<@$[$2.ARPA$]>		user@host.ARPA

E 14
D 15
# fully qualify computer center names so the rest works nicely
D 12
R$+<@$+.CC>		$1<@$2.LOCAL>		user@host.CC
E 12
I 12
D 13
R$+<@$=C>		$1<@$2.$A>		user@host.CC
E 13
I 13
R$+<@$=C>		$1<@$2.$D>		user@host.CC
E 13
E 12

E 15
# output local host in user@host.BERKELEY.EDU syntax
D 6
R$+<@$=w>		$@$1<@$w>			this host
R$+<@LOCAL>		$@$1<@$w>			this host
R$+<@$+.LOCAL>		$@$1<@$2.$A>			local hosts
E 6
I 6
D 18
R$+<@LOCAL>		$:$1<@$w>				this host
D 7
R$+<@$+>		$:$1<@$[$2$]>			check for local domain
E 7
I 7
R$+<@$->		$:$1<@$[$2$]>			check for local domain
E 7
D 16
R$+<@$~N.berkeley.edu>	$@$1%$2<@$A>			for non-nic-reg local hosts
E 16
I 16
R$+<@$=N.berkeley.edu>	$@$1<@$2.Berkeley.EDU>		for non-nic-reg local hosts
R$+<@$*.berkeley.edu>	$@$1%$2.Berkeley.EDU<@$A>	for non-nic-reg local hosts
E 18
I 18
D 19
R$+<@LOCAL>		$:$1<@$w>			this host
E 19
I 19
R$-			$1<@$w>				user w/o host
R$+<@$=w>		$:$1<@$w>			this host
E 19
R$+<@$->		$:$1<@$[$2$]>			canonicalize into dom
I 19
R$+<@$->		$:$1<@$2.$D>			if nameserver fails
E 19
R$+<@$=N.$D>		$@$1<@$2.$D>			nic-reg hosts are ok
R$+<@$*.$D>		$@$1%$2.$D<@$A>			else -> u%h@gateway
E 18
E 16
D 19
R$+<@$~N.LOCAL>		$@$1%$2<@$A>			for non-nic-registered sites
D 13
R$+<@$+.LOCAL>		$@$1<@$2.$A>			nic-reg local hosts
I 9
R$+<@$=w>		$@$1<@$w.$A>			user@this_host.berkeley.edu
E 13
I 13
R$+<@$+.LOCAL>		$@$1<@$2.$D>			nic-reg local hosts
D 18
R$+<@$=w>		$@$1<@$w.$D>			user@this_host.berkeley.edu
E 18
I 18
R$+<@$=w>		$@$1<@$w.$D>			user@our.domain
E 19
E 18
E 13
E 9
E 6

D 19
# output local hosts in user%host@BERKELEY.EDU syntax
E 19
I 19
# if not local, and not a "fake" domain, ask the nameserver
R$+<@$+.$~I>		$@$1<@$[$2.$3$]>		user@host.domain
R$+<@[$+]>		$@$1<@[$2]>			already ok
E 19

I 19
# output internal ("fake") domains as "user%host@relay"

E 19
D 18
R$+<@$+.CSNET>		$@$1%$2.CSNET<@CSNET-RELAY.ARPA>	user@host.CSNET
E 18
I 18
R$+<@$+.CSNET>		$@$1%$2.CSNET<@relay.cs.net>	user@host.CSNET
E 18
D 8
R$+<@$+.DEC>		$@$1%$2.DEC<@decwrl.ARPA>	user@host.DEC
E 8
I 8
D 21
R$+<@$+.DEC>		$@$1%$2.DEC<@decwrl.dec.com>	user@host.DEC
E 21
I 21
R$+<@$+.BITNET>		$@$1%$2.BITNET<@jade.berkeley.edu> user@host.BITNET
E 21
E 8
D 12
R$+<@$+.OZ>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ
R$+<@$+.OZ.AU>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ.AU
E 12
I 12
D 20
R$+<@$+.OZ.AU>		$@$1%$2.OZ.AU<@seismo.css.gov>	user@host.OZ.AU
E 20
E 12
R$+<@$+.UUCP>		$@$2!$1<@$w>			user@host.UUCP
D 19
R$+<@$+.$=P>		$@$1<@$[$2.$3$]>		user@host.{mil,edu,...}
R$+<@$+.$=K>		$@$1%$2.$3<@$w>			user@host.fake
E 19
D 15
R$+<@$*$=Z>		$@$1%$2$3<@$w>
E 15

D 19
# handle other external cases
R$+<@$->		$@$1<@$[$2$]>			no .ARPA on simple names
D 14
#R$+<@$+.$-.ARPA>	$@$1%$2<@$[$3.ARPA$]>		approximate something
E 14
R$+<@[$+]>		$@$1<@[$2]>			already ok
R$+<@$+>		$@$1<@$[$2$]>			set for named
E 19

D 19
# convert remaining addresses to old format and externalize appropriately
R$+			$:$>5$1				=> old format
R$-:$+			$@$1.$2<@$w>			convert berk hosts
#R$+<@$+>		$@$1%$2<@$w>			pessmize
R$+			$:$1<@$w>			tack on our hostname
I 9
D 13
R$+<@$=w>		$:$1<@$w.$A>			wher $w doesn't have .b.e
E 13
I 13
R$+<@$=w>		$:$1<@$w.$D>			wher $w doesn't have .b.e
E 13
E 9
I 6
D 16
R$+<@$~N.berkeley.edu>	$@$1%$2<@$A>			user%host@berkeley.edu
E 16
I 16
D 18
R$+<@$=N.berkeley.edu>	$@$1<@$2.Berkeley.EDU>		for non-nic-reg local hosts
R$+<@$*.berkeley.edu>	$@$1%$2.Berkeley.EDU<@$A>	for non-nic-reg local hosts
E 18
I 18
R$+<@$=N.$D>		$@$1<@$2.$D>			for non-nic-reg local hosts
R$+<@$*.$D>		$@$1%$2.$D<@$A>			for non-nic-reg local hosts
E 18
E 16
E 6
R$+%$=R<@$=A>		$1<@$[$3$]>			strip unneeded relay

E 19
S24

# put in <> kludge
R$*<$*>$*		$1$2$3				defocus
R$*			$:$>3$1				now canonical form

# pass <route-addr>'s through
R<@$+>$*		$@<@$[$1$]>$2			resolve <route-addr>

# map colons to dots everywhere.....
R$*:$*			$1.$2				map colons to dots
D 14

# handle the simple case....
R$+<@$-.ARPA>		$@$1<@$[$2.ARPA$]>		user@host.ARPA
E 14

D 15
# fully qualify computer center names so the rest works nicely
D 12
R$+<@$+.CC>		$1<@$2.LOCAL>		user@host.CC
E 12
I 12
D 13
R$+<@$=C>		$1<@$2.$A>		user@host.CC
E 13
I 13
R$+<@$=C>		$1<@$2.$D>		user@host.CC
E 13
E 12

E 15
D 20
# output local host in user@host.BERKELEY.EDU syntax
E 20
I 20
# output local host in user@host.domain syntax
E 20
D 19
R$+<@$=w>		$@$1<@$w>			this host
R$+<@LOCAL>		$@$1<@$w>			this host
D 13
R$+<@$+.LOCAL>		$@$1<@$2.$A>			local hosts
E 13
I 13
R$+<@$+.LOCAL>		$@$1<@$2.$D>			local hosts
E 13
I 10
R$+<@$->		$:$1<@$[$2$]>			resolve to full name
D 16
R$+<@$~N.berkeley.edu>	$@$1%$2<@$A>			non-nic host qualification
E 16
I 16
D 18
R$+<@$=N.berkeley.edu>	$@$1<@$2.Berkeley.EDU>		for non-nic-reg local hosts
R$+<@$*.berkeley.edu>	$@$1%$2.Berkeley.EDU<@$A>	for non-nic-reg local hosts
E 18
I 18
R$+<@$=N.$D>		$@$1<@$2.$D>			for non-nic-reg local hosts
R$+<@$*.$D>		$@$1%$2.$D<@$A>			for non-nic-reg local hosts
E 19
I 19
R$-			$1<@$w>				user w/o host
R$+<@$=w>		$:$1<@$w>			this host
R$+<@$->		$:$1<@$[$2$]>			canonicalize into dom
R$+<@$->		$:$1<@$2.$D>			if nameserver fails
R$+<@$=N.$D>		$@$1<@$2.$D>			nic-reg hosts are ok
R$+<@$*.$D>		$@$1%$2.$D<@$A>			else -> u%h@gateway
E 19
E 18
E 16
E 10

I 19
# if not local, and not a "fake" domain, ask the nameserver
R$+<@$+.$~I>		$@$1<@$[$2.$3$]>		user@host.domain
R$+<@[$+]>		$@$1<@[$2]>			already ok

E 19
D 20
# output local hosts in user%host@BERKELEY.EDU syntax
E 20
I 20
# Hide fake domains behind gateways
E 20

D 18
R$+<@$+.CSNET>		$@$1%$2.CSNET<@CSNET-RELAY.ARPA>	user@host.CSNET
E 18
I 18
R$+<@$+.CSNET>		$@$1%$2.CSNET<@relay.cs.net>	user@host.CSNET
E 18
D 8
R$+<@$+.DEC>		$@$1%$2.DEC<@decwrl.ARPA>	user@host.DEC
E 8
I 8
D 21
R$+<@$+.DEC>		$@$1%$2.DEC<@decwrl.dec.com>	user@host.DEC
E 8
D 12
R$+<@$+.OZ>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ
R$+<@$+.OZ.AU>		$@$1%$2.OZ<@seismo.css.gov>	user@host.OZ.AU
E 12
I 12
D 20
R$+<@$+.OZ.AU>		$@$1%$2.OZ.AU<@seismo.css.gov>	user@host.OZ.AU
E 20
E 12
R$+<@$+.UUCP>		$@$2!$1				user@host.UUCP
E 21
I 3
R$+<@$+.BITNET>		$@$1<@$2.BITNET>		user@host.BITNET
I 21
R$+<@$+.UUCP>		$@$2!$1				user@host.UUCP
E 21
E 3
D 19
R$+<@$+.$=P>		$@$1<@$[$2.$3$]>		user@host.{mil,edu,...}
R$+<@$+.$=K>		$@$1%$2.$3<@$w>			user@host.fake
D 15
R$+<@$=Z>		$@$1<@$2>			berkhosts
E 15

# handle other external cases
R$+<@$->		$@$1<@$[$2$]>			no .ARPA on simple names
D 15
#R$+<@$+.$-.ARPA>	$@$1%$2<@$[$3.ARPA$]>		approximate something
E 15
R$+<@[$+]>		$@$1<@[$2]>			already ok
R$+<@$+>		$@$1<@$[$2$]>			set for named

# convert remaining addresses to old format and externalize appropriately
R$+			$:$>5$1				=> old format
R$-:$+			$@$1.$2<@$w>			convert berk hosts
#R$+<@$+>		$@$1%$2<@$w>			pessmize
R$+			$:$1<@$w>			tack on our hostname
R$+%$=R<@$=A>		$1<@$[$3$]>			strip unneeded relay
E 19

E 1
