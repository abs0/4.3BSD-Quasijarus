h10800
s 00029/00013/00020
d D 5.4 87/06/19 11:15:06 bostic 4 3
c new template
e
s 00001/00001/00032
d D 5.3 86/04/30 07:51:56 lepreau 3 2
c make dbm.h mode 444
e
s 00006/00001/00027
d D 5.2 85/06/26 14:36:55 bloom 2 1
c Add copyright
e
s 00028/00000/00000
d D 5.1 85/06/25 18:56:40 kre 1 0
c date and time created 85/06/25 18:56:40 by kre
e
u
U
t
T
I 1
D 2
#	%M%	%I%	%E%
E 2
I 2
#
D 4
# Copyright (c) 1980 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
E 2
#
D 4
CFLAGS=-O
TAGSFILE=tags
E 4
I 4
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	dbm.c
OBJS=	dbm.o
E 4

all: libdbm.a libdbm_p.a

libdbm.a: dbm.c
	${CC} -c ${CFLAGS} dbm.c
	ld -r -o libdbm.a -x dbm.o
	rm -f dbm.o

libdbm_p.a: dbm.c
	${CC} -p -c ${CFLAGS} dbm.c
	ld -r -o libdbm_p.a -X dbm.o
	rm -f dbm.o

D 4
install: all
	install -m 644 libdbm.a $(DESTDIR)/usr/lib
	install -m 644 libdbm_p.a $(DESTDIR)/usr/lib
	-cmp -s dbm.h $(DESTDIR)/usr/include/dbm.h || \
D 3
		install -c -m 644 dbm.h $(DESTDIR)/usr/include
E 3
I 3
		install -c -m 444 dbm.h $(DESTDIR)/usr/include
E 4
I 4
clean: FRC
	rm -f ${OBJS} core libdbm.a libdbm_p.a
E 4
E 3

D 4
tags:
	ctags -a -f ${TAGSFILE} `pwd`/dbm.c
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 4

D 4
clean:
	rm -f *.o libdbm.a libdbm_p.a errs a.out core
E 4
I 4
install: FRC
	install -o bin -g bin -m 644 libdbm.a ${DESTDIR}/usr/lib/libdbm.a
	install -o bin -g bin -m 644 libdbm_p.a ${DESTDIR}/usr/lib/libdbm_p.a
	install -c -o bin -g bin -m 444 dbm.h ${DESTDIR}/usr/include/dbm.h

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

dbm.o: dbm.c dbm.h /usr/include/ndbm.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1
