h01227
s 00010/00005/00040
d D 3.10 88/06/29 21:36:37 bostic 10 9
c install approved copyright notice
e
s 00013/00007/00032
d D 3.9 88/02/21 13:37:32 bostic 9 8
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00003/00033
d D 3.8 85/09/20 15:15:50 edward 8 7
c correct padding
e
s 00006/00000/00030
d D 3.7 85/04/24 16:18:40 edward 7 6
c copyright messages
e
s 00001/00001/00029
d D 3.6 84/05/23 01:59:38 edward 6 5
c new sccs id
e
s 00006/00007/00024
d D 3.5 84/01/11 16:28:44 edward 5 4
c gen_GS and gen_GE changed to gen_AS and gen_AE
e
s 00007/00005/00024
d D 3.4 83/12/17 15:38:55 edward 4 3
c WWM_GRP added
e
s 00001/00001/00028
d D 3.3 83/09/23 10:32:09 edward 3 2
c Marshall says it works finally.
e
s 00004/00001/00025
d D 3.2 83/09/17 17:30:44 edward 2 1
c didn't work
e
s 00026/00000/00000
d D 3.1 83/09/17 17:11:03 edward 1 0
c date and time created 83/09/17 17:11:03 by edward
e
u
U
t
T
I 1
D 9
#ifndef lint
D 6
static	char *sccsid = "%W% %I%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 9
I 7
/*
D 9
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 9
I 9
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */
I 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 9

E 7
#include "ww.h"
#include "tt.h"

/*
 * Freedom 100
 */

D 4
char f100_frame[16] = {
	' ',      'J'|0x80, 'K'|0x80, 'A'|0x80,
	'J'|0x80, 'J'|0x80, 'B'|0x80, 'M'|0x80,
	'K'|0x80, 'D'|0x80, 'K'|0x80, 'O'|0x80,
	'C'|0x80, 'L'|0x80, 'N'|0x80, 'I'|0x80
E 4
I 4
#define G (WWM_GRP << WWC_MSHIFT)
short f100_frame[16] = {
	' ',	'J'|G,	'K'|G,	'A'|G,
	'J'|G,	'J'|G,	'B'|G,	'M'|G,
	'K'|G,	'D'|G,	'K'|G,	'O'|G,
	'C'|G,	'L'|G,	'N'|G,	'I'|G
E 4
};
D 5
extern char *gen_GE, *gen_GS;
E 5
I 5
D 8
extern char *gen_AE, *gen_AS;
E 8
I 8
extern struct tt_str *gen_AE, *gen_AS;
E 8
E 5

tt_f100()
{
I 8
	static struct tt_str ae = { "\033%", 2 };
	static struct tt_str as = { "\033$", 2 };

E 8
I 2
D 5
	int ret;

	ret = tt_generic();
E 5
I 5
	if (tt_generic() < 0)
		return -1;
E 5
E 2
	tt.tt_frame = f100_frame;
I 4
	tt.tt_availmodes |= WWM_GRP;
E 4
D 5
	gen_GS = "\033$";
D 3
	gen_GE = "\033'";
E 3
I 3
	gen_GE = "\033%";
E 3
D 2
	return tt_generic();
E 2
I 2
	return ret;
E 5
I 5
D 8
	gen_AS = "\033$";
	gen_AE = "\033%";
E 8
I 8
	gen_AS = &as;
	gen_AE = &ae;
E 8
	return 0;
E 5
E 2
}
E 1
