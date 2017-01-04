h15536
s 00001/00001/00065
d D 5.2 87/10/22 12:14:57 bostic 3 2
c ANSI C; sprintf now returns an int.
e
s 00008/00000/00058
d D 5.1 85/05/30 17:53:24 mckusick 2 1
c Add copyright
e
s 00058/00000/00000
d D 1.1 85/04/05 16:54:56 arnold 1 0
c date and time created 85/04/05 16:54:56 by arnold
e
u
U
t
T
I 1
/*
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

/*
E 2
 * Defines for things used in find.c
 *
 * $Revision: 1.4 $, $Date: 85/03/31 19:20:07 $
 */

/*
 * Don't change the constants, since they are used for sizes in many
 * places in the program.
 */

# define MAXSTR		80	/* maximum length of strings */
# define MAXLINES	32	/* maximum number of screen lines used */
# define MAXCOLS	80	/* maximum number of screen columns used */

# define RN		(((Seed = Seed * 11109 + 13849) >> 16) & 0xffff)
# ifdef CTRL
#	undef	CTRL
# endif	CTRL
# define	CTRL(c)		('c' & 037)

# undef	unctrl		/* Sigh..., why me??? */

/*
 * Now all the global variables
 */

extern bool	Got_ltc, In_shell, Wizard;

extern char	Fruit[], Orig_dsusp, Prbuf[], Whoami[];

extern int	Fd;

extern unsigned int	Numscores;

# ifdef TIOCGLTC
extern struct ltchars	Ltc;
# endif TIOCGLTC

/*
 * Function types
 */

char	*brk(), *charge_str(), *choose_str(), *ctime(), *getenv(),
	*inv_name(), *killname(), *malloc(), *nothing(), *nullstr(),
	*num(), *pick_color(), *ring_num(), *sbrk(), *set_mname(),
D 3
	*sprintf(), *strcat(), *strcpy(), *type_name(), *unctrl(),
E 3
I 3
	*strcat(), *strcpy(), *type_name(), *unctrl(),
E 3
	*vowelstr();

int	auto_save(), come_down(), doctor(), endit(), land(), leave(),
	nohaste(), quit(), rollwand(), runners(), sight(), stomach(),
	swander(), tstp(), turn_see(), unconfuse(), unsee(), visuals();

# ifdef CHECKTIME
int	checkout();
# endif	CHECKTIME

long	lseek(), time();
E 1
