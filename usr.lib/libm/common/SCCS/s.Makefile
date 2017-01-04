h39312
s 00010/00005/00046
d D 5.3 88/06/30 17:35:28 bostic 9 8
c install approved copyright notice
e
s 00001/00001/00050
d D 5.2 87/12/14 23:06:21 bostic 8 7
c force remake of archive
e
s 00000/00000/00051
d D 5.1 87/11/30 18:41:22 bostic 7 6
c tahoe release
e
s 00012/00003/00039
d D 1.5 87/11/30 18:05:42 bostic 6 4
c new header; add clean label
e
s 00009/00003/00039
d R 1.5 87/11/30 18:01:54 bostic 5 4
c Berkeley code, new header
e
s 00002/00003/00040
d D 1.4 87/08/03 23:18:27 zliu 4 3
c moving cabs.c to ../ieee/
e
s 00004/00003/00039
d D 1.3 87/07/24 13:31:46 zliu 3 2
c splitting trig.c into sincos.c and tan.c...
e
s 00000/00000/00042
d D 1.2 87/07/13 19:36:48 zliu 2 1
c clean-ups.
e
s 00042/00000/00000
d D 1.1 87/07/13 13:28:16 zliu 1 0
c date and time created 87/07/13 13:28:16 by zliu
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
D 6
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 6
I 6
# All rights reserved.
E 6
#
D 6
#	%Z%%M%	%I%	(ucb.elefunt)	%G%
E 6
I 6
# Redistribution and use in source and binary forms are permitted
D 9
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 6
#
I 6
#	%W% (Berkeley) %G%
#
E 6
CFLAGS=	-O
LIBC=	/lib/libc.a
D 3
SRCS=	atan2.c cabs.c trig.c
OBJS=	atan2.o cabs.o trig.o
E 3
I 3
D 4
SRCS=	atan2.c cabs.c sincos.c tan.c
OBJS=	atan2.o cabs.o sincos.o tan.o
E 4
I 4
SRCS=	atan2.c sincos.c tan.c
OBJS=	atan2.o sincos.o tan.o
E 4
E 3

.c.o:
	${CC} -p ${CFLAGS} -c $*.c
	-ld -X -r $*.o
	mv a.out ../profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
	-ld -x -r $*.o
	mv a.out $*.o

all: ../libm.a ../libm_p.a

D 8
../libm.a ../libm_p.a: ${OBJS}
E 8
I 8
../libm.a ../libm_p.a: ${OBJS} FRC
E 8
	cd ../profiled; ar cru ../libm_p.a ${OBJS}
	ar cru ../libm.a ${OBJS}

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}
I 6

clean: FRC
	rm -f ${OBJS} a.out
E 6

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

atan2.o: atan2.c
D 4
cabs.o: cabs.c
E 4
D 3
trig.o: trig.c
E 3
I 3
sincos.o: sincos.c trig.h
tan.o: tan.c trig.h
E 3

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
