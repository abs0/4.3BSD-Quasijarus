h24673
s 00010/00005/00075
d D 5.12 88/06/29 21:43:03 bostic 16 15
c install approved copyright notice
e
s 00009/00003/00071
d D 5.11 88/02/01 16:16:25 bostic 15 14
c add Berkeley specific header
e
s 00056/00019/00018
d D 5.10 87/06/16 18:42:31 bostic 14 13
c new template
e
s 00002/00000/00035
d D 5.9 87/05/31 21:13:38 bostic 13 12
c added depend label
e
s 00007/00000/00028
d D 5.8 87/04/11 15:38:36 bostic 12 11
c version #2; -f flag, remove home_dir, redist per folder
e
s 00010/00015/00018
d D 5.7 86/11/25 13:42:43 bostic 11 10
c added multiple file version of bugfiler
e
s 00001/00001/00032
d D 5.6 86/04/24 23:48:09 mckusick 10 9
c syntax error!
e
s 00005/00004/00028
d D 5.5 86/03/26 18:27:55 bloom 9 8
c move the home back to ucbvax, clean up unixtomh handling
e
s 00001/00001/00031
d D 5.4 86/02/12 19:01:53 bloom 8 7
c mv bugformat to /usr/lib
e
s 00000/00000/00032
d D 5.3 85/11/04 18:13:39 bloom 7 5
i 6
c merge work from arpa
e
s 00005/00000/00019
d D 4.3.1.1 85/11/04 18:11:47 bloom 6 3
c add unixtomh
e
s 00004/00001/00023
d D 5.2 85/08/09 18:08:34 kre 5 4
c allow default bugs name, and home to be set from makefile
e
s 00006/00001/00018
d D 5.1 85/06/06 08:58:38 dist 4 3
c Add copyright
e
s 00003/00000/00016
d D 4.3 83/11/15 13:19:08 ralph 3 2
c added clean entry
e
s 00001/00001/00015
d D 4.2 83/08/23 13:21:24 sam 2 1
c show some dependencies
e
s 00016/00000/00000
d D 4.1 83/05/11 14:01:08 ralph 1 0
c date and time created 83/05/11 14:01:08 by ralph
e
u
U
f b 
t
T
I 1
D 4
#	%M%	%I%	%E%
E 4
I 4
#
D 14
# Copyright (c) 1983 Regents of the University of California.
E 14
I 14
# Copyright (c) 1987 Regents of the University of California.
E 14
D 15
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 15
I 15
# All rights reserved.
E 15
#
D 14
#	%W% (Berkeley) %G%
E 14
I 14
D 15
#	%W%	(Berkeley)	%G%
E 15
I 15
# Redistribution and use in source and binary forms are permitted
D 16
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
#
#	%W% (Berkeley) %G%
E 15
E 14
E 4
#
D 14
# Bug report processor and associated programs
#

D 5
CFLAGS = -O -DUNIXCOMP
E 5
I 5
D 11
BUGS_NAME = 4bsd-bugs
D 9
BUGS_HOME = @ucbarpa.BERKELEY.EDU
E 9
I 9
BUGS_HOME = @ucbvax.BERKELEY.EDU
E 9
DEFS = -DBUGS_NAME='"$(BUGS_NAME)"' -DBUGS_HOME='"$(BUGS_HOME)"'
CFLAGS = -O -DUNIXCOMP $(DEFS)
E 5
LIBDIR=	/usr/lib
E 11
I 11
CFLAGS = -O -I.
E 11
DESTDIR=
E 14
I 14
CFLAGS=	-O -I.
LIBC=	/lib/libc.a
E 14
I 12
SRCS=	bugfiler.c error.c gethead.c process.c redist.c reply.c
E 12
I 11
OBJS=	bugfiler.o error.o gethead.o process.o redist.o reply.o
E 11

I 6
D 11
all: bugfiler unixtomh
E 11
I 11
all: bugfiler
E 11

E 6
D 2
bugfiler:
E 2
I 2
D 11
bugfiler: bugfiler.c
E 2
D 9
	${CC} ${CFLAGS} -o bugfiler bugfiler.c
E 9
I 9
D 10
	${CC} ${CFLAGS} -DUNIXTOMH=$'"{LIBDIR}/unixtomh"' -o bugfiler bugfiler.c
E 10
I 10
	${CC} ${CFLAGS} -DUNIXTOMH='"${LIBDIR}/unixtomh"' -o bugfiler bugfiler.c
E 11
I 11
D 14
bugfiler: ${OBJS}
E 14
I 14
bugfiler: ${OBJS} ${LIBC}
E 14
	${CC} ${CFLAGS} -o $@ ${OBJS}
E 11
E 10
E 9
I 6

D 11
unixtomh: unixtomh.c
	${CC} ${CFLAGS} -o unixtomh unixtomh.c
E 6

D 9
install: bugfiler sendbug.sh bugformat
E 9
I 9
install: bugfiler sendbug.sh bugformat unixtomh
E 9
	install -s bugfiler ${DESTDIR}${LIBDIR}/bugfiler
E 11
I 11
D 14
install: bugfiler sendbug.sh bugformat
	install -s -m 4755 -o root -g staff bugfiler ${DESTDIR}/usr/lib/bugfiler
E 11
	install -c sendbug.sh ${DESTDIR}/usr/ucb/sendbug
I 9
D 11
	install -s unixtomh ${DESTDIR}${LIBDIR}/unixtomh
E 11
E 9
D 8
	install -c -m 644 bugformat ${DESTDIR}/usr/ucb/bugformat
E 8
I 8
	install -c -m 644 bugformat ${DESTDIR}/usr/lib/bugformat
E 8
I 3

clean:
E 14
I 14
clean: FRC
E 14
D 9
	rm -f *.o bugfiler
E 9
I 9
D 11
	rm -f *.o bugfiler unixtomh
E 11
I 11
	rm -f ${OBJS} core bugfiler
I 12

I 13
D 14
depend:
E 14
I 14
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 14

E 13
D 14
tags:
E 14
I 14
install: FRC
	install -s -o root -g bin -m 4755 bugfiler ${DESTDIR}/usr/lib/bugfiler
	install -c -o bin -g bin -m 755 sendbug.sh ${DESTDIR}/usr/ucb/sendbug
	install -c -o bin -g bin -m 644 bugformat ${DESTDIR}/usr/lib/bugformat

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
E 14
	ctags ${SRCS}

D 14
lint:
	lint ${CFLAGS} -chapbx ${SRCS}
E 14
I 14
FRC:
E 14
E 12

D 14
${OBJS}: bug.h
E 14
I 14
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

bugfiler.o: bugfiler.c
bugfiler.o:bug.h
bugfiler.o: /usr/include/sys/param.h /usr/include/sys/types.h
bugfiler.o: /usr/include/signal.h /usr/include/machine/machparam.h
bugfiler.o: /usr/include/sys/dir.h /usr/include/sys/time.h /usr/include/time.h
bugfiler.o: /usr/include/sys/file.h /usr/include/pwd.h /usr/include/stdio.h
error.o: error.c
error.o:bug.h
error.o: /usr/include/sys/param.h /usr/include/sys/types.h
error.o: /usr/include/signal.h /usr/include/machine/machparam.h
error.o: /usr/include/sys/dir.h /usr/include/syslog.h /usr/include/stdio.h
gethead.o: gethead.c
gethead.o:bug.h
gethead.o: /usr/include/sys/param.h /usr/include/sys/types.h
gethead.o: /usr/include/signal.h /usr/include/machine/machparam.h
gethead.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/stdio.h
process.o: process.c
process.o:bug.h
process.o: /usr/include/sys/param.h /usr/include/sys/types.h
process.o: /usr/include/signal.h /usr/include/machine/machparam.h
process.o: /usr/include/sys/dir.h /usr/include/sys/file.h
process.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/stdio.h
process.o: /usr/include/ctype.h
redist.o: redist.c /usr/include/sys/file.h /usr/include/stdio.h
redist.o:bug.h
redist.o: /usr/include/sys/param.h /usr/include/sys/types.h
redist.o: /usr/include/signal.h /usr/include/machine/machparam.h
redist.o: /usr/include/sys/dir.h
reply.o: reply.c
reply.o:bug.h
reply.o: /usr/include/sys/param.h /usr/include/sys/types.h
reply.o: /usr/include/signal.h /usr/include/machine/machparam.h
reply.o: /usr/include/sys/dir.h /usr/include/sys/file.h /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 14
E 11
E 9
E 3
E 1
