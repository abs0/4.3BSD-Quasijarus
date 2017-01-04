h41752
s 00000/00000/00003
d D 4.2 82/08/17 13:26:16 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00003/00000/00000
d D 4.1 80/10/09 23:58:38 bill 1 0
c date and time created 80/10/09 23:58:38 by bill
e
u
U
t
T
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";
#include <sys/param.h>
char		u[ctob(UPAGES)]; /* struct user u */
E 1
