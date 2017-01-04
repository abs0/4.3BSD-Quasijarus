h50386
s 00010/00015/00187
d D 1.17 87/12/11 00:15:54 donn 18 17
c utah rcsid 1.5 86/08/03 00:58:14: Move configuration flags to macdefs.h.
c utah rcsid 1.7 87/01/15 01:34:57: Make 'lintall' entry more reasonable.
c utah rcsid 1.8 87/07/07 21:08:55: Move localdefs.h upstairs so that
c lint can get at it.
e
s 00006/00003/00196
d D 1.16 87/07/06 16:35:54 bostic 17 15
c tags, depend, install
e
s 00006/00003/00196
d R 1.16 87/06/06 15:30:00 bostic 16 15
c added tags/depend labels
e
s 00007/00011/00192
d D 1.15 86/10/15 21:47:12 sam 15 14
c add stuff for rel.o and such
e
s 00001/00001/00202
d D 1.14 86/10/13 17:12:17 sam 14 13
c move mip one level up
e
s 00015/00014/00188
d D 1.13 86/03/11 12:41:51 mckusick 13 12
c use `ln -s' to avoid modifying time on .o files forcing rebuild
c (from William Sommerfeld <wesommer@athena.mit.edu>)
e
s 00085/00075/00117
d D 1.12 85/08/23 15:02:53 mckusick 12 11
c update from donn@utah-cs
e
s 00005/00005/00187
d D 1.11 85/04/18 12:32:08 edward 11 10
c don't -g when loading, but do -s when installing
e
s 00042/00033/00150
d D 1.10 85/04/08 11:48:05 ralph 10 9
c move ONEPASS definition so lint will compile.
e
s 00125/00065/00058
d D 1.9 85/04/02 11:52:17 ralph 9 8
c use common header file for intermediate language defs.
e
s 00001/00001/00122
d D 1.8 85/01/24 10:44:33 ralph 8 7
c delete dependency on comp for making fort.
e
s 00042/00013/00081
d D 1.7 85/01/18 16:10:30 ralph 7 6
c added scomp for single precision floats (should be a flag to comp).
e
s 00004/00002/00090
d D 1.6 85/01/17 09:45:38 ralph 6 5
c added sccs header, fix make lintall
e
s 00003/00005/00089
d D 1.5 84/03/14 15:42:24 ralph 5 4
c merge f1 and c1; fix type casting conversion bugs.
e
s 00005/00003/00089
d D 1.4 83/08/09 13:01:27 karels 4 3
c fort not included in "all" or "install" until f77 copy of sources
c is merged back into these.
e
s 00003/00001/00089
d D 1.3 83/04/08 02:13:56 linton 3 2
c added O definition for either -O or -g, made LDFLAGS = -g by default
e
s 00008/00006/00082
d D 1.2 82/12/18 11:36:08 linton 2 1
c added new symbol stuff for dbx, split symbol table dumping 
c off into separate file ("stab.c")
e
s 00088/00000/00000
d D 1.1 82/12/15 13:26:10 linton 1 0
c date and time created 82/12/15 13:26:10 by linton
e
u
U
t
T
I 9
#
E 9
I 6
#	%M%	%I%	%E%
#
E 6
I 1
D 9
TESTDIR = .
FRC =
E 9
I 9
# Makefile for PCC
#
D 18
# These symbols are used to configure the compiler:
#	ASSTRINGS	assembler handles string initializations
#	STABDOT		assembler understands .stabd
#	LCOMM		assembler supports .lcomm
#	FIXSTRUCT	no trickery (just output structure)
#
E 18
I 10
# Some symbols are specific to certain compilers:
#	ONEPASS		compile pass 1 and pass 2 together
#	SPRECC		do single precision in single not double
#	FORT		get f77-style pass 2
#
E 10
D 18
CONFIG=	-DASSTRINGS -DSTABDOT -DLCOMM "-DFIXSTRUCT=outstruct"
E 18
E 9
D 2
CFLAGS = -O -DASSTRINGS -DSTABDOT -DLCOMM -DBUFSTDERR -DFLEXNAMES
E 2
I 2
D 3
CFLAGS = -O -I. -I${M} -DASSTRINGS -DSTABDOT -DLCOMM -DBUFSTDERR -DFLEXNAMES \
E 3
I 3
O = -O
D 9
CFLAGS = ${O} -I. -I${M} -DASSTRINGS -DSTABDOT -DLCOMM -DBUFSTDERR -DFLEXNAMES \
E 3
    "-DFIXSTRUCT=outstruct"
E 9
I 9
D 18
CFLAGS = $(O) -I. -I$(M) $(CONFIG)
E 18
I 18
CFLAGS = $(O) -I. -I$(M)
E 18
I 10

COPTS = -DONEPASS $(CFLAGS)
SCOPTS = -DONEPASS -DSPRECC $(CFLAGS)
FOPTS = -DFORT $(CFLAGS)
E 10
E 9
I 3
D 11
LDFLAGS = -g
E 11
I 11
LDFLAGS =
E 11
E 3

I 9
RM=	/bin/rm -f
I 13
LN=	/bin/ln -s
E 13

SFILES=	strees.c slocal.c slocal2.c sallo.c sorder.c stable.c
SOBJS=	strees.o slocal.o slocal2.o sallo.o sorder.o stable.o
FFILES=	freader.c fallo.c fmatch.c ftable.c forder.c flocal2.c fcomm2.c
FOBJS=	freader.o fallo.o fmatch.o ftable.o forder.o flocal2.o fcomm2.o

I 12
P1INCS=	$M/pass1.h macdefs.h $M/manifest.h pcclocal.h $M/config.h $M/ndu.h \
	/usr/include/stdio.h
P1ONEP=	$(P1INCS) $M/onepass.h
P2INCS=	$M/pass2.h macdefs.h mac2defs.h $M/manifest.h pcclocal.h $M/config.h \
	$M/ndu.h /usr/include/stdio.h
P2ONEP=	$(P2INCS) $M/onepass.h
D 15

E 15
I 15
OBJS=	code.o rel.o stab.o comm1.o match.o optim.o pftn.o \
	reader.o scan.o xdefs.o cgram.o rodata.o
DOBJS=	allo.o local.o local2.o order.o trees.o table.o
E 15
E 12
E 9
E 2
D 14
M=../mip
E 14
I 14
M=../../mip
E 14
I 9
TESTDIR = .

E 9
D 4
all: comp fort
E 4
I 4
D 5
# all: comp fort	not making f1 until f77 copy of sources is merged back
all: comp
E 5
I 5
D 7
all: comp fort
E 7
I 7
D 12
all: comp scomp fort
E 12
I 12
all: ccom sccom f1
E 12
I 9

#
D 12
# 'comp' is a one-pass C compiler.
E 12
I 12
# 'ccom' is a one-pass C compiler.
E 12
#
E 9
E 7
E 5
E 4
D 12
comp: rodata.o cgram.o xdefs.o scan.o pftn.o trees.o optim.o code.o local.o \
E 12
I 12
D 15
ccom: rodata.o cgram.o xdefs.o scan.o pftn.o trees.o optim.o code.o local.o \
E 12
D 2
	reader.o local2.o order.o match.o allo.o comm1.o table.o
E 2
I 2
	reader.o local2.o order.o match.o allo.o comm1.o table.o stab.o
E 2
D 10
	$(CC) $(LDFLAGS) -z rodata.o cgram.o xdefs.o scan.o pftn.o trees.o \
E 10
I 10
	$(CC) $(LDFLAGS) rodata.o cgram.o xdefs.o scan.o pftn.o trees.o \
E 10
		optim.o code.o local.o reader.o local2.o order.o match.o \
D 2
		allo.o comm1.o table.o -o $(TESTDIR)/comp
E 2
I 2
D 12
		allo.o comm1.o table.o stab.o -o $(TESTDIR)/comp
E 2
D 9
trees.o: $M/manifest macdefs $M/mfile1 $M/trees.c
E 9
I 9
trees.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/trees.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I.  $M/trees.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I.  $M/trees.c
E 10
D 9
optim.o: $M/manifest macdefs $M/mfile1 $M/optim.c
E 9
I 9
optim.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/optim.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/optim.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. $M/optim.c
E 10
D 9
pftn.o: $M/manifest macdefs $M/mfile1 $M/pftn.c
E 9
I 9
pftn.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/pftn.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/pftn.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. $M/pftn.c
E 10
D 9
code.o: $M/manifest macdefs $M/mfile1
E 9
I 9
code.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. code.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. code.c
E 10
D 9
local.o: $M/manifest macdefs $M/mfile1
E 9
I 9
local.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. local.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. local.c
E 10
D 9
scan.o: $M/manifest macdefs $M/mfile1 $M/scan.c
E 9
I 9
scan.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/scan.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/scan.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. $M/scan.c
E 10
D 9
xdefs.o: $M/manifest $M/mfile1 macdefs $M/xdefs.c
E 9
I 9
xdefs.o: $M/manifest.h $M/pass1.h pcclocal.h macdefs.h $M/xdefs.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/xdefs.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. $M/xdefs.c
E 10
D 9
cgram.o: $M/manifest $M/mfile1 macdefs cgram.c
E 9
I 9
cgram.o: $M/manifest.h $M/pass1.h pcclocal.h macdefs.h cgram.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. cgram.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. cgram.c
E 12
I 12
		allo.o comm1.o table.o stab.o -o $(TESTDIR)/ccom
E 15
I 15
ccom:	${OBJS} ${DOBJS} rel.o
	$(CC) $(LDFLAGS) ${OBJS} ${DOBJS} rel.o -o $(TESTDIR)/ccom
E 15
trees.o: $(P1ONEP) $M/trees.c
	$(CC) -c $(COPTS) $M/trees.c
optim.o: $(P1ONEP) $M/optim.c
	$(CC) -c $(COPTS) $M/optim.c
pftn.o: $(P1ONEP) $M/pftn.c
	$(CC) -c $(COPTS) $M/pftn.c
code.o: $(P1ONEP) code.c
	$(CC) -c $(COPTS) code.c
local.o: $(P1ONEP) local.c
	$(CC) -c $(COPTS) local.c
scan.o: $(P1ONEP) $M/scan.c
	$(CC) -c $(COPTS) $M/scan.c
xdefs.o: $(P1ONEP) $M/xdefs.c
	$(CC) -c $(COPTS) $M/xdefs.c
cgram.o: $(P1ONEP) cgram.c
	$(CC) -c $(COPTS) cgram.c
E 12
E 10
rodata.o: rodata.c
D 9
	$(CC) $(CFLAGS) -S rodata.c
D 2
	./:rofix rodata.s
E 2
I 2
	sh ./:rofix rodata.s
E 2
	$(AS) -o rodata.o rodata.s
	rm -f rodata.s
rodata.c cgram.c: $M/cgram.y
	$(YACC) $M/cgram.y
	rm -f rodata.c
E 9
I 9
D 10
	$(CC) -c $(CFLAGS) -R rodata.c
E 10
I 10
	$(CC) -c $(COPTS) -R rodata.c
E 10
rodata.c cgram.c: $M/cgram.y pcctokens
	cat pcctokens $M/cgram.y > gram.in
	$(YACC) gram.in
	$(RM) rodata.c
E 9
D 2
	./:yyfix yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 2
I 2
	sh ./:yyfix yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 2
	mv y.tab.c cgram.c
D 9
comm1.o: $M/manifest $M/mfile1 $M/common macdefs $M/comm1.c
	$(CC) -c $(CFLAGS) -I$M -I. $M/comm1.c
table.o: $M/manifest $M/mfile2 mac2defs macdefs table.c
	$(CC) $(CFLAGS) -S -I$M -I. table.c
D 2
	./:rofix table.s
E 2
I 2
	sh ./:rofix table.s
E 2
	$(AS) -o table.o table.s
	rm -f table.s
reader.o: $M/manifest $M/mfile2 mac2defs macdefs $M/reader.c
E 9
I 9
D 12
comm1.o: $M/manifest.h $M/pass1.h pcclocal.h $M/common.c macdefs.h
E 12
I 12
comm1.o: $(P1ONEP) $M/common.c
E 12
D 13
	ln $M/common.c comm1.c
E 13
I 13
	$(LN) $M/common.c comm1.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DPASS1COMMON comm1.c
E 10
I 10
D 12
	$(CC) -c $(COPTS) -I$M -I. -DPASS1COMMON comm1.c
E 12
I 12
	$(CC) -c $(COPTS) -DPASS1COMMON comm1.c
E 12
E 10
	$(RM) comm1.c
D 12
table.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h table.c
D 10
	$(CC) -c $(CFLAGS) -R -I$M -I. table.c
E 10
I 10
	$(CC) -c $(COPTS) -R -I$M -I. table.c
E 10
reader.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/reader.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/reader.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. $M/reader.c
E 10
D 9
local2.o: $M/manifest $M/mfile2 mac2defs macdefs
E 9
I 9
local2.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. local2.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. local2.c
E 10
D 9
order.o: $M/manifest $M/mfile2 mac2defs macdefs
E 9
I 9
order.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. order.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. order.c
E 10
D 9
match.o: $M/manifest $M/mfile2 mac2defs macdefs $M/match.c
E 9
I 9
match.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/match.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/match.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. $M/match.c
E 10
D 9
allo.o: $M/manifest $M/mfile2 mac2defs macdefs $M/allo.c
E 9
I 9
allo.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/allo.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/allo.c
E 10
I 10
	$(CC) -c $(COPTS) -I$M -I. $M/allo.c
E 12
I 12
stab.o: $(P1ONEP) stab.c \
	/usr/include/stab.h /usr/include/a.out.h /usr/include/sys/types.h
	$(CC) -c $(COPTS) stab.c
table.o: $(P2ONEP) table.c
	$(CC) -c $(COPTS) -R table.c
reader.o: $(P2ONEP) $M/reader.c
	$(CC) -c $(COPTS) $M/reader.c
local2.o: $(P2ONEP) local2.c
	$(CC) -c $(COPTS) local2.c
order.o: $(P2ONEP) order.c
	$(CC) -c $(COPTS) order.c
match.o: $(P2ONEP) $M/match.c
	$(CC) -c $(COPTS) $M/match.c
allo.o: $(P2ONEP) $M/allo.c
	$(CC) -c $(COPTS) $M/allo.c
E 12
E 10
I 9

#
D 12
# 'scomp' is a C compiler that does single precision computations in
E 12
I 12
# 'sccom' is a C compiler that does single precision computations in
E 12
#	single precision rather than double precision.
#
E 9
D 7
shrink:
	rm *.o comp
clean:
	rm -f *.o comp fort cgram.c rodata.c
lintall:
D 6
	lint -hpv -I. -I$M  $M/cgram.c $M/xdefs.c $M/scan.c $M/pftn.c \
		$M/trees.c $M/optim.c code.c local.c $M/reader \
E 6
I 6
	lint -hv -I. -I$M  cgram.c $M/xdefs.c $M/scan.c $M/pftn.c \
		$M/trees.c $M/optim.c code.c local.c $M/reader.c \
E 6
		local2.c order.c $M/match.c $M/allo.c $M/comm1.c table.c
E 7
I 7
D 12
scomp: rodata.o cgram.o xdefs.o scan.o pftn.o strees.o optim.o code.o slocal.o \
E 12
I 12
D 15
sccom: rodata.o cgram.o xdefs.o scan.o pftn.o strees.o optim.o code.o slocal.o \
E 12
	reader.o slocal2.o sorder.o match.o sallo.o comm1.o stable.o stab.o
D 10
	$(CC) $(LDFLAGS) -z rodata.o cgram.o xdefs.o scan.o pftn.o strees.o \
E 10
I 10
	$(CC) $(LDFLAGS) rodata.o cgram.o xdefs.o scan.o pftn.o strees.o \
E 10
		optim.o code.o slocal.o reader.o slocal2.o sorder.o match.o \
D 12
		sallo.o comm1.o stable.o stab.o -o $(TESTDIR)/scomp
D 9
strees.o: $M/manifest macdefs $M/mfile1 $M/trees.c
E 9
I 9
strees.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/trees.c
E 12
I 12
		sallo.o comm1.o stable.o stab.o -o $(TESTDIR)/sccom
E 15
I 15
sccom:	${OBJS} ${SOBJS} rel.o
	$(CC) $(LDFLAGS) ${OBJS} ${SOBJS} rel.o -o $(TESTDIR)/sccom
E 15
strees.o: $(P1ONEP) $M/trees.c
E 12
E 9
D 13
	ln $M/trees.c strees.c
E 13
I 13
	$(LN) $M/trees.c strees.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DSPRECC strees.c
E 10
I 10
D 12
	$(CC) -c $(SCOPTS) -I$M -I. strees.c
E 12
I 12
	$(CC) -c $(SCOPTS) strees.c
E 12
E 10
D 9
	rm strees.c
slocal.o: $M/manifest $M/mfile2 mac2defs macdefs local.c
E 9
I 9
	$(RM) strees.c
D 12
slocal.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h local.c
E 12
I 12
slocal.o: $(P1ONEP) local.c
E 12
E 9
D 13
	ln local.c slocal.c
E 13
I 13
	$(LN) local.c slocal.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DSPRECC slocal.c
E 10
I 10
D 12
	$(CC) -c $(SCOPTS) -I$M -I. slocal.c
E 12
I 12
	$(CC) -c $(SCOPTS) slocal.c
E 12
E 10
D 9
	rm slocal.c
slocal2.o: $M/manifest $M/mfile2 mac2defs macdefs local2.c
E 9
I 9
	$(RM) slocal.c
D 12
slocal2.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h local2.c
E 12
I 12
slocal2.o: $(P2ONEP) local2.c
E 12
E 9
D 13
	ln local2.c slocal2.c
E 13
I 13
	$(LN) local2.c slocal2.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DSPRECC slocal2.c
E 10
I 10
D 12
	$(CC) -c $(SCOPTS) -I$M -I. slocal2.c
E 12
I 12
	$(CC) -c $(SCOPTS) slocal2.c
E 12
E 10
D 9
	rm slocal2.c
sallo.o: $M/manifest $M/mfile2 mac2defs macdefs $M/allo.c
E 9
I 9
	$(RM) slocal2.c
D 12
sallo.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/allo.c
E 12
I 12
sallo.o: $(P2ONEP) $M/allo.c
E 12
E 9
D 13
	ln $M/allo.c sallo.c
E 13
I 13
	$(LN) $M/allo.c sallo.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DSPRECC sallo.c
E 10
I 10
D 12
	$(CC) -c $(SCOPTS) -I$M -I. sallo.c
E 12
I 12
	$(CC) -c $(SCOPTS) sallo.c
E 12
E 10
D 9
	rm sallo.c
sorder.o: $M/manifest $M/mfile2 mac2defs macdefs order.c
E 9
I 9
	$(RM) sallo.c
D 12
sorder.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h order.c
E 12
I 12
sorder.o: $(P2ONEP) order.c
E 12
E 9
D 13
	ln order.c sorder.c
E 13
I 13
	$(LN) order.c sorder.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DSPRECC sorder.c
E 10
I 10
D 12
	$(CC) -c $(SCOPTS) -I$M -I. sorder.c
E 12
I 12
	$(CC) -c $(SCOPTS) sorder.c
E 12
E 10
D 9
	rm sorder.c
stable.o: $M/manifest $M/mfile2 mac2defs macdefs table.c
	$(CC) $(CFLAGS) -S -I$M -I. -DSPRECC table.c
	sh ./:rofix table.s
	$(AS) -o stable.o table.s
	rm -f table.s
E 9
I 9
	$(RM) sorder.c
D 12
stable.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h table.c
E 12
I 12
stable.o: $(P2ONEP) table.c
E 12
D 13
	ln table.c stable.c
E 13
I 13
	$(LN) table.c stable.c
E 13
D 10
	$(CC) -c $(CFLAGS) -R -I$M -I. -DSPRECC stable.c
E 10
I 10
D 12
	$(CC) -c $(SCOPTS) -R -I$M -I. stable.c
E 12
I 12
	$(CC) -c $(SCOPTS) -R stable.c
E 12
E 10
	$(RM) stable.c

#
D 12
# 'fort' is the f77 and pc code generator.
E 12
I 12
# 'f1' is the f77 and pc code generator.
E 12
#
E 9
E 7
D 8
fort: comp fort.o freader.o fallo.o fmatch.o ftable.o forder.o flocal2.o \
E 8
I 8
D 12
fort: fort.o freader.o fallo.o fmatch.o ftable.o forder.o flocal2.o \
E 12
I 12
f1: fort.o freader.o fallo.o fmatch.o ftable.o forder.o flocal2.o \
E 12
E 8
	fcomm2.o
I 4
D 5
	@echo "f1 is usually made from sources in /usr/src/usr.lib/f77 ..."
E 5
E 4
D 10
	$(CC) -z $(CFLAGS) fort.o freader.o fallo.o fmatch.o ftable.o \
E 10
I 10
	$(CC) $(LDFLAGS) fort.o freader.o fallo.o fmatch.o ftable.o \
E 10
D 12
		forder.o flocal2.o fcomm2.o -o $(TESTDIR)/fort
D 9
fort.o: fort.h $M/fort.c
E 9
I 9
fort.o: fort.h $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/fort.c
E 9
D 10
	$(CC) -c $(CFLAGS) -I$M -I. $M/fort.c
E 10
I 10
	$(CC) -c $(FOPTS) -I$M -I. $M/fort.c
E 10
D 9
freader.o: reader.o
	$(CC) -c $(CFLAGS) -I$M -I. $M/freader.c
fallo.o: allo.o
	$(CC) -c $(CFLAGS) -I$M -I. $M/fallo.c
fmatch.o: match.o
	$(CC) -c $(CFLAGS) -I$M -I. $M/fmatch.c
ftable.o: table.o
	$(CC) -c -R $(CFLAGS) -I$M -I. $M/ftable.c
forder.o: order.o
	$(CC) -c $(CFLAGS) -I$M -I. $M/forder.c
flocal2.o: local2.o
	$(CC) -c $(CFLAGS) -I$M -I. $M/flocal2.c
fcomm2.o: $M/common
	$(CC) -c $(CFLAGS) -I$M -I. $M/fcomm2.c
fort.o freader.o fallo.o fmatch.o ftable.o forder.o flocal2.o fcomm2.o: \
	$M/mfile2 $M/manifest macdefs mac2defs
E 9
I 9
freader.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/reader.c
E 12
I 12
		forder.o flocal2.o fcomm2.o -o $(TESTDIR)/f1
fort.o: $(P2INCS) fort.h $M/fort.c
	$(CC) -c $(FOPTS) $M/fort.c
freader.o: $(P2INCS) $M/reader.c
E 12
D 13
	ln $M/reader.c freader.c
E 13
I 13
	$(LN) $M/reader.c freader.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DFORT -DNOMAIN freader.c
E 10
I 10
D 12
	$(CC) -c $(FOPTS) -I$M -I. freader.c
E 12
I 12
	$(CC) -c $(FOPTS) freader.c
E 12
E 10
	$(RM) freader.c
D 12
fallo.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/allo.c
E 12
I 12
fallo.o: $(P2INCS) $M/allo.c
E 12
D 13
	ln $M/allo.c fallo.c
E 13
I 13
	$(LN) $M/allo.c fallo.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DFORT fallo.c
E 10
I 10
D 12
	$(CC) -c $(FOPTS) -I$M -I. fallo.c
E 12
I 12
	$(CC) -c $(FOPTS) fallo.c
E 12
E 10
	$(RM) fallo.c
D 12
fmatch.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h $M/match.c
E 12
I 12
fmatch.o: $(P2INCS) $M/match.c
E 12
D 13
	ln $M/match.c fmatch.c
E 13
I 13
	$(LN) $M/match.c fmatch.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DFORT fmatch.c
E 10
I 10
D 12
	$(CC) -c $(FOPTS) -I$M -I. fmatch.c
E 12
I 12
	$(CC) -c $(FOPTS) fmatch.c
E 12
E 10
	$(RM) fmatch.c
D 12
ftable.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h table.c
E 12
I 12
ftable.o: $(P2INCS) table.c
E 12
D 13
	ln table.c ftable.c
E 13
I 13
	$(LN) table.c ftable.c
E 13
D 10
	$(CC) -c -R $(CFLAGS) -I$M -I. -DFORT ftable.c
E 10
I 10
D 12
	$(CC) -c -R $(FOPTS) -I$M -I. ftable.c
E 12
I 12
	$(CC) -c -R $(FOPTS) ftable.c
E 12
E 10
	$(RM) ftable.c
D 12
forder.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h
E 12
I 12
forder.o: $(P2INCS) order.c
E 12
D 13
	ln order.c forder.c
E 13
I 13
	$(LN) order.c forder.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DFORT forder.c
E 10
I 10
D 12
	$(CC) -c $(FOPTS) -I$M -I. forder.c
E 12
I 12
	$(CC) -c $(FOPTS) forder.c
E 12
E 10
	$(RM) forder.c
D 12
flocal2.o: $M/manifest.h $M/pass2.h pcclocal.h mac2defs.h macdefs.h
E 12
I 12
flocal2.o: $(P2INCS) local2.c
E 12
D 13
	ln local2.c flocal2.c
E 13
I 13
	$(LN) local2.c flocal2.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DFORT flocal2.c
E 10
I 10
D 12
	$(CC) -c $(FOPTS) -I$M -I. flocal2.c
E 12
I 12
	$(CC) -c $(FOPTS) flocal2.c
E 12
E 10
	$(RM) flocal2.c
D 12
fcomm2.o: $M/manifest.h $M/pass2.h pcclocal.h $M/common.c mac2defs.h macdefs.h
E 12
I 12
fcomm2.o: $(P2INCS) $M/common.c
E 12
D 13
	ln $M/common.c fcomm2.c
E 13
I 13
	$(LN) $M/common.c fcomm2.c
E 13
D 10
	$(CC) -c $(CFLAGS) -I$M -I. -DFORT -DPASS2COMMON fcomm2.c
E 10
I 10
D 12
	$(CC) -c $(FOPTS) -I$M -I. -DPASS2COMMON fcomm2.c
E 12
I 12
	$(CC) -c $(FOPTS) -DPASS2COMMON fcomm2.c
E 12
E 10
	$(RM) fcomm2.c

E 9
D 11
install:	all
D 7
	rm -f ${DESTDIR}/lib/ccom
	cp comp ${DESTDIR}/lib/ccom
D 4
	rm -f ${DESTDIR}/lib/f1
	cp fort ${DESTDIR}/lib/f1
E 4
I 4
D 5
#	rm -f ${DESTDIR}/lib/f1
#	cp fort ${DESTDIR}/lib/f1
E 5
I 5
	rm -f ${DESTDIR}/lib/f1
	cp fort ${DESTDIR}/lib/f1
E 7
I 7
	install comp ${DESTDIR}/lib/ccom
	install scomp ${DESTDIR}/lib/sccom
	install fort ${DESTDIR}/lib/f1
E 11
I 11
install: all
D 12
	install -s comp ${DESTDIR}/lib/ccom
	install -s scomp ${DESTDIR}/lib/sccom
	install -s fort ${DESTDIR}/lib/f1
E 12
I 12
D 17
	install -s ${TESTDIR}/ccom ${DESTDIR}/lib/ccom
	install -s ${TESTDIR}/sccom ${DESTDIR}/lib/sccom
	install -s ${TESTDIR}/f1 ${DESTDIR}/lib/f1
E 17
I 17
	install -s -o bin -g bin -m 755 ${TESTDIR}/ccom ${DESTDIR}/lib/ccom
	install -s -o bin -g bin -m 755 ${TESTDIR}/sccom ${DESTDIR}/lib/sccom
	install -s -o bin -g bin -m 755 ${TESTDIR}/f1 ${DESTDIR}/lib/f1
E 17
E 12
E 11
I 9

GREP=	egrep

D 18
pcclocal.h: localdefs.h /usr/include/pcc.h
E 18
I 18
pcclocal.h: ../localdefs.h /usr/include/pcc.h
E 18
	$(RM) pcclocal.h
D 18
	cat /usr/include/pcc.h localdefs.h | $(GREP) '^#[ 	]*(define[ 	][ 	]*PCC(F|T|TM|OM)?_|ifdef|ifndef|endif)' | sed -e 's/PCC[A-Z]*_//' > pcclocal.h 
E 18
I 18
	cat /usr/include/pcc.h ../localdefs.h | $(GREP) '^#[ 	]*(define[ 	][ 	]*PCC(F|T|TM|OM)?_|ifdef|ifndef|endif)' | sed -e 's/PCC[A-Z]*_//' > pcclocal.h 
E 18

D 18
pcctokens: localdefs.h /usr/include/pcc.h
E 18
I 18
pcctokens: ../localdefs.h /usr/include/pcc.h
E 18
	$(RM) pcctokens
D 18
	cat /usr/include/pcc.h localdefs.h | $(GREP) '^#[ 	]*define[ 	][ 	]*PCC_' | sed -e 's/^#[ 	]*define[ 	][ 	]*PCC_/%term	/' > pcctokens
E 18
I 18
	cat /usr/include/pcc.h ../localdefs.h | $(GREP) '^#[ 	]*define[ 	][ 	]*PCC_' | sed -e 's/^#[ 	]*define[ 	][ 	]*PCC_/%term	/' > pcctokens
E 18

DUMMIES=	$(SFILES) $(FFILES)

E 9
shrink:
D 9
	rm *.o comp scomp fort
E 9
I 9
D 12
	$(RM) *.o comp scomp fort $(DUMMIES)
E 12
I 12
	$(RM) *.o ccom sccom f1 $(DUMMIES)
E 12
E 9
clean:
D 9
	rm -f *.o comp fort cgram.c rodata.c
E 9
I 9
D 12
	$(RM) *.o comp scomp fort cgram.c rodata.c pcctokens pcclocal.h gram.in $(DUMMIES)
E 12
I 12
	$(RM) *.o ccom sccom f1 cgram.c rodata.c pcctokens pcclocal.h gram.in $(DUMMIES)
E 12
sfix:
	$(RM) $(SFILES)
sclean:
	$(RM) $(SOBJS) $(SFILES)
ffix:
	$(RM) $(FFILES)
fclean:
	$(RM) $(FOBJS) $(FFILES)

I 18
# Should use -a, but the situation is too confusing to fix at the moment...
E 18
E 9
lintall:
D 12
	lint -hv -I. -I$M  cgram.c $M/xdefs.c $M/scan.c $M/pftn.c \
		$M/trees.c $M/optim.c code.c local.c $M/reader.c \
E 12
I 12
D 18
	lint -hax -I. -I$M  cgram.c $M/xdefs.c $M/scan.c $M/pftn.c \
		$M/trees.c $M/optim.c code.c local.c stab.c $M/reader.c \
E 12
		local2.c order.c $M/match.c $M/allo.c $M/comm1.c table.c
E 18
I 18
	lint -hx $(COPTS) -DPASS1COMMON cgram.c $M/xdefs.c $M/scan.c \
		$M/pftn.c $M/trees.c $M/optim.c code.c local.c stab.c \
		$M/reader.c local2.c order.c $M/match.c $M/allo.c \
		$M/common.c table.c rodata.c rel.c
E 18
I 17

depend:
tags:
E 17
E 7
E 5
E 4
E 1
