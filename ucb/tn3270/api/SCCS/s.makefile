h20665
s 00013/00000/00138
d D 3.2 88/03/28 13:46:59 bostic 13 12
c add Berkeley specific header
e
s 00000/00000/00138
d D 3.1 87/08/11 10:17:35 minshall 12 11
c New version numbering.
e
s 00003/00003/00135
d D 1.11 87/07/16 10:54:17 minshall 11 10
c Appropriate target for make in tools directory (PC version).
e
s 00011/00011/00127
d D 1.10 87/07/15 15:24:32 minshall 10 9
c New directory structure
e
s 00032/00032/00106
d D 1.9 87/07/03 15:48:58 minshall 9 8
c Add in PC stuff (including the need to make some trivial
c .c files.
e
s 00070/00033/00068
d D 1.8 87/06/30 23:53:03 minshall 8 7
c mkmake, etc.
e
s 00045/00012/00056
d D 1.7 87/06/19 15:04:01 minshall 7 6
c New directories, new cleanup.
e
s 00008/00001/00060
d D 1.6 87/06/16 17:17:23 minshall 6 5
c tnrecv.c
e
s 00006/00000/00055
d D 1.5 87/06/15 23:27:18 minshall 5 4
c t1, t2 are test programs.
e
s 00003/00003/00052
d D 1.4 87/06/15 10:45:59 minshall 4 3
c sourcelist target.
e
s 00015/00001/00040
d D 1.3 87/06/15 10:00:42 minshall 3 2
c Add sourcelist and action targets.
e
s 00035/00003/00006
d D 1.2 87/06/12 13:54:46 minshall 2 1
c New files, new targets.
e
s 00009/00000/00000
d D 1.1 87/06/10 15:16:37 minshall 1 0
c date and time created 87/06/10 15:16:37 by minshall
e
u
U
t
T
I 13
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
#	%W% (Berkeley) %G%
#
E 13
I 1
D 2
ALLC = apilib.c
ALLH =
E 2
I 2
D 8
CFLAGS = -g
E 8
I 8
# msdos versus unix defines
O	= .o
D 9
PC_O	= .obj
E 9
I 9
#PC_O	= .obj
E 9
E 8
I 7

I 8
X	=
D 9
PC_X	= .exe
E 9
I 9
#PC_X	= .exe
E 9

I 9
L	=
#PC_L	= -link

E 9
CC	= cc
D 9
PC_CC	= cl
E 9
I 9
#PC_CC	= cl
E 9

MV	= mv
D 9
PC_MV	= rename
E 9
I 9
#PC_MV	= rename
E 9

RM	= rm -f
D 9
PC_RM= erase
E 9
I 9
#PC_RM= erase
E 9

LINT_ARGS =
D 9
PC_LINT_ARGS = -DLINT_ARGS
E 9
I 9
#PC_LINT_ARGS = -DLINT_ARGS
E 9

DEBUG_FLAGS = -g
D 9
PC_DEBUG_FLAGS = -Zi -Od
E 9
I 9
#PC_DEBUG_FLAGS = -Zi -Od
E 9

AR	= ar
D 9
C	=
PC_AR	= lib
PC_C	= +
E 9
I 9
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 9

RANLIB	= ranlib
D 9
PC_RANLIB = echo "Done with "
E 9
I 9
#PC_RANLIB = echo "Done with "
E 9

CFLAGS = ${DEBUG_FLAGS}

E 8
E 7
PRINT = lpr -p
E 2

D 2
ALLO = apilib.o
E 2
I 2
D 6
ALLC = apilib.c api_bsd.c api_exch.c
E 6
I 6
D 7
ALLC = apilib.c api_bsd.c api_exch.c tnrecv.c
E 6
ALLH = apilib.h api_exch.h
E 7
I 7
KBD	= 3270pc.kbd
KBD	= unix.kbd
E 7
E 2

I 7
D 9
ALLC = apilib.c api_bsd.c api_exch.c asc_ebc.c astosc.c dctype.c ebc_disp.c
E 9
I 9
ALLC = apilib.c api_bsd.c api_exch.c asc_ebc.c astosc.c dctype.c \
		disp_asc.c ebc_disp.c
E 9

ALLH = apilib.h api_exch.h asc_ebc.h astosc.h disp_asc.h dctype.h ebc_disp.h

E 7
I 3
ALLPRINT = ${ALLH} ${ALLC}

D 4
ALLSOURCE = ${ALLPRINT}
E 4
I 4
ALLSOURCE = ${ALLPRINT} makefile makefile.mak
E 4

E 3
I 2
D 7
ALLO = apilib.o api_bsd.o api_exch.o
E 7
I 7
D 8
ALLO = apilib.o api_bsd.o api_exch.o astosc.o asc_ebc.o disp_asc.o \
		dctype.o ebc_disp.o
E 8
I 8
D 9
ALLO = apilib$O api_bsd$O api_exch$O astosc$O asc_ebc$O disp_asc$O \
		dctype$O ebc_disp$O
E 9
I 9
ALLO = apilib$O api_bsd$O api_exch$O astosc$O asc_ebc$O dctype$O \
		disp_asc$O ebc_disp$O
E 9
E 8
E 7

I 8
.c.obj:
	${CC} ${CFLAGS} -c $<

E 8
E 2
D 9
apilib.a: ${ALLO}
E 9
I 9
D 10
apiliblib.a: ${ALLO}
E 10
I 10
apilib.a: ${ALLO}
E 10
E 9
D 7
	@-/bin/rm $@
E 7
I 7
D 8
	@-/bin/rm -f $@
E 7
	ar cr $@ ${ALLO}
	ranlib $@
E 8
I 8
	${RM} $@
D 9
	for i in ${ALLO}; do (${AR} cr $@ $C $$i); done
E 9
I 9
	for i in ${ALLO}; do (${AR} ${AR1} $@ ${AR2} $$i${AR3}); done
E 9
	${RANLIB} $@
E 8
I 2

I 6
D 7
tnrecv:	tnrecv.o apilib.a ../ascii/disp_asc.o ../ascii/astosc.o
	${CC} ${CFLAGS} -o $@ tnrecv.o apilib.a \
				../ascii/disp_asc.o ../ascii/astosc.o
E 7
I 7
.DEFAULT:
	sccs get $<
E 7

E 6
I 3
clean:
D 7
	-/bin/rm ${ALLO} errs apilib.a
E 7
I 7
D 8
	-/bin/rm -f ${ALLO} errs apilib.a makefile.bak \
E 8
I 8
D 9
	for i in ${ALLO} errs apilib.a makefile.bak \
E 9
I 9
D 10
	for i in ${ALLO} errs apiliblib.a makefile.bak \
E 10
I 10
	for i in ${ALLO} errs apilib.a makefile.bak \
E 10
E 9
E 8
		disp_out asc_disp.out astosc.out disp_asc.out \
D 8
		test* test.o t1* t1.o t2* t2.o
E 8
I 8
		test* test$O t1* t1$O t2* t2$O; \
			do (${RM} $$i); done

sccsclean:
E 8
	-sccs clean
	-sccs get makefile
E 7

action:
	${ACTION}

E 3
D 8
test:	apilib.a test.o
	${CC} ${CFLAGS} -o $@ test.o apilib.a
E 8
I 8
D 9
test:	apilib.a test$O
	${CC} ${CFLAGS} -o $@ test$O apilib.a
E 9
I 9
D 10
test:	apiliblib.a test$O
	${CC} ${CFLAGS} -o $@ test$O apiliblib.a
E 10
I 10
test:	apilib.a test$O
	${CC} ${CFLAGS} -o $@ test$O apilib.a
E 10
E 9
E 8

I 5
D 8
t1:	apilib.a t1.o
	${CC} ${CFLAGS} -o $@ t1.o apilib.a
E 8
I 8
D 9
t1:	apilib.a t1$O
	${CC} ${CFLAGS} -o $@ t1$O apilib.a
E 9
I 9
D 10
t1:	apiliblib.a t1$O
	${CC} ${CFLAGS} -o $@ t1$O apiliblib.a
E 10
I 10
t1:	apilib.a t1$O
	${CC} ${CFLAGS} -o $@ t1$O apilib.a
E 10
E 9
E 8

D 8
t2:	apilib.a t2.o
	${CC} ${CFLAGS} -o $@ t2.o apilib.a
E 8
I 8
D 9
t2:	apilib.a t2$O
	${CC} ${CFLAGS} -o $@ t2$O apilib.a
E 9
I 9
D 10
t2:	apiliblib.a t2$O
	${CC} ${CFLAGS} -o $@ t2$O apiliblib.a
E 10
I 10
t2:	apilib.a t2$O
	${CC} ${CFLAGS} -o $@ t2$O apilib.a
E 10
E 9
E 8

E 5
print:
D 3
	${PRINT} ${ALLH} ${ALLC}
E 3
I 3
	${PRINT} ${ALLPRINT}
E 3

I 3

D 4
sourcelist:
	for i in ${ALLSOURCE}; \
E 4
I 4
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
E 4
D 7
		do (echo ${DIRPATH}/$$i); done
E 7
I 7
		do (echo ${DIRPATH}$$i); done
E 7
E 3

I 7
astosc.out:	../ctlr/function.h ../ctlr/hostctlr.h ../ctlr/$(KBD)
D 8
	(cd ../tools; make mkastosc $(MFLAGS) )
	-/bin/rm -f $@
E 8
I 8
D 11
	(cd ../tools; make mkastosc )
E 11
I 11
	(cd ../tools; make mkastosc$X )
E 11
	${RM} $@
E 8
	../tools/mkastosc < ../ctlr/$(KBD) > $@

D 8
asc_disp.out:	ebc_disp.o
	(cd ../tools; make mkastods $(MFLAGS) )
	-/bin/rm -f $@
E 8
I 8
asc_disp.out:	ebc_disp$O
D 11
	(cd ../tools; make mkastods )
E 11
I 11
	(cd ../tools; make mkastods$X )
E 11
	${RM} $@
E 8
	../tools/mkastods > $@

D 8
disp_asc.out:	ebc_disp.o
	(cd ../tools; make mkdstoas $(MFLAGS) )
	-/bin/rm -f $@
E 8
I 8
disp_asc.out:	ebc_disp$O
D 11
	(cd ../tools; make mkdstoas )
E 11
I 11
	(cd ../tools; make mkdstoas$X )
E 11
	${RM} $@
E 8
	../tools/mkdstoas > $@

D 8
disp_asc.o:	disp_asc.h asc_disp.out disp_asc.out
	-/bin/rm -f $@ TMPfunc.c
E 8
I 8
D 9
disp_asc$O:	disp_asc.h asc_disp.out disp_asc.out
	${RM} $@ TMPfunc.c
E 8
	/bin/echo \#include \"disp_asc.h\" > TMPfunc.c
	/bin/echo \#include \"asc_disp.out\" >> TMPfunc.c
	/bin/echo \#include \"disp_asc.out\" >> TMPfunc.c
	$(CC) $(CFLAGS) -c TMPfunc.c
D 8
	-/bin/rm -f TMPfunc.c
	-/bin/mv TMPfunc.o $@
E 8
I 8
	${RM} TMPfunc.c
	${MV} TMPfunc$O $@
E 8

E 9
E 7
depend:
	grep '^#include' ${ALLC} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
D 8
	    -e 's/\.c/.o/' | \
E 8
I 8
	    -e 's/\.c/$$O/' | \
E 8
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
I 8
	-rm -f makefile.bak
E 8
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

D 8
apilib.o: ../api/api.h apilib.h
api_bsd.o: ../api/api.h api_exch.h
api_exch.o: api_exch.h
I 6
D 7
tnrecv.o: apilib.h tncomp.h ../api/api.h ../ctlr/function.h ../ctlr/hostctlr.h
tnrecv.o: ../ctlr/oia.h ../ctlr/screen.h ../ascii/disp_asc.h ../ascii/astosc.h
tnrecv.o: ../general/general.h
E 7
I 7
asc_ebc.o: asc_ebc.h
astosc.o: ../general/general.h ../ctlr/function.h astosc.h astosc.out
dctype.o: dctype.h
E 8
I 8
D 10
apilib$O: ../api/api.h apilib.h
api_bsd$O: ../api/api.h api_exch.h
api_exch$O: api_exch.h
E 10
I 10
apilib$O: ../ctlr/api.h apilib.h
api_bsd$O: ../ctlr/api.h api_exch.h
api_exch$O: ../general/general.h api_exch.h
E 10
asc_ebc$O: asc_ebc.h
astosc$O: ../general/general.h ../ctlr/function.h astosc.h astosc.out
dctype$O: dctype.h
I 9
disp_asc$O: disp_asc.h asc_disp.out disp_asc.out
E 9
E 8
E 7
E 6
E 2
E 1
