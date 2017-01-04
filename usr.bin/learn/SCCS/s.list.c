h44422
s 00000/00000/00034
d D 4.2 83/04/25 23:58:53 mckusick 2 1
c 
e
s 00034/00000/00000
d D 4.1 83/02/24 12:55:51 mckusick 1 0
c date and time created 83/02/24 12:55:51 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "stdio.h"
#include "lrnref.h"
#include "signal.h"

int istop;

list(r)
char *r;
{
	int stop(), intrpt();
	FILE *ft;
	char s[100];

	if (r==0)
		return;
	istop = 1;
	signal(SIGINT, stop);
	ft = fopen(r, "r");
	if (ft != NULL) {
		while (fgets(s, 100, ft) && istop)
			fputs(s, stdout);
		fclose(ft);
	}
	signal(SIGINT, intrpt);
}

stop()
{
	istop=0;
}
E 1
