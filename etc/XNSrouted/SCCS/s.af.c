h54133
s 00001/00001/00217
d D 5.7 87/12/26 12:09:44 bostic 8 7
c syntax error; fix for ANSI C
e
s 00002/00004/00216
d D 5.6 86/06/05 21:39:27 karels 7 6
c not so noisy
e
s 00011/00006/00209
d D 5.5 86/02/14 19:18:20 sklower 6 4
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00014/00006/00209
d R 5.5 86/02/14 18:27:40 sklower 5 4
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00019/00001/00196
d D 5.4 85/09/17 21:42:01 sklower 4 3
c latest changes from nesheim@cornell:
c use syslog instead of perror, ignore remote requests unless specifically asked,
c handle requests from net 0.
e
s 00022/00005/00175
d D 5.3 85/08/16 21:48:44 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00034/00030/00146
d D 5.2 85/08/16 20:43:31 sklower 2 1
c status as of 4.3 alpha tape
e
s 00176/00000/00000
d D 5.1 85/08/16 20:22:30 sklower 1 0
c date and time created 85/08/16 20:22:30 by sklower
e
u
U
t
T
I 3
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * This file include significant work done at Cornell University
 * by Bill Nesheim.  That work included by permission.
 */

E 3
I 1
#ifndef lint
D 3
static char rcsid[] = "$Header$";
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

I 3

E 3
#include "defs.h"

/*
 * Address family support routines
 */
int	null_hash(), null_netmatch(), null_output(),
	null_portmatch(), null_portcheck(),
	null_checkhost(), null_ishost(), null_canon();
int	xnnet_hash(), xnnet_netmatch(), xnnet_output(),
D 8
	xnnet_portmatch();
E 8
I 8
	xnnet_portmatch(),
E 8
	xnnet_checkhost(), xnnet_ishost(), xnnet_canon();
#define NIL \
	{ null_hash,		null_netmatch,		null_output, \
	  null_portmatch,	null_portcheck,		null_checkhost, \
	  null_ishost,		null_canon }
#define	XNSNET \
	{ xnnet_hash,		xnnet_netmatch,		xnnet_output, \
	  xnnet_portmatch,	xnnet_portmatch,	xnnet_checkhost, \
	  xnnet_ishost,		xnnet_canon }

struct afswitch afswitch[AF_MAX] =
	{ NIL, NIL, NIL, NIL, NIL, NIL, XNSNET, NIL, NIL, NIL, NIL };

D 2
struct sockaddr_xn xnnet_default = { AF_XNS };
E 2
I 2
struct sockaddr_ns xnnet_default = { AF_NS };
E 2

I 6
union ns_net ns_anynet;
union ns_net ns_zeronet;

E 6
D 2
xnnet_hash(sxn, hp)
	register struct sockaddr_xn *sxn;
E 2
I 2
xnnet_hash(sns, hp)
	register struct sockaddr_ns *sns;
E 2
	struct afhash *hp;
{
D 2
	hp->afh_nethash = xnnet(sxn->sxn_addr.xn_net);
	hp->afh_hosthash = *(int *)sxn->sxn_addr.xn_host;
E 2
I 2
	register long hash = 0;
	register u_short *s = sns->sns_addr.x_host.s_host;
D 6
	hp->afh_nethash = xnnet(sns->sns_addr.x_net);
E 6
I 6
	union ns_net_u net;

	net.net_e = sns->sns_addr.x_net;
	hp->afh_nethash = net.long_e;
E 6
	hash = *s++; hash <<= 8; hash += *s++; hash <<= 8; hash += *s;
	hp->afh_hosthash = hash;
E 2
}

xnnet_netmatch(sxn1, sxn2)
D 2
	struct sockaddr_xn *sxn1, *sxn2;
E 2
I 2
	struct sockaddr_ns *sxn1, *sxn2;
E 2
{
D 6

D 2
	return (xnnet(sxn1->sxn_addr.xn_net) == xnnet(sxn2->sxn_addr.xn_net));
E 2
I 2
	return (xnnet(sxn1->sns_addr.x_net) == xnnet(sxn2->sns_addr.x_net));
E 6
I 6
	return (ns_neteq(sxn1->sns_addr, sxn2->sns_addr));
E 6
E 2
}

/*
 * Verify the message is from the right port.
 */
D 2
xnnet_portmatch(sxn)
	register struct sockaddr_xn *sxn;
E 2
I 2
xnnet_portmatch(sns)
	register struct sockaddr_ns *sns;
E 2
{
	
D 2
	return (ntohs(sxn->sxn_addr.xn_socket) == IDPPORT_RIF );
E 2
I 2
	return (ntohs(sns->sns_addr.x_port) == IDPPORT_RIF );
E 2
}


/*
 * xns output routine.
 */
#ifdef DEBUG
int do_output = 0;
#endif
D 2
xnnet_output(s, flags, sxn, size)
	int s, flags;
	struct sockaddr_xn *sxn;
E 2
I 2
xnnet_output(flags, sns, size)
	int flags;
	struct sockaddr_ns *sns;
E 2
	int size;
{
D 2
	struct sockaddr_xn dst;
E 2
I 2
	struct sockaddr_ns dst;
E 2

D 2
	dst = *sxn;
	sxn = &dst;
	if (sxn->sxn_addr.xn_socket == 0)
		sxn->sxn_addr.xn_socket = htons(IDPPORT_RIF);
E 2
I 2
	dst = *sns;
	sns = &dst;
	if (sns->sns_addr.x_port == 0)
		sns->sns_addr.x_port = htons(IDPPORT_RIF);
E 2
#ifdef DEBUG
	if(do_output || ntohs(msg->rip_cmd) == RIPCMD_REQUEST)
#endif	
I 4
	/*
	 * Kludge to allow us to get routes out to machines that
	 * don't know their addresses yet; send to that address on
	 * ALL connected nets
	 */
D 6
	 if (ns_netof(sns->sns_addr) == 0L) {
E 6
I 6
	 if (ns_neteqnn(sns->sns_addr.x_net, ns_zeronet)) {
E 6
	 	extern  struct interface *ifnet;
	 	register struct interface *ifp;
		
		for (ifp = ifnet; ifp; ifp = ifp->int_next) {
D 6
			ns_netof(sns->sns_addr) = 
				ns_netof(((struct sockaddr_ns *)&ifp->int_addr)->sns_addr);
E 6
I 6
			sns->sns_addr.x_net = 
				satons_addr(ifp->int_addr).x_net;
E 6
D 7
			if (sendto(s, msg, size, flags, sns, sizeof (*sns)) < 0)
				syslog(LOG_ERR,"sendto: %m");
E 7
I 7
			(void) sendto(s, msg, size, flags, sns, sizeof (*sns));
E 7
		}
		return;
	}
	
E 4
D 2
	if (sendto(s, msg, size, flags, sxn, sizeof (*sxn)) < 0)
E 2
I 2
D 7
	if (sendto(s, msg, size, flags, sns, sizeof (*sns)) < 0)
E 2
D 4
		perror("sendto");
E 4
I 4
		syslog(LOG_ERR,"sendto: %m");
E 7
I 7
	(void) sendto(s, msg, size, flags, sns, sizeof (*sns));
E 7
E 4
}

/*
D 3
 * Return 1 if the address is believed
 *  -- THIS IS A KLUDGE.
E 3
I 3
 * Return 1 if we want this route.
 * We use this to disallow route net G entries for one for multiple
 * point to point links.
E 3
 */
D 2
xnnet_checkhost(sxn)
	struct sockaddr_xn *sxn;
E 2
I 2
xnnet_checkhost(sns)
	struct sockaddr_ns *sns;
E 2
{
D 3
	return (1);
E 3
I 3
	register struct interface *ifp = if_ifwithnet(sns);
	/*
	 * We want this route if there is no more than one 
	 * point to point interface with this network.
	 */
	if (ifp == 0 || (ifp->int_flags & IFF_POINTOPOINT)==0) return (1);
	return (ifp->int_sq.n == ifp->int_sq.p);
E 3
}

/*
 * Return 1 if the address is
 * for a host, 0 for a network.
 */
D 2
xnnet_ishost(sxn)
	struct sockaddr_xn *sxn;
E 2
I 2
xnnet_ishost(sns)
struct sockaddr_ns *sns;
E 2
{
D 2
	register int i;
E 2
I 2
	register u_short *s = sns->sns_addr.x_host.s_host;
E 2

D 2
	for (i = 0; i < 6; i++)
		if (sxn->sxn_addr.xn_host[i] != 0) return (1);
	return (0);
E 2
I 2
	if ((s[0]==0xffff) && (s[1]==0xffff) && (s[2]==0xffff))
		return (0);
	else
		return (1);
E 2
}

D 2
xnnet_canon(sxn)
	struct sockaddr_xn *sxn;
E 2
I 2
xnnet_canon(sns)
	struct sockaddr_ns *sns;
E 2
{

D 2
	sxn->sxn_addr.xn_socket = 0;
E 2
I 2
	sns->sns_addr.x_port = 0;
E 2
}

/*ARGSUSED*/
null_hash(addr, hp)
	struct sockaddr *addr;
	struct afhash *hp;
{

	hp->afh_nethash = hp->afh_hosthash = 0;
}

/*ARGSUSED*/
null_netmatch(a1, a2)
	struct sockaddr *a1, *a2;
{

	return (0);
}

/*ARGSUSED*/
null_output(s, f, a1, n)
	int s, f;
	struct sockaddr *a1;
	int n;
{

	;
}

/*ARGSUSED*/
null_portmatch(a1)
	struct sockaddr *a1;
{

	return (0);
}

/*ARGSUSED*/
null_portcheck(a1)
	struct sockaddr *a1;
{

	return (0);
}

/*ARGSUSED*/
null_ishost(a1)
	struct sockaddr *a1;
{

	return (0);
}

/*ARGSUSED*/
null_checkhost(a1)
	struct sockaddr *a1;
{

	return (0);
}

/*ARGSUSED*/
null_canon(a1)
	struct sockaddr *a1;
{

	;
}
E 1
