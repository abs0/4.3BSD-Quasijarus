h14367
s 00011/00000/00138
d D 7.4 07/05/18 19:58:52 msokolov 22 21
c added GRE
e
s 00010/00005/00128
d D 7.3 88/06/29 17:06:42 bostic 21 20
c install approved copyright notice
e
s 00008/00002/00125
d D 7.2 87/12/07 17:45:24 bostic 20 19
c use Berkeley specific header
e
s 00001/00001/00126
d D 7.1 86/06/05 00:26:27 mckusick 19 18
c 4.3BSD release version
e
s 00001/00001/00126
d D 6.14 86/02/19 16:54:16 karels 18 17
c fix hydomain
e
s 00004/00004/00123
d D 6.13 86/02/01 21:21:42 karels 17 16
c add rip_ctloutput
e
s 00002/00002/00125
d D 6.12 85/10/01 14:58:27 sklower 16 15
c add ctlinput for nsip.  (To reap dead routes).
e
s 00008/00007/00119
d D 6.11 85/09/16 22:53:04 karels 15 14
c add ctloutput routines; update hylink
e
s 00001/00001/00125
d D 6.10 85/08/09 12:26:14 karels 14 13
c change NSIP to use IPPROTO_IDP for keith
e
s 00019/00000/00107
d D 6.9 85/06/24 15:44:45 karels 13 12
c raw hyperchannel
e
s 00007/00001/00100
d D 6.8 85/06/08 12:38:54 mckusick 12 11
c Add copyright
e
s 00016/00004/00085
d D 6.7 85/06/02 23:40:19 karels 11 10
c remove EGP entry, add wildcard raw socket (don't ask about the other)
e
s 00007/00007/00082
d D 6.6 84/08/29 15:36:08 bloom 10 9
c Include file changes.  No more ../h
e
s 00015/00016/00074
d D 6.5 84/08/21 10:22:58 karels 9 8
c change protocol family number in protosw to pointer to domain
e
s 00005/00007/00085
d D 6.4 84/07/31 17:58:50 karels 8 7
c add EGP
e
s 00005/00005/00087
d D 6.3 84/02/15 14:13:42 karels 7 6
c move ICMP after raw IP, making IP the default for SOCK_RAW
e
s 00003/00003/00089
d D 6.2 83/12/15 14:59:09 karels 6 5
c add raw socket access to ICMP
e
s 00000/00000/00092
d D 6.1 83/07/29 07:11:22 sam 5 4
c 4.2 distribution
e
s 00014/00000/00078
d D 5.4 83/01/17 16:01:59 sam 4 3
c add croft's stuff
e
s 00003/00002/00075
d D 5.3 82/11/03 01:08:17 root 3 2
c misc 4.1c fixes
e
s 00013/00005/00064
d D 5.2 82/08/01 12:15:02 root 2 1
c split up protosw per domain
e
s 00069/00000/00000
d D 5.1 82/07/31 21:28:44 root 1 0
c date and time created 82/07/31 21:28:44 by root
e
u
U
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 19
 * Copyright (c) 1982 Regents of the University of California.
E 19
I 19
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 19
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 *
 *	%W% (Berkeley) %G%
 */
E 12

D 10
#include "../h/param.h"
#include "../h/socket.h"
#include "../h/protosw.h"
I 2
#include "../h/domain.h"
E 2
#include "../h/mbuf.h"
E 10
I 10
#include "param.h"
#include "socket.h"
#include "protosw.h"
#include "domain.h"
#include "mbuf.h"
E 10
D 3
#include "../net/in.h"
#include "../net/in_systm.h"
E 3
I 3

D 10
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 10
I 10
#include "in.h"
#include "in_systm.h"
E 10
E 3

/*
 * TCP/IP protocol family: IP, ICMP, UDP, TCP.
 */
D 15
int	ip_output();
E 15
I 15
int	ip_output(),ip_ctloutput();
E 15
int	ip_init(),ip_slowtimo(),ip_drain();
int	icmp_input();
int	udp_input(),udp_ctlinput();
int	udp_usrreq();
int	udp_init();
int	tcp_input(),tcp_ctlinput();
D 15
int	tcp_usrreq();
E 15
I 15
int	tcp_usrreq(),tcp_ctloutput();
E 15
int	tcp_init(),tcp_fasttimo(),tcp_slowtimo(),tcp_drain();
D 17
int	rip_input(),rip_output();
E 17
I 17
int	rip_input(),rip_output(),rip_ctloutput();
E 17
I 2
extern	int raw_usrreq();
E 2
/*
 * IMP protocol family: raw interface.
 * Using the raw interface entry to get the timer routine
 * in is a kludge.
 */
#include "imp.h"
#if NIMP > 0
int	rimp_output(), hostslowtimo();
#endif
I 4
D 9
/*
 * Network disk protocol: runs on top of IP
 */
#include "nd.h"
#if NND > 0
int	nd_input(), nd_slowtimo(), nd_init();
#endif
E 9
E 4

I 11
#ifdef NSIP
D 16
int	idpip_input();
E 16
I 16
int	idpip_input(), nsip_ctlinput();
E 16
#endif

I 22
#ifdef GRETERM
int	gre_input();
#endif

E 22
E 11
I 9
extern	struct domain inetdomain;

E 9
struct protosw inetsw[] = {
D 2
{ 0,		0,		0,		0,
E 2
I 2
D 9
{ 0,		PF_INET,	0,		0,
E 9
I 9
{ 0,		&inetdomain,	0,		0,
E 9
E 2
  0,		ip_output,	0,		0,
  0,
  ip_init,	0,		ip_slowtimo,	ip_drain,
},
D 6
{ 0,		PF_INET,	IPPROTO_ICMP,	0,
  icmp_input,	0,		0,		0,
  0,
E 6
I 6
D 7
{ SOCK_RAW,	PF_INET,	IPPROTO_ICMP,	PR_ATOMIC|PR_ADDR,
  icmp_input,	rip_output,	0,		0,
  raw_usrreq,
E 6
  0,		0,		0,		0,
},
E 7
D 9
{ SOCK_DGRAM,	PF_INET,	IPPROTO_UDP,	PR_ATOMIC|PR_ADDR,
E 9
I 9
{ SOCK_DGRAM,	&inetdomain,	IPPROTO_UDP,	PR_ATOMIC|PR_ADDR,
E 9
D 15
  udp_input,	0,		udp_ctlinput,	0,
E 15
I 15
  udp_input,	0,		udp_ctlinput,	ip_ctloutput,
E 15
  udp_usrreq,
  udp_init,	0,		0,		0,
},
D 9
{ SOCK_STREAM,	PF_INET,	IPPROTO_TCP,	PR_CONNREQUIRED|PR_WANTRCVD,
E 9
I 9
{ SOCK_STREAM,	&inetdomain,	IPPROTO_TCP,	PR_CONNREQUIRED|PR_WANTRCVD,
E 9
D 15
  tcp_input,	0,		tcp_ctlinput,	0,
E 15
I 15
  tcp_input,	0,		tcp_ctlinput,	tcp_ctloutput,
E 15
  tcp_usrreq,
  tcp_init,	tcp_fasttimo,	tcp_slowtimo,	tcp_drain,
},
D 9
{ SOCK_RAW,	PF_INET,	IPPROTO_RAW,	PR_ATOMIC|PR_ADDR,
E 9
I 9
{ SOCK_RAW,	&inetdomain,	IPPROTO_RAW,	PR_ATOMIC|PR_ADDR,
E 9
D 15
  rip_input,	rip_output,	0,	0,
E 15
I 15
D 17
  rip_input,	rip_output,	0,		0,
E 17
I 17
  rip_input,	rip_output,	0,		rip_ctloutput,
E 17
E 15
I 7
  raw_usrreq,
  0,		0,		0,		0,
},
I 8
D 9
{ SOCK_RAW,	PF_INET,	IPPROTO_EGP,	PR_ATOMIC|PR_ADDR,
E 9
I 9
D 11
{ SOCK_RAW,	&inetdomain,	IPPROTO_EGP,	PR_ATOMIC|PR_ADDR,
E 9
  rip_input,	rip_output,	0,	0,
E 11
I 11
{ SOCK_RAW,	&inetdomain,	IPPROTO_ICMP,	PR_ATOMIC|PR_ADDR,
D 17
  icmp_input,	rip_output,	0,		0,
E 17
I 17
  icmp_input,	rip_output,	0,		rip_ctloutput,
E 17
E 11
  raw_usrreq,
  0,		0,		0,		0,
},
E 8
D 9
{ SOCK_RAW,	PF_INET,	IPPROTO_ICMP,	PR_ATOMIC|PR_ADDR,
E 9
I 9
D 11
{ SOCK_RAW,	&inetdomain,	IPPROTO_ICMP,	PR_ATOMIC|PR_ADDR,
E 9
  icmp_input,	rip_output,	0,		0,
E 11
I 11
#ifdef NSIP
D 14
{ SOCK_RAW,	&inetdomain,	IPPROTO_PUP,	PR_ATOMIC|PR_ADDR,
E 14
I 14
{ SOCK_RAW,	&inetdomain,	IPPROTO_IDP,	PR_ATOMIC|PR_ADDR,
E 14
D 16
  idpip_input,	rip_output,	0,		0,
E 16
I 16
  idpip_input,	rip_output,	nsip_ctlinput,	0,
I 22
  raw_usrreq,
  0,		0,		0,		0,
},
#endif
#ifdef GRETERM
{ SOCK_RAW,	&inetdomain,	IPPROTO_GRE,	PR_ATOMIC|PR_ADDR,
  gre_input,	rip_output,	0,		0,
E 22
E 16
  raw_usrreq,
  0,		0,		0,		0,
},
#endif
	/* raw wildcard */
{ SOCK_RAW,	&inetdomain,	0,		PR_ATOMIC|PR_ADDR,
D 15
  rip_input,	rip_output,	0,	0,
E 15
I 15
D 17
  rip_input,	rip_output,	0,		0,
E 17
I 17
  rip_input,	rip_output,	0,		rip_ctloutput,
E 17
E 15
E 11
E 7
  raw_usrreq,
  0,		0,		0,		0,
},
I 4
D 8
#if NND > 0
{ 0,		PF_INET,	IPPROTO_ND,	0,
  nd_input,	0,		0,		0,
  0,
  nd_init,	0,		nd_slowtimo,	0,
},
#endif
E 8
E 4
I 2
};

struct domain inetdomain =
D 9
    { AF_INET, "internet", inetsw, &inetsw[sizeof(inetsw)/sizeof(inetsw[0])] };
E 9
I 9
    { AF_INET, "internet", 0, 0, 0, 
      inetsw, &inetsw[sizeof(inetsw)/sizeof(inetsw[0])] };
E 9

E 2
#if NIMP > 0
I 9
extern	struct domain impdomain;

E 9
I 2
struct protosw impsw[] = {
E 2
D 9
{ SOCK_RAW,	PF_IMPLINK,	0,		PR_ATOMIC|PR_ADDR,
E 9
I 9
{ SOCK_RAW,	&impdomain,	0,		PR_ATOMIC|PR_ADDR,
E 9
  0,		rimp_output,	0,		0,
  raw_usrreq,
  0,		0,		hostslowtimo,	0,
D 2
}
#endif
E 2
I 2
},
E 2
};

D 2
struct domain inetdomain =
    { AF_INET, "internet", inetsw, &inetsw[sizeof(inetsw)/sizeof(inetsw[0])] };
E 2
I 2
struct domain impdomain =
D 9
    { AF_IMPLINK, "imp", impsw, &impsw[sizeof (impsw)/sizeof(impsw[0])] };
E 9
I 9
    { AF_IMPLINK, "imp", 0, 0, 0,
      impsw, &impsw[sizeof (impsw)/sizeof(impsw[0])] };
E 9
#endif
I 13

#include "hy.h"
#if NHY > 0
/*
 * HYPERchannel protocol family: raw interface.
 */
int	rhy_output();
I 15
extern	struct domain hydomain;
E 15

struct protosw hysw[] = {
D 15
{ SOCK_RAW,	PF_HYLINK,	0,		PR_ATOMIC|PR_ADDR,
E 15
I 15
{ SOCK_RAW,	&hydomain,	0,		PR_ATOMIC|PR_ADDR,
E 15
  0,		rhy_output,	0,		0,
  raw_usrreq,
  0,		0,		0,		0,
},
};

struct domain hydomain =
D 18
    { AF_HYLINK, "hy", hysw, &hysw[sizeof (hysw)/sizeof(hysw[0])] };
E 18
I 18
    { AF_HYLINK, "hy", 0, 0, 0, hysw, &hysw[sizeof (hysw)/sizeof(hysw[0])] };
E 18
#endif
E 13
E 2
E 1
