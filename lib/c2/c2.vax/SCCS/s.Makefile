h04673
s 00001/00001/00036
d D 4.8 00/08/29 19:21:54 msokolov 8 7
c oops, make depend must depend on instrs.c2
e
s 00001/00013/00036
d D 4.7 00/08/29 19:17:42 msokolov 7 6
c remove instrs.c2 on make clean, it's a generated file
e
s 00038/00021/00011
d D 4.6 87/06/06 15:42:57 bostic 6 5
c new template
e
s 00001/00001/00031
d D 4.5 87/05/28 20:24:15 bostic 5 4
c wrong as directory
e
s 00001/00001/00031
d D 4.4 85/07/06 12:06:37 bloom 4 3
c allow easier repositioning of assembler src
e
s 00003/00003/00029
d D 4.3 85/03/19 10:50:39 ralph 3 2
c Turn on optimization for gosh sakes.
e
s 00001/00001/00031
d D 4.2 82/10/27 13:47:54 sam 2 1
c d2 causes "word displacement overflow" from ld
e
s 00032/00000/00000
d D 4.1 82/10/27 13:46:25 sam 1 0
c date and time created 82/10/27 13:46:25 by sam
e
u
U
t
T
I 1
D 6
#	%W%	(Berkeley)	%E%
E 6
#
D 2
CFLAGS=-c -d2 -w -DCOPYCODE -DC2
E 2
I 2
D 3
CFLAGS=-c -w -DCOPYCODE -DC2
E 3
I 3
D 6
CFLAGS=-DCOPYCODE -DC2 -O
E 3
E 2
LDFLAGS=
D 5
ASDIR = /usr/src/bin/as
E 5
I 5
ASDIR = /usr/src/bin/as/as.${MACHINE}
E 6
I 6
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-DCOPYCODE -DC2 -O
ASDIR=	../../../bin/as/as.${MACHINE}
SRCS=	c20.c c21.c c22.c
OBJS=	c20.o c21.o c22.o
E 6
E 5

D 6
SRCS = makefile c2.h c20.c c21.c c22.c
E 6
I 6
all: c2
E 6

D 6
c2:	c20.o c21.o c22.o
D 3
	$(CC) $(LDFLAGS) -z -o c2 c2?.o
E 3
I 3
	$(CC) $(LDFLAGS) -o c2 c2?.o
E 6
I 6
c2: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}
E 6
E 3

D 6
c20.o:	c20.c c2.h
c21.o:	c21.c c2.h
c22.o:  c22.c c2.h instrs.c2
D 3
	$(CC) $(CFLAGS) -R c22.c
E 3
I 3
	$(CC) $(CFLAGS) -R -c c22.c
E 6
I 6
c22.o: c22.c c2.h instrs.c2
	${CC} ${CFLAGS} -R -c c22.c
E 6
E 3

D 6
instrs.c2: $(ASDIR)/instrs
D 4
	(echo FLAVOR C2 ; cat $(ASDIR)/instrs) | awk -f /usr/src/bin/as/instrs > instrs.c2
E 4
I 4
	(echo FLAVOR C2 ; cat $(ASDIR)/instrs) | awk -f $(ASDIR)/instrs > instrs.c2
E 6
I 6
instrs.c2: ${ASDIR}/instrs
	(echo FLAVOR C2 ; cat ${ASDIR}/instrs) | awk -f ${ASDIR}/instrs > instrs.c2
E 6
E 4

clean:
D 6
	rm -f *.o *.s 
E 6
I 6
D 7
	rm -f *.o *.s c2
E 7
I 7
	rm -f *.o *.s c2 instrs.c2
E 7
E 6

D 6
install: c2
	install -s c2 $(DESTDIR)/lib
E 6
I 6
install:
	install -o bin -g bin -m 755 -s c2 ${DESTDIR}/lib/c2
E 6

D 6
sources: $(SRCS)
E 6
I 6
tags:
	ctags ${SRCS}
E 6

D 6
$(ASDIR)/instrs:
	(cd $(ASDIR); sccs get instrs)
E 6
I 6
D 8
depend:
E 8
I 8
depend: instrs.c2
E 8
	mkdep ${CFLAGS} ${SRCS}
E 6

D 6
$(SRCS):
	sccs get $@
E 6
I 6
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
D 7

c20.o: c20.c
c20.o:c2.h
c20.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/sys/types.h
c21.o: c21.c
c21.o:c2.h
c21.o: /usr/include/stdio.h /usr/include/ctype.h
c22.o: c22.c
c22.o:c2.h
c22.o:./instrs.c2

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 6
E 1
