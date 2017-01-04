h33398
s 00010/00005/00043
d D 4.4 88/06/29 21:54:32 bostic 4 3
c install approved copyright notice
e
s 00039/00037/00009
d D 4.3 87/12/13 13:59:04 bostic 3 2
c handle lines larger than 256 chars
e
s 00001/00000/00045
d D 4.2 87/12/02 16:46:57 bostic 2 1
c bug report 4.3BSD/usr.bin/110; exit 0 on success
e
s 00045/00000/00000
d D 4.1 80/10/01 17:28:10 bill 1 0
c date and time created 80/10/01 17:28:10 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
#include <stdio.h>
E 3
I 3
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
 */
E 3

D 3
/* reverse lines of a file */
E 3
I 3
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */
E 3

D 3
#define N 256
char line[N];
FILE *input;
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 3

D 3
main(argc,argv)
char **argv;
E 3
I 3
#include <stdio.h>

main(argc, argv)
	int argc;
	char **argv;
E 3
{
D 3
	register i,c;
	input = stdin;
E 3
I 3
	register char *t, *bp;
	char buf[BUFSIZ];

	bp = buf;
E 3
	do {
D 3
		if(argc>1) {
			if((input=fopen(argv[1],"r"))==NULL) {
				fprintf(stderr,"rev: cannot open %s\n",
					argv[1]);
				exit(1);
			}
E 3
I 3
		if (argc > 1 && !freopen(*++argv, "r", stdin)) {
			fprintf(stderr, "rev: cannot open %s.\n", *argv);
			exit(1);
E 3
		}
D 3
		for(;;){
			for(i=0;i<N;i++) {
				line[i] = c = getc(input);
				switch(c) {
				case EOF:
					goto eof;
				default:
					continue;
				case '\n':
					break;
				}
				break;
			}
			while(--i>=0)
				putc(line[i],stdout);
			putc('\n',stdout);
E 3
I 3
		while (fgets(bp, sizeof(buf), stdin)) {
			for (t = bp; *t; ++t);
			if (*--t == '\n')
				--t;
			for (; t >= bp; --t)
				putchar(*t);
			putchar('\n');
E 3
		}
D 3
eof:
		fclose(input);
		argc--;
		argv++;
	} while(argc>1);
E 3
I 3
	} while(--argc > 1);
E 3
I 2
	exit(0);
E 2
}
E 1
