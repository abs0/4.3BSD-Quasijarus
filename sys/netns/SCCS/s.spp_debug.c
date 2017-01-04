h12574
s 00011/00006/00141
d D 7.5 88/06/29 17:13:40 bostic 12 11
c install approved copyright notice
e
s 00004/00003/00143
d D 7.4 88/03/12 18:13:13 karels 11 10
c we get our own copy of xxx_timer.h (I don't want to debug TCP and SPP
c simultaneously!)
e
s 00009/00003/00137
d D 7.3 88/01/20 15:15:34 sklower 10 9
c Change licensing/use notice.
e
s 00002/00002/00138
d D 7.2 87/11/05 18:43:30 sklower 9 8
c This incorporates recent tcp strategies of Karels/Jacobson: 
c slow start, clamped rxmt, binary fixed point rtt smoothing.  Works on sun 3.X
e
s 00001/00001/00139
d D 7.1 86/06/05 00:38:28 mckusick 8 7
c 4.3BSD release version
e
s 00002/00002/00138
d D 6.7 86/03/04 19:46:44 sklower 7 6
c Shut Lint Up.
e
s 00001/00001/00139
d D 6.6 86/02/03 17:41:09 sklower 6 5
c Correct erroneous copyright information.
e
s 00001/00001/00139
d D 6.5 85/09/26 10:37:48 karels 5 4
c State as of 4.3 Beta Tape (by sklower).
e
s 00006/00004/00134
d D 6.4 85/08/23 12:37:33 walsh 4 3
c dependent on use of Berk TCP
e
s 00002/00000/00136
d D 6.3 85/08/09 11:34:36 sklower 3 2
c 
e
s 00007/00001/00129
d D 6.2 85/06/08 12:52:10 mckusick 2 1
c Add copyright
e
s 00130/00000/00000
d D 6.1 85/05/30 19:11:11 sklower 1 0
c date and time created 85/05/30 19:11:11 by sklower
e
u
U
t
T
I 1
D 2
/*      %M%     %I%     %E%     */
E 2
I 2
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
D 8
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 8
I 8
D 9
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
E 9
E 8
E 6
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
E 10
 *
D 10
 *	%W% (Berkeley) %G%
E 10
I 10
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
 *
D 12
 *      %W% (Berkeley) %G%
E 12
I 12
 *	%W% (Berkeley) %G%
E 12
E 10
 */
E 2

#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
#include "socketvar.h"
#include "protosw.h"
#include "errno.h"

#include "../net/route.h"
#include "../net/if.h"
#include "../netinet/tcp_fsm.h"
D 11
#include "../netinet/tcp_timer.h"
E 11

#include "ns.h"
#include "ns_pcb.h"
#include "idp.h"
#include "idp_var.h"
#include "sp.h"
#include "spidp.h"
I 11
#define SPPTIMERS
#include "spp_timer.h"
E 11
#include "spp_var.h"
#define	SANAMES
#include "spp_debug.h"

int	sppconsdebug = 0;
D 4
extern char *prurequests[];
extern char *tanames[];
extern char *tcpstates[];
extern char *tcptimers[];
E 4
/*
 * spp debug routines
 */
spp_trace(act, ostate, sp, si, req)
	short act;
	u_char ostate;
	struct sppcb *sp;
	struct spidp *si;
	int req;
{
I 4
D 5
#ifndef BBNNET
E 5
I 5
#ifdef INET
E 5
E 4
	u_short seq, ack, len, alo;
	unsigned long iptime();
	int flags;
	struct spp_debug *sd = &spp_debug[spp_debx++];
I 4
	extern char *prurequests[];
D 7
	extern char *tanames[];
E 7
I 7
	extern char *sanames[];
E 7
	extern char *tcpstates[];
D 11
	extern char *tcptimers[];
E 11
I 11
	extern char *spptimers[];
E 11
E 4

	if (spp_debx == SPP_NDEBUG)
		spp_debx = 0;
	sd->sd_time = iptime();
	sd->sd_act = act;
	sd->sd_ostate = ostate;
	sd->sd_cb = (caddr_t)sp;
	if (sp)
		sd->sd_sp = *sp;
	else
		bzero((caddr_t)&sd->sd_sp, sizeof (*sp));
	if (si)
		sd->sd_si = *si;
	else
		bzero((caddr_t)&sd->sd_si, sizeof (*si));
	sd->sd_req = req;
	if (sppconsdebug == 0)
		return;
	if (ostate >= TCP_NSTATES) ostate = 0;
	if (act >= SA_DROP) act = SA_DROP;
	if (sp)
		printf("%x %s:", sp, tcpstates[ostate]);
	else
		printf("???????? ");
D 7
	printf("%s ", tanames[act]);
E 7
I 7
	printf("%s ", sanames[act]);
E 7
	switch (act) {

	case SA_RESPOND:
	case SA_INPUT:
	case SA_OUTPUT:
	case SA_DROP:
		if (si == 0)
			break;
		seq = si->si_seq;
		ack = si->si_ack;
		alo = si->si_alo;
		len = si->si_len;
		if (act == SA_OUTPUT) {
			seq = ntohs(seq);
			ack = ntohs(ack);
			alo = ntohs(alo);
			len = ntohs(len);
		}
#ifndef lint
#define p1(f)  { printf("%s = %x, ", "f", f); }
		p1(seq); p1(ack); p1(alo); p1(len);
#endif
		flags = si->si_cc;
		if (flags) {
			char *cp = "<";
#ifndef lint
#define pf(f) { if (flags&SP_/**/f) { printf("%s%s", cp, "f"); cp = ","; } }
			pf(SP); pf(SA); pf(OB); pf(EM);
I 3
#else
			cp = cp;
E 3
#endif
			printf(">");
		}
#ifndef lint
#define p2(f)  { printf("%s = %x, ", "f", si->si_/**/f); }
		p2(sid);p2(did);p2(dt);p2(pt);
#endif
		ns_printhost(&si->si_sna);
		ns_printhost(&si->si_dna);

		if (act==SA_RESPOND) {
			printf("idp_len = %x, ",
				((struct idp *)si)->idp_len);
		}
		break;

	case SA_USER:
		printf("%s", prurequests[req&0xff]);
		if ((req & 0xff) == PRU_SLOWTIMO)
D 11
			printf("<%s>", tcptimers[req>>8]);
E 11
I 11
			printf("<%s>", spptimers[req>>8]);
E 11
		break;
	}
	if (sp)
		printf(" -> %s", tcpstates[sp->s_state]);
	/* print out internal state of sp !?! */
	printf("\n");
	if (sp == 0)
		return;
#ifndef lint
#define p3(f)  { printf("%s = %x, ", "f", sp->s_/**/f); }
D 9
	printf("\t"); p3(rack);p3(ralo);p3(snt);p3(flags); printf("\n");
E 9
I 9
	printf("\t"); p3(rack);p3(ralo);p3(smax);p3(flags); printf("\n");
E 9
I 4
#endif
E 4
#endif
}
E 1
