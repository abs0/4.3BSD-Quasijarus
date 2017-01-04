h50676
s 00007/00015/00026
d D 5.3 04/10/20 17:28:09 msokolov 3 2
c back to 4.3BSD /usr/man format
e
s 00010/00005/00031
d D 5.2 88/07/09 11:39:11 bostic 2 1
c install approved copyright notice
e
s 00036/00000/00000
d D 5.1 87/12/12 18:20:11 bostic 1 0
c date and time created 87/12/12 18:20:11 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 2
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 2
I 2
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 2
#
#	%W% (Berkeley) %G%
#
D 3
MDIR=	/usr/man/cat4/tahoe
SRCS=	ace.4 autoconf.4 cons.4 cy.4 dr.4 enp.4 ik.4 intro.4 lp.4 mem.4 \
	mpcc.4 mpcctab.4 mtio.4 vd.4 vx.4
OBJS=	ace.0 autoconf.0 cons.0 cy.0 dr.0 enp.0 ik.0 intro.0 lp.0 mem.0 \
	mpcc.0 mpcctab.0 mtio.0 vd.0 vx.0
LINKS=	kmem.0
E 3
I 3
MDIR=	/usr/man/man4
E 3

D 3
.SUFFIXES: .4 .0
E 3
I 3
all:
E 3

D 3
.4.0:
	${DESTDIR}/usr/man/manroff $*.4 > $*.0
E 3
I 3
psman: FRC
	for i in *.4; do echo $$i; pstroff -man $$i > $$i.ps; done
E 3

D 3
all: ${OBJS}

E 3
clean: FRC
D 3
	rm -f ${OBJS}
E 3
I 3
	rm -f *.ps
E 3

install: FRC
D 3
	cd ${DESTDIR}${MDIR}; rm -f *.0
	install -c -o bin -g bin -m 444 ${OBJS} ${DESTDIR}${MDIR}
	ln ${DESTDIR}${MDIR}/mem.0 ${DESTDIR}${MDIR}/kmem.0
E 3
I 3
	install -c -o bin -g bin -m 444 *.4 ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.4 ${DESTDIR}${MDIR}
E 3

FRC:
E 1
