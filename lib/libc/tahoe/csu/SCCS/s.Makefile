h26444
s 00010/00005/00060
d D 5.6 88/07/09 11:11:57 bostic 7 6
c install approved copyright notice
e
s 00012/00001/00053
d D 5.5 88/05/24 08:57:08 bostic 6 5
c add tags
e
s 00003/00001/00051
d D 5.4 88/05/20 15:04:05 bostic 5 4
c set DEFS to compile in SCCS ids.
e
s 00024/00018/00028
d D 5.3 88/05/20 13:48:25 bostic 4 3
c restructuring libc
e
s 00011/00004/00035
d D 5.2 87/07/27 16:16:04 bostic 3 1
c explicitly assign ownership
e
s 00008/00001/00038
d R 5.2 87/06/06 15:06:55 bostic 2 1
c added depend label
e
s 00039/00000/00000
d D 5.1 86/08/01 08:56:10 sam 1 0
c date and time created 86/08/01 08:56:10 by sam
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
#
I 3
D 4
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 4
I 4
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 4
#
D 4
#	%W%	(Berkeley)	%G%
E 4
I 4
# Redistribution and use in source and binary forms are permitted
D 7
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 4
#
E 3
D 4
DESTDIR=
E 4
I 4
#	%W% (Berkeley) %G%
#
E 4
D 5
CFLAGS=	-O
E 5
I 5
DEFS=	-DLIBC_SCCS
CFLAGS=	-O ${DEFS}
D 6
SRCS=	gmon.c mon.c
E 6
I 6
CSRCS=	gmon.c mon.c
ASRCS=	crt0.s  mcrt0.s
E 6
E 5
OBJS=	crt0.o mcrt0.o gcrt0.o
I 4
TAGSFILE=tags
E 4

.s.o:
	${AS} -o $*.o $*.s
	ld -x -r $*.o
	mv a.out $*.o

D 4
all:	${OBJS}
E 4
I 4
all link: ${OBJS}
E 4

D 4
mcrt0.o:	moncrt0.o mon.o
	ld -x -r -o mcrt0.o moncrt0.o mon.o
E 4
I 4
mcrt0.o: moncrt0.o mon.o
	ld -x -r -o $@ moncrt0.o mon.o
E 4

D 4
gcrt0.o:	moncrt0.o gmon.o
	ld -x -r -o gcrt0.o moncrt0.o gmon.o
E 4
I 4
gcrt0.o: moncrt0.o gmon.o
	ld -x -r -o $@ moncrt0.o gmon.o
E 4

D 4
moncrt0.o:	mcrt0.s
	$(AS) -o moncrt0.o mcrt0.s
E 4
I 4
moncrt0.o: mcrt0.s
	${AS} -o $@ mcrt0.s
E 4

D 4
mon.o:	mon.c
E 4
I 4
mon.o: mon.c
E 4
	${CC} -S ${CFLAGS} mon.c
	ex - mon.s < mon.ex
D 4
	$(AS) -o mon.o mon.s
E 4
I 4
	${AS} -o $@ mon.s
E 4

D 4
gmon.o:	gmon.c
E 4
I 4
gmon.o: gmon.c
E 4
	${CC} -S ${CFLAGS} gmon.c
	ex - gmon.s < mon.ex
D 4
	${AS} -o gmon.o gmon.s
E 4
I 4
	${AS} -o $@ gmon.s
E 4

D 4
install: all
E 4
I 4
install:
E 4
D 3
	install -m 444 crt0.o ${DESTDIR}/lib/crt0.o
	install -m 444 mcrt0.o ${DESTDIR}/lib/mcrt0.o
	install -m 444 gcrt0.o ${DESTDIR}/usr/lib/gcrt0.o
E 3
I 3
	install -o bin -g bin -m 444 crt0.o ${DESTDIR}/lib/crt0.o
	install -o bin -g bin -m 444 mcrt0.o ${DESTDIR}/lib/mcrt0.o
	install -o bin -g bin -m 444 gcrt0.o ${DESTDIR}/usr/lib/gcrt0.o
E 3

clean:
D 4
	rm -f ${OBJS} *mon.s moncrt0.o mon.o gmon.o a.out errs core
E 4
I 4
	rm -f *.o *mon.s a.out core ${TAGSFILE}
I 6

tags:
	cwd=`pwd`; \
	for i in ${CSRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done
	(P=`pwd`; \
	egrep "^ENTRY(.*)|^SYSCALL(.*)" ${ASRCS} | sed \
"s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);\3 $$P/\1 /^\2(\3\4$$/;" \
		>> ${TAGSFILE})
E 6
E 4
I 3

depend:
E 3
E 1
