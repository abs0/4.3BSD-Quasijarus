h55429
s 00002/00000/00020
d D 1.2 88/12/22 13:13:56 sam 2 1
c use syscall for doing syswrite stuff -- more portable?
e
s 00020/00000/00000
d D 1.1 88/12/22 13:04:38 sam 1 0
c date and time created 88/12/22 13:04:38 by sam
e
u
U
t
T
I 1
# include "errno.h"
# include "../hdr/macros.h"
I 2
#include <sys/syscall.h>
#define	syswrite(a,b,c)	syscall(SYS_write,a,b,c)
E 2
SCCSID(@(#)write	2.1);

/*
	Interface to write(II) (called syswrite) which handles
	all error conditions.
	Returns number of bytes written on success,
	returns fatal(<mesg>) on failure.
*/

write(fildes,buffer,nbytes)
char *buffer;
{
	register int n;

	if (nbytes>0 && (n=syswrite(fildes,buffer,nbytes))!=nbytes)
		n = xmsg("","write");
	return(n);
}
E 1
