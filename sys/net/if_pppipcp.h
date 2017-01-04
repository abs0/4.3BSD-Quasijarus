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
 *	@(#)if_pppipcp.h	7.1 (Berkeley) 7/23/02
 */

/*
 * PPP IP Control Protocol (IPCP), RFC 1332
 */

/* IPCP header */
struct pppipcp_header {
	u_char	ipcph_code;
	u_char	ipcph_id;
	u_short	ipcph_len;
};

/* IPCP packet codes */
#define	PPPIPCP_CONFREQ		0x01
#define	PPPIPCP_CONFACK		0x02
#define	PPPIPCP_CONFNAK		0x03
#define	PPPIPCP_CONFREJ		0x04
#define	PPPIPCP_TERMREQ		0x05
#define	PPPIPCP_TERMACK		0x06
#define	PPPIPCP_CODEREJ		0x07

/* IPCP options */
#define	IPCPOPT_IPADDRS		0x01
#define	IPCPOPT_COMPR		0x02
#define	IPCPOPT_IPADDR		0x03

/*
 * pppipcp module data structures and state machines.
 */

struct pppipcp_softc {
	struct in_ifaddr *ipcp_ia;	/* IP addresses assigned to this if */
	short		ipcp_state;	/* IPCP automaton state */
	short		ipcp_timer;	/* like if_timer for IPCP */
	short		ipcp_restcnt;	/* like pp_restcnt for IPCP */
	short		ipcp_negstate;	/* negot state for ConfReqs we send */
	u_char		ipcp_lastreqid;	/* ID of last ConfReq packet sent */
};

/* IPCP automaton states (subset of global PPP/LCP ones plus one we added) */
#define	PPPIPCP_STATE_INITIAL	0
#define	PPPIPCP_STATE_STOPPED	3
#define	PPPIPCP_STATE_STOPPING	5
#define	PPPIPCP_STATE_REQSENT	6
#define	PPPIPCP_STATE_ACKRCVD	7
#define	PPPIPCP_STATE_ACKSENT	8
#define	PPPIPCP_STATE_OPENED	9
/*
 * Like REQSENT, but can't send ConfReqs until we get one from peer with needed
 * options.
 */
#define	PPPIPCP_STATE_PAUSED	10

/* ipcp_negstate bits */
#define	IPCPNEGOT_SENDIPADDRS	0x0001
#define	IPCPNEGOT_SENDIPADDR	0x0002
#define	IPCPNEGOT_NEEDIPADDRS	0x0004
#define	IPCPNEGOT_NEEDIPADDR	0x0008
#define	IPCPNEGOT_DRAW		0x8000

#ifdef KERNEL
extern struct pppipcp_softc pppipcp_softc[];
extern struct ifqueue pppipcpinq;
#endif
