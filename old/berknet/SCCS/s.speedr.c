h54261
s 00037/00000/00000
d D 4.1 82/10/02 23:02:01 comay 1 0
c date and time created 82/10/02 23:02:01 by comay
e
u
U
t
T
I 1
static char sccsid[] = "%W%	(Berkeley)	%G%";

/*
	speedr.c

	with speeds.c used to time the links
*/
# include "defs.h"

/* global */
struct daemonparms netd;

main(argc,argv)
  char **argv; {
	char buf[2000];
	int savd, n;
	register int i;
	debugflg = DBV;
	setupdaemon(argc,argv);
	initseqno();
	savd = netd.dp_datasize;
	putchar('!');
	for(;;){
		netd.dp_datasize = savd;
		while(nread(&n,2) == BROKENREAD);
# ifdef SWAB
		swab(&n,&n,2);
# endif
		printf("Length = %d\n",n);
		netd.dp_datasize = n;
		for(;;){
			while((i=nread(buf,n)) == BROKENREAD);
			if(i != n)putchar('#');
			if(buf[0] == 'Z')break;
			}
		}
	}
E 1
