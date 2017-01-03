#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	5.11	(Berkeley)	1/21/99
#
CFLAGS=	-O -DBSD4_2 -DBITS=16
LIBC=	/lib/libc.a
LIBZ=	/usr/lib/libz.a
SRCS=	compress.c gzcompat.c
OBJS=	compress.o gzcompat.o

all: compress gzcompat

compress: compress.o ${LIBC} ${LIBZ}
	${CC} ${CFLAGS} -o $@ compress.o -lz

gzcompat: gzcompat.o ${LIBC}
	${CC} ${CFLAGS} -o $@ gzcompat.o

clean: FRC
	rm -f ${OBJS} core compress gzcompat

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 compress ${DESTDIR}/usr/ucb/compress
	rm -f ${DESTDIR}/usr/ucb/uncompress ${DESTDIR}/usr/ucb/zcat
	ln ${DESTDIR}/usr/ucb/compress ${DESTDIR}/usr/ucb/uncompress
	ln ${DESTDIR}/usr/ucb/compress ${DESTDIR}/usr/ucb/zcat
	install -s -o bin -g bin -m 755 gzcompat ${DESTDIR}/usr/ucb/gzcompat

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

compress.o: compress.c /usr/include/stdio.h /usr/include/ctype.h
compress.o: /usr/include/signal.h /usr/include/machine/trap.h
compress.o: /usr/include/sys/types.h /usr/include/sys/stat.h
compress.o: /usr/include/zlib.h /usr/include/zconf.h
gzcompat.o: gzcompat.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
