h12381
s 00042/00017/00006
d D 4.3 87/06/19 14:55:29 bostic 3 2
c new template
e
s 00009/00001/00014
d D 4.2 85/05/30 22:59:56 sam 2 1
c add tags
e
s 00015/00000/00000
d D 4.1 82/12/25 10:50:36 sam 1 0
c date and time created 82/12/25 10:50:36 by sam
e
u
U
t
T
I 1
D 3
#	%W%	%G%
E 3
#
D 3
DESTDIR=
CFLAGS=-O
I 2
SRCS= pow.c gcd.c msqrt.c mdiv.c mout.c mult.c madd.c util.c
E 2
OBJS= pow.o gcd.o msqrt.o mdiv.o mout.o mult.o madd.o util.o
I 2
TAGSFILE=tags
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
SRCS=	pow.c gcd.c msqrt.c mdiv.c mout.c mult.c madd.c util.c
OBJS=	pow.o gcd.o msqrt.o mdiv.o mout.o mult.o madd.o util.o
E 3
E 2

D 3
libmp.a: $(OBJS)
	ar cr libmp.a $(OBJS)
E 3
I 3
all: libmp.a
E 3

D 3
install: libmp.a
	install libmp.a ${DESTDIR}/usr/lib/libmp.a
E 3
I 3
libmp.a: ${OBJS}
	ar cr $@ ${OBJS}

clean: FRC
	rm -f ${OBJS} core libmp.a

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -o bin -g bin -m 644 libmp.a ${DESTDIR}/usr/lib/libmp.a
E 3
	ranlib ${DESTDIR}/usr/lib/libmp.a

I 2
D 3
tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 3

E 2
D 3
clean:
D 2
	rm -f *.o libmp.a
E 2
I 2
	rm -f ${OBJS} libmp.a tags
E 3
I 3
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

pow.o: pow.c /usr/include/mp.h
gcd.o: gcd.c /usr/include/mp.h
msqrt.o: msqrt.c /usr/include/mp.h
mdiv.o: mdiv.c /usr/include/mp.h
mout.o: mout.c /usr/include/stdio.h /usr/include/mp.h
mult.o: mult.c /usr/include/mp.h
madd.o: madd.c /usr/include/mp.h
util.o: util.c /usr/include/stdio.h /usr/include/mp.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1
