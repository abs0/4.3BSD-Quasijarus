h19745
s 00010/00001/00036
d D 5.1 85/04/26 12:31:07 dist 2 1
c Add copyright
e
s 00037/00000/00000
d D 4.1 83/03/09 16:23:09 ralph 1 0
c date and time created 83/03/09 16:23:09 by ralph
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
/*
 * get a character from the terminal, with no line buffering.
 */

#include "2648.h"

rawchar()
{
	char c;

	sync();
	escseq(NONE);
	fflush(stdout);
	if (_pb_front && _on2648) {
		c = *_pb_front++;
#ifdef TRACE
		if (trace)
			fprintf(trace, "%s from queue, front=%d, back=%d\n", rdchar(c), _pb_front-_pushback, _pb_back-_pushback);
#endif
		if (_pb_front > _pb_back) {
			_pb_front = _pb_back = NULL;
#ifdef TRACE
			if (trace)
				fprintf(trace, "reset pushback to null\n");
#endif
		}
		return (c);
	}
	_outcount = 0;
	c = getchar();
#ifdef TRACE
	if (trace)
		fprintf(trace, "rawchar '%s'\n", rdchar(c));
#endif
	return (c);
}
E 1
