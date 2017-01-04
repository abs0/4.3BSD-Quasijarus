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
#	@(#)Makefile	5.4 (Berkeley) 10/28/04
#
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBDIR=	/usr/lib
SRCS=	lppsbf.c lppsif.c lppsjf.c
OBJS=	lppsbf.o lppsif.o lppsjf.o

all: lppsbf lppsif lppsjf

lppsbf: lppsbf.c
	${CC} -o $@ ${CFLAGS} lppsbf.c

lppsif: lppsif.c
	${CC} -o $@ ${CFLAGS} lppsif.c

lppsjf: lppsjf.c
	${CC} -o $@ ${CFLAGS} lppsjf.c

clean: FRC
	rm -f ${OBJS} core a.out errs lppsbf lppsif lppsjf

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 lppsbf ${DESTDIR}/${LIBDIR}/lppsbf
	install -s -o bin -g bin -m 755 lppsif ${DESTDIR}/${LIBDIR}/lppsif
	install -s -o bin -g bin -m 755 lppsjf ${DESTDIR}/${LIBDIR}/lppsjf
	sed -e 's/%.*$$//' -e '/^$$/d' banner.ps > \
		${DESTDIR}/${LIBDIR}/lppsbanner
	chown bin.bin ${DESTDIR}/${LIBDIR}/lppsbanner

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

lppsbf: lppsbf.c /usr/include/sys/param.h /usr/include/sys/types.h
lppsbf: /usr/include/signal.h /usr/include/machine/trap.h
lppsbf: /usr/include/machine/machparam.h /usr/include/machine/endian.h
lppsbf: /usr/include/sys/file.h /usr/include/stdio.h /usr/include/ctype.h
lppsif: lppsif.c /usr/include/sys/param.h /usr/include/sys/types.h
lppsif: /usr/include/signal.h /usr/include/machine/trap.h
lppsif: /usr/include/machine/machparam.h /usr/include/machine/endian.h
lppsif: /usr/include/sys/file.h /usr/include/sys/stat.h /usr/include/sys/wait.h
lppsif: /usr/include/sys/errno.h /usr/include/stdio.h /usr/include/strings.h
lppsif: /usr/include/syslog.h
lppsjf: lppsjf.c /usr/include/sys/param.h /usr/include/sys/types.h
lppsjf: /usr/include/signal.h /usr/include/machine/trap.h
lppsjf: /usr/include/machine/machparam.h /usr/include/machine/endian.h
lppsjf: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
lppsjf: /usr/include/sys/ttydev.h /usr/include/sys/wait.h
lppsjf: /usr/include/sys/errno.h /usr/include/stdio.h /usr/include/strings.h
lppsjf: /usr/include/syslog.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
