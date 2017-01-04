h18283
s 00010/00007/00043
d D 6.2 86/05/08 14:37:31 karels 2 1
c corrections and additions
e
s 00050/00000/00000
d D 6.1 86/05/04 16:34:05 mckusick 1 0
c document distributed with 4.3BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1986 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>

#define DATA "The sea is calm tonight, the tide is full . . ."

/*
 * Here I send a datagram to a receiver whose name I get from the command
 * line arguments.  The form of the command line is dgramsend hostname
 * portnumber 
 */

main(argc, argv)
D 2
	int             argc;
	char           *argv[];
E 2
I 2
	int argc;
	char *argv[];
E 2
{
D 2
	int             sock;
E 2
I 2
	int sock;
E 2
	struct sockaddr_in name;
	struct hostent *hp, *gethostbyname();

	/* Create socket on which to send. */
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("opening datagram socket");
D 2
		exit(-1);
E 2
I 2
		exit(1);
E 2
	}
	/*
	 * Construct name, with no wildcards, of the socket to send to.
	 * Getnostbyname() returns a structure including the network address
	 * of the specified host.  The port number is taken from the command
	 * line. 
	 */
	hp = gethostbyname(argv[1]);
D 2
	bcopy(hp->h_addr, &(name.sin_addr.s_addr), hp->h_length);
E 2
I 2
	if (hp == 0) {
		fprintf(stderr, "%s: unknown host\n", argv[1]);
		exit(2);
	}
	bcopy(hp->h_addr, &name.sin_addr, hp->h_length);
E 2
	name.sin_family = AF_INET;
	name.sin_port = htons(atoi(argv[2]));
	/* Send message. */
D 2
	if (sendto(sock, DATA, sizeof(DATA), 0, &name, sizeof(name)) < 0) {
E 2
I 2
	if (sendto(sock, DATA, sizeof(DATA), 0, &name, sizeof(name)) < 0)
E 2
		perror("sending datagram message");
D 2
	}
E 2
	close(sock);
}
E 1
