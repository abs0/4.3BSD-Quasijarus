#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	5.4	(Berkeley)	2012/02/19
#
SUBDIR=	cat eqnchar neqn pseqn

all:	${SUBDIR}

eqnchar: pseqn

${SUBDIR}: FRC
	cd $@; make ${MFLAGS}

install: FRC
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done

clean: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

depend: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done

FRC:
