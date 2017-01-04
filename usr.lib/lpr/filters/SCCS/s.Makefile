h44015
s 00010/00005/00043
d D 5.5 88/06/30 17:54:09 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00039
d D 5.4 88/03/08 08:21:27 bostic 8 7
c add Berkeley specific header
e
s 00010/00080/00032
d D 5.3 87/11/16 13:07:07 bostic 7 5
c move varian/versatec and tools to vfilters
e
s 00010/00080/00032
d R 5.3 87/11/04 18:59:58 bostic 6 5
c move varian/versatec and tools to src/old/vpr
e
s 00071/00067/00041
d D 5.2 87/07/27 17:12:17 bostic 5 4
c new template
e
s 00007/00001/00101
d D 5.1 85/05/15 11:16:43 dist 4 3
c Add copyright notice
e
s 00000/00001/00102
d D 4.3 83/11/16 13:35:53 ralph 3 2
c no longer need to link vpsfW
e
s 00029/00028/00074
d D 4.2 83/07/17 00:23:21 sam 2 1
c chrtab no longer in library
e
s 00102/00000/00000
d D 4.1 83/05/11 15:54:26 ralph 1 0
c date and time created 83/05/11 15:54:26 by ralph
e
u
U
t
T
I 1
D 2
#	%W%	(Berkeley)	%G%
E 2
I 2
D 4
#	%M%	%I%	%E%
E 4
I 4
#
D 5
# Copyright (c) 1983 Regents of the University of California.
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
E 5
D 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 8
I 8
# All rights reserved.
E 8
#
D 5
#	%W% (Berkeley) %G%
E 5
I 5
D 8
#	%W%	(Berkeley)	%G%
E 8
I 8
# Redistribution and use in source and binary forms are permitted
D 9
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
#
#	%W% (Berkeley) %G%
E 8
E 5
#
E 4
E 2
D 5
#
# makefile for line printer filters and associated programs
#

D 2
CFLAGS=-O
LIBDIR=/usr/lib
CXREF=/usr/ucb/ctags -x
E 2
DESTDIR=
E 5
D 2

E 2
I 2
CFLAGS=	-O
I 5
LIBC=	/lib/libc.a
E 5
LIBDIR=	/usr/lib
D 5
CXREF=	/usr/ucb/ctags -x
E 2
SRCS=	lpf.c necf.c \
D 2
	rvsort.c rvcat.c vsort.c vcat.c vpf.c vpsf.c vdmp.c vpltdmp.c \
E 2
I 2
	chrtab.c rvsort.c rvcat.c vsort.c vcat.c vpf.c vpsf.c vdmp.c vpltdmp.c \
E 2
	vplotf.c vfontinfo.c vwidth.c vfw.c fcvt.c rotate.c rotprt.c
D 2
PRINTER=	lpf necf
E 2
I 2
PRINTER=lpf necf
E 5
I 5
D 7
SRCS=	lpf.c necf.c chrtab.c rvsort.c rvcat.c vsort.c vcat.c vpf.c vpsf.c \
	vdmp.c vpltdmp.c vplotf.c vfontinfo.c vwidth.c vfw.c fcvt.c rotate.c \
	rotprt.c
OBJS=	lpf.o necf.o chrtab.o rvsort.o rvcat.o vsort.o vcat.o vpf.o vpsf.o \
	vdmp.o vpltdmp.o vplotf.o vfontinfo.o vwidth.o vfw.o fcvt.o rotate.o \
	rotprt.o
PRINT=	lpf necf
E 5
E 2
VARIAN=	rvsort rvcat vsort vcat vpf vpsf vdmp vpltdmp vplotf vfontinfo vwidth \
	vfw fcvt rotate rotprt
I 5
ALL=	${PRINT} ${VARIAN}
E 7
I 7
SRCS=	lpf.c
OBJS=	lpf.o
E 7
E 5

I 2
D 5
all:	printer varian
E 5
I 5
D 7
all: ${ALL}
E 7
I 7
all: lpf
E 7
E 5

E 2
D 5
printer: ${PRINTER}
E 5
I 5
lpf: lpf.c
	${CC} -o $@ ${CFLAGS} lpf.c
E 5

D 5
varian:	${VARIAN}
E 5
I 5
D 7
necf: necf.c
	${CC} -o $@ ${CFLAGS} necf.c
E 5

D 5
lpf:	lpf.c
	${CC} -o lpf ${CFLAGS} lpf.c
E 5
I 5
rvsort: rvsort.c
	${CC} -o $@ ${CFLAGS} rvsort.c
E 5

D 5
necf:	necf.c
	${CC} -o necf ${CFLAGS} necf.c
E 5
I 5
rvcat: rvcat.c
	${CC} -o $@ ${CFLAGS} rvcat.c
E 5

D 5
rvsort:	rvsort.c
	${CC} -o rvsort ${CFLAGS} rvsort.c
E 5
I 5
vsort: vsort.c
	${CC} -o $@ ${CFLAGS} vsort.c
E 5

D 5
rvcat:	rvcat.c
	${CC} -o rvcat ${CFLAGS} rvcat.c
E 5
I 5
vcat: vcat.c
	${CC} -o $@ ${CFLAGS} vcat.c
E 5

D 5
vsort:	vsort.c
	${CC} -o vsort ${CFLAGS} vsort.c
E 5
I 5
vpf: vpf.c
	${CC} -o $@ ${CFLAGS} vpf.c
E 5

D 5
vcat:	vcat.c
	${CC} -o vcat ${CFLAGS} vcat.c
E 5
I 5
vpsf: vpsf.c
	${CC} -o $@ ${CFLAGS} vpsf.c
E 5

D 5
vpf:	vpf.c
	${CC} -o vpf ${CFLAGS} vpf.c

vpsf:	vpsf.c
	${CC} -o vpsf ${CFLAGS} vpsf.c

E 5
vdmp: vdmp.c
D 5
	${CC} -o vdmp ${CFLAGS} vdmp.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} vdmp.c
E 5

vpltdmp: vpltdmp.c
D 5
	${CC} -o vpltdmp ${CFLAGS} vpltdmp.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} vpltdmp.c
E 5

D 2
vplotf: vplotf.c
	${CC} -o vplotf ${CFLAGS} vplotf.c
E 2
I 2
vplotf: vplotf.c chrtab.o
D 5
	${CC} -o vplotf ${CFLAGS} vplotf.c chrtab.o
E 5
I 5
	${CC} -o $@ ${CFLAGS} vplotf.c chrtab.o
E 5
E 2

vfontinfo: vfontinfo.c
D 5
	${CC} -o vfontinfo ${CFLAGS} vfontinfo.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} vfontinfo.c
E 5

vwidth: vwidth.c
D 5
	${CC} -o vwidth ${CFLAGS} vwidth.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} vwidth.c
E 5

vfw: vfw.c
D 5
	${CC} -o vfw ${CFLAGS} vfw.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} vfw.c
E 5

fcvt: fcvt.c
D 5
	${CC} -o fcvt ${CFLAGS} fcvt.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} fcvt.c
E 5

rotate: rotate.c
D 5
	${CC} -o rotate ${CFLAGS} rotate.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} rotate.c
E 5

rotprt: rotprt.c
D 5
	${CC} -o rotprt ${CFLAGS} rotprt.c
E 5
I 5
	${CC} -o $@ ${CFLAGS} rotprt.c
E 5

E 7
D 5
install: printer
D 2
	install -s lpf ${DESTDIR}${LIBDIR}/lpf
	install -s necf ${DESTDIR}${LIBDIR}/necf
E 2
I 2
	install -s lpf ${DESTDIR}/${LIBDIR}/lpf
	install -s necf ${DESTDIR}/${LIBDIR}/necf
E 5
I 5
clean: FRC
D 7
	rm -f ${OBJS} core ${ALL}
E 7
I 7
	rm -f ${OBJS} core lpf
E 7
E 5
E 2

D 5
installv: varian
D 2
	install -s vfontinfo ${DESTDIR}${LIBDIR}/vfontinfo
	install -s vwidth ${DESTDIR}${LIBDIR}/vwidth
	install -s vfw ${DESTDIR}${LIBDIR}/vfw
	install -s fcvt ${DESTDIR}${LIBDIR}/fcvt
	install -s rotate ${DESTDIR}${LIBDIR}/rotate
	install -s rotprt ${DESTDIR}${LIBDIR}/rotprt
	install -s rvsort ${DESTDIR}${LIBDIR}/rvsort
	install -s rvcat ${DESTDIR}${LIBDIR}/rvcat
	install -s vsort ${DESTDIR}${LIBDIR}/vsort
	install -s vcat ${DESTDIR}${LIBDIR}/vcat
	install -s vpf ${DESTDIR}${LIBDIR}/vpf
	ln ${DESTDIR}${LIBDIR}/vpf ${DESTDIR}${LIBDIR}/vpfW
	install -s vpsf ${DESTDIR}${LIBDIR}/vpsf
	ln ${DESTDIR}${LIBDIR}/vpsf ${DESTDIR}${LIBDIR}/vpsfW
	install -s vdmp ${DESTDIR}${LIBDIR}/vdmp
	install -s vpltdmp ${DESTDIR}${LIBDIR}/vpltdmp
	install -s vplotf ${DESTDIR}${LIBDIR}/vplotf
E 2
I 2
	install -s vfontinfo ${DESTDIR}/${LIBDIR}/vfontinfo
	install -s vwidth ${DESTDIR}/${LIBDIR}/vwidth
	install -s vfw ${DESTDIR}/${LIBDIR}/vfw
	install -s fcvt ${DESTDIR}/${LIBDIR}/fcvt
	install -s rotate ${DESTDIR}/${LIBDIR}/rotate
	install -s rotprt ${DESTDIR}/${LIBDIR}/rotprt
	install -s rvsort ${DESTDIR}/${LIBDIR}/rvsort
	install -s rvcat ${DESTDIR}/${LIBDIR}/rvcat
	install -s vsort ${DESTDIR}/${LIBDIR}/vsort
	install -s vcat ${DESTDIR}/${LIBDIR}/vcat
	install -s vpf ${DESTDIR}/${LIBDIR}/vpf
E 5
I 5
depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 lpf ${DESTDIR}/${LIBDIR}/lpf
D 7
	install -s -o bin -g bin -m 755 necf ${DESTDIR}/${LIBDIR}/necf
E 7

D 7
installv:
	install -s -o bin -g bin -m 755 vfontinfo ${DESTDIR}/${LIBDIR}/vfontinfo
	install -s -o bin -g bin -m 755 vwidth ${DESTDIR}/${LIBDIR}/vwidth
	install -s -o bin -g bin -m 755 vfw ${DESTDIR}/${LIBDIR}/vfw
	install -s -o bin -g bin -m 755 fcvt ${DESTDIR}/${LIBDIR}/fcvt
	install -s -o bin -g bin -m 755 rotate ${DESTDIR}/${LIBDIR}/rotate
	install -s -o bin -g bin -m 755 rotprt ${DESTDIR}/${LIBDIR}/rotprt
	install -s -o bin -g bin -m 755 rvsort ${DESTDIR}/${LIBDIR}/rvsort
	install -s -o bin -g bin -m 755 rvcat ${DESTDIR}/${LIBDIR}/rvcat
	install -s -o bin -g bin -m 755 vsort ${DESTDIR}/${LIBDIR}/vsort
	install -s -o bin -g bin -m 755 vcat ${DESTDIR}/${LIBDIR}/vcat
	install -s -o bin -g bin -m 755 vpf ${DESTDIR}/${LIBDIR}/vpf
E 5
	ln ${DESTDIR}/${LIBDIR}/vpf ${DESTDIR}/${LIBDIR}/vpfW
D 5
	install -s vpsf ${DESTDIR}/${LIBDIR}/vpsf
D 3
	ln ${DESTDIR}/${LIBDIR}/vpsf ${DESTDIR}/${LIBDIR}/vpsfW
E 3
	install -s vdmp ${DESTDIR}/${LIBDIR}/vdmp
	install -s vpltdmp ${DESTDIR}/${LIBDIR}/vpltdmp
	install -s vplotf ${DESTDIR}/${LIBDIR}/vplotf
E 5
I 5
	install -s -o bin -g bin -m 755 vpsf ${DESTDIR}/${LIBDIR}/vpsf
	install -s -o bin -g bin -m 755 vdmp ${DESTDIR}/${LIBDIR}/vdmp
	install -s -o bin -g bin -m 755 vpltdmp ${DESTDIR}/${LIBDIR}/vpltdmp
	install -s -o bin -g bin -m 755 vplotf ${DESTDIR}/${LIBDIR}/vplotf
E 5
E 2

E 7
D 5
clean:
	rm -f ${PRINTER} ${VARIAN} *.o
E 5
I 5
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 5

D 5
print:
	@pr makefile
	@${CXREF} *.c | pr -h XREF
	@pr *.h *.c
E 5
I 5
tags: FRC
	ctags ${SRCS}

FRC:

D 7
# DO NOT DELETE THIS LINE -- make depend uses it
E 7
I 7
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 7

I 7
lpf: lpf.c /usr/include/stdio.h /usr/include/signal.h
lpf: /usr/include/machine/trap.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 5
E 1
