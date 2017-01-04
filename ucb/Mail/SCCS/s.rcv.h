h02613
s 00008/00002/00015
d D 5.3 88/02/18 17:04:19 bostic 7 6
c written by Kurt Shoens; added Berkeley specific header
e
s 00000/00003/00017
d D 5.2 87/05/18 12:28:45 edward 6 5
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00007/00001/00013
d D 5.1 85/06/06 10:48:18 dist 5 4
c Add copyright
e
s 00001/00005/00013
d D 2.3 83/08/11 22:19:31 sam 4 3
c standardize sccs keyword lines
e
s 00003/00000/00015
d D 2.2 82/10/21 04:43:25 carl 3 2
c Added ``#include <whoami.h>'' if pdp11 is defined.
e
s 00000/00000/00015
d D 2.1 81/07/01 11:11:29 kurt 2 1
c Release to Heidi Stettner
e
s 00015/00000/00000
d D 1.1 80/10/08 09:53:49 kas 1 0
c date and time created 80/10/08 09:53:49 by kas
e
u
U
f b 
t
T
I 1
D 4
#
E 4
I 4
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 5
E 4

/*
 * Mail -- a mail program
 *
 * This file is included by normal files which want both
 * globals and declarations.
D 4
 */

/*
 * Sccs Id = "%W% %G%";
E 4
 */

I 3
D 6
#ifdef	pdp11
#include <whoami.h>
#endif
E 6
E 3
#include "def.h"
#include "glob.h"
E 1
