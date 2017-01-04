h38117
s 00019/00019/00090
d D 5.3 86/03/29 07:37:15 lepreau 4 3
c Minor speedups & cleanups:
c replace letter() et al with ctype-like cmap macros and expand cmap to short
c for new LET and DIG bits; use bzero in private calloc; make btell a macro.
e
s 00003/00003/00106
d D 5.2 85/06/06 13:09:15 edward 3 2
c cleaning up after bozos
e
s 00008/00002/00101
d D 5.1 85/06/04 10:55:24 dist 2 1
c Add copyright
e
s 00103/00000/00000
d D 4.1 84/12/13 16:26:23 edward 1 0
c date and time created 84/12/13 16:26:23 by edward
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
E 3
I 3
 * All rights reserved.  The Berkeley Software License Agreement
E 3
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
#ifndef lint
D 2
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 2
I 2
D 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3
I 3
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 3
E 2

#include "sh.char.h"

D 4
char _cmap[256] = {
E 4
I 4
unsigned short _cmap[256] = {
E 4
/*	nul		soh		stx		etx	*/
	0,		0,		0,		0,

/*	eot		enq		ack		bel	*/
	0,		0,		0,		0,

/*	bs		ht		nl		vt	*/
	0,		_SP|_META,	_NL|_META,	0,

/*	np		cr		so		si	*/
	0,		0,		0,		0,

/*	dle		dc1		dc2		dc3	*/
	0,		0,		0,		0,

/*	dc4		nak		syn		etb	*/
	0,		0,		0,		0,

/*	can		em		sub		esc	*/
	0,		0,		0,		0,

/*	fs		gs		rs		us	*/
	0,		0,		0,		0,

/*	sp		!		"		#	*/
	_SP|_META,	0,		_Q,		_META,

/*	$		%		&		'	*/
	_DOL,		0,		_META,		_Q,

/*	(		)		*		+	*/
	_META,		_META,		_GLOB,		0,

/*	,		-		.		/	*/
	0,		0,		0,		0,

/*	0		1		2		3	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_DIG,		_DIG,		_DIG,		_DIG,
E 4

/*	4		5		6		7	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_DIG,		_DIG,		_DIG,		_DIG,
E 4

/*	8		9		:		;	*/
D 4
	0,		0,		0,		_META,
E 4
I 4
	_DIG,		_DIG,		0,		_META,
E 4

/*	<		=		>		?	*/
	_META,		0,		_META,		_GLOB,

/*	@		A		B		C	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	0,		_LET,		_LET,		_LET,
E 4

/*	D		E		F		G	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	H		I		J		K	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	L		M		N		O	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	P		Q		R		S	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	T		U		V		W	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	X		Y		Z		[	*/
D 4
	0,		0,		0,		_GLOB,
E 4
I 4
	_LET,		_LET,		_LET,		_GLOB,
E 4

/*	\		]		^		_	*/
D 4
	_ESC,		0,		0,		0,
E 4
I 4
	_ESC,		0,		0,		_LET,
E 4

/*	`		a		b		c	*/
D 4
	_Q1|_GLOB,	0,		0,		0,
E 4
I 4
	_Q1|_GLOB,	_LET,		_LET,		_LET,
E 4

/*	d		e		f		g	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	h		i		j		k	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	l		m		n		o	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	p		q		r		s	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	t		u		v		w	*/
D 4
	0,		0,		0,		0,
E 4
I 4
	_LET,		_LET,		_LET,		_LET,
E 4

/*	x		y		z		{	*/
D 4
	0,		0,		0,		_GLOB,
E 4
I 4
	_LET,		_LET,		_LET,		_GLOB,
E 4

/*	|		}		~		del	*/
	_META,		0,		0,		0,
};
E 1
