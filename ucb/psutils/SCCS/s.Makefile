h20779
s 00003/00003/00066
d D 5.9 10/10/09 19:07:54 msokolov 9 8
c fontlist.* library files added
e
s 00004/00002/00065
d D 5.8 05/09/16 04:46:49 msokolov 8 7
c psinclude added
e
s 00003/00003/00064
d D 5.7 04/10/30 00:43:04 msokolov 7 6
c oops, need to install binaries in /usr/ucb, not /usr/lib
e
s 00006/00002/00061
d D 5.6 04/10/30 00:39:29 msokolov 6 5
c include t1csasm from IFCTF's t1free package
e
s 00017/00005/00046
d D 5.5 04/10/30 00:36:35 msokolov 5 4
c management utils separated, psrange and txtps joined us instead
e
s 00001/00001/00050
d D 5.4 04/09/14 05:54:01 msokolov 4 3
c add cHexEncoding.ps
e
s 00001/00001/00050
d D 5.3 04/09/08 17:02:43 msokolov 3 2
c TroffEncoding.ps moved to pstroff source directory
e
s 00002/00002/00049
d D 5.2 04/09/04 08:26:00 msokolov 2 1
c add TroffEncoding.ps, fix install
e
s 00051/00000/00000
d D 5.1 04/09/03 21:52:25 msokolov 1 0
c date and time created 04/09/03 21:52:25 by msokolov
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
CFLAGS=	-O
LIBC=	/lib/libc.a
D 7
LIBDIR=	/usr/lib
E 7
I 7
LIBDIR=	/usr/lib/psutils
E 7
D 5
SRCS=	lppsspd.c
PROGS=	lppsspd
E 5
I 5
D 6
SRCS=	psrange.c txtps.c
PROGS=	psrange txtps
E 6
I 6
D 8
SRCS=	psrange.c t1csasm.c txtps.c
PROGS=	psrange t1csasm txtps
E 8
I 8
SRCS=	psinclude.c psrange.c t1csasm.c txtps.c
PROGS=	psinclude psrange t1csasm txtps
E 8
E 6
E 5
D 9
PSFILES=ISOCyrillicEncoding.ps ISOLatin1Encoding.ps KOI8Encoding.ps \
D 2
	l2trayconfutil.ps
E 2
I 2
D 3
	TroffEncoding.ps l2trayconfutil.ps
E 3
I 3
D 4
	l2trayconfutil.ps
E 4
I 4
D 5
	cHexEncoding.ps l2trayconfutil.ps
E 5
I 5
	cHexEncoding.ps
E 9
I 9
LIBFILES=ISOCyrillicEncoding.ps ISOLatin1Encoding.ps KOI8Encoding.ps \
	cHexEncoding.ps fontlist.13 fontlist.14 fontlist.35
E 9
E 5
E 4
E 3
E 2

all:	${PROGS}

D 5
lppsspd: lppsspd.c
	${CC} -o $@ ${CFLAGS} lppsspd.c
E 5
I 5
${PROGS}: ${LIBC}
	${CC} ${CFLAGS} -o $@ $@.c
E 5

clean: FRC
	rm -f *.o core a.out errs ${PROGS}

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
D 7
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/${LIBDIR}
D 2
	install -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}/${LIBDIR}/psutils
E 2
I 2
	install -c -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}/${LIBDIR}/psutils
E 7
I 7
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb
D 9
	install -c -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}${LIBDIR}
E 9
I 9
	install -c -o bin -g bin -m 444 ${LIBFILES} ${DESTDIR}${LIBDIR}
E 9
E 7
E 2

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
I 5

I 8
psinclude: psinclude.c /usr/include/stdio.h /usr/include/ctype.h
psinclude: /usr/include/strings.h
E 8
psrange: psrange.c /usr/include/sys/param.h /usr/include/sys/types.h
psrange: /usr/include/signal.h /usr/include/machine/trap.h
psrange: /usr/include/machine/machparam.h /usr/include/machine/endian.h
psrange: /usr/include/ctype.h /usr/include/strings.h /usr/include/stdio.h
I 6
t1csasm: t1csasm.c /usr/include/sys/param.h /usr/include/sys/types.h
t1csasm: /usr/include/signal.h /usr/include/machine/trap.h
t1csasm: /usr/include/machine/machparam.h /usr/include/machine/endian.h
t1csasm: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
E 6
txtps: txtps.c /usr/include/sys/param.h /usr/include/sys/types.h
txtps: /usr/include/signal.h /usr/include/machine/trap.h
txtps: /usr/include/machine/machparam.h /usr/include/machine/endian.h
txtps: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
txtps: /usr/include/time.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1
