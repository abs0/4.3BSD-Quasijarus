h14948
s 00003/00003/01146
d D 5.5 88/05/19 15:38:48 bostic 21 20
c install C version of _doprnt
e
s 00005/00004/01144
d D 5.4 87/06/25 09:15:15 bostic 20 19
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00002/00002/01146
d D 5.3 86/05/13 01:03:33 lepreau 19 18
c avoid null ptr deref, from glenn@sun
e
s 00003/00003/01145
d D 5.2 85/06/06 13:11:42 edward 18 17
c cleaning up after bozos
e
s 00008/00002/01140
d D 5.1 85/06/04 10:59:01 dist 17 16
c Add copyright
e
s 00015/00003/01127
d D 4.16 85/06/01 16:55:51 edward 16 15
c allow setenv with 0 and 1 arugments:
c 	setenv -> printenv
c 	setenv x -> setenv x ''
e
s 00032/00015/01098
d D 4.15 85/03/28 18:32:15 edward 15 14
c limit and unlimit bug fixed,
c plus -h to set and unset hard limits
e
s 00017/00007/01096
d D 4.14 85/03/19 18:20:19 mckusick 14 13
c null pointers; system call boiler plate
e
s 00086/00059/01017
d D 4.13 84/12/13 14:43:06 edward 13 12
c performance
e
s 00018/00018/01058
d D 4.12 84/08/31 09:31:57 ralph 12 11
c use new signal calls instead of compatibility routines.
e
s 00004/00001/01072
d D 4.11 84/07/03 19:51:13 mckusick 11 10
c fix the unlimit command so that it does not try to set greater than the
c user is allowed.
e
s 00015/00015/01058
d D 4.10 83/06/11 16:49:11 sam 10 9
c different approach, try signal compatibility package
e
s 00018/00016/01055
d D 4.9 83/06/10 23:59:04 sam 9 8
c new signals; no libjobs; still loses SIGINT by getting it masked 
c sometimes, but we check it in before we lose something
e
s 00001/00001/01070
d D 4.8 83/02/09 14:17:04 sam 8 7
c cleanups from sun
e
s 00025/00028/01046
d D 4.7 82/12/30 17:34:57 sam 7 6
c finally works (updated for 4.1c and merged with sun)
e
s 00001/00000/01073
d D 4.6 81/08/20 23:48:57 mckusic 6 5
c save history on "login" command
e
s 00003/00001/01070
d D 4.5 81/06/19 13:54:39 root 5 4
c fix to bug rep #32 from cmu
e
s 00004/00000/01067
d D 4.4 81/05/18 11:58:23 root 4 3
c fix per ken greer
e
s 00001/00000/01066
d D 4.3 81/04/13 20:01:07 wnj 3 2
c add limit on memoryuse
e
s 00001/00001/01065
d D 4.2 81/02/07 12:15:31 wnj 2 1
c fixed include file
e
s 01066/00000/00000
d D 4.1 80/10/09 12:40:58 bill 1 0
c date and time created 80/10/09 12:40:58 by bill
e
u
U
t
T
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
D 18
 * All rights reserved.  The Berkeley software License Agreement
E 18
I 18
 * All rights reserved.  The Berkeley Software License Agreement
E 18
 * specifies the terms and conditions for redistribution.
 */

E 17
I 1
D 5
static	char *sccsid = "%Z%%M% %I% %G%";
E 5
I 5
D 13
static	char *sccsid = "%Z%%M% %I% %E%";
E 13
I 13
#ifndef lint
D 17
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 17
I 17
D 18
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 18
I 18
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 18
E 17
E 13
E 5

#include "sh.h"
#include <sys/ioctl.h>

/*
 * C shell
 */

struct biltins *
isbfunc(t)
D 13
	register struct command *t;
E 13
I 13
	struct command *t;
E 13
{
	register char *cp = t->t_dcom[0];
D 13
	register char *dp;
	register struct biltins *bp;
E 13
I 13
	register struct biltins *bp, *bp1, *bp2;
E 13
	int dolabel(), dofg1(), dobg1();
	static struct biltins label = { "", dolabel, 0, 0 };
	static struct biltins foregnd = { "%job", dofg1, 0, 0 };
	static struct biltins backgnd = { "%job &", dobg1, 0, 0 };

	if (lastchr(cp) == ':') {
		label.bname = cp;
		return (&label);
	}
	if (*cp == '%') {
		if (t->t_dflg & FAND) {
			t->t_dflg &= ~FAND;
			backgnd.bname = cp;
			return (&backgnd);
D 13
		} 
E 13
I 13
		}
E 13
		foregnd.bname = cp;
		return (&foregnd);
	}
D 13
	for (bp = bfunc; dp = bp->bname; bp++) {
		if (dp[0] == cp[0] && eq(dp, cp))
			return (bp);
		if (dp[0] > cp[0])
			break;
E 13
I 13
	/*
	 * Binary search
	 * Bp1 is the beginning of the current search range.
	 * Bp2 is one past the end.
	 */
	for (bp1 = bfunc, bp2 = bfunc + nbfunc; bp1 < bp2;) {
		register i;

		bp = bp1 + (bp2 - bp1 >> 1);
		if ((i = *cp - *bp->bname) == 0 &&
		    (i = strcmp(cp, bp->bname)) == 0)
			return bp;
		if (i < 0)
			bp2 = bp;
		else
			bp1 = bp + 1;
E 13
	}
	return (0);
}

func(t, bp)
	register struct command *t;
	register struct biltins *bp;
{
	int i;

	xechoit(t->t_dcom);
	setname(bp->bname);
	i = blklen(t->t_dcom) - 1;
	if (i < bp->minargs)
		bferr("Too few arguments");
	if (i > bp->maxargs)
		bferr("Too many arguments");
	(*bp->bfunct)(t->t_dcom, t);
}

dolabel()
{

}

doonintr(v)
	char **v;
{
	register char *cp;
	register char *vv = v[1];

	if (parintr == SIG_IGN)
		return;
	if (setintr && intty)
		bferr("Can't from terminal");
	cp = gointr, gointr = 0, xfree(cp);
	if (vv == 0) {
		if (setintr)
D 9
			sighold(SIGINT);
E 9
I 9
D 10
			(void) sigblock(mask(SIGINT));
E 10
I 10
D 12
			sighold(SIGINT);
E 12
I 12
D 13
			sigblock(sigmask(SIGINT));
E 13
I 13
			(void) sigblock(sigmask(SIGINT));
E 13
E 12
E 10
E 9
		else
D 9
			sigset(SIGINT, SIG_DFL);
E 9
I 9
D 10
			signal(SIGINT, SIG_DFL);
E 10
I 10
D 12
			sigset(SIGINT, SIG_DFL);
E 12
I 12
D 13
			signal(SIGINT, SIG_DFL);
E 13
I 13
			(void) signal(SIGINT, SIG_DFL);
E 13
E 12
E 10
E 9
		gointr = 0;
	} else if (eq((vv = strip(vv)), "-")) {
D 9
		sigset(SIGINT, SIG_IGN);
E 9
I 9
D 10
		signal(SIGINT, SIG_IGN);
E 10
I 10
D 12
		sigset(SIGINT, SIG_IGN);
E 12
I 12
D 13
		signal(SIGINT, SIG_IGN);
E 13
I 13
		(void) signal(SIGINT, SIG_IGN);
E 13
E 12
E 10
E 9
		gointr = "-";
	} else {
		gointr = savestr(vv);
D 9
		sigset(SIGINT, pintr);
E 9
I 9
D 10
		signal(SIGINT, pintr);
E 10
I 10
D 12
		sigset(SIGINT, pintr);
E 12
I 12
D 13
		signal(SIGINT, pintr);
E 13
I 13
		(void) signal(SIGINT, pintr);
E 13
E 12
E 10
E 9
	}
}

donohup()
{

	if (intty)
		bferr("Can't from terminal");
	if (setintr == 0) {
D 13
		signal(SIGHUP, SIG_IGN);
E 13
I 13
		(void) signal(SIGHUP, SIG_IGN);
E 13
#ifdef CC
		submit(getpid());
#endif
	}
}

dozip()
{

	;
}

prvars()
{

	plist(&shvhed);
}

doalias(v)
	register char **v;
{
	register struct varent *vp;
	register char *p;

	v++;
	p = *v++;
	if (p == 0)
		plist(&aliases);
	else if (*v == 0) {
		vp = adrof1(strip(p), &aliases);
		if (vp)
			blkpr(vp->vec), printf("\n");
	} else {
		if (eq(p, "alias") || eq(p, "unalias")) {
			setname(p);
			bferr("Too dangerous to alias that");
		}
		set1(strip(p), saveblk(v), &aliases);
	}
}

unalias(v)
	char **v;
{

	unset1(v, &aliases);
}

dologout()
{

	islogin();
	goodbye();
}

dologin(v)
	char **v;
{

	islogin();
I 6
	rechist();
E 6
D 13
	signal(SIGTERM, parterm);
E 13
I 13
	(void) signal(SIGTERM, parterm);
E 13
	execl("/bin/login", "login", v[1], 0);
	untty();
	exit(1);
}

I 9
#ifdef NEWGRP
E 9
donewgrp(v)
	char **v;
{

I 5
	if (chkstop == 0 && setintr)
		panystop(0);
E 5
D 13
	signal(SIGTERM, parterm);
E 13
I 13
	(void) signal(SIGTERM, parterm);
E 13
	execl("/bin/newgrp", "newgrp", v[1], 0);
	execl("/usr/bin/newgrp", "newgrp", v[1], 0);
	untty();
	exit(1);
}
I 9
#endif
E 9

islogin()
{

	if (chkstop == 0 && setintr)
		panystop(0);
	if (loginsh)
		return;
	error("Not login shell");
}

doif(v, kp)
	char **v;
	struct command *kp;
{
	register int i;
	register char **vv;

	v++;
	i = exp(&v);
	vv = v;
	if (*vv == NOSTR)
		bferr("Empty if");
	if (eq(*vv, "then")) {
		if (*++vv)
			bferr("Improper then");
		setname("then");
		/*
		 * If expression was zero, then scan to else,
		 * otherwise just fall into following code.
		 */
		if (!i)
			search(ZIF, 0);
		return;
	}
	/*
	 * Simple command attached to this if.
	 * Left shift the node in this tree, munging it
	 * so we can reexecute it.
	 */
	if (i) {
		lshift(kp->t_dcom, vv - kp->t_dcom);
		reexecute(kp);
		donefds();
	}
}

/*
 * Reexecute a command, being careful not
 * to redo i/o redirection, which is already set up.
 */
reexecute(kp)
	register struct command *kp;
{

	kp->t_dflg &= FSAVE;
	kp->t_dflg |= FREDO;
	/*
	 * If tty is still ours to arbitrate, arbitrate it;
	 * otherwise dont even set pgrp's as the jobs would
	 * then have no way to get the tty (we can't give it
	 * to them, and our parent wouldn't know their pgrp, etc.
	 */
	execute(kp, tpgrp > 0 ? tpgrp : -1);
}

doelse()
{

	search(ZELSE, 0);
}

dogoto(v)
	char **v;
{
	register struct whyle *wp;
	char *lp;

	/*
	 * While we still can, locate any unknown ends of existing loops.
	 * This obscure code is the WORST result of the fact that we
	 * don't really parse.
	 */
	for (wp = whyles; wp; wp = wp->w_next)
		if (wp->w_end == 0) {
			search(ZBREAK, 0);
			wp->w_end = btell();
		} else
			bseek(wp->w_end);
	search(ZGOTO, 0, lp = globone(v[1]));
	xfree(lp);
	/*
	 * Eliminate loops which were exited.
	 */
	wfree();
}

doswitch(v)
	register char **v;
{
	register char *cp, *lp;

	v++;
	if (!*v || *(*v++) != '(')
		goto syntax;
	cp = **v == ')' ? "" : *v++;
	if (*(*v++) != ')')
		v--;
	if (*v)
syntax:
		error("Syntax error");
	search(ZSWITCH, 0, lp = globone(cp));
	xfree(lp);
}

dobreak()
{

	if (whyles)
		toend();
	else
		bferr("Not in while/foreach");
}

doexit(v)
	char **v;
{

	if (chkstop == 0)
		panystop(0);
	/*
	 * Don't DEMAND parentheses here either.
	 */
	v++;
	if (*v) {
		set("status", putn(exp(&v)));
		if (*v)
			bferr("Expression syntax");
	}
	btoeof();
	if (intty)
D 13
		close(SHIN);
E 13
I 13
		(void) close(SHIN);
E 13
}

doforeach(v)
	register char **v;
{
	register char *cp;
	register struct whyle *nwp;

	v++;
	cp = strip(*v);
	while (*cp && letter(*cp))
		cp++;
	if (*cp || strlen(*v) >= 20)
		bferr("Invalid variable");
	cp = *v++;
	if (v[0][0] != '(' || v[blklen(v) - 1][0] != ')')
		bferr("Words not ()'ed");
	v++;
D 13
	gflag = 0, rscan(v, tglob);
E 13
I 13
	gflag = 0, tglob(v);
E 13
	v = glob(v);
	if (v == 0)
		bferr("No match");
	nwp = (struct whyle *) calloc(1, sizeof *nwp);
	nwp->w_fe = nwp->w_fe0 = v; gargv = 0;
	nwp->w_start = btell();
	nwp->w_fename = savestr(cp);
	nwp->w_next = whyles;
	whyles = nwp;
	/*
	 * Pre-read the loop so as to be more
	 * comprehensible to a terminal user.
	 */
	if (intty)
		preread();
	doagain();
}

dowhile(v)
	char **v;
{
	register int status;
	register bool again = whyles != 0 && whyles->w_start == lineloc &&
	    whyles->w_fename == 0;

	v++;
	/*
	 * Implement prereading here also, taking care not to
	 * evaluate the expression before the loop has been read up
	 * from a terminal.
	 */
	if (intty && !again)
		status = !exp0(&v, 1);
	else
		status = !exp(&v);
	if (*v)
		bferr("Expression syntax");
	if (!again) {
		register struct whyle *nwp = (struct whyle *) calloc(1, sizeof (*nwp));

		nwp->w_start = lineloc;
		nwp->w_end = 0;
		nwp->w_next = whyles;
		whyles = nwp;
		if (intty) {
			/*
			 * The tty preread
			 */
			preread();
			doagain();
			return;
		}
	}
	if (status)
		/* We ain't gonna loop no more, no more! */
		toend();
}

preread()
{

	whyles->w_end = -1;
	if (setintr)
D 9
		sigrelse(SIGINT);
E 9
I 9
D 10
		(void) sigrelse(mask(SIGINT));
E 10
I 10
D 12
		sigrelse(SIGINT);
E 12
I 12
D 13
		sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 13
I 13
D 20
		(void) sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 20
I 20
		(void) sigsetmask(sigblock(0L) & ~sigmask(SIGINT));
E 20
E 13
E 12
E 10
E 9
	search(ZBREAK, 0);
	if (setintr)
D 9
		sighold(SIGINT);
E 9
I 9
D 10
		sigblock(mask(SIGINT));
E 10
I 10
D 12
		sighold(SIGINT);
E 12
I 12
D 13
		sigblock(sigmask(SIGINT));
E 13
I 13
		(void) sigblock(sigmask(SIGINT));
E 13
E 12
E 10
E 9
	whyles->w_end = btell();
}

doend()
{

	if (!whyles)
		bferr("Not in while/foreach");
	whyles->w_end = btell();
	doagain();
}

docontin()
{

	if (!whyles)
		bferr("Not in while/foreach");
	doagain();
}

doagain()
{

	/* Repeating a while is simple */
	if (whyles->w_fename == 0) {
		bseek(whyles->w_start);
		return;
	}
	/*
	 * The foreach variable list actually has a spurious word
	 * ")" at the end of the w_fe list.  Thus we are at the
	 * of the list if one word beyond this is 0.
	 */
	if (!whyles->w_fe[1]) {
		dobreak();
		return;
	}
	set(whyles->w_fename, savestr(*whyles->w_fe++));
	bseek(whyles->w_start);
}

dorepeat(v, kp)
	char **v;
	struct command *kp;
{
D 12
	register int i;
E 12
I 12
D 20
	register int i, omask;
E 20
I 20
	register int i;
	register long	omask;
E 20
E 12

	i = getn(v[1]);
	if (setintr)
D 9
		sighold(SIGINT);
E 9
I 9
D 10
		(void) sigblock(mask(SIGINT));
E 10
I 10
D 12
		sighold(SIGINT);
E 12
I 12
		omask = sigblock(sigmask(SIGINT)) & ~sigmask(SIGINT);
E 12
E 10
E 9
	lshift(v, 2);
	while (i > 0) {
		if (setintr)
D 9
			sigrelse(SIGINT);
E 9
I 9
D 10
			(void) sigrelse(mask(SIGINT));
E 10
I 10
D 12
			sigrelse(SIGINT);
E 12
I 12
D 13
			sigsetmask(omask);
E 13
I 13
			(void) sigsetmask(omask);
E 13
E 12
E 10
E 9
		reexecute(kp);
		--i;
	}
	donefds();
	if (setintr)
D 9
		sigrelse(SIGINT);
E 9
I 9
D 10
		(void) sigrelse(mask(SIGINT));
E 10
I 10
D 12
		sigrelse(SIGINT);
E 12
I 12
D 13
		sigsetmask(omask);
E 13
I 13
		(void) sigsetmask(omask);
E 13
E 12
E 10
E 9
}

doswbrk()
{

	search(ZBRKSW, 0);
}

srchx(cp)
	register char *cp;
{
D 13
	register struct srch *sp;
E 13
I 13
	register struct srch *sp, *sp1, *sp2;
	register i;
E 13

D 13
	for (sp = srchn; sp->s_name; sp++)
		if (eq(cp, sp->s_name))
			return (sp->s_value);
E 13
I 13
	/*
	 * Binary search
	 * Sp1 is the beginning of the current search range.
	 * Sp2 is one past the end.
	 */
	for (sp1 = srchn, sp2 = srchn + nsrchn; sp1 < sp2;) {
		sp = sp1 + (sp2 - sp1 >> 1);
		if ((i = *cp - *sp->s_name) == 0 &&
		    (i = strcmp(cp, sp->s_name)) == 0)
			return sp->s_value;
		if (i < 0)
			sp2 = sp;
		else
			sp1 = sp + 1;
	}
E 13
	return (-1);
}

char	Stype;
char	*Sgoal;

/*VARARGS2*/
search(type, level, goal)
	int type;
	register int level;
	char *goal;
{
	char wordbuf[BUFSIZ];
	register char *aword = wordbuf;
	register char *cp;

	Stype = type; Sgoal = goal;
	if (type == ZGOTO)
D 13
		bseek(0l);
E 13
I 13
		bseek((off_t)0);
E 13
	do {
		if (intty && fseekp == feobp)
			printf("? "), flush();
D 13
		aword[0] = 0, getword(aword);
E 13
I 13
		aword[0] = 0;
		(void) getword(aword);
E 13
		switch (srchx(aword)) {

		case ZELSE:
			if (level == 0 && type == ZIF)
				return;
			break;

		case ZIF:
			while (getword(aword))
				continue;
			if ((type == ZIF || type == ZELSE) && eq(aword, "then"))
				level++;
			break;

		case ZENDIF:
			if (type == ZIF || type == ZELSE)
				level--;
			break;

		case ZFOREACH:
		case ZWHILE:
			if (type == ZBREAK)
				level++;
			break;

		case ZEND:
			if (type == ZBREAK)
				level--;
			break;

		case ZSWITCH:
			if (type == ZSWITCH || type == ZBRKSW)
				level++;
			break;

		case ZENDSW:
			if (type == ZSWITCH || type == ZBRKSW)
				level--;
			break;

		case ZLABEL:
			if (type == ZGOTO && getword(aword) && eq(aword, goal))
				level = -1;
			break;

		default:
			if (type != ZGOTO && (type != ZSWITCH || level != 0))
				break;
			if (lastchr(aword) != ':')
				break;
			aword[strlen(aword) - 1] = 0;
			if (type == ZGOTO && eq(aword, goal) || type == ZSWITCH && eq(aword, "default"))
				level = -1;
			break;

		case ZCASE:
			if (type != ZSWITCH || level != 0)
				break;
D 13
			getword(aword);
E 13
I 13
			(void) getword(aword);
E 13
			if (lastchr(aword) == ':')
				aword[strlen(aword) - 1] = 0;
			cp = strip(Dfix1(aword));
			if (Gmatch(goal, cp))
				level = -1;
			xfree(cp);
			break;

		case ZDEFAULT:
			if (type == ZSWITCH && level == 0)
				level = -1;
			break;
		}
D 13
		getword(NOSTR);
E 13
I 13
		(void) getword(NOSTR);
E 13
	} while (level >= 0);
}

getword(wp)
	register char *wp;
{
	register int found = 0;
	register int c, d;

	c = readc(1);
	d = 0;
	do {
		while (c == ' ' || c == '\t')
			c = readc(1);
I 4
		if (c == '#')
			do
				c = readc(1);
			while (c >= 0 && c != '\n');
E 4
		if (c < 0)
			goto past;
		if (c == '\n') {
			if (wp)
				break;
			return (0);
		}
		unreadc(c);
		found = 1;
		do {
			c = readc(1);
			if (c == '\\' && (c = readc(1)) == '\n')
				c = ' ';
D 13
			if (any(c, "'\""))
E 13
I 13
			if (c == '\'' || c == '"')
E 13
				if (d == 0)
					d = c;
				else if (d == c)
					d = 0;
			if (c < 0)
				goto past;
			if (wp)
				*wp++ = c;
		} while ((d || c != ' ' && c != '\t') && c != '\n');
	} while (wp == 0);
	unreadc(c);
	if (found)
		*--wp = 0;
	return (found);

past:
	switch (Stype) {

	case ZIF:
		bferr("then/endif not found");

	case ZELSE:
		bferr("endif not found");

	case ZBRKSW:
	case ZSWITCH:
		bferr("endsw not found");

	case ZBREAK:
		bferr("end not found");

	case ZGOTO:
		setname(Sgoal);
		bferr("label not found");
	}
	/*NOTREACHED*/
}

toend()
{

	if (whyles->w_end == 0) {
		search(ZBREAK, 0);
		whyles->w_end = btell() - 1;
	} else
		bseek(whyles->w_end);
	wfree();
}

wfree()
{
	long o = btell();

	while (whyles) {
		register struct whyle *wp = whyles;
		register struct whyle *nwp = wp->w_next;

		if (o >= wp->w_start && (wp->w_end == 0 || o < wp->w_end))
			break;
		if (wp->w_fe0)
			blkfree(wp->w_fe0);
		if (wp->w_fename)
			xfree(wp->w_fename);
		xfree((char *)wp);
		whyles = nwp;
	}
}

doecho(v)
	char **v;
{

	echo(' ', v);
}

doglob(v)
	char **v;
{

	echo(0, v);
	flush();
}

echo(sep, v)
	char sep;
	register char **v;
{
	register char *cp;
	int nonl = 0;

	if (setintr)
D 9
		sigrelse(SIGINT);
E 9
I 9
D 10
		(void) sigrelse(mask(SIGINT));
E 10
I 10
D 12
		sigrelse(SIGINT);
E 12
I 12
D 13
		sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 13
I 13
D 20
		(void) sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 20
I 20
		(void) sigsetmask(sigblock(0L) & ~sigmask(SIGINT));
E 20
E 13
E 12
E 10
E 9
	v++;
	if (*v == 0)
		return;
D 13
	gflag = 0; rscan(v, tglob);
E 13
I 13
	gflag = 0, tglob(v);
E 13
	if (gflag) {
		v = glob(v);
		if (v == 0)
			bferr("No match");
	} else
D 13
		scan(v, trim);
E 13
I 13
		trim(v);
E 13
D 14
	if (sep == ' ' && !strcmp(*v, "-n"))
E 14
I 14
	if (sep == ' ' && *v && !strcmp(*v, "-n"))
E 14
		nonl++, v++;
	while (cp = *v++) {
		register int c;

		while (c = *cp++)
D 21
			putchar(c | QUOTE);
E 21
I 21
			cshputchar(c | QUOTE);
E 21
		if (*v)
D 21
			putchar(sep | QUOTE);
E 21
I 21
			cshputchar(sep | QUOTE);
E 21
	}
	if (sep && nonl == 0)
D 21
		putchar('\n');
E 21
I 21
		cshputchar('\n');
E 21
	else
		flush();
	if (setintr)
D 9
		sighold(SIGINT);
E 9
I 9
D 10
		(void) sigblock(mask(SIGINT));
E 10
I 10
D 12
		sighold(SIGINT);
E 12
I 12
D 13
		sigblock(sigmask(SIGINT));
E 13
I 13
		(void) sigblock(sigmask(SIGINT));
E 13
E 12
E 10
E 9
	if (gargv)
		blkfree(gargv), gargv = 0;
}

char	**environ;

dosetenv(v)
	register char **v;
{
D 16
	char *lp = globone(v[2]);
E 16
I 16
	char *vp, *lp;
E 16

D 16
	setenv(v[1], lp);
	if (eq(v[1], "PATH")) {
E 16
I 16
	v++;
	if ((vp = *v++) == 0) {
		register char **ep;

		if (setintr)
D 20
			(void) sigsetmask(sigblock(0) & ~ sigmask(SIGINT));
E 20
I 20
			(void) sigsetmask(sigblock(0L) & ~ sigmask(SIGINT));
E 20
		for (ep = environ; *ep; ep++)
			printf("%s\n", *ep);
		return;
	}
	if ((lp = *v++) == 0)
		lp = "";
	setenv(vp, lp = globone(lp));
	if (eq(vp, "PATH")) {
E 16
		importpath(lp);
		dohash();
	}
	xfree(lp);
}

dounsetenv(v)
	register char **v;
{

	v++;
	do
		unsetenv(*v++);
	while (*v);
}

D 13
setenv(name, value)
	char *name, *value;
E 13
I 13
setenv(name, val)
	char *name, *val;
E 13
{
	register char **ep = environ;
	register char *cp, *dp;
	char *blk[2], **oep = ep;

	for (; *ep; ep++) {
		for (cp = name, dp = *ep; *cp && *cp == *dp; cp++, dp++)
			continue;
		if (*cp != 0 || *dp != '=')
			continue;
D 13
		cp = strspl("=", value);
E 13
I 13
		cp = strspl("=", val);
E 13
		xfree(*ep);
		*ep = strspl(name, cp);
		xfree(cp);
D 13
		scan(ep, trim);
E 13
I 13
		trim(ep);
E 13
		return;
	}
	blk[0] = strspl(name, "="); blk[1] = 0;
	environ = blkspl(environ, blk);
	xfree((char *)oep);
D 13
	setenv(name, value);
E 13
I 13
	setenv(name, val);
E 13
}

unsetenv(name)
	char *name;
{
	register char **ep = environ;
	register char *cp, *dp;
	char **oep = ep;

	for (; *ep; ep++) {
		for (cp = name, dp = *ep; *cp && *cp == *dp; cp++, dp++)
			continue;
		if (*cp != 0 || *dp != '=')
			continue;
		cp = *ep;
		*ep = 0;
		environ = blkspl(environ, ep+1);
		*ep = cp;
		xfree(cp);
		xfree((char *)oep);
		return;
	}
}

doumask(v)
	register char **v;
{
	register char *cp = v[1];
	register int i;

	if (cp == 0) {
		i = umask(0);
D 13
		umask(i);
E 13
I 13
		(void) umask(i);
E 13
		printf("%o\n", i);
		return;
	}
	i = 0;
	while (digit(*cp) && *cp != '8' && *cp != '9')
		i = i * 8 + *cp++ - '0';
	if (*cp || i < 0 || i > 0777)
		bferr("Improper mask");
D 13
	umask(i);
E 13
I 13
	(void) umask(i);
E 13
}

D 2
#include <sys/limit.h>
E 2
I 2
D 7
#include <sys/vlimit.h>
E 7
E 2

struct limits {
	int	limconst;
	char	*limname;
	int	limdiv;
	char	*limscale;
} limits[] = {
D 7
	LIM_NORAISE,	"noraise",	1,	"",
	LIM_CPU,	"cputime",	1,	"seconds",
	LIM_FSIZE,	"filesize",	1024,	"kbytes",
	LIM_DATA,	"datasize",	1024,	"kbytes",
	LIM_STACK,	"stacksize",	1024,	"kbytes",
	LIM_CORE,	"coredumpsize",	1024,	"kbytes",
I 3
	LIM_MAXRSS,	"memoryuse",	1024,	"kbytes",
E 7
I 7
	RLIMIT_CPU,	"cputime",	1,	"seconds",
	RLIMIT_FSIZE,	"filesize",	1024,	"kbytes",
	RLIMIT_DATA,	"datasize",	1024,	"kbytes",
	RLIMIT_STACK,	"stacksize",	1024,	"kbytes",
	RLIMIT_CORE,	"coredumpsize",	1024,	"kbytes",
	RLIMIT_RSS,	"memoryuse",	1024,	"kbytes",
E 7
E 3
	-1,		0,
};

struct limits *
findlim(cp)
	char *cp;
{
	register struct limits *lp, *res;

	res = 0;
	for (lp = limits; lp->limconst >= 0; lp++)
		if (prefix(cp, lp->limname)) {
			if (res)
				bferr("Ambiguous");
			res = lp;
		}
	if (res)
		return (res);
	bferr("No such limit");
I 13
	/*NOTREACHED*/
E 13
}

dolimit(v)
	register char **v;
{
	register struct limits *lp;
	register int limit;
I 15
	char hard = 0;
E 15

	v++;
I 15
D 19
	if (eq(*v, "-h")) {
E 19
I 19
	if (*v && eq(*v, "-h")) {
E 19
		hard = 1;
		v++;
	}
E 15
	if (*v == 0) {
D 15
		for (lp = limits+1; lp->limconst >= 0; lp++)
			plim(lp);
E 15
I 15
		for (lp = limits; lp->limconst >= 0; lp++)
			plim(lp, hard);
E 15
D 7
		if (vlimit(LIM_NORAISE, -1) && getuid())
			printf("Limits cannot be raised\n");
E 7
		return;
	}
	lp = findlim(v[0]);
	if (v[1] == 0) {
D 15
		plim(lp);
E 15
I 15
		plim(lp,  hard);
E 15
		return;
	}
	limit = getval(lp, v+1);
D 14
	setlim(lp, limit);
E 14
I 14
D 15
	if (setlim(lp, limit) < 0)
E 15
I 15
	if (setlim(lp, hard, limit) < 0)
E 15
		error(NOSTR);
E 14
}

getval(lp, v)
	register struct limits *lp;
	char **v;
{
	register float f;
	double atof();
	char *cp = *v++;

	f = atof(cp);
	while (digit(*cp) || *cp == '.' || *cp == 'e' || *cp == 'E')
		cp++;
	if (*cp == 0) {
		if (*v == 0)
			return ((int)(f+0.5) * lp->limdiv);
		cp = *v;
	}
D 7
	if (lp->limconst == LIM_NORAISE)
		goto badscal;
E 7
	switch (*cp) {

	case ':':
D 7
		if (lp->limconst != LIM_CPU)
E 7
I 7
		if (lp->limconst != RLIMIT_CPU)
E 7
			goto badscal;
		return ((int)(f * 60.0 + atof(cp+1)));

	case 'h':
D 7
		if (lp->limconst != LIM_CPU)
E 7
I 7
		if (lp->limconst != RLIMIT_CPU)
E 7
			goto badscal;
		limtail(cp, "hours");
		f *= 3600.;
		break;

	case 'm':
D 7
		if (lp->limconst == LIM_CPU) {
E 7
I 7
		if (lp->limconst == RLIMIT_CPU) {
E 7
			limtail(cp, "minutes");
			f *= 60.;
			break;
		}
	case 'M':
D 7
		if (lp->limconst == LIM_CPU)
E 7
I 7
		if (lp->limconst == RLIMIT_CPU)
E 7
			goto badscal;
		*cp = 'm';
		limtail(cp, "megabytes");
		f *= 1024.*1024.;
		break;

	case 's':
D 7
		if (lp->limconst != LIM_CPU)
E 7
I 7
		if (lp->limconst != RLIMIT_CPU)
E 7
			goto badscal;
		limtail(cp, "seconds");
		break;

	case 'k':
D 7
		if (lp->limconst == LIM_CPU)
E 7
I 7
		if (lp->limconst == RLIMIT_CPU)
E 7
			goto badscal;
		limtail(cp, "kbytes");
		f *= 1024;
		break;

	case 'u':
		limtail(cp, "unlimited");
D 7
		return (INFINITY);
E 7
I 7
		return (RLIM_INFINITY);
E 7

	default:
badscal:
		bferr("Improper or unknown scale factor");
	}
	return ((int)(f+0.5));
}

limtail(cp, str0)
	char *cp, *str0;
{
	register char *str = str0;

	while (*cp && *cp == *str)
		cp++, str++;
	if (*cp)
		error("Bad scaling; did you mean ``%s''?", str0);
}

D 15
plim(lp)
E 15
I 15
plim(lp, hard)
E 15
	register struct limits *lp;
I 15
	char hard;
E 15
{
D 7
	register int lim;
E 7
I 7
	struct rlimit rlim;
I 15
	int limit;
E 15
E 7

	printf("%s \t", lp->limname);
D 7
	lim = vlimit(lp->limconst, -1);
	if (lim == INFINITY)
E 7
I 7
D 13
	getrlimit(lp->limconst, &rlim);
E 13
I 13
	(void) getrlimit(lp->limconst, &rlim);
E 13
D 15
	if (rlim.rlim_cur == RLIM_INFINITY)
E 15
I 15
	limit = hard ? rlim.rlim_max : rlim.rlim_cur;
	if (limit == RLIM_INFINITY)
E 15
E 7
		printf("unlimited");
D 7
	else if (lp->limconst == LIM_CPU)
		psecs((long)lim);
E 7
I 7
	else if (lp->limconst == RLIMIT_CPU)
D 15
		psecs((long)rlim.rlim_cur);
E 15
I 15
		psecs((long)limit);
E 15
E 7
	else
D 7
		printf("%d %s", lim / lp->limdiv, lp->limscale);
E 7
I 7
D 15
		printf("%d %s", rlim.rlim_cur / lp->limdiv, lp->limscale);
E 15
I 15
		printf("%d %s", limit / lp->limdiv, lp->limscale);
E 15
E 7
	printf("\n");
}

dounlimit(v)
	register char **v;
{
	register struct limits *lp;
I 14
	int err = 0;
I 15
	char hard = 0;
E 15
E 14

	v++;
I 15
D 19
	if (eq(*v, "-h")) {
E 19
I 19
	if (*v && eq(*v, "-h")) {
E 19
		hard = 1;
		v++;
	}
E 15
	if (*v == 0) {
D 15
		for (lp = limits+1; lp->limconst >= 0; lp++)
D 7
			setlim(lp, INFINITY);
E 7
I 7
D 13
			setlim(lp, RLIM_INFINITY);
E 13
I 13
D 14
			setlim(lp, (int)RLIM_INFINITY);
E 14
I 14
			if (setlim(lp, (int)RLIM_INFINITY) < 0)
E 15
I 15
		for (lp = limits; lp->limconst >= 0; lp++)
			if (setlim(lp, hard, (int)RLIM_INFINITY) < 0)
E 15
				err++;
		if (err)
			error(NOSTR);
E 14
E 13
E 7
		return;
	}
	while (*v) {
		lp = findlim(*v++);
D 7
		setlim(lp, INFINITY);
E 7
I 7
D 13
		setlim(lp, RLIM_INFINITY);
E 13
I 13
D 14
		setlim(lp, (int)RLIM_INFINITY);
E 14
I 14
D 15
		if (setlim(lp, (int)RLIM_INFINITY) < 0)
E 15
I 15
		if (setlim(lp, hard, (int)RLIM_INFINITY) < 0)
E 15
			error(NOSTR);
E 14
E 13
E 7
	}
}

D 15
setlim(lp, limit)
E 15
I 15
setlim(lp, hard, limit)
E 15
	register struct limits *lp;
I 15
	char hard;
E 15
{
I 7
	struct rlimit rlim;
E 7

D 7
	if (vlimit(lp->limconst, limit) < 0)
E 7
I 7
D 13
	getrlimit(lp->limconst, &rlim);
E 13
I 13
	(void) getrlimit(lp->limconst, &rlim);
E 13
D 11
	rlim.rlim_cur = limit;
E 11
I 11
D 14
  	if(limit == RLIM_INFINITY && geteuid() != 0)
E 14
I 14
D 15
  	if (limit == RLIM_INFINITY && geteuid() != 0)
E 15
I 15
	if (hard)
		rlim.rlim_max = limit;
  	else if (limit == RLIM_INFINITY && geteuid() != 0)
E 15
E 14
 		rlim.rlim_cur = rlim.rlim_max;
 	else
D 13
 		rlim.rlim_cur = limit;     
E 13
I 13
 		rlim.rlim_cur = limit;
E 13
E 11
D 14
	if (setrlimit(lp->limconst, &rlim) < 0)
E 7
		Perror(bname);
E 14
I 14
	if (setrlimit(lp->limconst, &rlim) < 0) {
D 15
		printf("%s: %s: Can't %s limit\n", bname, lp->limname,
		    limit == RLIM_INFINITY ? "remove" : "set");
E 15
I 15
		printf("%s: %s: Can't %s%s limit\n", bname, lp->limname,
		    limit == RLIM_INFINITY ? "remove" : "set",
		    hard ? " hard" : "");
E 15
		return (-1);
	}
	return (0);
E 14
}

dosuspend()
{
D 9
	int old, ldisc;
E 9
I 9
D 12
	int (*old)(), ldisc;
E 9
D 8
	short ctpgrp;
E 8
I 8
	int ctpgrp;
E 12
I 12
	int ldisc, ctpgrp;
	int (*old)();
E 12
E 8

	if (loginsh)
		error("Can't suspend a login shell (yet)");
	untty();
D 9
	old = sigsys(SIGTSTP, SIG_DFL);
E 9
I 9
D 10
	old = signal(SIGTSTP, SIG_DFL);
E 10
I 10
D 12
	old = sigsys(SIGTSTP, SIG_DFL);
E 12
I 12
	old = signal(SIGTSTP, SIG_DFL);
E 12
E 10
E 9
D 13
	kill(0, SIGTSTP);
E 13
I 13
	(void) kill(0, SIGTSTP);
E 13
	/* the shell stops here */
D 9
	sigsys(SIGTSTP, old);
E 9
I 9
D 10
	signal(SIGTSTP, old);
E 10
I 10
D 12
	sigsys(SIGTSTP, old);
E 12
I 12
D 13
	signal(SIGTSTP, old);
E 13
I 13
	(void) signal(SIGTSTP, old);
E 13
E 12
E 10
E 9
	if (tpgrp != -1) {
retry:
D 13
		ioctl(FSHTTY, TIOCGPGRP, &ctpgrp);
E 13
I 13
		(void) ioctl(FSHTTY, TIOCGPGRP, (char *)&ctpgrp);
E 13
		if (ctpgrp != opgrp) {
D 9
			old = sigsys(SIGTTIN, SIG_DFL);
E 9
I 9
D 10
			old = signal(SIGTTIN, SIG_DFL);
E 10
I 10
D 12
			old = sigsys(SIGTTIN, SIG_DFL);
E 12
I 12
			old = signal(SIGTTIN, SIG_DFL);
E 12
E 10
E 9
D 13
			kill(0, SIGTTIN);
D 9
			sigsys(SIGTTIN, old);
E 9
I 9
D 10
			signal(SIGTTIN, old);
E 10
I 10
D 12
			sigsys(SIGTTIN, old);
E 12
I 12
			signal(SIGTTIN, old);
E 13
I 13
			(void) kill(0, SIGTTIN);
			(void) signal(SIGTTIN, old);
E 13
E 12
E 10
E 9
			goto retry;
		}
D 13
		ioctl(FSHTTY, TIOCSPGRP, &shpgrp);
		setpgrp(0, shpgrp);
E 13
I 13
		(void) ioctl(FSHTTY, TIOCSPGRP, (char *)&shpgrp);
		(void) setpgrp(0, shpgrp);
E 13
	}
D 13
	ioctl(FSHTTY, TIOCGETD, &oldisc);
E 13
I 13
	(void) ioctl(FSHTTY, TIOCGETD, (char *)&oldisc);
E 13
	if (oldisc != NTTYDISC) {
		printf("Switching to new tty driver...\n");
		ldisc = NTTYDISC;
D 13
		ioctl(FSHTTY, TIOCSETD, &ldisc);
E 13
I 13
		(void) ioctl(FSHTTY, TIOCSETD, (char *)&ldisc);
E 13
	}
}

doeval(v)
	char **v;
{
	char **oevalvec = evalvec;
	char *oevalp = evalp;
	jmp_buf osetexit;
	int reenter;
	char **gv = 0;

	v++;
	if (*v == 0)
		return;
D 13
	gflag = 0; rscan(v, tglob);
E 13
I 13
	gflag = 0, tglob(v);
E 13
	if (gflag) {
		gv = v = glob(v);
		gargv = 0;
		if (v == 0)
			error("No match");
		v = copyblk(v);
	} else
D 13
		scan(v, trim);
E 13
I 13
		trim(v);
E 13
	getexit(osetexit);
	reenter = 0;
	setexit();
	reenter++;
	if (reenter == 1) {
		evalvec = v;
		evalp = 0;
		process(0);
	}
	evalvec = oevalvec;
	evalp = oevalp;
	doneinp = 0;
	if (gv)
		blkfree(gv);
	resexit(osetexit);
	if (reenter >= 2)
		error(NOSTR);
}
E 1
