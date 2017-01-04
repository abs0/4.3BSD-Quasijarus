h62660
s 00001/00001/00026
d D 5.5 87/12/20 13:14:08 bostic 6 5
c don't fail on ddlcomp return
e
s 00005/00002/00022
d D 5.4 87/12/12 17:19:38 bostic 5 4
c integrate with dm
e
s 00015/00009/00009
d D 5.3 87/06/03 17:30:32 bostic 4 3
c new template
e
s 00001/00001/00017
d D 5.2 86/02/01 16:21:14 mckusick 3 2
c clean up spurious aard's
e
s 00006/00001/00012
d D 5.1 85/05/29 11:28:04 dist 2 1
c Add copyright
e
s 00013/00000/00000
d D 4.1 83/08/13 16:28:17 sam 1 0
c date and time created 83/08/13 16:28:17 by sam
e
u
U
t
T
I 1
D 2
#	%M%	%I%	%E%
E 2
I 2
#
D 4
# Copyright (c) 1980 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
E 2
#
D 4
DESTDIR=
E 4

D 4
aard:
E 4
I 4
all: aard

aard: FRC
E 4
D 6
	../ddl/ddlcomp aard < aard.ddl > ddlcomp.out
E 6
I 6
	-../ddl/ddlcomp aard < aard.ddl > ddlcomp.out
E 6

D 4
install:
	install aard ${DESTDIR}/usr/games/lib/aard
	install -c -m 755 frontend ${DESTDIR}/usr/games/aardvark

clean:
E 4
I 4
clean: FRC
E 4
D 3
	rm -f ddlcomp.out
E 3
I 3
	rm -f ddlcomp.out aard
I 4

install: FRC
D 5
	install -o bin -g bin -m 755 aard ${DESTDIR}/usr/games/lib/aard
	install -c -o bin -g bin -m 755 frontend ${DESTDIR}/usr/games/aardvark
E 5
I 5
	install -o games -g bin -m 755 aard ${DESTDIR}/usr/games/lib/aard
	install -c -o games -g bin -m 755 frontend ${DESTDIR}/usr/games/hide/aardvark
	rm -f ${DESTDIR}/usr/games/aardvark
	ln -s ${DESTDIR}/usr/games/dm ${DESTDIR}/usr/games/aardvark
	chown games.bin ${DESTDIR}/usr/games/aardvark
E 5

depend:
lint:
tags:
FRC:
E 4
E 3
E 1
