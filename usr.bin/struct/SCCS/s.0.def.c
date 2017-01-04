h27404
s 00015/00000/00000
d D 4.1 83/02/11 15:43:49 rrh 1 0
c date and time created 83/02/11 15:43:49 by rrh
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

int routnum;
FILE *debfd;
LOGICAL routerr;
int nodenum, accessnum;
int **graph;
int progtype;
VERT stopvert, retvert;
VERT START;
E 1
