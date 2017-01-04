h22534
s 00010/00005/00084
d D 5.8 88/07/09 11:14:36 bostic 20 19
c install approved copyright notice
e
s 00001/00000/00088
d D 5.7 88/05/20 15:00:45 bostic 19 18
c set DEFS to compile in SCCS ids.
e
s 00013/00008/00075
d D 5.6 88/05/20 13:45:32 bostic 18 17
c restructuring libc
e
s 00016/00029/00067
d D 5.5 87/06/06 15:27:29 bostic 17 14
c new template
e
s 00016/00029/00067
d R 5.5 87/06/06 15:26:23 bostic 16 14
c new template
e
s 00013/00026/00070
d R 5.5 87/06/06 14:41:52 bostic 15 14
c new template
e
s 00027/00001/00069
d D 5.4 85/09/05 11:36:24 bloom 14 12
c fix make clean and add make depend
e
s 00027/00001/00069
d R 5.4 85/09/05 10:45:46 bloom 13 12
c fix make clean and add make depend
e
s 00002/00002/00068
d D 5.3 85/06/21 16:55:40 mckusick 12 11
c pass through DEFS
e
s 00009/00001/00061
d D 5.2 85/05/30 22:35:41 sam 11 10
c add tags
e
s 00006/00001/00056
d D 5.1 85/05/30 14:53:19 dist 10 9
c Add copyright
e
s 00008/00010/00049
d D 4.7 82/12/10 17:08:52 peter 9 8
c use ex scripts instead of /lib/cpp.
e
s 00044/00027/00015
d D 4.6 82/12/04 16:16:15 mckusick 8 7
c break out "monitor" into separate file for jkf
e
s 00011/00009/00031
d D 4.5 82/11/22 18:08:08 mckusick 7 6
c fix up so that "make" does not bomb out on re-compiles
e
s 00002/00002/00038
d D 4.4 82/10/28 19:21:35 mckusick 6 5
c do not remove .s files so that .o files need not always be remade
e
s 00026/00016/00014
d D 4.3 82/04/19 17:11:23 rrh 5 4
c Putting to bed; don't know the changes
e
s 00009/00000/00021
d D 4.2 82/01/05 15:18:12 mckusic 4 3
c change _start to start
e
s 00000/00000/00021
d D 4.1 81/11/29 23:32:41 mckusic 3 2
c renumber to version 4
e
s 00011/00011/00010
d D 1.2 81/11/29 17:19:41 mckusic 2 1
c conversion to start written in C
e
s 00021/00000/00000
d D 1.1 81/11/23 22:42:23 mckusick 1 0
c date and time created 81/11/23 22:42:23 by mckusick
e
u
U
t
T
I 1
D 10
# %W% (Berkeley) %G%
E 10
I 10
#
D 18
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 18
I 18
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 18
#
I 18
# Redistribution and use in source and binary forms are permitted
D 20
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
#
E 18
#	%W% (Berkeley) %G%
E 10
D 5

E 5
I 5
#
#	crt0	Normal C run time startoff
#	mcrt0	C run time start off for profiling, ``prof'' conventions
#	gcrt0	C run time start off for profiling, ``gprof'' conventions
#
I 19
DEFS=-DLIBC_SCCS
E 19
E 5
D 8
OBJS=	crt0.o mcrt0.o gcrt0.o
E 8
I 8
D 18
DESTDIR=
E 18
I 11
SRCS=	crt0.c mon.c gmon.c
E 11
OBJS=	crt0.o mcrt0.o gcrt0.o mon.o gmon.o
I 11
TAGSFILE=tags
E 11
E 8

D 2
.s.o:
	${AS} -o $*.o $*.s
	-ld -x -r $*.o
E 2
I 2
D 5
.c.o:
	cc -S ${DFLAGS} $*.c
	ex - $*.s < crt0.ex
	/lib/cpp $*.s > $*.S
	mv $*.S $*.s
	as -o $*.o $*.s
	ld -x -r $*.o
E 2
	mv a.out $*.o
I 2
	rm -f $*.s
E 2

E 5
D 18
all: ${OBJS}
E 18
I 18
all link: ${OBJS}
E 18

I 4
D 5
crt0.o: crt0.c
	cc -S ${DFLAGS} $*.c
E 5
I 5
D 18
install: ${OBJS}
E 18
I 18
install:
E 18
D 8
	mv crt0.o /lib/crt0.o
	mv mcrt0.o /lib/mcrt0.o
	mv gcrt0.o /usr/lib/gcrt0.o
E 8
I 8
D 17
	mv crt0.o ${DESTDIR}/lib/crt0.o
	mv mcrt0.o ${DESTDIR}/lib/mcrt0.o
	mv gcrt0.o ${DESTDIR}/usr/lib/gcrt0.o
E 17
I 17
	install -o bin -g bin -m 444 crt0.o ${DESTDIR}/lib/crt0.o
	install -o bin -g bin -m 444 mcrt0.o ${DESTDIR}/lib/mcrt0.o
	install -o bin -g bin -m 444 gcrt0.o ${DESTDIR}/usr/lib/gcrt0.o
E 17
E 8

D 8
crt0.s:	cmgt.crt0.c
	cc -S ${DFLAGS} -DCRT0 cmgt.crt0.c
D 7
	mv cmgt.crt0.s crt0.s
mcrt0.s: cmgt.crt0.c
E 7
I 7
	/lib/cpp cmgt.crt0.s > crt0.s
	rm -f cmgt.crt0.s
mcrt0.s: cmgt.crt0.c crt0.ex
E 7
	cc -S ${DFLAGS} -DMCRT0 cmgt.crt0.c
D 7
	mv cmgt.crt0.s mcrt0.s
gcrt0.s: cmgt.crt0.c gcrt0.h
E 7
I 7
	ex - cmgt.crt0.s < crt0.ex
	/lib/cpp cmgt.crt0.s > mcrt0.s
	rm -f cmgt.crt0.s
gcrt0.s: cmgt.crt0.c gcrt0.h crt0.ex
E 7
	cc -S ${DFLAGS} -DGCRT0 cmgt.crt0.c
D 7
	mv cmgt.crt0.s gcrt0.s
E 7
I 7
	ex - cmgt.crt0.s < crt0.ex
	/lib/cpp cmgt.crt0.s > gcrt0.s
	rm -f cmgt.crt0.s
E 8
I 8
D 18
crt0.o:	crt0.c
E 18
I 18
crt0.o: crt0.c
E 18
D 17
	cc -S ${DFLAGS} -DCRT0 crt0.c
E 17
I 17
	${CC} -S ${DFLAGS} -DCRT0 crt0.c
E 17
	/lib/cpp crt0.s > x.s
	as -o x.o x.s
	ld -x -r -o crt0.o x.o
	rm -f x.s x.o crt0.s
E 8
E 7

D 7
.s.o: crt0.ex
	ex - $*.s < crt0.ex
E 5
	/lib/cpp $*.s > $*.S
	mv $*.S $*.s
E 7
I 7
D 8
.s.o:
E 7
	as -o $*.o $*.s
	ld -x -r $*.o
	mv a.out $*.o
E 8
I 8
moncrt0.o: crt0.c
D 17
	cc -S ${DFLAGS} -DMCRT0 crt0.c
E 17
I 17
	${CC} -S ${DFLAGS} -DMCRT0 crt0.c
E 17
	/lib/cpp crt0.s > x.s
	as -o x.o x.s
	ld -x -r -o moncrt0.o x.o
	rm -f x.s x.o crt0.s
E 8
D 6
	rm -f $*.s
E 6
I 6

I 8
gcrt0.o: moncrt0.o gmon.o
	ld -x -r -o gcrt0.o moncrt0.o gmon.o

mcrt0.o: moncrt0.o mon.o
	ld -x -r -o mcrt0.o moncrt0.o mon.o

D 9
mon.o: mon.c mcount.ex
E 9
I 9
mon.o: mon.c mon.ex
E 9
D 12
	cc -S ${DFLAGS} mon.c
E 12
I 12
D 17
	cc -S ${DEFS} ${DFLAGS} mon.c
E 17
I 17
	${CC} -S ${DEFS} ${DFLAGS} mon.c
E 17
E 12
D 9
	ex - mon.s < mcount.ex
	/lib/cpp mon.s > x.s
	as -o x.o x.s
E 9
I 9
	ex - mon.s < mon.ex
	as -o x.o mon.s
E 9
	ld -x -r -o mon.o x.o
D 9
	rm -f x.s x.o mon.s
E 9
I 9
	rm -f x.o mon.s
E 9

D 9
gmon.o: gmon.c gmon.h mcount.ex
E 9
I 9
gmon.o: gmon.c gmon.h gmon.ex
E 9
D 12
	cc -S ${DFLAGS} gmon.c
E 12
I 12
D 17
	cc -S ${DEFS} ${DFLAGS} gmon.c
E 17
I 17
	${CC} -S ${DEFS} ${DFLAGS} gmon.c
E 17
E 12
D 9
	ex - gmon.s < mcount.ex
	/lib/cpp gmon.s > x.s
	as -o x.o x.s
E 9
I 9
	ex - gmon.s < gmon.ex
	as -o x.o gmon.s
E 9
	ld -x -r -o gmon.o x.o
D 9
	rm -f x.s x.o gmon.s
E 9
I 9
	rm -f x.o gmon.s
E 9

I 11
D 17
tags:	
E 17
I 17
tags:
E 17
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

E 11
E 8
E 6
D 5

E 5
E 4
D 2
gcrt0.o: gcrt0.c gcrt0.h gcrt0.ex
	cc -S ${DFLAGS} gcrt0.c
	ex - gcrt0.s < gcrt0.ex
	/lib/cpp gcrt0.s > gcrt0.S
	mv gcrt0.S gcrt0.s
	as -o gcrt0.o gcrt0.s
	rm -f gcrt0.s

E 2
clean:
D 6
	rm -f ${OBJS}
E 6
I 6
D 8
	rm -f ${OBJS} *.s
E 8
I 8
D 11
	rm -f ${OBJS} *.o *.s core errs
E 11
I 11
D 14
	rm -f ${OBJS} *.o *.s core errs tags
E 14
I 14
D 17
	rm -f ${OBJS} *.o *.s core errs tags Makefile.bak
E 17
I 17
D 18
	rm -f ${OBJS} *.o *.s core errs tags
E 18
I 18
	rm -f *.o a.out core ${TAGSFILE}
E 18
E 17
E 14
E 11
E 8
E 6
I 2

D 5
${OBJS}: crt0.ex
gcrt0.o: gcrt0.h
E 5
I 5
D 8
lint:	cmgt.crt0.c
	lint cmgt.crt0.c -DMCRT0
	lint cmgt.crt0.c -DGCRT0
	lint cmgt.crt0.c -DCRT0
E 8
I 8
lint:	crt0.c
	lint crt0.c -DMCRT0
	lint crt0.c -DGCRT0
	lint crt0.c -DCRT0
I 14

depend:
D 17
	for i in ${SRCS}; do \
	    cc -M ${DEFS} ${DFLAGS} $$i | awk ' { if ($$1 != prev) \
		{ if (rec != "") print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec } ' >> makedep; done
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 17
I 17
	mkdep ${CFLAGS} ${SRCS}
E 17

D 17
# DO NOT DELETE THIS LINE -- make depend uses it
E 17
I 17
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 17

crt0.o: crt0.c
mon.o: mon.c
D 17
gmon.o: gmon.c ./gmon.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 17
I 17
gmon.o: gmon.c
gmon.o:gmon.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 17
E 14
E 8
E 5
E 2
E 1
