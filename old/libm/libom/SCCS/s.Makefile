h23768
s 00001/00001/00072
d D 4.5 87/12/12 19:57:08 bostic 8 7
c clean profiled
e
s 00003/00000/00070
d D 4.4 87/07/27 17:12:56 bostic 7 5
c don't link libnm to libm for awhile
e
s 00002/00000/00070
d R 4.4 87/07/06 15:40:42 bostic 6 5
c link libnm to libom for awhile
e
s 00052/00026/00018
d D 4.3 87/06/19 11:28:08 bostic 5 4
c new template
e
s 00022/00009/00022
d D 4.2 85/06/05 18:07:37 miriam 4 1
c Backtrack to old makefile and add tags
e
s 00012/00001/00064
d R 4.3 85/05/30 22:58:33 sam 3 2
c add tags
e
s 00042/00008/00023
d R 4.2 85/05/24 10:36:47 miriam 2 1
c From Prof. Kahan
e
s 00031/00000/00000
d D 4.1 82/12/25 10:46:36 sam 1 0
c date and time created 82/12/25 10:46:36 by sam
e
u
U
t
T
I 1
D 5
#	%W%	%G%
E 5
#
D 5
SCCSID = "%Z%%M% %I% %G%"

CFLAGS=-O

I 4
DESTDIR=

E 4
INSTALL= install

E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
E 5
I 4
SRCS=	asin.c atan.c hypot.c jn.c j0.c j1.c pow.c gamma.c \
	log.c sin.c sqrt.c tan.c tanh.c sinh.c erf.c exp.c floor.c
D 5

E 4
FILES= asin.o atan.o hypot.o jn.o j0.o j1.o pow.o gamma.o \
E 5
I 5
OBJS=	asin.o atan.o hypot.o jn.o j0.o j1.o pow.o gamma.o \
E 5
	log.o sin.o sqrt.o tan.o tanh.o sinh.o erf.o exp.o floor.o

I 4
D 5
TAGSFILE=tags

E 5
E 4
.c.o:
	${CC} -p ${CFLAGS} -c $*.c
	-ld -X -r $*.o
	mv a.out profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
	-ld -x -r $*.o
	mv a.out $*.o

D 4
libm.a libm_p.a : $(FILES)
	cd profiled; ar cru ../libm_p.a $(FILES)
	ar cru libm.a $(FILES)
E 4
I 4
D 5
libom.a libom_p.a : $(FILES)
	cd profiled; ar cru ../libom_p.a $(FILES)
	ar cru libom.a $(FILES)
E 5
I 5
all: libom.a libom_p.a
E 5
E 4

D 4
install: libm.a libm_p.a
	${INSTALL} libm.a ${DESTDIR}/usr/lib
	ranlib ${DESTDIR}/usr/lib/libm.a
	${INSTALL} libm_p.a ${DESTDIR}/usr/lib
	ranlib ${DESTDIR}/usr/lib/libm_p.a
E 4
I 4
D 5
install: libom.a libom_p.a
	${INSTALL} libom.a ${DESTDIR}/usr/lib
E 5
I 5
libom.a libom_p.a: ${OBJS}
	cd profiled; ar cru ../libom_p.a ${OBJS}
	ar cru libom.a ${OBJS}

clean: FRC
D 8
	rm -f ${OBJS} core libom.a libom_p.a
E 8
I 8
	rm -f ${OBJS} core libom.a libom_p.a profiled/*
E 8

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
I 7
	rm -f ${DESTDIR}/usr/lib/libnm.a ${DESTDIR}/usr/lib/libnm_p.a
E 7
	install -o bin -g bin -m 644 libom.a ${DESTDIR}/usr/lib/libom.a
I 7
	ln ${DESTDIR}/usr/lib/libom.a ${DESTDIR}/usr/lib/libnm.a
E 7
E 5
	ranlib ${DESTDIR}/usr/lib/libom.a
D 5
	${INSTALL} libom_p.a ${DESTDIR}/usr/lib
E 5
I 5
	install -o bin -g bin -m 644 libom_p.a ${DESTDIR}/usr/lib/libom_p.a
I 7
	ln ${DESTDIR}/usr/lib/libom_p.a ${DESTDIR}/usr/lib/libnm_p.a
E 7
E 5
	ranlib ${DESTDIR}/usr/lib/libom_p.a
E 4

I 4
D 5
tags:
	cwd=`pwd`; \
 	for i in ${SRCS}; do \
 		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
 	done
E 5
I 5
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 5

E 4
D 5
clean:
D 4
	rm -f *.o profiled/*.o libm.a libm_p.a
E 4
I 4
	rm -f *.o profiled/*.o libom.a libom_p.a tags
E 5
I 5
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

asin.o: asin.c /usr/include/errno.h
atan.o: atan.c
hypot.o: hypot.c
jn.o: jn.c /usr/include/math.h /usr/include/errno.h
j0.o: j0.c /usr/include/math.h /usr/include/errno.h
j1.o: j1.c /usr/include/math.h /usr/include/errno.h
pow.o: pow.c /usr/include/errno.h
gamma.o: gamma.c /usr/include/errno.h /usr/include/math.h
log.o: log.c /usr/include/errno.h /usr/include/math.h
sin.o: sin.c
sqrt.o: sqrt.c /usr/include/errno.h
tan.o: tan.c /usr/include/errno.h /usr/include/math.h
tanh.o: tanh.c
sinh.o: sinh.c
erf.o: erf.c
exp.o: exp.c /usr/include/errno.h /usr/include/math.h
floor.o: floor.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 4
E 1
