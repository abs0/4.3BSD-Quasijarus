h36444
s 00002/00002/00076
d D 1.4 87/09/20 12:06:42 bostic 5 4
c owned by games, mode 755
e
s 00001/00004/00077
d D 1.3 87/08/30 09:12:20 bostic 4 3
c better fix for chmod problem; bug report 4.3BSD/games/8
e
s 00050/00042/00031
d D 1.2 87/06/06 14:54:59 bostic 3 1
c new template
e
s 00050/00042/00031
d R 1.2 87/06/03 13:51:09 bostic 2 1
c new template
e
s 00073/00000/00000
d D 1.1 87/06/03 12:22:12 bostic 1 0
c date and time created 87/06/03 12:22:12 by bostic
e
u
U
t
T
I 1
D 3
FORTUNES=	scene obscene
SOURCE=		fortune.c strfile.h strfile.c rnd.c unstr.c $(FORTUNES)
TFILES=		Troff.mac Troff.sed Do_troff
LIBDIR=		/usr/games/lib
BINDIR=		/usr/games
OWN=		arnold
GRP=		arpa
DEFS=
CFLAGS=		-O $(DEFS)
SFLAGS=		-r
TDEV=		-Pver
TROFF=		ditroff $(TDEV)
DESTDIR=
E 3
I 3
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SFLAGS=	-r
TDEV=	-Pver
TROFF=	ditroff ${TDEV}
SRCS=	fortune.c rnd.c strfile.c unstr.c
E 3

all: fortune strfile unstr fortunes.dat

D 3
fortune: fortune.o rnd.o
	$(CC) $(CFLAGS) -o fortune fortune.o rnd.o
E 3
I 3
fortune: fortune.o rnd.o ${LIBC}
	${CC} ${CFLAGS} -o $@ fortune.o rnd.o
E 3

D 3
strfile: strfile.o rnd.o
	$(CC) $(CFLAGS) -o strfile strfile.o rnd.o
E 3
I 3
strfile: strfile.o rnd.o ${LIBC}
	${CC} ${CFLAGS} -o $@ strfile.o rnd.o
E 3

D 3
unstr: unstr.o
	$(CC) $(CFLAGS) -o unstr unstr.o
E 3
I 3
unstr: unstr.o ${LIBC}
	${CC} ${CFLAGS} -o $@ unstr.o
E 3

D 3
fortune.o strfile.o unstr.o: strfile.h

E 3
fortunes.dat: fortunes strfile
D 3
	./strfile $(SFLAGS) fortunes
E 3
I 3
	./strfile ${SFLAGS} fortunes
E 3

D 3
fortunes: $(FORTUNES)
E 3
I 3
fortunes: scene obscene
E 3
D 4
	cp scene fortunes
I 3
	chmod 666 fortunes
E 3
	echo "%-" >> fortunes
	cat obscene >> fortunes
E 4
I 4
	(cat scene; echo "%-"; cat obscene) > fortunes
E 4

D 3
lint:
	lint -hxb $(DEFS) fortune.c rnd.c 2>&1 > fortune.lint
	lint -hxb $(DEFS) strfile.c rnd.c 2>&1 > strfile.lint
	lint -hxb $(DEFS) unstr.c 2>&1 > unstr.lint
E 3
I 3
clean: FRC
	rm -f fortune fortunes fortunes.dat strfile unstr core *.o
	rm -f Oscene Oobscene
E 3

D 3
install: all install.data
	install -s -m 4711 -o daemon fortune $(DESTDIR)$(BINDIR)
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

D 3
install.data: fortunes.dat
	install -m 600 -o daemon fortunes.dat $(DESTDIR)$(LIBDIR)
E 3
I 3
install: FRC
D 5
	install -s -o bin -g bin -m 4711 fortune ${DESTDIR}/usr/games
	install -o bin -g bin -m 600 fortunes.dat ${DESTDIR}/usr/games/lib
E 5
I 5
	install -s -o games -g bin -m 4755 fortune ${DESTDIR}/usr/games
	install -o games -g bin -m 600 fortunes.dat ${DESTDIR}/usr/games/lib
E 5
E 3

D 3
troff: troff.scene troff.obscene
E 3
I 3
lint: FRC
	lint ${CFLAGS} fortune.c rnd.c
	lint ${CFLAGS} strfile.c rnd.c
	lint ${CFLAGS} unstr.c
E 3

D 3
troff.scene:
	./Do_troff scene $(TROFF)
E 3
I 3
tags: FRC
	ctags ${SRCS}
E 3

D 3
troff.obscene:
	./Do_troff obscene $(TROFF)
E 3
I 3
troff: FRC
	./Do_troff scene ${TROFF}
	./Do_troff obscene ${TROFF}
E 3

D 3
clean: sort.clean
	rm -f fortune fortunes fortunes.dat strfile unstr ? core *.o

E 3
sort: sort.scene sort.obscene

sort.scene: strfile unstr
	strfile -oi scene
	mv scene Oscene
	unstr -o scene

sort.obscene: strfile unstr
	strfile -oi obscene
	mv obscene Oobscene
	unstr -o obscene

D 3
sort.clean:
	rm -f Oscene Oobscene
E 3
I 3
FRC:
E 3

D 3
depend:
E 3
I 3
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

fortune.o: fortune.c /usr/include/sys/types.h /usr/include/stdio.h
fortune.o: /usr/include/sys/file.h strfile.h
rnd.o: rnd.c
strfile.o: strfile.c /usr/include/stdio.h /usr/include/ctype.h strfile.h
unstr.o: unstr.c /usr/include/stdio.h strfile.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
