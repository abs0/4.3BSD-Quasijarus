h65146
s 00010/00005/00020
d D 7.3 88/06/27 18:54:53 bostic 9 8
c install approved copyright notice
e
s 00008/00002/00017
d D 7.2 87/12/30 12:04:51 bostic 8 7
c add Berkeley header
e
s 00001/00001/00018
d D 7.1 86/06/04 23:30:57 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00012
d D 6.3 85/06/08 15:11:41 mckusick 6 5
c Add copyright
e
s 00001/00001/00012
d D 6.2 84/05/07 13:12:59 karels 5 4
c avoid sizeof compiler padding
e
s 00000/00000/00013
d D 6.1 83/07/29 06:14:47 sam 4 3
c 4.2 distribution
e
s 00001/00001/00012
d D 5.3 83/06/13 23:03:29 sam 3 2
c show true limitation
e
s 00004/00000/00009
d D 5.2 83/05/27 13:59:07 sam 2 1
c wnj'ify for rights passing
e
s 00009/00000/00000
d D 5.1 82/08/02 00:05:25 root 1 0
c date and time created 82/08/02 00:05:25 by root
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 7
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
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
 *
 *	%W% (Berkeley) %G%
 */
E 6

/*
 * Definitions for UNIX IPC domain.
 */
struct	sockaddr_un {
	short	sun_family;		/* AF_UNIX */
D 3
	char	sun_path[14];		/* path name */
E 3
I 3
D 5
	char	sun_path[109];		/* path name (gag) */
E 5
I 5
	char	sun_path[108];		/* path name (gag) */
E 5
E 3
};
I 2

#ifdef KERNEL
int	unp_discard();
#endif
E 2
E 1
