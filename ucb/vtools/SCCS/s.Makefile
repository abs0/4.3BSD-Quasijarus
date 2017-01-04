h03024
s 00011/00008/00056
d D 6.3 04/10/26 17:39:23 msokolov 3 2
c revive from the ashes
e
s 00001/00001/00063
d D 6.2 99/09/27 17:47:32 msokolov 2 1
c vwidth was misspelled
e
s 00064/00000/00000
d D 6.1 87/11/04 20:46:39 bostic 1 0
c date and time created 87/11/04 20:46:39 by bostic
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
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	fcvt.c rotate.c rotprt.c vfontinfo.c vfw.c vwidth.c
OBJS=	fcvt.o rotate.o rotprt.o vfontinfo.o vfw.o vwidth.o
ALL=	fcvt rotate rotprt vfontinfo vfw vwidth

D 3
all: ${ALL}
E 3
I 3
all: ${ALL} fed
E 3

fcvt: ${LIBC}
	${CC} -o $@ ${CFLAGS} fcvt.c
rotate: ${LIBC}
	${CC} -o $@ ${CFLAGS} rotate.c
rotprt: ${LIBC}
	${CC} -o $@ ${CFLAGS} rotprt.c
vfontinfo: ${LIBC}
	${CC} -o $@ ${CFLAGS} vfontinfo.c
vfw: ${LIBC}
	${CC} -o $@ ${CFLAGS} vfw.c
vwidth: ${LIBC}
	${CC} -o $@ ${CFLAGS} vwidth.c

I 3
fed: FRC
	cd fed; make ${MFLAGS}

E 3
clean: FRC
	rm -f ${OBJS} core ${ALL}
I 3
	cd fed; make ${MFLAGS} clean
E 3

D 3
depend: FRC
E 3
I 3
ldepend: FRC
E 3
	mkdep -p ${CFLAGS} ${SRCS}

I 3
depend:	ldepend FRC
	cd fed; make ${MFLAGS} depend

E 3
install: FRC
D 3
	install -s -o bin -g bin -m 755 fcvt ${DESTDIR}/usr/old/fcvt
	install -s -o bin -g bin -m 755 rotate ${DESTDIR}/usr/old/rotate
	install -s -o bin -g bin -m 755 rotprt ${DESTDIR}/usr/old/rotprt
	install -s -o bin -g bin -m 755 vfontinfo ${DESTDIR}/usr/old/vfontinfo
	install -s -o bin -g bin -m 755 vfw ${DESTDIR}/usr/old/vfw
D 2
	install -s -o bin -g bin -m 755 vwdith ${DESTDIR}/usr/old/vwdith
E 2
I 2
	install -s -o bin -g bin -m 755 vwidth ${DESTDIR}/usr/old/vwidth
E 3
I 3
	install -s -o bin -g bin -m 755 ${ALL} ${DESTDIR}/usr/ucb
	cd fed; make ${MFLAGS} install
E 3
E 2

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

fcvt: fcvt.c /usr/include/stdio.h /usr/include/vfont.h
rotate: rotate.c /usr/include/stdio.h /usr/include/vfont.h
rotate: /usr/include/sys/types.h /usr/include/sys/stat.h
rotprt: rotprt.c /usr/include/stdio.h /usr/include/vfont.h
rotprt: /usr/include/sys/types.h /usr/include/sys/stat.h
vfontinfo: vfontinfo.c /usr/include/stdio.h /usr/include/ctype.h
vfontinfo: /usr/include/vfont.h
vfw: vfw.c /usr/include/stdio.h
vwidth: vwidth.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
