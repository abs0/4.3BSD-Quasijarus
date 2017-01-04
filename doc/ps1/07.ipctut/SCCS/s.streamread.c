h54809
s 00012/00010/00063
d D 6.2 86/05/08 14:37:42 karels 2 1
c corrections and additions
e
s 00073/00000/00000
d D 6.1 86/05/04 16:34:16 mckusick 1 0
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
#define TRUE 1

/*
 * This program creates a socket and then begins an infinite loop. Each time
 * through the loop it accepts a connection and prints out messages from it. 
 * When the connection breaks, or a termination message comes through, the
 * program accepts a new connection. 
 */

main()
{
D 2
	int             sock, length;
E 2
I 2
	int sock, length;
E 2
	struct sockaddr_in server;
D 2
	int             msgsock;
	char            buf[1024];
	int             rval;
	int             i;
E 2
I 2
	int msgsock;
	char buf[1024];
	int rval;
	int i;
E 2

	/* Create socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("opening stream socket");
D 2
		exit(0);
E 2
I 2
		exit(1);
E 2
	}
	/* Name socket using wildcards */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = 0;
	if (bind(sock, &server, sizeof(server))) {
		perror("binding stream socket");
I 2
		exit(1);
E 2
	}
	/* Find out assigned port number and print it out */
	length = sizeof(server);
	if (getsockname(sock, &server, &length)) {
		perror("getting socket name");
D 2
		exit(0);
E 2
I 2
		exit(1);
E 2
	}
	printf("Socket has port #%d\en", ntohs(server.sin_port));

	/* Start accepting connections */
	listen(sock, 5);
	do {
		msgsock = accept(sock, 0, 0);
D 2
		do {
			for (i = 0; i < 1024; i++)
				buf[i] = '\e0';
E 2
I 2
		if (msgsock == -1)
			perror("accept");
		else do {
			bzero(buf, sizeof(buf));
E 2
			if ((rval = read(msgsock, buf, 1024)) < 0)
				perror("reading stream message");
			i = 0;
			if (rval == 0)
				printf("Ending connection\en");
			else
				printf("-->%s\en", buf);
		} while (rval != 0);
		close(msgsock);
	} while (TRUE);
	/*
	 * Since this program has an infinite loop, the socket "sock" is
	 * never explicitly closed.  However, all sockets will be closed
	 * automatically when a process is killed or terminates normally. 
	 */
}
E 1
