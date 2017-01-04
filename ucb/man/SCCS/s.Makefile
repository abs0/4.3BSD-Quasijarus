h53824
s 00015/00024/00043
d D 5.6 04/10/20 20:57:54 msokolov 7 6
c old man is back!
e
s 00010/00005/00057
d D 5.5 88/06/29 19:42:44 bostic 6 5
c install approved copyright notice
e
s 00014/00014/00048
d D 5.4 88/01/15 16:43:33 bostic 5 4
c don't make .o's first
e
s 00009/00003/00053
d D 5.3 87/12/16 15:41:36 bostic 4 3
c add Berkeley headers
e
s 00002/00000/00054
d D 5.2 87/06/30 21:06:36 bostic 3 1
c general cleanup
e
s 00002/00000/00054
d R 5.2 87/06/30 19:15:22 bostic 2 1
c it really works now
e
s 00054/00000/00000
d D 5.1 87/06/29 20:55:49 bostic 1 0
c date and time created 87/06/29 20:55:49 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
D 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 4
I 4
# All rights reserved.
E 4
#
D 4
#	%W%	(Berkeley)	%G%
E 4
I 4
# Redistribution and use in source and binary forms are permitted
D 6
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
#
#	%W% (Berkeley) %G%
E 4
#
CFLAGS=	-O
LIBC=	/lib/libc.a
D 7
ASRCS=	apropos.c
D 5
AOBJS=	apropos.o
E 5
MSRCS=	man.c
E 7
I 7
SRCS=	man.c
E 7
D 5
MOBJS=	man.o
E 5

D 7
all: man apropos
E 7
I 7
all: man
E 7

D 5
apropos: ${AOBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${AOBJS}
E 5
I 5
D 7
apropos: ${LIBC}
	${CC} -o $@ ${CFLAGS} ${ASRCS}
E 7
I 7
man: ${SRCS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${SRCS}
E 7
E 5

D 5
man:	${MOBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${MOBJS}
E 5
I 5
D 7
man: ${LIBC}
	${CC} -o $@ ${CFLAGS} ${MSRCS}
E 5

E 7
clean: FRC
D 5
	rm -f ${AOBJS} ${MOBJS} core apropos man
E 5
I 5
D 7
	rm -f core apropos man
E 7
I 7
	rm -f core a.out errs man
E 7
E 5

depend: FRC
D 5
	mkdep ${CFLAGS} ${ASRCS} ${MSRCS}
E 5
I 5
D 7
	mkdep -p ${CFLAGS} ${ASRCS} ${MSRCS}
E 7
I 7
	mkdep -p ${CFLAGS} ${SRCS}
E 7
E 5

install: FRC
I 3
	rm -f ${DESTDIR}/usr/ucb/whatis ${DESTDIR}/usr/ucb/apropos
E 3
D 7
	install -s -o bin -g bin -m 755 apropos ${DESTDIR}/usr/ucb/apropos
E 7
	install -s -o bin -g bin -m 755 man ${DESTDIR}/usr/ucb/man
I 3
D 7
	ln ${DESTDIR}/usr/ucb/apropos ${DESTDIR}/usr/ucb/whatis
E 7
I 7
	ln ${DESTDIR}/usr/ucb/man ${DESTDIR}/usr/ucb/whatis
	ln ${DESTDIR}/usr/ucb/man ${DESTDIR}/usr/ucb/apropos
E 7
E 3

lint: FRC
D 7
	lint ${CFLAGS} ${ASRCS}
	lint ${CFLAGS} ${MSRCS}
E 7
I 7
	lint ${CFLAGS} ${SRCS}
E 7

tags: FRC
D 7
	ctags ${ASRCS}
	ctags ${MSRCS}
	sort -o tags tags
E 7
I 7
	ctags ${SRCS}
E 7

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 5
apropos.o: apropos.c /usr/include/sys/param.h /usr/include/sys/types.h
apropos.o: /usr/include/signal.h /usr/include/machine/machparam.h
apropos.o: /usr/include/stdio.h /usr/include/ctype.h
man.o: man.c /usr/include/sys/param.h /usr/include/sys/types.h
man.o: /usr/include/signal.h /usr/include/machine/machparam.h
man.o: /usr/include/sys/file.h /usr/include/stdio.h /usr/include/ctype.h
E 5
I 5
D 7
apropos: apropos.c /usr/include/sys/param.h /usr/include/sys/types.h
apropos: /usr/include/signal.h /usr/include/machine/trap.h
apropos: /usr/include/machine/machparam.h /usr/include/machine/endian.h
apropos: /usr/include/stdio.h /usr/include/ctype.h
man: man.c /usr/include/sys/param.h /usr/include/sys/types.h
man: /usr/include/signal.h /usr/include/machine/trap.h
E 7
I 7
man: man.c /usr/include/stdio.h /usr/include/ctype.h /usr/include/sgtty.h
man: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
man: /usr/include/sys/ttydev.h /usr/include/sys/param.h
man: /usr/include/sys/types.h /usr/include/signal.h /usr/include/machine/trap.h
E 7
man: /usr/include/machine/machparam.h /usr/include/machine/endian.h
D 7
man: /usr/include/sys/file.h /usr/include/stdio.h /usr/include/ctype.h
E 7
I 7
man: /usr/include/sys/stat.h /usr/include/signal.h /usr/include/strings.h
E 7
E 5

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
