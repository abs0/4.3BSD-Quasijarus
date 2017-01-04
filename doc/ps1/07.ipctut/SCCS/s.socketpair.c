h10198
s 00009/00004/00041
d D 6.2 86/05/08 14:37:36 karels 2 1
c corrections and additions
e
s 00045/00000/00000
d D 6.1 86/05/04 16:34:10 mckusick 1 0
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
#include <stdio.h>

#define DATA1 "In Xanadu, did Kublai Khan . . ."
#define DATA2 "A stately pleasure dome decree . . ."

/*
 * This program creates a pair of connected sockets then forks and
 * communicates over them.  This is very similar to communication with pipes,
 * however, socketpairs are two-way communications objects. Therefore I can
 * send messages in both directions. 
 */

main()
{
D 2
	int             sockets[2], child;
	char            buf[1024];
E 2
I 2
	int sockets[2], child;
	char buf[1024];
E 2

D 2
	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0)
E 2
I 2
	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
E 2
		perror("opening stream socket pair");
D 2
	if (child = fork()) {	/* This is the parent. */
E 2
I 2
		exit(1);
	}

	if ((child = fork()) == -1)
		perror("fork");
	else if (child) {	/* This is the parent. */
E 2
		close(sockets[0]);
		if (read(sockets[1], buf, 1024, 0) < 0)
			perror("reading stream message");
		printf("-->%s\en", buf);
		if (write(sockets[1], DATA2, sizeof(DATA2)) < 0)
			perror("writing stream message");
		close(sockets[1]);
	} else {		/* This is the child. */
		close(sockets[1]);
		if (write(sockets[0], DATA1, sizeof(DATA1)) < 0)
			perror("writing stream message");
		if (read(sockets[0], buf, 1024, 0) < 0)
			perror("reading stream message");
		printf("-->%s\en", buf);
		close(sockets[0]);
	}
}
E 1
