h31630
s 00002/00002/00013
d D 1.4 88/04/06 14:53:14 rwh 4 3
c Add full domain name for jade.berkeley.edu 
e
s 00002/00004/00013
d D 1.3 88/03/31 23:40:40 phil 3 2
c Remove .DEC and .MailNET.
e
s 00001/00001/00016
d D 1.2 87/07/05 20:09:53 phil 2 1
c Removed C macro for bitnet.
e
s 00017/00000/00000
d D 1.1 87/05/08 15:29:37 phil 1 0
c date and time created 87/05/08 15:29:37 by phil
e
u
U
t
T
I 1
divert(10)dnl
#
# Handle "fake" top level domains, by sending to a smarter
# host.  Currently, we support:
#
D 4
#	user@host.bitnet	->	jade		user@host.bitnet
E 4
I 4
#	user@host.bitnet	->	jade.berkeley.edu	user@host.bitnet
E 4
#	user@host.csnet		->	relay.cs.net	user@host.csnet
D 3
#	user@host.dec	(ugh)	->	decwrl.cs.net	user@host.dec
#	user@host.mailnet	->	mit-multics.arpa user@host.csnet
E 3
#
I 3
# Eventually, all these should Go Away.
#
E 3
# %W% (Berkeley) %G%
#
divert(0)dnl
D 2
R$*<@$+.BITNET>$*	$#tcpld$@$C$:$1<@$2.BITNET>$3		user@host.BITNET
E 2
I 2
D 4
R$*<@$+.BITNET>$*	$#tcpld$@jade$:$1<@$2.BITNET>$3		user@host.BITNET
E 4
I 4
R$*<@$+.BITNET>$*	$#tcpld$@jade.berkeley.edu$:$1<@$2.BITNET>$3	user@host.BITNET
E 4
E 2
R$*<@$+.CSNET>$*	$#tcp$@relay.cs.net$:$1<@$2.CSNET>$3	user@host.CSNET
D 3
R$*<@$+.DEC>$*		$#tcp$@decwrl.dec.com$:$1<@$2.DEC>$3	user@host.DEC
R$*<@$+.MailNET>$*	$#tcp$@mit-multics.arpa$:$1<@$2.MailNET>$3	user@host.MailNET
E 3
E 1
