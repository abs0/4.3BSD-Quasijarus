h09953
s 00010/00005/00044
d D 3.7 88/06/29 21:38:44 bostic 7 6
c install approved copyright notice
e
s 00013/00007/00036
d D 3.6 88/02/21 13:38:51 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00002/00007/00041
d D 3.5 87/06/08 02:28:11 edward 5 4
c interrupt mechanism reworked, make SIGCHLD interrupt also
e
s 00006/00000/00042
d D 3.4 85/04/24 16:19:05 edward 4 3
c copyright messages
e
s 00001/00001/00041
d D 3.3 84/05/23 01:59:48 edward 3 2
c new sccs id
e
s 00001/00001/00041
d D 3.2 84/04/16 20:29:10 edward 2 1
c 4.1a, 4.1c compatibility removed, local.h added
e
s 00042/00000/00000
d D 3.1 84/03/03 22:50:24 edward 1 0
c date and time created 84/03/03 22:50:24 by edward
e
u
U
t
T
I 1
D 6
#ifndef lint
D 3
static	char *sccsid = "%W% %E%";
E 3
I 3
static char sccsid[] = "%W% %G%";
E 3
#endif

E 6
I 4
/*
D 6
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 6
I 6
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */
I 6

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 6

E 4
#include "ww.h"
#include <fcntl.h>
#include <sys/signal.h>

/*
 * Tty input interrupt handler.
 * (1) Read input into buffer (wwib*).
D 5
 * (2) If the flag wwsetjmp is true, do longjmp(wwjmpbuf) for asyncronous
 *     actions, and to avoid race conditions, clear wwsetjmp.
E 5
I 5
 * (2) Set the interrupt flag if anything is read.
E 5
 * Currently, the last is used to get out of the blocking
 * select() in wwiomux().
 * To avoid race conditions, we only modify wwibq in here, except
 * when the buffer is empty; and everywhere else, we only change wwibp.
 * It should be completely safe.
 */
wwrint()
{
	register n;

	if (wwibp == wwibq)
		wwibp = wwibq = wwib;
	wwnread++;
	(void) fcntl(0, F_SETFL, FNDELAY|wwnewtty.ww_fflags);
	n = read(0, wwibq, wwibe - wwibq);
	(void) fcntl(0, F_SETFL, wwnewtty.ww_fflags);
	if (n > 0) {
		wwibq += n;
		wwnreadc += n;
I 5
		wwsetintr();
E 5
	} else if (n == 0)
		wwnreadz++;
	else
		wwnreade++;
D 5
	if (wwinterrupt() && wwsetjmp) {
		wwsetjmp = 0;
D 2
		(void) sigrelse(SIGIO);
E 2
I 2
		(void) sigsetmask(sigblock(0) & ~sigmask(SIGIO));
E 2
		longjmp(wwjmpbuf, 1);
	}
E 5
}
E 1
