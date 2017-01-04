h55745
s 00004/00002/00014
d D 6.1 86/04/20 15:50:17 mckusick 2 1
c 4.3BSD release document
e
s 00016/00000/00000
d D 5.1 86/04/20 15:28:31 mckusick 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
#
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
TROFF=	itroff
E 2
I 2
TROFF=	ditroff -Pdp
TBL=	dtbl -Pdp

E 2
FILES=	abs.ms motivation.ms equip.ms methodology.ms tests.ms results.ms \
	conclusions.ms appendix.ms

paper:	${FILES}
D 2
	@tbl ${FILES} | ${TROFF} -ms
E 2
I 2
	${TBL} ${FILES} | ${TROFF} -ms
E 2

preview:${FILES}
	tbl ${FILES} | nroff -ms | colcrt
E 1
