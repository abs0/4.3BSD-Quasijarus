h41239
s 00003/00001/00018
d D 4.2 83/08/11 20:39:09 sam 2 1
c standardize sccs keyword lines
e
s 00019/00000/00000
d D 4.1 83/02/11 18:28:25 shannon 1 0
c date and time created 83/02/11 18:28:25 by shannon
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

#include "e.h"

mark(p1) int p1; {
	markline = 1;
	printf(".ds %d \\k(97\\*(%d\n", p1, p1);
	yyval = p1;
	if(dbg)printf(".\tmark %d\n", p1);
}

lineup(p1) {
	markline = 1;
	if (p1 == 0) {
		yyval = oalloc();
		printf(".ds %d \\h'|\\n(97u'\n", yyval);
	}
	if(dbg)printf(".\tlineup %d\n", p1);
}
E 1
