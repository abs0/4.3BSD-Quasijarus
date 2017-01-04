h56922
s 00010/00005/00124
d D 7.3 88/06/29 17:07:15 bostic 16 15
c install approved copyright notice
e
s 00008/00002/00121
d D 7.2 87/12/07 17:46:04 bostic 15 14
c use Berkeley specific header
e
s 00001/00001/00122
d D 7.1 86/06/05 00:29:38 mckusick 14 13
c 4.3BSD release version
e
s 00007/00001/00116
d D 6.3 85/06/08 12:41:49 mckusick 13 12
c Add copyright
e
s 00019/00019/00098
d D 6.2 84/08/29 15:36:58 bloom 12 11
c Include file changes.  No more ../h
e
s 00000/00000/00117
d D 6.1 83/07/29 07:12:07 sam 11 10
c 4.2 distribution
e
s 00008/00004/00109
d D 4.10 83/05/14 15:01:21 sam 10 9
c print more info about dropped packets; show all flags
e
s 00005/00003/00108
d D 4.9 83/02/10 22:11:49 sam 9 8
c remove /usr/include dependencies
e
s 00000/00002/00111
d D 4.8 82/10/30 13:03:40 root 8 7
c get rid of conditional htons/ntohs etc
e
s 00000/00000/00113
d D 4.7 82/10/17 22:47:50 root 7 6
c lint
e
s 00001/00001/00112
d D 4.6 82/10/17 14:55:47 root 6 5
c fix lint
e
s 00012/00012/00101
d D 4.5 82/10/09 05:46:49 wnj 5 4
c localize header files
e
s 00001/00001/00112
d D 4.4 82/06/26 22:02:38 sam 4 3
c use <errno.h>
e
s 00001/00000/00112
d D 4.3 82/03/29 11:33:01 sam 3 2
c first cut (incomplete) at routing
e
s 00003/00002/00109
d D 4.2 82/03/13 12:52:44 sam 2 1
c lint
e
s 00111/00000/00000
d D 4.1 81/12/22 23:44:24 root 1 0
c date and time created 81/12/22 23:44:24 by root
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 15
 *
 *	%W% (Berkeley) %G%
 */
E 13

D 12
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
E 12
I 12
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
#include "socketvar.h"
E 12
#define PRUREQUESTS
D 12
#include "../h/protosw.h"
D 5
#include "../net/in.h"
E 5
I 5
D 9
#include "../netinet/in.h"
E 9
I 9
#include "../h/errno.h"
E 12
I 12
#include "protosw.h"
#include "errno.h"
E 12

E 9
E 5
I 3
#include "../net/route.h"
I 9
#include "../net/if.h"

D 12
#include "../netinet/in.h"
E 9
E 3
D 5
#include "../net/in_pcb.h"
#include "../net/in_systm.h"
E 5
I 5
#include "../netinet/in_pcb.h"
#include "../netinet/in_systm.h"
E 5
D 9
#include "../net/if.h"
E 9
D 5
#include "../net/ip.h"
#include "../net/ip_var.h"
#include "../net/tcp.h"
E 5
I 5
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/tcp.h"
E 12
I 12
#include "in.h"
#include "in_pcb.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
#include "tcp.h"
E 12
E 5
#define TCPSTATES
D 5
#include "../net/tcp_fsm.h"
#include "../net/tcp_seq.h"
E 5
I 5
D 12
#include "../netinet/tcp_fsm.h"
#include "../netinet/tcp_seq.h"
E 12
I 12
#include "tcp_fsm.h"
#include "tcp_seq.h"
E 12
E 5
#define	TCPTIMERS
D 5
#include "../net/tcp_timer.h"
#include "../net/tcp_var.h"
#include "../net/tcpip.h"
E 5
I 5
D 12
#include "../netinet/tcp_timer.h"
#include "../netinet/tcp_var.h"
#include "../netinet/tcpip.h"
E 12
I 12
#include "tcp_timer.h"
#include "tcp_var.h"
#include "tcpip.h"
E 12
E 5
#define	TANAMES
D 5
#include "../net/tcp_debug.h"
E 5
I 5
D 12
#include "../netinet/tcp_debug.h"
E 12
I 12
#include "tcp_debug.h"
E 12
E 5
D 4
#include "../errno.h"
E 4
I 4
D 9
#include <errno.h>
E 9
E 4

int	tcpconsdebug = 0;
/*
 * Tcp debug routines
 */
tcp_trace(act, ostate, tp, ti, req)
	short act, ostate;
	struct tcpcb *tp;
	struct tcpiphdr *ti;
	int req;
{
	tcp_seq seq, ack;
	int len, flags;
D 2
	char *cp;
E 2
	struct tcp_debug *td = &tcp_debug[tcp_debx++];

	if (tcp_debx == TCP_NDEBUG)
		tcp_debx = 0;
	td->td_time = iptime();
	td->td_act = act;
	td->td_ostate = ostate;
	td->td_tcb = (caddr_t)tp;
	if (tp)
		td->td_cb = *tp;
	else
		bzero((caddr_t)&td->td_cb, sizeof (*tp));
	if (ti)
		td->td_ti = *ti;
	else
		bzero((caddr_t)&td->td_ti, sizeof (*ti));
	td->td_req = req;
	if (tcpconsdebug == 0)
		return;
	if (tp)
		printf("%x %s:", tp, tcpstates[ostate]);
	else
		printf("???????? ");
	printf("%s ", tanames[act]);
	switch (act) {

	case TA_INPUT:
	case TA_OUTPUT:
I 10
	case TA_DROP:
		if (ti == 0)
			break;
E 10
		seq = ti->ti_seq;
		ack = ti->ti_ack;
		len = ti->ti_len;
D 6
#if vax
E 6
I 6
D 8
#if vax || pdp11 || ns16032
E 8
E 6
		if (act == TA_OUTPUT) {
			seq = ntohl(seq);
			ack = ntohl(ack);
D 2
			len = ntohs(len);
E 2
I 2
			len = ntohs((u_short)len);
E 2
		}
D 8
#endif
E 8
		if (act == TA_OUTPUT)
			len -= sizeof (struct tcphdr);
		if (len)
			printf("[%x..%x)", seq, seq+len);
		else
			printf("%x", seq);
D 10
		printf("@%x", ack);
E 10
I 10
		printf("@%x, urp=%x", ack, ti->ti_urp);
E 10
		flags = ti->ti_flags;
		if (flags) {
I 2
#ifndef lint
E 2
			char *cp = "<";
#define pf(f) { if (ti->ti_flags&TH_/**/f) { printf("%s%s", cp, "f"); cp = ","; } }
D 10
			pf(SYN); pf(ACK); pf(FIN); pf(RST);
E 10
I 10
			pf(SYN); pf(ACK); pf(FIN); pf(RST); pf(PUSH); pf(URG);
E 10
I 2
#endif
E 2
			printf(">");
		}
		break;

	case TA_USER:
		printf("%s", prurequests[req&0xff]);
		if ((req & 0xff) == PRU_SLOWTIMO)
			printf("<%s>", tcptimers[req>>8]);
		break;
	}
	if (tp)
		printf(" -> %s", tcpstates[tp->t_state]);
	/* print out internal state of tp !?! */
	printf("\n");
	if (tp == 0)
		return;
D 10
	printf("\trcv_(nxt,wnd) (%x,%x) snd_(una,nxt,max) (%x,%x,%x)\n",
	    tp->rcv_nxt, tp->rcv_wnd, tp->snd_una, tp->snd_nxt, tp->snd_max);
E 10
I 10
	printf("\trcv_(nxt,wnd,up) (%x,%x,%x) snd_(una,nxt,max) (%x,%x,%x)\n",
	    tp->rcv_nxt, tp->rcv_wnd, tp->rcv_up, tp->snd_una, tp->snd_nxt,
	    tp->snd_max);
E 10
	printf("\tsnd_(wl1,wl2,wnd) (%x,%x,%x)\n",
	    tp->snd_wl1, tp->snd_wl2, tp->snd_wnd);
}
E 1
