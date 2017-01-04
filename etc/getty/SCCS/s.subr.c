h40316
s 00000/00000/00476
d D 5.7 04/12/08 04:15:13 msokolov 11 10
x 10
c I wrote all this code only to find out that the modem does not after all behave
c the way I thought. Back to smgetty.
e
s 00078/00000/00476
d D 5.6 04/12/07 23:43:24 msokolov 10 9
c smart modem support
e
s 00003/00001/00473
d D 5.5 03/03/22 18:44:24 msokolov 9 8
c Add PASS8 support (p8 boolean flag)
c This is necessary for 8-bit terminals as the default parity will screw them
e
s 00003/00000/00471
d D 5.4 86/01/07 15:10:07 mckusick 8 7
c set DECCTLQ on specifc lines with getty (from muller@nprdc.arpa)
e
s 00001/00000/00470
d D 5.3 85/10/18 17:39:27 mckusick 7 6
c update for 19200 baud (from Keith Muller)
e
s 00001/00001/00469
d D 5.2 85/05/04 16:37:13 edward 6 5
c '\377' not '\0377'
e
s 00008/00002/00462
d D 5.1 85/04/29 12:46:16 dist 5 4
c Add copyright
e
s 00054/00001/00410
d D 4.4 85/02/05 08:48:58 ralph 4 3
c added autobaud detection.
e
s 00003/00000/00408
d D 4.3 84/06/05 11:25:24 ralph 3 2
c make `ck' work by setting the bit.
e
s 00014/00007/00394
d D 4.2 83/07/07 03:32:48 kre 2 1
c fix delay numbers, and make '1', '2', and '3' simply
c select the equiv delay algorithm.
e
s 00401/00000/00000
d D 4.1 83/07/06 00:10:15 sam 1 0
c date and time created 83/07/06 00:10:15 by sam
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
#ifndef lint
D 5
static char sccsid[] = "%W% (Berkeley) %E%";
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

/*
 * Melbourne getty.
 */
#include <sgtty.h>
I 10
#include <syslog.h>
E 10
#include "gettytab.h"

extern	struct sgttyb tmode;
extern	struct tchars tc;
extern	struct ltchars ltc;

/*
 * Get a table entry.
 */
gettable(name, buf, area)
	char *name, *buf, *area;
{
	register struct gettystrs *sp;
	register struct gettynums *np;
	register struct gettyflags *fp;
	register n;

	hopcount = 0;		/* new lookup, start fresh */
	if (getent(buf, name) != 1)
		return;

	for (sp = gettystrs; sp->field; sp++)
		sp->value = getstr(sp->field, &area);
	for (np = gettynums; np->field; np++) {
		n = getnum(np->field);
		if (n == -1)
			np->set = 0;
		else {
			np->set = 1;
			np->value = n;
		}
	}
	for (fp = gettyflags; fp->field; fp++) {
		n = getflag(fp->field);
		if (n == -1)
			fp->set = 0;
		else {
			fp->set = 1;
			fp->value = n ^ fp->invrt;
		}
	}
}

gendefaults()
{
	register struct gettystrs *sp;
	register struct gettynums *np;
	register struct gettyflags *fp;

	for (sp = gettystrs; sp->field; sp++)
		if (sp->value)
			sp->defalt = sp->value;
	for (np = gettynums; np->field; np++)
		if (np->set)
			np->defalt = np->value;
	for (fp = gettyflags; fp->field; fp++)
		if (fp->set)
			fp->defalt = fp->value;
		else
			fp->defalt = fp->invrt;
}

setdefaults()
{
	register struct gettystrs *sp;
	register struct gettynums *np;
	register struct gettyflags *fp;

	for (sp = gettystrs; sp->field; sp++)
		if (!sp->value)
			sp->value = sp->defalt;
	for (np = gettynums; np->field; np++)
		if (!np->set)
			np->value = np->defalt;
	for (fp = gettyflags; fp->field; fp++)
		if (!fp->set)
			fp->value = fp->defalt;
}

static char **
charnames[] = {
	&ER, &KL, &IN, &QU, &XN, &XF, &ET, &BK,
	&SU, &DS, &RP, &FL, &WE, &LN, 0
};

static char *
charvars[] = {
	&tmode.sg_erase, &tmode.sg_kill, &tc.t_intrc,
	&tc.t_quitc, &tc.t_startc, &tc.t_stopc,
	&tc.t_eofc, &tc.t_brkc, &ltc.t_suspc,
	&ltc.t_dsuspc, &ltc.t_rprntc, &ltc.t_flushc,
	&ltc.t_werasc, &ltc.t_lnextc, 0
};

setchars()
{
	register int i;
	register char *p;

	for (i = 0; charnames[i]; i++) {
		p = *charnames[i];
		if (p && *p)
			*charvars[i] = *p;
		else
D 6
			*charvars[i] = '\0377';
E 6
I 6
			*charvars[i] = '\377';
E 6
	}
}

long
setflags(n)
{
	register long f;

	switch (n) {
	case 0:
		if (F0set)
			return(F0);
		break;
	case 1:
		if (F1set)
			return(F1);
		break;
	default:
		if (F2set)
			return(F2);
		break;
	}

	f = 0;

D 9
	if (AP)
E 9
I 9
	if (P8)
		f |= PASS8;
	else if (AP)
E 9
		f |= ANYP;
	else if (OP)
		f |= ODDP;
	else if (EP)
		f |= EVENP;

	if (UC)
		f |= LCASE;

	if (NL)
		f |= CRMOD;

	f |= delaybits();

	if (n == 1) {		/* read mode flags */
		if (RW)
			f |= RAW;
		else
			f |= CBREAK;
		return (f);
	}

	if (!HT)
		f |= XTABS;

	if (n == 0)
		return (f);

	if (CB)
		f |= CRTBS;

	if (CE)
		f |= CRTERA;

I 3
	if (CK)
		f |= CRTKIL;

E 3
	if (PE)
		f |= PRTERA;

	if (EC)
		f |= ECHO;

	if (XC)
		f |= CTLECH;

I 8
	if (DX)
		f |= DECCTQ;

E 8
	return (f);
}

struct delayval {
	unsigned	delay;		/* delay in ms */
	int		bits;
};

/*
 * below are random guesses, I can't be bothered checking
 */

struct delayval	crdelay[] = {
D 2
	20,		CR1,
	30,		CR2,
	40,		CR3,
E 2
I 2
	1,		CR1,
	2,		CR2,
	3,		CR3,
	83,		CR1,
	166,		CR2,
E 2
	0,		CR3,
};

struct delayval nldelay[] = {
	1,		NL1,		/* special, calculated */
D 2
	16,		NL2,
	30,		NL3,
E 2
I 2
	2,		NL2,
	3,		NL3,
	100,		NL2,
E 2
	0,		NL3,
};

struct delayval	bsdelay[] = {
I 2
	1,		BS1,
E 2
	0,		0,
};

struct delayval	ffdelay[] = {
I 2
	1,		FF1,
E 2
	1750,		FF1,
	0,		FF1,
};

struct delayval	tbdelay[] = {
D 2
	10,		TAB1,
	20,		TAB2,
E 2
I 2
	1,		TAB1,
	2,		TAB2,
	3,		XTABS,		/* this is expand tabs */
	100,		TAB1,
E 2
	0,		TAB2,
};

delaybits()
{
	register f;

	f  = adelay(CD, crdelay);
	f |= adelay(ND, nldelay);
	f |= adelay(FD, ffdelay);
	f |= adelay(TD, tbdelay);
	f |= adelay(BD, bsdelay);
	return (f);
}

adelay(ms, dp)
	register ms;
	register struct delayval *dp;
{
	if (ms == 0)
		return (0);
	while (dp->delay && ms > dp->delay)
		dp++;
	return (dp->bits);
}

char	editedhost[32];

edithost(pat)
	register char *pat;
{
	register char *host = HN;
	register char *res = editedhost;

	if (!pat)
		pat = "";
	while (*pat) {
		switch (*pat) {

		case '#':
			if (*host)
				host++;
			break;

		case '@':
			if (*host)
				*res++ = *host++;
			break;

		default:
			*res++ = *pat;
			break;

		}
		if (res == &editedhost[sizeof editedhost - 1]) {
			*res = '\0';
			return;
		}
		pat++;
	}
	if (*host)
		strncpy(res, host, sizeof editedhost - (res - editedhost) - 1);
	else
		*res = '\0';
	editedhost[sizeof editedhost - 1] = '\0';
}

struct speedtab {
	int	speed;
	int	uxname;
} speedtab[] = {
	50,	B50,
	75,	B75,
	110,	B110,
	134,	B134,
	150,	B150,
	200,	B200,
	300,	B300,
	600,	B600,
	1200,	B1200,
	1800,	B1800,
	2400,	B2400,
	4800,	B4800,
	9600,	B9600,
	19200,	EXTA,
	19,	EXTA,		/* for people who say 19.2K */
	38400,	EXTB,
	38,	EXTB,
	7200,	EXTB,		/* alternative */
	0
};

speed(val)
{
	register struct speedtab *sp;

	if (val <= 15)
D 4
		return(val);
E 4
I 4
		return (val);
E 4

	for (sp = speedtab; sp->speed; sp++)
		if (sp->speed == val)
			return (sp->uxname);
	
	return (B300);		/* default in impossible cases */
}

makeenv(env)
	char *env[];
{
	static char termbuf[128] = "TERM=";
	register char *p, *q;
	register char **ep;
	char *index();

	ep = env;
	if (TT && *TT) {
		strcat(termbuf, TT);
		*ep++ = termbuf;
	}
	if (p = EV) {
		q = p;
		while (q = index(q, ',')) {
			*q++ = '\0';
			*ep++ = p;
			p = q;
		}
		if (*p)
			*ep++ = p;
	}
	*ep = (char *)0;
}

/*
 * This speed select mechanism is written for the Develcon DATASWITCH.
 * The Develcon sends a string of the form "B{speed}\n" at a predefined
 * baud rate. This string indicates the user's actual speed.
 * The routine below returns the terminal type mapped from derived speed.
 */
struct	portselect {
	char	*ps_baud;
	char	*ps_type;
} portspeeds[] = {
	{ "B110",	"std.110" },
	{ "B134",	"std.134" },
	{ "B150",	"std.150" },
	{ "B300",	"std.300" },
	{ "B600",	"std.600" },
	{ "B1200",	"std.1200" },
	{ "B2400",	"std.2400" },
	{ "B4800",	"std.4800" },
	{ "B9600",	"std.9600" },
I 7
	{ "B19200",	"std.19200" },
E 7
	{ 0 }
};

char *
portselector()
{
	char c, baud[20], *type = "default";
	register struct portselect *ps;
	int len;

	alarm(5*60);
	for (len = 0; len < sizeof (baud) - 1; len++) {
		if (read(0, &c, 1) <= 0)
			break;
		c &= 0177;
		if (c == '\n' || c == '\r')
			break;
		if (c == 'B')
			len = 0;	/* in case of leading garbage */
		baud[len] = c;
	}
	baud[len] = '\0';
	for (ps = portspeeds; ps->ps_baud; ps++)
		if (strcmp(ps->ps_baud, baud) == 0) {
			type = ps->ps_type;
			break;
		}
	sleep(2);	/* wait for connection to complete */
I 4
	return (type);
}

/*
 * This auto-baud speed select mechanism is written for the Micom 600
 * portselector. Selection is done by looking at how the character '\r'
 * is garbled at the different speeds.
 */
#include <sys/time.h>

char *
autobaud()
{
	int rfds;
	struct timeval timeout;
	char c, *type = "9600-baud";
	int null = 0;

	ioctl(0, TIOCFLUSH, &null);
	rfds = 1 << 0;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	if (select(32, &rfds, (int *)0, (int *)0, &timeout) <= 0)
		return (type);
	if (read(0, &c, sizeof(char)) != sizeof(char))
		return (type);
	timeout.tv_sec = 0;
	timeout.tv_usec = 20;
	(void) select(32, (int *)0, (int *)0, (int *)0, &timeout);
	ioctl(0, TIOCFLUSH, &null);
	switch (c & 0377) {

	case 0200:		/* 300-baud */
		type = "300-baud";
		break;

	case 0346:		/* 1200-baud */
		type = "1200-baud";
		break;

	case  015:		/* 2400-baud */
	case 0215:
		type = "2400-baud";
		break;

	default:		/* 4800-baud */
		type = "4800-baud";
		break;

	case 0377:		/* 9600-baud */
		type = "9600-baud";
		break;
	}
E 4
	return (type);
I 10
}

/*
 * Smart modem autobaud code.  Look for the CONNECT message from the modem
 * and extract the speed from it.  Assumes a modem that asserts DCD immediately
 * upon starting the answer tone (i.e., as soon as it answers the call, before
 * it hears anything from the other end), then if the connection is established
 * successfully sends a CONNECT message at a fixed baud rate indicating the
 * actual connection speed, and then switches to the baud rate best matching
 * the latter.
 */
struct	smspeed {
	int	speed;
	int	approx;
	char	*type;
} smspeeds[] = {
	{ 300,	0,	"sm-300" },	/* V.21 or Bell 103 */
	{ 600,	0,	"sm-600" },	/* V.22 */
	{ 1200,	0,	"sm-1200" },	/* V.22 */
	{ 2400,	0,	"sm-2400" },	/* V.22 bis */
	{ 4800,	0,	"sm-4800" },	/* V.32 */
	{ 9600,	1,	"sm-9600" },	/* V.32 */
	{ 19200,1,	"sm-19200" },	/* V.32 bis 14.4 kbps */
	{ 38400,1,	"sm-38400" },	/* V.34 28.8-33.6 kbps */
	{ 0 }
};
#include <stdio.h>
#include <ctype.h>
char *
smartmodem()
{
	char mmsg[64];
	register int c, i;
	extern char *ttyn;

	/*
	 * The CONNECT message will normally be preceded by CRLF.
	 * It should not be preceded by any other garbage if the modem asserts
	 * DCD when it starts the answer tone, since that's when we wake up
	 * from the open and flush.
	 */
	do
		c = getchar() & 0177;
	while (c == '\r' || c == '\n');
	for (i = 0; i < 63; i++) {
		c = getchar() & 0177;
		if (c == '\r' || c == '\n')
			break;
		mmsg[i] = c;
	}
	mmsg[i] = '\0';
	if (strncmp(mmsg, "CONNECT", 7)) {
		/*
		 * No connection established.  Exit and let init rerun us for
		 * the next call.  This is not a serious error and can occur
		 * routinely (a human dials the modem number by mistake, etc).
		 */
		exit(1);
	}
	/* connected */
	syslog(LOG_INFO, "%s: %s", ttyn+5, mmsg);
	/* get the speed */
	if (mmsg[7] == ' ' && isdigit(mmsg[8]))
		c = atoi(mmsg + 8);
	else
		c = 300;
	/* validate it */
	for (i = 0; smspeeds[i].speed; i++)
		if (c <= smspeeds[i].speed)
			break;
	if (!smspeeds[i].speed ||
	    c != smspeeds[i].speed && !smspeeds[i].approx) {
		syslog(LOG_ERR, "%s: invalid connection speed: %d", ttyn+5, c);
		exit(1);
	}
	closelog();
	return(smspeeds[i].type);
E 10
}
E 1
