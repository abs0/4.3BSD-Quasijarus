h52909
s 00010/00005/00089
d D 5.7 88/06/18 20:04:35 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00085
d D 5.6 88/03/09 11:18:32 bostic 8 7
c Written by Ken Arnold; add Berkeley specific copyright
e
s 00003/00002/00085
d D 5.5 87/09/21 11:55:50 bostic 7 5
c integrate with dm
e
s 00005/00002/00085
d R 5.5 87/09/20 10:44:54 bostic 6 5
c integrate with dm
e
s 00077/00022/00010
d D 5.4 87/06/05 16:16:28 bostic 5 3
c new template
e
s 00078/00022/00010
d R 5.4 87/06/03 16:52:42 bostic 4 3
c new template
e
s 00002/00000/00030
d D 5.3 87/05/31 21:01:15 bostic 3 2
c added depend label
e
s 00004/00003/00026
d D 5.2 86/05/15 07:03:33 lepreau 2 1
c DESTDIR
e
s 00029/00000/00000
d D 5.1 85/05/30 18:36:48 mckusick 1 0
c date and time created 85/05/30 18:36:48 by mckusick
e
u
U
t
T
I 1
#
D 5
# Copyright (c) 1980 Regents of the University of California.
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
I 2
D 5
DESTDIR=
E 2
HDRS=		robot.h
CFILES=		extern.c init_field.c main.c make_level.c move.c \
		move_robs.c play_level.c query.c rnd_pos.c score.c \
		flush_in.c
OBJS=		extern.o init_field.o main.o make_level.o move.o \
		move_robs.o play_level.o query.o rnd_pos.o score.o \
		flush_in.o
DEFS=		-DMAX_PER_UID=5
CFLAGS=		-O ${DEFS}
E 5
I 5
DEFS=	-DMAX_PER_UID=5
CFLAGS=	-O ${DEFS}
LIBC=	/lib/libc.a
LIBS=	-lcurses -ltermlib
SRCS=	extern.c init_field.c main.c make_level.c move.c move_robs.c \
	play_level.c query.c rnd_pos.c score.c flush_in.c
OBJS=	extern.o init_field.o main.o make_level.o move.o move_robs.o \
	play_level.o query.o rnd_pos.o score.o flush_in.o
E 5

D 5
robots: ${OBJS}
	${CC} ${CFLAGS} -o robots ${OBJS} -lcurses -ltermlib
E 5
I 5
all: robots
E 5

D 5
lint:
	lint -hb ${DEFS} ${CFILES} -lcurses 2>1 > lint.out
E 5
I 5
robots:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} ${LIBS}
E 5

D 5
install: robots
D 2
	install -c -s -m 4711 -o daemon robots /usr/games
	install -c -m 644 -o daemon /dev/null /usr/games/lib/robots_roll
E 2
I 2
	install -s -m 4711 -o daemon robots ${DESTDIR}/usr/games
	install -c -m 644 -o daemon /dev/null ${DESTDIR}/usr/games/lib/robots_roll
E 5
I 5
clean: FRC
	rm -f ${OBJS} core robots
E 5
E 2

D 5
clean:
D 2
	rm -f a.out core *.o robots
E 2
I 2
	rm -f a.out core *.o robots lint.out errs
E 5
I 5
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 5
I 3

D 5
depend:
E 5
I 5
install: FRC
D 7
	install -s -o daemon -g bin -m 4711 robots ${DESTDIR}/usr/games/robots
	install -c -o daemon -g bin -m 644 /dev/null ${DESTDIR}/usr/games/lib/robots_roll
E 7
I 7
	install -s -o games -g bin -m 4700 robots ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f robots; ln -s dm robots; chown games.bin robots)
	install -c -o games -g bin -m 600 /dev/null ${DESTDIR}/usr/games/lib/robots_roll
E 7

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

extern.o: extern.c robots.h /usr/include/curses.h /usr/include/stdio.h
extern.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
extern.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
extern.o: /usr/include/setjmp.h
init_field.o: init_field.c robots.h /usr/include/curses.h /usr/include/stdio.h
init_field.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
init_field.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
init_field.o: /usr/include/setjmp.h
main.o: main.c robots.h /usr/include/curses.h /usr/include/stdio.h
main.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
main.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/ctype.h
make_level.o: make_level.c robots.h /usr/include/curses.h /usr/include/stdio.h
make_level.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
make_level.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
make_level.o: /usr/include/setjmp.h
move.o: move.c robots.h /usr/include/curses.h /usr/include/stdio.h
move.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
move.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
move.o: /usr/include/setjmp.h /usr/include/ctype.h
move_robs.o: move_robs.c robots.h /usr/include/curses.h /usr/include/stdio.h
move_robs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
move_robs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
move_robs.o: /usr/include/setjmp.h /usr/include/signal.h
play_level.o: play_level.c robots.h /usr/include/curses.h /usr/include/stdio.h
play_level.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
play_level.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
play_level.o: /usr/include/setjmp.h
query.o: query.c robots.h /usr/include/curses.h /usr/include/stdio.h
query.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
query.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
query.o: /usr/include/setjmp.h
rnd_pos.o: rnd_pos.c robots.h /usr/include/curses.h /usr/include/stdio.h
rnd_pos.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
rnd_pos.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
rnd_pos.o: /usr/include/setjmp.h
score.o: score.c robots.h /usr/include/curses.h /usr/include/stdio.h
score.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
score.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
score.o: /usr/include/setjmp.h /usr/include/pwd.h
flush_in.o: flush_in.c /usr/include/curses.h /usr/include/stdio.h
flush_in.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
flush_in.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 3
E 2
E 1
