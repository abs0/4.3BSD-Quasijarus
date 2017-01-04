h47064
s 00001/00001/00133
d D 4.8 2011/07/13 06:36:20 msokolov 8 7
c the new date_ab() implementation uses libctsl
e
s 00001/00001/00133
d D 4.7 01/05/27 20:47:32 msokolov 7 6
c help => sccshelp
e
s 00027/00019/00107
d D 4.6 99/01/07 02:07:53 msokolov 6 5
c SCCS is not "local" any more. /usr/local => /usr/bin
c fix makefile so that stree and cmt get built and installed
e
s 00000/00001/00126
d D 4.5 87/02/15 22:54:02 lepreau 5 4
c rmdel is already linked
e
s 00028/00028/00099
d D 4.4 85/05/04 00:34:57 sam 4 3
c purge some of the old grotty local routines; for get add %Q% for man pages
e
s 00001/00001/00126
d D 4.3 83/12/22 14:07:51 ralph 3 2
c turn on delta logging.
e
s 00074/00122/00053
d D 4.2 83/12/22 10:16:57 ralph 2 1
c putting makefile under sccs
e
s 00175/00000/00000
d D 4.1 83/12/22 10:15:02 ralph 1 0
c date and time created 83/12/22 10:15:02 by ralph
e
u
U
t
T
I 1
D 2
#	 This is the description file used by the make(I) command
#	 to reconstruct all or part of SCCS
E 2
I 2
#	%M%	%I%	%E%
#
CFLAGS=	-O -w
D 8
LIBS=	../libpw.a ../libPW.a ../libwrt.a
E 8
I 8
LIBS=	../libpw.a ../libPW.a ../libwrt.a -lctsl
E 8
E 2

D 2
#	(All Macro Definitions are described on line following definition)
E 2
I 2
all:	admin bdiff chghist comb delta get help prt rmdel sccsdiff.sh \
D 6
	what val snull cmt prs
E 6
I 6
	what val snull cmt prs stree
E 6
E 2

D 2
GET = get 
#	SCCS command get(I)
REL =
#	Null string used to specify release to get in make(I) command line
CFLAGS = -O
#	Flags used by C compiler
LDFLAGS =
#	Load flags used by C compiler
LIBES = -lpw -lPW -lwrt
#	Libraries used during loading

SCCS:		admin bdiff chghist comb scv \
	delta get help prt rmdel sccsdiff \
	what val snull vc cmt

E 2
D 4
admin:	admin.o ../com/comobj.a ctime.o alloc.o
D 2
	$(CC) $(LDFLAGS) -o admin admin.o ../com/comobj.a $(LIBES)
E 2
I 2
	$(CC) -o admin admin.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
admin:	admin.o ../com/comobj.a alloc.o
	$(CC) -o admin admin.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

admin.o:	admin.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) admin.c
E 2
I 2
	$(CC) -c $(CFLAGS) admin.c
E 2

D 2
admin.c:	s.admin.c
	$(GET) $(REL) s.admin.c
E 2
I 2
D 4
cmt:	cmt.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o cmt cmt.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
cmt:	cmt.o ../com/comobj.a alloc.o
	$(CC) -o cmt cmt.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
cmt:	cmt.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o cmt cmt.o ../com/comobj.a $(LIBES)

E 2
cmt.o:	cmt.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) cmt.c
E 2
I 2
	$(CC) -c $(CFLAGS) cmt.c
E 2

D 2
cmt.c:		s.cmt.c
	$(GET) $(REL) s.cmt.c
E 2
I 2
D 4
bdiff:	bdiff.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o bdiff bdiff.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
bdiff:	bdiff.o ../com/comobj.a alloc.o
	$(CC) -o bdiff bdiff.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
bdiff:	bdiff.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o bdiff bdiff.o ../com/comobj.a $(LIBES)

E 2
bdiff.o:	bdiff.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) bdiff.c
E 2
I 2
	$(CC) -c $(CFLAGS) bdiff.c
E 2

D 2
bdiff.c:	s.bdiff.c
	$(GET) $(REL) s.bdiff.c
E 2
I 2
D 4
comb:	comb.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o comb comb.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
comb:	comb.o ../com/comobj.a alloc.o
	$(CC) -o comb comb.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
comb:	comb.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o comb comb.o ../com/comobj.a $(LIBES)

E 2
comb.o:		comb.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) comb.c
E 2
I 2
	$(CC) -c $(CFLAGS) comb.c
E 2

D 2
comb.c:		s.comb.c
	$(GET) $(REL) s.comb.c
E 2
I 2
D 4
scv:	scv.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o scv scv.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
scv:	scv.o ../com/comobj.a alloc.o
	$(CC) -o scv scv.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
scv:	scv.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o scv scv.o ../com/comobj.a $(LIBES)

E 2
scv.o:		scv.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) scv.c
E 2
I 2
	$(CC) -c $(CFLAGS) scv.c
E 2

D 2
scv.c:		s.scv.c
	$(GET) $(REL) s.scv.c
E 2
I 2
D 4
snull:	snull.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o snull snull.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
snull:	snull.o ../com/comobj.a alloc.o
	$(CC) -o snull snull.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
snull:	snull.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o snull snull.o ../com/comobj.a $(LIBES)

E 2
snull.o:		snull.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) snull.c
E 2
I 2
	$(CC) -c $(CFLAGS) snull.c
E 2

I 6
stree:	stree.o ../com/comobj.a alloc.o
	$(CC) -o stree stree.o ../com/comobj.a $(LIBS) alloc.o

stree.o:		stree.c ../hdr/defines.h ../hdr/had.h
	$(CC) -c $(CFLAGS) stree.c

E 6
D 2
snull.c:		s.snull.c
	$(GET) $(REL) s.snull.c
E 2
I 2
D 4
delta:	delta.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o delta delta.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
delta:	delta.o ../com/comobj.a alloc.o
	$(CC) -o delta delta.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
delta:	delta.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o delta delta.o ../com/comobj.a $(LIBES) ctime.o alloc.o

E 2
delta.o:	delta.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) delta.c
E 2
I 2
D 3
	$(CC) -c $(CFLAGS) delta.c
E 3
I 3
	$(CC) -c $(CFLAGS) -DLOGDELTA delta.c
E 3
E 2

D 2
delta.c:	s.delta.c
	$(GET) $(REL) s.delta.c
E 2
I 2
D 4
get:	get.o ../com/comobj.a ctime.o alloc.o
	$(CC) -y_getwd -o get get.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
get:	get.o ../com/comobj.a alloc.o
	$(CC) -o get get.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
get:	get.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o get get.o ../com/comobj.a $(LIBES) ctime.o alloc.o

E 2
get.o:		get.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) get.c
E 2
I 2
	$(CC) -c $(CFLAGS) get.c
E 2

D 2
get.c:		s.get.c
	$(GET) $(REL) s.get.c
E 2
I 2
D 4
help:	help.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o help help.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
help:	help.o ../com/comobj.a alloc.o
	$(CC) -o help help.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
help:	help.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o help help.o ../com/comobj.a $(LIBES)

E 2
help.o:		help.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) help.c
E 2
I 2
	$(CC) -c $(CFLAGS) help.c
E 2

D 2
help.c:		s.help.c
	$(GET) $(REL) s.help.c
E 2
I 2
D 4
prt:	prt.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o prt prt.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
prt:	prt.o ../com/comobj.a alloc.o
	$(CC) -o prt prt.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

D 2
prt:	prt.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o prt prt.o ../com/comobj.a $(LIBES) ctime.o alloc.o

E 2
prt.o:		prt.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) prt.c
E 2
I 2
	$(CC) -c $(CFLAGS) prt.c
E 2

D 2
prt.c:		s.prt.c
	$(GET) $(REL) s.prt.c
E 2
I 2
D 4
prs:	prs.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o prs prs.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
prs:	prs.o ../com/comobj.a alloc.o
	$(CC) -o prs prs.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

I 2
prs.o:		prs.c ../hdr/defines.h ../hdr/had.h
	$(CC) -c $(CFLAGS) prs.c

E 2
chghist:	rmchg
	-rm -f chghist
	ln rmchg chghist

rmdel:	rmchg
	-rm -f rmdel
	ln rmchg rmdel

D 2
rmchg:	rmchg.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o rmchg rmchg.o ../com/comobj.a $(LIBES)
E 2
I 2
D 4
rmchg:	rmchg.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o rmchg rmchg.o ../com/comobj.a $(LIBS) ctime.o alloc.o
E 4
I 4
rmchg:	rmchg.o ../com/comobj.a alloc.o
	$(CC) -o rmchg rmchg.o ../com/comobj.a $(LIBS) alloc.o
E 4
E 2

rmchg.o:	rmchg.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) rmchg.c
E 2
I 2
	$(CC) -c $(CFLAGS) rmchg.c
E 2

D 2
rmchg.c:		s.rmchg.c
	$(GET) $(REL) s.rmchg.c
E 2
I 2
D 4
what:	what.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o what what.o ../com/comobj.a $(LIBS) $(LIBES) ctime.o alloc.o
E 4
I 4
what:	what.o ../com/comobj.a alloc.o
	$(CC) -o what what.o ../com/comobj.a $(LIBS) $(LIBES) alloc.o
E 4
E 2

D 2
sccsdiff:	s.sccsdiff
		$(GET) $(REL) s.sccsdiff; chmod 555 sccsdiff

what:	what.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o what what.o ../com/comobj.a $(LIBES) $(LIBES) ctime.o alloc.o

E 2
what.o:		what.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) what.c
E 2
I 2
	$(CC) -c $(CFLAGS) what.c
E 2

D 2
what.c:		s.what.c
	$(GET) $(REL) s.what.c
E 2
I 2
D 4
val:	val.o ../com/comobj.a ctime.o alloc.o
	$(CC) -o val val.o ../com/comobj.a $(LIBS) $(LIBES) ctime.o alloc.o
E 4
I 4
val:	val.o ../com/comobj.a alloc.o
	$(CC) -o val val.o ../com/comobj.a $(LIBS) $(LIBES) alloc.o
E 4
E 2

D 2
val:	val.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o val val.o ../com/comobj.a $(LIBES) $(LIBES)

E 2
val.o:	val.c ../hdr/defines.h ../hdr/had.h
D 2
	$(CC) $(CFLAGS) val.c
E 2
I 2
	$(CC) -c $(CFLAGS) val.c
E 2

D 2
val.c:		s.val.c
	$(GET) $(REL) s.val.c

vc:	vc.o ../com/comobj.a
	$(CC) $(LDFLAGS) -o vc vc.o ../com/comobj.a $(LIBES) $(LIBES)

vc.o:	vc.c ../hdr/defines.h ../hdr/had.h
	$(CC) $(CFLAGS) vc.c

vc.c:		s.vc.c
	$(GET) $(REL) s.vc.c

#../hdr/defines.h:		../hdr/s.defines.h
#	-chdir ../hdr; $(GET) $(REL) -s s.defines.h

#../hdr/had.h:		../hdr/s.had.h
#	-chdir ../hdr; $(GET) $(REL) -s s.had.h

E 2
../com/comobj.a:
D 2
	-chdir ../com; Compile
E 2
I 2
	chdir ../com; make comobj.a
E 2

D 2
clean:		# Procedure to clean up unwanted files
	-rm -f *.o
	-rm -f admin.c bdiff.c comb.c rmchg.c scv.c \
	       delta.c get.c help.c prt.c what.c val.c snull.c vc.c \
		cmt.c
	-rm -f admin	bdiff	comb	rmchg	scv	chghist	\
		delta	get	help	prt	what	rmdel	sccsdiff \
		val snull vc cmt
	-rm -f ../errors ../logs
E 2
I 2
clean:
	rm -f *.o
	rm -f admin bdiff chghist comb scv delta get help prt rmdel \
D 6
	    what val snull cmt rmchg prs
E 6
I 6
	    what val snull cmt rmchg prs stree
E 6

install: all
D 6
	install -s admin ${DESTDIR}/usr/local
	install -s bdiff ${DESTDIR}/usr/local
	install -s chghist ${DESTDIR}/usr/local
	rm -f ${DESTDIR}/usr/local/rmdel ${DESTDIR}/usr/local/rmchg
	ln ${DESTDIR}/usr/local/chghist ${DESTDIR}/usr/local/rmchg
	ln ${DESTDIR}/usr/local/chghist ${DESTDIR}/usr/local/rmdel
	install -s comb ${DESTDIR}/usr/local
	install -s delta ${DESTDIR}/usr/local
	install -s help ${DESTDIR}/usr/local
	install -s prt ${DESTDIR}/usr/local
	install -s prs ${DESTDIR}/usr/local
D 5
	install -s rmdel ${DESTDIR}/usr/local
E 5
	install -c sccsdiff.sh ${DESTDIR}/usr/local/sccsdiff
	install -s what ${DESTDIR}/usr/local
	install -s val ${DESTDIR}/usr/local
	install -s snull ${DESTDIR}/usr/local
	install -s get ${DESTDIR}/usr/local
#	install -s scv ${DESTDIR}/usr/local
E 6
I 6
	install -s admin ${DESTDIR}/usr/bin
	install -s bdiff ${DESTDIR}/usr/bin
	install -s chghist ${DESTDIR}/usr/bin
	rm -f ${DESTDIR}/usr/bin/rmdel ${DESTDIR}/usr/bin/rmchg
	ln ${DESTDIR}/usr/bin/chghist ${DESTDIR}/usr/bin/rmchg
	ln ${DESTDIR}/usr/bin/chghist ${DESTDIR}/usr/bin/rmdel
	install -s comb ${DESTDIR}/usr/bin
	install -s delta ${DESTDIR}/usr/bin
D 7
	install -s help ${DESTDIR}/usr/bin
E 7
I 7
	install -s help ${DESTDIR}/usr/bin/sccshelp
E 7
	install -s prt ${DESTDIR}/usr/bin
	install -s prs ${DESTDIR}/usr/bin
	install -c sccsdiff.sh ${DESTDIR}/usr/bin/sccsdiff
	install -s what ${DESTDIR}/usr/bin
	install -s val ${DESTDIR}/usr/bin
	install -s snull ${DESTDIR}/usr/bin
	install -s stree ${DESTDIR}/usr/bin
	install -s get ${DESTDIR}/usr/bin
#	install -s scv ${DESTDIR}/usr/bin
	install -s cmt ${DESTDIR}/usr/bin
E 6
E 2
E 1
