h53038
s 00010/00005/00089
d D 5.5 88/06/29 20:19:23 bostic 14 13
c install approved copyright notice
e
s 00014/00008/00080
d D 5.4 88/02/01 11:34:35 bostic 13 12
c add new Berkeley headers
e
s 00073/00017/00015
d D 5.3 87/06/16 18:39:42 bostic 12 11
c new template
e
s 00002/00000/00030
d D 5.2 87/05/31 21:13:15 bostic 11 10
c added depend label
e
s 00007/00002/00023
d D 5.1 85/06/06 08:55:19 dist 10 9
c Add copyright
e
s 00001/00001/00024
d D 4.9 85/06/01 13:30:12 edward 9 8
c install with -s
e
s 00001/00001/00024
d D 4.8 85/02/28 14:40:48 ralph 8 7
c moved rdist to /usr/ucb
e
s 00003/00002/00022
d D 4.7 84/12/06 14:55:27 ralph 7 6
c make location of rdist definable (for testing).
e
s 00001/00001/00023
d D 4.6 83/11/30 15:20:48 ralph 6 5
c fix install dependency
e
s 00001/00001/00023
d D 4.5 83/10/28 13:19:17 ralph 5 4
c fixed install line
e
s 00001/00001/00023
d D 4.4 83/10/26 14:23:23 ralph 4 3
c changed to cc -O files
e
s 00001/00001/00023
d D 4.3 83/10/10 16:15:02 ralph 3 2
c stable version that works.
e
s 00005/00005/00019
d D 4.2 83/09/27 14:38:16 ralph 2 1
c First stable version.
e
s 00024/00000/00000
d D 4.1 83/09/07 13:19:10 ralph 1 0
c date and time created 83/09/07 13:19:10 by ralph
e
u
U
t
T
I 1
D 2
#	%M%	%I%	%E%
E 2
I 2
D 3
#	Makefile	4.1	83/09/07
E 3
I 3
D 10
#	%M%	%I%	%E%
E 3
E 2

E 10
I 10
#
D 12
# Copyright (c) 1983 Regents of the University of California.
E 12
I 12
# Copyright (c) 1987 Regents of the University of California.
E 12
D 13
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 13
I 13
# All rights reserved.
E 13
#
D 12
#	%W% (Berkeley) %G%
E 12
I 12
D 13
#	%W%	(Berkeley)	%G%
E 13
I 13
# Redistribution and use in source and binary forms are permitted
D 14
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
E 13
E 12
#
I 13
#	%W% (Berkeley) %G%
#
E 13
I 12
LIBC=	/lib/libc.a
E 12
E 10
I 7
D 8
RDIST = /usr/local/rdist
E 8
I 8
D 13
RDIST = /usr/ucb/rdist
E 8
E 7
D 12
DESTDIR=
E 12
I 12
CFLAGS= -O -DRDIST=\"${RDIST}\"
E 12
D 2
SRCS =	main.c gram.y docmd.c expand.c server.c
OBJS =	main.o gram.o docmd.o expand.o server.o
E 2
I 2
SRCS =	docmd.c expand.c gram.y lookup.c main.c server.c
OBJS =	docmd.o expand.o gram.o lookup.o main.o server.o
E 13
I 13
RDIST=	/usr/ucb/rdist
CFLAGS=	-O -DRDIST=\"${RDIST}\"
SRCS=	docmd.c expand.c gram.y lookup.c main.c server.c
OBJS=	docmd.o expand.o gram.o lookup.o main.o server.o
E 13
E 2
D 12
LINT =	lint -ps
D 4
CFLAGS=
E 4
I 4
D 7
CFLAGS= -O
E 7
I 7
CFLAGS= -O -DRDIST=\"${RDIST}\"
E 12
E 7
E 4

D 12
rdist:	${OBJS}
	${CC} -o rdist ${OBJS}
E 12
I 12
all: rdist
E 12

D 12
${OBJS}:  defs.h
E 12
I 12
D 13
rdist:	${OBJS} ${LIBC}
E 13
I 13
rdist: ${OBJS} ${LIBC}
E 13
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 12

D 12
clean:
	rm -f *.o gram.c errs
E 12
I 12
clean: FRC
	rm -f ${OBJS} core rdist
E 12

I 11
D 12
depend:
E 12
I 12
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 12

E 11
D 6
install:
E 6
I 6
D 12
install: rdist
E 6
D 5
	install -s rdist ${DESTDIR}/usr/ucb/rdist
E 5
I 5
D 7
	install -s -m 4751 rdist ${DESTDIR}/usr/local/rdist
E 7
I 7
D 9
	install -m 4751 rdist ${DESTDIR}${RDIST}
E 9
I 9
	install -s -m 4751 rdist ${DESTDIR}${RDIST}
E 12
I 12
install: FRC
	install -s -o root -g bin -m 4751 rdist ${DESTDIR}${RDIST}
E 12
E 9
E 7
E 5

D 2
lint:	main.c gram.c docmd.c expand.c server.c
	${LINT} main.c gram.c docmd.c expand.c server.c
E 2
I 2
D 12
lint:	docmd.c expand.c gram.c lookup.c main.c server.c
	${LINT} docmd.c expand.c gram.c lookup.c main.c server.c
E 12
I 12
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 12
E 2

D 12
print:	${SRCS}
	lpr -p ${SRCS} defs.h
E 12
I 12
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

docmd.o: docmd.c
docmd.o:defs.h
docmd.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/errno.h
docmd.o: /usr/include/pwd.h /usr/include/grp.h /usr/include/sys/param.h
docmd.o: /usr/include/sys/types.h /usr/include/signal.h
docmd.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
docmd.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
docmd.o: /usr/include/netinet/in.h /usr/include/setjmp.h /usr/include/netdb.h
expand.o: expand.c
expand.o:defs.h
expand.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/errno.h
expand.o: /usr/include/pwd.h /usr/include/grp.h /usr/include/sys/param.h
expand.o: /usr/include/sys/types.h /usr/include/signal.h
expand.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
expand.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
expand.o: /usr/include/netinet/in.h
gram.o: gram.y
gram.o:defs.h
gram.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/errno.h
gram.o: /usr/include/pwd.h /usr/include/grp.h /usr/include/sys/param.h
gram.o: /usr/include/sys/types.h /usr/include/signal.h
gram.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
gram.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
gram.o: /usr/include/netinet/in.h
lookup.o: lookup.c
lookup.o:defs.h
lookup.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/errno.h
lookup.o: /usr/include/pwd.h /usr/include/grp.h /usr/include/sys/param.h
lookup.o: /usr/include/sys/types.h /usr/include/signal.h
lookup.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
lookup.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
lookup.o: /usr/include/netinet/in.h
main.o: main.c
main.o:defs.h
main.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/errno.h
main.o: /usr/include/pwd.h /usr/include/grp.h /usr/include/sys/param.h
main.o: /usr/include/sys/types.h /usr/include/signal.h
main.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
main.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
main.o: /usr/include/netinet/in.h
server.o: server.c
server.o:defs.h
server.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/errno.h
server.o: /usr/include/pwd.h /usr/include/grp.h /usr/include/sys/param.h
server.o: /usr/include/sys/types.h /usr/include/signal.h
server.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
server.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
server.o: /usr/include/netinet/in.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 12
E 1
