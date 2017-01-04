h31808
s 00031/00000/00000
d D 1.1 02/05/24 22:27:12 msokolov 1 0
c date and time created 02/05/24 22:27:12 by msokolov
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
MSLIB=	/usr/lib/ms
TMLIB=	/usr/lib/tmac
MSSRCS=	acc.ms cov.ms eqn.ms ref.ms tbl.ms ths.ms toc.ms
TMSRCS=	tmac.s tmac.scover tmac.sdisp tmac.skeep tmac.srefs

all:

install: FRC
	-[ -d ${DESTDIR}${MSLIB} ] || mkdir ${DESTDIR}${MSLIB}
	-[ -d ${DESTDIR}${TMLIB} ] || mkdir ${DESTDIR}${TMLIB}
	chown bin.bin ${DESTDIR}${MSLIB} ${DESTDIR}${TMLIB}
	chmod 755 ${DESTDIR}${MSLIB} ${DESTDIR}${TMLIB}
	install -c -o bin -g bin -m 444 ${MSSRCS} ${DESTDIR}${MSLIB}
	install -c -o bin -g bin -m 444 ${TMSRCS} ${DESTDIR}${TMLIB}

clean:
depend:
FRC:
E 1
