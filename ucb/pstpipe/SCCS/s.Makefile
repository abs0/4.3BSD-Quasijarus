h65032
s 00001/00000/00035
d D 5.2 2012/02/17 21:36:28 msokolov 2 1
c call it tps!
e
s 00035/00000/00000
d D 5.1 10/10/09 18:56:49 msokolov 1 0
c written, compiles
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%E%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	buildpipe.c main.c readheader.c
OBJS=	buildpipe.o main.o readheader.o
PROG=	pstpipe

all: ${PROG}

pstpipe: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}

${OBJS}:	docreq.h

clean: FRC
	rm -f *.o a.out errs core ${PROG}

depend:

install: FRC
	install -s -o bin -g bin -m 755 ${PROG} ${DESTDIR}/usr/ucb
I 2
	cd ${DESTDIR}/usr/ucb; rm -f tps; ln pstpipe tps
E 2

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:
E 1
