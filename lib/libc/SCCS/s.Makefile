h42706
s 00003/00002/00104
d D 4.35 2012/06/21 02:55:40 msokolov 36 35
c cal directories added
e
s 00010/00005/00096
d D 4.34 88/07/09 11:10:44 bostic 35 34
c install approved copyright notice
e
s 00002/00005/00099
d D 4.33 88/06/04 10:19:18 bostic 34 33
c add compat-sys5.${MACHINE}; minor cleanups
e
s 00002/00001/00102
d D 4.32 88/05/25 17:41:50 bostic 33 32
c make tags by default, install tags on install:
e
s 00009/00002/00094
d D 4.31 88/05/24 08:56:13 bostic 32 31
c fix tags 
e
s 00045/00043/00051
d D 4.30 88/05/24 08:35:11 bostic 31 30
c restructure libc
e
s 00001/00001/00093
d D 4.29 88/05/19 17:50:26 bostic 30 29
c create compat-4.3
e
s 00001/00001/00093
d D 4.28 87/12/31 17:23:50 bostic 29 28
c remove libraries on clean
e
s 00001/00002/00093
d D 4.27 87/09/23 11:19:55 bostic 28 27
c just do rm -rf and don't bother ignoring exit
e
s 00003/00004/00092
d D 4.26 87/06/06 15:25:01 bostic 27 26
c install owner/group bin
e
s 00001/00001/00095
d D 4.25 87/05/30 14:24:50 bostic 26 25
c removed MACHINE/csu from depend list
e
s 00000/00004/00096
d D 4.24 87/05/28 18:16:27 bostic 25 24
c machine now defined in make
e
s 00001/00000/00099
d D 4.23 87/04/03 14:02:59 karels 24 23
x 22
c need hostlib
e
s 00000/00001/00098
d D 4.22 87/03/18 16:30:42 bostic 23 22
c install doesn't install tags, for make build
e
s 00002/00002/00097
d D 4.21 87/03/11 21:58:18 bostic 22 21
c changed install to include tags
e
s 00004/00001/00095
d D 4.20 86/10/13 17:14:36 sam 21 20
c we are tahoe
e
s 00005/00002/00091
d D 4.19 86/03/09 22:16:55 donn 20 19
c Change -Dlint feature (delete sccsid's) into LIBC_SCCS feature (preserve
c sccsid's).
e
s 00002/00002/00091
d D 4.18 86/03/08 19:55:00 kjd 19 18
c fix comment, Name server is two words
e
s 00004/00005/00089
d D 4.17 86/01/29 15:42:09 sklower 18 16
c Add xns addr conversion routines, make default named, fix bug in making tags.
e
s 00003/00004/00090
d R 4.17 86/01/29 15:37:05 sklower 17 16
c add xns i/o routines to libc, make named default for hostinfo.
e
s 00001/00000/00093
d D 4.16 85/09/15 14:58:21 bloom 16 15
c Make sure tmp is clean before building library
e
s 00015/00016/00078
d D 4.15 85/09/06 18:38:48 bloom 15 14
c cleanup comments, fix make clean, add make depend
e
s 00017/00012/00077
d D 4.14 85/09/04 18:56:32 bloom 14 13
c fix for proper host name lookup
e
s 00020/00000/00069
d D 4.13 85/07/12 15:50:26 kjd 13 12
c Add verable RESOLVE to determine which resolver is used
e
s 00005/00001/00064
d D 4.12 85/06/19 15:30:10 mckusick 12 11
c allow elimination of sccsid's
e
s 00000/00001/00065
d D 4.11 85/05/30 23:09:31 sam 11 10
c don't sort tags at this level
e
s 00012/00005/00054
d D 4.10 85/05/30 22:34:14 sam 10 9
c add tags
e
s 00008/00003/00051
d D 4.9 85/05/30 21:21:10 sam 9 8
c ci for ralph; rearrange libc dependency (exit follows findiop); add copyright
e
s 00001/00001/00053
d D 4.8 85/01/08 10:10:14 bloom 8 7
c fakcu.o added to libc.a twice instead of to libc_p.a
e
s 00002/00000/00052
d D 4.7 84/11/13 15:10:54 karels 7 6
c add fake cleanup()
e
s 00004/00003/00048
d D 4.6 83/07/02 23:53:33 root 6 5
c put str*n in sys5 compat library
c *** CHANGED *** 83/07/02 23:55:03 root
c make install work properly (sam)
e
s 00030/00031/00021
d D 4.5 83/06/27 18:24:55 root 5 4
c new organization
e
s 00009/00008/00043
d D 4.4 82/12/17 17:33:07 sam 4 3
c clean didn't work
e
s 00001/00001/00050
d D 4.3 82/12/15 22:03:50 clemc 3 2
c Fixed a bug so the mkdir tmp will not case an abort if the directory
c already exists.  Clem
e
s 00013/00014/00038
d D 4.2 82/12/04 18:38:28 mckusick 2 1
c changes to reintroduce mon.o
e
s 00052/00000/00000
d D 4.1 82/12/03 22:03:53 mckusick 1 0
c date and time created 82/12/03 22:03:53 by mckusick
e
u
U
t
T
I 13
D 18

E 18
E 13
I 1
D 4
#	%W%	(Berkeley)	%E%
E 4
I 4
D 6
#	%W%	{Berkeley}	%E%
E 6
I 6
D 9
#	%M%	%I%	%E%
E 9
E 6
E 4
#
I 9
D 31
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 31
I 31
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 31
#
I 31
# Redistribution and use in source and binary forms are permitted
D 35
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 35
I 35
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
E 35
#
E 31
D 36
#	%W% (Berkeley) %G%
E 36
I 36
#	%W% (Berkeley) %E%
E 36
#
I 13
D 31
#
E 13
E 9
I 2
D 5
#	The system has two monitoring schemes, utilizing either ``prof''
#	or ``gprof''. DFLMON determines the default profiler; mon.o
#	specifies that ``prof'' is the default, gmon.o specifies that
#	``gprof'' is the default.
E 5
I 5
# The system has two monitoring schemes, utilizing either ``prof''
# or ``gprof''. DFLMON determines the default profiler; mon.o
# specifies that ``prof'' is the default, gmon.o specifies that
# ``gprof'' is the default.
E 5
#
I 5
# Machine dependent routines are located in a subtree which parallels
# the top directories.  This subtree is identified by the machine name.
#
E 31
D 6
# Compatibility routines are kept in directories with a trailing ``compat''
E 6
I 6
# Compatibility routines are kept in directories with a prefixing
# ``compat'' (so they all sort together).
E 6
# 
# The C run-time startup code is always machine dependent and expected
# to be located in ${MACHINE}/csu
#
I 12
D 20
# All files contain sccsid strings. To compile a library that does
# not include these strings one must add -Dlint to DEFS below.
E 20
I 20
D 31
# All files contain sccsid strings, but these are not compiled into
# library objects by default, as a space-saving measure.  To produce
# a library that contains these strings in every object except
# system call stubs, add -DLIBC_SCCS to DEFS below; to put these
# strings into system call stubs, use -DSYSLIBC_SCCS.
E 20
#
E 31
I 13
D 15
#*********************************************************************
#=====================================================================
#							
E 15
D 14
# There are two types of resolvers, 'res_named' which uses the 
#  nameserver and 'res_static' which uses /etc/hosts.
E 14
I 14
# There are two possible methods of doing host name look up.  They are
D 15
# to use the nameserver or /etc/hosts.
E 14
#
D 14
#	RESOLVER defines which resolver is to be compiled into libc  
E 14
I 14
#	HOSTLOOKUP defines which method is to be compiled into libc  
E 15
I 15
D 19
# to use the nameserver or /etc/hosts. HOSTLOOKUP defines which method
E 19
I 19
# to use the name server or /etc/hosts. HOSTLOOKUP defines which method
E 19
# is to be compiled into libc  :
E 15
E 14
#								     
D 14
#		defining RESOLVER to res_named, compiles the         
E 14
I 14
D 15
#		defining HOSTLOOKUP to be "named", compiles the         
E 14
#		routines which the BIND nameserver uses into libc    
#---------------------------------------------------------------------
D 14
#RESOLVER=	res_named
E 14
I 14
#HOSTLOOKUP=	named
E 14
#---------------------------------------------------------------------
D 14
#		defining RESOLVER to res_static, compiles            #
#		the routines which use the old method of             #
#		hostname resolveing. (ie /etc/HOSTS )                #
E 14
I 14
#		defining HOSTLOOKUP to "hosttable", compiles
#		the routines which use the old method of
#		hostname lookup. (ie /etc/hosts )
E 14
#---------------------------------------------------------------------
E 15
I 15
#	defining HOSTLOOKUP to be "named", compiles the         
D 19
#	host lookup routines that use the BIND nameserver.
E 19
I 19
#	host lookup routines that use the BIND name server.
E 19
#
#	defining HOSTLOOKUP to be "hosttable", compiles
#	the host lookup routines that use /etc/hosts.
#
E 15
D 14
RESOLVER=	res_static
E 14
I 14
D 18
HOSTLOOKUP=	hosttable
I 15
#HOSTLOOKUP=	named
E 18
I 18
#HOSTLOOKUP=	hosttable
HOSTLOOKUP=	named
E 18
D 27
#							
E 27
I 27
#
E 27
E 15
E 14
E 13
E 12
E 5
E 2
D 31
DESTDIR=
I 2
D 27
INSTALL=install -m 644
E 27
D 4
DFLMON=mon.o
E 4
I 4
DFLMON=	mon.o
D 5
ALL=	csu sys gen stdio net
E 5
I 5
D 21
MACHINE=vax
E 21
I 21
D 25
#ifdef vax
#MACHINE=vax
#endif
MACHINE=tahoe
E 25
E 21
I 12
DEFS=
E 12
D 6
COPMAT=	4.1compat
E 6
I 6
D 30
COMPAT=	compat-4.1 compat-sys5
E 30
I 30
COMPAT=	compat-4.1 compat-4.3 compat-sys5
E 30
E 6
D 18
ALL=	gen inet net stdio ${MACHINE} ${COMPAT}
E 18
I 18
ALL=	gen inet net ns stdio ${MACHINE} ${COMPAT}
E 31
I 31
# The system has two monitoring schemes, utilizing either ``prof''
# or ``gprof''. DFLMON determines the default profiler; mon.o
# specifies that ``prof'' is the default, gmon.o specifies that
# ``gprof'' is the default.
#DFLMON=	gmon.o
DFLMON=		mon.o
#
# All library object contain sccsid strings by default; they may be
# excluded as a space-saving measure.  To produce a library that does
# not contain these strings, remove -DLIBC_SCCS and -DSYSLIBC_SCCS
# from DEFS below.  To remove these strings from just the system call
# stubs, remove -DSYSLIBC_SCCS from DEFS below.
#DEFS=
DEFS="-DLIBC_SCCS -DSYSLIBC_SCCS"

D 34
ALL=	compat-4.1 compat-4.1/compat-4.1.${MACHINE} compat-4.3 \
	compat-sys5 gen gen/gen.${MACHINE} inet net net/net.${MACHINE} \
	net/${HOSTLOOKUP} ns stdio stdio/stdio.${MACHINE} \
	${MACHINE}/csu ${MACHINE}/sys
E 34
SUBDIR=	${ALL} net/hosttable net/named
I 32
D 36
ONE=	compat-4.1 compat-4.3 compat-sys5 gen inet net ns stdio
E 36
I 36
ONE=	compat-4.1 compat-4.3 compat-sys5 gen inet net ns stdio cal
E 36
TWO=	compat-4.1/compat-4.1.${MACHINE} gen/gen.${MACHINE} \
	net/net.${MACHINE} net/${HOSTLOOKUP} stdio/stdio.${MACHINE} \
I 36
	cal/cal.${MACHINE} \
E 36
D 34
	${MACHINE}/csu ${MACHINE}/sys
E 34
I 34
	compat-sys5/compat-sys5.${MACHINE} ${MACHINE}/csu ${MACHINE}/sys
ALL=	${ONE} ${TWO}
E 34
E 32
E 31
E 18
I 10
TAGSFILE=tags
E 10
E 5
E 4
E 2

D 2
INSTALL=mv

all: libc.a libc_p.a crtx

libc.a libc_p.a:
E 2
I 2
D 4
libc.a libc_p.a: csu sys gen stdio net
E 4
I 4
D 5
libc.a libc_p.a: ${ALL}
E 4
	cd csu; make
E 2
	cd sys; make
	cd gen; make
	cd stdio; make
	cd net; make
E 5
I 5
D 14
libc.a libc_p.a: ${MACHINE}/csu ${ALL}
E 14
I 14
D 31
libc.a libc_p.a: ${MACHINE}/csu ${ALL} net/${HOSTLOOKUP}
I 16
	rm -rf t1 tmp
E 16
E 14
E 5
D 3
	mkdir tmp
E 3
I 3
	-mkdir tmp
E 3
D 5
	cd tmp; ar x ../sys/syslib
	cd tmp; ar x ../gen/genlib
	cd tmp; ar x ../stdio/stdiolib
	cd tmp; ar x ../net/netlib
E 5
I 5
	for i in ${ALL}; do (cd tmp; ar x ../$$i/$${i}lib); done
I 14
	cd tmp; ar x ../net/${HOSTLOOKUP}/hostlib
E 14
E 5
	ls tmp/*.o | sort -t/ +1 > t1
E 31
I 31
D 33
libc.a libc_p.a: mkdir ${ALL}
E 33
I 33
libc.a libc_p.a: mkdir ${ALL} tags
E 33
	ls library/*.o | sort -t/ +1 > t1
E 31
D 2
	ar ar libc.a `lorder \`cat t1\` | tsort`;
E 2
I 2
D 5
	ar cr libc.a `lorder \`cat t1\` | tsort` csu/${DFLMON}
E 5
I 5
	ar cr libc.a `lorder \`cat t1\` | tsort` ${MACHINE}/csu/${DFLMON}
E 5
E 2
D 9
	ar ma flsbuf.o libc.a exit.o
E 9
I 9
	ar ma findiop.o libc.a exit.o
E 9
I 7
	ar ma exit.o libc.a fakcu.o
E 7
D 31
	rm -f t1 tmp/*
D 5
	cd tmp; ar x ../sys/syslib_p
	cd tmp; ar x ../gen/genlib_p
	cd tmp; ar x ../stdio/stdiolib_p
	cd tmp; ar x ../net/netlib_p
E 5
I 5
	for i in ${ALL}; do (cd tmp; ar x ../$$i/$${i}lib_p); done
I 14
	cd tmp; ar x ../net/${HOSTLOOKUP}/hostlib_p
E 14
E 5
	ls tmp/*.o | sort -t/ +1 > t1
E 31
I 31
	ls profiled/*.o | sort -t/ +1 > t1
E 31
D 2
	ar ar libc_p.a `lorder \`cat t1\` | tsort`;
E 2
I 2
D 5
	ar cr libc_p.a `lorder \`cat t1\` | tsort` csu/${DFLMON}
E 5
I 5
	ar cr libc_p.a `lorder \`cat t1\` | tsort` ${MACHINE}/csu/${DFLMON}
E 5
E 2
D 9
	ar ma flsbuf.o libc_p.a exit.o
E 9
I 9
	ar ma findiop.o libc_p.a exit.o
E 9
I 7
D 8
	ar ma exit.o libc.a fakcu.o
E 8
I 8
	ar ma exit.o libc_p.a fakcu.o
E 8
E 7
D 31
	rm -rf t1 tmp
E 31
I 31
	rm -rf t1 library profiled
E 31

D 2
crtx:
	cd csu; make

E 2
D 5
clean:
D 4
	for i in */.; do cd $$i; make clean; cd ..; done
E 4
I 4
	for i in ${ALL}; do cd $$i; make clean; cd ..; done
E 4
	rm -f t1 *.o
E 5
I 5
D 14
${MACHINE}/csu ${ALL}: FRC
E 14
I 14
D 31
${MACHINE}/csu ${ALL} net/${HOSTLOOKUP}: FRC
E 14
D 12
	cd $@; make ${MFLAGS}
E 12
I 12
	cd $@; make ${MFLAGS} DEFS=${DEFS}
E 31
I 31
mkdir: FRC
	rm -rf library profiled
	mkdir library profiled
E 31
E 12
E 5

D 5
errlst.o: gen/errlst.c
	cc -S gen/errlst.c
	ed - <gen/:errfix errlst.s
	as -o errlst.o errlst.s
	rm errlst.s
E 5
I 5
D 31
FRC:
E 31
I 31
${ALL}: FRC
	cd $@; make ${MFLAGS} DEFS=${DEFS} link
E 31
E 5

D 2
install: all
E 2
I 2
D 5
install: libc.a libc_p.a
E 5
I 5
D 10
clean:
	for i in ${MACHINE}/csu ${ALL}; do (cd $$i; make ${MFLAGS} clean); done
	rm -f t1 tmp/*.o
	-rmdir tmp

E 10
install: 
E 5
E 2
D 4
	$(INSTALL) libc.a $(DESTDIR)/lib/libc.a
	ranlib $(DESTDIR)/lib/libc.a
	$(INSTALL) libc_p.a $(DESTDIR)/usr/lib/libc_p.a
	ranlib $(DESTDIR)/usr/lib/libc_p.a
E 4
I 4
D 27
	${INSTALL} libc.a ${DESTDIR}/lib/libc.a
E 27
I 27
	install -o bin -g bin -m 644 libc.a ${DESTDIR}/lib/libc.a
E 27
	ranlib ${DESTDIR}/lib/libc.a
D 27
	${INSTALL} libc_p.a ${DESTDIR}/usr/lib/libc_p.a
E 27
I 27
	install -o bin -g bin -m 644 libc_p.a ${DESTDIR}/usr/lib/libc_p.a
E 27
	ranlib ${DESTDIR}/usr/lib/libc_p.a
E 4
D 2
	cd csu; $(INSTALL) crt0.o $(DESTDIR)/lib
	cd csu; $(INSTALL) mcrt0.o $(DESTDIR)/lib
	cd csu; $(INSTALL) gcrt0.o $(DESTDIR)/usr/lib
E 2
I 2
D 5
	cd csu; make DESTDIR=${DESTDIR} install
E 5
I 5
	cd ${MACHINE}/csu; make DESTDIR=${DESTDIR} install
I 33
	install -o bin -g bin -m 444 ${TAGSFILE} ${DESTDIR}/usr/lib/${TAGSFILE}
E 33
I 22
D 23
	install -c ${TAGSFILE} ${DESTDIR}/usr/lib/${TAGSFILE}
E 23
E 22
I 10

tags:
D 32
	for i in ${ALL}; do \
D 31
		(cd $$i; make ${MFLAGS} TAGSFILE=../${TAGSFILE} tags); \
E 31
I 31
		(cd $$i; make ${MFLAGS} TAGSFILE=`pwd`/${TAGSFILE} tags); \
E 32
I 32
	for i in ${ONE}; do \
		(cd $$i; make ${MFLAGS} TAGSFILE=../${TAGSFILE} tags); \
	done
	for i in ${TWO}; do \
		(cd $$i; make ${MFLAGS} TAGSFILE=../../${TAGSFILE} tags); \
E 32
E 31
I 18
	done
E 18
I 14
D 22
D 31
	cd net/${HOSTLOOKUP}; \
		make ${MFLAGS} TAGSFILE=../../${TAGSFILE} tags
E 31
I 24
	sort -o ${TAGSFILE} ${TAGSFILE}
E 24
E 22
I 22
	/usr/bin/sort -o ${TAGSFILE} ${TAGSFILE}
E 22
E 14
D 18
	done
E 18
D 11
	sort -u +0 -1 tags -o tags
E 11

clean:
D 14
	for i in ${MACHINE}/csu ${ALL}; do (cd $$i; make ${MFLAGS} clean); done
E 14
I 14
D 15
	for i in ${MACHINE}/csu ${ALL} net/${HOSTLOOKUP}; \
E 15
I 15
D 31
	for i in ${MACHINE}/csu ${ALL} net/hosttable net/named; \
E 31
I 31
	for i in ${SUBDIR}; \
E 31
E 15
		do (cd $$i; make ${MFLAGS} clean); done
E 14
D 28
	rm -f t1 tmp/*.o
	-rmdir tmp
E 28
I 28
D 29
	rm -rf tmp t1
E 29
I 29
D 31
	rm -rf tmp t1 libc.a libc_p.a
E 31
I 31
	rm -rf libc.a libc_p.a library profiled
E 31
E 29
E 28
I 15

depend:
D 26
	for i in ${MACHINE}/csu ${ALL} net/hosttable net/named; \
E 26
I 26
D 31
	for i in ${ALL} net/hosttable net/named; \
E 31
I 31
	for i in ${SUBDIR}; \
E 31
E 26
		do (cd $$i; make ${MFLAGS} DEFS=${DEFS} depend); done
I 31

FRC:

E 31
E 15
E 10
E 5
E 2
E 1
