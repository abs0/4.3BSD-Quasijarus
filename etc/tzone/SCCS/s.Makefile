h06336
s 00001/00001/00062
d D 5.5 01/05/23 21:48:03 msokolov 5 4
c BSD development is back in California, change the default timezone to
c US/Pacific
e
s 00003/00003/00060
d D 5.4 99/09/29 18:10:23 msokolov 4 3
c install zdump and zic, don't build the timezone files twice
c BSD UNIX development is now hosted at the IFCTF Harhan facility in Dallas, TX,
c change the default timezone to US/Central
e
s 00000/00000/00063
d D 5.3 99/09/29 18:02:17 msokolov 3 2
c bump it up to 5.3
e
s 00000/00000/00063
d D 5.2 99/09/29 18:02:01 msokolov 2 1
c bump it up to 5.3
e
s 00063/00000/00000
d D 5.1 99/09/29 18:01:41 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 5.3
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#

# If you want something other than Eastern United States time used on your
# system, change the line below (after finding the zone you want in the
# time zone files, or adding it to a time zone file).
# Alternately, if you discover you've got the wrong time zone, you can just
#	zic -l rightzone
D 4
LOCALTIME=	US/Pacific
E 4
I 4
D 5
LOCALTIME=	US/Central
E 5
I 5
LOCALTIME=	US/Pacific
E 5
E 4

# If you want code inspired by certain emerging standards, add
#	-DSTD_INSPIRED
# to the end of the "CFLAGS=" line.

CFLAGS=	-O
LIBC=	/lib/libc.a
TZCSRCS=	zic.c scheck.c ialloc.c
TZCOBJS=	zic.o scheck.o ialloc.o
TZDSRCS=	zdump.c ialloc.c
TZDOBJS=	zdump.o ialloc.o
DOCS=		Theory README Makefile newctime.3 tzfile.5 zic.8 zdump.8
SRCS=		zic.c zdump.c scheck.c ialloc.c

# If you want to handle solar-time-based time zones, remove the
# "#define NOSOLAR" from the include file usr/include/tzfile.h.
# (and add solar87 to the DATA= line below).
DATA=		asia australasia europe etcetera northamerica \
		pacificnew systemv

all: zdump zic

zdump: ${TZDOBJS} ${LIBC}
	${CC} ${CFLAGS} ${TZDOBJS} -o $@

zic: ${TZCOBJS} ${LIBC}
	${CC} ${CFLAGS} ${TZCOBJS} -o $@

clean: FRC
	rm -f ${TZDOBJS} ${TZCOBJS} core zdump zic

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
D 4
	./zic ${DATA}
	./zic -d ${DESTDIR}/etc/zoneinfo -l ${LOCALTIME} ${DATA}
E 4
I 4
	install -s -o bin -g bin -m 755 zdump zic ${DESTDIR}/etc
	${DESTDIR}/etc/zic -d ${DESTDIR}/etc/zoneinfo -l ${LOCALTIME} ${DATA}
E 4

lint: FRC
	lint ${CFLAGS} ${TZCSRCS}
	lint ${CFLAGS} ${TZDSRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 1
