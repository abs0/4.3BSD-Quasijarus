h43183
s 00005/00001/00063
d D 7.2 02/07/19 22:01:05 msokolov 2 1
c add RFC 1662 definitions for octet-oriented framing
e
s 00064/00000/00000
d D 7.1 02/07/11 10:56:32 msokolov 1 0
c ppp module base written, compiles
e
u
U
t
T
I 1
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
 *	%W% (Berkeley) %G%
 */

/*
D 2
 * Point-to-Point Protocol (PPP) definitions per RFC 1661.
E 2
I 2
 * Point-to-Point Protocol (PPP) definitions per RFCs 1661 and 1662.
E 2
 */

/* HDLC framing */
#define	PPP_FRAME_ADDR		0xFF
#define	PPP_FRAME_CONTROL	0x03
I 2

/* Octet-oriented framing */
#define	PPP_OCTFRM_FLAG		0x7E
#define	PPP_OCTFRM_ESCAPE	0x7D
E 2

#define	PPP_DEFAULT_MTU		1500

/* PPP link/network layer protocols */
#define	PPPPROTO_IP		0x0021
#define	PPPPROTO_IPCP		0x8021
#define	PPPPROTO_LCP		0xC021
#define	PPPPROTO_PAP		0xC023
#define	PPPPROTO_CHAP		0xC223

/* LCP header */
struct ppplcp_header {
	u_char	lcp_code;
	u_char	lcp_id;
	u_short	lcp_len;
};

/* LCP packet codes */
#define	PPPLCP_CONFREQ		0x01
#define	PPPLCP_CONFACK		0x02
#define	PPPLCP_CONFNAK		0x03
#define	PPPLCP_CONFREJ		0x04
#define	PPPLCP_TERMREQ		0x05
#define	PPPLCP_TERMACK		0x06
#define	PPPLCP_CODEREJ		0x07
#define	PPPLCP_PROTREJ		0x08
#define	PPPLCP_ECHOREQ		0x09
#define	PPPLCP_ECHORPLY		0x0A
#define	PPPLCP_DISCARDREQ	0x0B

/* LCP options */
#define	LCPOPT_MRU		0x01
#define	LCPOPT_ACCM		0x02
#define	LCPOPT_AUTHTYPE		0x03
#define	LCPOPT_MAGICNUM		0x05
#define	LCPOPT_LQM		0x06
#define	LCPOPT_PROTCOMP		0x07
#define	LCPOPT_ACCOMP		0x08
E 1
