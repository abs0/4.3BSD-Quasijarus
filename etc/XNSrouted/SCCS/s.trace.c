h10038
s 00002/00002/00283
d D 5.7 87/10/22 11:26:50 bostic 9 8
c ANSI C; sprintf now returns an int.
e
s 00018/00004/00267
d D 5.6 86/02/14 19:21:06 sklower 8 6
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00021/00004/00267
d R 5.6 86/02/14 18:28:43 sklower 7 6
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00005/00001/00266
d D 5.5 85/09/17 21:42:14 sklower 6 5
c latest changes from nesheim@cornell:
c use syslog instead of perror, ignore remote requests unless specifically asked,
c handle requests from net 0.
e
s 00012/00002/00255
d D 5.4 85/08/16 22:12:52 sklower 5 3
c forgot to actually add sccs keyword lines.
e
s 00012/00002/00255
d R 5.4 85/08/16 22:11:53 sklower 4 3
c fprg
e
s 00000/00000/00257
d D 5.3 85/08/16 21:49:29 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00014/00014/00243
d D 5.2 85/08/16 20:44:18 sklower 2 1
c status as of 4.3 alpha tape
e
s 00257/00000/00000
d D 5.1 85/08/16 20:39:57 sklower 1 0
c date and time created 85/08/16 20:39:57 by sklower
e
u
U
t
T
I 5
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * Includes material written at Cornell University by Bill Nesheim,
 * by permission of the author.
 */


E 5
I 1
#ifndef lint
D 5
static char sccsid[] = "@(#)trace.c	4.6 (Berkeley) 4/9/84";
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

/*
 * Routing Table Management Daemon
 */
#define	RIPCMDS
#include "defs.h"

#define	NRECORDS	50		/* size of circular trace buffer */
#ifdef DEBUG
FILE	*ftrace = stdout;
int	tracing = 1;
I 6
#else DEBUG
FILE	*ftrace = NULL;
int	tracing = 0;
E 6
#endif

char *xns_ntoa();

traceinit(ifp)
	register struct interface *ifp;
{

	if (iftraceinit(ifp, &ifp->int_input) &&
	    iftraceinit(ifp, &ifp->int_output))
		return;
	tracing = 0;
D 6
	fprintf(stderr, "traceinit: can't init %s\n", ifp->int_name);
E 6
I 6
	syslog(LOG_ERR, "traceinit: can't init %s\n", ifp->int_name);
E 6
}

static
iftraceinit(ifp, ifd)
	struct interface *ifp;
	register struct ifdebug *ifd;
{
	register struct iftrace *t;

	ifd->ifd_records =
	  (struct iftrace *)malloc(NRECORDS * sizeof (struct iftrace));
	if (ifd->ifd_records == 0)
		return (0);
	ifd->ifd_front = ifd->ifd_records;
	ifd->ifd_count = 0;
	for (t = ifd->ifd_records; t < ifd->ifd_records + NRECORDS; t++) {
		t->ift_size = 0;
		t->ift_packet = 0;
	}
	ifd->ifd_if = ifp;
	return (1);
}

traceon(file)
	char *file;
{

	if (ftrace != NULL)
		return;
	ftrace = fopen(file, "a");
	if (ftrace == NULL)
		return;
	dup2(fileno(ftrace), 1);
	dup2(fileno(ftrace), 2);
	tracing = 1;
}

traceoff()
{
	if (!tracing)
		return;
	if (ftrace != NULL)
		fclose(ftrace);
	ftrace = NULL;
	tracing = 0;
}

trace(ifd, who, p, len, m)
	register struct ifdebug *ifd;
	struct sockaddr *who;
	char *p;
	int len, m;
{
	register struct iftrace *t;

	if (ifd->ifd_records == 0)
		return;
	t = ifd->ifd_front++;
	if (ifd->ifd_front >= ifd->ifd_records + NRECORDS)
		ifd->ifd_front = ifd->ifd_records;
	if (ifd->ifd_count < NRECORDS)
		ifd->ifd_count++;
	if (t->ift_size > 0 && t->ift_packet)
		free(t->ift_packet);
	t->ift_packet = 0;
	t->ift_stamp = time(0);
	t->ift_who = *who;
	if (len > 0) {
		t->ift_packet = malloc(len);
		if (t->ift_packet)
			bcopy(p, t->ift_packet, len);
		else
			len = 0;
	}
	t->ift_size = len;
	t->ift_metric = m;
}

traceaction(fd, action, rt)
	FILE *fd;
	char *action;
	struct rt_entry *rt;
{
D 2
	struct sockaddr_xn *dst, *gate;
E 2
I 2
	struct sockaddr_ns *dst, *gate;
E 2
	static struct bits {
		int	t_bits;
		char	*t_name;
	} flagbits[] = {
		{ RTF_UP,	"UP" },
		{ RTF_GATEWAY,	"GATEWAY" },
		{ RTF_HOST,	"HOST" },
		{ 0 }
	}, statebits[] = {
		{ RTS_PASSIVE,	"PASSIVE" },
		{ RTS_REMOTE,	"REMOTE" },
		{ RTS_INTERFACE,"INTERFACE" },
		{ RTS_CHANGED,	"CHANGED" },
		{ 0 }
	};
	register struct bits *p;
	register int first;
	char *cp;
	struct interface *ifp;

	if (fd == NULL)
		return;
	fprintf(fd, "%s ", action);
D 2
	dst = (struct sockaddr_xn *)&rt->rt_dst;
	gate = (struct sockaddr_xn *)&rt->rt_router;
	fprintf(fd, "dst %s, ", xns_ntoa(&dst->sxn_addr));
E 2
I 2
	dst = (struct sockaddr_ns *)&rt->rt_dst;
	gate = (struct sockaddr_ns *)&rt->rt_router;
	fprintf(fd, "dst %s, ", xns_ntoa(&dst->sns_addr));
E 2
	fprintf(fd, "router %s, metric %d, flags",
D 2
	     xns_ntoa(&gate->sxn_addr), rt->rt_metric);
E 2
I 2
	     xns_ntoa(&gate->sns_addr), rt->rt_metric);
E 2
	cp = " %s";
	for (first = 1, p = flagbits; p->t_bits > 0; p++) {
		if ((rt->rt_flags & p->t_bits) == 0)
			continue;
		fprintf(fd, cp, p->t_name);
		if (first) {
			cp = "|%s";
			first = 0;
		}
	}
	fprintf(fd, " state");
	cp = " %s";
	for (first = 1, p = statebits; p->t_bits > 0; p++) {
		if ((rt->rt_state & p->t_bits) == 0)
			continue;
		fprintf(fd, cp, p->t_name);
		if (first) {
			cp = "|%s";
			first = 0;
		}
	}
	putc('\n', fd);
	if (!tracepackets && (rt->rt_state & RTS_PASSIVE) == 0 && rt->rt_ifp)
		dumpif(fd, rt->rt_ifp);
	fflush(fd);
}

dumpif(fd, ifp)
	register struct interface *ifp;
I 6
	FILE *fd;
E 6
{
	if (ifp->int_input.ifd_count || ifp->int_output.ifd_count) {
		fprintf(fd, "*** Packet history for interface %s ***\n",
			ifp->int_name);
		dumptrace(fd, "to", &ifp->int_output);
		dumptrace(fd, "from", &ifp->int_input);
		fprintf(fd, "*** end packet history ***\n");
	}
}

dumptrace(fd, dir, ifd)
	FILE *fd;
	char *dir;
	register struct ifdebug *ifd;
{
	register struct iftrace *t;
	char *cp = !strcmp(dir, "to") ? "Output" : "Input";

	if (ifd->ifd_front == ifd->ifd_records &&
	    ifd->ifd_front->ift_size == 0) {
		fprintf(fd, "%s: no packets.\n", cp);
		return;
	}
	fprintf(fd, "%s trace:\n", cp);
	t = ifd->ifd_front - ifd->ifd_count;
	if (t < ifd->ifd_records)
		t += NRECORDS;
	for ( ; ifd->ifd_count; ifd->ifd_count--, t++) {
		if (t >= ifd->ifd_records + NRECORDS)
			t = ifd->ifd_records;
		if (t->ift_size == 0)
			continue;
		fprintf(fd, "%.24s: metric=%d\n", ctime(&t->ift_stamp),
			t->ift_metric);
		dumppacket(fd, dir, &t->ift_who, t->ift_packet, t->ift_size);
	}
}

dumppacket(fd, dir, who, cp, size)
	FILE *fd;
D 2
	struct sockaddr_xn *who;		/* should be sockaddr */
E 2
I 2
	struct sockaddr_ns *who;		/* should be sockaddr */
E 2
	char *dir, *cp;
	register int size;
{
	register struct rip *msg = (struct rip *)cp;
	register struct netinfo *n;
I 8
	char *xns_nettoa();
E 8

	if (msg->rip_cmd && ntohs(msg->rip_cmd) < RIPCMD_MAX)
		fprintf(fd, "%s %s %s#%x", ripcmds[ntohs(msg->rip_cmd)],
D 2
		    dir, xns_ntoa(&who->sxn_addr), ntohs(who->sxn_addr.xn_socket));
E 2
I 2
		    dir, xns_ntoa(&who->sns_addr), ntohs(who->sns_addr.x_port));
E 2
	else {
		fprintf(fd, "Bad cmd 0x%x %s %s#%x\n", ntohs(msg->rip_cmd),
D 2
		    dir, xns_ntoa(&who->sxn_addr), ntohs(who->sxn_addr.xn_socket));
E 2
I 2
		    dir, xns_ntoa(&who->sns_addr), ntohs(who->sns_addr.x_port));
E 2
		fprintf(fd, "size=%d cp=%x packet=%x\n", size, cp, packet);
		return;
	}
	switch (ntohs(msg->rip_cmd)) {

	case RIPCMD_REQUEST:
	case RIPCMD_RESPONSE:
		fprintf(fd, ":\n");
		size -= sizeof (u_short);
		n = msg->rip_nets;
		for (; size > 0; n++, size -= sizeof (struct netinfo)) {
			if (size < sizeof (struct netinfo))
				break;
D 8
			fprintf(fd, "\tnet %#x metric %d\n",
D 2
			     ntohl(xnnet(n->rip_dst)),
E 2
I 2
			     ntohl(xnnet(n->rip_dst[0])),
E 8
I 8
			fprintf(fd, "\tnet %s metric %d\n",
			     xns_nettoa(n->rip_dst),
E 8
E 2
			     ntohs(n->rip_metric));
		}
		break;

	}
}

I 8
union ns_net_u net;

E 8
char *
I 8
xns_nettoa(val)
union ns_net val;
{
	static char buf[100];
	net.net_e = val;
D 9
	sprintf(buf, "%lx", ntohl(net.long_e));
E 9
I 9
	(void)sprintf(buf, "%lx", ntohl(net.long_e));
E 9
	return (buf);
}


char *
E 8
xns_ntoa(addr)
D 2
struct xn_addr *addr;
E 2
I 2
struct ns_addr *addr;
E 2
{
    static char buf[100];

D 8
    sprintf(buf, "%x#%x:%x:%x:%x:%x:%x",
D 2
	ntohl(xnnet(addr->xn_net)),
	addr->xn_host[0], addr->xn_host[1], 
	addr->xn_host[2], addr->xn_host[3], 
	addr->xn_host[4], addr->xn_host[5]);
E 2
I 2
	ntohl(xnnet(addr->x_net)),
E 8
I 8
D 9
    sprintf(buf, "%s#%x:%x:%x:%x:%x:%x",
E 9
I 9
    (void)sprintf(buf, "%s#%x:%x:%x:%x:%x:%x",
E 9
	xns_nettoa(addr->x_net),
E 8
	addr->x_host.c_host[0], addr->x_host.c_host[1], 
	addr->x_host.c_host[2], addr->x_host.c_host[3], 
	addr->x_host.c_host[4], addr->x_host.c_host[5]);
E 2
	
    return(buf);
}
E 1
