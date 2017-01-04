h29585
s 00002/00002/00119
d D 1.21 88/05/22 12:53:16 bostic 25 24
c use relative paths, not absolute
e
s 00001/00004/00120
d D 1.20 87/12/11 19:55:33 donn 24 22
c localdefs.h was moved upstairs; give lint its own release file.
e
s 00000/00000/00124
d R 1.20 87/12/11 19:54:21 donn 23 22
c localdefs.h was moved upstairs; give lint its own release file.
e
s 00004/00004/00120
d D 1.19 87/11/05 11:35:01 bostic 22 21
c group bin, not src
e
s 00004/00001/00120
d D 1.18 87/09/28 16:24:18 bostic 21 20
c hash.c has to find config.h; bug report 4.3BSD/usr.bin/83
e
s 00007/00009/00114
d D 1.17 87/07/01 10:58:56 bostic 20 17
c added depend label, fixed install
e
s 00093/00084/00041
d R 1.18 87/06/18 20:40:53 bostic 19 18
c new template
e
s 00002/00000/00123
d R 1.17 87/05/31 21:30:28 bostic 18 17
c added depend label
e
s 00001/00001/00122
d D 1.16 87/04/22 15:50:19 bostic 17 16
c bug report 4.3BSD/usr.bin/55
e
s 00002/00002/00121
d D 1.15 86/11/15 11:11:02 sam 16 15
c pcc moved again
e
s 00011/00004/00112
d D 1.14 86/10/19 23:14:07 sam 15 14
c update for pcc dir move; add rel.c reference; use symbolic link to comm1.c
e
s 00005/00005/00111
d D 1.13 86/03/29 13:22:57 donn 14 13
c Don't use -p when making libraries other than 'port' since some of them
c are NOT portable (case-sensitivity).
e
s 00012/00006/00104
d D 1.12 86/03/20 18:10:15 donn 13 11
c Use relative symlinks for llib-termlib; load with ${CFLAGS} so that we pass
c on -g; add 'tags' dependency.
e
s 00011/00005/00105
d R 1.12 86/03/20 18:01:40 donn 12 11
c Use relative symlinks for termlib; use CFLAGS when linking for -g;
c add 'tags' dependency to help out with horrible tag construction problems.
e
s 00014/00001/00096
d D 1.11 86/03/14 19:16:38 donn 11 10
c Add entries for -ldbm, -lplot, -ltermcap, -ltermlib.
e
s 00001/00001/00096
d D 1.10 86/01/11 20:03:57 lepreau 10 9
c clean better
e
s 00044/00026/00053
d D 1.9 85/04/08 11:45:45 ralph 9 8
c changes due to pcc restructuring for common header files.
e
s 00004/00001/00075
d D 1.8 83/07/02 23:25:08 root 8 7
c add curses (sam)
e
s 00001/00001/00075
d D 1.7 83/06/30 14:08:24 sam 7 6
c from sun
e
s 00046/00028/00030
d D 1.6 83/04/01 00:03:53 sam 6 5
c from sun
e
s 00005/00004/00053
d D 1.5 83/03/29 11:49:50 edward 5 4
c Added module hash.c for hash function common to both passes
e
s 00002/00002/00055
d D 1.4 82/10/20 00:14:04 mckusick 4 3
c use -f in rm
e
s 00007/00006/00050
d D 1.3 82/10/11 17:09:18 rrh 3 2
c Changed to use install, instead of cp
e
s 00007/00002/00049
d D 1.2 82/08/30 13:38:58 rrh 2 1
c Augmentations to get files out of sccs
e
s 00051/00000/00000
d D 1.1 82/08/30 13:15:51 rrh 1 0
c date and time created 82/08/30 13:15:51 by rrh
e
u
U
t
T
I 1
D 3

E 3
#
#	%W%	(Berkeley)	%G%
#
D 2
M=../mip
E 2
I 2
D 25
M=/usr/src/lib/mip
E 2
D 3
LOAD1=-s
LOAD2=-s
E 3
I 3
D 6
#LOAD1=-s
#LOAD2=-s
E 6
D 9
LOAD1=
LOAD2=
E 3
CFLAGS=-O -DFLEXNAMES
E 9
I 9
D 15
P=/usr/src/lib/pcc
E 15
I 15
D 20
#ifdef vax
D 16
#P=/usr/src/lib/pcc.vax
E 16
I 16
#P=/usr/src/lib/pcc/pcc.vax
E 16
#else
D 16
P=/usr/src/lib/pcc.tahoe
E 16
I 16
P=/usr/src/lib/pcc/pcc.tahoe
E 16
#endif
E 20
I 20
D 24
P=/usr/src/lib/pcc/pcc.${MACHINE}
E 24
I 24
P=/usr/src/lib/pcc
E 25
I 25
M=../../lib/mip
P=../../lib/pcc
E 25
E 24
E 20
E 15
CFLAGS=-O
E 9
D 6
head: lpass1 lpass2 llib-port.ln llib-lc.ln;
E 6
I 6
D 8
LINTLIBS=llib-port.ln llib-lc.ln llib-lm.ln llib-lmp.ln
E 8
I 8
D 11
LINTLIBS=llib-port.ln llib-lc.ln llib-lm.ln llib-lmp.ln llib-lcurses.ln
E 11
I 11
LINTLIBS=llib-port.ln llib-lc.ln llib-lcurses.ln llib-ldbm.ln llib-lm.ln \
	llib-lmp.ln llib-lplot.ln llib-ltermcap.ln
I 13
SRCS=	$M/cgram.y $M/common.c $M/optim.c $M/pftn.c $M/scan.c $M/trees.c \
	$M/xdefs.c lint.c hash.c $M/pass1.h $M/manifest.h macdefs.h \
	lpass2.c
E 13
E 11
E 8

all:	lpass1 lpass2 ${LINTLIBS}

E 6
D 5
lpass1: cgram.o xdefs.o scan.o comm1.o pftn.o trees.o optim.o lint.o
	cc $(LOAD1) cgram.o xdefs.o scan.o comm1.o pftn.o trees.o optim.o lint.o
E 5
I 5
D 9
lpass1: cgram.o xdefs.o scan.o comm1.o pftn.o trees.o optim.o lint.o hash.o
D 6
	cc $(LOAD1) cgram.o xdefs.o scan.o comm1.o pftn.o trees.o optim.o \
		lint.o hash.o
E 5
	mv a.out lpass1
E 6
I 6
	${CC} cgram.o xdefs.o scan.o comm1.o pftn.o trees.o optim.o \
E 9
I 9
lpass1: cgram.o rodata.o comm1.o optim.o pftn.o scan.o trees.o xdefs.o \
D 15
	lint.o hash.o
E 15
I 15
	lint.o hash.o rel.o
E 15
D 13
	${CC} cgram.o rodata.o comm1.o optim.o pftn.o scan.o trees.o xdefs.o \
E 9
		lint.o hash.o -o lpass1
E 13
I 13
	${CC} ${CFLAGS} cgram.o rodata.o comm1.o optim.o pftn.o scan.o \
D 15
		trees.o xdefs.o lint.o hash.o -o lpass1
E 15
I 15
		trees.o xdefs.o lint.o hash.o rel.o -o lpass1
E 15
E 13

E 6
D 9
trees.o: $M/manifest macdefs $M/mfile1 $M/trees.c
D 6
	cc -c $(CFLAGS) -I$M -I. $M/trees.c
E 6
I 6
	${CC} -c ${CFLAGS} -I$M -I. $M/trees.c
E 9
I 9
cgram.o: $M/manifest.h $M/pass1.h pcclocal.h macdefs.h cgram.c
	$(CC) -c $(CFLAGS) -I$M -I. cgram.c
E 9

E 6
D 9
optim.o: $M/manifest macdefs $M/mfile1 $M/optim.c
D 6
	cc -c $(CFLAGS) -I$M -I. $M/optim.c
E 6
I 6
	${CC} -c ${CFLAGS} -I$M -I. $M/optim.c
E 9
I 9
rodata.o: rodata.c
	$(CC) -c $(CFLAGS) -R rodata.c
E 9

E 6
D 9
pftn.o: $M/manifest macdefs $M/mfile1 $M/pftn.c
D 6
	cc -c $(CFLAGS) -I$M -I. $M/pftn.c
E 6
I 6
	${CC} -c ${CFLAGS} -I$M -I. $M/pftn.c
E 9
I 9
comm1.o: $M/manifest.h $M/pass1.h pcclocal.h $M/common.c macdefs.h
D 15
	ln $M/common.c comm1.c
E 15
I 15
	ln -s $M/common.c comm1.c
E 15
	$(CC) -c $(CFLAGS) -I$M -I. -DPASS1COMMON comm1.c
	rm -f comm1.c
E 9

E 6
D 9
lint.o: $M/manifest macdefs $M/mfile1 lmanifest
D 6
	cc -c $(CFLAGS) -I$M -I. lint.c
E 6
I 6
	${CC} -c ${CFLAGS} -I$M -I. lint.c
E 9
I 9
optim.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/optim.c
	$(CC) -c $(CFLAGS) -I$M -I. $M/optim.c
E 9

E 6
D 9
scan.o: $M/manifest macdefs $M/mfile1 $M/scan.c
D 6
	cc -c $(CFLAGS) -I$M -I. $M/scan.c
E 6
I 6
	${CC} -c ${CFLAGS} -I$M -I. $M/scan.c
E 9
I 9
pftn.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/pftn.c
	$(CC) -c $(CFLAGS) -I$M -I. $M/pftn.c
E 9

E 6
D 9
xdefs.o: $M/manifest $M/mfile1 macdefs $M/xdefs.c
D 6
	cc -c $(CFLAGS) -I$M -I. $M/xdefs.c
E 6
I 6
	${CC} -c ${CFLAGS} -I$M -I. $M/xdefs.c
E 9
I 9
scan.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/scan.c
	$(CC) -c $(CFLAGS) -I$M -I. $M/scan.c
E 9

E 6
D 9
cgram.o: $M/manifest $M/mfile1 macdefs cgram.c
D 6
	cc -c $(CFLAGS) -I$M -I. cgram.c
E 6
I 6
	${CC} -c ${CFLAGS} -I$M -I. cgram.c
E 9
I 9
trees.o: $M/manifest.h macdefs.h $M/pass1.h pcclocal.h $M/trees.c
	$(CC) -c $(CFLAGS) -I$M -I. $M/trees.c
E 9

E 6
D 9
cgram.c: $M/cgram.y
	yacc $M/cgram.y
E 9
I 9
xdefs.o: $M/manifest.h $M/pass1.h pcclocal.h macdefs.h $M/xdefs.c
	$(CC) -c $(CFLAGS) -I$M -I. $M/xdefs.c
I 15
D 24

rel.o:	$P/rel.c
	${CC} -c ${CFLAGS} $P/rel.c
E 24
E 15

rodata.c cgram.c: $M/cgram.y pcctokens
	cat pcctokens $M/cgram.y > gram.in
	$(YACC) gram.in
	rm -f rodata.c
	sh ./:yyfix yyexca yyact yypact yypgo yyr1 yyr2 yychk yydef
E 9
	mv y.tab.c cgram.c
I 6

E 6
D 9
comm1.o: $M/manifest $M/mfile1 $M/common macdefs $M/comm1.c
D 6
	cc -c $(CFLAGS) -I. -I$M $M/comm1.c
E 6
I 6
	${CC} -c ${CFLAGS} -I. -I$M $M/comm1.c
E 9
I 9
GREP=	egrep
E 9

I 9
pcclocal.h: $P/localdefs.h /usr/include/pcc.h
	rm -f pcclocal.h
	cat /usr/include/pcc.h $P/localdefs.h | $(GREP) '^#[ 	]*(define[ 	][ 	]*PCC(F|T|TM|OM)?_|ifdef|ifndef|endif)' | sed -e 's/PCC[A-Z]*_//' > pcclocal.h 

pcctokens: $P/localdefs.h /usr/include/pcc.h
	rm -f pcctokens
	cat /usr/include/pcc.h $P/localdefs.h | $(GREP) '^#[ 	]*define[ 	][ 	]*PCC_' | sed -e 's/^#[ 	]*define[ 	][ 	]*PCC_/%term	/' > pcctokens

lint.o: $M/manifest.h macdefs.h $M/pass1.h lmanifest.h
	${CC} -c ${CFLAGS} -I$M -I. lint.c

E 9
E 6
llib-port.ln: llib-port lpass1
	-(/lib/cpp -C -Dlint llib-port | ./lpass1 -puv > llib-port.ln )
I 6

I 11
llib-ldbm.ln: llib-ldbm lpass1
D 14
	-(/lib/cpp -C -Dlint llib-ldbm | ./lpass1 -puv > llib-ldbm.ln )
E 14
I 14
	-(/lib/cpp -C -Dlint llib-ldbm | ./lpass1 -uv > llib-ldbm.ln )
E 14

E 11
llib-lm.ln: llib-lm lpass1
D 14
	-(/lib/cpp -C -Dlint llib-lm | ./lpass1 -puv > llib-lm.ln )
E 14
I 14
	-(/lib/cpp -C -Dlint llib-lm | ./lpass1 -uv > llib-lm.ln )
E 14

llib-lmp.ln: llib-lmp lpass1
D 14
	-(/lib/cpp -C -Dlint llib-lmp | ./lpass1 -puv > llib-lmp.ln )
E 14
I 14
	-(/lib/cpp -C -Dlint llib-lmp | ./lpass1 -uv > llib-lmp.ln )
E 14

I 11
llib-lplot.ln: llib-lplot lpass1
D 14
	-(/lib/cpp -C -Dlint llib-lplot | ./lpass1 -puv > llib-lplot.ln )
E 14
I 14
	-(/lib/cpp -C -Dlint llib-lplot | ./lpass1 -uv > llib-lplot.ln )
E 14

llib-ltermcap.ln: llib-ltermcap lpass1
D 14
	-(/lib/cpp -C -Dlint llib-ltermcap | ./lpass1 -puv > llib-ltermcap.ln )
E 14
I 14
	-(/lib/cpp -C -Dlint llib-ltermcap | ./lpass1 -uv > llib-ltermcap.ln )
E 14

E 11
E 6
llib-lc.ln: llib-lc lpass1
	-(/lib/cpp -C -Dlint llib-lc | ./lpass1 -v > llib-lc.ln )
I 8

llib-lcurses.ln: llib-lcurses lpass1
D 17
	-(/lib/cpp -C -Dlint llib-lcurses | ./lpass1 -v > llib-lcurses.ln )
E 17
I 17
	-(/lib/cpp -C -Dlint -D__void__=__curses__ llib-lcurses | ./lpass1 -v > llib-lcurses.ln )
E 17
E 8
D 6
shrink:
D 4
	rm *.o
E 4
I 4
	rm -f *.o
E 4
clean: shrink
D 4
	rm lpass1 lpass2 cgram.c llib-lc.ln llib-port.ln
E 4
I 4
	rm -f lpass1 lpass2 cgram.c llib-lc.ln llib-port.ln
E 6
I 6

E 6
E 4
D 5
lpass2: lpass2.o
	cc $(LOAD2) lpass2.o
E 5
I 5
lpass2: lpass2.o hash.o
D 6
	cc $(LOAD2) lpass2.o hash.o
E 5
	mv a.out lpass2
E 6
I 6
D 13
	${CC} lpass2.o hash.o -o lpass2
E 13
I 13
	${CC} ${CFLAGS} lpass2.o hash.o -o lpass2
E 13

E 6
D 9
lpass2.o: $M/manifest lmanifest
E 9
I 9
lpass2.o: $M/manifest.h lmanifest.h pcclocal.h macdefs.h
E 9
D 6
	cc $(CFLAGS) -c -I$M -I. lpass2.c
E 6
I 6
	${CC} ${CFLAGS} -c -I$M -I. lpass2.c
D 21
	
E 21
I 21

hash.o: hash.c
	${CC} ${CFLAGS} -c -I$M -I. hash.c

E 21
E 6
lintall:
D 6
	lint -hpv -I. -I$M  $M/cgram.c $M/xdefs.c $M/scan.c $M/pftn.c $M/trees.c $M/optim.c lint.c
D 2
install: head
E 2
I 2
install: head SHELL
E 2
D 3
	cp lpass1 ${DESTDIR}/usr/lib/lint/lint1
	cp lpass2 ${DESTDIR}/usr/lib/lint/lint2
E 3
I 3
	install -s lpass1 $(DESTDIR)/usr/lib/lint/lint1
	install -s lpass2 $(DESTDIR)/usr/lib/lint/lint2
E 6
I 6
	lint -hpv -I. -I$M  $M/cgram.c $M/xdefs.c $M/scan.c \
		$M/pftn.c $M/trees.c $M/optim.c lint.c

install: all SHELL
D 20
	install -s lpass1 ${DESTDIR}/usr/lib/lint/lint1
	install -s lpass2 ${DESTDIR}/usr/lib/lint/lint2
E 6
E 3
D 7
	cp llib-* ${DESTDIR}/usr/lib/lint
E 7
I 7
	for i in llib-*; do install -c -m 644 $$i ${DESTDIR}/usr/lib/lint; done
E 20
I 20
D 22
	install -s -o bin -g src -m 755 lpass1 ${DESTDIR}/usr/lib/lint/lint1
	install -s -o bin -g src -m 755 lpass2 ${DESTDIR}/usr/lib/lint/lint2
	for i in llib-*; do install -c -o bin -g src -m 644 $$i ${DESTDIR}/usr/lib/lint; done
E 22
I 22
	install -s -o bin -g bin -m 755 lpass1 ${DESTDIR}/usr/lib/lint/lint1
	install -s -o bin -g bin -m 755 lpass2 ${DESTDIR}/usr/lib/lint/lint2
	for i in llib-*; do install -c -o bin -g bin -m 644 $$i ${DESTDIR}/usr/lib/lint; done
E 22
E 20
I 11
	-rm -f ${DESTDIR}/usr/lib/lint/llib-ltermlib*
D 13
	ln -s /usr/lib/lint/llib-ltermcap ${DESTDIR}/usr/lib/lint/llib-ltermlib
	ln -s /usr/lib/lint/llib-ltermcap.ln ${DESTDIR}/usr/lib/lint/llib-ltermlib.ln
E 13
I 13
	ln -s llib-ltermcap ${DESTDIR}/usr/lib/lint/llib-ltermlib
	ln -s llib-ltermcap.ln ${DESTDIR}/usr/lib/lint/llib-ltermlib.ln
E 13
E 11
E 7
D 3
	cp SHELL ${DESTDIR}/usr/bin/lint
E 3
I 3
D 20
	install -c SHELL ${DESTDIR}/usr/bin/lint
E 20
I 20
D 22
	install -c -o bin -g src -m 755 SHELL ${DESTDIR}/usr/bin/lint
E 22
I 22
	install -c -o bin -g bin -m 755 SHELL ${DESTDIR}/usr/bin/lint
E 22
E 20
E 3
I 2

D 6
sources: READ_ME SHELL lint.c llib-lc llib-port lmanifest lpass2.c macdefs
E 6
I 6
shrink:
D 9
	rm -f *.o
E 9
I 9
D 10
	rm -f *.o errs
E 10
I 10
	rm -f *.o errs rodata.c pcctokens pcclocal.h
E 10
E 9
E 6

D 6
READ_ME SHELL lint.c llib-lc llib-port lmanifest lpass2.c macdefs:
	sccs get $@
E 6
I 6
clean: shrink
D 9
	rm -f lpass1 lpass2 cgram.c ${LINTLIBS}
E 9
I 9
D 13
	rm -f lpass1 lpass2 cgram.c gram.in ${LINTLIBS}
E 13
I 13
	rm -f lpass1 lpass2 cgram.c gram.in tags ${LINTLIBS}

tags:	${SRCS}
	ctags -w ${SRCS}
I 20

depend:
E 20
E 13
E 9
E 6
E 2
E 1
