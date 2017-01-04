h08160
s 00010/00005/00034
d D 5.4 88/06/30 17:38:13 bostic 8 7
c install approved copyright notice
e
s 00001/00001/00038
d D 5.3 87/12/14 23:05:42 bostic 7 6
c force remake of archive
e
s 00000/00000/00039
d D 5.2 87/11/30 18:49:06 bostic 6 5
c tahoe release
e
s 00000/00000/00039
d D 5.1 87/11/30 18:46:14 bostic 5 4
c tahoe release
e
s 00027/00006/00012
d D 1.4 87/11/30 18:12:09 bostic 4 3
c add header, labels
e
s 00001/00001/00017
d D 1.3 87/08/03 23:15:30 zliu 3 2
c adding cabs.o
e
s 00000/00000/00018
d D 1.2 87/07/13 13:06:10 zliu 2 1
c various clean-ups; added Makefile and mcount.sed.
e
s 00018/00000/00000
d D 1.1 87/07/13 13:05:18 zliu 1 0
c date and time created 87/07/13 13:05:18 by zliu
e
u
U
t
T
I 1
D 4
# %Z%%M%	%I%	(ucb.elefunt)	%G%
SCCSID = "%Z%%M%	%I%	(ucb.elefunt)	%G%"
D 3
MORE=cbrt.o sqrt.o support.o infnan.o
E 3
I 3
MORE=cabs.o cbrt.o sqrt.o support.o infnan.o
E 4
I 4
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
OBJS=	cabs.o cbrt.o sqrt.o support.o infnan.o
E 4
E 3

.s.o:
####	insert additional code for profiling
	sed -f mcount.sed $*.s | ${AS} -o $*.o
	-ld -X -r $*.o
	mv a.out ../profiled/$*.o
	${AS} -o $*.o $*.s
	-ld -x -r $*.o
	mv a.out $*.o

all: ../libm.a ../libm_p.a

D 4
../libm_p.a ../libm.a: ${MORE}
	cd ../profiled; ar cru ../libm_p.a ${MORE}
	ar cru ../libm.a ${MORE}
E 4
I 4
D 7
../libm_p.a ../libm.a: ${OBJS}
E 7
I 7
../libm_p.a ../libm.a: ${OBJS} FRC
E 7
	cd ../profiled; ar cru ../libm_p.a ${OBJS}
	ar cru ../libm.a ${OBJS}

depend: FRC

tags: FRC

clean: FRC
	rm -f ${OBJS} a.out

FRC:

E 4
E 1
