h10582
s 00042/00000/00000
d D 1.1 85/07/19 13:59:42 jaap 1 0
c date and time created 85/07/19 13:59:42 by jaap
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (CWI) %E%";
#endif lint

#include	<stdio.h>
#include	"pic.h"
#include	"y.tab.h"

struct obj *troffgen(s)	/* save away a string of troff commands */
	YYSTYPE s;
{
	struct obj *p;

	if (strncmp(s.p, ".PS", 3) == 0)
		yyerror(".PS found inside .PS/.PE");
	savetext(CENTER, s.p);	/* use the existing text mechanism */
	p = makenode(TROFF, 0);
	return(p);
}

savetext(t, s)	/* record text elements for current object */
	int t;
	char *s;
{
	switch (t) {
	case CENTER:	t = 'C'; break;
	case LJUST:	t = 'L'; break;
	case RJUST:	t = 'R'; break;
	case SPREAD:	t = 'S'; break;
	case FILL:	t = 'F'; break;
	case ABOVE:	t = 'A'; break;
	case BELOW:	t = 'B'; break;
	}
	if (ntext >= MAXTEXT) {
		yyerror("too many text strings (%d)\n", ntext);
		exit(1);
	}
	text[ntext].t_type = t;
	text[ntext].t_val = s;
	dprintf("saving %c text %s at %d\n", t, s, ntext);
	ntext++;
}
E 1
