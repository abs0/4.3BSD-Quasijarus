/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
 *
 *	@(#)if_hdlc.h	7.1 (Berkeley) 3/13/00
 */

/*
 * Structure of an HDLC header.
 */
struct	hdlc_header {
	u_char	hdlc_address;
	u_char	hdlc_control;
	u_short	hdlc_type;
};

/*
 * Fudge! Fudge! Fudge! No one in the world knows what did Cisco mean by
 * "unicast intent" and "multicast intent" on point-to-point links and what is
 * the difference between them. All drivers I've seen always send only one of
 * them (unicast in some and multicast in others) and accept both identically.
 */
#define	CISCOHDLC_ADDR_UNICAST		0x0F
#define	CISCOHDLC_ADDR_MULTICAST	0x8F

#define	CISCOHDLC_CONTROL	0x00
