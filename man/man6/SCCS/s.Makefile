h13251
s 00008/00026/00026
d D 5.8 04/10/20 18:06:04 msokolov 8 7
c back to 4.3BSD /usr/man format
e
s 00002/00002/00050
d D 5.7 99/09/29 18:25:34 msokolov 7 6
c Franz Lisp is now a separate package, so its man pages go
e
s 00003/00000/00049
d D 5.6 99/09/28 14:56:38 msokolov 6 5
c run phantasia.6 through tbl -TX
e
s 00005/00005/00044
d D 5.5 99/06/02 14:17:36 msokolov 5 4
c Axe out gnuchess. Hell known how it got there.
c Add phantasia(6)
c ppt.0 was missing from LINKS
e
s 00000/00000/00049
d D 5.4 99/06/02 14:08:48 msokolov 4 3
c bump it up to 5.4
e
s 00000/00000/00049
d D 5.3 99/06/02 14:08:26 msokolov 3 2
c bump it up to 5.4
e
s 00000/00000/00049
d D 5.2 99/06/02 14:08:00 msokolov 2 1
c bump it up to 5.4
e
s 00049/00000/00000
d D 5.1 99/06/02 14:06:44 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 5.4
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
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
#
#	%W% (Berkeley) %G%
#
D 8
MDIR=	/usr/man/cat6
SRCS=	aardvark.6 adventure.6 arithmetic.6 atc.6 backgammon.6 banner.6 \
	battlestar.6 bcd.6 boggle.6 canfield.6 chess.6 ching.6 cribbage.6 \
D 5
	doctor.6 fish.6 fortune.6 gnuchess.6 hack.6 hangman.6 hunt.6 \
	mille.6 monop.6 number.6 quiz.6 rain.6 robots.6 \
E 5
I 5
D 7
	doctor.6 fish.6 fortune.6 hack.6 hangman.6 hunt.6 \
E 7
I 7
	fish.6 fortune.6 hack.6 hangman.6 hunt.6 \
E 7
	mille.6 monop.6 number.6 phantasia.6 quiz.6 rain.6 robots.6 \
E 5
	rogue.6 sail.6 snake.6 trek.6 worm.6 worms.6 wump.6 zork.6
OBJS=	aardvark.0 adventure.0 arithmetic.0 atc.0 backgammon.0 banner.0 \
	battlestar.0 bcd.0 boggle.0 canfield.0 chess.0 ching.0 cribbage.0 \
D 5
	doctor.0 fish.0 fortune.0 gnuchess.0 hack.0 hangman.0 hunt.0 \
	mille.0 monop.0 number.0 quiz.0 rain.0 robots.0 \
E 5
I 5
D 7
	doctor.0 fish.0 fortune.0 hack.0 hangman.0 hunt.0 \
E 7
I 7
	fish.0 fortune.0 hack.0 hangman.0 hunt.0 \
E 7
	mille.0 monop.0 number.0 phantasia.0 quiz.0 rain.0 robots.0 \
E 5
	rogue.0 sail.0 snake.0 trek.0 worm.0 worms.0 wump.0 zork.0
D 5
LINKS=	snscore.0 cfscores.0
E 5
I 5
LINKS=	snscore.0 cfscores.0 ppt.0
E 8
I 8
MDIR=	/usr/man/man6
E 8
E 5

D 8
.SUFFIXES: .6 .0
E 8
I 8
all:
E 8

D 8
.6.0:
	${DESTDIR}/usr/man/manroff $*.6 > $*.0
E 8
I 8
psman: FRC
	for i in *.6; do echo $$i; pstroff -man $$i > $$i.ps; done
E 8

D 8
all: ${OBJS}

I 6
phantasia.0:
	tbl -TX phantasia.6 | ${DESTDIR}/usr/man/manroff > $@

E 8
E 6
clean: FRC
D 8
	rm -f ${OBJS}
E 8
I 8
	rm -f *.ps
E 8

install: FRC
D 8
	cd ${DESTDIR}${MDIR}; rm -f *.0
	install -c -o bin -g bin -m 444 ${OBJS} ${DESTDIR}${MDIR}
	ln ${DESTDIR}${MDIR}/snake.0 ${DESTDIR}${MDIR}/snscore.0
	ln ${DESTDIR}${MDIR}/canfield.0 ${DESTDIR}${MDIR}/cfscores.0
	ln ${DESTDIR}${MDIR}/bcd.0 ${DESTDIR}${MDIR}/ppt.0
E 8
I 8
	cd ${DESTDIR}${MDIR}; rm -f *
	install -c -o bin -g bin -m 444 *.6 ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.6 ${DESTDIR}${MDIR}
E 8

FRC:
E 1
