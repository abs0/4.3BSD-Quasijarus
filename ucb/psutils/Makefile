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
#	@(#)Makefile	5.9 (Berkeley) 10/9/10
#
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBDIR=	/usr/lib/psutils
SRCS=	psinclude.c psrange.c t1csasm.c txtps.c
PROGS=	psinclude psrange t1csasm txtps
LIBFILES=ISOCyrillicEncoding.ps ISOLatin1Encoding.ps KOI8Encoding.ps \
	cHexEncoding.ps fontlist.13 fontlist.14 fontlist.35

all:	${PROGS}

${PROGS}: ${LIBC}
	${CC} ${CFLAGS} -o $@ $@.c

clean: FRC
	rm -f *.o core a.out errs ${PROGS}

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb
	install -c -o bin -g bin -m 444 ${LIBFILES} ${DESTDIR}${LIBDIR}

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

psinclude: psinclude.c /usr/include/stdio.h /usr/include/ctype.h
psinclude: /usr/include/strings.h
psrange: psrange.c /usr/include/sys/param.h /usr/include/sys/types.h
psrange: /usr/include/signal.h /usr/include/machine/trap.h
psrange: /usr/include/machine/machparam.h /usr/include/machine/endian.h
psrange: /usr/include/ctype.h /usr/include/strings.h /usr/include/stdio.h
t1csasm: t1csasm.c /usr/include/sys/param.h /usr/include/sys/types.h
t1csasm: /usr/include/signal.h /usr/include/machine/trap.h
t1csasm: /usr/include/machine/machparam.h /usr/include/machine/endian.h
t1csasm: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
txtps: txtps.c /usr/include/sys/param.h /usr/include/sys/types.h
txtps: /usr/include/signal.h /usr/include/machine/trap.h
txtps: /usr/include/machine/machparam.h /usr/include/machine/endian.h
txtps: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
txtps: /usr/include/time.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
