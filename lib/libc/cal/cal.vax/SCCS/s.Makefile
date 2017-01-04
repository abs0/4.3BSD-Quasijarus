h37149
s 00003/00002/00057
d D 5.2 2012/06/20 05:03:02 msokolov 2 1
c mjd2weekday.s added
e
s 00059/00000/00000
d D 5.1 2012/06/20 02:01:12 msokolov 1 0
c date and time created 2012/06/20 02:01:12 by msokolov
e
u
U
t
T
I 1
#
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
DEFS=	-DLIBC_SCCS
FLAGS=	-I../../vax ${DEFS}
CFLAGS=	-O ${FLAGS}
D 2
SRCS=	mjd2unix.s unix2mjd.s
OBJS=	mjd2unix.o unix2mjd.o
E 2
I 2
SRCS=	mjd2unix.s mjd2weekday.s unix2mjd.s
OBJS=	mjd2unix.o mjd2weekday.o unix2mjd.o
E 2
TAGSFILE=tags

.s.o:
	@/lib/cpp -E ${FLAGS} -DPROF $*.s | ${AS} -o $*.o
	@-ld -X -o profiled/$*.o -r $*.o
	/lib/cpp -E ${FLAGS} $*.s | ${AS} -o $*.o
	@-ld -x -r $*.o
	@mv a.out $*.o

all: ${OBJS}

link: ${OBJS}
	(cd ../../library; rm -f ${OBJS})
	(cd ../../profiled; rm -f ${OBJS})
	ln ${OBJS} ../../library
	(cd profiled; ln ${OBJS} ../../../profiled)

tags:
	(P=`pwd`; \
	egrep "^ENTRY(.*)|^SYSCALL(.*)" ${SRCS} | sed \
"s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);\3 $$P/\1 /^\2(\3\4$$/;" \
	>> ${TAGSFILE})

clean:
	rm -f *.o profiled/* a.out core ${TAGSFILE}

depend:
	mkdep ${CFLAGS} ${SRCS}

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

mjd2unix.o: mjd2unix.s ../../vax/DEFS.h /usr/include/calendardefs.h
I 2
mjd2weekday.o: mjd2weekday.s ../../vax/DEFS.h
E 2
unix2mjd.o: unix2mjd.s ../../vax/DEFS.h /usr/include/calendardefs.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
