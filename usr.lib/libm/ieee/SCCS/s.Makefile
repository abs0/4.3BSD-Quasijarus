h07975
s 00010/00005/00045
d D 5.3 88/06/30 17:23:40 bostic 10 9
c install approved copyright notice
e
s 00001/00001/00049
d D 5.2 87/12/14 23:06:51 bostic 9 8
c force remake of archive
e
s 00000/00000/00050
d D 5.1 87/11/30 18:42:11 bostic 8 7
c tahoe release
e
s 00013/00004/00037
d D 1.6 87/11/30 18:04:45 bostic 7 5
c new header; fix clean
e
s 00010/00004/00037
d R 1.6 87/11/30 18:02:38 bostic 6 5
c new header
e
s 00000/00000/00041
d D 1.5 87/07/13 19:49:15 zliu 5 4
c clean-ups.
e
s 00010/00077/00031
d D 1.4 87/07/13 13:26:49 zliu 4 3
c re-structuring.
e
s 00099/00008/00009
d D 1.3 87/07/07 01:06:05 zliu 3 2
c first shot at TAHOE.
e
s 00002/00002/00015
d D 1.2 85/09/12 20:21:34 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00017/00000/00000
d D 1.1 85/09/06 17:51:22 zliu 1 0
c date and time created 85/09/06 17:51:22 by zliu
e
u
U
t
T
I 1
D 2
# %W% (ELEFUNT) %G%
SCCSID = "%W% (ELEFUNT) %G%"
E 2
I 2
D 3
# %W% (ucb.elefunt) %G%
SCCSID = "%W% (ucb.elefunt) %G%"
E 2
MORE=atan2.o cbrt.o trig.o cabs.o support.o
E 3
I 3
#
# Copyright (c) 1987 Regents of the University of California.
D 7
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 7
I 7
# All rights reserved.
E 7
#
D 4
#	@(#)Makefile	4.12	(Berkeley)	7/6/87
E 4
I 4
D 7
#	%Z%%M%	%I%	(ucb.elefunt)	%G%
E 7
I 7
# Redistribution and use in source and binary forms are permitted
D 10
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 7
E 4
#
I 7
#	%W% (Berkeley) %G%
#
E 7
D 4
# This high quality math library is intended to run on either a VAX in
# D_floating format or a machine that conforms to the IEEE standard 754
# for double precision floating-point arithmetic.
#
# WARNING: On machines other than the ones mentioned above, run the original
# Version 7 math library, if nothing better is available.
#
# MACHINE indicates the type of floating point hardware you are using; legal
# values are:
#
# VAX		- for the VAX D_floating format, the default.
# NATIONAL	- for those IEEE machines whose floating point implementation
#		  has similar byte ordering as the NATIONAL 32016 with 32081.
# IEEE		- for other IEEE machines, we hope.
#
E 4
CFLAGS=	-O
LIBC=	/lib/libc.a
D 4
#
# Files comprising the standard Math library;
# actually there are more under ${MACH}/ subdirectory.
#
SRCS=	acosh.c asincos.c asinh.c atan.c atanh.c cosh.c erf.c \
	exp.c exp__E.c expm1.c floor.c lgamma.c j0.c j1.c jn.c \
	log.c log10.c log1p.c log__L.c pow.c sinh.c tanh.c
OBJS=	acosh.o asincos.o asinh.o atan.o atanh.o cosh.o erf.o \
	exp.o exp__E.o expm1.o floor.o lgamma.o j0.o j1.o jn.o \
	log.o log10.o log1p.o log__L.o pow.o sinh.o tanh.o 
E 4
I 4
SRCS=	cbrt.c support.c
OBJS=	cbrt.o support.o
E 4
E 3

.c.o:
I 3
D 4
####	generate additional code for profiling (-p)
E 4
E 3
	${CC} -p ${CFLAGS} -c $*.c
I 3
D 4
####	generate relocation bits (-r) & preserve symbols that begin with L (-X)
E 4
E 3
	-ld -X -r $*.o
D 3
	mv a.out ../profiled/$*.o
E 3
I 3
D 4
	mv a.out profiled/$*.o
E 4
I 4
	mv a.out ../profiled/$*.o
E 4
E 3
	${CC} ${CFLAGS} -c $*.c
I 3
D 4
####	generate relocation bits (-r) but don't preserve local symbols (-x)
E 4
E 3
	-ld -x -r $*.o
	mv a.out $*.o

D 3
all: ../libm.a ../libm_p.a
E 3
I 3
D 4
all: libm.a libm_p.a
E 4
I 4
all: ../libm.a ../libm_p.a
E 4
E 3

D 3
../libm.a ../libm_p.a: ${MORE}
	cd ../profiled; ar cru ../libm_p.a ${MORE}
	ar cru ../libm.a ${MORE}
E 3
I 3
D 4
libm.a libm_p.a: ${OBJS} more.${MACHINE}
	cd profiled; ar cru ../libm_p.a ${OBJS}
	ar cru libm.a ${OBJS}
E 4
I 4
D 9
../libm.a ../libm_p.a: ${OBJS}
E 9
I 9
../libm.a ../libm_p.a: ${OBJS} FRC
E 9
	cd ../profiled; ar cru ../libm_p.a ${OBJS}
	ar cru ../libm.a ${OBJS}
E 4

D 4
more.vax: FRC
	cd VAX; make "CFLAGS=${CFLAGS} -DVAX"

more.tahoe: FRC
	cd IEEE; make "CFLAGS=${CFLAGS} -DTAHOE"

clean: FRC
	rm -f ${OBJS} core libnm.a libnm_p.a IEEE/*.o VAX/*.o profiled/*.o

E 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

D 4
install: FRC
	-rm -f ${DESTDIR}/usr/lib/libnm.a ${DESTDIR}/usr/lib/libnm_p.a
	install -o bin -g bin -m 644 libm.a ${DESTDIR}/usr/lib/libm.a
#	ln ${DESTDIR}/usr/lib/libm.a ${DESTDIR}/usr/lib/libnm.a
	ranlib ${DESTDIR}/usr/lib/libm.a
	install -o bin -g bin -m 644 libm_p.a ${DESTDIR}/usr/lib/libm_p.a
#	ln ${DESTDIR}/usr/lib/libm_p.a ${DESTDIR}/usr/lib/libnm_p.a
	ranlib ${DESTDIR}/usr/lib/libm_p.a

lint: FRC
	lint ${CFLAGS} ${SRCS}

E 4
tags: FRC
	ctags ${SRCS}

I 7
clean:
	rm -f ${OBJS} a.out

E 7
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 4
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
E 4
I 4
cbrt.o: cbrt.c
D 7
support.o: support.c
E 7
I 7
support.o: support.c /usr/include/errno.h
E 7
E 4

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
