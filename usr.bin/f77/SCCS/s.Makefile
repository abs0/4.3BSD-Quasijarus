h51914
s 00001/00001/00023
d D 5.5 99/07/09 20:02:34 msokolov 5 4
c correct SCCS ID keywords
e
s 00002/00002/00022
d D 5.4 87/06/18 17:37:28 bostic 4 3
c remove extra level of Makefiles
e
s 00012/00015/00012
d D 5.3 87/06/18 17:16:19 bostic 3 2
c new template
e
s 00000/00002/00027
d D 5.2 87/05/24 14:42:59 bostic 2 1
c MACHINE defined in make, now
e
s 00029/00000/00000
d D 5.1 87/05/11 09:32:39 mckusick 1 0
c date and time created 87/05/11 09:32:39 by mckusick
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
D 4
#	%W% (Berkeley) %G%
E 4
I 4
D 5
#	@(#)Makefile	5.3 (Berkeley) 6/18/87
E 5
I 5
#	%W% (Berkeley) %G%
E 5
E 4
#
D 3
DESTDIR	      =
E 3
I 3
D 4
SUBDIR=	f77.${MACHINE} fpr fsplit
E 4
I 4
SUBDIR=	f77.${MACHINE}/f77 f77.${MACHINE}/f77pass1 fpr fsplit
E 4
E 3

D 2
MACHINE	      = unknown

E 2
D 3
SUBDIR	      = f77.${MACHINE} fpr fsplit
E 3
I 3
all: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS}); done
E 3

D 3
all:		${SUBDIR}
E 3
I 3
install: FRC
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done
E 3

D 3
${SUBDIR}:	FRC
		cd $@; make ${MFLAGS}
E 3
I 3
clean: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 3

D 3
FRC:
E 3
I 3
depend: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 3

D 3
install:
		for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done

clean:
		for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

depend:
		for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 3
I 3
FRC:
E 3
E 1
