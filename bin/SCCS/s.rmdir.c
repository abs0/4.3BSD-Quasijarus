h60195
s 00016/00001/00023
d D 5.1 85/04/30 15:05:14 dist 9 8
c Add copyright
e
s 00001/00001/00023
d D 4.8 85/01/31 14:02:12 serge 8 7
c reasonable error message
e
s 00001/00000/00023
d D 4.7 82/12/19 13:07:28 sam 7 6
c label perror's
e
s 00010/00104/00013
d D 4.6 82/12/19 13:06:05 sam 6 5
c use sys call
e
s 00001/00001/00116
d D 4.5 82/05/07 16:26:37 mckusick 5 4
c update to new fs
e
s 00001/00001/00116
d D 4.4 82/03/31 21:56:04 mckusic 4 3
c change <sys/types.h> to <sys/param.h> for benefit of <ndir.h>
e
s 00010/00010/00107
d D 4.3 82/02/19 17:37:09 mckusic 3 2
c convert to new directory structure
e
s 00017/00005/00100
d D 4.2 80/11/10 22:28:50 bill 2 1
c fixes per presotto
e
s 00105/00000/00000
d D 4.1 80/10/01 17:28:17 bill 1 0
c date and time created 80/10/01 17:28:17 by bill
e
u
U
t
T
I 1
D 9
static char *sccsid = "%W% (Berkeley) %G%";
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 9
/*
 * Remove directory
 */
D 6

D 4
#include <sys/types.h>
E 4
I 4
#include <sys/param.h>
E 4
D 3
#include <sys/dir.h>
E 3
#include <sys/stat.h>
I 3
D 5
#include <ndir.h>
E 5
I 5
#include <dir.h>
E 6
E 5
E 3
#include <stdio.h>

D 6
int	Errors = 0;
char	*rindex();
char	*strcat();
char	*strcpy();

E 6
main(argc,argv)
D 6
int argc;
char **argv;
E 6
I 6
	int argc;
	char **argv;
E 6
{
I 6
	int errors = 0;
E 6

D 6
	if(argc < 2) {
E 6
I 6
	if (argc < 2) {
E 6
D 8
		fprintf(stderr, "rmdir: arg count\n");
E 8
I 8
		fprintf(stderr, "usage: %s directory ...\n", argv[0]);
E 8
		exit(1);
	}
D 6
	while(--argc)
		rmdir(*++argv);
	exit(Errors!=0);
}

rmdir(d)
char *d;
{
D 3
	int	fd;
	char	*np, name[500];
E 3
I 3
	char	*np, name[BUFSIZ];
E 3
	struct	stat	st, cst;
D 3
	struct	direct	dir;
E 3
I 3
	struct	direct	*dp;
	DIR	*dirp;
E 3

	strcpy(name, d);
I 2

	/* eat trailing slashes */
	np = &(name[strlen(name)-1]);
	while (*np == '/' && np != name) {
		*np = '\0';
		np--;
	}

	/* point after last slash */
E 2
	if((np = rindex(name, '/')) == NULL)
		np = name;
I 2
	else
		np++;

	if(!strcmp(np, ".") || !strcmp(np, "..")) {
		fprintf(stderr, "rmdir: cannot remove . or ..\n");
		++Errors;
		return;
	}
E 2
	if(stat(name,&st) < 0) {
		fprintf(stderr, "rmdir: %s non-existent\n", name);
		++Errors;
		return;
	}
	if (stat("", &cst) < 0) {
		fprintf(stderr, "rmdir: cannot stat \"\"");
		++Errors;
		exit(1);
	}
	if((st.st_mode & S_IFMT) != S_IFDIR) {
		fprintf(stderr, "rmdir: %s not a directory\n", name);
		++Errors;
		return;
	}
	if(st.st_ino==cst.st_ino &&st.st_dev==cst.st_dev) {
		fprintf(stderr, "rmdir: cannot remove current directory\n");
		++Errors;
		return;
	}
D 3
	if((fd = open(name,0)) < 0) {
E 3
I 3
	if((dirp = opendir(name)) == NULL) {
E 3
		fprintf(stderr, "rmdir: %s unreadable\n", name);
		++Errors;
		return;
	}
D 3
	while(read(fd, (char *)&dir, sizeof dir) == sizeof dir) {
		if(dir.d_ino == 0) continue;
		if(!strcmp(dir.d_name, ".") || !strcmp(dir.d_name, ".."))
E 3
I 3
	while((dp = readdir(dirp)) != NULL) {
		if(dp->d_ino == 0) continue;
		if(!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
E 3
			continue;
		fprintf(stderr, "rmdir: %s not empty\n", name);
		++Errors;
D 3
		close(fd);
E 3
I 3
		closedir(dirp);
E 3
		return;
	}
D 3
	close(fd);
E 3
I 3
	closedir(dirp);
E 3
D 2
	if(!strcmp(np, ".") || !strcmp(np, "..")) {
		fprintf(stderr, "rmdir: cannot remove . or ..\n");
		++Errors;
		return;
	}
E 2
	strcat(name, "/.");
	if((access(name, 0)) < 0) {		/* name/. non-existent */
		strcat(name, ".");
		goto unl;
	}
	strcat(name, ".");
	if((access(name, 0)) < 0)		/* name/.. non-existent */
		goto unl2;
	if(access(name, 02)) {
		name[strlen(name)-3] = '\0';
		fprintf(stderr, "rmdir: %s: no permission\n", name);
		++Errors;
		return;
	}
unl:
	unlink(name);	/* unlink name/.. */
unl2:
	name[strlen(name)-1] = '\0';
	unlink(name);	/* unlink name/.  */
	name[strlen(name)-2] = '\0';
	if (unlink(name) < 0) {
		fprintf(stderr, "rmdir: %s not removed\n", name);
		++Errors;
	}
E 6
I 6
	while (--argc)
		if (rmdir(*++argv) < 0) {
I 7
			fprintf(stderr, "rmdir: ");
E 7
			perror(*argv);;
			errors++;
		}
	exit(errors != 0);
E 6
}
E 1
