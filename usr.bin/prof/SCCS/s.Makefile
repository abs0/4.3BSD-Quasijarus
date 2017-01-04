h57647
s 00039/00013/00005
d D 4.3 87/06/18 22:39:52 bostic 3 2
c new template
e
s 00003/00001/00015
d D 4.2 87/05/31 21:32:00 bostic 2 1
c added depend label
e
s 00016/00000/00000
d D 4.1 83/06/02 16:53:27 sam 1 0
c date and time created 83/06/02 16:53:27 by sam
e
u
U
t
T
I 1
D 3
#	%W% (Berkeley) %G%
E 3
#
D 3
# If you don't want to plot, take out the -Dplot and the ref. to plot.a
PLOT = -lplot -Dplot
CFLAGS=-O 
prof:	prof.o
	$(CC) -o prof prof.o $(PLOT)
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
# If you don't want to plot, take out the -Dplot and the loader
# reference to plot.a
CFLAGS=	-O -Dplot
LIBC=	/lib/libc.a
SRCS=	prof.c
OBJS=	prof.o
E 3

D 3
prof.o: prof.c
	cc -c $(CFLAGS) $(PLOT) prof.c
E 3
I 3
all: prof
E 3

D 3
install:
	install -s prof $(DESTDIR)/usr/bin
E 3
I 3
prof: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} -lplot
E 3

D 2
clean :
E 2
I 2
D 3
clean:
E 2
	rm -f *.o prof
E 3
I 3
clean: FRC
	rm -f ${OBJS} core prof
E 3
I 2

D 3
depend:
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 prof ${DESTDIR}/usr/bin/prof

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

prof.o: prof.c /usr/include/stdio.h /usr/include/sys/types.h
prof.o: /usr/include/sys/stat.h /usr/include/a.out.h /usr/include/sys/exec.h
prof.o: /usr/include/sys/time.h /usr/include/time.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1
