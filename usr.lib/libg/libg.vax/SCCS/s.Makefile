h61598
s 00023/00007/00004
d D 5.2 87/06/19 11:20:28 bostic 2 1
c new template
e
s 00011/00000/00000
d D 5.1 85/07/12 19:31:28 mckusick 1 0
c date and time created 85/07/12 19:31:28 by mckusick
e
u
U
t
T
I 1
#
D 2
#	%W%	(Berkeley)	%E%
E 2
I 2
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 2
#
D 2
libg.a:	dbxxx.s
	as dbxxx.s -o libg.a
E 2
I 2
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=
OBJS=
E 2

D 2
install: libg.a
	install -c libg.a ${DESTDIR}/usr/lib
E 2
I 2
all: libg.a
E 2

D 2
clean:
	rm -f libg.a
E 2
I 2
libg.a: dbxxx.s
	${AS} dbxxx.s -o $@

clean: FRC
	rm -f ${OBJS} core libg.a

install: FRC
	install -o bin -g bin -m 644 libg.a ${DESTDIR}/usr/lib/libg.a

depend:
lint:
tags:
FRC:
E 2
E 1
