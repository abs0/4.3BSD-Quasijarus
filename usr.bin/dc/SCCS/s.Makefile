h14368
s 00004/00003/00037
d D 1.7 87/07/14 11:57:59 bostic 9 8
c dc.h isn't an OBJECT
e
s 00032/00011/00008
d D 1.6 87/06/18 15:01:02 bostic 8 5
c new template
e
s 00032/00011/00008
d R 1.6 87/06/18 14:59:39 bostic 7 5
c new template
e
s 00031/00010/00009
d R 1.6 87/06/18 14:58:44 bostic 6 5
c new template
e
s 00002/00000/00017
d D 1.5 87/05/31 21:27:36 bostic 5 4
c added depend label
e
s 00002/00002/00015
d D 1.4 83/06/30 14:06:26 sam 4 3
c from sun
e
s 00007/00008/00010
d D 1.3 83/03/30 11:49:38 sam 3 2
c close to what sun sent up
e
s 00001/00000/00017
d D 1.2 83/02/11 16:08:48 rrh 2 1
c Define DESTDIR
e
s 00017/00000/00000
d D 1.1 83/02/11 15:02:06 rrh 1 0
c date and time created 83/02/11 15:02:06 by rrh
e
u
U
t
T
I 1
#
D 8
#	%W%	(Berkeley)	%E%
E 8
I 8
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 8
#
I 2
D 8
DESTDIR=
E 2
D 3
SRCS = dc.c dc.h
E 3
I 3
SRCS=	dc.c dc.h
CFLAGS=	-O
E 8
I 8
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O -I.
LIBC=	/lib/libc.a
SRCS=	dc.c
D 9
OBJS=	dc.h
E 9
I 9
OBJS=
E 9
E 8

E 3
all: dc

D 8
dc:	dc.c dc.h
D 3
	cc -O dc.c -o dc
E 3
I 3
	${CC} ${CFLAGS} dc.c -o dc
E 8
I 8
D 9
dc:	dc.c ${LIBC}
E 9
I 9
dc: dc.c ${LIBC}
E 9
	${CC} ${CFLAGS} dc.c -o $@
E 8
E 3

D 3
install: dc
	install -s dc $(DESTDIR)/usr/bin
E 3
I 3
D 4
install:
E 4
I 4
D 8
install: dc
E 4
	install -s dc ${DESTDIR}/usr/bin/dc
E 8
I 8
clean: FRC
	rm -f ${OBJS} core dc
E 8

E 3
D 8
clean:
D 4
	rm -f *.o
E 4
I 4
	rm -f *.o dc a.out errs core
E 8
I 8
depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}
E 8
I 5

D 8
depend:
E 8
I 8
install: FRC
	install -s -o bin -g bin -m 755 dc ${DESTDIR}/usr/bin/dc

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 9
dc: dc.c /usr/include/stdio.h /usr/include/signal.h dc.h
E 9
I 9
dc: dc.c /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
dc: dc.h
E 9

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 8
E 5
E 4
D 3

sources: srcs
srcs: $(SRCS)
	sccs get $@
E 3
E 1
