h06785
s 00001/00001/00025
d D 5.2 99/09/14 19:45:59 msokolov 2 1
c fix SCCS ID keywords
e
s 00026/00000/00000
d D 5.1 86/12/09 13:53:42 bostic 1 0
c date and time created 86/12/09 13:53:42 by bostic
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
 */

D 2
/* @(#)strfile.h	1.2 (Berkeley) 5/14/81 */
E 2
I 2
/* %W% (Berkeley) %G% */
E 2

# define	MAXDELIMS	3

/*
 * bits for flag field
 */

# define	STR_RANDOM	0x1
# define	STR_ORDERED	0x2

struct	strfile {		/* information table */
	unsigned int	str_numstr;		/* # of strings in the file */
	unsigned int	str_longlen;		/* length of longest string */
	unsigned int	str_shortlen;		/* length of shortest string */
	long		str_delims[MAXDELIMS];	/* delimiter markings */
	int		str_flags;		/* bit field for flags */
};

typedef struct strfile	STRFILE;
E 1
