h48362
s 00014/00003/00088
d D 5.3 88/06/18 15:12:26 bostic 6 5
c install approved copyright notice
e
s 00002/00002/00089
d D 5.2 86/03/09 19:54:39 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00084
d D 5.1 85/05/30 10:50:04 dist 4 3
c Add copyright
e
s 00004/00001/00081
d D 4.3 83/12/05 15:24:31 ralph 3 2
c arraysz not recomputed if overflow.
e
s 00005/00002/00077
d D 4.2 83/07/01 18:32:50 sam 2 1
c include fixes
e
s 00079/00000/00000
d D 4.1 82/12/13 10:43:38 ralph 1 0
c date and time created 82/12/13 10:43:38 by ralph
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 6
 */

E 4
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 5
#endif not lint
E 5
I 5
D 6
#endif LIBC_SCCS and not lint
E 6
I 6
#endif /* LIBC_SCCS and not lint */
E 6
E 5
E 4

E 2
/*
 * Scan the directory dirname calling select to make a list of selected
 * directory entries then sort using qsort and compare routine dcomp.
 * Returns the number of entries and a pointer to a list of pointers to
 * struct direct (through namelist). Returns -1 if there were any errors.
 */

#include <sys/types.h>
#include <sys/stat.h>
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 2

scandir(dirname, namelist, select, dcomp)
	char *dirname;
	struct direct *(*namelist[]);
	int (*select)(), (*dcomp)();
{
	register struct direct *d, *p, **names;
	register int nitems;
	register char *cp1, *cp2;
	struct stat stb;
	long arraysz;
	DIR *dirp;

	if ((dirp = opendir(dirname)) == NULL)
		return(-1);
	if (fstat(dirp->dd_fd, &stb) < 0)
		return(-1);

	/*
	 * estimate the array size by taking the size of the directory file
	 * and dividing it by a multiple of the minimum size entry. 
	 */
	arraysz = (stb.st_size / 24);
	names = (struct direct **)malloc(arraysz * sizeof(struct direct *));
	if (names == NULL)
		return(-1);

	nitems = 0;
	while ((d = readdir(dirp)) != NULL) {
		if (select != NULL && !(*select)(d))
			continue;	/* just selected names */
		/*
		 * Make a minimum size copy of the data
		 */
		p = (struct direct *)malloc(DIRSIZ(d));
		if (p == NULL)
			return(-1);
		p->d_ino = d->d_ino;
		p->d_reclen = d->d_reclen;
		p->d_namlen = d->d_namlen;
		for (cp1 = p->d_name, cp2 = d->d_name; *cp1++ = *cp2++; );
		/*
		 * Check to make sure the array has space left and
		 * realloc the maximum size.
		 */
		if (++nitems >= arraysz) {
I 3
			if (fstat(dirp->dd_fd, &stb) < 0)
				return(-1);	/* just might have grown */
			arraysz = stb.st_size / 12;
E 3
			names = (struct direct **)realloc((char *)names,
D 3
				(stb.st_size/12) * sizeof(struct direct *));
E 3
I 3
				arraysz * sizeof(struct direct *));
E 3
			if (names == NULL)
				return(-1);
		}
		names[nitems-1] = p;
	}
	closedir(dirp);
	if (nitems && dcomp != NULL)
		qsort(names, nitems, sizeof(struct direct *), dcomp);
	*namelist = names;
	return(nitems);
}

/*
 * Alphabetic order comparison routine for those who want it.
 */
alphasort(d1, d2)
	struct direct **d1, **d2;
{
	return(strcmp((*d1)->d_name, (*d2)->d_name));
}
E 1
