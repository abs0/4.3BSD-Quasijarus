h59449
s 00001/00001/00072
d D 7.1 86/06/05 01:15:19 mckusick 5 4
c 4.3BSD release version
e
s 00006/00001/00067
d D 1.4 85/06/08 14:20:35 mckusick 4 3
c Add copyright
e
s 00003/00000/00065
d D 1.3 84/08/20 22:05:54 mckusick 3 2
c add `make print' entry
e
s 00007/00007/00058
d D 1.2 84/08/18 18:04:38 mckusick 2 1
c change name of header file from pc2.h to inline.h
e
s 00065/00000/00000
d D 1.1 84/08/18 17:35:32 mckusick 1 0
c date and time created 84/08/18 17:35:32 by mckusick
e
u
U
t
T
I 1
D 4
#	%W%	(Berkeley)	%E%
E 4
I 4
#
D 5
# Copyright (c) 1982 Regents of the University of California.
E 5
I 5
# Copyright (c) 1982, 1986 Regents of the University of California.
E 5
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 4
#
DESTDIR=
CFLAGS=	-O
INCPATH=-I.
LFLAGS=	

# The program itself
#
D 2
PROG=	pc2
E 2
I 2
PROG=	inline
E 2

# Sources
#
SRCS=	main.c machdep.c machpats.c libcpats.c langpats.c

# Objects
#
OBJS=	main.o machdep.o machpats.o libcpats.o langpats.o

# Header files
#
D 2
HDRS=	pc2.h
E 2
I 2
HDRS=	inline.h
E 2

${PROG}: ${OBJS} ${HDRS}
	cc ${LFLAGS} -o ${PROG} ${OBJS}

${OBJS}:
	cc ${CFLAGS} ${INCPATH} -c $*.c

install: ${PROG}
D 2
	install ${PROG} ${DESTDIR}/usr/lib/${PROG}
E 2
I 2
	install ${PROG} ../inline
E 2

clean:
	rm -f a.out core ${OBJS} ${PROG}

I 3
print:
	@pr ${HDRS} ${SRCS}

E 3
lint:
	lint ${SRCS}

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

# DO NOT DELETE THIS LINE -- make depend uses it


D 2
main.o: main.c /usr/include/stdio.h /usr/include/ctype.h ./pc2.h
E 2
I 2
main.o: main.c /usr/include/stdio.h /usr/include/ctype.h ./inline.h
E 2
machdep.o: machdep.c /usr/include/stdio.h /usr/include/ctype.h
D 2
machpats.o: machpats.c ./pc2.h
libcpats.o: libcpats.c ./pc2.h
langpats.o: langpats.c ./pc2.h
E 2
I 2
machpats.o: machpats.c ./inline.h
libcpats.o: libcpats.c ./inline.h
langpats.o: langpats.c ./inline.h
E 2
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 1
