h52267
s 00010/00005/00081
d D 7.3 88/06/29 17:06:30 bostic 15 14
c install approved copyright notice
e
s 00008/00002/00078
d D 7.2 87/12/07 17:45:07 bostic 14 13
c use Berkeley specific header
e
s 00001/00001/00079
d D 7.1 86/06/05 00:24:49 mckusick 13 12
c 4.3BSD release version
e
s 00010/00010/00070
d D 6.7 86/01/13 16:52:25 karels 12 11
c separate ARP header from IP-specific portion; break out IP
c portion of the input code; add trailer negotiation
e
s 00001/00001/00079
d D 6.6 85/09/16 22:42:18 karels 11 10
c compact entries
e
s 00007/00001/00073
d D 6.5 85/06/08 12:36:51 mckusick 10 9
c Add copyright
e
s 00017/00027/00057
d D 6.4 85/04/16 09:57:12 karels 9 8
c purge struct ether_addr (not portable);
c change ETHERPUP_*TYPE's to ETHERTYPE_*'s;
c add inaddr to arpcom struct, as not in ifnet any longer
e
s 00030/00010/00054
d D 6.3 84/03/20 15:25:34 karels 8 7
c new ARP; arptab in header file
e
s 00001/00001/00063
d D 6.2 83/09/26 08:38:05 karels 7 6
c PUP type is 0x0200 (RFC 820)
e
s 00000/00000/00064
d D 6.1 83/07/29 07:11:02 sam 6 5
c 4.2 distribution
e
s 00002/00003/00062
d D 4.5 83/05/15 17:15:37 sam 5 4
c from sun
e
s 00041/00000/00024
d D 4.4 83/03/15 18:17:35 sam 4 3
c ARP ARP
e
s 00003/00003/00021
d D 4.3 82/12/16 15:47:11 sam 3 2
c the numbers really were right (sigh)
e
s 00013/00010/00011
d D 4.2 82/12/16 15:40:23 sam 2 1
c fix byte swapping problems in header
e
s 00021/00000/00000
d D 4.1 82/12/16 14:38:25 sam 1 0
c date and time created 82/12/16 14:38:25 by sam
e
u
U
t
T
I 1
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
E 14
 *
 *	%W% (Berkeley) %G%
 */
E 10

/*
I 8
D 9
 * Ethernet address - 6 octets
 */
struct ether_addr {
	u_char	ether_addr_octet[6];
};

/*
E 9
E 8
 * Structure of a 10Mb/s Ethernet header.
 */
D 2
struct	eth_header {
	u_char	eth_dhost[6];
	u_char	eth_shost[6];
	u_short	eth_type;
E 2
I 2
struct	ether_header {
D 8
	u_char	ether_dhost[6];
	u_char	ether_shost[6];
E 8
I 8
D 9
	struct	ether_addr ether_dhost;
	struct	ether_addr ether_shost;
E 9
I 9
	u_char	ether_dhost[6];
	u_char	ether_shost[6];
E 9
E 8
	u_short	ether_type;
E 2
};

D 2
#define	ETHPUP_PUPTYPE	4		/* PUP protocol */
#define	ETHPUP_IPTYPE	8		/* IP protocol */
E 2
I 2
D 3
#define	ETHERPUP_PUPTYPE	4		/* PUP protocol */
#define	ETHERPUP_IPTYPE	8		/* IP protocol */
E 3
I 3
D 7
#define	ETHERPUP_PUPTYPE	0x0400		/* PUP protocol */
E 7
I 7
D 9
#define	ETHERPUP_PUPTYPE	0x0200		/* PUP protocol */
E 7
#define	ETHERPUP_IPTYPE		0x0800		/* IP protocol */
I 4
#define ETHERPUP_ARPTYPE	0x0806		/* Addr. resolution protocol */
E 9
I 9
#define	ETHERTYPE_PUP	0x0200		/* PUP protocol */
#define	ETHERTYPE_IP	0x0800		/* IP protocol */
#define ETHERTYPE_ARP	0x0806		/* Addr. resolution protocol */
E 9
E 4
E 3
E 2

/*
D 2
 * The ETHPUP_NTRAILER packet types starting at ETHPUP_TRAIL have
 * (type-ETHPUP_TRAIL)*512 bytes of data followed
E 2
I 2
D 9
 * The ETHERPUP_NTRAILER packet types starting at ETHERPUP_TRAIL have
E 9
I 9
 * The ETHERTYPE_NTRAILER packet types starting at ETHERTYPE_TRAIL have
E 9
D 12
 * (type-ETHERPUP_TRAIL)*512 bytes of data followed
E 2
 * by a PUP type (as given above) and then the (variable-length) header.
E 12
I 12
 * (type-ETHERTYPE_TRAIL)*512 bytes of data followed
 * by an ETHER type (as given above) and then the (variable-length) header.
E 12
 */
D 2
#define	ETHPUP_TRAIL	16		/* Trailer PUP */
#define	ETHPUP_NTRAILER	16
E 2
I 2
D 3
#define	ETHERPUP_TRAIL	16		/* Trailer PUP */
E 3
I 3
D 9
#define	ETHERPUP_TRAIL		0x1000		/* Trailer PUP */
E 3
#define	ETHERPUP_NTRAILER	16
E 9
I 9
#define	ETHERTYPE_TRAIL		0x1000		/* Trailer packet */
#define	ETHERTYPE_NTRAILER	16
E 9

#define	ETHERMTU	1500
#define	ETHERMIN	(60-14)
I 4

D 5
u_char etherbroadcastaddr[6];			/* 6 bytes of 0xFF */

E 5
/*
 * Ethernet Address Resolution Protocol.
 *
 * See RFC 826 for protocol description.  Structure below is adapted
 * to resolving internet addresses.  Field names used correspond to 
 * RFC 826.
 */
struct	ether_arp {
D 12
	u_short	arp_hrd;	/* format of hardware address */
#define ARPHRD_ETHER 	1	/* ethernet hardware address */
	u_short	arp_pro;	/* format of proto. address (ETHERPUP_IPTYPE) */
	u_char	arp_hln;	/* length of hardware address (6) */
	u_char	arp_pln;	/* length of protocol address (4) */
	u_short	arp_op;
#define	ARPOP_REQUEST	1	/* request to resolve address */
#define	ARPOP_REPLY	2	/* response to previous request */
E 12
I 12
	struct	arphdr ea_hdr;	/* fixed-size header */
E 12
D 8
	u_char	arp_sha[6];	/* sender hardware address */
	u_char	arp_spa[4];	/* sender protocol address */
	u_char	arp_tha[6];	/* target hardware address */
	u_char	arp_tpa[4];	/* target protocol address */
E 8
I 8
D 9
	u_char	arp_xsha[6];	/* sender hardware address */
	u_char	arp_xspa[4];	/* sender protocol address */
	u_char	arp_xtha[6];	/* target hardware address */
	u_char	arp_xtpa[4];	/* target protocol address */
E 9
I 9
	u_char	arp_sha[6];	/* sender hardware address */
	u_char	arp_spa[4];	/* sender protocol address */
	u_char	arp_tha[6];	/* target hardware address */
	u_char	arp_tpa[4];	/* target protocol address */
E 9
E 8
};
I 12
#define	arp_hrd	ea_hdr.ar_hrd
#define	arp_pro	ea_hdr.ar_pro
#define	arp_hln	ea_hdr.ar_hln
#define	arp_pln	ea_hdr.ar_pln
#define	arp_op	ea_hdr.ar_op
E 12
I 8
D 9
#define	arp_sha(ea)	(*(struct ether_addr *)(ea)->arp_xsha)
#define	arp_spa(ea)	(*(struct in_addr *)(ea)->arp_xspa)
#define	arp_tha(ea)	(*(struct ether_addr *)(ea)->arp_xtha)
#define	arp_tpa(ea)	(*(struct in_addr *)(ea)->arp_xtpa)
E 9
E 8

I 12

E 12
D 5
#ifdef	KERNEL
E 5
/*
 * Structure shared between the ethernet driver modules and
 * the address resolution code.  For example, each ec_softc or il_softc
 * begins with this structure.
 */
struct	arpcom {
D 9
	struct 	ifnet ac_if;	/* network-visible interface */
D 8
	u_char	ac_enaddr[6];	/* ethernet hardware address */
	struct	arpcom *ac_ac;	/* link to next ether driver */
E 8
I 8
	struct ether_addr ac_enaddr;	/* ethernet hardware address */
E 9
I 9
	struct 	ifnet ac_if;		/* network-visible interface */
	u_char	ac_enaddr[6];		/* ethernet hardware address */
	struct in_addr ac_ipaddr;	/* copy of ip address- XXX */
E 9
E 8
};

I 8
/*
 * Internet to ethernet address resolution table.
 */
struct	arptab {
	struct	in_addr at_iaddr;	/* internet address */
D 9
	struct	ether_addr at_enaddr;	/* ethernet address */
E 9
I 9
	u_char	at_enaddr[6];		/* ethernet address */
E 9
D 11
	struct	mbuf *at_hold;		/* last packet until resolved/timeout */
E 11
	u_char	at_timer;		/* minutes since last reference */
	u_char	at_flags;		/* flags */
I 11
	struct	mbuf *at_hold;		/* last packet until resolved/timeout */
E 11
};

E 8
I 5
#ifdef	KERNEL
D 8
u_char etherbroadcastaddr[6];			/* 6 bytes of 0xFF */
E 5
struct	in_addr arpmyaddr();
E 8
I 8
D 9
struct ether_addr etherbroadcastaddr;
E 9
I 9
u_char etherbroadcastaddr[6];
E 9
E 8
struct	arptab *arptnew();
I 12
char *ether_sprintf();
E 12
#endif
E 4
E 2
E 1
