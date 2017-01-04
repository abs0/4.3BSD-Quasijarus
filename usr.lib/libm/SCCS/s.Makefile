h40162
s 00010/00005/00117
d D 1.9 88/06/30 17:45:01 bostic 11 10
c install approved copyright notice
e
s 00001/00001/00121
d D 1.8 87/12/07 14:07:42 bostic 10 8
c tahoe release
e
s 00000/00000/00122
d R 5.1 87/11/30 18:33:45 bostic 9 8
c tahoe release
e
s 00025/00021/00097
d D 1.7 87/11/30 18:32:53 bostic 8 7
c new headers; handle subdirs
e
s 00016/00016/00102
d D 1.6 87/07/13 19:23:22 zliu 7 6
c clean-ups.
e
s 00005/00001/00113
d D 1.5 87/07/13 15:30:00 zliu 6 4
c adding NATIONAL support.
e
s 00004/00000/00114
d R 1.5 87/07/13 15:25:11 zliu 5 4
c adding NATIONAL support.
e
s 00014/00008/00100
d D 1.4 87/07/13 13:31:46 zliu 4 3
c re-structuring
e
s 00062/00037/00046
d D 1.3 87/07/07 01:32:14 zliu 3 2
c first shot at TAHOE.
e
s 00004/00004/00079
d D 1.2 85/09/11 23:53:14 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00083/00000/00000
d D 1.1 85/09/06 17:52:35 zliu 1 0
c date and time created 85/09/06 17:52:35 by zliu
e
u
U
f b 
t
T
I 1
#
D 2
#	%W% (ELEFUNT) %G%
E 2
I 2
D 3
#	%Z%%M%	4.9	9/11/85; %I% (ucb.elefunt) %G%
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
D 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 8
I 8
# All rights reserved.
E 8
E 3
E 2
#
D 2
SCCSID = "%W% (ELEFUNT) %G%"
E 2
I 2
D 3
SCCSID = "%Z%%M%	4.9 9/11/85; %I% (ucb.elefunt) %G%"
E 3
I 3
D 4
#	@(#)Makefile	4.12	(Berkeley)	7/6/87
E 4
I 4
D 8
#	%Z%%M%	%I%	(ucb.elefunt)	%G%
E 8
I 8
# Redistribution and use in source and binary forms are permitted
D 11
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 11
I 11
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 11
E 8
E 4
E 3
E 2
#
I 8
#	%W% (Berkeley) %G%
#
E 8
# This high quality math library is intended to run on either a VAX in
# D_floating format or a machine that conforms to the IEEE standard 754
# for double precision floating-point arithmetic.
#
# WARNING: On machines other than the ones mentioned above, run the original
# Version 7 math library, if nothing better is available.
D 3

E 3
#
D 3
# MACH indicates the type of floating point hardware you are using; legal
E 3
I 3
# MACHINE indicates the type of floating point hardware you are using; legal
E 3
# values are:
#
D 7
# VAX		- for the VAX D_floating format, the default.
I 4
# TAHOE		- for the TAHOE double format.
E 4
# NATIONAL	- for those IEEE machines whose floating point implementation
E 7
I 7
# vax		- for the VAX D_floating format, the default.
# tahoe		- for the TAHOE double format.
# national	- for those IEEE machines whose floating point implementation
E 7
#		  has similar byte ordering as the NATIONAL 32016 with 32081.
D 7
# IEEE		- for other IEEE machines, we hope.
E 7
I 7
# ieee		- for other IEEE machines, we hope.
E 7
#
D 3
MACH = VAX

E 3
I 3
D 4
CFLAGS=	-O
E 4
I 4
CFLAGS=	-O -D${MACHINE}
E 4
LIBC=	/lib/libc.a
I 8
SUBDIR=	vax tahoe national common ieee
E 8
E 3
#
D 3
# invoke object-code optimizer with appropriate MACH definition
#
CFLAGS=-O -D${MACH}

INSTALL=install

DESTDIR=

#
E 3
# Files comprising the standard Math library;
D 4
# actually there are more under ${MACH}/ subdirectory.
E 4
I 4
# actually there are more under ${MACHINE}/ subdirectory.
E 4
#
D 3
SRCS =	acosh.c asincos.c asinh.c atan.c atanh.c cosh.c erf.c \
E 3
I 3
SRCS=	acosh.c asincos.c asinh.c atan.c atanh.c cosh.c erf.c \
E 3
D 2
	exp.c exp__E.c expm1.c floor.c lgama.c j0.c j1.c jn.c \
E 2
I 2
	exp.c exp__E.c expm1.c floor.c lgamma.c j0.c j1.c jn.c \
E 2
	log.c log10.c log1p.c log__L.c pow.c sinh.c tanh.c
D 3

FILES =	acosh.o asincos.o asinh.o atan.o atanh.o cosh.o erf.o \
E 3
I 3
OBJS=	acosh.o asincos.o asinh.o atan.o atanh.o cosh.o erf.o \
E 3
D 2
	exp.o exp__E.o expm1.o floor.o lgama.o j0.o j1.o jn.o \
E 2
I 2
	exp.o exp__E.o expm1.o floor.o lgamma.o j0.o j1.o jn.o \
E 2
	log.o log10.o log1p.o log__L.o pow.o sinh.o tanh.o 

D 3
TAGSFILE=tags

E 3
.c.o:
####	generate additional code for profiling (-p)
	${CC} -p ${CFLAGS} -c $*.c
####	generate relocation bits (-r) & preserve symbols that begin with L (-X)
	-ld -X -r $*.o
	mv a.out profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
####	generate relocation bits (-r) but don't preserve local symbols (-x)
	-ld -x -r $*.o
	mv a.out $*.o

all: libm.a libm_p.a

D 3
libm.a libm_p.a: ${FILES} more
	cd profiled; ar cru ../libm_p.a ${FILES}
	ar cru libm.a ${FILES}
E 3
I 3
libm.a libm_p.a: ${OBJS} more.${MACHINE}
	cd profiled; ar cru ../libm_p.a ${OBJS}
	ar cru libm.a ${OBJS}
E 3

D 3
more:
	@cd ${MACH}; make "MACH=${MACH}" "CFLAGS=${CFLAGS}"
E 3
I 3
D 4
more.vax: FRC
	cd VAX; make "CFLAGS=${CFLAGS} -DVAX"
E 4
I 4
D 7
more.IEEE: FRC
	cd COMMON; make "CFLAGS=${CFLAGS}"
	cd IEEE; make "CFLAGS=${CFLAGS}"
E 7
I 7
more.ieee: FRC
D 8
	cd common; make "CFLAGS=${CFLAGS}"
	cd ieee; make "CFLAGS=${CFLAGS}"
E 8
I 8
	for i in common ieee; do (cd $$i; make ${MFLAGS}); done
E 8
E 7
E 4
E 3

I 6
D 7
more.NATIONAL: FRC
	cd COMMON; make "CFLAGS=${CFLAGS}"
	cd NATIONAL; make "CFLAGS=${CFLAGS}"
E 7
I 7
more.national: FRC
D 8
	cd common; make "CFLAGS=${CFLAGS}"
	cd national; make "CFLAGS=${CFLAGS}"
E 8
I 8
	for i in common national; do (cd $$i; make ${MFLAGS}); done
E 8
E 7

E 6
D 3
install: libm.a libm_p.a
E 3
I 3
D 4
more.tahoe: FRC
	cd IEEE; make "CFLAGS=${CFLAGS} -DTAHOE"
E 4
I 4
D 7
more.TAHOE: FRC
	cd COMMON; make "CFLAGS=${CFLAGS}"
	cd TAHOE; make "CFLAGS=${CFLAGS}"
E 7
I 7
more.tahoe: FRC
D 8
	cd common; make "CFLAGS=${CFLAGS}"
	cd tahoe; make "CFLAGS=${CFLAGS}"
E 8
I 8
	for i in common tahoe; do (cd $$i; make ${MFLAGS}); done
E 8
E 7
E 4

I 4
D 7
more.VAX: FRC
	cd VAX; make "CFLAGS=${CFLAGS}"
E 7
I 7
more.vax: FRC
	cd vax; make "CFLAGS=${CFLAGS}"
E 7

E 4
clean: FRC
D 4
	rm -f ${OBJS} core libnm.a libnm_p.a IEEE/*.o VAX/*.o profiled/*.o
E 4
I 4
D 6
	rm -f ${OBJS} core libm.a libm_p.a COMMON/*.o IEEE/*.o TAHOE/*.o VAX/*.o profiled/*.o
E 6
I 6
D 7
	rm -f ${OBJS} core libm.a libm_p.a COMMON/*.o IEEE/*.o NATIONAL/*.o TAHOE/*.o VAX/*.o profiled/*.o
E 7
I 7
D 8
	rm -f ${OBJS} core libm.a libm_p.a common/*.o ieee/*.o national/*.o tahoe/*.o vax/*.o profiled/*.o
E 8
I 8
D 10
	rm -f ${OBJS} core libm.a libm_p.a
E 10
I 10
	rm -f ${OBJS} profiled/*.o core libm.a libm_p.a
E 10
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 8
E 7
E 6
E 4

depend: FRC
	mkdep ${CFLAGS} ${SRCS}
I 8
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 8

install: FRC
E 3
D 8
	-rm -f ${DESTDIR}/usr/lib/libnm.a ${DESTDIR}/usr/lib/libnm_p.a
E 8
D 3
	${INSTALL} libm.a ${DESTDIR}/usr/lib
	ln ${DESTDIR}/usr/lib/libm.a ${DESTDIR}/usr/lib/libnm.a
E 3
I 3
	install -o bin -g bin -m 644 libm.a ${DESTDIR}/usr/lib/libm.a
D 8
#	ln ${DESTDIR}/usr/lib/libm.a ${DESTDIR}/usr/lib/libnm.a
E 8
E 3
	ranlib ${DESTDIR}/usr/lib/libm.a
D 3
	${INSTALL} libm_p.a ${DESTDIR}/usr/lib
	ln ${DESTDIR}/usr/lib/libm_p.a ${DESTDIR}/usr/lib/libnm_p.a
E 3
I 3
	install -o bin -g bin -m 644 libm_p.a ${DESTDIR}/usr/lib/libm_p.a
D 8
#	ln ${DESTDIR}/usr/lib/libm_p.a ${DESTDIR}/usr/lib/libnm_p.a
E 8
E 3
	ranlib ${DESTDIR}/usr/lib/libm_p.a

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

D 3
clean:
	-rm -f *.o ${MACH}/*.o profiled/*.o libm.a libm_p.a tags
E 3
I 3
tags: FRC
	ctags ${SRCS}
I 8
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} tags); done
E 8

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

acosh.o: acosh.c
asincos.o: asincos.c
asinh.o: asinh.c
atan.o: atan.c
D 8
atanh.o: atanh.c
E 8
I 8
atanh.o: atanh.c /usr/include/errno.h
E 8
cosh.o: cosh.c
erf.o: erf.c
exp.o: exp.c
exp__E.o: exp__E.c
expm1.o: expm1.c
floor.o: floor.c
D 8
lgamma.o: lgamma.c /usr/include/math.h
j0.o: j0.c /usr/include/math.h
j1.o: j1.c /usr/include/math.h
jn.o: jn.c /usr/include/math.h
log.o: log.c
E 8
I 8
lgamma.o: lgamma.c /usr/include/math.h /usr/include/errno.h
j0.o: j0.c /usr/include/math.h /usr/include/errno.h
j1.o: j1.c /usr/include/math.h /usr/include/errno.h
jn.o: jn.c /usr/include/math.h /usr/include/errno.h
log.o: log.c /usr/include/errno.h
E 8
log10.o: log10.c
D 8
log1p.o: log1p.c
E 8
I 8
log1p.o: log1p.c /usr/include/errno.h
E 8
log__L.o: log__L.c
D 8
pow.o: pow.c
E 8
I 8
pow.o: pow.c /usr/include/errno.h
E 8
sinh.o: sinh.c
tanh.o: tanh.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
