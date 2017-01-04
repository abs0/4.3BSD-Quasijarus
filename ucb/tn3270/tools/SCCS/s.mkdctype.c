h13864
s 00015/00018/00063
d D 3.2 88/03/28 12:08:19 bostic 7 6
c add Berkeley specific headers
e
s 00000/00000/00081
d D 3.1 87/08/11 10:20:40 minshall 6 5
c New version numbering.
e
s 00025/00000/00056
d D 1.5 87/07/17 10:06:01 minshall 5 4
c Install sccs headers and copyright notices.
e
s 00001/00001/00055
d D 1.4 87/07/15 15:27:12 minshall 4 3
c New directory structure.
e
s 00001/00001/00055
d D 1.3 87/06/19 12:52:45 minshall 3 2
c Directory changes.
e
s 00001/00001/00055
d D 1.2 87/05/12 14:10:39 minshall 2 1
c Various fixes for running under dos.
e
s 00056/00000/00000
d D 1.1 86/11/12 16:44:15 minshall 1 0
c date and time created 86/11/12 16:44:15 by minshall
e
u
U
t
T
I 5
/*
D 7
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 7
I 7
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 7
 *
D 7
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
E 7
I 7
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
 */

#ifndef lint
I 7
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 7
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif	/* not lint */
E 7
I 7
#endif /* not lint */
E 7

E 5
I 1
D 3
#include "../ctlr/ebc_disp.h"
E 3
I 3
D 4
#include "../apilib/ebc_disp.h"
E 4
I 4
#include "../api/ebc_disp.h"
E 4
E 3
#include "ectype.h"


extern unsigned char ectype[256];


void
main()
{
D 2
    static unsigned char dctype[192] = 0;
E 2
I 2
    static unsigned char dctype[192] = { 0 };
E 2
    int i;
    char *orbar;
    int type;

    for (i = 0; i < sizeof ectype; i++) {
	dctype[ebc_disp[i]] = ectype[i];
    }

    for (i = 0; i < sizeof dctype; i++) {
	if ((i%16) == 0) {
	    printf("/*%02x*/\n", i);
	}
	printf("\t");
	type = dctype[i];
	orbar = "";
	if (type & E_UPPER) {
	    printf("E_UPPER");
	    orbar = "|";
	}
	if (type & E_LOWER) {
	    printf("%sD_LOWER", orbar);
	    orbar = "|";
	}
	if (type & E_DIGIT) {
	    printf("%sD_DIGIT", orbar);
	    orbar = "|";
	}
	if (type & E_SPACE) {
	    printf("%sD_SPACE", orbar);
	    orbar = "|";
	}
	if (type & E_PUNCT) {
	    printf("%sD_PUNCT", orbar);
	    orbar = "|";
	}
	if (type & E_PRINT) {
	    printf("%sD_PRINT", orbar);
	    orbar = "|";
	}
	if (orbar[0] == 0) {
	    printf("0");
	}
	printf(",\n");
    }
}
E 1
