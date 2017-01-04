h62861
s 00040/00000/00000
d D 5.1 87/12/12 17:41:10 bostic 1 0
c date and time created 87/12/12 17:41:10 by bostic
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
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	fpr.c
OBJS=	fpr.o

all: fpr

fpr:	${SRCS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${SRCS}

clean: FRC
	rm -f ${OBJS} core fpr

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 fpr ${DESTDIR}/usr/ucb/fpr

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

fpr: fpr.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
