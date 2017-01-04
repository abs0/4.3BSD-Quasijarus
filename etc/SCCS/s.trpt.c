h54480
s 00013/00002/00361
d D 5.5 88/07/01 08:35:28 bostic 18 17
c add Berkeley specific copyright
e
s 00166/00136/00197
d D 5.4 88/03/04 17:10:07 bostic 17 16
c add getopt, handle dead kernels correctly, general lint/cleanup
e
s 00003/00002/00330
d D 5.3 87/09/09 16:52:51 karels 16 15
c tahoe conversion
e
s 00033/00002/00299
d D 5.2 85/09/18 15:01:14 karels 15 14
c add -f to follow a trace as it continues
e
s 00014/00002/00287
d D 5.1 85/06/04 16:47:34 dist 14 13
c Add copyright
e
s 00002/00003/00287
d D 4.12 85/06/03 09:34:46 karels 13 12
c logic error
e
s 00004/00021/00286
d D 4.11 83/10/16 14:43:44 sam 12 11
c use library function -- also eliminates byte swap problem
e
s 00001/00001/00306
d D 4.10 83/07/29 12:19:57 helge 11 10
c changed another %d to %x
e
s 00001/00000/00306
d D 4.9 83/07/20 16:16:49 helge 10 9
c print dropped packets
e
s 00001/00001/00305
d D 4.8 83/07/20 08:44:00 helge 9 8
c display rcv_wnd in hex, not decimal
e
s 00030/00000/00276
d D 4.7 83/01/22 17:55:45 sam 8 7
c -a to show addresses in packets
e
s 00092/00013/00184
d D 4.6 83/01/19 14:52:18 sam 7 6
c I was bored one night, so ...
e
s 00001/00001/00196
d D 4.5 83/01/18 15:02:29 sam 6 4
c show PUSH also
e
s 00001/00001/00196
d R 4.5 83/01/18 15:00:36 sam 5 4
c show PUSH flag also
e
s 00050/00014/00147
d D 4.4 83/01/13 21:17:40 sam 4 3
c add -p option to specify particular tcpcb and cleanup some stuf
e
s 00015/00013/00146
d D 4.3 82/11/14 15:10:07 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00011/00013/00148
d D 4.2 82/10/07 23:54:50 sam 2 1
c handle timers properly
e
s 00161/00000/00000
d D 4.1 82/04/02 10:29:14 wnj 1 0
c date and time created 82/04/02 10:29:14 by wnj
e
u
U
t
T
I 14
/*
D 17
 * Copyright (c) 1983 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 17
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
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
E 18
 */

E 14
I 1
#ifndef lint
D 7
static char sccsid[] = "%W% %E%";
E 7
I 7
D 14
static char sccsid[] = "%W% %G%";
E 7
#endif
E 14
I 14
char copyright[] =
D 17
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 17
I 17
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 17
 All rights reserved.\n";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 14

I 17
#include <machine/pte.h>

E 17
#include <sys/param.h>
I 17
#include <sys/vmmac.h>
E 17
#include <sys/socket.h>
#include <sys/socketvar.h>
#define PRUREQUESTS
#include <sys/protosw.h>
I 17
#include <sys/file.h>
E 17
D 3
#include <net/in.h>
E 3
I 3

E 3
#include <net/route.h>
D 3
#include <net/in_pcb.h>
#include <net/in_systm.h>
E 3
#include <net/if.h>
D 3
#include <net/ip.h>
#include <net/ip_var.h>
#include <net/tcp.h>
E 3
I 3

#include <netinet/in.h>
#include <netinet/in_pcb.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
E 3
#define TCPSTATES
D 3
#include <net/tcp_fsm.h>
#include <net/tcp_seq.h>
E 3
I 3
#include <netinet/tcp_fsm.h>
#include <netinet/tcp_seq.h>
E 3
#define	TCPTIMERS
D 3
#include <net/tcp_timer.h>
#include <net/tcp_var.h>
#include <net/tcpip.h>
E 3
I 3
#include <netinet/tcp_timer.h>
#include <netinet/tcp_var.h>
#include <netinet/tcpip.h>
E 3
#define	TANAMES
D 3
#include <net/tcp_debug.h>
#include <errno.h>
E 3
I 3
#include <netinet/tcp_debug.h>
E 3

I 12
#include <arpa/inet.h>

E 12
I 4
#include <stdio.h>
E 4
I 3
#include <errno.h>
E 3
#include <nlist.h>

D 17
n_time	ntime;
int	sflag;
I 7
int	tflag;
int	jflag;
I 8
int	aflag;
I 15
int	follow;
E 15
E 8
int	numeric();
E 7
struct	nlist nl[] = {
E 17
I 17
struct nlist nl[] = {
#define	N_TCP_DEBUG	0
E 17
	{ "_tcp_debug" },
I 17
#define	N_TCP_DEBX	1
E 17
	{ "_tcp_debx" },
D 17
	0
E 17
I 17
#define	N_SYSMAP	2
	{ "_Sysmap" },
#define	N_SYSSIZE	3
	{ "_Syssize" },
	{ "" },
E 17
};
D 17
struct	tcp_debug tcp_debug[TCP_NDEBUG];
I 7
caddr_t	tcp_pcbs[TCP_NDEBUG];
E 7
int	tcp_debx;
E 17
I 8
D 12
char	*ntoa();
E 12
E 8

I 17
static struct pte	*Sysmap;
static struct tcp_debug	tcp_debug[TCP_NDEBUG];
static caddr_t	tcp_pcbs[TCP_NDEBUG];
static n_time	ntime;
static int	aflag, kflag, memf, follow, sflag, tcp_debx, tflag;

E 17
main(argc, argv)
	int argc;
	char **argv;
{
D 4
	int i;
E 4
I 4
D 7
	int i, mask = 0;
	caddr_t tcpcb = 0;
E 7
I 7
D 17
	int i, mask = 0, npcbs = 0;
E 7
	char *system = "/vmunix", *core = "/dev/kmem";
E 17
I 17
	extern char *optarg;
	extern int optind;
	int ch, i, jflag, npcbs, numeric();
	char *system, *core, *malloc();
	off_t lseek();
E 17
E 4

D 17
	argc--, argv++;
again:
I 8
	if (argc > 0 && !strcmp(*argv, "-a")) {
		aflag++, argc--, argv++;
		goto again;
	}
I 15
	if (argc > 0 && !strcmp(*argv, "-f")) {
		follow++, argc--, argv++;
I 16
		setlinebuf(stdout);
E 16
		goto again;
	}
E 15
E 8
	if (argc > 0 && !strcmp(*argv, "-s")) {
		sflag++, argc--, argv++;
		goto again;
	}
I 7
	if (argc > 0 && !strcmp(*argv, "-t")) {
		tflag++, argc--, argv++;
		goto again;
	}
	if (argc > 0 && !strcmp(*argv, "-j")) {
		jflag++, argc--, argv++;
		goto again;
	}
E 7
D 4
	nlist(argc > 0 ? *argv : "/vmunix", nl);
E 4
I 4
	if (argc > 0 && !strcmp(*argv, "-p")) {
I 7
		argc--, argv++;
E 7
		if (argc < 1) {
			fprintf(stderr, "-p: missing tcpcb address\n");
E 17
I 17
	jflag = npcbs = 0;
	while ((ch = getopt(argc, argv, "afjp:st")) != EOF)
		switch((char)ch) {
		case 'a':
			++aflag;
			break;
		case 'f':
			++follow;
			setlinebuf(stdout);
			break;
		case 'j':
			++jflag;
			break;
		case 'p':
			if (npcbs >= TCP_NDEBUG) {
				fputs("trpt: too many pcb's specified\n",
				    stderr);
				exit(1);
			}
			(void)sscanf(optarg, "%x", (int *)&tcp_pcbs[npcbs++]);
			break;
		case 's':
			++sflag;
			break;
		case 't':
			++tflag;
			break;
		case '?':
		default:
			fputs("usage: trpt [-afjst] [-p hex-address] [system [core]]\n", stderr);
E 17
			exit(1);
		}
I 7
D 17
		if (npcbs >= TCP_NDEBUG) {
			fprintf(stderr, "-p: too many pcb's specified\n");
			exit(1);
		}
		sscanf(*argv, "%x", &tcp_pcbs[npcbs++]);
E 7
		argc--, argv++;
D 7
		sscanf(*argv, "%x", &tcpcb);
		argc--, argv++;
E 7
		goto again;
	}
E 17
I 17
	argc -= optind;
	argv += optind;

	core = "/dev/kmem";
E 17
	if (argc > 0) {
		system = *argv;
		argc--, argv++;
D 17
		mask++;
E 17
I 17
		if (argc > 0) {
			core = *argv;
			argc--, argv++;
			++kflag;
		}
E 17
	}
D 17
	if (argc > 0) {
		core = *argv;
		argc--, argv++;
		mask++;
	}
	(void) nlist(system, nl);
E 4
	if (nl[0].n_value == 0) {
E 17
I 17
	else
		system = "/vmunix";

	if (nlist(system, nl) < 0 || !nl[0].n_value) {
E 17
D 4
		printf("no namelist\n");
E 4
I 4
		fprintf(stderr, "trpt: %s: no namelist\n", system);
E 4
		exit(1);
	}
D 4
	close(0);
	open(argc > 1 ? argv[1] : "/dev/kmem", 0);
	if (argc > 1) {
E 4
I 4
D 17
	(void) close(0);
	if (open(core, 0) < 0) {
		fprintf(stderr, "trpt: "); perror(core);
E 17
I 17
	if ((memf = open(core, O_RDONLY)) < 0) {
		perror(core);
E 17
		exit(2);
	}
D 17
	if (mask) {
E 4
D 16
		nl[0].n_value &= 0x7fffffff;
		nl[1].n_value &= 0x7fffffff;
E 16
I 16
		nl[0].n_value &= ~KERNBASE;
		nl[1].n_value &= ~KERNBASE;
E 17
I 17
	if (kflag) {
		off_t off;

		Sysmap = (struct pte *)
		   malloc((u_int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
		if (!Sysmap) {
			fputs("arp: can't get memory for Sysmap.\n", stderr);
			exit(1);
		}
		off = nl[N_SYSMAP].n_value & ~KERNBASE;
		(void)lseek(memf, off, L_SET);
		(void)read(memf, (char *)Sysmap,
		    (int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
E 17
E 16
	}
D 4
	lseek(0, nl[1].n_value, 0);
	read(0, &tcp_debx, sizeof (tcp_debx));
E 4
I 4
D 17
	(void) lseek(0, nl[1].n_value, 0);
	if (read(0, &tcp_debx, sizeof (tcp_debx)) != sizeof (tcp_debx)) {
		fprintf(stderr, "trpt: "); perror("tcp_debx");
E 17
I 17
	(void)klseek(memf, (off_t)nl[N_TCP_DEBX].n_value, L_SET);
	if (read(memf, (char *)&tcp_debx, sizeof(tcp_debx)) !=
	    sizeof(tcp_debx)) {
		perror("trpt: tcp_debx");
E 17
		exit(3);
	}
E 4
D 13
	printf("tcp_debx=%d\n", tcp_debx);
E 13
D 4
	lseek(0, nl[0].n_value, 0);
	read(0, tcp_debug, sizeof (tcp_debug));
E 4
I 4
D 17
	(void) lseek(0, nl[0].n_value, 0);
	if (read(0, tcp_debug, sizeof (tcp_debug)) != sizeof (tcp_debug)) {
		fprintf(stderr, "trpt: "); perror("tcp_debug");
E 17
I 17
	(void)klseek(memf, (off_t)nl[N_TCP_DEBUG].n_value, L_SET);
	if (read(memf, (char *)tcp_debug, sizeof(tcp_debug)) !=
	    sizeof(tcp_debug)) {
		perror("trpt: tcp_debug");
E 17
		exit(3);
	}
E 4
D 7
	for (i = tcp_debx % TCP_NDEBUG; i < TCP_NDEBUG; i++) {
		struct tcp_debug *td = &tcp_debug[i];
E 7
I 7
	/*
	 * If no control blocks have been specified, figure
	 * out how many distinct one we have and summarize
	 * them in tcp_pcbs for sorting the trace records
	 * below.
	 */
D 17
	if (npcbs == 0) {
E 17
I 17
	if (!npcbs) {
E 17
		for (i = 0; i < TCP_NDEBUG; i++) {
D 17
			register int j;
E 17
			register struct tcp_debug *td = &tcp_debug[i];
I 17
			register int j;
E 17
E 7
D 2
		ntime = td->td_time;
#if vax
		ntime = ntohl(ntime);
#endif
E 2
I 2

I 7
			if (td->td_tcb == 0)
				continue;
			for (j = 0; j < npcbs; j++)
				if (tcp_pcbs[j] == td->td_tcb)
					break;
			if (j >= npcbs)
				tcp_pcbs[npcbs++] = td->td_tcb;
		}
I 17
		if (!npcbs)
			exit(0);
E 17
	}
D 17
	qsort(tcp_pcbs, npcbs, sizeof (caddr_t), numeric);
E 17
I 17
	qsort(tcp_pcbs, npcbs, sizeof(caddr_t), numeric);
E 17
	if (jflag) {
D 17
		char *cp = "";

		for (i = 0; i < npcbs; i++) {
			printf("%s%x", cp, tcp_pcbs[i]);
			cp = ", ";
E 17
I 17
		for (i = 0;;) {
			printf("%x", (int)tcp_pcbs[i]);
			if (++i == npcbs)
				break;
			fputs(", ", stdout);
E 17
		}
D 17
		if (*cp)
			putchar('\n');
		exit(0);
E 17
I 17
		putchar('\n');
E 17
	}
D 17
	for (i = 0; i < npcbs; i++) {
		printf("\n%x:\n", tcp_pcbs[i]);
E 17
I 17
	else for (i = 0; i < npcbs; i++) {
		printf("\n%x:\n", (int)tcp_pcbs[i]);
E 17
		dotrace(tcp_pcbs[i]);
	}
	exit(0);
}

dotrace(tcpcb)
	register caddr_t tcpcb;
{
D 17
	register int i;
E 17
	register struct tcp_debug *td;
I 17
	register int i;
E 17
I 15
	int prev_debx = tcp_debx;
E 15

D 13
	for (i = 0; i < tcp_debx % TCP_NDEBUG; i++) {
E 13
I 13
D 15
	for (i = tcp_debx % TCP_NDEBUG; i < TCP_NDEBUG; i++) {
E 15
I 15
D 17
again:
	if (--tcp_debx < 0)
E 17
I 17
again:	if (--tcp_debx < 0)
E 17
		tcp_debx = TCP_NDEBUG - 1;
	for (i = prev_debx % TCP_NDEBUG; i < TCP_NDEBUG; i++) {
E 15
E 13
		td = &tcp_debug[i];
E 7
I 4
		if (tcpcb && td->td_tcb != tcpcb)
			continue;
E 4
		ntime = ntohl(td->td_time);
E 2
		tcp_trace(td->td_act, td->td_ostate, td->td_tcb, &td->td_cb,
		    &td->td_ti, td->td_req);
I 15
		if (i == tcp_debx)
			goto done;
E 15
	}
D 7
	for (i = 0; i < tcp_debx % TCP_NDEBUG; i++) {
		struct tcp_debug *td = &tcp_debug[i];
D 2
		ntime = td->td_time;
#if vax
		ntime = ntohl(ntime);
#endif
E 2
I 2

E 7
I 7
D 13
	for (i = tcp_debx % TCP_NDEBUG; i < TCP_NDEBUG; i++) {
E 13
I 13
D 15
	for (i = 0; i < tcp_debx % TCP_NDEBUG; i++) {
E 15
I 15
	for (i = 0; i <= tcp_debx % TCP_NDEBUG; i++) {
E 15
E 13
		td = &tcp_debug[i];
E 7
I 4
		if (tcpcb && td->td_tcb != tcpcb)
			continue;
E 4
		ntime = ntohl(td->td_time);
E 2
		tcp_trace(td->td_act, td->td_ostate, td->td_tcb, &td->td_cb,
		    &td->td_ti, td->td_req);
I 15
	}
D 17
done:
	if (follow) {
	    prev_debx = tcp_debx + 1;
	    if (prev_debx >= TCP_NDEBUG)
		prev_debx = 0;
	    do {
		sleep(1);
		(void) lseek(0, nl[1].n_value, 0);
		if (read(0, &tcp_debx, sizeof(tcp_debx)) != sizeof(tcp_debx)) {
			fprintf(stderr, "trpt: "); perror("tcp_debx");
E 17
I 17
done:	if (follow) {
		prev_debx = tcp_debx + 1;
		if (prev_debx >= TCP_NDEBUG)
			prev_debx = 0;
		do {
			sleep(1);
			(void)klseek(memf, (off_t)nl[N_TCP_DEBX].n_value, L_SET);
			if (read(memf, (char *)&tcp_debx, sizeof(tcp_debx)) !=
			    sizeof(tcp_debx)) {
				perror("trpt: tcp_debx");
				exit(3);
			}
		} while (tcp_debx == prev_debx);
		(void)klseek(memf, (off_t)nl[N_TCP_DEBUG].n_value, L_SET);
		if (read(memf, (char *)tcp_debug, sizeof(tcp_debug)) !=
		    sizeof(tcp_debug)) {
			perror("trpt: tcp_debug");
E 17
			exit(3);
		}
D 17
	    } while (tcp_debx == prev_debx);
	    (void) lseek(0, nl[0].n_value, 0);
	    if (read(0, tcp_debug, sizeof(tcp_debug)) != sizeof(tcp_debug)) {
		    fprintf(stderr, "trpt: "); perror("tcp_debug");
		    exit(3);
	    }
	    goto again;
E 17
I 17
		goto again;
E 17
E 15
	}
D 7
	exit(0);
E 7
}

/*
 * Tcp debug routines
 */
I 17
/*ARGSUSED*/
E 17
tcp_trace(act, ostate, atp, tp, ti, req)
	short act, ostate;
	struct tcpcb *atp, *tp;
	struct tcpiphdr *ti;
	int req;
{
	tcp_seq seq, ack;
D 2
	int len, flags, win;
E 2
I 2
D 17
	int len, flags, win, timer;
E 2
	char *cp;
E 17
I 17
	int flags, len, win, timer;
E 17

D 17
	ptime(ntime);
D 7
	printf("%x %s:%s ", ((int)atp)&0xfffff,
	    tcpstates[ostate], tanames[act]);
E 7
I 7
	printf("%s:%s ", tcpstates[ostate], tanames[act]);
E 17
I 17
	printf("%03ld %s:%s ",(ntime/10) % 1000, tcpstates[ostate],
	    tanames[act]);
E 17
E 7
	switch (act) {
D 17

E 17
	case TA_INPUT:
	case TA_OUTPUT:
I 10
	case TA_DROP:
E 10
I 8
D 17
		if (aflag) {
D 12
			printf("(src=%s,%d, ", ntoa(ti->ti_src),
E 12
I 12
			printf("(src=%s,%d, ", inet_ntoa(ti->ti_src),
E 12
				ntohs(ti->ti_sport));
D 12
			printf("dst=%s,%d)", ntoa(ti->ti_dst),
E 12
I 12
			printf("dst=%s,%d)", inet_ntoa(ti->ti_dst),
E 12
				ntohs(ti->ti_dport));
		}
E 17
I 17
		if (aflag)
			printf("(src=%s,%u, dst=%s,%u)", inet_ntoa(ti->ti_src),
			    ntohs(ti->ti_sport), inet_ntoa(ti->ti_dst),
			    ntohs(ti->ti_dport));
E 17
E 8
		seq = ti->ti_seq;
		ack = ti->ti_ack;
		len = ti->ti_len;
		win = ti->ti_win;
D 2
#if vax
E 2
I 2
D 4
#if vax || pdp11
E 4
E 2
		if (act == TA_OUTPUT) {
			seq = ntohl(seq);
			ack = ntohl(ack);
			len = ntohs(len);
			win = ntohs(win);
		}
D 4
#endif
E 4
		if (act == TA_OUTPUT)
D 17
			len -= sizeof (struct tcphdr);
E 17
I 17
			len -= sizeof(struct tcphdr);
E 17
		if (len)
D 17
			printf("[%x..%x)", seq, seq+len);
E 17
I 17
			printf("[%lx..%lx)", seq, seq + len);
E 17
		else
D 17
			printf("%x", seq);
		printf("@%x", ack);
E 17
I 17
			printf("%lx", seq);
		printf("@%lx", ack);
E 17
		if (win)
D 11
			printf("(win=%d)", win);
E 11
I 11
			printf("(win=%x)", win);
E 11
		flags = ti->ti_flags;
		if (flags) {
D 17
			char *cp = "<";
#define pf(f) { if (ti->ti_flags&TH_/**/f) { printf("%s%s", cp, "f"); cp = ","; } }
D 6
			pf(SYN); pf(ACK); pf(FIN); pf(RST); pf(URG);
E 6
I 6
			pf(SYN); pf(ACK); pf(FIN); pf(RST); pf(PUSH); pf(URG);
E 17
I 17
			register char *cp = "<";
#define	pf(flag) { \
	if (ti->ti_flags&flag) \
		printf("%s%s", cp, "f"); \
		cp = ","; \
	}
			pf(TH_SYN);
			pf(TH_ACK);
			pf(TH_FIN);
			pf(TH_RST);
			pf(TH_PUSH);
			pf(TH_URG);
E 17
E 6
			printf(">");
		}
		break;
D 17

E 17
	case TA_USER:
D 2
		printf("%s", prurequests[req&0xff]);
		if (req >> 8)
			printf("<%s>", tcptimers[req>>8]);
E 2
I 2
		timer = req >> 8;
		req &= 0xff;
		printf("%s", prurequests[req]);
		if (req == PRU_SLOWTIMO || req == PRU_FASTTIMO)
			printf("<%s>", tcptimers[timer]);
E 2
		break;
	}
	printf(" -> %s", tcpstates[tp->t_state]);
	/* print out internal state of tp !?! */
	printf("\n");
	if (sflag) {
D 9
		printf("\trcv_nxt %x rcv_wnd %d snd_una %x snd_nxt %x snd_max %x\n",
E 9
I 9
D 17
		printf("\trcv_nxt %x rcv_wnd %x snd_una %x snd_nxt %x snd_max %x\n",
E 17
I 17
		printf("\trcv_nxt %lx rcv_wnd %x snd_una %lx snd_nxt %lx snd_max %lx\n",
E 17
E 9
D 4
		    tp->rcv_nxt, tp->rcv_wnd, tp->snd_una, tp->snd_nxt, tp->snd_max);
		printf("\tsnd_wl1 %x snd_wl2 %x snd_wnd %x\n", tp->snd_wl1, tp->snd_wl2, tp->snd_wnd);
E 4
I 4
		    tp->rcv_nxt, tp->rcv_wnd, tp->snd_una, tp->snd_nxt,
		    tp->snd_max);
D 17
		printf("\tsnd_wl1 %x snd_wl2 %x snd_wnd %x\n", tp->snd_wl1,
E 17
I 17
		printf("\tsnd_wl1 %lx snd_wl2 %lx snd_wnd %x\n", tp->snd_wl1,
E 17
		    tp->snd_wl2, tp->snd_wnd);
E 4
	}
I 7
	/* print out timers? */
	if (tflag) {
D 17
		char *cp = "\t";
E 17
I 17
		register char *cp = "\t";
E 17
		register int i;

		for (i = 0; i < TCPT_NTIMERS; i++) {
			if (tp->t_timer[i] == 0)
				continue;
			printf("%s%s=%d", cp, tcptimers[i], tp->t_timer[i]);
			if (i == TCPT_REXMT)
				printf(" (t_rxtshft=%d)", tp->t_rxtshift);
			cp = ", ";
		}
		if (*cp != '\t')
			putchar('\n');
	}
E 7
}

D 17
ptime(ms)
	int ms;
E 17
I 17
numeric(c1, c2)
	caddr_t *c1, *c2;
E 17
{
D 17

	printf("%03d ", (ms/10) % 1000);
E 17
I 17
	return(*c1 - *c2);
E 17
I 7
}

D 17
numeric(c1, c2)
	caddr_t *c1, *c2;
E 17
I 17
klseek(fd, base, off)
	int fd, off;
	off_t base;
E 17
{
D 17
	
	return (*c1 - *c2);
E 17
I 17
	off_t lseek();

	if (kflag) {	/* get kernel pte */
		base &= ~KERNBASE;
		base = ctob(Sysmap[btop(base)].pg_pfnum) + (base & PGOFSET);
	}
	(void)lseek(fd, base, off);
E 17
I 8
D 12
}

/*
 * Convert network-format internet address
 * to base 256 d.d.d.d representation.
 */
char *
ntoa(in)
	struct in_addr in;
{
	static char b[18];
	register char *p;

	in.s_addr = ntohl(in.s_addr);
	p = (char *)&in;
#define	UC(b)	(((int)b)&0xff)
	sprintf(b, "%d.%d.%d.%d", UC(p[0]), UC(p[1]), UC(p[2]), UC(p[3]));
	return (b);
E 12
E 8
E 7
}
E 1
