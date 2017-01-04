#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	5.2	(Berkeley)	2012/02/17
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
	cd ${DESTDIR}/usr/ucb; rm -f tps; ln pstpipe tps

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:
