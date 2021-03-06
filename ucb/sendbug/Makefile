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
#	@(#)Makefile	5.12 (Berkeley) 6/29/88
#
CFLAGS=	-O -I.
LIBC=	/lib/libc.a
SRCS=	bugfiler.c error.c gethead.c process.c redist.c reply.c
OBJS=	bugfiler.o error.o gethead.o process.o redist.o reply.o

all: bugfiler

bugfiler: ${OBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${OBJS}

clean: FRC
	rm -f ${OBJS} core bugfiler

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o root -g bin -m 4755 bugfiler ${DESTDIR}/usr/lib/bugfiler
	install -c -o bin -g bin -m 755 sendbug.sh ${DESTDIR}/usr/ucb/sendbug
	install -c -o bin -g bin -m 644 bugformat ${DESTDIR}/usr/lib/bugformat

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

bugfiler.o: bugfiler.c bug.h /usr/include/sys/param.h /usr/include/sys/types.h
bugfiler.o: /usr/include/signal.h /usr/include/machine/trap.h
bugfiler.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
bugfiler.o: /usr/include/sys/dir.h /usr/include/sys/time.h /usr/include/time.h
bugfiler.o: /usr/include/sys/file.h /usr/include/pwd.h /usr/include/stdio.h
error.o: error.c bug.h /usr/include/sys/param.h /usr/include/sys/types.h
error.o: /usr/include/signal.h /usr/include/machine/trap.h
error.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
error.o: /usr/include/sys/dir.h /usr/include/syslog.h /usr/include/stdio.h
gethead.o: gethead.c bug.h /usr/include/sys/param.h /usr/include/sys/types.h
gethead.o: /usr/include/signal.h /usr/include/machine/trap.h
gethead.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
gethead.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/stdio.h
process.o: process.c bug.h /usr/include/sys/param.h /usr/include/sys/types.h
process.o: /usr/include/signal.h /usr/include/machine/trap.h
process.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
process.o: /usr/include/sys/dir.h /usr/include/sys/file.h
process.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/stdio.h
process.o: /usr/include/ctype.h
redist.o: redist.c /usr/include/sys/file.h /usr/include/stdio.h
redist.o: /usr/include/ctype.h bug.h /usr/include/sys/param.h
redist.o: /usr/include/sys/types.h /usr/include/signal.h
redist.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
redist.o: /usr/include/machine/endian.h /usr/include/sys/dir.h
reply.o: reply.c bug.h /usr/include/sys/param.h /usr/include/sys/types.h
reply.o: /usr/include/signal.h /usr/include/machine/trap.h
reply.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
reply.o: /usr/include/sys/dir.h /usr/include/sys/file.h /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
