h20760
s 00002/00004/00064
d D 1.14 00/03/27 09:47:18 msokolov 15 14
c remove unnecessary extra canonicalization hop and fix the special error address
e
s 00001/00001/00067
d D 1.13 00/03/27 09:43:33 msokolov 14 13
c remove the C flag, it's totally unusable with the current cf file architecture
e
s 00001/00035/00067
d D 1.12 00/03/27 09:40:39 msokolov 13 12
c use the same ruleset for S and R instead of two identical ones
e
s 00005/00005/00097
d D 1.11 00/03/27 08:39:47 msokolov 12 11
c The prophecy has come true. HOSTS.TXT is gone, everyone uses DNS, and there are
c no more NIC-registered hosts to worry about. The old tcp mailer goes away and
c tcpld becomes smtp.
e
s 00000/00000/00102
d D 1.10 00/03/27 08:31:59 msokolov 11 10
c bump it up to 1.10
e
s 00000/00000/00102
d D 1.9 00/03/27 08:31:40 msokolov 10 9
c bump it up to 1.10
e
s 00025/00015/00077
d D 1.8 00/03/27 08:31:13 msokolov 9 8
c deltas 1.8-1.10 have apparently been lost, reconstructing from g-file 1.10
e
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
D 9
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 9
I 9
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 9
#
D 9
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
E 9
I 9
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 9
#
#	%W% (Berkeley) %G%
#
divert(0)
############################################################
############################################################
#####
D 9
#####		Local Domain TCP Mailer specification
E 9
I 9
D 12
#####		Local Domain SMTP Mailer specification
E 12
I 12
#####		Internet SMTP Mailer specification
E 12
E 9
#####
D 12
#####	Messages processed by this specification are assumed to remain
D 9
#####	the local domain -- hence, they must be canonical according to
#####	RFC822 etc.
E 9
I 9
#####	the local domain.  Hence, they can refer to hosts that are
#####	not registered in the NIC host table.
E 12
I 12
#####	Messages processed by this specification may leave
#####	the local domain -- hence, they must be canonical
#####	according to RFC822 etc.
E 12
E 9
#####
D 9
#####	This mailer is to be used with the Berkeley Name Server.
#####
E 9
############################################################
############################################################

D 12
Mtcpld,	P=[IPC], F=mDFMueXLC, S=17, R=27, A=IPC $h, E=\r\n
E 12
I 12
D 13
Msmtp,	P=[IPC], F=mDFMueXLC, S=17, R=27, A=IPC $h, E=\r\n
E 12

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

D 9
R$+<@$+.CSNET>		$@$1%$2.CSNET<@relay.cs.net>	user@host.CSNET
E 6
D 8
R$+<@$+.DEC>		$@$1%$2.DEC<@decwrl.dec.com>	user@host.DEC
E 8
I 6
R$+<@$+.BITNET>		$@$1%$2.BITNET<@jade.berkeley.edu>	 user@host.bitnet
E 9
I 9
ifdef(`BITNET_RELAY',
R$+<@$+.BITNET>		$@$1%$2.BITNET<@$B>		user@host.bitnet)
ifdef(`CSNET_RELAY',
R$+<@$+.CSNET>		$@$1%$2.CSNET<@$C>		user@host.CSNET)
E 9
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

E 13
I 13
D 14
Msmtp,	P=[IPC], F=mDFMueXLC, S=27, R=27, A=IPC $h, E=\r\n
E 14
I 14
Msmtp,	P=[IPC], F=mDFMueXL, S=27, R=27, A=IPC $h, E=\r\n
E 14
E 13
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
D 15
# cleanup
E 6
R$*<$*>$*		$1$2$3				defocus
R$*			$:$>3$1				now canonical form
D 6
R$*%$*<@LOCAL>		$:$>9$1%$2			user%localhost@localdomain
E 6
I 6
R$*%$*<@$w>		$:$>9$1%$2			user%localhost@localdomain
E 15
I 15
# don't touch the special error address
R@			$@@
E 15
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

D 9
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
E 9
I 9
ifdef(`BITNET_RELAY',
R$+<@$+.BITNET>		$@$1%$2.BITNET<@$B>		user@host.BITNET)
ifdef(`CSNET_RELAY',
R$+<@$+.CSNET>		$@$1%$2.CSNET<@$C>		user@host.CSNET)
E 9
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
