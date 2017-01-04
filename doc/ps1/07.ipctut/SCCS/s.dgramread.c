h20498
s 00007/00007/00049
d D 6.3 86/05/08 14:37:27 karels 3 2
c corrections and additions
e
s 00001/00004/00055
d D 6.2 86/05/06 17:08:54 mckusick 2 1
c tighten up code to reduce wasted paper
e
s 00059/00000/00000
d D 6.1 86/05/04 16:34:01 mckusick 1 0
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
#include <stdio.h>

/*
 * In the included file <netinet/in.h> a sockaddr_in is defined as follows:
 * struct sockaddr_in {
 *	short	sin_family;
 *	u_short	sin_port;
 *	struct in_addr sin_addr;
 *	char	sin_zero[8];
 * }; 
D 2
 */

/*
E 2
I 2
 *
E 2
 * This program creates a datagram socket, binds a name to it, then reads
D 3
 * from the socket.  
E 3
I 3
 * from the socket.
E 3
 */
D 2

E 2
main()
{
D 3
	int             sock, length;
E 3
I 3
	int sock, length;
E 3
	struct sockaddr_in name;
D 3
	char            buf[1024];
E 3
I 3
	char buf[1024];
E 3

	/* Create socket from which to read. */
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("opening datagram socket");
D 3
		exit(-1);
E 3
I 3
		exit(1);
E 3
	}
	/* Create name with wildcards. */
	name.sin_family = AF_INET;
	name.sin_addr.s_addr = INADDR_ANY;
	name.sin_port = 0;
	if (bind(sock, &name, sizeof(name))) {
D 3
		close(sock);
E 3
		perror("binding datagram socket");
I 3
		exit(1);
E 3
	}
	/* Find assigned port value and print it out. */
	length = sizeof(name);
	if (getsockname(sock, &name, &length)) {
D 3
		close(sock);
E 3
		perror("getting socket name");
I 3
		exit(1);
E 3
	}
	printf("Socket has port #%d\en", ntohs(name.sin_port));
	/* Read from the socket */
D 3
	if (read(sock, buf, 1024, 0) < 0)
E 3
I 3
	if (read(sock, buf, 1024) < 0)
E 3
		perror("receiving datagram packet");
	printf("-->%s\en", buf);
	close(sock);
}
E 1
