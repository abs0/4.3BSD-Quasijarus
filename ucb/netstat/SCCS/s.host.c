h48775
s 00012/00007/00114
d D 5.8 88/06/29 20:41:59 bostic 10 9
c install approved copyright notice
e
s 00007/00005/00114
d D 5.7 88/02/08 11:02:03 karels 9 8
c print in/out totals for impstats
e
s 00009/00003/00110
d D 5.6 88/02/07 20:38:13 karels 8 7
c new copyrights
e
s 00047/00013/00066
d D 5.5 88/02/07 20:25:00 karels 7 6
c new IMP stuff
e
s 00009/00004/00070
d D 5.4 88/02/06 16:31:49 karels 6 5
c new IMP host entries
e
s 00003/00004/00071
d D 5.3 86/08/11 11:50:29 kupfer 5 4
c Some lint.
e
s 00000/00003/00075
d D 5.2 85/09/27 19:23:58 karels 4 3
c remove unused hostent stuff; confuses h_addr
e
s 00008/00002/00070
d D 5.1 85/06/04 15:47:57 dist 3 2
c Add copyright
e
s 00005/00003/00067
d D 4.2 82/11/14 15:11:19 sam 2 1
c convert to 4.1c directory layout
e
s 00070/00000/00000
d D 4.1 82/08/25 22:21:38 sam 1 0
c date and time created 82/08/25 22:21:38 by sam
e
u
U
t
T
I 3
/*
D 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
D 10
 * Copyright (c) 1983,1988 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 8
 */

E 3
I 1
#ifndef lint
D 3
static char sccsid[] = "%W% %E%";
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 3

#include <sys/types.h>
#include <sys/mbuf.h>
I 6
#include <sys/socket.h>
E 6
D 2
#include <net/in.h>
#include <net/if_imp.h>
#include <net/if_imphost.h>
E 2
I 2

I 6
#include <net/if.h>

E 6
#include <netinet/in.h>
#include <netimp/if_imp.h>
#include <netimp/if_imphost.h>

E 2
D 4
#include <netdb.h>

E 4
extern	int kmem;
extern 	int nflag;
extern	char *inetname();

/*
 * Print the host tables associated with the ARPANET IMP.
 * Symbolic addresses are shown unless the nflag is given.
 */
D 7
hostpr(hostsaddr)
	off_t hostsaddr;
E 7
I 7
hostpr(impsoftcaddr, nimpaddr)
	off_t impsoftcaddr, nimpaddr;
E 7
{
	struct mbuf *hosts, mb;
I 7
	struct imp_softc imp_softc;
E 7
	register struct mbuf *m;
	register struct hmbuf *mh;
	register struct host *hp;
D 4
	struct hostent *p;
E 4
	char flagbuf[10], *flags;
I 7
	int i, nimp;
E 7
D 5
	int first = 1;
E 5

D 7
	if (hostsaddr == 0) {
		printf("hosts: symbol not in namelist\n");
E 7
I 7
	if (impsoftcaddr == 0) {
		printf("imp_softc: symbol not in namelist\n");
E 7
		return;
	}
D 7
	klseek(kmem, hostsaddr, 0);
D 5
	read(kmem, &hosts, sizeof (hosts));
E 5
I 5
	read(kmem, (char *)&hosts, sizeof (hosts));
E 5
	m = hosts;
	printf("IMP Host Table\n");
D 6
	printf("%-5.5s %-15.15s %-4.4s %-9.9s %-4.4s %s\n",
		"Flags", "Host", "Qcnt", "Q Address", "RFNM", "Timer");
E 6
I 6
	printf("%-4.4s %-5.5s %-6.6s %-8.8s %-4.4s %-9.9s %-4.4s %s\n", "Unit",
		"Flags", "Host", "Imp", "Qcnt", "Q Address", "RFNM", "Timer");
E 6
	while (m) {
E 7
I 7
	if (nimpaddr == 0) {
		printf("nimp: symbol not in namelist\n");
		return;
	}
	klseek(kmem, nimpaddr, 0);
	read(kmem, (char *)&nimp, sizeof (nimp));
	klseek(kmem, impsoftcaddr, 0);
	for (i = 0; i < nimp; i++) {
	    read(kmem, (char *)&imp_softc, sizeof (imp_softc));
	    m = imp_softc.imp_hosts;
	    printf("IMP%d Host Table\n", i);
	    printf("%-5.5s %-6.6s %-8.8s %-4.4s %-9.9s %-4.4s %s\n", "Flags",
	        "Host", "Imp", "Qcnt", "Q Address", "RFNM", "Timer");
	    while (m) {
E 7
D 5
		klseek(kmem, m, 0);
		read(kmem, &mb, sizeof (mb));
E 5
I 5
		klseek(kmem, (off_t)m, 0);
		read(kmem, (char *)&mb, sizeof (mb));
E 5
		m = &mb;
		mh = mtod(m, struct hmbuf *);
		if (mh->hm_count == 0) {
			m = m->m_next;
			continue;
		}
		for (hp = mh->hm_hosts; hp < mh->hm_hosts + HPMBUF; hp++) {
			if ((hp->h_flags&HF_INUSE) == 0 && hp->h_timer == 0)
				continue;
			flags = flagbuf;
			*flags++ = hp->h_flags&HF_INUSE ? 'A' : 'F';
			if (hp->h_flags&HF_DEAD)
				*flags++ = 'D';
			if (hp->h_flags&HF_UNREACH)
				*flags++ = 'U';
			*flags = '\0';
D 6
			printf("%-5.5s %-15.15s %-4d %-9x %-4d %d\n",
E 6
I 6
D 7
			printf("imp%-1d %-5.5s %-6d %-8d %-4d %-9x %-4d %d\n",
				hp->h_unit,
E 7
I 7
			printf("%-5.5s %-6d %-8d %-4d %-9x %-4d %d\n",
E 7
E 6
				flagbuf,
D 6
				inetname(hp->h_addr),
E 6
I 6
				hp->h_host,
				ntohs(hp->h_imp),
E 6
				hp->h_qcnt,
				hp->h_q,
				hp->h_rfnm,
				hp->h_timer);
		}
		m = m->m_next;
I 7
	    }
	}
}

impstats(impsoftcaddr, nimpaddr)
	off_t impsoftcaddr, nimpaddr;
{
	struct imp_softc imp_softc;
	int i, nimp;
	extern char *plural();

	if (impsoftcaddr == 0 || nimpaddr == 0)
		return;
	klseek(kmem, nimpaddr, 0);
	read(kmem, (char *)&nimp, sizeof (nimp));
	klseek(kmem, impsoftcaddr, 0);
	for (i = 0; i < nimp; i++) {
		read(kmem, (char *)&imp_softc, sizeof (imp_softc));
		printf("imp%d statistics:\n", i);
#define	p(f, m)		printf(m, imp_softc.f, plural(imp_softc.f))
D 9
		printf("\t%d times blocked at least %d sec.\n",
E 9
I 9
		p(imp_if.if_ipackets, "\t%u input message%s\n");
		p(imp_if.if_opackets, "\t%u output message%s\n");
		printf("\t%u times output blocked at least %d sec.\n",
E 9
		    imp_softc.imp_block, IMP_OTIMER);
D 9
		p(imp_incomplete, "\t%d \"incomplete\" message%s\n");
		p(imp_lostrfnm, "\t%d lost RFNM message%s\n");
		p(imp_badrfnm, "\t%d late/bogus RFNM/incomplete message%s\n");
		p(imp_garbage, "\t%d unknown message type%s\n");
E 9
I 9
		p(imp_incomplete, "\t%u \"incomplete\" message%s\n");
		p(imp_lostrfnm, "\t%u lost RFNM message%s\n");
		p(imp_badrfnm, "\t%u late/bogus RFNM/incomplete message%s\n");
		p(imp_garbage, "\t%u unknown message type%s\n");
E 9
E 7
	}
}
E 1
