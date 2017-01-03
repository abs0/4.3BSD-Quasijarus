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
#	@(#)Makefile	4.20 (Berkeley) 6/27/88
#
DEFS=	-DLIBC_SCCS
FLAGS=	-I../../vax ${DEFS}
CFLAGS=	-O ${FLAGS}
SRCS=	_setjmp.s abs.s alloca.s atof.s bcmp.s bcopy.s bzero.s fabs.s \
	ffs.s frexp.s index.s insque.s ldexp.s modf.s nargs.s remque.s \
	rindex.s setjmp.s strcat.s strcmp.s strcpy.s strlen.s strncat.s \
	strncmp.s strncpy.s udiv.s urem.s
OBJS=	_setjmp.o abs.o alloca.o atof.o bcmp.o bcopy.o bzero.o fabs.o \
	ffs.o frexp.o index.o insque.o ldexp.o modf.o nargs.o remque.o \
	rindex.o setjmp.o strcat.o strcmp.o strcpy.o strlen.o strncat.o \
	strncmp.o strncpy.o udiv.o urem.o
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

_setjmp.o: _setjmp.s ../../vax/DEFS.h
abs.o: abs.s ../../vax/DEFS.h
alloca.o: alloca.s ../../vax/DEFS.h
atof.o: atof.s ../../vax/DEFS.h
bcmp.o: bcmp.s ../../vax/DEFS.h
bcopy.o: bcopy.s ../../vax/DEFS.h
bzero.o: bzero.s ../../vax/DEFS.h
fabs.o: fabs.s ../../vax/DEFS.h
ffs.o: ffs.s ../../vax/DEFS.h
frexp.o: frexp.s ../../vax/DEFS.h
index.o: index.s ../../vax/DEFS.h
insque.o: insque.s ../../vax/DEFS.h
ldexp.o: ldexp.s ../../vax/DEFS.h /usr/include/errno.h
modf.o: modf.s ../../vax/DEFS.h
nargs.o: nargs.s ../../vax/DEFS.h
remque.o: remque.s ../../vax/DEFS.h
rindex.o: rindex.s ../../vax/DEFS.h
setjmp.o: setjmp.s ../../vax/DEFS.h
strcat.o: strcat.s ../../vax/DEFS.h
strcmp.o: strcmp.s ../../vax/DEFS.h
strcpy.o: strcpy.s ../../vax/DEFS.h
strlen.o: strlen.s ../../vax/DEFS.h
strncat.o: strncat.s ../../vax/DEFS.h
strncmp.o: strncmp.s ../../vax/DEFS.h
strncpy.o: strncpy.s ../../vax/DEFS.h
udiv.o: udiv.s ../../vax/DEFS.h ../../vax/DEFS.h
urem.o: urem.s ../../vax/DEFS.h ../../vax/DEFS.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
