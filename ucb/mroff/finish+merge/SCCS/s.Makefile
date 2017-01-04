h60523
s 00012/00009/00029
d D 5.3 2012/07/18 04:21:59 msokolov 3 2
c pstfinish reimplemented natively, not as a front-end
e
s 00002/00002/00036
d D 5.2 10/10/09 04:30:41 msokolov 2 1
c added -F option (font embedding)
e
s 00038/00000/00000
d D 5.1 10/10/08 06:56:01 msokolov 1 0
c date and time created 10/10/08 06:56:01 by msokolov
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
D 3
#	%W%	(Berkeley)	%G%
E 3
I 3
#	%W%	(Berkeley)	%E%
E 3
#
CFLAGS=	-O
LIBC=	/lib/libc.a
D 2
SRCS=	main.c output.c pass1.c pass2.c
OBJS=	main.o output.o pass1.o pass2.o
E 2
I 2
D 3
SRCS=	embedfonts.c main.c output.c pass1.c pass2.c
OBJS=	embedfonts.o main.o output.o pass1.o pass2.o
E 3
I 3
SRCS=	common.c embedfonts.c finishmain.c mergemain.c output.c pass1.c pass2.c
COBJS=	common.o embedfonts.o output.o pass1.o pass2.o
MOBJS=	${COBJS} mergemain.o
FOBJS=	${COBJS} finishmain.o
ALLOBJS=${COBJS} finishmain.o mergemain.o
E 3
E 2
PROGS=	pstmerge pstfinish

all: ${PROGS}

D 3
pstmerge: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}
E 3
I 3
pstmerge: ${MOBJS} ${LIBC}
	${CC} -o $@ ${MOBJS}
E 3

D 3
${OBJS}:	struct.h
E 3
I 3
pstfinish: ${FOBJS} ${LIBC}
	${CC} -o $@ ${FOBJS}
E 3

D 3
pstfinish: pstfinish.c
	${CC} -o $@ ${CFLAGS} pstfinish.c
E 3
I 3
${ALLOBJS}:	struct.h
E 3

clean: FRC
D 3
	rm -f *.o a.out errs core ${PROGS}
E 3
I 3
	rm -f *.o *.out errs core ${PROGS}
E 3

depend:

install: FRC
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:
E 1
