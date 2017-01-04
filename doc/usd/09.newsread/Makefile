#	@(#)Makefile	6.3 (Berkeley) 2012/02/19
#
# make the various documents

FMT=pstroff
FMTOPTS=

all:	howto.ps

howto.ps: howto.mn tmac.n
	$(FMT) $(FMTOPTS) tmac.n howto.mn | pstfinish -l USD:9-%l > $@

copyright.ps: copyright.mn tmac.n
	$(FMT) $(FMTOPTS) tmac.n copyright.mn > $@

clean:
	rm -f *.ps errs
