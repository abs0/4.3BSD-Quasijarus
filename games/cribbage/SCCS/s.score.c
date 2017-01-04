h43367
s 00010/00005/00338
d D 5.4 88/06/18 14:39:34 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00334
d D 5.3 88/03/10 16:31:54 bostic 8 7
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00003/00003/00334
d D 5.2 87/10/22 11:30:07 bostic 7 6
c ANSI C; sprintf now returns an int.
e
s 00009/00002/00328
d D 5.1 85/05/30 19:45:46 mckusick 6 5
c Add copyright
e
s 00003/00002/00327
d D 1.4 83/09/06 12:54:42 arnold 5 4
c make scorehand know what really is a crib and how to deal with flushes
e
s 00001/00000/00328
d D 1.3 83/05/19 12:22:19 arnold 4 3
c add sccs keywords
e
s 00087/00066/00241
d D 1.2 82/08/31 23:01:14 arnold 3 1
c speed up scorehand() and fifteens()
e
s 00244/00217/00090
d R 1.2 82/08/28 17:06:36 arnold 2 1
c reformatting and obvious optimization
e
s 00307/00000/00000
d D 1.1 82/08/11 16:36:02 arnold 1 0
c date and time created 82/08/11 16:36:02 by arnold
e
u
U
t
T
I 5
D 6
#
E 5
I 4
static char *sccsid = "%W% (Berkeley) %G%";
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 6
E 4
I 1

#include	<stdio.h>
#include	"deck.h"
#include	"cribbage.h"


/*
 * the following arrays give the sum of the scores of the (50 2)*48 = 58800
 * hands obtainable for the crib given the two cards whose ranks index the
 * array.  the two arrays are for the case where the suits are equal and
 * not equal respectively
 */

long		crbescr[ 169 ]		= {
    -10000, 271827, 278883, 332319, 347769, 261129, 250653, 253203, 248259,
    243435, 256275, 237435, 231051, -10000, -10000, 412815, 295707, 349497,
    267519, 262521, 259695, 254019, 250047, 262887, 244047, 237663, -10000,
    -10000, -10000, 333987, 388629, 262017, 266787, 262971, 252729, 254475,
    267315, 248475, 242091, -10000, -10000, -10000, -10000, 422097, 302787,
    256437, 263751, 257883, 254271, 267111, 248271, 241887, -10000, -10000,
    -10000, -10000, -10000, 427677, 387837, 349173, 347985, 423861, 436701,
    417861, 411477, -10000, -10000, -10000, -10000, -10000, -10000, 336387,
    298851, 338667, 236487, 249327, 230487, 224103, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000, 408483, 266691, 229803, 246195, 227355,
    220971, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
    300675, 263787, 241695, 226407, 220023, -10000, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000, -10000, 295635, 273543, 219771, 216939,
    -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
    -10000, 306519, 252747, 211431, -10000, -10000, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000, -10000, -10000, 304287, 262971, -10000,
    -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
    -10000, -10000, 244131, -10000, -10000, -10000, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000, -10000, -10000, -10000  };

long		crbnescr[ 169 ]		= {
    325272, 260772, 267828, 321264, 336714, 250074, 239598, 242148, 237204,
    232380, 246348, 226380, 219996, -10000, 342528, 401760, 284652, 338442,
    256464, 251466, 248640, 242964, 238992, 252960, 232992, 226608, -10000,
    -10000, 362280, 322932, 377574, 250962, 255732, 251916, 241674, 243420,
    257388, 237420, 231036, -10000, -10000, -10000, 360768, 411042, 291732,
    245382, 252696, 246828, 243216, 257184, 237216, 230832, -10000, -10000,
    -10000, -10000, 528768, 416622, 376782, 338118, 336930, 412806, 426774,
    406806, 400422, -10000, -10000, -10000, -10000, -10000, 369864, 325332,
    287796, 327612, 225432, 239400, 219432, 213048, -10000, -10000, -10000,
    -10000, -10000, -10000, 359160, 397428, 255636, 218748, 236268, 216300,
    209916, -10000, -10000, -10000, -10000, -10000, -10000, -10000, 331320,
    289620, 252732, 231768, 215352, 208968, -10000, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000, 325152, 284580, 263616, 208716, 205884,
    -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
    321240, 296592, 241692, 200376, -10000, -10000, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000, -10000, 348600, 294360, 253044, -10000,
    -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
    -10000, 308664, 233076, -10000, -10000, -10000, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000, -10000, -10000, 295896  };


static  int		ichoose2[ 5 ]		= { 0, 0, 2, 6, 12 };
static  int		pairpoints, runpoints;	/* globals from pairuns */


/*
D 3
 * scorehand score the given hand of n cards and the starter card
 * n must be <= 4
E 3
I 3
 * scorehand:
 *	Score the given hand of n cards and the starter card.
 *	n must be <= 4
E 3
 */
D 3

scorehand( hand, starter, n, crb )

    CARD		hand[];
    CARD		starter;
    int			n;
    BOOLEAN		crb;			/* true if scoring crib */
E 3
I 3
scorehand(hand, starter, n, crb, do_explain)
register CARD		hand[];
CARD			starter;
int			n;
BOOLEAN			crb;		/* true if scoring crib */
BOOLEAN			do_explain;	/* true if must explain this hand */
E 3
{
D 3
	CARD			h[ (CINHAND + 1) ];
	register  int		i, k;
	int			score;
E 3
I 3
	CARD			h[(CINHAND + 1)];
	register int		i, k;
	register int		score;
E 3
D 5
	BOOLEAN			flag;
E 5
I 5
	register BOOLEAN	flag;
E 5
	char			buf[32];

	expl[0] = NULL;		/* initialize explanation */
	score = 0;
D 3
	flag = TRUE;
E 3
I 3
D 5
	flag = !crb;
E 5
I 5
	flag = TRUE;
E 5
E 3
	k = hand[0].suit;
D 3
	for( i = 0; i < n; i++ )  {			/* check for flush */
	    flag = flag  &&  ( hand[i].suit == k );
	    if(  hand[i].rank == JACK  )  {		/* check for his nibs */
		if(  hand[i].suit == starter.suit  )  {
		    score += 1;
		    strcat( expl, "His Nobs" );
E 3
I 3
	for (i = 0; i < n; i++) {			/* check for flush */
	    flag = (flag && (hand[i].suit == k));
	    if (hand[i].rank == JACK)			/* check for his nibs */
		if (hand[i].suit == starter.suit) {
		    score++;
		    if (do_explain)
			strcat(expl, "His Nobs");
E 3
		}
D 3
	    }
E 3
	    h[i] = hand[i];
	}
D 3
	if(  flag  &&  n >= CINHAND  )  {
	    if(  expl[0] != NULL  )  strcat( expl, ", " );
	    if(  starter.suit == k  )  {
E 3
I 3

	if (flag && n >= CINHAND) {
	    if (do_explain && expl[0] != NULL)
		strcat(expl, ", ");
	    if (starter.suit == k) {
E 3
		score += 5;
D 3
		strcat( expl, "Five-flush" );
E 3
I 3
		if (do_explain)
		    strcat(expl, "Five-flush");
E 3
	    }
D 3
	    else  if( !crb )  {
E 3
I 3
	    else if (!crb) {
E 3
		score += 4;
D 3
		if(  expl[0] != NULL  )  strcat( expl, ", Four-flush" );
		strcat( expl, "Four-flush" );
E 3
I 3
		if (do_explain && expl[0] != NULL)
		    strcat(expl, ", Four-flush");
		else
		    strcpy(expl, "Four-flush");
E 3
	    }
	}
D 3
	if(  expl[0] != NULL  )  strcat( expl, ", " );
	h[ n ] = starter;
	sorthand( h, n + 1 );			/* sort by rank */
	i = 2*fifteens( h, n + 1 );
E 3
I 3

	if (do_explain && expl[0] != NULL)
	    strcat(expl, ", ");
	h[n] = starter;
	sorthand(h, n + 1);			/* sort by rank */
	i = 2 * fifteens(h, n + 1);
E 3
	score += i;
D 3
	if(  i > 0  )  {
	    sprintf( buf, "%d points in fifteens", i );
	    strcat( expl, buf );
	}
	else  {
	    strcat( expl, "No fifteens" );
	}
	i = pairuns( h, n + 1 );
E 3
I 3
	if (do_explain)
	    if (i > 0) {
D 7
		sprintf(buf, "%d points in fifteens", i);
E 7
I 7
		(void)sprintf(buf, "%d points in fifteens", i);
E 7
		strcat(expl, buf);
	    }
	    else
		strcat(expl, "No fifteens");
	i = pairuns(h, n + 1);
E 3
	score += i;
D 3
	if(  i > 0  )  {
	    sprintf( buf, ", %d points in pairs, %d in runs", pairpoints, runpoints );
	    strcat( expl, buf );
	}
	else  {
	    strcat( expl, ", No pairs/runs" );
	}
	return( score );
E 3
I 3
	if (do_explain)
	    if (i > 0) {
D 7
		sprintf(buf, ", %d points in pairs, %d in runs", pairpoints,
		    runpoints);
E 7
I 7
		(void)sprintf(buf, ", %d points in pairs, %d in runs",
			pairpoints, runpoints);
E 7
		strcat(expl, buf);
	    }
	    else
		strcat(expl, ", No pairs/runs");
	return score;
E 3
}

D 3


E 3
/*
D 3
 * return number of fifteens in hand of n cards
E 3
I 3
 * fifteens:
 *	Return number of fifteens in hand of n cards
E 3
 */
D 3

fifteens( hand, n )

    CARD		hand[];
    int			n;
E 3
I 3
fifteens(hand, n)
register CARD		hand[];
int			n;
E 3
{
D 3
	int			sums[ 15 ],  nsums[ 15 ];
	register  int		i, j, k;
E 3
I 3
	register int		*sp, *np;
	register int		i;
	register CARD		*endp;
	static int		sums[15], nsums[15];
E 3

D 3
	for( i = 0; i < 15; i++ )  nsums[i] = sums[i] = 0;
	for( i = 0; i < n; i++ )  {
	    k = hand[i].rank + 1;
	    if( k > 10 )  k = 10;
	    for( j = 1; j + k <= 15; j++ )  {
		nsums[j + k - 1] += sums[j - 1];
E 3
I 3
	np = nsums;
	sp = sums;
	i = 16;
	while (--i) {
	    *np++ = 0;
	    *sp++ = 0;
	}
	for (endp = &hand[n]; hand < endp; hand++) {
	    i = hand->rank + 1;
	    if (i > 10)
		i = 10;
	    np = &nsums[i];
	    np[-1]++;			/* one way to make this */
	    sp = sums;
	    while (i < 15) {
		*np++ += *sp++;
		i++;
E 3
	    }
D 3
	    nsums[ k - 1 ] += 1;		/* one way to make this */
	    for( j = 0; j < 15; j++ )  sums[j] = nsums[j];
E 3
I 3
	    sp = sums;
	    np = nsums;
	    i = 16;
	    while (--i)
		*sp++ = *np++;
E 3
	}
D 3
	return(  sums[14]  );
E 3
I 3
	return sums[14];
E 3
}



/*
 * pairuns returns the number of points in the n card sorted hand
 * due to pairs and runs
 * this routine only works if n is strictly less than 6
 * sets the globals pairpoints and runpoints appropriately
 */

pairuns( h, n )

    CARD		h[];
    int			n;
{
	register  int		i;
	int			runlength, runmult, lastmult, curmult;
	int			mult1, mult2, pair1, pair2;
	BOOLEAN			run;

	run = TRUE;
	runlength = 1;
	mult1 = 1;
	pair1 = -1;
	mult2 = 1;
	pair2 = -1;
	curmult = runmult = 1;
	for( i = 1; i < n; i++ )  {
	    lastmult = curmult;
	    if(  h[i].rank == h[i - 1].rank  )  {
		if(  pair1 < 0  )  {
		    pair1 = h[i].rank;
		    mult1 = curmult = 2;
		}
		else  {
		    if(  h[i].rank == pair1  )  {
			curmult = ++mult1;
		    }
		    else  {
			if(  pair2 < 0  )  {
			    pair2 = h[i].rank;
			    mult2 = curmult = 2;
			}
			else  {
			    curmult = ++mult2;
			}
		    }
		}
		if(  i == (n - 1)  &&  run  )  {
		    runmult *= curmult;
		}
	    }
	    else  {
		curmult = 1;
		if(  h[i].rank == h[i - 1].rank + 1  )  {
		    if( run )  {
			++runlength;
		    }
		    else  {
			if(  runlength < 3  )  {	/* only if old short */
			    run = TRUE;
			    runlength = 2;
			    runmult = 1;
			}
		    }
		    runmult *= lastmult;
		}
		else  {
		    if( run )  runmult *= lastmult;	/* if just ended */
		    run = FALSE;
		}
	    }
	}
	pairpoints = ichoose2[ mult1 ] + ichoose2[ mult2 ];
	runpoints = ( runlength >= 3 ? runlength*runmult : 0 );
	return(  pairpoints + runpoints  );
}



/*
 * pegscore tells how many points crd would get if played after
 * the n cards in tbl during pegging
 */

pegscore( crd, tbl, n, sum )

    CARD		crd,  tbl[];
    int			n;
    int			sum;
{
	BOOLEAN			got[ RANKS ];
	register  int		i, j, scr;
	int			k, lo, hi;

	sum += VAL( crd.rank );
	if(  sum > 31  )  return( -1 );
	if(  sum == 31  ||  sum == 15  )  scr = 2;
	else				  scr = 0;
	if(  !n  )  return( scr );
	j = 1;
	while(  ( crd.rank == tbl[n - j].rank )  &&  ( n - j >= 0 )  )  ++j;
	if( j > 1 )  return( scr + ichoose2[j] );
	if( n < 2 )  return( scr );
	lo = hi = crd.rank;
	for( i = 0; i < RANKS; i++ )  got[i] = FALSE;
	got[ crd.rank ] = TRUE;
	k = -1;
	for( i = n - 1; i >= 0; --i )  {
	    if(  got[ tbl[i].rank ]  )  break;
	    got[ tbl[i].rank ] = TRUE;
	    if(  tbl[i].rank < lo  )  lo = tbl[i].rank;
	    if(  tbl[i].rank > hi  )  hi = tbl[i].rank;
	    for( j = lo; j <= hi; j++ )  if( !got[j] )  break;
	    if(  j > hi )  k = hi - lo + 1;
	}
	if(  k >= 3  )  return( scr + k );
	else		return( scr );
}



/*
 * adjust takes a two card hand that will be put in the crib
 * and returns an adjusted normalized score for the number of
 * points such a crib will get.
 */

adjust( cb, tnv )

    CARD		cb[], tnv;
{
	int			i,  c0,  c1;
	long			scr;

	c0 = cb[0].rank;
	c1 = cb[1].rank;
	if(  c0 > c1  )  {
	    i = c0;
	    c0 = c1;
	    c1 = i;
	}
	if(  cb[0].suit != cb[1].suit  )  scr = crbnescr[ RANKS*c0 + c1 ];
	else				  scr = crbescr[ RANKS*c0 + c1 ];
	if(  scr <= 0  )  {
	    printf( "\nADJUST: internal error %d %d\n",  c0, c1 );
	    exit( 93 );
	}
	return(  (scr + 29400)/58800  );
}



E 1
