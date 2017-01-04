h63019
s 00004/00000/00067
d D 4.4 10/10/05 04:21:46 msokolov 4 3
c fat kludge scaled appropriately for pstroff
e
s 00003/00001/00064
d D 4.3 83/08/11 20:38:14 sam 3 2
c standardize sccs keyword lines
e
s 00004/00000/00061
d D 4.2 83/02/12 18:03:20 shannon 2 1
c merge eqn and neqn
e
s 00061/00000/00000
d D 4.1 83/02/11 18:27:59 shannon 1 0
c date and time created 83/02/11 18:27:59 by shannon
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

setfont(ch1) char ch1; {
	/* use number '1', '2', '3' for roman, italic, bold */
	yyval = ft;
	if (ch1 == 'r' || ch1 == 'R')
		ft = ROM;
	else if (ch1 == 'i' || ch1 == 'I')
		ft = ITAL;
	else if (ch1 == 'b' || ch1 == 'B')
		ft = BLD;
	else
		ft = ch1;
	printf(".ft %c\n", ft);
I 2
#ifndef NEQN
E 2
	if(dbg)printf(".\tsetfont %c %c\n", ch1, ft);
I 2
#else NEQN
	if(dbg)printf(".\tsetfont %c\n", ft);
#endif NEQN
E 2
}

font(p1, p2) int p1, p2; {
		/* old font in p1, new in ft */
	yyval = p2;
	lfont[yyval] = rfont[yyval] = ft==ITAL ? ITAL : ROM;
	if(dbg)printf(".\tb:fb: S%d <- \\f%c S%d \\f%c b=%d,h=%d,lf=%c,rf=%c\n", 
		yyval, ft, p2, p1, ebase[yyval], eht[yyval], lfont[yyval], rfont[yyval]);
	printf(".ds %d \\f%c\\*(%d\\f%c\n", 
		yyval, ft, p2, p1);
	ft = p1;
	printf(".ft %c\n", ft);
}

fatbox(p) int p; {
	int sh;

	yyval = p;
I 4
#ifdef PS
	sh = ps * 10 / 4;
#else
E 4
	sh = ps / 4;
I 4
#endif
E 4
	nrwid(p, ps, p);
	printf(".ds %d \\*(%d\\h'-\\n(%du+%du'\\*(%d\n", p, p, p, sh, p);
	if(dbg)printf(".\tfat %d, sh=%d\n", p, sh);
}

globfont() {
	char temp[20];

	getstr(temp, 20);
	yyval = eqnreg = 0;
	gfont = temp[0];
	switch (gfont) {
	case 'r': case 'R':
		gfont = '1';
		break;
	case 'i': case 'I':
		gfont = '2';
		break;
	case 'b': case 'B':
		gfont = '3';
		break;
	}
	printf(".ft %c\n", gfont);
	ft = gfont;
}
E 1
