h07456
s 00008/00015/00026
d D 5.4 04/10/20 19:08:31 msokolov 4 3
c back to 4.3BSD /usr/man format
e
s 00002/00002/00039
d D 5.3 04/01/02 10:55:09 msokolov 3 2
c add koi(7)
e
s 00010/00005/00031
d D 5.2 88/07/09 11:33:37 bostic 2 1
c install approved copyright notice
e
s 00036/00000/00000
d D 5.1 87/12/12 18:22:56 bostic 1 0
c date and time created 87/12/12 18:22:56 by bostic
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
D 4
MDIR=	/usr/man/cat7
D 3
SRCS=	ascii.7 environ.7 eqnchar.7 hier.7 hostname.7 intro.7 mailaddr.7 \
E 3
I 3
SRCS=	ascii.7 environ.7 eqnchar.7 hier.7 hostname.7 intro.7 koi.7 mailaddr.7 \
E 3
	man.7 me.7 ms.7 term.7
D 3
OBJS=	ascii.0 environ.0 eqnchar.0 hier.0 hostname.0 intro.0 mailaddr.0 \
E 3
I 3
OBJS=	ascii.0 environ.0 eqnchar.0 hier.0 hostname.0 intro.0 koi.0 mailaddr.0 \
E 3
	man.0 me.0 ms.0 term.0
LINKS=	miscellaneous.0
E 4
I 4
MDIR=	/usr/man/man7
E 4

D 4
.SUFFIXES: .7 .0
E 4
I 4
all:
E 4

D 4
.7.0:
	${DESTDIR}/usr/man/manroff $*.7 > $*.0
E 4
I 4
psman: FRC
	for i in *.7; do echo $$i; pstroff -man $$i > $$i.ps; done
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
	ln ${DESTDIR}${MDIR}/intro.0 ${DESTDIR}${MDIR}/miscellaneous.0
E 4
I 4
	cd ${DESTDIR}${MDIR}; rm -f *
	install -c -o bin -g bin -m 444 *.7 ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.7 ${DESTDIR}${MDIR}
E 4

FRC:
E 1
