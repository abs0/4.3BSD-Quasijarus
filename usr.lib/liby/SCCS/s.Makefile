h40786
s 00033/00013/00009
d D 5.2 87/06/30 21:25:32 bostic 3 1
c new template
e
s 00033/00013/00009
d R 5.2 87/06/19 16:30:39 bostic 2 1
c new template
e
s 00022/00000/00000
d D 5.1 85/08/09 21:45:42 mckusick 1 0
c date and time created 85/08/09 21:45:42 by mckusick
e
u
U
t
T
I 1
#
D 3
# Copyright (c) 1985 Regents of the University of California.
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
E 3
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 3
#	%W% (Berkeley) %G%
E 3
I 3
#	%W%	(Berkeley)	%G%
E 3
#
D 3
# Make a Yacc library
#
DESTDIR=
CFLAGS=-O 
E 3
I 3
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	libmai.c libzer.c
OBJS=	libmai.o libzer.o
E 3

D 3
liby.a:	libmai.o libzer.o
	ar rv liby.a libmai.o libzer.o
	ranlib liby.a
E 3
I 3
all: liby.a
E 3

D 3
install: liby.a
	install liby.a ${DESTDIR}/usr/lib/liby.a
E 3
I 3
liby.a: ${OBJS}
	ar cr $@ ${OBJS}

clean: FRC
	rm -f ${OBJS} core liby.a

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -o bin -g bin -m 644 liby.a ${DESTDIR}/usr/lib/liby.a
E 3
	ranlib ${DESTDIR}/usr/lib/liby.a

D 3
clean:
	rm -f *.o *.a errs
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

libmai.o: libmai.c
libzer.o: libzer.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
