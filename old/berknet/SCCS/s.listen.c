h47029
s 00029/00000/00000
d D 4.1 82/10/02 23:07:54 comay 1 0
c date and time created 82/10/02 23:07:54 by comay
e
u
U
t
T
I 1
static char sccsid[] = "%W%	(Berkeley)	%G%";

/*
	listen.c

	listen for a packet from the program interact.c and print it
*/
# include "defs.h"
main(argc,argv)
	  char **argv;
{
	struct packet *pp;
	char buf[BUFSIZ];
	setupdaemon(argc,argv);
	initseqno();
	putchar('!');
	fflush(stdout);
	for(;;){
		pp = getpacket();
		printpacket(pp,buf);
		printf("got %s\n",buf);
		if(pp == NULL )continue;
		pp->pcode = ACK;
		pp->len = 0;
		sendpacket(pp);
		printpacket(pp,buf);
		printf("sent %s\n",buf);
	}
}
E 1
