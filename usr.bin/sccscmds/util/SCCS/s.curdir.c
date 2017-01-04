h07182
s 00002/00001/00086
d D 4.5 82/05/08 19:19:15 sam 5 4
c initialize on each entry
e
s 00074/00097/00013
d D 4.4 82/05/07 11:42:00 sam 4 3
c new version (modded for new directory format) take from csh
e
s 00002/00000/00108
d D 4.3 82/03/14 21:39:44 eric 3 2
c remember to close some files....  stupid stupid
e
s 00008/00006/00100
d D 4.2 81/02/05 17:58:27 eric 2 1
c fix for a real system
e
s 00106/00000/00000
d D 4.1 81/02/05 17:33:39 eric 1 0
c date and time created 81/02/05 17:33:39 by eric
e
u
U
t
T
I 1
D 4
# include	"../hdr/macros.h"
# include	"dir.h"
I 2

E 2
#define IROOT 2
SCCSID(%W%);
E 4
/*
D 4
	current directory.
	Places the full pathname of the current directory in `str'.
	Handles file systems not mounted on a root directory
	via /etc/mtab (see mtab(V)).
	NOTE: PWB systems don't use mtab(V), but they don't mount
	file systems anywhere but on a root directory (so far, at least).
E 4
I 4
 * SCCSID(%W%);
 */
#include	<sys/param.h>
#include	<sys/stat.h>
#include	<sys/dir.h>
E 4

D 4
	returns 0 on success
	< 0 on failure.
E 4
I 4
#define	dot	"."
#define	dotdot	".."
E 4

D 4
	Current directory on return:
		success: same as on entry
		failure: UNKNOWN!
*/
E 4
I 4
static	char	*name;
E 4

I 4
D 5
static	int	off	= -1;
E 5
I 5
static	int	off;
E 5
static	struct	stat	d, dd;
static	struct	direct	*dir;
static	DIR	*dirp;
static	int	cat(), prexit();
E 4

D 4
static char *curdirp;
E 4
I 4
char *
curdir(np)
char *np;
{
	int rdev, rino;
E 4

I 5
	off = -1;
E 5
D 4
struct mtab {
D 2
	char	m_devstr[6];
	char	m_spcl[32];
E 2
	char	m_dir[32];
I 2
	char	m_spcl[32];
E 2
};
E 4
I 4
	*np++ = '/';
	name = np;
	stat("/", &d);
	rdev = d.st_dev;
	rino = d.st_ino;
	for (;;) {
		stat(dot, &d);
		if (d.st_ino==rino && d.st_dev==rdev)
			goto done;
		if ((dirp = opendir(dotdot)) == 0)
			prexit("curdir: cannot open ..\n");
		fstat(dirp->dd_fd, &dd);
		chdir(dotdot);
		if(d.st_dev == dd.st_dev) {
			if(d.st_ino == dd.st_ino)
				goto done;
			do
				if ((dir = readdir(dirp)) == 0)
					prexit("curdir: read error in ..\n");
			while (dir->d_ino != d.st_ino);
		} else
			do {
				if ((dir = readdir(dirp)) == 0)
					prexit("curdir: read error in ..\n");
				stat(dir->d_name, &dd);
			} while(dd.st_ino != d.st_ino || dd.st_dev != d.st_dev);
		closedir(dirp);
		cat();
	}
done:
	name--;
	if (chdir(name) < 0) {
		write(2, name, strlen(name));
		prexit(": can't change back\n");
	}
	return (0);
}
E 4

D 4
static struct mtab mtab;

curdir(str)
char *str;
E 4
I 4
static
cat()
E 4
{
D 4
	register int n;
E 4
I 4
	register i, j;
E 4

D 2
	copy("/dev//",mtab.m_devstr);
E 2
D 4
	curdirp = str;
	n = findir(0);
	return(n+chdir(str));
E 4
I 4
	i = dir->d_namlen;
	if ((off+i+2) > 1024-1)
		return;
	for(j=off+1; j>=0; --j)
		name[j+i+1] = name[j];
	if (off >= 0)
		name[i] = '/';
	off += i+1;
	name[off] = 0;
	for(--i; i>=0; --i)
		name[i] = dir->d_name[i];
E 4
}

D 4

# define ADDSLASH	if (flag) *curdirp++ = '/';
# define QUIT		{ close(fd); return(-1); }

findir(flag)
E 4
I 4
static
prexit(cp)
char *cp;
E 4
{
D 4
	register int fd,inum;
	register char *tp;
	char *slashp;
	int dev, r;
	struct dir entry;
	struct stat s;

	if (stat(".",&s)<0) return(-1);
	if ((inum = s.st_ino) == IROOT) {
		dev = s.st_dev;
		if ((fd = open("/",0))<0) return(-1);
		if (fstat(fd,&s)<0)
			QUIT;
		if (dev == s.st_dev) {
			*curdirp++ = '/';
			*curdirp = 0;
			close(fd);
			return(0);
		}
		slashp = entry.d_name;
		slashp--;
		while (read(fd,&entry,sizeof(entry)) == sizeof(entry)) {
			if (entry.d_ino == 0) continue;
			*slashp = '/';
			if (stat(slashp,&s)<0) continue;
			if (s.st_dev != dev) continue;
			if ((s.st_mode&S_IFMT) != S_IFDIR) continue;
			for (tp = slashp; *curdirp = (*tp++); curdirp++);
			ADDSLASH;
			*curdirp = 0;
			close(fd);
			return(0);
		}
I 3
		close(fd);
E 3
		if ((fd = open("/etc/mtab", 0))<0) return(-1);
D 2
		while (read(fd,mtab.m_spcl,64) == 64) {
			if (stat(mtab.m_devstr,&s)<0)
				QUIT;
E 2
I 2
		while (read(fd,&mtab,64) == 64) {
			char devstr[40];
			strcpy(devstr, "/dev/");
			strcat(devstr, mtab.m_spcl);
			if (stat(devstr,&s)<0)
				continue;
E 2
			if (s.st_rdev != dev) continue;
			for (tp = mtab.m_dir; *curdirp = *tp++; curdirp++);
			ADDSLASH;
			*curdirp = 0;
I 3
			close(fd);
E 3
			return(0);
		}
		QUIT;
	}
	if ((fd = open("..",0))<0) return(-1);
	for (entry.d_ino = 0; entry.d_ino != inum; )
		if (read(fd,&entry,sizeof(entry)) != sizeof(entry))
			QUIT;
	close(fd);
	if (chdir("..")<0) return(-1);
	if (findir(-1)<0) r = -1;
	else r = 0;
	for (tp = entry.d_name; *curdirp = (*tp++); curdirp++);
	ADDSLASH;
	*curdirp = 0;
	return(r);
E 4
I 4
	write(2, cp, strlen(cp));
	exit(1);
E 4
}
E 1
