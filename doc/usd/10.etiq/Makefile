#	@(#)Makefile	6.4 (Berkeley) 2012/03/12
#
# make the various documents

FMT=pstroff
FMTOPTS=-fR,I,B,S,ZD

all:	manner.ps

manner.ps: manner.mn tmac.n
	$(FMT) $(FMTOPTS) tmac.n manner.mn | pstfinish -l USD:10-%l > $@

clean:
	rm -f *.ps errs
