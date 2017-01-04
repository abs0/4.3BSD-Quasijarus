h42138
s 00001/00001/00604
d D 5.5 88/05/13 14:47:51 mckusick 25 24
c add Nflag to request not to do any writes
e
s 00008/00014/00597
d D 5.4 86/04/23 12:04:39 mckusick 24 23
c do not dump core when missing `.' or `..' entries in directories
e
s 00004/00000/00607
d D 5.3 86/03/26 23:13:30 sklower 23 22
c restore sun and cci tapes
e
s 00001/00001/00606
d D 5.2 85/06/18 21:11:12 mckusick 22 21
c dumprestor.h moves to /usr/include/protocols
e
s 00008/00004/00599
d D 5.1 85/05/28 15:10:20 dist 21 20
c Add copyright
e
s 00004/00000/00599
d D 3.20 85/02/18 18:29:29 mckusick 20 19
c do not set owner and times on directories that already exist ('i' and 'x' only)
e
s 00001/00002/00598
d D 3.19 85/02/13 14:14:26 mckusick 19 18
c allow for no files on dump tape (from sun!shannon)
e
s 00018/00183/00582
d D 3.18 85/01/18 22:38:14 mckusick 18 17
c reorganize to split out interactive shell
e
s 00006/00003/00759
d D 3.17 83/12/30 00:38:07 mckusick 17 16
c missing ``modefile'' is a non-fatal error
e
s 00002/00002/00760
d D 3.16 83/08/11 23:04:32 sam 16 15
c standardize sccs keyword lines
e
s 00007/00003/00755
d D 3.15 83/08/11 16:46:36 mckusick 15 14
c in 'x' or 'i' mode, ask if mode of "." should be changed
e
s 00008/00001/00750
d D 3.14 83/07/08 16:49:09 mckusick 14 13
c guard all dynamic allocations
e
s 00001/00001/00750
d D 3.13 83/07/01 03:10:03 sam 13 12
c include fixes
e
s 00001/00001/00750
d D 3.12 83/06/02 17:06:20 sam 12 11
c file.h updated
e
s 00021/00017/00730
d D 3.11 83/05/19 01:22:52 mckusick 11 10
c use perror everywhere; lint
e
s 00042/00013/00705
d D 3.10 83/05/14 21:53:40 mckusick 10 9
c make readdir more robust; allow printing of dir entries not on tape
e
s 00001/00001/00717
d D 3.9 83/05/03 23:29:18 mckusick 9 8
c do not panic if directory is not marked NEW when setting time and ownership
e
s 00225/00020/00493
d D 3.8 83/04/19 02:11:46 mckusick 8 7
c add and debug interactive extraction mode
e
s 00004/00017/00509
d D 3.7 83/03/27 18:33:23 mckusick 7 6
c pass pruning argument back to treescan
e
s 00014/00040/00512
d D 3.6 83/03/27 12:54:01 mckusick 6 5
c lint; delete opendir (use standard version in library)
e
s 00005/00005/00547
d D 3.5 83/03/23 08:56:41 mckusick 5 4
c use MAXPATHLEN instead of BUFSIZ where appropriate
e
s 00006/00004/00546
d D 3.4 83/03/06 17:43:47 mckusick 4 3
c lint
e
s 00035/00011/00515
d D 3.3 83/02/28 00:37:44 mckusick 3 2
c get "h" and "m" flags working
e
s 00019/00013/00507
d D 3.2 83/02/27 14:39:22 mckusick 2 1
c get "x" command working
e
s 00520/00000/00000
d D 3.1 83/02/18 00:41:37 mckusick 1 0
c date and time created 83/02/18 00:41:37 by mckusick
e
u
U
t
T
I 1
D 16
/* Copyright (c) 1983 Regents of the University of California */

E 16
D 21
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif
E 21
I 21
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 21
I 16

D 21
/* Copyright (c) 1983 Regents of the University of California */
E 21
I 21
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 21
E 16

#include "restore.h"
D 22
#include <dumprestor.h>
E 22
I 22
#include <protocols/dumprestore.h>
E 22
D 2
#include <file.h>
E 2
I 2
#include <sys/file.h>
E 2
D 13
#include <dir.h>
E 13
I 13
D 18
#include <sys/dir.h>
E 18
E 13

I 8
/*
 * Symbol table of directories read from tape.
 */
E 8
#define HASHSIZE	1000
D 8

E 8
#define INOHASH(val) (val % HASHSIZE)
struct inotab {
	struct inotab *t_next;
	ino_t	t_ino;
	daddr_t	t_seekpt;
	long t_size;
D 2
} *inotab[HASHSIZE];
struct inotab *inotablookup();
E 2
I 2
};
static struct inotab *inotab[HASHSIZE];
extern struct inotab *inotablookup();
I 3
extern struct inotab *allocinotab();
E 3
E 2

I 8
/*
 * Information retained about directories.
 */
E 8
struct modeinfo {
	ino_t ino;
	time_t timep[2];
	short mode;
	short uid;
	short gid;
};

I 8
/*
 * Global variables for this file.
 */
E 8
D 2
daddr_t	seekpt;
FILE	*df, *mf;
DIR	*dirp;
char	dirfile[] = "/tmp/rstaXXXXXX";
extern	ino_t search();
E 2
I 2
static daddr_t	seekpt;
static FILE	*df, *mf;
static DIR	*dirp;
D 8
static char	dirfile[] = "/tmp/rstaXXXXXX";
E 8
I 8
static char	dirfile[32] = "#";	/* No file */
static char	modefile[32] = "#";	/* No file */
E 8
extern ino_t	search();
I 11
struct direct 	*rst_readdir();
extern void 	rst_seekdir();
E 11
E 2

I 8
/*
 * Format of old style directories.
 */
E 8
#define ODIRSIZ 14
struct odirect {
	u_short	d_ino;
	char	d_name[ODIRSIZ];
};

/*
I 8
D 18
 * Structure and routines associated with listing directories.
 */
struct afile {
	ino_t	fnum;		/* inode number of file */
	char	*fname;		/* file name */
	short	fflags;		/* extraction flags, if any */
	char	ftype;		/* file type, e.g. LEAF or NODE */
};
extern int fcmp();
extern char *fmtentry();

/*
E 18
E 8
 *	Extract directory contents, building up a directory structure
 *	on disk for extraction by name.
D 8
 *	If modefile is requested, save mode, owner, and times for all
E 8
I 8
 *	If genmode is requested, save mode, owner, and times for all
E 8
 *	directories on the tape.
 */
D 8
extractdirs(modefile)
	char *modefile;
E 8
I 8
extractdirs(genmode)
	int genmode;
E 8
{
	register int i;
	register struct dinode *ip;
I 3
	struct inotab *itp;
E 3
	struct direct nulldir;
	int putdir(), null();

	vprintf(stdout, "Extract directories from tape\n");
D 4
	mktemp(dirfile);
E 4
I 4
D 8
	(void) mktemp(dirfile);
E 8
I 8
	(void) sprintf(dirfile, "/tmp/rstdir%d", dumpdate);
E 8
E 4
	df = fopen(dirfile, "w");
	if (df == 0) {
		fprintf(stderr,
D 17
		    "restor: %s - cannot create directory temporary\n",
E 17
I 17
		    "restore: %s - cannot create directory temporary\n",
E 17
		    dirfile);
		perror("fopen");
		done(1);
	}
D 8
	if (modefile != NULL) {
E 8
I 8
	if (genmode != 0) {
		(void) sprintf(modefile, "/tmp/rstmode%d", dumpdate);
E 8
		mf = fopen(modefile, "w");
D 2
		if (df == 0) {
E 2
I 2
		if (mf == 0) {
E 2
			fprintf(stderr,
D 17
			    "restor: %s - cannot create modefile \n",
E 17
I 17
			    "restore: %s - cannot create modefile \n",
E 17
			    modefile);
			perror("fopen");
			done(1);
		}
	}
D 3
	nulldir.d_ino = 1;
E 3
I 3
	nulldir.d_ino = 0;
E 3
	nulldir.d_namlen = 1;
D 8
	strncpy(nulldir.d_name, "/", nulldir.d_namlen);
E 8
I 8
D 10
	(void) strncpy(nulldir.d_name, "/", (int)nulldir.d_namlen);
E 10
I 10
	(void) strcpy(nulldir.d_name, "/");
E 10
E 8
	nulldir.d_reclen = DIRSIZ(&nulldir);
	for (;;) {
		curfile.name = "<directory file - name unknown>";
		curfile.action = USING;
		ip = curfile.dip;
D 19
		i = ip->di_mode & IFMT;
		if (i != IFDIR) {
E 19
I 19
		if (ip == NULL || (ip->di_mode & IFMT) != IFDIR) {
E 19
D 6
			fclose(df);
E 6
I 6
			(void) fclose(df);
E 6
			dirp = opendir(dirfile);
			if (dirp == NULL)
				perror("opendir");
			if (mf != NULL)
D 6
				fclose(mf);
E 6
I 6
				(void) fclose(mf);
E 6
I 4
D 8
			if ((i = psearch(".")) == 0 || BIT(i, dumpmap) == 0)
E 8
I 8
			i = dirlookup(".");
			if (i == 0)
E 8
				panic("Root directory is not on tape\n");
E 4
			return;
		}
D 3
		allocinotab(curfile.ino, ip, seekpt);
E 3
I 3
		itp = allocinotab(curfile.ino, ip, seekpt);
E 3
		getfile(putdir, null);
		putent(&nulldir);
		flushent();
I 3
		itp->t_size = seekpt - itp->t_seekpt;
E 3
	}
}

/*
I 3
 * skip over all the directories on the tape
 */
skipdirs()
{

	while ((curfile.dip->di_mode & IFMT) == IFDIR) {
		skipfile();
	}
}

/*
E 3
 *	Recursively find names and inumbers of all files in subtree 
 *	pname and pass them off to be processed.
 */
treescan(pname, ino, todo)
	char *pname;
	ino_t ino;
D 7
	void (*todo)();
E 7
I 7
	long (*todo)();
E 7
{
	register struct inotab *itp;
I 10
	register struct direct *dp;
	register struct entry *np;
E 10
	int namelen;
	daddr_t bpt;
D 10
	register struct direct *dp;
E 10
D 5
	char locname[BUFSIZ + 1];
E 5
I 5
	char locname[MAXPATHLEN + 1];
E 5

	itp = inotablookup(ino);
	if (itp == NULL) {
		/*
		 * Pname is name of a simple file or an unchanged directory.
		 */
D 7
		(*todo)(pname, ino, LEAF);
E 7
I 7
		(void) (*todo)(pname, ino, LEAF);
E 7
		return;
	}
	/*
	 * Pname is a dumped directory name.
	 */
D 7
	(*todo)(pname, ino, NODE);
E 7
I 7
	if ((*todo)(pname, ino, NODE) == FAIL)
		return;
E 7
	/*
	 * begin search through the directory
	 * skipping over "." and ".."
	 */
D 5
	strncpy(locname, pname, BUFSIZ);
	strncat(locname, "/", BUFSIZ);
E 5
I 5
D 8
	strncpy(locname, pname, MAXPATHLEN);
	strncat(locname, "/", MAXPATHLEN);
E 8
I 8
	(void) strncpy(locname, pname, MAXPATHLEN);
	(void) strncat(locname, "/", MAXPATHLEN);
E 8
E 5
	namelen = strlen(locname);
D 11
	seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
	dp = readdir(dirp); /* "." */
E 11
I 11
	rst_seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
	dp = rst_readdir(dirp); /* "." */
E 11
D 10
	dp = readdir(dirp); /* ".." */
	dp = readdir(dirp); /* first real entry */
E 10
I 10
D 24
	if (dp != NULL && strcmp(dp->d_name, ".") == 0) {
E 24
I 24
	if (dp != NULL && strcmp(dp->d_name, ".") == 0)
E 24
D 11
		dp = readdir(dirp); /* ".." */
E 11
I 11
		dp = rst_readdir(dirp); /* ".." */
E 11
D 24
	} else {
		np = lookupino(ino);
		if (np == NULL)
			panic("corrupted symbol table\n");
		fprintf(stderr, ". missing from directory %s\n", myname(np));
	}
	if (dp != NULL && strcmp(dp->d_name, "..") == 0) {
E 24
I 24
	else
		fprintf(stderr, "Warning: `.' missing from directory %s\n",
			pname);
	if (dp != NULL && strcmp(dp->d_name, "..") == 0)
E 24
D 11
		dp = readdir(dirp); /* first real entry */
E 11
I 11
		dp = rst_readdir(dirp); /* first real entry */
E 11
D 24
	} else {
		np = lookupino(ino);
		if (np == NULL)
			panic("corrupted symbol table\n");
		fprintf(stderr, ".. missing from directory %s\n", myname(np));
	}
E 24
I 24
	else
		fprintf(stderr, "Warning: `..' missing from directory %s\n",
			pname);
E 24
E 10
	bpt = telldir(dirp);
	/*
D 10
	 * "/" signals end of directory
E 10
I 10
	 * a zero inode signals end of directory
E 10
	 */
D 10
	while (dp != NULL && !(dp->d_namlen == 1 && dp->d_name[0] == '/')) {
E 10
I 10
	while (dp != NULL && dp->d_ino != 0) {
E 10
		locname[namelen] = '\0';
D 5
		if (namelen + dp->d_namlen >= BUFSIZ) {
E 5
I 5
		if (namelen + dp->d_namlen >= MAXPATHLEN) {
E 5
			fprintf(stderr, "%s%s: name exceeds %d char\n",
D 5
				locname, dp->d_name, BUFSIZ);
E 5
I 5
				locname, dp->d_name, MAXPATHLEN);
E 5
		} else {
D 8
			strncat(locname, dp->d_name, dp->d_namlen);
E 8
I 8
			(void) strncat(locname, dp->d_name, (int)dp->d_namlen);
E 8
			treescan(locname, dp->d_ino, todo);
D 11
			seekdir(dirp, bpt, itp->t_seekpt);
E 11
I 11
			rst_seekdir(dirp, bpt, itp->t_seekpt);
E 11
		}
D 11
		dp = readdir(dirp);
E 11
I 11
		dp = rst_readdir(dirp);
E 11
		bpt = telldir(dirp);
	}
	if (dp == NULL)
		fprintf(stderr, "corrupted directory: %s.\n", locname);
}

/*
 * Search the directory tree rooted at inode ROOTINO
 * for the path pointed at by n
 */
ino_t
psearch(n)
	char	*n;
{
	register char *cp, *cp1;
	ino_t ino;
	char c;

	ino = ROOTINO;
	if (*(cp = n) == '/')
		cp++;
next:
	cp1 = cp + 1;
	while (*cp1 != '/' && *cp1)
		cp1++;
	c = *cp1;
	*cp1 = 0;
	ino = search(ino, cp);
	if (ino == 0) {
		*cp1 = c;
		return(0);
	}
	*cp1 = c;
	if (c == '/') {
		cp = cp1+1;
		goto next;
	}
	return(ino);
}

/*
 * search the directory inode ino
 * looking for entry cp
 */
ino_t
search(inum, cp)
	ino_t	inum;
	char	*cp;
{
	register struct direct *dp;
	register struct inotab *itp;
	int len;

	itp = inotablookup(inum);
	if (itp == NULL)
		return(0);
D 11
	seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
E 11
I 11
	rst_seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
E 11
	len = strlen(cp);
	do {
D 11
		dp = readdir(dirp);
E 11
I 11
		dp = rst_readdir(dirp);
E 11
D 10
		if (dp->d_namlen == 1 && dp->d_name[0] == '/')
			return(0);
E 10
I 10
		if (dp == NULL || dp->d_ino == 0)
			return (0);
E 10
D 8
	} while (dp->d_namlen != len || strncmp(dp->d_name, cp, len));
E 8
I 8
	} while (dp->d_namlen != len || strncmp(dp->d_name, cp, len) != 0);
E 8
	return(dp->d_ino);
}

/*
 * Put the directory entries in the directory file
 */
putdir(buf, size)
	char *buf;
	int size;
{
	struct direct cvtbuf;
	register struct odirect *odp;
	struct odirect *eodp;
	register struct direct *dp;
	long loc, i;
I 23
	extern int Bcvt;
E 23

	if (cvtflag) {
		eodp = (struct odirect *)&buf[size];
		for (odp = (struct odirect *)buf; odp < eodp; odp++)
			if (odp->d_ino != 0) {
				dcvt(odp, &cvtbuf);
				putent(&cvtbuf);
			}
	} else {
		for (loc = 0; loc < size; ) {
			dp = (struct direct *)(buf + loc);
I 23
			if (Bcvt) {
				swabst("l2s", (char *) dp);
			}
E 23
			i = DIRBLKSIZ - (loc & (DIRBLKSIZ - 1));
			if (dp->d_reclen == 0 || dp->d_reclen > i) {
				loc += i;
				continue;
			}
			loc += dp->d_reclen;
			if (dp->d_ino != 0) {
				putent(dp);
			}
		}
	}
}

/*
 * These variables are "local" to the following two functions.
 */
char dirbuf[DIRBLKSIZ];
long dirloc = 0;
long prev = 0;

/*
 * add a new directory entry to a file.
 */
putent(dp)
	struct direct *dp;
{
D 3
	if (dp->d_ino == 0)
		return;
E 3
I 3
	dp->d_reclen = DIRSIZ(dp);
E 3
	if (dirloc + dp->d_reclen > DIRBLKSIZ) {
		((struct direct *)(dirbuf + prev))->d_reclen =
		    DIRBLKSIZ - prev;
D 6
		fwrite(dirbuf, 1, DIRBLKSIZ, df);
E 6
I 6
		(void) fwrite(dirbuf, 1, DIRBLKSIZ, df);
E 6
		dirloc = 0;
	}
	bcopy((char *)dp, dirbuf + dirloc, (long)dp->d_reclen);
	prev = dirloc;
	dirloc += dp->d_reclen;
}

/*
 * flush out a directory that is finished.
 */
flushent()
{

	((struct direct *)(dirbuf + prev))->d_reclen = DIRBLKSIZ - prev;
D 6
	fwrite(dirbuf, (int)dirloc, 1, df);
E 6
I 6
	(void) fwrite(dirbuf, (int)dirloc, 1, df);
E 6
	seekpt = ftell(df);
	dirloc = 0;
}

dcvt(odp, ndp)
	register struct odirect *odp;
	register struct direct *ndp;
{

	bzero((char *)ndp, (long)(sizeof *ndp));
	ndp->d_ino =  odp->d_ino;
D 8
	strncpy(ndp->d_name, odp->d_name, ODIRSIZ);
E 8
I 8
	(void) strncpy(ndp->d_name, odp->d_name, ODIRSIZ);
E 8
	ndp->d_namlen = strlen(ndp->d_name);
	ndp->d_reclen = DIRSIZ(ndp);
D 6
	/*
	 * this quickly calculates if this inode is a directory.
	 * Currently not maintained.
	 *
	itp = inotablookup(odp->d_ino);
	if (itp != NIL)
		ndp->d_fmt = IFDIR;
	 */
E 6
}

/*
D 6
 * Open a directory.
 * Modified to allow any random file to be a legal directory.
 */
DIR *
opendir(name)
	char *name;
{
	register DIR *dirp;

D 4
	dirp = (DIR *)malloc((unsigned long)sizeof(DIR));
E 4
I 4
	dirp = (DIR *)malloc((unsigned)sizeof(DIR));
E 4
	dirp->dd_fd = open(name, 0);
	if (dirp->dd_fd == -1) {
		free((char *)dirp);
		return NULL;
	}
	dirp->dd_loc = 0;
	return dirp;
}

/*
E 6
 * Seek to an entry in a directory.
D 11
 * Only values returned by ``telldir'' should be passed to seekdir.
E 11
I 11
 * Only values returned by ``telldir'' should be passed to rst_seekdir.
E 11
D 6
 * Modified to have many directories based in one file.
E 6
I 6
 * This routine handles many directories in a single file.
 * It takes the base of the directory in the file, plus
 * the desired seek offset into it.
E 6
 */
void
D 11
seekdir(dirp, loc, base)
E 11
I 11
rst_seekdir(dirp, loc, base)
E 11
	register DIR *dirp;
	daddr_t loc, base;
{

	if (loc == telldir(dirp))
		return;
	loc -= base;
	if (loc < 0)
D 11
		fprintf(stderr, "bad seek pointer to seekdir %d\n", loc);
E 11
I 11
		fprintf(stderr, "bad seek pointer to rst_seekdir %d\n", loc);
E 11
	(void) lseek(dirp->dd_fd, base + (loc & ~(DIRBLKSIZ - 1)), 0);
	dirp->dd_loc = loc & (DIRBLKSIZ - 1);
	if (dirp->dd_loc != 0)
		dirp->dd_size = read(dirp->dd_fd, dirp->dd_buf, DIRBLKSIZ);
}

/*
 * get next entry in a directory.
 */
struct direct *
D 11
readdir(dirp)
E 11
I 11
rst_readdir(dirp)
E 11
	register DIR *dirp;
{
	register struct direct *dp;

	for (;;) {
		if (dirp->dd_loc == 0) {
			dirp->dd_size = read(dirp->dd_fd, dirp->dd_buf, 
			    DIRBLKSIZ);
D 10
			if (dirp->dd_size <= 0)
E 10
I 10
			if (dirp->dd_size <= 0) {
				dprintf(stderr, "error reading directory\n");
E 10
				return NULL;
I 10
			}
E 10
		}
		if (dirp->dd_loc >= dirp->dd_size) {
			dirp->dd_loc = 0;
			continue;
		}
		dp = (struct direct *)(dirp->dd_buf + dirp->dd_loc);
		if (dp->d_reclen == 0 ||
D 10
		    dp->d_reclen > DIRBLKSIZ + 1 - dirp->dd_loc)
E 10
I 10
		    dp->d_reclen > DIRBLKSIZ + 1 - dirp->dd_loc) {
			dprintf(stderr, "corrupted directory: bad reclen %d\n",
				dp->d_reclen);
E 10
			return NULL;
I 10
		}
E 10
		dirp->dd_loc += dp->d_reclen;
I 10
		if (dp->d_ino == 0 && strcmp(dp->d_name, "/") != 0)
			continue;
D 11
		if (dp->d_ino < 0 || dp->d_ino >= maxino) {
E 11
I 11
		if (dp->d_ino >= maxino) {
E 11
			dprintf(stderr, "corrupted directory: bad inum %d\n",
				dp->d_ino);
			continue;
		}
E 10
D 3
		if (dp->d_ino == 0)
			continue;
E 3
		return (dp);
	}
}

/*
I 18
 * Simulate the opening of a directory
 */
DIR *
rst_opendir(name)
	char *name;
{
	struct inotab *itp;
	ino_t ino;

	if ((ino = dirlookup(name)) > 0 &&
	    (itp = inotablookup(ino)) != NULL) {
		rst_seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
		return (dirp);
	}
	return (0);
}

/*
E 18
 * Set the mode, owner, and times for all new or changed directories
 */
D 8
setdirmodes(modefile)
	char *modefile;
E 8
I 8
setdirmodes()
E 8
{
	FILE *mf;
	struct modeinfo node;
	struct entry *ep;
	char *cp;
	
	vprintf(stdout, "Set directory mode, owner, and times.\n");
I 17
	(void) sprintf(modefile, "/tmp/rstmode%d", dumpdate);
E 17
	mf = fopen(modefile, "r");
	if (mf == NULL) {
		perror("fopen");
D 17
		panic("cannot open mode file %s\n", modefile);
E 17
I 17
		fprintf(stderr, "cannot open mode file %s\n", modefile);
		fprintf(stderr, "directory mode, owner, and times not set\n");
		return;
E 17
	}
	clearerr(mf);
D 2
	fread((char *)&node, 1, sizeof(struct modeinfo), mf);
	while (!feof(mf)) {
E 2
I 2
	for (;;) {
D 6
		fread((char *)&node, 1, sizeof(struct modeinfo), mf);
E 6
I 6
		(void) fread((char *)&node, 1, sizeof(struct modeinfo), mf);
E 6
		if (feof(mf))
			break;
E 2
		ep = lookupino(node.ino);
D 2
		if (ep == NIL)
E 2
I 2
D 8
		if (ep == NIL) {
			if (command == 'x')
E 8
I 8
D 9
		if (ep == NIL || (ep->e_flags & NEW) == 0) {
E 9
I 9
D 15
		if (ep == NIL) {
E 9
			if (command != 'r' && command != 'R')
E 15
I 15
		if (command == 'i' || command == 'x') {
			if (ep == NIL)
E 15
E 8
				continue;
I 20
			if (ep->e_flags & EXISTED) {
				ep->e_flags &= ~NEW;
				continue;
			}
E 20
E 2
D 15
			panic("cannot find directory inode %d\n", node.ino);
E 15
I 15
			if (node.ino == ROOTINO &&
		   	    reply("set owner/mode for '.'") == FAIL)
				continue;
E 15
I 2
		}
I 15
		if (ep == NIL)
			panic("cannot find directory inode %d\n", node.ino);
E 15
E 2
		cp = myname(ep);
D 6
		chown(cp, node.uid, node.gid);
		chmod(cp, node.mode);
E 6
I 6
		(void) chown(cp, node.uid, node.gid);
		(void) chmod(cp, node.mode);
E 6
		utime(cp, node.timep);
I 8
		ep->e_flags &= ~NEW;
E 8
D 2
		fread((char *)&node, 1, sizeof(struct modeinfo), mf);
E 2
	}
	if (ferror(mf))
		panic("error setting directory modes\n");
D 6
	fclose(mf);
E 6
I 6
	(void) fclose(mf);
E 6
I 2
D 4
	unlink(modefile);
E 4
I 4
D 8
	(void) unlink(modefile);
E 8
E 4
E 2
}

/*
 * Generate a literal copy of a directory.
 */
genliteraldir(name, ino)
	char *name;
	ino_t ino;
{
	register struct inotab *itp;
	int ofile, dp, i, size;
	char buf[BUFSIZ];

	itp = inotablookup(ino);
	if (itp == NULL)
D 3
		panic("cannot find directory inode %d named %s\n", ino, name);
E 3
I 3
		panic("Cannot find directory inode %d named %s\n", ino, name);
E 3
D 12
	if ((ofile = open(name, FWRONLY|FCREATE, 0666)) < 0) {
E 12
I 12
	if ((ofile = creat(name, 0666)) < 0) {
E 12
D 11
		fprintf(stderr, "%s: cannot create file\n", name);
E 11
I 11
		fprintf(stderr, "%s: ", name);
		(void) fflush(stderr);
		perror("cannot create file");
E 11
		return (FAIL);
	}
D 11
	seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
E 11
I 11
	rst_seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
E 11
	dp = dup(dirp->dd_fd);
	for (i = itp->t_size; i > 0; i -= BUFSIZ) {
		size = i < BUFSIZ ? i : BUFSIZ;
		if (read(dp, buf, (int) size) == -1) {
			fprintf(stderr,
				"write error extracting inode %d, name %s\n",
				curfile.ino, curfile.name);
			perror("read");
			done(1);
		}
D 25
		if (write(ofile, buf, (int) size) == -1) {
E 25
I 25
		if (!Nflag && write(ofile, buf, (int) size) == -1) {
E 25
			fprintf(stderr,
				"write error extracting inode %d, name %s\n",
				curfile.ino, curfile.name);
			perror("write");
			done(1);
		}
	}
D 6
	close(dp);
	close(ofile);
E 6
I 6
	(void) close(dp);
	(void) close(ofile);
E 6
	return (GOOD);
D 7
}

/*
I 3
 * Determine the type of an inode
 */
inodetype(ino)
	ino_t ino;
{
	struct inotab *itp;

	itp = inotablookup(ino);
	if (itp == NULL)
		return (LEAF);
	return (NODE);
E 7
D 18
}

/*
I 8
 * Do an "ls" style listing of a directory
 */
printlist(name, ino)
	char *name;
	ino_t ino;
{
	register struct afile *fp;
	register struct inotab *itp;
	struct afile *dfp0, *dfplast;
	struct afile single;

	itp = inotablookup(ino);
	if (itp == NULL) {
		single.fnum = ino;
		single.fname = savename(rindex(name, '/') + 1);
		dfp0 = &single;
		dfplast = dfp0 + 1;
	} else {
D 11
		seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
E 11
I 11
		rst_seekdir(dirp, itp->t_seekpt, itp->t_seekpt);
E 11
		if (getdir(dirp, &dfp0, &dfplast) == FAIL)
			return;
	}
	qsort((char *)dfp0, dfplast - dfp0, sizeof (struct afile), fcmp);
	formatf(dfp0, dfplast);
	for (fp = dfp0; fp < dfplast; fp++)
		freename(fp->fname);
}

/*
 * Read the contents of a directory.
 */
getdir(dirp, pfp0, pfplast)
	DIR *dirp;
	struct afile **pfp0, **pfplast;
{
	register struct afile *fp;
	register struct direct *dp;
	static struct afile *basefp = NULL;
	static long nent = 20;

D 14
	if (basefp == NULL)
E 14
I 14
	if (basefp == NULL) {
E 14
		basefp = (struct afile *)calloc((unsigned)nent,
			sizeof (struct afile));
I 14
		if (basefp == NULL) {
			fprintf(stderr, "ls: out of memory\n");
			return (FAIL);
		}
	}
E 14
	fp = *pfp0 = basefp;
	*pfplast = *pfp0 + nent;
D 11
	while (dp = readdir(dirp)) {
E 11
I 11
	while (dp = rst_readdir(dirp)) {
E 11
D 10
		if (dp->d_ino == 0 && strcmp(dp->d_name, "/") == 0)
E 10
I 10
		if (dp == NULL || dp->d_ino == 0)
E 10
			break;
D 10
		if (BIT(dp->d_ino, dumpmap) == 0)
E 10
I 10
		if (!dflag && BIT(dp->d_ino, dumpmap) == 0)
E 10
			continue;
		if (vflag == 0 &&
		    (strcmp(dp->d_name, ".") == 0 ||
		     strcmp(dp->d_name, "..") == 0))
			continue;
		fp->fnum = dp->d_ino;
		fp->fname = savename(dp->d_name);
		fp++;
		if (fp == *pfplast) {
			basefp = (struct afile *)realloc((char *)basefp,
			    (unsigned)(2 * nent * sizeof (struct afile)));
			if (basefp == 0) {
				fprintf(stderr, "ls: out of memory\n");
				return (FAIL);
			}
			*pfp0 = basefp;
			fp = *pfp0 + nent;
			*pfplast = fp + nent;
			nent *= 2;
		}
	}
	*pfplast = fp;
	return (GOOD);
}

/*
 * Print out a pretty listing of a directory
 */
formatf(fp0, fplast)
	struct afile *fp0, *fplast;
{
	register struct afile *fp;
	struct entry *np;
	int width = 0, w, nentry = fplast - fp0;
	int i, j, len, columns, lines;
	char *cp;

	if (fp0 == fplast)
		return;
	for (fp = fp0; fp < fplast; fp++) {
		fp->ftype = inodetype(fp->fnum);
		np = lookupino(fp->fnum);
		if (np != NIL)
			fp->fflags = np->e_flags;
		else
			fp->fflags = 0;
		len = strlen(fmtentry(fp));
		if (len > width)
			width = len;
	}
	width += 2;
	columns = 80 / width;
	if (columns == 0)
		columns = 1;
	lines = (nentry + columns - 1) / columns;
	for (i = 0; i < lines; i++) {
		for (j = 0; j < columns; j++) {
			fp = fp0 + j * lines + i;
			cp = fmtentry(fp);
			fprintf(stderr, "%s", cp);
			if (fp + lines >= fplast) {
				fprintf(stderr, "\n");
				break;
			}
			w = strlen(cp);
			while (w < width) {
				w++;
				fprintf(stderr, " ");
			}
		}
	}
}

/*
 * Comparison routine for qsort.
 */
fcmp(f1, f2)
	register struct afile *f1, *f2;
{

	return (strcmp(f1->fname, f2->fname));
}

/*
 * Format a directory entry.
 */
char *
fmtentry(fp)
	register struct afile *fp;
{
	static char fmtres[BUFSIZ];
	register char *cp, *dp;

	if (vflag)
		(void) sprintf(fmtres, "%5d ", fp->fnum);
	else
		fmtres[0] = '\0';
	dp = &fmtres[strlen(fmtres)];
D 10
	if ((fp->fflags & NEW) != 0)
E 10
I 10
	if (dflag && BIT(fp->fnum, dumpmap) == 0)
		*dp++ = '^';
	else if ((fp->fflags & NEW) != 0)
E 10
		*dp++ = '*';
	else
		*dp++ = ' ';
	for (cp = fp->fname; *cp; cp++)
		if (!vflag && (*cp < ' ' || *cp >= 0177))
			*dp++ = '?';
		else
			*dp++ = *cp;
	if (fp->ftype == NODE)
		*dp++ = '/';
	*dp++ = 0;
	return (fmtres);
E 18
}

/*
 * Determine the type of an inode
 */
inodetype(ino)
	ino_t ino;
{
	struct inotab *itp;

	itp = inotablookup(ino);
	if (itp == NULL)
		return (LEAF);
	return (NODE);
}

/*
E 8
E 3
 * Allocate and initialize a directory inode entry.
 * If requested, save its pertinent mode, owner, and time info.
 */
I 3
struct inotab *
E 3
allocinotab(ino, dip, seekpt)
	ino_t ino;
	struct dinode *dip;
	daddr_t seekpt;
{
	register struct inotab	*itp;
	struct modeinfo node;
D 3
	static int prevseekpt = 0;
E 3

	itp = (struct inotab *)calloc(1, sizeof(struct inotab));
I 14
	if (itp == 0)
		panic("no memory directory table\n");
E 14
	itp->t_next = inotab[INOHASH(ino)];
	inotab[INOHASH(ino)] = itp;
	itp->t_ino = ino;
	itp->t_seekpt = seekpt;
D 3
	itp->t_size = seekpt - prevseekpt;
	prevseekpt = seekpt;
E 3
	if (mf == NULL)
D 3
		return;
E 3
I 3
		return(itp);
E 3
	node.ino = ino;
	node.timep[0] = dip->di_atime;
	node.timep[1] = dip->di_mtime;
	node.mode = dip->di_mode;
	node.uid = dip->di_uid;
	node.gid = dip->di_gid;
D 6
	fwrite((char *)&node, 1, sizeof(struct modeinfo), mf);
E 6
I 6
	(void) fwrite((char *)&node, 1, sizeof(struct modeinfo), mf);
E 6
I 3
	return(itp);
E 3
}

/*
 * Look up an inode in the table of directories
 */
struct inotab *
inotablookup(ino)
	ino_t	ino;
{
	register struct inotab *itp;

	for (itp = inotab[INOHASH(ino)]; itp != NULL; itp = itp->t_next)
		if (itp->t_ino == ino)
			return(itp);
	return ((struct inotab *)0);
}

/*
 * Clean up and exit
 */
done(exitcode)
	int exitcode;
{

	closemt();
D 4
	unlink(dirfile);
E 4
I 4
D 8
	(void) unlink(dirfile);
E 8
I 8
	if (modefile[0] != '#')
		(void) unlink(modefile);
	if (dirfile[0] != '#')
		(void) unlink(dirfile);
E 8
E 4
	exit(exitcode);
}
E 1
