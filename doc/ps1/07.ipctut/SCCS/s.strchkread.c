h59685
s 00024/00019/00055
d D 6.2 86/05/08 14:37:38 karels 2 1
c corrections and additions
e
s 00074/00000/00000
d D 6.1 86/05/04 16:34:14 mckusick 1 0
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
I 2
#include <sys/time.h>
E 2
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#define TRUE 1

/*
 * This program uses select() to check that someone is trying to connect
 * before calling accept(). 
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
	int             ready;
	struct timeval  to;
E 2
I 2
	int msgsock;
	char buf[1024];
	int rval;
	fd_set ready;
	struct timeval to;
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
D 2
		ready = 1 << sock;
E 2
I 2
		FD_ZERO(&ready);
		FD_SET(sock, &ready);
E 2
		to.tv_sec = 5;
D 2
		select(20, &ready, 0, 0, &to);
		if (ready) {
			msgsock = accept(sock, 0, 0);
			do {
				for (i = 0; i < 1024; i++)
					buf[i] = '\e0';
E 2
I 2
		if (select(sock + 1, &ready, 0, 0, &to) < 0) {
			perror("select");
			continue;
		}
		if (FD_ISSET(sock, &ready)) {
			msgsock = accept(sock, (struct sockaddr *)0, (int *)0);
			if (msgsock == -1)
				perror("accept");
			else do {
				bzero(buf, sizeof(buf));
E 2
				if ((rval = read(msgsock, buf, 1024)) < 0)
					perror("reading stream message");
D 2
				i = 0;
				if (rval == 0)
E 2
I 2
				else if (rval == 0)
E 2
					printf("Ending connection\en");
				else
					printf("-->%s\en", buf);
D 2
			} while (rval != 0);
E 2
I 2
			} while (rval > 0);
E 2
			close(msgsock);
		} else
			printf("Do something else\en");
	} while (TRUE);
}
E 1
