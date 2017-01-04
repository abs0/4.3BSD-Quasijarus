h17780
s 00030/00040/00021
d D 7.3 87/06/02 21:53:11 bostic 4 2
c new template
e
s 00029/00039/00022
d R 7.3 87/06/02 20:45:49 bostic 3 2
c new template
e
s 00002/00002/00059
d D 7.2 87/01/08 22:55:05 karels 2 1
c typo
e
s 00061/00000/00000
d D 7.1 87/01/08 22:42:15 karels 1 0
c date and time created 87/01/08 22:42:15 by karels
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
#
D 4
DESTDIR=
E 4
CFLAGS=	-O
D 4
LDFLAGS=	

E 4
I 4
LIBC=	/lib/libc.a
E 4
SRCS=	newfs.c mkfs.c
OBJS=	newfs.o mkfs.o

all: newfs

D 2
newfs: ${OBJS}}
	cc ${LDFLAGS} ${CFLAGS} -o newfs ${OBJS}}
E 2
I 2
D 4
newfs: ${OBJS}
	cc ${LDFLAGS} ${CFLAGS} -o newfs ${OBJS}
E 4
I 4
newfs: ${OBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${OBJS}
E 4
E 2

D 4
install: all
	install -s newfs ${DESTDIR}/etc/newfs
E 4
I 4
clean: FRC
	rm -f ${OBJS} core newfs
E 4

D 4
clean:
	rm -f newfs *.o errs a.out core
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 4

D 4
lint:
	lint ${SRCS}
E 4
I 4
install: FRC
	install -s -o bin -g bin -m 755 newfs ${DESTDIR}/etc/newfs
E 4

D 4
depend:
	cc -M ${INCPATH} ${SRCS} | \
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 4
I 4
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 4

D 4
# DO NOT DELETE THIS LINE -- make depend uses it
E 4
I 4
tags: FRC
	ctags ${SRCS}
E 4

I 4
FRC:
E 4

D 4
newfs.o: newfs.c /usr/include/sys/param.h /usr/include/machine/machparam.h
newfs.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/stat.h
newfs.o: /usr/include/sys/fs.h /usr/include/sys/dir.h /usr/include/sys/ioctl.h
newfs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
newfs.o: /usr/include/sys/disklabel.h /usr/include/sys/file.h
newfs.o: /usr/include/stdio.h /usr/include/ctype.h
E 4
I 4
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

newfs.o: newfs.c /usr/include/sys/param.h /usr/include/sys/types.h
newfs.o: /usr/include/signal.h /usr/include/machine/machparam.h
newfs.o: /usr/include/sys/stat.h /usr/include/sys/fs.h /usr/include/sys/dir.h
newfs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
newfs.o: /usr/include/sys/ttydev.h /usr/include/sys/disklabel.h
newfs.o: /usr/include/sys/file.h /usr/include/stdio.h /usr/include/ctype.h
E 4
mkfs.o: mkfs.c /usr/include/stdio.h /usr/include/a.out.h
mkfs.o: /usr/include/sys/exec.h /usr/include/sys/param.h
D 4
mkfs.o: /usr/include/machine/machparam.h /usr/include/signal.h
mkfs.o: /usr/include/sys/types.h /usr/include/sys/inode.h /usr/include/sys/fs.h
mkfs.o: /usr/include/sys/dir.h /usr/include/sys/disklabel.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 4
I 4
mkfs.o: /usr/include/sys/types.h /usr/include/signal.h
mkfs.o: /usr/include/machine/machparam.h /usr/include/sys/inode.h
mkfs.o: /usr/include/sys/fs.h /usr/include/sys/dir.h
mkfs.o: /usr/include/sys/disklabel.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1
