h26838
s 00010/00005/00063
d D 3.21 88/06/29 21:36:30 bostic 26 25
c install approved copyright notice
e
s 00013/00007/00055
d D 3.20 88/02/21 13:37:25 bostic 25 24
c written by Edward Wang; attach Berkeley specific copyright
e
s 00003/00002/00059
d D 3.19 87/10/22 19:38:23 bostic 24 23
c ANSI C; sprintf now returns an int.
e
s 00002/00000/00059
d D 3.18 86/08/04 14:16:26 edward 23 22
c WWM_USR and WWM_DIM added, termcap strings XS and XE added,
c display mode escape sequences changed
e
s 00006/00000/00053
d D 3.17 85/04/24 16:14:36 edward 22 21
c copyright messages
e
s 00002/00002/00051
d D 3.16 85/03/11 16:29:04 edward 21 20
c default windows: the top one is 1 and bottom is 2
e
s 00003/00004/00050
d D 3.15 85/02/08 11:40:32 edward 20 19
c reverse the order of openwin() in dodefault().  faster this way.
e
s 00001/00001/00053
d D 3.14 84/05/23 01:57:53 edward 19 18
c new sccs id
e
s 00004/00007/00050
d D 3.13 84/05/16 03:53:39 edward 18 17
c stupid mistake in doconfig(), and duplicate error message in dodefault()
e
s 00002/00001/00055
d D 3.12 84/04/16 20:28:53 edward 17 16
c 4.1a, 4.1c compatibility removed, local.h added
e
s 00010/00007/00046
d D 3.11 84/04/09 23:28:21 edward 16 15
c forgot openwin()'s new arguments, also sneakiness with sprintf().
e
s 00003/00002/00050
d D 3.10 84/04/08 12:08:29 edward 15 14
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00002/00002/00050
d D 3.9 84/03/03 22:45:41 edward 14 13
c interrupt driven input
e
s 00003/00002/00049
d D 3.8 84/01/11 16:29:27 edward 13 12
c make graphics mode available to user
e
s 00015/00000/00036
d D 3.7 83/12/06 12:50:45 edward 12 11
c predefined variables
e
s 00005/00004/00031
d D 3.6 83/11/22 19:52:45 edward 11 10
c openwin has new 'label' argument
e
s 00001/00001/00034
d D 3.5 83/08/26 16:26:15 edward 10 9
c error reporting
e
s 00002/00002/00033
d D 3.4 83/08/25 17:57:09 edward 9 8
c added user setable buffer size.
e
s 00001/00001/00034
d D 3.3 83/08/18 12:10:29 edward 8 7
c lint
e
s 00004/00003/00031
d D 3.2 83/08/17 12:52:05 edward 7 6
c fixed default window sizes and say what the escape character is.
e
s 00000/00000/00034
d D 3.1 83/08/11 17:22:59 edward 6 4
i 5
c last few day's work
e
s 00004/00007/00030
d D 2.1.1.1 83/08/09 18:36:09 edward 5 4
c mile stone
e
s 00000/00000/00037
d D 2.1 83/07/30 13:26:31 edward 4 3
c prepare for major change
e
s 00001/00001/00036
d D 1.3 83/07/29 17:13:11 edward 3 2
c .windowrc instead of cf
e
s 00003/00003/00034
d D 1.2 83/07/22 17:11:21 edward 2 1
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00037/00000/00000
d D 1.1 83/07/20 19:32:22 edward 1 0
c date and time created 83/07/20 19:32:22 by edward
e
u
U
f b 
t
T
I 1
D 25
#ifndef lint
D 19
static	char *sccsid = "%W% %E%";
E 19
I 19
static char sccsid[] = "%W% %G%";
E 19
#endif

E 25
I 22
/*
D 25
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 25
I 25
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 26
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 26
I 26
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
E 26
E 25
 */
I 25

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 25

E 22
#include "defs.h"
I 12
#include "value.h"
#include "var.h"
I 15
#include "char.h"
I 17
#include "local.h"
E 17
E 15
E 12

D 5
struct ww *doopen();
char *getenv();

E 5
doconfig()
{
	char buf[100];
	char *home;
I 16
D 17
	static char runcom[] = ".windrc";
E 17
I 17
	static char runcom[] = RUNCOM;
E 17
E 16

	if ((home = getenv("HOME")) == 0)
D 16
		home = "";
D 3
	sprintf(buf, "%s/.windowcf", home);
E 3
I 3
D 5
	sprintf(buf, "%s/.windowrc", home);
E 5
I 5
D 11
	(void) sprintf(buf, "%s/.windowrc", home);
E 11
I 11
	(void) sprintf(buf, "%s/.windrc", home);
E 11
E 5
E 3
	return dosource(buf);
E 16
I 16
		home = ".";
D 18
	return dosource(sprintf(buf, "%.*s/.windrc",
E 18
I 18
D 24
	return dosource(sprintf(buf, "%.*s/%s",
E 24
I 24
	sprintf(buf, "%.*s/%s",
E 24
E 18
		(sizeof buf - sizeof runcom) / sizeof (char) - 1,
D 24
		home, runcom));
E 24
I 24
		home, runcom);
	return dosource(buf);
E 24
E 16
}

/*
D 18
 * The default is two windows of equal sizes.
E 18
I 18
 * The default is two windows of equal size.
E 18
 */
dodefault()
{
	struct ww *w;
D 2
	register r = WRows / 2;
E 2
I 2
D 7
	register r = wwnrow / 2;
E 7
I 7
	register r = wwnrow / 2 - 1;
E 7
E 2

D 2
	if ((w = doopen(-1, r + 1, WCols, 0, 0)) == 0)
E 2
I 2
D 5
	if ((w = doopen(-1, r + 1, wwncol, 0, 0)) == 0)
E 5
I 5
D 7
	if ((w = openwin(-1, r + 1, wwncol, 0, 0)) == 0)
E 7
I 7
D 9
	if ((w = openwin(-1, r, wwncol, 1, 0)) == 0)
E 9
I 9
D 11
	if ((w = openwin(-1, 1, 0, r, wwncol, nbufline)) == 0)
E 11
I 11
D 16
	if ((w = openwin(-1, 1, 0, r, wwncol, nbufline, (char *) 0)) == 0)
E 16
I 16
D 20
	if ((w = openwin(-1, 1, 0, r, wwncol, nbufline,
				(char *) 0, 1, 1, shellfile, shell)) == 0)
E 16
E 11
E 9
E 7
E 5
E 2
D 18
		goto bad;
E 18
I 18
		return;
E 20
E 18
D 2
	if (doopen(-1, WRows - r, WCols, r, 0) == 0)
E 2
I 2
D 5
	if (doopen(-1, wwnrow - r, wwncol, r, 0) == 0)
E 5
I 5
D 7
	if (openwin(-1, wwnrow - r, wwncol, r, 0) == 0)
E 7
I 7
D 9
	if (openwin(-1, wwnrow - r - 2, wwncol, r + 2, 0) == 0)
E 9
I 9
D 11
	if (openwin(-1, r + 2, 0, wwnrow - r - 2, wwncol, nbufline) == 0)
E 11
I 11
D 16
	if (openwin(-1, r + 2, 0, wwnrow - r - 2, wwncol, nbufline, (char *) 0)
	    == 0)
E 16
I 16
D 21
	if (openwin(-1, r + 2, 0, wwnrow - r - 2, wwncol, nbufline,
E 21
I 21
	if (openwin(1, r + 2, 0, wwnrow - r - 2, wwncol, nbufline,
E 21
				(char *) 0, 1, 1, shellfile, shell) == 0)
E 16
E 11
E 9
E 7
E 5
E 2
D 18
		goto bad;
E 18
I 18
		return;
I 20
D 21
	if ((w = openwin(-1, 1, 0, r, wwncol, nbufline,
E 21
I 21
	if ((w = openwin(0, 1, 0, r, wwncol, nbufline,
E 21
				(char *) 0, 1, 1, shellfile, shell)) == 0)
		return;
E 20
E 18
I 7
D 8
	wwprintf(w, "Escape character is %s.\r\n", unctrl(escapec));
E 8
I 8
D 14
	(void) wwprintf(w, "Escape character is %s.\r\n", unctrl(escapec));
E 14
I 14
	wwprintf(w, "Escape character is %s.\r\n", unctrl(escapec));
E 14
E 8
E 7
D 20
	setselwin(w);
E 20
D 18
	return;
bad:
D 5
	wwputs("Can't open default windows.  ", cmdwin);
E 5
I 5
D 10
	(void) wwputs("Can't open default windows.  ", cmdwin);
E 10
I 10
D 11
	(void) wwputs("\nCan't open default windows.  ", cmdwin);
E 11
I 11
D 14
	(void) wwputs("Can't open default windows.  ", cmdwin);
E 14
I 14
D 16
	wwputs("Can't open default windows.  ", cmdwin);
E 16
I 16
	error("Can't open default windows.");
E 18
E 16
E 14
I 12
}

setvars()
{
D 13
	/* use a good ordering to balance the tree */
	(void) var_setnum("ncol", wwncol);
E 13
I 13
D 15
	/* try to use a good ordering to balance the tree */
E 15
I 15
	/* try to use a random ordering to balance the tree */
E 15
E 13
	(void) var_setnum("nrow", wwnrow);
I 13
	(void) var_setnum("ncol", wwncol);
E 13
D 15
	(void) var_setnum("availmodes", wwavailmodes);
E 15
	(void) var_setnum("baud", wwbaud);
	(void) var_setnum("m_rev", WWM_REV);
	(void) var_setnum("m_blk", WWM_BLK);
	(void) var_setnum("m_ul", WWM_UL);
I 13
	(void) var_setnum("m_grp", WWM_GRP);
I 23
	(void) var_setnum("m_dim", WWM_DIM);
	(void) var_setnum("m_usr", WWM_USR);
E 23
E 13
	(void) var_setstr("term", wwterm);
I 15
	(void) var_setnum("modes", wwavailmodes);
E 15
E 12
E 11
E 10
E 5
}
E 1
