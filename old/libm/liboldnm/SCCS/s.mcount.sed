h36992
s 00007/00000/00007
d D 5.1 85/05/08 12:37:25 dist 2 1
c Create SCCS file, add copyright
e
s 00007/00000/00000
d D 1.1 85/05/08 12:21:58 dist 1 0
c date and time created 85/05/08 12:21:58 by dist
e
u
U
t
T
I 2
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 2
I 1
s/.word	0x0.*$/&\
	.data\
1:\
	.long	0\
	.text\
	moval	1b,r0\
	jsb	mcount/
E 1
