h63210
s 00001/00001/00161
d D 4.12 87/10/22 09:49:17 bostic 12 11
c ANSI C; sprintf now returns an int.
e
s 00000/00000/00162
d D 4.11 83/07/01 23:56:42 wnj 11 10
c include problems
e
s 00001/00001/00161
d D 4.10 83/06/30 14:30:19 sam 10 9
c include fix
e
s 00012/00010/00150
d D 4.9 83/05/22 18:05:36 sam 9 8
c user block count in inode (from kre)
e
s 00002/00000/00158
d D 4.8 82/11/12 11:01:59 mckusick 8 7
c don't forget to close "dirp" when chdir fails
e
s 00010/00003/00148
d D 4.7 82/11/11 19:23:07 mckusick 7 6
c fix bug that caused du to core dump while working on execute only directories
e
s 00025/00013/00126
d D 4.6 82/07/01 11:39:47 root 6 5
c fixed bug with multiple arguments which caused errors
c when arguments didn't begin with /
e
s 00001/00001/00138
d D 4.5 82/05/07 16:17:43 mckusick 5 4
c update to new fs
e
s 00089/00100/00050
d D 4.4 82/03/31 11:47:00 root 4 3
c cleaned up and uses lstat
e
s 00041/00058/00109
d D 4.3 82/03/29 15:48:51 mckusic 3 2
c convert to use new directory routines
e
s 00001/00005/00166
d D 4.2 82/03/10 12:46:24 wnj 2 1
c to 1024 byte units
e
s 00171/00000/00000
d D 4.1 80/10/01 17:26:22 bill 1 0
c date and time created 80/10/01 17:26:22 by bill
e
u
U
t
T
I 3
#ifndef lint
E 3
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 3
#endif

E 3
#include <stdio.h>
#include <sys/param.h>
#include <sys/stat.h>
D 3
#include <sys/dir.h>
E 3
I 3
D 5
#include <ndir.h>
E 5
I 5
D 10
#include <dir.h>
E 10
I 10
#include <sys/dir.h>
E 10
E 5

D 4
#define howmany(x, y)	((x + y - 1) / y)
E 3
#define EQ(x,y)	(strcmp(x,y)==0)
#define ML	1000
E 4
I 4
D 6
#define howmany(x, y)	(((x) + (y) - 1) / (y))
E 4

E 6
D 4
struct stat Statb;
char	path[256], name[256];
int	Aflag = 0,
	Sflag = 0,
	Noarg = 0;
E 4
I 4
char	path[BUFSIZ], name[BUFSIZ];
int	aflg;
int	sflg;
char	*dot = ".";

#define ML	1000
E 4
struct {
D 4
	int	dev,
		ino;
E 4
I 4
	int	dev;
	ino_t	ino;
E 4
} ml[ML];
I 4
int	mlx;

E 4
long	descend();
D 4
char	*rindex();
char	*strcpy();
E 4
I 4
D 12
char	*index(), *rindex(), *strcpy(), *sprintf();
E 12
I 12
char	*index(), *rindex(), *strcpy();
E 12
E 4

I 9
#define	kb(n)	(howmany(dbtob(n), 1024))

E 9
main(argc, argv)
D 4
char **argv;
E 4
I 4
	int argc;
	char **argv;
E 4
{
D 4
	register	i = 1;
	long	blocks = 0;
	register char	*np;
E 4
I 4
D 9
	long kbytes = 0;
E 9
I 9
	long blocks = 0;
E 9
	register char *np;
I 6
	int pid;
E 6
E 4

D 4
	if (argc>1) {
		if(EQ(argv[i], "-s")) {
			++i;
			++Sflag;
		} else if(EQ(argv[i], "-a")) {
			++i;
			++Aflag;
		}
E 4
I 4
	argc--, argv++;
again:
	if (argc && !strcmp(*argv, "-s")) {
		sflg++;
		argc--, argv++;
		goto again;
E 4
	}
D 4
	if(i == argc)
		++Noarg;

E 4
I 4
	if (argc && !strcmp(*argv, "-a")) {
		aflg++;
		argc--, argv++;
		goto again;
	}
	if (argc == 0) {
		argv = &dot;
		argc = 1;
	}
E 4
	do {
D 3
		strcpy(path, Noarg? ".": argv[i]);
		strcpy(name, path);
E 3
I 3
D 4
		(void) strcpy(path, Noarg? ".": argv[i]);
		(void) strcpy(name, path);
E 3
		if(np = rindex(name, '/')) {
E 4
I 4
D 6
		(void) strcpy(path, *argv);
		(void) strcpy(name, *argv);
		if (np = rindex(name, '/')) {
E 4
			*np++ = '\0';
D 4
			if(chdir(*name? name: "/") == -1) {
				fprintf(stderr, "cannot chdir()\n");
E 4
I 4
			if (chdir(*name ? name : "/") < 0) {
				perror(*name ? name : "/");
E 6
I 6
		if (argc > 1) {
			pid = fork();
			if (pid == -1) {
				fprintf(stderr, "No more processes.\n");
E 6
E 4
				exit(1);
			}
D 6
		} else
			np = path;
D 4
		blocks = descend(path, *np? np: ".");
		if(Sflag)
			printf("%ld	%s\n", blocks, path);
	} while(++i < argc);

E 4
I 4
		kbytes = descend(path, *np ? np : ".");
		if (sflg)
			printf("%ld\t%s\n", kbytes, path);
E 6
I 6
			if (pid != 0)
				wait((int *)0);
		}
		if (argc == 1 || pid == 0) {
			(void) strcpy(path, *argv);
			(void) strcpy(name, *argv);
			if (np = rindex(name, '/')) {
				*np++ = '\0';
				if (chdir(*name ? name : "/") < 0) {
					perror(*name ? name : "/");
					exit(1);
				}
			} else
				np = path;
D 9
			kbytes = descend(path, *np ? np : ".");
E 9
I 9
			blocks = descend(path, *np ? np : ".");
E 9
			if (sflg)
D 9
				printf("%ld\t%s\n", kbytes, path);
E 9
I 9
				printf("%ld\t%s\n", kb(blocks), path);
E 9
			if (argc > 1)
				exit(1);
		}
E 6
		argc--, argv++;
	} while (argc > 0);
E 4
	exit(0);
}

I 3
D 4
DIR *dirp = NULL;
E 4
I 4
DIR	*dirp = NULL;

E 4
E 3
long
D 4
descend(np, fname)
char *np, *fname;
E 4
I 4
descend(base, name)
	char *base, *name;
E 4
{
D 3
	int dir = 0, /* open directory */
		offset,
		dsize,
		entries,
		dirsize;

	struct direct dentry[BUFSIZ / sizeof (struct direct)];
E 3
D 4
	register  struct direct *dp;
D 3
	register char *c1, *c2;
E 3
I 3
	register char *c1;
E 4
I 4
	char *ebase0, *ebase;
	struct stat stb;
E 4
E 3
	int i;
D 4
	char *endofname;
	long blocks = 0;
E 4
I 4
D 9
	long kbytes = 0;
E 9
I 9
	long blocks = 0;
E 9
E 4
I 3
	long curoff = NULL;
I 4
	register struct direct *dp;
E 4
E 3

D 4
	if(stat(fname,&Statb)<0) {
		fprintf(stderr, "--bad status < %s >\n", name);
		return 0L;
E 4
I 4
	ebase0 = ebase = index(base, 0);
	if (ebase > base && ebase[-1] == '/')
		ebase--;
	if (lstat(name, &stb) < 0) {
		perror(base);
		*ebase0 = 0;
		return (0);
E 4
	}
D 4
	if(Statb.st_nlink > 1 && (Statb.st_mode&S_IFMT)!=S_IFDIR) {
		static linked = 0;

		for(i = 0; i <= linked; ++i) {
			if(ml[i].ino==Statb.st_ino && ml[i].dev==Statb.st_dev)
				return 0;
E 4
I 4
	if (stb.st_nlink > 1 && (stb.st_mode&S_IFMT) != S_IFDIR) {
		for (i = 0; i <= mlx; i++)
			if (ml[i].ino == stb.st_ino && ml[i].dev == stb.st_dev)
				return (0);
		if (mlx < ML) {
			ml[mlx].dev = stb.st_dev;
			ml[mlx].ino = stb.st_ino;
			mlx++;
E 4
		}
D 4
		if (linked < ML) {
			ml[linked].dev = Statb.st_dev;
			ml[linked].ino = Statb.st_ino;
			++linked;
		}
E 4
	}
D 2
/*
	blocks = (Statb.st_size + BSIZE-1) >> BSHIFT;
*/
	blocks = (Statb.st_size + 511) >> 9;

E 2
I 2
D 3
	blocks = (Statb.st_size + 1023-1) >> 10;
E 2
	if((Statb.st_mode&S_IFMT)!=S_IFDIR) {
E 3
I 3
D 4
	blocks = howmany(Statb.st_size, 1024);

	if((Statb.st_mode&S_IFMT) != S_IFDIR) {
E 3
		if(Aflag)
			printf("%ld	%s\n", blocks, np);
		return(blocks);
E 4
I 4
D 9
	kbytes = howmany(stb.st_size, 1024);
E 9
I 9
	blocks = stb.st_blocks;
E 9
	if ((stb.st_mode&S_IFMT) != S_IFDIR) {
		if (aflg)
D 9
			printf("%ld\t%s\n", kbytes, base);
		return (kbytes);
E 9
I 9
			printf("%ld\t%s\n", kb(blocks), base);
		return (blocks);
E 9
E 4
	}
D 4

	for(c1 = np; *c1; ++c1);
	if(*(c1-1) == '/')
		--c1;
	endofname = c1;
D 3
	dirsize = Statb.st_size;
E 3
	if(chdir(fname) == -1)
		return 0;
E 4
I 4
D 7
	if (chdir(name) < 0)
		return (0);
E 7
E 4
D 3
	for(offset=0; offset < dirsize; offset += BUFSIZ) { /* each block */
		dsize = BUFSIZ<(dirsize-offset)? BUFSIZ: (dirsize-offset);
		if(!dir) {
			if((dir=open(".",0))<0) {
				fprintf(stderr, "--cannot open < %s >\n",
					np);
				goto ret;
			}
			if(offset) lseek(dir, (long)offset, 0);
			if(read(dir, (char *)dentry, dsize)<0) {
				fprintf(stderr, "--cannot read < %s >\n",
					np);
				goto ret;
			}
			if(dir > 10) {
				close(dir);
				dir = 0;
			}
		} else 
			if(read(dir, (char *)dentry, dsize)<0) {
				fprintf(stderr, "--cannot read < %s >\n",
					np);
				goto ret;
			}
		for(dp=dentry, entries=dsize>>4; entries; --entries, ++dp) {
			/* each directory entry */
			if(dp->d_ino==0
			|| EQ(dp->d_name, ".")
			|| EQ(dp->d_name, ".."))
				continue;
			c1 = endofname;
			*c1++ = '/';
			c2 = dp->d_name;
			for(i=0; i<DIRSIZ; ++i)
				if(*c2)
					*c1++ = *c2++;
				else
					break;
			*c1 = '\0';
			if(c1 == endofname) /* ?? */
				return 0L;
			blocks += descend(np, endofname+1);
E 3
I 3
	if (dirp != NULL)
		closedir(dirp);
D 4
	if ((dirp = opendir(".")) == NULL) {
		fprintf(stderr, "--cannot open < %s >\n", np);
		goto ret;
E 4
I 4
D 7
	dirp = opendir(".");
E 7
I 7
	dirp = opendir(name);
E 7
	if (dirp == NULL) {
		perror(base);
		*ebase0 = 0;
		return (0);
E 4
	}
I 7
	if (chdir(name) < 0) {
		perror(base);
		*ebase0 = 0;
I 8
		closedir(dirp);
		dirp = NULL;
E 8
		return (0);
	}
E 7
D 4
	if ((dp = readdir(dirp)) == NULL) {
		fprintf(stderr, "--cannot read < %s >\n", np);
		closedir(dirp);
		dirp = NULL;
		goto ret;
	}
	for ( ; dp != NULL; dp = readdir(dirp)) {
		/* each directory entry */
		if (EQ(dp->d_name, ".") || EQ(dp->d_name, ".."))
E 4
I 4
	while (dp = readdir(dirp)) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
E 4
			continue;
D 4
		c1 = endofname;
		*c1++ = '/';
		(void) strcpy(c1, dp->d_name);
E 4
I 4
		(void) sprintf(ebase, "/%s", dp->d_name);
E 4
		curoff = telldir(dirp);
D 4
		blocks += descend(np, endofname+1);
E 4
I 4
D 9
		kbytes += descend(base, ebase+1);
E 9
I 9
		blocks += descend(base, ebase+1);
E 9
		*ebase = 0;
E 4
		if (dirp == NULL) {
D 4
			/* previous entry was a directory */
E 4
			dirp = opendir(".");
I 7
			if (dirp == NULL) {
				perror(".");
				return (0);
			}
E 7
			seekdir(dirp, curoff);
E 3
		}
	}
I 3
	closedir(dirp);
	dirp = NULL;
E 3
D 4
	*endofname = '\0';
	if(!Sflag)
		printf("%ld	%s\n", blocks, np);
ret:
D 3
	if(dir)
		close(dir);
E 3
	if(chdir("..") == -1) {
		*endofname = '\0';
		fprintf(stderr, "Bad directory <%s>\n", np);
		while(*--endofname != '/');
		*endofname = '\0';
		if(chdir(np) == -1)
			exit(1);
E 4
I 4
	if (sflg == 0)
D 9
		printf("%ld\t%s\n", kbytes, base);
E 9
I 9
		printf("%ld\t%s\n", kb(blocks), base);
E 9
	if (chdir("..") < 0) {
		(void) sprintf(index(base, 0), "/..");
		perror(base);
		exit(1);
E 4
	}
D 4
	return(blocks);
E 4
I 4
	*ebase0 = 0;
D 9
	return (kbytes);
E 9
I 9
	return (blocks);
E 9
E 4
}
E 1
