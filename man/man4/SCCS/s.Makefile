h08542
s 00012/00015/00026
d D 5.3 04/10/20 17:27:55 msokolov 3 2
c back to 4.3BSD /usr/man format
e
s 00010/00005/00031
d D 5.2 88/07/09 11:38:34 bostic 2 1
c install approved copyright notice
e
s 00036/00000/00000
d D 5.1 87/12/12 18:19:18 bostic 1 0
c date and time created 87/12/12 18:19:18 by bostic
e
u
U
f b 
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
MDIR=	/usr/man/cat4
SRCS=	arp.4 bk.4 drum.4 icmp.4 idp.4 imp.4 inet.4 ip.4 kdb.4 \
	lo.4 netintro.4 ns.4 nsip.4 null.4 pty.4 spp.4 tcp.4 tty.4 udp.4
OBJS=	arp.0 bk.0 drum.0 icmp.0 idp.0 imp.0 inet.0 ip.0 kdb.0 \
	lo.0 netintro.0 ns.0 nsip.0 null.0 pty.0 spp.0 tcp.0 tty.0 udp.0
LINKS=	networking.0
E 3
I 3
MDIR=	/usr/man/man4
SUBDIR=	tahoe vax
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
	for i in *.4 *.4?; do echo $$i; pstroff -man $$i > $$i.ps; done
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} psman); done
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
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 3

install: FRC
D 3
	cd ${DESTDIR}${MDIR}; rm -f *.0
	install -c -o bin -g bin -m 444 ${OBJS} ${DESTDIR}${MDIR}
	ln ${DESTDIR}${MDIR}/netintro.0 ${DESTDIR}${MDIR}/networking.0
E 3
I 3
	cd ${DESTDIR}${MDIR}; rm -f *.4 *.4?
	install -c -o bin -g bin -m 444 *.4 *.4? ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.4? ${DESTDIR}${MDIR}
	cd ${MACHINE}; make ${MFLAGS} DESTDIR=${DESTDIR} install
E 3

FRC:
E 1
