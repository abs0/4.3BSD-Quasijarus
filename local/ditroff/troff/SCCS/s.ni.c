h60015
s 00004/00006/00304
d D 1.7 85/06/24 17:01:02 slatteng 8 6
c made tmac directory easier to specify and put in enfironment lookup for device
e
s 00004/00006/00304
d R 1.7 85/06/24 16:25:42 slatteng 7 6
c made tmac directory easier to specify and put in environment lookup for device
e
s 00004/00001/00306
d D 1.6 84/04/13 16:44:13 slatteng 6 5
c added polygons and stipples
e
s 00010/00003/00297
d D 1.5 84/01/19 12:37:08 slatteng 5 4
c make macro library changeable in makefile
e
s 00002/00002/00298
d D 1.4 83/12/19 17:43:01 slatteng 4 3
c moved macro library
e
s 00006/00002/00294
d D 1.3 83/12/19 17:15:09 slatteng 3 2
c make font directory changeable from makefile
e
s 00000/00001/00296
d D 1.2 83/11/09 15:21:04 slatteng 2 1
c removed smnt special font marker
e
s 00297/00000/00000
d D 1.1 83/11/04 10:33:55 slatteng 1 0
c date and time created 83/11/04 10:33:55 by slatteng
e
u
U
t
T
I 1
#include "tdef.h"

/* You may want to change these names */
I 5
/* these SHOULD be defined in the makefile */
E 5

I 3
#ifndef FONTDIR
D 5
#define FONTDIR "/usr/lib/font"
E 5
I 5
#	define FONTDIR "/usr/lib/font"
E 5
#endif
I 5
#ifndef MACROLIB
D 8
#	define MACROLIB "/usr/lib/tmac/tmac.xxxxx"
E 8
I 8
			/* MACROLIB is the prefix of the macro filenames */
#	define MACROLIB "/usr/lib/tmac/tmac."
E 8
#endif
D 8
#ifndef MACROINDEX
#	define MACROINDEX 19
#endif
E 8
E 5

E 3
#ifndef NROFF
D 3
char	termtab[NS] = "/usr/lib/font";	/* rest added in ptinit() */
char	fontfile[NS] = "/usr/lib/font";	/* rest added in casefp() */
E 3
I 3
char	termtab[NS] = FONTDIR;		/* rest added in ptinit() */
char	fontfile[NS] = FONTDIR;		/* rest added in casefp() */
E 3
D 8
char	devname[10]	 = "va";	/* default typesetter */
E 8
I 8
char	devname[20]	 = "va";	/* default typesetter */
E 8
#endif
char	obuf[OBUFSZ];	/* characters collected here for actual typesetter output */
char	*obufp = obuf;
int	r[NN] = {	/* read-only number registers at beginning */
	PAIR('%', 0),
	PAIR('n', 'l'),
	PAIR('y', 'r'),
	PAIR('h', 'p'),
	PAIR('c', 't'),
	PAIR('d', 'n'),
	PAIR('m', 'o'),
	PAIR('d', 'y'),
	PAIR('d', 'w'),
	PAIR('l', 'n'),
	PAIR('d', 'l'),
	PAIR('s', 't'),
	PAIR('s', 'b'),
	PAIR('c', '.'),
	PAIR('$', '$'),
};


int	pto = 10000;
int	pfrom = 1;
int	print = 1;
D 4
char	nextf[NS] = "/usr/lib/ditmac/tmac.xxxxx";
int	nfi = 21;
E 4
I 4
D 5
char	nextf[NS] = "/usr/local/lib/ditmac/tmac.xxxxx";
int	nfi = 27;
E 5
I 5
char	nextf[NS] = MACROLIB;
D 8
int	nfi = MACROINDEX;
E 8
I 8
int	nfi;
E 8
E 5
E 4
#ifdef NROFF
char	termtab[NS] = "/usr/lib/term/tab37";
#endif
#ifndef NROFF
int	oldbits = -1;
#endif
int	init = 1;
int	fc = IMP;	/* field character */
int	eschar = '\\';
#ifdef	NROFF
int	pl = 11*INCH;
int	po = PO;
#else
int	pl;
int	po;
#endif
int	dfact = 1;
int	dfactd = 1;
int	res = 1;
D 2
int	smnt = 0;	/* beginning of special fonts */
E 2
int	ascii = ASCII;
int	ptid = PTID;
int	lg = LG;
int	pnlist[NPN] = {
	-1};


int	*pnp = pnlist;
int	npn = 1;
int	npnflg = 1;
int	xflg = 1;
int	dpn = -1;
int	totout = 1;
int	ulfont = FT + 1;
int	ulbit = 1 << 9;
int	tabch = TAB;
int	ldrch = LEADER;
int	xxx;
extern caseds(), caseas(), casesp(), caseft(), caseps(), casevs(),
casenr(), caseif(), casepo(), casetl(), casetm(), casebp(), casech(),
casepn(), tbreak(), caseti(), casene(), casenf(), casece(), casefi(),
D 6
casein(), casell(), casens(), casemk(), casert(), caseam(),
E 6
I 6
casein(), casell(), casens(), casemk(), casert(), caseam(), casest(),
E 6
casede(), casedi(), caseda(), casewh(), casedt(), caseit(), caserm(),
casern(), casead(), casers(), casena(), casepl(), caseta(), casetr(),
caseul(), caselt(), casenx(), caseso(), caseig(), casetc(), casefc(),
caseec(), caseeo(), caselc(), caseev(), caserd(), caseab(), casefl(),
done(), casess(), casefp(), casecs(), casebd(), caselg(), casehc(),
casehy(), casenh(), casenm(), casenn(), casesv(), caseos(), casels(),
casecc(), casec2(), caseem(), caseaf(), casehw(), casemc(), casepm(),
casecu(), casepi(), caserr(), caseuf(), caseie(), caseel(), casepc(),
caseht(), casecf(), casesy();

struct contab {
	int	rq;
	/*
	union {
 */
	int	(*f)();
	/*
		unsigned mx;
	}x;
 */
} contab[NM] = {
	PAIR('d', 's'), caseds,
	PAIR('a', 's'), caseas,
	PAIR('s', 'p'), casesp,
	PAIR('f', 't'), caseft,
	PAIR('p', 's'), caseps,
	PAIR('v', 's'), casevs,
	PAIR('n', 'r'), casenr,
	PAIR('i', 'f'), caseif,
	PAIR('i', 'e'), caseie,
	PAIR('e', 'l'), caseel,
	PAIR('p', 'o'), casepo,
	PAIR('t', 'l'), casetl,
	PAIR('t', 'm'), casetm,
	PAIR('b', 'p'), casebp,
	PAIR('c', 'h'), casech,
	PAIR('p', 'n'), casepn,
	PAIR('b', 'r'), tbreak,
	PAIR('t', 'i'), caseti,
	PAIR('n', 'e'), casene,
	PAIR('n', 'f'), casenf,
	PAIR('c', 'e'), casece,
	PAIR('f', 'i'), casefi,
	PAIR('i', 'n'), casein,
	PAIR('l', 'l'), casell,
	PAIR('n', 's'), casens,
	PAIR('m', 'k'), casemk,
	PAIR('r', 't'), casert,
	PAIR('a', 'm'), caseam,
I 6
	PAIR('s', 't'), casest,
E 6
	PAIR('d', 'e'), casede,
	PAIR('d', 'i'), casedi,
	PAIR('d', 'a'), caseda,
	PAIR('w', 'h'), casewh,
	PAIR('d', 't'), casedt,
	PAIR('i', 't'), caseit,
	PAIR('r', 'm'), caserm,
	PAIR('r', 'r'), caserr,
	PAIR('r', 'n'), casern,
	PAIR('a', 'd'), casead,
	PAIR('r', 's'), casers,
	PAIR('n', 'a'), casena,
	PAIR('p', 'l'), casepl,
	PAIR('t', 'a'), caseta,
	PAIR('t', 'r'), casetr,
	PAIR('u', 'l'), caseul,
	PAIR('c', 'u'), casecu,
	PAIR('l', 't'), caselt,
	PAIR('n', 'x'), casenx,
	PAIR('s', 'o'), caseso,
	PAIR('i', 'g'), caseig,
	PAIR('t', 'c'), casetc,
	PAIR('f', 'c'), casefc,
	PAIR('e', 'c'), caseec,
	PAIR('e', 'o'), caseeo,
	PAIR('l', 'c'), caselc,
	PAIR('e', 'v'), caseev,
	PAIR('r', 'd'), caserd,
	PAIR('a', 'b'), caseab,
	PAIR('f', 'l'), casefl,
	PAIR('e', 'x'), done,
	PAIR('s', 's'), casess,
	PAIR('f', 'p'), casefp,
	PAIR('c', 's'), casecs,
	PAIR('b', 'd'), casebd,
	PAIR('l', 'g'), caselg,
	PAIR('h', 'c'), casehc,
	PAIR('h', 'y'), casehy,
	PAIR('n', 'h'), casenh,
	PAIR('n', 'm'), casenm,
	PAIR('n', 'n'), casenn,
	PAIR('s', 'v'), casesv,
	PAIR('o', 's'), caseos,
	PAIR('l', 's'), casels,
	PAIR('c', 'c'), casecc,
	PAIR('c', '2'), casec2,
	PAIR('e', 'm'), caseem,
	PAIR('a', 'f'), caseaf,
	PAIR('h', 'w'), casehw,
	PAIR('m', 'c'), casemc,
	PAIR('p', 'm'), casepm,
	PAIR('p', 'i'), casepi,
	PAIR('u', 'f'), caseuf,
	PAIR('p', 'c'), casepc,
	PAIR('h', 't'), caseht,
	PAIR('c', 'f'), casecf,
	PAIR('s', 'y'), casesy,
	PAIR('!', 0), casesy,	/* synonym for .sy */
};


tchar oline[LNSIZE+1];

/*
troff environment block
*/

int	block	 = 0;
#ifdef	NROFF
/* these are initialized statically in nroff (so far)
	/* and dynamically in ptinit() in troff beacuse INCH
	/* is a variable
	*/
int	ics	 = ICS;	/* space for insertion character */
int	sps	 = SPS;
int	spacesz	 = SS;
int	lss	 = VS;
int	lss1	 = VS;
int	ll	 = LL;
int	ll1	 = LL;
int	lt	 = LL;
int	lt1	 = LL;
#else
int	ics	 = 0;
int	sps	 = 0;
int	spacesz	 = 0;
int	lss	 = 0;
int	lss1	 = 0;
int	ll	 = 0;
int	ll1	 = 0;
int	lt	 = 0;
int	lt1	 = 0;
#endif
tchar	ic	 = 0;	/* insertion character (= margin character) */
int	icf	 = 0;
tchar	chbits	 = 0;	/* size+font bits for current character */
tchar	spbits	 = 0;	/* ditto for special font */
tchar	nmbits	 = 0;
int	apts	 = PS;	/* actual point size -- as requested by user */
int	apts1	 = PS;	/* need not match an existent size */
int	pts	 = PS;	/* hence, this is the size that really exists */
int	pts1	 = PS;
int	font	 = FT;
int	font1	 = FT;
I 6
int	stip	 = ST;
int	stip1	 = ST;
E 6
int	ls	 = 1;
int	ls1	 = 1;
int	ad	 = 1;
int	nms	 = 1;
int	ndf	 = 1;
int	fi	 = 1;
int	cc	 = '.';
int	c2	 = '\'';
int	ohc	 = OHC;
int	tdelim	 = IMP;
int	hyf	 = 1;
int	hyoff	 = 0;
int	un1	 = -1;
int	tabc	 = 0;
int	dotc	 = '.';
int	adsp	 = 0;
int	adrem	 = 0;
int	lastl	 = 0;
int	nel	 = 0;
int	admod	 = 0;
tchar	*wordp	 = 0;
int	spflg	 = 0;	/* probably to indicate space after punctuation needed */
tchar	*linep	 = 0;
tchar	*wdend	 = 0;
tchar	*wdstart	 = 0;
int	wne	 = 0;
int	ne	 = 0;
int	nc	 = 0;
int	nb	 = 0;
int	lnmod	 = 0;
int	nwd	 = 0;
int	nn	 = 0;
int	ni	 = 0;
int	ul	 = 0;
int	cu	 = 0;
int	ce	 = 0;
int	in	 = 0;
int	in1	 = 0;
int	un	 = 0;
int	wch	 = 0;
int	pendt	 = 0;
tchar	*pendw	 = 0;
int	pendnf	 = 0;
int	spread	 = 0;
int	it	 = 0;
int	itmac	 = 0;
int	lnsize	 = LNSIZE;
tchar	*hyptr[NHYP]	 = {
	0};


int	tabtab[NTAB]	 = {
	0};


tchar	line[LNSIZE]	 = {
	0};


tchar	word[WDSIZE]	 = {
	0};


char	blockxxx[EVSPARE]	 = {
	0};


E 1
