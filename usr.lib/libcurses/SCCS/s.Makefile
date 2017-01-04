h48513
s 00010/00005/00185
d D 5.4 88/06/30 17:21:07 bostic 26 25
c install approved copyright notice
e
s 00014/00012/00176
d D 5.3 88/06/08 14:37:17 bostic 25 24
c add Berkeley specific header; minor cleanups
e
s 00158/00043/00030
d D 5.2 87/06/24 14:17:18 minshall 24 23
c Add 'addbytes.c', plus some cleanup by K. Bostic in Makefile.
e
s 00005/00000/00068
d D 5.1 85/06/07 11:47:19 dist 23 22
c Add copyright
e
s 00009/00001/00059
d D 1.19 85/05/30 22:49:43 sam 22 21
c add tags
e
s 00025/00018/00035
d D 1.18 85/05/01 17:44:35 bloom 21 20
c new version from arnold
e
s 00031/00088/00022
d D 1.17 83/07/02 23:09:08 root 20 19
c major reorg
e
s 00004/00008/00106
d D 1.16 83/07/02 22:00:02 sam 19 18
c no more unctrl.h
e
s 00004/00004/00110
d D 1.15 83/06/21 19:19:00 mckusick 18 17
c use rm -f consistently
e
s 00002/00002/00112
d D 1.14 83/06/21 14:30:04 arnold 17 16
c 
e
s 00016/00002/00098
d D 1.13 83/05/12 13:23:18 arnold 16 15
c make install should install headers and lint files, too
e
s 00007/00001/00093
d D 1.12 83/05/09 20:31:43 arnold 15 14
c 
e
s 00002/00044/00092
d D 1.11 83/03/27 15:08:29 arnold 14 10
c 
e
s 00000/00042/00094
d R 1.11 82/02/17 14:12:26 arnold 13 10
c adopt latest version of fgoto() and plod() from vi
e
s 00003/00000/00094
d R 1.12 81/10/26 00:41:10 arnold 12 11
c add default for SCCS
e
s 00000/00042/00094
d R 1.11 81/10/26 00:36:17 root 11 10
c delete references to SCCS
e
s 00003/00003/00133
d D 1.10 81/04/17 15:39:50 arnold 10 9
c handle curses.ext properly
e
s 00004/00003/00132
d D 1.9 81/04/17 00:42:04 arnold 9 8
c add delch.c
e
s 00006/00003/00129
d D 1.8 81/04/17 00:27:51 arnold 8 7
c add insch
e
s 00007/00003/00125
d D 1.7 81/03/06 00:16:05 arnold 7 6
c add tstp.c
e
s 00002/00001/00126
d D 1.6 81/03/05 20:01:29 arnold 6 5
c make lpass1 a variable, since it sometimes lives in different places
e
s 00001/00001/00126
d D 1.5 81/02/17 19:28:15 arnold 5 4
c 
e
s 00003/00001/00124
d D 1.4 81/02/17 19:27:13 arnold 4 3
c 
e
s 00002/00004/00123
d D 1.3 81/02/09 17:48:57 arnold 3 2
c 
e
s 00039/00000/00088
d D 1.2 81/01/26 17:34:18 arnold 2 1
c add sccs dependencies
e
s 00088/00000/00000
d D 1.1 81/01/26 17:03:56 arnold 1 0
c date and time created 81/01/26 17:03:56 by arnold
e
u
U
t
T
I 23
#
D 24
# Copyright (c) 1980 Regents of the University of California.
E 24
I 24
# Copyright (c) 1987 Regents of the University of California.
E 24
D 25
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 25
I 25
# All rights reserved.
E 25
#
E 23
I 19
D 21
#	%M%	%I%	%E%
E 21
I 21
D 24
#	%W% (Berkeley) %G%
E 24
I 24
D 25
#	%W%	(Berkeley)	%G%
E 25
I 25
# Redistribution and use in source and binary forms are permitted
D 26
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 26
I 26
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
E 26
E 25
E 24
E 21
E 19
I 1
#
I 25
#	%W% (Berkeley) %G%
#
E 25
D 20
# cursor package maker
E 20
I 20
D 24
# curses package
E 20
#
D 19
# %W% (Berkeley) %G%
#
D 10
HEADERS=curses.h unctrl.h cr_ex.h
E 10
I 10
D 14
HEADERS=curses.h unctrl.h cr_ex.h curses.ext
E 14
I 14
HEADERS=curses.h unctrl.h curses.ext
E 19
I 19
D 20
HEADERS=curses.h curses.ext
E 20
E 19
E 14
E 10
D 21
CFILES=	box.c clear.c initscr.c endwin.c mvprintw.c mvscanw.c mvwin.c \
	newwin.c overlay.c overwrite.c printw.c scanw.c refresh.c \
	touchwin.c erase.c clrtobot.c clrtoeol.c cr_put.c cr_tty.c \
	longname.c delwin.c insertln.c deleteln.c scroll.c getstr.c \
D 7
	getch.c addstr.c addch.c move.c curses.c unctrl.c standout.c
E 7
I 7
	getch.c addstr.c addch.c move.c curses.c unctrl.c standout.c \
D 8
	tstp.c
E 8
I 8
D 9
	tstp.c insch.c
E 9
I 9
	tstp.c insch.c delch.c
E 21
I 21
CFILES=	addch.c addstr.c box.c clear.c clrtobot.c clrtoeol.c cr_put.c \
	cr_tty.c curses.c delch.c deleteln.c delwin.c endwin.c erase.c \
	fullname.c getch.c getstr.c idlok.c id_subwins.c initscr.c insch.c \
	insertln.c longname.c move.c mvprintw.c mvscanw.c mvwin.c newwin.c \
	overlay.c overwrite.c printw.c putchar.c refresh.c scanw.c scroll.c \
	toucholap.c standout.c touchwin.c tstp.c unctrl.c
E 21
E 9
E 8
E 7
D 20

OBJS=	box.o clear.o initscr.o endwin.o mvprintw.o mvscanw.o mvwin.o \
	newwin.o overlay.o overwrite.o printw.o scanw.o refresh.o \
	touchwin.o erase.o clrtobot.o clrtoeol.o cr_put.o cr_tty.o \
	longname.o delwin.o insertln.o deleteln.o scroll.o getstr.o \
D 7
	getch.o addstr.o addch.o move.o curses.o unctrl.o standout.o
E 7
I 7
	getch.o addstr.o addch.o move.o curses.o unctrl.o standout.o \
D 8
	tstp.o
E 8
I 8
D 9
	tstp.o insch.o
E 9
I 9
	tstp.o insch.o delch.o
E 9
E 8
E 7

POBJS=	box.p clear.p initscr.p endwin.p mvprintw.p mvscanw.p mvwin.p \
	newwin.p overlay.p overwrite.p printw.p scanw.p refresh.p \
	touchwin.p erase.p clrtobot.p clrtoeol.p cr_put.p cr_tty.p \
	longname.p delwin.p insertln.p deleteln.p scroll.p getstr.p \
D 7
	getch.p addstr.p addch.p move.p curses.p unctrl.p standout.p
E 7
I 7
	getch.p addstr.p addch.p move.p curses.p unctrl.p standout.p \
D 8
	tstp.p
E 8
I 8
D 9
	tstp.p insch.p
E 9
I 9
	tstp.p insch.p delch.p
E 9
E 8
E 7

E 20
I 20
OBJS=	addch.o addstr.o box.o clear.o clrtobot.o clrtoeol.o cr_put.o \
	cr_tty.o curses.o delch.o deleteln.o delwin.o endwin.o erase.o \
D 21
	getch.o getstr.o initscr.o insch.o insertln.o longname.o move.o \
	mvprintw.o mvscanw.o mvwin.o newwin.o overlay.o overwrite.o \
	printw.o refresh.o scanw.o scroll.o standout.o touchwin.o tstp.o \
	unctrl.o
E 21
I 21
	fullname.o getch.o getstr.o idlok.o id_subwins.o initscr.o insch.o \
	insertln.o longname.o move.o mvprintw.o mvscanw.o mvwin.o newwin.o \
	overlay.o overwrite.o printw.o putchar.o refresh.o scanw.o scroll.o \
	toucholap.o standout.o touchwin.o tstp.o unctrl.o
E 24
I 24
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	addbytes.c addch.c addstr.c box.c clear.c clrtobot.c clrtoeol.c \
	cr_put.c cr_tty.c curses.c delch.c deleteln.c delwin.c endwin.c \
	erase.c fullname.c getch.c getstr.c idlok.c id_subwins.c initscr.c \
	insch.c insertln.c longname.c move.c mvprintw.c mvscanw.c mvwin.c \
	newwin.c overlay.c overwrite.c printw.c putchar.c refresh.c scanw.c \
	scroll.c toucholap.c standout.c touchwin.c tstp.c unctrl.c
OBJS=	addbytes.o addch.o addstr.o box.o clear.o clrtobot.o clrtoeol.o \
	cr_put.o cr_tty.o curses.o delch.o deleteln.o delwin.o endwin.o \
	erase.o fullname.o getch.o getstr.o idlok.o id_subwins.o initscr.o \
	insch.o insertln.o longname.o move.o mvprintw.o mvscanw.o mvwin.o \
	newwin.o overlay.o overwrite.o printw.o putchar.o refresh.o scanw.o \
	scroll.o toucholap.o standout.o touchwin.o tstp.o unctrl.o
E 24

E 21
E 20
D 16

E 16
D 24
CTAGS=	ctags
D 20
CC=	cc
LINT=	lint
I 6
LPASS1=	/usr/lib/lint/lint1
E 6
AR=	ar
D 18
RM=	rm
E 18
I 18
RM=	rm -f
E 18
LN=	ln
CFL=	
CFLAGS=	-O ${CFL}
I 3
LDFLAGS=-n
I 16
INSTALL=${DESTDIR}/usr/lib/libcurses.a ${DESTDIR}/usr/include/curses.h \
D 19
	${DESTDIR}/usr/include/unctrl.h ${DESTDIR}/usr/lib/lint/llib-lcurses.ln
E 19
I 19
	${DESTDIR}/usr/lib/lint/llib-lcurses.ln
E 20
I 20
D 21
CFLAGS=	-O
E 21
I 21
DEFS=
CFLAGS=	-O $(DEFS)
I 22
TAGSFILE=tags
E 22
E 21
E 20
E 19

E 24
E 16
E 3
D 20
.SUFFIXES: .p
E 20
I 20
.c.o:
D 21
	${CC} -c -p ${CFLAGS} $*.c
E 21
I 21
D 25
	${CC} -c -pg ${CFLAGS} $*.c
E 21
	ld -x -r $*.o
	mv a.out profiled/$*.o
	${CC} -c ${CFLAGS} $*.c
	ld -x -r $*.o
	mv a.out $*.o
E 25
I 25
	@${CC} -c -pg ${CFLAGS} $*.c
	@ld -x -o profiled/$*.o -r $*.o
	${CC} ${CFLAGS} -c $*.c
	@ld -x -r $*.o
	@mv a.out $*.o
E 25
E 20

I 24
all: libcurses libcurses_p

E 24
D 20
.c.p:
I 4
D 18
	rm -f x.c
E 18
I 18
	${RM} x.c
E 18
E 4
	ln $*.c x.c
	${CC} ${CFLAGS} -p -c x.c
D 4
	mv x.o $*.p ; rm x.c
E 4
I 4
	mv x.o $*.p
E 20
I 20
libcurses libcurses_p: ${OBJS}
	@echo building profiled libcurses
D 21
	@cd profiled; ar cr ../libcurses_p ${OBJS}
E 21
I 21
	@cd profiled; ar cu ../libcurses_p ${OBJS}
	ranlib libcurses_p
E 21
	@echo building normal libcurses
D 21
	@ar cr libcurses ${OBJS}
E 21
I 21
	@ar cu libcurses ${OBJS}
	ranlib libcurses
E 21
E 20
E 4
D 25

I 15
D 20
.DEFAULT:
	sccs get $@
E 20
I 20
D 24
install: libcurses libcurses_p
	install -m 644 libcurses ${DESTDIR}/usr/lib/libcurses.a
E 24
I 24
test: libcurses test.o
	${CC} ${CFLAGS} -o $@ test.o libcurses -ltermlib
E 25

clean: FRC
	rm -f ${OBJS} profiled/*.o libcurses libcurses_p

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -o bin -g bin -m 644 libcurses ${DESTDIR}/usr/lib/libcurses.a
E 24
	ranlib ${DESTDIR}/usr/lib/libcurses.a
D 24
	install -m 644 libcurses_p ${DESTDIR}/usr/lib/libcurses_p.a
E 24
I 24
	install -o bin -g bin -m 644 libcurses_p ${DESTDIR}/usr/lib/libcurses_p.a
E 24
	ranlib ${DESTDIR}/usr/lib/libcurses_p.a
E 20

I 22
D 24
tags:
	cwd=`pwd`; \
	for i in ${CFILES}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done
E 24
I 24
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 24

E 22
E 15
I 2
D 20
libcurses: ${HEADERS} crlib

E 2
crlib: ${OBJS}
	${AR} rv crlib $?
	ranlib crlib

pcrlib: ${POBJS}
I 4
D 18
	rm -f x.c
E 18
I 18
	${RM} x.c
E 18
E 4
D 5
	${AR} ruv pcrlib ${POBJS}
E 5
I 5
	${AR} rv pcrlib $?
E 5
	ranlib pcrlib

D 17
test:	crlib test.o
D 3
	${CC} ${CFLAGS} -o test test.o crlib -ltermlib

a.out:	crlib cat.o
	${CC} ${CFLAGS} cat.o crlib -ltermlib
E 3
I 3
D 15
	${CC} ${LDFLAGS} ${CFLAGS} -o test test.o crlib -ltermlib
E 15
I 15
	${CC} ${LDFLAGS} ${CFLAGS} -o test test.o -lcurses -ltermlib
E 17
I 17
test:	libcurses test.o
	${CC} ${LDFLAGS} ${CFLAGS} -o test test.o crlib -ltermlib
E 17
E 15
E 3

cat.o:	curses.h
	${CC} -c ${CFLAGS} cat.c

new:	cleanup ctags
	${CC} -c ${CFLAGS} ${CFILES}
	${AR} qv crlib ${OBJS}
	${RM} /ya/staff/arnold/=eye/crlib /ya/staff/arnold/=hacks/crlib \
	      /ya/staff/arnold/=eye/curses.h /ya/staff/arnold/=hacks/curses.h

E 20
D 24
clean:
D 18
	rm ${OBJS} crlib
E 18
I 18
D 20
	${RM} ${OBJS} crlib
E 20
I 20
D 22
	rm -f ${OBJS} profiled/*.o a.out core test errs libcurses libcurses_p
E 22
I 22
	rm -f ${OBJS} profiled/*.o a.out core test errs \
	    libcurses libcurses_p tags
E 24
I 24
tags: FRC
	ctags ${SRCS}
E 24
E 22
E 20
E 18

D 24
ctags:
D 14
	${CTAGS} ${CFILES} curses.h cr_ex.h
E 14
I 14
	${CTAGS} ${CFILES} curses.h
E 24
I 24
FRC:
E 24
E 14

D 24
lint:
D 20
	${LINT} -hxb ${CFL} ${CFILES} -lcurses > lint.out
E 20
I 20
	lint -hxb ${CFILES} -lcurses > lint.out
E 24
I 24
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 24
E 20

D 20
lpr:
	-pr curses.h ${CFILES} | lpr
	-lpq
E 20
I 20
D 24
test:	libcurses test.o
D 21
	${CC} ${LDFLAGS} ${CFLAGS} -o test test.o crlib -ltermlib
E 21
I 21
	${CC} ${LDFLAGS} ${CFLAGS} -o test test.o libcurses -ltermlib
E 24
I 24
addbytes.o: addbytes.c curses.ext curses.h /usr/include/stdio.h
addbytes.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
addbytes.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
addch.o: addch.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
addch.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
addch.o: /usr/include/sys/ttydev.h
addstr.o: addstr.c curses.ext curses.h /usr/include/stdio.h
addstr.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
addstr.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
box.o: box.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
box.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
box.o: /usr/include/sys/ttydev.h
clear.o: clear.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
clear.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
clear.o: /usr/include/sys/ttydev.h
clrtobot.o: clrtobot.c curses.ext curses.h /usr/include/stdio.h
clrtobot.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
clrtobot.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
clrtoeol.o: clrtoeol.c curses.ext curses.h /usr/include/stdio.h
clrtoeol.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
clrtoeol.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cr_put.o: cr_put.c curses.ext curses.h /usr/include/stdio.h
cr_put.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
cr_put.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cr_tty.o: cr_tty.c curses.ext curses.h /usr/include/stdio.h
cr_tty.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
cr_tty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
curses.o: curses.c curses.h /usr/include/stdio.h /usr/include/sgtty.h
curses.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
curses.o: /usr/include/sys/ttydev.h
delch.o: delch.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
delch.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
delch.o: /usr/include/sys/ttydev.h
deleteln.o: deleteln.c curses.ext curses.h /usr/include/stdio.h
deleteln.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
deleteln.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
delwin.o: delwin.c curses.ext curses.h /usr/include/stdio.h
delwin.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
delwin.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
endwin.o: endwin.c curses.ext curses.h /usr/include/stdio.h
endwin.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
endwin.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
erase.o: erase.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
erase.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
erase.o: /usr/include/sys/ttydev.h
fullname.o: fullname.c
getch.o: getch.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
getch.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
getch.o: /usr/include/sys/ttydev.h
getstr.o: getstr.c curses.ext curses.h /usr/include/stdio.h
getstr.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
getstr.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
idlok.o: idlok.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
idlok.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
idlok.o: /usr/include/sys/ttydev.h
id_subwins.o: id_subwins.c curses.ext curses.h /usr/include/stdio.h
id_subwins.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
id_subwins.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
initscr.o: initscr.c curses.ext curses.h /usr/include/stdio.h
initscr.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
initscr.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
initscr.o: /usr/include/signal.h
insch.o: insch.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
insch.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
insch.o: /usr/include/sys/ttydev.h
insertln.o: insertln.c curses.ext curses.h /usr/include/stdio.h
insertln.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
insertln.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
longname.o: longname.c
move.o: move.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
move.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
move.o: /usr/include/sys/ttydev.h
mvprintw.o: mvprintw.c curses.ext curses.h /usr/include/stdio.h
mvprintw.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
mvprintw.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
mvscanw.o: mvscanw.c curses.ext curses.h /usr/include/stdio.h
mvscanw.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
mvscanw.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
mvwin.o: mvwin.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
mvwin.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
mvwin.o: /usr/include/sys/ttydev.h
newwin.o: newwin.c curses.ext curses.h /usr/include/stdio.h
newwin.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
newwin.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
overlay.o: overlay.c curses.ext curses.h /usr/include/stdio.h
overlay.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
overlay.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
overlay.o: /usr/include/ctype.h
overwrite.o: overwrite.c curses.ext curses.h /usr/include/stdio.h
overwrite.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
overwrite.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
overwrite.o: /usr/include/ctype.h
printw.o: printw.c curses.ext curses.h /usr/include/stdio.h
printw.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
printw.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
putchar.o: putchar.c curses.ext curses.h /usr/include/stdio.h
putchar.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
putchar.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
refresh.o: refresh.c curses.ext curses.h /usr/include/stdio.h
refresh.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
refresh.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
scanw.o: scanw.c curses.ext curses.h /usr/include/stdio.h /usr/include/sgtty.h
scanw.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
scanw.o: /usr/include/sys/ttydev.h
scroll.o: scroll.c curses.ext curses.h /usr/include/stdio.h
scroll.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
scroll.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
toucholap.o: toucholap.c curses.ext curses.h /usr/include/stdio.h
toucholap.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
toucholap.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
standout.o: standout.c curses.ext curses.h /usr/include/stdio.h
standout.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
standout.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
touchwin.o: touchwin.c curses.ext curses.h /usr/include/stdio.h
touchwin.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
touchwin.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tstp.o: tstp.c /usr/include/signal.h curses.ext curses.h /usr/include/stdio.h
tstp.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
tstp.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
unctrl.o: unctrl.c
E 24
E 21
E 20

D 20
tp:
D 10
	tp crm0 Makefile tags ${HEADERS} curses.ext ${CFILES} llib-lcurses
E 10
I 10
	tp crm0 Makefile tags ${HEADERS} ${CFILES} llib-lcurses
E 10

tar:
D 10
	tar crvf curses.tar Makefile tags ${HEADERS} curses.ext ${CFILES} llib-lcurses
E 10
I 10
	tar crvf curses.tar Makefile tags ${HEADERS} ${CFILES} llib-lcurses
I 15

ar:
	ar crv curses.ar Makefile tags ${HEADERS} ${CFILES} llib-lcurses
E 15
E 10

llib-lcurses.ln: llib-lcurses
D 6
	-(/lib/cpp -C -Dlint llib-lcurses | /usr/lib/lpass1 > llib-lcurses.ln ) 2>&1 | grep -v warning
E 6
I 6
	-(/lib/cpp -C -Dlint llib-lcurses | ${LPASS1} > llib-lcurses.ln ) 2>&1 | grep -v warning
E 6

D 16
install:
E 16
I 16
install: ${INSTALL}

${DESTDIR}/usr/lib/libcurses.a: crlib
E 16
D 19
	install -c crlib ${DESTDIR}/usr/lib/libcurses.a
E 19
I 19
	install -m 644 crlib ${DESTDIR}/usr/lib/libcurses.a
E 19
	ranlib ${DESTDIR}/usr/lib/libcurses.a
I 16

${DESTDIR}/usr/include/curses.h: curses.h
	install -c curses.h ${DESTDIR}/usr/include/
D 19

${DESTDIR}/usr/include/unctrl.h: unctrl.h
	install -c unctrl.h ${DESTDIR}/usr/include/
E 19

${DESTDIR}/usr/lib/lint/llib-lcurses.ln: llib-lcurses.ln
	install -c llib-lcurses ${DESTDIR}/usr/lib/lint
	install -c llib-lcurses.ln ${DESTDIR}/usr/lib/lint
E 20
I 20
D 21
cat.o:	curses.h
	${CC} -c ${CFLAGS} cat.c
E 21
I 21
D 24
test.o:	test.c
	${CC} ${CFLAGS} -c test.c

ar:
	ar crv curses.ar ${CFILES} curses.h curses.ext Makefile
E 24
I 24
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 24
E 21
E 20
E 16
I 2
D 14

I 8
source: ${HEADERS} ${CFILES}

E 8
addch.c: SCCS/s.addch.c ; sccs get addch.c
addstr.c: SCCS/s.addstr.c ; sccs get addstr.c
box.c: SCCS/s.box.c ; sccs get box.c
clear.c: SCCS/s.clear.c ; sccs get clear.c
clrtobot.c: SCCS/s.clrtobot.c ; sccs get clrtobot.c
clrtoeol.c: SCCS/s.clrtoeol.c ; sccs get clrtoeol.c
cr_ex.h: SCCS/s.cr_ex.h ; sccs get cr_ex.h
cr_put.c: SCCS/s.cr_put.c ; sccs get cr_put.c
cr_tty.c: SCCS/s.cr_tty.c ; sccs get cr_tty.c
curses.c: SCCS/s.curses.c ; sccs get curses.c
curses.h: SCCS/s.curses.h ; sccs get curses.h
I 9
delch.c: SCCS/s.delch.c ; sccs get delch.c
E 9
deleteln.c: SCCS/s.deleteln.c ; sccs get deleteln.c
delwin.c: SCCS/s.delwin.c ; sccs get delwin.c
endwin.c: SCCS/s.endwin.c ; sccs get endwin.c
erase.c: SCCS/s.erase.c ; sccs get erase.c
getch.c: SCCS/s.getch.c ; sccs get getch.c
getstr.c: SCCS/s.getstr.c ; sccs get getstr.c
initscr.c: SCCS/s.initscr.c ; sccs get initscr.c
I 8
insch.c: SCCS/s.insch.c ; sccs get insch.c
E 8
insertln.c: SCCS/s.insertln.c ; sccs get insertln.c
llib-lcurses: SCCS/s.llib-lcurses ; sccs get llib-lcurses
longname.c: SCCS/s.longname.c ; sccs get longname.c
move.c: SCCS/s.move.c ; sccs get move.c
mvprintw.c: SCCS/s.mvprintw.c ; sccs get mvprintw.c
mvscanw.c: SCCS/s.mvscanw.c ; sccs get mvscanw.c
mvwin.c: SCCS/s.mvwin.c ; sccs get mvwin.c
newwin.c: SCCS/s.newwin.c ; sccs get newwin.c
overlay.c: SCCS/s.overlay.c ; sccs get overlay.c
overwrite.c: SCCS/s.overwrite.c ; sccs get overwrite.c
printw.c: SCCS/s.printw.c ; sccs get printw.c
refresh.c: SCCS/s.refresh.c ; sccs get refresh.c
scanw.c: SCCS/s.scanw.c ; sccs get scanw.c
scroll.c: SCCS/s.scroll.c ; sccs get scroll.c
standout.c: SCCS/s.standout.c ; sccs get standout.c
touchwin.c: SCCS/s.touchwin.c ; sccs get touchwin.c
I 7
tstp.c: SCCS/s.tstp.c ; sccs get tstp.c
E 7
unctrl.c: SCCS/s.unctrl.c ; sccs get unctrl.c
unctrl.h: SCCS/s.unctrl.h ; sccs get unctrl.h
E 14
E 2
E 1
