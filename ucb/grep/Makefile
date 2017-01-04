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
#	@(#)Makefile	5.5 (Berkeley) 2012/03/03
#
# Compilation options for jawgrep:
#
# -DEGREPSTD=path	location of std egrep (normally /usr/bin/egrep).
# -DGREPSTD=path	location of std grep (normally /bin/grep).
# -DFGREPSTD=path	location of std fgrep (normally /usr/bin/fgrep).
# -Dstrrchr=rindex, -Dstrchr=index	for troglodytes.
# -DSLOWSYS		invoke xread() for system time quirk on PDP, others? 
# -DNOKANJI		default is for Japanese Unix.  undef only for raw
#			 parity-marked search capability, not standard w/grep.
# -DCHINESE		for systems using EUC Chinese2 codes

CFLAGS=	-O
JCFLAGS=${CFLAGS} -Dstrrchr=rindex -Dstrchr=index -DNOKANJI
LIBC=	/lib/libc.a
ALL=	bin-grep egrep fgrep jawgrep
SRCS=	bin-grep.c egrep.c fgrep.c jawgrep.c

all: ${ALL}

bin-grep: bin-grep.c ${LIBC}
	${CC} -o $@ ${CFLAGS} $@.c

egrep: egrep.o recurse.o ${LIBC}
	${CC} -o $@ $@.o recurse.o

fgrep: fgrep.o recurse.o ${LIBC}
	${CC} -o $@ $@.o recurse.o

jawgrep: jawgrep.c ${LIBC}
	${CC} -o $@ ${JCFLAGS} $@.c

clean: FRC
	rm -f *.o *.out errs core ${ALL} egrep.c

depend:
# no local includes, no depend needed

install: FRC
	install -c -s -o bin -g bin -m 755 bin-grep ${DESTDIR}/bin/grep
	install -c -s -o bin -g bin -m 755 bin-grep \
					${DESTDIR}/usr/lib/old.bin.grep
	install -s -o bin -g bin -m 755 egrep fgrep ${DESTDIR}/usr/bin
	install -s -o bin -g bin -m 755 jawgrep ${DESTDIR}/usr/ucb
	cd ${DESTDIR}/usr/lib; rm -f old.[ef]grep; ln ../bin/egrep old.egrep; \
						ln ../bin/fgrep old.fgrep

lint: FRC ${SRCS}
	lint ${CFLAGS} ${SRCS}

tags: FRC ${SRCS}
	ctags ${SRCS}

FRC:
