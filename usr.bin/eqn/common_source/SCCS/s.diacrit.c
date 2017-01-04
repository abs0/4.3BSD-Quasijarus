h15118
s 00010/00010/00137
d D 4.5 04/09/17 22:13:00 msokolov 5 4
c some fixes for PS
e
s 00058/00016/00089
d D 4.4 04/09/15 04:22:04 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00102
d D 4.3 83/08/11 20:38:05 sam 3 2
c standardize sccs keyword lines
e
s 00050/00005/00053
d D 4.2 83/02/12 18:03:08 shannon 2 1
c merge eqn and neqn
e
s 00058/00000/00000
d D 4.1 83/02/11 18:27:40 shannon 1 0
c date and time created 83/02/11 18:27:40 by shannon
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

# include "e.h"
# include "e.def"

diacrit(p1, type) int p1, type; {
D 2
	int c, t, effps;
E 2
I 2
	int c, t;
#ifndef NEQN
	int effps;
#endif NEQN
E 2

	c = oalloc();
	t = oalloc();
I 2
#ifdef NEQN
	nrwid(p1, ps, p1);
	printf(".nr 10 %du\n", max(eht[p1]-ebase[p1]-VERT(2),0));
#else NEQN
E 2
	effps = EFFPS(ps);
	nrwid(p1, effps, p1);
I 4
#ifdef CAT
E 4
	printf(".nr 10 %du\n", VERT(max(eht[p1]-ebase[p1]-6*ps,0)));	/* vertical shift if high */
I 4
#endif
#ifdef PS
	printf(".nr 10 %du\n", VERT(max(eht[p1]-ebase[p1]-60*ps,0)));	/* vertical shift if high */
#endif
E 4
	printf(".if \\n(ct>1 .nr 10 \\n(10+\\s%d.25m\\s0\n", effps);
I 5
#endif NEQN
#ifdef CAT
E 5
	printf(".nr %d \\s%d.1m\\s0\n", t, effps);	/* horiz shift if high */
	printf(".if \\n(ct>1 .nr %d \\s%d.15m\\s0\n", t, effps);
I 2
D 5
#endif NEQN
E 5
I 5
#endif
E 5
E 2
	switch(type) {
D 2
		case VEC:
			printf(".ds %d \\v'-.4m'\\s%d\\(->\\s0\\v'.4m'\n", c, max(effps-3, 6));
E 2
I 2
		case VEC:	/* vec */
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
			printf(".ds %d \\v'-.4m'\\s%d\\(->\\s0\\v'.4m'\n",
			    c, max(effps-3, 6));
E 2
			break;
D 2
		case DYAD:
			printf(".ds %d \\v'-.4m'\\s%d\\z\\(<-\\(->\\s0\\v'.4m'\n", c, max(effps-3, 6));
E 2
I 2
D 4
#endif NEQN
E 4
I 4
#endif
#ifdef PS
			printf(".ds %d \\v'-.4m'\\s%d\\(->\\s0\\v'.4m'\n",
			    c, max(effps-3, 4));
			break;
#endif
E 4
		case DYAD:	/* dyad */
#ifdef NEQN
			printf(".ds %d \\v'-1'_\\v'1'\n", c);
D 4
#else NEQN
E 4
I 4
#endif
#ifdef CAT
E 4
			printf(".ds %d \\v'-.4m'\\s%d\\z\\(<-\\(->\\s0\\v'.4m'\n",
			    c, max(effps-3, 6));
D 4
#endif NEQN
E 4
I 4
#endif
#ifdef PS
			printf(".ds %d \\v'-.4m'\\s%d\\SAB\\s0\\v'.4m'\n",
			    c, max(effps-3, 4));
#endif
E 4
E 2
			break;
		case HAT:
I 4
#ifndef PS
E 4
			printf(".ds %d ^\n", c);
I 4
#else
			printf(".ds %d \\X93\n", c);
#endif
E 4
			break;
		case TILDE:
I 4
#ifndef PS
E 4
			printf(".ds %d ~\n", c);
I 4
#else
			printf(".ds %d \\X94\n", c);
#endif
E 4
			break;
		case DOT:
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
			printf(".ds %d \\s%d\\v'-.67m'.\\v'.67m'\\s0\n", c, effps);
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
			printf(".ds %d \\X97\n", c);
#endif
#ifdef NEQN
E 4
			printf(".ds %d \\v'-1'.\\v'1'\n", c);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
			break;
		case DOTDOT:
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
			printf(".ds %d \\s%d\\v'-.67m'..\\v'.67m\\s0'\n", c, effps);
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
			printf(".ds %d \\XA8\n", c);
#endif
#ifdef NEQN
E 4
			printf(".ds %d \\v'-1'..\\v'1'\n", c);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
			break;
		case BAR:
I 2
D 4
#ifndef NEQN
E 4
I 4
D 5
#ifdef CAT
E 5
I 5
#ifndef NEQN
E 5
E 4
E 2
			printf(".ds %d \\s%d\\v'.18m'\\h'.05m'\\l'\\n(%du-.1m\\(rn'\\h'.05m'\\v'-.18m'\\s0\n",
				c, effps, p1);
I 2
D 4
#else NEQN
E 4
I 4
D 5
#endif
#ifdef PS
			printf(".ds %d \\XAF\n", c);
#endif
#ifdef NEQN
E 5
I 5
#else
E 5
E 4
			printf(".ds %d \\v'-1'\\l'\\n(%du'\\v'1'\n", 
				c, p1);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
			break;
		case UNDER:
I 2
#ifndef NEQN
E 2
			printf(".ds %d \\l'\\n(%du\\(ul'\n", c, p1);
I 5
#ifdef CAT
E 5
			printf(".nr %d 0\n", t);
I 5
#endif
E 5
			printf(".nr 10 0-%d\n", ebase[p1]);
I 2
#else NEQN
			printf(".ds %d \\l'\\n(%du'\n", c, p1);
#endif NEQN
E 2
			break;
		}
	nrwid(c, ps, c);
I 2
D 5
#ifndef NEQN
E 5
I 5
#ifdef CAT
E 5
E 2
	if (lfont[p1] != ITAL)
		printf(".nr %d 0\n", t);
	printf(".as %d \\h'-\\n(%du-\\n(%du/2u+\\n(%du'\\v'0-\\n(10u'\\*(%d", 
		p1, p1, c, t, c);
	printf("\\v'\\n(10u'\\h'-\\n(%du+\\n(%du/2u-\\n(%du'\n", c, p1, t);
	/* BUG - should go to right end of widest */
I 2
D 5
#else NEQN
E 5
I 5
#else CAT
E 5
	printf(".as %d \\h'-\\n(%du-\\n(%du/2u'\\v'0-\\n(10u'\\*(%d", 
		p1, p1, c, c);
	printf("\\v'\\n(10u'\\h'-\\n(%du+\\n(%du/2u'\n", c, p1);
D 5
#endif NEQN
E 5
I 5
#endif CAT
E 5
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	if (type != UNDER)
		eht[p1] += VERT( (6*ps*15) / 100);	/* 0.15m */
	if(dbg)printf(".\tdiacrit: %c over S%d, lf=%c, rf=%c, h=%d,b=%d\n",
		type, p1, lfont[p1], rfont[p1], eht[p1], ebase[p1]);
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
E 4
	if (type != UNDER)
I 4
		eht[p1] += VERT( (6*ps*15) / 10);	/* 0.15m */
	if(dbg)printf(".\tdiacrit: %c over S%d, lf=%c, rf=%c, h=%d,b=%d\n",
		type, p1, lfont[p1], rfont[p1], eht[p1], ebase[p1]);
#endif
#ifdef NEQN
	if (type != UNDER)
E 4
		eht[p1] += VERT(1);
	if (dbg) printf(".\tdiacrit: %c over S%d, h=%d, b=%d\n", type, p1, eht[p1], ebase[p1]);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	ofree(c); ofree(t);
}
E 1
