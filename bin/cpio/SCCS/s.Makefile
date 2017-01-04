h57800
s 00000/00019/00047
d D 5.4 99/09/27 18:23:17 msokolov 5 4
c man pages move to /usr/src/man
e
s 00010/00005/00056
d D 5.3 88/07/09 11:22:06 bostic 4 3
c install approved copyright notice
e
s 00015/00005/00046
d D 5.2 88/03/29 15:19:16 bostic 3 1
c add manual pages
e
s 00014/00004/00047
d R 5.2 88/03/29 15:18:39 bostic 2 1
c add manual pages
e
s 00051/00000/00000
d D 5.1 88/03/29 13:49:01 bostic 1 0
c date and time created 88/03/29 13:49:01 by bostic
e
u
U
t
T
I 1
#
D 3
# Copyright (c) 1987 Regents of the University of California.
E 3
I 3
# Copyright (c) 1988 Regents of the University of California.
E 3
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 4
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
D 3
# software without specific written prior permission. This software
E 3
I 3
# software without specific prior written permission. This software
E 3
# is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
#
#	%W% (Berkeley) %G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	cpio.c
OBJS=
I 3
D 5
MAN=	cpio.0 cpio_format.0
E 5
E 3

I 3
D 5
.SUFFIXES: .5 .1 .0

.1.0:
	${DESTDIR}/usr/man/manroff $*.1 > $*.0
.5.0:
	${DESTDIR}/usr/man/manroff $*.5 > $*.0

E 5
E 3
all: cpio

cpio: ${LIBC}
	${CC} -o $@ ${CFLAGS} cpio.c

clean: FRC
D 3
	rm -f ${OBJS} core cpio
E 3
I 3
	rm -f ${OBJS} ${MAN} core cpio
E 3

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

D 3
install: FRC
	install -s -o bin -g bin -m 755 PROG ${DESTDIR}/bin/cpio
E 3
I 3
install: ${MAN} FRC
	install -s -o bin -g bin -m 755 cpio ${DESTDIR}/bin/cpio
D 5
	install -c -o bin -g bin -m 444 cpio.0 ${DESTDIR}/usr/man/cat1/cpio.0
	install -c -o bin -g bin -m 444 cpio_format.0 ${DESTDIR}/usr/man/cat5/cpio.0
E 5
E 3

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
D 5

cpio: cpio.c /usr/include/errno.h /usr/include/fcntl.h /usr/include/memory.h
cpio: /usr/include/stdio.h /usr/include/string.h /usr/include/strings.h
cpio: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/varargs.h
cpio: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
cpio: /usr/include/machine/machparam.h /usr/include/machine/endian.h
cpio: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/pwd.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1
