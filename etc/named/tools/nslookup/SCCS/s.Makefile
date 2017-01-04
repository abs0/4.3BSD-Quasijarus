h39262
s 00004/00010/00040
d D 5.17 99/09/29 14:39:58 msokolov 17 16
c nslookup is not "local"
c man pages move to /usr/src/man
e
s 00000/00000/00050
d D 5.16 99/09/29 14:31:30 msokolov 16 15
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.15 99/09/29 14:31:28 msokolov 15 14
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.14 99/09/29 14:31:27 msokolov 14 13
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.13 99/09/29 14:31:26 msokolov 13 12
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.12 99/09/29 14:31:25 msokolov 12 11
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.11 99/09/29 14:31:24 msokolov 11 10
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.10 99/09/29 14:31:23 msokolov 10 9
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.9 99/09/29 14:31:22 msokolov 9 8
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.8 99/09/29 14:31:21 msokolov 8 7
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.7 99/09/29 14:31:20 msokolov 7 6
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.6 99/09/29 14:31:19 msokolov 6 5
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.5 99/09/29 14:31:18 msokolov 5 4
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.4 99/09/29 14:31:17 msokolov 4 3
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.3 99/09/29 14:31:16 msokolov 3 2
c bump it up to 5.16
e
s 00000/00000/00050
d D 5.2 99/09/29 14:31:14 msokolov 2 1
c bump it up to 5.16
e
s 00050/00000/00000
d D 5.1 99/09/29 14:29:56 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 5.16
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
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
#	%W% (Berkeley) %G%
#
CFLAGS=	-O
RES=
LIBC=	/lib/libc.a
LIBS=	-ll ${RES}
CSRCS=	main.c getinfo.c debug.c send.c skip.c list.c subr.c
SRCS=	${CSRCS} commands.c
OBJS=	main.o getinfo.o debug.o send.o skip.o list.o subr.o commands.o

D 17
.SUFFIXES: .1 .0

.1.0:
	${DESTDIR}/usr/man/manroff $*.1 > $*.0

E 17
nslookup: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS} ${LIBS}

clean: FRC
D 17
	rm -f ${OBJS} core nslookup commands.c nslookup.0 lex.yy.c lex.yy.o
E 17
I 17
	rm -f ${OBJS} core nslookup commands.c lex.yy.c lex.yy.o
E 17

depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}

D 17
install: nslookup.0 FRC
	install -s -o bin -g bin -m 755 nslookup ${DESTDIR}/usr/local/nslookup
	install -c -o bin -g bin -m 444 nslookup.help ${DESTDIR}/usr/local/nslookup.help
	install -c -o bin -g bin -m 444 nslookup.0 ${DESTDIR}/usr/local/man/cat1/nslookup.0
E 17
I 17
install: nslookup FRC
	install -s -o bin -g bin -m 755 nslookup ${DESTDIR}/usr/ucb/nslookup
	install -c -o bin -g bin -m 444 nslookup.help ${DESTDIR}/usr/lib/nslookup.help
E 17

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${CSRCS} FRC
	ctags ${CSRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 1
