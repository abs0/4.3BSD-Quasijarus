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
 *	@(#)if_pppvar.h	7.4 (Berkeley) 4/5/08
 */

/*
 * ppp netif module data structures and state machines.
 */

#define	PPP_NAUTH	8		/* # of auth protocols we support */
#define	PPP_AUTH_MAXP	6		/* max # of param bytes in LCP option */
struct ppp_authproto {
	short	authproto_nparambytes;
	u_short	authproto_proto;
	u_char	authproto_parambytes[PPP_AUTH_MAXP];
};

/* struct ppp_softc basically *is* the ppp interface */
struct ppp_softc {
	struct ifnet	pp_if;		/* network-visible interface */
	struct ppp_hw	*pp_hw;		/* phys if attached to the ppp module */
	u_long		pp_hwhnd;	/* opaque handle for the above */
	short		pp_state;	/* RFC 1661 ppp if state */
	short		pp_restcnt;	/* RFC 1661 restart-count */
	short		pp_desmtu;	/* desired MTU */
	short		pp_desmru;	/* desired MRU */
	short		pp_agreedmtu;	/* agreed MTU (remote MRU) */
	short		pp_agreedmru;	/* agreed local MRU */
	u_long		pp_laccm;	/* local ACCM */
	u_long		pp_raccm;	/* remote ACCM */
	short		pp_lcpnegot;	/* LCP neg state for ConfReqs we send */
	short		pp_peerconf;	/* what the peer said it'll accept */
	short		pp_flags;	/* additional flags */
	short		pp_restimer;	/* configurable per RFC 1661 sec 4.6 */
	short		pp_maxconf;	/* ditto */
	short		pp_maxterm;	/* ditto */
	u_char		pp_lastreqid;	/* ID of last ConfReq packet sent */
	short		pp_busy;	/* in addition to splnet */
	short		pp_pending_updn;/* deferred pppup() or pppdown() */
	char		*pp_asbuf;	/* pppasync receive buffer */
	char		*pp_asptr;	/* pppasync receive ptr */
	short		pp_ascnt;	/* pppasync receive count */
	u_short		pp_asfcs;	/* pppasync receive FCS */
	short		pp_asstate;	/* pppasync receive state */
	u_short		pp_asproto;	/* pppasync receive protocol */
	/* authentication stuff: us to the peer */
	struct ppp_authproto	pp_authself_protos[PPP_NAUTH];
	short			pp_authself_nprotos;	/* total # of protos */
	short			pp_authself_index;	/* selected proto */
	/* us authenticating the peer */
	struct ppp_authproto	pp_authpeer_protos[PPP_NAUTH];
	short			pp_authpeer_nprotos;	/* total # of protos */
	short			pp_authpeer_index;	/* selected proto */
};

/* PPP interface states (from RFC 1661) */
#define	PPP_STATE_INITIAL	0
#define	PPP_STATE_STARTING	1
#define	PPP_STATE_CLOSED	2
#define	PPP_STATE_STOPPED	3
#define	PPP_STATE_CLOSING	4
#define	PPP_STATE_STOPPING	5
#define	PPP_STATE_REQSENT	6
#define	PPP_STATE_ACKRCVD	7
#define	PPP_STATE_ACKSENT	8
#define	PPP_STATE_OPENED	9

/* pp_lcpnegot bits */
#define	LCPNEGOT_ASKACCM	0x0001
#define	LCPNEGOT_ASKACCOMP	0x0002
#define	LCPNEGOT_ASKPROTCOMP	0x0004
#define	LCPNEGOT_ASKMRU		0x0008
#define	LCPNEGOT_DRAW		0x8000

/* pp_peerconf bits */
#define	PEERCONF_OKACCOMP	0x0001
#define	PEERCONF_OKPROTCOMP	0x0002
#define	PEERCONF_NEEDAUTH	0x0004

/* pp_flags bits */
#define	PPP_FLAGS_UP		0x0001	/* truly up, not user thinking so */
#define	PPP_FLAGS_PERSIST	0x0002
#define	PPP_FLAGS_PASSIVE	0x0004

/* pppasync receive states */
#define	PPPASYNC_RXSTATE_ADDR		0x0000
#define	PPPASYNC_RXSTATE_CTRL		0x0001
#define	PPPASYNC_RXSTATE_PROTOHI	0x0002
#define	PPPASYNC_RXSTATE_PROTOLO	0x0003
#define	PPPASYNC_RXSTATE_DATA		0x0004
#define	PPPASYNC_RXSTATE_DROP		0x0005
#define	PPPASYNC_RXSTATE_ESCAPE		0x8000

/* struct ppp_hw describes the backend if attached to the ppp module */
struct ppp_hw {
	short		phw_mtu;	/* physical MTU */
	short		phw_mru;	/* physical MRU */
	short		phw_caps;	/* phy implementation capabilities */
	int		(*phw_output)();	/* xmit packet */
	int		(*phw_up)();	/* bring phys layer up */
	int		(*phw_down)();	/* bring phys layer down */
	int		(*phw_check)();	/* is the phys layer up? */
};

/* Phy implementation capabilities */
#define	PPP_PHYCAPS_OKSENDACCM		0x0001
#define	PPP_PHYCAPS_OKRECVACCM		0x0002
#define	PPP_PHYCAPS_OKSENDACCOMP	0x0004
#define	PPP_PHYCAPS_WANTSENDACCOMP	0x0008
#define	PPP_PHYCAPS_OKRECVACCOMP	0x0010
#define	PPP_PHYCAPS_WANTRECVACCOMP	0x0020
#define	PPP_PHYCAPS_OKSENDPROTCOMP	0x0040
#define	PPP_PHYCAPS_WANTSENDPROTCOMP	0x0080
#define	PPP_PHYCAPS_OKRECVPROTCOMP	0x0100
#define	PPP_PHYCAPS_WANTRECVPROTCOMP	0x0200

#ifdef KERNEL
extern struct ppp_softc ppp_softc[];
extern struct ifqueue ppplcpinq, pppunkq;
#endif
