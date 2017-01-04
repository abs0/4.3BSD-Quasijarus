h50309
s 00033/00004/00011
d D 1.3 87/06/19 13:09:08 bostic 4 2
c new template
e
s 00030/00001/00014
d R 1.3 87/06/19 12:57:43 bostic 3 2
c new template
e
s 00007/00003/00008
d D 1.2 85/08/21 13:47:27 miriam 2 1
c Revision by Prof. Kahan.
e
s 00011/00000/00000
d D 1.1 85/05/23 17:12:23 miriam 1 0
c date and time created 85/05/23 17:12:23 by miriam
e
u
U
t
From Prof. Kahan at UC at Berkeley
T
I 1
D 2
FILES=atan2.o cbrt.o trig.o cabs.o support.o
E 2
I 2
D 4
MORE=atan2.o cbrt.o trig.o cabs.o support.o
E 4
I 4
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	atan2.c cbrt.c trig.c cabs.c support.c
OBJS=	atan2.o cbrt.o trig.o cabs.o support.o
E 4
E 2

.c.o:
	${CC} -p ${CFLAGS} -c $*.c
	-ld -X -r $*.o
D 2
	mv a.out ../profiled/${MACH}/$*.o
E 2
I 2
	mv a.out ../profiled/$*.o
E 2
	${CC} ${CFLAGS} -c $*.c
	-ld -x -r $*.o
	mv a.out $*.o

D 2
all: ${FILES}
E 2
I 2
all: ../libm.a ../libm_p.a

D 4
../libm.a ../libm_p.a: ${MORE}
	cd ../profiled; ar cru ../libm_p.a ${MORE}
	ar cru ../libm.a ${MORE}
E 4
I 4
../libm.a ../libm_p.a: ${OBJS}
	cd ../profiled; ar cru ../libm_p.a ${OBJS}
	ar cru ../libm.a ${OBJS}

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

atan2.o: atan2.c
cbrt.o: cbrt.c
trig.o: trig.c
cabs.o: cabs.c
support.o: support.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 2
E 1
