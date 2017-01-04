h03344
s 00010/00005/00120
d D 5.7 88/06/18 19:38:15 bostic 9 8
c install approved copyright notice
e
s 00075/00045/00050
d D 5.6 88/04/18 09:38:13 bostic 8 7
c add Berkeley specific header
e
s 00004/00004/00091
d D 5.5 87/10/22 12:04:08 bostic 7 6
c fix make clean
e
s 00002/00001/00093
d D 5.4 87/09/21 11:52:06 bostic 6 4
c integrate with dm
e
s 00004/00001/00093
d R 5.4 87/09/20 10:20:40 bostic 5 4
c integrate with dm
e
s 00075/00063/00019
d D 5.3 87/06/03 17:09:35 bostic 4 2
c new template
e
s 00075/00063/00019
d R 5.3 87/06/03 16:18:27 bostic 3 2
c new template
e
s 00002/00000/00080
d D 5.2 87/05/31 21:00:23 bostic 2 1
c added depend label
e
s 00080/00000/00000
d D 5.1 86/11/26 13:39:41 bostic 1 0
c date and time created 86/11/26 13:39:41 by bostic
e
u
U
t
T
I 1
#
D 4
# Copyright (c) 1982 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
D 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 8
I 8
# All rights reserved.
E 8
#
D 4
#	@(#)Makefile	5.1 (Berkeley) 5/15/86
E 4
I 4
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
E 8
E 4
#
I 8
#	%W% (Berkeley) %G%
#
E 8
D 4
# mille bourne game makefile
#
HEADERS=mille.h
CFILES=	comp.c end.c extern.c init.c mille.c misc.c move.c print.c \
E 4
I 4
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBS=	-lcurses -ltermlib
SRCS=	comp.c end.c extern.c init.c mille.c misc.c move.c print.c \
	roll.c save.c table.c types.c varpush.c
MSRCS=	comp.c end.c extern.c init.c mille.c misc.c move.c print.c \
E 4
	roll.c save.c types.c varpush.c
D 4
OBJS=	comp.o end.o extern.o init.o mille.o misc.o move.o print.o \
E 4
I 4
MOBJS=	comp.o end.o extern.o init.o mille.o misc.o move.o print.o \
E 4
	roll.o save.o types.o varpush.o
D 4
POBJS=	comp.po end.po extern.po init.po mille.po misc.po move.po \
	roll.po print.po save.po types.po varpush.po
# CRL=	/jb/ingres/arnold/=lib/=curses/crlib
# CRL=	=curses/screen/libcurses.a
CRL=	
# L=	-ltermlib
L=	-lcurses -ltermlib
LIBS=	${CRL} ${L}
DEFS=
CFLAGS=	-O ${DEFS}
LDFLAGS=
DESTDIR=
BINDIR=	/usr/games
.SUFFIXES: .po .i
E 4
I 4
TSRCS=	table.c extern.c
TOBJS=	table.o extern.o
E 4

D 4
.c.po:
	rm -f x.c ; ln $*.c x.c
	${CC} ${CFLAGS} -p -c x.c
	mv x.o $*.po
E 4
I 4
all: mille
E 4

D 4
.c.i:
	${CC} ${LDFLAGS} -P $*.c
E 4
I 4
mille: ${MOBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${MOBJS} ${LIBS}
E 4

D 4
a.out: ${OBJS} ${CRL}
	${CC} ${LDFLAGS} ${OBJS} ${LIBS}
E 4
I 4
table: ${TOBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${TOBJS}
E 4

D 4
mille: ${OBJS} ${CRL}
	${CC} ${CFLAGS} -o mille ${OBJS} ${LIBS}
E 4
I 4
clean: FRC
D 7
	rm -f ${OBJS} ${TOBJS} core mille table
E 7
I 7
	rm -f ${OBJS} ${TOBJS} ${MOBJS} core mille table
E 7
E 4

D 4
install: mille
	install -s mille ${DESTDIR}${BINDIR}
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 4

D 4
pmb: ${POBJS} ../pcrlib
	${CC} ${CFLAGS} -p -o pmb ${POBJS} ../pcrlib -ltermlib
E 4
I 4
install: FRC
D 6
	install -s -o bin -g bin -m 755 mille ${DESTDIR}/usr/games/mille
E 6
I 6
	install -s -o games -g bin -m 700 mille ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f mille; ln -s dm mille; chown games.bin mille)
E 6
E 4

D 4
mille.po: mille.c
	rm -f x.c ; ln mille.c x.c
	${CC} ${CFLAGS} -DPROF -p -c x.c
	mv x.o mille.po
E 4
I 4
lint: FRC
D 7
	lint ${CFLAGS} ${SRCS}
E 7
I 7
	lint ${CFLAGS} ${MSRCS}
E 7
	lint ${CFLAGS} ${TSRCS}
E 4

D 4
table: table.o extern.o
	${CC} ${CFLAGS} -i -o table table.o extern.o
E 4
I 4
tags: FRC
D 7
	ctags ${SRCS}
E 7
I 7
	ctags ${MSRCS}
E 7
	ctags -a ${TSRCS}
	sort -o tags tags
E 4

D 4
readdump: readdump.o extern.o varpush.o
	${CC} ${CFLAGS} -i -o readdump readdump.o extern.o varpush.o
E 4
I 4
FRC:
E 4

D 4
ctags:
	ctags ${HEADERS} ${CFILES}
	ed - tags < :ctfix
	sort tags -o tags
E 4
I 4
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 4

D 4
lint:
	lint -hxb ${DEFS} ${CFILES} ${L} > lint.out
E 4
I 4
D 8
comp.o: comp.c mille.h /usr/include/ctype.h /usr/include/curses.h
comp.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
comp.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
end.o: end.c mille.h /usr/include/ctype.h /usr/include/curses.h
end.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
end.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
extern.o: extern.c mille.h /usr/include/ctype.h /usr/include/curses.h
extern.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
extern.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
init.o: init.c mille.h /usr/include/ctype.h /usr/include/curses.h
init.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
init.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
mille.o: mille.c mille.h /usr/include/ctype.h /usr/include/curses.h
mille.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
mille.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 7
mille.o: /usr/include/signal.h
E 7
I 7
mille.o: /usr/include/signal.h /usr/include/machine/trap.h
E 7
misc.o: misc.c mille.h /usr/include/ctype.h /usr/include/curses.h
misc.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
misc.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
misc.o: /usr/include/sys/file.h
move.o: move.c mille.h /usr/include/ctype.h /usr/include/curses.h
move.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
move.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
print.o: print.c mille.h /usr/include/ctype.h /usr/include/curses.h
print.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
print.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
roll.o: roll.c mille.h /usr/include/ctype.h /usr/include/curses.h
roll.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
roll.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
save.o: save.c mille.h /usr/include/ctype.h /usr/include/curses.h
save.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
save.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
save.o: /usr/include/sys/types.h /usr/include/sys/stat.h
table.o: table.c mille.h /usr/include/ctype.h /usr/include/curses.h
table.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
table.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
types.o: types.c mille.h /usr/include/ctype.h /usr/include/curses.h
types.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
types.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
varpush.o: varpush.c mille.h /usr/include/ctype.h /usr/include/curses.h
varpush.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
varpush.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 8
I 8
comp.o: comp.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
comp.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
comp.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
comp.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
comp.o: /usr/include/strings.h
end.o: end.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
end.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
end.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
end.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
end.o: /usr/include/strings.h
extern.o: extern.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
extern.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
extern.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
extern.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
extern.o: /usr/include/strings.h
init.o: init.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
init.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
init.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
init.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
init.o: /usr/include/strings.h
mille.o: mille.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
mille.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
mille.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
mille.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
mille.o: /usr/include/strings.h /usr/include/signal.h
mille.o: /usr/include/machine/trap.h
misc.o: misc.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
misc.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
misc.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
misc.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
misc.o: /usr/include/strings.h /usr/include/sys/file.h
move.o: move.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
move.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
move.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
move.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
move.o: /usr/include/strings.h
print.o: print.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
print.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
print.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
print.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
print.o: /usr/include/strings.h
roll.o: roll.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
roll.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
roll.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
roll.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
roll.o: /usr/include/strings.h
save.o: save.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
save.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
save.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
save.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
save.o: /usr/include/strings.h /usr/include/sys/types.h /usr/include/sys/stat.h
table.o: table.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
table.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
table.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
table.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
table.o: /usr/include/strings.h
types.o: types.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
types.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
types.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
types.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
types.o: /usr/include/strings.h
varpush.o: varpush.c mille.h /usr/include/sys/types.h /usr/include/ctype.h
varpush.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
varpush.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
varpush.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
varpush.o: /usr/include/strings.h
E 8
E 4

D 4
mille.ar:
	ar ruv mille.ar Makefile tags ${HEADERS} ${CFILES}

tar:
	tar rvf /dev/rmt0 Makefile tags :ctfix ${HEADERS} ${CFILES}

lpr:
	pr Makefile ${HEADERS} ${CFILES} tags | lpr ; lpq

clean:
	rm -f ${OBJS} ${POBJS} core ? a.out errs mille lint.out mille.ar \
		tags pmb
I 2

depend:
E 4
I 4
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 2
E 1
