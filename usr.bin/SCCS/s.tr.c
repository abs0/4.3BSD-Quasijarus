h42635
s 00005/00001/00132
d D 4.2 85/04/22 15:07:25 mckusick 2 1
c check for write failure
e
s 00133/00000/00000
d D 4.1 80/10/01 17:29:00 bill 1 0
c date and time created 80/10/01 17:29:00 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
#include <stdio.h>

/* tr - transliterate data stream */
int	dflag	= 0;
int	sflag	= 0;
int	cflag = 0;
int	save	= 0;
char	code[256];
char	squeez[256];
char	vect[256];
struct string { int last, max; char *p; } string1, string2;

main(argc,argv)
char **argv;
{
	register i;
	int j;
	register c, d;
	char *compl;
	int lastd;

	string1.last = string2.last = 0;
	string1.max = string2.max = 0;
	string1.p = string2.p = "";

	if(--argc>0) {
		argv++;
		if(*argv[0]=='-'&&argv[0][1]!=0) {
			while(*++argv[0])
				switch(*argv[0]) {
				case 'c':
					cflag++;
					continue;
				case 'd':
					dflag++;
					continue;
				case 's':
					sflag++;
					continue;
				}
			argc--;
			argv++;
		}
	}
	if(argc>0) string1.p = argv[0];
	if(argc>1) string2.p = argv[1];
	for(i=0; i<256; i++)
		code[i] = vect[i] = 0;
	if(cflag) {
		while(c = next(&string1))
			vect[c&0377] = 1;
		j = 0;
		for(i=1; i<256; i++)
			if(vect[i]==0) vect[j++] = i;
		vect[j] = 0;
		compl = vect;
	}
	for(i=0; i<256; i++)
		squeez[i] = 0;
	lastd = 0;
	for(;;){
		if(cflag) c = *compl++;
		else c = next(&string1);
		if(c==0) break;
		d = next(&string2);
		if(d==0) d = lastd;
		else lastd = d;
		squeez[d&0377] = 1;
		code[c&0377] = dflag?1:d;
	}
	while(d = next(&string2))
		squeez[d&0377] = 1;
	squeez[0] = 1;
	for(i=0;i<256;i++) {
		if(code[i]==0) code[i] = i;
		else if(dflag) code[i] = 0;
	}

I 2
	clearerr(stdout);
E 2
	while((c=getc(stdin)) != EOF ) {
		if(c == 0) continue;
		if(c = code[c&0377]&0377)
D 2
			if(!sflag || c!=save || !squeez[c&0377])
E 2
I 2
			if(!sflag || c!=save || !squeez[c&0377]) {
E 2
				putchar(save = c);
I 2
				if(ferror(stdout))
					exit(1);
			}
E 2
	}
	exit(0);
}

next(s)
struct string *s;
{

again:
	if(s->max) {
		if(s->last++ < s->max)
			return(s->last);
		s->max = s->last = 0;
	}
	if(s->last && *s->p=='-') {
		nextc(s);
		s->max = nextc(s);
		if(s->max==0) {
			s->p--;
			return('-');
		}
		if(s->max < s->last)  {
			s->last = s->max-1;
			return('-');
		}
		goto again;
	}
	return(s->last = nextc(s));
}

nextc(s)
struct string *s;
{
	register c, i, n;

	c = *s->p++;
	if(c=='\\') {
		i = n = 0;
		while(i<3 && (c = *s->p)>='0' && c<='7') {
			n = n*8 + c - '0';
			i++;
			s->p++;
		}
		if(i>0) c = n;
		else c = *s->p++;
	}
	if(c==0) *--s->p = 0;
	return(c&0377);
}
E 1
