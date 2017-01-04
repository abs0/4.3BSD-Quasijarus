h33870
s 00007/00001/00028
d D 6.2 85/06/08 13:59:38 mckusick 5 4
c Add copyright
e
s 00000/00000/00029
d D 6.1 83/07/29 07:38:45 sam 4 3
c 4.2 distribution
e
s 00002/00002/00027
d D 4.2 82/03/04 15:36:46 feldman 3 2
c fixed protocol type defs
e
s 00007/00000/00022
d D 4.1 82/03/04 00:51:25 feldman 2 1
c added message type definitions, upgrade to release level 4
e
s 00022/00000/00000
d D 1.1 82/02/05 23:37:20 root 1 0
c date and time created 82/02/05 23:37:20 by root
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
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Structure of a Ungermann-Bass datagram header.
 */

struct un_header {
	u_short	un_length;
	u_char	un_type;
	u_char	un_control;
	u_short	un_dnet;
	u_short	un_dniu;
	u_char	un_dport;
	u_char	un_dtype;
	u_short	un_snet;
	u_short	un_sniu;
	u_char	un_sport;
	u_char	un_stype;
	u_char	un_option;
	u_char	un_bcc;
	u_short	un_ptype;	/* protocol type */
};
I 2

/*
 * Protocol types
 */

D 3
#define	UNTYPE_INQUIRE		/* inquire - "Who am I?" */
#define	UNTYPE_IP		/* Internet Protocol */
E 3
I 3
#define	UNTYPE_INQUIRE		1	/* inquire - "Who am I?" */
#define	UNTYPE_IP		2	/* Internet Protocol */
E 3
E 2
E 1
