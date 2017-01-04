h14451
s 00010/00005/00052
d D 5.8 88/06/27 16:43:48 bostic 9 8
c install approved copyright notice
e
s 00001/00000/00056
d D 5.7 88/05/20 14:55:22 bostic 8 7
c set DEFS to compile in SCCS ids.
e
s 00023/00017/00033
d D 5.6 88/05/20 13:41:19 bostic 7 6
c restructuring libc
e
s 00008/00022/00042
d D 5.5 87/06/06 14:35:58 bostic 6 5
c new template
e
s 00030/00001/00034
d D 5.4 85/09/05 11:45:35 bloom 5 3
c fix make clean and add make depend
e
s 00030/00001/00034
d R 5.4 85/09/05 10:23:36 bloom 4 3
c fix make clean and add make depend
e
s 00016/00009/00019
d D 5.3 85/09/04 19:06:07 bloom 3 2
c fix for proper lookup compilation
e
s 00009/00010/00019
d D 5.2 85/08/05 15:05:33 kjd 2 1
c Add netlib
e
s 00029/00000/00000
d D 5.1 85/07/13 21:36:09 mckusick 1 0
c date and time created 85/07/13 21:36:09 by mckusick
e
u
U
t
T
I 2
D 7

E 7
E 2
I 1
#
D 7
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 7
I 7
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 7
#
I 7
# Redistribution and use in source and binary forms are permitted
D 9
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
#
E 7
#	%W% (Berkeley) %G%
#
I 8
DEFS=	-DLIBC_SCCS
E 8
D 7

E 7
I 7
CFLAGS=	-O ${DEFS}
E 7
D 2
OBJS=	gethostbyname.o gethostbyaddr.o 
E 2
I 2
D 3
OBJS=	gethostnamadr.o 
E 3
I 3
OBJS=	gethostnamadr.o gethostent.o
SRCS=	gethostnamadr.c gethostent.c
E 3
E 2
D 7
CFLAGS=	-O ${DEFS}
E 7
I 7
TAGSFILE=tags
E 7

D 2
gethostbyname.o: 
E 2
I 2
D 3
gethostnamadr.o: 
E 3
I 3
.c.o: 
E 3
E 2
D 7
	${CC} -p -c ${CFLAGS} $*.c
	-ld -X -r $*.o
D 3
	mv a.out ../profiled/$*.o
E 3
I 3
	mv a.out profiled/$*.o
E 7
I 7
	@${CC} -p -c ${CFLAGS} $*.c
	@-ld -X -o profiled/$*.o -r $*.o
E 7
E 3
	${CC} ${CFLAGS} -c $*.c
D 7
	-ld -x -r $*.o
D 3
	mv a.out ../$*.o
E 3
I 3
	mv a.out $*.o
E 7
I 7
	@-ld -x -r $*.o
	@mv a.out $*.o
E 7
E 3

D 2
gethostbyaddr.o:
	${CC} -p -c ${CFLAGS} $*.c
	-ld -X -r $*.o
	mv a.out ../profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
	-ld -x -r $*.o
	mv a.out ../$*.o

E 2
I 2
D 3
netlib netlib_p: ${OBJS} 
	@echo "building profiled netlib"
	@cd ../profiled; ar ru ../netlib_p ${TARGETOBJS}
E 3
I 3
D 7
hostlib hostlib_p: ${OBJS} 
	@echo "building profiled hostlib"
	@cd profiled; ar cru ../hostlib_p ${OBJS}
E 3
	@echo "building normal netlib"
D 3
	@ar ru ../netlib ${TARGETOBJS}
E 3
I 3
	@ar cru hostlib ${OBJS}
E 7
I 7
all: ${OBJS}
E 7
E 3
D 6
	
E 6
I 6

I 7
link: ${OBJS}
	(cd ../../library; rm -f ${OBJS})
	(cd ../../profiled; rm -f ${OBJS})
	ln ${OBJS} ../../library
	(cd profiled; ln ${OBJS} ../../../profiled)

E 7
E 6
I 3
tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

E 3
E 2
clean:
D 3
	rm -f ${OBJS} errs a.out core 
E 3
I 3
D 5
	rm -f ${OBJS} errs a.out core hostlib hostlib_p profiled/*.o tags
E 5
I 5
D 6
	rm -f *.o errs a.out core hostlib hostlib_p profiled/*.o \
		tags Makefile.bak
E 6
I 6
D 7
	rm -f *.o errs a.out core hostlib hostlib_p profiled/*.o tags
E 7
I 7
	rm -f *.o profiled/* a.out core ${TAGSFILE}
E 7
E 6

depend:
D 6
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
E 6
I 6
	mkdep ${CFLAGS} ${SRCS}
E 6

D 6
# DO NOT DELETE THIS LINE -- make depend uses it
E 6
I 6
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 6

gethostnamadr.o: gethostnamadr.c /usr/include/stdio.h /usr/include/netdb.h
gethostnamadr.o: /usr/include/sys/file.h /usr/include/ndbm.h
I 6
gethostnamadr.o: /usr/include/ctype.h
E 6
gethostent.o: gethostent.c /usr/include/stdio.h /usr/include/sys/types.h
gethostent.o: /usr/include/sys/socket.h /usr/include/netdb.h
gethostent.o: /usr/include/ctype.h /usr/include/ndbm.h
D 6
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 6
I 6

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 6
E 5
E 3
E 1
