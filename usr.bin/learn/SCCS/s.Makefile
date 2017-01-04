h10835
s 00002/00002/00081
d D 4.9 88/06/10 14:32:00 bostic 10 9
c don't destructively install getline.c and getnum.c
e
s 00010/00003/00073
d D 4.8 88/06/08 15:20:15 jak 9 8
c getline.c and getnum.c from C lessons moved into src directory
e
s 00001/00000/00075
d D 4.7 87/09/11 14:05:31 jak 8 7
c added chmod to Init files since many installed systems break w/o it.
e
s 00061/00044/00014
d D 4.6 87/06/18 17:59:49 bostic 7 6
c new template
e
s 00002/00000/00056
d D 4.5 87/05/31 21:29:55 bostic 6 5
c added depend label
e
s 00003/00006/00053
d D 4.4 86/05/15 17:57:51 bloom 5 4
c updates from John Kunze
e
s 00001/00001/00058
d D 4.3 83/06/19 11:22:02 root 4 3
c fix instlal
e
s 00023/00026/00036
d D 4.2 83/04/26 01:45:41 mckusick 3 1
c 
e
s 00023/00026/00036
d R 4.2 83/04/25 23:58:28 mckusick 2 1
c 
e
s 00062/00000/00000
d D 4.1 83/02/24 12:56:31 mckusick 1 0
c date and time created 83/02/24 12:56:31 by mckusick
e
u
U
t
T
I 1
D 7
#	%W%	(Berkeley)	%E%
E 7
#
D 7
DESTDIR=
E 7
I 7
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
# Flag BSD4_2 means 4.2 or later.
CFLAGS=	-O -DBSD4_2
LIBC=	/lib/libc.a
LLIB=	${DESTDIR}/usr/lib/learn/bin
SRCS=	copy.c dounit.c getlesson.c learn.c list.c mem.c makpipe.c maktee.c \
	mysys.c selsub.c selunit.c start.c whatnow.c wrapup.c
OBJS=	copy.o dounit.o getlesson.o learn.o list.o mem.o makpipe.o maktee.o \
	mysys.o selsub.o selunit.o start.o whatnow.o wrapup.o
E 7

I 5
D 7
# The vi lessons come with the user-contributed software.
E 5
LESSONS = files editor morefiles macros eqn C
E 7
I 7
D 9
all: learn lrntee lcount
E 9
I 9
all: learn lrntee lcount getline.o getnum.o
E 9
E 7

D 7
FILES = lrnref.h \
D 3
	copy.c dounit.c learn.c list.c \
E 3
I 3
	copy.c dounit.c getlesson.c learn.c list.c \
E 3
	makpipe.c maktee.c mem.c mysys.c selsub.c selunit.c \
	start.c whatnow.c wrapup.c \
D 3
	lcount.c tee.c \
E 3
I 3
	lcount.c lrntee.c \
E 3
	makefile
E 7
I 7
learn: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 7

D 3
OBJECTS = copy.o dounit.o learn.o list.o mem.o \
E 3
I 3
D 7
OBJECTS = copy.o dounit.o getlesson.o learn.o list.o mem.o \
E 3
	makpipe.o maktee.o mysys.o selsub.o selunit.o \
	start.o whatnow.o wrapup.o
E 7
I 7
lcount: lcount.c ${LIBC}
	${CC} ${CFLAGS} -o $@ lcount.c
E 7

D 5
CFLAGS = -O
E 5
I 5
D 7
# Flag BSD4_2 means 4.2 or later.
CFLAGS = -O -DBSD4_2
E 5
LIBRARY =
D 3
LLIB	= $(DESTDIR)/usr/lib/learn
E 3
I 3
LLIB	= $(DESTDIR)/usr/lib/learn/bin
E 7
I 7
lrntee: lrntee.c ${LIBC}
	${CC} ${CFLAGS} -o $@ lrntee.c
E 7
E 3

D 3
all:	learn tee lcount
	
E 3
I 3
D 7
all:	learn lrntee lcount
E 7
I 7
clean: FRC
D 9
	rm -f ${OBJS} core learn lrntee lcount
E 9
I 9
	rm -f ${OBJS} core learn lrntee lcount getline.o getnum.o
E 9
E 7

E 3
D 7
install:	all
D 4
	install -s learn $(DESTDIR)/usr/bin
E 4
I 4
	install -c -s learn $(DESTDIR)/usr/bin
E 4
D 3
	install -s tee $(LLIB)
E 3
I 3
	install -s learn $(LLIB)
	install -s lrntee $(LLIB)
E 3
	install -s lcount $(LLIB)
E 7
I 7
depend: FRC
D 9
	mkdep ${CFLAGS} ${SRCS} lcount.c lrntee.c
E 9
I 9
	mkdep ${CFLAGS} ${SRCS} lcount.c lrntee.c getline.c getnum.c
E 9
E 7
D 3
	@echo "Then do 'make play; make log' to make playpen and log directories"
E 3
D 5

I 3
ccinstall:	all
	cp learn lrntee lcount $(LLIB)
	chmod 755 $(LLIB)/*
	strip $(LLIB)/*
E 5

E 3
D 7
clean:
D 3
	rm -f *.o learn tee lcount errs
E 3
I 3
	rm -f *.o learn lrntee lcount errs
E 7
I 7
install: FRC
	install -c -s -o bin -g bin -m 755 learn ${DESTDIR}/usr/bin/learn
	install -s -o bin -g bin -m 755 learn ${LLIB}/learn
	install -s -o bin -g bin -m 755 lrntee ${LLIB}/lrntee
	install -s -o bin -g bin -m 755 lcount ${LLIB}/lcount
I 9
	install -o bin -g bin -m 644 getline.o ${LLIB}/getline.o
	install -o bin -g bin -m 644 getnum.o ${LLIB}/getnum.o
	cd ${LLIB}; rm -f ../C/get*.o; ln getline.o getnum.o ../C
D 10
	install -o bin -g bin -m 644 getline.c ${LLIB}/../C/getline.c
	install -o bin -g bin -m 644 getnum.c ${LLIB}/../C/getnum.c
E 10
I 10
	install -c -o bin -g bin -m 644 getline.c ${LLIB}/../C/getline.c
	install -c -o bin -g bin -m 644 getnum.c ${LLIB}/../C/getnum.c
E 10
E 9
I 8
	chmod 755 ${LLIB}/../*/Init
E 8
E 7
E 3

D 7
cmp:	all
D 3
	cmp learn $(DESTDIR)/bin/learn
	cmp tee $(LLIB)/tee
E 3
I 3
	cmp learn $(DESTDIR)/usr/bin/learn
	cmp learn $(LLIB)/learn
	cmp lrntee $(LLIB)/lrntee
E 3
	cmp lcount $(LLIB)/lcount
D 3
	rm learn tee lcount *.o
E 3
I 3
	rm learn lrntee lcount *.o
E 7
I 7
lint: FRC
	lint ${CFLAGS} ${SRCS}
	lint ${CFLAGS} lcount.c
	lint ${CFLAGS} lrntee.c
I 9
	lint ${CFLAGS} getline.c getnum.c
E 9
E 7
E 3

D 7
learn: $(OBJECTS)
	cc -o learn $(CFLAGS) $(OBJECTS) $(LIBRARY)
E 7
I 7
tags: FRC
	ctags ${SRCS}
	ctags -a lcount.c
	ctags -a lrntee.c
I 9
	ctags -a getline.c getnum.c
E 9
	sort -o tags tags
E 7

D 7
$(OBJECTS): lrnref.h
E 7
I 7
FRC:
E 7

D 3
lcount tee:
E 3
I 3
D 7
lcount lrntee:
E 3
	cc $(CFLAGS) $@.c -o $@ $(LIBRARY)
E 7
I 7
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 7

D 3
lessons:	$(LESSONS)
E 3
I 3
D 7
log:
	-rm -r $(LLIB)/../log; mkdir $(LLIB)/../log; chmod +w $(LLIB)/../log
E 7
I 7
copy.o: copy.c /usr/include/stdio.h /usr/include/signal.h lrnref.h
dounit.o: dounit.c /usr/include/stdio.h lrnref.h
getlesson.o: getlesson.c /usr/include/stdio.h lrnref.h
learn.o: learn.c /usr/include/stdio.h lrnref.h /usr/include/signal.h
list.o: list.c /usr/include/stdio.h lrnref.h /usr/include/signal.h
mem.o: mem.c /usr/include/stdio.h lrnref.h
makpipe.o: makpipe.c /usr/include/stdio.h
maktee.o: maktee.c /usr/include/stdio.h /usr/include/signal.h lrnref.h
mysys.o: mysys.c /usr/include/stdio.h /usr/include/signal.h
selsub.o: selsub.c /usr/include/stdio.h /usr/include/sys/types.h
selsub.o: /usr/include/sys/stat.h lrnref.h /usr/include/sys/dir.h
selunit.o: selunit.c /usr/include/stdio.h lrnref.h
start.o: start.c /usr/include/stdio.h lrnref.h /usr/include/sys/types.h
start.o: /usr/include/sys/dir.h
whatnow.o: whatnow.c /usr/include/stdio.h lrnref.h
wrapup.o: wrapup.c /usr/include/signal.h /usr/include/stdio.h lrnref.h
lcount.o: lcount.c /usr/include/stdio.h
lrntee.o: lrntee.c
E 7
E 3

D 3
$(LESSONS):
	-rm -r $(LLIB)/$@
	mkdir $(LLIB)/$@
	(cd $(LLIB)/$@; ar x ../$@.a)

play log:
	-rm -r $(LLIB)/$@; mkdir $(LLIB)/$@; chmod +w $(LLIB)/$@

E 3
D 7
check:
D 3
	-@test -r $(LLIB)/tee || echo 'tee not present; make tee'
E 3
I 3
	-@test -r $(LLIB)/lrntee || echo 'lrntee not present; make lrntee'
E 3
	-@test -r $(LLIB)/lcount || echo 'lcount not present; make lcount'
D 3
	-@test -r $(LLIB)/play || echo 'play directory not present; make play'
	-@test -r $(LLIB)/log || echo 'log directory not present; make log'
	-@for i in $(LESSONS); do test -r $(LLIB)/$$i/L0 || echo $$i not unarchived, make $$i; done
E 3
I 3
	-@test -r $(LLIB)/../log || echo 'log directory not present; make log if you want logging'
I 6

depend:
E 7
I 7
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 6
E 3
E 1
