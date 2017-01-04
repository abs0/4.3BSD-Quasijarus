h27797
s 00037/00009/00004
d D 5.3 87/06/18 19:37:07 bostic 3 2
c new template
e
s 00002/00000/00011
d D 5.2 87/05/31 21:30:40 bostic 2 1
c added depend label
e
s 00011/00000/00000
d D 5.1 82/12/15 23:19:37 clemc 1 0
c date and time created 82/12/15 23:19:37 by clemc
e
u
U
f b 
t
Virgin BTL M4 as sent out in 4.1
T
I 1
D 3
# %W% (Berkeley) %G%
E 3
I 3
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	m4.c m4y.c
OBJS=	m4.o m4y.o
E 3

D 3
CFLAGS=-O
m4:	m4.o m4y.o
	$(CC) -o m4 m4.o m4y.o 
E 3
I 3
all: m4
E 3

D 3
install:
	install -s m4 $(DESTDIR)/usr/bin
E 3
I 3
m4: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 3

D 3
clean:
	rm -f *.o
E 3
I 3
clean: FRC
	rm -f ${OBJS} core m4 m4y.c
E 3
I 2

D 3
depend:
E 3
I 3
depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 m4 ${DESTDIR}/usr/bin/m4

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

m4.o: m4.c /usr/include/stdio.h /usr/include/signal.h
m4y.o: m4y.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1
