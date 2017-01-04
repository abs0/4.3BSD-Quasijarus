h31632
s 00016/00001/00019
d D 5.1 85/04/30 15:05:10 dist 5 4
c Add copyright
e
s 00008/00068/00012
d D 4.4 83/01/05 15:40:10 sam 4 3
c use getwd from libc now
e
s 00001/00001/00079
d D 4.3 82/05/07 16:22:08 mckusick 3 2
c update to new fs
e
s 00015/00016/00065
d D 4.2 82/02/12 00:51:23 mckusic 2 1
c convert to use library routines to access directories
e
s 00081/00000/00000
d D 4.1 80/10/01 17:28:00 bill 1 0
c date and time created 80/10/01 17:28:00 by bill
e
u
U
t
T
I 1
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 5
/*
 * Print working (current) directory
 */
D 4
#include	<stdio.h>
#include	<sys/param.h>
#include	<sys/stat.h>
D 2
#include	<sys/dir.h>
E 2
I 2
D 3
#include	<ndir.h>
E 3
I 3
#include	<dir.h>
E 4
I 4
#include <stdio.h>
#include <sys/param.h>
E 4
E 3
E 2

D 4
char	dot[]	= ".";
char	dotdot[] = "..";
char	name[BUFSIZ];
D 2
int	file;
E 2
I 2
DIR	*file;
E 2
int	off	= -1;
struct	stat	d, dd;
D 2
struct	direct	dir;
E 2
I 2
struct	direct	*dir;
E 4
I 4
char *getwd();
E 4
E 2

main()
{
D 4
	int rdev, rino;
E 4
I 4
	char pathname[MAXPATHLEN + 1];
E 4

D 4
	stat("/", &d);
	rdev = d.st_dev;
	rino = d.st_ino;
	for (;;) {
		stat(dot, &d);
		if (d.st_ino==rino && d.st_dev==rdev)
			prname();
D 2
		if ((file = open(dotdot,0)) < 0) {
E 2
I 2
		if ((file = opendir(dotdot)) == NULL) {
E 2
			fprintf(stderr,"pwd: cannot open ..\n");
			exit(1);
		}
D 2
		fstat(file, &dd);
E 2
I 2
		fstat(file->dd_fd, &dd);
E 2
		chdir(dotdot);
		if(d.st_dev == dd.st_dev) {
			if(d.st_ino == dd.st_ino)
				prname();
			do
D 2
				if (read(file, (char *)&dir, sizeof(dir)) < sizeof(dir)) {
E 2
I 2
				if ((dir = readdir(file)) == NULL) {
E 2
					fprintf(stderr,"read error in ..\n");
					exit(1);
				}
D 2
			while (dir.d_ino != d.st_ino);
		}
		else do {
				if(read(file, (char *)&dir, sizeof(dir)) < sizeof(dir)) {
E 2
I 2
			while (dir->d_ino != d.st_ino);
		} else
			do {
				if ((dir = readdir(file)) == NULL) {
E 2
					fprintf(stderr,"read error in ..\n");
					exit(1);
				}
D 2
				stat(dir.d_name, &dd);
E 2
I 2
				stat(dir->d_name, &dd);
E 2
			} while(dd.st_ino != d.st_ino || dd.st_dev != d.st_dev);
D 2
		close(file);
E 2
I 2
		closedir(file);
E 2
		cat();
E 4
I 4
	if (getwd(pathname) == NULL) {
		fprintf(stderr, "pwd: %s\n", pathname);
		exit(1);
E 4
	}
D 4
}

prname()
{
	write(1, "/", 1);
	if (off<0)
		off = 0;
	name[off] = '\n';
	write(1, name, off+1);
E 4
I 4
	printf("%s\n", pathname);
E 4
	exit(0);
D 4
}

cat()
{
	register i, j;

D 2
	i = -1;
	while (dir.d_name[++i] != 0);
	if ((off+i+2) > BUFSIZ-1)
E 2
I 2
	i = dir->d_namlen;
	if ((off + dir->d_namlen + 2) > BUFSIZ-1)
E 2
		prname();
	for(j=off+1; j>=0; --j)
		name[j+i+1] = name[j];
	off=i+off+1;
	name[i] = '/';
	for(--i; i>=0; --i)
D 2
		name[i] = dir.d_name[i];
E 2
I 2
		name[i] = dir->d_name[i];
E 4
E 2
}
E 1
