h12161
s 00017/00008/00009
d D 1.2 87/12/12 17:25:01 bostic 2 1
c new template
e
s 00017/00000/00000
d D 1.1 87/06/06 15:51:16 bostic 1 0
c date and time created 87/06/06 15:51:16 by bostic
e
u
U
f b 
t
T
I 1
D 2
# Kludge Makefile to make just uncompact

E 2
I 2
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 2
DESTDIR=
I 2
SUBDIR=	man compact
E 2

D 2
all: FRC
	cd compact; make ${MFLAGS} uncompact
E 2
I 2
all: ${SUBDIR}
E 2

D 2
depend:
E 2
I 2
${SUBDIR}: FRC
	cd $@; make ${MFLAGS}
E 2

install: FRC
D 2
	cd compact; install -s uncompact ${DESTDIR}/usr/old
E 2
I 2
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
E 2

clean: FRC
D 2
	cd compact; make ${MFLAGS} clean
E 2
I 2
	-for i in ${SUBDIR}; do (echo $$i; cd $$i; make ${MFLAGS} clean); done
E 2

D 2
FRC:
E 2
I 2
depend:
	-for i in ${SUBDIR}; do (echo $$i; cd $$i; make ${MFLAGS} depend); done
E 2

I 2
FRC:
E 2
E 1
