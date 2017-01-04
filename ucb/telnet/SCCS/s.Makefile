h26183
s 00010/00005/00103
d D 1.11 88/07/09 10:41:42 bostic 11 10
c install approved copyright notice
e
s 00001/00001/00107
d D 1.10 88/06/27 22:10:24 minshall 10 9
c Clean up "tags" file.
e
s 00018/00005/00090
d D 1.9 88/06/27 22:07:40 minshall 9 8
c Make "tags" and "lint" work.
e
s 00050/00032/00045
d D 1.8 88/03/21 22:18:49 minshall 8 7
c New structure; new 'make depend'.
e
s 00009/00003/00068
d D 1.7 88/03/08 10:30:41 bostic 7 6
c add Berkeley specific copyright
e
s 00000/00001/00071
d D 1.6 88/02/17 22:31:50 bostic 6 5
c compile optimized
e
s 00001/00000/00071
d D 1.5 87/10/10 14:27:19 minshall 5 4
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00060/00116/00011
d D 1.4 87/10/10 12:35:56 minshall 4 3
c This is the approved style.
e
s 00002/00002/00125
d D 1.3 87/09/25 14:50:15 minshall 3 2
c Incorporate tn3270.c.
e
s 00001/00001/00126
d D 1.2 87/09/11 15:59:30 minshall 2 1
c Correct .h files.
e
s 00127/00000/00000
d D 1.1 87/09/11 15:40:53 minshall 1 0
c date and time created 87/09/11 15:40:53 by minshall
e
u
U
t
T
I 1
D 4
# msdos versus unix defines
O	= .o
#PC_O	= .obj
E 4
I 4
#
# Copyright (c) 1987 Regents of the University of California.
D 7
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 7
I 7
# All rights reserved.
E 7
#
D 7
#	%W%	(Berkeley)	%G%
E 7
I 7
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
#	%W% (Berkeley) %G%
E 7
#
D 8
CFLAGS=	-O
E 8
I 8

# The following is the telnet makefile.  The sources are down one level
# in directory "Source" because the sources are shared between telnet
# and tn3270.

VPATH	=	Source
INCLUDES=	-ISource
CFLAGS=	-O ${INCLUDES}
E 8
I 5
D 6
CFLAGS=	-g
E 6
E 5
LIBC=	/lib/libc.a
D 8
SRCS=	commands.c main.c network.c ring.c sys_bsd.c sys_dos.c \
	telnet.c terminal.c tn3270.c utilities.c
E 8
I 8
SRCS=	commands.c main.c network.c ring.c \
	sys_bsd.c sys_dos.c telnet.c terminal.c \
	tn3270.c utilities.c
I 9

ALLHC=	${SRCS} \
	Source/defines.h Source/externs.h Source/fdset.h Source/general.h \
	Source/ring.h Source/types.h

E 9
E 8
OBJS=	commands.o main.o network.o ring.o sys_bsd.o sys_dos.o \
	telnet.o terminal.o tn3270.o utilities.o
E 4

D 4
X	=
#PC_X	= .exe
E 4
I 4
all: telnet
E 4

D 4
L	=
#PC_L	= -link
E 4
I 4
telnet:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 4

D 4
CC	= cc
#PC_CC	= cl
E 4
I 4
clean: FRC
D 10
	rm -f ${OBJS} core telnet
E 10
I 10
	rm -f ${OBJS} core errs l.errs tags telnet
E 10
E 4

I 9
clist:	FRC ${SRCS}
	@for i in ${SRCS} ; \
		do (echo ${DIRPATH}$$i); done

hclist:	FRC ${ALLHC}
	@for i in ${ALLHC} ; \
		do (echo ${DIRPATH}$$i); done

E 9
D 4
MV	= mv
#PC_MV	= rename
E 4
I 4
D 8
depend: FRC
E 8
I 8
depend: FRC ${SRCS}
E 8
D 9
	mkdep ${CFLAGS} ${SRCS}
E 9
I 9
	mkdep ${CFLAGS} `make clist`
E 9
E 4

D 4
RM	= rm -f
#PC_RM= erase
E 4
I 4
install: FRC
	install -s -o bin -g bin -m 755 telnet ${DESTDIR}/usr/ucb/telnet
E 4

D 4
LINT_ARGS =
#PC_LINT_ARGS = -DLINT_ARGS
E 4
I 4
D 9
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 9
I 9
lint: FRC ${SRCS}
	lint ${CFLAGS} `make clist`
E 9
E 4

D 4
DEBUG_FLAGS = -g
#PC_DEBUG_FLAGS = -Zi -Od
E 4
I 4
D 9
tags: FRC
	ctags ${SRCS}
E 9
I 9
tags: FRC ${SRCS}
	ctags `make hclist`
E 9
E 4

D 4
AR	= ar
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 4
I 4
FRC:
E 4

D 4
RANLIB	= ranlib
#PC_RANLIB = echo "Done with "
E 4
I 4
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 4

D 4
PRINT	= print
E 4
I 4
D 8
commands.o: commands.c /usr/include/sys/types.h /usr/include/sys/socket.h
commands.o: /usr/include/netinet/in.h /usr/include/signal.h
commands.o: /usr/include/machine/trap.h /usr/include/netdb.h
commands.o: /usr/include/ctype.h /usr/include/arpa/telnet.h externs.h
commands.o: /usr/include/stdio.h /usr/include/setjmp.h defines.h types.h
main.o: main.c externs.h /usr/include/stdio.h /usr/include/setjmp.h defines.h
network.o: network.c /usr/include/sys/types.h /usr/include/sys/socket.h
E 8
I 8
commands.o: Source/commands.c /usr/include/sys/types.h
commands.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
commands.o: /usr/include/signal.h /usr/include/machine/trap.h
commands.o: /usr/include/netdb.h /usr/include/ctype.h
commands.o: /usr/include/arpa/telnet.h Source/ring.h Source/externs.h
commands.o: /usr/include/stdio.h /usr/include/setjmp.h Source/defines.h
commands.o: Source/types.h
main.o: Source/main.c /usr/include/sys/types.h Source/ring.h Source/externs.h
main.o: /usr/include/stdio.h /usr/include/setjmp.h Source/defines.h
network.o: Source/network.c /usr/include/sys/types.h /usr/include/sys/socket.h
E 8
network.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
D 8
network.o: /usr/include/arpa/telnet.h defines.h externs.h /usr/include/stdio.h
network.o: /usr/include/setjmp.h
sys_bsd.o: sys_bsd.c /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
sys_bsd.o: /usr/include/sys/ttydev.h /usr/include/sys/time.h
sys_bsd.o: /usr/include/time.h /usr/include/signal.h
sys_bsd.o: /usr/include/machine/trap.h defines.h externs.h /usr/include/stdio.h
sys_bsd.o: /usr/include/setjmp.h types.h
sys_dos.o: sys_dos.c
telnet.o: telnet.c /usr/include/sys/types.h /usr/include/sys/time.h
telnet.o: /usr/include/time.h /usr/include/sys/socket.h
telnet.o: /usr/include/netinet/in.h /usr/include/curses.h /usr/include/stdio.h
telnet.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 8
I 8
network.o: /usr/include/arpa/telnet.h Source/ring.h Source/defines.h
network.o: Source/externs.h /usr/include/stdio.h /usr/include/setjmp.h
network.o: Source/fdset.h
ring.o: Source/ring.c /usr/include/stdio.h /usr/include/errno.h
ring.o: /usr/include/sys/types.h /usr/include/sys/ioctl.h
ring.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ring.o: /usr/include/sys/socket.h Source/ring.h Source/general.h
sys_bsd.o: Source/sys_bsd.c /usr/include/sys/ioctl.h
sys_bsd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sys_bsd.o: /usr/include/sys/types.h /usr/include/sys/time.h /usr/include/time.h
sys_bsd.o: /usr/include/sys/socket.h /usr/include/signal.h
sys_bsd.o: /usr/include/machine/trap.h /usr/include/errno.h Source/ring.h
sys_bsd.o: Source/fdset.h Source/defines.h Source/externs.h
sys_bsd.o: /usr/include/stdio.h /usr/include/setjmp.h Source/types.h
sys_dos.o: Source/sys_dos.c
telnet.o: Source/telnet.c /usr/include/sys/types.h /usr/include/curses.h
telnet.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 8
telnet.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 8
telnet.o: /usr/include/arpa/telnet.h /usr/include/arpa/inet.h
telnet.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/netdb.h
telnet.o: /usr/include/strings.h defines.h externs.h /usr/include/stdio.h
telnet.o: /usr/include/setjmp.h types.h general.h
terminal.o: terminal.c /usr/include/arpa/telnet.h externs.h
terminal.o: /usr/include/stdio.h /usr/include/setjmp.h types.h
tn3270.o: tn3270.c
utilities.o: utilities.c /usr/include/arpa/telnet.h /usr/include/ctype.h
utilities.o: externs.h /usr/include/stdio.h /usr/include/setjmp.h
E 8
I 8
telnet.o: /usr/include/arpa/telnet.h /usr/include/strings.h Source/ring.h
telnet.o: Source/defines.h Source/externs.h /usr/include/stdio.h
telnet.o: /usr/include/setjmp.h Source/types.h Source/general.h
telnet.o: /usr/include/varargs.h
terminal.o: Source/terminal.c /usr/include/arpa/telnet.h
terminal.o: /usr/include/sys/types.h Source/ring.h Source/externs.h
terminal.o: /usr/include/stdio.h /usr/include/setjmp.h Source/types.h
tn3270.o: Source/tn3270.c Source/fdset.h
utilities.o: Source/utilities.c /usr/include/arpa/telnet.h
utilities.o: /usr/include/sys/types.h /usr/include/ctype.h Source/ring.h
utilities.o: Source/externs.h /usr/include/stdio.h /usr/include/setjmp.h
E 8
E 4

D 4
DEFINES = ${LINT_ARGS}

INCLUDES = -I.

OPTIMIZE = -O
OPTIMIZE = ${DEBUG_FLAGS}

CFLAGS	= $(OPTIMIZE) $(INCLUDES) $(DEFINES)

# Lint flags
LINTFLAGS	= -hbxaz

# The source files...
D 2
ALLH =	extern.h
E 2
I 2
ALLH =	defines.h externs.h general.h types.h
E 2

ALLC =	commands.c main.c network.c sys_bsd.c sys_dos.c telnet.c \
D 3
		terminal.c utilities.c
E 3
I 3
		terminal.c tn3270.c utilities.c
E 3

ALLO =	commands$O main$O network$O sys_bsd$O sys_dos$O telnet$O \
D 3
		terminal$O utilities$O
E 3
I 3
		terminal$O tn3270$O utilities$O
E 3

ALLPRINT =	${ALLH} ${ALLC}

ALLSOURCE =	${ALLPRINT} Makefile

.s.o:
	/lib/cpp -E $< | as -o $@

.c.obj:
	${CC} ${CFLAGS} -c $<

telnet$X:	${ALLO}
	${CC} ${CFLAGS} -o telnet ${ALLO}

clean:
	for i in $(ALLO) telnet$X errs \
		Makefile.bak; \
			do (${RM} $$i); done

sccsclean:
	-sccs clean
	-sccs get Makefile

sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
		do (echo ${DIRPATH}$$i); done

print:
	${PRINT} ${ALLPRINT}

tags:	${ALLC} ${ALLH}
	ctags -t ${ALLC} ${ALLH}

action:
	${ACTION}

lint:
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} ${ALLC} -lcurses

.DEFAULT:
	sccs get $<

depend:
	grep '^#include' ${ALLC} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
	    -e 's/\.c/$$O/' | \
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	-rm -f Makefile.bak
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

commands$O: externs.h defines.h types.h
main$O: externs.h
network$O: externs.h
sys_bsd$O: externs.h
telnet$O: externs.h types.h general.h
terminal$O: externs.h types.h
utilities$O: externs.h
E 4
I 4
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1
