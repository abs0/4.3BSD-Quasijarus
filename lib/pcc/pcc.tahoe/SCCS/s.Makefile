h33638
s 00005/00002/00201
d D 1.10 88/01/15 16:34:03 donn 11 10
c 'make depend' should also check fort.c.
e
s 00009/00008/00194
d D 1.9 88/01/13 22:02:27 donn 10 9
c eliminate confusion between "file" and "./file"
e
s 00004/00004/00198
d D 1.8 87/12/10 23:36:59 donn 9 8
c utah rcsid 1.5 87/12/11 00:28:45: Move localdefs.h upstairs so that
c lint can get at it.
e
s 00075/00154/00127
d D 1.7 87/12/10 20:21:03 donn 8 7
c utah rcsid 1.2 87/05/02 14:41:45: Push CONFIG parameters into macdefs.h;
c   fix lint action.
c utah rcsid 1.3 87/12/10 20:26:31: The single-precision compiler is the
c   standard tahoe compiler; delete all the junk for two compilers.
e
s 00091/00071/00190
d D 1.6 87/07/27 16:16:40 bostic 7 5
c fix install and dependencies
e
s 00089/00069/00192
d R 1.6 87/06/06 15:38:20 bostic 6 5
c new template
e
s 00052/00054/00209
d D 1.5 86/10/13 17:11:34 sam 5 4
c move mip one level up
e
s 00188/00121/00075
d D 1.4 86/07/31 22:57:32 sam 4 3
c mucho cleanups
e
s 00014/00019/00182
d D 1.3 86/07/27 16:08:01 sam 3 2
c add tags; table.c now dependent on SPRECC; purge some extra stuff
e
s 00192/00058/00009
d D 1.2 86/02/04 22:20:47 sam 2 1
c integrate vax version
e
s 00067/00000/00000
d D 1.1 86/01/11 11:00:51 sam 1 0
c date and time created 86/01/11 11:00:51 by sam
e
u
U
t
T
I 2
#
E 2
I 1
D 4
#	%M%	%I%	%E%
E 4
I 4
D 8
#	%MIP%	%I%	%E%
E 8
I 8
#	%M%	%I%	%E%
E 8
E 4
#
D 2
# Makefile for portable c compiler
E 2
I 2
# Makefile for tahoe pcc
E 2
#
I 4
RM=	/bin/rm -f
GREP=	egrep
D 5
MIP=	../mip
E 5
I 5
MIP=	../../mip
E 5
#
E 4
D 2
DESTDIR=
M=	../mip.tahoe
CFLAGS=	-O -I${M} -I.
OBJS=	rodata.o cgram.o xdefs.o scan.o pftn.o trees.o optim.o code.o local.o \
	reader.o local2.o order.o match.o allo.o comm1.o table.o stab.o
E 2
I 2
D 8
# These symbols are used to configure the compiler:
#	ASSTRINGS	assembler handles string initializations
#	STABDOT		assembler understands .stabd
#	LCOMM		assembler supports .lcomm
#	FIXSTRUCT	no trickery {just output structure}
#
E 8
# Some symbols are specific to certain compilers:
#	ONEPASS		compile pass 1 and pass 2 together
D 8
#	SPRECC		do single precision in single not double
E 8
#	FORT		get f77-style pass 2
#
D 8
CONFIG=	-DASSTRINGS -DSTABDOT -DLCOMM "-DFIXSTRUCT=outstruct"
E 8
D 4
O=	-O
CFLAGS = ${O} -I. -I${M} ${CONFIG}
E 4
I 4
INCS=	-I. -I${MIP}
CFLAGS=	-O
LDFLAGS=
I 10
LIBS=
E 10
E 4
E 2

D 2
all:	ccom alist
E 2
I 2
D 4
COPTS=	-DONEPASS ${CFLAGS}
SCOPTS=	-DONEPASS -DSPRECC ${CFLAGS}
FOPTS=	-DFORT ${CFLAGS}
LDFLAGS =
E 2

D 2
ccom: 	${OBJS}
	$(CC) $(LDFLAGS) ${OBJS} -o ccom
alist: alist.c
	$(CC) -o alist $(CFLAGS)  alist.c
	
trees.o: $M/manifest macdefs $M/mfile1 $M/trees.c
	$(CC) -c $(CFLAGS)  $M/trees.c
optim.o: $M/manifest macdefs $M/mfile1 $M/optim.c
	$(CC) -c $(CFLAGS) $M/optim.c
pftn.o: $M/manifest macdefs $M/mfile1 $M/pftn.c
	$(CC) -c $(CFLAGS) $M/pftn.c
code.o: $M/manifest macdefs $M/mfile1
	$(CC) -c $(CFLAGS) code.c
local.o: $M/manifest macdefs $M/mfile1
	$(CC) -c $(CFLAGS) local.c
stab.o: $M/manifest macdefs $M/mfile1
	$(CC) -c $(CFLAGS) stab.c
scan.o: $M/manifest macdefs $M/mfile1 $M/scan.c
	$(CC) -c $(CFLAGS) $M/scan.c
xdefs.o: $M/manifest $M/mfile1 macdefs $M/xdefs.c
	$(CC) -c $(CFLAGS) $M/xdefs.c
cgram.o: $M/manifest $M/mfile1 macdefs cgram.c
	$(CC) -c $(CFLAGS) cgram.c
E 2
I 2
RM=	/bin/rm -f

I 3
M=	../mip
SRCS=	code.c local.c local2.c order.c rel.c stab.c table.c \
	$M/allo.c $M/common.c $M/fort.c $M/match.c $M/optim.c \
	$M/pftn.c $M/reader.c $M/scan.c $M/trees.c $M/xdefs.c \
	$M/cgram.y
E 3
# objects common to single and double precision compilers
OBJS=	rodata.o cgram.o xdefs.o scan.o pftn.o optim.o code.o reader.o \
D 3
	match.o comm1.o stab.o local.o local2.o order.o table.o
E 3
I 3
	match.o comm1.o stab.o local.o local2.o order.o
E 3
# double precision objects
D 3
COBJS=	trees.o allo.o
E 3
I 3
COBJS=	trees.o allo.o table.o
E 4
I 4
D 8
# files common to single and double precision compilers
E 8
I 8
# c version
OPTS=	-DONEPASS ${INCS}
FLAGS=	${CFLAGS} ${OPTS}
E 8
SRCS=	code.c local.c local2.c order.c rel.c stab.c \
	${MIP}/common.c ${MIP}/match.c ${MIP}/optim.c ${MIP}/pftn.c \
D 8
	${MIP}/reader.c ${MIP}/scan.c ${MIP}/xdefs.c ${MIP}/cgram.y
E 8
I 8
	${MIP}/reader.c ${MIP}/scan.c ${MIP}/xdefs.c ${MIP}/cgram.y \
	${MIP}/allo.c ${MIP}/trees.c table.c
E 8
OBJS=	code.o local.o local2.o order.o rel.o stab.o \
	comm1.o match.o optim.o pftn.o reader.o scan.o xdefs.o cgram.o \
D 8
	rodata.o
# double precision files
DOPTS=	-DONEPASS ${INCS} ${CONFIG}
DFLAGS=	${CFLAGS} ${DOPTS}
DSRCS=	${MIP}/allo.c ${MIP}/trees.c table.c
DOBJS=	allo.o trees.o table.o
E 4
E 3
# single precision stuff
D 3
SFILES=	strees.c sallo.c
SOBJS=	strees.o sallo.o
E 3
I 3
D 4
SFILES=	strees.c sallo.c stable.c
E 4
I 4
SOPTS=	-DSPRECC -DONEPASS ${INCS} ${CONFIG}
SFLAGS=	${CFLAGS} ${SOPTS}
SSRCS=	strees.c sallo.c stable.c
E 4
SOBJS=	strees.o sallo.o stable.o
E 8
I 8
	allo.o trees.o table.o rodata.o
E 8
E 3
# fortran version
D 3
FFILES=	freader.c fallo.c fmatch.c ftable.c forder.c flocal2.c fcomm2.c
FOBJS=	freader.o fallo.o fmatch.o ftable.o forder.o flocal2.o fcomm2.o
E 3
I 3
D 4
FFILES=	freader.c fallo.c fmatch.c ftable.c forder.c flocal2.c fcomm2.c ftable.c
E 4
I 4
D 8
FOPTS=	-DFORT ${INCS} ${CONFIG}
E 8
I 8
FOPTS=	-DFORT ${INCS}
E 8
FFLAGS=	${CFLAGS} ${FOPTS}
FSRCS=	freader.c fallo.c fmatch.c ftable.c forder.c flocal2.c fcomm2.c ftable.c
E 4
FOBJS=	freader.o fallo.o fmatch.o ftable.o forder.o flocal2.o fcomm2.o ftable.o
E 3

D 4
P1INCS=	$M/pass1.h macdefs.h $M/manifest.h pcclocal.h $M/config.h $M/ndu.h \
	/usr/include/stdio.h
P1ONEP=	${P1INCS} $M/onepass.h
P2INCS=	$M/pass2.h macdefs.h mac2defs.h $M/manifest.h pcclocal.h $M/config.h \
	$M/ndu.h /usr/include/stdio.h
P2ONEP=	${P2INCS} $M/onepass.h

E 4
D 3
M=	../mip
E 3
TESTDIR=.

D 7
all:	ccom sccom f1
E 7
I 7
D 8
all:	./pcctokens ./pcclocal.h ccom sccom f1
E 8
I 8
D 10
all:	./pcctokens ./pcclocal.h ccom f1
E 10
I 10
all:	ccom f1
E 10
E 8
E 7

#
# 'ccom' is a one-pass C compiler.
#
D 4
ccom:	${OBJS} ${COBJS} rel.o
	${CC} ${LDFLAGS} -o ${TESTDIR}/ccom ${OBJS} ${COBJS} rel.o
trees.o: ${P1ONEP} $M/trees.c
	${CC} -c ${COPTS} $M/trees.c
optim.o: ${P1ONEP} $M/optim.c
	${CC} -c ${COPTS} $M/optim.c
pftn.o: ${P1ONEP} $M/pftn.c
	${CC} -c ${COPTS} $M/pftn.c
code.o: ${P1ONEP} code.c
	${CC} -c ${COPTS} code.c
local.o: ${P1ONEP} local.c
	${CC} -c ${COPTS} local.c
scan.o: ${P1ONEP} $M/scan.c
	${CC} -c ${COPTS} $M/scan.c
xdefs.o: ${P1ONEP} $M/xdefs.c
	${CC} -c ${COPTS} $M/xdefs.c
cgram.o: ${P1ONEP} cgram.c
	${CC} -c ${COPTS} cgram.c
E 4
I 4
D 8
ccom:	${OBJS} ${DOBJS} rel.o
	${CC} ${LDFLAGS} -o ${TESTDIR}/ccom ${OBJS} ${DOBJS} rel.o
E 8
I 8
ccom:	${OBJS} rel.o
D 10
	${CC} ${LDFLAGS} -o ${TESTDIR}/ccom ${OBJS} rel.o
E 10
I 10
	${CC} ${LDFLAGS} -o ${TESTDIR}/ccom ${OBJS} rel.o ${LIBS}
E 10
E 8
trees.o: ${MIP}/trees.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/trees.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/trees.c
E 8
optim.o: ${MIP}/optim.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/optim.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/optim.c
E 8
pftn.o: ${MIP}/pftn.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/pftn.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/pftn.c
E 8
code.o: code.c
D 8
	${CC} -c ${DFLAGS} code.c
E 8
I 8
	${CC} -c ${FLAGS} code.c
E 8
local.o: local.c
D 8
	${CC} -c ${DFLAGS} local.c
E 8
I 8
	${CC} -c ${FLAGS} local.c
E 8
scan.o: ${MIP}/scan.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/scan.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/scan.c
E 8
xdefs.o: ${MIP}/xdefs.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/xdefs.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/xdefs.c
E 8
cgram.o: cgram.c
D 8
	${CC} -c ${DFLAGS} cgram.c
E 8
I 8
	${CC} -c ${FLAGS} cgram.c
E 8
E 4
E 2
rodata.o: rodata.c
D 2
	$(CC) -c $(CFLAGS) -R rodata.c
rodata.c cgram.c: $M/cgram.y
	$(YACC) $M/cgram.y
	rm -f rodata.c
	./:yyfix yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 2
I 2
D 4
	${CC} -c ${COPTS} -R rodata.c
rodata.c cgram.c: $M/cgram.y pcctokens
	cat pcctokens $M/cgram.y > gram.in
E 4
I 4
D 8
	${CC} -c ${DFLAGS} -R rodata.c
E 8
I 8
	${CC} -c ${FLAGS} -R rodata.c
E 8
D 10
rodata.c cgram.c: ${MIP}/cgram.y ./pcctokens
E 10
I 10
rodata.c cgram.c: ${MIP}/cgram.y pcctokens
E 10
	cat pcctokens ${MIP}/cgram.y > gram.in
E 4
	${YACC} gram.in
	${RM} rodata.c
D 10
	sh ./:yyfix yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 10
I 10
	sh :yyfix yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 10
E 2
	mv y.tab.c cgram.c
D 2
comm1.o: $M/manifest $M/mfile1 $M/common macdefs $M/comm1.c
	$(CC) -c $(CFLAGS) $M/comm1.c
table.o: $M/manifest $M/mfile2 mac2defs macdefs table.c
	$(CC) -c $(CFLAGS) -R table.c
reader.o: $M/manifest $M/mfile2 mac2defs macdefs $M/reader.c
	$(CC) -c $(CFLAGS) $M/reader.c
local2.o: $M/manifest $M/mfile2 mac2defs macdefs
	$(CC) -c $(CFLAGS) local2.c
order.o: $M/manifest $M/mfile2 mac2defs macdefs
	$(CC) -c $(CFLAGS) order.c
match.o: $M/manifest $M/mfile2 mac2defs macdefs $M/match.c
	$(CC) -c $(CFLAGS) $M/match.c
allo.o: $M/manifest $M/mfile2 mac2defs macdefs $M/allo.c
	$(CC) -c $(CFLAGS) $M/allo.c
clean:
	rm -f *.o ccom cgram.c rodata.c
lintall:
	lint -hv -I. -I$M $(CFLAGS) rodata.c cgram.c $M/xdefs.c \
	$M/scan.c $M/pftn.c $M/trees.c $M/optim.c code.c local.c \
	$M/reader.c local2.c order.c $M/match.c $M/allo.c $M/comm1.c table.c
E 2
I 2
D 4
comm1.o: ${P1ONEP} $M/common.c
	ln $M/common.c comm1.c
	${CC} -c ${COPTS} -DPASS1COMMON comm1.c
E 4
I 4
comm1.o: ${MIP}/common.c
	ln ${MIP}/common.c comm1.c
D 8
	${CC} -c ${DFLAGS} -DPASS1COMMON comm1.c
E 8
I 8
	${CC} -c ${FLAGS} -DPASS1COMMON comm1.c
E 8
E 4
	${RM} comm1.c
D 4
stab.o: ${P1ONEP} stab.c \
	/usr/include/stab.h /usr/include/a.out.h /usr/include/sys/types.h
	${CC} -c ${COPTS} stab.c
table.o: ${P2ONEP} table.c
	${CC} -c ${COPTS} -R table.c
reader.o: ${P2ONEP} $M/reader.c
	${CC} -c ${COPTS} $M/reader.c
local2.o: ${P2ONEP} local2.c
	${CC} -c ${COPTS} local2.c
order.o: ${P2ONEP} order.c
	${CC} -c ${COPTS} order.c
match.o: ${P2ONEP} $M/match.c
	${CC} -c ${COPTS} $M/match.c
allo.o: ${P2ONEP} $M/allo.c
	${CC} -c ${COPTS} $M/allo.c
E 4
I 4
stab.o: stab.c
D 8
	${CC} -c ${DFLAGS} stab.c
E 8
I 8
	${CC} -c ${FLAGS} stab.c
E 8
table.o: table.c
D 8
	${CC} -c ${DFLAGS} -R table.c
E 8
I 8
	${CC} -c ${FLAGS} -R table.c
E 8
reader.o: ${MIP}/reader.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/reader.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/reader.c
E 8
local2.o: local2.c
D 8
	${CC} -c ${DFLAGS} local2.c
E 8
I 8
	${CC} -c ${FLAGS} local2.c
E 8
order.o: order.c
D 8
	${CC} -c ${DFLAGS} order.c
E 8
I 8
	${CC} -c ${FLAGS} order.c
E 8
match.o: ${MIP}/match.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/match.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/match.c
E 8
allo.o: ${MIP}/allo.c
D 8
	${CC} -c ${DFLAGS} ${MIP}/allo.c
E 8
I 8
	${CC} -c ${FLAGS} ${MIP}/allo.c
E 8
E 4
E 2

I 2
#
D 8
# 'sccom' is a C compiler that does single precision computations in
#	single precision rather than double precision.
#
sccom:	${OBJS} ${SOBJS} rel.o
	${CC} ${LDFLAGS} -o ${TESTDIR}/sccom ${OBJS} ${SOBJS} rel.o
D 4
strees.o: ${P1ONEP} $M/trees.c
	ln $M/trees.c strees.c
	${CC} -c ${SCOPTS} strees.c
E 4
I 4
strees.o: ${MIP}/trees.c
	ln ${MIP}/trees.c strees.c
	${CC} -c ${SFLAGS} strees.c
E 4
	${RM} strees.c
D 3
slocal.o: ${P1ONEP} local.c
	ln local.c slocal.c
	${CC} -c ${SCOPTS} slocal.c
	${RM} slocal.c
slocal2.o: ${P2ONEP} local2.c
	ln local2.c slocal2.c
	${CC} -c ${SCOPTS} slocal2.c
	${RM} slocal2.c
E 3
D 4
sallo.o: ${P2ONEP} $M/allo.c
	ln $M/allo.c sallo.c
	${CC} -c ${SCOPTS} sallo.c
E 4
I 4
sallo.o: ${MIP}/allo.c
	ln ${MIP}/allo.c sallo.c
	${CC} -c ${SFLAGS} sallo.c
E 4
	${RM} sallo.c
D 3
sorder.o: ${P2ONEP} order.c
	ln order.c sorder.c
	${CC} -c ${SCOPTS} sorder.c
	${RM} sorder.c
E 3
D 4
stable.o: ${P2ONEP} table.c
E 4
I 4
stable.o: table.c
E 4
	ln table.c stable.c
D 4
	${CC} -c ${SCOPTS} -R stable.c
E 4
I 4
	${CC} -c ${SFLAGS} -R stable.c
E 4
	${RM} stable.c

#
E 8
# 'f1' is the f77 and pc code generator.
#
f1:	fort.o ${FOBJS}
D 10
	${CC} ${LDFLAGS} -o ${TESTDIR}/f1 fort.o ${FOBJS}
E 10
I 10
	${CC} ${LDFLAGS} -o ${TESTDIR}/f1 fort.o ${FOBJS} ${LIBS}
E 10
D 4
fort.o: ${P2INCS} fort.h $M/fort.c
	${CC} -c ${FOPTS} $M/fort.c
freader.o: ${P2INCS} $M/reader.c
	ln $M/reader.c freader.c
	${CC} -c ${FOPTS} freader.c
E 4
I 4
fort.o: fort.h ${MIP}/fort.c
	${CC} -c ${FFLAGS} ${MIP}/fort.c
freader.o: ${MIP}/reader.c
	ln ${MIP}/reader.c freader.c
	${CC} -c ${FFLAGS} freader.c
E 4
	${RM} freader.c
D 4
fallo.o: ${P2INCS} $M/allo.c
	ln $M/allo.c fallo.c
	${CC} -c ${FOPTS} fallo.c
E 4
I 4
fallo.o: ${MIP}/allo.c
	ln ${MIP}/allo.c fallo.c
	${CC} -c ${FFLAGS} fallo.c
E 4
	${RM} fallo.c
D 4
fmatch.o: ${P2INCS} $M/match.c
	ln $M/match.c fmatch.c
	${CC} -c ${FOPTS} fmatch.c
E 4
I 4
fmatch.o: ${MIP}/match.c
	ln ${MIP}/match.c fmatch.c
	${CC} -c ${FFLAGS} fmatch.c
E 4
	${RM} fmatch.c
D 4
ftable.o: ${P2INCS} table.c
E 4
I 4
ftable.o: table.c
E 4
	ln table.c ftable.c
D 4
	${CC} -c -R ${FOPTS} ftable.c
E 4
I 4
	${CC} -c -R ${FFLAGS} ftable.c
E 4
	${RM} ftable.c
D 4
forder.o: ${P2INCS} order.c
E 4
I 4
forder.o: order.c
E 4
	ln order.c forder.c
D 4
	${CC} -c ${FOPTS} forder.c
E 4
I 4
	${CC} -c ${FFLAGS} forder.c
E 4
	${RM} forder.c
D 4
flocal2.o: ${P2INCS} local2.c
E 4
I 4
flocal2.o: local2.c
E 4
	ln local2.c flocal2.c
D 4
	${CC} -c ${FOPTS} flocal2.c
E 4
I 4
	${CC} -c ${FFLAGS} flocal2.c
E 4
	${RM} flocal2.c
D 4
fcomm2.o: ${P2INCS} $M/common.c
	ln $M/common.c fcomm2.c
	${CC} -c ${FOPTS} -DPASS2COMMON fcomm2.c
E 4
I 4
fcomm2.o: ${MIP}/common.c
	ln ${MIP}/common.c fcomm2.c
	${CC} -c ${FFLAGS} -DPASS2COMMON fcomm2.c
E 4
	${RM} fcomm2.c

E 2
D 7
install: all
D 2
	-mv ${DESTDIR}/lib/ccom ${DESTDIR}/lib/ccom.old
	install -s ccom ${DESTDIR}/lib/ccom
	install -s alist ${DESTDIR}/lib/alist
E 2
I 2
	install -s ${TESTDIR}/ccom ${DESTDIR}/lib/ccom
	install -s ${TESTDIR}/sccom ${DESTDIR}/lib/sccom
	install -s ${TESTDIR}/f1 ${DESTDIR}/lib/f1
E 7
I 7
install:
	install -s -o bin -g bin -m 755 ${TESTDIR}/ccom ${DESTDIR}/lib/ccom
D 8
	install -s -o bin -g bin -m 755 ${TESTDIR}/sccom ${DESTDIR}/lib/sccom
E 8
	install -s -o bin -g bin -m 755 ${TESTDIR}/f1 ${DESTDIR}/lib/f1
E 7

D 4
GREP=	egrep

pcclocal.h: localdefs.h /usr/include/pcc.h
E 4
I 4
D 9
./pcclocal.h: localdefs.h /usr/include/pcc.h
E 9
I 9
D 10
./pcclocal.h: ../localdefs.h /usr/include/pcc.h
E 10
I 10
pcclocal.h: ../localdefs.h /usr/include/pcc.h
E 10
E 9
E 4
	${RM} pcclocal.h
D 4
	cat /usr/include/pcc.h localdefs.h | ${GREP} '^#[ 	]*(define[ 	][ 	]*PCC(F|T|TM|OM)?_|ifdef|ifndef|endif)' | sed -e 's/PCC[A-Z]*_//' > pcclocal.h 
E 4
I 4
D 9
	cat /usr/include/pcc.h localdefs.h | \
E 9
I 9
	cat /usr/include/pcc.h ../localdefs.h | \
E 9
	    ${GREP} '^#[ 	]*(define[ 	][ 	]*PCC(F|T|TM|OM)?_|ifdef|ifndef|endif)' | \
	    sed -e 's/PCC[A-Z]*_//' > pcclocal.h 
E 4

D 4
pcctokens: localdefs.h /usr/include/pcc.h
E 4
I 4
D 9
./pcctokens: localdefs.h /usr/include/pcc.h
E 9
I 9
D 10
./pcctokens: ../localdefs.h /usr/include/pcc.h
E 10
I 10
pcctokens: ../localdefs.h /usr/include/pcc.h
E 10
E 9
E 4
	${RM} pcctokens
D 4
	cat /usr/include/pcc.h localdefs.h | ${GREP} '^#[ 	]*define[ 	][ 	]*PCC_' | sed -e 's/^#[ 	]*define[ 	][ 	]*PCC_/%term	/' > pcctokens
E 4
I 4
D 9
	cat /usr/include/pcc.h localdefs.h | \
E 9
I 9
	cat /usr/include/pcc.h ../localdefs.h | \
E 9
	    ${GREP} '^#[ 	]*define[ 	][ 	]*PCC_' | sed -e 's/^#[ 	]*define[ 	][ 	]*PCC_/%term	/' > pcctokens
E 4

D 4
DUMMIES=	${SFILES} ${FFILES}

shrink:
	${RM} *.o ccom sccom f1 ${DUMMIES}
E 4
clean:
D 4
	${RM} *.o ccom sccom f1 cgram.c rodata.c pcctokens pcclocal.h gram.in ${DUMMIES}
sfix:
	${RM} ${SFILES}
sclean:
	${RM} ${SOBJS} ${SFILES}
ffix:
	${RM} ${FFILES}
fclean:
	${RM} ${FOBJS} ${FFILES}
E 4
I 4
D 8
	${RM} *.o ccom sccom f1 cgram.c rodata.c pcctokens pcclocal.h \
E 8
I 8
	${RM} *.o ccom f1 cgram.c rodata.c pcctokens pcclocal.h \
E 8
	    gram.in ${SSRCS} ${FSRCS}
E 4

D 4
lintall:
	lint -hax -I. -I$M  cgram.c $M/xdefs.c $M/scan.c $M/pftn.c \
		$M/trees.c $M/optim.c code.c local.c stab.c $M/reader.c \
		local2.c order.c $M/match.c $M/allo.c $M/comm1.c table.c
E 4
I 4
lint:
D 8
	lint -hax ${INCS} -I${MIP} cgram.c \
E 8
I 8
	lint -hx ${OPTS} -DPASS1COMMON cgram.c \
E 8
	    ${MIP}/xdefs.c ${MIP}/scan.c ${MIP}/pftn.c ${MIP}/trees.c \
	    ${MIP}/optim.c ${MIP}/reader.c ${MIP}/match.c ${MIP}/allo.c \
D 8
	    ${MIP}/comm1.c \
	    code.c local.c stab.c local2.c order.c table.c
E 8
I 8
	    ${MIP}/common.c \
	    code.c local.c stab.c local2.c order.c table.c rel.c
E 8
E 4
I 3

D 4
tags:	${SRCS}
	ctags ${SRCS}
E 4
I 4
D 8
tags:	${SRCS} ${DSRCS}
	ctags ${SRCS} ${DSRCS}
E 8
I 8
tags:	${SRCS}
	ctags ${SRCS}
E 8

# XXX this is less than complete
D 8
depend: ${SRCS} ${DSRCS} ./pcclocal.h ./pcctokens
D 7
	for i in ${SRCS} ${DSRCS}; do \
	    cc -M ${DOPTS} $$i | \
	    awk ' { if ($$1 != prev) \
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
E 7
I 7
	mkdep ${CFLAGS} ${INCS} ${SRCS} ${DSRCS}
E 8
I 8
D 10
depend: ${SRCS} ./pcclocal.h ./pcctokens
E 10
I 10
D 11
depend: ${SRCS} pcclocal.h pcctokens
E 10
	mkdep ${CFLAGS} ${INCS} ${SRCS}
E 11
I 11
depend: ${SRCS} ${MIP}/fort.c pcclocal.h pcctokens
	mkdep ${CFLAGS} ${INCS} ${SRCS} ${MIP}/fort.c
E 11
E 8
E 7

D 7
# DO NOT DELETE THIS LINE
E 7
I 7
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 7

D 5
code.o: code.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
code.o: /usr/include/stdio.h ../mip/config.h ../mip/onepass.h ../mip/ndu.h
code.o: /usr/include/sys/types.h /usr/include/a.out.h /usr/include/sys/exec.h
code.o: /usr/include/stab.h
code.o: code.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
code.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
code.o: ../mip/ndu.h /usr/include/sys/types.h /usr/include/a.out.h
code.o: /usr/include/sys/exec.h /usr/include/stab.h
local.o: local.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
local.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
local.o: ../mip/ndu.h
local2.o: local2.c ../mip/pass2.h ./macdefs.h ./mac2defs.h ../mip/manifest.h
local2.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
local2.o: ../mip/ndu.h /usr/include/ctype.h
order.o: order.c ../mip/pass2.h ./macdefs.h ./mac2defs.h ../mip/manifest.h
order.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
order.o: ../mip/ndu.h
E 5
I 5
D 7
code.o: code.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
code.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
code.o: ../../mip/onepass.h ../../mip/ndu.h /usr/include/sys/types.h
E 7
I 7
D 8
code.o: code.c ../../mip/pass1.h
code.o:macdefs.h
code.o: ../../mip/manifest.h /usr/include/stdio.h
code.o:pcclocal.h
code.o: ../../mip/config.h ../../mip/ndu.h /usr/include/sys/types.h
E 7
code.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
D 7
local.o: local.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
local.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
local.o: ../../mip/onepass.h ../../mip/ndu.h
local2.o: local2.c ../../mip/pass2.h ./macdefs.h ./mac2defs.h
local2.o: ../../mip/manifest.h /usr/include/stdio.h ./pcclocal.h
local2.o: ../../mip/config.h ../../mip/onepass.h ../../mip/ndu.h
local2.o: /usr/include/ctype.h
order.o: order.c ../../mip/pass2.h ./macdefs.h ./mac2defs.h
order.o: ../../mip/manifest.h /usr/include/stdio.h ./pcclocal.h
order.o: ../../mip/config.h ../../mip/onepass.h ../../mip/ndu.h
E 7
I 7
local.o: local.c ../../mip/pass1.h
local.o:macdefs.h
local.o: ../../mip/manifest.h /usr/include/stdio.h
local.o:pcclocal.h
local.o: ../../mip/config.h ../../mip/ndu.h
local2.o: local2.c ../../mip/pass2.h
local2.o:macdefs.h
local2.o:mac2defs.h
local2.o: ../../mip/manifest.h /usr/include/stdio.h
local2.o:pcclocal.h
local2.o: ../../mip/config.h ../../mip/ndu.h /usr/include/ctype.h
order.o: order.c ../../mip/pass2.h
order.o:macdefs.h
order.o:mac2defs.h
order.o: ../../mip/manifest.h /usr/include/stdio.h
order.o:pcclocal.h
order.o: ../../mip/config.h ../../mip/ndu.h
E 8
I 8
code.o: code.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
code.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
code.o: /usr/include/sys/types.h /usr/include/a.out.h /usr/include/sys/exec.h
code.o: /usr/include/stab.h
local.o: local.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
local.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
local2.o: local2.c ../../mip/pass2.h macdefs.h mac2defs.h ../../mip/manifest.h
local2.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
local2.o: /usr/include/ctype.h
order.o: order.c ../../mip/pass2.h macdefs.h mac2defs.h ../../mip/manifest.h
order.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
E 8
E 7
E 5
rel.o: rel.c
D 5
stab.o: stab.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
stab.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
stab.o: ../mip/ndu.h /usr/include/sys/types.h /usr/include/a.out.h
stab.o: /usr/include/sys/exec.h /usr/include/stab.h
common.o: ../mip/common.c
match.o: ../mip/match.c ../mip/pass2.h ./macdefs.h ./mac2defs.h
match.o: ../mip/manifest.h /usr/include/stdio.h ./pcclocal.h ../mip/config.h
match.o: ../mip/onepass.h ../mip/ndu.h
optim.o: ../mip/optim.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
optim.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
optim.o: ../mip/ndu.h
pftn.o: ../mip/pftn.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
pftn.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
pftn.o: ../mip/ndu.h
reader.o: ../mip/reader.c ../mip/pass2.h ./macdefs.h ./mac2defs.h
reader.o: ../mip/manifest.h /usr/include/stdio.h ./pcclocal.h ../mip/config.h
reader.o: ../mip/onepass.h ../mip/ndu.h
scan.o: ../mip/scan.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
scan.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
scan.o: ../mip/ndu.h /usr/include/a.out.h /usr/include/sys/exec.h
scan.o: /usr/include/stab.h /usr/include/ctype.h /usr/include/signal.h
xdefs.o: ../mip/xdefs.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
xdefs.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
xdefs.o: ../mip/ndu.h
cgram.o: ../mip/cgram.y ../mip/pass1.h ./macdefs.h ../mip/manifest.h
cgram.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
cgram.o: ../mip/ndu.h
allo.o: ../mip/allo.c ../mip/pass2.h ./macdefs.h ./mac2defs.h ../mip/manifest.h
allo.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
allo.o: ../mip/ndu.h
trees.o: ../mip/trees.c ../mip/pass1.h ./macdefs.h ../mip/manifest.h
trees.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
trees.o: ../mip/ndu.h /usr/include/setjmp.h
table.o: table.c ../mip/pass2.h ./macdefs.h ./mac2defs.h ../mip/manifest.h
table.o: /usr/include/stdio.h ./pcclocal.h ../mip/config.h ../mip/onepass.h
table.o: ../mip/ndu.h
E 5
I 5
D 7
stab.o: stab.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
stab.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
stab.o: ../../mip/onepass.h ../../mip/ndu.h /usr/include/sys/types.h
E 7
I 7
D 8
stab.o: stab.c ../../mip/pass1.h
stab.o:macdefs.h
stab.o: ../../mip/manifest.h /usr/include/stdio.h
stab.o:pcclocal.h
stab.o: ../../mip/config.h ../../mip/ndu.h /usr/include/sys/types.h
E 7
stab.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
E 8
I 8
stab.o: stab.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
stab.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
stab.o: /usr/include/sys/types.h /usr/include/a.out.h /usr/include/sys/exec.h
stab.o: /usr/include/stab.h
E 8
common.o: ../../mip/common.c
D 7
match.o: ../../mip/match.c ../../mip/pass2.h ./macdefs.h ./mac2defs.h
match.o: ../../mip/manifest.h /usr/include/stdio.h ./pcclocal.h
match.o: ../../mip/config.h ../../mip/onepass.h ../../mip/ndu.h
optim.o: ../../mip/optim.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
optim.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
optim.o: ../../mip/onepass.h ../../mip/ndu.h
pftn.o: ../../mip/pftn.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
pftn.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
pftn.o: ../../mip/onepass.h ../../mip/ndu.h
reader.o: ../../mip/reader.c ../../mip/pass2.h ./macdefs.h ./mac2defs.h
reader.o: ../../mip/manifest.h /usr/include/stdio.h ./pcclocal.h
reader.o: ../../mip/config.h ../../mip/onepass.h ../../mip/ndu.h
scan.o: ../../mip/scan.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
scan.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
scan.o: ../../mip/onepass.h ../../mip/ndu.h /usr/include/a.out.h
E 7
I 7
D 8
match.o: ../../mip/match.c ../../mip/pass2.h
match.o:macdefs.h
match.o:mac2defs.h
match.o: ../../mip/manifest.h /usr/include/stdio.h
match.o:pcclocal.h
E 8
I 8
match.o: ../../mip/match.c ../../mip/pass2.h macdefs.h mac2defs.h
match.o: ../../mip/manifest.h /usr/include/stdio.h pcclocal.h
E 8
match.o: ../../mip/config.h ../../mip/ndu.h
D 8
optim.o: ../../mip/optim.c ../../mip/pass1.h
optim.o:macdefs.h
optim.o: ../../mip/manifest.h /usr/include/stdio.h
optim.o:pcclocal.h
optim.o: ../../mip/config.h ../../mip/ndu.h
pftn.o: ../../mip/pftn.c ../../mip/pass1.h
pftn.o:macdefs.h
pftn.o: ../../mip/manifest.h /usr/include/stdio.h
pftn.o:pcclocal.h
pftn.o: ../../mip/config.h ../../mip/ndu.h
reader.o: ../../mip/reader.c ../../mip/pass2.h
reader.o:macdefs.h
reader.o:mac2defs.h
reader.o: ../../mip/manifest.h /usr/include/stdio.h
reader.o:pcclocal.h
E 8
I 8
optim.o: ../../mip/optim.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
optim.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
pftn.o: ../../mip/pftn.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
pftn.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
reader.o: ../../mip/reader.c ../../mip/pass2.h macdefs.h mac2defs.h
reader.o: ../../mip/manifest.h /usr/include/stdio.h pcclocal.h
E 8
reader.o: ../../mip/config.h ../../mip/ndu.h
D 8
scan.o: ../../mip/scan.c ../../mip/pass1.h
scan.o:macdefs.h
scan.o: ../../mip/manifest.h /usr/include/stdio.h
scan.o:pcclocal.h
scan.o: ../../mip/config.h ../../mip/ndu.h /usr/include/a.out.h
E 7
scan.o: /usr/include/sys/exec.h /usr/include/stab.h /usr/include/ctype.h
scan.o: /usr/include/signal.h
D 7
xdefs.o: ../../mip/xdefs.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
xdefs.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
xdefs.o: ../../mip/onepass.h ../../mip/ndu.h
cgram.o: ../../mip/cgram.y ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
cgram.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
cgram.o: ../../mip/onepass.h ../../mip/ndu.h
allo.o: ../../mip/allo.c ../../mip/pass2.h ./macdefs.h ./mac2defs.h
allo.o: ../../mip/manifest.h /usr/include/stdio.h ./pcclocal.h
allo.o: ../../mip/config.h ../../mip/onepass.h ../../mip/ndu.h
trees.o: ../../mip/trees.c ../../mip/pass1.h ./macdefs.h ../../mip/manifest.h
trees.o: /usr/include/stdio.h ./pcclocal.h ../../mip/config.h
trees.o: ../../mip/onepass.h ../../mip/ndu.h /usr/include/setjmp.h
table.o: table.c ../../mip/pass2.h ./macdefs.h ./mac2defs.h
table.o: ../../mip/manifest.h /usr/include/stdio.h ./pcclocal.h
table.o: ../../mip/config.h ../../mip/onepass.h ../../mip/ndu.h
E 5
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 7
I 7
xdefs.o: ../../mip/xdefs.c ../../mip/pass1.h
xdefs.o:macdefs.h
xdefs.o: ../../mip/manifest.h /usr/include/stdio.h
xdefs.o:pcclocal.h
xdefs.o: ../../mip/config.h ../../mip/ndu.h
cgram.o: ../../mip/cgram.y ../../mip/pass1.h
cgram.o:macdefs.h
cgram.o: ../../mip/manifest.h /usr/include/stdio.h
cgram.o:pcclocal.h
cgram.o: ../../mip/config.h ../../mip/ndu.h
allo.o: ../../mip/allo.c ../../mip/pass2.h
allo.o:macdefs.h
allo.o:mac2defs.h
allo.o: ../../mip/manifest.h /usr/include/stdio.h
allo.o:pcclocal.h
allo.o: ../../mip/config.h ../../mip/ndu.h
trees.o: ../../mip/trees.c ../../mip/pass1.h
trees.o:macdefs.h
trees.o: ../../mip/manifest.h /usr/include/stdio.h
trees.o:pcclocal.h
trees.o: ../../mip/config.h ../../mip/ndu.h /usr/include/setjmp.h
table.o: table.c ../../mip/pass2.h
table.o:macdefs.h
table.o:mac2defs.h
table.o: ../../mip/manifest.h /usr/include/stdio.h
table.o:pcclocal.h
table.o: ../../mip/config.h ../../mip/ndu.h
E 8
I 8
scan.o: ../../mip/scan.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
scan.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
scan.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
scan.o: /usr/include/ctype.h /usr/include/signal.h /usr/include/machine/trap.h
xdefs.o: ../../mip/xdefs.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
xdefs.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
cgram.o: ../../mip/cgram.y ../../mip/pass1.h macdefs.h ../../mip/manifest.h
cgram.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
allo.o: ../../mip/allo.c ../../mip/pass2.h macdefs.h mac2defs.h
allo.o: ../../mip/manifest.h /usr/include/stdio.h pcclocal.h ../../mip/config.h
allo.o: ../../mip/ndu.h
trees.o: ../../mip/trees.c ../../mip/pass1.h macdefs.h ../../mip/manifest.h
trees.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
trees.o: /usr/include/setjmp.h
table.o: table.c ../../mip/pass2.h macdefs.h mac2defs.h ../../mip/manifest.h
table.o: /usr/include/stdio.h pcclocal.h ../../mip/config.h ../../mip/ndu.h
I 11
fort.o: ../../mip/fort.c ../../mip/pass2.h macdefs.h mac2defs.h
fort.o: ../../mip/manifest.h /usr/include/stdio.h pcclocal.h ../../mip/config.h
fort.o: ../../mip/ndu.h fort.h
E 11
E 8

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 4
E 3
E 2
E 1
