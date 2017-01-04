h04291
s 00007/00015/00026
d D 5.4 04/10/20 20:02:44 msokolov 4 3
c back to 4.3BSD /usr/man format
e
s 00002/00002/00039
d D 5.3 99/06/02 21:13:11 msokolov 3 2
c installboot has been laid to rest, disklabel does its job now
e
s 00010/00005/00031
d D 5.2 88/07/09 11:32:41 bostic 2 1
c install approved copyright notice
e
s 00036/00000/00000
d D 5.1 87/12/12 18:24:27 bostic 1 0
c date and time created 87/12/12 18:24:27 by bostic
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
D 4
MDIR=	/usr/man/cat8/vax
D 3
SRCS=	arff.8 bad144.8 crash.8 drtest.8 format.8 installboot.8 rxformat.8 \
E 3
I 3
SRCS=	arff.8 bad144.8 crash.8 drtest.8 format.8 rxformat.8 \
E 3
	reboot.8
D 3
OBJS=	arff.0 bad144.0 crash.0 drtest.0 format.0 installboot.0 rxformat.0 \
E 3
I 3
OBJS=	arff.0 bad144.0 crash.0 drtest.0 format.0 rxformat.0 \
E 3
	reboot.0
LINKS=	flcopy.0
E 4
I 4
MDIR=	/usr/man/man8
E 4

D 4
.SUFFIXES: .8 .0
E 4
I 4
all:
E 4

D 4
.8.0:
	${DESTDIR}/usr/man/manroff $*.8 > $*.0
E 4
I 4
psman: FRC
	for i in *.8 *.8v; do echo $$i; pstroff -man $$i > $$i.ps; done
E 4

D 4
all: ${OBJS}

E 4
clean: FRC
D 4
	rm -f ${OBJS}
E 4
I 4
	rm -f *.ps
E 4

install: FRC
D 4
	cd ${DESTDIR}${MDIR}; rm -f *.0
	install -c -o bin -g bin -m 444 ${OBJS} ${DESTDIR}${MDIR}
	ln ${DESTDIR}${MDIR}/arff.0 ${DESTDIR}${MDIR}/flcopy.0
E 4
I 4
	install -c -o bin -g bin -m 444 *.8 *.8v ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.8v ${DESTDIR}${MDIR}
E 4

FRC:
E 1
