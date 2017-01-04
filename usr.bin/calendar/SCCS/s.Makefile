h50111
s 00035/00010/00006
d D 4.3 87/06/19 06:11:08 bostic 5 2
c new template
e
s 00035/00010/00006
d R 4.3 87/06/18 15:01:40 bostic 4 2
c new template
e
s 00035/00010/00006
d R 4.3 87/06/18 14:57:25 bostic 3 2
c new template
e
s 00002/00000/00014
d D 4.2 87/05/31 21:27:23 bostic 2 1
c added depend label
e
s 00014/00000/00000
d D 4.1 83/08/13 16:10:00 sam 1 0
c date and time created 83/08/13 16:10:00 by sam
e
u
U
t
T
I 1
D 5
#	%M%	%I%	%E%
E 5
#
D 5
DESTDIR=
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 5
CFLAGS=	-O
I 5
LIBC=	/lib/libc.a
SRCS=	calendar.c
OBJS=	calendar.o
E 5

D 5
calendar: calendar.c
	${CC} ${CFLAGS} -o calendar calendar.c
E 5
I 5
all: calendar
E 5

D 5
install:
	install -s calendar $(DESTDIR)/usr/lib
	install -c -m 755 calendar.sh $(DESTDIR)/usr/bin/calendar
E 5
I 5
calendar: calendar.c ${LIBC}
	${CC} ${CFLAGS} -o $@ calendar.c
E 5

D 5
clean:
	rm -f calendar
E 5
I 5
clean: FRC
	rm -f ${OBJS} core calendar
E 5
I 2

D 5
depend:
E 5
I 5
depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 calendar ${DESTDIR}/usr/lib
	install -c -o bin -g bin -m 755 calendar.sh ${DESTDIR}/usr/bin/calendar

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

calendar.o: calendar.c /usr/include/sys/time.h /usr/include/time.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 2
E 1
