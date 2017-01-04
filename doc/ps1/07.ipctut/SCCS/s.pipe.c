h59980
s 00008/00004/00039
d D 6.2 86/05/08 14:37:33 karels 2 1
c corrections and additions
e
s 00043/00000/00000
d D 6.1 86/05/04 16:34:07 mckusick 1 0
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
#include <stdio.h>

#define DATA "Bright star, would I were steadfast as thou art . . ."

/*
 * This program creates a pipe, then forks.  The child communicates to the
 * parent over the pipe. Notice that a pipe is a one-way communications
 * device.  I can write to the output socket (sockets[1], the second socket
 * of the array returned by pipe()) and read from the input socket
 * (sockets[0]), but not vice versa. 
 */

main()
{
D 2
	int             sockets[2], child;
E 2
I 2
	int sockets[2], child;
E 2

	/* Create a pipe */
D 2
	if (pipe(sockets) < 0)
E 2
I 2
	if (pipe(sockets) < 0) {
E 2
		perror("opening stream socket pair");
I 2
		exit(10);
	}
E 2

D 2
	if (child = fork()) {
		char            buf[1024];
E 2
I 2
	if ((child = fork()) == -1)
		perror("fork");
	else if (child) {
		char buf[1024];
E 2

		/* This is still the parent.  It reads the child's message. */
		close(sockets[1]);
		if (read(sockets[0], buf, 1024) < 0)
			perror("reading message");
		printf("-->%s\en", buf);
		close(sockets[0]);
	} else {
		/* This is the child.  It writes a message to its parent. */
		close(sockets[0]);
		if (write(sockets[1], DATA, sizeof(DATA)) < 0)
			perror("writing message");
		close(sockets[1]);
	}
}
E 1
