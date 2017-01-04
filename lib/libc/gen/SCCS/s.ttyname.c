h18441
s 00002/00002/00049
d D 5.2 86/03/09 20:00:29 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00047
d D 5.1 85/06/05 12:40:48 mckusick 4 3
c Add copyright
e
s 00001/00001/00047
d D 4.3 82/05/07 20:38:54 mckusick 3 2
c update to new fs
e
s 00011/00013/00037
d D 4.2 82/03/30 13:16:03 mckusick 2 1
c convert to use new directory access routines
e
s 00050/00000/00000
d D 4.1 80/12/21 16:40:26 wnj 1 0
c date and time created 80/12/21 16:40:26 by wnj
e
u
U
t
T
I 1
D 4
/* %W% (Berkeley) %G% */
E 4
I 4
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5

E 4
/*
 * ttyname(f): return "/dev/ttyXX" which the the name of the
 * tty belonging to file f.
 *  NULL if it is not a tty
 */

#define	NULL	0
D 2
#include <sys/types.h>
#include <sys/dir.h>
E 2
I 2
#include <sys/param.h>
D 3
#include <sys/ndir.h>
E 3
I 3
#include <sys/dir.h>
E 3
E 2
#include <sys/stat.h>

static	char	dev[]	= "/dev/";
char	*strcpy();
char	*strcat();

char *
ttyname(f)
{
	struct stat fsb;
	struct stat tsb;
D 2
	struct direct db;
E 2
I 2
	register struct direct *db;
	register DIR *df;
E 2
	static char rbuf[32];
D 2
	register df;
E 2

	if (isatty(f)==0)
		return(NULL);
	if (fstat(f, &fsb) < 0)
		return(NULL);
	if ((fsb.st_mode&S_IFMT) != S_IFCHR)
		return(NULL);
D 2
	if ((df = open(dev, 0)) < 0)
E 2
I 2
	if ((df = opendir(dev)) == NULL)
E 2
		return(NULL);
D 2
	while (read(df, (char *)&db, sizeof(db)) == sizeof(db)) {
		if (db.d_ino == 0)
E 2
I 2
	while ((db = readdir(df)) != NULL) {
		if (db->d_ino != fsb.st_ino)
E 2
			continue;
D 2
		if (db.d_ino != fsb.st_ino)
			continue;
E 2
		strcpy(rbuf, dev);
D 2
		strcat(rbuf, db.d_name);
E 2
I 2
		strcat(rbuf, db->d_name);
E 2
		if (stat(rbuf, &tsb) < 0)
			continue;
D 2
		if (tsb.st_dev==fsb.st_dev && tsb.st_ino==fsb.st_ino) {
			close(df);
E 2
I 2
		if (tsb.st_dev == fsb.st_dev && tsb.st_ino == fsb.st_ino) {
			closedir(df);
E 2
			return(rbuf);
		}
	}
D 2
	close(df);
E 2
I 2
	closedir(df);
E 2
	return(NULL);
}
E 1
