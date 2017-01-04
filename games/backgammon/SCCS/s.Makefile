h41674
s 00010/00005/00099
d D 5.13 88/06/18 19:46:53 bostic 18 17
c install approved copyright notice
e
s 00011/00005/00093
d D 5.12 88/02/16 11:15:54 bostic 17 16
c add Berkeley specific header, remove -w flag from compiles
e
s 00002/00006/00096
d D 5.11 88/02/02 12:10:36 mckusick 16 15
c backgammon.src moves to /usr/src/man/man6/backgammon.6
e
s 00001/00001/00101
d D 5.10 87/12/01 17:54:47 bostic 15 14
c typo
e
s 00004/00002/00098
d D 5.9 87/09/21 11:21:21 bostic 14 11
c integrate with dm
e
s 00006/00002/00098
d R 5.9 87/09/19 17:02:20 bostic 13 11
c integrate with dm
e
s 00006/00002/00098
d R 5.9 87/09/19 13:52:26 bostic 12 11
c integrate with dm
e
s 00004/00008/00096
d D 5.8 87/09/04 17:37:05 bostic 11 10
c moved message.c to version.c
e
s 00001/00001/00103
d D 5.7 87/08/30 09:23:24 mckusick 10 9
c avoid editing unwritable files; bug report 4.3BSD/games/9
e
s 00086/00034/00018
d D 5.6 87/06/03 10:55:42 bostic 9 8
c new template
e
s 00002/00000/00050
d D 5.5 87/05/31 20:57:49 bostic 8 7
c added depend label
e
s 00001/00001/00049
d D 5.4 86/01/11 23:48:57 lepreau 7 6
c add -w to CFLAGS
e
s 00001/00001/00049
d D 5.3 86/01/11 20:52:43 lepreau 6 5
c clean better
e
s 00003/00003/00047
d D 5.2 85/09/07 16:49:12 mckusick 5 4
c strip on install; clean binaries
e
s 00007/00002/00043
d D 5.1 85/05/29 11:28:42 dist 4 3
c Add copyright
e
s 00000/00006/00045
d D 1.3 82/11/27 12:33:08 mckusick 3 2
c make game saving and restoring rational
e
s 00005/00011/00046
d D 1.2 82/10/24 19:05:25 mckusick 2 1
c add clean entry
e
s 00057/00000/00000
d D 1.1 82/05/11 14:55:02 rrh 1 0
c date and time created 82/05/11 14:55:02 by rrh
e
u
U
t
T
I 1
D 4
#	%M%	%I%	%E%

E 4
I 4
#
D 9
# Copyright (c) 1980 Regents of the University of California.
E 9
I 9
D 17
# Copyright {c} 1987 Regents of the University of California.
E 9
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 17
I 17
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
E 17
#
D 9
#	%W% (Berkeley) %G%
E 9
I 9
D 17
#	%W%	{Berkeley}	%G%
E 17
I 17
# Redistribution and use in source and binary forms are permitted
D 18
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 17
E 9
#
I 17
#	%W% (Berkeley) %G%
#
E 17
E 4
I 2
D 9
DESTDIR=
E 2
D 7
CFLAGS= -O -DV7
E 7
I 7
CFLAGS= -O -DV7 -w
E 7
OBJS= allow.o board.o check.o extra.o fancy.o init.o main.o move.o\
E 9
I 9
LIBC=	/lib/libc.a
LIBS=	-ltermlib
D 17
CFLAGS=	-O -DV7 -w
E 17
I 17
CFLAGS=	-O -DV7
E 17
SRCS=	allow.c board.c check.c data.c extra.c fancy.c init.c main.c move.c \
	odds.c one.c save.c subs.c table.c teach.c text.c ttext1.c ttext2.c \
D 11
	tutor.c message.c
E 11
I 11
	tutor.c version.c
E 11
BSRCS=	allow.c board.c check.c extra.c fancy.c init.c main.c move.c \
D 11
	odds.c one.c save.c subs.c table.c text.c message.c
E 11
I 11
	odds.c one.c save.c subs.c table.c text.c version.c
E 11
BOBJS=	allow.o board.o check.o extra.o fancy.o init.o main.o move.o \
E 9
D 11
	odds.o one.o save.o subs.o table.o text.o message.o
E 11
I 11
	odds.o one.o save.o subs.o table.o text.o version.o
E 11
D 9
TOBJS= allow.o board.o check.o data.o fancy.o init.o odds.o one.o save.o subs.o\
	table.o teach.o ttext1.o ttext2.o tutor.o
SRCS= allow.c board.c check.c data.c extra.c fancy.c init.c main.c\
	move.c odds.c one.c save.c subs.c table.c teach.c text.c ttext1.c\
	ttext2.c tutor.c message.c
E 9
I 9
TSRCS=	allow.c board.c check.c data.c fancy.c init.c odds.c one.c save.c \
	subs.c table.c teach.c ttext1.c ttext2.c tutor.c
TOBJS=	allow.o board.o check.o data.o fancy.o init.o odds.o one.o save.o \
	subs.o table.o teach.o ttext1.o ttext2.o tutor.o
E 9
D 2
TARF=	bg.tar
E 2

D 16
all: backgammon teachgammon backgammon.doc
E 16
I 16
all: backgammon teachgammon
E 16

D 9
#	Backgammon program
backgammon: $(OBJS)
	-rm -f backgammon
	cc -o backgammon $(OBJS) -ltermlib
E 9
I 9
# Backgammon program
backgammon: ${BOBJS} ${LIBC}
	${CC} -o $@ ${BOBJS} ${LIBS}
E 9

D 9
#	Backgammon rules and tutorial
teachgammon: ${TOBJS}
	-rm -f teachgammon
	cc -o teachgammon $(TOBJS) -ltermlib
E 9
I 9
# Backgammon rules and tutorial
teachgammon: ${TOBJS} ${LIBC}
	${CC} -o $@ ${TOBJS} ${LIBS}
E 9

D 9
#	Header files back.h and tutor.h
allow.o board.o check.o extra.o fancy.o main.o move.o odds.o one.o save.o\
	subs.o table.o teach.o text.o ttext1.o ttext2.o: back.h
data.o tutor.o: back.h tutor.h

#	Update message.  /tmp is always changing, so use it to ensure execution
message.c: /tmp
E 9
I 9
D 11
# Update message.
message.c: FRC
E 9
D 10
	ex - message.c < Mesgfix
E 10
I 10
	-[ ! -w message.c ] || ex - message.c < Mesgfix
E 10

E 11
D 3
#	Save subroutine.  Uses "execl" which execl's itself to backgammon
save.c: execl
	ex - save.c < Savefix
execl: execl.c
	cc -O -o execl execl.c

E 3
D 9
#	Documentation
E 9
I 9
D 16
# Documentation
E 9
backgammon.doc: backgammon.src
D 9
	-rm -f backgammon.doc
E 9
	nroff -man -Tcrt backgammon.src > backgammon.doc

E 16
D 9
#	Installation
install:
D 2
	-chmod 711 backgammon teachgammon
	pubrm backgammon
	public backgammon
E 2
I 2
D 5
	install backgammon ${DESTDIR}/usr/games/backgammon
	install teachgammon ${DESTDIR}/usr/games/teachgammon
E 5
I 5
	install -s backgammon ${DESTDIR}/usr/games/backgammon
	install -s teachgammon ${DESTDIR}/usr/games/teachgammon
E 9
I 9
clean: FRC
D 15
	rm -f ${TOBJS} ${BOBJS} core teachgammon backgammmon backgammon.doc
E 15
I 15
D 16
	rm -f ${TOBJS} ${BOBJS} core teachgammon backgammon backgammon.doc
E 16
I 16
	rm -f ${TOBJS} ${BOBJS} core teachgammon backgammon
E 16
E 15
E 9
E 5
E 2

D 2
news:
	pubrm gammon.news
	public gammon.news

tar:
	tar crvf ${TARF} ${SRCS} back.h tutor.h makefile execl.c Mesgfix Savefix backgammon.src

E 2
I 2
D 9
clean:
D 5
	rm -f ${OBJS} ${TOBJS}
E 5
I 5
D 6
	rm -f ${OBJS} ${TOBJS} backgammon teachgammon
E 6
I 6
	rm -f ${OBJS} ${TOBJS} backgammon teachgammon backgammon.doc errs
E 9
I 9
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 9
I 8

D 9
depend:
E 9
I 9
install: FRC
D 14
	install -s -o bin -g bin -m 755 backgammon ${DESTDIR}/usr/games/backgammon
	install -s -o bin -g bin -m 755 teachgammon ${DESTDIR}/usr/games/teachgammon
E 14
I 14
	install -s -o games -g bin -m 700 backgammon ${DESTDIR}/usr/games/hide
	install -s -o games -g bin -m 700 teachgammon ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f backgammon; ln -s dm backgammon; chown games.bin backgammon)
	(cd ${DESTDIR}/usr/games; rm -f teachgammon; ln -s dm teachgammon; chown games.bin teachgammon)
E 14

lint: FRC
	lint ${CFLAGS} ${BRCS}
	lint ${CFLAGS} ${TSRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

allow.o: allow.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
allow.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
board.o: board.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
board.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
check.o: check.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
check.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
data.o: data.c tutor.h
extra.o: extra.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
extra.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
fancy.o: fancy.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
fancy.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
init.o: init.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
init.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
main.o: main.c /usr/include/stdio.h back.h /usr/include/sgtty.h
main.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
main.o: /usr/include/sys/ttydev.h
move.o: move.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
move.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
odds.o: odds.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
odds.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
one.o: one.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
one.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
save.o: save.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
save.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
subs.o: subs.c /usr/include/stdio.h back.h /usr/include/sgtty.h
subs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
subs.o: /usr/include/sys/ttydev.h
table.o: table.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
table.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
teach.o: teach.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
teach.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
text.o: text.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
text.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ttext1.o: ttext1.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ttext1.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ttext2.o: ttext2.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ttext2.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tutor.o: tutor.c back.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
tutor.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h tutor.h
D 11
message.o: message.c
E 11
I 11
version.o: version.c
E 11

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 8
E 6
E 5
E 2
E 1
