h43245
s 00003/00003/00078
d D 5.3 04/09/13 01:54:02 msokolov 3 2
c add col8
e
s 00002/00001/00079
d D 5.2 99/01/17 00:02:20 msokolov 2 1
c add sccscmds subdir
e
s 00080/00000/00000
d D 5.1 99/01/17 00:00:25 msokolov 1 0
c This SCCS file has apparently been lost
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
DESTDIR=
CFLAGS=	-O
LIBC=	/lib/libc.a

# Programs that live in subdirectories, and have makefiles of their own.
#
SUBDIR=	at calendar dc diction diff3 efl eqn f77 find graph learn lex lint \
D 2
	m4 plot prof ratfor refer roff spell struct tbl tip uucp xsend yacc
E 2
I 2
	m4 plot prof ratfor refer roff spell struct tbl tip uucp xsend yacc \
	sccscmds
E 2

# Shell scripts that need only be installed and are never removed.
#
SCRIPT=	lorder mkdep nohup

# C source that lives in the current directory
#
D 3
SRCS=	ar11.c basename.c bc.c cal.c cb.c checkeq.c col.c comm.c crypt.c \
	deroff.c file.c install.c join.c look.c mesg.c ptx.c \
E 3
I 3
SRCS=	ar11.c basename.c bc.c cal.c cb.c checkeq.c col.c col8.c comm.c \
	crypt.c deroff.c file.c install.c join.c look.c mesg.c ptx.c \
E 3
	ranlib.c rev.c sleep.c sort.c spline.c split.c sum.c tabs.c \
	tc.c tk.c touch.c tr.c tsort.c tty.c uniq.c units.c

# C programs that live in the current directory and do not need
# explicit make lines.
#
D 3
STD=	ar11 basename bc cal cb checkeq col comm crypt deroff \
E 3
I 3
STD=	ar11 basename bc cal cb checkeq col col8 comm crypt deroff \
E 3
	file join look mesg ptx ranlib rev sleep sort spline split \
	sum tabs tc tk touch tr tsort tty uniq units

# C programs that live in the current directory and need explicit make lines.
#
NSTD=	xinstall

# Programs that get installed with special permissions
#
PERM=	iostat

all: ${SUBDIR} ${STD} ${PERM} ${NSTD}

${SUBDIR}: FRC
	cd $@; make ${MFLAGS}

bc: bc.c ${LIBC}
${STD} ${PERM}: ${LIBC}
	${CC} ${CFLAGS} -o $@ $@.c

install: FRC
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
	-for i in ${SCRIPT}; do \
		(install -c -o bin -g bin -m 555 $$i.sh ${DESTDIR}/usr/bin/$$i); done
	install -s -o bin -g bin -m 755 ${STD} ${DESTDIR}/usr/bin
	install -s -o bin -g bin -m 755 install ${DESTDIR}/usr/bin/install
	install -s -o bin -g kmem -m 2755 iostat ${DESTDIR}/usr/bin/iostat
	install -c -o bin -g bin -m 755 units.lib ${DESTDIR}/usr/lib/units

clean: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
	rm -f a.out core *.s *.o bc.c y.tab.c install ${STD} ${NSTD} ${PERM}

depend: ldepend
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done

ldepend: ${SRCS} FRC
	mkdep -p ${CFLAGS} ${SRCS}

FRC:

# Files listed in ${NSTD} have explicit make lines given below.

xinstall:
	${CC} ${CFLAGS} install.c -o install

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 1
