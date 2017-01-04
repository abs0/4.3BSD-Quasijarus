h62121
s 00002/00001/00057
d D 5.4 04/10/28 01:08:32 msokolov 4 3
c fix install:	must double the $'s
e
s 00010/00004/00048
d D 5.3 04/08/21 20:01:02 msokolov 3 2
c banner filter is here
e
s 00008/00004/00044
d D 5.2 04/08/04 07:24:38 msokolov 2 1
c add lppsif
e
s 00048/00000/00000
d D 5.1 04/07/30 02:19:58 msokolov 1 0
c date and time created 04/07/30 02:19:58 by msokolov
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
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBDIR=	/usr/lib
D 2
SRCS=	lppsjf.c
OBJS=	lppsjf.o
E 2
I 2
D 3
SRCS=	lppsif.c lppsjf.c
OBJS=	lppsif.o lppsjf.o
E 3
I 3
SRCS=	lppsbf.c lppsif.c lppsjf.c
OBJS=	lppsbf.o lppsif.o lppsjf.o
E 3
E 2

D 2
all: lppsjf
E 2
I 2
D 3
all: lppsif lppsjf
E 3
I 3
all: lppsbf lppsif lppsjf
E 3
E 2

I 3
lppsbf: lppsbf.c
	${CC} -o $@ ${CFLAGS} lppsbf.c

E 3
I 2
lppsif: lppsif.c
	${CC} -o $@ ${CFLAGS} lppsif.c

E 2
lppsjf: lppsjf.c
	${CC} -o $@ ${CFLAGS} lppsjf.c

clean: FRC
D 2
	rm -f ${OBJS} core a.out errs lppsjf
E 2
I 2
D 3
	rm -f ${OBJS} core a.out errs lppsif lppsjf
E 3
I 3
	rm -f ${OBJS} core a.out errs lppsbf lppsif lppsjf
E 3
E 2

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
I 3
	install -s -o bin -g bin -m 755 lppsbf ${DESTDIR}/${LIBDIR}/lppsbf
E 3
I 2
	install -s -o bin -g bin -m 755 lppsif ${DESTDIR}/${LIBDIR}/lppsif
E 2
	install -s -o bin -g bin -m 755 lppsjf ${DESTDIR}/${LIBDIR}/lppsjf
I 3
D 4
	sed -e 's/%.*$//' -e '/^$/d' banner.ps > ${DESTDIR}/${LIBDIR}/lppsbanner
E 4
I 4
	sed -e 's/%.*$$//' -e '/^$$/d' banner.ps > \
		${DESTDIR}/${LIBDIR}/lppsbanner
E 4
	chown bin.bin ${DESTDIR}/${LIBDIR}/lppsbanner
E 3

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 1
