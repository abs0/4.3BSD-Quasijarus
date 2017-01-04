h49019
s 00001/00001/00144
d D 1.4 2013/01/06 07:04:03 msokolov 4 3
c MSDNS => FalconDNS
e
s 00014/00001/00131
d D 1.3 2011/12/07 23:14:24 msokolov 3 2
c fixed 'fromlen' bug in udpout.c
c created udpout-debug apparatus in the process of chasing after that bug
e
s 00048/00001/00084
d D 1.2 2011/11/01 23:29:02 msokolov 2 1
c setup_udpout() implemented
e
s 00085/00000/00000
d D 1.1 2011/11/01 21:59:23 msokolov 1 0
c started
e
u
U
t
T
I 1
/*
D 4
 * Michael Sokolov's Domain Name Server (MSDNS)
E 4
I 4
 * FalconDNS daemon by Michael Spacefalcon
E 4
 *
 * Outbound UDP service
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
I 2
#include <stdio.h>
E 2
#include <syslog.h>
#include "udpout.h"
#include "globals.h"
#include "selectloop.h"

D 2
extern char *malloc(), *myalloc();
E 2
I 2
extern char *myalloc();
E 2
extern u_long random();

static int *sockets;
static struct udpout **slot_array;

#define	COLLISION_LOOP_LIMIT	100

struct udpout *
alloc_udpout_struct()
{
	register struct udpout *uo, **slot;
	int modulo;
	register int retry, idx;

	modulo = num_outbound_udp_sockets * 65536;
	for (retry = 0; ; ) {
		idx = random() % modulo;
		slot = slot_array + idx;
		if (!*slot)
			break;
		if (++retry >= COLLISION_LOOP_LIMIT) {
			syslog(LOG_ALERT, "udpout: too many collisions");
			return(0);
		}
	}
	uo = (struct udpout *)myalloc(sizeof(struct udpout));
	if (!uo)
		return(uo);
	*slot = uo;
	uo->uo_slotptr = slot;
	uo->uo_socket = sockets[idx >> 16];
	*(u_short *)uo->uo_query = idx;
I 3
	if (udpout_debug)
		syslog(LOG_DEBUG, "udpout-debug: allocated idx %d", idx);
E 3
	uo->uo_recv = 0;
	return(uo);
}

free_udpout_struct(uo)
	register struct udpout *uo;
{
	*uo->uo_slotptr = 0;
	free(uo);
}

void
udpout_recv_handler(sockptr)
	int *sockptr;
{
	register int idx, msglen;
	struct sockaddr_in from;
	u_char msg[PACKETSZ];
	int fromlen;
	register struct udpout *uo;

I 3
	fromlen = sizeof(struct sockaddr_in);
E 3
	msglen = recvfrom(*sockptr, msg, PACKETSZ, 0, &from, &fromlen);
I 3
	if (udpout_debug)
		syslog(LOG_DEBUG, "udpout-debug: recvfrom returned %d", msglen);
E 3
	/* Error or no header? ignore it if so */
	if (msglen < sizeof(HEADER))
		return;
	idx = (sockptr - sockets) * 65536 + *(u_short *)msg;
I 3
	if (udpout_debug)
		syslog(LOG_DEBUG, "udpout-debug: got idx %d", idx);
E 3
	uo = slot_array[idx];
D 3
	if (!uo)
E 3
I 3
	if (!uo) {
		if (udpout_debug)
			syslog(LOG_DEBUG,
				"udpout-debug: no struct at this idx");
E 3
		return;
I 3
	}
E 3
	if (uo->uo_recv)
		uo->uo_recv(uo, msg, msglen, &from);
I 3
	else if (udpout_debug)
		syslog(LOG_DEBUG, "udpout-debug: no recv func installed");
E 3
I 2
}

void
setup_udpout(num)
{
	struct sockaddr_in addr;
	static int one = 1;
	register int i, s;

	if (num_outbound_udp_sockets) {
		fprintf(stderr,
			"msdns.conf: duplicate outbound-sockets line\n");
		exit(1);
	}
	sockets = (int *) myalloc(sizeof(int) * num);
	slot_array = (struct udpout **)
			myalloc(sizeof(struct udpout *) * num * 65536);
	if (!sockets || !slot_array) {
		perror("unable to allocate memory for outbound-sockets");
		exit(1);
	}
	bzero(slot_array, sizeof(struct udpout *) * num * 65536);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 0;
	for (i = 0; i < num; i++) {
		s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (s < 0) {
			syslog(LOG_CRIT, "creating udpout socket: %m");
			perror("udpout socket");
			exit(1);
		}
		sockets[i] = s;
		if (bind(s, &addr, sizeof addr) < 0) {
			syslog(LOG_ERR, "bind udpout socket: %m");
			perror("bind udpout socket");
			exit(1);
		}
		ioctl(s, FIONBIO, &one);
		select_desc[s].sel_read = udpout_recv_handler;
		select_desc[s].sel_opaque = (caddr_t)&sockets[i];
		FD_SET(s, &select_for_read);
		if (s > select_max_fd)
			select_max_fd = s;
	}
	num_outbound_udp_sockets = num;
E 2
}
E 1
