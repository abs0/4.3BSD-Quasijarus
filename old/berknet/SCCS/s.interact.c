h36646
s 00023/00000/00000
d D 4.1 82/10/02 23:07:57 comay 1 0
c date and time created 82/10/02 23:07:57 by comay
e
u
U
t
T
I 1
static char sccsid[] = "%W%	(Berkeley)	%G%";

/*
	interact.c

	send a packet to the program "listen"
*/
# include "defs.h"
main(argc,argv)
  char **argv;
	{
	int i,c;
	char buf[2000];
	setupdaemon(argc,argv);
	initseqno();
	for(;;){
		putchar('?');
		i = 0;
		while((c = getchar()) != '\n' && c != EOF)
			buf[i++] = c;
		if(xwrite(buf,i) == WRITEFAIL)fprintf(stderr,"writefail\n");
		}
	}
E 1
