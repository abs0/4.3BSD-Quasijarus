h63352
s 00008/00002/00007
d D 5.3 88/02/18 17:04:06 bostic 6 5
c written by Kurt Shoens; added Berkeley specific header
e
s 00000/00022/00009
d D 5.2 87/05/18 12:28:55 edward 5 4
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00007/00001/00024
d D 5.1 85/06/06 10:48:01 dist 4 3
c Add copyright
e
s 00001/00003/00024
d D 2.2 83/08/11 22:17:30 sam 3 2
c standardize sccs keyword lines
e
s 00000/00000/00027
d D 2.1 81/07/01 11:11:26 kurt 2 1
c Release to Heidi Stettner
e
s 00027/00000/00000
d D 1.1 80/10/08 09:53:46 kas 1 0
c date and time created 80/10/08 09:53:46 by kas
e
u
U
f b 
t
T
I 1
D 3
/*
 * Sccs Id = "%W% %G%";
 */
E 3
I 3
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 3

D 5
#ifdef V7
E 5
#include "v7.local.h"
D 5
#endif

#ifdef CORY
#include "c.local.h"
#endif

#ifdef INGRES
#include "ing.local.h"
#endif

#ifdef V6
#include "v6.local.h"
#endif

#ifdef CC
#include "cc.local.h"
#endif

#ifdef V40
#include "40.local.h"
#endif
E 5
E 1
