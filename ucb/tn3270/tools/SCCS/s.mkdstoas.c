h52924
s 00015/00018/00042
d D 3.2 88/03/28 12:08:20 bostic 10 9
c add Berkeley specific headers
e
s 00000/00000/00060
d D 3.1 87/08/11 10:20:47 minshall 9 8
c New version numbering.
e
s 00025/00000/00035
d D 1.8 87/07/17 10:06:10 minshall 8 7
c Install sccs headers and copyright notices.
e
s 00002/00002/00033
d D 1.7 87/07/15 15:27:20 minshall 7 6
c New directory structure.
e
s 00003/00003/00032
d D 1.6 87/06/19 12:52:50 minshall 6 5
c Directory changes.
e
s 00002/00002/00033
d D 1.5 87/05/21 21:58:07 minshall 5 4
c Minor fix (that would never actually occur).
e
s 00007/00001/00028
d D 1.4 87/05/12 14:10:45 minshall 4 3
c Various fixes for running under dos.
e
s 00001/00001/00028
d D 1.3 87/05/10 11:41:34 minshall 3 2
c Strings.h (sigh) and a small bug.
e
s 00008/00003/00021
d D 1.2 86/11/16 10:56:22 minshall 2 1
c Make disp_asc 256 characters, so we can have the last 64 point 
c at blanks (these last are attribute characters).
e
s 00024/00000/00000
d D 1.1 86/11/12 16:44:17 minshall 1 0
c date and time created 86/11/12 16:44:17 by minshall
e
u
U
t
T
I 8
/*
D 10
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 10
 *
D 10
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 10
I 10
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

#ifndef lint
I 10
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif	/* not lint */
E 10
I 10
#endif /* not lint */
E 10

E 8
I 1
#include <stdio.h>
I 4
#if	defined(unix)
E 4
D 3
#include <string.h>
E 3
I 3
#include <strings.h>
I 4
#else	/* defined(unix) */
#include <string.h>
#endif	/* defined(unix) */
E 4
E 3
#include <ctype.h>
D 6
#include "../ascii/ascebc.h"
#include "../ctlr/ebc_disp.h"
E 6
I 6
D 7
#include "../apilib/asc_ebc.h"
#include "../apilib/ebc_disp.h"
E 7
I 7
#include "../api/asc_ebc.h"
#include "../api/ebc_disp.h"
E 7
E 6


D 4
void
E 4
I 4
int
E 4
main()
{
    int i;

    /* For each display code, find the ascii code that matches */

D 2
    printf("unsigned char disp_asc[%d] = {", sizeof disp_ebc);
E 2
I 2
    printf("unsigned char disp_asc[256] = {");
E 2
    for (i = 0; i < sizeof disp_ebc; i++) {
	if ((i%8) == 0) {
	    printf("\n");
	}
D 2
	printf("\t");
	printf("0x%2x,", ebcasc[0][disp_ebc[i]]);
E 2
I 2
D 5
	printf("\t0x%2x,", ebcasc[0][disp_ebc[i]]);
E 5
I 5
D 6
	printf("\t0x%02x,", ebcasc[0][disp_ebc[i]]);
E 6
I 6
	printf("\t0x%02x,", ebc_asc[disp_ebc[i]]);
E 6
E 5
    }
    for (i = sizeof disp_ebc; i < 256; i++) {
	if ((i%8) == 0) {
	    printf("\n");
	}
D 5
	printf("\t0x%2x,", ' ');
E 5
I 5
	printf("\t0x%02x,", ' ');
E 5
E 2
    }
    printf("\n};\n");
I 4

    return 0;
E 4
}
E 1
