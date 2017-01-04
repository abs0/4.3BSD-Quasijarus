h60798
s 00011/00006/00295
d D 7.6 88/06/29 17:13:18 bostic 16 15
c install approved copyright notice
e
s 00001/00001/00300
d D 7.5 88/02/04 11:51:55 mckusick 15 14
c fix spelling error in name of routine
e
s 00021/00001/00280
d D 7.4 88/01/28 21:00:17 sklower 14 11
c Allow for new error codes to be logged dynamically without overruning tables
e
s 00014/00000/00281
d R 7.4 88/01/28 20:45:52 sklower 13 11
c avoid table overruns logging unknown errors
e
s 00003/00004/00277
d R 7.4 88/01/27 21:55:07 sklower 12 11
c fix bug reported from sun; xerox has introduced more error codes
c that I don't know about!
e
s 00010/00004/00271
d D 7.3 88/01/20 15:15:12 sklower 11 10
c Change licensing/use notice.
e
s 00001/00001/00274
d D 7.2 86/10/28 23:02:51 karels 10 9
c spl6 => splclock
e
s 00001/00001/00274
d D 7.1 86/06/05 00:36:25 mckusick 9 8
c 4.3BSD release version
e
s 00004/00001/00271
d D 6.8 86/06/02 14:48:14 karels 8 7
c lint
e
s 00001/00002/00271
d D 6.7 86/02/23 23:27:46 karels 7 6
c lint
e
s 00001/00001/00272
d D 6.6 86/02/03 17:40:30 sklower 6 5
c Correct erroneous copyright information.
e
s 00007/00007/00266
d D 6.5 85/08/09 11:35:06 sklower 5 4
c 
e
s 00007/00000/00266
d D 6.4 85/07/19 19:01:27 sklower 4 3
c 1.)Don't Generate error packets in response to multicasts.
c 2.) Keep histogram of input error packets.
e
s 00007/00001/00259
d D 6.3 85/06/08 12:49:54 mckusick 3 2
c Add copyright
e
s 00039/00003/00221
d D 6.2 85/06/01 11:47:53 sklower 2 1
c add kernel echo protocol
e
s 00224/00000/00000
d D 6.1 85/05/30 19:10:52 sklower 1 0
c date and time created 85/05/30 19:10:52 by sklower
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
D 9
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 9
I 9
D 11
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 9
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
D 14
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1984, 1988 Regents of the University of California.
E 14
 * All rights reserved.
E 11
 *
D 11
 *	%W% (Berkeley) %G%
E 11
I 11
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
 *
D 16
 *      %W% (Berkeley) %G%
E 16
I 16
 *	%W% (Berkeley) %G%
E 16
E 11
 */
E 3

#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "time.h"
#include "kernel.h"

#include "../net/route.h"

#include "ns.h"
#include "ns_pcb.h"
#include "idp.h"
#include "ns_error.h"

I 5
#ifdef lint
#define NS_ERRPRINTFS 1
#endif

E 5
D 2
#define NS_ERRPRINTFS
E 2
#ifdef NS_ERRPRINTFS
/*
 * NS_ERR routines: error generation, receive packet processing, and
D 2
 * routines to turnaround packets back to the originator, and
 * host table maintenance routines.
E 2
I 2
 * routines to turnaround packets back to the originator.
E 2
 */
int	ns_errprintfs = 0;
#endif
I 14

D 15
ns_error_x(c)
E 15
I 15
ns_err_x(c)
E 15
{
	register u_short *w, *lim, *base = ns_errstat.ns_es_codes;
	u_short x = c;

	/*
	 * zero is a legit error code, handle specially
	 */
	if (x == 0)
		return (0);
	lim = base + NS_ERR_MAX - 1;
	for (w = base + 1; w < lim; w++) {
		if (*w == 0)
			*w = x;
		if (*w == x)
			break;
	}
	return (w - base);
}
E 14

/*
 * Generate an error packet of type error
 * in response to bad packet.
 */

ns_error(om, type, param)
	struct mbuf *om;
	int type;
{
	register struct ns_epidp *ep;
	struct mbuf *m;
	struct idp *nip;
	register struct idp *oip = mtod(om, struct idp *);
	extern int idpcksum;

I 2
	/*
	 * If this packet was sent to the echo port,
	 * and nobody was there, just echo it.
	 * (Yes, this is a wart!)
	 */
	if (type==NS_ERR_NOSOCK &&
	    oip->idp_dna.x_port==htons(2) &&
	    (type = ns_echo(oip)==0))
		return;

E 2
#ifdef NS_ERRPRINTFS
	if (ns_errprintfs)
		printf("ns_err_error(%x, %d, %d)\n", oip, type, param);
#endif
I 4
	/*
	 * Don't Generate error packets in response to multicasts.
	 */
	if (oip->idp_dna.x_host.c_host[0] & 1)
		goto free;

E 4
	ns_errstat.ns_es_error++;
	/*
	 * Make sure that the old IDP packet had 30 bytes of data to return;
	 * if not, don't bother.  Also don't EVER error if the old
	 * packet protocol was NS_ERR.
	 */
	if (oip->idp_len < sizeof(struct idp)) {
		ns_errstat.ns_es_oldshort++;
		goto free;
	}
	if (oip->idp_pt == NSPROTO_ERROR) {
		ns_errstat.ns_es_oldns_err++;
		goto free;
	}

	/*
	 * First, formulate ns_err message
	 */
	m = m_get(M_DONTWAIT, MT_HEADER);
	if (m == NULL)
		goto free;
	m->m_len = sizeof(*ep);
	m->m_off = MMAXOFF - m->m_len;
	ep = mtod(m, struct ns_epidp *);
	if ((u_int)type > NS_ERR_TOO_BIG)
		panic("ns_err_error");
	ns_errstat.ns_es_outhist[ns_err_x(type)]++;
D 5
	ep->ns_ep_errp.ns_err_num = htons(type);
	ep->ns_ep_errp.ns_err_param = htons(param);
E 5
I 5
	ep->ns_ep_errp.ns_err_num = htons((u_short)type);
	ep->ns_ep_errp.ns_err_param = htons((u_short)param);
E 5
	bcopy((caddr_t)oip, (caddr_t)&ep->ns_ep_errp.ns_err_idp, 42);
	nip = &ep->ns_ep_idp;
	nip->idp_len = sizeof(*ep);
	nip->idp_len = htons((u_short)nip->idp_len);
	nip->idp_pt = NSPROTO_ERROR;
	nip->idp_tc = 0;
	nip->idp_dna = oip->idp_sna;
	nip->idp_sna = oip->idp_dna;
	if (idpcksum) {
		nip->idp_sum = 0;
		nip->idp_sum = ns_cksum(dtom(nip), sizeof(*ep));
	} else 
		nip->idp_sum = 0xffff;
D 5
	ns_output(dtom(nip), (struct route *)0, 0);
E 5
I 5
	(void) ns_output(dtom(nip), (struct route *)0, 0);
E 5

free:
	m_freem(dtom(oip));
}
D 5

static struct sockproto ns_errroto = { AF_NS, NSPROTO_ERROR };
static struct sockaddr_ns ns_errsrc = { AF_NS };
static struct sockaddr_ns ns_errdst = { AF_NS };
E 5

ns_printhost(p)
register struct ns_addr *p;
{

	printf("<net:%x%x,host:%x%x%x,port:%x>",
			p->x_net.s_net[0],
			p->x_net.s_net[1],
			p->x_host.s_host[0],
			p->x_host.s_host[1],
			p->x_host.s_host[2],
			p->x_port);

}

/*
 * Process a received NS_ERR message.
 */
ns_err_input(m)
	struct mbuf *m;
{
	register struct ns_errp *ep;
	register struct ns_epidp *epidp = mtod(m, struct ns_epidp *);
	register int i;
	int type, code, param;
D 7
	extern struct ns_addr if_makeaddr();
E 7

	/*
	 * Locate ns_err structure in mbuf, and check
	 * that not corrupted and of at least minimum length.
	 */
#ifdef NS_ERRPRINTFS
	if (ns_errprintfs) {
		printf("ns_err_input from ");
		ns_printhost(&epidp->ns_ep_idp.idp_sna);
		printf("len %d\n", ntohs(epidp->ns_ep_idp.idp_len));
	}
#endif
	i = sizeof (struct ns_epidp);
 	if ((m->m_off > MMAXOFF || m->m_len < i) &&
 		(m = m_pullup(m, i)) == 0)  {
		ns_errstat.ns_es_tooshort++;
		return;
	}
	ep = &(mtod(m, struct ns_epidp *)->ns_ep_errp);
	type = ntohs(ep->ns_err_num);
	param = ntohs(ep->ns_err_param);
I 4
	ns_errstat.ns_es_inhist[ns_err_x(type)]++;
E 4

#ifdef NS_ERRPRINTFS
	/*
	 * Message type specific processing.
	 */
	if (ns_errprintfs)
		printf("ns_err_input, type %d param %d\n", type, param);
#endif
	if (type >= NS_ERR_TOO_BIG) {
		goto badcode;
	}
	ns_errstat.ns_es_outhist[ns_err_x(type)]++;
	switch (type) {

	case NS_ERR_UNREACH_HOST:
		code = PRC_UNREACH_NET;
		goto deliver;

	case NS_ERR_TOO_OLD:
		code = PRC_TIMXCEED_INTRANS;
		goto deliver;

	case NS_ERR_TOO_BIG:
		code = PRC_MSGSIZE;
		goto deliver;

	case NS_ERR_FULLUP:
		code = PRC_QUENCH;
		goto deliver;

	case NS_ERR_NOSOCK:
		code = PRC_UNREACH_PORT;
		goto deliver;

	case NS_ERR_UNSPEC_T:
	case NS_ERR_BADSUM_T:
	case NS_ERR_BADSUM:
	case NS_ERR_UNSPEC:
		code = PRC_PARAMPROB;
		goto deliver;

	deliver:
		/*
		 * Problem with datagram; advise higher level routines.
		 */
#ifdef NS_ERRPRINTFS
		if (ns_errprintfs)
			printf("deliver to protocol %d\n",
				       ep->ns_err_idp.idp_pt);
#endif
		switch(ep->ns_err_idp.idp_pt) {
		case NSPROTO_SPP:
			spp_ctlinput(code, (caddr_t)ep);
			break;

		default:
			idp_ctlinput(code, (caddr_t)ep);
		}
		
		goto free;

	default:
	badcode:
		ns_errstat.ns_es_badcode++;
		goto free;

	}
free:
	m_freem(m);
}
I 2

I 8
#ifdef notdef
E 8
E 2
u_long
nstime()
{
D 10
	int s = spl6();
E 10
I 10
	int s = splclock();
E 10
	u_long t;

	t = (time.tv_sec % (24*60*60)) * 1000 + time.tv_usec / 1000;
	splx(s);
	return (htonl(t));
I 2
}
I 8
#endif
E 8

ns_echo(idp)
register struct idp *idp;
{
	struct mbuf *m = dtom(idp);
	register struct echo {
	    struct idp	ec_idp;
	    u_short		ec_op; /* Operation, 1 = request, 2 = reply */
	} *ec = (struct echo *)idp;
	struct ns_addr temp;

	if (idp->idp_pt!=NSPROTO_ECHO) return(NS_ERR_NOSOCK);
	if (ec->ec_op!=htons(1)) return(NS_ERR_UNSPEC);

	ec->ec_op = htons(2);

	temp = idp->idp_dna;
	idp->idp_dna = idp->idp_sna;
	idp->idp_sna = temp;

	if (idp->idp_sum != 0xffff) {
		idp->idp_sum = 0;
D 8
		idp->idp_sum = ns_cksum(m, (((ntohs(idp->idp_len) - 1)|1)+1));
E 8
I 8
		idp->idp_sum = ns_cksum(m,
		    (int)(((ntohs(idp->idp_len) - 1)|1)+1));
E 8
	}
D 7
	(void) ns_output(m, 0, NS_FORWARDING);
E 7
I 7
	(void) ns_output(m, (struct route *)0, NS_FORWARDING);
E 7
	return(0);
E 2
}
E 1
