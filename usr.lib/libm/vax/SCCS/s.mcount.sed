h65535
s 00008/00000/00007
d D 5.2 88/04/29 13:28:42 bostic 6 5
c add Berkeley copyright; NOTE: this code is AT&T derived!
e
s 00000/00000/00007
d D 5.1 87/11/30 18:49:57 bostic 5 4
c tahoe release
e
s 00000/00000/00007
d D 1.3 85/09/12 22:20:37 elefunt 4 2
c adding sccsid asciz string to each source file.
e
s 00000/00000/00007
d R 1.3 85/09/12 22:16:10 elefunt 3 2
c adding sccsid asciz string to each source file.
e
s 00000/00000/00007
d D 1.2 85/09/12 20:17:29 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00007/00000/00000
d D 1.1 85/09/06 17:50:26 zliu 1 0
c date and time created 85/09/06 17:50:26 by zliu
e
u
U
t
T
I 6
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#

E 6
I 1
s/.word	0x0.*$/&\
	.data\
1:\
	.long	0\
	.text\
	moval	1b,r0\
	jsb	mcount/
E 1
