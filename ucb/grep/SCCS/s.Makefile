h05382
s 00004/00004/00067
d D 5.5 2012/03/03 18:17:24 msokolov 5 4
c directory recursion added to [ef]grep
e
s 00024/00051/00047
d D 5.4 2012/02/20 20:57:26 msokolov 4 3
c Asar lives, Asar returns!
e
s 00011/00005/00087
d D 5.3 88/07/09 10:41:10 bostic 3 2
c install approved copyright notice
e
s 00001/00001/00091
d D 5.2 88/01/21 12:41:01 bostic 2 1
c optimize compiler
e
s 00092/00000/00000
d D 5.1 87/12/12 18:07:39 bostic 1 0
c date and time created 87/12/12 18:07:39 by bostic
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
D 3
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W% (Berkeley) %E%
E 4
I 3
#
I 4
# Compilation options for jawgrep:
E 4
E 3
#
# -DEGREPSTD=path	location of std egrep (normally /usr/bin/egrep).
# -DGREPSTD=path	location of std grep (normally /bin/grep).
# -DFGREPSTD=path	location of std fgrep (normally /usr/bin/fgrep).
# -Dstrrchr=rindex, -Dstrchr=index	for troglodytes.
# -DSLOWSYS		invoke xread() for system time quirk on PDP, others? 
# -DNOKANJI		default is for Japanese Unix.  undef only for raw
#			 parity-marked search capability, not standard w/grep.
# -DCHINESE		for systems using EUC Chinese2 codes

D 2
CFLAGS=	-g -Dstrrchr=rindex -Dstrchr=index -DNOKANJI \
E 2
I 2
D 4
CFLAGS=	-O -Dstrrchr=rindex -Dstrchr=index -DNOKANJI \
E 2
	-DEGREPSTD=\"/usr/lib/old.egrep\" -DGREPSTD=\"/usr/lib/old.bin.grep\" \
	-DFGREPSTD=\"/usr/lib/old.fgrep\"
E 4
I 4
CFLAGS=	-O
JCFLAGS=${CFLAGS} -Dstrrchr=rindex -Dstrchr=index -DNOKANJI
E 4
LIBC=	/lib/libc.a
D 4
ALL=	egrep old.ucb.grep old.bin.grep old.fgrep old.egrep
SRCS=	egrep.c old.ucb.grep.c old.bin.grep.c old.fgrep.c old.egrep.c
OBJS=
E 4
I 4
ALL=	bin-grep egrep fgrep jawgrep
SRCS=	bin-grep.c egrep.c fgrep.c jawgrep.c
E 4

all: ${ALL}

I 4
bin-grep: bin-grep.c ${LIBC}
	${CC} -o $@ ${CFLAGS} $@.c

E 4
D 5
egrep: egrep.c ${LIBC}
D 4
	${CC} -o $@ ${CFLAGS} egrep.c
E 4
I 4
	${CC} -o $@ ${CFLAGS} $@.c
E 5
I 5
egrep: egrep.o recurse.o ${LIBC}
	${CC} -o $@ $@.o recurse.o
E 5
E 4

D 4
oegrep: oegrep.c ${LIBC}
	${CC} -o $@ ${CFLAGS} oegrep.c
E 4
I 4
D 5
fgrep: fgrep.c ${LIBC}
	${CC} -o $@ ${CFLAGS} $@.c
E 5
I 5
fgrep: fgrep.o recurse.o ${LIBC}
	${CC} -o $@ $@.o recurse.o
E 5
E 4

D 4
old.ucb.grep: ${LIBC}
	${CC} -o $@ ${CFLAGS} old.ucb.grep.c
E 4
I 4
jawgrep: jawgrep.c ${LIBC}
	${CC} -o $@ ${JCFLAGS} $@.c
E 4

D 4
old.bin.grep: ${LIBC}
	${CC} -o $@ ${CFLAGS} old.bin.grep.c

old.fgrep: ${LIBC}
	${CC} -o $@ ${CFLAGS} old.fgrep.c

old.egrep: ${LIBC}
	${CC} -o $@ ${CFLAGS} old.egrep.c

E 4
clean: FRC
D 4
	rm -f ${OBJS} core ${ALL} old.egrep.c
E 4
I 4
	rm -f *.o *.out errs core ${ALL} egrep.c
E 4

D 4
depend: FRC ${SRCS}
	mkdep -p ${CFLAGS} ${SRCS}
E 4
I 4
depend:
# no local includes, no depend needed
E 4

install: FRC
D 4
	install -s -o bin -g bin -m 755 egrep ${DESTDIR}/usr/ucb/egrep
	rm -f ${DESTDIR}/usr/ucb/fgrep ${DESTDIR}/usr/ucb/grep
	ln ${DESTDIR}/usr/ucb/egrep ${DESTDIR}/usr/ucb/grep
	ln ${DESTDIR}/usr/ucb/egrep ${DESTDIR}/usr/ucb/fgrep
	install -s -o bin -g bin -m 755 old.bin.grep ${DESTDIR}/usr/lib/old.bin.grep
	install -s -o bin -g bin -m 755 old.ucb.grep ${DESTDIR}/usr/lib/old.ucb.grep
	install -s -o bin -g bin -m 755 old.fgrep ${DESTDIR}/usr/lib/old.fgrep
	install -s -o bin -g bin -m 755 old.egrep ${DESTDIR}/usr/lib/old.egrep
E 4
I 4
	install -c -s -o bin -g bin -m 755 bin-grep ${DESTDIR}/bin/grep
	install -c -s -o bin -g bin -m 755 bin-grep \
					${DESTDIR}/usr/lib/old.bin.grep
	install -s -o bin -g bin -m 755 egrep fgrep ${DESTDIR}/usr/bin
	install -s -o bin -g bin -m 755 jawgrep ${DESTDIR}/usr/ucb
	cd ${DESTDIR}/usr/lib; rm -f old.[ef]grep; ln ../bin/egrep old.egrep; \
						ln ../bin/fgrep old.fgrep
E 4

lint: FRC ${SRCS}
	lint ${CFLAGS} ${SRCS}

tags: FRC ${SRCS}
	ctags ${SRCS}

FRC:
D 4

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

egrep: egrep.c /usr/include/stdio.h /usr/include/ctype.h
egrep: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/sys/file.h
egrep: /usr/include/regexp.h
old.ucb.grep: old.ucb.grep.c /usr/include/stdio.h /usr/include/sys/types.h
old.ucb.grep: /usr/include/sys/stat.h
old.bin.grep: old.bin.grep.c /usr/include/sys/types.h /usr/include/sys/file.h
old.bin.grep: /usr/include/sys/stat.h /usr/include/stdio.h /usr/include/ctype.h
old.fgrep: old.fgrep.c /usr/include/stdio.h /usr/include/ctype.h
old.fgrep: /usr/include/sys/param.h /usr/include/sys/types.h
old.fgrep: /usr/include/signal.h /usr/include/machine/trap.h
old.fgrep: /usr/include/machine/machparam.h /usr/include/sys/stat.h
old.egrep: old.egrep.c /usr/include/stdio.h /usr/include/sys/types.h
old.egrep: /usr/include/sys/stat.h /usr/include/ctype.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1
