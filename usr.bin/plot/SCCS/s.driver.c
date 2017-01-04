h56762
s 00055/00034/00098
d D 4.4 85/09/21 16:46:47 sam 4 3
c beautify and add -r flag for setting output device resolution
e
s 00003/00004/00129
d D 4.3 85/01/09 11:52:58 ralph 3 2
c rename local gets to prevent conflict with stdio
e
s 00001/00000/00132
d D 4.2 83/11/11 15:05:34 ralph 2 1
c added a fclose.
e
s 00132/00000/00000
d D 4.1 83/08/11 20:57:14 sam 1 0
c date and time created 83/08/11 20:57:14 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>

float deltx;
float delty;
I 4
int PlotRes;
E 4

D 4
main(argc,argv)  char **argv; {
	int std=1;
E 4
I 4
main(argc,argv)
	int argc;
	char *argv[];
{
	int std = 1;
	char *progname;
E 4
	FILE *fin;

D 4
	while(argc-- > 1) {
		if(*argv[1] == '-')
			switch(argv[1][1]) {
				case 'l':
					deltx = atoi(&argv[1][2]) - 1;
					break;
				case 'w':
					delty = atoi(&argv[1][2]) - 1;
					break;
				}

		else {
			std = 0;
			if ((fin = fopen(argv[1], "r")) == NULL) {
				fprintf(stderr, "can't open %s\n", argv[1]);
				exit(1);
				}
			fplt(fin);
I 2
			fclose(fin);
E 4
I 4
	progname = argv[0];
	for (argc--, argv++; argc > 0; argc--, argv++) {
		if (argv[0][0] == '-') {
			switch (argv[0][1]) {
			case 'l':
				deltx = atoi(&argv[0][2]) - 1;
				break;
			case 'w':
				delty = atoi(&argv[0][2]) - 1;
				break;
			case 'r':
				PlotRes = atoi(&argv[0][2]);
				break;
E 4
E 2
			}
D 4
		argv++;
E 4
I 4
			continue;
E 4
		}
I 4
		std = 0;
		fin = fopen(argv[0], "r");
		if (fin == NULL) {
			fprintf(stderr, "%s: can't open %s\n", progname,
			    argv[0]);
			exit(1);
		}
		fplt(fin);
		fclose(fin);
	}
E 4
	if (std)
D 4
		fplt( stdin );
E 4
I 4
		fplt(stdin);
E 4
	exit(0);
D 4
	}
E 4
I 4
}
E 4

D 4

fplt(fin)  FILE *fin; {
	int c;
E 4
I 4
fplt(fin)
	FILE *fin;
{
	register int c;
E 4
	char s[256];
	int xi,yi,x0,y0,x1,y1,r,dx,n,i;
	int pat[256];

	openpl();
D 4
	while((c=getc(fin)) != EOF){
		switch(c){
E 4
I 4
	while((c = getc(fin)) != EOF) {
		switch(c) {
E 4
		case 'm':
			xi = getsi(fin);
			yi = getsi(fin);
			move(xi,yi);
			break;
		case 'l':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			line(x0,y0,x1,y1);
			break;
		case 't':
D 3
			gets(s,fin);
E 3
I 3
			getstr(s,fin);
E 3
			label(s);
			break;
		case 'e':
			erase();
			break;
		case 'p':
			xi = getsi(fin);
			yi = getsi(fin);
			point(xi,yi);
			break;
		case 'n':
			xi = getsi(fin);
			yi = getsi(fin);
			cont(xi,yi);
			break;
		case 's':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			space(x0,y0,x1,y1);
			break;
		case 'a':
			xi = getsi(fin);
			yi = getsi(fin);
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			arc(xi,yi,x0,y0,x1,y1);
			break;
		case 'c':
			xi = getsi(fin);
			yi = getsi(fin);
			r = getsi(fin);
			circle(xi,yi,r);
			break;
		case 'f':
D 3
			gets(s,fin);
E 3
I 3
			getstr(s,fin);
E 3
			linemod(s);
			break;
		case 'd':
			xi = getsi(fin);
			yi = getsi(fin);
			dx = getsi(fin);
			n = getsi(fin);
D 4
			for(i=0; i<n; i++)pat[i] = getsi(fin);
E 4
I 4
			for(i=0; i<n; i++)
				pat[i] = getsi(fin);
E 4
			dot(xi,yi,dx,n,pat);
			break;
D 4
			}
E 4
		}
D 4
	closepl();
E 4
	}
D 4
getsi(fin)  FILE *fin; {	/* get an integer stored in 2 ascii bytes. */
E 4
I 4
	closepl();
}

/* get an integer stored in 2 ascii bytes. */
getsi(fin)
	register FILE *fin;
{
E 4
	short a, b;
I 4

E 4
	if((b = getc(fin)) == EOF)
		return(EOF);
	if((a = getc(fin)) == EOF)
		return(EOF);
	a = a<<8;
	return(a|b);
}
D 3
gets(s,fin)  char *s;  FILE *fin; {
E 3
I 3
D 4
getstr(s,fin)  char *s;  FILE *fin; {
E 4
I 4

getstr(s, fin)
	register char *s;
	register FILE *fin;
{

E 4
E 3
	for( ; *s = getc(fin); s++)
		if(*s == '\n')
			break;
	*s = '\0';
D 3
	return;
E 3
}
E 1
