h30474
s 00019/00015/00014
d D 6.1 86/04/24 00:03:11 mckusick 3 2
c document distributed with 4.3BSD
e
s 00003/00000/00026
d D 5.1 86/04/24 00:02:52 mckusick 2 1
c document distributed with 4.2BSD
e
s 00026/00000/00000
d D 4.1 86/04/24 00:02:02 mckusick 1 0
c document distributed with 4.1BSD
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
I 2
 *
 *	%W% (Berkeley) %G%";
E 2
 */
I 2

E 2
D 3

E 3
# define	WINDOW	struct _win_st

struct _win_st {
D 3
	short	_cury, _curx;
	short	_maxy, _maxx;
	short	_begy, _begx;
	short	_flags;
	bool	_clear;
	bool	_leave;
	bool	_scroll;
	char	**_y;
	short	*_firstch;
	short	*_lastch;
E 3
I 3
	short		_cury, _curx;
	short		_maxy, _maxx;
	short		_begy, _begx;
	short		_flags;
	short		_ch_off;
	bool		_clear;
	bool		_leave;
	bool		_scroll;
	char		**_y;
	short		*_firstch;
	short		*_lastch;
	struct _win_st	*_nextp, *_orig;
E 3
};

D 3
# define	_SUBWIN		01
# define	_ENDLINE	02
# define	_FULLWIN	04
# define	_SCROLLWIN	010
E 3
I 3
# define	_ENDLINE	001
# define	_FULLWIN	002
# define	_SCROLLWIN	004
# define	_FLUSH		010
# define	_FULLLINE	020
# define	_IDLINE		040
E 3
# define	_STANDOUT	0200
I 3
# define	_NOCHANGE	-1
E 3
E 1
