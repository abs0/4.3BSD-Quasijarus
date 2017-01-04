h55169
s 00050/00000/00000
d D 5.1 04/10/30 00:29:35 msokolov 1 0
c psmgmt separated from psutils
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
SRCS=	lppsspd.c
PROGS=	lppsspd
PSFILES=l2trayconfutil.ps

all:	${PROGS}

lppsspd: lppsspd.c
	${CC} -o $@ ${CFLAGS} lppsspd.c

clean: FRC
	rm -f *.o core a.out errs ${PROGS}

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/${LIBDIR}
	install -c -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}/${LIBDIR}/psutils

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 1
