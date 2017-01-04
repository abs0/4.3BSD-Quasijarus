h36048
s 00002/00002/00071
d D 6.3 86/03/09 20:40:22 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00015/00010/00058
d D 6.2 86/02/04 22:10:16 sklower 2 1
c print case where host is zero but port is not (as in server local addresses)
e
s 00068/00000/00000
d D 6.1 86/01/29 15:22:19 sklower 1 0
c Routine to convert NS addresses to human readable form
e
u
U
t
T
I 1
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 */

D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3

#include <sys/types.h>
#include <netns/ns.h>

char *
ns_ntoa(addr)
struct ns_addr addr;
{
	static char obuf[40];
	char *spectHex();
D 2
	u_long net;
E 2
I 2
	union { union ns_net net_e; u_long long_e; } net;
E 2
	u_short port = htons(addr.x_port);
	register char *cp;
	char *cp2;
	register u_char *up = addr.x_host.c_host;
	u_char *uplim = up + 6;

D 2
	* (union ns_net *) &net = addr.x_net;
	net = ntohl(net);
	sprintf(obuf, "%lx", net);
E 2
I 2
	net.net_e = addr.x_net;
	sprintf(obuf, "%lx", ntohl(net.long_e));
E 2
	cp = spectHex(obuf);
	cp2 = cp + 1;
	while (*up==0 && up < uplim) up++;
D 2
	if (up == uplim) return (obuf);
	sprintf(cp, ".%x", *up++);
	while (up < uplim) {
		while (*cp) cp++;
		sprintf(cp, "%02x", *up++);
E 2
I 2
	if (up == uplim) {
		if (port) {
			sprintf(cp, ".0");
			cp += 2;
		}
	} else {
		sprintf(cp, ".%x", *up++);
		while (up < uplim) {
			while (*cp) cp++;
			sprintf(cp, "%02x", *up++);
		}
		cp = spectHex(cp2);
E 2
	}
D 2
	cp = spectHex(cp2);
E 2
	if (port) {
		sprintf(cp, ".%x", port);
		spectHex(cp + 1);
	}
	return (obuf);
}

static char *
spectHex(p0)
char *p0;
{
	int ok = 0;
	int nonzero = 0;
	register char *p = p0;
	for (; *p; p++) switch (*p) {

	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
		*p += ('A' - 'a');
		/* fall into . . . */
	case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
		ok = 1;
	case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
		nonzero = 1;
	}
	if (nonzero && !ok) { *p++ = 'H'; *p = 0; }
	return (p);
}
E 1
