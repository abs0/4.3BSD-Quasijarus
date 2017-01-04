h22337
s 00034/00007/00006
d D 5.3 87/06/19 11:18:35 bostic 3 2
c new template
e
s 00004/00002/00009
d D 5.2 86/07/26 13:19:16 sam 2 1
c tahoe
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
D 3
#	%W%	(Berkeley)	%E%
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 3
#
D 2
libg.a:	dbxxx.s
	as dbxxx.s -o libg.a
E 2
I 2
D 3
DESTDIR=
E 3
I 3
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	dbxxx.c
OBJS=	dbxxx.o
E 3

D 3
libg.a:	dbxxx.c
E 3
I 3
all: libg.a

libg.a: dbxxx.c
E 3
	${CC} -E dbxxx.c | ${AS} -o libg.a
E 2

D 3
install: libg.a
	install -c libg.a ${DESTDIR}/usr/lib
E 3
I 3
clean: FRC
	rm -f ${OBJS} core libg.a
E 3

D 3
clean:
	rm -f libg.a
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -o bin -g bin -m 644 libg.a ${DESTDIR}/usr/lib/libg.a

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

dbxxx.o: dbxxx.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
