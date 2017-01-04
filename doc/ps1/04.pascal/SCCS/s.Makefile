h49792
s 00036/00032/00070
d D 6.1 86/05/07 14:53:32 mckusick 3 2
c document distributed with 4.3BSD
e
s 00006/00000/00096
d D 5.1 86/05/07 14:53:04 mckusick 2 1
c document distributed with 4.2BSD
e
s 00096/00000/00000
d D 4.1 86/05/07 14:52:39 mckusick 1 0
c document distributed with 4.1BSD
e
u
U
t
T
I 1
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
# This makefile assumes that csh is running the figures
#
D 3
DEV = -x
E 3
I 3
PRINTER=Pdp
TROFF=	ditroff -${PRINTER}
TBL=	dtbl -${PRINTER}
LPR=	lpr -n -${PRINTER}
E 3
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
I 2
D 3
TROFF=	vtroff
E 3

E 2
D 3
puman: ${FIGURES}
	soelim puman${SEC}.n | tbl | csh -cf '/usr/ucb/vtroff -t ${DEV} >lpr'
	vpr -t lpr
E 3
I 3
manual: lpr.${PRINTER}
	${LPR} lpr.${PRINTER}
E 3
I 2

I 3
lpr.${PRINTER}: ${FIGURES}
	soelim puman${SEC}.n | ${TBL} | csh -cf '${TROFF} -t >lpr.${PRINTER}'

E 3
troff:	${FIGURES}
D 3
	soelim puman${SEC}.n | tbl | ${TROFF}
E 3
I 3
	soelim puman${SEC}.n | ${TBL} | ${TROFF}
E 3

E 2
csfix:
	cc -O csfix.c -o csfix
firstout: first.p csfix
D 3
	-csh -cf 'pix first.p |& expand | csfix >firstout'
E 3
I 3
	-csh -cf 'pix -g first.p |& expand | csfix >firstout'
E 3
firstobjout: first.p
D 3
	-csh -cf 'pi first.p >& firstobjout ; px >& firstobjout'
E 3
I 3
	-csh -cf 'pi -g first.p >& firstobjout ; px >& firstobjout'
E 3
firstobjout2: first.p
D 3
	-csh -cf 'pi -p first.p >& firstobjout2 ; px >& firstobjout2'
E 3
I 3
	-csh -cf 'pi -g -p first.p >& firstobjout2 ; px >& firstobjout2'
E 3
bigger2.p: bigger.p
	-expand bigger.p >bigger2.p
bigger3.p: bigger2.p csfix
	cat -n bigger2.p | expand | csfix -d >bigger3.p
bigout1: bigger.p csfix
D 3
	-csh -cf 'pix bigger.p |& expand | csfix  >bigout1'
E 3
I 3
	-csh -cf 'pix -g bigger.p |& expand | csfix  >bigout1'
E 3
bigger6.p: bigger5.p csfix
	cat -n bigger5.p | expand | csfix -d >bigger6.p
bigout2: bigger4.p
D 3
	-csh -cf 'pix bigger4.p |& expand >bigout2'
E 3
I 3
	-csh -cf 'pix -g bigger4.p |& expand >bigout2'
E 3
bigout3: bigger7.p
D 3
	-csh -cf 'pix bigger7.p |& expand >bigout3'
E 3
I 3
	-csh -cf 'pix -g bigger7.p |& expand >bigout3'
E 3
bigout4: bigger7.p
D 3
	-csh -cf '(pix bigger7.p >/dev/null) |& expand > bigout4'
E 3
I 3
	-csh -cf '(pix -g bigger7.p >/dev/null) |& expand > bigout4'
E 3
primeout1: primes.p csfix
D 3
	-csh -cf 'pix -l -z primes.p |& expand | csfix - >primeout1'
E 3
I 3
	-csh -cf 'pix -g -l -z primes.p |& expand | csfix - >primeout1'
E 3
primeout2: primes.p csfix
	-csh -cf 'pxp -z primes.p |& expand | csfix - >primeout2'
digitsout: digits.p csfix
D 3
	-csh -cf 'pi digits.p |& expand | csfix >digitsout'
E 3
I 3
	-csh -cf 'pi -g digits.p |& expand | csfix >digitsout'
E 3
synerrout: synerr.p csfix
D 3
	-csh -cf 'pi -l synerr.p |& expand | csfix >synerrout'
E 3
I 3
	-csh -cf 'pi -g -l synerr.p |& expand | csfix >synerrout'
E 3
synerr2out: synerr2.p csfix
D 3
	-csh -cf 'pix -l synerr2.p |& expand | csfix >synerr2out'
E 3
I 3
	-csh -cf 'pix -g -l synerr2.p |& expand | csfix >synerr2out'
E 3
mismout: mism.p csfix
D 3
	-csh -cf 'pi -l mism.p |& expand | csfix >mismout'
E 3
I 3
	-csh -cf 'pi -g -l mism.p |& expand | csfix >mismout'
E 3
clashout: clash.p
D 3
	-csh -cf 'pi clash.p |& expand >clashout'
E 3
I 3
	-csh -cf 'pi -g clash.p |& expand >clashout'
E 3
sinout1: sin1.p
D 3
	-csh -cf 'pi sin1.p |& expand >sinout1'
E 3
I 3
	-csh -cf 'pi -g sin1.p |& expand >sinout1'
E 3
sinout2: sin2.p
D 3
	-csh -cf 'pi sin2.p |& expand >sinout2'
E 3
I 3
	-csh -cf 'pi -g sin2.p |& expand >sinout2'
E 3
exprout: expr.p
D 3
	-pi -l expr.p | expand >exprout
E 3
I 3
	-pi -g -l expr.p | expand >exprout
E 3
typequout: typequ.p
D 3
	-pi typequ.p >typequout
E 3
I 3
	-pi -g typequ.p >typequout
E 3
primeout3: primes2.p csfix
D 3
	-csh -cf 'pix primes2.p |& expand | csfix -d >primeout3'
E 3
I 3
	-csh -cf 'pix -g primes2.p |& expand | csfix -d >primeout3'
E 3
katout: kat.p csfix primes
D 3
	-csh -cf 'pix -l kat.p <primes |& expand | csfix -d >katout'
E 3
I 3
	-csh -cf 'pix -g -l kat.p <primes |& expand | csfix -d >katout'
E 3
copydataout: copydata.p csfix
D 3
	-csh -cf 'pix -l copydata.p |& expand | csfix -d >copydataout'
E 3
I 3
	-csh -cf 'pix -g -l copydata.p |& expand | csfix -d >copydataout'
E 3
kat2out: kat2.p
D 3
	-csh -cf 'pi kat2.p ; obj primes |& csfix -d >kat2out'
E 3
I 3
	-csh -cf 'pi -g kat2.p ; obj primes |& csfix -d >kat2out'
E 3
xxxxqqqout: kat2.p
D 3
	-pi kat2.p
E 3
I 3
	-pi -g kat2.p
E 3
	-csh -cf 'obj xxxxqqq >& xxxxqqqout'
xxxxqqqout2: kat2.p
D 3
	-pi -p kat2.p
E 3
I 3
	-pi -g -p kat2.p
E 3
	-csh -cf 'obj xxxxqqq >& xxxxqqqout2'
primes: primes.p
D 3
	-pix -p primes.p > primes
E 3
I 3
	-pix -g -p primes.p > primes
E 3
primes-d: primes
	csfix -d <primes >primes-d
katscript: katin
D 3
	-csh -cf 'pi kat2.p ; obj katin >& katscript'
E 3
I 3
	-csh -cf 'pi -g kat2.p ; obj katin >& katscript'
E 3
	-ed - katscript < fixkatscript
comments1.p: comments.p
	-expand comments.p >comments1.p
commentsout: comments.p
	-csh -cf 'pxp comments.p |& expand >commentsout'
	-ed - commentsout < fixcomments
clean:
D 3
	-rm csfix pmon.out obj lpr ${FIGURES}
E 3
I 3
	-rm csfix pmon.out obj lpr.${PRINTER} ${FIGURES} errs Errs
E 3
E 1
