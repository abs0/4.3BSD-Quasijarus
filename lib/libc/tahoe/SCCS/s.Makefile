h05413
s 00010/00005/00032
d D 5.7 88/07/25 13:55:42 bostic 8 7
c approved copyright notice
e
s 00002/00001/00035
d D 5.6 88/05/24 08:08:20 bostic 7 6
c fix ALL define
e
s 00004/00003/00032
d D 5.5 88/05/20 15:05:08 bostic 6 5
c set DEFS to compile in SCCS ids.
e
s 00012/00019/00023
d D 5.4 88/05/20 13:51:34 bostic 5 4
c restructuring libc
e
s 00001/00001/00041
d D 5.3 88/05/19 15:56:16 bostic 4 3
c remove stdio, everything is in ../stdio now
e
s 00008/00008/00034
d D 5.2 87/12/01 18:30:59 bostic 3 1
c make rm clean; always clean fpe
e
s 00001/00002/00040
d R 5.2 87/10/03 14:33:26 bostic 2 1
c make rm clean
e
s 00042/00000/00000
d D 5.1 86/08/01 09:24:27 sam 1 0
c date and time created 86/08/01 09:24:27 by sam
e
u
U
t
T
I 1
#
D 5
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 5
I 5
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 5
#
I 5
# Redistribution and use in source and binary forms are permitted
D 8
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
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
E 5
#	%W% (Berkeley) %G%
#
I 6
DEFS=	-DLIBC_SCCS -DSYSLIBC_SCCS
TAGSFILE=tags

E 6
D 5
# Machine dependent routines for the Tahoe are located here
#
COMPAT=	compat-4.1
E 5
# include this for floating point emulation code
#FPE=	fpe
I 7
ALL=	sys ${FPE}
E 7
D 4
ALL=	gen net stdio sys ${COMPAT}
E 4
I 4
D 5
ALL=	gen net sys ${COMPAT}
E 5
I 5
D 6
ALL=	sys ${FPE}
E 5
E 4
TAGSFILE=tags
E 6

D 5
tahoelib tahoelib_p: ${ALL}
	-mkdir tmp
	for i in ${ALL}; do (cd tmp; ar x ../$$i/$${i}lib); done
	ar cr tahoelib `ls tmp/*.o | sort -t/ +1`
	rm -f tmp/*
	for i in ${ALL}; do (cd tmp; ar x ../$$i/$${i}lib_p); done
	ar cr tahoelib_p `ls tmp/*.o | sort -t/ +1`
	rm -rf tmp
E 5
I 5
D 6
all:
E 6
I 6
D 7
all: sys ${FPE}
E 7
I 7
all: ${ALL}
E 7
E 6
	for i in ${ALL}; do (cd $$i; make ${MFLAGS} DEFS=${DEFS}); done
E 5

D 5
${ALL}:	FRC
	cd $@; make ${MFLAGS} DEFS=${DEFS}

E 5
D 3
FRC:
E 3
I 3
clean:
	for i in ${ALL} fpe; do (cd $$i; make ${MFLAGS} clean); done
D 5
	rm -rf tahoelib tahoelib_p tmp/*.o;
E 5
E 3

I 3
depend:
	for i in ${ALL}; do \
		(cd $$i; make ${MFLAGS} DEFS=${DEFS} depend); done

E 3
tags:
	for i in ${ALL}; do \
		(cd $$i; make ${MFLAGS} TAGSFILE=../${TAGSFILE} tags); \
	done

D 3
clean:
	for i in ${ALL}; do (cd $$i; make ${MFLAGS} clean); done
	rm -f tahoelib tahoelib_p tmp/*.o;
	-rmdir tmp
E 3
I 3
FRC:
E 3

D 3
depend:
	for i in ${ALL}; do \
		(cd $$i; make ${MFLAGS} DEFS=${DEFS} depend); done
E 3
E 1
