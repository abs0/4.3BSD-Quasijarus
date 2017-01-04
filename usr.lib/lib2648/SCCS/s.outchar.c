h24757
s 00009/00001/00044
d D 5.1 85/04/26 12:28:59 dist 2 1
c Add copyright
e
s 00045/00000/00000
d D 4.1 83/03/09 16:23:04 ralph 1 0
c date and time created 83/03/09 16:23:04 by ralph
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
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

#include "2648.h"

outchar(c)
char c;
{
	extern int QUIET;
#ifdef TRACE
	if (trace)
		fprintf(trace, "%s", rdchar(c));
#endif
	if (QUIET)
		return;
	_outcount++;
	putchar(c);

	/* Do 2648 ^E/^F handshake */
	if (_outcount > TBLKSIZ && _on2648) {
#ifdef TRACE
		if (trace)
			fprintf(trace, "ENQ .. ");
#endif
		putchar(ENQ);
		fflush(stdout);
		c = getchar();
		while (c != ACK) {
			if (_pb_front == NULL) {
				_pb_front = _pushback;
				_pb_back = _pb_front - 1;
			}
			*++_pb_back = c;
#ifdef TRACE
			if (trace)
				fprintf(trace, "push back %s, front=%d, back=%d, ", rdchar(c), _pb_front-_pushback, _pb_front-_pushback);
#endif
			c = getchar();
		}
#ifdef TRACE
		if (trace)
			fprintf(trace, "ACK\n");
#endif
		_outcount = 0;
	}
}
E 1
