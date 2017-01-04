h17820
s 00042/00013/00017
d D 1.3 87/06/06 15:46:58 bostic 5 2
c new template
e
s 00002/00000/00030
d R 1.3 87/05/30 14:15:10 bostic 4 2
c added depend label
e
s 00002/00002/00028
d R 1.3 86/08/14 19:13:05 sam 3 2
c make opcode an enum and cleanup a bunch of code so that 
c dbx is more useful (i.e. can step over part of a line of code); add 
c tempreg and has[[23]ops macros; force clr to check acc when writing dest
e
s 00002/00002/00028
d D 1.2 86/07/31 22:58:08 sam 2 1
c purge -g
e
s 00030/00000/00000
d D 1.1 86/03/02 15:30:40 sam 1 0
c date and time created 86/03/02 15:30:40 by sam
e
u
U
t
T
I 1
D 5
#	%M%	%I%	%E%
E 5
#
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 5
DESTDIR=
D 2
CFLAGS=	-g
LDFLAGS=-g
E 2
I 2
CFLAGS=	-O
D 5
LDFLAGS=
E 5
I 5
SRCS=	c20.c c21.c c22.c c23.c
OBJS=	c20.o c21.o c22.o c23.o
E 5
E 2

D 5
c2:	c20.o c21.o c22.o c23.o
	$(CC) $(LDFLAGS) -o c2 c2?.o
E 5
I 5
all: c2
c2: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}
E 5

D 5
c20.o:	c20.c c2.h
c21.o:	c21.c c2.h
c22.o:  c22.c c2.h
c23.o:  c23.c c2.h
	$(CC) $(CFLAGS) -R -c c23.c
E 5
I 5
c23.o:  c23.c
	${CC} ${CFLAGS} -R -c c23.c
E 5

c2.h:	tokens
	grep -n '^' tokens>toks
	( echo '/tokens/+1;/^$$/-1d'; \
	echo '/tokens/r toks'; \
	echo '/tokens/+1;/^$$/-1s/^\([0-9]*\):\([A-Z][A-Z0-9]*\)/#define \2	\1/'; \
	echo 'w'; \
	echo 'q'; \
	) | ed - c2.h
	rm toks

D 5
clean:
	rm -f *.o *.s 
E 5
I 5
clean: FRC
	rm -f *.o *.s c2
E 5

D 5
install: c2
	install -s c2 ${DESTDIR}/lib/c2
E 5
I 5
install: FRC
	install -s -o bin -g bin -m 755 c2 ${DESTDIR}/lib/c2

tags: FRC
	ctags ${SRCS}

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

c20.o: c20.c
c20.o:c2.h
c20.o: /usr/include/stdio.h /usr/include/ctype.h
c21.o: c21.c
c21.o:c2.h
c21.o: /usr/include/stdio.h /usr/include/ctype.h
c22.o: c22.c
c22.o:c2.h
c22.o: /usr/include/stdio.h /usr/include/ctype.h
c23.o: c23.c
c23.o:c2.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1
