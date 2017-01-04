h50600
s 00000/00001/00080
d D 5.5 87/10/26 18:12:43 bostic 6 5
c MACHINE defined by make(1), now
e
s 00008/00006/00073
d D 5.4 87/05/10 16:33:03 mckusick 5 4
c update dependencies
e
s 00002/00001/00077
d D 5.3 86/11/13 18:08:48 mckusick 4 3
c add CCI (tahoe) support
e
s 00001/00001/00077
d D 5.2 86/03/18 23:27:07 mckusick 3 2
c strip on install
e
s 00006/00001/00072
d D 5.1 85/06/05 16:36:22 dist 2 1
c Add copyright
e
s 00073/00000/00000
d D 1.1 84/08/18 18:25:01 mckusick 1 0
c date and time created 84/08/18 18:25:01 by mckusick
e
u
U
t
T
I 1
D 2
#	%W%	(Berkeley)	%E%
E 2
I 2
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 2
#
DESTDIR=
CFLAGS=	-O
INCPATH=-I${SRCDIR}
LFLAGS=	
D 4
SRCDIR=	/sys/vax/inline
E 4
I 4
D 6
MACHINE= unknown
E 6
SRCDIR=	/sys/${MACHINE}/inline
E 4

# The program itself
#
PROG=	pc2

# Sources
#
RMTSRCS=${SRCDIR}/main.c ${SRCDIR}/machdep.c ${SRCDIR}/machpats.c \
	${SRCDIR}/libcpats.c
LOCSRCS=langpats.c

# Objects
#
RMTOBJS=main.o machdep.o machpats.o libcpats.o
LOCOBJS=langpats.o

# Header files
#
HDRS=	${SRCDIR}/inline.h

${PROG}: ${RMTOBJS} ${LOCOBJS} ${HDRS}
	cc ${LFLAGS} -o ${PROG} ${RMTOBJS} ${LOCOBJS}

${RMTOBJS}:
	cc ${CFLAGS} ${INCPATH} -c ${SRCDIR}/$*.c

${LOCOBJS}:
	cc ${CFLAGS} ${INCPATH} -c $*.c

install: ${PROG}
D 3
	install ${PROG} ${DESTDIR}/usr/lib/${PROG}
E 3
I 3
	install -s ${PROG} ${DESTDIR}/usr/lib/${PROG}
E 3

clean:
	rm -f a.out core ${RMTOBJS} ${LOCOBJS} ${PROG}

lint:
	lint ${LOCSRCS} ${RMTSRCS}

depend:
	cc -M ${INCPATH} ${LOCSRCS} ${RMTSRCS} | \
I 5
	sed 's/${MACHINE}/$${MACHINE}/' | \
E 5
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

# DO NOT DELETE THIS LINE -- make depend uses it


D 5
langpats.o: langpats.c /sys/vax/inline/inline.h
main.o: /sys/vax/inline/main.c /usr/include/stdio.h /usr/include/ctype.h
main.o: /sys/vax/inline/inline.h
machdep.o: /sys/vax/inline/machdep.c /usr/include/stdio.h /usr/include/ctype.h
machpats.o: /sys/vax/inline/machpats.c /sys/vax/inline/inline.h
libcpats.o: /sys/vax/inline/libcpats.c /sys/vax/inline/inline.h
E 5
I 5
langpats.o: langpats.c /sys/${MACHINE}/inline/inline.h
main.o: /sys/${MACHINE}/inline/main.c /usr/include/stdio.h /usr/include/ctype.h
main.o: /sys/${MACHINE}/inline/inline.h
machdep.o: /sys/${MACHINE}/inline/machdep.c /usr/include/stdio.h
machdep.o: /usr/include/ctype.h /sys/${MACHINE}/inline/inline.h
machpats.o: /sys/${MACHINE}/inline/machpats.c /sys/${MACHINE}/inline/inline.h
libcpats.o: /sys/${MACHINE}/inline/libcpats.c /sys/${MACHINE}/inline/inline.h
E 5
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 1
