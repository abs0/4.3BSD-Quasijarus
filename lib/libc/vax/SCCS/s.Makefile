h04315
s 00010/00005/00028
d D 5.8 88/07/09 11:13:46 bostic 11 10
c install approved copyright notice
e
s 00001/00000/00032
d D 5.7 88/05/20 15:07:09 bostic 10 9
c set DEFS to compile in SCCS ids.
e
s 00018/00026/00014
d D 5.6 88/05/20 13:52:53 bostic 9 8
c restructuring libc
e
s 00004/00000/00036
d D 5.5 85/09/05 10:38:53 bloom 8 7
c add make depend
e
s 00001/00001/00035
d D 5.4 85/06/18 22:50:11 mckusick 7 6
c add DEFS
e
s 00001/00001/00035
d D 5.3 85/06/05 18:30:09 mckusick 6 5
c cleanup clean entry
e
s 00006/00000/00030
d D 5.2 85/05/30 22:35:26 sam 5 4
c add tags
e
s 00006/00001/00024
d D 5.1 85/05/30 14:32:00 dist 4 3
c Add copyright
e
s 00001/00001/00024
d D 4.3 83/07/05 20:00:23 sam 3 2
c new directory
e
s 00001/00001/00024
d D 4.2 83/07/02 12:15:48 sam 2 1
c reorganization
e
s 00025/00000/00000
d D 4.1 83/06/27 18:26:05 root 1 0
c date and time created 83/06/27 18:26:05 by root
e
u
U
t
T
I 1
D 4
#	%M%	%I%	%E%
E 4
I 4
#
D 9
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 9
I 9
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 9
#
I 9
# Redistribution and use in source and binary forms are permitted
D 11
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
#
E 9
#	%W% (Berkeley) %G%
E 4
#
I 10
DEFS=	-DLIBC_SCCS -DSYSLIBC_SCCS
E 10
D 9
# Machine dependent routines for the VAX are located here
#
D 2
COMPAT=	4.1compat
E 2
I 2
D 3
COMPAT=	
E 3
I 3
COMPAT=	compat-4.1
E 3
E 2
ALL=	gen net stdio sys ${COMPAT}
E 9
I 9
ALL=	sys
E 9
I 5
TAGSFILE=tags
E 5

D 9
vaxlib vaxlib_p: ${ALL}
	-mkdir tmp
	for i in ${ALL}; do (cd tmp; ar x ../$$i/$${i}lib); done
	ar cr vaxlib `ls tmp/*.o | sort -t/ +1`
	rm -f tmp/*
	for i in ${ALL}; do (cd tmp; ar x ../$$i/$${i}lib_p); done
	ar cr vaxlib_p `ls tmp/*.o | sort -t/ +1`
	rm -rf tmp
E 9
I 9
${ALL}:
	for i in ${ALL}; do (cd $$i; make ${MFLAGS} DEFS=${DEFS}); done
E 9

D 9
${ALL}:	FRC
D 7
	cd $@; make ${MFLAGS}
E 7
I 7
	cd $@; make ${MFLAGS} DEFS=${DEFS}
E 9
I 9
clean:
	for i in ${ALL}; do (cd $$i; make ${MFLAGS} clean); done
E 9
E 7

D 9
FRC:
E 9
I 9
depend:
	for i in ${ALL}; do \
		(cd $$i; make ${MFLAGS} DEFS=${DEFS} depend); done
E 9
I 5

tags:
	for i in ${ALL}; do \
		(cd $$i; make ${MFLAGS} TAGSFILE=../${TAGSFILE} tags); \
	done
E 5

D 9
clean:
	for i in ${ALL}; do (cd $$i; make ${MFLAGS} clean); done
D 6
	rm -f tmp/*.o;
E 6
I 6
	rm -f vaxlib vaxlib_p tmp/*.o;
E 6
	-rmdir tmp
I 8

depend:
	for i in ${ALL}; do \
		(cd $$i; make ${MFLAGS} DEFS=${DEFS} depend); done
E 9
I 9
FRC:
E 9
E 8
E 1
