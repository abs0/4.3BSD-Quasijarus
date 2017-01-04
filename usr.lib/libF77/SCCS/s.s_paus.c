h19453
s 00005/00001/00050
d D 5.1 85/06/07 22:35:30 kre 2 1
c Add copyright
e
s 00051/00000/00000
d D 1.1 83/01/21 11:19:01 dlw 1 0
c date and time created 83/01/21 11:19:01 by dlw
e
u
U
t
T
I 1
/*
D 2
 *	"%W%"
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 2
 */

#include <stdio.h>
#define PAUSESIG 15


s_paus(s, n)
char *s;
long int n;
{
int i;
int waitpause();

fprintf(stderr, "PAUSE: ");
if(n > 0)
	{
	for(i = 0; i<n ; ++i)
		putc(*s++, stderr);
	putc('\n', stderr);
	}
if( isatty(fileno(stdin)) )
	{
	fprintf(stderr, "To resume execution, type:   go\nAny other input will terminate the program.\n");
	if( getchar()!='g' || getchar()!='o' || getchar()!='\n' )
		{
		fprintf(stderr, "STOP\n");
		f_exit();
		_cleanup();
		exit(0);
		}
	}
else
	{
	fprintf(stderr, "To resume execution, type:    kill -%d %d\n",
		PAUSESIG, getpid() );
	signal(PAUSESIG, waitpause);
	pause();
	}
fprintf(stderr, "Execution resumed after PAUSE.\n");
}





static waitpause()
{
return;
}
E 1
