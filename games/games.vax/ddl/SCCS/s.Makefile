h51609
s 00002/00004/00013
d D 5.2 87/06/03 17:36:39 bostic 2 1
c added depend label
e
s 00017/00000/00000
d D 5.1 86/02/01 16:18:28 mckusick 1 0
c date and time created 86/02/01 16:18:28 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
DESTDIR=

E 2
all:
	@echo "ddlcomp and ddlrun come in binary form only"

install:
D 2
	install -c -m 755 ddlrun ${DESTDIR}/usr/games/lib/ddlrun
E 2
I 2
	install -c -o bin -g bin -m 755 ddlrun ${DESTDIR}/usr/games/lib/ddlrun
E 2

clean:
D 2
	
E 2
I 2
depend:
E 2
E 1
