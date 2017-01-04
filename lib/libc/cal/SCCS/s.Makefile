h03357
s 00012/00020/00037
d D 5.2 2012/06/21 00:32:52 msokolov 2 1
c a functional ctime() reimplementation appears to be complete
e
s 00057/00000/00000
d D 5.1 2012/06/20 02:36:33 msokolov 1 0
c date and time created 2012/06/20 02:36:33 by msokolov
e
u
U
t
T
I 2
#	%W% (IFCTF) %E%
E 2
I 1
#
D 2
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
#	%W% (Berkeley) %E%
#
E 2
DEFS=	-DLIBC_SCCS
D 2
CFLAGS=	-O ${DEFS}
SRCS=	sexatime.c
OBJS=	sexatime.o
E 2
I 2
CFLAGS=	-O -R ${DEFS}
SRCS=	asctime.c ctime.c gmtime.c localtime.c mjd2greg.c sexatime.c
OBJS=	asctime.o ctime.o gmtime.o localtime.o mjd2greg.o sexatime.o
E 2
TAGSFILE=tags

.c.o:
	@${CC} -p -c ${CFLAGS} $*.c
	@-ld -X -o profiled/$*.o -r $*.o
	${CC} ${CFLAGS} -c $*.c
	@-ld -x -r $*.o
	@mv a.out $*.o

all: ${OBJS}

link: ${OBJS}
	(cd ../library; rm -f ${OBJS})
	(cd ../profiled; rm -f ${OBJS})
	ln ${OBJS} ../library
	(cd profiled; ln ${OBJS} ../../profiled)

tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

clean:
	rm -f *.o profiled/* a.out core ${TAGSFILE}

depend:
	mkdep ${CFLAGS} ${SRCS}

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

I 2
asctime.o: asctime.c /usr/include/stdio.h /usr/include/time.h
ctime.o: ctime.c /usr/include/sys/types.h /usr/include/time.h
gmtime.o: gmtime.c /usr/include/sys/types.h /usr/include/mjdtime.h
gmtime.o: /usr/include/time.h
localtime.o: localtime.c /usr/include/sys/types.h /usr/include/mjdtime.h
localtime.o: /usr/include/time.h
mjd2greg.o: mjd2greg.c /usr/include/sys/types.h /usr/include/calendardefs.h
mjd2greg.o: /usr/include/time.h
E 2
sexatime.o: sexatime.c /usr/include/sys/types.h /usr/include/mjdtime.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
