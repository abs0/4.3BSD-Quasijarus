#ifndef lint
static char sccsid[] = "@(#)recurse.c	1.2 (Berkeley) 2012/03/03";
#endif

#include <sys/param.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <stdio.h>
#include <strings.h>

extern char *malloc();

extern int recurse_symlinks;
extern int retcode;

recurse(pathname, cmdline)
	char *pathname;
{
	struct stat st;
	register int s;

	if (cmdline || recurse_symlinks)
		s = stat(pathname, &st);
	else
		s = lstat(pathname, &st);
	if (s < 0) {
		fprintf(stderr, "%s: can't stat\n", pathname);
		retcode = 2;
		return;
	}
	switch (st.st_mode & S_IFMT) {
	case S_IFREG:
		execute(pathname);
		return;
	case S_IFDIR:
		recurse_dir(pathname);
		return;
	case S_IFLNK:
		if (cmdline || recurse_symlinks) {
			fprintf(stderr, "%s: bad symlink\n", pathname);
			retcode = 2;
		}
		return;
	default:
		fprintf(stderr, "%s: neither regular file nor directory\n",
			pathname);
		retcode = 2;
	}
}

recurse_dir(dirpath)
	char *dirpath;
{
	DIR *reader;
	char *pathbuf, *newpart;
	register struct direct *entry;

	reader = opendir(dirpath);
	if (!reader) {
		fprintf(stderr, "%s: can't read directory\n", dirpath);
		retcode = 2;
		return;
	}
	pathbuf = malloc(strlen(dirpath) + MAXNAMLEN + 2);
	if (!pathbuf) {
		fprintf(stderr, "%s: can't malloc buffer for recursion\n",
			dirpath);
		closedir(reader);
		retcode = 2;
		return;
	}
	strcpy(pathbuf, dirpath);
	newpart = index(pathbuf, '\0');
	*newpart++ = '/';
	while (entry = readdir(reader)) {
		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
			continue;
		strcpy(newpart, entry->d_name);
		recurse(pathbuf, 0);
	}
	closedir(reader);
	free(pathbuf);
}
