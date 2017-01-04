h62037
s 00002/00000/00026
d D 4.2 87/12/10 00:16:09 donn 2 1
c utah rcsid 1.2 86/08/03 01:07:55: Permit deflab to be a macro, for
c efficiency.
e
s 00026/00000/00000
d D 4.1 85/03/19 13:07:24 ralph 1 0
c date and time created 85/03/19 13:07:24 by ralph
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#ifndef _ONEPASS_
#define	_ONEPASS_
/*
 * Definitions for creating a one-pass
 * version of the compiler.
 */

#ifdef _PASS2_
#define crslab crs2lab
#define where where2
#define xdebug x2debug
#define tdebug t2debug
I 2
#ifndef deflab
E 2
#define deflab def2lab
I 2
#endif
E 2
#define edebug e2debug
#define eprint e2print
#define getlab get2lab
#define filename ftitle
#endif

/* NOPREF must be defined for use in first pass tree machine */
#define NOPREF	020000		/* no preference for register assignment */

#include "ndu.h"
#endif
E 1
