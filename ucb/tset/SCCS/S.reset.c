h65397
s 00002/00000/00061
d D 5.2 85/08/13 05:25:47 lepreau 6 5
c reset MDMBUF,LITOUT, and PASS8
e
s 00015/00002/00046
d D 5.1 85/05/31 09:26:21 dist 5 4
c Add copyright
e
s 00016/00016/00032
d D 4.4 83/07/01 03:05:35 sam 4 3
c use system defaults
e
s 00003/00001/00045
d D 4.3 80/12/03 20:52:30 mark 3 2
c added exec of tset to set remaining modes correctly
e
s 00029/00016/00017
d D 4.2 80/10/10 00:46:08 bill 2 1
c new version, substantial cleanup and saner
e
s 00033/00000/00000
d D 4.1 80/10/01 17:28:06 bill 1 0
c date and time created 80/10/01 17:28:06 by bill
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
I 4
#ifndef lint
E 4
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
I 4
#endif
E 5
I 5
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 5
E 4
E 2
/*
D 2
 * reset - set the teletype mode bits to be sensible
 *
 * Kurt Shoens
 *
 * Very useful after crapping out in raw.
 * Modified by Mark Horton to know about tchars
 * and to not mess with peoples chars unless they are null.
E 2
I 2
D 3
 * reset 
E 3
I 3
 * reset - restore tty to sensible state after crapping out in raw mode.
E 3
E 2
 */
#include <sgtty.h>
D 2
#define chk(val, dft) (val==0 ? dft : val)
E 2

I 2
D 4
#define	CTRL(x)	('x'&037)

E 4
E 2
main()
{
	struct sgttyb buf;
	struct tchars tbuf;
I 2
	struct ltchars ltbuf;
I 6
	static int lclear = LMDMBUF|LLITOUT|LPASS8;
E 6
E 2

D 4
	gtty(2, &buf);
E 4
I 4
	ioctl(2, TIOCGETP, &buf);
E 4
	ioctl(2, TIOCGETC, &tbuf);
I 2
	ioctl(2, TIOCGLTC, &ltbuf);
E 2
	buf.sg_flags &= ~(RAW|CBREAK|VTDELAY|ALLDELAY);
	buf.sg_flags |= XTABS|ECHO|CRMOD|ANYP;
D 2
	buf.sg_erase = chk(buf.sg_erase, '\08');	/* ^H */
	buf.sg_kill = chk(buf.sg_kill, '\30');		/* ^X */
	tbuf.t_intrc = chk(tbuf.t_intrc, '\177');	/* ^? */
	tbuf.t_quitc = chk(tbuf.t_quitc, '\34');	/* ^\ */
	tbuf.t_startc = chk(tbuf.t_startc, '\22');	/* ^Q */
	tbuf.t_stopc = chk(tbuf.t_stopc, '\24');	/* ^S */
	tbuf.t_eofc = chk(tbuf.t_eofc, '\4');		/* ^D */
E 2
I 2
D 4
	reset(&buf.sg_erase, CTRL(h));
	reset(&buf.sg_kill, '@');
	reset(&tbuf.t_intrc, 0177);
	reset(&tbuf.t_quitc, CTRL(\\\\));
	reset(&tbuf.t_startc, CTRL(q));
	reset(&tbuf.t_stopc, CTRL(s));
	reset(&tbuf.t_eofc, CTRL(d));
	reset(&ltbuf.t_suspc, CTRL(z));
	reset(&ltbuf.t_dsuspc, CTRL(y));
	reset(&ltbuf.t_rprntc, CTRL(r));
	reset(&ltbuf.t_flushc, CTRL(o));
	reset(&ltbuf.t_lnextc, CTRL(v));
	reset(&ltbuf.t_werasc, CTRL(w));
E 4
I 4
	reset(&buf.sg_erase, CERASE);
	reset(&buf.sg_kill, CKILL);
	reset(&tbuf.t_intrc, CINTR);
	reset(&tbuf.t_quitc, CQUIT);
	reset(&tbuf.t_startc, CSTART);
	reset(&tbuf.t_stopc, CSTOP);
	reset(&tbuf.t_eofc, CEOF);
	reset(&ltbuf.t_suspc, CSUSP);
	reset(&ltbuf.t_dsuspc, CDSUSP);
	reset(&ltbuf.t_rprntc, CRPRNT);
	reset(&ltbuf.t_flushc, CFLUSH);
	reset(&ltbuf.t_lnextc, CLNEXT);
	reset(&ltbuf.t_werasc, CWERASE);
E 4
E 2
	/* brkc is left alone */
I 6
	ioctl(2, TIOCLBIC, &lclear);
E 6
	ioctl(2, TIOCSETN, &buf);
	ioctl(2, TIOCSETC, &tbuf);
I 2
	ioctl(2, TIOCSLTC, &ltbuf);
I 3
	execlp("tset", "tset", "-Q", "-I", 0);	/* fix term dependent stuff */
	exit(1);
E 3
}

reset(cp, def)
	char *cp;
	int def;
{

	if (*cp == 0 || (*cp&0377)==0377)
		*cp = def;
E 2
}
E 1
