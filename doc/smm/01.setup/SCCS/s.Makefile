h30212
s 00010/00012/00030
d D 5.3 04/09/13 03:04:57 msokolov 3 2
c pstroff and nroff8 are here!
e
s 00021/00006/00021
d D 5.2 03/11/18 22:33:14 msokolov 2 1
c VAX rules!
e
s 00027/00000/00000
d D 5.1 88/07/17 09:37:22 karels 1 0
c date and time created 88/07/17 09:37:22 by karels
e
u
U
t
T
I 1
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
#	%W% (Berkeley) %G%
#
I 2
D 3
PRINTER=-Plz
TROFF=	ditroff ${PRINTER}
EQN=	deqn ${PRINTER}
TBL=	dtbl ${PRINTER}
LPR=	lpr -n ${PRINTER}
E 3
I 3
TROFF=	pstroff
NROFF=	nroff8 -Tcol8
TBL=	tbl
COL=	col8 -b
E 3
E 2

D 2
all:
	cd ${MACHINE}; make ${MFLAGS}
E 2
I 2
SRC=	0.t 1.t 2.t 3.t 4.t 5.t 6.t a.t b.t c.t
E 2

D 2
setup:
	cd ${MACHINE}; make ${MFLAGS} setup
E 2
I 2
D 3
setup.out: ${SRC}
	${EQN} ${SRC} | ${TBL} | ${TROFF} -t -ms > setup.out
E 3
I 3
all:	setup.ps setup.txt
E 3
E 2

I 3
setup.ps: ${SRC}
	${TBL} ${SRC} | ${TROFF} -ms > $@

E 3
D 2
setup.out:
	cd ${MACHINE}; make ${MFLAGS} setup.out
E 2
I 2
setup.txt: ${SRC}
D 3
	neqn ${SRC} | tbl | nroff -ms | colcrt - > setup.txt
E 3
I 3
	${TBL} ${SRC} | ${NROFF} -ms | ${COL} > $@
E 3

D 3
setup: setup.out
	${LPR} setup.out

E 3
clean:
D 3
	rm -f setup.out setup.txt ?.t.spell errs Errs
E 3
I 3
	rm -f setup.ps setup.txt ?.t.spell errs Errs
E 3

spell:	${SRC}
	@for i in ${SRC}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 2
E 1
