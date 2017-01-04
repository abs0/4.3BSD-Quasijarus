h35777
s 00001/00001/00027
d D 1.3 87/02/15 21:24:12 lepreau 4 3
c modern syntax for inits.  When ANSI cpp comes will need more work.
e
s 00001/00001/00027
d D 1.2 85/05/04 00:07:50 sam 3 1
c use strcpy, it's been optimized
e
s 00001/00001/00027
d R 1.2 85/05/03 23:49:08 sam 2 1
c use strcpy, it's been optimized
e
s 00028/00000/00000
d D 1.1 85/05/03 12:10:56 sam 1 0
c date and time created 85/05/03 12:10:56 by sam
e
u
U
t
T
I 1
#define numeric(c) (c>='0' && c<='9')
#define max(a,b) (a<b ? b : a)
#define min(a,b) (a>b ? b : a)
#define abs(x) (x<0 ? -x : x)

D 3
#define copy(src,dest) cat(dest,src,0)
E 3
I 3
#define copy(src,dest) strcpy(dest,src)
E 3
#define compare(str1,str2) strcmp(str1,str2)
#define equal(str1,str2) !strcmp(str1,str2)
#define length(str) strlen(str)
#define size(str) (1+strlen(str))

#include "sys/types.h"
#include "sys/stat.h"
struct stat Statbuf;
#define exists(file) (stat(file,&Statbuf)<0 ? 0:Statbuf.st_mode)

#define xfopen(file,mode) fdopen(xopen(file,mode),mode==0?"r":mode==1?"w":"r+w")
#define xfcreat(file,mode) fdopen(xcreat(file,mode),"w")
#define remove(file) xunlink(file)

D 4
#define SCCSID(arg) static char Sccsid[] "arg"
E 4
I 4
#define SCCSID(arg) static char Sccsid[] = "arg"
E 4

#define USXALLOC()

#define NONBLANK(p) while (*p==' ' || *p=='\t') p++

char Null[1];
char Error[128];
E 1
