h29392
s 00053/00014/00014
d D 4.3 87/06/29 11:52:55 bostic 4 2
c new template
e
s 00053/00014/00014
d R 4.3 87/06/03 00:07:09 bostic 3 2
c new template
e
s 00002/00000/00026
d D 4.2 87/05/31 20:33:01 bostic 2 1
c added depend label
e
s 00026/00000/00000
d D 4.1 83/02/09 14:25:06 sam 1 0
c date and time created 83/02/09 14:25:06 by sam
e
u
U
t
T
I 1
D 4
#	%W%	%G%
E 4
#
I 4
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 4
DIFF=	/bin/diff
DIFFH=	/usr/lib/diffh
PR=	/bin/pr
CFLAGS=	-O -DDIFF='"${DIFF}"' -DDIFFH='"${DIFFH}"' -DPR='"${PR}"'
D 4
DESTDIR=

E 4
I 4
LIBC=	/lib/libc.a
E 4
SRCS=	diff.c diffdir.c diffreg.c
D 4
HDRS=	diff.h
E 4
OBJS=	diff.o diffdir.o diffreg.o
I 4
HSRCS=	diffh.c
HOBJS=	diffh.o
E 4

all: diff diffh

D 4
diff: ${OBJS}
	cc ${CFLAGS} -o diff ${OBJS} ${LDFLAGS}
E 4
I 4
diff: ${OBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${OBJS}
E 4

D 4
diffh: diffh.o
	cc -o diffh diffh.o ${LDFLAGS}
E 4
I 4
diffh: ${HOBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${HOBJS}
E 4

I 2
D 4
depend:
E 4
I 4
clean: FRC
	rm -f ${HOBJS} ${OBJS} core diff diffh
E 4

E 2
D 4
clean:
	rm -f diff diffh ${OBJS} diffh.o
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${HSRCS} ${SRCS}
E 4

D 4
install:
	install -s diff ${DESTDIR}/bin/diff
	install -s diffh ${DESTDIR}/usr/lib/diffh
E 4
I 4
install: FRC
	install -s -o bin -g bin -m 755 diff ${DESTDIR}/bin/diff
	install -s -o bin -g bin -m 755 diffh ${DESTDIR}/usr/lib/diffh

lint: FRC
	lint ${CFLAGS} ${SRCS}
	lint ${CFLAGS} ${HSRCS}

tags: FRC
	ctags ${SRCS}
	ctags ${HSRCS}
	sort -o tags tags

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

diffh.o: diffh.c /usr/include/stdio.h /usr/include/ctype.h
diffh.o: /usr/include/sys/types.h /usr/include/sys/stat.h
diff.o: diff.c diff.h /usr/include/stdio.h /usr/include/ctype.h
diff.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
diff.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
diff.o: /usr/include/sys/dir.h /usr/include/signal.h
diffdir.o: diffdir.c diff.h /usr/include/stdio.h /usr/include/ctype.h
diffdir.o: /usr/include/sys/param.h /usr/include/sys/types.h
diffdir.o: /usr/include/signal.h /usr/include/machine/machparam.h
diffdir.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/signal.h
diffdir.o: /usr/include/a.out.h /usr/include/sys/exec.h
diffreg.o: diffreg.c diff.h /usr/include/stdio.h /usr/include/ctype.h
diffreg.o: /usr/include/sys/param.h /usr/include/sys/types.h
diffreg.o: /usr/include/signal.h /usr/include/machine/machparam.h
diffreg.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/signal.h
diffreg.o: /usr/include/a.out.h /usr/include/sys/exec.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1
