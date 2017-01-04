h26266
s 00016/00000/00000
d D 4.1 83/01/01 19:02:29 sam 1 0
c date and time created 83/01/01 19:02:29 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

main(argc,argv)
	char *argv[];
{
char b[512], *p;
int f, c;
f = open(argv[1], 0);
if (f<0) return(1);
p = b + read(f, b, 512);
while (p>b)
	if ( (c= *--p) ==0 || (c&0200) ) return(1);
return(0);
}
E 1
