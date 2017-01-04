h56284
s 00005/00004/00015
d D 4.2 85/07/18 22:43:35 mckusick 2 1
c update to reflect 4.3BSD version of fsck
e
s 00019/00000/00000
d D 4.1 85/06/03 17:31:54 mckusick 1 0
c date and time created 85/06/03 17:31:54 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1982 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
SRCS=	0.t 1.t 2.t 3.t 4.t
D 2
TROFF=	itroff
TYPE=	-t
E 2
I 2
TROFF=	ditroff
PRINTER=-Pdp
TYPE=	-n
E 2

paper:	fsck.t
D 2
	lpr -Pimagen ${TYPE} fsck.t
E 2
I 2
	lpr ${PRINTER} ${TYPE} fsck.t
E 2

fsck.t:	${SRCS}
D 2
	${TROFF} -ms -t ${SRCS} > fsck.t
E 2
I 2
	${TROFF} ${PRINTER} -ms -t ${SRCS} > fsck.t
E 2

clean:
	rm -f fsck.t
E 1
