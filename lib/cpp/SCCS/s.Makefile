h38714
s 00045/00017/00011
d D 1.5 87/06/06 14:31:47 bostic 5 4
c new template
e
s 00002/00000/00026
d D 1.4 87/05/30 14:18:10 bostic 4 3
c added depend label
e
s 00003/00002/00023
d D 1.3 86/10/15 21:12:12 sam 3 2
c mv :yyfix
e
s 00002/00003/00023
d D 1.2 83/07/02 23:31:27 sam 2 1
c no need for -Dvax
e
s 00026/00000/00000
d D 1.1 82/08/30 10:04:13 rrh 1 0
c date and time created 82/08/30 10:04:13 by rrh
e
u
U
t
T
I 2
D 5
#	%M%	%I%	%E%
E 5
E 2
I 1
#
D 2
# %Z%%M% %I% %G%
#
E 2
D 5

D 2
CFLAGS=-O -Dunix=1 -Dvax=1 -DFLEXNAMES
E 2
I 2
D 3
CFLAGS=-O -Dunix=1 -DFLEXNAMES
E 3
I 3
YYFIX=	../pcc/pcc.`machine`/:yyfix
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 5
CFLAGS=	-O -Dunix=1 -DFLEXNAMES
I 5
LIBC=	/lib/libc.a
YYFIX=	../pcc/pcc.${MACHINE}/:yyfix
SRCS=	cpp.c cpy.c rodata.c
OBJS=	cpp.o cpy.o rodata.o
E 5
E 3
E 2

D 5
cpp :	cpp.o cpy.o rodata.o
	$(CC) $(CFLAGS) -o cpp rodata.o cpp.o cpy.o  
E 5
I 5
all: cpp
E 5

D 5
cpy.c : cpy.y
E 5
I 5
cpp:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}

cpy.c: cpy.y
E 5
	yacc cpy.y
D 3
	../pcc/:yyfix yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 3
I 3
	${YYFIX} yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 3
	mv y.tab.c cpy.c
D 5
cpy.o :	cpy.c yylex.c
rodata.o : cpy.c
	$(CC) $(CFLAGS) -R -c rodata.c
E 5

D 5
clean :
	rm -f *.s *.o cpy.c rodata.c
E 5
I 5
cpy.o: cpy.c yylex.c
E 5

D 5
install :
	install -s cpp $(DESTDIR)/lib
E 5
I 5
rodata.o: cpy.c
	${CC} ${CFLAGS} -R -c rodata.c
E 5

I 4
D 5
depend :
E 5
I 5
clean: FRC
	rm -f ${OBJS} cpp core cpy.c rodata.c
E 5

E 4
D 5
sources : cpp.c cpy.y yylex.c README
cpp.c cpy.y yylex.c README :
	sccs get $@
E 5
I 5
depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 cpp ${DESTDIR}/lib/cpp

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

cpp.o: cpp.c /usr/include/sys/param.h /usr/include/sys/types.h
cpp.o: /usr/include/signal.h /usr/include/machine/machparam.h
cpp.o: /usr/include/stdio.h /usr/include/ctype.h
cpy.o: cpy.c
cpy.o:yylex.c
rodata.o: rodata.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1
