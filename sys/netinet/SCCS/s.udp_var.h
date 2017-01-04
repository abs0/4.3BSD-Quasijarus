h53758
s 00010/00005/00040
d D 7.4 88/06/29 17:07:59 bostic 11 10
c install approved copyright notice
e
s 00008/00002/00037
d D 7.3 87/12/07 17:47:18 bostic 10 9
c use Berkeley specific header
e
s 00001/00001/00038
d D 7.2 87/06/04 22:03:45 karels 9 8
c add patchable udp ttl
e
s 00001/00001/00038
d D 7.1 86/06/05 00:34:05 mckusick 8 7
c 4.3BSD release version
e
s 00001/00001/00038
d D 6.4 86/04/05 09:14:23 karels 7 6
c longer TTL's
e
s 00002/00000/00037
d D 6.3 86/02/05 16:51:58 karels 6 5
c smaller TTL
e
s 00007/00001/00030
d D 6.2 85/06/08 12:46:57 mckusick 5 4
c Add copyright
e
s 00000/00000/00031
d D 6.1 83/07/29 07:13:34 sam 4 3
c 4.2 distribution
e
s 00010/00000/00021
d D 4.3 81/11/18 15:38:50 wnj 3 2
c more cleanup
e
s 00018/00000/00003
d D 4.2 81/11/15 13:01:09 wnj 2 1
c listing
e
s 00003/00000/00000
d D 4.1 81/11/14 16:52:29 wnj 1 0
c date and time created 81/11/14 16:52:29 by wnj
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 *
 *	%W% (Berkeley) %G%
 */
E 5

I 3
/*
 * UDP kernel structures and variables.
 */
E 3
I 2
struct	udpiphdr {
	struct 	ipovly ui_i;		/* overlaid ip structure */
	struct	udphdr ui_u;		/* udp header */
};
#define	ui_next		ui_i.ih_next
#define	ui_prev		ui_i.ih_prev
#define	ui_x1		ui_i.ih_x1
#define	ui_pr		ui_i.ih_pr
#define	ui_len		ui_i.ih_len
#define	ui_src		ui_i.ih_src
#define	ui_dst		ui_i.ih_dst
#define	ui_sport	ui_u.uh_sport
#define	ui_dport	ui_u.uh_dport
#define	ui_ulen		ui_u.uh_ulen
#define	ui_sum		ui_u.uh_sum

I 3
struct	udpstat {
	int	udps_hdrops;
	int	udps_badsum;
	int	udps_badlen;
};

I 6
D 7
#define	UDP_TTL		15		/* time to live for UDP packets */
E 7
I 7
D 9
#define	UDP_TTL		30		/* time to live for UDP packets */
E 9
I 9
#define	UDP_TTL		30		/* deflt time to live for UDP packets */
E 9
E 7

E 6
E 3
#ifdef KERNEL
E 2
struct	inpcb udb;
I 3
struct	udpstat udpstat;
E 3
I 2
#endif
E 2
E 1
