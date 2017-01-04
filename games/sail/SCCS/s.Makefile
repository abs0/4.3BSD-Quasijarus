h02742
s 00010/00005/00135
d D 5.7 88/06/18 19:55:09 bostic 35 34
c install approved copyright notice
e
s 00009/00003/00131
d D 5.6 88/03/09 12:24:10 bostic 34 33
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00049/00036/00085
d D 5.5 87/09/21 11:57:14 bostic 33 31
c integrate with dm
e
s 00051/00036/00085
d R 5.5 87/09/20 10:57:40 bostic 32 31
c integrate with dm
e
s 00101/00055/00020
d D 5.4 87/06/03 17:07:09 bostic 31 30
c new template
e
s 00002/00000/00073
d D 5.3 87/05/31 21:01:50 bostic 30 29
c added depend label
e
s 00001/00002/00072
d D 5.2 85/09/17 21:32:38 mckusick 29 28
c sail.6 need not be installed
e
s 00004/00006/00070
d D 5.1 85/06/05 09:23:12 dist 28 27
c Add copyright
e
s 00023/00074/00053
d D 2.10 85/04/25 20:57:47 edward 27 26
c don't depend on /usr/include anymore
e
s 00007/00002/00120
d D 2.9 85/04/23 21:46:07 edward 26 25
c copyright message
e
s 00092/00021/00030
d D 2.8 85/03/04 19:03:57 edward 25 23
c changed some more filenames, and .h dependencies added
e
s 00090/00019/00032
d R 2.8 85/03/04 18:37:59 edward 24 23
c changed some more filenames, and dependencies added
e
s 00023/00038/00028
d D 2.7 85/03/04 18:07:10 edward 23 22
c more cleanup; sail, driver, sail.log merged into single program
e
s 00003/00016/00063
d D 2.6 84/12/03 17:32:31 edward 22 21
c some install fixes
e
s 00003/00003/00076
d D 2.5 84/02/14 18:16:40 edward 21 20
c Install with read bits on.
e
s 00010/00000/00069
d D 2.4 84/02/13 18:52:22 edward 20 19
c added rdist commands
e
s 00004/00004/00065
d D 2.3 83/11/09 11:32:26 edward 19 18
c use install -c
e
s 00003/00003/00066
d D 2.2 83/10/31 14:55:04 edward 18 16
c something else wrong
e
s 00002/00002/00067
d R 2.2 83/10/31 14:52:36 edward 17 16
c something else wrong
e
s 00000/00000/00069
d D 2.1 83/10/31 13:43:04 edward 16 15
c new version
e
s 00001/00001/00068
d D 1.15 83/10/31 13:37:28 edward 15 14
c messed up
e
s 00028/00035/00041
d D 1.14 83/10/31 13:34:24 edward 14 13
c DESTDIR, and general cleanup.
e
s 00004/00002/00072
d D 1.13 83/10/28 19:22:53 edward 13 12
c rearranged player and screen stuff
e
s 00006/00011/00068
d D 1.12 83/10/10 20:09:37 edward 12 11
c got rid of unnecessary variables
e
s 00002/00002/00077
d D 1.11 83/10/05 11:43:25 edward 11 10
c changed sizes of things and reformated globals.c
e
s 00032/00034/00047
d D 1.10 83/07/20 17:16:56 edward 10 9
c 
e
s 00001/00001/00080
d D 1.9 83/05/20 21:28:38 root 9 8
c catch SIGCHLD
e
s 00002/00002/00079
d D 1.8 83/05/20 19:09:02 edward 8 7
c moved driver to /usr/games/lib and merged externs.h and globals.c
e
s 00003/00003/00078
d D 1.7 83/05/20 16:41:15 leres 7 6
c Lowercase binary names
e
s 00002/00002/00079
d D 1.6 83/05/19 23:25:35 leres 6 5
c removed sail.doc stuff
e
s 00010/00010/00071
d D 1.5 83/05/19 22:47:58 leres 5 4
c Changed from /usr/public to /usr/games
e
s 00002/00002/00079
d D 1.4 83/03/19 13:52:32 leres 4 3
c Added version
e
s 00024/00021/00057
d D 1.3 83/03/18 15:23:06 leres 3 2
c Make install now does a /usr/public install. Also added sccs get for
c missing source.
e
s 00010/00011/00068
d D 1.2 83/03/18 11:14:54 leres 2 1
c Added "all" to make all of the useful stuff
e
s 00079/00000/00000
d D 1.1 83/03/17 21:08:56 leres 1 0
c date and time created 83/03/17 21:08:56 by leres
e
u
U
t
T
I 1
#
D 26
# Sail - Wooden Ships And Iron Men
E 26
I 26
D 28
# Copyright (c) 1983 Regents of the University of California,
# All rights reserved.  Redistribution permitted subject to
# the terms of the Berkeley Software License Agreement.
E 28
I 28
D 31
# Copyright (c) 1980 Regents of the University of California.
E 31
I 31
# Copyright (c) 1987 Regents of the University of California.
E 31
D 34
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 34
I 34
# All rights reserved.
E 34
E 28
E 26
#
D 26
# Makefile	%W% %E%
E 26
I 26
D 28

E 26
#
I 26
# %W% %E%
E 28
I 28
D 31
#	%W% (Berkeley) %G%
E 31
I 31
D 34
#	%W%	(Berkeley)	%G%
E 34
I 34
# Redistribution and use in source and binary forms are permitted
D 35
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 35
I 35
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
E 35
#
#	%W% (Berkeley) %G%
E 34
E 31
E 28
#
D 31

E 26
D 14
CC= cc
I 3
CTAGS= ctags -w
E 3
D 2
CFLAGS= -O -v
E 2
I 2
CFLAGS= -O
E 14
I 14
D 25
CC=	cc
CTAGS=	ctags -w
CFLAGS=	-O
E 25
I 25
CTAGS = ctags -w
CFLAGS = -O
E 25
E 14
E 2
D 10
DFILES= driver1.c driver2.c driver3.c grap.c
DOBJS= driver1.o driver2.o driver3.o grap.o
D 4
PFILES= player1.c player2.c
POBJS= player1.o player2.o
E 4
I 4
PFILES= version.c player1.c player2.c
POBJS= version.o player1.o player2.o
E 10
I 10

D 14
DFILES= driver1.c driver2.c driver3.c grap.c boarders.c
DOBJS= driver1.o driver2.o driver3.o grap.o boarders.o
D 13
PFILES= player1.c player2.c player3.c player4.c version.c
POBJS= player1.o player2.o player3.o player4.o version.o
E 13
I 13
PFILES= player1.c player2.c player3.c player4.c player5.c player6.c player7.c \
	version.c
POBJS= player1.o player2.o player3.o player4.o player5.o player6.o player7.o \
	version.o
E 13
D 11
COMMONFILES= assorted.c game.c globals.c misc.c parties.c screen.c machdep.c
COMMONOBJS= assorted.o game.o globals.o misc.o parties.o screen.o machdep.o
E 11
I 11
D 12
COMMONFILES= assorted.c game.c globals.c misc.c parties.c screen.c
COMMONOBJS= assorted.o game.o globals.o misc.o parties.o screen.o
E 12
I 12
COMMONFILES= assorted.c game.c globals.c misc.c parties.c sync.c
COMMONOBJS= assorted.o game.o globals.o misc.o parties.o sync.o
E 12
E 11
E 10
E 4
LFILES= sail.log.c
LOBJS= sail.log.o
D 2
COMMONFILES= assorted.c boarders.c game.c globals.c \
E 2
I 2
D 10
COMMONFILES= assorted.c boarders.c game.c globals.c\
E 2
	main.c parties.c screen.c machdep.c
COMMONOBJS= assorted.o boarders.o game.o globals.o\
	main.o parties.o screen.o machdep.o
D 2
OTHERFILES= makefile externs.h player.h machdep.h sail.m
E 2
I 2
D 3
OTHERFILES= Makefile externs.h player.h machdep.h sail.m
E 3
I 3
HDRS= externs.h player.h machdep.h
OTHERFILES= Makefile sail.m
E 10
I 10

HDRS= externs.h player.h driver.h machdep.h
OTHERFILES= Makefile sail.6
E 10
CTAGFILES= ${DFILES} ${PFILES} ${LFILES} ${COMMONFILES}
E 3
E 2
D 10
JUNKFILES= sail driver sail.log sail.doc junk arch tags
D 9
PLIBS= -lcurses -ltermlib machdep.o
E 9
I 9
PLIBS= -lcurses -ltermlib machdep.o -ljobs
E 10
I 10
D 12
JUNKFILES= sail driver sail.log sail.doc
PLIBS= -lcurses -ltermlib machdep.o
E 12
I 12
JUNKFILES= make.out
PLIBS= -lcurses -ltermlib
E 14
I 14
D 23
DFILES=		driver1.c driver2.c driver3.c grap.c boarders.c
DOBJS=		driver1.o driver2.o driver3.o grap.o boarders.o
PFILES=		player1.c player2.c player3.c player4.c player5.c \
		player6.c player7.c version.c
POBJS=		player1.o player2.o player3.o player4.o player5.o \
		player6.o player7.o version.o
COMMONFILES=	assorted.c game.c globals.c misc.c parties.c sync.c
COMMONOBJS=	assorted.o game.o globals.o misc.o parties.o sync.o
LFILES=		sail.log.c
LOBJS=		sail.log.o
HDRS=		externs.h player.h driver.h machdep.h
E 23
I 23
D 25
CFILES=		main.c pl_main.c player1.c player2.c player3.c player4.c \
		player5.c player6.c player7.c dr_main.c driver1.c driver2.c \
		driver3.c driver4.c driver5.c lo_main.c assorted.c game.c \
		globals.c misc.c parties.c sync.c version.c
OBJS=		main.o pl_main.o player1.o player2.o player3.o player4.o \
		player5.o player6.o player7.o dr_main.o driver1.o driver2.o \
		driver3.o driver4.o driver5.o lo_main.o assorted.o game.o \
		globals.o misc.o parties.o sync.o version.o
HFILES=		externs.h player.h driver.h machdep.h
E 23
D 15
OTHERFILES	 Makefile sail.6
E 15
I 15
OTHERFILES=	Makefile sail.6
E 15
D 23
CTAGFILES=	${DFILES} ${PFILES} ${LFILES} ${COMMONFILES}
E 23
JUNKFILES=	make.out
D 23
PLIBS=		-lcurses -ltermlib
E 14
E 12
E 10
E 9
DLIBS=
LLIBS=
E 23
I 23
LIBS=		-lcurses -ltermlib
E 25
I 25
CFILES = main.c pl_main.c pl_1.c pl_2.c pl_3.c pl_4.c pl_5.c pl_6.c pl_7.c \
E 31
I 31
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBS=	-lcurses -ltermlib
SRCS=	main.c pl_main.c pl_1.c pl_2.c pl_3.c pl_4.c pl_5.c pl_6.c pl_7.c \
E 31
	dr_main.c dr_1.c dr_2.c dr_3.c dr_4.c dr_5.c lo_main.c \
	assorted.c game.c globals.c misc.c parties.c sync.c version.c
D 31
OBJS = main.o pl_main.o pl_1.o pl_2.o pl_3.o pl_4.o pl_5.o pl_6.o pl_7.o \
E 31
I 31
OBJS=	main.o pl_main.o pl_1.o pl_2.o pl_3.o pl_4.o pl_5.o pl_6.o pl_7.o \
E 31
	dr_main.o dr_1.o dr_2.o dr_3.o dr_4.o dr_5.o lo_main.o \
	assorted.o game.o globals.o misc.o parties.o sync.o version.o
D 31
HFILES = externs.h player.h driver.h machdep.h
OTHERFILES = Makefile sail.6
JUNKFILES = sail tags make.out
LIBS = -lcurses -ltermlib
E 31
E 25
E 23
I 3
D 14
SAILMASTER= daemon
E 3
D 2
HOME= /u1/tourist/leres
BIN= /u1/tourist/leres/bin
MAN= /u1/tourist/leres/man
SAIL= sail
E 2
I 2
D 7
SAIL= SAIL
E 7
I 7
SAIL= sail
E 7
E 2
D 8
DRIVER= .driver
E 8
I 8
DRIVER= lib/saildriver
E 8
D 2
SAIL.LOG= sail.log
SAIL.DOC= sail.doc
E 2
I 2
D 7
SAIL.LOG= SAIL.log
SAIL.DOC= SAIL.doc
E 7
I 7
SAIL.LOG= sail.log
D 12
SAIL.DOC= sail.doc
E 12
E 7
I 3
D 8
SHIPSLOG= .shipslog
E 8
I 8
D 10
SHIPSLOG= lib/saillog
E 10
I 10
LOGFILE= lib/saillog
E 10
E 8
D 5
PUBLIC= /usr/public
E 5
I 5
TARGET= /usr/games
E 14
E 5
E 3
E 2

I 14
D 25
SAILMASTER=	daemon
D 22
SAIL=		sail
E 22
D 23
DRIVER=		lib/saildriver
E 23
D 22
SAIL.LOG=	sail.log
E 22
LOGFILE=	lib/saillog
D 22
DESTDIR=
E 22
D 18
TARGET=		$(TARGET)/usr/games
E 18
I 18
TARGET=		$(DESTDIR)/usr/games
E 25
I 25
D 31
SAILMASTER = daemon
LOGFILE = lib/saillog
TARGET = $(DESTDIR)/usr/games
E 25
E 18

E 31
E 14
D 10
..c.o:; ${CC} ${CFLAGS} -c $<

E 10
I 2
D 12
all: sail driver sail.log sail.doc
E 12
I 12
D 23
all: sail driver sail.log
E 23
I 23
all: sail
E 23
E 12

E 2
D 10
sail: ${COMMONOBJS} ${POBJS}
E 10
I 10
D 23
sail: ${POBJS} ${COMMONOBJS}
E 10
	cc -O ${COMMONOBJS} ${POBJS} ${PLIBS} -o sail
E 23
I 23
D 31
sail: $(OBJS)
	$(CC) -o sail $(OBJS) $(LIBS)
E 31
I 31
sail: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS} ${LIBS}
E 31
E 23

D 10
driver: ${COMMONOBJS} ${DOBJS}
E 10
I 10
D 23
driver: ${DOBJS} ${COMMONOBJS}
E 10
	cc -O ${COMMONOBJS} ${DOBJS} ${DLIBS} -o driver

D 10
${DOBJS} ${POBJS} ${LOBJS} ${COMMONOBJS}: externs.h machdep.h

E 10
sail.log: ${LOBJS} globals.o
	cc -O ${LOBJS} globals.o -o sail.log

E 23
D 10
sail.doc: sail.m
D 6
	nroff -man sail.m > sail.doc
E 6
I 6
#	nroff -man sail.m > sail.doc
E 10
I 10
D 12
sail.doc: sail.6
#	nroff -man sail.6 > sail.doc
E 10
E 6

E 12
I 10
D 31
lint:
D 23
	lint -z $(PFILES) $(COMMONFILES) -lcurses
	lint -z $(DFILES) $(COMMONFILES)
E 23
I 23
	lint -z $(CFILES) -lcurses
E 31
I 31
clean: FRC
	rm -f ${OBJS} core sail
E 31
E 23

E 10
I 3
D 23
tags: ${CTAGFILES}
	${CTAGS} ${CTAGFILES}
E 23
I 23
D 31
tags: $(CFILES) $(HFILES)
	$(CTAGS) $(CFILES) $(HFILES)
E 31
I 31
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 31
E 23

D 23
${HDRS} ${CTAGFILES}:
E 23
I 23
D 31
$(CFILES) $(HFILES) $(OTHERFILES):
E 23
D 25
	sccs get $@;
E 25
I 25
	sccs get $@
E 31
I 31
install: FRC
D 33
	install -s -o daemon -g bin -m 4755 sail ${DESTDIR}/usr/games/sail
	install -c -o daemon -g bin -m 644 /dev/null ${DESTDIR}/usr/games/saillog
E 33
I 33
	install -c -o games -g bin -m 600 /dev/null ${DESTDIR}/usr/games/lib/saillog
	install -s -o games -g bin -m 4700 sail ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f sail; ln -s dm sail; chown games.bin sail)
E 33
E 31
E 25

E 3
D 2
arch:	sail.a
	ar uv sail.a ${PFILES} ${COMMONFILES} ${OTHERFILES} \
E 2
I 2
D 10
arch:	sail.ar
	ar uv sail.ar ${PFILES} ${COMMONFILES} ${OTHERFILES} \
E 2
D 3
	${DFILES} ${LFILES}
E 3
I 3
	${DFILES} ${LFILES} ${HDRS}
E 10
I 10
D 14
profile: sail.prof
E 10
E 3

D 10
driveprofile: ${COMMONOBJS} ${DOBJS}
	cc -i -p ${COMMONOBJS} ${DOBJS} ${CFLAGS} ${DLIBS} -o DRIVE.pro
E 10
I 10
driver.prof: ${COMMONOBJS} ${DOBJS}
	cc -i -p ${COMMONOBJS} ${DOBJS} ${CFLAGS} ${DLIBS} -o driver.prof
E 10

D 10
profile: ${COMMONOBJS} ${POBJS} ${DOBJS}
	cc -i -p ${COMMONOBJS} ${POBJS} ${CFLAGS} ${PLIBS} -o SAIL.pro
	cc -i -p ${COMMONOBJS} ${DOBJS} ${CFLAGS} ${DLIBS} -o DRIVE.pro
E 10
I 10
profile: sail.prof
	cc -i -p ${COMMONOBJS} ${POBJS} ${CFLAGS} ${PLIBS} -o sail.prof
E 10

E 14
D 3
install: ${BIN}/${SAIL} ${BIN}/${DRIVER} ${BIN}/${SAIL.LOG} ${MAN}/${SAIL.DOC}
${BIN}/${SAIL}: sail
	rm -f ${BIN}/${SAIL}
	cp sail ${BIN}/${SAIL}
	chmod 711 ${BIN}/${SAIL}
${BIN}/${DRIVER}: driver
	rm -f ${BIN}/${DRIVER}
	cp driver ${BIN}/${DRIVER}
	chmod 711 ${BIN}/${DRIVER}
${BIN}/${SAIL.LOG}: sail.log
	rm -f ${BIN}/${SAIL.LOG}
	cp sail.log ${BIN}/${SAIL.LOG}
	chmod 710 ${BIN}/${SAIL.LOG}
	strip ${BIN}/${SAIL.LOG}
${MAN}/${SAIL.DOC}: sail.doc
	rm -f ${MAN}/${SAIL.DOC}
	cp sail.doc ${MAN}/${SAIL.DOC}
	chmod 640 ${MAN}/${SAIL.DOC}

E 3
D 27
clean: 
E 27
I 27
D 31
clean:
E 27
D 23
	rm -f ${DOBJS} ${POBJS} ${LOBJS} ${COMMONOBJS} ${JUNKFILES}
E 23
I 23
	rm -f $(OBJS) $(JUNKFILES)
E 31
I 31
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 31
E 23

I 30
D 31
depend:
E 31
I 31
tags: FRC
	ctags ${SRCS}
E 31

E 30
I 3
D 5
install: sail driver sail.log sail.doc ${PUBLIC}/${SHIPSLOG}
	install -s -m 4711 -o ${SAILMASTER} sail ${PUBLIC}/${SAIL}
	install -s -m 4711 -o ${SAILMASTER} driver ${PUBLIC}/${DRIVER}
	install -s -m 711 sail.log ${PUBLIC}/${SAIL.LOG}
	cp sail.doc ${PUBLIC}/${SAIL.DOC}
E 5
I 5
D 10
install: sail driver sail.log sail.doc ${TARGET}/${SHIPSLOG}
E 10
I 10
D 12
install: sail driver sail.log sail.doc ${TARGET}/${LOGFILE}
E 12
I 12
D 14
install: sail driver sail.log ${TARGET}/${LOGFILE}
E 14
I 14
D 18
install: sail driver sail.log logfile
E 18
I 18
D 23
install: sail driver sail.log $(TARGET)/$(LOGFILE)
E 18
E 14
E 12
E 10
D 19
	install -s -m 4711 -o ${SAILMASTER} sail ${TARGET}/${SAIL}
	install -s -m 4711 -o ${SAILMASTER} driver ${TARGET}/${DRIVER}
	install -s -m 711 sail.log ${TARGET}/${SAIL.LOG}
I 10
	install sail.6 /usr/man/man6
E 19
I 19
D 21
	install -c -s -m 4711 -o ${SAILMASTER} sail ${TARGET}/${SAIL}
	install -c -s -m 4711 -o ${SAILMASTER} driver ${TARGET}/${DRIVER}
	install -c -s -m 711 sail.log ${TARGET}/${SAIL.LOG}
E 21
I 21
D 22
	install -c -s -m 4755 -o ${SAILMASTER} sail ${TARGET}/${SAIL}
E 22
I 22
	install -c -s -m 4755 -o ${SAILMASTER} sail ${TARGET}/sail
E 22
	install -c -s -m 4755 -o ${SAILMASTER} driver ${TARGET}/${DRIVER}
D 22
	install -c -s -m 755 sail.log ${TARGET}/${SAIL.LOG}
E 21
	install -c sail.6 /usr/man/man6
E 22
I 22
	install -c -s -m 755 sail.log ${TARGET}/sail.log
E 23
I 23
D 29
install: sail sail.6 $(TARGET)/$(LOGFILE)
E 29
I 29
D 31
install: sail $(TARGET)/$(LOGFILE)
E 29
D 25
	install -c -s -m 4755 -o $(SAILMASTER) sail $(TARGET)/sail
E 23
	install -c sail.6 $(DESTDIR)/usr/man/man6
E 25
I 25
	install -s -m 4755 -o $(SAILMASTER) sail $(TARGET)/sail
E 31
I 31
FRC:
E 31
D 29
	install -c -m 644 sail.6 $(DESTDIR)/usr/man/man6
E 29
E 25
E 22
E 19
E 10
D 6
	cp sail.doc ${TARGET}/${SAIL.DOC}
E 6
I 6
D 12
#	cp sail.doc ${TARGET}/${SAIL.DOC}
E 12
E 6
E 5

D 5
${PUBLIC}/${SHIPSLOG}:
	cp /dev/null ${PUBLIC}/${SHIPSLOG}
	chown ${SAILMASTER} ${PUBLIC}/${SHIPSLOG}
	chmod 644 ${PUBLIC}/${SHIPSLOG}
E 5
I 5
D 10
${TARGET}/${SHIPSLOG}:
	cp /dev/null ${TARGET}/${SHIPSLOG}
	chown ${SAILMASTER} ${TARGET}/${SHIPSLOG}
	chmod 644 ${TARGET}/${SHIPSLOG}
E 10
I 10
D 14
${TARGET}/${LOGFILE}:
E 14
I 14
D 18
logfile:
E 18
I 18
D 31
logfile $(TARGET)/$(LOGFILE):
E 18
E 14
D 23
	cp /dev/null ${TARGET}/${LOGFILE}
	chown ${SAILMASTER} ${TARGET}/${LOGFILE}
	chmod 644 ${TARGET}/${LOGFILE}
E 23
I 23
	cp /dev/null $(TARGET)/$(LOGFILE)
	chown $(SAILMASTER) $(TARGET)/$(LOGFILE)
	chmod 644 $(TARGET)/$(LOGFILE)
E 31
I 31
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 31
I 25

D 27
###
assorted.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
dr_1.o: driver.h externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
dr_2.o: driver.h externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
dr_3.o: driver.h externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
dr_4.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
dr_5.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
dr_main.o: driver.h externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
game.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
globals.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
lo_main.o: /usr/include/pwd.h externs.h /usr/include/stdio.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h
main.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
misc.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h \
	/usr/include/sys/file.h
parties.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h
pl_1.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h /usr/include/sys/types.h /usr/include/sys/wait.h
pl_2.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h
pl_3.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h
pl_4.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h
pl_5.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h
pl_6.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h
pl_7.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h
pl_main.o: player.h /usr/include/curses.h /usr/include/stdio.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h \
	/usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h \
	machdep.h /usr/include/sys/types.h /usr/include/sys/wait.h
sync.o: externs.h /usr/include/stdio.h /usr/include/signal.h \
	/usr/include/ctype.h /usr/include/setjmp.h machdep.h \
	/usr/include/sys/file.h /usr/include/sys/errno.h \
	/usr/include/sys/types.h /usr/include/sys/stat.h
E 27
I 27
D 31
main.o: externs.h machdep.h
pl_main.o: player.h externs.h machdep.h
pl_1.o: player.h externs.h machdep.h
pl_2.o: player.h externs.h machdep.h
pl_3.o: player.h externs.h machdep.h
pl_4.o: player.h externs.h machdep.h
pl_5.o: player.h externs.h machdep.h
pl_6.o: player.h externs.h machdep.h
pl_7.o: player.h externs.h machdep.h
dr_main.o: driver.h externs.h machdep.h
dr_1.o: driver.h externs.h machdep.h
dr_2.o: driver.h externs.h machdep.h
dr_3.o: driver.h externs.h machdep.h
dr_4.o: externs.h machdep.h
dr_5.o: externs.h machdep.h
lo_main.o: externs.h machdep.h
assorted.o: externs.h machdep.h
game.o: externs.h machdep.h
globals.o: externs.h machdep.h
misc.o: externs.h machdep.h
parties.o: externs.h machdep.h
sync.o: externs.h machdep.h
E 31
I 31
main.o: main.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
main.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
main.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
main.o: machdep.h
E 33
pl_main.o: pl_main.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_main.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_main.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
E 33
I 33
pl_main.o: /usr/include/stdio.h /usr/include/signal.h
pl_main.o: /usr/include/machine/trap.h /usr/include/ctype.h
E 33
pl_main.o: /usr/include/setjmp.h machdep.h /usr/include/sys/types.h
pl_main.o: /usr/include/sys/wait.h /usr/include/machine/machparam.h
pl_1.o: pl_1.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_1.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_1.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_1.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
pl_1.o: /usr/include/setjmp.h machdep.h /usr/include/sys/types.h
pl_1.o: /usr/include/sys/wait.h /usr/include/machine/machparam.h
E 33
I 33
pl_1.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
pl_1.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
pl_1.o: /usr/include/sys/types.h /usr/include/sys/wait.h
pl_1.o: /usr/include/machine/machparam.h
E 33
pl_2.o: pl_2.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_2.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_2.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_2.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
pl_2.o: /usr/include/setjmp.h machdep.h
E 33
I 33
pl_2.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
pl_2.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
pl_3.o: pl_3.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_3.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_3.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_3.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
pl_3.o: /usr/include/setjmp.h machdep.h
E 33
I 33
pl_3.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
pl_3.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
pl_4.o: pl_4.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_4.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_4.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_4.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
pl_4.o: /usr/include/setjmp.h machdep.h
E 33
I 33
pl_4.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
pl_4.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
pl_5.o: pl_5.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_5.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_5.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_5.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
pl_5.o: /usr/include/setjmp.h machdep.h
E 33
I 33
pl_5.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
pl_5.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
pl_6.o: pl_6.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_6.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_6.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_6.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
pl_6.o: /usr/include/setjmp.h machdep.h
E 33
I 33
pl_6.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
pl_6.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
pl_7.o: pl_7.c player.h /usr/include/curses.h /usr/include/stdio.h
pl_7.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
pl_7.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h externs.h
D 33
pl_7.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
pl_7.o: /usr/include/setjmp.h machdep.h
E 33
I 33
pl_7.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
pl_7.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
dr_main.o: dr_main.c driver.h externs.h /usr/include/stdio.h
D 33
dr_main.o: /usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h
dr_main.o: machdep.h
E 33
I 33
dr_main.o: /usr/include/signal.h /usr/include/machine/trap.h
dr_main.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
dr_1.o: dr_1.c driver.h externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
dr_1.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
dr_1.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
dr_1.o: machdep.h
E 33
dr_2.o: dr_2.c driver.h externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
dr_2.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
dr_2.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
dr_2.o: machdep.h
E 33
dr_3.o: dr_3.c driver.h externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
dr_3.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
dr_3.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
dr_3.o: machdep.h
E 33
dr_4.o: dr_4.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
dr_4.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
dr_4.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
dr_4.o: machdep.h
E 33
dr_5.o: dr_5.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
dr_5.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
dr_5.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
dr_5.o: machdep.h
E 33
lo_main.o: lo_main.c /usr/include/pwd.h externs.h /usr/include/stdio.h
D 33
lo_main.o: /usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h
lo_main.o: machdep.h
E 33
I 33
lo_main.o: /usr/include/signal.h /usr/include/machine/trap.h
lo_main.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
assorted.o: assorted.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
assorted.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
assorted.o: /usr/include/machine/trap.h /usr/include/ctype.h
assorted.o: /usr/include/setjmp.h machdep.h
E 33
game.o: game.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
game.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
game.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
game.o: machdep.h
E 33
globals.o: globals.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
globals.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
globals.o: /usr/include/machine/trap.h /usr/include/ctype.h
globals.o: /usr/include/setjmp.h machdep.h
E 33
misc.o: misc.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
misc.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
misc.o: /usr/include/sys/file.h
E 33
I 33
misc.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
misc.o: machdep.h /usr/include/sys/file.h
E 33
parties.o: parties.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
parties.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
E 33
I 33
parties.o: /usr/include/machine/trap.h /usr/include/ctype.h
parties.o: /usr/include/setjmp.h machdep.h
E 33
sync.o: sync.c externs.h /usr/include/stdio.h /usr/include/signal.h
D 33
sync.o: /usr/include/ctype.h /usr/include/setjmp.h machdep.h
sync.o: /usr/include/sys/file.h /usr/include/sys/errno.h
E 33
I 33
sync.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/setjmp.h
sync.o: machdep.h /usr/include/sys/file.h /usr/include/sys/errno.h
E 33
sync.o: /usr/include/sys/types.h /usr/include/sys/stat.h
version.o: version.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 31
E 27
E 25
E 23
I 20
D 22

miro:
	rdist -c '$(TARGET)/{$(SAIL),sail.log,$(DRIVER)}' \
		/usr/man/man6/sail.6 miro
cory:
	rdist -c '$(TARGET)/{$(SAIL),sail.log,$(DRIVER)}' \
		/usr/man/man6/sail.6 cory
dali:
	rdist -c '$(TARGET)/{$(SAIL),sail.log,$(DRIVER)}' \
		/usr/man/man6/sail.6 dali
E 22
E 20
E 10
E 5
E 3
E 1
