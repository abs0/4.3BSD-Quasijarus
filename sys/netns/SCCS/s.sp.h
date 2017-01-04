h29959
s 00011/00006/00025
d D 7.3 88/06/29 17:13:37 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00021
d D 7.2 88/01/20 15:15:31 sklower 5 4
c Change licensing/use notice.
e
s 00001/00001/00024
d D 7.1 86/06/05 00:38:11 mckusick 4 3
c 4.3BSD release version
e
s 00001/00001/00024
d D 6.3 86/02/03 17:40:27 sklower 3 2
c Correct erroneous copyright information.
e
s 00007/00001/00018
d D 6.2 85/06/08 12:51:54 mckusick 2 1
c Add copyright
e
s 00019/00000/00000
d D 6.1 85/05/30 19:11:08 sklower 1 0
c date and time created 85/05/30 19:11:08 by sklower
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
 * Copyright (c) 1984 Regents of the University of California.
E 4
I 4
D 5
 * Copyright (c) 1984, 1986 Regents of the University of California.
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
 * Definitions for Xerox NS style sequenced packet protocol
 */

struct sphdr {
	u_char	sp_cc;		/* connection control */
	u_char	sp_dt;		/* datastream type */
#define	SP_SP	0x80		/* system packet */
#define	SP_SA	0x40		/* send acknowledgement */
#define	SP_OB	0x20		/* attention (out of band data) */
#define	SP_EM	0x10		/* end of message */
	u_short	sp_sid;		/* source connection identifier */
	u_short	sp_did;		/* destination connection identifier */
	u_short	sp_seq;		/* sequence number */
	u_short	sp_ack;		/* acknowledge number */
	u_short	sp_alo;		/* allocation number */
};
E 1
