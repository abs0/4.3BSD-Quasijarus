h06591
s 00002/00000/00029
d D 4.3 04/09/17 22:12:44 msokolov 3 2
c only do the italic padding on CAT, not needed on PS with Adobe fonts
e
s 00003/00001/00026
d D 4.2 83/08/11 20:38:11 sam 2 1
c standardize sccs keyword lines
e
s 00027/00000/00000
d D 4.1 83/02/11 18:27:57 shannon 1 0
c date and time created 83/02/11 18:27:57 by shannon
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 2

# include "e.h"

eqnbox(p1, p2, lu) {
	int b, h;
	char *sh;

	yyval = p1;
	b = max(ebase[p1], ebase[p2]);
	eht[yyval] = h = b + max(eht[p1]-ebase[p1], 
		eht[p2]-ebase[p2]);
	ebase[yyval] = b;
	if(dbg)printf(".\te:eb: S%d <- S%d S%d; b=%d, h=%d\n", 
		yyval, p1, p2, b, h);
I 3
#ifdef CAT
E 3
	if (rfont[p1] == ITAL && lfont[p2] == ROM)
		sh = "\\|";
	else
I 3
#endif
E 3
		sh = "";
	if (lu) {
		printf(".nr %d \\w'\\s%d\\*(%d%s'\n", p1, ps, p1, sh);
		printf(".ds %d \\h'|\\n(97u-\\n(%du'\\*(%d\n", p1, p1, p1);
	}
	printf(".as %d \"%s\\*(%d\n", yyval, sh, p2);
	rfont[p1] = rfont[p2];
	ofree(p2);
}
E 1
