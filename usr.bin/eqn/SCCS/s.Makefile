h18284
s 00007/00003/00021
d D 5.4 2012/02/19 18:41:21 msokolov 4 3
c eqnchar added
e
s 00002/00002/00022
d D 5.3 2012/02/16 03:54:09 msokolov 3 2
c call the CAT eqn object directory cat
e
s 00001/00001/00023
d D 5.2 04/09/17 22:13:48 msokolov 2 1
c add pseqn
e
s 00024/00000/00000
d D 5.1 87/12/12 17:36:15 bostic 1 0
c date and time created 87/12/12 17:36:15 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 3
#	%W%	(Berkeley)	%G%
E 3
I 3
#	%W%	(Berkeley)	%E%
E 3
#
D 2
SUBDIR=	eqn neqn
E 2
I 2
D 3
SUBDIR=	eqn neqn pseqn
E 3
I 3
D 4
SUBDIR=	cat neqn pseqn
E 4
I 4
SUBDIR=	cat eqnchar neqn pseqn
E 4
E 3
E 2

D 4
all: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS}); done
E 4
I 4
all:	${SUBDIR}

eqnchar: pseqn

${SUBDIR}: FRC
	cd $@; make ${MFLAGS}
E 4

install: FRC
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done

clean: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

depend: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done

FRC:
E 1
