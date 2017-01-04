h17452
s 00010/00005/00033
d D 7.3 88/06/29 17:07:16 bostic 7 6
c install approved copyright notice
e
s 00008/00002/00030
d D 7.2 87/12/07 17:46:06 bostic 6 5
c use Berkeley specific header
e
s 00001/00001/00031
d D 7.1 86/06/05 00:29:47 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00025
d D 6.2 85/06/08 12:42:00 mckusick 4 3
c Add copyright
e
s 00000/00000/00026
d D 6.1 83/07/29 07:12:10 sam 3 2
c 4.2 distribution
e
s 00004/00001/00022
d D 4.2 82/03/24 21:56:05 root 2 1
c fix keep alives and timeouts: checksum problem and doing keeps
c on all connections by mistake (still needs more work to do keeps more 
c persistantly!)
e
s 00023/00000/00000
d D 4.1 81/12/22 23:37:18 root 1 0
c date and time created 81/12/22 23:37:18 by root
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 5
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
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
 *
 *	%W% (Berkeley) %G%
 */
E 4

struct	tcp_debug {
	n_time	td_time;
	short	td_act;
	short	td_ostate;
	caddr_t	td_tcb;
	struct	tcpiphdr td_ti;
	short	td_req;
	struct	tcpcb td_cb;
};

#define	TA_INPUT 	0
#define	TA_OUTPUT	1
#define	TA_USER		2
I 2
#define	TA_RESPOND	3
#define	TA_DROP		4
E 2

#ifdef TANAMES
D 2
char	*tanames[] = { "input", "output", "user" };
E 2
I 2
char	*tanames[] =
    { "input", "output", "user", "respond", "drop" };
E 2
#endif

#define	TCP_NDEBUG 100
struct	tcp_debug tcp_debug[TCP_NDEBUG];
int	tcp_debx;
E 1
