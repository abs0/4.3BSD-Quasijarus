h10539
s 00010/00005/00052
d D 5.6 88/06/18 14:00:46 bostic 14 13
c install approved copyright notice
e
s 00015/00007/00042
d D 5.5 88/02/23 15:26:25 bostic 13 12
c add Berkeley specific header
e
s 00032/00021/00017
d D 5.4 87/06/02 21:49:56 bostic 12 10
c new template
e
s 00032/00021/00017
d R 5.4 87/06/02 20:32:24 bostic 11 10
c new template
e
s 00002/00000/00036
d D 5.3 87/05/31 20:39:53 bostic 10 9
c added depend label
e
s 00001/00001/00035
d D 5.2 85/09/18 02:17:09 lepreau 9 8
c clean should remove lex and yacc output
e
s 00007/00001/00029
d D 5.1 85/04/29 12:49:57 dist 8 7
c Add copyright
e
s 00001/00002/00029
d D 4.6 83/11/03 12:21:45 karels 7 6
c calculate connectivity of gateways to find multi-hop gateways;
c read localgateways and use in eliminating dups and gateways remote from them;
c take local nets and connected nets in args, not compiled in.
e
s 00000/00000/00031
d D 4.5 83/05/28 10:50:01 mo 6 4
c put stupid  LOCALNET define back in Makefile
e
s 00001/00001/00030
d R 4.5 83/05/28 10:44:58 mo 5 4
c removed LOCALNET define in makefile
e
s 00001/00005/00030
d D 4.4 83/05/04 14:33:08 sam 4 3
c gettable moves up one level
e
s 00007/00003/00028
d D 4.3 82/12/31 10:52:36 sam 3 2
c add gettable and strip targets
e
s 00002/00001/00029
d D 4.2 82/10/21 14:33:48 sam 2 1
c DESTDIR
e
s 00030/00000/00000
d D 4.1 82/10/20 21:27:51 sam 1 0
c date and time created 82/10/20 21:27:51 by sam
e
u
U
t
T
I 1
D 8
# %W% %G%
E 8
I 8
#
D 12
# Copyright (c) 1980 Regents of the University of California.
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
E 8
D 7
OPTIONS=-DLOCALNET=46
E 7
CFLAGS=	-O
I 2
D 12
DESTDIR=
E 2
D 3
ALL=	htable
E 3
I 3
D 4
ALL=	htable gettable
E 4
I 4
ALL=	htable
E 12
I 12
LIBC=	/lib/libc.a
SRCS=	htable.c parse.c scan.c
OBJS=	htable.o parse.o scan.o
E 12
E 4
E 3

D 3
all:	htable
E 3
I 3
D 12
all:	${ALL}
E 12
I 12
all: htable
E 12
E 3

D 12
htable:	htable.o parse.o scan.o
	${CC} htable.o parse.o scan.o -o htable
E 12
I 12
htable: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 12

I 3
D 4
gettable: gettable.o
	${CC} gettable.o -o gettable

E 4
E 3
D 12
htable.o: htable.c htable.h
D 7
	${CC} ${CFLAGS} ${OPTIONS} -c htable.c
E 7
I 7
	${CC} ${CFLAGS} -c htable.c
E 12
I 12
y.tab.h:
	yacc -d parse.y
	rm -f y.tab.c
E 12
E 7

D 12
scan.o:	scan.c htable.h y.tab.h
E 12
I 12
clean: FRC
	rm -f ${OBJS} core htable parse.c scan.c y.tab.h
E 12

D 12
parse.o: parse.c htable.h
E 12
I 12
depend: ${SRCS} y.tab.h FRC
	mkdep ${CFLAGS} ${SRCS}
E 12

D 12
scan.c:	scan.l
E 12
I 12
install: FRC
	install -s -o bin -g bin -m 755 htable ${DESTDIR}/etc/htable
E 12

D 12
parse.c: parse.y
E 12
I 12
D 13
lint: FRC
E 13
I 13
lint: ${SRCS} FRC
E 13
	lint ${CFLAGS} ${SRCS}
E 12

D 12
y.tab.h:
	${YACC} -d parse.y
	rm y.tab.c
E 12
I 12
tags: FRC
	ctags ${SRCS}
E 12

D 12
clean:
D 9
	rm -f ${ALL} *.o *.s y.tab.h errs
E 9
I 9
	rm -f ${ALL} *.o *.s parse.c scan.c y.tab.h errs
E 12
I 12
FRC:
E 12
E 9

D 12
install:
D 2
	install htable /etc
E 2
I 2
D 3
	install htable ${DESTDIR}/etc
E 3
I 3
	install -s htable ${DESTDIR}/etc/htable
E 12
I 12
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 12
I 10

D 12
depend:
E 12
I 12
htable.o: htable.c /usr/include/stdio.h /usr/include/ctype.h
htable.o: /usr/include/errno.h /usr/include/netdb.h htable.h
D 13
htable.o: /usr/include/sys/types.h /usr/include/sys/socket.h
htable.o: /usr/include/netinet/in.h
parse.o: parse.c htable.h /usr/include/sys/types.h /usr/include/stdio.h
E 13
I 13
htable.o: /usr/include/sys/types.h /usr/include/netinet/in.h
htable.o: /usr/include/sys/socket.h /usr/include/arpa/inet.h
parse.o: parse.c htable.h /usr/include/sys/types.h /usr/include/netinet/in.h
parse.o: /usr/include/stdio.h
E 13
scan.o: scan.c /usr/include/stdio.h y.tab.h htable.h /usr/include/sys/types.h
I 13
scan.o: /usr/include/netinet/in.h
E 13

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 12
E 10
D 4
	install -s gettable ${DESTDIR}/etc/gettable
E 4
E 3
E 2
E 1
