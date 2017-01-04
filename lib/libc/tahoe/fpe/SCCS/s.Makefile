h43624
s 00010/00005/00071
d D 5.8 88/07/09 11:11:24 bostic 8 7
c install approved copyright notice
e
s 00001/00000/00075
d D 5.7 88/05/20 15:05:18 bostic 7 6
c set DEFS to compile in SCCS ids.
e
s 00022/00016/00053
d D 5.6 88/05/20 13:51:01 bostic 6 5
c restructuring libc
e
s 00013/00021/00056
d D 5.5 87/06/06 15:20:39 bostic 5 4
c new template
e
s 00023/00023/00054
d D 5.4 86/08/01 09:06:12 sam 4 3
c make depend
e
s 00004/00003/00073
d D 5.3 86/08/01 09:04:36 sam 3 2
c mv DEFS.h ..
e
s 00002/00011/00074
d D 5.2 86/07/02 16:34:47 sam 2 1
c add DEFS
e
s 00085/00000/00000
d D 5.1 86/07/02 16:25:59 sam 1 0
c date and time created 86/07/02 16:25:59 by sam
e
u
U
t
T
I 1
D 5
#	%M%	%I%	%E%
E 5
#
I 5
D 6
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 6
I 6
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 6
#
D 6
#	%W%	(Berkeley)	%G%
E 6
I 6
# Redistribution and use in source and binary forms are permitted
D 8
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 6
#
E 5
D 6
DESTDIR=
E 6
I 6
#	%W% (Berkeley) %G%
#
I 7
DEFS=	-DLIBC_SCCS
E 7
E 6
I 3
FLAGS=	-I.. ${DEFS}
I 5
CFLAGS=	-O ${FLAGS}
E 5
E 3
D 2
CFLAGS=	-O
E 2
SRCS=	addd.s addf.s cmpd.s cmpf.s cvtdl.s cvtfl.s cvtld.s cvtlf.s cvtud.s \
	cvtuf.s divd.s divf.s fnorm.s fp_exp.s modf.s muld.s mulf.s negd.s \
	negf.s sfnorm.s sfp_exp.s subd.s subf.s
OBJS=	addd.o addf.o cmpd.o cmpf.o cvtdl.o cvtfl.o cvtld.o cvtlf.o cvtud.o \
	cvtuf.o divd.o divf.o fnorm.o fp_exp.o modf.o muld.o mulf.o negd.o \
	negf.o sfnorm.o sfp_exp.o subd.o subf.o
TAGSFILE=tags

.s.o:
D 2
	/lib/cpp -E -DPROF $*.s | ${AS} -o $*.o
E 2
I 2
D 3
	/lib/cpp -E ${DEFS} -DPROF $*.s | ${AS} -o $*.o
E 3
I 3
D 6
	/lib/cpp -E ${FLAGS} -DPROF $*.s | ${AS} -o $*.o
E 3
E 2
	ld -X -r $*.o
	mv a.out profiled/$*.o
E 6
I 6
	@/lib/cpp -E ${FLAGS} -DPROF $*.s | ${AS} -o $*.o
	@ld -X -o profiled/$*.o -r $*.o
E 6
D 2
	/lib/cpp -E $*.s | ${AS} -o $*.o
	ld -x -r $*.o
	mv a.out $*.o

.c.o:
	${CC} -pg -DPROF ${CFLAGS} -c $*.c
	ld -X -r $*.o
	mv a.out profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
E 2
I 2
D 3
	/lib/cpp -E ${DEFS} $*.s | ${AS} -o $*.o
E 3
I 3
	/lib/cpp -E ${FLAGS} $*.s | ${AS} -o $*.o
E 3
E 2
D 6
	ld -x -r $*.o
	mv a.out $*.o
E 6
I 6
	@ld -x -r $*.o
	@mv a.out $*.o
E 6

D 6
fpelib fpelib_p: ${OBJS}
	@echo "building profiled fpelib"
	@cd profiled; ar cru ../fpelib_p ${OBJS}
	@echo "building normal fpelib"
	@ar cru fpelib ${OBJS}
E 6
I 6
all: ${OBJS}
E 6

I 6
link: ${OBJS}
	(cd ../../library; rm -f ${OBJS})
	(cd ../../profiled; rm -f ${OBJS})
	ln ${OBJS} ../../library
	(cd profiled; ln ${OBJS} ../../../profiled)

E 6
tags:
	echo "no tags here"

clean:
D 5
	rm -f ${OBJS} profiled/*.o errs a.out core fpelib fpelib_p Makefile.bak
E 5
I 5
D 6
	rm -f ${OBJS} profiled/*.o errs a.out core fpelib fpelib_p
E 6
I 6
	rm -f *.o profiled/* a.out core ${TAGSFILE}
E 6
E 5

depend:
D 5
	for i in ${SRCS}; do \
D 3
	    cc -M ${CFLAGS} $$i | awk ' { if ($$1 != prev) \
E 3
I 3
	    cc -M ${FLAGS} $$i | awk ' { if ($$1 != prev) \
E 3
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
E 5
I 5
	mkdep ${CFLAGS} ${SRCS}
E 5

D 5
# DO NOT DELETE THIS LINE -- make depend uses it
E 5
I 5
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 5

D 4
addd.o: addd.s /usr/include/tahoemath/fp.h ./DEFS.h
addf.o: addf.s /usr/include/tahoemath//fp.h ./DEFS.h
cmpd.o: cmpd.s ./DEFS.h
cmpf.o: cmpf.s ./DEFS.h
cvtdl.o: cvtdl.s /usr/include/tahoemath/fp.h ./DEFS.h
cvtfl.o: cvtfl.s /usr/include/tahoemath/fp.h ./DEFS.h
cvtld.o: cvtld.s /usr/include/tahoemath/fp.h ./DEFS.h
cvtlf.o: cvtlf.s /usr/include/tahoemath/fp.h ./DEFS.h
cvtud.o: cvtud.s /usr/include/tahoemath/fp.h ./DEFS.h
cvtuf.o: cvtuf.s /usr/include/tahoemath/fp.h ./DEFS.h
divd.o: divd.s /usr/include/tahoemath/fp.h ./DEFS.h
divf.o: divf.s /usr/include/tahoemath/fp.h ./DEFS.h
fnorm.o: fnorm.s /usr/include/tahoemath/fp.h ./DEFS.h
fp_exp.o: fp_exp.s /usr/include/tahoemath/fp.h ./DEFS.h
modf.o: modf.s /usr/include/tahoemath/fp.h ./DEFS.h
muld.o: muld.s /usr/include/tahoemath/fp.h ./DEFS.h
mulf.o: mulf.s /usr/include/tahoemath/fp.h ./DEFS.h
negd.o: negd.s /usr/include/tahoemath/fp.h ./DEFS.h
negf.o: negf.s /usr/include/tahoemath/fp.h ./DEFS.h
sfnorm.o: sfnorm.s /usr/include/tahoemath/fp.h ./DEFS.h
sfp_exp.o: sfp_exp.s /usr/include/tahoemath/fp.h ./DEFS.h
subd.o: subd.s /usr/include/tahoemath/fp.h ./DEFS.h
subf.o: subf.s /usr/include/tahoemath/fp.h ./DEFS.h
E 4
I 4
addd.o: addd.s /usr/include/tahoemath/fp.h ../DEFS.h
addf.o: addf.s /usr/include/tahoemath//fp.h ../DEFS.h
cmpd.o: cmpd.s ../DEFS.h
cmpf.o: cmpf.s ../DEFS.h
cvtdl.o: cvtdl.s /usr/include/tahoemath/fp.h ../DEFS.h
cvtfl.o: cvtfl.s /usr/include/tahoemath/fp.h ../DEFS.h
cvtld.o: cvtld.s /usr/include/tahoemath/fp.h ../DEFS.h
cvtlf.o: cvtlf.s /usr/include/tahoemath/fp.h ../DEFS.h
cvtud.o: cvtud.s /usr/include/tahoemath/fp.h ../DEFS.h
cvtuf.o: cvtuf.s /usr/include/tahoemath/fp.h ../DEFS.h
divd.o: divd.s /usr/include/tahoemath/fp.h ../DEFS.h
divf.o: divf.s /usr/include/tahoemath/fp.h ../DEFS.h
fnorm.o: fnorm.s /usr/include/tahoemath/fp.h ../DEFS.h
fp_exp.o: fp_exp.s /usr/include/tahoemath/fp.h ../DEFS.h
modf.o: modf.s /usr/include/tahoemath/fp.h ../DEFS.h
muld.o: muld.s /usr/include/tahoemath/fp.h ../DEFS.h
mulf.o: mulf.s /usr/include/tahoemath/fp.h ../DEFS.h
negd.o: negd.s /usr/include/tahoemath/fp.h ../DEFS.h
negf.o: negf.s /usr/include/tahoemath/fp.h ../DEFS.h
sfnorm.o: sfnorm.s /usr/include/tahoemath/fp.h ../DEFS.h
sfp_exp.o: sfp_exp.s /usr/include/tahoemath/fp.h ../DEFS.h
subd.o: subd.s /usr/include/tahoemath/fp.h ../DEFS.h
subf.o: subf.s /usr/include/tahoemath/fp.h ../DEFS.h
E 4
D 5
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 5
I 5

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1
