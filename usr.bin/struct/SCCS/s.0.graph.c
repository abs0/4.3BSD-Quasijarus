h19975
s 00063/00000/00000
d D 4.1 83/02/11 15:43:53 rrh 1 0
c date and time created 83/02/11 15:43:53 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include <stdio.h>
#include "def.h"

#define TABOVER(n)	tabover(n,stderr)
prgraph()
	{
	VERT v;
	int i;
	if (progress) fprintf(stderr,"prgraph():\n");
	for (v = 0; v < nodenum; ++v)
		{
		fprintf(stderr,"%d %s:",v, typename[NTYPE(v)]);
		for (i = 0; i < ARCNUM(v); ++i)
			{
			printf("%d ",ARC(v,i));
			ASSERT(UNDEFINED <= ARC(v,i) && ARC(v,i) < nodenum, prgraph);
			}
		printf("\n");
		}
	printf("\n\n");
	}

prtree()
	{
	prtr(START,1);
	}

prtr(v,tab)		/* print tree in form of program indenting by tab */
VERT v;
int tab;
	{
	int i;
	TABOVER(tab);
	fprintf(stderr,"%d %s:",v,typename[NTYPE(v)]);
	for (i = 0; i < ARCNUM(v); ++i)
		fprintf(stderr," %d",ARC(v,i));
	printf("\n");
	for (i = 0; i < CHILDNUM(v); ++i)
		{
		TABOVER(tab+1);
		fprintf(stderr,"{\n");
		if (DEFINED(LCHILD(v,i)))
			prtr(LCHILD(v,i),tab+1);
		TABOVER(tab+1);
		fprintf(stderr,"}\n");
		}
	if (DEFINED(RSIB(v)))
		prtr(RSIB(v),tab);
	}


tabover(n,fd)		/* tab n times */
int n;
FILE *fd;
	{
	int i;
	for (i = 0; i < n; ++i)
		putc('\t',fd);
	}
E 1
