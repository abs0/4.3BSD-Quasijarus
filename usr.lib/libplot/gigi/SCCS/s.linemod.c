h46531
s 00007/00001/00064
d D 5.1 85/05/07 11:50:49 dist 2 1
c Add copyright notice
e
s 00065/00000/00000
d D 4.1 83/11/10 16:05:18 ralph 1 0
c date and time created 83/11/10 16:05:18 by ralph
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
#endif not lint
E 2

#include "gigi.h"

linemod( line )
char	*line;
{
	/*
	 * Note that the bit patterns could be compacted using the
	 *  repeat field conventions.  They aren't for clarity.
	 *  Examples of almost identical packed patterns are in the
	 *  comments.
	 *  If linemod is changed really often, a ~15% savings
	 *  could be achieved.
	 */
	if ( *(line) == 's' ) {
		if ( *(++line) == 'o' ) {
			/*
			 * solid mode 1
			 */
			printf( "W(P1)" );
			return;
		}
		else if ( *(line) == 'h' ) {
			/*
			 * shortdashed mode 4
			 *  printf( "W(P000111)" );
			 */
			printf( "W(P00011100)" );
			return;
		}
	}
	else if ( *(line) == 'd' ) {
		if ( *(++line) == 'o' && *(++line) == 't' ) {
			if ( *(++line) == 't' ) {
				/*
				 * dotted mode 2
				 *  printf( "W(P00001)" );
				 */
				printf( "W(P10000000)" );
				return;
			}
			else if ( *(line) == 'd' ) {
				/*
				 * dotdashed mode 3
				 *  printf( "W(P0110010)" );
				 */
				printf( "W(P10001100)" );
				return;
			}
		}
	}
	else if ( *(line) == 'l' ) {
		/*
		 * longdashed mode 5
		 *  printf( "W(P11100)" );
		 */
		printf( "W(P11111100)" );
		return;
	}
	printf( "W(P1)" );			/* default to solid */
	return;
}
E 1
