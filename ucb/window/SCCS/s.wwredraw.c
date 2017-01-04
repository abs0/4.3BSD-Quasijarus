h13513
s 00010/00005/00027
d D 3.9 88/06/29 21:38:41 bostic 9 8
c install approved copyright notice
e
s 00013/00007/00019
d D 3.8 88/02/21 13:38:49 bostic 8 7
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00020
d D 3.7 85/04/24 16:15:19 edward 7 6
c copyright messages
e
s 00001/00001/00019
d D 3.6 84/05/23 01:58:10 edward 6 5
c new sccs id
e
s 00001/00001/00019
d D 3.5 83/12/02 22:45:26 edward 5 4
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00001/00000/00019
d D 3.4 83/08/16 12:54:55 edward 4 3
c wwtouched added
e
s 00001/00000/00018
d D 3.3 83/08/15 18:14:40 edward 3 2
c tt cleanup
e
s 00000/00000/00018
d D 3.2 83/08/11 17:23:12 edward 2 1
i
c last few day's work
e
s 00018/00000/00000
d D 3.1 83/08/09 18:36:21 edward 1 0
c date and time created 83/08/09 18:36:21 by edward
e
u
U
t
T
I 1
D 8
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 8
I 7
/*
D 8
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */
I 8

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8

E 7
#include "ww.h"
I 3
#include "tt.h"
E 3

wwredraw()
{
	register i, j;
	register union ww_char *os;

	(*tt.tt_clear)();
	for (i = 0; i < wwnrow; i++) {
I 4
D 5
		wwtouched[i] = 1;
E 5
I 5
		wwtouched[i] = WWU_TOUCHED;
E 5
E 4
		os = wwos[i];
		for (j = wwncol; --j >= 0;)
			(os++)->c_w = ' ';
	}
}
E 1
