h23229
s 00001/00001/00072
d D 1.3 86/02/24 22:28:05 sam 3 2
c put back sccsid
e
s 00001/00001/00072
d D 1.2 86/02/24 22:27:08 sam 2 1
c update from monet: check number of arguments in pattern calls
e
s 00073/00000/00000
d D 1.1 85/07/25 17:44:06 sam 1 0
c date and time created 85/07/25 17:44:06 by sam
e
u
U
t
T
I 1
#
# Copyright (c) 1982 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 3
#	@(#)Makefile	1.4 (Berkeley) 6/8/85
E 3
I 3
#	%W% (Berkeley) %G%
E 3
#
DESTDIR=
CFLAGS=	-O
INCPATH=-I.
LFLAGS=	

# The program itself
#
PROG=	inline

# Sources
#
SRCS=	main.c machdep.c machpats.c libcpats.c langpats.c

# Objects
#
OBJS=	main.o machdep.o machpats.o libcpats.o langpats.o

# Header files
#
HDRS=	inline.h

${PROG}: ${OBJS} ${HDRS}
	cc ${LFLAGS} -o ${PROG} ${OBJS}

${OBJS}:
	cc ${CFLAGS} ${INCPATH} -c $*.c

install: ${PROG}
D 2
	install ${PROG} ../inline
E 2
I 2
#	install ${PROG} ../inline
E 2

clean:
	rm -f a.out core ${OBJS} ${PROG}

print:
	@pr ${HDRS} ${SRCS}

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


main.o: main.c /usr/include/stdio.h /usr/include/ctype.h ./inline.h
machdep.o: machdep.c /usr/include/stdio.h /usr/include/ctype.h
machpats.o: machpats.c ./inline.h
libcpats.o: libcpats.c ./inline.h
langpats.o: langpats.c ./inline.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 1
