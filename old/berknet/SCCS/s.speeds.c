h56395
s 00036/00000/00000
d D 4.1 82/10/02 23:02:07 comay 1 0
c date and time created 82/10/02 23:02:07 by comay
e
u
U
t
T
I 1
static char sccsid[] = "%W%	(Berkeley)	%G%";

/*
	speeds niter -m mach -p len

	used with speedr.c to compute the link speed
*/
# include "defs.h"
/* global variables */
struct daemonparms netd;

main(argc,argv)
  char **argv;{
	int n,t,i;
	short j;
	char buf[2000];
	t = atoi(argv[argc-1]);
	debugflg = DBV;
	setupdaemon(argc,argv);
	n = netd.dp_datasize;
	printf("len %d iter %d\n",netd.dp_datasize,t);
	initseqno();
	j = n;
# ifdef SWAB
	swab(&j,&j,2);
# endif
	xwrite(&j,2);
	for(i=0; i<n; i++)buf[i] = 'A';
	buf[n-1] = '\n';
	for(i=0;i<t;i++){
		if(i == t-1)buf[0] = 'Z';
		xwrite(buf,n);
		putchar('.');
		fflush(stdout);
		}
	}
E 1
