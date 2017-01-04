h34024
s 00036/00010/00005
d D 4.3 87/06/18 15:44:41 bostic 3 2
c new template
e
s 00003/00001/00012
d D 4.2 87/05/31 21:28:23 bostic 2 1
c added depend label
e
s 00013/00000/00000
d D 4.1 83/02/10 21:00:45 shannon 1 0
c date and time created 83/02/10 21:00:45 by shannon
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
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
SRCS=	diff3.c
OBJS=	diff3.o
E 3

D 3
CFLAGS=-O
E 3
I 3
all: diff3
E 3

D 3
diff3: diff3.o
	cc -o diff3 diff3.o
E 3
I 3
diff3: diff3.c ${LIBC}
	${CC} ${CFLAGS} -o $@ diff3.c
E 3

D 3
install: diff3
	install -s diff3 $(DESTDIR)/usr/lib
	install -c diff3.sh $(DESTDIR)/usr/bin/diff3
E 3
I 3
clean: FRC
	rm -f ${OBJS} core diff3
E 3

D 3
clean:
D 2
	rm -f diff3.o diff3	
E 2
I 2
	rm -f diff3.o diff3
E 3
I 3
depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}
E 3

D 3
depend:
E 3
I 3
install: FRC
	install -s -o bin -g bin -m 755 diff3 $(DESTDIR)/usr/lib/diff3
	install -c -o bin -g bin -m 755 diff3.sh $(DESTDIR)/usr/bin/diff3

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

diff3: diff3.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1
