h38191
s 00042/00011/00019
d D 5.3 87/06/16 19:28:33 bostic 3 2
c new template
e
s 00002/00000/00028
d D 5.2 87/05/31 21:07:45 bostic 2 1
c added depend label
e
s 00028/00000/00000
d D 5.1 87/03/16 18:00:32 bostic 1 0
c date and time created 87/03/16 18:00:32 by bostic
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
DESTDIR=
CFLAGS=-O -I.
I 3
LIBC=	/lib/libc.a
E 3
SRCS=	C.c ctags.c fortran.c lisp.c print.c tree.c yacc.c
OBJS=	C.o ctags.o fortran.o lisp.o print.o tree.o yacc.o

D 3
ctags: ${OBJS}
E 3
I 3
all: ctags

ctags: ${OBJS} ${LIBC}
E 3
	${CC} ${CFLAGS} -o $@ ${OBJS}

D 3
install: ctags
	install -o root -g staff -m 755 -s ctags ${DESTDIR}/usr/ucb
E 3
I 3
install: FRC
	install -s -o bin -g bin -m 755 ctags ${DESTDIR}/usr/ucb/ctags
E 3

D 3
clean:
	rm -f ctags *.o core
E 3
I 3
clean: FRC
	rm -f ${OBJS} core ctags
E 3

D 3
lint:
	lint -I. -chapbx ${SRCS}
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 3

D 3
tags:
	ctags -dt ${SRCS}
E 3
I 3
tags: FRC
	ctags ${SRCS}
E 3

I 2
D 3
depend:
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

E 2
D 3
${OBJS}: ctags.h
E 3
I 3
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

C.o: C.c /usr/include/stdio.h
C.o:ctags.h
C.o: /usr/include/stdio.h /usr/include/ctype.h
ctags.o: ctags.c
ctags.o:ctags.h
ctags.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
fortran.o: fortran.c
fortran.o:ctags.h
fortran.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
lisp.o: lisp.c
lisp.o:ctags.h
lisp.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
print.o: print.c /usr/include/sys/types.h /usr/include/sys/file.h
print.o:ctags.h
print.o: /usr/include/stdio.h /usr/include/ctype.h
tree.o: tree.c
tree.o:ctags.h
tree.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h
yacc.o: yacc.c
yacc.o:ctags.h
yacc.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/strings.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
