h03994
s 00037/00003/00002
d D 5.2 87/06/18 22:22:25 bostic 2 1
c new template
e
s 00005/00000/00000
d D 5.1 86/06/06 20:15:53 mckusick 1 0
c date and time created 86/06/06 20:15:53 by mckusick
e
u
U
t
T
I 1
#
D 2
#	%W% %G%
E 2
I 2
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 2
#
D 2
mkfont: mkfont.o
	cc mkfont.o -o mkfont
E 2
I 2
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	mkfont.c
OBJS=	mkfont.o

all: mkfont

mkfont: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}

clean: FRC
	rm -f ${OBJS} core mkfont

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

mkfont.o: mkfont.c mkfont1.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 2
E 1
