h00754
s 00011/00002/00008
d D 5.1 85/06/07 16:20:56 dist 6 5
m 
c Add copyright
e
s 00000/00000/00010
d D 4.1 83/07/25 19:42:52 eric 5 4
m 
c 4.2 release version
e
s 00000/00000/00010
d D 3.1 81/03/07 14:25:19 eric 4 3
c ----- delivermail ==> postbox -----
e
s 00000/00000/00010
d D 2.1 80/11/05 10:59:58 eric 3 2
c release 2
e
s 00006/00000/00005
d D 1.2 80/07/25 22:02:51 eric 2 1
c add ID keywords
e
s 00005/00000/00000
d D 1.1 80/06/23 08:23:35 eric 1 0
e
u
U
f b 
f i 
t
T
I 2
#
D 6
#  BMOVE.S -- optimized block move routine.
E 6
I 6
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 6
#
D 6
#	%W%	%G%
E 6
I 6
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
#
#  BMOVE.S -- optimized block move routine.
E 6
#
E 2
I 1
.globl	_bmove
_bmove:
	.word	0x0030
	movc3	12(ap),*4(ap),*8(ap)
	ret
E 1
