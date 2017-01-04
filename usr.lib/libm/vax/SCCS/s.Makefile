h21893
s 00010/00005/00035
d D 5.3 88/06/30 17:32:10 bostic 9 8
c install approved copyright notice
e
s 00001/00001/00039
d D 5.2 87/12/14 23:07:10 bostic 8 7
c force remake of archive
e
s 00000/00000/00040
d D 5.1 87/11/30 18:49:51 bostic 7 6
c tahoe release
e
s 00028/00005/00012
d D 1.5 87/11/30 18:13:24 bostic 6 5
c add header, labels
e
s 00000/00001/00017
d D 1.4 87/07/13 19:50:52 zliu 5 4
c clean-ups.
e
s 00000/00000/00018
d D 1.3 85/09/12 22:19:44 elefunt 4 2
c adding sccsid asciz string to each source file.
e
s 00000/00000/00018
d R 1.3 85/09/12 22:15:13 elefunt 3 2
c adding sccsid asciz string to each source file.
e
s 00002/00002/00016
d D 1.2 85/09/12 20:16:27 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00018/00000/00000
d D 1.1 85/09/06 17:50:10 zliu 1 0
c date and time created 85/09/06 17:50:10 by zliu
e
u
U
t
T
I 1
D 2
# %W% (ELEFUNT) %G%
SCCSID = "%W% (ELEFUNT) %G%"
E 2
I 2
D 6
# %W% (ucb.elefunt) %G%
D 5
# SCCSID = "%W% (ucb.elefunt) %G%"
E 5
E 2
MORE=atan2.o cabs.o cbrt.o sqrt.o sincos.o tan.o argred.o support.o infnan.o
E 6
I 6
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
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
#
#	%W% (Berkeley) %G%
#
OBJS=	atan2.o cabs.o cbrt.o sqrt.o sincos.o tan.o argred.o support.o \
	infnan.o
E 6

.s.o:
####	insert additional code for profiling
	sed -f mcount.sed $*.s | ${AS} -o $*.o
	-ld -X -r $*.o
	mv a.out ../profiled/$*.o
	${AS} -o $*.o $*.s
	-ld -x -r $*.o
	mv a.out $*.o

all: ../libm.a ../libm_p.a

D 6
../libm_p.a ../libm.a: ${MORE}
	cd ../profiled; ar cru ../libm_p.a ${MORE}
	ar cru ../libm.a ${MORE}
E 6
I 6
D 8
../libm_p.a ../libm.a: ${OBJS}
E 8
I 8
../libm_p.a ../libm.a: ${OBJS} FRC
E 8
	cd ../profiled; ar cru ../libm_p.a ${OBJS}
	ar cru ../libm.a ${OBJS}

depend: FRC

tags: FRC

clean: FRC
	rm -f ${OBJS} a.out

FRC:

E 6
E 1
