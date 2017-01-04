h48285
s 00003/00002/00054
d D 4.8 99/09/28 17:28:44 msokolov 8 7
c build and install nsquery and don't build nstest
e
s 00000/00000/00056
d D 4.7 99/09/28 17:23:58 msokolov 7 6
c bump it up to 4.7
e
s 00000/00000/00056
d D 4.6 99/09/28 17:23:56 msokolov 6 5
c bump it up to 4.7
e
s 00000/00000/00056
d D 4.5 99/09/28 17:23:55 msokolov 5 4
c bump it up to 4.7
e
s 00000/00000/00056
d D 4.4 99/09/28 17:23:54 msokolov 4 3
c bump it up to 4.7
e
s 00000/00000/00056
d D 4.3 99/09/28 17:23:53 msokolov 3 2
c bump it up to 4.7
e
s 00000/00000/00056
d D 4.2 99/09/28 17:23:52 msokolov 2 1
c bump it up to 4.7
e
s 00056/00000/00000
d D 4.1 99/09/28 17:22:58 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 4.7
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
SRCS=	nsquery.c nstest.c
OBJS=	nsquery.o nstest.o

D 8
all: nsquery nstest nslookup
E 8
I 8
all: nsquery nslookup
E 8

nsquery: ${LIBC}
D 8
	${CC} -o $@ nsquery.c ${RES}
E 8
I 8
	${CC} ${CFLAGS} -o $@ nsquery.c ${RES}
E 8

# test programs and utilities
nstest: ${LIBC}
	@echo "The resolver routines in libc must be compiled with the -DDEBUG"
	@echo "option or nstest will not have any output."
	${CC} -o $@ nstest.c ${RES}

nslookup: FRC
	cd nslookup; make ${MFLAGS} RES=${RES}

clean: FRC
	cd nslookup; make ${MFLAGS} clean
	rm -f ${OBJS} core nsquery nstest

depend: FRC
	cd nslookup; make ${MFLAGS} depend
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	cd nslookup; make ${MFLAGS} DESTDIR=${DESTDIR} install
I 8
	install -s -o bin -g bin -m 755 nsquery ${DESTDIR}/usr/ucb/nsquery
E 8

lint: FRC
	cd nslookup; make ${MFLAGS} lint
	lint ${CFLAGS} ${SRCS}

tags: FRC
	cd nslookup; make ${MFLAGS} tags
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 1
