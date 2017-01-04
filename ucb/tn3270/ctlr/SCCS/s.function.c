h38663
s 00016/00000/00010
d D 3.2 88/03/28 12:34:13 bostic 4 3
c add Berkeley specific header
e
s 00000/00000/00010
d D 3.1 87/08/11 10:18:58 minshall 3 2
c New version numbering.
e
s 00000/00000/00010
d D 1.2 87/07/17 10:03:32 minshall 2 1
c Install sccs headers and copyright notices.
e
s 00010/00000/00000
d D 1.1 87/07/06 10:27:35 minshall 1 0
c date and time created 87/07/06 10:27:35 by minshall
e
u
U
t
T
I 1
/*
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

/*
E 4
 * This file, which never produces a function.o, is used solely to
 * be run through the preprocessor.
 *
 * On a 4.3 system (or even msdos), "cc -E function.h" would produce
 * the correct output.  Unfortunately, 4.2 compilers aren't quite that
 * useful.
 */

#include "function.h"
E 1
