h00680
s 00053/00012/00010
d D 4.6 87/07/30 10:38:57 bostic 6 5
c new template
e
s 00001/00001/00021
d D 4.5 84/08/26 00:03:01 sam 5 4
c remove commands on cleanup
e
s 00002/00002/00020
d D 4.4 84/08/25 22:04:44 sam 4 3
c rewrite and speed up 
e
s 00001/00002/00021
d D 4.3 83/03/10 19:19:28 sam 3 2
c use install
e
s 00002/00000/00021
d D 4.2 83/02/23 22:50:22 shannon 2 1
c add dependency on compact.h
e
s 00021/00000/00000
d D 4.1 83/02/11 14:56:43 shannon 1 0
c date and time created 83/02/11 14:56:43 by shannon
e
u
U
t
T
I 1
D 6
#	%M%	%I%	%E%

CFLAGS=-O
E 6
I 6
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 6
DESTDIR=
I 6
CFLAGS=-O
SRCS=	compact.c tree.c uncompact.c
OBJS=	compact.o tree.o uncompact.o
MDIR=	/usr/man/cat.old
LINKS=	
E 6

I 6
.SUFFIXES: .1 .0

.1.0:
	/usr/man/manroff $*.1 > $*.0

E 6
all: compact uncompact

compact: compact.o tree.o
D 4
	cc compact.o tree.o -o compact
E 4
I 4
D 6
	${CC} ${LDFLAGS} compact.o tree.o -o compact
E 6
I 6
	${CC} ${LDFLAGS} compact.o tree.o -o $@
E 6
E 4

uncompact: uncompact.o tree.o
D 4
	cc uncompact.o tree.o -o uncompact
E 4
I 4
D 6
	${CC} ${LDFLAGS} uncompact.o tree.o -o uncompact
E 6
I 6
	${CC} ${LDFLAGS} uncompact.o tree.o -o $@
E 6
E 4

I 2
D 6
compact.o uncompact.o tree.o: compact.h
E 6
I 6
install: compact.0
#	install -s -o bin -g bin -m 755 compact ${DESTDIR}/usr/old/compact
	install -s -o bin -g bin -m 755 uncompact ${DESTDIR}/usr/old/uncompact
	install -c -o bin -g bin -m 755 ccat.sh ${DESTDIR}/usr/old/ccat
	install -c -o bin -g bin -m 755 compact.0 ${DESTDIR}${MDIR}/compact.0
	(cd ${DESTDIR}${MDIR};rm -f ccat.0 uncompact.0)
	ln ${DESTDIR}${MDIR}/compact.0 ${DESTDIR}${MDIR}/ccat.0
	ln ${DESTDIR}${MDIR}/compact.0 ${DESTDIR}${MDIR}/uncompact.0
E 6

E 2
D 6
install:
	install -s compact ${DESTDIR}/usr/ucb
	install -s uncompact ${DESTDIR}/usr/ucb
D 3
	cp ccat.sh ${DESTDIR}/usr/ucb/ccat
	chmod 755 ${DESTDIR}/usr/ucb/ccat
E 3
I 3
	install -c -m 755 ccat.sh ${DESTDIR}/usr/ucb/ccat
E 3

E 6
clean:
D 5
	rm -f compact.o uncompact.o tree.o
E 5
I 5
D 6
	rm -f compact uncompact compact.o uncompact.o tree.o
E 6
I 6
	rm -f compact uncompact ${OBJS}

depend:
	mkdep ${SRCS}

tags:
	ctags ${SRCS}

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

compact.o: compact.c /usr/include/strings.h compact.h /usr/include/sys/param.h
compact.o: /usr/include/sys/types.h /usr/include/signal.h
compact.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
compact.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/stdio.h
tree.o: tree.c compact.h /usr/include/sys/param.h /usr/include/sys/types.h
tree.o: /usr/include/signal.h /usr/include/machine/trap.h
tree.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
tree.o: /usr/include/sys/dir.h /usr/include/stdio.h
uncompact.o: uncompact.c compact.h /usr/include/sys/param.h
uncompact.o: /usr/include/sys/types.h /usr/include/signal.h
uncompact.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
uncompact.o: /usr/include/sys/stat.h /usr/include/sys/dir.h
uncompact.o: /usr/include/stdio.h /usr/include/strings.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 6
E 5
E 1
