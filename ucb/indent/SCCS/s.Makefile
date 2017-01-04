h46265
s 00010/00005/00062
d D 5.8 88/06/29 19:40:27 bostic 10 9
c install approved copyright notice
e
s 00009/00003/00058
d D 5.7 88/03/10 08:41:38 bostic 9 8
c add Berkeley specific header
e
s 00044/00040/00017
d D 5.6 87/06/16 18:31:56 bostic 8 7
c new template
e
s 00003/00000/00054
d D 5.5 87/04/29 18:08:39 bostic 7 6
c added make tags
e
s 00035/00010/00019
d D 5.4 85/09/08 15:41:42 mckusick 6 5
c update on Sun stuff by Chris Torek
e
s 00002/00002/00027
d D 5.3 85/09/07 15:39:34 mckusick 5 4
c fix CFLAGS and install in ucb not usr/bin
e
s 00014/00004/00015
d D 5.2 85/08/28 13:48:23 mckusick 4 3
c kernel normal form (from sun!shannon)
e
s 00006/00001/00013
d D 5.1 85/06/04 13:39:23 dist 3 2
c Add copyright
e
s 00001/00001/00013
d D 4.2 82/10/22 00:02:14 mckusick 2 1
c add DESTDIR
e
s 00014/00000/00000
d D 4.1 82/10/21 23:57:06 mckusick 1 0
c date and time created 82/10/21 23:57:06 by mckusick
e
u
U
t
T
I 1
D 3
#	%W%	(Berkeley)	%G%
E 3
I 3
#
D 8
# Copyright (c) 1980 Regents of the University of California.
E 8
I 8
# Copyright (c) 1987 Regents of the University of California.
E 8
D 9
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 9
I 9
# All rights reserved.
E 9
#
D 8
#	%W% (Berkeley) %G%
E 8
I 8
D 9
#	%W%	(Berkeley)	%G%
E 9
I 9
# Redistribution and use in source and binary forms are permitted
D 10
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
#
#	%W% (Berkeley) %G%
E 9
E 8
E 3
#
D 8
DESTDIR=
E 8
D 4
CFLAGS=	-O
E 4
I 4
D 5
CFLAGS=	-g
E 5
I 5
CFLAGS=	-O
I 8
LIBC=	/lib/libc.a
E 8
E 5
E 4
D 6
OBJS=	indent.o io.o lexi.o parse.o pr_comment.o
E 6
I 6
SRCS=	indent.c io.c lexi.c parse.c pr_comment.c args.c
OBJS=	indent.o io.o lexi.o parse.o pr_comment.o args.o
E 6

D 6
indent: indent.o io.o lexi.o parse.o pr_comment.o
E 6
I 6
D 8
indent: ${OBJS}
E 6
D 4
	cc -o indent ${OBJS}
E 4
I 4
	cc ${CFLAGS} -o indent ${OBJS}
E 8
I 8
all: indent
E 8
E 4

D 8
clean:
D 6
	rm -f ${OBJS} indent
E 6
I 6
	rm -f ${OBJS} indent core
E 8
I 8
indent:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 8
E 6

I 7
D 8
tags:
	ctags ${SRCS}
E 8
I 8
clean: FRC
	rm -f ${OBJS} core indent
E 8

E 7
D 4
install:
D 2
	install -s indent /usr/ucb/indent
E 2
I 2
	install -s indent ${DESTDIR}/usr/ucb/indent
E 4
I 4
D 6
indent.o: indent.c
io.o: io.c
lexi.o: lexi.c
parse.o: parse.c
pr_comment.o: pr_comment.c
$(OBJS): indent_globs.h indent_codes.h

E 6
D 8
.DEFAULT:
	sccs get $<
E 8
I 8
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 8

D 8
install: indent
D 5
	install -s indent ${DESTDIR}/usr/bin/indent
E 5
I 5
	install -s indent ${DESTDIR}/usr/ucb/indent
E 8
I 8
install: FRC
	install -s -o bin -g bin -m 755 indent ${DESTDIR}/usr/ucb/indent
E 8
I 6

D 8
depend:
	cc -M ${SRCS} | \
	    awk '{ if ($$1 != prev) { if (rec != "") print rec; \
		rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec }' >makedep
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >> eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 8
I 8
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 8

D 8
# DO NOT DELETE THIS LINE -- make depend uses it
E 8
I 8
tags: FRC
	ctags ${SRCS}
E 8

D 8
indent.o: indent.c ./indent_globs.h /usr/include/stdio.h ./indent_codes.h
io.o: io.c ./indent_globs.h /usr/include/stdio.h
lexi.o: lexi.c ./indent_globs.h /usr/include/stdio.h ./indent_codes.h
E 8
I 8
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

indent.o: indent.c
indent.o:indent_globs.h
indent.o: /usr/include/stdio.h
indent.o:indent_codes.h
io.o: io.c
io.o:indent_globs.h
io.o: /usr/include/stdio.h
lexi.o: lexi.c
lexi.o:indent_globs.h
lexi.o: /usr/include/stdio.h
lexi.o:indent_codes.h
E 8
lexi.o: /usr/include/ctype.h
D 8
parse.o: parse.c ././indent_globs.h /usr/include/stdio.h ././indent_codes.h
pr_comment.o: pr_comment.c ./indent_globs.h /usr/include/stdio.h
args.o: args.c ./indent_globs.h /usr/include/stdio.h /usr/include/sys/types.h
args.o: /usr/include/ctype.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 8
I 8
parse.o: parse.c
parse.o:./indent_globs.h
parse.o: /usr/include/stdio.h
parse.o:./indent_codes.h
pr_comment.o: pr_comment.c
pr_comment.o:indent_globs.h
pr_comment.o: /usr/include/stdio.h
args.o: args.c
args.o:indent_globs.h
args.o: /usr/include/stdio.h /usr/include/sys/types.h /usr/include/ctype.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 8
E 6
E 5
E 4
E 2
E 1
