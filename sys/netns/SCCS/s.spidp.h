h41462
s 00011/00006/00035
d D 7.3 88/06/29 17:13:38 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00031
d D 7.2 88/01/20 15:15:33 sklower 5 4
c Change licensing/use notice.
e
s 00001/00001/00034
d D 7.1 86/06/05 00:38:19 mckusick 4 3
c 4.3BSD release version
e
s 00001/00001/00034
d D 6.3 86/02/03 17:41:06 sklower 3 2
c Correct erroneous copyright information.
e
s 00007/00001/00028
d D 6.2 85/06/08 12:52:02 mckusick 2 1
c Add copyright
e
s 00029/00000/00000
d D 6.1 85/05/30 19:11:10 sklower 1 0
c date and time created 85/05/30 19:11:10 by sklower
e
u
U
t
T
I 1
D 2
/*      %M%     %I%     %E%     */
E 2
I 2
/*
D 3
 * Copyright (c) 1982 Regents of the University of California.
E 3
I 3
D 4
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 4
I 4
D 5
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 4
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 5
 *
D 5
 *	%W% (Berkeley) %G%
E 5
I 5
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
 *
D 6
 *      %W% (Berkeley) %G%
E 6
I 6
 *	%W% (Berkeley) %G%
E 6
E 5
 */
E 2

/*
 * Definitions for NS(tm) Internet Datagram Protocol
 * containing a Sequenced Packet Protocol packet.
 */
struct spidp {
	struct idp	si_i;
	struct sphdr 	si_s;
};
struct spidp_q {
	struct spidp_q	*si_next;
	struct spidp_q	*si_prev;
};
#define SI(x)	((struct spidp *)x)
#define si_sum	si_i.idp_sum
#define si_len	si_i.idp_len
#define si_tc	si_i.idp_tc
#define si_pt	si_i.idp_pt
#define si_dna	si_i.idp_dna
#define si_sna	si_i.idp_sna
#define si_sport	si_i.idp_sna.x_port
#define si_cc	si_s.sp_cc
#define si_dt	si_s.sp_dt
#define si_sid	si_s.sp_sid
#define si_did	si_s.sp_did
#define si_seq	si_s.sp_seq
#define si_ack	si_s.sp_ack
#define si_alo	si_s.sp_alo
E 1
