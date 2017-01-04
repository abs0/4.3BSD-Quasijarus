h37599
s 00010/00005/00028
d D 5.3 88/07/09 10:55:40 bostic 4 3
c install approved copyright notice
e
s 00027/00007/00006
d D 5.2 88/01/07 13:44:09 bostic 3 1
c new template, clean sub-directories
e
s 00027/00007/00006
d R 5.2 88/01/07 13:42:57 bostic 2 1
c new template, clean subdirs
e
s 00013/00000/00000
d D 5.1 88/01/07 13:37:26 bostic 1 0
c date and time created 88/01/07 13:37:26 by bostic
e
u
U
t
T
I 1
#
D 3
# Makefile for testing dbx.
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
E 3
#
I 3
# Redistribution and use in source and binary forms are permitted
D 4
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
#
#	%W% (Berkeley) %G%
#
E 3

D 3
TESTDBX = ../../tdbx
E 3
I 3
TESTDBX=	../../tdbx
#SUBDIR=	mod cc pc f77
SUBDIR=	cc
E 3

D 3
passed:
#	@chdir mod; make TESTDBX=${TESTDBX}
	@chdir cc; make TESTDBX=${TESTDBX}
#	@chdir pc; make TESTDBX=${TESTDBX}
#	@chdir f77; make TESTDBX=${TESTDBX}
E 3
I 3
passed: ${SUBDIR}

${SUBDIR}: FRC
	cd $@; make TESTDBX=${TESTDBX}
E 3
	@echo ""
	@echo "passed tests"
I 3

clean: FRC
	-for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

depend: FRC
install: FRC
lint: FRC
tags: FRC
FRC:
E 3
E 1
