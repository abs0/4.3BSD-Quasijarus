h13274
s 00010/00005/00573
d D 5.4 88/06/18 14:39:30 bostic 18 17
c install approved copyright notice
e
s 00009/00003/00569
d D 5.3 88/03/10 16:31:51 bostic 17 16
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00002/00002/00570
d D 5.2 87/10/07 07:49:00 bostic 16 15
c erasechar/killchar already defined in curses.h
e
s 00009/00001/00563
d D 5.1 85/05/30 19:45:14 mckusick 15 14
c Add copyright
e
s 00000/00001/00564
d D 1.13 83/09/26 21:44:43 karels 14 13
c no uncntl.h now
e
s 00015/00000/00550
d D 1.12 83/09/06 12:54:28 arnold 13 12
c make scorehand know what really is a crib and how to deal with flushes
e
s 00002/00000/00548
d D 1.11 83/05/19 12:21:29 arnold 12 11
c add sccs keywords
e
s 00007/00002/00541
d D 1.10 83/05/08 18:47:41 arnold 11 10
c set Mpos properly in endmsg()
e
s 00037/00010/00506
d D 1.9 83/05/07 14:06:50 arnold 10 9
c add a scrolling region
e
s 00036/00027/00480
d D 1.8 83/05/01 15:30:56 arnold 9 8
c make a scrolling region for cribbage
e
s 00001/00001/00506
d D 1.7 83/05/01 13:26:08 arnold 8 7
c swap the board and the cards on the screen
e
s 00006/00004/00501
d D 1.6 82/09/06 14:58:55 arnold 7 5
c show back of computer's hand during play
e
s 00147/00113/00392
d R 1.6 82/08/28 17:06:25 arnold 6 5
c reformatting and obvious optimization
e
s 00001/00001/00504
d D 1.5 82/08/27 23:04:49 arnold 5 4
c simplify infrom() prompt mechanism
e
s 00009/00006/00496
d D 1.4 82/08/27 22:55:16 arnold 4 3
c print blank turnover card to indicate crib
e
s 00032/00034/00470
d D 1.3 82/08/27 14:23:29 arnold 3 2
c make simple <RETURN> not be the same as typing "0"
e
s 00417/00260/00087
d D 1.2 82/08/24 18:34:07 arnold 2 1
c first "working" visual version
e
s 00347/00000/00000
d D 1.1 82/08/11 16:35:59 arnold 1 0
c date and time created 82/08/11 16:35:59 by arnold
e
u
U
t
T
I 12
D 15
static char	*sccsid = "%W% (Berkeley) %G%";
E 15
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 17
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 15

E 12
I 2
# include	<curses.h>
# include	<ctype.h>
I 13
# include	<signal.h>
E 13
D 14
# include	<unctrl.h>
E 14
# include	"deck.h"
# include	"cribbage.h"
I 9
# include	"cribcur.h"
E 9
E 2
I 1

D 2
#include	<stdio.h>
#include	"deck.h"
E 2
I 2
# define	LINESIZE		128
E 2

I 9
# ifdef CTRL
# undef CTRL
# endif
E 9
D 2
#define		LINESIZE		128
E 2
I 2
# define	CTRL(X)			('X' - 'A' + 1)
E 2

I 2
D 16
# ifndef	attron
E 16
I 16
# ifdef	notdef				/* defined in curses.h */
E 16
#	define	erasechar()	_tty.sg_erase
#	define	killchar()	_tty.sg_kill
D 16
# endif		attron
E 16
I 16
# endif
E 16

E 2
char		linebuf[ LINESIZE ];

char		*rankname[ RANKS ]	= { "ACE", "TWO", "THREE", "FOUR",
D 2
				            "FIVE", "SIX", "SEVEN", "EIGHT",
                                            "NINE", "TEN", "JACK", "QUEEN",
                                            "KING" };
E 2
I 2
					    "FIVE", "SIX", "SEVEN", "EIGHT",
					    "NINE", "TEN", "JACK", "QUEEN",
					    "KING" };
E 2

char            *rankchar[ RANKS ]      = { "A", "2", "3", "4", "5", "6", "7",
D 2
                                            "8", "9", "T", "J", "Q", "K" };
E 2
I 2
					    "8", "9", "T", "J", "Q", "K" };
E 2

char            *suitname[ SUITS ]      = { "SPADES", "HEARTS", "DIAMONDS",
D 2
                                            "CLUBS" };
E 2
I 2
					    "CLUBS" };
E 2

char            *suitchar[ SUITS ]      = { "S", "H", "D", "C" };



/*
D 2
 * call prcard in one of two forms
E 2
I 2
 * msgcard:
 *	Call msgcrd in one of two forms
E 2
 */
D 2

printcard( c, brief )

    CARD                c;
    BOOLEAN             brief;
E 2
I 2
msgcard(c, brief)
CARD		c;
BOOLEAN		brief;
E 2
{
D 2
        if( brief )  return(  prcard( c, TRUE, (char *) NULL, TRUE )  );
        else         return(  prcard( c, FALSE, " of ", FALSE )  );
E 2
I 2
	if (brief)
		return msgcrd(c, TRUE, (char *) NULL, TRUE);
	else
		return msgcrd(c, FALSE, " of ", FALSE);
E 2
}



/*
D 2
 * print the value of a card in ascii
E 2
I 2
 * msgcrd:
 *	Print the value of a card in ascii
E 2
 */
I 2
msgcrd(c, brfrank, mid, brfsuit)
CARD		c;
char		*mid;
BOOLEAN		brfrank,  brfsuit;
{
	if (c.rank == EMPTY || c.suit == EMPTY)
	    return FALSE;
	if (brfrank)
	    addmsg("%1.1s", rankchar[c.rank]);
	else
	    addmsg(rankname[c.rank]);
	if (mid != NULL)
	    addmsg(mid);
	if (brfsuit)
	    addmsg("%1.1s", suitchar[c.suit]);
	else
	    addmsg(suitname[c.suit]);
	return TRUE;
}
E 2

D 2
prcard( c, brfrank, mid, brfsuit )

    CARD                c;
    char                *mid;
    BOOLEAN             brfrank,  brfsuit;
E 2
I 2
/*
 * printcard:
 *	Print out a card.
 */
D 7
printcard(win, cardno, c)
E 7
I 7
printcard(win, cardno, c, blank)
E 7
WINDOW		*win;
int		cardno;
CARD		c;
I 7
BOOLEAN		blank;
E 7
E 2
{
D 2
        if(  c.rank == -1  ||  c.suit == -1  )  return( FALSE );
        if( brfrank )  {
            printf( "%1.1s",  rankchar[ c.rank ] );
        }
        else  {
            printf( "%s",  rankname[ c.rank ] );
        }
        if( mid != NULL )  printf( "%s", mid );
        if( brfsuit )  {
            printf( "%1.1s",  suitchar[ c.suit ] );
        }
        else  {
            printf( "%s",  suitname[ c.suit ] );
        }
        return( TRUE );
E 2
I 2
D 4
	prcard(win, cardno * 2, cardno, c);
E 4
I 4
D 7
	prcard(win, cardno * 2, cardno, c, FALSE);
E 7
I 7
	prcard(win, cardno * 2, cardno, c, blank);
E 7
E 4
E 2
}

D 2


E 2
/*
D 2
 * prhand prints a hand of n cards
E 2
I 2
 * prcard:
 *	Print out a card on the window at the specified location
E 2
 */
I 2
D 4
prcard(win, y, x, c)
E 4
I 4
prcard(win, y, x, c, blank)
E 4
WINDOW		*win;
int		y, x;
CARD		c;
I 4
BOOLEAN		blank;
E 4
{
	if (c.rank == EMPTY)
	    return;
	mvwaddstr(win, y + 0, x, "+-----+");
	mvwaddstr(win, y + 1, x, "|     |");
	mvwaddstr(win, y + 2, x, "|     |");
	mvwaddstr(win, y + 3, x, "|     |");
	mvwaddstr(win, y + 4, x, "+-----+");
D 4
	mvwaddch(win, y + 1, x + 1, rankchar[c.rank][0]);
	waddch(win, suitchar[c.suit][0]);
	mvwaddch(win, y + 3, x + 4, rankchar[c.rank][0]);
	waddch(win, suitchar[c.suit][0]);
E 4
I 4
	if (!blank) {
		mvwaddch(win, y + 1, x + 1, rankchar[c.rank][0]);
		waddch(win, suitchar[c.suit][0]);
		mvwaddch(win, y + 3, x + 4, rankchar[c.rank][0]);
		waddch(win, suitchar[c.suit][0]);
	}
E 4
}
E 2

D 2
prhand( h, n, brief )

    CARD                h[];
    int                 n;
    BOOLEAN             brief;
E 2
I 2
/*
 * prhand:
 *	Print a hand of n cards
 */
D 7
prhand(h, n, win)
E 7
I 7
prhand(h, n, win, blank)
E 7
CARD		h[];
int		n;
WINDOW		*win;
I 7
BOOLEAN		blank;
E 7
E 2
{
D 2
        register  int           i;
E 2
I 2
	register int	i;
E 2

D 2
        --n;
        for( i = 0; i < n; i++ )  {
            if(  printcard( h[i], brief )  )  {
                if( brief )  printf( ", " );
                else     printf( "\n" );
            }
        }
        printcard( h[i], brief );
E 2
I 2
	werase(win);
	for (i = 0; i < n; i++)
D 7
	    printcard(win, i, h[i]);
E 7
I 7
	    printcard(win, i, *h++, blank);
E 7
	wrefresh(win);
E 2
}



/*
D 2
 * infrom reads a card, supposedly in hand, accepting unambigous brief input
 * returns the index of the card found...
E 2
I 2
 * infrom:
 *	reads a card, supposedly in hand, accepting unambigous brief
 *	input, returns the index of the card found...
E 2
 */
D 2

infrom( hand, n )

    CARD                hand[];
    int                 n;
E 2
I 2
infrom(hand, n, prompt)
CARD		hand[];
int		n;
char		*prompt;
E 2
{
D 2
        register  int           i, j;
        CARD                    crd;
E 2
I 2
	register int           i, j;
	CARD                    crd;
E 2

D 2
        if(  n < 1  )  {
            printf( "\nINFROM: %d = n < 1!!\n", n );
            exit( 74 );
        }
        do  {
            if(  incard( &crd )  )  {           /* if card is full card */
                if(  !isone( crd, hand, n )  )  {
                    printf( "That's not in your hand.  Play one of ( " );
                    prhand( hand, n, TRUE );
                    printf( " ): " );
                }
                else  {
                    for( i = 0; i < n; i++ )  {
                        if(  hand[i].rank == crd.rank  &&
                             hand[i].suit == crd.suit      )  break;
                    }
                    if(  i >= n  )  {
                        printf( "\nINFROM: isone or something messed up\n" );
                        exit( 77 );
                    }
                    return( i );
                }
            }
            else  {                             /* if not full card... */
                if(  crd.rank  !=  -1  )  {
                    for( i = 0; i < n; i++ )  {
                        if(  hand[i].rank == crd.rank  )  break;
                    }
                    if(  i >= n  )  {
                        printf( "No such rank in your hand.  Play one of ( " );
                        prhand( hand, n, TRUE );
                        printf( " ): " );
                    }
                    else  {
                        for( j = i + 1; j < n; j++ )  {
                            if(  hand[j].rank == crd.rank  )  break;
                        }
                        if(  j < n  )  {
                            printf( "Ambiguous rank.  Play one of ( " );
                            prhand( hand, n, TRUE );
                            printf( " ): " );
                        }
                        else  {
                            return( i );
                        }
                    }
                }
                else  {
                    printf( "Sorry, I missed that.  Play one of ( " );
                    prhand( hand, n, TRUE );
                    printf( " ): " );
                }
            }
        }  while( TRUE );
	return( 0 );   /*  Useless:  keeps lint quiet  */
}
E 2
I 2
	if (n < 1) {
	    printf("\nINFROM: %d = n < 1!!\n", n);
	    exit(74);
	}
	for (;;) {
I 5
	    msg(prompt);
E 5
	    if (incard(&crd)) {			/* if card is full card */
		if (!isone(crd, hand, n))
		    msg("That's not in your hand");
		else {
		    for (i = 0; i < n; i++)
			if (hand[i].rank == crd.rank &&
			    hand[i].suit == crd.suit)
				break;
		    if (i >= n) {
			printf("\nINFROM: isone or something messed up\n");
			exit(77);
		    }
		    return i;
		}
	    }
	    else				/* if not full card... */
		if (crd.rank != EMPTY) {
		    for (i = 0; i < n; i++)
			if (hand[i].rank == crd.rank)
				break;
		    if (i >= n)
			msg("No such rank in your hand");
		    else {
			for (j = i + 1; j < n; j++)
			    if (hand[j].rank == crd.rank)
				break;
			if (j < n)
			    msg("Ambiguous rank");
			else
			    return i;
		    }
		}
		else
		    msg("Sorry, I missed that");
D 5
	    msg(prompt);
E 5
	}
	/* NOTREACHED */
}
E 2



/*
D 2
 * incard inputs a card in any format
 * it reads a line ending with a CR and then parses it
E 2
I 2
 * incard:
 *	Inputs a card in any format.  It reads a line ending with a CR
 *	and then parses it.
E 2
 */
D 2

incard( crd )

    CARD                *crd;
E 2
I 2
incard(crd)
CARD		*crd;
E 2
{
D 2
        char                    *getline();
        register  int           i;
        int                     rnk, sut;
        char                    *line, *p, *p1;
        BOOLEAN                 retval;
E 2
I 2
	char		*getline();
	register int	i;
	int		rnk, sut;
	char		*line, *p, *p1;
	BOOLEAN		retval;
E 2

D 2
        retval = FALSE;
        rnk = sut = -1;
        if(  !( line = getline() )  )  goto  gotit;
        p = p1 = line;
        while(  *p1 != ' '  &&  *p1 != NULL  )  ++p1;
        *p1++ = NULL;
        if(  *p == NULL  )  goto  gotit;
                        /* IMPORTANT: no real card has 2 char first name */
        if(  strlen(p) == 2  )  {               /* check for short form */
            rnk = -1;
            for( i = 0; i < RANKS; i++ )  {
                if(  *p == *rankchar[i]  )  {
                    rnk = i;
                    break;
                }
            }
            if(  rnk == -1  )  goto  gotit;     /* it's nothing... */
            ++p;                                /* advance to next char */
            sut = -1;
            for( i = 0; i < SUITS; i++ )  {
                if(  *p == *suitchar[i]  )  {
                    sut = i;
                    break;
                }
            }
            if(  sut != -1  )  retval = TRUE;
            goto  gotit;
        }
        rnk = -1;
        for( i = 0; i < RANKS; i++ )  {
            if(  !strcmp( p, rankname[i] )  ||  !strcmp( p, rankchar[i] )  )  {
                rnk = i;
                break;
            }
        }
        if(  rnk == -1  )  goto  gotit;
        p = p1;
        while(  *p1 != ' '  &&  *p1 != NULL  )  ++p1;
        *p1++ = NULL;
        if(  *p == NULL  )  goto  gotit;
        if(  !strcmp( "OF", p )  )  {
            p = p1;
            while(  *p1 != ' '  &&  *p1 != NULL  )  ++p1;
            *p1++ = NULL;
            if(  *p == NULL  )  goto  gotit;
        }
        sut = -1;
        for( i = 0; i < SUITS; i++ )  {
            if(  !strcmp( p, suitname[i] )  ||  !strcmp( p, suitchar[i] )  )  {
                sut = i;
                break;
            }
        }
        if(  sut != -1  )  retval = TRUE;
E 2
I 2
	retval = FALSE;
	rnk = sut = EMPTY;
	if (!(line = getline()))
		goto gotit;
	p = p1 = line;
	while(  *p1 != ' '  &&  *p1 != NULL  )  ++p1;
	*p1++ = NULL;
	if(  *p == NULL  )  goto  gotit;
			/* IMPORTANT: no real card has 2 char first name */
	if(  strlen(p) == 2  )  {               /* check for short form */
	    rnk = EMPTY;
	    for( i = 0; i < RANKS; i++ )  {
		if(  *p == *rankchar[i]  )  {
		    rnk = i;
		    break;
		}
	    }
	    if(  rnk == EMPTY  )  goto  gotit;     /* it's nothing... */
	    ++p;                                /* advance to next char */
	    sut = EMPTY;
	    for( i = 0; i < SUITS; i++ )  {
		if(  *p == *suitchar[i]  )  {
		    sut = i;
		    break;
		}
	    }
	    if(  sut != EMPTY  )  retval = TRUE;
	    goto  gotit;
	}
	rnk = EMPTY;
	for( i = 0; i < RANKS; i++ )  {
	    if(  !strcmp( p, rankname[i] )  ||  !strcmp( p, rankchar[i] )  )  {
		rnk = i;
		break;
	    }
	}
	if(  rnk == EMPTY  )  goto  gotit;
	p = p1;
	while(  *p1 != ' '  &&  *p1 != NULL  )  ++p1;
	*p1++ = NULL;
	if(  *p == NULL  )  goto  gotit;
	if(  !strcmp( "OF", p )  )  {
	    p = p1;
	    while(  *p1 != ' '  &&  *p1 != NULL  )  ++p1;
	    *p1++ = NULL;
	    if(  *p == NULL  )  goto  gotit;
	}
	sut = EMPTY;
	for( i = 0; i < SUITS; i++ )  {
	    if(  !strcmp( p, suitname[i] )  ||  !strcmp( p, suitchar[i] )  )  {
		sut = i;
		break;
	    }
	}
	if(  sut != EMPTY  )  retval = TRUE;
E 2
gotit:
D 2
        (*crd).rank = rnk;
        (*crd).suit = sut;
        return( retval );
E 2
I 2
	(*crd).rank = rnk;
	(*crd).suit = sut;
	return( retval );
E 2
}



/*
D 2
 * getuchar reads and converts to upper case
E 2
I 2
 * getuchar:
 *	Reads and converts to upper case
E 2
 */
D 2

E 2
getuchar()
{
D 2
        register  int           c;
E 2
I 2
	register int		c;
E 2

D 2
        c = getchar();
        if(  c < 'a'  ||  c > 'z'  )  return( c );
        else                          return(  c + ('A' - 'a')  );
E 2
I 2
	c = readchar();
	if (islower(c))
	    c = toupper(c);
D 9
	addch(c);
E 9
I 9
	waddch(Msgwin, c);
E 9
	return c;
E 2
}

D 3


E 3
/*
D 3
 * number reads in a decimal number and makes sure it is between
 * lo and hi inclusive
 * a cr counts as lo
E 3
I 3
 * number:
 *	Reads in a decimal number and makes sure it is between "lo" and
 *	"hi" inclusive.
E 3
 */
D 3

number( lo, hi )

    int         lo, hi;
E 3
I 3
number(lo, hi, prompt)
int		lo, hi;
char		*prompt;
E 3
{
D 2
        char                    *getline();
        register  char          *p;
        register  int            sum;
E 2
I 2
D 3
	char                    *getline();
	register  char          *p;
	register  int            sum;
E 3
I 3
	char			*getline();
	register char		*p;
	register int		sum;
E 3
E 2

D 2
        sum = 0;
        do  {
            if(  !( p = getline() )  )  return( lo );   /* no line = lo */
            if(  *p == NULL  )  return( lo );
            sum = 0;
            while(  *p == ' '  ||  *p == '\t'  )  ++p;
            if(  *p < '0'  ||  *p > '9'  )  {
                sum = lo - 1;
            }
            else  {
                do  {
                    sum = 10*sum + (*p - '0');
                    ++p;
                }  while(  '0' <= *p  &&  *p <= '9'  );
            }
            if(  *p != ' '  &&  *p != '\t'  &&  *p != NULL  )  sum = lo - 1;
            if(  sum >= lo  &&  sum <= hi  )  break;
            if(  sum == lo - 1  )  {
                printf( "that doesn't look like a number, try again --> " );
            }
            else  {
                printf( "%d is not between %d and %d inclusive, try again --> ",
                                                                sum, lo, hi );
            }
        }  while( TRUE );
        return( sum );
E 2
I 2
	sum = 0;
D 3
	do  {
	    if(  !( p = getline() )  )  return( lo );   /* no line = lo */
	    if(  *p == NULL  )  return( lo );
E 3
I 3
	for (;;) {
	    msg(prompt);
	    if(!(p = getline()) || *p == NULL) {
		msg(quiet ? "Not a number" : "That doesn't look like a number");
		continue;
	    }
E 3
	    sum = 0;
D 3
	    while(  *p == ' '  ||  *p == '\t'  )  ++p;
	    if(  *p < '0'  ||  *p > '9'  )  {
E 3
I 3

	    if (!isdigit(*p))
E 3
		sum = lo - 1;
D 3
	    }
	    else  {
		do  {
		    sum = 10*sum + (*p - '0');
E 3
I 3
	    else
		while (isdigit(*p)) {
		    sum = 10 * sum + (*p - '0');
E 3
		    ++p;
D 3
		}  while(  '0' <= *p  &&  *p <= '9'  );
	    }
	    if(  *p != ' '  &&  *p != '\t'  &&  *p != NULL  )  sum = lo - 1;
	    if(  sum >= lo  &&  sum <= hi  )  break;
	    if(  sum == lo - 1  )  {
		printf( "that doesn't look like a number, try again --> " );
	    }
	    else  {
		printf( "%d is not between %d and %d inclusive, try again --> ",
								sum, lo, hi );
	    }
	}  while( TRUE );
	return( sum );
E 3
I 3
		}

	    if (*p != ' ' && *p != '\t' && *p != NULL)
		sum = lo - 1;
	    if (sum >= lo && sum <= hi)
		return sum;
	    if (sum == lo - 1)
		msg("that doesn't look like a number, try again --> ");
	    else
		msg("%d is not between %d and %d inclusive, try again --> ",
								sum, lo, hi);
	}
E 3
E 2
}

I 2
/*
 * msg:
 *	Display a message at the top of the screen.
 */
D 8
char		Msgbuf[BUFSIZ] = "";
E 8
I 8
char		Msgbuf[BUFSIZ] = { '\0' };
E 8
E 2

I 2
int		Mpos = 0;
E 2

I 2
static int	Newpos = 0;

/* VARARGS1 */
msg(fmt, args)
char	*fmt;
int	args;
{
D 9
    /*
     * if the string is "", just clear the line
     */
    if (*fmt == '\0') {
	move(LINES - 1, 0);
	clrtoeol();
	Mpos = 0;
	Hasread = TRUE;
	return;
    }
    /*
     * otherwise add to the message and flush it out
     */
E 9
    doadd(fmt, &args);
    endmsg();
}

E 2
/*
D 2
 * getline reads the next line up to '\n' or EOF
 * multiple spaces are compressed to one space
 * a space is inserted before a ','
E 2
I 2
 * addmsg:
 *	Add things to the current message
E 2
 */
I 2
/* VARARGS1 */
addmsg(fmt, args)
char	*fmt;
int	args;
{
    doadd(fmt, &args);
}
E 2

D 2
char  *getline()
E 2
I 2
/*
 * endmsg:
D 9
 *	Display a new msg (giving him a chance to see the previous one
 *	if it is up there with the --More--)
E 9
I 9
 *	Display a new msg.
E 9
 */
I 10

int	Lineno = 0;

E 10
endmsg()
E 2
{
D 2
        register  char                  c, *p;
E 2
I 2
D 9
    if (!Hasread) {
	move(LINES - 1, Mpos);
	addstr("--More--");
	refresh();
	wait_for(' ');
    }
E 9
I 9
    register int	len;
    register char	*mp, *omp;
D 10
    static int		lineno = 0;
E 10
I 10
    static int		lastline = 0;
E 10

E 9
    /*
D 10
     * All messages should start with uppercase, except ones that
     * start with a pack addressing character
E 10
I 10
     * All messages should start with uppercase
E 10
     */
I 10
    mvaddch(lastline + Y_MSG_START, SCORE_X, ' ');
E 10
    if (islower(Msgbuf[0]) && Msgbuf[1] != ')')
	Msgbuf[0] = toupper(Msgbuf[0]);
D 9
    mvaddstr(LINES - 1, 0, Msgbuf);
    clrtoeol();
E 9
I 9
    mp = Msgbuf;
    len = strlen(mp);
D 10
    if (len / MSG_X + lineno > MSG_Y)
	lineno = 0;
E 10
I 10
D 11
    if (len / MSG_X + Lineno >= MSG_Y)
E 11
I 11
    if (len / MSG_X + Lineno >= MSG_Y) {
	while (Lineno < MSG_Y) {
	    wmove(Msgwin, Lineno++, 0);
	    wclrtoeol(Msgwin);
	}
E 11
	Lineno = 0;
I 11
    }
E 11
    mvaddch(Lineno + Y_MSG_START, SCORE_X, '*');
    lastline = Lineno;
E 10
    do {
D 10
	mvwaddstr(Msgwin, lineno, 0, mp);
E 10
I 10
	mvwaddstr(Msgwin, Lineno, 0, mp);
E 10
	if ((len = strlen(mp)) > MSG_X) {
	    omp = mp;
	    for (mp = &mp[MSG_X-1]; *mp != ' '; mp--)
	    	continue;
	    while (*mp == ' ')
		mp--;
	    mp++;
D 10
	    wmove(Msgwin, lineno, mp - omp);
E 10
I 10
	    wmove(Msgwin, Lineno, mp - omp);
E 10
	    wclrtoeol(Msgwin);
	}
D 10
	if (++lineno >= MSG_Y)
	    lineno = 0;
E 10
I 10
	if (++Lineno >= MSG_Y)
	    Lineno = 0;
E 10
    } while (len > MSG_X);
    wclrtoeol(Msgwin);
E 9
D 10
    Mpos = Newpos;
E 10
I 10
D 11
    Mpos = Newpos % MSG_X;
E 11
I 11
    Mpos = len;
E 11
E 10
    Newpos = 0;
I 9
    wrefresh(Msgwin);
E 9
    refresh();
D 9
    Hasread = FALSE;
E 9
I 9
    wrefresh(Msgwin);
E 9
}
E 2

D 2
        do  {
            c = getuchar();
            if(  c < 0  )  return( NULL );
        }  while(  c == ' '  ||  c == '\t'  );
        if(  c == '\n'  )  {
            linebuf[0] = NULL;
            return( linebuf );
        }
        p = linebuf;
        *p = c;                                         /* first non-blank */
        while(  ( c = getuchar() )  >= 0  )  {          /* read one line */
            if(  c == '\n'  )  break;
            if(  c == ','  )  if(  *p != ' '  )  *++p = ' ';
            if(  *p == ' '  )  {                        /* compress spaces */
                if(  c == ' '  ||  c == '\t'  )  continue;
                else  *++p = c;
            }
            else  {
                if(  c == ' '  ||  c == '\t'  )  *++p = ' ';
                else  *++p = c;
            }
            if(  p - linebuf  >=  (LINESIZE - 2)  )  {
                do  {
                    c = getuchar();
                    if(  c < 0  )  return( NULL );
                }  while(  c != '\n'  );
                break;
            }
        }
        if(  c < 0  )  return( NULL );
        *++p = NULL;
        *++p = NULL;
        return( linebuf );
E 2
I 2
/*
 * doadd:
 *	Perform an add onto the message buffer
 */
doadd(fmt, args)
char	*fmt;
int	*args;
{
    static FILE	junk;

    /*
     * Do the printf into Msgbuf
     */
    junk._flag = _IOWRT + _IOSTRG;
    junk._ptr = &Msgbuf[Newpos];
    junk._cnt = 32767;
    _doprnt(fmt, args, &junk);
    putc('\0', &junk);
    Newpos = strlen(Msgbuf);
I 10
}

/*
 * do_wait:
 *	Wait for the user to type ' ' before doing anything else
 */
do_wait()
{
    register int line;
    static char prompt[] = { '-', '-', 'M', 'o', 'r', 'e', '-', '-', '\0' };

    if (Mpos + sizeof prompt < MSG_X)
	wmove(Msgwin, Lineno > 0 ? Lineno - 1 : MSG_Y - 1, Mpos);
    else {
	mvwaddch(Msgwin, Lineno, 0, ' ');
	wclrtoeol(Msgwin);
	if (++Lineno >= MSG_Y)
	    Lineno = 0;
    }
    waddstr(Msgwin, prompt);
    wrefresh(Msgwin);
    wait_for(' ');
E 10
E 2
}

I 2
/*
 * wait_for
 *	Sit around until the guy types the right key
 */
wait_for(ch)
register char	ch;
{
    register char	c;
E 2

I 2
    if (ch == '\n')
	while ((c = readchar()) != '\n')
	    continue;
    else
	while (readchar() != ch)
	    continue;
}
E 2

I 2
/*
 * readchar:
 *	Reads and returns a character, checking for gross input errors
 */
readchar()
{
    register int	cnt, y, x;
    auto char		c;
E 2

I 2
over:
    cnt = 0;
    while (read(0, &c, 1) <= 0)
	if (cnt++ > 100)	/* if we are getting infinite EOFs */
	    bye();		/* quit the game */
    if (c == CTRL(L)) {
	wrefresh(curscr);
	goto over;
    }
D 9
    Hasread = TRUE;
E 9
    if (c == '\r')
	return '\n';
    else
	return c;
}

/*
 * getline:
 *      Reads the next line up to '\n' or EOF.  Multiple spaces are
 *	compressed to one space; a space is inserted before a ','
 */
char *
getline()
{
    register char	*sp;
    register int	c, oy, ox;
I 9
    register WINDOW	*oscr;
E 9

I 9
    oscr = stdscr;
    stdscr = Msgwin;
E 9
    getyx(stdscr, oy, ox);
    refresh();
    /*
     * loop reading in the string, and put it in a temporary buffer
     */
    for (sp = linebuf; (c = readchar()) != '\n'; clrtoeol(), refresh()) {
	if (c == -1)
	    continue;
	else if (c == erasechar()) {	/* process erase character */
	    if (sp > linebuf) {
		register int i;

		sp--;
		for (i = strlen(unctrl(*sp)); i; i--)
		    addch('\b');
	    }
	    continue;
	}
	else if (c == killchar()) {	/* process kill character */
	    sp = linebuf;
	    move(oy, ox);
	    continue;
	}
	else if (sp == linebuf && c == ' ')
	    continue;
	if (sp >= &linebuf[LINESIZE-1] || !(isprint(c) || c == ' '))
	    putchar(CTRL(G));
	else {
	    if (islower(c))
		c = toupper(c);
	    *sp++ = c;
	    addstr(unctrl(c));
D 9
/*###366 [cc] Mpos undefined %%%*/
E 9
	    Mpos++;
	}
    }
    *sp = '\0';
I 9
    stdscr = oscr;
E 9
    return linebuf;
I 13
}

/*
 * bye:
 *	Leave the program, cleaning things up as we go.
 */
bye()
{
	signal(SIGINT, SIG_IGN);
	mvcur(0, COLS - 1, LINES - 1, 0);
	fflush(stdout);
	endwin();
	putchar('\n');
	exit(1);
E 13
}
E 2
E 1
