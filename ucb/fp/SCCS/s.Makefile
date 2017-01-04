h05584
s 00027/00000/00000
d D 5.1 87/12/23 13:59:14 bostic 1 0
c date and time created 87/12/23 13:59:14 by bostic
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
all: FRC
	cd fp.${MACHINE}; make ${MFLAGS}

install: FRC
	cd fp.${MACHINE}; make DESTDIR=${DESTDIR} install

clean: FRC
	cd fp.${MACHINE}; make ${MFLAGS} clean

depend: FRC
	cd fp.${MACHINE}; make ${MFLAGS} depend

FRC:

E 1
