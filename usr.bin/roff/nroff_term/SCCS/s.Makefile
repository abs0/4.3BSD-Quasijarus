h30667
s 00007/00003/00115
d D 5.2 04/09/13 02:14:13 msokolov 9 8
c add tabcol8
e
s 00008/00005/00110
d D 5.1 04/09/08 17:08:25 msokolov 8 7
c add tablpr8
e
s 00095/00041/00020
d D 4.7 87/06/18 22:17:45 bostic 7 6
c new template
e
s 00001/00004/00060
d D 4.6 86/05/15 06:48:30 lepreau 6 5
c "make links" must be done every time or else the links get broken & never remade
e
s 00002/00001/00062
d D 4.5 86/04/03 18:59:37 mckusick 5 4
c addition of nec25-t (from muller@nprdc.arpa (Keith Muller))
e
s 00001/00001/00062
d D 4.4 85/12/13 11:27:41 donn 4 3
c pass DESTDIR value to 'make links' during 'make install'
e
s 00002/00001/00061
d D 4.3 85/05/21 12:19:08 miriam 3 2
c include epson
e
s 00001/00001/00061
d D 4.2 83/08/15 12:17:32 root 2 1
c ignore error return from test ! -f .../tabtn300
c 	(karels)
e
s 00062/00000/00000
d D 4.1 83/08/05 13:34:29 sam 1 0
c date and time created 83/08/05 13:34:29 by sam
e
u
U
t
T
I 1
D 7
#	%M%	%I%	%E%
E 7
#
I 7
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 7
# Possible options:
D 7
#	make		compile source for terminal tables below
E 7
I 7
#	make		compile source for all terminal tables below
E 7
#	make <term>	compile table for a specific <term>
#	make install	move tables to ${DEST}
D 7
#	make links	make links for ease of documentation
E 7
#	make clean	remove tab*.o files lying around
D 7
ALL=	37 lpr 300 300-12 302 302-12 382 382-12 450 450-12 833 833-12 \
D 3
	itoh itoh12 nec nec12 nec-t qume qume12 xerox xerox12 \
E 3
I 3
D 5
	epson itoh itoh12 nec nec12 nec-t qume qume12 xerox xerox12 \
E 5
I 5
	epson itoh itoh12 nec nec12 nec-t nec25-t qume qume12 xerox xerox12 \
E 5
E 3
	x-ecs x-ecs12
DESTDIR=
E 7
I 7
CFLAGS=	-O
LIBC=	/lib/libc.a
E 7
DEST=	${DESTDIR}/usr/lib/term
I 7
SRCS=	tab300-12.c tab300.c tab302-12.c tab302.c tab37.c tab382-12.c \
	tab382.c tab450-12.c tab450.c tab833-12.c tab833.c tabepson.c \
D 8
	tabitoh.c tabitoh12.c tablpr.c tabnec-t.c tabnec.c tabnec12.c \
	tabnec25-t.c tabqume.c tabqume12.c tabx-ecs.c tabx-ecs12.c \
E 8
I 8
	tabitoh.c tabitoh12.c tablpr.c tablpr8.c tabnec-t.c tabnec.c \
	tabnec12.c tabnec25-t.c tabqume.c tabqume12.c tabx-ecs.c tabx-ecs12.c \
E 8
	tabxerox.c tabxerox12.c
OBJS=	tab300-12.o tab300.o tab302-12.o tab302.o tab37.o tab382-12.o \
	tab382.o tab450-12.o tab450.o tab833-12.o tab833.o tabepson.o \
D 8
	tabitoh.o tabitoh12.o tablpr.o tabnec-t.o tabnec.o tabnec12.o \
	tabnec25-t.o tabqume.o tabqume12.o tabx-ecs.o tabx-ecs12.o \
E 8
I 8
	tabitoh.o tabitoh12.o tablpr.o tablpr8.o tabnec-t.o tabnec.o \
	tabnec12.o tabnec25-t.o tabqume.o tabqume12.o tabx-ecs.o tabx-ecs12.o \
E 8
D 9
	tabxerox.o tabxerox12.o
D 8
ALL=	37 lpr 300 300-12 302 302-12 382 382-12 450 450-12 833 833-12 \
E 8
I 8
ALL=	37 lpr lpr8 300 300-12 302 302-12 382 382-12 450 450-12 833 833-12 \
E 8
	epson itoh itoh12 nec nec12 nec-t nec25-t qume qume12 xerox \
E 9
I 9
	tabxerox.o tabxerox12.o tabcol8.o
ALL=	37 lpr lpr8 col8 300 300-12 302 302-12 382 382-12 450 450-12 833 \
	833-12 epson itoh itoh12 nec nec12 nec-t nec25-t qume qume12 xerox \
E 9
	xerox12 x-ecs x-ecs12
E 7

D 7
all:	${ALL}
E 7
I 7
all: ${ALL}
E 7

D 7
37:	tab37.o
lpr:	tablpr.o
300:	tab300.o code.300
300-12:	tab300-12.o code.300
302:	tab302.o code.300
302-12:	tab302-12.o code.300
382:	tab382.o code.300
382-12: tab382-12.o code.300
450:	tab450.o code.300
450-12:	tab450-12.o code.300
833:	tab833.o code.aj833
833-12: tab833-12.o code.aj833
I 3
epson:	tabepson.o
E 3
itoh:	tabitoh.o code.itoh
itoh12: tabitoh12.o code.itoh
nec:	tabnec.o code.nec
nec12:	tabnec12.o code.nec
nec-t:	tabnec-t.o
I 5
nec25-t:tabnec25-t.o
E 5
qume:	tabqume.o
qume12:	tabqume12.o
xerox:	tabxerox.o code.xerox
xerox12:tabxerox12.o code.xerox
x-ecs:	tabx-ecs.o code.x-ecs
x-ecs12:tabx-ecs12.o code.x-ecs
E 7
I 7
37:		tab37.o
lpr:		tablpr.o
I 8
lpr8:		tablpr8.o
I 9
col8:		tabcol8.o
E 9
E 8
300:		tab300.o 
300-12:		tab300-12.o 
302:		tab302.o 
302-12:		tab302-12.o 
382:		tab382.o 
382-12:		tab382-12.o 
450:		tab450.o 
450-12:		tab450-12.o 
833:		tab833.o 
833-12:		tab833-12.o 
epson:		tabepson.o
itoh:		tabitoh.o 
itoh12:		tabitoh12.o 
nec:		tabnec.o 
nec12:		tabnec12.o 
nec-t:		tabnec-t.o
nec25-t:	tabnec25-t.o
qume:		tabqume.o
qume12:		tabqume12.o
xerox:		tabxerox.o 
xerox12:	tabxerox12.o 
x-ecs:		tabx-ecs.o 
x-ecs12:	tabx-ecs12.o 
I 9

tabcol8.o:	tablpr8.c
	${CC} ${CFLAGS} -DCOL8 -c -o $@ tablpr8.c
E 9
E 7

D 7
install:
E 7
I 7
clean: FRC
	rm -f ${OBJS} core

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
E 7
	for file in tab*.o; do \
D 7
		install -s -m 755 $$file ${DEST}/`basename $$file .o`;\
E 7
I 7
		install -s -o bin -g bin -m 755 $$file ${DEST}/`basename $$file .o`; \
E 7
	done
D 2
	if test ! -f ${DEST}/tabtn300; \
E 2
I 2
D 6
	-if test ! -f ${DEST}/tabtn300; \
E 2
	then \
D 4
		make links; \
E 4
I 4
		make DESTDIR=${DESTDIR} links; \
E 4
	fi
E 6
I 6
D 7
	make DESTDIR=${DESTDIR} links
E 6
	install -c -m 644 README ${DEST}/README

links:
E 7
	rm -f ${DEST}/tabtn300; ln ${DEST}/tablpr ${DEST}/tabtn300
	rm -f ${DEST}/tabcrt; ln ${DEST}/tablpr ${DEST}/tabcrt
I 8
	rm -f ${DEST}/tabcrt8; ln ${DEST}/tablpr8 ${DEST}/tabcrt8
E 8
	rm -f ${DEST}/tab300s; ln ${DEST}/tab302 ${DEST}/tab300s
	rm -f ${DEST}/tab300s-12; ln ${DEST}/tab302-12 ${DEST}/tab300s-12
	rm -f ${DEST}/tabdtc; ln ${DEST}/tab302 ${DEST}/tabdtc
	rm -f ${DEST}/tabdtc12; ln ${DEST}/tab302-12 ${DEST}/tabdtc12
	rm -f ${DEST}/tabipsi; ln ${DEST}/tab450 ${DEST}/tabipsi
	rm -f ${DEST}/tabipsi12; ln ${DEST}/tab450-12 ${DEST}/tabipsi12
I 7
	install -c -o bin -g bin -m 644 README ${DEST}/README
E 7

D 7
clean:
	rm -f tab*.o errs
E 7
I 7
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

tab300-12.o: tab300-12.c code.300
tab300.o: tab300.c code.300
tab302-12.o: tab302-12.c code.300
tab302.o: tab302.c code.300
tab37.o: tab37.c
tab382-12.o: tab382-12.c code.300
tab382.o: tab382.c code.300
tab450-12.o: tab450-12.c code.300
tab450.o: tab450.c code.300
tab833-12.o: tab833-12.c code.aj833
tab833.o: tab833.c code.aj833
tabepson.o: tabepson.c
tabitoh.o: tabitoh.c code.itoh
tabitoh12.o: tabitoh12.c code.itoh
tablpr.o: tablpr.c
I 8
tablpr8.o: tablpr8.c
E 8
tabnec-t.o: tabnec-t.c
tabnec.o: tabnec.c code.nec
tabnec12.o: tabnec12.c code.nec
tabnec25-t.o: tabnec25-t.c
tabqume.o: tabqume.c
tabqume12.o: tabqume12.c
tabx-ecs.o: tabx-ecs.c code.x-ecs
tabx-ecs12.o: tabx-ecs12.c code.x-ecs
tabxerox.o: tabxerox.c code.xerox
tabxerox12.o: tabxerox12.c code.xerox

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 1
