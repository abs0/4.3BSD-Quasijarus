h49807
s 00010/00005/00053
d D 5.3 88/06/30 17:40:10 bostic 8 7
c install approved copyright notice
e
s 00001/00001/00057
d D 5.2 87/12/14 23:06:04 bostic 7 6
c force remake of archive
e
s 00000/00000/00058
d D 5.1 87/11/30 18:43:59 bostic 6 5
c tahoe release
e
s 00034/00003/00024
d D 1.5 87/11/30 18:09:23 bostic 5 4
c checked in for zliu; added header, various labels
e
s 00001/00001/00026
d D 1.4 87/07/13 19:50:12 zliu 4 3
c clean-ups.
e
s 00006/00008/00021
d D 1.3 87/07/13 15:18:31 zliu 3 2
c restructuring.
e
s 00003/00002/00026
d D 1.2 86/03/04 16:51:21 elefunt 2 1
c adding drem.s,sqrt.s
e
s 00028/00000/00000
d D 1.1 85/09/19 16:03:19 zliu 1 0
c date and time created 85/09/19 16:03:19 by zliu
e
u
U
t
T
I 1
D 5
# %W% (ucb.elefunt) %G%
E 5
I 5
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 8
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
#
#	%W% (Berkeley) %G%
#
E 5
D 3
SCCSID= "%W% (ucb.elefunt) %G%"
CFLAGS= -DNATIONAL
D 2
MORE=atan2.o cbrt.o tan.o sincos.o cabs.o support.o sqrt.o national.o
E 2
I 2
MORE=atan2.o cbrt.o tan.o sincos.o cabs.o\
     drem.o sqrt.o support.o
E 3
I 3
D 4
CFLAGS= -DNATIONAL -O
E 4
I 4
CFLAGS=	-O
E 4
D 5
SRCS=cbrt.c sqrt.s support.s
OBJS=cbrt.o sqrt.o support.o
E 5
I 5
SRCS=	cabs.c cbrt.c
OBJS=	cabs.o cbrt.o sqrt.o support.o
E 5
E 3
E 2

.c.o:
	${CC} -p ${CFLAGS} -c $*.c
D 2
	-lx32 -X -r $*.o
E 2
I 2
	-ld -X -r $*.o
E 2
	mv a.out ../profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
	-ld -x -r $*.o
	mv a.out $*.o

.s.o:
####	insert additional code for profiling
	sed -f mcount.sed $*.s | ${AS} -o $*.o
	-ld -X -r $*.o
	mv a.out ../profiled/$*.o
	${AS} -o $*.o $*.s
	-ld -x -r $*.o
	mv a.out $*.o

all: ../libm.a ../libm_p.a

D 3
../libm.a ../libm_p.a: ${MORE}
	cd ../profiled; ar cru ../libm_p.a ${MORE}
	ar cru ../libm.a ${MORE}

E 3
I 3
D 7
../libm.a ../libm_p.a: ${OBJS}
E 7
I 7
../libm.a ../libm_p.a: ${OBJS} FRC
E 7
	cd ../profiled; ar cru ../libm_p.a ${OBJS}
	ar cru ../libm.a ${OBJS}
I 5

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

clean: FRC
	rm -f ${OBJS} a.out

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

cabs.o: cabs.c
cbrt.o: cbrt.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 3
E 1
