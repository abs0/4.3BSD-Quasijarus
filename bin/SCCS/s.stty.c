h14787
s 00005/00000/00578
d D 5.6 03/03/29 16:28:09 msokolov 25 24
c add koi mode
e
s 00002/00002/00576
d D 5.5 87/12/22 12:20:06 bostic 24 23
c make ANSI C compatible; use supplied defines
e
s 00001/00001/00577
d D 5.4 86/04/04 11:24:27 bloom 23 22
c make cols an alias for columns
e
s 00005/00000/00573
d D 5.3 86/01/09 19:56:30 karels 22 20
c add "stty size" ala "stty speed"
e
s 00004/00000/00573
d R 5.3 86/01/09 16:00:19 karels 21 20
c add "stty size" ala "stty speed"
e
s 00003/00000/00570
d D 5.2 85/08/13 05:38:51 lepreau 20 18
c add PASS8: pass all 8 bits of input
e
s 00002/00000/00570
d R 5.2 85/08/13 05:26:36 lepreau 19 18
c add PASS8: pass all 8 bits of input
e
s 00015/00002/00555
d D 5.1 85/05/02 14:46:09 dist 18 17
c Add copyright
e
s 00016/00001/00541
d D 4.15 85/02/20 11:27:28 bloom 17 16
c set and print window sizes
e
s 00006/00002/00536
d D 4.14 83/07/06 22:10:14 sam 16 13
c prettier
e
s 00002/00002/00536
d R 4.14 83/07/06 21:45:55 sam 15 13
c yet another old delta come back to haunt us
e
s 00003/00006/00532
d R 4.14 83/07/06 21:43:38 sam 14 13
c screwey
e
s 00275/00273/00263
d D 4.13 83/06/13 02:41:29 sam 13 12
c back to yesteryear (or how to go in a circle real hard)
e
s 00001/00002/00535
d D 4.12 83/02/08 12:38:32 mckusick 12 11
c fix as per Mike Odell
e
s 00001/00001/00536
d D 4.11 83/01/16 11:17:23 peter 11 10
c add space separating `crt' and `tostop' for `stty all'.
e
s 00276/00273/00261
d D 4.10 82/12/19 13:21:07 sam 10 9
c use new ioctl's
e
s 00003/00001/00531
d D 4.9 82/05/12 17:40:11 wnj 9 8
c added 9600 and 19200 to set and print
e
s 00000/00003/00532
d D 4.8 82/05/07 17:36:29 mckusick 8 7
c get rid of LINTRUP
e
s 00008/00000/00527
d D 4.7 81/07/18 16:46:36 root 7 6
c add decctq and noflsh printing and setting
e
s 00001/00001/00526
d D 4.6 81/07/08 18:48:39 root 6 5
c fix typo
e
s 00001/00001/00526
d D 4.5 81/07/08 18:46:08 root 5 4
c fix per reeves
e
s 00016/00001/00511
d D 4.4 81/05/18 11:57:28 root 4 3
c re-insert decctlq
e
s 00001/00001/00511
d D 4.3 81/05/18 01:23:42 wnj 3 2
c fix bug per hek
e
s 00002/00002/00510
d D 4.2 80/10/11 23:39:51 bill 2 1
c newcrt->crt
e
s 00512/00000/00000
d D 4.1 80/10/01 18:33:31 bill 1 0
c date and time created 80/10/01 18:33:31 by bill
e
u
U
t
T
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 18
I 13
#ifndef lint
E 13
I 1
D 18
static char *sccsid ="%W% (Berkeley) %G%";
I 13
#endif
E 18
I 18
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 18
E 13
/*
 * set teletype modes
 */

#include <stdio.h>
D 17
#include <sgtty.h>
E 17
I 17
#include <sys/ioctl.h>
E 17

D 10
struct
{
E 10
I 10
D 13
struct {
E 13
I 13
struct
{
E 13
E 10
	char	*string;
	int	speed;
} speeds[] = {
D 10
	"0",	B0,
	"50",	B50,
	"75",	B75,
	"110",	B110,
	"134",	B134,
	"134.5",B134,
	"150",	B150,
	"200",	B200,
	"300",	B300,
	"600",	B600,
	"1200",	B1200,
	"1800",	B1800,
	"2400",	B2400,
	"4800",	B4800,
	"9600",	B9600,
	"exta",	EXTA,
I 9
	"19200", EXTA,
E 9
	"extb",	EXTB,
I 9
	"38400", EXTB,
E 9
	0,
E 10
I 10
D 13
	{ "0",		B0 },
	{ "50",		B50 },
	{ "75",		B75 },
	{ "110",	B110 },
	{ "134",	B134 },
	{ "134.5",	B134 },
	{ "150",	B150 },
	{ "200",	B200 },
	{ "300",	B300 },
	{ "600",	B600 },
	{ "1200",	B1200 },
	{ "1800",	B1800 },
	{ "2400",	B2400 },
	{ "4800",	B4800 },
	{ "9600",	B9600 },
	{ "exta",	EXTA },
	{ "19200",	EXTA },
	{ "extb",	EXTB },
	{ "38400",	EXTB },
	{ 0 },
E 13
I 13
	"0",	B0,
	"50",	B50,
	"75",	B75,
	"110",	B110,
	"134",	B134,
	"134.5",B134,
	"150",	B150,
	"200",	B200,
	"300",	B300,
	"600",	B600,
	"1200",	B1200,
	"1800",	B1800,
	"2400",	B2400,
	"4800",	B4800,
	"9600",	B9600,
	"exta",	EXTA,
	"19200", EXTA,
	"extb",	EXTB,
	"38400", EXTB,
	0,
E 13
E 10
};
D 10
struct
{
E 10
I 10
D 13

struct {
E 13
I 13
struct
{
E 13
E 10
	char	*string;
D 10
	int	set;
	int	reset;
	int	lset;
	int	lreset;
E 10
I 10
D 13
	long	set;
	long	reset;
E 13
I 13
	int	set;
	int	reset;
	int	lset;
	int	lreset;
E 13
E 10
} modes[] = {
D 10
	"even",		EVENP, 0, 0, 0,
	"-even",	0, EVENP, 0, 0,
	"odd",		ODDP, 0, 0, 0,
	"-odd",		0, ODDP, 0, 0,
	"raw",		RAW, 0, 0, 0,
	"-raw",		0, RAW, 0, 0,
	"cooked",	0, RAW, 0, 0,
	"-nl",		CRMOD, 0, 0, 0,
	"nl",		0, CRMOD, 0, 0,
	"echo",		ECHO, 0, 0, 0,
	"-echo",	0, ECHO, 0, 0,
	"LCASE",	LCASE, 0, 0, 0,
	"lcase",	LCASE, 0, 0, 0,
	"-LCASE",	0, LCASE, 0, 0,
	"-lcase",	0, LCASE, 0, 0,
	"-tabs",	XTABS, 0, 0, 0,
	"tabs",		0, XTABS, 0, 0,
	"tandem",	TANDEM, 0, 0, 0,
	"-tandem",	0, TANDEM, 0, 0,
	"cbreak",	CBREAK, 0, 0, 0,
	"-cbreak",	0, CBREAK, 0, 0,
	"cr0",		CR0, CR3, 0, 0,
	"cr1",		CR1, CR3, 0, 0,
	"cr2",		CR2, CR3, 0, 0,
	"cr3",		CR3, CR3, 0, 0,
	"tab0",		TAB0, XTABS, 0, 0,
	"tab1",		TAB1, XTABS, 0, 0,
	"tab2",		TAB2, XTABS, 0, 0,
	"nl0",		NL0, NL3, 0, 0,
	"nl1",		NL1, NL3, 0, 0,
	"nl2",		NL2, NL3, 0, 0,
	"nl3",		NL3, NL3, 0, 0,
	"ff0",		FF0, FF1, 0, 0,
	"ff1",		FF1, FF1, 0, 0,
	"bs0",		BS0, BS1, 0, 0,
	"bs1",		BS1, BS1, 0, 0,
	"33",		CR1, ALLDELAY, 0, 0,
	"tty33",	CR1, ALLDELAY, 0, 0,
	"37",		FF1+CR2+TAB1+NL1, ALLDELAY, 0, 0,
	"tty37",	FF1+CR2+TAB1+NL1, ALLDELAY, 0, 0,
	"05",		NL2, ALLDELAY, 0, 0,
	"vt05",		NL2, ALLDELAY, 0, 0,
	"tn",		CR1, ALLDELAY, 0, 0,
	"tn300",	CR1, ALLDELAY, 0, 0,
	"ti",		CR2, ALLDELAY, 0, 0,
	"ti700",	CR2, ALLDELAY, 0, 0,
	"tek",		FF1, ALLDELAY, 0, 0,
	"crtbs",	0, 0, LCRTBS, LPRTERA,
	"-crtbs",	0, 0, 0, LCRTBS,
	"prterase",	0, 0, LPRTERA, LCRTBS+LCRTKIL+LCRTERA,
	"-prterase",	0, 0, 0, LPRTERA,
	"crterase",	0, 0, LCRTERA, LPRTERA,
	"-crterase",	0, 0, 0, LCRTERA,
	"crtkill",	0, 0, LCRTKIL, LPRTERA,
	"-crtkill",	0, 0, 0, LCRTKIL,
	"tilde",	0, 0, LTILDE, 0,
	"-tilde",	0, 0, 0, LTILDE,
	"mdmbuf",	0, 0, LMDMBUF, 0,
	"-mdmbuf",	0, 0, 0, LMDMBUF,
	"litout",	0, 0, LLITOUT, 0,
	"-litout",	0, 0, 0, LLITOUT,
	"tostop",	0, 0, LTOSTOP, 0,
	"-tostop",	0, 0, 0, LTOSTOP,
	"flusho",	0, 0, LFLUSHO, 0,
	"-flusho",	0, 0, 0, LFLUSHO,
	"nohang",	0, 0, LNOHANG, 0,
	"-nohang",	0, 0, 0, LNOHANG,
	"etxack",	0, 0, LETXACK, 0,
	"-etxack",	0, 0, 0, LETXACK,
D 8
	"intrup",	0, 0, LINTRUP, 0,
	"-intrup",	0, 0, 0, LINTRUP,
E 8
	"ctlecho",	0, 0, LCTLECH, 0,
	"-ctlecho",	0, 0, 0, LCTLECH,
	"pendin",	0, 0, LPENDIN, 0,
	"-pendin",	0, 0, 0, LPENDIN,
I 4
	"decctlq",	0, 0, LDECCTQ, 0,
	"-decctlq",	0, 0, 0, LDECCTQ,
I 7
	"noflsh",	0, 0, LNOFLSH, 0,
	"-noflsh",	0, 0, 0, LNOFLSH,
E 7
E 4
	0,
E 10
I 10
D 13
	{ "even",	EVENP,		0 },
	{ "-even",	0,		EVENP },
	{ "odd",	ODDP,		0 },
	{ "-odd",	0,		ODDP },
	{ "raw",	RAW,		0 },
	{ "-raw",	0,		RAW },
	{ "cooked",	0,		RAW },
	{ "-nl",	CRMOD,		0 },
	{ "nl",		0,		CRMOD },
	{ "echo",	ECHO,		0 },
	{ "-echo",	0,		ECHO },
	{ "LCASE",	LCASE,		0 },
	{ "lcase",	LCASE,		0 },
	{ "-LCASE",	0,		LCASE },
	{ "-lcase",	0,		LCASE },
	{ "-tabs",	XTABS,		0 },
	{ "tabs",	0,		XTABS },
	{ "tandem",	TANDEM,		0 },
	{ "-tandem",	0,		TANDEM },
	{ "cbreak",	CBREAK,		0 },
	{ "-cbreak",	0,		CBREAK },
	{ "cr0",	CR0,		CR3 },
	{ "cr1",	CR1,		CR3 },
	{ "cr2",	CR2,		CR3 },
	{ "cr3",	CR3,		CR3 },
	{ "tab0",	TAB0,		XTABS },
	{ "tab1",	TAB1,		XTABS },
	{ "tab2",	TAB2,		XTABS },
	{ "nl0",	NL0,		NL3 },
	{ "nl1",	NL1,		NL3 },
	{ "nl2",	NL2,		NL3 },
	{ "nl3",	NL3,		NL3 },
	{ "ff0",	FF0,		FF1 },
	{ "ff1",	FF1,		FF1 },
	{ "bs0",	BS0,		BS1 },
	{ "bs1",	BS1,		BS1 },
	{ "33",		CR1,		ALLDELAY },
	{ "tty33",	CR1,		ALLDELAY },
	{ "37",		FF1+CR2+TAB1+NL1, ALLDELAY },
	{ "tty37",	FF1+CR2+TAB1+NL1, ALLDELAY },
	{ "05",		NL2,		ALLDELAY },
	{ "vt05",	NL2,		ALLDELAY },
	{ "tn",		CR1,		ALLDELAY },
	{ "tn300",	CR1,		ALLDELAY },
	{ "ti",		CR2,		ALLDELAY },
	{ "ti700",	CR2,		ALLDELAY },
	{ "tek",	FF1,		ALLDELAY },
	{ "crtbs",	CRTBS,		PRTERA },
	{ "-crtbs",	0,		CRTBS },
	{ "prterase",	PRTERA,		CRTBS+CRTKIL+CRTERA },
	{ "-prterase",	0,		PRTERA },
	{ "crterase",	CRTERA,		PRTERA },
	{ "-crterase",	0,		CRTERA },
	{ "crtkill",	CRTKIL,		PRTERA },
	{ "-crtkill",	0,		CRTKIL },
	{ "tilde",	TILDE,		0 },
	{ "-tilde",	0,		TILDE },
	{ "mdmbuf",	MDMBUF,		0 },
	{ "-mdmbuf",	0,		MDMBUF },
	{ "litout",	LITOUT,		0 },
	{ "-litout",	0,		LITOUT },
	{ "tostop",	TOSTOP,		0 },
	{ "-tostop",	0,		TOSTOP },
	{ "flusho",	FLUSHO,		0 },
	{ "-flusho",	0,		FLUSHO },
	{ "nohang",	NOHANG,		0 },
	{ "-nohang",	0,		NOHANG },
E 13
I 13
	"even",		EVENP, 0, 0, 0,
	"-even",	0, EVENP, 0, 0,
	"odd",		ODDP, 0, 0, 0,
	"-odd",		0, ODDP, 0, 0,
	"raw",		RAW, 0, 0, 0,
	"-raw",		0, RAW, 0, 0,
	"cooked",	0, RAW, 0, 0,
	"-nl",		CRMOD, 0, 0, 0,
	"nl",		0, CRMOD, 0, 0,
	"echo",		ECHO, 0, 0, 0,
	"-echo",	0, ECHO, 0, 0,
	"LCASE",	LCASE, 0, 0, 0,
	"lcase",	LCASE, 0, 0, 0,
	"-LCASE",	0, LCASE, 0, 0,
	"-lcase",	0, LCASE, 0, 0,
	"-tabs",	XTABS, 0, 0, 0,
	"tabs",		0, XTABS, 0, 0,
	"tandem",	TANDEM, 0, 0, 0,
	"-tandem",	0, TANDEM, 0, 0,
	"cbreak",	CBREAK, 0, 0, 0,
	"-cbreak",	0, CBREAK, 0, 0,
	"cr0",		CR0, CR3, 0, 0,
	"cr1",		CR1, CR3, 0, 0,
	"cr2",		CR2, CR3, 0, 0,
	"cr3",		CR3, CR3, 0, 0,
	"tab0",		TAB0, XTABS, 0, 0,
	"tab1",		TAB1, XTABS, 0, 0,
	"tab2",		TAB2, XTABS, 0, 0,
	"nl0",		NL0, NL3, 0, 0,
	"nl1",		NL1, NL3, 0, 0,
	"nl2",		NL2, NL3, 0, 0,
	"nl3",		NL3, NL3, 0, 0,
	"ff0",		FF0, FF1, 0, 0,
	"ff1",		FF1, FF1, 0, 0,
	"bs0",		BS0, BS1, 0, 0,
	"bs1",		BS1, BS1, 0, 0,
	"33",		CR1, ALLDELAY, 0, 0,
	"tty33",	CR1, ALLDELAY, 0, 0,
	"37",		FF1+CR2+TAB1+NL1, ALLDELAY, 0, 0,
	"tty37",	FF1+CR2+TAB1+NL1, ALLDELAY, 0, 0,
	"05",		NL2, ALLDELAY, 0, 0,
	"vt05",		NL2, ALLDELAY, 0, 0,
	"tn",		CR1, ALLDELAY, 0, 0,
	"tn300",	CR1, ALLDELAY, 0, 0,
	"ti",		CR2, ALLDELAY, 0, 0,
	"ti700",	CR2, ALLDELAY, 0, 0,
	"tek",		FF1, ALLDELAY, 0, 0,
	"crtbs",	0, 0, LCRTBS, LPRTERA,
	"-crtbs",	0, 0, 0, LCRTBS,
	"prterase",	0, 0, LPRTERA, LCRTBS+LCRTKIL+LCRTERA,
	"-prterase",	0, 0, 0, LPRTERA,
	"crterase",	0, 0, LCRTERA, LPRTERA,
	"-crterase",	0, 0, 0, LCRTERA,
	"crtkill",	0, 0, LCRTKIL, LPRTERA,
	"-crtkill",	0, 0, 0, LCRTKIL,
	"tilde",	0, 0, LTILDE, 0,
	"-tilde",	0, 0, 0, LTILDE,
	"mdmbuf",	0, 0, LMDMBUF, 0,
	"-mdmbuf",	0, 0, 0, LMDMBUF,
	"litout",	0, 0, LLITOUT, 0,
	"-litout",	0, 0, 0, LLITOUT,
I 20
	"pass8",	0, 0, LPASS8, 0,
	"-pass8",	0, 0, 0, LPASS8,
I 25
	"koi",		0, 0, LKOI, 0,
	"-koi",		0, 0, 0, LKOI,
	"koi7",		0, 0, LKOI, LPASS8,
	"koi8",		0, 0, LKOI+LPASS8, 0,
E 25
E 20
	"tostop",	0, 0, LTOSTOP, 0,
	"-tostop",	0, 0, 0, LTOSTOP,
	"flusho",	0, 0, LFLUSHO, 0,
	"-flusho",	0, 0, 0, LFLUSHO,
	"nohang",	0, 0, LNOHANG, 0,
	"-nohang",	0, 0, 0, LNOHANG,
E 13
#ifdef notdef
D 13
	{ "etxack",	ETXACK,		0 },
	{ "-etxack",	0,		ETXACK },
E 13
I 13
	"etxack",	0, 0, LETXACK, 0,
	"-etxack",	0, 0, 0, LETXACK,
E 13
#endif
D 13
	{ "ctlecho",	CTLECH,		0 },
	{ "-ctlecho",	0,		CTLECH },
	{ "pendin",	PENDIN,		0 },
	{ "-pendin",	0,		PENDIN },
	{ "decctlq",	DECCTQ,		0 },
	{ "-decctlq",	0,		DECCTQ },
	{ "noflsh",	NOFLSH,		0 },
	{ "-noflsh",	0,		NOFLSH },
	{ 0 },
E 13
I 13
	"ctlecho",	0, 0, LCTLECH, 0,
	"-ctlecho",	0, 0, 0, LCTLECH,
	"pendin",	0, 0, LPENDIN, 0,
	"-pendin",	0, 0, 0, LPENDIN,
	"decctlq",	0, 0, LDECCTQ, 0,
	"-decctlq",	0, 0, 0, LDECCTQ,
	"noflsh",	0, 0, LNOFLSH, 0,
	"-noflsh",	0, 0, 0, LNOFLSH,
	0,
E 13
E 10
};

D 10
struct tchars tc;
struct ltchars ltc;
struct sgttyb mode;
int	lmode;
E 10
I 10
D 13
struct ttychars tc;
struct sgttyb sb;
long	flags;
E 13
I 13
struct tchars tc;
struct ltchars ltc;
struct sgttyb mode;
I 17
struct winsize win;
E 17
int	lmode;
E 13
E 10
int	oldisc, ldisc;

D 10
#define	CTRL(x)		('x'&037)

E 10
struct	special {
	char	*name;
	char	*cp;
	char	def;
} special[] = {
D 10
	"erase",	&mode.sg_erase,		CTRL(h),
	"kill",		&mode.sg_kill,		'@',
	"intr",		&tc.t_intrc,		0177,
	"quit",		&tc.t_quitc,		CTRL(\\\\),
	"start",	&tc.t_startc,		CTRL(q),
	"stop",		&tc.t_stopc,		CTRL(s),
	"eof",		&tc.t_eofc,		CTRL(d),
	"brk",		&tc.t_brkc,		0377,
	"susp",		&ltc.t_suspc,		CTRL(z),
	"dsusp",	&ltc.t_dsuspc,		CTRL(y),
	"rprnt",	&ltc.t_rprntc,		CTRL(r),
	"flush",	&ltc.t_flushc,		CTRL(o),
	"werase",	&ltc.t_werasc,		CTRL(w),
	"lnext",	&ltc.t_lnextc,		CTRL(v),
E 10
I 10
D 13
	{ "erase",	&tc.tc_erase,		CERASE },
	{ "kill",	&tc.tc_kill,		CKILL },
	{ "intr",	&tc.tc_intrc,		CINTR },
	{ "quit",	&tc.tc_quitc,		CQUIT },
	{ "start",	&tc.tc_startc,		CSTART },
	{ "stop",	&tc.tc_stopc,		CSTOP },
	{ "eof",	&tc.tc_eofc,		CEOF },
	{ "brk",	&tc.tc_brkc,		CBRK },
	{ "susp",	&tc.tc_suspc,		CSUSP },
	{ "dsusp",	&tc.tc_dsuspc,		CDSUSP },
	{ "rprnt",	&tc.tc_rprntc,		CRPRNT },
	{ "flush",	&tc.tc_flushc,		CFLUSH },
	{ "werase",	&tc.tc_werasc,		CWERASE },
	{ "lnext",	&tc.tc_lnextc,		CLNEXT },
E 13
I 13
	"erase",	&mode.sg_erase,		CERASE,
	"kill",		&mode.sg_kill,		CKILL,
	"intr",		&tc.t_intrc,		CINTR,
	"quit",		&tc.t_quitc,		CQUIT,
	"start",	&tc.t_startc,		CSTART,
	"stop",		&tc.t_stopc,		CSTOP,
	"eof",		&tc.t_eofc,		CEOF,
	"brk",		&tc.t_brkc,		CBRK,
	"susp",		&ltc.t_suspc,		CSUSP,
	"dsusp",	&ltc.t_dsuspc,		CDSUSP,
	"rprnt",	&ltc.t_rprntc,		CRPRNT,
	"flush",	&ltc.t_flushc,		CFLUSH,
	"werase",	&ltc.t_werasc,		CWERASE,
	"lnext",	&ltc.t_lnextc,		CLNEXT,
E 13
E 10
	0
};
char	*arg;

int	argc;
char	**argv;
I 10
D 13

E 13
E 10
main(iargc, iargv)
D 10
char	**iargv;
E 10
I 10
D 13
	int iargc;
	char *iargv[];
E 13
I 13
char	**iargv;
E 13
E 10
{
	int i;
	register struct special *sp;
	char obuf[BUFSIZ];

	setbuf(stderr, obuf);
	argc = iargc;
	argv = iargv;
D 10
	gtty(1, &mode);
E 10
I 10
D 13
	ioctl(1, TIOCCGET, (char *)&tc);
	ioctl(1, TIOCGET, (char *)&flags);
E 13
I 13
	ioctl(1, TIOCGETP, &mode);
E 13
E 10
	ioctl(1, TIOCGETD, &ldisc);
I 10
D 13
#ifndef notdef
	ioctl(1, TIOCGETP, (char *)&sb);
#endif
E 13
E 10
	oldisc = ldisc;
D 10
	ioctl(1, TIOCGETC, &tc);
	ioctl(1, TIOCLGET, &lmode);
	ioctl(1, TIOCGLTC, &ltc);
	if(argc == 1) {
E 10
I 10
D 13
	if (argc == 1) {
E 13
I 13
	ioctl(1, TIOCGETC, &tc);
	ioctl(1, TIOCLGET, &lmode);
	ioctl(1, TIOCGLTC, &ltc);
I 17
	ioctl(1, TIOCGWINSZ, &win);
E 17
	if(argc == 1) {
E 13
E 10
		prmodes(0);
		exit(0);
	}
	if (argc == 2 && !strcmp(argv[1], "all")) {
		prmodes(1);
		exit(0);
	}
	if (argc == 2 && !strcmp(argv[1], "everything")) {
		prmodes(2);
		exit(0);
	}
D 10
/*
	if (argc == 2 && !strcmp(argv[1], "all")) {
		prmodes(2);
		exit(0);
	}
*/
	while(--argc > 0) {
E 10
I 10
D 13
	while (--argc > 0) {
E 13
I 13
/*
	if (argc == 2 && !strcmp(argv[1], "all")) {
		prmodes(2);
		exit(0);
	}
*/
	while(--argc > 0) {
E 13
E 10
		arg = *++argv;
D 10
		if (eq("ek")){
			mode.sg_erase = '#';
			mode.sg_kill = '@';
E 10
I 10
D 13
		if (eq("ek")) {
			tc.tc_erase = '#';
			tc.tc_kill = '@';
E 13
I 13
		if (eq("ek")){
			mode.sg_erase = '#';
			mode.sg_kill = '@';
E 13
E 10
			continue;
		}
D 10
		if (eq("new")){
E 10
I 10
D 13
		if (eq("new")) {
E 13
I 13
		if (eq("new")){
E 13
E 10
			ldisc = NTTYDISC;
D 10
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 10
I 10
D 13
			if (ioctl(1, TIOCSETD, &ldisc) < 0)
E 13
I 13
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 13
E 10
				perror("ioctl");
			continue;
		}
D 10
		if (eq("newcrt")){
E 10
I 10
D 13
		if (eq("newcrt")) {
E 13
I 13
		if (eq("newcrt")){
E 13
E 10
			ldisc = NTTYDISC;
D 10
			lmode &= ~LPRTERA;
			lmode |= LCRTBS|LCTLECH;
			if (mode.sg_ospeed >= B1200)
				lmode |= LCRTERA|LCRTKIL;
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 10
I 10
D 13
			flags &= ~PRTERA;
			flags |= CRTBS|CTLECH;
			if (sb.sg_ospeed >= B1200)
				flags |= CRTERA|CRTKIL;
			if (ioctl(1, TIOCSETD, &ldisc) < 0)
E 13
I 13
			lmode &= ~LPRTERA;
			lmode |= LCRTBS|LCTLECH;
			if (mode.sg_ospeed >= B1200)
				lmode |= LCRTERA|LCRTKIL;
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 13
E 10
				perror("ioctl");
			continue;
		}
D 10
		if (eq("crt")){
			lmode &= ~LPRTERA;
			lmode |= LCRTBS|LCTLECH;
			if (mode.sg_ospeed >= B1200)
				lmode |= LCRTERA|LCRTKIL;
E 10
I 10
D 13
		if (eq("crt")) {
			flags &= ~PRTERA;
			flags |= CRTBS|CTLECH;
			if (sb.sg_ospeed >= B1200)
				flags |= CRTERA|CRTKIL;
E 13
I 13
		if (eq("crt")){
			lmode &= ~LPRTERA;
			lmode |= LCRTBS|LCTLECH;
			if (mode.sg_ospeed >= B1200)
				lmode |= LCRTERA|LCRTKIL;
E 13
E 10
			continue;
		}
D 10
		if (eq("old")){
			ldisc = 0;
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 10
I 10
D 13
		if (eq("old")) {
			ldisc = OTTYDISC;
			if (ioctl(1, TIOCSETD, &ldisc) < 0)
E 13
I 13
		if (eq("old")){
			ldisc = 0;
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 13
E 10
				perror("ioctl");
			continue;
		}
I 4
D 10
		if (eq("dec")){
			mode.sg_erase = 0177;
			mode.sg_kill = CTRL(u);
			tc.t_intrc = CTRL(c);
E 10
I 10
D 13
		if (eq("dec")) {
			tc.tc_erase = 0177;
			tc.tc_kill = CTRL(u);
			tc.tc_intrc = CTRL(c);
E 13
I 13
		if (eq("dec")){
			mode.sg_erase = 0177;
D 24
			mode.sg_kill = CTRL(u);
			tc.t_intrc = CTRL(c);
E 24
I 24
			mode.sg_kill = CKILL;
			tc.t_intrc = CINTR;
E 24
E 13
E 10
			ldisc = NTTYDISC;
D 10
			lmode &= ~LPRTERA;
			lmode |= LCRTBS|LCTLECH|LDECCTQ;
			if (mode.sg_ospeed >= B1200)
				lmode |= LCRTERA|LCRTKIL;
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 10
I 10
D 13
			flags &= ~PRTERA;
			flags |= CRTBS|CTLECH|DECCTQ;
			if (sb.sg_ospeed >= B1200)
				flags |= CRTERA|CRTKIL;
			if (ioctl(1, TIOCSETD, &ldisc) < 0)
E 13
I 13
			lmode &= ~LPRTERA;
			lmode |= LCRTBS|LCTLECH|LDECCTQ;
			if (mode.sg_ospeed >= B1200)
				lmode |= LCRTERA|LCRTKIL;
			if (ioctl(1, TIOCSETD, &ldisc)<0)
E 13
E 10
				perror("ioctl");
			continue;
		}
E 4
		for (sp = special; sp->name; sp++)
			if (eq(sp->name)) {
				if (--argc == 0)
					goto done;
				if (**++argv == 'u')
					*sp->cp = 0377;
				else if (**argv == '^')
D 3
					*sp->cp = (*(argv[1]) == '?') ?
E 3
I 3
D 4
					*sp->cp = ((*argv)[1] == '?') ?
E 4
I 4
D 5
					*sp->cp = (*(argv[1]) == '?') ?
E 5
I 5
D 6
					*sp->cp = (*argv)[1] == '?') ?
E 6
I 6
					*sp->cp = ((*argv)[1] == '?') ?
E 6
E 5
E 4
E 3
					    0177 : (*argv)[1] & 037;
				else
					*sp->cp = **argv;
				goto cont;
			}
		if (eq("gspeed")) {
D 10
			mode.sg_ispeed = B300;
			mode.sg_ospeed = B9600;
E 10
I 10
D 13
			sb.sg_ispeed = B300;
			sb.sg_ospeed = B9600;
E 13
I 13
			mode.sg_ispeed = B300;
			mode.sg_ospeed = B9600;
E 13
E 10
			continue;
		}
		if (eq("hup")) {
D 10
			ioctl(1, TIOCHPCL, NULL);
E 10
I 10
D 13
			if (ioctl(1, TIOCHPCL, NULL) < 0)
				perror("ioctl");
E 13
I 13
			ioctl(1, TIOCHPCL, NULL);
E 13
E 10
			continue;
		}
I 17
		if (eq("rows")) {
			if (--argc == 0)
				goto done;
			win.ws_row = atoi(*++argv);
		}
D 23
		if (eq("columns")) {
E 23
I 23
		if (eq("cols") || eq("columns")) {
E 23
			if (--argc == 0)
				goto done;
			win.ws_col = atoi(*++argv);
		}
I 22
		if (eq("size")) {
			ioctl(open("/dev/tty", 0), TIOCGWINSZ, &win);
			printf("%d %d\n", win.ws_row, win.ws_col);
			exit(0);
		}
E 22
E 17
D 10
		for(i=0; speeds[i].string; i++)
			if(eq(speeds[i].string)) {
				mode.sg_ispeed = mode.sg_ospeed = speeds[i].speed;
E 10
I 10
D 13
		for (i = 0; speeds[i].string; i++)
			if (eq(speeds[i].string)) {
				sb.sg_ispeed = sb.sg_ospeed = speeds[i].speed;
E 13
I 13
		for(i=0; speeds[i].string; i++)
			if(eq(speeds[i].string)) {
				mode.sg_ispeed = mode.sg_ospeed = speeds[i].speed;
E 13
E 10
				goto cont;
			}
		if (eq("speed")) {
D 10
			gtty(open("/dev/tty", 0), &mode);
			for(i=0; speeds[i].string; i++)
				if (mode.sg_ospeed == speeds[i].speed) {
E 10
I 10
D 13
			int fd = open("/dev/tty", 0);

			if (fd < 0) {
				perror("open");
				exit(1);
			}
			ioctl(fd, TIOCGETP, &sb);
			for (i = 0; speeds[i].string; i++)
				if (sb.sg_ospeed == speeds[i].speed) {
E 13
I 13
			ioctl(open("/dev/tty", 0), TIOCGETP, &mode);
			for(i=0; speeds[i].string; i++)
				if (mode.sg_ospeed == speeds[i].speed) {
E 13
E 10
					printf("%s\n", speeds[i].string);
					exit(0);
				}
			printf("unknown\n");
			exit(1);
		}
D 10
		for(i=0; modes[i].string; i++)
			if(eq(modes[i].string)) {
				mode.sg_flags &= ~modes[i].reset;
				mode.sg_flags |= modes[i].set;
				lmode &= ~modes[i].lreset;
				lmode |= modes[i].lset;
E 10
I 10
D 13
		for (i = 0; modes[i].string; i++)
			if (eq(modes[i].string)) {
				flags &= ~modes[i].reset;
				flags |= modes[i].set;
E 13
I 13
		for(i=0; modes[i].string; i++)
			if(eq(modes[i].string)) {
				mode.sg_flags &= ~modes[i].reset;
				mode.sg_flags |= modes[i].set;
				lmode &= ~modes[i].lreset;
				lmode |= modes[i].lset;
E 13
E 10
			}
D 10
		if(arg)
E 10
I 10
D 13
		if (arg)
E 13
I 13
		if(arg)
E 13
E 10
			fprintf(stderr,"unknown mode: %s\n", arg);
cont:
		;
	}
done:
D 10
	ioctl(1, TIOCSETN, &mode);
	ioctl(1, TIOCSETC, &tc);
	ioctl(1, TIOCSLTC, &ltc);
	ioctl(1, TIOCLSET, &lmode);
E 10
I 10
D 13
#ifndef notdef
	ioctl(1, TIOCSETN, &sb);
#endif
	ioctl(1, TIOCSET, &flags);
	ioctl(1, TIOCCSET, &tc);
E 13
I 13
	ioctl(1, TIOCSETN, &mode);
	ioctl(1, TIOCSETC, &tc);
	ioctl(1, TIOCSLTC, &ltc);
	ioctl(1, TIOCLSET, &lmode);
I 17
	ioctl(1, TIOCSWINSZ, &win);
E 17
E 13
E 10
}

eq(string)
D 10
char *string;
E 10
I 10
D 13
	char *string;
E 13
I 13
char *string;
E 13
E 10
{
	int i;

D 10
	if(!arg)
		return(0);
E 10
I 10
D 13
	if (!arg)
		return (0);
E 13
I 13
	if(!arg)
		return(0);
E 13
E 10
	i = 0;
loop:
D 10
	if(arg[i] != string[i])
E 10
I 10
D 13
	if (arg[i] != string[i])
E 13
I 13
	if(arg[i] != string[i])
E 13
E 10
		return(0);
D 10
	if(arg[i++] != '\0')
E 10
I 10
D 13
	if (arg[i++] != '\0')
E 13
I 13
	if(arg[i++] != '\0')
E 13
E 10
		goto loop;
	arg = 0;
D 10
	return(1);
E 10
I 10
D 13
	return (1);
E 13
I 13
	return(1);
E 13
E 10
}

prmodes(all)
I 10
D 13
	int all;
E 13
E 10
{
	register m;
	int any;

D 10
	if(ldisc==NETLDISC)
E 10
I 10
D 13
	if (ldisc == NETLDISC)
E 13
I 13
	if(ldisc==NETLDISC)
E 13
E 10
		fprintf(stderr, "net discipline, ");
D 10
	else if(ldisc==NTTYDISC)
E 10
I 10
D 13
	else if (ldisc == NTTYDISC)
E 13
I 13
	else if(ldisc==NTTYDISC)
E 13
E 10
		fprintf(stderr, "new tty, ");
D 10
	else if(all==2)
E 10
I 10
D 13
	else if (all == 2)
E 13
I 13
	else if(all==2)
E 13
E 10
		fprintf(stderr, "old tty, ");
D 10
	if(mode.sg_ispeed != mode.sg_ospeed) {
		prspeed("input speed ", mode.sg_ispeed);
		prspeed("output speed ", mode.sg_ospeed);
E 10
I 10
D 13
	if(sb.sg_ispeed != sb.sg_ospeed) {
		prspeed("input speed ", sb.sg_ispeed);
		prspeed("output speed ", sb.sg_ospeed);
E 13
I 13
	if(mode.sg_ispeed != mode.sg_ospeed) {
		prspeed("input speed ", mode.sg_ispeed);
		prspeed("output speed ", mode.sg_ospeed);
E 13
E 10
	} else
D 10
		prspeed("speed ", mode.sg_ispeed);
	fprintf(stderr, all==2 ? "\n" : "; ");
	m = mode.sg_flags;
	if(all==2 || (m&(EVENP|ODDP))!=(EVENP|ODDP)) {
		if(m & EVENP)	fprintf(stderr,"even ");
		if(m & ODDP)	fprintf(stderr,"odd ");
E 10
I 10
D 13
		prspeed("speed ", sb.sg_ispeed);
	fprintf(stderr, all == 2 ? "\n" : "; ");
	m = flags;
	if (all == 2 || (m&(EVENP|ODDP)) != (EVENP|ODDP)) {
		if (m & EVENP)
			fprintf(stderr,"even ");
		if (m & ODDP)
			fprintf(stderr,"odd ");
E 13
I 13
		prspeed("speed ", mode.sg_ispeed);
I 17
	if (all)
		fprintf(stderr, ", %d rows, %d columns", win.ws_row, win.ws_col);
E 17
	fprintf(stderr, all==2 ? "\n" : "; ");
	m = mode.sg_flags;
	if(all==2 || (m&(EVENP|ODDP))!=(EVENP|ODDP)) {
		if(m & EVENP)	fprintf(stderr,"even ");
		if(m & ODDP)	fprintf(stderr,"odd ");
E 13
E 10
	}
D 10
	if(all==2 || m&RAW)
		fprintf(stderr,"-raw "+((m&RAW)!=0));
	if(all==2 || (m&CRMOD)==0)
		fprintf(stderr,"-nl "+((m&CRMOD)==0));
	if(all==2 || (m&ECHO)==0)
		fprintf(stderr,"-echo "+((m&ECHO)!=0));
	if(all==2 || (m&LCASE))
		fprintf(stderr,"-lcase "+((m&LCASE)!=0));
	if(all==2 || (m&TANDEM))
		fprintf(stderr,"-tandem "+((m&TANDEM)!=0));
	fprintf(stderr,"-tabs "+((m&XTABS)!=XTABS));
	if(all==2 || (m&CBREAK))
		fprintf(stderr,"-cbreak "+((m&CBREAK)!=0));
	if(all==2 || (m&NLDELAY))
		delay((m&NLDELAY)/NL1,	"nl");
	if ((m&TBDELAY)!=XTABS)
		delay((m&TBDELAY)/TAB1,	"tab");
	if(all==2 || (m&CRDELAY))
		delay((m&CRDELAY)/CR1,	"cr");
	if(all==2 || (m&VTDELAY))
		delay((m&VTDELAY)/FF1,	"ff");
	if(all==2 || (m&BSDELAY))
		delay((m&BSDELAY)/BS1,	"bs");
E 10
I 10
D 13
	if (all == 2 || m&RAW)
		fprintf(stderr,"-raw " + ((m&RAW) != 0));
	if (all == 2 || (m&CRMOD) == 0)
		fprintf(stderr,"-nl " + ((m&CRMOD) == 0));
	if (all == 2 || (m&ECHO) == 0)
		fprintf(stderr,"-echo " + ((m&ECHO) != 0));
	if (all == 2 || m&LCASE)
		fprintf(stderr,"-lcase " + ((m&LCASE) != 0));
	if (all == 2 || m&TANDEM)
		fprintf(stderr,"-tandem " + ((m&TANDEM) != 0));
	fprintf(stderr,"-tabs " + ((m&XTABS) != XTABS));
	if (all == 2 || m&CBREAK)
		fprintf(stderr,"-cbreak " + ((m&CBREAK) != 0));
	if (all == 2 || m&NLDELAY)
		delay((m&NLDELAY) / NL1, "nl");
	if ((m&TBDELAY) != XTABS)
		delay((m&TBDELAY)/ TAB1, "tab");
	if (all == 2 || m&CRDELAY)
		delay((m&CRDELAY) / CR1, "cr");
	if (all == 2 || m&VTDELAY)
		delay((m&VTDELAY) / FF1, "ff");
	if (all == 2 || m&BSDELAY)
		delay((m&BSDELAY) / BS1, "bs");
E 13
I 13
	if(all==2 || m&RAW)
		fprintf(stderr,"-raw "+((m&RAW)!=0));
	if(all==2 || (m&CRMOD)==0)
		fprintf(stderr,"-nl "+((m&CRMOD)==0));
	if(all==2 || (m&ECHO)==0)
		fprintf(stderr,"-echo "+((m&ECHO)!=0));
	if(all==2 || (m&LCASE))
		fprintf(stderr,"-lcase "+((m&LCASE)!=0));
	if(all==2 || (m&TANDEM))
		fprintf(stderr,"-tandem "+((m&TANDEM)!=0));
	fprintf(stderr,"-tabs "+((m&XTABS)!=XTABS));
	if(all==2 || (m&CBREAK))
		fprintf(stderr,"-cbreak "+((m&CBREAK)!=0));
	if(all==2 || (m&NLDELAY))
		delay((m&NLDELAY)/NL1,	"nl");
	if ((m&TBDELAY)!=XTABS)
		delay((m&TBDELAY)/TAB1,	"tab");
	if(all==2 || (m&CRDELAY))
		delay((m&CRDELAY)/CR1,	"cr");
	if(all==2 || (m&VTDELAY))
		delay((m&VTDELAY)/FF1,	"ff");
	if(all==2 || (m&BSDELAY))
		delay((m&BSDELAY)/BS1,	"bs");
E 13
E 10
	if (all)
		fprintf(stderr,"\n");
#define	lpit(what,str) \
D 10
	if (all==2||(lmode&what)) { \
		fprintf(stderr,str+((lmode&what)!=0)); any++; \
E 10
I 10
D 13
	if (all == 2 || flags&what) { \
		fprintf(stderr,str + ((flags&what) != 0)); any++; \
E 13
I 13
	if (all==2||(lmode&what)) { \
		fprintf(stderr,str+((lmode&what)!=0)); any++; \
E 13
E 10
	}
	if (ldisc == NTTYDISC) {
D 10
		int newcrt = (lmode&(LCTLECH|LCRTBS)) == (LCTLECH|LCRTBS) &&
		    (lmode&(LCRTERA|LCRTKIL)) ==
		      ((mode.sg_ospeed > B300) ? LCRTERA|LCRTKIL : 0);
E 10
I 10
D 13
		int newcrt = (flags&(CTLECH|CRTBS)) == (CTLECH|CRTBS) &&
		    (flags&(CRTERA|CRTKIL)) ==
		      ((sb.sg_ospeed > B300) ? CRTERA|CRTKIL : 0);
E 13
I 13
		int newcrt = (lmode&(LCTLECH|LCRTBS)) == (LCTLECH|LCRTBS) &&
		    (lmode&(LCRTERA|LCRTKIL)) ==
		      ((mode.sg_ospeed > B300) ? LCRTERA|LCRTKIL : 0);
I 16
		int nothing = 1;
E 16
E 13
E 10
		if (newcrt) {
D 10
			if (all==2)
D 2
				fprintf(stderr, "newcrt: (crtbs crterase crtkill ctlecho) ");
E 2
I 2
				fprintf(stderr, "crt: (crtbs crterase crtkill ctlecho) ");
E 2
			else
D 2
				fprintf(stderr, "newcrt ");
E 2
I 2
				fprintf(stderr, "crt ");
E 10
I 10
D 11
			fprintf(stderr, all != 2 ? "crt" :
E 11
I 11
D 13
			fprintf(stderr, all != 2 ? "crt " :
E 11
				 "crt: (crtbs crterase crtkill ctlecho) ");
E 13
I 13
			if (all==2)
				fprintf(stderr, "crt: (crtbs crterase crtkill ctlecho) ");
			else
				fprintf(stderr, "crt ");
E 13
E 10
E 2
			any++;
		} else {
D 10
			lpit(LCRTBS, "-crtbs ");
			lpit(LCRTERA, "-crterase ");
			lpit(LCRTKIL, "-crtkill ");
			lpit(LCTLECH, "-ctlecho ");
			lpit(LPRTERA, "-prterase ");
E 10
I 10
D 13
			lpit(CRTBS, "-crtbs ");
			lpit(CRTERA, "-crterase ");
			lpit(CRTKIL, "-crtkill ");
			lpit(CTLECH, "-ctlecho ");
			lpit(PRTERA, "-prterase ");
E 13
I 13
			lpit(LCRTBS, "-crtbs ");
			lpit(LCRTERA, "-crterase ");
			lpit(LCRTKIL, "-crtkill ");
			lpit(LCTLECH, "-ctlecho ");
			lpit(LPRTERA, "-prterase ");
E 13
E 10
		}
D 10
		lpit(LTOSTOP, "-tostop ");
D 8
		lpit(LINTRUP, "-intrup ");
E 8
		if (all==2) {
E 10
I 10
D 13
		lpit(TOSTOP, "-tostop ");
		if (all == 2) {
E 13
I 13
		lpit(LTOSTOP, "-tostop ");
		if (all==2) {
E 13
E 10
			fprintf(stderr, "\n");
			any = 0;
I 16
			nothing = 0;
E 16
		}
D 10
		lpit(LTILDE, "-tilde ");
		lpit(LFLUSHO, "-flusho ");
		lpit(LMDMBUF, "-mdmbuf ");
		lpit(LLITOUT, "-litout ");
		lpit(LNOHANG, "-nohang ");
E 10
I 10
D 13
		lpit(TILDE, "-tilde ");
		lpit(FLUSHO, "-flusho ");
		lpit(MDMBUF, "-mdmbuf ");
		lpit(LITOUT, "-litout ");
		lpit(NOHANG, "-nohang ");
E 13
I 13
		lpit(LTILDE, "-tilde ");
		lpit(LFLUSHO, "-flusho ");
		lpit(LMDMBUF, "-mdmbuf ");
		lpit(LLITOUT, "-litout ");
I 20
		lpit(LPASS8, "-pass8 ");
I 25
		lpit(LKOI, "-koi ");
E 25
E 20
		lpit(LNOHANG, "-nohang ");
E 13
E 10
I 7
		if (any) {
			fprintf(stderr,"\n");
			any = 0;
I 16
			nothing = 0;
E 16
		}
E 7
D 10
		lpit(LETXACK, "-etxack ");
		lpit(LPENDIN, "-pendin ");
I 7
		lpit(LDECCTQ, "-decctlq ");
		lpit(LNOFLSH, "-noflsh ");
E 10
I 10
#ifdef notdef
D 13
		lpit(ETXACK, "-etxack ");
E 13
I 13
		lpit(LETXACK, "-etxack ");
E 13
#endif
D 13
		lpit(PENDIN, "-pendin ");
		lpit(DECCTQ, "-decctlq ");
		lpit(NOFLSH, "-noflsh ");
E 13
I 13
		lpit(LPENDIN, "-pendin ");
		lpit(LDECCTQ, "-decctlq ");
		lpit(LNOFLSH, "-noflsh ");
E 13
E 10
E 7
D 16
		if (any)
E 16
I 16
		if (any || nothing)
E 16
			fprintf(stderr,"\n");
	} else if (!all)
		fprintf(stderr,"\n");
	if (all) {
		switch (ldisc) {

		case 0:
			fprintf(stderr,"\
erase  kill   intr   quit   stop   eof\
\n");
D 10
			pcol(mode.sg_erase, -1);
			pcol(mode.sg_kill, -1);
			pcol(tc.t_intrc, -1);
			pcol(tc.t_quitc, -1);
			pcol(tc.t_stopc, tc.t_startc);
			pcol(tc.t_eofc, tc.t_brkc);
E 10
I 10
D 13
			pcol(tc.tc_erase, -1);
			pcol(tc.tc_kill, -1);
			pcol(tc.tc_intrc, -1);
			pcol(tc.tc_quitc, -1);
			pcol(tc.tc_stopc, tc.tc_startc);
			pcol(tc.tc_eofc, tc.tc_brkc);
E 13
I 13
			pcol(mode.sg_erase, -1);
			pcol(mode.sg_kill, -1);
			pcol(tc.t_intrc, -1);
			pcol(tc.t_quitc, -1);
			pcol(tc.t_stopc, tc.t_startc);
			pcol(tc.t_eofc, tc.t_brkc);
E 13
E 10
			fprintf(stderr,"\n");
			break;

		case NTTYDISC:
			fprintf(stderr,"\
erase  kill   werase rprnt  flush  lnext  susp   intr   quit   stop   eof\
\n"); 
D 10
			pcol(mode.sg_erase, -1);
			pcol(mode.sg_kill, -1);
			pcol(ltc.t_werasc, -1);
			pcol(ltc.t_rprntc, -1);
			pcol(ltc.t_flushc, -1);
			pcol(ltc.t_lnextc, -1);
			pcol(ltc.t_suspc, ltc.t_dsuspc);
			pcol(tc.t_intrc, -1);
			pcol(tc.t_quitc, -1);
			pcol(tc.t_stopc, tc.t_startc);
			pcol(tc.t_eofc, tc.t_brkc);
E 10
I 10
D 13
			pcol(tc.tc_erase, -1);
			pcol(tc.tc_kill, -1);
			pcol(tc.tc_werasc, -1);
			pcol(tc.tc_rprntc, -1);
			pcol(tc.tc_flushc, -1);
			pcol(tc.tc_lnextc, -1);
			pcol(tc.tc_suspc, tc.tc_dsuspc);
			pcol(tc.tc_intrc, -1);
			pcol(tc.tc_quitc, -1);
			pcol(tc.tc_stopc, tc.tc_startc);
			pcol(tc.tc_eofc, tc.tc_brkc);
E 13
I 13
			pcol(mode.sg_erase, -1);
			pcol(mode.sg_kill, -1);
			pcol(ltc.t_werasc, -1);
			pcol(ltc.t_rprntc, -1);
			pcol(ltc.t_flushc, -1);
			pcol(ltc.t_lnextc, -1);
			pcol(ltc.t_suspc, ltc.t_dsuspc);
			pcol(tc.t_intrc, -1);
			pcol(tc.t_quitc, -1);
			pcol(tc.t_stopc, tc.t_startc);
			pcol(tc.t_eofc, tc.t_brkc);
E 13
E 10
			fprintf(stderr,"\n");
			break;
		}
	} else if (ldisc != NETLDISC) {
		register struct special *sp;
		int first = 1;
I 16

E 16
I 10
D 13

E 13
E 10
		for (sp = special; sp->name; sp++) {
			if ((*sp->cp&0377) != (sp->def&0377)) {
				pit(*sp->cp, sp->name, first ? "" : ", ");
				first = 0;
			};
D 10
			if (sp->cp == &tc.t_brkc && ldisc == 0)
E 10
I 10
D 13
			if (sp->cp == &tc.tc_brkc && ldisc == 0)
E 13
I 13
			if (sp->cp == &tc.t_brkc && ldisc == 0)
E 13
E 10
				break;
		}
D 12
		if (first == 0)
			fprintf(stderr, "\n");
E 12
I 12
D 13
		fprintf(stderr, "\n");
E 13
I 13
D 16
		if (first == 0)
E 16
I 16
		if (!first)
E 16
			fprintf(stderr, "\n");
E 13
E 12
	}
}

pcol(ch1, ch2)
	int ch1, ch2;
{
	int nout = 0;

	ch1 &= 0377;
	ch2 &= 0377;
	if (ch1 == ch2)
		ch2 = 0377;
	for (; ch1 != 0377 || ch2 != 0377; ch1 = ch2, ch2 = 0377) {
		if (ch1 == 0377)
			continue;
		if (ch1 & 0200) {
			fprintf(stderr, "M-");
			nout += 2;
			ch1 &= ~ 0200;
		}
		if (ch1 == 0177) {
			fprintf(stderr, "^");
			nout++;
			ch1 = '?';
		} else if (ch1 < ' ') {
			fprintf(stderr, "^");
			nout++;
			ch1 += '@';
		}
		fprintf(stderr, "%c", ch1);
		nout++;
		if (ch2 != 0377) {
			fprintf(stderr, "/");
			nout++;
		}
	}
	while (nout < 7) {
		fprintf(stderr, " ");
		nout++;
	}
}

pit(what, itsname, sep)
	unsigned what;
	char *itsname, *sep;
{

	what &= 0377;
	fprintf(stderr, "%s%s", sep, itsname);
	if (what == 0377) {
		fprintf(stderr, " <undef>");
		return;
	}
	fprintf(stderr, " = ");
	if (what & 0200) {
		fprintf(stderr, "M-");
		what &= ~ 0200;
	}
	if (what == 0177) {
		fprintf(stderr, "^");
		what = '?';
	} else if (what < ' ') {
		fprintf(stderr, "^");
		what += '@';
	}
	fprintf(stderr, "%c", what);
}

delay(m, s)
D 10
char *s;
E 10
I 10
D 13
	char *s;
E 13
I 13
char *s;
E 13
E 10
{

D 10
	if(m)
E 10
I 10
D 13
	if (m)
E 13
I 13
	if(m)
E 13
E 10
		fprintf(stderr,"%s%d ", s, m);
}

int	speed[] = {
D 9
	0,50,75,110,134,150,200,300,600,1200,1800,2400,4800,9600,0,0
E 9
I 9
	0,50,75,110,134,150,200,300,600,1200,1800,2400,4800,9600,19200,38400
E 9
};

prspeed(c, s)
char *c;
{

	fprintf(stderr,"%s%d baud",  c, speed[s]);
}
E 1
