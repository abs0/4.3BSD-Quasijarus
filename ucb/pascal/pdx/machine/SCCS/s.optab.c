h38707
s 00031/00025/00247
d D 5.2 87/09/30 09:02:04 mckusick 5 4
c fix entries for pred and succ (4.3BSD/ucb/21 Allyn Franklin UCSD)
e
s 00008/00002/00264
d D 5.1 85/06/06 08:17:45 dist 4 3
c Add copyright
e
s 00003/00005/00263
d D 1.3 82/08/29 22:29:26 linton 3 2
c addition of dfdisp op
e
s 00001/00001/00267
d D 1.2 82/03/08 18:58:45 linton 2 1
c fixed table entry for "defname" operator
e
s 00268/00000/00000
d D 1.1 82/01/18 19:20:14 linton 1 0
c date and time created 82/01/18 19:20:14 by linton
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1982 Regents of the University of California */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 4

D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

/*
 * px opcode table
 */

#include "optab.h"

OPTAB optab[] ={
D 5
	{ "badop00" },
E 5
I 5
	{ "badop0" },
E 5
	{ "nodump", PSUBOP, LWORD, HWORD, STRING },
D 5
	{ "beg", PSUBOP, LWORD, LWORD, LWORD, HWORD, STRING },
E 5
I 5
#ifdef ADDR32
	{ "beg", PSUBOP, LWORD, LWORD, HWORD, LWORD, STRING },
#else
	{ "beg", PSUBOP, LWORD, LWORD, HWORD, HWORD, STRING },
#endif
E 5
	{ "end" },
	{ "call", DISP, ADDR4 },
	{ "fcall" },
	{ "frtn", PSUBOP },
	{ "fsav", SUBOP, LWORD },
	{ "sdup2" },
	{ "sdup4" },
	{ "tra", ADDR2 },
	{ "tra4", ADDR4 },
	{ "goto", DISP, ADDR4 },
	{ "lino", PSUBOP },
	{ "push", PSUBOP },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop15" },
E 5
	{ "if", ADDR2 },
	{ "rel2", SUBOP },
	{ "rel4", SUBOP },
	{ "rel24", SUBOP },
	{ "rel42", SUBOP },
	{ "rel8", SUBOP },
	{ "relg", SUBOP, VLEN },
	{ "relt", SUBOP, VLEN },
	{ "rel28", SUBOP },
	{ "rel48", SUBOP },
	{ "rel82", SUBOP },
	{ "rel84", SUBOP },
	{ "and" },
	{ "or" },
	{ "not" },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop31" },
E 5
	{ "as2" },
	{ "as4" },
	{ "as24" },
	{ "as42" },
	{ "as21" },
	{ "as41" },
	{ "as28" },
	{ "as48" },
	{ "as8" },
	{ "as" },
	{ "inx2p2", PSUBOP },
	{ "inx4p2", PSUBOP },
	{ "inx2", PSUBOP, HWORD, HWORD },
	{ "inx4", PSUBOP, HWORD, HWORD },
	{ "off", PSUBOP },
	{ "nil" },
	{ "add2" },
	{ "add4" },
	{ "add24" },
	{ "add42" },
	{ "add28" },
	{ "add48" },
	{ "add82" },
	{ "add84" },
	{ "sub2" },
	{ "sub4" },
	{ "sub24" },
	{ "sub42" },
	{ "sub28" },
	{ "sub48" },
	{ "sub82" },
	{ "sub84" },
	{ "mul2" },
	{ "mul4" },
	{ "mul24" },
	{ "mul42" },
	{ "mul28" },
	{ "mul48" },
	{ "mul82" },
	{ "mul84" },
	{ "abs2" },
	{ "abs4" },
	{ "abs8" },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop75" },
E 5
	{ "neg2" },
	{ "neg4" },
	{ "neg8" },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop79" },
E 5
	{ "div2" },
	{ "div4" },
	{ "div24" },
	{ "div42" },
	{ "mod2" },
	{ "mod4" },
	{ "mod24" },
	{ "mod42" },
	{ "add8" },
	{ "sub8" },
	{ "mul8" },
	{ "dvd8" },
	{ "stoi" },
	{ "stod" },
	{ "itod" },
	{ "itos" },
	{ "dvd2" },
	{ "dvd4" },
	{ "dvd24" },
	{ "dvd42" },
	{ "dvd28" },
	{ "dvd48" },
	{ "dvd82" },
	{ "dvd84" },
	{ "rv1", DISP, ADDR2 },
	{ "rv14", DISP, ADDR2 },
	{ "rv2", DISP, ADDR2 },
	{ "rv24", DISP, ADDR2 },
	{ "rv4", DISP, ADDR2 },
	{ "rv8", DISP, ADDR2 },
	{ "rv", PSUBOP, DISP, ADDR2 },
	{ "lv", DISP, HWORD },
	{ "lrv1", DISP, ADDR4 },
	{ "lrv14", DISP, ADDR4 },
	{ "lrv2", DISP, ADDR4 },
	{ "lrv24", DISP, ADDR4 },
	{ "lrv4", DISP, ADDR4 },
	{ "lrv8", DISP, ADDR4 },
	{ "lrv", PSUBOP, DISP, ADDR4 },
	{ "llv", DISP, ADDR4 },
	{ "ind1" },
	{ "ind14" },
	{ "ind2" },
	{ "ind24" },
	{ "ind4" },
	{ "ind8" },
	{ "ind" },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop127" },
E 5
	{ "con1", SUBOP },
	{ "con14", SUBOP },
	{ "con2", HWORD },
	{ "con24", HWORD },
	{ "con4", LWORD },
	{ "con8", LWORD, LWORD },
	{ "con", HWORD },
	{ "lvcon", PSUBOP, STRING },
	{ "rang2", HWORD, HWORD },
	{ "rang42", HWORD, HWORD },
	{ "rsng2", HWORD },
	{ "rsng42", HWORD },
	{ "rang4", LWORD, LWORD },
	{ "rang24", LWORD, LWORD },
	{ "rsng4", LWORD },
	{ "rsng24", LWORD },
	{ "stlim" },
	{ "llimit" },
	{ "buff", PSUBOP },
	{ "halt" },
D 5
	{ "badopnn" },
	{ "badopnn" },
	{ "badopnn" },
	{ "badopnn" },
E 5
I 5
	{ "badop148" },
	{ "badop149" },
	{ "badop150" },
	{ "badop151" },
E 5
	{ "*ord2" },
	{ "*cong" },
	{ "*conc" },
	{ "*conc4" },
	{ "*abort" },
	{ "pxpbuf", HWORD },
	{ "count", HWORD },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop159" },
E 5
	{ "case1op", HWORD },
	{ "case2op", HWORD },
	{ "case4op", HWORD },
	{ "*casebeg" },
	{ "*case1" },
	{ "*case2" },
	{ "*case4" },
	{ "*caseend" },
	{ "addt" },
	{ "subt" },
	{ "mult" },
	{ "inct" },
	{ "cttot", PSUBOP, HWORD, HWORD },
	{ "card", PSUBOP },
	{ "in", PSUBOP, HWORD, HWORD },
	{ "asrt" },
	{ "for1u", HWORD, HWORD, ADDR2 },
	{ "for2u", HWORD, HWORD, ADDR2 },
	{ "for4u", LWORD, LWORD, ADDR2 },
	{ "for1d", HWORD, HWORD, ADDR2 },
	{ "for2d", HWORD, HWORD, ADDR2 },
	{ "for4d", LWORD, LWORD, ADDR2 },
D 5
	{ "badopnn" },
	{ "badopnn" },
E 5
I 5
	{ "badop182" },
	{ "badop183" },
E 5
	{ "reade", ADDR4 },
	{ "read4" },
	{ "readc" },
	{ "read8" },
	{ "readln" },
	{ "eof" },
	{ "eoln" },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop191" },
E 5
	{ "writec" },
	{ "writes" },
	{ "writef", PSUBOP },
	{ "writln" },
	{ "page" },
	{ "nam", ADDR4 },
	{ "max", PSUBOP, HWORD },
	{ "min", PSUBOP },
	{ "unit" },
	{ "unitinp" },
	{ "unitout" },
	{ "message" },
	{ "get" },
	{ "put" },
	{ "fnil" },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop207" },
E 5
D 2
	{ "defname", PSUBOP, HWORD },
E 2
I 2
	{ "defname" },
E 2
	{ "reset" },
	{ "rewrite" },
	{ "file" },
	{ "remove" },
	{ "flush" },
D 5
	{ "badopnn" },
	{ "badopnn" },
E 5
I 5
	{ "badop214" },
	{ "badop215" },
E 5
	{ "pack", PSUBOP, HWORD, HWORD, HWORD },
	{ "unpack", PSUBOP, HWORD, HWORD, HWORD },
I 3
	{ "new", PSUBOP },
	{ "dispose", PSUBOP },
	{ "dfdisp", PSUBOP },
E 3
	{ "argc" },
	{ "argv", PSUBOP },
D 5
	{ "badopnn" },
E 5
I 5
	{ "badop223" },
E 5
D 3
	{ "badopnn" },
	{ "badopnn" },
	{ "badopnn" },
E 3
	{ "clck" },
	{ "wclck" },
	{ "sclck" },
D 3
	{ "dispose", PSUBOP },
	{ "new", PSUBOP },
E 3
	{ "date" },
	{ "time" },
	{ "undef" },
I 5
	{ "badop230" },
	{ "badop231" },
E 5
	{ "atan" },
	{ "cos" },
	{ "exp" },
	{ "ln" },
	{ "sin" },
	{ "sqrt" },
	{ "chr2" },
	{ "chr4" },
	{ "odd2" },
	{ "odd4" },
D 5
	{ "pred2" },
	{ "pred4" },
	{ "pred24" },
	{ "succ2" },
	{ "succ4" },
	{ "succ24" },
E 5
I 5
	{ "pred2", HWORD, HWORD },
	{ "pred4", LWORD, LWORD },
	{ "pred24", HWORD, HWORD },
	{ "succ2", HWORD, HWORD },
	{ "succ4", LWORD, LWORD },
	{ "succ24", HWORD, HWORD },
E 5
	{ "seed" },
	{ "random" },
	{ "expo" },
	{ "sqr2" },
	{ "sqr4" },
	{ "sqr8" },
	{ "round" },
	{ "trunc" },
};
E 1
