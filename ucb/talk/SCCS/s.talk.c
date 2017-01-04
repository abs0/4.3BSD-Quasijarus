h60530
s 00010/00005/00048
d D 5.4 88/06/29 20:22:29 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00043
d D 5.3 88/05/20 12:37:11 bostic 5 4
c add Berkeley specific header
e
s 00001/00002/00046
d D 5.2 88/05/20 12:11:00 edward 4 3
c use getpwuid in addition to getlogin to get user name, and some cleanup
e
s 00013/00001/00035
d D 5.1 85/06/06 09:20:07 dist 3 2
c Add copyright
e
s 00008/00013/00028
d D 1.2 84/04/11 15:15:05 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00041/00000/00000
d D 1.1 84/04/11 15:03:13 karels 1 0
c date and time created 84/04/11 15:03:13 by karels
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

E 3
I 1
D 2
/* $Header: talk.c 1.3 83/04/23 02:08:25 moore Exp $ */
E 2
I 2
#ifndef lint
I 3
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#ifndef lint
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 3
E 2

#include "talk.h"

/*
 * talk:	A visual form of write. Using sockets, a two way 
 *		connection is set up between the two people talking. 
 *		With the aid of curses, the screen is split into two 
 *		windows, and each users text is added to the window,
 *		one character at a time...
 *
 *		Written by Kipp Hickman
 *		
 *		Modified to run under 4.1a by Clem Cole and Peter Moore
 *		Modified to run between hosts by Peter Moore, 8/19/82
 *		Modified to run under 4.1c by Peter Moore 3/17/83
 */

main(argc, argv)
D 2
int argc;
char *argv[];
E 2
I 2
	int argc;
	char *argv[];
E 2
{
D 2
	get_names(argc, argv);
E 2
D 4

E 4
I 2
	get_names(argc, argv);
E 2
	init_display();
D 2

E 2
	open_ctl();
	open_sockt();
D 2

E 2
	start_msgs();
D 2

	if ( !check_local() ) {
	    invite_remote();
	}

E 2
I 2
D 4
	if (!check_local() )
E 4
I 4
	if (!check_local())
E 4
		invite_remote();
E 2
	end_msgs();
D 2

E 2
	set_edit_chars();
D 2

E 2
	talk();
}
E 1
