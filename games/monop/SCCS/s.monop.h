h16872
s 00011/00006/00110
d D 5.4 88/06/18 14:54:58 bostic 4 3
c install approved copyright notice
e
s 00002/00002/00114
d D 5.3 88/01/02 21:07:32 bostic 3 2
c GCC doesn't replace functional macros if there's no trailing perins;
c PCC does
e
s 00012/00008/00104
d D 5.2 88/01/02 20:59:18 bostic 2 1
c John Gilmore's changes for ANSI C and general cleanup
e
s 00112/00000/00000
d D 5.1 88/01/02 20:53:28 bostic 1 0
c date and time created 88/01/02 20:53:28 by bostic
e
u
U
t
T
I 1
/*
D 4
 * Copyright (c) 1987 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
E 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 4
 *
 *	%W% (Berkeley) %G%
 */

# include	<stdio.h>

# define	reg	register
# define	shrt	char
# define	bool	char
# define	unsgn	unsigned

# define	TRUE	(1)
# define	FALSE	(0)

# define	N_MON	8	/* number of monopolies			*/
# define	N_PROP	22	/* number of normal property squares	*/
# define	N_RR	4	/* number of railroads			*/
# define	N_UTIL	2	/* number of utilities			*/
# define	N_SQRS	40	/* number of squares on board		*/
# define	MAX_PL	9	/* maximum number of players		*/
# define	MAX_PRP	(N_PROP+N_RR+N_UTIL) /* max # ownable property	*/

				/* square type numbers			*/
# define	PRPTY	0	/* normal property			*/
# define	RR	1	/* railroad				*/
# define	UTIL	2	/* water works - electric co		*/
# define	SAFE	3	/* safe spot				*/
# define	CC	4	/* community chest			*/
# define	CHANCE	5	/* chance (surprise!!!)			*/
D 2
# define	SPEC	6	/* special				*/
E 2
I 2
# define	INC_TAX	6	/* Income tax */
# define	GOTO_J	7	/* Go To Jail! */
# define	LUX_TAX	8	/* Luxury tax */
# define	IN_JAIL	9	/* In jail */
E 2

# define	JAIL	40	/* JAIL square number			*/

# define	lucky(str)	printf("%s%s\n",str,lucky_mes[roll(1,num_luck)-1])
# define	printline()	printf("------------------------------\n")
# define	sqnum(sqp)	(sqp - board)
# define	swap(A1,A2)	if ((A1) != (A2)) { \
					(A1) ^= (A2); \
					(A2) ^= (A1); \
					(A1) ^= (A2); \
				}

struct sqr_st {			/* structure for square			*/
	char	*name;			/* place name			*/
	shrt	owner;			/* owner number			*/
	shrt	type;			/* place type			*/
D 2
	char	*desc;			/* description struct		*/
E 2
I 2
	struct prp_st	*desc;		/* description struct		*/
E 2
	int	cost;			/* cost				*/
};

typedef struct sqr_st	SQUARE;

D 3
struct mon_st {			/* monopoly descriptin structure	*/
E 3
I 3
struct mon_st {			/* monopoly description structure	*/
E 3
	char	*name;			/* monop. name (color)		*/
	shrt	owner;			/* owner of monopoly		*/
	shrt	num_in;			/* # in monopoly		*/
	shrt	num_own;		/* # owned (-1: not poss. monop)*/
	shrt	h_cost;			/* price of houses		*/
	char	*not_m;			/* name if not monopoly		*/
	char	*mon_n;			/* name if a monopoly		*/
I 2
D 3
	char	sqnum[3];		/* Square numbers (used to init)*/
E 3
I 3
	char	sqnums[3];		/* Square numbers (used to init)*/
E 3
E 2
	SQUARE	*sq[3];			/* list of squares in monop	*/
};

typedef struct mon_st	MON;

I 2
/*
 * This struct describes a property.  For railroads and utilities, only
 * the "morg" member is used.
 */
E 2
struct prp_st {			/* property description structure	*/
	bool	morg;			/* set if mortgaged		*/
	bool	monop;			/* set if monopoly		*/
	shrt	square;			/* square description		*/
	shrt	houses;			/* number of houses		*/
	MON	*mon_desc;		/* name of color		*/
	int	rent[6];		/* rents			*/
};

struct own_st {			/* element in list owned things		*/
	SQUARE	*sqr;			/* pointer to square		*/
	struct own_st	*next;		/* next in list			*/
};

typedef struct own_st	OWN;

struct plr_st {			/* player description structure		*/
	char	*name;			/* owner name			*/
	shrt	num_gojf;		/* # of get-out-of-jail-free's	*/
	shrt	num_rr;			/* # of railroads owned		*/
	shrt	num_util;		/* # of water works/elec. co.	*/
	shrt	loc;			/* location on board		*/
	shrt	in_jail;		/* count of turns in jail	*/
	int	money;			/* amount of money		*/
	OWN	*own_list;		/* start of propery list	*/
};

D 2
struct rr_st {			/* railroad description structure	*/
	bool	morg;			/* set if morgaged		*/
};

E 2
typedef struct plr_st	PLAY;
typedef struct prp_st	PROP;
D 2
typedef struct rr_st	RR_S;
typedef struct rr_st	UTIL_S;
E 2
I 2
typedef struct prp_st	RR_S;
typedef struct prp_st	UTIL_S;
E 2

int	cc(), chance(), lux_tax(), goto_jail(), inc_tax();
E 1
