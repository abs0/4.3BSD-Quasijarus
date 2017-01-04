h26505
s 00009/00001/00015
d D 1.3 87/06/19 11:34:15 bostic 3 2
c new template
e
s 00008/00004/00008
d D 1.2 85/08/21 13:26:20 miriam 2 1
c Revision by Prof. Kahan.
e
s 00012/00000/00000
d D 1.1 85/05/23 17:08:07 miriam 1 0
c date and time created 85/05/23 17:08:07 by miriam
e
u
U
t
From Prof. Kahan at UC at Berkeley
T
I 1
D 2
MORE=atan2.o cbrt.o trig.o cabs.o support.o
E 2
I 2
D 3
MORE=atan2.o cabs.o cbrt.o sqrt.o sincos.o tan.o argred.o support.o infnan.o
E 3
I 3
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
MORE=	atan2.o cabs.o cbrt.o sqrt.o sincos.o tan.o argred.o support.o \
	infnan.o
E 3
E 2

.s.o:
D 2
####	insert additional code for profiling (sed -f VAX/mcount.sed)
E 2
I 2
####	insert additional code for profiling
E 2
	sed -f mcount.sed $*.s | ${AS} -o $*.o
	-ld -X -r $*.o
D 2
	mv a.out ../profiled/${MACH}/$*.o
E 2
I 2
	mv a.out ../profiled/$*.o
E 2
	${AS} -o $*.o $*.s
	-ld -x -r $*.o
	mv a.out $*.o

D 2
all: ${MORE}
E 2
I 2
all: ../libm.a ../libm_p.a

../libm_p.a ../libm.a: ${MORE}
	cd ../profiled; ar cru ../libm_p.a ${MORE}
	ar cru ../libm.a ${MORE}
E 2
E 1
