h52791
s 00010/00006/00049
d D 5.3 88/06/18 19:38:35 bostic 3 2
c install approved copyright notice
e
s 00010/00003/00045
d D 5.2 87/12/29 17:17:23 bostic 2 1
c Berkeley header
e
s 00048/00000/00000
d D 5.1 86/11/26 13:36:40 bostic 1 0
c date and time created 86/11/26 13:36:40 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 3
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif not lint
E 2
I 2
#endif /* not lint */
D 3

E 3
E 2

# include	"mille.h"

/*
 * @(#)types.c	1.1 (Berkeley) 4/1/82
 */

isrepair(card)
reg CARD	card; {

	return card == C_GAS || card == C_SPARE || card == C_REPAIRS || card == C_INIT;
}

safety(card)
reg CARD	card; {

	switch (card) {
	  case C_EMPTY:
	  case C_GAS:
	  case C_GAS_SAFE:
		return C_GAS_SAFE;
	  case C_FLAT:
	  case C_SPARE:
	  case C_SPARE_SAFE:
		return C_SPARE_SAFE;
	  case C_CRASH:
	  case C_REPAIRS:
	  case C_DRIVE_SAFE:
		return C_DRIVE_SAFE;
	  case C_GO:
	  case C_STOP:
	  case C_RIGHT_WAY:
	  case C_LIMIT:
	  case C_END_LIMIT:
		return C_RIGHT_WAY;
	}
	/* NOTREACHED */
}

E 1
