h54357
s 00010/00004/00127
d D 5.2 88/03/10 16:28:52 bostic 5 4
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00015/00001/00116
d D 5.1 85/05/30 19:46:36 mckusick 4 3
c Add copyright
e
s 00060/00005/00057
d D 1.3 83/09/06 12:51:42 arnold 3 2
c 
e
s 00001/00000/00061
d D 1.2 83/05/19 12:21:46 arnold 2 1
c add sccs keywords
e
s 00061/00000/00000
d D 1.1 82/08/11 16:36:09 arnold 1 0
c date and time created 82/08/11 16:36:09 by arnold
e
u
U
t
T
I 2
D 4
static char	*sccsid = "%W% (Berkeley) %G%";
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 4
E 2
I 1

#include	<stdio.h>
#include	"deck.h"


CARD		known[ CARDS ];			/* a deck */
CARD		deck[ CARDS ];			/* a deck */
CARD		hand[ 4 ];			/* a hand */

int		knownum;


main( argc, argv )

    int		argc;
    char	*argv[];
{
	register  int		k, l, m;
D 3
	int			i, j, is, n, sum;
E 3
I 3
	int			i, j, is, n, sum, sum2;
E 3
	CARD			ic, jc;
	CARD			d[ CARDS];
I 3
	extern char		expl[];
E 3

	printf( "Assuming cards are same suit\n" );
	if(  argc == 2  )  {
	    is = atoi( *++argv );
	    printf( "Starting at i = %d\n", is );
	}
	makedeck( deck );
I 3
# if 0
E 3
	for( i = is; i < RANKS; i++ )  {		/* first card */
	    ic.rank = i;
	    ic.suit = 0;
	    hand[0] = ic;
	    for( j = 0; j <= i; j++ )  {
D 3
		printf( "%d %d: sum = %d\n", i, j, -10000000 );
E 3
I 3
		printf( "%d %d: sum  = %d\n", i, j, -10000000 );
		printf( "%d %d: sum2 = %d\n", i, j, -10000000 );
E 3
	    }
	    for( j = i + 1; j < RANKS; j++ )  {		/* second card */
		jc.rank = j;
		jc.suit = 0;
		hand[1] = jc;
		for( k = 0; k < CARDS; k++ )  d[k] = deck[k];
		n = CARDS;
		remove( ic, d, n-- );
		remove( jc, d, n-- );
		sum = 0;
I 3
		sum2 = 0;
E 3
		for( k = 0; k < n - 1; k++ )  {			/* 3rd card */
		    hand[2] = d[k];
		    for( l = k + 1; l < n; l++ )  {		/* 4th card */
			hand[3] = d[l];
			for( m = 0; m < n; m++ )  {		/* cut card */
			    if(  m != l  &&  m != k  )
D 3
					    sum += scorehand( hand, d[m], 4 );
E 3
I 3
					    sum += scorehand(hand, d[m], 4, FALSE, FALSE);
					    sum2 += scorehand(hand, d[m], 4, TRUE, FALSE);
E 3
			}
		    }
		}
D 3
		printf( "%d %d: sum = %d\n", i, j, sum );
E 3
I 3
		printf( "%d %d: sum  = %d\n", i, j, sum );
		printf( "%d %d: sum2 = %d\n", i, j, sum2 );
E 3
		fflush( stdout );
	    }
	}
	printf( "\nthe hand scores %d\n", i );
I 3
# else
	hand[0].rank = 0;
	hand[1].rank = 1;
	hand[2].rank = 2;
	hand[3].rank = 3;
	hand[4].rank = 4;
	hand[0].suit = 0;
	hand[1].suit = 0;
	hand[2].suit = 0;
	hand[3].suit = 0;
	hand[4].suit = 0;
	printf("scorehand of hand = %d\n", scorehand(hand, hand[4], CINHAND, FALSE, TRUE));
	printf("\t%s\n", expl);
	hand[0].rank = 0;
	hand[1].rank = 1;
	hand[2].rank = 2;
	hand[3].rank = 3;
	hand[4].rank = 4;
	hand[0].suit = 0;
	hand[1].suit = 0;
	hand[2].suit = 0;
	hand[3].suit = 0;
	hand[4].suit = 0;
	printf("scorehand of crib = %d\n", scorehand(hand, hand[4], CINHAND, TRUE, TRUE));
	printf("\t%s\n", expl);
	hand[0].rank = 0;
	hand[1].rank = 1;
	hand[2].rank = 2;
	hand[3].rank = 3;
	hand[4].rank = 4;
	hand[0].suit = 0;
	hand[1].suit = 0;
	hand[2].suit = 0;
	hand[3].suit = 0;
	hand[4].suit = 1;
	printf("scorehand of hand = %d\n", scorehand(hand, hand[4], CINHAND, FALSE, TRUE));
	printf("\t%s\n", expl);
	hand[0].rank = 0;
	hand[1].rank = 1;
	hand[2].rank = 2;
	hand[3].rank = 3;
	hand[4].rank = 4;
	hand[0].suit = 0;
	hand[1].suit = 0;
	hand[2].suit = 0;
	hand[3].suit = 0;
	hand[4].suit = 1;
	printf("scorehand of crib = %d\n", scorehand(hand, hand[4], CINHAND, TRUE, TRUE));
	printf("\t%s\n", expl);
# endif
E 3
}
D 3

E 3
E 1
