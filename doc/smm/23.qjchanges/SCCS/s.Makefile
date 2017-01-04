h62376
s 00010/00003/00029
d D 6.2 04/09/13 03:11:39 msokolov 2 1
c pstroff and nroff8 are here!
e
s 00032/00000/00000
d D 6.1 03/12/04 14:30:09 msokolov 1 0
c date and time created 03/12/04 14:30:09 by msokolov
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
D 2
NROFF=	nroff
E 2
I 2
TROFF=	pstroff
NROFF=	nroff8 -Tcol8
COL=	col8 -b
E 2

SRC=	title.t 0a.t 0b.t

I 2
all:	qjchanges.ps qjchanges.txt

qjchanges.ps: ${SRC}
	${TROFF} -ms ${SRC} > qjchanges.ps

E 2
qjchanges.txt: ${SRC}
D 2
	${NROFF} -ms ${SRC} | colcrt - > qjchanges.txt
E 2
I 2
	${NROFF} -ms ${SRC} | ${COL} > qjchanges.txt
E 2

clean:
D 2
	rm -f qjchanges.txt ?.t.spell errs Errs
E 2
I 2
	rm -f qjchanges.ps qjchanges.txt ?.t.spell errs Errs
E 2

spell:	${SRC}
	@for i in ${SRC}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
