h22770
s 00003/00001/00029
d D 1.3 88/12/22 12:57:21 sam 3 2
c purge uses of alloca
e
s 00004/00002/00026
d D 1.2 88/02/02 15:57:25 bostic 2 1
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00028/00000/00000
d D 1.1 88/02/02 15:45:55 bostic 1 0
c date and time created 88/02/02 15:45:55 by bostic
e
u
U
t
T
I 1
# include	"../hdr/macros.h"
SCCSID(@(#)xcreat	2.1);

/*
	"Sensible" creat: write permission in directory is required in
	all cases, and created file is guaranteed to have specified mode
	and be owned by effective user.
	(It does this by first unlinking the file to be created.)
	Returns file descriptor on success,
	fatal() on failure.
*/

xcreat(name,mode)
char *name;
int mode;
{
	register int fd;
	register char *d;

D 3
	d = alloca(size(name));
E 3
I 3
	d = alloc(size(name));
E 3
	copy(name,d);
D 2
	if (!exists(dname(d)))
		fatal(sprintf(Error,"directory `%s' nonexistent (ut1)",d));
E 2
I 2
	if (!exists(dname(d))) {
I 3
		free(d);
E 3
		sprintf(Error,"directory `%s' nonexistent (ut1)",d);
		fatal(Error);
	}
I 3
	free(d);
E 3
E 2
	unlink(name);
	if ((fd = creat(name,mode)) >= 0)
		return(fd);
	return(xmsg(name,"xcreat"));
}
E 1
