h38692
s 00010/00005/00029
d D 3.9 88/06/29 21:38:54 bostic 15 14
c install approved copyright notice
e
s 00013/00007/00021
d D 3.8 88/02/21 13:38:58 bostic 14 13
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00022
d D 3.7 85/04/24 16:18:45 edward 13 12
c copyright messages
e
s 00001/00001/00021
d D 3.6 84/11/20 23:40:29 edward 12 11
c we don't flush typeahead any more
e
s 00001/00001/00021
d D 3.5 84/05/23 01:59:40 edward 11 10
c new sccs id
e
s 00001/00001/00021
d D 3.4 84/04/16 20:28:59 edward 10 9
c 4.1a, 4.1c compatibility removed, local.h added
e
s 00005/00007/00017
d D 3.3 83/11/02 11:07:55 edward 9 8
c flags for different machines.
e
s 00002/00001/00022
d D 3.2 83/08/15 18:14:25 edward 8 7
c tt cleanup
e
s 00000/00000/00023
d D 3.1 83/08/11 17:22:00 edward 7 5
i 6
c last few day's work
e
s 00009/00008/00014
d D 2.1.1.1 83/08/09 18:35:16 edward 6 5
c mile stone
e
s 00000/00000/00022
d D 2.1 83/07/30 13:27:17 edward 5 4
c prepare for major change
e
s 00000/00000/00022
d D 1.4 83/07/22 17:09:43 edward 4 3
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00022
d D 1.3 83/07/19 20:07:58 edward 3 2
c today's work
e
s 00000/00000/00022
d D 1.2 83/07/18 21:03:57 edward 2 1
c multiple window
e
s 00022/00000/00000
d D 1.1 83/07/17 15:19:06 edward 1 0
c date and time created 83/07/17 15:19:06 by edward
e
u
U
f b 
t
T
I 1
D 14
#ifndef lint
D 11
static	char *sccsid = "%W% %E%";
E 11
I 11
static char sccsid[] = "%W% %G%";
E 11
#endif

E 14
I 13
/*
D 14
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 14
I 14
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
E 14
 */
I 14

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 14

E 13
#include "ww.h"
I 8
#include "tt.h"
E 8
D 10
#include <signal.h>
E 10
I 10
#include <sys/signal.h>
E 10

D 6
#define mask(s)	(1<<(SIG/**/s-1))
E 6
I 6
D 9
#define mask(s)	(1 << (s) - 1)
E 6

E 9
wwsuspend()
{
D 9
	int oldmask;
E 9
I 9
	int (*oldsig)();
E 9

D 6
	oldmask = sigblock(mask(TSTP));
E 6
I 6
D 9
	oldmask = sigblock(mask(SIGTSTP));
E 9
I 9
	oldsig = signal(SIGTSTP, SIG_IGN);
E 9
E 6
	wwend();
D 6
	sigsetmask(sigblock(0) & ~mask(TSTP));
	kill(0, SIGTSTP);
	sigblock(mask(TSTP));
	wwsettty(0, &wwnewtty);
	Winit(2, 1);
	sigsetmask(oldmask);
E 6
I 6
D 9
	(void) sigsetmask(sigblock(0) & ~mask(SIGTSTP));
E 9
I 9
	(void) signal(SIGTSTP, SIG_DFL);
E 9
	(void) kill(0, SIGTSTP);
D 9
	(void) sigblock(mask(SIGTSTP));
E 9
I 9
	(void) signal(SIGTSTP, SIG_IGN);
E 9
D 12
	(void) wwsettty(0, &wwnewtty);
E 12
I 12
	(void) wwsettty(0, &wwnewtty, &wwoldtty);
E 12
D 8
	(*tt.tt_reset)();
E 8
I 8
	(*tt.tt_init)();
E 8
	wwredraw();
D 9
	(void) sigsetmask(oldmask);
E 9
I 9
	(void) signal(SIGTSTP, oldsig);
E 9
E 6
}
E 1
