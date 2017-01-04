h15665
s 00001/00000/00077
d D 5.8 88/05/20 15:02:02 bostic 11 10
c set DEFS to compile in SCCS ids.
e
s 00025/00016/00052
d D 5.7 88/05/20 13:46:04 bostic 10 9
c restructuring libc
e
s 00001/00001/00067
d D 5.6 87/08/31 15:31:25 bostic 9 8
c spelling check
e
s 00023/00017/00045
d D 5.5 87/06/06 14:58:42 bostic 8 7
c new template
e
s 00022/00001/00040
d D 5.4 85/09/05 11:51:35 bloom 7 5
c fix make clean and add make depend
e
s 00022/00001/00040
d R 5.4 85/09/05 09:49:41 bloom 6 5
c fix make clean and add make depend
e
s 00001/00001/00040
d D 5.3 85/06/18 22:46:08 mckusick 5 4
c add DEFS
e
s 00012/00001/00029
d D 5.2 85/05/30 22:34:36 sam 4 3
c add tags
e
s 00006/00001/00024
d D 5.1 85/05/30 09:50:53 dist 3 2
c Add copyright
e
s 00001/00001/00024
d D 4.2 83/07/05 19:51:34 sam 2 1
c reset goes back to machine dependent
e
s 00025/00000/00000
d D 4.1 83/07/04 11:56:05 sam 1 0
c date and time created 83/07/04 11:56:05 by sam
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
D 10
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 10
I 10
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 10
#
I 10
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
E 10
#	%W% (Berkeley) %G%
E 3
#
I 11
DEFS=	-DLIBC_SCCS
E 11
D 5
CFLAGS=	-O
E 5
I 5
CFLAGS=	-O ${DEFS}
E 5
I 4
STDSRCS=ftime.c gtty.c nice.c pause.c rand.c stty.c tell.c \
	times.c utime.c vlimit.c vtimes.c
E 4
STD=	ftime.o gtty.o nice.o pause.o rand.o stty.o tell.o \
	times.o utime.o vlimit.o vtimes.o
# these should just be pitched, but in the interest of compatibility...
I 4
TRASHSRC=getpw.c
E 4
D 2
TRASH=	getpw.o reset.o
E 2
I 2
TRASH=	getpw.o 
I 4
SRCS=	${STDSRCS} ${TRASHSRCS}
E 4
E 2
OBJS=	${STD} ${TRASH}
I 4
TAGSFILE=tags
E 4

.c.o:
D 10
	${CC} -p ${CFLAGS} -c $*.c
	-ld -X -r $*.o
	mv a.out profiled/$*.o
E 10
I 10
	@${CC} -p ${CFLAGS} -c $*.c
	@-ld -X -o profiled/$*.o -r $*.o
E 10
	${CC} ${CFLAGS} -c $*.c
D 10
	-ld -x -r $*.o
	mv a.out $*.o
E 10
I 10
	@-ld -x -r $*.o
	@mv a.out $*.o
E 10

D 10
compat-4.1lib compat-4.1lib_p: ${OBJS}
	@echo "building profiled compat-4.1lib"
	@cd profiled; ar cru ../compat-4.1lib_p ${OBJS}
D 9
	@echo "buiding normal compat-4.1lib"
E 9
I 9
	@echo "building normal compat-4.1lib"
E 9
	@ar cru compat-4.1lib ${OBJS}
E 10
I 10
all: ${OBJS}
E 10

I 10
link: ${OBJS}
	(cd ../library; rm -f ${OBJS})
	(cd ../profiled; rm -f ${OBJS})
	ln ${OBJS} ../library
	(cd profiled; ln ${OBJS} ../../profiled)

E 10
I 4
tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

E 4
clean:
D 4
	rm -f compat-4.1lib compat-4.1lib_p ${OBJS} profiled/*.o
E 4
I 4
D 7
	rm -f compat-4.1lib compat-4.1lib_p ${OBJS} profiled/*.o tags
E 7
I 7
D 8
	rm -f compat-4.1lib compat-4.1lib_p *.o profiled/*.o tags Makefile.bak
E 8
I 8
D 10
	rm -f compat-4.1lib compat-4.1lib_p *.o profiled/*.o tags
E 10
I 10
	rm -f *.o profiled/* a.out core ${TAGSFILE}
E 10
E 8

depend:
D 8
	for i in ${SRCS}; do \
	    cc -M ${CFLAGS} $$i | awk ' { if ($$1 != prev) \
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
E 8
I 8
	mkdep ${CFLAGS} ${SRCS}
E 8

D 8
# DO NOT DELETE THIS LINE -- make depend uses it
E 8
I 8
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 8

I 8
ftime.o: ftime.c /usr/include/sys/types.h /usr/include/sys/time.h
ftime.o: /usr/include/time.h
gtty.o: gtty.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 10
gtty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 10
I 10
gtty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
gtty.o: /usr/include/sys/ttydev.h
E 10
nice.o: nice.c /usr/include/sys/time.h /usr/include/time.h
nice.o: /usr/include/sys/resource.h
pause.o: pause.c
rand.o: rand.c
stty.o: stty.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 10
stty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 10
I 10
stty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
stty.o: /usr/include/sys/ttydev.h
E 10
tell.o: tell.c
times.o: times.c /usr/include/sys/time.h /usr/include/time.h
times.o: /usr/include/sys/resource.h
utime.o: utime.c /usr/include/sys/time.h /usr/include/time.h
vlimit.o: vlimit.c /usr/include/sys/time.h /usr/include/time.h
vlimit.o: /usr/include/sys/resource.h /usr/include/errno.h
vtimes.o: vtimes.c /usr/include/sys/time.h /usr/include/time.h
vtimes.o: /usr/include/sys/resource.h
E 8

I 8
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 8
E 7
E 4
E 1
