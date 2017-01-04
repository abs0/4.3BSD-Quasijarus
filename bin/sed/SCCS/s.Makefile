h28541
s 00036/00011/00005
d D 4.3 87/06/03 00:05:16 bostic 3 2
c new template
e
s 00002/00000/00014
d D 4.2 87/05/31 20:33:24 bostic 2 1
c added depend label
e
s 00014/00000/00000
d D 4.1 85/04/05 09:29:10 ralph 1 0
c date and time created 85/04/05 09:29:10 by ralph
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
CFLAGS=-O -w
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O -w
LIBC=	/lib/libc.a
SRCS=	sed0.c sed1.c
OBJS=	sed0.o sed1.o
E 3

D 3
sed:	sed0.o sed1.o
	cc -o sed *.o
E 3
I 3
all: sed
E 3

D 3
sed0.o: sed0.c sed.h
sed1.o: sed1.c sed.h
E 3
I 3
sed:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 3

D 3
install: sed
	install -s sed $(DESTDIR)/bin
clean:
	rm -f *.o sed
E 3
I 3
clean: FRC
	rm -f ${OBJS} core sed
E 3
I 2

D 3
depend:
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 sed ${DESTDIR}/bin/sed

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

sed0.o: sed0.c /usr/include/stdio.h sed.h
sed1.o: sed1.c /usr/include/stdio.h sed.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1
