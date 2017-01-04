h31429
s 00001/00001/00045
d D 4.5 87/09/22 10:46:17 bostic 7 6
c fix mkdir
e
s 00012/00007/00034
d D 4.4 87/09/21 11:55:01 bostic 6 3
c integrate with dm
e
s 00014/00007/00034
d R 4.4 87/09/20 10:47:40 bostic 5 3
c integrate with dm
e
s 00031/00031/00010
d D 4.3 87/06/03 16:47:25 bostic 3 2
c new template
e
s 00001/00001/00040
d D 4.2 85/09/07 21:10:40 mckusick 2 1
c strip on install
e
s 00041/00000/00000
d D 4.1 82/11/28 18:24:30 mckusick 1 0
c date and time created 82/11/28 18:24:30 by mckusick
e
u
U
t
T
I 3
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
E 3
I 1
#	%W%	(Berkeley)	%G%
#
D 3
DESTDIR=
E 3
CFLAGS=	-O
I 3
LIBC=	/lib/libc.a
SRCS=	quiz.c
D 6
OBJS=	quiz.o
E 6
I 6
OBJS=
E 6
E 3

D 3
quiz: quiz.c
	cc ${CFLAGS} -o quiz quiz.c
E 3
I 3
all: quiz
E 3

D 3
install:
D 2
	install quiz ${DESTDIR}/usr/games/quiz
E 2
I 2
	install -s quiz ${DESTDIR}/usr/games/quiz
E 3
I 3
D 6
quiz:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 6
I 6
quiz: ${LIBC}
	${CC} -o $@ ${CFLAGS} ${SRCS}
E 6

clean: FRC
	rm -f ${OBJS} core quiz

depend: FRC
D 6
	mkdep ${CFLAGS} ${SRCS}
E 6
I 6
	mkdep -p ${CFLAGS} ${SRCS}
E 6

install: FRC
D 6
	install -s -o bin -g bin -m 755 quiz ${DESTDIR}/usr/games/quiz
E 3
E 2
	cp -r quiz.k ${DESTDIR}/usr/games/lib
E 6
I 6
D 7
	-mkdir ${DESTDIR}/usr/games/lib/quiz.k > /dev/null 2>&1
E 7
I 7
	-[ -d ${DESTDIR}/usr/games/lib/quiz.k ] || mkdir ${DESTDIR}/usr/games/lib/quiz.k
E 7
	chmod 700 ${DESTDIR}/usr/games/lib/quiz.k
	chown games.bin ${DESTDIR}/usr/games/lib/quiz.k
	cd quiz.k; install -c -o games -g bin -m 400 * ${DESTDIR}/usr/games/lib/quiz.k
	install -s -o games -g bin -m 700 quiz ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f quiz; ln -s dm quiz; chown games.bin quiz)
E 6

D 3
clean:
	rm -f a.out core *.s *.o quiz
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 3

D 3
depend:
	cat </dev/null >x.c
	for i in quiz; do \
		(echo $$i: $$i.c >>makedep; \
		/bin/grep '^#[ 	]*include' x.c $$i.c | sed \
			-e 's,<\(.*\)>,"/usr/include/\1",' \
			-e 's/:[^"]*"\([^"]*\)".*/: \1/' \
			-e 's/\.c//' >>makedep); done
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep x.c
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 3
I 3
tags: FRC
	ctags ${SRCS}
E 3

D 3
# DO NOT DELETE THIS LINE -- make depend uses it
E 3
I 3
FRC:
E 3

D 3
quiz: quiz.c
quiz: /usr/include/stdio.h
quiz: /usr/include/signal.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 3
I 3
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 6
quiz.o: quiz.c /usr/include/stdio.h /usr/include/signal.h
E 6
I 6
quiz: quiz.c /usr/include/stdio.h /usr/include/signal.h
quiz: /usr/include/machine/trap.h
E 6

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
