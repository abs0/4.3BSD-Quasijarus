h14782
s 00008/00000/00023
d D 5.3 87/11/18 08:42:11 bostic 5 4
c add S5 routines
e
s 00002/00000/00021
d D 5.2 87/08/03 20:10:15 bostic 4 2
c added strcasecmp, strncasecmp
e
s 00002/00000/00021
d R 5.2 87/07/02 09:20:56 bostic 3 2
c added strcasecmp(), strcasencmp()
e
s 00007/00001/00014
d D 5.1 85/05/30 09:40:45 dist 2 1
c Add copyright
e
s 00015/00000/00000
d D 4.1 83/05/26 10:53:48 sam 1 0
c date and time created 83/05/26 10:53:48 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * External function definitions
 * for routines described in string(3).
 */
char	*strcat();
char	*strncat();
int	strcmp();
int	strncmp();
I 4
int	strcasecmp();
int	strncasecmp();
E 4
char	*strcpy();
char	*strncpy();
int	strlen();
char	*index();
char	*rindex();
I 5

/* S5 compatibility */
char	*strchr();
char	*strrchr();
char	*strpbrk();
int	strspn();
int	strcspn();
char	*strtok();
E 5
E 1
