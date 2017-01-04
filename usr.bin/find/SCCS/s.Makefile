h49748
s 00001/00001/00060
d D 4.5 87/10/07 09:31:02 bostic 6 5
c fix mkdir line
e
s 00046/00054/00015
d D 4.4 87/06/19 07:13:48 bostic 5 3
c new template
e
s 00047/00054/00015
d R 4.4 87/06/18 17:49:47 bostic 4 3
c new template
e
s 00003/00003/00066
d D 4.3 85/06/01 14:00:02 edward 3 2
c install with -s
e
s 00003/00001/00066
d D 4.2 83/07/21 00:33:16 mckusick 2 1
c minor name changes
e
s 00067/00000/00000
d D 4.1 83/07/21 00:14:42 mckusick 1 0
c date and time created 83/07/21 00:14:42 by mckusick
e
u
U
t
T
I 1
D 5
#	%W%	(Berkeley)	%E%
E 5
#
D 5
DESTDIR=
CFLAGS=	-O
LFLAGS=	

# The programs themselves
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 5
#
D 5
PROG=	find
LIBS=	bigram code

# Sources
E 5
I 5
#	%W%	(Berkeley)	%G%
E 5
#
I 5
CFLAGS=	-O
LIBC=	/lib/libc.a
E 5
SRCS=	find.c bigram.c code.c
I 5
OBJS=	find.o bigram.o code.o
E 5

I 2
D 5
all: ${PROG} ${LIBS}
E 5
I 5
all: find bigram code
E 5

E 2
D 5
find: find.c
	cc ${CFLAGS} -o find find.c
E 5
I 5
find: find.c ${LIBC}
	${CC} ${CFLAGS} -o $@ find.c
E 5

bigram: bigram.c
D 5
	cc ${CFLAGS} -o bigram bigram.c
E 5
I 5
	${CC} ${CFLAGS} -o $@ bigram.c
E 5

code: code.c
D 5
	cc ${CFLAGS} -o code code.c
E 5
I 5
	${CC} ${CFLAGS} -o $@ code.c
E 5

D 5
install: ${PROG} ${LIBS}
D 3
	install ${PROG} ${DESTDIR}/usr/bin/${PROG}
E 3
I 3
	install -s ${PROG} ${DESTDIR}/usr/bin/${PROG}
E 3
	-mkdir ${DESTDIR}/usr/lib/find
D 3
	install bigram ${DESTDIR}/usr/lib/find/bigram
	install code ${DESTDIR}/usr/lib/find/code
E 3
I 3
	install -s bigram ${DESTDIR}/usr/lib/find/bigram
	install -s code ${DESTDIR}/usr/lib/find/code
E 3
D 2
	install -c -m 755 squeeze.csh ${DESTDIR}/usr/lib/find/squeeze.csh
E 2
I 2
	install -c -m 755 updatedb.csh ${DESTDIR}/usr/lib/find/updatedb
E 5
I 5
clean: FRC
	rm -f ${OBJS} core find bigram code
E 5
E 2

D 5
clean:
	rm -f a.out core ${LIBS} ${PROG}
E 5
I 5
depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}
E 5

D 5
depend:
	cat </dev/null >x.c
	for i in ${SRCS}; do \
		(echo `basename $$i .c`.o: $$i >>makedep; \
		/bin/grep '^#[ 	]*include' x.c $$i | sed \
			-e 's,<\(.*\)>,"/usr/include/\1",' \
			-e 's/:[^"]*"\([^"]*\)".*/: \1/' \
			-e 's/\.c/.o/' >>makedep); done
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep x.c
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 5
I 5
install: FRC
	install -s -o bin -g bin -m 755 find ${DESTDIR}/usr/bin/find
D 6
	-mkdir ${DESTDIR}/usr/lib/find > /dev/null 2>&1
E 6
I 6
	-[ -d ${DESTDIR}/usr/lib/find ] || mkdir ${DESTDIR}/usr/lib/find
E 6
	install -s -o bin -g bin -m 755 bigram ${DESTDIR}/usr/lib/find/bigram
	install -s -o bin -g bin -m 755 code ${DESTDIR}/usr/lib/find/code
	install -c -o bin -g bin -m 755 updatedb.csh ${DESTDIR}/usr/lib/find/updatedb
E 5

D 5
# DO NOT DELETE THIS LINE -- make depend uses it
E 5
I 5
lint: FRC
	lint ${CFLAGS} find.c
	lint ${CFLAGS} bigram.c
	lint ${CFLAGS} code.c
E 5

D 5
find.o: find.c
find.o: /usr/include/stdio.h
find.o: /usr/include/sys/param.h
find.o: /usr/include/sys/dir.h
find.o: /usr/include/sys/stat.h
find.o: /usr/include/signal.h
bigram.o: bigram.c
bigram.o: /usr/include/stdio.h
code.o: code.c
code.o: /usr/include/stdio.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 5
I 5
tags: FRC
	ctags find.c
	ctags -a bigram.c
	ctags -a code.c
	sort -o tags tags

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

find: find.c /usr/include/stdio.h /usr/include/sys/param.h
find: /usr/include/sys/types.h /usr/include/signal.h
find: /usr/include/machine/machparam.h /usr/include/sys/dir.h
find: /usr/include/sys/stat.h /usr/include/pwd.h /usr/include/grp.h
find: /usr/include/utmp.h
bigram: bigram.c /usr/include/stdio.h
code: code.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1
