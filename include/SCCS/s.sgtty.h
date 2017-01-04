h48603
s 00000/00015/00005
d D 4.2 85/01/03 10:53:35 bloom 3 1
c get rid of circular dependencies
e
s 00004/00000/00020
d R 4.2 84/12/31 13:15:53 bloom 2 1
c ioctl.h now requires types.h
e
s 00020/00000/00000
d D 4.1 83/05/03 13:48:16 sam 1 0
c date and time created 83/05/03 13:48:16 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

D 3
/*
 * Structure for stty and gtty system calls.
 */

E 3
#ifndef	_IOCTL_
#include <sys/ioctl.h>
D 3
#endif

#ifndef _SGTTYB_
#define	_SGTTYB_
struct sgttyb {
	char	sg_ispeed;		/* input speed */
	char	sg_ospeed;		/* output speed */
	char	sg_erase;		/* erase character */
	char	sg_kill;		/* kill character */
	short	sg_flags;		/* mode flags */
};
E 3
#endif
E 1
