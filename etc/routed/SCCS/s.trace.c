h64120
s 00010/00005/00316
d D 5.7 88/06/18 13:56:45 bostic 13 12
c install approved copyright notice
e
s 00010/00002/00311
d D 5.6 88/05/31 14:16:40 karels 12 11
c close off fd's 1,2 when turning off tracing (so file gets closed)
e
s 00057/00016/00256
d D 5.5 88/05/31 11:52:08 karels 11 10
c add ability to trace changes only, with timestamp; even up output fields
e
s 00009/00003/00263
d D 5.4 88/02/16 18:51:04 bostic 10 9
c add Berkeley specific headers
e
s 00007/00000/00259
d D 5.3 86/05/30 13:56:33 karels 9 8
c don't send net route to subnet gw's unless on subnet 0;
c a few checks for imposters; bug fix in "external" route configuration;
c rm loopback net defn.
e
s 00011/00006/00248
d D 5.2 86/03/28 15:20:00 karels 8 7
c touchups
e
s 00007/00001/00247
d D 5.1 85/06/04 16:38:22 dist 7 6
c Add copyright
e
s 00016/00015/00232
d D 4.6 84/04/09 15:05:48 karels 6 5
c many cleanups; avoid interface timing out; put it back asap
e
s 00001/00001/00246
d D 4.5 84/03/07 21:56:33 karels 5 4
c more consistency checks; watch those unsigned moduli
e
s 00010/00008/00237
d D 4.4 83/09/25 19:25:14 sam 4 3
c cleanup some of the printout's (it's still unreadable)
e
s 00001/00001/00244
d D 4.3 83/05/25 17:51:21 sam 3 2
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00001/00001/00244
d D 4.2 83/01/11 14:38:47 sam 2 1
c 4.1c conversion contortions
e
s 00245/00000/00000
d D 4.1 82/11/02 22:28:11 sam 1 0
c date and time created 82/11/02 22:28:11 by sam
e
u
U
t
T
I 7
/*
D 11
 * Copyright (c) 1983 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 11
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 10
 */

E 7
I 1
#ifndef lint
D 3
static char sccsid[] = "%W% %G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 7
#endif
E 7
I 7
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 7

/*
 * Routing Table Management Daemon
 */
#define	RIPCMDS
D 2
#include "router.h"
E 2
I 2
#include "defs.h"
I 12
#include <sys/file.h>
E 12
I 9
#include <sys/stat.h>
I 11
#include <sys/signal.h>
E 11
E 9
E 2

#define	NRECORDS	50		/* size of circular trace buffer */
#ifdef DEBUG
FILE	*ftrace = stdout;
D 11
int	tracing = 1;
E 11
I 11
int	traceactions = 1;
E 11
#endif

traceinit(ifp)
	register struct interface *ifp;
{

	if (iftraceinit(ifp, &ifp->int_input) &&
	    iftraceinit(ifp, &ifp->int_output))
		return;
D 11
	tracing = 0;
E 11
I 11
	tracehistory = 0;
E 11
	fprintf(stderr, "traceinit: can't init %s\n", ifp->int_name);
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
I 6
	ifd->ifd_count = 0;
E 6
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
I 9
	struct stat stbuf;
E 9

	if (ftrace != NULL)
		return;
I 9
	if (stat(file, &stbuf) >= 0 && (stbuf.st_mode & S_IFMT) != S_IFREG)
		return;
E 9
	ftrace = fopen(file, "a");
	if (ftrace == NULL)
		return;
	dup2(fileno(ftrace), 1);
	dup2(fileno(ftrace), 2);
D 11
	tracing = 1;
E 11
I 11
	traceactions = 1;
E 11
}

traceoff()
{
D 11
	if (!tracing)
E 11
I 11
	if (!traceactions)
E 11
		return;
D 12
	if (ftrace != NULL)
E 12
I 12
	if (ftrace != NULL) {
		int fd = open("/dev/null", O_RDWR);

		fprintf(ftrace, "Tracing disabled\n");
		(void) dup2(fd, 1);
		(void) dup2(fd, 2);
		(void) close(fd);
E 12
		fclose(ftrace);
D 12
	ftrace = NULL;
E 12
I 12
		ftrace = NULL;
	}
E 12
D 11
	tracing = 0;
E 11
I 11
	traceactions = 0;
	tracehistory = 0;
E 11
}

I 11
sigtrace(s)
	int s;
{
	if (s == SIGUSR2) {
		traceoff();
		tracepackets = 0;
	} else if (traceactions == 0)
		traceactions++;
	else if (tracehistory == 0)
		tracehistory++;
	else {
		tracepackets++;
		tracehistory = 0;
	}
}

E 11
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
I 6
	if (ifd->ifd_count < NRECORDS)
		ifd->ifd_count++;
E 6
D 8
	if (t->ift_size > 0 && t->ift_packet)
E 8
I 8
	if (t->ift_size > 0 && t->ift_size < len && t->ift_packet) {
E 8
		free(t->ift_packet);
D 8
	t->ift_packet = 0;
E 8
I 8
		t->ift_packet = 0;
	}
E 8
	t->ift_stamp = time(0);
	t->ift_who = *who;
D 8
	if (len > 0) {
E 8
I 8
	if (len > 0 && t->ift_packet == 0) {
E 8
		t->ift_packet = malloc(len);
D 8
		if (t->ift_packet)
			bcopy(p, t->ift_packet, len);
		else
E 8
I 8
		if (t->ift_packet == 0)
E 8
			len = 0;
	}
I 8
	if (len > 0)
		bcopy(p, t->ift_packet, len);
E 8
	t->ift_size = len;
	t->ift_metric = m;
}

traceaction(fd, action, rt)
	FILE *fd;
	char *action;
	struct rt_entry *rt;
{
	struct sockaddr_in *dst, *gate;
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
I 9
		{ RTS_INTERNAL,	"INTERNAL" },
		{ RTS_EXTERNAL,	"EXTERNAL" },
		{ RTS_SUBNET,	"SUBNET" },
E 9
		{ 0 }
	};
	register struct bits *p;
	register int first;
	char *cp;
	struct interface *ifp;

	if (fd == NULL)
		return;
I 11
	if (curtime) {
		fprintf(fd, "\n%s", curtime);
		curtime = NULL;
	}
E 11
	fprintf(fd, "%s ", action);
	dst = (struct sockaddr_in *)&rt->rt_dst;
	gate = (struct sockaddr_in *)&rt->rt_router;
D 4
	fprintf(fd, "dst %x, router %x, metric %d, flags", dst->sin_addr,
		gate->sin_addr, rt->rt_metric);
E 4
I 4
	fprintf(fd, "dst %s, ", inet_ntoa(dst->sin_addr));
	fprintf(fd, "router %s, metric %d, flags",
	     inet_ntoa(gate->sin_addr), rt->rt_metric);
E 4
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
D 11
	putc('\n', fd);
E 11
I 11
	fprintf(fd, " timer %d\n", rt->rt_timer);
E 11
D 5
	if ((rt->rt_state & RTS_PASSIVE) == 0 && rt->rt_ifp)
E 5
I 5
	if (!tracepackets && (rt->rt_state & RTS_PASSIVE) == 0 && rt->rt_ifp)
E 5
		dumpif(fd, rt->rt_ifp);
	fflush(fd);
}

I 11
tracenewmetric(fd, rt, newmetric)
	FILE *fd;
	struct rt_entry *rt;
	int newmetric;
{
	struct sockaddr_in *dst, *gate;

	if (fd == NULL)
		return;
	dst = (struct sockaddr_in *)&rt->rt_dst;
	gate = (struct sockaddr_in *)&rt->rt_router;
	fprintf(fd, "CHANGE metric dst %s, ", inet_ntoa(dst->sin_addr));
	fprintf(fd, "router %s, from %d to %d\n",
	     inet_ntoa(gate->sin_addr), rt->rt_metric, newmetric);
	fflush(fd);
}

E 11
dumpif(fd, ifp)
	register struct interface *ifp;
{
D 6
	register struct ifdebug *ifd;
	
	fprintf(fd, "*** Packet history for interface %s ***\n",
		ifp->int_name);
	dumptrace(fd, "to", &ifp->int_output);
	dumptrace(fd, "from", &ifp->int_output);
	fprintf(fd, "*** end packet history ***\n");
E 6
I 6
	if (ifp->int_input.ifd_count || ifp->int_output.ifd_count) {
		fprintf(fd, "*** Packet history for interface %s ***\n",
			ifp->int_name);
I 11
#ifdef notneeded
E 11
		dumptrace(fd, "to", &ifp->int_output);
I 11
#endif
E 11
		dumptrace(fd, "from", &ifp->int_input);
		fprintf(fd, "*** end packet history ***\n");
	}
I 8
	fflush(fd);
E 8
E 6
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
I 8
		fflush(fd);
E 8
		return;
	}
	fprintf(fd, "%s trace:\n", cp);
D 6
	for (t = ifd->ifd_front; t <= ifd->ifd_records + NRECORDS; t++) {
		if (t->ift_size == 0)
			continue;
		fprintf(fd, "%.24s: metric=%d\n", ctime(&t->ift_stamp),
			t->ift_metric);
		dumppacket(fd, dir, &t->ift_who, t->ift_packet, t->ift_size);
	}
	for (t = ifd->ifd_records; t < ifd->ifd_front; t++) {
E 6
I 6
	t = ifd->ifd_front - ifd->ifd_count;
	if (t < ifd->ifd_records)
		t += NRECORDS;
	for ( ; ifd->ifd_count; ifd->ifd_count--, t++) {
		if (t >= ifd->ifd_records + NRECORDS)
			t = ifd->ifd_records;
E 6
		if (t->ift_size == 0)
			continue;
D 11
		fprintf(fd, "%.24s: metric=%d\n", ctime(&t->ift_stamp),
			t->ift_metric);
		dumppacket(fd, dir, &t->ift_who, t->ift_packet, t->ift_size);
E 11
I 11
		dumppacket(fd, dir, &t->ift_who, t->ift_packet, t->ift_size,
		    &t->ift_stamp);
E 11
	}
}

D 11
dumppacket(fd, dir, who, cp, size)
E 11
I 11
dumppacket(fd, dir, who, cp, size, tstamp)
E 11
	FILE *fd;
	struct sockaddr_in *who;		/* should be sockaddr */
	char *dir, *cp;
	register int size;
I 11
	time_t *tstamp;
E 11
{
	register struct rip *msg = (struct rip *)cp;
	register struct netinfo *n;

	if (msg->rip_cmd && msg->rip_cmd < RIPCMD_MAX)
D 4
		fprintf(fd, "%s %s %x.%d", ripcmds[msg->rip_cmd],
			dir, who->sin_addr, ntohs(who->sin_port));
E 4
I 4
		fprintf(fd, "%s %s %s.%d", ripcmds[msg->rip_cmd],
		    dir, inet_ntoa(who->sin_addr), ntohs(who->sin_port));
E 4
	else {
D 11
		fprintf(fd, "Bad cmd 0x%x %s %x.%d\n", msg->rip_cmd,
D 4
			dir, who->sin_addr, ntohs(who->sin_port));
E 4
I 4
		    dir, inet_ntoa(who->sin_addr), ntohs(who->sin_port));
E 11
I 11
		fprintf(fd, "Bad cmd 0x%x %s %x.%d %.24s\n", msg->rip_cmd,
		    dir, inet_ntoa(who->sin_addr), ntohs(who->sin_port),
		    ctime(tstamp));
E 11
E 4
		fprintf(fd, "size=%d cp=%x packet=%x\n", size, cp, packet);
I 8
		fflush(fd);
E 8
		return;
	}
I 11
	fprintf(fd, " %.24s:\n", ctime(tstamp));
E 11
	switch (msg->rip_cmd) {

	case RIPCMD_REQUEST:
	case RIPCMD_RESPONSE:
D 11
		fprintf(fd, ":\n");
E 11
		size -= 4 * sizeof (char);
		n = msg->rip_nets;
		for (; size > 0; n++, size -= sizeof (struct netinfo)) {
			if (size < sizeof (struct netinfo))
				break;
D 4
			fprintf(fd, "\tdst %x metric %d\n",
				((struct sockaddr_in *)&n->rip_dst)->sin_addr,
				n->rip_metric);
E 4
I 4
			fprintf(fd, "\tdst %s metric %d\n",
#define	satosin(sa)	((struct sockaddr_in *)&sa)
			     inet_ntoa(satosin(n->rip_dst)->sin_addr),
			     ntohl(n->rip_metric));
E 4
		}
		break;

	case RIPCMD_TRACEON:
D 11
		fprintf(fd, ", file=%*s\n", size, msg->rip_tracefile);
E 11
I 11
		fprintf(fd, "\tfile=%*s\n", size, msg->rip_tracefile);
E 11
		break;

	case RIPCMD_TRACEOFF:
D 11
		fprintf(fd, "\n");
E 11
		break;
	}
I 8
	fflush(fd);
E 8
}
E 1
