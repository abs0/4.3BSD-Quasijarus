h30798
s 00035/00010/00005
d D 4.3 87/06/18 17:51:34 bostic 3 2
c new template
e
s 00002/00000/00013
d D 4.2 87/05/31 21:29:37 bostic 2 1
c added depend label
e
s 00013/00000/00000
d D 4.1 83/03/30 12:03:04 sam 1 0
c date and time created 83/03/30 12:03:04 by sam
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
#
D 3
CFLAGS=-O
DESTDIR=
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	graph.c
OBJS=	graph.o
E 3

D 3
graph: graph.c
	${CC} $(CFLAGS) -o graph graph.c -lplot -lm
E 3
I 3
all: graph
E 3

D 3
install: graph
	install -s graph ${DESTDIR}/usr/bin/graph
E 3
I 3
graph: ${SRCS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${SRCS} -lplot -lm
E 3

D 3
clean:
	rm -f *.o graph
E 3
I 3
clean: FRC
	rm -f ${OBJS} core graph
E 3
I 2

D 3
depend:
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 graph ${DESTDIR}/usr/bin/graph

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

graph.o: graph.c /usr/include/stdio.h /usr/include/ctype.h /usr/include/math.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1
