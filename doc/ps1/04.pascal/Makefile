#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)makefile	6.1 (Berkeley) 5/7/86
#
# This makefile assumes that csh is running the figures
#
PRINTER=Pdp
TROFF=	ditroff -${PRINTER}
TBL=	dtbl -${PRINTER}
LPR=	lpr -n -${PRINTER}
SEC = ?
FIGURES=\
	firstout firstobjout firstobjout2\
	bigger2.p bigger3.p bigout1 bigger6.p bigout2 bigout3 bigout4\
	primeout1 primeout2\
	digitsout synerrout synerr2out\
	mismout clashout sinout1 sinout2\
	exprout typequout primeout3\
	katout copydataout kat2out katscript xxxxqqqout xxxxqqqout2\
	primes primes-d\
	comments1.p commentsout

manual: lpr.${PRINTER}
	${LPR} lpr.${PRINTER}

lpr.${PRINTER}: ${FIGURES}
	soelim puman${SEC}.n | ${TBL} | csh -cf '${TROFF} -t >lpr.${PRINTER}'

troff:	${FIGURES}
	soelim puman${SEC}.n | ${TBL} | ${TROFF}

csfix:
	cc -O csfix.c -o csfix
firstout: first.p csfix
	-csh -cf 'pix -g first.p |& expand | csfix >firstout'
firstobjout: first.p
	-csh -cf 'pi -g first.p >& firstobjout ; px >& firstobjout'
firstobjout2: first.p
	-csh -cf 'pi -g -p first.p >& firstobjout2 ; px >& firstobjout2'
bigger2.p: bigger.p
	-expand bigger.p >bigger2.p
bigger3.p: bigger2.p csfix
	cat -n bigger2.p | expand | csfix -d >bigger3.p
bigout1: bigger.p csfix
	-csh -cf 'pix -g bigger.p |& expand | csfix  >bigout1'
bigger6.p: bigger5.p csfix
	cat -n bigger5.p | expand | csfix -d >bigger6.p
bigout2: bigger4.p
	-csh -cf 'pix -g bigger4.p |& expand >bigout2'
bigout3: bigger7.p
	-csh -cf 'pix -g bigger7.p |& expand >bigout3'
bigout4: bigger7.p
	-csh -cf '(pix -g bigger7.p >/dev/null) |& expand > bigout4'
primeout1: primes.p csfix
	-csh -cf 'pix -g -l -z primes.p |& expand | csfix - >primeout1'
primeout2: primes.p csfix
	-csh -cf 'pxp -z primes.p |& expand | csfix - >primeout2'
digitsout: digits.p csfix
	-csh -cf 'pi -g digits.p |& expand | csfix >digitsout'
synerrout: synerr.p csfix
	-csh -cf 'pi -g -l synerr.p |& expand | csfix >synerrout'
synerr2out: synerr2.p csfix
	-csh -cf 'pix -g -l synerr2.p |& expand | csfix >synerr2out'
mismout: mism.p csfix
	-csh -cf 'pi -g -l mism.p |& expand | csfix >mismout'
clashout: clash.p
	-csh -cf 'pi -g clash.p |& expand >clashout'
sinout1: sin1.p
	-csh -cf 'pi -g sin1.p |& expand >sinout1'
sinout2: sin2.p
	-csh -cf 'pi -g sin2.p |& expand >sinout2'
exprout: expr.p
	-pi -g -l expr.p | expand >exprout
typequout: typequ.p
	-pi -g typequ.p >typequout
primeout3: primes2.p csfix
	-csh -cf 'pix -g primes2.p |& expand | csfix -d >primeout3'
katout: kat.p csfix primes
	-csh -cf 'pix -g -l kat.p <primes |& expand | csfix -d >katout'
copydataout: copydata.p csfix
	-csh -cf 'pix -g -l copydata.p |& expand | csfix -d >copydataout'
kat2out: kat2.p
	-csh -cf 'pi -g kat2.p ; obj primes |& csfix -d >kat2out'
xxxxqqqout: kat2.p
	-pi -g kat2.p
	-csh -cf 'obj xxxxqqq >& xxxxqqqout'
xxxxqqqout2: kat2.p
	-pi -g -p kat2.p
	-csh -cf 'obj xxxxqqq >& xxxxqqqout2'
primes: primes.p
	-pix -g -p primes.p > primes
primes-d: primes
	csfix -d <primes >primes-d
katscript: katin
	-csh -cf 'pi -g kat2.p ; obj katin >& katscript'
	-ed - katscript < fixkatscript
comments1.p: comments.p
	-expand comments.p >comments1.p
commentsout: comments.p
	-csh -cf 'pxp comments.p |& expand >commentsout'
	-ed - commentsout < fixcomments
clean:
	-rm csfix pmon.out obj lpr.${PRINTER} ${FIGURES} errs Errs
