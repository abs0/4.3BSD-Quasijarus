h50548
s 00002/00000/00026
d D 5.4 87/06/03 17:37:04 bostic 6 5
c added depend label
e
s 00003/00003/00023
d D 5.3 85/06/23 15:26:49 mckusick 5 4
c fix DESTDIR botch
e
s 00004/00009/00022
d D 5.2 85/06/05 11:04:52 mckusick 4 3
c renaming and cleanups
e
s 00007/00000/00024
d D 5.1 85/05/30 17:53:53 mckusick 3 2
c Add copyright
e
s 00002/00002/00022
d D 1.2 85/04/17 21:29:36 bloom 2 1
c owner is daemon
e
s 00024/00000/00000
d D 1.1 85/04/05 16:54:54 arnold 1 0
c date and time created 85/04/05 16:54:54 by arnold
e
u
U
t
T
I 3
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 3
I 1
D 4
OBJS=		main.o machdep.o
E 4
I 4
OBJS=		main.obj machdep.o
E 4

D 5
SCOREFILE=	/usr/games/lib/rogue_roll
E 5
I 5
GAMESDIR=	$(DESTDIR)/usr/games
SCOREFILE=	$(DESTDIR)/usr/games/lib/rogue_roll
E 5
DEFS=		-DSCOREFILE='"$(SCOREFILE)"'
CFLAGS=		-O $(DEFS)
D 5
DESTDIR=	/usr/games
E 5

NROFF=	nroff
TROFF=	ditroff

rogue:	$(OBJS)
	$(CC) $(CFLAGS) -o rogue $(OBJS) -lcurses -ltermlib

D 4
doc.nroff: rogue.doc
	tbl rogue.doc | $(NROFF) -me -Tcrt > doc.nroff

doc.troff: rogue.doc
	tbl rogue.doc | $(TROFF) -me

all:	rogue doc.nroff doc.troff

E 4
install: rogue
D 2
	install -s -o games -m 4711 rogue $(DESTDIR)
	install -c -o games -m 644 /dev/null $(SCOREFILE)
E 2
I 2
D 5
	install -s -o daemon -m 4711 rogue $(DESTDIR)
E 5
I 5
	install -s -o daemon -m 4711 rogue $(GAMESDIR)
E 5
	install -c -o daemon -m 644 /dev/null $(SCOREFILE)
I 4

clean:
	rm -f rogue machdep.o
I 6

depend:
E 6
E 4
E 2
E 1
