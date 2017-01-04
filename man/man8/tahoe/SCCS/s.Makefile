h02859
s 00006/00011/00026
d D 5.3 04/10/20 20:02:31 msokolov 3 2
c back to 4.3BSD /usr/man format
e
s 00000/00000/00037
d D 5.2 04/10/20 19:52:20 msokolov 2 1
c bump it up to 5.2
e
s 00037/00000/00000
d D 5.1 04/10/20 19:52:01 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 5.2
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
#
#	%W% (Berkeley) %G%
#
D 3
MDIR=	/usr/man/cat8/tahoe
SRCS=	crash.8 dlmpcc.8 enpload.8 reboot.8 vdformat.8
OBJS=	crash.0 dlmpcc.0 enpload.0 reboot.0 vdformat.0
E 3
I 3
MDIR=	/usr/man/man8
E 3

D 3
.SUFFIXES: .8 .0
E 3
I 3
all:
E 3

D 3
.8.0:
	${DESTDIR}/usr/man/manroff $*.8 > $*.0
E 3
I 3
psman: FRC
	for i in *.8; do echo $$i; pstroff -man $$i > $$i.ps; done
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
E 3
I 3
	install -c -o bin -g bin -m 444 *.8 ${DESTDIR}${MDIR}
E 3

FRC:
E 1
