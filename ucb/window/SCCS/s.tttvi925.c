h59390
s 00010/00005/00037
d D 3.4 88/06/29 21:36:54 bostic 4 3
c install approved copyright notice
e
s 00013/00007/00029
d D 3.3 88/02/21 13:37:45 bostic 3 2
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00030
d D 3.2 85/04/24 16:24:30 edward 2 1
c copyright messages
e
s 00030/00000/00000
d D 3.1 85/03/01 18:04:09 edward 1 0
c date and time created 85/03/01 18:04:09 by edward
e
u
U
t
T
I 1
D 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif

E 3
I 2
/*
D 3
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 3
I 3
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */
I 3

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 3

E 2
#include "ww.h"
#include "tt.h"

/*
 * Televideo 925 as emulated by Microterm.
 *
 * From David Barto <sdcsvax!celerity!barto>.
 */

#define G (WWM_GRP << WWC_MSHIFT)
short tvi925_frame[16] = {
	' ',	'~'|G,	'|'|G,	'c'|G,
	'~'|G,	'~'|G,	'`'|G,	'e'|G,
	'|'|G,	'a'|G,	'|'|G,	'g'|G,
	'b'|G,	'f'|G,	'h'|G,	'd'|G
};

tt_tvi925()
{

	if (tt_generic() < 0)
		return -1;
	tt.tt_availmodes |= WWM_GRP;
	tt.tt_frame = tvi925_frame;
	return 0;
}
E 1
