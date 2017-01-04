h10933
s 00001/00001/00017
d D 5.2 85/06/06 13:09:42 edward 4 3
c cleaning up after bozos
e
s 00007/00001/00011
d D 5.1 85/06/04 11:10:32 dist 3 2
c Add copyright
e
s 00001/00001/00011
d D 4.2 84/12/13 14:39:59 edward 2 1
c performance
e
s 00012/00000/00000
d D 4.1 80/10/09 12:40:32 bill 1 0
c date and time created 80/10/09 12:40:32 by bill
e
u
U
t
T
I 1
D 2
/* %M% %I% %G% */
E 2
I 2
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
E 4
I 4
 * All rights reserved.  The Berkeley Software License Agreement
E 4
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
 * Structure for entries in directory stack.
 */
struct	directory	{
	struct	directory *di_next;	/* next in loop */
	struct	directory *di_prev;	/* prev in loop */
	unsigned short *di_count;	/* refcount of processes */
	char	*di_name;		/* actual name */
};
struct directory *dcwd;		/* the one we are in now */
E 1
