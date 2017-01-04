h54513
s 00019/00000/00007
d D 5.3 88/04/29 13:27:37 bostic 7 6
c add Berkeley specific header
e
s 00000/00000/00007
d D 5.2 87/11/30 18:49:10 bostic 6 5
c tahoe release
e
s 00000/00000/00007
d D 5.1 87/11/30 18:46:17 bostic 5 4
c tahoe release
e
s 00003/00003/00004
d D 1.2 87/07/13 13:40:04 zliu 4 1
c jsb->callf; 1:->9:
e
s 00001/00001/00006
d R 1.2 87/07/13 13:35:21 zliu 3 1
c jsb->callf
e
s 00000/00000/00007
d R 1.2 87/07/13 13:06:10 zliu 2 1
c various clean-ups; added Makefile and mcount.sed.
e
s 00007/00000/00000
d D 1.1 87/07/13 13:03:01 zliu 1 0
c date and time created 87/07/13 13:03:01 by zliu
e
u
U
t
T
I 7
#
# Copyright (c) 1985 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
# All recipients should regard themselves as participants in an ongoing
# research project and hence should feel obligated to report their
# experiences (good or bad) with these elementary function codes, using
# the sendbug(8) program, to the authors.
#
#	%W% (Berkeley) %G%
#

E 7
I 1
s/.word	0x.*$/&\
	.data\
	.align 2\
D 4
1:	.long 0\
E 4
I 4
9:	.long 0\
E 4
	.text\
D 4
	pushal	1b\
	callf	$8,mcount/
E 4
I 4
	pushal	9b\
	callf	\$8,mcount/
E 4
E 1
