h50010
s 00021/00010/00024
d D 5.4 87/10/27 07:47:45 bostic 10 7
c new template, pass depend on down
e
s 00015/00006/00028
d R 5.4 87/10/26 07:43:42 bostic 9 7
c new template
e
s 00011/00006/00028
d R 5.4 87/10/26 07:42:42 bostic 8 7
c new template
e
s 00002/00000/00032
d D 5.3 87/05/31 21:12:55 bostic 7 6
c added depend label
e
s 00004/00001/00028
d D 5.2 87/05/10 16:20:59 mckusick 6 5
c update from Jim McKie
e
s 00006/00001/00023
d D 5.1 85/06/04 14:06:57 mckusick 5 4
c Add copyright
e
s 00001/00001/00023
d D 1.4 85/06/04 13:37:50 mckusick 4 3
c eyacc moves into Pascal
e
s 00005/00002/00019
d D 1.3 83/04/17 14:11:09 peter 3 2
c record subdirectory names in the output as you get to them.
e
s 00001/00001/00020
d D 1.2 83/02/03 18:07:02 mckusick 2 1
c pascal is renamed to utilities
e
s 00021/00000/00000
d D 1.1 83/01/31 18:05:04 mckusick 1 0
c date and time created 83/01/31 18:05:04 by mckusick
e
u
U
t
T
I 1
D 5
#	%W%	(Berkeley)	%G%
E 5
I 5
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 5
#
D 10
DESTDIR=
E 10
CFLAGS=	-O

# Programs that live in subdirectories, and have makefiles of their own.
#
D 2
SUBDIR=	pi pc0 px pxp pdx pascal
E 2
I 2
D 4
SUBDIR=	pi pc0 px pxp pdx utilities
E 4
I 4
D 10
SUBDIR=	eyacc pi pc0 px pxp pdx utilities
E 10
I 10
SUBDIR=	pi pc0 px pxp pdx utilities
E 10
E 4
E 2

D 6
all:	${SUBDIR}
E 6
I 6
all:
D 10
	for i in ${SUBDIR}; do \
E 10
I 10
	for i in eyacc ${SUBDIR}; do \
E 10
		(cd $$i; make ${MFLAGS}); \
	done
E 6

D 10
${SUBDIR}: /tmp
E 10
I 10
${SUBDIR}: FRC
E 10
	cd $@; make ${MFLAGS}

D 10
install:
	for i in ${SUBDIR}; do \
D 3
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
E 3
I 3
		(echo $$i; cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
E 10
I 10
tags: FRC
	for i in eyacc ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} tags); \
E 10
	done
E 3

D 10
clean:
E 10
I 10
install: FRC
	for i in eyacc ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done

clean: FRC
E 10
	rm -f a.out core *.s *.o
D 3
	for i in ${SUBDIR}; do (echo $$i; cd $$i; make ${MFLAGS} clean); done
E 3
I 3
D 10
	for i in ${SUBDIR}; do \
		(echo $$i; cd $$i; make ${MFLAGS} clean); \
E 10
I 10
	for i in eyacc ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} clean); \
E 10
	done
I 7

depend:
I 10
	(cd eyacc; make ${MFLAGS} depend)
	(cd eyacc; make ${MFLAGS} all)
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} depend); \
	done

FRC:
E 10
E 7
E 3
E 1
