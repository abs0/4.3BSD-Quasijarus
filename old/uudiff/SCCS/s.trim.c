h27216
s 00019/00000/00000
d D 4.1 83/01/01 19:02:32 sam 1 0
c date and time created 83/01/01 19:02:32 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

# if interdata
# include "stdio.h"
# endif
main(argc,argv)
	char *argv[];
{
char *nm, *p;
p = nm = argv[1];
while (*p) p++;
while (*p != '/') p--;
if (p==nm) p++;
*p = 0;
printf("%s\n", nm);
exit(0);
}
E 1
