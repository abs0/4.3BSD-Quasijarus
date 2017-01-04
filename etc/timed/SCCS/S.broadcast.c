h43704
s 00000/00003/00034
d D 1.4 85/11/16 19:08:04 bloom 4 3
c make sure bytenetorder not called multiple times per packet
e
s 00001/00003/00036
d D 1.3 85/11/16 17:45:03 bloom 3 2
c cleanup the code a bit
e
s 00001/00001/00038
d D 1.2 85/09/18 19:43:17 bloom 2 1
c fix syslog messages
e
s 00039/00000/00000
d D 1.1 85/06/22 22:07:45 gusella 1 0
c date and time created 85/06/22 22:07:45 by gusella
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

#include "globals.h"
#include <protocols/timed.h>

extern int sock;
extern struct sockaddr_in server;

/* 
 * `broadcast' broadcasts the given message on the local network 
 * at the broadcast address set in main.c
 */

broadcast(msg) 
struct tsp *msg;
{
D 3
	int length;
E 3
	extern struct in_addr broadcastaddr;
D 4
	int bytenetorder();
E 4

	msg->tsp_vers = TSPVERSION;
D 4
	bytenetorder(msg);

E 4
	server.sin_addr = broadcastaddr;
D 3
	length = sizeof(struct sockaddr_in);
E 3
	if (sendto(sock, (char *)msg, sizeof(struct tsp), 0, 
D 3
					&server, length) < 0) {
E 3
I 3
	    &server, sizeof(struct sockaddr_in)) < 0) {
E 3
D 2
		syslog(LOG_ERR, "timed: sendto: %m");
E 2
I 2
		syslog(LOG_ERR, "sendto: %m");
E 2
		exit(1);
	}
}
E 1
