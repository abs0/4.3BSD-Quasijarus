h13560
s 00052/00000/00000
d D 4.1 83/02/11 15:44:11 rrh 1 0
c date and time created 83/02/11 15:44:11 by rrh
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
#include "1.defs.h"
#include  "1.incl.h"
#include "def.h"


prog_init()
	{
	endline = endcom = 0;	endchar = -1;
	comchar = -1;
	graph = challoc(sizeof(*graph) * maxnode);
	}

routinit()
	{
	graf_init();
	progtype = !sub;
	routbeg = endline + 1;
	rtnbeg = endchar + 1;
	nameline = 0;
	stflag = UNDEFINED;
	}
line_init()
	{
	struct lablist *makelab();
	freelabs();
	newlab = linelabs = makelab(0L);
	flag = counter = nlabs = lswnum = swptr = p1 = 0;
	p3 = 5;
	endcom = endline;
	comchar = endchar;
	begline = endline + 1;	begchar = endchar + 1;
	reflab = endlab = errlab = 0;
	r1 = r2 = 0;
	}
graf_init()
	{
	int arctype[3];  long arclab[3];
	nodenum = 0;
	doptr = UNDEFINED;
	retvert = stopvert = UNDEFINED;
	ENTLST = FMTLST = 0;

	
	arctype[0] = -2;  arclab[0] = implicit;
	START = makenode(DUMVX,FALSE,FALSE,implicit,1,arctype,arclab);
	}

E 1
