h05059
s 00049/00000/00000
d D 4.1 83/02/11 15:44:33 rrh 1 0
c date and time created 83/02/11 15:44:33 by rrh
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
#
/* for testing only */
#include "def.h"
#include "2.def.h"

testaft()
	{
	int i;
	for (i = 0; i < nodenum; ++i)
		fprintf(stderr,"ntoaft[%d] = %d, ntobef[%d] = %d\n",i,ntoaft[i],i,ntobef[i]);
	fprintf(stderr,"\n");
	for (i = 0; i < accessnum; ++i)
		fprintf(stderr,"after[%d] = %d\n",i,after[i]);
	}

testhead(head)
VERT *head;
	{
	VERT v;
	for (v = 0; v < nodenum; ++v)
		fprintf(stderr,"head[%d] = %d\n",v,head[v]);
	}

testdom(dom)
VERT *dom;
	{
	VERT v;
	for (v = 0; v < nodenum; ++v)
		fprintf(stderr,"dom[%d] = %d\n",v,dom[v]);
	}


testtree()
	{
	VERT v;
	int i;
	for (v = 0; v < nodenum; ++v)
		{
		fprintf(stderr,"%d: RSIB %d, ",v,RSIB(v));
		for (i = 0; i < CHILDNUM(v); ++i)
			fprintf(stderr," %d",LCHILD(v,i));
		fprintf(stderr,"\n");
		}
	}
E 1
