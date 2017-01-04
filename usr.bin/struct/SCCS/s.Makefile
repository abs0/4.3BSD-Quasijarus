h49079
s 00086/00047/00013
d D 4.5 87/06/18 23:34:47 bostic 5 4
c new template
e
s 00002/00000/00058
d D 4.4 87/05/31 21:32:47 bostic 4 3
c added depend label
e
s 00001/00006/00057
d D 4.3 83/08/13 11:39:18 sam 3 2
c remove sccs get's so distributed source will recompile
e
s 00013/00002/00050
d D 4.2 83/02/11 16:31:33 rrh 2 1
c use sccs
e
s 00052/00000/00000
d D 4.1 83/02/11 15:45:16 rrh 1 0
c date and time created 83/02/11 15:45:16 by rrh
e
u
U
t
T
I 3
D 5
#	%M%	%I%	%E%
E 5
E 3
I 1
#
D 3
#	%W%	(Berkeley)	%E%
#
E 3
I 2
D 5
DESTDIR=
E 2
CFLAGS=-O
YFLAGS=-d
0FILES.c = 0.alloc.c 0.args.c 0.def.c 0.extr.c 0.graph.c 0.list.c 0.parts.c 0.string.c
0FILES.o = 0.alloc.o 0.args.o 0.def.o 0.extr.o 0.graph.o 0.list.o 0.parts.o 0.string.o
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
YFLAGS=	-d
LIBC=	/lib/libc.a
BSRCS=	beauty.c tree.c lextab.c bdef.c
BOBJS=	beauty.o tree.o lextab.o bdef.o
SSRCS=	0.alloc.c 0.args.c 0.def.c 0.extr.c 0.graph.c 0.list.c 0.parts.c \
	0.string.c 1.finish.c 1.form.c 1.fort.c 1.hash.c 1.init.c 1.line.c \
	1.main.c 1.node.c 1.recog.c 1.tables.c 2.dfs.c 2.dom.c 2.head.c \
	2.inarc.c 2.main.c 2.tree.c 3.branch.c 3.flow.c 3.loop.c 3.main.c \
	3.reach.c 3.then.c 4.brace.c 4.form.c 4.main.c 4.out.c main.c
SOBJS=	0.alloc.o 0.args.o 0.def.o 0.extr.o 0.graph.o 0.list.o 0.parts.o \
	0.string.o 1.finish.o 1.form.o 1.fort.o 1.hash.o 1.init.o 1.line.o \
	1.main.o 1.node.o 1.recog.o 1.tables.o 2.dfs.o 2.dom.o 2.head.o \
	2.inarc.o 2.main.o 2.tree.o 3.branch.o 3.flow.o 3.loop.o 3.main.o \
	3.reach.o 3.then.o 4.brace.o 4.form.o 4.main.o 4.out.o main.o
SRCS=	${BSRCS} ${SSRCS}
OBJS=	${BOBJS} ${SOBJS}
E 5

D 5
1FILES.c = 1.finish.c 1.form.c 1.fort.c 1.hash.c 1.init.c 1.line.c 1.main.c 1.node.c 1.recog.c 1.tables.c
1FILES.o = 1.finish.o 1.form.o 1.fort.o 1.hash.o 1.init.o 1.line.o 1.main.o 1.node.o 1.recog.o 1.tables.o
E 5
I 5
all: beautify structure
E 5

D 5
2FILES.c = 2.dfs.c 2.dom.c 2.head.c 2.inarc.c 2.main.c 2.tree.c
2FILES.o = 2.dfs.o 2.dom.o 2.head.o 2.inarc.o 2.main.o 2.tree.o
E 5
I 5
beautify: ${BOBJS} ${LIBC}
	${CC} ${CFLAGS} ${BOBJS} -o $@ -lln
E 5

D 5
3FILES.c = 3.branch.c 3.flow.c 3.loop.c 3.main.c 3.reach.c 3.then.c
3FILES.o = 3.branch.o 3.flow.o 3.loop.o 3.main.o 3.reach.o 3.then.o
E 5
I 5
structure: ${SOBJS} ${LIBC}
	${CC} ${CFLAGS} ${SOBJS} -o $@
E 5

D 5
4FILES.c = 4.brace.c 4.form.c 4.main.c 4.out.c
4FILES.o = 4.brace.o 4.form.o 4.main.o 4.out.o
E 5
I 5
clean: FRC
	rm -f ${OBJS} core beauty.c structure beautify y.tab.h lextab.c
E 5

I 2
D 5
HDRS = 1.defs.h 1.incl.h 2.def.h 3.def.h 4.def.h b.h def.h
MSRCS = bdef.c main.c tree.c Makefile beauty.y lextab.l struct
E 5
I 5
depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}
E 5

D 5
SRCS = $(0FILES.c) $(1FILES.c) $(2FILES.c) \
	$(3FILES.c) $(4FILES.c) $(HDRS) $(MSRCS)
E 5
I 5
install: FRC
	install -s -o bin -g bin -m 755 structure $(DESTDIR)/usr/lib/struct/structure
	install -s -o bin -g bin -m 755 beautify $(DESTDIR)/usr/lib/struct/beautify
	install -c -o bin -g bin -m 755 struct $(DESTDIR)/usr/bin/struct
E 5

E 2
D 5
all:	structure beautify
E 5
I 5
lint: ${SRCS} FRC
	lint ${CFLAGS} ${BSRCS}
	lint ${CFLAGS} ${SSRCS}
E 5

D 2
install: structure beautify
E 2
I 2
D 5
install: structure beautify struct
E 2
	install -s structure $(DESTDIR)/usr/lib/struct
	install -s beautify $(DESTDIR)/usr/lib/struct
	install -c struct $(DESTDIR)/usr/bin
clean:
D 2
	rm -f *.o y.tab.h beauty.c
E 2
I 2
	rm -f *.o y.tab.h beauty.c structure beautify
E 5
I 5
tags: ${SRCS} FRC
	ctags ${BSRCS}
	ctags -a ${SSRCS}
	sort -o tags tags
E 5
E 2

D 5
structure: main.o $(0FILES.o) $(1FILES.o) $(2FILES.o) $(3FILES.o) $(4FILES.o)
	cc -o structure main.o 0.*.o 1.*.o 2.*.o 3.*.o 4.*.o 
E 5
I 5
FRC:
E 5

D 5
beautify:	beauty.o tree.o lextab.o bdef.o
	cc -O beauty.o tree.o lextab.o bdef.o -o beautify -lln
E 5
I 5
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 5

D 5
lint:
	lint $(0FILES.c) $(1FILES.c) $(2FILES.c) $(3FILES.c) $(4FILES.c) main.c

main.o $(0FILES.o) $(1FILES.o) $(2FILES.o) $(3FILES.o) $(4FILES.o): def.h
E 5
I 5
beauty.o: beauty.c b.h /usr/include/stdio.h /usr/include/signal.h
tree.o: tree.c y.tab.h b.h /usr/include/stdio.h
lextab.o: lextab.c /usr/include/stdio.h y.tab.h b.h
bdef.o: bdef.c
0.alloc.o: 0.alloc.c /usr/include/stdio.h def.h
0.args.o: 0.args.c /usr/include/stdio.h def.h
0.def.o: 0.def.c /usr/include/stdio.h def.h
0.extr.o: 0.extr.c /usr/include/stdio.h def.h
0.graph.o: 0.graph.c /usr/include/stdio.h def.h
0.list.o: 0.list.c /usr/include/stdio.h def.h
0.parts.o: 0.parts.c /usr/include/stdio.h def.h
0.string.o: 0.string.c /usr/include/stdio.h def.h 1.defs.h
1.finish.o: 1.finish.c /usr/include/stdio.h def.h 1.incl.h
1.form.o: 1.form.c /usr/include/stdio.h 1.defs.h def.h
1.fort.o: 1.fort.c /usr/include/stdio.h 1.incl.h 1.defs.h def.h
1.hash.o: 1.hash.c /usr/include/stdio.h 1.incl.h 1.defs.h def.h
1.init.o: 1.init.c /usr/include/stdio.h 1.defs.h 1.incl.h def.h
1.line.o: 1.line.c /usr/include/stdio.h def.h
1.main.o: 1.main.c /usr/include/stdio.h def.h
1.node.o: 1.node.c /usr/include/stdio.h def.h 1.incl.h
1.recog.o: 1.recog.c /usr/include/stdio.h 1.incl.h def.h
1.tables.o: 1.tables.c /usr/include/stdio.h
2.dfs.o: 2.dfs.c /usr/include/stdio.h def.h 2.def.h
2.dom.o: 2.dom.c /usr/include/stdio.h def.h 2.def.h
2.head.o: 2.head.c /usr/include/stdio.h def.h 2.def.h
2.inarc.o: 2.inarc.c /usr/include/stdio.h def.h 2.def.h
2.main.o: 2.main.c /usr/include/stdio.h def.h 2.def.h
2.tree.o: 2.tree.c /usr/include/stdio.h def.h 2.def.h
3.branch.o: 3.branch.c /usr/include/stdio.h def.h 3.def.h
3.flow.o: 3.flow.c /usr/include/stdio.h def.h 3.def.h
3.loop.o: 3.loop.c /usr/include/stdio.h def.h 3.def.h
3.main.o: 3.main.c /usr/include/stdio.h def.h
3.reach.o: 3.reach.c /usr/include/stdio.h def.h
3.then.o: 3.then.c /usr/include/stdio.h def.h 3.def.h
4.brace.o: 4.brace.c /usr/include/stdio.h def.h 4.def.h 3.def.h
4.form.o: 4.form.c /usr/include/stdio.h def.h 4.def.h
4.main.o: 4.main.c /usr/include/stdio.h def.h 4.def.h
4.out.o: 4.out.c /usr/include/stdio.h def.h 4.def.h 3.def.h
main.o: main.c /usr/include/signal.h /usr/include/stdio.h 1.defs.h def.h
E 5

D 5
$(1FILES.o): 1.defs.h 1.incl.h
$(2FILES.o): 2.def.h
$(3FILES.o): 3.def.h
$(4FILES.o): 4.def.h

lextab.o tree.o: y.tab.h

y.tab.h: beauty.y

lextab.o tree.o beauty.y: b.h

y.tab.h:	beauty.c
I 4

depend:
E 5
I 5
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 4
I 2
D 3

srcs: $(SRCS)
$(SRCS):
	sccs get $@
E 3
E 2
E 1
