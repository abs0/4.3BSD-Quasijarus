#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	5.3	(Berkeley)	2012/07/18
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	common.c embedfonts.c finishmain.c mergemain.c output.c pass1.c pass2.c
COBJS=	common.o embedfonts.o output.o pass1.o pass2.o
MOBJS=	${COBJS} mergemain.o
FOBJS=	${COBJS} finishmain.o
ALLOBJS=${COBJS} finishmain.o mergemain.o
PROGS=	pstmerge pstfinish

all: ${PROGS}

pstmerge: ${MOBJS} ${LIBC}
	${CC} -o $@ ${MOBJS}

pstfinish: ${FOBJS} ${LIBC}
	${CC} -o $@ ${FOBJS}

${ALLOBJS}:	struct.h

clean: FRC
	rm -f *.o *.out errs core ${PROGS}

depend:

install: FRC
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:
