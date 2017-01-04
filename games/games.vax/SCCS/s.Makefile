h52582
s 00010/00005/00055
d D 5.4 88/07/09 11:16:52 bostic 4 3
c install approved copyright notice
e
s 00017/00012/00043
d D 5.3 88/01/06 17:08:38 bostic 3 2
c Berkeley header, remove rogue
e
s 00015/00026/00040
d D 5.2 87/06/03 17:42:48 bostic 2 1
c new template
e
s 00066/00000/00000
d D 5.1 86/11/17 18:25:05 mckusick 1 0
c vax only games
e
u
U
t
T
I 1
#
D 3
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
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
# software without specific prior written permission. This software
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
E 3
#	%W% (Berkeley) %G%
#
D 3
DESTDIR=
E 3
CFLAGS=	-O

# Programs that live in subdirectories, and have makefiles of their own.
#
D 3
SUBDIR=	aard ching compat ddl rogue zork
E 3
I 3
SUBDIR=	aard ching compat ddl zork
E 3

I 2
# C sources that live in the current directory
#
SRCS=	chess.c

E 2
# C programs that live in the current directory and do not need
# explicit make lines.
#
STD=	chess

D 3
all:	${SUBDIR} ${STD}
E 3
I 3
all: ${SUBDIR} ${STD}
E 3

${SUBDIR}: FRC
	cd $@; make ${MFLAGS}

D 3
FRC:

E 3
${STD}:
D 2
	cc ${CFLAGS} -o $@ $@.c
E 2
I 2
	${CC} ${CFLAGS} -o $@ $@.c
E 2

D 3
install:
E 3
I 3
install: FRC
E 3
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
	-for i in ${STD}; do \
D 2
		(install -s $$i ${DESTDIR}/usr/games/$$i); done
	install -c chess.bin ${DESTDIR}/usr/games/lib/chess
E 2
I 2
		(install -s -o bin -g bin -m 755 $$i ${DESTDIR}/usr/games/$$i); \
	done
	install -c -o bin -g bin -m 444 chess.bin ${DESTDIR}/usr/games/lib/chess
E 2

D 3
clean:
D 2
	rm -f a.out core *.s *.o
E 2
I 2
	rm -f ${STD} a.out core *.s *.o
E 3
I 3
clean: FRC
E 3
E 2
	-for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
I 3
	rm -f ${STD} a.out core *.s *.o
E 3
D 2
	rm -f ${STD}
E 2

D 3
depend:
E 3
I 3
depend: FRC
E 3
D 2
	for i in ${STD}; do \
	    cc -M ${INCPATH} $$i.c | sed 's/\.o//' | \
	    awk ' { if ($$1 != prev) \
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
E 2
I 2
	-for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
	mkdep ${CFLAGS} ${SRCS}
I 3

FRC:
E 3
E 2

I 2
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 2

D 2
# DO NOT DELETE THIS LINE -- make depend uses it
E 2
I 2
chess.o: chess.c /usr/include/stdio.h
E 2

D 2
chess: chess.c /usr/include/stdio.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 2
I 2
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 2
E 1
