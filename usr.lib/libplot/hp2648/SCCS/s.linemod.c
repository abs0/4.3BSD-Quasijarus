h39642
s 00007/00001/00071
d D 5.1 85/05/07 12:07:27 dist 2 1
c Add copyright notice
e
s 00072/00000/00000
d D 4.1 83/11/10 14:14:28 ralph 1 0
c date and time created 83/11/10 14:14:28 by ralph
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

#include "hp2648.h"

linemod( line )
char	*line;
{
	putchar('Z'); 
	handshake();
	putchar(ESC); 
	putchar(GRAPHIC);
	putchar(MODE);
	if ( *(line) == 's' ) {
		if ( *(++line) == 'o' ) {
			/*
			 * solid mode 1
			 */
			putchar( '1' );
			putchar( 'b' );
			goto done;
		}
		else if ( *(line) == 'h' ) {
			/*
			 * shortdashed mode 4
			 */
			putchar( '6' );
			putchar( 'b' );
			goto done;
		}
	}
	else if ( *(line) == 'd' ) {
		if ( *(++line) == 'o' && *(++line) == 't' ) {
			if ( *(++line) == 't' ) {
				/*
				 * dotted mode 2
				 */
				putchar( '7' );
				putchar( 'b' );
				goto done;
			}
			else if ( *(line) == 'd' ) {
				/*
				 * dotdashed mode 3
				 */
				putchar( '8' );
				putchar( 'b' );
				goto done;
			}
		}
	}
	else if ( *(line) == 'l' ) {
		/*
		 * longdashed mode 5
		 */
		putchar( '5' );
		putchar( 'b' );
		goto done;
	}
	putchar( '1' );				/* default to solid */
	putchar( 'b' );				/* default to solid */
done:
	putchar( 'Z' );
	handshake();
	putchar(ESC); 
	putchar(GRAPHIC);
	putchar(PLOT);
	putchar(BINARY);
	buffcount = 4;
	return;
}
E 1
