h51499
s 00010/00005/00046
d D 7.3 88/06/29 17:21:22 bostic 36 35
c install approved copyright notice
e
s 00008/00002/00043
d D 7.2 87/12/30 12:06:40 bostic 35 34
c add Berkeley header
e
s 00001/00001/00044
d D 7.1 86/06/05 00:16:11 mckusick 34 33
c 4.3BSD release version
e
s 00001/00001/00044
d D 6.5 85/12/19 14:52:31 karels 33 32
c allow rights in streams
e
s 00007/00001/00038
d D 6.4 85/06/08 14:59:14 mckusick 32 31
c Add copyright
e
s 00005/00005/00034
d D 6.3 84/08/29 20:27:56 bloom 31 30
c Change to includes.  no more ../h
e
s 00007/00003/00032
d D 6.2 84/08/21 10:42:04 karels 30 29
c change datagram queuing to use m_act properly; type mbufs with rights;
c change protocol family number in protosw to pointer to domain (for sam)
e
s 00000/00000/00035
d D 6.1 83/07/29 06:47:01 sam 29 28
c 4.2 distribution
e
s 00001/00001/00034
d D 4.28 83/05/27 12:50:26 sam 28 27
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00009/00192/00026
d D 4.27 82/11/02 11:35:01 root 27 26
c domain style
e
s 00002/00002/00216
d D 4.26 82/10/17 21:52:12 root 26 25
c more lint
e
s 00002/00002/00216
d D 4.25 82/10/09 05:39:15 wnj 25 24
c fix up header file dependencies 
e
s 00000/00000/00218
d D 4.24 82/10/03 23:38:48 root 24 23
c overhaul
e
s 00006/00000/00212
d D 4.23 82/09/06 22:58:05 root 23 22
c 
e
s 00000/00006/00212
d D 4.22 82/06/20 12:21:54 sam 22 21
c purge COUNT crap now that we have gprof
e
s 00005/00003/00213
d D 4.21 82/04/25 18:36:38 sam 21 20
c icmp needs protocol family
e
s 00019/00008/00197
d D 4.20 82/04/24 20:39:52 sam 20 19
c icmp and ctlinput working
e
s 00008/00008/00197
d D 4.19 82/03/28 14:25:59 sam 19 18
c purge raw junk
e
s 00001/00002/00204
d D 4.18 82/03/13 12:54:53 sam 18 17
c lint
e
s 00002/00002/00204
d D 4.17 82/03/03 11:07:55 root 17 16
c update for raw pup
e
s 00019/00003/00187
d D 4.16 82/02/15 11:26:03 root 16 15
c rename raw imp stuff and add in raw pup
e
s 00001/00001/00189
d D 4.15 82/02/01 15:14:44 sam 15 14
c make rip PR_ADDR again
e
s 00028/00002/00162
d D 4.14 82/01/25 18:38:24 wnj 14 13
c bug fixes (round 1)
e
s 00002/00002/00162
d D 4.13 81/12/20 15:25:22 root 13 12
c typo in fasttimo code
e
s 00000/00000/00164
d D 4.12 81/12/12 18:07:42 root 12 11
c delete prints
e
s 00023/00000/00141
d D 4.11 81/12/12 17:49:41 root 11 10
c almost works
e
s 00004/00004/00137
d D 4.10 81/12/03 17:27:22 wnj 10 9
c cleanup
e
s 00017/00017/00124
d D 4.9 81/11/30 16:23:19 wnj 9 8
c lint
e
s 00004/00004/00137
d D 4.8 81/11/26 11:58:41 wnj 8 7
c before carry to arpavax
e
s 00003/00003/00138
d D 4.7 81/11/21 21:30:26 wnj 7 6
c CONNREQUIRED for TCP; <= protoswLAST in loops
e
s 00004/00004/00137
d D 4.6 81/11/20 00:46:03 wnj 6 5
c linted
e
s 00009/00006/00132
d D 4.5 81/11/18 15:45:17 wnj 5 4
c more cleanup
e
s 00001/00001/00137
d D 4.4 81/11/16 14:20:59 wnj 4 3
c lint
e
s 00073/00128/00065
d D 4.3 81/11/14 16:43:49 wnj 3 2
c before header overlay
e
s 00045/00032/00148
d D 4.2 81/11/08 16:56:57 wnj 2 1
c first listing
e
s 00180/00000/00000
d D 4.1 81/11/07 17:59:33 wnj 1 0
c date and time created 81/11/07 17:59:33 by wnj
e
u
U
t
T
I 2
D 32
/*	%M%	%I%	%E%	*/
E 32
I 32
/*
D 34
 * Copyright (c) 1982 Regents of the University of California.
E 34
I 34
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 34
D 35
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 35
I 35
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 35
 *
 *	%W% (Berkeley) %G%
 */
E 32

E 2
I 1
D 31
#include "../h/param.h"
D 2
#include "../inet/protocol.h"
#include "../inet/protocolsw.h"
E 2
I 2
#include "../h/socket.h"
D 5
#include "../h/protocol.h"
E 5
#include "../h/protosw.h"
I 27
#include "../h/domain.h"
E 27
#include "../h/mbuf.h"
E 31
I 31
#include "param.h"
#include "socket.h"
#include "protosw.h"
#include "domain.h"
#include "mbuf.h"
E 31
I 23
D 27
#include <time.h>
#include "../h/kernel.h"
E 23
D 8
#include "../net/inet.h"
I 5
#include "../net/inet_systm.h"
E 8
I 8
D 25
#include "../net/in.h"
#include "../net/in_systm.h"
E 25
I 25
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 27
E 25
E 8
E 5

E 2
D 3
/* should include a header file giving desired protocols */
#define	NTCP	1

E 3
/*
D 27
 * Protocol configuration table and routines to search it.
I 3
 *
 * SHOULD INCLUDE A HEADER FILE GIVING DESIRED PROTOCOLS
E 27
I 27
 * Definitions of protocols supported in the UNIX domain.
E 27
E 3
 */

D 27
/*
D 3
 * Generic (local or not yet specified) protocol.
E 3
I 3
 * Local protocol handler.
E 3
 */
D 3
int	gen_usrreq();
E 3
I 3
D 5
int	pi_usrreq();
E 5
I 5
int	piusrreq();
E 5
E 3

D 3
#if NTCP > 0
E 3
/*
 * TCP/IP protocol family: IP, ICMP, UDP, TCP.
 */
D 2
int	ip_input(),ip_output(),ip_advise(),ip_slowtimo(),ip_drain();
int	icmp_input(),icmp_output();
E 2
I 2
D 3
int	ip_init(),ip_input(),ip_output(),ip_advise(),ip_slowtimo(),ip_drain();
int	icmp_input(),icmp_drain();
E 2
int	udp_input(),udp_advise(),udp_usrreq(),udp_sense();
D 2
int	tcp_input(),tcp_advise(),tcp_fasttimo(),tcp_slowtimo(),
	    tcp_drain(),tcp_sense();
int	rawip_input(),rawip_advise(),rawip_advise(),rawip_usrreq(),
	    rawip_sense();
E 2
I 2
int	tcp_init(),tcp_input(),tcp_advise(),tcp_fasttimo(),tcp_slowtimo(),
	    tcp_usrreq(),tcp_drain(),tcp_sense();
int	ri_input(),ri_advise(),ri_usrreq(),ri_sense();
E 2
#endif
E 3
I 3
D 4
int	ip_input(),ip_output(),ip_ctloutput();
E 4
I 4
D 8
int	ip_input(),ip_output();
E 8
I 8
int	ip_output();
E 8
E 4
int	ip_init(),ip_slowtimo(),ip_drain();
D 10
int	icmp_input();
E 10
I 10
D 20
int	icmp_input(),icmp_ctlinput();
E 10
int	icmp_drain();
E 20
I 20
int	icmp_input();
E 20
int	udp_input(),udp_ctlinput();
D 10
int	udp_usrreq(),udp_sense();
E 10
I 10
int	udp_usrreq();
E 10
int	udp_init();
int	tcp_input(),tcp_ctlinput();
D 10
int	tcp_usrreq(),tcp_sense();
E 10
I 10
int	tcp_usrreq();
E 10
int	tcp_init(),tcp_fasttimo(),tcp_slowtimo(),tcp_drain();
D 6
int	ri_input(),ri_ctlinput();
int	ri_usrreq(),ri_sense();
E 6
I 6
D 9
int	rip_input(),rip_ctlinput();
int	rip_usrreq(),rip_sense();
E 9
I 9
D 18
int	rip_input(),rip_output(),rip_ctlinput();
int	rip_usrreq(),rip_slowtimo();
E 18
I 18
D 19
int	rip_input(),rip_output(),rip_ctlinput(),rip_usrreq();
E 19
I 19
int	rip_input(),rip_output();
E 19
E 18
E 9
E 6
E 3

I 14
/*
D 21
 * IMP protocol family: raw interface
E 21
I 21
 * IMP protocol family: raw interface.
 * Using the raw interface entry to get the timer routine
 * in is a kludge.
E 21
 */
#include "imp.h"
#if NIMP > 0
D 16
int	imp_usrreq(),imp_output(),imp_ctlinput();
E 16
I 16
D 19
int	rimp_usrreq(),rimp_output(),rimp_ctlinput();
E 19
I 19
D 21
int	rimp_output();
E 21
I 21
int	rimp_output(), hostslowtimo();
E 21
E 19
E 16
#endif

/*
I 16
 * PUP-I protocol family: raw interface
 */
#include "pup.h"
#if NPUP > 0
D 17
int	rpup_usrreq(),rpup_output(),rpup_ctlinput();
E 17
I 17
D 19
int	rpup_output(),rpup_ctlinput();
E 19
I 19
int	rpup_output();
E 19
E 17
#endif

/*
E 16
 * Sundries.
*/
E 27
I 27
int	uipc_usrreq();
E 27
D 20
int	raw_init(),raw_usrreq(),raw_input();
E 20
I 20
int	raw_init(),raw_usrreq(),raw_input(),raw_ctlinput();
I 30
extern	struct domain unixdomain;		/* or at least forward */
E 30
E 20

E 14
D 3
#if NPUP > 0
/*
 * Pup protocols: PUP, BSP.
 */
int	pup1_input(),pup1_output(),pup1_advise(),pup1_slowtimo(),
	    pup1_drain(),pup1_usrreq(),pup1_sense();
int	bsp_input(),bsp_advise(),bsp_fasttimo(),bsp_slowtimo(),
	    bsp_drain(),bsp_usrreq(),bsp_sense();
int	rawpup_input(),rawpup_usrreq(),rawpup_sense();
#endif

#if NCHAOS > 0
/*
 * Chaosnet protocols.
 */
/* ... */
#endif

#if NOISCP > 0
/*
 * Office information system communcation protocols.
 */
/* ... */
#endif

#if NNBS > 0
/*
 * NBS protocols.
 */
/* ... */
#endif

#if NECMA > 0
/*
 * ECMA protocols.
 */
/* ... */
#endif

#if NDATAKIT > 0
/*
 * Datakit protocols.
 */
/* ... */
#endif

E 3
D 27
struct protosw protosw[] = {
D 3
{ SOCK_STREAM,	PF_GENERIC,	0,		0,
E 3
I 3
D 9
{ SOCK_STREAM,	PF_LOCAL,	0,		PR_CONNREQUIRED,
E 9
I 9
{ SOCK_STREAM,	PF_UNIX,	0,		PR_CONNREQUIRED,
E 27
I 27
struct protosw unixsw[] = {
D 30
{ SOCK_STREAM,	PF_UNIX,	0,		PR_CONNREQUIRED|PR_WANTRCVD,
E 30
I 30
D 33
{ SOCK_STREAM,	&unixdomain,	0,		PR_CONNREQUIRED|PR_WANTRCVD,
E 33
I 33
{ SOCK_STREAM,	&unixdomain,	0,	PR_CONNREQUIRED|PR_WANTRCVD|PR_RIGHTS,
E 33
E 30
E 27
E 9
E 3
D 2
  0,		0,		0,
E 2
I 2
  0,		0,		0,		0,
E 2
D 3
  0,		0,		0,		gen_usrreq,	0,
  0 },
D 2
{ SOCK_DGRAM,	PF_GENERIC,	0,		PR_ATOMIC|PR_PROVIDEADDR,
  0,		0,		0,
E 2
I 2
{ SOCK_DGRAM,	PF_GENERIC,	0,		PR_ATOMIC|PR_ADDR,
E 3
I 3
D 5
  pi_usrreq,	0,		0,
E 5
I 5
D 9
  piusrreq,	0,		0,
E 9
I 9
D 27
  piusrreq,
E 27
I 27
  uipc_usrreq,
E 27
E 9
E 5
E 3
  0,		0,		0,		0,
E 2
D 3
  0,		0,		0,		gen_usrreq,	0,
  0 },
D 2
{ SOCK_RDM,	PF_GENERIC,	0,		PR_ATOMIC|PR_PROVIDEADDR,
  0,		0,		0,
E 2
I 2
{ SOCK_RDM,	PF_GENERIC,	0,		PR_ATOMIC|PR_ADDR,
E 3
I 3
},
D 9
{ SOCK_DGRAM,	PF_LOCAL,	0,		PR_ATOMIC|PR_ADDR,
E 9
I 9
D 28
{ SOCK_DGRAM,	PF_UNIX,	0,		PR_ATOMIC|PR_ADDR,
E 28
I 28
D 30
{ SOCK_DGRAM,	PF_UNIX,	0,		PR_ATOMIC|PR_ADDR|PR_RIGHTS,
E 30
I 30
{ SOCK_DGRAM,	&unixdomain,	0,		PR_ATOMIC|PR_ADDR|PR_RIGHTS,
E 30
E 28
E 9
E 3
  0,		0,		0,		0,
E 2
D 3
  0,		0,		0,		gen_usrreq,	0,
  0 },
D 2
{ SOCK_RAW,	PF_GENERIC,	0,		PR_ATOMIC|PR_PROVIDEADDR,
  0,		0,		0,
E 2
I 2
{ SOCK_RAW,	PF_GENERIC,	0,		PR_ATOMIC|PR_ADDR,
E 3
I 3
D 5
  pi_usrreq,	0,		0,
E 5
I 5
D 9
  piusrreq,	0,		0,
E 9
I 9
D 27
  piusrreq,
E 27
I 27
  uipc_usrreq,
E 27
E 9
E 5
E 3
  0,		0,		0,		0,
E 2
D 3
  0,		0,		0,		gen_usrreq,	0,
I 2
  0 },
E 2
#if NTCP > 0
E 3
I 3
},
D 9
{ SOCK_RDM,	PF_LOCAL,	0,		PR_ATOMIC|PR_ADDR,
E 9
I 9
D 27
{ SOCK_RDM,	PF_UNIX,	0,		PR_ATOMIC|PR_ADDR,
E 9
  0,		0,		0,		0,
D 5
  pi_usrreq,	0,		0,
E 5
I 5
D 9
  piusrreq,	0,		0,
E 9
I 9
  piusrreq,
E 9
E 5
  0,		0,		0,		0,
},
D 9
{ SOCK_RAW,	PF_LOCAL,	0,		PR_ATOMIC|PR_ADDR,
E 9
I 9
{ SOCK_RAW,	PF_UNIX,	0,		PR_ATOMIC|PR_ADDR,
E 9
  0,		0,		0,		0,
D 5
  pi_usrreq,	0,		0,
E 5
I 5
D 9
  piusrreq,	0,		0,
E 9
I 9
  piusrreq,
E 9
E 5
  0,		0,		0,		0,
},
E 27
E 3
{ 0,		0,		0,		0,
D 2
  ip_input,	ip_output,	0,
E 2
I 2
D 3
  ip_init,	ip_input,	ip_output,	0,
E 2
  0,		ip_slowtimo,	ip_drain,	0,		0,
  0 },
E 3
I 3
D 8
  ip_input,	ip_output,	0,		0,
E 8
I 8
D 27
  0,		ip_output,	0,		0,
E 8
D 9
  0,		0,		0,
E 9
I 9
  0,
E 9
  ip_init,	0,		ip_slowtimo,	ip_drain,
},
E 3
D 20
{ 0,		0,		IPPROTO_ICMP,	0,
D 2
  icmp_input,	icmp_output,	0,
E 2
I 2
D 3
  0,		icmp_input,	0,		0,
E 2
  0,		0,		icmp_drain,	0,		0,
  0 },
E 3
I 3
D 10
  icmp_input,	0,		0,		0,
E 10
I 10
  icmp_input,	0,		icmp_ctlinput,	0,
E 20
I 20
{ 0,		PF_INET,	IPPROTO_ICMP,	0,
  icmp_input,	0,		0,		0,
E 20
E 10
D 9
  0,		0,		0,
E 9
I 9
  0,
E 9
D 20
  0,		0,		0,		icmp_drain,
E 20
I 20
  0,		0,		0,		0,
E 20
},
E 3
D 2
{ SOCK_DGRAM,	PF_INET,	IPPROTO_UDP,	PR_ATOMIC|PR_PROVIDEADDR,
  udp_input,	0,		udp_advise,
E 2
I 2
{ SOCK_DGRAM,	PF_INET,	IPPROTO_UDP,	PR_ATOMIC|PR_ADDR,
D 3
  0,		udp_input,	0,		udp_advise,
E 2
  0,		0,		0,		udp_usrreq,	udp_sense,
  MLEN },
{ SOCK_STREAM,	PF_INET,	IPPROTO_TCP,	0,
D 2
  tcp_input,	0,		tcp_advise,
E 2
I 2
  tcp_init,	tcp_input,	0,		tcp_advise,
E 2
  tcp_fasttimo,	tcp_slowtimo,	tcp_drain,	tcp_usrreq,	tcp_sense,
  MLEN },
E 3
I 3
  udp_input,	0,		udp_ctlinput,	0,
D 9
  udp_usrreq,	udp_sense,	MLEN,
E 9
I 9
  udp_usrreq,
E 9
  udp_init,	0,		0,		0,
},
D 7
{ SOCK_STREAM,	PF_INET,	IPPROTO_TCP,	PR_CONNREQUIRED,
E 7
I 7
{ SOCK_STREAM,	PF_INET,	IPPROTO_TCP,	PR_CONNREQUIRED|PR_WANTRCVD,
E 7
  tcp_input,	0,		tcp_ctlinput,	0,
D 9
  tcp_usrreq,	tcp_sense,	MLEN,
E 9
I 9
  tcp_usrreq,
E 9
  tcp_init,	tcp_fasttimo,	tcp_slowtimo,	tcp_drain,
},
E 3
D 2
{ SOCK_RAW,	PF_INET,	IPPROTO_RAW,	PR_ATOMIC|PR_PROVIDEADDR,
  ri_input,	0,		ri_advise,
  ri_fasttimo,	ri_slowtimo,	ri_drain,	ri_usrreq,	ri_sense,
E 2
I 2
D 14
{ SOCK_RAW,	PF_INET,	IPPROTO_RAW,	PR_ATOMIC|PR_ADDR,
E 14
I 14
{ 0,		0,		0,		0,
E 27
D 20
  raw_input,	0,		0,		0,
E 20
I 20
  raw_input,	0,		raw_ctlinput,	0,
E 20
  raw_usrreq,
  raw_init,	0,		0,		0,
D 27
},
D 15
{ SOCK_RAW,	PF_INET,	IPPROTO_RAW,	PR_ATOMIC,
E 15
I 15
{ SOCK_RAW,	PF_INET,	IPPROTO_RAW,	PR_ATOMIC|PR_ADDR,
E 15
E 14
D 3
  0,		ri_input,	0,		ri_advise,
  0,		0,		0,		ri_usrreq,	ri_sense,
E 2
  MLEN },
#endif
#if NPUP > 0
D 2
{ SOCK_DGRAM,	PF_PUP,		0,		PR_ATOMIC|PR_PROVIDEADDR,
  pup_input,	pup_output,	pup_advise,
E 2
I 2
{ SOCK_DGRAM,	PF_PUP,		0,		PR_ATOMIC|PR_ADDR,
  pup_init,	pup_input,	pup_output,	pup_advise,
E 2
  0,		pup_slowtimo,	pup_drain,	pup_usrreq,	pup_sense,
  MLEN },
{ SOCK_STREAM,	PF_PUP1,	PUPPROTO_BSP,	0,
D 2
  bsp_input,	0,		bsp_advise,
E 2
I 2
  bsp_init,	bsp_input,	0,		bsp_advise,
E 2
  bsp_fasttimo,	bsp_slowtimo,	bsp_drain,	bsp_usrreq,	bsp_sense,
  MLEN },
D 2
{ SOCK_RAW,	PF_PUP1,	PUPPROTO_RAW,	PR_ATOMIC|PR_PROVIDEADDR,
  rp_input,	0,		rp_advise,
E 2
I 2
{ SOCK_RAW,	PF_PUP1,	PUPPROTO_RAW,	PR_ATOMIC|PR_ADDR,
  rp_init,	rp_input,	0,		rp_advise,
E 2
  rp_fasttimo,	rp_slowtimo,	rp_drain,	rp_usrreq,	rp_sense,
  MLEN	},
#endif
#if NCHAOS > 0
/* ... */
#endif
#if NOISCP > 0
/* ... */
#endif
#if NNBS > 0
/* ... */
#endif
#if NECMA > 0
/* ... */
#endif
#if NDATAKIT > 0
/* ... */
#endif
E 3
I 3
D 6
  ri_input,	0,		ri_ctlinput,	0,
  ri_usrreq,	ri_sense,	MLEN,
E 6
I 6
D 9
  rip_input,	0,		rip_ctlinput,	0,
  rip_usrreq,	rip_sense,	MLEN,
E 6
  0,		0,		0,		0,
E 9
I 9
D 19
  rip_input,	rip_output,	rip_ctlinput,	0,
  rip_usrreq,
E 19
I 19
D 20
  rip_input,	rip_output,	0,		0,
E 20
I 20
  rip_input,	rip_output,	0,	0,
E 20
  raw_usrreq,
E 19
D 14
  0,		0,		rip_slowtimo,	0,
E 14
I 14
  0,		0,		0,		0,
E 27
E 14
E 9
}
I 14
D 27
#if NIMP > 0
,
{ SOCK_RAW,	PF_IMPLINK,	0,		PR_ATOMIC|PR_ADDR,
D 16
  0,		imp_output,	imp_ctlinput,	0,
  imp_usrreq,
E 16
I 16
D 19
  0,		rimp_output,	rimp_ctlinput,	0,
  rimp_usrreq,
E 19
I 19
  0,		rimp_output,	0,		0,
  raw_usrreq,
E 19
D 21
  0,		0,		0,		0,
E 21
I 21
  0,		0,		hostslowtimo,	0,
E 21
}
#endif
#if NPUP > 0
,
{ SOCK_RAW,	PF_PUP,		0,		PR_ATOMIC|PR_ADDR,
D 19
  0,		rpup_output,	rpup_ctlinput,	0,
E 19
I 19
  0,		rpup_output,	0,		0,
E 19
D 17
  rpup_usrreq,
E 17
I 17
  raw_usrreq,
E 17
E 16
  0,		0,		0,		0,
}
#endif
E 27
E 14
E 3
};
D 3
#define	protoswEND	&protosw[sizeof (protosw)/sizeof (protosw[0])]
E 3

I 30
int	unp_externalize(), unp_dispose();

E 30
I 3
D 27
#define	NPROTOSW	(sizeof(protosw) / sizeof(protosw[0]))

struct	protosw *protoswLAST = &protosw[NPROTOSW-1];

E 3
/*
 * Operations on protocol table and protocol families.
 */

/*
I 3
 * Initialize all protocols.
 */
pfinit()
{
	register struct protosw *pr;

I 5
D 22
COUNT(PFINIT);
E 22
E 5
	for (pr = protoswLAST; pr >= protosw; pr--)
		if (pr->pr_init)
			(*pr->pr_init)();
I 23
	pffasttimo();
	pfslowtimo();
E 23
}

/*
E 3
 * Find a standard protocol in a protocol family
 * of a specific type.
 */
D 2
pf_stdproto(family, type)
E 2
I 2
struct protosw *
D 3
pf_findtype(family, type)
E 3
I 3
pffindtype(family, type)
E 3
E 2
	int family, type;
{
	register struct protosw *pr;

I 5
D 22
COUNT(PFFINDTYPE);
E 22
E 5
	if (family == 0)
		return (0);
D 3
	for (pr = protosw; pr < protoswEND; pr++)
E 3
I 3
D 7
	for (pr = protosw; pr < protoswLAST; pr++)
E 7
I 7
	for (pr = protosw; pr <= protoswLAST; pr++)
E 7
E 3
		if (pr->pr_family == family && pr->pr_type == type)
			return (pr);
	return (0);
}

/*
 * Find a specified protocol in a specified protocol family.
 */
D 2
pf_findproto(family, proto)
	int family, proto;
E 2
I 2
struct protosw *
D 3
pf_findproto(family, protocol)
E 3
I 3
pffindproto(family, protocol)
E 3
	int family, protocol;
E 2
{
	register struct protosw *pr;

I 5
D 22
COUNT(PFFINDPROTO);
E 22
E 5
	if (family == 0)
		return (0);
D 3
	for (pr = protosw; pr < protoswEND; pr++)
E 3
I 3
D 7
	for (pr = protosw; pr < protoswLAST; pr++)
E 7
I 7
	for (pr = protosw; pr <= protoswLAST; pr++)
E 7
E 3
D 2
		if (pr->pr_family == family && pr->pr_proto == proto)
E 2
I 2
		if (pr->pr_family == family && pr->pr_protocol == protocol)
E 2
			return (pr);
	return (0);
I 20
}

pfctlinput(cmd, arg)
	int cmd;
	caddr_t arg;
{
	register struct protosw *pr;
D 22
COUNT(PFCTLINPUT);
E 22

	for (pr = protosw; pr <= protoswLAST; pr++)
		if (pr->pr_ctlinput)
			(*pr->pr_ctlinput)(cmd, arg);
E 20
I 2
D 3
}

prinit()
{

E 3
E 2
}
I 11

/*
 * Slow timeout on all protocols.
 */
pfslowtimo()
{
	register struct protosw *pr;

D 22
COUNT(PFSLOWTIMO);
E 22
	for (pr = protoswLAST; pr >= protosw; pr--)
		if (pr->pr_slowtimo)
			(*pr->pr_slowtimo)();
I 23
D 26
	timeout(pfslowtimo, 0, hz / PR_SLOWHZ);
E 26
I 26
	timeout(pfslowtimo, (caddr_t)0, hz / PR_SLOWHZ);
E 26
E 23
}

pffasttimo()
{
	register struct protosw *pr;

D 22
COUNT(PFSLOWTIMO);
E 22
	for (pr = protoswLAST; pr >= protosw; pr--)
D 13
		if (pr->pr_slowtimo)
			(*pr->pr_slowtimo)();
E 13
I 13
		if (pr->pr_fasttimo)
			(*pr->pr_fasttimo)();
I 23
D 26
	timeout(pffasttimo, 0, hz / PR_FASTHZ);
E 26
I 26
	timeout(pffasttimo, (caddr_t)0, hz / PR_FASTHZ);
E 26
E 23
E 13
}
E 27
I 27
struct domain unixdomain =
D 30
    { AF_UNIX, "unix", unixsw, &unixsw[sizeof(unixsw)/sizeof(unixsw[0])] };
E 30
I 30
    { AF_UNIX, "unix", 0, unp_externalize, unp_dispose,
      unixsw, &unixsw[sizeof(unixsw)/sizeof(unixsw[0])] };
E 30
E 27
E 11
E 1
