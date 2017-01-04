h39435
s 00002/00002/00106
d D 4.12 87/07/06 15:41:03 bostic 12 11
c don't link libnm to libm for awhile
e
s 00058/00032/00050
d D 4.11 87/06/19 13:10:05 bostic 11 10
c new template
e
s 00011/00012/00071
d D 4.10 86/11/03 10:25:41 mckusick 10 9
c update for VAX/TAHOE merge
e
s 00002/00002/00081
d D 4.9 85/09/11 17:56:44 mckusick 9 8
c new from Kahan
e
s 00002/00002/00081
d D 4.8 85/08/22 12:21:41 miriam 8 7
c Reflect the correct gamma.
e
s 00021/00017/00062
d D 4.7 85/08/21 10:41:43 miriam 7 6
c Revision by Prof. Kahan.
e
s 00001/00000/00078
d D 4.6 85/06/07 10:04:34 miriam 6 5
c Remove links before installation
e
s 00003/00003/00075
d D 4.5 85/06/05 16:52:54 miriam 5 4
c Correct files in SRCS to reflect only those files used.
e
s 00002/00000/00076
d D 4.4 85/06/04 22:11:38 miriam 4 3
c Put in ln for libnm to libm
e
s 00012/00001/00064
d D 4.3 85/05/30 22:58:33 sam 3 2
c add tags
e
s 00042/00008/00023
d D 4.2 85/05/24 10:36:47 miriam 2 1
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
I 2
#
E 2
I 1
D 11
#	%W%	%G%
E 11
I 11
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 11
#
D 7
SCCSID = "%Z%%M% %I% %G%"
E 7
I 7
D 11
SCCSID = "%W% %G%"
E 11
I 11
#	%W%	(Berkeley)	%G%
E 11
E 7
I 2
#
# This high quality math library is intended to run on either a VAX in
# D_floating format or a machine that conforms to the IEEE standard 754
# for double precision floating-point arithmetic.
#
# WARNING: On machines other than the ones mentioned above, run the original
# Version 7 math library, if nothing better is available.
E 2
D 11

E 11
D 2
CFLAGS=-O
E 2
I 2
#
D 10
# MACH indicates the type of floating point hardware you are using; legal
E 10
I 10
# MACHINE indicates the type of floating point hardware you are using; legal
E 10
# values are:
#
# VAX		- for the VAX D_floating format, the default.
# NATIONAL	- for those IEEE machines whose floating point implementation
#		  has similar byte ordering as the NATIONAL 32016 with 32081.
# IEEE		- for other IEEE machines, we hope.
#
D 7
MACH=VAX
E 7
I 7
D 10
MACH = VAX
E 10
E 7
E 2
D 11

D 2
INSTALL= install
E 2
I 2
D 10
#
# invoke object-code optimizer with appropriate MACH definition
#
CFLAGS=-O -D${MACH}
E 10
I 10
DESTDIR=
MACHINE=unknown
CFLAGS=-O
E 10
E 2

D 2
FILES= asin.o atan.o hypot.o jn.o j0.o j1.o pow.o gamma.o \
	log.o sin.o sqrt.o tan.o tanh.o sinh.o erf.o exp.o floor.o
E 2
I 2
INSTALL=install
E 2

E 11
I 11
CFLAGS=	-O
LIBC=	/lib/libc.a
E 11
I 2
D 10
DESTDIR=

E 10
#
D 7
# files comprising the standard Math library
E 7
I 7
# Files comprising the standard Math library;
# actually there are more under ${MACH}/ subdirectory.
E 7
#
I 3
D 5
SRCS=	E.c L.c acosh.c asin.c asinh.c atan.c atanh.c atrig.c cosh.c \
	erf.c exp.c exp__E.c floor.c gamma.c hypot.c j0.c j1.c jn.c \
	log.c log10.c log__L.c pow.c sin.c sinh.c sqrt.c tan.c tanh.c
E 5
I 5
D 7
SRCS=	E.c L.c acosh.c asinh.c atanh.c atrig.c cosh.c \
	erf.c exp.c exp__E.c floor.c gamma.c j0.c j1.c jn.c \
	log.c log10.c log__L.c pow.c sinh.c tanh.c
E 5
E 3
FILES=cosh.o sinh.o tanh.o acosh.o asinh.o atanh.o atrig.o \
E.o L.o exp.o log.o log10.o pow.o exp__E.o log__L.o \
jn.o j0.o j1.o gamma.o erf.o floor.o
MORE=\
${MACH}/atan2.o ${MACH}/cbrt.o ${MACH}/trig.o ${MACH}/cabs.o ${MACH}/support.o
E 7
I 7
D 11
SRCS =	acosh.c asincos.c asinh.c atan.c atanh.c cosh.c erf.c \
E 11
I 11
SRCS=	acosh.c asincos.c asinh.c atan.c atanh.c cosh.c erf.c \
E 11
D 8
	exp.c exp__E.c expm1.c floor.c lgama.c j0.c j1.c jn.c \
E 8
I 8
D 9
	exp.c exp__E.c expm1.c floor.c gamma.c j0.c j1.c jn.c \
E 9
I 9
	exp.c exp__E.c expm1.c floor.c lgamma.c j0.c j1.c jn.c \
E 9
E 8
	log.c log10.c log1p.c log__L.c pow.c sinh.c tanh.c
D 11

FILES =	acosh.o asincos.o asinh.o atan.o atanh.o cosh.o erf.o \
E 11
I 11
OBJS=	acosh.o asincos.o asinh.o atan.o atanh.o cosh.o erf.o \
E 11
D 8
	exp.o exp__E.o expm1.o floor.o lgama.o j0.o j1.o jn.o \
E 8
I 8
D 9
	exp.o exp__E.o expm1.o floor.o gamma.o j0.o j1.o jn.o \
E 9
I 9
	exp.o exp__E.o expm1.o floor.o lgamma.o j0.o j1.o jn.o \
E 9
E 8
	log.o log10.o log1p.o log__L.o pow.o sinh.o tanh.o 

E 7
I 3
D 11
TAGSFILE=tags
E 3

E 11
E 2
.c.o:
I 2
####	generate additional code for profiling (-p)
E 2
	${CC} -p ${CFLAGS} -c $*.c
I 2
####	generate relocation bits (-r) & preserve symbols that begin with L (-X)
E 2
	-ld -X -r $*.o
	mv a.out profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
I 2
####	generate relocation bits (-r) but don't preserve local symbols (-x)
E 2
	-ld -x -r $*.o
	mv a.out $*.o

D 2
libm.a libm_p.a : $(FILES)
	cd profiled; ar cru ../libm_p.a $(FILES)
	ar cru libm.a $(FILES)
E 2
I 2
D 7
libm.a libm_p.a : ${FILES}
	cd ${MACH}; make "MACH=${MACH}" "CFLAGS=${CFLAGS}"
	cd profiled; ar cru ../libm_p.a ${FILES} ${MORE}
	ar cru libm.a ${FILES} ${MORE}
E 7
I 7
all: libm.a libm_p.a
E 7
E 2

I 7
D 10
libm.a libm_p.a: ${FILES} more
E 10
I 10
D 11
libm.a libm_p.a: ${FILES} more.${MACHINE}
E 10
	cd profiled; ar cru ../libm_p.a ${FILES}
	ar cru libm.a ${FILES}
E 11
I 11
libm.a libm_p.a: ${OBJS} more.${MACHINE}
	cd profiled; ar cru ../libm_p.a ${OBJS}
	ar cru libm.a ${OBJS}
E 11

D 10
more:
	@cd ${MACH}; make "MACH=${MACH}" "CFLAGS=${CFLAGS}"
E 10
I 10
D 11
more.vax:
	@cd VAX; make "CFLAGS=${CFLAGS} -DVAX"
E 11
I 11
more.vax: FRC
	cd VAX; make "CFLAGS=${CFLAGS} -DVAX"
E 11
E 10

I 10
D 11
more.tahoe:
	@cd IEEE; make "CFLAGS=${CFLAGS} -DTAHOE"
E 11
I 11
more.tahoe: FRC
	cd IEEE; make "CFLAGS=${CFLAGS} -DTAHOE"
E 11

E 10
E 7
D 11
install: libm.a libm_p.a
E 11
I 11
clean: FRC
	rm -f ${OBJS} core libnm.a libnm_p.a IEEE/*.o VAX/*.o profiled/*.o

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
E 11
I 6
	-rm -f ${DESTDIR}/usr/lib/libnm.a ${DESTDIR}/usr/lib/libnm_p.a
E 6
D 11
	${INSTALL} libm.a ${DESTDIR}/usr/lib
E 11
I 11
	install -o bin -g bin -m 644 libm.a ${DESTDIR}/usr/lib/libm.a
E 11
I 4
D 12
	ln ${DESTDIR}/usr/lib/libm.a ${DESTDIR}/usr/lib/libnm.a
E 12
I 12
#	ln ${DESTDIR}/usr/lib/libm.a ${DESTDIR}/usr/lib/libnm.a
E 12
E 4
	ranlib ${DESTDIR}/usr/lib/libm.a
D 11
	${INSTALL} libm_p.a ${DESTDIR}/usr/lib
E 11
I 11
	install -o bin -g bin -m 644 libm_p.a ${DESTDIR}/usr/lib/libm_p.a
E 11
I 4
D 12
	ln ${DESTDIR}/usr/lib/libm_p.a ${DESTDIR}/usr/lib/libnm_p.a
E 12
I 12
#	ln ${DESTDIR}/usr/lib/libm_p.a ${DESTDIR}/usr/lib/libnm_p.a
E 12
E 4
	ranlib ${DESTDIR}/usr/lib/libm_p.a

I 3
D 11
tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done
E 11
I 11
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 11

E 3
D 11
clean:
D 2
	rm -f *.o profiled/*.o libm.a libm_p.a
E 2
I 2
D 3
	-rm -f *.o ${MACH}/*.o profiled/*.o profiled/${MACH}/*.o libm.a libm_p.a
E 3
I 3
D 7
	-rm -f *.o ${MACH}/*.o profiled/*.o profiled/${MACH}/*.o \
	    libm.a libm_p.a tags
E 7
I 7
D 10
	-rm -f *.o ${MACH}/*.o profiled/*.o libm.a libm_p.a tags
E 10
I 10
	-rm -f *.o IEEE/*.o VAX/*.o profiled/*.o libm.a libm_p.a tags
E 11
I 11
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

acosh.o: acosh.c
asincos.o: asincos.c
asinh.o: asinh.c
atan.o: atan.c
atanh.o: atanh.c
cosh.o: cosh.c
erf.o: erf.c
exp.o: exp.c
exp__E.o: exp__E.c
expm1.o: expm1.c
floor.o: floor.c
lgamma.o: lgamma.c /usr/include/math.h
j0.o: j0.c /usr/include/math.h
j1.o: j1.c /usr/include/math.h
jn.o: jn.c /usr/include/math.h
log.o: log.c
log10.o: log10.c
log1p.o: log1p.c
log__L.o: log__L.c
pow.o: pow.c
sinh.o: sinh.c
tanh.o: tanh.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 11
E 10
E 7
E 3
E 2
E 1
