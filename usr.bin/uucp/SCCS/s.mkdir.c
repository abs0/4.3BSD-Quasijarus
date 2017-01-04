h55369
s 00003/00001/00027
d D 5.2 85/06/20 10:03:59 bloom 2 1
c fixes from rick adams
e
s 00028/00000/00000
d D 5.1 85/03/22 09:03:14 ralph 1 0
c date and time created 85/03/22 09:03:14 by ralph
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#ifndef BSD4_2
#include <stdio.h>
I 2

E 2
/*
 * make a directory. Also make sure that the directory is owned
 * by the right userid
 */
mkdir(path, mode)
char *path;
int mode;
{
	int pid, status, w;

	if (pid=fork()) {
		while ((w = wait(&status)) != pid && w != -1)
			;
		(void) chmod(path, mode);
	} else {
D 2
		(void) umask(mode);
E 2
I 2
		(void) umask(~mode);
E 2
		(void) execlp("mkdir", "mkdir", path, (char *)NULL);
		perror(path);
		_exit(1);
	}
I 2
	return status;
E 2
}
#endif !BSD4_2
E 1
