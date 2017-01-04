BINDIR	= /usr/local
TROFF	= troff_p
DEVDIR	= "/usr/local/lib/ditroff"
CFLAGS	= '-DFONTDIR=$(DEVDIR)' -O
#TMACDIR	= /usr/local/lib/ditmac
#MACROLIB= "$(TMACDIR)/tmac."

CFILES	= n1.c n2.c n3.c n4.c n5.c t6.c n7.c n8.c n9.c t10.c ni.c nii.c \
	hytab.c suftab.c

HFILES	= tdef.h v.h d.h s.h tw.h dev.h

TFILES	= n1.o n2.o n3.o n4.o n5.o t6.o n7.o n8.o n9.o t10.o ni.o nii.o \
	hytab.o suftab.o

NFILES	= n1.o n2.o n3.o n4.o n5.o n6.o n7.o n8.o n9.o n10.o ni.o nii.o \
	hytab.o suftab.o

troff:	$(TFILES)
	cc -o troff $(CFLAGS) $(TFILES)

nroff:	$(NFILES)
	cc -o nroff $(CFLAGS) $(NFILES)

install: $(BINDIR)/$(TROFF)

$(BINDIR)/$(TROFF): troff
	install -c -s troff $(BINDIR)/$(TROFF)

n1.o:	tdef.h d.h v.h tw.h s.h
n2.o:	tdef.h d.h v.h tw.h s.h
n3.o:	tdef.h d.h v.h tw.h s.h
n4.o:	tdef.h d.h v.h tw.h s.h
n5.o:	tdef.h d.h v.h tw.h s.h
n6.o:	tdef.h d.h v.h tw.h s.h
t6.o:	tdef.h d.h v.h tw.h s.h dev.h
n7.o:	tdef.h d.h v.h tw.h s.h
n8.o:	tdef.h d.h v.h tw.h s.h
n9.o:	tdef.h d.h v.h tw.h s.h
n10.o:	tdef.h d.h v.h tw.h s.h
t10.o:	tdef.h d.h v.h tw.h s.h dev.h
ni.o:	tdef.h d.h v.h tw.h s.h
#	cc $(CFLAGS) '-DMACROLIB=$(MACROLIB)' -c ni.c

nii.o:	tdef.h d.h v.h tw.h s.h

hytab.o:	hytab.c

suftab.o:	suftab.c


list:
	@pr TODO n[1-6].c t6.c n[7-9].c [nt]10.c ni.c nii.c *.h

lint:
	lint -phc $(CFILES)

clean:
	/bin/rm -f *.o make.out [nt]roff
