#
# Copyright (c) 1980, 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	7.3 (Berkeley) 1/14/99
#
# Make a 750/730 tu58 cassette
# 
BOOTS=	boot
STDBOO=	defboo.cmd anyboo.cmd restar.cmd
DEFBOO=	defboo.rb defboo.rl defboo.hk defboo.up defboo.ra
DEVBOO=	rbmboo.cmd rbsboo.cmd rlsboo.cmd hkmboo.cmd hksboo.cmd \
	upmboo.cmd upsboo.cmd ramboo.cmd rasboo.cmd
UTILS=	format copy drtest

# order is NOT random...
OBJS=	${BOOTS} ${STDBOO} ${DEVBOO} ${UTILS}
FROMDEC=d[lmq]* cs* *boo.* boot.exe vmb.exe

CASSETTE=/dev/tu0

all:	cassette

cassette: ${OBJS} ../mdec/tuboot
	cp /dev/null cassette
	cp /dev/null pad
	arff mcrf cassette ${OBJS} pad
	rm -f pad
	dd if=../mdec/tuboot of=cassette bs=512 count=2

install: cassette
	dd if=cassette of=${CASSETTE} bs=2k conv=sync

# build a 730 boot cassette from a DEC console cassette
# DONT TRY THIS ON A 750 W/O MRSP, THE SYSTEM WILL CRASH
update:	${OBJS}
	-mkdir fromdec
	cd fromdec; arff mxf ${CASSETTE}; rm -f ${FROMDEC} ${OBJS} ${DEFBOO}; \
		flcopy -t3 -f ${CASSETTE}; arff mcrf ${CASSETTE} *
	rm -rf fromdec
	arff mrf ${CASSETTE} ${OBJS}
	-rm -f defboo.cmd

defboo.cmd:
	@echo You must copy one of ${DEFBOO} to defboo.cmd.
	@echo See installing and operating guide for details.
	@/bin/false	#force exits

clean:
	rm -f ${BOOTS} ${UTILS} cassette form50 boot50 copy50 defboo.cmd
