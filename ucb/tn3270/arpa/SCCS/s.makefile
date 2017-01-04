h23579
s 00013/00000/00065
d D 3.1 88/03/28 12:57:06 bostic 6 5
c add Berkeley specific headers
e
s 00018/00011/00047
d D 1.5 87/07/03 15:49:49 minshall 5 4
c Add in PC stuff.
e
s 00032/00000/00026
d D 1.4 87/06/30 23:53:32 minshall 4 3
c mkmake, etc.
e
s 00003/00002/00023
d D 1.3 87/06/19 15:05:16 minshall 3 2
c New directories, new cleanup.
e
s 00003/00000/00022
d D 1.2 87/06/18 11:57:41 minshall 2 1
c Default rule (for sourcelist).
e
s 00022/00000/00000
d D 1.1 87/06/18 10:56:04 minshall 1 0
c date and time created 87/06/18 10:56:04 by minshall
e
u
U
t
T
I 6
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
E 6
I 4
# msdos versus unix defines
O	= .o
D 5
PC_O	= .obj
E 5
I 5
#PC_O	= .obj
E 5

X	=
D 5
PC_X	= .exe
E 5
I 5
#PC_X	= .exe
E 5

I 5
L	=
#PC_L	= -link

E 5
CC	= cc
D 5
PC_CC	= cl
E 5
I 5
#PC_CC	= cl
E 5

MV	= mv
D 5
PC_MV	= rename
E 5
I 5
#PC_MV	= rename
E 5

RM	= rm -f
D 5
PC_RM= erase
E 5
I 5
#PC_RM= erase
E 5

LINT_ARGS =
D 5
PC_LINT_ARGS = -DLINT_ARGS
E 5
I 5
#PC_LINT_ARGS = -DLINT_ARGS
E 5

DEBUG_FLAGS = -g
D 5
PC_DEBUG_FLAGS = -Zi -Od
E 5
I 5
#PC_DEBUG_FLAGS = -Zi -Od
E 5

AR	= ar
D 5
C	=
PC_AR	= lib
PC_C	= +
E 5
I 5
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 5

RANLIB	= ranlib
D 5
PC_RANLIB = echo "Done with "
E 5
I 5
#PC_RANLIB = echo "Done with "
E 5

E 4
I 1
PRINT = lpr -p

ALLC =
ALLH = telnet.h

ALLPRINT = ${ALLH} ${ALLC}

ALLSOURCE = ${ALLPRINT} makefile makefile.mak

clean:
I 4

sccsclean:
E 4
I 3
	-sccs clean
	-sccs get makefile
E 3

D 3

E 3
action:
	${ACTION}

print:
	${PRINT} ${ALLPRINT}


sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
D 3
		do (echo ${DIRPATH}/$$i); done
E 3
I 3
		do (echo ${DIRPATH}$$i); done
E 3
I 2

.DEFAULT:
	sccs get $<
E 2
E 1
