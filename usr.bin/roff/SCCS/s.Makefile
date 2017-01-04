h16623
s 00030/00000/00000
d D 5.1 87/12/12 17:37:39 bostic 1 0
c date and time created 87/12/12 17:37:39 by bostic
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
SUBDIR=	nroff troff nroff_term troff_font

all: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS}); done

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
