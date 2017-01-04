h30529
s 00002/00002/00047
d D 4.2 83/07/21 11:22:53 mckusick 2 1
c move database to /usr/lib/find; restrict database to /usr
e
s 00049/00000/00000
d D 4.1 83/07/21 00:14:45 mckusick 1 0
c date and time created 83/07/21 00:14:45 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

/*
 *  bigram < text > bigrams
 * 
D 2
 * List bigrams for 'find.squeeze' script.
 * Use 'find.code' to encode a file using this output.
E 2
I 2
 * List bigrams for 'updatedb' script.
 * Use 'code' to encode a file using this output.
E 2
 */

#include <stdio.h>

#define MAXPATH	1024		/* maximum pathname length */

char path[MAXPATH];
char oldpath[MAXPATH] = " ";	

main ( )
{
  	register int count, j;

     	while ( gets ( path ) != NULL ) {

		count = prefix_length ( oldpath, path );
		/*
		   output post-residue bigrams only
		*/
		for ( j = count; path[j] != NULL; j += 2 ) {
			if ( path[j + 1] == NULL ) 
				break;
			putchar ( path[j] );
			putchar ( path[j + 1] );
			putchar ( '\n' );
		}
		strcpy ( oldpath, path );
   	}
}

prefix_length ( s1, s2 )	/* return length of longest common prefix */
	char *s1, *s2;		/* ... of strings s1 and s2 */
{
	register char *start;

    	for ( start = s1; *s1 == *s2; s1++, s2++ )	
		if ( *s1 == NULL )		
	    		break;
    	return ( s1 - start );
}
E 1
