h37214
s 00012/00016/00043
d D 5.8 87/12/01 17:57:54 bostic 12 11
c cleanup; make clean lable work
e
s 00003/00002/00056
d D 5.7 87/09/21 11:28:44 bostic 11 9
c integrate with dm
e
s 00005/00002/00056
d R 5.7 87/09/19 14:19:12 bostic 10 9
c integrate with dm
e
s 00041/00016/00017
d D 5.6 87/06/05 16:15:13 bostic 9 7
c new template
e
s 00042/00016/00017
d R 5.6 87/06/03 12:15:29 bostic 8 7
c new template
e
s 00002/00000/00031
d D 5.5 87/05/31 20:58:27 bostic 7 6
c added depend label
e
s 00001/00001/00030
d D 5.4 87/04/03 11:15:18 karels 6 5
c use *this* comp
e
s 00001/00001/00030
d D 5.3 85/09/07 21:03:32 mckusick 5 4
c strip on install
e
s 00001/00001/00030
d D 5.2 85/06/23 15:24:49 mckusick 4 3
c missing conditional
e
s 00006/00001/00025
d D 5.1 85/05/30 19:41:57 mckusick 3 2
c Add copyright
e
s 00004/00001/00022
d D 4.2 85/05/27 19:16:23 mckusick 2 1
c do not depend on having /usr/local/lib/w2a
e
s 00023/00000/00000
d D 4.1 82/12/24 13:07:54 sam 1 0
c date and time created 82/12/24 13:07:54 by sam
e
u
U
t
T
I 1
D 3
#	%W%	%G%
E 3
I 3
#
D 9
# Copyright (c) 1980 Regents of the University of California.
E 9
I 9
# Copyright (c) 1987 Regents of the University of California.
E 9
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 9
#	%W% (Berkeley) %G%
E 9
I 9
#	%W%	(Berkeley)	%G%
E 9
E 3
#
D 9
DESTDIR=
CC = /bin/cc
CFLAGS = -O
E 9
I 9
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	comp.c boggle.c
D 12
CSRCS=	comp.c
COBJS=	comp.o
BSRCS=	boggle.c
BOBJS=	boggle.o
E 12
E 9

D 9
all:	boggle bogdict
E 9
I 9
all: boggle bogdict
E 9

bogdict: comp sfile
D 2
	sed -f sfile /usr/local/lib/w2a | uniq | comp >bogdict
E 2
I 2
D 4
	if [ -f /usr/local/lib/w2a ]; \
E 4
I 4
	-if [ -f /usr/local/lib/w2a ]; \
E 4
		then dict=/usr/local/lib/w2a; \
		else dict=/usr/dict/words; fi; \
D 6
	sed -f sfile $$dict | uniq | comp >bogdict
E 6
I 6
	sed -f sfile $$dict | uniq | ./comp >bogdict
E 6
E 2

D 9
install:
D 5
	install boggle ${DESTDIR}/usr/games/boggle
E 5
I 5
	install -s boggle ${DESTDIR}/usr/games/boggle
E 5
	install bogdict ${DESTDIR}/usr/games/bogdict
E 9
I 9
D 12
boggle:	${BOBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${BOBJS}
E 12
I 12
boggle: ${LIBC}
	${CC} -o $@ ${CFLAGS} $@.c
E 12
E 9

D 9
boggle: boggle.c
	cc -o boggle ${CFLAGS} boggle.c
E 9
I 9
D 12
comp:	${COBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${COBJS}
E 12
I 12
comp: ${LIBC}
	${CC} -o $@ ${CFLAGS} $@.c
E 12
E 9

D 9
comp: comp.c
	cc -o comp ${CFLAGS} comp.c
E 9
I 9
clean: FRC
	rm -f ${OBJS} core comp boggle bogdict
E 9

D 9
clean:
	rm -f bogdict boggle comp
E 9
I 9
depend: FRC
D 12
	mkdep ${CFLAGS} ${SRCS}
E 12
I 12
	mkdep -p ${CFLAGS} ${SRCS}
E 12
E 9
I 7

D 9
depend:
E 9
I 9
install: FRC
D 11
	install -s -o bin -g bin -m 755 boggle ${DESTDIR}/usr/games/boggle
	install -o bin -g bin -m 444 bogdict ${DESTDIR}/usr/games/bogdict
E 11
I 11
	install -s -o games -g bin -m 4700 boggle ${DESTDIR}/usr/games/hide/boggle
	install -o games -g bin -m 400 bogdict ${DESTDIR}/usr/games/lib/bogdict
	(cd ${DESTDIR}/usr/games; rm -f boggle; ln -s dm boggle; chown games.bin boggle)
E 11

lint: FRC
D 12
	lint ${CFLAGS} ${CSRCS}
	lint ${CFLAGS} ${BSRCS}
E 12
I 12
	lint ${CFLAGS} comp.c
	lint ${CFLAGS} boggle.c
E 12

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 12
comp.o: comp.c /usr/include/stdio.h
boggle.o: boggle.c /usr/include/ctype.h /usr/include/errno.h
boggle.o: /usr/include/setjmp.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
boggle.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
boggle.o: /usr/include/signal.h /usr/include/stdio.h
E 12
I 12
comp: comp.c /usr/include/stdio.h
boggle: boggle.c /usr/include/ctype.h /usr/include/errno.h
boggle: /usr/include/setjmp.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
boggle: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
boggle: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/stdio.h
E 12

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 7
E 1
