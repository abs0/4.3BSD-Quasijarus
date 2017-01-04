h39928
s 00001/00001/00234
d R 1.4 85/06/24 16:40:05 slatteng 4 3
c make devname a pointer instead of an array.
e
s 00007/00003/00228
d D 1.3 84/04/13 16:44:19 slatteng 3 2
c added polygons and stipples
e
s 00000/00001/00231
d D 1.2 83/11/09 15:20:07 slatteng 2 1
c removed smnt special font marker
e
s 00232/00000/00000
d D 1.1 83/11/04 10:37:48 slatteng 1 0
c date and time created 83/11/04 10:37:48 by slatteng
e
u
U
t
T
I 1
extern	char	**argp;
extern	char	*chname;
extern	char	*eibuf;
extern	char	*enda;
extern	char	*fitab[];
extern	char	*fontab[];
extern	char	*kerntab[];
extern	char	*ibufp;
extern	char	*obufp;
extern	char	*unlkp;
extern	char	*xbufp;
extern	char	*xeibuf;
extern	char	codetab[];
extern	char	devname[];
extern	char	fontfile[];
extern	char	ibuf[IBUFSZ];
extern	char	nextf[];
extern	char	obuf[],	*obufp;
D 3
extern	char	termtab[],	fontfile[];
E 3
I 3
extern	char	termtab[];
E 3
extern	char	xbuf[IBUFSZ];
extern	filep	apptr;
extern	filep	ip;
extern	filep	nextb;
extern	filep	offset;
extern	filep	roff;
extern	filep	woff;
extern	short	*chtab;
extern	int	*pnp;
extern	int	*pslp;
extern	short	*pstab;
extern	int	*vlist;
extern	int	Bflg;
extern	int	ad,	admod;
extern	int	adrem;
extern	int	adsp;
extern	int	app;
D 3
extern	int	apts,	apts1,	pts,	pts1,	font,	font1;
E 3
I 3
extern	int	apts,	apts1;
E 3
extern	int	ascii;
extern	int	back;
extern	int	bd;
extern	int	bdtab[];
extern	int	c2;
extern	int	cc;
extern	int	ccs;
extern	int	ce;
extern	int	code;
extern	int	copyf;
extern	int	cps;
extern	int	cs;
extern	int	cu;
extern	int	cwidth;
extern	int	dfact;
extern	int	dfactd;
extern	int	diflg;
extern	int	dilev;
extern	int	donef;
extern	int	dotT;
extern	int	dotc;
extern	int	dpn;
extern	int	ds;
extern	int	ejf;
extern	int	em;
extern	int	eqflg;
extern	int	error;
extern	int	esc;
extern	int	eschar;
extern	int	ev;
extern	int	evi;
extern	int	evlist[EVLSZ];
extern	int	fc;
extern	int	fi;
extern	int	flss;
extern	int	fmt[NN];
extern	int	font1;
extern	int	font;
extern	int	fontlab[];
I 3
extern	int	stip1;
extern	int	stip;
extern	tchar	*stiplab;
E 3
extern	int	gflag;
extern	int	hflg;
extern	int	hyf;
extern	int	hyoff;
extern	int	ibf;
extern	int	icf;
extern	int	ics;
extern	int	ifi;
extern	int	ifile;
extern	int	ifl[NSO];
extern	int	iflg;
extern	int	in1;
extern	int	in;
extern	int	inc[NN];
extern	int	init;
extern	int	it;
extern	int	itmac;
extern	int	lastl;
extern	int	lead;
extern	int	level;
extern	int	lg;
extern	int	lgf;
extern	int	ll1;
extern	int	ll;
extern	int	lnmod;
extern	int	lnsize;
extern	int	ls1;
extern	int	ls;
extern	int	lss1;
extern	int	lss;
extern	int	lt1;
extern	int	lt;
extern	int	macerr;
extern	int	mflg;
extern	int	mfont;
extern	int	mlist[NTRAP];
extern	int	mpts;
extern	int	nb;
extern	int	nc;
extern	int	nchar;
extern	int	ndf;
extern	int	ndone;
extern	int	ne;
D 3
extern	int	nel,	un;
E 3
I 3
extern	int	nel;
E 3
extern	int	newmn;
extern	int	nfi;
extern	int	nflush;
extern	int	nfo;
extern	int	nfonts;
I 3
extern	int	nstips;
E 3
extern	int	nform;
extern	int	nhyp;
extern	int	ni;
extern	int	nlflg;
extern	int	nlist[NTRAP];
extern	int	nms;
extern	int	nn;
extern	int	no_out;
extern	int	nofeed;
extern	int	nonumb;
extern	int	noscale;
extern	int	npn;
extern	int	npnflg;
extern	int	nwd;
extern	int	nx;
extern	int	ohc;
extern	int	oldbits;
extern	int	oldmn;
extern	int	over;
extern	int	padc;
extern	int	paper;
extern	int	pendnf;
extern	int	pendt;
extern	int	pfont;
extern	int	pfrom;
extern	int	pipeflg;
extern	int	pl;
extern	int	pnlist[];
extern	int	po1;
extern	int	po;
extern	int	ppts;
extern	int	print;
extern	int	psflg;
extern	int	ptid;
extern	int	pto;
extern	int	pts1;
extern	int	pts;
extern	int	quiet;
extern	int	r[NN];
extern	int	ralss;
extern	int	rargc;
extern	int	raw;
extern	int	res;
extern	int	setwdf;
extern	int	sfont;
D 2
extern	int	smnt;
E 2
extern	int	spacesz;
extern	int	spflg;
extern	int	spread;
extern	int	sps;
extern	int	stdi;
extern	int	stop;
extern	int	sv;
extern	int	tabc,	dotc;
extern	int	tabch,	ldrch;
extern	int	tabtab[NTAB];
extern	int	tdelim;
extern	int	tflg;
extern	int	tlss;
extern	int	totout;
extern	int	trap;
extern	int	trflg;
extern	int	trtab[];
extern	int	tty;
extern	int	ttyod;
extern	int	ttysave;
extern	int	ul;
extern	tchar	ulbit;
extern	int	ulfont;
extern	int	un1;
extern	int	un;
extern	int	vflag;
extern	int	waitf;
extern	int	wbfi;
extern	int	wch;
extern	int	widthp;
extern	int	wne;
extern	int	xbitf;
extern	int	xflg;
extern	int	xfont;
extern	int	xpts;
extern	no_out;
extern	struct	font	*fontbase[NFONT+1];	/* origin of each font in core hole */
extern	struct	s	*ejl;
extern	struct	s	*frame,	*stk,	*nxf;
extern	struct	sgttyb	ttys;
extern	tchar	**hyp;
extern	tchar	*ap;
extern	tchar	*cp;
extern	tchar	*hyptr[NHYP];
extern	tchar	*linep;
extern	tchar	*olinep;
extern	tchar	*pendw;
extern	tchar	*wdstart,	*wdend;
extern	tchar	*wordp;
extern	tchar	cbuf[NC];
extern	tchar	ch0;
extern	tchar	ch;
extern	tchar	chbits;
extern	tchar	ic;
extern	tchar	inchar[LNSIZE],	*pinchar;
extern	tchar	line[];
extern	tchar	nmbits;
extern	tchar	nrbits;
extern	tchar	oline[];
extern	tchar	rchar;
extern	tchar	word[];
E 1
