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
#	@(#)Makefile	5.6 (Berkeley) 10/20/04
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	man.c

all: man

man: ${SRCS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${SRCS}

clean: FRC
	rm -f core a.out errs man

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	rm -f ${DESTDIR}/usr/ucb/whatis ${DESTDIR}/usr/ucb/apropos
	install -s -o bin -g bin -m 755 man ${DESTDIR}/usr/ucb/man
	ln ${DESTDIR}/usr/ucb/man ${DESTDIR}/usr/ucb/whatis
	ln ${DESTDIR}/usr/ucb/man ${DESTDIR}/usr/ucb/apropos

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

man: man.c /usr/include/stdio.h /usr/include/ctype.h /usr/include/sgtty.h
man: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
man: /usr/include/sys/ttydev.h /usr/include/sys/param.h
man: /usr/include/sys/types.h /usr/include/signal.h /usr/include/machine/trap.h
man: /usr/include/machine/machparam.h /usr/include/machine/endian.h
man: /usr/include/sys/stat.h /usr/include/signal.h /usr/include/strings.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
