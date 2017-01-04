h16221
s 00001/00000/00266
d D 5.3 87/03/10 16:22:59 mckusick 9 8
c must save link count when changing file type
e
s 00004/00000/00262
d D 5.2 86/03/05 17:14:37 mckusick 8 7
c add firewall check for bad entry in state map
e
s 00008/00002/00254
d D 5.1 85/06/05 08:57:06 dist 7 6
c Add copyright
e
s 00011/00003/00245
d D 3.6 85/02/15 12:09:05 mckusick 6 5
c calc and print out pathname of offending hard links to directories
e
s 00029/00009/00219
d D 3.5 85/02/14 19:18:33 mckusick 5 4
c recreate root directory if missing or trashed
e
s 00003/00003/00225
d D 3.4 85/02/11 18:29:25 mckusick 4 3
c ginode() succeeds or exits
e
s 00018/00006/00210
d D 3.3 85/02/08 19:15:42 mckusick 3 2
c merge passes 5 and 6 into a single pass
e
s 00001/00001/00215
d D 3.2 85/02/07 17:52:11 mckusick 2 1
c code reorganization and cleanup
e
s 00216/00000/00000
d D 3.1 84/03/31 21:03:48 mckusick 1 0
c date and time created 84/03/31 21:03:48 by mckusick
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
#ifndef lint
D 7
static char version[] = "%W% (Berkeley) %G%";
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7

#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include <sys/dir.h>
#include <strings.h>
#include "fsck.h"

int	pass2check();

pass2()
{
	register DINODE *dp;
	struct inodesc rootdesc;

	bzero((char *)&rootdesc, sizeof(struct inodesc));
	rootdesc.id_type = ADDR;
	rootdesc.id_func = pass2check;
	rootdesc.id_number = ROOTINO;
	pathp = pathname;
	switch (statemap[ROOTINO]) {

	case USTATE:
D 5
		errexit("ROOT INODE UNALLOCATED. TERMINATING.\n");
E 5
I 5
		pfatal("ROOT INODE UNALLOCATED");
		if (reply("ALLOCATE") == 0)
			errexit("");
		if (allocdir(ROOTINO, ROOTINO) != ROOTINO)
			errexit("CANNOT ALLOCATE ROOT INODE\n");
		descend(&rootdesc, ROOTINO);
		break;
E 5

I 5
	case DCLEAR:
		pfatal("DUPS/BAD IN ROOT INODE");
		if (reply("REALLOCATE")) {
			freeino(ROOTINO);
			if (allocdir(ROOTINO, ROOTINO) != ROOTINO)
				errexit("CANNOT ALLOCATE ROOT INODE\n");
			descend(&rootdesc, ROOTINO);
			break;
		}
		if (reply("CONTINUE") == 0)
			errexit("");
		statemap[ROOTINO] = DSTATE;
		descend(&rootdesc, ROOTINO);
		break;

E 5
	case FSTATE:
I 3
	case FCLEAR:
E 3
		pfatal("ROOT INODE NOT DIRECTORY");
I 5
		if (reply("REALLOCATE")) {
			freeino(ROOTINO);
			if (allocdir(ROOTINO, ROOTINO) != ROOTINO)
				errexit("CANNOT ALLOCATE ROOT INODE\n");
			descend(&rootdesc, ROOTINO);
			break;
		}
E 5
D 4
		if (reply("FIX") == 0 || (dp = ginode(ROOTINO)) == NULL)
E 4
I 4
		if (reply("FIX") == 0)
E 4
			errexit("");
I 4
		dp = ginode(ROOTINO);
E 4
		dp->di_mode &= ~IFMT;
		dp->di_mode |= IFDIR;
		inodirty();
D 3
		inosumbad++;
E 3
		statemap[ROOTINO] = DSTATE;
		/* fall into ... */

	case DSTATE:
		descend(&rootdesc, ROOTINO);
		break;
D 5

D 3
	case CLEAR:
E 3
I 3
	case DCLEAR:
E 3
		pfatal("DUPS/BAD IN ROOT INODE");
		printf("\n");
		if (reply("CONTINUE") == 0)
			errexit("");
		statemap[ROOTINO] = DSTATE;
		descend(&rootdesc, ROOTINO);
E 5
I 3

	default:
		errexit("BAD STATE %d FOR ROOT INODE", statemap[ROOTINO]);
E 3
	}
}

pass2check(idesc)
	struct inodesc *idesc;
{
	register DIRECT *dirp = idesc->id_dirp;
	char *curpathloc;
	int n, entrysize, ret = 0;
	DINODE *dp;
	DIRECT proto;
I 6
	char namebuf[BUFSIZ];
E 6

	/* 
	 * check for "."
	 */
	if (idesc->id_entryno != 0)
		goto chk1;
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, ".") == 0) {
		if (dirp->d_ino != idesc->id_number) {
			direrr(idesc->id_number, "BAD INODE NUMBER FOR '.'");
			dirp->d_ino = idesc->id_number;
			if (reply("FIX") == 1)
				ret |= ALTERED;
		}
		goto chk1;
	}
	direrr(idesc->id_number, "MISSING '.'");
	proto.d_ino = idesc->id_number;
	proto.d_namlen = 1;
	(void)strcpy(proto.d_name, ".");
	entrysize = DIRSIZ(&proto);
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, "..") != 0) {
		pfatal("CANNOT FIX, FIRST ENTRY IN DIRECTORY CONTAINS %s\n",
			dirp->d_name);
	} else if (dirp->d_reclen < entrysize) {
		pfatal("CANNOT FIX, INSUFFICIENT SPACE TO ADD '.'\n");
	} else if (dirp->d_reclen < 2 * entrysize) {
		proto.d_reclen = dirp->d_reclen;
		bcopy((char *)&proto, (char *)dirp, entrysize);
		if (reply("FIX") == 1)
			ret |= ALTERED;
	} else {
		n = dirp->d_reclen - entrysize;
		proto.d_reclen = entrysize;
		bcopy((char *)&proto, (char *)dirp, entrysize);
		idesc->id_entryno++;
		lncntp[dirp->d_ino]--;
		dirp = (DIRECT *)((char *)(dirp) + entrysize);
		bzero((char *)dirp, n);
		dirp->d_reclen = n;
		if (reply("FIX") == 1)
			ret |= ALTERED;
	}
chk1:
	if (idesc->id_entryno > 1)
		goto chk2;
	proto.d_ino = idesc->id_parent;
	proto.d_namlen = 2;
	(void)strcpy(proto.d_name, "..");
	entrysize = DIRSIZ(&proto);
	if (idesc->id_entryno == 0) {
		n = DIRSIZ(dirp);
		if (dirp->d_reclen < n + entrysize)
			goto chk2;
		proto.d_reclen = dirp->d_reclen - n;
		dirp->d_reclen = n;
		idesc->id_entryno++;
		lncntp[dirp->d_ino]--;
		dirp = (DIRECT *)((char *)(dirp) + n);
		bzero((char *)dirp, n);
		dirp->d_reclen = n;
	}
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, "..") == 0) {
		if (dirp->d_ino != idesc->id_parent) {
			direrr(idesc->id_number, "BAD INODE NUMBER FOR '..'");
			dirp->d_ino = idesc->id_parent;
			if (reply("FIX") == 1)
				ret |= ALTERED;
		}
		goto chk2;
	}
	direrr(idesc->id_number, "MISSING '..'");
	if (dirp->d_ino != 0 && strcmp(dirp->d_name, ".") != 0) {
		pfatal("CANNOT FIX, SECOND ENTRY IN DIRECTORY CONTAINS %s\n",
			dirp->d_name);
	} else if (dirp->d_reclen < entrysize) {
		pfatal("CANNOT FIX, INSUFFICIENT SPACE TO ADD '..'\n");
	} else {
		proto.d_reclen = dirp->d_reclen;
		bcopy((char *)&proto, (char *)dirp, entrysize);
		if (reply("FIX") == 1)
			ret |= ALTERED;
	}
chk2:
	if (dirp->d_ino == 0)
		return (ret|KEEPON);
	if (dirp->d_namlen <= 2 &&
	    dirp->d_name[0] == '.' &&
	    idesc->id_entryno >= 2) {
		if (dirp->d_namlen == 1) {
			direrr(idesc->id_number, "EXTRA '.' ENTRY");
			dirp->d_ino = 0;
			if (reply("FIX") == 1)
				ret |= ALTERED;
			return (KEEPON | ret);
		}
		if (dirp->d_name[1] == '.') {
			direrr(idesc->id_number, "EXTRA '..' ENTRY");
			dirp->d_ino = 0;
			if (reply("FIX") == 1)
				ret |= ALTERED;
			return (KEEPON | ret);
		}
	}
	curpathloc = pathp;
	*pathp++ = '/';
	if (pathp + dirp->d_namlen >= endpathname) {
		*pathp = '\0';
		errexit("NAME TOO LONG %s%s\n", pathname, dirp->d_name);
	}
	bcopy(dirp->d_name, pathp, dirp->d_namlen + 1);
	pathp += dirp->d_namlen;
	idesc->id_entryno++;
	n = 0;
	if (dirp->d_ino > imax || dirp->d_ino <= 0) {
		direrr(dirp->d_ino, "I OUT OF RANGE");
		n = reply("REMOVE");
	} else {
again:
		switch (statemap[dirp->d_ino]) {
		case USTATE:
			direrr(dirp->d_ino, "UNALLOCATED");
			n = reply("REMOVE");
			break;

D 3
		case CLEAR:
E 3
I 3
		case DCLEAR:
		case FCLEAR:
E 3
			direrr(dirp->d_ino, "DUP/BAD");
			if ((n = reply("REMOVE")) == 1)
				break;
D 4
			if ((dp = ginode(dirp->d_ino)) == NULL)
				break;
E 4
I 4
			dp = ginode(dirp->d_ino);
E 4
D 2
			statemap[dirp->d_ino] = DIRCT ? DSTATE : FSTATE;
E 2
I 2
			statemap[dirp->d_ino] = DIRCT(dp) ? DSTATE : FSTATE;
I 9
			lncntp[dirp->d_ino] = dp->di_nlink;
E 9
E 2
			goto again;

I 3
		case DFOUND:
D 6
			if (idesc->id_entryno > 2)
				pwarn("WARNING: %s IS %s\n", pathname,
				    "AN EXTRANEOUS HARD LINK TO A DIRECTORY");
E 6
I 6
			if (idesc->id_entryno > 2) {
				getpathname(namebuf, dirp->d_ino, dirp->d_ino);
				pwarn("%s %s %s\n", pathname,
				    "IS AN EXTRANEOUS HARD LINK TO DIRECTORY",
				    namebuf);
				if (preen)
					printf(" (IGNORED)\n");
				else if ((n = reply("REMOVE")) == 1)
					break;
			}
E 6
			/* fall through */

E 3
		case FSTATE:
			lncntp[dirp->d_ino]--;
			break;

		case DSTATE:
			descend(idesc, dirp->d_ino);
D 3
			if (statemap[dirp->d_ino] != CLEAR) {
E 3
I 3
			if (statemap[dirp->d_ino] == DFOUND) {
E 3
				lncntp[dirp->d_ino]--;
D 3
			} else {
E 3
I 3
			} else if (statemap[dirp->d_ino] == DCLEAR) {
E 3
				dirp->d_ino = 0;
				ret |= ALTERED;
D 3
			}
E 3
I 3
			} else
				errexit("BAD RETURN STATE %d FROM DESCEND",
				    statemap[dirp->d_ino]);
E 3
			break;
I 8

		default:
			errexit("BAD STATE %d FOR INODE I=%d",
			    statemap[dirp->d_ino], dirp->d_ino);
E 8
		}
	}
	pathp = curpathloc;
	*pathp = '\0';
	if (n == 0)
		return (ret|KEEPON);
	dirp->d_ino = 0;
	return (ret|KEEPON|ALTERED);
}
E 1
