h35311
s 00010/00005/00025
d D 7.3 88/06/27 18:53:38 bostic 8 7
c install approved copyright notice
e
s 00008/00002/00022
d D 7.2 87/12/30 12:04:46 bostic 7 6
c add Berkeley header
e
s 00001/00001/00023
d D 7.1 86/06/04 23:21:59 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00017
d D 6.3 85/06/08 14:56:29 mckusick 5 4
c Add copyright
e
s 00003/00000/00015
d D 6.2 84/08/21 10:16:11 karels 4 3
c add RIGHTS type for mbufs, use m_act correctly for queuing datagrams
c (for sam)
e
s 00000/00000/00015
d D 6.1 83/07/29 06:12:11 sam 3 2
c 4.2 distribution
e
s 00005/00007/00010
d D 5.2 82/08/01 12:12:29 root 2 1
c protosw per domain
e
s 00017/00000/00000
d D 5.1 82/07/31 20:42:45 root 1 0
c date and time created 82/07/31 20:42:45 by root
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%I%	*/
E 2
I 2
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 5
E 2

/*
D 2
 * Structure for a communications domain.
 * Each communications domain supports a set or protocols,
 * which are contained in a protocol table located through
 * this structure.
E 2
I 2
 * Structure per communications domain.
E 2
 */
struct	domain {
I 2
	int	dom_family;		/* AF_xxx */
E 2
	char	*dom_name;
I 4
	int	(*dom_init)();		/* initialize domain data structures */
	int	(*dom_externalize)();	/* externalize access rights */
	int	(*dom_dispose)();	/* dispose of internalized rights */
E 4
D 2
	struct	protosw *dom_proto;
	int	dom_nproto;
E 2
I 2
	struct	protosw *dom_protosw, *dom_protoswNPROTOSW;
	struct	domain *dom_next;
E 2
};

#ifdef KERNEL
struct	domain *domains;
#endif
E 1
