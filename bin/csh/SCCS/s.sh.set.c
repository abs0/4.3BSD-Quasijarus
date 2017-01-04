h03612
s 00004/00004/00697
d D 5.3 88/05/19 15:39:07 bostic 7 6
c install C version of _doprnt
e
s 00003/00003/00698
d D 5.2 85/06/06 13:10:29 edward 6 5
c cleaning up after bozos
e
s 00008/00002/00693
d D 5.1 85/06/04 11:08:01 dist 5 4
c Add copyright
e
s 00260/00120/00435
d D 4.4 84/12/13 14:41:09 edward 4 3
c performance
e
s 00001/00001/00554
d D 4.3 84/08/31 09:31:40 ralph 3 2
c use new signal calls instead of compatibility routines.
e
s 00003/00003/00552
d D 4.2 83/11/02 14:51:58 layer 2 1
c don't allow "@ 1 = 1", but do allow "@ t1 = 1"
e
s 00555/00000/00000
d D 4.1 80/10/09 12:41:53 bill 1 0
c date and time created 80/10/09 12:41:53 by bill
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
E 6
I 6
 * All rights reserved.  The Berkeley Software License Agreement
E 6
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
D 4
static	char *sccsid = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 5
I 5
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
I 6
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 6
E 5
E 4

#include "sh.h"

/*
 * C Shell
 */

doset(v)
	register char **v;
{
	register char *p;
	char *vp, op;
	char **vecp;
	bool hadsub;
	int subscr;

	v++;
	p = *v++;
	if (p == 0) {
		prvars();
		return;
	}
	do {
		hadsub = 0;
		for (vp = p; alnum(*p); p++)
			continue;
D 2
		if (vp == p)
E 2
I 2
		if (vp == p || !letter(*vp))
E 2
			goto setsyn;
		if (*p == '[') {
			hadsub++;
			p = getinx(p, &subscr);
		}
		if (op = *p) {
			*p++ = 0;
			if (*p == 0 && *v && **v == '(')
				p = *v++;
		} else if (*v && eq(*v, "=")) {
			op = '=', v++;
			if (*v)
				p = *v++;
		}
		if (op && op != '=')
setsyn:
			bferr("Syntax error");
		if (eq(p, "(")) {
			register char **e = v;

			if (hadsub)
				goto setsyn;
			for (;;) {
				if (!*e)
					bferr("Missing )");
				if (**e == ')')
					break;
				e++;
			}
			p = *e;
			*e = 0;
			vecp = saveblk(v);
			set1(vp, vecp, &shvhed);
			*e = p;
			v = e + 1;
		} else if (hadsub)
			asx(vp, subscr, savestr(p));
		else
			set(vp, savestr(p));
		if (eq(vp, "path")) {
			exportpath(adrof("path")->vec);
			dohash();
		} else if (eq(vp, "histchars")) {
			register char *p = value("histchars");

			HIST = *p++;
			HISTSUB = *p;
		} else if (eq(vp, "user"))
			setenv("USER", value(vp));
		else if (eq(vp, "term"))
			setenv("TERM", value(vp));
		else if (eq(vp, "home"))
			setenv("HOME", value(vp));
I 4
#ifdef FILEC
		else if (eq(vp, "filec"))
			filec = 1;
#endif
E 4
	} while (p = *v++);
}

char *
getinx(cp, ip)
	register char *cp;
	register int *ip;
{

	*ip = 0;
	*cp++ = 0;
	while (*cp && digit(*cp))
		*ip = *ip * 10 + *cp++ - '0';
	if (*cp++ != ']')
		bferr("Subscript error");
	return (cp);
}

asx(vp, subscr, p)
	char *vp;
	int subscr;
	char *p;
{
	register struct varent *v = getvx(vp, subscr);

	xfree(v->vec[subscr - 1]);
	v->vec[subscr - 1] = globone(p);
}

struct varent *
getvx(vp, subscr)
I 4
	char *vp;
E 4
{
	register struct varent *v = adrof(vp);

	if (v == 0)
		udvar(vp);
	if (subscr < 1 || subscr > blklen(v->vec))
		bferr("Subscript out of range");
	return (v);
}

char	plusplus[2] = { '1', 0 };

D 4

E 4
dolet(v)
	char **v;
{
	register char *p;
	char *vp, c, op;
	bool hadsub;
	int subscr;

	v++;
	p = *v++;
	if (p == 0) {
		prvars();
		return;
	}
	do {
		hadsub = 0;
D 2
		for (vp = p; letter(*p); p++)
E 2
I 2
		for (vp = p; alnum(*p); p++)
E 2
			continue;
D 2
		if (vp == p)
E 2
I 2
		if (vp == p || !letter(*vp))
E 2
			goto letsyn;
		if (*p == '[') {
			hadsub++;
			p = getinx(p, &subscr);
		}
		if (*p == 0 && *v)
			p = *v++;
		if (op = *p)
			*p++ = 0;
		else
			goto letsyn;
		vp = savestr(vp);
		if (op == '=') {
			c = '=';
			p = xset(p, &v);
		} else {
			c = *p++;
			if (any(c, "+-")) {
				if (c != op || *p)
					goto letsyn;
				p = plusplus;
			} else {
				if (any(op, "<>")) {
					if (c != op)
						goto letsyn;
					c = *p++;
letsyn:
					bferr("Syntax error");
				}
				if (c != '=')
					goto letsyn;
				p = xset(p, &v);
			}
		}
		if (op == '=')
			if (hadsub)
				asx(vp, subscr, p);
			else
				set(vp, p);
		else
			if (hadsub)
#ifndef V6
				/* avoid bug in vax CC */
				{
					struct varent *gv = getvx(vp, subscr);

					asx(vp, subscr, operate(op, gv->vec[subscr - 1], p));
				}
#else
				asx(vp, subscr, operate(op, getvx(vp, subscr)->vec[subscr - 1], p));
#endif
			else
				set(vp, operate(op, value(vp), p));
D 4
		if (strcmp(vp, "path") == 0)
E 4
I 4
		if (eq(vp, "path")) {
			exportpath(adrof("path")->vec);
E 4
			dohash();
D 4
		xfree(vp);
E 4
I 4
		}
		XFREE(vp)
E 4
		if (c != '=')
D 4
			xfree(p);
E 4
I 4
			XFREE(p)
E 4
	} while (p = *v++);
}

char *
xset(cp, vp)
	char *cp, ***vp;
{
	register char *dp;

	if (*cp) {
		dp = savestr(cp);
		--(*vp);
		xfree(**vp);
		**vp = dp;
	}
	return (putn(exp(vp)));
}

char *
operate(op, vp, p)
	char op, *vp, *p;
{
	char opr[2];
	char *vec[5];
	register char **v = vec;
	char **vecp = v;
	register int i;

	if (op != '=') {
		if (*vp)
			*v++ = vp;
		opr[0] = op;
		opr[1] = 0;
		*v++ = opr;
		if (op == '<' || op == '>')
			*v++ = opr;
	}
	*v++ = p;
	*v++ = 0;
	i = exp(&vecp);
	if (*vecp)
		bferr("Expression syntax");
	return (putn(i));
}

D 4
onlyread(cp)
	char *cp;
{
	extern char end[];

	return (cp < end);
}

xfree(cp)
	char *cp;
{
	extern char end[];

	if (cp >= end && cp < (char *) &cp)
D 3
		cfree(cp);
E 3
I 3
		free(cp);
E 3
}

char *
savestr(s)
	register char *s;
{
	register char *n;

	if (s == 0)
		s = "";
	strcpy(n = calloc(1, strlen(s) + 1), s);
	return (n);
}

E 4
static	char *putp;
 
char *
putn(n)
	register int n;
{
	static char number[15];

	putp = number;
	if (n < 0) {
		n = -n;
		*putp++ = '-';
	}
	if (sizeof (int) == 2 && n == -32768) {
		*putp++ = '3';
		n = 2768;
#ifdef pdp11
	}
#else
	} else if (sizeof (int) == 4 && n == -2147483648) {
		*putp++ = '2';
		n = 147483648;
	}
#endif
	putn1(n);
	*putp = 0;
	return (savestr(number));
}

putn1(n)
	register int n;
{
	if (n > 9)
		putn1(n / 10);
	*putp++ = n % 10 + '0';
}

getn(cp)
	register char *cp;
{
	register int n;
	int sign;

	sign = 0;
	if (cp[0] == '+' && cp[1])
		cp++;
	if (*cp == '-') {
		sign++;
		cp++;
		if (!digit(*cp))
			goto badnum;
	}
	n = 0;
	while (digit(*cp))
		n = n * 10 + *cp++ - '0';
	if (*cp)
		goto badnum;
	return (sign ? -n : n);
badnum:
	bferr("Badly formed number");
	return (0);
}

char *
D 4
value(var)
	char *var;
{

	return (value1(var, &shvhed));
}

char *
E 4
value1(var, head)
	char *var;
	struct varent *head;
{
	register struct varent *vp;

	vp = adrof1(var, head);
	return (vp == 0 || vp->vec[0] == 0 ? "" : vp->vec[0]);
}

D 4
static	struct varent *shprev;

E 4
struct varent *
D 4
adrof(var)
	char *var;
{

	return (adrof1(var, &shvhed));
}

struct varent *
madrof(pat, head)
E 4
I 4
madrof(pat, vp)
E 4
	char *pat;
D 4
	struct varent *head;
{
E 4
	register struct varent *vp;
I 4
{
	register struct varent *vp1;
E 4

D 4
	shprev = head;
	for (vp = shprev->link; vp != 0; vp = vp->link) {
		if (Gmatch(vp->name, pat))
			return (vp);
		shprev = vp;
E 4
I 4
	for (; vp; vp = vp->v_right) {
		if (vp->v_left && (vp1 = madrof(pat, vp->v_left)))
			return vp1;
		if (Gmatch(vp->v_name, pat))
			return vp;
E 4
	}
D 4
	return (0);
E 4
I 4
	return vp;
E 4
}

struct varent *
D 4
adrof1(var, head)
	char *var;
	struct varent *head;
E 4
I 4
adrof1(name, v)
	register char *name;
	register struct varent *v;
E 4
{
D 4
	register struct varent *vp;
	int cmp;
E 4
I 4
	register cmp;
E 4

D 4
	shprev = head;
	for (vp = shprev->link; vp != 0; vp = vp->link) {
		cmp = strcmp(vp->name, var);
		if (cmp == 0)
			return (vp);
		else if (cmp > 0)
			return (0);
		shprev = vp;
	}
	return (0);
E 4
I 4
	v = v->v_left;
	while (v && ((cmp = *name - *v->v_name) ||
		     (cmp = strcmp(name, v->v_name))))
		if (cmp < 0)
			v = v->v_left;
		else
			v = v->v_right;
	return v;
E 4
}

/*
 * The caller is responsible for putting value in a safe place
 */
D 4
set(var, value)
	char *var, *value;
E 4
I 4
set(var, val)
	char *var, *val;
E 4
{
D 4
	register char **vec = (char **) calloc(2, sizeof (char **));
E 4
I 4
	register char **vec = (char **) xalloc(2 * sizeof (char **));
E 4

D 4
	vec[0] = onlyread(value) ? savestr(value) : value;
E 4
I 4
	vec[0] = onlyread(val) ? savestr(val) : val;
	vec[1] = 0;
E 4
	set1(var, vec, &shvhed);
}

set1(var, vec, head)
	char *var, **vec;
	struct varent *head;
{
D 4

E 4
	register char **oldv = vec;

D 4
	gflag = 0; rscan(oldv, tglob);
E 4
I 4
	gflag = 0; tglob(oldv);
E 4
	if (gflag) {
		vec = glob(oldv);
		if (vec == 0) {
			bferr("No match");
			blkfree(oldv);
			return;
		}
		blkfree(oldv);
		gargv = 0;
	}
	setq(var, vec, head);
}

D 4
setq(var, vec, head)
	char *var, **vec;
	struct varent *head;
E 4
I 4
setq(name, vec, p)
	char *name, **vec;
	register struct varent *p;
E 4
{
D 4
	register struct varent *vp;
E 4
I 4
	register struct varent *c;
	register f;
E 4

D 4
	vp = adrof1(var, head);
	if (vp == 0) {
		vp = (struct varent *) calloc(1, sizeof *vp);
		vp->name = savestr(var);
		vp->link = shprev->link;
		shprev->link = vp;
E 4
I 4
	f = 0;			/* tree hangs off the header's left link */
	while (c = p->v_link[f]) {
		if ((f = *name - *c->v_name) == 0 &&
		    (f = strcmp(name, c->v_name)) == 0) {
			blkfree(c->vec);
			goto found;
		}
		p = c;
		f = f > 0;
E 4
	}
D 4
	if (vp->vec)
		blkfree(vp->vec);
	scan(vec, trim);
	vp->vec = vec;
E 4
I 4
	p->v_link[f] = c = (struct varent *)xalloc(sizeof (struct varent));
	c->v_name = savestr(name);
	c->v_bal = 0;
	c->v_left = c->v_right = 0;
	c->v_parent = p;
	balance(p, f, 0);
found:
	trim(c->vec = vec);
E 4
}

unset(v)
D 4
	register char *v[];
E 4
I 4
	char *v[];
E 4
{

	unset1(v, &shvhed);
	if (adrof("histchars") == 0) {
		HIST = '!';
		HISTSUB = '^';
	}
I 4
#ifdef FILEC
	if (adrof("filec") == 0)
		filec = 0;
#endif
E 4
}

unset1(v, head)
	register char *v[];
	struct varent *head;
{
D 4
	register char *var;
E 4
	register struct varent *vp;
	register int cnt;

D 4
	v++;
	while (var = *v++) {
E 4
I 4
	while (*++v) {
E 4
		cnt = 0;
D 4
		while (vp = madrof(var, head))
			unsetv1(vp->name, head), cnt++;
E 4
I 4
		while (vp = madrof(*v, head->v_left))
			unsetv1(vp), cnt++;
E 4
		if (cnt == 0)
D 4
			setname(var);
E 4
I 4
			setname(*v);
E 4
	}
}

unsetv(var)
	char *var;
{
I 4
	register struct varent *vp;
E 4

D 4
	unsetv1(var, &shvhed);
E 4
I 4
	if ((vp = adrof1(var, &shvhed)) == 0)
		udvar(var);
	unsetv1(vp);
E 4
}

D 4
unsetv1(var, head)
	char *var;
	struct varent *head;
E 4
I 4
unsetv1(p)
	register struct varent *p;
E 4
{
D 4
	register struct varent *vp;
E 4
I 4
	register struct varent *c, *pp;
	register f;
E 4

D 4
	vp = adrof1(var, head);
	if (vp == 0)
		udvar(var);
	vp = shprev->link;
	shprev->link = vp->link;
	blkfree(vp->vec);
	xfree(vp->name);
	xfree((char *)vp);
E 4
I 4
	/*
	 * Free associated memory first to avoid complications.
	 */
	blkfree(p->vec);
	XFREE(p->v_name);
	/*
	 * If p is missing one child, then we can move the other
	 * into where p is.  Otherwise, we find the predecessor
	 * of p, which is guaranteed to have no right child, copy
	 * it into p, and move it's left child into it.
	 */
	if (p->v_right == 0)
		c = p->v_left;
	else if (p->v_left == 0)
		c = p->v_right;
	else {
		for (c = p->v_left; c->v_right; c = c->v_right)
			;
		p->v_name = c->v_name;
		p->vec = c->vec;
		p = c;
		c = p->v_left;
	}
	/*
	 * Move c into where p is.
	 */
	pp = p->v_parent;
	f = pp->v_right == p;
	if (pp->v_link[f] = c)
		c->v_parent = pp;
	/*
	 * Free the deleted node, and rebalance.
	 */
	XFREE((char *)p);
	balance(pp, f, 1);
E 4
}

setNS(cp)
	char *cp;
{

	set(cp, "");
}

shift(v)
	register char **v;
{
	register struct varent *argv;
	register char *name;

	v++;
	name = *v;
	if (name == 0)
		name = "argv";
	else
D 4
		strip(name);
E 4
I 4
		(void) strip(name);
E 4
	argv = adrof(name);
	if (argv == 0)
		udvar(name);
	if (argv->vec[0] == 0)
		bferr("No more words");
	lshift(argv->vec, 1);
}

exportpath(val)
char **val;
{
	char exppath[BUFSIZ];
D 4
	register char *dir;
E 4

	exppath[0] = 0;
	if (val)
		while (*val) {
			if (strlen(*val) + strlen(exppath) + 2 > BUFSIZ) {
				printf("Warning: ridiculously long PATH truncated\n");
				break;
			}
D 4
			strcat(exppath, *val++);
E 4
I 4
			(void) strcat(exppath, *val++);
E 4
			if (*val == 0 || eq(*val, ")"))
				break;
D 4
			strcat(exppath, ":");
E 4
I 4
			(void) strcat(exppath, ":");
E 4
		}
	setenv("PATH", exppath);
I 4
}

	/* macros to do single rotations on node p */
#define rright(p) (\
	t = (p)->v_left,\
	(t)->v_parent = (p)->v_parent,\
	((p)->v_left = t->v_right) ? (t->v_right->v_parent = (p)) : 0,\
	(t->v_right = (p))->v_parent = t,\
	(p) = t)
#define rleft(p) (\
	t = (p)->v_right,\
	(t)->v_parent = (p)->v_parent,\
	((p)->v_right = t->v_left) ? (t->v_left->v_parent = (p)) : 0,\
	(t->v_left = (p))->v_parent = t,\
	(p) = t)

/*
 * Rebalance a tree, starting at p and up.
 * F == 0 means we've come from p's left child.
 * D == 1 means we've just done a delete, otherwise an insert.
 */
balance(p, f, d)
	register struct varent *p;
	register f;
{
	register struct varent *pp;
	register struct varent *t;		/* used by the rotate macros */
	register ff;

	/*
	 * Ok, from here on, p is the node we're operating on;
	 * pp is it's parent; f is the branch of p from which we have come;
	 * ff is the branch of pp which is p.
	 */
	for (; pp = p->v_parent; p = pp, f = ff) {
		ff = pp->v_right == p;
		if (f ^ d) {		/* right heavy */
			switch (p->v_bal) {
			case -1:		/* was left heavy */
				p->v_bal = 0;
				break;
			case 0:			/* was balanced */
				p->v_bal = 1;
				break;
			case 1:			/* was already right heavy */
				switch (p->v_right->v_bal) {
				case 1:			/* sigle rotate */
					pp->v_link[ff] = rleft(p);
					p->v_left->v_bal = 0;
					p->v_bal = 0;
					break;
				case 0:			/* single rotate */
					pp->v_link[ff] = rleft(p);
					p->v_left->v_bal = 1;
					p->v_bal = -1;
					break;
				case -1:		/* double rotate */
					rright(p->v_right);
					pp->v_link[ff] = rleft(p);
					p->v_left->v_bal =
						p->v_bal < 1 ? 0 : -1;
					p->v_right->v_bal =
						p->v_bal > -1 ? 0 : 1;
					p->v_bal = 0;
					break;
				}
				break;
			}
		} else {		/* left heavy */
			switch (p->v_bal) {
			case 1:			/* was right heavy */
				p->v_bal = 0;
				break;
			case 0:			/* was balanced */
				p->v_bal = -1;
				break;
			case -1:		/* was already left heavy */
				switch (p->v_left->v_bal) {
				case -1:		/* single rotate */
					pp->v_link[ff] = rright(p);
					p->v_right->v_bal = 0;
					p->v_bal = 0;
					break;
				case 0:			/* signle rotate */
					pp->v_link[ff] = rright(p);
					p->v_right->v_bal = -1;
					p->v_bal = 1;
					break;
				case 1:			/* double rotate */
					rleft(p->v_left);
					pp->v_link[ff] = rright(p);
					p->v_left->v_bal =
						p->v_bal < 1 ? 0 : -1;
					p->v_right->v_bal =
						p->v_bal > -1 ? 0 : 1;
					p->v_bal = 0;
					break;
				}
				break;
			}
		}
		/*
		 * If from insert, then we terminate when p is balanced.
		 * If from delete, then we terminate when p is unbalanced.
		 */
		if ((p->v_bal == 0) ^ d)
			break;
	}
}

plist(p)
	register struct varent *p;
{
	register struct varent *c;
	register len;

	if (setintr)
		(void) sigsetmask(sigblock(0) & ~ sigmask(SIGINT));
	for (;;) {
		while (p->v_left)
			p = p->v_left;
	x:
		if (p->v_parent == 0)		/* is it the header? */
			return;
		len = blklen(p->vec);
		printf(p->v_name);
D 7
		putchar('\t');
E 7
I 7
		cshputchar('\t');
E 7
		if (len != 1)
D 7
			putchar('(');
E 7
I 7
			cshputchar('(');
E 7
		blkpr(p->vec);
		if (len != 1)
D 7
			putchar(')');
		putchar('\n');
E 7
I 7
			cshputchar(')');
		cshputchar('\n');
E 7
		if (p->v_right) {
			p = p->v_right;
			continue;
		}
		do {
			c = p;
			p = p->v_parent;
		} while (p->v_right == c);
		goto x;
	}
E 4
}
E 1
