h41202
s 00013/00000/00103
d D 3.2 88/03/28 12:18:26 bostic 8 7
c add Berkeley specific headers
e
s 00000/00000/00103
d D 3.1 87/08/11 10:21:03 minshall 7 6
c New version numbering.
e
s 00002/00002/00101
d D 1.6 87/07/31 15:09:59 minshall 6 5
c Add "tarread.exe" to sourcelist.
e
s 00004/00004/00099
d D 1.5 87/07/15 15:27:53 minshall 5 4
c New directory structure.
e
s 00025/00018/00078
d D 1.4 87/07/03 15:50:16 minshall 4 3
c Add in PC stuff.
e
s 00045/00006/00051
d D 1.3 87/06/30 23:53:48 minshall 3 2
c mkmake, etc.
e
s 00003/00003/00054
d D 1.2 87/06/19 15:05:48 minshall 2 1
c New directories, new cleanup.
e
s 00057/00000/00000
d D 1.1 87/06/19 12:56:07 minshall 1 0
c date and time created 87/06/19 12:56:07 by minshall
e
u
U
t
T
I 8
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
E 8
I 1
D 3
CFLAGS = -g -I..
E 3
I 3
# msdos versus unix defines
O	= .o
D 4
PC_O	= .obj
E 4
I 4
#PC_O	= .obj
E 4
E 3

I 3
X	=
D 4
PC_X	= .exe
E 4
I 4
#PC_X	= .exe
E 4

I 4
L	=
#PC_L	= -link

E 4
CC	= cc
D 4
PC_CC	= cl
E 4
I 4
#PC_CC	= cl
E 4

MV	= mv
D 4
PC_MV	= rename
E 4
I 4
#PC_MV	= rename
E 4

RM	= rm -f
D 4
PC_RM= erase
E 4
I 4
#PC_RM= erase
E 4

LINT_ARGS =
D 4
PC_LINT_ARGS = -DLINT_ARGS
E 4
I 4
#PC_LINT_ARGS = -DLINT_ARGS
E 4

DEBUG_FLAGS = -g
D 4
PC_DEBUG_FLAGS = -Zi -Od
E 4
I 4
#PC_DEBUG_FLAGS = -Zi -Od
E 4

AR	= ar
D 4
C	=
PC_AR	= lib
PC_C	= +
E 4
I 4
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 4

RANLIB	= ranlib
D 4
PC_RANLIB = echo "Done with "
E 4
I 4
#PC_RANLIB = echo "Done with "
E 4

DEFINES = ${LINT_ARGS}

CFLAGS = ${DEBUG_FLAGS} -I..

E 3
PRINT = lpr -p

ALLC = tnrecv.c
ALLH = tncomp.h

ALLPRINT = ${ALLH} ${ALLC}

ALLSOURCE = ${ALLPRINT} makefile makefile.mak

D 3
ALLO = tnrecv.o
E 3
I 3
ALLO = tnrecv$O
E 3

I 3
.c.obj:
	${CC} ${CFLAGS} -c $<

E 3
D 4
.DEFAULT:
	sccs get $<
E 4
I 4
all:	tnrecv$X
E 4

D 4
all:	tnrecv
E 4
I 4
tnrecv$X:	tnrecv$O
D 5
	${CC} ${CFLAGS} -o $@ tnrecv$O $L ../apilib/apiliblib.a
E 5
I 5
	${CC} ${CFLAGS} -o $@ tnrecv$O $L ../api/apilib.a
E 5
E 4

D 3
tnrecv:	tnrecv.o
	${CC} ${CFLAGS} -o $@ tnrecv.o ../apilib/apilib.a
E 3
I 3
D 4
tnrecv:	tnrecv$O
	${CC} ${CFLAGS} -o $@ tnrecv$O ../apilib/apilib.a
E 3

E 4
clean:
D 2
	-/bin/rm ${ALLO} errs
	sccs clean
E 2
I 2
D 3
	-/bin/rm -f makefile.bak ${ALLO} errs
E 3
I 3
D 4
	for i in makefile.bak ${ALLO} errs; \
E 4
I 4
	for i in makefile.bak ${ALLO} errs tnrecv$X; \
E 4
		do (${RM} $$i); done
I 4

.DEFAULT:
	sccs get $<
E 4

sccsclean:
E 3
	-sccs clean
E 2
	-sccs get makefile

action:
	${ACTION}

print:
	${PRINT} ${ALLPRINT}

D 6
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
E 6
I 6
sourcelist:	${ALLSOURCE} tarread.exe
	@for i in ${ALLSOURCE} tarread.exe; \
E 6
D 2
		do (echo ${DIRPATH}/$$i); done
E 2
I 2
		do (echo ${DIRPATH}$$i); done
E 2

depend:
	grep '^#include' ${ALLC} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
D 3
	    -e 's/\.c/.o/' | \
E 3
I 3
	    -e 's/\.c/$$O/' | \
E 3
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
I 3
	-rm -f makefile.bak
E 3
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

D 5
#include "apilib.h" "tncomp.h" "../api/api.h" "../ctlr/function.h"
#include "../ctlr/hostctlr.h" "../ctlr/oia.h" "../ctlr/screen.h"
#include "../ascii/disp_asc.h" "../ascii/astosc.h" "../general/general.h"
E 5
I 5
#include "tncomp.h" "../api/api.h" "../ctlr/function.h" "../ctlr/hostctlr.h"
#include "../ctlr/oia.h" "../ctlr/screen.h" "../apilib/disp_asc.h"
#include "../apilib/astosc.h" "../general/general.h"
E 5
E 1
