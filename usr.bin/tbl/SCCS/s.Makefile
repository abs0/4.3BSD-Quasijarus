h38757
s 00057/00014/00059
d D 4.3 87/06/18 23:35:28 bostic 3 2
c new template
e
s 00002/00000/00071
d D 4.2 87/05/31 21:33:04 bostic 2 1
c added depend label
e
s 00071/00000/00000
d D 4.1 83/02/12 19:06:11 shannon 1 0
c date and time created 83/02/12 19:06:11 by shannon
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
I 3
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	t0.c t1.c t2.c t3.c t4.c t5.c t6.c t7.c t8.c t9.c tb.c tc.c te.c \
	tf.c tg.c ti.c tm.c ts.c tt.c tu.c tv.c
OBJS=	t0.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o tb.o tc.o te.o \
	tf.o tg.o ti.o tm.o ts.o tt.o tu.o tv.o
E 3

D 3
CFLAGS=-O
o = t0.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o\
    tb.o tc.o te.o tf.o tg.o ti.o tm.o ts.o tt.o tu.o tv.o
E 3
I 3
all: tbl
E 3

D 3
tbl :	$o
	$(CC) $o -o tbl
$o :	t..c
E 3
I 3
tbl: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 3

D 3
install: 
	install -s tbl $(DESTDIR)/usr/bin
E 3
I 3
clean: FRC
	rm -f ${OBJS} core tbl
E 3

D 3
clean :
	rm -f *.o
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

I 3
install: FRC
	install -s -o bin -g bin -m 755 tbl ${DESTDIR}/usr/bin/tbl

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

E 3
test:
	sh compr sample01
	sh compr sample02
	sh compr sample03
	sh compr sample04
	sh compr sample05
	sh compr sample06
	sh compr sample07
	sh compr sample08
	sh compeq sample09
	sh compeq sample10
	sh compeq sample11
	sh compr sample12
	sh compr sample13
	sh compr sample14
	sh compr sample15
	sh compr sample16
	sh compr sample17
	sh compr sample18
	sh compr sample19
	sh compr sample20
	sh compr sample21
	sh compr sample22
	sh compr sample23
	sh compms sample24
	sh compr sample25
	sh compr sample26
	sh compr sample27
	sh compr sample28
	sh compr sample29
	sh compr sample30
	sh compr sample31
	sh compr sample32
	sh compr sample33
	sh compms sample34
	sh compeq sample35
	sh compeq sample36
	sh compnr sample37
	sh compr sample38
	sh compr sample39
	sh compr sample40
	sh compr sample41
	sh compr sample42
	sh compr sample43
	sh compr sample44
	sh compms sample45
	sh compms sample46
	sh compr sample47
	sh compnr sample48
	sh compeq /usr/doc/mel/tables
I 3

E 3
ichk: /usr/bin/tbl
	/usr/bin/tbl sample1 >junk1
	cmp -s junk1 out1
D 3
comp: tbl
	cmp -s tbl /usr/bin/tbl
E 3
I 3
FRC:
E 3
I 2

D 3
depend:
E 3
I 3
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

t0.o: t0.c t..c /usr/include/stdio.h /usr/include/ctype.h
t1.o: t1.c t..c /usr/include/stdio.h /usr/include/ctype.h /usr/include/signal.h
t2.o: t2.c t..c /usr/include/stdio.h /usr/include/ctype.h
t3.o: t3.c t..c /usr/include/stdio.h /usr/include/ctype.h
t4.o: t4.c t..c /usr/include/stdio.h /usr/include/ctype.h
t5.o: t5.c t..c /usr/include/stdio.h /usr/include/ctype.h
t6.o: t6.c t..c /usr/include/stdio.h /usr/include/ctype.h
t7.o: t7.c t..c /usr/include/stdio.h /usr/include/ctype.h
t8.o: t8.c t..c /usr/include/stdio.h /usr/include/ctype.h
t9.o: t9.c t..c /usr/include/stdio.h /usr/include/ctype.h
tb.o: tb.c t..c /usr/include/stdio.h /usr/include/ctype.h
tc.o: tc.c t..c /usr/include/stdio.h /usr/include/ctype.h
te.o: te.c t..c /usr/include/stdio.h /usr/include/ctype.h
tf.o: tf.c t..c /usr/include/stdio.h /usr/include/ctype.h
tg.o: tg.c t..c /usr/include/stdio.h /usr/include/ctype.h
ti.o: ti.c t..c /usr/include/stdio.h /usr/include/ctype.h
tm.o: tm.c t..c /usr/include/stdio.h /usr/include/ctype.h
ts.o: ts.c
tt.o: tt.c t..c /usr/include/stdio.h /usr/include/ctype.h
tu.o: tu.c t..c /usr/include/stdio.h /usr/include/ctype.h
tv.o: tv.c t..c /usr/include/stdio.h /usr/include/ctype.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1
