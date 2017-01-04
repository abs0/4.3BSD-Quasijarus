h46868
s 00008/00001/00034
d D 5.1 85/06/07 23:18:13 kre 6 5
c Add copyright
e
s 00006/00001/00029
d D 1.5 83/04/30 16:53:28 dlw 5 4
c changed to use MAXPATHLEN. DLW
e
s 00007/00102/00023
d D 1.4 83/01/31 22:26:14 dlw 4 3
c adapted to 4.2BSD. DLW
e
s 00007/00002/00118
d D 1.3 81/06/15 21:42:22 dlw 3 2
c fixed case of "/". DLW
e
s 00001/00001/00119
d D 1.2 81/04/21 14:16:15 dlw 2 1
c fixed declaration for 'len'. DLW
e
s 00120/00000/00000
d D 1.1 81/04/19 16:11:53 dlw 1 0
c date and time created 81/04/19 16:11:53 by dlw
e
u
U
t
T
I 1
D 4
/** F77 NOTE: the getcwd() routine should be in libc.a ! **/
E 4
/*
D 4
 * return name of working (current) directory
 */
#include	<stdio.h>
#include	<sys/param.h>
#include	<sys/stat.h>
#include	<sys/dir.h>

I 3
static char	slash[]	= "/";
E 3
static char	dot[]	= ".";
static char	dotdot[] = "..";
static char	name[128];

char *
getcwd()
{
	int	rdev, rino;
	int	fd;
	struct	stat	d, dd;
	struct	direct	dir;
	char	*prepend();
	char	*namep = &name[(sizeof name)-1];

	*namep = '\0';
D 3
	stat("/", &d);
E 3
I 3
	stat(slash, &d);
E 3
	rdev = d.st_dev;
	rino = d.st_ino;
	for (;;)
	{
		stat(dot, &d);
		if (d.st_ino == rino && d.st_dev == rdev)
		{
I 3
			if (*namep == '\0')	/* rootdir is a special case */
				namep = prepend(namep, slash);
E 3
			chdir(namep);
			return(namep);
		}
		if ((fd = open(dotdot,0)) < 0)
		{
			chdir(prepend(namep, dot));
			return((char *)0);
		}
		chdir(dotdot);
		fstat(fd, &dd);
		if(d.st_dev == dd.st_dev)
		{
			if(d.st_ino == dd.st_ino)
			{
				close(fd);
I 3
				if (*namep == '\0') /* root is a special case */
					namep = prepend(namep, slash);
E 3
				chdir(namep);
				return(namep);
			}
			do
			{
				if (read(fd, (char *)&dir, sizeof(dir)) < sizeof(dir))
				{
					close(fd);
					chdir(prepend(namep, dot));
					return((char *)0);
				}
			} while (dir.d_ino != d.st_ino);
		}
		else do
		{
				if(read(fd, (char *)&dir, sizeof(dir)) < sizeof(dir))
				{
					close(fd);
					chdir(prepend(namep, dot));
					return((char *)0);
				}
				stat(dir.d_name, &dd);
			} while(dd.st_ino != d.st_ino || dd.st_dev != d.st_dev);
		close(fd);
D 3
		namep = prepend(prepend(namep, dir.d_name), "/");
E 3
I 3
		namep = prepend(prepend(namep, dir.d_name), slash);
E 3
	}
}

char *
prepend(p, n)
char *p;
char *n;
{
	int i = 0;

	while (i < DIRSIZ && *n)
	{
		n++; i++;
	}
	while (i--)
		*--p = *--n;
	return(p);
}

/*
E 4
D 6
char id_getcwd[] = "%W%";
E 6
I 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
 */

/*
E 6
 * Get pathname of current working directory.
 *
 * calling sequence:
 *	character*128 path
 *	ierr = getcwd(path)
 * where:
 *	path will receive the pathname of the current working directory.
 *	ierr will be 0 if successful, a system error code otherwise.
 */

I 5
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif

E 5
extern int errno;
I 4
char	*getwd();
E 4

long
getcwd_(path, len)
char *path;
D 2
int len;
E 2
I 2
long len;
E 2
{
D 4
	char *p;
E 4
I 4
	char	*p;
D 5
	char	pathname[1024];
E 5
I 5
	char	pathname[MAXPATHLEN];
E 5
E 4

D 4
	p = getcwd();
E 4
I 4
	p = getwd(pathname);
	b_char(pathname, path, len);
E 4
	if (p)
D 4
	{
		b_char(p, path, len);
E 4
		return(0L);
D 4
	}
	return((long)errno);
E 4
I 4
	else
		return((long)errno);
E 4
}
E 1
