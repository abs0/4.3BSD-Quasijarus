h55366
s 00030/00012/00059
d D 4.12 87/06/19 16:58:17 bostic 14 12
c new template
e
s 00067/00060/00011
d R 4.12 87/06/19 16:33:53 bostic 13 12
c new template
e
s 00005/00002/00066
d D 4.11 86/08/29 14:33:01 sklower 12 11
c add gremlin output library
e
s 00002/00002/00066
d D 4.10 85/09/21 15:18:45 sam 11 10
c move imagen archive name
e
s 00006/00002/00062
d D 4.9 85/09/21 15:11:07 sam 10 9
c add imagen
e
s 00008/00002/00056
d D 4.8 85/05/30 23:21:51 sam 9 8
c ci for ralph; add 4013 library
e
s 00022/00002/00036
d D 4.7 83/11/11 15:19:14 ralph 8 6
c added new devices.
e
s 00015/00002/00036
d R 4.7 83/11/10 15:02:14 ralph 7 6
c added bitgraph, dumbplot, hp2648, hp7221
e
s 00005/00005/00033
d D 4.6 83/09/21 19:03:17 sam 6 5
c wrong library names being installed
e
s 00002/00001/00036
d D 4.5 83/07/09 23:48:09 sam 5 4
c get make clean right some day
e
s 00009/00009/00028
d D 4.4 83/07/09 23:45:40 sam 4 3
c name changes
e
s 00003/00000/00034
d D 4.3 83/07/09 23:41:54 sam 3 2
c clean wrong
e
s 00003/00001/00031
d D 4.2 83/07/03 22:15:24 sam 2 1
c fix install
e
s 00032/00000/00000
d D 4.1 83/06/27 14:53:27 sam 1 0
c date and time created 83/06/27 14:53:27 by sam
e
u
U
t
T
I 1
D 14
#	%M%	%I%	%E%
E 14
#
I 14
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
E 14
D 2
all: libplot.a libt4014.a libt300.a libt300s.a libt450.a libvt0.a
E 2
I 2
D 4
ALL=	libplot.a libt4014.a libt300.a libt300s.a libt450.a libvt0.a
E 4
I 4
D 6
ALL=	libplot libt4014 libt300 libt300s libt450 libvt0
E 6
I 6
D 8
ALL=	libplot lib4014 lib300 lib300s lib450 libvt0
E 6
I 5
SUBDIRS=plot t4014 t300 t300s t450 vt0
E 8
I 8
D 9
ALL=	libplot lib300 lib300s lib4014 lib450 libvt0 \
E 9
I 9
ALL=	libf77plot libplot lib300 lib300s lib4013 lib4014 lib450 libvt0 \
E 9
D 10
	libplotaed libplotbg libplotdumb libplotgigi libplot2648 libplot7221
E 10
I 10
D 14
	libplotaed libplotbg libplotdumb libplotgigi libplot2648 \
D 11
	libplot7221 libimagen
E 11
I 11
D 12
	libplot7221 libplotimagen
E 12
I 12
	libplot7221 libplotimagen libplotgrn
E 12
E 11
E 10
D 9
SUBDIRS=plot t4014 t300 t300s t450 vt0 \
E 9
I 9
SUBDIRS=tf77 plot t4013 t4014 t300 t300s t450 vt0 \
E 9
D 10
	aed bitgraph dumb gigi hp2648 hp7221
E 10
I 10
D 12
	aed bitgraph dumb gigi hp2648 hp7221 imagen
E 12
I 12
	aed bitgraph dumb gigi hp2648 hp7221 imagen grn
E 14
I 14
	libplotaed libplotbg libplotdumb libplotgigi libplot2648 libplot7221 \
	libplotimagen libplotgrn
SUBDIRS=tf77 plot t4013 t4014 t300 t300s t450 vt0 aed bitgraph dumb gigi \
	hp2648 hp7221 imagen grn
E 14
E 12
E 10
E 8
E 5
E 4

D 14
all:	${ALL}
E 14
I 14
all: ${ALL}
E 14
E 2

I 9
libf77plot: FRC
	cd tf77; make ${MFLAGS}

E 9
D 4
libplot.a: FRC
E 4
I 4
libplot: FRC
E 4
	cd plot; make ${MFLAGS}
I 9

lib4013: FRC
	cd t4013; make ${MFLAGS}
E 9

D 4
libt4014.a: FRC
E 4
I 4
D 6
libt4014: FRC
E 6
I 6
lib4014: FRC
E 6
E 4
	cd t4014; make ${MFLAGS}

D 4
libt300.a: FRC
E 4
I 4
D 6
libt300: FRC
E 6
I 6
lib300: FRC
E 6
E 4
	cd t300; make ${MFLAGS}

D 4
libt300s.a: FRC
E 4
I 4
D 6
libt300s: FRC
E 6
I 6
lib300s: FRC
E 6
E 4
	cd t300s; make ${MFLAGS}

D 4
libt450.a: FRC
E 4
I 4
D 6
libt450: FRC
E 6
I 6
lib450: FRC
E 6
E 4
	cd t450; make ${MFLAGS}

D 4
libvt0.a: FRC
E 4
I 4
libvt0: FRC
E 4
	cd vt0; make ${MFLAGS}
I 8

libplotaed: FRC
	cd aed; make ${MFLAGS}

libplotbg: FRC
	cd bitgraph; make ${MFLAGS}

libplotdumb: FRC
	cd dumb; make ${MFLAGS}

libplotgigi: FRC
	cd gigi; make ${MFLAGS}

libplot2648: FRC
	cd hp2648; make ${MFLAGS}

libplot7221: FRC
	cd hp7221; make ${MFLAGS}
I 10

D 11
libimagen: FRC
E 11
I 11
libplotimagen: FRC
E 11
	cd imagen; make ${MFLAGS}
I 12

libplotgrn: FRC
	cd grn; make ${MFLAGS}
E 12
E 10
E 8

D 14
FRC:
E 14
I 14
clean: FRC
	rm -f ${ALL} core
	for i in ${SUBDIRS}; do \
		(cd $$i; make ${MFLAGS} clean); \
	done
E 14

D 14
install: all
E 14
I 14
depend: FRC
	for i in ${SUBDIRS}; do \
		(cd $$i; make ${MFLAGS} depend); \
	done

install: FRC
E 14
	for i in ${ALL}; do \
D 4
		install -m 644 $$i ${DESTDIR}/usr/lib/$$i; \
		ranlib ${DESTDIR}/usr/lib/$$i; \
E 4
I 4
D 14
		install -m 644 $$i ${DESTDIR}/usr/lib/$$i.a; \
E 14
I 14
		install -o bin -g bin -m 644 $$i ${DESTDIR}/usr/lib/$$i.a; \
E 14
		ranlib ${DESTDIR}/usr/lib/$$i.a; \
E 4
	done

D 14
clean:
	rm -f ${ALL} errs a.out core
E 14
I 14
tags: FRC
E 14
I 3
D 5
	for i in ${ALL}; do \
E 5
I 5
	for i in ${SUBDIRS}; do \
E 5
D 14
		(cd $$i; make ${MFLAGS} clean); \
E 14
I 14
		(cd $$i; make ${MFLAGS} tags); \
E 14
	done
I 14

lint:
FRC:
E 14
E 3
E 1
