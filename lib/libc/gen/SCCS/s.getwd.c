h45672
s 00002/00002/00112
d D 5.2 86/03/09 19:49:27 donn 13 12
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00105
d D 5.1 85/05/30 10:43:35 dist 12 11
c Add copyright
e
s 00034/00036/00072
d D 4.10 85/01/24 16:50:30 ralph 11 10
c modified to not call chdir(). Also, uses fewer stat()'s.
e
s 00001/00001/00107
d D 4.9 84/12/09 02:55:30 lepreau 10 9
c report real path even if a symlink to a root dir comes first
e
s 00001/00000/00107
d D 4.8 83/03/02 09:46:49 nicklin 9 8
c declared char *strcpy();
e
s 00002/00003/00105
d D 4.7 83/01/05 15:01:55 sam 8 7
c use MAXPATHLEN from <sys/param.h>
e
s 00079/00055/00029
d D 4.6 83/01/05 14:57:07 sam 7 6
c new version from nicklin -- bugs to him
e
s 00004/00003/00080
d D 4.5 83/01/04 20:51:23 sam 6 4
c make error messages returned legible
e
s 00001/00001/00082
d R 4.5 83/01/04 14:57:31 sam 5 4
c screwed up last time
e
s 00007/00012/00076
d D 4.4 83/01/04 14:42:04 sam 4 3
c don't abort, just return error in buff and NULL value
e
s 00006/00005/00082
d D 4.3 83/01/04 14:32:01 sam 3 2
c missing check on chdir
e
s 00012/00010/00075
d D 4.2 83/01/02 16:41:22 sam 2 1
c make it callable multiple times (from sun)
e
s 00085/00000/00000
d D 4.1 82/12/28 15:19:43 sam 1 0
c date and time created 82/12/28 15:19:43 by sam
e
u
U
t
T
I 1
D 12
/*	%W%	(Berkeley)	%G%	*/
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 13
#ifndef lint
E 13
I 13
#if defined(LIBC_SCCS) && !defined(lint)
E 13
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif not lint
E 13
I 13
#endif LIBC_SCCS and not lint
E 13
E 12

/*
D 7
 * Getwd
E 7
I 7
 * getwd() returns the pathname of the current working directory. On error
 * an error message is copied to pathname and null pointer is returned.
E 7
 */
D 2
#include	<sys/param.h>
#include	<sys/stat.h>
#include	<sys/dir.h>
E 2
I 2
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/dir.h>
E 2

D 7
#define	dot	"."
#define	dotdot	".."
E 7
I 7
D 11
#define CURDIR		"."
E 11
#define GETWDERR(s)	strcpy(pathname, (s));
D 11
#define PARENTDIR	".."
#define PATHSEP		"/"
D 8
#define PATHSIZE	1024
E 8
#define ROOTDIR		"/"
E 11
E 7

I 9
char *strcpy();
E 9
I 4
D 6
#define	prexit(s)	{ strcpy(np, s); return (NULL); }
E 6
I 6
D 7
#define	prexit(s)	 { strcpy(esave, (s)); return (NULL); }
E 7
I 7
static int pathsize;			/* pathname length */
E 7
E 6

E 4
D 2
static	char	*name;
E 2
I 2
D 7
static	char *name;
E 2

D 2
static	DIR	*file;
static	int	off	= -1;
static	struct	stat	d, dd;
static	struct	direct	*dir;
E 2
I 2
static	DIR *file;
static	int off;
static	struct stat d, dd;
static	struct direct *dir;
E 2

E 7
char *
D 7
getwd(np)
D 2
char *np;
E 2
I 2
	char *np;
E 7
I 7
getwd(pathname)
	char *pathname;
E 7
E 2
{
D 2
	int rdev, rino;
E 2
I 2
D 7
	dev_t rdev;
	ino_t rino;
I 6
	char *esave = np;
E 7
I 7
D 8
	char pathbuf[PATHSIZE];		/* temporary pathname buffer */
E 8
I 8
	char pathbuf[MAXPATHLEN];		/* temporary pathname buffer */
E 8
	char *pnptr = &pathbuf[(sizeof pathbuf)-1]; /* pathname pointer */
I 11
	char curdir[MAXPATHLEN];	/* current directory buffer */
	char *dptr = curdir;		/* directory pointer */
E 11
	char *prepend();		/* prepend dirname to pathname */
D 11
	dev_t rdev;			/* root device number */
E 11
I 11
	dev_t cdev, rdev;		/* current & root device number */
	ino_t cino, rino;		/* current & root inode number */
E 11
	DIR *dirp;			/* directory stream */
D 11
	ino_t rino;			/* root inode number */
E 11
	struct direct *dir;		/* directory entry struct */
D 11
	struct stat d ,dd;		/* file status struct */
E 11
I 11
	struct stat d, dd;		/* file status struct */
E 11
E 7
E 6
E 2

I 2
D 7
	off = -1;
E 2
	*np++ = '/';
	name = np;
	stat("/", &d);
E 7
I 7
	pathsize = 0;
	*pnptr = '\0';
D 11
	stat(ROOTDIR, &d);
E 11
I 11
	if (stat("/", &d) < 0) {
		GETWDERR("getwd: can't stat /");
		return (NULL);
	}
E 11
E 7
	rdev = d.st_dev;
	rino = d.st_ino;
I 11
	strcpy(dptr, "./");
	dptr += 2;
	if (stat(curdir, &d) < 0) {
		GETWDERR("getwd: can't stat .");
		return (NULL);
	}
E 11
	for (;;) {
D 7
		stat(dot, &d);
		if (d.st_ino==rino && d.st_dev==rdev)
			goto done;
		if ((file = opendir(dotdot)) == NULL)
D 4
			prexit("getwd: cannot open ..\n");
E 4
I 4
			prexit("getwd: cannot open ..");
E 4
		fstat(file->dd_fd, &dd);
D 3
		chdir(dotdot);
		if(d.st_dev == dd.st_dev) {
E 3
I 3
		if (chdir(dotdot) < 0)
D 4
			prexit("getwd: cannot chdir to ..\n");
E 4
I 4
			prexit("getwd: cannot chdir to ..");
E 7
I 7
D 11
		stat(CURDIR, &d);
E 11
		if (d.st_ino == rino && d.st_dev == rdev)
			break;		/* reached root directory */
D 11
		if ((dirp = opendir(PARENTDIR)) == NULL) {
E 11
I 11
		cino = d.st_ino;
		cdev = d.st_dev;
		strcpy(dptr, "../");
		dptr += 3;
		if ((dirp = opendir(curdir)) == NULL) {
E 11
			GETWDERR("getwd: can't open ..");
D 11
			goto fail;
E 11
I 11
			return (NULL);
E 11
		}
D 11
		if (chdir(PARENTDIR) < 0) {
			GETWDERR("getwd: can't chdir to ..");
			goto fail;
		}
		fstat(dirp->dd_fd, &dd);
E 7
E 4
		if (d.st_dev == dd.st_dev) {
E 3
D 7
			if(d.st_ino == dd.st_ino)
				goto done;
E 7
I 7
			if (d.st_ino == dd.st_ino) {
E 11
I 11
		fstat(dirp->dd_fd, &d);
		if (cdev == d.st_dev) {
			if (cino == d.st_ino) {
E 11
				/* reached root directory */
				closedir(dirp);
				break;
			}
E 7
D 6
			do
E 6
I 6
			do {
E 6
D 7
				if ((dir = readdir(file)) == NULL)
D 4
					prexit("getwd: read error in ..\n");
E 4
I 4
					prexit("getwd: read error in ..");
E 7
I 7
				if ((dir = readdir(dirp)) == NULL) {
					closedir(dirp);
					GETWDERR("getwd: read error in ..");
D 11
					goto fail;
E 11
I 11
					return (NULL);
E 11
				}
E 7
E 4
D 6
			while (dir->d_ino != d.st_ino);
E 6
I 6
D 11
			} while (dir->d_ino != d.st_ino);
E 11
I 11
			} while (dir->d_ino != cino);
E 11
E 6
D 3
		}
		else do {
E 3
I 3
		} else
			do {
E 3
D 7
				if ((dir = readdir(file)) == NULL)
D 4
					prexit("getwd: read error in ..\n");
E 4
I 4
					prexit("getwd: read error in ..");
E 7
I 7
D 11
				if((dir = readdir(dirp)) == NULL) {
E 11
I 11
				if ((dir = readdir(dirp)) == NULL) {
E 11
					closedir(dirp);
					GETWDERR("getwd: read error in ..");
D 11
					goto fail;
E 11
I 11
					return (NULL);
E 11
				}
E 7
E 4
D 10
				stat(dir->d_name, &dd);
E 10
I 10
D 11
				lstat(dir->d_name, &dd);
E 10
			} while(dd.st_ino != d.st_ino || dd.st_dev != d.st_dev);
E 11
I 11
				strcpy(dptr, dir->d_name);
				lstat(curdir, &dd);
			} while(dd.st_ino != cino || dd.st_dev != cdev);
E 11
D 7
		closedir(file);
		cat();
E 7
I 7
		closedir(dirp);
D 11
		pnptr = prepend(PATHSEP, prepend(dir->d_name, pnptr));
E 11
I 11
		pnptr = prepend("/", prepend(dir->d_name, pnptr));
E 11
E 7
	}
D 7
done:
	name--;
	if (chdir(name) < 0)
D 4
		prexit("getwd: can't change back\n");
E 4
I 4
		prexit("getwd: can't change back");
E 4
	return (name);
E 7
I 7
	if (*pnptr == '\0')		/* current dir == root dir */
D 11
		strcpy(pathname, ROOTDIR);
	else {
E 11
I 11
		strcpy(pathname, "/");
	else
E 11
		strcpy(pathname, pnptr);
D 11
		if (chdir(pnptr) < 0) {
			GETWDERR("getwd: can't change back to .");
			return (NULL);
		}
	}
E 11
	return (pathname);
D 11

fail:
	chdir(prepend(CURDIR, pnptr));
	return (NULL);
E 11
E 7
}

D 7
cat()
E 7
I 7
/*
 * prepend() tacks a directory name onto the front of a pathname.
 */
static char *
prepend(dirname, pathname)
	register char *dirname;
	register char *pathname;
E 7
{
D 7
	register i, j;
E 7
I 7
	register int i;			/* directory name size counter */
E 7

D 7
	i = -1;
	while (dir->d_name[++i] != 0);
	if ((off+i+2) > 1024-1)
		return;
	for(j=off+1; j>=0; --j)
		name[j+i+1] = name[j];
	if (off >= 0)
		name[i] = '/';
	off=i+off+1;
	name[off] = 0;
	for(--i; i>=0; --i)
		name[i] = dir->d_name[i];
E 7
I 7
	for (i = 0; *dirname != '\0'; i++, dirname++)
		continue;
D 8
	if ((pathsize += i) < PATHSIZE)
E 8
I 8
	if ((pathsize += i) < MAXPATHLEN)
E 8
		while (i-- > 0)
			*--pathname = *--dirname;
	return (pathname);
E 7
D 4
}

prexit(cp)
D 3
char *cp;
E 3
I 3
	char *cp;
E 3
{
	write(2, cp, strlen(cp));
	exit(1);
E 4
}
E 1
