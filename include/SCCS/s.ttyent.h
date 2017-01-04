h33286
s 00007/00001/00015
d D 5.1 85/05/30 09:41:50 dist 4 3
c Add copyright
e
s 00003/00002/00013
d D 4.2 85/01/30 11:34:20 ralph 3 1
c added support for windows
e
s 00003/00002/00013
d R 4.2 85/01/30 10:10:08 ralph 2 1
c support for window systems
e
s 00015/00000/00000
d D 4.1 84/04/27 10:34:35 ralph 1 0
c date and time created 84/04/27 10:34:35 by ralph
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

struct	ttyent { /* see getttyent(3) */
	char	*ty_name;	/* terminal device name */
D 3
	char	*ty_getty;	/* name for gettytab (5) */
E 3
I 3
	char	*ty_getty;	/* command to execute, usually getty */
E 3
	char	*ty_type;	/* terminal type for termcap (3X) */
	int	ty_status;	/* status flags (see below for defines) */
D 3
	char	*ty_comment;	/* unused - for comments */
E 3
I 3
	char 	*ty_window;	/* command to start up window manager */
	char	*ty_comment;	/* usually the location of the terminal */
E 3
};

#define TTY_ON		0x1	/* enable logins (startup getty) */
#define TTY_SECURE	0x2	/* allow root to login */

extern struct ttyent *getttyent();
extern struct ttyent *getttynam();
E 1
